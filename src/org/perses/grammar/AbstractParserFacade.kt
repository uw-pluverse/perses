/*
 * Copyright (C) 2018-2026 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.grammar

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import com.google.common.io.ByteStreams
import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.CommonToken
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.DefaultErrorStrategy
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.ParserRuleContext
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.TokenSource
import org.antlr.v4.runtime.TokenStream
import org.antlr.v4.runtime.atn.LexerATNSimulator
import org.antlr.v4.runtime.atn.ParserATNSimulator
import org.antlr.v4.runtime.atn.PredictionContextCache
import org.antlr.v4.runtime.atn.PredictionMode
import org.antlr.v4.runtime.tree.ErrorNodeImpl
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.TerminalNode
import org.perses.antlr.AbstractAntlrGrammar
import org.perses.antlr.AntlrGrammarUtil
import org.perses.antlr.GrammarHierarchy.Companion.createFromAntlrGrammar
import org.perses.antlr.MetaTokenInfoDB
import org.perses.antlr.ParseTreeWithParser
import org.perses.antlr.SyntaxError
import org.perses.antlr.TokenType
import org.perses.antlr.ast.LexerRuleList
import org.perses.antlr.ast.PersesAstBuilder.Companion.loadGrammarFromString
import org.perses.antlr.ast.PersesChannelDefinitionAst
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesGrammarOptionsAst
import org.perses.antlr.ast.PersesLexerRuleAst
import org.perses.antlr.ast.PersesTokenSpecificationAst
import org.perses.antlr.ast.PersesUndefinedRuleElement
import org.perses.antlr.ast.SymbolTable
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.antlr.pnf.UsedRuleNameCollector
import org.perses.antlr.toTokenType
import org.perses.program.LanguageKind
import org.perses.program.ProgramSize
import org.perses.util.IoUtil
import org.perses.util.ReflectionUtil
import org.perses.util.ThreadUtil.callWithLargeStackOnStackOverflow
import org.perses.util.ktFine
import org.perses.util.ktWarning
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList
import java.io.Reader
import java.io.StringReader
import java.lang.reflect.Constructor
import java.lang.reflect.InvocationTargetException
import java.lang.reflect.Method
import java.nio.charset.StandardCharsets
import java.nio.file.Path
import kotlin.io.path.absolute
import kotlin.io.path.readText

/**
 * How a facade reacts to syntax errors while parsing. [STRICT] aborts on the first error (the
 * historical behavior); [TOLERANT] lets ANTLR recover and always returns a tree, recording the
 * errors on the result.
 */
enum class ParseErrorHandling {
  STRICT,
  TOLERANT,
}

/** The base class for the parser facade  */
abstract class AbstractParserFacade protected constructor(
  val language: LanguageKind,
  val antlrGrammar: AbstractAntlrGrammar,
  private val identifierTokenTypes: ImmutableIntArray,
  private val includeAutoDetectedIdentifierTokenTypes: Boolean,
  val lexerClass: Class<out Lexer>,
  val parserClass: Class<out Parser>,
) {
  /**
   * The lexer that actually tokenizes the source text: this facade's own, unless it is an
   * [AbstractLexerAdaptingParserFacade], which reads another language and overrides this.
   *
   * Ask for this rather than testing for particular facade types -- such a test has to be repeated
   * at every site that needs the real tokenization, and silently misses any adaptor it does not
   * enumerate.
   */
  open val realLexerClass: Class<out Lexer>
    get() = lexerClass

  val ruleHierarchy = createFromAntlrGrammar(antlrGrammar)

  val lexerAtnWrapper: LexerAtnWrapper by lazy {
    if (ReflectionUtil.hasStaticFiled(lexerClass, FIELD_NAME_LEXER_WRAPPER)) {
      ReflectionUtil.readStaticField(lexerClass, FIELD_NAME_LEXER_WRAPPER)
    } else {
      LexerAtnWrapper.createLexerWrapperFromLexerClass(lexerClass)
    }
  }

  val metaTokenInfoDb: MetaTokenInfoDB
    get() = lexerAtnWrapper.metaTokenInfoDB

  /**
   * The effective identifier token types for this language: the explicitly
   * provided [identifierTokenTypes], plus -- only when
   * [includeAutoDetectedIdentifierTokenTypes] is set -- those found by the
   * default heuristic [LexerAtnWrapper.identifierTokens].
   *
   * The flag exists because the explicit list cannot, by itself, express whether
   * it is the complete set (authoritative; do not detect more) or a subset to be
   * augmented by detection. Authoritative is the right choice for any curated
   * grammar: the heuristic deliberately under-approximates, and the union cannot
   * subtract, so auto-detection can only add false positives a curated facade
   * does not want (e.g. Ruby's heredoc terminator, Solidity's fixed-point type
   * keywords). Detection is meant for ad-hoc grammars that declare nothing.
   *
   * Computing this set also runs [warnAboutAutoDetectedIdentifierTokenTypesNotSpecified]
   * once, so an authoritative facade that drops a token the heuristic flagged is
   * surfaced the first time its identifiers are used.
   */
  val fusedIdentifierTokenTypes: ImmutableList<TokenType> by lazy {
    warnAboutAutoDetectedIdentifierTokenTypesNotSpecified()
    val set = LinkedHashSet<TokenType>()
    identifierTokenTypes.toArray().forEach { set.add(it.toTokenType()) }
    if (includeAutoDetectedIdentifierTokenTypes) {
      autoDetectedIdentifierTokenTypes.forEach { set.add(it) }
    }
    set.transformToImmutableList { it }
  }

  val autoDetectedIdentifierTokenTypes: ImmutableList<TokenType> by lazy {
    lexerAtnWrapper.identifierTokens.transformToImmutableList { it.tokenType }
  }

  init {
    require(identifierTokenTypes.toArray().distinct().size == identifierTokenTypes.length()) {
      "The identifier token types have duplicate elements: $identifierTokenTypes"
    }
  }

  /**
   * Logs a warning for each token type the heuristic
   * [autoDetectedIdentifierTokenTypes] flags that the curated [identifierTokenTypes]
   * does not list. Such a token is either an identifier the curated list forgot, or
   * an identifier-shaped non-identifier the heuristic over-approximated (e.g. Ruby's
   * heredoc terminator) -- either way it is worth a human's review.
   *
   * This only fires for an authoritative facade
   * ([includeAutoDetectedIdentifierTokenTypes] is false): when detection is enabled,
   * any auto-detected token is already merged into [fusedIdentifierTokenTypes], so
   * none is missing. The opposite direction -- specified but not auto-detected -- is
   * also silent, because the detector deliberately under-approximates (it misses
   * operator and quoted identifiers, e.g. Scala's), so that divergence is expected.
   *
   * @return the sorted symbolic names of the warned-about token types (empty when
   *   there is nothing to warn about), so callers can assert on the result.
   */
  fun warnAboutAutoDetectedIdentifierTokenTypesNotSpecified(): List<String> {
    if (includeAutoDetectedIdentifierTokenTypes) {
      return emptyList()
    }
    val specified = identifierTokenTypes.toArray().map { it.toTokenType() }.toSet()
    val autoDetectedButNotSpecified =
      (autoDetectedIdentifierTokenTypes.toSet() - specified).toSortedSymbolicNames()
    if (autoDetectedButNotSpecified.isNotEmpty()) {
      logger.ktWarning {
        "For language '${language.name}', these auto-detected identifier token types are " +
          "excluded by the authoritative specification and may be missing identifiers or " +
          "detector false positives: $autoDetectedButNotSpecified"
      }
    }
    return autoDetectedButNotSpecified
  }

  private fun Set<TokenType>.toSortedSymbolicNames(): List<String> =
    map { metaTokenInfoDb.getTokenInfoWithType(it)?.symbolicName ?: it.antlrTokenType.toString() }
      .sorted()

  // Routed through parseString (rather than parseReader directly) so a deeply nested file gets the
  // same large-stack retry, and a failed parse echoes the source in its diagnostic. ANTLR buffers the
  // whole input into a CharStream regardless, so reading to a string here costs no extra pass of note.
  fun parseFile(file: Path): ParseTreeWithParser =
    parseString(
      string = file.readText(),
      filename = file.absolute().toString(),
      errorMode = ParseErrorHandling.STRICT,
    )

  fun tokenizeFile(file: Path): ImmutableList<Token> =
    tokenizeString(content = file.readText(), fileName = file.absolute().toString())

  /**
   * Lexes [file] and returns its [ProgramSize], streaming the tokens without retaining them.
   * Only this facade's lexer is used, so the canonical token count is left unspecified and
   * [ProgramSize] falls back to the surrogate (this facade's) token count — which *is* the
   * canonical count when this facade is the canonical one for the file's language. A caller
   * lexing with a non-canonical facade (e.g. a Dyck-language or ad-hoc grammar) composes the
   * canonical count itself via [countTokensInString] on the canonical facade.
   */
  fun computeProgramSizeOf(file: Path): ProgramSize<Unit> =
    computeProgramSizeOf(content = file.readText(), fileName = file.absolute().toString())

  /** The in-memory counterpart of the [Path] overload; see its contract above. */
  fun computeProgramSizeOf(
    content: String,
    fileName: String = DEFAULT_FILE_NAME,
  ): ProgramSize<Unit> {
    val lexer = createLexerWithoutCache(CharStreams.fromString(content, fileName))
    var tokenCount = 0
    var totalCharacterCount = 0
    var nonBlankCharacterCount = 0
    AntlrGrammarUtil.forEachTokenInDefaultChannel(lexer) { token ->
      ++tokenCount
      val text = token.text
      totalCharacterCount += text.length
      nonBlankCharacterCount += text.count { !Character.isWhitespace(it) }
    }
    return ProgramSize(
      payload = Unit,
      canonicalTokenCount = null,
      surrogateTokenCount = tokenCount,
      totalCharacterCount = totalCharacterCount,
      nonBlankCharacterCount = nonBlankCharacterCount,
    )
  }

  fun transformLiteralIntoSingleToken(literal: String): Token {
    val lexer = createLexerWithoutCache(CharStreams.fromString(literal))
    val result = lexer.nextToken()
    val next = lexer.nextToken()
    check(next.type == Token.EOF) {
      """|literal = $literal
         |result = ${result.text}, ${result.type}, $result
         |next = ${next.text}, ${next.type}, $next
      """.trimMargin()
    }
    return result
  }

  /**
   * Parses [string] under this facade's grammar. With [ParseErrorHandling.STRICT] the first syntax
   * error aborts with an [AntlrFailureException]; with [ParseErrorHandling.TOLERANT] ANTLR's
   * [DefaultErrorStrategy] recovers and a tree is always returned, its collected errors exposed via
   * [ParseTreeWithParser.syntaxErrors] (empty means a clean parse). A tolerant tree may contain
   * fabricated "missing" tokens (tokenIndex &lt; 0); use [isFabricatedToken] to drop them before
   * reconstructing source text.
   */
  fun parseString(
    string: String,
    filename: String = DEFAULT_FILE_NAME,
    startRuleName: String? = null,
    errorMode: ParseErrorHandling,
  ): ParseTreeWithParser =
    // A deeply nested input overflows the recursive-descent parse on the default thread stack. Retry
    // once on a large stack here, in the one place every parse funnels through, so no caller has to
    // handle the overflow. Only StackOverflowError is handled -- every other throwable propagates
    // unchanged. (The spar-tree build downstream is iterative, so the parse is the only overflow
    // point.)
    try {
      callWithLargeStackOnStackOverflow {
        when (errorMode) {
          ParseErrorHandling.STRICT -> parseStringStrictly(string, startRuleName)
          ParseErrorHandling.TOLERANT -> parseStringTolerantly(string, filename, startRuleName)
        }
      }
    } catch (e: StackOverflowError) {
      // Too deep even for the large-stack retry: surface it as an unparsable input -- the signal
      // callers already handle for any parse failure -- instead of letting a raw Error escape.
      throw AntlrFailureException(
        cause = e,
        file = filename,
        details = "Input at $filename nests too deep to parse even on a large stack.",
      )
    }

  private fun parseStringStrictly(
    string: String,
    startRuleName: String?,
  ): ParseTreeWithParser {
    val reader = StringReader(string)
    try {
      return parseReader(reader, startRuleName)
    } catch (e: Exception) {
      val message =
        """Failed to parse the following input.
          |---------------------------------------
          |$string
          |---------------------------------------
        """.trimMargin()
      throw if (e is AntlrFailureException) {
        AntlrFailureException(
          cause = e,
          file = e.file,
          details = message + "\nThe following is the old details.\n" + e.details,
        )
      } else {
        RuntimeException(message, e)
      }
    }
  }

  private fun parseStringTolerantly(
    string: String,
    filename: String,
    startRuleName: String?,
  ): ParseTreeWithParser {
    val parsingMethod =
      if (startRuleName == null) {
        startRuleParsingMethod
      } else {
        parserClass.getDeclaredMethod(startRuleName)
      }

    val charStream = CharStreams.fromString(string, filename)
    // The lexer drops characters it cannot match; the parser therefore sees a clean stream and builds
    // undamaged structure. The dropped characters are spliced back in below, after parsing.
    val errorTolerantLexer = createTolerantLexing(charStream)
    val lexer = errorTolerantLexer.lexer
    val tokenStream = CommonTokenStream(lexer)
    val errorListener = CollectingAntlrErrorListener(filename)
    val parser = createTolerantParser(tokenStream, errorListener)
    // Tolerant parsing is best-effort, but ANTLR error recovery can still fail catastrophically on
    // some inputs (e.g. a fabricated token with a null source, which then NPEs deep in the generated
    // parser). Surface that as a clean AntlrFailureException so callers fall back / skip gracefully
    // (as they do for any unparsable program) instead of an opaque RuntimeException escaping to the
    // top-level handler. See internal_doc/error_tolerant_multi_grammar_passes.md.
    val tree =
      try {
        parseWithMethod(parser, parsingMethod)
      } catch (e: Exception) {
        throw AntlrFailureException(
          cause = e,
          file = filename,
          details = "Tolerant parse of $filename failed even under error recovery: ${e.message}",
        )
      }
    val droppedCharacters = errorTolerantLexer.droppedCharacters
    // Every character the lexer could not tokenize is a syntax error, even when the recovered token
    // stream then parses cleanly; folding these in is what keeps hasSyntaxErrors -- the AUTO-pass
    // trigger -- true for a file whose only defect is un-lexable characters.
    val syntaxErrors = errorListener.errors.toMutableList()
    droppedCharacters.forEach {
      syntaxErrors.add(
        SyntaxError(
          line = it.line,
          column = it.column,
          message = "unlexable character: '${it.text}'",
          offendingSymbol = null,
        ),
      )
    }
    // GAP-EOF: an un-anchored start rule stops at the first complete construct; capture the rest.
    appendUnconsumedTrailingTokens(tree, tokenStream)?.let { syntaxErrors.add(it) }
    // GAP-LEXER: put each dropped character back into the tree as a leaf next to its source neighbor.
    insertDroppedCharacters(tree, droppedCharacters, charStream)

    lexer.interpreter?.let { interpreter ->
      interpreter.clearDFA()
      interpreter.reset()
    }
    parser.interpreter.clearDFA()
    parser.interpreter.reset()
    return ParseTreeWithParser(tree, parser, lexer, syntaxErrors)
  }

  /**
   * Splices each character the lexer dropped ([dropped]) back into [tree] as an [Token.INVALID_TYPE]
   * error-node leaf, positioned by its source offset: the leaf is inserted immediately after the
   * terminal whose token ends just before the dropped character (or before the first terminal, when
   * the drop precedes all tokens). Because the parser never saw these characters, the surrounding tree
   * structure is intact; this only re-adds the missing leaves so the tree still spells the input.
   */
  private fun insertDroppedCharacters(
    tree: ParseTree,
    dropped: List<DroppedCharacter>,
    charStream: CharStream,
  ) {
    if (dropped.isEmpty() || tree !is ParserRuleContext) {
      return
    }
    val terminals = ArrayList<TerminalNode>()
    collectTerminals(tree, terminals)
    val realTerminals =
      terminals
        .filter { it.symbol.type != Token.EOF && it.symbol.startIndex >= 0 }
        .sortedBy { it.symbol.startIndex }

    if (realTerminals.isEmpty()) {
      // No anchor tokens (e.g. all-garbage input); hang the drops off the root, in source order.
      // addErrorNode creates the child list if the root has none, so this is null-safe.
      dropped
        .sortedBy {
          it.charIndex
        }.forEach { tree.addErrorNode(droppedCharErrorNode(it, charStream)) }
      return
    }

    // Group the new leaves by the (parent, child-index) at which they must be inserted, computed
    // against the pristine tree; applying the groups in descending index order then keeps every
    // precomputed index valid, since a later (higher-index) insertion never shifts an earlier one.
    val sites = LinkedHashMap<Pair<ParserRuleContext, Int>, MutableList<ErrorNodeImpl>>()
    for (droppedChar in dropped.sortedBy { it.charIndex }) {
      val preceding = realTerminals.lastOrNull { it.symbol.stopIndex < droppedChar.charIndex }
      val site =
        if (preceding != null) {
          val parent = preceding.parent as ParserRuleContext
          Pair(parent, parent.children.indexOf(preceding) + 1)
        } else {
          val first = realTerminals.first()
          val parent = first.parent as ParserRuleContext
          Pair(parent, parent.children.indexOf(first))
        }
      sites.getOrPut(site) { ArrayList() }.add(droppedCharErrorNode(droppedChar, charStream))
    }

    sites.entries
      .sortedByDescending { it.key.second }
      .forEach { (site, nodes) ->
        val (parent, index) = site
        nodes.forEach { it.setParent(parent) }
        parent.children.addAll(index, nodes)
      }
  }

  private fun collectTerminals(
    node: ParseTree,
    out: MutableList<TerminalNode>,
  ) {
    if (node is TerminalNode) {
      out.add(node)
      return
    }
    for (i in 0 until node.childCount) {
      collectTerminals(node.getChild(i), out)
    }
  }

  private fun droppedCharErrorNode(
    droppedChar: DroppedCharacter,
    charStream: CharStream,
  ): ErrorNodeImpl {
    val token =
      CommonToken(
        org.antlr.v4.runtime.misc
          .Pair<TokenSource, CharStream>(null, charStream),
        Token.INVALID_TYPE,
        Token.DEFAULT_CHANNEL,
        droppedChar.charIndex,
        droppedChar.charIndex + droppedChar.text.length - 1,
      ).apply {
        text = droppedChar.text
        line = droppedChar.line
        charPositionInLine = droppedChar.column
      }
    return ErrorNodeImpl(token)
  }

  /**
   * Appends every token the parser left unconsumed before EOF to [tree] as an error-node leaf, so the
   * trailing input an un-anchored start rule would otherwise silently ignore still appears in the
   * tree. Returns a synthetic [SyntaxError] describing the leftover, or null when the whole input was
   * consumed.
   */
  private fun appendUnconsumedTrailingTokens(
    tree: ParseTree,
    tokenStream: CommonTokenStream,
  ): SyntaxError? {
    if (tree !is ParserRuleContext || tokenStream.LA(1) == Token.EOF) {
      return null
    }
    val firstLeftover = tokenStream.LT(1)
    var count = 0
    while (tokenStream.LA(1) != Token.EOF) {
      tree.addErrorNode(ErrorNodeImpl(tokenStream.LT(1)))
      tokenStream.consume()
      ++count
    }
    return SyntaxError(
      line = firstLeftover.line,
      column = firstLeftover.charPositionInLine,
      message = "unconsumed trailing input ($count tokens starting with '${firstLeftover.text}')",
      offendingSymbol = firstLeftover,
    )
  }

  private fun createTolerantLexing(inputStream: CharStream): ErrorTolerantLexer =
    // Route through createLexer so subclass lexer customization is preserved; ErrorTolerantLexer then
    // swaps the lexer's fail-fast listeners for its dropped-character recorder.
    ErrorTolerantLexer {
      createLexer(inputStream).also { disableGlobalCachingIfInstructed(it) }
    }

  private fun createTolerantParser(
    tokens: TokenStream,
    errorListener: CollectingAntlrErrorListener,
  ): Parser {
    val parser = parserConstructor.newInstance(tokens) as Parser
    parser.removeErrorListeners()
    // Null-safe recovery: the Dyck lexers wrap another lexer, so their tokens can have a null source
    // that stock DefaultErrorStrategy.getMissingSymbol would NPE on. See TolerantErrorStrategy.
    parser.errorHandler = TolerantErrorStrategy()
    parser.addErrorListener(errorListener)
    return disableGlobalCachingIfInstructed(parser)
  }

  fun isSourceCodeParsable(sourceCode: String): Boolean =
    try {
      parseString(sourceCode, errorMode = ParseErrorHandling.STRICT)
      true
    } catch (e: Exception) {
      logger.ktFine {
        """
        The input source is not parsable.
        
        $e
        """.trimIndent()
      }
      false
    }

  fun tokenizeString(
    content: String,
    fileName: String = DEFAULT_FILE_NAME,
  ): ImmutableList<Token> {
    val lexer: Lexer = createLexerWithoutCache(CharStreams.fromString(content, fileName))
    return AntlrGrammarUtil.readAllTokensInDefaultChannel(lexer)
  }

  /**
   * Returns the number of tokens [content] produces on the default channel (EOF excluded). This is
   * equivalent to `tokenizeString(content).size`, but it does not build and retain the intermediate
   * list of tokens -- it only counts them.
   *
   * Lexer errors are always tolerated. Counting is not parsing: a program the grammar has no token
   * for at some position -- a stray `@`, a `#` from a surviving preprocessor directive, a `\`
   * line-continuation -- still has a perfectly well-defined token count, and there is no caller for
   * whom refusing to give one is useful. Callers that need to know whether a program parses ask
   * [isSourceCodeParsable] or [parseString]; a strict count merely turned an unlexable program into
   * an exception at whatever call site happened to measure it.
   *
   * Each dropped character run is counted, because the tolerant parse splices it back into the tree
   * as a leaf (see `insertDroppedCharacters`): it is a node the reducer sees and can delete, so a
   * count that omitted it would not describe the program the reducer actually works on. A file that
   * lexes cleanly drops nothing and so counts exactly as a strict lex would.
   */
  fun countTokensInString(content: String): Int {
    val errorTolerantLexer =
      createTolerantLexing(CharStreams.fromString(content, DEFAULT_FILE_NAME))
    return AntlrGrammarUtil.countTokensInDefaultChannel(errorTolerantLexer.lexer) +
      errorTolerantLexer.droppedCharacters.size
  }

  private val parserConstructor: Constructor<out Parser> =
    parserClass.getDeclaredConstructor(TokenStream::class.java)
  private val startRuleParsingMethod: Method =
    parserClass.getDeclaredMethod(antlrGrammar.startRuleName)

  protected fun startParsingWithSpecificRule(
    parser: Parser,
    parserRuleName: String,
  ): ParseTree {
    val method = parser::class.java.getDeclaredMethod(parserRuleName)
    return parseWithMethod(parser, method)
  }

  private fun parseWithMethod(
    parser: Parser,
    method: Method,
  ): ParseTree {
    try {
      return method.invoke(parser) as ParseTree
    } catch (e: InvocationTargetException) {
      val targetException = e.targetException
      // Need to throw the target exception.
      if (targetException is AntlrFailureException) {
        throw AntlrFailureException(
          cause = targetException,
          file = targetException.file,
          details =
            targetException.details +
              """\nThis is a rethrown exception to track the current stack trace.
              |Method = $method
              """.trimMargin(),
        )
      }
      // Do not bury an Error (notably a StackOverflowError from a deeply nested input) inside a
      // RuntimeException -- that turns it into something a catch(Exception) would swallow. Let Errors
      // propagate as-is so the parse boundary can decide: descend the tolerant fallback ladder, or
      // retry the parse on a large-stack thread. Only genuine Exceptions are wrapped.
      if (targetException is Error) {
        throw targetException
      }
      throw RuntimeException(targetException)
    }
  }

  private fun parseReader(
    reader: Reader,
    startRuleName: String?,
  ): ParseTreeWithParser {
    val parsingMethod =
      if (startRuleName == null) {
        startRuleParsingMethod
      } else {
        parserClass.getDeclaredMethod(startRuleName)
      }
    return parseReader(
      reader,
      lexerCreator = ::createLexerWithoutCache,
      parserCreator = ::createParserWithoutCache,
      parseFunction = { parser ->
        parseWithMethod(parser, parsingMethod)
      },
    )
  }

  protected open fun createLexer(inputStream: CharStream): Lexer {
    val constructor = getCharStreamConstructorFromLexer(lexerClass)
    val lexer = constructor.newInstance(inputStream) as Lexer
    lexer.removeErrorListeners()
    lexer.addErrorListener(FailOnErrorAntlrErrorListener(sourceFile = inputStream.sourceName))
    return lexer
  }

  private fun createLexerWithoutCache(inputStream: CharStream): Lexer {
    val lexer = createLexer(inputStream)
    disableGlobalCachingIfInstructed(lexer)
    return lexer
  }

  private fun createParser(tokens: TokenStream): Parser {
    val parser = parserConstructor.newInstance(tokens) as Parser
    parser.removeErrorListeners()
    parser.errorHandler = DefaultErrorStrategy()
    parser.addErrorListener(FailOnErrorAntlrErrorListener(tokens.sourceName))
    return parser
  }

  private fun createParserWithoutCache(tokens: TokenStream): Parser {
    val parser = createParser(tokens)
    disableGlobalCachingIfInstructed(parser)
    return parser
  }

  companion object {
    val FIELD_NAME_LEXER_WRAPPER = "LEXER_WRAPPER"

    /**
     * True for a token that spans no input characters and therefore must not become a tree leaf or
     * reach reconstructed source text -- otherwise the output would contain characters the input
     * never had. Two kinds qualify, both marked by a negative [Token.getStartIndex]:
     * - Tokens ANTLR fabricates during single-token-insertion recovery (e.g. the `<missing '}'>` it
     *   invents to repair a rule); [org.antlr.v4.runtime.DefaultErrorStrategy.getMissingSymbol] gives
     *   them `startIndex == -1` and synthetic text.
     * - Tokens a lexer synthesizes purely as structural delimiters (e.g. the Dyck lexer's
     *   `FABRICATED_NEWLINE`, inserted to group `OTHER` runs into lines), which it stamps with a
     *   negative start/stop index for the same reason.
     *
     * The check is on the char interval, not the token index, so it does not also reject the real
     * dropped-character leaves spliced into the tree by the tolerant parse path (those carry a valid
     * [Token.getStartIndex]). It tests for any negative index rather than a specific sentinel.
     */
    @JvmStatic
    fun isFabricatedToken(token: Token): Boolean = token.startIndex < 0

    fun getCharStreamConstructorFromLexer(lexerClass: Class<out Lexer>): Constructor<out Lexer> =
      lexerClass.getDeclaredConstructor(CharStream::class.java)

    @JvmStatic
    fun readAntlrGrammarContent(
      antlrGrammarFileName: String,
      classUnderSamePkg: Class<*>,
    ): String {
      IoUtil.openResourceAsStream(antlrGrammarFileName, classUnderSamePkg).use { stream ->
        return String(ByteStreams.toByteArray(stream), StandardCharsets.UTF_8)
      }
    }

    @JvmStatic
    protected fun createSeparateAntlrParserGrammarOnly(
      startRuleName: String,
      antlrParserGrammarFileName: String,
      classUnderSamePkg: Class<*>,
    ): AbstractAntlrGrammar.SeparateAntlrGrammar {
      val parserGrammar =
        loadGrammarFromString(
          readAntlrGrammarContent(antlrParserGrammarFileName, classUnderSamePkg),
        )
      val lexerGrammar = computeDummyLexerGrammarForParserGrammar(parserGrammar)
      return AbstractAntlrGrammar.SeparateAntlrGrammar(startRuleName, parserGrammar, lexerGrammar)
    }

    // TODO(cnsun): to be tested.
    private fun computeDummyLexerGrammarForParserGrammar(
      parserGrammar: PersesGrammar,
    ): PersesGrammar {
      require(parserGrammar.grammarType == PersesGrammar.GrammarType.PARSER)
      val usedLexerRuleNameCollector = UsedRuleNameCollector()
      usedLexerRuleNameCollector.preorderGrammar(parserGrammar)
      val symbolTable = SymbolTable()
      return PersesGrammar(
        grammarType = PersesGrammar.GrammarType.LEXER,
        grammarName = "JacksonLexer.g4",
        channelDefinitions = PersesChannelDefinitionAst.EMPTY,
        tokenSpecifications = PersesTokenSpecificationAst.EMPTY,
        options = PersesGrammarOptionsAst.EMPTY,
        namedActions = ImmutableList.of(),
        lexerRules =
          LexerRuleList(
            defaultModeLexerRules =
              usedLexerRuleNameCollector.tokenReferences
                .map { lexerRuleName ->
                  PersesLexerRuleAst(
                    ruleNameHandle = symbolTable.ruleNameRegistry.getOrCreate(lexerRuleName),
                    body = PersesUndefinedRuleElement(),
                  )
                }.toImmutableList(),
            nonDefaultModes = ImmutableList.of(),
          ),
        parserRules = ImmutableList.of(),
        symbolTable = SymbolTable(),
      )
    }

    @JvmStatic
    protected fun createSeparateAntlrGrammar(
      startRuleName: String,
      antlrParserGrammarFileName: String,
      antlrLexerGrammarFileName: String,
      classUnderSamePkg: Class<*>,
    ): AbstractAntlrGrammar.SeparateAntlrGrammar {
      val parserGrammar =
        loadGrammarFromString(
          readAntlrGrammarContent(antlrParserGrammarFileName, classUnderSamePkg),
        )
      val lexerGrammar =
        loadGrammarFromString(
          readAntlrGrammarContent(antlrLexerGrammarFileName, classUnderSamePkg),
        )
      return AbstractAntlrGrammar.SeparateAntlrGrammar(startRuleName, parserGrammar, lexerGrammar)
    }

    @JvmStatic
    protected fun createCombinedAntlrGrammar(
      startRuleName: String,
      antlrGrammarFileName: String,
      classUnderSamePkg: Class<*>,
    ): AbstractAntlrGrammar.CombinedAntlrGrammar {
      val content = readAntlrGrammarContent(antlrGrammarFileName, classUnderSamePkg)
      val persesGrammar = loadGrammarFromString(content)
      return AbstractAntlrGrammar.CombinedAntlrGrammar(startRuleName, persesGrammar)
    }

    private val logger = FluentLogger.forEnclosingClass()

    const val DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY = true

    @JvmStatic
    inline fun <L : Lexer, P : Parser> parseReader(
      // TODO(cnsun): need to delete this fileName.
      reader: Reader,
      lexerCreator: (CharStream) -> L,
      parserCreator: (CommonTokenStream) -> P,
      parseFunction: (P) -> ParseTree,
    ): ParseTreeWithParser {
      val lexer = lexerCreator.invoke(CharStreams.fromReader(reader))
      val tokenStream = CommonTokenStream(lexer)
      val parser = parserCreator.invoke(tokenStream)
      if (DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY) {
        parser.interpreter =
          ParserATNSimulator(
            parser,
            parser.atn,
            parser.interpreter.decisionToDFA,
            PredictionContextCache(),
          )
      }
      val tree = parseFunction.invoke(parser)
      lexer.interpreter?.let { interpreter ->
        interpreter.clearDFA()
        interpreter.reset()
      }
      parser.interpreter.clearDFA()
      parser.interpreter.reset()
      // TODO(cnsun): need to mark whether the entire input is parsed.
      return ParseTreeWithParser(tree, parser, lexer)
    }

    @JvmStatic
    fun <LEXER : Lexer> disableGlobalCachingIfInstructed(lexer: LEXER): LEXER {
      if (DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY) {
        val oldIntepreter = lexer.interpreter ?: return lexer
        lexer.interpreter =
          LexerATNSimulator(
            lexer,
            lexer.atn,
            oldIntepreter.decisionToDFA,
            PredictionContextCache(),
          )
      }
      return lexer
    }

    @JvmStatic
    fun <PARSER : Parser> disableGlobalCachingIfInstructed(parser: PARSER): PARSER {
      if (DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY) {
        // The following code is from.
        // https://github.com/antlr/antlr4/issues/499#issuecomment-38159752
        parser.interpreter =
          ParserATNSimulator(
            parser,
            parser.atn,
            parser.interpreter.decisionToDFA,
            PredictionContextCache(),
          )
        parser.interpreter.predictionMode = PredictionMode.LL
      }
      return parser
    }

    private val DEFAULT_FILE_NAME = "<in memory>"
  }
}

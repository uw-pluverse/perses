lexer grammar TestLexer;

// A fragment referenced twice within the SAME rule. In ANTLR's ATN, FX is a
// separate per-rule NFA whose single RuleStopState gets one epsilon "return"
// edge per call site. A context-insensitive traversal can return from the
// first FX call via the second call site's return edge, short-circuiting the
// middle of the rule. The only real lexeme of DoubleFragRef is "axbxc".
// Declared first so it wins the maximal-munch tie against NegationAndPlus
// (~[\n]+), which also matches "axbxc"; this keeps the lex-back test precise.
fragment FX
    : 'x'
    ;

DoubleFragRef
    : 'a' FX 'b' FX 'c'
    ;

SingleChar
    : 'A'
    ;

TwoChars
    : 'AB'
    ;

CharSet
    : [a-z]
    ;

NotADigit
    : ~[0-9]
    ;

KleeneStar
    : 'a' 'b'*
    ;

OptionalOnly
    : 'b' ?
    ;

OptionalChar
    : 'a' 'b'?
    ;

OptionalSequence
    : 'abcd'? 'e'
    ;

Alt
    : 'a' | 'A'
    ;

KleenePlusOnSingleChar
    : 'a' +
    ;

NegationAndPlus
    : ~[\n]+
    ;

IncludeDirective
    : '#' 'include' ~ [\n]+
    ;

fragment DIGIT
    : [0-9]
    ;

NaturalNumber
    : DIGIT+
    ;

Long
    : DIGIT+ 'L'
    ;

Wildcard
    : 'a' .
    ;

NonRegexToken
    : 'a'
    | '#' NonRegexToken '#'
    ;

GreedyWildcard
    : '|' .* '|'
    ;

NonGreedyWildcard
    : '|' .*? '|'
    ;

// Mirrors the overlapping-char-class shape of Scala's `Lower : 'a'..'z' |
// UnicodeClass_LL` (UnicodeClass_LL is a superset of a-z): a range alternated
// with a fragment-reference char set that OVERLAPS it. Unlike two inline
// char-set literals (which simplifyToRegex merges earlier), this shape reaches
// ATNConstructorFromRegex as a two-branch alternation, so it exercises the merge
// there. The single character 'a' is accepted by both branches: without the
// merge that is two accepting paths and findATNPathForLexeme throws on its
// uniqueness check; with it, exactly one. Kept to a single character (no
// star/plus) so it isolates the alternation merge from the separate
// epsilon-diamond behavior of starred rules.
fragment WiderLower
    : [a-zµ]
    ;

OverlappingChar
    : 'a' .. 'z'
    | WiderLower
    ;

// A star/plus over the overlapping alternation, expressed via a fragment so the
// alternation is inlined and merged (as Scala's `Lower` is inside `Varid`). The
// star still produces 2^n epsilon-routing path representations for an n-char
// lexeme, but they are vacuous duplicates (same merged atom transition), so
// findATNPathForLexeme must collapse them to a single unique path.
fragment OverlapCharFragment
    : 'a' .. 'z'
    | WiderLower
    ;

OverlappingId
    : OverlapCharFragment+
    ;

// Genuinely structurally ambiguous: "aaa" can split as (1,2) or (2,1) across the
// two plus-blocks. Both produce the token text "aaa", so findATNPathForLexeme
// returns one deterministic representative rather than rejecting the lexeme.
AmbiguousSplit
    : 'a' + 'a' +
    ;

grammar MakefileGrammar;

// A precise, word-level Makefile grammar. Unlike a line-at-a-time grammar, it splits each non-recipe
// line into individually-deletable words, so the reducer can drop a single entry from a list -- one
// file from `SRCS = a.c b.c c.c`, one prerequisite from `app: a.o b.o c.o` -- not just whole lines.
// A `$(...)`/`${...}` reference is one atomic word (so `$(foreach d,$(DIRS),$(d))` is never split on
// its internal spaces/commas). Recipe lines (a leading TAB) stay one atomic token and are grouped
// under their rule header, so a whole rule -- header plus recipes -- still deletes as one node.
// The grammar is permissive: any line tokenizes into words, and invalid variants are rejected by the
// interestingness test.

makefile
    : item* lastLine? EOF
    ;

item
    : rule
    | textLine
    | blankLine
    ;

blankLine
    : NEWLINE
    ;

// A rule header (a word-list line) followed by its tab-indented recipe block. The header is
// mandatory, so deleting the rule node removes the header and every recipe together.
rule
    : header recipe+
    ;

header
    : word+ NEWLINE
    ;

recipe
    : RECIPE_LINE NEWLINE
    ;

textLine
    : word+ NEWLINE
    ;

// A final line that lacks a trailing newline (EOF terminates it). Kept off [item] so EOF is matched
// only once, by [makefile].
lastLine
    : word+
    | RECIPE_LINE
    ;

word
    : WORD
    | VARREF
    | COMMENT
    | CONTINUATION
    ;

// ---------- Lexer ----------

// A recipe line: a TAB at the very start of a line, then the rest of the line (folding backslash
// continuations). The predicate distinguishes a leading TAB (recipe) from a TAB used as inter-word
// whitespace (which the WS rule skips).
RECIPE_LINE
    : {getCharPositionInLine() == 0}? '\t' ( '\\' '\r'? '\n' | ~[\r\n] )*
    ;

COMMENT
    : '#' ~[\r\n]*
    ;

// An atomic variable/function reference: $(...), ${...}, or $x. Balanced parens/braces keep nested
// references and function calls together despite internal spaces and commas.
VARREF
    : '$' ( '(' PAREN_BODY ')' | '{' BRACE_BODY '}' | ~[ \t\r\n] )
    ;

fragment PAREN_BODY
    : ( ~[()] | '(' PAREN_BODY ')' )*
    ;

fragment BRACE_BODY
    : ( ~[{}] | '{' BRACE_BODY '}' )*
    ;

// A line continuation kept as a real token (not skipped) so its backslash is preserved and the
// content round-trips; it carries the newline, so the logical line continues past it.
CONTINUATION
    : '\\' '\r'? '\n'
    ;

// A word: a run of ordinary characters. Stops at whitespace and at the special starts #, $, \.
// A backslash escapes the next (non-newline) char so an escaped space stays part of the word.
WORD
    : ( '\\' ~[\r\n] | ~[ \t\r\n#$\\] )+
    ;

NEWLINE
    : '\r'? '\n'
    ;

WS
    : [ \t]+ -> skip
    ;

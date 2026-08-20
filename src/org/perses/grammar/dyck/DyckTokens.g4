lexer grammar DyckTokens;

// The single definition of the Dyck token vocabulary. LineAwareDyckParser and
// PristineDyckParser both reference it via `options { tokenVocab = DyckTokens; }` instead
// of each repeating an identical tokens block, which also guarantees they share one token
// numbering (OPEN_BRACE=1 .. FABRICATED_NEWLINE=8).
//
// These rules exist ONLY to fix the token names and their order/numbering. The actual
// tokenization is done by the hand-written DyckLexer, not by this grammar, so the rule
// patterns below are never used to lex anything -- only the declaration order matters.
OPEN_BRACE: '{';
CLOSE_BRACE: '}';
OPEN_PARENTHESIS: '(';
CLOSE_PARENTHESIS: ')';
OPEN_BRACKET: '[';
CLOSE_BRACKET: ']';
OTHER: ~'\n';
FABRICATED_NEWLINE: '\n';

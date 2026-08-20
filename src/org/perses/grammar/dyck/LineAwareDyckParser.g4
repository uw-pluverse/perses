parser grammar LineAwareDyckParser;

options {
    tokenVocab = DyckTokens;
}

start
    : lines EOF
    ;

// Represents a sequence of lines.
lines
    : line*
    ;

// Represents a single logical line that ends with a newline.
// By greedily consuming nodes, tokens and blocks occurring on the
// same line (e.g., `int f() { ... }`) are grouped together into a single line unit.
line
    : node+ FABRICATED_NEWLINE?
    | FABRICATED_NEWLINE
    ;

// Represents a component on a line: either a flat sequence of text
// or a bracketed block that recursively contains more lines.
node
    : text
    | OPEN_BRACE lines CLOSE_BRACE
    | OPEN_PARENTHESIS lines CLOSE_PARENTHESIS
    | OPEN_BRACKET lines CLOSE_BRACKET
    ;

// Represents a flat sequence of non-newline, non-bracket tokens.
text
    : OTHER+
    ;

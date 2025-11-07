parser grammar BraceDyckParser;

tokens {
    OPEN_BRACE,
    CLOSE_BRACE,
    OPEN_PARENTHESIS,
    CLOSE_PARENTHESIS,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    OTHER
}

start
    : stmt_list EOF
    ;

stmt_list
    : stmt*
    ;

stmt
    : others
    | OPEN_BRACE stmt_list CLOSE_BRACE
    | OPEN_PARENTHESIS stmt_list CLOSE_PARENTHESIS
    | OPEN_BRACKET stmt_list CLOSE_BRACKET
    ;

others
    : OTHER+
    ;
grammar lexer_skip;

ID
    : ('a' | 'b' ) 'c' -> skip
    ;

D2
    : ('a' | 'b') -> skip
    ;

D3
    : 'a' -> skip
    ;
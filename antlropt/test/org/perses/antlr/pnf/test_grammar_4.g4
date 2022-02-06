grammar test_grammar_4;

a
    : b c
    | d
    |
    ;

b
    : a d
    | c d
    ;

c
    : 'c'
    ;

d
    : 'd'
    ;

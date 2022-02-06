grammar test_grammar_1;

s
    : a
    | ~('c' | 'd')
    | b+
    ;

a
    : c b
    | d
    |
    ;

b
    : c d
    | d
    | d c b
    | d d
    ;

c
    : 'c'
    ;

d
    : 'd'
    ;
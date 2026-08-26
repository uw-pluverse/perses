grammar test_grammar_15;

// c is epsilon-only; inlining it makes b epsilon-only, and then a. One pass
// call must chase the whole chain.
s
    : a 'k'
    | b
    | d
    ;

a
    : b
    ;

b
    : c
    ;

c
    :
    ;

d
    : 'x'
    |
    ;

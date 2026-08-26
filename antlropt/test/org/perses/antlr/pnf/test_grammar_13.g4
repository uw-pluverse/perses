grammar test_grammar_13;

s
    : a
    | 'k' self_ref
    ;

a
    : 'x' b?
    ;

b
    : 'y'
    ;

self_ref
    : self_ref 'r'
    | 'r'
    ;

// Reachable only from other dead rules.
dead_1
    : 'z' dead_2
    ;

dead_2
    : 'w' dead_1
    | a
    ;

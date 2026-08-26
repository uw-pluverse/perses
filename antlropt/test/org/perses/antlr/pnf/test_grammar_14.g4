grammar test_grammar_14;

// single_use has several alternatives and exactly one reference: inlined into s
// while keeping s's alternative order. shared is referenced twice: kept.
// single_alt has one alternative: kept.
s
    : 'k'
    | single_use
    | shared
    | single_alt
    ;

single_use
    : 'x'
    | 'y' 'z'
    ;

shared
    : 'p'
    | 'q'
    ;

single_alt
    : 'm' shared
    ;

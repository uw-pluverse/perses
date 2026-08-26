grammar test_grammar_12;

// a and b have identical bodies: b is merged into a (the smaller name) and
// references to b are renamed. dup_of_start is identical to the start rule s
// and is merged into s, because the start rule is always kept.
s
    : a b
    | c
    ;

dup_of_start
    : a b
    | c
    ;

a
    : 'x'
    | 'y'
    ;

b
    : 'x'
    | 'y'
    ;

c
    : b dup_of_start
    | 'z'
    ;

// Also duplicates a; merged even though nothing references it.
unused_dup
    : 'x'
    | 'y'
    ;

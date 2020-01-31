grammar pnf_test;

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

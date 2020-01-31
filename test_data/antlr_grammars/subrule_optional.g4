grammar subrule_optional;

start
    : a?
    ;

a
    : b a?
    ;

b
    : 'id'
    ;
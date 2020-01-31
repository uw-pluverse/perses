grammar subrule_star;

start
    : a*
    ;

a
    : b a*
    ;

b
    : 'id'
    ;
grammar subrule_plus;

start
    : a+
    ;

a
    : b a+
    ;

b
    : 'id'
    ;
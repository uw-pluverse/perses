grammar subrule_alternative;

start
    : a | b
    ;

a
    : c | ID?
    ;

b
    : 'id' c
    ;

c
    : d
    ;

d
    : ID
    ;

ID
    : 'id'
    ;
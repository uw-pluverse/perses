grammar subrule_sequence;

start
    : a? b? c?
    ;

a
    : b a?
    ;

b
    : 'id' c
    ;

c
    : d
    ;

d
    : 'd'
    ;
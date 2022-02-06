grammar assoc_right_2;

start
    : s EOF;

s
    : <assoc=right> s '**' s
    | <assoc=right> s '++' s
    | <assoc=right> s '--' s
    | '1'
    ;

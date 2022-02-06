grammar assoc_right;

start
    : <assoc=right> start '**' start
    ;
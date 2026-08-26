grammar test_grammar_11;

// <assoc=...> element options are stripped; everything else is kept.
expr
    : <assoc=right> expr '^' expr
    | expr '+' expr
    | '-' expr
    | ID
    ;

other
    : ID '=' expr
    ;

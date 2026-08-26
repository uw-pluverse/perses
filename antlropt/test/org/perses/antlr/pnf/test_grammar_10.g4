grammar test_grammar_10;

s
    : list
    | cond
    | mixed
    | outlined_list
    | outlined_cond
    ;

// direct right recursion under a trailing optional: a : Y a?
list
    : 'c' list?
    | 'd' list?
    ;

// a : Y (Z a)?
cond
    : 'x' ('?' 'y' ':' cond)?
    ;

// a : Y (Z1 a | W)?
mixed
    : 'm' ('+' mixed | '-')?
    ;

// the shapes above after QuantifiedAstNormalizationPass has outlined the optional
outlined_list
    : 'c' opt_outlined_list
    | 'd' opt_outlined_list
    ;

opt_outlined_list
    : outlined_list?
    ;

outlined_cond
    : 'x' opt_outlined_cond
    | 'z'
    ;

opt_outlined_cond
    : tail_outlined_cond?
    ;

tail_outlined_cond
    : '?' 'y' ':' outlined_cond
    ;

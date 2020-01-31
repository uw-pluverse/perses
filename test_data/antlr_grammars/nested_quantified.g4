grammar nested_quantified;

start
    : ('A' ('C' | 'D')+ 'B'?)* 'E'?
    ;
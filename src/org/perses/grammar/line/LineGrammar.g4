grammar LineGrammar;

LINE
    : (~'\n')+
    ;

NEWLINE
    : '\n' -> skip
    ;

lines
    : LINE* EOF
    ;
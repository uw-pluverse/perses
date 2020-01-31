grammar parentheses;

start
    : (A | r1 | r2) r3
    ;

rule_2
    : ID ((A | r1 | r2) r4 | r5) ID
    ;
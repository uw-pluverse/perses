// A tiny language shared by the kitten tests that pin seeded-random golden values
// (node-type ids, generated trees, mutated programs). Any grammar change renumbers
// rules and reshuffles seeded choices, so the goldens must be derived from this
// small frozen grammar instead of the real language grammars, which evolve.
//
// The rules deliberately cover every shape the encoders and mutators care about:
// Kleene stars (program, block), alternative blocks (stmt, expr, atom),
// single-child collapse chains (stmt -> assign, expr -> atom), recursion (stmt -> block -> stmt),
// keywords, punctuation, identifiers, and number literals.
grammar Tiny;

program
    : stmt* EOF
    ;

stmt
    : assign
    | print
    | block
    ;

assign
    : ID '=' expr ';'
    ;

print
    : 'print' expr ';'
    ;

block
    : '{' stmt* '}'
    ;

expr
    : atom
    | addition
    ;

addition
    : atom '+' atom
    ;

atom
    : ID
    | NUM
    ;

ID : [a-z] [a-z0-9_]* ;
NUM : [0-9]+ ;
WS : [ \t\r\n]+ -> skip ;

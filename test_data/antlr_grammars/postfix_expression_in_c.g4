grammar postfix_expression_in_c;

postfixExpression
    :  primaryExpression
    | '(' typeName ')' '{' initializerList optional__comma '}'
    | '__extension__' '(' typeName ')' '{' initializerList optional__comma '}' ( '[' expression ']' |  '(' optional__argumentExpressionList ')' |  '.' Identifier |  '->' Identifier |  '++' |  '--')*
    ;
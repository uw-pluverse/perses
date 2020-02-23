parser grammar G;

primaryExpr
    : Operand
    | Conversion
    | primaryExpr ( DOT IDENTIFIER
                  | Index
                  | Slice
                  | TypeAssertion
                  | Arguments)
    ;

grammar left_recursion;

id
    : 'hello' 'world'
    ;

start
    : id
    | start '[]'
    | start '()'
    | start '.' id
    | start '->' id
    | start '++'
    | start '--'
    | '(' id ')'
    | 'extension' '(' id ')'
    ;
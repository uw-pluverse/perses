grammar rule_element_label;

start
    :left = exp '+' middle = exp+ '*' + right += ~ID
    ;

exp
    : '*'
    ;

ID
    : 'ID'
    ;
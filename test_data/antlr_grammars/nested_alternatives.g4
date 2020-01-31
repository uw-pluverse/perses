grammar nested_alternatives;

start
    : (a | b | c) | 't' | (ID | 'm')
    ;
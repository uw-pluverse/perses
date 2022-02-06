grammar test_grammar_8;

start
    : rule*
    | ID*
    | 'test'*
    | ('A' | 'B')*
    | ('C' | 'D' | 'E')*
    | ('F' | 'G' | another)*
    ;
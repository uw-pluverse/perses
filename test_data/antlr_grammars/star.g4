grammar star;

start
    : rule*
    | ID*
    | 'test'*
    | ('A' | 'B')*
    | ('C' | 'D' | 'E')*
    | ('F' | 'G' | another)*
    ;
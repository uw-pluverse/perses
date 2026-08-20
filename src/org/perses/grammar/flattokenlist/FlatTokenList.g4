parser grammar FlatTokenList;

tokens {
    TOKEN
}

start
    : TOKEN* EOF
    ;

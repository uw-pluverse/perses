lexer grammar lexer_pushMode;

COMMENT : '<!--' .*? '-->' ;
CDATA   : '<![CDATA[' .*? ']]>' ;
OPEN : '<' -> pushMode(INSIDE) ;

XMLDeclOpen : '<?xml' -> pushMode(INSIDE) ;
SPECIAL_OPEN: '<?' -> more, pushMode(INSIDE) ;
// ----------------- Everything INSIDE of a tag ---------------------
mode INSIDE;
CLOSE        : '>' -> popMode ;
SPECIAL_CLOSE: '?>' -> popMode ; // close <?xml...?>
SLASH_CLOSE  : '/>' -> popMode ;

LQUOTE : '"' -> more, mode(STR) ;
WS : [ \r\t\n]+ -> skip ;
mode STR;
STRING : '"' -> mode(DEFAULT_MODE) ; // token we want parser to see
TEXT : . -> more ; // collect more text for string

DOUBLE : '"' .*? '"'   -> type(STRING) ;
SINGLE : '\'' .*? '\'' -> type(STRING) ;
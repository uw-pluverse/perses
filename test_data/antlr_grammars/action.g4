grammar action;

decl: type ID ';' {System.out.println("found a decl");} ;
type: 'int' | 'float' ;
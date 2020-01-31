






struct s { int a; int b; };
char x[((sizeof (struct s){ 1, 2 }) == sizeof (struct s)) ? 1 : -1];

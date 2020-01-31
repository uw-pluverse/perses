



struct s { char c; } a, b;
int c;
char x[sizeof ((c ? a : b).c) == 1 ? 1 : -1];

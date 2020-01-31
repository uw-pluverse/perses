



static int dummy = 0;
extern int foo __attribute__((__weak__, __alias__("dummy")));
int bar() { if (foo) return 1; return 0; }

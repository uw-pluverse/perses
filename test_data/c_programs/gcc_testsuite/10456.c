






#pragma redefine_extname foo bar
extern int foo(void);
int (*p)(void) = foo;

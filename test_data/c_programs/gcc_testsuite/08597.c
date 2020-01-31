


static int i;
extern void baz(int);
void foo() { i = 3; }
void bar() { baz(i ? 2 : 1); }

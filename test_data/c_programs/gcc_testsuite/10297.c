


struct S { const char *s; };
const struct S s[] = { "s" };
extern void foo (void (*) (void));
static void bar (void) {}
void baz () { foo (bar); }




struct A { int a; };
extern void *y;

__attribute__((optimize (0))) void
foo (void *p, struct A x)
{
  foo (y, x);
}

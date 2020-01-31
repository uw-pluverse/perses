




struct S { int a; int b; } s[4], *t;
struct U { int a[10]; } u[4], *v;
volatile int *a, *b, *c;
volatile void *d;
volatile int e[4][4];

int
main (void)
{
  t = &s[4];
  a = &s[4].a;
  b = &s[4].b;
  d = &e[4];
  c = &e[4][0];
  c = &e[3][4];
  c = &e[3][3];

  a = &u[4].a[9];
  a = &u[4].a[10];
  a = &u[3].a[9];
  a = &u[3].a[10];
  a = &u[3].a[11];

  return 0;
}

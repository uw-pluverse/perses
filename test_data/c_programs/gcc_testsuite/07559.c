




struct S { unsigned int a; unsigned int *b; };
struct T { struct S a; struct S b; };
struct U { const char *u; };
int n[10];
volatile int v;

struct U
foo (const char *s)
{
  struct U r;
  r.u = s;
  return r;
}

void
bar (struct T *s, int a, int b)
{
  s->a.a = a;
  s->a.b = &s->a.a;
  s->b.a = b;
  s->b.b = &s->b.a;
}

int
main ()
{
  struct T t;
  struct U x = foo ("this is x");
  struct S y, z;
  y.b = n;
  y.a = 0;
  bar (&t, 17, 21);
  v++;
  z = y;
  return 0;
}

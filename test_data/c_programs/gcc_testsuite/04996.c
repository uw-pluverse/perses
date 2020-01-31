


int
f1 (unsigned int x)
{
  int c = ({ union { unsigned int a; int b; } u; u.a = x; u.b; });
  return c;
}

void
f2 (void)
{
  struct S { int i; } a;
  int b[1];
  a.i = 1;
  a.i;
  b[0] = 1;
  b[0];
}

void
f3 (void)
{
  struct S { int i; } a;
  int b[1];
  a.i = 1;
  b[0] = 1;
}





void
foo (void)
{
  int a, b, c, d, e, f, g;
  a = 1;
  b = 2;
  c = 3;
  d = 4;
  e = 5;
  f = 6;
  g = 7;
  a;
  b, 1;
  (void) c;
  (void) d, 1;
  e, f, 1;
  (void) g, f, 1;
}

void
bar (void)
{
  int a;
  int b;
  int c;
  a = 1;
  b = 2;
  c = 3;
  c = ({ a++, b; });
}

void
baz (void)
{
  int a;
  int b;
  int c;
  int d;
  a = 1;
  b = 2;
  c = 3;
  d = 4;
  d, ( a++, b ), c;
}

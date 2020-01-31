



typedef struct {
  int a[8];
} foo;

foo f;

int
test ()
{
  foo g;
  g.a[0] = 1; g.a[1] = 2; g.a[2] = 3; g.a[3] = 4;
  g.a[4] = 5; g.a[5] = 6; g.a[6] = 7; g.a[7] = 8;
  f=g;
  return f.a[2];
}

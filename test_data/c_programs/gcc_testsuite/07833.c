



struct S
{
  int *a;
  int b;
  int **c;
  int d;
};

void foo (struct S *);
void bar (struct S *);

int
baz (void)
{
  struct S s;
  foo (&s);
  {
    int a[s.b];
    int *c[s.d];
    s.a = a;
    s.c = c;
    bar (&s);
  }
  return 0;
}

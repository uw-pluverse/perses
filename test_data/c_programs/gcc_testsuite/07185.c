extern int foo1();
extern int foo2();

void foo(int n, int b)
{
  int i, a;

  foo1();

  a = (long)(b * ((double) 0.1));

  for (i=0; i < n; i++) {
    foo2(a);
  }
}

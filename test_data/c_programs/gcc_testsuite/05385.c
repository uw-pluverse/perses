





struct X { int i; int j; };

void foo(void)
{
  struct X x;
  x.i = 1;
  x.j = 2;
}


int bar(struct X x)
{
  return x.i;
}


extern void do_something (struct X);

void bar2(int i, int j)
{
  struct X x;

  x.i = i;
  x.j = j;
  do_something (x);
}

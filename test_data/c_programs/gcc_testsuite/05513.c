

int p;
int r;

__attribute__ ((noinline))
static int a(void)
{
  return p;
}
int foo(int argc)
{
  int q;
  q = a();




  if (argc)
    r = 9;
  return q + a();
}

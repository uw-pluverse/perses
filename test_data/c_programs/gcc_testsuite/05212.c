


struct A { int i; };
int
foo(struct A *locp, int str)
{
  int T355, *T356;
  T356 = &locp->i;
  *T356 = str;
  return locp->i;
}

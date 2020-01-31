


int foo (double xx, double xy)
{
  int p = xx < xy;
  int np = !p;
  if (np)
    return 5;
  return 2;
}

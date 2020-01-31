

int foo(int *a, int argc)
{
  int c;
  int d, e;


  d = *a;
  if (argc)
    {
      a = &c;
    }
  e = *a;
  return d + e;
}

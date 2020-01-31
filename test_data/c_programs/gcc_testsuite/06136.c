

typedef int type[2];
int foo(type *a, int argc)
{
  type c = {0, 1};
  int d, e;


  d = (*a)[0];
  if (argc)
    {
      a = &c;
    }
  e = (*a)[0];
  return d + e;
}

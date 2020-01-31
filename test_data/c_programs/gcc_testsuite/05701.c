

typedef int type[2];
int foo(type *a, int argc, int t)
{
  type c = {0, 1};
  int d, e;


  d = (*a)[t];
  if (argc)
    {
      a = &c;
    }
  e = (*a)[t];
  return d + e;
}

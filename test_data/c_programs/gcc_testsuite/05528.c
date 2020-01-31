

typedef int type[2];
int foo(type *a, int argc)
{
  int d, e;


  d = (*a)[argc];
  if (argc)
      a++;
  e = (*a)[argc];
  return d + e;
}

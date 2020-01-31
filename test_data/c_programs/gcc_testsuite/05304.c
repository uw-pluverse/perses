

typedef int type[2];
int foo(type *a, int argc)
{
  int d, e;


  d = (*a)[0];
  if (argc)
      a++;
  e = (*a)[0];
  return d + e;
}

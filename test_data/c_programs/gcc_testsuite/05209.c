

typedef int type[2];
int foo(type *a, int argc)
{
  int d, e;


  d = (*a)[argc];
  if (!d)
      argc++;
  e = (*a)[argc];
  return e;
}

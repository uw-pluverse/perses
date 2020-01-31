

struct X { int i; };
int foo(struct X *a, int argc)
{
  int i;
  int e;

  for (i = 0; i < argc; i++)
    {
      e = a->i;
      a->i = 9;
    }
  return e;
}

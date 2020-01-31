


int a;

int foo(int argc)
{
  int i;
  int e;

  for (i = 0; i < argc; i++)
    {
      e = a;
      a = 9;
    }
  return e;
}

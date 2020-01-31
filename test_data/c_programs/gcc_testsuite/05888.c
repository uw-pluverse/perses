


struct {
  int a;
  int large[100];
} x;

int foo(int argc)
{
  int c;
  int i;
  int e;

  for (i = 0; i < argc; i++)
    {
      e = x.a;
      x.a = 9;
    }
  return e;
}

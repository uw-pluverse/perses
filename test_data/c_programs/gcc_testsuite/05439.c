


int
foo (int a, int b, int c)
{
  int *p;
  if (c)
    p = &a;
  else
    p = &b;

  *p = 3;
  *p = 4;
  return *p;
}

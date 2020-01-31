



int
t(int a, int b, int c)
{
  int *p;
  if (a)
    p = &a;
  else
    p = &c;
  return *p;
}

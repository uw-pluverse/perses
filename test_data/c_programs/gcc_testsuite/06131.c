


int c, d;

int
bar (int a)
{
  void *p;
  int b;

  if (a!=0)
    {
      b = 3;
      p = &&L0;
    }
  else
    {
      b = 5;
      p = &&L1;
    }

  goto *p;

 L0:
  c = b;
  return 1;

 L1:
  d = b;
  return 0;
}

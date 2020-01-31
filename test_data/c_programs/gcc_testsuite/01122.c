




int f (int a, int b, int c)
{
  if (a == 0)
    return b;
  else
    return c;
}

int g (int a, int b, int c)
{
  if (a != 0)
    return b;
  else
    return c;
}

extern int i (int);
extern int j (int);
extern int k (int);

int h (int a)
{
  int x;





  if (a == 1)
    x = i (37);
  else
    x = j (42);
  return x + a + k (x);
}

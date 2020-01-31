


int foo (int i, int j, int b)
{
  int res = 0;
  if (b)
    res = i/j;

  res += i/j;
  return res;
}

extern void bar (void);
int foo2 (int i, int j, int b)
{
  int res = 0;
  if (b)
    res = i/j;


  res += i/j;
  bar ();
  return res;
}

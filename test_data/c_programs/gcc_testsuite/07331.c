




int a[512];
int foo()
{
  int i, res = 0;
  for (i=0; i<512; i++)
  {
    if (a[i] != 0)
      res += 1;
  }
  return res;
}

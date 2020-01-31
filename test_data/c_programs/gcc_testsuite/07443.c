



int a[512], b[512];
void foo(int k)
{
  int i, res = 0;
  for (i=0; i<512; i++)
  {
    if (b[i] != 0)
      res += b[i];
  }
  a[k] = res;
}

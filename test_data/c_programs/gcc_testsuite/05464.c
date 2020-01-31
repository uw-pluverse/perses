




short a[(2048)];
short foo (int len, int v)
{
  int i;
  for (i = 0; i < len; i++) {
      a[i] = v;
  }
  return a[0];
}

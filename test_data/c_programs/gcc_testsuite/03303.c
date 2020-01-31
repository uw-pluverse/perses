


int ssbgst (int c, int k)
{
  int a, i, j;

  a = 0;
  i = 1;
  j = k;
  while (j)
    {
      a += (j + i) * (k + i + c) + (j + i + c);
      j = j - 1;
    }
  return a;
}

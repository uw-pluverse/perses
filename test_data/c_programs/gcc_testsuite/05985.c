


int foo (int i)
{
  int k = i + 1;
  int j = i + 1;
  if (k != j)
    k = k + 1;
  if (k != j)
    k = k + 1;
  k = k - i;
  return k;
}






int t (int a, int b)
{
  if (a > 0)
    goto L1;
  if (b > 0)
    goto L1;
  return 0;
L1:
  return 1;
}

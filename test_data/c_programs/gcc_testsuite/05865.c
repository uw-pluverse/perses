




int t (int a, int b)
{
  if (a > 0)
    goto L1;
  else
    goto L2;
L1:
  if (b > 0)
    goto L2;
  return 5;
L2:
  return 6;
}

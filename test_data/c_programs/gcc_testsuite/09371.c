



void foo(short a[], short m)
{
  int i, j;
  int f1[10];
  short nc;

  nc = m + 1;
  if (nc > 3)
    {
      for (i = 0; i <= nc; i++)
 {
   f1[i] = f1[i] + 1;
 }
    }

  for (i = 0, j = m; i < nc; i++, j--)
    {
      a[i] = f1[i];
      a[j] = i;
    }
  return;
}

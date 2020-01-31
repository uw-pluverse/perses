


void foo (int a[], int b[])
{
  int i;
  for (i = 0; i < 100; i++)
    {
      if (a[i] == 0)
 a[i] = b[i]*4;
      else
 a[i] = b[i]*3;
    }
}

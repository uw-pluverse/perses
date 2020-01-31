




int
foo (int *x, int *z, int a)
{
  int b = 0;
  int c = 0;
  int d = 0;
  int i;

  for (i = 0; i < a; i++)
    {
      if (x[i] < c)
 {
   b = z[i];
   if (c < b)
     {
       c = b;
       d = i;
     }
 }
    }

  return c + d;
}

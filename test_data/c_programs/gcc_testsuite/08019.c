





extern int foo (int, int);
int
main (void)
{
  int a[50];
  int b[50];
  int i, j, k;
  for (i = 4; i < 30; i++)
    {
      for (j = 3; j < 40; j++)
 {
   for (k = 9; k < 50; k++)
     {
       b[j] = a[i];
       a[k] = b[i];
     }
 }
    }
  foo (a[i], b[i]);
}

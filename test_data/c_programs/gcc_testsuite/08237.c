
int max = 33333;
int a[8];
int
main ()
{
  int i;
  for (i = 0; i < max; i++)
    {
      a[i % 8]++;
    }
  return 0;
}

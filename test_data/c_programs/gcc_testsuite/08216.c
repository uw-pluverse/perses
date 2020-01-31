
int a[1000];
int b = 256;
int c = 257;
int
main ()
{
  int i;
  int n;
  for (i = 0; i < 1000; i++)
    {
      if (i % 17)
 n = c;
      else n = b;
      a[i] /= n;
    }
  return 0;
}

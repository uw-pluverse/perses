
int a[1000];
int b[1000];
int size=1;
int max=10000;
int
main()
{
  int i;
  for (i=0;i<max; i++)
    {
      __builtin_memcpy (a, b, size * sizeof (a[0]));
      asm("");
    }
   return 0;
}

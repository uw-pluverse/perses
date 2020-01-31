
void abort ();

int a[1000];
int
__attribute__ ((noinline))
t()
{
  int i;
  for (i=0;i<1000;i++)
    if (!a[i])
      return 1;
  abort ();
}
int
main()
{
  int i;
  for (i=0;i<1000;i++)
    t();
  return 0;
}

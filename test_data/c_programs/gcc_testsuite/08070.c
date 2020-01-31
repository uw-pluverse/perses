





int a[1000];

static int __attribute__((noinline))
foo (void)
{
  int j;
  int i;


  for (i = 0; i < 1000; i++)
    for (j = 0; j < 1000; j++)
      a[j] = a[i] + 1;

  return a[0];
}

extern void abort ();

int
main (void)
{
  int i, res;

  for (i = 0; i < 1000; i++)
    a[i] = i;

  res = foo ();





  if (res != 1999)
    abort ();

  return 0;
}

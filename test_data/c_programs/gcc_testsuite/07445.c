




extern void abort (void);



static void __attribute__((noinline, noclone, optimize("-fno-tree-vectorize")))
init (unsigned *results, unsigned *pData)
{
  unsigned int i;
  for (i = 0; i < 1000; ++i)
    pData[i] = i % 3;
}

static void __attribute__((noinline, noclone, optimize("-fno-tree-vectorize")))
check (unsigned *results)
{
  unsigned sum = 0;
  for (int idx = 0; idx < (int)1000; idx++)
    sum += results[idx];

  if (sum != 1998)
    abort ();
}

int
main (void)
{
  unsigned results[1000];
  unsigned pData[1000];
  unsigned coeff = 2;

  init (&results[0], &pData[0]);

 for (int idx = 0; idx < (int)1000; idx++)
    results[idx] = coeff * pData[idx];

  check (&results[0]);

  return 0;
}

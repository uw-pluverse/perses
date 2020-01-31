

extern void abort (void) __attribute__ ((noreturn));





int
condition_reduction (int *a, int min_v)
{
  int last = 27 + 96;

  for (int i = 0; i < 27; i++)
    if (a[i] > min_v)
      last = i;

  return last;
}

int
main (void)
{
  int a[27] = {
  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
  21, 22, 23, 24, 25, 26, 27
  };

  int ret = condition_reduction (a, 46);


  if (ret != 27 + 96)
    abort ();

  return 0;
}

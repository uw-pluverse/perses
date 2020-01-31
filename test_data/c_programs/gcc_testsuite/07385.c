

extern void abort (void) __attribute__ ((noreturn));






signed int
condition_reduction (signed int *a, signed int min_v)
{
  signed int last = -1;

  for (signed int i = 0; i < 32; i++)
    if (a[i] < min_v)
      last = -i;

  return last;
}

int
main (void)
{
  signed int a[32] = {
  11, -12, 13, 14, 15, 16, 17, 18, 19, 20,
  1, 2, -3, 4, 5, 6, 7, -8, 9, 10,
  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
  31, 32
  };

  signed int ret = condition_reduction (a, 16);

  if (ret != -19)
    abort ();

  return 0;
}

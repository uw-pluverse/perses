

extern void abort (void) __attribute__ ((noreturn));





unsigned char
condition_reduction (unsigned char *a, unsigned char min_v)
{
  unsigned char last = 65;

  for (unsigned char i = 0; i < 254; i++)
    if (a[i] < min_v)
      last = a[i];

  return last;
}

int
main (void)
{
  unsigned char a[254] = {
  11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
  21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
  31, 32
  };
  __builtin_memset (a+32, 43, 254 -32);

  unsigned char ret = condition_reduction (a, 16);

  if (ret != 10)
    abort ();

  return 0;
}

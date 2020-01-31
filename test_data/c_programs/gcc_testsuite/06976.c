


extern void abort (void);
extern void exit (int);




typedef unsigned long int uint64_t;
uint64_t a, b, c;

int
foo (uint64_t x, uint64_t y, uint64_t z, int i)
{
  a = x;
  b = y;
  c = z;
  return 2 * i;
}

int
main (void)
{
  if (foo (1234512345123ull, 3456734567345ull, 7897897897897ull, 42) != 84)
    abort ();
  if (a != 1234512345123ull)
    abort ();
  if (b != 3456734567345ull)
    abort ();
  if (c != 7897897897897ull)
    abort ();
  exit (0);
}

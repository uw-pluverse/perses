



extern void exit (int);
extern void abort (void);

volatile long double a = 0x1p-1024L;
volatile long double b = 0x3p-53L;
volatile long double r;
volatile long double expected = 0x1.55555555555555555555555555p-973L;

int
main (void)
{
  r = a / b;

  if (__builtin_fabsl (r - expected) > 0x1p-1073L)
    abort ();
  exit (0);
}

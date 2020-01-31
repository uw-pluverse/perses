


extern void abort (void);

volatile long double l, m, n;

int
main (void)
{
  l = __builtin_copysignl (0.0L, -1.0L);
  m = __builtin_copysignl (0.0L, -1.0L);
  n = l + m;
  if (__builtin_copysignl (1.0L, n) >= 0.0L)
    abort ();
  return 0;
}

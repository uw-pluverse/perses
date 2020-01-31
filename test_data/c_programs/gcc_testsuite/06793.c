



typedef double __m128d __attribute__ ((__vector_size__ (16), __may_alias__));




typedef __m128d __attribute__((aligned(1))) unaligned;

extern void abort (void);


__m128d __attribute__((noinline))
foo (__m128d a1, __m128d a2, __m128d a3, __m128d a4,
     __m128d a5, __m128d a6, __m128d a7, __m128d a8,
     int b1, int b2, int b3, int b4, int b5, int b6, int b7, unaligned y)
{
  return y;
}

void
do_test (void)
{
  unaligned x;
  __m128d y = { 0 };
  x = y;
  y = foo (y, y, y, y, y, y, y, y, 1, 2, 3, 4, 5, 6, -1, x);
  if (__builtin_memcmp (&y, &x, sizeof (y)) != 0)
    abort ();
}

int
main (void)
{
  do_test ();
  return 0;
}


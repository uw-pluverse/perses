


typedef long int intmax_t;


extern int abs (int);
extern long labs (long);
extern long long llabs (long long);
extern intmax_t imaxabs (intmax_t);
extern void abort (void);
extern void link_error (void);

void
main_test (void)
{


  volatile int i0 = 0, i1 = 1, im1 = -1, imin = -2147483647, imax = 2147483647;
  volatile long l0 = 0L, l1 = 1L, lm1 = -1L, lmin = -9223372036854775807L, lmax = 9223372036854775807L;
  volatile long long ll0 = 0LL, ll1 = 1LL, llm1 = -1LL;
  volatile long long llmin = -9223372036854775807LL, llmax = 9223372036854775807LL;
  volatile intmax_t imax0 = 0, imax1 = 1, imaxm1 = -1;
  volatile intmax_t imaxmin = -9223372036854775807L, imaxmax = 9223372036854775807L;
  if (abs (i0) != 0)
    abort ();
  if (abs (0) != 0)
    link_error ();
  if (abs (i1) != 1)
    abort ();
  if (abs (1) != 1)
    link_error ();
  if (abs (im1) != 1)
    abort ();
  if (abs (-1) != 1)
    link_error ();
  if (abs (imin) != 2147483647)
    abort ();
  if (abs (-2147483647) != 2147483647)
    link_error ();
  if (abs (imax) != 2147483647)
    abort ();
  if (abs (2147483647) != 2147483647)
    link_error ();
  if (labs (l0) != 0L)
    abort ();
  if (labs (0L) != 0L)
    link_error ();
  if (labs (l1) != 1L)
    abort ();
  if (labs (1L) != 1L)
    link_error ();
  if (labs (lm1) != 1L)
    abort ();
  if (labs (-1L) != 1L)
    link_error ();
  if (labs (lmin) != 9223372036854775807L)
    abort ();
  if (labs (-9223372036854775807L) != 9223372036854775807L)
    link_error ();
  if (labs (lmax) != 9223372036854775807L)
    abort ();
  if (labs (9223372036854775807L) != 9223372036854775807L)
    link_error ();
  if (llabs (ll0) != 0LL)
    abort ();
  if (llabs (0LL) != 0LL)
    link_error ();
  if (llabs (ll1) != 1LL)
    abort ();
  if (llabs (1LL) != 1LL)
    link_error ();
  if (llabs (llm1) != 1LL)
    abort ();
  if (llabs (-1LL) != 1LL)
    link_error ();
  if (llabs (llmin) != 9223372036854775807LL)
    abort ();
  if (llabs (-9223372036854775807LL) != 9223372036854775807LL)
    link_error ();
  if (llabs (llmax) != 9223372036854775807LL)
    abort ();
  if (llabs (9223372036854775807LL) != 9223372036854775807LL)
    link_error ();
  if (imaxabs (imax0) != 0)
    abort ();
  if (imaxabs (0) != 0)
    link_error ();
  if (imaxabs (imax1) != 1)
    abort ();
  if (imaxabs (1) != 1)
    link_error ();
  if (imaxabs (imaxm1) != 1)
    abort ();
  if (imaxabs (-1) != 1)
    link_error ();
  if (imaxabs (imaxmin) != 9223372036854775807L)
    abort ();
  if (imaxabs (-9223372036854775807L) != 9223372036854775807L)
    link_error ();
  if (imaxabs (imaxmax) != 9223372036854775807L)
    abort ();
  if (imaxabs (9223372036854775807L) != 9223372036854775807L)
    link_error ();
}

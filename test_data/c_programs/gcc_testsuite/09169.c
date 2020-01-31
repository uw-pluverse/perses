


extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));

int d, i;

struct S
{
  int f0;
} *b, c, e, h, **g = &b;

static struct S *f = &e;

int
fn1 (int p)
{
  int a = 0;
  return a || p < 0 || p >= 2 || 1 >> p;
}

int
main ()
{
  int k = 1, l, *m = &c.f0;

  for (;;)
    {
      l = fn1 (i);
      *m = k && i;
      if (l)
 {
   int n[1] = {0};
 }
      break;
    }

  *g = &h;

  ((b) ? (void) (0) : __assert_fail ("b", "../gcc-seed-programs/gcc.dg/pr64007.c", 40, __PRETTY_FUNCTION__));

  if (d)
    (*m)--;
  d = (f != 0) | (i >= 0);

  if (c.f0 != 0)
    __builtin_abort ();

  return 0;
}

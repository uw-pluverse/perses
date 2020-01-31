
extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));

static inline int
blk_oversized_queue (int* q)
{
  if (q[2])
    return q[1] != 0;
  return q[0] == 0;
}

int __attribute__ ((noinline))
get_request (int* q, int rw)
{
  if (blk_oversized_queue (q))
    {
      if ((rw == 1) || (rw == 0))
 return -33;

      return 0;
    }

  return -100;
}

int main (void)
{
  int x[3];
  int r;

  x[0] = 0; x[1] = 1; x[2] = 1;
  r = get_request (x, 0);
  ((r == -33) ? (void) (0) : __assert_fail ("r == -33", "../gcc-seed-programs/gcc.dg/torture/pr51244-21.c", 33, __PRETTY_FUNCTION__));

  r = get_request (x, 1);
  ((r == -33) ? (void) (0) : __assert_fail ("r == -33", "../gcc-seed-programs/gcc.dg/torture/pr51244-21.c", 36, __PRETTY_FUNCTION__));

  r = get_request (x, 2);
  ((r == 0) ? (void) (0) : __assert_fail ("r == 0", "../gcc-seed-programs/gcc.dg/torture/pr51244-21.c", 39, __PRETTY_FUNCTION__));


  x[0] = 0; x[1] = 0; x[2] = 1;
  r = get_request (x, 0);
  ((r == -100) ? (void) (0) : __assert_fail ("r == -100", "../gcc-seed-programs/gcc.dg/torture/pr51244-21.c", 44, __PRETTY_FUNCTION__));

  r = get_request (x, 1);
  ((r == -100) ? (void) (0) : __assert_fail ("r == -100", "../gcc-seed-programs/gcc.dg/torture/pr51244-21.c", 47, __PRETTY_FUNCTION__));

  r = get_request (x, 2);
  ((r == -100) ? (void) (0) : __assert_fail ("r == -100", "../gcc-seed-programs/gcc.dg/torture/pr51244-21.c", 50, __PRETTY_FUNCTION__));


  x[0] = 0; x[1] = 0; x[2] = 0;
  r = get_request (x, 0);
  ((r == -33) ? (void) (0) : __assert_fail ("r == -33", "../gcc-seed-programs/gcc.dg/torture/pr51244-21.c", 55, __PRETTY_FUNCTION__));

  r = get_request (x, 1);
  ((r == -33) ? (void) (0) : __assert_fail ("r == -33", "../gcc-seed-programs/gcc.dg/torture/pr51244-21.c", 58, __PRETTY_FUNCTION__));

  r = get_request (x, 2);
  ((r == 0) ? (void) (0) : __assert_fail ("r == 0", "../gcc-seed-programs/gcc.dg/torture/pr51244-21.c", 61, __PRETTY_FUNCTION__));


  x[0] = 0; x[1] = 0; x[2] = 0;
  r = get_request (x, 0);
  ((r == -33) ? (void) (0) : __assert_fail ("r == -33", "../gcc-seed-programs/gcc.dg/torture/pr51244-21.c", 66, __PRETTY_FUNCTION__));

  r = get_request (x, 1);
  ((r == -33) ? (void) (0) : __assert_fail ("r == -33", "../gcc-seed-programs/gcc.dg/torture/pr51244-21.c", 69, __PRETTY_FUNCTION__));

  r = get_request (x, 2);
  ((r == 0) ? (void) (0) : __assert_fail ("r == 0", "../gcc-seed-programs/gcc.dg/torture/pr51244-21.c", 72, __PRETTY_FUNCTION__));

  return 0;
}

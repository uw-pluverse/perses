extern void link_error(int);

void __attribute__ ((__noinline__))
foo (float f, double d, long double ld)
{


  if (__builtin_isinf_sign(f)
      != (__builtin_isinf(f) ? (__builtin_signbitf(f) ? -1 : 1) : 0))
    link_error (19);
  if (__builtin_isinf_sign(d)
      != (__builtin_isinf(d) ? (__builtin_signbit(d) ? -1 : 1) : 0))
    link_error (22);
  if (__builtin_isinf_sign(ld)
      != (__builtin_isinf(ld) ? (__builtin_signbitl(ld) ? -1 : 1) : 0))
    link_error (25);
  if ((__builtin_isinf_sign(f) != 0) != (__builtin_isinf(f) != 0))
    link_error (40);
  if ((__builtin_isinf_sign(d) != 0) != (__builtin_isinf(d) != 0))
    link_error (42);
  if ((__builtin_isinf_sign(ld) != 0) != (__builtin_isinf(ld) != 0))
    link_error (44);

  if ((__builtin_isinf_sign(f) ? 5 : 6) != (__builtin_isinf(f) ? 5 : 6))
    link_error (47);
  if ((__builtin_isinf_sign(d) ? 5 : 6) != (__builtin_isinf(d) ? 5 : 6))
    link_error (49);
  if ((__builtin_isinf_sign(ld) ? 5 : 6) != (__builtin_isinf(ld) ? 5 : 6))
    link_error (51);
}

int main (void)
{
  foo (1, 2, 3);
  return 0;
}

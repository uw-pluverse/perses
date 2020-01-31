typedef union
{
  long double value;
  struct
  {
    unsigned long long msw;
    unsigned long long lsw;
  } parts64;
  struct
  {
    unsigned int w0, w1, w2, w3;
  } parts32;
} ieee854_long_double_shape_type;

static const long double twolm54 = 5.55111512312578270212e-17;

long double foo (long double x, int n)
{
  long long k, hx, lx;
  ieee854_long_double_shape_type qw_u;

  qw_u.value = x;
  hx = qw_u.parts64.msw;
  lx = qw_u.parts64.lsw;

  k = ((hx >> 52) & 0x7ff) + n + 54;

  qw_u.parts64.msw = ((hx & 0x800fffffffffffffULL) | (k << 52));
  qw_u.parts64.lsw = lx;
  x = qw_u.value;

  return x*twolm54;
}

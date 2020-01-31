





union u_ld { long double ld; double d[2]; };

long double
pack (double a, double aa)
{
  union u_ld u;
  u.d[0] = a;
  u.d[1] = aa;
  return u.ld;
}

double
unpack_0 (long double x)
{
  union u_ld u;
  u.ld = x;
  return u.d[0];
}

double
unpack_1 (long double x)
{
  union u_ld u;
  u.ld = x;
  return u.d[1];
}

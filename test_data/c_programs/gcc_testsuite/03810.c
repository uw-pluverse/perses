double
unsigned_to_double1 (u)
     unsigned u;
{
  double d;
  d = (int) u;
  return ((int) u < 0)
    ? d + 4294967296.0
      : d;
}



double
unsigned_to_double2 (u)
     unsigned u;
{
  double d;
  u -= 2147483648;
  d = (int) u;
  return d + 2147483648.0;
}

unsigned
double_to_unsigned (d)
     double d;
{
  d += 2147483648.0;
  return ((int) d) - 2147483648;
}

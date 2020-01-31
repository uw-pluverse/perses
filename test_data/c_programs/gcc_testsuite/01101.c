




long long foo (long long x)
{
  return __builtin_ffsll (x);
}

long long bar (long long x)
{
  return __builtin_clzll (x);
}

long long baz (long long x)
{
  return __builtin_ctzll (x);
}

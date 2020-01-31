

int test_popcount(int a)
{
  return __builtin_popcount(a);
}

long test_popcountl(long a)
{
  return __builtin_popcountl(a);
}

long long test_popcountll(long long a)
{
  return __builtin_popcountll(a);
}

int test_divwe(void)
{
  int a = 74;
  int b = 32;
  return __builtin_divwe(a, b);
}
unsigned int test_divweu(void)
{
  unsigned int a = 74;
  unsigned int b = 32;
  return __builtin_divweu(a, b);
}
long long test_divde(void)
{
  long long a = 74LL;
  long long b = 32LL;
  return __builtin_divde(a, b);
}
unsigned long long test_divdeu(void)
{
  unsigned long long a = 74ULL;
  unsigned long long b = 32ULL;
  return __builtin_divdeu(a, b);
}
long long test_bpermd(void)
{
  long long a = 74LL;
  long long b = 32LL;
  return __builtin_bpermd(a, b);
}

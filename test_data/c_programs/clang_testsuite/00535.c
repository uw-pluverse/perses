void call_p7_builtins(void)
{
  int a = __builtin_divwe(33, 11);
  unsigned int b = __builtin_divweu(33U, 11U);
  unsigned long long d = __builtin_divde(33ULL, 11ULL);
  unsigned long long e = __builtin_divdeu(33ULL, 11ULL);
  unsigned long long f = __builtin_bpermd(33ULL, 11ULL);
}

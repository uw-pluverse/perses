void test_eh_return_data_regno()
{
  volatile int res;
  res = __builtin_eh_return_data_regno(0);
  res = __builtin_eh_return_data_regno(1);
}
long long test_builtin_ppc_get_timebase() {
  return __builtin_ppc_get_timebase();
}

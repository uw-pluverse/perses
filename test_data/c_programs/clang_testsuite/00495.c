int test1(int x) {
  return x;
}
int test2(int) __attribute__((no_instrument_function));
int test2(int x) {
  return x;
}

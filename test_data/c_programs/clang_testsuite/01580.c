int printf(char const *, ...);
void test(void) {
  printf("%zu", (double)42);
  printf("%jd", (double)42);
  printf("%ju", (double)42);
  printf("%td", (double)42);
}
void test_writeback(void) {
  printf("%jn", (long*)0);
  printf("%jn", (unsigned long*)0);
  printf("%jn", (int*)0);
  printf("%zn", (long*)0);
  printf("%tn", (long*)0);
  printf("%tn", (unsigned long*)0);
  printf("%tn", (int*)0);
}

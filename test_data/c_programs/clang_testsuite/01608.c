int printf(const char *restrict, ...);
int scanf(const char * restrict, ...) ;
void test() {
  long notLongEnough = 1;
  long long quiteLong = 2;
  printf("%Ld", notLongEnough);
  printf("%Ld", quiteLong);
  printf("%Z\n", quiteLong);
}
void testAlwaysInvalid() {
  printf("%Lc", 'a');
  printf("%Ls", "a");
}

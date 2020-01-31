int printf(const char *restrict, ...);
int scanf(const char * restrict, ...) ;
void test() {
  int justRight = 1;
  long tooLong = 2;
  printf("%D", justRight);
  printf("%D", tooLong);
  printf("%U", justRight);
  printf("%U", tooLong);
  printf("%O", justRight);
  printf("%O", tooLong);
}

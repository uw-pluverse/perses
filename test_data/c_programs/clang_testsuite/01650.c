int printf(char const *, ...);
void test() {
  typedef signed long int ssize_t;
  printf("%f", (ssize_t) 42);
}

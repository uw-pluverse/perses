int printf(char const *, ...);
int scanf(char const *, ...);
void test(void) {
  printf("%jd", 42.0);
  printf("%ju", 42.0);
  printf("%zu", 42.0);
  printf("%td", 42.0);
  printf("%lc", 42.0);
  printf("%ls", 42.0);
  printf("%S", 42.0);
  printf("%C", 42.0);
  scanf("%jd", 0);
  scanf("%ju", 0);
  scanf("%zu", 0);
  scanf("%td", 0);
  scanf("%lc", 0);
  scanf("%ls", 0);
  scanf("%S", 0);
  scanf("%C", 0);
  typedef void *size_t;
  typedef void *intmax_t;
  typedef void *uintmax_t;
  typedef void *ptrdiff_t;
  printf("%jd", (intmax_t)42);
  printf("%ju", (uintmax_t)42);
  printf("%zu", (size_t)42);
  printf("%td", (ptrdiff_t)42);
}

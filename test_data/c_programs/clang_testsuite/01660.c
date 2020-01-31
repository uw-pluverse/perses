int printf(const char *restrict, ...);
int scanf(const char * restrict, ...);
void f(void) {
  char *cp;
  printf("%qd", (long long)42);
  scanf("%qd", (long long *)0);
  scanf("%ms", &cp);
  printf("%S", L"foo");
  printf("%C", L'x');
  printf("%Li", (long long)42);
  printf("%Lo", (long long)42);
  printf("%Lu", (long long)42);
  printf("%Lx", (long long)42);
  printf("%LX", (long long)42);
  printf("%1$d", 42);
}

int printf(const char *format, ...) __attribute__((format(printf, 1, 2)));
int scanf(const char * restrict, ...) ;
typedef unsigned short wchar_t;
void signed_test() {
  short val = 30;
  printf("val = %I64d\n", val);
  long long bigval = 30;
  printf("val = %I32d\n", bigval);
  printf("val = %Id\n", bigval);
}
void unsigned_test() {
  unsigned short val = 30;
  printf("val = %I64u\n", val);
  unsigned long long bigval = 30;
  printf("val = %I32u\n", bigval);
  printf("val = %Iu\n", bigval);
}
void w_test(wchar_t c, wchar_t *s) {
  printf("%wc", c);
  printf("%wC", c);
  printf("%C", c);
  printf("%ws", s);
  printf("%wS", s);
  printf("%S", s);
  scanf("%wc", &c);
  scanf("%wC", &c);
  scanf("%C", &c);
  scanf("%ws", s);
  scanf("%wS", s);
  scanf("%S", s);
  double bad;
  printf("%wc", bad);
  printf("%wC", bad);
  printf("%C", bad);
  printf("%ws", bad);
  printf("%wS", bad);
  printf("%S", bad);
  scanf("%wc", &bad);
  scanf("%wC", &bad);
  scanf("%C", &bad);
  scanf("%ws", &bad);
  scanf("%wS", &bad);
  scanf("%S", &bad);
}
void h_test(char c, char* s) {
  double bad;
  printf("%hc", bad);
  printf("%hC", bad);
  printf("%hs", bad);
  printf("%hS", bad);
  scanf("%hc", &bad);
  scanf("%hC", &bad);
  scanf("%hs", &bad);
  scanf("%hS", &bad);
}
void z_test(void *p) {
  printf("%Z", p);
  printf("%hZ", p);
  printf("%lZ", p);
  printf("%wZ", p);
  printf("%hhZ", p);
  scanf("%Z", p);
}

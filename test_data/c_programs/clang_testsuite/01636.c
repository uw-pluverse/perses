extern int printf(const char *,...);
extern int scanf(const char *, ...);
typedef enum { Constant = 0 } TestEnum;
void test(TestEnum input) {
    printf("%d", input);
    printf("%d", Constant);
    printf("%lld", input);
    printf("%lld", Constant);
}
typedef enum { LongConstant = ~0UL } LongEnum;
void testLong(LongEnum input) {
  printf("%u", input);
  printf("%u", LongConstant);
  printf("%lu", input);
  printf("%lu", LongConstant);
}
extern enum forward_declared *fwd;
void forward_enum() {
  printf("%u", fwd);
  printf("%p", fwd);
  scanf("%c", fwd);
  scanf("%u", fwd);
  scanf("%lu", fwd);
  scanf("%p", fwd);
}

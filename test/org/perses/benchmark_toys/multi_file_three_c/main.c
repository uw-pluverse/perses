int printf(const char *format, ...);
int compute_a(void);
int compute_b(void);

int main(void) {
  int unused_main = 333;
  int sum = compute_a() + compute_b();
  printf("sum = %d\n", sum);
  return 0;
}

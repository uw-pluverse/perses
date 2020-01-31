int printf(const char * restrict format, ...);
union X { char X; void *B; int a, b, c, d;};
union X foo() {
  union X Global;
  Global.B = (void*)123;
  return Global;
}
int main() {
  union X test = foo();
  printf("0x%p", test.B);
}

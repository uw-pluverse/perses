void foo(void) { }
void foo_weak(void) __attribute__((weak));
void foo_weak(void) { if (0){} if (0){} if (0){} if (0){} }
static void foo_internal(void);
int main(void) {
  foo();
  foo_internal();
  foo_weak();
  return 0;
}
static void foo_internal(void) { if (0){} if (0){} }

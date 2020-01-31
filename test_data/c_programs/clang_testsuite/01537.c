static void (*fp0)(void) __attribute__((noreturn));
void fatal();
static void __attribute__((noreturn)) f0(void) {
  fatal();
}
int f1() __attribute__((noreturn));
int g0 __attribute__((noreturn));
int f2() __attribute__((noreturn(1, 2)));
void f3() __attribute__((noreturn));
void f3() {
  return;
}
#pragma clang diagnostic error "-Winvalid-noreturn"
void f4() __attribute__((noreturn));
void f4() {
  return;
}
extern void f5 (unsigned long) __attribute__ ((__noreturn__));
void
f5 (unsigned long size)
{
}
__attribute__((noreturn)) void f(__attribute__((noreturn)) void (*x)(void)) {
  x();
}
typedef void (*Fun)(void) __attribute__ ((noreturn(2)));

int foo(int X, int Y);
double sqrt(double X);
void bar(volatile int *VP, int *P, int A,
         _Complex double C, volatile _Complex double VC) {
  VP < P;
  (void)A;
  (void)foo(1,2);
  A < foo(1, 2);
  foo(1,2)+foo(4,3);
  *P;
  *VP;
  P[4];
  VP[4];
  __real__ C;
  __real__ VC;
  sqrt(A);
}
extern void t1();
extern void t2();
void t3(int c) {
  c ? t1() : t2();
}
int stmt_expr(int x, int y) {
  return ({int _a = x, _b = y; _a > _b ? _a : _b; });
}
void nowarn(unsigned char* a, unsigned char* b)
{
  unsigned char c = 1;
  *a |= c, *b += c;
  int y, x;
  ((void)0), y = x;
}
void t4(int a) {
  int b = 0;
  if (a)
    b < 1;
  else
    b < 2;
  while (1)
    b < 3;
  do
    b < 4;
  while (1);
  for (;;)
    b < 5;
  for (b < 1;;) {}
  for (;b < 1;) {}
  for (;;b < 1) {}
}
int t5f(void) __attribute__((warn_unused_result));
void t5() {
  t5f();
}
int fn1() __attribute__ ((warn_unused_result));
int fn2() __attribute__ ((pure));
int fn3() __attribute__ ((__const));
int t6() {
  if (fn1() < 0 || fn2(2,1) < 0 || fn3(2) < 0)
    return -1;
  fn1();
  fn2(92, 21);
  fn3(42);
  __builtin_abs(0);
  (void)0, fn1();
  return 0;
}
int t7 __attribute__ ((warn_unused_result));
int (*fn4)(void) __attribute__ ((warn_unused_result));
void t8() {
  fn4();
}
void t9() __attribute__((warn_unused_result));
void *some_function(void);
void t10() {
  (void*) some_function();
}
void f(int i, ...) {
    __builtin_va_list ap;
    __builtin_va_start(ap, i);
    __builtin_va_arg(ap, int);
    __builtin_va_end(ap);
}
int fn5() __attribute__ ((__const));
void t11(int i, int j) {
  (long)foo((i), (j));
  ((long)foo(i, j));
  (long)0;;
  ((long)0);
  (t3(i), fn2());
  ((t3(i), fn2()));
  (foo((i), (j)) ? 0 : t3(i), 1);
  ((foo(i, j) ? 0 : t3(i), 1));
  (foo((i), (j)), 1);
  ((foo(i, j), 1));
  fn1();
  fn2();
}
void unused_parm(int a) {
  (a);
}

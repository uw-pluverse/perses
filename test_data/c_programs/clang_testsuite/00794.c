char *foo(float) __attribute__((__overloadable__));
void test_foo_1(float fv, double dv, float _Complex fc, double _Complex dc) {
  char *cp1 = foo(fv);
  char *cp2 = foo(dv);
  char *cp3 = foo(fc);
  char *cp4 = foo(dc);
}
int *foo(float _Complex) __attribute__((__overloadable__));
void test_foo_2(float fv, double dv, float _Complex fc, double _Complex dc) {
  char *cp1 = foo(fv);
  char *cp2 = foo(dv);
  int *ip = foo(fc);
  int *lp = foo(dc);
}
long *foo(double _Complex) __attribute__((__overloadable__));
void test_foo_3(float fv, double dv, float _Complex fc, double _Complex dc) {
  char *cp1 = foo(fv);
  char *cp2 = foo(dv);
  int *ip = foo(fc);
  long *lp = foo(dc);
}
char *promote_or_convert(double _Complex) __attribute__((__overloadable__));
int *promote_or_convert(long double _Complex) __attribute__((__overloadable__));
void test_promote_or_convert(float f, float _Complex fc) {
  char *cp = promote_or_convert(fc);
  int *ip2 = promote_or_convert(f);
}
char *promote_or_convert2(float) __attribute__((__overloadable__));
int *promote_or_convert2(double _Complex) __attribute__((__overloadable__));
void test_promote_or_convert2(float _Complex fc) {
  int *cp = promote_or_convert2(fc);
}
char *promote_or_convert3(int _Complex) __attribute__((__overloadable__));
int *promote_or_convert3(long _Complex) __attribute__((__overloadable__));
void test_promote_or_convert3(short _Complex sc) {
  char *cp = promote_or_convert3(sc);
}

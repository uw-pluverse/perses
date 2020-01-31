void foo() {
  *(0 ? (double *)0 : (void *)0) = 0;
  *(0 ? (double *)0 : (void *)(int *)0) = 0;
  *(0 ? (double *)0 : (void *)(double *)0) = 0;
  *(0 ? (double *)0 : (int *)(void *)0) = 0;
  *(0 ? (double *)0 : (double *)(void *)0) = 0;
  *((void *) 0) = 0;
  double *dp;
  int *ip;
  void *vp;
  dp = vp;
  vp = dp;
  ip = dp;
  dp = ip;
  dp = 0 ? (double *)0 : (void *)0;
  vp = 0 ? (double *)0 : (void *)0;
  ip = 0 ? (double *)0 : (void *)0;
  const int *cip;
  vp = (0 ? vp : cip);
  vp = (0 ? cip : vp);
  int i = 2;
  int (*pf)[2];
  int (*pv)[i];
  pf = (i ? pf : pv);
  enum {xxx,yyy,zzz} e, *ee;
  short x;
  ee = ee ? &x : ee ? &i : &e;
  typedef void *asdf;
  *(0 ? (asdf) 0 : &x) = 10;
  unsigned long test0 = 5;
  test0 = test0 ? (long) test0 : test0;
  test0 = test0 ? (int) test0 : test0;
  test0 = test0 ? (short) test0 : test0;
  test0 = test0 ? test0 : (long) test0;
  test0 = test0 ? test0 : (int) test0;
  test0 = test0 ? test0 : (short) test0;
  test0 = test0 ? test0 : (long) 10;
  test0 = test0 ? test0 : (int) 10;
  test0 = test0 ? test0 : (short) 10;
  test0 = test0 ? (long) 10 : test0;
  test0 = test0 ? (int) 10 : test0;
  test0 = test0 ? (short) 10 : test0;
  int test1;
  enum Enum { EVal };
  test0 = test0 ? EVal : test0;
  test1 = test0 ? EVal : (int) test0;
  test0 = test0 ?
                  (unsigned) EVal
                : (int) test0;
  test0 = test0 ? EVal : test1;
  test0 = test0 ? test1 : EVal;
  const int *const_int;
  int *nonconst_int;
  *(test0 ? const_int : nonconst_int) = 42;
  *(test0 ? nonconst_int : const_int) = 42;
  int (*incomplete)[];
  int (*complete)[12];
  sizeof(*(test0 ? incomplete : complete));
  sizeof(*(test0 ? complete : incomplete));
  int __attribute__((address_space(2))) *adr2;
  int __attribute__((address_space(3))) *adr3;
  test0 ? adr2 : adr3;
  (test0 ? (test0 ? adr2 : adr2) : nonconst_int);
}
int Postgresql() {
  char x;
  return ((((&x) != ((void *) 0)) ? (*(&x) = ((char) 1)) : (void) ((void *) 0)), (unsigned long) ((void *) 0));
}
extern int f1(void);
int f0(int a) {
  return a ? f1() : ((void*) 0);
}
int f2(int x) {
  return (x != 0) ? 0U : x;
}
void PR9236() {
  struct A {int i;} A1;
  (void)(1 ? A1 : (void*)0);
  (void)(1 ? (void*)0 : A1);
  (void)(1 ? 0 : A1);
  (void)(1 ? (void*)0 : A1);
  (void)(1 ? A1: (void*)0);
  (void)(1 ? A1 : ((void*)0));
}

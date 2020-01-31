int nonconst(void);
int isconst(void) __attribute__((const));
int ispure(void) __attribute__((pure));
int test1(int *a, int i) {
  __builtin_assume(a != 0);
  __builtin_assume(isconst());
  __builtin_assume(ispure());
  __builtin_assume(++i != 0);
  __builtin_assume(nonconst());
  return a[0];
}

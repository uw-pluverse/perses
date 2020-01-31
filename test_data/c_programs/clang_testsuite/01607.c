int nonconst(void);
int isconst(void) __attribute__((const));
int ispure(int) __attribute__((pure));
int foo(int *a, int i) {
  __builtin_assume(i != 4);
  __builtin_assume(++i > 2);
  __builtin_assume(nonconst() > 2);
  __builtin_assume(isconst() > 2);
  __builtin_assume(ispure(i) > 2);
  __builtin_assume(ispure(++i) > 2);
  int test = sizeof(struct{char qq[(__builtin_assume(i != 5), 7)];});
  return a[i];
}

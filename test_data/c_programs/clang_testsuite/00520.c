void foo();
#pragma omp single
#pragma omp single foo
void test_no_clause() {
  int i;
#pragma omp single
  foo();
#pragma omp single
  ++i;
}
void test_branch_protected_scope() {
  int i = 0;
L1:
  ++i;
  int x[24];
#pragma omp parallel
#pragma omp single
  {
    if (i == 5)
      goto L1;
    else if (i == 6)
      return;
    else if (i == 7)
      goto L2;
    else if (i == 8) {
    L2:
      x[i]++;
    }
  }
  if (x[0] == 0)
    goto L2;
  else if (x[1] == 1)
    goto L1;
}
void test_invalid_clause() {
  int i;
#pragma omp parallel
#pragma omp single foo bar
  foo();
}
void test_non_identifiers() {
  int i, x;
#pragma omp parallel
#pragma omp single;
  foo();
#pragma omp parallel
#pragma omp single linear(x);
  foo();
#pragma omp parallel
#pragma omp single private(x);
  foo();
#pragma omp parallel
#pragma omp single, private(x);
  foo();
}
void test_private() {
  int i;
#pragma omp parallel
#pragma omp single private(
  foo();
#pragma omp parallel
#pragma omp single private(,
  foo();
#pragma omp parallel
#pragma omp single private(, )
  foo();
#pragma omp parallel
#pragma omp single private()
  foo();
#pragma omp parallel
#pragma omp single private(int)
  foo();
#pragma omp parallel
#pragma omp single private(0)
  foo();
  int x, y, z;
#pragma omp parallel
#pragma omp single private(x)
  foo();
#pragma omp parallel
#pragma omp single private(x, y)
  foo();
#pragma omp parallel
#pragma omp single private(x, y, z)
  foo();
}
void test_firstprivate() {
  int i;
#pragma omp parallel
#pragma omp single firstprivate(
  foo();
#pragma omp parallel
#pragma omp single firstprivate(,
  foo();
#pragma omp parallel
#pragma omp single firstprivate(, )
  foo();
#pragma omp parallel
#pragma omp single firstprivate()
  foo();
#pragma omp parallel
#pragma omp single firstprivate(int)
  foo();
#pragma omp parallel
#pragma omp single firstprivate(0)
  foo();
}
void test_nowait() {
#pragma omp single nowait nowait
  for (int i = 0; i < 16; ++i)
    ;
}

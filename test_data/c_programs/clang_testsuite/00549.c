#pragma omp target teams distribute parallel for simd
#pragma omp target teams distribute parallel for simd foo
void test_no_clause() {
  int i;
#pragma omp target teams distribute parallel for simd
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd
  ++i;
}
void test_branch_protected_scope() {
  int i = 0;
L1:
  ++i;
  int x[24];
#pragma omp target teams distribute parallel for simd
  for (i = 0; i < 16; ++i) {
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
#pragma omp target teams distribute parallel for simd foo bar
  for (i = 0; i < 16; ++i)
    ;
}
void test_non_identifiers() {
  int i, x;
#pragma omp target teams distribute parallel for simd;
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd private(x);
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd, private(x);
  for (i = 0; i < 16; ++i)
    ;
}
extern int foo();
void test_collapse() {
  int i;
#pragma omp target teams distribute parallel for simd collapse
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse()
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse 4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(4
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(4,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(4, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(4 4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(4, , 4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(4)
  for (int i1 = 0; i1 < 16; ++i1)
    for (int i2 = 0; i2 < 16; ++i2)
      for (int i3 = 0; i3 < 16; ++i3)
        for (int i4 = 0; i4 < 16; ++i4)
          foo();
#pragma omp target teams distribute parallel for simd collapse(4, 8)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(2.5)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(foo())
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(-5)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(0)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(5 - 5)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd collapse(2) firstprivate(i)
  for (i = 0; i < 16; ++i)
    for (int j = 0; j < 16; ++j)
#pragma omp parallel for reduction(+ : i, j)
      for (int k = 0; k < 16; ++k)
        i += j;
}
void test_private() {
  int i;
#pragma omp target teams distribute parallel for simd private(
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd private(,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd private(, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd private()
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd private(int)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd private(0)
  for (i = 0; i < 16; ++i)
    ;
  int x, y, z;
#pragma omp target teams distribute parallel for simd private(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd private(x, y)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd private(x, y, z)
  for (i = 0; i < 16; ++i) {
    x = y * i + z;
  }
}
void test_lastprivate() {
  int i;
#pragma omp target teams distribute parallel for simd lastprivate(
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd lastprivate(,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd lastprivate(, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd lastprivate()
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd lastprivate(int)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd lastprivate(0)
  for (i = 0; i < 16; ++i)
    ;
  int x, y, z;
#pragma omp target teams distribute parallel for simd lastprivate(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd lastprivate(x, y)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd lastprivate(x, y, z)
  for (i = 0; i < 16; ++i)
    ;
}
void test_firstprivate() {
  int i;
#pragma omp target teams distribute parallel for simd firstprivate(
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd firstprivate(,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd firstprivate(, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd firstprivate()
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd firstprivate(int)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd firstprivate(0)
  for (i = 0; i < 16; ++i)
    ;
  int x, y, z;
#pragma omp target teams distribute parallel for simd lastprivate(x) firstprivate(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd lastprivate(x, y) firstprivate(x, y)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target teams distribute parallel for simd lastprivate(x, y, z) firstprivate(x, y, z)
  for (i = 0; i < 16; ++i)
    ;
}
void test_loop_messages() {
  float a[100], b[100], c[100];
#pragma omp target teams distribute parallel for simd
  for (float fi = 0; fi < 10.0; fi++) {
    c[(int)fi] = a[(int)fi] + b[(int)fi];
  }
#pragma omp target teams distribute parallel for simd
  for (double fi = 0; fi < 10.0; fi++) {
    c[(int)fi] = a[(int)fi] + b[(int)fi];
  }
}

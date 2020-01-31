#pragma omp distribute simd
#pragma omp distribute simd foo
#pragma omp distribute simd safelen(4)
void test_no_clause() {
  int i;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd
  ++i;
}
void test_branch_protected_scope() {
  int i = 0;
L1:
  ++i;
  int x[24];
#pragma omp target
#pragma omp teams
#pragma omp distribute simd
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
#pragma omp target
#pragma omp teams
#pragma omp distribute simd foo bar
  for (i = 0; i < 16; ++i)
    ;
}
void test_non_identifiers() {
  int i, x;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd;
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd private(x);
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd, private(x);
  for (i = 0; i < 16; ++i)
    ;
}
extern int foo();
void test_safelen() {
  int i;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen()
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen 4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(4
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(4,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(4, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(4 4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(4, , 4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(4, 8)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(2.5)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(foo())
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(-5)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(0)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(5 - 5)
  for (i = 0; i < 16; ++i)
    ;
}
void test_simdlen() {
  int i;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen()
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen 4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(4
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(4,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(4, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(4 4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(4, , 4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(4, 8)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(2.5)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(foo())
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(-5)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(0)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(5 - 5)
  for (i = 0; i < 16; ++i)
    ;
}
void test_safelen_simdlen() {
  int i;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd simdlen(6) safelen(5)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd safelen(5) simdlen(6)
  for (i = 0; i < 16; ++i)
    ;
}
void test_collapse() {
  int i;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse()
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse 4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(4
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(4,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(4, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(4 4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(4, , 4)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(4)
  for (int i1 = 0; i1 < 16; ++i1)
    for (int i2 = 0; i2 < 16; ++i2)
      for (int i3 = 0; i3 < 16; ++i3)
        for (int i4 = 0; i4 < 16; ++i4)
          foo();
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(4, 8)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(2.5)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(foo())
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(-5)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(0)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(5 - 5)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd collapse(2) reduction(+ : i)
  for (i = 0; i < 16; ++i)
    for (int j = 0; j < 16; ++j)
#pragma omp for reduction(+ : i, j)
      for (int k = 0; k < 16; ++k)
        i += j;
#pragma omp target
#pragma omp teams
  for (i = 0; i < 16; ++i)
    for (int j = 0; j < 16; ++j)
#pragma omp distribute simd reduction(+ : i, j)
      for (int k = 0; k < 16; ++k)
        i += j;
}
void test_linear() {
  int i;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear()
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(int)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(0)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x, y)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x, y, z)
  for (i = 0; i < 16; ++i)
    ;
  int x, y;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x :)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x :, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x : 1)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x : 2 * 2)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x : 1, y)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x : 1, y, z : 1)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x) linear(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd private(x) linear(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x) private(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x, y : 0)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(x) lastprivate(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd lastprivate(x) linear(x)
  for (i = 0; i < 16; ++i)
    ;
}
void test_aligned() {
  int i;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned()
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(int)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(0)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x, y)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x, y, z)
  for (i = 0; i < 16; ++i)
    ;
  int *x, y, z[25];
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(z)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x :)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x :, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x : 1)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x : 2 * 2)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x : 1, y)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x : 1, y, z : 1)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x, y)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x, y, z)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x) aligned(z, x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd aligned(x, y, z) aligned(y, z)
  for (i = 0; i < 16; ++i)
    ;
}
void test_private() {
  int i;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd private(
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd private(,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd private(, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd private()
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd private(int)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd private(0)
  for (i = 0; i < 16; ++i)
    ;
  int x, y, z;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd private(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd private(x, y)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd private(x, y, z)
  for (i = 0; i < 16; ++i) {
    x = y * i + z;
  }
}
void test_firstprivate() {
  int i;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd firstprivate(
  for (i = 0; i < 16; ++i)
    ;
}
void test_lastprivate() {
  int i;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd lastprivate(
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd lastprivate(,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd lastprivate(, )
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd lastprivate()
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd lastprivate(int)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd lastprivate(0)
  for (i = 0; i < 16; ++i)
    ;
  int x, y, z;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd lastprivate(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd lastprivate(x, y)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd lastprivate(x, y, z)
  for (i = 0; i < 16; ++i)
    ;
}
void test_reduction() {
  int i, x, y;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction()
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction( : x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(,
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(+
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(+:
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(+ :)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(+ :, y)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(+ : x, + : y)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(% : x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(+ : x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(* : x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(- : x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(& : x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(| : x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(^ : x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(&& : x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(|| : x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(max : x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(min : x)
  for (i = 0; i < 16; ++i)
    ;
  struct X {
    int x;
  };
  struct X X;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(+ : X.x)
  for (i = 0; i < 16; ++i)
    ;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd reduction(+ : x + x)
  for (i = 0; i < 16; ++i)
    ;
}
void test_loop_messages() {
  float a[100], b[100], c[100];
#pragma omp target
#pragma omp teams
#pragma omp distribute simd
  for (float fi = 0; fi < 10.0; fi++) {
    c[(int)fi] = a[(int)fi] + b[(int)fi];
  }
#pragma omp target
#pragma omp teams
#pragma omp distribute simd
  for (double fi = 0; fi < 10.0; fi++) {
    c[(int)fi] = a[(int)fi] + b[(int)fi];
  }
}
void linear_modifiers(int argc) {
  int f;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(f)
  for (int k = 0; k < argc; ++k) ++k;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(val(f))
  for (int k = 0; k < argc; ++k) ++k;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(uval(f))
  for (int k = 0; k < argc; ++k) ++k;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(ref(f))
  for (int k = 0; k < argc; ++k) ++k;
#pragma omp target
#pragma omp teams
#pragma omp distribute simd linear(foo(f))
  for (int k = 0; k < argc; ++k) ++k;
}

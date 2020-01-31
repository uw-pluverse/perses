void foo();
#pragma omp sections
#pragma omp sections foo
void test_no_clause() {
  int i;
#pragma omp sections
  {
    foo();
  }
#pragma omp sections
  ++i;
#pragma omp sections
  {
    foo();
    foo();
  }
}
void test_branch_protected_scope() {
  int i = 0;
L1:
  ++i;
  int x[24];
#pragma omp parallel
#pragma omp sections
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
#pragma omp section
    if (i == 5)
      goto L1;
    else if (i == 6)
      return;
    else if (i == 7)
      goto L3;
    else if (i == 8) {
    L3:
      x[i]++;
    }
  }
  if (x[0] == 0)
    goto L2;
  else if (x[1] == 1)
    goto L1;
  goto L3;
}
void test_invalid_clause() {
  int i;
#pragma omp parallel
#pragma omp sections foo bar
  {
    foo();
#pragma omp section nowait
    ;
  }
}
void test_non_identifiers() {
  int i, x;
#pragma omp parallel
#pragma omp sections;
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections linear(x);
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections private(x);
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections, private(x);
  {
    foo();
  }
}
void test_private() {
  int i;
#pragma omp parallel
#pragma omp sections private(
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections private(,
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections private(, )
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections private()
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections private(int)
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections private(0)
  {
    foo();
  }
  int x, y, z;
#pragma omp parallel
#pragma omp sections private(x)
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections private(x, y)
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections private(x, y, z)
  {
    foo();
  }
}
void test_lastprivate() {
  int i;
#pragma omp parallel
#pragma omp sections lastprivate(
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections lastprivate(,
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections lastprivate(, )
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections lastprivate()
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections lastprivate(int)
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections lastprivate(0)
  {
    foo();
  }
  int x, y, z;
#pragma omp parallel
#pragma omp sections lastprivate(x)
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections lastprivate(x, y)
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections lastprivate(x, y, z)
  {
    foo();
  }
}
void test_firstprivate() {
  int i;
#pragma omp parallel
#pragma omp sections firstprivate(
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections firstprivate(,
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections firstprivate(, )
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections firstprivate()
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections firstprivate(int)
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections firstprivate(0)
  {
    foo();
  }
  int x, y, z;
#pragma omp parallel
#pragma omp sections lastprivate(x) firstprivate(x)
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections lastprivate(x, y) firstprivate(x, y)
  {
    foo();
  }
#pragma omp parallel
#pragma omp sections lastprivate(x, y, z) firstprivate(x, y, z)
  {
    foo();
  }
}
void test_nowait() {
#pragma omp parallel
#pragma omp sections nowait nowait
  {
    ;
  }
}

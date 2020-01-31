void foo() { }
int main(int argc, char **argv) {
  int a;
#pragma omp target data
  {}
  L1:
    foo();
#pragma omp target data map(a)
  {
    foo();
    goto L1;
  }
  goto L2;
#pragma omp target data map(a)
  L2:
  foo();
#pragma omp target data map(a)(i)
  {
    foo();
  }
#pragma omp target unknown
  {
    foo();
  }
  return 0;
}

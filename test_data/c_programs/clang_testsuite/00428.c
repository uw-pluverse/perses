int a;
void foo() {
  int(*b)[a];
  int *(**c)[a];
#pragma omp parallel if (0)
  b[0][0] = c[0][a][0][a];
}

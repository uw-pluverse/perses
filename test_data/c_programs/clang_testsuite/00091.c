double foo(int N) {
  double v = 0.0;
  for (int i = 0; i < N; i++)
    v = v + 1.0;
  return v;
}
void foo2(int *dw, int *uw, int *A, int *B, int *C, int *D, int N) {
  for (int i = 0; i < N; i++) {
    dw[i] = A[i] + B[i - 1] + C[i - 2] + D[i - 3];
    uw[i] = A[i] + B[i + 1] + C[i + 2] + D[i + 3];
  }
}

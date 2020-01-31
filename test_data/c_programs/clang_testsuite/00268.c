extern int bar(char *A, int n);
int foo(int n) {
  if (n) {
    char A[10];
    return bar(A, 1);
  } else {
    char A[20];
    return bar(A, 2);
  }
}

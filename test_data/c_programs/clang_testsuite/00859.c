struct incomplete;
int sub1(int *a, double *b) {
  return a - b;
}
void *sub2(struct incomplete *P) {
  return P-4;
}
void *sub3(void *P) {
  return P-4;
}
int sub4(void *P, void *Q) {
  return P-Q;
}
int sub5(void *P, int *Q) {
  return P-Q;
}
int logicaland1(int a) {
  return a && (void)a;
}

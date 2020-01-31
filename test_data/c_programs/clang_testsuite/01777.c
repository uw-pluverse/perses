void use(int *ptr, int val) {
  *ptr = val;
}
int compute() {
  return 2 + 3 + 4 + 5 + 6;
}
void testSimple() {
  int *p = 0;
  use(p, compute());
}
void use2(int *ptr, int val) {
  *ptr = val;
}
void passThrough(int *p) {
  use2(p, compute());
}
void testChainedCalls() {
  int *ptr = 0;
  passThrough(ptr);
}

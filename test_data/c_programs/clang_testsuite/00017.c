void callee() {
  ;
}
int test_calling_unimportant_callee(int argc, char *argv[]) {
  int x;
  callee();
  return x;
}

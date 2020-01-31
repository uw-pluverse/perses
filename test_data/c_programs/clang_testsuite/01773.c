void test_01(int * data);
void test_01(int *data) {
  data = 0;
  *data = 1;
}
int test_02() {
  int res = 1/0;
  return res;
}
int test_03() {
  int res = 1/0;
  return res;
}

void clang_analyzer_eval(int);
void test1(int x) {
  int buf[100];
  buf[100] = 1;
}
void test1_ok(int x) {
  int buf[100];
  buf[99] = 1;
}
const char test1_strings_underrun(int x) {
  const char *mystr = "mary had a little lamb";
  return mystr[-1];
}
const char test1_strings_overrun(int x) {
  const char *mystr = "mary had a little lamb";
  return mystr[1000];
}
const char test1_strings_ok(int x) {
  const char *mystr = "mary had a little lamb";
  return mystr[5];
}
void test1_ptr(int x) {
  int buf[100];
  int *p = buf;
  p[101] = 1;
}
void test1_ptr_ok(int x) {
  int buf[100];
  int *p = buf;
  p[99] = 1;
}
void test1_ptr_arith(int x) {
  int buf[100];
  int *p = buf;
  p = p + 100;
  p[0] = 1;
}
void test1_ptr_arith_ok(int x) {
  int buf[100];
  int *p = buf;
  p = p + 99;
  p[0] = 1;
}
void test1_ptr_arith_bad(int x) {
  int buf[100];
  int *p = buf;
  p = p + 99;
  p[1] = 1;
}
void test1_ptr_arith_ok2(int x) {
  int buf[100];
  int *p = buf;
  p = p + 99;
  p[-1] = 1;
}
void test2(int x) {
  int buf[100];
  buf[-1] = 1;
}
void test2_ptr(int x) {
  int buf[100];
  int *p = buf;
  p[-1] = 1;
}
void test2_ptr_arith(int x) {
  int buf[100];
  int *p = buf;
  --p;
  p[0] = 1;
}
void test2_multi(int x) {
  int buf[100][100];
  buf[0][-1] = 1;
}
void test2_multi_b(int x) {
  int buf[100][100];
  buf[-1][0] = 1;
}
void test2_multi_ok(int x) {
  int buf[100][100];
  buf[0][0] = 1;
}
void test3(int x) {
  int buf[100];
  if (x < 0)
    buf[x] = 1;
}
void test4(int x) {
  int buf[100];
  if (x > 99)
    buf[x] = 1;
}
void test_assume_after_access(unsigned long x) {
  int buf[100];
  buf[x] = 1;
  clang_analyzer_eval(x <= 99);
}
int *get_symbolic();
void test_index_below_symboloc() {
  int *buf = get_symbolic();
  buf[-1] = 0;
}
void test_incomplete_struct() {
  extern struct incomplete incomplete;
  int *p = (int *)&incomplete;
  p[1] = 42;
}
void test_extern_void() {
  extern void v;
  int *p = (int *)&v;
  p[1] = 42;
}
void test_assume_after_access2(unsigned long x) {
  char buf[100];
  buf[x] = 1;
  clang_analyzer_eval(x <= 99);
}

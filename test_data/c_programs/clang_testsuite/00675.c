static int test2_i = 99;
int test2_f() {
  extern int test2_i;
  return test2_i;
}
static void f(int x);
void g0() {
  f(5);
}
extern void f(int x) { }

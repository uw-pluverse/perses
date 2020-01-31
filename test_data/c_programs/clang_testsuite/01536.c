void f1(void) {
  int x, y, z;
#pragma unused(x)
#pragma unused(y, z)
  int w;
#pragma unused w
}
void f2(void) {
  int x, y;
#pragma unused(x,)
#pragma unused()
}
void f3(void) {
#pragma unused(x)
}
void f4(void) {
  int w;
#pragma unused((w))
}
void f6(void) {
  int z;
  {
#pragma unused(z)
  }
}
void f7() {
  int y;
#pragma unused(undeclared, undefined, y)
}
int f8(int x) {
  return 0;
}
int f9(int x) {
  return x;
}
int f10(int x) {
#pragma unused(x)
  return 0;
}
int f11(int x) {
#pragma unused(x)
  return x;
}
int f12(int x) {
  int y = x;
#pragma unused(x)
  return y;
}
static int glob_var = 0;
#pragma unused(glob_var)

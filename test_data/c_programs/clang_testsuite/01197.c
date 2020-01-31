int f(int) __attribute__((unavailable));
int test(int i, int j, int k, int l) {
  return i | j | k & l;
}
struct X __attribute__((deprecated)) f1 = { 17 };
void f2() { f1(17); }
const char *str = "Hello, \nWorld";
void f3(const char*, ...) __attribute__((sentinel(0)));
void f4(const char* str) {
  f3(str, __null);
}
typedef int type;
void f5(float f) {
  (type)f;
}

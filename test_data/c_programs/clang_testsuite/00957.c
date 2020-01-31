int global = 42;
typedef const char* constCharPtrArray[10];
struct S {
  char a;
  double b;
  constCharPtrArray c;
};
enum E { ZERO = 0, ONE = 1 };
int sum(int p, int q) {
  int r = p + q;
  struct S s;
  enum E e;
  return r;
}

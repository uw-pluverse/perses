





__attribute__((always_inline))
inline void foo(int *x) {
  *x = 0;
}

int main() {
  int x;
  foo(&x);
  return x;
}

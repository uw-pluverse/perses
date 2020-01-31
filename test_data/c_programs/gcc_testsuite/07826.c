

void f() {
  int n = 3;
  typedef int T[n++];

  T t;
  t[0] = 7;
}

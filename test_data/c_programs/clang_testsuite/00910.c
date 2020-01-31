struct s {
  double d1;
  int s1;
};
struct s foo(void) {
  struct s S = {1.1, 2};
  return S;
}

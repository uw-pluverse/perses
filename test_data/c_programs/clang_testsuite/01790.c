struct Q { int a, b, c; };
union UQ { struct Q q; };
union UQ getUQ() {
  union UQ u = { { 1, 2, 3 } };
  return u;
}
void test() {
  struct LUQ { union UQ uq; } var = { getUQ(), .uq.q.a = 100 };
  struct Q s[] = {
    [0] = (struct Q){1, 2},
    [0].c = 3
  };
}

typedef signed i;
typedef unsigned u;
void p(u c, int f) { printf("%X", c); }
i f(i s, i i) { return s % i; }
u c;
void r(b) { c = c ^ b; }
void c2(v) { r(v); }
void t(u v, char *n, int f) { c2(v); }
u g;
i _;
static u _3 = 2;
i _4[7][5][7] = {{8}, {8}, {{8}, 0x9}};
i _9;
i _1() {
  i _5[2];
  int i;
  for (i = 0; i < 2; i++)
    _5[i] = 8;
  for (_3 = 1;;) {
    for (; i < 5; i++)
      ;
    for (_9 = 6; _9 >= 0; _9 -= 1)
      _ = _5[0] ^= _4[_3 + 1][_3][_9] = f(g--, 4294967295);
    return _;
  }
}
int main() {
  int i, j, k;
  int r = 0;
  _1();
  for (i = 0; i < 7; i++)
    for (j = 0; j < 5; j++)
      for (k = 0; k < 7; k++)
        t(_4[i][j][k], "", r);
  p(c, r);
  return 0;
}

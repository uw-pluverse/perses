int test2() { return; }
void test3() { return 4; }
void test4() {
bar:
baz:
blong:
bing:
 ;
static long x = &&bar - &&baz;
static long y = &&baz;
  &&bing;
  &&blong;
  if (y)
    goto *y;
  goto *x;
}
int test5(long long b) {
  static void *lbls[] = { &&lbl };
  goto *b;
 lbl:
  return 0;
}

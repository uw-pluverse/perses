void test1(int volatile *p, int v) {
  __iso_volatile_store32(p, v);
}
int test2(const int volatile *p) {
  return __iso_volatile_load32(p);
}

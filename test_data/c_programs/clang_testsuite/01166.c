int abs(int);
int fabsf(int);
void test_int(int i, unsigned u, long long ll, float f, double d) {
  (void)abs(i);
  (void)abs(u);
  int llabs;
  (void)llabs;
  (void)abs(ll);
  (void)abs(f);
  (void)abs(d);
}

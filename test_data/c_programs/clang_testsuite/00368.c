volatile _Complex float cf;
volatile _Complex double cd;
volatile _Complex float cf32 __attribute__((aligned(32)));
volatile _Complex double cd32 __attribute__((aligned(32)));
void test_cf() {
  (void)(cf);
  (void)(cf=cf);
}
void test_cd() {
  (void)(cd);
  (void)(cd=cd);
}
void test_cf32() {
  (void)(cf32);
  (void)(cf32=cf32);
}
void test_cd32() {
  (void)(cd32);
  (void)(cd32=cd32);
}

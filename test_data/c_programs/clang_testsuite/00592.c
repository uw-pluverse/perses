void testFloat(_Atomic(float) *fp) {
  __c11_atomic_init(fp, 1.0f);
  _Atomic(float) x = 2.0f;
  float f = *fp;
  *fp = f;
}
void testComplexFloat(_Atomic(_Complex float) *fp) {
  __c11_atomic_init(fp, 1.0f);
  _Atomic(_Complex float) x = 2.0f;
  _Complex float f = *fp;
  *fp = f;
}
typedef struct { short x, y, z, w; } S;
void testStruct(_Atomic(S) *fp) {
  __c11_atomic_init(fp, (S){1,2,3,4});
  _Atomic(S) x = (S){1,2,3,4};
  S f = *fp;
  *fp = f;
}
typedef struct { short x, y, z; } PS;
void testPromotedStruct(_Atomic(PS) *fp) {
  __c11_atomic_init(fp, (PS){1,2,3});
  _Atomic(PS) x = (PS){1,2,3};
  PS f = *fp;
  *fp = f;
}
PS test_promoted_load(_Atomic(PS) *addr) {
  return __c11_atomic_load(addr, 5);
}
void test_promoted_store(_Atomic(PS) *addr, PS *val) {
  __c11_atomic_store(addr, *val, 5);
}
PS test_promoted_exchange(_Atomic(PS) *addr, PS *val) {
  return __c11_atomic_exchange(addr, *val, 5);
}
_Bool test_promoted_cmpxchg(_Atomic(PS) *addr, PS *desired, PS *new) {
  return __c11_atomic_compare_exchange_strong(addr, desired, *new, 5, 5);
}

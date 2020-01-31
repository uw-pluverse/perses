void foo() {
  union { int i; } u;
  u.i=1;
}
int bar(int *a) {
  return *a;
}
int addr_space(int __attribute__((address_space(256))) *a) {
  return *a;
}
int lsh_overflow(int a, int b) {
  return a << b;
}
int rsh_inbounds(int a, int b) {
  return a >> b;
}
int load(int *p) {
  return *p;
}
void store(int *p, int q) {
  *p = q;
}
struct S { int k; };
int *member_access(struct S *p) {
  return &p->k;
}
int signed_overflow(int a, int b) {
  return a + b;
}
int no_return() {
}
void vla_bound(int n) {
  int arr[n * 3];
}
float int_float_no_overflow(__int128 n) {
  return n;
}
float int_float_overflow(unsigned __int128 n) {
  return n;
}
void int_fp16_overflow(int n, __fp16 *p) {
  *p = n;
}
int float_int_overflow(float f) {
  return f;
}
int long_double_int_overflow(long double ld) {
  return ld;
}
unsigned float_uint_overflow(float f) {
  return f;
}
signed char fp16_char_overflow(__fp16 *p) {
  return *p;
}
float float_float_overflow(double f) {
  return f;
}
int int_divide_overflow(int a, int b) {
  return a / b;
}
_Bool sour_bool(_Bool *p) {
  return *p;
}
__attribute__((returns_nonnull))
int *ret_nonnull(int *a) {
  return a;
}
__attribute__((nonnull)) void decl_nonnull(int *a);
void call_decl_nonnull(int *a) {
  decl_nonnull(a);
}
extern void *memcpy (void *, const void *, unsigned) __attribute__((nonnull(1, 2)));
void call_memcpy_nonnull(void *p, void *q, int sz) {
  memcpy(p, q, sz);
}
extern void *memmove (void *, const void *, unsigned) __attribute__((nonnull(1, 2)));
void call_memmove_nonnull(void *p, void *q, int sz) {
  memmove(p, q, sz);
}
__attribute__((nonnull)) void nonnull_variadic(int a, ...);
void call_nonnull_variadic(int a, int *b) {
  nonnull_variadic(a, b);
}

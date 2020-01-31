typedef enum memory_order {
  memory_order_relaxed, memory_order_consume, memory_order_acquire,
  memory_order_release, memory_order_acq_rel, memory_order_seq_cst
} memory_order;
int fi1(_Atomic(int) *i) {
  return __c11_atomic_load(i, memory_order_seq_cst);
}
int fi1a(int *i) {
  int v;
  __atomic_load(i, &v, memory_order_seq_cst);
  return v;
}
int fi1b(int *i) {
  return __atomic_load_n(i, memory_order_seq_cst);
}
void fi2(_Atomic(int) *i) {
  __c11_atomic_store(i, 1, memory_order_seq_cst);
}
void fi2a(int *i) {
  int v = 1;
  __atomic_store(i, &v, memory_order_seq_cst);
}
void fi2b(int *i) {
  __atomic_store_n(i, 1, memory_order_seq_cst);
}
int fi3(_Atomic(int) *i) {
  return __c11_atomic_fetch_and(i, 1, memory_order_seq_cst);
}
int fi3a(int *i) {
  return __atomic_fetch_xor(i, 1, memory_order_seq_cst);
}
int fi3b(int *i) {
  return __atomic_add_fetch(i, 1, memory_order_seq_cst);
}
int fi3c(int *i) {
  return __atomic_fetch_nand(i, 1, memory_order_seq_cst);
}
int fi3d(int *i) {
  return __atomic_nand_fetch(i, 1, memory_order_seq_cst);
}
_Bool fi4(_Atomic(int) *i) {
  int cmp = 0;
  return __c11_atomic_compare_exchange_strong(i, &cmp, 1, memory_order_acquire, memory_order_acquire);
}
_Bool fi4a(int *i) {
  int cmp = 0;
  int desired = 1;
  return __atomic_compare_exchange(i, &cmp, &desired, 0, memory_order_acquire, memory_order_acquire);
}
_Bool fi4b(int *i) {
  int cmp = 0;
  return __atomic_compare_exchange_n(i, &cmp, 1, 1, memory_order_acquire, memory_order_acquire);
}
float ff1(_Atomic(float) *d) {
  return __c11_atomic_load(d, memory_order_relaxed);
}
void ff2(_Atomic(float) *d) {
  __c11_atomic_store(d, 1, memory_order_release);
}
float ff3(_Atomic(float) *d) {
  return __c11_atomic_exchange(d, 2, memory_order_seq_cst);
}
int* fp1(_Atomic(int*) *p) {
  return __c11_atomic_load(p, memory_order_seq_cst);
}
int* fp2(_Atomic(int*) *p) {
  return __c11_atomic_fetch_add(p, 1, memory_order_relaxed);
}
int *fp2a(int **p) {
  return __atomic_fetch_sub(p, 4, memory_order_relaxed);
}
_Complex float fc(_Atomic(_Complex float) *c) {
  return __c11_atomic_exchange(c, 2, memory_order_seq_cst);
}
typedef struct X { int x; } X;
X fs(_Atomic(X) *c) {
  return __c11_atomic_exchange(c, (X){2}, memory_order_seq_cst);
}
X fsa(X *c, X *d) {
  X ret;
  __atomic_exchange(c, d, &ret, memory_order_seq_cst);
  return ret;
}
_Bool fsb(_Bool *c) {
  return __atomic_exchange_n(c, 1, memory_order_seq_cst);
}
char flag1;
volatile char flag2;
void test_and_set() {
  __atomic_test_and_set(&flag1, memory_order_seq_cst);
  __atomic_test_and_set(&flag2, memory_order_acquire);
  __atomic_clear(&flag2, memory_order_release);
  __atomic_clear(&flag1, memory_order_seq_cst);
}
struct Sixteen {
  char c[16];
} sixteen;
struct Seventeen {
  char c[17];
} seventeen;
int lock_free(struct Incomplete *incomplete) {
  __c11_atomic_is_lock_free(3);
  __atomic_is_lock_free(16, &sixteen);
  __atomic_is_lock_free(17, &seventeen);
  __atomic_is_lock_free(4, incomplete);
  char cs[20];
  __atomic_is_lock_free(4, cs+1);
  __atomic_always_lock_free(3, 0);
  __atomic_always_lock_free(16, 0);
  __atomic_always_lock_free(17, 0);
  __atomic_always_lock_free(16, &sixteen);
  __atomic_always_lock_free(17, &seventeen);
  int n;
  __atomic_is_lock_free(4, &n);
  return __c11_atomic_is_lock_free(sizeof(_Atomic(int)));
}
struct foo {
  int big[128];
};
struct bar {
  char c[3];
};
struct bar smallThing, thing1, thing2;
struct foo bigThing;
_Atomic(struct foo) bigAtomic;
void structAtomicStore() {
  struct foo f = {0};
  __c11_atomic_store(&bigAtomic, f, 5);
  struct bar b = {0};
  __atomic_store(&smallThing, &b, 5);
  __atomic_store(&bigThing, &f, 5);
}
void structAtomicLoad() {
  struct foo f = __c11_atomic_load(&bigAtomic, 5);
  struct bar b;
  __atomic_load(&smallThing, &b, 5);
  __atomic_load(&bigThing, &f, 5);
}
struct foo structAtomicExchange() {
  struct foo f = {0};
  struct foo old;
  __atomic_exchange(&f, &bigThing, &old, 5);
  return __c11_atomic_exchange(&bigAtomic, f, 5);
}
int structAtomicCmpExchange() {
  _Bool x = __atomic_compare_exchange(&smallThing, &thing1, &thing2, 1, 5, 5);
  struct foo f = {0};
  struct foo g = {0};
  g.big[12] = 12;
  return x & __c11_atomic_compare_exchange_strong(&bigAtomic, &f, g, 5, 5);
}
_Atomic(int) atomic_init_i = 42;
void atomic_init_foo()
{
  _Atomic(int) j = 12;
  __c11_atomic_init(&j, 42);
}

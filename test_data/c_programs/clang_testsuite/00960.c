enum {
  memory_order_relaxed = 0,
  memory_order_consume = 1,
  memory_order_acquire = 2,
  memory_order_release = 3,
  memory_order_acq_rel = 4,
  memory_order_seq_cst = 5
};
typedef struct { void *a, *b; } pointer_pair_t;
typedef struct { void *a, *b, *c, *d; } pointer_quad_t;
extern _Atomic(_Bool) a_bool;
extern _Atomic(float) a_float;
extern _Atomic(void*) a_pointer;
extern _Atomic(pointer_pair_t) a_pointer_pair;
extern _Atomic(pointer_quad_t) a_pointer_quad;
void test0() {
  __c11_atomic_store(&a_bool, 1, memory_order_seq_cst);
}
void test1() {
  __c11_atomic_store(&a_float, 3, memory_order_seq_cst);
}
void test2() {
  __c11_atomic_store(&a_pointer, &a_bool, memory_order_seq_cst);
}
void test3(pointer_pair_t pair) {
  __c11_atomic_store(&a_pointer_pair, pair, memory_order_seq_cst);
}
void test4(pointer_quad_t quad) {
  __c11_atomic_store(&a_pointer_quad, quad, memory_order_seq_cst);
}

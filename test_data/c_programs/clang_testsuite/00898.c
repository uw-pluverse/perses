enum memory_order {
  memory_order_relaxed, memory_order_consume, memory_order_acquire,
  memory_order_release, memory_order_acq_rel, memory_order_seq_cst
};
int *test_c11_atomic_fetch_add_int_ptr(_Atomic(int *) *p) {
  return __c11_atomic_fetch_add(p, 3, memory_order_seq_cst);
}
int *test_c11_atomic_fetch_sub_int_ptr(_Atomic(int *) *p) {
  return __c11_atomic_fetch_sub(p, 5, memory_order_seq_cst);
}
int test_c11_atomic_fetch_add_int(_Atomic(int) *p) {
  return __c11_atomic_fetch_add(p, 3, memory_order_seq_cst);
}
int test_c11_atomic_fetch_sub_int(_Atomic(int) *p) {
  return __c11_atomic_fetch_sub(p, 5, memory_order_seq_cst);
}
int *fp2a(int **p) {
  return __atomic_fetch_sub(p, 4, memory_order_relaxed);
}
int test_atomic_fetch_add(int *p) {
  return __atomic_fetch_add(p, 55, memory_order_seq_cst);
}
int test_atomic_fetch_sub(int *p) {
  return __atomic_fetch_sub(p, 55, memory_order_seq_cst);
}
int test_atomic_fetch_and(int *p) {
  return __atomic_fetch_and(p, 55, memory_order_seq_cst);
}
int test_atomic_fetch_or(int *p) {
  return __atomic_fetch_or(p, 55, memory_order_seq_cst);
}
int test_atomic_fetch_xor(int *p) {
  return __atomic_fetch_xor(p, 55, memory_order_seq_cst);
}
int test_atomic_fetch_nand(int *p) {
  return __atomic_fetch_nand(p, 55, memory_order_seq_cst);
}
int test_atomic_add_fetch(int *p) {
  return __atomic_add_fetch(p, 55, memory_order_seq_cst);
}
int test_atomic_sub_fetch(int *p) {
  return __atomic_sub_fetch(p, 55, memory_order_seq_cst);
}
int test_atomic_and_fetch(int *p) {
  return __atomic_and_fetch(p, 55, memory_order_seq_cst);
}
int test_atomic_or_fetch(int *p) {
  return __atomic_or_fetch(p, 55, memory_order_seq_cst);
}
int test_atomic_xor_fetch(int *p) {
  return __atomic_xor_fetch(p, 55, memory_order_seq_cst);
}
int test_atomic_nand_fetch(int *p) {
  return __atomic_nand_fetch(p, 55, memory_order_seq_cst);
}

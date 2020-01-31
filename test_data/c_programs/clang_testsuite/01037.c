int i;
long long l;
typedef enum memory_order {
  memory_order_relaxed, memory_order_consume, memory_order_acquire,
  memory_order_release, memory_order_acq_rel, memory_order_seq_cst
} memory_order;
void test_presence(void)
{
  __atomic_fetch_add(&i, 1, memory_order_seq_cst);
  __atomic_fetch_sub(&i, 1, memory_order_seq_cst);
  int r;
  __atomic_load(&i, &r, memory_order_seq_cst);
  r = 0;
  __atomic_store(&i, &r, memory_order_seq_cst);
  __atomic_fetch_add(&l, 1, memory_order_seq_cst);
  __atomic_fetch_sub(&l, 1, memory_order_seq_cst);
  long long rl;
  __atomic_load(&l, &rl, memory_order_seq_cst);
  rl = 0;
  __atomic_store(&l, &rl, memory_order_seq_cst);
}

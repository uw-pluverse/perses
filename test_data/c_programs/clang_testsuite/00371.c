unsigned char c1, c2;
unsigned short s1, s2;
unsigned int i1, i2;
unsigned long long ll1, ll2;
unsigned char a1[100], a2[100];
enum memory_order {
  memory_order_relaxed,
  memory_order_consume,
  memory_order_acquire,
  memory_order_release,
  memory_order_acq_rel,
  memory_order_seq_cst
};
void test1(void) {
  (void)__atomic_load(&c1, &c2, memory_order_seq_cst);
  (void)__atomic_store(&c1, &c2, memory_order_seq_cst);
  (void)__atomic_load(&s1, &s2, memory_order_seq_cst);
  (void)__atomic_store(&s1, &s2, memory_order_seq_cst);
  (void)__atomic_load(&i1, &i2, memory_order_seq_cst);
  (void)__atomic_store(&i1, &i2, memory_order_seq_cst);
  (void)__atomic_load(&ll1, &ll2, memory_order_seq_cst);
  (void)__atomic_store(&ll1, &ll2, memory_order_seq_cst);
  (void)__atomic_load(&a1, &a2, memory_order_seq_cst);
  (void)__atomic_store(&a1, &a2, memory_order_seq_cst);
}

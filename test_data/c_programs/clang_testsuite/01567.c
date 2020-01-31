struct spinlock_t {
  int lock;
} audit_skb_queue;
void fn1() {
  audit_skb_queue = (lock);
}
void fn2() {
  audit_skb_queue + (lock);
}

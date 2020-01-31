void f0(void *a, void *b) {
 __clear_cache(a,b);
}
void *tp (void) {
  return __builtin_thread_pointer ();
}
unsigned rbit(unsigned a) {
  return __builtin_arm_rbit(a);
}
unsigned long long rbit64(unsigned long long a) {
  return __builtin_arm_rbit64(a);
}
void hints() {
  __builtin_arm_nop();
  __builtin_arm_yield();
  __builtin_arm_wfe();
  __builtin_arm_wfi();
  __builtin_arm_sev();
  __builtin_arm_sevl();
}
void barriers() {
  __builtin_arm_dmb(1);
  __builtin_arm_dsb(2);
  __builtin_arm_isb(3);
}
void prefetch() {
  __builtin_arm_prefetch(0, 1, 2, 0, 1);
  __builtin_arm_prefetch(0, 0, 0, 1, 1);
  __builtin_arm_prefetch(0, 0, 0, 1, 1);
  __builtin_arm_prefetch(0, 0, 0, 0, 0);
}
unsigned rsr() {
  return __builtin_arm_rsr("1:2:3:4:5");
}
unsigned long rsr64() {
  return __builtin_arm_rsr64("1:2:3:4:5");
}
void *rsrp() {
  return __builtin_arm_rsrp("1:2:3:4:5");
}
void wsr(unsigned v) {
  __builtin_arm_wsr("1:2:3:4:5", v);
}
void wsr64(unsigned long v) {
  __builtin_arm_wsr64("1:2:3:4:5", v);
}
void wsrp(void *v) {
  __builtin_arm_wsrp("1:2:3:4:5", v);
}

typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long int int64_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;
typedef unsigned long int uintptr_t;
typedef long int intmax_t;
typedef unsigned long int uintmax_t;
void *f0()
{
  return __builtin_thread_pointer();
}
void f1(char *a, char *b) {
 __clear_cache(a,b);
}
void test_eh_return_data_regno()
{
  volatile int res;
  res = __builtin_eh_return_data_regno(0);
  res = __builtin_eh_return_data_regno(1);
}
void nop() {
  __builtin_arm_nop();
}
void yield() {
  __builtin_arm_yield();
}
void wfe() {
  __builtin_arm_wfe();
}
void wfi() {
  __builtin_arm_wfi();
}
void sev() {
  __builtin_arm_sev();
}
void sevl() {
  __builtin_arm_sevl();
}
void dbg() {
  __builtin_arm_dbg(0);
}
void test_barrier() {
  __builtin_arm_dmb(1);
  __builtin_arm_dsb(2);
  __builtin_arm_isb(3);
}
unsigned rbit(unsigned a) {
  return __builtin_arm_rbit(a);
}
void prefetch(int i) {
  __builtin_arm_prefetch(&i, 0, 1);
  __builtin_arm_prefetch(&i, 1, 1);
  __builtin_arm_prefetch(&i, 1, 0);
}
void ldc(const void *i) {
  __builtin_arm_ldc(1, 2, i);
}
void ldcl(const void *i) {
  __builtin_arm_ldcl(1, 2, i);
}
void ldc2(const void *i) {
  __builtin_arm_ldc2(1, 2, i);
}
void ldc2l(const void *i) {
  __builtin_arm_ldc2l(1, 2, i);
}
void stc(void *i) {
  __builtin_arm_stc(1, 2, i);
}
void stcl(void *i) {
  __builtin_arm_stcl(1, 2, i);
}
void stc2(void *i) {
  __builtin_arm_stc2(1, 2, i);
}
void stc2l(void *i) {
  __builtin_arm_stc2l(1, 2, i);
}
void cdp() {
  __builtin_arm_cdp(1, 2, 3, 4, 5, 6);
}
void cdp2() {
  __builtin_arm_cdp2(1, 2, 3, 4, 5, 6);
}
unsigned mrc() {
  return __builtin_arm_mrc(15, 0, 13, 0, 3);
}
unsigned mrc2() {
  return __builtin_arm_mrc2(15, 0, 13, 0, 3);
}
void mcr(unsigned a) {
  __builtin_arm_mcr(15, 0, a, 13, 0, 3);
}
void mcr2(unsigned a) {
  __builtin_arm_mcr2(15, 0, a, 13, 0, 3);
}
void mcrr(uint64_t a) {
  __builtin_arm_mcrr(15, 0, a, 0);
}
void mcrr2(uint64_t a) {
  __builtin_arm_mcrr2(15, 0, a, 0);
}
uint64_t mrrc() {
  return __builtin_arm_mrrc(15, 0, 0);
}
uint64_t mrrc2() {
  return __builtin_arm_mrrc2(15, 0, 0);
}
unsigned rsr() {
  return __builtin_arm_rsr("cp1:2:c3:c4:5");
}
unsigned long long rsr64() {
  return __builtin_arm_rsr64("cp1:2:c3");
}
void *rsrp() {
  return __builtin_arm_rsrp("sysreg");
}
void wsr(unsigned v) {
  __builtin_arm_wsr("cp1:2:c3:c4:5", v);
}
void wsr64(unsigned long long v) {
  __builtin_arm_wsr64("cp1:2:c3", v);
}
void wsrp(void *v) {
  __builtin_arm_wsrp("sysreg", v);
}

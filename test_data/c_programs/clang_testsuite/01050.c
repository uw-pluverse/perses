long double testinc(_Atomic long double *addr) {
  return ++*addr;
}
long double testdec(_Atomic long double *addr) {
  return (*addr)--;
}
long double testcompassign(_Atomic long double *addr) {
  *addr -= 25;
  return *addr;
}
long double testassign(_Atomic long double *addr) {
  *addr = 115;
  return *addr;
}
long double test_volatile_inc(volatile _Atomic long double *addr) {
  return ++*addr;
}
long double test_volatile_dec(volatile _Atomic long double *addr) {
  return (*addr)--;
}
long double test_volatile_compassign(volatile _Atomic long double *addr) {
  *addr -= 25;
  return *addr;
}
long double test_volatile_assign(volatile _Atomic long double *addr) {
  *addr = 115;
  return *addr;
}

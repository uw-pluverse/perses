__int128 test_sync_call(__int128 *addr, __int128 val) {
  return __sync_fetch_and_add(addr, val);
}
__int128 test_c11_call(_Atomic __int128 *addr, __int128 val) {
  return __c11_atomic_fetch_sub(addr, val, 0);
}
__int128 test_atomic_call(__int128 *addr, __int128 val) {
  return __atomic_fetch_or(addr, val, 0);
}
__int128 test_expression(_Atomic __int128 *addr) {
  *addr &= 1;
}

int atomic(void) {
  int old;
  int val = 1;
  char valc = 1;
  _Bool valb = 0;
  unsigned int uval = 1;
  int cmp = 0;
  int* ptrval;
  old = __sync_fetch_and_add(&val, 1);
  old = __sync_fetch_and_sub(&valc, 2);
  old = __sync_fetch_and_min(&val, 3);
  old = __sync_fetch_and_max(&val, 4);
  old = __sync_fetch_and_umin(&uval, 5u);
  old = __sync_fetch_and_umax(&uval, 6u);
  old = __sync_lock_test_and_set(&val, 7);
  old = __sync_swap(&val, 8);
  old = __sync_val_compare_and_swap(&val, 4, 1976);
  old = __sync_bool_compare_and_swap(&val, 4, 1976);
  old = __sync_fetch_and_and(&val, 0x9);
  old = __sync_fetch_and_or(&val, 0xa);
  old = __sync_fetch_and_xor(&val, 0xb);
  old = __sync_fetch_and_nand(&val, 0xc);
  old = __sync_add_and_fetch(&val, 1);
  old = __sync_sub_and_fetch(&val, 2);
  old = __sync_and_and_fetch(&valc, 3);
  old = __sync_or_and_fetch(&valc, 4);
  old = __sync_xor_and_fetch(&valc, 5);
  old = __sync_nand_and_fetch(&valc, 6);
  __sync_val_compare_and_swap((void **)0, (void *)0, (void *)0);
  if ( __sync_val_compare_and_swap(&valb, 0, 1)) {
    old = 42;
  }
  __sync_bool_compare_and_swap((void **)0, (void *)0, (void *)0);
  __sync_lock_release(&val);
  __sync_lock_release(&ptrval);
  __sync_synchronize ();
  return old;
}
void release_return(int *lock) {
  return __sync_lock_release(lock);
}
void addrspace(int __attribute__((address_space(256))) * P) {
  __sync_bool_compare_and_swap(P, 0, 1);
  __sync_val_compare_and_swap(P, 0, 1);
  __sync_xor_and_fetch(P, 123);
}

void t_int__sync_fetch_and_add(int *p) { __typeof(__sync_fetch_and_add(p, 1)) *pp; pp = p; } void t_long__sync_fetch_and_add(long *p) { __typeof(__sync_fetch_and_add(p, 1)) *pp; pp = p; }
void t_int__sync_fetch_and_sub(int *p) { __typeof(__sync_fetch_and_sub(p, 1)) *pp; pp = p; } void t_long__sync_fetch_and_sub(long *p) { __typeof(__sync_fetch_and_sub(p, 1)) *pp; pp = p; }
void t_int__sync_fetch_and_or(int *p) { __typeof(__sync_fetch_and_or(p, 1)) *pp; pp = p; } void t_long__sync_fetch_and_or(long *p) { __typeof(__sync_fetch_and_or(p, 1)) *pp; pp = p; }
void t_int__sync_fetch_and_and(int *p) { __typeof(__sync_fetch_and_and(p, 1)) *pp; pp = p; } void t_long__sync_fetch_and_and(long *p) { __typeof(__sync_fetch_and_and(p, 1)) *pp; pp = p; }
void t_int__sync_fetch_and_xor(int *p) { __typeof(__sync_fetch_and_xor(p, 1)) *pp; pp = p; } void t_long__sync_fetch_and_xor(long *p) { __typeof(__sync_fetch_and_xor(p, 1)) *pp; pp = p; }
void t_int__sync_fetch_and_nand(int *p) { __typeof(__sync_fetch_and_nand(p, 1)) *pp; pp = p; } void t_long__sync_fetch_and_nand(long *p) { __typeof(__sync_fetch_and_nand(p, 1)) *pp; pp = p; }

void t_int__sync_add_and_fetch(int *p) { __typeof(__sync_add_and_fetch(p, 1)) *pp; pp = p; } void t_long__sync_add_and_fetch(long *p) { __typeof(__sync_add_and_fetch(p, 1)) *pp; pp = p; }
void t_int__sync_sub_and_fetch(int *p) { __typeof(__sync_sub_and_fetch(p, 1)) *pp; pp = p; } void t_long__sync_sub_and_fetch(long *p) { __typeof(__sync_sub_and_fetch(p, 1)) *pp; pp = p; }
void t_int__sync_or_and_fetch(int *p) { __typeof(__sync_or_and_fetch(p, 1)) *pp; pp = p; } void t_long__sync_or_and_fetch(long *p) { __typeof(__sync_or_and_fetch(p, 1)) *pp; pp = p; }
void t_int__sync_and_and_fetch(int *p) { __typeof(__sync_and_and_fetch(p, 1)) *pp; pp = p; } void t_long__sync_and_and_fetch(long *p) { __typeof(__sync_and_and_fetch(p, 1)) *pp; pp = p; }
void t_int__sync_xor_and_fetch(int *p) { __typeof(__sync_xor_and_fetch(p, 1)) *pp; pp = p; } void t_long__sync_xor_and_fetch(long *p) { __typeof(__sync_xor_and_fetch(p, 1)) *pp; pp = p; }
void t_int__sync_nand_and_fetch(int *p) { __typeof(__sync_nand_and_fetch(p, 1)) *pp; pp = p; } void t_long__sync_nand_and_fetch(long *p) { __typeof(__sync_nand_and_fetch(p, 1)) *pp; pp = p; }

void t_int__sync_lock_test_and_set(int *p) { __typeof(__sync_lock_test_and_set(p, 1)) *pp; pp = p; } void t_long__sync_lock_test_and_set(long *p) { __typeof(__sync_lock_test_and_set(p, 1)) *pp; pp = p; }
void t_int__sync_val_compare_and_swap(int *p) { __typeof(__sync_val_compare_and_swap(p, 1, 2)) *pp; pp = p; }
void t_long__sync_val_compare_and_swap(long *p) { __typeof(__sync_val_compare_and_swap(p, 1, 2)) *pp; pp = p; }

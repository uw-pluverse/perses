






long long swap_load (long long *a) { return __builtin_bswap64 (*a); }
long long swap_reg (long long a) { return __builtin_bswap64 (a); }
void swap_store (long long *a, long long b) { *a = __builtin_bswap64 (b); }

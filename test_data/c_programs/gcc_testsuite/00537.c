






unsigned long ul;
unsigned long load_bswap64 (unsigned long *p) { return __builtin_bswap64 (*p); }
void store_bswap64 (unsigned long a) { ul = __builtin_bswap64 (a); }

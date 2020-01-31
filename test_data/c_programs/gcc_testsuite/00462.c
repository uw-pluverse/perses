




unsigned int ui;
unsigned int load_bswap32 (unsigned int *p) { return __builtin_bswap32 (*p); }
void store_bswap32 (unsigned int a) { ui = __builtin_bswap32 (a); }

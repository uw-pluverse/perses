







typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef int i32;
void unary_not(u64 *a, u64 *b) { *a = ~ (*b + 0x1234567812345678ULL) ; }

void binary_add(u64 *a, u64 *b, u64 *c) { *a = *b + *c ; }
void binary_sub(u64 *a, u64 *b, u64 *c) { *a = *b - *c ; }
void binary_and(u64 *a, u64 *b, u64 *c) { *a = *b & *c ; }
void binary_or(u64 *a, u64 *b, u64 *c) { *a = *b | *c ; }
void binary_xor(u64 *a, u64 *b, u64 *c) { *a = *b ^ *c ; }

void ushift_right1(u64 *a, u64 *b, int c) { *a = *b >> 1; }
void ushift_right2(u64 *a, u64 *b, int c) { *a = *b >> 2; }
void ushift_right5(u64 *a, u64 *b, int c) { *a = *b >> 5; }
void ushift_rightn(u64 *a, u64 *b, int c) { *a = *b >> c; }

void sshift_right1(i64 *a, i64 *b, int c) { *a = *b >> 1; }
void sshift_right2(i64 *a, i64 *b, int c) { *a = *b >> 2; }
void sshift_right5(i64 *a, i64 *b, int c) { *a = *b >> 5; }
void sshift_rightn(i64 *a, i64 *b, int c) { *a = *b >> c; }

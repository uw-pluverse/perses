typedef unsigned long u;
typedef long s;




void g(void);

void rot1(u x, u n) { x = (x << (8 * sizeof(long) - (n))) | (x >> n); if ((s)x > 0) g(); }
   u rot2(u x, u n) { x = (x << (8 * sizeof(long) - (n))) | (x >> n); if ((s)x > 0) g(); return x; }
void shl1(u x, u n) { x <<= n; if ((s)x > 0) g(); }
   u shl2(u x, u n) { x <<= n; if ((s)x > 0) g(); return x; }
void shr1(u x, u n) { x >>= n; if ((s)x > 0) g(); }
   u shr2(u x, u n) { x >>= n; if ((s)x > 0) g(); return x; }
void asr1(s x, u n) { x >>= n; if ((s)x > 0) g(); }
   s asr2(s x, u n) { x >>= n; if ((s)x > 0) g(); return x; }

void rot1i(u x) { x = (x << (8 * sizeof(long) - (23))) | (x >> 23); if ((s)x > 0) g(); }
   u rot2i(u x) { x = (x << (8 * sizeof(long) - (23))) | (x >> 23); if ((s)x > 0) g(); return x; }
void shl1i(u x) { x <<= 23; if ((s)x > 0) g(); }
   u shl2i(u x) { x <<= 23; if ((s)x > 0) g(); return x; }
void shr1i(u x) { x >>= 23; if ((s)x > 0) g(); }
   u shr2i(u x) { x >>= 23; if ((s)x > 0) g(); return x; }
void asr1i(s x) { x >>= 23; if ((s)x > 0) g(); }
   s asr2i(s x) { x >>= 23; if ((s)x > 0) g(); return x; }

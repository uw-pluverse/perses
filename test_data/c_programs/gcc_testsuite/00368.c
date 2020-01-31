typedef unsigned u;
typedef signed s;

u rot(u x, u n) { return (x << n) | (x >> (32 - n)); }
u shl(u x, u n) { return x << n; }
u shr(u x, u n) { return x >> n; }
s asr(s x, u n) { return x >> n; }

u roti(u x) { return (x << 23) | (x >> 9); }
u shli(u x) { return x << 23; }
u shri(u x) { return x >> 23; }
s asri(s x) { return x >> 23; }

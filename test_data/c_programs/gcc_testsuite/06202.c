



extern void abort (void);

int cnt, d;
void foo (int x);
__attribute__((noinline, noclone)) unsigned int f1 (unsigned int x, unsigned int y) { unsigned int r = x - y; if (r >= x) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long f2 (unsigned long x, unsigned long y) { unsigned long r = x - y; if (r < x) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned short f3 (unsigned short x, unsigned short y) { unsigned short r = x - y; if (x <= r) foo (r); return r; }
__attribute__((noinline, noclone)) unsigned long long f4 (unsigned long long x, unsigned long long y) { unsigned long long r = x - y; if (d || x > r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned int f5 (unsigned int x, unsigned int y) { unsigned int r = x - y; if (d || r >= x) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long f6 (unsigned long x, unsigned long y) { unsigned long r = x - y; if (d || r < x) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned short f7 (unsigned short x, unsigned short y) { unsigned short r = x - y; if (d || x <= r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long long f8 (unsigned long long x, unsigned long long y) { unsigned long long r = x - y; if (d || x > r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned int f9 (unsigned int x, unsigned int y) { unsigned int r = x - y; if (r > y) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long f10 (unsigned long x, unsigned long y) { unsigned long r = x - y; if (r <= y) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned short f11 (unsigned short x, unsigned short y) { unsigned short r = x - y; if (y < r) foo (r); return r; }
__attribute__((noinline, noclone)) unsigned long long f12 (unsigned long long x, unsigned long long y) { unsigned long long r = x - y; if (y >= r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned int f13 (unsigned int x, unsigned int y) { unsigned int r = x - y; if (r >= y) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long f14 (unsigned long x, unsigned long y) { unsigned long r = x - y; if (r < y) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned short f15 (unsigned short x, unsigned short y) { unsigned short r = x - y; if (y <= r) foo (r); return r; }
__attribute__((noinline, noclone)) unsigned long long f16 (unsigned long long x, unsigned long long y) { unsigned long long r = x - y; if (d || y > r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned int f17 (unsigned int x, unsigned int y) { unsigned int r = x - y; if (d || r > y) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long f18 (unsigned long x, unsigned long y) { unsigned long r = x - y; if (d || r <= y) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned char f19 (unsigned char x, unsigned char y) { unsigned char r = x - y; if (d || y < r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long long f20 (unsigned long long x, unsigned long long y) { unsigned long long r = x - y; if (d || y >= r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned int f21 (unsigned int x, unsigned int y) { unsigned int r = x - y; if (d || r >= y) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long f22 (unsigned long x, unsigned long y) { unsigned long r = x - y; if (d || r < y) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned short f23 (unsigned short x, unsigned short y) { unsigned short r = x - y; if (d || y <= r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long long f24 (unsigned long long x, unsigned long long y) { unsigned long long r = x - y; if (d || y > r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned int f25 (unsigned int x, unsigned int y) { unsigned int r = x + y; if (r > x) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long f26 (unsigned long x, unsigned long y) { unsigned long r = x + y; if (r <= x) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned short f27 (unsigned short x, unsigned short y) { unsigned short r = x + y; if (x < r) foo (r); return r; }
__attribute__((noinline, noclone)) unsigned long long f28 (unsigned long long x, unsigned long long y) { unsigned long long r = x + y; if (x >= r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned int f29 (unsigned int x, unsigned int y) { unsigned int r = x + y; if (d || r > x) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long f30 (unsigned long x, unsigned long y) { unsigned long r = x + y; if (d || r <= x) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned char f31 (unsigned char x, unsigned char y) { unsigned char r = x + y; if (d || x < r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long long f32 (unsigned long long x, unsigned long long y) { unsigned long long r = x + y; if (d || x >= r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned int f33 (unsigned int x, unsigned int y) { unsigned int r = x + y; if (r > y) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long f34 (unsigned long x, unsigned long y) { unsigned long r = x + y; if (r <= y) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned short f35 (unsigned short x, unsigned short y) { unsigned short r = x + y; if (y < r) foo (r); return r; }
__attribute__((noinline, noclone)) unsigned long long f36 (unsigned long long x, unsigned long long y) { unsigned long long r = x + y; if (y >= r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned int f37 (unsigned int x, unsigned int y) { unsigned int r = x + y; if (d || r > y) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long f38 (unsigned long x, unsigned long y) { unsigned long r = x + y; if (d || r <= y) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned char f39 (unsigned char x, unsigned char y) { unsigned char r = x + y; if (d || y < r) foo (0); return r; }
__attribute__((noinline, noclone)) unsigned long long f40 (unsigned long long x, unsigned long long y) { unsigned long long r = x + y; if (d || y >= r) foo (0); return r; }

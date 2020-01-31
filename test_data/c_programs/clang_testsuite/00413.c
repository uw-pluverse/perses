int foo() {
L1:
  foo();
#pragma omp atomic
  {
    foo();
    goto L1;
  }
  goto L2;
#pragma omp atomic
  {
    foo();
  L2:
    foo();
  }
  return 0;
}
struct S {
  int a;
};
int readint() {
  int a = 0, b = 0;
#pragma omp atomic read
  ;
#pragma omp atomic read
  foo();
#pragma omp atomic read
  a += b;
#pragma omp atomic read
  a = 0;
#pragma omp atomic read
  a = b;
#pragma omp atomic read read
  a = b;
  return 0;
}
int readS() {
  struct S a, b;
#pragma omp atomic read read
  a = b;
  return a.a;
}
int writeint() {
  int a = 0, b = 0;
#pragma omp atomic write
  ;
#pragma omp atomic write
  foo();
#pragma omp atomic write
  a += b;
#pragma omp atomic write
  a = 0;
#pragma omp atomic write
  a = b;
#pragma omp atomic write write
  a = b;
  return 0;
}
int writeS() {
  struct S a, b;
#pragma omp atomic write write
  a = b;
  return a.a;
}
int updateint() {
  int a = 0, b = 0;
#pragma omp atomic update
  ;
#pragma omp atomic
  foo();
#pragma omp atomic
  a = b;
#pragma omp atomic update
  a = b || a;
#pragma omp atomic update
  a = a && b;
#pragma omp atomic update
  a = (float)a + b;
#pragma omp atomic
  a = 2 * b;
#pragma omp atomic
  a = b + *&a;
#pragma omp atomic update
  *&a = *&a + 2;
#pragma omp atomic update
  a++;
#pragma omp atomic
  ++a;
#pragma omp atomic update
  a--;
#pragma omp atomic
  --a;
#pragma omp atomic update
  a += b;
#pragma omp atomic
  a %= b;
#pragma omp atomic update
  a *= b;
#pragma omp atomic
  a -= b;
#pragma omp atomic update
  a /= b;
#pragma omp atomic
  a &= b;
#pragma omp atomic update
  a ^= b;
#pragma omp atomic
  a |= b;
#pragma omp atomic update
  a <<= b;
#pragma omp atomic
  a >>= b;
#pragma omp atomic update
  a = b + a;
#pragma omp atomic
  a = a * b;
#pragma omp atomic update
  a = b - a;
#pragma omp atomic
  a = a / b;
#pragma omp atomic update
  a = b & a;
#pragma omp atomic
  a = a ^ b;
#pragma omp atomic update
  a = b | a;
#pragma omp atomic
  a = a << b;
#pragma omp atomic
  a = b >> a;
#pragma omp atomic update update
  a /= b;
  return 0;
}
int captureint() {
  int a = 0, b = 0, c = 0;
#pragma omp atomic capture
  ;
#pragma omp atomic capture
  foo();
#pragma omp atomic capture
  a = b;
#pragma omp atomic capture
  a = b || a;
#pragma omp atomic capture
  b = a = a && b;
#pragma omp atomic capture
  a = (float)a + b;
#pragma omp atomic capture
  a = 2 * b;
#pragma omp atomic capture
  a = b + *&a;
#pragma omp atomic capture
  { a = b; }
#pragma omp atomic capture
  {}
#pragma omp atomic capture
  {a = b;a = b;}
#pragma omp atomic capture
  {a = b; a = b || a;}
#pragma omp atomic capture
  {b = a; a = a && b;}
#pragma omp atomic capture
  b = a = (float)a + b;
#pragma omp atomic capture
  b = a = 2 * b;
#pragma omp atomic capture
  b = a = b + *&a;
#pragma omp atomic capture
  c = *&a = *&a + 2;
#pragma omp atomic capture
  c = a++;
#pragma omp atomic capture
  c = ++a;
#pragma omp atomic capture
  c = a--;
#pragma omp atomic capture
  c = --a;
#pragma omp atomic capture
  c = a += b;
#pragma omp atomic capture
  c = a %= b;
#pragma omp atomic capture
  c = a *= b;
#pragma omp atomic capture
  c = a -= b;
#pragma omp atomic capture
  c = a /= b;
#pragma omp atomic capture
  c = a &= b;
#pragma omp atomic capture
  c = a ^= b;
#pragma omp atomic capture
  c = a |= b;
#pragma omp atomic capture
  c = a <<= b;
#pragma omp atomic capture
  c = a >>= b;
#pragma omp atomic capture
  c = a = b + a;
#pragma omp atomic capture
  c = a = a * b;
#pragma omp atomic capture
  c = a = b - a;
#pragma omp atomic capture
  c = a = a / b;
#pragma omp atomic capture
  c = a = b & a;
#pragma omp atomic capture
  c = a = a ^ b;
#pragma omp atomic capture
  c = a = b | a;
#pragma omp atomic capture
  c = a = a << b;
#pragma omp atomic capture
  c = a = b >> a;
#pragma omp atomic capture
  { c = *&a; *&a = *&a + 2;}
#pragma omp atomic capture
  { *&a = *&a + 2; c = *&a;}
#pragma omp atomic capture
  {c = a; a++;}
#pragma omp atomic capture
  {c = a; (a)++;}
#pragma omp atomic capture
  {++a;c = a;}
#pragma omp atomic capture
  {c = a;a--;}
#pragma omp atomic capture
  {--a;c = a;}
#pragma omp atomic capture
  {c = a; a += b;}
#pragma omp atomic capture
  {c = a; (a) += b;}
#pragma omp atomic capture
  {a %= b; c = a;}
#pragma omp atomic capture
  {c = a; a *= b;}
#pragma omp atomic capture
  {a -= b;c = a;}
#pragma omp atomic capture
  {c = a; a /= b;}
#pragma omp atomic capture
  {a &= b; c = a;}
#pragma omp atomic capture
  {c = a; a ^= b;}
#pragma omp atomic capture
  {a |= b; c = a;}
#pragma omp atomic capture
  {c = a; a <<= b;}
#pragma omp atomic capture
  {a >>= b; c = a;}
#pragma omp atomic capture
  {c = a; a = b + a;}
#pragma omp atomic capture
  {a = a * b; c = a;}
#pragma omp atomic capture
  {c = a; a = b - a;}
#pragma omp atomic capture
  {a = a / b; c = a;}
#pragma omp atomic capture
  {c = a; a = b & a;}
#pragma omp atomic capture
  {a = a ^ b; c = a;}
#pragma omp atomic capture
  {c = a; a = b | a;}
#pragma omp atomic capture
  {a = a << b; c = a;}
#pragma omp atomic capture
  {c = a; a = b >> a;}
#pragma omp atomic capture
  {c = a; a = foo();}
#pragma omp atomic capture capture
  b = a /= b;
  return 0;
}

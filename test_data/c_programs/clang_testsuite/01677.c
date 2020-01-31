typedef long long t1 __attribute__ ((vector_size (8)));
typedef char t2 __attribute__ ((vector_size (16)));
typedef float t3 __attribute__ ((vector_size (16)));
typedef short s2 __attribute__ ((vector_size(4)));
typedef enum { Evalue = 0x10000 } E;
void f()
{
  t1 v1;
  t2 v2;
  t3 v3;
  s2 v4;
  E e;
  e = (E)v4;
  v4 = (s2)e;
  v2 = (t2)v1;
  v1 = (t1)v2;
  v3 = (t3)v2;
  v1 = (t1)(char *)10;
  v1 = (t1)(long long)10;
  v1 = (t1)(short)10;
  long long r1 = (long long)v1;
  short r2 = (short)v1;
  char *r3 = (char *)v1;
}
void f2(t2 X);
void f3(t3 Y) {
  f2(Y);
}
typedef float float2 __attribute__ ((vector_size (8)));
typedef __attribute__((vector_size(8))) double float64x1_t;
typedef __attribute__((vector_size(16))) double float64x2_t;
float64x1_t vget_low_f64(float64x2_t __p0);
void f4() {
  float2 f2;
  double d, a, b, c;
  float64x2_t v = {0.0, 1.0};
  f2 += d;
  d += f2;
  a = 3.0 + vget_low_f64(v);
  b = vget_low_f64(v) + 3.0;
  c = vget_low_f64(v);
  c -= vget_low_f64(v);
  d = f2;
  d = d + f2;
}
typedef short short_sizeof_pointer __attribute__((vector_size(sizeof(void*))));
void f5() {
  short_sizeof_pointer v;
  void *ptr;
  v = ptr;
  ptr = v;
}

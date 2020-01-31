typedef unsigned int v2u __attribute__ ((vector_size (8)));
typedef signed int v2s __attribute__ ((vector_size (8)));
typedef signed int v1s __attribute__ ((vector_size (4)));
typedef float v2f __attribute__ ((vector_size(8)));
typedef signed short v4ss __attribute__ ((vector_size (8)));
void test1() {
  v2s v1;
  v2u v2;
  v1s v3;
  v2f v4;
  v4ss v5;
  v1 = v2;
  v1 = v3;
  v1 = v4;
  v1 = v5;
  v2 = v1;
  v2 = v3;
  v2 = v4;
  v2 = v5;
  v3 = v1;
  v3 = v2;
  v3 = v4;
  v3 = v5;
  v4 = v1;
  v4 = v2;
  v4 = v3;
  v4 = v5;
  v5 = v1;
  v5 = v2;
  v5 = v3;
  v5 = v4;
}
float test2(__attribute__((vector_size(16))) float a, int b) {
   return a[b];
}
typedef long long __attribute__((__vector_size__(2 * sizeof(long long))))
longlongvec;
void test3a(longlongvec *);
void test3(const unsigned *src) {
  test3a(src);
}

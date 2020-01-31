int test0(long v) {
  return v;
}
typedef int int4 __attribute__ ((vector_size(16)));
typedef long long long2 __attribute__((__vector_size__(16)));
int4 test1(long2 a) {
  int4 v127 = a;
  return v127;
}
int test2(long v) {
  return v / 2;
}

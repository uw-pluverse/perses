typedef __attribute__((ext_vector_type(4))) char char4;
typedef __attribute__((ext_vector_type(4))) short short4;
typedef __attribute__((ext_vector_type(1))) float float1;
static void test() {
  char4 vc4;
  float f;
  vc4 += f;
  short4 vs4;
  long long ll;
  vs4 += ll;
}

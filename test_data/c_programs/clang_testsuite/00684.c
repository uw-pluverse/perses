typedef float v4sf __attribute__ ((__vector_size__ (16)));
typedef double v4df __attribute__ ((__vector_size__ (32)));
typedef int v4i32 __attribute__ ((__vector_size__ (16)));
v4sf test_v4sf(float a) {
  return (v4sf){0.0f, a, 0.0f, 0.0f};
}
v4df test_v4df(double a) {
  return (v4df){0.0, a, 0.0, 0.0};
}
v4i32 test_v4i32(int a) {
  return (v4i32){0, a, 0, 0};
}

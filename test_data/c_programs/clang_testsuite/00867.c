typedef float __m128 __attribute__ ((__vector_size__ (16)));
typedef union
{
  int i[4];
  float f[4];
  __m128 v;
} u_t;
__m128 t(u_t *a) {
  return a->v;
}

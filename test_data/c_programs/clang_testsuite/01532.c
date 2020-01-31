typedef int __v4si __attribute__((__vector_size__(16)));
typedef float __m128 __attribute__((__vector_size__(16)));
__m128 _mm_xor_ps(__m128 a, __m128 b);
__m128 _mm_loadu_ps(const float *p);
void test1(float *input) {
  __m128 x, y, z, w, X;
  x = _mm_xor_ps(x,x);
  y = _mm_xor_ps(y,y);
  z = _mm_xor_ps(z,z);
  w = _mm_xor_ps(w,w);
  X = _mm_loadu_ps(&input[0]);
  X = _mm_xor_ps(X,X);
}




typedef double __m128d __attribute__ ((__vector_size__ (16), __may_alias__));

__m128d
foo (double d)
{
  return __extension__ (__m128d){ d, 0.0 };
}

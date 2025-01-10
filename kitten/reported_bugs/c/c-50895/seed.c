








#include <immintrin.h>

volatile __m256i y;
volatile __m128i x;
volatile __mmask8 m;

void extern
avx512vl_test (void)
{
  y = _mm256_alignr_epi64 (y, y, 3);
  y = _mm256_mask_alignr_epi64 (y, m, y, y, 3);
  y = _mm256_maskz_alignr_epi64 (m, y, y, 3);

  x = _mm_alignr_epi64 (x, x, 1);
  x = _mm_mask_alignr_epi64 (x, m, x, x, 1);
  x = _mm_maskz_alignr_epi64 (m, x, x, 1);
}

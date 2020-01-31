void
foo (float *u, float v, float w, float x, float y, float z, float t)
{
  int i, j, k, l;
  float a, *b, c, s, e;
#pragma omp parallel for private (i, j, k, l, a, b, c, s, e)
 for (j = 0; j < 1024; j++)
    {
      k = j * 64;
      l = j * 64 + 63;
      a = v + j * w;
      b = u + j * 64;
      for (i = k; i <= l; i++, b++, a += w)
 {
   c = a * a + y;
   s = (1.f - c * x) * (1.f - c * x);
   e = t * (1 / __builtin_sqrtf (c)) * s;
   *b += (c < z ? e : 0);
 }
    }
}

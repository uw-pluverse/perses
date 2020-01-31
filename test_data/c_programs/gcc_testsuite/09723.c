#pragma omp declare simd linear(p:1) linear(val(q):-1) linear(s:-3)
int
f1 (int *p, int *q, short *s)
{
  return *p + *q + *s;
}
#pragma omp declare simd linear(p:s) linear(q:t) uniform (s) linear(r:s) notinbranch simdlen(8) uniform(t)
int
f2 (int *p, short *q, int s, int r, int t)
{
  return *p + *q + r;
}

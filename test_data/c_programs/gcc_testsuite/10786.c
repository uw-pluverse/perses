





float x[4096];


#pragma omp declare simd
float
__attribute__ ((noinline))
my_mul (float x, float y) {
  return x * y;
}

__attribute__ ((noinline))
int foo ()
{
  int i = 0;
#pragma omp simd safelen (16)
 for (i = 0; i < 4096; i++)
    x[i] = my_mul ((float)i, 9932.3323);
  return (int)x[0];
}

int main ()
{
  int i = 0;
  for (i = 0; i < 4096; i++)
    x[i] = my_mul ((float) i, 9932.3323);
  foo ();
  return (int)x[0];
}

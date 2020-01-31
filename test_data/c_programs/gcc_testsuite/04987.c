


double t1 (double *x, int N)
{
  double result = 0.0;

 for (int i = 0; i < N; ++i)
    result = x[i] > result ? x[i] : result;

  return result;
}

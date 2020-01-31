extern double a_d[1024] __attribute__((__aligned__(32)));
extern double b_d[1024] __attribute__((__aligned__(32)));

void
vectorize_rsqrt_d (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a_d[i] = 1.0 / __builtin_sqrt (b_d[i]);
}

extern float a_f[1024] __attribute__((__aligned__(32)));
extern float b_f[1024] __attribute__((__aligned__(32)));

void
vectorize_rsqrt_f (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a_f[i] = 1.0f / __builtin_sqrtf (b_f[i]);
}

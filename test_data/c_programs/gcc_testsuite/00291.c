float a[1024] __attribute__((__aligned__(32)));
float b[1024] __attribute__((__aligned__(32)));
float c[1024] __attribute__((__aligned__(32)));
float d[1024] __attribute__((__aligned__(32)));
float e[1024] __attribute__((__aligned__(32)));

extern float floorf (float);
extern float ceilf (float);
extern float truncf (float);
extern float copysignf (float, float);

void
vector_floor (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = floorf (b[i]);
}

void
vector_ceil (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = ceilf (b[i]);
}

void
vector_trunc (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = truncf (b[i]);
}

void
vector_copysign (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = copysignf (b[i], c[i]);
}

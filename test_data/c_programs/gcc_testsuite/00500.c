double a[1024] __attribute__((__aligned__(32)));
double b[1024] __attribute__((__aligned__(32)));
double c[1024] __attribute__((__aligned__(32)));
double d[1024] __attribute__((__aligned__(32)));
double e[1024] __attribute__((__aligned__(32)));

void
vector_add (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = b[i] + c[i];
}

void
vector_subtract (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = b[i] - c[i];
}

void
vector_multiply (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = b[i] * c[i];
}

void
vector_multiply_add (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = (b[i] * c[i]) + d[i];
}

void
vector_multiply_subtract (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = (b[i] * c[i]) - d[i];
}

void
vector_divide (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = b[i] / c[i];
}

extern double sqrt (double);
extern double floor (double);
extern double ceil (double);
extern double trunc (double);
extern double nearbyint (double);
extern double rint (double);
extern double copysign (double, double);

void
vector_sqrt (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = sqrt (b[i]);
}

void
vector_floor (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = floor (b[i]);
}

void
vector_ceil (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = ceil (b[i]);
}

void
vector_trunc (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = trunc (b[i]);
}

void
vector_nearbyint (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = nearbyint (b[i]);
}

void
vector_rint (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = rint (b[i]);
}

void
vector_copysign (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    a[i] = copysign (b[i], c[i]);
}

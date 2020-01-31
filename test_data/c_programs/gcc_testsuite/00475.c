double
builtin_fma (double b, double c, double d)
{
  return __builtin_fma (b, c, d);
}

double
builtin_fms (double b, double c, double d)
{
  return __builtin_fma (b, c, -d);
}

double
builtin_fnma (double b, double c, double d)
{
  return - __builtin_fma (b, c, d);
}

double
builtin_fnms (double b, double c, double d)
{
  return - __builtin_fma (b, c, -d);
}

float
builtin_fmaf (float b, float c, float d)
{
  return __builtin_fmaf (b, c, d);
}

float
builtin_fmsf (float b, float c, float d)
{
  return __builtin_fmaf (b, c, -d);
}

float
builtin_fnmaf (float b, float c, float d)
{
  return - __builtin_fmaf (b, c, d);
}

float
builtin_fnmsf (float b, float c, float d)
{
  return - __builtin_fmaf (b, c, -d);
}

double
normal_fma (double b, double c, double d)
{
  return (b * c) + d;
}

float
normal_fmaf (float b, float c, float d)
{
  return (b * c) + d;
}





float vfa[1024] __attribute__((__aligned__(32)));
float vfb[1024] __attribute__((__aligned__(32)));
float vfc[1024] __attribute__((__aligned__(32)));
float vfd[1024] __attribute__((__aligned__(32)));

void
vector_fmaf (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    vfa[i] = __builtin_fmaf (vfb[i], vfc[i], vfd[i]);
}

void
vnormal_fmaf (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    vfa[i] = (vfb[i] * vfc[i]) + vfd[i];
}

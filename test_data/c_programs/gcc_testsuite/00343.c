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





double vda[1024] __attribute__((__aligned__(32)));
double vdb[1024] __attribute__((__aligned__(32)));
double vdc[1024] __attribute__((__aligned__(32)));
double vdd[1024] __attribute__((__aligned__(32)));

float vfa[1024] __attribute__((__aligned__(32)));
float vfb[1024] __attribute__((__aligned__(32)));
float vfc[1024] __attribute__((__aligned__(32)));
float vfd[1024] __attribute__((__aligned__(32)));

void
vector_fma (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    vda[i] = __builtin_fma (vdb[i], vdc[i], vdd[i]);
}

void
vector_fms (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    vda[i] = __builtin_fma (vdb[i], vdc[i], -vdd[i]);
}

void
vector_fnma (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    vda[i] = - __builtin_fma (vdb[i], vdc[i], vdd[i]);
}

void
vector_fnms (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    vda[i] = - __builtin_fma (vdb[i], vdc[i], -vdd[i]);
}

void
vector_fmaf (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    vfa[i] = __builtin_fmaf (vfb[i], vfc[i], vfd[i]);
}

void
vector_fmsf (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    vfa[i] = __builtin_fmaf (vfb[i], vfc[i], -vfd[i]);
}

void
vector_fnmaf (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    vfa[i] = - __builtin_fmaf (vfb[i], vfc[i], vfd[i]);
}

void
vector_fnmsf (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    vfa[i] = - __builtin_fmaf (vfb[i], vfc[i], -vfd[i]);
}

void
vnormal_fma (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    vda[i] = (vdb[i] * vdc[i]) + vdd[i];
}

void
vnormal_fmaf (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    vfa[i] = (vfb[i] * vfc[i]) + vfd[i];
}

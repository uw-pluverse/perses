double d1[1024] __attribute__((__aligned__(32)));
double d2[1024] __attribute__((__aligned__(32)));
double d3[1024] __attribute__((__aligned__(32)));

float f1[1024] __attribute__((__aligned__(32)));
float f2[1024] __attribute__((__aligned__(32)));
float f3[1024] __attribute__((__aligned__(32)));

void
test_double_atan2 (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_atan2 (d2[i], d3[i]);
}

void
test_float_atan2 (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_atan2f (f2[i], f3[i]);
}

void
test_double_hypot (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_hypot (d2[i], d3[i]);
}

void
test_float_hypot (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_hypotf (f2[i], f3[i]);
}

void
test_double_pow (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_pow (d2[i], d3[i]);
}

void
test_float_pow (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_powf (f2[i], f3[i]);
}

void
test_double_acos (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_acos (d2[i]);
}

void
test_float_acos (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_acosf (f2[i]);
}

void
test_double_acosh (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_acosh (d2[i]);
}

void
test_float_acosh (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_acoshf (f2[i]);
}

void
test_double_asin (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_asin (d2[i]);
}

void
test_float_asin (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_asinf (f2[i]);
}

void
test_double_asinh (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_asinh (d2[i]);
}

void
test_float_asinh (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_asinhf (f2[i]);
}

void
test_double_atan (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_atan (d2[i]);
}

void
test_float_atan (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_atanf (f2[i]);
}

void
test_double_atanh (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_atanh (d2[i]);
}

void
test_float_atanh (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_atanhf (f2[i]);
}

void
test_double_cbrt (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_cbrt (d2[i]);
}

void
test_float_cbrt (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_cbrtf (f2[i]);
}

void
test_double_cos (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_cos (d2[i]);
}

void
test_float_cos (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_cosf (f2[i]);
}

void
test_double_cosh (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_cosh (d2[i]);
}

void
test_float_cosh (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_coshf (f2[i]);
}

void
test_double_erf (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_erf (d2[i]);
}

void
test_float_erf (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_erff (f2[i]);
}

void
test_double_erfc (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_erfc (d2[i]);
}

void
test_float_erfc (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_erfcf (f2[i]);
}

void
test_double_exp2 (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_exp2 (d2[i]);
}

void
test_float_exp2 (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_exp2f (f2[i]);
}

void
test_double_exp (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_exp (d2[i]);
}

void
test_float_exp (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_expf (f2[i]);
}

void
test_double_expm1 (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_expm1 (d2[i]);
}

void
test_float_expm1 (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_expm1f (f2[i]);
}

void
test_double_lgamma (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_lgamma (d2[i]);
}

void
test_float_lgamma (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_lgammaf (f2[i]);
}

void
test_double_log10 (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_log10 (d2[i]);
}

void
test_float_log10 (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_log10f (f2[i]);
}

void
test_double_log1p (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_log1p (d2[i]);
}

void
test_float_log1p (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_log1pf (f2[i]);
}

void
test_double_log2 (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_log2 (d2[i]);
}

void
test_float_log2 (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_log2f (f2[i]);
}

void
test_double_log (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_log (d2[i]);
}

void
test_float_log (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_logf (f2[i]);
}

void
test_double_sin (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_sin (d2[i]);
}

void
test_float_sin (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_sinf (f2[i]);
}

void
test_double_sinh (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_sinh (d2[i]);
}

void
test_float_sinh (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_sinhf (f2[i]);
}

void
test_double_sqrt (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_sqrt (d2[i]);
}

void
test_float_sqrt (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_sqrtf (f2[i]);
}

void
test_double_tan (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_tan (d2[i]);
}

void
test_float_tan (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_tanf (f2[i]);
}

void
test_double_tanh (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    d1[i] = __builtin_tanh (d2[i]);
}

void
test_float_tanh (void)
{
  int i;

  for (i = 0; i < 1024; i++)
    f1[i] = __builtin_tanhf (f2[i]);
}

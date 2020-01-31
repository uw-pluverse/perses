



void
math (double d, int *ex, double *dp)
{
  acos (d);

  acosh (d);

  asin (d);

  asinh (d);

  atan (d);

  atanh (d);

  atan2 (d, d);

  cbrt (d);

  ceil (d);

  copysign (d, d);

  cos (d);

  cosh (d);

  erf (d);

  erfc (d);

  exp (d);

  exp2 (d);

  expm1 (d);

  fabs (d);

  fdim (d, d);

  floor (d);

  fma (d, d, d);

  fmax (d, d);

  fmin (d, d);

  fmod (d, d);

  frexp (d, ex);

  hypot (d, d);


  ilogb (d);
  ldexp (d, *ex);

  lgamma (d);

  llrint (d);

  llround (d);

  log (d);

  log10 (d);

  log1p (d);

  log2 (d);

  logb (d);

  lrint (d);

  lround (d);

  modf (d, dp);

  nan ("");

  nearbyint (d);

  nextafter (d, d);

  nexttoward (d, 20.0L);

  pow (d, d);

  remainder (d, d);

  remquo (d, d, ex);

  rint (d);

  round (d);

  scalbln (d, 100L);

  scalbn (d, 100);

  sin (d);

  sinh (d);

  sincos (d, dp, dp);

  sqrt (d);

  tan (d);

  tanh (d);

  tgamma (d);

  trunc (d);

}

void
cmplx (double _Complex z)
{
  cabs (z);

  cacos (z);

  cacosh (z);

  carg (z);

  casin (z);

  casinh (z);

  catan (z);

  catanh (z);

  ccos (z);

  ccosh (z);

  cexp (z);

  cimag (z);

  clog (z);

  conj (z);

  cpow (z, z);

  cproj (z);

  creal (z);

  csin (z);

  csinh (z);

  csqrt (z);

  ctan (z);

  ctanh (z);

}

void
string (void *p, void *q, long unsigned int sz)
{
  memchr (p, 2, sz);


  memcmp (p, q, sz);
  memcpy (p, q, sz);

  memmove (p, q, sz);

  memset (p, 0, sz);

  strcat (p, q);

  strchr (p, 'a');


  strcmp (p, q);
  strcpy (p, q);

  strcspn (p, q);

  strlen (p);

  strncat (p, q, sz);


  strncmp (p, q, sz);
  strncpy (p, q, sz);

  strpbrk (p, q);

  strrchr (p, 'q');

  strspn (p, q);

  strstr (p, q);

}


typedef struct { int i; } FILE;

void
stdio (FILE *fp, void *p, long unsigned int sz)
{
  fprintf (fp, "");

  fscanf (fp, "");

  fwrite (p, sz, sz, fp);

  printf ("");

  scanf ("");

  snprintf ("", sz, "");

  sprintf ("", "");

  sscanf ("", "");

}

void
stdlib (void *p, void *q, long unsigned int sz)
{
  abort ();

  calloc (sz, 1);

  exit (1);

  free (p);

  labs (1L);

  llabs (1LL);

  malloc (sz);

  realloc (p, sz);

  aligned_alloc (sz, sz);

}

void
inttypes (long int j)
{
  imaxabs (j);

}

struct tm;

void
timeh (char *s, long unsigned int sz, struct tm *tm)
{
  strftime (s, sz, "", tm);

}









float vfloat;
double vdouble;
long double vlongdouble;

void ffloat (float f);
void fdouble (double d);
void flongdouble (long double ld);

void h (void)
{
  float f = 0;
  double d = 0;
  long double ld = 0;

  ffloat (3.1);
  vfloat = 3.1;
  ffloat (3.1L);
  vfloat = 3.1L;
  fdouble (3.1L);
  vdouble = 3.1L;
  ffloat (vdouble);
  vfloat = vdouble;
  ffloat (vlongdouble);
  vfloat = vlongdouble;
  fdouble (vlongdouble);
  vdouble = vlongdouble;


  ffloat ((float) 3.1);
  vfloat = (float) 3.1;
  ffloat ((float) 3.1L);
  vfloat = (float) 3.1L;
  fdouble ((double) 3.1L);
  vdouble = (double) 3.1L;
  ffloat ((float) vdouble);
  vfloat = (float) vdouble;
  ffloat ((float) vlongdouble);
  vfloat = (float) vlongdouble;
  fdouble ((double) vlongdouble);
  vdouble = (double) vlongdouble;


  ffloat (3.0);
  vfloat = 3.0;
  ffloat (3.1f);
  vfloat = 3.1f;
  ffloat (0.25L);
  vfloat = 0.25L;


  fdouble (3.0);
  vdouble = 3.0;
  fdouble (3.1f);
  vdouble = 3.1f;
  fdouble (0.25L);
  vdouble = 0.25L;

  flongdouble (3.0);
  vlongdouble = 3.0;
  flongdouble (3.1f);
  vlongdouble = 3.1f;
  flongdouble (0.25L);
  vlongdouble = 0.25L;

  ffloat (f);
  vfloat = f;
  fdouble (f);
  vdouble = f;
  fdouble (d);
  vdouble = d;
  flongdouble (f);
  vlongdouble = f;
  flongdouble (d);
  vlongdouble = d;
  flongdouble (ld);
  vlongdouble = ld;
}

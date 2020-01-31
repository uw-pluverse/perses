








float vfloat;
double vdouble;
long double vlongdouble;
int bar;

void fsi (signed int x);
void fui (unsigned int x);
void ffloat (float f);
void fdouble (double d);
void flongdouble (long double ld);

void h (void)
{
  unsigned int ui = 3;
  int si = 3;
  unsigned char uc = 3;
  signed char sc = 3;
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

  fsi (3.1f);
  si = 3.1f;
  fsi (3.1);
  si = 3.1;
  fsi (d);
  si = d;
  ffloat (2147483647);
  vfloat = 2147483647;
  ffloat (16777217);
  vfloat = 16777217;

  sc = bar != 0 ? 2.1 : 10;
  uc = bar != 0 ? 2.1 : 10;
}

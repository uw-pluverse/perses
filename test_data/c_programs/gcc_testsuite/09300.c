








void fsi (signed int x);
void fui (unsigned int x);
void ffloat (float x);
void fdouble (double x);

float vfloat;
double vdouble;

void h (void)
{
  unsigned int ui = 3;
  int si = 3;
  unsigned char uc = 3;
  signed char sc = 3;
  float f = 3;
  double d = 3;

  fsi (3.1f);
  si = 3.1f;
  fsi (3.1);
  si = 3.1;
  fsi (d);
  si = d;
  fui (-1.0);
  ui = -1.0;
  ffloat (2147483647);
  vfloat = 2147483647;
  ffloat (16777217);
  vfloat = 16777217;
  ffloat (si);
  vfloat = si;
  ffloat (ui);
  vfloat = ui;

  fsi (3);
  si = 3;
  fsi (3.0f);
  si = 3.0f;
  fsi (3.0);
  si = 3.0;
  fsi (16777217.0f);
  si = 16777217.0f;
  fsi ((int) 3.1);
  si = (int) 3.1;
  ffloat (3U);
  vfloat = 3U;
  ffloat (3);
  vfloat = 3;
  ffloat ((-2147483647 -1));
  vfloat = (-2147483647 -1);
  ffloat (uc);
  vfloat = uc;
  ffloat (sc);
  vfloat = sc;

  fdouble ((2147483647 *2U +1U));
  vdouble = (2147483647 *2U +1U);
  fdouble (ui);
  vdouble = ui;
  fdouble (si);
  vdouble = si;
}


void fss (signed short x);
void fus (unsigned short x);
void fsc (signed char x);
void fuc (unsigned char x);

void h2 (void)
{
  unsigned short int us;
  short int ss;
  unsigned char uc;
  signed char sc;

  fss (4294967294.0);
  ss = 4294967294.0;
  fss (-4294967294.0);
  ss = -4294967294.0;
  fus (4294967294.0);
  us = 4294967294.0;
  fus (-4294967294.0);
  us = -4294967294.0;

  fsc (500.0);
  sc = 500.0;
  fsc (-500.0);
  sc = -500.0;
  fuc (500.0);
  uc = 500.0;
  fuc (-500.0);
  uc = -500.0;

  fss (500.0);
  ss = 500.0;
  fss (-500.0);
  ss = -500.0;
  fus (500.0);
  us = 500.0;
  fus (-500.0);
  us = -500.0;
}

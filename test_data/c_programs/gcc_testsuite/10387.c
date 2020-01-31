





void fsc(signed char);
void fsi(signed int);
void fsll(signed long long);
void fuc(unsigned char);
void fui(unsigned int);
void full(unsigned long long);
void ff(float);
void fld(long double);
void fcf(_Complex float);

struct s {
  void (*fsc)(signed char);
  void (*fsi)(signed int);
  void (*fsll)(signed long long);
  void (*fuc)(unsigned char);
  void (*fui)(unsigned int);
  void (*full)(unsigned long long);
  void (*ff)(float);
  void (*fld)(long double);
  void (*fcf)(_Complex float);
} x;

signed char sc;
signed int si;
signed long long sll;
unsigned char uc;
unsigned int ui;
unsigned long long ull;
float f;
long double ld;
_Complex float cf;

void
g (void)
{
  fsi(f);
  x.fsi(f);
  fsi(cf);
  x.fsi(cf);
  fcf(f);
  x.fcf(f);
  fcf(si);
  x.fcf(si);
  ff(sc);
  x.ff(sc);
  ff(cf);
  x.ff(cf);
  ff(1.0);
  x.ff(1.0);
  fsll(sc);
  x.fsll(sc);
  fsc(sll);
  x.fsc(sll);
  fsi(ui);
  x.fsi(ui);
  full(sll);
  x.full(sll);
}





typedef const int CT1;

typedef volatile int VT1;

typedef char *restrict RT1;


void
foo (void)
{
  const CT1 x1;
  const const int x2;
  CT1 const x3;
  const int const x4;
  const int const x5;
  const int *const x6;
  volatile VT1 y1;
  volatile volatile int y2;
  VT1 volatile y3;
  volatile int volatile y4;
  volatile int volatile y5;
  volatile int *volatile y6;
  RT1 restrict r1;
  char *restrict restrict r2;
  restrict RT1 r3;

  char *restrict restrict r4;
  char *restrict *restrict r5;
}

void c1(const CT1 t) { }
void c2(const const int t) { }
void c3(CT1 const t) { }
void c4(const int const t) { }
void c5(const int const t) { }
void v1(volatile VT1 t) { }
void v2(volatile volatile int t) { }
void v3(VT1 volatile t) { }
void v4(volatile int volatile t) { }
void v5(volatile int volatile t) { }
void r1(restrict RT1 t) { }
void r2(RT1 restrict t) { }
void r3(char *restrict restrict t) { }
void r4(char *restrict restrict t) { }

typedef const CT1 CCT1;
typedef const const int CCT2;
typedef CT1 const CT1C;
typedef const int const CT2C;
typedef const int const CIC;
typedef volatile VT1 VVT1;
typedef volatile volatile int VVT2;
typedef VT1 volatile VT1V;
typedef volatile int volatile VT2V;
typedef volatile int volatile VIV;
typedef RT1 restrict RT1R;
typedef char *restrict restrict RT2R;
typedef restrict RT1 RRT1;
typedef int *restrict restrict IRR;

int outer1;
extern int outer2;
int outer4;
int outer4;
int outer5;
int outer6(float);
int outer7(float);
void outer_test() {
  extern float outer1;
  extern float outer2;
  extern float outer3;
  double outer4;
  extern int outer5;
  extern int outer6;
  int outer7;
  extern int outer8;
  extern int outer9;
  {
    extern int outer9;
  }
}
int outer3;
float outer4;
float outer5;
int outer8(int);
float outer9;
extern int outer13;
void outer_shadowing_test() {
  extern int outer10;
  extern int outer11;
  extern int outer12;
  {
    float outer10;
    float outer11;
    float outer12;
    {
      extern int outer10;
      extern float outer11;
      static double outer12;
      {
        extern float outer12;
        extern float outer13;
      }
    }
  }
}
void g18(void) {
  extern int g19;
}
int *p=&g19;
static int a;
extern int a;
int a;
void f(int x) {
  extern int x;
}
extern int b[];
void g20() { extern int b[3]; }
void g21() { extern int b[4]; }

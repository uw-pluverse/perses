static int g0;
int g0;
static int g1;
extern int g1;
static int g2;
__private_extern__ int g2;
int g3;
static int g3;
extern int g4;
static int g4;
__private_extern__ int g5;
static int g5;
void f0() {
  int g6;
  extern int g6;
}
void f1() {
  int g7;
  __private_extern__ int g7;
}
void f2() {
  extern int g8;
  int g8;
}
void f3() {
  __private_extern__ int g9;
  int g9;
}
void f4() {
  extern int g10;
  extern int g10;
}
void f5() {
  __private_extern__ int g11;
  __private_extern__ int g11;
}
void f6() {
  extern int g12;
  __private_extern__ int g12;
}
void f7() {
  __private_extern__ int g13;
  extern int g13;
}
struct s0;
void f8() {
  extern struct s0 g14;
  __private_extern__ struct s0 g14;
}
struct s0 { int x; };
void f9() {
  extern int g15 = 0;
  __private_extern__ int g16 = 0;
}
extern int g17;
int g17 = 0;
extern int g18 = 0;
__private_extern__ int g19;
int g19 = 0;
__private_extern__ int g20 = 0;

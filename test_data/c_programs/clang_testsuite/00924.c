struct s1 {
  int a;
  int b;
};
struct s1 f1_1(void) { while (1) {} }
void f1_2(struct s1 a0) {}
struct s2 {
  short a;
  short b;
};
struct s2 f2_1(void) { while (1) {} }
struct s3 {
  char a;
  char b;
};
struct s3 f3_1(void) { while (1) {} }
struct s4 {
  char a:4;
  char b:4;
};
struct s4 f4_1(void) { while (1) {} }
struct s5 {
  double a;
};
struct s5 f5_1(void) { while (1) {} }
void f5_2(struct s5 a0) {}
struct s6 {
  float a;
};
struct s6 f6_1(void) { while (1) {} }
void f6_2(struct s6 a0) {}

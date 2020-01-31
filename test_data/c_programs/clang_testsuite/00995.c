void f0(int i, long j, double k) {}
typedef struct {
  int aa;
  int bb;
} s1;
void f1(s1 i) {}
typedef struct {
  int cc;
} s2;
s2 f2() {
  s2 foo;
  return foo;
}
void f3(long long i) {}
void f4(char a, short b) {}
void f5(unsigned char a, unsigned short b) {}
enum my_enum {
  ENUM1,
  ENUM2,
  ENUM3,
};
void f6(enum my_enum a) {}
union simple_union {
  int a;
  char b;
};
void f7(union simple_union s) {}
typedef struct {
  int b4 : 4;
  int b3 : 3;
  int b8 : 8;
} bitfield1;
void f8(bitfield1 bf1) {}

void f0(int i, long j, long long k) {}
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
typedef struct {
  int cc;
  int dd;
} s3;
s3 f3() {
  s3 foo;
  return foo;
}
void f4(long long i) {}
void f5(char a, short b) {}
void f6(unsigned char a, unsigned short b) {}
enum my_enum {
  ENUM1,
  ENUM2,
  ENUM3,
};
void f7(enum my_enum a) {}
enum my_big_enum {
  ENUM4 = 0xFFFFFFFFFFFFFFFF,
};
void f8(enum my_big_enum a) {}
union simple_union {
  int a;
  char b;
};
void f9(union simple_union s) {}
typedef struct {
  int b4 : 4;
  int b3 : 3;
  int b8 : 8;
} bitfield1;
void f10(bitfield1 bf1) {}

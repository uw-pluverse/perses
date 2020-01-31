void test_6792488(void) {
  int x = 0x3ff0000000000000U;
}
void test_7809123(void) {
  struct { int i5 : 5; } a;
  a.i5 = 36;
}
void test() {
  struct { int bit : 1; } a;
  a.bit = 1;
}
enum Test2 { K_zero, K_one };
enum Test2 test2(enum Test2 *t) {
  *t = 20;
  return 10;
}
void test3() {
  struct A {
    unsigned int foo : 2;
    int bar : 2;
  };
  struct A a = { 0, 10 };
  struct A b[] = { 0, 10, 0, 0 };
  struct A c[] = {{10, 0}};
  struct A d = (struct A) { 10, 0 };
  struct A e = { .foo = 10 };
}
void test4() {
  struct A {
    char c : 2;
  } a;
  a.c = 0x101;
}
void test5() {
  struct A {
    _Bool b : 1;
  } a;
  a.b = 100;
}
void test6() {
  unsigned char x = 0 ? 65535 : 1;
  unsigned char y = 1 ? 65535 : 1;
}
void test7() {
 struct {
  unsigned int twoBits1:2;
  unsigned int twoBits2:2;
  unsigned int reserved:28;
 } f;
 f.twoBits1 = ~0;
 f.twoBits1 = ~1;
 f.twoBits2 = ~2;
 f.twoBits1 &= ~1;
 f.twoBits2 &= ~2;
}
void test8() {
  enum E { A, B, C };
  struct { enum E x : 1; } f;
  f.x = C;
}
void test9() {
  const char max_char = 0x7F;
  const short max_short = 0x7FFF;
  const int max_int = 0x7FFFFFFF;
  const short max_char_plus_one = (short)max_char + 1;
  const int max_short_plus_one = (int)max_short + 1;
  const long max_int_plus_one = (long)max_int + 1;
  char new_char = max_char_plus_one;
  short new_short = max_short_plus_one;
  int new_int = max_int_plus_one;
  char hex_char = 0x80;
  short hex_short = 0x8000;
  int hex_int = 0x80000000;
  char oct_char = 0200;
  short oct_short = 0100000;
  int oct_int = 020000000000;
  char bin_char = 0b10000000;
  short bin_short = 0b1000000000000000;
  int bin_int = 0b10000000000000000000000000000000;
  char macro_char_hex = 0xff;
  char macro_char_dec = 255;
  char array_init[] = { 255, 127, 128, 129, 0 };
}
void test10() {
  struct S {
    unsigned a : 4;
  } s;
  s.a = -1;
  s.a = 15;
  s.a = -8;
  s.a = ~0;
  s.a = ~0U;
  s.a = ~(1<<1);
  s.a = -9;
  s.a = 16;
}

unsigned char test_addcb(unsigned char x, unsigned char y,
                         unsigned char carryin, unsigned char *z) {
  unsigned char carryout;
  *z = __builtin_addcb(x, y, carryin, &carryout);
  return carryout;
}
unsigned short test_addcs(unsigned short x, unsigned short y,
                          unsigned short carryin, unsigned short *z) {
  unsigned short carryout;
  *z = __builtin_addcs(x, y, carryin, &carryout);
  return carryout;
}
unsigned test_addc(unsigned x, unsigned y, unsigned carryin, unsigned *z) {
  unsigned carryout;
  *z = __builtin_addc(x, y, carryin, &carryout);
  return carryout;
}
unsigned long test_addcl(unsigned long x, unsigned long y,
                         unsigned long carryin, unsigned long *z) {
  unsigned long carryout;
  *z = __builtin_addcl(x, y, carryin, &carryout);
  return carryout;
}
unsigned long long test_addcll(unsigned long long x, unsigned long long y,
                               unsigned long long carryin,
                               unsigned long long *z) {
  unsigned long long carryout;
  *z = __builtin_addcll(x, y, carryin, &carryout);
  return carryout;
}
unsigned char test_subcb(unsigned char x, unsigned char y,
                         unsigned char carryin, unsigned char *z) {
  unsigned char carryout;
  *z = __builtin_subcb(x, y, carryin, &carryout);
  return carryout;
}
unsigned short test_subcs(unsigned short x, unsigned short y,
                          unsigned short carryin, unsigned short *z) {
  unsigned short carryout;
  *z = __builtin_subcs(x, y, carryin, &carryout);
  return carryout;
}
unsigned test_subc(unsigned x, unsigned y, unsigned carryin, unsigned *z) {
  unsigned carryout;
  *z = __builtin_subc(x, y, carryin, &carryout);
  return carryout;
}
unsigned long test_subcl(unsigned long x, unsigned long y,
                         unsigned long carryin, unsigned long *z) {
  unsigned long carryout;
  *z = __builtin_subcl(x, y, carryin, &carryout);
  return carryout;
}
unsigned long long test_subcll(unsigned long long x, unsigned long long y,
                               unsigned long long carryin,
                               unsigned long long *z) {
  unsigned long long carryout;
  *z = __builtin_subcll(x, y, carryin, &carryout);
  return carryout;
}

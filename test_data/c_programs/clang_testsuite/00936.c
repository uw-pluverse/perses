__int64 test__emul(int a, int b) {
  return __emul(a, b);
}
unsigned __int64 test__emulu(unsigned int a, unsigned int b) {
  return __emulu(a, b);
}
char test__readgsbyte(unsigned long Offset) {
  return __readgsbyte(Offset);
}
short test__readgsword(unsigned long Offset) {
  return __readgsword(Offset);
}
long test__readgsdword(unsigned long Offset) {
  return __readgsdword(Offset);
}
long long test__readgsqword(unsigned long Offset) {
  return __readgsqword(Offset);
}
__int64 test__mulh(__int64 a, __int64 b) {
  return __mulh(a, b);
}
unsigned __int64 test__umulh(unsigned __int64 a, unsigned __int64 b) {
  return __umulh(a, b);
}
__int64 test_mul128(__int64 Multiplier,
                    __int64 Multiplicand,
                    __int64 *HighProduct) {
  return _mul128(Multiplier, Multiplicand, HighProduct);
}
unsigned __int64 test_umul128(unsigned __int64 Multiplier,
                              unsigned __int64 Multiplicand,
                              unsigned __int64 *HighProduct) {
  return _umul128(Multiplier, Multiplicand, HighProduct);
}

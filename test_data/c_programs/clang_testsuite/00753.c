unsigned char test_rotl8(unsigned char value, unsigned char shift) {
  return _rotl8(value, shift);
}
unsigned short test_rotl16(unsigned short value, unsigned char shift) {
  return _rotl16(value, shift);
}
unsigned int test_rotl(unsigned int value, int shift) {
  return _rotl(value, shift);
}
unsigned long test_lrotl(unsigned long value, int shift) {
  return _lrotl(value, shift);
}
unsigned __int64 test_rotl64(unsigned __int64 value, int shift) {
  return _rotl64(value, shift);
}
unsigned char test_rotr8(unsigned char value, unsigned char shift) {
  return _rotr8(value, shift);
}
unsigned short test_rotr16(unsigned short value, unsigned char shift) {
  return _rotr16(value, shift);
}
unsigned int test_rotr(unsigned int value, int shift) {
  return _rotr(value, shift);
}
unsigned long test_lrotr(unsigned long value, int shift) {
  return _lrotr(value, shift);
}
unsigned __int64 test_rotr64(unsigned __int64 value, int shift) {
  return _rotr64(value, shift);
}

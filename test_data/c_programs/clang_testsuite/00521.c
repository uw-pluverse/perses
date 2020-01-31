int f1(int c, int shamt) {
  return 1 << (c << shamt);
}
int f2(long c, int shamt) {
  return 1 << (c << shamt);
}
unsigned f3(unsigned c, int shamt) {
  return 1U << (c << shamt);
}
unsigned f4(unsigned long c, int shamt) {
  return 1U << (c << shamt);
}
int f5(int c, long long shamt) {
  return c << shamt;
}
int f6(int c, int shamt) {
  return c << shamt;
}

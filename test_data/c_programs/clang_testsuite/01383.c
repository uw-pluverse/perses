int f(int i) {
  switch (i) {
    case 2147483647 + 2:
      return 1;
    case 9223372036854775807L * 4:
      return 2;
    case (123456 *789012) + 1:
      return 3;
    case (2147483647*4)/4:
    case (2147483647*4)%4:
      return 4;
    case 2147483647:
      return 0;
  }
  return (i, 65537) * 65537;
}
unsigned long long l = 65536 * 65536;
unsigned long long l2 = 65536 * (unsigned)65536;
unsigned long long l3 = 65536 * 65536ULL;

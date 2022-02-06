typedef signed int8_t;
typedef short int16_t;
typedef int int32_t;
typedef unsigned uint8_t;
typedef short uint16_t;
typedef unsigned uint32_t;
static int16_t g_100 = 0x7EBAL;
uint8_t g_104 = 0xCAL;
uint16_t g_117;
int32_t g_222[5][5];
uint32_t g_654 = 0xAF7C65D6L;
static uint8_t g_1603;
uint32_t g_2244[9][2][3];
int32_t g_2684;
uint8_t func_6(int8_t, int16_t, int32_t, int8_t);
int8_t func_11(int32_t);
uint32_t func_1() {
  func_6(func_11(0), 7, 7, 0);
  return g_2684;
}
uint8_t func_6(int8_t p_7, int16_t p_8, int32_t p_9, int8_t p_10) {
  p_7 || (g_2244[1][0][1] = p_7);
  return 2;
}
int8_t func_11(p_12) {
  uint32_t l_1624[6][3][2];
  int32_t l_1883 = 0x709BFC8AL;
  for (g_117 = 0;;) {
    if (g_654)
      break;
    return l_1624[g_100][g_1603 + 1][g_1603];
  }
  if (g_104) {
  } else
    return g_222[g_100][g_100];
  for (; p_12;) {
  }
  return l_1883;
}
int main() { func_1(); }

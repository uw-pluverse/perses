typedef signed int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef unsigned uint8_t;
typedef unsigned uint16_t;
typedef unsigned uint32_t;
typedef long long uint64_t;
int8_t g_14 = 0x83L;
uint64_t g_71;
uint32_t g_81;
int32_t func_2(int32_t);
static int16_t func_12(int64_t);
int8_t func_28(int32_t, uint64_t, uint32_t, uint8_t, uint8_t);
uint16_t func_1() { func_2(func_12(g_14)); }
int32_t func_2(p_3) {
  for (; g_81;)
    continue;
}
int16_t func_12(int64_t p_13) {
  func_28(p_13, p_13, p_13, p_13, p_13);
  return p_13;
}
int8_t func_28(int32_t p_29, uint64_t p_30, uint32_t p_31, uint8_t p_32,
               uint8_t p_33) {
  uint32_t l_721 = 0x6FB6BC49L;
  int32_t l_725 = 1L;
  int64_t l_705 = -1L;
  g_71 = -(-l_705 ^ (l_721 | g_81)) * ~l_725;
  printf("g_71=%llu\n", g_71);
}
int main() { func_1(); }

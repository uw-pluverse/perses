typedef signed int8_t;
typedef short int16_t;
typedef int int32_t;
typedef unsigned uint8_t;
typedef unsigned uint16_t;
typedef unsigned uint32_t;
int16_t safe_sub_func_int16_t_s_s(int16_t si1, int16_t si2) {
  return si1 - si2;
}
uint32_t safe_sub_func_uint32_t_u_u(uint32_t ui1, uint32_t ui2) {
  return ui1 - ui2;
}
int32_t g_201;
uint16_t g_774;
volatile uint32_t g_1265[5][8];
uint8_t func_45(uint32_t p_46) {
  int8_t l_2275 = 0x4FL;
  for (;;) {
    for (g_774 = 0; g_774 < 20; g_774++)
      for (g_201 = 0; g_201 >= -27; g_201 = safe_sub_func_int16_t_s_s(g_201, 6))
        p_46 = safe_sub_func_uint32_t_u_u(l_2275, p_46);
    p_46 || g_1265[2][5];
  }
}
int main() {}

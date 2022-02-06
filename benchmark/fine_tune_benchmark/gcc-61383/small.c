typedef signed int8_t;
typedef short int16_t;
typedef int int32_t;
typedef unsigned uint8_t;
typedef short uint16_t;
typedef unsigned uint32_t;
int8_t safe_mod_func_int8_t_s_s(int8_t si1, int8_t si2) {
  return si2 == 0 ? si1 : si1 % si2;
}
int16_t safe_lshift_func_int16_t_s_s(int16_t left, int right) { return left; }
int32_t safe_add_func_int32_t_s_s(int32_t si1, int32_t si2) {
  return si1 && si2 && si1 > 2147483647 - si2 || si1 < 0 && si2 < 0 && si1
             ? si1
             : si1 + si2;
}
int8_t g_7;
uint32_t g_129;
uint8_t g_176;
static uint32_t g_244 = 0x01B28DB7L;
int32_t g_1920;
int32_t func_2(int8_t, uint8_t, uint32_t);
uint16_t func_39(int8_t);
uint16_t func_1() {
  int16_t l_6 = 0L;
  if (func_2(l_6, g_7, l_6)) {
  }
  return g_1920;
}
int32_t func_2(int8_t p_3, uint8_t p_4, uint32_t p_5) {
  if (func_39(g_7)) {
  }
  return p_4;
}
uint16_t func_39(p_40) {
  for (; g_176 < 12; g_176 = safe_add_func_int32_t_s_s(g_176, 3)) {
    int32_t l_220;
    if (0x4F92L <
        safe_lshift_func_int16_t_s_s(
            g_244 | (l_220 = safe_mod_func_int8_t_s_s(p_40, p_40)), 6)) {
    } else {
      int8_t l_319 = 0xE3L;
      if (p_40 <= l_319)
        ;
      else if (l_220)
        break;
    }
  }
  return g_129;
}
int main() { func_1(); }

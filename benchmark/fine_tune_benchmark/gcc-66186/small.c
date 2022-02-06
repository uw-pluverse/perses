typedef signed int8_t;
typedef short int16_t;
typedef int int32_t;
typedef unsigned uint8_t;
typedef unsigned short uint16_t;
typedef unsigned uint32_t;
int32_t g_2;
int32_t g_1600;
int32_t func_8(uint16_t, uint8_t, uint16_t);
uint16_t func_55(int8_t, uint16_t, uint32_t);
int16_t func_89(int8_t, int8_t, int8_t, uint16_t, int32_t);
uint32_t func_97(int32_t, uint16_t, uint16_t, uint32_t, uint16_t);
int32_t func_1() {
  int32_t l_14 = 1L;
  uint32_t l_2413 = 0x5A683F60L;
  func_8(l_14, g_2, g_2);
  return l_2413;
}
int32_t func_8(uint16_t p_9, uint8_t p_10, uint16_t p_11) {
  int32_t l_45 = 0x57638FF4L;
  int32_t l_2211 = 1L;
  func_55(g_2, l_45, g_2);
  return l_2211;
}
uint16_t func_55(int8_t p_56, uint16_t p_57, uint32_t p_58) {
  uint32_t l_72 = 0x30A04A8FL;
  if (func_89(0x9A5DL, g_2, p_57, l_72, p_56))
    ;
  return 0;
}
int16_t func_89(int8_t p_90, int8_t p_91, int8_t p_92, uint16_t p_93,
                int32_t p_94) {
  int32_t l_103 = -7L;
  int8_t l_267 = 0xA3L;
  if (func_97(l_103, 4294967287UL, l_103, g_2, p_94)) {
  }
  return l_267;
}
uint32_t func_97(int32_t p_98, uint16_t p_99, uint16_t p_100, uint32_t p_101,
                 uint16_t p_102) {
  int16_t l_125[8];
  for (p_99 = 0; p_99 <= 7; p_99 += 1)
    for (p_101 = 0; p_101 <= 7; p_101 += 1)
      if (g_1600 < 0)
        for (p_101 = 0; p_101 <= 7; p_101 += 1)
          if (l_125[p_100])
            break;
  return g_2;
}
int main() { func_1(); }

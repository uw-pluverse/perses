typedef short int16_t;
typedef int int32_t;
typedef long int64_t;
typedef unsigned char uint8_t;
typedef short uint16_t;
typedef unsigned uint32_t;
typedef unsigned uint64_t;
void platform_main_end(uint32_t crc, int flag) {
  printf("checksum = %X\n", crc);
}
int32_t safe_sub_func_int32_t_s_s(int32_t si1, int32_t si2) {
  return si1 - si2;
}
int64_t safe_sub_func_int64_t_s_s(int64_t si1, int64_t si2) {
  return si1 - si2;
}
uint8_t safe_sub_func_uint8_t_u_u(uint8_t ui1, uint8_t ui2) { return ui1; }
uint32_t safe_add_func_uint32_t_u_u(uint32_t ui1, uint32_t ui2) { return ui2; }
uint32_t safe_sub_func_uint32_t_u_u(uint32_t ui1, uint32_t ui2) {
  return ui1 - ui2;
}
uint32_t crc32_context;
void crc32_byte(b) { crc32_context = b; }
void crc32_8bytes(val) { crc32_byte(val); }
void transparent_crc(uint64_t val, char *vname, int flag) { crc32_8bytes(val); }
int32_t g_3;
uint32_t g_4;
int64_t g_170;
int16_t g_332;
uint32_t g_836;
int16_t g_877 = 1L;
uint8_t func_13(uint64_t, uint16_t);
uint8_t func_26(uint8_t, uint32_t, int32_t, uint16_t);
int16_t func_39(int32_t, int32_t, uint8_t, int16_t, uint64_t);
int32_t func_1() {
  uint16_t l_3032 = 1UL;
  func_13(g_4, g_3);
  return l_3032;
}
uint8_t func_13(uint64_t p_14, uint16_t p_15) {
  int32_t l_1829 = 0x2F2F6D26L;
  uint8_t l_25 = 248UL;
  func_26(2L, l_25, p_15, 1);
  return l_1829;
}
uint8_t func_26(uint8_t p_27, uint32_t p_28, int32_t p_29, uint16_t p_30) {
  int64_t l_38 = 7L;
  uint16_t l_1827 = 1UL;
  func_39(l_38, l_38, p_27, 0, p_27);
  return l_1827;
}
int16_t func_39(int32_t p_40, int32_t p_41, uint8_t p_42, int16_t p_43,
                uint64_t p_44) {
  int32_t l_1146 = 3L;
  int64_t l_1165 = 1L;
  int32_t l_1166;
  for (g_332 = 3; g_332; g_332 -= 1)
    if (l_1166 = 250UL) {
      p_41 = safe_add_func_uint32_t_u_u(g_836, g_877) ||
             (l_1166 = g_332) == 0x294A85636008822DLL;
      int16_t l_1196 = 0xBCD1L;
      if (safe_sub_func_int32_t_s_s(
              safe_sub_func_int64_t_s_s(
                  l_1196,
                  safe_sub_func_uint8_t_u_u(
                      safe_sub_func_uint32_t_u_u(l_1165, l_1166), 0xECL)),
              p_41) &
          1UL)
        g_170 = 1UL;
    }
  return l_1146;
}
int main() {
  int print_hash_value = 0;
  func_1();
  transparent_crc(g_170, "g_170", print_hash_value);
  platform_main_end(crc32_context, print_hash_value);
  return 0;
}

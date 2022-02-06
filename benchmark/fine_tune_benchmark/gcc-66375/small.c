typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef unsigned uint8_t;
typedef unsigned uint32_t;
typedef unsigned uint64_t;
void platform_main_end(uint32_t crc, int flag) {
  printf("checksum = %X\n", crc);
}
int8_t safe_rshift_func_int8_t_s_s(int8_t left, int right) { return left; }
int16_t safe_add_func_int16_t_s_s(int16_t si1, int16_t si2) { return si2; }
uint64_t safe_add_func_uint64_t_u_u(uint64_t ui1, uint64_t ui2) {
  return ui1 + ui2;
}
uint32_t crc32_context;
void crc32_byte(b) { crc32_context = b; }
void crc32_8bytes(val) { crc32_byte(val); }
void transparent_crc(uint64_t val, char *vname, int flag) { crc32_8bytes(val); }
uint32_t g_15;
uint64_t g_163;
uint64_t g_1729[1][4];
uint8_t func_12(int8_t, int32_t);
uint64_t func_22(uint32_t, uint32_t, int32_t, uint64_t, int32_t);
int32_t func_32(int32_t, uint8_t, uint32_t, int32_t);
int16_t func_1() {
  int8_t l_16 = 0xFBL;
  int32_t l_3555 = 0L;
  func_12(g_15, l_16);
  return l_3555;
}
uint8_t func_12(int8_t p_13, int32_t p_14) {
  func_22(p_14, p_14, g_15, 18446744073709551613UL, g_15);
  return p_13;
}
uint64_t func_22(uint32_t p_23, uint32_t p_24, int32_t p_25, uint64_t p_26,
                 int32_t p_27) {
  uint8_t l_43 = 255UL;
  func_32(6, l_43, 1, p_23);
  return p_24;
}
int32_t func_32(int32_t p_33, uint8_t p_34, uint32_t p_35, int32_t p_36) {
  int32_t l_2124 = 2L;
  for (; g_163 < 51; ++g_163) {
    uint64_t l_2150[9];
    int i;
    for (i = 0; i < 9; i++)
      l_2150[i] = 0x9EE7F9D1C772505BLL;
    l_2124 = safe_add_func_uint64_t_u_u(
        safe_rshift_func_int8_t_s_s(
            g_1729[0][3] = safe_add_func_int16_t_s_s(4L, l_2124), 3),
        l_2150[0]);
  }
  return 3;
}
int main() {
  int i, j;
  int print_hash_value = 0;
  func_1();
  for (i = 0; i < 1; i++)
    for (j = 0; j < 4; j++)
      transparent_crc(g_1729[i][j], "g_1729[i][j]", print_hash_value);
  platform_main_end(crc32_context, print_hash_value);
  return 0;
}

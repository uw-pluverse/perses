typedef signed int8_t;
typedef short int16_t;
typedef int int32_t;
typedef unsigned uint8_t;
typedef unsigned uint16_t;
typedef unsigned uint32_t;
void platform_main_end(uint32_t crc, int flag) {
  printf("checksum = %X\n", crc);
}
int8_t safe_sub_func_int8_t_s_s(int8_t si1, int8_t si2) { return si1; }
int16_t safe_mul_func_int16_t_s_s(int16_t si1, int16_t si2) { return si1; }
int32_t safe_mod_func_int32_t_s_s(int32_t si1, int32_t si2) {
  return si1 % si2;
}
uint8_t safe_add_func_uint8_t_u_u(uint8_t ui1, uint8_t ui2) { return ui1; }
uint32_t crc32_context;
void crc32_byte(b) { crc32_context = crc32_context ^ b; }
void crc32_8bytes(val) { crc32_byte(val); }
void transparent_crc(uint32_t val, char *vname, int flag) { crc32_8bytes(val); }
uint8_t g_148;
int32_t g_375;
static uint8_t g_613 = 254U;
int8_t g_643[7][5][7] = {{8}, {8}, {{8}, 0x98}};
int16_t g_738;
int32_t g_1419;
int8_t func_1() {
  uint16_t l_1557 = 3U;
  int32_t l_1565[2];
  int i;
  for (i = 0; i < 2; i++)
    l_1565[i] = 8;
  for (g_613 = 1;;) {
    for (; i < 5; i++)
      ;
    for (g_1419 = 6; g_1419 >= 0; g_1419 -= 1)
      g_375 = l_1565[0] ^= g_643[g_613 + 1][g_613][g_1419] =
          safe_mod_func_int32_t_s_s(
              safe_mul_func_int16_t_s_s(
                  1, safe_add_func_uint8_t_u_u(
                         255U, safe_sub_func_int8_t_s_s(l_1557, g_148--))),
              4294967295U);
    return g_738;
  }
}
int main() {
  int i, j, k;
  int print_hash_value = 0;
  func_1();
  for (i = 0; i < 7; i++)
    for (j = 0; j < 5; j++)
      for (k = 0; k < 7; k++)
        transparent_crc(g_643[i][j][k], "g_643[i][j][k]", print_hash_value);
  platform_main_end(crc32_context, print_hash_value);
  return 0;
}

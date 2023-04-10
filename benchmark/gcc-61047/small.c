typedef unsigned int size_t;
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long long int int64_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;
int printf(const char *, ...);
void __assert_fail(const char *__assertion, const char *__file,
                   unsigned int __line, const char *__function);
static void platform_main_end(uint32_t crc, int flag) {
  printf("checksum = %X\n", crc);
}
static int8_t(safe_unary_minus_func_int8_t_s)(int8_t si) { return -si; }
static int8_t(safe_add_func_int8_t_s_s)(int8_t si1, int8_t si2) {
  return (si1 + si2);
}
static int8_t(safe_sub_func_int8_t_s_s)(int8_t si1, int8_t si2) {
  return (si1 - si2);
}
static int8_t(safe_mul_func_int8_t_s_s)(int8_t si1, int8_t si2) {
  return si1 * si2;
}
static int8_t(safe_mod_func_int8_t_s_s)(int8_t si1, int8_t si2) {
  return ((si2 == 0) || ((si1 == (-128)) && (si2 == (-1)))) ? ((si1))
                                                            : (si1 % si2);
}
static int8_t(safe_div_func_int8_t_s_s)(int8_t si1, int8_t si2) {
  return ((si2 == 0) || ((si1 == (-128)) && (si2 == (-1)))) ? ((si1))
                                                            : (si1 / si2);
}
static int8_t(safe_lshift_func_int8_t_s_s)(int8_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((127) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static int8_t(safe_lshift_func_int8_t_s_u)(int8_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32) ||
          (left > ((127) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static int8_t(safe_rshift_func_int8_t_s_s)(int8_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
             ? ((left))
             : (left >> ((int)right));
}
static int8_t(safe_rshift_func_int8_t_s_u)(int8_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32))
             ? ((left))
             : (left >> ((unsigned int)right));
}
static int16_t(safe_unary_minus_func_int16_t_s)(int16_t si) { return -si; }
static int16_t(safe_add_func_int16_t_s_s)(int16_t si1, int16_t si2) {
  return (si1 + si2);
}
static int16_t(safe_sub_func_int16_t_s_s)(int16_t si1, int16_t si2) {
  return (si1 - si2);
}
static int16_t(safe_mul_func_int16_t_s_s)(int16_t si1, int16_t si2) {
  return si1 * si2;
}
static int16_t(safe_mod_func_int16_t_s_s)(int16_t si1, int16_t si2) {
  return ((si2 == 0) || ((si1 == (-32767 - 1)) && (si2 == (-1)))) ? ((si1))
                                                                  : (si1 % si2);
}
static int16_t(safe_div_func_int16_t_s_s)(int16_t si1, int16_t si2) {
  return ((si2 == 0) || ((si1 == (-32767 - 1)) && (si2 == (-1)))) ? ((si1))
                                                                  : (si1 / si2);
}
static int16_t(safe_lshift_func_int16_t_s_s)(int16_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((32767) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static int16_t(safe_lshift_func_int16_t_s_u)(int16_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32) ||
          (left > ((32767) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static int16_t(safe_rshift_func_int16_t_s_s)(int16_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
             ? ((left))
             : (left >> ((int)right));
}
static int16_t(safe_rshift_func_int16_t_s_u)(int16_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32))
             ? ((left))
             : (left >> ((unsigned int)right));
}
static int32_t(safe_unary_minus_func_int32_t_s)(int32_t si) {
  return (si == (-2147483647 - 1)) ? ((si)) : -si;
}
static int32_t(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2) {
  return (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) - si2))) ||
          ((si1 < 0) && (si2 < 0) && (si1 < ((-2147483647 - 1) - si2))))
             ? ((si1))
             : (si1 + si2);
}
static int32_t(safe_sub_func_int32_t_s_s)(int32_t si1, int32_t si2) {
  return (((si1 ^ si2) &
           (((si1 ^ ((si1 ^ si2) & (~(2147483647)))) - si2) ^ si2)) < 0)
             ? ((si1))
             : (si1 - si2);
}
static int32_t(safe_mul_func_int32_t_s_s)(int32_t si1, int32_t si2) {
  return (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) / si2))) ||
          ((si1 > 0) && (si2 <= 0) && (si2 < ((-2147483647 - 1) / si1))) ||
          ((si1 <= 0) && (si2 > 0) && (si1 < ((-2147483647 - 1) / si2))) ||
          ((si1 <= 0) && (si2 <= 0) && (si1 != 0) &&
           (si2 < ((2147483647) / si1))))
             ? ((si1))
             : si1 * si2;
}
static int32_t(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2) {
  return ((si2 == 0) || ((si1 == (-2147483647 - 1)) && (si2 == (-1))))
             ? ((si1))
             : (si1 % si2);
}
static int32_t(safe_div_func_int32_t_s_s)(int32_t si1, int32_t si2) {
  return ((si2 == 0) || ((si1 == (-2147483647 - 1)) && (si2 == (-1))))
             ? ((si1))
             : (si1 / si2);
}
static int32_t(safe_lshift_func_int32_t_s_s)(int32_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((2147483647) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static int32_t(safe_lshift_func_int32_t_s_u)(int32_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32) ||
          (left > ((2147483647) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static int32_t(safe_rshift_func_int32_t_s_s)(int32_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
             ? ((left))
             : (left >> ((int)right));
}
static int32_t(safe_rshift_func_int32_t_s_u)(int32_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32))
             ? ((left))
             : (left >> ((unsigned int)right));
}
static uint8_t(safe_unary_minus_func_uint8_t_u)(uint8_t ui) { return -ui; }
static uint8_t(safe_add_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {
  return ui1 + ui2;
}
static uint8_t(safe_sub_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {
  return ui1 - ui2;
}
static uint8_t(safe_mul_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {
  return ((unsigned int)ui1) * ((unsigned int)ui2);
}
static uint8_t(safe_mod_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 % ui2);
}
static uint8_t(safe_div_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 / ui2);
}
static uint8_t(safe_lshift_func_uint8_t_u_s)(uint8_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((255) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static uint8_t(safe_lshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {
  return ((((unsigned int)right) >= 32) ||
          (left > ((255) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static uint8_t(safe_rshift_func_uint8_t_u_s)(uint8_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32)) ? ((left))
                                                      : (left >> ((int)right));
}
static uint8_t(safe_rshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {
  return (((unsigned int)right) >= 32) ? ((left))
                                       : (left >> ((unsigned int)right));
}
static uint16_t(safe_unary_minus_func_uint16_t_u)(uint16_t ui) { return -ui; }
static uint16_t(safe_add_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {
  return ui1 + ui2;
}
static uint16_t(safe_sub_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {
  return ui1 - ui2;
}
static uint16_t(safe_mul_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {
  return ((unsigned int)ui1) * ((unsigned int)ui2);
}
static uint16_t(safe_mod_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 % ui2);
}
static uint16_t(safe_div_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 / ui2);
}
static uint16_t(safe_lshift_func_uint16_t_u_s)(uint16_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((65535) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static uint16_t(safe_lshift_func_uint16_t_u_u)(uint16_t left,
                                               unsigned int right) {
  return ((((unsigned int)right) >= 32) ||
          (left > ((65535) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static uint16_t(safe_rshift_func_uint16_t_u_s)(uint16_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32)) ? ((left))
                                                      : (left >> ((int)right));
}
static uint16_t(safe_rshift_func_uint16_t_u_u)(uint16_t left,
                                               unsigned int right) {
  return (((unsigned int)right) >= 32) ? ((left))
                                       : (left >> ((unsigned int)right));
}
static uint32_t(safe_unary_minus_func_uint32_t_u)(uint32_t ui) { return -ui; }
static uint32_t(safe_add_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {
  return ui1 + ui2;
}
static uint32_t(safe_sub_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {
  return ui1 - ui2;
}
static uint32_t(safe_mul_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {
  return ((unsigned int)ui1) * ((unsigned int)ui2);
}
static uint32_t(safe_mod_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 % ui2);
}
static uint32_t(safe_div_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 / ui2);
}
static uint32_t(safe_lshift_func_uint32_t_u_s)(uint32_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((4294967295U) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static uint32_t(safe_lshift_func_uint32_t_u_u)(uint32_t left,
                                               unsigned int right) {
  return ((((unsigned int)right) >= 32) ||
          (left > ((4294967295U) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static uint32_t(safe_rshift_func_uint32_t_u_s)(uint32_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32)) ? ((left))
                                                      : (left >> ((int)right));
}
static uint32_t(safe_rshift_func_uint32_t_u_u)(uint32_t left,
                                               unsigned int right) {
  return (((unsigned int)right) >= 32) ? ((left))
                                       : (left >> ((unsigned int)right));
}
static uint32_t crc32_tab[256];
static uint32_t crc32_context = 0xFFFFFFFFUL;
static void crc32_gentab(void) {
  uint32_t crc;
  const uint32_t poly = 0xEDB88320UL;
  int i, j;
  for (i = 0; i < 256; i++) {
    crc = i;
    for (j = 8; j > 0; j--) {
      if (crc & 1) {
        crc = (crc >> 1) ^ poly;
      } else {
        crc >>= 1;
      }
    }
    crc32_tab[i] = crc;
  }
}
static void crc32_byte(uint8_t b) {
  crc32_context = ((crc32_context >> 8) & 0x00FFFFFF) ^
                  crc32_tab[(crc32_context ^ b) & 0xFF];
}
static void crc32_8bytes(uint32_t val) {
  crc32_byte((val >> 0) & 0xff);
  crc32_byte((val >> 8) & 0xff);
  crc32_byte((val >> 16) & 0xff);
  crc32_byte((val >> 24) & 0xff);
}
static void transparent_crc(uint32_t val, char *vname, int flag) {
  crc32_8bytes(val);
  if (flag) {
    printf("...checksum after hashing %s : %X\n", vname,
           crc32_context ^ 0xFFFFFFFFU);
  }
}
static long __undefined;
static const int16_t g_4 = (-6L);
static int32_t g_6 = 0L;
static int16_t g_8 = (-1L);
static int16_t g_9 = 6L;
static int32_t g_10 = 0x4C90D297L;
static uint16_t g_11 = 0x471DL;
static uint16_t g_58 = 0x1CEAL;
static uint32_t g_148 = 0xE05CF484L;
static int32_t g_252 = 0xFD24D6F2L;
static int32_t g_485 = 0xFDB362B9L;
static uint32_t g_515 = 0xAA8C972FL;
static int32_t g_592 = (-1L);
static int32_t g_593[3][4][6] = {
    {{0xFCD62227L, 0xFA6E450DL, 0xFA6E450DL, 0xFCD62227L, 0xA970CF09L, (-5L)},
     {0xFCD62227L, 0xFA6E450DL, 0xFA6E450DL, 0xFCD62227L, 0xA970CF09L, (-5L)},
     {0xFCD62227L, 0xFA6E450DL, 0xFA6E450DL, 0xFCD62227L, 0xA970CF09L, (-5L)},
     {0xFCD62227L, 0xFA6E450DL, 0xFA6E450DL, 0xFCD62227L, 0xA970CF09L, (-5L)}},
    {{0xFCD62227L, 0xFA6E450DL, 0xFA6E450DL, 0xFCD62227L, 0xA970CF09L, (-5L)},
     {0xFCD62227L, 0xFA6E450DL, 0xFA6E450DL, 0xFCD62227L, 0xA970CF09L, (-5L)},
     {0xFCD62227L, 0xFA6E450DL, 0xFA6E450DL, 0xFCD62227L, 0xA970CF09L, (-5L)},
     {0xFCD62227L, 0xFA6E450DL, 0xFA6E450DL, 0xFCD62227L, 0xA970CF09L, (-5L)}},
    {{0xFCD62227L, 0xFA6E450DL, 0xFA6E450DL, 0xFCD62227L, 0xA970CF09L, (-5L)},
     {0xFCD62227L, 0xFA6E450DL, 0xFA6E450DL, 0xFCD62227L, 0xA970CF09L, (-5L)},
     {0xFCD62227L, 0xFA6E450DL, 0xFA6E450DL, 0xFCD62227L, 0xA970CF09L, (-5L)},
     {0xFCD62227L, 0xFA6E450DL, 0xFA6E450DL, 0xFCD62227L, 0xA970CF09L, (-5L)}}};
static int32_t g_677 = 9L;
static const int16_t g_806 = 0xD1DDL;
static uint32_t g_878[1][5][7] = {
    {{0xE8095E9CL, 0xFED73685L, 0xE8095E9CL, 0xFED73685L, 0xE8095E9CL,
      0xFED73685L, 0xE8095E9CL},
     {0xE8095E9CL, 0xFED73685L, 0xE8095E9CL, 0xFED73685L, 0xE8095E9CL,
      0xFED73685L, 0xE8095E9CL},
     {0xE8095E9CL, 0xFED73685L, 0xE8095E9CL, 0xFED73685L, 0xE8095E9CL,
      0xFED73685L, 0xE8095E9CL},
     {0xE8095E9CL, 0xFED73685L, 0xE8095E9CL, 0xFED73685L, 0xE8095E9CL,
      0xFED73685L, 0xE8095E9CL},
     {0xE8095E9CL, 0xFED73685L, 0xE8095E9CL, 0xFED73685L, 0xE8095E9CL,
      0xFED73685L, 0xE8095E9CL}}};
static int32_t g_1220 = (-3L);
static uint8_t g_1565 = 0xB8L;
static int16_t func_1(void);
static int32_t func_2(const uint32_t p_3);
static uint32_t func_14(uint8_t p_15, uint32_t p_16, uint16_t p_17);
static int32_t func_20(int16_t p_21);
static uint16_t func_27(int32_t p_28, int8_t p_29);
static uint32_t func_30(uint32_t p_31, uint8_t p_32);
static const uint32_t func_37(uint32_t p_38, int16_t p_39, int16_t p_40,
                              int16_t p_41, int32_t p_42);
static uint16_t func_45(uint16_t p_46, int32_t p_47, const int8_t p_48,
                        const int8_t p_49);
static int8_t func_50(int32_t p_51, uint8_t p_52, uint32_t p_53, int32_t p_54,
                      const uint32_t p_55);
static int32_t func_62(const uint8_t p_63, int32_t p_64);
static int16_t func_1(void) {
  uint32_t l_1222[10] = {2UL, 0x3B0DC92AL, 2UL, 0x3B0DC92AL, 2UL, 0x3B0DC92AL,
                         2UL, 0x3B0DC92AL, 2UL, 0x3B0DC92AL};
  int32_t l_1229[2][10] = {
      {0x8EF79923L, 0xD4C23B76L, 0x8EF79923L, 0xD4C23B76L, 0x8EF79923L,
       0xD4C23B76L, 0x8EF79923L, 0xD4C23B76L, 0x8EF79923L, 0xD4C23B76L},
      {0x8EF79923L, 0xD4C23B76L, 0x8EF79923L, 0xD4C23B76L, 0x8EF79923L,
       0xD4C23B76L, 0x8EF79923L, 0xD4C23B76L, 0x8EF79923L, 0xD4C23B76L}};
  int32_t l_1269 = 1L;
  const uint32_t l_1354 = 0xC482E747L;
  uint32_t l_1380 = 4UL;
  int8_t l_1384[8] = {0xC6L, 1L, 0xC6L, 1L, 0xC6L, 1L, 0xC6L, 1L};
  int16_t l_1412 = 7L;
  const uint16_t l_1428 = 0xCD6BL;
  const uint16_t l_1528 = 65534UL;
  uint8_t l_1568 = 0x78L;
  int32_t l_1612[5] = {0xBE38E7E2L, 0x244946D6L, 0xBE38E7E2L, 0x244946D6L,
                       0xBE38E7E2L};
  int i, j;
  l_1222[0] = func_2(g_4);
  for (g_677 = 15; (g_677 == 10); g_677 = safe_sub_func_int8_t_s_s(g_677, 2)) {
    int16_t l_1227 = 0x5C3AL;
    int32_t l_1228 = (-1L);
    l_1228 = ((safe_rshift_func_int8_t_s_u(l_1227, 2)) && 0x13L);
  }
  for (g_1220 = 0; (g_1220 >= 0); g_1220 -= 1) {
    uint16_t l_1230[7] = {0xD568L, 1UL, 0xD568L, 1UL, 0xD568L, 1UL, 0xD568L};
    const uint16_t l_1249[1][8] = {
        {3UL, 3UL, 65527UL, 3UL, 3UL, 65527UL, 3UL, 3UL}};
    uint32_t l_1278 = 0UL;
    const int32_t l_1295 = 1L;
    int32_t l_1313 = 0L;
    int16_t l_1355 = 0xE44FL;
    int32_t l_1357 = (-3L);
    uint8_t l_1362[6] = {0UL, 0UL, 1UL, 0UL, 0UL, 1UL};
    int16_t l_1446 = (-1L);
    int32_t l_1521 = 0x59AE342CL;
    int16_t l_1558 = 0xA483L;
    int32_t l_1566[6] = {1L, (-3L), 1L, (-3L), 1L, (-3L)};
    uint32_t l_1599 = 0UL;
    int32_t l_1611 = 4L;
    int i, j;
    l_1230[1]++;
    if ((((l_1229[1][9] <
           ((safe_add_func_int32_t_s_s(
                (0x83DAL >
                 ((((1L <=
                     (((((safe_mod_func_uint32_t_u_u(
                             (safe_mod_func_uint32_t_u_u(
                                 ((safe_add_func_int8_t_s_s(
                                      g_4,
                                      (g_252 <
                                       ((!(safe_mul_func_uint16_t_u_u(
                                            (l_1229[1][9] ||
                                             (safe_rshift_func_int8_t_s_s(
                                                 (safe_mul_func_int8_t_s_s(
                                                     g_148,
                                                     ((((((safe_rshift_func_int8_t_s_u(
                                                              7L, l_1230[1])) >
                                                          l_1222[0]),
                                                         (-1L)) <=
                                                        g_593[1][1][4]) ^
                                                       0x392CA8A1L),
                                                      0xBEL))),
                                                 6))),
                                            0x87FBL))),
                                        g_677)))) ^
                                  g_6),
                                 l_1249[0][1])),
                             l_1222[0])) &&
                         0UL) < 4294967291UL) ^
                       g_592) <= (-4L))) > 0x1AEA13B1L) ||
                   0x0BL),
                  l_1229[1][1])),
                l_1230[3])),
            g_878[0][1][0])),
          l_1229[1][9]) > l_1229[1][9])) {
      uint32_t l_1254[7];
      int32_t l_1260 = 0xB86278AFL;
      int32_t l_1330 = (-5L);
      int32_t l_1358 = 0xAB7F0D64L;
      int32_t l_1359 = 1L;
      int32_t l_1360 = 0x5A3D0EE6L;
      int32_t l_1361[5][6] = {
          {0x441BD344L, 0x86F01D0AL, (-1L), 0x86F01D0AL, 0x441BD344L, 0L},
          {0x441BD344L, 0x86F01D0AL, (-1L), 0x86F01D0AL, 0x441BD344L, 0L},
          {0x441BD344L, 0x86F01D0AL, (-1L), 0x86F01D0AL, 0x441BD344L, 0L},
          {0x441BD344L, 0x86F01D0AL, (-1L), 0x86F01D0AL, 0x441BD344L, 0L},
          {0x441BD344L, 0x86F01D0AL, (-1L), 0x86F01D0AL, 0x441BD344L, 0L}};
      int32_t l_1383 = 1L;
      int i, j;
      for (i = 0; i < 7; i++)
        l_1254[i] = 0x05FC8492L;
      for (g_9 = 0; (g_9 >= 0); g_9 -= 1) {
        int16_t l_1257 = (-1L);
        uint32_t l_1272 = 0x384D2360L;
        int16_t l_1331 = 1L;
        int32_t l_1356 = 0xE9F73634L;
        int32_t l_1386[9][1][10] = {
            {{(-1L), (-3L), 0x2331A843L, 0x2AFF29B5L, 0xF945BCABL, 0L, 0L,
              0x9595B7EDL, 0x0D6153DCL, 8L}},
            {{(-1L), (-3L), 0x2331A843L, 0x2AFF29B5L, 0xF945BCABL, 0L, 0L,
              0x9595B7EDL, 0x0D6153DCL, 8L}},
            {{(-1L), (-3L), 0x2331A843L, 0x2AFF29B5L, 0xF945BCABL, 0L, 0L,
              0x9595B7EDL, 0x0D6153DCL, 8L}},
            {{(-1L), (-3L), 0x2331A843L, 0x2AFF29B5L, 0xF945BCABL, 0L, 0L,
              0x9595B7EDL, 0x0D6153DCL, 8L}},
            {{(-1L), (-3L), 0x2331A843L, 0x2AFF29B5L, 0xF945BCABL, 0L, 0L,
              0x9595B7EDL, 0x0D6153DCL, 8L}},
            {{(-1L), (-3L), 0x2331A843L, 0x2AFF29B5L, 0xF945BCABL, 0L, 0L,
              0x9595B7EDL, 0x0D6153DCL, 8L}},
            {{(-1L), (-3L), 0x2331A843L, 0x2AFF29B5L, 0xF945BCABL, 0L, 0L,
              0x9595B7EDL, 0x0D6153DCL, 8L}},
            {{(-1L), (-3L), 0x2331A843L, 0x2AFF29B5L, 0xF945BCABL, 0L, 0L,
              0x9595B7EDL, 0x0D6153DCL, 8L}},
            {{(-1L), (-3L), 0x2331A843L, 0x2AFF29B5L, 0xF945BCABL, 0L, 0L,
              0x9595B7EDL, 0x0D6153DCL, 8L}}};
        int i, j, k;
        l_1260 =
            ((safe_lshift_func_uint8_t_u_u(
                 (((safe_lshift_func_int8_t_s_u(
                       (g_515 & ((0x9432BD24L != l_1254[2]),
                                 (safe_lshift_func_int16_t_s_u(l_1257, 3)))),
                       2)) |
                   (0x53D3E266L != 0x071EE425L)),
                  ((safe_sub_func_uint32_t_u_u(
                       (((0xDCA6L != l_1254[1]) & (~0L)) ^ l_1257),
                       l_1249[0][1])) |
                   l_1257)),
                 l_1254[2])) <= 0xA9719400L);
        for (g_677 = 0; (g_677 >= 0); g_677 -= 1) {
          uint16_t l_1273[5] = {0xE25DL, 0UL, 0xE25DL, 0UL, 0xE25DL};
          int32_t l_1296[5][7] = {
              {0x6D1B9171L, 0L, 8L, 0x424A6F05L, 0L, 0L, 0L},
              {0x6D1B9171L, 0L, 8L, 0x424A6F05L, 0L, 0L, 0L},
              {0x6D1B9171L, 0L, 8L, 0x424A6F05L, 0L, 0L, 0L},
              {0x6D1B9171L, 0L, 8L, 0x424A6F05L, 0L, 0L, 0L},
              {0x6D1B9171L, 0L, 8L, 0x424A6F05L, 0L, 0L, 0L}};
          int i, j;
          for (g_10 = 2; (g_10 >= 0); g_10 -= 1) {
            int i, j, k;
            g_593[g_9][g_10][(g_677 + 1)] =
                (((((safe_sub_func_int16_t_s_s(
                        ((((safe_mul_func_int16_t_s_s(
                               (((((g_878[g_677][(g_9 + 3)][(g_1220 + 6)] ||
                                    (g_593[g_10][(g_1220 + 1)][(g_677 + 4)] >
                                     (((((((((((safe_rshift_func_int16_t_s_u(
                                                   ((((safe_mul_func_int16_t_s_s(
                                                          (-5L),
                                                          l_1254[(g_677 + 1)])),
                                                      g_677) ^
                                                     (+(((((l_1269 ^
                                                            (l_1222[0] &
                                                             (safe_mod_func_uint32_t_u_u(
                                                                 (((g_4 >
                                                                    0xBB10L),
                                                                   l_1257) ==
                                                                  3UL),
                                                                 4294967289UL)))) &
                                                           9UL),
                                                          g_1220) >=
                                                         0xDA9B1169L),
                                                        g_252))) <= 9L),
                                                   g_1220)) >=
                                               g_593[g_10][(g_1220 + 1)]
                                                    [(g_677 + 4)]),
                                              0xB66CL) &&
                                             g_878[g_677][(g_9 + 3)]
                                                  [(g_1220 + 6)]),
                                            l_1230[4]) &
                                           2UL) |
                                          g_806) != g_593[0][3][0]) >
                                        l_1230[1]) >= g_9) &&
                                      g_6))) <= 0xDA22L) |
                                  0xC3F2L) >= l_1249[0][5]),
                                (-2L)),
                               g_485)) ||
                           l_1260) &&
                          g_677) >= l_1272),
                        g_593[0][3][0])),
                    l_1273[1]) >= l_1249[0][7]),
                  g_8) &&
                 g_592);
            g_485 =
                ((-1L) &
                 ((safe_sub_func_int32_t_s_s(
                      ((0x029BL !=
                        ((~l_1230[3]) && (safe_lshift_func_int16_t_s_s(
                                             (l_1278 > g_593[0][3][0]), 1)))) ^
                       g_9),
                      (safe_lshift_func_uint16_t_u_s(
                          (safe_lshift_func_int16_t_s_u(l_1254[2], 15)), 0)))) |
                  g_6));
            g_6 = l_1272;
          }
          for (g_592 = 0; (g_592 >= 0); g_592 -= 1) {
            int i, j, k;
            l_1296[0][5] &= (safe_sub_func_uint16_t_u_u(
                (safe_rshift_func_int16_t_s_s(
                    ((0x90E2DA55L && g_878[g_9][(g_1220 + 1)][(g_9 + 3)]),
                     ((safe_add_func_int16_t_s_s(
                          (1UL ==
                           ((safe_sub_func_uint32_t_u_u(
                                (g_593[g_677][(g_1220 + 2)][(g_9 + 2)],
                                 l_1273[1]),
                                (safe_lshift_func_uint8_t_u_s(
                                    (safe_sub_func_uint16_t_u_u(
                                        ((((((0xB7L <=
                                              (l_1272 !=
                                               (g_485 == g_878[0][0][1]))) ^
                                             0x8D21L) <= l_1295) &&
                                           1L) ||
                                          (-1L)) > l_1273[2]),
                                        g_9)),
                                    0)))) > (-1L))),
                          0UL)) > g_252)),
                    5)),
                0xFD3DL));
            if (g_878[0][0][1])
              break;
            l_1313 = (safe_rshift_func_int16_t_s_u(
                ((safe_mul_func_uint8_t_u_u(
                     (safe_sub_func_uint16_t_u_u(
                         ((safe_lshift_func_uint16_t_u_s(
                              (0x2A85133BL ==
                               ((safe_sub_func_int8_t_s_s(
                                    l_1273[2],
                                    (((((safe_lshift_func_uint8_t_u_s(
                                            ((((0xC8F71E00L <=
                                                ((((safe_mod_func_int8_t_s_s(
                                                       (g_878[g_9][(g_1220 + 1)]
                                                             [(g_9 + 3)] |
                                                        (6UL >=
                                                         (safe_mul_func_uint16_t_u_u(
                                                             g_252, 0x10ECL)))),
                                                       g_878[0][0][6])),
                                                   l_1222[0]) ^
                                                  g_485) != l_1229[1][8])) <
                                               0x3F88L) &
                                              g_58) <= l_1296[0][5]),
                                            5)) ^
                                        g_677) >= g_592) &
                                      g_878[g_9][(g_1220 + 1)][(g_9 + 3)]) &
                                     l_1229[1][9]))) ^
                                1UL)),
                              8)),
                          1UL),
                         0x33AFL)),
                     l_1296[0][5])) ^
                 l_1222[4]),
                g_593[(g_677 + 1)][(g_677 + 3)][(g_677 + 3)]));
          }
        }
        for (g_6 = 0; (g_6 > 22); g_6 = safe_add_func_uint16_t_u_u(g_6, 1)) {
          for (g_677 = (-13); (g_677 <= (-23)); --g_677) {
            int16_t l_1326 = 0x1500L;
            g_593[0][3][0] = (safe_add_func_uint16_t_u_u(
                (g_878[0][3][5] ^ g_1220),
                (+(((0L == g_485) ==
                    (safe_mul_func_int8_t_s_s(
                        (safe_mul_func_int8_t_s_s(
                            (safe_sub_func_int8_t_s_s(
                                l_1326,
                                ((safe_add_func_int16_t_s_s(
                                     (g_8 >= 0xC298L),
                                     (((((safe_unary_minus_func_int8_t_s(
                                             ((((l_1229[0][0] ^
                                                 ((-1L) == l_1272)) <= g_8) !=
                                               l_1330) ^
                                              g_6))) ^
                                         l_1229[0][4]),
                                        l_1326),
                                       0xD52FL) <= l_1331))) > l_1229[1][9]))),
                            g_1220)),
                        7L))) &&
                   l_1272))));
            return l_1326;
          }
        }
        if ((safe_add_func_int32_t_s_s(
                (safe_mod_func_int8_t_s_s(
                    (((((safe_lshift_func_uint8_t_u_u(
                            (safe_add_func_uint16_t_u_u(g_252, (-1L))), 5)) <
                        (safe_lshift_func_int16_t_s_s(
                            (safe_rshift_func_uint16_t_u_s(g_6, 1)),
                            ((safe_mul_func_int16_t_s_s(
                                 ((((safe_sub_func_int16_t_s_s(
                                        (safe_lshift_func_int16_t_s_s(
                                            (((l_1260,
                                               (safe_mul_func_uint16_t_u_u(
                                                   ((~g_806) |
                                                    ((4L |
                                                      (((l_1229[1][9] >=
                                                         g_515) >=
                                                        ((safe_mod_func_uint16_t_u_u(
                                                             (+(0x45L <=
                                                                0x9DL)),
                                                             l_1331)) !=
                                                         g_878[0][2][2])) <
                                                       0L)) < l_1354)),
                                                   g_593[0][3][0]))) !=
                                              g_878[0][0][1]),
                                             (-7L)),
                                            l_1260)),
                                        l_1331)) <= l_1355),
                                   0x5DL) &
                                  0x2DL),
                                 g_148)) < g_6)))),
                       (-6L)) ||
                      7UL) &
                     0x618E9F49L),
                    g_10)),
                l_1254[3]))) {
          for (l_1278 = 0; (l_1278 <= 6); l_1278 += 1) {
            int i;
            return l_1222[(g_1220 + 7)];
          }
          --l_1362[0];
        } else {
          uint8_t l_1387 = 0x23L;
          for (l_1257 = 2; (l_1257 > (-17)); --l_1257) {
            int8_t l_1367 = (-6L);
            int32_t l_1385 = 3L;
            l_1229[1][9] = 0x71738925L;
            l_1367 = (!0xBE2B69B6L);
            g_593[0][3][3] = (safe_sub_func_uint32_t_u_u(
                0xDA5CE296L,
                (safe_rshift_func_uint8_t_u_s(
                    (((g_593[0][3][0] !=
                       ((safe_rshift_func_uint8_t_u_u(
                            (255UL ==
                             (safe_mul_func_uint8_t_u_u(
                                 (safe_rshift_func_uint16_t_u_u(65534UL, 11)),
                                 (g_9 &&
                                  ((((g_593[0][1][5],
                                      (safe_mul_func_int16_t_s_s(
                                          l_1380, (((l_1362[3], l_1257), g_9) &
                                                   0L)))) > g_4) ||
                                    l_1367) != 0x5D22L))))),
                            7)),
                        l_1383)) ||
                      l_1383),
                     255UL),
                    g_677))));
            ++l_1387;
          }
          g_593[2][0][3] =
              ((((safe_rshift_func_uint8_t_u_u(
                     (0x05D1L &&
                      (((((l_1380 <=
                           (safe_rshift_func_uint16_t_u_s(
                               g_878[0][1][4],
                               (safe_add_func_int8_t_s_s(
                                   (safe_mul_func_uint8_t_u_u(
                                       (((safe_rshift_func_int8_t_s_s(
                                             ((+0x0C73B376L),
                                              (((safe_sub_func_int32_t_s_s(
                                                    (65535UL <=
                                                     ((((safe_lshift_func_int8_t_s_u(
                                                            0xD1L,
                                                            ((1L &&
                                                              ((safe_lshift_func_uint8_t_u_s(
                                                                   ((safe_lshift_func_int8_t_s_s(
                                                                        9L,
                                                                        7)) ==
                                                                    ((safe_mod_func_uint32_t_u_u(
                                                                         (safe_lshift_func_int8_t_s_u(
                                                                             (((0xB7C9L <
                                                                                1UL) &&
                                                                               4294967295UL) <=
                                                                              0x80FAFB48L),
                                                                             6)),
                                                                         0xCE22189EL)) <
                                                                     g_485)),
                                                                   g_252)) >
                                                               0xFBBDL)) ||
                                                             l_1412))) >
                                                        g_10) == (-7L)) ^
                                                      l_1260)),
                                                    l_1387)) &
                                                0xD89FL) <= l_1356)),
                                             l_1387)) < l_1412) &&
                                        l_1222[1]),
                                       g_8)),
                                   251UL))))) ^
                          l_1222[0]),
                         g_515) > g_593[0][3][0]),
                       l_1257)),
                     3)) < g_11) == 65528UL) == l_1272);
        }
      }
    } else {
      int8_t l_1415[9] = {0L, 0L, 0x6CL, 0L, 0L, 0x6CL, 0L, 0L, 0x6CL};
      int i;
      l_1415[1] = (safe_rshift_func_int16_t_s_u((3UL & l_1354), g_6));
      l_1269 = (0xCC6BL && g_878[0][3][5]);
    }
    if ((((safe_add_func_uint32_t_u_u(
              (safe_mul_func_int16_t_s_s(
                  ((safe_mul_func_uint16_t_u_u(
                       (+((safe_mul_func_int8_t_s_s(
                              (l_1354 !=
                               (safe_mod_func_uint8_t_u_u(
                                   (l_1222[7] |
                                    ((((((l_1412 >=
                                          (l_1412 >
                                           (safe_sub_func_int8_t_s_s(
                                               g_593[0][3][0],
                                               ((l_1230[4] >= (g_4 < g_11)) ==
                                                0x3B54L))))) > g_592),
                                        g_485) == 0xEF89L) < g_878[0][0][1]) <=
                                     l_1428)),
                                   g_10))),
                              0xF9L)) == (-1L))),
                       l_1384[2])) &
                   4294967289UL),
                  0xFF2BL)),
              g_4)),
          g_4) < 0xBFL)) {
      uint32_t l_1437 = 0x1D6388C9L;
      int32_t l_1552 = 0x33B29EE9L;
      const uint32_t l_1553 = 0x6A6F0B75L;
      l_1269 =
          ((safe_rshift_func_uint8_t_u_u(
               1UL,
               (safe_rshift_func_uint8_t_u_s(
                   (safe_rshift_func_int8_t_s_u(
                       ((!(safe_mul_func_uint8_t_u_u(
                            ((((((l_1355 > 1UL) >= l_1362[0]) || l_1437) &&
                               0UL) ||
                              (safe_lshift_func_uint8_t_u_u(
                                  (safe_rshift_func_uint16_t_u_s(
                                      (~((((safe_sub_func_uint16_t_u_u(
                                               (g_515 >
                                                ((safe_lshift_func_int16_t_s_u(
                                                     (g_252,
                                                      ((g_515, 0L) == l_1437)),
                                                     g_58)) > g_10)),
                                               (-4L))) < g_10) &&
                                          l_1446) ||
                                         g_11)),
                                      g_806)),
                                  l_1269))) &&
                             g_58),
                            0UL))) ||
                        0x5AL),
                       5)),
                   g_485)))) > 0xFFL);
      if (l_1362[4])
        ; /* delete */
      for (g_58 = 8; (g_58 >= 42); g_58 = safe_add_func_uint8_t_u_u(g_58, 3)) {
        uint16_t l_1455 = 0x7663L;
        uint32_t l_1470 = 5UL;
        uint32_t l_1527 = 4294967293UL;
g_593
[
2
]
[
1
]
[
1
]
 =
 (
(
safe_mul_func_int16_t_s_s
 (
(
(
safe_mul_func_int8_t_s_s
 (
(
(
(
0x8A95321BL
 |
 (
(
(
safe_mul_func_uint16_t_u_u
 (
(
(
l_1455
 ^
 (
(
(
(
(
(
safe_lshift_func_int8_t_s_u
 (
(
safe_sub_func_int8_t_s_s
 (
(
g_58
 ==
 (
(
(
(
(
(
(
safe_mul_func_uint8_t_u_u
 (
(
l_1229
[
1
]
[
9
]
 >=
 (
!
0x63ADL
)
)
,
 (
1UL
 ^
 (
(
safe_lshift_func_uint16_t_u_s
 (
(
safe_mul_func_uint16_t_u_u
 (
(
~
9UL
)
,
 (
(
4UL
 ^
 (
safe_add_func_uint8_t_u_u
 (
(
(
(
(
(
(
(
safe_lshift_func_uint16_t_u_s
 (
(
0x8FL
 <
 g_11
)
,
 g_592
)
)
 ^
 1L
)
,
 l_1455
)
,
 0xC313L
)
 &
 g_592
)
 &&
 0x987825FBL
)
 |
 l_1470
)
,
 (
-
9L
)
)
)
)
 >
 g_9
)
)
)
,
 g_252
)
)
 ||
 g_806
)
)
)
)
 ==
 g_878
[
0
]
[
2
]
[
5
]
)
,
 (
-
6L
)
)
 ==
 0x5721ABC7L
)
,
 g_148
)
,
 g_515
)
 ^
 g_9
)
)
,
 g_593
[
0
]
[
3
]
[
0
]
)
)
,
 l_1437
)
)
 >
 l_1455
)
,
 1L
)
,
 g_6
)
,
 g_593
[
0
]
[
3
]
[
0
]
)
 ==
 g_593
[
0
]
[
3
]
[
4
]
)
)
 &
 g_878
[
0
]
[
1
]
[
0
]
)
,
 9L
)
)
,
 l_1470
)
 <=
 0x6DB5226AL
)
)
 |
 g_878
[
0
]
[
4
]
[
1
]
)
,
 l_1437
)
,
 l_1230
[
6
]
)
)
 <=
 l_1278
)
,
 g_9
)
)
 &
 l_1437
)
;
for (g_11 = 2; (g_11 > 19); ++g_11) {
  uint16_t l_1475[3];
  uint16_t l_1486 = 0xA9A2L;
  int i;
  for (i = 0; i < 3; i++)
    ; /* delete */
  /* delete */
}
for (l_1380 = 17; (l_1380 < 38);
     l_1380 = safe_add_func_int16_t_s_s(l_1380, 1)) {
  int16_t l_1526 = (-5L);
  int32_t l_1567[5][10][5] = {{{(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L}},
                              {{(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L}},
                              {{(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 6L},
                               {(-1L), 0x9A0D841FL, 1L, 2L, 6L}}};
  int i, j, k;
  for (l_1278 = 0; (l_1278 <= 7); l_1278 += 1) {
    int i;
    g_592 |=
        ((l_1384[l_1278] && (-1L)) <
         ((safe_rshift_func_uint8_t_u_u(
              (safe_sub_func_int8_t_s_s(
                  (safe_mul_func_int16_t_s_s(
                      (safe_add_func_int16_t_s_s(l_1384[l_1278],
                                                 l_1362[(g_1220 + 2)])),
                      (safe_rshift_func_int16_t_s_u(l_1384[l_1278], 4)))),
                  (safe_add_func_int16_t_s_s(
                      ((safe_lshift_func_uint16_t_u_s(
                           (safe_sub_func_uint32_t_u_u(
                               (((g_593[0][3][0] > g_8) |
                                 (safe_mod_func_int8_t_s_s(l_1428, (+g_58)))) <
                                0x9322L),
                               0x4BE28134L)),
                           l_1384[l_1278])) ^
                       g_6),
                      g_9)))),
              6)) >= l_1437));
  }
  if ((safe_mul_func_int8_t_s_s(
          g_9,
          ((~((safe_mul_func_uint16_t_u_u(
                  (g_878[0][0][4] <
                   (0xBDBBL >=
                    (safe_mod_func_uint32_t_u_u(
                        (g_593[0][1][0],
                         ((safe_add_func_uint16_t_u_u(
                              (safe_lshift_func_int16_t_s_s(l_1412, 5)),
                              (g_1220,
                               ((safe_mul_func_int8_t_s_s(
                                    ((l_1521 >= ((safe_mod_func_uint8_t_u_u(
                                                     (safe_add_func_int32_t_s_s(
                                                         (l_1526 != l_1526),
                                                         0x6E65C9C9L)),
                                                     l_1527)) ||
                                                 g_4)) >= 0L),
                                    l_1528)) != g_593[2][3][1])))) == g_4)),
                        0x3AC5143EL)))),
                  0x5A67L)) &
              g_878[0][0][1])),
           0x8CL)))) {
    uint16_t l_1551 = 4UL;
    if (l_1412)
      ; /* delete */
    /* delete */
  } else {
    g_677 = g_878[0][0][1];
    /* delete */
  }
  /* delete */
}
for (g_10 = 0; (g_10 >= (-20)); g_10 = safe_sub_func_uint16_t_u_u(g_10, 3)) {
  int8_t l_1577 = 0x68L;
  l_1357 =
      ((safe_sub_func_int16_t_s_s(
           l_1428,
           (safe_add_func_uint16_t_u_u(((g_515 != g_485), 0x9D3CL),
                                       (g_1220 >= (l_1577 <= g_1220)))))) !=
       (safe_rshift_func_uint8_t_u_s(
           (safe_rshift_func_uint8_t_u_u(
               (safe_mod_func_uint16_t_u_u(0x7493L, ((l_1568 != 1UL), l_1470))),
               l_1362[1])),
           4)));
}
      }
    } else {
      const uint32_t l_1598 = 4UL;
      l_1229[1][4] =
          (((l_1230[4] &
             (((!(((l_1566[1] ==
                    (g_1565 ^
                     (safe_lshift_func_int8_t_s_s(
                         (((((((((((safe_mul_func_int16_t_s_s(
                                       (safe_mod_func_uint8_t_u_u(
                                           (l_1249[0][0] ||
                                            (safe_mul_func_int8_t_s_s(
                                                (((safe_sub_func_int16_t_s_s(
                                                      (l_1446 >= g_8),
                                                      ((+(safe_add_func_int32_t_s_s(
                                                           (((g_806 !=
                                                              (((((safe_rshift_func_int8_t_s_s(
                                                                      g_593[0]
                                                                           [3]
                                                                           [0],
                                                                      1)),
                                                                  (4294967294UL >=
                                                                   4294967292UL)) |
                                                                 0x2814L) &&
                                                                g_58) ^
                                                               l_1428)) <=
                                                             l_1566[1]),
                                                            g_148),
                                                           g_485))) ^
                                                       65535UL))) != 3UL) >
                                                 l_1446),
                                                0UL))),
                                           g_485)),
                                       g_485)) > g_485) > g_806) < 0xE3L),
                                l_1528) <= l_1598) &&
                              g_4) ^
                             l_1599) == g_1220),
                           l_1528) &&
                          l_1229[1][9]),
                         6)))) ^
                   g_1565) |
                  l_1598)),
               0x68L) ^
              l_1249[0][1])),
            0L),
           0x9C65AFF9L);
    }
    for (g_6 = 20; (g_6 == 21); g_6 = safe_add_func_uint32_t_u_u(g_6, 1)) {
      uint32_t l_1610[1][1][9] = {
          {{4294967292UL, 4294967292UL, 0x41F02188L, 4294967292UL, 4294967292UL,
            0x41F02188L, 4294967292UL, 4294967292UL, 0x41F02188L}}};
      int32_t l_1613 = 0x339E279CL;
      int i, j, k;
      if (((((((safe_lshift_func_int16_t_s_s(1L, g_8)) ||
               ((safe_mul_func_uint16_t_u_u(l_1412, l_1278)),
                ((((0xDE2FL < (g_593[0][0][5],
                               (safe_sub_func_int8_t_s_s(
                                   l_1610[0][0][4], ((((l_1599 ^ g_1220),
                                                       l_1611) < l_1229[0][9]) ^
                                                     g_9))))) < 0x4BC5L),
                  g_677) < l_1230[4]))),
              0x8B42L) &&
             g_592),
            l_1428) |
           (-9L))) {
        l_1612[1] = g_8;
        l_1613 = g_485;
      } else {
        if (g_58)
          break;
      }
      g_485 =
          ((g_8 <
            (l_1229[1][9] ==
             (safe_sub_func_int8_t_s_s(
                 ((((((((safe_unary_minus_func_uint32_t_u((
                            l_1249[0][3] >=
                            (((safe_rshift_func_uint8_t_u_s(
                                  (safe_sub_func_int16_t_s_s(
                                      (g_592 & g_485),
                                      (((((l_1568,
                                           (safe_mul_func_int8_t_s_s(
                                               ((safe_lshift_func_uint16_t_u_u(
                                                    g_593[1][3][4],
                                                    (safe_sub_func_int32_t_s_s(
                                                        0xF389AD00L,
                                                        (safe_unary_minus_func_int8_t_s(
                                                            g_485)))))) ^
                                                0UL),
                                               g_1565))) != l_1230[1]) &
                                         1L) |
                                        g_485),
                                       g_677))),
                                  g_148)) > l_1610[0][0][4]) ^
                             l_1610[0][0][4])))) != 2UL) |
                       l_1613),
                      l_1384[4]),
                     0xDD3B204EL) == l_1610[0][0][4]) >= l_1446),
                  g_9),
                 g_11)))),
           g_677);
      for (g_10 = 0; (g_10 <= 9); g_10 += 1) {
        int32_t l_1628 = (-8L);
        int i;
        /* delete */
      }
    }
  }
  return g_1220;
}
static int32_t func_2(const uint32_t p_3) {
  int8_t l_5 = 0x4FL;
  int32_t l_7[1];
  uint32_t l_1211 = 4294967294UL;
  uint8_t l_1221 = 250UL;
  int i;
  for (i = 0; i < 1; i++)
    l_7[i] = 3L;
  g_11--;
  l_7[0] = ((g_10 != (func_14((g_8 | 0UL), g_10, p_3) <
                      ((-4L) & (((safe_rshift_func_uint16_t_u_u(65535UL, 11)) ^
                                 (safe_sub_func_uint16_t_u_u(
                                     (safe_add_func_uint8_t_u_u(l_5, p_3)),
                                     g_878[0][0][0]))) ||
                                g_878[0][0][1])))) != p_3);
  g_593[0][3][0] =
      (((l_1211 <
         (+((safe_rshift_func_int8_t_s_s((g_677 & g_592),
                                         (l_7[0] == 4294967286UL))) >=
            (((((((((p_3 |
                     ((((((((-4L) | g_9),
                           ((safe_mul_func_uint8_t_u_u(
                                (safe_rshift_func_int16_t_s_u(0x7B8EL, g_806)),
                                0x9CL)) &
                            p_3)),
                          l_5) == 4L) ||
                        g_9) <= p_3) < 0xE675L)) &&
                    p_3),
                   p_3) >= p_3) == 0x20C5L) < g_806),
               l_7[0]),
              g_1220) <= l_1211)))) &
        4294967295UL) > 65535UL);
  return l_1221;
}
static uint32_t func_14(uint8_t p_15, uint32_t p_16, uint16_t p_17) {
  int16_t l_22 = 3L;
  int8_t l_1053 = 0L;
  uint16_t l_1084 = 0x44F9L;
  int32_t l_1093 = 0x7F652F4AL;
  uint32_t l_1146 = 4294967287UL;
  int32_t l_1173[1][10] = {{2L, 0L, 2L, 0L, 2L, 0L, 2L, 0L, 2L, 0L}};
  int32_t l_1174 = (-8L);
  int32_t l_1175 = 0x30981575L;
  int i, j;
  if ((safe_lshift_func_uint16_t_u_u(
          (!p_17), ((((((func_20(l_22), ((!(65535UL && g_11)) < l_22)) >=
                        ((~((safe_add_func_uint32_t_u_u(
                                (safe_rshift_func_int16_t_s_s(p_15, 7)),
                                g_878[0][0][1])) ==
                            (((l_22 > l_1053) <= g_878[0][0][6]) || g_10))) >=
                         g_806)) >= p_15) >= p_15) >= l_1053) ||
                    p_16)))) {
    uint32_t l_1062 = 0UL;
    int32_t l_1063[1];
    int i;
    /* delete */
    if ((((g_58 <
           (((g_593[0][3][0] >=
              (safe_mod_func_uint16_t_u_u(
                  (safe_mul_func_uint8_t_u_u(
                      p_16,
                      (((g_252,
                         ((safe_mul_func_uint16_t_u_u(l_1053, g_878[0][0][1])),
                          (g_878[0][0][6] ==
                           ((4294967293UL ==
                             (safe_add_func_uint32_t_u_u(
                                 (((p_17 < g_592) ^ l_1062) > g_58), p_16))),
                            p_16)))) <= p_17) &
                       g_6))),
                  65535UL))) ^
             g_485) ||
            p_15)) >= l_22) |
         0xEB587278L)) {
      const int8_t l_1073 = 0x05L;
      l_1063[0] = 0xF293357CL;
      for (p_17 = 0; (p_17 <= 0); p_17 += 1) {
        uint32_t l_1074 = 0xFF804381L;
        int i;
        /* delete */
        for (l_1053 = 2; (l_1053 >= 0); l_1053 -= 1) {
          /* delete */
          return p_16;
        }
      }
    } else {
      int32_t l_1085 = 0L;
      int32_t l_1086 = 0x1DBD3C5FL;
      g_593[1][0][4] =
          (0xB45BL <
           ((safe_mul_func_int8_t_s_s(
                ((safe_unary_minus_func_int8_t_s(
                     (0x9F1D8A61L >
                      ((safe_add_func_int8_t_s_s(
                           ((safe_add_func_int16_t_s_s(
                                (p_15 |
                                 ((p_16 <= (l_1062 >= p_15)) ==
                                  ((0x60C6A31CL <
                                    (safe_add_func_int16_t_s_s(
                                        ((((((((l_22 >= (g_11, p_17)) ^
                                               0xA430L) > p_17) >= l_1084) ||
                                            0xA8F1L) |
                                           g_58),
                                          p_15) |
                                         p_16),
                                        p_15))) > p_15))),
                                l_1085)) != p_15),
                           p_15)),
                       g_11)))) ^
                 l_1085),
                l_1086)) ^
            l_1085));
      for (l_1053 = 0; (l_1053 >= (-28));
           l_1053 = safe_sub_func_int8_t_s_s(l_1053, 7)) {
        l_1063[0] |= g_8;
      }
    }
    l_1093 = (((safe_sub_func_uint16_t_u_u(
                   g_592,
                   (0UL <
                    ((((((+(p_17, (p_15 > g_593[2][2][3]))) & 255UL) >= p_17) !=
                       ((safe_mul_func_int16_t_s_s((p_16 == l_22), p_16)) |
                        0xDEL)) == g_9),
                     0L)))) |
               p_17) <= l_1084);
    l_1093 =
        (l_1063[0] ^
         ((safe_rshift_func_uint16_t_u_s(
              65534UL,
              (safe_rshift_func_uint16_t_u_u(
                  (safe_lshift_func_uint8_t_u_u(
                      ((safe_mul_func_uint16_t_u_u(
                           ((!(p_17 <= p_15)) && p_17),
                           ((safe_rshift_func_int16_t_s_u(
                                (safe_rshift_func_int8_t_s_u(
                                    (l_1063[0] !=
                                     (((((+(g_677 <=
                                            (((safe_sub_func_uint32_t_u_u(
                                                  (((g_593[0][3][0] < g_6) &
                                                    65526UL) >= g_878[0][4][3]),
                                                  p_15)),
                                              l_1053),
                                             l_1093))) < p_17) ||
                                        l_1063[0]) ||
                                       l_1093) > 0xC4E5D3E3L)),
                                    7)),
                                g_8)) == 7UL))) &
                       0x92L),
                      6)),
                  l_1063[0])))) &&
          l_1063[0]));
  } else {
    uint32_t l_1110 = 4294967295UL;
    uint16_t l_1139 = 1UL;
    ++l_1110;
    for (g_11 = 7; (g_11 <= 33); g_11 = safe_add_func_uint8_t_u_u(g_11, 5)) {
      int32_t l_1123[7] = {(-1L), (-1L), 0L, (-1L), (-1L), 0L, (-1L)};
      int32_t l_1155 = 5L;
      int i;
      g_485 |= g_878[0][0][1];
      if ((safe_mod_func_int8_t_s_s(
              (safe_mod_func_uint32_t_u_u(
                  (!(safe_add_func_uint32_t_u_u(l_1084, l_1110))),
                  (safe_rshift_func_int8_t_s_u((-5L), l_1123[0])))),
              ((safe_rshift_func_int16_t_s_u(
                   (((safe_lshift_func_int8_t_s_s(
                         (((safe_mod_func_uint16_t_u_u(
                               (safe_sub_func_uint16_t_u_u(
                                   (g_10,
                                    ((0xC6L | (g_878[0][0][1],
                                               (safe_sub_func_int32_t_s_s(
                                                   (1UL != p_15), p_16)))) &&
                                     249UL)),
                                   1L)),
                               0x6D8EL)),
                           p_16) >= l_1110),
                         g_9)) &&
                     p_16) < l_22),
                   4)),
               p_16)))) {
        int32_t l_1138[2] = {0, 0};
        int i;
        for (i = 0; i < 2; i++)
          ; /* delete */
        l_1139 =
            (((((safe_add_func_uint8_t_u_u(
                    (((safe_lshift_func_int16_t_s_u(
                          (((1UL | (g_6 < (((((p_16 ^ g_878[0][0][6]) >=
                                              246UL) < (p_15 <= l_1123[0])) &&
                                            (((g_593[1][2][4],
                                               (((g_878[0][0][3] ^ p_17) >
                                                 l_1138[1]) ||
                                                g_11)),
                                              (-8L)) != g_593[2][1][3])),
                                           l_1053))) |
                            (-9L)),
                           1L),
                          g_10)) |
                      (-1L)),
                     p_17),
                    p_17)),
                g_58) == g_878[0][0][1]) <= p_16) |
             l_1138[1]);
      } else {
        l_1155 |= (~(
            ((((p_16, g_677) < l_22),
              ((((safe_mul_func_int8_t_s_s(
                     ((safe_sub_func_int8_t_s_s(
                          (safe_lshift_func_uint16_t_u_u(l_1123[0],
                                                         (l_1123[0], l_1146))),
                          (safe_mod_func_uint8_t_u_u(
                              (((safe_add_func_int32_t_s_s(
                                    (safe_mul_func_int8_t_s_s(
                                        g_878[0][4][1],
                                        (safe_rshift_func_int8_t_s_u(
                                            ((p_16 != (g_252 == 255UL)), 0xBAL),
                                            0)))),
                                    0xEDE83B49L)) <= p_16),
                               g_11),
                              0x88L)))),
                      0x6DL),
                     0xA8L)) |
                 p_17),
                0x7C4DL) ||
               p_15)) >= g_485),
            g_677));
      }
    }
  }
  for (g_485 = 19; (g_485 <= (-9)); g_485--) {
    if (g_4)
      ; /* delete */
  }
  if ((p_17 ||
       ((safe_lshift_func_int16_t_s_u(
            ((l_1146,
              ((((((g_11 | 254UL),
                   (safe_rshift_func_int16_t_s_u(
                       (safe_sub_func_uint32_t_u_u(
                           (((safe_unary_minus_func_uint16_t_u((
                                 p_16,
                                 ((safe_lshift_func_uint8_t_u_s(
                                      g_10, (safe_mul_func_uint8_t_u_u(
                                                l_1053, g_878[0][0][1])))),
                                  (safe_sub_func_uint32_t_u_u(
                                      ((safe_lshift_func_uint16_t_u_u(0UL, 12)),
                                       g_252),
                                      l_1093)))))) > l_1173[0][5]) &&
                            l_1174),
                           p_17)),
                       0))) &&
                  l_1174),
                 7L),
                g_878[0][0][1]) ^
               0xA2L)) <= g_148),
            p_16)) < l_1175))) {
    int32_t l_1202[8] = {0xDB3CA381L, 0xDB3CA381L, 1L,          0xDB3CA381L,
                         0xDB3CA381L, 1L,          0xDB3CA381L, 0xDB3CA381L};
    int i;
    l_1202[5] = (safe_mod_func_uint32_t_u_u(
        (safe_mul_func_int8_t_s_s(l_1173[0][1], g_593[0][3][0])),
        (safe_lshift_func_int16_t_s_u(
            (safe_lshift_func_int16_t_s_s(
                ((p_15 < 0x75L),
                 ((((safe_sub_func_int16_t_s_s(
                        g_148,
                        (safe_add_func_int16_t_s_s(
                            ((-4L) ^
                             (safe_rshift_func_uint16_t_u_s(
                                 (safe_lshift_func_uint8_t_u_u(
                                     (~((((safe_mul_func_int8_t_s_s(
                                              (((safe_sub_func_int16_t_s_s(
                                                    ((safe_mod_func_uint8_t_u_u(
                                                         (!(safe_mod_func_uint8_t_u_u(
                                                             (safe_rshift_func_int16_t_s_s(
                                                                 ((g_593[0][3]
                                                                        [0] ||
                                                                   ((l_1174 ^
                                                                     g_878[0][0]
                                                                          [6]),
                                                                    l_1175)),
                                                                  g_806),
                                                                 g_9)),
                                                             p_15))),
                                                         l_1202[5])) |
                                                     3L),
                                                    g_806)) < p_15),
                                               g_58),
                                              l_1202[3])) ||
                                          p_16) > l_22) == p_15)),
                                     6)),
                                 9))),
                            g_11)))) == p_17),
                   0UL) |
                  p_17)),
                15)),
            8))));
  } else {
    return p_16;
  }
  for (l_1053 = 0; (l_1053 != 28); l_1053++) {
    g_593[0][3][0] = 0x7D557EB5L;
  }
  return l_1146;
}
static int32_t func_20(int16_t p_21) {
  const int8_t l_486 = 0x5EL;
  uint8_t l_995 = 0UL;
  int32_t l_1048 = (-1L);
  l_1048 = (safe_mul_func_int16_t_s_s(
      p_21,
      (safe_sub_func_uint32_t_u_u(
          (func_27(
               p_21,
               (func_30(
                    ((safe_mod_func_uint16_t_u_u(
                         ((safe_add_func_uint32_t_u_u(
                              ((0x4186E145L &&
                                (0xD79339B8L &&
                                 (func_37(
                                      (safe_rshift_func_uint16_t_u_s(
                                          func_45(p_21,
                                                  (((func_50(g_11, p_21, g_4,
                                                             p_21, g_6) < g_9) ^
                                                    p_21),
                                                   p_21),
                                                  l_486, g_4),
                                          l_486)),
                                      l_486, l_486, g_9, g_8) < g_9))) != g_9),
                              4294967287UL)) >= g_9),
                         p_21)) &
                     l_995),
                    p_21),
                0x83L)) ^
           l_486),
          0xC35E2FB1L))));
  return p_21;
}
static uint16_t func_27(int32_t p_28, int8_t p_29) {
  int8_t l_1018 = (-4L);
  int32_t l_1033[6] = {0x84077342L, 0x84077342L, 3L,
                       0x84077342L, 0x84077342L, 3L};
  int i;
  l_1033[1] ^=
      ((safe_sub_func_int8_t_s_s(
           (((~(safe_sub_func_int8_t_s_s(
                 (safe_rshift_func_uint8_t_u_s(
                     (safe_mod_func_int8_t_s_s(
                         l_1018,
                         (safe_mul_func_int16_t_s_s(g_515, (~0x1E84L))))),
                     4)),
                 ((((safe_add_func_uint8_t_u_u(
                        l_1018,
                        (safe_mul_func_int16_t_s_s(
                            p_29,
                            ((safe_mul_func_int8_t_s_s(
                                 0x52L,
                                 ((safe_mod_func_uint32_t_u_u(
                                      (safe_lshift_func_int8_t_s_u(
                                          (l_1018 == (safe_sub_func_int16_t_s_s(
                                                         g_10, p_28))),
                                          2)),
                                      l_1018)) == g_148))),
                             g_58))))) >= 0x3FL) >= 1L) |
                  g_878[0][4][5])))) >= 7L) ^
            (-8L)),
           l_1018)),
       p_28);
  for (g_9 = 0; (g_9 > (-9)); g_9--) {
    if (g_252)
      break;
  }
  p_28 = ((safe_lshift_func_uint16_t_u_u(
              g_8, (safe_lshift_func_uint8_t_u_u(
                       (((safe_mul_func_uint8_t_u_u(1UL, 3L)) < p_29) & g_592),
                       (safe_lshift_func_int8_t_s_s(
                           (safe_lshift_func_uint8_t_u_u(
                               (l_1033[2] ||
                                (l_1018, (((safe_add_func_int8_t_s_s(
                                               (p_28, (p_29 <= g_10)), g_4)),
                                           l_1033[4]) > p_28))),
                               5)),
                           p_28)))))) &&
          248UL);
  return g_593[0][3][0];
}
static uint32_t func_30(uint32_t p_31, uint8_t p_32) {
  int32_t l_998 = 1L;
  int32_t l_1009[10][5][1] = {{{0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L}},
                              {{0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L}},
                              {{0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L}},
                              {{0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L}},
                              {{0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L}},
                              {{0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L}},
                              {{0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L}},
                              {{0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L}},
                              {{0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L}},
                              {{0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L},
                               {0x572B1976L}}};
  int i, j, k;
  l_1009[4][1][0] =
      ((safe_rshift_func_int8_t_s_u(4L, l_998)),
       (safe_add_func_int32_t_s_s(
           ((p_31 == l_998) |
            (safe_sub_func_uint8_t_u_u(
                ((safe_sub_func_uint32_t_u_u(
                     ((l_998,
                       ((p_32 >
                         (((0L != (((safe_lshift_func_uint16_t_u_u(
                                        (0x5B2C4D94L ==
                                         (safe_rshift_func_int8_t_s_u(
                                             (l_998 | g_593[0][0][0]), l_998))),
                                        l_998)) ^
                                    p_32),
                                   l_998)) < g_8) <= g_58)),
                        g_592)) ^
                      g_252),
                     l_998)),
                 l_998),
                0x48L))),
           g_252)));
  return g_11;
}
static const uint32_t func_37(uint32_t p_38, int16_t p_39, int16_t p_40,
                              int16_t p_41, int32_t p_42) {
  uint32_t l_491 = 0x41C72211L;
  uint32_t l_512 = 0UL;
  int8_t l_557 = (-8L);
  int32_t l_560 = (-1L);
  int32_t l_646 = 0x1E18A1B8L;
  int32_t l_695[5] = {0L, 0L, 0L, 0L, 0L};
  uint32_t l_732 = 0xB3C0F6E4L;
  int32_t l_904 = 1L;
  int8_t l_973 = 0xE3L;
  int i;
  if ((safe_rshift_func_int16_t_s_u(
          g_9,
          ((safe_mul_func_uint16_t_u_u(
               ((~(l_491 >
                   ((g_148 <=
                     (safe_add_func_uint8_t_u_u(
                         l_491,
                         ((safe_mod_func_int32_t_s_s(
                              l_491,
                              (safe_add_func_int8_t_s_s(
                                  (safe_rshift_func_int16_t_s_u(
                                      (safe_lshift_func_uint16_t_u_s(
                                          ((safe_rshift_func_uint8_t_u_s(
                                               ((g_11 ^
                                                 ((g_4 ||
                                                   ((safe_add_func_uint8_t_u_u(
                                                        p_40,
                                                        ((((((safe_mod_func_uint8_t_u_u(
                                                                 (safe_mul_func_uint16_t_u_u(
                                                                     (((safe_sub_func_int8_t_s_s(
                                                                           g_6,
                                                                           l_491)) |
                                                                       g_4) &
                                                                      g_485),
                                                                     p_41)),
                                                                 255UL)) ||
                                                             1UL) &&
                                                            0UL),
                                                           g_10) > 0x946AL),
                                                         p_39))) <= 0x464EL)) ||
                                                  1UL)) ^
                                                0x8993L),
                                               g_58)),
                                           0UL),
                                          15)),
                                      13)),
                                  l_512)))) &&
                          6UL)))) >= p_38))),
                g_8),
               l_512)) < l_512)))) {
    return g_10;
  } else {
    int8_t l_555 = 1L;
    int32_t l_590 = 0x17549102L;
    int8_t l_678[9] = {(-1L), 0x2FL, (-1L), 0x2FL, (-1L),
                       0x2FL, (-1L), 0x2FL, (-1L)};
    uint32_t l_696[3][4][6] = {
        {{2UL, 4294967295UL, 2UL, 4294967295UL, 4294967287UL, 0xC187209CL},
         {2UL, 4294967295UL, 2UL, 4294967295UL, 4294967287UL, 0xC187209CL},
         {2UL, 4294967295UL, 2UL, 4294967295UL, 4294967287UL, 0xC187209CL},
         {2UL, 4294967295UL, 2UL, 4294967295UL, 4294967287UL, 0xC187209CL}},
        {{2UL, 4294967295UL, 2UL, 4294967295UL, 4294967287UL, 0xC187209CL},
         {2UL, 4294967295UL, 2UL, 4294967295UL, 4294967287UL, 0xC187209CL},
         {2UL, 4294967295UL, 2UL, 4294967295UL, 4294967287UL, 0xC187209CL},
         {2UL, 4294967295UL, 2UL, 4294967295UL, 4294967287UL, 0xC187209CL}},
        {{2UL, 4294967295UL, 2UL, 4294967295UL, 4294967287UL, 0xC187209CL},
         {2UL, 4294967295UL, 2UL, 4294967295UL, 4294967287UL, 0xC187209CL},
         {2UL, 4294967295UL, 2UL, 4294967295UL, 4294967287UL, 0xC187209CL},
         {2UL, 4294967295UL, 2UL, 4294967295UL, 4294967287UL, 0xC187209CL}}};
    uint32_t l_711 = 9UL;
    int i, j, k;
    if ((safe_mod_func_int32_t_s_s(g_9, g_58))) {
      uint16_t l_522 = 65535UL;
      int32_t l_527 = 4L;
      uint32_t l_556 = 1UL;
      int32_t l_566 = (-1L);
      int32_t l_645 = 0xB51FAC4DL;
      /* delete */
      l_527 = (safe_sub_func_uint16_t_u_u(
          ((safe_mul_func_int16_t_s_s(
               ((4294967294UL ^ g_6) >=
                (((~(l_522 <=
                     ((g_252 ^ p_42) &&
                      (((((safe_lshift_func_int16_t_s_s(p_39, 6)) > l_491) |
                         (safe_sub_func_int16_t_s_s(
                             g_4, (((0UL ^ l_512), 0x5F70L) < p_42)))) == 6UL),
                       p_39)))) &
                  p_42) ^
                 l_522)),
               g_9)) ||
           g_8),
          p_38));
      /* delete */
    } else {
      g_592 = 0L;
    }
    g_485 &=
        ((safe_lshift_func_uint8_t_u_s(
             (!(((((safe_lshift_func_int8_t_s_s(
                       ((p_38 &
                         ((safe_sub_func_int32_t_s_s(
                              (p_38 <
                               (1L >=
                                (1UL >=
                                 ((safe_mod_func_int16_t_s_s(
                                      ((((safe_sub_func_uint16_t_u_u(
                                             1UL,
                                             ((p_38 ||
                                               ((g_10,
                                                 (+((g_10 ||
                                                     ((safe_sub_func_uint32_t_u_u(
                                                          ((((0xAFL != 0UL),
                                                             0x5FL) > 0UL) &&
                                                           1L),
                                                          p_38)),
                                                      l_555)),
                                                    l_512))) &
                                                g_11)) &
                                              p_39))),
                                         g_10) &
                                        0xC540F072L),
                                       g_4),
                                      l_555)),
                                  p_42)))),
                              l_696[2][2][2])) >= l_560)) <= 65531UL),
                       l_711)) > g_6) ||
                  p_38) >= 1UL) == 0L)),
             g_10)),
         p_38);
    g_485 = (safe_lshift_func_uint8_t_u_u(
        1UL,
        (((((safe_mod_func_int8_t_s_s((l_512 == 0xECL), (p_40 ^ (~(~2L))))) ||
            g_11) <= p_39),
          (+(((l_678[5] ==
               (safe_mod_func_uint8_t_u_u(
                   ((safe_rshift_func_int16_t_s_u(p_38, p_39)) >= 7L),
                   l_555))) <= 248UL) > g_58))),
         g_6)));
  }
  /* delete */
  /* delete */
  return g_806;
}
static uint16_t func_45(uint16_t p_46, int32_t p_47, const int8_t p_48,
                        const int8_t p_49) {
  return g_4;
}
static int8_t func_50(int32_t p_51, uint8_t p_52, uint32_t p_53, int32_t p_54,
                      const uint32_t p_55) {
  int32_t l_56 = (-1L);
  int32_t l_57[4] = {0x309757A8L, 0x681C37F5L, 0x309757A8L, 0x681C37F5L};
  int8_t l_253 = 5L;
  const int32_t l_284 = 0x53ABCEACL;
  uint8_t l_400[7];
  uint8_t l_414 = 9UL;
  int i;
  for (i = 0; i < 7; i++)
    l_400[i] = 255UL;
  ++g_58;
  for (g_11 = 0; (g_11 <= 3); g_11 += 1) {
    uint8_t l_92 = 0x5DL;
    int32_t l_163 = 8L;
    int32_t l_358 = 0L;
    uint32_t l_407 = 4294967289UL;
    int i;
    l_57[g_11] ^= 4L;
    for (g_58 = 0; (g_58 <= 3); g_58 += 1) {
      int16_t l_61 = (-1L);
      int32_t l_127 = 0x551B120EL;
      int8_t l_204 = 0x5DL;
      int32_t l_228[8] = {8L, 0xC1BA8594L, 8L, 0xC1BA8594L,
                          8L, 0xC1BA8594L, 8L, 0xC1BA8594L};
      uint16_t l_251 = 0UL;
      int8_t l_254[9] = {(-1L), (-1L), 0L, (-1L), (-1L), 0L, (-1L), (-1L), 0L};
      int i;
      for (g_6 = 3; (g_6 >= 0); g_6 -= 1) {
        int i;
        l_61 = l_57[g_58];
      }
      for (p_54 = 0; (p_54 <= 3); p_54 += 1) {
        int32_t l_106[8][3] = {
            {(-1L), 0x5D214902L, 1L}, {(-1L), 0x5D214902L, 1L},
            {(-1L), 0x5D214902L, 1L}, {(-1L), 0x5D214902L, 1L},
            {(-1L), 0x5D214902L, 1L}, {(-1L), 0x5D214902L, 1L},
            {(-1L), 0x5D214902L, 1L}, {(-1L), 0x5D214902L, 1L}};
        int i, j;
        if (l_57[g_11])
          break;
        if (g_8) {
          for (p_51 = 0; p_51 < 4; p_51 += 1) {
            /* delete */
          }
        } else {
          int8_t l_87 = 3L;
          int32_t l_128 = (-3L);
          uint8_t l_182 = 0x70L;
          int32_t l_183 = 0x7CBB44D9L;
          if (l_57[g_11]) {
            int32_t l_93[2][2][5] = {
                {{0x2EE702D1L, 0x2EE702D1L, 1L, 0x2EE702D1L, 0x2EE702D1L},
                 {0x2EE702D1L, 0x2EE702D1L, 1L, 0x2EE702D1L, 0x2EE702D1L}},
                {{0x2EE702D1L, 0x2EE702D1L, 1L, 0x2EE702D1L, 0x2EE702D1L},
                 {0x2EE702D1L, 0x2EE702D1L, 1L, 0x2EE702D1L, 0x2EE702D1L}}};
            int i, j, k;
            l_57[2] = func_62(
                ((safe_mod_func_uint32_t_u_u(
                     ((safe_mul_func_int16_t_s_s(
                          (safe_mod_func_int32_t_s_s(
                              ((p_54 |
                                (((((p_51 >
                                     ((safe_rshift_func_uint16_t_u_s(
                                          ((safe_mul_func_int8_t_s_s(
                                               ((((safe_lshift_func_int8_t_s_s(
                                                      (safe_sub_func_uint8_t_u_u(
                                                          (((p_54 !=
                                                             (g_6,
                                                              (safe_sub_func_uint16_t_u_u(
                                                                  (g_10 <
                                                                   (safe_sub_func_uint8_t_u_u(
                                                                       1UL,
                                                                       (safe_sub_func_int8_t_s_s(
                                                                           (safe_lshift_func_uint8_t_u_u(
                                                                               0xDDL,
                                                                               l_87)),
                                                                           (safe_lshift_func_uint16_t_u_u(
                                                                               (safe_add_func_uint8_t_u_u(
                                                                                   p_52,
                                                                                   p_51)),
                                                                               p_53))))))),
                                                                  l_57[g_11])))),
                                                            g_11) ||
                                                           65535UL),
                                                          0x5AL)),
                                                      7)),
                                                  4294967293UL) == 3UL),
                                                (-3L)),
                                               0xB3L)) &&
                                           l_57[g_11]),
                                          l_92)) &&
                                      g_9)) &&
                                    g_4),
                                   0x18F8L) ||
                                  g_58) ||
                                 0x9FL)) <= 0x2E27L),
                              p_55)),
                          0x04C9L)) &
                      255UL),
                     g_11)),
                 1UL),
                l_93[1][1][4]);
            if (g_6)
              ; /* delete */
            l_93[1][0][4] = 0xA5A8E70CL;
          } else {
            l_57[g_11] = (l_57[g_11] ^ g_10);
          }
          for (l_92 = 26; (l_92 != 49);
               l_92 = safe_add_func_uint16_t_u_u(l_92, 3)) {
            uint8_t l_126 = 0xD6L;
            if (l_92)
              ; /* delete */
            /* delete */
            /* delete */
          }
          if ((safe_unary_minus_func_int8_t_s(p_54))) {
            int32_t l_146 = (-1L);
            l_106[1][2] =
                ((~((safe_sub_func_uint32_t_u_u(
                        (safe_sub_func_uint8_t_u_u(
                            (((((((safe_lshift_func_int8_t_s_s(
                                      (!(((((safe_sub_func_int32_t_s_s(
                                                ((p_53 & g_9) |
                                                 ((((l_128 !=
                                                     (safe_mod_func_int32_t_s_s(
                                                         (safe_sub_func_uint16_t_u_u(
                                                             p_55,
                                                             l_106[2][2])),
                                                         l_57[g_11]))) !=
                                                    (0x64E3L !=
                                                     ((safe_rshift_func_uint16_t_u_s(
                                                          ((((((safe_mul_func_int8_t_s_s(
                                                                   (l_56 <=
                                                                    (1L <
                                                                     p_52)),
                                                                   254UL)),
                                                               g_10) |
                                                              246UL),
                                                             8UL) &
                                                            0x6958L),
                                                           0UL),
                                                          l_57[3])) &&
                                                      p_51))),
                                                   p_54) > 0x27L)),
                                                g_8)) < l_146) == 1UL) &
                                          l_56) > l_57[3])),
                                      7)) &&
                                  l_61) ^
                                 g_4) ^
                                l_57[3]) >= l_128) >= l_106[6][0]) ^
                             p_55),
                            0x03L)),
                        0xA708A12FL)) &
                    p_53)),
                 l_57[g_11]);
            return g_8;
          } else {
            int16_t l_147 = (-9L);
            g_148--;
            l_163 ^=
                ((safe_mul_func_uint16_t_u_u(
                     (safe_mul_func_uint16_t_u_u(
                         p_52,
                         (l_87 >
                          (safe_mod_func_uint8_t_u_u(
                              (((((safe_add_func_uint8_t_u_u(
                                      (0xE8B2L ^ g_58),
                                      (((0x70E6L &
                                         ((safe_mul_func_int8_t_s_s(
                                              l_106[6][1],
                                              ((l_106[2][2] !=
                                                ((((safe_mul_func_uint8_t_u_u(
                                                       (g_58, l_87), (-10L))) ==
                                                   p_53) &
                                                  0xD7L),
                                                 (-4L))) ||
                                               0x68978726L))),
                                          p_51)) <= p_55) == p_51))),
                                  l_106[2][2]) > l_128) > p_51) |
                               (-7L)),
                              l_57[3]))))),
                     0x85CCL)) ^
                 0L);
            l_57[g_11] |=
                ((g_10 <
                  ((safe_unary_minus_func_uint8_t_u((
                       ((safe_mul_func_int8_t_s_s(
                            ((safe_sub_func_int32_t_s_s(
                                 (safe_rshift_func_int16_t_s_u(1L, 15)), g_6)) ^
                             (l_163 ||
                              (safe_unary_minus_func_uint16_t_u((
                                  (safe_sub_func_int8_t_s_s(
                                      (((0xA7L !=
                                         ((safe_unary_minus_func_int32_t_s(
                                              (safe_sub_func_uint32_t_u_u(
                                                  l_128,
                                                  (safe_mod_func_int32_t_s_s(
                                                      (((0L &&
                                                         (safe_add_func_uint8_t_u_u(
                                                             ((safe_unary_minus_func_uint32_t_u(
                                                                  (p_52 !=
                                                                   0UL))) ^
                                                              0xF8L),
                                                             g_9))),
                                                        0x10L) != l_182),
                                                      4294967291UL)))))) ==
                                          l_147)) != 0x1DCDL),
                                       l_147),
                                      1UL)) &&
                                  0UL))))),
                            (-1L))),
                        (-2L)) > p_52))) != 9L)) &
                 p_53);
          }
          for (l_128 = 0; (l_128 <= 3); l_128 += 1) {
            int i;
            l_183 &= (0x69L >= (l_57[p_54] == (g_4, (!g_58))));
          }
        }
        l_163 |=
            (l_57[3] >=
             ((safe_mod_func_int16_t_s_s(
                  l_106[2][2],
                  ((p_53, (safe_mul_func_int16_t_s_s(
                              ((g_6, (safe_lshift_func_uint8_t_u_s(
                                         (0x2776L <
                                          (l_57[g_11] <
                                           (((((((safe_rshift_func_uint16_t_u_u(
                                                     l_92, p_53)),
                                                 g_148) >= 8L),
                                               0x27L),
                                              g_4),
                                             4294967295UL) ^
                                            0x5C307838L))),
                                         g_4))) &&
                               0x8087EC75L),
                              g_4))),
                   g_9))) ||
              0x4AL));
        if (((((safe_mul_func_uint16_t_u_u(
                   (!(safe_rshift_func_uint8_t_u_u(1UL, 3))), 0x7671L)) >
               (safe_rshift_func_int16_t_s_s(
                   ((p_53, ((248UL | (safe_mod_func_int8_t_s_s(
                                         (((safe_mod_func_int32_t_s_s(
                                               (safe_rshift_func_int16_t_s_u(
                                                   l_56, (+l_204))),
                                               4294967293UL)),
                                           (safe_mod_func_uint16_t_u_u(
                                               (p_55 ^ g_4), g_10))) >= g_10),
                                         g_148))) &
                            (-1L))),
                    p_55),
                   14))) &
              g_11) > p_53)) {
          uint32_t l_207 = 8UL;
          l_207--;
          l_228[6] ^=
              ((safe_mul_func_int16_t_s_s(
                   (safe_lshift_func_uint16_t_u_s(
                       ((safe_lshift_func_int8_t_s_u(
                            ((((g_10 ^
                                (g_58 !=
                                 (g_8 >=
                                  ((safe_add_func_uint32_t_u_u(
                                       ((((((safe_add_func_uint16_t_u_u(
                                                8UL,
                                                (safe_lshift_func_uint8_t_u_s(
                                                    (safe_mod_func_uint32_t_u_u(
                                                        l_56,
                                                        ((safe_rshift_func_uint16_t_u_s(
                                                             l_207, 1)) |
                                                         l_57[1]))),
                                                    ((l_57[3] &
                                                      (safe_lshift_func_int16_t_s_s(
                                                          l_207, g_11))),
                                                     g_4))))) == l_106[7][0]),
                                           p_53) ^
                                          0UL) |
                                         0x0DL) > g_148),
                                       l_57[g_11])) <= 1L)))) != p_54),
                              (-1L)) == 0x7200L),
                            g_58)) &
                        g_148),
                       p_51)),
                   g_9)) > g_10);
          l_106[2][2] =
              (!((+(((((safe_lshift_func_uint16_t_u_s(
                           ((g_58 > (0UL != (g_11 > l_56))) & 0L),
                           (safe_unary_minus_func_int16_t_s(
                               (safe_sub_func_int32_t_s_s((g_58 ^ g_10),
                                                          0x17C70540L)))))) <=
                       ((0x8961DA0AL != 0xDEA74B1BL) == g_11)) == 0UL) >=
                     l_228[7]) > 0x4A2B7FD2L)) <= g_58));
        } else {
          uint8_t l_250 = 253UL;
          for (l_163 = 3; (l_163 >= 0); l_163 -= 1) {
            int i;
            /* delete */
            /* delete */
          }
          l_253 = g_10;
          l_163 = l_254[0];
        }
      }
    }
    if ((((safe_mul_func_uint8_t_u_u(
              l_57[g_11],
              (((!((safe_unary_minus_func_int16_t_s(
                       (l_57[0] |
                        (4294967287UL ==
                         ((((((p_51 & g_11) ==
                              (((safe_add_func_int8_t_s_s(
                                    ((((((safe_mul_func_int16_t_s_s(
                                             0x89F0L, (-1L))) >= p_51),
                                        ((safe_mul_func_uint8_t_u_u(
                                             (safe_unary_minus_func_uint32_t_u(
                                                 (l_56 != 255UL))),
                                             l_253)),
                                         2L)),
                                       p_53),
                                      255UL) == 0x44L),
                                    g_8)) < 0L) ||
                               g_148)),
                             g_9) ^
                            g_252) != p_53) |
                          g_148))))) ^
                   g_9)) < l_56) ^
               g_6))),
          7L) &&
         p_53)) {
      int16_t l_281 = (-1L);
      const int32_t l_303 = 0x22ABE010L;
      uint8_t l_304[4][6] = {{255UL, 0x47L, 255UL, 0x47L, 255UL, 0x47L},
                             {255UL, 0x47L, 255UL, 0x47L, 255UL, 0x47L},
                             {255UL, 0x47L, 255UL, 0x47L, 255UL, 0x47L},
                             {255UL, 0x47L, 255UL, 0x47L, 255UL, 0x47L}};
      int8_t l_305 = 0x0CL;
      uint8_t l_322[6][1] = {{255UL}, {255UL}, {255UL},
                             {255UL}, {255UL}, {255UL}};
      uint32_t l_356 = 7UL;
      int32_t l_399 = (-1L);
      uint32_t l_436 = 4294967295UL;
      int i, j;
      for (g_58 = 0; (g_58 <= 3); g_58 += 1) {
        int8_t l_285 = 0L;
        int i;
        l_57[g_11] =
            ((((((((safe_lshift_func_uint8_t_u_s(255UL, 7)) <
                   (((((safe_sub_func_uint8_t_u_u(
                           (safe_add_func_int8_t_s_s(
                               0x47L,
                               ((safe_mod_func_uint32_t_u_u(
                                    (safe_mod_func_uint32_t_u_u(
                                        ((l_57[g_11] >=
                                          (((0xEEC47D6EL >=
                                             (safe_mod_func_uint32_t_u_u(
                                                 (((((safe_sub_func_uint8_t_u_u(
                                                         l_281, 0L)) &
                                                     (g_148,
                                                      (p_55 !=
                                                       ((safe_rshift_func_int16_t_s_u(
                                                            g_148, 13)) |
                                                        0xEBB6C139L)))) &&
                                                    l_281) &
                                                   0x1AC7L) &
                                                  0L),
                                                 p_51))) <= g_10),
                                           g_252)) &
                                         l_57[g_11]),
                                        l_284)),
                                    p_54)) ||
                                l_253))),
                           (-5L))) &&
                       g_11),
                      g_148) <= l_57[g_11]),
                    0UL)),
                  l_57[g_11]) >= g_6) ||
                l_285) <= p_52) &
              l_285) == l_57[0]);
        for (p_52 = 0; (p_52 == 36);
             p_52 = safe_add_func_uint8_t_u_u(p_52, 2)) {
          int16_t l_288[5];
          int i;
          /* delete */
          l_288[4] = 0xA55430ACL;
        }
        l_305 |=
            (((((((((safe_mod_func_uint16_t_u_u(
                        (l_163 < 0xFDB97C64L),
                        (((safe_rshift_func_uint16_t_u_s(0xFA5CL, g_4)),
                          (safe_mul_func_uint8_t_u_u(
                              ((safe_mod_func_int32_t_s_s(
                                   0x97B437FCL,
                                   (safe_mul_func_int8_t_s_s(
                                       ((l_57[g_11] ==
                                         (((0xE5901075L || 0xDCA3CA68L) >
                                           (safe_mod_func_int8_t_s_s(
                                               (((safe_add_func_int8_t_s_s(
                                                     (g_8 < l_303),
                                                     l_57[g_11])) > l_57[g_11]),
                                                0L),
                                               p_54))),
                                          g_8)) &&
                                        0xE046L),
                                       g_252)))),
                               p_53),
                              g_6))) &
                         l_92))) != p_51) |
                   l_304[3][4]) ^
                  0xFE1010FDL) > g_4) ||
                l_253),
               0x8B6CL) ||
              l_304[3][4]) != g_148);
        g_6 =
            ((((safe_sub_func_uint32_t_u_u(
                   (((safe_lshift_func_uint16_t_u_s(
                         ((65528UL != (250UL && (g_11 && 1UL))) &&
                          ((((l_281 &&
                              (~((safe_mul_func_uint8_t_u_u(
                                     ((safe_sub_func_int32_t_s_s(
                                          (g_4 ||
                                           ((((((safe_mul_func_int16_t_s_s(
                                                    (safe_lshift_func_uint8_t_u_s(
                                                        (0x1AL <=
                                                         (safe_mod_func_uint32_t_u_u(
                                                             (safe_mul_func_int8_t_s_s(
                                                                 p_53, p_52)),
                                                             p_52))),
                                                        p_54)),
                                                    g_10)) < 0x7AD94609L) &&
                                               l_57[g_11]) ||
                                              g_9) != 4L) <= l_285)),
                                          l_322[5][0])) ^
                                      p_54),
                                     l_163)) == g_10))),
                             6L) ||
                            249UL) == l_253)),
                         11)) >= 0xB193B929L) ||
                    g_148),
                   l_304[3][4])) < g_10) > g_10),
             5L);
      }
      for (p_54 = 0; (p_54 <= 3); p_54 += 1) {
        int i, j;
        l_56 |= ((((l_304[p_54][g_11] |
                    (l_281,
                     ((((((((((((safe_mod_func_uint32_t_u_u(l_163, 1UL)) &&
                                ((l_304[p_54][g_11] == l_163),
                                 (l_304[p_54][g_11],
                                  (safe_add_func_int16_t_s_s(
                                      (0x0F28L &&
                                       ((safe_lshift_func_int16_t_s_s(
                                            ((l_304[3][4] ^ 1L), 6L), g_11)) &&
                                        0x7C5CL)),
                                      g_6))))) ||
                               l_322[4][0]),
                              0xB9AF4620L) > 0x889CA701L) != p_53) ||
                           g_6) != 0xB167L) < g_4) |
                        p_52) ||
                       0x9773L) > g_58))) >= 1L) >= l_304[p_54][g_11]) > (-2L));
      }
      if ((g_11 ==
           ((safe_rshift_func_uint8_t_u_s(
                (p_51,
                 ((safe_sub_func_uint16_t_u_u(
                      ((l_253 ==
                        ((((((safe_sub_func_int32_t_s_s(
                                 (((g_148 &
                                    ((((safe_rshift_func_int16_t_s_s(
                                           (((0xCAL && g_10) ^
                                             (safe_mod_func_int8_t_s_s(
                                                 (safe_mod_func_int8_t_s_s(
                                                     (safe_sub_func_int32_t_s_s(
                                                         (((safe_unary_minus_func_int16_t_s(
                                                               ((g_9 && g_8),
                                                                (safe_mod_func_int32_t_s_s(
                                                                    g_6,
                                                                    1UL))))) <=
                                                           p_55) == 1L),
                                                         g_9)),
                                                     0x83L)),
                                                 l_322[5][0]))) &
                                            l_163),
                                           2)) ^
                                       p_51),
                                      65535UL) != p_52)) <= l_322[5][0]) ||
                                  l_253),
                                 l_284)) &&
                             p_55) > p_54) ||
                           p_51) != 0x385099B4L) != 0x4DL)) > 0x63F3L),
                      0L)) &&
                  p_54)),
                p_55)) |
            0x4B15L))) {
        int16_t l_357 = 0L;
        /* delete */
        l_358 ^=
            (l_253 |
             (((((l_57[3] >
                  (safe_sub_func_uint32_t_u_u(
                      ((safe_rshift_func_uint8_t_u_u(
                           g_9, (l_305 == 4294967291UL))) >=
                       (safe_lshift_func_int8_t_s_s(
                           (g_8 <=
                            (safe_mod_func_int8_t_s_s(
                                0L, (((((g_6 & (((((safe_mul_func_uint16_t_u_u(
                                                       p_55, g_148)) &&
                                                   p_51),
                                                  g_8) &
                                                 l_356) < l_163)) >= g_9) &
                                       3UL) &
                                      g_252) ||
                                     2L)))),
                           5))),
                      0xF36821A4L))) <= l_357),
                l_281) &&
               g_11) &
              0x59L));
        g_6 =
            (l_322[5][0],
             (((((((g_6,
                    (safe_rshift_func_int16_t_s_s(
                        (l_284 <=
                         ((g_148 <= p_53) >
                          (((((p_51 <
                               ((safe_mul_func_int16_t_s_s(
                                    (safe_sub_func_uint8_t_u_u(
                                        g_58,
                                        ((safe_mul_func_uint16_t_u_u(
                                             g_11,
                                             (safe_mod_func_uint32_t_u_u(
                                                 (safe_lshift_func_uint8_t_u_s(
                                                     ((safe_add_func_int8_t_s_s(
                                                          (g_6 == l_56), 1L)) <
                                                      (-2L)),
                                                     l_92)),
                                                 0x9AFD36CDL)))) |
                                         0x02L))),
                                    p_54)) |
                                0L)) != g_4) > g_8) |
                            l_358) == l_57[3]))),
                        0))) != g_11) ||
                  0x80L) > l_92),
                p_55) <= l_303),
              l_57[g_11]));
      } else {
        int32_t l_394 = (-1L);
        int32_t l_397 = 0x80CC1CDAL;
        int32_t l_398 = 0x308EB30CL;
        int8_t l_422 = 0xEFL;
        if ((((safe_sub_func_int16_t_s_s(
                  (p_51, 0L),
                  (p_55 ==
                   (p_52 &&
                    (safe_sub_func_uint8_t_u_u(
                        ((((safe_unary_minus_func_uint8_t_u((
                               ((((safe_rshift_func_int8_t_s_u(
                                      (~(safe_mod_func_uint8_t_u_u(
                                          ((((p_51 !=
                                              (((p_52,
                                                 ((safe_mod_func_int16_t_s_s(
                                                      0xC01FL, 0x0E41L)) >=
                                                  (safe_mod_func_uint32_t_u_u(
                                                      (safe_lshift_func_uint8_t_u_s(
                                                          ((safe_add_func_int8_t_s_s(
                                                               (safe_rshift_func_int16_t_s_u(
                                                                   ((((safe_lshift_func_int8_t_s_s(
                                                                          0L,
                                                                          0)) <=
                                                                      l_356) ^
                                                                     g_4),
                                                                    l_358),
                                                                   8)),
                                                               g_4)) > 4UL),
                                                          4)),
                                                      0x1DCE14E5L)))) < 5UL) &&
                                               l_303)) &&
                                             g_6),
                                            l_57[3]) > l_394),
                                          l_92))),
                                      l_163)),
                                  p_54) < g_252),
                                g_11) ||
                               3UL))) >= p_54) >= l_358) ^
                         0x5E03L),
                        0xF4L)))))) != p_52) ||
             g_11)) {
          for (l_253 = 0; (l_253 >= 14); l_253++) {
            int8_t l_423 = 6L;
            l_400[2]--;
            l_399 = (safe_mod_func_uint16_t_u_u(
                (~((safe_sub_func_uint32_t_u_u(
                       (l_407 ||
                        (safe_sub_func_int16_t_s_s(
                            (safe_sub_func_int8_t_s_s(
                                (safe_rshift_func_uint8_t_u_s(
                                    (l_414,
                                     (safe_unary_minus_func_int8_t_s((
                                         ((((0xFB1646E8L <=
                                             ((p_52 && (1L && (p_53 >= g_9))),
                                              (safe_lshift_func_int8_t_s_u(
                                                  (safe_rshift_func_uint8_t_u_s(
                                                      ((((g_10 &
                                                          (safe_sub_func_int32_t_s_s(
                                                              ((((((((0UL !=
                                                                      p_54) ^
                                                                     g_8) &&
                                                                    l_422),
                                                                   g_6),
                                                                  l_304[3]
                                                                       [4]) <=
                                                                 1UL),
                                                                l_356) == p_51),
                                                              g_148))) !=
                                                         65535UL) != 255UL) ^
                                                       p_52),
                                                      4)),
                                                  g_8)))) ||
                                            0x04L) |
                                           p_52) != l_399) < 0x5AL)))),
                                    g_252)),
                                0x70L)),
                            l_304[3][4]))),
                       g_4)),
                   l_423)),
                p_52));
            l_399 = p_53;
            l_436 |=
                (1UL !=
                 (safe_mod_func_int32_t_s_s(
                     (((g_252 ^ (safe_lshift_func_int16_t_s_u(
                                    l_57[3], (safe_lshift_func_int8_t_s_s(
                                                 (safe_rshift_func_uint16_t_u_u(
                                                     0xD4A1L, 5)),
                                                 7))))) ||
                       (safe_mul_func_uint16_t_u_u(p_55, l_57[3]))) ||
                      (safe_rshift_func_uint16_t_u_u(0x2E94L,
                                                     ((p_54, 2UL) == g_11)))),
                     (-1L))));
          }
        } else {
          const uint16_t l_459 = 65535UL;
          int8_t l_480[3];
          int i;
          /* delete */
          for (l_407 = 0; (l_407 != 18); ++l_407) {
            uint32_t l_460 = 0x3107AC0DL;
            /* delete */
            /* delete */
            /* delete */
          }
        }
      }
      l_358 = l_358;
    } else {
      return g_58;
    }
  }
  return g_8;
}
static int32_t func_62(const uint8_t p_63, int32_t p_64) { return g_10; }
int main(void) {
  int i, j, k;
  int print_hash_value = 0;
  crc32_gentab();
  func_1();
  transparent_crc(g_4, "g_4", print_hash_value);
  transparent_crc(g_6, "g_6", print_hash_value);
  transparent_crc(g_8, "g_8", print_hash_value);
  transparent_crc(g_9, "g_9", print_hash_value);
  transparent_crc(g_10, "g_10", print_hash_value);
  transparent_crc(g_11, "g_11", print_hash_value);
  transparent_crc(g_58, "g_58", print_hash_value);
  transparent_crc(g_148, "g_148", print_hash_value);
  transparent_crc(g_252, "g_252", print_hash_value);
  transparent_crc(g_485, "g_485", print_hash_value);
  transparent_crc(g_515, "g_515", print_hash_value);
  transparent_crc(g_592, "g_592", print_hash_value);
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 6; k++) {
        transparent_crc(g_593[i][j][k], "g_593[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_677, "g_677", print_hash_value);
  transparent_crc(g_806, "g_806", print_hash_value);
  for (i = 0; i < 1; i++) {
    for (j = 0; j < 5; j++) {
      for (k = 0; k < 7; k++) {
        transparent_crc(g_878[i][j][k], "g_878[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_1220, "g_1220", print_hash_value);
  transparent_crc(g_1565, "g_1565", print_hash_value);
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}

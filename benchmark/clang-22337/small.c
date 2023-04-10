typedef unsigned int size_t;
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long long int int64_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;
float fabsf(float a) {
  return -1 * a;
}
float fabs(float a) {
  return -1 * a;
}

int printf(const char *, ...);
void __assert_fail(const char *__assertion, const char *__file,
                   unsigned int __line, const char *__function);
static void platform_main_end(uint32_t crc, int flag) {

  printf("checksum = %X\n", crc);
}
static int8_t(safe_unary_minus_func_int8_t_s)(int8_t si) {

  return

      (si == (-128)) ? ((si)) :

                     -si;
}

static int8_t(safe_add_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((127) - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < ((-128) - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int8_t(safe_sub_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~(127)))) - si2) ^ si2)) < 0)
          ? ((si1))
          :

          (si1 - si2);
}

static int8_t(safe_mul_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((127) / si2))) ||
       ((si1 > 0) && (si2 <= 0) && (si2 < ((-128) / si1))) ||
       ((si1 <= 0) && (si2 > 0) && (si1 < ((-128) / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((127) / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int8_t(safe_mod_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      ((si2 == 0) || ((si1 == (-128)) && (si2 == (-1)))) ? ((si1)) :

                                                         (si1 % si2);
}

static int8_t(safe_div_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return

      ((si2 == 0) || ((si1 == (-128)) && (si2 == (-1)))) ? ((si1)) :

                                                         (si1 / si2);
}

static int8_t(safe_lshift_func_int8_t_s_s)(int8_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((127) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static int8_t(safe_lshift_func_int8_t_s_u)(int8_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32) ||
       (left > ((127) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static int8_t(safe_rshift_func_int8_t_s_s)(int8_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
          ? ((left))
          :

          (left >> ((int)right));
}

static int8_t(safe_rshift_func_int8_t_s_u)(int8_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32))
          ? ((left))
          :

          (left >> ((unsigned int)right));
}

static int16_t(safe_unary_minus_func_int16_t_s)(int16_t si) {

  return

      (si == (-32767 - 1)) ? ((si)) :

                           -si;
}

static int16_t(safe_add_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((32767) - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < ((-32767 - 1) - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int16_t(safe_sub_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~(32767)))) - si2) ^ si2)) < 0)
          ? ((si1))
          :

          (si1 - si2);
}

static int16_t(safe_mul_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((32767) / si2))) ||
       ((si1 > 0) && (si2 <= 0) && (si2 < ((-32767 - 1) / si1))) ||
       ((si1 <= 0) && (si2 > 0) && (si1 < ((-32767 - 1) / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((32767) / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int16_t(safe_mod_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      ((si2 == 0) || ((si1 == (-32767 - 1)) && (si2 == (-1)))) ? ((si1)) :

                                                               (si1 % si2);
}

static int16_t(safe_div_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      ((si2 == 0) || ((si1 == (-32767 - 1)) && (si2 == (-1)))) ? ((si1)) :

                                                               (si1 / si2);
}

static int16_t(safe_lshift_func_int16_t_s_s)(int16_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((32767) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static int16_t(safe_lshift_func_int16_t_s_u)(int16_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32) ||
       (left > ((32767) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static int16_t(safe_rshift_func_int16_t_s_s)(int16_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
          ? ((left))
          :

          (left >> ((int)right));
}

static int16_t(safe_rshift_func_int16_t_s_u)(int16_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32))
          ? ((left))
          :

          (left >> ((unsigned int)right));
}

static int32_t(safe_unary_minus_func_int32_t_s)(int32_t si) {

  return

      (si == (-2147483647 - 1)) ? ((si)) :

                                -si;
}

static int32_t(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < ((-2147483647 - 1) - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int32_t(safe_sub_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~(2147483647)))) - si2) ^ si2)) <
       0)
          ? ((si1))
          :

          (si1 - si2);
}

static int32_t(safe_mul_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) / si2))) ||
       ((si1 > 0) && (si2 <= 0) && (si2 < ((-2147483647 - 1) / si1))) ||
       ((si1 <= 0) && (si2 > 0) && (si1 < ((-2147483647 - 1) / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((2147483647) / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int32_t(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      ((si2 == 0) || ((si1 == (-2147483647 - 1)) && (si2 == (-1)))) ? ((si1)) :

                                                                    (si1 % si2);
}

static int32_t(safe_div_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      ((si2 == 0) || ((si1 == (-2147483647 - 1)) && (si2 == (-1)))) ? ((si1)) :

                                                                    (si1 / si2);
}

static int32_t(safe_lshift_func_int32_t_s_s)(int32_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((2147483647) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static int32_t(safe_lshift_func_int32_t_s_u)(int32_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32) ||
       (left > ((2147483647) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static int32_t(safe_rshift_func_int32_t_s_s)(int32_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
          ? ((left))
          :

          (left >> ((int)right));
}

static int32_t(safe_rshift_func_int32_t_s_u)(int32_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32))
          ? ((left))
          :

          (left >> ((unsigned int)right));
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

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 % ui2);
}

static uint8_t(safe_div_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static uint8_t(safe_lshift_func_uint8_t_u_s)(uint8_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((255) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static uint8_t(safe_lshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > ((255) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static uint8_t(safe_rshift_func_uint8_t_u_s)(uint8_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32)) ? ((left)) :

                                                   (left >> ((int)right));
}

static uint8_t(safe_rshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {

  return

      (((unsigned int)right) >= 32) ? ((left)) :

                                    (left >> ((unsigned int)right));
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

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 % ui2);
}

static uint16_t(safe_div_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static uint16_t(safe_lshift_func_uint16_t_u_s)(uint16_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((65535) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static uint16_t(safe_lshift_func_uint16_t_u_u)(uint16_t left,
                                               unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > ((65535) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static uint16_t(safe_rshift_func_uint16_t_u_s)(uint16_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32)) ? ((left)) :

                                                   (left >> ((int)right));
}

static uint16_t(safe_rshift_func_uint16_t_u_u)(uint16_t left,
                                               unsigned int right) {

  return

      (((unsigned int)right) >= 32) ? ((left)) :

                                    (left >> ((unsigned int)right));
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

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 % ui2);
}

static uint32_t(safe_div_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static uint32_t(safe_lshift_func_uint32_t_u_s)(uint32_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((4294967295U) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static uint32_t(safe_lshift_func_uint32_t_u_u)(uint32_t left,
                                               unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > ((4294967295U) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static uint32_t(safe_rshift_func_uint32_t_u_s)(uint32_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32)) ? ((left)) :

                                                   (left >> ((int)right));
}

static uint32_t(safe_rshift_func_uint32_t_u_u)(uint32_t left,
                                               unsigned int right) {

  return

      (((unsigned int)right) >= 32) ? ((left)) :

                                    (left >> ((unsigned int)right));
}
static float(safe_add_func_float_f_f)(float sf1, float sf2) {

  return

      (fabsf((0.5f * sf1) + (0.5f * sf2)) > (0.5f * 3.40282347e+38F))
          ? (sf1)
          :

          (sf1 + sf2);
}

static float(safe_sub_func_float_f_f)(float sf1, float sf2) {

  return

      (fabsf((0.5f * sf1) - (0.5f * sf2)) > (0.5f * 3.40282347e+38F))
          ? (sf1)
          :

          (sf1 - sf2);
}

static float(safe_mul_func_float_f_f)(float sf1, float sf2) {

  return

      (fabsf((0x1.0p-100f * sf1) * (0x1.0p-28f * sf2)) >
       (0x1.0p-100f * (0x1.0p-28f * 3.40282347e+38F)))
          ? (sf1)
          :

          (sf1 * sf2);
}

static float(safe_div_func_float_f_f)(float sf1, float sf2) {

  return

      ((fabsf(sf2) < 1.0f) &&
       (((sf2 == 0.0f) || (fabsf((0x1.0p-49f * sf1) / (0x1.0p100f * sf2))) >
                              (0x1.0p-100f * (0x1.0p-49f * 3.40282347e+38F)))))
          ? (sf1)
          :

          (sf1 / sf2);
}

static double(safe_add_func_double_f_f)(double sf1, double sf2) {

  return

      (fabs((0.5 * sf1) + (0.5 * sf2)) > (0.5 * 1.7976931348623157e+308))
          ? (sf1)
          :

          (sf1 + sf2);
}

static double(safe_sub_func_double_f_f)(double sf1, double sf2) {

  return

      (fabs((0.5 * sf1) - (0.5 * sf2)) > (0.5 * 1.7976931348623157e+308))
          ? (sf1)
          :

          (sf1 - sf2);
}

static double(safe_mul_func_double_f_f)(double sf1, double sf2) {

  return

      (fabs((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) >
       (0x1.0p-100 * (0x1.0p-924 * 1.7976931348623157e+308)))
          ? (sf1)
          :

          (sf1 * sf2);
}

static double(safe_div_func_double_f_f)(double sf1, double sf2) {

  return

      ((fabs(sf2) < 1.0) &&
       (((sf2 == 0.0) ||
         (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) >
             (0x1.0p-100 * (0x1.0p-974 * 1.7976931348623157e+308)))))
          ? (sf1)
          :

          (sf1 / sf2);
}

static int32_t(safe_convert_func_float_to_int32_t)(float sf1) {

  return

      ((sf1 <= (-2147483647 - 1)) || (sf1 >= (2147483647))) ? ((2147483647)) :

                                                            ((int32_t)(sf1));
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
static void transparent_crc_bytes(char *ptr, int nbytes, char *vname,
                                  int flag) {
  int i;
  for (i = 0; i < nbytes; i++) {
    crc32_byte(ptr[i]);
  }
  if (flag) {
    printf("...checksum after hashing %s : %lX\n", vname,
           crc32_context ^ 0xFFFFFFFFUL);
  }
}

static long __undefined;

static uint16_t g_5 = 0UL;
static uint8_t g_26[2][5] = {{0x72L, 0x37L, 0x09L, 0x09L, 0x37L},
                             {0x72L, 0x37L, 0x09L, 0x09L, 0x37L}};
static uint32_t g_74 = 0UL;
static int16_t g_86 = 0x3F47L;
static uint16_t g_104 = 0UL;
static int8_t g_119 = 0x45L;
static int16_t g_140 = (-1L);
static uint32_t g_147 = 7UL;
static int32_t g_153[10] = {0x50E2895DL, 0x50E2895DL, 0x50E2895DL, 0x50E2895DL,
                            0x50E2895DL, 0x50E2895DL, 0x50E2895DL, 0x50E2895DL,
                            0x50E2895DL, 0x50E2895DL};
static int32_t g_181 = 0xD107391EL;
static int32_t g_182[7] = {(-2L), (-2L), (-2L), (-2L), (-2L), (-2L), (-2L)};
static uint32_t g_212[7][1][8] = {
    {{0x30141AF6L, 0x34180264L, 0x30141AF6L, 1UL, 0x824FA916L, 1UL, 0x30141AF6L,
      0x34180264L}},
    {{0x824FA916L, 1UL, 0x30141AF6L, 0x34180264L, 0x30141AF6L, 1UL, 0x824FA916L,
      1UL}},
    {{0x824FA916L, 0x34180264L, 1UL, 1UL, 0x30141AF6L, 0x34180264L, 0x30141AF6L,
      1UL}},
    {{1UL, 1UL, 1UL, 4294967295UL, 0x30141AF6L, 4294967295UL, 1UL, 1UL}},
    {{0x30141AF6L, 4294967295UL, 1UL, 1UL, 1UL, 4294967295UL, 0x30141AF6L,
      4294967295UL}},
    {{0x30141AF6L, 1UL, 0x824FA916L, 1UL, 0x30141AF6L, 0x34180264L, 0x30141AF6L,
      1UL}},
    {{1UL, 1UL, 1UL, 4294967295UL, 0x30141AF6L, 4294967295UL, 1UL, 1UL}}};
static uint16_t g_238 = 0x404FL;
static int16_t g_255 = 0x6D23L;
static uint32_t g_258 = 0x52CBC31EL;
static int32_t g_283[7] = {0L, (-10L), (-10L), 0L, (-10L), (-10L), 0L};
static uint8_t g_293[4] = {0xD1L, 0xD1L, 0xD1L, 0xD1L};
static uint16_t g_335[6] = {1UL, 1UL, 1UL, 1UL, 1UL, 1UL};
static int32_t g_378[8] = {1L, 1L, 1L, 1L, 1L, 1L, 1L, 1L};
static uint16_t g_395 = 65535UL;
static uint8_t g_438 = 0xC6L;
static int8_t g_466[5] = {0x75L, 0x75L, 0x75L, 0x75L, 0x75L};
static int8_t g_592 = (-10L);
static int16_t g_734 = 1L;
static uint8_t g_1047 = 0xF3L;
static int16_t g_1076 = 0x5469L;
static int8_t g_1185 = 0x49L;
static int8_t g_1254 = 0L;
static uint32_t g_1260 = 4294967289UL;
static int32_t g_1441 = 0x1CA23C94L;
static int8_t g_1462 = 0x15L;
static int32_t g_1519 = (-4L);
static int32_t g_1655 = 0x0FD9268DL;
static uint8_t g_1815 = 0x68L;
static uint32_t g_2295[5] = {7UL, 7UL, 7UL, 7UL, 7UL};
static uint32_t g_2643[4] = {0x14F52DC1L, 0x14F52DC1L, 0x14F52DC1L,
                             0x14F52DC1L};
static int32_t g_2737 = 0xB34F9A53L;
static uint32_t g_2870 = 0x8C521BC3L;
static uint16_t g_2949 = 5UL;
static int32_t g_2982 = (-7L);
static uint8_t g_3025 = 251UL;
static int32_t g_3235[10][5][5] = {
    {{0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L}},
    {{(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)}},
    {{0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L}},
    {{(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)}},
    {{0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L}},
    {{(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)}},
    {{0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L}},
    {{(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)}},
    {{0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L}},
    {{(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)},
     {0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L, 0x8D0BCCD7L},
     {(-4L), (-4L), (-4L), (-4L), (-4L)}}};
static uint16_t g_3442 = 65535UL;
static int8_t g_3652 = 1L;
static uint16_t g_3797[1] = {0x3A03L};
static uint32_t g_3899[8][4][4] = {
    {{0x10D43B0BL, 0x8F7D44D7L, 0x10D43B0BL, 0xEFFAB798L},
     {0x12803B1AL, 5UL, 0x10D43B0BL, 0xC7093FE1L},
     {0x10D43B0BL, 0xC7093FE1L, 0x10D43B0BL, 5UL},
     {0x12803B1AL, 0xEFFAB798L, 0x10D43B0BL, 0x8F7D44D7L}},
    {{0x10D43B0BL, 0x8F7D44D7L, 0x10D43B0BL, 0xEFFAB798L},
     {0x12803B1AL, 5UL, 0x10D43B0BL, 0xC7093FE1L},
     {0x10D43B0BL, 0xC7093FE1L, 0x10D43B0BL, 5UL},
     {0x12803B1AL, 0xEFFAB798L, 0x10D43B0BL, 0x8F7D44D7L}},
    {{0x10D43B0BL, 0x8F7D44D7L, 0x10D43B0BL, 0xEFFAB798L},
     {0x12803B1AL, 5UL, 0x10D43B0BL, 0xC7093FE1L},
     {0x10D43B0BL, 0xC7093FE1L, 0x10D43B0BL, 5UL},
     {0x12803B1AL, 0xEFFAB798L, 0x10D43B0BL, 0x8F7D44D7L}},
    {{0x10D43B0BL, 0x8F7D44D7L, 0x10D43B0BL, 0xEFFAB798L},
     {0x12803B1AL, 5UL, 0x10D43B0BL, 0xC7093FE1L},
     {0x10D43B0BL, 0xC7093FE1L, 0x10D43B0BL, 5UL},
     {0x12803B1AL, 0xEFFAB798L, 0x10D43B0BL, 0x8F7D44D7L}},
    {{0x10D43B0BL, 0x8F7D44D7L, 0x10D43B0BL, 0xEFFAB798L},
     {0x12803B1AL, 5UL, 0x10D43B0BL, 0xC7093FE1L},
     {0x10D43B0BL, 0xC7093FE1L, 0x10D43B0BL, 5UL},
     {0x12803B1AL, 0xEFFAB798L, 0x10D43B0BL, 0x8F7D44D7L}},
    {{0x10D43B0BL, 0x8F7D44D7L, 0x10D43B0BL, 0xEFFAB798L},
     {0x12803B1AL, 5UL, 0x10D43B0BL, 0xC7093FE1L},
     {0x10D43B0BL, 0xC7093FE1L, 0x10D43B0BL, 5UL},
     {0x12803B1AL, 0xEFFAB798L, 0x10D43B0BL, 0x8F7D44D7L}},
    {{0x10D43B0BL, 0x8F7D44D7L, 0x10D43B0BL, 0xEFFAB798L},
     {0x12803B1AL, 5UL, 0x10D43B0BL, 0xC7093FE1L},
     {0x10D43B0BL, 0xC7093FE1L, 0x10D43B0BL, 5UL},
     {0x12803B1AL, 0xEFFAB798L, 0x10D43B0BL, 0x8F7D44D7L}},
    {{0x10D43B0BL, 0x8F7D44D7L, 0x10D43B0BL, 0xEFFAB798L},
     {0x12803B1AL, 5UL, 0x10D43B0BL, 0xC7093FE1L},
     {0x10D43B0BL, 0xC7093FE1L, 0x10D43B0BL, 5UL},
     {0x12803B1AL, 0xEFFAB798L, 0x10D43B0BL, 0x8F7D44D7L}}};
static uint32_t g_3935 = 0x30F5BEB9L;

static uint32_t func_1(void);
static uint32_t func_2(uint32_t p_3, uint8_t p_4);
static uint8_t func_6(uint8_t p_7, uint32_t p_8);
static uint16_t func_13(int32_t p_14, uint8_t p_15);
static int8_t func_18(int8_t p_19, int8_t p_20, uint32_t p_21, uint8_t p_22);
static int32_t func_38(int32_t p_39, uint16_t p_40, uint32_t p_41,
                       uint16_t p_42);
static int16_t func_45(int8_t p_46);
static uint16_t func_62(int32_t p_63, uint32_t p_64, uint32_t p_65);
static int16_t func_77(int32_t p_78);
static uint16_t func_80(uint32_t p_81);
static uint32_t func_1(void) {
  int8_t l_9 = 0x76L;
  int32_t l_12 = 0x9ACD4098L;
  uint32_t l_3683 = 9UL;
  g_3935 &=
      (((func_2(g_5,
                func_6((((-9L) >= l_9) ==
                        (((((l_9 || (safe_rshift_func_int8_t_s_u(0xBCL, 4))) &
                            (l_12 = l_9)),
                           ((l_12 & func_13(l_12, g_5)), 0xAB7CC4E5L)) |
                          g_1185),
                         l_3683)),
                       g_3235[4][4][2])) ||
         l_3683) &&
        g_3899[1][3][3]) == g_378[6]);
  l_12 = (safe_add_func_int32_t_s_s(
      ((safe_mod_func_int8_t_s_s(
           ((((safe_add_func_int16_t_s_s(
                  (l_9 <=
                   ((((safe_rshift_func_int16_t_s_s(
                          (((((g_466[3] >
                               ((safe_div_func_uint8_t_u_u(
                                    (g_3025 =
                                         ((-1L) ||
                                          (safe_rshift_func_int8_t_s_u(
                                              ((safe_rshift_func_uint16_t_u_s(
                                                   ((safe_mod_func_int32_t_s_s(
                                                        (g_438,
                                                         (safe_lshift_func_uint8_t_u_u(
                                                             0UL, 0))),
                                                        g_140)) != g_181),
                                                   8)) ||
                                               (safe_lshift_func_int8_t_s_s(
                                                   (((safe_mod_func_int8_t_s_s(
                                                         ((((((safe_add_func_int8_t_s_s(
                                                                  (~(g_1462 ^=
                                                                     (safe_add_func_uint32_t_u_u(
                                                                         l_3683,
                                                                         ((g_74 |
                                                                           l_3683) ||
                                                                          0x012CDE3FL))))),
                                                                  g_438)) !=
                                                              l_9) ||
                                                             (-6L)) &&
                                                            g_3797[0]) >=
                                                           g_3442) |
                                                          0L),
                                                         0x86L)) ^
                                                     0x09D85AE5L) |
                                                    g_3899[1][3][3]),
                                                   g_283[3]))),
                                              g_293[0])))),
                                    l_3683)) &&
                                g_378[6])) ||
                              g_466[0]) < l_9) < g_1047) ^
                           0xA7D81404L),
                          3)) ^
                      g_212[5][0][2]),
                     g_153[0]) <= 252UL)),
                  l_3683)),
              0x04L) &
             l_3683) > 0UL),
           g_335[0])) &&
       (-1L)),
      l_12));
  return g_1441;
}

static uint32_t func_2(uint32_t p_3, uint8_t p_4) {
  uint32_t l_3686[10][3][2] = {
      {{1UL, 1UL}, {0xE5C6C04AL, 1UL}, {1UL, 4294967289UL}},
      {{4294967289UL, 1UL}, {1UL, 0xE5C6C04AL}, {1UL, 1UL}},
      {{4294967289UL, 4294967289UL}, {1UL, 1UL}, {0xE5C6C04AL, 1UL}},
      {{1UL, 4294967289UL}, {4294967289UL, 1UL}, {1UL, 0xE5C6C04AL}},
      {{1UL, 1UL}, {4294967289UL, 4294967289UL}, {1UL, 1UL}},
      {{0xE5C6C04AL, 1UL}, {1UL, 4294967289UL}, {4294967289UL, 1UL}},
      {{1UL, 0xE5C6C04AL}, {1UL, 1UL}, {4294967289UL, 4294967289UL}},
      {{1UL, 1UL}, {0xE5C6C04AL, 1UL}, {1UL, 4294967289UL}},
      {{4294967289UL, 1UL}, {1UL, 0xE5C6C04AL}, {1UL, 1UL}},
      {{4294967289UL, 4294967289UL}, {1UL, 1UL}, {0xE5C6C04AL, 1UL}}};
  int16_t l_3689 = 0L;
  int32_t l_3696 = 1L;
  int32_t l_3697[1][5][2] = {{{0x6FCCF454L, 1L},
                              {0xFC913FEEL, 0xD4660106L},
                              {1L, 0xD4660106L},
                              {0xFC913FEEL, 1L},
                              {0x6FCCF454L, 0x6FCCF454L}}};
  int32_t l_3710[3];
  uint32_t l_3739 = 0x66F5B7A5L;
  int32_t l_3774 = 1L;
  int8_t l_3852[5][10] = {
      {8L, 0x61L, 8L, 0x61L, 8L, 0x61L, 8L, 0x61L, 8L, 0x61L},
      {8L, 0x61L, 8L, 0x61L, 8L, 0x61L, 8L, 0x61L, 8L, 0x61L},
      {8L, 0x61L, 8L, 0x61L, 8L, 0x61L, 8L, 0x61L, 8L, 0x61L},
      {8L, 0x61L, 8L, 0x61L, 8L, 0x61L, 8L, 0x61L, 8L, 0x61L},
      {8L, 0x61L, 8L, 0x61L, 8L, 0x61L, 8L, 0x61L, 8L, 0x61L}};
  uint16_t l_3862 = 65535UL;
  int32_t l_3874[8][2][1] = {
      {{0x5773D0B4L}, {(-1L)}},       {{0x5773D0B4L}, {9L}},
      {{0x710E7890L}, {0x710E7890L}}, {{9L}, {0x5773D0B4L}},
      {{(-1L)}, {0x5773D0B4L}},       {{9L}, {0x710E7890L}},
      {{0x710E7890L}, {9L}},          {{0x5773D0B4L}, {(-1L)}}};
  int i, j, k;
  for (i = 0; i < 3; i++)
    l_3710[i] = 0L;
  if (((((p_4 > (l_3686[1][2][0] ^= 0xB33E0784L)) <
         ((safe_mod_func_int16_t_s_s(
              ((((l_3689, (-10L)) |
                 ((g_3025--) ^
                  (l_3697[0][3][0] =
                       ((safe_div_func_int8_t_s_s(
                            (p_4,
                             (safe_sub_func_uint16_t_u_u(
                                 (g_395++),
                                 (((safe_rshift_func_int8_t_s_u(
                                       ((g_104 ^= p_4) == l_3697[0][2][0]), 6)),
                                   (safe_add_func_uint16_t_u_u(
                                       ((((safe_add_func_uint16_t_u_u(
                                              ((safe_add_func_uint16_t_u_u(
                                                   65535UL,
                                                   (safe_add_func_uint32_t_u_u(
                                                       ((0xB60DL == 0x82F2L) >=
                                                        g_2295[0]),
                                                       p_3)))) |
                                               l_3689),
                                              g_2295[0])),
                                          g_283[0]) == l_3697[0][0][0]) ||
                                        p_4),
                                       0x509DL))) == g_378[7])))),
                            p_3)) > 3UL)))) == l_3689) &
               l_3696),
              0x6D85L)) ||
          p_4)) > l_3689) != l_3710[2])) {
    for (g_2949 = 0; g_2949 < 5; g_2949 += 1) {
      g_2295[g_2949] = 0x77A946ABL;
    }
  } else {
    int8_t l_3724 = 1L;
    int32_t l_3749 = 0x0023B5CBL;
    int32_t l_3751 = (-3L);
    uint32_t l_3817[9] = {0xAB494884L, 0xAB494884L, 0xAB494884L,
                          0xAB494884L, 0xAB494884L, 0xAB494884L,
                          0xAB494884L, 0xAB494884L, 0xAB494884L};
    uint32_t l_3818 = 0UL;
    int32_t l_3857 = 0x6F330C08L;
    int32_t l_3858[3];
    int i;
    for (i = 0; i < 3; i++)

    {
      for (i = 0; i < 3; i++)
        l_3710[i] = 0L;
    }

    {
      for (g_2949 = 0; g_2949 < 5; g_2949 += 1) {
        g_2295[g_2949] = 0x77A946ABL;
      }
    }

    if ((0x5FL <=
         (4294967295UL <=
          (((0xA600L &
             ((l_3749 =
                   (((safe_sub_func_uint8_t_u_u(
                         (l_3710[2] |
                          ((g_3025--),
                           (safe_lshift_func_int16_t_s_s(
                               ((g_2295[2] = (safe_sub_func_int8_t_s_s(
                                     ((safe_lshift_func_uint16_t_u_s(
                                          ((g_238--) &&
                                           (l_3774 =
                                                (l_3697[0][2][1] =
                                                     (l_3710[1] >
                                                      ((((((safe_add_func_int16_t_s_s(
                                                               l_3749,
                                                               (safe_sub_func_int16_t_s_s(
                                                                   (((safe_rshift_func_uint8_t_u_u(
                                                                         g_86,
                                                                         1)) &&
                                                                     (l_3696 = (safe_div_func_int8_t_s_s(
                                                                          (((p_4 =
                                                                                 p_3) >=
                                                                            (-1L)) ||
                                                                           l_3739),
                                                                          g_378
                                                                              [6])))) >
                                                                    g_258),
                                                                   l_3697
                                                                       [0][2]
                                                                       [1])))) ==
                                                           l_3710[0]) >
                                                          0xB2F6L) |
                                                         l_3724) ||
                                                        0x648A3105L) |
                                                       l_3724))))),
                                          12)) |
                                      l_3710[2]),
                                     g_1815))) < 0x448A4D6CL),
                               8)))),
                         l_3724)),
                     g_1047) ^
                    0UL)) == (-1L))) &&
            p_4) == l_3751)))) {
      int16_t l_3800 = 0x7F44L;
      int32_t l_3802 = 0x0B28B0A5L;
      if (l_3751) {
        int32_t l_3777 = (-1L);
        int32_t l_3786[4][9][4] = {
            {{(-1L), 0x6A80EEA9L, 0xD059880AL, 0L},
             {1L, (-1L), (-4L), 0x6A80EEA9L},
             {1L, 4L, (-4L), 9L},
             {1L, (-9L), 0xD059880AL, 1L},
             {(-1L), 0x9C64C913L, 0xF8846F0AL, 9L},
             {0xF8846F0AL, 9L, 0x71EF8F58L, 0x06E11658L},
             {8L, 0x2EBD0365L, 3L, 3L},
             {(-9L), 0xB31234E2L, 0x0072052BL, 0x5FE6E480L},
             {1L, 0x0072052BL, 0L, 0x5021D0DBL}},
            {{3L, (-1L), 1L, 9L},
             {0xD059880AL, (-4L), 8L, 5L},
             {0x16173EFCL, 1L, 9L, 0x0072052BL},
             {0x891639A2L, 1L, 0xB82FC906L, (-1L)},
             {(-4L), 0x498B5E9BL, (-1L), (-1L)},
             {1L, 1L, 0x891639A2L, 0x2EBD0365L},
             {0xB31234E2L, 0x16173EFCL, (-1L), 0xF8846F0AL},
             {1L, 0xA436A24AL, 1L, (-1L)},
             {1L, 0xA436A24AL, 0x6A3A30D3L, 0xF8846F0AL}},
            {{0xA436A24AL, 0x16173EFCL, 0L, 0x2EBD0365L},
             {4L, 1L, 0x5D074F55L, (-1L)},
             {0x262D3F94L, 0x498B5E9BL, 1L, (-1L)},
             {0x6A3A30D3L, 1L, 0x262D3F94L, 0x0072052BL},
             {(-1L), 1L, 0L, 5L},
             {0L, (-4L), 0L, 9L},
             {0x2EBD0365L, (-1L), 0xBC87CD3AL, 0x5021D0DBL},
             {9L, 0x0072052BL, (-1L), 0x5FE6E480L},
             {0L, 0xB31234E2L, 0x5021D0DBL, 3L}},
            {{3L, 0x2EBD0365L, (-1L), 0x06E11658L},
             {9L, 9L, 0x6A80EEA9L, 9L},
             {0x04619379L, 0x9C64C913L, 0xB31234E2L, 1L},
             {(-1L), (-9L), 1L, 9L},
             {0x71EF8F58L, 4L, 0x7E560AA7L, 0x6A80EEA9L},
             {0x71EF8F58L, (-1L), 1L, 0L},
             {(-1L), 0x6A80EEA9L, 0xB31234E2L, 5L},
             {0x04619379L, 0x1223DDD5L, 0x6A80EEA9L, 0xBC87CD3AL},
             {9L, (-1L), (-1L), 0x71EF8F58L}}};
        uint32_t l_3809 = 0x7ECF4AE9L;
        int i, j, k;
        l_3786[3][4][3] =
            (((safe_lshift_func_int8_t_s_u(
                  l_3777,
                  (((safe_add_func_int16_t_s_s(
                        g_438,
                        ((safe_rshift_func_uint8_t_u_u(
                             ((p_4,
                               (((l_3751 &&
                                  (l_3751 <=
                                   (safe_mod_func_int16_t_s_s(
                                       0x4B6FL, (safe_lshift_func_uint8_t_u_s(
                                                    g_592, 1)))))) > p_3),
                                p_4)),
                              247UL),
                             5)) &&
                         0x3973L))) > g_1076) ^
                   p_4))) >= g_1815) != g_3442);
        {
          for (g_2949 = 0; g_2949 < 5; g_2949 += 1) {
            g_2295[g_2949] = 0x77A946ABL;
          }
        }

        {
          for (g_2949 = 0; g_2949 < 5; g_2949 += 1) {
            g_2295[g_2949] = 0x77A946ABL;
          }
        }

        l_3786[3][4][3] |= (safe_lshift_func_int8_t_s_s(
            (l_3689 | (safe_unary_minus_func_int32_t_s(g_2295[4]))),
            (((g_2295[3] >
               ((((((l_3710[2] =
                         (((l_3774 ||
                            ((safe_unary_minus_func_uint8_t_u(
                                 (safe_mod_func_int32_t_s_s(0L, l_3802)))) ==
                             (((l_3809 |
                                ((safe_lshift_func_uint8_t_u_u(
                                     (((l_3817[1] =
                                            (g_119 =
                                                 (0x91L &&
                                                  (((safe_div_func_uint8_t_u_u(
                                                        ((safe_unary_minus_func_int32_t_s(
                                                             (safe_mod_func_int16_t_s_s(
                                                                 ((l_3802 <=
                                                                   l_3777) >
                                                                  p_3),
                                                                 g_181)))) >
                                                         l_3739),
                                                        g_1185)) <= p_4) &&
                                                   l_3710[2])))) > 0xEAL) ^
                                      g_395),
                                     p_4)),
                                 l_3724)) >= 0x95L) ^
                              l_3689))) |
                           l_3818),
                          g_2737)) <= 4294967293UL) &
                   (-10L)) != 0x27E83AECL) &&
                 g_119),
                p_4)) < 4294967295UL) ^
             p_3)));
        for (g_258 = 5; (g_258 < 37);
             g_258 = safe_add_func_uint16_t_u_u(g_258, 8)) {
          int8_t l_3717 = 3L;
          int32_t l_3725 = (-1L);
          int32_t l_3750[9][10][2] = {{{1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L}},
                                      {{0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L}},
                                      {{1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L}},
                                      {{1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L}},
                                      {{0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L}},
                                      {{1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L}},
                                      {{1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L}},
                                      {{0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L},
                                       {1L, 0xE3208151L},
                                       {1L, 1L},
                                       {0xE3208151L, 1L}},
                                      {{1L, 0xE3208151L},
                                       {1L, 0xE3208151L},
                                       {(-2L), 0xE3208151L},
                                       {0xE3208151L, (-2L)},
                                       {0xE3208151L, 0xE3208151L},
                                       {(-2L), 0xE3208151L},
                                       {0xE3208151L, (-2L)},
                                       {0xE3208151L, 0xE3208151L},
                                       {(-2L), 0xE3208151L},
                                       {0xE3208151L, (-2L)}}};
          int i, j, k;
          g_153[5] ^=
              (((safe_rshift_func_uint8_t_u_s(
                    (safe_div_func_uint32_t_u_u(
                        ((((~l_3717),
                           (safe_lshift_func_int16_t_s_s(
                               (safe_add_func_int16_t_s_s(
                                   (0xF3E3L >
                                    (g_104 =
                                         ((((safe_add_func_int32_t_s_s(
                                                ((g_212[5][0][2] <
                                                  (((g_182[0] >= l_3724) |
                                                    g_182[2]),
                                                   (l_3725 =
                                                        (((g_734 = 0xCAADL) <=
                                                          (-9L)) != 1UL)))) <
                                                 0x9D6C78D6L),
                                                3UL)),
                                            g_1655) == l_3717),
                                          p_4))),
                                   g_335[5])),
                               l_3686[2][0][1]))) != g_2643[0]),
                         g_2949),
                        l_3710[1])),
                    l_3717)) != p_4),
               l_3717);
          l_3725 = p_3;
      g_153
 [0]
 ^=
 ((g_5 && ((l_3696 &= (((safe_lshift_func_int8_t_s_u (((l_3697[0][2][1] |= ((safe_sub_func_int32_t_s_s ((((0x8C5F7811L == (safe_mod_func_uint16_t_u_u ((((((((((((l_3725 = 0L) & ((safe_unary_minus_func_int8_t_s (((safe_mod_func_uint32_t_u_u (((l_3751 &= ((safe_add_func_uint16_t_u_u ((safe_add_func_uint8_t_u_u (l_3717, ((0L >= (4294967293UL < (((((l_3739 > (((l_3750[7][6][0] = (safe_lshift_func_uint8_t_u_s ((safe_div_func_int16_t_s_s ((safe_unary_minus_func_uint32_t_u ((g_3235[4][1][0] == (safe_rshift_func_int16_t_s_u ((((l_3749 = ((safe_lshift_func_uint16_t_u_u ((p_4 < l_3724), 15)) == p_4)) >= g_293[3]) == l_3710[0]), 10))))), l_3717)), g_2295[0]))) < g_283[3]) <= l_3717)) & p_4) != l_3717) && 4294967295UL) ^ p_3))) > 0xCCL))), l_3724)) & g_3235[2][1][2])), l_3751), 0x78E86DB9L)) | 0xF3B6L))), g_5)) < 0xF13FL) <= g_182[0]) < l_3717) < g_182[4]) && p_4) >= 0x791AL) != g_335[5]), 0x2EB1247EL) && 1L), g_5))) > l_3717) & l_3710[2]), 0x62EF9181L)), p_4)) <= 1UL), 2)) && 4294967295UL) <= p_3)), l_3686[1][2][0])) & l_3724);
        }

      } else {
        g_153[6] = 0x9DA2A772L;
      }
      for (g_258 = 5; (g_258 < 37);
           g_258 = safe_add_func_uint16_t_u_u(g_258, 8)) {
        int8_t l_3717 = 3L;
        int32_t l_3725 = (-1L);
        int32_t l_3750[9][10][2] = {{{1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L}},
                                    {{0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L}},
                                    {{1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L}},
                                    {{1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L}},
                                    {{0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L}},
                                    {{1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L}},
                                    {{1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L}},
                                    {{0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L}},
                                    {{1L, 0xE3208151L},
                                     {1L, 0xE3208151L},
                                     {(-2L), 0xE3208151L},
                                     {0xE3208151L, (-2L)},
                                     {0xE3208151L, 0xE3208151L},
                                     {(-2L), 0xE3208151L},
                                     {0xE3208151L, (-2L)},
                                     {0xE3208151L, 0xE3208151L},
                                     {(-2L), 0xE3208151L},
                                     {0xE3208151L, (-2L)}}};
        int i, j, k;
        g_153[5] ^=
            (((safe_rshift_func_uint8_t_u_s(
                  (safe_div_func_uint32_t_u_u(
                      ((((~l_3717),
                         (safe_lshift_func_int16_t_s_s(
                             (safe_add_func_int16_t_s_s(
                                 (0xF3E3L >
                                  (g_104 = ((((safe_add_func_int32_t_s_s(
                                                  ((g_212[5][0][2] <
                                                    (((g_182[0] >= l_3724) |
                                                      g_182[2]),
                                                     (l_3725 =
                                                          (((g_734 = 0xCAADL) <=
                                                            (-9L)) != 1UL)))) <
                                                   0x9D6C78D6L),
                                                  3UL)),
                                              g_1655) == l_3717),
                                            p_4))),
                                 g_335[5])),
                             l_3686[2][0][1]))) != g_2643[0]),
                       g_2949),
                      l_3710[1])),
                  l_3717)) != p_4),
             l_3717);
        l_3725 = p_3;
      g_153
 [0]
 ^=
 ((g_5 && ((l_3696 &= (((safe_lshift_func_int8_t_s_u (((l_3697[0][2][1] |= ((safe_sub_func_int32_t_s_s ((((0x8C5F7811L == (safe_mod_func_uint16_t_u_u ((((((((((((l_3725 = 0L) & ((safe_unary_minus_func_int8_t_s (((safe_mod_func_uint32_t_u_u (((l_3751 &= ((safe_add_func_uint16_t_u_u ((safe_add_func_uint8_t_u_u (l_3717, ((0L >= (4294967293UL < (((((l_3739 > (((l_3750[7][6][0] = (safe_lshift_func_uint8_t_u_s ((safe_div_func_int16_t_s_s ((safe_unary_minus_func_uint32_t_u ((g_3235[4][1][0] == (safe_rshift_func_int16_t_s_u ((((l_3749 = ((safe_lshift_func_uint16_t_u_u ((p_4 < l_3724), 15)) == p_4)) >= g_293[3]) == l_3710[0]), 10))))), l_3717)), g_2295[0]))) < g_283[3]) <= l_3717)) & p_4) != l_3717) && 4294967295UL) ^ p_3))) > 0xCCL))), l_3724)) & g_3235[2][1][2])), l_3751), 0x78E86DB9L)) | 0xF3B6L))), g_5)) < 0xF13FL) <= g_182[0]) < l_3717) < g_182[4]) && p_4) >= 0x791AL) != g_335[5]), 0x2EB1247EL) && 1L), g_5))) > l_3717) & l_3710[2]), 0x62EF9181L)), p_4)) <= 1UL), 2)) && 4294967295UL) <= p_3)), l_3686[1][2][0])) & l_3724);
      }

      return g_153[0];
    } else {
      uint8_t l_3842 = 0xACL;
      uint16_t l_3843 = 1UL;
      int32_t l_3851 = 0L;
      int32_t l_3854 = (-1L);
      int32_t l_3861[4][10] = {
          {8L, 1L, (-10L), (-10L), (-10L), 1L, 8L, 8L, 1L, (-10L)},
          {1L, 8L, 8L, 1L, (-10L), (-10L), (-10L), 1L, 8L, 8L},
          {(-10L), 8L, 1L, 0x98D7280CL, 0x98D7280CL, 1L, 8L, (-10L), 8L, 1L},
          {1L, 8L, (-10L), 8L, 1L, 0x98D7280CL, 0x98D7280CL, 1L, 8L, (-10L)}};
      int8_t l_3896[2][9][4] = {{{0x95L, 0x71L, (-1L), (-1L)},
                                 {0L, 0L, 0x95L, (-1L)},
                                 {(-4L), 0x71L, (-4L), 0x95L},
                                 {(-4L), 0x95L, 0x95L, (-4L)},
                                 {0L, 0x95L, (-1L), 0x95L},
                                 {0x95L, 0x71L, (-1L), (-1L)},
                                 {0L, 0L, 0x95L, (-1L)},
                                 {(-4L), 0x71L, (-4L), 0x95L},
                                 {(-4L), 0x95L, 0x95L, (-4L)}},
                                {{0L, 0x95L, (-1L), 0x95L},
                                 {0x95L, 0x71L, (-1L), (-1L)},
                                 {0L, 0L, 0x95L, (-1L)},
                                 {(-4L), 0x71L, (-4L), 0x95L},
                                 {(-4L), 0x95L, 0x95L, (-4L)},
                                 {0L, 0x95L, (-1L), 0x95L},
                                 {0x95L, 0x71L, (-1L), (-1L)},
                                 {0L, 0L, 0x95L, (-1L)},
                                 {(-4L), 0x71L, (-4L), 0x95L}}};
      int i, j, k;
      g_153[8] |= 0x8FC4BD16L;
      for (g_258 = 5; (g_258 < 37);
           g_258 = safe_add_func_uint16_t_u_u(g_258, 8)) {
        int8_t l_3717 = 3L;
        int32_t l_3725 = (-1L);
        int32_t l_3750[9][10][2] = {{{1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L}},
                                    {{0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L}},
                                    {{1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L}},
                                    {{1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L}},
                                    {{0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L}},
                                    {{1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L}},
                                    {{1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L}},
                                    {{0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L}},
                                    {{1L, 0xE3208151L},
                                     {1L, 0xE3208151L},
                                     {(-2L), 0xE3208151L},
                                     {0xE3208151L, (-2L)},
                                     {0xE3208151L, 0xE3208151L},
                                     {(-2L), 0xE3208151L},
                                     {0xE3208151L, (-2L)},
                                     {0xE3208151L, 0xE3208151L},
                                     {(-2L), 0xE3208151L},
                                     {0xE3208151L, (-2L)}}};
        int i, j, k;
        g_153[5] ^=
            (((safe_rshift_func_uint8_t_u_s(
                  (safe_div_func_uint32_t_u_u(
                      ((((~l_3717),
                         (safe_lshift_func_int16_t_s_s(
                             (safe_add_func_int16_t_s_s(
                                 (0xF3E3L >
                                  (g_104 = ((((safe_add_func_int32_t_s_s(
                                                  ((g_212[5][0][2] <
                                                    (((g_182[0] >= l_3724) |
                                                      g_182[2]),
                                                     (l_3725 =
                                                          (((g_734 = 0xCAADL) <=
                                                            (-9L)) != 1UL)))) <
                                                   0x9D6C78D6L),
                                                  3UL)),
                                              g_1655) == l_3717),
                                            p_4))),
                                 g_335[5])),
                             l_3686[2][0][1]))) != g_2643[0]),
                       g_2949),
                      l_3710[1])),
                  l_3717)) != p_4),
             l_3717);
        l_3725 = p_3;
      g_153
 [0]
 ^=
 ((g_5 && ((l_3696 &= (((safe_lshift_func_int8_t_s_u (((l_3697[0][2][1] |= ((safe_sub_func_int32_t_s_s ((((0x8C5F7811L == (safe_mod_func_uint16_t_u_u ((((((((((((l_3725 = 0L) & ((safe_unary_minus_func_int8_t_s (((safe_mod_func_uint32_t_u_u (((l_3751 &= ((safe_add_func_uint16_t_u_u ((safe_add_func_uint8_t_u_u (l_3717, ((0L >= (4294967293UL < (((((l_3739 > (((l_3750[7][6][0] = (safe_lshift_func_uint8_t_u_s ((safe_div_func_int16_t_s_s ((safe_unary_minus_func_uint32_t_u ((g_3235[4][1][0] == (safe_rshift_func_int16_t_s_u ((((l_3749 = ((safe_lshift_func_uint16_t_u_u ((p_4 < l_3724), 15)) == p_4)) >= g_293[3]) == l_3710[0]), 10))))), l_3717)), g_2295[0]))) < g_283[3]) <= l_3717)) & p_4) != l_3717) && 4294967295UL) ^ p_3))) > 0xCCL))), l_3724)) & g_3235[2][1][2])), l_3751), 0x78E86DB9L)) | 0xF3B6L))), g_5)) < 0xF13FL) <= g_182[0]) < l_3717) < g_182[4]) && p_4) >= 0x791AL) != g_335[5]), 0x2EB1247EL) && 1L), g_5))) > l_3717) & l_3710[2]), 0x62EF9181L)), p_4)) <= 1UL), 2)) && 4294967295UL) <= p_3)), l_3686[1][2][0])) & l_3724);
      }

      for (g_3652 = 0; (g_3652 >= 0); g_3652 -= 1) {
        int32_t l_3840 = 0x5D5C0F38L;
        uint32_t l_3841 = 0x5A98E1D2L;
        int32_t l_3844 = 0x36512728L;
        int16_t l_3850[1][5][8] = {
            {{0L, (-1L), 0xDFD5L, 0xEBA3L, (-1L), 0x2A54L, 1L, 0x7558L},
             {0x02E6L, 0x3615L, 0x2A54L, 0xEBA3L, 0x4A45L, 0xEBA3L, 0x2A54L,
              0x3615L},
             {1L, 0x4A45L, 5L, 0x59F3L, 0x7558L, 0xA12CL, 0x02E6L, 0x85A5L},
             {0x59F3L, 0L, 0x3615L, 5L, 1L, 0x02E6L, 0x02E6L, 1L},
             {0xA12CL, 5L, 5L, 0xA12CL, 0x3615L, 0x7558L, 0x2A54L, 0x3458L}}};
        int32_t l_3853 = 0x461BB2F5L;
        int32_t l_3856[6][4][10] = {
            {{6L, 0x414EE073L, 0xCEC088D0L, 1L, (-5L), (-4L), 0xFF3E70A6L,
              (-1L), (-8L), 0xEBB7DD63L},
             {(-8L), 0xD8ED7100L, 1L, 0xB6D94CCFL, (-1L), 0xDEE0228AL,
              0x4C86CA63L, 8L, 0x0BCF90FFL, 0xF8CC614EL},
             {0x48798598L, 8L, 0x70C2554DL, 5L, 0x905C3133L, 2L, 0xCC0DF21BL,
              0x25928902L, (-8L), 0x0BED6334L},
             {0xB6D94CCFL, 0x15ABFD11L, 0xD63AE329L, 0L, 0xD6C44439L,
              0x0A4FEFF5L, (-1L), 1L, 8L, (-8L)}},
            {{2L, 0L, 0xB2329A9EL, 3L, 0x25928902L, 0x96A521F1L, 8L, (-5L), 1L,
              (-5L)},
             {0x40BA7C4BL, 0xAFD1776AL, 0xDEE0228AL, 8L, 0xDEE0228AL,
              0xAFD1776AL, 0x40BA7C4BL, 0x13EE9084L, 6L, (-2L)},
             {0xC8573EF2L, 0xD2039BCFL, 1L, 1L, 0x3351E9D3L, 1L, 0x2D672D44L,
              (-3L), 0x0702DCABL, 0L},
             {0L, 0x40BA7C4BL, 4L, (-1L), 0L, (-3L), 0xDEE0228AL, 1L, 1L,
              0x853ACD20L}},
            {{0x97DBC3AAL, (-4L), 0x5DD1449DL, 0x15ABFD11L, 0x414EE073L, 7L,
              (-1L), 0xEAFB1385L, 0xDEE0228AL, 1L},
             {0xD8ED7100L, 0x414EE073L, (-1L), 8L, 7L, 0xD2039BCFL, 0x2F571873L,
              (-4L), (-1L), 7L},
             {0L, 0x3351E9D3L, 0L, 0xEAC53225L, 0xB2329A9EL, 0x0BED6334L,
              0x4E769EF0L, 0xD2039BCFL, 0xDEACFE02L, 1L},
             {0x60DA0CC5L, 1L, 5L, 0x89A92BFBL, 0xCEAA265BL, (-8L), 0xCB74D84FL,
              6L, 0x8CC82C4EL, 0x15ABFD11L}},
            {{0x853ACD20L, 0xAA2F44FFL, 0L, 0x3288010AL, (-1L), 0x8CC82C4EL,
              0xCEAA265BL, 0x905C3133L, 0xF8CC614EL, 3L},
             {8L, 0xEAFB1385L, 0x656AE0EFL, 1L, 0x60FC2C0AL, 0xCEAA265BL, 1L,
              0xEB9DA192L, 0L, 0x23FF46F2L},
             {0xC8573EF2L, 1L, 0xCB74D84FL, 0x08FD2435L, 6L, 1L, 0x0702DCABL,
              0x97DBC3AAL, (-1L), 0x25928902L},
             {0L, 2L, (-8L), 0xDEACFE02L, 0xFF3E70A6L, 0xEBB7DD63L, 8L,
              0xAA2F44FFL, (-2L), (-1L)}},
            {{0x2B4D469BL, 0xD6C44439L, 7L, 1L, (-8L), (-8L), 1L, 7L,
              0xD6C44439L, 0x2B4D469BL},
             {0x414EE073L, 0x0A4FEFF5L, (-3L), 0x4A45BC9CL, (-9L), 8L,
              0xC8573EF2L, 4L, 1L, 5L},
             {(-5L), 0xDDF8DA20L, 0x23FF46F2L, 0x0A4FEFF5L, (-9L), 0x890B3456L,
              3L, 0xCEAA265BL, 0xBDB50373L, 0x2B4D469BL},
             {(-9L), 0xC8573EF2L, (-2L), 0x2F571873L, (-8L), (-1L), 0x656AE0EFL,
              0x4E769EF0L, (-4L), (-1L)}},
            {{(-8L), 0x23FF46F2L, (-9L), 4L, 0xFF3E70A6L, 0x6A879EDBL, 1L,
              0xB6D94CCFL, 0x890B3456L, 0x25928902L},
             {0xCB74D84FL, 8L, 0x3351E9D3L, (-8L), 6L, 0xEAFB1385L, 1L,
              0x2D8E8956L, 0L, 0x23FF46F2L},
             {1L, (-10L), 0x0A4FEFF5L, 1L, 0x60FC2C0AL, 1L, 0x4A45BC9CL, 8L, 0L,
              3L},
             {0x0702DCABL, 5L, 8L, 0L, (-1L), 0L, 0x60DA0CC5L, 0L, 7L,
              0x15ABFD11L}}};
        int16_t l_3894 = 0L;
        int32_t l_3897[3][8] = {
            {(-1L), 1L, (-1L), (-1L), 1L, (-1L), (-1L), 1L},
            {1L, (-1L), (-1L), 1L, (-1L), (-1L), 1L, (-1L)},
            {1L, 1L, 0x06E16F32L, (-1L), (-1L), 1L, (-1L), (-1L)}};
        int i, j, k;
        for (g_104 = 0; (g_104 <= 0); g_104 += 1) {
          int32_t l_3835 = 0x079A24FAL;
          int32_t l_3846 = 1L;
          int32_t l_3848 = 8L;
          int32_t l_3849 = 0x9F309731L;
          uint32_t l_3865 = 0xF9D97247L;
          int i;
          for (l_3774 = 1; (l_3774 >= 0); l_3774 -= 1) {
            int i;
            if (l_3817[(g_104 + 7)])
              break;
          }

          {
            int32_t l_3840 = 0x5D5C0F38L;
            uint32_t l_3841 = 0x5A98E1D2L;
            int32_t l_3844 = 0x36512728L;
            int16_t l_3850[1][5][8] = {
                {{0L, (-1L), 0xDFD5L, 0xEBA3L, (-1L), 0x2A54L, 1L, 0x7558L},
                 {0x02E6L, 0x3615L, 0x2A54L, 0xEBA3L, 0x4A45L, 0xEBA3L, 0x2A54L,
                  0x3615L},
                 {1L, 0x4A45L, 5L, 0x59F3L, 0x7558L, 0xA12CL, 0x02E6L, 0x85A5L},
                 {0x59F3L, 0L, 0x3615L, 5L, 1L, 0x02E6L, 0x02E6L, 1L},
                 {0xA12CL, 5L, 5L, 0xA12CL, 0x3615L, 0x7558L, 0x2A54L,
                  0x3458L}}};
            int32_t l_3853 = 0x461BB2F5L;
            int32_t l_3856[6][4][10] = {
                {{6L, 0x414EE073L, 0xCEC088D0L, 1L, (-5L), (-4L), 0xFF3E70A6L,
                  (-1L), (-8L), 0xEBB7DD63L},
                 {(-8L), 0xD8ED7100L, 1L, 0xB6D94CCFL, (-1L), 0xDEE0228AL,
                  0x4C86CA63L, 8L, 0x0BCF90FFL, 0xF8CC614EL},
                 {0x48798598L, 8L, 0x70C2554DL, 5L, 0x905C3133L, 2L,
                  0xCC0DF21BL, 0x25928902L, (-8L), 0x0BED6334L},
                 {0xB6D94CCFL, 0x15ABFD11L, 0xD63AE329L, 0L, 0xD6C44439L,
                  0x0A4FEFF5L, (-1L), 1L, 8L, (-8L)}},
                {{2L, 0L, 0xB2329A9EL, 3L, 0x25928902L, 0x96A521F1L, 8L, (-5L),
                  1L, (-5L)},
                 {0x40BA7C4BL, 0xAFD1776AL, 0xDEE0228AL, 8L, 0xDEE0228AL,
                  0xAFD1776AL, 0x40BA7C4BL, 0x13EE9084L, 6L, (-2L)},
                 {0xC8573EF2L, 0xD2039BCFL, 1L, 1L, 0x3351E9D3L, 1L,
                  0x2D672D44L, (-3L), 0x0702DCABL, 0L},
                 {0L, 0x40BA7C4BL, 4L, (-1L), 0L, (-3L), 0xDEE0228AL, 1L, 1L,
                  0x853ACD20L}},
                {{0x97DBC3AAL, (-4L), 0x5DD1449DL, 0x15ABFD11L, 0x414EE073L, 7L,
                  (-1L), 0xEAFB1385L, 0xDEE0228AL, 1L},
                 {0xD8ED7100L, 0x414EE073L, (-1L), 8L, 7L, 0xD2039BCFL,
                  0x2F571873L, (-4L), (-1L), 7L},
                 {0L, 0x3351E9D3L, 0L, 0xEAC53225L, 0xB2329A9EL, 0x0BED6334L,
                  0x4E769EF0L, 0xD2039BCFL, 0xDEACFE02L, 1L},
                 {0x60DA0CC5L, 1L, 5L, 0x89A92BFBL, 0xCEAA265BL, (-8L),
                  0xCB74D84FL, 6L, 0x8CC82C4EL, 0x15ABFD11L}},
                {{0x853ACD20L, 0xAA2F44FFL, 0L, 0x3288010AL, (-1L), 0x8CC82C4EL,
                  0xCEAA265BL, 0x905C3133L, 0xF8CC614EL, 3L},
                 {8L, 0xEAFB1385L, 0x656AE0EFL, 1L, 0x60FC2C0AL, 0xCEAA265BL,
                  1L, 0xEB9DA192L, 0L, 0x23FF46F2L},
                 {0xC8573EF2L, 1L, 0xCB74D84FL, 0x08FD2435L, 6L, 1L,
                  0x0702DCABL, 0x97DBC3AAL, (-1L), 0x25928902L},
                 {0L, 2L, (-8L), 0xDEACFE02L, 0xFF3E70A6L, 0xEBB7DD63L, 8L,
                  0xAA2F44FFL, (-2L), (-1L)}},
                {{0x2B4D469BL, 0xD6C44439L, 7L, 1L, (-8L), (-8L), 1L, 7L,
                  0xD6C44439L, 0x2B4D469BL},
                 {0x414EE073L, 0x0A4FEFF5L, (-3L), 0x4A45BC9CL, (-9L), 8L,
                  0xC8573EF2L, 4L, 1L, 5L},
                 {(-5L), 0xDDF8DA20L, 0x23FF46F2L, 0x0A4FEFF5L, (-9L),
                  0x890B3456L, 3L, 0xCEAA265BL, 0xBDB50373L, 0x2B4D469BL},
                 {(-9L), 0xC8573EF2L, (-2L), 0x2F571873L, (-8L), (-1L),
                  0x656AE0EFL, 0x4E769EF0L, (-4L), (-1L)}},
                {{(-8L), 0x23FF46F2L, (-9L), 4L, 0xFF3E70A6L, 0x6A879EDBL, 1L,
                  0xB6D94CCFL, 0x890B3456L, 0x25928902L},
                 {0xCB74D84FL, 8L, 0x3351E9D3L, (-8L), 6L, 0xEAFB1385L, 1L,
                  0x2D8E8956L, 0L, 0x23FF46F2L},
                 {1L, (-10L), 0x0A4FEFF5L, 1L, 0x60FC2C0AL, 1L, 0x4A45BC9CL, 8L,
                  0L, 3L},
                 {0x0702DCABL, 5L, 8L, 0L, (-1L), 0L, 0x60DA0CC5L, 0L, 7L,
                  0x15ABFD11L}}};
            int16_t l_3894 = 0L;
            int32_t l_3897[3][8] = {
                {(-1L), 1L, (-1L), (-1L), 1L, (-1L), (-1L), 1L},
                {1L, (-1L), (-1L), 1L, (-1L), (-1L), 1L, (-1L)},
                {1L, 1L, 0x06E16F32L, (-1L), (-1L), 1L, (-1L), (-1L)}};
            int i, j, k;
            for (g_104 = 0; (g_104 <= 0); g_104 += 1) {
              int32_t l_3835 = 0x079A24FAL;
              int32_t l_3846 = 1L;
              int32_t l_3848 = 8L;
              int32_t l_3849 = 0x9F309731L;
              uint32_t l_3865 = 0xF9D97247L;
              int i;
              for (l_3774 = 1; (l_3774 >= 0); l_3774 -= 1) {
                int i;
                if (l_3817[(g_104 + 7)])
                  break;
              }
              for (g_734 = 1; (g_734 >= 0); g_734 -= 1) {
                int32_t l_3845 = 0xA4102868L;
                int32_t l_3847 = (-2L);
                int32_t l_3855 = 1L;
                int32_t l_3859 = 0L;
                int32_t l_3860 = 1L;
                int i, j, k;
                l_3844 = (safe_div_func_uint16_t_u_u(
                    l_3817[(g_734 + 4)],
                    (safe_mod_func_int8_t_s_s(
                        (((l_3749 ^= (safe_rshift_func_int8_t_s_u(
                               l_3817[(g_104 + 5)], 1))) >
                          (safe_lshift_func_int16_t_s_s(
                              (((l_3817[(g_734 + 6)] ||
                                 (l_3817[(g_104 + 1)] >
                                  (l_3843 = (safe_lshift_func_int16_t_s_u(
                                       (l_3842 =
                                            ((g_1462 <
                                              ((g_283[5] &=
                                                ((safe_rshift_func_uint8_t_u_s(
                                                     (safe_div_func_uint8_t_u_u(
                                                         ((g_26[g_734][(g_104 +
                                                                        1)] =
                                                               ((g_1185 =
                                                                     (l_3751 =
                                                                          (((safe_rshift_func_uint8_t_u_u(
                                                                                ((l_3835 =
                                                                                      p_4) !=
                                                                                 (safe_lshift_func_uint16_t_u_u(
                                                                                     p_3,
                                                                                     ((p_4 ==
                                                                                       ((g_212[(
                                                                                            g_104 +
                                                                                            4)]
                                                                                              [g_3652]
                                                                                              [g_734]--) |
                                                                                        ((g_466[0] =
                                                                                              0x84L) >=
                                                                                         g_2949))) <
                                                                                      0xE6AF7225L)))),
                                                                                0)) ==
                                                                            l_3840) &
                                                                           l_3841))) ==
                                                                1L)) ||
                                                          (-4L)),
                                                         p_3)),
                                                     l_3817[(g_104 + 5)])) &
                                                 0x5CL)),
                                               g_466[1])) !=
                                             l_3817[(g_734 + 6)])),
                                       11))))) &
                                0x3DL) > l_3739),
                              10))) |
                         0x6F17L),
                        0x12L))));
                --l_3862;
                l_3865++;
                l_3846 |=
                    (l_3844 =
                         (((g_3652 && 65535UL),
                           (~(safe_mod_func_uint8_t_u_u(
                               (safe_div_func_uint8_t_u_u(
                                   (safe_add_func_uint8_t_u_u(p_3, 0xCCL)),
                                   0xC9L)),
                               0xD0L)))) >=
                          (l_3852[0][9] ==
                           ((g_2643[3] > ((g_438 = (g_293[2] = p_4)) & l_3841)),
                            l_3874[4][0][0]))));
              }
              l_3835 = l_3817[(g_3652 + 1)];
              if (l_3817[(g_3652 + 4)])
                break;
              for (l_3751 = 1; (l_3751 >= 0); l_3751 -= 1) {
                return p_4;
              }
            }
            for (g_1260 = 0; (g_1260 <= 0); g_1260 += 1) {
              uint32_t l_3875[9][8] = {
                  {0x3DF852EAL, 0xD415547CL, 0x3DF852EAL, 4294967295UL,
                   0xD415547CL, 0x14533909L, 0x14533909L, 0xD415547CL},
                  {0xD415547CL, 0x14533909L, 0x14533909L, 0xD415547CL,
                   4294967295UL, 0x3DF852EAL, 0xD415547CL, 0x3DF852EAL},
                  {0xD415547CL, 4UL, 0x1D2F4715L, 4UL, 0xD415547CL, 0x1D2F4715L,
                   0x1CCF0451L, 0x1CCF0451L},
                  {0x3DF852EAL, 4UL, 4294967295UL, 4294967295UL, 4UL,
                   0x3DF852EAL, 0x14533909L, 4UL},
                  {0x1CCF0451L, 0x14533909L, 4294967295UL, 0x1CCF0451L,
                   4294967295UL, 0x14533909L, 0x1CCF0451L, 0x3DF852EAL},
                  {4UL, 0xD415547CL, 0x1D2F4715L, 0x1CCF0451L, 0x1CCF0451L,
                   0x1D2F4715L, 0xD415547CL, 4UL},
                  {0x3DF852EAL, 0x1CCF0451L, 0x14533909L, 4294967295UL,
                   0x1CCF0451L, 4294967295UL, 0x14533909L, 0x1CCF0451L},
                  {4UL, 0x14533909L, 0x3DF852EAL, 4UL, 4294967295UL,
                   4294967295UL, 4UL, 0x3DF852EAL},
                  {0x1CCF0451L, 0x1CCF0451L, 0x1D2F4715L, 0xD415547CL, 4UL,
                   0x1D2F4715L, 4UL, 0xD415547CL}};
              int8_t l_3895[4][10] = {
                  {0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L},
                  {0L, 0L, 0xCDL, 0L, 0L, 0xCDL, 0L, 0L, 0xCDL, 0L},
                  {0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L},
                  {0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L}};
              int32_t l_3898[9][4] = {{(-1L), 1L, 0x3CF8A80CL, 0L},
                                      {1L, 0xAEDA39EBL, 0xAEDA39EBL, 1L},
                                      {0x85DE5D23L, 0L, 0xAEDA39EBL, 0L},
                                      {1L, (-1L), 0x3CF8A80CL, (-1L)},
                                      {(-1L), 0xAEDA39EBL, 0x85DE5D23L, (-1L)},
                                      {0x85DE5D23L, (-1L), 0L, 0L},
                                      {0L, 0L, 0x3CF8A80CL, 1L},
                                      {0L, 0xAEDA39EBL, 0L, 0L},
                                      {0x85DE5D23L, 1L, 0x85DE5D23L, 0L}};
              int i, j;
              if (l_3875[7][1])
                break;
   l_3897
     [1]
     [3]
     =
     (g_26
      [1]
      [1]
      |
      (((((!(+((g_466[2] &= l_3739) != ((safe_rshift_func_uint8_t_u_u (((((safe_lshift_func_uint16_t_u_s ((((l_3896[1][0][0] = (((!(safe_mod_func_int16_t_s_s (((p_3 <= 0xC19FE0FAL) != (safe_sub_func_uint16_t_u_u ((safe_sub_func_int8_t_s_s ((l_3844 = (safe_mod_func_uint8_t_u_u (((l_3841 && ((l_3844 >= ((safe_unary_minus_func_uint8_t_u ((safe_rshift_func_uint16_t_u_s ((!(safe_add_func_int16_t_s_s ((l_3853 = (((0x28L >= (((((l_3856[4][3][4] |= (g_255 |= ((+(safe_unary_minus_func_uint32_t_u ((p_4, (((l_3894 != p_4) | g_212[5][0][5]) & l_3850[0][0][4]))))) >= p_3))) && l_3895[2][2]) != l_3710[2]) & p_4) >= l_3894)) < 0x68722F69L) <= l_3875[7][1])), l_3858[0]))), l_3850[0][1][5])))) != g_3797[0])) != g_182[0])) || p_3), p_3))), 0x42L)), 0UL))), g_283[2]))) == l_3875[5][6]) > g_3652)) | p_4) <= l_3843), 0)) > g_182[0]), l_3874[0][0][0]) == p_4), 4)), g_2982)))) <= l_3850[0][0][4]) != 0L) >= 0x05D04FBFL), l_3774));
   ++g_3899[1][3][3];
   for (g_86 = 0; (g_86 <= 8); g_86 += 1) {
     if (l_3895[2][2])
       break;
   }
            }
          }

          l_3835 = l_3817[(g_3652 + 1)];
          if (l_3817[(g_3652 + 4)])

          {
            g_153[8] |= 0x8FC4BD16L;
          }

          for (i = 0; i < 3; i++)
            l_3710[i] = 0L;
        }
        for (g_1260 = 0; (g_1260 <= 0); g_1260 += 1) {
          uint32_t l_3875[9][8] = {
              {0x3DF852EAL, 0xD415547CL, 0x3DF852EAL, 4294967295UL, 0xD415547CL,
               0x14533909L, 0x14533909L, 0xD415547CL},
              {0xD415547CL, 0x14533909L, 0x14533909L, 0xD415547CL, 4294967295UL,
               0x3DF852EAL, 0xD415547CL, 0x3DF852EAL},
              {0xD415547CL, 4UL, 0x1D2F4715L, 4UL, 0xD415547CL, 0x1D2F4715L,
               0x1CCF0451L, 0x1CCF0451L},
              {0x3DF852EAL, 4UL, 4294967295UL, 4294967295UL, 4UL, 0x3DF852EAL,
               0x14533909L, 4UL},
              {0x1CCF0451L, 0x14533909L, 4294967295UL, 0x1CCF0451L,
               4294967295UL, 0x14533909L, 0x1CCF0451L, 0x3DF852EAL},
              {4UL, 0xD415547CL, 0x1D2F4715L, 0x1CCF0451L, 0x1CCF0451L,
               0x1D2F4715L, 0xD415547CL, 4UL},
              {0x3DF852EAL, 0x1CCF0451L, 0x14533909L, 4294967295UL, 0x1CCF0451L,
               4294967295UL, 0x14533909L, 0x1CCF0451L},
              {4UL, 0x14533909L, 0x3DF852EAL, 4UL, 4294967295UL, 4294967295UL,
               4UL, 0x3DF852EAL},
              {0x1CCF0451L, 0x1CCF0451L, 0x1D2F4715L, 0xD415547CL, 4UL,
               0x1D2F4715L, 4UL, 0xD415547CL}};
          int8_t l_3895[4][10] = {
              {0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L},
              {0L, 0L, 0xCDL, 0L, 0L, 0xCDL, 0L, 0L, 0xCDL, 0L},
              {0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L},
              {0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L}};
          int32_t l_3898[9][4] = {{(-1L), 1L, 0x3CF8A80CL, 0L},
                                  {1L, 0xAEDA39EBL, 0xAEDA39EBL, 1L},
                                  {0x85DE5D23L, 0L, 0xAEDA39EBL, 0L},
                                  {1L, (-1L), 0x3CF8A80CL, (-1L)},
                                  {(-1L), 0xAEDA39EBL, 0x85DE5D23L, (-1L)},
                                  {0x85DE5D23L, (-1L), 0L, 0L},
                                  {0L, 0L, 0x3CF8A80CL, 1L},
                                  {0L, 0xAEDA39EBL, 0L, 0L},
                                  {0x85DE5D23L, 1L, 0x85DE5D23L, 0L}};
          int i, j;

          l_3710[i] = 0L;

          {
            int32_t l_3835 = 0x079A24FAL;
            int32_t l_3846 = 1L;
            int32_t l_3848 = 8L;
            int32_t l_3849 = 0x9F309731L;
            uint32_t l_3865 = 0xF9D97247L;
            int i;
            for (l_3774 = 1; (l_3774 >= 0); l_3774 -= 1) {
              int i;
              if (l_3817[(g_104 + 7)])
                break;
            }
            for (g_734 = 1; (g_734 >= 0); g_734 -= 1) {
              int32_t l_3845 = 0xA4102868L;
              int32_t l_3847 = (-2L);
              int32_t l_3855 = 1L;
              int32_t l_3859 = 0L;
              int32_t l_3860 = 1L;
              int i, j, k;
              l_3844 = (safe_div_func_uint16_t_u_u(
                  l_3817[(g_734 + 4)],
                  (safe_mod_func_int8_t_s_s(
                      (((l_3749 ^= (safe_rshift_func_int8_t_s_u(
                             l_3817[(g_104 + 5)], 1))) >
                        (safe_lshift_func_int16_t_s_s(
                            (((l_3817[(g_734 + 6)] ||
                               (l_3817[(g_104 + 1)] >
                                (l_3843 = (safe_lshift_func_int16_t_s_u(
                                     (l_3842 =
                                          ((g_1462 <
                                            ((g_283[5] &=
                                              ((safe_rshift_func_uint8_t_u_s(
                                                   (safe_div_func_uint8_t_u_u(
                                                       ((g_26[g_734][(g_104 +
                                                                      1)] =
                                                             ((g_1185 =
                                                                   (l_3751 =
                                                                        (((safe_rshift_func_uint8_t_u_u(
                                                                              ((l_3835 =
                                                                                    p_4) !=
                                                                               (safe_lshift_func_uint16_t_u_u(
                                                                                   p_3,
                                                                                   ((p_4 ==
                                                                                     ((g_212[(
                                                                                          g_104 +
                                                                                          4)]
                                                                                            [g_3652]
                                                                                            [g_734]--) |
                                                                                      ((g_466[0] =
                                                                                            0x84L) >=
                                                                                       g_2949))) <
                                                                                    0xE6AF7225L)))),
                                                                              0)) ==
                                                                          l_3840) &
                                                                         l_3841))) ==
                                                              1L)) ||
                                                        (-4L)),
                                                       p_3)),
                                                   l_3817[(g_104 + 5)])) &
                                               0x5CL)),
                                             g_466[1])) !=
                                           l_3817[(g_734 + 6)])),
                                     11))))) &
                              0x3DL) > l_3739),
                            10))) |
                       0x6F17L),
                      0x12L))));
              --l_3862;
              l_3865++;
              l_3846 |=
                  (l_3844 =
                       (((g_3652 && 65535UL),
                         (~(safe_mod_func_uint8_t_u_u(
                             (safe_div_func_uint8_t_u_u(
                                 (safe_add_func_uint8_t_u_u(p_3, 0xCCL)),
                                 0xC9L)),
                             0xD0L)))) >=
                        (l_3852[0][9] ==
                         ((g_2643[3] > ((g_438 = (g_293[2] = p_4)) & l_3841)),
                          l_3874[4][0][0]))));
            }
            l_3835 = l_3817[(g_3652 + 1)];
            if (l_3817[(g_3652 + 4)])
              break;
            for (l_3751 = 1; (l_3751 >= 0); l_3751 -= 1) {
              return p_4;
            }
          }

          ++g_3899[1][3][3];
          {
            uint32_t l_3875[9][8] = {
                {0x3DF852EAL, 0xD415547CL, 0x3DF852EAL, 4294967295UL,
                 0xD415547CL, 0x14533909L, 0x14533909L, 0xD415547CL},
                {0xD415547CL, 0x14533909L, 0x14533909L, 0xD415547CL,
                 4294967295UL, 0x3DF852EAL, 0xD415547CL, 0x3DF852EAL},
                {0xD415547CL, 4UL, 0x1D2F4715L, 4UL, 0xD415547CL, 0x1D2F4715L,
                 0x1CCF0451L, 0x1CCF0451L},
                {0x3DF852EAL, 4UL, 4294967295UL, 4294967295UL, 4UL, 0x3DF852EAL,
                 0x14533909L, 4UL},
                {0x1CCF0451L, 0x14533909L, 4294967295UL, 0x1CCF0451L,
                 4294967295UL, 0x14533909L, 0x1CCF0451L, 0x3DF852EAL},
                {4UL, 0xD415547CL, 0x1D2F4715L, 0x1CCF0451L, 0x1CCF0451L,
                 0x1D2F4715L, 0xD415547CL, 4UL},
                {0x3DF852EAL, 0x1CCF0451L, 0x14533909L, 4294967295UL,
                 0x1CCF0451L, 4294967295UL, 0x14533909L, 0x1CCF0451L},
                {4UL, 0x14533909L, 0x3DF852EAL, 4UL, 4294967295UL, 4294967295UL,
                 4UL, 0x3DF852EAL},
                {0x1CCF0451L, 0x1CCF0451L, 0x1D2F4715L, 0xD415547CL, 4UL,
                 0x1D2F4715L, 4UL, 0xD415547CL}};
            int8_t l_3895[4][10] = {
                {0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L},
                {0L, 0L, 0xCDL, 0L, 0L, 0xCDL, 0L, 0L, 0xCDL, 0L},
                {0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L},
                {0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L}};
            int32_t l_3898[9][4] = {{(-1L), 1L, 0x3CF8A80CL, 0L},
                                    {1L, 0xAEDA39EBL, 0xAEDA39EBL, 1L},
                                    {0x85DE5D23L, 0L, 0xAEDA39EBL, 0L},
                                    {1L, (-1L), 0x3CF8A80CL, (-1L)},
                                    {(-1L), 0xAEDA39EBL, 0x85DE5D23L, (-1L)},
                                    {0x85DE5D23L, (-1L), 0L, 0L},
                                    {0L, 0L, 0x3CF8A80CL, 1L},
                                    {0L, 0xAEDA39EBL, 0L, 0L},
                                    {0x85DE5D23L, 1L, 0x85DE5D23L, 0L}};
            int i, j;
            if (l_3875[7][1])
              break;
   l_3897
     [1]
     [3]
     =
     (g_26
      [1]
      [1]
      |
      (((((!(+((g_466[2] &= l_3739) != ((safe_rshift_func_uint8_t_u_u (((((safe_lshift_func_uint16_t_u_s ((((l_3896[1][0][0] = (((!(safe_mod_func_int16_t_s_s (((p_3 <= 0xC19FE0FAL) != (safe_sub_func_uint16_t_u_u ((safe_sub_func_int8_t_s_s ((l_3844 = (safe_mod_func_uint8_t_u_u (((l_3841 && ((l_3844 >= ((safe_unary_minus_func_uint8_t_u ((safe_rshift_func_uint16_t_u_s ((!(safe_add_func_int16_t_s_s ((l_3853 = (((0x28L >= (((((l_3856[4][3][4] |= (g_255 |= ((+(safe_unary_minus_func_uint32_t_u ((p_4, (((l_3894 != p_4) | g_212[5][0][5]) & l_3850[0][0][4]))))) >= p_3))) && l_3895[2][2]) != l_3710[2]) & p_4) >= l_3894)) < 0x68722F69L) <= l_3875[7][1])), l_3858[0]))), l_3850[0][1][5])))) != g_3797[0])) != g_182[0])) || p_3), p_3))), 0x42L)), 0UL))), g_283[2]))) == l_3875[5][6]) > g_3652)) | p_4) <= l_3843), 0)) > g_182[0]), l_3874[0][0][0]) == p_4), 4)), g_2982)))) <= l_3850[0][0][4]) != 0L) >= 0x05D04FBFL), l_3774));
   ++g_3899[1][3][3];
   for (g_86 = 0; (g_86 <= 8); g_86 += 1) {
     if (l_3895[2][2])
       break;
   }
          }

          for (g_86 = 0; (g_86 <= 8); g_86 += 1) {
            if (l_3895[2][2])
              ;
          }
          for (i = 0; i < 3; i++)
            l_3858[i] = 0x42C60853L;
        }
      }
      for (g_258 = 5; (g_258 < 37);
           g_258 = safe_add_func_uint16_t_u_u(g_258, 8)) {
        int8_t l_3717 = 3L;
        int32_t l_3725 = (-1L);
        int32_t l_3750[9][10][2] = {{{1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L}},
                                    {{0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L}},
                                    {{1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L}},
                                    {{1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L}},
                                    {{0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L}},
                                    {{1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L}},
                                    {{1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L}},
                                    {{0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L}},
                                    {{1L, 0xE3208151L},
                                     {1L, 0xE3208151L},
                                     {(-2L), 0xE3208151L},
                                     {0xE3208151L, (-2L)},
                                     {0xE3208151L, 0xE3208151L},
                                     {(-2L), 0xE3208151L},
                                     {0xE3208151L, (-2L)},
                                     {0xE3208151L, 0xE3208151L},
                                     {(-2L), 0xE3208151L},
                                     {0xE3208151L, (-2L)}}};
        int i, j, k;
        g_153[5] ^=
            (((safe_rshift_func_uint8_t_u_s(
                  (safe_div_func_uint32_t_u_u(
                      ((((~l_3717),
                         (safe_lshift_func_int16_t_s_s(
                             (safe_add_func_int16_t_s_s(
                                 (0xF3E3L >
                                  (g_104 = ((((safe_add_func_int32_t_s_s(
                                                  ((g_212[5][0][2] <
                                                    (((g_182[0] >= l_3724) |
                                                      g_182[2]),
                                                     (l_3725 =
                                                          (((g_734 = 0xCAADL) <=
                                                            (-9L)) != 1UL)))) <
                                                   0x9D6C78D6L),
                                                  3UL)),
                                              g_1655) == l_3717),
                                            p_4))),
                                 g_335[5])),
                             l_3686[2][0][1]))) != g_2643[0]),
                       g_2949),
                      l_3710[1])),
                  l_3717)) != p_4),
             l_3717);
        l_3725 = p_3;
      g_153
 [0]
 ^=
 ((g_5 && ((l_3696 &= (((safe_lshift_func_int8_t_s_u (((l_3697[0][2][1] |= ((safe_sub_func_int32_t_s_s ((((0x8C5F7811L == (safe_mod_func_uint16_t_u_u ((((((((((((l_3725 = 0L) & ((safe_unary_minus_func_int8_t_s (((safe_mod_func_uint32_t_u_u (((l_3751 &= ((safe_add_func_uint16_t_u_u ((safe_add_func_uint8_t_u_u (l_3717, ((0L >= (4294967293UL < (((((l_3739 > (((l_3750[7][6][0] = (safe_lshift_func_uint8_t_u_s ((safe_div_func_int16_t_s_s ((safe_unary_minus_func_uint32_t_u ((g_3235[4][1][0] == (safe_rshift_func_int16_t_s_u ((((l_3749 = ((safe_lshift_func_uint16_t_u_u ((p_4 < l_3724), 15)) == p_4)) >= g_293[3]) == l_3710[0]), 10))))), l_3717)), g_2295[0]))) < g_283[3]) <= l_3717)) & p_4) != l_3717) && 4294967295UL) ^ p_3))) > 0xCCL))), l_3724)) & g_3235[2][1][2])), l_3751), 0x78E86DB9L)) | 0xF3B6L))), g_5)) < 0xF13FL) <= g_182[0]) < l_3717) < g_182[4]) && p_4) >= 0x791AL) != g_335[5]), 0x2EB1247EL) && 1L), g_5))) > l_3717) & l_3710[2]), 0x62EF9181L)), p_4)) <= 1UL), 2)) && 4294967295UL) <= p_3)), l_3686[1][2][0])) & l_3724);
      }

      for (g_119 = 5; (g_119 >= 0); g_119 -= 1) {
        uint32_t l_3914 = 0xB6107E31L;
        int i;
        if (g_182[g_119])

        {
          g_153[8] |= 0x8FC4BD16L;
        }

        if (g_153[(g_119 + 3)]) {
          break;
          for (i = 0; i < 3; i++)
            l_3858[i] = 0x42C60853L;

          l_3710[i] = 0L;
        }

        for (g_5 = 0; (g_5 <= 9); g_5 += 1) {
          int i;

          for (g_258 = 5; (g_258 < 37);
               g_258 = safe_add_func_uint16_t_u_u(g_258, 8)) {
            int8_t l_3717 = 3L;
            int32_t l_3725 = (-1L);
            int32_t l_3750[9][10][2] = {{{1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L}},
                                        {{0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L}},
                                        {{1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L}},
                                        {{1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L}},
                                        {{0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L}},
                                        {{1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L}},
                                        {{1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L}},
                                        {{0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L},
                                         {1L, 0xE3208151L},
                                         {1L, 1L},
                                         {0xE3208151L, 1L}},
                                        {{1L, 0xE3208151L},
                                         {1L, 0xE3208151L},
                                         {(-2L), 0xE3208151L},
                                         {0xE3208151L, (-2L)},
                                         {0xE3208151L, 0xE3208151L},
                                         {(-2L), 0xE3208151L},
                                         {0xE3208151L, (-2L)},
                                         {0xE3208151L, 0xE3208151L},
                                         {(-2L), 0xE3208151L},
                                         {0xE3208151L, (-2L)}}};
            int i, j, k;
            g_153[5] ^=
                (((safe_rshift_func_uint8_t_u_s(
                      (safe_div_func_uint32_t_u_u(
                          ((((~l_3717),
                             (safe_lshift_func_int16_t_s_s(
                                 (safe_add_func_int16_t_s_s(
                                     (0xF3E3L >
                                      (g_104 =
                                           ((((safe_add_func_int32_t_s_s(
                                                  ((g_212[5][0][2] <
                                                    (((g_182[0] >= l_3724) |
                                                      g_182[2]),
                                                     (l_3725 =
                                                          (((g_734 = 0xCAADL) <=
                                                            (-9L)) != 1UL)))) <
                                                   0x9D6C78D6L),
                                                  3UL)),
                                              g_1655) == l_3717),
                                            p_4))),
                                     g_335[5])),
                                 l_3686[2][0][1]))) != g_2643[0]),
                           g_2949),
                          l_3710[1])),
                      l_3717)) != p_4),
                 l_3717);
            l_3725 = p_3;
      g_153
 [0]
 ^=
 ((g_5 && ((l_3696 &= (((safe_lshift_func_int8_t_s_u (((l_3697[0][2][1] |= ((safe_sub_func_int32_t_s_s ((((0x8C5F7811L == (safe_mod_func_uint16_t_u_u ((((((((((((l_3725 = 0L) & ((safe_unary_minus_func_int8_t_s (((safe_mod_func_uint32_t_u_u (((l_3751 &= ((safe_add_func_uint16_t_u_u ((safe_add_func_uint8_t_u_u (l_3717, ((0L >= (4294967293UL < (((((l_3739 > (((l_3750[7][6][0] = (safe_lshift_func_uint8_t_u_s ((safe_div_func_int16_t_s_s ((safe_unary_minus_func_uint32_t_u ((g_3235[4][1][0] == (safe_rshift_func_int16_t_s_u ((((l_3749 = ((safe_lshift_func_uint16_t_u_u ((p_4 < l_3724), 15)) == p_4)) >= g_293[3]) == l_3710[0]), 10))))), l_3717)), g_2295[0]))) < g_283[3]) <= l_3717)) & p_4) != l_3717) && 4294967295UL) ^ p_3))) > 0xCCL))), l_3724)) & g_3235[2][1][2])), l_3751), 0x78E86DB9L)) | 0xF3B6L))), g_5)) < 0xF13FL) <= g_182[0]) < l_3717) < g_182[4]) && p_4) >= 0x791AL) != g_335[5]), 0x2EB1247EL) && 1L), g_5))) > l_3717) & l_3710[2]), 0x62EF9181L)), p_4)) <= 1UL), 2)) && 4294967295UL) <= p_3)), l_3686[1][2][0])) & l_3724);
          }

          return p_4;
        }
      }
      for (g_258 = 5; (g_258 < 37);
           g_258 = safe_add_func_uint16_t_u_u(g_258, 8)) {
        int8_t l_3717 = 3L;
        int32_t l_3725 = (-1L);
        int32_t l_3750[9][10][2] = {{{1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L}},
                                    {{0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L}},
                                    {{1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L}},
                                    {{1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L}},
                                    {{0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L}},
                                    {{1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L}},
                                    {{1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L}},
                                    {{0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L},
                                     {1L, 0xE3208151L},
                                     {1L, 1L},
                                     {0xE3208151L, 1L}},
                                    {{1L, 0xE3208151L},
                                     {1L, 0xE3208151L},
                                     {(-2L), 0xE3208151L},
                                     {0xE3208151L, (-2L)},
                                     {0xE3208151L, 0xE3208151L},
                                     {(-2L), 0xE3208151L},
                                     {0xE3208151L, (-2L)},
                                     {0xE3208151L, 0xE3208151L},
                                     {(-2L), 0xE3208151L},
                                     {0xE3208151L, (-2L)}}};
        int i, j, k;
        g_153[5] ^=
            (((safe_rshift_func_uint8_t_u_s(
                  (safe_div_func_uint32_t_u_u(
                      ((((~l_3717),
                         (safe_lshift_func_int16_t_s_s(
                             (safe_add_func_int16_t_s_s(
                                 (0xF3E3L >
                                  (g_104 = ((((safe_add_func_int32_t_s_s(
                                                  ((g_212[5][0][2] <
                                                    (((g_182[0] >= l_3724) |
                                                      g_182[2]),
                                                     (l_3725 =
                                                          (((g_734 = 0xCAADL) <=
                                                            (-9L)) != 1UL)))) <
                                                   0x9D6C78D6L),
                                                  3UL)),
                                              g_1655) == l_3717),
                                            p_4))),
                                 g_335[5])),
                             l_3686[2][0][1]))) != g_2643[0]),
                       g_2949),
                      l_3710[1])),
                  l_3717)) != p_4),
             l_3717);
        l_3725 = p_3;
      g_153
 [0]
 ^=
 ((g_5 && ((l_3696 &= (((safe_lshift_func_int8_t_s_u (((l_3697[0][2][1] |= ((safe_sub_func_int32_t_s_s ((((0x8C5F7811L == (safe_mod_func_uint16_t_u_u ((((((((((((l_3725 = 0L) & ((safe_unary_minus_func_int8_t_s (((safe_mod_func_uint32_t_u_u (((l_3751 &= ((safe_add_func_uint16_t_u_u ((safe_add_func_uint8_t_u_u (l_3717, ((0L >= (4294967293UL < (((((l_3739 > (((l_3750[7][6][0] = (safe_lshift_func_uint8_t_u_s ((safe_div_func_int16_t_s_s ((safe_unary_minus_func_uint32_t_u ((g_3235[4][1][0] == (safe_rshift_func_int16_t_s_u ((((l_3749 = ((safe_lshift_func_uint16_t_u_u ((p_4 < l_3724), 15)) == p_4)) >= g_293[3]) == l_3710[0]), 10))))), l_3717)), g_2295[0]))) < g_283[3]) <= l_3717)) & p_4) != l_3717) && 4294967295UL) ^ p_3))) > 0xCCL))), l_3724)) & g_3235[2][1][2])), l_3751), 0x78E86DB9L)) | 0xF3B6L))), g_5)) < 0xF13FL) <= g_182[0]) < l_3717) < g_182[4]) && p_4) >= 0x791AL) != g_335[5]), 0x2EB1247EL) && 1L), g_5))) > l_3717) & l_3710[2]), 0x62EF9181L)), p_4)) <= 1UL), 2)) && 4294967295UL) <= p_3)), l_3686[1][2][0])) & l_3724);
      }
    }
    for (i = 0; i < 3; i++)
      l_3858[i] = 0x42C60853L;
  }
  l_3774 = (l_3696 &= p_3);
  return p_4;
}

static uint8_t func_6(uint8_t p_7, uint32_t p_8) {
  int32_t l_3684 = 0xEEFCA387L;
  for (g_258 = 0; (g_258 <= 3); g_258 += 1) {
    int i;
    if (g_2643[g_258])
      break;
  }
  l_3684 = (+(l_3684 ^ (safe_unary_minus_func_int16_t_s(l_3684))));
  return l_3684;
}

static uint16_t func_13(int32_t p_14, uint8_t p_15) {
  uint8_t l_25 = 0xC4L;
  int32_t l_31[8][4] = {{0x7B30477AL, 0x7B30477AL, 5L, 0xC1FCC8AFL},
                        {0x8B9628EAL, 1L, 0x8B9628EAL, 5L},
                        {0x8B9628EAL, 5L, 5L, 0x8B9628EAL},
                        {0x7B30477AL, 5L, 0xC1FCC8AFL, 5L},
                        {5L, 1L, 0xC1FCC8AFL, 0xC1FCC8AFL},
                        {0x7B30477AL, 0x7B30477AL, 5L, 0xC1FCC8AFL},
                        {0x8B9628EAL, 1L, 0x8B9628EAL, 5L},
                        {0x8B9628EAL, 5L, 5L, 0x8B9628EAL}};
  int16_t l_1860 = 1L;
  int32_t l_1935 = 8L;
  int32_t l_1936 = 0x8EF5C001L;
  uint32_t l_2001 = 0xE1F93DDDL;
  int16_t l_2118[8][3] = {{0L, 0L, 0L}, {0xD9BBL, 0xC82AL, 0xD9BBL},
                          {0L, 0L, 0L}, {0xD9BBL, 0xC82AL, 0xD9BBL},
                          {0L, 0L, 0L}, {0xD9BBL, 0xC82AL, 0xD9BBL},
                          {0L, 0L, 0L}, {0xD9BBL, 0xC82AL, 0xD9BBL}};
  int16_t l_2346[8];
  int8_t l_2421 = 0x35L;
  int32_t l_2504 = 0L;
  uint8_t l_2510 = 1UL;
  uint32_t l_2542 = 0x646A4ED7L;
  int16_t l_2552[2];
  int32_t l_2587[10][1][9] = {
      {{0x9BF51D87L, 0x35F300BAL, 0xC606858DL, 0xC606858DL, 0x35F300BAL,
        0x9BF51D87L, 0x134717F6L, 0L, 0xC606858DL}},
      {{0x196945FCL, 0x629D17EDL, 0x9BF51D87L, 0xC606858DL, 0x7F5C24DEL,
        0x196945FCL, 0x196945FCL, 0x7F5C24DEL, 0xC606858DL}},
      {{0x824BDCC5L, 0x35F300BAL, 0x824BDCC5L, 0x9BF51D87L, 0x7F5C24DEL,
        0x824BDCC5L, 0x134717F6L, 0x258835ECL, 0x9BF51D87L}},
      {{0x824BDCC5L, 0x7F5C24DEL, 0x9BF51D87L, 0x824BDCC5L, 0x35F300BAL,
        0x824BDCC5L, 0x9BF51D87L, 0x7F5C24DEL, 0x824BDCC5L}},
      {{0x196945FCL, 0x7F5C24DEL, 0xC606858DL, 0x9BF51D87L, 0x629D17EDL,
        0x196945FCL, 0x9BF51D87L, 0L, 0x9BF51D87L}},
      {{0x9BF51D87L, 0x35F300BAL, 0xC606858DL, 0xC606858DL, 0x35F300BAL,
        0x9BF51D87L, 0x134717F6L, 0L, 0xC606858DL}},
      {{0x196945FCL, 0x629D17EDL, 0x9BF51D87L, 0xC606858DL, 0x7F5C24DEL,
        0x196945FCL, 0x196945FCL, 0x7F5C24DEL, 0xC606858DL}},
      {{0x824BDCC5L, 0x35F300BAL, 0x824BDCC5L, 0x9BF51D87L, 0x7F5C24DEL,
        0x824BDCC5L, 0x134717F6L, 0x258835ECL, 0x9BF51D87L}},
      {{0x824BDCC5L, 0x7F5C24DEL, 0x9BF51D87L, 0x824BDCC5L, 0x35F300BAL,
        0x824BDCC5L, 0x9BF51D87L, 0x7F5C24DEL, 0x824BDCC5L}},
      {{0x196945FCL, 0x7F5C24DEL, 0xC606858DL, 0x9BF51D87L, 0x629D17EDL,
        0x196945FCL, 0x9BF51D87L, 0L, 0x9BF51D87L}}};
  uint16_t l_2653 = 1UL;
  int32_t l_2700 = 0x4E209AFCL;
  int32_t l_2825[6][4] = {{(-1L), 0L, (-1L), (-1L)}, {0L, 0L, 0x61A980BAL, 0L},
                          {0L, (-1L), (-1L), 0L},    {(-1L), 0L, (-1L), (-1L)},
                          {0L, 0L, 0x61A980BAL, 0L}, {0L, (-1L), (-1L), 0L}};
  int16_t l_2871 = (-9L);
  uint16_t l_2933[4][2] = {{0xD465L, 0x5996L},
                           {0x5996L, 0xD465L},
                           {0x5996L, 0x5996L},
                           {0xD465L, 0x5996L}};
  int32_t l_3013 = 0xBFF46306L;
  int32_t l_3088 = 0x9F62D42CL;
  uint32_t l_3146 = 0UL;
  int8_t l_3215 = (-1L);
  int8_t l_3331[9] = {0xC4L, 0xC4L, 0xC4L, 0xC4L, 0xC4L,
                      0xC4L, 0xC4L, 0xC4L, 0xC4L};
  uint8_t l_3346 = 1UL;
  int32_t l_3533 = (-1L);
  uint8_t l_3601[7];
  uint32_t l_3658 = 4294967295UL;
  int i, j, k;
  for (i = 0; i < 8; i++)
    l_2346[i] = 7L;
  for (i = 0; i < 2; i++)
    l_2552[i] = 7L;
  for (i = 0; i < 7; i++)
    l_3601[i] = 0x47L;
lbl_1816:
  l_31[7][2] = (safe_rshift_func_int8_t_s_u(
      func_18((safe_rshift_func_int8_t_s_u(0xBAL, 7)), (l_25 | g_5), (+g_5),
              g_5),
      4));
  if (((safe_div_func_uint8_t_u_u(
           (~(l_31[7][2] |
              (func_18(g_5,
                       (safe_mod_func_uint8_t_u_u(
                           (safe_rshift_func_uint16_t_u_u(l_25, 9)),
                           (func_38(l_31[7][2],
                                    (g_1076 |= (safe_rshift_func_uint8_t_u_u(
                                         (g_26[1][1] |
                                          func_18(p_15,
                                                  (func_45((g_26[1][2] ||
                                                            l_31[7][2])) < g_5),
                                                  g_255, l_25)),
                                         l_31[7][2]))),
                                    g_255, p_15),
                            g_181))),
                       g_1185, g_1815),
               0x5F42L))),
           g_1815)) != p_15)) {
    int32_t l_1842 = 1L;
    int32_t l_1843 = 1L;
    int32_t l_1846 = 0xE41C83DEL;
    int32_t l_1893 = 0x6995EFEDL;
    int32_t l_1896 = 0xD5ACBF82L;
    int32_t l_1897 = 0x33ECE688L;
    int32_t l_1898[5] = {1L, 1L, 1L, 1L, 1L};
    int16_t l_1996 = 1L;
    uint32_t l_2140 = 8UL;
    int32_t l_2334 = 0xD8AD8FFEL;
    int32_t l_2423 = 0x4FB6862EL;
    int i;
  lbl_2463:
    if (g_1462)
      goto lbl_1816;

    l_3601[i] = 0x47L;

  lbl_2513:
    for (g_1254 = 1; (g_1254 <= 4); g_1254 += 1) {
      uint32_t l_1938 = 0x9E84B3F0L;
      int32_t l_2048 = 0L;
      uint8_t l_2151[10] = {0x21L, 0x37L, 0x21L, 0x37L, 0x21L,
                            0x37L, 0x21L, 0x37L, 0x21L, 0x37L};
      int i;
      l_1936 &= ((g_153[(g_1254 + 4)] | ((!g_466[g_1254]), l_1898[g_1254])) >=
                 (safe_sub_func_uint32_t_u_u(
                     (((l_1898[g_1254] | (g_335[3]++)) &&
                       ((((safe_div_func_uint8_t_u_u(
                              (((l_1898[g_1254] < g_212[5][0][2]) |
                                (0x81D9L | (((safe_add_func_uint16_t_u_u(
                                                 0xDC2AL, l_1898[g_1254])) ||
                                             g_212[5][0][2]) > 4UL))) > l_25),
                              l_31[7][2])) &
                          0x77AF5CA5L) &
                         l_1893) < g_181)) &
                      l_1935),
                     p_14)));
      if (g_119) {
        int16_t l_1937 = (-1L);
        if (g_153[6])
          break;
        --l_1938;
      } else {
        uint8_t l_1947 = 0x3BL;
        int32_t l_1956 = 0x98144EBDL;
        int32_t l_1995 = 0x7ECA14B5L;
        int32_t l_1998 = (-4L);
        int32_t l_2000 = 0x15A754ACL;
        int8_t l_2102 = 0x41L;
        uint32_t l_2142 = 0x6426362EL;
        uint32_t l_2259 = 1UL;
        l_1898[g_1254] = ((safe_lshift_func_uint16_t_u_u(
                              ((l_1935 |= (++g_212[5][0][2])) ||
                               (safe_lshift_func_uint16_t_u_s(g_212[5][0][2],
                                                              (p_14, l_1947)))),
                              l_31[7][2])) == g_293[0]);
        if ((safe_sub_func_int8_t_s_s(
                0x86L,
                (((l_1898[g_1254] =
                       (g_153[(g_1254 + 4)] <
                        (safe_rshift_func_int8_t_s_s(
                            (l_31[7][2] = (safe_mod_func_int8_t_s_s(
                                 (0x79CBD193L >
                                  (safe_mod_func_uint8_t_u_u(3UL, l_1956))),
                                 (g_119 = ((safe_lshift_func_int16_t_s_s(
                                               (g_86 = 0xEA4FL), 14)),
                                           (g_592 &= 7L)))))),
                            (((safe_lshift_func_uint16_t_u_s(
                                  (safe_mod_func_int8_t_s_s(
                                      ((safe_add_func_int16_t_s_s(
                                           (((l_1898[0] >=
                                              ((safe_lshift_func_uint16_t_u_s(
                                                   ((safe_add_func_uint8_t_u_u(
                                                        (safe_div_func_uint32_t_u_u(
                                                            p_15, 1L)),
                                                        g_734)),
                                                    g_1260),
                                                   p_15)) ||
                                               g_293[1])),
                                             0xD4DEA6A5L) < p_15),
                                           p_14)) < l_1956),
                                      l_1893)),
                                  6)) == p_15),
                             l_1842))))) ||
                  p_15),
                 l_1947)))) {
          uint16_t l_1990 = 0UL;
          int32_t l_1997[8];
          uint8_t l_2039 = 7UL;
          int32_t l_2080 = 0xAAC87EDBL;
          int i;
          for (i = 0; i < 8; i++)
            l_1997[i] = 0x6201EBB6L;
          for (l_1956 = (-27); (l_1956 == (-28));
               l_1956 = safe_sub_func_int8_t_s_s(l_1956, 1)) {
            int32_t l_1987 = 8L;
            int32_t l_1999[9][7] = {
                {0x4777AC42L, 0L, 0L, 0L, 0x4777AC42L, 0xB0ECFC88L,
                 0x254D6C53L},
                {0x4777AC42L, 6L, 0xCF0C0BC4L, 0L, (-10L), 0xE18B93D3L,
                 0x254D6C53L},
                {(-10L), 0L, 0xCF0C0BC4L, 6L, 0x4777AC42L, 0xE18B93D3L,
                 0xE18B93D3L},
                {0x4777AC42L, 0L, 0L, 0L, 0x4777AC42L, 0xB0ECFC88L,
                 0x254D6C53L},
                {0x4777AC42L, 6L, 0xCF0C0BC4L, 0L, (-10L), 0xE18B93D3L,
                 0x254D6C53L},
                {(-10L), 0L, 0xCF0C0BC4L, 6L, 0x4777AC42L, 0xE18B93D3L,
                 0xE18B93D3L},
                {0x4777AC42L, 0L, 0L, 0L, 0x4777AC42L, 0xB0ECFC88L,
                 0x254D6C53L},
                {0x4777AC42L, 6L, (-10L), 4L, 0xB0ECFC88L, 0L, 0xCF0C0BC4L},
                {0xB0ECFC88L, 4L, (-10L), 6L, 0xE18B93D3L, 0L, 0L}};
            int i, j;
            g_153[0] =
                (l_1846 <
                 (safe_add_func_uint32_t_u_u(
                     (++g_74),
                     ((safe_rshift_func_int8_t_s_s(
                          (g_293[3] ==
                           ((g_1519,
                             ((7UL &&
                               (g_212[5][0][2] = (safe_lshift_func_int8_t_s_s(
                                    (safe_lshift_func_int8_t_s_s(
                                        (safe_rshift_func_uint16_t_u_s(
                                            ((((l_1990 =
                                                    (safe_div_func_uint8_t_u_u(
                                                        l_1987,
                                                        (safe_add_func_int8_t_s_s(
                                                            l_1898[g_1254],
                                                            0xD0L))))) >=
                                               (safe_div_func_int32_t_s_s(
                                                   (-1L),
                                                   (safe_div_func_int8_t_s_s(
                                                       g_1076, (-2L)))))) !=
                                              p_14),
                                             g_182[0]),
                                            l_1935)),
                                        g_153[(g_1254 + 4)])),
                                    7)))) >= g_181)),
                            g_293[0])),
                          2)) &
                      (-7L)))));
            --l_2001;
          }
          l_1898[0] =
              ((safe_add_func_int32_t_s_s(
                   (safe_sub_func_uint8_t_u_u(
                       (l_1997[1] = (safe_sub_func_int16_t_s_s(
                            ((safe_mod_func_uint8_t_u_u(
                                 ((safe_unary_minus_func_uint16_t_u(
                                      ((p_15 ^= (((safe_sub_func_int8_t_s_s(
                                                      (g_74 <= (~l_1947)),
                                                      l_25)) <= g_438) &&
                                                 (safe_lshift_func_uint8_t_u_s(
                                                     p_14, (l_2000 < p_14))))) ^
                                       l_1998))),
                                  ((0x80CBL != (-7L)) & 0xA7L)),
                                 7L)) |
                             0xBAL),
                            p_14))),
                       g_5)),
                   g_212[6][0][4])) != 0x1C23L);
   if ((l_2048 = (g_26[1][2] < (safe_rshift_func_int16_t_s_s ((safe_sub_func_int16_t_s_s ((l_31[3][1] = ((p_15 && (g_293[0] = (safe_add_func_uint8_t_u_u (0x65L, ((((safe_sub_func_uint16_t_u_u (((safe_rshift_func_int16_t_s_u (g_734, 5)), (safe_add_func_uint32_t_u_u (((l_1936 |= (((((l_25 & (safe_div_func_int16_t_s_s (((safe_mod_func_uint16_t_u_u (((((((safe_lshift_func_uint8_t_u_s ((safe_div_func_int32_t_s_s ((((((l_1860 && (safe_mod_func_int8_t_s_s ((g_153[(g_1254 + 4)] = l_2039), (safe_div_func_int8_t_s_s (((l_1898[0] = (safe_rshift_func_int16_t_s_u (p_15, (g_395 &= ((safe_rshift_func_int8_t_s_u ((g_592 = (safe_add_func_uint16_t_u_u ((g_181 <= p_15), g_1047))), p_15)), l_31[7][2]))))) ^ l_2001), p_14))))), l_1860) || p_14) && l_31[7][2]) && p_14), 4294967289UL)), g_283[3])) < l_1938) > g_438) & 0L), 0x25L) <= g_1254), p_14)) != p_14), g_378[6]))) <= p_14) | 0xD1L), g_1047) || g_1047)) >= g_86), g_466[g_1254]))), 0L)), 0UL) != g_466[3]) && p_14))))) && 7L)), 0x1499L)), 14)))))
   {
     g_153[0] ^= (safe_lshift_func_int8_t_s_s(g_335[5], 3));
   } else {
     int32_t l_2081 = 0xC2A3CCD4L;
     l_1898[g_1254] =
         (g_153[4] ^=
          (~((g_1441 >
              (((~(g_74 = 0x9B2E5E7EL)) ^ (-1L)),
               (safe_mod_func_int32_t_s_s(
                   (4294967295UL !=
                    (((g_1254 !=
                       (((safe_add_func_uint8_t_u_u(0x66L, (~g_378[3]))) ^
                         (safe_sub_func_uint32_t_u_u(
                             ((((safe_rshift_func_int16_t_s_u(
                                    ((((!0UL) != (p_14 && l_1898[g_1254])) <
                                      5UL) <= 0x4679L),
                                    12)) &
                                g_466[2]) &
                               g_466[g_1254]),
                              l_31[6][2]),
                             g_283[5]))) >= p_15)) |
                      p_14) ^
                     g_140)),
                   (-1L))))) ||
             0x255F804DL)));
     g_283[1] |=
         ((safe_div_func_int32_t_s_s(
              ((safe_sub_func_uint32_t_u_u(
                   ((safe_add_func_int16_t_s_s(
                        ((safe_lshift_func_uint8_t_u_s(
                             ((0xD8L &&
                               (g_119 =
                                    ((l_1990 <=
                                      (((p_14 < l_1997[5]) &
                                        (safe_rshift_func_uint16_t_u_u(
                                            (l_1995 = p_14),
                                            (p_15 <=
                                             (((safe_lshift_func_int16_t_s_s(
                                                   ((safe_sub_func_uint32_t_u_u(
                                                        ((safe_rshift_func_uint16_t_u_u(
                                                             (((l_2080 |=
                                                                ((safe_rshift_func_int16_t_s_u(
                                                                     g_182[4],
                                                                     (g_238 = g_293
                                                                          [0]))) ==
                                                                 ((safe_unary_minus_func_uint8_t_u(
                                                                      p_14)),
                                                                  g_466
                                                                      [g_1254]))) <
                                                               l_1936),
                                                              l_1998),
                                                             l_31[7][2])) !=
                                                         255UL),
                                                        l_1898[g_1254])) ||
                                                    0x44L),
                                                   12)) |
                                               g_293[0]) ||
                                              p_14))))),
                                       9L)) >= 4294967286UL))) != p_15),
                             1)) < 0x4218L),
                        l_2081)) < 0x7D2EB91BL),
                   g_1815)) > l_1997[3]),
              l_1998)) < p_15);
   }
        } else {
          int32_t l_2103[6][1] = {{(-1L)},       {0x8875B971L}, {(-1L)},
                                  {0x8875B971L}, {(-1L)},       {0x8875B971L}};
          uint8_t l_2120 = 0x4EL;
          int32_t l_2135 = 0x25B4A680L;
          int32_t l_2141 = (-1L);
          int32_t l_2202 = 0xF9C4DDD9L;
          int i, j;
          l_1936 |= 0x6A25D82EL;
          for (l_1860 = 6; (l_1860 >= 0); l_1860 -= 1) {
            uint32_t l_2086 = 0x6E79C4FFL;
            int32_t l_2119[8][5][6] = {
                {{(-5L), (-10L), 0x7734754BL, (-10L), (-5L), (-10L)},
                 {1L, 0xC1A70DA4L, 5L, (-5L), 0xACF8C3F1L, 1L},
                 {0xB74B5AF4L, (-1L), 0x1EE50787L, 0xC1A70DA4L, (-1L), 1L},
                 {(-8L), (-1L), 5L, (-8L), 0L, (-10L)},
                 {(-1L), (-3L), 0x7734754BL, 0x8F0ADA79L, (-10L), 0x1EE50787L}},
                {{(-10L), 0xB74B5AF4L, (-7L), (-1L), (-10L), 0x64C2E5E1L},
                 {0x24D23A06L, (-3L), 3L, 0L, 0L, 0x817D5DEBL},
                 {0xC1A70DA4L, (-1L), 0xBBDE0FEDL, 0xACF8C3F1L, (-1L), 1L},
                 {0x8F0ADA79L, (-1L), 0x9E1B5FD2L, 0xACF8C3F1L, 0xACF8C3F1L,
                  0x9E1B5FD2L},
                 {0xC1A70DA4L, 0xC1A70DA4L, (-7L), 0L, (-5L), 3L}},
                {{0x24D23A06L, (-10L), (-10L), (-1L), (-1L), (-7L)},
                 {(-10L), 0x24D23A06L, (-10L), 0x8F0ADA79L, 0xC1A70DA4L, 3L},
                 {(-1L), 0x8F0ADA79L, (-7L), (-8L), 1L, 0x9E1B5FD2L},
                 {(-8L), 1L, 0x9E1B5FD2L, 0xC1A70DA4L, 0x8FE00E48L, 1L},
                 {0xB74B5AF4L, 1L, 0xBBDE0FEDL, (-5L), 1L, 0x817D5DEBL}},
                {{1L, 0x8F0ADA79L, 3L, (-10L), 0xC1A70DA4L, 0x64C2E5E1L},
                 {(-5L), 0x24D23A06L, (-7L), (-10L), (-1L), 0x1EE50787L},
                 {(-5L), (-10L), 0x7734754BL, (-10L), (-5L), (-10L)},
                 {1L, 0xC1A70DA4L, 5L, (-5L), 0xACF8C3F1L, 1L},
                 {0xB74B5AF4L, (-1L), 0x1EE50787L, 0xC1A70DA4L, (-1L), 1L}},
                {{(-8L), (-1L), 5L, (-8L), 0L, (-10L)},
                 {(-1L), (-3L), 0x7734754BL, 0x8F0ADA79L, (-10L), 0x1EE50787L},
                 {(-10L), 0xB74B5AF4L, (-7L), (-1L), (-10L), 0x64C2E5E1L},
                 {0x24D23A06L, (-3L), 3L, 0L, 0L, 0x817D5DEBL},
                 {0xC1A70DA4L, (-1L), 0xBBDE0FEDL, 0xACF8C3F1L, (-1L), 1L}},
                {{0x8F0ADA79L, (-1L), 0x9E1B5FD2L, 0xACF8C3F1L, 0xACF8C3F1L,
                  0x9E1B5FD2L},
                 {0xC1A70DA4L, 0xC1A70DA4L, (-7L), 0L, (-5L), 3L},
                 {0x24D23A06L, (-10L), (-10L), (-1L), (-1L), (-7L)},
                 {(-10L), 0x24D23A06L, (-10L), 0x8F0ADA79L, (-1L), 0L},
                 {(-3L), (-1L), (-1L), (-6L), 6L, 1L}},
                {{(-6L), 6L, 1L, (-1L), 0xC62A1683L, (-3L)},
                 {1L, 6L, 0x24D23A06L, 0x4E3D2C95L, 6L, (-10L)},
                 {6L, (-1L), 0L, 0L, (-1L), 0xB74B5AF4L},
                 {0x4E3D2C95L, 0x1A6BA489L, 0xACF8C3F1L, 0x4F1D62BAL, 0L,
                  (-5L)},
                 {0x4E3D2C95L, 0L, 0x8F0ADA79L, 0L, 0x4E3D2C95L, (-10L)}},
                {{6L, (-1L), 0x8FE00E48L, 0x4E3D2C95L, 0x006AE983L, 0L},
                 {1L, 0x2EE8A06EL, (-5L), (-1L), (-3L), 0L},
                 {(-6L), 0L, 0x8FE00E48L, (-6L), 0x5520A720L, (-10L)},
                 {(-3L), 0x86F8F5C1L, 0x8F0ADA79L, (-1L), 0L, (-5L)},
                 {0x4F1D62BAL, 1L, 0xACF8C3F1L, 0x2EE8A06EL, 0L, 0xB74B5AF4L}}};
            int i, j, k;
            g_153[(g_1254 + 4)] &=
                (l_1936 &=
                 (((g_734 = (safe_lshift_func_int16_t_s_u(
                        ((g_293[0] = (safe_rshift_func_int8_t_s_s(
                              l_2048,
                              ((g_1441, l_2086),
                               ((safe_div_func_int8_t_s_s(
                                    (g_238 &
                                     (safe_rshift_func_uint16_t_u_s(
                                         (safe_lshift_func_uint8_t_u_u(
                                             ((safe_add_func_uint8_t_u_u(
                                                  ((g_293[0] <=
                                                    (!(((safe_unary_minus_func_uint8_t_u(
                                                            ((((l_31[7][2] >
                                                                (safe_div_func_int16_t_s_s(
                                                                    5L,
                                                                    (safe_lshift_func_int16_t_s_u(
                                                                        (g_395 >
                                                                         (l_2000 ==
                                                                          0x0CL)),
                                                                        4))))) &&
                                                               0x44F5L) >=
                                                              g_119) ^
                                                             l_2102))) <=
                                                        g_283[3]) != 0x8DL))) >=
                                                   0x9902L),
                                                  1L)) >= l_2103[3][0]),
                                             4)),
                                         g_378[6]))),
                                    p_15)) <= 1L))))) &
                         0x25L),
                        9))) &&
                   l_2103[1][0]) != l_1947));
            l_2119[5][0][2] = (safe_rshift_func_int16_t_s_u(
                (g_1076 =
                     ((((p_15 !=
                         ((g_1047 > l_2102) ^
                          ((safe_sub_func_int16_t_s_s(
                               (~(safe_add_func_int32_t_s_s(
                                   (l_1936 &=
                                    ((safe_lshift_func_int8_t_s_s(
                                         (0UL &
                                          ((((((~(g_74++)) <= 0L) | g_335[5]) ==
                                             (((safe_sub_func_uint8_t_u_u(
                                                   ((g_26[1][0] |=
                                                     g_153[(g_1254 + 4)]),
                                                    l_2000),
                                                   (safe_div_func_uint8_t_u_u(
                                                       g_212[5][0][2],
                                                       0xEFL)))) == p_14) <=
                                              0xECL)) ^
                                            l_2118[4][1]) &
                                           0x74301785L)),
                                         5)) ^
                                     g_438)),
                                   p_14))),
                               g_283[5])) ^
                           p_14))) != l_2103[2][0]),
                       0xD5A2L) == 2L)),
                p_15));
            l_2120++;
            l_2119[5][0][2] = (safe_rshift_func_uint8_t_u_u(
                (l_1898[g_1254] !=
                 ((((l_2103[3][0] = p_15) & (l_1843 <= p_14)) >=
                   ((l_1897 ^=
                     ((g_335[5]++) >=
                      ((((safe_div_func_uint32_t_u_u(
                             ((p_14 >=
                               (safe_lshift_func_uint8_t_u_s(
                                   (safe_lshift_func_uint8_t_u_s(
                                       ((safe_sub_func_uint32_t_u_u(
                                            ((l_2141 =
                                                  (l_1896 =
                                                       (((l_2135 &= 7UL) &
                                                         8UL) !=
                                                        (((safe_rshift_func_int8_t_s_s(
                                                              (+(l_31[5][2] ^=
                                                                 0x2DL)),
                                                              ((((safe_mod_func_int8_t_s_s(
                                                                     ((g_1254 &
                                                                       p_14) >
                                                                      0xB1FB4B26L),
                                                                     l_2119
                                                                         [5][0]
                                                                         [2])) ||
                                                                 p_15) ^
                                                                g_181) ==
                                                               l_2140))) >
                                                          g_1260),
                                                         l_1846)))) ||
                                             g_26[0][1]),
                                            2L)) ||
                                        l_1898[g_1254]),
                                       4)),
                                   6))) != 0x96L),
                             p_14)) != 0L) >= p_14) &&
                       p_14))) ||
                    g_1462)),
                  l_2142)),
                6));
          }
          g_153[6] =
              (((safe_mod_func_uint32_t_u_u(
                    g_140,
                    ((safe_add_func_int8_t_s_s(
                         (((safe_mod_func_uint8_t_u_u(
                               (safe_rshift_func_int16_t_s_s(
                                   ((l_2141 |=
                                     (((((1UL & (l_2151[4] |= (0UL & p_15))),
                                         p_14) > (g_255, 0x33L)) ||
                                       ((+((safe_add_func_int16_t_s_s(
                                               (((g_153[(g_1254 + 4)],
                                                  (l_2000 &= g_1655)),
                                                 0x2DAA0D4EL) >= p_15),
                                               l_2118[6][2])) ^
                                           0x328AL)) ||
                                        0UL)) >= g_104)) <= 0x00L),
                                   12)),
                               0xB6L)) ^
                           2UL),
                          (-1L)),
                         l_1935)) &&
                     l_1998))) |
                l_2103[2][0]) ||
               p_15);
          if ((g_283[3] =
                   (((g_378[6] && (safe_rshift_func_uint8_t_u_s(g_1441, 3))) ==
                     (safe_unary_minus_func_int16_t_s((
                         (((((safe_sub_func_int16_t_s_s(
                                 ((((g_238 |= p_15) <=
                                    (safe_rshift_func_int8_t_s_u(0L, 2))),
                                   ((p_15,
                                     (!(((0x4D309952L >=
                                          (safe_mod_func_int32_t_s_s(
                                              0x38180868L,
                                              (((!(safe_lshift_func_uint16_t_u_s(
                                                    (safe_lshift_func_uint8_t_u_s(
                                                        ((g_74 | (2L ^ p_14)) >
                                                         0xBAB6L),
                                                        1)),
                                                    p_14))),
                                                g_5),
                                               l_1938)))) < g_293[0]) ||
                                        p_15))) < 0x2190BA6DL)) >= l_1860),
                                 l_1898[0])) &
                             l_2120) &&
                            l_1995),
                           g_283[4]) |
                          p_15) ^
                         (-1L))))),
                    p_14))) {
            int8_t l_2177 = 0x5BL;
            g_153[(g_1254 + 4)] = (safe_lshift_func_uint16_t_u_s(
                ((0L &&
                  ((safe_add_func_uint8_t_u_u(
                       (safe_sub_func_uint32_t_u_u(
                           l_2177,
                           (safe_add_func_int8_t_s_s(
                               (~((g_26[1][4] &
                                   ((g_1815 !=
                                     (l_1998 |=
                                      (((((l_1898[g_1254] = (safe_add_func_uint32_t_u_u(
                                               (p_14 &&
                                                (safe_sub_func_int32_t_s_s(
                                                    (((safe_rshift_func_int8_t_s_u(
                                                          ((safe_div_func_uint32_t_u_u(
                                                               p_14,
                                                               (((((~(((safe_div_func_int8_t_s_s(
                                                                           (((safe_div_func_uint16_t_u_u(
                                                                                 (safe_rshift_func_uint8_t_u_s(
                                                                                     0xD9L,
                                                                                     0)),
                                                                                 p_15)),
                                                                             (l_2103
                                                                                  [3]
                                                                                  [0] ==
                                                                              g_119)),
                                                                            p_14),
                                                                           l_1898
                                                                               [0])) ||
                                                                       p_15) &&
                                                                      g_181)),
                                                                   g_1655) >=
                                                                  p_14) &&
                                                                 0UL) ||
                                                                p_15))),
                                                           g_147),
                                                          1)) >= (-7L)) ==
                                                     g_378[3]),
                                                    l_2151[7]))),
                                               g_1655))) &
                                          0xF3B1L),
                                         0xA84A8E2DL) ||
                                        l_1956) ^
                                       0x3AB0BA9CL))) |
                                    l_2140)) < p_15)),
                               p_15)))),
                       p_14)) != g_238)),
                 l_2141),
                g_1462));
            if (p_14)
              continue;
          } else {
            l_1995 &=
                ((0x40381F2CL |
                  ((safe_sub_func_uint16_t_u_u(
                       l_25,
                       (((safe_add_func_int32_t_s_s(
                             l_2048,
                             ((l_1898[g_1254] = (safe_lshift_func_int8_t_s_u(
                                   (safe_lshift_func_int16_t_s_s(
                                       ((p_15 | ((-1L) != p_14)) <=
                                        (g_1047 ^= g_181)),
                                       14)),
                                   ((((p_14, (0x22D6L || g_293[1])),
                                      0xF2402C66L) >= (-1L)),
                                    g_119)))) < 0x64F4L))) ||
                         0xCBL) < 65527UL))) ^
                   l_2202)) &&
                 p_14);
            return l_2103[3][0];
          }
        }
        if ((safe_lshift_func_int16_t_s_s(
                (safe_lshift_func_uint8_t_u_s(
                    (safe_sub_func_uint8_t_u_u(
                        p_15, (safe_rshift_func_int16_t_s_u(g_5, 7)))),
                    6)),
                (((+253UL) ==
                  ((((((g_255 >=
                        ((safe_sub_func_uint16_t_u_u(
                             (l_1995 |=
                              ((safe_add_func_int32_t_s_s(
                                   (safe_lshift_func_int16_t_s_u(
                                       ((((p_15 <= l_31[2][3]), 249UL) <
                                         (((((safe_rshift_func_int16_t_s_s(
                                                 (g_283[3] == l_1898[g_1254]),
                                                 g_5)) ^
                                             p_15) >= 1UL) == g_255) > p_14)) ==
                                        p_15),
                                       p_14)),
                                   0L)) ||
                               g_104)),
                             l_31[7][2])),
                         g_1076)) != 0UL),
                      g_238) == l_1956) != 0L) &&
                   p_15)) <= l_2000)))) {
          g_153[3] = g_153[(g_1254 + 4)];
        } else {
          int32_t l_2260 = 0xF065842EL;
   l_1995
     =
     (safe_add_func_uint8_t_u_u
      (((((!p_15) || g_378[6]) & (p_15 & (safe_div_func_uint16_t_u_u ((safe_rshift_func_uint8_t_u_u ((g_26[0][2] = (+((((0L != (l_2260 = (safe_sub_func_int32_t_s_s ((safe_div_func_int8_t_s_s ((l_31[1][0] |= (safe_add_func_uint8_t_u_u ((safe_div_func_uint16_t_u_u (((safe_div_func_int16_t_s_s (((((safe_sub_func_uint32_t_u_u ((safe_rshift_func_int16_t_s_u ((safe_rshift_func_uint8_t_u_u (g_104, (g_734 & p_15))), (safe_sub_func_int32_t_s_s ((safe_sub_func_uint8_t_u_u ((safe_sub_func_int32_t_s_s (((g_212[0][0][5] || ((+((safe_mul_func_uint32_t_u_u (((safe_div_func_int16_t_s_s (((safe_lshift_func_int8_t_s_u ((safe_mod_func_uint16_t_u_u ((safe_add_func_int32_t_s_s ((g_153[(g_1254 + 4)] = 0xA783669BL), p_14)), l_2259)), 2)) > 0x1145L), l_2259)) <= l_2260), 0L)), g_26[0][2])) >= l_2260)) && g_1047), l_2142)), 0xA8L)), l_1896)))), g_734)) >= 0x2F0FL), 0xA6L) != p_14), 65535UL)) & l_2260), g_1185)), p_14))), p_14)), 0x901429FBL)))), 1UL), p_15) && l_1843))), 0)), g_147)))) >= 0x1622L), g_5));
   return p_15;
        }
      }
    }
    if (l_1842) {
      int8_t l_2269 = 0xDFL;
      int32_t l_2278 = 1L;
      int32_t l_2292[8][8][2] = {{{(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)}},
                                 {{(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)}},
                                 {{0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL}},
                                 {{(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)}},
                                 {{(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)}},
                                 {{0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL}},
                                 {{(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)}},
                                 {{(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x5ABDC85CL, (-4L)},
                                  {(-4L), 0x5ABDC85CL},
                                  {(-4L), (-4L)},
                                  {0x7199C605L, 0x5ABDC85CL},
                                  {0x5ABDC85CL, 0x7199C605L},
                                  {0x5ABDC85CL, 0x5ABDC85CL}}};
      int32_t l_2332 = 0x8FA6027DL;
      int32_t l_2341 = (-1L);
      int32_t l_2342 = 0xAF9A6691L;
      int32_t l_2343 = 0L;
      int32_t l_2344 = 0xFA026477L;
      int32_t l_2345[9] = {0xED1F0CAFL, (-1L), 0xED1F0CAFL,
                           0xED1F0CAFL, (-1L), 0xED1F0CAFL,
                           0xED1F0CAFL, (-1L), 0xED1F0CAFL};
      int8_t l_2385 = (-5L);
      int8_t l_2506 = 0xFAL;
      int i, j, k;
    lbl_2509:
      if (((p_15 & (p_15 != p_15)) |
           (safe_add_func_int8_t_s_s(
               g_438,
               (safe_rshift_func_uint8_t_u_s(
                   ((l_1897 ^=
                     (g_1655 ||
                      ((safe_add_func_uint32_t_u_u(
                           (((l_2269,
                              ((safe_div_func_int32_t_s_s(
                                   (safe_sub_func_uint32_t_u_u(
                                       (l_2278 =
                                            ((((safe_lshift_func_int16_t_s_u(
                                                   (-1L),
                                                   (l_2118[4][1] <
                                                    (safe_rshift_func_uint8_t_u_u(
                                                        (l_2269 == l_1842),
                                                        g_238))))) > p_14) >
                                              p_14),
                                             0x96026114L)),
                                       p_14)),
                                   g_1047)) ^
                               g_212[5][0][2])),
                             g_1076) > g_258),
                           0xB37C28E8L)) &
                       g_378[6]))) |
                    l_1935),
                   l_1898[0])))))) {
        int16_t l_2285 = (-6L);
        int32_t l_2293 = 0x2BE38F57L;
        int32_t l_2294 = 2L;
        for (g_1254 = 0; (g_1254 >= 24);
             g_1254 = safe_add_func_int8_t_s_s(g_1254, 7)) {
          return l_1898[0];
        }
        g_283[5] =
            ((safe_rshift_func_uint16_t_u_s(
                 (((((safe_lshift_func_int16_t_s_u(p_14, l_2285)) <=
                     ((g_1185,
                       ((((((l_2294 =
                                 ((safe_add_func_uint32_t_u_u(
                                      (((l_2293 = (+(
                                             (0x68L !=
                                              ((safe_lshift_func_uint8_t_u_u(
                                                   (g_438 =
                                                        ((((65532UL && (-2L)),
                                                           g_153[0]) <
                                                          (safe_lshift_func_int8_t_s_s(
                                                              (g_212[5][0][2] |
                                                               l_2001),
                                                              p_14))) &
                                                         g_74)),
                                                   2)),
                                               0xECL)),
                                             l_2292[1][7][0]))) ||
                                        g_592) > p_14),
                                      0x4893C00DL)) >= l_1860)) > g_153[0]) <=
                           l_1897) ||
                          g_2295[0]) ^
                         g_378[3]) == 0UL)) != g_147)) >= g_212[3][0][4]) <
                   0L) ||
                  p_14),
                 8)) &&
             g_255);
        l_1898[0] = (l_2293 == g_293[3]);
      } else {
        uint16_t l_2318 = 5UL;
        int32_t l_2326 = (-7L);
        int32_t l_2329 = 0x2328AC30L;
        int32_t l_2330[10][6] = {
            {1L, 0x2FDCACE1L, (-8L), 6L, 0x5F6F5AA5L, 0x000277B7L},
            {(-8L), (-9L), 0x5AC21C4CL, (-1L), 0L, 0x5AC21C4CL},
            {(-8L), 0x5F6F5AA5L, (-1L), 6L, 1L, 6L},
            {1L, 0x5F6F5AA5L, 1L, 0x5AC21C4CL, 0L, (-1L)},
            {0x000277B7L, (-9L), 1L, 0x000277B7L, 0x5F6F5AA5L, 6L},
            {6L, 0x2FDCACE1L, (-1L), 0x000277B7L, 0L, 0x5AC21C4CL},
            {0x000277B7L, 0L, 0x5AC21C4CL, 0x5AC21C4CL, 0L, 0x000277B7L},
            {1L, 0x2FDCACE1L, (-8L), 6L, 0x5F6F5AA5L, 0x000277B7L},
            {(-8L), (-9L), 0x5AC21C4CL, (-1L), 0L, 0x5AC21C4CL},
            {(-8L), 0x5F6F5AA5L, (-1L), 6L, 1L, 6L}};
        int32_t l_2347 = 1L;
        int16_t l_2391 = 0x20F1L;
        uint32_t l_2393[4][5][2] = {{{0x64AE9E79L, 1UL},
                                     {4294967295UL, 0x5F0900E5L},
                                     {4294967295UL, 1UL},
                                     {0x64AE9E79L, 1UL},
                                     {4294967295UL, 0x5F0900E5L}},
                                    {{4294967295UL, 1UL},
                                     {0x64AE9E79L, 1UL},
                                     {4294967295UL, 0x5F0900E5L},
                                     {4294967295UL, 1UL},
                                     {0x64AE9E79L, 1UL}},
                                    {{4294967295UL, 0x5F0900E5L},
                                     {4294967295UL, 1UL},
                                     {0x64AE9E79L, 1UL},
                                     {4294967295UL, 0x5F0900E5L},
                                     {4294967295UL, 1UL}},
                                    {{0x64AE9E79L, 1UL},
                                     {4294967295UL, 0x5F0900E5L},
                                     {4294967295UL, 1UL},
                                     {0x64AE9E79L, 1UL},
                                     {4294967295UL, 0x5F0900E5L}}};
        uint8_t l_2440 = 5UL;
        int8_t l_2447 = (-10L);
        int32_t l_2505 = 6L;
        int i, j, k;
        l_1936 = (safe_unary_minus_func_uint16_t_u((
            (-5L) <=
            (((safe_lshift_func_int8_t_s_u(
                  (safe_div_func_uint8_t_u_u(
                      (g_26[0][0] |= (safe_div_func_uint32_t_u_u(
                           (((g_1462 ^= 1L) &
                             ((l_1843 =
                                   ((safe_mod_func_int32_t_s_s(
                                        ((+p_15) &
                                         (l_2278 =
                                              (((!((4294967295UL &&
                                                    (safe_rshift_func_uint16_t_u_s(
                                                        ((l_2292[6][3][0] ==
                                                          p_14) ==
                                                         (safe_add_func_uint8_t_u_u(
                                                             ((safe_sub_func_uint16_t_u_u(
                                                                  (safe_sub_func_uint8_t_u_u(
                                                                      l_2001,
                                                                      (safe_unary_minus_func_uint8_t_u(
                                                                          p_15)))),
                                                                  (safe_add_func_uint32_t_u_u(
                                                                      (safe_add_func_int16_t_s_s(
                                                                          0L,
                                                                          l_1897)),
                                                                      g_1254)))) |
                                                              p_15),
                                                             0L))),
                                                        l_2292[3][6][1]))) &&
                                                   g_378[6])) >= (-7L)) ^
                                               0L))),
                                        0x2FDD62ABL)),
                                    g_1260)) |
                              l_2269)) |
                            l_2318),
                           (-1L)))),
                      l_2318)),
                  l_2318)) >= l_1893),
             l_31[0][3]))));
        for (g_1260 = 20; (g_1260 > 41);
             g_1260 = safe_add_func_int32_t_s_s(g_1260, 3)) {
          for (g_147 = (-21); (g_147 == 57); g_147++) {
            return p_14;
          }
        }
        if ((l_31[0][2] = p_14)) {
          int32_t l_2323 = 0x44A3AC28L;
          int32_t l_2324 = 0x1232BC43L;
          int32_t l_2327 = 0x9E9CAC17L;
          int32_t l_2328 = 0x063C469CL;
          int32_t l_2333 = 0xB62E9951L;
          int32_t l_2337 = (-5L);
          int32_t l_2338 = 0x108821EBL;
          int32_t l_2340[1][1];
          uint32_t l_2348[10][3][1] = {
              {{0xBC74B2C9L}, {0xBC74B2C9L}, {0x2DE65F24L}},
              {{0xBC74B2C9L}, {0xBC74B2C9L}, {0x2DE65F24L}},
              {{0xBC74B2C9L}, {0xBC74B2C9L}, {0x2DE65F24L}},
              {{0xBC74B2C9L}, {0xBC74B2C9L}, {0x2DE65F24L}},
              {{0xBC74B2C9L}, {0xBC74B2C9L}, {0x2DE65F24L}},
              {{0xBC74B2C9L}, {0xBC74B2C9L}, {0x2DE65F24L}},
              {{0xBC74B2C9L}, {0xBC74B2C9L}, {0x2DE65F24L}},
              {{0xBC74B2C9L}, {0xBC74B2C9L}, {0x2DE65F24L}},
              {{0xBC74B2C9L}, {0xBC74B2C9L}, {0x2DE65F24L}},
              {{0xBC74B2C9L}, {0xBC74B2C9L}, {0x2DE65F24L}}};
          int i, j, k;
          for (i = 0; i < 1; i++) {
            for (j = 0; j < 1; j++)
              l_2340[i][j] = 0x4378ACC6L;
          }
          l_31[7][2] &= p_14;
          for (g_140 = 4; (g_140 >= 0); g_140 -= 1) {
            int32_t l_2325 = 1L;
            int32_t l_2331 = 0x7B38606AL;
            int32_t l_2335 = 5L;
            int32_t l_2336 = (-9L);
            int32_t l_2339[6];
            int i;
            for (i = 0; i < 6; i++)
              l_2339[i] = (-1L);
            if (g_466[g_140])
              break;
            l_2348[5][0][0]++;
            l_2329 =
                (((g_238 &= 0x0746L) ||
                  ((l_2347 = (l_2345[5] = p_14)),
                   ((safe_rshift_func_uint16_t_u_u(
                        (l_2346[2] ^
                         (((safe_rshift_func_uint16_t_u_u(
                               g_5,
                               (g_395 =
                                    ((safe_sub_func_uint32_t_u_u(
                                         ((safe_unary_minus_func_uint16_t_u(
                                              g_147)) |
                                          ((g_466[g_140] =
                                                ((l_2292[2][7][0] >
                                                  (((safe_div_func_int8_t_s_s(
                                                        p_14,
                                                        (1L |
                                                         ((l_1936, 0xD7L) <=
                                                          p_14)))) >= 0UL),
                                                   0L)) > 0xBBL)) |
                                           g_1815)),
                                         p_14)) <= l_1996)))) |
                           0x263C4B7BL) ^
                          g_1441)),
                        10)),
                    1UL))) ||
                 p_14);
          }
          if ((safe_lshift_func_uint8_t_u_u(
                  (((safe_div_func_uint32_t_u_u(
                        ((((safe_lshift_func_int8_t_s_s(
                               (safe_sub_func_uint16_t_u_u(
                                   (safe_rshift_func_int8_t_s_s(
                                       (~((safe_unary_minus_func_int16_t_s((~(safe_lshift_func_uint8_t_u_u(
                                              ((p_15 == l_2341) ^
                                               (((safe_add_func_int8_t_s_s(
                                                     (safe_rshift_func_int16_t_s_s(
                                                         (g_1076 =
                                                              (g_147 != 0UL)),
                                                         p_14)),
                                                     0xB3L)),
                                                 (0xC9L &
                                                  ((((safe_rshift_func_int16_t_s_s(
                                                         ((safe_rshift_func_int16_t_s_u(
                                                              ((safe_div_func_int32_t_s_s(
                                                                   (((p_14,
                                                                      ((safe_lshift_func_uint16_t_u_u(
                                                                           0x5A15L,
                                                                           l_25)) <
                                                                       l_1897)) <=
                                                                     9UL) &&
                                                                    6L),
                                                                   p_14)) &
                                                               g_153[0]),
                                                              p_15)) <=
                                                          0xF96BL),
                                                         8)),
                                                     4UL) |
                                                    g_153[0]) ^
                                                   p_14))) &
                                                g_2295[4])),
                                              0))))) ||
                                          l_2318)),
                                       l_2334)),
                                   l_25)),
                               p_15)) |
                           p_14) < 0xEB22L),
                         8UL),
                        l_2341)),
                    p_15) != g_395),
                  l_2385))) {
            int16_t l_2386[7][6][5] = {
                {{1L, (-1L), 1L, 1L, 1L},
                 {0x87A7L, 0xBB7CL, 9L, (-8L), 8L},
                 {1L, (-6L), 0x1A6EL, 1L, 2L},
                 {0x9E3AL, 0xDB1EL, 1L, (-1L), (-1L)},
                 {0x4742L, 1L, 1L, 0x4742L, (-3L)},
                 {0L, 1L, 0x318FL, 0x08B7L, (-1L)}},
                {{(-3L), 0xA959L, 7L, (-8L), 0x7F3CL},
                 {1L, 0x1A6EL, 0xD7E5L, 0x08B7L, (-10L)},
                 {0xCC09L, (-4L), (-10L), 0x4742L, 8L},
                 {0xD21DL, 0xA959L, (-1L), 8L, 1L},
                 {0xF852L, 0x7E0BL, 1L, 4L, 0x0993L},
                 {0xFD12L, (-1L), 0x5B99L, 1L, 0x5CFCL}},
                {{(-5L), 0x08B7L, 9L, 0x5F09L, 0xBF16L},
                 {1L, 8L, (-10L), 0xDB1EL, (-1L)},
                 {(-1L), (-2L), 8L, 3L, 0L},
                 {(-7L), 1L, (-3L), (-5L), 7L},
                 {1L, 1L, 1L, 8L, (-1L)},
                 {1L, (-2L), 0L, 0x3E78L, 0L}},
                {{1L, 8L, 0x551BL, 0xFD12L, 0x8845L},
                 {0x4A0AL, 0x08B7L, 0xD66DL, (-10L), 0x7088L},
                 {0xB95EL, (-1L), 0xF0F8L, 0x9802L, 1L},
                 {1L, 0x7E0BL, 0xDFE1L, (-8L), 0L},
                 {4L, 0xA959L, (-7L), 0xA959L, 4L},
                 {(-3L), 6L, (-1L), 4L, 0xB95EL}},
                {{0xF852L, 0xB95EL, 0L, 0L, 0xBB7CL},
                 {(-5L), 1L, 1L, 6L, 0xB95EL},
                 {0xD21DL, 0L, (-10L), 0x5F09L, 4L},
                 {0xB95EL, 0x5B99L, 3L, (-3L), 0L},
                 {0x5B99L, 0xB1EEL, (-1L), 9L, 1L},
                 {0x08B7L, 1L, (-1L), 0xA959L, 0x7088L}},
                {{0x87A7L, 0x4A0AL, (-2L), 0x3E78L, 0x8845L},
                 {(-1L), 0x5CFCL, 1L, 1L, 0L},
                 {0x4A0AL, 1L, 0xCC09L, 0xD7E5L, (-1L)},
                 {0xD7E5L, 0xBF16L, 0xF0F8L, 0x0568L, 7L},
                 {1L, (-2L), 0xF0F8L, 0x1A6EL, 0L},
                 {1L, 0x8845L, 0xCC09L, 0xF0F8L, (-1L)}},
                {{1L, 6L, 1L, (-5L), 0xBF16L},
                 {(-3L), 0xD7E5L, (-2L), 0L, 0x5CFCL},
                 {1L, (-1L), (-1L), 0xA65CL, 0x0993L},
                 {0xD21DL, 8L, (-1L), 6L, 1L},
                 {0xD7E5L, (-7L), 3L, 3L, (-7L)},
                 {(-2L), 0x5B7EL, (-10L), (-1L), 1L}}};
            int32_t l_2387 = 0x93084174L;
            int32_t l_2388 = (-8L);
            int32_t l_2389 = 0x853B6491L;
            int32_t l_2390 = 0x1171EB6CL;
            int32_t l_2392 = 0xCD329ACFL;
            int i, j, k;
            --l_2393[2][4][0];
          } else {
            uint16_t l_2406 = 0xC90BL;
            int32_t l_2412 = (-1L);
            int32_t l_2413[5][8] = {
                {1L, 0L, 0xA9EA0BDFL, 1L, 0xA9EA0BDFL, 0L, 1L, 0xAD7F3E80L},
                {0xC0DFDE0FL, 0xAD7F3E80L, 0xA9EA0BDFL, 0L, (-5L), 0L,
                 0xA9EA0BDFL, 0xAD7F3E80L},
                {0xA9EA0BDFL, 3L, 0xE0DBBD43L, 1L, (-5L), 0xAD7F3E80L, (-5L),
                 1L},
                {0xC0DFDE0FL, 3L, 0xC0DFDE0FL, 0L, 0xC0DFDE0FL, 1L, 1L, 1L},
                {0xA9EA0BDFL, 0L, (-5L), 0L, 0xA9EA0BDFL, 0xAD7F3E80L,
                 0xC0DFDE0FL, 3L}};
            int i, j;
            l_2413[4][2] =
                ((safe_rshift_func_uint8_t_u_u((g_438++), 1)),
                 (((safe_add_func_uint32_t_u_u(
                       g_26[1][0],
                       (safe_lshift_func_uint16_t_u_s(
                           (l_2330[9][1] |= (l_2334 = (g_238 = 0x295DL))),
                           3)))) < 0L) >=
                  (((g_283[5] | g_293[1]) >=
                    (l_2340[0][0] =
                         (0UL ||
                          (((safe_mod_func_int16_t_s_s(
                                (g_255 =
                                     (l_2412 =
                                          (l_2406 >=
                                           (p_14 !=
                                            ((safe_unary_minus_func_uint16_t_u(
                                                 (safe_rshift_func_uint8_t_u_s(
                                                     0UL, l_2118[7][1])))) <
                                             p_15))))),
                                p_14)) >= l_2340[0][0]) |
                           g_438)))) ||
                   p_14)));
          }
        } else {
          uint32_t l_2414[8] = {1UL, 6UL, 1UL, 6UL, 1UL, 6UL, 1UL, 6UL};
          int32_t l_2422 = 0x7C994649L;
          int i;
          for (g_1519 = 0; (g_1519 <= 2); g_1519 += 1) {
            g_153[6] = g_2295[2];
          }
          l_2332 &= (+(
              ((l_2414[1] = 1L) |
               (safe_add_func_int8_t_s_s(
                   ((safe_div_func_uint32_t_u_u(
                        (((l_1935 =
                               ((g_378[5] &&
                                 ((p_14 & (!g_1254)) ||
                                  ((((safe_lshift_func_int8_t_s_s(
                                         l_2421,
                                         ((0x1314L | 0xA43FL),
                                          ((((g_335[3] & g_258), l_2422), p_14),
                                           (-7L))))) != p_14) &
                                    (-2L)) < 0xAEL))) == (-1L))) == p_14) &&
                         0L),
                        g_1462)) &
                    3UL),
                   l_2345[7]))) &&
              0x3757L));
          for (l_2343 = 1; (l_2343 >= 0); l_2343 -= 1) {
            int i;
            l_2423 = (g_283[(l_2343 + 5)] > 0x826B0A22L);
          }
          if (((g_1519 != (l_2344 = l_31[7][2])) >=
               (safe_lshift_func_uint8_t_u_s(
                   ((safe_add_func_int16_t_s_s(
                        g_182[1],
                        ((safe_lshift_func_int8_t_s_s(
                             (safe_lshift_func_int8_t_s_u(
                                 (safe_lshift_func_uint16_t_u_s(
                                     (((g_26[1][3] >=
                                        (p_14 |
                                         ((g_1076 =
                                               (((safe_rshift_func_int16_t_s_u(
                                                     (g_255 ^=
                                                      ((safe_sub_func_int16_t_s_s(
                                                           ((safe_lshift_func_int16_t_s_s(
                                                                ((l_2440 |
                                                                  l_2118[4]
                                                                        [0]) <=
                                                                 (safe_mod_func_uint16_t_u_u(
                                                                     (g_104 = (safe_lshift_func_int8_t_s_s(
                                                                          (safe_add_func_uint16_t_u_u(
                                                                              ((p_15 <
                                                                                (1UL &&
                                                                                 l_2447)),
                                                                               p_14),
                                                                              6L)),
                                                                          6))),
                                                                     p_14))),
                                                                13)) |
                                                            p_15),
                                                           l_2347)) |
                                                       1UL)),
                                                     11)) ^
                                                 g_1260) ||
                                                p_15)) > 1L))) &&
                                       g_293[0]) < p_14),
                                     p_15)),
                                 4)),
                             l_2414[6])) < p_15))) > p_15),
                   4)))) {
            g_283[5] =
                ((safe_add_func_int8_t_s_s(l_2318, p_15)),
                 ((l_2326 = p_15) |
                  (safe_mod_func_int32_t_s_s(
                      ((safe_add_func_int16_t_s_s(0x5946L, 65532UL)) |
                       (((safe_lshift_func_uint16_t_u_s(
                             (((g_255 ^=
                                ((safe_add_func_int32_t_s_s(
                                     (safe_add_func_uint32_t_u_u(
                                         (safe_unary_minus_func_int16_t_s((
                                             (((l_2347 =
                                                    (((g_378[2] >
                                                       (0xE28FFB98L ==
                                                        ((safe_add_func_int16_t_s_s(
                                                             g_86,
                                                             (0x3FL < p_15))) >
                                                         0L))) != 5L),
                                                     9L)) &
                                               p_15) >= p_15) ||
                                             g_5))),
                                         g_592)),
                                     0x2498ED58L)) == 253UL)) |
                               0xF8FEL) ^
                              g_2295[0]),
                             1)),
                         l_2393[3][3][0]) |
                        1UL)),
                      p_14))));
            return p_14;
          } else {
            uint32_t l_2476 = 0xCB30D1D3L;
            int32_t l_2477 = (-2L);
            if (l_2422)
              goto lbl_2463;
            l_1898[3] =
                ((safe_sub_func_uint8_t_u_u(
                     l_2414[1],
                     (((g_5 |
                        (safe_lshift_func_int16_t_s_s(
                            (((safe_rshift_func_int16_t_s_u(
                                  (safe_rshift_func_uint8_t_u_u(
                                      ((safe_lshift_func_uint8_t_u_s(
                                           ((0x8375L &
                                             ((0xEBL != (0xBA26L <= (+(-6L)))) &
                                              (((l_2422 = (l_2334 = p_14)),
                                                (l_2476 = ((g_5 == 0x5CL) ||
                                                           l_2414[0]))) ||
                                               0L))) ||
                                            0L),
                                           g_153[8])) == l_2414[6]),
                                      l_2477)),
                                  p_14)),
                              (-1L)) == 1UL),
                            l_1898[4]))) ||
                       g_395),
                      l_2329))) != 0xC0DBL);
          }
        }
        l_1898[4] = (+(
            l_31[6][3] =
                ((l_1936 |=
                  ((safe_sub_func_uint8_t_u_u(
                       ((p_15 >=
                         (safe_lshift_func_int16_t_s_u(
                             (safe_rshift_func_int8_t_s_u(
                                 (l_1935 = l_1843),
                                 (((l_2393[0][4][0] ||
                                    ((l_2345[0] =
                                          (((safe_div_func_uint16_t_u_u(
                                                ((l_1893 = (g_592 = 4L)) ^
                                                 (safe_mod_func_int16_t_s_s(
                                                     (l_2278 = (safe_sub_func_int32_t_s_s(
                                                          ((safe_add_func_uint16_t_u_u(
                                                               ((safe_div_func_int16_t_s_s(
                                                                    ((safe_div_func_uint8_t_u_u(
                                                                         (g_335
                                                                              [5] <
                                                                          p_15),
                                                                         (safe_sub_func_int8_t_s_s(
                                                                             (safe_add_func_int8_t_s_s(
                                                                                 (l_2343 |=
                                                                                  (safe_sub_func_uint32_t_u_u(
                                                                                      ((p_15 &
                                                                                        l_2278) <
                                                                                       (((safe_div_func_int8_t_s_s(
                                                                                             (-6L),
                                                                                             l_2504)) ||
                                                                                         0x75L) >=
                                                                                        0xBA8C9D55L)),
                                                                                      1L))),
                                                                                 0xC4L)),
                                                                             l_2505)))),
                                                                     0xD87EL),
                                                                    p_14)) <
                                                                0xBD47L),
                                                               p_15)) >= 0L),
                                                          l_2332))),
                                                     p_14))),
                                                l_2506)) |
                                            p_14) &&
                                           0x08L)) &&
                                     0x94C1L)),
                                   0x46L) >= p_14))),
                             l_1896))) <= p_14),
                       l_2292[0][2][0])) >= l_1842)) &
                 0L)));
      }
      for (l_1843 = 0; (l_1843 < (-17));
           l_1843 = safe_sub_func_int16_t_s_s(l_1843, 7)) {
        if (g_181)
          goto lbl_2509;
        for (i = 0; i < 7; i++)
          l_3601[i] = 0x47L;
      }
      l_2510--;
    } else {
      int32_t l_2533 = (-7L);
      int32_t l_2536 = (-7L);
      int32_t l_2545 = 0x81EA0A91L;
      uint16_t l_2588[7] = {0xBC44L, 0xBC44L, 1UL,    0xBC44L,
                            0xBC44L, 1UL,     0xBC44L};
      int32_t l_2591 = (-1L);
      int i;
      if (l_1860)
        ;
    }
    for (i = 0; i < 7; i++)
      l_3601[i] = 0x47L;

  } else {
    uint32_t l_2642[3];
    int32_t l_2644 = 0xD3EED88BL;
    int32_t l_2645[9][10][1] = {{{0L},
                                 {0L},
                                 {0x1A87319EL},
                                 {0x1A87319EL},
                                 {0L},
                                 {0L},
                                 {0L},
                                 {0x9148DA28L},
                                 {3L},
                                 {4L}},
                                {{0x91EBB8D6L},
                                 {0xD6494989L},
                                 {0x522A8A2CL},
                                 {0L},
                                 {0xBD256464L},
                                 {0x7816FE47L},
                                 {0x07887102L},
                                 {(-3L)},
                                 {0x4F82D6E8L},
                                 {0x6D43F7BEL}},
                                {{(-1L)},
                                 {0L},
                                 {(-4L)},
                                 {0x7AC4B346L},
                                 {0x54E75791L},
                                 {0x7AC4B346L},
                                 {(-4L)},
                                 {0L},
                                 {(-1L)},
                                 {0x6D43F7BEL}},
                                {{0x4F82D6E8L},
                                 {(-3L)},
                                 {0x07887102L},
                                 {0x7816FE47L},
                                 {0xBD256464L},
                                 {0L},
                                 {0x522A8A2CL},
                                 {0xD6494989L},
                                 {0x91EBB8D6L},
                                 {4L}},
                                {{3L},
                                 {0x9148DA28L},
                                 {0L},
                                 {0L},
                                 {0L},
                                 {0x1A87319EL},
                                 {0x1A87319EL},
                                 {0L},
                                 {0L},
                                 {0L}},
                                {{0x9148DA28L},
                                 {3L},
                                 {4L},
                                 {0x91EBB8D6L},
                                 {0xD6494989L},
                                 {0x522A8A2CL},
                                 {0L},
                                 {0xBD256464L},
                                 {0x7816FE47L},
                                 {0x07887102L}},
                                {{(-3L)},
                                 {0x4F82D6E8L},
                                 {0x6D43F7BEL},
                                 {(-1L)},
                                 {0L},
                                 {(-4L)},
                                 {0x7AC4B346L},
                                 {0x54E75791L},
                                 {0x7AC4B346L},
                                 {(-4L)}},
                                {{0L},
                                 {(-1L)},
                                 {0x6D43F7BEL},
                                 {0x4F82D6E8L},
                                 {(-3L)},
                                 {0x07887102L},
                                 {0x7816FE47L},
                                 {0xBD256464L},
                                 {0L},
                                 {0x522A8A2CL}},
                                {{0xD6494989L},
                                 {0x91EBB8D6L},
                                 {4L},
                                 {3L},
                                 {0x9148DA28L},
                                 {0L},
                                 {0L},
                                 {0L},
                                 {0x1A87319EL},
                                 {0x1A87319EL}}};
    int i, j, k;
    for (i = 0; i < 3; i++)
      l_2642[i] = 0x289267C1L;
    l_2645
      [2]
      [8]
      [0]
      =
      (0UL
       ^
       ((g_283[2] = (g_378[6], ((p_15 == (l_31[7][2] = (!(safe_sub_func_uint8_t_u_u ((safe_rshift_func_int8_t_s_s ((((safe_lshift_func_int8_t_s_u (0L, 1)) == ((l_2644 &= (l_1860 || ((((g_2643[0] = ((safe_add_func_uint16_t_u_u (((7UL ^ (safe_mod_func_int32_t_s_s (((safe_add_func_uint16_t_u_u (((((safe_add_func_int16_t_s_s ((((safe_lshift_func_int16_t_s_s ((safe_lshift_func_uint16_t_u_s ((safe_add_func_uint8_t_u_u (g_283[3], (g_592 &= (!(((((safe_rshift_func_uint16_t_u_s ((safe_add_func_int16_t_s_s (g_293[3], (((((((safe_lshift_func_int8_t_s_u (0x40L, 3)) ^ 2L), l_31[7][2]) <= 0x83L) && p_14) == 0xEE48L), g_5))), l_2552[1])) | l_2642[0]) | 0x45729D35L) <= p_15) == g_182[0]))))), 15)), 4)) == g_2643[0]) || g_293[0]), g_466[2])) | p_15) || g_592), g_147), 0UL)) != g_258), 1L))) <= g_466[0]), l_2587[3][0][6])) < g_293[0])) == 6L) || p_15) >= 1UL))) > 1UL)) | l_2642[0]), 5)), (-8L)))))) ^ p_15))) & l_2642[1]));
  }
  if ((+(!(-8L)))) {
    int32_t l_2646 = 0x4B708CD9L;
    int16_t l_2660 = 0x2905L;
    int32_t l_2679[1][5] = {{(-2L), (-2L), (-2L), (-2L), (-2L)}};
    int32_t l_2721[3][3] = {{1L, 0xD9F415FFL, 1L},
                            {0xDC0CF794L, 0xDC0CF794L, 0xDC0CF794L},
                            {1L, 0xD9F415FFL, 1L}};
    int32_t l_2722 = 0xD80A231BL;
    uint32_t l_2723[7][2] = {
        {0xE992933DL, 0xE992933DL}, {0xE992933DL, 0xE992933DL},
        {0xE992933DL, 0xE992933DL}, {0xE992933DL, 0xE992933DL},
        {0xE992933DL, 0xE992933DL}, {0xE992933DL, 0xE992933DL},
        {0xE992933DL, 0xE992933DL}};
    int32_t l_2724 = 0x458631ECL;
    uint32_t l_2772 = 0xF3D6F75AL;
    uint8_t l_2853 = 0x2BL;
    uint8_t l_2990 = 0x54L;
    int32_t l_3145 = 0x83379901L;
    int16_t l_3170 = 1L;
    uint8_t l_3257 = 0xDAL;
    uint32_t l_3351[9][6][4] = {
        {{4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL},
         {4294967294UL, 4294967295UL, 0xC6097374L, 4294967295UL},
         {4294967295UL, 0xEDB3F67CL, 0xC6097374L, 0xC6097374L},
         {4294967294UL, 4294967294UL, 4294967295UL, 0xEDB3F67CL},
         {0xC6097374L, 4294967294UL, 0xC6097374L, 4294967295UL},
         {0xC6097374L, 4294967295UL, 4294967295UL, 0xC6097374L}},
        {{4294967295UL, 4294967295UL, 0xEDB3F67CL, 4294967295UL},
         {4294967295UL, 4294967294UL, 0xEDB3F67CL, 0xEDB3F67CL},
         {4294967295UL, 4294967295UL, 4294967295UL, 0xEDB3F67CL},
         {0xC6097374L, 4294967294UL, 0xC6097374L, 4294967295UL},
         {0xC6097374L, 4294967295UL, 4294967295UL, 0xC6097374L},
         {4294967295UL, 4294967295UL, 0xEDB3F67CL, 4294967295UL}},
        {{4294967295UL, 4294967294UL, 0xEDB3F67CL, 0xEDB3F67CL},
         {4294967295UL, 4294967295UL, 4294967295UL, 0xEDB3F67CL},
         {0xC6097374L, 4294967294UL, 0xC6097374L, 4294967295UL},
         {0xC6097374L, 4294967295UL, 4294967295UL, 0xC6097374L},
         {4294967295UL, 4294967295UL, 0xEDB3F67CL, 4294967295UL},
         {4294967295UL, 4294967294UL, 0xEDB3F67CL, 0xEDB3F67CL}},
        {{4294967295UL, 4294967295UL, 4294967295UL, 0xEDB3F67CL},
         {0xC6097374L, 4294967294UL, 0xC6097374L, 4294967295UL},
         {0xC6097374L, 4294967295UL, 4294967295UL, 0xC6097374L},
         {4294967295UL, 4294967295UL, 0xEDB3F67CL, 4294967295UL},
         {4294967295UL, 4294967294UL, 0xEDB3F67CL, 0xEDB3F67CL},
         {4294967295UL, 4294967295UL, 4294967295UL, 0xEDB3F67CL}},
        {{0xC6097374L, 4294967294UL, 0xC6097374L, 4294967295UL},
         {0xC6097374L, 4294967295UL, 4294967295UL, 0xC6097374L},
         {4294967295UL, 4294967295UL, 0xEDB3F67CL, 4294967295UL},
         {4294967295UL, 4294967294UL, 0xEDB3F67CL, 0xEDB3F67CL},
         {4294967295UL, 4294967295UL, 4294967295UL, 0xEDB3F67CL},
         {0xC6097374L, 4294967294UL, 0xC6097374L, 4294967295UL}},
        {{0xC6097374L, 4294967295UL, 4294967295UL, 0xC6097374L},
         {4294967295UL, 4294967295UL, 0xEDB3F67CL, 4294967295UL},
         {4294967295UL, 4294967294UL, 0xEDB3F67CL, 0xEDB3F67CL},
         {4294967295UL, 4294967295UL, 4294967295UL, 0xEDB3F67CL},
         {0xC6097374L, 4294967294UL, 0xC6097374L, 4294967295UL},
         {0xC6097374L, 4294967295UL, 4294967295UL, 0xC6097374L}},
        {{4294967295UL, 4294967295UL, 0xEDB3F67CL, 4294967295UL},
         {4294967295UL, 4294967294UL, 0xEDB3F67CL, 0xEDB3F67CL},
         {4294967295UL, 4294967295UL, 4294967295UL, 0xEDB3F67CL},
         {0xC6097374L, 4294967294UL, 0xC6097374L, 4294967295UL},
         {0xC6097374L, 4294967295UL, 4294967295UL, 0xC6097374L},
         {4294967295UL, 4294967295UL, 0xEDB3F67CL, 4294967295UL}},
        {{4294967295UL, 4294967294UL, 0xEDB3F67CL, 0xEDB3F67CL},
         {4294967295UL, 4294967295UL, 4294967295UL, 0xEDB3F67CL},
         {0xC6097374L, 4294967294UL, 0xC6097374L, 4294967295UL},
         {0xC6097374L, 4294967295UL, 4294967295UL, 0xC6097374L},
         {4294967295UL, 4294967295UL, 0xEDB3F67CL, 4294967295UL},
         {4294967295UL, 4294967294UL, 0xEDB3F67CL, 0xEDB3F67CL}},
        {{4294967295UL, 4294967295UL, 4294967295UL, 0xEDB3F67CL},
         {0xC6097374L, 4294967294UL, 0xC6097374L, 4294967295UL},
         {0xC6097374L, 4294967295UL, 4294967295UL, 0xC6097374L},
         {4294967295UL, 0xC6097374L, 4294967294UL, 0xC6097374L},
         {0xC6097374L, 4294967295UL, 4294967294UL, 4294967294UL},
         {4294967295UL, 4294967295UL, 0xC6097374L, 4294967294UL}}};
    uint8_t l_3354 = 0xFAL;
    int32_t l_3510[1][8] = {{0x1F52AC1AL, 0x1F52AC1AL, 0x1F52AC1AL, 0x1F52AC1AL,
                             0x1F52AC1AL, 0x1F52AC1AL, 0x1F52AC1AL,
                             0x1F52AC1AL}};
    int32_t l_3551[6];
    int16_t l_3564 = 0x238AL;
    int8_t l_3621 = 0x04L;
    int8_t l_3637 = 0xFDL;
    int i, j, k;
    for (i = 0; i < 6; i++)
      l_3551[i] = 5L;
    if (g_255) {
      return l_2646;
    } else {
      int32_t l_2677[10] = {0xA9F00338L, 0xA9F00338L, 0xA9F00338L, 0xA9F00338L,
                            0xA9F00338L, 0xA9F00338L, 0xA9F00338L, 0xA9F00338L,
                            0xA9F00338L, 0xA9F00338L};
      int32_t l_2678 = 1L;
      int16_t l_2702 = 0x9DAFL;
      int32_t l_2716 = (-1L);
      int i;
      l_2677[5] = (safe_lshift_func_int8_t_s_s(
          ((safe_lshift_func_int16_t_s_s(
               (((((safe_rshift_func_uint16_t_u_u(l_2653, p_15)) >
                   (safe_mod_func_uint16_t_u_u(0x2E80L, (p_15 || p_14)))) ^
                  (safe_mod_func_uint32_t_u_u(
                      ((l_2679[0][4] = (safe_sub_func_int16_t_s_s(
                            l_2660,
                            (+((((((((safe_div_func_uint16_t_u_u(
                                         p_14,
                                         (safe_lshift_func_uint8_t_u_u(
                                             (safe_div_func_uint32_t_u_u(
                                                 (((safe_add_func_int16_t_s_s(
                                                       (((safe_lshift_func_int16_t_s_s(
                                                             ((g_335[0]++),
                                                              (((safe_lshift_func_uint8_t_u_s(
                                                                    p_15,
                                                                    ((safe_div_func_uint16_t_u_u(
                                                                         0x9841L,
                                                                         l_2677
                                                                             [5])) <=
                                                                     0x20E1L))) !=
                                                                0xB743L) <=
                                                               l_2677[9])),
                                                             g_147)) ==
                                                         g_293[0]) ^
                                                        l_2677[2]),
                                                       g_1462)) <= p_15) >
                                                  p_15),
                                                 (-5L))),
                                             6)))) <= l_2653) ||
                                    l_2646) <= g_104) == 0UL),
                                 g_2643[2]),
                                (-1L)) &
                               l_2678))))),
                       g_466[0]),
                      0xF6A12685L))) != l_2677[5]),
                p_15),
               g_258)),
           g_1185),
          g_153[0]));
      for (g_1260 = (-30); (g_1260 <= 21);
           g_1260 = safe_add_func_uint16_t_u_u(g_1260, 2)) {
        uint8_t l_2701[7][6] = {{255UL, 0UL, 0xD1L, 0x0BL, 0UL, 0UL},
                                {0xD1L, 1UL, 4UL, 0x59L, 0x99L, 4UL},
                                {0xD1L, 0UL, 0x59L, 0x0BL, 2UL, 0x0BL},
                                {255UL, 0UL, 255UL, 4UL, 0x99L, 0x59L},
                                {0UL, 1UL, 255UL, 0UL, 0UL, 0x0BL},
                                {0x0BL, 0UL, 0x59L, 0UL, 0x16L, 4UL},
                                {0UL, 0x16L, 4UL, 4UL, 0x16L, 0UL}};
        int i, j;
        if (((safe_div_func_int16_t_s_s(
                 g_466[0],
                 (safe_lshift_func_uint8_t_u_s(
                     ((safe_rshift_func_int8_t_s_u(
                          p_14,
                          (safe_rshift_func_int16_t_s_u(
                              (safe_add_func_int8_t_s_s(
                                  ((safe_add_func_uint32_t_u_u(
                                       (((((safe_add_func_uint32_t_u_u(
                                               (((safe_sub_func_uint32_t_u_u(
                                                     ((p_15 ||
                                                       (l_1935 |=
                                                        (l_2504 &=
                                                         (safe_lshift_func_int16_t_s_s(
                                                             l_2646, 4))))) ||
                                                      g_2643[0]),
                                                     (l_2679[0][2] ^=
                                                      ((l_2700 = 0xF5L) ^
                                                       l_2678)))) &&
                                                 0xBFL) == p_15),
                                               p_14)) >= 1UL),
                                          p_15),
                                         p_15) |
                                        0x50L),
                                       l_2701[1][4])),
                                   l_2701[1][4]),
                                  g_181)),
                              9)))) <= p_15),
                     4)))) ||
             g_2295[0])) {
          g_283[3] |= (~p_15);
          return g_592;
        } else {
          uint32_t l_2703[9] = {4294967295UL, 4294967295UL, 4294967295UL,
                                4294967295UL, 4294967295UL, 4294967295UL,
                                4294967295UL, 4294967295UL, 4294967295UL};
          int i;
          --l_2703[1];
          return g_2643[3];
        }
      }
      g_153[0] = p_14;
      g_283[3] = (safe_mod_func_int16_t_s_s(
          l_2677[5],
          (safe_add_func_int32_t_s_s(
              ((l_1936 &=
                ((safe_rshift_func_uint16_t_u_u(
                     (((safe_add_func_uint8_t_u_u(
                           (p_15 <=
                            ((l_2716 = (0x88982177L || g_734)),
                             (((((l_2679[0][4] |= 4294967293UL) ==
                                 (((safe_rshift_func_uint16_t_u_s(1UL, 3)) ||
                                   g_734) <
                                  ((((l_2722 |=
                                      ((l_2721[1][2] =
                                            (safe_div_func_int32_t_s_s(
                                                l_2678, 0x69A0ABE3L))) <=
                                       l_2677[2])) < 0xCAEDL) ||
                                    1L),
                                   6UL))) > 254UL) != g_238),
                              5UL))),
                           p_15)) < l_2723[3][1]) != 0UL),
                     0)),
                 l_2721[1][2])) != p_14),
              g_238))));
    }
  lbl_3124:
    for (g_734 = 0; (g_734 <= 1); g_734 += 1) {
      int32_t l_2738[1];
      int32_t l_2899[5][1];
      int8_t l_2934 = 0xFDL;
      uint16_t l_2950 = 65533UL;
      int32_t l_3021 = 8L;
      int i, j;
      for (i = 0; i < 1; i++)
        l_2738[i] = (-1L);
      for (i = 0; i < 5; i++) {
        for (j = 0; j < 1; j++)
          l_2899[i][j] = 0xFDB17862L;
      }
      l_2738[0] =
          (((~((((((g_2737 |=
                    (l_2724 !=
                     ((g_283[3] =
                           ((g_1655 ==
                             ((safe_lshift_func_int16_t_s_u(
                                  (((g_2295[0] = p_15) <
                                    (((((((safe_rshift_func_int16_t_s_s(
                                              ((p_15,
                                                (safe_div_func_int32_t_s_s(
                                                    g_1655, g_212[0][0][1]))),
                                               ((g_1462 &
                                                 (l_31[7][2] =
                                                      (l_1935 = g_378[6]))) !=
                                                (l_2721[1][2] =
                                                     (((safe_mod_func_uint8_t_u_u(
                                                           (+(p_15 == g_255)),
                                                           0x27L)) &&
                                                       p_15) == g_153[0])))),
                                              g_293[0])),
                                          0x55L) &&
                                         g_335[5]),
                                        0xD6L) >= l_2722),
                                      g_2643[0]) >= g_1462)) > 0x7D840F79L),
                                  g_104)) >= 255UL)) == l_2660)),
                      l_31[7][3]))) <= p_14) ||
                  65527UL) ||
                 g_335[1]),
                l_2653) ^
               0xA1L)) &
            l_2738[0]) &
           g_1047);
      if (((safe_mod_func_uint8_t_u_u(
               p_14,
               (safe_lshift_func_int8_t_s_s(
                   ((g_147,
                     (safe_mod_func_int8_t_s_s(
                         ((g_1260 < l_2738[0]) &&
                          (((+(((l_31[7][2] = (safe_div_func_uint32_t_u_u(
                                     (safe_lshift_func_int8_t_s_u(g_181, 5)),
                                     ((p_14 |
                                       (p_14 <
                                        (((safe_add_func_int8_t_s_s(
                                              (((safe_div_func_int16_t_s_s(
                                                    p_15, g_182[0])),
                                                g_395),
                                               0x9CL),
                                              p_15)) &
                                          0UL) &
                                         g_119))) &
                                      g_153[8])))) >= g_153[0]),
                               0xD9L)) < 0x2FL) > g_140)),
                         0x1DL))) != l_2346[6]),
                   5)))),
           g_182[0])) {
        int32_t l_2765 = 9L;
        int32_t l_2793 = 1L;
        int32_t l_2794 = 0x608D6ABAL;
        int32_t l_2795 = (-10L);
        int32_t l_2959 = 1L;
        for (g_592 = 0; (g_592 <= 1); g_592 += 1) {
          int32_t l_2792 = (-1L);
          uint32_t l_2897[4] = {0x1A5F911BL, 0x1A5F911BL, 0x1A5F911BL,
                                0x1A5F911BL};
          int32_t l_2898 = 0xD4C29BCCL;
          int i, j;
          if ((g_2737 = (safe_rshift_func_int16_t_s_s(
                   (((((6UL <=
                        (((l_2723[(g_592 + 4)][g_592] <=
                           (((safe_rshift_func_int8_t_s_s(
                                 ((0x71E6E1D5L <=
                                   ((g_293[(g_734 + 2)]++),
                                    (safe_mod_func_uint8_t_u_u(
                                        (l_2723[(g_734 + 1)][g_592] >=
                                         l_2723[(g_592 + 3)][g_592]),
                                        (+(((l_2723[(g_592 + 3)][g_734],
                                             (p_15 = g_293[(g_592 + 2)])) >
                                            l_2552[g_734]) &&
                                           (((safe_rshift_func_int16_t_s_u(
                                                 l_2738[0], p_15)),
                                             p_14) < l_2679[0][4]))))))) <=
                                  0x0CL),
                                 l_2765)),
                             0L) > p_14)),
                          l_2765) ||
                         l_2723[3][1])) >= g_26[0][0]),
                      0xCA93L) |
                     0x07BAL) ^
                    g_153[0]),
                   11)))) {
            int8_t l_2777 = 0xDDL;
            l_2738[0] = (safe_sub_func_uint8_t_u_u(
                (safe_mod_func_uint8_t_u_u(p_14, (--p_15))),
                ((++l_2772) &&
                 (safe_mod_func_uint16_t_u_u(
                     l_2777,
                     (safe_add_func_uint8_t_u_u(
                         (g_2643[0] || (p_14, (p_14, g_181))),
                         (safe_div_func_int8_t_s_s(
                             (l_2721[1][2] =
                                  ((g_182[0] &
                                    (l_2504 =
                                         ((safe_add_func_uint16_t_u_u(
                                              (g_104 =
                                                   ((safe_lshift_func_uint8_t_u_s(
                                                        g_293[(g_592 + 2)],
                                                        2)) &
                                                    (((~(+(
                                                          safe_mod_func_int32_t_s_s(
                                                              l_1860, 1UL)))) <
                                                      0xF2E0L) ^
                                                     0x5AL))),
                                              (-1L))),
                                          g_2643[0]))),
                                   g_378[5])),
                             g_1441)))))))));
            l_2738[0] = p_14;
            if (l_2765)
              break;
            l_2504 = ((p_14 | 0x70EF3621L) &&
                      (safe_rshift_func_uint8_t_u_u(
                          (safe_div_func_uint32_t_u_u(l_2765, g_182[1])), 5)));
          } else {
            uint32_t l_2796 = 4UL;
            --l_2796;
            return p_14;
          }
          g_283[2] = l_2646;
          for (g_1655 = 0; (g_1655 <= 1); g_1655 += 1) {
            l_2795 = g_181;
            return g_1076;
          }
   if (((l_31[0][0] |= (l_2738[0] = (safe_lshift_func_uint16_t_u_s ((safe_rshift_func_uint8_t_u_u ((safe_add_func_int8_t_s_s ((l_2793 |= (safe_lshift_func_int16_t_s_s ((safe_div_func_int8_t_s_s ((((p_15 == (((safe_add_func_int16_t_s_s ((safe_rshift_func_uint16_t_u_s (((0x6696L > (safe_lshift_func_uint8_t_u_u ((((p_14 & (((safe_rshift_func_uint8_t_u_s (((1L != (safe_add_func_uint8_t_u_u ((safe_sub_func_uint16_t_u_u (p_15, (l_2679[0][4] |= ((((safe_mod_func_uint8_t_u_u ((l_2721[1][2] |= (safe_div_func_int8_t_s_s ((l_2825[3][3], (safe_add_func_int16_t_s_s ((safe_lshift_func_int16_t_s_u (l_2738[0], 0)), ((safe_mod_func_int16_t_s_s ((((0x55L || (p_14 >= 0xEDFDL)) >= 0xBCL), g_293[0]), 0x755CL)) == l_2552[g_734])))), g_293[(g_592 + 2)]))), 0x47L)), 7UL) > l_2792), 0xBC65L)))), l_2825[2][3]))) || g_1047), p_14)) ^ g_182[0]), g_283[3])) | g_119) <= l_2792), l_2660))) > p_15), l_2738[0])), l_2722)) || 254UL) & p_15)) | l_2723[2][1]) != g_238), 249UL)), l_2825[3][3]))), p_14)), g_153[0])), 11)))) && g_466[2]))
   {
     uint8_t l_2842 = 254UL;
     l_2794 |=
         ((((safe_mod_func_uint32_t_u_u(
                (0x9449L !=
                 (((safe_lshift_func_uint16_t_u_s(
                       ((safe_sub_func_int32_t_s_s(
                            ((((l_2825[3][3] = 9L), (l_2792 = l_2724)) ==
                              0UL) >=
                             (safe_mod_func_int32_t_s_s(
                                 (((p_14 < (l_2795 |= l_2842)), 247UL) ||
                                  (safe_lshift_func_uint16_t_u_s(
                                      (l_2793 <=
                                       ((safe_div_func_uint16_t_u_u(
                                            (l_2853 = (safe_div_func_uint8_t_u_u(
                                                 ((safe_rshift_func_int16_t_s_u(
                                                      (safe_sub_func_int8_t_s_s(
                                                          0x50L,
                                                          g_293[(g_734 + 2)])),
                                                      p_15)) !=
                                                  l_2723[(g_592 + 3)][g_734]),
                                                 g_1462))),
                                            g_734)),
                                        p_15)),
                                      7))),
                                 (-1L)))),
                            g_258)),
                        g_293[3]),
                       3)) <= g_293[3]) != p_14)),
                (-1L))) &
            1UL) >= g_104) <= g_1076);
     g_153[0] |=
         ((!(((l_2871 = (safe_add_func_uint16_t_u_u(
                   (safe_sub_func_uint32_t_u_u(
                       (l_2795 =
                            ((65532UL |
                              (((+((g_1462 &=
                                    (l_2792 =
                                         (l_2721[0][2] = (safe_mod_func_uint16_t_u_u(
                                              (l_2738[0] = (safe_sub_func_int32_t_s_s(
                                                   (((safe_rshift_func_uint16_t_u_u(
                                                         (safe_add_func_int32_t_s_s(
                                                             (p_15, 0L),
                                                             (g_2643[3] !=
                                                              (safe_add_func_uint32_t_u_u(
                                                                  ((safe_sub_func_uint16_t_u_u(
                                                                       ((0xEDL ^
                                                                         l_2738
                                                                             [0]) ==
                                                                        (p_14 ||
                                                                         p_14)),
                                                                       ((((g_2870 &&
                                                                           4294967295UL) &&
                                                                          p_15),
                                                                         g_335
                                                                             [1]),
                                                                        l_2842))) <
                                                                   g_283[3]),
                                                                  l_2842))))),
                                                         5)) >= l_2738[0]) &&
                                                    g_255),
                                                   0xAD9E5DCAL))),
                                              0x2AD5L))))) &&
                                   l_2842)) < p_15),
                               g_438)) >= 0xEF14L)),
                       p_14)),
                   0L))) ^
              l_2679[0][4]),
             l_2118[5][0])) < 0xDC543DFCL);
   } else {
     int32_t l_2896[8][10] = {
         {(-2L), 6L, 4L, 0L, 0x118F8043L, 0x4996E841L, 0x9826F16AL, 0xF450EB35L,
          0x60F884EAL, 0x5E41CD9FL},
         {0xFEFFDD80L, 0x1ABF802AL, (-10L), 0xF450EB35L, 7L, 7L, 0xF450EB35L,
          (-10L), 0x1ABF802AL, 0xFEFFDD80L},
         {0x5E41CD9FL, 0x60F884EAL, 0xF450EB35L, 0x9826F16AL, 0x4996E841L,
          0x118F8043L, 0L, 4L, 6L, (-2L)},
         {0L, 0x118F8043L, 0x510045EAL, 0x60F884EAL, 0x4996E841L, 0xE67D6805L,
          7L, 0x760827E9L, 0L, 0xFEFFDD80L},
         {0x4996E841L, 0L, 0L, 0xFA34006CL, 7L, 0xFA34006CL, 0L, 0L,
          0x4996E841L, 0x5E41CD9FL},
         {0xF450EB35L, 7L, 6L, 0x11C6EA0AL, 0x118F8043L, 0x9826F16AL, 0L,
          0xE67D6805L, 0x760827E9L, 0L},
         {0xFA34006CL, 0L, 7L, 0x11C6EA0AL, 0xE67D6805L, (-2L), 1L, 0xFAE77906L,
          0x4996E841L, 0x4996E841L},
         {(-7L), 0xE67D6805L, 6L, 0xFA34006CL, 0xFA34006CL, 6L, 0xE67D6805L,
          (-7L), 0L, 0xF450EB35L}};
     int32_t l_2906 = (-2L);
     int i, j;
     l_2721[1][2] =
         ((safe_sub_func_int16_t_s_s(
              (~(((p_15 != 0xE8L) >=
                  (g_153[3] &=
                   (l_2897[2] = (+(
                        (safe_add_func_int16_t_s_s(
                            ((safe_sub_func_int32_t_s_s(
                                 ((!((safe_add_func_uint32_t_u_u(
                                         (safe_rshift_func_int8_t_s_s(0x3BL,
                                                                      2)),
                                         (safe_mod_func_int16_t_s_s(
                                             ((safe_add_func_uint32_t_u_u(
                                                  ((safe_add_func_int8_t_s_s(
                                                       (safe_div_func_int16_t_s_s(
                                                           (safe_lshift_func_int8_t_s_u(
                                                               ((safe_mod_func_int16_t_s_s(
                                                                    2L,
                                                                    0x3CA0L)) &&
                                                                (g_212[5][0][2],
                                                                 (p_15 &
                                                                  ((p_15 ==
                                                                    ((safe_sub_func_int16_t_s_s(
                                                                         (l_2722 =
                                                                              ((l_2896
                                                                                    [6]
                                                                                    [2] ||
                                                                                253UL) &
                                                                               g_283
                                                                                   [3])),
                                                                         (-8L))),
                                                                     l_2896
                                                                         [6]
                                                                         [2])) &&
                                                                   255UL)))),
                                                               0)),
                                                           0x804AL)),
                                                       l_2896[6][2])) &
                                                   p_15),
                                                  g_74)) ||
                                              l_2504),
                                             l_2510)))) < g_182[0])) ||
                                  l_2794),
                                 g_238)) ||
                             1UL),
                            0xC450L)),
                        0xBE0D45B6L))))) < l_2898)),
              l_2899[3][0])) != 0x46L);
     l_2792 |=
         ((safe_sub_func_int32_t_s_s(
              ((safe_add_func_uint32_t_u_u(
                   p_15,
                   ((safe_add_func_uint16_t_u_u((g_335[2]--),
                                                (0L <= l_2825[3][3]))) |
                    (((((safe_div_func_int32_t_s_s(
                            ((((l_2906 = (safe_sub_func_int8_t_s_s(
                                    ((safe_div_func_uint16_t_u_u(
                                         ((safe_sub_func_int16_t_s_s(
                                              (g_182[0] >= (g_293[0] ^ p_14)),
                                              (-2L))),
                                          (g_395 =
                                               ((((safe_add_func_uint32_t_u_u(
                                                      (((4294967286UL <
                                                         (65535UL == p_14)) &
                                                        0xEF97L) ^
                                                       g_1254),
                                                      1L)),
                                                  0x18L) |
                                                 0xF6L) ||
                                                g_1254))),
                                         l_2001)) ^
                                     0xE2F9E3E0L),
                                    p_15))) &&
                               l_2896[7][0]) &
                              0x9EL) <= p_14),
                            g_466[3])),
                        l_2738[0]) &&
                       0UL),
                      p_14) >= l_2896[7][2])))) != g_1076),
              7L)) &
          g_2737);
     if (p_14)
       continue;
     if (g_5)
       break;
   }
        }
        if ((((((((safe_add_func_uint32_t_u_u(
                      ((((safe_div_func_uint32_t_u_u(
                             ((l_1935 =
                                   (l_2723[3][1] >
                                    (safe_sub_func_int8_t_s_s(
                                        (0xBEF2L !=
                                         (((((~(l_2721[1][2] &
                                                (((safe_sub_func_int8_t_s_s(
                                                      (g_592 =
                                                           (g_74 &&
                                                            (g_1260 &
                                                             ((l_2738[0] |
                                                               ((safe_add_func_uint16_t_u_u(
                                                                    ((safe_mod_func_int32_t_s_s(
                                                                         l_2853,
                                                                         (safe_rshift_func_int16_t_s_s(
                                                                             (g_1815 >=
                                                                              ((((g_378
                                                                                      [6] >=
                                                                                  0x1A917EC0L),
                                                                                 p_15) &&
                                                                                g_182
                                                                                    [1]) !=
                                                                               l_2933
                                                                                   [0]
                                                                                   [1])),
                                                                             12)))) ==
                                                                     g_2737),
                                                                    p_15)) >
                                                                g_2643[0])) <=
                                                              l_25)))),
                                                      0x9EL)),
                                                  l_2724) < p_15))),
                                             p_14),
                                            g_147),
                                           p_15) != 0UL)),
                                        0x42L)))) == 0x657EB1B2L),
                             p_14)),
                         l_31[7][2]) == l_2723[3][1]),
                       0xDFA36E12L),
                      0xA6168718L)) ||
                  p_14) &
                 4294967295UL) ^
                l_2934) != l_2899[3][0]) == l_2679[0][0]) > 0xCCL)) {
          int32_t l_2947 = (-1L);
          int32_t l_2948 = 0x415FAD5CL;
          int32_t l_2957 = 0xD0EA186BL;
          int16_t l_2958 = 1L;
          g_153[9] =
              ((l_2795 =
                    ((safe_mod_func_int16_t_s_s(
                         (safe_add_func_int16_t_s_s(
                             (!g_395),
                             (safe_sub_func_uint8_t_u_u(
                                 ((safe_rshift_func_int16_t_s_s(
                                      (g_182[6] <=
                                       (+(l_2948 =
                                              (0L ^
                                               (((safe_add_func_uint16_t_u_u(
                                                     (7L >
                                                      (safe_mod_func_uint16_t_u_u(
                                                          g_592, l_2947))),
                                                     0x1453L)) ==
                                                 ((-1L) == (p_14, g_1260))) <
                                                p_15))))),
                                      l_2947)),
                                  g_2949),
                                 1L)))),
                         g_74)) <= g_466[2])) == l_2950);
          for (l_2934 = 1; (l_2934 >= 0); l_2934 -= 1) {
            int i, j;
            if (l_2723[(g_734 + 1)][g_734])
              break;
            g_153[0] =
                (((p_14 &
                   ((4L ^ p_15) <
                    (l_2947 &&
                     (((safe_sub_func_uint8_t_u_u(
                           (safe_mul_func_int32_t_s_s(
                               (l_2957, p_15),
                               (l_25 <= (l_2933[0][1] & (p_15 || p_14))))),
                           g_1185)),
                       l_2421) != g_1185)))) <= 1L) < l_2552[0]);
          }
          if (((((((((((--g_2643[2]) |
                       ((safe_mod_func_int8_t_s_s(
                            (g_212[5][0][2],
                             ((safe_rshift_func_uint8_t_u_u(p_15, l_2948)),
                              0x55L)),
                            1UL)) <
                        (l_2957 !=
                         (((g_283[2] |
                            (safe_add_func_int32_t_s_s(
                                (safe_rshift_func_uint16_t_u_s(
                                    (((l_2958 != p_14) || g_74) && 0x83L),
                                    l_2899[2][0])),
                                p_15))) <= g_258),
                          p_15)))) &&
                      p_14) &
                     g_153[9]),
                    p_14) ||
                   0x267B9662L) ^
                  g_1185),
                 g_466[0]) == 0x1EL) == 0x34L)) {
            uint32_t l_2970 = 0UL;
            l_2970--;
            if (p_15)
              continue;
          } else {
            uint8_t l_2973 = 246UL;
            --l_2973;
          }
          for (g_1260 = 0; (g_1260 <= 1); g_1260 += 1) {
            int32_t l_2978 = 6L;
            int32_t l_2979 = 0xA873A961L;
            l_2825[5][0] = g_212[5][0][2];
            g_283[3] =
                (((l_2978 !=
                   (((0x8927L && (l_2979 = (!1L))) ||
                     (((g_74,
                        (((safe_div_func_int32_t_s_s(
                              (g_2982 !=
                               (safe_mod_func_uint8_t_u_u(
                                   ((p_14 | g_1462) == (l_2765 > 4L)), 0xD1L))),
                              g_2737)) ^
                          65527UL) ^
                         p_15)) &
                       l_2679[0][3]) &
                      l_2979)) <= 0L)) == 0UL) ^
                 g_293[2]);
          }
        } else {
          int8_t l_3009 = (-3L);
          uint16_t l_3012[3];
          int i;
          for (i = 0; i < 3; i++)
            l_3012[i] = 0xF0E5L;
          for (g_1260 = 0; g_1260 < 6; g_1260 += 1) {
            for (l_2950 = 0; l_2950 < 4; l_2950 += 1) {
              l_2825[g_1260][l_2950] = (-1L);
            }
          }
   l_2794
     =
     (((~((safe_unary_minus_func_int16_t_s ((safe_div_func_uint16_t_u_u ((((safe_sub_func_int16_t_s_s (((p_15 | l_2990) && (safe_sub_func_int32_t_s_s (((((g_153[9] = (((((g_1047 == (((l_1935 &= (safe_rshift_func_int8_t_s_s (((((safe_add_func_uint8_t_u_u (((l_2721[1][2] = (safe_sub_func_int32_t_s_s ((0L ^ (((p_14, 1UL) & (((safe_mod_func_int32_t_s_s ((safe_rshift_func_int8_t_s_u (p_14, ((safe_div_func_int8_t_s_s ((((((((l_3009 != (safe_rshift_func_uint8_t_u_s ((l_2899[3][0] || p_15), l_3009))) && 0L) < (-1L)) ^ 0UL) ^ 0x31FBL) && l_1860) <= g_104), l_3009)) < p_15))), l_3009)) | 0x77L), l_3012[0])), 0x7F1AL)), g_147))) <= l_2899[2][0]), p_15)) < 0x58E349B3L) < p_14) | 0UL), p_14))) == 0xE445L) == 1L)) <= p_14) & p_14) ^ p_15) & p_14)) > l_3013) > g_734) > 0L), p_14))), 0L)) > 1L), g_283[3]), 0xC48AL)))) == p_14)) != 0xB6L) & l_2933[0][1]);
        }
      } else {
        return p_14;
      }
      l_2825[5][2] ^= (-1L);
      for (l_2934 = 1; (l_2934 >= 0); l_2934 -= 1) {
        uint8_t l_3018 = 1UL;
        int32_t l_3022 = 0x9AA810D2L;
        l_3022 ^=
            (((+(safe_rshift_func_uint16_t_u_u(
                  (((safe_lshift_func_uint8_t_u_s(
                        ((l_3021 &=
                          (((p_14 <=
                             ((g_438 =
                                   (g_238 ==
                                    ((l_3018 >= 0x3DL) >=
                                     (g_283[2] >=
                                      (l_2950 >
                                       ((+((0L <= g_181) ==
                                           (((g_335[1] =
                                                  ((safe_sub_func_uint16_t_u_u(
                                                       0xF4D8L, 0xDFF4L)) ^
                                                   p_15)) &
                                             l_2738[0]) > g_2643[3]))),
                                        0x9DL)))))) ||
                              255UL)),
                            1UL) ^
                           g_283[3])) ^
                         l_2724),
                        p_15)) &
                    l_2772) < 0x288AL),
                  p_15))) ^
              g_1441) &
             0xCCL);
      }
    }
    if (((safe_lshift_func_int8_t_s_u(
             ((g_3025, (l_2825[0][0] = g_140)) >=
              (safe_div_func_int8_t_s_s(
                  ((safe_mod_func_uint16_t_u_u(
                       (safe_lshift_func_uint16_t_u_u(
                           l_2700,
                           (safe_add_func_uint8_t_u_u(
                               (safe_div_func_uint8_t_u_u(0x95L, p_14)),
                               (((((~(p_15 <= ((((l_2933[0][1] &&
                                                  (safe_lshift_func_int8_t_s_s(
                                                      (((p_14 & g_466[3]), 1L) &
                                                       g_466[4]),
                                                      0))) != g_2870) !=
                                                p_14) != g_238))) &
                                   0xBE2DL) ^
                                  p_15) == l_2724) >= p_15))))),
                       g_1815)) &
                   p_15),
                  9UL))),
             6)) > l_1860)) {
      int32_t l_3068 = 0xAEE34D1CL;
      for (l_2772 = (-28); (l_2772 != 52); l_2772++) {
        int8_t l_3072 = 0x54L;
 g_283
   [3]
   =
   (l_2721
    [0]
    [0]
    =
    (l_2679
     [0]
     [4]
     &=
     (+
      (safe_div_func_uint32_t_u_u
       ((((0UL | (safe_lshift_func_uint16_t_u_s ((((safe_rshift_func_uint8_t_u_u ((safe_lshift_func_int16_t_s_s ((safe_div_func_uint8_t_u_u (((g_2949 &= (1UL >= ((safe_add_func_int8_t_s_s ((((!(safe_sub_func_int16_t_s_s (((g_212[6][0][3] = (safe_add_func_int16_t_s_s (l_2723[3][1], ((safe_div_func_uint16_t_u_u ((g_335[5] ^= ((safe_rshift_func_uint16_t_u_s ((((((safe_lshift_func_int16_t_s_s (g_1655, (((safe_mod_func_uint16_t_u_u ((p_14, (safe_div_func_int16_t_s_s ((safe_mod_func_uint32_t_u_u (l_3068, ((safe_unary_minus_func_uint16_t_u (g_147)), (p_15 || (((safe_mod_func_int8_t_s_s (((((l_2871, 0x3635L) || 0x7283L) != l_2723[3][1]) != p_15), l_3068)) < 0x5FL) > 0xB5L))))), l_3072))), l_3072)), g_1260), 0x14F0L))) | p_14) || p_15) && p_14) >= g_1185), 12)) == p_14)), l_3068)) ^ 0x1CL)))) == p_14), 1UL))) || 5L) || 9L), l_3068)), 249UL))) | g_3025), p_14)), 6)), l_3072)) >= 0x5F80L) != g_104), 1))) || p_15) <= g_182[4]), p_15)))));
 l_2679[0][4] &=
     ((g_86 = (-1L)),
      (~(safe_lshift_func_uint16_t_u_u(
          (safe_sub_func_uint8_t_u_u((g_3025 == (l_2721[2][2] = p_15)), p_14)),
          5))));
      }
      return p_14;
    } else {
      int16_t l_3083 = 0xBE7BL;
      int32_t l_3099 = 1L;
      int32_t l_3101 = 0xC3304EDDL;
      int32_t l_3107 = 0L;
      int32_t l_3108 = 0xAFD932BCL;
      int32_t l_3112 = 0x57916956L;
      int32_t l_3114 = 0x35B4FB63L;
      int32_t l_3116 = 0x703C071EL;
      int32_t l_3117 = 1L;
      int32_t l_3118 = 6L;
      uint8_t l_3121[7] = {0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL};
      int32_t l_3131 = 0x78518540L;
      int16_t l_3187 = 0x4014L;
      uint32_t l_3199[10];
      int32_t l_3238 = (-2L);
      int32_t l_3352 = 1L;
      uint32_t l_3353 = 0UL;
      int8_t l_3407 = (-1L);
      int32_t l_3463 = 0xA6B06964L;
      int8_t l_3504 = 0L;
      int16_t l_3539 = (-1L);
      int16_t l_3600 = (-5L);
      int32_t l_3622[3][8] = {
          {0xC6FD1A9BL, 0xBD19921EL, 0xBD19921EL, 0xC6FD1A9BL, 0xC6FD1A9BL,
           0xBD19921EL, 0xBD19921EL, 0xC6FD1A9BL},
          {0xC6FD1A9BL, 0xBD19921EL, 0xBD19921EL, 0xC6FD1A9BL, 0xC6FD1A9BL,
           0xBD19921EL, 0xBD19921EL, 0xC6FD1A9BL},
          {0xC6FD1A9BL, 0xBD19921EL, 0xBD19921EL, 0xC6FD1A9BL, 0xC6FD1A9BL,
           0xBD19921EL, 0xBD19921EL, 0xC6FD1A9BL}};
      int32_t l_3640[5][5] = {
          {0xDE9C82EBL, 0xC202D400L, 6L, 0xC202D400L, 0xDE9C82EBL},
          {0xD5BF106EL, (-1L), 3L, (-1L), (-1L)},
          {0xDE9C82EBL, 3L, 3L, 0xDE9C82EBL, (-1L)},
          {0xC202D400L, 0xDE9C82EBL, 6L, (-1L), (-1L)},
          {0xD5BF106EL, 0xDE9C82EBL, 0xD5BF106EL, (-1L), 0xDE9C82EBL}};
      int i, j;
      for (i = 0; i < 10; i++)
        l_3199[i] = 8UL;
      for (l_2772 = 0; (l_2772 <= 1); l_2772 += 1) {
        int32_t l_3103 = 0x8BF30E8CL;
        int32_t l_3104 = 0xE5886D35L;
        int32_t l_3110 = 0x86B66048L;
        int32_t l_3111[3][4] = {
            {0x53C284EEL, 0xC79A429FL, 0x53C284EEL, 0xC79A429FL},
            {0x53C284EEL, 0xC79A429FL, 0x53C284EEL, 0xC79A429FL},
            {0x53C284EEL, 0xC79A429FL, 0x53C284EEL, 0xC79A429FL}};
        int i, j;
        if (((!(safe_rshift_func_uint16_t_u_s(
                 (safe_lshift_func_int8_t_s_s(
                     ((safe_div_func_int16_t_s_s(
                          ((((l_2721[1][2] =
                                  (((((l_3083 ^= l_2552[l_2772]) ||
                                      (p_14 |
                                       (safe_add_func_uint32_t_u_u(
                                           ((safe_sub_func_int32_t_s_s(
                                                (0xDF81C58CL && g_238),
                                                (((g_182[0], (1L >= l_3083)) ^
                                                  l_3088) >= 255UL))) ||
                                            p_15),
                                           p_15)))),
                                     0L),
                                    l_2552[l_2772]) ^
                                   l_2933[3][1])) ||
                             p_14) == (-1L)) &&
                           l_31[7][2]),
                          l_2510)) ||
                      l_3083),
                     g_181)),
                 g_592))) <= 0xACB962FAL)) {
          l_1936 = (0x1F6FL &
                    (p_14 !=
                     (((g_2295[0] =
                            (safe_sub_func_int16_t_s_s((0x85L < 0L), g_2982))) ^
                       p_14),
                      (safe_lshift_func_uint16_t_u_u(
                          ((0xE4DFF3B7L <=
                            (safe_lshift_func_int16_t_s_s(
                                (-1L),
                                (safe_div_func_int32_t_s_s(
                                    (safe_lshift_func_int8_t_s_u(0L, g_283[6])),
                                    (-1L)))))) ||
                           l_31[3][2]),
                          11)))));
          l_3099 = p_15;
        } else {
          int16_t l_3100 = 0x4BDFL;
          int32_t l_3102 = 0x978F22BBL;
          int32_t l_3105 = 0x8499A8E0L;
          int32_t l_3106 = 0x17FCB947L;
          int32_t l_3109 = (-2L);
          int32_t l_3113 = 0xE5A6583FL;
          int32_t l_3115 = 0x03A57AA2L;
          int32_t l_3119 = 0x8E0D0DAFL;
          int32_t l_3120[5] = {(-1L), (-1L), (-1L), (-1L), (-1L)};
          int i;
          ++l_3121[2];
          if (p_14)
            goto lbl_3124;
        }
        for (l_3108 = 0; (l_3108 <= 2); l_3108 += 1) {
          for (l_3099 = 0; (l_3099 <= 2); l_3099 += 1) {
            int i, j;
            return l_2118[(l_3099 + 3)][l_3099];
          }
        }
        for (l_3110 = 0; (l_3110 <= 2); l_3110 += 1) {
          int i, j;
          l_2504 = (l_2118[(l_2772 + 3)][l_2772] && g_438);
        }
      }
      for (g_104 = (-27); (g_104 > 54);
           g_104 = safe_add_func_uint32_t_u_u(g_104, 8)) {
        int16_t l_3138 = 7L;
        int32_t l_3155[3];
        uint8_t l_3282 = 251UL;
        int i;
        for (i = 0; i < 3; i++)
          l_3155[i] = (-7L);
        if ((((p_14,
               ((((safe_lshift_func_uint8_t_u_u(
                      l_3112,
                      (safe_mod_func_uint16_t_u_u(
                          (p_15 ==
                           (l_3131 |
                            (safe_div_func_uint32_t_u_u(
                                (safe_lshift_func_uint8_t_u_u(
                                    ((p_14 !=
                                      (safe_div_func_int8_t_s_s(
                                          (~((((((((((l_2722 =
                                                          (l_3138 = g_104)) ||
                                                     (safe_sub_func_uint8_t_u_u(
                                                         ((((0UL >=
                                                             ((safe_rshift_func_uint16_t_u_s(
                                                                  ((0x34L >
                                                                    ((safe_rshift_func_int16_t_s_s(
                                                                         g_378
                                                                             [1],
                                                                         15)),
                                                                     p_14)) &
                                                                   l_2723[4]
                                                                         [1]),
                                                                  l_2001)),
                                                              p_15)),
                                                            p_14) > l_3116),
                                                          g_153[1]),
                                                         g_238))) ||
                                                    l_2722) != l_3121[2]) !=
                                                  l_3145) &
                                                 0xB6L),
                                                (-1L)) < p_14) |
                                              0x5F3DL) >= g_2737)),
                                          l_3118))) == 0x73L),
                                    7)),
                                l_3146)))),
                          0x624CL)))) > p_14),
                 p_15) ||
                0x19566CB3L)) == 0x264BL) ^
             g_2643[0])) {
          int32_t l_3147 = 0x289F41D2L;
          int32_t l_3148 = (-1L);
          int32_t l_3194 = (-1L);
          int32_t l_3195 = 0L;
          int32_t l_3196 = (-7L);
          int32_t l_3197 = 1L;
          int32_t l_3198[1][9] = {{0x8C801306L, 0x8C801306L, 0x8C801306L,
                                   0x8C801306L, 0x8C801306L, 0x8C801306L,
                                   0x8C801306L, 0x8C801306L, 0x8C801306L}};
          int i, j;
          l_3148 = l_3147;
          if ((safe_sub_func_int16_t_s_s(
                  ((g_1260 >= p_14) ||
                   ((safe_add_func_uint32_t_u_u(
                        (g_212[5][0][2] = (0x7A0367B5L == (g_2737 = p_15))),
                        (safe_add_func_uint8_t_u_u(
                            ((((g_335[5]++) &&
                               (0xFDL ==
                                (safe_mod_func_int32_t_s_s(
                                    (safe_rshift_func_int16_t_s_s(
                                        (+((safe_rshift_func_int16_t_s_u(
                                               (safe_sub_func_int32_t_s_s(
                                                   (-5L),
                                                   ((safe_add_func_int16_t_s_s(
                                                        g_1047,
                                                        ((0x24A4583EL >=
                                                          (safe_mod_func_int8_t_s_s(
                                                              (g_238, (-1L)),
                                                              (-1L)))) ||
                                                         g_182[3]))) ^
                                                    l_2772))),
                                               l_3118)) != l_2990)),
                                        l_3170)),
                                    p_14)))),
                              0xC1L) < 0x4CL),
                            l_3083)))) &
                    p_14)),
                  0x26D1L))) {
            int32_t l_3192 = 0L;
            int32_t l_3193[10][6] = {
                {0xD738CCBAL, 1L, 0xA800174EL, 0x173B1E5AL, 0x173B1E5AL,
                 0xA800174EL},
                {0x5A2CE011L, 0x5A2CE011L, 1L, 0x173B1E5AL, 1L, 0xA73D2B0BL},
                {0xD738CCBAL, 1L, 0xE9214434L, 0xA73D2B0BL, 0xE9214434L, 1L},
                {0x173B1E5AL, 0xD738CCBAL, 0xE9214434L, 0x57302E08L,
                 0x5A2CE011L, 0xA73D2B0BL},
                {0xA800174EL, 0x57302E08L, 1L, 1L, 0x57302E08L, 0xA800174EL},
                {1L, 0x57302E08L, 0xA800174EL, 3L, 0x5A2CE011L, 0xE9214434L},
                {0xE9214434L, 0xD738CCBAL, 0x173B1E5AL, 0xD738CCBAL,
                 0xE9214434L, 0x57302E08L},
                {0xE9214434L, 1L, 0xD738CCBAL, 3L, 1L, 1L},
                {1L, 0x5A2CE011L, 0x5A2CE011L, 1L, 0x173B1E5AL, 1L},
                {0xA800174EL, 1L, 0xD738CCBAL, 0x57302E08L, 3L, 0x57302E08L}};
            int i, j;
            l_2825[3][3] =
                ((safe_sub_func_int8_t_s_s(
                     ((!(((p_15 <
                           ((g_2870 |=
                             (p_15,
                              ((safe_sub_func_int16_t_s_s(
                                   (((safe_lshift_func_int16_t_s_s(0x3EC2L,
                                                                   7)) <=
                                     ((((safe_div_func_uint32_t_u_u(
                                            (safe_rshift_func_int8_t_s_u(
                                                (l_2552[0],
                                                 (safe_rshift_func_int16_t_s_u(
                                                     (((l_2722,
                                                        (+(0xDD8F0E96L ^
                                                           (safe_add_func_int16_t_s_s(
                                                               (safe_div_func_uint32_t_u_u(
                                                                   ((l_3187,
                                                                     ((((safe_lshift_func_int16_t_s_u(
                                                                            ((safe_rshift_func_int16_t_s_s(
                                                                                 g_140,
                                                                                 g_293
                                                                                     [3])),
                                                                             1L),
                                                                            g_438)) |
                                                                        p_14) >=
                                                                       9L),
                                                                      l_3148)) &&
                                                                    g_86),
                                                                   g_153[9])),
                                                               g_1047))))) ||
                                                       p_14) > g_86),
                                                     p_15))),
                                                4)),
                                            g_283[3])),
                                        1UL) ||
                                       l_3155[1]) > g_1655)) > g_1519),
                                   0x7F26L)) == 0xB4L))) < p_14)),
                          p_15) ||
                         l_2825[3][0])) &
                      0xACL),
                     g_2737)) <= g_255);
            l_3199[8]--;
            g_2737 |= l_3116;
     g_283
       [0]
       =
       ((safe_lshift_func_int8_t_s_u ((g_466[0] = p_15), (0x7E8E832CL >= ((((safe_lshift_func_uint16_t_u_s (((safe_sub_func_uint16_t_u_u (((safe_div_func_uint32_t_u_u (((safe_lshift_func_int8_t_s_u (((((safe_unary_minus_func_int32_t_s (g_212[5][0][2])) >= (g_153[7] ^= ((((((safe_add_func_uint8_t_u_u ((l_3215 != ((g_119 ^= ((((((l_3192 < (safe_rshift_func_int16_t_s_u ((l_3118 ^= (safe_sub_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u ((safe_sub_func_uint16_t_u_u (((((l_2721[2][0] &= (safe_lshift_func_uint8_t_u_s (((safe_sub_func_uint16_t_u_u (((safe_lshift_func_int8_t_s_u ((((l_3198[0][4] = ((l_2722 |= ((safe_sub_func_int16_t_s_s (0x44EEL, (safe_rshift_func_int8_t_s_u ((safe_unary_minus_func_uint16_t_u ((g_238 &= (g_3235[4][1][0] <= p_14)))), 7)))) < (safe_sub_func_uint16_t_u_u ((~(l_3116 = (g_335[4] = ((l_3013 <= l_3145) <= (-3L))))), 7L)))), g_212[5][0][2])) != l_3193[6][2]) > g_1462), l_3155[1])) && l_3147), g_283[3])) != 0x4189L), l_2990))) >= l_3148) ^ l_2001) != p_15), p_15)), g_2737)), g_2295[2]))), p_15))) | l_2542) ^ l_3155[1]), l_3238) != p_15) && p_15)) | 0x39L)), p_15)) && 247UL) & g_212[5][0][2]) >= 3UL) & l_3083) > l_3155[2]))), (-1L)) == p_14), 6)), 0xA2072C5EL), g_283[3])) & l_3155[1]), 0x52A2L)) ^ g_1519), p_15)) < g_2870) | l_2118[4][1]) > p_15)))) & l_2724);
          } else {
            return l_3138;
          }
        } else {
          uint16_t l_3264 = 0UL;
          for (l_3145 = 2; (l_3145 <= 6); l_3145 += 1) {
            int i;
            l_3155[1] = (safe_div_func_uint8_t_u_u(
                ((safe_lshift_func_int16_t_s_s(0x5CF3L, 3)) >= g_283[l_3145]),
                (safe_sub_func_uint16_t_u_u(
                    (((0L &&
                       ((((safe_mod_func_int32_t_s_s(
                              p_14,
                              ((((65530UL || 0x5FA9L),
                                 (safe_rshift_func_int8_t_s_s(
                                     ((p_14 !=
                                       ((g_283[3] <=
                                         (((safe_sub_func_int32_t_s_s(
                                               ((safe_add_func_uint32_t_u_u(
                                                    (safe_rshift_func_int8_t_s_u(
                                                        (((safe_sub_func_uint8_t_u_u(
                                                              p_15,
                                                              l_2118[5][0])),
                                                          (-4L)) > g_104),
                                                        7)),
                                                    0x6ABB34E1L)) |
                                                l_3155[1]),
                                               p_14)) > g_212[5][0][2]) !=
                                          g_1260)) |
                                        0xA2L)) <= p_15),
                                     g_212[5][0][2]))) ^
                                1L),
                               g_378[0]))),
                          4294967295UL) ^
                         l_3257) < g_140)) >= (-1L)) |
                     0x061EL),
                    0xE565L))));
          }
          for (g_1076 = 0; (g_1076 == (-20)); --g_1076) {
            g_283[2] = (safe_sub_func_int32_t_s_s(
                ((safe_mod_func_int8_t_s_s(l_3083, (l_2510 && p_14))) ^
                 (1L && 0x31496822L)),
                p_15));
            return l_3264;
          }
        }
        for (p_14 = 3; (p_14 >= 0); p_14 -= 1) {
          for (l_2001 = 0; (l_2001 <= 3); l_2001 += 1) {
            int i;
            l_3145 = (safe_add_func_int8_t_s_s((g_1254 = g_2643[p_14]),
                                               g_3235[4][2][3]));
          }
        }
        if (p_14) {
          uint8_t l_3279 = 0x68L;
          int32_t l_3283 = 1L;
          for (g_1441 = 0; (g_1441 <= 1); g_1441 += 1) {
            int32_t l_3303 = 6L;
            int i, j;
            l_3283 =
                ((g_283[g_1441] & 4294967295UL) ||
                 (g_3025 = (safe_div_func_uint32_t_u_u(
                      ((safe_sub_func_uint32_t_u_u(
                           (((safe_lshift_func_int16_t_s_s(
                                 (safe_div_func_uint32_t_u_u(
                                     (safe_lshift_func_uint8_t_u_s(
                                         (g_1815 = 0xBBL),
                                         ((g_26[1][0] ==
                                           (0x9AL >= (g_293[0] &=
                                                      (~((l_2723[(g_1441 + 5)]
                                                                [g_1441]--),
                                                         g_283[3]))))) ||
                                          l_3279))),
                                     (safe_lshift_func_uint16_t_u_s(
                                         ((((g_1076 =
                                                 ((g_2949 =
                                                       ((((((g_378[6] >=
                                                             l_3282) ||
                                                            g_2295[2]),
                                                           l_3101) &&
                                                          l_3279) ^
                                                         g_3235[1][2][0]) <=
                                                        g_283[g_1441])) !=
                                                  0x18DCL)) &
                                            0xF6D5L) >= 0xDCE9B7E8L),
                                          p_14),
                                         11)))),
                                 g_378[6])) <= l_3131) != 0UL),
                           4294967289UL)) < p_14),
                      1L))));
            l_3303 ^=
                (((safe_rshift_func_uint16_t_u_u(
                      (g_283[g_1441] ^
                       (safe_rshift_func_uint16_t_u_s((!g_255), 3))),
                      ((safe_mod_func_uint8_t_u_u(p_15, g_5)) == p_14))),
                  ((safe_rshift_func_uint8_t_u_s(
                       ((((l_3155[1] ==
                           (safe_sub_func_int16_t_s_s(
                               ((((safe_unary_minus_func_uint8_t_u(
                                      (safe_mod_func_uint8_t_u_u(
                                          ((g_3025 ^=
                                            (g_26[1][2] ||
                                             (p_15 &
                                              (l_2825[3][3] &=
                                               (safe_rshift_func_int8_t_s_u(
                                                   (safe_add_func_int16_t_s_s(
                                                       (safe_rshift_func_uint16_t_u_u(
                                                           0xF164L, 10)),
                                                       65526UL)),
                                                   p_14)))))) == 0x73L),
                                          g_5)))) <= g_119),
                                 p_14) >= 0xD8L),
                               5L))) > 0x92L),
                         p_14) == l_3279),
                       g_2870)),
                   p_15)) < p_14);
            g_283[g_1441] |= (g_2295[0], 0L);
          }
          return g_1519;
        } else {
          uint32_t l_3306 = 4294967293UL;
          int32_t l_3316 = 0x0ABC9676L;
          int32_t l_3327 = 0xF160161AL;
          int32_t l_3328[7][1] = {{0xC5AEE3F4L}, {0xC5AEE3F4L}, {0xBF24F83EL},
                                  {0xC5AEE3F4L}, {0xC5AEE3F4L}, {0xBF24F83EL},
                                  {0xC5AEE3F4L}};
          int i, j;
          for (g_1260 = 0; (g_1260 == 51); ++g_1260) {
            uint16_t l_3317 = 0x0922L;
            int32_t l_3324 = 0x721435A0L;
            l_31[3][1] ^=
                ((((g_1254 = ((+(l_3306 && p_15)) <= g_2643[0])), 0L) >
                  (0x8789EFFCL !=
                   (safe_div_func_int32_t_s_s(
                       ((((((safe_add_func_int16_t_s_s(
                                ((~(safe_unary_minus_func_uint8_t_u(
                                     (safe_mod_func_uint8_t_u_u(
                                         (+p_15),
                                         (+((p_15 >= g_734) <=
                                            (safe_mod_func_int8_t_s_s(
                                                l_3316, l_3155[1]))))))))) ||
                                 g_26[1][1]),
                                g_2982)) &
                            g_734) ||
                           g_182[0]) >= g_2643[0]),
                         l_3317),
                        p_15),
                       g_378[6])))) != 3L);
            g_283[2] |=
                (((safe_add_func_uint16_t_u_u(
                      ((((safe_rshift_func_int16_t_s_u(
                             ((safe_lshift_func_uint8_t_u_s((g_1076 || g_5),
                                                            7)) ||
                              ((g_2643[0] <
                                ((p_14, ((p_15 | ((l_3324 ^= (l_3114 > p_14)) ^
                                                  g_3025)) <
                                         (0x17A7L && l_2723[3][1]))),
                                 4294967287UL)) >= p_14)),
                             4)) == 0x07C1L) ||
                        p_15) >= l_3083),
                      l_3316)) |
                  p_14) <= g_238);
            l_3328[6][0] ^= ((l_3327 = ((246UL < 0x6BL) >
                                        (safe_add_func_int32_t_s_s(
                                            (1UL | l_2723[3][1]), 0L)))) ||
                             g_26[1][1]);
            if (l_3317)
              continue;
          }
        }
      }
      if ((safe_lshift_func_uint16_t_u_u ((l_3331[0], (safe_mod_func_int16_t_s_s ((((((!(safe_mod_func_uint8_t_u_u (((((safe_lshift_func_int16_t_s_s ((((l_2722 = (g_466[3] <= (l_3107 &= p_15))) != (safe_mod_func_uint32_t_u_u (8UL, ((~((((~((g_140 = l_3199[8]) && (0xC84BL < (((l_3108 ^= (safe_lshift_func_uint8_t_u_u ((safe_rshift_func_int8_t_s_u (0L, (l_3352 = (safe_mod_func_uint16_t_u_u ((l_3346++), ((((g_153[0] ^ (((((((safe_add_func_int16_t_s_s (l_3257, p_14)), l_3351[4][2][2]) && 0x671EL) | 65531UL) ^ 0x618FL) & g_378[6]) != g_1185)) > l_3121[1]) && l_3146), 0x0AFBL)))))), 6))) < p_15) >= l_2721[1][1])))) != p_14) || 250UL) ^ 0x3BL)), l_2587[4][0][3])))), p_15), 10)) <= p_14) && l_3352) & 0x69L), 1L))) && l_3353), l_3354) > 4294967295UL) != 0x5F6DL), g_1185))), p_15)))
      {
        return l_3187;
      } else {
        uint32_t l_3357[7] = {0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL};
        uint32_t l_3386 = 0x2F6B114EL;
        int32_t l_3424 = (-8L);
        int32_t l_3486 = 0x1A615D8DL;
        int32_t l_3546 = 0x55A19FAAL;
        int32_t l_3547 = (-9L);
        int32_t l_3548 = 0x86A5192AL;
        int32_t l_3549 = 0x32FC5914L;
        int32_t l_3550[4][4] = {
            {(-2L), 0x48B7A7EFL, 0x48B7A7EFL, (-2L)},
            {0x2483151DL, 0x48B7A7EFL, 0xC94B7AECL, 0x48B7A7EFL},
            {0x48B7A7EFL, 1L, 0xC94B7AECL, 0xC94B7AECL},
            {0x2483151DL, 0x2483151DL, 0x48B7A7EFL, 0xC94B7AECL}};
        uint8_t l_3555 = 0xD1L;
        int i, j;
        for (l_25 = 0; (l_25 <= 3); l_25 += 1) {
          l_1936 =
              ((((safe_sub_func_int8_t_s_s(
                     (l_1935 = l_3357[3]),
                     ((safe_mod_func_int32_t_s_s(
                          (g_153[0] =
                               (((((((~(safe_mod_func_int16_t_s_s(g_2295[4],
                                                                  (+(-1L))))),
                                     g_3025),
                                    ((l_2933[1][1] >= 65534UL) ==
                                     (safe_add_func_uint16_t_u_u(
                                         ((safe_add_func_uint32_t_u_u(
                                              (safe_sub_func_uint32_t_u_u(
                                                  0xFA0C83C4L,
                                                  (safe_lshift_func_uint16_t_u_s(
                                                      (safe_add_func_uint16_t_u_u(
                                                          (safe_lshift_func_uint16_t_u_s(
                                                              p_14, l_3121[2])),
                                                          65535UL)),
                                                      9)))),
                                              g_1655)) > g_1519),
                                         g_1441)))) &&
                                   7UL) <= l_3357[3]) >= g_3235[7][1][1]) ==
                                65534UL)),
                          g_438)),
                      0x3FL))),
                 0x2788A971L) > g_3235[2][1][3]) < 0x28B1L);
          for (g_1441 = 0; (g_1441 <= 4); g_1441 += 1) {
            if (g_335[5])
              break;
          }
        }
        for (l_1936 = 1; (l_1936 >= 0); l_1936 -= 1) {
          int i;
          g_283[1] =
              (((g_153[(l_1936 + 4)] ||
                 (safe_sub_func_uint8_t_u_u(
                     g_2643[2],
                     (safe_lshift_func_int16_t_s_s(
                         ((g_2643[0] >
                           (~(safe_add_func_int8_t_s_s(
                               (l_3357[4] !=
                                (((safe_sub_func_int32_t_s_s(
                                      (-8L),
                                      ((g_153[(l_1936 + 1)] =
                                            (((safe_sub_func_uint16_t_u_u(
                                                  (safe_sub_func_uint32_t_u_u(
                                                      (((l_3121[2] & p_14) &
                                                        6L) == l_3357[3]),
                                                      g_3235[4][1][0])),
                                                  (-10L))) == (-1L)) == p_14)),
                                       l_3083))) |
                                  p_15) == p_15)),
                               l_3386)))) |
                          p_14),
                         0))))) ||
                0x123D79D5L) ||
               7UL);
          l_2722 =
              (((safe_sub_func_uint8_t_u_u((g_335[4] <= (g_466[3] = 0x72L)),
                                           0L)),
                (safe_rshift_func_uint16_t_u_u(
                    (g_86,
                     ((safe_div_func_int16_t_s_s(
                          (((safe_rshift_func_uint16_t_u_u(
                                (((((((safe_sub_func_uint32_t_u_u(
                                          g_26[0][3], 4294967295UL)) >
                                      (safe_add_func_int32_t_s_s(
                                          ((((-1L) ||
                                             (l_3407 = (safe_sub_func_uint32_t_u_u(
                                                  (((g_2870 &=
                                                     (safe_add_func_int32_t_s_s(
                                                         ((safe_mod_func_int16_t_s_s(
                                                              (safe_rshift_func_int8_t_s_s(
                                                                  g_258,
                                                                  (l_3170 &&
                                                                   l_3199[8]))),
                                                              p_14)) &&
                                                          g_1655),
                                                         g_212[5][0][2]))) !=
                                                    p_14) != l_1935),
                                                  g_153[(l_1936 + 4)])))) <=
                                            g_153[(l_1936 + 1)]) != g_734),
                                          p_15))) |
                                     p_15) |
                                    65535UL),
                                   g_212[5][0][2]) > g_74) ||
                                 g_2949),
                                p_15)) <= 0x461F9DEBL) <= l_3108),
                          p_15)),
                      g_153[(l_1936 + 1)])),
                    15))) > g_258);
          for (g_258 = 0; (g_258 <= 7); g_258 += 1) {
            int32_t l_3408 = (-1L);
            int i, j;
            l_3408 ^= l_2723[(l_1936 + 2)][l_1936];
            l_3424 = (safe_add_func_uint32_t_u_u(
                ((safe_mod_func_int16_t_s_s(
                     (safe_lshift_func_uint8_t_u_u(
                         ((l_2723[(l_1936 + 3)][l_1936] |
                           (((((l_2723[3][0] && p_14),
                               (safe_unary_minus_func_uint16_t_u((
                                   p_15 ==
                                   (((((((safe_add_func_uint8_t_u_u(
                                             (safe_mod_func_int8_t_s_s(
                                                 l_3099, (0x763A4F9DL && 1UL))),
                                             (safe_lshift_func_uint16_t_u_u(
                                                 ((safe_mod_func_int32_t_s_s(
                                                      l_3357[3],
                                                      (((g_395, g_1462) |
                                                        0xB0B5L) ||
                                                       0UL))) &&
                                                  l_2723[(l_1936 + 2)][l_1936]),
                                                 7)))) ^
                                         p_15) &
                                        65533UL) &
                                       0x25L) &&
                                      0xCDEF7225L) ^
                                     l_3386) >= p_14))))) &&
                              l_3386) >= 0xA1L) != p_14)) != p_15),
                         1)),
                     0x665FL)) |
                 1UL),
                p_14));
          }
        }
 if ((safe_mod_func_uint16_t_u_u ((safe_sub_func_uint16_t_u_u (0x51A8L, (safe_unary_minus_func_int16_t_s ((1UL != ((safe_lshift_func_uint8_t_u_s (((safe_rshift_func_int16_t_s_u ((safe_add_func_uint8_t_u_u ((safe_lshift_func_uint16_t_u_s (p_15, (safe_mod_func_int16_t_s_s ((l_3357[6] <= (safe_mul_func_int16_t_s_s (g_3442, ((((((249UL & (l_31[7][2] = (safe_sub_func_uint32_t_u_u ((--g_74), ((safe_add_func_uint16_t_u_u ((((safe_sub_func_int32_t_s_s ((safe_sub_func_uint32_t_u_u ((safe_lshift_func_uint8_t_u_s ((l_2722 >= ((safe_sub_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u ((safe_mod_func_int32_t_s_s (((g_255 > (l_3424 = ((((g_1047++) & 0xC4L) || g_255), (-1L)))) >= 65534UL), 0xA69DA250L)), l_3170)), 0x158EL)) || g_1462)), 5)), g_466[0])), g_212[0][0][4])) > p_14), l_3146), g_5)) || l_3170))))) <= l_3346) | l_3463), p_14), l_2871) < 0x7F720654L)))), l_3357[3])))), l_2552[0])), 5)) != 1L), g_378[6])) | g_283[6])))))), l_2587[0][0][7])))
 {
   int8_t l_3474 = 0x3CL;
   int32_t l_3482 = 2L;
   int32_t l_3487[8][10][3] = {{{0x8DFA95FCL, (-1L), 0L},
                                {0x6CD3C3C0L, (-10L), 0x6CD3C3C0L},
                                {0L, 0L, 0x0403A053L},
                                {0x856F24C8L, 0x3AC75974L, (-1L)},
                                {0L, 0x4BF49D69L, 5L},
                                {0x77EFE64FL, (-4L), 0x9ED0B66EL},
                                {0L, 0L, 0x4B4A6F76L},
                                {0x856F24C8L, 0x856F24C8L, (-10L)},
                                {0L, 0xF9439EC1L, 1L},
                                {0x6CD3C3C0L, 0xAC4D575FL, 0x856F24C8L}},
                               {{0x8DFA95FCL, 0L, (-5L)},
                                {8L, 0x6CD3C3C0L, 0x856F24C8L},
                                {(-1L), 0x704FFF94L, 1L},
                                {(-5L), 0x77EFE64FL, (-10L)},
                                {0x35CC2434L, 1L, 0x4B4A6F76L},
                                {1L, 0x3AC75974L, (-6L)},
                                {0x6266C13DL, 0L, (-5L)},
                                {0xAC4D575FL, 0x3AC75974L, 0x6CD3C3C0L},
                                {1L, 0L, 1L},
                                {0x3AC75974L, 1L, (-6L)}},
                               {{0x4B4A6F76L, 0x7EEA5A3FL, 0x0403A053L},
                                {0x6CD3C3C0L, (-6L), 0x29C4BD88L},
                                {(-1L), 0xA1AECC36L, 0L},
                                {0x6CD3C3C0L, 0x856F24C8L, 0x77EFE64FL},
                                {0x4B4A6F76L, 7L, 0xD3CC1AAFL},
                                {0x3AC75974L, 8L, 1L},
                                {1L, 0xF9439EC1L, 0x4B4A6F76L},
                                {0xAC4D575FL, 1L, (-1L)},
                                {0x6266C13DL, (-1L), 0x4B4A6F76L},
                                {(-5L), 1L, 1L}},
                               {{0xF291AFECL, 0xB57C6A9FL, 0xD3CC1AAFL},
                                {0x9ED0B66EL, (-4L), 0x77EFE64FL},
                                {0x35CC2434L, 0x704FFF94L, 0L},
                                {0x77EFE64FL, 0xAC4D575FL, 0x29C4BD88L},
                                {0xE6ADAA7DL, 0x704FFF94L, 0x0403A053L},
                                {(-6L), (-4L), (-6L)},
                                {1L, 0xB57C6A9FL, 1L},
                                {8L, 1L, 0x6CD3C3C0L},
                                {0x0403A053L, (-1L), (-5L)},
                                {1L, 1L, (-6L)}},
                               {{0x0403A053L, 0xF9439EC1L, 0x6266C13DL},
                                {8L, 8L, (-4L)},
                                {1L, 7L, 5L},
                                {(-6L), 0x856F24C8L, 8L},
                                {0xE6ADAA7DL, 0xA1AECC36L, 0L},
                                {0x77EFE64FL, (-6L), 8L},
                                {0x35CC2434L, 0x7EEA5A3FL, 5L},
                                {0x9ED0B66EL, 1L, (-4L)},
                                {0xF291AFECL, 0L, 0x6266C13DL},
                                {(-5L), 0x3AC75974L, (-6L)}},
                               {{0x6266C13DL, 0L, (-5L)},
                                {0xAC4D575FL, 0x3AC75974L, 0x6CD3C3C0L},
                                {1L, 0L, 1L},
                                {0x3AC75974L, 1L, (-6L)},
                                {0x4B4A6F76L, 0x7EEA5A3FL, 0x0403A053L},
                                {0x6CD3C3C0L, (-6L), 0x29C4BD88L},
                                {(-1L), 0xA1AECC36L, 0L},
                                {0x6CD3C3C0L, 0x856F24C8L, 0x77EFE64FL},
                                {0x4B4A6F76L, 7L, 0xD3CC1AAFL},
                                {0x3AC75974L, 8L, 1L}},
                               {{1L, 0xF9439EC1L, 0x4B4A6F76L},
                                {0xAC4D575FL, 1L, (-1L)},
                                {0x6266C13DL, (-1L), 0x4B4A6F76L},
                                {(-5L), 1L, 1L},
                                {0xF291AFECL, 0xB57C6A9FL, 0xD3CC1AAFL},
                                {0x9ED0B66EL, (-4L), 0x77EFE64FL},
                                {0x35CC2434L, 0x704FFF94L, 0L},
                                {0x77EFE64FL, 0xAC4D575FL, 0x29C4BD88L},
                                {0xE6ADAA7DL, 0x704FFF94L, 0x0403A053L},
                                {(-6L), (-4L), (-6L)}},
                               {{1L, 0xB57C6A9FL, 1L},
                                {8L, 1L, 0x6CD3C3C0L},
                                {0x0403A053L, (-1L), (-5L)},
                                {1L, 1L, (-6L)},
                                {0x0403A053L, 0xF9439EC1L, 0x6266C13DL},
                                {8L, 8L, (-4L)},
                                {1L, 7L, 5L},
                                {(-6L), 0x856F24C8L, 8L},
                                {0xE6ADAA7DL, 0xA1AECC36L, 0x0403A053L},
                                {1L, (-10L), 0x77EFE64FL}}};
   int i, j, k;
   for (g_2949 = (-12); (g_2949 == 10); g_2949++) {
     return g_255;
   }
   g_153[0] = p_15;
   if (l_3083)
     goto lbl_3483;
 lbl_3483:
   l_2679[0][2] &= (safe_sub_func_uint32_t_u_u(
       ((((safe_add_func_int16_t_s_s(
              ((0xA6301F84L || p_15) >
               (safe_mod_func_uint16_t_u_u(
                   ((++g_74) |
                    ((l_3474 = l_3199[8]) < (g_1519 > l_2721[0][2]))),
                   (safe_unary_minus_func_uint16_t_u(p_14))))),
              (0x4C2FL >=
               (p_14 || (l_31[7][2] = (((safe_lshift_func_uint16_t_u_u(
                                            (safe_mod_func_int32_t_s_s(
                                                (safe_rshift_func_int8_t_s_s(
                                                    (l_2722 = l_2772), 7)),
                                                l_31[7][2])),
                                            l_3482)),
                                        l_3121[2]) &&
                                       0x5C3AL)))))),
          g_1047),
         0x34D76207L),
        g_2295[0]),
       0xDAC12D24L));
   g_283[4] =
       ((safe_lshift_func_uint16_t_u_s(
            ((g_2643[0]--) !=
             ((g_592 =
                   (((0L <=
                      (safe_add_func_int16_t_s_s(
                          (safe_mod_func_uint8_t_u_u(
                              (p_15 =
                                   ((safe_mod_func_uint16_t_u_u(
                                        g_466[0],
                                        ((safe_mod_func_uint32_t_u_u(
                                             (!0UL),
                                             (safe_add_func_int16_t_s_s(
                                                 (((safe_div_func_uint32_t_u_u(
                                                       (g_238 ==
                                                        ((l_2721[0][0],
                                                          (safe_sub_func_uint32_t_u_u(
                                                              ((0L || l_3504) <
                                                               (g_592,
                                                                ((((safe_unary_minus_func_uint8_t_u((safe_sub_func_int16_t_s_s(
                                                                       (safe_div_func_uint8_t_u_u(
                                                                           (g_3235
                                                                                [4]
                                                                                [1]
                                                                                [0] ==
                                                                            0xD64F1DF2L),
                                                                           0xDBL)),
                                                                       l_3510
                                                                           [0]
                                                                           [5])))) >=
                                                                   p_15),
                                                                  4294967292UL),
                                                                 g_734))),
                                                              1UL))) <=
                                                         4294967295UL)),
                                                       p_14)) &
                                                   p_14) == 0x860DCBF2L),
                                                 (-2L))))) ^
                                         0xD805L))) == 0xC734L)),
                              246UL)),
                          l_3482))) <= g_212[3][0][5]) |
                    g_592)) >= p_14)),
            5)),
        p_15);
 } else {
   uint16_t l_3526 = 0x604CL;
   int32_t l_3534 = 1L;
   int32_t l_3536 = (-2L);
   int32_t l_3538 = 0xAE923797L;
   uint8_t l_3541 = 0x8FL;
   for (p_14 = 0; p_14 < 2; p_14 += 1) {
     for (g_2737 = 0; g_2737 < 5; g_2737 += 1) {
       g_26[p_14][g_2737] = 0x83L;
     }
   }
   if (p_15) {
     g_153[0] = (safe_div_func_uint16_t_u_u(p_15, (-5L)));
   } else {
     uint32_t l_3523 = 4294967295UL;
     int32_t l_3535 = 0x1D0B9F63L;
     int32_t l_3537 = (-7L);
     int32_t l_3540 = (-5L);
     int32_t l_3544 = 5L;
     int32_t l_3545 = 0x13BC8887L;
     int32_t l_3552 = 0x0E1917BBL;
     int32_t l_3553 = 0L;
     int32_t l_3554 = (-8L);
     l_3486 =
         (l_3108 |=
          ((safe_mod_func_uint32_t_u_u(
               ((safe_sub_func_int32_t_s_s(
                    (((safe_sub_func_int8_t_s_s(
                          (0xC04FL ||
                           (safe_div_func_uint16_t_u_u(
                               ((l_3523 =
                                     (safe_div_func_uint8_t_u_u(g_74, g_1047))),
                                (((l_1935 = l_3099) ^
                                  ((((!p_15) <=
                                     (l_3526 &&
                                      ((safe_lshift_func_uint16_t_u_u(p_15,
                                                                      14)) !=
                                       (safe_rshift_func_uint8_t_u_u(
                                           ((safe_sub_func_uint16_t_u_u(
                                                l_3523, l_3533)) ||
                                            g_466[0]),
                                           l_3386))))) > 0x7F4E1A5AL) >=
                                   0x4CACL)) <= p_14)),
                               l_2825[1][2]))),
                          l_3463)) != g_212[2][0][1]) >= 0x36634F77L),
                    g_26[0][1])) <= 0xE0854C26L),
               p_14)) ||
           1L));
     ++l_3541;
     l_3555--;
   }
 }
 l_2825[3][3] ^= (safe_div_func_uint16_t_u_u(
     ((p_15 <= (l_3116 = p_14)) ||
      ((safe_mod_func_uint16_t_u_u(
           ((l_3088 |= l_3564) ||
            ((0xB637L | (4294967288UL != g_395)) ^
             ((safe_add_func_uint32_t_u_u((++g_2870), g_5)) >=
              (g_466[0] ^=
               (+(((((safe_add_func_int8_t_s_s(
                         p_15, ((((safe_mod_func_int16_t_s_s(
                                      (safe_div_func_uint32_t_u_u(
                                          (((g_1254 = (1UL == p_15)), l_2504) >
                                           0x50B1114DL),
                                          g_153[3])),
                                      g_1047)) != p_14) <= g_293[0]) ^
                                p_14))),
                     l_1936) != l_3547),
                   g_2295[0]) != g_140)))))),
           (-1L))) != l_3548)),
     p_15));
      }
      if ((((safe_add_func_int8_t_s_s ((safe_add_func_uint8_t_u_u ((safe_add_func_int32_t_s_s ((safe_sub_func_uint8_t_u_u (((((safe_lshift_func_uint8_t_u_u ((safe_div_func_int8_t_s_s ((((((((safe_lshift_func_uint16_t_u_s (((((safe_rshift_func_uint16_t_u_s ((g_3442 &= ((safe_unary_minus_func_int16_t_s (p_14)) == 0x2249E0CBL)), 2)) | 0UL) ^ (p_15, (((+((~p_14) | (((safe_div_func_int8_t_s_s ((g_466[1] = (p_15 && (safe_div_func_uint32_t_u_u (((+((((safe_rshift_func_int8_t_s_s (p_14, (((safe_sub_func_int16_t_s_s (0x0015L, p_14)) < p_14) | 0x2EL))) > 0x376EEE8CL) ^ l_3551[1]) != g_1462)) < p_15), l_2679[0][4])))), l_3600)) <= 0x4C9DFD28L) || l_3463))) ^ (-2L)), g_86))) >= l_3145), 6)), 0x3BD7L) ^ p_15) | 0xD8L) >= l_3238) | 0L) != g_378[6]), l_2660)), p_14)) <= l_3601[0]), g_378[6]) < g_255), p_15)), p_15)), l_3510[0][5])), l_3083)) > p_14) > l_3108))
      {
        uint16_t l_3608 = 65527UL;
        int32_t l_3635 = 0x1F9B467DL;
        int32_t l_3636 = (-1L);
 l_2679
   [0]
   [3]
   ^=
   ((((l_3533 = ((g_438--) || (((safe_add_func_uint32_t_u_u (((0x4FE7D2C9L & ((((safe_lshift_func_int16_t_s_s (((g_2643[0] = (++l_3608)), (safe_add_func_int8_t_s_s ((((safe_lshift_func_int16_t_s_u (((((safe_lshift_func_uint16_t_u_s ((safe_div_func_uint32_t_u_u ((((~((safe_rshift_func_int16_t_s_s ((l_3622[0][7] ^= l_3621), 15)), (safe_lshift_func_uint8_t_u_s ((safe_rshift_func_uint16_t_u_s ((safe_add_func_int16_t_s_s (l_3088, (safe_rshift_func_int16_t_s_u ((l_3145 |= (g_255 ^= (l_3131 | (0x636930A4L || (l_3636 = (0x2D36L && (safe_rshift_func_uint8_t_u_s (((safe_add_func_uint8_t_u_u (((l_3635 = (0x6753EB8FL >= p_14)) ^ (g_86 = (~g_1815))), 0x4DL)) > g_182[0]), 1)))))))), 8)))), 10)), p_15)))) < l_3637) ^ g_238), g_104)), g_592)), 0x22L) && g_2295[1]), 6L), g_140)) < l_3608) <= 0xD8L), 3UL))), p_14)), l_3551[0]), p_15) != 0x482CL)) && l_3013), 0xC83BB634L)) != l_3107), (-1L)))) != 0xB11AL) > 1UL) | p_15);
      } else {
        uint32_t l_3656[5];
        int32_t l_3657[10][3][4] = {
            {{6L, 1L, 0x1099A938L, 1L},
             {6L, 0x729ECC57L, 0x8570345AL, 1L},
             {0x8570345AL, 1L, 0x8570345AL, 0x729ECC57L}},
            {{6L, 1L, 0x1099A938L, 1L},
             {6L, 0x729ECC57L, 0x8570345AL, 1L},
             {0x8570345AL, 1L, 0x8570345AL, 0x729ECC57L}},
            {{6L, 1L, 0x1099A938L, 1L},
             {6L, 0x729ECC57L, 0x8570345AL, 1L},
             {0x8570345AL, 1L, 0x8570345AL, 0x729ECC57L}},
            {{6L, 1L, 0x1099A938L, 1L},
             {6L, 0x729ECC57L, 0x8570345AL, 1L},
             {0x8570345AL, 1L, 0x8570345AL, 0x729ECC57L}},
            {{6L, 1L, 0x1099A938L, 1L},
             {6L, 0x729ECC57L, 0x8570345AL, 1L},
             {0x8570345AL, 1L, 0x8570345AL, 0x729ECC57L}},
            {{6L, 1L, 0x1099A938L, 1L},
             {6L, 0x729ECC57L, 0x8570345AL, 1L},
             {0x8570345AL, 1L, 0x8570345AL, 0x729ECC57L}},
            {{6L, 1L, 0x1099A938L, 1L},
             {6L, 0x729ECC57L, 0x8570345AL, 1L},
             {0x8570345AL, 1L, 0x8570345AL, 0x729ECC57L}},
            {{6L, 1L, 0x1099A938L, 1L},
             {6L, 0x729ECC57L, 0x8570345AL, 1L},
             {0x8570345AL, 1L, 0x8570345AL, 0x729ECC57L}},
            {{6L, 1L, 0x1099A938L, 1L},
             {6L, 0x729ECC57L, 0x8570345AL, 1L},
             {0x8570345AL, 1L, 0x8570345AL, 0x729ECC57L}},
            {{6L, 1L, 0x1099A938L, 1L},
             {6L, 0x729ECC57L, 0x8570345AL, 1L},
             {0x8570345AL, 1L, 0x8570345AL, 0x729ECC57L}}};
        int i, j, k;
        for (i = 0; i < 5; i++)
          l_3656[i] = 2UL;
        for (l_2542 = 0; (l_2542 <= 1); l_2542 += 1) {
          int16_t l_3638 = 0x9EC5L;
          int32_t l_3639 = 2L;
          uint8_t l_3641[1][9] = {
              {0xB8L, 0xEEL, 0xB8L, 0xEEL, 0xB8L, 0xEEL, 0xB8L, 0xEEL, 0xB8L}};
          int i, j;
          ++l_3641[0][3];
          if (l_2552[l_2542]) {
            return l_2853;
          } else {
            return l_2722;
          }
        }
        l_3657[5][0][0] =
            ((safe_sub_func_int8_t_s_s(
                 ((l_3116 ^= (safe_mod_func_uint16_t_u_u(
                       l_2990, (+(l_2679[0][4] = 0x9AE3L))))),
                  g_283[2]),
                 (l_25 <= p_15))) &&
             ((((safe_mod_func_int16_t_s_s(
                    ((safe_div_func_int32_t_s_s(
                         (g_3652 !=
                          (safe_unary_minus_func_uint8_t_u(
                              ((((((0xDACAA398L ||
                                    (0x5B4C30B2L > ((safe_sub_func_int16_t_s_s(
                                                        g_182[5], p_15)) ||
                                                    0xF015E4CCL))) &&
                                   l_3407) < l_31[5][3]) <= 0x60L) &
                                g_734) == l_2853)))),
                         p_14)) != l_3656[3]),
                    p_14)),
                g_1655),
               g_181) < g_86));
      }
    }
    l_3658++;
  } else {
    int32_t l_3681 = 0x92FC4B01L;
    int32_t l_3682 = (-1L);
    for (l_3533 = 14; (l_3533 != 5);
         l_3533 = safe_sub_func_uint8_t_u_u(l_3533, 8)) {
      int16_t l_3673 = 0x237FL;
      int16_t l_3680 = 0L;
      l_3682 =
          ((safe_rshift_func_int16_t_s_u(g_466[1], 13)) <
           ((g_26[1][2] &=
             (((safe_mod_func_int16_t_s_s(
                   p_15,
                   ((safe_add_func_uint32_t_u_u(
                        (~(((l_1936 |=
                             (((safe_mod_func_uint8_t_u_u(
                                   (((safe_div_func_uint8_t_u_u(
                                         l_3673, (safe_rshift_func_int8_t_s_s(
                                                     l_2871, 7)))) >
                                     (((0x85A3L || 7L) && l_2346[7]),
                                      ((safe_mod_func_uint8_t_u_u(
                                           ((g_140 &= 0x9835L) &&
                                            (~((safe_add_func_int16_t_s_s(
                                                   ((g_1254 ^ g_293[0]) >=
                                                    p_15),
                                                   0x894CL)) &&
                                               l_3331[0]))),
                                           1L)) ||
                                       g_2949))) &
                                    0x522660D5L),
                                   p_15)) ||
                               p_15) == l_3680)) < g_293[3]) != 255UL)),
                        p_15)) |
                    0x7D52L))) <= 251UL) &
              0L)),
            l_3681));
      return l_3673;
    }
    l_2504 = p_14;
  }
  return g_2295[1];
}

static int8_t func_18(int8_t p_19, int8_t p_20, uint32_t p_21, uint8_t p_22) {
  int32_t l_30 = (-1L);
  for (p_21 = 0; (p_21 <= 1); p_21 += 1) {
    uint16_t l_27 = 0xB7B8L;
    l_27--;
    return l_30;
  }
  return p_22;
}

static int32_t func_38(int32_t p_39, uint16_t p_40, uint32_t p_41,
                       uint16_t p_42) {
  uint8_t l_1079 = 2UL;
  uint16_t l_1080 = 0UL;
  int32_t l_1090 = 0x86BD9BCEL;
  int32_t l_1101 = 0x3FB908E9L;
  int32_t l_1142 = 0x2ECF957AL;
  uint8_t l_1146 = 2UL;
  int32_t l_1150 = 0xF27E0833L;
  int32_t l_1152[10];
  uint32_t l_1544 = 0x97EAA1ADL;
  uint32_t l_1557 = 1UL;
  int32_t l_1697 = 0L;
  int32_t l_1731 = 0x92EE1D8FL;
  uint32_t l_1750[7][5][4] = {
      {{4294967295UL, 4294967291UL, 0UL, 0x221BA614L},
       {0x4568984AL, 0UL, 0UL, 0xFA80D259L},
       {0UL, 4294967295UL, 0x44D53F94L, 0x44D53F94L},
       {0UL, 0UL, 0UL, 0x96862F87L},
       {0x4568984AL, 0x44D53F94L, 0UL, 0UL}},
      {{4294967295UL, 0xF219B592L, 0xDFD198C9L, 0UL},
       {0x221BA614L, 0xF219B592L, 0x221BA614L, 0UL},
       {0xF219B592L, 0x44D53F94L, 0xE517667BL, 0x96862F87L},
       {0x96862F87L, 0UL, 4294967295UL, 0x44D53F94L},
       {0xFA80D259L, 4294967295UL, 4294967295UL, 0xFA80D259L}},
      {{0x96862F87L, 0UL, 0xE517667BL, 0x221BA614L},
       {0xF219B592L, 4294967291UL, 0x221BA614L, 0UL},
       {0x221BA614L, 0UL, 0xDFD198C9L, 0UL},
       {4294967295UL, 4294967291UL, 0UL, 0x221BA614L},
       {0x4568984AL, 0UL, 0xF219B592L, 0UL}},
      {{0UL, 0xFA80D259L, 4294967295UL, 4294967295UL},
       {0UL, 0UL, 0xF219B592L, 0UL},
       {0x221BA614L, 4294967295UL, 0UL, 4294967291UL},
       {0xFA80D259L, 0x96862F87L, 0x4568984AL, 0UL},
       {0x44D53F94L, 0x96862F87L, 0x44D53F94L, 4294967291UL}},
      {{0x96862F87L, 4294967295UL, 0xDFD198C9L, 0UL},
       {0UL, 0UL, 0xFA80D259L, 4294967295UL},
       {0UL, 0xFA80D259L, 0xFA80D259L, 0UL},
       {0UL, 4294967291UL, 0xDFD198C9L, 0x44D53F94L},
       {0x96862F87L, 0xE517667BL, 0x44D53F94L, 0xF219B592L}},
      {{0x44D53F94L, 0xF219B592L, 0x4568984AL, 0xF219B592L},
       {0xFA80D259L, 0xE517667BL, 0UL, 0x44D53F94L},
       {0x221BA614L, 4294967291UL, 0xF219B592L, 0UL},
       {0UL, 0xFA80D259L, 4294967295UL, 4294967295UL},
       {0UL, 0UL, 0xF219B592L, 0UL}},
      {{0x221BA614L, 4294967295UL, 0UL, 4294967291UL},
       {0xFA80D259L, 0x96862F87L, 0x4568984AL, 0UL},
       {0x44D53F94L, 0x96862F87L, 0x44D53F94L, 4294967291UL},
       {0x96862F87L, 4294967295UL, 0xDFD198C9L, 0UL},
       {0UL, 0UL, 0xFA80D259L, 4294967295UL}}};
  uint32_t l_1813 = 0x0279C9F8L;
  uint32_t l_1814[10] = {0UL, 0xB3A667F2L, 0UL,         0UL, 0xB3A667F2L,
                         0UL, 0UL,         0xB3A667F2L, 0UL, 0UL};
  int i, j, k;
  for (i = 0; i < 10; i++)
    l_1152[i] = 8L;
lbl_1116:
  p_39 = (safe_sub_func_uint16_t_u_u(
      (g_335[1] = 0xAA6CL),
      (g_238,
       (((l_1080 = l_1079) | g_395) ==
        ((safe_unary_minus_func_uint16_t_u(
             (p_42 &&
              ((l_1101 ^=
                ((safe_sub_func_int16_t_s_s(
                     ((safe_mod_func_int32_t_s_s(
                          (safe_add_func_int16_t_s_s(
                              ((l_1090 = ((safe_add_func_uint32_t_u_u(
                                              g_378[2], (++g_212[5][0][2]))),
                                          p_42)) > p_41),
                              ((--g_238), (safe_lshift_func_uint16_t_u_u(
                                              (safe_rshift_func_int16_t_s_s(
                                                  (safe_sub_func_uint16_t_u_u(
                                                      p_39, l_1079)),
                                                  7)),
                                              11))))),
                          4294967295UL)) >= g_140),
                     g_395)) < l_1079)) == g_153[4])))) < g_147)))));
lbl_1751:
  for (g_74 = 22; (g_74 >= 27); g_74 = safe_add_func_uint32_t_u_u(g_74, 4)) {
    int8_t l_1104 = 0x17L;
    int32_t l_1131 = 1L;
    int32_t l_1137[5][3][2];
    int32_t l_1149 = 0L;
    uint32_t l_1163 = 2UL;
    uint32_t l_1196 = 1UL;
    int16_t l_1299 = 0L;
    uint32_t l_1366[8] = {0xD9D7D1C4L, 0xD9D7D1C4L, 0xD9D7D1C4L, 0xD9D7D1C4L,
                          0xD9D7D1C4L, 0xD9D7D1C4L, 0xD9D7D1C4L, 0xD9D7D1C4L};
    int32_t l_1418 = 0x88B5C65CL;
    uint32_t l_1429 = 4294967295UL;
    uint32_t l_1506 = 0xFBE0F1D6L;
    int i, j, k;
    for (i = 0; i < 5; i++) {
      for (j = 0; j < 3; j++) {
        for (k = 0; k < 2; k++)
          l_1137[i][j][k] = 0x3D2E2303L;
      }
    }
    if (l_1104) {
      uint32_t l_1115 = 0x66EC97A6L;
      int32_t l_1133 = 0L;
      int16_t l_1134[5];
      int32_t l_1135[8];
      uint16_t l_1269 = 0xF491L;
      uint32_t l_1322 = 4294967290UL;
      int32_t l_1391 = 0x4C38E6D5L;
      int32_t l_1439 = 1L;
      int i;
      for (i = 0; i < 5; i++)
        l_1134[i] = 0xDD8AL;
      for (i = 0; i < 8; i++)
        l_1135[i] = 0xFF7CEAD8L;
      if ((safe_div_func_int32_t_s_s(
              ((9UL |
                ((l_1079,
                  (((g_104 = (((safe_mod_func_int16_t_s_s(
                                   (safe_rshift_func_int16_t_s_u(
                                       (safe_add_func_uint32_t_u_u(
                                           0x4C2CF8AEL, g_212[4][0][0])),
                                       ((safe_add_func_int32_t_s_s(
                                            (g_283[0] = g_466[4]), l_1104)),
                                        p_39))),
                                   p_42)) < p_40) |
                              g_258)) |
                    (-1L)) <= 0x64L)),
                 l_1115)) >= 0x6BL),
              7UL))) {
        int8_t l_1138 = 6L;
        int32_t l_1140 = (-3L);
        int32_t l_1143 = 7L;
        int32_t l_1151 = 0x07F9FC0DL;
        int32_t l_1153 = 0xB49C3DD9L;
        int32_t l_1154 = 1L;
        int32_t l_1156 = 2L;
        int32_t l_1159 = 0x2283F0C0L;
        int32_t l_1160 = 0xF53177EAL;
        int32_t l_1161[4][3][9] = {
            {{0x533F255FL, 2L, 0x80BDD17BL, 0x6E6DCDBAL, 0x6E6DCDBAL,
              0x80BDD17BL, 2L, 0x533F255FL, 1L},
             {0xAA0C4BE3L, 0x1BDBD70CL, 0x6A1B443BL, 0x77BDD5BEL, 0x4867F991L,
              (-1L), 0x87F193E2L, 0x46F409F9L, (-10L)},
             {1L, 0x1616789AL, 0L, 0x16D42CFBL, 8L, 0x16D42CFBL, 0L,
              0x1616789AL, 1L}},
            {{0L, 0xBB3395B6L, 0x4867F991L, 0x3698CBCEL, 0xAA0C4BE3L,
              0x87F193E2L, 0x1BDBD70CL, 0L, 0L},
             {0L, 0x80BDD17BL, 0x91EECED5L, (-1L), 1L, 1L, (-1L), 0x91EECED5L,
              0x80BDD17BL},
             {0L, 0xAA0C4BE3L, 0x1BDBD70CL, 0x6A1B443BL, 0x77BDD5BEL,
              0x4867F991L, (-1L), 0x87F193E2L, 0x46F409F9L}},
            {{1L, (-1L), 8L, 0x55549B3CL, 0x91EECED5L, 0x69E91AEFL, 0x91EECED5L,
              0x55549B3CL, 8L},
             {0xAA0C4BE3L, 0xAA0C4BE3L, 0L, 0x46F409F9L, 0x88A8F256L,
              0xBB3395B6L, 0x3698CBCEL, (-10L), 0L},
             {0x533F255FL, 0x80BDD17BL, 0x1616789AL, 0x8491A4EFL, 0xF10FD951L,
              1L, 1L, 0xF10FD951L, 0x8491A4EFL}},
            {{0L, 0xBB3395B6L, 0L, 0x4867F991L, 0x87F193E2L, 0L, 0x5726AE10L,
              0L, 0x88A8F256L},
             {0x16D42CFBL, 0L, 1L, 0x1616789AL, 0L, 0x16D42CFBL, 8L,
              0x16D42CFBL, 0L},
             {0L, 0xAA0C4BE3L, 0xAA0C4BE3L, 0L, 0x46F409F9L, 0x88A8F256L,
              0xBB3395B6L, 0x3698CBCEL, (-10L)}}};
        int i, j, k;
        if (p_41)
          goto lbl_1116;
        if ((safe_lshift_func_uint16_t_u_u(0x9558L, 10))) {
          int32_t l_1124 = 0x5A2EF1F4L;
          int32_t l_1141 = (-1L);
          int16_t l_1155[6];
          int32_t l_1157 = 0xC7F32A5FL;
          int32_t l_1158 = 0xDF3643EAL;
          int32_t l_1162[1];
          int i;
          for (i = 0; i < 6; i++)
            l_1155[i] = 0x2ABEL;
          for (i = 0; i < 1; i++)
            l_1162[i] = 0xB49BF7AEL;
          for (g_734 = 15; (g_734 <= (-8));
               g_734 = safe_sub_func_int16_t_s_s(g_734, 7)) {
            uint8_t l_1127 = 0xFFL;
            int32_t l_1130 = 0x3820E806L;
            int32_t l_1132 = 0x0B73074AL;
            int32_t l_1136 = 0L;
            int32_t l_1139 = 0L;
            int32_t l_1144 = (-1L);
            int32_t l_1145 = 9L;
            p_39 =
                (l_1080,
                 (p_39 |
                  (l_1090 >=
                   (safe_mod_func_int8_t_s_s(
                       g_140,
                       (((((l_1101 =
                                ((g_592 =
                                      ((safe_unary_minus_func_uint8_t_u(g_86)) |
                                       (l_1130 =
                                            (l_1124,
                                             ((safe_add_func_uint32_t_u_u(
                                                  (((l_1127 = 0xE2196E44L),
                                                    ((-9L) >=
                                                     (safe_mod_func_uint16_t_u_u(
                                                         65529UL, p_39)))) |
                                                   g_86),
                                                  g_212[2][0][5])) ||
                                              0UL))))) &&
                                 0xB8L)) >= l_1090) ^
                          l_1079) < g_293[0]) ||
                        0x2FL))))));
            ++l_1146;
            if (p_42)
              goto lbl_1116;
            if (p_40)
              break;
          }
          --l_1163;
        } else {
          int32_t l_1168 = (-1L);
          l_1133 |=
              ((g_119,
                ((safe_add_func_uint32_t_u_u(
                     g_26[1][3],
                     ((((l_1168 = l_1137[0][2][1]),
                        (g_182[3] =
                             ((safe_mod_func_int32_t_s_s(
                                  (((safe_lshift_func_int16_t_s_s(
                                        (g_74 !=
                                         ((g_153[0] = p_41) |
                                          (g_255 >
                                           ((safe_rshift_func_uint16_t_u_s(
                                                (((0xD2B5ACBEL ^
                                                   (0x066CL >= g_466[0])) >=
                                                  9L),
                                                 0xA1E4L),
                                                p_41)) < p_41)))),
                                        15)) > g_238),
                                   g_5),
                                  1L)) &&
                              0L))),
                       g_1076),
                      0x79E6DBA8L))) <= 8UL)) ||
               0x4A0EFA6EL);
        }
        if ((p_40 >=
             (((l_1080 ==
                (safe_mod_func_uint16_t_u_u(
                    (p_42 = (safe_add_func_uint16_t_u_u(
                         (safe_rshift_func_uint8_t_u_s(
                             (l_1161[2][0][4] || p_40), 2)),
                         ((l_1152[7] = g_1185),
                          (safe_add_func_uint32_t_u_u(
                              ((safe_sub_func_int16_t_s_s(
                                   ((((((safe_lshift_func_uint8_t_u_u(
                                            ((((0UL !=
                                                (l_1137[4][2][0] =
                                                     ((safe_mod_func_uint16_t_u_u(
                                                          (safe_sub_func_int16_t_s_s(
                                                              ((g_104 |
                                                                (g_734 &
                                                                 ((l_1161[1][0]
                                                                         [3] ^
                                                                   0x8C48788AL),
                                                                  1L))),
                                                               l_1149),
                                                              65526UL)),
                                                          g_378[6])) &
                                                      g_466[3]))),
                                               g_293[3]) < l_1196),
                                             g_182[0]),
                                            6)) >= l_1135[1]) < 65535UL) >=
                                      g_1185) ^
                                     p_41) == 0x03DAB49AL),
                                   p_42)) != 0x2A70L),
                              g_140)))))),
                    g_293[3]))) <= l_1160) <= p_39))) {
          uint32_t l_1214[6];
          int i;
          for (i = 0; i < 6; i++)
            l_1214[i] = 0x69F66A40L;
          g_153[0] |=
              ((safe_add_func_uint8_t_u_u(
                   (safe_unary_minus_func_int8_t_s((
                       l_1214[4] =
                           (0x66L >
                            (safe_lshift_func_uint8_t_u_s(
                                (safe_lshift_func_uint16_t_u_s(
                                    (((safe_mod_func_int32_t_s_s(
                                          ((g_293[0] &=
                                            (safe_lshift_func_uint8_t_u_u(
                                                (l_1090 =
                                                     (g_258 <
                                                      ((l_1131 &=
                                                        ((safe_div_func_int8_t_s_s(
                                                             l_1137[2][2][1],
                                                             (p_39 |
                                                              ((safe_lshift_func_uint8_t_u_s(
                                                                   g_1185, 4)) &
                                                               ((g_395 <=
                                                                 g_283[3]) |
                                                                (safe_add_func_uint8_t_u_u(
                                                                    p_41,
                                                                    0x9EL))))))) ==
                                                         p_39)),
                                                       g_119))),
                                                7))) &
                                           l_1104),
                                          (-6L))) > g_119),
                                     0UL),
                                    6)),
                                7)))))),
                   0UL)),
               p_40);
          for (l_1115 = 21; (l_1115 > 43); l_1115++) {
            int8_t l_1237 = 0x07L;
            uint8_t l_1255 = 1UL;
            l_1154 = (safe_sub_func_uint32_t_u_u(
                (safe_add_func_int8_t_s_s(p_41, 0x5FL)),
                (g_283[3] =
                     ((l_1214[4] <= p_42) ==
                      (((0xCC20L >= (l_1138 >= ((((+l_1150) == 255UL), 0x70L),
                                                l_1152[6]))) > p_41),
                       g_466[3])))));
            l_1149 =
                ((-4L) <
                 (safe_lshift_func_uint8_t_u_s(
                     (safe_lshift_func_uint8_t_u_u(
                         (safe_add_func_uint16_t_u_u(
                             (((safe_lshift_func_int16_t_s_s(
                                   (safe_div_func_uint32_t_u_u(
                                       (safe_add_func_uint16_t_u_u(
                                           ((((p_40 <=
                                               ((safe_sub_func_int16_t_s_s(
                                                    ((safe_div_func_uint8_t_u_u(
                                                         (l_1237 !=
                                                          (safe_lshift_func_int16_t_s_u(
                                                              ((l_1137[1][1][0] =
                                                                    (safe_div_func_uint32_t_u_u(
                                                                        p_42,
                                                                        l_1161
                                                                            [2]
                                                                            [0]
                                                                            [4]))) <=
                                                               ((safe_rshift_func_int8_t_s_s(
                                                                    9L, 3)) !=
                                                                ((g_1185,
                                                                  ((safe_mod_func_uint16_t_u_u(
                                                                       ((safe_div_func_uint16_t_u_u(
                                                                            (safe_sub_func_int16_t_s_s(
                                                                                4L,
                                                                                (g_1076 =
                                                                                     ((safe_lshift_func_uint16_t_u_s(
                                                                                          g_212
                                                                                              [4]
                                                                                              [0]
                                                                                              [5],
                                                                                          p_42)) <=
                                                                                      255UL)))),
                                                                            p_41)),
                                                                        0xD3DEL),
                                                                       g_86)) <
                                                                   l_1154)) &&
                                                                 l_1163))),
                                                              10))),
                                                         g_104)) &&
                                                     g_74),
                                                    0xB163L)) != g_283[5])) >
                                              g_1254) ||
                                             0x76C93DFFL),
                                            l_1237),
                                           l_1214[0])),
                                       l_1214[4])),
                                   l_1237)) < p_41) &
                              l_1255),
                             l_1163)),
                         g_104)),
                     g_26[0][4])));
            if (g_438)
              continue;
          }
        } else {
          uint8_t l_1270 = 252UL;
          int32_t l_1278 = 0x5B8C0B29L;
          l_1150 &= (safe_add_func_int32_t_s_s(
              ((safe_div_func_int8_t_s_s(6L, g_1260)),
               (((l_1278 = (safe_unary_minus_func_int8_t_s(
                      (safe_sub_func_int16_t_s_s(
                          (safe_unary_minus_func_int16_t_s(
                              ((((safe_lshift_func_int16_t_s_s(
                                     (3L | (safe_mod_func_uint8_t_u_u(
                                               g_592, (l_1269 | g_104)))),
                                     ((((l_1270 &= 0x961783F6L) |
                                        (safe_unary_minus_func_int8_t_s((
                                            ((safe_div_func_uint16_t_u_u(
                                                 (safe_sub_func_int16_t_s_s(
                                                     (safe_div_func_int32_t_s_s(
                                                         g_283[3], g_293[3])),
                                                     g_212[5][0][2])),
                                                 l_1278)) >= l_1159) &
                                            g_182[0])))) < p_39) &
                                      l_1278))) != p_39) < 0xD5C31981L) &&
                               (-9L)))),
                          (-10L)))))) &
                 g_212[5][0][1]),
                g_293[0])),
              l_1163));
          return g_238;
        }
      } else {
        int32_t l_1324 = 0x7266AEADL;
        uint8_t l_1343 = 0xF2L;
        l_1152[4] =
            (7UL &
             ((safe_sub_func_int8_t_s_s(
                  (g_181 <
                   ((safe_lshift_func_uint16_t_u_u(l_1080, 8)) >= p_42)),
                  l_1150)) !=
              (safe_div_func_uint16_t_u_u(
                  (safe_add_func_int16_t_s_s(
                      ((((safe_div_func_uint16_t_u_u(
                             (safe_mod_func_int16_t_s_s(1L, g_466[0])),
                             (p_40 &
                              ((safe_add_func_uint16_t_u_u(
                                   (((safe_add_func_uint32_t_u_u(
                                         (safe_mod_func_uint8_t_u_u(g_592,
                                                                    p_41)),
                                         0xEAC925D0L)) >= l_1299) != 0xB7L),
                                   0x4E2AL)) != l_1131)))) &&
                         g_212[0][0][3]),
                        p_42) ^
                       g_1254),
                      2UL)),
                  p_40))));
        for (g_181 = 0; (g_181 == 17);
             g_181 = safe_add_func_uint8_t_u_u(g_181, 9)) {
          uint32_t l_1323 = 4294967295UL;
          int32_t l_1373[9][5] = {
              {0x5324AD95L, 0xA218EA2BL, 0x5324AD95L, 0xC11A77F2L, 0xA218EA2BL},
              {9L, 1L, 0xC11A77F2L, 9L, 0xC11A77F2L},
              {9L, 9L, 1L, 0xA218EA2BL, 0xF1DE8A16L},
              {0x5324AD95L, 0xF1DE8A16L, 0xC11A77F2L, 0xC11A77F2L, 0xF1DE8A16L},
              {0xF1DE8A16L, 1L, 0x5324AD95L, 0xF1DE8A16L, 0xC11A77F2L},
              {0xA218EA2BL, 0xF1DE8A16L, 1L, 0xF1DE8A16L, 0xA218EA2BL},
              {0x5324AD95L, 9L, 1L, 0xC11A77F2L, 9L},
              {0xA218EA2BL, 1L, 1L, 0xA218EA2BL, 0xC11A77F2L},
              {0xF1DE8A16L, 0xA218EA2BL, 1L, 9L, 9L}};
          int i, j;
          for (g_1254 = 7; (g_1254 >= 0); g_1254 -= 1) {
            uint32_t l_1321 = 0xB024EE1EL;
            int i;
            l_1324 =
                (l_1135[g_1254] =
                     ((~(-4L)) ||
                      (safe_sub_func_uint32_t_u_u(
                          (safe_mod_func_uint32_t_u_u(
                              (safe_lshift_func_uint16_t_u_u(
                                  (safe_rshift_func_uint16_t_u_u(
                                      ((l_1101 |=
                                        ((g_293[0] !=
                                          (safe_add_func_int32_t_s_s(
                                              ((safe_lshift_func_int8_t_s_u(
                                                   (safe_lshift_func_uint16_t_u_s(
                                                       (safe_div_func_int32_t_s_s(
                                                           p_42,
                                                           ((((((safe_lshift_func_int8_t_s_u(
                                                                    (safe_unary_minus_func_int8_t_s(
                                                                        ((0xD2L |
                                                                          p_42) ^
                                                                         9UL))),
                                                                    (l_1137[2]
                                                                           [2]
                                                                           [1],
                                                                     0xDDL))) &&
                                                                ((g_26[0][2] <=
                                                                  1UL) |
                                                                 (-4L))) &
                                                               p_40) < 1UL) ^
                                                             0xE44FL) ^
                                                            l_1090))),
                                                       9)),
                                                   7)) |
                                               l_1321),
                                              0xF81F93B6L))) ||
                                         l_1146)) != p_40),
                                      l_1322)),
                                  10)),
                              l_1323)),
                          p_39))));
          }
          g_153[0] &=
              (g_592 !=
               (safe_lshift_func_uint16_t_u_u(
                   ((p_40 <= p_39) <= g_1185),
                   (((l_1133 = (safe_div_func_int8_t_s_s(
                          (!p_42),
                          (~(safe_add_func_int16_t_s_s(
                              (((l_1135[7] =
                                     ((safe_add_func_uint32_t_u_u(
                                          (((safe_add_func_int32_t_s_s(
                                                (safe_sub_func_uint32_t_u_u(
                                                    (safe_lshift_func_int8_t_s_s(
                                                        (1L <=
                                                         (((p_42 ==
                                                            ((safe_lshift_func_int16_t_s_s(
                                                                 (safe_lshift_func_int8_t_s_u(
                                                                     (g_119 ^=
                                                                      (g_466
                                                                           [2] &=
                                                                       l_1324)),
                                                                     g_5)),
                                                                 p_42)) > 1L)),
                                                           g_1260),
                                                          g_104)),
                                                        5)),
                                                    g_147)),
                                                0x959FEBF8L)),
                                            0xC6L) ^
                                           p_42),
                                          p_42)) >= p_41)) |
                                0x8AL) != l_1343),
                              l_1131)))))) <= l_1323),
                    l_1324))));
          g_153[0] =
              ((safe_rshift_func_uint16_t_u_u(
                   (((l_1373[0][1] =
                          (((((l_1322 !=
                               ((safe_add_func_uint32_t_u_u(
                                    (safe_rshift_func_int8_t_s_u(
                                        ((safe_add_func_uint32_t_u_u(
                                             (g_212[5][0][2] &=
                                              (l_1269 <=
                                               ((safe_mod_func_int32_t_s_s(
                                                    (safe_mod_func_uint8_t_u_u(
                                                        0x73L,
                                                        ((safe_sub_func_int8_t_s_s(
                                                             (safe_div_func_uint32_t_u_u(
                                                                 ((((safe_sub_func_uint32_t_u_u(
                                                                        (l_1135
                                                                             [2],
                                                                         (safe_div_func_uint16_t_u_u(
                                                                             (p_42 >
                                                                              l_1137
                                                                                  [2]
                                                                                  [0]
                                                                                  [0]),
                                                                             (l_1149 = (safe_div_func_int8_t_s_s(
                                                                                  (p_41 &&
                                                                                   (--l_1366
                                                                                        [2])),
                                                                                  (safe_sub_func_int32_t_s_s(
                                                                                      (-3L),
                                                                                      ((safe_rshift_func_uint16_t_u_u(
                                                                                           ((255UL &&
                                                                                             0xBAL) ^
                                                                                            0xB8L),
                                                                                           15)) ||
                                                                                       l_1269))))))))),
                                                                        0xD3F85E50L)) !=
                                                                    0xD487L),
                                                                   0x89L) &&
                                                                  l_1152[0]),
                                                                 (-4L))),
                                                             (-3L))) &
                                                         l_1323))),
                                                    l_1324)) == (-8L)))),
                                             p_41)) < g_466[3]),
                                        3)),
                                    p_40)) &&
                                65535UL)) &
                              0x8465B9E0L) &
                             l_1080) &
                            4294967289UL) > 0L)) &&
                     0x8CL) <= g_119),
                   l_1152[6])) ||
               p_40);
        }
      }
      l_1090 = (safe_div_func_uint32_t_u_u(
          (safe_mod_func_int16_t_s_s(
              (safe_rshift_func_int16_t_s_u((p_40 > 0x9767L), 0)),
              (safe_add_func_int32_t_s_s(
                  ((((safe_unary_minus_func_int16_t_s(
                         ((p_39 = 0L) || (g_119 <= 0UL)))),
                     (l_1163 >=
                      (((((safe_lshift_func_uint8_t_u_s(
                              ((l_1137[3][0][1] =
                                    ((safe_add_func_int32_t_s_s(
                                         ((-4L) !=
                                          (safe_lshift_func_uint16_t_u_u(
                                              g_395, p_41))),
                                         0xEDE3B193L)),
                                     g_212[5][0][2])) > l_1104),
                              4)) == p_40) <= 0x1AL) |
                        7UL) > 0x36L))) < g_592) <= p_42),
                  l_1101)))),
          p_40));
      if (g_258) {
        return g_5;
      } else {
        int8_t l_1389 = 0xE2L;
        int32_t l_1390[3];
        uint32_t l_1392 = 1UL;
        uint32_t l_1407[9][7] = {
            {0x4E356496L, 4294967295UL, 0xE510425EL, 4UL, 0xE510425EL,
             4294967295UL, 0x4E356496L},
            {0xBF5CB0E4L, 0x15186389L, 0x32DD2950L, 0x7EA50A58L, 0x32DD2950L,
             0x15186389L, 0xBF5CB0E4L},
            {0x4E356496L, 4294967295UL, 0xE510425EL, 4UL, 0xE510425EL,
             4294967295UL, 0x4E356496L},
            {0xBF5CB0E4L, 0x15186389L, 0x32DD2950L, 0x7EA50A58L, 0x32DD2950L,
             0x15186389L, 0xBF5CB0E4L},
            {0x4E356496L, 4294967295UL, 0xE510425EL, 4UL, 0xE510425EL,
             4294967295UL, 0x4E356496L},
            {0xBF5CB0E4L, 0x15186389L, 0x32DD2950L, 0x7EA50A58L, 0x32DD2950L,
             0x15186389L, 0xBF5CB0E4L},
            {0x4E356496L, 4294967295UL, 0xE510425EL, 4UL, 0xE510425EL,
             4294967295UL, 0x4E356496L},
            {0xBF5CB0E4L, 0x15186389L, 0x32DD2950L, 0x7EA50A58L, 0x32DD2950L,
             0x15186389L, 0xBF5CB0E4L},
            {0x4E356496L, 4294967295UL, 0xE510425EL, 4UL, 0xE510425EL,
             4294967295UL, 0x4E356496L}};
        int8_t l_1417 = 9L;
        int i, j;
        for (i = 0; i < 3; i++)
          l_1390[i] = 8L;
        ++l_1392;
        for (g_395 = (-7); (g_395 == 54);
             g_395 = safe_add_func_uint8_t_u_u(g_395, 6)) {
          uint8_t l_1416 = 0x3BL;
          g_153[0] &= (-1L);
          g_283[3] = g_378[6];
          if (((l_1090 =
                    ((0L >= 0x6F8402CFL) &&
                     (safe_mod_func_int8_t_s_s(
                         (safe_div_func_uint32_t_u_u(
                             ((g_140 ==
                               (safe_div_func_int32_t_s_s(
                                   (g_86 <
                                    (0xE4DFL ==
                                     ((safe_lshift_func_int16_t_s_u(
                                          ((l_1390[0] = g_147) != g_283[3]),
                                          (g_5,
                                           (((safe_rshift_func_uint8_t_u_s(
                                                 (((l_1135[0] = ((p_41 < 8UL) >
                                                                 l_1322)) ||
                                                   0x3CL) < l_1137[2][0][1]),
                                                 0)) ^
                                             l_1407[1][5]) == p_40)))) <
                                      65535UL))),
                                   (-2L)))),
                              l_1135[0]),
                             l_1079)),
                         l_1389)))) == 0L)) {
            return p_41;
          } else {
            l_1418 = (+(+(
                l_1149 =
                    (p_39 =
                         ((safe_mul_func_int16_t_s_s(
                              (g_255 ^= ((l_1137[0][2][1] = 65535UL) ==
                                         (p_41 != (0xC0L & g_335[5])))),
                              ((((g_1260--),
                                 ((safe_add_func_int8_t_s_s(
                                      p_42, (safe_rshift_func_int8_t_s_u(
                                                ((p_41 &&
                                                  ((l_1131 &= 0xD1L) ^ 255UL)),
                                                 (l_1389 & g_1076)),
                                                l_1392)))) != l_1416)) &&
                                5L) <= l_1417))),
                          9L)))));
          }
        }
        for (g_181 = 0; (g_181 >= (-21));
             g_181 = safe_sub_func_int16_t_s_s(g_181, 2)) {
          uint8_t l_1440 = 8UL;
          int32_t l_1461 = 0x3FB1A675L;
          for (l_1131 = 0; (l_1131 >= 1); ++l_1131) {
            int16_t l_1432 = 0x1A1CL;
            int32_t l_1442 = 2L;
            l_1442 &= (safe_lshift_func_int16_t_s_s(
                1L,
                (~(safe_lshift_func_int16_t_s_u(
                    (safe_add_func_uint16_t_u_u(
                        ((l_1429 ||
                          (0x70L |
                           (safe_div_func_uint32_t_u_u(
                               (g_212[1][0][1] ^= (l_1135[0] &= 0x6352E486L)),
                               ((l_1432 ||
                                 (((p_41, (g_1076 <= 65535UL)) &&
                                   (safe_lshift_func_int16_t_s_s(
                                       ((safe_div_func_uint32_t_u_u(
                                            (g_1441 =
                                                 (safe_add_func_uint8_t_u_u(
                                                     ((l_1439 = g_1185), g_238),
                                                     l_1440))),
                                            0xB1FA695EL)) ^
                                        0xA233L),
                                       3))) &&
                                  0x2DCA0DA6L)) &
                                p_40))))) <= g_466[0]),
                        l_1432)),
                    15)))));
            g_1462 ^=
                ((safe_add_func_int32_t_s_s(
                     0L,
                     (safe_sub_func_int16_t_s_s(
                         (g_734 = l_1163),
                         ((+((l_1461 ^= (safe_rshift_func_uint16_t_u_u(
                                  (safe_lshift_func_uint8_t_u_s(
                                      (l_1080,
                                       (l_1442 =
                                            ((0UL &
                                              ((g_283[2] &=
                                                (safe_div_func_uint16_t_u_u(
                                                    p_40, l_1146))) >=
                                               (safe_div_func_int16_t_s_s(
                                                   (safe_rshift_func_int8_t_s_s(
                                                       (safe_sub_func_uint16_t_u_u(
                                                           (safe_mod_func_uint32_t_u_u(
                                                               (g_1047 >
                                                                0xB0BCL),
                                                               g_378[3])),
                                                           p_40)),
                                                       g_147)),
                                                   g_153[0])))) ^
                                             g_395))),
                                      p_42)),
                                  l_1135[0]))) ^
                             l_1440)) > 4294967287UL))))),
                 l_1442);
            if (g_395)
              break;
          }
          for (g_119 = 0; (g_119 >= 11); ++g_119) {
            return p_40;
          }
        }
        if (g_212[5][0][2])
          break;
      }
      return p_39;
    } else {
      int32_t l_1479[1];
      int i;
      for (i = 0; i < 1; i++)
        l_1479[i] = 1L;
      if ((((((+(safe_add_func_uint16_t_u_u(
                  ((g_395 > g_181) >
                   (safe_rshift_func_uint8_t_u_u(p_40, p_42))),
                  (+((safe_div_func_int16_t_s_s(
                         p_40, (safe_div_func_uint32_t_u_u(0xCB663968L,
                                                           0x9D231198L)))) >
                     ((safe_mod_func_uint8_t_u_u(
                          (safe_add_func_int32_t_s_s(
                              ((safe_div_func_uint32_t_u_u(
                                   (g_182[4] ==
                                    (l_1479[0] =
                                         (g_153[0] =
                                              (g_283[2] = (l_1142 || p_39))))),
                                   4294967289UL)) == 65535UL),
                              g_140)),
                          0xBEL)) == (-1L))))))) &
              p_41),
             (-9L)) > g_378[6]) == g_1047)) {
        uint16_t l_1480 = 0UL;
        if (l_1152[7]) {
          --l_1480;
        } else {
          uint8_t l_1502 = 0x88L;
          for (g_395 = 0; (g_395 >= 53);
               g_395 = safe_add_func_uint32_t_u_u(g_395, 5)) {
            int32_t l_1503 = 0xBAEF0EDDL;
            p_39 = p_41;
            l_1137[0][2][1] = (safe_add_func_uint16_t_u_u(
                0x2188L,
                ((((safe_rshift_func_int16_t_s_s(0x7111L, 12)) <
                   ((((l_1480,
                       (safe_mod_func_uint8_t_u_u(
                           1UL,
                           (safe_add_func_int8_t_s_s(
                               (safe_rshift_func_uint8_t_u_s(
                                   (((0xAFL ^ 248UL) &
                                     ((((((safe_mod_func_uint32_t_u_u(
                                              (((safe_sub_func_int32_t_s_s(
                                                    (safe_unary_minus_func_int32_t_s(
                                                        (g_466[0] &&
                                                         (safe_sub_func_int32_t_s_s(
                                                             (g_153[0] =
                                                                  (l_1502 &=
                                                                   p_40)),
                                                             g_1441))))),
                                                    l_1479[0])) &&
                                                g_74) |
                                               p_41),
                                              l_1479[0])),
                                          g_181) < 3UL),
                                        l_1503) != l_1503) ||
                                      p_40)) < (-10L)),
                                   l_1196)),
                               g_1260))))),
                      g_147) |
                     0x9C733F2BL) ||
                    255UL)) < 0L) &
                 0UL)));
          }
          return g_212[2][0][0];
        }
      } else {
        if (g_1076)
          goto lbl_1116;
        if (p_40)
          continue;
      }
      g_283[6] &= ((g_86 ^= g_335[3]) <= (-1L));
      for (p_42 = 0; (p_42 >= 24); p_42++) {
        if (l_1080)
          goto lbl_1116;
      }
    }
    ++l_1506;
  }
  for (g_238 = 0; (g_238 <= 1); g_238 += 1) {
    uint8_t l_1509 = 254UL;
    int32_t l_1512 = (-2L);
    int32_t l_1513 = 0x0F84B16FL;
    int32_t l_1514 = 0L;
    int32_t l_1515[2][4][4] = {{{0L, 0L, 0L, 0L},
                                {0L, 0L, 0x1CE3882EL, 0L},
                                {0L, 0L, 0L, 0L},
                                {0L, 0L, 0L, 0L}},
                               {{0L, 0L, 0x1CE3882EL, 0L},
                                {0L, 0L, 0L, 0L},
                                {0L, 0L, 0L, 0L},
                                {0L, 0L, 0x1CE3882EL, 0L}}};
    uint8_t l_1516 = 0xB9L;
    uint16_t l_1627 = 0UL;
    uint16_t l_1632 = 0x82A1L;
    uint32_t l_1648 = 5UL;
    uint8_t l_1657 = 1UL;
    int i, j, k;
    --l_1509;
    --l_1516;
    p_39 = l_1090;
    for (l_1512 = 0; (l_1512 >= 0); l_1512 -= 1) {
      int32_t l_1556[6][8][5] = {
          {{0x9CE33AB6L, (-1L), 0xBB2712B2L, (-8L), 0x3102029EL},
           {0xBB2712B2L, 6L, 0xB1B85752L, 0xED3D9540L, 0x204B5405L},
           {(-1L), 0x7390B539L, 0xBB2712B2L, 0x3102029EL, 0x18F9CBA8L},
           {0x7D34257AL, 0x7390B539L, 0x9D746E26L, 0L, 5L},
           {0x0E89B34DL, 6L, (-1L), (-1L), 0L},
           {0x7D34257AL, (-1L), (-1L), 0x5A90B2D7L, 0L},
           {(-1L), 0L, 0x22BE0B71L, 0x01D439F9L, 0x9CE33AB6L},
           {0xF1CE9C6BL, 0xE719AD43L, 3L, (-4L), 0x22BE0B71L}},
          {{(-1L), 5L, 3L, 0xBB2712B2L, 0x0E89B34DL},
           {6L, 0x507549DDL, 0x1C3400CAL, 0x7D34257AL, 0xB1B85752L},
           {0xD079CD84L, 5L, 7L, 0xB1B85752L, 0x01D439F9L},
           {0xD079CD84L, 0xE719AD43L, 0xF01AF86BL, (-1L), (-1L)},
           {6L, 0x9EC0EB6CL, 6L, 0x67AB5A55L, 0x01D439F9L},
           {(-1L), 0x513DC93FL, 0xF1CE9C6BL, 0x67AB5A55L, 0xB1B85752L},
           {0xF1CE9C6BL, 0x93BC98FAL, 0xDEEE2C75L, (-1L), 0x0E89B34DL},
           {0xF01AF86BL, 0L, 0xF1CE9C6BL, 0xB1B85752L, 0x22BE0B71L}},
          {{0x527CC36CL, 0L, 6L, 0x7D34257AL, 0x9CE33AB6L},
           {0xEDD614E4L, 0x93BC98FAL, 0xF01AF86BL, 0xBB2712B2L, 0x7D34257AL},
           {0x527CC36CL, 0x513DC93FL, 7L, (-4L), 0x7D34257AL},
           {0xF01AF86BL, 0x9EC0EB6CL, 0x1C3400CAL, 0x01D439F9L, 0x9CE33AB6L},
           {0xF1CE9C6BL, 0xE719AD43L, 3L, (-4L), 0x22BE0B71L},
           {(-1L), 5L, 3L, 0xBB2712B2L, 0x0E89B34DL},
           {6L, 0x507549DDL, 0x1C3400CAL, 0x7D34257AL, 0xB1B85752L},
           {0xD079CD84L, 5L, 7L, 0xB1B85752L, 0x01D439F9L}},
          {{0xD079CD84L, 0xE719AD43L, 0xF01AF86BL, (-1L), (-1L)},
           {6L, 0x9EC0EB6CL, 6L, 0x67AB5A55L, 0x01D439F9L},
           {(-1L), 0x513DC93FL, 0xF1CE9C6BL, 0x67AB5A55L, 0xB1B85752L},
           {0xF1CE9C6BL, 0x93BC98FAL, 0xDEEE2C75L, (-1L), 0x0E89B34DL},
           {0xF01AF86BL, 0L, 0xF1CE9C6BL, 0xB1B85752L, 0x22BE0B71L},
           {0x527CC36CL, 0L, 6L, 0x7D34257AL, 0x9CE33AB6L},
           {0xEDD614E4L, 0x93BC98FAL, 0xF01AF86BL, 0xBB2712B2L, 0x7D34257AL},
           {0x527CC36CL, 0x513DC93FL, 7L, (-4L), 0x7D34257AL}},
          {{0xF01AF86BL, 0x9EC0EB6CL, 0x1C3400CAL, 0x01D439F9L, 0x9CE33AB6L},
           {0xF1CE9C6BL, 0xE719AD43L, 3L, (-4L), 0x22BE0B71L},
           {(-1L), 5L, 3L, 0xBB2712B2L, 0x0E89B34DL},
           {6L, 0x507549DDL, 0x1C3400CAL, 0x7D34257AL, 0xB1B85752L},
           {0xD079CD84L, 5L, 7L, 0xB1B85752L, 0x01D439F9L},
           {0xD079CD84L, 0xE719AD43L, 0xF01AF86BL, (-1L), (-1L)},
           {6L, 0x9EC0EB6CL, 6L, 0x67AB5A55L, 0x01D439F9L},
           {(-1L), 0x513DC93FL, 0xF1CE9C6BL, 0x67AB5A55L, 0xB1B85752L}},
          {{0xF1CE9C6BL, 0x93BC98FAL, 0xDEEE2C75L, (-1L), 0x0E89B34DL},
           {0xF01AF86BL, 0L, 0xF1CE9C6BL, 0xB1B85752L, 0x22BE0B71L},
           {0x527CC36CL, 0L, 6L, 0x7D34257AL, 0x9CE33AB6L},
           {0xEDD614E4L, 0x93BC98FAL, 0xF01AF86BL, 0xBB2712B2L, 0x7D34257AL},
           {0x527CC36CL, 0x513DC93FL, 7L, (-4L), 0x527CC36CL},
           {0L, (-8L), 1L, 3L, (-1L)},
           {0L, (-4L), 2L, 0xD70275B4L, 0x1C3400CAL},
           {(-1L), 0x18F9CBA8L, 2L, 0xF1CE9C6BL, 0xEDD614E4L}}};
      int32_t l_1674[3];
      int32_t l_1749[9][3] = {
          {0xDC1C682DL, (-1L), (-1L)},       {4L, 1L, 4L},
          {0xDC1C682DL, 0xDC1C682DL, (-1L)}, {0xE2B80B0EL, 1L, 0xE2B80B0EL},
          {0xDC1C682DL, (-1L), (-1L)},       {4L, 1L, 4L},
          {0xDC1C682DL, 0xDC1C682DL, (-1L)}, {0xE2B80B0EL, 1L, 0xE2B80B0EL},
          {0xDC1C682DL, (-1L), (-1L)}};
      int i, j, k;
      for (i = 0; i < 3; i++)
        l_1674[i] = 0x2B5D692AL;
      g_1519 = 0xDCC15825L;
      if ((~(safe_add_func_uint32_t_u_u((--g_212[5][0][2]),
                                        g_26[g_238][(l_1512 + 4)])))) {
        uint16_t l_1545[3][10] = {{0UL, 0xB5A1L, 65533UL, 65533UL, 0xB5A1L, 0UL,
                                   0xB5A1L, 65533UL, 65533UL, 0xB5A1L},
                                  {0UL, 0xB5A1L, 65533UL, 65533UL, 0xB5A1L, 0UL,
                                   0xB5A1L, 65533UL, 65533UL, 0xB5A1L},
                                  {0UL, 0xB5A1L, 65533UL, 65533UL, 0xB5A1L, 0UL,
                                   0xB5A1L, 65533UL, 65533UL, 0xB5A1L}};
        int32_t l_1574 = (-8L);
        uint32_t l_1581 = 3UL;
        uint32_t l_1626 = 4294967289UL;
        int32_t l_1645 = (-1L);
        int32_t l_1647 = 0xEAB8D481L;
        int i, j;
        for (l_1509 = 0; (l_1509 <= 0); l_1509 += 1) {
          int8_t l_1542 = 0x98L;
          int16_t l_1543 = 0xAC9AL;
          int i, j, k;
          for (g_258 = 0; (g_258 <= 3); g_258 += 1) {
            int i, j, k;
            l_1545[0][2] =
                (0xCBL >
                 (((0L ==
                    (safe_div_func_int32_t_s_s(
                        (g_153[0] ^=
                         (((g_283[3] =
                                (p_39 =
                                     (l_1543 =
                                          (((l_1152[3] = 0x08BB6471L) |
                                            (safe_mod_func_uint8_t_u_u(
                                                (safe_sub_func_int16_t_s_s(
                                                    (((safe_sub_func_uint32_t_u_u(
                                                          ((safe_sub_func_int16_t_s_s(
                                                               ((((safe_div_func_uint16_t_u_u(
                                                                      (safe_add_func_uint8_t_u_u(
                                                                          0x66L,
                                                                          g_212
                                                                              [(g_258 +
                                                                                3)]
                                                                              [l_1509]
                                                                              [(g_238 +
                                                                                1)])),
                                                                      0xD209L)) ||
                                                                  ((((safe_sub_func_uint8_t_u_u(
                                                                         ((((g_182[(
                                                                                 l_1512 +
                                                                                 3)] &
                                                                             (safe_rshift_func_uint16_t_u_u(
                                                                                 g_293
                                                                                     [g_238],
                                                                                 7))) &&
                                                                            g_378[(
                                                                                g_258 +
                                                                                1)]) ||
                                                                           g_378[(
                                                                               g_258 +
                                                                               4)]) <
                                                                          (-1L)),
                                                                         g_378[(
                                                                             g_258 +
                                                                             3)])),
                                                                     l_1542) ==
                                                                    g_293[1]) >=
                                                                   0xC619L)) ||
                                                                 0x92417744L) |
                                                                g_1076),
                                                               0x9AB9L)) != 1L),
                                                          (-1L))) > p_41) <=
                                                     g_26[g_238][(l_1512 + 4)]),
                                                    p_42)),
                                                1L))) ^
                                           l_1542)))) ||
                           l_1544),
                          p_41)),
                        g_258))) == l_1542) ^
                  g_1076));
            if (l_1545[0][2])
              break;
            g_153[0] =
                (((safe_lshift_func_int16_t_s_u((4UL == 0UL), 15)) <
                  (g_293[0] =
                       (l_1556[1][0][3] ^=
                        (g_26[g_238][(l_1509 + 3)] =
                             ((safe_sub_func_uint32_t_u_u(g_378[(g_258 + 1)],
                                                          g_438)) >
                              ((safe_lshift_func_uint16_t_u_u(
                                   (((l_1142 !=
                                      (((((safe_rshift_func_uint8_t_u_u(0xBBL,
                                                                        4)) >=
                                          (~((safe_rshift_func_uint16_t_u_s(
                                                 (((((g_335[5] |= p_42),
                                                     g_293[0]) ^
                                                    g_26[g_238][(l_1512 + 4)]) >
                                                   p_41) ==
                                                  g_212[(g_258 + 3)][l_1509]
                                                       [(g_238 + 1)]),
                                                 g_378[(g_258 + 3)])),
                                             l_1514))) ^
                                         l_1101) != g_153[0]) <=
                                       l_1545[0][2])) >= p_41) &
                                    4294967295UL),
                                   l_1080)) >= l_1515[0][3][2])))))),
                 g_283[3]);
            ++l_1557;
          }
          if (g_212[(l_1509 + 3)][l_1509][(l_1512 + 3)])
            break;
          l_1556[4][3][4] &=
              (1UL ==
               (safe_mod_func_int32_t_s_s(
                   ((l_1514 ^=
                     ((g_592 |=
                       (g_182[(l_1512 + 5)] >=
                        ((safe_mod_func_uint32_t_u_u(
                             ((g_335[5] = (~(
                                   (safe_rshift_func_int16_t_s_s(
                                       g_182[(l_1509 + 3)],
                                       (g_293[(l_1509 + 1)],
                                        ((safe_lshift_func_int16_t_s_u(
                                             (~((safe_rshift_func_uint8_t_u_s(
                                                    g_212[(l_1509 + 3)][l_1509]
                                                         [(l_1512 + 3)],
                                                    p_40)) !=
                                                (safe_mod_func_uint16_t_u_u(
                                                    l_1080,
                                                    (((safe_add_func_int32_t_s_s(
                                                          ((l_1513 =
                                                                ((l_1574 =
                                                                      (((0UL ||
                                                                         l_1150),
                                                                        0x0C39L) ^
                                                                       65531UL)) >=
                                                                 g_26[0][0])) &&
                                                           0x107E163AL),
                                                          g_1254)) > p_39),
                                                     p_41))))),
                                             p_40)) ||
                                         l_1545[0][3])))),
                                   65530UL))) == 0x81DEL),
                             9L)) < g_438))) &&
                      p_39)) ^
                    p_39),
                   p_39)));
        }
        l_1556[4][7][1] = l_1509;
        if (((safe_sub_func_uint32_t_u_u(
                 (((g_212[1][0][7] =
                        (g_140 &
                         (safe_sub_func_int8_t_s_s(
                             (0xC978L <=
                              (((safe_mod_func_uint32_t_u_u(
                                    (l_1581 = l_1574),
                                    ((0x934C65BFL | (safe_mod_func_int16_t_s_s(
                                                        (-10L), 0xDE29L))),
                                     g_86))) < 0xDC1D5787L) >=
                               (0xCCL == 0x05L))),
                             g_1462)))) != (-1L)),
                  p_42),
                 l_1101)),
             0xD70FF1DBL)) {
          int8_t l_1595 = (-3L);
          int32_t l_1601 = (-1L);
          for (g_86 = 1; (g_86 >= 0); g_86 -= 1) {
            int32_t l_1600[1][10] = {{(-4L), (-10L), (-4L), (-10L), (-4L),
                                      (-10L), (-4L), (-10L), (-4L), (-10L)}};
            uint32_t l_1641 = 0x5710A45CL;
            int i, j, k;
            l_1601 =
                (g_212[(g_86 + 3)][l_1512][(l_1512 + 6)] !=
                 (!(((safe_add_func_uint16_t_u_u(
                         65535UL,
                         (g_335[1] =
                              ((safe_rshift_func_uint8_t_u_s(
                                   ((safe_add_func_uint32_t_u_u(
                                        g_212[(g_86 + 5)][l_1512][(g_238 + 1)],
                                        (safe_unary_minus_func_uint32_t_u((safe_div_func_uint32_t_u_u(
                                            (safe_rshift_func_uint16_t_u_s(
                                                l_1595,
                                                (l_1595 |
                                                 (safe_sub_func_uint16_t_u_u(
                                                     (safe_add_func_uint32_t_u_u(
                                                         p_39,
                                                         (l_1515[0][3][2] =
                                                              (l_1600[0][0] =
                                                                   (l_1150 =
                                                                        (p_41 >
                                                                         (((+(l_1574 ==
                                                                              p_40)) ==
                                                                           (-9L)) ^
                                                                          l_1513))))))),
                                                     p_41))))),
                                            g_26[0][4])))))) &&
                                    l_1142),
                                   p_41)) ||
                               g_734)))) < p_39) ||
                    g_1462)));
            p_39 =
                (((safe_div_func_int32_t_s_s(
                      ((l_1627 = (safe_lshift_func_int8_t_s_u(
                            (safe_add_func_int8_t_s_s(
                                l_1090,
                                ((g_26[g_86][(g_86 + 2)] = p_41) <=
                                 (safe_sub_func_int32_t_s_s(
                                     (l_1556[1][0][3] =
                                          (((safe_mod_func_uint16_t_u_u(
                                                ((l_1513 |= 0xF153L) |
                                                 l_1515[0][3][2]),
                                                ((safe_add_func_uint32_t_u_u(
                                                     g_1260,
                                                     ((!(safe_div_func_uint8_t_u_u(
                                                          (safe_rshift_func_int16_t_s_s(
                                                              (((safe_mod_func_int32_t_s_s(
                                                                    ((safe_div_func_int8_t_s_s(
                                                                         ((safe_div_func_int16_t_s_s(
                                                                              (l_1514 |=
                                                                               p_41),
                                                                              0x0B0DL)),
                                                                          ((safe_lshift_func_uint8_t_u_u(
                                                                               (p_39,
                                                                                ((l_1574 =
                                                                                      ((p_40 !=
                                                                                        l_1090) <
                                                                                       0L)),
                                                                                 p_39)),
                                                                               g_1462)) >
                                                                           g_1519)),
                                                                         p_41)) ||
                                                                     g_140),
                                                                    p_41)) !=
                                                                l_1545[0][2]) <
                                                               l_1626),
                                                              2)),
                                                          l_1515[0][3][2]))) <=
                                                      1UL))),
                                                 p_39))) |
                                            g_212[(g_86 + 3)][l_1512]
                                                 [(l_1512 + 6)]) &&
                                           1L)),
                                     p_39))))),
                            4))) ||
                       g_1462),
                      l_1515[0][3][2])) ^
                  0L) ^
                 p_40);
            g_283[1] =
                ((safe_rshift_func_uint16_t_u_s(
                     ((((l_1600[0][2] ||
                         (l_1574 = (safe_div_func_int32_t_s_s(
                              (l_1632 >=
                               ((-7L) &
                                (((((8L !=
                                     (safe_lshift_func_int16_t_s_s(
                                         (((((g_153[4] &=
                                              (safe_rshift_func_int16_t_s_u(
                                                  (safe_rshift_func_uint16_t_u_u(
                                                      0xC353L, 13)),
                                                  13))) > g_466[1]) >
                                            ((g_293[0] &&
                                              ((1L |
                                                (safe_rshift_func_uint8_t_u_s(
                                                    g_26[g_238][(l_1512 + 4)],
                                                    l_1595))),
                                               0xD0L)) ||
                                             p_40)) <= l_1556[0][2][0]) ||
                                          p_40),
                                         0))),
                                    l_1557) &&
                                   0L) ||
                                  p_41) < l_1641))),
                              0x4D8BC72BL)))) < g_212[1][0][3]),
                       6L) ||
                      l_1079),
                     g_378[1])) < g_104);
          }
          if (g_181)
            break;
          g_153[6] = (g_283[4], 0xEAC6AEF0L);
        } else {
          int16_t l_1642 = 0xD64DL;
          int32_t l_1643 = 1L;
          int32_t l_1644 = 0x40E76B0AL;
          int32_t l_1646 = 0L;
          --l_1648;
          p_39 = l_1557;
          p_39 = l_1645;
        }
      } else {
        uint32_t l_1653 = 0UL;
        int32_t l_1654 = 4L;
        int32_t l_1732[1][2];
        uint8_t l_1733 = 0x9CL;
        int i, j;
        for (i = 0; i < 1; i++) {
        }
        g_283[3] |= (-5L);

        p_39 = l_1090;
      }

      {
        int32_t l_1556[6][8][5] = {
            {{0x9CE33AB6L, (-1L), 0xBB2712B2L, (-8L), 0x3102029EL},
             {0xBB2712B2L, 6L, 0xB1B85752L, 0xED3D9540L, 0x204B5405L},
             {(-1L), 0x7390B539L, 0xBB2712B2L, 0x3102029EL, 0x18F9CBA8L},
             {0x7D34257AL, 0x7390B539L, 0x9D746E26L, 0L, 5L},
             {0x0E89B34DL, 6L, (-1L), (-1L), 0L},
             {0x7D34257AL, (-1L), (-1L), 0x5A90B2D7L, 0L},
             {(-1L), 0L, 0x22BE0B71L, 0x01D439F9L, 0x9CE33AB6L},
             {0xF1CE9C6BL, 0xE719AD43L, 3L, (-4L), 0x22BE0B71L}},
            {{(-1L), 5L, 3L, 0xBB2712B2L, 0x0E89B34DL},
             {6L, 0x507549DDL, 0x1C3400CAL, 0x7D34257AL, 0xB1B85752L},
             {0xD079CD84L, 5L, 7L, 0xB1B85752L, 0x01D439F9L},
             {0xD079CD84L, 0xE719AD43L, 0xF01AF86BL, (-1L), (-1L)},
             {6L, 0x9EC0EB6CL, 6L, 0x67AB5A55L, 0x01D439F9L},
             {(-1L), 0x513DC93FL, 0xF1CE9C6BL, 0x67AB5A55L, 0xB1B85752L},
             {0xF1CE9C6BL, 0x93BC98FAL, 0xDEEE2C75L, (-1L), 0x0E89B34DL},
             {0xF01AF86BL, 0L, 0xF1CE9C6BL, 0xB1B85752L, 0x22BE0B71L}},
            {{0x527CC36CL, 0L, 6L, 0x7D34257AL, 0x9CE33AB6L},
             {0xEDD614E4L, 0x93BC98FAL, 0xF01AF86BL, 0xBB2712B2L, 0x7D34257AL},
             {0x527CC36CL, 0x513DC93FL, 7L, (-4L), 0x7D34257AL},
             {0xF01AF86BL, 0x9EC0EB6CL, 0x1C3400CAL, 0x01D439F9L, 0x9CE33AB6L},
             {0xF1CE9C6BL, 0xE719AD43L, 3L, (-4L), 0x22BE0B71L},
             {(-1L), 5L, 3L, 0xBB2712B2L, 0x0E89B34DL},
             {6L, 0x507549DDL, 0x1C3400CAL, 0x7D34257AL, 0xB1B85752L},
             {0xD079CD84L, 5L, 7L, 0xB1B85752L, 0x01D439F9L}},
            {{0xD079CD84L, 0xE719AD43L, 0xF01AF86BL, (-1L), (-1L)},
             {6L, 0x9EC0EB6CL, 6L, 0x67AB5A55L, 0x01D439F9L},
             {(-1L), 0x513DC93FL, 0xF1CE9C6BL, 0x67AB5A55L, 0xB1B85752L},
             {0xF1CE9C6BL, 0x93BC98FAL, 0xDEEE2C75L, (-1L), 0x0E89B34DL},
             {0xF01AF86BL, 0L, 0xF1CE9C6BL, 0xB1B85752L, 0x22BE0B71L},
             {0x527CC36CL, 0L, 6L, 0x7D34257AL, 0x9CE33AB6L},
             {0xEDD614E4L, 0x93BC98FAL, 0xF01AF86BL, 0xBB2712B2L, 0x7D34257AL},
             {0x527CC36CL, 0x513DC93FL, 7L, (-4L), 0x7D34257AL}},
            {{0xF01AF86BL, 0x9EC0EB6CL, 0x1C3400CAL, 0x01D439F9L, 0x9CE33AB6L},
             {0xF1CE9C6BL, 0xE719AD43L, 3L, (-4L), 0x22BE0B71L},
             {(-1L), 5L, 3L, 0xBB2712B2L, 0x0E89B34DL},
             {6L, 0x507549DDL, 0x1C3400CAL, 0x7D34257AL, 0xB1B85752L},
             {0xD079CD84L, 5L, 7L, 0xB1B85752L, 0x01D439F9L},
             {0xD079CD84L, 0xE719AD43L, 0xF01AF86BL, (-1L), (-1L)},
             {6L, 0x9EC0EB6CL, 6L, 0x67AB5A55L, 0x01D439F9L},
             {(-1L), 0x513DC93FL, 0xF1CE9C6BL, 0x67AB5A55L, 0xB1B85752L}},
            {{0xF1CE9C6BL, 0x93BC98FAL, 0xDEEE2C75L, (-1L), 0x0E89B34DL},
             {0xF01AF86BL, 0L, 0xF1CE9C6BL, 0xB1B85752L, 0x22BE0B71L},
             {0x527CC36CL, 0L, 6L, 0x7D34257AL, 0x9CE33AB6L},
             {0xEDD614E4L, 0x93BC98FAL, 0xF01AF86BL, 0xBB2712B2L, 0x7D34257AL},
             {0x527CC36CL, 0x513DC93FL, 7L, (-4L), 0x527CC36CL},
             {0L, (-8L), 1L, 3L, (-1L)},
             {0L, (-4L), 2L, 0xD70275B4L, 0x1C3400CAL},
             {(-1L), 0x18F9CBA8L, 2L, 0xF1CE9C6BL, 0xEDD614E4L}}};
        int32_t l_1674[3];
        int32_t l_1749[9][3] = {
            {0xDC1C682DL, (-1L), (-1L)},       {4L, 1L, 4L},
            {0xDC1C682DL, 0xDC1C682DL, (-1L)}, {0xE2B80B0EL, 1L, 0xE2B80B0EL},
            {0xDC1C682DL, (-1L), (-1L)},       {4L, 1L, 4L},
            {0xDC1C682DL, 0xDC1C682DL, (-1L)}, {0xE2B80B0EL, 1L, 0xE2B80B0EL},
            {0xDC1C682DL, (-1L), (-1L)}};
        int i, j, k;
        for (i = 0; i < 3; i++)
          l_1674[i] = 0x2B5D692AL;
        g_1519 = 0xDCC15825L;
        if ((~(safe_add_func_uint32_t_u_u((--g_212[5][0][2]),
                                          g_26[g_238][(l_1512 + 4)])))) {
          uint16_t l_1545[3][10] = {{0UL, 0xB5A1L, 65533UL, 65533UL, 0xB5A1L,
                                     0UL, 0xB5A1L, 65533UL, 65533UL, 0xB5A1L},
                                    {0UL, 0xB5A1L, 65533UL, 65533UL, 0xB5A1L,
                                     0UL, 0xB5A1L, 65533UL, 65533UL, 0xB5A1L},
                                    {0UL, 0xB5A1L, 65533UL, 65533UL, 0xB5A1L,
                                     0UL, 0xB5A1L, 65533UL, 65533UL, 0xB5A1L}};
          int32_t l_1574 = (-8L);
          uint32_t l_1581 = 3UL;
          uint32_t l_1626 = 4294967289UL;
          int32_t l_1645 = (-1L);
          int32_t l_1647 = 0xEAB8D481L;
          int i, j;
          for (l_1509 = 0; (l_1509 <= 0); l_1509 += 1) {
            int8_t l_1542 = 0x98L;
            int16_t l_1543 = 0xAC9AL;
            int i, j, k;
            for (g_258 = 0; (g_258 <= 3); g_258 += 1) {
              int i, j, k;
              l_1545[0][2] =
                  (0xCBL >
                   (((0L ==
                      (safe_div_func_int32_t_s_s(
                          (g_153[0] ^=
                           (((g_283[3] =
                                  (p_39 =
                                       (l_1543 =
                                            (((l_1152[3] = 0x08BB6471L) |
                                              (safe_mod_func_uint8_t_u_u(
                                                  (safe_sub_func_int16_t_s_s(
                                                      (((safe_sub_func_uint32_t_u_u(
                                                            ((safe_sub_func_int16_t_s_s(
                                                                 ((((safe_div_func_uint16_t_u_u(
                                                                        (safe_add_func_uint8_t_u_u(
                                                                            0x66L,
                                                                            g_212
                                                                                [(g_258 +
                                                                                  3)]
                                                                                [l_1509]
                                                                                [(g_238 +
                                                                                  1)])),
                                                                        0xD209L)) ||
                                                                    ((((safe_sub_func_uint8_t_u_u(
                                                                           ((((g_182[(
                                                                                   l_1512 +
                                                                                   3)] &
                                                                               (safe_rshift_func_uint16_t_u_u(
                                                                                   g_293
                                                                                       [g_238],
                                                                                   7))) &&
                                                                              g_378[(
                                                                                  g_258 +
                                                                                  1)]) ||
                                                                             g_378[(
                                                                                 g_258 +
                                                                                 4)]) <
                                                                            (-1L)),
                                                                           g_378[(
                                                                               g_258 +
                                                                               3)])),
                                                                       l_1542) ==
                                                                      g_293
                                                                          [1]) >=
                                                                     0xC619L)) ||
                                                                   0x92417744L) |
                                                                  g_1076),
                                                                 0x9AB9L)) !=
                                                             1L),
                                                            (-1L))) > p_41) <=
                                                       g_26[g_238]
                                                           [(l_1512 + 4)]),
                                                      p_42)),
                                                  1L))) ^
                                             l_1542)))) ||
                             l_1544),
                            p_41)),
                          g_258))) == l_1542) ^
                    g_1076));
              if (l_1545[0][2])
                break;
              g_153[0] =
                  (((safe_lshift_func_int16_t_s_u((4UL == 0UL), 15)) <
                    (g_293[0] =
                         (l_1556[1][0][3] ^=
                          (g_26[g_238][(l_1509 + 3)] =
                               ((safe_sub_func_uint32_t_u_u(g_378[(g_258 + 1)],
                                                            g_438)) >
                                ((safe_lshift_func_uint16_t_u_u(
                                     (((l_1142 !=
                                        (((((safe_rshift_func_uint8_t_u_u(0xBBL,
                                                                          4)) >=
                                            (~((safe_rshift_func_uint16_t_u_s(
                                                   (((((g_335[5] |= p_42),
                                                       g_293[0]) ^
                                                      g_26[g_238]
                                                          [(l_1512 + 4)]) >
                                                     p_41) ==
                                                    g_212[(g_258 + 3)][l_1509]
                                                         [(g_238 + 1)]),
                                                   g_378[(g_258 + 3)])),
                                               l_1514))) ^
                                           l_1101) != g_153[0]) <=
                                         l_1545[0][2])) >= p_41) &
                                      4294967295UL),
                                     l_1080)) >= l_1515[0][3][2])))))),
                   g_283[3]);
              ++l_1557;
            }
            if (g_212[(l_1509 + 3)][l_1509][(l_1512 + 3)])
              break;
            l_1556[4][3][4] &=
                (1UL ==
                 (safe_mod_func_int32_t_s_s(
                     ((l_1514 ^=
                       ((g_592 |=
                         (g_182[(l_1512 + 5)] >=
                          ((safe_mod_func_uint32_t_u_u(
                               ((g_335[5] = (~(
                                     (safe_rshift_func_int16_t_s_s(
                                         g_182[(l_1509 + 3)],
                                         (g_293[(l_1509 + 1)],
                                          ((safe_lshift_func_int16_t_s_u(
                                               (~((safe_rshift_func_uint8_t_u_s(
                                                      g_212[(l_1509 + 3)]
                                                           [l_1509]
                                                           [(l_1512 + 3)],
                                                      p_40)) !=
                                                  (safe_mod_func_uint16_t_u_u(
                                                      l_1080,
                                                      (((safe_add_func_int32_t_s_s(
                                                            ((l_1513 =
                                                                  ((l_1574 =
                                                                        (((0UL ||
                                                                           l_1150),
                                                                          0x0C39L) ^
                                                                         65531UL)) >=
                                                                   g_26[0]
                                                                       [0])) &&
                                                             0x107E163AL),
                                                            g_1254)) > p_39),
                                                       p_41))))),
                                               p_40)) ||
                                           l_1545[0][3])))),
                                     65530UL))) == 0x81DEL),
                               9L)) < g_438))) &&
                        p_39)) ^
                      p_39),
                     p_39)));
          }
          l_1556[4][7][1] = l_1509;
          if (((safe_sub_func_uint32_t_u_u(
                   (((g_212[1][0][7] =
                          (g_140 &
                           (safe_sub_func_int8_t_s_s(
                               (0xC978L <= (((safe_mod_func_uint32_t_u_u(
                                                 (l_1581 = l_1574),
                                                 ((0x934C65BFL |
                                                   (safe_mod_func_int16_t_s_s(
                                                       (-10L), 0xDE29L))),
                                                  g_86))) < 0xDC1D5787L) >=
                                            (0xCCL == 0x05L))),
                               g_1462)))) != (-1L)),
                    p_42),
                   l_1101)),
               0xD70FF1DBL)) {
            int8_t l_1595 = (-3L);
            int32_t l_1601 = (-1L);
            for (g_86 = 1; (g_86 >= 0); g_86 -= 1) {
              int32_t l_1600[1][10] = {{(-4L), (-10L), (-4L), (-10L), (-4L),
                                        (-10L), (-4L), (-10L), (-4L), (-10L)}};
              uint32_t l_1641 = 0x5710A45CL;
              int i, j, k;
              l_1601 =
                  (g_212[(g_86 + 3)][l_1512][(l_1512 + 6)] !=
                   (!(((safe_add_func_uint16_t_u_u(
                           65535UL,
                           (g_335[1] =
                                ((safe_rshift_func_uint8_t_u_s(
                                     ((safe_add_func_uint32_t_u_u(
                                          g_212[(g_86 + 5)][l_1512]
                                               [(g_238 + 1)],
                                          (safe_unary_minus_func_uint32_t_u((safe_div_func_uint32_t_u_u(
                                              (safe_rshift_func_uint16_t_u_s(
                                                  l_1595,
                                                  (l_1595 |
                                                   (safe_sub_func_uint16_t_u_u(
                                                       (safe_add_func_uint32_t_u_u(
                                                           p_39,
                                                           (l_1515[0][3][2] =
                                                                (l_1600[0][0] =
                                                                     (l_1150 =
                                                                          (p_41 >
                                                                           (((+(l_1574 ==
                                                                                p_40)) ==
                                                                             (-9L)) ^
                                                                            l_1513))))))),
                                                       p_41))))),
                                              g_26[0][4])))))) &&
                                      l_1142),
                                     p_41)) ||
                                 g_734)))) < p_39) ||
                      g_1462)));
              p_39 =
                  (((safe_div_func_int32_t_s_s(
                        ((l_1627 = (safe_lshift_func_int8_t_s_u(
                              (safe_add_func_int8_t_s_s(
                                  l_1090,
                                  ((g_26[g_86][(g_86 + 2)] = p_41) <=
                                   (safe_sub_func_int32_t_s_s(
                                       (l_1556[1][0][3] =
                                            (((safe_mod_func_uint16_t_u_u(
                                                  ((l_1513 |= 0xF153L) |
                                                   l_1515[0][3][2]),
                                                  ((safe_add_func_uint32_t_u_u(
                                                       g_1260,
                                                       ((!(safe_div_func_uint8_t_u_u(
                                                            (safe_rshift_func_int16_t_s_s(
                                                                (((safe_mod_func_int32_t_s_s(
                                                                      ((safe_div_func_int8_t_s_s(
                                                                           ((safe_div_func_int16_t_s_s(
                                                                                (l_1514 |=
                                                                                 p_41),
                                                                                0x0B0DL)),
                                                                            ((safe_lshift_func_uint8_t_u_u(
                                                                                 (p_39,
                                                                                  ((l_1574 =
                                                                                        ((p_40 !=
                                                                                          l_1090) <
                                                                                         0L)),
                                                                                   p_39)),
                                                                                 g_1462)) >
                                                                             g_1519)),
                                                                           p_41)) ||
                                                                       g_140),
                                                                      p_41)) !=
                                                                  l_1545[0]
                                                                        [2]) <
                                                                 l_1626),
                                                                2)),
                                                            l_1515[0][3]
                                                                  [2]))) <=
                                                        1UL))),
                                                   p_39))) |
                                              g_212[(g_86 + 3)][l_1512]
                                                   [(l_1512 + 6)]) &&
                                             1L)),
                                       p_39))))),
                              4))) ||
                         g_1462),
                        l_1515[0][3][2])) ^
                    0L) ^
                   p_40);
              g_283[1] =
                  ((safe_rshift_func_uint16_t_u_s(
                       ((((l_1600[0][2] ||
                           (l_1574 = (safe_div_func_int32_t_s_s(
                                (l_1632 >=
                                 ((-7L) &
                                  (((((8L !=
                                       (safe_lshift_func_int16_t_s_s(
                                           (((((g_153[4] &=
                                                (safe_rshift_func_int16_t_s_u(
                                                    (safe_rshift_func_uint16_t_u_u(
                                                        0xC353L, 13)),
                                                    13))) > g_466[1]) >
                                              ((g_293[0] &&
                                                ((1L |
                                                  (safe_rshift_func_uint8_t_u_s(
                                                      g_26[g_238][(l_1512 + 4)],
                                                      l_1595))),
                                                 0xD0L)) ||
                                               p_40)) <= l_1556[0][2][0]) ||
                                            p_40),
                                           0))),
                                      l_1557) &&
                                     0L) ||
                                    p_41) < l_1641))),
                                0x4D8BC72BL)))) < g_212[1][0][3]),
                         6L) ||
                        l_1079),
                       g_378[1])) < g_104);
            }
            if (g_181)
              break;
            g_153[6] = (g_283[4], 0xEAC6AEF0L);
          } else {
            int16_t l_1642 = 0xD64DL;
            int32_t l_1643 = 1L;
            int32_t l_1644 = 0x40E76B0AL;
            int32_t l_1646 = 0L;
            --l_1648;
            p_39 = l_1557;
            p_39 = l_1645;
          }
        } else {
          uint32_t l_1653 = 0UL;
          int32_t l_1654 = 4L;
          int32_t l_1732[1][2];
          uint8_t l_1733 = 0x9CL;
          int i, j;
          for (i = 0; i < 1; i++) {
            for (j = 0; j < 2; j++)
              l_1732[i][j] = 8L;
          }
          g_283[3] |= (-5L);
          if ((safe_div_func_uint8_t_u_u(p_39,
                                         (l_1654 &= (l_1653 == (-1L)))))) {
            int16_t l_1656 = 0x51A4L;
            l_1556[1][2][3] = (l_1648 >= g_466[0]);
            ++l_1657;
            for (p_42 = 0; p_42 < 7; p_42 += 1) {
              for (l_1514 = 0; l_1514 < 1; l_1514 += 1) {
                for (g_734 = 0; g_734 < 8; g_734 += 1) {
                  g_212[p_42][l_1514][g_734] = 0x82839A75L;
                }
              }
            }
          } else {
            uint8_t l_1677 = 254UL;
            int32_t l_1678 = 0x00238138L;
            if ((g_238 &&
                 ((safe_div_func_uint8_t_u_u(
                      l_1080,
                      (((l_1090 ^= (safe_mod_func_int16_t_s_s(
                             (l_1678 =
                                  (g_255 = (~(
                                       (safe_sub_func_int32_t_s_s(
                                           8L,
                                           (l_1654 &=
                                            (safe_rshift_func_uint8_t_u_s(
                                                ((l_1556[1][0][3] ^=
                                                  g_283[3]) ==
                                                 (((((safe_add_func_uint8_t_u_u(
                                                         ((safe_sub_func_uint16_t_u_u(
                                                              (p_39,
                                                               (safe_add_func_uint8_t_u_u(
                                                                   ((l_1152[7] =
                                                                         (~0x8C6FL)) ==
                                                                    (g_734 =
                                                                         (l_1674[1] =
                                                                              (~l_1509)))),
                                                                   ((safe_add_func_uint8_t_u_u(
                                                                        l_1677,
                                                                        (0x1685L !=
                                                                         1UL))) <=
                                                                    0x7F19L)))),
                                                              p_41)) &&
                                                          l_1509),
                                                         l_1146)) != 1UL) ^
                                                    p_40) >= g_293[0]),
                                                  g_283[3])),
                                                4))))) < g_395)))),
                             (-2L)))) > 0x1F30L) ||
                       0xCD3F9BEDL))) != g_153[6]))) {
              int16_t l_1685[2];
              int32_t l_1696 = 0L;
              int i;
              for (i = 0; i < 2; i++)
                l_1685[i] = 0L;
              l_1090 ^= ((safe_div_func_int8_t_s_s(
                             (((safe_add_func_int16_t_s_s(
                                   (p_40 ^ (l_1685[0] = (l_1556[1][0][3] !=
                                                         ((p_41, p_39), 1UL)))),
                                   p_41)) >
                               (g_592,
                                (l_1678 <=
                                 ((g_283[4] |=
                                   (((safe_lshift_func_uint16_t_u_s(
                                         (safe_mod_func_uint32_t_u_u(
                                             (safe_div_func_int32_t_s_s(
                                                 ((g_438--) &
                                                  ((((safe_mod_func_int16_t_s_s(
                                                         (0x6FL | 1L),
                                                         0x6B44L)) >= (-1L)) &
                                                    p_41) ||
                                                   (-10L))),
                                                 l_1696)),
                                             l_1142)),
                                         5)),
                                     255UL) &
                                    7UL)) &&
                                  g_26[g_238][(l_1512 + 4)])))) |
                              0xD912B9D6L),
                             p_39)) |
                         l_1697);
              return g_378[6];
            } else {
              uint32_t l_1698 = 0x898565AEL;
              l_1698++;
              if (g_283[3])
                break;
     l_1654
       =
       (g_283
        [3]
        =
        (p_39
  =
  (((--p_42), ((((safe_mod_func_uint8_t_u_u ((((g_293[0]--) < (((g_153[0] |= (safe_lshift_func_uint8_t_u_s ((safe_lshift_func_uint16_t_u_u ((((safe_mod_func_int8_t_s_s (((l_1556[1][5][4] > (((~(p_42 & (safe_lshift_func_uint16_t_u_u ((g_104 = p_40), ((((l_1657 == 8L) == (safe_div_func_uint32_t_u_u ((((safe_lshift_func_int8_t_s_s (((l_1698, g_1076), (l_1090 &= (((l_1150 |= (safe_sub_func_int8_t_s_s (((g_86 | ((safe_mod_func_uint16_t_u_u ((~(g_335[2] = (safe_rshift_func_int8_t_s_s (((safe_lshift_func_uint16_t_u_u (((safe_rshift_func_int16_t_s_s ((~1L), l_1654)) & p_40), 8)), l_1654), l_1632)))), g_1076)) && l_1731)), 0xCFL), g_378[6]))) || l_1678) & 0x64AA7D07L))), g_1076)) & g_378[2]) != p_41), 0x977026D3L))) == g_283[3]), g_26[1][1]))))), 0xE7L) != l_1674[0])) && l_1677), g_86)) || 0x6D00L) ^ l_1653), 7)), 4))) || l_1698) > l_1678)) && p_40), 0xD8L)) < (-1L)) & l_1678), g_238)) == l_1678)));
            }
          }
          ++l_1733;
        }
        if ((safe_mod_func_int8_t_s_s(
                (l_1146 ==
                 ((safe_mod_func_int16_t_s_s(
                      (safe_div_func_uint16_t_u_u(
                          0xE50AL,
                          (safe_mod_func_int8_t_s_s(
                              (g_1462 &=
                               (((((((safe_div_func_uint32_t_u_u(
                                         (g_1254,
                                          ((((p_39, 7UL) || l_1731),
                                            (safe_rshift_func_int16_t_s_u(
                                                (safe_unary_minus_func_int8_t_s(
                                                    ((g_26[0][0] &= p_40) >=
                                                     0L))),
                                                11))) ||
                                           (l_1674[2] =
                                                ((1UL <= l_1749[4][0]) ||
                                                 0x40L)))),
                                         p_40)) &&
                                     l_1750[6][1][1]) < l_1515[0][1][1]) ^
                                   0UL) == g_335[5]),
                                 (-1L)) >= 0x94CBB10BL)),
                              p_42)))),
                      0x090EL)) >= p_42)),
                g_734))) {
          int32_t l_1772[4][7] = {
              {0L, 1L, 0xAD015D6CL, 0xAD015D6CL, 1L, 0L, 1L},
              {0x1F8B8010L, 0xAF31C057L, 0xAF31C057L, 0x1F8B8010L, 7L,
               0x1F8B8010L, 0xAF31C057L},
              {0L, 0L, 0L, 0xAD015D6CL, 0L, 0L, 0L},
              {0x3580C8ECL, 0xAF31C057L, 0x3F56E9C4L, 0xAF31C057L, 0x3580C8ECL,
               0x3580C8ECL, 0xAF31C057L}};
          int32_t l_1785 = (-7L);
          int32_t l_1788 = 1L;
          int32_t l_1789 = 0x9654DDE8L;
          int i, j;
          if (g_119)
            goto lbl_1751;
          g_283[2] =
              (g_153[0] =
                   ((safe_mul_func_int16_t_s_s(
                        (p_40 < p_39),
                        (((safe_mod_func_int16_t_s_s(
                              (safe_lshift_func_int16_t_s_s(
                                  (l_1513 =
                                       ((((safe_div_func_uint16_t_u_u(g_1185,
                                                                      g_1047)) <
                                          ((((((g_212[5][0][2] ^=
                                                (g_335[5] ^
                                                 (g_258, l_1749[4][0]))) ==
                                               (safe_rshift_func_uint8_t_u_s(
                                                   g_378[0], 4))),
                                              p_39),
                                             0x58L) < 255UL) ||
                                           (-1L))) |
                                         p_40) |
                                        l_1146)),
                                  11)),
                              g_438)) > 0x6B57L) == p_40))),
                    6L));
          l_1789 |=
              (p_39 =
                   ((safe_rshift_func_int16_t_s_s(
                        (l_1515[0][2][1] =
                             (g_1076 |=
                              (~((safe_sub_func_int8_t_s_s(
                                     (p_41 <
                                      (l_1556[1][0][3] =
                                           ((safe_add_func_int8_t_s_s(
                                                (-1L),
                                                ((l_1772[3][4] =
                                                      (((safe_rshift_func_uint8_t_u_u(
                                                            p_39, 2)) == 9UL) <=
                                                       (0xEF8FL ==
                                                        (g_734 = (g_1655 |
                                                                  p_40))))) >=
                                                 (safe_div_func_uint8_t_u_u(
                                                     (safe_mul_func_uint16_t_u_u(
                                                         (safe_div_func_uint8_t_u_u(
                                                             (safe_add_func_int16_t_s_s(
                                                                 (safe_lshift_func_int16_t_s_u(
                                                                     (safe_rshift_func_int16_t_s_u(
                                                                         (l_1785 =
                                                                              0x9E8CL),
                                                                         ((l_1142 = (!(
                                                                               l_1514 &=
                                                                               ((safe_sub_func_int8_t_s_s(
                                                                                    p_39,
                                                                                    p_40)) |
                                                                                0xAC88L)))) &
                                                                          2L))),
                                                                     3)),
                                                                 0x58F2L)),
                                                             g_212[5][0][2])),
                                                         0UL)),
                                                     l_1788))))) == g_592))),
                                     g_86)) == l_1150)))),
                        g_153[0])) &&
                    (-7L)));
        } else {
          uint8_t l_1790[2][6][4] = {{{5UL, 0x38L, 0x1BL, 255UL},
                                      {5UL, 0x13L, 0x13L, 5UL},
                                      {0xB0L, 255UL, 0xBCL, 0x13L},
                                      {255UL, 0x38L, 0x8FL, 255UL},
                                      {0xA7L, 0xB0L, 0x13L, 255UL},
                                      {1UL, 0x38L, 1UL, 0x13L}},
                                     {{5UL, 255UL, 251UL, 5UL},
                                      {0xA7L, 0x13L, 0xBCL, 255UL},
                                      {0x13L, 0x38L, 0xBCL, 0xBCL},
                                      {0xA7L, 0xA7L, 251UL, 255UL},
                                      {5UL, 0x21L, 1UL, 255UL},
                                      {1UL, 255UL, 0x13L, 1UL}}};
          int i, j, k;
          return l_1790[0][0][1];
        }
      }
    }
  }
  l_1101 |=
      (g_283[3] ^=
       ((((safe_sub_func_int8_t_s_s(
              (safe_sub_func_int8_t_s_s(p_42, 0x1BL)),
              (safe_div_func_int32_t_s_s(
                  (((((((safe_lshift_func_int16_t_s_s(g_1260, 12)) >=
                        (((g_153[3] = (!(
                               p_41 &&
                               (((safe_div_func_int16_t_s_s(
                                     g_5,
                                     (p_40 = (safe_mod_func_int8_t_s_s(
                                          (((((((safe_rshift_func_int16_t_s_u(
                                                    (((safe_add_func_int8_t_s_s(
                                                          ((((safe_unary_minus_func_int8_t_s(
                                                                 g_5)) ==
                                                             (safe_lshift_func_uint8_t_u_s(
                                                                 (safe_unary_minus_func_int32_t_s(
                                                                     g_1441)),
                                                                 7))) &
                                                            ((safe_rshift_func_uint16_t_u_u(
                                                                 (1L ^ 0UL),
                                                                 13)) >
                                                             l_1544)) |
                                                           l_1146),
                                                          g_378[7])) ^
                                                      0xD77BL),
                                                     g_104),
                                                    2)) > g_293[0]),
                                               g_1441),
                                              l_1152[7]) ^
                                             l_1557),
                                            p_39) <= l_1813),
                                          g_1462))))),
                                 g_592) &
                                g_212[5][0][2])))) == g_182[0]) > p_41)),
                       g_74) ||
                      l_1150) < p_39) == p_41) < l_1090),
                  p_42)))) ^
          g_335[5]) ||
         l_1080),
        l_1814[2]));
  return l_1101;
}

static int16_t func_45(int8_t p_46) {
  uint32_t l_53 = 4UL;
  int32_t l_54 = 0x82B3F54CL;
  int32_t l_55 = 8L;
  int32_t l_56 = 9L;
  int32_t l_57 = 0x33AED5EBL;
  int32_t l_72[8] = {(-1L), (-1L), (-1L), (-1L), (-1L), (-1L), (-1L), (-1L)};
  int32_t l_970 = 0xBFDBC38DL;
  int32_t l_1056 = (-6L);
  uint32_t l_1071 = 4294967295UL;
  int i;
  if ((safe_sub_func_uint16_t_u_u(
          (safe_add_func_int32_t_s_s(
              g_26[1][2],
              (l_72[2] = (safe_add_func_int16_t_s_s(
                   l_53,
                   func_18(
                       ((l_57 = (l_56 &= (l_55 = (l_54 = l_53)))) >
                        ((((safe_rshift_func_uint16_t_u_u(
                               (!(g_5 <=
                                  (l_72[3] =
                                       ((safe_add_func_uint32_t_u_u(
                                            (func_62(
                                                 l_53,
                                                 (safe_add_func_int16_t_s_s(
                                                     l_53, (1UL == 255UL))),
                                                 (safe_add_func_int32_t_s_s(
                                                     (l_72[1] =
                                                          (safe_add_func_int8_t_s_s(
                                                              1L, (-10L)))),
                                                     g_5))) < p_46),
                                            g_255)),
                                        1UL)))),
                               l_970)) != l_970) != p_46),
                         65534UL)),
                       g_378[6], g_5, p_46)))))),
          g_5))) {
    int32_t l_995 = (-4L);
    int32_t l_1013 = 0x9C6B2016L;
    for (g_104 = 0; (g_104 == 25); ++g_104) {
      uint8_t l_983[1];
      int32_t l_994 = (-8L);
      int32_t l_996 = 0xC05D00E3L;
      int i;

      if (((safe_rshift_func_int16_t_s_s(
               ((((safe_add_func_uint8_t_u_u(
                      ((l_996 =
                            (((g_293[3], (-4L)) |
                              ((safe_div_func_uint16_t_u_u(
                                   (--g_335[1]),
                                   (l_56 =
                                        ((safe_div_func_uint16_t_u_u(
                                             65530UL,
                                             (((l_55 &= l_983[0]),
                                               (safe_rshift_func_uint8_t_u_s(
                                                   (safe_add_func_int16_t_s_s(
                                                       (((safe_div_func_uint32_t_u_u(
                                                             (safe_rshift_func_uint8_t_u_u(
                                                                 (p_46 &
                                                                  (safe_add_func_int32_t_s_s(
                                                                      p_46,
                                                                      ((-2L) ||
                                                                       ((l_994 =
                                                                             (l_72[1] ^=
                                                                              ((1L ||
                                                                                65528UL) |
                                                                               p_46))) &
                                                                        p_46))))),
                                                                 p_46)),
                                                             1L)) >= p_46) |
                                                        p_46),
                                                       l_55)),
                                                   4))) ||
                                              p_46))) ||
                                         l_995)))) ^
                               65533UL)) < l_995)) == 0x3FL),
                      g_283[3])) &&
                  l_983[0]) ||
                 0xE855L) == g_153[2]),
               0)) <= 0x4DL)) {
        uint32_t l_1014[7];
        int32_t l_1048[7][3] = {{0x758EFABEL, (-9L), 0x758EFABEL},
                                {0x758EFABEL, (-9L), 0x758EFABEL},
                                {0x758EFABEL, (-9L), 0x758EFABEL},
                                {0x758EFABEL, (-9L), 0x758EFABEL},
                                {0x758EFABEL, (-9L), 0x758EFABEL},
                                {0x758EFABEL, (-9L), 0x758EFABEL},
                                {0x758EFABEL, (-9L), 0x758EFABEL}};
        int i, j;
        for (i = 0; i < 7; i++)
          ;

        if ((safe_sub_func_uint16_t_u_u(
                (safe_add_func_int32_t_s_s(
                    g_26[1][2],
                    (l_72[2] = (safe_add_func_int16_t_s_s(
                         l_53,
                         func_18(
                             ((l_57 = (l_56 &= (l_55 = (l_54 = l_53)))) >
                              ((((safe_rshift_func_uint16_t_u_u(
                                     (!(g_5 <=
                                        (l_72[3] =
                                             ((safe_add_func_uint32_t_u_u(
                                                  (func_62(
                                                       l_53,
                                                       (safe_add_func_int16_t_s_s(
                                                           l_53,
                                                           (1UL == 255UL))),
                                                       (safe_add_func_int32_t_s_s(
                                                           (l_72[1] =
                                                                (safe_add_func_int8_t_s_s(
                                                                    1L,
                                                                    (-10L)))),
                                                           g_5))) < p_46),
                                                  g_255)),
                                              1UL)))),
                                     l_970)) != l_970) != p_46),
                               65534UL)),
                             g_378[6], g_5, p_46)))))),
                g_5))) {
          int32_t l_995 = (-4L);
          int32_t l_1013 = 0x9C6B2016L;
          for (g_104 = 0; (g_104 == 25); ++g_104) {
            uint8_t l_983[1];
            int32_t l_994 = (-8L);
            int32_t l_996 = 0xC05D00E3L;
            int i;
            for (i = 0; i < 1; i++)
              l_983[i] = 1UL;
            if (((safe_rshift_func_int16_t_s_s(
                     ((((safe_add_func_uint8_t_u_u(
                            ((l_996 =
                                  (((g_293[3], (-4L)) |
                                    ((safe_div_func_uint16_t_u_u(
                                         (--g_335[1]),
                                         (l_56 =
                                              ((safe_div_func_uint16_t_u_u(
                                                   65530UL,
                                                   (((l_55 &= l_983[0]),
                                                     (safe_rshift_func_uint8_t_u_s(
                                                         (safe_add_func_int16_t_s_s(
                                                             (((safe_div_func_uint32_t_u_u(
                                                                   (safe_rshift_func_uint8_t_u_u(
                                                                       (p_46 &
                                                                        (safe_add_func_int32_t_s_s(
                                                                            p_46,
                                                                            ((-2L) ||
                                                                             ((l_994 =
                                                                                   (l_72[1] ^=
                                                                                    ((1L ||
                                                                                      65528UL) |
                                                                                     p_46))) &
                                                                              p_46))))),
                                                                       p_46)),
                                                                   1L)) >=
                                                               p_46) |
                                                              p_46),
                                                             l_55)),
                                                         4))) ||
                                                    p_46))) ||
                                               l_995)))) ^
                                     65533UL)) < l_995)) == 0x3FL),
                            g_283[3])) &&
                        l_983[0]) ||
                       0xE855L) == g_153[2]),
                     0)) <= 0x4DL)) {
              uint32_t l_1014[7];
              int32_t l_1048[7][3] = {{0x758EFABEL, (-9L), 0x758EFABEL},
                                      {0x758EFABEL, (-9L), 0x758EFABEL},
                                      {0x758EFABEL, (-9L), 0x758EFABEL},
                                      {0x758EFABEL, (-9L), 0x758EFABEL},
                                      {0x758EFABEL, (-9L), 0x758EFABEL},
                                      {0x758EFABEL, (-9L), 0x758EFABEL},
                                      {0x758EFABEL, (-9L), 0x758EFABEL}};
              int i, j;
              for (i = 0; i < 7; i++)
                l_1014[i] = 2UL;
              g_283[0] =
                  (((g_140,
                     (safe_mod_func_uint32_t_u_u(
                         (safe_sub_func_uint8_t_u_u(
                             ((g_466[0] = 0x2DL) >=
                              ((safe_div_func_int16_t_s_s(
                                   (safe_mod_func_int32_t_s_s(
                                       (((g_283[3],
                                          ((safe_mod_func_int16_t_s_s(
                                               (0L &
                                                ((((((((l_994 = g_378[6]) >=
                                                       (safe_div_func_int16_t_s_s(
                                                           l_995,
                                                           (((l_1014[3] =
                                                                  (((l_1013 = (safe_sub_func_int32_t_s_s(
                                                                         (safe_add_func_uint8_t_u_u(
                                                                             ((l_996 ^=
                                                                               (1L <=
                                                                                ((g_335
                                                                                      [5] &&
                                                                                  g_258) <
                                                                                 p_46))) ||
                                                                              0x03A5L),
                                                                             0x2CL)),
                                                                         g_238))) ||
                                                                    1UL) &&
                                                                   3UL)) < 5L) |
                                                            p_46)))) &&
                                                      0x9DF6L),
                                                     0xC84458C2L),
                                                    0x9C98A0F6L) < 1UL) >=
                                                  g_378[2]) < 1UL)),
                                               0xD779L)) != 0x473AL)) &&
                                         0xB2L) <= (-2L)),
                                       p_46)),
                                   p_46)) ^
                               p_46)),
                             l_54)),
                         g_26[0][3]))) &
                    p_46) >= g_86);
              for (g_181 = 23; (g_181 > (-22)); g_181--) {
                uint16_t l_1044 = 65528UL;
                for (g_258 = 21; (g_258 >= 49);
                     g_258 = safe_add_func_uint8_t_u_u(g_258, 1)) {
                  int16_t l_1045 = (-5L);
                  int32_t l_1046 = (-1L);
     l_1048
       [1]
       [1]
       =
       (l_996
        =
        (g_1047
  ^=
  (g_153
   [7]
   =
   ((safe_mod_func_uint8_t_u_u (((p_46 && ((safe_rshift_func_uint8_t_u_u (g_212[5][0][2], (safe_sub_func_uint8_t_u_u ((((safe_rshift_func_int16_t_s_s ((safe_lshift_func_int16_t_s_s ((safe_mod_func_uint16_t_u_u ((((((g_734 ^= (((p_46 | (safe_div_func_int32_t_s_s ((g_283[6] = 0x14DFF13BL), (((safe_mod_func_uint8_t_u_u (0x1AL, (l_1045 = ((safe_sub_func_uint16_t_u_u (((((safe_sub_func_int32_t_s_s ((p_46 >= (((safe_div_func_uint8_t_u_u ((((l_994 = (safe_unary_minus_func_uint32_t_u ((safe_mod_func_uint16_t_u_u ((0xED06L == g_153[0]), l_1044))))), l_1044) > g_293[3]), g_153[3])) | p_46) ^ g_255)), p_46)) <= 0xF5L) < g_466[3]) | p_46), p_46)) & l_1044)))) < g_182[6]) && p_46)))) == g_293[0]) > p_46)) || l_1045) != l_1046), l_1014[6]), g_147), p_46)), l_57)), l_1046)) && 0UL) != l_983[0]), p_46)))) <= p_46)) == p_46), g_335[5])) && g_182[0]))));
     g_283[4] = 0L;
                }
              }
            } else {
              return g_153[0];
            }
          }
        } else {
          uint32_t l_1055 = 0xB6E21F33L;
          int32_t l_1057[9] = {0x7C388A25L, 0x7C388A25L, 0x7C388A25L,
                               0x7C388A25L, 0x7C388A25L, 0x7C388A25L,
                               0x7C388A25L, 0x7C388A25L, 0x7C388A25L};
          int i;
          if ((((((g_140 = (9L || ((l_57 = (g_438 = 255UL)) | l_54))) ^
                  (l_1056 =
                       ((g_181 &&
                         ((g_283[3] ^=
                           (l_1055 =
                                (g_258,
                                 ((((((((safe_lshift_func_uint16_t_u_s(l_72[1],
                                                                       9)) &
                                        0x4C5148FDL),
                                       ((safe_add_func_uint16_t_u_u(
                                            g_212[0][0][6],
                                            ((safe_rshift_func_int8_t_s_s(
                                                 p_46, 0)) >= g_86))) |
                                        0x19C7L)) == p_46) == l_970) < g_74),
                                   p_46),
                                  l_970)))) &
                          p_46)) > 0xCC9CL))) == g_466[0]) > 0x9219L),
               p_46)) {
            uint32_t l_1058 = 0xFC481CBDL;
            int32_t l_1073 = 1L;
            for (g_238 = 0; (g_238 <= 7); g_238 += 1) {
              uint8_t l_1072 = 0x7AL;
              --l_1058;
              for (g_140 = 0; (g_140 <= 7); g_140 += 1) {
                int i;
                l_1073 =
                    (5L !=
                     ((-2L) <=
                      (safe_sub_func_uint32_t_u_u(
                          (((l_1072 &= (safe_lshift_func_int16_t_s_u(
                                 ((g_378[g_140], 65535UL),
                                  (g_238 |
                                   (safe_sub_func_uint16_t_u_u(
                                       (safe_sub_func_int32_t_s_s(
                                           p_46, (~(safe_div_func_uint8_t_u_u(
                                                     l_1055, l_1071))))),
                                       (0xAAB95725L >= 0x7B8B7BDBL))))),
                                 g_238))) ||
                            l_1072) == g_181),
                          0UL))));
                for (l_53 = 0; (l_53 <= 7); l_53 += 1) {
                  l_1073 ^= p_46;
                  g_153[8] = g_466[1];
                }
                g_153[1] &= l_1057[7];
              }
            }
          } else {
            l_1057[4] = 0xF88F41F3L;
          }
          l_54 |= (safe_rshift_func_int16_t_s_s(l_53, 7));
        }

        for (g_181 = 23; (g_181 > (-22)); g_181--) {
          uint16_t l_1044 = 65528UL;
          for (g_258 = 21; (g_258 >= 49);
               g_258 = safe_add_func_uint8_t_u_u(g_258, 1)) {
            int16_t l_1045 = (-5L);
            int32_t l_1046 = (-1L);
     l_1048
       [1]
       [1]
       =
       (l_996
        =
        (g_1047
  ^=
  (g_153
   [7]
   =
   ((safe_mod_func_uint8_t_u_u (((p_46 && ((safe_rshift_func_uint8_t_u_u (g_212[5][0][2], (safe_sub_func_uint8_t_u_u ((((safe_rshift_func_int16_t_s_s ((safe_lshift_func_int16_t_s_s ((safe_mod_func_uint16_t_u_u ((((((g_734 ^= (((p_46 | (safe_div_func_int32_t_s_s ((g_283[6] = 0x14DFF13BL), (((safe_mod_func_uint8_t_u_u (0x1AL, (l_1045 = ((safe_sub_func_uint16_t_u_u (((((safe_sub_func_int32_t_s_s ((p_46 >= (((safe_div_func_uint8_t_u_u ((((l_994 = (safe_unary_minus_func_uint32_t_u ((safe_mod_func_uint16_t_u_u ((0xED06L == g_153[0]), l_1044))))), l_1044) > g_293[3]), g_153[3])) | p_46) ^ g_255)), p_46)) <= 0xF5L) < g_466[3]) | p_46), p_46)) & l_1044)))) < g_182[6]) && p_46)))) == g_293[0]) > p_46)) || l_1045) != l_1046), l_1014[6]), g_147), p_46)), l_57)), l_1046)) && 0UL) != l_983[0]), p_46)))) <= p_46)) == p_46), g_335[5])) && g_182[0]))));
     g_283[4] = 0L;
          }
        }

      } else {
        return g_153[0];
      }
    }
  } else {
    uint32_t l_1055 = 0xB6E21F33L;
    int32_t l_1057[9] = {0x7C388A25L, 0x7C388A25L, 0x7C388A25L,
                         0x7C388A25L, 0x7C388A25L, 0x7C388A25L,
                         0x7C388A25L, 0x7C388A25L, 0x7C388A25L};
    int i;
    if ((((((g_140 = (9L || ((l_57 = (g_438 = 255UL)) | l_54))) ^
            (l_1056 =
                 ((g_181 &&
                   ((g_283[3] ^=
                     (l_1055 =
                          (g_258,
                           ((((((((safe_lshift_func_uint16_t_u_s(l_72[1], 9)) &
                                  0x4C5148FDL),
                                 ((safe_add_func_uint16_t_u_u(
                                      g_212[0][0][6],
                                      ((safe_rshift_func_int8_t_s_s(p_46, 0)) >=
                                       g_86))) |
                                  0x19C7L)) == p_46) == l_970) < g_74),
                             p_46),
                            l_970)))) &
                    p_46)) > 0xCC9CL))) == g_466[0]) > 0x9219L),
         p_46)) {
      uint32_t l_1058 = 0xFC481CBDL;
      int32_t l_1073 = 1L;
      for (g_238 = 0; (g_238 <= 7); g_238 += 1) {
        uint8_t l_1072 = 0x7AL;

        {
          int32_t l_995 = (-4L);
          int32_t l_1013 = 0x9C6B2016L;
          for (g_104 = 0; (g_104 == 25); ++g_104) {
            uint8_t l_983[1];
            int32_t l_994 = (-8L);
            int32_t l_996 = 0xC05D00E3L;
            int i;
            for (i = 0; i < 1; i++)
              l_983[i] = 1UL;
            if (((safe_rshift_func_int16_t_s_s(
                     ((((safe_add_func_uint8_t_u_u(
                            ((l_996 =
                                  (((g_293[3], (-4L)) |
                                    ((safe_div_func_uint16_t_u_u(
                                         (--g_335[1]),
                                         (l_56 =
                                              ((safe_div_func_uint16_t_u_u(
                                                   65530UL,
                                                   (((l_55 &= l_983[0]),
                                                     (safe_rshift_func_uint8_t_u_s(
                                                         (safe_add_func_int16_t_s_s(
                                                             (((safe_div_func_uint32_t_u_u(
                                                                   (safe_rshift_func_uint8_t_u_u(
                                                                       (p_46 &
                                                                        (safe_add_func_int32_t_s_s(
                                                                            p_46,
                                                                            ((-2L) ||
                                                                             ((l_994 =
                                                                                   (l_72[1] ^=
                                                                                    ((1L ||
                                                                                      65528UL) |
                                                                                     p_46))) &
                                                                              p_46))))),
                                                                       p_46)),
                                                                   1L)) >=
                                                               p_46) |
                                                              p_46),
                                                             l_55)),
                                                         4))) ||
                                                    p_46))) ||
                                               l_995)))) ^
                                     65533UL)) < l_995)) == 0x3FL),
                            g_283[3])) &&
                        l_983[0]) ||
                       0xE855L) == g_153[2]),
                     0)) <= 0x4DL)) {
              uint32_t l_1014[7];
              int32_t l_1048[7][3] = {{0x758EFABEL, (-9L), 0x758EFABEL},
                                      {0x758EFABEL, (-9L), 0x758EFABEL},
                                      {0x758EFABEL, (-9L), 0x758EFABEL},
                                      {0x758EFABEL, (-9L), 0x758EFABEL},
                                      {0x758EFABEL, (-9L), 0x758EFABEL},
                                      {0x758EFABEL, (-9L), 0x758EFABEL},
                                      {0x758EFABEL, (-9L), 0x758EFABEL}};
              int i, j;
              for (i = 0; i < 7; i++)
                l_1014[i] = 2UL;
              g_283[0] =
                  (((g_140,
                     (safe_mod_func_uint32_t_u_u(
                         (safe_sub_func_uint8_t_u_u(
                             ((g_466[0] = 0x2DL) >=
                              ((safe_div_func_int16_t_s_s(
                                   (safe_mod_func_int32_t_s_s(
                                       (((g_283[3],
                                          ((safe_mod_func_int16_t_s_s(
                                               (0L &
                                                ((((((((l_994 = g_378[6]) >=
                                                       (safe_div_func_int16_t_s_s(
                                                           l_995,
                                                           (((l_1014[3] =
                                                                  (((l_1013 = (safe_sub_func_int32_t_s_s(
                                                                         (safe_add_func_uint8_t_u_u(
                                                                             ((l_996 ^=
                                                                               (1L <=
                                                                                ((g_335
                                                                                      [5] &&
                                                                                  g_258) <
                                                                                 p_46))) ||
                                                                              0x03A5L),
                                                                             0x2CL)),
                                                                         g_238))) ||
                                                                    1UL) &&
                                                                   3UL)) < 5L) |
                                                            p_46)))) &&
                                                      0x9DF6L),
                                                     0xC84458C2L),
                                                    0x9C98A0F6L) < 1UL) >=
                                                  g_378[2]) < 1UL)),
                                               0xD779L)) != 0x473AL)) &&
                                         0xB2L) <= (-2L)),
                                       p_46)),
                                   p_46)) ^
                               p_46)),
                             l_54)),
                         g_26[0][3]))) &
                    p_46) >= g_86);
              for (g_181 = 23; (g_181 > (-22)); g_181--) {
                uint16_t l_1044 = 65528UL;
                for (g_258 = 21; (g_258 >= 49);
                     g_258 = safe_add_func_uint8_t_u_u(g_258, 1)) {
                  int16_t l_1045 = (-5L);
                  int32_t l_1046 = (-1L);
     l_1048
       [1]
       [1]
       =
       (l_996
        =
        (g_1047
  ^=
  (g_153
   [7]
   =
   ((safe_mod_func_uint8_t_u_u (((p_46 && ((safe_rshift_func_uint8_t_u_u (g_212[5][0][2], (safe_sub_func_uint8_t_u_u ((((safe_rshift_func_int16_t_s_s ((safe_lshift_func_int16_t_s_s ((safe_mod_func_uint16_t_u_u ((((((g_734 ^= (((p_46 | (safe_div_func_int32_t_s_s ((g_283[6] = 0x14DFF13BL), (((safe_mod_func_uint8_t_u_u (0x1AL, (l_1045 = ((safe_sub_func_uint16_t_u_u (((((safe_sub_func_int32_t_s_s ((p_46 >= (((safe_div_func_uint8_t_u_u ((((l_994 = (safe_unary_minus_func_uint32_t_u ((safe_mod_func_uint16_t_u_u ((0xED06L == g_153[0]), l_1044))))), l_1044) > g_293[3]), g_153[3])) | p_46) ^ g_255)), p_46)) <= 0xF5L) < g_466[3]) | p_46), p_46)) & l_1044)))) < g_182[6]) && p_46)))) == g_293[0]) > p_46)) || l_1045) != l_1046), l_1014[6]), g_147), p_46)), l_57)), l_1046)) && 0UL) != l_983[0]), p_46)))) <= p_46)) == p_46), g_335[5])) && g_182[0]))));
     g_283[4] = 0L;
                }
              }
            } else {
              return g_153[0];
            }
          }
        }

        for (g_140 = 0; (g_140 <= 7); g_140 += 1) {
          int i;
          l_1073 =
              (5L !=
               ((-2L) <=
                (safe_sub_func_uint32_t_u_u(
                    (((l_1072 &= (safe_lshift_func_int16_t_s_u(
                           ((g_378[g_140], 65535UL),
                            (g_238 | (safe_sub_func_uint16_t_u_u(
                                         (safe_sub_func_int32_t_s_s(
                                             p_46, (~(safe_div_func_uint8_t_u_u(
                                                       l_1055, l_1071))))),
                                         (0xAAB95725L >= 0x7B8B7BDBL))))),
                           g_238))) ||
                      l_1072) == g_181),
                    0UL))));
          for (l_53 = 0; (l_53 <= 7); l_53 += 1) {
            l_1073 ^= p_46;
            g_153[8] = g_466[1];
          }
          g_153[1] &= l_1057[7];
        }
      }
      {
        uint32_t l_1058 = 0xFC481CBDL;
        int32_t l_1073 = 1L;
        for (g_238 = 0; (g_238 <= 7); g_238 += 1) {
          uint8_t l_1072 = 0x7AL;
          --l_1058;
          for (g_140 = 0; (g_140 <= 7); g_140 += 1) {
            int i;
            l_1073 =
                (5L != ((-2L) <=
                        (safe_sub_func_uint32_t_u_u(
                            (((l_1072 &= (safe_lshift_func_int16_t_s_u(
                                   ((g_378[g_140], 65535UL),
                                    (g_238 |
                                     (safe_sub_func_uint16_t_u_u(
                                         (safe_sub_func_int32_t_s_s(
                                             p_46, (~(safe_div_func_uint8_t_u_u(
                                                       l_1055, l_1071))))),
                                         (0xAAB95725L >= 0x7B8B7BDBL))))),
                                   g_238))) ||
                              l_1072) == g_181),
                            0UL))));
            for (l_53 = 0; (l_53 <= 7); l_53 += 1) {
              l_1073 ^= p_46;
              g_153[8] = g_466[1];
            }
            g_153[1] &= l_1057[7];
          }
        }
      }

    } else {
    }
    if ((((((g_140 = (9L || ((l_57 = (g_438 = 255UL)) | l_54))) ^
            (l_1056 =
                 ((g_181 &&
                   ((g_283[3] ^=
                     (l_1055 =
                          (g_258,
                           ((((((((safe_lshift_func_uint16_t_u_s(l_72[1], 9)) &
                                  0x4C5148FDL),
                                 ((safe_add_func_uint16_t_u_u(
                                      g_212[0][0][6],
                                      ((safe_rshift_func_int8_t_s_s(p_46, 0)) >=
                                       g_86))) |
                                  0x19C7L)) == p_46) == l_970) < g_74),
                             p_46),
                            l_970)))) &
                    p_46)) > 0xCC9CL))) == g_466[0]) > 0x9219L),
         p_46)) {
      uint32_t l_1058 = 0xFC481CBDL;
      int32_t l_1073 = 1L;
      for (g_238 = 0; (g_238 <= 7); g_238 += 1) {
        uint8_t l_1072 = 0x7AL;
        --l_1058;
        for (g_140 = 0; (g_140 <= 7); g_140 += 1) {
          int i;
          l_1073 =
              (5L !=
               ((-2L) <=
                (safe_sub_func_uint32_t_u_u(
                    (((l_1072 &= (safe_lshift_func_int16_t_s_u(
                           ((g_378[g_140], 65535UL),
                            (g_238 | (safe_sub_func_uint16_t_u_u(
                                         (safe_sub_func_int32_t_s_s(
                                             p_46, (~(safe_div_func_uint8_t_u_u(
                                                       l_1055, l_1071))))),
                                         (0xAAB95725L >= 0x7B8B7BDBL))))),
                           g_238))) ||
                      l_1072) == g_181),
                    0UL))));
          for (l_53 = 0; (l_53 <= 7); l_53 += 1) {
            l_1073 ^= p_46;
            g_153[8] = g_466[1];
          }
          g_153[1] &= l_1057[7];
        }
      }
    } else {
      l_1057[4] = 0xF88F41F3L;
    }

    l_54 |= (safe_rshift_func_int16_t_s_s(l_53, 7));
  }
  return p_46;
}

static uint16_t func_62(int32_t p_63, uint32_t p_64, uint32_t p_65) {
  uint16_t l_73[6][6] = {{0UL, 0x49CFL, 3UL, 65532UL, 0x49CFL, 65532UL},
                         {0UL, 1UL, 0UL, 65532UL, 1UL, 3UL},
                         {0UL, 1UL, 65532UL, 65532UL, 1UL, 0UL},
                         {0UL, 0x49CFL, 3UL, 65532UL, 0x49CFL, 65532UL},
                         {0UL, 1UL, 0UL, 65532UL, 1UL, 3UL},
                         {0UL, 1UL, 65532UL, 65532UL, 1UL, 0UL}};
  int32_t l_715[9][4] = {{0xBC19C81CL, 0x2A91BA2BL, 0xBC19C81CL, 0x2A91BA2BL},
                         {0xBC19C81CL, 0x2A91BA2BL, 0xBC19C81CL, 0x2A91BA2BL},
                         {0xBC19C81CL, 0x2A91BA2BL, 0xBC19C81CL, 0x2A91BA2BL},
                         {0xBC19C81CL, 0x2A91BA2BL, 0xBC19C81CL, 0x2A91BA2BL},
                         {0xBC19C81CL, 0x2A91BA2BL, 0xBC19C81CL, 0x2A91BA2BL},
                         {0xBC19C81CL, 0x2A91BA2BL, 0xBC19C81CL, 0x2A91BA2BL},
                         {0xBC19C81CL, 0x2A91BA2BL, 0xBC19C81CL, 0x2A91BA2BL},
                         {0xBC19C81CL, 0x2A91BA2BL, 0xBC19C81CL, 0x2A91BA2BL},
                         {0xBC19C81CL, 0x2A91BA2BL, 0xBC19C81CL, 0x2A91BA2BL}};
  int32_t l_738 = (-2L);
  int32_t l_949 = (-1L);
  int32_t l_960 = 0xC9B99492L;
  uint8_t l_963 = 1UL;
  uint32_t l_964[2];
  int8_t l_969[6];
  int i, j;
  for (i = 0; i < 2; i++)
    l_964[i] = 4294967286UL;
  for (i = 0; i < 6; i++)
    l_969[i] = 0x96L;
  for (p_65 = 0; (p_65 <= 5); p_65 += 1) {
    uint32_t l_714[7][7] = {
        {4294967286UL, 0UL, 4294967286UL, 0UL, 4294967286UL, 0UL, 4294967286UL},
        {4294967292UL, 4294967292UL, 4294967292UL, 4294967292UL, 4294967292UL,
         4294967292UL, 4294967292UL},
        {4294967286UL, 0UL, 4294967286UL, 0UL, 4294967286UL, 0UL, 4294967286UL},
        {4294967292UL, 4294967292UL, 4294967292UL, 4294967292UL, 4294967292UL,
         4294967292UL, 4294967292UL},
        {4294967286UL, 0UL, 4294967286UL, 0UL, 4294967286UL, 0UL, 4294967286UL},
        {4294967292UL, 4294967292UL, 4294967292UL, 4294967292UL, 4294967292UL,
         4294967292UL, 4294967292UL},
        {4294967286UL, 0UL, 4294967286UL, 0UL, 4294967286UL, 0UL,
         4294967286UL}};
    int32_t l_716 = 1L;
    uint8_t l_731[1][1][5] = {{{9UL, 9UL, 9UL, 9UL, 9UL}}};
    int16_t l_735 = 0x8F8BL;
    uint16_t l_765[8] = {0xAAE8L, 0x3DC2L, 0xAAE8L, 0xAAE8L,
                         0x3DC2L, 0xAAE8L, 0xAAE8L, 0x3DC2L};
    int32_t l_767 = 0x73560EADL;
    int i, j, k;
    g_74 = (p_63 = g_26[1][1]);
    for (p_63 = 5; (p_63 >= 0); p_63 -= 1) {
      int32_t l_717 = (-1L);
      int i, j;
      l_717 =
          ((safe_add_func_int16_t_s_s(
               l_73[p_63][p_63],
               (l_716 =
                    (g_26[1][3] &&
                     ((l_715[0][2] =
                           (((func_77(l_73[p_63][p_63]) != 0x5F08L) !=
                             (((func_80(l_73[5][3]) & 0xD9B2L) <=
                               (safe_sub_func_int16_t_s_s(
                                   ((safe_rshift_func_int8_t_s_u(
                                        ((safe_lshift_func_uint8_t_u_s(
                                             (safe_div_func_uint32_t_u_u(
                                                 (((safe_add_func_uint32_t_u_u(
                                                       (+(safe_rshift_func_int8_t_s_s(
                                                           p_64, g_592))),
                                                       l_714[5][5])) <=
                                                   0xBF313294L) &&
                                                  0xD57C685CL),
                                                 0x5D350F5FL)),
                                             p_63)),
                                         0x72L),
                                        p_65)) < 0UL),
                                   0xCE13L))),
                              0UL)) ^
                            l_73[2][1])) == g_592))))) &
           g_378[6]);
    }
    if ((~(g_293[3],
           (safe_sub_func_int8_t_s_s(
               (g_466[0] ^= ((6L > l_715[0][2]),
                             (((0xA7L ^ (0xF1L < (safe_rshift_func_int16_t_s_s(
                                                     g_258, l_715[0][2])))) ||
                               (((l_715[4][1] = (safe_rshift_func_uint8_t_u_u(
                                      (g_104 & (p_64 = l_715[0][2])), 4))) ==
                                 0xC29AADE5L) != 0xD7L)) != g_395))),
               g_5))))) {
      if (p_65)
        ;

    } else {
      return g_258;
    }
    l_716 =
        ((safe_rshift_func_int16_t_s_u(
             ((((p_64 |= 0x00CB7D0DL),
                (l_715[0][2] = (safe_unary_minus_func_uint32_t_u(
                     (((((safe_add_func_uint8_t_u_u(
                             (g_335[5] ==
                              (((g_438 = (((0x0E04L < (g_283[3] < 0x9417L)) &&
                                           (~l_731[0][0][0])) ^
                                          g_104)) ^
                                ((l_73[1][4] | (safe_sub_func_uint32_t_u_u(
                                                   l_715[0][2], g_734))) <
                                 g_119)),
                               0UL)),
                             (-10L))),
                         0x44L) > 0x0CL) |
                       l_735),
                      g_466[0]))))) &&
               g_283[1]) ||
              p_63),
             g_258)),
         p_65);
    for (g_140 = 1; (g_140 <= 5); g_140 += 1) {
      uint32_t l_743 = 0x7DE7D91DL;
      int32_t l_766 = 3L;
      uint8_t l_768 = 254UL;
      int32_t l_801 = 0L;
      int32_t l_803 = 0x72FA4EF3L;
      uint32_t l_837[1][1];
      uint16_t l_852 = 5UL;
      int16_t l_877 = 0x9C68L;
      int16_t l_892 = (-1L);
      int i, j;
      for (i = 0; i < 1; i++) {
        for (j = 0; j < 1; j++)
          l_837[i][j] = 0x6BA0ABD9L;
      }
      g_153[0] &= g_466[0];
      if ((0UL >= (((safe_mod_func_int16_t_s_s ((((((g_335[4] > (l_738 && ((safe_div_func_uint8_t_u_u (((l_766 = ((l_767 &= ((+(safe_add_func_uint16_t_u_u (((((((l_743 < (safe_lshift_func_uint16_t_u_s ((l_716 = (((safe_sub_func_int16_t_s_s (((0xACD95A8AL >= (((safe_unary_minus_func_int8_t_s ((safe_div_func_uint16_t_u_u ((((safe_div_func_uint16_t_u_u ((((g_104 ^= (safe_div_func_uint16_t_u_u (l_73[4][1], 6L))) != (((safe_add_func_int32_t_s_s ((((safe_sub_func_uint32_t_u_u ((safe_add_func_int16_t_s_s ((g_734 = ((safe_sub_func_int8_t_s_s ((safe_rshift_func_uint16_t_u_u (((l_73[2][1], (g_119 != g_153[0])), g_335[5]), g_119)), l_743)) > l_765[5])), p_65)), 1UL)), 0xEAB9L) <= p_65), g_592)) >= l_738) <= 0xB4B7CA50L)) && l_73[2][5]), g_283[3])) > p_63) & p_64), g_119)))) || 0x68L) || 0x458AL)), p_63), l_738)) == 0L), l_766)), g_86))) >= l_735) ^ 5L) & g_466[0]) >= l_738) <= 0x6D9DL), g_238))) | p_63)) > 4294967293UL)), 255UL), 0x52L)), 0x5BD3E2EBL))) > 0UL), l_766) < l_768) != g_293[2]), g_74)) <= g_182[0]) <= p_65)))
      {
        uint8_t l_798 = 0xA6L;
        int32_t l_800 = 0xBCEC7AB9L;

        {
          uint32_t l_714[7][7] = {
              {4294967286UL, 0UL, 4294967286UL, 0UL, 4294967286UL, 0UL,
               4294967286UL},
              {4294967292UL, 4294967292UL, 4294967292UL, 4294967292UL,
               4294967292UL, 4294967292UL, 4294967292UL},
              {4294967286UL, 0UL, 4294967286UL, 0UL, 4294967286UL, 0UL,
               4294967286UL},
              {4294967292UL, 4294967292UL, 4294967292UL, 4294967292UL,
               4294967292UL, 4294967292UL, 4294967292UL},
              {4294967286UL, 0UL, 4294967286UL, 0UL, 4294967286UL, 0UL,
               4294967286UL},
              {4294967292UL, 4294967292UL, 4294967292UL, 4294967292UL,
               4294967292UL, 4294967292UL, 4294967292UL},
              {4294967286UL, 0UL, 4294967286UL, 0UL, 4294967286UL, 0UL,
               4294967286UL}};
          int32_t l_716 = 1L;
          uint8_t l_731[1][1][5] = {{{9UL, 9UL, 9UL, 9UL, 9UL}}};
          int16_t l_735 = 0x8F8BL;
          uint16_t l_765[8] = {0xAAE8L, 0x3DC2L, 0xAAE8L, 0xAAE8L,
                               0x3DC2L, 0xAAE8L, 0xAAE8L, 0x3DC2L};
          int32_t l_767 = 0x73560EADL;
          int i, j, k;
          g_74 = (p_63 = g_26[1][1]);
          for (p_63 = 5; (p_63 >= 0); p_63 -= 1) {
            int32_t l_717 = (-1L);
            int i, j;
            l_717 =
                ((safe_add_func_int16_t_s_s(
                     l_73[p_63][p_63],
                     (l_716 =
                          (g_26[1][3] &&
                           ((l_715[0][2] =
                                 (((func_77(l_73[p_63][p_63]) != 0x5F08L) !=
                                   (((func_80(l_73[5][3]) & 0xD9B2L) <=
                                     (safe_sub_func_int16_t_s_s(
                                         ((safe_rshift_func_int8_t_s_u(
                                              ((safe_lshift_func_uint8_t_u_s(
                                                   (safe_div_func_uint32_t_u_u(
                                                       (((safe_add_func_uint32_t_u_u(
                                                             (+(safe_rshift_func_int8_t_s_s(
                                                                 p_64, g_592))),
                                                             l_714[5][5])) <=
                                                         0xBF313294L) &&
                                                        0xD57C685CL),
                                                       0x5D350F5FL)),
                                                   p_63)),
                                               0x72L),
                                              p_65)) < 0UL),
                                         0xCE13L))),
                                    0UL)) ^
                                  l_73[2][1])) == g_592))))) &
                 g_378[6]);
          }
          if ((~(g_293[3],
                 (safe_sub_func_int8_t_s_s(
                     (g_466[0] ^=
                      ((6L > l_715[0][2]),
                       (((0xA7L ^ (0xF1L < (safe_rshift_func_int16_t_s_s(
                                               g_258, l_715[0][2])))) ||
                         (((l_715[4][1] = (safe_rshift_func_uint8_t_u_u(
                                (g_104 & (p_64 = l_715[0][2])), 4))) ==
                           0xC29AADE5L) != 0xD7L)) != g_395))),
                     g_5))))) {
            if (p_65)
              break;
          } else {
            return g_258;
          }
          l_716 =
              ((safe_rshift_func_int16_t_s_u(
                   ((((p_64 |= 0x00CB7D0DL),
                      (l_715[0][2] = (safe_unary_minus_func_uint32_t_u(
                           (((((safe_add_func_uint8_t_u_u(
                                   (g_335[5] ==
                                    (((g_438 =
                                           (((0x0E04L < (g_283[3] < 0x9417L)) &&
                                             (~l_731[0][0][0])) ^
                                            g_104)) ^
                                      ((l_73[1][4] |
                                        (safe_sub_func_uint32_t_u_u(
                                            l_715[0][2], g_734))) < g_119)),
                                     0UL)),
                                   (-10L))),
                               0x44L) > 0x0CL) |
                             l_735),
                            g_466[0]))))) &&
                     g_283[1]) ||
                    p_63),
                   g_258)),
               p_65);
          for (g_140 = 1; (g_140 <= 5); g_140 += 1) {
            uint32_t l_743 = 0x7DE7D91DL;
            int32_t l_766 = 3L;
            uint8_t l_768 = 254UL;
            int32_t l_801 = 0L;
            int32_t l_803 = 0x72FA4EF3L;
            uint32_t l_837[1][1];
            uint16_t l_852 = 5UL;
            int16_t l_877 = 0x9C68L;
            int16_t l_892 = (-1L);
            int i, j;
            for (i = 0; i < 1; i++) {
              for (j = 0; j < 1; j++)
                l_837[i][j] = 0x6BA0ABD9L;
            }
            g_153[0] &= g_466[0];
      if ((0UL >= (((safe_mod_func_int16_t_s_s ((((((g_335[4] > (l_738 && ((safe_div_func_uint8_t_u_u (((l_766 = ((l_767 &= ((+(safe_add_func_uint16_t_u_u (((((((l_743 < (safe_lshift_func_uint16_t_u_s ((l_716 = (((safe_sub_func_int16_t_s_s (((0xACD95A8AL >= (((safe_unary_minus_func_int8_t_s ((safe_div_func_uint16_t_u_u ((((safe_div_func_uint16_t_u_u ((((g_104 ^= (safe_div_func_uint16_t_u_u (l_73[4][1], 6L))) != (((safe_add_func_int32_t_s_s ((((safe_sub_func_uint32_t_u_u ((safe_add_func_int16_t_s_s ((g_734 = ((safe_sub_func_int8_t_s_s ((safe_rshift_func_uint16_t_u_u (((l_73[2][1], (g_119 != g_153[0])), g_335[5]), g_119)), l_743)) > l_765[5])), p_65)), 1UL)), 0xEAB9L) <= p_65), g_592)) >= l_738) <= 0xB4B7CA50L)) && l_73[2][5]), g_283[3])) > p_63) & p_64), g_119)))) || 0x68L) || 0x458AL)), p_63), l_738)) == 0L), l_766)), g_86))) >= l_735) ^ 5L) & g_466[0]) >= l_738) <= 0x6D9DL), g_238))) | p_63)) > 4294967293UL)), 255UL), 0x52L)), 0x5BD3E2EBL))) > 0UL), l_766) < l_768) != g_293[2]), g_74)) <= g_182[0]) <= p_65)))
      {
        uint8_t l_798 = 0xA6L;
        int32_t l_800 = 0xBCEC7AB9L;
        for (l_735 = (-28); (l_735 == 14); l_735++) {
          if (g_283[3])
            break;
        }
        if (l_767)
          break;
        for (l_766 = (-26); (l_766 >= 7);
             l_766 = safe_add_func_uint32_t_u_u(l_766, 2)) {
          int32_t l_775 = 0xDA8A8BE9L;
          int32_t l_802[5][8][2] = {{{0x83E67752L, 0x9CA8A1FAL},
                                     {0x48DBEEBAL, 0xDACCA481L},
                                     {0x83E67752L, 0x69167366L},
                                     {1L, 0x69167366L},
                                     {0x83E67752L, 0xDACCA481L},
                                     {0x48DBEEBAL, 0x9CA8A1FAL},
                                     {0x83E67752L, 0x95D906CAL},
                                     {1L, 0x95D906CAL}},
                                    {{0x83E67752L, 0x9CA8A1FAL},
                                     {0x48DBEEBAL, 0xDACCA481L},
                                     {0x83E67752L, 0x69167366L},
                                     {1L, 0x69167366L},
                                     {0x83E67752L, 0xDACCA481L},
                                     {0x48DBEEBAL, 0x9CA8A1FAL},
                                     {0x83E67752L, 0x95D906CAL},
                                     {1L, 0x95D906CAL}},
                                    {{0x83E67752L, 0x9CA8A1FAL},
                                     {0x48DBEEBAL, 0xDACCA481L},
                                     {0x83E67752L, 0x69167366L},
                                     {1L, 0x69167366L},
                                     {0x83E67752L, 0xDACCA481L},
                                     {0x48DBEEBAL, 0x9CA8A1FAL},
                                     {0x83E67752L, 0x95D906CAL},
                                     {1L, 0x95D906CAL}},
                                    {{0x83E67752L, 0x9CA8A1FAL},
                                     {0x48DBEEBAL, 0xDACCA481L},
                                     {0x83E67752L, 0x69167366L},
                                     {1L, 0x69167366L},
                                     {0x83E67752L, 0xDACCA481L},
                                     {0x48DBEEBAL, 0x9CA8A1FAL},
                                     {0x83E67752L, 0x95D906CAL},
                                     {1L, 0x95D906CAL}},
                                    {{0x83E67752L, 0x9CA8A1FAL},
                                     {0x48DBEEBAL, 0xDACCA481L},
                                     {0x83E67752L, 0x69167366L},
                                     {1L, 0x69167366L},
                                     {0x83E67752L, 0xDACCA481L},
                                     {0x48DBEEBAL, 0x9CA8A1FAL},
                                     {0x83E67752L, 0x95D906CAL},
                                     {1L, 0x95D906CAL}}};
          int i, j, k;
          for (l_767 = (-19); (l_767 <= (-13)); l_767++) {
            int32_t l_799 = 0xCF4157FAL;
            p_63 = l_775;
            l_801 =
                (((safe_sub_func_int8_t_s_s(
                      (safe_lshift_func_uint8_t_u_u(
                          (((+(safe_add_func_uint16_t_u_u(
                                ((p_63 = (p_64 || 0UL)) >
                                 ((0xF387673EL < 1UL) ==
                                  (l_800 =
                                       (((safe_lshift_func_int8_t_s_u(
                                             ((safe_sub_func_uint8_t_u_u(
                                                  (safe_add_func_uint16_t_u_u(
                                                      (g_119 ==
                                                       ((safe_rshift_func_uint16_t_u_u(
                                                            (safe_sub_func_int8_t_s_s(
                                                                (((safe_div_func_int32_t_s_s(
                                                                      (((safe_rshift_func_uint8_t_u_s(
                                                                            (((safe_lshift_func_int8_t_s_s(
                                                                                  p_65,
                                                                                  (p_64,
                                                                                   g_293
                                                                                       [0]))) &
                                                                              (g_438 &
                                                                               p_64)) !=
                                                                             0x024EC518L),
                                                                            2)) ==
                                                                        p_65) ==
                                                                       (-1L)),
                                                                      p_64)) |
                                                                  0x4AFBL) <
                                                                 0xF378L),
                                                                g_466[4])),
                                                            8)) <= 7L)),
                                                      2L)),
                                                  l_798)) ||
                                              g_734),
                                             p_64)),
                                         l_799) &
                                        p_65)))),
                                0xB819L))) &
                            l_798) <= 6UL),
                          7)),
                      0x85L)),
                  l_768) == g_182[0]);
            if (l_800)
              break;
          }
          p_63 =
              (((0x2B79D30DL < g_74), (++g_293[3])),
               (safe_rshift_func_int8_t_s_s(
                   (safe_add_func_int8_t_s_s(
                       (safe_add_func_uint8_t_u_u(
                           l_767,
                           ((((((safe_lshift_func_int16_t_s_s(
                                    (l_800 = (0xB5L > g_293[0])), 7)) <
                                (!((0L ||
                                    (g_153[0] <
                                     (l_716 |= (safe_rshift_func_uint16_t_u_u(
                                          l_802[3][5][0], 12))))) ||
                                   ((-1L) | g_378[6])))) <= p_65) &
                              4294967295UL) &
                             p_63),
                            0L))),
                       (-6L))),
                   g_74)));
        }
      } else {
        uint16_t l_818 = 65535UL;
        int32_t l_825[7];
        int32_t l_826 = 1L;
        int i;
        for (i = 0; i < 7; i++)
          l_825[i] = 0xC982926AL;
        g_153[3] |= (l_801 = g_293[3]);
        ++l_818;
        l_826 ^= (0x876AL == (safe_div_func_uint8_t_u_u(
                                 (g_293[0] = p_65),
                                 (safe_rshift_func_int16_t_s_u(
                                     (l_738 = (l_801 >= 0xF927L)),
                                     (l_825[3] &= (l_767 = g_378[7])))))));
        if (((safe_mod_func_int8_t_s_s(
                 p_64, (safe_lshift_func_uint8_t_u_u(1UL, 6)))) |
             0L)) {
          g_283[5] ^=
              ((safe_mod_func_uint16_t_u_u(
                   p_65,
                   (safe_div_func_int8_t_s_s(
                       0x07L, (safe_mod_func_int8_t_s_s(
                                  ((l_837[0][0] &&
                                    (safe_sub_func_int32_t_s_s(
                                        (safe_rshift_func_uint8_t_u_u(
                                            (safe_sub_func_uint32_t_u_u(
                                                0UL, (g_212[3][0][7] ^
                                                      (1UL <= (++g_104))))),
                                            g_5)),
                                        ((p_65 ^ ((safe_div_func_int8_t_s_s(
                                                      (-8L), g_86)) |
                                                  g_255)),
                                         g_86)))) <= g_153[0]),
                                  p_65)))))) > 0xBE44L);
          return l_818;
        } else {
          uint8_t l_876 = 0x62L;
          int32_t l_893[3];
          int32_t l_894[10][5] = {
              {1L, 0xFB140EABL, 1L, 0xB8304EABL, 0x75475F90L},
              {0xB5B4717BL, 1L, 0xB5B4717BL, (-10L), (-10L)},
              {1L, 0xFB140EABL, 1L, 0xB8304EABL, 0x75475F90L},
              {0xB5B4717BL, 1L, 0xB5B4717BL, (-10L), (-10L)},
              {1L, 0xFB140EABL, 1L, 0xB8304EABL, 0x75475F90L},
              {0xB5B4717BL, 1L, 0xB5B4717BL, (-10L), (-10L)},
              {1L, 0xFB140EABL, 1L, 0xB8304EABL, 0x75475F90L},
              {0xB5B4717BL, 1L, 0xB5B4717BL, (-10L), (-10L)},
              {1L, 0xFB140EABL, 1L, 0xB8304EABL, 0x75475F90L},
              {0xB5B4717BL, 1L, 0xB5B4717BL, (-10L), (-10L)}};
          int i, j;
          for (i = 0; i < 3; i++)
            l_893[i] = (-9L);
          for (g_119 = 0; (g_119 != (-21)); --g_119) {
            int32_t l_850 = 0x0DE402C1L;
            int32_t l_851[5] = {0xBE7C7E02L, 0xBE7C7E02L, 0xBE7C7E02L,
                                0xBE7C7E02L, 0xBE7C7E02L};
            int i;
            ++l_852;
            if (g_212[2][0][6])
              break;
            l_716 &=
                ((6UL <=
                  (safe_div_func_int8_t_s_s(
                      (+((g_140 ||
                          (0xB81EL !=
                           (safe_lshift_func_int16_t_s_u(
                               (safe_add_func_int16_t_s_s(
                                   l_765[7],
                                   ((safe_rshift_func_uint8_t_u_s(
                                        ((safe_rshift_func_uint16_t_u_s(
                                             ((((safe_unary_minus_func_int8_t_s(
                                                    0x4BL)),
                                                (safe_div_func_uint16_t_u_u(
                                                    (l_715[8][0] =
                                                         (0xDF463D2BL ==
                                                          (((safe_rshift_func_int8_t_s_u(
                                                                (((safe_add_func_int16_t_s_s(
                                                                      p_64,
                                                                      ((~l_851
                                                                            [0]) !=
                                                                       (l_766 =
                                                                            ((safe_add_func_uint16_t_u_u(
                                                                                 l_876,
                                                                                 p_65)),
                                                                             p_65))))) |
                                                                  p_63) &&
                                                                 g_293[0]),
                                                                g_258)) >
                                                            0x3EL) > 0x00L))),
                                                    l_851[2]))) <
                                               4294967286UL) ||
                                              l_826),
                                             9)) >= p_65),
                                        p_63)) ||
                                    l_877))),
                               4)))),
                         p_64)),
                      g_74))),
                 0x42C570C6L);
            l_894[7][2] =
                (l_893[2] ^=
                 (((safe_lshift_func_int8_t_s_u(
                       (safe_sub_func_int16_t_s_s((l_715[0][2] = p_64), g_592)),
                       6)) &&
                   (((-2L) ||
                     (g_283[3] >
                      ((safe_add_func_int16_t_s_s(
                           (~p_64),
                           (((safe_lshift_func_int8_t_s_s(p_64, 6)) >
                             ((safe_mod_func_int16_t_s_s(
                                  ((safe_add_func_uint16_t_u_u(
                                       (((((((l_851[2] &=
                                              ((safe_add_func_int16_t_s_s(
                                                   8L, 0xD195L)) ^
                                               0L)),
                                             p_63) |
                                            l_892) |
                                           p_63),
                                          g_153[5]) > g_293[0]) &
                                        0xDD96C110L),
                                       l_765[0])) < g_182[0]),
                                  65532UL)) >= p_63)) > l_825[5]))),
                       l_765[5]))) <= 0UL)),
                  0L));
          }
   l_801
     &=
     ((l_803 = ((safe_sub_func_int8_t_s_s (((safe_lshift_func_int8_t_s_s ((((+((-1L) == (((safe_div_func_uint8_t_u_u (((((safe_sub_func_int8_t_s_s ((((safe_add_func_int8_t_s_s (p_65, (safe_mod_func_uint32_t_u_u ((p_64 = 4294967295UL), ((((safe_div_func_uint8_t_u_u (p_65, ((((safe_unary_minus_func_uint16_t_u ((((((safe_rshift_func_int8_t_s_s ((p_63 && (((!((l_716 |= ((l_715[8][0] = (g_238 = ((p_63 > (safe_mod_func_uint32_t_u_u (((safe_unary_minus_func_int8_t_s (((safe_add_func_uint16_t_u_u ((safe_rshift_func_int8_t_s_s (p_63, p_65)), ((safe_mod_func_uint8_t_u_u ((l_837[0][0] & l_877), 0xC5L)) && 7UL))), 0xF3L))) < 0x96L), l_731[0][0][4]))) < 0x74L))) <= g_26[1][4])) > p_63)) ^ (-1L)) && g_153[0])), 4)) > g_335[2]) ^ 0x8E3C2910L) >= p_63) <= l_837[0][0]))) & p_63) && p_65), 6L))) < l_826) != l_73[1][2]), 0xD83587F8L))))) < 0UL) ^ l_73[5][2]), l_766)) < 0x91B8L) != l_877) & l_738), p_63)) != l_73[4][2]) != p_65))) | p_65) & p_65), g_283[2])), g_378[6]), 0x65L)), g_86)) | 0x3E4CC660L);
   p_63
     =
     ((g_335[5] = ((safe_mul_func_uint16_t_u_u (g_182[0], ((((0xD2C620E8L <= (safe_sub_func_int8_t_s_s (((safe_mod_func_uint16_t_u_u (((~(safe_rshift_func_int16_t_s_u ((safe_rshift_func_int16_t_s_s ((safe_mod_func_int16_t_s_s ((((5L == ((l_876 > ((p_64 ^ (safe_div_func_int8_t_s_s ((((g_395++) == l_893[2]) <= ((l_738 = ((safe_rshift_func_int16_t_s_u (((l_715[0][2] = (g_181 |= (safe_rshift_func_uint8_t_u_u ((--g_438), (safe_add_func_uint16_t_u_u ((((((g_293[0] >= (safe_add_func_int32_t_s_s (p_64, g_592))) >= g_255) & 1L) > (-1L)) || p_63), p_63)))))), g_153[4]), p_63)) != 0x720CL)) ^ l_893[0])), (-1L)))), 255UL)), l_716)) || 8L) & l_825[2]), p_63)), 13)), 9))) & l_852), g_26[1][3])) >= l_801), g_378[6]))) != l_73[1][5]) && g_293[3]) == 0UL))), l_818)), g_140);
        }
      }
          }
        }

        { return g_258; }

      } else {
        uint16_t l_818 = 65535UL;
        int32_t l_825[7];
        int32_t l_826 = 1L;
        int i;
        for (i = 0; i < 7; i++)
          l_825[i] = 0xC982926AL;
        g_153[3] |= (l_801 = g_293[3]);
        ++l_818;
        l_826 ^= (0x876AL == (safe_div_func_uint8_t_u_u(
                                 (g_293[0] = p_65),
                                 (safe_rshift_func_int16_t_s_u(
                                     (l_738 = (l_801 >= 0xF927L)),
                                     (l_825[3] &= (l_767 = g_378[7])))))));
        if (((safe_mod_func_int8_t_s_s(
                 p_64, (safe_lshift_func_uint8_t_u_u(1UL, 6)))) |
             0L)) {
          g_283[5] ^=
              ((safe_mod_func_uint16_t_u_u(
                   p_65,
                   (safe_div_func_int8_t_s_s(
                       0x07L, (safe_mod_func_int8_t_s_s(
                                  ((l_837[0][0] &&
                                    (safe_sub_func_int32_t_s_s(
                                        (safe_rshift_func_uint8_t_u_u(
                                            (safe_sub_func_uint32_t_u_u(
                                                0UL, (g_212[3][0][7] ^
                                                      (1UL <= (++g_104))))),
                                            g_5)),
                                        ((p_65 ^ ((safe_div_func_int8_t_s_s(
                                                      (-8L), g_86)) |
                                                  g_255)),
                                         g_86)))) <= g_153[0]),
                                  p_65)))))) > 0xBE44L);
          return l_818;
        } else {
          uint8_t l_876 = 0x62L;
          int32_t l_893[3];
          int32_t l_894[10][5] = {
              {1L, 0xFB140EABL, 1L, 0xB8304EABL, 0x75475F90L},
              {0xB5B4717BL, 1L, 0xB5B4717BL, (-10L), (-10L)},
              {1L, 0xFB140EABL, 1L, 0xB8304EABL, 0x75475F90L},
              {0xB5B4717BL, 1L, 0xB5B4717BL, (-10L), (-10L)},
              {1L, 0xFB140EABL, 1L, 0xB8304EABL, 0x75475F90L},
              {0xB5B4717BL, 1L, 0xB5B4717BL, (-10L), (-10L)},
              {1L, 0xFB140EABL, 1L, 0xB8304EABL, 0x75475F90L},
              {0xB5B4717BL, 1L, 0xB5B4717BL, (-10L), (-10L)},
              {1L, 0xFB140EABL, 1L, 0xB8304EABL, 0x75475F90L},
              {0xB5B4717BL, 1L, 0xB5B4717BL, (-10L), (-10L)}};
          int i, j;
          for (i = 0; i < 3; i++)

          {
            ++l_818;
          }

   l_801
     &=
     ((l_803 = ((safe_sub_func_int8_t_s_s (((safe_lshift_func_int8_t_s_s ((((+((-1L) == (((safe_div_func_uint8_t_u_u (((((safe_sub_func_int8_t_s_s ((((safe_add_func_int8_t_s_s (p_65, (safe_mod_func_uint32_t_u_u ((p_64 = 4294967295UL), ((((safe_div_func_uint8_t_u_u (p_65, ((((safe_unary_minus_func_uint16_t_u ((((((safe_rshift_func_int8_t_s_s ((p_63 && (((!((l_716 |= ((l_715[8][0] = (g_238 = ((p_63 > (safe_mod_func_uint32_t_u_u (((safe_unary_minus_func_int8_t_s (((safe_add_func_uint16_t_u_u ((safe_rshift_func_int8_t_s_s (p_63, p_65)), ((safe_mod_func_uint8_t_u_u ((l_837[0][0] & l_877), 0xC5L)) && 7UL))), 0xF3L))) < 0x96L), l_731[0][0][4]))) < 0x74L))) <= g_26[1][4])) > p_63)) ^ (-1L)) && g_153[0])), 4)) > g_335[2]) ^ 0x8E3C2910L) >= p_63) <= l_837[0][0]))) & p_63) && p_65), 6L))) < l_826) != l_73[1][2]), 0xD83587F8L))))) < 0UL) ^ l_73[5][2]), l_766)) < 0x91B8L) != l_877) & l_738), p_63)) != l_73[4][2]) != p_65))) | p_65) & p_65), g_283[2])), g_378[6]), 0x65L)), g_86)) | 0x3E4CC660L);
   p_63
     =
     ((g_335[5] = ((safe_mul_func_uint16_t_u_u (g_182[0], ((((0xD2C620E8L <= (safe_sub_func_int8_t_s_s (((safe_mod_func_uint16_t_u_u (((~(safe_rshift_func_int16_t_s_u ((safe_rshift_func_int16_t_s_s ((safe_mod_func_int16_t_s_s ((((5L == ((l_876 > ((p_64 ^ (safe_div_func_int8_t_s_s ((((g_395++) == l_893[2]) <= ((l_738 = ((safe_rshift_func_int16_t_s_u (((l_715[0][2] = (g_181 |= (safe_rshift_func_uint8_t_u_u ((--g_438), (safe_add_func_uint16_t_u_u ((((((g_293[0] >= (safe_add_func_int32_t_s_s (p_64, g_592))) >= g_255) & 1L) > (-1L)) || p_63), p_63)))))), g_153[4]), p_63)) != 0x720CL)) ^ l_893[0])), (-1L)))), 255UL)), l_716)) || 8L) & l_825[2]), p_63)), 13)), 9))) & l_852), g_26[1][3])) >= l_801), g_378[6]))) != l_73[1][5]) && g_293[3]) == 0UL))), l_818)), g_140);
        }
      }
    }
  }
  g_153[0] |=
      ((safe_rshift_func_int8_t_s_s(
           (l_949 = (l_738 = ((((l_715[0][2] = 0x343FC338L) | l_738) ^ p_64) ^
                              l_738))),
           6)) ^
       ((safe_sub_func_uint32_t_u_u(
            ((p_65 ^ p_65) &
             (l_73[1][2] <=
              (safe_div_func_int8_t_s_s(
                  (safe_mod_func_uint16_t_u_u(p_65, 0xE898L)), g_293[0])))),
            g_182[2])),
        p_65));
  l_738 |=
      ((safe_lshift_func_int8_t_s_s(
           g_283[3],
           ((g_438++) >
            (l_960, ((safe_lshift_func_int8_t_s_s(
                         (((((((l_715[0][2] = g_283[3]) ||
                               ((l_963, l_964[1]) ^
                                (safe_div_func_uint8_t_u_u(
                                    g_182[4], (safe_div_func_uint16_t_u_u(
                                                  65531UL, ((p_65 <= l_969[2]) &
                                                            p_63))))))) ^
                              252UL) > 2L) > p_64) < l_949),
                          g_26[0][0]),
                         g_293[3])) ||
                     (-3L)))))),
       g_104);
  return g_238;
}

static int16_t func_77(int32_t p_78) {
  int16_t l_79 = 0xF408L;
  return l_79;
}

static uint16_t func_80(uint32_t p_81) {
  int32_t l_87 = 7L;
  int32_t l_90 = 0x95D92507L;
  int8_t l_211 = 0xC4L;
  int32_t l_221 = (-1L);
  int32_t l_256 = (-3L);
  int32_t l_257 = 7L;
  uint32_t l_351 = 0x9355559AL;
  int32_t l_372 = (-6L);
  int16_t l_394 = 0x2381L;
  int8_t l_626 = (-1L);
  uint16_t l_681 = 0x55B9L;
  uint8_t l_699 = 254UL;
  if ((g_26[1][1],
       (safe_rshift_func_int8_t_s_u((((p_81 | p_81) | (-3L)), 0x86L), 1)))) {
    uint16_t l_91 = 65527UL;
    int32_t l_102 = (-1L);
    int32_t l_109 = 0x918DDDCDL;
    uint32_t l_163 = 0UL;
    int8_t l_164[2];
    int i;
    for (i = 0; i < 2; i++)
      l_164[i] = 1L;
    for (p_81 = (-4); (p_81 == 50); p_81 = safe_add_func_int16_t_s_s(p_81, 6)) {
      int16_t l_88 = 0x4F54L;
      int32_t l_89[1];
      uint8_t l_127 = 250UL;
      int32_t l_150 = 0L;
      int i;

      for (i = 0; i < 1; i++)
        l_89[i] = 0x1C1BBB80L;

      g_86 = (-4L);
      l_88 = l_87;

      l_221 &= (l_88 < 0xA74CL);
    }
    g_258 &=
        ((((p_81 &
            (l_257 |= (safe_rshift_func_int8_t_s_s(
                 (l_90 =
                      ((0xECEDL >=
                        ((((safe_sub_func_uint32_t_u_u(
                               (l_256 &=
                                (((safe_sub_func_uint32_t_u_u(
                                      (((l_221 >=
                                         (g_119 >=
                                          (l_91 &&
                                           (0x3A82L &
                                            (65535UL ||
                                             (l_102 = (safe_add_func_int8_t_s_s(
                                                  l_211,
                                                  (((l_109 ^= g_147) || l_90) ==
                                                   p_81))))))))) == p_81),
                                       0x3595D045L),
                                      0x86C6B0ADL)) |
                                  g_255) <= l_90)),
                               l_164[1])) == 0xD44DL) ^
                          0xDBBDL),
                         p_81)),
                       l_87)),
                 g_153[0])))) |
           p_81) &
          l_211) == g_104);
  } else {
    uint32_t l_270 = 1UL;
    uint32_t l_282 = 4294967295UL;
    int32_t l_291 = 0L;
    int32_t l_296 = 0xCBC9E5EEL;
    uint16_t l_312[2];
    int32_t l_337 = 9L;
    int32_t l_341 = 0x93EB98A8L;
    int32_t l_346 = 8L;
    uint32_t l_411[5][2] = {{0x64F34E5CL, 0x64F34E5CL},
                            {0x64F34E5CL, 0x64F34E5CL},
                            {0x64F34E5CL, 0x64F34E5CL},
                            {0x64F34E5CL, 0x64F34E5CL},
                            {0x64F34E5CL, 0x64F34E5CL}};
    uint16_t l_495 = 0xB410L;
    int32_t l_657 = (-1L);
    int32_t l_658 = 0x1E9C7087L;
    int32_t l_660 = 0xA922C990L;
    int32_t l_661 = 0xA794E776L;
    int32_t l_662 = 0x029A9FE3L;
    int32_t l_663 = (-1L);
    int32_t l_664 = 1L;
    int32_t l_666 = 0x0EFC14EFL;
    int32_t l_671 = 0L;
    int32_t l_674 = (-2L);
    int i, j;

    g_283[3] &= g_378[6];
    for (l_495 = 0; (l_495 < 31); l_495++) {
      --l_699;
      for (l_495 = 0; (l_495 < 31); l_495++) {
        --l_699;
      }
    }
  }
  return p_81;
}

int main(void) {
  int i, j, k;
  int print_hash_value = 0;
  crc32_gentab();
  func_1();
  transparent_crc(g_5, "g_5", print_hash_value);
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 5; j++) {
      transparent_crc(g_26[i][j], "g_26[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_74, "g_74", print_hash_value);
  transparent_crc(g_86, "g_86", print_hash_value);
  transparent_crc(g_104, "g_104", print_hash_value);
  transparent_crc(g_119, "g_119", print_hash_value);
  transparent_crc(g_140, "g_140", print_hash_value);
  transparent_crc(g_147, "g_147", print_hash_value);
  for (i = 0; i < 10; i++) {
    transparent_crc(g_153[i], "g_153[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_181, "g_181", print_hash_value);
  for (i = 0; i < 7; i++) {
    transparent_crc(g_182[i], "g_182[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 1; j++) {
      for (k = 0; k < 8; k++) {
        transparent_crc(g_212[i][j][k], "g_212[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_238, "g_238", print_hash_value);
  transparent_crc(g_255, "g_255", print_hash_value);
  transparent_crc(g_258, "g_258", print_hash_value);
  for (i = 0; i < 7; i++) {
    transparent_crc(g_283[i], "g_283[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  for (i = 0; i < 4; i++) {
    transparent_crc(g_293[i], "g_293[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  for (i = 0; i < 6; i++) {
    transparent_crc(g_335[i], "g_335[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  for (i = 0; i < 8; i++) {
    transparent_crc(g_378[i], "g_378[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_395, "g_395", print_hash_value);
  transparent_crc(g_438, "g_438", print_hash_value);
  for (i = 0; i < 5; i++) {
    transparent_crc(g_466[i], "g_466[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_592, "g_592", print_hash_value);
  transparent_crc(g_734, "g_734", print_hash_value);
  transparent_crc(g_1047, "g_1047", print_hash_value);
  transparent_crc(g_1076, "g_1076", print_hash_value);
  transparent_crc(g_1185, "g_1185", print_hash_value);
  transparent_crc(g_1254, "g_1254", print_hash_value);
  transparent_crc(g_1260, "g_1260", print_hash_value);
  transparent_crc(g_1441, "g_1441", print_hash_value);
  transparent_crc(g_1462, "g_1462", print_hash_value);
  transparent_crc(g_1519, "g_1519", print_hash_value);
  transparent_crc(g_1655, "g_1655", print_hash_value);
  transparent_crc(g_1815, "g_1815", print_hash_value);
  for (i = 0; i < 5; i++) {
    transparent_crc(g_2295[i], "g_2295[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  for (i = 0; i < 4; i++) {
    transparent_crc(g_2643[i], "g_2643[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_2737, "g_2737", print_hash_value);
  transparent_crc(g_2870, "g_2870", print_hash_value);
  transparent_crc(g_2949, "g_2949", print_hash_value);
  transparent_crc(g_2982, "g_2982", print_hash_value);
  transparent_crc(g_3025, "g_3025", print_hash_value);
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 5; j++) {
      for (k = 0; k < 5; k++) {
        transparent_crc(g_3235[i][j][k], "g_3235[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_3442, "g_3442", print_hash_value);
  transparent_crc(g_3652, "g_3652", print_hash_value);
  for (i = 0; i < 1; i++) {
    transparent_crc(g_3797[i], "g_3797[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        transparent_crc(g_3899[i][j][k], "g_3899[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_3935, "g_3935", print_hash_value);
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}

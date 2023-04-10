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

int printf (const char *, ...);
void __assert_fail (const char *__assertion, const char *__file, unsigned int __line, const char *__function);
static void
platform_main_end(uint32_t crc, int flag) {

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

      (si == (-32767-1)) ? ((si)) :

                        -si;
}

static int16_t(safe_add_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((32767) - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < ((-32767-1) - si2))))
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
       ((si1 > 0) && (si2 <= 0) && (si2 < ((-32767-1) / si1))) ||
       ((si1 <= 0) && (si2 > 0) && (si1 < ((-32767-1) / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((32767) / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int16_t(safe_mod_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      ((si2 == 0) || ((si1 == (-32767-1)) && (si2 == (-1)))) ? ((si1)) :

                                                            (si1 % si2);
}

static int16_t(safe_div_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return

      ((si2 == 0) || ((si1 == (-32767-1)) && (si2 == (-1)))) ? ((si1)) :

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

      (si == (-2147483647-1)) ? ((si)) :

                        -si;
}

static int32_t(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < ((-2147483647-1) - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int32_t(safe_sub_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~(2147483647)))) - si2) ^ si2)) < 0)
          ? ((si1))
          :

          (si1 - si2);
}

static int32_t(safe_mul_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) / si2))) ||
       ((si1 > 0) && (si2 <= 0) && (si2 < ((-2147483647-1) / si1))) ||
       ((si1 <= 0) && (si2 > 0) && (si1 < ((-2147483647-1) / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((2147483647) / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int32_t(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      ((si2 == 0) || ((si1 == (-2147483647-1)) && (si2 == (-1)))) ? ((si1)) :

                                                            (si1 % si2);
}

static int32_t(safe_div_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return

      ((si2 == 0) || ((si1 == (-2147483647-1)) && (si2 == (-1)))) ? ((si1)) :

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

      (fabsf((0.5f * sf1) + (0.5f * sf2)) > (0.5f * 3.40282347e+38F)) ? (sf1) :

                                                              (sf1 + sf2);
}

static float(safe_sub_func_float_f_f)(float sf1, float sf2) {

  return

      (fabsf((0.5f * sf1) - (0.5f * sf2)) > (0.5f * 3.40282347e+38F)) ? (sf1) :

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

      (fabsf((0.5 * sf1) + (0.5 * sf2)) > (0.5 * 1.7976931348623157e+308)) ? (sf1) :

                                                          (sf1 + sf2);
}

static double(safe_sub_func_double_f_f)(double sf1, double sf2) {

  return

      (fabsf((0.5 * sf1) - (0.5 * sf2)) > (0.5 * 1.7976931348623157e+308)) ? (sf1) :

                                                          (sf1 - sf2);
}

static double(safe_mul_func_double_f_f)(double sf1, double sf2) {

  return

      (fabsf((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) >
       (0x1.0p-100 * (0x1.0p-924 * 1.7976931348623157e+308)))
          ? (sf1)
          :

          (sf1 * sf2);
}

static double(safe_div_func_double_f_f)(double sf1, double sf2) {

  return

      ((fabsf(sf2) < 1.0) &&
       (((sf2 == 0.0) || (fabsf((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) >
                             (0x1.0p-100 * (0x1.0p-974 * 1.7976931348623157e+308)))))
          ? (sf1)
          :

          (sf1 / sf2);
}

static int32_t(safe_convert_func_float_to_int32_t)(float sf1) {

  return

      ((sf1 <= (-2147483647-1)) || (sf1 >= (2147483647))) ? ((2147483647)) :

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

union U0 {
  int32_t f0;
  uint16_t f1;
  const uint8_t f2;
};

static int8_t g_20 = 0x76L;
static uint8_t g_25[1] = {5UL};
static uint8_t g_28[3] = {255UL, 255UL, 255UL};
static int32_t g_66 = 0L;
static uint16_t g_67 = 65535UL;
static int32_t g_90 = (-9L);
static int16_t g_151[10][3] = {
    {(-3L), (-3L), 0x8666L}, {(-3L), (-3L), 0x8666L}, {(-3L), (-3L), 0x8666L},
    {(-3L), (-3L), 0x8666L}, {(-3L), (-3L), 0x8666L}, {(-3L), (-3L), 0x8666L},
    {(-3L), (-3L), 0x8666L}, {(-3L), (-3L), 0x8666L}, {(-3L), (-3L), 0x8666L},
    {(-3L), (-3L), 0x8666L}};
static uint8_t g_164 = 255UL;
static int16_t g_167[6][8] = {
    {0x2041L, 0x0EE3L, 0x2041L, 0xD350L, 0x4927L, (-1L), 0L, 0L},
    {0x2041L, 0x0EE3L, 0x2041L, 0xD350L, 0x4927L, (-1L), 0L, 0L},
    {0x2041L, 0x0EE3L, 0x2041L, 0xD350L, 0x4927L, (-1L), 0L, 0L},
    {0x2041L, 0x0EE3L, 0x2041L, 0xD350L, 0x4927L, (-1L), 0L, 0L},
    {0x2041L, 0x0EE3L, 0x2041L, 0xD350L, 0x4927L, (-1L), 0L, 0L},
    {0x2041L, 0x0EE3L, 0x2041L, 0xD350L, 0x4927L, (-1L), 0L, 0L}};
static union U0 g_208 = {-1L};
static uint16_t g_218 = 0x3B9CL;
static uint32_t g_233 = 0x72AEE829L;
static int8_t g_251 = 0x26L;
static uint32_t g_264 = 4294967293UL;
static uint32_t g_322[8][3] = {
    {0UL, 0UL, 0UL}, {0UL, 0UL, 0UL}, {0UL, 0UL, 0UL}, {0UL, 0UL, 0UL},
    {0UL, 0UL, 0UL}, {0UL, 0UL, 0UL}, {0UL, 0UL, 0UL}, {0UL, 0UL, 0UL}};
static const int32_t g_372 = 0x098EF1BAL;
static int8_t g_598 = 0x40L;
static uint8_t g_623 = 0x7DL;
static int32_t g_720 = 1L;
static uint16_t g_745 = 0UL;
static int32_t g_976 = 0x05761C0CL;
static uint8_t g_978[8][1] = {{0x0FL}, {0x0FL}, {0x0FL}, {0x0FL},
                              {0x0FL}, {0x0FL}, {0x0FL}, {0x0FL}};
static int16_t g_1279 = (-1L);
static int16_t g_1445 = 3L;
static uint32_t g_1467 = 1UL;
static int32_t g_1550[10][7][3] = {{{0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)}},
                                   {{0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)}},
                                   {{0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)}},
                                   {{0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)}},
                                   {{0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)}},
                                   {{0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)}},
                                   {{0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)}},
                                   {{0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)}},
                                   {{0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)}},
                                   {{0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)},
                                    {0x04495A0DL, 1L, (-1L)}}};
static uint32_t g_1574 = 0x09CC1D35L;
static int8_t g_1705 = 0x1FL;
static uint32_t g_1706 = 0xCA671623L;
static uint32_t g_1781 = 0x9E833115L;
static int16_t g_1916 = 9L;
static union U0 g_1918 = {0xD57133ADL};
static int32_t g_1939[5][3][4] = {{{4L, 4L, 0xD33DB3E6L, 0xB0F494EFL},
                                   {4L, 4L, 0xD33DB3E6L, 0xB0F494EFL},
                                   {4L, 4L, 0xD33DB3E6L, 0xB0F494EFL}},
                                  {{4L, 4L, 0xD33DB3E6L, 0xB0F494EFL},
                                   {4L, 4L, 0xD33DB3E6L, 0xB0F494EFL},
                                   {4L, 4L, 0xD33DB3E6L, 0xB0F494EFL}},
                                  {{4L, 4L, 0xD33DB3E6L, 0xB0F494EFL},
                                   {4L, 4L, 0xD33DB3E6L, 0xB0F494EFL},
                                   {4L, 4L, 0xD33DB3E6L, 0xB0F494EFL}},
                                  {{4L, 4L, 0xD33DB3E6L, 0xB0F494EFL},
                                   {4L, 4L, 0xD33DB3E6L, 0xB0F494EFL},
                                   {4L, 4L, 0xD33DB3E6L, 0xB0F494EFL}},
                                  {{4L, 4L, 0xD33DB3E6L, 0xB0F494EFL},
                                   {4L, 4L, 0xD33DB3E6L, 0xB0F494EFL},
                                   {4L, 4L, 0xD33DB3E6L, 0xB0F494EFL}}};

static int16_t func_1(void);
static uint16_t func_7(const uint8_t p_8, union U0 p_9, uint16_t p_10);
static const uint8_t func_11(uint16_t p_12, uint32_t p_13, int32_t p_14,
                             int8_t p_15);
static uint16_t func_16(int8_t p_17, uint8_t p_18, int16_t p_19);
static uint8_t func_21(int32_t p_22, int32_t p_23);
static int32_t func_31(int8_t p_32, uint32_t p_33, uint16_t p_34, int32_t p_35);
static uint16_t func_36(uint16_t p_37, union U0 p_38, int8_t p_39);
static union U0 func_40(int32_t p_41, uint8_t p_42, int8_t p_43, int16_t p_44);
static int8_t func_45(int8_t p_46, uint32_t p_47);
static int32_t func_51(uint16_t p_52, uint32_t p_53, uint8_t p_54,
                       union U0 p_55, int32_t p_56);
static int16_t func_1(void) {
  int32_t l_6 = 1L;
  int32_t l_974 = 0x1E67093AL;
  uint16_t l_975 = 8UL;
  int32_t l_977 = 0x844D201FL;
  uint8_t l_1389 = 8UL;
  int8_t l_1947 = 0xACL;
  int32_t l_1948 = 0xD853BA35L;
  int32_t l_1951 = 0xAD55A993L;
  g_1939[1][2][0] =
      ((safe_add_func_uint16_t_u_u(
           ((safe_rshift_func_int16_t_s_u(
                (l_6 &&
                 (func_7(
                      func_11(
                          func_16(
                              g_20, func_21(g_20, g_20),
                              (safe_mod_func_int16_t_s_s(
                                  (safe_lshift_func_uint16_t_u_u(
                                      g_372,
                                      ((g_978[0][0] =
                                            (l_6 ||
                                             (g_372,
                                              (l_977 =
                                                   ((!((safe_lshift_func_int16_t_s_u(
                                                           (((((g_976 = (safe_sub_func_int8_t_s_s(
                                                                    (((safe_mod_func_int32_t_s_s(
                                                                          (l_974 =
                                                                               (l_6 |
                                                                                1L)),
                                                                          l_6)) &&
                                                                      0xE6EBA926L) |
                                                                     l_975),
                                                                    255UL))) <
                                                               g_372) <=
                                                              g_20) &&
                                                             l_974) < g_372),
                                                           g_20)) &&
                                                       0x10L)) != g_372))))) ||
                                       l_6))),
                                  (-8L)))),
                          l_975, g_372, l_1389),
                      g_1918, l_6) ^
                  0UL)),
                g_1550[6][2][2])) > l_6),
           65530UL)) |
       0x9E07L);
  l_1948 =
      ((((l_1947 =
              (l_1389,
               ((((((g_218 =
                         (l_974 =
                              (l_6 |
                               ((((g_1916 >
                                   ((((g_1445 ^
                                       ((safe_add_func_int32_t_s_s(
                                            (l_977 = l_6),
                                            (safe_unary_minus_func_uint16_t_u(
                                                l_1389)))) >= (2UL | l_974))) >
                                      (0xC90FBA8AL & l_974)) ^
                                     g_167[2][6]) <= 0L)) &
                                  g_233) <= 2L) &
                                g_1939[1][2][0])))) &
                    l_6) ||
                   g_151[2][2]) |
                  l_975) == l_975),
                l_975))) == g_1939[1][0][0]) != g_1918.f2) != 0UL);
  l_977 = (safe_rshift_func_uint8_t_u_u(g_745, 3));
  return l_1951;
}

static uint16_t func_7(const uint8_t p_8, union U0 p_9, uint16_t p_10) {
  uint32_t l_1927 = 4294967288UL;
  int32_t l_1936[9][2][5] = {{{0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L},
                              {0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L}},
                             {{0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L},
                              {0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L}},
                             {{0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L},
                              {0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L}},
                             {{0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L},
                              {0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L}},
                             {{0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L},
                              {0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L}},
                             {{0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L},
                              {0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L}},
                             {{0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L},
                              {0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L}},
                             {{0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L},
                              {0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L}},
                             {{0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L},
                              {0xC3EBE3B0L, 9L, 2L, (-1L), 0x305EBBD0L}}};
  int32_t l_1937[5][1][4] = {{{0xA1379ADDL, (-1L), 0xA1379ADDL, (-1L)}},
                             {{0xA1379ADDL, (-1L), 0xA1379ADDL, (-1L)}},
                             {{0xA1379ADDL, (-1L), 0xA1379ADDL, (-1L)}},
                             {{0xA1379ADDL, (-1L), 0xA1379ADDL, (-1L)}},
                             {{0xA1379ADDL, (-1L), 0xA1379ADDL, (-1L)}}};
  int32_t l_1938 = 0x832903CEL;
  int i, j, k;
  l_1938 = (safe_rshift_func_int16_t_s_u(
      ((((l_1937[2][0][2] =
              ((safe_rshift_func_int16_t_s_u(
                   ((safe_lshift_func_int16_t_s_u(
                        ((safe_sub_func_int8_t_s_s(
                             (l_1936[3][1][0] =
                                  ((g_598 <
                                    (!(((((((p_9.f0 | g_598) >=
                                            (l_1927 == l_1927)),
                                           ((safe_add_func_uint16_t_u_u(
                                                ((safe_sub_func_uint16_t_u_u(
                                                     l_1927,
                                                     (safe_add_func_uint8_t_u_u(
                                                         g_1918.f0,
                                                         ((p_9.f2,
                                                           (safe_mod_func_uint16_t_u_u(
                                                               (p_9.f1 == p_8),
                                                               l_1927))),
                                                          0L))))) < 2L),
                                                l_1927)) &&
                                            3UL)) ^
                                          g_322[4][2]),
                                         l_1927),
                                        p_9.f2) &&
                                       p_9.f0))) != g_218)),
                             p_10)) &
                         l_1927),
                        p_8)) &&
                    l_1927),
                   6)) ||
               g_720)) |
         (-1L)),
        0x87L) &
       0x3DL),
      5));
  return p_10;
}

static const uint8_t func_11(uint16_t p_12, uint32_t p_13, int32_t p_14,
                             int8_t p_15) {
  int32_t l_1411 = 8L;
  int32_t l_1509[9];
  uint32_t l_1541 = 0x7AC89CD1L;
  uint32_t l_1546 = 0UL;
  const int8_t l_1548 = 1L;
  const union U0 l_1675 = {0x0BCF4CEFL};
  const uint32_t l_1709 = 0x42D153A8L;
  const int16_t l_1717 = 0x798BL;
  int32_t l_1773 = 0x33BF1BB4L;
  uint16_t l_1807 = 65535UL;
  int8_t l_1814 = 0x41L;
  int32_t l_1842 = 0xA1E86E23L;
  uint32_t l_1845 = 0x9968D128L;
  int32_t l_1846 = (-9L);
  int32_t l_1847 = 9L;
  int32_t l_1886 = (-1L);
  uint32_t l_1904 = 0UL;
  int i;
  for (i = 0; i < 9; i++)
    l_1509[i] = 0x706038CFL;
  for (g_90 = 0; (g_90 < 15); g_90 = safe_add_func_int8_t_s_s(g_90, 2)) {
    int32_t l_1413 = 0L;
    int32_t l_1443[6];
    const uint32_t l_1444 = 3UL;
    union U0 l_1486 = {0x0B6D8429L};
    int i;
    for (i = 0; i < 6; i++)
      l_1443[i] = 0xC1FE4307L;
    for (g_66 = 0; (g_66 <= 2); g_66 += 1) {
      union U0 l_1410 = {-1L};
      int32_t l_1414 = (-8L);
      for (g_598 = 0; (g_598 <= 2); g_598 += 1) {
        uint32_t l_1412[5][7][7] = {{{6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L}},
                                    {{6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L}},
                                    {{6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L}},
                                    {{6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L}},
                                    {{6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L},
                                     {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                      0x474578C0L, 0UL, 0x8B57FD33L}}};
        int32_t l_1423 = 8L;
        int16_t l_1442 = 0x73C9L;
        uint16_t l_1466[2][5] = {{0x7FBAL, 0x806DL, 0x7FBAL, 0x806DL, 0x7FBAL},
                                 {0x7FBAL, 0x806DL, 0x7FBAL, 0x806DL, 0x7FBAL}};
        int i, j, k;
        l_1414 = (safe_lshift_func_uint16_t_u_u(
            g_322[(g_598 + 1)][g_66],
            (g_218 =
                 (l_1413 =
                      ((safe_mod_func_int16_t_s_s(
                           (g_151[g_598][g_66] =
                                (((safe_lshift_func_uint8_t_u_u(
                                      g_322[(g_598 + 5)][g_66], 3)) >
                                  ((((p_15 |
                                      ((safe_lshift_func_int8_t_s_u(
                                           (((safe_sub_func_int16_t_s_s(
                                                 ((p_13 <
                                                   ((safe_mod_func_uint8_t_u_u(
                                                        ((safe_add_func_int32_t_s_s(
                                                             ((safe_add_func_int16_t_s_s(
                                                                  (g_322
                                                                       [(g_598 +
                                                                         1)]
                                                                       [g_66] !=
                                                                   (!(g_25[0] !=
                                                                      g_322
                                                                          [(g_598 +
                                                                            5)]
                                                                          [g_66]))),
                                                                  (+(~(
                                                                      (g_208,
                                                                       ((safe_rshift_func_uint16_t_u_s(
                                                                            (l_1410,
                                                                             g_322[(
                                                                                 g_598 +
                                                                                 5)]
                                                                                  [g_66]),
                                                                            2)) ||
                                                                        0xD6L)),
                                                                      p_13))))),
                                                              6L),
                                                             1L)) |
                                                         p_12),
                                                        p_12)),
                                                    g_322[(g_598 + 5)]
                                                         [g_66])) != p_15),
                                                 g_28[1])) > g_90) != p_14),
                                           l_1411)) &&
                                       g_167[2][2])),
                                     l_1412[3][5][5]) |
                                    p_15) &
                                   0x6AE9L)) ||
                                 l_1411)),
                           p_12)) ||
                       g_976)))));
        for (g_208.f1 = (-20); (g_208.f1 < 9);
             g_208.f1 = safe_add_func_int8_t_s_s(g_208.f1, 9)) {
          int8_t l_1438 = 0xFBL;
          const int32_t l_1439 = 0x4145AAC2L;
          int32_t l_1450 = 0xB303076EL;
          if (((l_1411 ^
                ((safe_add_func_uint8_t_u_u(
                     (p_12 | (((safe_mod_func_int32_t_s_s(
                                   ((g_976 &&
                                     (((safe_add_func_int16_t_s_s(
                                           g_372, (l_1423 = (l_1412[0][4][2] <=
                                                             0UL)))) <= p_14) !=
                                      ((safe_lshift_func_uint16_t_u_s(
                                           (l_1410.f0, l_1414), 8)) ^
                                       p_14))),
                                    g_67),
                                   0xF02186A5L)) &&
                               0x8DL),
                              g_251)),
                     0xC4L)) |
                 g_233)) <= g_720)) {
            g_1445 = (safe_mod_func_int16_t_s_s(
                (safe_lshift_func_int16_t_s_u(
                    (safe_mod_func_int32_t_s_s(
                        ((safe_add_func_uint32_t_u_u(
                             ((safe_mod_func_int8_t_s_s(
                                  p_12,
                                  (safe_sub_func_int8_t_s_s(
                                      ((g_208,
                                        (((((l_1443[1] =
                                                 (g_322[1][2] =
                                                      (g_25[0] &&
                                                       (((((+(((l_1438 =
                                                                    0x32L) ==
                                                               (g_978[5][0] ^
                                                                ((0xD73CL ||
                                                                  ((g_251 =
                                                                        (((+(((l_1439 ==
                                                                               ((safe_sub_func_int16_t_s_s(
                                                                                    (g_208,
                                                                                     (g_251 ||
                                                                                      p_13)),
                                                                                    p_15)) <
                                                                                l_1410
                                                                                    .f2)) &&
                                                                              (-1L)) <
                                                                             0x8CD1823FL)) >
                                                                          g_623) >
                                                                         0x6FDB139BL)) <=
                                                                   g_372)),
                                                                 p_12))) >=
                                                              l_1442)) ^
                                                           g_372) ^
                                                          p_14) |
                                                         0x51L) <= l_1411)))) <
                                            g_20) <= 1L) &
                                          p_12),
                                         l_1444)),
                                       0L),
                                      p_14)))),
                              l_1411),
                             p_14)) > l_1444),
                        0xDC0806FCL)),
                    p_13)),
                p_14));
            {
              int32_t l_1413 = 0L;
              int32_t l_1443[6];
              const uint32_t l_1444 = 3UL;
              union U0 l_1486 = {0x0B6D8429L};
              int i;
              for (i = 0; i < 6; i++)
                l_1443[i] = 0xC1FE4307L;
              for (g_66 = 0; (g_66 <= 2); g_66 += 1) {
                union U0 l_1410 = {-1L};
                int32_t l_1414 = (-8L);
                for (g_598 = 0; (g_598 <= 2); g_598 += 1) {
                  uint32_t l_1412[5][7][7] = {
                      {{6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L}},
                      {{6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L}},
                      {{6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L}},
                      {{6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L}},
                      {{6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L},
                       {6UL, 4UL, 4294967295UL, 0x1FB493A9L, 0x474578C0L, 0UL,
                        0x8B57FD33L}}};
                  int32_t l_1423 = 8L;
                  int16_t l_1442 = 0x73C9L;
                  uint16_t l_1466[2][5] = {
                      {0x7FBAL, 0x806DL, 0x7FBAL, 0x806DL, 0x7FBAL},
                      {0x7FBAL, 0x806DL, 0x7FBAL, 0x806DL, 0x7FBAL}};
                  int i, j, k;
                  l_1414 = (safe_lshift_func_uint16_t_u_u(
                      g_322[(g_598 + 1)][g_66],
                      (g_218 =
                           (l_1413 =
                                ((safe_mod_func_int16_t_s_s(
                                     (g_151[g_598][g_66] =
                                          (((safe_lshift_func_uint8_t_u_u(
                                                g_322[(g_598 + 5)][g_66], 3)) >
                                            ((((p_15 |
                                                ((safe_lshift_func_int8_t_s_u(
                                                     (((safe_sub_func_int16_t_s_s(
                                                           ((p_13 <
                                                             ((safe_mod_func_uint8_t_u_u(
                                                                  ((safe_add_func_int32_t_s_s(
                                                                       ((safe_add_func_int16_t_s_s(
                                                                            (g_322[(
                                                                                 g_598 +
                                                                                 1)]
                                                                                  [g_66] !=
                                                                             (!(g_25[0] !=
                                                                                g_322[(
                                                                                    g_598 +
                                                                                    5)]
                                                                                     [g_66]))),
                                                                            (+(~(
                                                                                (g_208,
                                                                                 ((safe_rshift_func_uint16_t_u_s(
                                                                                      (l_1410,
                                                                                       g_322[(
                                                                                           g_598 +
                                                                                           5)]
                                                                                            [g_66]),
                                                                                      2)) ||
                                                                                  0xD6L)),
                                                                                p_13))))),
                                                                        6L),
                                                                       1L)) |
                                                                   p_12),
                                                                  p_12)),
                                                              g_322[(g_598 + 5)]
                                                                   [g_66])) !=
                                                            p_15),
                                                           g_28[1])) > g_90) !=
                                                      p_14),
                                                     l_1411)) &&
                                                 g_167[2][2])),
                                               l_1412[3][5][5]) |
                                              p_15) &
                                             0x6AE9L)) ||
                                           l_1411)),
                                     p_12)) ||
                                 g_976)))));
                  for (g_208.f1 = (-20); (g_208.f1 < 9);
                       g_208.f1 = safe_add_func_int8_t_s_s(g_208.f1, 9)) {
                    int8_t l_1438 = 0xFBL;
                    const int32_t l_1439 = 0x4145AAC2L;
                    int32_t l_1450 = 0xB303076EL;
                    if (((l_1411 ^
                          ((safe_add_func_uint8_t_u_u(
                               (p_12 |
                                (((safe_mod_func_int32_t_s_s(
                                      ((g_976 &&
                                        (((safe_add_func_int16_t_s_s(
                                              g_372,
                                              (l_1423 = (l_1412[0][4][2] <=
                                                         0UL)))) <= p_14) !=
                                         ((safe_lshift_func_uint16_t_u_s(
                                              (l_1410.f0, l_1414), 8)) ^
                                          p_14))),
                                       g_67),
                                      0xF02186A5L)) &&
                                  0x8DL),
                                 g_251)),
                               0xC4L)) |
                           g_233)) <= g_720)) {
                      g_1445 = (safe_mod_func_int16_t_s_s(
                          (safe_lshift_func_int16_t_s_u(
                              (safe_mod_func_int32_t_s_s(
                                  ((safe_add_func_uint32_t_u_u(
                                       ((safe_mod_func_int8_t_s_s(
                                            p_12,
                                            (safe_sub_func_int8_t_s_s(
                                                ((g_208,
                                                  (((((l_1443[1] =
                                                           (g_322[1][2] =
                                                                (g_25[0] &&
                                                                 (((((+(((l_1438 =
                                                                              0x32L) ==
                                                                         (g_978
                                                                              [5]
                                                                              [0] ^
                                                                          ((0xD73CL ||
                                                                            ((g_251 =
                                                                                  (((+(((l_1439 ==
                                                                                         ((safe_sub_func_int16_t_s_s(
                                                                                              (g_208,
                                                                                               (g_251 ||
                                                                                                p_13)),
                                                                                              p_15)) <
                                                                                          l_1410
                                                                                              .f2)) &&
                                                                                        (-1L)) <
                                                                                       0x8CD1823FL)) >
                                                                                    g_623) >
                                                                                   0x6FDB139BL)) <=
                                                                             g_372)),
                                                                           p_12))) >=
                                                                        l_1442)) ^
                                                                     g_372) ^
                                                                    p_14) |
                                                                   0x51L) <=
                                                                  l_1411)))) <
                                                      g_20) <= 1L) &
                                                    p_12),
                                                   l_1444)),
                                                 0L),
                                                p_14)))),
                                        l_1411),
                                       p_14)) > l_1444),
                                  0xDC0806FCL)),
                              p_13)),
                          p_14));
                      if (p_13)
                        continue;
                    } else {
                      int32_t l_1451 = (-5L);
                      l_1451 = (safe_rshift_func_int16_t_s_s(
                          (safe_sub_func_uint8_t_u_u((l_1450 = p_15), (-2L))),
                          6));
                      if (g_28[0])
                        break;
                    }
                    for (l_1411 = 1; (l_1411 <= 4); l_1411 += 1) {
                      int i, j, k;
                      l_1414 =
                          (((((((g_322[g_598][g_598] <
                                 (safe_add_func_int32_t_s_s(
                                     ((((((-1L) <=
                                          ((safe_lshift_func_int16_t_s_u(
                                               l_1412[l_1411][l_1411]
                                                     [(g_598 + 3)],
                                               1)) &&
                                           ((((safe_add_func_uint32_t_u_u(
                                                  l_1439,
                                                  ((1L !=
                                                    (((p_12 >=
                                                       ((safe_sub_func_int8_t_s_s(
                                                            (p_12 ==
                                                             (safe_add_func_int8_t_s_s(
                                                                 0xA5L,
                                                                 ((!(safe_mod_func_uint8_t_u_u(
                                                                      (((safe_rshift_func_int8_t_s_u(
                                                                            (g_66,
                                                                             p_13),
                                                                            0)) |
                                                                        0x49L) &
                                                                       7UL),
                                                                      1L))) <=
                                                                  1L)))),
                                                            0xC5L)) &
                                                        g_90)),
                                                      (-2L)) ^
                                                     0L)) |
                                                   65535UL))) != l_1438) &&
                                             0xAF341D2CL) > 1L))) >= l_1450),
                                        p_15) >= 0x6DL) != 0xAC20L),
                                     0xC4429022L))) >= l_1411) |
                               0x1B2BL) < p_12) |
                             l_1466[1][0]) |
                            8L) |
                           l_1411);
                      l_1450 = l_1412[l_1411][l_1411][(g_598 + 3)];
                      g_1467 = g_251;
                      if (p_14)
                        continue;
                    }
                  }
                }
                return l_1414;
              }
              if ((((~((g_167[2][2] |
                        (((((((safe_lshift_func_int8_t_s_s(
                                  ((safe_add_func_uint8_t_u_u(
                                       (((((((safe_sub_func_uint16_t_u_u(
                                                 g_67, g_976)) ||
                                             ((safe_rshift_func_uint8_t_u_u(
                                                  255UL, 0)),
                                              (safe_add_func_int8_t_s_s(
                                                  (((((g_623 &
                                                       (g_745 = (safe_sub_func_uint8_t_u_u(
                                                            (((safe_lshift_func_uint16_t_u_u(
                                                                  (p_14 |
                                                                   l_1411),
                                                                  (((g_233 <=
                                                                     (((~(safe_add_func_int32_t_s_s(
                                                                           g_218,
                                                                           (-1L)))),
                                                                       p_13) !=
                                                                      l_1443
                                                                          [4])) |
                                                                    1L) ^
                                                                   l_1444))) >=
                                                              g_720) ||
                                                             0xE5BEL),
                                                            g_151[6][2])))) >
                                                      0x7FL) > l_1443[1]) <=
                                                    0x7044L) > p_14),
                                                  g_598)))) &&
                                            0x0CL),
                                           l_1411) <= 0x13DC0E27L) &&
                                         p_13),
                                        g_720),
                                       0x9BL)) == l_1411),
                                  g_978[6][0])),
                              l_1411) > p_15) > g_20),
                           p_14),
                          g_745) != 0x89L)) |
                       g_251)),
                    l_1486),
                   l_1411)) {
                int32_t l_1507 = 0x8CE51DC4L;
                int32_t l_1508[9] = {3L, 8L, 3L, 8L, 3L, 8L, 3L, 8L, 3L};
                int i;
                l_1509[7] =
                    ((safe_rshift_func_uint8_t_u_s(255UL, 3)) !=
                     (0xBC008C8BL ^
                      (((safe_add_func_int16_t_s_s(
                            (-1L),
                            (safe_rshift_func_int8_t_s_s(
                                ((safe_rshift_func_uint8_t_u_u(
                                     (p_13 < p_14),
                                     ((safe_add_func_uint32_t_u_u(
                                          (safe_add_func_uint16_t_u_u(
                                              g_976,
                                              (safe_sub_func_uint8_t_u_u(
                                                  (safe_add_func_uint8_t_u_u(
                                                      (safe_sub_func_uint8_t_u_u(
                                                          l_1411,
                                                          (l_1486.f0 |
                                                           (l_1508[8] =
                                                                (safe_mod_func_int8_t_s_s(
                                                                    ((g_25[0] =
                                                                          8UL) ==
                                                                     0xE8L),
                                                                    l_1507)))))),
                                                      g_67)),
                                                  g_322[5][2])))),
                                          0x72A20BADL)),
                                      g_167[1][6]))),
                                 (-7L)),
                                6)))),
                        1L),
                       p_12)));
              } else {
                const uint32_t l_1543[10] = {
                    0x40587882L, 0x40587882L, 0x40587882L, 0x40587882L,
                    0x40587882L, 0x40587882L, 0x40587882L, 0x40587882L,
                    0x40587882L, 0x40587882L};
                int i;
                for (g_745 = (-15); (g_745 != 51); ++g_745) {
                  uint32_t l_1542[10] = {
                      5UL, 0x9F45FADFL, 0x18B02749L, 0x18B02749L, 0x9F45FADFL,
                      5UL, 0x9F45FADFL, 0x18B02749L, 0x18B02749L, 0x9F45FADFL};
                  int32_t l_1544 = 0x840A4CE2L;
                  int32_t l_1545 = 0xFF561900L;
                  int i;
                l_1509[1] = (((g_1467 && (((+(((safe_mod_func_uint32_t_u_u((0xFD06L && (0xF385L || ((l_1545 = ((((safe_unary_minus_func_int8_t_s((safe_mod_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u((p_14 || (l_1544 = ((l_1443[3] = ((((0x513497E0L & ((safe_mod_func_uint8_t_u_u(((g_208.f1 = l_1413) && (safe_sub_func_int8_t_s_s((safe_sub_func_uint16_t_u_u(((((safe_lshift_func_int16_t_s_s(((g_208.f1 = (safe_add_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_s((~(p_12 || (g_1279 = (safe_add_func_int32_t_s_s(((((safe_rshift_func_uint8_t_u_s((p_15 != (safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(g_978[5][0], p_12)), 3L))), 2)) ^ g_208.f2) && l_1541) , g_322[1][1]), l_1542[9]))))), g_167[2][2])) , 65532UL), 0x57ADL)) ^ p_14), g_1445))) > l_1543[6]), 10)) , g_66) , 0L) & l_1543[0]), g_1445)), 0x45L))), g_233)) , l_1509[7])) < l_1543[6]) & 0x751BL) <= (-9L))) , 0xBEL))), g_322[1][2])), 0xD51FL)))) , p_14) & p_12) >= p_14)) < 0x58L))), l_1486.f0)) , 1L) > g_976)) & l_1542[8]) | l_1546)) >= l_1543[4]) , (-1L));
                }
              }
            }

          } else {
            int32_t l_1451 = (-5L);

            {
              uint32_t l_1412[5][7][7] = {{{6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L}},
                                          {{6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L}},
                                          {{6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L}},
                                          {{6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L}},
                                          {{6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L},
                                           {6UL, 4UL, 4294967295UL, 0x1FB493A9L,
                                            0x474578C0L, 0UL, 0x8B57FD33L}}};
              int32_t l_1423 = 8L;
              int16_t l_1442 = 0x73C9L;
              uint16_t l_1466[2][5] = {
                  {0x7FBAL, 0x806DL, 0x7FBAL, 0x806DL, 0x7FBAL},
                  {0x7FBAL, 0x806DL, 0x7FBAL, 0x806DL, 0x7FBAL}};
              int i, j, k;
              l_1414 = (safe_lshift_func_uint16_t_u_u(
                  g_322[(g_598 + 1)][g_66],
                  (g_218 =
                       (l_1413 =
                            ((safe_mod_func_int16_t_s_s(
                                 (g_151[g_598][g_66] =
                                      (((safe_lshift_func_uint8_t_u_u(
                                            g_322[(g_598 + 5)][g_66], 3)) >
                                        ((((p_15 |
                                            ((safe_lshift_func_int8_t_s_u(
                                                 (((safe_sub_func_int16_t_s_s(
                                                       ((p_13 <
                                                         ((safe_mod_func_uint8_t_u_u(
                                                              ((safe_add_func_int32_t_s_s(
                                                                   ((safe_add_func_int16_t_s_s(
                                                                        (g_322[(
                                                                             g_598 +
                                                                             1)]
                                                                              [g_66] !=
                                                                         (!(g_25[0] !=
                                                                            g_322[(
                                                                                g_598 +
                                                                                5)]
                                                                                 [g_66]))),
                                                                        (+(~(
                                                                            (g_208,
                                                                             ((safe_rshift_func_uint16_t_u_s(
                                                                                  (l_1410,
                                                                                   g_322[(
                                                                                       g_598 +
                                                                                       5)]
                                                                                        [g_66]),
                                                                                  2)) ||
                                                                              0xD6L)),
                                                                            p_13))))),
                                                                    6L),
                                                                   1L)) |
                                                               p_12),
                                                              p_12)),
                                                          g_322[(g_598 + 5)]
                                                               [g_66])) !=
                                                        p_15),
                                                       g_28[1])) > g_90) !=
                                                  p_14),
                                                 l_1411)) &&
                                             g_167[2][2])),
                                           l_1412[3][5][5]) |
                                          p_15) &
                                         0x6AE9L)) ||
                                       l_1411)),
                                 p_12)) ||
                             g_976)))));
              for (g_208.f1 = (-20); (g_208.f1 < 9);
                   g_208.f1 = safe_add_func_int8_t_s_s(g_208.f1, 9)) {
                int8_t l_1438 = 0xFBL;
                const int32_t l_1439 = 0x4145AAC2L;
                int32_t l_1450 = 0xB303076EL;
                if (((l_1411 ^
                      ((safe_add_func_uint8_t_u_u(
                           (p_12 |
                            (((safe_mod_func_int32_t_s_s(
                                  ((g_976 &&
                                    (((safe_add_func_int16_t_s_s(
                                          g_372, (l_1423 = (l_1412[0][4][2] <=
                                                            0UL)))) <= p_14) !=
                                     ((safe_lshift_func_uint16_t_u_s(
                                          (l_1410.f0, l_1414), 8)) ^
                                      p_14))),
                                   g_67),
                                  0xF02186A5L)) &&
                              0x8DL),
                             g_251)),
                           0xC4L)) |
                       g_233)) <= g_720)) {
                  g_1445 = (safe_mod_func_int16_t_s_s(
                      (safe_lshift_func_int16_t_s_u(
                          (safe_mod_func_int32_t_s_s(
                              ((safe_add_func_uint32_t_u_u(
                                   ((safe_mod_func_int8_t_s_s(
                                        p_12,
                                        (safe_sub_func_int8_t_s_s(
                                            ((g_208,
                                              (((((l_1443[1] =
                                                       (g_322[1][2] =
                                                            (g_25[0] &&
                                                             (((((+(((l_1438 =
                                                                          0x32L) ==
                                                                     (g_978[5]
                                                                           [0] ^
                                                                      ((0xD73CL ||
                                                                        ((g_251 =
                                                                              (((+(((l_1439 ==
                                                                                     ((safe_sub_func_int16_t_s_s(
                                                                                          (g_208,
                                                                                           (g_251 ||
                                                                                            p_13)),
                                                                                          p_15)) <
                                                                                      l_1410
                                                                                          .f2)) &&
                                                                                    (-1L)) <
                                                                                   0x8CD1823FL)) >
                                                                                g_623) >
                                                                               0x6FDB139BL)) <=
                                                                         g_372)),
                                                                       p_12))) >=
                                                                    l_1442)) ^
                                                                 g_372) ^
                                                                p_14) |
                                                               0x51L) <=
                                                              l_1411)))) <
                                                  g_20) <= 1L) &
                                                p_12),
                                               l_1444)),
                                             0L),
                                            p_14)))),
                                    l_1411),
                                   p_14)) > l_1444),
                              0xDC0806FCL)),
                          p_13)),
                      p_14));
                  if (p_13)
                    continue;
                } else {
                  int32_t l_1451 = (-5L);
                  l_1451 = (safe_rshift_func_int16_t_s_s(
                      (safe_sub_func_uint8_t_u_u((l_1450 = p_15), (-2L))), 6));
                  if (g_28[0])
                    break;
                }
                for (l_1411 = 1; (l_1411 <= 4); l_1411 += 1) {
                  int i, j, k;
                  l_1414 =
                      (((((((g_322[g_598][g_598] <
                             (safe_add_func_int32_t_s_s(
                                 ((((((-1L) <=
                                      ((safe_lshift_func_int16_t_s_u(
                                           l_1412[l_1411][l_1411][(g_598 + 3)],
                                           1)) &&
                                       ((((safe_add_func_uint32_t_u_u(
                                              l_1439,
                                              ((1L !=
                                                (((p_12 >=
                                                   ((safe_sub_func_int8_t_s_s(
                                                        (p_12 ==
                                                         (safe_add_func_int8_t_s_s(
                                                             0xA5L,
                                                             ((!(safe_mod_func_uint8_t_u_u(
                                                                  (((safe_rshift_func_int8_t_s_u(
                                                                        (g_66,
                                                                         p_13),
                                                                        0)) |
                                                                    0x49L) &
                                                                   7UL),
                                                                  1L))) <=
                                                              1L)))),
                                                        0xC5L)) &
                                                    g_90)),
                                                  (-2L)) ^
                                                 0L)) |
                                               65535UL))) != l_1438) &&
                                         0xAF341D2CL) > 1L))) >= l_1450),
                                    p_15) >= 0x6DL) != 0xAC20L),
                                 0xC4429022L))) >= l_1411) |
                           0x1B2BL) < p_12) |
                         l_1466[1][0]) |
                        8L) |
                       l_1411);
                  l_1450 = l_1412[l_1411][l_1411][(g_598 + 3)];
                  g_1467 = g_251;
                  if (p_14)
                    continue;
                }
              }
            }
          }

          for (i = 0; i < 6; i++)
            l_1443[i] = 0xC1FE4307L;
        }
      }
      return l_1414;
    }

    for (i = 0; i < 9; i++)
      l_1509[i] = 0x706038CFL;
  }
  for (g_745 = 0; (g_745 <= 5); g_745 += 1) {
    int8_t l_1551[10] = {0x0DL, 0xEDL, 8L, 8L, 0xEDL,
                         0x0DL, 0xEDL, 8L, 8L, 0xEDL};
    uint16_t l_1605 = 1UL;
    int32_t l_1728 = 1L;
    union U0 l_1782[4] = {
        {0x8B812E20L}, {0x1D7486BCL}, {0x8B812E20L}, {0x1D7486BCL}};
    int i;

    for (g_976 = 2; (g_976 >= 0); g_976 -= 1) {
      uint32_t l_1549 = 4294967295UL;
      int32_t l_1575 = (-1L);
      int32_t l_1606 = 1L;
      int8_t l_1790 = 0L;
      if (l_1549) {
        break;
        for (i = 0; i < 9; i++)
          l_1509[i] = 0x706038CFL;
      }

      {
        int8_t l_1551[10] = {0x0DL, 0xEDL, 8L, 8L, 0xEDL,
                             0x0DL, 0xEDL, 8L, 8L, 0xEDL};
        uint16_t l_1605 = 1UL;
        int32_t l_1728 = 1L;
        union U0 l_1782[4] = {
            {0x8B812E20L}, {0x1D7486BCL}, {0x8B812E20L}, {0x1D7486BCL}};
        int i;
        if ((p_12 || 0xA09DL)) {
          if (p_14)
            break;
        } else {
          for (g_251 = 4; (g_251 >= 0); g_251 -= 1) {
            int32_t l_1547 = 1L;
            l_1547 = (0L ^ g_598);
          }
          l_1509[4] = 0L;
          return l_1548;
        }
        for (g_976 = 2; (g_976 >= 0); g_976 -= 1) {
          uint32_t l_1549 = 4294967295UL;
          int32_t l_1575 = (-1L);
          int32_t l_1606 = 1L;
          int8_t l_1790 = 0L;
          if (l_1549)
            break;
            p_14 = ((((g_67 = ((((((g_264 , (l_1551[5] = g_1550[6][2][2])) > 1L) > (safe_mod_func_int32_t_s_s((safe_unary_minus_func_uint8_t_u(((g_251 , g_167[2][2]) && (safe_lshift_func_int8_t_s_u(((g_322[1][2] < (safe_lshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((safe_add_func_int16_t_s_s(((((safe_rshift_func_uint16_t_u_u(((((g_720 ^ (((g_1574 = ((((safe_lshift_func_uint16_t_u_u(((((((safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_u((((g_1467 = (safe_unary_minus_func_int8_t_s(p_15))) <= 1UL) ^ g_90), l_1411)), p_12)) || 0UL) && l_1509[7]) ^ l_1546) && 0xF1EB257FL) < l_1509[7]), 9)) & l_1549) > l_1509[4]) || 0xBD94L)) , 1L) < l_1541)) , g_598) < 1UL) , g_28[0]), l_1548)) && 0x5E0CL) <= g_167[2][4]) < 0xD0L), g_322[5][0])), 0x49C6L)), 2))) || g_218), 6))))), g_25[0]))) && l_1551[5]) <= 255UL) ^ 0x91L)) == 0x3B04L) || g_167[2][5]) > l_1575);
            for (g_20 = 0; (g_20 <= 5); g_20 += 1) {
              uint16_t l_1580 = 0x9D13L;
              int32_t l_1581[9] = {9L, 0xC5AA1793L, 9L,
                                   0xC5AA1793L, 9L, 0xC5AA1793L,
                                   9L, 0xC5AA1793L, 9L};
              int32_t l_1604 = 0x2C77C4BCL;
              int32_t l_1607 = 1L;
              int8_t l_1716 = (-1L);
              int8_t l_1733 = 0xA9L;
              int i;
              l_1607 =
                  (((l_1605 = (safe_lshift_func_int8_t_s_s(
                         (safe_lshift_func_int8_t_s_s(
                             (0L &
                              (l_1509[4] =
                                   (0UL &
                                    ((l_1581[8] = l_1580) ||
                                     (safe_add_func_uint8_t_u_u(
                                         (l_1604 =
                                              (((safe_lshift_func_int16_t_s_u(
                                                    ((safe_add_func_int16_t_s_s(
                                                         g_28[1],
                                                         ((l_1575 =
                                                               (0x41DC1FACL |
                                                                ((safe_lshift_func_uint8_t_u_u(
                                                                     (l_1581[8] =
                                                                          (l_1551
                                                                               [5] <=
                                                                           p_13)),
                                                                     5)),
                                                                 (l_1581[8] = (safe_lshift_func_int16_t_s_u(
                                                                      (((safe_lshift_func_uint16_t_u_s(
                                                                            (safe_add_func_uint32_t_u_u(
                                                                                (safe_sub_func_int32_t_s_s(
                                                                                    (safe_sub_func_uint16_t_u_u(
                                                                                        (((safe_add_func_int8_t_s_s(
                                                                                              (p_12 <
                                                                                               (0L !=
                                                                                                0x836C8943L)),
                                                                                              g_218)),
                                                                                          g_598) ||
                                                                                         g_25[0]),
                                                                                        (-3L))),
                                                                                    g_1467)),
                                                                                l_1548)),
                                                                            l_1509
                                                                                [7])) ^
                                                                        0x1F4FL) |
                                                                       p_13),
                                                                      p_13)))))),
                                                          0xCFCAL))) >
                                                     0xBACA9389L),
                                                    3)) < g_167[2][2]) <
                                               l_1509[7])),
                                         g_67)))))),
                             g_28[2])),
                         7))) < g_1574) |
                   l_1606);
              for (g_1574 = 0; (g_1574 <= 2); g_1574 += 1) {
                int i;
                g_66 = g_28[g_976];
                if (g_1550[0][4][0])
                  break;
                p_14 = p_15;
              }
              if ((((g_28[1] !=
                     ((safe_rshift_func_uint16_t_u_u(
                          (safe_lshift_func_uint16_t_u_s(
                              (((p_14 =
                                     (((p_14 && p_15) <
                                       (0xD5A8L >
                                        (((l_1581[4] <
                                           (safe_lshift_func_int16_t_s_s(
                                               ((0x3EC7L <=
                                                 (safe_sub_func_uint8_t_u_u(
                                                     (0x20F3EF3EL ==
                                                      (safe_sub_func_int32_t_s_s(
                                                          ((~(1L ==
                                                              ((g_251 = (safe_lshift_func_uint16_t_u_s(
                                                                    (safe_sub_func_int32_t_s_s(
                                                                        ((((l_1509[7] =
                                                                                (g_598 = (safe_add_func_int16_t_s_s(
                                                                                     g_598,
                                                                                     0xCE0EL)))),
                                                                           p_13) &&
                                                                          l_1509
                                                                              [6]) ^
                                                                         l_1551
                                                                             [5]),
                                                                        p_14)),
                                                                    6))) ||
                                                               g_233))) !=
                                                           l_1551[5]),
                                                          0x4636B20BL))),
                                                     l_1549))) |
                                                p_14),
                                               g_322[6][0]))) > l_1606),
                                         l_1581[3]))) == g_372)) ==
                                0xBC00AF46L) &
                               l_1551[5]),
                              g_322[1][2])),
                          g_372)) |
                      g_720)) == 1L) |
                   g_28[1])) {
                uint16_t l_1646 = 0x7873L;
                union U0 l_1656 = {0L};
                int16_t l_1665 = 9L;
                int32_t l_1666 = 1L;
                if ((safe_lshift_func_int16_t_s_s(
                        ((safe_add_func_int16_t_s_s(
                             (safe_lshift_func_uint16_t_u_u(
                                 ((g_25[0] ^
                                   ((safe_lshift_func_uint16_t_u_u(
                                        ((safe_lshift_func_uint16_t_u_u(p_12,
                                                                        10)),
                                         0x6FF3L),
                                        (safe_lshift_func_int16_t_s_s(
                                            (l_1581[2] > p_14), 5)))) >
                                    ((g_66 = g_28[1]) !=
                                     (~(safe_mod_func_int32_t_s_s(
                                         (safe_add_func_int16_t_s_s(
                                             g_90,
                                             (((((safe_mod_func_uint8_t_u_u(
                                                     (safe_add_func_uint32_t_u_u(
                                                         ((safe_lshift_func_uint16_t_u_u(
                                                              (g_218 = l_1575),
                                                              (0xF0E2L ^
                                                               65531UL))) <
                                                          g_251),
                                                         g_28[1])),
                                                     g_976)) ||
                                                 g_264) >= p_13) &&
                                               g_167[0][7]) < g_322[1][2]))),
                                         p_13)))))) == g_1467),
                                 g_976)),
                             0xE5FEL)),
                         g_322[4][2]),
                        p_15))) {
                  uint8_t l_1655 = 0UL;
                  l_1646 = (g_90 = 0x3E7C82F2L);
                  g_90 = (safe_add_func_uint32_t_u_u(
                      (p_13 > 0xE6L),
                      (l_1666 =
                           ((safe_add_func_uint32_t_u_u(8UL, l_1605)) >
                            (safe_mod_func_int16_t_s_s(
                                (safe_add_func_uint32_t_u_u(
                                    p_15,
                                    ((l_1655 = 0x9A9DL),
                                     ((l_1656,
                                       (safe_lshift_func_int8_t_s_s(
                                           (g_598 =
                                                (((safe_add_func_uint8_t_u_u(
                                                      ((((0x3906B507L ^
                                                          (safe_lshift_func_uint8_t_u_u(
                                                              (safe_add_func_uint8_t_u_u(
                                                                  l_1656.f2,
                                                                  g_623)),
                                                              1))) ^
                                                         0x2F5AL) >= p_14) &&
                                                       p_15),
                                                      g_218)) != p_12) >=
                                                 l_1655)),
                                           6))),
                                      g_976)))),
                                l_1665))))));
                  g_90 = (safe_add_func_int16_t_s_s(
                      (((((safe_add_func_int8_t_s_s(
                              (safe_rshift_func_uint8_t_u_u(
                                  (+((safe_mod_func_int16_t_s_s(
                                         (l_1675,
                                          (0xFB54L <=
                                           ((g_151[2][2],
                                             ((((safe_mod_func_uint8_t_u_u(
                                                    (((p_15 >=
                                                       ((l_1581[2] ^
                                                         g_167[2][2]) ^
                                                        (safe_mod_func_int8_t_s_s(
                                                            ((p_14 ||
                                                              ((1UL &
                                                                (safe_mod_func_uint32_t_u_u(
                                                                    0x29F9CF69L,
                                                                    g_598))) <=
                                                               g_28[0])) >
                                                             l_1551[0]),
                                                            l_1655)))) &&
                                                      p_15),
                                                     g_167[2][2]),
                                                    p_12)) |
                                                0x5E1682C9L) > l_1575) ==
                                              0x3F7FL)) ^
                                            p_14))),
                                         g_151[2][2])) <= 1L)),
                                  p_15)),
                              7UL)) &
                          0L) |
                         g_90),
                        0x178AL),
                       g_167[2][2]),
                      p_14));
                  if (p_15)
                    break;
                } else {
                  int8_t l_1690 = 0L;
                  int i, j;
                  g_90 =
                      ((((safe_mod_func_int8_t_s_s(
                             ((((safe_rshift_func_uint16_t_u_s(
                                    (((((g_978[0][0] =
                                             ((((safe_rshift_func_uint8_t_u_s(
                                                    (!2UL), 5)) <=
                                                (((safe_rshift_func_uint8_t_u_u(
                                                      (0UL > p_14),
                                                      (p_14,
                                                       (0x3AL &
                                                        (g_264 !=
                                                         (((p_12 = l_1690) ^
                                                           (-8L)) <
                                                          ((l_1607 = g_233) <
                                                           l_1656.f2))))))) <
                                                  g_167[2][2]) < p_15)) &
                                               l_1581[3]) >= l_1690)) |
                                        p_14) != 3L) ||
                                      l_1656.f1) < p_13),
                                    g_28[0])) ||
                                0UL) |
                               p_15) != g_322[3][0]),
                             l_1605)) ^
                         g_25[0]) &
                        g_66) |
                       1UL);
                  p_14 =
                      (((l_1690 &
                         (0xA92DL <
                          ((g_264 ==
                            (g_90 =
                                 ((safe_sub_func_uint32_t_u_u(
                                      (((p_15 = (safe_rshift_func_int8_t_s_s(
                                             (safe_add_func_int8_t_s_s(
                                                 (l_1666 =
                                                      ((0xC3B4L ==
                                                        ((~g_151[2][2]) &
                                                         (((g_322[5][0] >=
                                                            ((l_1606 = (safe_mod_func_uint32_t_u_u(
                                                                  (((g_1706 =
                                                                         (l_1575 ||
                                                                          ((safe_sub_func_int16_t_s_s(
                                                                               (g_167[(
                                                                                    g_976 +
                                                                                    2)][(
                                                                                    g_976 +
                                                                                    4)] =
                                                                                    ((0xCD0432AEL ^
                                                                                      (safe_rshift_func_int8_t_s_s(
                                                                                          0L,
                                                                                          6))) >=
                                                                                     g_1705)),
                                                                               l_1646)) &
                                                                           g_233))) ^
                                                                    l_1575) <=
                                                                   p_12),
                                                                  l_1607))),
                                                             l_1666)) > 7UL) |
                                                          g_151[(g_20 + 2)]
                                                               [g_976]))) &&
                                                       g_978[0][0])),
                                                 0UL)),
                                             6))) &
                                        0x41L) &
                                       p_13),
                                      l_1549)),
                                  l_1551[6]))) < 0L))) ^
                        l_1549) ^
                       p_14);
                  return p_14;
                }
                if (((l_1607 =
                          (((0UL || (safe_lshift_func_uint8_t_u_s(l_1709, 5))) |
                            (safe_add_func_int32_t_s_s(
                                (g_322[4][2] &
                                 (l_1581[2] =
                                      (((l_1604 = ((safe_add_func_int8_t_s_s(
                                                       l_1581[8], l_1716)) ==
                                                   0x053CL)) <=
                                        ((((((l_1411 >= g_233) | g_66), l_1549),
                                           0x78E8BD1EL),
                                          0x33E843D9L),
                                         255UL)) &
                                       0L))),
                                g_28[2]))) ^
                           l_1509[5])) >= l_1605)) {
                  p_14 = 6L;
                  if (l_1717)
                    break;
                  g_90 =
                      ((safe_mod_func_int16_t_s_s(
                           l_1607,
                           (p_14 ||
                            ((((l_1604 =
                                    (g_208,
                                     (+(safe_mod_func_uint16_t_u_u(
                                         ((safe_add_func_uint16_t_u_u(
                                              ((0xE3L >=
                                                ((l_1666 =
                                                      (p_13 &&
                                                       (g_20 ||
                                                        (l_1728 =
                                                             ((safe_rshift_func_int8_t_s_u(
                                                                  l_1606, 4)) ||
                                                              (safe_rshift_func_uint8_t_u_u(
                                                                  ((g_598 =
                                                                        (-4L)) &
                                                                   (l_1581[5] =
                                                                        (g_978[0][0] =
                                                                             l_1665))),
                                                                  2))))))),
                                                 g_1445)) <= 0L),
                                              p_15)) &
                                          4L),
                                         p_13))))) <= g_1706) < 4UL) &
                             l_1656.f2)))) ||
                       l_1666);
                } else {
                  int32_t l_1744 = 0x3580AE79L;
                  int32_t l_1763 = 4L;
                  int i, j;
                  l_1581[1] = (safe_add_func_int32_t_s_s(
                      (((((((l_1733 &
                             ((p_14 < (g_67 = 0UL)) !=
                              ((safe_mod_func_uint8_t_u_u(
                                   (safe_rshift_func_uint8_t_u_s(
                                       ((!((0L ^
                                            ((safe_add_func_uint8_t_u_u(
                                                 (((g_322[0][0] &
                                                    ((l_1606 =
                                                          ((safe_rshift_func_int16_t_s_u(
                                                               ((safe_lshift_func_int16_t_s_u(
                                                                    7L,
                                                                    (l_1656
                                                                         .f0 ==
                                                                     ((((0xAFBBL >=
                                                                         0x7606L),
                                                                        p_14) ==
                                                                       0xF035EB9DL) ^
                                                                      l_1744)))) !=
                                                                p_12),
                                                               7)) > l_1744)) |
                                                     255UL)) ||
                                                   0xD492277CL) &
                                                  g_25[0]),
                                                 l_1549)) ||
                                             p_15)) &&
                                           p_12)),
                                        l_1607),
                                       2)),
                                   255UL)) == p_15))) ^
                            0x91AFL),
                           l_1675.f0),
                          0x722B8D54L) ||
                         p_12) <= 0x7D1DL) >= p_15),
                      l_1551[4]));
                  if (p_13)
                    continue;
                  p_14 =
                      ((safe_add_func_int32_t_s_s(
                           (safe_add_func_uint8_t_u_u(
                               ((safe_sub_func_int16_t_s_s(
                                    p_14,
                                    ((((safe_mod_func_uint16_t_u_u(
                                           (safe_lshift_func_uint16_t_u_s(
                                               (p_12 =
                                                    ((safe_sub_func_uint16_t_u_u(
                                                         0x3BF7L,
                                                         g_1550[6][2][2])) ||
                                                     (((((((((((l_1763 = (safe_lshift_func_uint8_t_u_s(
                                                                    (g_208.f2 <
                                                                     ((p_15 = (safe_lshift_func_uint16_t_u_s(
                                                                           g_20,
                                                                           7))) <=
                                                                      ((g_167[g_745][(
                                                                            g_976 +
                                                                            5)] =
                                                                            0x4A5EL) <
                                                                       (((safe_rshift_func_uint8_t_u_u(
                                                                             (l_1551
                                                                                  [9] ||
                                                                              (l_1604 =
                                                                                   (-1L))),
                                                                             7)) <=
                                                                         (l_1575 = l_1551
                                                                              [5])) &&
                                                                        0xBDL)))),
                                                                    g_978[0]
                                                                         [0]))),
                                                               g_1550[9][0]
                                                                     [2]) ||
                                                              0xC9EDL) |
                                                             p_12) &&
                                                            0xDBL),
                                                           0x7BFEL) > l_1549),
                                                         4294967295UL),
                                                        l_1509[7]) < p_13) <
                                                      p_14))),
                                               g_1279)),
                                           g_66)) ||
                                       2UL) &
                                      l_1549) &
                                     g_745))) ||
                                p_14),
                               p_13)),
                           4294967290UL)) &
                       0x5F9A1599L);
                }
              } else {
                int16_t l_1770 = 8L;
                for (g_208.f1 = 0; (g_208.f1 == 18);
                     g_208.f1 = safe_add_func_uint32_t_u_u(g_208.f1, 7)) {
                  int32_t l_1778 = 0x8C30C565L;
                  int32_t l_1789 = (-1L);
                  l_1790 = (safe_mod_func_int32_t_s_s(
                      ((safe_add_func_uint16_t_u_u(
                           ((((l_1509[7] =
                                   ((((((((l_1770 !=
                                           (safe_sub_func_int32_t_s_s(
                                               (l_1773 != 9UL),
                                               ((safe_rshift_func_uint8_t_u_s(
                                                    (((safe_sub_func_int32_t_s_s(
                                                          (!l_1778),
                                                          (safe_add_func_int8_t_s_s(
                                                              (g_1781 &&
                                                               g_167[2][2]),
                                                              g_90)))) <
                                                      (p_15 =
                                                           (l_1782[0],
                                                            (safe_mod_func_int8_t_s_s(
                                                                (((((safe_rshift_func_int8_t_s_s(
                                                                        (safe_rshift_func_int8_t_s_u(
                                                                            (l_1789 =
                                                                                 1L),
                                                                            g_208
                                                                                .f1)),
                                                                        p_12)) ^
                                                                    0xAD38L) <=
                                                                   8UL) ==
                                                                  p_15) &&
                                                                 g_25[0]),
                                                                0x6AL))))) ||
                                                     p_12),
                                                    l_1778)) > 0L)))) >
                                          g_164) != l_1509[2]) > p_12) >=
                                       0x90A8L) |
                                      l_1581[8]) >= g_20) != g_598)) == p_13) &&
                             4294967286UL),
                            0UL),
                           5UL)) ^
                       l_1607),
                      p_14));
                  g_90 = (safe_rshift_func_int16_t_s_u(
                      (l_1789 =
                           ((8L ==
                             (safe_lshift_func_int8_t_s_u(
                                 (safe_lshift_func_int8_t_s_s(
                                     ((safe_sub_func_int32_t_s_s(
                                          0x70753FD2L,
                                          (((p_15 |
                                             (((g_67 =
                                                    (((p_15,
                                                       (safe_lshift_func_uint8_t_u_s(
                                                           ((((safe_rshift_func_uint8_t_u_s(
                                                                  (0x0D1DL |
                                                                   ((safe_rshift_func_uint16_t_u_u(
                                                                        l_1807,
                                                                        (p_12 =
                                                                             l_1606))),
                                                                    (p_12 =
                                                                         (((((safe_sub_func_uint16_t_u_u(
                                                                                 ((safe_sub_func_uint16_t_u_u(
                                                                                      (+(safe_lshift_func_int16_t_s_u(
                                                                                          g_264,
                                                                                          (g_720 &
                                                                                           0x6CL)))),
                                                                                      l_1411)) ^
                                                                                  l_1509
                                                                                      [5]),
                                                                                 l_1814)) ==
                                                                             l_1549) |
                                                                            g_1781) &&
                                                                           p_14) !=
                                                                          l_1733)))),
                                                                  p_14)) |
                                                              g_151[2][2]) !=
                                                             0x32A5L) !=
                                                            g_167[2][2]),
                                                           l_1778))) >= g_598),
                                                     l_1782[0].f2)),
                                               g_90) > (-1L))) == p_15),
                                           0L))) <= l_1778),
                                     g_28[1])),
                                 p_14))) ||
                            l_1807)),
                      7));
                }
              }
              for (l_1607 = 28; (l_1607 < (-14)); --l_1607) {
                p_14 = (g_208, 0x63FCA2D3L);
                for (g_164 = 0; (g_164 >= 37); g_164++) {
                  uint8_t l_1825 = 0x87L;
                  int32_t l_1828 = 0x3E348266L;
                  l_1828 =
                      (p_14 =
                           ((((((safe_mod_func_uint32_t_u_u(
                                    (safe_lshift_func_int8_t_s_s(
                                        ((((g_322[1][2] =
                                                (safe_lshift_func_uint8_t_u_s(
                                                    ((p_12 = p_12) <=
                                                     ((l_1825 = g_208.f1) >
                                                      l_1717)),
                                                    5))) > 0UL) &
                                          l_1551[0]) !=
                                         (((l_1604 !=
                                            (((g_20 |
                                               (0UL &&
                                                (safe_mod_func_int8_t_s_s(
                                                    p_13, l_1549)))) &
                                              4294967295UL) |
                                             p_15)),
                                           p_14) != g_66)),
                                        g_1550[6][2][2])),
                                    l_1828)),
                                g_623) <= g_978[4][0]) ^
                              (-1L)) ||
                             p_14),
                            0xA4C9F1D9L));
                }
                p_14 = (-1L);
              }
            }
        }
      }

      for (g_20 = 0; (g_20 <= 5); g_20 += 1) {
        uint16_t l_1580 = 0x9D13L;
        int32_t l_1581[9] = {9L, 0xC5AA1793L, 9L, 0xC5AA1793L, 9L, 0xC5AA1793L,
                             9L, 0xC5AA1793L, 9L};
        int32_t l_1604 = 0x2C77C4BCL;
        int32_t l_1607 = 1L;
        int8_t l_1716 = (-1L);
        int8_t l_1733 = 0xA9L;
        int i = 0;

        l_1509[i] = 0x706038CFL;

        for (g_20 = 0; (g_20 <= 5); g_20 += 1) {
          uint16_t l_1580 = 0x9D13L;
          int32_t l_1581[9] = {9L, 0xC5AA1793L, 9L,
                               0xC5AA1793L, 9L, 0xC5AA1793L,
                               9L, 0xC5AA1793L, 9L};
          int32_t l_1604 = 0x2C77C4BCL;
          int32_t l_1607 = 1L;
          int8_t l_1716 = (-1L);
          int8_t l_1733 = 0xA9L;
          int i;
          l_1607 =
              (((l_1605 = (safe_lshift_func_int8_t_s_s(
                     (safe_lshift_func_int8_t_s_s(
                         (0L &
                          (l_1509[4] =
                               (0UL &
                                ((l_1581[8] = l_1580) ||
                                 (safe_add_func_uint8_t_u_u(
                                     (l_1604 =
                                          (((safe_lshift_func_int16_t_s_u(
                                                ((safe_add_func_int16_t_s_s(
                                                     g_28[1],
                                                     ((l_1575 =
                                                           (0x41DC1FACL |
                                                            ((safe_lshift_func_uint8_t_u_u(
                                                                 (l_1581[8] =
                                                                      (l_1551
                                                                           [5] <=
                                                                       p_13)),
                                                                 5)),
                                                             (l_1581[8] = (safe_lshift_func_int16_t_s_u(
                                                                  (((safe_lshift_func_uint16_t_u_s(
                                                                        (safe_add_func_uint32_t_u_u(
                                                                            (safe_sub_func_int32_t_s_s(
                                                                                (safe_sub_func_uint16_t_u_u(
                                                                                    (((safe_add_func_int8_t_s_s(
                                                                                          (p_12 <
                                                                                           (0L !=
                                                                                            0x836C8943L)),
                                                                                          g_218)),
                                                                                      g_598) ||
                                                                                     g_25[0]),
                                                                                    (-3L))),
                                                                                g_1467)),
                                                                            l_1548)),
                                                                        l_1509
                                                                            [7])) ^
                                                                    0x1F4FL) |
                                                                   p_13),
                                                                  p_13)))))),
                                                      0xCFCAL))) > 0xBACA9389L),
                                                3)) < g_167[2][2]) <
                                           l_1509[7])),
                                     g_67)))))),
                         g_28[2])),
                     7))) < g_1574) |
               l_1606);
          for (g_1574 = 0; (g_1574 <= 2); g_1574 += 1) {
            int i;
            g_66 = g_28[g_976];
            if (g_1550[0][4][0])
              break;
            p_14 = p_15;
          }
          if ((((g_28[1] !=
                 ((safe_rshift_func_uint16_t_u_u(
                      (safe_lshift_func_uint16_t_u_s(
                          (((p_14 =
                                 (((p_14 && p_15) <
                                   (0xD5A8L >
                                    (((l_1581[4] <
                                       (safe_lshift_func_int16_t_s_s(
                                           ((0x3EC7L <=
                                             (safe_sub_func_uint8_t_u_u(
                                                 (0x20F3EF3EL ==
                                                  (safe_sub_func_int32_t_s_s(
                                                      ((~(1L ==
                                                          ((g_251 = (safe_lshift_func_uint16_t_u_s(
                                                                (safe_sub_func_int32_t_s_s(
                                                                    ((((l_1509[7] =
                                                                            (g_598 = (safe_add_func_int16_t_s_s(
                                                                                 g_598,
                                                                                 0xCE0EL)))),
                                                                       p_13) &&
                                                                      l_1509
                                                                          [6]) ^
                                                                     l_1551[5]),
                                                                    p_14)),
                                                                6))) ||
                                                           g_233))) !=
                                                       l_1551[5]),
                                                      0x4636B20BL))),
                                                 l_1549))) |
                                            p_14),
                                           g_322[6][0]))) > l_1606),
                                     l_1581[3]))) == g_372)) == 0xBC00AF46L) &
                           l_1551[5]),
                          g_322[1][2])),
                      g_372)) |
                  g_720)) == 1L) |
               g_28[1])) {
            uint16_t l_1646 = 0x7873L;
            union U0 l_1656 = {0L};
            int16_t l_1665 = 9L;
            int32_t l_1666 = 1L;
            if ((safe_lshift_func_int16_t_s_s(
                    ((safe_add_func_int16_t_s_s(
                         (safe_lshift_func_uint16_t_u_u(
                             ((g_25[0] ^
                               ((safe_lshift_func_uint16_t_u_u(
                                    ((safe_lshift_func_uint16_t_u_u(p_12, 10)),
                                     0x6FF3L),
                                    (safe_lshift_func_int16_t_s_s(
                                        (l_1581[2] > p_14), 5)))) >
                                ((g_66 = g_28[1]) !=
                                 (~(safe_mod_func_int32_t_s_s(
                                     (safe_add_func_int16_t_s_s(
                                         g_90,
                                         (((((safe_mod_func_uint8_t_u_u(
                                                 (safe_add_func_uint32_t_u_u(
                                                     ((safe_lshift_func_uint16_t_u_u(
                                                          (g_218 = l_1575),
                                                          (0xF0E2L ^
                                                           65531UL))) < g_251),
                                                     g_28[1])),
                                                 g_976)) ||
                                             g_264) >= p_13) &&
                                           g_167[0][7]) < g_322[1][2]))),
                                     p_13)))))) == g_1467),
                             g_976)),
                         0xE5FEL)),
                     g_322[4][2]),
                    p_15))) {
              uint8_t l_1655 = 0UL;
              l_1646 = (g_90 = 0x3E7C82F2L);
              g_90 = (safe_add_func_uint32_t_u_u(
                  (p_13 > 0xE6L),
                  (l_1666 =
                       ((safe_add_func_uint32_t_u_u(8UL, l_1605)) >
                        (safe_mod_func_int16_t_s_s(
                            (safe_add_func_uint32_t_u_u(
                                p_15,
                                ((l_1655 = 0x9A9DL),
                                 ((l_1656,
                                   (safe_lshift_func_int8_t_s_s(
                                       (g_598 =
                                            (((safe_add_func_uint8_t_u_u(
                                                  ((((0x3906B507L ^
                                                      (safe_lshift_func_uint8_t_u_u(
                                                          (safe_add_func_uint8_t_u_u(
                                                              l_1656.f2,
                                                              g_623)),
                                                          1))) ^
                                                     0x2F5AL) >= p_14) &&
                                                   p_15),
                                                  g_218)) != p_12) >= l_1655)),
                                       6))),
                                  g_976)))),
                            l_1665))))));
              g_90 = (safe_add_func_int16_t_s_s(
                  (((((safe_add_func_int8_t_s_s(
                          (safe_rshift_func_uint8_t_u_u(
                              (+((safe_mod_func_int16_t_s_s(
                                     (l_1675,
                                      (0xFB54L <=
                                       ((g_151[2][2],
                                         ((((safe_mod_func_uint8_t_u_u(
                                                (((p_15 >=
                                                   ((l_1581[2] ^ g_167[2][2]) ^
                                                    (safe_mod_func_int8_t_s_s(
                                                        ((p_14 ||
                                                          ((1UL &
                                                            (safe_mod_func_uint32_t_u_u(
                                                                0x29F9CF69L,
                                                                g_598))) <=
                                                           g_28[0])) >
                                                         l_1551[0]),
                                                        l_1655)))) &&
                                                  p_15),
                                                 g_167[2][2]),
                                                p_12)) |
                                            0x5E1682C9L) > l_1575) ==
                                          0x3F7FL)) ^
                                        p_14))),
                                     g_151[2][2])) <= 1L)),
                              p_15)),
                          7UL)) &
                      0L) |
                     g_90),
                    0x178AL),
                   g_167[2][2]),
                  p_14));
              if (p_15)
                break;
            } else {
              int8_t l_1690 = 0L;
              int i, j;
              g_90 =
                  ((((safe_mod_func_int8_t_s_s(
                         ((((safe_rshift_func_uint16_t_u_s(
                                (((((g_978[0][0] =
                                         ((((safe_rshift_func_uint8_t_u_s(
                                                (!2UL), 5)) <=
                                            (((safe_rshift_func_uint8_t_u_u(
                                                  (0UL > p_14),
                                                  (p_14, (0x3AL &
                                                          (g_264 !=
                                                           (((p_12 = l_1690) ^
                                                             (-8L)) <
                                                            ((l_1607 = g_233) <
                                                             l_1656.f2))))))) <
                                              g_167[2][2]) < p_15)) &
                                           l_1581[3]) >= l_1690)) |
                                    p_14) != 3L) ||
                                  l_1656.f1) < p_13),
                                g_28[0])) ||
                            0UL) |
                           p_15) != g_322[3][0]),
                         l_1605)) ^
                     g_25[0]) &
                    g_66) |
                   1UL);
              p_14 =
                  (((l_1690 &
                     (0xA92DL <
                      ((g_264 ==
                        (g_90 =
                             ((safe_sub_func_uint32_t_u_u(
                                  (((p_15 = (safe_rshift_func_int8_t_s_s(
                                         (safe_add_func_int8_t_s_s(
                                             (l_1666 =
                                                  ((0xC3B4L ==
                                                    ((~g_151[2][2]) &
                                                     (((g_322[5][0] >=
                                                        ((l_1606 = (safe_mod_func_uint32_t_u_u(
                                                              (((g_1706 =
                                                                     (l_1575 ||
                                                                      ((safe_sub_func_int16_t_s_s(
                                                                           (g_167[(
                                                                                g_976 +
                                                                                2)][(
                                                                                g_976 +
                                                                                4)] =
                                                                                ((0xCD0432AEL ^
                                                                                  (safe_rshift_func_int8_t_s_s(
                                                                                      0L,
                                                                                      6))) >=
                                                                                 g_1705)),
                                                                           l_1646)) &
                                                                       g_233))) ^
                                                                l_1575) <=
                                                               p_12),
                                                              l_1607))),
                                                         l_1666)) > 7UL) |
                                                      g_151[(g_20 + 2)]
                                                           [g_976]))) &&
                                                   g_978[0][0])),
                                             0UL)),
                                         6))) &
                                    0x41L) &
                                   p_13),
                                  l_1549)),
                              l_1551[6]))) < 0L))) ^
                    l_1549) ^
                   p_14);
              return p_14;
            }
            if (((l_1607 =
                      (((0UL || (safe_lshift_func_uint8_t_u_s(l_1709, 5))) |
                        (safe_add_func_int32_t_s_s(
                            (g_322[4][2] &
                             (l_1581[2] =
                                  (((l_1604 = ((safe_add_func_int8_t_s_s(
                                                   l_1581[8], l_1716)) ==
                                               0x053CL)) <=
                                    ((((((l_1411 >= g_233) | g_66), l_1549),
                                       0x78E8BD1EL),
                                      0x33E843D9L),
                                     255UL)) &
                                   0L))),
                            g_28[2]))) ^
                       l_1509[5])) >= l_1605)) {
              p_14 = 6L;
              if (l_1717)
                break;
              g_90 =
                  ((safe_mod_func_int16_t_s_s(
                       l_1607,
                       (p_14 ||
                        ((((l_1604 =
                                (g_208,
                                 (+(safe_mod_func_uint16_t_u_u(
                                     ((safe_add_func_uint16_t_u_u(
                                          ((0xE3L >=
                                            ((l_1666 =
                                                  (p_13 &&
                                                   (g_20 ||
                                                    (l_1728 =
                                                         ((safe_rshift_func_int8_t_s_u(
                                                              l_1606, 4)) ||
                                                          (safe_rshift_func_uint8_t_u_u(
                                                              ((g_598 = (-4L)) &
                                                               (l_1581[5] =
                                                                    (g_978[0][0] =
                                                                         l_1665))),
                                                              2))))))),
                                             g_1445)) <= 0L),
                                          p_15)) &
                                      4L),
                                     p_13))))) <= g_1706) < 4UL) &
                         l_1656.f2)))) ||
                   l_1666);
            } else {
              int32_t l_1744 = 0x3580AE79L;
              int32_t l_1763 = 4L;
              int i, j;
              l_1581[1] = (safe_add_func_int32_t_s_s(
                  (((((((l_1733 &
                         ((p_14 < (g_67 = 0UL)) !=
                          ((safe_mod_func_uint8_t_u_u(
                               (safe_rshift_func_uint8_t_u_s(
                                   ((!((0L ^
                                        ((safe_add_func_uint8_t_u_u(
                                             (((g_322[0][0] &
                                                ((l_1606 =
                                                      ((safe_rshift_func_int16_t_s_u(
                                                           ((safe_lshift_func_int16_t_s_u(
                                                                7L,
                                                                (l_1656.f0 ==
                                                                 ((((0xAFBBL >=
                                                                     0x7606L),
                                                                    p_14) ==
                                                                   0xF035EB9DL) ^
                                                                  l_1744)))) !=
                                                            p_12),
                                                           7)) > l_1744)) |
                                                 255UL)) ||
                                               0xD492277CL) &
                                              g_25[0]),
                                             l_1549)) ||
                                         p_15)) &&
                                       p_12)),
                                    l_1607),
                                   2)),
                               255UL)) == p_15))) ^
                        0x91AFL),
                       l_1675.f0),
                      0x722B8D54L) ||
                     p_12) <= 0x7D1DL) >= p_15),
                  l_1551[4]));
              if (p_13)
                continue;
              p_14 =
                  ((safe_add_func_int32_t_s_s(
                       (safe_add_func_uint8_t_u_u(
                           ((safe_sub_func_int16_t_s_s(
                                p_14,
                                ((((safe_mod_func_uint16_t_u_u(
                                       (safe_lshift_func_uint16_t_u_s(
                                           (p_12 =
                                                ((safe_sub_func_uint16_t_u_u(
                                                     0x3BF7L,
                                                     g_1550[6][2][2])) ||
                                                 (((((((((((l_1763 = (safe_lshift_func_uint8_t_u_s(
                                                                (g_208.f2 <
                                                                 ((p_15 =
                                                                       (safe_lshift_func_uint16_t_u_s(
                                                                           g_20,
                                                                           7))) <=
                                                                  ((g_167[g_745][(
                                                                        g_976 +
                                                                        5)] =
                                                                        0x4A5EL) <
                                                                   (((safe_rshift_func_uint8_t_u_u(
                                                                         (l_1551
                                                                              [9] ||
                                                                          (l_1604 =
                                                                               (-1L))),
                                                                         7)) <=
                                                                     (l_1575 = l_1551
                                                                          [5])) &&
                                                                    0xBDL)))),
                                                                g_978[0][0]))),
                                                           g_1550[9][0][2]) ||
                                                          0xC9EDL) |
                                                         p_12) &&
                                                        0xDBL),
                                                       0x7BFEL) > l_1549),
                                                     4294967295UL),
                                                    l_1509[7]) < p_13) <
                                                  p_14))),
                                           g_1279)),
                                       g_66)) ||
                                   2UL) &
                                  l_1549) &
                                 g_745))) ||
                            p_14),
                           p_13)),
                       4294967290UL)) &
                   0x5F9A1599L);
            }
          } else {
            int16_t l_1770 = 8L;
            for (g_208.f1 = 0; (g_208.f1 == 18);
                 g_208.f1 = safe_add_func_uint32_t_u_u(g_208.f1, 7)) {
              int32_t l_1778 = 0x8C30C565L;
              int32_t l_1789 = (-1L);
              l_1790 = (safe_mod_func_int32_t_s_s(
                  ((safe_add_func_uint16_t_u_u(
                       ((((l_1509[7] =
                               ((((((((l_1770 !=
                                       (safe_sub_func_int32_t_s_s(
                                           (l_1773 != 9UL),
                                           ((safe_rshift_func_uint8_t_u_s(
                                                (((safe_sub_func_int32_t_s_s(
                                                      (!l_1778),
                                                      (safe_add_func_int8_t_s_s(
                                                          (g_1781 &&
                                                           g_167[2][2]),
                                                          g_90)))) <
                                                  (p_15 =
                                                       (l_1782[0],
                                                        (safe_mod_func_int8_t_s_s(
                                                            (((((safe_rshift_func_int8_t_s_s(
                                                                    (safe_rshift_func_int8_t_s_u(
                                                                        (l_1789 =
                                                                             1L),
                                                                        g_208
                                                                            .f1)),
                                                                    p_12)) ^
                                                                0xAD38L) <=
                                                               8UL) == p_15) &&
                                                             g_25[0]),
                                                            0x6AL))))) ||
                                                 p_12),
                                                l_1778)) > 0L)))) > g_164) !=
                                     l_1509[2]) > p_12) >= 0x90A8L) |
                                  l_1581[8]) >= g_20) != g_598)) == p_13) &&
                         4294967286UL),
                        0UL),
                       5UL)) ^
                   l_1607),
                  p_14));
              g_90 = (safe_rshift_func_int16_t_s_u(
                  (l_1789 =
                       ((8L ==
                         (safe_lshift_func_int8_t_s_u(
                             (safe_lshift_func_int8_t_s_s(
                                 ((safe_sub_func_int32_t_s_s(
                                      0x70753FD2L,
                                      (((p_15 |
                                         (((g_67 =
                                                (((p_15,
                                                   (safe_lshift_func_uint8_t_u_s(
                                                       ((((safe_rshift_func_uint8_t_u_s(
                                                              (0x0D1DL |
                                                               ((safe_rshift_func_uint16_t_u_u(
                                                                    l_1807,
                                                                    (p_12 =
                                                                         l_1606))),
                                                                (p_12 =
                                                                     (((((safe_sub_func_uint16_t_u_u(
                                                                             ((safe_sub_func_uint16_t_u_u(
                                                                                  (+(safe_lshift_func_int16_t_s_u(
                                                                                      g_264,
                                                                                      (g_720 &
                                                                                       0x6CL)))),
                                                                                  l_1411)) ^
                                                                              l_1509
                                                                                  [5]),
                                                                             l_1814)) ==
                                                                         l_1549) |
                                                                        g_1781) &&
                                                                       p_14) !=
                                                                      l_1733)))),
                                                              p_14)) |
                                                          g_151[2][2]) !=
                                                         0x32A5L) !=
                                                        g_167[2][2]),
                                                       l_1778))) >= g_598),
                                                 l_1782[0].f2)),
                                           g_90) > (-1L))) == p_15),
                                       0L))) <= l_1778),
                                 g_28[1])),
                             p_14))) ||
                        l_1807)),
                  7));
            }
          }
          for (l_1607 = 28; (l_1607 < (-14)); --l_1607) {
            p_14 = (g_208, 0x63FCA2D3L);
            for (g_164 = 0; (g_164 >= 37); g_164++) {
              uint8_t l_1825 = 0x87L;
              int32_t l_1828 = 0x3E348266L;
              l_1828 =
                  (p_14 = ((((((safe_mod_func_uint32_t_u_u(
                                   (safe_lshift_func_int8_t_s_s(
                                       ((((g_322[1][2] =
                                               (safe_lshift_func_uint8_t_u_s(
                                                   ((p_12 = p_12) <=
                                                    ((l_1825 = g_208.f1) >
                                                     l_1717)),
                                                   5))) > 0UL) &
                                         l_1551[0]) !=
                                        (((l_1604 !=
                                           (((g_20 |
                                              (0UL && (safe_mod_func_int8_t_s_s(
                                                          p_13, l_1549)))) &
                                             4294967295UL) |
                                            p_15)),
                                          p_14) != g_66)),
                                       g_1550[6][2][2])),
                                   l_1828)),
                               g_623) <= g_978[4][0]) ^
                             (-1L)) ||
                            p_14),
                           0xA4C9F1D9L));
            }
            p_14 = (-1L);
          }
        }

        for (g_1574 = 0; (g_1574 <= 2); g_1574 += 1) {
          int i;
          g_66 = g_28[g_976];
          if (g_1550[0][4][0])
            break;
          p_14 = p_15;
        }

        for (l_1607 = 28; (l_1607 < (-14)); --l_1607) {
          p_14 = (g_208, 0x63FCA2D3L);
          l_1607 =
              (((l_1605 = (safe_lshift_func_int8_t_s_s(
                     (safe_lshift_func_int8_t_s_s(
                         (0L &
                          (l_1509[4] =
                               (0UL &
                                ((l_1581[8] = l_1580) ||
                                 (safe_add_func_uint8_t_u_u(
                                     (l_1604 =
                                          (((safe_lshift_func_int16_t_s_u(
                                                ((safe_add_func_int16_t_s_s(
                                                     g_28[1],
                                                     ((l_1575 =
                                                           (0x41DC1FACL |
                                                            ((safe_lshift_func_uint8_t_u_u(
                                                                 (l_1581[8] =
                                                                      (l_1551
                                                                           [5] <=
                                                                       p_13)),
                                                                 5)),
                                                             (l_1581[8] = (safe_lshift_func_int16_t_s_u(
                                                                  (((safe_lshift_func_uint16_t_u_s(
                                                                        (safe_add_func_uint32_t_u_u(
                                                                            (safe_sub_func_int32_t_s_s(
                                                                                (safe_sub_func_uint16_t_u_u(
                                                                                    (((safe_add_func_int8_t_s_s(
                                                                                          (p_12 <
                                                                                           (0L !=
                                                                                            0x836C8943L)),
                                                                                          g_218)),
                                                                                      g_598) ||
                                                                                     g_25[0]),
                                                                                    (-3L))),
                                                                                g_1467)),
                                                                            l_1548)),
                                                                        l_1509
                                                                            [7])) ^
                                                                    0x1F4FL) |
                                                                   p_13),
                                                                  p_13)))))),
                                                      0xCFCAL))) > 0xBACA9389L),
                                                3)) < g_167[2][2]) <
                                           l_1509[7])),
                                     g_67)))))),
                         g_28[2])),
                     7))) < g_1574) |
               l_1606);

          for (g_164 = 0; (g_164 >= 37); g_164++) {
            uint8_t l_1825 = 0x87L;
            int32_t l_1828 = 0x3E348266L;

            if (l_1549)
              break;
          }

          p_14 = (-1L);
        }
      }
    }
  }
  if (((safe_mod_func_int16_t_s_s(
           ((safe_add_func_int32_t_s_s(
                ((l_1847 =
                      ((safe_unary_minus_func_int8_t_s(
                           (g_28[2] ^ (g_745 = (l_1509[2] = g_164))))) >
                       (safe_sub_func_uint16_t_u_u(
                           p_12,
                           (l_1546 >=
                            (safe_mod_func_uint16_t_u_u(
                                (safe_mod_func_uint16_t_u_u(
                                    (0xAB47L >=
                                     ((l_1846 =
                                           ((safe_mod_func_int32_t_s_s(
                                                ((g_1279 = (~(
                                                      g_151[2][2] =
                                                          ((l_1845 =
                                                                ((p_14 =
                                                                      ((l_1842 =
                                                                            (!g_978
                                                                                 [0]
                                                                                 [0])) ==
                                                                       ((safe_lshift_func_uint8_t_u_s(
                                                                            (g_976 ==
                                                                             ((((+l_1675
                                                                                      .f1) &
                                                                                (g_1706 ==
                                                                                 p_14)) ||
                                                                               g_720) <
                                                                              l_1675
                                                                                  .f0)),
                                                                            1)),
                                                                        0x27L))) >=
                                                                 l_1675.f2)) |
                                                           l_1807)))) ||
                                                 0x1E85L),
                                                l_1814)) |
                                            l_1548)),
                                      g_976)),
                                    l_1541)),
                                (-1L)))))))) &
                 l_1773),
                g_164)) >= 4294967287UL),
           0xEDB3L)) == p_13)) {
    uint32_t l_1863 = 0xB1A28FDCL;
    const uint16_t l_1869 = 0x72CEL;
    int32_t l_1888 = 0x36F4EC01L;
    uint8_t l_1895 = 0xDFL;
    uint32_t l_1905[2][3];
    int i, j;
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 3; j++)
        ;
    }
    for (g_67 = 0; (g_67 < 35); ++g_67) {
      uint16_t l_1856 = 0UL;
      int32_t l_1868 = 1L;
      int32_t l_1887 = (-2L);

      l_1509[2] = p_14;
      if (((safe_mod_func_int16_t_s_s(
               ((safe_add_func_int32_t_s_s(
                    ((l_1847 =
                          ((safe_unary_minus_func_int8_t_s(
                               (g_28[2] ^ (g_745 = (l_1509[2] = g_164))))) >
                           (safe_sub_func_uint16_t_u_u(
                               p_12,
                               (l_1546 >=
                                (safe_mod_func_uint16_t_u_u(
                                    (safe_mod_func_uint16_t_u_u(
                                        (0xAB47L >=
                                         ((l_1846 =
                                               ((safe_mod_func_int32_t_s_s(
                                                    ((g_1279 = (~(
                                                          g_151[2][2] =
                                                              ((l_1845 =
                                                                    ((p_14 =
                                                                          ((l_1842 =
                                                                                (!g_978
                                                                                     [0]
                                                                                     [0])) ==
                                                                           ((safe_lshift_func_uint8_t_u_s(
                                                                                (g_976 ==
                                                                                 ((((+l_1675
                                                                                          .f1) &
                                                                                    (g_1706 ==
                                                                                     p_14)) ||
                                                                                   g_720) <
                                                                                  l_1675
                                                                                      .f0)),
                                                                                1)),
                                                                            0x27L))) >=
                                                                     l_1675
                                                                         .f2)) |
                                                               l_1807)))) ||
                                                     0x1E85L),
                                                    l_1814)) |
                                                l_1548)),
                                          g_976)),
                                        l_1541)),
                                    (-1L)))))))) &
                     l_1773),
                    g_164)) >= 4294967287UL),
               0xEDB3L)) == p_13)) {
        uint32_t l_1863 = 0xB1A28FDCL;
        const uint16_t l_1869 = 0x72CEL;
        int32_t l_1888 = 0x36F4EC01L;
        uint8_t l_1895 = 0xDFL;
        uint32_t l_1905[2][3];
        int i, j;
        for (i = 0; i < 2; i++) {
          for (j = 0; j < 3; j++)
            l_1905[i][j] = 4294967289UL;
        }
        for (g_67 = 0; (g_67 < 35); ++g_67) {
          uint16_t l_1856 = 0UL;
          int32_t l_1868 = 1L;
          int32_t l_1887 = (-2L);
          p_14 =
              (g_264,
               ((g_66 =
                     (((p_12 >=
                        (safe_rshift_func_int8_t_s_s(
                            l_1807,
                            ((((safe_lshift_func_uint16_t_u_s(
                                   ((0x7DD154ACL <=
                                     (0x49L <
                                      (safe_rshift_func_uint8_t_u_s(
                                          (l_1856 <
                                           ((((((((((l_1847 = p_12) >= g_1279) >
                                                   ((safe_lshift_func_int16_t_s_u(
                                                        (safe_mod_func_int16_t_s_s(
                                                            ((((safe_add_func_int16_t_s_s(
                                                                   l_1863,
                                                                   l_1856)) ||
                                                               255UL) == g_67) &
                                                             p_12),
                                                            l_1856)),
                                                        l_1856)),
                                                    g_20)) >= l_1863) >
                                                 0xF526L) ||
                                                3UL) <= 0xEB65BACBL),
                                              0xEB62L) <= l_1546) != 0xBDL)),
                                          1)))),
                                    p_13),
                                   l_1863)),
                               0x0DEEL) >= p_12) ^
                             255UL)))) |
                       p_12) < p_15)) ^
                g_25[0]));
          g_90 =
              (g_218 < ((((l_1856 &&
                           (l_1675.f1 ||
                            ((safe_lshift_func_int8_t_s_u(
                                 (p_12 <= (safe_rshift_func_int8_t_s_u(
                                              (((l_1868 = (+(g_28[1] >= 1UL))) &
                                                (((((-5L) != 0x9A51L), p_13) |
                                                  l_1863) == l_1863)),
                                               1L),
                                              0))),
                                 3)) >= g_720))) < l_1869) > g_218) &
                        l_1863));
          l_1509[2] = p_14;
          p_14 =
              ((safe_rshift_func_uint16_t_u_u(
                   ((l_1863 >=
                     ((safe_lshift_func_int16_t_s_s(p_15, (0x76L <= (-3L)))) >=
                      (!((g_1706 !=
                          ((safe_add_func_int16_t_s_s(
                               (l_1888 =
                                    ((((+((safe_rshift_func_uint8_t_u_s(
                                              (l_1856 <= l_1868),
                                              (safe_sub_func_uint16_t_u_u(
                                                  ((safe_sub_func_int8_t_s_s(
                                                       (((safe_add_func_uint8_t_u_u(
                                                             g_218,
                                                             (((l_1887 = (~(
                                                                    (safe_rshift_func_uint8_t_u_u(
                                                                        (l_1886 =
                                                                             (p_14 |
                                                                              g_322
                                                                                  [0]
                                                                                  [0])),
                                                                        p_14)) >=
                                                                    0xF525L))) <
                                                               0xE190F681L),
                                                              0xE6L))) |
                                                         g_151[2][2]) < p_14),
                                                       (-10L))) &&
                                                   0xE1A2L),
                                                  65535UL)))) ^
                                          0xC5038752L)),
                                       8UL) ^
                                      g_1574) >= 0UL)),
                               l_1869)) == 0xBEL)) == g_978[0][0])))) > g_66),
                   g_1706)) == (-6L));
        }
        l_1905[1][2] =
            (((g_208,
               ((g_208.f0 = (safe_rshift_func_int16_t_s_s(
                     ((safe_add_func_int8_t_s_s(
                          ((65535UL ||
                            (p_12 =
                                 ((p_12,
                                   (safe_lshift_func_int8_t_s_u(
                                       (((l_1895 ^
                                          (safe_mod_func_int16_t_s_s(
                                              p_15,
                                              (((safe_mod_func_int32_t_s_s(
                                                    l_1869, g_28[1])) ==
                                                ((l_1842 =
                                                      (p_14 !=
                                                       (safe_rshift_func_uint16_t_u_s(
                                                           (safe_add_func_uint32_t_u_u(
                                                               (1L ||
                                                                g_978[0][0]),
                                                               l_1541)),
                                                           l_1869)))) <
                                                 g_745)) &&
                                               0xB00DAB19L)))) != l_1888) <
                                        l_1904),
                                       p_14))) |
                                  l_1869))) > l_1869),
                          p_15)),
                      g_1445),
                     p_15))),
                g_20)),
              g_1550[4][1][2]) == 0x25B26E43L);
      } else {
        int32_t l_1912 = 1L;
        int32_t l_1915[1][7][5] = {
            {{4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L},
             {4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L},
             {4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L},
             {4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L},
             {4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L},
             {4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L},
             {4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L}}};
        uint32_t l_1917 = 3UL;
        int i, j, k;
        l_1917 =
            ((safe_lshift_func_int8_t_s_u(
                 ((safe_mod_func_int32_t_s_s(
                      (safe_sub_func_int32_t_s_s(
                          ((l_1912 >=
                            (l_1915[0][6][2] =
                                 ((((0x6267L || 0L) <
                                    ((l_1912 < l_1717) <=
                                     (g_20 = ((p_15 = g_978[2][0]) < 0UL)))) ||
                                   3UL) ||
                                  (((safe_rshift_func_int8_t_s_s(
                                        (p_12 & 0x4B7BL), g_208.f2)) ^
                                    l_1912) >= 0x7FL)))),
                           0L),
                          g_1279)),
                      l_1509[7])),
                  p_14),
                 g_1916)) > p_13);
        g_90 = 0xBB08448AL;
      }

      p_14 =
          ((safe_rshift_func_uint16_t_u_u(
               ((l_1863 >=
                 ((safe_lshift_func_int16_t_s_s(p_15, (0x76L <= (-3L)))) >=
                  (!((g_1706 !=
                      ((safe_add_func_int16_t_s_s(
                           (l_1888 =
                                ((((+((safe_rshift_func_uint8_t_u_s(
                                          (l_1856 <= l_1868),
                                          (safe_sub_func_uint16_t_u_u(
                                              ((safe_sub_func_int8_t_s_s(
                                                   (((safe_add_func_uint8_t_u_u(
                                                         g_218,
                                                         (((l_1887 = (~(
                                                                (safe_rshift_func_uint8_t_u_u(
                                                                    (l_1886 =
                                                                         (p_14 |
                                                                          g_322
                                                                              [0]
                                                                              [0])),
                                                                    p_14)) >=
                                                                0xF525L))) <
                                                           0xE190F681L),
                                                          0xE6L))) |
                                                     g_151[2][2]) < p_14),
                                                   (-10L))) &&
                                               0xE1A2L),
                                              65535UL)))) ^
                                      0xC5038752L)),
                                   8UL) ^
                                  g_1574) >= 0UL)),
                           l_1869)) == 0xBEL)) == g_978[0][0])))) > g_66),
               g_1706)) == (-6L));
    }
    l_1905[1][2] =
        (((g_208,
           ((g_208.f0 = (safe_rshift_func_int16_t_s_s(
                 ((safe_add_func_int8_t_s_s(
                      ((65535UL ||
                        (p_12 =
                             ((p_12,
                               (safe_lshift_func_int8_t_s_u(
                                   (((l_1895 ^
                                      (safe_mod_func_int16_t_s_s(
                                          p_15,
                                          (((safe_mod_func_int32_t_s_s(
                                                l_1869, g_28[1])) ==
                                            ((l_1842 =
                                                  (p_14 !=
                                                   (safe_rshift_func_uint16_t_u_s(
                                                       (safe_add_func_uint32_t_u_u(
                                                           (1L || g_978[0][0]),
                                                           l_1541)),
                                                       l_1869)))) < g_745)) &&
                                           0xB00DAB19L)))) != l_1888) < l_1904),
                                   p_14))) |
                              l_1869))) > l_1869),
                      p_15)),
                  g_1445),
                 p_15))),
            g_20)),
          g_1550[4][1][2]) == 0x25B26E43L);
    {
      for (j = 0; j < 3; j++)
        l_1905[i][j] = 4294967289UL;
    }

  } else {
    int32_t l_1912 = 1L;
    int32_t l_1915[1][7][5] = {
        {{4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L},
         {4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L},
         {4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L},
         {4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L},
         {4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L},
         {4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L},
         {4L, 0x6E1D06A7L, 0x47ED6F79L, 0x4F7309D9L, 0x47ED6F79L}}};
    uint32_t l_1917 = 3UL;
    int i, j, k;

    g_90 = 0xBB08448AL;
    {
      uint32_t l_1863 = 0xB1A28FDCL;
      const uint16_t l_1869 = 0x72CEL;
      int32_t l_1888 = 0x36F4EC01L;
      uint8_t l_1895 = 0xDFL;
      uint32_t l_1905[2][3];
      int i, j;
      for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++)
          l_1905[i][j] = 4294967289UL;
      }
      for (g_67 = 0; (g_67 < 35); ++g_67) {
        uint16_t l_1856 = 0UL;
        int32_t l_1868 = 1L;
        int32_t l_1887 = (-2L);
        p_14 =
            (g_264,
             ((g_66 =
                   (((p_12 >=
                      (safe_rshift_func_int8_t_s_s(
                          l_1807,
                          ((((safe_lshift_func_uint16_t_u_s(
                                 ((0x7DD154ACL <=
                                   (0x49L <
                                    (safe_rshift_func_uint8_t_u_s(
                                        (l_1856 <
                                         ((((((((((l_1847 = p_12) >= g_1279) >
                                                 ((safe_lshift_func_int16_t_s_u(
                                                      (safe_mod_func_int16_t_s_s(
                                                          ((((safe_add_func_int16_t_s_s(
                                                                 l_1863,
                                                                 l_1856)) ||
                                                             255UL) == g_67) &
                                                           p_12),
                                                          l_1856)),
                                                      l_1856)),
                                                  g_20)) >= l_1863) >
                                               0xF526L) ||
                                              3UL) <= 0xEB65BACBL),
                                            0xEB62L) <= l_1546) != 0xBDL)),
                                        1)))),
                                  p_13),
                                 l_1863)),
                             0x0DEEL) >= p_12) ^
                           255UL)))) |
                     p_12) < p_15)) ^
              g_25[0]));
        g_90 =
            (g_218 <
             ((((l_1856 && (l_1675.f1 ||
                            ((safe_lshift_func_int8_t_s_u(
                                 (p_12 <= (safe_rshift_func_int8_t_s_u(
                                              (((l_1868 = (+(g_28[1] >= 1UL))) &
                                                (((((-5L) != 0x9A51L), p_13) |
                                                  l_1863) == l_1863)),
                                               1L),
                                              0))),
                                 3)) >= g_720))) < l_1869) > g_218) &
              l_1863));
        l_1509[2] = p_14;
        p_14 =
            ((safe_rshift_func_uint16_t_u_u(
                 ((l_1863 >=
                   ((safe_lshift_func_int16_t_s_s(p_15, (0x76L <= (-3L)))) >=
                    (!((g_1706 !=
                        ((safe_add_func_int16_t_s_s(
                             (l_1888 =
                                  ((((+((safe_rshift_func_uint8_t_u_s(
                                            (l_1856 <= l_1868),
                                            (safe_sub_func_uint16_t_u_u(
                                                ((safe_sub_func_int8_t_s_s(
                                                     (((safe_add_func_uint8_t_u_u(
                                                           g_218,
                                                           (((l_1887 = (~(
                                                                  (safe_rshift_func_uint8_t_u_u(
                                                                      (l_1886 =
                                                                           (p_14 |
                                                                            g_322
                                                                                [0]
                                                                                [0])),
                                                                      p_14)) >=
                                                                  0xF525L))) <
                                                             0xE190F681L),
                                                            0xE6L))) |
                                                       g_151[2][2]) < p_14),
                                                     (-10L))) &&
                                                 0xE1A2L),
                                                65535UL)))) ^
                                        0xC5038752L)),
                                     8UL) ^
                                    g_1574) >= 0UL)),
                             l_1869)) == 0xBEL)) == g_978[0][0])))) > g_66),
                 g_1706)) == (-6L));
      }
      l_1905[1][2] =
          (((g_208,
             ((g_208.f0 = (safe_rshift_func_int16_t_s_s(
                   ((safe_add_func_int8_t_s_s(
                        ((65535UL ||
                          (p_12 =
                               ((p_12,
                                 (safe_lshift_func_int8_t_s_u(
                                     (((l_1895 ^
                                        (safe_mod_func_int16_t_s_s(
                                            p_15,
                                            (((safe_mod_func_int32_t_s_s(
                                                  l_1869, g_28[1])) ==
                                              ((l_1842 =
                                                    (p_14 !=
                                                     (safe_rshift_func_uint16_t_u_s(
                                                         (safe_add_func_uint32_t_u_u(
                                                             (1L ||
                                                              g_978[0][0]),
                                                             l_1541)),
                                                         l_1869)))) < g_745)) &&
                                             0xB00DAB19L)))) != l_1888) <
                                      l_1904),
                                     p_14))) |
                                l_1869))) > l_1869),
                        p_15)),
                    g_1445),
                   p_15))),
              g_20)),
            g_1550[4][1][2]) == 0x25B26E43L);
    }
  }
  return g_322[1][2];
}

static uint16_t func_16(int8_t p_17, uint8_t p_18, int16_t p_19) {
  int32_t l_993 = 0x2D4C6CE8L;
  int32_t l_1058[5][7] = {
      {0xFF6E870FL, (-7L), (-1L), (-7L), 0xFF6E870FL, 0x75CFBC07L, 0xFF6E870FL},
      {0xFF6E870FL, (-7L), (-1L), (-7L), 0xFF6E870FL, 0x75CFBC07L, 0xFF6E870FL},
      {0xFF6E870FL, (-7L), (-1L), (-7L), 0xFF6E870FL, 0x75CFBC07L, 0xFF6E870FL},
      {0xFF6E870FL, (-7L), (-1L), (-7L), 0xFF6E870FL, 0x75CFBC07L, 0xFF6E870FL},
      {0xFF6E870FL, (-7L), (-1L), (-7L), 0xFF6E870FL, 0x75CFBC07L,
       0xFF6E870FL}};
  int32_t l_1085 = 0x6FD409F8L;
  int32_t l_1161 = 2L;
  const int16_t l_1189 = 0xC5BCL;
  int8_t l_1264 = 0x13L;
  uint8_t l_1348 = 0x9EL;
  int i, j;
  for (g_264 = 9; (g_264 > 24); g_264++) {
    uint32_t l_983 = 0xB5BFB2B6L;
    int32_t l_1004 = 0L;
    uint32_t l_1057 = 6UL;
    int32_t l_1152 = 0xE5A4FC2DL;
    int16_t l_1180 = 0x9BB4L;
  }
  for (g_598 = 0; (g_598 < 21); ++g_598) {
    union U0 l_1204 = {0xBEDCB866L};
    uint32_t l_1207 = 0xE71AA25FL;
    int32_t l_1208 = 0x34C2FBB4L;
    int32_t l_1211 = 0x26C85BD0L;
    uint32_t l_1212 = 4294967295UL;
    uint16_t l_1280 = 65535UL;
    int32_t l_1281 = 0x0A0D1D1EL;
    int16_t l_1327 = (-1L);
    for (g_623 = 7; (g_623 != 3); --g_623) {
      int16_t l_1203[5] = {0xAB15L, (-1L), 0xAB15L, (-1L), 0xAB15L};
      int32_t l_1209 = 0xDB556D6DL;
      int32_t l_1210 = 0xECF99823L;
      int8_t l_1238 = (-5L);
      int8_t l_1259 = (-1L);
      uint16_t l_1271[8][6] = {{0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                               {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                               {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                               {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                               {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                               {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                               {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                               {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL}};
      int i, j;
      if ((g_208.f1 > ((safe_mod_func_uint8_t_u_u(p_18, 5UL)), l_1085))) {
        int8_t l_1266[4][8][8] = {
            {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}},
            {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}},
            {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}},
            {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
             {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}}};
        int32_t l_1288 = 9L;
        int i, j, k;
        l_1211 = (safe_unary_minus_func_int16_t_s((
            (p_17 = p_18) >=
            ((g_208.f1 >=
              (safe_sub_func_uint32_t_u_u(
                  (l_1210 =
                       (((((safe_rshift_func_int8_t_s_u(
                               (safe_mod_func_int16_t_s_s(
                                   ((((((g_151[2][2] =
                                             ((l_1209 =
                                                   (l_1203[1] &&
                                                    ((l_1204,
                                                      (safe_lshift_func_int8_t_s_s(
                                                          (g_251 =
                                                               (p_19 ||
                                                                (((((0x3A17L ^
                                                                     l_1207) >=
                                                                    (l_1208 =
                                                                         (l_1189,
                                                                          (l_1204,
                                                                           p_18)))) !=
                                                                   l_1204.f2) ^
                                                                  p_18) >
                                                                 0x1BAFL))),
                                                          0))) > g_208.f1))) !=
                                              p_18)) >= p_18) == l_1203[1]) <
                                      0x6E960D46L) &
                                     4294967295UL) == l_1058[1][1]),
                                   g_233)),
                               l_1203[1])) ||
                           p_19) |
                          4294967295UL) |
                         l_1203[1]) < l_1207)),
                  0L))) <= 4294967295UL))));

        {
          uint32_t l_983 = 0xB5BFB2B6L;
          int32_t l_1004 = 0L;
          uint32_t l_1057 = 6UL;
          int32_t l_1152 = 0xE5A4FC2DL;
          int16_t l_1180 = 0x9BB4L;
        }

      } else {
        const uint8_t l_1328 = 0xC0L;
        int32_t l_1340 = 0x6DFA6B21L;
        int16_t l_1341 = 0xD6FCL;
        for (l_1204.f0 = 1; (l_1204.f0 <= 5); l_1204.f0 += 1) {
          int i, j;
          if ((((((((((safe_rshift_func_uint16_t_u_u(
                          (((+(l_1271[(l_1204.f0 + 2)][l_1204.f0],
                               (p_17 &
                                (l_1271[(l_1204.f0 + 1)][l_1204.f0] = (safe_lshift_func_int16_t_s_u(
                                     p_19,
                                     (((((p_19 && p_19) |
                                         (((((g_264 =
                                                  (l_993 <=
                                                   (((safe_sub_func_uint16_t_u_u(
                                                         l_1271[(l_1204.f0 + 2)]
                                                               [l_1204.f0],
                                                         (l_1208,
                                                          ((((safe_mod_func_int16_t_s_s(
                                                                 ((safe_lshift_func_uint16_t_u_u(
                                                                      (((safe_sub_func_uint8_t_u_u(
                                                                            (safe_add_func_uint32_t_u_u(
                                                                                (p_19,
                                                                                 l_1327),
                                                                                0xC953E68FL)),
                                                                            0L)) &
                                                                        p_18) &
                                                                       0x1B45L),
                                                                      p_18)) &
                                                                  (-1L)),
                                                                 p_17)) &
                                                             g_1279) &&
                                                            0L) &&
                                                           p_19)))),
                                                     1L) |
                                                    0L))) <= g_20) |
                                            g_167[1][5]) ^
                                           8UL) &
                                          g_67)) != p_18) >= p_19) >
                                      1L))))))) <= p_18) > 1UL),
                          l_1209)) < p_19) == 1UL),
                    0xC4L) >= 6L),
                  l_1271[(l_1204.f0 + 2)][l_1204.f0]) ^
                 l_1328) &
                0UL) > g_151[2][2])) {
            return g_25[0];
          } else {
            return g_208.f2;
          }
        }
      }
      for (g_20 = 0; (g_20 <= 2); g_20 += 1) {
        int i, j;

        if ((g_208.f1 > ((safe_mod_func_uint8_t_u_u(p_18, 5UL)), l_1085))) {
          int8_t l_1266[4][8][8] = {
              {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}},
              {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}},
              {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}},
              {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}}};
          int32_t l_1288 = 9L;
          int i, j, k;
          l_1211 = (safe_unary_minus_func_int16_t_s((
              (p_17 = p_18) >=
              ((g_208.f1 >=
                (safe_sub_func_uint32_t_u_u(
                    (l_1210 =
                         (((((safe_rshift_func_int8_t_s_u(
                                 (safe_mod_func_int16_t_s_s(
                                     ((((((g_151[2][2] =
                                               ((l_1209 =
                                                     (l_1203[1] &&
                                                      ((l_1204,
                                                        (safe_lshift_func_int8_t_s_s(
                                                            (g_251 =
                                                                 (p_19 ||
                                                                  (((((0x3A17L ^
                                                                       l_1207) >=
                                                                      (l_1208 =
                                                                           (l_1189,
                                                                            (l_1204,
                                                                             p_18)))) !=
                                                                     l_1204
                                                                         .f2) ^
                                                                    p_18) >
                                                                   0x1BAFL))),
                                                            0))) >
                                                       g_208.f1))) != p_18)) >=
                                          p_18) == l_1203[1]) < 0x6E960D46L) &
                                       4294967295UL) == l_1058[1][1]),
                                     g_233)),
                                 l_1203[1])) ||
                             p_19) |
                            4294967295UL) |
                           l_1203[1]) < l_1207)),
                    0L))) <= 4294967295UL))));
          if (p_17) {
            uint32_t l_1239[7] = {4294967293UL, 4294967293UL, 1UL,
                                  4294967293UL, 4294967293UL, 1UL,
                                  4294967293UL};
            int32_t l_1240 = 1L;
            int i;
            l_1212 = p_18;
            for (l_1207 = (-9); (l_1207 != 5);
                 l_1207 = safe_add_func_uint32_t_u_u(l_1207, 1)) {
              g_90 = (-6L);
            }
            for (g_208.f0 = 0; (g_208.f0 >= 0); g_208.f0 -= 1) {
              union U0 l_1237 = {0L};
              int32_t l_1265 = 0L;
              const int32_t l_1278 = 0xBAC09BEDL;
              int i, j;
              l_1240 =
                  ((safe_lshift_func_int16_t_s_s(
                       ((safe_mod_func_uint8_t_u_u(
                            (((((g_978[(g_208.f0 + 2)][g_208.f0] >
                                 g_28[(g_208.f0 + 1)]) &
                                (safe_lshift_func_uint8_t_u_u(
                                    (safe_mod_func_uint8_t_u_u(
                                        (g_164 = g_28[(g_208.f0 + 2)]),
                                        (safe_mul_func_int8_t_s_s(
                                            (g_251 = g_151[2][2]),
                                            (!(safe_sub_func_int32_t_s_s(
                                                ((((0x803FL > 0x5072L) >=
                                                   (!((safe_sub_func_int16_t_s_s(
                                                          (((safe_sub_func_uint16_t_u_u(
                                                                (((safe_mod_func_uint8_t_u_u(
                                                                      ((((safe_lshift_func_int8_t_s_s(
                                                                             ((p_18 !=
                                                                               ((safe_sub_func_uint16_t_u_u(
                                                                                    ((((((l_1237,
                                                                                          g_208),
                                                                                         l_1238),
                                                                                        6L) !=
                                                                                       p_18) <
                                                                                      255UL),
                                                                                     0x6F8AL),
                                                                                    0xF180L)) >
                                                                                g_322
                                                                                    [1]
                                                                                    [2])) &
                                                                              l_1212),
                                                                             2)) &&
                                                                         l_1085),
                                                                        0x53E1098EL) >=
                                                                       4294967293UL),
                                                                      p_19)) >
                                                                  p_19) &
                                                                 g_978[3][0]),
                                                                p_17)) >= 1UL) &
                                                           0xBDL),
                                                          l_1207)) ||
                                                      0x08F9745AL))) ^
                                                  1UL),
                                                 p_17),
                                                p_17))))))),
                                    7))) |
                               (-1L)),
                              g_372) == 0xDCL),
                            l_1239[6])) ||
                        g_264),
                       8)),
                   0x4D7C804AL);
              l_1265 = (safe_mod_func_int32_t_s_s(
                  (safe_rshift_func_uint16_t_u_u(
                      ((((safe_add_func_uint8_t_u_u(
                             0xA3L,
                             (safe_add_func_uint16_t_u_u(
                                 0x8027L,
                                 (g_167[2][7],
                                  (((safe_rshift_func_uint16_t_u_u(
                                        (safe_mod_func_uint32_t_u_u(
                                            (safe_add_func_uint8_t_u_u(
                                                ((0L ==
                                                  (safe_rshift_func_int8_t_s_s(
                                                      (safe_sub_func_uint8_t_u_u(
                                                          255UL, l_1259)),
                                                      l_1239[1]))),
                                                 (safe_rshift_func_uint8_t_u_u(
                                                     (l_1207 <
                                                      (safe_rshift_func_int8_t_s_s(
                                                          (((l_1209 && p_18) &
                                                            p_17),
                                                           0x9EL),
                                                          0))),
                                                     g_978[(g_208.f0 + 3)]
                                                          [g_208.f0]))),
                                                0xE9L)),
                                            l_1058[2][0])),
                                        p_18)) &
                                    1L) <= 4294967288UL)))))) < 1UL),
                        l_1264) == 0x30L),
                      8)),
                  g_167[3][5]));
              g_66 = g_322[1][2];
              g_66 =
                  ((((((g_322[5][1] =
                            (g_598 <=
                             ((l_1266[2][0][1] &&
                               (((p_17 <
                                  ((((((g_66,
                                        ((safe_sub_func_uint16_t_u_u(
                                             (g_90,
                                              ((g_20 =
                                                    (((safe_lshift_func_int8_t_s_s(
                                                          ((((((l_1271[6][4] ||
                                                                (safe_add_func_int8_t_s_s(
                                                                    (p_17 ==
                                                                     (safe_lshift_func_int8_t_s_s(
                                                                         p_17,
                                                                         0))),
                                                                    ((safe_lshift_func_int8_t_s_s(
                                                                         3L,
                                                                         2)) ||
                                                                     0x14L)))) &&
                                                               255UL) &
                                                              g_623),
                                                             0x60L) > l_1278),
                                                           p_18),
                                                          p_18)) ||
                                                      0UL) &&
                                                     g_598)),
                                               g_372)),
                                             l_1209)) ||
                                         9UL)) > p_19) != g_322[1][2]) >=
                                     0x0FA9L) |
                                    g_1279) > l_1239[1])) ||
                                 g_978[0][0]) ^
                                g_151[2][2])),
                              g_164))) == l_1280) |
                      255UL) &&
                     l_1239[6]) ^
                    p_18) != g_90);
            }
            g_66 =
                ((p_19 != g_208.f2) >=
                 ((g_90 =
                       (l_1281 &
                        (g_1279 = (safe_add_func_uint8_t_u_u(
                             1UL,
                             ((((p_19 <= g_251),
                                (((safe_lshift_func_int16_t_s_u(
                                      ((l_1264 !=
                                        (l_1288 =
                                             ((g_745 =
                                                   (safe_mod_func_int32_t_s_s(
                                                       0xEAB3A0C8L,
                                                       (l_1208 = g_218)))) |
                                              p_18))) != l_1239[6]),
                                      8)),
                                  l_1239[6]) == 4294967295UL)) != 0xFF94L) &
                              0x69L)))))) ^
                  p_18));
          } else {
            int16_t l_1291 = 0x2C31L;
            int32_t l_1311 = 0xF8834343L;
            for (p_17 = 0; (p_17 != 7); p_17++) {
              int8_t l_1310 = 0x7EL;
              uint8_t l_1312 = 248UL;
              l_1291 = g_322[1][2];
              l_1312 =
                  (g_90 = (!(safe_rshift_func_int16_t_s_s(
                       (l_1311 =
                            ((safe_rshift_func_int8_t_s_s(
                                 (((safe_rshift_func_uint8_t_u_u(
                                       (safe_add_func_int32_t_s_s(
                                           (safe_mod_func_uint32_t_u_u(l_1207,
                                                                       6UL)),
                                           p_18)),
                                       (l_1204, 0x2CL))) |
                                   (-4L)) !=
                                  (safe_rshift_func_uint16_t_u_u(
                                      ((((safe_rshift_func_uint8_t_u_u(
                                             l_1271[4][0],
                                             (((safe_add_func_uint8_t_u_u(
                                                   (((safe_sub_func_int32_t_s_s(
                                                         (p_17 >
                                                          (l_1085 =
                                                               ((p_18, g_233) &
                                                                l_1310))),
                                                         p_19)) &
                                                     0x73DDL) > 1L),
                                                   0L)) == p_18) ^
                                              l_1310))) &&
                                         0xF7A46F60L) ||
                                        248UL) >= l_1264),
                                      14))),
                                 4)) &&
                             0UL)),
                       15))));
            }
          }
        } else {
          const uint8_t l_1328 = 0xC0L;
          int32_t l_1340 = 0x6DFA6B21L;
          int16_t l_1341 = 0xD6FCL;
          for (l_1204.f0 = 1; (l_1204.f0 <= 5); l_1204.f0 += 1) {
            int i, j;
            if ((((((((((safe_rshift_func_uint16_t_u_u(
                            (((+(l_1271[(l_1204.f0 + 2)][l_1204.f0],
                                 (p_17 &
                                  (l_1271[(l_1204.f0 + 1)][l_1204.f0] = (safe_lshift_func_int16_t_s_u(
                                       p_19,
                                       (((((p_19 && p_19) |
                                           (((((g_264 =
                                                    (l_993 <=
                                                     (((safe_sub_func_uint16_t_u_u(
                                                           l_1271[(
                                                               l_1204.f0 +
                                                               2)][l_1204.f0],
                                                           (l_1208,
                                                            ((((safe_mod_func_int16_t_s_s(
                                                                   ((safe_lshift_func_uint16_t_u_u(
                                                                        (((safe_sub_func_uint8_t_u_u(
                                                                              (safe_add_func_uint32_t_u_u(
                                                                                  (p_19,
                                                                                   l_1327),
                                                                                  0xC953E68FL)),
                                                                              0L)) &
                                                                          p_18) &
                                                                         0x1B45L),
                                                                        p_18)) &
                                                                    (-1L)),
                                                                   p_17)) &
                                                               g_1279) &&
                                                              0L) &&
                                                             p_19)))),
                                                       1L) |
                                                      0L))) <= g_20) |
                                              g_167[1][5]) ^
                                             8UL) &
                                            g_67)) != p_18) >= p_19) >
                                        1L))))))) <= p_18) > 1UL),
                            l_1209)) < p_19) == 1UL),
                      0xC4L) >= 6L),
                    l_1271[(l_1204.f0 + 2)][l_1204.f0]) ^
                   l_1328) &
                  0UL) > g_151[2][2])) {
              return g_25[0];
            } else {
              return g_208.f2;
            }
          }
          for (l_1281 = 20; (l_1281 >= (-7)); --l_1281) {
            int32_t l_1337[1];
            int i;
            for (i = 0; i < 1; i++)
              l_1337[i] = 1L;
            g_90 =
                (0xBA73956DL <=
                 (safe_add_func_uint8_t_u_u(
                     (l_1209 = 8UL),
                     (((65534UL || 0xF2DAL) &
                       ((g_598 || l_1203[2]) >
                        ((safe_add_func_int16_t_s_s(
                             ((safe_sub_func_uint32_t_u_u(
                                  ((p_17,
                                    (l_1337[0] >=
                                     ((((((l_1340 = (safe_add_func_int16_t_s_s(
                                               (0xC2L | p_17), 0xE971L))) |
                                          g_322[1][2]) > (-1L)) >=
                                        g_151[9][0]) > l_1341) != p_19))) ||
                                   (-4L)),
                                  l_1337[0])) > p_18),
                             p_19)) &&
                         0x5CCED47EL))) &
                      0x2DL))));
          }
        }
      }

      {
        uint32_t l_983 = 0xB5BFB2B6L;
        int32_t l_1004 = 0L;
        uint32_t l_1057 = 6UL;
        int32_t l_1152 = 0xE5A4FC2DL;
        int16_t l_1180 = 0x9BB4L;
      }
    }
    g_90 = (safe_lshift_func_uint8_t_u_u(0xC2L, 6));

    {
      union U0 l_1204 = {0xBEDCB866L};
      uint32_t l_1207 = 0xE71AA25FL;
      int32_t l_1208 = 0x34C2FBB4L;
      int32_t l_1211 = 0x26C85BD0L;
      uint32_t l_1212 = 4294967295UL;
      uint16_t l_1280 = 65535UL;
      int32_t l_1281 = 0x0A0D1D1EL;
      int16_t l_1327 = (-1L);
      for (g_623 = 7; (g_623 != 3); --g_623) {
        int16_t l_1203[5] = {0xAB15L, (-1L), 0xAB15L, (-1L), 0xAB15L};
        int32_t l_1209 = 0xDB556D6DL;
        int32_t l_1210 = 0xECF99823L;
        int8_t l_1238 = (-5L);
        int8_t l_1259 = (-1L);
        uint16_t l_1271[8][6] = {{0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL}};
        int i, j;
        if ((g_208.f1 > ((safe_mod_func_uint8_t_u_u(p_18, 5UL)), l_1085))) {
          int8_t l_1266[4][8][8] = {
              {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}},
              {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}},
              {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}},
              {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}}};
          int32_t l_1288 = 9L;
          int i, j, k;
          l_1211 = (safe_unary_minus_func_int16_t_s((
              (p_17 = p_18) >=
              ((g_208.f1 >=
                (safe_sub_func_uint32_t_u_u(
                    (l_1210 =
                         (((((safe_rshift_func_int8_t_s_u(
                                 (safe_mod_func_int16_t_s_s(
                                     ((((((g_151[2][2] =
                                               ((l_1209 =
                                                     (l_1203[1] &&
                                                      ((l_1204,
                                                        (safe_lshift_func_int8_t_s_s(
                                                            (g_251 =
                                                                 (p_19 ||
                                                                  (((((0x3A17L ^
                                                                       l_1207) >=
                                                                      (l_1208 =
                                                                           (l_1189,
                                                                            (l_1204,
                                                                             p_18)))) !=
                                                                     l_1204
                                                                         .f2) ^
                                                                    p_18) >
                                                                   0x1BAFL))),
                                                            0))) >
                                                       g_208.f1))) != p_18)) >=
                                          p_18) == l_1203[1]) < 0x6E960D46L) &
                                       4294967295UL) == l_1058[1][1]),
                                     g_233)),
                                 l_1203[1])) ||
                             p_19) |
                            4294967295UL) |
                           l_1203[1]) < l_1207)),
                    0L))) <= 4294967295UL))));
          if (p_17) {
            uint32_t l_1239[7] = {4294967293UL, 4294967293UL, 1UL,
                                  4294967293UL, 4294967293UL, 1UL,
                                  4294967293UL};
            int32_t l_1240 = 1L;
            int i;
            l_1212 = p_18;
            for (l_1207 = (-9); (l_1207 != 5);
                 l_1207 = safe_add_func_uint32_t_u_u(l_1207, 1)) {
              g_90 = (-6L);
            }
            for (g_208.f0 = 0; (g_208.f0 >= 0); g_208.f0 -= 1) {
              union U0 l_1237 = {0L};
              int32_t l_1265 = 0L;
              const int32_t l_1278 = 0xBAC09BEDL;
              int i, j;
              l_1240 =
                  ((safe_lshift_func_int16_t_s_s(
                       ((safe_mod_func_uint8_t_u_u(
                            (((((g_978[(g_208.f0 + 2)][g_208.f0] >
                                 g_28[(g_208.f0 + 1)]) &
                                (safe_lshift_func_uint8_t_u_u(
                                    (safe_mod_func_uint8_t_u_u(
                                        (g_164 = g_28[(g_208.f0 + 2)]),
                                        (safe_mul_func_int8_t_s_s(
                                            (g_251 = g_151[2][2]),
                                            (!(safe_sub_func_int32_t_s_s(
                                                ((((0x803FL > 0x5072L) >=
                                                   (!((safe_sub_func_int16_t_s_s(
                                                          (((safe_sub_func_uint16_t_u_u(
                                                                (((safe_mod_func_uint8_t_u_u(
                                                                      ((((safe_lshift_func_int8_t_s_s(
                                                                             ((p_18 !=
                                                                               ((safe_sub_func_uint16_t_u_u(
                                                                                    ((((((l_1237,
                                                                                          g_208),
                                                                                         l_1238),
                                                                                        6L) !=
                                                                                       p_18) <
                                                                                      255UL),
                                                                                     0x6F8AL),
                                                                                    0xF180L)) >
                                                                                g_322
                                                                                    [1]
                                                                                    [2])) &
                                                                              l_1212),
                                                                             2)) &&
                                                                         l_1085),
                                                                        0x53E1098EL) >=
                                                                       4294967293UL),
                                                                      p_19)) >
                                                                  p_19) &
                                                                 g_978[3][0]),
                                                                p_17)) >= 1UL) &
                                                           0xBDL),
                                                          l_1207)) ||
                                                      0x08F9745AL))) ^
                                                  1UL),
                                                 p_17),
                                                p_17))))))),
                                    7))) |
                               (-1L)),
                              g_372) == 0xDCL),
                            l_1239[6])) ||
                        g_264),
                       8)),
                   0x4D7C804AL);
              l_1265 = (safe_mod_func_int32_t_s_s(
                  (safe_rshift_func_uint16_t_u_u(
                      ((((safe_add_func_uint8_t_u_u(
                             0xA3L,
                             (safe_add_func_uint16_t_u_u(
                                 0x8027L,
                                 (g_167[2][7],
                                  (((safe_rshift_func_uint16_t_u_u(
                                        (safe_mod_func_uint32_t_u_u(
                                            (safe_add_func_uint8_t_u_u(
                                                ((0L ==
                                                  (safe_rshift_func_int8_t_s_s(
                                                      (safe_sub_func_uint8_t_u_u(
                                                          255UL, l_1259)),
                                                      l_1239[1]))),
                                                 (safe_rshift_func_uint8_t_u_u(
                                                     (l_1207 <
                                                      (safe_rshift_func_int8_t_s_s(
                                                          (((l_1209 && p_18) &
                                                            p_17),
                                                           0x9EL),
                                                          0))),
                                                     g_978[(g_208.f0 + 3)]
                                                          [g_208.f0]))),
                                                0xE9L)),
                                            l_1058[2][0])),
                                        p_18)) &
                                    1L) <= 4294967288UL)))))) < 1UL),
                        l_1264) == 0x30L),
                      8)),
                  g_167[3][5]));
              g_66 = g_322[1][2];
              g_66 =
                  ((((((g_322[5][1] =
                            (g_598 <=
                             ((l_1266[2][0][1] &&
                               (((p_17 <
                                  ((((((g_66,
                                        ((safe_sub_func_uint16_t_u_u(
                                             (g_90,
                                              ((g_20 =
                                                    (((safe_lshift_func_int8_t_s_s(
                                                          ((((((l_1271[6][4] ||
                                                                (safe_add_func_int8_t_s_s(
                                                                    (p_17 ==
                                                                     (safe_lshift_func_int8_t_s_s(
                                                                         p_17,
                                                                         0))),
                                                                    ((safe_lshift_func_int8_t_s_s(
                                                                         3L,
                                                                         2)) ||
                                                                     0x14L)))) &&
                                                               255UL) &
                                                              g_623),
                                                             0x60L) > l_1278),
                                                           p_18),
                                                          p_18)) ||
                                                      0UL) &&
                                                     g_598)),
                                               g_372)),
                                             l_1209)) ||
                                         9UL)) > p_19) != g_322[1][2]) >=
                                     0x0FA9L) |
                                    g_1279) > l_1239[1])) ||
                                 g_978[0][0]) ^
                                g_151[2][2])),
                              g_164))) == l_1280) |
                      255UL) &&
                     l_1239[6]) ^
                    p_18) != g_90);
            }
            g_66 =
                ((p_19 != g_208.f2) >=
                 ((g_90 =
                       (l_1281 &
                        (g_1279 = (safe_add_func_uint8_t_u_u(
                             1UL,
                             ((((p_19 <= g_251),
                                (((safe_lshift_func_int16_t_s_u(
                                      ((l_1264 !=
                                        (l_1288 =
                                             ((g_745 =
                                                   (safe_mod_func_int32_t_s_s(
                                                       0xEAB3A0C8L,
                                                       (l_1208 = g_218)))) |
                                              p_18))) != l_1239[6]),
                                      8)),
                                  l_1239[6]) == 4294967295UL)) != 0xFF94L) &
                              0x69L)))))) ^
                  p_18));
          } else {
            int16_t l_1291 = 0x2C31L;
            int32_t l_1311 = 0xF8834343L;
            for (p_17 = 0; (p_17 != 7); p_17++) {
              int8_t l_1310 = 0x7EL;
              uint8_t l_1312 = 248UL;
              l_1291 = g_322[1][2];
              l_1312 =
                  (g_90 = (!(safe_rshift_func_int16_t_s_s(
                       (l_1311 =
                            ((safe_rshift_func_int8_t_s_s(
                                 (((safe_rshift_func_uint8_t_u_u(
                                       (safe_add_func_int32_t_s_s(
                                           (safe_mod_func_uint32_t_u_u(l_1207,
                                                                       6UL)),
                                           p_18)),
                                       (l_1204, 0x2CL))) |
                                   (-4L)) !=
                                  (safe_rshift_func_uint16_t_u_u(
                                      ((((safe_rshift_func_uint8_t_u_u(
                                             l_1271[4][0],
                                             (((safe_add_func_uint8_t_u_u(
                                                   (((safe_sub_func_int32_t_s_s(
                                                         (p_17 >
                                                          (l_1085 =
                                                               ((p_18, g_233) &
                                                                l_1310))),
                                                         p_19)) &
                                                     0x73DDL) > 1L),
                                                   0L)) == p_18) ^
                                              l_1310))) &&
                                         0xF7A46F60L) ||
                                        248UL) >= l_1264),
                                      14))),
                                 4)) &&
                             0UL)),
                       15))));
            }
          }
        } else {
          const uint8_t l_1328 = 0xC0L;
          int32_t l_1340 = 0x6DFA6B21L;
          int16_t l_1341 = 0xD6FCL;
          for (l_1204.f0 = 1; (l_1204.f0 <= 5); l_1204.f0 += 1) {
            int i, j;
            if ((((((((((safe_rshift_func_uint16_t_u_u(
                            (((+(l_1271[(l_1204.f0 + 2)][l_1204.f0],
                                 (p_17 &
                                  (l_1271[(l_1204.f0 + 1)][l_1204.f0] = (safe_lshift_func_int16_t_s_u(
                                       p_19,
                                       (((((p_19 && p_19) |
                                           (((((g_264 =
                                                    (l_993 <=
                                                     (((safe_sub_func_uint16_t_u_u(
                                                           l_1271[(
                                                               l_1204.f0 +
                                                               2)][l_1204.f0],
                                                           (l_1208,
                                                            ((((safe_mod_func_int16_t_s_s(
                                                                   ((safe_lshift_func_uint16_t_u_u(
                                                                        (((safe_sub_func_uint8_t_u_u(
                                                                              (safe_add_func_uint32_t_u_u(
                                                                                  (p_19,
                                                                                   l_1327),
                                                                                  0xC953E68FL)),
                                                                              0L)) &
                                                                          p_18) &
                                                                         0x1B45L),
                                                                        p_18)) &
                                                                    (-1L)),
                                                                   p_17)) &
                                                               g_1279) &&
                                                              0L) &&
                                                             p_19)))),
                                                       1L) |
                                                      0L))) <= g_20) |
                                              g_167[1][5]) ^
                                             8UL) &
                                            g_67)) != p_18) >= p_19) >
                                        1L))))))) <= p_18) > 1UL),
                            l_1209)) < p_19) == 1UL),
                      0xC4L) >= 6L),
                    l_1271[(l_1204.f0 + 2)][l_1204.f0]) ^
                   l_1328) &
                  0UL) > g_151[2][2])) {
              return g_25[0];
            } else {
              return g_208.f2;
            }
          }
          for (l_1281 = 20; (l_1281 >= (-7)); --l_1281) {
            int32_t l_1337[1];
            int i;
            for (i = 0; i < 1; i++)
              l_1337[i] = 1L;
            g_90 =
                (0xBA73956DL <=
                 (safe_add_func_uint8_t_u_u(
                     (l_1209 = 8UL),
                     (((65534UL || 0xF2DAL) &
                       ((g_598 || l_1203[2]) >
                        ((safe_add_func_int16_t_s_s(
                             ((safe_sub_func_uint32_t_u_u(
                                  ((p_17,
                                    (l_1337[0] >=
                                     ((((((l_1340 = (safe_add_func_int16_t_s_s(
                                               (0xC2L | p_17), 0xE971L))) |
                                          g_322[1][2]) > (-1L)) >=
                                        g_151[9][0]) > l_1341) != p_19))) ||
                                   (-4L)),
                                  l_1337[0])) > p_18),
                             p_19)) &&
                         0x5CCED47EL))) &
                      0x2DL))));
          }
        }
        for (g_20 = 0; (g_20 <= 2); g_20 += 1) {
          int i, j;
          if (g_322[(g_20 + 3)][g_20])
            break;
        }
        for (g_264 = 0; (g_264 == 39); ++g_264) {
          return p_17;
        }
        l_1211 = (safe_add_func_int16_t_s_s(
            ((l_1281 = (p_19, (g_218 = ((4294967295UL < (!l_1210)) >=
                                        (!(p_18 & 0x3CC9A2DCL)))))) ==
             (p_17 && 0x8AL)),
            ((p_19 & ((safe_lshift_func_int8_t_s_u(
                          (((g_164 != l_1271[6][4]) < 0L) > l_1204.f1), 3)) &
                      g_208.f1)) |
             l_1348)));
      }
      g_90 = (safe_lshift_func_uint8_t_u_u(0xC2L, 6));
      if (g_598)
        continue;
    }
  }

  for (p_18 = 0; (p_18 != 35); p_18 = safe_add_func_uint32_t_u_u(p_18, 8)) {
    uint16_t l_1380 = 65535UL;

    g_90 = ((safe_sub_func_int16_t_s_s(((g_208.f1 = (l_1380, g_233)) == g_745),
                                       p_19)) <=
            (safe_add_func_uint16_t_u_u(
                0x8F2FL,
                (4294967294UL >=
                 (g_66 = (safe_lshift_func_uint16_t_u_s(
                      (((safe_add_func_uint8_t_u_u(
                            l_1189, (((safe_lshift_func_int16_t_s_u(
                                          (l_1380 & 0xFAL), 10)) != 0x20L),
                                     l_993))) ^
                        g_218),
                       l_1161),
                      12)))))));

    g_90 = g_151[2][0];
    g_90 = g_151[2][0];

    if (p_17)

    {
      if (p_17)
        continue;
    }

    {
      union U0 l_1204 = {0xBEDCB866L};
      uint32_t l_1207 = 0xE71AA25FL;
      int32_t l_1208 = 0x34C2FBB4L;
      int32_t l_1211 = 0x26C85BD0L;
      uint32_t l_1212 = 4294967295UL;
      uint16_t l_1280 = 65535UL;
      int32_t l_1281 = 0x0A0D1D1EL;
      int16_t l_1327 = (-1L);
      for (g_623 = 7; (g_623 != 3); --g_623) {
        int16_t l_1203[5] = {0xAB15L, (-1L), 0xAB15L, (-1L), 0xAB15L};
        int32_t l_1209 = 0xDB556D6DL;
        int32_t l_1210 = 0xECF99823L;
        int8_t l_1238 = (-5L);
        int8_t l_1259 = (-1L);
        uint16_t l_1271[8][6] = {{0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL},
                                 {0x2AD9L, 1UL, 7UL, 1UL, 0x2AD9L, 1UL}};
        int i, j;
        if ((g_208.f1 > ((safe_mod_func_uint8_t_u_u(p_18, 5UL)), l_1085))) {
          int8_t l_1266[4][8][8] = {
              {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}},
              {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}},
              {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}},
              {{0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L},
               {0x44L, 0xA5L, 0x4AL, 0x73L, 0L, 0xDBL, 0L, 0x73L}}};
          int32_t l_1288 = 9L;
          int i, j, k;
          l_1211 = (safe_unary_minus_func_int16_t_s((
              (p_17 = p_18) >=
              ((g_208.f1 >=
                (safe_sub_func_uint32_t_u_u(
                    (l_1210 =
                         (((((safe_rshift_func_int8_t_s_u(
                                 (safe_mod_func_int16_t_s_s(
                                     ((((((g_151[2][2] =
                                               ((l_1209 =
                                                     (l_1203[1] &&
                                                      ((l_1204,
                                                        (safe_lshift_func_int8_t_s_s(
                                                            (g_251 =
                                                                 (p_19 ||
                                                                  (((((0x3A17L ^
                                                                       l_1207) >=
                                                                      (l_1208 =
                                                                           (l_1189,
                                                                            (l_1204,
                                                                             p_18)))) !=
                                                                     l_1204
                                                                         .f2) ^
                                                                    p_18) >
                                                                   0x1BAFL))),
                                                            0))) >
                                                       g_208.f1))) != p_18)) >=
                                          p_18) == l_1203[1]) < 0x6E960D46L) &
                                       4294967295UL) == l_1058[1][1]),
                                     g_233)),
                                 l_1203[1])) ||
                             p_19) |
                            4294967295UL) |
                           l_1203[1]) < l_1207)),
                    0L))) <= 4294967295UL))));
          if (p_17) {
            uint32_t l_1239[7] = {4294967293UL, 4294967293UL, 1UL,
                                  4294967293UL, 4294967293UL, 1UL,
                                  4294967293UL};
            int32_t l_1240 = 1L;
            int i;
            l_1212 = p_18;
            for (l_1207 = (-9); (l_1207 != 5);
                 l_1207 = safe_add_func_uint32_t_u_u(l_1207, 1)) {
              g_90 = (-6L);
            }
            for (g_208.f0 = 0; (g_208.f0 >= 0); g_208.f0 -= 1) {
              union U0 l_1237 = {0L};
              int32_t l_1265 = 0L;
              const int32_t l_1278 = 0xBAC09BEDL;
              int i, j;
              l_1240 =
                  ((safe_lshift_func_int16_t_s_s(
                       ((safe_mod_func_uint8_t_u_u(
                            (((((g_978[(g_208.f0 + 2)][g_208.f0] >
                                 g_28[(g_208.f0 + 1)]) &
                                (safe_lshift_func_uint8_t_u_u(
                                    (safe_mod_func_uint8_t_u_u(
                                        (g_164 = g_28[(g_208.f0 + 2)]),
                                        (safe_mul_func_int8_t_s_s(
                                            (g_251 = g_151[2][2]),
                                            (!(safe_sub_func_int32_t_s_s(
                                                ((((0x803FL > 0x5072L) >=
                                                   (!((safe_sub_func_int16_t_s_s(
                                                          (((safe_sub_func_uint16_t_u_u(
                                                                (((safe_mod_func_uint8_t_u_u(
                                                                      ((((safe_lshift_func_int8_t_s_s(
                                                                             ((p_18 !=
                                                                               ((safe_sub_func_uint16_t_u_u(
                                                                                    ((((((l_1237,
                                                                                          g_208),
                                                                                         l_1238),
                                                                                        6L) !=
                                                                                       p_18) <
                                                                                      255UL),
                                                                                     0x6F8AL),
                                                                                    0xF180L)) >
                                                                                g_322
                                                                                    [1]
                                                                                    [2])) &
                                                                              l_1212),
                                                                             2)) &&
                                                                         l_1085),
                                                                        0x53E1098EL) >=
                                                                       4294967293UL),
                                                                      p_19)) >
                                                                  p_19) &
                                                                 g_978[3][0]),
                                                                p_17)) >= 1UL) &
                                                           0xBDL),
                                                          l_1207)) ||
                                                      0x08F9745AL))) ^
                                                  1UL),
                                                 p_17),
                                                p_17))))))),
                                    7))) |
                               (-1L)),
                              g_372) == 0xDCL),
                            l_1239[6])) ||
                        g_264),
                       8)),
                   0x4D7C804AL);
              l_1265 = (safe_mod_func_int32_t_s_s(
                  (safe_rshift_func_uint16_t_u_u(
                      ((((safe_add_func_uint8_t_u_u(
                             0xA3L,
                             (safe_add_func_uint16_t_u_u(
                                 0x8027L,
                                 (g_167[2][7],
                                  (((safe_rshift_func_uint16_t_u_u(
                                        (safe_mod_func_uint32_t_u_u(
                                            (safe_add_func_uint8_t_u_u(
                                                ((0L ==
                                                  (safe_rshift_func_int8_t_s_s(
                                                      (safe_sub_func_uint8_t_u_u(
                                                          255UL, l_1259)),
                                                      l_1239[1]))),
                                                 (safe_rshift_func_uint8_t_u_u(
                                                     (l_1207 <
                                                      (safe_rshift_func_int8_t_s_s(
                                                          (((l_1209 && p_18) &
                                                            p_17),
                                                           0x9EL),
                                                          0))),
                                                     g_978[(g_208.f0 + 3)]
                                                          [g_208.f0]))),
                                                0xE9L)),
                                            l_1058[2][0])),
                                        p_18)) &
                                    1L) <= 4294967288UL)))))) < 1UL),
                        l_1264) == 0x30L),
                      8)),
                  g_167[3][5]));
              g_66 = g_322[1][2];
              g_66 =
                  ((((((g_322[5][1] =
                            (g_598 <=
                             ((l_1266[2][0][1] &&
                               (((p_17 <
                                  ((((((g_66,
                                        ((safe_sub_func_uint16_t_u_u(
                                             (g_90,
                                              ((g_20 =
                                                    (((safe_lshift_func_int8_t_s_s(
                                                          ((((((l_1271[6][4] ||
                                                                (safe_add_func_int8_t_s_s(
                                                                    (p_17 ==
                                                                     (safe_lshift_func_int8_t_s_s(
                                                                         p_17,
                                                                         0))),
                                                                    ((safe_lshift_func_int8_t_s_s(
                                                                         3L,
                                                                         2)) ||
                                                                     0x14L)))) &&
                                                               255UL) &
                                                              g_623),
                                                             0x60L) > l_1278),
                                                           p_18),
                                                          p_18)) ||
                                                      0UL) &&
                                                     g_598)),
                                               g_372)),
                                             l_1209)) ||
                                         9UL)) > p_19) != g_322[1][2]) >=
                                     0x0FA9L) |
                                    g_1279) > l_1239[1])) ||
                                 g_978[0][0]) ^
                                g_151[2][2])),
                              g_164))) == l_1280) |
                      255UL) &&
                     l_1239[6]) ^
                    p_18) != g_90);
            }
            g_66 =
                ((p_19 != g_208.f2) >=
                 ((g_90 =
                       (l_1281 &
                        (g_1279 = (safe_add_func_uint8_t_u_u(
                             1UL,
                             ((((p_19 <= g_251),
                                (((safe_lshift_func_int16_t_s_u(
                                      ((l_1264 !=
                                        (l_1288 =
                                             ((g_745 =
                                                   (safe_mod_func_int32_t_s_s(
                                                       0xEAB3A0C8L,
                                                       (l_1208 = g_218)))) |
                                              p_18))) != l_1239[6]),
                                      8)),
                                  l_1239[6]) == 4294967295UL)) != 0xFF94L) &
                              0x69L)))))) ^
                  p_18));
          } else {
            int16_t l_1291 = 0x2C31L;
            int32_t l_1311 = 0xF8834343L;
            for (p_17 = 0; (p_17 != 7); p_17++) {
              int8_t l_1310 = 0x7EL;
              uint8_t l_1312 = 248UL;
              l_1291 = g_322[1][2];
              l_1312 =
                  (g_90 = (!(safe_rshift_func_int16_t_s_s(
                       (l_1311 =
                            ((safe_rshift_func_int8_t_s_s(
                                 (((safe_rshift_func_uint8_t_u_u(
                                       (safe_add_func_int32_t_s_s(
                                           (safe_mod_func_uint32_t_u_u(l_1207,
                                                                       6UL)),
                                           p_18)),
                                       (l_1204, 0x2CL))) |
                                   (-4L)) !=
                                  (safe_rshift_func_uint16_t_u_u(
                                      ((((safe_rshift_func_uint8_t_u_u(
                                             l_1271[4][0],
                                             (((safe_add_func_uint8_t_u_u(
                                                   (((safe_sub_func_int32_t_s_s(
                                                         (p_17 >
                                                          (l_1085 =
                                                               ((p_18, g_233) &
                                                                l_1310))),
                                                         p_19)) &
                                                     0x73DDL) > 1L),
                                                   0L)) == p_18) ^
                                              l_1310))) &&
                                         0xF7A46F60L) ||
                                        248UL) >= l_1264),
                                      14))),
                                 4)) &&
                             0UL)),
                       15))));
            }
          }
        } else {
          const uint8_t l_1328 = 0xC0L;
          int32_t l_1340 = 0x6DFA6B21L;
          int16_t l_1341 = 0xD6FCL;
          for (l_1204.f0 = 1; (l_1204.f0 <= 5); l_1204.f0 += 1) {
            int i, j;
            if ((((((((((safe_rshift_func_uint16_t_u_u(
                            (((+(l_1271[(l_1204.f0 + 2)][l_1204.f0],
                                 (p_17 &
                                  (l_1271[(l_1204.f0 + 1)][l_1204.f0] = (safe_lshift_func_int16_t_s_u(
                                       p_19,
                                       (((((p_19 && p_19) |
                                           (((((g_264 =
                                                    (l_993 <=
                                                     (((safe_sub_func_uint16_t_u_u(
                                                           l_1271[(
                                                               l_1204.f0 +
                                                               2)][l_1204.f0],
                                                           (l_1208,
                                                            ((((safe_mod_func_int16_t_s_s(
                                                                   ((safe_lshift_func_uint16_t_u_u(
                                                                        (((safe_sub_func_uint8_t_u_u(
                                                                              (safe_add_func_uint32_t_u_u(
                                                                                  (p_19,
                                                                                   l_1327),
                                                                                  0xC953E68FL)),
                                                                              0L)) &
                                                                          p_18) &
                                                                         0x1B45L),
                                                                        p_18)) &
                                                                    (-1L)),
                                                                   p_17)) &
                                                               g_1279) &&
                                                              0L) &&
                                                             p_19)))),
                                                       1L) |
                                                      0L))) <= g_20) |
                                              g_167[1][5]) ^
                                             8UL) &
                                            g_67)) != p_18) >= p_19) >
                                        1L))))))) <= p_18) > 1UL),
                            l_1209)) < p_19) == 1UL),
                      0xC4L) >= 6L),
                    l_1271[(l_1204.f0 + 2)][l_1204.f0]) ^
                   l_1328) &
                  0UL) > g_151[2][2])) {
              return g_25[0];
            } else {
              return g_208.f2;
            }
          }
          for (l_1281 = 20; (l_1281 >= (-7)); --l_1281) {
            int32_t l_1337[1];
            int i;
            for (i = 0; i < 1; i++)
              l_1337[i] = 1L;
            g_90 =
                (0xBA73956DL <=
                 (safe_add_func_uint8_t_u_u(
                     (l_1209 = 8UL),
                     (((65534UL || 0xF2DAL) &
                       ((g_598 || l_1203[2]) >
                        ((safe_add_func_int16_t_s_s(
                             ((safe_sub_func_uint32_t_u_u(
                                  ((p_17,
                                    (l_1337[0] >=
                                     ((((((l_1340 = (safe_add_func_int16_t_s_s(
                                               (0xC2L | p_17), 0xE971L))) |
                                          g_322[1][2]) > (-1L)) >=
                                        g_151[9][0]) > l_1341) != p_19))) ||
                                   (-4L)),
                                  l_1337[0])) > p_18),
                             p_19)) &&
                         0x5CCED47EL))) &
                      0x2DL))));
          }
        }
        for (g_20 = 0; (g_20 <= 2); g_20 += 1) {
          int i, j;
          if (g_322[(g_20 + 3)][g_20])
            break;
        }
        for (g_264 = 0; (g_264 == 39); ++g_264) {
          return p_17;
        }
        l_1211 = (safe_add_func_int16_t_s_s(
            ((l_1281 = (p_19, (g_218 = ((4294967295UL < (!l_1210)) >=
                                        (!(p_18 & 0x3CC9A2DCL)))))) ==
             (p_17 && 0x8AL)),
            ((p_19 & ((safe_lshift_func_int8_t_s_u(
                          (((g_164 != l_1271[6][4]) < 0L) > l_1204.f1), 3)) &
                      g_208.f1)) |
             l_1348)));
      }
      g_90 = (safe_lshift_func_uint8_t_u_u(0xC2L, 6));
      if (g_598)
        continue;
    }
  }
  for (g_264 = 9; (g_264 > 24); g_264++) {
    uint32_t l_983 = 0xB5BFB2B6L;
    int32_t l_1004 = 0L;
    uint32_t l_1057 = 6UL;
    int32_t l_1152 = 0xE5A4FC2DL;
    int16_t l_1180 = 0x9BB4L;
  }

  return g_598;
}

static uint8_t func_21(int32_t p_22, int32_t p_23) {
  int16_t l_24 = (-3L);
  int32_t l_961 = 0x9603CF04L;
  int32_t l_962[6] = {0xC6ECB169L, 0xC6ECB169L, 0L,
                      0xC6ECB169L, 0xC6ECB169L, 0L};
  int32_t l_963 = 0x317BB256L;
  int i;
  g_25[0] = (l_24 > l_24);
  l_963 =
      ((l_962[3] =
            (((g_28[1] = l_24) <
              (l_961 =
                   (((safe_rshift_func_int8_t_s_u(g_20, 6)) &&
                     (p_23 <= func_31(g_25[0], p_22,
                                      func_36(p_22,
                                              func_40(l_24, (g_25[0] != g_20),
                                                      p_23, l_24),
                                              g_25[0]),
                                      g_20))) |
                    g_20))) <= 0L)) &
       p_22);
  return g_28[1];
}

static int32_t func_31(int8_t p_32, uint32_t p_33, uint16_t p_34,
                       int32_t p_35) {
  int8_t l_955 = 0xA2L;
  int32_t l_956 = 0x7AFC0374L;
  l_955 = g_208.f2;
  for (g_251 = 0; (g_251 >= 0); g_251 -= 1) {
    return l_955;
  }
  p_35 =
      ((((p_34, g_208.f0) && (0x8E851EBBL <= 0xA64A3286L)) >=
        ((p_33 =
              (((((((l_956 = p_33) >=
                    (((0x65L & (l_955 ^ 0L)) |
                      ((safe_rshift_func_int8_t_s_s(
                           ((((safe_mod_func_uint16_t_u_u(65535UL, 0x30FAL)) !=
                              4294967287UL) > g_151[1][1]) ^
                            g_218),
                           g_164)) ^
                       p_34)) >= l_955)) |
                   g_151[2][2]) < p_33) |
                 p_35) &
                p_35) <= g_264)) > l_955)) > 0x22L);
  return g_167[2][2];
}

static uint16_t func_36(uint16_t p_37, union U0 p_38, int8_t p_39) {
  int8_t l_954 = 0L;
  return l_954;
}

static union U0 func_40(int32_t p_41, uint8_t p_42, int8_t p_43, int16_t p_44) {
  int32_t l_48[10] = {(-1L), 0xAB430688L, (-1L), 0xAB430688L,
                      (-1L), 0xAB430688L, (-1L), 0xAB430688L,
                      (-1L), 0xAB430688L};
  int32_t l_750 = (-5L);
  int32_t l_757 = 0x6317373DL;
  int32_t l_758[6] = {6L, 0x957FBD29L, 6L, 0x957FBD29L, 6L, 0x957FBD29L};
  union U0 l_791 = {2L};
  int32_t l_804 = 0L;
  uint32_t l_913 = 0xB29A7AEDL;
  uint32_t l_914 = 4294967291UL;
  int8_t l_921 = (-3L);
  uint16_t l_942[7] = {0xC1C7L, 65535UL, 0xC1C7L, 65535UL,
                       0xC1C7L, 65535UL, 0xC1C7L};
  uint32_t l_943 = 4294967295UL;
  int i;
  if ((func_45(l_48[5], g_20) >
       (g_208.f0,
        (((l_48[3] |
           ((safe_add_func_int32_t_s_s(
                ((((l_758[3] = (safe_mod_func_uint8_t_u_u(
                        ((l_750 = l_48[5]) |
                         (safe_rshift_func_uint16_t_u_u(
                             ((safe_add_func_uint8_t_u_u(
                                  ((((safe_sub_func_uint32_t_u_u(
                                         ((l_757 = (0x8C1CL | 0xC04BL)), p_44),
                                         g_218)) |
                                     l_48[5]),
                                    65531UL) == p_42),
                                  p_42)) ||
                              0x2FL),
                             15))),
                        p_43))) != (-1L)) &
                  p_43) ||
                 0x03L),
                g_322[1][2])),
            0xD852L)),
          l_758[3]) > g_745)))) {
    return g_208;
  } else {
    uint32_t l_771 = 4294967295UL;
    int32_t l_781 = (-6L);
    union U0 l_792 = {0x17E89B25L};
    int32_t l_809 = (-1L);
    uint32_t l_840[3][4][4] = {
        {{0xC6DA1F5AL, 4294967295UL, 0x39EB0CB2L, 4294967295UL},
         {0xC6DA1F5AL, 4294967295UL, 0x39EB0CB2L, 4294967295UL},
         {0xC6DA1F5AL, 4294967295UL, 0x39EB0CB2L, 4294967295UL},
         {0xC6DA1F5AL, 4294967295UL, 0x39EB0CB2L, 4294967295UL}},
        {{0xC6DA1F5AL, 4294967295UL, 0x39EB0CB2L, 4294967295UL},
         {0xC6DA1F5AL, 4294967295UL, 0x39EB0CB2L, 4294967295UL},
         {0xC6DA1F5AL, 4294967295UL, 0x39EB0CB2L, 4294967295UL},
         {0xC6DA1F5AL, 4294967295UL, 0x39EB0CB2L, 4294967295UL}},
        {{0xC6DA1F5AL, 4294967295UL, 0x39EB0CB2L, 4294967295UL},
         {0xC6DA1F5AL, 4294967295UL, 0x39EB0CB2L, 4294967295UL},
         {0xC6DA1F5AL, 4294967295UL, 0x39EB0CB2L, 4294967295UL},
         {0xC6DA1F5AL, 4294967295UL, 0x39EB0CB2L, 4294967295UL}}};
    int32_t l_863 = 0xA50F9BE2L;
    int i, j, k;
    g_66 = (-9L);
    g_66 = p_41;
    for (g_233 = 19; (g_233 <= 19);
         g_233 = safe_add_func_int16_t_s_s(g_233, 6)) {
      uint8_t l_772 = 248UL;
      uint16_t l_773[8] = {0xEF97L, 2UL, 0xEF97L, 2UL,
                           0xEF97L, 2UL, 0xEF97L, 2UL};
      int8_t l_790 = 0x85L;
      int32_t l_810 = 0x0A48B166L;
      int i;
      for (g_164 = 0; (g_164 <= 5); g_164 += 1) {
        union U0 l_805 = {0L};
        int32_t l_844 = 0x69029569L;
        int i, j;
        if (((g_218 =
                  ((((l_773[7] =
                          (((g_167[g_164][(g_164 + 2)] < l_758[g_164]) >
                            l_758[g_164]),
                           (((0x8322549CL || g_720) <
                             ((safe_mod_func_uint16_t_u_u(
                                  (!(0xAFL !=
                                     ((((safe_rshift_func_int16_t_s_s(
                                            (g_167[0][5] =
                                                 (((safe_rshift_func_int16_t_s_s(
                                                       ((p_43 =
                                                             (safe_add_func_int32_t_s_s(
                                                                 l_758[3],
                                                                 g_720))) ||
                                                        ((l_771 == l_758[4]) <
                                                         p_42)),
                                                       1)) <= 0x658E8D2FL),
                                                  l_772)),
                                            l_772)) ||
                                        g_25[0]) &
                                       p_42) <= p_42))),
                                  g_208.f0)) ||
                              l_771)) &&
                            p_42))) &
                     (-8L)) ^
                    g_745) == 0UL)) > p_44)) {
          uint32_t l_778 = 0x759574E1L;
          for (p_43 = 2; (p_43 >= 0); p_43 -= 1) {
            int i, j;
            g_66 =
                (((safe_add_func_uint8_t_u_u(
                      (safe_rshift_func_uint8_t_u_s(
                          (l_778,
                           (safe_rshift_func_uint16_t_u_s(
                               ((((g_167[5][1] =
                                       (((l_781 = p_43) >
                                         ((safe_sub_func_int32_t_s_s(
                                              (safe_lshift_func_uint8_t_u_s(
                                                  (safe_sub_func_uint8_t_u_u(
                                                      l_771, (-1L))),
                                                  (g_208,
                                                   (safe_sub_func_int8_t_s_s(
                                                       0x9DL,
                                                       (p_42 &
                                                        (((p_44 !=
                                                           (g_151[(g_164 + 2)]
                                                                 [p_43] =
                                                                     (l_790 !=
                                                                      p_41))),
                                                          l_791),
                                                         0xF1L))))))),
                                              p_42)) |
                                          5L)) != 0L)) <= p_41) >= p_44) >=
                                p_41),
                               0))),
                          2)),
                      g_25[0])) &
                  l_772) &&
                 g_745);
          }
          return l_792;
        } else {
          uint8_t l_795 = 0UL;
          int32_t l_832[6][3][3] = {{{9L, 0x11DD8167L, 0x11DD8167L},
                                     {9L, 0x11DD8167L, 0x11DD8167L},
                                     {9L, 0x11DD8167L, 0x11DD8167L}},
                                    {{9L, 0x11DD8167L, 0x11DD8167L},
                                     {9L, 0x11DD8167L, 0x11DD8167L},
                                     {9L, 0x11DD8167L, 0x11DD8167L}},
                                    {{9L, 0x11DD8167L, 0x11DD8167L},
                                     {9L, 0x11DD8167L, 0x11DD8167L},
                                     {9L, 0x11DD8167L, 0x11DD8167L}},
                                    {{9L, 0x11DD8167L, 0x11DD8167L},
                                     {9L, 0x11DD8167L, 0x11DD8167L},
                                     {9L, 0x11DD8167L, 0x11DD8167L}},
                                    {{9L, 0x11DD8167L, 0x11DD8167L},
                                     {9L, 0x11DD8167L, 0x11DD8167L},
                                     {9L, 0x11DD8167L, 0x11DD8167L}},
                                    {{9L, 0x11DD8167L, 0x11DD8167L},
                                     {9L, 0x11DD8167L, 0x11DD8167L},
                                     {9L, 0x11DD8167L, 0x11DD8167L}}};
          int i, j, k;
          g_90 = 1L;
          {
            union U0 l_805 = {0L};
            int32_t l_844 = 0x69029569L;
            int i, j;
            if (((g_218 =
                      ((((l_773[7] =
                              (((g_167[g_164][(g_164 + 2)] < l_758[g_164]) >
                                l_758[g_164]),
                               (((0x8322549CL || g_720) <
                                 ((safe_mod_func_uint16_t_u_u(
                                      (!(0xAFL !=
                                         ((((safe_rshift_func_int16_t_s_s(
                                                (g_167[0][5] =
                                                     (((safe_rshift_func_int16_t_s_s(
                                                           ((p_43 =
                                                                 (safe_add_func_int32_t_s_s(
                                                                     l_758[3],
                                                                     g_720))) ||
                                                            ((l_771 ==
                                                              l_758[4]) <
                                                             p_42)),
                                                           1)) <= 0x658E8D2FL),
                                                      l_772)),
                                                l_772)) ||
                                            g_25[0]) &
                                           p_42) <= p_42))),
                                      g_208.f0)) ||
                                  l_771)) &&
                                p_42))) &
                         (-8L)) ^
                        g_745) == 0UL)) > p_44)) {
              uint32_t l_778 = 0x759574E1L;
              for (p_43 = 2; (p_43 >= 0); p_43 -= 1) {
                int i, j;
                g_66 =
                    (((safe_add_func_uint8_t_u_u(
                          (safe_rshift_func_uint8_t_u_s(
                              (l_778,
                               (safe_rshift_func_uint16_t_u_s(
                                   ((((g_167[5][1] =
                                           (((l_781 = p_43) >
                                             ((safe_sub_func_int32_t_s_s(
                                                  (safe_lshift_func_uint8_t_u_s(
                                                      (safe_sub_func_uint8_t_u_u(
                                                          l_771, (-1L))),
                                                      (g_208,
                                                       (safe_sub_func_int8_t_s_s(
                                                           0x9DL,
                                                           (p_42 &
                                                            (((p_44 !=
                                                               (g_151[(
                                                                    g_164 +
                                                                    2)][p_43] =
                                                                    (l_790 !=
                                                                     p_41))),
                                                              l_791),
                                                             0xF1L))))))),
                                                  p_42)) |
                                              5L)) != 0L)) <= p_41) >= p_44) >=
                                    p_41),
                                   0))),
                              2)),
                          g_25[0])) &
                      l_772) &&
                     g_745);
              }
              return l_792;
            } else {
              uint8_t l_795 = 0UL;
              int32_t l_832[6][3][3] = {{{9L, 0x11DD8167L, 0x11DD8167L},
                                         {9L, 0x11DD8167L, 0x11DD8167L},
                                         {9L, 0x11DD8167L, 0x11DD8167L}},
                                        {{9L, 0x11DD8167L, 0x11DD8167L},
                                         {9L, 0x11DD8167L, 0x11DD8167L},
                                         {9L, 0x11DD8167L, 0x11DD8167L}},
                                        {{9L, 0x11DD8167L, 0x11DD8167L},
                                         {9L, 0x11DD8167L, 0x11DD8167L},
                                         {9L, 0x11DD8167L, 0x11DD8167L}},
                                        {{9L, 0x11DD8167L, 0x11DD8167L},
                                         {9L, 0x11DD8167L, 0x11DD8167L},
                                         {9L, 0x11DD8167L, 0x11DD8167L}},
                                        {{9L, 0x11DD8167L, 0x11DD8167L},
                                         {9L, 0x11DD8167L, 0x11DD8167L},
                                         {9L, 0x11DD8167L, 0x11DD8167L}},
                                        {{9L, 0x11DD8167L, 0x11DD8167L},
                                         {9L, 0x11DD8167L, 0x11DD8167L},
                                         {9L, 0x11DD8167L, 0x11DD8167L}}};
              int i, j, k;
              g_90 = 1L;
              l_758[g_164] =
                  ((l_772 == p_43) !=
                   ((g_623 = 1UL),
                    (g_151[2][2] &
                     (l_791,
                      (g_598 = (((l_48[5], p_41) !=
                                 (0x7DBCL >=
                                  ((safe_mod_func_uint16_t_u_u(p_42, g_208.f1)),
                                   l_795))),
                                g_208.f1))))));
              if ((g_208,
                   (l_758[g_164] =
                        ((0xC2L != g_208.f1) <=
                         (g_90 |
                          (((!0x7EBB2B6CL), 5UL) |
                           (safe_rshift_func_uint8_t_u_s(
                               1UL, (safe_mod_func_int16_t_s_s(
                                        (((l_792.f1, l_772) <= 0L) && l_758[3]),
                                        g_372)))))))))) {
                union U0 l_808 = {-1L};
                int32_t l_815[6] = {1L, 0xAE10E44DL, 1L,
                                    0xAE10E44DL, 1L, 0xAE10E44DL};
                int i;
                g_90 = l_795;
                p_41 = (safe_add_func_uint8_t_u_u(
                    (((g_25[0] >=
                       (p_42 =
                            (p_42 <
                             (safe_add_func_uint32_t_u_u(
                                 0x16126D34L,
                                 ((l_815[0] =
                                       ((l_804 >
                                         (l_805,
                                          (safe_rshift_func_uint8_t_u_u(
                                              ((l_810 =
                                                    (l_808, (l_809 && p_41))) <
                                               (safe_rshift_func_int8_t_s_u(
                                                   (safe_add_func_uint32_t_u_u(
                                                       (~(((+((l_795 & p_41) |
                                                              0x36CEL)) >=
                                                           8UL) >=
                                                          0x78170C6AL)),
                                                       1UL)),
                                                   g_745))),
                                              0)))) >= 0x55L)) >= 65535UL)))))),
                      g_233) &
                     g_164),
                    p_43));
                return l_792;
              } else {
                int16_t l_833 = 0xF06AL;
                g_66 =
                    (g_90 = (safe_rshift_func_int8_t_s_s(
                         (0x0EL >
                          (safe_mod_func_uint8_t_u_u(
                              (((g_151[0][0] = (safe_add_func_uint32_t_u_u(
                                     (g_208.f1 !=
                                      (+(g_25[0] <
                                         (g_208,
                                          (safe_mod_func_uint8_t_u_u(
                                              ((safe_add_func_int16_t_s_s(
                                                   ((((g_720 =
                                                           (((l_810 >=
                                                              ((g_90 | 0xEFL) >=
                                                               l_773[7])) !=
                                                             (!(safe_sub_func_int32_t_s_s(
                                                                 (safe_sub_func_int16_t_s_s(
                                                                     (((((safe_mod_func_uint8_t_u_u(
                                                                             ((l_832[1][0][2] =
                                                                                   (l_773
                                                                                        [7],
                                                                                    l_832
                                                                                        [1]
                                                                                        [0]
                                                                                        [2])) ||
                                                                              g_25[0]),
                                                                             p_44)),
                                                                         g_167
                                                                             [4]
                                                                             [0]),
                                                                        g_66) >
                                                                       0x79757B04L),
                                                                      g_322[1]
                                                                           [2]),
                                                                     0x6C98L)),
                                                                 l_772)))) |
                                                            l_805.f0)),
                                                      p_41) > 0x7A0AL),
                                                    g_598),
                                                   1UL)) == l_805.f1),
                                              l_833)))))),
                                     l_791.f0))) == 65535UL) ||
                               p_41),
                              p_43))),
                         l_805.f2)));
              }
              for (p_41 = 22; (p_41 >= (-2)); --p_41) {
                g_66 = ((safe_sub_func_uint16_t_u_u(l_810, (-1L))) >
                        (g_623 = 0x8BL));
              }
            }
            l_840[2][0][1] = (safe_sub_func_uint32_t_u_u(g_598, l_791.f1));
            for (g_745 = 0; (g_745 <= 7); g_745 += 1) {
              int i;
              g_90 = ((!(safe_sub_func_int16_t_s_s(
                          (safe_unary_minus_func_int16_t_s(
                              (p_44 = ((l_773[g_745] || (~p_41)) <= g_233)))),
                          l_844))),
                      (+3L));
            }
            for (l_809 = 9; (l_809 >= 0); l_809 -= 1) {
              int i;
              if (l_48[l_809])
                break;
              for (g_66 = 1; (g_66 <= 7); g_66 += 1) {
                int i;
                if (l_758[g_164])
                  break;
                if (l_773[g_164])
                  continue;
              }
            }
          }

          l_758[g_164] =
              ((l_772 == p_43) !=
               ((g_623 = 1UL),
                (g_151[2][2] &
                 (l_791, (g_598 = (((l_48[5], p_41) !=
                                    (0x7DBCL >= ((safe_mod_func_uint16_t_u_u(
                                                     p_42, g_208.f1)),
                                                 l_795))),
                                   g_208.f1))))));
          if ((g_208,
               (l_758[g_164] =
                    ((0xC2L != g_208.f1) <=
                     (g_90 |
                      (((!0x7EBB2B6CL), 5UL) |
                       (safe_rshift_func_uint8_t_u_s(
                           1UL, (safe_mod_func_int16_t_s_s(
                                    (((l_792.f1, l_772) <= 0L) && l_758[3]),
                                    g_372)))))))))) {
            union U0 l_808 = {-1L};
            int32_t l_815[6] = {1L, 0xAE10E44DL, 1L,
                                0xAE10E44DL, 1L, 0xAE10E44DL};
            int i;

            for (g_164 = 0; (g_164 <= 5); g_164 += 1) {
              union U0 l_805 = {0L};
              int32_t l_844 = 0x69029569L;
              int i, j;
              if (((g_218 =
                        ((((l_773[7] =
                                (((g_167[g_164][(g_164 + 2)] < l_758[g_164]) >
                                  l_758[g_164]),
                                 (((0x8322549CL || g_720) <
                                   ((safe_mod_func_uint16_t_u_u(
                                        (!(0xAFL !=
                                           ((((safe_rshift_func_int16_t_s_s(
                                                  (g_167[0][5] =
                                                       (((safe_rshift_func_int16_t_s_s(
                                                             ((p_43 =
                                                                   (safe_add_func_int32_t_s_s(
                                                                       l_758[3],
                                                                       g_720))) ||
                                                              ((l_771 ==
                                                                l_758[4]) <
                                                               p_42)),
                                                             1)) <=
                                                         0x658E8D2FL),
                                                        l_772)),
                                                  l_772)) ||
                                              g_25[0]) &
                                             p_42) <= p_42))),
                                        g_208.f0)) ||
                                    l_771)) &&
                                  p_42))) &
                           (-8L)) ^
                          g_745) == 0UL)) > p_44)) {
                uint32_t l_778 = 0x759574E1L;
                for (p_43 = 2; (p_43 >= 0); p_43 -= 1) {
                  int i, j;
                  g_66 =
                      (((safe_add_func_uint8_t_u_u(
                            (safe_rshift_func_uint8_t_u_s(
                                (l_778,
                                 (safe_rshift_func_uint16_t_u_s(
                                     ((((g_167[5][1] =
                                             (((l_781 = p_43) >
                                               ((safe_sub_func_int32_t_s_s(
                                                    (safe_lshift_func_uint8_t_u_s(
                                                        (safe_sub_func_uint8_t_u_u(
                                                            l_771, (-1L))),
                                                        (g_208,
                                                         (safe_sub_func_int8_t_s_s(
                                                             0x9DL,
                                                             (p_42 &
                                                              (((p_44 !=
                                                                 (g_151[(
                                                                      g_164 +
                                                                      2)][p_43] =
                                                                      (l_790 !=
                                                                       p_41))),
                                                                l_791),
                                                               0xF1L))))))),
                                                    p_42)) |
                                                5L)) != 0L)) <= p_41) >=
                                       p_44) >= p_41),
                                     0))),
                                2)),
                            g_25[0])) &
                        l_772) &&
                       g_745);
                }
                return l_792;
              } else {
                uint8_t l_795 = 0UL;
                int32_t l_832[6][3][3] = {{{9L, 0x11DD8167L, 0x11DD8167L},
                                           {9L, 0x11DD8167L, 0x11DD8167L},
                                           {9L, 0x11DD8167L, 0x11DD8167L}},
                                          {{9L, 0x11DD8167L, 0x11DD8167L},
                                           {9L, 0x11DD8167L, 0x11DD8167L},
                                           {9L, 0x11DD8167L, 0x11DD8167L}},
                                          {{9L, 0x11DD8167L, 0x11DD8167L},
                                           {9L, 0x11DD8167L, 0x11DD8167L},
                                           {9L, 0x11DD8167L, 0x11DD8167L}},
                                          {{9L, 0x11DD8167L, 0x11DD8167L},
                                           {9L, 0x11DD8167L, 0x11DD8167L},
                                           {9L, 0x11DD8167L, 0x11DD8167L}},
                                          {{9L, 0x11DD8167L, 0x11DD8167L},
                                           {9L, 0x11DD8167L, 0x11DD8167L},
                                           {9L, 0x11DD8167L, 0x11DD8167L}},
                                          {{9L, 0x11DD8167L, 0x11DD8167L},
                                           {9L, 0x11DD8167L, 0x11DD8167L},
                                           {9L, 0x11DD8167L, 0x11DD8167L}}};
                int i, j, k;
                g_90 = 1L;
                l_758[g_164] =
                    ((l_772 == p_43) !=
                     ((g_623 = 1UL),
                      (g_151[2][2] &
                       (l_791,
                        (g_598 = (((l_48[5], p_41) !=
                                   (0x7DBCL >= ((safe_mod_func_uint16_t_u_u(
                                                    p_42, g_208.f1)),
                                                l_795))),
                                  g_208.f1))))));
                if ((g_208,
                     (l_758[g_164] =
                          ((0xC2L != g_208.f1) <=
                           (g_90 | (((!0x7EBB2B6CL), 5UL) |
                                    (safe_rshift_func_uint8_t_u_s(
                                        1UL, (safe_mod_func_int16_t_s_s(
                                                 (((l_792.f1, l_772) <= 0L) &&
                                                  l_758[3]),
                                                 g_372)))))))))) {
                  union U0 l_808 = {-1L};
                  int32_t l_815[6] = {1L, 0xAE10E44DL, 1L,
                                      0xAE10E44DL, 1L, 0xAE10E44DL};
                  int i;
                  g_90 = l_795;
                  p_41 = (safe_add_func_uint8_t_u_u(
                      (((g_25[0] >=
                         (p_42 =
                              (p_42 <
                               (safe_add_func_uint32_t_u_u(
                                   0x16126D34L,
                                   ((l_815[0] =
                                         ((l_804 >
                                           (l_805,
                                            (safe_rshift_func_uint8_t_u_u(
                                                ((l_810 = (l_808,
                                                           (l_809 && p_41))) <
                                                 (safe_rshift_func_int8_t_s_u(
                                                     (safe_add_func_uint32_t_u_u(
                                                         (~(((+((l_795 & p_41) |
                                                                0x36CEL)) >=
                                                             8UL) >=
                                                            0x78170C6AL)),
                                                         1UL)),
                                                     g_745))),
                                                0)))) >= 0x55L)) >=
                                    65535UL)))))),
                        g_233) &
                       g_164),
                      p_43));
                  return l_792;
                } else {
                  int16_t l_833 = 0xF06AL;
                  g_66 =
                      (g_90 = (safe_rshift_func_int8_t_s_s(
                           (0x0EL >
                            (safe_mod_func_uint8_t_u_u(
                                (((g_151[0][0] = (safe_add_func_uint32_t_u_u(
                                       (g_208.f1 !=
                                        (+(g_25[0] <
                                           (g_208,
                                            (safe_mod_func_uint8_t_u_u(
                                                ((safe_add_func_int16_t_s_s(
                                                     ((((g_720 =
                                                             (((l_810 >=
                                                                ((g_90 |
                                                                  0xEFL) >=
                                                                 l_773[7])) !=
                                                               (!(safe_sub_func_int32_t_s_s(
                                                                   (safe_sub_func_int16_t_s_s(
                                                                       (((((safe_mod_func_uint8_t_u_u(
                                                                               ((l_832[1][0][2] =
                                                                                     (l_773
                                                                                          [7],
                                                                                      l_832
                                                                                          [1]
                                                                                          [0]
                                                                                          [2])) ||
                                                                                g_25[0]),
                                                                               p_44)),
                                                                           g_167
                                                                               [4]
                                                                               [0]),
                                                                          g_66) >
                                                                         0x79757B04L),
                                                                        g_322
                                                                            [1]
                                                                            [2]),
                                                                       0x6C98L)),
                                                                   l_772)))) |
                                                              l_805.f0)),
                                                        p_41) > 0x7A0AL),
                                                      g_598),
                                                     1UL)) == l_805.f1),
                                                l_833)))))),
                                       l_791.f0))) == 65535UL) ||
                                 p_41),
                                p_43))),
                           l_805.f2)));
                }
                for (p_41 = 22; (p_41 >= (-2)); --p_41) {
                  g_66 = ((safe_sub_func_uint16_t_u_u(l_810, (-1L))) >
                          (g_623 = 0x8BL));
                }
              }
              l_840[2][0][1] = (safe_sub_func_uint32_t_u_u(g_598, l_791.f1));
              for (g_745 = 0; (g_745 <= 7); g_745 += 1) {
                int i;
                g_90 = ((!(safe_sub_func_int16_t_s_s(
                            (safe_unary_minus_func_int16_t_s(
                                (p_44 = ((l_773[g_745] || (~p_41)) <= g_233)))),
                            l_844))),
                        (+3L));
              }
              for (l_809 = 9; (l_809 >= 0); l_809 -= 1) {
                int i;
                if (l_48[l_809])
                  break;
                for (g_66 = 1; (g_66 <= 7); g_66 += 1) {
                  int i;
                  if (l_758[g_164])
                    break;
                  if (l_773[g_164])
                    continue;
                }
              }
            }

            { return g_208; }

            return l_792;
          } else {
            int16_t l_833 = 0xF06AL;
            g_66 =
                (g_90 = (safe_rshift_func_int8_t_s_s(
                     (0x0EL >
                      (safe_mod_func_uint8_t_u_u(
                          (((g_151[0][0] = (safe_add_func_uint32_t_u_u(
                                 (g_208.f1 !=
                                  (+(g_25[0] <
                                     (g_208,
                                      (safe_mod_func_uint8_t_u_u(
                                          ((safe_add_func_int16_t_s_s(
                                               ((((g_720 =
                                                       (((l_810 >=
                                                          ((g_90 | 0xEFL) >=
                                                           l_773[7])) !=
                                                         (!(safe_sub_func_int32_t_s_s(
                                                             (safe_sub_func_int16_t_s_s(
                                                                 (((((safe_mod_func_uint8_t_u_u(
                                                                         ((l_832[1][0][2] =
                                                                               (l_773
                                                                                    [7],
                                                                                l_832
                                                                                    [1]
                                                                                    [0]
                                                                                    [2])) ||
                                                                          g_25[0]),
                                                                         p_44)),
                                                                     g_167[4]
                                                                          [0]),
                                                                    g_66) >
                                                                   0x79757B04L),
                                                                  g_322[1][2]),
                                                                 0x6C98L)),
                                                             l_772)))) |
                                                        l_805.f0)),
                                                  p_41) > 0x7A0AL),
                                                g_598),
                                               1UL)) == l_805.f1),
                                          l_833)))))),
                                 l_791.f0))) == 65535UL) ||
                           p_41),
                          p_43))),
                     l_805.f2)));
            {
              union U0 l_808 = {-1L};
              int32_t l_815[6] = {1L, 0xAE10E44DL, 1L,
                                  0xAE10E44DL, 1L, 0xAE10E44DL};
              int i;
              g_90 = l_795;
              p_41 = (safe_add_func_uint8_t_u_u(
                  (((g_25[0] >=
                     (p_42 =
                          (p_42 <
                           (safe_add_func_uint32_t_u_u(
                               0x16126D34L,
                               ((l_815[0] =
                                     ((l_804 >
                                       (l_805,
                                        (safe_rshift_func_uint8_t_u_u(
                                            ((l_810 =
                                                  (l_808, (l_809 && p_41))) <
                                             (safe_rshift_func_int8_t_s_u(
                                                 (safe_add_func_uint32_t_u_u(
                                                     (~(((+((l_795 & p_41) |
                                                            0x36CEL)) >= 8UL) >=
                                                        0x78170C6AL)),
                                                     1UL)),
                                                 g_745))),
                                            0)))) >= 0x55L)) >= 65535UL)))))),
                    g_233) &
                   g_164),
                  p_43));
              return l_792;
            }
          }
          if (((g_218 =
                    ((((l_773[7] =
                            (((g_167[g_164][(g_164 + 2)] < l_758[g_164]) >
                              l_758[g_164]),
                             (((0x8322549CL || g_720) <
                               ((safe_mod_func_uint16_t_u_u(
                                    (!(0xAFL !=
                                       ((((safe_rshift_func_int16_t_s_s(
                                              (g_167[0][5] =
                                                   (((safe_rshift_func_int16_t_s_s(
                                                         ((p_43 =
                                                               (safe_add_func_int32_t_s_s(
                                                                   l_758[3],
                                                                   g_720))) ||
                                                          ((l_771 == l_758[4]) <
                                                           p_42)),
                                                         1)) <= 0x658E8D2FL),
                                                    l_772)),
                                              l_772)) ||
                                          g_25[0]) &
                                         p_42) <= p_42))),
                                    g_208.f0)) ||
                                l_771)) &&
                              p_42))) &
                       (-8L)) ^
                      g_745) == 0UL)) > p_44)) {
            uint32_t l_778 = 0x759574E1L;
            for (p_43 = 2; (p_43 >= 0); p_43 -= 1) {
              int i, j;
              g_66 =
                  (((safe_add_func_uint8_t_u_u(
                        (safe_rshift_func_uint8_t_u_s(
                            (l_778,
                             (safe_rshift_func_uint16_t_u_s(
                                 ((((g_167[5][1] =
                                         (((l_781 = p_43) >
                                           ((safe_sub_func_int32_t_s_s(
                                                (safe_lshift_func_uint8_t_u_s(
                                                    (safe_sub_func_uint8_t_u_u(
                                                        l_771, (-1L))),
                                                    (g_208,
                                                     (safe_sub_func_int8_t_s_s(
                                                         0x9DL,
                                                         (p_42 &
                                                          (((p_44 !=
                                                             (g_151[(g_164 + 2)]
                                                                   [p_43] =
                                                                       (l_790 !=
                                                                        p_41))),
                                                            l_791),
                                                           0xF1L))))))),
                                                p_42)) |
                                            5L)) != 0L)) <= p_41) >= p_44) >=
                                  p_41),
                                 0))),
                            2)),
                        g_25[0])) &
                    l_772) &&
                   g_745);
            }
            return l_792;
          } else {
            uint8_t l_795 = 0UL;
            int32_t l_832[6][3][3] = {{{9L, 0x11DD8167L, 0x11DD8167L},
                                       {9L, 0x11DD8167L, 0x11DD8167L},
                                       {9L, 0x11DD8167L, 0x11DD8167L}},
                                      {{9L, 0x11DD8167L, 0x11DD8167L},
                                       {9L, 0x11DD8167L, 0x11DD8167L},
                                       {9L, 0x11DD8167L, 0x11DD8167L}},
                                      {{9L, 0x11DD8167L, 0x11DD8167L},
                                       {9L, 0x11DD8167L, 0x11DD8167L},
                                       {9L, 0x11DD8167L, 0x11DD8167L}},
                                      {{9L, 0x11DD8167L, 0x11DD8167L},
                                       {9L, 0x11DD8167L, 0x11DD8167L},
                                       {9L, 0x11DD8167L, 0x11DD8167L}},
                                      {{9L, 0x11DD8167L, 0x11DD8167L},
                                       {9L, 0x11DD8167L, 0x11DD8167L},
                                       {9L, 0x11DD8167L, 0x11DD8167L}},
                                      {{9L, 0x11DD8167L, 0x11DD8167L},
                                       {9L, 0x11DD8167L, 0x11DD8167L},
                                       {9L, 0x11DD8167L, 0x11DD8167L}}};
            int i, j, k;
            g_90 = 1L;
            l_758[g_164] =
                ((l_772 == p_43) !=
                 ((g_623 = 1UL),
                  (g_151[2][2] &
                   (l_791, (g_598 = (((l_48[5], p_41) !=
                                      (0x7DBCL >= ((safe_mod_func_uint16_t_u_u(
                                                       p_42, g_208.f1)),
                                                   l_795))),
                                     g_208.f1))))));
            if ((g_208,
                 (l_758[g_164] =
                      ((0xC2L != g_208.f1) <=
                       (g_90 |
                        (((!0x7EBB2B6CL), 5UL) |
                         (safe_rshift_func_uint8_t_u_s(
                             1UL, (safe_mod_func_int16_t_s_s(
                                      (((l_792.f1, l_772) <= 0L) && l_758[3]),
                                      g_372)))))))))) {
              union U0 l_808 = {-1L};
              int32_t l_815[6] = {1L, 0xAE10E44DL, 1L,
                                  0xAE10E44DL, 1L, 0xAE10E44DL};
              int i;
              g_90 = l_795;
              p_41 = (safe_add_func_uint8_t_u_u(
                  (((g_25[0] >=
                     (p_42 =
                          (p_42 <
                           (safe_add_func_uint32_t_u_u(
                               0x16126D34L,
                               ((l_815[0] =
                                     ((l_804 >
                                       (l_805,
                                        (safe_rshift_func_uint8_t_u_u(
                                            ((l_810 =
                                                  (l_808, (l_809 && p_41))) <
                                             (safe_rshift_func_int8_t_s_u(
                                                 (safe_add_func_uint32_t_u_u(
                                                     (~(((+((l_795 & p_41) |
                                                            0x36CEL)) >= 8UL) >=
                                                        0x78170C6AL)),
                                                     1UL)),
                                                 g_745))),
                                            0)))) >= 0x55L)) >= 65535UL)))))),
                    g_233) &
                   g_164),
                  p_43));
              return l_792;
            } else {
              int16_t l_833 = 0xF06AL;
              g_66 =
                  (g_90 = (safe_rshift_func_int8_t_s_s(
                       (0x0EL >
                        (safe_mod_func_uint8_t_u_u(
                            (((g_151[0][0] = (safe_add_func_uint32_t_u_u(
                                   (g_208.f1 !=
                                    (+(g_25[0] <
                                       (g_208,
                                        (safe_mod_func_uint8_t_u_u(
                                            ((safe_add_func_int16_t_s_s(
                                                 ((((g_720 =
                                                         (((l_810 >=
                                                            ((g_90 | 0xEFL) >=
                                                             l_773[7])) !=
                                                           (!(safe_sub_func_int32_t_s_s(
                                                               (safe_sub_func_int16_t_s_s(
                                                                   (((((safe_mod_func_uint8_t_u_u(
                                                                           ((l_832[1][0][2] =
                                                                                 (l_773
                                                                                      [7],
                                                                                  l_832
                                                                                      [1]
                                                                                      [0]
                                                                                      [2])) ||
                                                                            g_25[0]),
                                                                           p_44)),
                                                                       g_167
                                                                           [4]
                                                                           [0]),
                                                                      g_66) >
                                                                     0x79757B04L),
                                                                    g_322[1]
                                                                         [2]),
                                                                   0x6C98L)),
                                                               l_772)))) |
                                                          l_805.f0)),
                                                    p_41) > 0x7A0AL),
                                                  g_598),
                                                 1UL)) == l_805.f1),
                                            l_833)))))),
                                   l_791.f0))) == 65535UL) ||
                             p_41),
                            p_43))),
                       l_805.f2)));
            }
            for (p_41 = 22; (p_41 >= (-2)); --p_41) {
              g_66 = ((safe_sub_func_uint16_t_u_u(l_810, (-1L))) >
                      (g_623 = 0x8BL));
            }
          }

          for (p_41 = 22; (p_41 >= (-2)); --p_41) {
            g_66 =
                ((safe_sub_func_uint16_t_u_u(l_810, (-1L))) > (g_623 = 0x8BL));
          }
          {
            int16_t l_833 = 0xF06AL;
            g_66 =
                (g_90 = (safe_rshift_func_int8_t_s_s(
                     (0x0EL >
                      (safe_mod_func_uint8_t_u_u(
                          (((g_151[0][0] = (safe_add_func_uint32_t_u_u(
                                 (g_208.f1 !=
                                  (+(g_25[0] <
                                     (g_208,
                                      (safe_mod_func_uint8_t_u_u(
                                          ((safe_add_func_int16_t_s_s(
                                               ((((g_720 =
                                                       (((l_810 >=
                                                          ((g_90 | 0xEFL) >=
                                                           l_773[7])) !=
                                                         (!(safe_sub_func_int32_t_s_s(
                                                             (safe_sub_func_int16_t_s_s(
                                                                 (((((safe_mod_func_uint8_t_u_u(
                                                                         ((l_832[1][0][2] =
                                                                               (l_773
                                                                                    [7],
                                                                                l_832
                                                                                    [1]
                                                                                    [0]
                                                                                    [2])) ||
                                                                          g_25[0]),
                                                                         p_44)),
                                                                     g_167[4]
                                                                          [0]),
                                                                    g_66) >
                                                                   0x79757B04L),
                                                                  g_322[1][2]),
                                                                 0x6C98L)),
                                                             l_772)))) |
                                                        l_805.f0)),
                                                  p_41) > 0x7A0AL),
                                                g_598),
                                               1UL)) == l_805.f1),
                                          l_833)))))),
                                 l_791.f0))) == 65535UL) ||
                           p_41),
                          p_43))),
                     l_805.f2)));
          }
        }
        l_840[2][0][1] = (safe_sub_func_uint32_t_u_u(g_598, l_791.f1));
        { return g_208; }

        g_66 = (-9L);
      }
    }
  }
  p_41 = (safe_mod_func_int8_t_s_s(
      ((g_233 |
        (l_913 >
         (l_914 >
          (((((((safe_mod_func_uint16_t_u_u(0UL, g_598)) >= (-6L)) >=
               l_48[5]) &&
              (safe_sub_func_uint8_t_u_u(
                  (safe_mod_func_uint16_t_u_u((l_750, (8L == (-10L))), 8L)),
                  l_913))),
             g_218) != l_750) &
           g_218)))) ^
       p_41),
      l_921));
  { return g_208; }

  g_90 =
      (((safe_sub_func_uint16_t_u_u(
            g_322[1][2],
            (safe_mod_func_uint32_t_u_u(
                ((safe_sub_func_uint32_t_u_u(g_67, p_43)) | l_750), p_44)))) ||
        (p_44 = ((l_804 = p_41) ==
                 (safe_add_func_uint16_t_u_u(p_41, (l_750 = 65535UL)))))) &
       (((safe_lshift_func_int16_t_s_u(g_25[0], l_942[6])) >= l_757), 65535UL));
  return g_208;
}

static int8_t func_45(int8_t p_46, uint32_t p_47) {
  uint32_t l_57[5][5][1] = {{{1UL}, {1UL}, {1UL}, {1UL}, {1UL}},
                            {{1UL}, {1UL}, {1UL}, {1UL}, {1UL}},
                            {{1UL}, {1UL}, {1UL}, {1UL}, {1UL}},
                            {{1UL}, {1UL}, {1UL}, {1UL}, {1UL}},
                            {{1UL}, {1UL}, {1UL}, {1UL}, {1UL}}};
  union U0 l_68 = {8L};
  int32_t l_568[3];
  int32_t l_661 = 1L;
  const int8_t l_679 = 0xB6L;
  int8_t l_728 = 0L;
  uint16_t l_739 = 0x06EBL;
  int i, j, k;
  for (i = 0; i < 3; i++)
    l_568[i] = 1L;
  for (p_46 = 18; (p_46 <= 14); p_46 = safe_sub_func_int8_t_s_s(p_46, 6)) {
    uint8_t l_60 = 255UL;
    int32_t l_65 = 8L;
    int32_t l_599[9];
    int16_t l_602 = 1L;
    int8_t l_622 = 1L;
    int32_t l_678 = 0L;
    int16_t l_700 = (-1L);
    uint32_t l_721 = 1UL;
    int i;
    for (i = 0; i < 9; i++)

    {
      {
        uint8_t l_60 = 255UL;
        int32_t l_65 = 8L;
        int32_t l_599[9];
        int16_t l_602 = 1L;
        int8_t l_622 = 1L;
        int32_t l_678 = 0L;
        int16_t l_700 = (-1L);
        uint32_t l_721 = 1UL;
        int i;
        for (i = 0; i < 9; i++)
          l_599[i] = 1L;
      }
    }

    for (p_46 = 18; (p_46 <= 14); p_46 = safe_sub_func_int8_t_s_s(p_46, 6)) {
      uint8_t l_60 = 255UL;
      int32_t l_65 = 8L;
      int32_t l_599[9];
      int16_t l_602 = 1L;
      int8_t l_622 = 1L;
      int32_t l_678 = 0L;
      int16_t l_700 = (-1L);
      uint32_t l_721 = 1UL;
      int i;
      for (i = 0; i < 9; i++)
        l_599[i] = 1L;
    }
  }
  g_66 = p_47;
  return l_728;
}

static int32_t func_51(uint16_t p_52, uint32_t p_53, uint8_t p_54,
                       union U0 p_55, int32_t p_56) {
  int32_t l_69 = 0x0E685266L;
  int32_t l_78 = 7L;
  int32_t l_79 = 0xC99C4DB7L;
  int8_t l_128[6];
  uint8_t l_141[8][3][1] = {
      {{255UL}, {255UL}, {255UL}}, {{255UL}, {255UL}, {255UL}},
      {{255UL}, {255UL}, {255UL}}, {{255UL}, {255UL}, {255UL}},
      {{255UL}, {255UL}, {255UL}}, {{255UL}, {255UL}, {255UL}},
      {{255UL}, {255UL}, {255UL}}, {{255UL}, {255UL}, {255UL}}};
  uint32_t l_194 = 0UL;
  union U0 l_250 = {0x79FF8554L};
  int32_t l_385[6][5][8] = {{{(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL}},
                            {{(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL}},
                            {{(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL}},
                            {{(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL}},
                            {{(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL}},
                            {{(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL},
                             {(-6L), (-1L), 0x3D792CEEL, 0xB4597DB1L, 0L, 1L,
                              0xDCEFEB4FL, 0xDCEFEB4FL}}};
  int16_t l_507[8][10] = {{0x5A5CL, 0x99BAL, 0xC6B7L, 0x679EL, 0L, (-3L), (-7L),
                           0x9A37L, (-1L), (-2L)},
                          {0x5A5CL, 0x99BAL, 0xC6B7L, 0x679EL, 0L, (-3L), (-7L),
                           0x9A37L, (-1L), (-2L)},
                          {0x5A5CL, 0x99BAL, 0xC6B7L, 0x679EL, 0L, (-3L), (-7L),
                           0x9A37L, (-1L), (-2L)},
                          {0x5A5CL, 0x99BAL, 0xC6B7L, 0x679EL, 0L, (-3L), (-7L),
                           0x9A37L, (-1L), (-2L)},
                          {0x5A5CL, 0x99BAL, 0xC6B7L, 0x679EL, 0L, (-3L), (-7L),
                           0x9A37L, (-1L), (-2L)},
                          {0x5A5CL, 0x99BAL, 0xC6B7L, 0x679EL, 0L, (-3L), (-7L),
                           0x9A37L, (-1L), (-2L)},
                          {0x5A5CL, 0x99BAL, 0xC6B7L, 0x679EL, 0L, (-3L), (-7L),
                           0x9A37L, (-1L), (-2L)},
                          {0x5A5CL, 0x99BAL, 0xC6B7L, 0x679EL, 0L, (-3L), (-7L),
                           0x9A37L, (-1L), (-2L)}};
  int8_t l_532[3];
  uint8_t l_557 = 9UL;
  int16_t l_558 = 0xF2EBL;
  int32_t l_559 = 1L;
  int i, j, k;
  for (i = 0; i < 6; i++)
    ;

  for (i = 0; i < 6; i++)
    l_128[i] = 0L;

  for (i = 0; i < 3; i++) {
    l_532[i] = 0L;
    for (i = 0; i < 3; i++)
      l_532[i] = 0L;
  }

  l_69 = p_55.f2;
  for (i = 0; i < 3; i++)
    l_532[i] = 0L;

  if ((g_66 = (safe_rshift_func_int16_t_s_s(
           ((safe_mod_func_uint32_t_u_u(
                (safe_add_func_int8_t_s_s(
                    l_69,
                    (safe_sub_func_int8_t_s_s(
                        ((l_79 = (l_78 = (0x82L ^ g_25[0]))) ||
                         (safe_add_func_int16_t_s_s(g_25[0], p_55.f0))),
                        ((((safe_sub_func_int32_t_s_s(
                               (g_20 >= (safe_sub_func_uint32_t_u_u(
                                            g_25[0],
                                            (((safe_lshift_func_int16_t_s_s(
                                                  (safe_lshift_func_uint8_t_u_s(
                                                      (g_90 = ((l_69, g_67) ==
                                                               p_55.f0)),
                                                      3)),
                                                  3)) |
                                              0x1368L),
                                             0x77DABF26L)))),
                               0x4C01D5BCL)) ||
                           g_67) ||
                          246UL) &&
                         l_69))))),
                0x71515025L)) |
            l_69),
           6)))) {
    int32_t l_98 = 0xF216A9CAL;
    int32_t l_107[1];
    uint16_t l_168[1][6] = {{0UL, 65529UL, 0UL, 65529UL, 0UL, 65529UL}};
    int32_t l_219[9] = {0xF7F2E4BEL, 0xF7F2E4BEL, 0x21EC393FL,
                        0xF7F2E4BEL, 0xF7F2E4BEL, 0x21EC393FL,
                        0xF7F2E4BEL, 0xF7F2E4BEL, 0x21EC393FL};
    int i, j;
    for (i = 0; i < 1; i++)

    {
      l_69 = p_55.f2;
    }

    for (i = 0; i < 1; i++)
      l_107[i] = 6L;

    for (g_90 = 21; (g_90 == 24); g_90 = safe_add_func_uint16_t_u_u(g_90, 5)) {
      int8_t l_97 = 1L;
      uint8_t l_135 = 248UL;
      int32_t l_169[5] = {0x08DD124EL, 1L, 0x08DD124EL, 1L, 0x08DD124EL};
      int32_t l_192 = 0L;
      int i;
    }
    {
      int32_t l_98 = 0xF216A9CAL;
      int32_t l_107[1];
      uint16_t l_168[1][6] = {{0UL, 65529UL, 0UL, 65529UL, 0UL, 65529UL}};
      int32_t l_219[9] = {0xF7F2E4BEL, 0xF7F2E4BEL, 0x21EC393FL,
                          0xF7F2E4BEL, 0xF7F2E4BEL, 0x21EC393FL,
                          0xF7F2E4BEL, 0xF7F2E4BEL, 0x21EC393FL};
      int i, j;
      for (i = 0; i < 1; i++)
        l_107[i] = 6L;
      for (g_90 = 21; (g_90 == 24);
           g_90 = safe_add_func_uint16_t_u_u(g_90, 5)) {
        int8_t l_97 = 1L;
        uint8_t l_135 = 248UL;
        int32_t l_169[5] = {0x08DD124EL, 1L, 0x08DD124EL, 1L, 0x08DD124EL};
        int32_t l_192 = 0L;
        int i;
      }
    }

  } else {
    int32_t l_247 = (-1L);
    uint32_t l_297 = 3UL;
    int32_t l_341 = 0x05E8E35BL;
    int32_t l_379 = (-3L);
    int32_t l_381 = 0xC81BA072L;
    uint32_t l_430 = 0xBD10AD33L;
    int32_t l_473 = 6L;

    l_381 =
        (g_66 =
             ((safe_sub_func_uint8_t_u_u(
                  (safe_rshift_func_int16_t_s_s(
                      ((g_67 =
                            (p_52 =
                                 ((l_78 ^
                                   (((l_379 && (-9L)) <=
                                     ((((0x53A7L <
                                         (+((safe_rshift_func_uint16_t_u_u(
                                                (safe_sub_func_int32_t_s_s(
                                                    ((250UL >=
                                                      (safe_mod_func_int8_t_s_s(
                                                          1L, 0x3FL))) !=
                                                     0x7C5429EBL),
                                                    g_25[0])),
                                                g_25[0])) > l_247))) !=
                                        l_250.f2),
                                       p_52),
                                      65528UL)) ^
                                    g_67)) != p_55.f2))) >= g_251),
                      2)),
                  l_297)) != l_250.f1));

    for (i = 0; i < 6; i++)
      l_128[i] = 0L;
  }
  for (i = 0; i < 3; i++)
    l_532[i] = 0L;

  for (p_55.f0 = 0; (p_55.f0 <= 0); p_55.f0 += 1) {
    uint32_t l_474[10][7][3] = {{{0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL}},
                                {{0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL}},
                                {{0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL}},
                                {{0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL}},
                                {{0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL}},
                                {{0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL}},
                                {{0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL}},
                                {{0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL}},
                                {{0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL}},
                                {{0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL},
                                 {0x755148FBL, 4294967290UL, 0UL}}};
    int8_t l_487[1];
    int32_t l_500[5][2] = {{0x3AF742B0L, 0L},
                           {0x3AF742B0L, 0L},
                           {0x3AF742B0L, 0L},
                           {0x3AF742B0L, 0L},
                           {0x3AF742B0L, 0L}};
    uint32_t l_509 = 7UL;
    int32_t l_529 = (-9L);
    union U0 l_546 = {0x63780ED2L};
    int i, j, k;
    for (i = 0; i < 1; i++)
      l_487[i] = 0x79L;
    for (l_250.f1 = 0; (l_250.f1 <= 0); l_250.f1 += 1) {
      int32_t l_479 = 0x76CFE393L;
      int32_t l_488 = 0x5A875E03L;
      int32_t l_489 = 0x064A395DL;
      l_474[0][1][2] = g_167[2][2];
      for (p_54 = 0; (p_54 <= 0); p_54 += 1) {
        int32_t l_484 = (-1L);
        uint32_t l_515 = 0x3DDB3EEAL;
        int8_t l_530[7][3][10] = {{{0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)}},
                                  {{0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)}},
                                  {{0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)}},
                                  {{0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)}},
                                  {{0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)}},
                                  {{0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)}},
                                  {{0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)},
                                   {0x7CL, (-10L), (-1L), 0x8BL, (-10L), (-9L),
                                    0x79L, 1L, (-1L), (-10L)}}};
        int8_t l_531 = 0xF2L;
        int i, j, k;
        l_489 =
            ((!((((((((l_488 = ((l_141[(p_54 + 6)][(p_54 + 2)][p_54] =
                                     (safe_add_func_int16_t_s_s(
                                         (l_479 ^ (safe_mod_func_uint32_t_u_u(
                                                      g_167[2][2], p_55.f1))),
                                         (safe_sub_func_uint8_t_u_u(
                                             1UL, l_484))))) ||
                                ((g_322[5][2] ^
                                  (((g_208.f2 <
                                     (g_167[2][2] <
                                      ((safe_lshift_func_uint8_t_u_u(
                                           (l_141[(p_54 + 7)][(l_250.f1 + 2)]
                                                 [p_55.f0] = (l_479 ^ p_55.f0)),
                                           1)),
                                       l_479))) < g_322[1][2]) != l_487[0])),
                                 0xD1L))) > g_66) > g_208.f2) == 1UL) > p_56) !=
                  0x22A1L) &
                 0L),
                p_55.f1)),
             (-1L));
        for (p_53 = 6; (p_53 == 12); p_53++) {
          uint8_t l_508 = 0xB4L;
          int32_t l_510 = 0L;
          g_66 =
              (l_510 = (safe_lshift_func_uint8_t_u_s(
                   ((((((g_151[3][2] ==
                         (((safe_sub_func_uint32_t_u_u(
                               0UL,
                               ((((((safe_lshift_func_uint16_t_u_u(6UL, 9)) <
                                    (l_479 ||
                                     ((safe_sub_func_uint16_t_u_u(
                                          (0x64173A46L >=
                                           (l_500[0][1] = l_484)),
                                          (((safe_sub_func_int32_t_s_s(
                                                (l_141[(p_54 + 6)][(p_54 + 2)]
                                                      [p_54] !=
                                                 ((((g_151[9][2] >=
                                                     (safe_lshift_func_uint16_t_u_u(
                                                         ((safe_mod_func_int32_t_s_s(
                                                              g_322[1][2],
                                                              0x326939B5L)) |
                                                          g_322[1][2]),
                                                         15))) >= g_20) <
                                                   l_507[4][9]) <= (-1L))),
                                                p_55.f2)) ^
                                            (-7L)) ^
                                           l_508))) >= l_509))) >= 0UL) ||
                                  g_218),
                                 p_56) ==
                                l_141[(p_54 + 7)][(l_250.f1 + 2)][p_55.f0]))),
                           p_55.f0),
                          1UL)) |
                        0xF2L) &
                       0x4C1AL) |
                      g_151[9][0]) |
                     p_56) > 1UL),
                   1)));
          for (l_69 = 0; (l_69 == (-23));
               l_69 = safe_sub_func_int16_t_s_s(l_69, 2)) {
            int32_t l_522 = 1L;
            l_385[4][0][4] =
                (((!(((+(safe_sub_func_uint16_t_u_u(
                          ((((l_515 = g_218),
                             ((~(safe_add_func_uint16_t_u_u(
                                  (l_532[2] =
                                       (g_25[0],
                                        ((l_500[0][1] >=
                                          (safe_sub_func_int16_t_s_s(
                                              (((safe_lshift_func_uint8_t_u_s(
                                                    l_522, 4)),
                                                (((l_529 =
                                                       ((+(((safe_sub_func_int8_t_s_s(
                                                                (p_55.f1 ^ 1L),
                                                                ((safe_lshift_func_uint16_t_u_u(
                                                                     (g_67 =
                                                                          ((safe_lshift_func_int16_t_s_s(
                                                                               (l_500
                                                                                    [0]
                                                                                    [1],
                                                                                (~l_522)),
                                                                               (g_67,
                                                                                g_25[0]))) ^
                                                                           p_52)),
                                                                     12)) ^
                                                                 p_55.f1))) ||
                                                            l_489) &&
                                                           p_55.f0)) ==
                                                        g_20)) >= l_508) ^
                                                 0x8CL)) |
                                               l_530[6][2][6]),
                                              g_233))) >= l_531))),
                                  l_507[4][9]))) > 0UL)) < 0L) > p_56),
                          g_167[1][7]))) == l_522) ^
                     0x08L)),
                  l_522) != l_474[0][1][2]);
          }
        }
      }
    }
    g_66 =
        ((((safe_lshift_func_uint16_t_u_s(
               (safe_unary_minus_func_uint16_t_u(p_52)),
               (((((((safe_lshift_func_int8_t_s_u(
                         ((((safe_sub_func_uint8_t_u_u(
                                (safe_rshift_func_uint16_t_u_u(
                                    (l_500[2][1] = 0UL),
                                    (safe_add_func_int16_t_s_s(
                                        (safe_lshift_func_uint16_t_u_u(
                                            (l_546,
                                             (l_78 = (safe_sub_func_int32_t_s_s(
                                                  g_66,
                                                  (safe_sub_func_uint8_t_u_u(
                                                      (safe_lshift_func_int8_t_s_u(
                                                          ((((((safe_sub_func_int16_t_s_s(
                                                                   0x3C6EL,
                                                                   ((g_208,
                                                                     (l_385[5][0][0] = (~(
                                                                          (safe_add_func_int32_t_s_s(
                                                                              g_164,
                                                                              4294967288UL)) ==
                                                                          (l_79 =
                                                                               ((l_529 =
                                                                                     (0xDD35L >
                                                                                      g_251)) <
                                                                                l_509)))))) >
                                                                    0x20356C5EL))) <
                                                               l_557) <
                                                              g_151[0][2]) >
                                                             l_558) < p_55.f1),
                                                           p_55.f1),
                                                          1)),
                                                      5L)))))),
                                            12)),
                                        65533UL)))),
                                g_167[5][0])) |
                            g_372) ^
                           p_52) &
                          p_55.f2),
                         p_53)) == g_25[0]) ^
                    0xE68DD99FL) == g_372) < l_194) ^
                 0xE312L),
                p_55.f0))) >= 0L),
          0xA55FL) <= g_167[2][2]);
  }

  return g_372;
}

int main(int argc, char *argv[]) {
  int i, j, k;
  int print_hash_value = 0;
  if (argc == 2 && strcmp(argv[1], "1") == 0)
  crc32_gentab();
  func_1();
  transparent_crc(g_20, "g_20", print_hash_value);
  for (i = 0; i < 1; i++) {
    transparent_crc(g_25[i], "g_25[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  for (i = 0; i < 3; i++) {
    transparent_crc(g_28[i], "g_28[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_66, "g_66", print_hash_value);
  transparent_crc(g_67, "g_67", print_hash_value);
  transparent_crc(g_90, "g_90", print_hash_value);
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 3; j++) {
      transparent_crc(g_151[i][j], "g_151[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_164, "g_164", print_hash_value);
  for (i = 0; i < 6; i++) {
    for (j = 0; j < 8; j++) {
      transparent_crc(g_167[i][j], "g_167[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_208.f1, "g_208.f1", print_hash_value);
  transparent_crc(g_208.f2, "g_208.f2", print_hash_value);
  transparent_crc(g_218, "g_218", print_hash_value);
  transparent_crc(g_233, "g_233", print_hash_value);
  transparent_crc(g_251, "g_251", print_hash_value);
  transparent_crc(g_264, "g_264", print_hash_value);
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 3; j++) {
      transparent_crc(g_322[i][j], "g_322[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_372, "g_372", print_hash_value);
  transparent_crc(g_598, "g_598", print_hash_value);
  transparent_crc(g_623, "g_623", print_hash_value);
  transparent_crc(g_720, "g_720", print_hash_value);
  transparent_crc(g_745, "g_745", print_hash_value);
  transparent_crc(g_976, "g_976", print_hash_value);
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 1; j++) {
      transparent_crc(g_978[i][j], "g_978[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_1279, "g_1279", print_hash_value);
  transparent_crc(g_1445, "g_1445", print_hash_value);
  transparent_crc(g_1467, "g_1467", print_hash_value);
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 7; j++) {
      for (k = 0; k < 3; k++) {
        transparent_crc(g_1550[i][j][k], "g_1550[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_1574, "g_1574", print_hash_value);
  transparent_crc(g_1705, "g_1705", print_hash_value);
  transparent_crc(g_1706, "g_1706", print_hash_value);
  transparent_crc(g_1781, "g_1781", print_hash_value);
  transparent_crc(g_1916, "g_1916", print_hash_value);
  transparent_crc(g_1918.f0, "g_1918.f0", print_hash_value);
  transparent_crc(g_1918.f1, "g_1918.f1", print_hash_value);
  transparent_crc(g_1918.f2, "g_1918.f2", print_hash_value);
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 4; k++) {
        transparent_crc(g_1939[i][j][k], "g_1939[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}

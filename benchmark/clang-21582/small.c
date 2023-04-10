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

static void transparent_crc(uint32_t val, char* vname, int flag) {
  crc32_8bytes(val);
  if (flag) {
    printf("...checksum after hashing %s : %X\n", vname,
           crc32_context ^ 0xFFFFFFFFU);
  }
}
static void transparent_crc_bytes(char* ptr, int nbytes, char* vname,
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

struct S0 {
  int32_t f0;
  const uint16_t f1;
  const uint32_t f2;
  const int32_t f3;
  uint32_t f4;
  uint32_t f5;
  uint16_t f6;
};

struct S1 {
  uint8_t f0;
  int32_t f1;
  uint16_t f2;
  uint32_t f3;
  uint16_t f4;
  const int16_t f5;
};

struct S2 {
  int32_t f0;
  uint8_t f1;
  int16_t f2;
  uint32_t f3;
  int16_t f4;
  int16_t f5;
  uint16_t f6;
};

static const struct S0 g_5[1] = {
    {1L, 5UL, 0xC63C4078L, 1L, 0xC25B054DL, 0xBE56890CL, 0x4408L}};
static uint32_t g_16 = 0xE5161E33L;
static uint32_t g_17[8] = {4294967289UL, 5UL, 4294967289UL, 5UL,
                           4294967289UL, 5UL, 4294967289UL, 5UL};
static uint16_t g_22 = 65535UL;
static struct S2 g_28 = {0x3CC114FFL, 0xA9L, 0xA76AL, 1UL, 0x0519L, -1L, 9UL};
static struct S2 g_76[5][4][10] = {
    {{{1L, 0x93L, 0xB6BEL, 7UL, 0xBBDFL, -9L, 0xA4B2L},
      {-1L, 2UL, 0L, 0x36661290L, 0L, 0L, 65529UL},
      {-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x491F1F15L, 252UL, 0x96B5L, 0x1468E88EL, -1L, -3L, 0UL},
      {-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {-1L, 2UL, 0L, 0x36661290L, 0L, 0L, 65529UL},
      {1L, 0x93L, 0xB6BEL, 7UL, 0xBBDFL, -9L, 0xA4B2L},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {-2L, 254UL, -1L, 0x37CDB552L, 0xD6D4L, 0x0C11L, 0x42F3L},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL}},
     {{0xFDDCEC70L, 5UL, 3L, 0x445E426DL, 0x7943L, 0x2B23L, 0x0CBEL},
      {-1L, 2UL, 0L, 0x36661290L, 0L, 0L, 65529UL},
      {0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x491F1F15L, 252UL, 0x96B5L, 0x1468E88EL, -1L, -3L, 0UL},
      {0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {-1L, 2UL, 0L, 0x36661290L, 0L, 0L, 65529UL},
      {0xFDDCEC70L, 5UL, 3L, 0x445E426DL, 0x7943L, 0x2B23L, 0x0CBEL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {-2L, 0xD0L, -1L, 0xD8B2F8DCL, 8L, 0xBAAFL, 6UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL}},
     {{1L, 0x93L, 0xB6BEL, 7UL, 0xBBDFL, -9L, 0xA4B2L},
      {-1L, 2UL, 0L, 0x36661290L, 0L, 0L, 65529UL},
      {-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x491F1F15L, 252UL, 0x96B5L, 0x1468E88EL, -1L, -3L, 0UL},
      {-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {-1L, 2UL, 0L, 0x36661290L, 0L, 0L, 65529UL},
      {1L, 0x93L, 0xB6BEL, 7UL, 0xBBDFL, -9L, 0xA4B2L},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {-2L, 254UL, -1L, 0x37CDB552L, 0xD6D4L, 0x0C11L, 0x42F3L},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL}},
     {{0xFDDCEC70L, 5UL, 3L, 0x445E426DL, 0x7943L, 0x2B23L, 0x0CBEL},
      {-1L, 2UL, 0L, 0x36661290L, 0L, 0L, 65529UL},
      {0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x491F1F15L, 252UL, 0x96B5L, 0x1468E88EL, -1L, -3L, 0UL},
      {0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {-1L, 2UL, 0L, 0x36661290L, 0L, 0L, 65529UL},
      {0xFDDCEC70L, 5UL, 3L, 0x445E426DL, 0x7943L, 0x2B23L, 0x0CBEL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0x1021D522L, 0x42L, 0x98E8L, 0xF6226F77L, 0x7A5BL, 0x85A9L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}}},
    {{{-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0xDF6318FFL, 0x4DL, 0L, 0xD499989FL, 0x4E93L, 0x460CL, 0x5032L},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}},
     {{0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0x1021D522L, 0x42L, 0x98E8L, 0xF6226F77L, 0x7A5BL, 0x85A9L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}},
     {{-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0xDF6318FFL, 0x4DL, 0L, 0xD499989FL, 0x4E93L, 0x460CL, 0x5032L},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}},
     {{0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0x1021D522L, 0x42L, 0x98E8L, 0xF6226F77L, 0x7A5BL, 0x85A9L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}}},
    {{{-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0xDF6318FFL, 0x4DL, 0L, 0xD499989FL, 0x4E93L, 0x460CL, 0x5032L},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}},
     {{0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0x1021D522L, 0x42L, 0x98E8L, 0xF6226F77L, 0x7A5BL, 0x85A9L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}},
     {{-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0xDF6318FFL, 0x4DL, 0L, 0xD499989FL, 0x4E93L, 0x460CL, 0x5032L},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}},
     {{0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0x1021D522L, 0x42L, 0x98E8L, 0xF6226F77L, 0x7A5BL, 0x85A9L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}}},
    {{{-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0xDF6318FFL, 0x4DL, 0L, 0xD499989FL, 0x4E93L, 0x460CL, 0x5032L},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}},
     {{0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0x1021D522L, 0x42L, 0x98E8L, 0xF6226F77L, 0x7A5BL, 0x85A9L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}},
     {{-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0xDF6318FFL, 0x4DL, 0L, 0xD499989FL, 0x4E93L, 0x460CL, 0x5032L},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}},
     {{0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0x1021D522L, 0x42L, 0x98E8L, 0xF6226F77L, 0x7A5BL, 0x85A9L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}}},
    {{{-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0xDF6318FFL, 0x4DL, 0L, 0xD499989FL, 0x4E93L, 0x460CL, 0x5032L},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}},
     {{0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0x1021D522L, 0x42L, 0x98E8L, 0xF6226F77L, 0x7A5BL, 0x85A9L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}},
     {{-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {6L, 0x0DL, 0x3939L, 0x282F80E5L, 0x6308L, 0x2EBDL, 65527UL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {-1L, 0x79L, 0x12DCL, 4294967294UL, 1L, 3L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0xDF6318FFL, 0x4DL, 0L, 0xD499989FL, 0x4E93L, 0x460CL, 0x5032L},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}},
     {{0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0xD186C8CCL, 2UL, 0x6F9DL, 4294967295UL, 0x7ECAL, 0x0655L, 0xB860L},
      {0x2E7BD33CL, 0UL, -1L, 0xC40DF3FCL, 0x1527L, 0x319CL, 0xE683L},
      {0x2E2C5736L, 250UL, 1L, 0xCAF8AA5BL, 1L, 6L, 0x3ECDL},
      {0xF1A53783L, 0UL, 1L, 0xD59BB75FL, 0xF1AFL, -4L, 0x327DL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L},
      {0x1021D522L, 0x42L, 0x98E8L, 0xF6226F77L, 0x7A5BL, 0x85A9L, 65535UL},
      {0x2F772B8AL, 0UL, -8L, 0x0AD585B8L, 0xFC90L, 0L, 0xB137L}}}};
static uint8_t g_146 = 252UL;
static int8_t g_159 = 0x13L;
static int16_t g_160 = (-1L);
static int32_t g_162 = 8L;
static int32_t g_181 = 0x41F1B08CL;
static uint32_t g_223 = 0x5C1F3B26L;
static struct S2 g_290 = {-1L, 249UL, -1L, 1UL, 0L, 0xF8BFL, 65533UL};
static uint8_t g_368[6] = {0xABL, 0xC9L, 0xC9L, 0xABL, 0xC9L, 0xC9L};
static int32_t g_374 = 1L;
static uint16_t g_380[4][3] = {{65535UL, 0x87ECL, 0x87ECL},
                               {65535UL, 0x87ECL, 0x87ECL},
                               {65535UL, 0x87ECL, 0x87ECL},
                               {65535UL, 0x87ECL, 0x87ECL}};
static int16_t g_392 = 0L;
static struct S1 g_415[4][3] = {
    {{0x2CL, 0x004BFDDCL, 0x9246L, 0x7C76657BL, 65535UL, 1L},
     {0x2CL, 0x004BFDDCL, 0x9246L, 0x7C76657BL, 65535UL, 1L},
     {0x2CL, 0x004BFDDCL, 0x9246L, 0x7C76657BL, 65535UL, 1L}},
    {{0x2CL, 0x004BFDDCL, 0x9246L, 0x7C76657BL, 65535UL, 1L},
     {0x2CL, 0x004BFDDCL, 0x9246L, 0x7C76657BL, 65535UL, 1L},
     {0x2CL, 0x004BFDDCL, 0x9246L, 0x7C76657BL, 65535UL, 1L}},
    {{0x2CL, 0x004BFDDCL, 0x9246L, 0x7C76657BL, 65535UL, 1L},
     {0x2CL, 0x004BFDDCL, 0x9246L, 0x7C76657BL, 65535UL, 1L},
     {0x2CL, 0x004BFDDCL, 0x9246L, 0x7C76657BL, 65535UL, 1L}},
    {{0x2CL, 0x004BFDDCL, 0x9246L, 0x7C76657BL, 65535UL, 1L},
     {0x2CL, 0x004BFDDCL, 0x9246L, 0x7C76657BL, 65535UL, 1L},
     {0x2CL, 0x004BFDDCL, 0x9246L, 0x7C76657BL, 65535UL, 1L}}};
static int32_t g_447 = 1L;
static uint16_t g_449 = 2UL;
static int32_t g_467 = 1L;
static int8_t g_468 = 0x16L;
static int16_t g_470 = 0xEE57L;
static uint16_t g_472[2][2][10] = {
    {{0x567DL, 0x567DL, 65535UL, 65529UL, 65535UL, 0x567DL, 0x567DL, 65535UL,
      65529UL, 65535UL},
     {0x567DL, 0x567DL, 65535UL, 65529UL, 65535UL, 0x567DL, 0x567DL, 65535UL,
      65529UL, 65535UL}},
    {{0x567DL, 0x567DL, 65535UL, 65529UL, 65535UL, 0x567DL, 0x567DL, 65535UL,
      65529UL, 65535UL},
     {0x567DL, 0x567DL, 65535UL, 65529UL, 65535UL, 0x567DL, 0x567DL, 65535UL,
      65529UL, 65535UL}}};
static uint8_t g_580 = 0x7CL;
static int16_t g_584 = (-1L);
static int16_t g_766 = 0xF7E8L;
static uint16_t g_811 = 0UL;
static int16_t g_845 = (-1L);
static uint32_t g_846[9][8] = {
    {4294967295UL, 0xC48835D1L, 4294967295UL, 0x2E1A3ECEL, 4294967295UL,
     0x2E1A3ECEL, 4294967295UL, 0xC48835D1L},
    {4294967295UL, 0x2E1A3ECEL, 4294967295UL, 0xC48835D1L, 4294967295UL,
     0x2E1A3ECEL, 4294967295UL, 0x2E1A3ECEL},
    {4294967295UL, 0xC48835D1L, 4294967290UL, 0xC48835D1L, 4294967295UL,
     4294967295UL, 4294967295UL, 0xC48835D1L},
    {4294967295UL, 0xC48835D1L, 4294967295UL, 0x2E1A3ECEL, 4294967295UL,
     0x2E1A3ECEL, 4294967295UL, 0xC48835D1L},
    {4294967295UL, 0x2E1A3ECEL, 4294967295UL, 0xC48835D1L, 4294967295UL,
     0x2E1A3ECEL, 4294967295UL, 0x2E1A3ECEL},
    {4294967295UL, 0xC48835D1L, 4294967290UL, 0xC48835D1L, 4294967295UL,
     4294967295UL, 4294967295UL, 0xC48835D1L},
    {4294967295UL, 0xC48835D1L, 4294967295UL, 0x2E1A3ECEL, 4294967295UL,
     0x2E1A3ECEL, 4294967295UL, 0xC48835D1L},
    {4294967295UL, 0x2E1A3ECEL, 4294967295UL, 0xC48835D1L, 4294967295UL,
     0x2E1A3ECEL, 4294967295UL, 0x2E1A3ECEL},
    {4294967295UL, 0xC48835D1L, 4294967290UL, 0xC48835D1L, 4294967295UL,
     4294967295UL, 4294967295UL, 0xC48835D1L}};
static uint16_t g_1038 = 0xC903L;
static int32_t g_1160 = 0x2F524F45L;
static uint32_t g_1220 = 0UL;

static uint32_t func_1(void);
static int32_t func_2(const struct S0 p_3, int32_t p_4);
static int32_t func_6(int32_t p_7, uint32_t p_8, uint32_t p_9);
static int32_t func_20(const int8_t p_21);
static uint32_t func_30(struct S2 p_31, int32_t p_32);
static int8_t func_48(uint8_t p_49, uint8_t p_50, const struct S2 p_51,
                      int32_t p_52, uint32_t p_53);
static uint8_t func_54(uint8_t p_55, int32_t p_56, uint8_t p_57, int16_t p_58,
                       int8_t p_59);
static uint8_t func_61(struct S0 p_62);
static int16_t func_67(int8_t p_68, struct S0 p_69, uint32_t p_70,
                       struct S0 p_71, int32_t p_72);
static uint16_t func_83(int8_t p_84);
static uint32_t func_1(void) {
  uint32_t l_10 = 0x80EBBD48L;
  int32_t l_1165 = 0L;
  int32_t l_1172 = 1L;
  struct S2 l_1174[8] = {{0x1747EB85L, 0x27L, 0x4B97L, 0UL, 0x97E7L, -7L, 0UL},
                         {0L, 0x04L, 5L, 0UL, 0xFF98L, 0x60A8L, 65531UL},
                         {0x1747EB85L, 0x27L, 0x4B97L, 0UL, 0x97E7L, -7L, 0UL},
                         {0L, 0x04L, 5L, 0UL, 0xFF98L, 0x60A8L, 65531UL},
                         {0x1747EB85L, 0x27L, 0x4B97L, 0UL, 0x97E7L, -7L, 0UL},
                         {0L, 0x04L, 5L, 0UL, 0xFF98L, 0x60A8L, 65531UL},
                         {0x1747EB85L, 0x27L, 0x4B97L, 0UL, 0x97E7L, -7L, 0UL},
                         {0L, 0x04L, 5L, 0UL, 0xFF98L, 0x60A8L, 65531UL}};
  uint8_t l_1224 = 255UL;
  int8_t l_1235 = 4L;
  int i;
  g_1160 ^= func_2(g_5[0], func_6(l_10, g_5[0].f0, l_10));
  for (g_470 = 2; (g_470 <= 7); g_470 += 1) {
    uint8_t l_1168 = 254UL;
    int32_t l_1173 = 0x0525A6C0L;
    int8_t l_1219 = 0L;
    const int8_t l_1231[6][2] = {{7L, (-8L)}, {7L, 7L}, {(-8L), 7L},
                                 {7L, (-8L)}, {7L, 7L}, {(-8L), 7L}};
    int i, j;
    g_1160 = g_223;
    for (l_10 = 1; (l_10 <= 7); l_10 += 1) {
      int32_t l_1171 = (-1L);
      struct S2 l_1175[6] = {{-8L, 0x4DL, -1L, 0UL, 0x0C9CL, 0x8F60L, 65532UL},
                             {-8L, 0x4DL, -1L, 0UL, 0x0C9CL, 0x8F60L, 65532UL},
                             {-8L, 0x4DL, -1L, 0UL, 0x0C9CL, 0x8F60L, 65532UL},
                             {-8L, 0x4DL, -1L, 0UL, 0x0C9CL, 0x8F60L, 65532UL},
                             {-8L, 0x4DL, -1L, 0UL, 0x0C9CL, 0x8F60L, 65532UL},
                             {-8L, 0x4DL, -1L, 0UL, 0x0C9CL, 0x8F60L, 65532UL}};
      struct S2 l_1176 = {0xFF608FDCL, 255UL, 0x0A2AL, 0x4E527192L,
                          -9L, 1L, 0x4C68L};
      struct S0 l_1202 = {0x203D7C02L, 0x80CCL, 0xF8AFA3A7L, 0L,
                          0UL, 0xB6297DA5L, 0x6BD6L};
      int32_t l_1247 = 0L;
      uint16_t l_1253 = 6UL;
      int32_t l_1254 = (-6L);
      int i, j;
      l_1176 =
          ((l_1165 |= (safe_add_func_int32_t_s_s(
                9L, (safe_lshift_func_uint8_t_u_s(
                        (g_846[(g_470 + 1)][g_470] | 0xA1B7L), 4))))),
           (l_1175[1] =
                (g_290 =
                     (g_76[2][1][8] =
                          (((l_1172 =
                                 (((safe_add_func_int16_t_s_s(
                                       0xCE01L, g_447)) <= (l_1168 = (-5L))) !=
                                  ((safe_lshift_func_uint8_t_u_u(
                                       (l_1165 = (l_1171 = 1UL)), 2)) ||
                                   g_368[2]))) >
                            ((g_415[0][0].f2 || g_28.f1) & l_1173)),
                           l_1174[5])))));
      for (l_1176.f6 = 0; (l_1176.f6 <= 2); l_1176.f6 += 1) {
        uint32_t l_1192 = 0xA367585FL;
        int8_t l_1221 = 0x65L;
        int32_t l_1223[9] = {0xB95B59E8L, 0x92B8BBFBL, 0xB95B59E8L,
                             0x92B8BBFBL, 0xB95B59E8L, 0x92B8BBFBL,
                             0xB95B59E8L, 0x92B8BBFBL, 0xB95B59E8L};
        int32_t l_1234[9];
        int i;
        for (i = 0; i < 9; i++) l_1234[i] = 0L;
        for (g_181 = 1; (g_181 <= 7); g_181 += 1) {
          int32_t l_1195 = 0x3149E29DL;
          uint32_t l_1222 = 0UL;
          int i;
          for (g_28.f2 = 7; (g_28.f2 >= 0); g_28.f2 -= 1) {
            int i, j;
            l_1195 =
                ((safe_mul_func_uint16_t_u_u(
                     ((safe_lshift_func_int16_t_s_s(0xFADBL, 2)) <
                      ((65528UL ==
                        (safe_mod_func_uint8_t_u_u(
                            (safe_add_func_int8_t_s_s(
                                (l_1172 |= g_380[l_1176.f6][l_1176.f6]),
                                (safe_mod_func_int16_t_s_s(
                                    ((((-4L) ==
                                       (((((g_380[l_1176.f6][l_1176.f6],
                                            ((g_368[(l_1176.f6 + 1)] !=
                                              (safe_lshift_func_int8_t_s_u(
                                                  (safe_unary_minus_func_uint32_t_u(
                                                      (g_415[0][0].f3 =
                                                           ((safe_mod_func_int32_t_s_s(
                                                                (g_1160 =
                                                                     l_1192),
                                                                (g_17[g_181] =
                                                                     ((safe_mod_func_int16_t_s_s(
                                                                          (l_1195 ||
                                                                           (safe_mul_func_int16_t_s_s(
                                                                               ((safe_sub_func_int16_t_s_s(
                                                                                    (safe_add_func_int8_t_s_s(
                                                                                        ((g_290
                                                                                              .f1,
                                                                                          1UL) ^
                                                                                         l_1173),
                                                                                        g_290
                                                                                            .f4)),
                                                                                    l_1168)) >
                                                                                0xBAL),
                                                                               g_76[2]
                                                                                   [0]
                                                                                   [9]
                                                                                       .f4))),
                                                                          l_1174[5]
                                                                              .f5)) &&
                                                                      l_1174[5]
                                                                          .f3)))),
                                                            g_223)))),
                                                  4))),
                                             0x5AA206D6L)) ||
                                           l_1168) &&
                                          g_290.f2) < 0UL) &&
                                        g_380[3][2])),
                                      l_1202),
                                     l_1174[5].f2),
                                    g_28.f3)))),
                            g_76[2][0][9].f1))) |
                       g_5[0].f3)),
                     g_1038)) ^
                 0x318F4680L);
            return g_28.f2;
          }
          l_1224 |=
              ((l_1223[7] =
                    ((g_290.f5 !=
                      (((((safe_add_func_uint16_t_u_u(
                              l_1192,
                              (safe_mul_func_int16_t_s_s(
                                  (!(l_1168 !=
                                     (safe_mul_func_int8_t_s_s(
                                         ((((((safe_lshift_func_int16_t_s_u(
                                                  l_1176.f4, 6)),
                                              l_1195) <
                                             ((safe_rshift_func_int8_t_s_u(
                                                  (safe_lshift_func_int8_t_s_u(
                                                      l_1176.f6,
                                                      (g_368[(l_1176.f6 + 3)] =
                                                           (safe_mod_func_int8_t_s_s(
                                                               (4L &
                                                                (l_1219 =
                                                                     (g_846[6]
                                                                           [0] <
                                                                      g_811))),
                                                               g_76[2][0][9]
                                                                   .f0))))),
                                                  3)) > g_5[0].f0)),
                                            l_10) |
                                           g_1220) >= 0x00L),
                                         g_766)))),
                                  0x0CC5L)))) == g_392) >= 0x91D4L) &&
                        l_1221) <= l_10)) > l_1222)) > 4294967287UL);
        }
      }
      g_181 =
          (l_1224 ||
           (((l_1172 ^=
              (g_76[3][2][6], (g_290.f2 = (g_380[1][2] ^ g_368[2])))) >
             ((+(g_290.f0, ((safe_sub_func_int8_t_s_s(
                                (g_470, (safe_sub_func_uint16_t_u_u(
                                            l_1253, ((l_1254 && g_584) & 1L)))),
                                l_1174[5].f1)) > 0x0E5AL))),
              0x364DL)) != 9UL));
    }
  }
  return l_1174[5].f3;
}

static int32_t func_2(const struct S0 p_3, int32_t p_4) {
  int32_t l_1125 = 0x6F982E29L;
  int32_t l_1138 = 1L;
  int8_t l_1139[3][9][1] = {
      {{(-6L)},
       {0xD8L},
       {(-6L)},
       {9L},
       {0x7DL},
       {9L},
       {(-6L)},
       {0xD8L},
       {(-6L)}},
      {{9L}, {0x7DL}, {9L}, {(-6L)}, {0xD8L}, {(-6L)}, {9L}, {0x7DL}, {9L}},
      {{(-6L)},
       {0xD8L},
       {(-6L)},
       {9L},
       {0x7DL},
       {9L},
       {(-6L)},
       {0xD8L},
       {(-6L)}}};
  int i, j, k;
  g_181 =
      (p_3.f2,
       (l_1125 ||
        (safe_lshift_func_int16_t_s_s(
            (((safe_mod_func_uint16_t_u_u(
                  (safe_add_func_int32_t_s_s(
                      0xFB7EEFF0L,
                      ((l_1125 = (p_4 > (p_4 > (g_415[0][0].f2 = p_3.f5)))) <=
                       ((safe_mul_func_uint16_t_u_u(
                            0x39BEL,
                            (((((safe_lshift_func_int16_t_s_u(
                                    (safe_sub_func_int32_t_s_s(
                                        ((p_3, g_5[0]), p_3.f6), 4294967286UL)),
                                    l_1138)) |
                                p_3.f4) <= l_1138) < g_76[2][0][9].f5) <=
                             l_1138))) <= g_28.f1)))),
                  p_3.f6)) != p_3.f6) &&
             l_1125),
            p_4))));
  l_1139[2][5][0] ^= g_5[0].f0;
  g_374 |=
      (((p_3.f4 <
         (((safe_mul_func_int8_t_s_s((1L && p_3.f3), g_76[2][0][9].f5)) |
           (((g_447 = (safe_mod_func_int32_t_s_s(
                  p_4,
                  (safe_add_func_uint32_t_u_u(
                      ((safe_add_func_int8_t_s_s(
                           (safe_lshift_func_uint16_t_u_s(
                               ((((l_1125 |
                                   (safe_lshift_func_int16_t_s_s(
                                       ((safe_mul_func_int8_t_s_s(
                                            ((safe_lshift_func_uint8_t_u_s(
                                                 (0xCDAAL ==
                                                  (l_1138,
                                                   (safe_lshift_func_int16_t_s_s(
                                                       (((-1L) | 0x6BL) !=
                                                        0x3A61L),
                                                       10)))),
                                                 g_472[0][0][4])) >= 0x0AA7L),
                                            1UL)) <= g_181),
                                       g_159))) != l_1125),
                                 g_290.f3) < g_845),
                               2)),
                           l_1138)) &
                       0L),
                      1UL))))) == 0UL) < p_3.f4)),
          p_3.f2)) ||
        g_290.f2) > g_449);
  return g_28.f3;
}

static int32_t func_6(int32_t p_7, uint32_t p_8, uint32_t p_9) {
  int16_t l_854 = 6L;
  struct S2 l_872 = {0xB5C80C62L, 0xAEL, -3L, 1UL, 0x456CL, 0x0154L, 4UL};
  int32_t l_934 = 0x319251E1L;
  struct S1 l_1033 = {0x1BL, 7L, 65530UL, 0xFFFDEF8FL, 65535UL, -2L};
  uint8_t l_1080 = 0x3EL;
  struct S0 l_1123 = {0xF12901C4L, 0xE45AL, 0xDEE5DCF8L, -1L,
                      2UL, 1UL, 65535UL};
  for (p_7 = 16; (p_7 != (-30)); --p_7) {
    uint32_t l_13[6][6][7] = {
        {{0x881DDA8DL, 0x0335900BL, 0x0335900BL, 0x881DDA8DL, 0x6B51F0EFL,
          4294967295UL, 0x881DDA8DL},
         {4294967295UL, 1UL, 0x6B51F0EFL, 0x6B51F0EFL, 1UL, 4294967295UL,
          0x0335900BL},
         {0x6B51F0EFL, 0x0335900BL, 0x407374FDL, 4294967295UL, 4294967295UL,
          0x407374FDL, 0x0335900BL},
         {0x6B51F0EFL, 0UL, 0xFC0336AEL, 0x6B51F0EFL, 4294967290UL,
          4294967290UL, 0x6B51F0EFL},
         {0xFC0336AEL, 0x0335900BL, 0xFC0336AEL, 4294967290UL, 0x0335900BL, 0UL,
          0UL},
         {0x0335900BL, 0x6B51F0EFL, 0x407374FDL, 0x6B51F0EFL, 0x0335900BL,
          0x407374FDL, 4294967295UL}},
        {{4294967295UL, 0UL, 4294967290UL, 4294967295UL, 4294967290UL, 0UL,
          4294967295UL},
         {0xFC0336AEL, 4294967295UL, 0UL, 4294967290UL, 4294967295UL,
          4294967290UL, 0UL},
         {4294967295UL, 4294967295UL, 0x407374FDL, 0x0335900BL, 0x6B51F0EFL,
          0x407374FDL, 0x6B51F0EFL},
         {0x0335900BL, 0UL, 0UL, 0x0335900BL, 4294967290UL, 0xFC0336AEL,
          0x0335900BL},
         {0xFC0336AEL, 0x6B51F0EFL, 4294967290UL, 4294967290UL, 0x6B51F0EFL,
          0xFC0336AEL, 0UL},
         {0x6B51F0EFL, 0x0335900BL, 0x407374FDL, 4294967295UL, 4294967295UL,
          0x407374FDL, 0x0335900BL}},
        {{0x6B51F0EFL, 0UL, 0xFC0336AEL, 0x6B51F0EFL, 4294967290UL,
          4294967290UL, 0x6B51F0EFL},
         {0xFC0336AEL, 0x0335900BL, 0xFC0336AEL, 4294967290UL, 0x0335900BL, 0UL,
          0UL},
         {0x0335900BL, 0x6B51F0EFL, 0x407374FDL, 0x6B51F0EFL, 0x0335900BL,
          0x407374FDL, 4294967295UL},
         {4294967295UL, 0UL, 4294967290UL, 4294967295UL, 4294967290UL, 0UL,
          4294967295UL},
         {0xFC0336AEL, 4294967295UL, 0UL, 4294967290UL, 4294967295UL,
          4294967290UL, 0UL},
         {4294967295UL, 4294967295UL, 0x407374FDL, 0x0335900BL, 0x6B51F0EFL,
          0x407374FDL, 0x6B51F0EFL}},
        {{0x0335900BL, 0UL, 0UL, 0x0335900BL, 4294967290UL, 0xFC0336AEL,
          0x0335900BL},
         {0xFC0336AEL, 0x6B51F0EFL, 4294967290UL, 4294967290UL, 0x6B51F0EFL,
          0xFC0336AEL, 0UL},
         {0x6B51F0EFL, 0x0335900BL, 0x407374FDL, 4294967295UL, 4294967295UL,
          0x407374FDL, 0x0335900BL},
         {0x6B51F0EFL, 0UL, 0xFC0336AEL, 0x6B51F0EFL, 4294967290UL,
          4294967290UL, 0x6B51F0EFL},
         {0xFC0336AEL, 0x0335900BL, 0xFC0336AEL, 4294967290UL, 0x0335900BL, 0UL,
          0UL},
         {0x0335900BL, 0x6B51F0EFL, 0x407374FDL, 0x6B51F0EFL, 0x0335900BL,
          0x407374FDL, 4294967295UL}},
        {{4294967295UL, 0UL, 4294967290UL, 4294967295UL, 4294967290UL, 0UL,
          4294967295UL},
         {0xFC0336AEL, 4294967295UL, 0UL, 4294967290UL, 4294967295UL,
          4294967290UL, 0UL},
         {4294967295UL, 4294967295UL, 0x407374FDL, 0x0335900BL, 0x6B51F0EFL,
          0x407374FDL, 0x6B51F0EFL},
         {0x0335900BL, 0UL, 0UL, 0x0335900BL, 4294967290UL, 0xFC0336AEL,
          0x0335900BL},
         {0xFC0336AEL, 0x6B51F0EFL, 4294967290UL, 4294967290UL, 0x6B51F0EFL,
          0xFC0336AEL, 0UL},
         {0x6B51F0EFL, 0x0335900BL, 4294967295UL, 0xFC0336AEL, 0xFC0336AEL,
          4294967295UL, 0UL}},
        {{4294967290UL, 0x407374FDL, 1UL, 4294967290UL, 0x881DDA8DL,
          0x881DDA8DL, 4294967290UL},
         {1UL, 0UL, 1UL, 0x881DDA8DL, 0UL, 0x407374FDL, 0x407374FDL},
         {0UL, 4294967290UL, 4294967295UL, 4294967290UL, 0UL, 4294967295UL,
          0xFC0336AEL},
         {0xFC0336AEL, 0x407374FDL, 0x881DDA8DL, 0xFC0336AEL, 0x881DDA8DL,
          0x407374FDL, 0xFC0336AEL},
         {1UL, 0xFC0336AEL, 0x407374FDL, 0x881DDA8DL, 0xFC0336AEL, 0x881DDA8DL,
          0x407374FDL},
         {0xFC0336AEL, 0xFC0336AEL, 4294967295UL, 0UL, 4294967290UL,
          4294967295UL, 4294967290UL}}};
    struct S2 l_871 = {0x31924B3EL, 3UL, 0x8534L, 0xDC3984BEL,
                       0xF496L, 0x0B1CL, 0x43F3L};
    int32_t l_890 = 1L;
    int32_t l_898 = 0x37473797L;
    uint32_t l_900 = 0x5F7B44B0L;
    int32_t l_901 = 2L;
    int32_t l_902 = 0x8CBFB14CL;
    uint16_t l_905 = 0x25B8L;
    struct S1 l_956 = {1UL, 0xC946A6A8L, 65535UL,
                       0x8BEB220AL, 0x2DA9L, 0x0DF5L};
    uint32_t l_1010 = 0x31368FF9L;
    int16_t l_1078 = 0xA87AL;
    struct S0 l_1117 = {0x0E86DEDEL, 6UL, 0x95830998L, -9L,
                        1UL, 0xDF641586L, 65535UL};
    int i, j, k;
    for (p_8 = 0; (p_8 <= 5); p_8 += 1) {
      uint32_t l_875 = 0x5056D583L;
      int8_t l_897 = 0x75L;
      int32_t l_906 = 1L;
      int32_t l_960 = 0x5DAA8A91L;
      struct S1 l_1020 = {0x2AL, 0L, 65535UL, 1UL, 65535UL, 0x01FBL};
      int32_t l_1037 = 3L;
      uint32_t l_1057[6][10] = {
          {0UL, 0x316749BEL, 0xA76468F0L, 4294967295UL, 0x316749BEL,
           0xBE27ECB6L, 0x7BEC38FEL, 0xA76468F0L, 0xA76468F0L, 0x7BEC38FEL},
          {0xBE27ECB6L, 0x7BEC38FEL, 0xA76468F0L, 0xA76468F0L, 0x7BEC38FEL,
           0xBE27ECB6L, 0x316749BEL, 4294967295UL, 0xA76468F0L, 0x316749BEL},
          {0UL, 0x7BEC38FEL, 0UL, 4294967295UL, 0x7BEC38FEL, 4294967291UL,
           0x7BEC38FEL, 4294967295UL, 0UL, 0x7BEC38FEL},
          {0UL, 0x316749BEL, 0xA76468F0L, 4294967295UL, 0x316749BEL,
           0xBE27ECB6L, 0x7BEC38FEL, 0xA76468F0L, 0xA76468F0L, 0x7BEC38FEL},
          {0xBE27ECB6L, 0x7BEC38FEL, 0xA76468F0L, 0xA76468F0L, 0x7BEC38FEL,
           0xBE27ECB6L, 0x316749BEL, 4294967295UL, 0xA76468F0L, 0x316749BEL},
          {0UL, 0x7BEC38FEL, 0UL, 4294967295UL, 0x7BEC38FEL, 4294967291UL,
           0x7BEC38FEL, 4294967295UL, 0UL, 0x7BEC38FEL}};
      uint8_t l_1067[9][6] = {{0x8CL, 0UL, 0x8CL, 0x6DL, 0x8CL, 0UL},
                              {7UL, 0UL, 255UL, 0UL, 7UL, 0UL},
                              {0x8CL, 0x6DL, 0x8CL, 0UL, 0x8CL, 0x6DL},
                              {7UL, 0x6DL, 255UL, 0x6DL, 7UL, 0x6DL},
                              {0x8CL, 0UL, 0x8CL, 0x6DL, 0x8CL, 0UL},
                              {7UL, 0UL, 255UL, 0UL, 7UL, 0UL},
                              {0x8CL, 0x6DL, 0x8CL, 0UL, 0x8CL, 0x6DL},
                              {7UL, 0x6DL, 255UL, 0x6DL, 7UL, 0x6DL},
                              {0x8CL, 0UL, 0x8CL, 0x6DL, 0x8CL, 0UL}};
      int32_t l_1115 = (-2L);
      int32_t l_1124 = 0L;
      int i, j;
      g_16 = (safe_lshift_func_int16_t_s_u((0x4FL > p_8), 7));
      --g_17[5];
      for (p_9 = 1; (p_9 <= 5); p_9 += 1) {
        int i, j, k;
        l_854 = (l_13[p_9][p_9][(p_9 + 1)] != func_20(l_13[0][5][6]));
      }
      if (((safe_mul_func_uint16_t_u_u(
               (safe_add_func_int8_t_s_s(
                   p_7,
                   ((p_7 <= (safe_lshift_func_int8_t_s_s(0xC8L, 2))),
                    (safe_rshift_func_uint8_t_u_u(
                        (g_415[0][0].f0 =
                             ((safe_mod_func_int16_t_s_s(
                                  ((((safe_rshift_func_int16_t_s_u(
                                         (((+0x926C23A0L), 0L) &&
                                          (safe_sub_func_int32_t_s_s(
                                              p_7,
                                              (safe_mul_func_int8_t_s_s(
                                                  ((g_374 = 0x3D575655L),
                                                   (g_159 =
                                                        ((l_872 = l_871),
                                                         (safe_mod_func_int8_t_s_s(
                                                             (0x5A39L != p_9),
                                                             0x67L))))),
                                                  7UL))))),
                                         4)) &
                                     p_9) &&
                                    l_875) &&
                                   p_7),
                                  1L)) ||
                              0x2AEDL)),
                        5))))),
               4UL)) &&
           0x9AC0L)) {
        int32_t l_899 = (-8L);
        struct S1 l_931 = {0x75L, -8L, 65530UL, 1UL, 0x47C7L, 0xFC30L};
        int32_t l_977[3];
        int32_t l_1049 = 0xD7515BA7L;
        int i;
        for (i = 0; i < 3; i++) l_977[i] = 0xD3B19F35L;
        l_902 =
            ((!((safe_sub_func_int8_t_s_s(
                    p_9,
                    ((safe_mod_func_int16_t_s_s(
                         ((l_901 ^=
                           (((safe_mul_func_uint8_t_u_u(
                                 (l_900 =
                                      (((safe_mod_func_uint8_t_u_u(
                                            (safe_rshift_func_uint8_t_u_s(
                                                (safe_sub_func_uint8_t_u_u(
                                                    (safe_mul_func_int8_t_s_s(
                                                        g_766,
                                                        (l_890 &=
                                                         (g_290.f1 = p_8)))),
                                                    (-1L))),
                                                0)),
                                            p_9)) ==
                                        (safe_add_func_uint16_t_u_u(
                                            ((safe_add_func_uint16_t_u_u(
                                                 65529UL,
                                                 (((safe_lshift_func_int16_t_s_u(
                                                       ((l_854,
                                                         (((l_899 =
                                                                ((l_898 =
                                                                      l_897) !=
                                                                 p_7)) |
                                                           g_159) <= p_8)) &
                                                        7UL),
                                                       0)) != 0x2D06L) <
                                                  g_368[2]))) < 4L),
                                            g_368[2]))) > 0xC1L)),
                                 g_374)) != 0x4E8E6CE3L) <= g_28.f5)) &
                          0x43F6L),
                         g_447)),
                     8L))) |
                p_8)) <= g_5[0].f1);
        if (l_872.f5) {
          for (l_899 = 26; (l_899 == (-15));
               l_899 = safe_sub_func_int8_t_s_s(l_899, 9)) {
            g_181 ^= g_76[2][0][9].f3;
            return l_905;
          }
          l_906 = p_9;
          return p_9;
        } else {
          uint16_t l_907[10][10] = {
              {65529UL, 0x0C9AL, 0x3B3CL, 0x78CDL, 0x4612L, 0x78CDL, 0x3B3CL,
               0x0C9AL, 65529UL, 0x4319L},
              {65527UL, 3UL, 0x3B3CL, 0x4612L, 0x0C9AL, 0x0C9AL, 0x4612L,
               0x3B3CL, 3UL, 65527UL},
              {3UL, 0x78CDL, 65529UL, 0x4612L, 8UL, 65527UL, 8UL, 0x4612L,
               65529UL, 0x78CDL},
              {0x78CDL, 0x5AD8L, 65529UL, 3UL, 0x78D0L, 0x3B3CL, 0x3B3CL,
               0x78D0L, 3UL, 65529UL},
              {0x78D0L, 0x78D0L, 8UL, 0x78CDL, 65527UL, 0x3B3CL, 0x4319L,
               0x3B3CL, 65527UL, 0x78CDL},
              {0x78CDL, 0x4612L, 0x78CDL, 0x3B3CL, 0x0C9AL, 65529UL, 0x4319L,
               0x4319L, 65529UL, 0x0C9AL},
              {8UL, 0x78D0L, 0x78D0L, 8UL, 0x78CDL, 65527UL, 0x3B3CL, 0x4319L,
               0x3B3CL, 65527UL},
              {65529UL, 0x5AD8L, 0x78CDL, 0x5AD8L, 65529UL, 3UL, 0x78D0L,
               0x3B3CL, 0x3B3CL, 0x78D0L},
              {0x4319L, 3UL, 8UL, 8UL, 3UL, 0x4319L, 0x0C9AL, 0x78D0L, 65529UL,
               0x78D0L},
              {0x5AD8L, 8UL, 65529UL, 0x3B3CL, 65529UL, 8UL, 0x5AD8L, 0x0C9AL,
               65527UL, 65527UL}};
          int32_t l_912 = 0x0B1380F3L;
          struct S2 l_1018 = {4L, 0x17L, -4L, 0x0DD7EFB5L, -2L, 7L, 65529UL};
          int32_t l_1035 = 0x35DF92F1L;
          int32_t l_1036 = 0x5D395614L;
          int i, j;

          for (i = 0; i < 3; i++) l_977[i] = 0xD3B19F35L;
        }
        l_902 = l_1033.f1;
      } else {
        uint16_t l_1066 = 0xFAA9L;
        int32_t l_1118 = 6L;
        for (g_290.f6 = 0; (g_290.f6 <= 2);
             g_290.f6 = safe_add_func_int16_t_s_s(g_290.f6, 9)) {
          int32_t l_1072 = (-1L);
          const int32_t l_1077 = 0x88405E55L;
          int32_t l_1116 = (-1L);
        }
        for (p_8 = 0; (p_8 <= 5); p_8 += 1) {
          uint32_t l_875 = 0x5056D583L;
          int8_t l_897 = 0x75L;
          int32_t l_906 = 1L;
          int32_t l_960 = 0x5DAA8A91L;
          struct S1 l_1020 = {0x2AL, 0L, 65535UL, 1UL, 65535UL, 0x01FBL};
          int32_t l_1037 = 3L;
          uint32_t l_1057[6][10] = {
              {0UL, 0x316749BEL, 0xA76468F0L, 4294967295UL, 0x316749BEL,
               0xBE27ECB6L, 0x7BEC38FEL, 0xA76468F0L, 0xA76468F0L, 0x7BEC38FEL},
              {0xBE27ECB6L, 0x7BEC38FEL, 0xA76468F0L, 0xA76468F0L, 0x7BEC38FEL,
               0xBE27ECB6L, 0x316749BEL, 4294967295UL, 0xA76468F0L,
               0x316749BEL},
              {0UL, 0x7BEC38FEL, 0UL, 4294967295UL, 0x7BEC38FEL, 4294967291UL,
               0x7BEC38FEL, 4294967295UL, 0UL, 0x7BEC38FEL},
              {0UL, 0x316749BEL, 0xA76468F0L, 4294967295UL, 0x316749BEL,
               0xBE27ECB6L, 0x7BEC38FEL, 0xA76468F0L, 0xA76468F0L, 0x7BEC38FEL},
              {0xBE27ECB6L, 0x7BEC38FEL, 0xA76468F0L, 0xA76468F0L, 0x7BEC38FEL,
               0xBE27ECB6L, 0x316749BEL, 4294967295UL, 0xA76468F0L,
               0x316749BEL},
              {0UL, 0x7BEC38FEL, 0UL, 4294967295UL, 0x7BEC38FEL, 4294967291UL,
               0x7BEC38FEL, 4294967295UL, 0UL, 0x7BEC38FEL}};
          uint8_t l_1067[9][6] = {{0x8CL, 0UL, 0x8CL, 0x6DL, 0x8CL, 0UL},
                                  {7UL, 0UL, 255UL, 0UL, 7UL, 0UL},
                                  {0x8CL, 0x6DL, 0x8CL, 0UL, 0x8CL, 0x6DL},
                                  {7UL, 0x6DL, 255UL, 0x6DL, 7UL, 0x6DL},
                                  {0x8CL, 0UL, 0x8CL, 0x6DL, 0x8CL, 0UL},
                                  {7UL, 0UL, 255UL, 0UL, 7UL, 0UL},
                                  {0x8CL, 0x6DL, 0x8CL, 0UL, 0x8CL, 0x6DL},
                                  {7UL, 0x6DL, 255UL, 0x6DL, 7UL, 0x6DL},
                                  {0x8CL, 0UL, 0x8CL, 0x6DL, 0x8CL, 0UL}};
          int32_t l_1115 = (-2L);
          int32_t l_1124 = 0L;
          int i, j;
          g_16 = (safe_lshift_func_int16_t_s_u((0x4FL > p_8), 7));
          --g_17[5];
          for (p_9 = 1; (p_9 <= 5); p_9 += 1) {
            int i, j, k;
            l_854 = (l_13[p_9][p_9][(p_9 + 1)] != func_20(l_13[0][5][6]));
          }
          if (((safe_mul_func_uint16_t_u_u(
                   (safe_add_func_int8_t_s_s(
                       p_7,
                       ((p_7 <= (safe_lshift_func_int8_t_s_s(0xC8L, 2))),
                        (safe_rshift_func_uint8_t_u_u(
                            (g_415[0][0].f0 =
                                 ((safe_mod_func_int16_t_s_s(
                                      ((((safe_rshift_func_int16_t_s_u(
                                             (((+0x926C23A0L), 0L) &&
                                              (safe_sub_func_int32_t_s_s(
                                                  p_7,
                                                  (safe_mul_func_int8_t_s_s(
                                                      ((g_374 = 0x3D575655L),
                                                       (g_159 =
                                                            ((l_872 = l_871),
                                                             (safe_mod_func_int8_t_s_s(
                                                                 (0x5A39L !=
                                                                  p_9),
                                                                 0x67L))))),
                                                      7UL))))),
                                             4)) &
                                         p_9) &&
                                        l_875) &&
                                       p_7),
                                      1L)) ||
                                  0x2AEDL)),
                            5))))),
                   4UL)) &&
               0x9AC0L)) {
            int32_t l_899 = (-8L);
            struct S1 l_931 = {0x75L, -8L, 65530UL, 1UL, 0x47C7L, 0xFC30L};
            int32_t l_977[3];
            int32_t l_1049 = 0xD7515BA7L;
            int i;
            for (i = 0; i < 3; i++) l_977[i] = 0xD3B19F35L;
            l_902 =
                ((!((safe_sub_func_int8_t_s_s(
                        p_9,
                        ((safe_mod_func_int16_t_s_s(
                             ((l_901 ^=
                               (((safe_mul_func_uint8_t_u_u(
                                     (l_900 =
                                          (((safe_mod_func_uint8_t_u_u(
                                                (safe_rshift_func_uint8_t_u_s(
                                                    (safe_sub_func_uint8_t_u_u(
                                                        (safe_mul_func_int8_t_s_s(
                                                            g_766,
                                                            (l_890 &=
                                                             (g_290.f1 =
                                                                  p_8)))),
                                                        (-1L))),
                                                    0)),
                                                p_9)) ==
                                            (safe_add_func_uint16_t_u_u(
                                                ((safe_add_func_uint16_t_u_u(
                                                     65529UL,
                                                     (((safe_lshift_func_int16_t_s_u(
                                                           ((l_854,
                                                             (((l_899 =
                                                                    ((l_898 =
                                                                          l_897) !=
                                                                     p_7)) |
                                                               g_159) <= p_8)) &
                                                            7UL),
                                                           0)) != 0x2D06L) <
                                                      g_368[2]))) < 4L),
                                                g_368[2]))) > 0xC1L)),
                                     g_374)) != 0x4E8E6CE3L) <= g_28.f5)) &
                              0x43F6L),
                             g_447)),
                         8L))) |
                    p_8)) <= g_5[0].f1);
            if (l_872.f5) {
              for (l_899 = 26; (l_899 == (-15));
                   l_899 = safe_sub_func_int8_t_s_s(l_899, 9)) {
                g_181 ^= g_76[2][0][9].f3;
                return l_905;
              }
              l_906 = p_9;
              return p_9;
            } else {
              uint16_t l_907[10][10] = {
                  {65529UL, 0x0C9AL, 0x3B3CL, 0x78CDL, 0x4612L, 0x78CDL,
                   0x3B3CL, 0x0C9AL, 65529UL, 0x4319L},
                  {65527UL, 3UL, 0x3B3CL, 0x4612L, 0x0C9AL, 0x0C9AL, 0x4612L,
                   0x3B3CL, 3UL, 65527UL},
                  {3UL, 0x78CDL, 65529UL, 0x4612L, 8UL, 65527UL, 8UL, 0x4612L,
                   65529UL, 0x78CDL},
                  {0x78CDL, 0x5AD8L, 65529UL, 3UL, 0x78D0L, 0x3B3CL, 0x3B3CL,
                   0x78D0L, 3UL, 65529UL},
                  {0x78D0L, 0x78D0L, 8UL, 0x78CDL, 65527UL, 0x3B3CL, 0x4319L,
                   0x3B3CL, 65527UL, 0x78CDL},
                  {0x78CDL, 0x4612L, 0x78CDL, 0x3B3CL, 0x0C9AL, 65529UL,
                   0x4319L, 0x4319L, 65529UL, 0x0C9AL},
                  {8UL, 0x78D0L, 0x78D0L, 8UL, 0x78CDL, 65527UL, 0x3B3CL,
                   0x4319L, 0x3B3CL, 65527UL},
                  {65529UL, 0x5AD8L, 0x78CDL, 0x5AD8L, 65529UL, 3UL, 0x78D0L,
                   0x3B3CL, 0x3B3CL, 0x78D0L},
                  {0x4319L, 3UL, 8UL, 8UL, 3UL, 0x4319L, 0x0C9AL, 0x78D0L,
                   65529UL, 0x78D0L},
                  {0x5AD8L, 8UL, 65529UL, 0x3B3CL, 65529UL, 8UL, 0x5AD8L,
                   0x0C9AL, 65527UL, 65527UL}};
              int32_t l_912 = 0x0B1380F3L;
              struct S2 l_1018 = {4L, 0x17L, -4L, 0x0DD7EFB5L,
                                  -2L, 7L, 65529UL};
              int32_t l_1035 = 0x35DF92F1L;
              int32_t l_1036 = 0x5D395614L;
              int i, j;
              for (g_160 = 5; (g_160 >= 0); g_160 -= 1) {
                uint32_t l_920 = 0xF1A80AB2L;
                int i;
                l_907[7][3] &= g_17[(p_8 + 2)];
                l_906 |= (~(
                    g_17[(g_160 + 2)] <=
                    (((safe_lshift_func_uint16_t_u_s(
                          ((l_912 =
                                ((((65535UL ^
                                    ((safe_rshift_func_int8_t_s_u(
                                         (g_290.f3 <=
                                          ((p_9, (l_899 & (p_9, l_899))) ^ 1L)),
                                         4)) < (0x7EDD389EL <= 1UL))) <=
                                   65535UL) != 65534UL) |
                                 g_17[1])) <= 0xB889D762L),
                          g_845)) &&
                      g_5[0].f4) &&
                     0x83L)));
                l_906 =
                    ((p_8 >
                      (safe_lshift_func_int8_t_s_s(
                          (((1UL & g_368[0]) != g_28.f4) &&
                           (g_159 <
                            (((safe_mod_func_int8_t_s_s(
                                  (safe_mul_func_uint8_t_u_u(
                                      (((safe_unary_minus_func_int32_t_s((
                                            (l_920 ||
                                             (l_912 =
                                                  (((l_906 !=
                                                     (safe_lshift_func_int16_t_s_s(
                                                         ((safe_mod_func_uint16_t_u_u(
                                                              ((safe_mul_func_uint16_t_u_u(
                                                                   (((((p_9 <
                                                                        l_899) >=
                                                                       0xF307L),
                                                                      g_16) <
                                                                     0x94L) <=
                                                                    (-1L)),
                                                                   0x41BCL)),
                                                               p_7),
                                                              g_5[0].f2)) >=
                                                          p_8),
                                                         11))) > l_899),
                                                   g_368[2]))) < l_872.f3))),
                                        l_897) <= 1L),
                                      l_899)),
                                  l_872.f4)) != 0x3B548DBEL) ^
                             0xAD422F43L))),
                          4))) >= 0L);
              }
              if ((l_912 |= (+(~(safe_mod_func_int32_t_s_s(
                       (((safe_rshift_func_uint16_t_u_s((0x2C16897EL == p_8),
                                                        l_899)),
                         l_931),
                        0x8EB49E4BL),
                       (((l_872.f6, g_76[2][0][9]), 0UL) ||
                        (((l_934 = ((safe_rshift_func_uint8_t_u_u(
                                        ((l_931.f5 <= l_890), g_374), 2)) >
                                    g_28.f2)) &&
                          l_890) &&
                         8UL)))))))) {
                uint16_t l_959 = 0x60ABL;
                g_467 = (safe_mul_func_uint8_t_u_u(
                    ((l_934 >=
                      (g_380[2][0] ||
                       (l_872,
                        (safe_sub_func_int16_t_s_s(
                            (safe_add_func_int16_t_s_s(
                                ((safe_mul_func_uint8_t_u_u(
                                     ((safe_sub_func_uint8_t_u_u(l_872.f3,
                                                                 0xFAL)) < 0L),
                                     (safe_mod_func_int32_t_s_s(
                                         (safe_add_func_int8_t_s_s(
                                             (((((safe_unary_minus_func_int16_t_s(
                                                     (safe_mul_func_uint16_t_u_u(
                                                         ((safe_mod_func_int16_t_s_s(
                                                              (safe_sub_func_uint32_t_u_u(
                                                                  (((l_956,
                                                                     (((safe_sub_func_int8_t_s_s(
                                                                           g_447,
                                                                           0UL)) <
                                                                       l_912) ||
                                                                      0UL)) |
                                                                    0x3BFEL),
                                                                   4294967292UL),
                                                                  1UL)),
                                                              5UL)) >= p_8),
                                                         p_8)))) != 2L) !=
                                                g_5[0].f6) >= l_897),
                                              p_8),
                                             p_7)),
                                         g_449)))) < (-5L)),
                                g_846[4][7])),
                            g_76[2][0][9].f5))))) > l_959),
                    0x8EL));
                l_960 |= 0x55DA0688L;
                g_447 ^= (safe_mod_func_int32_t_s_s(
                    ((safe_sub_func_uint8_t_u_u(
                         ((p_7 >= p_9) || (g_5[0], l_931.f2)),
                         (g_76[2][0][9].f2 >=
                          ((safe_lshift_func_int16_t_s_s(
                               (((safe_mod_func_int16_t_s_s(
                                     ((g_162 = (l_906 ^= 0x68738A91L)) >
                                      (l_907[4][3],
                                       (((((safe_sub_func_int16_t_s_s(
                                               g_472[1][1][3],
                                               ((safe_lshift_func_int8_t_s_s(
                                                    ((g_468 = 0xA5L) <= g_470),
                                                    l_871.f2)) ^
                                                0x5C84DE80L))) &&
                                           1UL) <= 0L),
                                         255UL) ^
                                        l_875))),
                                     p_7)) >= p_7),
                                g_16),
                               14)) < 0UL)))) &&
                     g_374),
                    0x773F7505L));
              } else {
                return l_907[7][3];
              }
              if (((((0xFF3FL &
                      ((l_934 = ((0x6E918A2AL ^
                                  (g_17[5] |=
                                   (l_977[2] ^=
                                    ((safe_sub_func_uint16_t_u_u(
                                         (p_7 >=
                                          ((g_159 &&
                                            ((g_5[0],
                                              (((l_931, l_906) &&
                                                ((safe_mul_func_uint8_t_u_u(
                                                     l_956.f3, (p_9 < 0x22L))) >
                                                 g_28.f1)) != p_8)) |
                                             65535UL)) ||
                                           p_8)),
                                         l_931.f1)) &&
                                     l_875)))) == l_899)) != 1L)),
                     g_17[4]) |
                    p_8),
                   p_7)) {
                struct S0 l_990[6][5][5] = {
                    {{{-4L, 65535UL, 0UL, 2L, 4294967295UL, 4294967287UL, 2UL},
                      {0x72FEF34CL, 3UL, 0x49A21933L, 0L, 0x3330DF52L,
                       4294967295UL, 6UL},
                      {0xCCE96CF9L, 0x7056L, 0UL, 0x3F89658EL, 1UL, 3UL, 0UL},
                      {0x73221832L, 0xB58DL, 3UL, 0L, 1UL, 0x4DC72634L,
                       65535UL},
                      {0x73221832L, 0xB58DL, 3UL, 0L, 1UL, 0x4DC72634L,
                       65535UL}},
                     {{0x0ACF52EDL, 65527UL, 0UL, 1L, 1UL, 0UL, 0x006EL},
                      {0xDAC36A7DL, 0x60F5L, 0x7A6EF175L, 0xD074A6F4L,
                       4294967291UL, 4294967290UL, 0xF171L},
                      {0x0ACF52EDL, 65527UL, 0UL, 1L, 1UL, 0UL, 0x006EL},
                      {0x73221832L, 0xB58DL, 3UL, 0L, 1UL, 0x4DC72634L,
                       65535UL},
                      {1L, 0xC834L, 1UL, -4L, 0xD203C118L, 1UL, 65535UL}},
                     {{4L, 65535UL, 0x1FAD5B1AL, 0x09CE8164L, 0xB37CCBE2L,
                       0xEA670C28L, 65535UL},
                      {0xA820905CL, 65530UL, 0x2497B0EEL, 0xBDB215D4L,
                       0x8ECA5571L, 0x86B3E2E0L, 0xA4A4L},
                      {-10L, 1UL, 9UL, 0x0B28D5FCL, 0x46DE1B6EL, 0x2B325E89L,
                       65531UL},
                      {0xCCE96CF9L, 0x7056L, 0UL, 0x3F89658EL, 1UL, 3UL, 0UL},
                      {-4L, 65535UL, 0UL, 2L, 4294967295UL, 4294967287UL, 2UL}},
                     {{0xDAC36A7DL, 0x60F5L, 0x7A6EF175L, 0xD074A6F4L,
                       4294967291UL, 4294967290UL, 0xF171L},
                      {1L, 0xC834L, 1UL, -4L, 0xD203C118L, 1UL, 65535UL},
                      {0xBE4029E3L, 0xC32CL, 0UL, 0L, 4294967295UL, 0xDAB356C9L,
                       4UL},
                      {0x72FEF34CL, 3UL, 0x49A21933L, 0L, 0x3330DF52L,
                       4294967295UL, 6UL},
                      {0L, 0xD97AL, 1UL, 1L, 4294967295UL, 4294967295UL,
                       65535UL}},
                     {{0x4F9B6631L, 0UL, 6UL, 1L, 4294967295UL, 4UL, 0UL},
                      {-1L, 65529UL, 0xC9DDAC57L, 0x471B025DL, 0x5BDEEFA2L,
                       0xA741CB4EL, 8UL},
                      {-10L, 1UL, 9UL, 0x0B28D5FCL, 0x46DE1B6EL, 0x2B325E89L,
                       65531UL},
                      {-4L, 65535UL, 0UL, 2L, 4294967295UL, 4294967287UL, 2UL},
                      {0xC3AC4E32L, 0x82CCL, 1UL, 0x7F2D53F5L, 4294967295UL,
                       1UL, 7UL}}},
                    {{{1L, 1UL, 1UL, 0x8043446BL, 0x514C231DL, 0x51262750L,
                       0x4D28L},
                      {0x6001C466L, 65531UL, 0xF8F92EDFL, 0xC71DB368L,
                       4294967295UL, 4294967295UL, 0x9C50L},
                      {0x0ACF52EDL, 65527UL, 0UL, 1L, 1UL, 0UL, 0x006EL},
                      {0x0ACF52EDL, 65527UL, 0UL, 1L, 1UL, 0UL, 0x006EL},
                      {0x6001C466L, 65531UL, 0xF8F92EDFL, 0xC71DB368L,
                       4294967295UL, 4294967295UL, 0x9C50L}},
                     {{0L, 0xD97AL, 1UL, 1L, 4294967295UL, 4294967295UL,
                       65535UL},
                      {0x6001C466L, 65531UL, 0xF8F92EDFL, 0xC71DB368L,
                       4294967295UL, 4294967295UL, 0x9C50L},
                      {0xCCE96CF9L, 0x7056L, 0UL, 0x3F89658EL, 1UL, 3UL, 0UL},
                      {4L, 65535UL, 0x1FAD5B1AL, 0x09CE8164L, 0xB37CCBE2L,
                       0xEA670C28L, 65535UL},
                      {-1L, 1UL, 1UL, 0L, 0UL, 4294967289UL, 0x2D29L}},
                     {{-5L, 65535UL, 0x77780E33L, 0xAAE4A112L, 4294967286UL,
                       0xC5BE975AL, 0x84D0L},
                      {-1L, 65529UL, 0xC9DDAC57L, 0x471B025DL, 0x5BDEEFA2L,
                       0xA741CB4EL, 8UL},
                      {0xC3AC4E32L, 0x82CCL, 1UL, 0x7F2D53F5L, 4294967295UL,
                       1UL, 7UL},
                      {0xDAC36A7DL, 0x60F5L, 0x7A6EF175L, 0xD074A6F4L,
                       4294967291UL, 4294967290UL, 0xF171L},
                      {0xF1826ED3L, 3UL, 8UL, 1L, 0x68534FFBL, 4294967295UL,
                       0xB2B8L}},
                     {{-10L, 1UL, 9UL, 0x0B28D5FCL, 0x46DE1B6EL, 0x2B325E89L,
                       65531UL},
                      {1L, 0xC834L, 1UL, -4L, 0xD203C118L, 1UL, 65535UL},
                      {-5L, 65535UL, 0x77780E33L, 0xAAE4A112L, 4294967286UL,
                       0xC5BE975AL, 0x84D0L},
                      {0x4F9B6631L, 0UL, 6UL, 1L, 4294967295UL, 4UL, 0UL},
                      {0x64D5F042L, 65528UL, 0xB3E11D9FL, 0L, 0UL, 0xE1715A2FL,
                       65529UL}},
                     {{-5L, 65535UL, 0x77780E33L, 0xAAE4A112L, 4294967286UL,
                       0xC5BE975AL, 0x84D0L},
                      {0xA820905CL, 65530UL, 0x2497B0EEL, 0xBDB215D4L,
                       0x8ECA5571L, 0x86B3E2E0L, 0xA4A4L},
                      {0x72FEF34CL, 3UL, 0x49A21933L, 0L, 0x3330DF52L,
                       4294967295UL, 6UL},
                      {1L, 1UL, 1UL, 0x8043446BL, 0x514C231DL, 0x51262750L,
                       0x4D28L},
                      {0xCCE96CF9L, 0x7056L, 0UL, 0x3F89658EL, 1UL, 3UL, 0UL}}},
                    {{{0L, 0xD97AL, 1UL, 1L, 4294967295UL, 4294967295UL,
                       65535UL},
                      {0xDAC36A7DL, 0x60F5L, 0x7A6EF175L, 0xD074A6F4L,
                       4294967291UL, 4294967290UL, 0xF171L},
                      {0xDAC36A7DL, 0x60F5L, 0x7A6EF175L, 0xD074A6F4L,
                       4294967291UL, 4294967290UL, 0xF171L},
                      {0L, 0xD97AL, 1UL, 1L, 4294967295UL, 4294967295UL,
                       65535UL},
                      {0xCCE96CF9L, 0x7056L, 0UL, 0x3F89658EL, 1UL, 3UL, 0UL}},
                     {{1L, 1UL, 1UL, 0x8043446BL, 0x514C231DL, 0x51262750L,
                       0x4D28L},
                      {0x72FEF34CL, 3UL, 0x49A21933L, 0L, 0x3330DF52L,
                       4294967295UL, 6UL},
                      {0xA820905CL, 65530UL, 0x2497B0EEL, 0xBDB215D4L,
                       0x8ECA5571L, 0x86B3E2E0L, 0xA4A4L},
                      {-5L, 65535UL, 0x77780E33L, 0xAAE4A112L, 4294967286UL,
                       0xC5BE975AL, 0x84D0L},
                      {0x64D5F042L, 65528UL, 0xB3E11D9FL, 0L, 0UL, 0xE1715A2FL,
                       65529UL}},
                     {{0x4F9B6631L, 0UL, 6UL, 1L, 4294967295UL, 4UL, 0UL},
                      {-5L, 65535UL, 0x77780E33L, 0xAAE4A112L, 4294967286UL,
                       0xC5BE975AL, 0x84D0L},
                      {1L, 0xC834L, 1UL, -4L, 0xD203C118L, 1UL, 65535UL},
                      {-10L, 1UL, 9UL, 0x0B28D5FCL, 0x46DE1B6EL, 0x2B325E89L,
                       65531UL},
                      {0xF1826ED3L, 3UL, 8UL, 1L, 0x68534FFBL, 4294967295UL,
                       0xB2B8L}},
                     {{0xDAC36A7DL, 0x60F5L, 0x7A6EF175L, 0xD074A6F4L,
                       4294967291UL, 4294967290UL, 0xF171L},
                      {0xC3AC4E32L, 0x82CCL, 1UL, 0x7F2D53F5L, 4294967295UL,
                       1UL, 7UL},
                      {-1L, 65529UL, 0xC9DDAC57L, 0x471B025DL, 0x5BDEEFA2L,
                       0xA741CB4EL, 8UL},
                      {-5L, 65535UL, 0x77780E33L, 0xAAE4A112L, 4294967286UL,
                       0xC5BE975AL, 0x84D0L},
                      {-1L, 1UL, 1UL, 0L, 0UL, 4294967289UL, 0x2D29L}},
                     {{4L, 65535UL, 0x1FAD5B1AL, 0x09CE8164L, 0xB37CCBE2L,
                       0xEA670C28L, 65535UL},
                      {0xCCE96CF9L, 0x7056L, 0UL, 0x3F89658EL, 1UL, 3UL, 0UL},
                      {0x6001C466L, 65531UL, 0xF8F92EDFL, 0xC71DB368L,
                       4294967295UL, 4294967295UL, 0x9C50L},
                      {0L, 0xD97AL, 1UL, 1L, 4294967295UL, 4294967295UL,
                       65535UL},
                      {0x6001C466L, 65531UL, 0xF8F92EDFL, 0xC71DB368L,
                       4294967295UL, 4294967295UL, 0x9C50L}}},
                    {{{0x0ACF52EDL, 65527UL, 0UL, 1L, 1UL, 0UL, 0x006EL},
                      {0x0ACF52EDL, 65527UL, 0UL, 1L, 1UL, 0UL, 0x006EL},
                      {0x6001C466L, 65531UL, 0xF8F92EDFL, 0xC71DB368L,
                       4294967295UL, 4294967295UL, 0x9C50L},
                      {1L, 1UL, 1UL, 0x8043446BL, 0x514C231DL, 0x51262750L,
                       0x4D28L},
                      {0xC3AC4E32L, 0x82CCL, 1UL, 0x7F2D53F5L, 4294967295UL,
                       1UL, 7UL}},
                     {{-4L, 65535UL, 0UL, 2L, 4294967295UL, 4294967287UL, 2UL},
                      {-10L, 1UL, 9UL, 0x0B28D5FCL, 0x46DE1B6EL, 0x2B325E89L,
                       65531UL},
                      {-1L, 65529UL, 0xC9DDAC57L, 0x471B025DL, 0x5BDEEFA2L,
                       0xA741CB4EL, 8UL},
                      {0x4F9B6631L, 0UL, 6UL, 1L, 4294967295UL, 4UL, 0UL},
                      {0L, 0xD97AL, 1UL, 1L, 4294967295UL, 4294967295UL,
                       65535UL}},
                     {{0x72FEF34CL, 3UL, 0x49A21933L, 0L, 0x3330DF52L,
                       4294967295UL, 6UL},
                      {0xBE4029E3L, 0xC32CL, 0UL, 0L, 4294967295UL, 0xDAB356C9L,
                       4UL},
                      {1L, 0xC834L, 1UL, -4L, 0xD203C118L, 1UL, 65535UL},
                      {0xDAC36A7DL, 0x60F5L, 0x7A6EF175L, 0xD074A6F4L,
                       4294967291UL, 4294967290UL, 0xF171L},
                      {-4L, 65535UL, 0UL, 2L, 4294967295UL, 4294967287UL, 2UL}},
                     {{0xCCE96CF9L, 0x7056L, 0UL, 0x3F89658EL, 1UL, 3UL, 0UL},
                      {-10L, 1UL, 9UL, 0x0B28D5FCL, 0x46DE1B6EL, 0x2B325E89L,
                       65531UL},
                      {0xA820905CL, 65530UL, 0x2497B0EEL, 0xBDB215D4L,
                       0x8ECA5571L, 0x86B3E2E0L, 0xA4A4L},
                      {4L, 65535UL, 0x1FAD5B1AL, 0x09CE8164L, 0xB37CCBE2L,
                       0xEA670C28L, 65535UL},
                      {1L, 0xC834L, 1UL, -4L, 0xD203C118L, 1UL, 65535UL}},
                     {{0x73221832L, 0xB58DL, 3UL, 0L, 1UL, 0x4DC72634L,
                       65535UL},
                      {0x0ACF52EDL, 65527UL, 0UL, 1L, 1UL, 0UL, 0x006EL},
                      {0xDAC36A7DL, 0x60F5L, 0x7A6EF175L, 0xD074A6F4L,
                       4294967291UL, 4294967290UL, 0xF171L},
                      {0x0ACF52EDL, 65527UL, 0UL, 1L, 1UL, 0UL, 0x006EL},
                      {0x73221832L, 0xB58DL, 3UL, 0L, 1UL, 0x4DC72634L,
                       65535UL}}},
                    {{{0x73221832L, 0xB58DL, 3UL, 0L, 1UL, 0x4DC72634L,
                       65535UL},
                      {0xCCE96CF9L, 0x7056L, 0UL, 0x3F89658EL, 1UL, 3UL, 0UL},
                      {0x72FEF34CL, 3UL, 0x49A21933L, 0L, 0x3330DF52L,
                       4294967295UL, 6UL},
                      {-4L, 65535UL, 0UL, 2L, 4294967295UL, 4294967287UL, 2UL},
                      {0x0ACF52EDL, 65527UL, 0UL, 1L, 1UL, 0UL, 0x006EL}},
                     {{0xCCE96CF9L, 0x7056L, 0UL, 0x3F89658EL, 1UL, 3UL, 0UL},
                      {0xC3AC4E32L, 0x82CCL, 1UL, 0x7F2D53F5L, 4294967295UL,
                       1UL, 7UL},
                      {-5L, 65535UL, 0x77780E33L, 0xAAE4A112L, 4294967286UL,
                       0xC5BE975AL, 0x84D0L},
                      {0x72FEF34CL, 3UL, 0x49A21933L, 0L, 0x3330DF52L,
                       4294967295UL, 6UL},
                      {0xDAC36A7DL, 0x60F5L, 0x7A6EF175L, 0xD074A6F4L,
                       4294967291UL, 4294967290UL, 0xF171L}},
                     {{0x72FEF34CL, 3UL, 0x49A21933L, 0L, 0x3330DF52L,
                       4294967295UL, 6UL},
                      {-5L, 65535UL, 0x77780E33L, 0xAAE4A112L, 4294967286UL,
                       0xC5BE975AL, 0x84D0L},
                      {0xC3AC4E32L, 0x82CCL, 1UL, 0x7F2D53F5L, 4294967295UL,
                       1UL, 7UL},
                      {0xCCE96CF9L, 0x7056L, 0UL, 0x3F89658EL, 1UL, 3UL, 0UL},
                      {0x0ACF52EDL, 65527UL, 0UL, 1L, 1UL, 0UL, 0x006EL}},
                     {{-4L, 65535UL, 0UL, 2L, 4294967295UL, 4294967287UL, 2UL},
                      {0x72FEF34CL, 3UL, 0x49A21933L, 0L, 0x3330DF52L,
                       4294967295UL, 6UL},
                      {0xCCE96CF9L, 0x7056L, 0UL, 0x3F89658EL, 1UL, 3UL, 0UL},
                      {0x73221832L, 0xB58DL, 3UL, 0L, 1UL, 0x4DC72634L,
                       65535UL},
                      {0x73221832L, 0xB58DL, 3UL, 0L, 1UL, 0x4DC72634L,
                       65535UL}},
                     {{0x0ACF52EDL, 65527UL, 0UL, 1L, 1UL, 0UL, 0x006EL},
                      {0x3485922EL, 0x5387L, 3UL, 0x5F0FF9A5L, 4294967295UL,
                       0xCBB4DEF0L, 0xB606L},
                      {-1L, 1UL, 1UL, 0L, 0UL, 4294967289UL, 0x2D29L},
                      {-10L, 1UL, 9UL, 0x0B28D5FCL, 0x46DE1B6EL, 0x2B325E89L,
                       65531UL},
                      {0x6001C466L, 65531UL, 0xF8F92EDFL, 0xC71DB368L,
                       4294967295UL, 4294967295UL, 0x9C50L}}},
                    {{{-1L, 65529UL, 0xC9DDAC57L, 0x471B025DL, 0x5BDEEFA2L,
                       0xA741CB4EL, 8UL},
                      {1L, 0xC834L, 1UL, -4L, 0xD203C118L, 1UL, 65535UL},
                      {0xA820905CL, 65530UL, 0x2497B0EEL, 0xBDB215D4L,
                       0x8ECA5571L, 0x86B3E2E0L, 0xA4A4L},
                      {0xDAC36A7DL, 0x60F5L, 0x7A6EF175L, 0xD074A6F4L,
                       4294967291UL, 4294967290UL, 0xF171L},
                      {0x72FEF34CL, 3UL, 0x49A21933L, 0L, 0x3330DF52L,
                       4294967295UL, 6UL}},
                     {{0x3485922EL, 0x5387L, 3UL, 0x5F0FF9A5L, 4294967295UL,
                       0xCBB4DEF0L, 0xB606L},
                      {0x6001C466L, 65531UL, 0xF8F92EDFL, 0xC71DB368L,
                       4294967295UL, 4294967295UL, 0x9C50L},
                      {0x4F9B6631L, 0UL, 6UL, 1L, 4294967295UL, 4UL, 0UL},
                      {0x73221832L, 0xB58DL, 3UL, 0L, 1UL, 0x4DC72634L,
                       65535UL},
                      {1L, 0xABABL, 0x32C31175L, 0L, 9UL, 0xE6DAA2BBL, 3UL}},
                     {{0x64D5F042L, 65528UL, 0xB3E11D9FL, 0L, 0UL, 0xE1715A2FL,
                       65529UL},
                      {-5L, 65535UL, 0x77780E33L, 0xAAE4A112L, 4294967286UL,
                       0xC5BE975AL, 0x84D0L},
                      {0xA820905CL, 65530UL, 0x2497B0EEL, 0xBDB215D4L,
                       0x8ECA5571L, 0x86B3E2E0L, 0xA4A4L},
                      {0x72FEF34CL, 3UL, 0x49A21933L, 0L, 0x3330DF52L,
                       4294967295UL, 6UL},
                      {1L, 1UL, 1UL, 0x8043446BL, 0x514C231DL, 0x51262750L,
                       0x4D28L}},
                     {{0x0ACF52EDL, 65527UL, 0UL, 1L, 1UL, 0UL, 0x006EL},
                      {0xBE4029E3L, 0xC32CL, 0UL, 0L, 4294967295UL, 0xDAB356C9L,
                       4UL},
                      {-1L, 1UL, 1UL, 0L, 0UL, 4294967289UL, 0x2D29L},
                      {-1L, 1UL, 1UL, 0L, 0UL, 4294967289UL, 0x2D29L},
                      {0xBE4029E3L, 0xC32CL, 0UL, 0L, 4294967295UL, 0xDAB356C9L,
                       4UL}},
                     {{1L, 0xABABL, 0x32C31175L, 0L, 9UL, 0xE6DAA2BBL, 3UL},
                      {0xBE4029E3L, 0xC32CL, 0UL, 0L, 4294967295UL, 0xDAB356C9L,
                       4UL},
                      {0xDAC36A7DL, 0x60F5L, 0x7A6EF175L, 0xD074A6F4L,
                       4294967291UL, 4294967290UL, 0xF171L},
                      {-1L, 65529UL, 0xC9DDAC57L, 0x471B025DL, 0x5BDEEFA2L,
                       0xA741CB4EL, 8UL},
                      {0xF1826ED3L, 3UL, 8UL, 1L, 0x68534FFBL, 4294967295UL,
                       0xB2B8L}}}};
                int32_t l_997 = 0x00243E11L;
                int i, j, k;
                l_912 =
                    (65535UL !=
                     ((safe_add_func_int16_t_s_s(
                          ((((safe_mul_func_uint16_t_u_u(
                                 (g_415[0][0].f0 ^ g_5[0].f4), 0x4B05L)) |
                             (safe_lshift_func_int8_t_s_u(
                                 (g_28.f4 <=
                                  (safe_mul_func_int8_t_s_s(
                                      (safe_mul_func_uint8_t_u_u(
                                          (safe_sub_func_int32_t_s_s(
                                              (-10L),
                                              (((l_990[3][2][4],
                                                 ((safe_rshift_func_int8_t_s_u(
                                                      (g_159 =
                                                           ((safe_lshift_func_int16_t_s_s(
                                                                (safe_add_func_uint32_t_u_u(
                                                                    ((g_76[2][0]
                                                                          [9]
                                                                              .f4 |=
                                                                      0x5F68L) &
                                                                     (((l_997 |=
                                                                        (p_7 >
                                                                         0x9FL)) >
                                                                       (-9L)) ^
                                                                      0L)),
                                                                    g_415[0][0]
                                                                        .f3)),
                                                                p_7)) &&
                                                            (-5L))),
                                                      4)),
                                                  l_977[0])),
                                                0x3BL) >= p_9))),
                                          g_181)),
                                      4UL))),
                                 l_898))) <= 0x82L) ||
                           p_7),
                          g_580)) != 0xEFL));
              } else {
                if (g_28.f6) break;
                l_977[2] |= ((safe_add_func_uint32_t_u_u(l_871.f5, l_906)) >=
                             g_846[6][1]);
                l_977[2] &= 0xE00427E9L;
              }
              if (g_472[0][0][4]) {
                uint16_t l_1017 = 0x2C8DL;
                struct S2 l_1019 = {-3L, 0xF6L, 0xAE5FL, 0x8F5B9E08L,
                                    0x91DAL, 2L, 65531UL};
                int32_t l_1034[10][3][2] = {{{(-5L), 0x5AE13C86L},
                                             {0x5AE13C86L, 0x9E077E0FL},
                                             {0xDA2BB4DBL, 0xA00BEDE4L}},
                                            {{(-5L), 0xDA2BB4DBL},
                                             {0xA00BEDE4L, 0x9E077E0FL},
                                             {0xA00BEDE4L, 0xDA2BB4DBL}},
                                            {{(-5L), 0xA00BEDE4L},
                                             {0xDA2BB4DBL, 0x9E077E0FL},
                                             {0x5AE13C86L, 0x5AE13C86L}},
                                            {{(-5L), 0x5AE13C86L},
                                             {0x5AE13C86L, 0x9E077E0FL},
                                             {0xDA2BB4DBL, 0xA00BEDE4L}},
                                            {{(-5L), 0xDA2BB4DBL},
                                             {0xA00BEDE4L, 0x9E077E0FL},
                                             {0xA00BEDE4L, 0xDA2BB4DBL}},
                                            {{(-5L), 0xA00BEDE4L},
                                             {0xDA2BB4DBL, 0x9E077E0FL},
                                             {0x5AE13C86L, 0x5AE13C86L}},
                                            {{(-5L), 0x5AE13C86L},
                                             {0x5AE13C86L, 0x9E077E0FL},
                                             {0xDA2BB4DBL, 0xA00BEDE4L}},
                                            {{(-5L), 0xDA2BB4DBL},
                                             {0xA00BEDE4L, 0x9E077E0FL},
                                             {0xA00BEDE4L, 0xDA2BB4DBL}},
                                            {{(-5L), 0xA00BEDE4L},
                                             {0xDA2BB4DBL, 0x9E077E0FL},
                                             {0x5AE13C86L, 0x5AE13C86L}},
                                            {{(-5L), 0x5AE13C86L},
                                             {0x5AE13C86L, 0x9E077E0FL},
                                             {0xDA2BB4DBL, 0xA00BEDE4L}}};
                int i, j, k;
                l_872 =
                    (l_1019 =
                         ((safe_lshift_func_uint8_t_u_s(
                              g_290.f3,
                              (safe_add_func_uint32_t_u_u(
                                  (~(((safe_add_func_uint8_t_u_u(
                                          l_898,
                                          (4UL &
                                           (g_415[0][0].f1 !=
                                            ((safe_sub_func_int16_t_s_s(
                                                 (l_871.f5 >=
                                                  ((safe_rshift_func_int16_t_s_u(
                                                       l_1010,
                                                       (l_890 =
                                                            (((safe_lshift_func_uint8_t_u_s(
                                                                  0xBFL, 1)) >
                                                              ((+((((safe_add_func_int32_t_s_s(
                                                                        ((safe_rshift_func_uint8_t_u_u(
                                                                             (l_905 ||
                                                                              p_9),
                                                                             p_7)) ==
                                                                         0UL),
                                                                        g_584)) >=
                                                                    65535UL),
                                                                   0x1BC4L) |
                                                                  g_28.f1)) ||
                                                               g_766)) ==
                                                             l_872.f3)))) &&
                                                   (-2L))),
                                                 l_872.f1)) <= g_584))))) &
                                      l_956.f0) == l_1017)),
                                  4294967295UL)))),
                          l_1018));
                l_906 ^= (((l_934 > (l_1020, p_8)) <
                           ((safe_rshift_func_uint16_t_u_u(
                                ((safe_mod_func_uint16_t_u_u(
                                     ((safe_mul_func_int8_t_s_s(
                                          l_897, ((l_13[4][0][6] == p_8) |
                                                  (safe_mul_func_int16_t_s_s(
                                                      p_7, p_8))))) !=
                                      (((((safe_sub_func_uint32_t_u_u(
                                              ((((safe_mul_func_uint16_t_u_u(
                                                     (((g_811, l_1033), p_7) <=
                                                      g_160),
                                                     1UL)) ^
                                                 g_415[0][0].f3) <= l_871.f6) >=
                                               l_1018.f1),
                                              l_1017)),
                                          l_956),
                                         g_76[2][0][9]),
                                        p_7) != p_8)),
                                     p_8)) == l_1033.f2),
                                g_16)) <= 0L)) &
                          l_1033.f5);
                g_1038--;
              } else {
                struct S2 l_1052 = {1L, 0x68L, 0L, 0x2AFFD3EEL,
                                    9L, 1L, 0x2769L};
                l_934 = p_8;
                g_162 |= (safe_lshift_func_uint8_t_u_u(
                    (safe_unary_minus_func_int32_t_s(
                        (((safe_unary_minus_func_uint32_t_u(
                              ((safe_add_func_uint32_t_u_u(
                                   l_872.f1,
                                   ((0xBB4BE26CL ^
                                     (l_1020.f4 >
                                      (p_8 ==
                                       ((p_7 != 0x75A9L) &&
                                        (((p_7 !=
                                           (safe_mul_func_uint8_t_u_u(
                                               ((l_1049 >
                                                 (!(((safe_mod_func_int8_t_s_s(
                                                         (((-1L) ^ l_1018.f0) |
                                                          l_875),
                                                         p_8)) &&
                                                     g_374) <= 0x3DL))) <= p_7),
                                               (-2L)))) < l_871.f0),
                                         l_931.f5))))) != p_7))) |
                               0x25L))) ^
                          g_28.f3) > g_846[4][7]))),
                    l_977[1]));
                g_76[4][2][3] = l_1052;
                if (l_931.f4) break;
              }
            }
            l_902 = l_1033.f1;
          } else {
            uint16_t l_1066 = 0xFAA9L;
            int32_t l_1118 = 6L;
            for (g_290.f6 = 0; (g_290.f6 <= 2);
                 g_290.f6 = safe_add_func_int16_t_s_s(g_290.f6, 9)) {
              int32_t l_1072 = (-1L);
              const int32_t l_1077 = 0x88405E55L;
              int32_t l_1116 = (-1L);
              for (l_872.f5 = 15; (l_872.f5 != 26);
                   l_872.f5 = safe_add_func_uint8_t_u_u(l_872.f5, 1)) {
                g_467 ^= (-1L);
                if (g_16) break;
                ++l_1057[3][2];
                g_76[2][0][9] = g_28;
              }
              for (g_160 = (-9); (g_160 == (-12)); g_160--) {
                int8_t l_1079 = 0x8FL;
                l_901 ^=
                    (l_1080 =
                         (p_7 |
                          (((safe_lshift_func_uint16_t_u_s(0x934CL, 9)) >=
                            ((p_8 <
                              ((((safe_mul_func_uint8_t_u_u(
                                     (l_1033.f2,
                                      ((((6L <
                                          ((l_1067[0][1] = l_1066) >
                                           (safe_add_func_int8_t_s_s(
                                               ((safe_mod_func_int8_t_s_s(
                                                    l_1072,
                                                    (safe_mod_func_int32_t_s_s(
                                                        (safe_lshift_func_uint8_t_u_u(
                                                            p_8, 7)),
                                                        p_7)))) != l_1077),
                                               g_181)))) <= 1UL) <
                                        0x15042F27L) ||
                                       0xBE9F595DL)),
                                     g_845)),
                                 l_1078) &
                                l_905),
                               l_1079)) |
                             (-10L))) ||
                           p_9)));
                if (l_1072) continue;
              }
   l_901
     =
     ((safe_mul_func_int8_t_s_s ((safe_mul_func_uint16_t_u_u (((safe_rshift_func_int16_t_s_s (((safe_lshift_func_uint8_t_u_u ((p_8 >= 4L), (l_1118 = ((((safe_add_func_int8_t_s_s ((((l_1116 = (safe_mod_func_uint32_t_u_u ((((((p_8 <= ((safe_mod_func_uint8_t_u_u (p_8, (~(safe_lshift_func_uint16_t_u_s (p_8, (((0xC8L && ((safe_sub_func_uint16_t_u_u (g_16, ((safe_sub_func_uint32_t_u_u (((safe_mod_func_uint32_t_u_u ((safe_mul_func_uint16_t_u_u ((safe_mul_func_uint16_t_u_u (((((l_906 = (g_468 <= ((!(safe_rshift_func_int16_t_s_u (((((safe_mod_func_int8_t_s_s ((+((safe_rshift_func_int16_t_s_u ((safe_mod_func_int8_t_s_s (p_9, l_1077)), l_1057[2][8])) <= l_1072)), l_1115)) > 4294967292UL) > 0x28L) & l_956.f4), 14))) | p_8))) && l_1033.f4) || g_415[0][0].f2) & p_8), 0xB7FEL)), l_934)), g_28.f2)) <= l_1066), 0x3D38DBD2L)) > p_7))), g_5[0].f4)) == l_872.f5) == g_160)))))) <= p_7)) > 0x44A19AE9L) || p_8) && l_1057[0][0]), l_1037), p_7))) ^ g_17[5]) < (-7L)), 0x59L)) > g_415[0][0].f0), l_1117), l_1033.f4)))) != p_8), 9)), 65527UL), p_9)), g_290.f1)) == 0UL);
            }
            l_1124 =
                ((2L < (safe_sub_func_uint8_t_u_u(0UL, (l_934 = l_956.f1)))) &
                 ((safe_mul_func_uint8_t_u_u(
                      ((7UL && ((l_1123, l_875) &
                                ((g_415[0][0].f5 <
                                  (((-6L) ^ ((g_811 ^= p_7) <= l_1057[5][2])) >
                                   g_415[0][0].f5)) != g_76[2][0][9].f0))) ==
                       g_17[5]),
                      0xB5L)) &&
                  0xBB53C313L));
          }
        }

        l_1124 = ((2L < (safe_sub_func_uint8_t_u_u(0UL, (l_934 = l_956.f1)))) &
                  ((safe_mul_func_uint8_t_u_u(
                       ((7UL && ((l_1123, l_875) &
                                 ((g_415[0][0].f5 <
                                   (((-6L) ^ ((g_811 ^= p_7) <= l_1057[5][2])) >
                                    g_415[0][0].f5)) != g_76[2][0][9].f0))) ==
                        g_17[5]),
                       0xB5L)) &&
                   0xBB53C313L));
      }
    }
  }
  g_76[2][0][9] = l_872;
  return p_7;
}

static int32_t func_20(const int8_t p_21) {
  struct S2 l_29 = {0L, 255UL, -2L, 4294967295UL, 0L, 0x519BL, 1UL};
  uint8_t l_771 = 0x77L;
  uint8_t l_772 = 0x7AL;
  int32_t l_773[3];
  int i;
  for (i = 0; i < 3; i++) l_773[i] = 0x7F4C3013L;
  g_22 ^= p_21;
  for (g_16 = 0; (g_16 < 56); ++g_16) {
    struct S2 l_27 = {0xE520C3D8L, 1UL, -5L, 0xB296AD98L, 1L, 0xAEB9L, 0x3763L};
    uint32_t l_768[8][2] = {
        {4294967295UL, 0x1B4A6FFDL}, {4294967295UL, 0x1B4A6FFDL},
        {4294967295UL, 0x1B4A6FFDL}, {4294967295UL, 0x1B4A6FFDL},
        {4294967295UL, 0x1B4A6FFDL}, {4294967295UL, 0x1B4A6FFDL},
        {4294967295UL, 0x1B4A6FFDL}, {4294967295UL, 0x1B4A6FFDL}};
    int32_t l_834 = 0L;
    int32_t l_841 = 0x7AD944F7L;
    int32_t l_843 = 0x2958D11EL;
    int32_t l_844 = 0x76D09BBDL;
    int i, j;
    for (g_22 = 0; (g_22 >= 27); g_22 = safe_add_func_uint32_t_u_u(g_22, 2)) {
      uint8_t l_33 = 0x8BL;
      const struct S1 l_767[10] = {
          {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L},
          {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L},
          {0x46L, 0x96764F14L, 2UL, 0x36891233L, 0UL, -7L},
          {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L},
          {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L},
          {0x46L, 0x96764F14L, 2UL, 0x36891233L, 0UL, -7L},
          {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L},
          {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L},
          {0x46L, 0x96764F14L, 2UL, 0x36891233L, 0UL, -7L},
          {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L}};
      int i;
      l_29 = (g_28 = l_27);
      l_773[0] = ((((-2L) & p_21) !=
                   (func_30(l_29, l_33),
                    (((((((l_767[6], l_768[1][1]) !=
                          (0L && (safe_mul_func_int8_t_s_s(
                                     ((l_771 && 0x4DL) >= l_772), g_28.f1)))) ^
                         l_27.f4) ||
                        1UL) &&
                       p_21) == l_27.f5),
                     l_33))) ||
                  g_290.f1);
    }
    l_29 = l_27;
    if (p_21) {
      uint32_t l_780 = 6UL;
      int32_t l_781[2][7][6] = {
          {{0x46A7AD03L, 0L, (-1L), 0x963E7327L, 0xD0DB5B36L, 0xD0DB5B36L},
           {0x963E7327L, 0xD0DB5B36L, 0xD0DB5B36L, 0x963E7327L, (-1L), 0L},
           {0x46A7AD03L, 1L, 0L, 0L, 0xF132239AL, 0xF53ED125L},
           {0xF132239AL, (-1L), 0xC86AD7C0L, (-1L), 0xF132239AL, 1L},
           {0xF53ED125L, 1L, 0x035D88C6L, (-1L), (-1L), 0L},
           {0L, 0xD0DB5B36L, 1L, 1L, 0xD0DB5B36L, 0L},
           {(-1L), 0L, 0x035D88C6L, 0xF132239AL, 0L, 1L}},
          {{0xD0DB5B36L, 0xF53ED125L, 0xC86AD7C0L, 0L, 0xC86AD7C0L,
            0xF53ED125L},
           {0xD0DB5B36L, 1L, 0L, 0xF132239AL, 0x035D88C6L, 0L},
           {(-1L), 0L, 0xD0DB5B36L, 1L, 1L, 0xD0DB5B36L},
           {0L, 0L, (-1L), (-1L), 0x035D88C6L, 1L},
           {0xF53ED125L, 1L, 0xF132239AL, (-1L), 0xC86AD7C0L, (-1L)},
           {0xF132239AL, 0xF53ED125L, 0xF132239AL, 1L, (-1L), 0xD0DB5B36L},
           {0xF132239AL, 1L, 0xF53ED125L, 0L, 0x963E7327L, 0x963E7327L}}};
      int i, j, k;
      if (((p_21 >
            ((safe_mod_func_int32_t_s_s(
                 (g_447 ^=
                  (g_162 = (safe_rshift_func_uint16_t_u_u(
                       (safe_mul_func_int16_t_s_s(
                           ((((l_781[1][4][2] |= l_780) ==
                              (l_27.f2 !=
                               ((p_21 >=
                                 ((((((4L || p_21) ^ g_467) !=
                                     (safe_add_func_int32_t_s_s(
                                         0x3EF30D39L,
                                         (safe_sub_func_int32_t_s_s(
                                             ((g_415[3][0], g_17[5]) < 0L),
                                             p_21))))) < 4294967295UL) ==
                                   p_21) != p_21)),
                                g_467))) &
                             65527UL) > l_27.f1),
                           p_21)),
                       3)))),
                 4294967293UL)) != 2UL)) > p_21)) {
        uint8_t l_790 = 0x5FL;
        int32_t l_810[2][3][2] = {{{0x03D6D626L, 0xBC554963L},
                                   {0x03D6D626L, 0xBC554963L},
                                   {0x03D6D626L, 0xBC554963L}},
                                  {{0x03D6D626L, 0xBC554963L},
                                   {0x03D6D626L, 0xBC554963L},
                                   {0x03D6D626L, 0xBC554963L}}};
        int i, j, k;
        for (l_27.f6 = 0; (l_27.f6 > 45); l_27.f6++) {
          int32_t l_797 = 1L;
          int32_t l_809 = 4L;

          ++g_811;
        }
      } else {
        int32_t l_827 = 0x23B3B689L;
        struct S2 l_830 = {0x8546CB26L, 1UL, 0x2EE0L, 0xD4AAF366L,
                           0x9335L, 0x2507L, 65535UL};
        int32_t l_835 = (-4L);
        int32_t l_836 = 1L;
        int32_t l_837 = 0x230833C9L;
        int32_t l_838[8];
        int i;
        for (i = 0; i < 8; i++) {
          l_838[i] = 0x0F1A7A0EL;
          {
            uint8_t l_33 = 0x8BL;
            const struct S1 l_767[10] = {
                {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L},
                {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L},
                {0x46L, 0x96764F14L, 2UL, 0x36891233L, 0UL, -7L},
                {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L},
                {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L},
                {0x46L, 0x96764F14L, 2UL, 0x36891233L, 0UL, -7L},
                {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L},
                {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L},
                {0x46L, 0x96764F14L, 2UL, 0x36891233L, 0UL, -7L},
                {255UL, 0xBC75E543L, 65534UL, 4294967290UL, 0x75CFL, 0xC718L}};
            int i;
            l_29 = (g_28 = l_27);
            l_773[0] =
                ((((-2L) & p_21) !=
                  (func_30(l_29, l_33),
                   (((((((l_767[6], l_768[1][1]) !=
                         (0L && (safe_mul_func_int8_t_s_s(
                                    ((l_771 && 0x4DL) >= l_772), g_28.f1)))) ^
                        l_27.f4) ||
                       1UL) &&
                      p_21) == l_27.f5),
                    l_33))) ||
                 g_290.f1);
          }

          l_29 = l_27;
        }
      }
    } else {
      l_29 = g_28;
    }
    for (g_28.f5 = (-27); (g_28.f5 >= 14);
         g_28.f5 = safe_add_func_int16_t_s_s(g_28.f5, 1)) {
    }
  }
  return l_772;
}

static uint32_t func_30(struct S2 p_31, int32_t p_32) {
  int8_t l_60 = 1L;
  struct S0 l_73 = {0xA2B5195EL, 0xC378L, 0x16A71534L, 2L,
                    1UL, 0xA85E45CFL, 0x1528L};
  struct S0 l_74 = {0x38899A86L, 0UL, 4294967288UL, -1L,
                    0x4BD6B41AL, 0x4168CBA4L, 0x4122L};
  int32_t l_583 = 2L;
  const struct S2 l_586 = {2L, 255UL, 0xD4B0L, 2UL, 1L, 0xD8BAL, 0xD4EAL};
  g_766 &=
      ((safe_sub_func_uint32_t_u_u(
           (safe_lshift_func_int16_t_s_s(
               (safe_lshift_func_uint16_t_u_u(
                   (safe_mul_func_uint8_t_u_u(
                       (0L ^
                        (safe_rshift_func_uint8_t_u_s(
                            0UL,
                            (safe_mul_func_int16_t_s_s(
                                (safe_mul_func_uint16_t_u_u(
                                    (func_48(
                                         func_54(
                                             g_28.f3,
                                             ((l_60 !=
                                               ((l_60,
                                                 ((g_584 =
                                                       (l_583 = func_61((
                                                            (l_60 <
                                                             (((safe_add_func_int16_t_s_s(
                                                                   l_60,
                                                                   ((safe_lshift_func_int16_t_s_s(
                                                                        l_60,
                                                                        func_67(
                                                                            l_60,
                                                                            l_73,
                                                                            p_31.f5,
                                                                            l_74,
                                                                            g_5[0]
                                                                                .f1))) &&
                                                                    p_31.f3))) ==
                                                               251UL) ^
                                                              0xA667L)),
                                                            g_5[0])))),
                                                  g_28.f5)) |
                                                g_5[0].f5)) > p_31.f5),
                                             l_74.f1, l_74.f1, l_73.f3),
                                         l_74.f1, l_586, p_31.f1,
                                         l_586.f4) > 0x05L),
                                    g_5[0].f3)),
                                0x186FL))))),
                       g_5[0].f4)),
                   4)),
               g_5[0].f2)),
           p_31.f3)) != 0UL);
  return g_162;
}

static int8_t func_48(uint8_t p_49, uint8_t p_50, const struct S2 p_51,
                      int32_t p_52, uint32_t p_53) {
  int8_t l_599 = 0L;
  int8_t l_600 = (-10L);
  int32_t l_601 = 0xF1C50707L;
  uint8_t l_602 = 1UL;
  const uint32_t l_689[9] = {0UL, 0x6DD5FCB1L, 0UL, 0UL, 0x6DD5FCB1L,
                             0UL, 0UL, 0x6DD5FCB1L, 0UL};
  struct S1 l_764[8] = {{0UL, 0x52B6FADFL, 0x14E4L, 4294967295UL, 0xE30CL, -1L},
                        {6UL, 0x4225695DL, 65535UL, 0x965FA91EL, 0xB59DL, -1L},
                        {0UL, 0x52B6FADFL, 0x14E4L, 4294967295UL, 0xE30CL, -1L},
                        {0UL, 0x52B6FADFL, 0x14E4L, 4294967295UL, 0xE30CL, -1L},
                        {6UL, 0x4225695DL, 65535UL, 0x965FA91EL, 0xB59DL, -1L},
                        {0UL, 0x52B6FADFL, 0x14E4L, 4294967295UL, 0xE30CL, -1L},
                        {0UL, 0x52B6FADFL, 0x14E4L, 4294967295UL, 0xE30CL, -1L},
                        {6UL, 0x4225695DL, 65535UL, 0x965FA91EL, 0xB59DL, -1L}};
  const uint16_t l_765 = 0UL;
  int i;
  if ((safe_rshift_func_uint8_t_u_s(
          (g_76[2][0][9].f1 =
               ((((p_50 = 255UL) >
                  (safe_sub_func_int32_t_s_s(g_5[0].f1, (0x21L | p_53)))) <
                 ((safe_mul_func_uint16_t_u_u(
                      ((~((1L !=
                           (((g_159 =
                                  ((safe_sub_func_int8_t_s_s(
                                       1L, (p_51.f1,
                                            (safe_mod_func_uint8_t_u_u(
                                                (safe_rshift_func_int16_t_s_s(
                                                    l_599, 7)),
                                                g_17[5]))))) != p_52)) ||
                             l_599),
                            251UL)) ^
                          p_52)) < l_600),
                      l_600)) >= g_415[0][0].f2)) != l_599)),
          7))) {
    l_602--;
    l_602--;

    g_76[2][0][9] = g_76[3][3][5];
  } else {
    uint8_t l_658 = 246UL;
    int32_t l_661 = 0L;
    int32_t l_677 = (-1L);
    struct S2 l_730 = {-1L, 0x5DL, 0L, 0UL, 1L, 4L, 0x98B5L};
    if (g_290.f4) {
      int32_t l_608 = 0x5065081DL;
      int32_t l_609 = 0x8B2CF0D5L;
      int32_t l_712 = (-10L);
      for (p_50 = 0; (p_50 > 57); p_50 = safe_add_func_uint32_t_u_u(p_50, 3)) {
        int8_t l_607 = (-1L);
        l_609 ^= (l_608 = (p_52 &= l_607));
        {
          l_602--;
          g_76[2][0][9] = g_76[3][3][5];
        }
      }
      {
        l_602--;
        g_76[2][0][9] = g_76[3][3][5];
      }

      for (p_53 = 0; (p_53 > 8); ++p_53) {
        return l_608;
      }
      for (g_181 = 0; (g_181 < 24);
           g_181 = safe_add_func_int16_t_s_s(g_181, 6)) {
        const uint32_t l_621 = 1UL;
        uint16_t l_659[4][10][4] = {{{65535UL, 0xFC8EL, 0xF023L, 0xB7B7L},
                                     {4UL, 65532UL, 65531UL, 2UL},
                                     {5UL, 0xA733L, 0xE5B1L, 0x4A92L},
                                     {65535UL, 0x7A5EL, 65532UL, 0xFC8EL},
                                     {0xFC8EL, 65528UL, 0xB924L, 1UL},
                                     {65533UL, 0x18EDL, 0x1A4CL, 0UL},
                                     {0x7A5EL, 0xE5B1L, 5UL, 65531UL},
                                     {0x46AEL, 65533UL, 0xD670L, 65535UL},
                                     {0xF622L, 0xF978L, 1UL, 0x0621L},
                                     {0xED50L, 2UL, 0xED50L, 0xF023L}},
                                    {{0x5584L, 65531UL, 0x18EDL, 5UL},
                                     {0xF023L, 0UL, 0UL, 0x0621L},
                                     {0x4CC8L, 9UL, 65535UL, 0xF978L},
                                     {0x1A4CL, 0x18EDL, 65533UL, 65534UL},
                                     {0x4A92L, 1UL, 65528UL, 65535UL},
                                     {65528UL, 65535UL, 0xB924L, 4UL},
                                     {1UL, 0x421BL, 0x23FDL, 0UL},
                                     {0x9646L, 5UL, 65535UL, 65532UL},
                                     {0xC3EFL, 0xED50L, 0xB7B7L, 0x2E31L},
                                     {0xE5B1L, 0x0BCDL, 0x7A5EL, 5UL}},
                                    {{0xBC67L, 65533UL, 0x2E31L, 0xF622L},
                                     {0xD072L, 0xB7B7L, 0UL, 0xF023L},
                                     {65535UL, 65532UL, 0xD670L, 0x421BL},
                                     {5UL, 65531UL, 0x1A4CL, 0x4CC8L},
                                     {4UL, 65528UL, 0x9646L, 0UL},
                                     {0UL, 0x1A4CL, 0xCCCEL, 0xCCCEL},
                                     {65535UL, 65535UL, 0x0BCDL, 0xD670L},
                                     {0xF023L, 0UL, 0UL, 1UL},
                                     {0UL, 5UL, 65528UL, 0UL},
                                     {0xF116L, 5UL, 0x0392L, 1UL}},
                                    {{5UL, 0UL, 4UL, 0xD670L},
                                     {0UL, 65535UL, 0x46AEL, 0xCCCEL},
                                     {1UL, 0x1A4CL, 0xF116L, 0UL},
                                     {0xF622L, 65528UL, 0x0621L, 0x4CC8L},
                                     {0xB924L, 65531UL, 0x0F0FL, 0x421BL},
                                     {9UL, 65532UL, 65531UL, 0xF023L},
                                     {0x0F0FL, 0xB7B7L, 0x4CC8L, 0xF622L},
                                     {7UL, 65533UL, 0UL, 5UL},
                                     {65528UL, 0x0BCDL, 0UL, 0x2E31L},
                                     {0x7A5EL, 0xED50L, 7UL, 65532UL}}};
        int32_t l_662 = 0x94CF11DEL;
        struct S2 l_663 = {0xFA05BAE7L, 0x2CL, 8L, 0x3EDB6E51L,
                           0xC033L, 0x632FL, 65532UL};
        uint32_t l_674 = 4294967292UL;
        int32_t l_678 = 0x6EC8AD47L;
        int i, j, k;
        for (g_290.f1 = 0; (g_290.f1 >= 5); g_290.f1++) {
          const int32_t l_630 = 0L;
          int32_t l_660 = 0L;
          int32_t l_707[3][9] = {
              {(-6L), (-6L), 0L, 8L, 0L, (-6L), (-6L), 0L, 8L},
              {0x152CA6F1L, (-1L), 0x152CA6F1L, 0L, 0L, 0x152CA6F1L, (-1L),
               0x152CA6F1L, 0L},
              {0x152CA6F1L, 0L, 0L, 0x152CA6F1L, (-1L), 0x152CA6F1L, 0L, 0L,
               0x152CA6F1L}};
          int i, j;
          for (g_468 = 0; (g_468 < 26);
               g_468 = safe_add_func_int8_t_s_s(g_468, 6)) {
            uint32_t l_631 = 0x0565A3F9L;
            g_374 =
                (((+p_51.f6) &
                  (+(safe_rshift_func_uint16_t_u_u(
                      0UL,
                      (((safe_unary_minus_func_int8_t_s((
                            g_5[0].f6 <=
                            ((((l_621 &&
                                (p_52 =
                                     ((safe_rshift_func_int8_t_s_s(
                                          g_17[5],
                                          (l_631 =
                                               ((safe_unary_minus_func_uint8_t_u((~(
                                                    (safe_rshift_func_uint16_t_u_s(
                                                        g_472[0]
                                                             [0]
                                                             [5],
                                                        12)) ||
                                                    (safe_unary_minus_func_int8_t_s(
                                                        (((0UL <= g_290.f3) ^
                                                          ((((safe_sub_func_uint32_t_u_u(
                                                                 (((0x36B184AAL |
                                                                    4294967295UL),
                                                                   g_447) ==
                                                                  (-9L)),
                                                                 g_290.f2)) <
                                                             g_17[5]) ==
                                                            l_630) == 249UL)) <
                                                         p_51.f4))))))),
                                                0xCFL)))) < l_621))),
                               g_5[0]),
                              p_51.f4) != g_28.f4)))) &
                        l_609) >= g_28.f2))))) != p_51.f5);
            for (g_290.f1 = 0; (g_290.f1 >= 5); g_290.f1++) {
              const int32_t l_630 = 0L;
              int32_t l_660 = 0L;
              int32_t l_707[3][9] = {
                  {(-6L), (-6L), 0L, 8L, 0L, (-6L), (-6L), 0L, 8L},
                  {0x152CA6F1L, (-1L), 0x152CA6F1L, 0L, 0L, 0x152CA6F1L, (-1L),
                   0x152CA6F1L, 0L},
                  {0x152CA6F1L, 0L, 0L, 0x152CA6F1L, (-1L), 0x152CA6F1L, 0L, 0L,
                   0x152CA6F1L}};
              int i, j;
              for (g_468 = 0; (g_468 < 26);
                   g_468 = safe_add_func_int8_t_s_s(g_468, 6)) {
                uint32_t l_631 = 0x0565A3F9L;
                g_374 =
                    (((+p_51.f6) &
                      (+(safe_rshift_func_uint16_t_u_u(
                          0UL,
                          (((safe_unary_minus_func_int8_t_s((
                                g_5[0].f6 <=
                                ((((l_621 &&
                                    (p_52 =
                                         ((safe_rshift_func_int8_t_s_s(
                                              g_17[5],
                                              (l_631 =
                                                   ((safe_unary_minus_func_uint8_t_u((~(
                                                        (safe_rshift_func_uint16_t_u_s(
                                                            g_472[0]
                                                                 [0]
                                                                 [5],
                                                            12)) ||
                                                        (safe_unary_minus_func_int8_t_s(
                                                            (((0UL <=
                                                               g_290.f3) ^
                                                              ((((safe_sub_func_uint32_t_u_u(
                                                                     (((0x36B184AAL |
                                                                        4294967295UL),
                                                                       g_447) ==
                                                                      (-9L)),
                                                                     g_290
                                                                         .f2)) <
                                                                 g_17[5]) ==
                                                                l_630) ==
                                                               249UL)) <
                                                             p_51.f4))))))),
                                                    0xCFL)))) < l_621))),
                                   g_5[0]),
                                  p_51.f4) != g_28.f4)))) &
                            l_609) >= g_28.f2))))) != p_51.f5);
                l_662 ^= (safe_sub_func_uint8_t_u_u(
                    (safe_lshift_func_int16_t_s_u(l_630, 3)),
                    (((safe_lshift_func_int16_t_s_u(
                          ((safe_rshift_func_uint16_t_u_s(p_50, 10)), p_53),
                          5)) < g_415[0][0].f2) ==
                     (safe_add_func_uint16_t_u_u(
                         (((((safe_sub_func_int32_t_s_s(
                                 (l_661 = (safe_mul_func_int16_t_s_s(
                                      0x1200L,
                                      (safe_mod_func_int8_t_s_s(
                                          (((safe_mul_func_uint8_t_u_u(
                                                ((safe_lshift_func_int8_t_s_u(
                                                     (l_660 =
                                                          ((safe_mod_func_uint8_t_u_u(
                                                               (g_415[0][0]
                                                                    .f2 ||
                                                                ((l_609 = (safe_mod_func_int8_t_s_s(
                                                                      l_631,
                                                                      (0x3FC2L ||
                                                                       (safe_mul_func_uint16_t_u_u(
                                                                           (2L ==
                                                                            l_658),
                                                                           l_599)))))) >=
                                                                 p_51.f2)),
                                                               g_449)) <
                                                           l_659[1][3][3])),
                                                     g_22)),
                                                 255UL),
                                                (-1L))) >= g_580) &
                                           255UL),
                                          7UL))))),
                                 1UL)) >= l_621) >= p_51.f1) &
                           (-1L)) &
                          2UL),
                         p_52)))));
                if (g_290.f2) break;
                l_663 = g_76[2][0][9];
              }
              if (p_51.f3) break;
              if (g_290.f6) {
                uint32_t l_692 = 4294967294UL;
                l_601 &= (safe_sub_func_int32_t_s_s(
                    ((safe_sub_func_int32_t_s_s(
                         l_663.f5,
                         (safe_rshift_func_uint8_t_u_s(
                             ((((safe_mul_func_int16_t_s_s(
                                    ((((safe_lshift_func_int8_t_s_u(
                                           (l_609 ^= 0xBAL), 0)) ^
                                       (((0x8ABFL <
                                          ((((l_674 !=
                                              (p_51.f6 |
                                               (g_472[0][0][6] |=
                                                (((((1L ||
                                                     (((safe_rshift_func_uint16_t_u_u(
                                                           1UL, l_677)) !=
                                                       l_630) ^
                                                      p_51.f3)) != p_51.f6) ||
                                                   p_51.f0) <= g_223) >=
                                                 p_53)))) > 0x377CL) != (-6L)) &
                                           l_677)),
                                         (-3L)) > g_290.f6)) == (-4L)) ^
                                     1L),
                                    0x1688L)) &&
                                0L) > g_290.f3) != p_51.f0),
                             g_368[2])))) <= 0x089E91BAL),
                    0x86C4B67CL));
                if (g_5[0].f5) break;
                if (l_602) break;
                l_678 =
                    ((0UL || l_678),
                     ((safe_rshift_func_uint8_t_u_s(
                          (safe_mul_func_int8_t_s_s(
                              ((((safe_add_func_int8_t_s_s(
                                     0x5BL,
                                     ((p_52,
                                       (safe_mod_func_int32_t_s_s(
                                           (safe_add_func_int32_t_s_s(
                                               (l_662 =
                                                    (g_5[0].f0 !=
                                                     (p_51.f6 !=
                                                      (l_689[8],
                                                       (safe_add_func_uint16_t_u_u(
                                                           (p_50 <=
                                                            (l_661 ==
                                                             g_415[0][0].f2)),
                                                           l_692)))))),
                                               0L)),
                                           0x5AE8D3F4L))),
                                      0UL))) <= p_51.f5) <= p_49) ^
                               g_415[0][0].f0),
                              l_692)),
                          5)),
                      g_162));
              } else {
                p_52 =
                    ((((((safe_lshift_func_uint16_t_u_s(
                             p_53,
                             (safe_mod_func_uint32_t_u_u(
                                 (l_689[8] &&
                                  ((safe_lshift_func_int16_t_s_s(
                                       (safe_sub_func_int8_t_s_s(
                                           (l_660 =
                                                ((((safe_lshift_func_uint16_t_u_u(
                                                       ((safe_rshift_func_uint16_t_u_s(
                                                            (l_661 =
                                                                 (((0xB5L |
                                                                    (-9L)) !=
                                                                   ((safe_rshift_func_int16_t_s_u(
                                                                        l_608,
                                                                        (l_707[2][2] =
                                                                             (p_53 &
                                                                              l_663
                                                                                  .f2)))) >
                                                                    (safe_add_func_uint32_t_u_u(
                                                                        g_5[0]
                                                                            .f6,
                                                                        (safe_add_func_int32_t_s_s(
                                                                            l_659
                                                                                [1]
                                                                                [3]
                                                                                [3],
                                                                            5UL)))))),
                                                                  g_160)),
                                                            g_415[0][0].f3)),
                                                        1UL),
                                                       p_51.f5)) &
                                                   g_16) == g_28.f6),
                                                 (-7L))),
                                           0x78L)),
                                       l_663.f3)) &&
                                   l_677)),
                                 0x2075DBD4L)))),
                         2UL) > p_52),
                       0xB3EF5C9AL) != l_602) < p_51.f0);
                g_374 &=
                    ((~(l_712 ^
                        (safe_add_func_int32_t_s_s(
                            0L,
                            (safe_lshift_func_uint16_t_u_s(
                                (g_5[0].f2 &
                                 (((safe_lshift_func_uint8_t_u_s(
                                       ((p_52 = p_51.f5) ^
                                        ((safe_rshift_func_int8_t_s_s(
                                             ((safe_add_func_uint32_t_u_u(
                                                  (safe_mul_func_uint8_t_u_u(
                                                      ((safe_lshift_func_int16_t_s_u(
                                                           l_661, 1)) ||
                                                       ((safe_sub_func_int32_t_s_s(
                                                            g_28.f4,
                                                            ((p_51.f6,
                                                              ((g_470 =
                                                                    ((g_580 =
                                                                          255UL) >
                                                                     g_290
                                                                         .f6)) ||
                                                               g_467)),
                                                             0x99A700AFL))) <=
                                                        6L)),
                                                      l_678)),
                                                  g_290.f4)) ^
                                              g_5[0].f1),
                                             6)) &
                                         0x77L)),
                                       l_707[2][2])) == 253UL) |
                                  g_22)),
                                9)))))) &
                     l_689[8]);
                return p_51.f0;
              }
            }

            { return l_608; }

            for (g_290.f1 = 0; (g_290.f1 >= 5); g_290.f1++) {
              const int32_t l_630 = 0L;
              int32_t l_660 = 0L;
              int32_t l_707[3][9] = {
                  {(-6L), (-6L), 0L, 8L, 0L, (-6L), (-6L), 0L, 8L},
                  {0x152CA6F1L, (-1L), 0x152CA6F1L, 0L, 0L, 0x152CA6F1L, (-1L),
                   0x152CA6F1L, 0L},
                  {0x152CA6F1L, 0L, 0L, 0x152CA6F1L, (-1L), 0x152CA6F1L, 0L, 0L,
                   0x152CA6F1L}};
              int i, j;
              for (g_468 = 0; (g_468 < 26);
                   g_468 = safe_add_func_int8_t_s_s(g_468, 6)) {
                uint32_t l_631 = 0x0565A3F9L;
                g_374 =
                    (((+p_51.f6) &
                      (+(safe_rshift_func_uint16_t_u_u(
                          0UL,
                          (((safe_unary_minus_func_int8_t_s((
                                g_5[0].f6 <=
                                ((((l_621 &&
                                    (p_52 =
                                         ((safe_rshift_func_int8_t_s_s(
                                              g_17[5],
                                              (l_631 =
                                                   ((safe_unary_minus_func_uint8_t_u((~(
                                                        (safe_rshift_func_uint16_t_u_s(
                                                            g_472[0]
                                                                 [0]
                                                                 [5],
                                                            12)) ||
                                                        (safe_unary_minus_func_int8_t_s(
                                                            (((0UL <=
                                                               g_290.f3) ^
                                                              ((((safe_sub_func_uint32_t_u_u(
                                                                     (((0x36B184AAL |
                                                                        4294967295UL),
                                                                       g_447) ==
                                                                      (-9L)),
                                                                     g_290
                                                                         .f2)) <
                                                                 g_17[5]) ==
                                                                l_630) ==
                                                               249UL)) <
                                                             p_51.f4))))))),
                                                    0xCFL)))) < l_621))),
                                   g_5[0]),
                                  p_51.f4) != g_28.f4)))) &
                            l_609) >= g_28.f2))))) != p_51.f5);
                l_662 ^= (safe_sub_func_uint8_t_u_u(
                    (safe_lshift_func_int16_t_s_u(l_630, 3)),
                    (((safe_lshift_func_int16_t_s_u(
                          ((safe_rshift_func_uint16_t_u_s(p_50, 10)), p_53),
                          5)) < g_415[0][0].f2) ==
                     (safe_add_func_uint16_t_u_u(
                         (((((safe_sub_func_int32_t_s_s(
                                 (l_661 = (safe_mul_func_int16_t_s_s(
                                      0x1200L,
                                      (safe_mod_func_int8_t_s_s(
                                          (((safe_mul_func_uint8_t_u_u(
                                                ((safe_lshift_func_int8_t_s_u(
                                                     (l_660 =
                                                          ((safe_mod_func_uint8_t_u_u(
                                                               (g_415[0][0]
                                                                    .f2 ||
                                                                ((l_609 = (safe_mod_func_int8_t_s_s(
                                                                      l_631,
                                                                      (0x3FC2L ||
                                                                       (safe_mul_func_uint16_t_u_u(
                                                                           (2L ==
                                                                            l_658),
                                                                           l_599)))))) >=
                                                                 p_51.f2)),
                                                               g_449)) <
                                                           l_659[1][3][3])),
                                                     g_22)),
                                                 255UL),
                                                (-1L))) >= g_580) &
                                           255UL),
                                          7UL))))),
                                 1UL)) >= l_621) >= p_51.f1) &
                           (-1L)) &
                          2UL),
                         p_52)))));
                if (g_290.f2) break;
                l_663 = g_76[2][0][9];
              }
              if (p_51.f3) break;
              if (g_290.f6) {
                uint32_t l_692 = 4294967294UL;
                l_601 &= (safe_sub_func_int32_t_s_s(
                    ((safe_sub_func_int32_t_s_s(
                         l_663.f5,
                         (safe_rshift_func_uint8_t_u_s(
                             ((((safe_mul_func_int16_t_s_s(
                                    ((((safe_lshift_func_int8_t_s_u(
                                           (l_609 ^= 0xBAL), 0)) ^
                                       (((0x8ABFL <
                                          ((((l_674 !=
                                              (p_51.f6 |
                                               (g_472[0][0][6] |=
                                                (((((1L ||
                                                     (((safe_rshift_func_uint16_t_u_u(
                                                           1UL, l_677)) !=
                                                       l_630) ^
                                                      p_51.f3)) != p_51.f6) ||
                                                   p_51.f0) <= g_223) >=
                                                 p_53)))) > 0x377CL) != (-6L)) &
                                           l_677)),
                                         (-3L)) > g_290.f6)) == (-4L)) ^
                                     1L),
                                    0x1688L)) &&
                                0L) > g_290.f3) != p_51.f0),
                             g_368[2])))) <= 0x089E91BAL),
                    0x86C4B67CL));
                if (g_5[0].f5) break;
                if (l_602) break;
                l_678 =
                    ((0UL || l_678),
                     ((safe_rshift_func_uint8_t_u_s(
                          (safe_mul_func_int8_t_s_s(
                              ((((safe_add_func_int8_t_s_s(
                                     0x5BL,
                                     ((p_52,
                                       (safe_mod_func_int32_t_s_s(
                                           (safe_add_func_int32_t_s_s(
                                               (l_662 =
                                                    (g_5[0].f0 !=
                                                     (p_51.f6 !=
                                                      (l_689[8],
                                                       (safe_add_func_uint16_t_u_u(
                                                           (p_50 <=
                                                            (l_661 ==
                                                             g_415[0][0].f2)),
                                                           l_692)))))),
                                               0L)),
                                           0x5AE8D3F4L))),
                                      0UL))) <= p_51.f5) <= p_49) ^
                               g_415[0][0].f0),
                              l_692)),
                          5)),
                      g_162));
              } else {
                p_52 =
                    ((((((safe_lshift_func_uint16_t_u_s(
                             p_53,
                             (safe_mod_func_uint32_t_u_u(
                                 (l_689[8] &&
                                  ((safe_lshift_func_int16_t_s_s(
                                       (safe_sub_func_int8_t_s_s(
                                           (l_660 =
                                                ((((safe_lshift_func_uint16_t_u_u(
                                                       ((safe_rshift_func_uint16_t_u_s(
                                                            (l_661 =
                                                                 (((0xB5L |
                                                                    (-9L)) !=
                                                                   ((safe_rshift_func_int16_t_s_u(
                                                                        l_608,
                                                                        (l_707[2][2] =
                                                                             (p_53 &
                                                                              l_663
                                                                                  .f2)))) >
                                                                    (safe_add_func_uint32_t_u_u(
                                                                        g_5[0]
                                                                            .f6,
                                                                        (safe_add_func_int32_t_s_s(
                                                                            l_659
                                                                                [1]
                                                                                [3]
                                                                                [3],
                                                                            5UL)))))),
                                                                  g_160)),
                                                            g_415[0][0].f3)),
                                                        1UL),
                                                       p_51.f5)) &
                                                   g_16) == g_28.f6),
                                                 (-7L))),
                                           0x78L)),
                                       l_663.f3)) &&
                                   l_677)),
                                 0x2075DBD4L)))),
                         2UL) > p_52),
                       0xB3EF5C9AL) != l_602) < p_51.f0);
                g_374 &=
                    ((~(l_712 ^
                        (safe_add_func_int32_t_s_s(
                            0L,
                            (safe_lshift_func_uint16_t_u_s(
                                (g_5[0].f2 &
                                 (((safe_lshift_func_uint8_t_u_s(
                                       ((p_52 = p_51.f5) ^
                                        ((safe_rshift_func_int8_t_s_s(
                                             ((safe_add_func_uint32_t_u_u(
                                                  (safe_mul_func_uint8_t_u_u(
                                                      ((safe_lshift_func_int16_t_s_u(
                                                           l_661, 1)) ||
                                                       ((safe_sub_func_int32_t_s_s(
                                                            g_28.f4,
                                                            ((p_51.f6,
                                                              ((g_470 =
                                                                    ((g_580 =
                                                                          255UL) >
                                                                     g_290
                                                                         .f6)) ||
                                                               g_467)),
                                                             0x99A700AFL))) <=
                                                        6L)),
                                                      l_678)),
                                                  g_290.f4)) ^
                                              g_5[0].f1),
                                             6)) &
                                         0x77L)),
                                       l_707[2][2])) == 253UL) |
                                  g_22)),
                                9)))))) &
                     l_689[8]);
                return p_51.f0;
              }
            }
          }
          {
            l_602--;
            g_76[2][0][9] = g_76[3][3][5];
          }

          if (p_51.f3)

          {
            {
              return l_608;
            }
          }

          for (g_468 = 0; (g_468 < 26);
               g_468 = safe_add_func_int8_t_s_s(g_468, 6)) {
            uint32_t l_631 = 0x0565A3F9L;
            g_374 =
                (((+p_51.f6) &
                  (+(safe_rshift_func_uint16_t_u_u(
                      0UL,
                      (((safe_unary_minus_func_int8_t_s((
                            g_5[0].f6 <=
                            ((((l_621 &&
                                (p_52 =
                                     ((safe_rshift_func_int8_t_s_s(
                                          g_17[5],
                                          (l_631 =
                                               ((safe_unary_minus_func_uint8_t_u((~(
                                                    (safe_rshift_func_uint16_t_u_s(
                                                        g_472[0]
                                                             [0]
                                                             [5],
                                                        12)) ||
                                                    (safe_unary_minus_func_int8_t_s(
                                                        (((0UL <= g_290.f3) ^
                                                          ((((safe_sub_func_uint32_t_u_u(
                                                                 (((0x36B184AAL |
                                                                    4294967295UL),
                                                                   g_447) ==
                                                                  (-9L)),
                                                                 g_290.f2)) <
                                                             g_17[5]) ==
                                                            l_630) == 249UL)) <
                                                         p_51.f4))))))),
                                                0xCFL)))) < l_621))),
                               g_5[0]),
                              p_51.f4) != g_28.f4)))) &
                        l_609) >= g_28.f2))))) != p_51.f5);
            l_662 ^= (safe_sub_func_uint8_t_u_u(
                (safe_lshift_func_int16_t_s_u(l_630, 3)),
                (((safe_lshift_func_int16_t_s_u(
                      ((safe_rshift_func_uint16_t_u_s(p_50, 10)), p_53), 5)) <
                  g_415[0][0].f2) ==
                 (safe_add_func_uint16_t_u_u(
                     (((((safe_sub_func_int32_t_s_s(
                             (l_661 = (safe_mul_func_int16_t_s_s(
                                  0x1200L,
                                  (safe_mod_func_int8_t_s_s(
                                      (((safe_mul_func_uint8_t_u_u(
                                            ((safe_lshift_func_int8_t_s_u(
                                                 (l_660 =
                                                      ((safe_mod_func_uint8_t_u_u(
                                                           (g_415[0][0].f2 ||
                                                            ((l_609 = (safe_mod_func_int8_t_s_s(
                                                                  l_631,
                                                                  (0x3FC2L ||
                                                                   (safe_mul_func_uint16_t_u_u(
                                                                       (2L ==
                                                                        l_658),
                                                                       l_599)))))) >=
                                                             p_51.f2)),
                                                           g_449)) <
                                                       l_659[1][3][3])),
                                                 g_22)),
                                             255UL),
                                            (-1L))) >= g_580) &
                                       255UL),
                                      7UL))))),
                             1UL)) >= l_621) >= p_51.f1) &
                       (-1L)) &
                      2UL),
                     p_52)))));
            if (g_290.f2) break;
            l_663 = g_76[2][0][9];
          }
        }
      }
      for (p_53 = 0; (p_53 > 8); ++p_53) {
        return l_608;
      }

    } else {
      struct S2 l_729 = {5L, 0xDEL, 0x44A6L, 0xC50B85CCL, 1L, 0x4F1FL, 0xDD3CL};

      {
        struct S2 l_729 = {5L, 0xDEL, 0x44A6L, 0xC50B85CCL,
                           1L, 0x4F1FL, 0xDD3CL};
        l_730 = l_729;
      }
    }
    {
      l_602--;
      g_76[2][0][9] = g_76[3][3][5];
    }

    {
      struct S2 l_729 = {5L, 0xDEL, 0x44A6L, 0xC50B85CCL, 1L, 0x4F1FL, 0xDD3CL};
      l_730 = l_729;
    }
  }
  g_467
    =
    ((safe_mul_func_uint16_t_u_u (p_49, (((safe_unary_minus_func_uint32_t_u (((g_76[2][0][9].f6 |= (g_28.f6 |= (safe_add_func_uint8_t_u_u (((((safe_rshift_func_uint16_t_u_u ((safe_lshift_func_int16_t_s_s ((p_51.f5 && (((l_601 = ((safe_mul_func_uint16_t_u_u (((safe_mul_func_uint8_t_u_u ((safe_add_func_uint16_t_u_u (1UL, ((g_415[0][0], (((((((safe_add_func_int8_t_s_s (g_415[0][0].f3, ((g_449 = (~((((g_16 ^ g_181) & p_51.f2) < (p_50 = ((safe_add_func_uint32_t_u_u (((safe_mod_func_uint8_t_u_u ((0xFB361449L <= g_584), l_602)) && g_380[1][1]), 0x3DA468F6L)) || g_472[1][1][4]))) <= g_368[2]))) || (-1L)))) ^ 0xADL) | g_584) | 2L) != 4294967295UL), l_764[3]), l_764[4])), 0x5364L))), g_290.f2)) != l_765), l_764[3].f0)), p_51.f6)), l_601) && l_689[0])), 0)), 13)) <= l_764[3].f5) < g_28.f1) < 0x88L), g_415[0][0].f2)))) || (-5L)))), l_599) != l_764[3].f0))) != 1L);
  return g_22;
}

static uint8_t func_54(uint8_t p_55, int32_t p_56, uint8_t p_57, int16_t p_58,
                       int8_t p_59) {
  uint32_t l_585 = 0x5F364F09L;
  return l_585;
}

static uint8_t func_61(struct S0 p_62) {
  g_181 &= 4L;
  return p_62.f1;
}

static int16_t func_67(int8_t p_68, struct S0 p_69, uint32_t p_70,
                       struct S0 p_71, int32_t p_72) {
  struct S2 l_75 = {-4L, 0x0DL, 0xC7D6L, 0x12DD267AL, 0xBDFEL, -1L, 0UL};
  uint16_t l_114 = 0xE0D8L;
  int32_t l_121 = (-9L);
  int16_t l_129 = 0L;
  struct S1 l_347 = {0xF5L, 0xDEBA183DL, 0UL, 4294967295UL, 0x4138L, -1L};
  uint8_t l_350 = 0x51L;
  int32_t l_361 = 1L;
  struct S2 l_445 = {0xE9724E1EL, 1UL, -2L, 0x25985E8BL, 0L, -7L, 1UL};
  int32_t l_448 = 0L;
  g_76[2][0][9] = l_75;
  g_76[1][0][7] = l_75;
  for (p_69.f6 = 24; (p_69.f6 > 26); p_69.f6++) {
    uint16_t l_107[5][8][6] = {
        {{0xB528L, 0xF467L, 65535UL, 0UL, 65535UL, 3UL},
         {1UL, 3UL, 0xAE1DL, 1UL, 0x2B1CL, 1UL},
         {65535UL, 0x9BD9L, 65535UL, 65535UL, 1UL, 0x259AL},
         {0xAE1DL, 3UL, 1UL, 0x47AEL, 65535UL, 0x62C9L},
         {65535UL, 0xF467L, 0xB528L, 0x47AEL, 0x1E74L, 65535UL},
         {0xAE1DL, 0UL, 0x7936L, 65535UL, 0x7936L, 0UL},
         {65535UL, 1UL, 0UL, 1UL, 65535UL, 65535UL},
         {1UL, 1UL, 0x9B28L, 0UL, 65535UL, 0x62C9L}},
        {{0xB528L, 1UL, 7UL, 3UL, 65535UL, 0x62C9L},
         {1UL, 0x9BD9L, 65535UL, 0x9BD9L, 1UL, 0UL},
         {7UL, 0xF467L, 9UL, 3UL, 0UL, 0x259AL},
         {65535UL, 65535UL, 65526UL, 0xF467L, 65535UL, 0x259AL},
         {65535UL, 0x259AL, 9UL, 0UL, 0x1E74L, 0UL},
         {65535UL, 65534UL, 65535UL, 1UL, 6UL, 0x62C9L},
         {9UL, 0x259AL, 65535UL, 1UL, 4UL, 0x47AEL},
         {65526UL, 65535UL, 65535UL, 1UL, 0x7936L, 1UL}},
        {{9UL, 0xF467L, 7UL, 1UL, 7UL, 0xF467L},
         {65535UL, 0x9BD9L, 1UL, 0UL, 65526UL, 1UL},
         {65535UL, 0UL, 65535UL, 0xF467L, 0xB528L, 0x47AEL},
         {65535UL, 0UL, 65535UL, 3UL, 65526UL, 0x62C9L},
         {7UL, 0x9BD9L, 4UL, 0x9BD9L, 7UL, 0UL},
         {1UL, 0xF467L, 3UL, 3UL, 0x7936L, 0x259AL},
         {65535UL, 65535UL, 65535UL, 0xF467L, 4UL, 0x259AL},
         {65535UL, 0x259AL, 3UL, 0UL, 6UL, 0UL}},
        {{4UL, 65534UL, 4UL, 1UL, 0x1E74L, 0x62C9L},
         {3UL, 0x259AL, 65535UL, 1UL, 65535UL, 0x47AEL},
         {65535UL, 65535UL, 65535UL, 1UL, 0UL, 1UL},
         {3UL, 0xF467L, 1UL, 1UL, 1UL, 0xF467L},
         {4UL, 0x9BD9L, 7UL, 0UL, 65535UL, 1UL},
         {65535UL, 0UL, 65535UL, 0xF467L, 0x9B28L, 0x47AEL},
         {65535UL, 0UL, 65535UL, 3UL, 65535UL, 0x62C9L},
         {1UL, 0x9BD9L, 65535UL, 0x9BD9L, 1UL, 0UL}},
        {{7UL, 0xF467L, 9UL, 3UL, 0UL, 0x259AL},
         {65535UL, 65535UL, 65526UL, 0xF467L, 65535UL, 0x259AL},
         {65535UL, 0x259AL, 9UL, 0UL, 0x1E74L, 0UL},
         {65535UL, 65534UL, 65535UL, 1UL, 6UL, 0x62C9L},
         {9UL, 0x259AL, 65535UL, 1UL, 4UL, 0x47AEL},
         {65526UL, 65535UL, 65535UL, 1UL, 0x7936L, 1UL},
         {9UL, 0xF467L, 7UL, 1UL, 7UL, 0xF467L},
         {65535UL, 0x9BD9L, 1UL, 0UL, 65526UL, 1UL}}};
    int16_t l_108 = 9L;
    uint16_t l_109 = 0x030AL;
    int i, j, k;
  }
  g_76[2][0][9] = l_75;

  if ((p_72 = (safe_mul_func_uint16_t_u_u(
           p_71.f1,
           (((safe_mod_func_uint32_t_u_u(g_28.f1,
                                         (0L | (p_69.f3 ^ g_5[0].f3)))) >
             (((p_71.f5,
                (l_114 ^ (safe_add_func_uint16_t_u_u(
                             (+g_28.f4),
                             ((l_121 = (((((safe_rshift_func_uint16_t_u_u(
                                               (safe_mod_func_uint8_t_u_u(
                                                   (l_75.f4, g_22), p_71.f4)),
                                               p_71.f1)) == 0x11C632E4L) ||
                                          p_69.f4) < 0L) &&
                                        1L)) ||
                              0x436A30DAL))))) |
               p_71.f3) ^
              65531UL)) &&
            g_28.f0))))) {
    uint32_t l_126[10][9] = {{1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL},
                             {1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL},
                             {1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL},
                             {1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL},
                             {1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL},
                             {1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL},
                             {1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL},
                             {1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL},
                             {1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL},
                             {1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL}};
    int32_t l_138[1][8][6];
    int32_t l_139 = (-2L);
    int i, j, k;

  } else {
    uint32_t l_161 = 0xBF2BBB11L;
    int32_t l_221 = 0x902A8F9CL;
    int32_t l_222 = (-4L);
    int8_t l_234 = 1L;
    const struct S2 l_240 = {0x242BF8CBL, 253UL, 0x6875L, 0x382D7FBBL,
                             0x95AFL, 0L, 0xB915L};
    const uint8_t l_263 = 0xB3L;
    int16_t l_304 = 0xBCE7L;
    uint8_t l_442 = 0x78L;
    int32_t l_443 = 0xD30C9E96L;
    struct S0 l_479 = {1L, 65534UL, 0xDDF92009L, -3L, 6UL, 1UL, 0x2FE1L};
    for (g_28.f4 = 0; (g_28.f4 <= 23); ++g_28.f4) {
      int32_t l_153[8] = {0x5896D5BFL, 0x5896D5BFL, 0x5896D5BFL, 0x5896D5BFL,
                          0x5896D5BFL, 0x5896D5BFL, 0x5896D5BFL, 0x5896D5BFL};
      int32_t l_238 = 0x409EA005L;
      struct S2 l_291 = {-9L, 0xD6L, 0x6D53L, 0UL, 0x226DL, 0xEE6DL, 65535UL};
      int8_t l_375 = 0L;
      int16_t l_578 = (-2L);
      int i;
      if (p_69.f3) {
        return g_76[2][0][9].f0;
      } else {
      }
      {
        uint16_t l_107[5][8][6] = {
            {{0xB528L, 0xF467L, 65535UL, 0UL, 65535UL, 3UL},
             {1UL, 3UL, 0xAE1DL, 1UL, 0x2B1CL, 1UL},
             {65535UL, 0x9BD9L, 65535UL, 65535UL, 1UL, 0x259AL},
             {0xAE1DL, 3UL, 1UL, 0x47AEL, 65535UL, 0x62C9L},
             {65535UL, 0xF467L, 0xB528L, 0x47AEL, 0x1E74L, 65535UL},
             {0xAE1DL, 0UL, 0x7936L, 65535UL, 0x7936L, 0UL},
             {65535UL, 1UL, 0UL, 1UL, 65535UL, 65535UL},
             {1UL, 1UL, 0x9B28L, 0UL, 65535UL, 0x62C9L}},
            {{0xB528L, 1UL, 7UL, 3UL, 65535UL, 0x62C9L},
             {1UL, 0x9BD9L, 65535UL, 0x9BD9L, 1UL, 0UL},
             {7UL, 0xF467L, 9UL, 3UL, 0UL, 0x259AL},
             {65535UL, 65535UL, 65526UL, 0xF467L, 65535UL, 0x259AL},
             {65535UL, 0x259AL, 9UL, 0UL, 0x1E74L, 0UL},
             {65535UL, 65534UL, 65535UL, 1UL, 6UL, 0x62C9L},
             {9UL, 0x259AL, 65535UL, 1UL, 4UL, 0x47AEL},
             {65526UL, 65535UL, 65535UL, 1UL, 0x7936L, 1UL}},
            {{9UL, 0xF467L, 7UL, 1UL, 7UL, 0xF467L},
             {65535UL, 0x9BD9L, 1UL, 0UL, 65526UL, 1UL},
             {65535UL, 0UL, 65535UL, 0xF467L, 0xB528L, 0x47AEL},
             {65535UL, 0UL, 65535UL, 3UL, 65526UL, 0x62C9L},
             {7UL, 0x9BD9L, 4UL, 0x9BD9L, 7UL, 0UL},
             {1UL, 0xF467L, 3UL, 3UL, 0x7936L, 0x259AL},
             {65535UL, 65535UL, 65535UL, 0xF467L, 4UL, 0x259AL},
             {65535UL, 0x259AL, 3UL, 0UL, 6UL, 0UL}},
            {{4UL, 65534UL, 4UL, 1UL, 0x1E74L, 0x62C9L},
             {3UL, 0x259AL, 65535UL, 1UL, 65535UL, 0x47AEL},
             {65535UL, 65535UL, 65535UL, 1UL, 0UL, 1UL},
             {3UL, 0xF467L, 1UL, 1UL, 1UL, 0xF467L},
             {4UL, 0x9BD9L, 7UL, 0UL, 65535UL, 1UL},
             {65535UL, 0UL, 65535UL, 0xF467L, 0x9B28L, 0x47AEL},
             {65535UL, 0UL, 65535UL, 3UL, 65535UL, 0x62C9L},
             {1UL, 0x9BD9L, 65535UL, 0x9BD9L, 1UL, 0UL}},
            {{7UL, 0xF467L, 9UL, 3UL, 0UL, 0x259AL},
             {65535UL, 65535UL, 65526UL, 0xF467L, 65535UL, 0x259AL},
             {65535UL, 0x259AL, 9UL, 0UL, 0x1E74L, 0UL},
             {65535UL, 65534UL, 65535UL, 1UL, 6UL, 0x62C9L},
             {9UL, 0x259AL, 65535UL, 1UL, 4UL, 0x47AEL},
             {65526UL, 65535UL, 65535UL, 1UL, 0x7936L, 1UL},
             {9UL, 0xF467L, 7UL, 1UL, 7UL, 0xF467L},
             {65535UL, 0x9BD9L, 1UL, 0UL, 65526UL, 1UL}}};
        int16_t l_108 = 9L;
        uint16_t l_109 = 0x030AL;
        int i, j, k;
    l_109
      |=
      ((((safe_mul_func_uint16_t_u_u (0xCA7BL, (safe_lshift_func_uint16_t_u_u (func_83 ((p_68 = (g_76[1][3][2], (+(safe_lshift_func_uint16_t_u_s ((safe_add_func_int32_t_s_s ((safe_rshift_func_uint8_t_u_s ((safe_add_func_int16_t_s_s (((((0x8701C1B6L == (safe_add_func_int16_t_s_s (((safe_lshift_func_int16_t_s_s (((g_17[5] = (g_28.f1 <= (safe_add_func_uint32_t_u_u (((safe_sub_func_int32_t_s_s (1L, (safe_lshift_func_int16_t_s_u ((safe_rshift_func_uint8_t_u_u (0x5DL, ((((p_69.f5 >= (g_28.f6 = (((p_72 ^= (safe_mod_func_uint32_t_u_u (((g_28.f2 || ((0x6B95L < g_76[2][0][9].f3) | p_68)) < l_107[2][2][5]), 0x6DA58D7DL))) ^ l_75.f5) ^ 0xA032275AL))) | l_107[3][6][2]) < p_69.f3) || g_5[0].f2))), 1)))) <= g_76[2][0][9].f6), g_28.f1)))) | 0x65F83DE7L), p_71.f1)) < g_5[0].f2), g_76[2][0][9].f5))), 0x29863923L) == l_108) != 0x10L), l_107[2][2][5])), l_107[2][2][5])), l_75.f4)), 1)))))), 13)))) || 0x6BL), p_69.f5), p_69.f6);
      }

      for (p_71.f5 = 0; (p_71.f5 <= 7); p_71.f5 += 1) {
        int32_t l_239[2][10][1];
        int i, j, k;
        for (i = 0; i < 2; i++) {
          for (j = 0; j < 10; j++) {
            for (k = 0; k < 1; k++)
              ;

            for (i = 0; i < 2; i++) {
              for (j = 0; j < 10; j++) {
                for (k = 0; k < 1; k++) l_239[i][j][k] = 3L;
              }
            }
          }
        }

        { return g_76[2][0][9].f0; }

        g_76[2][0][9] = l_75;

        g_162 = (safe_mod_func_uint8_t_u_u(
            (g_76[2][0][9].f4 && (((-1L) >= g_5[0].f4) & (g_17[5]--))),
            (safe_sub_func_uint16_t_u_u(
                (g_28.f1 != 6UL),
                ((safe_sub_func_uint32_t_u_u(
                     l_114,
                     ((l_121 = ((safe_sub_func_int8_t_s_s(
                                    (safe_sub_func_int8_t_s_s(
                                        (safe_lshift_func_uint16_t_u_u(
                                            (((safe_rshift_func_uint8_t_u_s(
                                                  (0L & (g_159 = ((p_69.f4--) |
                                                                  g_28.f2))),
                                                  (p_68, g_28.f4))) >=
                                              l_153[3]) >= g_181),
                                            1)),
                                        4UL)),
                                    g_5[0].f0)) &&
                                65535UL)) ||
                      0L))) <= (-1L))))));
        {
          for (j = 0; j < 10; j++) {
            for (k = 0; k < 1; k++) l_239[i][j][k] = 3L;
          }
        }
      }
      for (p_71.f5 = 0; (p_71.f5 <= 7); p_71.f5 += 1) {
        int32_t l_239[2][10][1];
        int i, j, k;
        for (i = 0; i < 2; i++) {
          for (j = 0; j < 10; j++) {
            for (k = 0; k < 1; k++) l_239[i][j][k] = 3L;
          }
        }
        p_72 |= 0x21426223L;
        g_162 =
            (((1L |
               ((safe_add_func_uint8_t_u_u(
                    (g_17[p_71.f5] && (safe_lshift_func_int16_t_s_s(0L, 13))),
                    ((((g_5[0].f0 | l_153[3]) >=
                       (((-1L) <=
                         (((p_71.f3 >=
                            ((g_160 = (safe_mul_func_int8_t_s_s(
                                  (g_159 = (p_71.f6 &
                                            ((safe_unary_minus_func_int8_t_s(
                                                 (safe_sub_func_uint16_t_u_u(
                                                     0xA417L, p_69.f4)))) !=
                                             4294967295UL))),
                                  g_5[0].f1))) &&
                             0x79318AA5L)) == l_75.f1) != p_70)) <= l_161)) ==
                      g_28.f4) ^
                     65535UL))) &&
                9UL)) |
              (-1L)) == 0x1146L);
        g_162 = (safe_mod_func_uint8_t_u_u(
            (g_76[2][0][9].f4 && (((-1L) >= g_5[0].f4) & (g_17[5]--))),
            (safe_sub_func_uint16_t_u_u(
                (g_28.f1 != 6UL),
                ((safe_sub_func_uint32_t_u_u(
                     l_114,
                     ((l_121 = ((safe_sub_func_int8_t_s_s(
                                    (safe_sub_func_int8_t_s_s(
                                        (safe_lshift_func_uint16_t_u_u(
                                            (((safe_rshift_func_uint8_t_u_s(
                                                  (0L & (g_159 = ((p_69.f4--) |
                                                                  g_28.f2))),
                                                  (p_68, g_28.f4))) >=
                                              l_153[3]) >= g_181),
                                            1)),
                                        4UL)),
                                    g_5[0].f0)) &&
                                65535UL)) ||
                      0L))) <= (-1L))))));
        for (p_69.f5 = 0; (p_69.f5 <= 3); p_69.f5 += 1) {
          int i, j, k;
          p_72 =
              (((safe_mod_func_uint16_t_u_u(
                    (g_76[(p_69.f5 + 1)][p_69.f5][(p_71.f5 + 2)], 0x81A0L),
                    2UL)) ||
                (((g_76[2][0][9].f5 |= (safe_lshift_func_uint16_t_u_s(
                       (((g_5[0],
                          ((g_5[0].f2 >= g_76[2][0][9].f2) ==
                           (safe_mul_func_uint8_t_u_u(
                               (~((((((safe_rshift_func_uint16_t_u_u(1UL, 15)) &
                                      g_28.f5) ||
                                     p_69.f1) <= 0x56CFA103L) &&
                                   0x5540F05BL) ||
                                  2UL)),
                               l_153[3])))),
                         g_17[p_71.f5]) == 0x8EL),
                       g_17[p_71.f5]))) |
                  l_161),
                 l_153[2])) != p_69.f3);
          for (p_71.f0 = 3; (p_71.f0 >= 0); p_71.f0 -= 1) {
            int32_t l_206 = 1L;
            int32_t l_219 = 0xB5C4B602L;
            int32_t l_220[2][3][1];
            int i, j, k;
            for (i = 0; i < 2; i++) {
              for (j = 0; j < 3; j++) {
                for (k = 0; k < 1; k++) l_220[i][j][k] = 1L;
              }
            }
     l_221
       ^=
       (p_69.
        f4
        |
        (((safe_mul_func_uint16_t_u_u ((((safe_mod_func_uint8_t_u_u ((((((g_76[2][0][9].f3 = (g_17[p_71.f5], (((safe_lshift_func_uint8_t_u_s (((safe_mod_func_int32_t_s_s ((((safe_rshift_func_int16_t_s_s ((+((safe_mod_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u (((safe_sub_func_uint16_t_u_u (p_71.f5, (++p_71.f6))), (safe_lshift_func_int8_t_s_u ((l_220[0][0][0] = (safe_rshift_func_int16_t_s_s ((g_28.f5 = (p_68 == (safe_mod_func_int32_t_s_s (((g_146 >= (0x545CL ^ g_17[0])) == (safe_rshift_func_int16_t_s_u ((((((((safe_sub_func_int16_t_s_s ((g_28.f2 = (l_219 |= l_153[3])), (g_28.f0 & g_28.f6))) <= l_206) || p_71.f0) >= (-1L)) && p_71.f2) != g_17[p_71.f5]) < g_17[5]), 4))), p_69.f4)))), p_69.f1))), 1))), 6)), g_17[5])) == l_161)), g_76[2][0][9].f0)), g_159) && g_5[0].f2), 0x381081BDL)), p_71.f4), g_76[(p_69.f5 + 1)][p_69.f5][(p_71.f5 + 2)].f1)) <= 0xF889L) <= p_68))), g_76[(p_69.f5 + 1)][p_69.f5][(p_71.f5 + 2)].f6) || g_146) && g_76[(p_69.f5 + 1)][p_69.f5][(p_71.f5 + 2)].f5) > l_75.f4), g_17[5])) == g_76[2][0][9].f0) == g_16), l_161)) == 1UL) == 0xABD0L));
     ++g_223;
     l_239[1][1][0] |= (~(safe_sub_func_int16_t_s_s(
         (((-1L) <=
           ((safe_lshift_func_int8_t_s_u(
                (((safe_add_func_uint8_t_u_u(
                      (safe_mod_func_int8_t_s_s(
                          (g_76[2][0][9].f4 !=
                           (l_234,
                            (l_238 = ((safe_unary_minus_func_uint16_t_u(
                                          (p_69.f5 >
                                           ((((safe_add_func_uint16_t_u_u(
                                                  (p_69.f4, p_72),
                                                  (l_153[3] ^=
                                                   ((65530UL <=
                                                     ((g_17[5] ==
                                                       (g_159 && 0x0606D169L)) <
                                                      0xE94AL)) >
                                                    g_5[0].f3)))) != 0UL),
                                             0xE75EL) < g_223)))) ||
                                      p_71.f6)))),
                          0xC5L)),
                      g_16)) &&
                  l_238) |
                 252UL),
                g_160)) &&
            p_71.f5)) < 255UL),
         p_71.f3)));
     g_76[(p_69.f5 + 1)][p_71.f0][(p_69.f5 + 3)] = l_240;
          }
          if ((safe_mul_func_uint16_t_u_u(
                  (!l_129),
                  ((safe_lshift_func_uint16_t_u_u(
                       (safe_mul_func_uint8_t_u_u(
                           (((0L >=
                              (safe_lshift_func_uint8_t_u_s(
                                  (safe_mul_func_uint8_t_u_u(4UL, l_153[6])),
                                  (safe_rshift_func_int16_t_s_u(
                                      ((g_28.f1,
                                        (safe_mul_func_uint8_t_u_u(
                                            g_17[p_71.f5],
                                            (safe_lshift_func_int8_t_s_u(
                                                (((l_121 |=
                                                   (((safe_lshift_func_uint16_t_u_s(
                                                         ((safe_sub_func_int8_t_s_s(
                                                              (((safe_lshift_func_uint16_t_u_u(
                                                                    (((((0x75L &
                                                                         (1L <
                                                                          p_71.f0)) !=
                                                                        g_17[4]) &&
                                                                       4294967294UL) >=
                                                                      g_76[(
                                                                          p_69.f5 +
                                                                          1)]
                                                                          [p_69.f5]
                                                                          [(p_71.f5 +
                                                                            2)]
                                                                              .f1) ||
                                                                     l_263),
                                                                    g_5[0]
                                                                        .f2)) &
                                                                65534UL) |
                                                               0L),
                                                              l_75.f6)) ^
                                                          g_76[2][0][9].f3),
                                                         2)) &
                                                     l_240.f4) >= p_71.f2)),
                                                  2L) <= p_71.f1),
                                                g_76[(p_69.f5 + 1)][p_69.f5]
                                                    [(p_71.f5 + 2)]
                                                        .f2))))) &
                                       g_5[0].f3),
                                      l_222))))) <= g_160) ||
                            g_160),
                           l_153[3])),
                       p_71.f4)) >= g_162)))) {
            uint8_t l_289 = 1UL;
            g_290 =
                (((safe_sub_func_int32_t_s_s(
                      (safe_unary_minus_func_uint32_t_u(
                          ((safe_lshift_func_uint8_t_u_u(g_223, 4)) |
                           (l_240.f3, 0L)))),
                      p_69.f3)) ||
                  ((((safe_add_func_uint16_t_u_u(
                         l_240.f6,
                         ((~((p_69.f6 ^=
                              (l_161 ||
                               (((safe_mod_func_int8_t_s_s(
                                     (safe_rshift_func_uint8_t_u_u(
                                         (safe_add_func_int16_t_s_s(
                                             (g_76[2][0][9].f4 = (~(
                                                  l_289 = (safe_rshift_func_int16_t_s_u(
                                                      (safe_add_func_int8_t_s_s(
                                                          (((safe_mod_func_uint8_t_u_u(
                                                                (g_76[2][0][9]
                                                                     .f1 = (safe_mul_func_int8_t_s_s(
                                                                     ((((g_17[2] >=
                                                                         (g_76[2]
                                                                              [0]
                                                                              [9]
                                                                                  .f5 =
                                                                              (g_76[2]
                                                                                   [0]
                                                                                   [9]
                                                                                       .f0 >
                                                                               ((safe_mod_func_int32_t_s_s(
                                                                                    p_72,
                                                                                    0x1E61F330L)),
                                                                                g_76[(
                                                                                    p_69.f5 +
                                                                                    1)]
                                                                                    [p_69.f5]
                                                                                    [(p_71.f5 +
                                                                                      2)]
                                                                                        .f6)))) >
                                                                        (-8L)) |
                                                                       (-7L)) <
                                                                      g_223),
                                                                     l_75.f0))),
                                                                0xA3L)) &&
                                                            l_239[1][1][0]) ==
                                                           g_76[2][0][9].f4),
                                                          g_146)),
                                                      13))))),
                                             0xF185L)),
                                         g_160)),
                                     l_222)) == 0x3D34L) != p_69.f1))) ==
                             3UL)) < p_69.f5))),
                     g_290),
                    l_75.f0) |
                   0UL)),
                 l_291);
            return g_76[(p_69.f5 + 1)][p_69.f5][(p_71.f5 + 2)].f1;
          } else {
            return g_160;
          }
        }
      }

      { --g_146; }

      if ((safe_add_func_int16_t_s_s ((((safe_lshift_func_uint16_t_u_s ((l_238 = (safe_rshift_func_int8_t_s_u (((g_181 &= ((((((((((((((g_5[0], ((safe_lshift_func_int16_t_s_u ((safe_sub_func_int32_t_s_s (((p_71.f6 ^ (g_146 && (l_75.f2 <= ((l_222 = (safe_unary_minus_func_int16_t_s ((l_238 || (safe_sub_func_uint8_t_u_u (((!((safe_mod_func_uint8_t_u_u (l_75.f2, l_75.f6)) ^ ((p_69.f6, (safe_rshift_func_uint8_t_u_s ((safe_sub_func_uint16_t_u_u (((safe_sub_func_int16_t_s_s ((l_153[6] = (g_76[2][0][9].f2 > p_72)), (-2L))) != 255UL), 0L)), l_234))), 4UL))) <= l_240.f1), 0x63L)))))) == l_240.f5)))) & g_76[2][0][9].f4), 0UL)), 11)) | 0xC5DCL)) != g_290.f3) == p_71.f5) <= g_290.f6) | g_146) && p_71.f1), 0xC07887B8L), p_71.f4), 0xDF5171D4L) || l_240.f0) || g_76[2][0][9].f5) | l_75.f2) | p_71.f2) <= 0x548190C9L)) || g_290.f0), 4))), l_263)), p_71.f2) & p_69.f2), l_291.f5)))
      {
        int8_t l_360 = 0x34L;
        int32_t l_363[2];
        uint16_t l_365 = 65535UL;
        struct S1 l_391 = {0xEEL, 0x3E62D634L, 65530UL,
                           4294967288UL, 0xDC51L, 1L};
        struct S2 l_446 = {4L, 0x98L, -1L, 0xD4ABB65AL,
                           0x1EE8L, 0x26FBL, 65534UL};
        int i;
        for (i = 0; i < 2; i++)

        {
          for (g_290.f3 = 0; (g_290.f3 == 46); g_290.f3++) {
            int16_t l_309 = 0xAFFFL;
            g_162 &=
                (l_121 ^= (safe_rshift_func_int16_t_s_u(
                     (safe_mod_func_uint32_t_u_u(
                         ((safe_lshift_func_int16_t_s_u(
                              (safe_lshift_func_int16_t_s_u((p_70 != p_72),
                                                            g_28.f6)),
                              0)) >= 0xD4L),
                         l_240.f0)),
                     (((((((((((((safe_add_func_uint16_t_u_u(
                                     (l_304, (safe_mul_func_uint16_t_u_u(
                                                 (safe_rshift_func_uint8_t_u_u(
                                                     0xABL, (p_69.f2 < p_70))),
                                                 8UL))),
                                     l_291.f2)) <= 0xA27AL) != l_309) !=
                               l_240.f5),
                              l_309) ^
                             0x90EE6CEDL) &&
                            p_69.f5),
                           p_71),
                          0xA1L) &&
                         l_222) |
                        1UL) == l_75.f5) <= 247UL))));
          }
        }

        g_76[1][0][7] = l_75;

        g_181 = 7L;
        if (p_69.f3) {
          return g_76[2][0][9].f0;
        } else {
          --g_146;
        }

      } else {
        int32_t l_471 = 0x56BBDED5L;
        int16_t l_509 = 3L;
        struct S2 l_528 = {0x1D178339L, 0xF6L, 0x908DL, 1UL,
                           1L, 0xE1C2L, 65534UL};
        int32_t l_529 = 0xF0301CE7L;
        for (g_28.f0 = 5; (g_28.f0 >= 2); g_28.f0 -= 1) {
          int32_t l_466 = 0xBCF2F5A1L;
          int32_t l_469 = 0x16C547C9L;
          int i;
          ++g_472[0][0][4];
          for (g_223 = 0; (g_223 <= 2); g_223 += 1) {
            int i, j;
            l_153[6] = g_380[g_223][g_223];
          }
        }
        if (g_368[2]) {
          int16_t l_512[1][7] = {
              {0xF5BBL, 0x4C73L, 0x4C73L, 0xF5BBL, 0x4C73L, 0x4C73L, 0xF5BBL}};
          int32_t l_554 = 5L;
          int32_t l_555 = 0x27A58C53L;
          int32_t l_576 = 0x7AFC8810L;
          int i, j;

          for (g_290.f3 = 0; (g_290.f3 == 46); g_290.f3++) {
            int16_t l_309 = 0xAFFFL;
            g_162 &=
                (l_121 ^= (safe_rshift_func_int16_t_s_u(
                     (safe_mod_func_uint32_t_u_u(
                         ((safe_lshift_func_int16_t_s_u(
                              (safe_lshift_func_int16_t_s_u((p_70 != p_72),
                                                            g_28.f6)),
                              0)) >= 0xD4L),
                         l_240.f0)),
                     (((((((((((((safe_add_func_uint16_t_u_u(
                                     (l_304, (safe_mul_func_uint16_t_u_u(
                                                 (safe_rshift_func_uint8_t_u_u(
                                                     0xABL, (p_69.f2 < p_70))),
                                                 8UL))),
                                     l_291.f2)) <= 0xA27AL) != l_309) !=
                               l_240.f5),
                              l_309) ^
                             0x90EE6CEDL) &&
                            p_69.f5),
                           p_71),
                          0xA1L) &&
                         l_222) |
                        1UL) == l_75.f5) <= 247UL))));
          }

          for (p_71.f5 = 0; (p_71.f5 <= 7); p_71.f5 += 1) {
            int32_t l_239[2][10][1];
            int i, j, k;
            for (i = 0; i < 2; i++) {
              for (j = 0; j < 10; j++) {
                for (k = 0; k < 1; k++) l_239[i][j][k] = 3L;
              }
            }
            p_72 |= 0x21426223L;
            g_162 =
                (((1L |
                   ((safe_add_func_uint8_t_u_u(
                        (g_17[p_71.f5] &&
                         (safe_lshift_func_int16_t_s_s(0L, 13))),
                        ((((g_5[0].f0 | l_153[3]) >=
                           (((-1L) <=
                             (((p_71.f3 >=
                                ((g_160 = (safe_mul_func_int8_t_s_s(
                                      (g_159 =
                                           (p_71.f6 &
                                            ((safe_unary_minus_func_int8_t_s(
                                                 (safe_sub_func_uint16_t_u_u(
                                                     0xA417L, p_69.f4)))) !=
                                             4294967295UL))),
                                      g_5[0].f1))) &&
                                 0x79318AA5L)) == l_75.f1) != p_70)) <=
                            l_161)) == g_28.f4) ^
                         65535UL))) &&
                    9UL)) |
                  (-1L)) == 0x1146L);
            g_162 = (safe_mod_func_uint8_t_u_u(
                (g_76[2][0][9].f4 && (((-1L) >= g_5[0].f4) & (g_17[5]--))),
                (safe_sub_func_uint16_t_u_u(
                    (g_28.f1 != 6UL),
                    ((safe_sub_func_uint32_t_u_u(
                         l_114,
                         ((l_121 =
                               ((safe_sub_func_int8_t_s_s(
                                    (safe_sub_func_int8_t_s_s(
                                        (safe_lshift_func_uint16_t_u_u(
                                            (((safe_rshift_func_uint8_t_u_s(
                                                  (0L & (g_159 = ((p_69.f4--) |
                                                                  g_28.f2))),
                                                  (p_68, g_28.f4))) >=
                                              l_153[3]) >= g_181),
                                            1)),
                                        4UL)),
                                    g_5[0].f0)) &&
                                65535UL)) ||
                          0L))) <= (-1L))))));
            for (p_69.f5 = 0; (p_69.f5 <= 3); p_69.f5 += 1) {
              int i, j, k;
              p_72 =
                  (((safe_mod_func_uint16_t_u_u(
                        (g_76[(p_69.f5 + 1)][p_69.f5][(p_71.f5 + 2)], 0x81A0L),
                        2UL)) ||
                    (((g_76[2][0][9].f5 |= (safe_lshift_func_uint16_t_u_s(
                           (((g_5[0],
                              ((g_5[0].f2 >= g_76[2][0][9].f2) ==
                               (safe_mul_func_uint8_t_u_u(
                                   (~((((((safe_rshift_func_uint16_t_u_u(1UL,
                                                                         15)) &
                                          g_28.f5) ||
                                         p_69.f1) <= 0x56CFA103L) &&
                                       0x5540F05BL) ||
                                      2UL)),
                                   l_153[3])))),
                             g_17[p_71.f5]) == 0x8EL),
                           g_17[p_71.f5]))) |
                      l_161),
                     l_153[2])) != p_69.f3);
              for (p_71.f0 = 3; (p_71.f0 >= 0); p_71.f0 -= 1) {
                int32_t l_206 = 1L;
                int32_t l_219 = 0xB5C4B602L;
                int32_t l_220[2][3][1];
                int i, j, k;
                for (i = 0; i < 2; i++) {
                  for (j = 0; j < 3; j++) {
                    for (k = 0; k < 1; k++) l_220[i][j][k] = 1L;
                  }
                }
     l_221
       ^=
       (p_69.
        f4
        |
        (((safe_mul_func_uint16_t_u_u ((((safe_mod_func_uint8_t_u_u ((((((g_76[2][0][9].f3 = (g_17[p_71.f5], (((safe_lshift_func_uint8_t_u_s (((safe_mod_func_int32_t_s_s ((((safe_rshift_func_int16_t_s_s ((+((safe_mod_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u (((safe_sub_func_uint16_t_u_u (p_71.f5, (++p_71.f6))), (safe_lshift_func_int8_t_s_u ((l_220[0][0][0] = (safe_rshift_func_int16_t_s_s ((g_28.f5 = (p_68 == (safe_mod_func_int32_t_s_s (((g_146 >= (0x545CL ^ g_17[0])) == (safe_rshift_func_int16_t_s_u ((((((((safe_sub_func_int16_t_s_s ((g_28.f2 = (l_219 |= l_153[3])), (g_28.f0 & g_28.f6))) <= l_206) || p_71.f0) >= (-1L)) && p_71.f2) != g_17[p_71.f5]) < g_17[5]), 4))), p_69.f4)))), p_69.f1))), 1))), 6)), g_17[5])) == l_161)), g_76[2][0][9].f0)), g_159) && g_5[0].f2), 0x381081BDL)), p_71.f4), g_76[(p_69.f5 + 1)][p_69.f5][(p_71.f5 + 2)].f1)) <= 0xF889L) <= p_68))), g_76[(p_69.f5 + 1)][p_69.f5][(p_71.f5 + 2)].f6) || g_146) && g_76[(p_69.f5 + 1)][p_69.f5][(p_71.f5 + 2)].f5) > l_75.f4), g_17[5])) == g_76[2][0][9].f0) == g_16), l_161)) == 1UL) == 0xABD0L));
     ++g_223;
     l_239[1][1][0] |= (~(safe_sub_func_int16_t_s_s(
         (((-1L) <=
           ((safe_lshift_func_int8_t_s_u(
                (((safe_add_func_uint8_t_u_u(
                      (safe_mod_func_int8_t_s_s(
                          (g_76[2][0][9].f4 !=
                           (l_234,
                            (l_238 = ((safe_unary_minus_func_uint16_t_u(
                                          (p_69.f5 >
                                           ((((safe_add_func_uint16_t_u_u(
                                                  (p_69.f4, p_72),
                                                  (l_153[3] ^=
                                                   ((65530UL <=
                                                     ((g_17[5] ==
                                                       (g_159 && 0x0606D169L)) <
                                                      0xE94AL)) >
                                                    g_5[0].f3)))) != 0UL),
                                             0xE75EL) < g_223)))) ||
                                      p_71.f6)))),
                          0xC5L)),
                      g_16)) &&
                  l_238) |
                 252UL),
                g_160)) &&
            p_71.f5)) < 255UL),
         p_71.f3)));
     g_76[(p_69.f5 + 1)][p_71.f0][(p_69.f5 + 3)] = l_240;
              }
              if ((safe_mul_func_uint16_t_u_u(
                      (!l_129),
                      ((safe_lshift_func_uint16_t_u_u(
                           (safe_mul_func_uint8_t_u_u(
                               (((0L >=
                                  (safe_lshift_func_uint8_t_u_s(
                                      (safe_mul_func_uint8_t_u_u(4UL,
                                                                 l_153[6])),
                                      (safe_rshift_func_int16_t_s_u(
                                          ((g_28.f1,
                                            (safe_mul_func_uint8_t_u_u(
                                                g_17[p_71.f5],
                                                (safe_lshift_func_int8_t_s_u(
                                                    (((l_121 |=
                                                       (((safe_lshift_func_uint16_t_u_s(
                                                             ((safe_sub_func_int8_t_s_s(
                                                                  (((safe_lshift_func_uint16_t_u_u(
                                                                        (((((0x75L &
                                                                             (1L <
                                                                              p_71.f0)) !=
                                                                            g_17[4]) &&
                                                                           4294967294UL) >=
                                                                          g_76[(
                                                                              p_69.f5 +
                                                                              1)]
                                                                              [p_69.f5]
                                                                              [(p_71.f5 +
                                                                                2)]
                                                                                  .f1) ||
                                                                         l_263),
                                                                        g_5[0]
                                                                            .f2)) &
                                                                    65534UL) |
                                                                   0L),
                                                                  l_75.f6)) ^
                                                              g_76[2][0][9].f3),
                                                             2)) &
                                                         l_240.f4) >= p_71.f2)),
                                                      2L) <= p_71.f1),
                                                    g_76[(p_69.f5 + 1)][p_69.f5]
                                                        [(p_71.f5 + 2)]
                                                            .f2))))) &
                                           g_5[0].f3),
                                          l_222))))) <= g_160) ||
                                g_160),
                               l_153[3])),
                           p_71.f4)) >= g_162)))) {
                uint8_t l_289 = 1UL;
                g_290 =
                    (((safe_sub_func_int32_t_s_s(
                          (safe_unary_minus_func_uint32_t_u(
                              ((safe_lshift_func_uint8_t_u_u(g_223, 4)) |
                               (l_240.f3, 0L)))),
                          p_69.f3)) ||
                      ((((safe_add_func_uint16_t_u_u(
                             l_240.f6,
                             ((~((p_69.f6 ^=
                                  (l_161 ||
                                   (((safe_mod_func_int8_t_s_s(
                                         (safe_rshift_func_uint8_t_u_u(
                                             (safe_add_func_int16_t_s_s(
                                                 (g_76[2][0][9].f4 = (~(
                                                      l_289 = (safe_rshift_func_int16_t_s_u(
                                                          (safe_add_func_int8_t_s_s(
                                                              (((safe_mod_func_uint8_t_u_u(
                                                                    (g_76[2][0][9]
                                                                         .f1 = (safe_mul_func_int8_t_s_s(
                                                                         ((((g_17[2] >=
                                                                             (g_76[2]
                                                                                  [0]
                                                                                  [9]
                                                                                      .f5 =
                                                                                  (g_76[2]
                                                                                       [0]
                                                                                       [9]
                                                                                           .f0 >
                                                                                   ((safe_mod_func_int32_t_s_s(
                                                                                        p_72,
                                                                                        0x1E61F330L)),
                                                                                    g_76[(
                                                                                        p_69.f5 +
                                                                                        1)]
                                                                                        [p_69.f5]
                                                                                        [(p_71.f5 +
                                                                                          2)]
                                                                                            .f6)))) >
                                                                            (-8L)) |
                                                                           (-7L)) <
                                                                          g_223),
                                                                         l_75.f0))),
                                                                    0xA3L)) &&
                                                                l_239[1][1]
                                                                     [0]) ==
                                                               g_76[2][0][9]
                                                                   .f4),
                                                              g_146)),
                                                          13))))),
                                                 0xF185L)),
                                             g_160)),
                                         l_222)) == 0x3D34L) != p_69.f1))) ==
                                 3UL)) < p_69.f5))),
                         g_290),
                        l_75.f0) |
                       0UL)),
                     l_291);
                return g_76[(p_69.f5 + 1)][p_69.f5][(p_71.f5 + 2)].f1;
              } else {
                return g_160;
              }
            }
          }

        } else {
          int32_t l_577 = 0x4262284AL;
          int32_t l_579[3][10][1] = {{{(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)}},
                                     {{8L},
                                      {8L},
                                      {(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)},
                                      {8L}},
                                     {{8L},
                                      {(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)},
                                      {8L},
                                      {8L}}};
          int i, j, k;
          --g_580;
          {
            int16_t l_512[1][7] = {{0xF5BBL, 0x4C73L, 0x4C73L, 0xF5BBL, 0x4C73L,
                                    0x4C73L, 0xF5BBL}};
            int32_t l_554 = 5L;
            int32_t l_555 = 0x27A58C53L;
            int32_t l_576 = 0x7AFC8810L;
            int i, j;
            if (((safe_lshift_func_int8_t_s_u(p_71.f1, l_512[0][3])),
                 (safe_add_func_int32_t_s_s(
                     ((safe_rshift_func_int8_t_s_s(
                          0x0EL,
                          (((((safe_sub_func_int32_t_s_s(
                                  (safe_rshift_func_uint16_t_u_s(
                                      l_347.f3,
                                      ((l_509 != (g_415[2][2], p_69.f4)) |
                                       (((g_5[0], g_468) != l_238) == l_471)))),
                                  p_69.f3)) <= 4294967290UL) >= g_290.f1),
                            g_28),
                           l_291.f4))) |
                      0x41D8366DL),
                     0xD882FBFCL)))) {
              uint32_t l_521 = 0x1E457E49L;
              l_521--;
            } else {
              return p_68;
            }
            if ((((((((l_347.f1 == (8L < (g_28.f3 != (0x17L != p_69.f0)))) >
                      (safe_add_func_uint16_t_u_u(
                          (((safe_rshift_func_int16_t_s_u(
                                ((l_528,
                                  ((l_529 = (g_76[2][0][9].f0 < 0x039FL)),
                                   (((0x4EL == g_76[2][0][9].f6) == p_71.f3) ^
                                    l_222))) |
                                 g_290.f3),
                                g_28.f3)) &
                            8L) |
                           l_528.f2),
                          0xA133L))) &&
                     p_69.f6) ^
                    g_76[2][0][9].f0) |
                   g_5[0].f6) &
                  l_445.f6) ^
                 p_71.f6)) {
              l_555 &=
                  (0UL ==
                   (((safe_mul_func_int16_t_s_s(
                         ((safe_rshift_func_uint16_t_u_u(g_368[2], 6)),
                          (+(g_290.f2 &= (safe_mod_func_uint16_t_u_u(
                                 g_162,
                                 (safe_sub_func_int16_t_s_s(
                                     (safe_mul_func_int16_t_s_s(
                                         (safe_rshift_func_uint8_t_u_u(
                                             ((((l_448 = 0x19L) >
                                                (safe_lshift_func_uint16_t_u_s(
                                                    (g_159 == (-1L)),
                                                    (safe_mod_func_uint32_t_u_u(
                                                        ((p_71.f6 = (safe_mul_func_uint16_t_u_u(
                                                              (0x6EL <
                                                               (safe_lshift_func_int16_t_s_u(
                                                                   ((+p_69.f4),
                                                                    (l_554 ^=
                                                                     (safe_rshift_func_uint8_t_u_s(
                                                                         (safe_rshift_func_int8_t_s_s(
                                                                             (p_69.f5 >=
                                                                              0x6D250B95L),
                                                                             p_69.f1)),
                                                                         l_528
                                                                             .f3)))),
                                                                   g_28.f4))),
                                                              3L))),
                                                         l_75.f2),
                                                        0x3C6BA643L))))) <=
                                               l_238) >= l_291.f1),
                                             4)),
                                         l_528.f6)),
                                     g_290.f5))))))),
                         p_69.f3)) == 4294967295UL) < l_75.f0));
              g_181 &=
                  ((4UL >
                    ((p_69.f2 & l_471) ||
                     (safe_lshift_func_uint16_t_u_s(
                         (p_69.f4 & ((g_28.f1 &= (p_70 >= g_449)) < 0x6DL)),
                         1)))) ||
                   g_5[0].f3);
            } else {
              struct S2 l_572 = {0xA5B92E3AL, 252UL, 0x1A88L, 4294967291UL,
                                 0x6F78L, 0x8B43L, 0UL};
              int16_t l_575 = 4L;
              g_447 =
                  ((safe_rshift_func_uint8_t_u_u(
                       (safe_mul_func_int16_t_s_s(1L, p_71.f0)), 0)) &
                   (safe_rshift_func_int16_t_s_s(
                       ((safe_lshift_func_int16_t_s_u(
                            ((p_71.f6 =
                                  ((+((safe_sub_func_int16_t_s_s(
                                          (((safe_lshift_func_int16_t_s_u(
                                                ((p_69.f6 !=
                                                  ((safe_mod_func_int32_t_s_s(
                                                       g_76[2][0][9].f3,
                                                       (g_181 & 0x5AL))),
                                                   (g_415[0][0].f5 ^
                                                    ((l_572,
                                                      (safe_add_func_uint32_t_u_u(
                                                          p_70,
                                                          4294967286UL))) !=
                                                     p_71.f4)))) &
                                                 p_71.f3),
                                                p_72)) < 1UL),
                                           l_347.f0),
                                          1UL)) == l_575)) <= p_69.f3)) ||
                             (-1L)),
                            11)) &
                        p_71.f3),
                       g_76[2][0][9].f2)));
              g_76[2][0][9] = g_290;
              g_162 = l_576;
              return p_69.f4;
            }
          }

          g_374 = l_579[0][9][0];
          {
            int16_t l_512[1][7] = {{0xF5BBL, 0x4C73L, 0x4C73L, 0xF5BBL, 0x4C73L,
                                    0x4C73L, 0xF5BBL}};
            int32_t l_554 = 5L;
            int32_t l_555 = 0x27A58C53L;
            int32_t l_576 = 0x7AFC8810L;
            int i, j;
            if (((safe_lshift_func_int8_t_s_u(p_71.f1, l_512[0][3])),
                 (safe_add_func_int32_t_s_s(
                     ((safe_rshift_func_int8_t_s_s(
                          0x0EL,
                          (((((safe_sub_func_int32_t_s_s(
                                  (safe_rshift_func_uint16_t_u_s(
                                      l_347.f3,
                                      ((l_509 != (g_415[2][2], p_69.f4)) |
                                       (((g_5[0], g_468) != l_238) == l_471)))),
                                  p_69.f3)) <= 4294967290UL) >= g_290.f1),
                            g_28),
                           l_291.f4))) |
                      0x41D8366DL),
                     0xD882FBFCL)))) {
              uint32_t l_521 = 0x1E457E49L;
              l_521--;
            } else {
              return p_68;
            }
            if ((((((((l_347.f1 == (8L < (g_28.f3 != (0x17L != p_69.f0)))) >
                      (safe_add_func_uint16_t_u_u(
                          (((safe_rshift_func_int16_t_s_u(
                                ((l_528,
                                  ((l_529 = (g_76[2][0][9].f0 < 0x039FL)),
                                   (((0x4EL == g_76[2][0][9].f6) == p_71.f3) ^
                                    l_222))) |
                                 g_290.f3),
                                g_28.f3)) &
                            8L) |
                           l_528.f2),
                          0xA133L))) &&
                     p_69.f6) ^
                    g_76[2][0][9].f0) |
                   g_5[0].f6) &
                  l_445.f6) ^
                 p_71.f6)) {
              l_555 &=
                  (0UL ==
                   (((safe_mul_func_int16_t_s_s(
                         ((safe_rshift_func_uint16_t_u_u(g_368[2], 6)),
                          (+(g_290.f2 &= (safe_mod_func_uint16_t_u_u(
                                 g_162,
                                 (safe_sub_func_int16_t_s_s(
                                     (safe_mul_func_int16_t_s_s(
                                         (safe_rshift_func_uint8_t_u_u(
                                             ((((l_448 = 0x19L) >
                                                (safe_lshift_func_uint16_t_u_s(
                                                    (g_159 == (-1L)),
                                                    (safe_mod_func_uint32_t_u_u(
                                                        ((p_71.f6 = (safe_mul_func_uint16_t_u_u(
                                                              (0x6EL <
                                                               (safe_lshift_func_int16_t_s_u(
                                                                   ((+p_69.f4),
                                                                    (l_554 ^=
                                                                     (safe_rshift_func_uint8_t_u_s(
                                                                         (safe_rshift_func_int8_t_s_s(
                                                                             (p_69.f5 >=
                                                                              0x6D250B95L),
                                                                             p_69.f1)),
                                                                         l_528
                                                                             .f3)))),
                                                                   g_28.f4))),
                                                              3L))),
                                                         l_75.f2),
                                                        0x3C6BA643L))))) <=
                                               l_238) >= l_291.f1),
                                             4)),
                                         l_528.f6)),
                                     g_290.f5))))))),
                         p_69.f3)) == 4294967295UL) < l_75.f0));
              g_181 &=
                  ((4UL >
                    ((p_69.f2 & l_471) ||
                     (safe_lshift_func_uint16_t_u_s(
                         (p_69.f4 & ((g_28.f1 &= (p_70 >= g_449)) < 0x6DL)),
                         1)))) ||
                   g_5[0].f3);
            } else {
              struct S2 l_572 = {0xA5B92E3AL, 252UL, 0x1A88L, 4294967291UL,
                                 0x6F78L, 0x8B43L, 0UL};
              int16_t l_575 = 4L;
              g_447 =
                  ((safe_rshift_func_uint8_t_u_u(
                       (safe_mul_func_int16_t_s_s(1L, p_71.f0)), 0)) &
                   (safe_rshift_func_int16_t_s_s(
                       ((safe_lshift_func_int16_t_s_u(
                            ((p_71.f6 =
                                  ((+((safe_sub_func_int16_t_s_s(
                                          (((safe_lshift_func_int16_t_s_u(
                                                ((p_69.f6 !=
                                                  ((safe_mod_func_int32_t_s_s(
                                                       g_76[2][0][9].f3,
                                                       (g_181 & 0x5AL))),
                                                   (g_415[0][0].f5 ^
                                                    ((l_572,
                                                      (safe_add_func_uint32_t_u_u(
                                                          p_70,
                                                          4294967286UL))) !=
                                                     p_71.f4)))) &
                                                 p_71.f3),
                                                p_72)) < 1UL),
                                           l_347.f0),
                                          1UL)) == l_575)) <= p_69.f3)) ||
                             (-1L)),
                            11)) &
                        p_71.f3),
                       g_76[2][0][9].f2)));
              g_76[2][0][9] = g_290;
              g_162 = l_576;
              return p_69.f4;
            }
          }

          return l_238;
        }
        if (g_368[2]) {
          int16_t l_512[1][7] = {
              {0xF5BBL, 0x4C73L, 0x4C73L, 0xF5BBL, 0x4C73L, 0x4C73L, 0xF5BBL}};
          int32_t l_554 = 5L;
          int32_t l_555 = 0x27A58C53L;
          int32_t l_576 = 0x7AFC8810L;
          int i, j;
          if (((safe_lshift_func_int8_t_s_u(p_71.f1, l_512[0][3])),
               (safe_add_func_int32_t_s_s(
                   ((safe_rshift_func_int8_t_s_s(
                        0x0EL,
                        (((((safe_sub_func_int32_t_s_s(
                                (safe_rshift_func_uint16_t_u_s(
                                    l_347.f3,
                                    ((l_509 != (g_415[2][2], p_69.f4)) |
                                     (((g_5[0], g_468) != l_238) == l_471)))),
                                p_69.f3)) <= 4294967290UL) >= g_290.f1),
                          g_28),
                         l_291.f4))) |
                    0x41D8366DL),
                   0xD882FBFCL)))) {
            uint32_t l_521 = 0x1E457E49L;
            l_521--;
          } else {
            return p_68;
          }
          if ((((((((l_347.f1 == (8L < (g_28.f3 != (0x17L != p_69.f0)))) >
                    (safe_add_func_uint16_t_u_u(
                        (((safe_rshift_func_int16_t_s_u(
                              ((l_528,
                                ((l_529 = (g_76[2][0][9].f0 < 0x039FL)),
                                 (((0x4EL == g_76[2][0][9].f6) == p_71.f3) ^
                                  l_222))) |
                               g_290.f3),
                              g_28.f3)) &
                          8L) |
                         l_528.f2),
                        0xA133L))) &&
                   p_69.f6) ^
                  g_76[2][0][9].f0) |
                 g_5[0].f6) &
                l_445.f6) ^
               p_71.f6)) {
            l_555 &=
                (0UL ==
                 (((safe_mul_func_int16_t_s_s(
                       ((safe_rshift_func_uint16_t_u_u(g_368[2], 6)),
                        (+(g_290.f2 &= (safe_mod_func_uint16_t_u_u(
                               g_162,
                               (safe_sub_func_int16_t_s_s(
                                   (safe_mul_func_int16_t_s_s(
                                       (safe_rshift_func_uint8_t_u_u(
                                           ((((l_448 = 0x19L) >
                                              (safe_lshift_func_uint16_t_u_s(
                                                  (g_159 == (-1L)),
                                                  (safe_mod_func_uint32_t_u_u(
                                                      ((p_71.f6 = (safe_mul_func_uint16_t_u_u(
                                                            (0x6EL <
                                                             (safe_lshift_func_int16_t_s_u(
                                                                 ((+p_69.f4),
                                                                  (l_554 ^=
                                                                   (safe_rshift_func_uint8_t_u_s(
                                                                       (safe_rshift_func_int8_t_s_s(
                                                                           (p_69.f5 >=
                                                                            0x6D250B95L),
                                                                           p_69.f1)),
                                                                       l_528
                                                                           .f3)))),
                                                                 g_28.f4))),
                                                            3L))),
                                                       l_75.f2),
                                                      0x3C6BA643L))))) <=
                                             l_238) >= l_291.f1),
                                           4)),
                                       l_528.f6)),
                                   g_290.f5))))))),
                       p_69.f3)) == 4294967295UL) < l_75.f0));
            g_181 &=
                ((4UL > ((p_69.f2 & l_471) ||
                         (safe_lshift_func_uint16_t_u_s(
                             (p_69.f4 & ((g_28.f1 &= (p_70 >= g_449)) < 0x6DL)),
                             1)))) ||
                 g_5[0].f3);
          } else {
            struct S2 l_572 = {0xA5B92E3AL, 252UL, 0x1A88L, 4294967291UL,
                               0x6F78L, 0x8B43L, 0UL};
            int16_t l_575 = 4L;
            g_447 =
                ((safe_rshift_func_uint8_t_u_u(
                     (safe_mul_func_int16_t_s_s(1L, p_71.f0)), 0)) &
                 (safe_rshift_func_int16_t_s_s(
                     ((safe_lshift_func_int16_t_s_u(
                          ((p_71.f6 =
                                ((+((safe_sub_func_int16_t_s_s(
                                        (((safe_lshift_func_int16_t_s_u(
                                              ((p_69.f6 !=
                                                ((safe_mod_func_int32_t_s_s(
                                                     g_76[2][0][9].f3,
                                                     (g_181 & 0x5AL))),
                                                 (g_415[0][0].f5 ^
                                                  ((l_572,
                                                    (safe_add_func_uint32_t_u_u(
                                                        p_70, 4294967286UL))) !=
                                                   p_71.f4)))) &
                                               p_71.f3),
                                              p_72)) < 1UL),
                                         l_347.f0),
                                        1UL)) == l_575)) <= p_69.f3)) ||
                           (-1L)),
                          11)) &
                      p_71.f3),
                     g_76[2][0][9].f2)));
            g_76[2][0][9] = g_290;
            g_162 = l_576;
            return p_69.f4;
          }
        } else {
          int32_t l_577 = 0x4262284AL;
          int32_t l_579[3][10][1] = {{{(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)}},
                                     {{8L},
                                      {8L},
                                      {(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)},
                                      {8L}},
                                     {{8L},
                                      {(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)},
                                      {8L},
                                      {8L},
                                      {(-6L)},
                                      {8L},
                                      {8L}}};
          int i, j, k;
          --g_580;
          g_374 = l_579[0][9][0];
          return l_238;
        }
      }
    }
    {
      uint16_t l_107[5][8][6] = {
          {{0xB528L, 0xF467L, 65535UL, 0UL, 65535UL, 3UL},
           {1UL, 3UL, 0xAE1DL, 1UL, 0x2B1CL, 1UL},
           {65535UL, 0x9BD9L, 65535UL, 65535UL, 1UL, 0x259AL},
           {0xAE1DL, 3UL, 1UL, 0x47AEL, 65535UL, 0x62C9L},
           {65535UL, 0xF467L, 0xB528L, 0x47AEL, 0x1E74L, 65535UL},
           {0xAE1DL, 0UL, 0x7936L, 65535UL, 0x7936L, 0UL},
           {65535UL, 1UL, 0UL, 1UL, 65535UL, 65535UL},
           {1UL, 1UL, 0x9B28L, 0UL, 65535UL, 0x62C9L}},
          {{0xB528L, 1UL, 7UL, 3UL, 65535UL, 0x62C9L},
           {1UL, 0x9BD9L, 65535UL, 0x9BD9L, 1UL, 0UL},
           {7UL, 0xF467L, 9UL, 3UL, 0UL, 0x259AL},
           {65535UL, 65535UL, 65526UL, 0xF467L, 65535UL, 0x259AL},
           {65535UL, 0x259AL, 9UL, 0UL, 0x1E74L, 0UL},
           {65535UL, 65534UL, 65535UL, 1UL, 6UL, 0x62C9L},
           {9UL, 0x259AL, 65535UL, 1UL, 4UL, 0x47AEL},
           {65526UL, 65535UL, 65535UL, 1UL, 0x7936L, 1UL}},
          {{9UL, 0xF467L, 7UL, 1UL, 7UL, 0xF467L},
           {65535UL, 0x9BD9L, 1UL, 0UL, 65526UL, 1UL},
           {65535UL, 0UL, 65535UL, 0xF467L, 0xB528L, 0x47AEL},
           {65535UL, 0UL, 65535UL, 3UL, 65526UL, 0x62C9L},
           {7UL, 0x9BD9L, 4UL, 0x9BD9L, 7UL, 0UL},
           {1UL, 0xF467L, 3UL, 3UL, 0x7936L, 0x259AL},
           {65535UL, 65535UL, 65535UL, 0xF467L, 4UL, 0x259AL},
           {65535UL, 0x259AL, 3UL, 0UL, 6UL, 0UL}},
          {{4UL, 65534UL, 4UL, 1UL, 0x1E74L, 0x62C9L},
           {3UL, 0x259AL, 65535UL, 1UL, 65535UL, 0x47AEL},
           {65535UL, 65535UL, 65535UL, 1UL, 0UL, 1UL},
           {3UL, 0xF467L, 1UL, 1UL, 1UL, 0xF467L},
           {4UL, 0x9BD9L, 7UL, 0UL, 65535UL, 1UL},
           {65535UL, 0UL, 65535UL, 0xF467L, 0x9B28L, 0x47AEL},
           {65535UL, 0UL, 65535UL, 3UL, 65535UL, 0x62C9L},
           {1UL, 0x9BD9L, 65535UL, 0x9BD9L, 1UL, 0UL}},
          {{7UL, 0xF467L, 9UL, 3UL, 0UL, 0x259AL},
           {65535UL, 65535UL, 65526UL, 0xF467L, 65535UL, 0x259AL},
           {65535UL, 0x259AL, 9UL, 0UL, 0x1E74L, 0UL},
           {65535UL, 65534UL, 65535UL, 1UL, 6UL, 0x62C9L},
           {9UL, 0x259AL, 65535UL, 1UL, 4UL, 0x47AEL},
           {65526UL, 65535UL, 65535UL, 1UL, 0x7936L, 1UL},
           {9UL, 0xF467L, 7UL, 1UL, 7UL, 0xF467L},
           {65535UL, 0x9BD9L, 1UL, 0UL, 65526UL, 1UL}}};
      int16_t l_108 = 9L;
      uint16_t l_109 = 0x030AL;
      int i, j, k;
    l_109
      |=
      ((((safe_mul_func_uint16_t_u_u (0xCA7BL, (safe_lshift_func_uint16_t_u_u (func_83 ((p_68 = (g_76[1][3][2], (+(safe_lshift_func_uint16_t_u_s ((safe_add_func_int32_t_s_s ((safe_rshift_func_uint8_t_u_s ((safe_add_func_int16_t_s_s (((((0x8701C1B6L == (safe_add_func_int16_t_s_s (((safe_lshift_func_int16_t_s_s (((g_17[5] = (g_28.f1 <= (safe_add_func_uint32_t_u_u (((safe_sub_func_int32_t_s_s (1L, (safe_lshift_func_int16_t_s_u ((safe_rshift_func_uint8_t_u_u (0x5DL, ((((p_69.f5 >= (g_28.f6 = (((p_72 ^= (safe_mod_func_uint32_t_u_u (((g_28.f2 || ((0x6B95L < g_76[2][0][9].f3) | p_68)) < l_107[2][2][5]), 0x6DA58D7DL))) ^ l_75.f5) ^ 0xA032275AL))) | l_107[3][6][2]) < p_69.f3) || g_5[0].f2))), 1)))) <= g_76[2][0][9].f6), g_28.f1)))) | 0x65F83DE7L), p_71.f1)) < g_5[0].f2), g_76[2][0][9].f5))), 0x29863923L) == l_108) != 0x10L), l_107[2][2][5])), l_107[2][2][5])), l_75.f4)), 1)))))), 13)))) || 0x6BL), p_69.f5), p_69.f6);
    }
  }
  for (p_69.f6 = 24; (p_69.f6 > 26); p_69.f6++) {
    uint16_t l_107[5][8][6] = {
        {{0xB528L, 0xF467L, 65535UL, 0UL, 65535UL, 3UL},
         {1UL, 3UL, 0xAE1DL, 1UL, 0x2B1CL, 1UL},
         {65535UL, 0x9BD9L, 65535UL, 65535UL, 1UL, 0x259AL},
         {0xAE1DL, 3UL, 1UL, 0x47AEL, 65535UL, 0x62C9L},
         {65535UL, 0xF467L, 0xB528L, 0x47AEL, 0x1E74L, 65535UL},
         {0xAE1DL, 0UL, 0x7936L, 65535UL, 0x7936L, 0UL},
         {65535UL, 1UL, 0UL, 1UL, 65535UL, 65535UL},
         {1UL, 1UL, 0x9B28L, 0UL, 65535UL, 0x62C9L}},
        {{0xB528L, 1UL, 7UL, 3UL, 65535UL, 0x62C9L},
         {1UL, 0x9BD9L, 65535UL, 0x9BD9L, 1UL, 0UL},
         {7UL, 0xF467L, 9UL, 3UL, 0UL, 0x259AL},
         {65535UL, 65535UL, 65526UL, 0xF467L, 65535UL, 0x259AL},
         {65535UL, 0x259AL, 9UL, 0UL, 0x1E74L, 0UL},
         {65535UL, 65534UL, 65535UL, 1UL, 6UL, 0x62C9L},
         {9UL, 0x259AL, 65535UL, 1UL, 4UL, 0x47AEL},
         {65526UL, 65535UL, 65535UL, 1UL, 0x7936L, 1UL}},
        {{9UL, 0xF467L, 7UL, 1UL, 7UL, 0xF467L},
         {65535UL, 0x9BD9L, 1UL, 0UL, 65526UL, 1UL},
         {65535UL, 0UL, 65535UL, 0xF467L, 0xB528L, 0x47AEL},
         {65535UL, 0UL, 65535UL, 3UL, 65526UL, 0x62C9L},
         {7UL, 0x9BD9L, 4UL, 0x9BD9L, 7UL, 0UL},
         {1UL, 0xF467L, 3UL, 3UL, 0x7936L, 0x259AL},
         {65535UL, 65535UL, 65535UL, 0xF467L, 4UL, 0x259AL},
         {65535UL, 0x259AL, 3UL, 0UL, 6UL, 0UL}},
        {{4UL, 65534UL, 4UL, 1UL, 0x1E74L, 0x62C9L},
         {3UL, 0x259AL, 65535UL, 1UL, 65535UL, 0x47AEL},
         {65535UL, 65535UL, 65535UL, 1UL, 0UL, 1UL},
         {3UL, 0xF467L, 1UL, 1UL, 1UL, 0xF467L},
         {4UL, 0x9BD9L, 7UL, 0UL, 65535UL, 1UL},
         {65535UL, 0UL, 65535UL, 0xF467L, 0x9B28L, 0x47AEL},
         {65535UL, 0UL, 65535UL, 3UL, 65535UL, 0x62C9L},
         {1UL, 0x9BD9L, 65535UL, 0x9BD9L, 1UL, 0UL}},
        {{7UL, 0xF467L, 9UL, 3UL, 0UL, 0x259AL},
         {65535UL, 65535UL, 65526UL, 0xF467L, 65535UL, 0x259AL},
         {65535UL, 0x259AL, 9UL, 0UL, 0x1E74L, 0UL},
         {65535UL, 65534UL, 65535UL, 1UL, 6UL, 0x62C9L},
         {9UL, 0x259AL, 65535UL, 1UL, 4UL, 0x47AEL},
         {65526UL, 65535UL, 65535UL, 1UL, 0x7936L, 1UL},
         {9UL, 0xF467L, 7UL, 1UL, 7UL, 0xF467L},
         {65535UL, 0x9BD9L, 1UL, 0UL, 65526UL, 1UL}}};
    int16_t l_108 = 9L;
    uint16_t l_109 = 0x030AL;
    int i, j, k;
    l_109
      |=
      ((((safe_mul_func_uint16_t_u_u (0xCA7BL, (safe_lshift_func_uint16_t_u_u (func_83 ((p_68 = (g_76[1][3][2], (+(safe_lshift_func_uint16_t_u_s ((safe_add_func_int32_t_s_s ((safe_rshift_func_uint8_t_u_s ((safe_add_func_int16_t_s_s (((((0x8701C1B6L == (safe_add_func_int16_t_s_s (((safe_lshift_func_int16_t_s_s (((g_17[5] = (g_28.f1 <= (safe_add_func_uint32_t_u_u (((safe_sub_func_int32_t_s_s (1L, (safe_lshift_func_int16_t_s_u ((safe_rshift_func_uint8_t_u_u (0x5DL, ((((p_69.f5 >= (g_28.f6 = (((p_72 ^= (safe_mod_func_uint32_t_u_u (((g_28.f2 || ((0x6B95L < g_76[2][0][9].f3) | p_68)) < l_107[2][2][5]), 0x6DA58D7DL))) ^ l_75.f5) ^ 0xA032275AL))) | l_107[3][6][2]) < p_69.f3) || g_5[0].f2))), 1)))) <= g_76[2][0][9].f6), g_28.f1)))) | 0x65F83DE7L), p_71.f1)) < g_5[0].f2), g_76[2][0][9].f5))), 0x29863923L) == l_108) != 0x10L), l_107[2][2][5])), l_107[2][2][5])), l_75.f4)), 1)))))), 13)))) || 0x6BL), p_69.f5), p_69.f6);
  }

  return g_76[2][0][9].f6;
}

static uint16_t func_83(int8_t p_84) { return g_28.f0; }

int main(int argc, char* argv[]) {
  int i, j, k;
  int print_hash_value = 0;
  crc32_gentab();
  func_1();
  for (i = 0; i < 1; i++) {
    transparent_crc(g_5[i].f0, "g_5[i].f0", print_hash_value);
    transparent_crc(g_5[i].f1, "g_5[i].f1", print_hash_value);
    transparent_crc(g_5[i].f2, "g_5[i].f2", print_hash_value);
    transparent_crc(g_5[i].f3, "g_5[i].f3", print_hash_value);
    transparent_crc(g_5[i].f4, "g_5[i].f4", print_hash_value);
    transparent_crc(g_5[i].f5, "g_5[i].f5", print_hash_value);
    transparent_crc(g_5[i].f6, "g_5[i].f6", print_hash_value);
    if (print_hash_value) printf("index = [%d]\n", i);
  }
  transparent_crc(g_16, "g_16", print_hash_value);
  for (i = 0; i < 8; i++) {
    transparent_crc(g_17[i], "g_17[i]", print_hash_value);
    if (print_hash_value) printf("index = [%d]\n", i);
  }
  transparent_crc(g_22, "g_22", print_hash_value);
  transparent_crc(g_28.f0, "g_28.f0", print_hash_value);
  transparent_crc(g_28.f1, "g_28.f1", print_hash_value);
  transparent_crc(g_28.f2, "g_28.f2", print_hash_value);
  transparent_crc(g_28.f3, "g_28.f3", print_hash_value);
  transparent_crc(g_28.f4, "g_28.f4", print_hash_value);
  transparent_crc(g_28.f5, "g_28.f5", print_hash_value);
  transparent_crc(g_28.f6, "g_28.f6", print_hash_value);
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 10; k++) {
        transparent_crc(g_76[i][j][k].f0, "g_76[i][j][k].f0", print_hash_value);
        transparent_crc(g_76[i][j][k].f1, "g_76[i][j][k].f1", print_hash_value);
        transparent_crc(g_76[i][j][k].f2, "g_76[i][j][k].f2", print_hash_value);
        transparent_crc(g_76[i][j][k].f3, "g_76[i][j][k].f3", print_hash_value);
        transparent_crc(g_76[i][j][k].f4, "g_76[i][j][k].f4", print_hash_value);
        transparent_crc(g_76[i][j][k].f5, "g_76[i][j][k].f5", print_hash_value);
        transparent_crc(g_76[i][j][k].f6, "g_76[i][j][k].f6", print_hash_value);
        if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_146, "g_146", print_hash_value);
  transparent_crc(g_159, "g_159", print_hash_value);
  transparent_crc(g_160, "g_160", print_hash_value);
  transparent_crc(g_162, "g_162", print_hash_value);
  transparent_crc(g_181, "g_181", print_hash_value);
  transparent_crc(g_223, "g_223", print_hash_value);
  transparent_crc(g_290.f0, "g_290.f0", print_hash_value);
  transparent_crc(g_290.f1, "g_290.f1", print_hash_value);
  transparent_crc(g_290.f2, "g_290.f2", print_hash_value);
  transparent_crc(g_290.f3, "g_290.f3", print_hash_value);
  transparent_crc(g_290.f4, "g_290.f4", print_hash_value);
  transparent_crc(g_290.f5, "g_290.f5", print_hash_value);
  transparent_crc(g_290.f6, "g_290.f6", print_hash_value);
  for (i = 0; i < 6; i++) {
    transparent_crc(g_368[i], "g_368[i]", print_hash_value);
    if (print_hash_value) printf("index = [%d]\n", i);
  }
  transparent_crc(g_374, "g_374", print_hash_value);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 3; j++) {
      transparent_crc(g_380[i][j], "g_380[i][j]", print_hash_value);
      if (print_hash_value) printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_392, "g_392", print_hash_value);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 3; j++) {
      transparent_crc(g_415[i][j].f0, "g_415[i][j].f0", print_hash_value);
      transparent_crc(g_415[i][j].f1, "g_415[i][j].f1", print_hash_value);
      transparent_crc(g_415[i][j].f2, "g_415[i][j].f2", print_hash_value);
      transparent_crc(g_415[i][j].f3, "g_415[i][j].f3", print_hash_value);
      transparent_crc(g_415[i][j].f4, "g_415[i][j].f4", print_hash_value);
      transparent_crc(g_415[i][j].f5, "g_415[i][j].f5", print_hash_value);
      if (print_hash_value) printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_447, "g_447", print_hash_value);
  transparent_crc(g_449, "g_449", print_hash_value);
  transparent_crc(g_467, "g_467", print_hash_value);
  transparent_crc(g_468, "g_468", print_hash_value);
  transparent_crc(g_470, "g_470", print_hash_value);
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      for (k = 0; k < 10; k++) {
        transparent_crc(g_472[i][j][k], "g_472[i][j][k]", print_hash_value);
        if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_580, "g_580", print_hash_value);
  transparent_crc(g_584, "g_584", print_hash_value);
  transparent_crc(g_766, "g_766", print_hash_value);
  transparent_crc(g_811, "g_811", print_hash_value);
  transparent_crc(g_845, "g_845", print_hash_value);
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 8; j++) {
      transparent_crc(g_846[i][j], "g_846[i][j]", print_hash_value);
      if (print_hash_value) printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_1038, "g_1038", print_hash_value);
  transparent_crc(g_1160, "g_1160", print_hash_value);
  transparent_crc(g_1220, "g_1220", print_hash_value);
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}

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

static int64_t(safe_unary_minus_func_int64_t_s)(int64_t si) {

  return

      (si == (-9223372036854775807LL -1)) ? ((si)) :

                        -si;
}

static int64_t(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((9223372036854775807LL) - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < ((-9223372036854775807LL -1) - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int64_t(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~(9223372036854775807LL)))) - si2) ^ si2)) < 0)
          ? ((si1))
          :

          (si1 - si2);
}

static int64_t(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((9223372036854775807LL) / si2))) ||
       ((si1 > 0) && (si2 <= 0) && (si2 < ((-9223372036854775807LL -1) / si1))) ||
       ((si1 <= 0) && (si2 > 0) && (si1 < ((-9223372036854775807LL -1) / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((9223372036854775807LL) / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int64_t(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      ((si2 == 0) || ((si1 == (-9223372036854775807LL -1)) && (si2 == (-1)))) ? ((si1)) :

                                                            (si1 % si2);
}

static int64_t(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      ((si2 == 0) || ((si1 == (-9223372036854775807LL -1)) && (si2 == (-1)))) ? ((si1)) :

                                                            (si1 / si2);
}

static int64_t(safe_lshift_func_int64_t_s_s)(int64_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((9223372036854775807LL) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static int64_t(safe_lshift_func_int64_t_s_u)(int64_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32) ||
       (left > ((9223372036854775807LL) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static int64_t(safe_rshift_func_int64_t_s_s)(int64_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
          ? ((left))
          :

          (left >> ((int)right));
}

static int64_t(safe_rshift_func_int64_t_s_u)(int64_t left, unsigned int right) {

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

static uint64_t(safe_unary_minus_func_uint64_t_u)(uint64_t ui) { return -ui; }

static uint64_t(safe_add_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {

  return ui1 + ui2;
}

static uint64_t(safe_sub_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {

  return ui1 - ui2;
}

static uint64_t(safe_mul_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {

  return ((unsigned long long)ui1) * ((unsigned long long)ui2);
}

static uint64_t(safe_mod_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 % ui2);
}

static uint64_t(safe_div_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {

  return

      (ui2 == 0) ? ((ui1)) :

                 (ui1 / ui2);
}

static uint64_t(safe_lshift_func_uint64_t_u_s)(uint64_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((18446744073709551615ULL) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static uint64_t(safe_lshift_func_uint64_t_u_u)(uint64_t left,
                                               unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > ((18446744073709551615ULL) >> ((unsigned int)right))))
          ? ((left))
          :

          (left << ((unsigned int)right));
}

static uint64_t(safe_rshift_func_uint64_t_u_s)(uint64_t left, int right) {

  return

      ((((int)right) < 0) || (((int)right) >= 32)) ? ((left)) :

                                                   (left >> ((int)right));
}

static uint64_t(safe_rshift_func_uint64_t_u_u)(uint64_t left,
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

      (fabs((0.5 * sf1) + (0.5 * sf2)) > (0.5 * 1.7976931348623157e+308)) ? (sf1) :

                                                          (sf1 + sf2);
}

static double(safe_sub_func_double_f_f)(double sf1, double sf2) {

  return

      (fabs((0.5 * sf1) - (0.5 * sf2)) > (0.5 * 1.7976931348623157e+308)) ? (sf1) :

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
       (((sf2 == 0.0) || (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) >
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
static void crc32_8bytes(uint64_t val) {
  crc32_byte((val >> 0) & 0xff);
  crc32_byte((val >> 8) & 0xff);
  crc32_byte((val >> 16) & 0xff);
  crc32_byte((val >> 24) & 0xff);
  crc32_byte((val >> 32) & 0xff);
  crc32_byte((val >> 40) & 0xff);
  crc32_byte((val >> 48) & 0xff);
  crc32_byte((val >> 56) & 0xff);
}

static void transparent_crc(uint64_t val, char *vname, int flag) {
  crc32_8bytes(val);
  if (flag) {
    printf("...checksum after hashing %s : %lX\n", vname,
           crc32_context ^ 0xFFFFFFFFUL);
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

static int32_t g_4 = 1L;
static uint8_t g_27[7] = {0xE7L, 0xE7L, 0xBBL, 0xE7L, 0xE7L, 0xBBL, 0xE7L};
static int32_t g_150 = 1L;
static int16_t g_185 = (-6L);
static uint32_t g_186 = 0x2B7E3690L;
static uint8_t g_205 = 251UL;
static uint32_t g_361 = 0x67B818E0L;
static uint32_t g_362 = 0x07D99C1FL;
static int32_t g_365 = 0xA54B7A8BL;
static uint32_t g_420 = 1UL;
static int32_t g_463[6] = {0x6972C5E3L, 0x6972C5E3L, 0x0CC05694L,
                           0x6972C5E3L, 0x6972C5E3L, 0x0CC05694L};
static uint8_t g_493 = 1UL;
static uint32_t g_734 = 0x10824ECDL;
static uint32_t g_753 = 4294967295UL;
static int32_t g_870 = 0L;
static const uint16_t g_1089[10] = {0x3CA5L, 0x3CA5L, 0x3CA5L, 0x3CA5L,
                                    0x3CA5L, 0x3CA5L, 0x3CA5L, 0x3CA5L,
                                    0x3CA5L, 0x3CA5L};
static uint8_t g_1201 = 0x5AL;
static int32_t g_1503 = 1L;
static int16_t g_1526[7][2] = {{1L, (-1L)}, {1L, (-1L)}, {1L, (-1L)},
                               {1L, (-1L)}, {1L, (-1L)}, {1L, (-1L)},
                               {1L, (-1L)}};
static uint32_t g_1942 = 0UL;
static int8_t g_2050[2] = {0L, 0L};
static int32_t g_2104 = 0x87D9316EL;
static uint8_t g_2473 = 0xA9L;
static int8_t g_2503[7][7][5] = {{{0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L}},
                                 {{0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L}},
                                 {{0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L}},
                                 {{0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L}},
                                 {{0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L}},
                                 {{0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L}},
                                 {{0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L},
                                  {0x7EL, (-9L), 0L, 0xEAL, 6L}}};
static uint8_t g_2780[2] = {0UL, 0UL};
static int8_t g_2787 = 8L;
static const int32_t g_2927 = 0x8481FC27L;

static int32_t func_1(void);
static uint16_t func_28(const int32_t p_29);
static uint8_t func_32(int8_t p_33, uint16_t p_34, int32_t p_35, uint8_t p_36);
static int8_t func_37(int32_t p_38, int8_t p_39, int32_t p_40);
static int16_t func_41(uint8_t p_42, int16_t p_43, uint32_t p_44, int16_t p_45,
                       int32_t p_46);
static int8_t func_49(int8_t p_50, uint16_t p_51, const uint32_t p_52);
static const uint8_t func_57(uint8_t p_58, int8_t p_59, int8_t p_60,
                             int32_t p_61, int8_t p_62);
static uint16_t func_65(uint8_t p_66, uint32_t p_67);
static int8_t func_81(int8_t p_82, int32_t p_83);
static uint8_t func_85(uint8_t p_86, uint16_t p_87, int8_t p_88);
static int32_t func_1(void) {
  uint16_t l_7 = 0x272AL;
  int32_t l_10[7];
  int8_t l_1943[4][2][4] = {
      {{(-1L), (-1L), 0x94L, 0xB9L}, {(-1L), (-1L), 0x94L, 0xB9L}},
      {{(-1L), (-1L), 0x94L, 0xB9L}, {(-1L), (-1L), 0x94L, 0xB9L}},
      {{(-1L), (-1L), 0x94L, 0xB9L}, {(-1L), (-1L), 0x94L, 0xB9L}},
      {{(-1L), (-1L), 0x94L, 0xB9L}, {(-1L), (-1L), 0x94L, 0xB9L}}};
  uint32_t l_2982 = 0xE195B792L;
  int i, j, k;
  for (i = 0; i < 7; i++)
    l_10[i] = 0x0E704F3DL;
  l_10[2] = (safe_add_func_uint8_t_u_u(
      (g_4 < g_4), (((safe_mod_func_uint8_t_u_u(l_7, l_7)) &
                     (safe_sub_func_uint32_t_u_u(g_4, g_4))) == g_4)));
  g_27[6] ^=
      ((!0x8421L) &
       ((safe_sub_func_uint16_t_u_u(
            (safe_mod_func_uint16_t_u_u(
                (safe_sub_func_int16_t_s_s(
                    ((-6L) | l_7),
                    ((safe_add_func_uint8_t_u_u(
                         (0x62L <=
                          (safe_div_func_int32_t_s_s(
                              ((safe_add_func_uint8_t_u_u(
                                   ((~l_10[6]) >
                                    (safe_add_func_int8_t_s_s(
                                        (safe_add_func_int16_t_s_s(
                                            (-1L), (l_10[2] >=
                                                    (0x5A8CCEDBL > l_10[2])))),
                                        g_4))),
                                   l_10[2])) == 0xD4L),
                              0xB79DC866L))),
                         l_10[2])) |
                     0x4DL))),
                65526UL)),
            g_4)) ^
        g_4));
  if (g_27[6]) {
    uint32_t l_829 = 0x8A6CA8BCL;
    int8_t l_1959 = 0x7CL;
    int32_t l_2945 = (-1L);
    uint8_t l_2979 = 1UL;
    if ((g_27[6] !=
         func_28((safe_sub_func_uint8_t_u_u(
             func_32(
                 func_37(
                     (((((func_41(
                              (safe_mul_func_int8_t_s_s(
                                  1L,
                                  (func_49(
                                       (safe_mod_func_uint16_t_u_u(
                                           (0L &
                                            ((safe_mod_func_int8_t_s_s(
                                                 0x02L, (g_4 ^ g_4))) <
                                             func_57(
                                                 (((safe_mod_func_uint16_t_u_u(
                                                       func_65(
                                                           (safe_mul_func_uint8_t_u_u(
                                                               g_4, g_4)),
                                                           g_27[0]),
                                                       1UL)) &
                                                   0x0D3385B3L) <= l_10[0]),
                                                 l_829, g_753, g_734, g_734))),
                                           g_27[6])),
                                       l_7, g_1526[4][0]) < g_1942))),
                              g_27[5], g_1526[5][0], l_1943[3][1][0],
                              g_1526[5][0]) != 1L) == l_829) ^
                        g_734) &&
                       l_10[2]) > g_734),
                     l_1959, g_27[6]),
                 l_7, g_4, l_829),
             l_10[2]))))) {
      uint8_t l_2946 = 0x48L;
      const int32_t l_2949 = 0xBC5B5660L;
      l_2946--;
      g_1503
 ^=
 (((l_2949 || (((((safe_rshift_func_int16_t_s_u (((safe_sub_func_int8_t_s_s ((((safe_sub_func_int16_t_s_s ((((((((safe_mul_func_uint16_t_u_u ((((safe_add_func_uint16_t_u_u ((safe_lshift_func_int16_t_s_u (1L, (safe_mul_func_int16_t_s_s ((safe_sub_func_int16_t_s_s ((safe_div_func_int32_t_s_s (1L, (~(safe_sub_func_int16_t_s_s (l_1959, ((l_2945 == ((safe_unary_minus_func_uint8_t_u ((safe_mul_func_int16_t_s_s ((safe_lshift_func_uint8_t_u_u (0x34L, 6)), (((((safe_sub_func_uint16_t_u_u ((safe_add_func_int8_t_s_s ((g_365 == (g_2050[1] > ((l_2946 && 0x45L) <= 0xB39E4DC6L))), g_362)), l_1959)) < g_2473) || l_2979) > 65532UL) != 255UL))))) <= g_2104)) > g_1942)))))), l_2949)), l_2945)))), l_2945)) && 0UL) && g_1942), g_365)) != g_362) > g_1201) <= g_185) >= 0xEF1274DEL) != 65533UL) <= l_2949), g_1089[1])) != g_2780[1]) || 0x6F87L), g_2503[1][3][2])) && l_2946), 4)) != l_2949) ^ l_10[2]) ^ g_1089[1]) != l_1943[3][1][0])) < l_1959) != g_870);
      l_10[2] =
          ((safe_rshift_func_uint8_t_u_u(
               l_2982,
               (((g_1526[5][0] ^ l_2979) &&
                 (safe_add_func_uint16_t_u_u(
                     (safe_lshift_func_uint8_t_u_s(8UL, 0)),
                     (safe_rshift_func_int8_t_s_u(
                         ((0xAD48L >=
                           (safe_div_func_int32_t_s_s(g_420, 8UL))) ||
                          (0xD0C9L < (safe_div_func_uint32_t_u_u(
                                         (safe_mul_func_int8_t_s_s(
                                             (g_1942 == g_1089[5]), l_2949)),
                                         g_2927)))),
                         g_365))))) ||
                l_2982))) == l_1943[2][0][2]);
    } else {
      int32_t l_3035[4][1][2];
      int32_t l_3036[3];
      uint8_t l_3037[3][2][7] = {
          {{246UL, 246UL, 0x1CL, 253UL, 0xD4L, 253UL, 0x1CL},
           {246UL, 246UL, 0x1CL, 253UL, 0xD4L, 253UL, 0x1CL}},
          {{246UL, 246UL, 0x1CL, 253UL, 0xD4L, 253UL, 0x1CL},
           {246UL, 246UL, 0x1CL, 253UL, 0xD4L, 253UL, 0x1CL}},
          {{246UL, 246UL, 0x1CL, 253UL, 0xD4L, 253UL, 0x1CL},
           {246UL, 246UL, 0x1CL, 253UL, 0xD4L, 253UL, 0x1CL}}};
      int i, j, k;
      for (i = 0; i < 4; i++) {
        for (j = 0; j < 1; j++) {
          for (k = 0; k < 2; k++)
            l_3035[i][j][k] = 0L;
        }
      }
      for (i = 0; i < 3; i++)
        l_3036[i] = 0x0162406CL;
      l_3036
 [1]
 =
 ((safe_rshift_func_uint8_t_u_s (l_1943[1][1][1], 1)) != ((safe_lshift_func_uint16_t_u_u (((l_2979 > (safe_sub_func_int16_t_s_s (((safe_rshift_func_int8_t_s_u ((safe_sub_func_int8_t_s_s ((((!(safe_lshift_func_uint8_t_u_s ((g_27[1] && (safe_sub_func_uint16_t_u_u ((safe_add_func_uint16_t_u_u ((safe_sub_func_uint16_t_u_u ((((safe_add_func_uint16_t_u_u (((((((safe_rshift_func_int8_t_s_u ((((safe_mod_func_int16_t_s_s (l_2979, l_2979)) == (safe_div_func_int16_t_s_s ((g_463[3] >= (safe_sub_func_int16_t_s_s ((safe_sub_func_uint8_t_u_u ((safe_mod_func_int16_t_s_s ((l_829 <= (safe_mul_func_int16_t_s_s (((safe_sub_func_uint16_t_u_u (1UL, (safe_lshift_func_uint16_t_u_s ((((safe_div_func_uint16_t_u_u (((l_3035[3][0][0] ^ 0x158B9CC8L) != 0xEDL), 8UL)) || 1L) ^ g_1089[1]), 8)))) < g_365), g_185))), l_1943[3][0][0])), g_463[0])), l_7))), 9L))) || g_1089[8]), 4)) & l_2945) || l_2982) ^ 4294967286UL) | 3L) <= 0x42BAC66DL), g_27[6])) < 0x9DL) > l_1943[1][0][0]), l_1943[3][1][0])), l_2982)), (-8L)))), l_1959))) ^ 0x057CL) && 0x5DL), 4UL)), l_1959)) >= 0x7645L), l_1943[3][1][0]))) || l_3035[3][0][0]), 13)) >= l_2982));
      l_3037[0][0][1] = g_361;
    }
  } else {
    int32_t l_3050 = 0xB0C45DF9L;
    g_1503 =
        ((l_10[1] |
          (safe_rshift_func_int16_t_s_s(
              ((l_1943[3][1][0] ||
                (((safe_mod_func_int16_t_s_s(
                      ((safe_mul_func_int8_t_s_s(
                           (safe_rshift_func_uint8_t_u_s(
                               l_7,
                               (safe_lshift_func_uint8_t_u_u(
                                   ((safe_rshift_func_int8_t_s_u(
                                        (l_3050 &&
                                         (safe_add_func_uint8_t_u_u(
                                             ((safe_sub_func_int16_t_s_s(
                                                  l_2982, g_1201)) <
                                              ((g_2503[1][3][2] &
                                                (((0xB78074E9L > g_420) ==
                                                  4L) <= l_3050)) > g_1201)),
                                             0xE2L))),
                                        6)) |
                                    l_3050),
                                   l_3050)))),
                           0x09L)) ^
                       g_1503),
                      g_2104)) ||
                  l_3050) != g_362)) != g_1942),
              15))) &
         g_27[3]);
  }
  return l_2982;
}

static uint16_t func_28(const int32_t p_29) {
  int8_t l_2933 = (-5L);
  int32_t l_2934 = (-2L);
  int32_t l_2935 = (-1L);
  int32_t l_2936 = (-9L);
  int32_t l_2937 = 0xFD762BA8L;
  int32_t l_2938 = 0xF1B34372L;
  int32_t l_2939 = 0x09F4A08EL;
  int32_t l_2940[7];
  int16_t l_2941 = 1L;
  uint16_t l_2942 = 65535UL;
  int i;
  for (i = 0; i < 7; i++)
    l_2940[i] = (-4L);
  ++l_2942;
  return g_27[6];
}

static uint8_t func_32(int8_t p_33, uint16_t p_34, int32_t p_35, uint8_t p_36) {
  uint8_t l_2930[1][9] = {
      {0UL, 0x27L, 0UL, 0x27L, 0UL, 0x27L, 0UL, 0x27L, 0UL}};
  int i, j;
  g_1503 &= 0x312F0DD3L;
  l_2930[0][4]--;
  return g_2503[1][3][2];
}

static int8_t func_37(int32_t p_38, int8_t p_39, int32_t p_40) {
  int32_t l_1968 = 0xD7E5A479L;
  uint32_t l_1969 = 18446744073709551607UL;
  int32_t l_1970 = 0x728BBE2FL;
  int32_t l_1974 = 0L;
  int32_t l_1975 = (-1L);
  uint32_t l_1976 = 0x25C031FAL;
  int32_t l_2066 = 1L;
  uint16_t l_2226 = 0x84A4L;
  int32_t l_2239 = 9L;
  uint16_t l_2305 = 65531UL;
  uint32_t l_2322 = 0x5802E505L;
  int16_t l_2461 = (-7L);
  int32_t l_2511[3][8][4] = {{{0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L}},
                             {{0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L}},
                             {{0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L},
                              {0xA42AEFDBL, 0xC8FCAA42L, (-1L), 0xC8FCAA42L}}};
  uint16_t l_2744 = 0x5898L;
  int32_t l_2777 = 0xB6F8FAA0L;
  uint16_t l_2778 = 0x001CL;
  int32_t l_2779[2];
  int i, j, k;
  for (i = 0; i < 2; i++)
    l_2779[i] = 0xB6CB34A7L;
  l_1970 = ((p_40 ^ ((0x6DC2E0F5L > p_40) ||
                     (((((safe_mul_func_uint8_t_u_u(
                             (safe_lshift_func_uint8_t_u_u(
                                 ((safe_sub_func_uint32_t_u_u(
                                      (safe_mod_func_uint32_t_u_u(
                                          ((-1L) <= (l_1968 | p_38)), p_38)),
                                      (p_40 >= 0x58FE04B9L))) ^
                                  p_40),
                                 p_38)),
                             l_1968)) >= l_1968) >= l_1969) >= g_27[6]) ^
                      1UL))) ||
            l_1968);
  for (g_185 = (-21); (g_185 >= (-30)); --g_185) {
    int32_t l_1973[6];
    int32_t l_2004 = 0xF9C07A40L;
    int16_t l_2041 = 0L;
    uint32_t l_2084 = 1UL;
    uint8_t l_2112 = 0UL;
    uint8_t l_2119 = 255UL;
    uint32_t l_2141 = 0xCB9F49DEL;
    int i;
    for (i = 0; i < 6; i++)
      l_1973[i] = (-6L);
    l_1976++;
    for (p_39 = 17; (p_39 > (-23));
         p_39 = safe_sub_func_uint16_t_u_u(p_39, 2)) {
      uint32_t l_1981 = 18446744073709551615UL;
      return l_1981;
    }

    l_1976++;
  }
  if ((safe_lshift_func_int8_t_s_u((g_1089[8] < p_39), 7))) {
    uint8_t l_2148 = 0xB4L;
    int16_t l_2162 = 0L;
    int32_t l_2163 = (-1L);
    int32_t l_2317 = 1L;
    int32_t l_2318 = 0L;
    int32_t l_2319 = 0x784F46DAL;
    int32_t l_2320[9][5] = {
        {(-9L), 0L, (-1L), 8L, (-1L)}, {(-9L), 0L, (-1L), 8L, (-1L)},
        {(-9L), 0L, (-1L), 8L, (-1L)}, {(-9L), 0L, (-1L), 8L, (-1L)},
        {(-9L), 0L, (-1L), 8L, (-1L)}, {(-9L), 0L, (-1L), 8L, (-1L)},
        {(-9L), 0L, (-1L), 8L, (-1L)}, {(-9L), 0L, (-1L), 8L, (-1L)},
        {(-9L), 0L, (-1L), 8L, (-1L)}};
    int8_t l_2502 = 0x51L;
    uint32_t l_2687 = 0x2FF85CB7L;
    int32_t l_2712 = 1L;
    uint16_t l_2713[6][2][7] = {
        {{0x5565L, 0x6276L, 2UL, 65535UL, 0xD9DEL, 1UL, 1UL},
         {0x5565L, 0x6276L, 2UL, 65535UL, 0xD9DEL, 1UL, 1UL}},
        {{0x5565L, 0x6276L, 2UL, 65535UL, 0xD9DEL, 1UL, 1UL},
         {0x5565L, 0x6276L, 2UL, 65535UL, 0xD9DEL, 1UL, 1UL}},
        {{0x5565L, 0x6276L, 2UL, 65535UL, 0xD9DEL, 1UL, 1UL},
         {0x5565L, 0x6276L, 2UL, 65535UL, 0xD9DEL, 1UL, 1UL}},
        {{0x5565L, 0x6276L, 2UL, 65535UL, 0xD9DEL, 1UL, 1UL},
         {0x5565L, 0x6276L, 2UL, 65535UL, 0xD9DEL, 1UL, 1UL}},
        {{0x5565L, 0x6276L, 2UL, 65535UL, 0xD9DEL, 1UL, 1UL},
         {0x5565L, 0x6276L, 2UL, 65535UL, 0xD9DEL, 1UL, 1UL}},
        {{0x5565L, 0x6276L, 2UL, 65535UL, 0xD9DEL, 1UL, 1UL},
         {0x5565L, 0x6276L, 2UL, 65535UL, 0xD9DEL, 1UL, 1UL}}};
    int32_t l_2820 = 0x9BA7B86AL;
    const uint16_t l_2928 = 0x1D7CL;
    int i, j, k;

    {
      int32_t l_1973[6];
      int32_t l_2004 = 0xF9C07A40L;
      int16_t l_2041 = 0L;
      uint32_t l_2084 = 1UL;
      uint8_t l_2112 = 0UL;
      uint8_t l_2119 = 255UL;
      uint32_t l_2141 = 0xCB9F49DEL;
      int i;
      for (i = 0; i < 6; i++)
        l_1973[i] = (-6L);
      l_1976++;
      for (p_39 = 17; (p_39 > (-23));
           p_39 = safe_sub_func_uint16_t_u_u(p_39, 2)) {
        uint32_t l_1981 = 18446744073709551615UL;
        return l_1981;
      }
      for (g_365 = 23; (g_365 < 25); g_365++) {
        int8_t l_1984 = 0L;
        int32_t l_1985[1];
        int16_t l_1986 = (-1L);
        uint32_t l_1987 = 8UL;
        uint16_t l_2009 = 8UL;
        int8_t l_2042 = 0x86L;
        int i;
        for (i = 0; i < 1; i++)
          l_1985[i] = 0L;
        l_1987++;
        if ((((safe_div_func_uint16_t_u_u(
                  (~((safe_div_func_int32_t_s_s(
                         (safe_add_func_int16_t_s_s(
                             (safe_add_func_int32_t_s_s(
                                 (g_1201 <
                                  (g_27[0] <=
                                   (safe_lshift_func_uint16_t_u_s(
                                       (0x5BL &&
                                        ((((p_38 & l_1985[0]) >=
                                           (~((safe_mul_func_uint16_t_u_u(
                                                  (safe_add_func_uint16_t_u_u(
                                                      (g_1089[1] <
                                                       (p_38 == 0x01A3L)),
                                                      (!(((+(p_40 >
                                                             4294967286UL)) <
                                                          4294967292UL) ||
                                                         p_38)))),
                                                  p_39)) &
                                              0x30L))) <= 4294967289UL) ==
                                         p_38)),
                                       l_1976)))),
                                 0xE2A6F02BL)),
                             l_1968)),
                         g_1526[5][0])) > p_39)),
                  l_1973[1])) < p_40) ^
             0x3A03C392L)) {
          int16_t l_2005 = 0xB05FL;
          int32_t l_2006 = 0xA52F5619L;
          int32_t l_2007 = 0xEB149D52L;
          int32_t l_2008 = 0xA3078835L;
          ++l_2009;
          l_2008 = (safe_rshift_func_int16_t_s_s(
              (safe_unary_minus_func_uint8_t_u((safe_add_func_int8_t_s_s(
                  ((safe_div_func_uint16_t_u_u(
                       (safe_lshift_func_int8_t_s_u(
                           (safe_add_func_uint8_t_u_u(
                               ((((((safe_sub_func_int16_t_s_s(
                                        (safe_add_func_int16_t_s_s(
                                            (safe_rshift_func_int16_t_s_u(
                                                (safe_sub_func_uint8_t_u_u(
                                                    255UL, (l_2005 < 6UL))),
                                                13)),
                                            (safe_sub_func_int16_t_s_s(
                                                (0x7DF5742DL == p_40),
                                                (safe_rshift_func_uint8_t_u_u(
                                                    (safe_mod_func_uint32_t_u_u(
                                                        (l_2004 ^
                                                         (safe_lshift_func_uint16_t_u_s(
                                                             9UL,
                                                             (((g_186 >=
                                                                (safe_sub_func_int8_t_s_s(
                                                                    ((l_1973
                                                                          [5] !=
                                                                      l_1973
                                                                          [1]) &
                                                                     g_463[0]),
                                                                    0xC8L))) !=
                                                               g_205) >=
                                                              p_38)))),
                                                        1L)),
                                                    l_1985[0])))))),
                                        0x0B21L)) >= l_2004) > l_2041) ||
                                  l_1986) |
                                 0xF741L) > 0x3737C347L),
                               p_38)),
                           3)),
                       l_2005)) == p_39),
                  (-4L))))),
              7));
        } else {
          uint32_t l_2043 = 0xE942FE7CL;
          l_2043++;
          g_2050[1] = (safe_sub_func_uint32_t_u_u(
              l_1970, ((safe_div_func_int32_t_s_s(8L, l_1968)) || g_365)));
        }
        for (g_186 = 9; (g_186 > 5);
             g_186 = safe_sub_func_int16_t_s_s(g_186, 1)) {
          int16_t l_2055 = 0x6523L;
          uint32_t l_2086[6][2] = {
              {0x13B548E2L, 4294967286UL}, {0x13B548E2L, 4294967286UL},
              {0x13B548E2L, 4294967286UL}, {0x13B548E2L, 4294967286UL},
              {0x13B548E2L, 4294967286UL}, {0x13B548E2L, 4294967286UL}};
          int32_t l_2122 = 0x00627251L;
          int i, j;
          for (l_1968 = 0; (l_1968 < (-7));
               l_1968 = safe_sub_func_int32_t_s_s(l_1968, 4)) {
            const uint32_t l_2058 = 0x3FDF85EEL;
            uint32_t l_2065 = 0x08341940L;
            if ((g_4 &&
                 ((l_2055 == l_1984) ==
                  (+((l_2042 <=
                      ((((safe_mod_func_uint32_t_u_u(
                             l_2058,
                             (safe_mod_func_int16_t_s_s(
                                 p_39, (safe_rshift_func_uint16_t_u_u(
                                           (safe_rshift_func_uint16_t_u_u(
                                               l_2058, ((-7L) != 0xC8D7L))),
                                           g_4)))))) &
                         l_2058) &
                        0x258C3106L) |
                       p_38)) &
                     l_1973[1]))))) {
              int32_t l_2083 = 0L;
              int32_t l_2085 = 0xD139BB90L;
              g_463[1] = l_2065;
              l_2066 = p_40;
              l_2085 |= (safe_div_func_int8_t_s_s(
                  (safe_mod_func_uint8_t_u_u(
                      (safe_add_func_uint32_t_u_u(
                          (g_186 ==
                           (safe_sub_func_int16_t_s_s(
                               (safe_mod_func_uint32_t_u_u(
                                   (g_185 ==
                                    (9UL ||
                                     ((l_2058 || g_4) &
                                      (safe_mul_func_uint16_t_u_u(
                                          (safe_lshift_func_int16_t_s_s(
                                              (p_38 &
                                               ((safe_rshift_func_uint16_t_u_u(
                                                    (((-2L) & l_1976) && 0UL),
                                                    p_38)) ||
                                                l_2083)),
                                              l_2084)),
                                          g_1526[5][0]))))),
                                   1UL)),
                               g_870))),
                          1UL)),
                      6UL)),
                  p_39));
            } else {
              int16_t l_2089 = 0x640AL;
              ++l_2086[5][1];
              if (l_2089)
                continue;
              g_1503 &=
                  ((0UL <=
                    ((safe_sub_func_int8_t_s_s(0x6EL, g_1089[1])) ==
                     ((safe_add_func_int16_t_s_s(
                          ((g_1089[2] &&
                            (safe_mod_func_uint16_t_u_u(
                                (safe_mod_func_int8_t_s_s(
                                    (((((safe_sub_func_uint32_t_u_u(
                                            (safe_rshift_func_uint8_t_u_s(
                                                (((!((safe_rshift_func_int16_t_s_u(
                                                         (g_2104 < g_493), 0)) &
                                                     (safe_add_func_uint16_t_u_u(
                                                         ((safe_unary_minus_func_int8_t_s((safe_div_func_int32_t_s_s(
                                                              (safe_mul_func_int16_t_s_s(
                                                                  (l_2112 !=
                                                                   ((safe_rshift_func_uint8_t_u_u(
                                                                        (safe_mul_func_uint8_t_u_u(
                                                                            (safe_add_func_uint16_t_u_u(
                                                                                g_27[5],
                                                                                ((((0L ||
                                                                                    l_2089) ||
                                                                                   p_38) >=
                                                                                  0x7FL) <
                                                                                 p_39))),
                                                                            l_1984)),
                                                                        l_2055)) &&
                                                                    l_2065)),
                                                                  l_2065)),
                                                              l_1974)))) &&
                                                          g_185),
                                                         p_38)))) < 0x06L) ==
                                                 255UL),
                                                g_870)),
                                            0x0353AFF4L)) == 0L) &
                                       251UL) >= g_1089[6]) &
                                     p_38),
                                    l_2004)),
                                l_2004))) != l_2119),
                          0x0962L)) |
                      g_205))) <= l_1986);
              l_1975 = l_2086[5][1];
            }
            l_2122 = (l_2065 > ((((safe_lshift_func_uint16_t_u_s(p_40, 12)) <=
                                  l_2058) >= 0xAEC227CCL) |
                                g_27[6]));
          }
          l_2122 =
              ((l_2066 == (safe_mul_func_uint16_t_u_u(
                              (g_205 <= (~((~p_39) >=
                                           (g_205 == (safe_sub_func_uint8_t_u_u(
                                                         0xE2L, l_1969)))))),
                              g_2050[1]))) &&
               0xA7L);
          g_870 =
              (((safe_mod_func_int8_t_s_s(
                    (safe_mod_func_uint32_t_u_u(l_1984, g_870)),
                    (safe_mul_func_uint16_t_u_u(
                        ((!(safe_sub_func_int8_t_s_s(
                             ((((g_27[2] ==
                                 (l_1969 &&
                                  ((1L == (l_1973[1] == p_38)) <=
                                   (((safe_div_func_int8_t_s_s(l_2009, p_40)) ^
                                     l_2122) == g_1201)))) &&
                                p_40) <= p_39) |
                              g_753),
                             4L))) &&
                         l_2041),
                        g_1503)))) &&
                l_1986) == 1UL);
          l_2122 = l_2086[5][1];
        }
        g_1503 &= (l_1970 >= (safe_rshift_func_int8_t_s_u(p_38, 3)));
      }
      l_2141++;
    }

    l_2239 &= (safe_sub_func_int32_t_s_s(
        (safe_mod_func_uint32_t_u_u(
            (((l_1968 >
               ((g_1503 &&
                 ((safe_mul_func_uint16_t_u_u(
                      l_2148,
                      (!(safe_mul_func_int16_t_s_s(
                          (1UL >=
                           (safe_sub_func_uint8_t_u_u(
                               (p_40 <=
                                ((safe_sub_func_uint8_t_u_u(
                                     (safe_div_func_uint8_t_u_u(
                                         l_2305,
                                         ((safe_div_func_uint16_t_u_u(
                                              p_40,
                                              (safe_sub_func_int8_t_s_s(
                                                  (safe_sub_func_int8_t_s_s(
                                                      ((((((((safe_lshift_func_int16_t_s_s(
                                                                 (((p_38 |
                                                                    (((4294967287UL <
                                                                       4294967292UL) >=
                                                                      4294967294UL) !=
                                                                     g_205)) <=
                                                                   6UL) &&
                                                                  l_2305),
                                                                 g_1526[6]
                                                                       [0])) |
                                                             l_2305) |
                                                            l_1975) <
                                                           0x3815L) &&
                                                          p_40) !=
                                                         0x961C2A05L) < 0UL) ||
                                                       g_1526[0][1]),
                                                      p_40)),
                                                  g_463[2])))) &
                                          l_2502))),
                                     g_1526[2][0])) < l_2320[2][0])),
                               p_40))),
                          8L))))) == p_38)) > 0xC4L)) |
              g_2503[1][3][2]) != 0x4C51L),
            p_38)),
        0xF5C9E3E9L));
    if ((safe_mod_func_uint16_t_u_u((0x51L < (g_1526[5][0] > p_39)),
                                    0xC606L))) {
      uint16_t l_2506 = 1UL;

    } else {
      int16_t l_2507 = 1L;
      int32_t l_2508 = 0xCBAAF1DBL;
      int32_t l_2509 = (-3L);
      int32_t l_2510 = (-2L);
      int32_t l_2512 = 1L;
      int32_t l_2513 = 1L;
      uint32_t l_2514 = 0xD187B0AEL;
      uint32_t l_2608 = 4294967291UL;
      uint8_t l_2637 = 0xF6L;
      int32_t l_2685 = 0xDFC38EAEL;
      uint8_t l_2686 = 0UL;
      int32_t l_2688[9][1] = {{0x8EC040ADL}, {0x8EC040ADL}, {0x8EC040ADL},
                              {0x8EC040ADL}, {0x8EC040ADL}, {0x8EC040ADL},
                              {0x8EC040ADL}, {0x8EC040ADL}, {0x8EC040ADL}};
      uint32_t l_2788 = 0xAC47B669L;
      uint8_t l_2800 = 255UL;
      int i, j;

      {
        int32_t l_1973[6];
        int32_t l_2004 = 0xF9C07A40L;
        int16_t l_2041 = 0L;
        uint32_t l_2084 = 1UL;
        uint8_t l_2112 = 0UL;
        uint8_t l_2119 = 255UL;
        uint32_t l_2141 = 0xCB9F49DEL;
        int i;
        for (i = 0; i < 6; i++)
          l_1973[i] = (-6L);
        l_1976++;
        for (p_39 = 17; (p_39 > (-23));
             p_39 = safe_sub_func_uint16_t_u_u(p_39, 2)) {
          uint32_t l_1981 = 18446744073709551615UL;
          return l_1981;
        }
        for (g_365 = 23; (g_365 < 25); g_365++) {
          int8_t l_1984 = 0L;
          int32_t l_1985[1];
          int16_t l_1986 = (-1L);
          uint32_t l_1987 = 8UL;
          uint16_t l_2009 = 8UL;
          int8_t l_2042 = 0x86L;
          int i;
          for (i = 0; i < 1; i++)
            l_1985[i] = 0L;
          l_1987++;
          if ((((safe_div_func_uint16_t_u_u(
                    (~((safe_div_func_int32_t_s_s(
                           (safe_add_func_int16_t_s_s(
                               (safe_add_func_int32_t_s_s(
                                   (g_1201 <
                                    (g_27[0] <=
                                     (safe_lshift_func_uint16_t_u_s(
                                         (0x5BL &&
                                          ((((p_38 & l_1985[0]) >=
                                             (~((safe_mul_func_uint16_t_u_u(
                                                    (safe_add_func_uint16_t_u_u(
                                                        (g_1089[1] <
                                                         (p_38 == 0x01A3L)),
                                                        (!(((+(p_40 >
                                                               4294967286UL)) <
                                                            4294967292UL) ||
                                                           p_38)))),
                                                    p_39)) &
                                                0x30L))) <= 4294967289UL) ==
                                           p_38)),
                                         l_1976)))),
                                   0xE2A6F02BL)),
                               l_1968)),
                           g_1526[5][0])) > p_39)),
                    l_1973[1])) < p_40) ^
               0x3A03C392L)) {
            int16_t l_2005 = 0xB05FL;
            int32_t l_2006 = 0xA52F5619L;
            int32_t l_2007 = 0xEB149D52L;
            int32_t l_2008 = 0xA3078835L;
            ++l_2009;
            l_2008 = (safe_rshift_func_int16_t_s_s(
                (safe_unary_minus_func_uint8_t_u((safe_add_func_int8_t_s_s(
                    ((safe_div_func_uint16_t_u_u(
                         (safe_lshift_func_int8_t_s_u(
                             (safe_add_func_uint8_t_u_u(
                                 ((((((safe_sub_func_int16_t_s_s(
                                          (safe_add_func_int16_t_s_s(
                                              (safe_rshift_func_int16_t_s_u(
                                                  (safe_sub_func_uint8_t_u_u(
                                                      255UL, (l_2005 < 6UL))),
                                                  13)),
                                              (safe_sub_func_int16_t_s_s(
                                                  (0x7DF5742DL == p_40),
                                                  (safe_rshift_func_uint8_t_u_u(
                                                      (safe_mod_func_uint32_t_u_u(
                                                          (l_2004 ^
                                                           (safe_lshift_func_uint16_t_u_s(
                                                               9UL,
                                                               (((g_186 >=
                                                                  (safe_sub_func_int8_t_s_s(
                                                                      ((l_1973
                                                                            [5] !=
                                                                        l_1973
                                                                            [1]) &
                                                                       g_463
                                                                           [0]),
                                                                      0xC8L))) !=
                                                                 g_205) >=
                                                                p_38)))),
                                                          1L)),
                                                      l_1985[0])))))),
                                          0x0B21L)) >= l_2004) > l_2041) ||
                                    l_1986) |
                                   0xF741L) > 0x3737C347L),
                                 p_38)),
                             3)),
                         l_2005)) == p_39),
                    (-4L))))),
                7));
          } else {
            uint32_t l_2043 = 0xE942FE7CL;
            l_2043++;
            g_2050[1] = (safe_sub_func_uint32_t_u_u(
                l_1970, ((safe_div_func_int32_t_s_s(8L, l_1968)) || g_365)));
          }
          for (g_186 = 9; (g_186 > 5);
               g_186 = safe_sub_func_int16_t_s_s(g_186, 1)) {
            int16_t l_2055 = 0x6523L;
            uint32_t l_2086[6][2] = {
                {0x13B548E2L, 4294967286UL}, {0x13B548E2L, 4294967286UL},
                {0x13B548E2L, 4294967286UL}, {0x13B548E2L, 4294967286UL},
                {0x13B548E2L, 4294967286UL}, {0x13B548E2L, 4294967286UL}};
            int32_t l_2122 = 0x00627251L;
            int i, j;
            for (l_1968 = 0; (l_1968 < (-7));
                 l_1968 = safe_sub_func_int32_t_s_s(l_1968, 4)) {
              const uint32_t l_2058 = 0x3FDF85EEL;
              uint32_t l_2065 = 0x08341940L;
              if ((g_4 &&
                   ((l_2055 == l_1984) ==
                    (+((l_2042 <=
                        ((((safe_mod_func_uint32_t_u_u(
                               l_2058,
                               (safe_mod_func_int16_t_s_s(
                                   p_39, (safe_rshift_func_uint16_t_u_u(
                                             (safe_rshift_func_uint16_t_u_u(
                                                 l_2058, ((-7L) != 0xC8D7L))),
                                             g_4)))))) &
                           l_2058) &
                          0x258C3106L) |
                         p_38)) &
                       l_1973[1]))))) {
                int32_t l_2083 = 0L;
                int32_t l_2085 = 0xD139BB90L;
                g_463[1] = l_2065;
                l_2066 = p_40;
                l_2085 |= (safe_div_func_int8_t_s_s(
                    (safe_mod_func_uint8_t_u_u(
                        (safe_add_func_uint32_t_u_u(
                            (g_186 ==
                             (safe_sub_func_int16_t_s_s(
                                 (safe_mod_func_uint32_t_u_u(
                                     (g_185 ==
                                      (9UL ||
                                       ((l_2058 || g_4) &
                                        (safe_mul_func_uint16_t_u_u(
                                            (safe_lshift_func_int16_t_s_s(
                                                (p_38 &
                                                 ((safe_rshift_func_uint16_t_u_u(
                                                      (((-2L) & l_1976) && 0UL),
                                                      p_38)) ||
                                                  l_2083)),
                                                l_2084)),
                                            g_1526[5][0]))))),
                                     1UL)),
                                 g_870))),
                            1UL)),
                        6UL)),
                    p_39));
              } else {
                int16_t l_2089 = 0x640AL;
                ++l_2086[5][1];
                if (l_2089)
                  continue;
                g_1503 &=
                    ((0UL <=
                      ((safe_sub_func_int8_t_s_s(0x6EL, g_1089[1])) ==
                       ((safe_add_func_int16_t_s_s(
                            ((g_1089[2] &&
                              (safe_mod_func_uint16_t_u_u(
                                  (safe_mod_func_int8_t_s_s(
                                      (((((safe_sub_func_uint32_t_u_u(
                                              (safe_rshift_func_uint8_t_u_s(
                                                  (((!((safe_rshift_func_int16_t_s_u(
                                                           (g_2104 < g_493),
                                                           0)) &
                                                       (safe_add_func_uint16_t_u_u(
                                                           ((safe_unary_minus_func_int8_t_s((safe_div_func_int32_t_s_s(
                                                                (safe_mul_func_int16_t_s_s(
                                                                    (l_2112 !=
                                                                     ((safe_rshift_func_uint8_t_u_u(
                                                                          (safe_mul_func_uint8_t_u_u(
                                                                              (safe_add_func_uint16_t_u_u(
                                                                                  g_27[5],
                                                                                  ((((0L ||
                                                                                      l_2089) ||
                                                                                     p_38) >=
                                                                                    0x7FL) <
                                                                                   p_39))),
                                                                              l_1984)),
                                                                          l_2055)) &&
                                                                      l_2065)),
                                                                    l_2065)),
                                                                l_1974)))) &&
                                                            g_185),
                                                           p_38)))) < 0x06L) ==
                                                   255UL),
                                                  g_870)),
                                              0x0353AFF4L)) == 0L) &
                                         251UL) >= g_1089[6]) &
                                       p_38),
                                      l_2004)),
                                  l_2004))) != l_2119),
                            0x0962L)) |
                        g_205))) <= l_1986);
                l_1975 = l_2086[5][1];
              }
              l_2122 = (l_2065 > ((((safe_lshift_func_uint16_t_u_s(p_40, 12)) <=
                                    l_2058) >= 0xAEC227CCL) |
                                  g_27[6]));
            }
            l_2122 = ((l_2066 ==
                       (safe_mul_func_uint16_t_u_u(
                           (g_205 <=
                            (~((~p_39) >= (g_205 == (safe_sub_func_uint8_t_u_u(
                                                        0xE2L, l_1969)))))),
                           g_2050[1]))) &&
                      0xA7L);
            g_870 =
                (((safe_mod_func_int8_t_s_s(
                      (safe_mod_func_uint32_t_u_u(l_1984, g_870)),
                      (safe_mul_func_uint16_t_u_u(
                          ((!(safe_sub_func_int8_t_s_s(
                               ((((g_27[2] ==
                                   (l_1969 && ((1L == (l_1973[1] == p_38)) <=
                                               (((safe_div_func_int8_t_s_s(
                                                     l_2009, p_40)) ^
                                                 l_2122) == g_1201)))) &&
                                  p_40) <= p_39) |
                                g_753),
                               4L))) &&
                           l_2041),
                          g_1503)))) &&
                  l_1986) == 1UL);
            l_2122 = l_2086[5][1];
          }
          g_1503 &= (l_1970 >= (safe_rshift_func_int8_t_s_u(p_38, 3)));
        }
        l_2141++;
      }

      for (p_40 = 0; (p_40 <= 2); p_40 += 1) {
        uint32_t l_2569 = 18446744073709551615UL;
        const int16_t l_2633 = 1L;
        int32_t l_2635 = 0x5EBB2312L;
        int16_t l_2718[8][3][5] = {
            {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
            {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
            {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
            {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
            {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
            {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
            {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
            {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
             {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}}};
        uint16_t l_2719 = 0UL;
        int32_t l_2840 = 0L;
        int i, j, k;

        l_2239 &= (safe_sub_func_int32_t_s_s(
            (safe_mod_func_uint32_t_u_u(
                (((l_1968 >
                   ((g_1503 &&
                     ((safe_mul_func_uint16_t_u_u(
                          l_2148,
                          (!(safe_mul_func_int16_t_s_s(
                              (1UL >=
                               (safe_sub_func_uint8_t_u_u(
                                   (p_40 <=
                                    ((safe_sub_func_uint8_t_u_u(
                                         (safe_div_func_uint8_t_u_u(
                                             l_2305,
                                             ((safe_div_func_uint16_t_u_u(
                                                  p_40,
                                                  (safe_sub_func_int8_t_s_s(
                                                      (safe_sub_func_int8_t_s_s(
                                                          ((((((((safe_lshift_func_int16_t_s_s(
                                                                     (((p_38 |
                                                                        (((4294967287UL <
                                                                           4294967292UL) >=
                                                                          4294967294UL) !=
                                                                         g_205)) <=
                                                                       6UL) &&
                                                                      l_2305),
                                                                     g_1526
                                                                         [6]
                                                                         [0])) |
                                                                 l_2305) |
                                                                l_1975) <
                                                               0x3815L) &&
                                                              p_40) !=
                                                             0x961C2A05L) <
                                                            0UL) ||
                                                           g_1526[0][1]),
                                                          p_40)),
                                                      g_463[2])))) &
                                              l_2502))),
                                         g_1526[2][0])) < l_2320[2][0])),
                                   p_40))),
                              8L))))) == p_38)) > 0xC4L)) |
                  g_2503[1][3][2]) != 0x4C51L),
                p_38)),
            0xF5C9E3E9L));

        l_2713[3][1][6]--;
        l_2779[i] = 0xB6CB34A7L;

        {
          uint32_t l_2569 = 18446744073709551615UL;
          const int16_t l_2633 = 1L;
          int32_t l_2635 = 0x5EBB2312L;
          int16_t l_2718[8][3][5] = {
              {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
              {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
              {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
              {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
              {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
              {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
              {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}},
              {{0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)},
               {0x19B8L, 0x22CAL, 0x537EL, 0xDEFCL, (-1L)}}};
          uint16_t l_2719 = 0UL;
          int32_t l_2840 = 0L;
          int i, j, k;
          if (g_463[(p_40 + 3)]) {
            uint16_t l_2547[5] = {0x0869L, 65535UL, 0x0869L, 65535UL, 0x0869L};
            int32_t l_2552 = 0x0B84A2DDL;
            int i;
            for (p_38 = 0; (p_38 <= 4); p_38 += 1) {
              uint32_t l_2546 = 4294967295UL;
              int i;
              g_1503 |=
                  (((p_38 != g_150) <=
                    (((((safe_div_func_int32_t_s_s(0x3D5E245FL, g_2050[0])) !=
                        (safe_sub_func_int8_t_s_s(
                            (safe_unary_minus_func_uint8_t_u((safe_rshift_func_int8_t_s_s(
                                l_2514,
                                (((0UL &
                                   ((safe_sub_func_int32_t_s_s(
                                        ((safe_lshift_func_uint8_t_u_u(
                                             (safe_add_func_int8_t_s_s(
                                                 ((safe_div_func_int16_t_s_s(
                                                      g_2050[1],
                                                      (safe_sub_func_int32_t_s_s(
                                                          ((safe_sub_func_int32_t_s_s(
                                                               (!((((safe_lshift_func_uint8_t_u_u(
                                                                        (safe_sub_func_uint16_t_u_u(
                                                                            (p_40 &
                                                                             (safe_sub_func_uint16_t_u_u(
                                                                                 ((safe_rshift_func_int8_t_s_s(
                                                                                      (safe_mod_func_int8_t_s_s(
                                                                                          ((g_365 ^
                                                                                            g_1526
                                                                                                [5]
                                                                                                [0]) ||
                                                                                           p_38),
                                                                                          8UL)),
                                                                                      7)) <
                                                                                  l_2511
                                                                                      [1]
                                                                                      [2]
                                                                                      [0]),
                                                                                 g_361))),
                                                                            p_40)),
                                                                        g_1089
                                                                            [6])) <
                                                                    g_1089[1]) |
                                                                   l_2162) ||
                                                                  g_150)),
                                                               0x768C1572L)) ^
                                                           9L),
                                                          l_2546)))) &&
                                                  l_2318),
                                                 6UL)),
                                             p_38)) ||
                                         p_38),
                                        g_27[6])) ^
                                    p_38)) < l_2547[2]) < g_185))))),
                            g_870))) >= l_2514) < g_463[(p_40 + 3)]) |
                     p_39)) |
                   l_2513);
            }
            l_2512 = (safe_div_func_int32_t_s_s(
                ((safe_mod_func_uint32_t_u_u(g_463[4], 0x2EBD8EB9L)) >
                 g_1089[1]),
                l_1975));
            for (g_365 = 4; (g_365 >= 1); g_365 -= 1) {
              l_2552 ^= 0x4B6C121EL;
            }
          } else {
            uint32_t l_2601 = 0UL;
            int32_t l_2634[4] = {(-9L), 0x2C626A1AL, (-9L), 0x2C626A1AL};
            int16_t l_2669 = (-7L);
            int i;
            for (g_1201 = 0; (g_1201 <= 4); g_1201 += 1) {
              l_1975 ^= (safe_rshift_func_int8_t_s_s(
                  (safe_sub_func_int16_t_s_s(
                      (safe_add_func_int8_t_s_s(
                          (((6L && (p_38 == (safe_add_func_uint32_t_u_u(
                                                (safe_lshift_func_uint8_t_u_s(
                                                    g_205, 1)),
                                                0x860CBDCFL)))) <=
                            (safe_lshift_func_uint8_t_u_u(
                                ((safe_div_func_int8_t_s_s(
                                     ((((safe_add_func_uint8_t_u_u(
                                            ((g_463[(p_40 + 3)] >= 0x9FL) >
                                             (0xFCAAL ==
                                              (4294967293UL ==
                                               (g_27[6] && l_2507)))),
                                            0xD9L)) <= 0x2CA7L) ||
                                       0xF3L) <= g_2104),
                                     0xFAL)) ||
                                 0xEF33L),
                                g_2050[1]))) &&
                           l_2507),
                          p_40)),
                      0xA680L)),
                  2));
              if (g_463[(p_40 + 3)])
                break;
              l_2569++;
              g_463[(p_40 + 3)] |= g_186;
            }
            g_870 |=
                ((((g_27[0] <=
                    ((g_2473 == p_39) <
                     (safe_mul_func_uint16_t_u_u(
                         (safe_rshift_func_int8_t_s_s(
                             ((((safe_lshift_func_int16_t_s_u(
                                    l_2569,
                                    (safe_mul_func_int16_t_s_s(
                                        ((((safe_unary_minus_func_int32_t_s((
                                               (0L <=
                                                ((((g_2050[1] <=
                                                    (safe_rshift_func_uint16_t_u_s(
                                                        0x4A06L, 8))) <=
                                                   g_362) &
                                                  (((((l_2162 == l_2508) ||
                                                      p_39) <
                                                     g_463[(p_40 + 3)]) |
                                                    l_2320[8][2]) > l_2226)) <=
                                                 g_185)) != 5L))) <= g_186) ^
                                          l_2163) <= p_38),
                                        0L)))) |
                                l_1976) == g_1089[1]) ^
                              g_205),
                             5)),
                         g_27[0])))) &
                   g_365) > 0x77344526L) |
                 0xC813L);
            if ((safe_mul_func_int16_t_s_s(
                    (((65533UL != 0xB88EL) >=
                      ((((((safe_sub_func_int8_t_s_s(
                               (safe_lshift_func_int8_t_s_u(
                                   (((safe_sub_func_int8_t_s_s(
                                         (((safe_mod_func_uint16_t_u_u(
                                               (safe_lshift_func_int8_t_s_u(
                                                   0xF7L, l_2601)),
                                               (~65534UL))) > 0xDE961BA8L) ^
                                          (safe_add_func_uint16_t_u_u(
                                              0xA43CL,
                                              (safe_div_func_int8_t_s_s(
                                                  ((safe_div_func_int32_t_s_s(
                                                       (g_870 == g_734),
                                                       0x73B21EAAL)) !=
                                                   0x2AE29BE3L),
                                                  l_2569))))),
                                         l_2608)) <= p_40) >= g_1089[8]),
                                   l_2601)),
                               2L)) &
                           1UL) ||
                          l_2608) >= l_2512) &&
                        p_38) < p_38)) == 1UL),
                    0xEA1AL))) {
              uint32_t l_2611[10][8][3] = {{{0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL}},
                                           {{0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL}},
                                           {{0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL}},
                                           {{0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL}},
                                           {{0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL}},
                                           {{0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL}},
                                           {{0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL}},
                                           {{0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL}},
                                           {{0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL}},
                                           {{0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL},
                                            {0UL, 0UL, 4294967295UL}}};
              int32_t l_2636 = 0x79DF7BCCL;
              int i, j, k;
              l_1970 ^=
                  ((l_2569 >=
                    (safe_lshift_func_uint16_t_u_u(
                        l_2611[5][1][0],
                        (safe_mod_func_int16_t_s_s(
                            ((safe_div_func_uint8_t_u_u(
                                 (safe_add_func_int32_t_s_s(
                                     (p_40 <= (0x56L && g_186)),
                                     (safe_unary_minus_func_uint32_t_u((safe_add_func_uint32_t_u_u(
                                         ((safe_add_func_uint8_t_u_u(
                                              (g_1526[5][0] >=
                                               (!(p_39 !=
                                                  (safe_div_func_uint8_t_u_u(
                                                      (safe_add_func_uint8_t_u_u(
                                                          0UL,
                                                          (((safe_mul_func_int16_t_s_s(
                                                                (((safe_sub_func_int8_t_s_s(
                                                                      (+(safe_div_func_uint32_t_u_u(
                                                                          (0xDFF6L >
                                                                           l_2601),
                                                                          g_185))),
                                                                      g_2503
                                                                          [1][3]
                                                                          [2])) |
                                                                  p_40) &
                                                                 p_40),
                                                                l_2508)) &&
                                                            g_4) |
                                                           65535UL))),
                                                      l_2633))))),
                                              9UL)) &&
                                          l_1968),
                                         g_1503)))))),
                                 5L)) >= p_40),
                            l_2608))))) &&
                   l_2148);
              l_2637--;
              g_463[5] = (safe_lshift_func_uint8_t_u_s(
                  ((safe_lshift_func_int16_t_s_u(
                       (((0x17L &
                          ((l_2634[3] &&
                            ((l_2635 ==
                              (0x9AF3875EL >=
                               (+((safe_rshift_func_int8_t_s_s(
                                      l_2634[0],
                                      (safe_mul_func_int16_t_s_s(
                                          (g_150 <
                                           (((safe_sub_func_uint32_t_u_u(
                                                 (safe_add_func_uint16_t_u_u(
                                                     g_1942,
                                                     (g_1089[3] !=
                                                      (0xA80BL | g_27[2])))),
                                                 l_2633)) == p_39) >= 0x88L)),
                                          g_1089[0])))) ^
                                  1UL)))) == p_40)) <= g_870)) != p_39) >=
                        0x25426310L),
                       p_40)) ||
                   l_2611[8][5][1]),
                  7));
            } else {
              l_1974 = (safe_div_func_int8_t_s_s(
                  g_1526[5][0],
                  (((((safe_unary_minus_func_uint8_t_u(
                          (safe_mul_func_int8_t_s_s(
                              (safe_div_func_int32_t_s_s(
                                  ((safe_add_func_uint8_t_u_u(
                                       (4L && (safe_div_func_uint8_t_u_u(
                                                  g_1089[1], l_2319))),
                                       (l_2608 &
                                        ((safe_div_func_int16_t_s_s(
                                             0L, (safe_mul_func_int8_t_s_s(
                                                     l_2319, p_39)))) ||
                                         ((p_39 <= p_38) >= g_463[0]))))) |
                                   0L),
                                  0x456E39A8L)),
                              0UL)))) ^
                      l_2461) &&
                     0x676EL) != 0L) &
                   0x07L)));
            }
            if ((0L > (safe_mod_func_int32_t_s_s(l_2669, g_734)))) {
              uint8_t l_2684 = 0xC4L;
              l_2686 &= (safe_lshift_func_uint8_t_u_u(
                  (safe_lshift_func_int8_t_s_u(
                      ((1L > g_493) >
                       (g_205 < (safe_rshift_func_int8_t_s_s((-2L), l_2635)))),
                      (safe_mul_func_int8_t_s_s(
                          (4294967295UL &&
                           (l_2633 >=
                            (safe_sub_func_int8_t_s_s(
                                ((l_2634[1] <=
                                  (((safe_div_func_int8_t_s_s(
                                        ((safe_div_func_int16_t_s_s(
                                             g_27[4], 0x842EL)) != l_2684),
                                        l_2685)) == l_2513) == 65535UL)) &
                                 l_2512),
                                g_205)))),
                          0L)))),
                  6));
              g_870 = l_2687;
              l_2635 |=
                  (p_40 >=
                   ((l_2688[1][0] &&
                     (((4294967292UL &&
                        (0x2682L <
                         ((((safe_lshift_func_int16_t_s_s(
                                (safe_mod_func_uint8_t_u_u(
                                    (safe_add_func_uint32_t_u_u(
                                        (safe_sub_func_int16_t_s_s(
                                            0L,
                                            ((((safe_mod_func_uint16_t_u_u(
                                                   65535UL,
                                                   (safe_mul_func_uint8_t_u_u(
                                                       (((((((((g_362 !=
                                                                (safe_mul_func_uint8_t_u_u(
                                                                    0x83L,
                                                                    (safe_div_func_uint16_t_u_u(
                                                                        ((safe_mul_func_uint8_t_u_u(
                                                                             ((safe_lshift_func_uint16_t_u_s(
                                                                                  (safe_sub_func_uint16_t_u_u(
                                                                                      (p_40 ^
                                                                                       g_2503
                                                                                           [1]
                                                                                           [3]
                                                                                           [2]),
                                                                                      l_1974)),
                                                                                  4)) >=
                                                                              l_2320
                                                                                  [3]
                                                                                  [3]),
                                                                             p_38)) ^
                                                                         p_39),
                                                                        l_2684))))) ||
                                                               65530UL) &&
                                                              p_38) >=
                                                             0x68E52B44L) &
                                                            l_2066) <=
                                                           g_27[2]) ^
                                                          0x12E9ABD9L) |
                                                         255UL) &
                                                        l_2513),
                                                       0x0EL)))) == 1L) &&
                                              (-1L)) == 65526UL))),
                                        5L)),
                                    1UL)),
                                13)) &
                            p_38) >= g_1089[1]) &
                          5UL))) &&
                       0UL) == 7L)) &&
                    0x894D3CDAL));
            } else {
              uint16_t l_2711 = 0xFCFFL;
              l_2635 = l_2711;
              l_2712 = 9L;
              if (l_2711)
                break;
              l_2508 = l_2569;
            }
          }
          l_2713[3][1][6]--;
          for (g_2104 = 4; (g_2104 >= 0); g_2104 -= 1) {
            int8_t l_2799 = (-10L);
            int32_t l_2821 = 0x4F666A07L;
            int32_t l_2822[5][2] = {{7L, 0x0D26AF51L},
                                    {7L, 0x0D26AF51L},
                                    {7L, 0x0D26AF51L},
                                    {7L, 0x0D26AF51L},
                                    {7L, 0x0D26AF51L}};
            uint16_t l_2823 = 1UL;
            const uint32_t l_2852 = 4294967293UL;
            int i, j;
            l_2320[2][2] = p_40;
            if ((safe_rshift_func_int8_t_s_s(l_2226, 3))) {
              l_2319 = (0x16D5L & p_39);
              --l_2719;
            } else {
              l_1975 = (safe_rshift_func_int8_t_s_u(
                  (g_1201 >=
                   (g_362 >
                    ((safe_sub_func_int8_t_s_s(
                         (safe_div_func_int8_t_s_s(
                             (0x6FL ^
                              (safe_sub_func_uint32_t_u_u(
                                  (l_1976 &
                                   (safe_lshift_func_uint16_t_u_s(
                                       ((!((((safe_add_func_int32_t_s_s(
                                                 (((p_40 >=
                                                    (safe_add_func_int8_t_s_s(
                                                        (g_463[4] <
                                                         ((safe_sub_func_uint8_t_u_u(
                                                              ((safe_rshift_func_int16_t_s_s(
                                                                   0x0CA0L,
                                                                   (safe_add_func_int8_t_s_s(
                                                                       (safe_add_func_int8_t_s_s(
                                                                           (g_1526
                                                                                [5]
                                                                                [0] &
                                                                            g_150),
                                                                           248UL)),
                                                                       g_186)))) ==
                                                               p_38),
                                                              l_2719)) ==
                                                          0x3299L)),
                                                        0x3BL))) == g_1942) ^
                                                  0x3043821BL),
                                                 l_2744)) <= p_40) |
                                            p_40) |
                                           4294967294UL)) < p_38),
                                       15))),
                                  0x8A9EE54FL))),
                             p_39)),
                         p_39)) |
                     249UL))),
                  g_493));
              g_463[0] = l_2685;
            }
            for (l_2608 = 0; (l_2608 <= 2); l_2608 += 1) {
              int i, j, k;
     l_2511
       [p_40]
       [(l_2608 + 5)][(l_2608 + 1)] = (5L <= (((safe_mod_func_int32_t_s_s ((safe_div_func_int8_t_s_s (((safe_sub_func_uint8_t_u_u ((safe_mod_func_int8_t_s_s (((l_2511[p_40][(p_40 + 5)][l_2608] ^ (safe_div_func_uint8_t_u_u ((((0xD4L | (safe_lshift_func_uint16_t_u_u ((safe_div_func_int32_t_s_s (((0xBE01L > ((l_2511[p_40][(l_2608 + 1)][p_40] >= (0xE3610BC0L != ((0x4D21D8B9L || (safe_sub_func_uint8_t_u_u (((l_2511[p_40][(g_2104 + 3)][p_40] & ((+(((safe_rshift_func_int8_t_s_s ((safe_sub_func_uint8_t_u_u ((((safe_mod_func_int16_t_s_s ((safe_sub_func_int8_t_s_s ((safe_mod_func_uint8_t_u_u ((((((safe_mul_func_int16_t_s_s (((((((safe_rshift_func_int16_t_s_u ((((g_2503[(p_40 + 1)][(p_40 + 2)][g_2104] >= 0x388CD7DFL) != g_27[6]) <= g_185), 4)) & l_2320[2][0]) | 0xE324L) == 0xDDL) > p_38) < 0UL), p_39)) >= 0x83L) && l_2511[1][2][0]) > l_2744) != l_2319), l_2744)), g_2503[(p_40 + 1)][(p_40 + 2)][g_2104])), g_734)) && 0xD5L) ^ l_2512), l_2777)), p_39)) || g_2473) < 0xA25AL)) & 0xA9L)) ^ g_2473), (-10L)))) && l_2718[3][0][1]))) > 65529UL)) < p_40), p_39)), 0))) & p_38) && g_2104), p_39))) >= 0x76B3B760L), l_2688[1][0])), g_1526[1][0])) == l_2778), p_40)), l_2779[0])) && g_205) && g_2780[1]));
            }
            if ((safe_sub_func_uint16_t_u_u(
                    (safe_sub_func_int32_t_s_s(
                        (((0x42L <= g_2780[0]) ||
                          (safe_add_func_uint16_t_u_u((!g_2787),
                                                      (65535UL > l_2788)))) ||
                         (((!((safe_div_func_uint8_t_u_u(
                                  (safe_mod_func_uint16_t_u_u(
                                      (safe_add_func_int32_t_s_s(
                                          1L, ((safe_rshift_func_int16_t_s_s(
                                                   l_2633, 15)) ^
                                               l_1976))),
                                      (safe_mod_func_uint32_t_u_u(
                                          (g_2787 | p_38), 0x466520E3L)))),
                                  g_1526[5][0])) != p_38)) != g_463[0]) |
                          0x2EL)),
                        l_2799)),
                    g_463[(p_40 + 3)]))) {
              int32_t l_2819 = 5L;
              l_2800 = g_186;
              g_365 = (safe_rshift_func_int8_t_s_s(
                  g_2503[1][3][2],
                  (((safe_div_func_uint32_t_u_u(
                        (g_1201 ||
                         ((((-6L) ||
                            (!((safe_add_func_int8_t_s_s(
                                   0L,
                                   ((safe_div_func_int16_t_s_s(
                                        (safe_sub_func_int8_t_s_s(
                                            0x02L,
                                            (0xD6175F41L ==
                                             ((safe_sub_func_uint8_t_u_u(
                                                  (safe_add_func_int32_t_s_s(
                                                      (p_39 ^
                                                       (safe_add_func_int8_t_s_s(
                                                           0L,
                                                           (safe_div_func_uint8_t_u_u(
                                                               p_38,
                                                               l_2819))))),
                                                      p_39)),
                                                  g_1526[5][0])) >=
                                              0x0392CCDFL)))),
                                        g_185)) &
                                    p_40))) >= g_2104))) &&
                           l_2799) > p_38)),
                        0xD097F6A0L)) == l_2779[1]) == l_2820)));
              --l_2823;
              l_2320[2][0] = l_2819;
            } else {
              return l_2305;
            }
            for (g_420 = 0; (g_420 <= 4); g_420 += 1) {
              int32_t l_2841 = (-1L);
              g_463[1] =
                  ((((safe_rshift_func_int8_t_s_u(
                         ((safe_lshift_func_uint16_t_u_s(
                              g_365,
                              (((g_1526[2][0] != (+g_753)) <
                                ((safe_lshift_func_uint8_t_u_s(
                                     ((safe_add_func_uint16_t_u_u(
                                          g_463[2],
                                          (l_2713[5][0][5] &&
                                           (safe_add_func_uint16_t_u_u(
                                               (l_2318 <=
                                                (0x52L &&
                                                 (l_2514 <
                                                  (safe_add_func_int8_t_s_s(
                                                      ((safe_div_func_int32_t_s_s(
                                                           (p_40 < g_2104),
                                                           g_2503[4][3][2])) &&
                                                       0xFF1B0484L),
                                                      p_38))))),
                                               g_150))))) == 0xC042L),
                                     0)) |
                                 p_40)) >= g_734))) != (-1L)),
                         l_2713[3][1][6])) ||
                     l_2840) >= l_2841) |
                   0L);
              l_2635 = ((+(p_39 < (0UL < g_2780[0]))) >
                        ((safe_div_func_int8_t_s_s(
                             (safe_sub_func_uint16_t_u_u(
                                 (p_38 |
                                  ((safe_mul_func_uint8_t_u_u(
                                       ((p_39 &&
                                         (safe_lshift_func_int16_t_s_u(
                                             (p_40 > (((((((l_2712 || p_39) &&
                                                           g_463[(p_40 + 3)]) &
                                                          g_734) ^
                                                         p_38) ||
                                                        l_2841) &&
                                                       l_2852) ^
                                                      g_463[(p_40 + 3)])),
                                             p_40))) <= l_2305),
                                       p_40)) |
                                   l_2320[2][0])),
                                 (-1L))),
                             l_2320[2][0])) == 4294967295UL));
            }
          }
          for (g_753 = 0; (g_753 <= 4); g_753 += 1) {
            uint16_t l_2873 = 0x6282L;
            g_870 =
                ((((((safe_mod_func_uint32_t_u_u(
                         g_205,
                         (safe_sub_func_int8_t_s_s(
                             g_2104,
                             (safe_add_func_int16_t_s_s(
                                 (0x380F5F28L !=
                                  (safe_rshift_func_uint8_t_u_u(
                                      ((safe_div_func_int32_t_s_s(0xC41B1AB9L,
                                                                  (-1L))) >=
                                       ((safe_div_func_int8_t_s_s(
                                            (((safe_sub_func_uint16_t_u_u(
                                                  (g_27[6] < (-1L)), p_40)) &
                                              ((safe_add_func_int32_t_s_s(
                                                   ((((((safe_rshift_func_uint8_t_u_u(
                                                            p_38, g_2104)) ^
                                                        0L) != p_38) |
                                                      l_2873) > l_2873) ^
                                                    p_39),
                                                   p_38)) &
                                               g_2050[1])) == 0L),
                                            255UL)) >= 0x0AL)),
                                      l_2687))),
                                 g_463[1])))))) |
                     l_2686) >= 0xECA3A8D8L) ||
                   0xB6EE66BEL) &
                  l_2800) < l_2509);
            for (g_870 = 0; (g_870 <= 4); g_870 += 1) {
              int8_t l_2906 = 0x1DL;
     g_365
       =
       ((((l_2685 | (safe_lshift_func_int8_t_s_u ((safe_lshift_func_int8_t_s_s (p_38, (safe_sub_func_uint8_t_u_u (g_1089[4], (249UL >= (safe_div_func_uint32_t_u_u ((((safe_add_func_uint8_t_u_u ((safe_add_func_uint8_t_u_u (((safe_add_func_uint32_t_u_u (0x90F228E3L, (((safe_mod_func_uint16_t_u_u ((safe_rshift_func_int8_t_s_u ((safe_rshift_func_uint16_t_u_u (g_1089[7], (safe_sub_func_int16_t_s_s (((((safe_mul_func_int16_t_s_s ((safe_mul_func_uint32_t_u_u (((((safe_sub_func_uint16_t_u_u (1UL, ((p_40 == (((((((((safe_rshift_func_int16_t_s_u ((safe_mul_func_uint8_t_u_u ((2UL || p_39), 248UL)), g_186)) || p_38) > g_493) < 0xF375L) & 4UL) ^ l_2873) < l_2906) == p_38) < p_38)) > g_27[6]))) != p_39) | l_2317) == 1L), 0L)), g_2050[0])) > (-1L)) == g_205) && l_1970), g_1526[5][0])))), 5)), l_2719)) != p_38) == 0L))) != 0x709192FEL), 0x97L)), l_2873)) || 1UL) > g_2780[1]), g_753))))))), l_2778))) && 3L) & 4294967292UL) > p_39);
     l_2510 = p_39;
     if (g_150)
       continue;
     return g_753;
            }
          }
        }

        l_2713[3][1][6]--;
      }
    }

  } else {
    uint16_t l_2929 = 0UL;
    return l_2929;
  }
  return g_1503;
}

static int16_t func_41(uint8_t p_42, int16_t p_43, uint32_t p_44, int16_t p_45,
                       int32_t p_46) {
  const int16_t l_1958 = (-1L);
  for (p_43 = 0; (p_43 <= 5); p_43 += 1) {
    int i;
    g_365 ^= (safe_sub_func_int16_t_s_s(
        ((safe_mod_func_uint32_t_u_u(
             ((g_463[p_43] &&
               ((safe_mod_func_int8_t_s_s(
                    (safe_sub_func_uint16_t_u_u(
                        (g_463[p_43] != p_42),
                        (safe_add_func_uint8_t_u_u(
                            (safe_rshift_func_uint16_t_u_s(
                                (safe_add_func_uint8_t_u_u(
                                    (p_42 > p_42),
                                    ((0x7167F99FL == g_870) == l_1958))),
                                13)),
                            (g_463[p_43] < g_734))))),
                    1UL)) == 5L)) &&
              g_420),
             p_44)) == g_4),
        l_1958));
    if (p_43)
      continue;
  }
  return p_42;
}

static int8_t func_49(int8_t p_50, uint16_t p_51, const uint32_t p_52) {
  int32_t l_1940[5];
  int32_t l_1941 = (-1L);
  int i;
  for (i = 0; i < 5; i++)
    l_1940[i] = 0L;
  for (g_185 = (-27); (g_185 < 16); ++g_185) {
    g_365 = g_362;
  }
  l_1941 = (~(safe_add_func_uint16_t_u_u(
      0xBEFCL,
      (((0x3DL == p_51) |
        (safe_lshift_func_int16_t_s_s(
            (safe_div_func_uint8_t_u_u(
                (safe_div_func_int32_t_s_s(
                    (safe_mul_func_uint16_t_u_u(
                        (9L ^
                         (p_52 ==
                          (safe_lshift_func_int8_t_s_u(
                              (safe_sub_func_int16_t_s_s(
                                  0x04D8L,
                                  (g_1089[5] <
                                   (!(~(safe_div_func_int16_t_s_s(
                                       (((((safe_mul_func_int8_t_s_s(
                                               (~(safe_div_func_int8_t_s_s(
                                                   (safe_add_func_int8_t_s_s(
                                                       l_1940[3], 255UL)),
                                                   g_27[1]))),
                                               l_1940[3])) ||
                                           p_52) > p_51) |
                                         255UL) <= l_1940[3]),
                                       0x4FE4L))))))),
                              1)))),
                        g_870)),
                    0x90B66C05L)),
                p_51)),
            p_51))) &&
       p_50))));
  return l_1940[1];
}

static const uint8_t func_57(uint8_t p_58, int8_t p_59, int8_t p_60,
                             int32_t p_61, int8_t p_62) {
  uint8_t l_834 = 0x81L;
  int32_t l_849 = 0L;
  int32_t l_850 = 1L;
  int32_t l_918 = 0xF9576AD6L;
  int8_t l_1113[1];
  int16_t l_1230 = 1L;
  int32_t l_1251 = 0x3A9B52D8L;
  int32_t l_1255 = 0xD59FCC4EL;
  int32_t l_1256 = 0x6BA866DFL;
  int32_t l_1260[10][9][2] = {{{0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L}},
                              {{0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L}},
                              {{0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L}},
                              {{0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L}},
                              {{0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L}},
                              {{0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L}},
                              {{0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L}},
                              {{0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L}},
                              {{0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L}},
                              {{0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L},
                               {0x754A2931L, 3L}}};
  int8_t l_1354[2][3] = {{0xC5L, 0xC5L, 0xB9L}, {0xC5L, 0xC5L, 0xB9L}};
  uint8_t l_1666[8];
  uint8_t l_1719 = 0UL;
  const int8_t l_1890 = 0xA7L;
  const uint16_t l_1891 = 65528UL;
  int i, j, k;
  for (i = 0; i < 1; i++)
    l_1113[i] = 0xA9L;
  for (i = 0; i < 8; i++)
    l_1666[i] = 0x20L;
  if ((safe_add_func_int32_t_s_s(
          (safe_lshift_func_uint8_t_u_s(
              ((!l_834) <=
               (g_361 &
                ((((safe_div_func_int8_t_s_s(
                       (((((safe_rshift_func_uint8_t_u_u(p_58, 3)) >=
                           ((safe_lshift_func_int16_t_s_s(
                                (safe_mul_func_uint8_t_u_u(
                                    (((((safe_sub_func_int8_t_s_s(
                                            0xA2L,
                                            ((((((safe_mul_func_uint16_t_u_u(
                                                     g_186,
                                                     ((255UL !=
                                                       (0x4C77029BL &&
                                                        (!((0x99F1L >=
                                                            ((+g_186) >=
                                                             g_463[0])) <=
                                                           l_834)))) <
                                                      l_834))) ^
                                                 g_753) != 6UL) < 0UL) ^
                                              l_834) ^
                                             l_849))) ^
                                        0xABL) &&
                                       0xEBL) < g_27[3]) < p_61),
                                    g_205)),
                                p_61)) < g_186)) <= 0UL) == g_186) != l_834),
                       g_186)) != g_493) &
                  0xF4L) < 5L))),
              3)),
          p_60))) {
    uint32_t l_851 = 0xA8E84D58L;
    int32_t l_928 = 2L;
    int32_t l_969 = 0xD8D385ABL;
    int32_t l_970 = (-1L);
    int32_t l_971 = 0L;
    int32_t l_974 = 9L;
    int32_t l_1034 = 6L;
    uint16_t l_1099[10][2] = {{0xDA5CL, 0xDA5CL}, {0xDA5CL, 0xDA5CL},
                              {0xDA5CL, 0xDA5CL}, {0xDA5CL, 0xDA5CL},
                              {0xDA5CL, 0xDA5CL}, {0xDA5CL, 0xDA5CL},
                              {0xDA5CL, 0xDA5CL}, {0xDA5CL, 0xDA5CL},
                              {0xDA5CL, 0xDA5CL}, {0xDA5CL, 0xDA5CL}};
    uint16_t l_1245 = 0UL;
    int32_t l_1257 = 0x1923BED1L;
    int32_t l_1259 = 8L;
    int32_t l_1262 = 0xEA8ED61FL;
    int32_t l_1263 = 0x00FB36C8L;
    int32_t l_1264[10];
    uint32_t l_1290 = 0x5FADAE7DL;
    int32_t l_1452[3];
    int32_t l_1476 = (-5L);
    uint16_t l_1527 = 4UL;
    int16_t l_1612 = 0xB231L;
    uint8_t l_1761 = 248UL;
    uint8_t l_1851 = 1UL;
    int i, j;
    for (i = 0; i < 10; i++)
      l_1264[i] = 0x7613354CL;
    for (i = 0; i < 3; i++)
      l_1452[i] = 0xBBFAC232L;
    --l_851;
    for (p_60 = 0; (p_60 <= 5); p_60 += 1) {
      int8_t l_968 = 0x1FL;
      const int8_t l_1108 = 0xC5L;
      uint32_t l_1169 = 1UL;
      int32_t l_1250 = 3L;
      int32_t l_1253 = (-1L);
      int32_t l_1258[2][9] = {
          {0xD261F19EL, (-4L), 5L, 5L, (-4L), 0xD261F19EL, (-4L), 5L, 5L},
          {0xD261F19EL, (-4L), 5L, 5L, (-4L), 0xD261F19EL, (-4L), 5L, 5L}};
      int16_t l_1505 = (-1L);
      uint32_t l_1506[7][8] = {
          {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
           4294967291UL, 4294967289UL, 0xC871E012L},
          {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
           4294967291UL, 4294967289UL, 0xC871E012L},
          {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
           4294967291UL, 4294967289UL, 0xC871E012L},
          {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
           4294967291UL, 4294967289UL, 0xC871E012L},
          {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
           4294967291UL, 4294967289UL, 0xC871E012L},
          {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
           4294967291UL, 4294967289UL, 0xC871E012L},
          {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
           4294967291UL, 4294967289UL, 0xC871E012L}};
      int32_t l_1529 = 0x4EB8D007L;
      int i, j;
      if ((safe_add_func_int32_t_s_s(0x45062FE5L, g_463[p_60]))) {
        int32_t l_973 = 0xDBBB214EL;
        int i;
        g_463[p_60] =
            ((safe_mul_func_int16_t_s_s(
                 0xFE61L,
                 ((0x6B5FL >=
                   ((safe_mod_func_uint8_t_u_u(
                        g_463[p_60],
                        (0UL ^ (safe_sub_func_int8_t_s_s(
                                   p_62, ((safe_sub_func_int16_t_s_s(l_851,
                                                                     0x26F0L)) >
                                          (0L <= 4294967290UL))))))) > p_60)) ^
                  0x753D1A51L))) &
             0x2A37BEC8L);
        for (g_186 = (-22); (g_186 <= 54); ++g_186) {
          uint32_t l_919[10][2] = {
              {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
              {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
              {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
              {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
              {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L}};
          int i, j;
          if ((safe_mod_func_int8_t_s_s(g_362, p_59))) {
            l_850 =
                ((0x34L &
                  (g_734 >= (safe_lshift_func_uint16_t_u_s(g_870, 9)))) >=
                 ((safe_div_func_int8_t_s_s(
                      (safe_lshift_func_uint16_t_u_u(
                          (p_59 &
                           (safe_add_func_int16_t_s_s(
                               ((!((safe_lshift_func_uint16_t_u_u(
                                       ((1L !=
                                         (((((l_834 !=
                                              (safe_lshift_func_uint16_t_u_u(
                                                  (g_4 ^
                                                   (!((safe_mul_func_int16_t_s_s(
                                                          (safe_lshift_func_uint8_t_u_u(
                                                              p_62, 6)),
                                                          (safe_mod_func_int8_t_s_s(
                                                              ((l_851 || p_62) <
                                                               g_365),
                                                              l_850)))) <=
                                                      65535UL))),
                                                  0))) |
                                             g_4) > l_851) <= p_62) ^
                                          g_753)) == g_463[p_60]),
                                       p_60)) <= 0x3B5BL)) > g_463[p_60]),
                               g_365))),
                          g_361)),
                      g_734)) != g_753));

            return g_493;
          } else {
            const int32_t l_903 = 5L;
            l_918 |= (safe_mod_func_int16_t_s_s(
                ((safe_add_func_uint32_t_u_u(
                     (safe_mul_func_int16_t_s_s(p_62, g_27[6])), g_734)) &&
                 l_851),
                (+(1L <
                   ((safe_add_func_uint32_t_u_u(
                        (((((safe_lshift_func_int8_t_s_u(
                                (safe_sub_func_int16_t_s_s(
                                    (safe_mod_func_int32_t_s_s(
                                        (safe_div_func_int16_t_s_s(
                                            ((l_903 ||
                                              (((safe_add_func_uint16_t_u_u(
                                                    ((safe_lshift_func_uint8_t_u_u(
                                                         p_59, 4)) !=
                                                     (~((safe_mul_func_int16_t_s_s(
                                                            (safe_mod_func_int32_t_s_s(
                                                                (safe_div_func_int16_t_s_s(
                                                                    ((safe_div_func_uint32_t_u_u(
                                                                         (+(g_362 ^
                                                                            (safe_mul_func_int16_t_s_s(
                                                                                ((-1L) &&
                                                                                 p_61),
                                                                                l_850)))),
                                                                         l_849)) |
                                                                     p_59),
                                                                    g_463[4])),
                                                                0x4C30C153L)),
                                                            l_851)) ||
                                                        g_186))),
                                                    g_362)) ||
                                                0x80L) &
                                               9L)) &&
                                             p_60),
                                            65534UL)),
                                        0xE9AD882DL)),
                                    g_493)),
                                6)) |
                            0x59L) < g_4) &
                          g_463[p_60]) != p_62),
                        l_903)) ||
                    p_60)))));
            l_928 =
                ((((((l_919[1][0] ^ g_361) ==
                     (9L |
                      (((safe_lshift_func_uint16_t_u_s(
                            ((p_62 < (~(safe_sub_func_int8_t_s_s(
                                         g_463[p_60],
                                         (l_918 | (safe_div_func_int8_t_s_s(
                                                      (safe_sub_func_int8_t_s_s(
                                                          (-1L), 0x5BL)),
                                                      l_918))))))) ||
                             p_58),
                            5)) &
                        p_61) |
                       g_463[p_60]))) != (-5L)) == g_463[2]) > p_58) &
                 g_186);
          }
          l_1113[i] = 0xA9L;
        }
        if (l_928) {
          p_61 = (((+(safe_div_func_int32_t_s_s(p_62, p_58))) != g_463[p_60]) >
                  ((safe_add_func_uint32_t_u_u(
                       ((g_420 || l_851) < g_150),
                       (((p_59 <= g_753) ==
                         (safe_add_func_int16_t_s_s(
                             (!(safe_lshift_func_int8_t_s_u(
                                 ((safe_lshift_func_int16_t_s_u(l_928, g_365)) ^
                                  g_186),
                                 7))),
                             g_463[p_60]))) &&
                        p_59))) >= g_362));
          for (p_61 = 0; (p_61 <= (-22));
               p_61 = safe_sub_func_uint32_t_u_u(p_61, 1)) {
            const uint32_t l_941 = 0xAC0362BEL;

            {
              const uint32_t l_941 = 0xAC0362BEL;
              if (l_941)
                break;
              g_463[p_60] = (-10L);
            }

            g_463[p_60] = (-10L);
          }
          for (g_362 = 1; (g_362 <= 5); g_362 += 1) {
            int i;
            if (g_463[g_362])
              break;
            p_61 = 0xFD45FC42L;
            l_849 = 0xCB027895L;
          }
        } else {
          uint8_t l_966 = 0x54L;
          int32_t l_967 = 0x418378F9L;
          int32_t l_972 = 0xDCA573D8L;
          uint16_t l_975 = 5UL;

          for (i = 0; i < 10; i++)
            l_1264[i] = 0x7613354CL;

          g_870 =
              ((safe_lshift_func_int8_t_s_u(
                   ((0x049DL ^
                     (safe_mul_func_uint16_t_u_u(
                         (safe_add_func_int32_t_s_s(
                             (safe_add_func_int32_t_s_s(
                                 (safe_mul_func_uint8_t_u_u(g_463[p_60], p_59)),
                                 (safe_lshift_func_int16_t_s_s(
                                     (g_463[2] &&
                                      (4294967295UL <
                                       ((safe_rshift_func_int8_t_s_s(
                                            (-1L),
                                            (((safe_add_func_int16_t_s_s(
                                                  (((safe_add_func_uint32_t_u_u(
                                                        ((safe_div_func_int32_t_s_s(
                                                             g_870,
                                                             (safe_add_func_int8_t_s_s(
                                                                 l_918, 2L)))) <
                                                         4294967288UL),
                                                        0x13E14289L)) &
                                                    p_62) ||
                                                   g_493),
                                                  0x36E5L)) != l_966) <=
                                             g_362))) < p_62))),
                                     l_834)))),
                             l_966)),
                         g_420))) <= l_966),
                   7)) ||
               g_463[0]);
          ++l_975;
          --l_851;
        }
      } else {
        uint32_t l_986[8][9][3] = {{{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                                   {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                                   {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                                   {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                                   {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                                   {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                                   {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                                   {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                                    {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}}};
        int i, j, k;

        {
          int32_t l_973 = 0xDBBB214EL;
          int i;
          g_463[p_60] =
              ((safe_mul_func_int16_t_s_s(
                   0xFE61L,
                   ((0x6B5FL >=
                     ((safe_mod_func_uint8_t_u_u(
                          g_463[p_60],
                          (0UL ^
                           (safe_sub_func_int8_t_s_s(
                               p_62,
                               ((safe_sub_func_int16_t_s_s(l_851, 0x26F0L)) >
                                (0L <= 4294967290UL))))))) > p_60)) ^
                    0x753D1A51L))) &
               0x2A37BEC8L);
          for (g_186 = (-22); (g_186 <= 54); ++g_186) {
            uint32_t l_919[10][2] = {
                {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L}};
            int i, j;
            if ((safe_mod_func_int8_t_s_s(g_362, p_59))) {
              l_850 =
                  ((0x34L &
                    (g_734 >= (safe_lshift_func_uint16_t_u_s(g_870, 9)))) >=
                   ((safe_div_func_int8_t_s_s(
                        (safe_lshift_func_uint16_t_u_u(
                            (p_59 &
                             (safe_add_func_int16_t_s_s(
                                 ((!((safe_lshift_func_uint16_t_u_u(
                                         ((1L !=
                                           (((((l_834 !=
                                                (safe_lshift_func_uint16_t_u_u(
                                                    (g_4 ^
                                                     (!((safe_mul_func_int16_t_s_s(
                                                            (safe_lshift_func_uint8_t_u_u(
                                                                p_62, 6)),
                                                            (safe_mod_func_int8_t_s_s(
                                                                ((l_851 ||
                                                                  p_62) <
                                                                 g_365),
                                                                l_850)))) <=
                                                        65535UL))),
                                                    0))) |
                                               g_4) > l_851) <= p_62) ^
                                            g_753)) == g_463[p_60]),
                                         p_60)) <= 0x3B5BL)) > g_463[p_60]),
                                 g_365))),
                            g_361)),
                        g_734)) != g_753));
              if (g_870)
                break;
              return g_493;
            } else {
              const int32_t l_903 = 5L;
              l_918 |= (safe_mod_func_int16_t_s_s(
                  ((safe_add_func_uint32_t_u_u(
                       (safe_mul_func_int16_t_s_s(p_62, g_27[6])), g_734)) &&
                   l_851),
                  (+(1L <
                     ((safe_add_func_uint32_t_u_u(
                          (((((safe_lshift_func_int8_t_s_u(
                                  (safe_sub_func_int16_t_s_s(
                                      (safe_mod_func_int32_t_s_s(
                                          (safe_div_func_int16_t_s_s(
                                              ((l_903 ||
                                                (((safe_add_func_uint16_t_u_u(
                                                      ((safe_lshift_func_uint8_t_u_u(
                                                           p_59, 4)) !=
                                                       (~((safe_mul_func_int16_t_s_s(
                                                              (safe_mod_func_int32_t_s_s(
                                                                  (safe_div_func_int16_t_s_s(
                                                                      ((safe_div_func_uint32_t_u_u(
                                                                           (+(g_362 ^
                                                                              (safe_mul_func_int16_t_s_s(
                                                                                  ((-1L) &&
                                                                                   p_61),
                                                                                  l_850)))),
                                                                           l_849)) |
                                                                       p_59),
                                                                      g_463
                                                                          [4])),
                                                                  0x4C30C153L)),
                                                              l_851)) ||
                                                          g_186))),
                                                      g_362)) ||
                                                  0x80L) &
                                                 9L)) &&
                                               p_60),
                                              65534UL)),
                                          0xE9AD882DL)),
                                      g_493)),
                                  6)) |
                              0x59L) < g_4) &
                            g_463[p_60]) != p_62),
                          l_903)) ||
                      p_60)))));
              l_928 =
                  ((((((l_919[1][0] ^ g_361) ==
                       (9L | (((safe_lshift_func_uint16_t_u_s(
                                   ((p_62 <
                                     (~(safe_sub_func_int8_t_s_s(
                                         g_463[p_60],
                                         (l_918 | (safe_div_func_int8_t_s_s(
                                                      (safe_sub_func_int8_t_s_s(
                                                          (-1L), 0x5BL)),
                                                      l_918))))))) ||
                                    p_58),
                                   5)) &
                               p_61) |
                              g_463[p_60]))) != (-5L)) == g_463[2]) > p_58) &
                   g_186);
            }
          }
          if (l_928) {
            p_61 =
                (((+(safe_div_func_int32_t_s_s(p_62, p_58))) != g_463[p_60]) >
                 ((safe_add_func_uint32_t_u_u(
                      ((g_420 || l_851) < g_150),
                      (((p_59 <= g_753) ==
                        (safe_add_func_int16_t_s_s(
                            (!(safe_lshift_func_int8_t_s_u(
                                ((safe_lshift_func_int16_t_s_u(l_928, g_365)) ^
                                 g_186),
                                7))),
                            g_463[p_60]))) &&
                       p_59))) >= g_362));
            for (p_61 = 0; (p_61 <= (-22));
                 p_61 = safe_sub_func_uint32_t_u_u(p_61, 1)) {
              const uint32_t l_941 = 0xAC0362BEL;
              if (l_941)
                break;
              g_463[p_60] = (-10L);
            }
            for (g_362 = 1; (g_362 <= 5); g_362 += 1) {
              int i;
              if (g_463[g_362])
                break;
              p_61 = 0xFD45FC42L;
              l_849 = 0xCB027895L;
            }
          } else {
            uint8_t l_966 = 0x54L;
            int32_t l_967 = 0x418378F9L;
            int32_t l_972 = 0xDCA573D8L;
            uint16_t l_975 = 5UL;
            if (l_851)
              break;
            g_870 =
                ((safe_lshift_func_int8_t_s_u(
                     ((0x049DL ^
                       (safe_mul_func_uint16_t_u_u(
                           (safe_add_func_int32_t_s_s(
                               (safe_add_func_int32_t_s_s(
                                   (safe_mul_func_uint8_t_u_u(g_463[p_60],
                                                              p_59)),
                                   (safe_lshift_func_int16_t_s_s(
                                       (g_463[2] &&
                                        (4294967295UL <
                                         ((safe_rshift_func_int8_t_s_s(
                                              (-1L),
                                              (((safe_add_func_int16_t_s_s(
                                                    (((safe_add_func_uint32_t_u_u(
                                                          ((safe_div_func_int32_t_s_s(
                                                               g_870,
                                                               (safe_add_func_int8_t_s_s(
                                                                   l_918,
                                                                   2L)))) <
                                                           4294967288UL),
                                                          0x13E14289L)) &
                                                      p_62) ||
                                                     g_493),
                                                    0x36E5L)) != l_966) <=
                                               g_362))) < p_62))),
                                       l_834)))),
                               l_966)),
                           g_420))) <= l_966),
                     7)) ||
                 g_463[0]);
            ++l_975;
          }
        }

        for (l_971 = (-14); (l_971 <= 26); l_971++) {

          g_463[0] = g_753;
        }
        if (p_61) {
          uint32_t l_1114 = 18446744073709551615UL;

          g_463[0] = p_58;

          l_1264[i] = 0x7613354CL;

          g_365 |=
              ((((((((p_61 >=
                      (l_1034 <=
                       (((0x95L <= g_753) |
                         (safe_rshift_func_uint16_t_u_u(
                             ((safe_sub_func_int16_t_s_s(
                                  l_1108,
                                  (1L || (safe_mod_func_uint32_t_u_u(
                                             (safe_lshift_func_int16_t_s_s(
                                                 l_986[1][3][1], 9)),
                                             7L))))) <
                              ((g_420 > g_186) && p_61)),
                             0))) > p_58))) &&
                     l_1113[0]) <= 0x5C091B7AL) >= g_4) == (-1L)) > g_493) &
                0x8E3F9787L) <= l_1114);
          if ((safe_add_func_int32_t_s_s(0x45062FE5L, g_463[p_60]))) {
            int32_t l_973 = 0xDBBB214EL;
            int i;
            g_463[p_60] =
                ((safe_mul_func_int16_t_s_s(
                     0xFE61L,
                     ((0x6B5FL >=
                       ((safe_mod_func_uint8_t_u_u(
                            g_463[p_60],
                            (0UL ^
                             (safe_sub_func_int8_t_s_s(
                                 p_62,
                                 ((safe_sub_func_int16_t_s_s(l_851, 0x26F0L)) >
                                  (0L <= 4294967290UL))))))) > p_60)) ^
                      0x753D1A51L))) &
                 0x2A37BEC8L);
            for (g_186 = (-22); (g_186 <= 54); ++g_186) {
              uint32_t l_919[10][2] = {
                  {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                  {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                  {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                  {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                  {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L}};
              int i, j;
              if ((safe_mod_func_int8_t_s_s(g_362, p_59))) {
                l_850 =
                    ((0x34L &
                      (g_734 >= (safe_lshift_func_uint16_t_u_s(g_870, 9)))) >=
                     ((safe_div_func_int8_t_s_s(
                          (safe_lshift_func_uint16_t_u_u(
                              (p_59 &
                               (safe_add_func_int16_t_s_s(
                                   ((!((safe_lshift_func_uint16_t_u_u(
                                           ((1L !=
                                             (((((l_834 !=
                                                  (safe_lshift_func_uint16_t_u_u(
                                                      (g_4 ^
                                                       (!((safe_mul_func_int16_t_s_s(
                                                              (safe_lshift_func_uint8_t_u_u(
                                                                  p_62, 6)),
                                                              (safe_mod_func_int8_t_s_s(
                                                                  ((l_851 ||
                                                                    p_62) <
                                                                   g_365),
                                                                  l_850)))) <=
                                                          65535UL))),
                                                      0))) |
                                                 g_4) > l_851) <= p_62) ^
                                              g_753)) == g_463[p_60]),
                                           p_60)) <= 0x3B5BL)) > g_463[p_60]),
                                   g_365))),
                              g_361)),
                          g_734)) != g_753));
                if (g_870)
                  break;
                return g_493;
              } else {
                const int32_t l_903 = 5L;
                l_918 |= (safe_mod_func_int16_t_s_s(
                    ((safe_add_func_uint32_t_u_u(
                         (safe_mul_func_int16_t_s_s(p_62, g_27[6])), g_734)) &&
                     l_851),
                    (+(1L <
                       ((safe_add_func_uint32_t_u_u(
                            (((((safe_lshift_func_int8_t_s_u(
                                    (safe_sub_func_int16_t_s_s(
                                        (safe_mod_func_int32_t_s_s(
                                            (safe_div_func_int16_t_s_s(
                                                ((l_903 ||
                                                  (((safe_add_func_uint16_t_u_u(
                                                        ((safe_lshift_func_uint8_t_u_u(
                                                             p_59, 4)) !=
                                                         (~((safe_mul_func_int16_t_s_s(
                                                                (safe_mod_func_int32_t_s_s(
                                                                    (safe_div_func_int16_t_s_s(
                                                                        ((safe_div_func_uint32_t_u_u(
                                                                             (+(g_362 ^
                                                                                (safe_mul_func_int16_t_s_s(
                                                                                    ((-1L) &&
                                                                                     p_61),
                                                                                    l_850)))),
                                                                             l_849)) |
                                                                         p_59),
                                                                        g_463
                                                                            [4])),
                                                                    0x4C30C153L)),
                                                                l_851)) ||
                                                            g_186))),
                                                        g_362)) ||
                                                    0x80L) &
                                                   9L)) &&
                                                 p_60),
                                                65534UL)),
                                            0xE9AD882DL)),
                                        g_493)),
                                    6)) |
                                0x59L) < g_4) &
                              g_463[p_60]) != p_62),
                            l_903)) ||
                        p_60)))));
                l_928 =
                    ((((((l_919[1][0] ^ g_361) ==
                         (9L |
                          (((safe_lshift_func_uint16_t_u_s(
                                ((p_62 <
                                  (~(safe_sub_func_int8_t_s_s(
                                      g_463[p_60],
                                      (l_918 | (safe_div_func_int8_t_s_s(
                                                   (safe_sub_func_int8_t_s_s(
                                                       (-1L), 0x5BL)),
                                                   l_918))))))) ||
                                 p_58),
                                5)) &
                            p_61) |
                           g_463[p_60]))) != (-5L)) == g_463[2]) > p_58) &
                     g_186);
              }
            }
            if (l_928) {
              p_61 =
                  (((+(safe_div_func_int32_t_s_s(p_62, p_58))) != g_463[p_60]) >
                   ((safe_add_func_uint32_t_u_u(
                        ((g_420 || l_851) < g_150),
                        (((p_59 <= g_753) ==
                          (safe_add_func_int16_t_s_s(
                              (!(safe_lshift_func_int8_t_s_u(
                                  ((safe_lshift_func_int16_t_s_u(l_928,
                                                                 g_365)) ^
                                   g_186),
                                  7))),
                              g_463[p_60]))) &&
                         p_59))) >= g_362));
              for (p_61 = 0; (p_61 <= (-22));
                   p_61 = safe_sub_func_uint32_t_u_u(p_61, 1)) {
                const uint32_t l_941 = 0xAC0362BEL;
                if (l_941)
                  break;
                g_463[p_60] = (-10L);
              }
              for (g_362 = 1; (g_362 <= 5); g_362 += 1) {
                int i;
                if (g_463[g_362])
                  break;
                p_61 = 0xFD45FC42L;
                l_849 = 0xCB027895L;
              }
            } else {
              uint8_t l_966 = 0x54L;
              int32_t l_967 = 0x418378F9L;
              int32_t l_972 = 0xDCA573D8L;
              uint16_t l_975 = 5UL;
              if (l_851)
                break;
              g_870 =
                  ((safe_lshift_func_int8_t_s_u(
                       ((0x049DL ^
                         (safe_mul_func_uint16_t_u_u(
                             (safe_add_func_int32_t_s_s(
                                 (safe_add_func_int32_t_s_s(
                                     (safe_mul_func_uint8_t_u_u(g_463[p_60],
                                                                p_59)),
                                     (safe_lshift_func_int16_t_s_s(
                                         (g_463[2] &&
                                          (4294967295UL <
                                           ((safe_rshift_func_int8_t_s_s(
                                                (-1L),
                                                (((safe_add_func_int16_t_s_s(
                                                      (((safe_add_func_uint32_t_u_u(
                                                            ((safe_div_func_int32_t_s_s(
                                                                 g_870,
                                                                 (safe_add_func_int8_t_s_s(
                                                                     l_918,
                                                                     2L)))) <
                                                             4294967288UL),
                                                            0x13E14289L)) &
                                                        p_62) ||
                                                       g_493),
                                                      0x36E5L)) != l_966) <=
                                                 g_362))) < p_62))),
                                         l_834)))),
                                 l_966)),
                             g_420))) <= l_966),
                       7)) ||
                   g_463[0]);
              ++l_975;
            }
          } else {
            uint32_t l_986[8][9][3] = {
                {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                 {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}}};
            int i, j, k;
            if ((safe_sub_func_uint16_t_u_u(
                    0x8860L,
                    (safe_sub_func_uint16_t_u_u(
                        g_365,
                        (safe_add_func_uint16_t_u_u(
                            (0x2DL <= (safe_lshift_func_uint16_t_u_u(
                                          l_986[1][3][1], 6))),
                            (((((g_27[6] ^
                                 (safe_add_func_int8_t_s_s(
                                     (safe_sub_func_uint8_t_u_u(
                                         (safe_sub_func_int8_t_s_s(
                                             ((l_968 !=
                                               ((0x97L &&
                                                 (p_58 !=
                                                  (safe_sub_func_uint8_t_u_u(
                                                      (safe_mod_func_uint8_t_u_u(
                                                          ((6L | p_60) <=
                                                           l_986[1][6][0]),
                                                          l_850)),
                                                      0x9AL)))) != 7L)) ^
                                              l_968),
                                             p_61)),
                                         p_59)),
                                     g_185))) == 6UL) == 0x0060DD85L) &&
                              0x27L) > 255UL)))))))) {
              g_365 |= (safe_unary_minus_func_uint16_t_u((p_58 > l_969)));
            } else {
              uint8_t l_1060 = 0x5CL;
              for (g_361 = 0; (g_361 >= 53);
                   g_361 = safe_add_func_uint16_t_u_u(g_361, 7)) {
                uint16_t l_1022 = 65531UL;
                g_463[p_60] = 2L;
                g_870 = (safe_mul_func_uint8_t_u_u(
                    (safe_mod_func_int8_t_s_s(g_753, p_59)), g_365));
                g_463[3] |=
                    (((safe_lshift_func_int8_t_s_s(
                          (-1L),
                          ((~((safe_div_func_int8_t_s_s(
                                  p_62,
                                  (safe_rshift_func_int8_t_s_u(
                                      (safe_add_func_int32_t_s_s(
                                          (safe_add_func_uint32_t_u_u(
                                              0UL,
                                              ((safe_mod_func_uint8_t_u_u(
                                                   (safe_lshift_func_int16_t_s_s(
                                                       g_420, 6)),
                                                   (safe_rshift_func_uint16_t_u_u(
                                                       (g_27[6] < p_61),
                                                       (safe_lshift_func_int8_t_s_s(
                                                           ((p_60 >
                                                             ((g_753 >=
                                                               g_870) <=
                                                              l_986[4][1]
                                                                   [0])) !=
                                                            l_1022),
                                                           l_834)))))) |
                                               0xFDL))),
                                          0xDFD5D61BL)),
                                      5)))) &
                              l_918)) >= g_27[5]))) &
                      (-1L)) <= 4294967295UL);
                p_61 =
                    (0x1B5EF209L |
                     (safe_unary_minus_func_uint8_t_u(
                         (65535UL <=
                          (0x40L <
                           (safe_add_func_int32_t_s_s(
                               l_849,
                               (safe_rshift_func_int8_t_s_u(
                                   ((safe_sub_func_uint16_t_u_u(
                                        (safe_div_func_uint16_t_u_u(
                                            g_493, (safe_mul_func_uint8_t_u_u(
                                                       (l_986[0][4][1] != 5L),
                                                       l_1034)))),
                                        (safe_sub_func_uint8_t_u_u(
                                            (safe_mod_func_int16_t_s_s(0x1AAAL,
                                                                       g_150)),
                                            0x03L)))) <= 0L),
                                   g_361)))))))));
              }
              l_1060 =
                  (((safe_sub_func_int32_t_s_s(p_58, (-5L))) ||
                    (safe_add_func_int32_t_s_s(
                        (safe_lshift_func_int16_t_s_u(p_61, 14)),
                        (((safe_mod_func_uint8_t_u_u(
                              (!((safe_add_func_int16_t_s_s(
                                     (p_59 |
                                      (safe_lshift_func_int8_t_s_u(
                                          (safe_rshift_func_uint16_t_u_s(
                                              0x29D9L,
                                              (safe_div_func_uint32_t_u_u(
                                                  0UL, g_753)))),
                                          0))),
                                     (safe_unary_minus_func_uint32_t_u(
                                         (l_968 !=
                                          (safe_rshift_func_int8_t_s_u(
                                              (safe_sub_func_int8_t_s_s(
                                                  (l_968 ^ 0x0044B4B1L), p_61)),
                                              6))))))) |
                                 0x23L)),
                              0x5DL)) ||
                          0xDC5166B7L) ^
                         0x188DL)))) > p_60);
              p_61 =
                  ((((safe_mul_func_int8_t_s_s(
                         ((+(g_185 <
                             (safe_sub_func_int8_t_s_s(
                                 l_851,
                                 ((safe_mul_func_uint16_t_u_u(
                                      (((safe_rshift_func_uint8_t_u_u(
                                            ((safe_lshift_func_int8_t_s_s(
                                                 p_61,
                                                 ((safe_mod_func_uint8_t_u_u(
                                                      ((7UL &
                                                        ((((safe_lshift_func_uint16_t_u_u(
                                                               (safe_add_func_uint8_t_u_u(
                                                                   0x1EL,
                                                                   0x44L)),
                                                               ((safe_lshift_func_uint16_t_u_u(
                                                                    (safe_div_func_uint32_t_u_u(
                                                                        (((safe_div_func_uint32_t_u_u(
                                                                              ((g_493 ^
                                                                                (safe_mul_func_int8_t_s_s(
                                                                                    ((safe_lshift_func_uint8_t_u_u(
                                                                                         ((safe_sub_func_uint32_t_u_u(
                                                                                              4294967294UL,
                                                                                              (0x617AL >=
                                                                                               0xF678L))) !=
                                                                                          g_362),
                                                                                         p_61)) &&
                                                                                     4294967295UL),
                                                                                    g_463
                                                                                        [0]))) <=
                                                                               p_60),
                                                                              l_850)) &
                                                                          0UL) <=
                                                                         g_493),
                                                                        4294967292UL)),
                                                                    11)) <
                                                                p_61))) ^
                                                           l_968) == l_971) &&
                                                         l_986[0][1][2])) ==
                                                       p_58),
                                                      0x93L)) > p_60))) ==
                                             p_58),
                                            3)) <= l_834) >= g_186),
                                      g_185)) == l_850))))) ||
                          0xB5CAL),
                         g_27[6])) >= g_753) > p_62) == 0UL);
              if (g_1089[1])
                continue;
            }
            for (l_971 = (-14); (l_971 <= 26); l_971++) {
              l_928 &= (safe_unary_minus_func_uint16_t_u(
                  (g_463[0] ==
                   ((safe_add_func_uint16_t_u_u(
                        (((safe_div_func_uint16_t_u_u(
                              (0L < (safe_mod_func_uint16_t_u_u(l_1099[9][1],
                                                                g_463[p_60]))),
                              (safe_add_func_int16_t_s_s(
                                  (g_734 |
                                   ((p_58 < (0x7CL && 0x56L)) ^
                                    (((((p_59 || l_834) && p_59) < g_27[6]) &&
                                      l_986[1][3][1]) ^
                                     7L))),
                                  p_62)))) < l_918) ||
                         0xE8L),
                        l_834)) <= p_60))));
              g_463[0] = g_753;
            }
            if (p_61) {
              uint32_t l_1114 = 18446744073709551615UL;
              g_463[0] = p_58;
              l_928 |= (safe_rshift_func_uint16_t_u_u(p_58, 6));
              g_365 |=
                  ((((((((p_61 >=
                          (l_1034 <=
                           (((0x95L <= g_753) |
                             (safe_rshift_func_uint16_t_u_u(
                                 ((safe_sub_func_int16_t_s_s(
                                      l_1108,
                                      (1L || (safe_mod_func_uint32_t_u_u(
                                                 (safe_lshift_func_int16_t_s_s(
                                                     l_986[1][3][1], 9)),
                                                 7L))))) <
                                  ((g_420 > g_186) && p_61)),
                                 0))) > p_58))) &&
                         l_1113[0]) <= 0x5C091B7AL) >= g_4) == (-1L)) > g_493) &
                    0x8E3F9787L) <= l_1114);
            } else {
              uint8_t l_1120 = 0x1EL;
              int32_t l_1160 = 0x9C031653L;
              p_61 = (safe_mul_func_uint8_t_u_u(
                  (g_734 !=
                   (((-5L) || ((safe_unary_minus_func_uint16_t_u(l_849)) |
                               ((safe_div_func_int8_t_s_s(p_60, l_1120)) >=
                                0x6DL))) < l_1120)),
                  (safe_rshift_func_uint8_t_u_s(
                      (((safe_sub_func_int32_t_s_s(
                            l_1113[0], (251UL ^ 0xDFL))) == g_870) > l_918),
                      6))));
              if (((((safe_sub_func_int8_t_s_s(
                         (((0x4AL == (safe_lshift_func_int16_t_s_u(
                                         (l_986[2][1][1] || p_59), 2))) &
                           ((safe_unary_minus_func_int8_t_s(
                                (safe_div_func_uint8_t_u_u(
                                    ((safe_sub_func_uint16_t_u_u(
                                         g_185,
                                         ((safe_mod_func_uint8_t_u_u(
                                              l_986[1][3][1],
                                              (((g_493 >
                                                 (0x56L <
                                                  (safe_sub_func_int8_t_s_s(
                                                      l_1113[0], 0x65L)))) >=
                                                0x83L) &
                                               l_1120))) |
                                          0x8E174AC1L))) ||
                                     1UL),
                                    g_420)))) <= g_734)) < g_362),
                         g_186)) > l_834) ||
                    p_60) != l_1099[9][1])) {
                p_61 = g_1089[1];
              } else {
                g_463[5] = (p_59 ^ p_62);
              }
              g_870 &=
                  (((((((safe_lshift_func_int8_t_s_s(
                            (safe_sub_func_int8_t_s_s(
                                ((safe_sub_func_uint8_t_u_u(
                                     5UL,
                                     (safe_sub_func_uint16_t_u_u(
                                         ((g_362 &
                                           ((safe_rshift_func_int8_t_s_u(
                                                ((safe_sub_func_int8_t_s_s(
                                                     (safe_sub_func_uint32_t_u_u(
                                                         (safe_add_func_uint8_t_u_u(
                                                             (safe_lshift_func_int16_t_s_s(
                                                                 l_974, 4)),
                                                             g_493)),
                                                         l_1120)),
                                                     0x3BL)) ==
                                                 (((safe_sub_func_uint16_t_u_u(
                                                       p_59, (-2L))) <
                                                   0x3A956D3AL) &
                                                  p_58)),
                                                2)) == g_1089[3])) == g_186),
                                         0x2452L)))) != p_61),
                                1UL)),
                            g_185)) ^
                        p_60) &&
                       l_1120) ^
                      0xD2CFL) >= l_1160) > p_59) == 0UL);
            }
            return g_362;
          }

        } else {
          uint8_t l_1120 = 0x1EL;
          int32_t l_1160 = 0x9C031653L;

          l_1666[i] = 0x20L;

          if (((((safe_sub_func_int8_t_s_s(
                     (((0x4AL == (safe_lshift_func_int16_t_s_u(
                                     (l_986[2][1][1] || p_59), 2))) &
                       ((safe_unary_minus_func_int8_t_s(
                            (safe_div_func_uint8_t_u_u(
                                ((safe_sub_func_uint16_t_u_u(
                                     g_185,
                                     ((safe_mod_func_uint8_t_u_u(
                                          l_986[1][3][1],
                                          (((g_493 >
                                             (0x56L < (safe_sub_func_int8_t_s_s(
                                                          l_1113[0],
                                                          0x65L)))) >= 0x83L) &
                                           l_1120))) |
                                      0x8E174AC1L))) ||
                                 1UL),
                                g_420)))) <= g_734)) < g_362),
                     g_186)) > l_834) ||
                p_60) != l_1099[9][1])) {
            p_61 = g_1089[1];
          } else {
            g_463[5] = (p_59 ^ p_62);
            if ((safe_add_func_int32_t_s_s(0x45062FE5L, g_463[p_60]))) {
              int32_t l_973 = 0xDBBB214EL;
              int i;
              g_463[p_60] =
                  ((safe_mul_func_int16_t_s_s(
                       0xFE61L,
                       ((0x6B5FL >=
                         ((safe_mod_func_uint8_t_u_u(
                              g_463[p_60],
                              (0UL ^ (safe_sub_func_int8_t_s_s(
                                         p_62, ((safe_sub_func_int16_t_s_s(
                                                    l_851, 0x26F0L)) >
                                                (0L <= 4294967290UL))))))) >
                          p_60)) ^
                        0x753D1A51L))) &
                   0x2A37BEC8L);
              for (g_186 = (-22); (g_186 <= 54); ++g_186) {
                uint32_t l_919[10][2] = {
                    {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                    {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                    {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                    {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                    {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L}};
                int i, j;
                if ((safe_mod_func_int8_t_s_s(g_362, p_59))) {
                  l_850 =
                      ((0x34L &
                        (g_734 >= (safe_lshift_func_uint16_t_u_s(g_870, 9)))) >=
                       ((safe_div_func_int8_t_s_s(
                            (safe_lshift_func_uint16_t_u_u(
                                (p_59 &
                                 (safe_add_func_int16_t_s_s(
                                     ((!((safe_lshift_func_uint16_t_u_u(
                                             ((1L !=
                                               (((((l_834 !=
                                                    (safe_lshift_func_uint16_t_u_u(
                                                        (g_4 ^
                                                         (!((safe_mul_func_int16_t_s_s(
                                                                (safe_lshift_func_uint8_t_u_u(
                                                                    p_62, 6)),
                                                                (safe_mod_func_int8_t_s_s(
                                                                    ((l_851 ||
                                                                      p_62) <
                                                                     g_365),
                                                                    l_850)))) <=
                                                            65535UL))),
                                                        0))) |
                                                   g_4) > l_851) <= p_62) ^
                                                g_753)) == g_463[p_60]),
                                             p_60)) <= 0x3B5BL)) > g_463[p_60]),
                                     g_365))),
                                g_361)),
                            g_734)) != g_753));
                  if (g_870)
                    break;
                  return g_493;
                } else {
                  const int32_t l_903 = 5L;
                  l_918 |= (safe_mod_func_int16_t_s_s(
                      ((safe_add_func_uint32_t_u_u(
                           (safe_mul_func_int16_t_s_s(p_62, g_27[6])),
                           g_734)) &&
                       l_851),
                      (+(1L <
                         ((safe_add_func_uint32_t_u_u(
                              (((((safe_lshift_func_int8_t_s_u(
                                      (safe_sub_func_int16_t_s_s(
                                          (safe_mod_func_int32_t_s_s(
                                              (safe_div_func_int16_t_s_s(
                                                  ((l_903 ||
                                                    (((safe_add_func_uint16_t_u_u(
                                                          ((safe_lshift_func_uint8_t_u_u(
                                                               p_59, 4)) !=
                                                           (~((safe_mul_func_int16_t_s_s(
                                                                  (safe_mod_func_int32_t_s_s(
                                                                      (safe_div_func_int16_t_s_s(
                                                                          ((safe_div_func_uint32_t_u_u(
                                                                               (+(g_362 ^
                                                                                  (safe_mul_func_int16_t_s_s(
                                                                                      ((-1L) &&
                                                                                       p_61),
                                                                                      l_850)))),
                                                                               l_849)) |
                                                                           p_59),
                                                                          g_463
                                                                              [4])),
                                                                      0x4C30C153L)),
                                                                  l_851)) ||
                                                              g_186))),
                                                          g_362)) ||
                                                      0x80L) &
                                                     9L)) &&
                                                   p_60),
                                                  65534UL)),
                                              0xE9AD882DL)),
                                          g_493)),
                                      6)) |
                                  0x59L) < g_4) &
                                g_463[p_60]) != p_62),
                              l_903)) ||
                          p_60)))));
                  l_928 =
                      ((((((l_919[1][0] ^ g_361) ==
                           (9L |
                            (((safe_lshift_func_uint16_t_u_s(
                                  ((p_62 <
                                    (~(safe_sub_func_int8_t_s_s(
                                        g_463[p_60],
                                        (l_918 | (safe_div_func_int8_t_s_s(
                                                     (safe_sub_func_int8_t_s_s(
                                                         (-1L), 0x5BL)),
                                                     l_918))))))) ||
                                   p_58),
                                  5)) &
                              p_61) |
                             g_463[p_60]))) != (-5L)) == g_463[2]) > p_58) &
                       g_186);
                }
              }
              if (l_928) {
                p_61 = (((+(safe_div_func_int32_t_s_s(p_62, p_58))) !=
                         g_463[p_60]) >
                        ((safe_add_func_uint32_t_u_u(
                             ((g_420 || l_851) < g_150),
                             (((p_59 <= g_753) ==
                               (safe_add_func_int16_t_s_s(
                                   (!(safe_lshift_func_int8_t_s_u(
                                       ((safe_lshift_func_int16_t_s_u(l_928,
                                                                      g_365)) ^
                                        g_186),
                                       7))),
                                   g_463[p_60]))) &&
                              p_59))) >= g_362));
                for (p_61 = 0; (p_61 <= (-22));
                     p_61 = safe_sub_func_uint32_t_u_u(p_61, 1)) {
                  const uint32_t l_941 = 0xAC0362BEL;
                  if (l_941)
                    break;
                  g_463[p_60] = (-10L);
                }
                for (g_362 = 1; (g_362 <= 5); g_362 += 1) {
                  int i;
                  if (g_463[g_362])
                    break;
                  p_61 = 0xFD45FC42L;
                  l_849 = 0xCB027895L;
                }
              } else {
                uint8_t l_966 = 0x54L;
                int32_t l_967 = 0x418378F9L;
                int32_t l_972 = 0xDCA573D8L;
                uint16_t l_975 = 5UL;
                if (l_851)
                  break;
                g_870 =
                    ((safe_lshift_func_int8_t_s_u(
                         ((0x049DL ^
                           (safe_mul_func_uint16_t_u_u(
                               (safe_add_func_int32_t_s_s(
                                   (safe_add_func_int32_t_s_s(
                                       (safe_mul_func_uint8_t_u_u(g_463[p_60],
                                                                  p_59)),
                                       (safe_lshift_func_int16_t_s_s(
                                           (g_463[2] &&
                                            (4294967295UL <
                                             ((safe_rshift_func_int8_t_s_s(
                                                  (-1L),
                                                  (((safe_add_func_int16_t_s_s(
                                                        (((safe_add_func_uint32_t_u_u(
                                                              ((safe_div_func_int32_t_s_s(
                                                                   g_870,
                                                                   (safe_add_func_int8_t_s_s(
                                                                       l_918,
                                                                       2L)))) <
                                                               4294967288UL),
                                                              0x13E14289L)) &
                                                          p_62) ||
                                                         g_493),
                                                        0x36E5L)) != l_966) <=
                                                   g_362))) < p_62))),
                                           l_834)))),
                                   l_966)),
                               g_420))) <= l_966),
                         7)) ||
                     g_463[0]);
                ++l_975;
              }
            } else {
              uint32_t l_986[8][9][3] = {
                  {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                  {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                  {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                  {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                  {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                  {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                  {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                  {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                   {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}}};
              int i, j, k;
              if ((safe_sub_func_uint16_t_u_u(
                      0x8860L,
                      (safe_sub_func_uint16_t_u_u(
                          g_365,
                          (safe_add_func_uint16_t_u_u(
                              (0x2DL <= (safe_lshift_func_uint16_t_u_u(
                                            l_986[1][3][1], 6))),
                              (((((g_27[6] ^
                                   (safe_add_func_int8_t_s_s(
                                       (safe_sub_func_uint8_t_u_u(
                                           (safe_sub_func_int8_t_s_s(
                                               ((l_968 !=
                                                 ((0x97L &&
                                                   (p_58 !=
                                                    (safe_sub_func_uint8_t_u_u(
                                                        (safe_mod_func_uint8_t_u_u(
                                                            ((6L | p_60) <=
                                                             l_986[1][6][0]),
                                                            l_850)),
                                                        0x9AL)))) != 7L)) ^
                                                l_968),
                                               p_61)),
                                           p_59)),
                                       g_185))) == 6UL) == 0x0060DD85L) &&
                                0x27L) > 255UL)))))))) {
                g_365 |= (safe_unary_minus_func_uint16_t_u((p_58 > l_969)));
              } else {
                uint8_t l_1060 = 0x5CL;
                for (g_361 = 0; (g_361 >= 53);
                     g_361 = safe_add_func_uint16_t_u_u(g_361, 7)) {
                  uint16_t l_1022 = 65531UL;
                  g_463[p_60] = 2L;
                  g_870 = (safe_mul_func_uint8_t_u_u(
                      (safe_mod_func_int8_t_s_s(g_753, p_59)), g_365));
                  g_463[3] |=
                      (((safe_lshift_func_int8_t_s_s(
                            (-1L),
                            ((~((safe_div_func_int8_t_s_s(
                                    p_62,
                                    (safe_rshift_func_int8_t_s_u(
                                        (safe_add_func_int32_t_s_s(
                                            (safe_add_func_uint32_t_u_u(
                                                0UL,
                                                ((safe_mod_func_uint8_t_u_u(
                                                     (safe_lshift_func_int16_t_s_s(
                                                         g_420, 6)),
                                                     (safe_rshift_func_uint16_t_u_u(
                                                         (g_27[6] < p_61),
                                                         (safe_lshift_func_int8_t_s_s(
                                                             ((p_60 >
                                                               ((g_753 >=
                                                                 g_870) <=
                                                                l_986[4][1]
                                                                     [0])) !=
                                                              l_1022),
                                                             l_834)))))) |
                                                 0xFDL))),
                                            0xDFD5D61BL)),
                                        5)))) &
                                l_918)) >= g_27[5]))) &
                        (-1L)) <= 4294967295UL);
                  p_61 =
                      (0x1B5EF209L |
                       (safe_unary_minus_func_uint8_t_u(
                           (65535UL <=
                            (0x40L <
                             (safe_add_func_int32_t_s_s(
                                 l_849,
                                 (safe_rshift_func_int8_t_s_u(
                                     ((safe_sub_func_uint16_t_u_u(
                                          (safe_div_func_uint16_t_u_u(
                                              g_493, (safe_mul_func_uint8_t_u_u(
                                                         (l_986[0][4][1] != 5L),
                                                         l_1034)))),
                                          (safe_sub_func_uint8_t_u_u(
                                              (safe_mod_func_int16_t_s_s(
                                                  0x1AAAL, g_150)),
                                              0x03L)))) <= 0L),
                                     g_361)))))))));
                }
                l_1060 =
                    (((safe_sub_func_int32_t_s_s(p_58, (-5L))) ||
                      (safe_add_func_int32_t_s_s(
                          (safe_lshift_func_int16_t_s_u(p_61, 14)),
                          (((safe_mod_func_uint8_t_u_u(
                                (!((safe_add_func_int16_t_s_s(
                                       (p_59 |
                                        (safe_lshift_func_int8_t_s_u(
                                            (safe_rshift_func_uint16_t_u_s(
                                                0x29D9L,
                                                (safe_div_func_uint32_t_u_u(
                                                    0UL, g_753)))),
                                            0))),
                                       (safe_unary_minus_func_uint32_t_u(
                                           (l_968 !=
                                            (safe_rshift_func_int8_t_s_u(
                                                (safe_sub_func_int8_t_s_s(
                                                    (l_968 ^ 0x0044B4B1L),
                                                    p_61)),
                                                6))))))) |
                                   0x23L)),
                                0x5DL)) ||
                            0xDC5166B7L) ^
                           0x188DL)))) > p_60);
                p_61 =
                    ((((safe_mul_func_int8_t_s_s(
                           ((+(g_185 <
                               (safe_sub_func_int8_t_s_s(
                                   l_851,
                                   ((safe_mul_func_uint16_t_u_u(
                                        (((safe_rshift_func_uint8_t_u_u(
                                              ((safe_lshift_func_int8_t_s_s(
                                                   p_61,
                                                   ((safe_mod_func_uint8_t_u_u(
                                                        ((7UL &
                                                          ((((safe_lshift_func_uint16_t_u_u(
                                                                 (safe_add_func_uint8_t_u_u(
                                                                     0x1EL,
                                                                     0x44L)),
                                                                 ((safe_lshift_func_uint16_t_u_u(
                                                                      (safe_div_func_uint32_t_u_u(
                                                                          (((safe_div_func_uint32_t_u_u(
                                                                                ((g_493 ^
                                                                                  (safe_mul_func_int8_t_s_s(
                                                                                      ((safe_lshift_func_uint8_t_u_u(
                                                                                           ((safe_sub_func_uint32_t_u_u(
                                                                                                4294967294UL,
                                                                                                (0x617AL >=
                                                                                                 0xF678L))) !=
                                                                                            g_362),
                                                                                           p_61)) &&
                                                                                       4294967295UL),
                                                                                      g_463
                                                                                          [0]))) <=
                                                                                 p_60),
                                                                                l_850)) &
                                                                            0UL) <=
                                                                           g_493),
                                                                          4294967292UL)),
                                                                      11)) <
                                                                  p_61))) ^
                                                             l_968) == l_971) &&
                                                           l_986[0][1][2])) ==
                                                         p_58),
                                                        0x93L)) > p_60))) ==
                                               p_58),
                                              3)) <= l_834) >= g_186),
                                        g_185)) == l_850))))) ||
                            0xB5CAL),
                           g_27[6])) >= g_753) > p_62) == 0UL);
                if (g_1089[1])
                  continue;
              }
              for (l_971 = (-14); (l_971 <= 26); l_971++) {
                l_928 &= (safe_unary_minus_func_uint16_t_u(
                    (g_463[0] ==
                     ((safe_add_func_uint16_t_u_u(
                          (((safe_div_func_uint16_t_u_u(
                                (0L < (safe_mod_func_uint16_t_u_u(
                                          l_1099[9][1], g_463[p_60]))),
                                (safe_add_func_int16_t_s_s(
                                    (g_734 |
                                     ((p_58 < (0x7CL && 0x56L)) ^
                                      (((((p_59 || l_834) && p_59) < g_27[6]) &&
                                        l_986[1][3][1]) ^
                                       7L))),
                                    p_62)))) < l_918) ||
                           0xE8L),
                          l_834)) <= p_60))));
                g_463[0] = g_753;
              }
              if (p_61) {
                uint32_t l_1114 = 18446744073709551615UL;
                g_463[0] = p_58;
                l_928 |= (safe_rshift_func_uint16_t_u_u(p_58, 6));
                g_365 |= ((((((((p_61 >=
                                 (l_1034 <=
                                  (((0x95L <= g_753) |
                                    (safe_rshift_func_uint16_t_u_u(
                                        ((safe_sub_func_int16_t_s_s(
                                             l_1108,
                                             (1L ||
                                              (safe_mod_func_uint32_t_u_u(
                                                  (safe_lshift_func_int16_t_s_s(
                                                      l_986[1][3][1], 9)),
                                                  7L))))) <
                                         ((g_420 > g_186) && p_61)),
                                        0))) > p_58))) &&
                                l_1113[0]) <= 0x5C091B7AL) >= g_4) == (-1L)) >
                            g_493) &
                           0x8E3F9787L) <= l_1114);
              } else {
                uint8_t l_1120 = 0x1EL;
                int32_t l_1160 = 0x9C031653L;
                p_61 = (safe_mul_func_uint8_t_u_u(
                    (g_734 !=
                     (((-5L) || ((safe_unary_minus_func_uint16_t_u(l_849)) |
                                 ((safe_div_func_int8_t_s_s(p_60, l_1120)) >=
                                  0x6DL))) < l_1120)),
                    (safe_rshift_func_uint8_t_u_s(
                        (((safe_sub_func_int32_t_s_s(
                              l_1113[0], (251UL ^ 0xDFL))) == g_870) > l_918),
                        6))));
                if (((((safe_sub_func_int8_t_s_s(
                           (((0x4AL == (safe_lshift_func_int16_t_s_u(
                                           (l_986[2][1][1] || p_59), 2))) &
                             ((safe_unary_minus_func_int8_t_s(
                                  (safe_div_func_uint8_t_u_u(
                                      ((safe_sub_func_uint16_t_u_u(
                                           g_185,
                                           ((safe_mod_func_uint8_t_u_u(
                                                l_986[1][3][1],
                                                (((g_493 >
                                                   (0x56L <
                                                    (safe_sub_func_int8_t_s_s(
                                                        l_1113[0], 0x65L)))) >=
                                                  0x83L) &
                                                 l_1120))) |
                                            0x8E174AC1L))) ||
                                       1UL),
                                      g_420)))) <= g_734)) < g_362),
                           g_186)) > l_834) ||
                      p_60) != l_1099[9][1])) {
                  p_61 = g_1089[1];
                } else {
                  g_463[5] = (p_59 ^ p_62);
                }
                g_870 &=
                    (((((((safe_lshift_func_int8_t_s_s(
                              (safe_sub_func_int8_t_s_s(
                                  ((safe_sub_func_uint8_t_u_u(
                                       5UL,
                                       (safe_sub_func_uint16_t_u_u(
                                           ((g_362 &
                                             ((safe_rshift_func_int8_t_s_u(
                                                  ((safe_sub_func_int8_t_s_s(
                                                       (safe_sub_func_uint32_t_u_u(
                                                           (safe_add_func_uint8_t_u_u(
                                                               (safe_lshift_func_int16_t_s_s(
                                                                   l_974, 4)),
                                                               g_493)),
                                                           l_1120)),
                                                       0x3BL)) ==
                                                   (((safe_sub_func_uint16_t_u_u(
                                                         p_59, (-2L))) <
                                                     0x3A956D3AL) &
                                                    p_58)),
                                                  2)) == g_1089[3])) == g_186),
                                           0x2452L)))) != p_61),
                                  1UL)),
                              g_185)) ^
                          p_60) &&
                         l_1120) ^
                        0xD2CFL) >= l_1160) > p_59) == 0UL);
              }
              return g_362;
            }
          }
          g_870 &=
              (((((((safe_lshift_func_int8_t_s_s(
                        (safe_sub_func_int8_t_s_s(
                            ((safe_sub_func_uint8_t_u_u(
                                 5UL,
                                 (safe_sub_func_uint16_t_u_u(
                                     ((g_362 &
                                       ((safe_rshift_func_int8_t_s_u(
                                            ((safe_sub_func_int8_t_s_s(
                                                 (safe_sub_func_uint32_t_u_u(
                                                     (safe_add_func_uint8_t_u_u(
                                                         (safe_lshift_func_int16_t_s_s(
                                                             l_974, 4)),
                                                         g_493)),
                                                     l_1120)),
                                                 0x3BL)) ==
                                             (((safe_sub_func_uint16_t_u_u(
                                                   p_59, (-2L))) <
                                               0x3A956D3AL) &
                                              p_58)),
                                            2)) == g_1089[3])) == g_186),
                                     0x2452L)))) != p_61),
                            1UL)),
                        g_185)) ^
                    p_60) &&
                   l_1120) ^
                  0xD2CFL) >= l_1160) > p_59) == 0UL);
        }
        l_1666[i] = 0x20L;

        return g_362;
      }
      for (l_968 = 0; (l_968 <= 0); l_968 += 1) {
        if (p_61)

        {
          {
            if (p_61)
              break;
          }
        }
      }
      if (((safe_lshift_func_uint8_t_u_s(
               ((safe_lshift_func_uint8_t_u_u(
                    ((((((~(safe_mod_func_int16_t_s_s(
                             1L,
                             (safe_lshift_func_int16_t_s_s(
                                 (l_1169 &&
                                  ((safe_mul_func_int16_t_s_s(
                                       g_27[6], 0xA045L)) <
                                   (safe_sub_func_int32_t_s_s(
                                       (0x21C05D77L |
                                        (!((safe_rshift_func_int8_t_s_u(
                                               (l_850 &&
                                                (safe_add_func_int16_t_s_s(
                                                    (safe_add_func_int8_t_s_s(
                                                        (((safe_div_func_uint16_t_u_u(
                                                              (safe_add_func_int32_t_s_s(
                                                                  (safe_sub_func_int32_t_s_s(
                                                                      2L,
                                                                      (l_928 <
                                                                       (((safe_lshift_func_int16_t_s_u(
                                                                             (((g_463
                                                                                    [p_60] &&
                                                                                l_918) |
                                                                               g_493) <
                                                                              1UL),
                                                                             p_62)) >
                                                                         g_27[3]) <=
                                                                        l_918)))),
                                                                  g_186)),
                                                              g_753)) ^
                                                          0x5BL) >= p_62),
                                                        p_61)),
                                                    g_365))),
                                               g_27[1])) >= g_463[5]))),
                                       g_463[0])))),
                                 g_186))))) > l_1113[0]) > 1L) ||
                       l_1099[7][1]) > 1UL) |
                     1UL),
                    p_62)) &
                p_58),
               p_61)) != p_60)) {
        uint8_t l_1218 = 0x9AL;
        int32_t l_1219 = 0xF3C6DCF4L;
        int32_t l_1247 = 2L;
        int32_t l_1248 = 0x3BACB270L;
        int32_t l_1249 = (-7L);
        int32_t l_1252[8][1] = {{1L}, {1L}, {1L}, {1L}, {1L}, {1L}, {1L}, {1L}};
        int32_t l_1265 = 1L;
        uint8_t l_1266 = 7UL;
        int i, j;
        if ((g_753 ||
             (((((p_60 !=
                  (safe_mul_func_int8_t_s_s(
                      (safe_mul_func_int8_t_s_s(
                          (-5L),
                          ((((safe_mod_func_uint16_t_u_u(
                                 p_61,
                                 (safe_sub_func_uint8_t_u_u(
                                     ((((safe_rshift_func_int8_t_s_u(
                                            (255UL ||
                                             ((safe_unary_minus_func_int16_t_s(
                                                  g_27[6])) >
                                              (p_60 |
                                               (safe_div_func_int16_t_s_s(
                                                   (((g_27[6] |
                                                      (0x69E9L >= p_62)) !=
                                                     p_58) < g_493),
                                                   p_60))))),
                                            l_1169)) &
                                        l_1108) >= 9UL) != (-4L)),
                                     p_62)))) &&
                             0xFAL) ^
                            g_463[0]) <= p_62))),
                      p_59))) |
                 l_918) &
                g_1201) >= p_61) == p_60))) {
          int8_t l_1213 = (-1L);
          int32_t l_1246[4][4];
          int32_t l_1254 = 0xB057E000L;
          int32_t l_1261 = (-5L);
          int i, j;
          for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++)
              l_1246[i][j] = 1L;
          }
          for (g_753 = 0; (g_753 <= 1); g_753 += 1) {
            int i, j;
            l_849 = (safe_div_func_uint32_t_u_u(
                (l_1099[(g_753 + 4)][g_753] ^
                 ((((safe_lshift_func_int8_t_s_u(
                        ((safe_rshift_func_uint8_t_u_u(g_870, 2)) || p_58),
                        7)) !=
                    ((safe_sub_func_uint16_t_u_u(
                         (safe_unary_minus_func_uint8_t_u(
                             ((safe_mul_func_int16_t_s_s(
                                  (8UL ==
                                   (l_1213 &&
                                    ((l_849 == g_734) >=
                                     ((65527UL ==
                                       (safe_rshift_func_uint8_t_u_u(
                                           ((safe_lshift_func_uint16_t_u_u(
                                                (l_1099[(g_753 + 4)][g_753] ^
                                                 g_493),
                                                10)) == g_365),
                                           6))) <= 0xBC26A47CL)))),
                                  g_186)) >= g_1089[1]))),
                         p_59)) |
                     g_463[p_60])) == g_361) < 0xD5L)),
                p_61));
            l_1219 |= l_1218;
            p_61 = (safe_mul_func_uint8_t_u_u(
                ((safe_rshift_func_int8_t_s_s(
                     p_59,
                     (safe_div_func_uint8_t_u_u(
                         ((safe_add_func_int16_t_s_s(
                              (((g_1089[1] &
                                 ((((g_420 &
                                     (p_61 <
                                      (safe_lshift_func_uint16_t_u_s(
                                          ((~l_1230) ||
                                           (safe_add_func_uint32_t_u_u(
                                               ((safe_lshift_func_uint16_t_u_u(
                                                    ((safe_rshift_func_uint16_t_u_s(
                                                         ((safe_mod_func_int8_t_s_s(
                                                              ((safe_sub_func_int8_t_s_s(
                                                                   (1L ^ g_362),
                                                                   ((safe_mul_func_uint16_t_u_u(
                                                                        ((safe_rshift_func_uint16_t_u_u(
                                                                             l_1099
                                                                                 [(g_753 +
                                                                                   4)]
                                                                                 [g_753],
                                                                             p_59)) >=
                                                                         7L),
                                                                        p_58)) |
                                                                    0xDFDDL))) &&
                                                               g_4),
                                                              6UL)) &&
                                                          l_1245),
                                                         10)) &&
                                                     g_361),
                                                    11)) > 0xF5L),
                                               l_1218))),
                                          l_971)))) > g_1089[1]) < p_58) ==
                                  (-1L))) >= l_834) == 0xF5001292L),
                              p_61)) |
                          l_1213),
                         g_27[6])))) <= g_463[1]),
                1L));
          }
          ++l_1266;
          for (l_1245 = 2; (l_1245 > 30);
               l_1245 = safe_add_func_uint16_t_u_u(l_1245, 1)) {
            uint8_t l_1289 = 0UL;
            g_365 &= l_928;
            l_1290 |=
                ((safe_rshift_func_uint8_t_u_s(
                     (safe_mod_func_uint8_t_u_u(
                         l_834,
                         (safe_sub_func_uint32_t_u_u(
                             (6UL >=
                              (safe_lshift_func_int16_t_s_s(
                                  (safe_div_func_int32_t_s_s(p_60, l_849)),
                                  0))),
                             (safe_add_func_uint16_t_u_u(
                                 (safe_lshift_func_int8_t_s_s(
                                     ((p_60 &&
                                       ((safe_mod_func_uint16_t_u_u(
                                            ((((0xEF80L &
                                                (safe_rshift_func_int16_t_s_s(
                                                    (+p_61), 12))) &&
                                               (0x6C9FL | l_1247)) &
                                              p_58) |
                                             l_1289),
                                            g_1089[1])) &
                                        g_734)) >= l_1253),
                                     2)),
                                 0xD86EL)))))),
                     0)) ||
                 l_1218);
          }
        } else {
          int16_t l_1347 = (-10L);

          if (l_851) {
            uint16_t l_1359 = 65534UL;

            g_365 = (safe_lshift_func_uint8_t_u_u(
                ((((safe_add_func_int32_t_s_s(
                       (l_1347 &&
                        ((safe_add_func_uint32_t_u_u(
                             ((safe_lshift_func_uint16_t_u_u(
                                  (safe_sub_func_int16_t_s_s(
                                      (l_1354[0][1] !=
                                       (((-9L) == p_58) ==
                                        ((g_1089[6] !=
                                          (safe_mul_func_int16_t_s_s(
                                              l_1113[0],
                                              (((((~(2UL <= (~g_1089[1]))) &
                                                  (safe_mod_func_uint16_t_u_u(
                                                      0x02DBL, 65531UL))) <=
                                                 0x1742L) &&
                                                5L) &&
                                               p_62)))) &
                                         3L))),
                                      l_1359)),
                                  l_1252[5][0])) < g_463[0]),
                             l_1359)) |
                         l_968)),
                       p_61)) != p_62) &&
                  0xA93F03F5L) &
                 p_59),
                l_1354[0][1]));

          } else {
            p_61 ^= (safe_lshift_func_uint16_t_u_u(g_870, 13));
            --l_851;

            l_1256 ^= (safe_add_func_int32_t_s_s(
                ((((safe_rshift_func_int8_t_s_u(
                       (safe_mul_func_int16_t_s_s(
                           ((safe_sub_func_uint16_t_u_u(
                                65535UL,
                                ((safe_add_func_uint16_t_u_u(
                                     g_734,
                                     (safe_mod_func_int32_t_s_s(
                                         g_361,
                                         (safe_rshift_func_uint16_t_u_s(
                                             (((p_59 & (g_463[p_60] ^ g_186)) >
                                               ((((safe_lshift_func_uint8_t_u_u(
                                                      ((((g_1089[1] &
                                                          (safe_lshift_func_int8_t_s_s(
                                                              (g_27[6] <=
                                                               ((safe_rshift_func_int16_t_s_s(
                                                                    p_58, 0)) <=
                                                                (-5L))),
                                                              2))) ^
                                                         l_1252[4][0]) >=
                                                        0xE4CE3C55L) > (-1L)),
                                                      6)) ^
                                                  g_1089[6]) != p_60) <
                                                g_150)) &
                                              g_186),
                                             5)))))) |
                                 p_62))) &
                            0xCEE90828L),
                           0xA1B2L)),
                       1)) <= (-1L)) < l_1264[9]) <= 2L),
                0x79B95C6FL));
            l_1256 ^= (safe_add_func_int32_t_s_s(
                ((((safe_rshift_func_int8_t_s_u(
                       (safe_mul_func_int16_t_s_s(
                           ((safe_sub_func_uint16_t_u_u(
                                65535UL,
                                ((safe_add_func_uint16_t_u_u(
                                     g_734,
                                     (safe_mod_func_int32_t_s_s(
                                         g_361,
                                         (safe_rshift_func_uint16_t_u_s(
                                             (((p_59 & (g_463[p_60] ^ g_186)) >
                                               ((((safe_lshift_func_uint8_t_u_u(
                                                      ((((g_1089[1] &
                                                          (safe_lshift_func_int8_t_s_s(
                                                              (g_27[6] <=
                                                               ((safe_rshift_func_int16_t_s_s(
                                                                    p_58, 0)) <=
                                                                (-5L))),
                                                              2))) ^
                                                         l_1252[4][0]) >=
                                                        0xE4CE3C55L) > (-1L)),
                                                      6)) ^
                                                  g_1089[6]) != p_60) <
                                                g_150)) &
                                              g_186),
                                             5)))))) |
                                 p_62))) &
                            0xCEE90828L),
                           0xA1B2L)),
                       1)) <= (-1L)) < l_1264[9]) <= 2L),
                0x79B95C6FL));

            if (g_734)
              break;
            g_870 ^= l_1258[0][2];
          }
          p_61 = 0x831162D3L;
        }
      } else {
        uint16_t l_1398 = 1UL;
        int8_t l_1423 = 1L;
        int32_t l_1475[3];
        int16_t l_1504 = 0x0AA6L;
        int8_t l_1528 = 0x3EL;
        int i;
        for (i = 0; i < 3; i++)
          l_1475[i] = 1L;
        for (g_1201 = 2; (g_1201 <= 9); g_1201 += 1) {
          int i;
          if ((safe_lshift_func_int8_t_s_s(l_1264[p_60], 2))) {
            const uint8_t l_1392 = 0UL;
            return l_1392;
          } else {
            int8_t l_1397 = (-1L);
            int i;
            l_1264[g_1201] = (safe_add_func_uint32_t_u_u(
                (safe_mul_func_int8_t_s_s(l_851, l_1397)),
                ((g_205 || 6L) > (g_4 <= (-1L)))));
            ++l_1398;
            g_870 =
                ((((-1L) &
                   ((((safe_add_func_uint32_t_u_u(
                          (safe_add_func_uint8_t_u_u(
                              248UL,
                              (safe_rshift_func_uint16_t_u_s(
                                  p_62,
                                  ((((safe_rshift_func_uint16_t_u_s(
                                         (safe_add_func_uint16_t_u_u(
                                             ((safe_add_func_int32_t_s_s(
                                                  ((safe_lshift_func_uint8_t_u_s(
                                                       0xF7L,
                                                       (safe_lshift_func_uint8_t_u_s(
                                                           (0UL < g_870),
                                                           4)))) != (-1L)),
                                                  (safe_lshift_func_int16_t_s_u(
                                                      (g_420 &
                                                       (safe_sub_func_uint16_t_u_u(
                                                           ((((((safe_mul_func_int16_t_s_s(
                                                                    l_971,
                                                                    g_27[6])) ||
                                                                l_1230) >
                                                               l_968) <
                                                              g_365) != p_61) ^
                                                            0x28333F6AL),
                                                           0UL))),
                                                      p_58)))) > g_420),
                                             0UL)),
                                         12)) >= p_61) != g_420) != l_1397))))),
                          g_753)) >= g_27[2]) == 0xE0C2L) < l_1423)) < p_62) &&
                 0x32B2F135L);
            g_463[p_60] &= (safe_rshift_func_uint16_t_u_s(
                (p_60 ^
                 (safe_mul_func_uint16_t_u_u(
                     (((safe_sub_func_int16_t_s_s(
                           (((safe_mod_func_int8_t_s_s(
                                 5L,
                                 (safe_mul_func_int8_t_s_s(
                                     (safe_sub_func_int16_t_s_s(
                                         (((safe_mod_func_int16_t_s_s(
                                               (safe_sub_func_uint16_t_u_u(
                                                   (g_1089[6] &&
                                                    (safe_div_func_int16_t_s_s(
                                                        (p_61 &
                                                         ((safe_mod_func_int32_t_s_s(
                                                              (safe_add_func_uint16_t_u_u(
                                                                  (safe_lshift_func_int8_t_s_u(
                                                                      ((~1UL) &&
                                                                       ((0xC8DA6783L &&
                                                                         (((safe_sub_func_int16_t_s_s(
                                                                               ((safe_add_func_int16_t_s_s(
                                                                                    (p_58 &&
                                                                                     ((g_362 !=
                                                                                       1UL) <=
                                                                                      g_205)),
                                                                                    p_60)) ||
                                                                                l_1264
                                                                                    [4]),
                                                                               p_62)) ==
                                                                           l_1264
                                                                               [g_1201]) &&
                                                                          0x600BL)) <=
                                                                        l_1264
                                                                            [p_60])),
                                                                      l_1452
                                                                          [2])),
                                                                  0x1A41L)),
                                                              g_186)) != 1UL)),
                                                        l_1264[p_60]))),
                                                   p_62)),
                                               l_1250)) |
                                           p_62) ||
                                          0UL),
                                         g_361)),
                                     l_1264[p_60])))) != g_1089[5]) == g_365),
                           p_58)) == g_205) &
                      g_734),
                     g_205))),
                11));
          }
          g_365 = l_834;
          g_870 =
              (g_205 ==
               (safe_lshift_func_int16_t_s_u(
                   ((g_463[0] >
                     ((((safe_lshift_func_uint8_t_u_u(
                            ((((((safe_add_func_uint16_t_u_u(
                                     ((safe_mod_func_int8_t_s_s(
                                          (safe_lshift_func_int16_t_s_s(
                                              (safe_rshift_func_uint8_t_u_u(
                                                  (((p_62 <= l_1423) && p_62) &&
                                                   (safe_add_func_int16_t_s_s(
                                                       ((safe_lshift_func_uint8_t_u_s(
                                                            (safe_mod_func_int8_t_s_s(
                                                                (g_734 &&
                                                                 (safe_div_func_int16_t_s_s(
                                                                     g_493,
                                                                     ((safe_div_func_int8_t_s_s(
                                                                          l_1475
                                                                              [0],
                                                                          0x56L)) &&
                                                                      l_928)))),
                                                                g_463[4])),
                                                            g_27[6])) ||
                                                        0UL),
                                                       g_420))),
                                                  1)),
                                              3)),
                                          l_1250)) > g_361),
                                     p_62)) ^
                                 0xEFL) |
                                l_1476) ||
                               g_4) != 0x5C945727L) ||
                             0x5DL),
                            g_361)) |
                        g_493) &
                       0x59L) &&
                      p_58)) > 0x3EC9L),
                   p_58)));
          if (g_493) {
            int16_t l_1489 = 0xC2FEL;
            g_870 =
                ((+l_1099[4][0]) >=
                 (((((((p_61 >= 0xB7L) !=
                       (0x5B02DFFEL !=
                        (safe_sub_func_uint16_t_u_u(
                            ((-6L) &
                             (safe_rshift_func_int16_t_s_u(
                                 (safe_mod_func_uint8_t_u_u(
                                     ((0x47BE737CL & (p_58 <= g_27[5])) & p_58),
                                     g_870)),
                                 p_61))),
                            0xBBBCL)))) |
                      g_463[0]) <= 4294967291UL) < p_59) &
                   0x5DFFB796L) |
                  l_850));
            for (g_1201 = 2; (g_1201 <= 9); g_1201 += 1) {
              int i;
              if ((safe_lshift_func_int8_t_s_s(l_1264[p_60], 2))) {
                const uint8_t l_1392 = 0UL;
                return l_1392;
              } else {
                int8_t l_1397 = (-1L);
                int i;
                l_1264[g_1201] = (safe_add_func_uint32_t_u_u(
                    (safe_mul_func_int8_t_s_s(l_851, l_1397)),
                    ((g_205 || 6L) > (g_4 <= (-1L)))));
                ++l_1398;
                g_870 =
                    ((((-1L) &
                       ((((safe_add_func_uint32_t_u_u(
                              (safe_add_func_uint8_t_u_u(
                                  248UL,
                                  (safe_rshift_func_uint16_t_u_s(
                                      p_62,
                                      ((((safe_rshift_func_uint16_t_u_s(
                                             (safe_add_func_uint16_t_u_u(
                                                 ((safe_add_func_int32_t_s_s(
                                                      ((safe_lshift_func_uint8_t_u_s(
                                                           0xF7L,
                                                           (safe_lshift_func_uint8_t_u_s(
                                                               (0UL < g_870),
                                                               4)))) != (-1L)),
                                                      (safe_lshift_func_int16_t_s_u(
                                                          (g_420 &
                                                           (safe_sub_func_uint16_t_u_u(
                                                               ((((((safe_mul_func_int16_t_s_s(
                                                                        l_971,
                                                                        g_27[6])) ||
                                                                    l_1230) >
                                                                   l_968) <
                                                                  g_365) !=
                                                                 p_61) ^
                                                                0x28333F6AL),
                                                               0UL))),
                                                          p_58)))) > g_420),
                                                 0UL)),
                                             12)) >= p_61) != g_420) !=
                                       l_1397))))),
                              g_753)) >= g_27[2]) == 0xE0C2L) < l_1423)) <
                      p_62) &&
                     0x32B2F135L);
                g_463[p_60] &= (safe_rshift_func_uint16_t_u_s(
                    (p_60 ^
                     (safe_mul_func_uint16_t_u_u(
                         (((safe_sub_func_int16_t_s_s(
                               (((safe_mod_func_int8_t_s_s(
                                     5L,
                                     (safe_mul_func_int8_t_s_s(
                                         (safe_sub_func_int16_t_s_s(
                                             (((safe_mod_func_int16_t_s_s(
                                                   (safe_sub_func_uint16_t_u_u(
                                                       (g_1089[6] &&
                                                        (safe_div_func_int16_t_s_s(
                                                            (p_61 &
                                                             ((safe_mod_func_int32_t_s_s(
                                                                  (safe_add_func_uint16_t_u_u(
                                                                      (safe_lshift_func_int8_t_s_u(
                                                                          ((~1UL) &&
                                                                           ((0xC8DA6783L &&
                                                                             (((safe_sub_func_int16_t_s_s(
                                                                                   ((safe_add_func_int16_t_s_s(
                                                                                        (p_58 &&
                                                                                         ((g_362 !=
                                                                                           1UL) <=
                                                                                          g_205)),
                                                                                        p_60)) ||
                                                                                    l_1264
                                                                                        [4]),
                                                                                   p_62)) ==
                                                                               l_1264
                                                                                   [g_1201]) &&
                                                                              0x600BL)) <=
                                                                            l_1264
                                                                                [p_60])),
                                                                          l_1452
                                                                              [2])),
                                                                      0x1A41L)),
                                                                  g_186)) !=
                                                              1UL)),
                                                            l_1264[p_60]))),
                                                       p_62)),
                                                   l_1250)) |
                                               p_62) ||
                                              0UL),
                                             g_361)),
                                         l_1264[p_60])))) != g_1089[5]) ==
                                g_365),
                               p_58)) == g_205) &
                          g_734),
                         g_205))),
                    11));
              }
              g_365 = l_834;
              g_870 =
                  (g_205 ==
                   (safe_lshift_func_int16_t_s_u(
                       ((g_463[0] >
                         ((((safe_lshift_func_uint8_t_u_u(
                                ((((((safe_add_func_uint16_t_u_u(
                                         ((safe_mod_func_int8_t_s_s(
                                              (safe_lshift_func_int16_t_s_s(
                                                  (safe_rshift_func_uint8_t_u_u(
                                                      (((p_62 <= l_1423) &&
                                                        p_62) &&
                                                       (safe_add_func_int16_t_s_s(
                                                           ((safe_lshift_func_uint8_t_u_s(
                                                                (safe_mod_func_int8_t_s_s(
                                                                    (g_734 &&
                                                                     (safe_div_func_int16_t_s_s(
                                                                         g_493,
                                                                         ((safe_div_func_int8_t_s_s(
                                                                              l_1475
                                                                                  [0],
                                                                              0x56L)) &&
                                                                          l_928)))),
                                                                    g_463[4])),
                                                                g_27[6])) ||
                                                            0UL),
                                                           g_420))),
                                                      1)),
                                                  3)),
                                              l_1250)) > g_361),
                                         p_62)) ^
                                     0xEFL) |
                                    l_1476) ||
                                   g_4) != 0x5C945727L) ||
                                 0x5DL),
                                g_361)) |
                            g_493) &
                           0x59L) &&
                          p_58)) > 0x3EC9L),
                       p_58)));
              if (g_493) {
                int16_t l_1489 = 0xC2FEL;
                g_870 =
                    ((+l_1099[4][0]) >=
                     (((((((p_61 >= 0xB7L) !=
                           (0x5B02DFFEL !=
                            (safe_sub_func_uint16_t_u_u(
                                ((-6L) &
                                 (safe_rshift_func_int16_t_s_u(
                                     (safe_mod_func_uint8_t_u_u(
                                         ((0x47BE737CL & (p_58 <= g_27[5])) &
                                          p_58),
                                         g_870)),
                                     p_61))),
                                0xBBBCL)))) |
                          g_463[0]) <= 4294967291UL) < p_59) &
                       0x5DFFB796L) |
                      l_850));
                p_61 = (safe_lshift_func_uint16_t_u_s(
                    (safe_mul_func_uint16_t_u_u(
                        (safe_div_func_uint8_t_u_u(
                            p_62, ((0xECL || (g_463[0] == 0xA6L)) ^
                                   (4UL && l_1489)))),
                        (safe_rshift_func_int8_t_s_s(
                            (safe_sub_func_uint16_t_u_u(
                                0UL,
                                (0x94E9L ^ (safe_unary_minus_func_uint32_t_u(
                                               g_1089[1]))))),
                            6)))),
                    6));
                l_1260[2][4][1] =
                    (((0x06L <=
                       ((1L == (safe_sub_func_uint8_t_u_u(0UL, g_1089[1]))) &
                        (p_59 >
                         (0xE069L &
                          (safe_unary_minus_func_int16_t_s(
                              ((g_4 ==
                                (((!(safe_rshift_func_uint16_t_u_s(
                                      (safe_lshift_func_int8_t_s_s(g_27[6], 5)),
                                      5))) ^
                                  (l_1253 > (-1L))) <= 0UL)) <= p_62))))))) ||
                      0x1FL) <= l_1264[4]);
              } else {
                int16_t l_1502 = 0x0AE4L;
                l_1475[0] = 0L;
                l_1034 = l_1502;
              }
            }

            p_61 = (safe_lshift_func_uint16_t_u_s(
                (safe_mul_func_uint16_t_u_u(
                    (safe_div_func_uint8_t_u_u(
                        p_62,
                        ((0xECL || (g_463[0] == 0xA6L)) ^ (4UL && l_1489)))),
                    (safe_rshift_func_int8_t_s_s(
                        (safe_sub_func_uint16_t_u_u(
                            0UL, (0x94E9L ^ (safe_unary_minus_func_uint32_t_u(
                                                g_1089[1]))))),
                        6)))),
                6));

            {
              int8_t l_968 = 0x1FL;
              const int8_t l_1108 = 0xC5L;
              uint32_t l_1169 = 1UL;
              int32_t l_1250 = 3L;
              int32_t l_1253 = (-1L);
              int32_t l_1258[2][9] = {{0xD261F19EL, (-4L), 5L, 5L, (-4L),
                                       0xD261F19EL, (-4L), 5L, 5L},
                                      {0xD261F19EL, (-4L), 5L, 5L, (-4L),
                                       0xD261F19EL, (-4L), 5L, 5L}};
              int16_t l_1505 = (-1L);
              uint32_t l_1506[7][8] = {
                  {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
                   4294967291UL, 4294967289UL, 0xC871E012L},
                  {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
                   4294967291UL, 4294967289UL, 0xC871E012L},
                  {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
                   4294967291UL, 4294967289UL, 0xC871E012L},
                  {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
                   4294967291UL, 4294967289UL, 0xC871E012L},
                  {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
                   4294967291UL, 4294967289UL, 0xC871E012L},
                  {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
                   4294967291UL, 4294967289UL, 0xC871E012L},
                  {0UL, 0xC871E012L, 4294967289UL, 4294967291UL, 0x690DE275L,
                   4294967291UL, 4294967289UL, 0xC871E012L}};
              int32_t l_1529 = 0x4EB8D007L;
              int i, j;
              if ((safe_add_func_int32_t_s_s(0x45062FE5L, g_463[p_60]))) {
                int32_t l_973 = 0xDBBB214EL;
                int i;
                g_463[p_60] =
                    ((safe_mul_func_int16_t_s_s(
                         0xFE61L,
                         ((0x6B5FL >=
                           ((safe_mod_func_uint8_t_u_u(
                                g_463[p_60],
                                (0UL ^ (safe_sub_func_int8_t_s_s(
                                           p_62, ((safe_sub_func_int16_t_s_s(
                                                      l_851, 0x26F0L)) >
                                                  (0L <= 4294967290UL))))))) >
                            p_60)) ^
                          0x753D1A51L))) &
                     0x2A37BEC8L);
                for (g_186 = (-22); (g_186 <= 54); ++g_186) {
                  uint32_t l_919[10][2] = {
                      {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                      {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                      {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                      {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L},
                      {0xB7E2B343L, 0x15F45458L}, {0xB7E2B343L, 0x15F45458L}};
                  int i, j;
                  if ((safe_mod_func_int8_t_s_s(g_362, p_59))) {
                    l_850 =
                        ((0x34L & (g_734 >= (safe_lshift_func_uint16_t_u_s(
                                                g_870, 9)))) >=
                         ((safe_div_func_int8_t_s_s(
                              (safe_lshift_func_uint16_t_u_u(
                                  (p_59 &
                                   (safe_add_func_int16_t_s_s(
                                       ((!((safe_lshift_func_uint16_t_u_u(
                                               ((1L !=
                                                 (((((l_834 !=
                                                      (safe_lshift_func_uint16_t_u_u(
                                                          (g_4 ^
                                                           (!((safe_mul_func_int16_t_s_s(
                                                                  (safe_lshift_func_uint8_t_u_u(
                                                                      p_62, 6)),
                                                                  (safe_mod_func_int8_t_s_s(
                                                                      ((l_851 ||
                                                                        p_62) <
                                                                       g_365),
                                                                      l_850)))) <=
                                                              65535UL))),
                                                          0))) |
                                                     g_4) > l_851) <= p_62) ^
                                                  g_753)) == g_463[p_60]),
                                               p_60)) <= 0x3B5BL)) >
                                        g_463[p_60]),
                                       g_365))),
                                  g_361)),
                              g_734)) != g_753));
                    if (g_870)
                      break;
                    return g_493;
                  } else {
                    const int32_t l_903 = 5L;
                    l_918 |= (safe_mod_func_int16_t_s_s(
                        ((safe_add_func_uint32_t_u_u(
                             (safe_mul_func_int16_t_s_s(p_62, g_27[6])),
                             g_734)) &&
                         l_851),
                        (+(1L <
                           ((safe_add_func_uint32_t_u_u(
                                (((((safe_lshift_func_int8_t_s_u(
                                        (safe_sub_func_int16_t_s_s(
                                            (safe_mod_func_int32_t_s_s(
                                                (safe_div_func_int16_t_s_s(
                                                    ((l_903 ||
                                                      (((safe_add_func_uint16_t_u_u(
                                                            ((safe_lshift_func_uint8_t_u_u(
                                                                 p_59, 4)) !=
                                                             (~((safe_mul_func_int16_t_s_s(
                                                                    (safe_mod_func_int32_t_s_s(
                                                                        (safe_div_func_int16_t_s_s(
                                                                            ((safe_div_func_uint32_t_u_u(
                                                                                 (+(g_362 ^
                                                                                    (safe_mul_func_int16_t_s_s(
                                                                                        ((-1L) &&
                                                                                         p_61),
                                                                                        l_850)))),
                                                                                 l_849)) |
                                                                             p_59),
                                                                            g_463
                                                                                [4])),
                                                                        0x4C30C153L)),
                                                                    l_851)) ||
                                                                g_186))),
                                                            g_362)) ||
                                                        0x80L) &
                                                       9L)) &&
                                                     p_60),
                                                    65534UL)),
                                                0xE9AD882DL)),
                                            g_493)),
                                        6)) |
                                    0x59L) < g_4) &
                                  g_463[p_60]) != p_62),
                                l_903)) ||
                            p_60)))));
                    l_928 =
                        ((((((l_919[1][0] ^ g_361) ==
                             (9L |
                              (((safe_lshift_func_uint16_t_u_s(
                                    ((p_62 < (~(safe_sub_func_int8_t_s_s(
                                                 g_463[p_60],
                                                 (l_918 |
                                                  (safe_div_func_int8_t_s_s(
                                                      (safe_sub_func_int8_t_s_s(
                                                          (-1L), 0x5BL)),
                                                      l_918))))))) ||
                                     p_58),
                                    5)) &
                                p_61) |
                               g_463[p_60]))) != (-5L)) == g_463[2]) > p_58) &
                         g_186);
                  }
                }
                if (l_928) {
                  p_61 = (((+(safe_div_func_int32_t_s_s(p_62, p_58))) !=
                           g_463[p_60]) >
                          ((safe_add_func_uint32_t_u_u(
                               ((g_420 || l_851) < g_150),
                               (((p_59 <= g_753) ==
                                 (safe_add_func_int16_t_s_s(
                                     (!(safe_lshift_func_int8_t_s_u(
                                         ((safe_lshift_func_int16_t_s_u(
                                              l_928, g_365)) ^
                                          g_186),
                                         7))),
                                     g_463[p_60]))) &&
                                p_59))) >= g_362));
                  for (p_61 = 0; (p_61 <= (-22));
                       p_61 = safe_sub_func_uint32_t_u_u(p_61, 1)) {
                    const uint32_t l_941 = 0xAC0362BEL;
                    if (l_941)
                      break;
                    g_463[p_60] = (-10L);
                  }
                  for (g_362 = 1; (g_362 <= 5); g_362 += 1) {
                    int i;
                    if (g_463[g_362])
                      break;
                    p_61 = 0xFD45FC42L;
                    l_849 = 0xCB027895L;
                  }
                } else {
                  uint8_t l_966 = 0x54L;
                  int32_t l_967 = 0x418378F9L;
                  int32_t l_972 = 0xDCA573D8L;
                  uint16_t l_975 = 5UL;
                  if (l_851)
                    break;
                  g_870 =
                      ((safe_lshift_func_int8_t_s_u(
                           ((0x049DL ^
                             (safe_mul_func_uint16_t_u_u(
                                 (safe_add_func_int32_t_s_s(
                                     (safe_add_func_int32_t_s_s(
                                         (safe_mul_func_uint8_t_u_u(g_463[p_60],
                                                                    p_59)),
                                         (safe_lshift_func_int16_t_s_s(
                                             (g_463[2] &&
                                              (4294967295UL <
                                               ((safe_rshift_func_int8_t_s_s(
                                                    (-1L),
                                                    (((safe_add_func_int16_t_s_s(
                                                          (((safe_add_func_uint32_t_u_u(
                                                                ((safe_div_func_int32_t_s_s(
                                                                     g_870,
                                                                     (safe_add_func_int8_t_s_s(
                                                                         l_918,
                                                                         2L)))) <
                                                                 4294967288UL),
                                                                0x13E14289L)) &
                                                            p_62) ||
                                                           g_493),
                                                          0x36E5L)) != l_966) <=
                                                     g_362))) < p_62))),
                                             l_834)))),
                                     l_966)),
                                 g_420))) <= l_966),
                           7)) ||
                       g_463[0]);
                  ++l_975;
                }
              } else {
                uint32_t l_986[8][9][3] = {
                    {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                    {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                    {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                    {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                    {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                    {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                    {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}},
                    {{0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L},
                     {0xE4C57AE4L, 0xDC0C2B27L, 0x6DCC79A1L}}};
                int i, j, k;
                if ((safe_sub_func_uint16_t_u_u(
                        0x8860L,
                        (safe_sub_func_uint16_t_u_u(
                            g_365,
                            (safe_add_func_uint16_t_u_u(
                                (0x2DL <= (safe_lshift_func_uint16_t_u_u(
                                              l_986[1][3][1], 6))),
                                (((((g_27[6] ^
                                     (safe_add_func_int8_t_s_s(
                                         (safe_sub_func_uint8_t_u_u(
                                             (safe_sub_func_int8_t_s_s(
                                                 ((l_968 !=
                                                   ((0x97L &&
                                                     (p_58 !=
                                                      (safe_sub_func_uint8_t_u_u(
                                                          (safe_mod_func_uint8_t_u_u(
                                                              ((6L | p_60) <=
                                                               l_986[1][6][0]),
                                                              l_850)),
                                                          0x9AL)))) != 7L)) ^
                                                  l_968),
                                                 p_61)),
                                             p_59)),
                                         g_185))) == 6UL) == 0x0060DD85L) &&
                                  0x27L) > 255UL)))))))) {
                  g_365 |= (safe_unary_minus_func_uint16_t_u((p_58 > l_969)));
                } else {
                  uint8_t l_1060 = 0x5CL;
                  for (g_361 = 0; (g_361 >= 53);
                       g_361 = safe_add_func_uint16_t_u_u(g_361, 7)) {
                    uint16_t l_1022 = 65531UL;
                    g_463[p_60] = 2L;
                    g_870 = (safe_mul_func_uint8_t_u_u(
                        (safe_mod_func_int8_t_s_s(g_753, p_59)), g_365));
                    g_463[3] |=
                        (((safe_lshift_func_int8_t_s_s(
                              (-1L),
                              ((~((safe_div_func_int8_t_s_s(
                                      p_62,
                                      (safe_rshift_func_int8_t_s_u(
                                          (safe_add_func_int32_t_s_s(
                                              (safe_add_func_uint32_t_u_u(
                                                  0UL,
                                                  ((safe_mod_func_uint8_t_u_u(
                                                       (safe_lshift_func_int16_t_s_s(
                                                           g_420, 6)),
                                                       (safe_rshift_func_uint16_t_u_u(
                                                           (g_27[6] < p_61),
                                                           (safe_lshift_func_int8_t_s_s(
                                                               ((p_60 >
                                                                 ((g_753 >=
                                                                   g_870) <=
                                                                  l_986[4][1]
                                                                       [0])) !=
                                                                l_1022),
                                                               l_834)))))) |
                                                   0xFDL))),
                                              0xDFD5D61BL)),
                                          5)))) &
                                  l_918)) >= g_27[5]))) &
                          (-1L)) <= 4294967295UL);
                    p_61 = (0x1B5EF209L |
                            (safe_unary_minus_func_uint8_t_u(
                                (65535UL <=
                                 (0x40L <
                                  (safe_add_func_int32_t_s_s(
                                      l_849,
                                      (safe_rshift_func_int8_t_s_u(
                                          ((safe_sub_func_uint16_t_u_u(
                                               (safe_div_func_uint16_t_u_u(
                                                   g_493,
                                                   (safe_mul_func_uint8_t_u_u(
                                                       (l_986[0][4][1] != 5L),
                                                       l_1034)))),
                                               (safe_sub_func_uint8_t_u_u(
                                                   (safe_mod_func_int16_t_s_s(
                                                       0x1AAAL, g_150)),
                                                   0x03L)))) <= 0L),
                                          g_361)))))))));
                  }
                  l_1060 =
                      (((safe_sub_func_int32_t_s_s(p_58, (-5L))) ||
                        (safe_add_func_int32_t_s_s(
                            (safe_lshift_func_int16_t_s_u(p_61, 14)),
                            (((safe_mod_func_uint8_t_u_u(
                                  (!((safe_add_func_int16_t_s_s(
                                         (p_59 |
                                          (safe_lshift_func_int8_t_s_u(
                                              (safe_rshift_func_uint16_t_u_s(
                                                  0x29D9L,
                                                  (safe_div_func_uint32_t_u_u(
                                                      0UL, g_753)))),
                                              0))),
                                         (safe_unary_minus_func_uint32_t_u(
                                             (l_968 !=
                                              (safe_rshift_func_int8_t_s_u(
                                                  (safe_sub_func_int8_t_s_s(
                                                      (l_968 ^ 0x0044B4B1L),
                                                      p_61)),
                                                  6))))))) |
                                     0x23L)),
                                  0x5DL)) ||
                              0xDC5166B7L) ^
                             0x188DL)))) > p_60);
                  p_61 =
                      ((((safe_mul_func_int8_t_s_s(
                             ((+(g_185 <
                                 (safe_sub_func_int8_t_s_s(
                                     l_851,
                                     ((safe_mul_func_uint16_t_u_u(
                                          (((safe_rshift_func_uint8_t_u_u(
                                                ((safe_lshift_func_int8_t_s_s(
                                                     p_61,
                                                     ((safe_mod_func_uint8_t_u_u(
                                                          ((7UL &
                                                            ((((safe_lshift_func_uint16_t_u_u(
                                                                   (safe_add_func_uint8_t_u_u(
                                                                       0x1EL,
                                                                       0x44L)),
                                                                   ((safe_lshift_func_uint16_t_u_u(
                                                                        (safe_div_func_uint32_t_u_u(
                                                                            (((safe_div_func_uint32_t_u_u(
                                                                                  ((g_493 ^
                                                                                    (safe_mul_func_int8_t_s_s(
                                                                                        ((safe_lshift_func_uint8_t_u_u(
                                                                                             ((safe_sub_func_uint32_t_u_u(
                                                                                                  4294967294UL,
                                                                                                  (0x617AL >=
                                                                                                   0xF678L))) !=
                                                                                              g_362),
                                                                                             p_61)) &&
                                                                                         4294967295UL),
                                                                                        g_463
                                                                                            [0]))) <=
                                                                                   p_60),
                                                                                  l_850)) &
                                                                              0UL) <=
                                                                             g_493),
                                                                            4294967292UL)),
                                                                        11)) <
                                                                    p_61))) ^
                                                               l_968) ==
                                                              l_971) &&
                                                             l_986[0][1][2])) ==
                                                           p_58),
                                                          0x93L)) > p_60))) ==
                                                 p_58),
                                                3)) <= l_834) >= g_186),
                                          g_185)) == l_850))))) ||
                              0xB5CAL),
                             g_27[6])) >= g_753) > p_62) == 0UL);
                  if (g_1089[1])
                    continue;
                }
                for (l_971 = (-14); (l_971 <= 26); l_971++) {
                  l_928 &= (safe_unary_minus_func_uint16_t_u(
                      (g_463[0] ==
                       ((safe_add_func_uint16_t_u_u(
                            (((safe_div_func_uint16_t_u_u(
                                  (0L < (safe_mod_func_uint16_t_u_u(
                                            l_1099[9][1], g_463[p_60]))),
                                  (safe_add_func_int16_t_s_s(
                                      (g_734 | ((p_58 < (0x7CL && 0x56L)) ^
                                                (((((p_59 || l_834) && p_59) <
                                                   g_27[6]) &&
                                                  l_986[1][3][1]) ^
                                                 7L))),
                                      p_62)))) < l_918) ||
                             0xE8L),
                            l_834)) <= p_60))));
                  g_463[0] = g_753;
                }
                if (p_61) {
                  uint32_t l_1114 = 18446744073709551615UL;
                  g_463[0] = p_58;
                  l_928 |= (safe_rshift_func_uint16_t_u_u(p_58, 6));
                  g_365 |=
                      ((((((((p_61 >=
                              (l_1034 <=
                               (((0x95L <= g_753) |
                                 (safe_rshift_func_uint16_t_u_u(
                                     ((safe_sub_func_int16_t_s_s(
                                          l_1108,
                                          (1L ||
                                           (safe_mod_func_uint32_t_u_u(
                                               (safe_lshift_func_int16_t_s_s(
                                                   l_986[1][3][1], 9)),
                                               7L))))) <
                                      ((g_420 > g_186) && p_61)),
                                     0))) > p_58))) &&
                             l_1113[0]) <= 0x5C091B7AL) >= g_4) == (-1L)) >
                         g_493) &
                        0x8E3F9787L) <= l_1114);
                } else {
                  uint8_t l_1120 = 0x1EL;
                  int32_t l_1160 = 0x9C031653L;
                  p_61 = (safe_mul_func_uint8_t_u_u(
                      (g_734 !=
                       (((-5L) || ((safe_unary_minus_func_uint16_t_u(l_849)) |
                                   ((safe_div_func_int8_t_s_s(p_60, l_1120)) >=
                                    0x6DL))) < l_1120)),
                      (safe_rshift_func_uint8_t_u_s(
                          (((safe_sub_func_int32_t_s_s(
                                l_1113[0], (251UL ^ 0xDFL))) == g_870) > l_918),
                          6))));
                  if (((((safe_sub_func_int8_t_s_s(
                             (((0x4AL == (safe_lshift_func_int16_t_s_u(
                                             (l_986[2][1][1] || p_59), 2))) &
                               ((safe_unary_minus_func_int8_t_s(
                                    (safe_div_func_uint8_t_u_u(
                                        ((safe_sub_func_uint16_t_u_u(
                                             g_185,
                                             ((safe_mod_func_uint8_t_u_u(
                                                  l_986[1][3][1],
                                                  (((g_493 >
                                                     (0x56L <
                                                      (safe_sub_func_int8_t_s_s(
                                                          l_1113[0],
                                                          0x65L)))) >= 0x83L) &
                                                   l_1120))) |
                                              0x8E174AC1L))) ||
                                         1UL),
                                        g_420)))) <= g_734)) < g_362),
                             g_186)) > l_834) ||
                        p_60) != l_1099[9][1])) {
                    p_61 = g_1089[1];
                  } else {
                    g_463[5] = (p_59 ^ p_62);
                  }
                  g_870 &=
                      (((((((safe_lshift_func_int8_t_s_s(
                                (safe_sub_func_int8_t_s_s(
                                    ((safe_sub_func_uint8_t_u_u(
                                         5UL,
                                         (safe_sub_func_uint16_t_u_u(
                                             ((g_362 &
                                               ((safe_rshift_func_int8_t_s_u(
                                                    ((safe_sub_func_int8_t_s_s(
                                                         (safe_sub_func_uint32_t_u_u(
                                                             (safe_add_func_uint8_t_u_u(
                                                                 (safe_lshift_func_int16_t_s_s(
                                                                     l_974, 4)),
                                                                 g_493)),
                                                             l_1120)),
                                                         0x3BL)) ==
                                                     (((safe_sub_func_uint16_t_u_u(
                                                           p_59, (-2L))) <
                                                       0x3A956D3AL) &
                                                      p_58)),
                                                    2)) == g_1089[3])) ==
                                              g_186),
                                             0x2452L)))) != p_61),
                                    1UL)),
                                g_185)) ^
                            p_60) &&
                           l_1120) ^
                          0xD2CFL) >= l_1160) > p_59) == 0UL);
                }
                return g_362;
              }
              for (l_968 = 0; (l_968 <= 0); l_968 += 1) {
                if (p_61)
                  break;
              }
              if (((safe_lshift_func_uint8_t_u_s(
                       ((safe_lshift_func_uint8_t_u_u(
                            ((((((~(safe_mod_func_int16_t_s_s(
                                     1L,
                                     (safe_lshift_func_int16_t_s_s(
                                         (l_1169 &&
                                          ((safe_mul_func_int16_t_s_s(
                                               g_27[6], 0xA045L)) <
                                           (safe_sub_func_int32_t_s_s(
                                               (0x21C05D77L |
                                                (!((safe_rshift_func_int8_t_s_u(
                                                       (l_850 &&
                                                        (safe_add_func_int16_t_s_s(
                                                            (safe_add_func_int8_t_s_s(
                                                                (((safe_div_func_uint16_t_u_u(
                                                                      (safe_add_func_int32_t_s_s(
                                                                          (safe_sub_func_int32_t_s_s(
                                                                              2L,
                                                                              (l_928 <
                                                                               (((safe_lshift_func_int16_t_s_u(
                                                                                     (((g_463
                                                                                            [p_60] &&
                                                                                        l_918) |
                                                                                       g_493) <
                                                                                      1UL),
                                                                                     p_62)) >
                                                                                 g_27[3]) <=
                                                                                l_918)))),
                                                                          g_186)),
                                                                      g_753)) ^
                                                                  0x5BL) >=
                                                                 p_62),
                                                                p_61)),
                                                            g_365))),
                                                       g_27[1])) >= g_463[5]))),
                                               g_463[0])))),
                                         g_186))))) > l_1113[0]) > 1L) ||
                               l_1099[7][1]) > 1UL) |
                             1UL),
                            p_62)) &
                        p_58),
                       p_61)) != p_60)) {
                uint8_t l_1218 = 0x9AL;
                int32_t l_1219 = 0xF3C6DCF4L;
                int32_t l_1247 = 2L;
                int32_t l_1248 = 0x3BACB270L;
                int32_t l_1249 = (-7L);
                int32_t l_1252[8][1] = {{1L}, {1L}, {1L}, {1L},
                                        {1L}, {1L}, {1L}, {1L}};
                int32_t l_1265 = 1L;
                uint8_t l_1266 = 7UL;
                int i, j;
                if ((g_753 ||
                     (((((p_60 !=
                          (safe_mul_func_int8_t_s_s(
                              (safe_mul_func_int8_t_s_s(
                                  (-5L),
                                  ((((safe_mod_func_uint16_t_u_u(
                                         p_61,
                                         (safe_sub_func_uint8_t_u_u(
                                             ((((safe_rshift_func_int8_t_s_u(
                                                    (255UL ||
                                                     ((safe_unary_minus_func_int16_t_s(
                                                          g_27[6])) >
                                                      (p_60 |
                                                       (safe_div_func_int16_t_s_s(
                                                           (((g_27[6] |
                                                              (0x69E9L >=
                                                               p_62)) != p_58) <
                                                            g_493),
                                                           p_60))))),
                                                    l_1169)) &
                                                l_1108) >= 9UL) != (-4L)),
                                             p_62)))) &&
                                     0xFAL) ^
                                    g_463[0]) <= p_62))),
                              p_59))) |
                         l_918) &
                        g_1201) >= p_61) == p_60))) {
                  int8_t l_1213 = (-1L);
                  int32_t l_1246[4][4];
                  int32_t l_1254 = 0xB057E000L;
                  int32_t l_1261 = (-5L);
                  int i, j;
                  for (i = 0; i < 4; i++) {
                    for (j = 0; j < 4; j++)
                      l_1246[i][j] = 1L;
                  }
                  for (g_753 = 0; (g_753 <= 1); g_753 += 1) {
                    int i, j;
                    l_849 = (safe_div_func_uint32_t_u_u(
                        (l_1099[(g_753 + 4)][g_753] ^
                         ((((safe_lshift_func_int8_t_s_u(
                                ((safe_rshift_func_uint8_t_u_u(g_870, 2)) ||
                                 p_58),
                                7)) !=
                            ((safe_sub_func_uint16_t_u_u(
                                 (safe_unary_minus_func_uint8_t_u((
                                     (safe_mul_func_int16_t_s_s(
                                         (8UL ==
                                          (l_1213 &&
                                           ((l_849 == g_734) >=
                                            ((65527UL ==
                                              (safe_rshift_func_uint8_t_u_u(
                                                  ((safe_lshift_func_uint16_t_u_u(
                                                       (l_1099[(g_753 + 4)]
                                                              [g_753] ^
                                                        g_493),
                                                       10)) == g_365),
                                                  6))) <= 0xBC26A47CL)))),
                                         g_186)) >= g_1089[1]))),
                                 p_59)) |
                             g_463[p_60])) == g_361) < 0xD5L)),
                        p_61));
                    l_1219 |= l_1218;
                    p_61 = (safe_mul_func_uint8_t_u_u(
                        ((safe_rshift_func_int8_t_s_s(
                             p_59,
                             (safe_div_func_uint8_t_u_u(
                                 ((safe_add_func_int16_t_s_s(
                                      (((g_1089[1] &
                                         ((((g_420 &
                                             (p_61 <
                                              (safe_lshift_func_uint16_t_u_s(
                                                  ((~l_1230) ||
                                                   (safe_add_func_uint32_t_u_u(
                                                       ((safe_lshift_func_uint16_t_u_u(
                                                            ((safe_rshift_func_uint16_t_u_s(
                                                                 ((safe_mod_func_int8_t_s_s(
                                                                      ((safe_sub_func_int8_t_s_s(
                                                                           (1L ^
                                                                            g_362),
                                                                           ((safe_mul_func_uint16_t_u_u(
                                                                                ((safe_rshift_func_uint16_t_u_u(
                                                                                     l_1099
                                                                                         [(g_753 +
                                                                                           4)]
                                                                                         [g_753],
                                                                                     p_59)) >=
                                                                                 7L),
                                                                                p_58)) |
                                                                            0xDFDDL))) &&
                                                                       g_4),
                                                                      6UL)) &&
                                                                  l_1245),
                                                                 10)) &&
                                                             g_361),
                                                            11)) > 0xF5L),
                                                       l_1218))),
                                                  l_971)))) > g_1089[1]) <
                                           p_58) == (-1L))) >= l_834) ==
                                       0xF5001292L),
                                      p_61)) |
                                  l_1213),
                                 g_27[6])))) <= g_463[1]),
                        1L));
                  }
                  ++l_1266;
                  for (l_1245 = 2; (l_1245 > 30);
                       l_1245 = safe_add_func_uint16_t_u_u(l_1245, 1)) {
                    uint8_t l_1289 = 0UL;
                    g_365 &= l_928;
                    l_1290 |=
                        ((safe_rshift_func_uint8_t_u_s(
                             (safe_mod_func_uint8_t_u_u(
                                 l_834,
                                 (safe_sub_func_uint32_t_u_u(
                                     (6UL >= (safe_lshift_func_int16_t_s_s(
                                                 (safe_div_func_int32_t_s_s(
                                                     p_60, l_849)),
                                                 0))),
                                     (safe_add_func_uint16_t_u_u(
                                         (safe_lshift_func_int8_t_s_s(
                                             ((p_60 &&
                                               ((safe_mod_func_uint16_t_u_u(
                                                    ((((0xEF80L &
                                                        (safe_rshift_func_int16_t_s_s(
                                                            (+p_61), 12))) &&
                                                       (0x6C9FL | l_1247)) &
                                                      p_58) |
                                                     l_1289),
                                                    g_1089[1])) &
                                                g_734)) >= l_1253),
                                             2)),
                                         0xD86EL)))))),
                             0)) ||
                         l_1218);
                  }
                } else {
                  int16_t l_1347 = (-10L);
                  for (g_205 = 0; (g_205 <= 35); ++g_205) {
                    uint32_t l_1293[6][5][8] = {
                        {{0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL}},
                        {{0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL}},
                        {{0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL}},
                        {{0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL}},
                        {{0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL}},
                        {{0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL},
                         {0x8111B5F8L, 0x62C49F69L, 0x71B4D921L, 0xE2CB1869L,
                          0x62C49F69L, 7UL, 0xEAC00F75L, 8UL}}};
                    int i, j, k;
                    l_1293[4][2][6]--;
                    l_1249 = (safe_sub_func_uint32_t_u_u(
                        (((l_970 !=
                           ((((safe_div_func_int8_t_s_s(
                                  p_58,
                                  (safe_div_func_uint8_t_u_u(
                                      (safe_unary_minus_func_int8_t_s((
                                          (l_1264[6] >=
                                           (((safe_lshift_func_int8_t_s_u(
                                                 0L, l_1262)) > g_4) ==
                                            (p_61 >= l_1258[1][8]))) ^
                                          (((safe_div_func_uint8_t_u_u(
                                                (safe_unary_minus_func_int8_t_s((
                                                    safe_lshift_func_uint16_t_u_s(
                                                        (0x5665L != p_60),
                                                        5)))),
                                                l_1250)) != 0x53L) == 0xB1L)))),
                                      g_365)))) > g_27[3]) > 0x18L) <=
                            (-10L))) ||
                          g_186) != l_1250),
                        p_59));
                  }
                  if (g_361)
                    continue;
                  if (l_851) {
                    uint16_t l_1359 = 65534UL;
                    g_870 =
                        ((0UL &&
                          (g_420 &&
                           (safe_rshift_func_uint8_t_u_u(
                               ((safe_lshift_func_int16_t_s_u(
                                    (safe_mul_func_uint8_t_u_u(
                                        (safe_add_func_uint32_t_u_u(
                                            ((safe_lshift_func_int16_t_s_s(
                                                 (((((safe_sub_func_uint8_t_u_u(
                                                         (safe_lshift_func_uint16_t_u_u(
                                                             (safe_unary_minus_func_int8_t_s((safe_add_func_int32_t_s_s(
                                                                 ((65535UL <=
                                                                   (((safe_mod_func_uint32_t_u_u(
                                                                         ((g_186 &
                                                                           (((safe_add_func_uint32_t_u_u(
                                                                                 ((-1L) <
                                                                                  (safe_mul_func_int16_t_s_s(
                                                                                      g_493,
                                                                                      (safe_mod_func_int32_t_s_s(
                                                                                          (safe_sub_func_int16_t_s_s(
                                                                                              (safe_mul_func_uint16_t_u_u(
                                                                                                  g_27[6],
                                                                                                  0x6B95L)),
                                                                                              (0xE174BBB5L >
                                                                                               0x4523E2F4L))),
                                                                                          1UL))))),
                                                                                 4294967295UL)) ^
                                                                             p_62) ==
                                                                            0xD4645944L)) ==
                                                                          p_59),
                                                                         p_62)) &
                                                                     p_59) &
                                                                    g_186)) !=
                                                                  l_1258[1][2]),
                                                                 g_463[5])))),
                                                             g_27[0])),
                                                         0x77L)) |
                                                     g_463[p_60]) ^
                                                    l_1256) != 65533UL) >
                                                  l_850),
                                                 1)) &
                                             5UL),
                                            p_61)),
                                        p_59)),
                                    l_1249)) >= g_27[5]),
                               6)))) ^
                         0UL);
                    g_365 = (safe_lshift_func_uint8_t_u_u(
                        ((((safe_add_func_int32_t_s_s(
                               (l_1347 &&
                                ((safe_add_func_uint32_t_u_u(
                                     ((safe_lshift_func_uint16_t_u_u(
                                          (safe_sub_func_int16_t_s_s(
                                              (l_1354[0][1] !=
                                               (((-9L) == p_58) ==
                                                ((g_1089[6] !=
                                                  (safe_mul_func_int16_t_s_s(
                                                      l_1113[0],
                                                      (((((~(2UL <=
                                                             (~g_1089[1]))) &
                                                          (safe_mod_func_uint16_t_u_u(
                                                              0x02DBL,
                                                              65531UL))) <=
                                                         0x1742L) &&
                                                        5L) &&
                                                       p_62)))) &
                                                 3L))),
                                              l_1359)),
                                          l_1252[5][0])) < g_463[0]),
                                     l_1359)) |
                                 l_968)),
                               p_61)) != p_62) &&
                          0xA93F03F5L) &
                         p_59),
                        l_1354[0][1]));
                    l_1250 &=
                        (l_1354[0][1] <
                         ((((0L ==
                             ((l_974 ==
                               (((safe_sub_func_uint8_t_u_u(l_1347, g_27[6])) ==
                                 (l_1249 ^
                                  ((((safe_rshift_func_uint8_t_u_u(
                                         (safe_lshift_func_uint16_t_u_u(g_734,
                                                                        p_62)),
                                         ((0x4F8EL ^ g_362) & (-1L)))) >=
                                     g_361) |
                                    l_850) >= 0L))) != g_362)) >= l_1113[0])) !=
                            g_753) ||
                           0x3CL) <= l_1218));
                  } else {
                    p_61 ^= (safe_lshift_func_uint16_t_u_u(g_870, 13));
                    l_1256 ^= (safe_add_func_int32_t_s_s(
                        ((((safe_rshift_func_int8_t_s_u(
                               (safe_mul_func_int16_t_s_s(
                                   ((safe_sub_func_uint16_t_u_u(
                                        65535UL,
                                        ((safe_add_func_uint16_t_u_u(
                                             g_734,
                                             (safe_mod_func_int32_t_s_s(
                                                 g_361,
                                                 (safe_rshift_func_uint16_t_u_s(
                                                     (((p_59 &
                                                        (g_463[p_60] ^ g_186)) >
                                                       ((((safe_lshift_func_uint8_t_u_u(
                                                              ((((g_1089[1] &
                                                                  (safe_lshift_func_int8_t_s_s(
                                                                      (g_27[6] <=
                                                                       ((safe_rshift_func_int16_t_s_s(
                                                                            p_58,
                                                                            0)) <=
                                                                        (-5L))),
                                                                      2))) ^
                                                                 l_1252[4]
                                                                       [0]) >=
                                                                0xE4CE3C55L) >
                                                               (-1L)),
                                                              6)) ^
                                                          g_1089[6]) != p_60) <
                                                        g_150)) &
                                                      g_186),
                                                     5)))))) |
                                         p_62))) &
                                    0xCEE90828L),
                                   0xA1B2L)),
                               1)) <= (-1L)) < l_1264[9]) <= 2L),
                        0x79B95C6FL));
                    if (g_734)
                      break;
                    g_870 ^= l_1258[0][2];
                  }
                  p_61 = 0x831162D3L;
                }
              } else {
                uint16_t l_1398 = 1UL;
                int8_t l_1423 = 1L;
                int32_t l_1475[3];
                int16_t l_1504 = 0x0AA6L;
                int8_t l_1528 = 0x3EL;
                int i;
                for (i = 0; i < 3; i++)
                  l_1475[i] = 1L;
                for (g_1201 = 2; (g_1201 <= 9); g_1201 += 1) {
                  int i;
                  if ((safe_lshift_func_int8_t_s_s(l_1264[p_60], 2))) {
                    const uint8_t l_1392 = 0UL;
                    return l_1392;
                  } else {
                    int8_t l_1397 = (-1L);
                    int i;
                    l_1264[g_1201] = (safe_add_func_uint32_t_u_u(
                        (safe_mul_func_int8_t_s_s(l_851, l_1397)),
                        ((g_205 || 6L) > (g_4 <= (-1L)))));
                    ++l_1398;
                    g_870 =
                        ((((-1L) &
                           ((((safe_add_func_uint32_t_u_u(
                                  (safe_add_func_uint8_t_u_u(
                                      248UL,
                                      (safe_rshift_func_uint16_t_u_s(
                                          p_62,
                                          ((((safe_rshift_func_uint16_t_u_s(
                                                 (safe_add_func_uint16_t_u_u(
                                                     ((safe_add_func_int32_t_s_s(
                                                          ((safe_lshift_func_uint8_t_u_s(
                                                               0xF7L,
                                                               (safe_lshift_func_uint8_t_u_s(
                                                                   (0UL <
                                                                    g_870),
                                                                   4)))) !=
                                                           (-1L)),
                                                          (safe_lshift_func_int16_t_s_u(
                                                              (g_420 &
                                                               (safe_sub_func_uint16_t_u_u(
                                                                   ((((((safe_mul_func_int16_t_s_s(
                                                                            l_971,
                                                                            g_27[6])) ||
                                                                        l_1230) >
                                                                       l_968) <
                                                                      g_365) !=
                                                                     p_61) ^
                                                                    0x28333F6AL),
                                                                   0UL))),
                                                              p_58)))) > g_420),
                                                     0UL)),
                                                 12)) >= p_61) != g_420) !=
                                           l_1397))))),
                                  g_753)) >= g_27[2]) == 0xE0C2L) < l_1423)) <
                          p_62) &&
                         0x32B2F135L);
                    g_463[p_60] &= (safe_rshift_func_uint16_t_u_s(
                        (p_60 ^
                         (safe_mul_func_uint16_t_u_u(
                             (((safe_sub_func_int16_t_s_s(
                                   (((safe_mod_func_int8_t_s_s(
                                         5L,
                                         (safe_mul_func_int8_t_s_s(
                                             (safe_sub_func_int16_t_s_s(
                                                 (((safe_mod_func_int16_t_s_s(
                                                       (safe_sub_func_uint16_t_u_u(
                                                           (g_1089[6] &&
                                                            (safe_div_func_int16_t_s_s(
                                                                (p_61 &
                                                                 ((safe_mod_func_int32_t_s_s(
                                                                      (safe_add_func_uint16_t_u_u(
                                                                          (safe_lshift_func_int8_t_s_u(
                                                                              ((~1UL) &&
                                                                               ((0xC8DA6783L &&
                                                                                 (((safe_sub_func_int16_t_s_s(
                                                                                       ((safe_add_func_int16_t_s_s(
                                                                                            (p_58 &&
                                                                                             ((g_362 !=
                                                                                               1UL) <=
                                                                                              g_205)),
                                                                                            p_60)) ||
                                                                                        l_1264
                                                                                            [4]),
                                                                                       p_62)) ==
                                                                                   l_1264
                                                                                       [g_1201]) &&
                                                                                  0x600BL)) <=
                                                                                l_1264
                                                                                    [p_60])),
                                                                              l_1452
                                                                                  [2])),
                                                                          0x1A41L)),
                                                                      g_186)) !=
                                                                  1UL)),
                                                                l_1264[p_60]))),
                                                           p_62)),
                                                       l_1250)) |
                                                   p_62) ||
                                                  0UL),
                                                 g_361)),
                                             l_1264[p_60])))) != g_1089[5]) ==
                                    g_365),
                                   p_58)) == g_205) &
                              g_734),
                             g_205))),
                        11));
                  }
                  g_365 = l_834;
                  g_870 =
                      (g_205 ==
                       (safe_lshift_func_int16_t_s_u(
                           ((g_463[0] >
                             ((((safe_lshift_func_uint8_t_u_u(
                                    ((((((safe_add_func_uint16_t_u_u(
                                             ((safe_mod_func_int8_t_s_s(
                                                  (safe_lshift_func_int16_t_s_s(
                                                      (safe_rshift_func_uint8_t_u_u(
                                                          (((p_62 <= l_1423) &&
                                                            p_62) &&
                                                           (safe_add_func_int16_t_s_s(
                                                               ((safe_lshift_func_uint8_t_u_s(
                                                                    (safe_mod_func_int8_t_s_s(
                                                                        (g_734 &&
                                                                         (safe_div_func_int16_t_s_s(
                                                                             g_493,
                                                                             ((safe_div_func_int8_t_s_s(
                                                                                  l_1475
                                                                                      [0],
                                                                                  0x56L)) &&
                                                                              l_928)))),
                                                                        g_463
                                                                            [4])),
                                                                    g_27[6])) ||
                                                                0UL),
                                                               g_420))),
                                                          1)),
                                                      3)),
                                                  l_1250)) > g_361),
                                             p_62)) ^
                                         0xEFL) |
                                        l_1476) ||
                                       g_4) != 0x5C945727L) ||
                                     0x5DL),
                                    g_361)) |
                                g_493) &
                               0x59L) &&
                              p_58)) > 0x3EC9L),
                           p_58)));
                  if (g_493) {
                    int16_t l_1489 = 0xC2FEL;
                    g_870 = ((+l_1099[4][0]) >=
                             (((((((p_61 >= 0xB7L) !=
                                   (0x5B02DFFEL !=
                                    (safe_sub_func_uint16_t_u_u(
                                        ((-6L) & (safe_rshift_func_int16_t_s_u(
                                                     (safe_mod_func_uint8_t_u_u(
                                                         ((0x47BE737CL &
                                                           (p_58 <= g_27[5])) &
                                                          p_58),
                                                         g_870)),
                                                     p_61))),
                                        0xBBBCL)))) |
                                  g_463[0]) <= 4294967291UL) < p_59) &
                               0x5DFFB796L) |
                              l_850));
                    p_61 = (safe_lshift_func_uint16_t_u_s(
                        (safe_mul_func_uint16_t_u_u(
                            (safe_div_func_uint8_t_u_u(
                                p_62, ((0xECL || (g_463[0] == 0xA6L)) ^
                                       (4UL && l_1489)))),
                            (safe_rshift_func_int8_t_s_s(
                                (safe_sub_func_uint16_t_u_u(
                                    0UL, (0x94E9L ^
                                          (safe_unary_minus_func_uint32_t_u(
                                              g_1089[1]))))),
                                6)))),
                        6));
                    l_1260[2][4][1] =
                        (((0x06L <=
                           ((1L ==
                             (safe_sub_func_uint8_t_u_u(0UL, g_1089[1]))) &
                            (p_59 >
                             (0xE069L &
                              (safe_unary_minus_func_int16_t_s(
                                  ((g_4 == (((!(safe_rshift_func_uint16_t_u_s(
                                                 (safe_lshift_func_int8_t_s_s(
                                                     g_27[6], 5)),
                                                 5))) ^
                                             (l_1253 > (-1L))) <= 0UL)) <=
                                   p_62))))))) ||
                          0x1FL) <= l_1264[4]);
                  } else {
                    int16_t l_1502 = 0x0AE4L;
                    l_1475[0] = 0L;
                    l_1034 = l_1502;
                  }
                }
                ++l_1506[3][4];
                for (l_1169 = 2; (l_1169 <= 6); l_1169 += 1) {
                  int i, j;
                  p_61 = (safe_mod_func_int8_t_s_s(
                      0xECL,
                      (safe_sub_func_int32_t_s_s(
                          (((safe_unary_minus_func_int32_t_s(
                                l_1506[(p_60 + 1)][(p_60 + 2)])) <
                            (((-9L) >
                              (((safe_mod_func_uint32_t_u_u(
                                    (2L ||
                                     (safe_div_func_uint32_t_u_u(
                                         (((safe_rshift_func_int8_t_s_s(
                                               l_1264[p_60],
                                               ((safe_mod_func_uint16_t_u_u(
                                                    (safe_add_func_int32_t_s_s(
                                                        (safe_mul_func_uint16_t_u_u(
                                                            (+g_753),
                                                            (g_1089[1] &
                                                             p_61))),
                                                        g_1201)),
                                                    g_1526[5][0])) <= p_58))) &&
                                           l_1527) < p_62),
                                         l_1506[(p_60 + 1)][(p_60 + 2)]))),
                                    l_1504)) > g_1201) <= (-1L))) != l_1528)) &&
                           l_1529),
                          0xDFA269F6L))));
                  g_870 |= (safe_rshift_func_uint8_t_u_u(
                      (safe_div_func_int32_t_s_s(
                          (safe_mul_func_uint16_t_u_u(
                              (safe_rshift_func_int8_t_s_u(
                                  (safe_mod_func_int32_t_s_s(1L, g_1503)),
                                  (safe_sub_func_int32_t_s_s(
                                      (((safe_add_func_int16_t_s_s(
                                            ((+0xA346A7BCL) != 0x2A60F066L),
                                            1L)) ||
                                        (safe_mod_func_uint16_t_u_u(
                                            (safe_lshift_func_uint8_t_u_u(
                                                (((safe_mod_func_uint8_t_u_u(
                                                      (g_1503 !=
                                                       (safe_div_func_uint32_t_u_u(
                                                           ((!(safe_add_func_int16_t_s_s(
                                                                (((safe_add_func_uint16_t_u_u(
                                                                      ((safe_mul_func_int16_t_s_s(
                                                                           (safe_div_func_int32_t_s_s(
                                                                               ((safe_div_func_uint32_t_u_u(
                                                                                    (safe_add_func_uint32_t_u_u(
                                                                                        (g_1526
                                                                                             [4]
                                                                                             [0] &&
                                                                                         (l_1262 ==
                                                                                          0x2CL)),
                                                                                        0x3AE02A7EL)),
                                                                                    g_361)) >=
                                                                                0x5AL),
                                                                               l_1423)),
                                                                           65532UL)) <=
                                                                       g_1089
                                                                           [1]),
                                                                      g_365)) !=
                                                                  l_1251) >
                                                                 l_1506[(p_60 +
                                                                         1)]
                                                                       [(p_60 +
                                                                         2)]),
                                                                l_1264
                                                                    [p_60]))) &
                                                            p_60),
                                                           g_27[6]))),
                                                      0x65L)) == l_1113[0]) >=
                                                 1L),
                                                p_58)),
                                            l_1264[6]))) < 2L),
                                      p_60)))),
                              8UL)),
                          p_59)),
                      4));
                }
              }
            }

          } else {
            int16_t l_1502 = 0x0AE4L;

            {
              if (p_61)
                break;
            }

            --l_851;
          }
          {
            int i;
            if ((safe_lshift_func_int8_t_s_s(l_1264[p_60], 2))) {
              const uint8_t l_1392 = 0UL;
              return l_1392;
            } else {
              int8_t l_1397 = (-1L);
              int i;
              l_1264[g_1201] = (safe_add_func_uint32_t_u_u(
                  (safe_mul_func_int8_t_s_s(l_851, l_1397)),
                  ((g_205 || 6L) > (g_4 <= (-1L)))));
              ++l_1398;
              g_870 =
                  ((((-1L) &
                     ((((safe_add_func_uint32_t_u_u(
                            (safe_add_func_uint8_t_u_u(
                                248UL,
                                (safe_rshift_func_uint16_t_u_s(
                                    p_62,
                                    ((((safe_rshift_func_uint16_t_u_s(
                                           (safe_add_func_uint16_t_u_u(
                                               ((safe_add_func_int32_t_s_s(
                                                    ((safe_lshift_func_uint8_t_u_s(
                                                         0xF7L,
                                                         (safe_lshift_func_uint8_t_u_s(
                                                             (0UL < g_870),
                                                             4)))) != (-1L)),
                                                    (safe_lshift_func_int16_t_s_u(
                                                        (g_420 &
                                                         (safe_sub_func_uint16_t_u_u(
                                                             ((((((safe_mul_func_int16_t_s_s(
                                                                      l_971,
                                                                      g_27[6])) ||
                                                                  l_1230) >
                                                                 l_968) <
                                                                g_365) !=
                                                               p_61) ^
                                                              0x28333F6AL),
                                                             0UL))),
                                                        p_58)))) > g_420),
                                               0UL)),
                                           12)) >= p_61) != g_420) !=
                                     l_1397))))),
                            g_753)) >= g_27[2]) == 0xE0C2L) < l_1423)) <
                    p_62) &&
                   0x32B2F135L);
              g_463[p_60] &= (safe_rshift_func_uint16_t_u_s(
                  (p_60 ^
                   (safe_mul_func_uint16_t_u_u(
                       (((safe_sub_func_int16_t_s_s(
                             (((safe_mod_func_int8_t_s_s(
                                   5L,
                                   (safe_mul_func_int8_t_s_s(
                                       (safe_sub_func_int16_t_s_s(
                                           (((safe_mod_func_int16_t_s_s(
                                                 (safe_sub_func_uint16_t_u_u(
                                                     (g_1089[6] &&
                                                      (safe_div_func_int16_t_s_s(
                                                          (p_61 &
                                                           ((safe_mod_func_int32_t_s_s(
                                                                (safe_add_func_uint16_t_u_u(
                                                                    (safe_lshift_func_int8_t_s_u(
                                                                        ((~1UL) &&
                                                                         ((0xC8DA6783L &&
                                                                           (((safe_sub_func_int16_t_s_s(
                                                                                 ((safe_add_func_int16_t_s_s(
                                                                                      (p_58 &&
                                                                                       ((g_362 !=
                                                                                         1UL) <=
                                                                                        g_205)),
                                                                                      p_60)) ||
                                                                                  l_1264
                                                                                      [4]),
                                                                                 p_62)) ==
                                                                             l_1264
                                                                                 [g_1201]) &&
                                                                            0x600BL)) <=
                                                                          l_1264
                                                                              [p_60])),
                                                                        l_1452
                                                                            [2])),
                                                                    0x1A41L)),
                                                                g_186)) !=
                                                            1UL)),
                                                          l_1264[p_60]))),
                                                     p_62)),
                                                 l_1250)) |
                                             p_62) ||
                                            0UL),
                                           g_361)),
                                       l_1264[p_60])))) != g_1089[5]) == g_365),
                             p_58)) == g_205) &
                        g_734),
                       g_205))),
                  11));
            }
            g_365 = l_834;
            g_870 =
                (g_205 ==
                 (safe_lshift_func_int16_t_s_u(
                     ((g_463[0] >
                       ((((safe_lshift_func_uint8_t_u_u(
                              ((((((safe_add_func_uint16_t_u_u(
                                       ((safe_mod_func_int8_t_s_s(
                                            (safe_lshift_func_int16_t_s_s(
                                                (safe_rshift_func_uint8_t_u_u(
                                                    (((p_62 <= l_1423) &&
                                                      p_62) &&
                                                     (safe_add_func_int16_t_s_s(
                                                         ((safe_lshift_func_uint8_t_u_s(
                                                              (safe_mod_func_int8_t_s_s(
                                                                  (g_734 &&
                                                                   (safe_div_func_int16_t_s_s(
                                                                       g_493,
                                                                       ((safe_div_func_int8_t_s_s(
                                                                            l_1475
                                                                                [0],
                                                                            0x56L)) &&
                                                                        l_928)))),
                                                                  g_463[4])),
                                                              g_27[6])) ||
                                                          0UL),
                                                         g_420))),
                                                    1)),
                                                3)),
                                            l_1250)) > g_361),
                                       p_62)) ^
                                   0xEFL) |
                                  l_1476) ||
                                 g_4) != 0x5C945727L) ||
                               0x5DL),
                              g_361)) |
                          g_493) &
                         0x59L) &&
                        p_58)) > 0x3EC9L),
                     p_58)));
            if (g_493) {
              int16_t l_1489 = 0xC2FEL;
              g_870 = ((+l_1099[4][0]) >=
                       (((((((p_61 >= 0xB7L) !=
                             (0x5B02DFFEL !=
                              (safe_sub_func_uint16_t_u_u(
                                  ((-6L) &
                                   (safe_rshift_func_int16_t_s_u(
                                       (safe_mod_func_uint8_t_u_u(
                                           ((0x47BE737CL & (p_58 <= g_27[5])) &
                                            p_58),
                                           g_870)),
                                       p_61))),
                                  0xBBBCL)))) |
                            g_463[0]) <= 4294967291UL) < p_59) &
                         0x5DFFB796L) |
                        l_850));
              p_61 = (safe_lshift_func_uint16_t_u_s(
                  (safe_mul_func_uint16_t_u_u(
                      (safe_div_func_uint8_t_u_u(
                          p_62,
                          ((0xECL || (g_463[0] == 0xA6L)) ^ (4UL && l_1489)))),
                      (safe_rshift_func_int8_t_s_s(
                          (safe_sub_func_uint16_t_u_u(
                              0UL, (0x94E9L ^ (safe_unary_minus_func_uint32_t_u(
                                                  g_1089[1]))))),
                          6)))),
                  6));
              l_1260[2][4][1] =
                  (((0x06L <=
                     ((1L == (safe_sub_func_uint8_t_u_u(0UL, g_1089[1]))) &
                      (p_59 >
                       (0xE069L &
                        (safe_unary_minus_func_int16_t_s(
                            ((g_4 ==
                              (((!(safe_rshift_func_uint16_t_u_s(
                                    (safe_lshift_func_int8_t_s_s(g_27[6], 5)),
                                    5))) ^
                                (l_1253 > (-1L))) <= 0UL)) <= p_62))))))) ||
                    0x1FL) <= l_1264[4]);
            } else {
              int16_t l_1502 = 0x0AE4L;
              l_1475[0] = 0L;
              l_1034 = l_1502;
            }
          }
        }

        for (l_1169 = 2; (l_1169 <= 6); l_1169 += 1) {
          int i, j;

          for (l_1169 = 2; (l_1169 <= 6); l_1169 += 1) {
            int i, j;
            p_61 = (safe_mod_func_int8_t_s_s(
                0xECL,
                (safe_sub_func_int32_t_s_s(
                    (((safe_unary_minus_func_int32_t_s(
                          l_1506[(p_60 + 1)][(p_60 + 2)])) <
                      (((-9L) >
                        (((safe_mod_func_uint32_t_u_u(
                              (2L ||
                               (safe_div_func_uint32_t_u_u(
                                   (((safe_rshift_func_int8_t_s_s(
                                         l_1264[p_60],
                                         ((safe_mod_func_uint16_t_u_u(
                                              (safe_add_func_int32_t_s_s(
                                                  (safe_mul_func_uint16_t_u_u(
                                                      (+g_753),
                                                      (g_1089[1] & p_61))),
                                                  g_1201)),
                                              g_1526[5][0])) <= p_58))) &&
                                     l_1527) < p_62),
                                   l_1506[(p_60 + 1)][(p_60 + 2)]))),
                              l_1504)) > g_1201) <= (-1L))) != l_1528)) &&
                     l_1529),
                    0xDFA269F6L))));
            g_870 |= (safe_rshift_func_uint8_t_u_u(
                (safe_div_func_int32_t_s_s(
                    (safe_mul_func_uint16_t_u_u(
                        (safe_rshift_func_int8_t_s_u(
                            (safe_mod_func_int32_t_s_s(1L, g_1503)),
                            (safe_sub_func_int32_t_s_s(
                                (((safe_add_func_int16_t_s_s(
                                      ((+0xA346A7BCL) != 0x2A60F066L), 1L)) ||
                                  (safe_mod_func_uint16_t_u_u(
                                      (safe_lshift_func_uint8_t_u_u(
                                          (((safe_mod_func_uint8_t_u_u(
                                                (g_1503 !=
                                                 (safe_div_func_uint32_t_u_u(
                                                     ((!(safe_add_func_int16_t_s_s(
                                                          (((safe_add_func_uint16_t_u_u(
                                                                ((safe_mul_func_int16_t_s_s(
                                                                     (safe_div_func_int32_t_s_s(
                                                                         ((safe_div_func_uint32_t_u_u(
                                                                              (safe_add_func_uint32_t_u_u(
                                                                                  (g_1526
                                                                                       [4]
                                                                                       [0] &&
                                                                                   (l_1262 ==
                                                                                    0x2CL)),
                                                                                  0x3AE02A7EL)),
                                                                              g_361)) >=
                                                                          0x5AL),
                                                                         l_1423)),
                                                                     65532UL)) <=
                                                                 g_1089[1]),
                                                                g_365)) !=
                                                            l_1251) >
                                                           l_1506[(p_60 + 1)]
                                                                 [(p_60 + 2)]),
                                                          l_1264[p_60]))) &
                                                      p_60),
                                                     g_27[6]))),
                                                0x65L)) == l_1113[0]) >= 1L),
                                          p_58)),
                                      l_1264[6]))) < 2L),
                                p_60)))),
                        8UL)),
                    p_59)),
                4));
          }
        }
      }
    }

    l_1113[i] = 0xA9L;

  } else {
    uint32_t l_1874[2];
    uint32_t l_1881 = 0xC15CD944L;
    uint16_t l_1892 = 0x716EL;
    uint32_t l_1893 = 0x054866EBL;
    int i;
    for (i = 0; i < 2; i++) {
      l_1874[i] = 0xA56F7022L;
      {
        uint32_t l_1874[2];
        uint32_t l_1881 = 0xC15CD944L;
        uint16_t l_1892 = 0x716EL;
        uint32_t l_1893 = 0x054866EBL;
        int i;
        for (i = 0; i < 2; i++)
          l_1874[i] = 0xA56F7022L;
        for (g_362 = (-4); (g_362 < 26); g_362++) {
          l_1874[0] &= 1L;
        }
        l_1893 ^= (safe_div_func_int8_t_s_s(
            ((((safe_mod_func_int16_t_s_s(
                   (-9L), (safe_lshift_func_int16_t_s_s(l_1881, 1)))) |
               1UL) <
              ((safe_mul_func_int8_t_s_s(
                   (safe_mul_func_int16_t_s_s(
                       p_60,
                       ((((l_1881 ^
                           ((((((safe_mul_func_uint8_t_u_u(l_1256, 0UL)) |
                                (!g_420)) |
                               ((((safe_lshift_func_uint16_t_u_u(l_1230, 2)) !=
                                  l_1874[0]) <= p_62) ||
                                g_150)) >= l_1890) &&
                             0x913FL) &&
                            0xE614L)) &&
                          l_1891) ||
                         1UL) <= g_1526[3][0]))),
                   0x68L)) &&
               l_1892)) <= g_27[6]),
            g_27[6]));
      }

      l_1113[i] = 0xA9L;
    }

    for (i = 0; i < 2; i++)
      l_1874[i] = 0xA56F7022L;

    l_1893 ^= (safe_div_func_int8_t_s_s(
        ((((safe_mod_func_int16_t_s_s(
               (-9L), (safe_lshift_func_int16_t_s_s(l_1881, 1)))) |
           1UL) <
          ((safe_mul_func_int8_t_s_s(
               (safe_mul_func_int16_t_s_s(
                   p_60,
                   ((((l_1881 ^ ((((((safe_mul_func_uint8_t_u_u(l_1256, 0UL)) |
                                     (!g_420)) |
                                    ((((safe_lshift_func_uint16_t_u_u(
                                           l_1230, 2)) != l_1874[0]) <= p_62) ||
                                     g_150)) >= l_1890) &&
                                  0x913FL) &&
                                 0xE614L)) &&
                      l_1891) ||
                     1UL) <= g_1526[3][0]))),
               0x68L)) &&
           l_1892)) <= g_27[6]),
        g_27[6]));
  }
  g_463[0] = (safe_div_func_uint16_t_u_u(g_361, ((~0xFAL) && g_362)));
  g_1503 = g_753;
  l_1256 =
      (g_463[1] ==
       ((safe_mul_func_uint8_t_u_u(
            ((((safe_rshift_func_uint8_t_u_s(
                   255UL,
                   ((safe_lshift_func_int8_t_s_s(
                        (+((safe_sub_func_int16_t_s_s(
                               1L,
                               ((safe_sub_func_uint8_t_u_u(
                                    (safe_mod_func_int32_t_s_s(
                                        (!(safe_mul_func_uint16_t_u_u(
                                            0xA2DEL,
                                            (safe_lshift_func_int8_t_s_s(
                                                p_60,
                                                (((safe_rshift_func_uint16_t_u_s(
                                                      (((1L ||
                                                         ((l_1230 == g_186) ^
                                                          (safe_mod_func_int16_t_s_s(
                                                              1L, 0xAEFFL)))) |
                                                        p_62) == (-9L)),
                                                      1)) <= l_1113[0]) |
                                                 0x16A6L)))))),
                                        p_58)),
                                    p_59)) < g_734))) ^
                           l_1666[3])),
                        4)) ||
                    0x90B2L))) == 0x8A29L) == (-1L)) >= g_4),
            255UL)) < p_59));
  return g_463[2];
}

static uint16_t func_65(uint8_t p_66, uint32_t p_67) {
  uint32_t l_72 = 1UL;
  int32_t l_311 = 0xE02EBC21L;
  uint8_t l_396[5];
  int32_t l_458 = 5L;
  int32_t l_460 = 1L;
  int32_t l_461 = (-6L);
  int32_t l_467 = (-10L);
  int32_t l_474 = 4L;
  int32_t l_481 = 0L;
  int32_t l_482[7];
  int32_t l_483 = 0x1E88A426L;
  int32_t l_484 = 0x5483BA15L;
  int32_t l_488 = 0x67865A1FL;
  int32_t l_491[3];
  int32_t l_678 = (-1L);
  int i;
  for (i = 0; i < 5; i++)
    l_396[i] = 0x3FL;
  for (i = 0; i < 7; i++)
    l_482[i] = 0xA0EC81A7L;
  for (i = 0; i < 3; i++)
    l_491[i] = (-1L);
  for (p_66 = (-14); (p_66 >= 51); ++p_66) {
    int32_t l_75 = 0x90CB933DL;
    uint16_t l_76 = 1UL;
    int8_t l_241 = 0xAAL;
    int8_t l_266 = (-8L);
    int8_t l_354[8][10][3] = {{{1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L}},
                              {{1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L}},
                              {{1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L}},
                              {{1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L}},
                              {{1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L}},
                              {{1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L}},
                              {{1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L}},
                              {{1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L},
                               {1L, 1L, 0xC7L}}};
    uint16_t l_421 = 0xDCF7L;
    int32_t l_462 = 0xE09EF83DL;
    int32_t l_464 = 9L;
    int32_t l_465 = (-10L);
    int32_t l_466 = 0xFCE1F6F2L;
    int32_t l_469 = 0L;
    int32_t l_470 = 0xB853B75FL;
    int32_t l_471 = 0xB538F557L;
    int32_t l_476[3];
    uint16_t l_572[9] = {0x5125L, 1UL, 0x5125L, 1UL, 0x5125L,
                         1UL, 0x5125L, 1UL, 0x5125L};
    int16_t l_666 = 0xFF82L;
    int32_t l_686 = 0xAAB29B71L;
    int i, j, k;
    for (i = 0; i < 3; i++)
      l_476[i] = 0x0DB31005L;
    l_75 = (l_72 ^ (safe_add_func_int32_t_s_s((p_67 & 0x32L), l_75)));
    if ((l_76 | l_72)) {
      uint16_t l_84 = 65530UL;
      int32_t l_206[7][4][9] = {
          {{0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L}},
          {{0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L}},
          {{0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L}},
          {{0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L}},
          {{0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L}},
          {{0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L}},
          {{0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L},
           {0x88135523L, 3L, 1L, 0x6DE7A280L, 4L, 0x28373B84L, 0xE283F7B2L,
            0xE283F7B2L, 0x28373B84L}}};
      int32_t l_219 = 0L;
      uint16_t l_399 = 0x12BCL;
      int16_t l_485 = 0x0A03L;
      int16_t l_489 = 0xF99BL;
      int8_t l_490 = (-3L);
      int i, j, k;
      l_206[5][0][3] |= (safe_lshift_func_int8_t_s_s(
          ((safe_sub_func_int8_t_s_s(
               0xDDL,
               func_81((((l_84 >= func_85(p_66,
                                          ((~(safe_rshift_func_int16_t_s_u(
                                               g_27[6], p_66))) |
                                           0xF78CL),
                                          p_66)) < p_66) >= p_67),
                       g_4))) == 0xEAL),
          p_67));
      if ((p_67 >
           ((safe_lshift_func_int8_t_s_u(
                (((0xCABFL & g_4) || 7L) <=
                 ((1UL <= (safe_add_func_uint16_t_u_u(
                              p_67, (safe_mod_func_int16_t_s_s(
                                        (safe_mod_func_int32_t_s_s(
                                            ((safe_sub_func_uint32_t_u_u(
                                                 (safe_mul_func_uint16_t_u_u(
                                                     l_219, l_219)),
                                                 p_67)) >= l_219),
                                            8UL)),
                                        l_76))))) ^
                  l_84)),
                3)) != l_72))) {
        uint16_t l_242 = 0xCD76L;
        int32_t l_243[2];
        uint32_t l_267 = 2UL;
        uint32_t l_268 = 18446744073709551613UL;
        int i;
        for (i = 0; i < 2; i++)
          l_243[i] = 0x46863D7EL;
        l_243[0] =
            ((~(((((((safe_mod_func_uint32_t_u_u(
                         g_4, (safe_mod_func_uint16_t_u_u(
                                  g_205, ((safe_unary_minus_func_uint32_t_u(
                                              (safe_mod_func_int32_t_s_s(
                                                  0x9937AC40L, g_205)))) &
                                          0x80L))))) >= p_66) &
                    (safe_add_func_int8_t_s_s(
                        (safe_sub_func_uint8_t_u_u(
                            ((g_4 &
                              (((safe_mod_func_int32_t_s_s(
                                    (l_76 &
                                     ((safe_add_func_int16_t_s_s(
                                          (safe_lshift_func_uint16_t_u_u(
                                              (safe_mod_func_int8_t_s_s(
                                                  (((l_76 && 0x1EC77C8AL) &
                                                    g_27[3]) == 1UL),
                                                  g_150)),
                                              8)),
                                          p_67)) > g_186)),
                                    g_4)) == 1UL) |
                               g_150)) ||
                             p_66),
                            0L)),
                        l_241))) |
                   g_150) <= p_66) &&
                 g_4) == l_242)) &
             (-3L));
        for (l_242 = (-21); (l_242 == 57);
             l_242 = safe_add_func_uint8_t_u_u(l_242, 8)) {
          uint32_t l_269 = 18446744073709551615UL;
          l_243[0] =
              ((((safe_mul_func_int8_t_s_s(
                     (safe_rshift_func_uint16_t_u_s(
                         (safe_mul_func_int8_t_s_s(
                             ((p_67 ||
                               ((safe_sub_func_int8_t_s_s(
                                    ((safe_mul_func_int16_t_s_s(
                                         (g_186 >=
                                          ((safe_mul_func_uint16_t_u_u(
                                               (g_185 != 0xA51C1661L),
                                               ((((safe_add_func_int32_t_s_s(
                                                      l_206[4][2][7],
                                                      (safe_mod_func_uint8_t_u_u(
                                                          (((p_67 >=
                                                             ((((l_206[5][0]
                                                                      [3] ||
                                                                 (safe_lshift_func_int8_t_s_s(
                                                                     g_27[6],
                                                                     (safe_div_func_int8_t_s_s(
                                                                         (l_266 <=
                                                                          l_84),
                                                                         255UL))))) |
                                                                0x6C95E86AL) ^
                                                               p_66) < l_72)) !=
                                                            g_4) > 1UL),
                                                          l_267)))) ||
                                                  0x54L) |
                                                 g_185) ||
                                                l_219))) |
                                           0x1AL)),
                                         0x5223L)) |
                                     0x0AL),
                                    g_185)) |
                                p_67)) |
                              g_150),
                             l_266)),
                         12)),
                     l_268)) &
                 l_269) == 6L) > l_72);
        }
      } else {
        int32_t l_285 = 0xA9A72296L;
        uint32_t l_310[9][1];
        int32_t l_457 = 1L;
        int32_t l_459 = 0L;
        int32_t l_468 = 0x3682DA73L;
        int32_t l_472 = 1L;
        int32_t l_473 = 0xC36ACF2EL;
        int32_t l_475 = 1L;
        int32_t l_477 = 2L;
        int32_t l_478 = 0x3E920F85L;
        int32_t l_479 = 1L;
        int32_t l_480 = 1L;
        int32_t l_486 = 7L;
        int32_t l_487 = 0x69C654EAL;
        int32_t l_492 = 0x2085F373L;
        int i, j;

        for (i = 0; i < 3; i++)
          l_476[i] = 0x0DB31005L;

        if ((p_67 |
             (((safe_mul_func_int16_t_s_s(
                   0x0890L,
                   (((((safe_lshift_func_uint16_t_u_u(g_150, g_205)) |
                       ((~((~(safe_mod_func_int16_t_s_s(
                               (((safe_mod_func_int16_t_s_s(
                                     l_219, (safe_mul_func_int8_t_s_s(
                                                (g_185 >= 0x9188L), 0x26L)))) &&
                                 (p_67 && 0x4D6F5489L)) ||
                                g_205),
                               g_27[6]))) > l_266)) < (-1L))) != 0UL) ||
                     g_27[3]) <= p_66))) &
               p_66) != p_67))) {
          const int8_t l_284 = 0x4EL;
          int32_t l_335 = 0xFAD5A6DDL;

          l_206[5][0][3] |= (safe_lshift_func_int8_t_s_s(
              ((safe_sub_func_int8_t_s_s(
                   0xDDL,
                   func_81((((l_84 >= func_85(p_66,
                                              ((~(safe_rshift_func_int16_t_s_u(
                                                   g_27[6], p_66))) |
                                               0xF78CL),
                                              p_66)) < p_66) >= p_67),
                           g_4))) == 0xEAL),
              p_67));

          for (g_186 = 0; (g_186 == 5);
               g_186 = safe_add_func_int16_t_s_s(g_186, 9)) {

            for (i = 0; i < 7; i++)
              l_482[i] = 0xA0EC81A7L;
          }
          l_75 = (l_72 ^ (safe_add_func_int32_t_s_s((p_67 & 0x32L), l_75)));

        } else {
          uint16_t l_395 = 65530UL;

          l_491[i] = (-1L);

          for (i = 0; i < 3; i++)
            l_476[i] = 0x0DB31005L;
        }
        for (l_241 = 0; (l_241 < 20); ++l_241) {
          uint8_t l_446 = 0xE0L;

          l_491[i] = (-1L);

          l_311 &=
              ((safe_div_func_int8_t_s_s(
                   ((safe_add_func_int16_t_s_s(
                        (0xB2L || p_67),
                        ((((((-5L) < (~7L)) ==
                            (safe_add_func_int32_t_s_s(
                                (safe_mod_func_int8_t_s_s(
                                    (((safe_add_func_int8_t_s_s(l_285, 0x0DL)) &
                                      (g_420 <= 1L)) >
                                     (safe_sub_func_uint32_t_u_u(
                                         (safe_add_func_uint32_t_u_u(
                                             ((safe_mul_func_int16_t_s_s(
                                                  g_4, 65535UL)) > p_67),
                                             0L)),
                                         g_186))),
                                    p_67)),
                                p_66))) ^
                           l_76) == 255UL) > 0xD2L))) == g_4),
                   p_66)) |
               g_365);
          {
            uint16_t l_242 = 0xCD76L;
            int32_t l_243[2];
            uint32_t l_267 = 2UL;
            uint32_t l_268 = 18446744073709551613UL;
            int i;
            for (i = 0; i < 2; i++)
              l_243[i] = 0x46863D7EL;
            l_243[0] =
                ((~(((((((safe_mod_func_uint32_t_u_u(
                             g_4, (safe_mod_func_uint16_t_u_u(
                                      g_205, ((safe_unary_minus_func_uint32_t_u(
                                                  (safe_mod_func_int32_t_s_s(
                                                      0x9937AC40L, g_205)))) &
                                              0x80L))))) >= p_66) &
                        (safe_add_func_int8_t_s_s(
                            (safe_sub_func_uint8_t_u_u(
                                ((g_4 &
                                  (((safe_mod_func_int32_t_s_s(
                                        (l_76 &
                                         ((safe_add_func_int16_t_s_s(
                                              (safe_lshift_func_uint16_t_u_u(
                                                  (safe_mod_func_int8_t_s_s(
                                                      (((l_76 && 0x1EC77C8AL) &
                                                        g_27[3]) == 1UL),
                                                      g_150)),
                                                  8)),
                                              p_67)) > g_186)),
                                        g_4)) == 1UL) |
                                   g_150)) ||
                                 p_66),
                                0L)),
                            l_241))) |
                       g_150) <= p_66) &&
                     g_4) == l_242)) &
                 (-3L));
            for (l_242 = (-21); (l_242 == 57);
                 l_242 = safe_add_func_uint8_t_u_u(l_242, 8)) {
              uint32_t l_269 = 18446744073709551615UL;
              l_243[0] =
                  ((((safe_mul_func_int8_t_s_s(
                         (safe_rshift_func_uint16_t_u_s(
                             (safe_mul_func_int8_t_s_s(
                                 ((p_67 ||
                                   ((safe_sub_func_int8_t_s_s(
                                        ((safe_mul_func_int16_t_s_s(
                                             (g_186 >=
                                              ((safe_mul_func_uint16_t_u_u(
                                                   (g_185 != 0xA51C1661L),
                                                   ((((safe_add_func_int32_t_s_s(
                                                          l_206[4][2][7],
                                                          (safe_mod_func_uint8_t_u_u(
                                                              (((p_67 >=
                                                                 ((((l_206[5][0]
                                                                          [3] ||
                                                                     (safe_lshift_func_int8_t_s_s(
                                                                         g_27[6],
                                                                         (safe_div_func_int8_t_s_s(
                                                                             (l_266 <=
                                                                              l_84),
                                                                             255UL))))) |
                                                                    0x6C95E86AL) ^
                                                                   p_66) <
                                                                  l_72)) !=
                                                                g_4) > 1UL),
                                                              l_267)))) ||
                                                      0x54L) |
                                                     g_185) ||
                                                    l_219))) |
                                               0x1AL)),
                                             0x5223L)) |
                                         0x0AL),
                                        g_185)) |
                                    p_67)) |
                                  g_150),
                                 l_266)),
                             12)),
                         l_268)) &
                     l_269) == 6L) > l_72);
            }
          }

          for (p_67 = (-5); (p_67 <= 54); ++p_67) {
            uint32_t l_451 = 1UL;
            int32_t l_456 = 0xCD17E708L;

            l_446 = g_185;

            for (p_67 = 11; (p_67 >= 12);
                 p_67 = safe_add_func_uint32_t_u_u(p_67, 8)) {
              return g_4;
            }
          }
          l_75 = (l_72 ^ (safe_add_func_int32_t_s_s((p_67 & 0x32L), l_75)));
        }

        {
          uint16_t l_395 = 65530UL;
          g_365 =
              ((safe_mod_func_uint8_t_u_u(
                   (safe_mod_func_int32_t_s_s(
                       ((0x74L ==
                         (((safe_sub_func_uint32_t_u_u(
                               (safe_mod_func_uint16_t_u_u(
                                   (safe_add_func_int16_t_s_s(
                                       l_354[1][1][0],
                                       ((l_206[6][0][7] ==
                                         ((safe_mul_func_int16_t_s_s(
                                              (safe_mul_func_uint16_t_u_u(
                                                  ((((safe_add_func_int32_t_s_s(
                                                         (g_27[6] > 252UL),
                                                         ((safe_div_func_int8_t_s_s(
                                                              (safe_mod_func_int8_t_s_s(
                                                                  (safe_add_func_int8_t_s_s(
                                                                      (safe_rshift_func_int16_t_s_u(
                                                                          (l_311 ^
                                                                           (safe_unary_minus_func_uint16_t_u(
                                                                               ((safe_div_func_uint16_t_u_u(
                                                                                    (safe_add_func_uint8_t_u_u(
                                                                                        1UL,
                                                                                        g_27[6])),
                                                                                    (-10L))) ^
                                                                                g_365)))),
                                                                          4)),
                                                                      0xE3L)),
                                                                  l_395)),
                                                              0x67L)) &
                                                          0xFE5EA9AEL))) |
                                                     l_395) < 252UL) >= l_395),
                                                  g_27[1])),
                                              0xC3BCL)) &&
                                          0x42342475L)) &
                                        l_206[5][0][3]))),
                                   0xEC04L)),
                               l_396[3])) == p_66) &&
                          p_66)) < g_27[4]),
                       0x604C85C1L)),
                   1UL)) != l_395);
          g_420 ^=
              (((safe_mul_func_int8_t_s_s(
                    ((l_399 <
                      (safe_div_func_uint32_t_u_u(
                          ((safe_add_func_int32_t_s_s(
                               ((safe_rshift_func_int16_t_s_s(
                                    (safe_add_func_uint8_t_u_u(
                                        (safe_mul_func_uint16_t_u_u(6UL,
                                                                    0x60BFL)),
                                        (((safe_lshift_func_uint16_t_u_s(
                                              g_361,
                                              ((0x47L & p_66) &&
                                               ((g_27[6] <=
                                                 (l_395 >
                                                  (safe_sub_func_uint16_t_u_u(
                                                      ((safe_rshift_func_int16_t_s_s(
                                                           (safe_sub_func_uint32_t_u_u(
                                                               (safe_add_func_int16_t_s_s(
                                                                   l_311,
                                                                   g_205)),
                                                               0xED3D2726L)),
                                                           9)) &&
                                                       g_27[5]),
                                                      g_365)))) ||
                                                g_205)))) |
                                          0xEA4B3987L) != (-1L)))),
                                    p_67)) &
                                p_67),
                               g_362)) < g_186),
                          0xD3EC22CCL))) <= 1L),
                    l_241)) > g_27[0]) ||
               3L);
          ++l_421;
        }
      }
      l_461
 =
 (!
  (g_185
   &&
   (safe_add_func_int32_t_s_s
    ((safe_div_func_uint32_t_u_u ((safe_add_func_uint16_t_u_u ((safe_lshift_func_int16_t_s_u ((safe_mul_func_uint8_t_u_u ((safe_mul_func_uint16_t_u_u (((((1UL & (safe_mul_func_int16_t_s_s ((~(safe_rshift_func_uint16_t_u_s ((!(safe_sub_func_uint32_t_u_u ((safe_mul_func_int8_t_s_s (p_67, (safe_add_func_int8_t_s_s ((0xA1L || (safe_add_func_uint8_t_u_u (((safe_rshift_func_uint8_t_u_s ((((safe_mul_func_uint16_t_u_u ((((safe_sub_func_uint8_t_u_u ((safe_rshift_func_int16_t_s_s (((-3L) < (safe_add_func_uint32_t_u_u ((safe_sub_func_uint16_t_u_u (((((safe_lshift_func_uint16_t_u_u ((safe_rshift_func_int16_t_s_u ((safe_mul_func_uint8_t_u_u ((l_488 ^ ((safe_rshift_func_uint16_t_u_u ((((0xD191L && (safe_div_func_int8_t_s_s ((((safe_add_func_uint16_t_u_u ((((g_27[6] & (!(((255UL >= l_490) & p_67) || p_67))) & l_396[1]) == l_311), 0UL)) == 4L) & (-1L)), l_72))) <= l_470) | 0xA211L), 4)) | l_482[3])), 4L)), p_66)), p_67)) > 0x2C45471EL) == g_27[6]) < g_27[1]), g_4)), 4294967295UL))), 5)), g_463[2])) | p_67) & l_396[4]), p_66)) & g_205) && 6L), 7)) == p_66), 0xC1L))), l_467)))), g_185))), 15))), p_66))) != p_66) ^ 0xDB71L) | p_67), p_66)), p_67)), l_396[3])), 0x2948L)), g_420)), p_66))));
      l_491[2] =
          ((((p_67 !=
              (g_420 ||
               (safe_mul_func_int8_t_s_s(
                   (g_4 <=
                    ((safe_rshift_func_uint16_t_u_s(
                         ((p_66 &&
                           (safe_add_func_uint8_t_u_u(
                               l_206[2][0][8],
                               ((l_396[0] |
                                 (safe_lshift_func_uint16_t_u_s(
                                     9UL, (safe_div_func_int32_t_s_s(
                                              (g_362 | (0xEC3AL != 0xBAC0L)),
                                              p_67))))) == g_361)))) <= 252UL),
                         8)) == 0x989DL)),
                   l_491[1])))) <= 0x12A0E969L) < g_205) == g_362);
    } else {
      int32_t l_591 = (-6L);
      int32_t l_681 = 0xDE930396L;
      int32_t l_682 = (-6L);
      int32_t l_684 = 0x380E6533L;
      int32_t l_685[9];
      uint16_t l_750[4] = {65532UL, 3UL, 65532UL, 3UL};
      uint32_t l_793 = 0x7C313479L;
      int i;
      for (i = 0; i < 9; i++)
        ;

      l_482[i] = 0xA0EC81A7L;

      if (((safe_mod_func_int8_t_s_s(
               (safe_sub_func_int16_t_s_s(
                   ((safe_div_func_int32_t_s_s(
                        (((safe_rshift_func_int8_t_s_u(p_66, 5)) >
                          (safe_mod_func_int16_t_s_s((+p_67), g_420))) &
                         l_311),
                        (safe_div_func_int8_t_s_s(
                            (safe_mul_func_int8_t_s_s(
                                (safe_mul_func_uint8_t_u_u(
                                    (safe_mod_func_int32_t_s_s(
                                        (((~l_572[3]) != g_420) |
                                         ((g_361 ^
                                           (g_361 !=
                                            (safe_lshift_func_int16_t_s_u(
                                                ((safe_add_func_uint32_t_u_u(
                                                     2UL, g_150)) >= p_66),
                                                1)))) < g_365)),
                                        l_572[8])),
                                    g_27[6])),
                                g_186)),
                            0x19L)))) &&
                    0x1C35E09FL),
                   0x4D76L)),
               g_463[0])) <= l_354[1][1][0])) {
        uint16_t l_637[2][2] = {{65531UL, 1UL}, {65531UL, 1UL}};
        int32_t l_643 = 1L;
        int32_t l_671[9] = {0x0B0FD8E5L, 6L, 0x0B0FD8E5L, 6L, 0x0B0FD8E5L, 6L,
                            0x0B0FD8E5L, 6L, 0x0B0FD8E5L};
        int i, j;

        for (i = 0; i < 3; i++)
          l_476[i] = 0x0DB31005L;

        for (i = 0; i < 3; i++)
          l_476[i] = 0x0DB31005L;

      } else {
        uint16_t l_674 = 0x064AL;
        int32_t l_677 = 0x4E4C5D7BL;
        int32_t l_679 = (-10L);
        int32_t l_680 = 0xE55FBF8FL;
        int32_t l_683[7] = {(-8L), 2L, (-8L), 2L, (-8L), 2L, (-8L)};
        uint32_t l_687 = 0x6DBF1C60L;
        int i;

        l_396[i] = 0x3FL;

        if (l_484)
          break;

        for (i = 0; i < 3; i++)
          l_491[i] = (-1L);
      }
      l_476[i] = 0x0DB31005L;

      l_476[i] = 0x0DB31005L;

      l_476[i] = 0x0DB31005L;
    }
    l_686 = l_464;
  }
  if (l_458) {
    for (l_458 = 0; (l_458 <= 5); l_458 += 1) {
      int i;
      g_463[l_458] |= ((safe_unary_minus_func_uint32_t_u(p_66)) & 0x0111L);
    }
    g_365 = (safe_mul_func_uint16_t_u_u(p_67, p_66));
  } else {
    uint16_t l_827 = 0x1EEBL;
    int32_t l_828[1];
    int i;
    for (i = 0; i < 1; i++) {
      l_828[i] = 0x31608BE7L;
      for (i = 0; i < 7; i++)
        l_482[i] = 0xA0EC81A7L;
    }

    l_828[0] &=
        ((7L ||
          (safe_mod_func_uint32_t_u_u(
              (((0x3FL !=
                 ((safe_mod_func_int32_t_s_s(
                      l_396[1],
                      (safe_rshift_func_int16_t_s_s(
                          (safe_add_func_uint16_t_u_u(
                              (safe_add_func_int16_t_s_s(
                                  (safe_add_func_uint8_t_u_u(
                                      ((safe_sub_func_uint32_t_u_u(
                                           (p_66 >=
                                            (safe_sub_func_uint8_t_u_u(
                                                ((safe_rshift_func_uint16_t_u_s(
                                                     (safe_lshift_func_int16_t_s_u(
                                                         (l_481 | (~(!l_488))),
                                                         (safe_add_func_int32_t_s_s(
                                                             ((safe_mod_func_int16_t_s_s(
                                                                  (safe_sub_func_uint8_t_u_u(
                                                                      ((safe_rshift_func_int16_t_s_s(
                                                                           ((0x2FL &
                                                                             0UL) ||
                                                                            l_827),
                                                                           l_827)) >
                                                                       4294967294UL),
                                                                      g_185)),
                                                                  l_467)) >=
                                                              p_66),
                                                             p_67)))),
                                                     11)) <= l_483),
                                                0x5EL))),
                                           g_463[3])) >= 1L),
                                      l_827)),
                                  0xBB5CL)),
                              l_827)),
                          g_185)))) |
                  p_67)) > l_827) ^
               p_67),
              0xEC8FD928L))) >= l_827);
  }
  return p_66;
}

static int8_t func_81(int8_t p_82, int32_t p_83) {
  int8_t l_199 = 0x41L;
  int8_t l_204 = 1L;
  g_186 = p_82;
  g_205 =
      ((!((0UL >= g_4) < (safe_rshift_func_int8_t_s_u(p_83, 0)))) &&
       (0L >
        (((((safe_mul_func_int16_t_s_s(
                (-1L),
                (safe_mul_func_int16_t_s_s(
                    1L, (safe_mul_func_int16_t_s_s(
                            (-1L),
                            (safe_lshift_func_uint8_t_u_s(
                                (((safe_rshift_func_uint16_t_u_s(
                                      l_199, (safe_mod_func_int32_t_s_s(
                                                 ((safe_add_func_uint16_t_u_u(
                                                      g_4, 0L)) ||
                                                  0x572EL),
                                                 g_150)))) ||
                                  l_199) != 0x8EL),
                                4)))))))) > g_186) == l_199) <= 1UL) <=
         l_204)));
  return g_185;
}

static uint8_t func_85(uint8_t p_86, uint16_t p_87, int8_t p_88) {
  uint32_t l_91 = 4294967295UL;
  int8_t l_104[9] = {0x0CL, 0xBEL, 0x0CL, 0xBEL, 0x0CL,
                     0xBEL, 0x0CL, 0xBEL, 0x0CL};
  int32_t l_183 = 0L;
  int32_t l_184 = 0x2824790DL;
  int i;
  if (p_87) {
    uint8_t l_100[4][5] = {{0x69L, 0x69L, 7UL, 0x3FL, 0UL},
                           {0x69L, 0x69L, 7UL, 0x3FL, 0UL},
                           {0x69L, 0x69L, 7UL, 0x3FL, 0UL},
                           {0x69L, 0x69L, 7UL, 0x3FL, 0UL}};
    int32_t l_120 = 0x5CE3A63AL;
    int16_t l_182 = 0xC430L;
    int i, j;
    l_91 = 0xD13BCE86L;
    for (p_88 = (-22); (p_88 <= (-8)); ++p_88) {
      uint16_t l_106 = 65535UL;
      uint32_t l_107 = 0x3D1D1CE1L;
      int16_t l_110 = 8L;
      int32_t l_119[1];
      const int32_t l_147 = 0x8EAAB991L;
      int8_t l_171 = 8L;
      int i;
      for (i = 0; i < 1; i++)
        l_119[i] = (-1L);
      for (p_87 = 0; (p_87 < 25); ++p_87) {
        int16_t l_105[7] = {0L, (-9L), 0L, (-9L), 0L, (-9L), 0L};
        int i;
        for (l_91 = 0; (l_91 <= 32); l_91++) {
          uint16_t l_103 = 0xC86DL;
          int32_t l_115 = 0L;
          for (p_86 = (-26); (p_86 == 10); ++p_86) {
            l_105[2] =
                (l_100[2][2] == ((-5L) < (safe_sub_func_int32_t_s_s(
                                             ((p_87 & (l_103 == p_87)) >= 0UL),
                                             (p_88 || l_104[2])))));
            l_106 |= (0x7E08CD91L != 0xFB6CA454L);

            l_107++;
            {
              uint16_t l_103 = 0xC86DL;
              int32_t l_115 = 0L;
              for (p_86 = (-26); (p_86 == 10); ++p_86) {
                l_105[2] = (l_100[2][2] ==
                            ((-5L) < (safe_sub_func_int32_t_s_s(
                                         ((p_87 & (l_103 == p_87)) >= 0UL),
                                         (p_88 || l_104[2])))));
                l_106 |= (0x7E08CD91L != 0xFB6CA454L);
                if (p_86)
                  break;
                l_107++;
              }
              l_115 = (((l_110 || 0xA83EL) ==
                        ((safe_div_func_int8_t_s_s(
                             (g_27[2] <
                              ((((0xC298B4A0L != 0x31E92403L) > l_105[5]) |
                                (+g_27[6])) <
                               (safe_mod_func_int8_t_s_s(g_4, l_100[2][2])))),
                             3UL)) > 0xD26586BCL)) != l_100[3][4]);
            }
          }
          l_115 =
              (((l_110 || 0xA83EL) ==
                ((safe_div_func_int8_t_s_s(
                     (g_27[2] < ((((0xC298B4A0L != 0x31E92403L) > l_105[5]) |
                                  (+g_27[6])) <
                                 (safe_mod_func_int8_t_s_s(g_4, l_100[2][2])))),
                     3UL)) > 0xD26586BCL)) != l_100[3][4]);
        }
        l_119[0] |=
            (l_100[2][2] ^
             (safe_mul_func_int8_t_s_s(
                 g_27[6], ((safe_unary_minus_func_int32_t_s(l_107)) == 0L))));
        l_120 ^= l_104[6];
        for (l_91 = 0; (l_91 <= 3); l_91 += 1) {
          int i, j;
          l_120 =
              (((safe_mul_func_int16_t_s_s(
                    (safe_rshift_func_int8_t_s_u(
                        (safe_mod_func_int16_t_s_s(
                            (safe_div_func_uint16_t_u_u(0xB072L, l_105[l_91])),
                            (safe_mod_func_int32_t_s_s(l_105[(l_91 + 2)],
                                                       0xC767A1E7L)))),
                        6)),
                    (safe_sub_func_int8_t_s_s(
                        (safe_rshift_func_int8_t_s_u(
                            (safe_rshift_func_uint8_t_u_s(
                                (safe_mod_func_uint16_t_u_u(
                                    0xD326L,
                                    (safe_lshift_func_int16_t_s_s(
                                        (safe_mod_func_uint8_t_u_u(
                                            0x4AL, l_100[l_91][l_91])),
                                        ((((safe_add_func_uint8_t_u_u(
                                               (((safe_div_func_int8_t_s_s(
                                                     1L, l_100[l_91][l_91])) &
                                                 4L) &
                                                0x8538L),
                                               l_100[l_91][(l_91 + 1)])) !=
                                           p_86) < l_100[l_91][(l_91 + 1)]) ^
                                         l_120))))),
                                2)),
                            3)),
                        l_105[(l_91 + 2)])))) &&
                l_147) != l_105[2]);
          l_120 ^= (!0x421085DAL);
        }
      }
      for (l_91 = 0; (l_91 > 58); l_91 = safe_add_func_int16_t_s_s(l_91, 7)) {
        int16_t l_163 = 0xDD8BL;
        int32_t l_164 = 0xA2FA3D26L;
        g_150 &= l_104[8];
        l_164 =
            (((p_87 !=
               ((-1L) |
                ((0xF974L ==
                  (safe_mod_func_uint8_t_u_u(
                      (((safe_mod_func_int8_t_s_s(
                            (safe_lshift_func_uint8_t_u_u(
                                (0x4EFFBF5EL ^
                                 ((safe_add_func_uint8_t_u_u(
                                      p_88,
                                      (+(1UL >
                                         (safe_sub_func_uint16_t_u_u(
                                             1UL,
                                             (safe_rshift_func_uint16_t_u_s(
                                                 0xCAB4L, 8)))))))) < p_87)),
                                g_4)),
                            g_4)) != g_150) &&
                       0x40L),
                      l_120))) ||
                 g_27[0]))) >= g_150) ||
             l_163);
      }
      l_182 &= (safe_lshift_func_uint16_t_u_s(
          (((((safe_lshift_func_uint8_t_u_u(
                  (p_86 | (safe_lshift_func_int8_t_s_u(p_88, 6))),
                  (l_171 |
                   (safe_mul_func_uint16_t_u_u(
                       ((safe_mul_func_uint16_t_u_u(0x8170L, g_4)) && p_86),
                       l_147))))) <= l_91) >
             ((safe_add_func_uint16_t_u_u(
                  ((safe_rshift_func_int16_t_s_u(
                       ((+(safe_div_func_int32_t_s_s((0x3F393C2DL & p_86),
                                                     0x0387E0A5L))) |
                        0xA727L),
                       4)) |
                   g_4),
                  l_104[2])) ||
              p_87)) > 0xE2L) &
           g_27[6]),
          12));
    }
  } else {
    l_183 ^= g_27[6];
    l_184 ^= l_183;
    g_185 = (-2L);
  }
  return g_27[6];
}

int main(void) {
  int i, j, k;
  int print_hash_value = 0;
  crc32_gentab();
  func_1();
  transparent_crc(g_4, "g_4", print_hash_value);
  for (i = 0; i < 7; i++) {
    transparent_crc(g_27[i], "g_27[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_150, "g_150", print_hash_value);
  transparent_crc(g_185, "g_185", print_hash_value);
  transparent_crc(g_186, "g_186", print_hash_value);
  transparent_crc(g_205, "g_205", print_hash_value);
  transparent_crc(g_361, "g_361", print_hash_value);
  transparent_crc(g_362, "g_362", print_hash_value);
  transparent_crc(g_365, "g_365", print_hash_value);
  transparent_crc(g_420, "g_420", print_hash_value);
  for (i = 0; i < 6; i++) {
    transparent_crc(g_463[i], "g_463[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_493, "g_493", print_hash_value);
  transparent_crc(g_734, "g_734", print_hash_value);
  transparent_crc(g_753, "g_753", print_hash_value);
  transparent_crc(g_870, "g_870", print_hash_value);
  for (i = 0; i < 10; i++) {
    transparent_crc(g_1089[i], "g_1089[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_1201, "g_1201", print_hash_value);
  transparent_crc(g_1503, "g_1503", print_hash_value);
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 2; j++) {
      transparent_crc(g_1526[i][j], "g_1526[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_1942, "g_1942", print_hash_value);
  for (i = 0; i < 2; i++) {
    transparent_crc(g_2050[i], "g_2050[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_2104, "g_2104", print_hash_value);
  transparent_crc(g_2473, "g_2473", print_hash_value);
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 7; j++) {
      for (k = 0; k < 5; k++) {
        transparent_crc(g_2503[i][j][k], "g_2503[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  for (i = 0; i < 2; i++) {
    transparent_crc(g_2780[i], "g_2780[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_2787, "g_2787", print_hash_value);
  transparent_crc(g_2927, "g_2927", print_hash_value);
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}

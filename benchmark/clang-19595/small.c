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

static int32_t g_2 = 0xB110C93BL;
static int32_t g_5[10] = {0x4EBB0CB8L, 0x9609C3FBL, 0xDF98A59CL, 0xDF98A59CL,
                          0x9609C3FBL, 0x4EBB0CB8L, 0x9609C3FBL, 0xDF98A59CL,
                          0xDF98A59CL, 0x9609C3FBL};
static int32_t g_8[3][2] = {{0xEC79E672L, 0xEC79E672L},
                            {0xEC79E672L, 0xEC79E672L},
                            {0xEC79E672L, 0xEC79E672L}};
static int32_t g_9 = 0L;
static int8_t g_10 = 0x15L;
static uint32_t g_101 = 0x7C3E802FL;
static int8_t g_142[5][5] = {{(-1L), (-1L), 0x39L, 7L, (-6L)},
                             {(-1L), (-1L), 0x39L, 7L, (-6L)},
                             {(-1L), (-1L), 0x39L, 7L, (-6L)},
                             {(-1L), (-1L), 0x39L, 7L, (-6L)},
                             {(-1L), (-1L), 0x39L, 7L, (-6L)}};
static uint32_t g_208 = 0x8879A0F3L;
static uint16_t g_227 = 0x2153L;
static int16_t g_358 = 0L;
static uint16_t g_405[9] = {65530UL, 0xF13BL, 65530UL, 0xF13BL, 65530UL,
                            0xF13BL, 65530UL, 0xF13BL, 65530UL};
static int16_t g_406 = (-2L);
static int8_t g_458[1] = {0x90L};
static uint32_t g_508[3][10][1] = {{{0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL}},
                                   {{0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL}},
                                   {{0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL},
                                    {0xA0ABFA0EL}}};
static int16_t g_520[9] = {3L, 3L, 4L, 3L, 3L, 4L, 3L, 3L, 4L};
static int32_t g_580[4] = {0xD7605479L, 0xD7605479L, 0xD7605479L, 0xD7605479L};
static int8_t g_754 = (-7L);
static int32_t g_830 = (-1L);
static int8_t g_1165 = (-1L);
static uint32_t g_1195 = 0x8B77D5C4L;
static uint8_t g_1588 = 0xE5L;
static uint32_t g_1625 = 0x37ADF603L;

static int32_t func_1(void);
static int8_t func_11(uint16_t p_12, int16_t p_13, int32_t p_14, uint32_t p_15,
                      uint32_t p_16);
static uint16_t func_21(uint16_t p_22);
static int8_t func_23(int8_t p_24, uint8_t p_25, uint16_t p_26, int32_t p_27);
static int16_t func_36(uint32_t p_37, int32_t p_38);
static int16_t func_46(int8_t p_47, int32_t p_48, uint8_t p_49, int32_t p_50);
static uint32_t func_61(uint16_t p_62, uint8_t p_63, int32_t p_64);
static int32_t func_72(int16_t p_73);
static uint32_t func_78(int8_t p_79, int16_t p_80);
static uint8_t func_118(uint8_t p_119, int32_t p_120, int16_t p_121,
                        uint16_t p_122, int32_t p_123);
static int32_t func_1(void) {
  uint16_t l_2038 = 0x0693L;
  int32_t l_2067[3];
  uint8_t l_2142 = 0x9AL;
  int32_t l_2231 = 1L;
  int i;
  for (i = 0; i < 3; i++)
    l_2067[i] = 0x95763659L;
  for (g_2 = 0; (g_2 <= 28); g_2 = safe_add_func_uint16_t_u_u(g_2, 9)) {
    uint8_t l_2036 = 0x5DL;
    for (g_5[6] = 0; (g_5[6] == (-15)); g_5[6]--) {
      int8_t l_2037[6][7][2] = {{{0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L}},
                                {{0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L}},
                                {{0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L}},
                                {{0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L}},
                                {{0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L}},
                                {{0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L},
                                 {0x1CL, 0L}}};
      int32_t l_2059 = (-1L);
      uint16_t l_2141 = 0xF260L;
      int32_t l_2163 = 0xB8660EB2L;
      int32_t l_2229 = 0xD9767C14L;
      int i, j, k;
      for (g_9 = 1; (g_9 >= 0); g_9 -= 1) {
        int16_t l_2149 = 0xCCC4L;
        int32_t l_2232[2];
        int i, j;
        for (i = 0; i < 2; i++)
          ;

        for (g_9 = 1; (g_9 >= 0); g_9 -= 1) {
          int16_t l_2149 = 0xCCC4L;
          int32_t l_2232[2];
          int i, j;
          for (i = 0; i < 2; i++)
            l_2232[i] = 1L;
          g_10 = g_8[(g_9 + 1)][g_9];
          for (g_10 = 0; (g_10 <= 1); g_10 += 1) {
            int32_t l_2058 = 0x38544D0EL;
            uint32_t l_2070 = 1UL;
            int32_t l_2085 = 0x0E069FBBL;
            int16_t l_2198[9];
            int32_t l_2233 = 0xB91FAD3AL;
            int i, j;
            for (i = 0; i < 9; i++)
              l_2198[i] = 0L;
            if ((0x9150L >= g_8[(g_10 + 1)][g_9])) {
              int8_t l_2035 = 0xC1L;
              l_2058 =
                  (func_11(((g_5[6],
                             (safe_sub_func_uint32_t_u_u(
                                 g_8[(g_10 + 1)][g_9],
                                 (safe_rshift_func_uint16_t_u_u(
                                     func_21(g_10),
                                     (((safe_mod_func_int8_t_s_s(l_2035, g_9)) |
                                       l_2035) <= l_2036)))))),
                            (l_2036, g_9)),
                           l_2037[4][5][0], g_8[(g_9 + 1)][g_9], l_2038,
                           g_8[(g_9 + 1)][g_9]) != l_2035);
              if (g_1165)
                continue;
              l_2059 = l_2036;
            } else {
              uint16_t l_2086 = 0x583EL;
              uint32_t l_2105 = 18446744073709551612UL;
              g_830 = g_520[6];
              g_580[1] = g_227;
              g_580[1] = (safe_add_func_int32_t_s_s(
                  (((safe_unary_minus_func_uint8_t_u(l_2059)) |
                    (g_1625 ||
                     (safe_lshift_func_int16_t_s_s(
                         (safe_mod_func_int16_t_s_s(l_2036, l_2067[2])),
                         15)))) &
                   (safe_mod_func_uint16_t_u_u(g_1195, l_2070))),
                  (((safe_add_func_int16_t_s_s(
                        (safe_lshift_func_int16_t_s_u(
                            ((g_1195 ^
                              (safe_mod_func_int16_t_s_s(
                                  (((((safe_sub_func_uint16_t_u_u(
                                          (safe_lshift_func_uint8_t_u_s(
                                              (0xBAL <
                                               ((safe_sub_func_int16_t_s_s(
                                                    ((safe_add_func_uint16_t_u_u(
                                                         g_8[(g_9 + 1)][g_9],
                                                         g_508[1][4][0])) &
                                                     l_2085),
                                                    g_508[2][4][0])) == 1UL)),
                                              1)),
                                          g_830)) >= l_2067[2]) ==
                                     l_2037[3][6][1]) >= l_2086),
                                   g_520[0]),
                                  g_508[1][2][0]))) < l_2038),
                            10)),
                        0xF45DL)) != g_1588),
                   l_2067[1])));
              g_830 = (safe_rshift_func_int16_t_s_u(
                  8L,
                  (((safe_mul_func_int8_t_s_s(
                        ((safe_lshift_func_int8_t_s_u(
                             l_2038,
                             ((((safe_mul_func_uint16_t_u_u(
                                    ((0x22L && 0xDAL) <=
                                     (safe_mod_func_int8_t_s_s(
                                         (safe_rshift_func_int8_t_s_s(
                                             (g_5[3] >
                                              ((0x6CL |
                                                (safe_mod_func_uint32_t_u_u(
                                                    ((safe_sub_func_uint8_t_u_u(
                                                         0UL, l_2038)) <
                                                     ((safe_rshift_func_int16_t_s_s(
                                                          g_8[(g_9 + 1)][g_9],
                                                          g_520[0])),
                                                      0x12767035L)),
                                                    (-5L)))) == 0x85E16F77L)),
                                             g_1588)),
                                         g_830))),
                                    65527UL)) >= g_580[1]) != g_8[2][1]) >
                              g_358))) != g_10),
                        g_9)) ||
                    l_2105) ^
                   g_405[8])));
            }
            for (l_2038 = 0; (l_2038 <= 1); l_2038 += 1) {
              uint8_t l_2120 = 247UL;
              l_2120 =
                  ((l_2070,
                    (g_580[1] <=
                     (3L >
                      ((safe_sub_func_uint8_t_u_u(
                           ((g_580[3] &&
                             (safe_mul_func_int16_t_s_s(
                                 (safe_add_func_uint16_t_u_u(
                                     0x0E34L,
                                     ((safe_mul_func_uint16_t_u_u(
                                          1UL,
                                          (safe_mul_func_uint16_t_u_u(
                                              (((safe_mul_func_uint16_t_u_u(
                                                    ((0x3BE3L != (-1L)),
                                                     l_2038),
                                                    1UL)) ^
                                                g_2) &
                                               g_1195),
                                              g_101)))) ^
                                      g_8[1][0]))),
                                 l_2058))) != l_2038),
                           g_1588)) < g_458[0])))) >= g_227);
              if (g_2)
                break;
              if (l_2036)
                break;
              g_580[2] =
                  ((safe_add_func_int16_t_s_s(
                       (((l_2036 & (l_2070 != (l_2120 > l_2036))) !=
                         (0L !=
                          (((-2L) ==
                            ((safe_mod_func_int32_t_s_s(
                                 (((((safe_rshift_func_uint16_t_u_u(
                                         (safe_lshift_func_int16_t_s_s(
                                             (safe_sub_func_uint16_t_u_u(
                                                 ((safe_mul_func_uint8_t_u_u(
                                                      (safe_sub_func_int32_t_s_s(
                                                          (g_830 |
                                                           (((((safe_rshift_func_int16_t_s_s(
                                                                   ((safe_sub_func_uint32_t_u_u(
                                                                        (safe_mul_func_int8_t_s_s(
                                                                            (l_2067
                                                                                 [2] &&
                                                                             (g_1195 |
                                                                              1L)),
                                                                            l_2058)),
                                                                        1L)) ==
                                                                    l_2070),
                                                                   15)) ^
                                                               3L) <=
                                                              0x8039L) &&
                                                             0x76520C5AL) |
                                                            4UL)),
                                                          g_101)),
                                                      l_2120)) >= g_458[0]),
                                                 1UL)),
                                             5)),
                                         15)) <= 1L) ||
                                    l_2038) >= 0x7247L) <= l_2037[4][5][0]),
                                 l_2141)) &
                             2L)),
                           g_227))) ^
                        (-1L)),
                       l_2142)) ^
                   g_142[3][0]);
            }
            if ((((safe_mod_func_int32_t_s_s(
                      (safe_sub_func_int16_t_s_s(
                          (((safe_mul_func_int8_t_s_s((g_5[1] == l_2142),
                                                      (g_405[6] || l_2149))) &&
                            1UL) <= g_508[2][4][0]),
                          (((safe_mul_func_uint8_t_u_u(
                                (g_1195 &
                                 (((+((0x94L &&
                                       ((safe_add_func_uint32_t_u_u(
                                            ((((safe_rshift_func_int8_t_s_u(
                                                   (0x24C81AC5L != 0x21380933L),
                                                   4)) ||
                                               0xD40C0F3CL) ||
                                              g_8[(g_9 + 1)][g_9]) |
                                             0x52D8L),
                                            g_2)) < g_8[(g_10 + 1)][g_9])) ==
                                      0L)) &
                                   l_2085) > l_2067[2])),
                                g_1165)) &
                            7L) == l_2059))),
                      0xCF5CA7DDL)) <= g_8[(g_9 + 1)][g_9]) |
                 l_2067[1])) {
              uint8_t l_2162[4] = {0x53L, 0x0DL, 0x53L, 0x0DL};
              int i;
              g_580[1] =
                  (l_2036 >=
                   ((+0xE040D8F8L) |
                    ((g_508[2][4][0] ^
                      ((safe_sub_func_int32_t_s_s(
                           (((safe_lshift_func_int8_t_s_s(
                                 (255UL >=
                                  (l_2142 != (((((safe_rshift_func_int16_t_s_s(
                                                     g_508[2][4][0], 0)),
                                                 l_2067[2]) != l_2141) ||
                                               ((1UL ^ 246UL) != l_2142)) |
                                              4294967293UL))),
                                 2)),
                             (-1L)) >= 1L),
                           1L)) |
                       g_1625)) < l_2162[3])));
              l_2163 = l_2162[0];
              l_2058 =
                  ((((safe_mul_func_int16_t_s_s(
                         (-8L),
                         ((safe_rshift_func_int16_t_s_s(
                              (((((l_2070 ^
                                   (safe_add_func_int16_t_s_s(
                                       (g_458[0] ^
                                        ((safe_rshift_func_uint16_t_u_u(
                                             ((safe_unary_minus_func_uint16_t_u(
                                                  g_142[0][1])),
                                              0x7182L),
                                             l_2036)),
                                         g_5[6])),
                                       ((g_508[2][4][0],
                                         ((((safe_sub_func_int16_t_s_s(
                                                (3L > 6L), l_2162[3])) &&
                                            0L),
                                           l_2067[2]) |
                                          l_2085)) >= 0x7B49L)))),
                                  0UL) &
                                 g_101) == g_8[(g_9 + 1)][g_9]) &
                               g_458[0]),
                              6)) >= g_405[8]))),
                     g_2) != g_405[8]),
                   0x53BBB007L);
            } else {
              int32_t l_2197 = (-9L);
              uint16_t l_2230[4][10][5] = {{{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}},
                                           {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}},
                                           {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}},
                                           {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}}};
              int i, j, k;
              l_2198[6] =
                  (g_101,
                   (((safe_add_func_uint16_t_u_u(
                         (((((((safe_sub_func_int16_t_s_s(
                                   (safe_lshift_func_uint8_t_u_s(
                                       (!(((-1L) >
                                           (safe_add_func_int32_t_s_s(
                                               ((safe_add_func_uint8_t_u_u(
                                                    l_2085,
                                                    (safe_sub_func_int32_t_s_s(
                                                        ((safe_add_func_uint16_t_u_u(
                                                             (l_2085 ||
                                                              (safe_lshift_func_int16_t_s_s(
                                                                  (g_1625 >
                                                                   (safe_sub_func_uint8_t_u_u(
                                                                       ((l_2036 |
                                                                         (safe_mod_func_uint16_t_u_u(
                                                                             g_520
                                                                                 [0],
                                                                             (g_405
                                                                                  [8] ^
                                                                              ((safe_mod_func_int8_t_s_s(
                                                                                   (-8L),
                                                                                   g_830)) >=
                                                                               l_2149))))) &
                                                                        l_2038),
                                                                       g_830))),
                                                                  12))),
                                                             l_2197)) >=
                                                         l_2197),
                                                        l_2070)))) == g_458[0]),
                                               0UL))) == g_1588)),
                                       l_2058)),
                                   l_2142)) > 0xA7511AFCL) ^
                              g_10) |
                             0x4495FEC8L) == g_458[0]) > 65532UL) > 0x730FL),
                         0xE99FL)),
                     g_458[0]) >= 4294967295UL));
                        g_580[1] = (safe_add_func_uint16_t_u_u((((((safe_add_func_uint8_t_u_u((((((safe_mul_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_u(((((l_2197 > 0xC0L) | (((safe_add_func_uint32_t_u_u((safe_sub_func_int16_t_s_s(((((safe_mul_func_int16_t_s_s((~((safe_sub_func_uint32_t_u_u(0xE8633FD1L, (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((0L > g_101) && (((l_2036 , (l_2036 && (safe_mod_func_uint16_t_u_u((g_1588 & (safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u((((((l_2036 && g_208) && l_2229) < g_520[6]) == g_508[0][6][0]) || g_227), 0x30L)), g_5[6])) != l_2230[0][3][3]) , g_1588), 1L))), g_1625)))) >= g_458[0]) , l_2142)), g_458[0])), l_2036)))) & l_2231)), 2UL)) <= g_358) <= g_8[(g_9 + 1)][g_9]) != g_101), (-1L))), 0xAE57AF4CL)) && 255UL) <= 5UL)) < l_2232[1]) != 0L), g_8[(g_10 + 1)][g_9])) <= g_754) | g_580[1]), l_2233)) <= (-1L)) > l_2197) , l_2058) == 0xDED5L), 0x8AL)) == l_2232[1]) == l_2229) || g_1165) , l_2231), 0xC11BL));
            }
          }
          g_580[0] = 1L;
        }

        g_580[0] = 1L;
        {
          int8_t l_2037[6][7][2] = {{{0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L}},
                                    {{0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L}},
                                    {{0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L}},
                                    {{0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L}},
                                    {{0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L}},
                                    {{0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L},
                                     {0x1CL, 0L}}};
          int32_t l_2059 = (-1L);
          uint16_t l_2141 = 0xF260L;
          int32_t l_2163 = 0xB8660EB2L;
          int32_t l_2229 = 0xD9767C14L;
          int i, j, k;
          for (g_9 = 1; (g_9 >= 0); g_9 -= 1) {
            int16_t l_2149 = 0xCCC4L;
            int32_t l_2232[2];
            int i, j;
            for (i = 0; i < 2; i++)
              l_2232[i] = 1L;
            g_10 = g_8[(g_9 + 1)][g_9];
            for (g_10 = 0; (g_10 <= 1); g_10 += 1) {
              int32_t l_2058 = 0x38544D0EL;
              uint32_t l_2070 = 1UL;
              int32_t l_2085 = 0x0E069FBBL;
              int16_t l_2198[9];
              int32_t l_2233 = 0xB91FAD3AL;
              int i, j;
              for (i = 0; i < 9; i++)
                l_2198[i] = 0L;
              if ((0x9150L >= g_8[(g_10 + 1)][g_9])) {
                int8_t l_2035 = 0xC1L;
                l_2058 =
                    (func_11(
                         ((g_5[6],
                           (safe_sub_func_uint32_t_u_u(
                               g_8[(g_10 + 1)][g_9],
                               (safe_rshift_func_uint16_t_u_u(
                                   func_21(g_10),
                                   (((safe_mod_func_int8_t_s_s(l_2035, g_9)) |
                                     l_2035) <= l_2036)))))),
                          (l_2036, g_9)),
                         l_2037[4][5][0], g_8[(g_9 + 1)][g_9], l_2038,
                         g_8[(g_9 + 1)][g_9]) != l_2035);
                if (g_1165)
                  continue;
                l_2059 = l_2036;
              } else {
                uint16_t l_2086 = 0x583EL;
                uint32_t l_2105 = 18446744073709551612UL;
                g_830 = g_520[6];
                g_580[1] = g_227;
                g_580[1] = (safe_add_func_int32_t_s_s(
                    (((safe_unary_minus_func_uint8_t_u(l_2059)) |
                      (g_1625 ||
                       (safe_lshift_func_int16_t_s_s(
                           (safe_mod_func_int16_t_s_s(l_2036, l_2067[2])),
                           15)))) &
                     (safe_mod_func_uint16_t_u_u(g_1195, l_2070))),
                    (((safe_add_func_int16_t_s_s(
                          (safe_lshift_func_int16_t_s_u(
                              ((g_1195 ^
                                (safe_mod_func_int16_t_s_s(
                                    (((((safe_sub_func_uint16_t_u_u(
                                            (safe_lshift_func_uint8_t_u_s(
                                                (0xBAL <
                                                 ((safe_sub_func_int16_t_s_s(
                                                      ((safe_add_func_uint16_t_u_u(
                                                           g_8[(g_9 + 1)][g_9],
                                                           g_508[1][4][0])) &
                                                       l_2085),
                                                      g_508[2][4][0])) == 1UL)),
                                                1)),
                                            g_830)) >= l_2067[2]) ==
                                       l_2037[3][6][1]) >= l_2086),
                                     g_520[0]),
                                    g_508[1][2][0]))) < l_2038),
                              10)),
                          0xF45DL)) != g_1588),
                     l_2067[1])));
                g_830 = (safe_rshift_func_int16_t_s_u(
                    8L,
                    (((safe_mul_func_int8_t_s_s(
                          ((safe_lshift_func_int8_t_s_u(
                               l_2038,
                               ((((safe_mul_func_uint16_t_u_u(
                                      ((0x22L && 0xDAL) <=
                                       (safe_mod_func_int8_t_s_s(
                                           (safe_rshift_func_int8_t_s_s(
                                               (g_5[3] >
                                                ((0x6CL |
                                                  (safe_mod_func_uint32_t_u_u(
                                                      ((safe_sub_func_uint8_t_u_u(
                                                           0UL, l_2038)) <
                                                       ((safe_rshift_func_int16_t_s_s(
                                                            g_8[(g_9 + 1)][g_9],
                                                            g_520[0])),
                                                        0x12767035L)),
                                                      (-5L)))) == 0x85E16F77L)),
                                               g_1588)),
                                           g_830))),
                                      65527UL)) >= g_580[1]) != g_8[2][1]) >
                                g_358))) != g_10),
                          g_9)) ||
                      l_2105) ^
                     g_405[8])));
              }
              for (l_2038 = 0; (l_2038 <= 1); l_2038 += 1) {
                uint8_t l_2120 = 247UL;
                l_2120 =
                    ((l_2070,
                      (g_580[1] <=
                       (3L >
                        ((safe_sub_func_uint8_t_u_u(
                             ((g_580[3] &&
                               (safe_mul_func_int16_t_s_s(
                                   (safe_add_func_uint16_t_u_u(
                                       0x0E34L,
                                       ((safe_mul_func_uint16_t_u_u(
                                            1UL,
                                            (safe_mul_func_uint16_t_u_u(
                                                (((safe_mul_func_uint16_t_u_u(
                                                      ((0x3BE3L != (-1L)),
                                                       l_2038),
                                                      1UL)) ^
                                                  g_2) &
                                                 g_1195),
                                                g_101)))) ^
                                        g_8[1][0]))),
                                   l_2058))) != l_2038),
                             g_1588)) < g_458[0])))) >= g_227);
                if (g_2)
                  break;
                if (l_2036)
                  break;
                g_580[2] =
                    ((safe_add_func_int16_t_s_s(
                         (((l_2036 & (l_2070 != (l_2120 > l_2036))) !=
                           (0L !=
                            (((-2L) ==
                              ((safe_mod_func_int32_t_s_s(
                                   (((((safe_rshift_func_uint16_t_u_u(
                                           (safe_lshift_func_int16_t_s_s(
                                               (safe_sub_func_uint16_t_u_u(
                                                   ((safe_mul_func_uint8_t_u_u(
                                                        (safe_sub_func_int32_t_s_s(
                                                            (g_830 |
                                                             (((((safe_rshift_func_int16_t_s_s(
                                                                     ((safe_sub_func_uint32_t_u_u(
                                                                          (safe_mul_func_int8_t_s_s(
                                                                              (l_2067
                                                                                   [2] &&
                                                                               (g_1195 |
                                                                                1L)),
                                                                              l_2058)),
                                                                          1L)) ==
                                                                      l_2070),
                                                                     15)) ^
                                                                 3L) <=
                                                                0x8039L) &&
                                                               0x76520C5AL) |
                                                              4UL)),
                                                            g_101)),
                                                        l_2120)) >= g_458[0]),
                                                   1UL)),
                                               5)),
                                           15)) <= 1L) ||
                                      l_2038) >= 0x7247L) <= l_2037[4][5][0]),
                                   l_2141)) &
                               2L)),
                             g_227))) ^
                          (-1L)),
                         l_2142)) ^
                     g_142[3][0]);
              }
              if ((((safe_mod_func_int32_t_s_s(
                        (safe_sub_func_int16_t_s_s(
                            (((safe_mul_func_int8_t_s_s(
                                  (g_5[1] == l_2142), (g_405[6] || l_2149))) &&
                              1UL) <= g_508[2][4][0]),
                            (((safe_mul_func_uint8_t_u_u(
                                  (g_1195 &
                                   (((+((0x94L &&
                                         ((safe_add_func_uint32_t_u_u(
                                              ((((safe_rshift_func_int8_t_s_u(
                                                     (0x24C81AC5L !=
                                                      0x21380933L),
                                                     4)) ||
                                                 0xD40C0F3CL) ||
                                                g_8[(g_9 + 1)][g_9]) |
                                               0x52D8L),
                                              g_2)) < g_8[(g_10 + 1)][g_9])) ==
                                        0L)) &
                                     l_2085) > l_2067[2])),
                                  g_1165)) &
                              7L) == l_2059))),
                        0xCF5CA7DDL)) <= g_8[(g_9 + 1)][g_9]) |
                   l_2067[1])) {
                uint8_t l_2162[4] = {0x53L, 0x0DL, 0x53L, 0x0DL};
                int i;
                g_580[1] =
                    (l_2036 >=
                     ((+0xE040D8F8L) |
                      ((g_508[2][4][0] ^
                        ((safe_sub_func_int32_t_s_s(
                             (((safe_lshift_func_int8_t_s_s(
                                   (255UL >= (l_2142 !=
                                              (((((safe_rshift_func_int16_t_s_s(
                                                      g_508[2][4][0], 0)),
                                                  l_2067[2]) != l_2141) ||
                                                ((1UL ^ 246UL) != l_2142)) |
                                               4294967293UL))),
                                   2)),
                               (-1L)) >= 1L),
                             1L)) |
                         g_1625)) < l_2162[3])));
                l_2163 = l_2162[0];
                l_2058 =
                    ((((safe_mul_func_int16_t_s_s(
                           (-8L),
                           ((safe_rshift_func_int16_t_s_s(
                                (((((l_2070 ^
                                     (safe_add_func_int16_t_s_s(
                                         (g_458[0] ^
                                          ((safe_rshift_func_uint16_t_u_u(
                                               ((safe_unary_minus_func_uint16_t_u(
                                                    g_142[0][1])),
                                                0x7182L),
                                               l_2036)),
                                           g_5[6])),
                                         ((g_508[2][4][0],
                                           ((((safe_sub_func_int16_t_s_s(
                                                  (3L > 6L), l_2162[3])) &&
                                              0L),
                                             l_2067[2]) |
                                            l_2085)) >= 0x7B49L)))),
                                    0UL) &
                                   g_101) == g_8[(g_9 + 1)][g_9]) &
                                 g_458[0]),
                                6)) >= g_405[8]))),
                       g_2) != g_405[8]),
                     0x53BBB007L);
              } else {
                int32_t l_2197 = (-9L);
                uint16_t l_2230[4][10][5] = {
                    {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}},
                    {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}},
                    {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}},
                    {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                     {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}}};
                int i, j, k;
                l_2198[6] =
                    (g_101,
                     (((safe_add_func_uint16_t_u_u(
                           (((((((safe_sub_func_int16_t_s_s(
                                     (safe_lshift_func_uint8_t_u_s(
                                         (!(((-1L) >
                                             (safe_add_func_int32_t_s_s(
                                                 ((safe_add_func_uint8_t_u_u(
                                                      l_2085,
                                                      (safe_sub_func_int32_t_s_s(
                                                          ((safe_add_func_uint16_t_u_u(
                                                               (l_2085 ||
                                                                (safe_lshift_func_int16_t_s_s(
                                                                    (g_1625 >
                                                                     (safe_sub_func_uint8_t_u_u(
                                                                         ((l_2036 |
                                                                           (safe_mod_func_uint16_t_u_u(
                                                                               g_520
                                                                                   [0],
                                                                               (g_405
                                                                                    [8] ^
                                                                                ((safe_mod_func_int8_t_s_s(
                                                                                     (-8L),
                                                                                     g_830)) >=
                                                                                 l_2149))))) &
                                                                          l_2038),
                                                                         g_830))),
                                                                    12))),
                                                               l_2197)) >=
                                                           l_2197),
                                                          l_2070)))) ==
                                                  g_458[0]),
                                                 0UL))) == g_1588)),
                                         l_2058)),
                                     l_2142)) > 0xA7511AFCL) ^
                                g_10) |
                               0x4495FEC8L) == g_458[0]) > 65532UL) > 0x730FL),
                           0xE99FL)),
                       g_458[0]) >= 4294967295UL));
                        g_580[1] = (safe_add_func_uint16_t_u_u((((((safe_add_func_uint8_t_u_u((((((safe_mul_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_u(((((l_2197 > 0xC0L) | (((safe_add_func_uint32_t_u_u((safe_sub_func_int16_t_s_s(((((safe_mul_func_int16_t_s_s((~((safe_sub_func_uint32_t_u_u(0xE8633FD1L, (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((0L > g_101) && (((l_2036 , (l_2036 && (safe_mod_func_uint16_t_u_u((g_1588 & (safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u((((((l_2036 && g_208) && l_2229) < g_520[6]) == g_508[0][6][0]) || g_227), 0x30L)), g_5[6])) != l_2230[0][3][3]) , g_1588), 1L))), g_1625)))) >= g_458[0]) , l_2142)), g_458[0])), l_2036)))) & l_2231)), 2UL)) <= g_358) <= g_8[(g_9 + 1)][g_9]) != g_101), (-1L))), 0xAE57AF4CL)) && 255UL) <= 5UL)) < l_2232[1]) != 0L), g_8[(g_10 + 1)][g_9])) <= g_754) | g_580[1]), l_2233)) <= (-1L)) > l_2197) , l_2058) == 0xDED5L), 0x8AL)) == l_2232[1]) == l_2229) || g_1165) , l_2231), 0xC11BL));
              }
            }
            g_580[0] = 1L;
          }
          if (g_508[1][1][0])
            break;
          l_2163 = (9UL | g_508[2][4][0]);
        }
      }
      for (i = 0; i < 3; i++)
        l_2067[i] = 0x95763659L;

      for (g_5[6] = 0; (g_5[6] == (-15)); g_5[6]--) {
        int8_t l_2037[6][7][2] = {{{0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L}},
                                  {{0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L}},
                                  {{0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L}},
                                  {{0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L}},
                                  {{0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L}},
                                  {{0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L},
                                   {0x1CL, 0L}}};
        int32_t l_2059 = (-1L);
        uint16_t l_2141 = 0xF260L;
        int32_t l_2163 = 0xB8660EB2L;
        int32_t l_2229 = 0xD9767C14L;
        int i, j, k;
        for (g_9 = 1; (g_9 >= 0); g_9 -= 1) {
          int16_t l_2149 = 0xCCC4L;
          int32_t l_2232[2];
          int i, j;
          for (i = 0; i < 2; i++)
            l_2232[i] = 1L;
          g_10 = g_8[(g_9 + 1)][g_9];
          for (g_10 = 0; (g_10 <= 1); g_10 += 1) {
            int32_t l_2058 = 0x38544D0EL;
            uint32_t l_2070 = 1UL;
            int32_t l_2085 = 0x0E069FBBL;
            int16_t l_2198[9];
            int32_t l_2233 = 0xB91FAD3AL;
            int i, j;
            for (i = 0; i < 9; i++)
              l_2198[i] = 0L;
            if ((0x9150L >= g_8[(g_10 + 1)][g_9])) {
              int8_t l_2035 = 0xC1L;
              l_2058 =
                  (func_11(((g_5[6],
                             (safe_sub_func_uint32_t_u_u(
                                 g_8[(g_10 + 1)][g_9],
                                 (safe_rshift_func_uint16_t_u_u(
                                     func_21(g_10),
                                     (((safe_mod_func_int8_t_s_s(l_2035, g_9)) |
                                       l_2035) <= l_2036)))))),
                            (l_2036, g_9)),
                           l_2037[4][5][0], g_8[(g_9 + 1)][g_9], l_2038,
                           g_8[(g_9 + 1)][g_9]) != l_2035);
              if (g_1165)
                continue;
              l_2059 = l_2036;
            } else {
              uint16_t l_2086 = 0x583EL;
              uint32_t l_2105 = 18446744073709551612UL;
              g_830 = g_520[6];
              g_580[1] = g_227;
              g_580[1] = (safe_add_func_int32_t_s_s(
                  (((safe_unary_minus_func_uint8_t_u(l_2059)) |
                    (g_1625 ||
                     (safe_lshift_func_int16_t_s_s(
                         (safe_mod_func_int16_t_s_s(l_2036, l_2067[2])),
                         15)))) &
                   (safe_mod_func_uint16_t_u_u(g_1195, l_2070))),
                  (((safe_add_func_int16_t_s_s(
                        (safe_lshift_func_int16_t_s_u(
                            ((g_1195 ^
                              (safe_mod_func_int16_t_s_s(
                                  (((((safe_sub_func_uint16_t_u_u(
                                          (safe_lshift_func_uint8_t_u_s(
                                              (0xBAL <
                                               ((safe_sub_func_int16_t_s_s(
                                                    ((safe_add_func_uint16_t_u_u(
                                                         g_8[(g_9 + 1)][g_9],
                                                         g_508[1][4][0])) &
                                                     l_2085),
                                                    g_508[2][4][0])) == 1UL)),
                                              1)),
                                          g_830)) >= l_2067[2]) ==
                                     l_2037[3][6][1]) >= l_2086),
                                   g_520[0]),
                                  g_508[1][2][0]))) < l_2038),
                            10)),
                        0xF45DL)) != g_1588),
                   l_2067[1])));
              g_830 = (safe_rshift_func_int16_t_s_u(
                  8L,
                  (((safe_mul_func_int8_t_s_s(
                        ((safe_lshift_func_int8_t_s_u(
                             l_2038,
                             ((((safe_mul_func_uint16_t_u_u(
                                    ((0x22L && 0xDAL) <=
                                     (safe_mod_func_int8_t_s_s(
                                         (safe_rshift_func_int8_t_s_s(
                                             (g_5[3] >
                                              ((0x6CL |
                                                (safe_mod_func_uint32_t_u_u(
                                                    ((safe_sub_func_uint8_t_u_u(
                                                         0UL, l_2038)) <
                                                     ((safe_rshift_func_int16_t_s_s(
                                                          g_8[(g_9 + 1)][g_9],
                                                          g_520[0])),
                                                      0x12767035L)),
                                                    (-5L)))) == 0x85E16F77L)),
                                             g_1588)),
                                         g_830))),
                                    65527UL)) >= g_580[1]) != g_8[2][1]) >
                              g_358))) != g_10),
                        g_9)) ||
                    l_2105) ^
                   g_405[8])));
            }
            for (l_2038 = 0; (l_2038 <= 1); l_2038 += 1) {
              uint8_t l_2120 = 247UL;
              l_2120 =
                  ((l_2070,
                    (g_580[1] <=
                     (3L >
                      ((safe_sub_func_uint8_t_u_u(
                           ((g_580[3] &&
                             (safe_mul_func_int16_t_s_s(
                                 (safe_add_func_uint16_t_u_u(
                                     0x0E34L,
                                     ((safe_mul_func_uint16_t_u_u(
                                          1UL,
                                          (safe_mul_func_uint16_t_u_u(
                                              (((safe_mul_func_uint16_t_u_u(
                                                    ((0x3BE3L != (-1L)),
                                                     l_2038),
                                                    1UL)) ^
                                                g_2) &
                                               g_1195),
                                              g_101)))) ^
                                      g_8[1][0]))),
                                 l_2058))) != l_2038),
                           g_1588)) < g_458[0])))) >= g_227);
              if (g_2)
                break;
              if (l_2036)
                break;
              g_580[2] =
                  ((safe_add_func_int16_t_s_s(
                       (((l_2036 & (l_2070 != (l_2120 > l_2036))) !=
                         (0L !=
                          (((-2L) ==
                            ((safe_mod_func_int32_t_s_s(
                                 (((((safe_rshift_func_uint16_t_u_u(
                                         (safe_lshift_func_int16_t_s_s(
                                             (safe_sub_func_uint16_t_u_u(
                                                 ((safe_mul_func_uint8_t_u_u(
                                                      (safe_sub_func_int32_t_s_s(
                                                          (g_830 |
                                                           (((((safe_rshift_func_int16_t_s_s(
                                                                   ((safe_sub_func_uint32_t_u_u(
                                                                        (safe_mul_func_int8_t_s_s(
                                                                            (l_2067
                                                                                 [2] &&
                                                                             (g_1195 |
                                                                              1L)),
                                                                            l_2058)),
                                                                        1L)) ==
                                                                    l_2070),
                                                                   15)) ^
                                                               3L) <=
                                                              0x8039L) &&
                                                             0x76520C5AL) |
                                                            4UL)),
                                                          g_101)),
                                                      l_2120)) >= g_458[0]),
                                                 1UL)),
                                             5)),
                                         15)) <= 1L) ||
                                    l_2038) >= 0x7247L) <= l_2037[4][5][0]),
                                 l_2141)) &
                             2L)),
                           g_227))) ^
                        (-1L)),
                       l_2142)) ^
                   g_142[3][0]);
            }
            if ((((safe_mod_func_int32_t_s_s(
                      (safe_sub_func_int16_t_s_s(
                          (((safe_mul_func_int8_t_s_s((g_5[1] == l_2142),
                                                      (g_405[6] || l_2149))) &&
                            1UL) <= g_508[2][4][0]),
                          (((safe_mul_func_uint8_t_u_u(
                                (g_1195 &
                                 (((+((0x94L &&
                                       ((safe_add_func_uint32_t_u_u(
                                            ((((safe_rshift_func_int8_t_s_u(
                                                   (0x24C81AC5L != 0x21380933L),
                                                   4)) ||
                                               0xD40C0F3CL) ||
                                              g_8[(g_9 + 1)][g_9]) |
                                             0x52D8L),
                                            g_2)) < g_8[(g_10 + 1)][g_9])) ==
                                      0L)) &
                                   l_2085) > l_2067[2])),
                                g_1165)) &
                            7L) == l_2059))),
                      0xCF5CA7DDL)) <= g_8[(g_9 + 1)][g_9]) |
                 l_2067[1])) {
              uint8_t l_2162[4] = {0x53L, 0x0DL, 0x53L, 0x0DL};
              int i;
              g_580[1] =
                  (l_2036 >=
                   ((+0xE040D8F8L) |
                    ((g_508[2][4][0] ^
                      ((safe_sub_func_int32_t_s_s(
                           (((safe_lshift_func_int8_t_s_s(
                                 (255UL >=
                                  (l_2142 != (((((safe_rshift_func_int16_t_s_s(
                                                     g_508[2][4][0], 0)),
                                                 l_2067[2]) != l_2141) ||
                                               ((1UL ^ 246UL) != l_2142)) |
                                              4294967293UL))),
                                 2)),
                             (-1L)) >= 1L),
                           1L)) |
                       g_1625)) < l_2162[3])));
              l_2163 = l_2162[0];
              l_2058 =
                  ((((safe_mul_func_int16_t_s_s(
                         (-8L),
                         ((safe_rshift_func_int16_t_s_s(
                              (((((l_2070 ^
                                   (safe_add_func_int16_t_s_s(
                                       (g_458[0] ^
                                        ((safe_rshift_func_uint16_t_u_u(
                                             ((safe_unary_minus_func_uint16_t_u(
                                                  g_142[0][1])),
                                              0x7182L),
                                             l_2036)),
                                         g_5[6])),
                                       ((g_508[2][4][0],
                                         ((((safe_sub_func_int16_t_s_s(
                                                (3L > 6L), l_2162[3])) &&
                                            0L),
                                           l_2067[2]) |
                                          l_2085)) >= 0x7B49L)))),
                                  0UL) &
                                 g_101) == g_8[(g_9 + 1)][g_9]) &
                               g_458[0]),
                              6)) >= g_405[8]))),
                     g_2) != g_405[8]),
                   0x53BBB007L);
            } else {
              int32_t l_2197 = (-9L);
              uint16_t l_2230[4][10][5] = {{{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}},
                                           {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}},
                                           {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}},
                                           {{3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL},
                                            {3UL, 0x248CL, 0UL, 0x0FD3L, 6UL}}};
              int i, j, k;
              l_2198[6] =
                  (g_101,
                   (((safe_add_func_uint16_t_u_u(
                         (((((((safe_sub_func_int16_t_s_s(
                                   (safe_lshift_func_uint8_t_u_s(
                                       (!(((-1L) >
                                           (safe_add_func_int32_t_s_s(
                                               ((safe_add_func_uint8_t_u_u(
                                                    l_2085,
                                                    (safe_sub_func_int32_t_s_s(
                                                        ((safe_add_func_uint16_t_u_u(
                                                             (l_2085 ||
                                                              (safe_lshift_func_int16_t_s_s(
                                                                  (g_1625 >
                                                                   (safe_sub_func_uint8_t_u_u(
                                                                       ((l_2036 |
                                                                         (safe_mod_func_uint16_t_u_u(
                                                                             g_520
                                                                                 [0],
                                                                             (g_405
                                                                                  [8] ^
                                                                              ((safe_mod_func_int8_t_s_s(
                                                                                   (-8L),
                                                                                   g_830)) >=
                                                                               l_2149))))) &
                                                                        l_2038),
                                                                       g_830))),
                                                                  12))),
                                                             l_2197)) >=
                                                         l_2197),
                                                        l_2070)))) == g_458[0]),
                                               0UL))) == g_1588)),
                                       l_2058)),
                                   l_2142)) > 0xA7511AFCL) ^
                              g_10) |
                             0x4495FEC8L) == g_458[0]) > 65532UL) > 0x730FL),
                         0xE99FL)),
                     g_458[0]) >= 4294967295UL));
                        g_580[1] = (safe_add_func_uint16_t_u_u((((((safe_add_func_uint8_t_u_u((((((safe_mul_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_u(((((l_2197 > 0xC0L) | (((safe_add_func_uint32_t_u_u((safe_sub_func_int16_t_s_s(((((safe_mul_func_int16_t_s_s((~((safe_sub_func_uint32_t_u_u(0xE8633FD1L, (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((0L > g_101) && (((l_2036 , (l_2036 && (safe_mod_func_uint16_t_u_u((g_1588 & (safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u((((((l_2036 && g_208) && l_2229) < g_520[6]) == g_508[0][6][0]) || g_227), 0x30L)), g_5[6])) != l_2230[0][3][3]) , g_1588), 1L))), g_1625)))) >= g_458[0]) , l_2142)), g_458[0])), l_2036)))) & l_2231)), 2UL)) <= g_358) <= g_8[(g_9 + 1)][g_9]) != g_101), (-1L))), 0xAE57AF4CL)) && 255UL) <= 5UL)) < l_2232[1]) != 0L), g_8[(g_10 + 1)][g_9])) <= g_754) | g_580[1]), l_2233)) <= (-1L)) > l_2197) , l_2058) == 0xDED5L), 0x8AL)) == l_2232[1]) == l_2229) || g_1165) , l_2231), 0xC11BL));
            }
          }
          g_580[0] = 1L;
        }
        if (g_508[1][1][0])
          break;
        l_2163 = (9UL | g_508[2][4][0]);
      }

      l_2163 = (9UL | g_508[2][4][0]);
      l_2163 = (9UL | g_508[2][4][0]);
    }
  }
  return g_458[0];
}

static int8_t func_11(uint16_t p_12, int16_t p_13, int32_t p_14, uint32_t p_15,
                      uint32_t p_16) {
  uint8_t l_2046 = 1UL;

  return p_16;
}

static uint16_t func_21(uint16_t p_22) {
  uint32_t l_45[3];
  uint8_t l_51 = 0x0FL;
  int32_t l_1687 = 0xA3E2613DL;
  int32_t l_1776 = 0x3BBE683FL;
  uint32_t l_1946 = 18446744073709551607UL;
  int8_t l_2024 = 1L;
  int i;
  for (i = 0; i < 3; i++)
    l_45[i] = 0UL;
lbl_1856:
  g_580[1] =
      (func_23(((safe_mod_func_uint16_t_u_u(
                    g_2,
                    (safe_lshift_func_int16_t_s_u(
                        ((safe_mod_func_uint32_t_u_u(
                             (((((func_36(p_22, p_22) &&
                                  (safe_add_func_uint32_t_u_u(
                                      (safe_mod_func_uint16_t_u_u(
                                          l_45[0], func_46(p_22, g_9, g_5[8],
                                                           (((((g_5[6] | l_51) |
                                                               p_22) > 252UL) |
                                                             0xA4L) == 5L)))),
                                      g_1588))),
                                 g_1625) ||
                                p_22),
                               (-7L)),
                              4294967295UL),
                             l_45[0])),
                         g_8[1][0]),
                        g_5[0])))) > 0UL),
               g_2, p_22, g_2),
       g_458[0]);
  if (g_1195) {
    int16_t l_1688 = 0x35CEL;
    int32_t l_1717[2];
    int16_t l_1850[2];
    int16_t l_1895 = 0x421BL;
    int i;
    for (i = 0; i < 2; i++) {
      l_1717[i] = 0L;
      for (i = 0; i < 3; i++)
        l_45[i] = 0UL;

      for (i = 0; i < 3; i++)
        l_45[i] = 0UL;
    }

  lbl_1843:
    l_1687 = l_51;
    g_580[0] = 0x7EAF790BL;
    if (p_22) {
      uint8_t l_1693 = 255UL;
      uint32_t l_1700 = 4UL;
      int32_t l_1733 = (-7L);
      uint8_t l_1767 = 252UL;
      int32_t l_1768 = 0x9FD3A243L;

      {
        uint8_t l_1693 = 255UL;
        uint32_t l_1700 = 4UL;
        int32_t l_1733 = (-7L);
        uint8_t l_1767 = 252UL;
        int32_t l_1768 = 0x9FD3A243L;
        if (((((((+(p_22 >=
                    (((((l_1688,
                         ((((((((((((safe_add_func_int32_t_s_s(
                                        (safe_lshift_func_int8_t_s_u(
                                            0x33L,
                                            (p_22 ^
                                             (l_1693 ||
                                              (g_101 !=
                                               (safe_mul_func_uint8_t_u_u(
                                                   p_22,
                                                   ((safe_add_func_int16_t_s_s(
                                                        (safe_rshift_func_uint16_t_u_s(
                                                            2UL, 14)),
                                                        0xD796L)) &&
                                                    p_22)))))))),
                                        g_520[6])),
                                    l_1688) |
                                   0x19L) == g_458[0]),
                                 l_1688) <= 1L) > 1UL) |
                              l_1688) <= g_830) &
                            l_51) <= g_5[6]) > p_22)),
                        g_1195) ||
                       4294967289UL) < l_1700) != 0x0591EFB8L))) &
                 p_22) &
                g_5[6]) ||
               l_1693) ^
              g_754) |
             g_227)) {
          int8_t l_1714 = (-1L);
          g_830 =
              ((((safe_mod_func_int32_t_s_s(
                     (safe_unary_minus_func_uint32_t_u((
                         (safe_sub_func_int16_t_s_s(l_45[0], 65534UL)) ==
                         ((safe_lshift_func_int16_t_s_s(
                              ((safe_sub_func_uint8_t_u_u(
                                   ((((safe_mod_func_int8_t_s_s(
                                          0x24L,
                                          ((((safe_rshift_func_int16_t_s_s(
                                                 (l_1714 > g_405[1]),
                                                 (p_22 >=
                                                  ((((safe_sub_func_int32_t_s_s(
                                                         (((-1L) |
                                                           (0UL > 4UL)) &
                                                          p_22),
                                                         p_22)) &&
                                                     0x32C4976CL),
                                                    l_1688) == l_1688)))) <
                                             0x6D99L) ^
                                            p_22) |
                                           2UL))) &
                                      l_1688) &
                                     0x22D6D603L) |
                                    p_22),
                                   l_1688)) &
                               0L),
                              10)),
                          l_45[0])))),
                     g_1588)) ||
                 g_580[0]) < 0L) > l_1714);
          l_1717[1] = ((p_22 >= 0x35D6L) > p_22);
          l_1717[1] = (safe_sub_func_int8_t_s_s(
              (safe_sub_func_uint32_t_u_u(
                  (((p_22 && (!l_1717[1])) >= g_520[0]) ==
                   ((safe_unary_minus_func_uint32_t_u(
                        (((safe_add_func_int32_t_s_s(
                              (l_1700 |
                               (safe_mod_func_int8_t_s_s(
                                   (safe_rshift_func_uint8_t_u_u(
                                       (1UL <=
                                        (((((((safe_lshift_func_uint16_t_u_s(
                                                  (p_22 !=
                                                   (((safe_sub_func_int8_t_s_s(
                                                         (l_1733 != l_1717[0]),
                                                         (-1L))) ^
                                                     g_406) &&
                                                    g_2)),
                                                  l_1700)),
                                              6UL) != g_458[0]) ^
                                            g_458[0]),
                                           p_22) >= g_520[0]) &
                                         l_1717[1])),
                                       3)),
                                   l_1714))),
                              g_5[6])) <= 0xD47E2DAEL) != p_22))),
                    4294967295UL)),
                  g_405[8])),
              g_754));
        } else {
          uint32_t l_1766[5][9] = {
              {18446744073709551615UL, 18446744073709551615UL, 0x981E0BC1L,
               18446744073709551609UL, 0xAF3B28D0L, 18446744073709551609UL,
               0x981E0BC1L, 18446744073709551615UL, 18446744073709551615UL},
              {18446744073709551615UL, 18446744073709551615UL, 0x981E0BC1L,
               18446744073709551609UL, 0xAF3B28D0L, 18446744073709551609UL,
               0x981E0BC1L, 18446744073709551615UL, 18446744073709551615UL},
              {18446744073709551615UL, 18446744073709551615UL, 0x981E0BC1L,
               18446744073709551609UL, 0xAF3B28D0L, 18446744073709551609UL,
               0x981E0BC1L, 18446744073709551615UL, 18446744073709551615UL},
              {18446744073709551615UL, 18446744073709551615UL, 0x981E0BC1L,
               18446744073709551609UL, 0xAF3B28D0L, 18446744073709551609UL,
               0x981E0BC1L, 18446744073709551615UL, 18446744073709551615UL},
              {18446744073709551615UL, 18446744073709551615UL, 0x981E0BC1L,
               18446744073709551609UL, 0xAF3B28D0L, 18446744073709551609UL,
               0x981E0BC1L, 18446744073709551615UL, 18446744073709551615UL}};
          int i, j;
          for (l_51 = 0; (l_51 >= 5); l_51++) {
            uint8_t l_1749[1];
            int32_t l_1769[10] = {0x7732275CL, 1L, 0x7732275CL, 1L,
                                  0x7732275CL, 1L, 0x7732275CL, 1L,
                                  0x7732275CL, 1L};
            int i;
            for (i = 0; i < 1; i++)
              l_1749[i] = 255UL;
            for (l_1688 = 0; (l_1688 <= 8); l_1688 += 1) {
              int32_t l_1750 = 0xE6909761L;
              int i;
              g_580[2] =
                  ((((g_520[l_1688] ||
                      ((safe_lshift_func_int8_t_s_s(
                           (((((safe_add_func_uint32_t_u_u(
                                   ((p_22 &&
                                     (safe_rshift_func_int8_t_s_s(
                                         ((p_22 !=
                                           ((safe_unary_minus_func_uint32_t_u(
                                                (safe_rshift_func_int8_t_s_s(
                                                    l_1700, 4)))),
                                            ((safe_rshift_func_int16_t_s_s(
                                                 (safe_mul_func_int8_t_s_s(
                                                     ((((g_520[0],
                                                         ((l_45[0] !=
                                                           g_520[0]) <=
                                                          g_358)) |
                                                        (p_22, p_22)) !=
                                                       0x19L) != 0x005AD943L),
                                                     p_22)),
                                                 g_1588)) ||
                                             l_51))) ||
                                          p_22),
                                         g_1625))),
                                    0x4A949223L),
                                   l_1749[0])) > g_358) <= g_2),
                             l_1749[0]) <= 4294967295UL),
                           2)) &
                       p_22)) > p_22) ^
                    l_1750) != 9L);
              g_830 =
                  ((safe_sub_func_int8_t_s_s(
                       (safe_add_func_int8_t_s_s(
                           ((l_1749[0] |
                             ((safe_sub_func_int32_t_s_s((-8L), l_1750)) &
                              (l_1749[0] ==
                               (((safe_add_func_uint32_t_u_u(
                                     (safe_rshift_func_uint16_t_u_s(p_22, 9)),
                                     p_22)) <=
                                 ((l_1749[0] <
                                   (((p_22 &
                                      ((safe_add_func_uint8_t_u_u(
                                           (safe_add_func_uint32_t_u_u(
                                               ((safe_unary_minus_func_uint32_t_u(
                                                    (~((255UL != g_142[4][2]) <=
                                                       l_1766[1][5])))) &
                                                l_1767),
                                               0xF4D917C2L)),
                                           l_1749[0])) >= g_5[5])) ^
                                     l_51) < 0xC01B4D91L)),
                                  0xE50CL)),
                                l_1693)))) ^
                            g_520[l_1688]),
                           0x28L)),
                       0x7EL)) &
                   0x14ABCF1FL);
              l_1768 = p_22;
            }
            l_1769[8] = 0x403F0A83L;
            l_1717[0] = g_358;
          }
          return p_22;
        }
            g_580[0] = ((((safe_mul_func_uint16_t_u_u(((0xC009L > g_1588) & (safe_mod_func_uint32_t_u_u(l_1693, (safe_sub_func_int16_t_s_s(g_508[2][0][0], l_1776))))), (((safe_rshift_func_uint16_t_u_u((((((safe_lshift_func_uint8_t_u_s((((safe_mul_func_int8_t_s_s((g_2 <= (((((((safe_lshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u((((safe_rshift_func_int8_t_s_u(((safe_mul_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u((safe_mul_func_int8_t_s_s(l_1767, (safe_rshift_func_int8_t_s_s(((safe_mul_func_int16_t_s_s((safe_add_func_uint32_t_u_u((0x56B8C77BL > ((g_142[0][1] && 4294967286UL) <= l_1776)), 0xE9C2AEB3L)), l_1776)) & p_22), 3)))), g_1625)) , l_1717[1]), 3UL)) , p_22), p_22)) > l_1776), p_22)) && g_458[0]) == (-1L)), l_1688)), 2)) , l_1776), p_22)) >= (-1L)) , 0x547DA53AL) <= g_208) || p_22) || 0L) && l_51)), p_22)) , 0xABC20D0AL) ^ 0x4B215BF4L), l_45[2])) , g_1588) , 1UL) || p_22) || l_1688), 9)) , g_9) < g_1195))) > l_51) , (-1L)) , (-1L));
            return l_1717[0];
      }

      for (i = 0; i < 2; i++)
        l_1850[i] = 0L;

      return l_1717[0];
    } else {
      uint32_t l_1823 = 0xA82F9AD5L;
      int32_t l_1900 = 0xF70E6F28L;
    lbl_1855:
      if (((g_508[2][4][0] |
            (0x79L &
             ((((safe_mod_func_uint8_t_u_u(
                    ((p_22 &&
                      (safe_mul_func_uint8_t_u_u(
                          (((l_1717[1],
                             ((p_22 ^
                               (p_22,
                                (((safe_add_func_int8_t_s_s(
                                      (((safe_mul_func_int16_t_s_s(
                                            (p_22 < g_405[6]),
                                            (safe_add_func_uint32_t_u_u(
                                                ((safe_rshift_func_uint8_t_u_u(
                                                     (safe_rshift_func_uint16_t_u_s(
                                                         ((((((safe_sub_func_int16_t_s_s(
                                                                  ((g_580[0] ||
                                                                    g_5[3]) ^
                                                                   0L),
                                                                  p_22)),
                                                              0x7DE91883L) >=
                                                             p_22) &
                                                            g_508[2][4][0]) |
                                                           0x2254L) >= 65527UL),
                                                         8)),
                                                     2)) == p_22),
                                                0xBB9BE894L)))) >= l_1823),
                                       0xCFL),
                                      0L)) != p_22) < 0x873EFC68L))) > p_22)) >
                            0x2FL),
                           l_1823),
                          0UL))),
                     g_10),
                    g_458[0])),
                0x922804D8L),
               0x91E0L) < g_405[7]))),
           p_22)) {
        uint32_t l_1830[10];
        int i;
        for (i = 0; i < 10; i++)
          l_1830[i] = 4294967295UL;
        l_1717[1] = (safe_rshift_func_uint16_t_u_s(0xFDA2L, 2));
        g_580[1] = (safe_add_func_uint16_t_u_u(
            (safe_mod_func_int8_t_s_s(g_10, l_1823)),
            (((l_1830[7] &&
               (safe_add_func_int16_t_s_s(
                   ((safe_mod_func_int8_t_s_s(
                        (0xA9L <=
                         ((((safe_sub_func_uint8_t_u_u(
                                (l_1830[4] > (safe_mod_func_uint16_t_u_u(
                                                 l_1717[1], g_458[0]))),
                                p_22)) ^
                            ((safe_lshift_func_int8_t_s_s(
                                 (safe_sub_func_uint32_t_u_u((l_1823, 0UL),
                                                             g_830)),
                                 6)) |
                             g_580[1])) == g_458[0]) ^
                          9L)),
                        g_520[8])),
                    p_22),
                   1UL))) < p_22) ||
             p_22)));
      } else {
        if (g_406)
          goto lbl_1843;
      }

      for (i = 0; i < 2; i++)
        l_1717[i] = 0L;

      return g_405[1];
    }
  } else {
    uint16_t l_1926 = 65535UL;

    if (g_1588) {
      int16_t l_1931 = 1L;
      int32_t l_1945[6] = {(-1L), (-1L), 0x35121526L,
                           (-1L), (-1L), 0x35121526L};
      int i;
      if ((safe_add_func_uint8_t_u_u(
              (~(p_22 || p_22)),
              (((((safe_add_func_int16_t_s_s(
                      (g_2 <= (((safe_mod_func_uint16_t_u_u(6UL, p_22)),
                                (safe_sub_func_uint32_t_u_u(
                                    ((((safe_add_func_int8_t_s_s(
                                           (g_580[1] >
                                            (((l_1926 |
                                               ((safe_rshift_func_uint16_t_u_s(
                                                    (safe_mod_func_int32_t_s_s(
                                                        g_142[4][1], g_830)),
                                                    15)) < g_508[0][7][0])) ^
                                              p_22),
                                             l_1931)),
                                           g_227)) != g_8[2][1]) <= p_22) ^
                                     p_22),
                                    g_1195))) >= 4294967295UL)),
                      g_358)) ^
                  l_1931) < 0L) == g_208) > 1UL)))) {
        int8_t l_1944[4][7] = {{(-7L), 0xF4L, 1L, 0L, 8L, (-5L), 8L},
                               {(-7L), 0xF4L, 1L, 0L, 8L, (-5L), 8L},
                               {(-7L), 0xF4L, 1L, 0L, 8L, (-5L), 8L},
                               {(-7L), 0xF4L, 1L, 0L, 8L, (-5L), 8L}};
        int i, j;
        l_1945[1] =
            ((((safe_sub_func_uint8_t_u_u(
                   0x41L,
                   ((((((safe_mod_func_uint8_t_u_u(
                            1UL, (safe_sub_func_int16_t_s_s(
                                     g_458[0], (safe_mod_func_int16_t_s_s(
                                                   l_1926, p_22)))))) !=
                        (safe_mul_func_int16_t_s_s(
                            ((safe_mul_func_uint8_t_u_u(
                                 (p_22 != (((p_22 || 0L) != (g_1195, 1L)) !=
                                           l_1944[1][0])),
                                 p_22)),
                             0xF0FBL),
                            g_580[2]))) ^
                       0x88D3L),
                      (-1L)) &
                     p_22),
                    g_406))) ||
               0L) <= p_22) ^
             l_45[0]);
        if ((l_1946, p_22)) {
          g_830 = l_1945[1];
        } else {
          uint16_t l_1960 = 65526UL;
          int32_t l_2025 = 0x45968C25L;
          if ((((!p_22),
                ((1L |
                  (~(((safe_sub_func_int32_t_s_s(
                          ((safe_mul_func_uint8_t_u_u(
                               ((safe_add_func_int16_t_s_s(
                                    1L,
                                    (((p_22,
                                       (!((((p_22 !=
                                             (safe_unary_minus_func_int8_t_s(
                                                 (safe_sub_func_int16_t_s_s(
                                                     p_22,
                                                     ((safe_unary_minus_func_uint16_t_u(
                                                          ((safe_mul_func_int16_t_s_s(
                                                               (((g_520[0],
                                                                  l_1926),
                                                                 (safe_unary_minus_func_int8_t_s(
                                                                     l_1687))) ||
                                                                g_405[8]),
                                                               1UL)) <
                                                           l_1926))) |
                                                      0x7D6B8347L)))))),
                                            0x8DBCE599L),
                                           g_580[2]) ||
                                          1L))) ^
                                      p_22) |
                                     0UL))) > p_22),
                               p_22)) <= p_22),
                          0xC2A58029L)) < p_22) &
                     l_1960))) &
                 l_1926)),
               g_508[1][9][0])) {
            return g_2;
          } else {
            int32_t l_1987 = 3L;
            uint16_t l_1997 = 1UL;
            g_830 =
                (((((((safe_rshift_func_uint16_t_u_s(
                          (g_1588 &&
                           (+(safe_unary_minus_func_int32_t_s((safe_rshift_func_int8_t_s_u(
                               ((safe_rshift_func_uint8_t_u_u(
                                    (((p_22 ==
                                       (safe_lshift_func_int16_t_s_s(
                                           ((-4L) != 0x1AL),
                                           13))) |
                                      ((safe_add_func_uint16_t_u_u(
                                           ((safe_add_func_int8_t_s_s(
                                                (safe_rshift_func_int16_t_s_s(
                                                    0x58E6L,
                                                    (safe_lshift_func_uint8_t_u_s(
                                                        (safe_lshift_func_int8_t_s_s(
                                                            g_101, 2)),
                                                        (safe_lshift_func_uint16_t_u_s(
                                                            ((((g_10 <
                                                                ((safe_mod_func_uint8_t_u_u(
                                                                     250UL,
                                                                     (safe_unary_minus_func_int8_t_s((
                                                                         (((safe_mul_func_uint8_t_u_u(
                                                                               ((p_22 <=
                                                                                 0x590E5EE8L) ||
                                                                                p_22),
                                                                               g_10)) ==
                                                                           0x52L) ||
                                                                          0xB726L),
                                                                         l_1926))))) ||
                                                                 g_405[8])),
                                                               g_5[2]) ||
                                                              g_754) != l_1931),
                                                            13)))))),
                                                p_22)),
                                            g_2),
                                           l_1960)) <= 0x2277BEF4L)) >= g_10),
                                    p_22)) < l_1987),
                               6)))))),
                          12)),
                      g_520[5]) ||
                     l_1960) < l_1946) ||
                   l_1945[1]) ||
                  0x67029D07L) > l_51);
            g_580[1] = l_1926;
            l_1997 =
                ((safe_unary_minus_func_uint8_t_u(p_22)) <
                 (safe_lshift_func_int8_t_s_s(
                     g_580[1],
                     ((((l_1926 ||
                         ((0x4D32D024L && p_22) !=
                          (safe_rshift_func_uint8_t_u_u(
                              ((safe_mul_func_int8_t_s_s(
                                   p_22, (((g_1588,
                                            ((safe_add_func_int8_t_s_s(
                                                 (-10L), 0x0FL)) <= 0x68B0L)) ||
                                           0x5EA29434L) |
                                          p_22))),
                               l_1926),
                              l_1987)))) < p_22) ||
                       1L) |
                      g_5[7]))));
          }
          l_2025 = (safe_mod_func_int32_t_s_s(
              ((((((4L &&
                    ((safe_sub_func_int8_t_s_s(
                         ((safe_sub_func_int16_t_s_s(
                              ((safe_mod_func_int16_t_s_s(
                                   (p_22 &
                                    (p_22 !=
                                     ((safe_mod_func_uint8_t_u_u(
                                          (safe_sub_func_int32_t_s_s(
                                              l_1960,
                                              ((l_1945[1],
                                                (safe_add_func_int32_t_s_s(
                                                    l_1926,
                                                    (safe_sub_func_uint16_t_u_u(
                                                        (((safe_mod_func_int16_t_s_s(
                                                              ((safe_sub_func_int32_t_s_s(
                                                                   (-3L),
                                                                   (safe_sub_func_int16_t_s_s(
                                                                       (((safe_rshift_func_int16_t_s_s(
                                                                             g_5[1],
                                                                             ((!(safe_mul_func_int16_t_s_s(
                                                                                  ((0UL |
                                                                                    0x79L) <
                                                                                   p_22),
                                                                                  p_22))) &&
                                                                              0xCA02L))) ||
                                                                         3UL) <=
                                                                        0xEB80L),
                                                                       l_1944
                                                                           [1]
                                                                           [0])))) >=
                                                               0xA59DL),
                                                              5L)) < 0xE20FL) <=
                                                         l_2024),
                                                        0x0714L))))) >=
                                               l_1945[1]))),
                                          g_508[0][2][0])) < g_405[8]))),
                                   g_227)) != 0x788B78DBL),
                              0x182DL)) &&
                          p_22),
                         0x99L)) &
                     l_45[0])),
                   l_51) != p_22),
                 p_22) >= 0x03L) &&
               g_405[1]),
              p_22));
        }
        l_1945[1] = 0xACFEA494L;
      } else {
        return g_458[0];
      }
      l_1776 = (4294967295UL <=
                ((safe_lshift_func_int16_t_s_s(
                     (safe_lshift_func_uint16_t_u_u(g_458[0], g_10)),
                     (safe_lshift_func_uint8_t_u_u(g_458[0], 1)))) > p_22));
    } else {
      uint32_t l_2032 = 0x5A3B6E36L;
      return l_2032;
    }

    l_1776 = l_45[0];
    if (g_1588) {
      int16_t l_1931 = 1L;
      int32_t l_1945[6] = {(-1L), (-1L), 0x35121526L,
                           (-1L), (-1L), 0x35121526L};
      int i;
      if ((safe_add_func_uint8_t_u_u(
              (~(p_22 || p_22)),
              (((((safe_add_func_int16_t_s_s(
                      (g_2 <= (((safe_mod_func_uint16_t_u_u(6UL, p_22)),
                                (safe_sub_func_uint32_t_u_u(
                                    ((((safe_add_func_int8_t_s_s(
                                           (g_580[1] >
                                            (((l_1926 |
                                               ((safe_rshift_func_uint16_t_u_s(
                                                    (safe_mod_func_int32_t_s_s(
                                                        g_142[4][1], g_830)),
                                                    15)) < g_508[0][7][0])) ^
                                              p_22),
                                             l_1931)),
                                           g_227)) != g_8[2][1]) <= p_22) ^
                                     p_22),
                                    g_1195))) >= 4294967295UL)),
                      g_358)) ^
                  l_1931) < 0L) == g_208) > 1UL)))) {
        int8_t l_1944[4][7] = {{(-7L), 0xF4L, 1L, 0L, 8L, (-5L), 8L},
                               {(-7L), 0xF4L, 1L, 0L, 8L, (-5L), 8L},
                               {(-7L), 0xF4L, 1L, 0L, 8L, (-5L), 8L},
                               {(-7L), 0xF4L, 1L, 0L, 8L, (-5L), 8L}};
        int i, j;
        l_1945[1] =
            ((((safe_sub_func_uint8_t_u_u(
                   0x41L,
                   ((((((safe_mod_func_uint8_t_u_u(
                            1UL, (safe_sub_func_int16_t_s_s(
                                     g_458[0], (safe_mod_func_int16_t_s_s(
                                                   l_1926, p_22)))))) !=
                        (safe_mul_func_int16_t_s_s(
                            ((safe_mul_func_uint8_t_u_u(
                                 (p_22 != (((p_22 || 0L) != (g_1195, 1L)) !=
                                           l_1944[1][0])),
                                 p_22)),
                             0xF0FBL),
                            g_580[2]))) ^
                       0x88D3L),
                      (-1L)) &
                     p_22),
                    g_406))) ||
               0L) <= p_22) ^
             l_45[0]);
        if ((l_1946, p_22)) {
          g_830 = l_1945[1];
        } else {
          uint16_t l_1960 = 65526UL;
          int32_t l_2025 = 0x45968C25L;
          if ((((!p_22),
                ((1L |
                  (~(((safe_sub_func_int32_t_s_s(
                          ((safe_mul_func_uint8_t_u_u(
                               ((safe_add_func_int16_t_s_s(
                                    1L,
                                    (((p_22,
                                       (!((((p_22 !=
                                             (safe_unary_minus_func_int8_t_s(
                                                 (safe_sub_func_int16_t_s_s(
                                                     p_22,
                                                     ((safe_unary_minus_func_uint16_t_u(
                                                          ((safe_mul_func_int16_t_s_s(
                                                               (((g_520[0],
                                                                  l_1926),
                                                                 (safe_unary_minus_func_int8_t_s(
                                                                     l_1687))) ||
                                                                g_405[8]),
                                                               1UL)) <
                                                           l_1926))) |
                                                      0x7D6B8347L)))))),
                                            0x8DBCE599L),
                                           g_580[2]) ||
                                          1L))) ^
                                      p_22) |
                                     0UL))) > p_22),
                               p_22)) <= p_22),
                          0xC2A58029L)) < p_22) &
                     l_1960))) &
                 l_1926)),
               g_508[1][9][0])) {
            return g_2;
          } else {
            int32_t l_1987 = 3L;
            uint16_t l_1997 = 1UL;
            g_830 =
                (((((((safe_rshift_func_uint16_t_u_s(
                          (g_1588 &&
                           (+(safe_unary_minus_func_int32_t_s((safe_rshift_func_int8_t_s_u(
                               ((safe_rshift_func_uint8_t_u_u(
                                    (((p_22 ==
                                       (safe_lshift_func_int16_t_s_s(
                                           ((-4L) != 0x1AL),
                                           13))) |
                                      ((safe_add_func_uint16_t_u_u(
                                           ((safe_add_func_int8_t_s_s(
                                                (safe_rshift_func_int16_t_s_s(
                                                    0x58E6L,
                                                    (safe_lshift_func_uint8_t_u_s(
                                                        (safe_lshift_func_int8_t_s_s(
                                                            g_101, 2)),
                                                        (safe_lshift_func_uint16_t_u_s(
                                                            ((((g_10 <
                                                                ((safe_mod_func_uint8_t_u_u(
                                                                     250UL,
                                                                     (safe_unary_minus_func_int8_t_s((
                                                                         (((safe_mul_func_uint8_t_u_u(
                                                                               ((p_22 <=
                                                                                 0x590E5EE8L) ||
                                                                                p_22),
                                                                               g_10)) ==
                                                                           0x52L) ||
                                                                          0xB726L),
                                                                         l_1926))))) ||
                                                                 g_405[8])),
                                                               g_5[2]) ||
                                                              g_754) != l_1931),
                                                            13)))))),
                                                p_22)),
                                            g_2),
                                           l_1960)) <= 0x2277BEF4L)) >= g_10),
                                    p_22)) < l_1987),
                               6)))))),
                          12)),
                      g_520[5]) ||
                     l_1960) < l_1946) ||
                   l_1945[1]) ||
                  0x67029D07L) > l_51);
            g_580[1] = l_1926;
            l_1997 =
                ((safe_unary_minus_func_uint8_t_u(p_22)) <
                 (safe_lshift_func_int8_t_s_s(
                     g_580[1],
                     ((((l_1926 ||
                         ((0x4D32D024L && p_22) !=
                          (safe_rshift_func_uint8_t_u_u(
                              ((safe_mul_func_int8_t_s_s(
                                   p_22, (((g_1588,
                                            ((safe_add_func_int8_t_s_s(
                                                 (-10L), 0x0FL)) <= 0x68B0L)) ||
                                           0x5EA29434L) |
                                          p_22))),
                               l_1926),
                              l_1987)))) < p_22) ||
                       1L) |
                      g_5[7]))));
          }
          l_2025 = (safe_mod_func_int32_t_s_s(
              ((((((4L &&
                    ((safe_sub_func_int8_t_s_s(
                         ((safe_sub_func_int16_t_s_s(
                              ((safe_mod_func_int16_t_s_s(
                                   (p_22 &
                                    (p_22 !=
                                     ((safe_mod_func_uint8_t_u_u(
                                          (safe_sub_func_int32_t_s_s(
                                              l_1960,
                                              ((l_1945[1],
                                                (safe_add_func_int32_t_s_s(
                                                    l_1926,
                                                    (safe_sub_func_uint16_t_u_u(
                                                        (((safe_mod_func_int16_t_s_s(
                                                              ((safe_sub_func_int32_t_s_s(
                                                                   (-3L),
                                                                   (safe_sub_func_int16_t_s_s(
                                                                       (((safe_rshift_func_int16_t_s_s(
                                                                             g_5[1],
                                                                             ((!(safe_mul_func_int16_t_s_s(
                                                                                  ((0UL |
                                                                                    0x79L) <
                                                                                   p_22),
                                                                                  p_22))) &&
                                                                              0xCA02L))) ||
                                                                         3UL) <=
                                                                        0xEB80L),
                                                                       l_1944
                                                                           [1]
                                                                           [0])))) >=
                                                               0xA59DL),
                                                              5L)) < 0xE20FL) <=
                                                         l_2024),
                                                        0x0714L))))) >=
                                               l_1945[1]))),
                                          g_508[0][2][0])) < g_405[8]))),
                                   g_227)) != 0x788B78DBL),
                              0x182DL)) &&
                          p_22),
                         0x99L)) &
                     l_45[0])),
                   l_51) != p_22),
                 p_22) >= 0x03L) &&
               g_405[1]),
              p_22));
        }
        l_1945[1] = 0xACFEA494L;
      } else {
        return g_458[0];
      }
      l_1776 = (4294967295UL <=
                ((safe_lshift_func_int16_t_s_s(
                     (safe_lshift_func_uint16_t_u_u(g_458[0], g_10)),
                     (safe_lshift_func_uint8_t_u_u(g_458[0], 1)))) > p_22));
    } else {
      uint32_t l_2032 = 0x5A3B6E36L;
      return l_2032;
    }

    return g_208;
  }
}

static int8_t func_23(int8_t p_24, uint8_t p_25, uint16_t p_26, int32_t p_27) {
  uint16_t l_1640 = 1UL;
  int32_t l_1684 = 5L;
  for (p_24 = 21; (p_24 != (-17)); --p_24) {
    uint8_t l_1641 = 0UL;
    int32_t l_1642 = 1L;
    int32_t l_1659 = 0L;

    l_1642 =
        ((((safe_rshift_func_uint16_t_u_u(
               (safe_rshift_func_int8_t_s_s(
                   (safe_rshift_func_uint8_t_u_u(
                       ((safe_lshift_func_int16_t_s_s(p_27, 7)) ^
                        ((((((safe_rshift_func_int8_t_s_s(
                                 (~((g_405[8] &&
                                     (safe_mod_func_uint8_t_u_u(
                                         (0xACE4L != 0xAB04L), 0x7AL))) &
                                    l_1640)),
                                 g_8[0][1])) >=
                             (0x059FL || ((l_1641 >= 0xC7228C1EL) < g_9))) &
                            0x9EL) == p_24) ||
                          p_25),
                         g_1625)),
                       p_24)),
                   2)),
               l_1640)) ^
           g_1195) != 0x95792450L) ^
         g_227);

    l_1659 =
        (((safe_mod_func_uint16_t_u_u(
              (0x973613BCL > g_830),
              (l_1640 |
               ((safe_rshift_func_int16_t_s_s(
                    0x3FFAL,
                    (safe_lshift_func_int16_t_s_u(
                        ((g_10 ||
                          (safe_lshift_func_int16_t_s_u(
                              ((l_1641, l_1641),
                               (((safe_add_func_uint16_t_u_u(
                                     (safe_rshift_func_uint16_t_u_u(
                                         ((safe_mod_func_uint32_t_u_u(
                                              ((safe_mod_func_uint32_t_u_u(
                                                   ((l_1641,
                                                     (g_9 > 0xE0315AD3L)) <=
                                                    g_1588),
                                                   l_1642)) > 0xC097L),
                                              0x43E008B5L)) ||
                                          4294967295UL),
                                         p_25)),
                                     p_24)),
                                 0xA80F52FFL) &
                                l_1640)),
                              g_101))) <= l_1641),
                        2)))) > 252UL)))),
          l_1641) > g_358);
    for (p_24 = 21; (p_24 != (-17)); --p_24) {
      uint8_t l_1641 = 0UL;
      int32_t l_1642 = 1L;
      int32_t l_1659 = 0L;
      l_1642 =
          ((((safe_rshift_func_uint16_t_u_u(
                 (safe_rshift_func_int8_t_s_s(
                     (safe_rshift_func_uint8_t_u_u(
                         ((safe_lshift_func_int16_t_s_s(p_27, 7)) ^
                          ((((((safe_rshift_func_int8_t_s_s(
                                   (~((g_405[8] &&
                                       (safe_mod_func_uint8_t_u_u(
                                           (0xACE4L != 0xAB04L), 0x7AL))) &
                                      l_1640)),
                                   g_8[0][1])) >=
                               (0x059FL || ((l_1641 >= 0xC7228C1EL) < g_9))) &
                              0x9EL) == p_24) ||
                            p_25),
                           g_1625)),
                         p_24)),
                     2)),
                 l_1640)) ^
             g_1195) != 0x95792450L) ^
           g_227);
      l_1659 =
          (((safe_mod_func_uint16_t_u_u(
                (0x973613BCL > g_830),
                (l_1640 |
                 ((safe_rshift_func_int16_t_s_s(
                      0x3FFAL,
                      (safe_lshift_func_int16_t_s_u(
                          ((g_10 ||
                            (safe_lshift_func_int16_t_s_u(
                                ((l_1641, l_1641),
                                 (((safe_add_func_uint16_t_u_u(
                                       (safe_rshift_func_uint16_t_u_u(
                                           ((safe_mod_func_uint32_t_u_u(
                                                ((safe_mod_func_uint32_t_u_u(
                                                     ((l_1641,
                                                       (g_9 > 0xE0315AD3L)) <=
                                                      g_1588),
                                                     l_1642)) > 0xC097L),
                                                0x43E008B5L)) ||
                                            4294967295UL),
                                           p_25)),
                                       p_24)),
                                   0xA80F52FFL) &
                                  l_1640)),
                                g_101))) <= l_1641),
                          2)))) > 252UL)))),
            l_1641) > g_358);
      l_1684 =
          (((((((safe_mul_func_uint8_t_u_u(
                    (safe_rshift_func_int16_t_s_u(
                        (safe_lshift_func_uint8_t_u_s(
                            ((safe_mul_func_int16_t_s_s(
                                 ((safe_mul_func_int8_t_s_s(
                                      (safe_mul_func_uint16_t_u_u(
                                          (safe_lshift_func_int8_t_s_u(
                                              ((safe_rshift_func_uint16_t_u_u(
                                                   l_1640, 0)) ==
                                               (((l_1640 >=
                                                  (g_5[6] && l_1640)) >
                                                 (p_26 >=
                                                  (safe_add_func_uint16_t_u_u(
                                                      (((safe_rshift_func_int8_t_s_u(
                                                            l_1640,
                                                            (g_508[1][9][0],
                                                             (((safe_sub_func_int16_t_s_s(
                                                                   ((safe_lshift_func_uint8_t_u_u(
                                                                        ((((g_208,
                                                                            (1UL &
                                                                             g_754)) >
                                                                           l_1659) <
                                                                          0UL) ||
                                                                         0xF2B8L),
                                                                        l_1640)),
                                                                    0xD990L),
                                                                   6L)) |
                                                               0x90AEL) !=
                                                              g_1625)))) &&
                                                        g_208) &&
                                                       l_1640),
                                                      p_25)))),
                                                1UL)),
                                              l_1659)),
                                          1L)),
                                      1UL)) &&
                                  0xB6F8L),
                                 p_27)),
                             l_1659),
                            2)),
                        p_25)),
                    249UL)) &&
                p_24) < (-1L)) >= g_10) &&
             0xCDL) > g_8[0][0]),
           g_227);
      for (g_830 = 0; (g_830 >= (-23));
           g_830 = safe_sub_func_int16_t_s_s(g_830, 7)) {
        l_1642 = 0L;
      }
    }

    l_1684 =
        (((((((safe_mul_func_uint8_t_u_u(
                  (safe_rshift_func_int16_t_s_u(
                      (safe_lshift_func_uint8_t_u_s(
                          ((safe_mul_func_int16_t_s_s(
                               ((safe_mul_func_int8_t_s_s(
                                    (safe_mul_func_uint16_t_u_u(
                                        (safe_lshift_func_int8_t_s_u(
                                            ((safe_rshift_func_uint16_t_u_u(
                                                 l_1640, 0)) ==
                                             (((l_1640 >= (g_5[6] && l_1640)) >
                                               (p_26 >=
                                                (safe_add_func_uint16_t_u_u(
                                                    (((safe_rshift_func_int8_t_s_u(
                                                          l_1640,
                                                          (g_508[1][9][0],
                                                           (((safe_sub_func_int16_t_s_s(
                                                                 ((safe_lshift_func_uint8_t_u_u(
                                                                      ((((g_208,
                                                                          (1UL &
                                                                           g_754)) >
                                                                         l_1659) <
                                                                        0UL) ||
                                                                       0xF2B8L),
                                                                      l_1640)),
                                                                  0xD990L),
                                                                 6L)) |
                                                             0x90AEL) !=
                                                            g_1625)))) &&
                                                      g_208) &&
                                                     l_1640),
                                                    p_25)))),
                                              1UL)),
                                            l_1659)),
                                        1L)),
                                    1UL)) &&
                                0xB6F8L),
                               p_27)),
                           l_1659),
                          2)),
                      p_25)),
                  249UL)) &&
              p_24) < (-1L)) >= g_10) &&
           0xCDL) > g_8[0][0]),
         g_227);
    for (g_830 = 0; (g_830 >= (-23));
         g_830 = safe_sub_func_int16_t_s_s(g_830, 7)) {
      l_1642 = 0L;
      for (p_24 = 21; (p_24 != (-17)); --p_24) {
        uint8_t l_1641 = 0UL;
        int32_t l_1642 = 1L;
        int32_t l_1659 = 0L;
        l_1642 =
            ((((safe_rshift_func_uint16_t_u_u(
                   (safe_rshift_func_int8_t_s_s(
                       (safe_rshift_func_uint8_t_u_u(
                           ((safe_lshift_func_int16_t_s_s(p_27, 7)) ^
                            ((((((safe_rshift_func_int8_t_s_s(
                                     (~((g_405[8] &&
                                         (safe_mod_func_uint8_t_u_u(
                                             (0xACE4L != 0xAB04L), 0x7AL))) &
                                        l_1640)),
                                     g_8[0][1])) >=
                                 (0x059FL || ((l_1641 >= 0xC7228C1EL) < g_9))) &
                                0x9EL) == p_24) ||
                              p_25),
                             g_1625)),
                           p_24)),
                       2)),
                   l_1640)) ^
               g_1195) != 0x95792450L) ^
             g_227);
        l_1659 =
            (((safe_mod_func_uint16_t_u_u(
                  (0x973613BCL > g_830),
                  (l_1640 |
                   ((safe_rshift_func_int16_t_s_s(
                        0x3FFAL,
                        (safe_lshift_func_int16_t_s_u(
                            ((g_10 ||
                              (safe_lshift_func_int16_t_s_u(
                                  ((l_1641, l_1641),
                                   (((safe_add_func_uint16_t_u_u(
                                         (safe_rshift_func_uint16_t_u_u(
                                             ((safe_mod_func_uint32_t_u_u(
                                                  ((safe_mod_func_uint32_t_u_u(
                                                       ((l_1641,
                                                         (g_9 > 0xE0315AD3L)) <=
                                                        g_1588),
                                                       l_1642)) > 0xC097L),
                                                  0x43E008B5L)) ||
                                              4294967295UL),
                                             p_25)),
                                         p_24)),
                                     0xA80F52FFL) &
                                    l_1640)),
                                  g_101))) <= l_1641),
                            2)))) > 252UL)))),
              l_1641) > g_358);
        l_1684 =
            (((((((safe_mul_func_uint8_t_u_u(
                      (safe_rshift_func_int16_t_s_u(
                          (safe_lshift_func_uint8_t_u_s(
                              ((safe_mul_func_int16_t_s_s(
                                   ((safe_mul_func_int8_t_s_s(
                                        (safe_mul_func_uint16_t_u_u(
                                            (safe_lshift_func_int8_t_s_u(
                                                ((safe_rshift_func_uint16_t_u_u(
                                                     l_1640, 0)) ==
                                                 (((l_1640 >=
                                                    (g_5[6] && l_1640)) >
                                                   (p_26 >=
                                                    (safe_add_func_uint16_t_u_u(
                                                        (((safe_rshift_func_int8_t_s_u(
                                                              l_1640,
                                                              (g_508[1][9][0],
                                                               (((safe_sub_func_int16_t_s_s(
                                                                     ((safe_lshift_func_uint8_t_u_u(
                                                                          ((((g_208,
                                                                              (1UL &
                                                                               g_754)) >
                                                                             l_1659) <
                                                                            0UL) ||
                                                                           0xF2B8L),
                                                                          l_1640)),
                                                                      0xD990L),
                                                                     6L)) |
                                                                 0x90AEL) !=
                                                                g_1625)))) &&
                                                          g_208) &&
                                                         l_1640),
                                                        p_25)))),
                                                  1UL)),
                                                l_1659)),
                                            1L)),
                                        1UL)) &&
                                    0xB6F8L),
                                   p_27)),
                               l_1659),
                              2)),
                          p_25)),
                      249UL)) &&
                  p_24) < (-1L)) >= g_10) &&
               0xCDL) > g_8[0][0]),
             g_227);
        for (g_830 = 0; (g_830 >= (-23));
             g_830 = safe_sub_func_int16_t_s_s(g_830, 7)) {
          l_1642 = 0L;
        }
      }
    }
  }
  return l_1640;
}

static int16_t func_36(uint32_t p_37, int32_t p_38) {

  {
    for (p_37 = (-13); (p_37 == 10);
         p_37 = safe_add_func_uint16_t_u_u(p_37, 5)) {
      return g_5[9];
    }
    return p_38;
  }

  return p_38;
}

static int16_t func_46(int8_t p_47, int32_t p_48, uint8_t p_49, int32_t p_50) {
  uint32_t l_54 = 0x0B2B0402L;
  int32_t l_1520 = 0x4B97A823L;
lbl_1442:
  p_50 = ((safe_add_func_int32_t_s_s(
              func_36(l_54, g_8[0][1]),
              (safe_mul_func_uint16_t_u_u(
                  (((safe_sub_func_int8_t_s_s(
                        (+((safe_sub_func_int8_t_s_s(
                               g_2,
                               (func_36(func_61(l_54,
                                                ((safe_rshift_func_uint16_t_u_u(
                                                     0x021FL,
                                                     (safe_mod_func_int32_t_s_s(
                                                         l_54, 1L)))),
                                                 ((-8L) >= g_5[6])),
                                                l_54),
                                        g_9) == p_48))) |
                           9L)),
                        p_49)) < 1UL),
                   l_54),
                  0UL)))) != 0x129EF3EDL);

  return p_47;
}

static uint32_t func_61(uint16_t p_62, uint8_t p_63, int32_t p_64) {
  int16_t l_83 = 0x81F0L;
  int32_t l_640 = 1L;
  int32_t l_661 = 0x37621463L;
  int16_t l_755 = 1L;
  int32_t l_763 = 0x91DAA854L;
  int32_t l_814 = 0xE6CF3267L;
  uint8_t l_921 = 250UL;
  uint32_t l_927 = 0x77982F67L;
  uint16_t l_974 = 65535UL;
  uint16_t l_997[3];
  int32_t l_1015 = 0x21F353DDL;
  int32_t l_1057 = 0xF3E5B39BL;
  int32_t l_1280 = (-1L);
  uint32_t l_1340 = 0UL;
  int i;

  for (i = 0; i < 3; i++)
    l_997[i] = 0xE02CL;

lbl_824:
  for (p_64 = 0; (p_64 <= 4); p_64++) {
    int32_t l_71[5][9][5] = {{{0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}},
                             {{0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}},
                             {{0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}},
                             {{0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}},
                             {{0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L},
                              {0L, 0x21011012L, 5L, 0x1DBD7CCFL, 0L}}};
    uint16_t l_686[3][7][10] = {{{65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL}},
                                {{65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL}},
                                {{65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL},
                                 {65529UL, 0x4553L, 5UL, 0x4DEDL, 65529UL, 9UL,
                                  65535UL, 0xD2A9L, 0UL, 0x4DEDL}}};
    int32_t l_724[3][1][4];
    int i, j, k;
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 1; j++) {
        for (k = 0; k < 4; k++)
          l_724[i][j][k] = 0x90B84A7FL;
      }
    }
    for (p_63 = 0; (p_63 <= 4); p_63 += 1) {
      uint8_t l_637 = 0x74L;
      int16_t l_645[2][9][5] = {{{7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}},
                                {{7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L},
                                 {7L, 0x7511L, 0x7849L, 0xEC7FL, 0xAC46L}}};
      int i, j, k;
      for (p_62 = 0; (p_62 <= 4); p_62 += 1) {
        if (g_10)
          break;
      }
      l_637 = func_72(
          ((((g_10 >= 0L) !=
             (((safe_mod_func_uint16_t_u_u(
                   (9L != p_64),
                   func_36(
                       (((safe_mod_func_uint32_t_u_u(
                             0x2FE49608L,
                             ((g_8[1][0] &
                               (func_78(
                                    g_2,
                                    ((((((((safe_mod_func_int8_t_s_s(
                                               l_83, (0x31L ^ p_62))) != 1L) |
                                          p_64) != l_71[3][5][2]) <= 65527UL),
                                       g_9),
                                      0xD621L) < l_83)),
                                p_64)),
                              g_9))),
                         p_62) >= p_64),
                       g_5[6]))) == 0x8A45DB5CL) < 0x9E86L)) ||
            0x69L),
           g_405[8]));
      l_640 = (p_63 > (safe_add_func_uint8_t_u_u(0UL, 0L)));
      if (l_637)
        continue;
      for (l_640 = 0; (l_640 <= 4); l_640 += 1) {
        int32_t l_656 = 7L;
        uint16_t l_662 = 65526UL;
        for (g_208 = 0; (g_208 <= 4); g_208 += 1) {
          int8_t l_660 = 0x91L;
          for (l_637 = 0; (l_637 <= 4); l_637 += 1) {
            int8_t l_641 = 0x31L;
            int32_t l_642 = 0x52312FD2L;
            uint16_t l_659 = 0x51F4L;
            l_641 = g_8[1][0];
            l_642 = 0xABA84B95L;
            g_580[3] = (safe_mul_func_uint8_t_u_u(
                (((l_645[1][4][3] &&
                   (l_71[0][2][4],
                    (p_62 ==
                     (safe_rshift_func_int8_t_s_s(
                         (((safe_lshift_func_int8_t_s_s(
                               ((safe_lshift_func_int16_t_s_s(
                                    (safe_sub_func_int8_t_s_s(
                                        l_656, ((safe_rshift_func_int16_t_s_s(
                                                    l_71[0][4][0],
                                                    (l_659, (-1L)))) > g_2))),
                                    14)) ||
                                (l_637 < 0UL)),
                               g_405[5])) |
                           7L) > p_64),
                         l_645[1][3][2]))))),
                  l_71[3][6][3]) >= l_660),
                p_63));
          }
          l_661 = p_62;
        }
        g_580[0] =
            (g_142[3][0] |
             (((l_656 >=
                (((((l_71[4][8][3], l_662) <
                    (safe_add_func_uint16_t_u_u(
                        (+((safe_mul_func_uint8_t_u_u(
                               l_656,
                               (safe_add_func_int32_t_s_s(
                                   ((safe_lshift_func_uint16_t_u_s(
                                        (safe_unary_minus_func_int8_t_s(p_64)),
                                        2)) &
                                    l_71[1][5][1]),
                                   (safe_rshift_func_int16_t_s_s(l_662,
                                                                 1)))))) &&
                           ((safe_sub_func_int32_t_s_s(p_63, p_62)),
                            g_580[0]))),
                        0L))),
                   p_62) &
                  p_64) ||
                 p_64)),
               g_358) &
              7L));
      }
    }
    for (g_101 = (-2); (g_101 != 53); g_101++) {
      uint32_t l_723 = 0UL;
      for (g_227 = 0; (g_227 <= 0); g_227 += 1) {
        uint32_t l_693 = 0x1280DB3CL;
        int32_t l_725[8][3] = {{9L, 9L, 0x0AE53D70L}, {9L, 9L, 0x0AE53D70L},
                               {9L, 9L, 0x0AE53D70L}, {9L, 9L, 0x0AE53D70L},
                               {9L, 9L, 0x0AE53D70L}, {9L, 9L, 0x0AE53D70L},
                               {9L, 9L, 0x0AE53D70L}, {9L, 9L, 0x0AE53D70L}};
        int i, j;
        if (g_405[(g_227 + 2)]) {
          int i, j, k;
          l_693 =
              ((safe_sub_func_uint16_t_u_u(
                   (g_508[(g_227 + 2)][(g_227 + 7)][g_227] & 0x09L),
                   (((((((safe_mod_func_int32_t_s_s(
                             (safe_sub_func_int8_t_s_s(
                                 ((p_62 == g_405[(g_227 + 2)]), g_405[5]),
                                 (((safe_rshift_func_uint8_t_u_s(
                                       l_686[2][2][8],
                                       (!(0x23D2FE6FL <
                                          ((safe_rshift_func_uint16_t_u_s(
                                               ((~(safe_mod_func_uint32_t_u_u(
                                                    ((((safe_mod_func_uint16_t_u_u(
                                                           ((((((g_580[1] ^
                                                                 ((p_64 |
                                                                   p_63) >
                                                                  g_10)),
                                                                (-9L)) ==
                                                               g_405[8]) >=
                                                              g_458[0]) <
                                                             l_640) !=
                                                            0x541A2144L),
                                                           0x35FBL)) !=
                                                       0xA8583C15L) ^
                                                      p_62) &&
                                                     (-4L)),
                                                    g_405[7]))) < 1L),
                                               5)),
                                           p_62))))) == 0x8B5A455AL),
                                  l_83))),
                             0x5634D574L)) ^
                         (-8L)) |
                        0x8BL) < p_62) < g_227) <= g_405[8]) &&
                    g_142[1][0]))) ||
               g_227);
                    l_724[2][0][3] = ((safe_add_func_int8_t_s_s(p_63, (safe_unary_minus_func_uint32_t_u((0x4E926192L | (safe_add_func_int16_t_s_s(((safe_mul_func_int8_t_s_s((0x61CDL && (5UL & (safe_add_func_int8_t_s_s((safe_add_func_int32_t_s_s((+(-2L)), (((((((((safe_sub_func_uint16_t_u_u((+(((safe_mul_func_uint16_t_u_u((safe_mul_func_int16_t_s_s(((safe_add_func_int32_t_s_s(p_62, p_62)) | g_5[6]), (safe_unary_minus_func_int8_t_s((safe_unary_minus_func_uint32_t_u((((safe_lshift_func_int8_t_s_s(((safe_sub_func_int16_t_s_s((safe_mul_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_s((0x3FA9B884L == g_508[2][4][0]), 0)) > p_62) > g_10), p_62)), g_101)) > l_693), g_142[1][1])) ^ p_64) && g_580[1]))))))), 1UL)) ^ p_62) || 6L)), 0x9512L)) > g_142[3][1]) >= g_405[(g_227 + 2)]) >= l_723) , g_508[(g_227 + 2)][(g_227 + 7)][g_227]) == 0xC5L) != l_723) , p_63) || p_64))), g_10)))), p_64)) && g_405[4]), g_508[(g_227 + 2)][(g_227 + 7)][g_227]))))))) < p_64);
        } else {
          for (g_208 = 0; (g_208 <= 4); g_208 += 1) {
            return p_64;
          }
          l_725[3][1] = 0L;
        }
        for (l_83 = 0; (l_83 >= 0); l_83 -= 1) {
          int32_t l_726 = 1L;
          g_580[1] = l_726;
          if (l_723)
            break;
          return g_101;
        }
      }
    }
    if (g_2)
      break;
  }

  for (i = 0; i < 3; i++)
    l_997[i] = 0xE02CL;

  return g_1195;
}

static int32_t func_72(int16_t p_73) {
  int16_t l_407 = 0xC69DL;
  int16_t l_420 = 0xB340L;
  uint16_t l_421 = 1UL;
  int16_t l_453 = 0xD169L;
  uint32_t l_484 = 0x3CD6C90BL;
  int32_t l_485 = 0xCACFB812L;
  uint8_t l_556[4] = {254UL, 0UL, 254UL, 0UL};
  int i;

  if ((0x3EL >
       ((safe_mul_func_uint16_t_u_u(
            1UL,
            (safe_mod_func_int32_t_s_s(
                p_73,
                ((safe_rshift_func_int16_t_s_s(
                     (p_73,
                      (l_407 ==
                       (safe_unary_minus_func_uint32_t_u((~(
                           ((((safe_lshift_func_int8_t_s_s(
                                  (0x370377B8L ||
                                   (p_73 ^
                                    ((((((1L >=
                                          (safe_rshift_func_uint8_t_u_s(
                                              (((safe_unary_minus_func_int16_t_s(
                                                    (p_73 & g_358))) !=
                                                (-1L)) <= l_420),
                                              l_420))) ^
                                         g_5[6]) == 0L) &
                                       l_420) > l_421),
                                     l_407))),
                                  l_420)) ^
                              l_420) < l_421),
                            l_421) ^
                           g_2)))))),
                     p_73)),
                 4294967286UL))))) ^
        0xD2L))) {
    uint32_t l_422[1];
    int32_t l_426 = 0xC366842CL;
    int i;
    for (i = 0; i < 1; i++)
      l_422[i] = 0UL;
    for (i = 0; i < 1; i++)
      l_422[i] = 0UL;

    for (i = 0; i < 1; i++)
      l_422[i] = 0UL;

    {
      uint32_t l_422[1];
      int32_t l_426 = 0xC366842CL;
      int i;
      for (i = 0; i < 1; i++)
        l_422[i] = 0UL;
      l_426 = (((p_73 &&
                 ((((p_73 & l_422[0]) & 0x8077E666L) <
                   (safe_rshift_func_int16_t_s_s(
                       ((p_73 &&
                         (((((l_420 >= g_208),
                             (+(p_73 ^ ((safe_unary_minus_func_int16_t_s(4L)) |
                                        8L)))) &
                            8L) &&
                           0x6DL) <= p_73)),
                        0xEA8FL),
                       p_73))) &
                  l_407)),
                0x6AL) &
               p_73);
        l_426 = ((((0x512EL & (((((p_73 > (((((safe_rshift_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(g_10, (safe_mod_func_uint8_t_u_u((safe_mod_func_int32_t_s_s((safe_mod_func_uint16_t_u_u(((safe_mul_func_uint16_t_u_u((!((safe_mul_func_uint8_t_u_u(((0xE82BF19AL & (safe_add_func_uint16_t_u_u(((((((((((((((safe_add_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u(((l_422[0] , (~0x7A72L)) && l_420), 5)) != ((safe_mod_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(((g_406 > (safe_add_func_uint32_t_u_u(((1L & 1L) < (-3L)), l_407))) <= l_422[0]), p_73)) < g_405[0]), 0x6A7EL)) == g_101)), p_73)) || p_73) <= 0UL) >= 0x3B3CL) < l_426) <= p_73) && p_73) > l_426) | g_208) & l_422[0]) == p_73) & 1UL) == l_426) , 4UL), l_453))) == 0xDBCAL), g_5[6])) & p_73)), l_420)) , 0x52DDL), l_426)), 0xBC1A0054L)), g_2)))), 3)) , l_421) && 0x99L) && l_407) < g_5[6])) > g_405[5]) ^ p_73) , p_73) | (-2L))) != g_405[8]) && l_420) , p_73);
        g_458[0] =
            (((safe_rshift_func_uint8_t_u_s(
                  ((p_73 != l_407) &
                   (((safe_add_func_int8_t_s_s(
                         6L,
                         ((p_73 & (l_422[0] < (p_73 || (((~l_422[0]) | 8L) &&
                                                        (l_407, l_421))))) ==
                          g_358))) <= p_73) != l_422[0])),
                  g_227)) != 65532UL) > (-1L));
    }

  } else {
    uint32_t l_494 = 0UL;
    int16_t l_595[1];
    int32_t l_597 = 0x1951CAB3L;
    int i;
    for (i = 0; i < 1; i++)
      ;

    {
      uint32_t l_422[1];
      int32_t l_426 = 0xC366842CL;
      int i;
      for (i = 0; i < 1; i++)
        l_422[i] = 0UL;
      l_426 = (((p_73 &&
                 ((((p_73 & l_422[0]) & 0x8077E666L) <
                   (safe_rshift_func_int16_t_s_s(
                       ((p_73 &&
                         (((((l_420 >= g_208),
                             (+(p_73 ^ ((safe_unary_minus_func_int16_t_s(4L)) |
                                        8L)))) &
                            8L) &&
                           0x6DL) <= p_73)),
                        0xEA8FL),
                       p_73))) &
                  l_407)),
                0x6AL) &
               p_73);
        l_426 = ((((0x512EL & (((((p_73 > (((((safe_rshift_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(g_10, (safe_mod_func_uint8_t_u_u((safe_mod_func_int32_t_s_s((safe_mod_func_uint16_t_u_u(((safe_mul_func_uint16_t_u_u((!((safe_mul_func_uint8_t_u_u(((0xE82BF19AL & (safe_add_func_uint16_t_u_u(((((((((((((((safe_add_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u(((l_422[0] , (~0x7A72L)) && l_420), 5)) != ((safe_mod_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(((g_406 > (safe_add_func_uint32_t_u_u(((1L & 1L) < (-3L)), l_407))) <= l_422[0]), p_73)) < g_405[0]), 0x6A7EL)) == g_101)), p_73)) || p_73) <= 0UL) >= 0x3B3CL) < l_426) <= p_73) && p_73) > l_426) | g_208) & l_422[0]) == p_73) & 1UL) == l_426) , 4UL), l_453))) == 0xDBCAL), g_5[6])) & p_73)), l_420)) , 0x52DDL), l_426)), 0xBC1A0054L)), g_2)))), 3)) , l_421) && 0x99L) && l_407) < g_5[6])) > g_405[5]) ^ p_73) , p_73) | (-2L))) != g_405[8]) && l_420) , p_73);
        g_458[0] =
            (((safe_rshift_func_uint8_t_u_s(
                  ((p_73 != l_407) &
                   (((safe_add_func_int8_t_s_s(
                         6L,
                         ((p_73 & (l_422[0] < (p_73 || (((~l_422[0]) | 8L) &&
                                                        (l_407, l_421))))) ==
                          g_358))) <= p_73) != l_422[0])),
                  g_227)) != 65532UL) > (-1L));
    }

    for (l_421 = 0; (l_421 <= 8); l_421 += 1) {
      int i;

      for (i = 0; i < 1; i++)
        l_595[i] = 6L;

      for (l_453 = 0; (l_453 >= 0); l_453 -= 1) {
        int i;
        l_494 = (g_458[l_453],
                 ((p_73 <= g_405[l_421]),
                  (((safe_mod_func_int8_t_s_s(
                        g_5[6],
                        (safe_mul_func_int16_t_s_s(
                            g_5[6],
                            (safe_mod_func_uint8_t_u_u(
                                (safe_rshift_func_int8_t_s_u(
                                    ((g_2 <= ((p_73 || (0x52L <= g_142[3][0])) >
                                              g_458[l_453])) ^
                                     g_8[0][1]),
                                    2)),
                                8L)))))) ^
                    l_484),
                   g_10)));
      }
    }
    for (l_421 = 0; (l_421 <= 8); l_421 += 1) {
      int i;
            l_485 = (g_405[l_421] == ((safe_sub_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((g_10 >= ((safe_add_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(0xD697L, (safe_sub_func_int32_t_s_s(((safe_unary_minus_func_uint16_t_u((((safe_add_func_int8_t_s_s((safe_add_func_int8_t_s_s((((((safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_s(g_2, 15)), (((g_5[2] != ((((safe_add_func_int32_t_s_s(((g_405[l_421] <= g_406) == ((((safe_sub_func_uint32_t_u_u(((!(1L | g_405[l_421])) > p_73), g_10)) && 0x95L) <= g_458[0]) >= p_73)), 1UL)) || g_406) | p_73) >= 5L)) || g_2) < 0x13L))), g_358)) && l_407) >= 0L) | g_208) , g_5[8]), l_484)), p_73)) , g_405[l_421]) >= 0x9AL))) , p_73), 0x89E1DE85L)))), 0x229333FCL)) <= g_10)), 2)) ^ p_73) ^ g_405[8]) || g_8[0][1]) < g_458[0]), g_405[l_421])) , p_73));
            for (l_453 = 0; (l_453 >= 0); l_453 -= 1) {
              int i;
              l_494 = (g_458[l_453],
                       ((p_73 <= g_405[l_421]),
                        (((safe_mod_func_int8_t_s_s(
                              g_5[6],
                              (safe_mul_func_int16_t_s_s(
                                  g_5[6],
                                  (safe_mod_func_uint8_t_u_u(
                                      (safe_rshift_func_int8_t_s_u(
                                          ((g_2 <=
                                            ((p_73 || (0x52L <= g_142[3][0])) >
                                             g_458[l_453])) ^
                                           g_8[0][1]),
                                          2)),
                                      8L)))))) ^
                          l_484),
                         g_10)));
            }
    }

    for (l_421 = 0; (l_421 <= 8); l_421 += 1) {
      int i;
            l_485 = (g_405[l_421] == ((safe_sub_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((g_10 >= ((safe_add_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(0xD697L, (safe_sub_func_int32_t_s_s(((safe_unary_minus_func_uint16_t_u((((safe_add_func_int8_t_s_s((safe_add_func_int8_t_s_s((((((safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_s(g_2, 15)), (((g_5[2] != ((((safe_add_func_int32_t_s_s(((g_405[l_421] <= g_406) == ((((safe_sub_func_uint32_t_u_u(((!(1L | g_405[l_421])) > p_73), g_10)) && 0x95L) <= g_458[0]) >= p_73)), 1UL)) || g_406) | p_73) >= 5L)) || g_2) < 0x13L))), g_358)) && l_407) >= 0L) | g_208) , g_5[8]), l_484)), p_73)) , g_405[l_421]) >= 0x9AL))) , p_73), 0x89E1DE85L)))), 0x229333FCL)) <= g_10)), 2)) ^ p_73) ^ g_405[8]) || g_8[0][1]) < g_458[0]), g_405[l_421])) , p_73));
            for (l_453 = 0; (l_453 >= 0); l_453 -= 1) {
              int i;
              l_494 = (g_458[l_453],
                       ((p_73 <= g_405[l_421]),
                        (((safe_mod_func_int8_t_s_s(
                              g_5[6],
                              (safe_mul_func_int16_t_s_s(
                                  g_5[6],
                                  (safe_mod_func_uint8_t_u_u(
                                      (safe_rshift_func_int8_t_s_u(
                                          ((g_2 <=
                                            ((p_73 || (0x52L <= g_142[3][0])) >
                                             g_458[l_453])) ^
                                           g_8[0][1]),
                                          2)),
                                      8L)))))) ^
                          l_484),
                         g_10)));
            }
    }
  }
  for (g_227 = (-2); (g_227 > 24); g_227++) {
    int16_t l_616 = (-1L);
    uint16_t l_628 = 1UL;

    l_628 = (safe_mul_func_int8_t_s_s(
        (((safe_add_func_uint16_t_u_u(l_616, (-1L))) >
          (safe_sub_func_uint16_t_u_u(
              (((safe_lshift_func_int8_t_s_u(
                    (((((safe_unary_minus_func_int8_t_s(g_142[2][2])) <=
                        ((safe_lshift_func_int8_t_s_u(
                             (((((((safe_rshift_func_uint16_t_u_s(
                                       0xCD89L,
                                       ((safe_sub_func_uint32_t_u_u(
                                            ((0x401CDDD9L && g_580[2]) || 1L),
                                            p_73)) >= p_73))),
                                   p_73) >= 0x85L) >= 0xA1A1L) ^
                                0xD50A5EE1L),
                               g_580[1]) &&
                              p_73),
                             5)),
                         g_9)) ^
                       p_73) &&
                      g_458[0]) > l_484),
                    g_580[1])) &&
                0x6DL) >= 0x5CD8L),
              p_73))) >= g_142[4][3]),
        g_101));
  }

  l_485 = ((((g_405[8] | (0x292C3D8EL && g_2)) && (l_485 || g_520[5])),
            (l_556[2] <=
             (l_407 !=
              (+(((safe_add_func_uint32_t_u_u(
                      (safe_mod_func_int32_t_s_s(
                          (safe_sub_func_uint32_t_u_u(9UL, (p_73, g_8[0][1]))),
                          g_520[1])),
                      p_73)) ^
                  252UL) > (-1L)))))) == p_73);

  return p_73;
}

static uint32_t func_78(int8_t p_79, int16_t p_80) {
  int16_t l_99[3][7] = {{0xE080L, 0x4F5AL, 0L, 0x9881L, 0x718AL, 0L, 0x718AL},
                        {0xE080L, 0x4F5AL, 0L, 0x9881L, 0x718AL, 0L, 0x718AL},
                        {0xE080L, 0x4F5AL, 0L, 0x9881L, 0x718AL, 0L, 0x718AL}};
  uint32_t l_100 = 4294967295UL;
  int32_t l_139 = (-8L);
  uint8_t l_149 = 0x63L;
  uint32_t l_255 = 0UL;
  int32_t l_356 = 0xB94147C4L;
  int i, j;
lbl_110:
  if (g_5[6]) {
    uint8_t l_92[2];
    int i;
    for (i = 0; i < 2; i++)
      l_92[i] = 246UL;
    g_101 = (safe_mod_func_int16_t_s_s(
        (g_5[6] <= p_79),
        func_36((((safe_rshift_func_int8_t_s_s(
                      ((safe_mod_func_uint8_t_u_u(
                           (safe_mul_func_uint16_t_u_u(p_80, l_92[1])), p_80)) <
                       ((safe_lshift_func_int16_t_s_u((g_5[6] == l_92[1]), 13)),
                        0x10L)),
                      ((safe_sub_func_uint32_t_u_u(
                           (safe_rshift_func_int8_t_s_s(l_99[0][5], g_5[6])),
                           p_80)) >= (-9L)))) &&
                  l_100) < g_5[6]),
                l_92[1])));
  } else {
    return g_5[3];
  }
lbl_272:
  for (p_80 = 4; (p_80 == 22); p_80 = safe_add_func_uint32_t_u_u(p_80, 2)) {
    uint8_t l_117 = 7UL;
    int32_t l_144 = (-1L);
    uint8_t l_192 = 0xC2L;
    if ((safe_mul_func_uint16_t_u_u(
            (0x20L ||
             (p_79 >=
              ((-10L) ^
               func_36((((g_5[7] || func_36((safe_add_func_uint32_t_u_u(
                                                (p_79 == 0x62DAC39FL), p_79)),
                                            g_8[0][0])) != 0x83L),
                        0xD6BEAEC5L),
                       g_2)))),
            0xA390L))) {
      for (g_101 = 9; (g_101 >= 22); ++g_101) {
        return l_100;
      }
    } else {
      int8_t l_138 = 0x75L;
      if (g_101)
        goto lbl_110;
      l_144 =
          ((p_79 ==
            (safe_mod_func_int16_t_s_s(
                (safe_sub_func_uint16_t_u_u(
                    (safe_mod_func_int8_t_s_s(
                        ((2UL == func_36(g_8[2][0], l_117)) |
                         (func_118(
                              ((((safe_mul_func_int16_t_s_s(
                                     (~1L),
                                     (((safe_rshift_func_uint8_t_u_u(
                                           (safe_mul_func_uint8_t_u_u(
                                               g_9,
                                               ((p_79 ^
                                                 (safe_add_func_int8_t_s_s(
                                                     (safe_sub_func_uint32_t_u_u(
                                                         (safe_mul_func_uint16_t_u_u(
                                                             ((((((safe_mul_func_int8_t_s_s(
                                                                      p_80,
                                                                      0x2FL)),
                                                                  l_117) |
                                                                 0xCAL) |
                                                                l_138) <= g_9),
                                                              l_100),
                                                             p_80)),
                                                         g_2)),
                                                     g_9))),
                                                0x86L))),
                                           0)),
                                       g_5[6]) == l_117))) >= p_79) ^
                                l_99[0][5]) > l_138),
                              g_10, g_5[5], g_5[6], l_139) ||
                          p_80)),
                        (-1L))),
                    0L)),
                0x9C82L))),
           0x5A8FD6DDL);
      for (l_139 = 0; (l_139 == 15);
           l_139 = safe_add_func_int32_t_s_s(l_139, 1)) {
        uint32_t l_193 = 0xD12158B1L;
        int32_t l_254[8][4][4] = {{{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}},
                                  {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}},
                                  {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}},
                                  {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}},
                                  {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}},
                                  {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}},
                                  {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}},
                                  {{0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L},
                                   {0xEFDAD2A3L, (-1L), 0x5D44334FL, 0L}}};
        int i, j, k;
        for (g_101 = (-17); (g_101 < 8);
             g_101 = safe_add_func_int16_t_s_s(g_101, 4)) {
          int8_t l_166 = 0x86L;
          uint8_t l_167 = 0xC6L;
          uint16_t l_168[6];
          int i;
          for (i = 0; i < 6; i++)
            l_168[i] = 0x379BL;
          if ((l_149 &&
               (safe_mod_func_uint8_t_u_u(
                   ((safe_sub_func_uint32_t_u_u(
                        ((safe_rshift_func_int16_t_s_u(
                             g_2,
                             (((safe_rshift_func_int16_t_s_s(
                                   (((((safe_add_func_int8_t_s_s(
                                           (((safe_mod_func_int16_t_s_s(
                                                 ((safe_mul_func_int16_t_s_s(
                                                      (safe_mul_func_int16_t_s_s(
                                                          (g_8[1][0] &
                                                           (!l_166)),
                                                          (-6L))),
                                                      l_117)) ^
                                                  (((l_167,
                                                     (l_168[1],
                                                      ((l_99[1][4] && p_80),
                                                       g_10))),
                                                    1UL) <= p_80)),
                                                 3UL)) >= 0xAC6AL),
                                            g_142[2][3]),
                                           0x2FL)) >= l_166) ^
                                      p_79) &&
                                     0x0DL),
                                    p_79),
                                   l_168[1])),
                               1L) >= 0xC1D1B066L))),
                         g_101),
                        l_144)) < p_80),
                   l_168[1])))) {
            int32_t l_187 = 0L;
            l_144 = (safe_mul_func_uint8_t_u_u(
                (((((((((safe_sub_func_uint8_t_u_u(
                            (((safe_add_func_int16_t_s_s(
                                  ((g_5[3] ^
                                    ((safe_mod_func_uint32_t_u_u(
                                         (((((safe_add_func_uint16_t_u_u(
                                                 (safe_mod_func_int8_t_s_s(
                                                     p_79,
                                                     (((65531UL <= p_80) ||
                                                       g_5[6]),
                                                      ((safe_rshift_func_int16_t_s_u(
                                                           ((safe_lshift_func_uint16_t_u_u(
                                                                g_5[6], 14)) ^
                                                            (safe_sub_func_int32_t_s_s(
                                                                (l_187 &&
                                                                 (safe_lshift_func_uint8_t_u_u(
                                                                     p_80,
                                                                     ((safe_sub_func_int8_t_s_s(
                                                                          (((p_79,
                                                                             l_166) &
                                                                            p_80) &
                                                                           l_144),
                                                                          l_192)) ||
                                                                      l_144)))),
                                                                g_10))),
                                                           l_168[5])),
                                                       l_193)))),
                                                 g_2)) < g_2) |
                                            0xFEL) < 0xE21D6552L) > g_10),
                                         g_10)),
                                     p_80)) ||
                                   g_142[1][2]),
                                  p_79)) < p_80),
                             g_142[1][4]),
                            0x32L)) ^
                        0L),
                       0x5B5EL) == g_9) < l_138) == 0xD71703F9L) |
                   l_193),
                  p_79),
                 5UL),
                p_79));
          } else {
            g_208 =
                ((((+(safe_lshift_func_uint8_t_u_s(
                       (((p_79 == 0x2EL) !=
                         (p_79 <=
                          ((((((~g_2) &&
                               ((+((safe_lshift_func_uint16_t_u_u(
                                       0xEE89L,
                                       (safe_mul_func_int16_t_s_s(
                                           (((((l_99[0][5] ^
                                                (((safe_mul_func_uint16_t_u_u(
                                                      (8UL &
                                                       (safe_mul_func_int16_t_s_s(
                                                           (g_5[6] | g_8[0][0]),
                                                           0xCE8CL))),
                                                      1L)) ^
                                                  g_5[1]) != l_149)) <=
                                               (-1L)) ||
                                              g_5[6]) > g_10) ||
                                            1L),
                                           l_168[1])))) &&
                                   g_5[6])) <= g_9)),
                              255UL) <= p_79) >= g_5[5]) >= 7UL))) > l_167),
                       p_79))) >= p_79),
                  (-2L)) != p_80);
          }
        }
        g_227 = ((safe_add_func_int8_t_s_s(
                     (l_117, g_9),
                     (safe_lshift_func_int16_t_s_u(
                         (+(safe_add_func_uint16_t_u_u(
                             ((safe_lshift_func_uint16_t_u_u(p_80, 2)) &
                              (safe_mul_func_uint16_t_u_u(
                                  (((safe_sub_func_int8_t_s_s(p_79, 0xD1L)),
                                    (safe_add_func_int32_t_s_s(
                                        (safe_rshift_func_int16_t_s_u(2L, 2)),
                                        l_192))) !=
                                   (0xEFCB1569L &&
                                    (safe_mul_func_uint8_t_u_u(
                                        ((l_193 >= 0x8CD2L), 0xA4L), g_5[6])))),
                                  0xA05CL))),
                             g_208))),
                         6)))),
                 g_142[3][4]);
        l_254[5][2][2] =
            ((safe_mul_func_uint16_t_u_u(
                 l_138,
                 (g_5[1] |
                  ((safe_rshift_func_int8_t_s_s(l_100, 4)) |
                   (safe_mul_func_uint16_t_u_u(
                       ((safe_rshift_func_uint8_t_u_s(
                            (~(safe_mod_func_int8_t_s_s(
                                ((safe_add_func_int32_t_s_s(
                                     l_138,
                                     (safe_mod_func_uint16_t_u_u(
                                         (safe_rshift_func_int16_t_s_u(
                                             (~(safe_lshift_func_uint8_t_u_s(
                                                 ((p_79 ==
                                                   (((safe_mul_func_int16_t_s_s(
                                                         (((+(l_193, p_80)) <=
                                                           (safe_lshift_func_uint8_t_u_s(
                                                               ((safe_mul_func_int8_t_s_s(
                                                                    l_149,
                                                                    ((safe_rshift_func_int16_t_s_u(
                                                                         l_193,
                                                                         6)) >
                                                                     1L))),
                                                                l_193),
                                                               l_138))) &&
                                                          p_79),
                                                         l_138)) <= p_79) &&
                                                    l_193)) < p_80),
                                                 4))),
                                             6)),
                                         l_193)))) &&
                                 p_80),
                                l_117))),
                            3)) ^
                        p_79),
                       0xF83BL)))))) ||
             g_8[1][0]);
      }
    }
    if (l_255)
      continue;
  }

  for (l_100 = 1; (l_100 <= 4); l_100 += 1) {
    uint8_t l_270[3];
    int32_t l_271 = 0xC06C30A7L;
    int32_t l_393 = 0xA6E4B284L;
    int i;
    for (i = 0; i < 3; i++)
      l_270[i] = 255UL;
    l_271 = (safe_sub_func_int32_t_s_s(
        (safe_lshift_func_uint8_t_u_u(
            (((((safe_sub_func_uint8_t_u_u((g_10 == p_80), 3L)) > p_79) <
               l_149) <=
              ((safe_add_func_int32_t_s_s(
                   0x9C167B5BL,
                   (safe_add_func_int8_t_s_s(
                       (safe_mul_func_int8_t_s_s(
                           0x59L,
                           (safe_add_func_int32_t_s_s(
                               (((1L < p_80) != p_80) != g_5[6]), l_255)))),
                       0x48L)))) != 0xC8L)) > l_270[0]),
            l_99[2][1])),
        5UL));
    if (l_139)
      goto lbl_272;
        l_139 = ((safe_mul_func_uint8_t_u_u((g_5[5] <= ((safe_add_func_int32_t_s_s((((((safe_mod_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_u(((((((((safe_mul_func_uint8_t_u_u(p_80, (g_8[0][0] && ((safe_rshift_func_uint8_t_u_u(0x95L, ((p_80 & (safe_mul_func_uint16_t_u_u((~(((((safe_add_func_int8_t_s_s(p_80, 0xE6L)) == ((safe_sub_func_uint32_t_u_u((safe_sub_func_int32_t_s_s(((safe_rshift_func_uint16_t_u_u((safe_mul_func_int16_t_s_s(((((safe_sub_func_int32_t_s_s((l_99[0][6] | (((1UL == (-1L)) & g_5[6]) < l_100)), l_255)) >= l_99[2][4]) == 1L) & 0x5AC83A63L), p_79)), l_149)) <= 0L), l_139)), 0xC67E8D82L)) || p_79)) , l_139) <= p_80) && 255UL)), (-1L)))) || 0L))) , p_80)))) ^ g_227) , g_142[0][4]) == 0UL) & 0x2B3F61FCL) || 4294967286UL) && 1UL) & 1UL), 0)) , 0x36697B6FL), 0xCBE982E7L)) <= g_142[3][4]) < l_270[2]) > l_270[1]) , g_5[7]), p_79)) != g_227)), p_80)) <= l_99[0][5]);
        for (l_149 = 1; (l_149 <= 4); l_149 += 1) {
          int32_t l_333[4][3][7] = {
              {{0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L},
               {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L},
               {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}},
              {{0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L},
               {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L},
               {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}},
              {{0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L},
               {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L},
               {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}},
              {{0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L},
               {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L},
               {0L, 1L, 1L, (-1L), 0x70DDCE62L, (-8L), 0x5FE1D2F5L}}};
          int i, j, k;
          for (l_139 = 4; (l_139 >= 0); l_139 -= 1) {
            int32_t l_334[3][8][6] = {
                {{6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}},
                {{6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}},
                {{6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL},
                 {6L, 0xDAD46290L, 0xDE7840DFL, 0xE0E8DCDAL, 0L, 0xFC60A11CL}}};
            int32_t l_335 = (-8L);
            int i, j, k;
            l_335 = (safe_mod_func_int8_t_s_s(
                l_99[2][2],
                (safe_mul_func_int16_t_s_s(
                    ((safe_mul_func_int8_t_s_s(
                         l_270[0],
                         (safe_mul_func_int16_t_s_s(
                             (7UL != p_79),
                             (((((safe_rshift_func_uint16_t_u_u(
                                     (safe_sub_func_uint16_t_u_u(
                                         (safe_mod_func_uint32_t_u_u(
                                             (safe_rshift_func_int8_t_s_s(0x6BL,
                                                                          0)),
                                             (safe_mod_func_uint8_t_u_u(
                                                 (safe_add_func_int32_t_s_s(
                                                     (p_79,
                                                      (safe_mul_func_uint8_t_u_u(
                                                          (safe_mul_func_uint8_t_u_u(
                                                              ((safe_add_func_uint8_t_u_u(
                                                                   (safe_lshift_func_uint8_t_u_s(
                                                                       (safe_mul_func_uint8_t_u_u(
                                                                           ((safe_lshift_func_uint16_t_u_s(
                                                                                (p_79 ||
                                                                                 g_2),
                                                                                ((safe_add_func_int32_t_s_s(
                                                                                     0xA10EE6A9L,
                                                                                     g_8[2]
                                                                                        [0])) ^
                                                                                 g_208))) >
                                                                            (-3L)),
                                                                           p_80)),
                                                                       p_79)),
                                                                   g_2)) <=
                                                               l_333[3][1][4]),
                                                              l_334[1][5][1])),
                                                          l_270[0]))),
                                                     g_142[0][0])),
                                                 p_80)))),
                                         0x576EL)),
                                     6)) &&
                                 g_2) ^
                                0x5DL) ||
                               p_80) != 0x130623DAL))))) == p_79),
                    0x85D1L))));
            l_356 = (safe_rshift_func_int8_t_s_s(
                (safe_sub_func_int8_t_s_s(
                    (g_5[6] |
                     (g_208,
                      (safe_sub_func_uint8_t_u_u(
                          (safe_mod_func_uint16_t_u_u(
                              (l_333[2][1][5] <=
                               (safe_sub_func_int32_t_s_s(
                                   0x03310008L,
                                   (safe_mod_func_uint16_t_u_u(
                                       ((safe_mod_func_uint32_t_u_u(
                                            0x41DCC979L,
                                            (((((l_334[1][5][1] <=
                                                 (+0x1C9BFA93L)) ==
                                                (((((safe_sub_func_uint16_t_u_u(
                                                        p_79,
                                                        ((safe_rshift_func_uint8_t_u_s(
                                                             (safe_lshift_func_int16_t_s_u(
                                                                 p_79, 10)),
                                                             g_208)) <=
                                                         p_80))) <=
                                                    0x97F4BBE4L),
                                                   0x60007889L) !=
                                                  l_333[3][1][4]) ==
                                                 l_333[3][2][4])) >
                                               0x1D0DC95DL) > g_9) ||
                                             p_79))),
                                        p_80),
                                       g_208))))),
                              l_333[3][1][4])),
                          g_9)))),
                    l_333[3][1][4])),
                2));
          }
        }
        for (l_271 = 4; (l_271 >= 1); l_271 -= 1) {
          int16_t l_357[1];
          int32_t l_364[5] = {0x8076C985L, 0xBCB5D35EL, 0x8076C985L,
                              0xBCB5D35EL, 0x8076C985L};
          int i;
          for (i = 0; i < 1; i++)
            l_357[i] = 1L;
          g_358 = l_357[0];
          l_364[0] =
              ((l_139 ^
                (((0x1BL <
                   (g_101,
                    ((safe_rshift_func_uint8_t_u_s(
                         l_270[1],
                         (g_101 & (!(g_227, ((safe_unary_minus_func_uint32_t_u(
                                                 g_208)) >= g_5[5])))))) &&
                     (safe_rshift_func_uint8_t_u_s(0x9CL, 2))))) > 0x571DL) !=
                 l_357[0])),
               0x64FC777FL);
          for (l_149 = 1; (l_149 <= 4); l_149 += 1) {
            uint32_t l_392 = 0UL;
            for (g_358 = 4; (g_358 >= 1); g_358 -= 1) {
              int16_t l_391 = 0x7A41L;
              uint32_t l_404 = 1UL;
                    l_393 = (((((safe_sub_func_uint16_t_u_u((((((safe_add_func_uint16_t_u_u((p_79 > ((safe_add_func_int32_t_s_s(p_80, (safe_mul_func_int8_t_s_s(l_271, (((((((g_10 || (safe_sub_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((safe_sub_func_int32_t_s_s(((safe_mul_func_int8_t_s_s(((0x51BAL && g_9) == ((((safe_mul_func_uint16_t_u_u((safe_mul_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((((safe_add_func_int32_t_s_s((l_270[0] ^ (safe_lshift_func_int16_t_s_u(((l_357[0] ^ 0xD1EE3892L) , 3L), 2))), 4294967292UL)) > p_80) & g_2), p_80)), 4UL)), g_9)) | 65535UL) ^ g_9) == 0xEBL)), p_79)) <= p_80), l_391)), l_364[0])), l_271))) >= 0x9A8E6CA8L) <= g_10) || l_270[0]) || 0x18BEC9C2L) != l_149) | 0x5891L))))) == g_208)), 0xE40EL)) , p_79) , l_391) && p_80) & p_80), 65535UL)) & l_391) , p_79) , (-1L)) ^ l_392);
                    g_405[8] = (safe_mul_func_int8_t_s_s(
                        (p_79 ==
                         ((((safe_add_func_uint8_t_u_u(
                                (l_270[0] |
                                 (248UL ==
                                  ((safe_sub_func_int8_t_s_s(
                                       l_99[0][5],
                                       (p_79 >=
                                        (safe_sub_func_int16_t_s_s(
                                            g_2,
                                            ((safe_lshift_func_uint16_t_u_u(
                                                 (p_80 |
                                                  (((((p_79 |
                                                       ((p_80 & 0xBC50E1AEL) &
                                                        0x79D4BE2AL)) ^
                                                      p_79) >= l_270[0]) !=
                                                    0xAF85L) >= 0x6AL)),
                                                 p_80)) &
                                             l_357[0])))))) |
                                   (-1L)))),
                                l_404)) ^
                            1UL),
                           l_356) < 0L)),
                        p_79));
            }
          }
          g_406 = g_142[2][1];
        }
  }

  return g_405[8];
}

static uint8_t func_118(uint8_t p_119, int32_t p_120, int16_t p_121,
                        uint16_t p_122, int32_t p_123) {
  int32_t l_143 = 0L;

  {
    int32_t l_143 = 0L;
    for (p_119 = (-1); (p_119 < 45);
         p_119 = safe_add_func_int8_t_s_s(p_119, 1)) {
      for (g_101 = 0; (g_101 <= 4); g_101 += 1) {
        p_123 = 0L;
      }
    }
    return l_143;
  }

  return l_143;
}

int main(void) {
  int i, j, k;
  int print_hash_value = 0;
  crc32_gentab();
  func_1();
  transparent_crc(g_2, "g_2", print_hash_value);
  for (i = 0; i < 10; i++) {
    transparent_crc(g_5[i], "g_5[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 2; j++) {
      transparent_crc(g_8[i][j], "g_8[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_9, "g_9", print_hash_value);
  transparent_crc(g_10, "g_10", print_hash_value);
  transparent_crc(g_101, "g_101", print_hash_value);
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      transparent_crc(g_142[i][j], "g_142[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_208, "g_208", print_hash_value);
  transparent_crc(g_227, "g_227", print_hash_value);
  transparent_crc(g_358, "g_358", print_hash_value);
  for (i = 0; i < 9; i++) {
    transparent_crc(g_405[i], "g_405[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_406, "g_406", print_hash_value);
  for (i = 0; i < 1; i++) {
    transparent_crc(g_458[i], "g_458[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 10; j++) {
      for (k = 0; k < 1; k++) {
        transparent_crc(g_508[i][j][k], "g_508[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  for (i = 0; i < 9; i++) {
    transparent_crc(g_520[i], "g_520[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  for (i = 0; i < 4; i++) {
    transparent_crc(g_580[i], "g_580[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_754, "g_754", print_hash_value);
  transparent_crc(g_830, "g_830", print_hash_value);
  transparent_crc(g_1165, "g_1165", print_hash_value);
  transparent_crc(g_1195, "g_1195", print_hash_value);
  transparent_crc(g_1588, "g_1588", print_hash_value);
  transparent_crc(g_1625, "g_1625", print_hash_value);
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}

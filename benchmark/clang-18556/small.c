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

      (si == (-9223372036854775807L -1)) ? ((si)) :

                        -si;
}

static int64_t(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((9223372036854775807L) - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < ((-9223372036854775807L -1) - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int64_t(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~(9223372036854775807L)))) - si2) ^ si2)) < 0)
          ? ((si1))
          :

          (si1 - si2);
}

static int64_t(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((9223372036854775807L) / si2))) ||
       ((si1 > 0) && (si2 <= 0) && (si2 < ((-9223372036854775807L -1) / si1))) ||
       ((si1 <= 0) && (si2 > 0) && (si1 < ((-9223372036854775807L -1) / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((9223372036854775807L) / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int64_t(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      ((si2 == 0) || ((si1 == (-9223372036854775807L -1)) && (si2 == (-1)))) ? ((si1)) :

                                                            (si1 % si2);
}

static int64_t(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      ((si2 == 0) || ((si1 == (-9223372036854775807L -1)) && (si2 == (-1)))) ? ((si1)) :

                                                            (si1 / si2);
}

static int64_t(safe_lshift_func_int64_t_s_s)(int64_t left, int right) {

  return

      ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
       (left > ((9223372036854775807L) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static int64_t(safe_lshift_func_int64_t_s_u)(int64_t left, unsigned int right) {

  return

      ((left < 0) || (((unsigned int)right) >= 32) ||
       (left > ((9223372036854775807L) >> ((unsigned int)right))))
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
       (left > ((18446744073709551615UL) >> ((int)right))))
          ? ((left))
          :

          (left << ((int)right));
}

static uint64_t(safe_lshift_func_uint64_t_u_u)(uint64_t left,
                                               unsigned int right) {

  return

      ((((unsigned int)right) >= 32) ||
       (left > ((18446744073709551615UL) >> ((unsigned int)right))))
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

static int32_t g_7 = 0x70CD5099L;
static int32_t *g_10 = &g_7;
static uint32_t g_20 = 18446744073709551614UL;
static int16_t g_55 = 0x2A25L;
static int32_t g_72 = 0xD74ECB9AL;
static uint16_t g_114[5] = {0xB00EL, 0xB00EL, 0xB00EL, 0xB00EL, 0xB00EL};

static int32_t g_115 = 0x95FD5604L;
static int32_t **g_144 = (void *)0;
static int32_t ***g_143 = &g_144;
static int32_t g_171 = 1L;
static int32_t g_483 = 0x6D6E9D4CL;
static int8_t g_496[7][6] = {{(-1L), (-4L), (-1L), (-1L), (-1L), (-4L)},
                             {(-1L), (-4L), (-1L), (-1L), (-1L), (-4L)},
                             {(-1L), (-4L), (-1L), (-1L), (-1L), (-4L)},
                             {(-1L), (-4L), (-1L), (-1L), (-1L), (-4L)},
                             {(-1L), (-4L), (-1L), (-1L), (-1L), (-4L)},
                             {(-1L), (-4L), (-1L), (-1L), (-1L), (-4L)},
                             {(-1L), (-4L), (-1L), (-1L), (-1L), (-4L)}};
static int32_t *g_677[8][1][8] = {
    {{&g_483, &g_483, &g_483, (void *)0, &g_171, &g_7, &g_483, &g_483}},
    {{&g_483, &g_483, &g_483, (void *)0, &g_171, &g_7, &g_483, &g_483}},
    {{&g_483, &g_483, &g_483, (void *)0, &g_171, &g_7, &g_483, &g_483}},
    {{&g_483, &g_483, &g_483, (void *)0, &g_171, &g_7, &g_483, &g_483}},
    {{&g_483, &g_483, &g_483, (void *)0, &g_171, &g_7, &g_483, &g_483}},
    {{&g_483, &g_483, &g_483, (void *)0, &g_171, &g_7, &g_483, &g_483}},
    {{&g_483, &g_483, &g_483, (void *)0, &g_171, &g_7, &g_483, &g_483}},
    {{&g_483, &g_483, &g_483, (void *)0, &g_171, &g_7, &g_483, &g_483}}};
static int32_t *g_725 = &g_483;
static int16_t g_798 = 0x09B2L;
static uint32_t g_820[5][2][7] = {
    {{18446744073709551615UL, 18446744073709551615UL, 18446744073709551615UL,
      9UL, 0xA03B0599L, 0xAFEBB02EL, 18446744073709551612UL},
     {18446744073709551615UL, 18446744073709551615UL, 18446744073709551615UL,
      9UL, 0xA03B0599L, 0xAFEBB02EL, 18446744073709551612UL}},
    {{18446744073709551615UL, 18446744073709551615UL, 18446744073709551615UL,
      9UL, 0xA03B0599L, 0xAFEBB02EL, 18446744073709551612UL},
     {18446744073709551615UL, 18446744073709551615UL, 18446744073709551615UL,
      9UL, 0xA03B0599L, 0xAFEBB02EL, 18446744073709551612UL}},
    {{18446744073709551615UL, 18446744073709551615UL, 18446744073709551615UL,
      9UL, 0xA03B0599L, 0xAFEBB02EL, 18446744073709551612UL},
     {18446744073709551615UL, 18446744073709551615UL, 18446744073709551615UL,
      9UL, 0xA03B0599L, 0xAFEBB02EL, 18446744073709551612UL}},
    {{18446744073709551615UL, 18446744073709551615UL, 18446744073709551615UL,
      9UL, 0xA03B0599L, 0xAFEBB02EL, 18446744073709551612UL},
     {18446744073709551615UL, 18446744073709551615UL, 18446744073709551615UL,
      9UL, 0xA03B0599L, 0xAFEBB02EL, 18446744073709551612UL}},
    {{18446744073709551615UL, 18446744073709551615UL, 18446744073709551615UL,
      9UL, 0xA03B0599L, 0xAFEBB02EL, 18446744073709551612UL},
     {18446744073709551615UL, 18446744073709551615UL, 18446744073709551615UL,
      9UL, 0xA03B0599L, 0xAFEBB02EL, 18446744073709551612UL}}};

static uint32_t func_1(void);
static uint32_t func_3(int8_t p_4, uint32_t p_5, uint8_t p_6);
static int32_t func_13(uint32_t p_14);
static int16_t func_26(int32_t **p_27);
static uint8_t func_39(int32_t *p_40, uint32_t p_41, uint8_t p_42,
                       int16_t p_43);
static int32_t func_56(int32_t p_57, int32_t *p_58, int32_t ***p_59,
                       uint32_t p_60, int16_t p_61);
static uint16_t func_64(uint16_t p_65);
static int32_t func_73(uint32_t p_74);
static int16_t func_82(int32_t *p_83, uint8_t p_84, int32_t **p_85,
                       uint32_t p_86, int32_t **p_87);
static int32_t func_93(int32_t **p_94, int32_t *p_95, int32_t *p_96);
static uint32_t func_1(void) {
  int32_t l_2 = 0xB0B02971L;
  uint32_t l_8 = 0xA3B3F365L;
  int8_t l_21 = 2L;
  int32_t **l_959 = &g_725;
  int32_t *l_962 = &g_171;
  int32_t l_963 = 1L;
  l_21 =
      (l_2 |
       ((+func_3(g_7, l_8, g_7)) !=
        (((safe_rshift_func_uint16_t_u_u((g_20 || (l_8 | 1UL)), func_13(l_2))),
          g_20),
         l_2)));

  (*g_143) = (((0xE052L <
                (safe_mod_func_uint16_t_u_u(
                    (((((safe_lshift_func_int16_t_s_s((+func_26(&g_10)), 10)) >=
                        g_820[0][0][0]) &&
                       g_171) ||
                      ((safe_div_func_uint8_t_u_u(
                           (0x4007L != (safe_sub_func_uint8_t_u_u(
                                           250UL, (g_114[0], g_820[0][1][0])))),
                           g_820[0][1][0])),
                       g_483)) < l_2),
                    0x7200L))) &
               l_8),
              l_959);

  (*l_962) = (safe_div_func_int8_t_s_s(l_8, 0xC0L));
  return l_963;
}

static uint32_t func_3(int8_t p_4, uint32_t p_5, uint8_t p_6) {
  int32_t *l_9 = (void *)0;
  int32_t *l_16 = &g_7;
  int32_t l_17 = (-4L);
  g_10 = l_9;

  (*l_16) = ((safe_sub_func_uint16_t_u_u(
                 g_7, (func_13(g_7) & (((p_5, g_7) >= (&g_7 == l_16)) ^
                                       (p_5 | (p_4, g_7)))))) <= 251UL);
  return l_17;
}

static int32_t func_13(uint32_t p_14) {
  int32_t *l_15 = (void *)0;
  l_15 = l_15;
  return p_14;
}

static int16_t func_26(int32_t **p_27) {
  uint16_t l_37 = 0UL;
  int32_t *l_736 = &g_72;
  int32_t ***l_790 = &g_144;
  uint32_t l_811 = 0xCF6CDECFL;
  uint32_t l_812[8];
  int8_t l_855 = (-1L);
  int8_t l_871 = 0L;
  int16_t l_928 = 0xD1DFL;
  int32_t l_944 = 3L;
  int i;
  for (i = 0; i < 8; i++)
    l_812[i] = 2UL;
  for (g_7 = 19; (g_7 >= (-21)); g_7--) {
    uint8_t l_45 = 1UL;
    int32_t l_735[8][9] = {{(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                            0xD7D2406AL, (-6L), (-7L)},
                           {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                            0xD7D2406AL, (-6L), (-7L)},
                           {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                            0xD7D2406AL, (-6L), (-7L)},
                           {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                            0xD7D2406AL, (-6L), (-7L)},
                           {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                            0xD7D2406AL, (-6L), (-7L)},
                           {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                            0xD7D2406AL, (-6L), (-7L)},
                           {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                            0xD7D2406AL, (-6L), (-7L)},
                           {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                            0xD7D2406AL, (-6L), (-7L)}};
    int i, j;
    for (g_20 = 6; (g_20 == 19); g_20 = safe_add_func_uint8_t_u_u(g_20, 2)) {
      int8_t l_34 = 1L;
      uint16_t l_38[3];
      int32_t *l_44 = &g_7;
      int32_t l_734 = (-5L);
      int i = 0;

      l_812[i] = 2UL;

      l_735[2][8] =
          ((1L <=
            (safe_rshift_func_int8_t_s_u(
                (((l_34 < (&g_10 == p_27)),
                  (~(safe_mod_func_int32_t_s_s(
                      ((((~l_37) <=
                         (((((~((l_38[1], ((func_39((func_13((func_13(g_20) ^
                                                              func_13(l_37))),
                                                     l_44),
                                                    g_20, (*l_44), l_45),
                                            (void *)0) != (void *)0)) ||
                                g_72)),
                             (-10L)),
                            0x03L) != 255UL) == l_734)) > g_114[0]) <= 0x17C4L),
                      l_45)))) |
                 l_45),
                3))) != (*l_44));
      {
        int8_t l_34 = 1L;
        uint16_t l_38[3];
        int32_t *l_44 = &g_7;
        int32_t l_734 = (-5L);
        int i;
        for (i = 0; i < 3; i++)
          l_38[i] = 65535UL;
        l_735[2][8] =
            ((1L <=
              (safe_rshift_func_int8_t_s_u(
                  (((l_34 < (&g_10 == p_27)),
                    (~(safe_mod_func_int32_t_s_s(
                        ((((~l_37) <=
                           (((((~((l_38[1], ((func_39((func_13((func_13(g_20) ^
                                                                func_13(l_37))),
                                                       l_44),
                                                      g_20, (*l_44), l_45),
                                              (void *)0) != (void *)0)) ||
                                  g_72)),
                               (-10L)),
                              0x03L) != 255UL) == l_734)) > g_114[0]) <=
                         0x17C4L),
                        l_45)))) |
                   l_45),
                  3))) != (*l_44));

        if (l_37)
          break;
        (*p_27) = &l_735[4][0];

      }


      (*p_27) = &l_735[4][0];
      for (i = 0; i < 8; i++)
        l_812[i] = 2UL;

    }


    (*p_27) = l_736;

  }

  for (g_483 = 0; (g_483 > 17); g_483 = safe_add_func_int32_t_s_s(g_483, 9)) {
    int16_t l_765 = 0x3917L;
    int32_t ***l_768 = (void *)0;
    int16_t l_771 = 1L;
    int32_t **l_793[5][7][3] = {{{&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]}},
                                {{&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]}},
                                {{&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]}},
                                {{&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]}},
                                {{&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]},
                                 {&g_725, &l_736, &g_677[1][0][1]}}};
    int8_t l_837 = 0x79L;
    uint8_t l_839 = 255UL;
    uint32_t l_850 = 0x4E6F860AL;
    int32_t *l_894[7][3] = {{&g_7, &g_7, &g_7}, {&g_7, &g_7, &g_7},
                            {&g_7, &g_7, &g_7}, {&g_7, &g_7, &g_7},
                            {&g_7, &g_7, &g_7}, {&g_7, &g_7, &g_7},
                            {&g_7, &g_7, &g_7}};
    int32_t *l_910 = &g_72;
    int i, j, k;
    if ((*l_736)) {
      uint32_t l_748 = 1UL;
      int32_t **l_756 = &l_736;
      int32_t **l_777 = (void *)0;

      {
        uint32_t l_748 = 1UL;
        int32_t **l_756 = &l_736;
        int32_t **l_777 = (void *)0;
        for (g_7 = 0; (g_7 <= 5); g_7 += 1) {
          int32_t *l_739 = (void *)0;
          uint8_t l_770 = 0x44L;
          uint8_t l_778 = 6UL;
          int32_t l_783 = 0x449CE7E6L;
          int i, j;
          (*p_27) = l_739;

          if (g_496[g_7][g_7]) {
            int i, j;
            (**l_756) =
                (((g_496[g_7][g_7],
                   ((safe_lshift_func_uint8_t_u_u(
                        ((safe_sub_func_uint16_t_u_u(
                             (safe_lshift_func_uint8_t_u_u(
                                 ((g_496[g_7][g_7],
                                   (safe_lshift_func_uint8_t_u_s(
                                       0x22L, (l_748 | 0UL)))),
                                  (*l_736)),
                                 (safe_lshift_func_int8_t_s_u(
                                     (safe_add_func_int32_t_s_s(
                                         ((safe_sub_func_uint16_t_u_u(
                                              (((safe_unary_minus_func_int32_t_s(
                                                    ((void *)0 == l_756))),
                                                (*p_27)) != (*l_756)),
                                              g_72)) |
                                          g_20),
                                         8L)),
                                     0)))),
                             (**l_756))) |
                         g_496[g_7][g_7]),
                        4)) &&
                    0xF5L)),
                  (void *)0) != (void *)0);
            (*p_27) = (void *)0;
          } else {
            uint32_t l_769[6][3];
            int i, j;
            for (i = 0; i < 6; i++) {
              for (j = 0; j < 3; j++)
                l_769[i][j] = 18446744073709551612UL;
            }
            (**l_756) = (safe_rshift_func_int16_t_s_s(
                (safe_mod_func_int32_t_s_s(
                    (safe_rshift_func_int16_t_s_u(
                        (((safe_sub_func_uint16_t_u_u(
                              ((l_765, 1UL), g_171),
                              (safe_rshift_func_uint16_t_u_s(
                                  65535UL,
                                  (((1UL != 1L) |
                                    ((((((l_768 != (void *)0) < l_769[1][2]),
                                        1UL) == (*l_736)) &&
                                      0x76L) ^
                                     l_770)) != (*l_736)))))),
                          l_771) &
                         g_55),
                        g_7)),
                    l_769[1][2])),
                12));
            (*l_736) =
                ((safe_div_func_int16_t_s_s(
                     (((void *)0 != (*p_27)) &
                      (safe_unary_minus_func_int16_t_s(
                          ((0xF1B5L != (safe_sub_func_int32_t_s_s(
                                           l_769[1][2],
                                           (((void *)0 == l_777) >= l_778)))) <=
                           (safe_div_func_int8_t_s_s(
                               ((1UL == (g_496[1][2] <= g_20)) ^ l_769[5][1]),
                               l_783)))))),
                     l_769[1][0])) ||
                 0xC8L);
          }
          (*l_736) = (safe_lshift_func_uint16_t_u_u(
              (0x6169L &&
               (((safe_lshift_func_int8_t_s_s((0x39AE2E96L > (**l_756)), 6)) <=
                 (g_496[1][4] & (*l_736))),
                ((safe_lshift_func_int16_t_s_u(g_496[1][4], 0)) !=
                 (&g_144 == l_790)))),
              g_114[1]));
        }
      }

    } else {
      int8_t l_794[4][1];
      int32_t l_797 = 6L;
      int i, j;
      for (i = 0; i < 4; i++) {
        for (j = 0; j < 1; j++)
          ;
      }

    }

    {
      uint8_t l_45 = 1UL;
      int32_t l_735[8][9] = {{(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                              0xD7D2406AL, (-6L), (-7L)},
                             {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                              0xD7D2406AL, (-6L), (-7L)},
                             {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                              0xD7D2406AL, (-6L), (-7L)},
                             {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                              0xD7D2406AL, (-6L), (-7L)},
                             {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                              0xD7D2406AL, (-6L), (-7L)},
                             {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                              0xD7D2406AL, (-6L), (-7L)},
                             {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                              0xD7D2406AL, (-6L), (-7L)},
                             {(-7L), (-8L), 8L, 0x4C3F4589L, (-7L), (-6L),
                              0xD7D2406AL, (-6L), (-7L)}};
      int i, j;
      for (g_20 = 6; (g_20 == 19); g_20 = safe_add_func_uint8_t_u_u(g_20, 2)) {
        int8_t l_34 = 1L;
        uint16_t l_38[3];
        int32_t *l_44 = &g_7;
        int32_t l_734 = (-5L);
        int i;
        for (i = 0; i < 3; i++)
          l_38[i] = 65535UL;
        l_735[2][8] =
            ((1L <=
              (safe_rshift_func_int8_t_s_u(
                  (((l_34 < (&g_10 == p_27)),
                    (~(safe_mod_func_int32_t_s_s(
                        ((((~l_37) <=
                           (((((~((l_38[1], ((func_39((func_13((func_13(g_20) ^
                                                                func_13(l_37))),
                                                       l_44),
                                                      g_20, (*l_44), l_45),
                                              (void *)0) != (void *)0)) ||
                                  g_72)),
                               (-10L)),
                              0x03L) != 255UL) == l_734)) > g_114[0]) <=
                         0x17C4L),
                        l_45)))) |
                   l_45),
                  3))) != (*l_44));

        if (l_37)
          break;
        (*p_27) = &l_735[4][0];

      }


      (*p_27) = l_736;

    }

    if (g_798)
      ;

    {
      int16_t l_765 = 0x3917L;
      int32_t ***l_768 = (void *)0;
      int16_t l_771 = 1L;
      int32_t **l_793[5][7][3] = {{{&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]}},
                                  {{&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]}},
                                  {{&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]}},
                                  {{&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]}},
                                  {{&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]},
                                   {&g_725, &l_736, &g_677[1][0][1]}}};
      int8_t l_837 = 0x79L;
      uint8_t l_839 = 255UL;
      uint32_t l_850 = 0x4E6F860AL;
      int32_t *l_894[7][3] = {{&g_7, &g_7, &g_7}, {&g_7, &g_7, &g_7},
                              {&g_7, &g_7, &g_7}, {&g_7, &g_7, &g_7},
                              {&g_7, &g_7, &g_7}, {&g_7, &g_7, &g_7},
                              {&g_7, &g_7, &g_7}};
      int32_t *l_910 = &g_72;
      int i, j, k;
      if ((*l_736)) {
        uint32_t l_748 = 1UL;
        int32_t **l_756 = &l_736;
        int32_t **l_777 = (void *)0;
        for (g_7 = 0; (g_7 <= 5); g_7 += 1) {
          int32_t *l_739 = (void *)0;
          uint8_t l_770 = 0x44L;
          uint8_t l_778 = 6UL;
          int32_t l_783 = 0x449CE7E6L;
          int i, j;
          (*p_27) = l_739;

          if (g_496[g_7][g_7]) {
            int i, j;
            (**l_756) =
                (((g_496[g_7][g_7],
                   ((safe_lshift_func_uint8_t_u_u(
                        ((safe_sub_func_uint16_t_u_u(
                             (safe_lshift_func_uint8_t_u_u(
                                 ((g_496[g_7][g_7],
                                   (safe_lshift_func_uint8_t_u_s(
                                       0x22L, (l_748 | 0UL)))),
                                  (*l_736)),
                                 (safe_lshift_func_int8_t_s_u(
                                     (safe_add_func_int32_t_s_s(
                                         ((safe_sub_func_uint16_t_u_u(
                                              (((safe_unary_minus_func_int32_t_s(
                                                    ((void *)0 == l_756))),
                                                (*p_27)) != (*l_756)),
                                              g_72)) |
                                          g_20),
                                         8L)),
                                     0)))),
                             (**l_756))) |
                         g_496[g_7][g_7]),
                        4)) &&
                    0xF5L)),
                  (void *)0) != (void *)0);
            (*p_27) = (void *)0;
          } else {
            uint32_t l_769[6][3];
            int i, j;
            for (i = 0; i < 6; i++) {
              for (j = 0; j < 3; j++)
                l_769[i][j] = 18446744073709551612UL;
            }
            (**l_756) = (safe_rshift_func_int16_t_s_s(
                (safe_mod_func_int32_t_s_s(
                    (safe_rshift_func_int16_t_s_u(
                        (((safe_sub_func_uint16_t_u_u(
                              ((l_765, 1UL), g_171),
                              (safe_rshift_func_uint16_t_u_s(
                                  65535UL,
                                  (((1UL != 1L) |
                                    ((((((l_768 != (void *)0) < l_769[1][2]),
                                        1UL) == (*l_736)) &&
                                      0x76L) ^
                                     l_770)) != (*l_736)))))),
                          l_771) &
                         g_55),
                        g_7)),
                    l_769[1][2])),
                12));
            (*l_736) =
                ((safe_div_func_int16_t_s_s(
                     (((void *)0 != (*p_27)) &
                      (safe_unary_minus_func_int16_t_s(
                          ((0xF1B5L != (safe_sub_func_int32_t_s_s(
                                           l_769[1][2],
                                           (((void *)0 == l_777) >= l_778)))) <=
                           (safe_div_func_int8_t_s_s(
                               ((1UL == (g_496[1][2] <= g_20)) ^ l_769[5][1]),
                               l_783)))))),
                     l_769[1][0])) ||
                 0xC8L);
          }
          (*l_736) = (safe_lshift_func_uint16_t_u_u(
              (0x6169L &&
               (((safe_lshift_func_int8_t_s_s((0x39AE2E96L > (**l_756)), 6)) <=
                 (g_496[1][4] & (*l_736))),
                ((safe_lshift_func_int16_t_s_u(g_496[1][4], 0)) !=
                 (&g_144 == l_790)))),
              g_114[1]));
        }
      } else {
        int8_t l_794[4][1];
        int32_t l_797 = 6L;
        int i, j;
        for (i = 0; i < 4; i++) {
          for (j = 0; j < 1; j++)
            l_794[i][j] = 0x0BL;
        }
        l_797 =
            (((*g_143) != l_793[2][5][2]) <=
             ((l_794[3][0] == l_794[3][0]) <=
              (safe_rshift_func_int8_t_s_s((p_27 != (l_794[3][0], p_27)), 4))));
      }
      (*l_736) = 0x385572E3L;
      if (g_798)
        continue;
      if (((safe_add_func_int8_t_s_s(
               ((((safe_mod_func_uint8_t_u_u(
                      (safe_sub_func_uint32_t_u_u(
                          0x7241DEF4L,
                          ((safe_div_func_uint32_t_u_u(
                               (safe_add_func_int16_t_s_s(
                                   ((safe_lshift_func_uint16_t_u_s(
                                        ((g_7, (*p_27)) != (void *)0),
                                        ((((g_115 >= g_7) >= g_114[4]),
                                          (0xDEL < g_171)) > 0x551E1BC3L))) &&
                                    g_171),
                                   0x20FFL)),
                               (*l_736))) != l_811))),
                      (*l_736))),
                  g_171) |
                 0x54L) ^
                l_812[0]),
               g_7)) > g_798)) {
        int32_t l_813 = 0x38DEED34L;
        int32_t l_838[8][6][5] = {
            {{0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L}},
            {{0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L}},
            {{0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L}},
            {{0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L}},
            {{0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L}},
            {{0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L}},
            {{0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L}},
            {{0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L},
             {0xB62D0EFDL, 0xCA0096E1L, 0x9AEF4818L, 1L, 1L}}};
        int i, j, k;
        if (l_813)
          break;
        l_838[2][4][3] =
            (((safe_lshift_func_int8_t_s_u(
                  ((safe_rshift_func_int8_t_s_u(
                       (((safe_add_func_uint8_t_u_u((g_7, g_820[0][1][0]),
                                                    0x72L)) |
                         ((((safe_div_func_int8_t_s_s(
                                (safe_sub_func_int16_t_s_s(
                                    g_7,
                                    ((safe_div_func_uint8_t_u_u(
                                         l_813,
                                         (safe_lshift_func_uint16_t_u_s(
                                             (g_798 ^
                                              (safe_lshift_func_uint16_t_u_s(
                                                  (safe_rshift_func_int8_t_s_s(
                                                      (((0x79DF1A72L ==
                                                         (safe_rshift_func_uint16_t_u_s(
                                                             (safe_div_func_uint8_t_u_u(
                                                                 (l_813,
                                                                  (l_813 >=
                                                                   (*l_736))),
                                                                 0x2AL)),
                                                             14))) > g_798) &&
                                                       (*l_736)),
                                                      g_115)),
                                                  3))),
                                             13)))) ^
                                     0x20CAL))),
                                g_483)) |
                            l_837) >= (*l_736)) < (-5L))) &&
                        (*l_736)),
                       2)),
                   g_20),
                  g_496[1][4])) < l_813),
             l_813);
        return l_839;
      } else {
        uint32_t l_844 = 0xDE4B6407L;
        int8_t l_849 = 0x34L;
        int32_t l_873 = 1L;
        uint32_t l_896 = 0x0B8C8F1CL;
        uint8_t l_929 = 0UL;
        int16_t l_953 = 0L;
        if (((!((safe_add_func_uint32_t_u_u(
                    (((((*l_790) == p_27) &&
                       ((safe_add_func_int8_t_s_s(
                            l_844,
                            ((((safe_lshift_func_uint16_t_u_u(
                                   (safe_sub_func_int16_t_s_s(
                                       (0L ^ (l_849, l_849)), l_844)),
                                   (((((((0x3FL ^ (((l_844 != 0xDCCB7517L) ==
                                                    0xA0B54DFEL) < l_850)) ==
                                         g_72),
                                        (*p_27)) == (void *)0) != l_844) ||
                                     (*l_736)) >= g_820[0][1][0]))) |
                               l_849),
                              g_115),
                             l_849))) &&
                        g_55)) ^
                      g_820[0][1][0]) &&
                     0x60C06FB5L),
                    g_820[4][0][5])) |
                (*l_736))) ||
             0x3582L)) {
          uint8_t l_866[3][7] = {
              {250UL, 249UL, 250UL, 249UL, 250UL, 249UL, 250UL},
              {250UL, 249UL, 250UL, 249UL, 250UL, 249UL, 250UL},
              {250UL, 249UL, 250UL, 249UL, 250UL, 249UL, 250UL}};
          int i, j;
          for (l_839 = 10; (l_839 >= 24); l_839++) {
            int8_t l_864[6][9][4] = {{{1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L}},
                                     {{1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L}},
                                     {{1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L}},
                                     {{1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L}},
                                     {{1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L}},
                                     {{1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L},
                                      {1L, (-1L), (-1L), 0x86L}}};
            int32_t *l_865 = &g_171;
            int32_t *l_895[5][3][2] = {
                {{&g_115, &g_7}, {&g_115, &g_7}, {&g_115, &g_7}},
                {{&g_115, &g_7}, {&g_115, &g_7}, {&g_115, &g_7}},
                {{&g_115, &g_7}, {&g_115, &g_7}, {&g_115, &g_7}},
                {{&g_115, &g_7}, {&g_115, &g_7}, {&g_115, &g_7}},
                {{&g_115, &g_7}, {&g_115, &g_7}, {&g_115, &g_7}}};
            int i, j, k;
            for (l_771 = 0; (l_771 < (-22));
                 l_771 = safe_sub_func_int32_t_s_s(l_771, 9)) {
              int32_t l_872[10][8][3] = {{{0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L}},
                                         {{0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L}},
                                         {{0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L}},
                                         {{0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L}},
                                         {{0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L}},
                                         {{0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L}},
                                         {{0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L}},
                                         {{0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L}},
                                         {{0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L}},
                                         {{0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L},
                                          {0L, 0x4B93A83EL, 0x4AF23651L}}};
              int i, j, k;
              (*l_736) =
                  ((((-2L) ^ l_855) ==
                    (safe_rshift_func_int8_t_s_s(
                        (safe_mod_func_int32_t_s_s(
                            (((((((safe_add_func_int8_t_s_s(
                                      (safe_add_func_uint8_t_u_u(
                                          0x8DL, l_864[5][6][1])),
                                      (l_865 ==
                                       (((l_866[0][1] &&
                                          (((((safe_div_func_uint8_t_u_u(
                                                  l_844,
                                                  (safe_add_func_uint16_t_u_u(
                                                      ((((l_866[0][1],
                                                          (l_844 == l_871)) ==
                                                         7L) <=
                                                        l_872[3][6][2]) >
                                                       (*l_865)),
                                                      (-3L))))) ||
                                              l_872[7][7][1]) ^
                                             8UL) >= l_844),
                                           l_866[0][1])),
                                         0x048EL),
                                        (*p_27))))) == g_483) |
                                 (*l_865)) < g_171) ^
                               (*l_865)),
                              0x91L) != l_849),
                            l_873)),
                        3))) == (*l_865));
            }
            (*l_736) =
                ((((+(safe_div_func_int8_t_s_s(
                       ((((safe_rshift_func_uint16_t_u_s(
                              0xC9B1L,
                              (((safe_sub_func_uint32_t_u_u(
                                    ((safe_sub_func_int32_t_s_s(
                                         (*l_865),
                                         (safe_lshift_func_int16_t_s_s(
                                             (g_496[2][3] ||
                                              (((safe_lshift_func_uint16_t_u_s(
                                                    (((g_115,
                                                       (((((safe_rshift_func_uint8_t_u_s(
                                                               (((*p_27) !=
                                                                 (((safe_lshift_func_uint16_t_u_s(
                                                                       g_20,
                                                                       (((*l_865),
                                                                         (*l_865)) ==
                                                                        ((safe_mod_func_int16_t_s_s(
                                                                             5L,
                                                                             g_114
                                                                                 [3])),
                                                                         (*l_736))))) <
                                                                   g_72),
                                                                  l_894[6]
                                                                       [1])) !=
                                                                g_483),
                                                               g_496[2][1])) <
                                                           0x84071E47L) &
                                                          (*l_736)) > 0UL) >=
                                                        0x40L)) <=
                                                      0x9B345832L) ^
                                                     l_844),
                                                    (*l_865))),
                                                (*p_27)) != l_895[2][1][0])),
                                             g_7)))) != 0L),
                                    l_873)) &&
                                l_866[0][1]),
                               0x4685L))),
                          0x9E9C6014L),
                         g_115),
                        l_866[0][1]),
                       0x10L))) < 7UL) < l_873) ^
                 l_896);
            for (g_20 = (-19); (g_20 >= 8);
                 g_20 = safe_add_func_int32_t_s_s(g_20, 2)) {
              (*p_27) = (*p_27);
            }
            for (l_811 = 0; (l_811 <= 5); l_811 += 1) {
              int i, j;
              return g_496[(l_811 + 1)][l_811];
            }
          }
        } else {
          uint8_t l_899 = 0UL;
          int32_t ***l_907 = &l_793[1][0][2];
          if (l_899) {
            int32_t *l_902 = &g_171;
            int32_t l_903 = 1L;
            for (l_896 = 0; (l_896 <= 58); ++l_896) {
              l_902 = (*p_27);

              l_903 = l_844;
            }

          } else {
            uint32_t l_904 = 0x35BB44C1L;
            if (l_904)
              break;
            (*l_736) = (((void *)0 == p_27) >=
                        (safe_add_func_uint8_t_u_u(
                            (((((*l_736), ((-7L) > 0x24L)) <= g_496[5][5]),
                              p_27) == (((void *)0 == l_907), (void *)0)),
                            l_899)));
            return l_873;
          }
          (*p_27) = (*p_27);
        }
        for (l_839 = 13; (l_839 > 50);
             l_839 = safe_add_func_uint8_t_u_u(l_839, 1)) {
          int16_t l_930[10] = {0L, (-5L), 0L, (-5L), 0L,
                               (-5L), 0L, (-5L), 0L, (-5L)};
          uint32_t l_954 = 0xC9F29674L;
          int i;
          for (g_115 = 0; (g_115 <= 7); g_115 += 1) {
            int32_t ***l_919 = &l_793[2][2][0];
            int32_t l_931 = (-1L);
            int i;
            l_910 = (*p_27);
            l_931 = (safe_lshift_func_int8_t_s_u(
                ((safe_rshift_func_uint16_t_u_s(l_812[g_115], 9)) ^
                 ((*p_27) == (void *)0)),
                (((safe_unary_minus_func_int32_t_s(
                      (l_812[g_115] <
                       ((safe_sub_func_int16_t_s_s(
                            (safe_unary_minus_func_uint16_t_u(l_812[g_115])),
                            ((l_919 != (void *)0) ^
                             ((!(safe_sub_func_uint8_t_u_u(
                                  (+(safe_add_func_int32_t_s_s(
                                      (safe_add_func_int32_t_s_s(
                                          (safe_rshift_func_int8_t_s_s(l_873,
                                                                       l_849)),
                                          (*l_736))),
                                      (-5L)))),
                                  0x47L))) == l_928)))) > l_929)))) |
                  65535UL) != l_930[2])));
          }
          l_954 =
              ((safe_sub_func_uint16_t_u_u(
                   (safe_rshift_func_uint8_t_u_u(
                       (((safe_div_func_uint32_t_u_u(
                             (((((((safe_add_func_uint32_t_u_u(
                                       (&g_144 != (l_849, &g_144)),
                                       (((safe_rshift_func_int8_t_s_u(
                                             ((*g_143) == (void *)0), 0)) >=
                                         (safe_sub_func_uint16_t_u_u(
                                             l_944,
                                             (safe_lshift_func_int16_t_s_s(
                                                 0xF87CL,
                                                 ((safe_rshift_func_int16_t_s_u(
                                                      (*l_736), 11)) &
                                                  (!(safe_div_func_uint32_t_u_u(
                                                      (((((((((safe_rshift_func_int8_t_s_s(
                                                                  0xFDL,
                                                                  l_930[2])) ^
                                                              l_896) >
                                                             0xFCFEL) &&
                                                            0x12FD2A34L) &
                                                           l_930[2]) &
                                                          g_115) &
                                                         g_55) &&
                                                        l_930[2]) > g_55),
                                                      l_849))))))))) !=
                                        l_953))) ||
                                   g_798) &&
                                  l_929),
                                 (void *)0) == &g_115) ||
                               248UL) <= l_849),
                             (*l_736))),
                         (*g_143)) != (void *)0),
                       g_72)),
                   65528UL)) &&
               l_873);
        }

        (*p_27) = (*p_27);
      }

    }

  }
  return g_115;
}

static uint8_t func_39(int32_t *p_40, uint32_t p_41, uint8_t p_42,
                       int16_t p_43) {
  int32_t **l_50 = &g_10;
  int32_t l_724[4][4][6] = {
      {{0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L},
       {0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L},
       {0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L},
       {0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L}},
      {{0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L},
       {0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L},
       {0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L},
       {0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L}},
      {{0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L},
       {0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L},
       {0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L},
       {0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L}},
      {{0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L},
       {0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L},
       {0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L},
       {0x77D48A48L, (-6L), 1L, (-6L), 0x77D48A48L, 0xDB7477F5L}}};
  int32_t *l_732 = (void *)0;
  int32_t *l_733 = &l_724[1][3][3];
  int i, j, k;
  for (p_42 = 0; (p_42 <= 26); p_42 = safe_add_func_int8_t_s_s(p_42, 8)) {
    int32_t **l_49[8] = {&g_10, &g_10, (void *)0, &g_10,
                         &g_10, (void *)0, &g_10, &g_10};
    int32_t ***l_48[9] = {&l_49[4], &l_49[4], &l_49[4], &l_49[4], &l_49[4],
                          &l_49[4], &l_49[4], &l_49[4], &l_49[4]};
    int i;
    l_50 = &p_40;
    {
      int32_t **l_49[8] = {&g_10, &g_10, (void *)0, &g_10,
                           &g_10, (void *)0, &g_10, &g_10};
      int32_t ***l_48[9] = {&l_49[4], &l_49[4], &l_49[4], &l_49[4], &l_49[4],
                            &l_49[4], &l_49[4], &l_49[4], &l_49[4]};
      int i;
      l_50 = &p_40;

      (*l_50) = (void *)0;

      for (p_41 = 25; (p_41 <= 43);
           p_41 = safe_add_func_uint32_t_u_u(p_41, 1)) {
        int32_t *l_70[9] = {&g_7, &g_7, &g_7, &g_7, &g_7,
                            &g_7, &g_7, &g_7, &g_7};
        int32_t ***l_678 = (void *)0;
        int i;
        for (p_43 = (-16); (p_43 != 11);
             p_43 = safe_add_func_uint16_t_u_u(p_43, 8)) {
          (*l_50) = &g_7;

          if ((**l_50))
            continue;
          g_55 = (!func_13((func_13((func_13(p_42) != 0x89L)) <= (**l_50))));
          l_724[1][3][3] =
              (g_55,
               (((g_55 |
                  (func_56((safe_rshift_func_uint16_t_u_u(
                               0UL,
                               func_64((((&g_7 == (void *)0), func_13(p_41)),
                                        (safe_div_func_int32_t_s_s(
                                            (((safe_rshift_func_uint8_t_u_u(
                                                  0xF1L,
                                                  ((g_20, p_40) == (void *)0))),
                                              l_70[2]) != (void *)0),
                                            g_55)))))),
                           p_40, l_678, p_43, g_496[0][3]) ^
                   1L)) &&
                 (*p_40)) |
                g_20));
        }
      }

    }

    (*l_50) = (void *)0;

    for (p_41 = 25; (p_41 <= 43); p_41 = safe_add_func_uint32_t_u_u(p_41, 1)) {
      int32_t *l_70[9] = {&g_7, &g_7, &g_7, &g_7, &g_7, &g_7, &g_7, &g_7, &g_7};
      int32_t ***l_678 = (void *)0;
      int i;
      for (p_43 = (-16); (p_43 != 11);
           p_43 = safe_add_func_uint16_t_u_u(p_43, 8)) {

        for (p_43 = (-16); (p_43 != 11);
             p_43 = safe_add_func_uint16_t_u_u(p_43, 8)) {
          (*l_50) = &g_7;

          if ((**l_50))
            continue;
          g_55 = (!func_13((func_13((func_13(p_42) != 0x89L)) <= (**l_50))));
          l_724[1][3][3] =
              (g_55,
               (((g_55 |
                  (func_56((safe_rshift_func_uint16_t_u_u(
                               0UL,
                               func_64((((&g_7 == (void *)0), func_13(p_41)),
                                        (safe_div_func_int32_t_s_s(
                                            (((safe_rshift_func_uint8_t_u_u(
                                                  0xF1L,
                                                  ((g_20, p_40) == (void *)0))),
                                              l_70[2]) != (void *)0),
                                            g_55)))))),
                           p_40, l_678, p_43, g_496[0][3]) ^
                   1L)) &&
                 (*p_40)) |
                g_20));
        }
	__assert_fail ("p_40 == &g_7", "small_orig.c", 2107, "func");
        if ((**l_50)) {
          continue;
        }

        g_55 = (!func_13((func_13((func_13(p_42) != 0x89L)) <= (**l_50))));
      }
    }

  }
  if (l_50 == &p_40 || l_50 == &g_10) ; 
  __assert_fail ("l_50 == &p_40 || l_50 == &g_10", "small_orig.c", 2122, "err");

  g_725 = (void *)0;


  return p_43;
}

static int32_t func_56(int32_t p_57, int32_t *p_58, int32_t ***p_59,
                       uint32_t p_60, int16_t p_61) {
  int8_t l_683 = 0xFAL;
  int32_t *l_691 = &g_483;
  int32_t *l_714 = &g_171;
  (*l_691) = (safe_add_func_uint8_t_u_u(
      (safe_rshift_func_int8_t_s_s(
          ((l_683 || (((safe_lshift_func_uint8_t_u_u(g_20, 6)) ==
                       (safe_rshift_func_int8_t_s_s(
                           (safe_mul_func_int16_t_s_s(
                               p_61, (!(((~(p_57 || p_61)),
                                         ((safe_unary_minus_func_uint8_t_u(
                                              (l_691 == (void *)0))) !=
                                          (l_691 == (void *)0))),
                                        (*l_691))))),
                           2))) |
                      g_55)) ||
           (*l_691)),
          (*l_691))),
      g_496[1][4]));
  for (g_483 = 18; (g_483 > 29); g_483++) {
    int32_t l_698 = 0xDD0561D5L;
    int32_t l_699 = 0x756F43EAL;
    l_699 = (((safe_rshift_func_uint8_t_u_s(
                  (((g_55 || (g_55 | (0UL == g_114[3]))),
                    (safe_add_func_uint8_t_u_u(
                        (l_698 & ((g_7 <= g_55), 0x68AD2A78L)),
                        (0x2E239FE6L > g_171)))) < p_60),
                  (*l_691))) ||
              p_57) ||
             p_60);
    l_699 = (((safe_rshift_func_uint8_t_u_s(
                  (((g_55 || (g_55 | (0UL == g_114[3]))),
                    (safe_add_func_uint8_t_u_u(
                        (l_698 & ((g_7 <= g_55), 0x68AD2A78L)),
                        (0x2E239FE6L > g_171)))) < p_60),
                  (*l_691))) ||
              p_57) ||
             p_60);
  }
  for (g_72 = 0; (g_72 >= (-7)); g_72 = safe_sub_func_uint32_t_u_u(g_72, 7)) {
    uint8_t l_704 = 5UL;
    int32_t *l_713 = &g_72;
    for (l_683 = 0; (l_683 <= (-16));
         l_683 = safe_sub_func_uint16_t_u_u(l_683, 6)) {
      return l_704;
    }
    (*l_691) = (safe_rshift_func_uint16_t_u_u(
        (safe_sub_func_uint16_t_u_u(
            (((safe_mod_func_uint8_t_u_u(((*g_143) != (void *)0), (*l_691))) ==
              ((((void *)0 == l_691) <=
                ((p_57 && 0xCBL) ==
                 (((safe_rshift_func_int8_t_s_u(
                       (((*l_691) || p_57) || g_114[1]), g_496[1][4])) ||
                   0x53L) == (*l_691)))) &&
               l_704)) != 5L),
            g_72)),
        9));
    (*l_691) = (safe_rshift_func_uint16_t_u_u(
        (safe_sub_func_uint16_t_u_u(
            (((safe_mod_func_uint8_t_u_u(((*g_143) != (void *)0), (*l_691))) ==
              ((((void *)0 == l_691) <=
                ((p_57 && 0xCBL) ==
                 (((safe_rshift_func_int8_t_s_u(
                       (((*l_691) || p_57) || g_114[1]), g_496[1][4])) ||
                   0x53L) == (*l_691)))) &&
               l_704)) != 5L),
            g_72)),
        9));

    l_714 = l_713;
    {
      int32_t l_698 = 0xDD0561D5L;
      int32_t l_699 = 0x756F43EAL;
      l_699 = (((safe_rshift_func_uint8_t_u_s(
                    (((g_55 || (g_55 | (0UL == g_114[3]))),
                      (safe_add_func_uint8_t_u_u(
                          (l_698 & ((g_7 <= g_55), 0x68AD2A78L)),
                          (0x2E239FE6L > g_171)))) < p_60),
                    (*l_691))) ||
                p_57) ||
               p_60);
    }

  }


  {
    int8_t l_683 = 0xFAL;
    int32_t *l_691 = &g_483;
    int32_t *l_714 = &g_171;
    (*l_691) = (safe_add_func_uint8_t_u_u(
        (safe_rshift_func_int8_t_s_s(
            ((l_683 || (((safe_lshift_func_uint8_t_u_u(g_20, 6)) ==
                         (safe_rshift_func_int8_t_s_s(
                             (safe_mul_func_int16_t_s_s(
                                 p_61, (!(((~(p_57 || p_61)),
                                           ((safe_unary_minus_func_uint8_t_u(
                                                (l_691 == (void *)0))) !=
                                            (l_691 == (void *)0))),
                                          (*l_691))))),
                             2))) |
                        g_55)) ||
             (*l_691)),
            (*l_691))),
        g_496[1][4]));
    for (g_483 = 18; (g_483 > 29); g_483++) {
      int32_t l_698 = 0xDD0561D5L;
      int32_t l_699 = 0x756F43EAL;
      l_699 = (((safe_rshift_func_uint8_t_u_s(
                    (((g_55 || (g_55 | (0UL == g_114[3]))),
                      (safe_add_func_uint8_t_u_u(
                          (l_698 & ((g_7 <= g_55), 0x68AD2A78L)),
                          (0x2E239FE6L > g_171)))) < p_60),
                    (*l_691))) ||
                p_57) ||
               p_60);
    }
    for (g_72 = 0; (g_72 >= (-7)); g_72 = safe_sub_func_uint32_t_u_u(g_72, 7)) {
      uint8_t l_704 = 5UL;
      int32_t *l_713 = &g_72;
      for (l_683 = 0; (l_683 <= (-16));
           l_683 = safe_sub_func_uint16_t_u_u(l_683, 6)) {
        return l_704;
      }
      (*l_691) = (safe_rshift_func_uint16_t_u_u(
          (safe_sub_func_uint16_t_u_u(
              (((safe_mod_func_uint8_t_u_u(((*g_143) != (void *)0),
                                           (*l_691))) ==
                ((((void *)0 == l_691) <=
                  ((p_57 && 0xCBL) ==
                   (((safe_rshift_func_int8_t_s_u(
                         (((*l_691) || p_57) || g_114[1]), g_496[1][4])) ||
                     0x53L) == (*l_691)))) &&
                 l_704)) != 5L),
              g_72)),
          9));
      l_714 = l_713;

    }

    (*l_691) =
        ((p_57 > ((*l_714) == 0x546DL)) >=
         (((+((*l_691) ==
              (((*l_714), (!g_20)) >=
               (safe_lshift_func_int8_t_s_s(
                   (safe_lshift_func_int8_t_s_u(
                       (-4L),
                       (safe_lshift_func_int8_t_s_s(
                           p_60, (((safe_unary_minus_func_uint16_t_u((~g_55))) ^
                                   p_61) |
                                  (*p_58)))))),
                   0))))),
           &l_691) != (*g_143)));
    return (*l_714);
  }

  return (*l_714);
}

static uint16_t func_64(uint16_t p_65) {
  int32_t *l_71 = &g_72;
  uint16_t l_627 = 0UL;

lbl_594:
  (*l_71) = func_73((*l_71));
lbl_606:
  for (p_65 = (-2); (p_65 > 50); p_65++) {
    int32_t **l_580 = (void *)0;
    uint32_t l_581 = 18446744073709551615UL;
    if (p_65)
      break;
    for (g_72 = 0; (g_72 == 23); g_72 = safe_add_func_uint16_t_u_u(g_72, 9)) {
      uint8_t l_571 = 0x2CL;
      uint32_t l_592 = 0x59E68A70L;
      int32_t l_593 = 1L;
      if ((safe_sub_func_int32_t_s_s(
              ((safe_div_func_int16_t_s_s(
                   (safe_sub_func_int8_t_s_s(
                       l_571,
                       (safe_lshift_func_int16_t_s_s(
                           ((((((safe_add_func_int16_t_s_s(
                                    ((*l_71) && 4294967293UL), g_496[1][4])),
                                ((safe_div_func_uint32_t_u_u(
                                     ((safe_mod_func_uint8_t_u_u(
                                          (((((((g_115, l_580) != (*g_143)) <=
                                               (((l_71 == (void *)0) | p_65) >
                                                0x0EBCL)),
                                              (void *)0) != &g_144) <= g_55) <=
                                           0x673EL),
                                          g_115)) >= (*l_71)),
                                     p_65)) >= 0x06DEL)),
                               (*l_71)) > l_581),
                             p_65) < p_65),
                           8)))),
                   p_65)) >= (*l_71)),
              p_65))) {
        uint16_t l_586 = 0x442AL;
        int32_t *l_591 = &g_72;
        for (g_115 = (-8); (g_115 != 3); g_115++) {
          l_593 = ((safe_div_func_uint8_t_u_u(
                       ((-1L) !=
                        (((l_586 != (0x0BL == ((*l_71) ^ (~g_72)))), l_71) !=
                         ((safe_sub_func_int8_t_s_s(
                              (safe_add_func_int32_t_s_s(l_586, 0x15B31ADBL)),
                              ((((l_591 != (void *)0) <= 4UL) != 1UL), p_65))),
                          l_591))),
                       p_65)),
                   l_592);
        }
        if (g_72)
          goto lbl_594;
      } else {
        for (l_581 = 29; (l_581 != 31); ++l_581) {
          return g_483;
        }
      }
      return l_571;
    }
  }
  for (g_171 = (-3); (g_171 <= (-12));
       g_171 = safe_sub_func_uint16_t_u_u(g_171, 4)) {
    int32_t **l_605 = (void *)0;
    int32_t *l_608 = &g_115;
    int8_t l_669 = 0x2DL;

    if ((*l_71))
      break;

    if ((&l_71 ==
         ((safe_sub_func_uint32_t_u_u(
              ((safe_add_func_int16_t_s_s(g_115, p_65)) >=
               (safe_sub_func_int16_t_s_s(
                   (((65529UL && ((*l_71) != (((*l_71), l_605) == &l_71))) ^
                     (((0xFE9FL < (*l_71)), p_65) != p_65)),
                    p_65),
                   p_65))),
              (*l_71))),
          (*g_143)))) {
      int32_t *l_607 = &g_171;

      {
        int32_t *l_607 = &g_171;
        if (g_7)
          goto lbl_606;
        l_608 = l_607;

      }

      l_608 = l_607;

    } else {
      uint16_t l_611 = 0xBBEEL;
      int32_t **l_612 = (void *)0;
      for (g_483 = 0; (g_483 >= (-7));
           g_483 = safe_sub_func_uint8_t_u_u(g_483, 2)) {
        if (l_611)
          break;
        {
          uint16_t l_611 = 0xBBEEL;
          int32_t **l_612 = (void *)0;
          for (g_483 = 0; (g_483 >= (-7));
               g_483 = safe_sub_func_uint8_t_u_u(g_483, 2)) {
            if (l_611)
              break;
          }
          if (((*g_143) == l_612)) {
            uint8_t l_613[8] = {0xABL, 0xABL, 7UL, 0xABL,
                                0xABL, 7UL, 0xABL, 0xABL};
            uint32_t l_618 = 18446744073709551615UL;
            int32_t ***l_628 = (void *)0;
            int i;
            (*l_71) = (l_613[4] < p_65);
            g_115 = (p_65 <=
                     ((safe_rshift_func_uint8_t_u_s(l_613[4], 4)) ==
                      (((safe_div_func_int8_t_s_s(
                            l_618,
                            (safe_sub_func_uint8_t_u_u(
                                0xB2L,
                                ((0x6C35L &
                                  ((safe_mul_func_int16_t_s_s(
                                       ((void *)0 == (*g_143)),
                                       ((((safe_mod_func_int16_t_s_s(
                                              0xC6E6L,
                                              ((((safe_mod_func_uint32_t_u_u(
                                                     ((((((((g_20, l_613[4]) <=
                                                            p_65) &
                                                           g_115) < p_65) &&
                                                         l_613[2]) &&
                                                        0xDEE6L) >= l_618) &
                                                      l_627),
                                                     g_72)),
                                                 p_65) |
                                                g_496[1][4]),
                                               (-1L)))) < l_613[0]),
                                         g_496[2][2]) != g_483))) == g_483)) <
                                 g_7))))),
                        &g_144) != l_628)));
            for (g_72 = 5; (g_72 >= 0); g_72 -= 1) {
              int32_t *l_629 = &g_483;
              int32_t **l_630 = &l_71;
              int i, j;
              (*l_630) = l_629;

              (*l_71) = (l_628 == &l_630);
              if (g_496[g_72][g_72])
                continue;
            }
            if (p_65)
              break;
          } else {
            int16_t l_649 = 0xF921L;
            int16_t l_650 = (-5L);
            int32_t *l_651 = (void *)0;
            uint32_t l_655 = 0xF25B5010L;
            int32_t *l_660[1];
            int i;
            for (i = 0; i < 1; i++)
              l_660[i] = &g_115;
            (*l_608) = (safe_lshift_func_uint8_t_u_u(
                (!(((((safe_mod_func_int8_t_s_s(
                          ((safe_mod_func_int16_t_s_s(
                               (+((safe_add_func_uint16_t_u_u(
                                      p_65,
                                      ((safe_div_func_int32_t_s_s(
                                           (((safe_sub_func_uint8_t_u_u(
                                                 (p_65 | p_65),
                                                 ((safe_sub_func_int16_t_s_s(
                                                      (safe_add_func_int16_t_s_s(
                                                          ((*g_143) != &l_608),
                                                          (safe_rshift_func_int16_t_s_s(
                                                              ((void *)0 ==
                                                               &l_605),
                                                              2)))),
                                                      (*l_608))) >=
                                                  (((0xE48EL | 65535UL),
                                                    0xE3FBL) >= (*l_71))))) &
                                             (*l_71)) |
                                            g_496[3][1]),
                                           4294967286UL)),
                                       (*l_71)))) != 0x5A241DA0L)),
                               l_649)) <= (-5L)),
                          (*l_71))),
                      g_115) < g_171),
                    0x02EFBA42L) < p_65)),
                p_65));
            if (l_650) {
              int32_t **l_652 = &l_608;
              (*l_652) = (g_20, l_651);

              for (g_115 = (-30); (g_115 == 12); g_115++) {
                (*l_652) = &g_72;

                l_655 = ((((g_171 ^ (*l_71)), &g_72) != l_651) >= p_65);
              }

              for (p_65 = 26; (p_65 == 37);
                   p_65 = safe_add_func_int32_t_s_s(p_65, 8)) {
                (*l_71) = (safe_rshift_func_uint8_t_u_s(
                    (*l_71), (l_660[0] == (void *)0)));
              }
            } else {
              int16_t l_663[3];
              uint8_t l_676 = 0UL;
              int i;
              for (i = 0; i < 3; i++)
                l_663[i] = 1L;
              for (g_115 = 11; (g_115 >= 26); ++g_115) {
                uint16_t l_664 = 0x2FD1L;
                l_664 = l_663[2];
                (*l_71) = (safe_add_func_int8_t_s_s(
                    (p_65,
                     ((((safe_div_func_int32_t_s_s(
                            (((l_669 & (safe_lshift_func_int16_t_s_u(
                                           p_65, 15))) != p_65) ==
                             (p_65 &
                              ((safe_rshift_func_int8_t_s_s(l_663[0], 5)) !=
                               (((&l_612 != (void *)0) ==
                                 (safe_div_func_int32_t_s_s(
                                     (((((*g_143) != (*g_143)) ^ g_115) <
                                       4294967295UL) >= 65528UL),
                                     g_496[5][1]))) >= p_65)))),
                            p_65)) != g_496[5][2]) &
                       0x48L) != g_20)),
                    (-3L)));
                l_676 = p_65;
                l_660[0] = g_677[6][0][4];
              }
            }


            if (p_65)
              continue;
          }

        }
      }
      if (((*g_143) == l_612)) {
        uint8_t l_613[8] = {0xABL, 0xABL, 7UL, 0xABL, 0xABL, 7UL, 0xABL, 0xABL};
        uint32_t l_618 = 18446744073709551615UL;
        int32_t ***l_628 = (void *)0;
        int i;
        (*l_71) = (l_613[4] < p_65);

        (*l_71) = (l_613[4] < p_65);

        for (g_72 = 5; (g_72 >= 0); g_72 -= 1) {
          int32_t *l_629 = &g_483;
          int32_t **l_630 = &l_71;
          int i, j;

          (*l_71) = (l_628 == &l_630);
          if (g_496[g_72][g_72]) {
            continue;
          }
        }
        if (p_65) {
          break;
          {
            if (l_611)
              break;
          }

          {
            uint16_t l_611 = 0xBBEEL;
            int32_t **l_612 = (void *)0;
            for (g_483 = 0; (g_483 >= (-7));
                 g_483 = safe_sub_func_uint8_t_u_u(g_483, 2)) {
              if (l_611)
                break;
            }
            if (((*g_143) == l_612)) {
              uint8_t l_613[8] = {0xABL, 0xABL, 7UL, 0xABL,
                                  0xABL, 7UL, 0xABL, 0xABL};
              uint32_t l_618 = 18446744073709551615UL;
              int32_t ***l_628 = (void *)0;
              int i;
              (*l_71) = (l_613[4] < p_65);
              g_115 =
                  (p_65 <=
                   ((safe_rshift_func_uint8_t_u_s(l_613[4], 4)) ==
                    (((safe_div_func_int8_t_s_s(
                          l_618,
                          (safe_sub_func_uint8_t_u_u(
                              0xB2L,
                              ((0x6C35L &
                                ((safe_mul_func_int16_t_s_s(
                                     ((void *)0 == (*g_143)),
                                     ((((safe_mod_func_int16_t_s_s(
                                            0xC6E6L,
                                            ((((safe_mod_func_uint32_t_u_u(
                                                   ((((((((g_20, l_613[4]) <=
                                                          p_65) &
                                                         g_115) < p_65) &&
                                                       l_613[2]) &&
                                                      0xDEE6L) >= l_618) &
                                                    l_627),
                                                   g_72)),
                                               p_65) |
                                              g_496[1][4]),
                                             (-1L)))) < l_613[0]),
                                       g_496[2][2]) != g_483))) == g_483)) <
                               g_7))))),
                      &g_144) != l_628)));
              for (g_72 = 5; (g_72 >= 0); g_72 -= 1) {
                int32_t *l_629 = &g_483;
                int32_t **l_630 = &l_71;
                int i, j;
                (*l_630) = l_629;

                (*l_71) = (l_628 == &l_630);
                if (g_496[g_72][g_72])
                  continue;
              }
              if (p_65)
                break;
            } else {
              int16_t l_649 = 0xF921L;
              int16_t l_650 = (-5L);
              int32_t *l_651 = (void *)0;
              uint32_t l_655 = 0xF25B5010L;
              int32_t *l_660[1];
              int i;
              for (i = 0; i < 1; i++)
                l_660[i] = &g_115;
              (*l_608) = (safe_lshift_func_uint8_t_u_u(
                  (!(((((safe_mod_func_int8_t_s_s(
                            ((safe_mod_func_int16_t_s_s(
                                 (+((safe_add_func_uint16_t_u_u(
                                        p_65,
                                        ((safe_div_func_int32_t_s_s(
                                             (((safe_sub_func_uint8_t_u_u(
                                                   (p_65 | p_65),
                                                   ((safe_sub_func_int16_t_s_s(
                                                        (safe_add_func_int16_t_s_s(
                                                            ((*g_143) !=
                                                             &l_608),
                                                            (safe_rshift_func_int16_t_s_s(
                                                                ((void *)0 ==
                                                                 &l_605),
                                                                2)))),
                                                        (*l_608))) >=
                                                    (((0xE48EL | 65535UL),
                                                      0xE3FBL) >= (*l_71))))) &
                                               (*l_71)) |
                                              g_496[3][1]),
                                             4294967286UL)),
                                         (*l_71)))) != 0x5A241DA0L)),
                                 l_649)) <= (-5L)),
                            (*l_71))),
                        g_115) < g_171),
                      0x02EFBA42L) < p_65)),
                  p_65));
              if (l_650) {
                int32_t **l_652 = &l_608;
                (*l_652) = (g_20, l_651);

                for (g_115 = (-30); (g_115 == 12); g_115++) {
                  (*l_652) = &g_72;

                  l_655 = ((((g_171 ^ (*l_71)), &g_72) != l_651) >= p_65);
                }

                for (p_65 = 26; (p_65 == 37);
                     p_65 = safe_add_func_int32_t_s_s(p_65, 8)) {
                  (*l_71) = (safe_rshift_func_uint8_t_u_s(
                      (*l_71), (l_660[0] == (void *)0)));
                }
              } else {
                int16_t l_663[3];
                uint8_t l_676 = 0UL;
                int i;
                for (i = 0; i < 3; i++)
                  l_663[i] = 1L;
                for (g_115 = 11; (g_115 >= 26); ++g_115) {
                  uint16_t l_664 = 0x2FD1L;
                  l_664 = l_663[2];
                  (*l_71) = (safe_add_func_int8_t_s_s(
                      (p_65,
                       ((((safe_div_func_int32_t_s_s(
                              (((l_669 & (safe_lshift_func_int16_t_s_u(
                                             p_65, 15))) != p_65) ==
                               (p_65 &
                                ((safe_rshift_func_int8_t_s_s(l_663[0], 5)) !=
                                 (((&l_612 != (void *)0) ==
                                   (safe_div_func_int32_t_s_s(
                                       (((((*g_143) != (*g_143)) ^ g_115) <
                                         4294967295UL) >= 65528UL),
                                       g_496[5][1]))) >= p_65)))),
                              p_65)) != g_496[5][2]) &
                         0x48L) != g_20)),
                      (-3L)));
                  l_676 = p_65;
                  l_660[0] = g_677[6][0][4];
                }
              }


              if (p_65)
                continue;
            }

          }
        }

      } else {
        int16_t l_649 = 0xF921L;
        int16_t l_650 = (-5L);
        int32_t *l_651 = (void *)0;
        uint32_t l_655 = 0xF25B5010L;
        int32_t *l_660[1];
        int i;

        (*l_71) = g_7;

        (*l_608) = (safe_lshift_func_uint8_t_u_u(
            (!(((((safe_mod_func_int8_t_s_s(
                      ((safe_mod_func_int16_t_s_s(
                           (+((safe_add_func_uint16_t_u_u(
                                  p_65,
                                  ((safe_div_func_int32_t_s_s(
                                       (((safe_sub_func_uint8_t_u_u(
                                             (p_65 | p_65),
                                             ((safe_sub_func_int16_t_s_s(
                                                  (safe_add_func_int16_t_s_s(
                                                      ((*g_143) != &l_608),
                                                      (safe_rshift_func_int16_t_s_s(
                                                          ((void *)0 == &l_605),
                                                          2)))),
                                                  (*l_608))) >=
                                              (((0xE48EL | 65535UL), 0xE3FBL) >=
                                               (*l_71))))) &
                                         (*l_71)) |
                                        g_496[3][1]),
                                       4294967286UL)),
                                   (*l_71)))) != 0x5A241DA0L)),
                           l_649)) <= (-5L)),
                      (*l_71))),
                  g_115) < g_171),
                0x02EFBA42L) < p_65)),
            p_65));
        if (l_650) {
          int32_t **l_652 = &l_608;

          if ((*l_71))
            break;

          for (g_115 = (-30); (g_115 == 12); g_115++) {

            if (l_650) {
              int32_t **l_652 = &l_608;
              (*l_652) = (g_20, l_651);

              for (g_115 = (-30); (g_115 == 12); g_115++) {
                (*l_652) = &g_72;

                l_655 = ((((g_171 ^ (*l_71)), &g_72) != l_651) >= p_65);
              }

              for (p_65 = 26; (p_65 == 37);
                   p_65 = safe_add_func_int32_t_s_s(p_65, 8)) {
                (*l_71) = (safe_rshift_func_uint8_t_u_s(
                    (*l_71), (l_660[0] == (void *)0)));
              }
            } else {
              int16_t l_663[3];
              uint8_t l_676 = 0UL;
              int i;
              for (i = 0; i < 3; i++)
                l_663[i] = 1L;
              for (g_115 = 11; (g_115 >= 26); ++g_115) {
                uint16_t l_664 = 0x2FD1L;
                l_664 = l_663[2];
                (*l_71) = (safe_add_func_int8_t_s_s(
                    (p_65,
                     ((((safe_div_func_int32_t_s_s(
                            (((l_669 & (safe_lshift_func_int16_t_s_u(
                                           p_65, 15))) != p_65) ==
                             (p_65 &
                              ((safe_rshift_func_int8_t_s_s(l_663[0], 5)) !=
                               (((&l_612 != (void *)0) ==
                                 (safe_div_func_int32_t_s_s(
                                     (((((*g_143) != (*g_143)) ^ g_115) <
                                       4294967295UL) >= 65528UL),
                                     g_496[5][1]))) >= p_65)))),
                            p_65)) != g_496[5][2]) &
                       0x48L) != g_20)),
                    (-3L)));
                l_676 = p_65;
                l_660[0] = g_677[6][0][4];
              }
            }


            if ((&l_71 ==
                 ((safe_sub_func_uint32_t_u_u(
                      ((safe_add_func_int16_t_s_s(g_115, p_65)) >=
                       (safe_sub_func_int16_t_s_s(
                           (((65529UL &&
                              ((*l_71) != (((*l_71), l_605) == &l_71))) ^
                             (((0xFE9FL < (*l_71)), p_65) != p_65)),
                            p_65),
                           p_65))),
                      (*l_71))),
                  (*g_143)))) {
              int32_t *l_607 = &g_171;
              if (g_7)
                goto lbl_606;
              l_608 = l_607;

            } else {
              uint16_t l_611 = 0xBBEEL;
              int32_t **l_612 = (void *)0;
              for (g_483 = 0; (g_483 >= (-7));
                   g_483 = safe_sub_func_uint8_t_u_u(g_483, 2)) {
                if (l_611)
                  break;
              }
              if (((*g_143) == l_612)) {
                uint8_t l_613[8] = {0xABL, 0xABL, 7UL, 0xABL,
                                    0xABL, 7UL, 0xABL, 0xABL};
                uint32_t l_618 = 18446744073709551615UL;
                int32_t ***l_628 = (void *)0;
                int i;
                (*l_71) = (l_613[4] < p_65);
                g_115 =
                    (p_65 <=
                     ((safe_rshift_func_uint8_t_u_s(l_613[4], 4)) ==
                      (((safe_div_func_int8_t_s_s(
                            l_618,
                            (safe_sub_func_uint8_t_u_u(
                                0xB2L,
                                ((0x6C35L &
                                  ((safe_mul_func_int16_t_s_s(
                                       ((void *)0 == (*g_143)),
                                       ((((safe_mod_func_int16_t_s_s(
                                              0xC6E6L,
                                              ((((safe_mod_func_uint32_t_u_u(
                                                     ((((((((g_20, l_613[4]) <=
                                                            p_65) &
                                                           g_115) < p_65) &&
                                                         l_613[2]) &&
                                                        0xDEE6L) >= l_618) &
                                                      l_627),
                                                     g_72)),
                                                 p_65) |
                                                g_496[1][4]),
                                               (-1L)))) < l_613[0]),
                                         g_496[2][2]) != g_483))) == g_483)) <
                                 g_7))))),
                        &g_144) != l_628)));
                for (g_72 = 5; (g_72 >= 0); g_72 -= 1) {
                  int32_t *l_629 = &g_483;
                  int32_t **l_630 = &l_71;
                  int i, j;
                  (*l_630) = l_629;

                  (*l_71) = (l_628 == &l_630);
                  if (g_496[g_72][g_72])
                    continue;
                }
                if (p_65)
                  break;
              } else {
                int16_t l_649 = 0xF921L;
                int16_t l_650 = (-5L);
                int32_t *l_651 = (void *)0;
                uint32_t l_655 = 0xF25B5010L;
                int32_t *l_660[1];
                int i;
                for (i = 0; i < 1; i++)
                  l_660[i] = &g_115;
                (*l_608) = (safe_lshift_func_uint8_t_u_u(
                    (!(((((safe_mod_func_int8_t_s_s(
                              ((safe_mod_func_int16_t_s_s(
                                   (+((safe_add_func_uint16_t_u_u(
                                          p_65,
                                          ((safe_div_func_int32_t_s_s(
                                               (((safe_sub_func_uint8_t_u_u(
                                                     (p_65 | p_65),
                                                     ((safe_sub_func_int16_t_s_s(
                                                          (safe_add_func_int16_t_s_s(
                                                              ((*g_143) !=
                                                               &l_608),
                                                              (safe_rshift_func_int16_t_s_s(
                                                                  ((void *)0 ==
                                                                   &l_605),
                                                                  2)))),
                                                          (*l_608))) >=
                                                      (((0xE48EL | 65535UL),
                                                        0xE3FBL) >=
                                                       (*l_71))))) &
                                                 (*l_71)) |
                                                g_496[3][1]),
                                               4294967286UL)),
                                           (*l_71)))) != 0x5A241DA0L)),
                                   l_649)) <= (-5L)),
                              (*l_71))),
                          g_115) < g_171),
                        0x02EFBA42L) < p_65)),
                    p_65));
                if (l_650) {
                  int32_t **l_652 = &l_608;
                  (*l_652) = (g_20, l_651);

                  for (g_115 = (-30); (g_115 == 12); g_115++) {
                    (*l_652) = &g_72;

                    l_655 = ((((g_171 ^ (*l_71)), &g_72) != l_651) >= p_65);
                  }

                  for (p_65 = 26; (p_65 == 37);
                       p_65 = safe_add_func_int32_t_s_s(p_65, 8)) {
                    (*l_71) = (safe_rshift_func_uint8_t_u_s(
                        (*l_71), (l_660[0] == (void *)0)));
                  }
                } else {
                  int16_t l_663[3];
                  uint8_t l_676 = 0UL;
                  int i;
                  for (i = 0; i < 3; i++)
                    l_663[i] = 1L;
                  for (g_115 = 11; (g_115 >= 26); ++g_115) {
                    uint16_t l_664 = 0x2FD1L;
                    l_664 = l_663[2];
                    (*l_71) = (safe_add_func_int8_t_s_s(
                        (p_65,
                         ((((safe_div_func_int32_t_s_s(
                                (((l_669 & (safe_lshift_func_int16_t_s_u(
                                               p_65, 15))) != p_65) ==
                                 (p_65 &
                                  ((safe_rshift_func_int8_t_s_s(l_663[0], 5)) !=
                                   (((&l_612 != (void *)0) ==
                                     (safe_div_func_int32_t_s_s(
                                         (((((*g_143) != (*g_143)) ^ g_115) <
                                           4294967295UL) >= 65528UL),
                                         g_496[5][1]))) >= p_65)))),
                                p_65)) != g_496[5][2]) &
                           0x48L) != g_20)),
                        (-3L)));
                    l_676 = p_65;
                    l_660[0] = g_677[6][0][4];
                  }
                }


                if (p_65)
                  continue;
              }

            }
          }

          for (p_65 = 26; (p_65 == 37);
               p_65 = safe_add_func_int32_t_s_s(p_65, 8)) {
          }
          for (p_65 = 26; (p_65 == 37);
               p_65 = safe_add_func_int32_t_s_s(p_65, 8)) {
            (*l_71) = (safe_rshift_func_uint8_t_u_s((*l_71),
                                                    (l_660[0] == (void *)0)));
          }

        } else {
          int16_t l_663[3];
          uint8_t l_676 = 0UL;
          int i;
          for (i = 0; i < 3; i++) {
            l_663[i] = 1L;
            if (l_650) {
              int32_t **l_652 = &l_608;
              (*l_652) = (g_20, l_651);

              for (g_115 = (-30); (g_115 == 12); g_115++) {
                (*l_652) = &g_72;

                l_655 = ((((g_171 ^ (*l_71)), &g_72) != l_651) >= p_65);
              }

              for (p_65 = 26; (p_65 == 37);
                   p_65 = safe_add_func_int32_t_s_s(p_65, 8)) {
                (*l_71) = (safe_rshift_func_uint8_t_u_s(
                    (*l_71), (l_660[0] == (void *)0)));
              }
            } else {
              int16_t l_663[3];
              uint8_t l_676 = 0UL;
              int i;
              for (i = 0; i < 3; i++)
                l_663[i] = 1L;
              for (g_115 = 11; (g_115 >= 26); ++g_115) {
                uint16_t l_664 = 0x2FD1L;
                l_664 = l_663[2];
                (*l_71) = (safe_add_func_int8_t_s_s(
                    (p_65,
                     ((((safe_div_func_int32_t_s_s(
                            (((l_669 & (safe_lshift_func_int16_t_s_u(
                                           p_65, 15))) != p_65) ==
                             (p_65 &
                              ((safe_rshift_func_int8_t_s_s(l_663[0], 5)) !=
                               (((&l_612 != (void *)0) ==
                                 (safe_div_func_int32_t_s_s(
                                     (((((*g_143) != (*g_143)) ^ g_115) <
                                       4294967295UL) >= 65528UL),
                                     g_496[5][1]))) >= p_65)))),
                            p_65)) != g_496[5][2]) &
                       0x48L) != g_20)),
                    (-3L)));
                l_676 = p_65;
                l_660[0] = g_677[6][0][4];
              }
            }

            {
              int16_t l_663[3];
              uint8_t l_676 = 0UL;
              int i;
              for (i = 0; i < 3; i++)
                l_663[i] = 1L;
              for (g_115 = 11; (g_115 >= 26); ++g_115) {
                uint16_t l_664 = 0x2FD1L;
                l_664 = l_663[2];
                (*l_71) = (safe_add_func_int8_t_s_s(
                    (p_65,
                     ((((safe_div_func_int32_t_s_s(
                            (((l_669 & (safe_lshift_func_int16_t_s_u(
                                           p_65, 15))) != p_65) ==
                             (p_65 &
                              ((safe_rshift_func_int8_t_s_s(l_663[0], 5)) !=
                               (((&l_612 != (void *)0) ==
                                 (safe_div_func_int32_t_s_s(
                                     (((((*g_143) != (*g_143)) ^ g_115) <
                                       4294967295UL) >= 65528UL),
                                     g_496[5][1]))) >= p_65)))),
                            p_65)) != g_496[5][2]) &
                       0x48L) != g_20)),
                    (-3L)));
                l_676 = p_65;
                l_660[0] = g_677[6][0][4];
              }
            }
          }
        }
        {
          if (l_611)
            break;
        }


        if (p_65)
          continue;
      }

    }
    if ((&l_71 ==
         ((safe_sub_func_uint32_t_u_u(
              ((safe_add_func_int16_t_s_s(g_115, p_65)) >=
               (safe_sub_func_int16_t_s_s(
                   (((65529UL && ((*l_71) != (((*l_71), l_605) == &l_71))) ^
                     (((0xFE9FL < (*l_71)), p_65) != p_65)),
                    p_65),
                   p_65))),
              (*l_71))),
          (*g_143)))) {
      int32_t *l_607 = &g_171;
      if (g_7)
        goto lbl_606;
      l_608 = l_607;

    } else {
      uint16_t l_611 = 0xBBEEL;
      int32_t **l_612 = (void *)0;
      for (g_483 = 0; (g_483 >= (-7));
           g_483 = safe_sub_func_uint8_t_u_u(g_483, 2)) {
        if (l_611)
          break;
      }
      if (((*g_143) == l_612)) {
        uint8_t l_613[8] = {0xABL, 0xABL, 7UL, 0xABL, 0xABL, 7UL, 0xABL, 0xABL};
        uint32_t l_618 = 18446744073709551615UL;
        int32_t ***l_628 = (void *)0;
        int i;
        (*l_71) = (l_613[4] < p_65);
        g_115 =
            (p_65 <=
             ((safe_rshift_func_uint8_t_u_s(l_613[4], 4)) ==
              (((safe_div_func_int8_t_s_s(
                    l_618,
                    (safe_sub_func_uint8_t_u_u(
                        0xB2L,
                        ((0x6C35L &
                          ((safe_mul_func_int16_t_s_s(
                               ((void *)0 == (*g_143)),
                               ((((safe_mod_func_int16_t_s_s(
                                      0xC6E6L,
                                      ((((safe_mod_func_uint32_t_u_u(
                                             ((((((((g_20, l_613[4]) <= p_65) &
                                                   g_115) < p_65) &&
                                                 l_613[2]) &&
                                                0xDEE6L) >= l_618) &
                                              l_627),
                                             g_72)),
                                         p_65) |
                                        g_496[1][4]),
                                       (-1L)))) < l_613[0]),
                                 g_496[2][2]) != g_483))) == g_483)) < g_7))))),
                &g_144) != l_628)));
        for (g_72 = 5; (g_72 >= 0); g_72 -= 1) {
          int32_t *l_629 = &g_483;
          int32_t **l_630 = &l_71;
          int i, j;
          (*l_630) = l_629;

          (*l_71) = (l_628 == &l_630);
          if (g_496[g_72][g_72])
            continue;
        }
        if (p_65)
          break;
      } else {
        int16_t l_649 = 0xF921L;
        int16_t l_650 = (-5L);
        int32_t *l_651 = (void *)0;
        uint32_t l_655 = 0xF25B5010L;
        int32_t *l_660[1];
        int i;
        for (i = 0; i < 1; i++)
          l_660[i] = &g_115;
        (*l_608) = (safe_lshift_func_uint8_t_u_u(
            (!(((((safe_mod_func_int8_t_s_s(
                      ((safe_mod_func_int16_t_s_s(
                           (+((safe_add_func_uint16_t_u_u(
                                  p_65,
                                  ((safe_div_func_int32_t_s_s(
                                       (((safe_sub_func_uint8_t_u_u(
                                             (p_65 | p_65),
                                             ((safe_sub_func_int16_t_s_s(
                                                  (safe_add_func_int16_t_s_s(
                                                      ((*g_143) != &l_608),
                                                      (safe_rshift_func_int16_t_s_s(
                                                          ((void *)0 == &l_605),
                                                          2)))),
                                                  (*l_608))) >=
                                              (((0xE48EL | 65535UL), 0xE3FBL) >=
                                               (*l_71))))) &
                                         (*l_71)) |
                                        g_496[3][1]),
                                       4294967286UL)),
                                   (*l_71)))) != 0x5A241DA0L)),
                           l_649)) <= (-5L)),
                      (*l_71))),
                  g_115) < g_171),
                0x02EFBA42L) < p_65)),
            p_65));
        if (l_650) {
          int32_t **l_652 = &l_608;
          (*l_652) = (g_20, l_651);

          for (g_115 = (-30); (g_115 == 12); g_115++) {
            (*l_652) = &g_72;

            l_655 = ((((g_171 ^ (*l_71)), &g_72) != l_651) >= p_65);
          }

          for (p_65 = 26; (p_65 == 37);
               p_65 = safe_add_func_int32_t_s_s(p_65, 8)) {
            (*l_71) = (safe_rshift_func_uint8_t_u_s((*l_71),
                                                    (l_660[0] == (void *)0)));
          }
        } else {
          int16_t l_663[3];
          uint8_t l_676 = 0UL;
          int i;
          for (i = 0; i < 3; i++)
            l_663[i] = 1L;
          for (g_115 = 11; (g_115 >= 26); ++g_115) {
            uint16_t l_664 = 0x2FD1L;
            l_664 = l_663[2];
            (*l_71) = (safe_add_func_int8_t_s_s(
                (p_65,
                 ((((safe_div_func_int32_t_s_s(
                        (((l_669 & (safe_lshift_func_int16_t_s_u(p_65, 15))) !=
                          p_65) ==
                         (p_65 & ((safe_rshift_func_int8_t_s_s(l_663[0], 5)) !=
                                  (((&l_612 != (void *)0) ==
                                    (safe_div_func_int32_t_s_s(
                                        (((((*g_143) != (*g_143)) ^ g_115) <
                                          4294967295UL) >= 65528UL),
                                        g_496[5][1]))) >= p_65)))),
                        p_65)) != g_496[5][2]) &
                   0x48L) != g_20)),
                (-3L)));
            l_676 = p_65;
            l_660[0] = g_677[6][0][4];
          }
        }


        if (p_65)
          continue;
      }

    }

  }
  (*l_71) = g_7;

  return p_65;
}

static int32_t func_73(uint32_t p_74) {
  int32_t *l_75 = (void *)0;
  int32_t *l_76 = &g_72;
  int32_t **l_78[5][2] = {{&l_75, &l_76},
                          {&l_75, &l_76},
                          {&l_75, &l_76},
                          {&l_75, &l_76},
                          {&l_75, &l_76}};
  int32_t ***l_77 = &l_78[3][1];
  int32_t *l_88 = &g_72;
  uint32_t l_349[1][2];
  int32_t *l_428 = &g_115;
  int16_t l_551 = 0x603EL;
  int8_t l_555[8];
  int i, j;
  for (i = 0; i < 1; i++) {
    for (j = 0; j < 2; j++)

    {
      for (i = 0; i < 1; i++) {
        for (j = 0; j < 2; j++)
          l_349[i][j] = 4UL;
      }
    }

    {
      for (j = 0; j < 2; j++)
        l_349[i][j] = 4UL;
    }
  }

  {
    for (j = 0; j < 2; j++)
      l_349[i][j] = 4UL;
  }

  (*l_76) = (p_74, (l_75 != &g_7));
  if (func_13((l_77 != &l_78[1][0]))) {
    int32_t *l_79 = (void *)0;
    uint32_t l_107[9][8][3] = {{{0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL}},
                               {{0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL}},
                               {{0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL}},
                               {{0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL}},
                               {{0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL}},
                               {{0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL}},
                               {{0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL}},
                               {{0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL}},
                               {{0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL},
                                {0xBD50C841L, 4294967295UL, 0UL}}};
    int32_t ***l_360 = &l_78[2][1];
    int16_t l_426 = 2L;
    int32_t *l_445 = &g_171;
    int8_t l_450 = 0x0BL;
    uint32_t l_477[7] = {0x40216707L, 0x40216707L, 0UL, 0x40216707L,
                         0x40216707L, 0UL, 0x40216707L};
    int8_t l_553 = 5L;
    int i, j, k;
    g_10 = l_79;
    for (i = 0; i < 8; i++)
      l_555[i] = (-2L);

  } else {
    uint16_t l_560[5];
    int i;
    for (i = 0; i < 5; i++) {
      l_560[i] = 0xAB71L;
      {
        int32_t *l_79 = (void *)0;
        uint32_t l_107[9][8][3] = {{{0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL}},
                                   {{0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL}},
                                   {{0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL}},
                                   {{0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL}},
                                   {{0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL}},
                                   {{0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL}},
                                   {{0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL}},
                                   {{0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL}},
                                   {{0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL},
                                    {0xBD50C841L, 4294967295UL, 0UL}}};
        int32_t ***l_360 = &l_78[2][1];
        int16_t l_426 = 2L;
        int32_t *l_445 = &g_171;
        int8_t l_450 = 0x0BL;
        uint32_t l_477[7] = {0x40216707L, 0x40216707L, 0UL, 0x40216707L,
                             0x40216707L, 0UL, 0x40216707L};
        int8_t l_553 = 5L;
        int i, j, k;
        g_10 = l_79;

      }
    }

    for (g_483 = 0; (g_483 >= 0); g_483 -= 1) {
      return l_560[2];
    }
  }
  {
    int32_t *l_75 = (void *)0;
    int32_t *l_76 = &g_72;
    int32_t **l_78[5][2] = {{&l_75, &l_76},
                            {&l_75, &l_76},
                            {&l_75, &l_76},
                            {&l_75, &l_76},
                            {&l_75, &l_76}};
    int32_t ***l_77 = &l_78[3][1];
    int32_t *l_88 = &g_72;
    uint32_t l_349[1][2];
    int32_t *l_428 = &g_115;
    int16_t l_551 = 0x603EL;
    int8_t l_555[8];
    int i, j;
    for (i = 0; i < 1; i++) {
      for (j = 0; j < 2; j++)
        l_349[i][j] = 4UL;
    }
    for (i = 0; i < 8; i++)
      l_555[i] = (-2L);
    (*l_76) = (p_74, (l_75 != &g_7));
    if (func_13((l_77 != &l_78[1][0]))) {
      int32_t *l_79 = (void *)0;
      uint32_t l_107[9][8][3] = {{{0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL}},
                                 {{0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL}},
                                 {{0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL}},
                                 {{0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL}},
                                 {{0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL}},
                                 {{0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL}},
                                 {{0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL}},
                                 {{0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL}},
                                 {{0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL},
                                  {0xBD50C841L, 4294967295UL, 0UL}}};
      int32_t ***l_360 = &l_78[2][1];
      int16_t l_426 = 2L;
      int32_t *l_445 = &g_171;
      int8_t l_450 = 0x0BL;
      uint32_t l_477[7] = {0x40216707L, 0x40216707L, 0UL, 0x40216707L,
                           0x40216707L, 0UL, 0x40216707L};
      int8_t l_553 = 5L;
      int i, j, k;
      g_10 = l_79;

    } else {
      uint16_t l_560[5];
      int i;
      for (i = 0; i < 5; i++)
        l_560[i] = 0xAB71L;
      for (g_483 = 0; (g_483 >= 0); g_483 -= 1) {
        return l_560[2];
      }
    }
    (**l_77) = (void *)0;

    return p_74;
  }

  (**l_77) = (void *)0;
  (*l_76) = (p_74, (l_75 != &g_7));

  return p_74;
}

static int16_t func_82(int32_t *p_83, uint8_t p_84, int32_t **p_85,
                       uint32_t p_86, int32_t **p_87) {
  int32_t **l_108 = &g_10;
  int32_t ***l_109 = &l_108;
  int32_t **l_137 = (void *)0;
  int8_t l_168[1][4];
  int32_t l_194 = 0xE1ED03BDL;
  int32_t *l_217 = &g_7;
  int32_t *l_220 = &g_7;
  int32_t l_233 = 0x5D77D440L;
  int i, j;

  (*l_108) = (*p_87);
  if (g_10 == &g_72 || g_10 == 0)
    ;

  return g_7;
}

static int32_t func_93(int32_t **p_94, int32_t *p_95, int32_t *p_96) {
  int32_t l_97 = 0xF5D7AD18L;
  int32_t *l_106 = &g_72;

  {
    int32_t l_97 = 0xF5D7AD18L;
    int32_t *l_106 = &g_72;
    (*l_106) =
        ((((l_97,
            (((safe_sub_func_int16_t_s_s(
                  (g_72 >=
                   (g_7 ||
                    (g_72 <
                     ((((void *)0 == &g_7) <= 4294967295UL),
                      (((safe_mod_func_int32_t_s_s(
                            ((g_72 || (safe_rshift_func_uint8_t_u_u(l_97, 5))),
                             g_7),
                            g_55)),
                        (void *)0) != &g_7))))),
                  l_97)) != g_20) |
             0x997BD6D7L)) <= l_97),
          (void *)0) == &g_7);
    return g_72;
  }

  return g_72;
}

int main(void) {
  int i, j, k;
  int print_hash_value = 0;
  crc32_gentab();
  func_1();
  transparent_crc(g_7, "g_7", print_hash_value);
  transparent_crc(g_20, "g_20", print_hash_value);
  transparent_crc(g_55, "g_55", print_hash_value);
  transparent_crc(g_72, "g_72", print_hash_value);
  for (i = 0; i < 5; i++) {
    transparent_crc(g_114[i], "g_114[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_115, "g_115", print_hash_value);
  transparent_crc(g_171, "g_171", print_hash_value);
  transparent_crc(g_483, "g_483", print_hash_value);
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 6; j++) {
      transparent_crc(g_496[i][j], "g_496[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_798, "g_798", print_hash_value);
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 2; j++) {
      for (k = 0; k < 7; k++) {
        transparent_crc(g_820[i][j][k], "g_820[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}

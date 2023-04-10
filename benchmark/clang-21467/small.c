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

static int64_t(safe_unary_minus_func_int64_t_s)(int64_t si) {

  return

      (si == (-9223372036854775807LL - 1)) ? ((si)) :

                                           -si;
}

static int64_t(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((9223372036854775807LL) - si2))) ||
       ((si1 < 0) && (si2 < 0) && (si1 < ((-9223372036854775807LL - 1) - si2))))
          ? ((si1))
          :

          (si1 + si2);
}

static int64_t(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      (((si1 ^ si2) &
        (((si1 ^ ((si1 ^ si2) & (~(9223372036854775807LL)))) - si2) ^ si2)) < 0)
          ? ((si1))
          :

          (si1 - si2);
}

static int64_t(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      (((si1 > 0) && (si2 > 0) && (si1 > ((9223372036854775807LL) / si2))) ||
       ((si1 > 0) && (si2 <= 0) &&
        (si2 < ((-9223372036854775807LL - 1) / si1))) ||
       ((si1 <= 0) && (si2 > 0) &&
        (si1 < ((-9223372036854775807LL - 1) / si2))) ||
       ((si1 <= 0) && (si2 <= 0) && (si1 != 0) &&
        (si2 < ((9223372036854775807LL) / si1))))
          ? ((si1))
          :

          si1 * si2;
}

static int64_t(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      ((si2 == 0) || ((si1 == (-9223372036854775807LL - 1)) && (si2 == (-1))))
          ? ((si1))
          :

          (si1 % si2);
}

static int64_t(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return

      ((si2 == 0) || ((si1 == (-9223372036854775807LL - 1)) && (si2 == (-1))))
          ? ((si1))
          :

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

struct S0 {
  const int32_t f0;
  signed f1 : 10;
  unsigned f2 : 22;
  const unsigned : 0;
  signed f3 : 5;
  const signed f4 : 29;
  unsigned f5 : 10;
  signed f6 : 27;
  unsigned : 0;
  unsigned f7 : 8;
};

struct S1 {
  signed f0 : 27;
  int64_t f1;
  uint32_t f2;
  const unsigned f3 : 18;
};

static uint8_t g_18 = 1UL;
static uint32_t g_93 = 0x4D75DB0CL;
static struct S1 g_98 = {9369, -2L, 1UL, 366};
static int64_t g_103 = 0x2714BD4865626A28LL;
static uint64_t g_104 = 18446744073709551615UL;
static uint32_t g_119 = 4UL;
static uint32_t g_204 = 4294967288UL;
static uint8_t g_207 = 1UL;
static int32_t g_217 = 0x69674BCFL;
static int8_t g_220 = 2L;
static int64_t g_276 = 0x7966B2488C446EDBLL;
static uint8_t g_279 = 0x77L;
static int32_t g_281 = 0x5E1E2EF9L;
static struct S0 g_307 = {0xB5D3E5C6L, 7, 62, -2, -7048, 26, 10775, 3};
static int8_t g_360 = 0xA4L;
static const int8_t g_363 = 0L;
static uint8_t g_417 = 249UL;
static const uint32_t g_443 = 18446744073709551606UL;
static int16_t g_481 = 0x424AL;
static int32_t g_483 = 0x115D8315L;
static int16_t g_486 = (-1L);
static uint8_t g_488 = 0x68L;
static uint32_t g_628 = 1UL;
static int16_t g_631 = 1L;
static uint8_t g_701 = 255UL;
static int64_t g_758 = 9L;
static uint16_t g_946 = 0xCAF7L;
static int32_t g_1054 = (-8L);
static uint32_t g_1066 = 9UL;
static const int16_t g_1338 = (-10L);
static uint32_t g_1814 = 18446744073709551615UL;
static int32_t g_1846 = 1L;
static const int16_t g_1860 = (-1L);

static int32_t func_1(void);
static uint8_t func_25(uint32_t p_26, uint16_t p_27, int16_t p_28);
static uint32_t func_31(int64_t p_32, uint32_t p_33, uint8_t p_34,
                        uint32_t p_35);
static uint8_t func_46(uint16_t p_47);
static uint8_t func_48(int64_t p_49, const int8_t p_50, int8_t p_51);
static int64_t func_58(const uint64_t p_59, const uint8_t p_60, uint32_t p_61);
static int16_t func_64(const uint32_t p_65, int64_t p_66, uint32_t p_67,
                       int64_t p_68);
static uint64_t func_109(int16_t p_110, int16_t p_111, int16_t p_112,
                         const int32_t p_113, uint16_t p_114);
static int8_t func_134(int16_t p_135, int16_t p_136, uint32_t p_137,
                       int32_t p_138, uint64_t p_139);
static uint16_t func_146(uint16_t p_147, int32_t p_148);
static int32_t func_1(void) {
  uint8_t l_12 = 247UL;
  const int32_t l_13 = 0x82AA9DADL;
  int32_t l_19 = 0x98AB79AEL;
  int32_t l_20 = (-1L);
  int32_t l_1952 = (-6L);
  int64_t l_1953 = 7L;
  int16_t l_1954 = 0L;
  int32_t l_1955 = (-6L);
  int32_t l_1956 = 0xAE3BC6E9L;
  l_1956 =
      ((safe_rshift_func_int16_t_s_u(
           (safe_mod_func_int16_t_s_s(
               (safe_sub_func_int8_t_s_s(
                   (safe_mul_func_int8_t_s_s(
                       (((safe_rshift_func_int8_t_s_u(
                             (l_1955 =
                                  (((l_12,
                                     (l_13 ^
                                      ((((safe_lshift_func_int16_t_s_u(
                                             (((((l_19 = g_18) ==
                                                 ((l_20 ^=
                                                   18446744073709551608UL) ==
                                                  (((((safe_lshift_func_int8_t_s_s(
                                                          (((safe_lshift_func_uint8_t_u_u(
                                                                (l_1952 = func_25(
                                                                     g_18,
                                                                     (safe_sub_func_uint8_t_u_u(
                                                                         247UL,
                                                                         0x11L)),
                                                                     ((func_31(
                                                                           ((((g_18,
                                                                               ((safe_mod_func_uint32_t_u_u(
                                                                                    1UL,
                                                                                    g_18)) &&
                                                                                g_18)) &
                                                                              l_12),
                                                                             0x3D8BL) <=
                                                                            0x5E13L),
                                                                           g_18,
                                                                           g_18,
                                                                           g_18) >=
                                                                       g_1338),
                                                                      0xB022L))),
                                                                g_1814)) &
                                                            l_12),
                                                           (-1L)),
                                                          l_1953)) != l_12),
                                                     g_628) &&
                                                    (-1L)) < 6L))) ||
                                                1L),
                                               g_98),
                                              7L),
                                             g_307.f0)) == 0x18L) <
                                        0x91682CECL),
                                       l_1954))) &
                                    l_1953),
                                   0x34L)),
                             2)) >= l_13) ^
                        g_1814),
                       g_98.f3)),
                   l_1953)),
               g_443)),
           15)) != l_1953);
  g_307.f3 =
      (((!(g_488 = (~g_98.f1))) || 9L) &&
       (safe_mod_func_uint64_t_u_u(
           ((((safe_mul_func_int16_t_s_s(0x5046L, g_98.f1)) <= l_1955) >
             l_19) ||
            (g_1860 != (l_19 |= (safe_div_func_int8_t_s_s(
                            ((l_1955 = (+(safe_sub_func_uint32_t_u_u(
                                  (+(safe_rshift_func_int8_t_s_s(
                                      (l_20 |= l_1954),
                                      (safe_div_func_int8_t_s_s(1L, g_1846))))),
                                  l_1956)))) &
                             g_204),
                            g_307.f5))))),
           g_758)));
  return g_486;
}

static uint8_t func_25(uint32_t p_26, uint16_t p_27, int16_t p_28) {
  int32_t l_1714 = 1L;
  int32_t l_1754 = 0x1CF10B6AL;
  int32_t l_1845 = 0x200535A8L;
  int64_t l_1922 = 0x7E7DD27881D1DA92LL;
  int32_t l_1950 = 0xE5F23249L;
  uint8_t l_1951 = 0x1CL;
  for (g_946 = (-16); (g_946 < 48); ++g_946) {
    uint32_t l_1738 = 0x32EB4178L;
    uint32_t l_1816 = 18446744073709551615UL;
    int8_t l_1851 = (-10L);
    uint32_t l_1867 = 4294967295UL;
    int32_t l_1868 = 1L;
    int32_t l_1869 = (-1L);
    struct S0 l_1878 = {0x8676A15EL, 4, 1188, -3, 374, 3, -6279, 9};
    uint64_t l_1895 = 18446744073709551613UL;
    if ((safe_mul_func_uint8_t_u_u(l_1714, p_27))) {
      int16_t l_1729 = 0L;
      const int32_t l_1753 = 0xE00A8097L;
      int8_t l_1787 = 0xF1L;
      int32_t l_1848 = 0L;
      if (((((((safe_rshift_func_int16_t_s_u ((safe_sub_func_int64_t_s_s ((safe_div_func_uint32_t_u_u ((safe_mul_func_int16_t_s_s (l_1714, ((((safe_lshift_func_uint16_t_u_s (0x390DL, ((safe_rshift_func_uint16_t_u_s ((((safe_mod_func_uint8_t_u_u ((((l_1729 = (g_217 |= 0xDFC7F084L)) >= p_28) ^ (+(l_1754 = (0x93L <= (g_220 = (safe_mod_func_int8_t_s_s (((((safe_rshift_func_uint8_t_u_s ((safe_mul_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_s (((l_1714 || 255UL) == (l_1738 = p_27)), 6)) < (safe_mul_func_uint8_t_u_u ((safe_sub_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u ((((safe_sub_func_uint64_t_u_u ((safe_add_func_uint16_t_u_u ((safe_div_func_int64_t_s_s ((((safe_lshift_func_int8_t_s_u ((((0x0635L && 0xCB98L) >= p_27) >= 0xE48EF5508BAF3C6DLL), 1)) > p_26), 0xB31966A343A81CA7LL), l_1714)), p_28)), 0UL)) < 0x8343L) && g_104), 3)), p_26)), l_1714))), (-1L))), 6)), p_26), 1L) | p_27), l_1753))))))), 255UL)) == g_701) ^ p_27), 11)) <= l_1753))) != 0xC20610E7L) >= 0UL) | g_98.f2))), 0x714641C3L)), 0x2FF84D128D700EEDLL)), g_360)) || p_28) > g_483), g_363), 0x0C723813AD03E75ELL) < p_26))
      {
        l_1754 = (-8L);
        if ((safe_mul_func_uint8_t_u_u(l_1714, p_27))) {
          int16_t l_1729 = 0L;
          const int32_t l_1753 = 0xE00A8097L;
          int8_t l_1787 = 0xF1L;
          int32_t l_1848 = 0L;
      if (((((((safe_rshift_func_int16_t_s_u ((safe_sub_func_int64_t_s_s ((safe_div_func_uint32_t_u_u ((safe_mul_func_int16_t_s_s (l_1714, ((((safe_lshift_func_uint16_t_u_s (0x390DL, ((safe_rshift_func_uint16_t_u_s ((((safe_mod_func_uint8_t_u_u ((((l_1729 = (g_217 |= 0xDFC7F084L)) >= p_28) ^ (+(l_1754 = (0x93L <= (g_220 = (safe_mod_func_int8_t_s_s (((((safe_rshift_func_uint8_t_u_s ((safe_mul_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_s (((l_1714 || 255UL) == (l_1738 = p_27)), 6)) < (safe_mul_func_uint8_t_u_u ((safe_sub_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u ((((safe_sub_func_uint64_t_u_u ((safe_add_func_uint16_t_u_u ((safe_div_func_int64_t_s_s ((((safe_lshift_func_int8_t_s_u ((((0x0635L && 0xCB98L) >= p_27) >= 0xE48EF5508BAF3C6DLL), 1)) > p_26), 0xB31966A343A81CA7LL), l_1714)), p_28)), 0UL)) < 0x8343L) && g_104), 3)), p_26)), l_1714))), (-1L))), 6)), p_26), 1L) | p_27), l_1753))))))), 255UL)) == g_701) ^ p_27), 11)) <= l_1753))) != 0xC20610E7L) >= 0UL) | g_98.f2))), 0x714641C3L)), 0x2FF84D128D700EEDLL)), g_360)) || p_28) > g_483), g_363), 0x0C723813AD03E75ELL) < p_26))
      {
        l_1754 = (-8L);
      } else {
        uint8_t l_1777 = 0UL;
        uint32_t l_1815 = 0x240146FDL;
        for (l_1754 = (-29); (l_1754 <= 11); l_1754++) {
          int8_t l_1775 = 0x06L;
          uint8_t l_1776 = 0x4AL;
          int8_t l_1778 = 0x4AL;
          int32_t l_1779 = 0x65FB2E90L;
          if (((((l_1779 = (safe_rshift_func_uint8_t_u_s(
                      (((safe_sub_func_int32_t_s_s(
                            (safe_add_func_uint16_t_u_u(
                                ((safe_div_func_uint32_t_u_u(
                                     g_1338,
                                     (0xA792414F4DF79A93LL &&
                                      ((((~(p_26,
                                            (g_360 ^=
                                             ((safe_sub_func_int32_t_s_s(
                                                  l_1738,
                                                  (((safe_rshift_func_uint8_t_u_s(
                                                        6UL,
                                                        (((safe_mod_func_int32_t_s_s(
                                                              (((safe_rshift_func_uint8_t_u_u(
                                                                    (safe_sub_func_uint16_t_u_u(
                                                                        (p_26 ==
                                                                         (p_27 >=
                                                                          (l_1776 &=
                                                                           ((l_1775 =
                                                                                 (g_98.f3 >
                                                                                  (l_1738 ||
                                                                                   g_363))) !=
                                                                            l_1754)))),
                                                                        l_1729)),
                                                                    3)) >
                                                                p_28) ||
                                                               p_27),
                                                              p_26)) >=
                                                          0x1AB9L),
                                                         g_104))) >
                                                    0xCAB1D5D2C1591FE0LL),
                                                   l_1714))),
                                              l_1777)))) != 0xF1L) == l_1778) >=
                                       p_26)))) ^
                                 g_758),
                                g_103)),
                            g_204)) ||
                        4UL) <= p_27),
                      3))) < g_1054) <= 18446744073709551613UL) <= l_1777)) {
            int64_t l_1780 = 0x09A642E82F9C7B25LL;
            l_1787 |=
                (18446744073709551612UL <=
                 ((l_1780 &= l_1754) &&
                  ((safe_mul_func_uint8_t_u_u(
                       l_1777,
                       (((safe_add_func_uint32_t_u_u(
                             4294967286UL,
                             (((((safe_unary_minus_func_int8_t_s(l_1777)) <
                                 (l_1729 == (!(safe_unary_minus_func_int8_t_s((
                                                (p_27 < p_27) &&
                                                (4294967295UL <= g_488))))))) ==
                                0x0D36F576L) <= l_1780) < l_1777))) ==
                         0xD13427715DB54472LL) < p_27))) >= 0x2F0365FDL)));
            if (p_27)
              break;
            l_1779 =
                ((((safe_mod_func_int32_t_s_s(
                       (safe_lshift_func_int8_t_s_s(
                           ((p_27 = (safe_rshift_func_uint16_t_u_s(
                                 (safe_lshift_func_uint16_t_u_s(
                                     ((l_1780 >=
                                       (safe_mul_func_int8_t_s_s(
                                           (((safe_add_func_int32_t_s_s(
                                                 (((safe_add_func_int8_t_s_s(
                                                       (g_443,
                                                        ((g_279 =
                                                              ((safe_mod_func_int32_t_s_s(
                                                                   (safe_mod_func_int16_t_s_s(
                                                                       (!(((l_1777 ==
                                                                            (l_1778,
                                                                             (0xE69107A0868FB16CLL !=
                                                                              ((safe_mul_func_uint8_t_u_u(
                                                                                   (safe_div_func_int64_t_s_s(
                                                                                       l_1729,
                                                                                       0x98D0D10A6F937A31LL)),
                                                                                   (~((safe_rshift_func_uint8_t_u_u(
                                                                                          ((safe_mul_func_uint8_t_u_u(
                                                                                               g_207,
                                                                                               (g_307
                                                                                                    .f2 ^
                                                                                                l_1738))) |
                                                                                           g_1338),
                                                                                          2)) >=
                                                                                      4294967286UL)))) &&
                                                                               l_1753)))) <=
                                                                           9L),
                                                                          0x0379L)),
                                                                       g_1814)),
                                                                   l_1780)),
                                                               0xF9L)) ^
                                                         0x3EL)),
                                                       l_1815)) > (-1L)) <=
                                                  l_1738),
                                                 l_1816)) == p_26) &
                                            g_93),
                                           g_276))),
                                      0xB1FAL),
                                     14)),
                                 13))) &&
                            0L),
                           g_276)),
                       p_26)) &&
                   0x2B41L) &&
                  l_1776) &&
                 l_1780);
          } else {
            int32_t l_1823 = 0xCB59B68DL;
            int32_t l_1830 = 0x3A92E13EL;
            uint64_t l_1847 = 0x7DA90B982AC6555DLL;
            l_1847 =
                ((safe_add_func_uint32_t_u_u(
                     (g_207 |
                      (g_279 |= (safe_rshift_func_int8_t_s_u(
                           ((p_27--) |
                            ((((((l_1823 >=
                                  ((safe_rshift_func_int8_t_s_u(
                                       (g_1846 =
                                            ((safe_lshift_func_int8_t_s_s(
                                                 (g_220 = g_307.f0),
                                                 g_98.f0)) <=
                                             (0xD2L ^
                                              (g_360 =
                                                   (((((safe_rshift_func_int8_t_s_u(
                                                           (l_1830 ^= 0xB3L),
                                                           (safe_div_func_uint8_t_u_u(
                                                               (safe_add_func_int32_t_s_s(
                                                                   0x799CD25CL,
                                                                   (l_1845 &=
                                                                    (safe_lshift_func_uint16_t_u_s(
                                                                        ((safe_mod_func_int16_t_s_s(
                                                                             ((safe_sub_func_int16_t_s_s(
                                                                                  0x230EL,
                                                                                  (safe_rshift_func_uint8_t_u_u(
                                                                                      (safe_mod_func_int16_t_s_s(
                                                                                          ((p_26 >=
                                                                                            p_28) <
                                                                                           g_307
                                                                                               .f7),
                                                                                          1UL)),
                                                                                      g_307
                                                                                          .f7)))),
                                                                              p_28),
                                                                             l_1738)),
                                                                         p_26),
                                                                        2))))),
                                                               p_28)))) &
                                                       g_631) |
                                                      1L) &&
                                                     p_26),
                                                    p_28))))),
                                       4)) >= 1UL)) >= l_1787),
                                0x41304B91L) >= p_26),
                              g_488) > g_443)),
                           l_1775)))),
                     4294967292UL)) &&
                 l_1830);
          }
          g_98.f0 = (l_1848 |= l_1776);
          l_1848 =
              ((l_1851 = (safe_rshift_func_int8_t_s_s(g_204, 3))) !=
               ((safe_mul_func_int8_t_s_s(
                    ((~(!l_1777)) >=
                     (g_631 |= (safe_sub_func_int16_t_s_s(
                          ((-5L) >
                           (g_307.f6 <
                            (!(((7UL ^ (safe_lshift_func_uint8_t_u_u(1UL, 6))) >
                                ((safe_sub_func_uint64_t_u_u(
                                     ((g_758 || g_486) || p_26), g_701)) ||
                                 g_276)) &
                               g_204)))),
                          g_1860)))),
                    l_1778)) &&
                0x656D4D7CL));
        }
        l_1754 |= g_18;
      }
      l_1754 = (p_26 != l_1851);
        } else {
          return g_1054;
        }

      } else {
        uint8_t l_1777 = 0UL;
        uint32_t l_1815 = 0x240146FDL;
        for (l_1754 = (-29); (l_1754 <= 11); l_1754++) {
          int8_t l_1775 = 0x06L;
          uint8_t l_1776 = 0x4AL;
          int8_t l_1778 = 0x4AL;
          int32_t l_1779 = 0x65FB2E90L;

          {
            int8_t l_1775 = 0x06L;
            uint8_t l_1776 = 0x4AL;
            int8_t l_1778 = 0x4AL;
            int32_t l_1779 = 0x65FB2E90L;
            if (((((l_1779 = (safe_rshift_func_uint8_t_u_s(
                        (((safe_sub_func_int32_t_s_s(
                              (safe_add_func_uint16_t_u_u(
                                  ((safe_div_func_uint32_t_u_u(
                                       g_1338,
                                       (0xA792414F4DF79A93LL &&
                                        ((((~(p_26,
                                              (g_360 ^=
                                               ((safe_sub_func_int32_t_s_s(
                                                    l_1738,
                                                    (((safe_rshift_func_uint8_t_u_s(
                                                          6UL,
                                                          (((safe_mod_func_int32_t_s_s(
                                                                (((safe_rshift_func_uint8_t_u_u(
                                                                      (safe_sub_func_uint16_t_u_u(
                                                                          (p_26 ==
                                                                           (p_27 >=
                                                                            (l_1776 &=
                                                                             ((l_1775 =
                                                                                   (g_98.f3 >
                                                                                    (l_1738 ||
                                                                                     g_363))) !=
                                                                              l_1754)))),
                                                                          l_1729)),
                                                                      3)) >
                                                                  p_28) ||
                                                                 p_27),
                                                                p_26)) >=
                                                            0x1AB9L),
                                                           g_104))) >
                                                      0xCAB1D5D2C1591FE0LL),
                                                     l_1714))),
                                                l_1777)))) != 0xF1L) ==
                                          l_1778) >= p_26)))) ^
                                   g_758),
                                  g_103)),
                              g_204)) ||
                          4UL) <= p_27),
                        3))) < g_1054) <= 18446744073709551613UL) <= l_1777)) {
              int64_t l_1780 = 0x09A642E82F9C7B25LL;
              l_1787 |=
                  (18446744073709551612UL <=
                   ((l_1780 &= l_1754) &&
                    ((safe_mul_func_uint8_t_u_u(
                         l_1777,
                         (((safe_add_func_uint32_t_u_u(
                               4294967286UL,
                               (((((safe_unary_minus_func_int8_t_s(l_1777)) <
                                   (l_1729 ==
                                    (!(safe_unary_minus_func_int8_t_s(
                                        ((p_27 < p_27) &&
                                         (4294967295UL <= g_488))))))) ==
                                  0x0D36F576L) <= l_1780) < l_1777))) ==
                           0xD13427715DB54472LL) < p_27))) >= 0x2F0365FDL)));
              if (p_27)
                break;
              l_1779 =
                  ((((safe_mod_func_int32_t_s_s(
                         (safe_lshift_func_int8_t_s_s(
                             ((p_27 = (safe_rshift_func_uint16_t_u_s(
                                   (safe_lshift_func_uint16_t_u_s(
                                       ((l_1780 >=
                                         (safe_mul_func_int8_t_s_s(
                                             (((safe_add_func_int32_t_s_s(
                                                   (((safe_add_func_int8_t_s_s(
                                                         (g_443,
                                                          ((g_279 =
                                                                ((safe_mod_func_int32_t_s_s(
                                                                     (safe_mod_func_int16_t_s_s(
                                                                         (!(((l_1777 ==
                                                                              (l_1778,
                                                                               (0xE69107A0868FB16CLL !=
                                                                                ((safe_mul_func_uint8_t_u_u(
                                                                                     (safe_div_func_int64_t_s_s(
                                                                                         l_1729,
                                                                                         0x98D0D10A6F937A31LL)),
                                                                                     (~((safe_rshift_func_uint8_t_u_u(
                                                                                            ((safe_mul_func_uint8_t_u_u(
                                                                                                 g_207,
                                                                                                 (g_307
                                                                                                      .f2 ^
                                                                                                  l_1738))) |
                                                                                             g_1338),
                                                                                            2)) >=
                                                                                        4294967286UL)))) &&
                                                                                 l_1753)))) <=
                                                                             9L),
                                                                            0x0379L)),
                                                                         g_1814)),
                                                                     l_1780)),
                                                                 0xF9L)) ^
                                                           0x3EL)),
                                                         l_1815)) > (-1L)) <=
                                                    l_1738),
                                                   l_1816)) == p_26) &
                                              g_93),
                                             g_276))),
                                        0xB1FAL),
                                       14)),
                                   13))) &&
                              0L),
                             g_276)),
                         p_26)) &&
                     0x2B41L) &&
                    l_1776) &&
                   l_1780);
            } else {
              int32_t l_1823 = 0xCB59B68DL;
              int32_t l_1830 = 0x3A92E13EL;
              uint64_t l_1847 = 0x7DA90B982AC6555DLL;
              l_1847 =
                  ((safe_add_func_uint32_t_u_u(
                       (g_207 |
                        (g_279 |= (safe_rshift_func_int8_t_s_u(
                             ((p_27--) |
                              ((((((l_1823 >=
                                    ((safe_rshift_func_int8_t_s_u(
                                         (g_1846 =
                                              ((safe_lshift_func_int8_t_s_s(
                                                   (g_220 = g_307.f0),
                                                   g_98.f0)) <=
                                               (0xD2L ^
                                                (g_360 =
                                                     (((((safe_rshift_func_int8_t_s_u(
                                                             (l_1830 ^= 0xB3L),
                                                             (safe_div_func_uint8_t_u_u(
                                                                 (safe_add_func_int32_t_s_s(
                                                                     0x799CD25CL,
                                                                     (l_1845 &=
                                                                      (safe_lshift_func_uint16_t_u_s(
                                                                          ((safe_mod_func_int16_t_s_s(
                                                                               ((safe_sub_func_int16_t_s_s(
                                                                                    0x230EL,
                                                                                    (safe_rshift_func_uint8_t_u_u(
                                                                                        (safe_mod_func_int16_t_s_s(
                                                                                            ((p_26 >=
                                                                                              p_28) <
                                                                                             g_307
                                                                                                 .f7),
                                                                                            1UL)),
                                                                                        g_307
                                                                                            .f7)))),
                                                                                p_28),
                                                                               l_1738)),
                                                                           p_26),
                                                                          2))))),
                                                                 p_28)))) &
                                                         g_631) |
                                                        1L) &&
                                                       p_26),
                                                      p_28))))),
                                         4)) >= 1UL)) >= l_1787),
                                  0x41304B91L) >= p_26),
                                g_488) > g_443)),
                             l_1775)))),
                       4294967292UL)) &&
                   l_1830);
            }
            g_98.f0 = (l_1848 |= l_1776);
            l_1848 =
                ((l_1851 = (safe_rshift_func_int8_t_s_s(g_204, 3))) !=
                 ((safe_mul_func_int8_t_s_s(
                      ((~(!l_1777)) >=
                       (g_631 |= (safe_sub_func_int16_t_s_s(
                            ((-5L) >
                             (g_307.f6 <
                              (!(((7UL ^
                                   (safe_lshift_func_uint8_t_u_u(1UL, 6))) >
                                  ((safe_sub_func_uint64_t_u_u(
                                       ((g_758 || g_486) || p_26), g_701)) ||
                                   g_276)) &
                                 g_204)))),
                            g_1860)))),
                      l_1778)) &&
                  0x656D4D7CL));
          }

          {
            uint8_t l_1777 = 0UL;
            uint32_t l_1815 = 0x240146FDL;
            for (l_1754 = (-29); (l_1754 <= 11); l_1754++) {
              int8_t l_1775 = 0x06L;
              uint8_t l_1776 = 0x4AL;
              int8_t l_1778 = 0x4AL;
              int32_t l_1779 = 0x65FB2E90L;
              if (((((l_1779 = (safe_rshift_func_uint8_t_u_s(
                          (((safe_sub_func_int32_t_s_s(
                                (safe_add_func_uint16_t_u_u(
                                    ((safe_div_func_uint32_t_u_u(
                                         g_1338,
                                         (0xA792414F4DF79A93LL &&
                                          ((((~(p_26,
                                                (g_360 ^=
                                                 ((safe_sub_func_int32_t_s_s(
                                                      l_1738,
                                                      (((safe_rshift_func_uint8_t_u_s(
                                                            6UL,
                                                            (((safe_mod_func_int32_t_s_s(
                                                                  (((safe_rshift_func_uint8_t_u_u(
                                                                        (safe_sub_func_uint16_t_u_u(
                                                                            (p_26 ==
                                                                             (p_27 >=
                                                                              (l_1776 &=
                                                                               ((l_1775 =
                                                                                     (g_98.f3 >
                                                                                      (l_1738 ||
                                                                                       g_363))) !=
                                                                                l_1754)))),
                                                                            l_1729)),
                                                                        3)) >
                                                                    p_28) ||
                                                                   p_27),
                                                                  p_26)) >=
                                                              0x1AB9L),
                                                             g_104))) >
                                                        0xCAB1D5D2C1591FE0LL),
                                                       l_1714))),
                                                  l_1777)))) != 0xF1L) ==
                                            l_1778) >= p_26)))) ^
                                     g_758),
                                    g_103)),
                                g_204)) ||
                            4UL) <= p_27),
                          3))) < g_1054) <= 18446744073709551613UL) <=
                   l_1777)) {
                int64_t l_1780 = 0x09A642E82F9C7B25LL;
                l_1787 |=
                    (18446744073709551612UL <=
                     ((l_1780 &= l_1754) &&
                      ((safe_mul_func_uint8_t_u_u(
                           l_1777,
                           (((safe_add_func_uint32_t_u_u(
                                 4294967286UL,
                                 (((((safe_unary_minus_func_int8_t_s(l_1777)) <
                                     (l_1729 ==
                                      (!(safe_unary_minus_func_int8_t_s(
                                          ((p_27 < p_27) &&
                                           (4294967295UL <= g_488))))))) ==
                                    0x0D36F576L) <= l_1780) < l_1777))) ==
                             0xD13427715DB54472LL) < p_27))) >= 0x2F0365FDL)));
                if (p_27)
                  break;
                l_1779 =
                    ((((safe_mod_func_int32_t_s_s(
                           (safe_lshift_func_int8_t_s_s(
                               ((p_27 = (safe_rshift_func_uint16_t_u_s(
                                     (safe_lshift_func_uint16_t_u_s(
                                         ((l_1780 >=
                                           (safe_mul_func_int8_t_s_s(
                                               (((safe_add_func_int32_t_s_s(
                                                     (((safe_add_func_int8_t_s_s(
                                                           (g_443,
                                                            ((g_279 =
                                                                  ((safe_mod_func_int32_t_s_s(
                                                                       (safe_mod_func_int16_t_s_s(
                                                                           (!(((l_1777 ==
                                                                                (l_1778,
                                                                                 (0xE69107A0868FB16CLL !=
                                                                                  ((safe_mul_func_uint8_t_u_u(
                                                                                       (safe_div_func_int64_t_s_s(
                                                                                           l_1729,
                                                                                           0x98D0D10A6F937A31LL)),
                                                                                       (~((safe_rshift_func_uint8_t_u_u(
                                                                                              ((safe_mul_func_uint8_t_u_u(
                                                                                                   g_207,
                                                                                                   (g_307
                                                                                                        .f2 ^
                                                                                                    l_1738))) |
                                                                                               g_1338),
                                                                                              2)) >=
                                                                                          4294967286UL)))) &&
                                                                                   l_1753)))) <=
                                                                               9L),
                                                                              0x0379L)),
                                                                           g_1814)),
                                                                       l_1780)),
                                                                   0xF9L)) ^
                                                             0x3EL)),
                                                           l_1815)) > (-1L)) <=
                                                      l_1738),
                                                     l_1816)) == p_26) &
                                                g_93),
                                               g_276))),
                                          0xB1FAL),
                                         14)),
                                     13))) &&
                                0L),
                               g_276)),
                           p_26)) &&
                       0x2B41L) &&
                      l_1776) &&
                     l_1780);
              } else {
                int32_t l_1823 = 0xCB59B68DL;
                int32_t l_1830 = 0x3A92E13EL;
                uint64_t l_1847 = 0x7DA90B982AC6555DLL;
                l_1847 =
                    ((safe_add_func_uint32_t_u_u(
                         (g_207 |
                          (g_279 |= (safe_rshift_func_int8_t_s_u(
                               ((p_27--) |
                                ((((((l_1823 >=
                                      ((safe_rshift_func_int8_t_s_u(
                                           (g_1846 =
                                                ((safe_lshift_func_int8_t_s_s(
                                                     (g_220 = g_307.f0),
                                                     g_98.f0)) <=
                                                 (0xD2L ^
                                                  (g_360 =
                                                       (((((safe_rshift_func_int8_t_s_u(
                                                               (l_1830 ^=
                                                                0xB3L),
                                                               (safe_div_func_uint8_t_u_u(
                                                                   (safe_add_func_int32_t_s_s(
                                                                       0x799CD25CL,
                                                                       (l_1845 &=
                                                                        (safe_lshift_func_uint16_t_u_s(
                                                                            ((safe_mod_func_int16_t_s_s(
                                                                                 ((safe_sub_func_int16_t_s_s(
                                                                                      0x230EL,
                                                                                      (safe_rshift_func_uint8_t_u_u(
                                                                                          (safe_mod_func_int16_t_s_s(
                                                                                              ((p_26 >=
                                                                                                p_28) <
                                                                                               g_307
                                                                                                   .f7),
                                                                                              1UL)),
                                                                                          g_307
                                                                                              .f7)))),
                                                                                  p_28),
                                                                                 l_1738)),
                                                                             p_26),
                                                                            2))))),
                                                                   p_28)))) &
                                                           g_631) |
                                                          1L) &&
                                                         p_26),
                                                        p_28))))),
                                           4)) >= 1UL)) >= l_1787),
                                    0x41304B91L) >= p_26),
                                  g_488) > g_443)),
                               l_1775)))),
                         4294967292UL)) &&
                     l_1830);
              }
              g_98.f0 = (l_1848 |= l_1776);
              l_1848 =
                  ((l_1851 = (safe_rshift_func_int8_t_s_s(g_204, 3))) !=
                   ((safe_mul_func_int8_t_s_s(
                        ((~(!l_1777)) >=
                         (g_631 |= (safe_sub_func_int16_t_s_s(
                              ((-5L) >
                               (g_307.f6 <
                                (!(((7UL ^
                                     (safe_lshift_func_uint8_t_u_u(1UL, 6))) >
                                    ((safe_sub_func_uint64_t_u_u(
                                         ((g_758 || g_486) || p_26), g_701)) ||
                                     g_276)) &
                                   g_204)))),
                              g_1860)))),
                        l_1778)) &&
                    0x656D4D7CL));
            }
            l_1754 |= g_18;
          }

          l_1848 =
              ((l_1851 = (safe_rshift_func_int8_t_s_s(g_204, 3))) !=
               ((safe_mul_func_int8_t_s_s(
                    ((~(!l_1777)) >=
                     (g_631 |= (safe_sub_func_int16_t_s_s(
                          ((-5L) >
                           (g_307.f6 <
                            (!(((7UL ^ (safe_lshift_func_uint8_t_u_u(1UL, 6))) >
                                ((safe_sub_func_uint64_t_u_u(
                                     ((g_758 || g_486) || p_26), g_701)) ||
                                 g_276)) &
                               g_204)))),
                          g_1860)))),
                    l_1778)) &&
                0x656D4D7CL));
        }

        {
          int8_t l_1775 = 0x06L;
          uint8_t l_1776 = 0x4AL;
          int8_t l_1778 = 0x4AL;
          int32_t l_1779 = 0x65FB2E90L;
          if (((((l_1779 = (safe_rshift_func_uint8_t_u_s(
                      (((safe_sub_func_int32_t_s_s(
                            (safe_add_func_uint16_t_u_u(
                                ((safe_div_func_uint32_t_u_u(
                                     g_1338,
                                     (0xA792414F4DF79A93LL &&
                                      ((((~(p_26,
                                            (g_360 ^=
                                             ((safe_sub_func_int32_t_s_s(
                                                  l_1738,
                                                  (((safe_rshift_func_uint8_t_u_s(
                                                        6UL,
                                                        (((safe_mod_func_int32_t_s_s(
                                                              (((safe_rshift_func_uint8_t_u_u(
                                                                    (safe_sub_func_uint16_t_u_u(
                                                                        (p_26 ==
                                                                         (p_27 >=
                                                                          (l_1776 &=
                                                                           ((l_1775 =
                                                                                 (g_98.f3 >
                                                                                  (l_1738 ||
                                                                                   g_363))) !=
                                                                            l_1754)))),
                                                                        l_1729)),
                                                                    3)) >
                                                                p_28) ||
                                                               p_27),
                                                              p_26)) >=
                                                          0x1AB9L),
                                                         g_104))) >
                                                    0xCAB1D5D2C1591FE0LL),
                                                   l_1714))),
                                              l_1777)))) != 0xF1L) == l_1778) >=
                                       p_26)))) ^
                                 g_758),
                                g_103)),
                            g_204)) ||
                        4UL) <= p_27),
                      3))) < g_1054) <= 18446744073709551613UL) <= l_1777)) {
            int64_t l_1780 = 0x09A642E82F9C7B25LL;
            l_1787 |=
                (18446744073709551612UL <=
                 ((l_1780 &= l_1754) &&
                  ((safe_mul_func_uint8_t_u_u(
                       l_1777,
                       (((safe_add_func_uint32_t_u_u(
                             4294967286UL,
                             (((((safe_unary_minus_func_int8_t_s(l_1777)) <
                                 (l_1729 == (!(safe_unary_minus_func_int8_t_s((
                                                (p_27 < p_27) &&
                                                (4294967295UL <= g_488))))))) ==
                                0x0D36F576L) <= l_1780) < l_1777))) ==
                         0xD13427715DB54472LL) < p_27))) >= 0x2F0365FDL)));
            if (p_27)
              break;
            l_1779 =
                ((((safe_mod_func_int32_t_s_s(
                       (safe_lshift_func_int8_t_s_s(
                           ((p_27 = (safe_rshift_func_uint16_t_u_s(
                                 (safe_lshift_func_uint16_t_u_s(
                                     ((l_1780 >=
                                       (safe_mul_func_int8_t_s_s(
                                           (((safe_add_func_int32_t_s_s(
                                                 (((safe_add_func_int8_t_s_s(
                                                       (g_443,
                                                        ((g_279 =
                                                              ((safe_mod_func_int32_t_s_s(
                                                                   (safe_mod_func_int16_t_s_s(
                                                                       (!(((l_1777 ==
                                                                            (l_1778,
                                                                             (0xE69107A0868FB16CLL !=
                                                                              ((safe_mul_func_uint8_t_u_u(
                                                                                   (safe_div_func_int64_t_s_s(
                                                                                       l_1729,
                                                                                       0x98D0D10A6F937A31LL)),
                                                                                   (~((safe_rshift_func_uint8_t_u_u(
                                                                                          ((safe_mul_func_uint8_t_u_u(
                                                                                               g_207,
                                                                                               (g_307
                                                                                                    .f2 ^
                                                                                                l_1738))) |
                                                                                           g_1338),
                                                                                          2)) >=
                                                                                      4294967286UL)))) &&
                                                                               l_1753)))) <=
                                                                           9L),
                                                                          0x0379L)),
                                                                       g_1814)),
                                                                   l_1780)),
                                                               0xF9L)) ^
                                                         0x3EL)),
                                                       l_1815)) > (-1L)) <=
                                                  l_1738),
                                                 l_1816)) == p_26) &
                                            g_93),
                                           g_276))),
                                      0xB1FAL),
                                     14)),
                                 13))) &&
                            0L),
                           g_276)),
                       p_26)) &&
                   0x2B41L) &&
                  l_1776) &&
                 l_1780);
          } else {
            int32_t l_1823 = 0xCB59B68DL;
            int32_t l_1830 = 0x3A92E13EL;
            uint64_t l_1847 = 0x7DA90B982AC6555DLL;
            l_1847 =
                ((safe_add_func_uint32_t_u_u(
                     (g_207 |
                      (g_279 |= (safe_rshift_func_int8_t_s_u(
                           ((p_27--) |
                            ((((((l_1823 >=
                                  ((safe_rshift_func_int8_t_s_u(
                                       (g_1846 =
                                            ((safe_lshift_func_int8_t_s_s(
                                                 (g_220 = g_307.f0),
                                                 g_98.f0)) <=
                                             (0xD2L ^
                                              (g_360 =
                                                   (((((safe_rshift_func_int8_t_s_u(
                                                           (l_1830 ^= 0xB3L),
                                                           (safe_div_func_uint8_t_u_u(
                                                               (safe_add_func_int32_t_s_s(
                                                                   0x799CD25CL,
                                                                   (l_1845 &=
                                                                    (safe_lshift_func_uint16_t_u_s(
                                                                        ((safe_mod_func_int16_t_s_s(
                                                                             ((safe_sub_func_int16_t_s_s(
                                                                                  0x230EL,
                                                                                  (safe_rshift_func_uint8_t_u_u(
                                                                                      (safe_mod_func_int16_t_s_s(
                                                                                          ((p_26 >=
                                                                                            p_28) <
                                                                                           g_307
                                                                                               .f7),
                                                                                          1UL)),
                                                                                      g_307
                                                                                          .f7)))),
                                                                              p_28),
                                                                             l_1738)),
                                                                         p_26),
                                                                        2))))),
                                                               p_28)))) &
                                                       g_631) |
                                                      1L) &&
                                                     p_26),
                                                    p_28))))),
                                       4)) >= 1UL)) >= l_1787),
                                0x41304B91L) >= p_26),
                              g_488) > g_443)),
                           l_1775)))),
                     4294967292UL)) &&
                 l_1830);
          }
          g_98.f0 = (l_1848 |= l_1776);
          l_1848 =
              ((l_1851 = (safe_rshift_func_int8_t_s_s(g_204, 3))) !=
               ((safe_mul_func_int8_t_s_s(
                    ((~(!l_1777)) >=
                     (g_631 |= (safe_sub_func_int16_t_s_s(
                          ((-5L) >
                           (g_307.f6 <
                            (!(((7UL ^ (safe_lshift_func_uint8_t_u_u(1UL, 6))) >
                                ((safe_sub_func_uint64_t_u_u(
                                     ((g_758 || g_486) || p_26), g_701)) ||
                                 g_276)) &
                               g_204)))),
                          g_1860)))),
                    l_1778)) &&
                0x656D4D7CL));
        }
      }
      l_1754 = (p_26 != l_1851);
      { l_1754 = (-8L); }

    } else {
      return g_1054;
    }
    if ((safe_mul_func_uint8_t_u_u(l_1714, p_27))) {
      int16_t l_1729 = 0L;
      const int32_t l_1753 = 0xE00A8097L;
      int8_t l_1787 = 0xF1L;
      int32_t l_1848 = 0L;
      if (((((((safe_rshift_func_int16_t_s_u ((safe_sub_func_int64_t_s_s ((safe_div_func_uint32_t_u_u ((safe_mul_func_int16_t_s_s (l_1714, ((((safe_lshift_func_uint16_t_u_s (0x390DL, ((safe_rshift_func_uint16_t_u_s ((((safe_mod_func_uint8_t_u_u ((((l_1729 = (g_217 |= 0xDFC7F084L)) >= p_28) ^ (+(l_1754 = (0x93L <= (g_220 = (safe_mod_func_int8_t_s_s (((((safe_rshift_func_uint8_t_u_s ((safe_mul_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_s (((l_1714 || 255UL) == (l_1738 = p_27)), 6)) < (safe_mul_func_uint8_t_u_u ((safe_sub_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u ((((safe_sub_func_uint64_t_u_u ((safe_add_func_uint16_t_u_u ((safe_div_func_int64_t_s_s ((((safe_lshift_func_int8_t_s_u ((((0x0635L && 0xCB98L) >= p_27) >= 0xE48EF5508BAF3C6DLL), 1)) > p_26), 0xB31966A343A81CA7LL), l_1714)), p_28)), 0UL)) < 0x8343L) && g_104), 3)), p_26)), l_1714))), (-1L))), 6)), p_26), 1L) | p_27), l_1753))))))), 255UL)) == g_701) ^ p_27), 11)) <= l_1753))) != 0xC20610E7L) >= 0UL) | g_98.f2))), 0x714641C3L)), 0x2FF84D128D700EEDLL)), g_360)) || p_28) > g_483), g_363), 0x0C723813AD03E75ELL) < p_26))
      {
        l_1754 = (-8L);
      } else {
        uint8_t l_1777 = 0UL;
        uint32_t l_1815 = 0x240146FDL;
        for (l_1754 = (-29); (l_1754 <= 11); l_1754++) {
          int8_t l_1775 = 0x06L;
          uint8_t l_1776 = 0x4AL;
          int8_t l_1778 = 0x4AL;
          int32_t l_1779 = 0x65FB2E90L;
          if (((((l_1779 = (safe_rshift_func_uint8_t_u_s(
                      (((safe_sub_func_int32_t_s_s(
                            (safe_add_func_uint16_t_u_u(
                                ((safe_div_func_uint32_t_u_u(
                                     g_1338,
                                     (0xA792414F4DF79A93LL &&
                                      ((((~(p_26,
                                            (g_360 ^=
                                             ((safe_sub_func_int32_t_s_s(
                                                  l_1738,
                                                  (((safe_rshift_func_uint8_t_u_s(
                                                        6UL,
                                                        (((safe_mod_func_int32_t_s_s(
                                                              (((safe_rshift_func_uint8_t_u_u(
                                                                    (safe_sub_func_uint16_t_u_u(
                                                                        (p_26 ==
                                                                         (p_27 >=
                                                                          (l_1776 &=
                                                                           ((l_1775 =
                                                                                 (g_98.f3 >
                                                                                  (l_1738 ||
                                                                                   g_363))) !=
                                                                            l_1754)))),
                                                                        l_1729)),
                                                                    3)) >
                                                                p_28) ||
                                                               p_27),
                                                              p_26)) >=
                                                          0x1AB9L),
                                                         g_104))) >
                                                    0xCAB1D5D2C1591FE0LL),
                                                   l_1714))),
                                              l_1777)))) != 0xF1L) == l_1778) >=
                                       p_26)))) ^
                                 g_758),
                                g_103)),
                            g_204)) ||
                        4UL) <= p_27),
                      3))) < g_1054) <= 18446744073709551613UL) <= l_1777)) {
            int64_t l_1780 = 0x09A642E82F9C7B25LL;
            l_1787 |=
                (18446744073709551612UL <=
                 ((l_1780 &= l_1754) &&
                  ((safe_mul_func_uint8_t_u_u(
                       l_1777,
                       (((safe_add_func_uint32_t_u_u(
                             4294967286UL,
                             (((((safe_unary_minus_func_int8_t_s(l_1777)) <
                                 (l_1729 == (!(safe_unary_minus_func_int8_t_s((
                                                (p_27 < p_27) &&
                                                (4294967295UL <= g_488))))))) ==
                                0x0D36F576L) <= l_1780) < l_1777))) ==
                         0xD13427715DB54472LL) < p_27))) >= 0x2F0365FDL)));
            if (p_27)
              break;
            l_1779 =
                ((((safe_mod_func_int32_t_s_s(
                       (safe_lshift_func_int8_t_s_s(
                           ((p_27 = (safe_rshift_func_uint16_t_u_s(
                                 (safe_lshift_func_uint16_t_u_s(
                                     ((l_1780 >=
                                       (safe_mul_func_int8_t_s_s(
                                           (((safe_add_func_int32_t_s_s(
                                                 (((safe_add_func_int8_t_s_s(
                                                       (g_443,
                                                        ((g_279 =
                                                              ((safe_mod_func_int32_t_s_s(
                                                                   (safe_mod_func_int16_t_s_s(
                                                                       (!(((l_1777 ==
                                                                            (l_1778,
                                                                             (0xE69107A0868FB16CLL !=
                                                                              ((safe_mul_func_uint8_t_u_u(
                                                                                   (safe_div_func_int64_t_s_s(
                                                                                       l_1729,
                                                                                       0x98D0D10A6F937A31LL)),
                                                                                   (~((safe_rshift_func_uint8_t_u_u(
                                                                                          ((safe_mul_func_uint8_t_u_u(
                                                                                               g_207,
                                                                                               (g_307
                                                                                                    .f2 ^
                                                                                                l_1738))) |
                                                                                           g_1338),
                                                                                          2)) >=
                                                                                      4294967286UL)))) &&
                                                                               l_1753)))) <=
                                                                           9L),
                                                                          0x0379L)),
                                                                       g_1814)),
                                                                   l_1780)),
                                                               0xF9L)) ^
                                                         0x3EL)),
                                                       l_1815)) > (-1L)) <=
                                                  l_1738),
                                                 l_1816)) == p_26) &
                                            g_93),
                                           g_276))),
                                      0xB1FAL),
                                     14)),
                                 13))) &&
                            0L),
                           g_276)),
                       p_26)) &&
                   0x2B41L) &&
                  l_1776) &&
                 l_1780);
          } else {
            int32_t l_1823 = 0xCB59B68DL;
            int32_t l_1830 = 0x3A92E13EL;
            uint64_t l_1847 = 0x7DA90B982AC6555DLL;
            l_1847 =
                ((safe_add_func_uint32_t_u_u(
                     (g_207 |
                      (g_279 |= (safe_rshift_func_int8_t_s_u(
                           ((p_27--) |
                            ((((((l_1823 >=
                                  ((safe_rshift_func_int8_t_s_u(
                                       (g_1846 =
                                            ((safe_lshift_func_int8_t_s_s(
                                                 (g_220 = g_307.f0),
                                                 g_98.f0)) <=
                                             (0xD2L ^
                                              (g_360 =
                                                   (((((safe_rshift_func_int8_t_s_u(
                                                           (l_1830 ^= 0xB3L),
                                                           (safe_div_func_uint8_t_u_u(
                                                               (safe_add_func_int32_t_s_s(
                                                                   0x799CD25CL,
                                                                   (l_1845 &=
                                                                    (safe_lshift_func_uint16_t_u_s(
                                                                        ((safe_mod_func_int16_t_s_s(
                                                                             ((safe_sub_func_int16_t_s_s(
                                                                                  0x230EL,
                                                                                  (safe_rshift_func_uint8_t_u_u(
                                                                                      (safe_mod_func_int16_t_s_s(
                                                                                          ((p_26 >=
                                                                                            p_28) <
                                                                                           g_307
                                                                                               .f7),
                                                                                          1UL)),
                                                                                      g_307
                                                                                          .f7)))),
                                                                              p_28),
                                                                             l_1738)),
                                                                         p_26),
                                                                        2))))),
                                                               p_28)))) &
                                                       g_631) |
                                                      1L) &&
                                                     p_26),
                                                    p_28))))),
                                       4)) >= 1UL)) >= l_1787),
                                0x41304B91L) >= p_26),
                              g_488) > g_443)),
                           l_1775)))),
                     4294967292UL)) &&
                 l_1830);
          }
          g_98.f0 = (l_1848 |= l_1776);
          l_1848 =
              ((l_1851 = (safe_rshift_func_int8_t_s_s(g_204, 3))) !=
               ((safe_mul_func_int8_t_s_s(
                    ((~(!l_1777)) >=
                     (g_631 |= (safe_sub_func_int16_t_s_s(
                          ((-5L) >
                           (g_307.f6 <
                            (!(((7UL ^ (safe_lshift_func_uint8_t_u_u(1UL, 6))) >
                                ((safe_sub_func_uint64_t_u_u(
                                     ((g_758 || g_486) || p_26), g_701)) ||
                                 g_276)) &
                               g_204)))),
                          g_1860)))),
                    l_1778)) &&
                0x656D4D7CL));
        }
        l_1754 |= g_18;
      }
      l_1754 = (p_26 != l_1851);
    } else {
      return g_1054;
    }

    g_307.f6 =
        (((((safe_lshift_func_uint8_t_u_s(
                (l_1754 = ((!1UL), (safe_rshift_func_uint8_t_u_s(g_103, 7)))),
                (safe_add_func_uint32_t_u_u((g_307, 4294967295UL), 1L)))),
            ((l_1867 ^ (p_28 = (-6L))) ^
             ((l_1869 |=
               (((((((g_220 = (l_1868 ^= 0x4BL)), 1UL), g_631) == 0UL) &
                  l_1851) &&
                 l_1714) > 0x88E8L)) ^
              p_27))) > p_26) &
          p_26) |
         l_1816);
    l_1754 &= (safe_mul_func_uint16_t_u_u(
        (((((safe_div_func_uint16_t_u_u(
                (safe_mod_func_uint64_t_u_u(
                    ((safe_mul_func_uint8_t_u_u(
                         l_1868,
                         (((l_1878,
                            ((safe_sub_func_int64_t_s_s(
                                 (safe_div_func_uint32_t_u_u(
                                     (safe_add_func_uint8_t_u_u(
                                         ((-2L) ==
                                          ((g_220 =
                                                ((safe_mod_func_uint32_t_u_u(
                                                     (((l_1869 = (l_1878.f3 <
                                                                  (-9L))) &
                                                       ((safe_div_func_int16_t_s_s(
                                                            (safe_mul_func_uint16_t_u_u(
                                                                l_1878.f2,
                                                                (65527UL <
                                                                 (l_1878.f6 &&
                                                                  ((p_27 <
                                                                    4294967291UL) >=
                                                                   l_1878
                                                                       .f5))))),
                                                            l_1878.f6)),
                                                        g_279)) ||
                                                      0x31L),
                                                     1UL)),
                                                 g_98.f0)) != 6UL)),
                                         l_1878.f5)),
                                     p_26)),
                                 p_26)) != l_1878.f6)),
                           g_281) ||
                          g_1338))) ^
                     (-2L)),
                    l_1714)),
                0xB31EL)) > l_1878.f3) ^
           g_281),
          5UL) &
         g_103),
        l_1845));
    if ((l_1868 = (safe_lshift_func_uint8_t_u_s(5UL, 7)))) {
      uint32_t l_1902 = 0xAA8E5855L;
      int32_t l_1907 = (-1L);

      {
        uint32_t l_1902 = 0xAA8E5855L;
        int32_t l_1907 = (-1L);
        l_1869 =
            (l_1845 =
                 (((g_104 = (safe_rshift_func_int8_t_s_s(
                        (((l_1878, (l_1895 | (-1L))) & l_1845) != 9UL), 6))),
                   ((safe_mod_func_int16_t_s_s(
                        ((safe_add_func_int16_t_s_s(
                             (safe_mul_func_int16_t_s_s(p_28, l_1902)),
                             (safe_sub_func_int16_t_s_s(
                                 ((g_279 && ((safe_rshift_func_uint16_t_u_s(
                                                 (p_27 = (+1UL)), p_28)) >=
                                             l_1845)) >= p_26),
                                 g_631)))) &&
                         l_1902),
                        0xE732L)),
                    0x4360A5CEL)) == 0L));
        l_1907 = (+(l_1868 = (p_28 > g_483)));
      }

    } else {
      uint32_t l_1910 = 3UL;
      int32_t l_1925 = 0x4520BFCBL;
      int32_t l_1928 = 1L;

      if ((safe_mul_func_uint8_t_u_u(l_1714, p_27))) {
        int16_t l_1729 = 0L;
        const int32_t l_1753 = 0xE00A8097L;
        int8_t l_1787 = 0xF1L;
        int32_t l_1848 = 0L;
      if (((((((safe_rshift_func_int16_t_s_u ((safe_sub_func_int64_t_s_s ((safe_div_func_uint32_t_u_u ((safe_mul_func_int16_t_s_s (l_1714, ((((safe_lshift_func_uint16_t_u_s (0x390DL, ((safe_rshift_func_uint16_t_u_s ((((safe_mod_func_uint8_t_u_u ((((l_1729 = (g_217 |= 0xDFC7F084L)) >= p_28) ^ (+(l_1754 = (0x93L <= (g_220 = (safe_mod_func_int8_t_s_s (((((safe_rshift_func_uint8_t_u_s ((safe_mul_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_s (((l_1714 || 255UL) == (l_1738 = p_27)), 6)) < (safe_mul_func_uint8_t_u_u ((safe_sub_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u ((((safe_sub_func_uint64_t_u_u ((safe_add_func_uint16_t_u_u ((safe_div_func_int64_t_s_s ((((safe_lshift_func_int8_t_s_u ((((0x0635L && 0xCB98L) >= p_27) >= 0xE48EF5508BAF3C6DLL), 1)) > p_26), 0xB31966A343A81CA7LL), l_1714)), p_28)), 0UL)) < 0x8343L) && g_104), 3)), p_26)), l_1714))), (-1L))), 6)), p_26), 1L) | p_27), l_1753))))))), 255UL)) == g_701) ^ p_27), 11)) <= l_1753))) != 0xC20610E7L) >= 0UL) | g_98.f2))), 0x714641C3L)), 0x2FF84D128D700EEDLL)), g_360)) || p_28) > g_483), g_363), 0x0C723813AD03E75ELL) < p_26))
      {
        l_1754 = (-8L);
      } else {
        uint8_t l_1777 = 0UL;
        uint32_t l_1815 = 0x240146FDL;
        for (l_1754 = (-29); (l_1754 <= 11); l_1754++) {
          int8_t l_1775 = 0x06L;
          uint8_t l_1776 = 0x4AL;
          int8_t l_1778 = 0x4AL;
          int32_t l_1779 = 0x65FB2E90L;
          if (((((l_1779 = (safe_rshift_func_uint8_t_u_s(
                      (((safe_sub_func_int32_t_s_s(
                            (safe_add_func_uint16_t_u_u(
                                ((safe_div_func_uint32_t_u_u(
                                     g_1338,
                                     (0xA792414F4DF79A93LL &&
                                      ((((~(p_26,
                                            (g_360 ^=
                                             ((safe_sub_func_int32_t_s_s(
                                                  l_1738,
                                                  (((safe_rshift_func_uint8_t_u_s(
                                                        6UL,
                                                        (((safe_mod_func_int32_t_s_s(
                                                              (((safe_rshift_func_uint8_t_u_u(
                                                                    (safe_sub_func_uint16_t_u_u(
                                                                        (p_26 ==
                                                                         (p_27 >=
                                                                          (l_1776 &=
                                                                           ((l_1775 =
                                                                                 (g_98.f3 >
                                                                                  (l_1738 ||
                                                                                   g_363))) !=
                                                                            l_1754)))),
                                                                        l_1729)),
                                                                    3)) >
                                                                p_28) ||
                                                               p_27),
                                                              p_26)) >=
                                                          0x1AB9L),
                                                         g_104))) >
                                                    0xCAB1D5D2C1591FE0LL),
                                                   l_1714))),
                                              l_1777)))) != 0xF1L) == l_1778) >=
                                       p_26)))) ^
                                 g_758),
                                g_103)),
                            g_204)) ||
                        4UL) <= p_27),
                      3))) < g_1054) <= 18446744073709551613UL) <= l_1777)) {
            int64_t l_1780 = 0x09A642E82F9C7B25LL;
            l_1787 |=
                (18446744073709551612UL <=
                 ((l_1780 &= l_1754) &&
                  ((safe_mul_func_uint8_t_u_u(
                       l_1777,
                       (((safe_add_func_uint32_t_u_u(
                             4294967286UL,
                             (((((safe_unary_minus_func_int8_t_s(l_1777)) <
                                 (l_1729 == (!(safe_unary_minus_func_int8_t_s((
                                                (p_27 < p_27) &&
                                                (4294967295UL <= g_488))))))) ==
                                0x0D36F576L) <= l_1780) < l_1777))) ==
                         0xD13427715DB54472LL) < p_27))) >= 0x2F0365FDL)));
            if (p_27)
              break;
            l_1779 =
                ((((safe_mod_func_int32_t_s_s(
                       (safe_lshift_func_int8_t_s_s(
                           ((p_27 = (safe_rshift_func_uint16_t_u_s(
                                 (safe_lshift_func_uint16_t_u_s(
                                     ((l_1780 >=
                                       (safe_mul_func_int8_t_s_s(
                                           (((safe_add_func_int32_t_s_s(
                                                 (((safe_add_func_int8_t_s_s(
                                                       (g_443,
                                                        ((g_279 =
                                                              ((safe_mod_func_int32_t_s_s(
                                                                   (safe_mod_func_int16_t_s_s(
                                                                       (!(((l_1777 ==
                                                                            (l_1778,
                                                                             (0xE69107A0868FB16CLL !=
                                                                              ((safe_mul_func_uint8_t_u_u(
                                                                                   (safe_div_func_int64_t_s_s(
                                                                                       l_1729,
                                                                                       0x98D0D10A6F937A31LL)),
                                                                                   (~((safe_rshift_func_uint8_t_u_u(
                                                                                          ((safe_mul_func_uint8_t_u_u(
                                                                                               g_207,
                                                                                               (g_307
                                                                                                    .f2 ^
                                                                                                l_1738))) |
                                                                                           g_1338),
                                                                                          2)) >=
                                                                                      4294967286UL)))) &&
                                                                               l_1753)))) <=
                                                                           9L),
                                                                          0x0379L)),
                                                                       g_1814)),
                                                                   l_1780)),
                                                               0xF9L)) ^
                                                         0x3EL)),
                                                       l_1815)) > (-1L)) <=
                                                  l_1738),
                                                 l_1816)) == p_26) &
                                            g_93),
                                           g_276))),
                                      0xB1FAL),
                                     14)),
                                 13))) &&
                            0L),
                           g_276)),
                       p_26)) &&
                   0x2B41L) &&
                  l_1776) &&
                 l_1780);
          } else {
            int32_t l_1823 = 0xCB59B68DL;
            int32_t l_1830 = 0x3A92E13EL;
            uint64_t l_1847 = 0x7DA90B982AC6555DLL;
            l_1847 =
                ((safe_add_func_uint32_t_u_u(
                     (g_207 |
                      (g_279 |= (safe_rshift_func_int8_t_s_u(
                           ((p_27--) |
                            ((((((l_1823 >=
                                  ((safe_rshift_func_int8_t_s_u(
                                       (g_1846 =
                                            ((safe_lshift_func_int8_t_s_s(
                                                 (g_220 = g_307.f0),
                                                 g_98.f0)) <=
                                             (0xD2L ^
                                              (g_360 =
                                                   (((((safe_rshift_func_int8_t_s_u(
                                                           (l_1830 ^= 0xB3L),
                                                           (safe_div_func_uint8_t_u_u(
                                                               (safe_add_func_int32_t_s_s(
                                                                   0x799CD25CL,
                                                                   (l_1845 &=
                                                                    (safe_lshift_func_uint16_t_u_s(
                                                                        ((safe_mod_func_int16_t_s_s(
                                                                             ((safe_sub_func_int16_t_s_s(
                                                                                  0x230EL,
                                                                                  (safe_rshift_func_uint8_t_u_u(
                                                                                      (safe_mod_func_int16_t_s_s(
                                                                                          ((p_26 >=
                                                                                            p_28) <
                                                                                           g_307
                                                                                               .f7),
                                                                                          1UL)),
                                                                                      g_307
                                                                                          .f7)))),
                                                                              p_28),
                                                                             l_1738)),
                                                                         p_26),
                                                                        2))))),
                                                               p_28)))) &
                                                       g_631) |
                                                      1L) &&
                                                     p_26),
                                                    p_28))))),
                                       4)) >= 1UL)) >= l_1787),
                                0x41304B91L) >= p_26),
                              g_488) > g_443)),
                           l_1775)))),
                     4294967292UL)) &&
                 l_1830);
          }
          g_98.f0 = (l_1848 |= l_1776);
          l_1848 =
              ((l_1851 = (safe_rshift_func_int8_t_s_s(g_204, 3))) !=
               ((safe_mul_func_int8_t_s_s(
                    ((~(!l_1777)) >=
                     (g_631 |= (safe_sub_func_int16_t_s_s(
                          ((-5L) >
                           (g_307.f6 <
                            (!(((7UL ^ (safe_lshift_func_uint8_t_u_u(1UL, 6))) >
                                ((safe_sub_func_uint64_t_u_u(
                                     ((g_758 || g_486) || p_26), g_701)) ||
                                 g_276)) &
                               g_204)))),
                          g_1860)))),
                    l_1778)) &&
                0x656D4D7CL));
        }
        l_1754 |= g_18;
      }
      l_1754 = (p_26 != l_1851);
      } else {
        return g_1054;
      }

      l_1928 =
          (g_307.f3 = (safe_add_func_int8_t_s_s(
               (safe_sub_func_uint64_t_u_u(
                   0xC47878A5A2F6696ALL,
                   (g_104 ^= (safe_lshift_func_int16_t_s_s(
                        ((l_1754,
                          ((g_628++),
                           (((l_1910,
                              (l_1922 >=
                               (safe_sub_func_int8_t_s_s(
                                   ((0UL > (l_1816 ||
                                            ((((l_1925 |= l_1754) <
                                               ((0x0AA64E7AC8486078LL !=
                                                 (safe_mod_func_uint32_t_u_u(
                                                     ((65535UL <= 4UL) ^ 0xEBL),
                                                     0xCAA79A1BL))) ^
                                                p_28)) >= p_28) ^
                                             0x3C0EL))) |
                                    p_27),
                                   4L)))) > 1UL) &&
                            l_1878.f3))) <= l_1714),
                        p_26))))),
               g_1846)));
    }
    {
      uint32_t l_1738 = 0x32EB4178L;
      uint32_t l_1816 = 18446744073709551615UL;
      int8_t l_1851 = (-10L);
      uint32_t l_1867 = 4294967295UL;
      int32_t l_1868 = 1L;
      int32_t l_1869 = (-1L);
      struct S0 l_1878 = {0x8676A15EL, 4, 1188, -3, 374, 3, -6279, 9};
      uint64_t l_1895 = 18446744073709551613UL;
      if ((safe_mul_func_uint8_t_u_u(l_1714, p_27))) {
        int16_t l_1729 = 0L;
        const int32_t l_1753 = 0xE00A8097L;
        int8_t l_1787 = 0xF1L;
        int32_t l_1848 = 0L;
      if (((((((safe_rshift_func_int16_t_s_u ((safe_sub_func_int64_t_s_s ((safe_div_func_uint32_t_u_u ((safe_mul_func_int16_t_s_s (l_1714, ((((safe_lshift_func_uint16_t_u_s (0x390DL, ((safe_rshift_func_uint16_t_u_s ((((safe_mod_func_uint8_t_u_u ((((l_1729 = (g_217 |= 0xDFC7F084L)) >= p_28) ^ (+(l_1754 = (0x93L <= (g_220 = (safe_mod_func_int8_t_s_s (((((safe_rshift_func_uint8_t_u_s ((safe_mul_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_s (((l_1714 || 255UL) == (l_1738 = p_27)), 6)) < (safe_mul_func_uint8_t_u_u ((safe_sub_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u ((((safe_sub_func_uint64_t_u_u ((safe_add_func_uint16_t_u_u ((safe_div_func_int64_t_s_s ((((safe_lshift_func_int8_t_s_u ((((0x0635L && 0xCB98L) >= p_27) >= 0xE48EF5508BAF3C6DLL), 1)) > p_26), 0xB31966A343A81CA7LL), l_1714)), p_28)), 0UL)) < 0x8343L) && g_104), 3)), p_26)), l_1714))), (-1L))), 6)), p_26), 1L) | p_27), l_1753))))))), 255UL)) == g_701) ^ p_27), 11)) <= l_1753))) != 0xC20610E7L) >= 0UL) | g_98.f2))), 0x714641C3L)), 0x2FF84D128D700EEDLL)), g_360)) || p_28) > g_483), g_363), 0x0C723813AD03E75ELL) < p_26))
      {
        l_1754 = (-8L);
      } else {
        uint8_t l_1777 = 0UL;
        uint32_t l_1815 = 0x240146FDL;
        for (l_1754 = (-29); (l_1754 <= 11); l_1754++) {
          int8_t l_1775 = 0x06L;
          uint8_t l_1776 = 0x4AL;
          int8_t l_1778 = 0x4AL;
          int32_t l_1779 = 0x65FB2E90L;
          if (((((l_1779 = (safe_rshift_func_uint8_t_u_s(
                      (((safe_sub_func_int32_t_s_s(
                            (safe_add_func_uint16_t_u_u(
                                ((safe_div_func_uint32_t_u_u(
                                     g_1338,
                                     (0xA792414F4DF79A93LL &&
                                      ((((~(p_26,
                                            (g_360 ^=
                                             ((safe_sub_func_int32_t_s_s(
                                                  l_1738,
                                                  (((safe_rshift_func_uint8_t_u_s(
                                                        6UL,
                                                        (((safe_mod_func_int32_t_s_s(
                                                              (((safe_rshift_func_uint8_t_u_u(
                                                                    (safe_sub_func_uint16_t_u_u(
                                                                        (p_26 ==
                                                                         (p_27 >=
                                                                          (l_1776 &=
                                                                           ((l_1775 =
                                                                                 (g_98.f3 >
                                                                                  (l_1738 ||
                                                                                   g_363))) !=
                                                                            l_1754)))),
                                                                        l_1729)),
                                                                    3)) >
                                                                p_28) ||
                                                               p_27),
                                                              p_26)) >=
                                                          0x1AB9L),
                                                         g_104))) >
                                                    0xCAB1D5D2C1591FE0LL),
                                                   l_1714))),
                                              l_1777)))) != 0xF1L) == l_1778) >=
                                       p_26)))) ^
                                 g_758),
                                g_103)),
                            g_204)) ||
                        4UL) <= p_27),
                      3))) < g_1054) <= 18446744073709551613UL) <= l_1777)) {
            int64_t l_1780 = 0x09A642E82F9C7B25LL;
            l_1787 |=
                (18446744073709551612UL <=
                 ((l_1780 &= l_1754) &&
                  ((safe_mul_func_uint8_t_u_u(
                       l_1777,
                       (((safe_add_func_uint32_t_u_u(
                             4294967286UL,
                             (((((safe_unary_minus_func_int8_t_s(l_1777)) <
                                 (l_1729 == (!(safe_unary_minus_func_int8_t_s((
                                                (p_27 < p_27) &&
                                                (4294967295UL <= g_488))))))) ==
                                0x0D36F576L) <= l_1780) < l_1777))) ==
                         0xD13427715DB54472LL) < p_27))) >= 0x2F0365FDL)));
            if (p_27)
              break;
            l_1779 =
                ((((safe_mod_func_int32_t_s_s(
                       (safe_lshift_func_int8_t_s_s(
                           ((p_27 = (safe_rshift_func_uint16_t_u_s(
                                 (safe_lshift_func_uint16_t_u_s(
                                     ((l_1780 >=
                                       (safe_mul_func_int8_t_s_s(
                                           (((safe_add_func_int32_t_s_s(
                                                 (((safe_add_func_int8_t_s_s(
                                                       (g_443,
                                                        ((g_279 =
                                                              ((safe_mod_func_int32_t_s_s(
                                                                   (safe_mod_func_int16_t_s_s(
                                                                       (!(((l_1777 ==
                                                                            (l_1778,
                                                                             (0xE69107A0868FB16CLL !=
                                                                              ((safe_mul_func_uint8_t_u_u(
                                                                                   (safe_div_func_int64_t_s_s(
                                                                                       l_1729,
                                                                                       0x98D0D10A6F937A31LL)),
                                                                                   (~((safe_rshift_func_uint8_t_u_u(
                                                                                          ((safe_mul_func_uint8_t_u_u(
                                                                                               g_207,
                                                                                               (g_307
                                                                                                    .f2 ^
                                                                                                l_1738))) |
                                                                                           g_1338),
                                                                                          2)) >=
                                                                                      4294967286UL)))) &&
                                                                               l_1753)))) <=
                                                                           9L),
                                                                          0x0379L)),
                                                                       g_1814)),
                                                                   l_1780)),
                                                               0xF9L)) ^
                                                         0x3EL)),
                                                       l_1815)) > (-1L)) <=
                                                  l_1738),
                                                 l_1816)) == p_26) &
                                            g_93),
                                           g_276))),
                                      0xB1FAL),
                                     14)),
                                 13))) &&
                            0L),
                           g_276)),
                       p_26)) &&
                   0x2B41L) &&
                  l_1776) &&
                 l_1780);
          } else {
            int32_t l_1823 = 0xCB59B68DL;
            int32_t l_1830 = 0x3A92E13EL;
            uint64_t l_1847 = 0x7DA90B982AC6555DLL;
            l_1847 =
                ((safe_add_func_uint32_t_u_u(
                     (g_207 |
                      (g_279 |= (safe_rshift_func_int8_t_s_u(
                           ((p_27--) |
                            ((((((l_1823 >=
                                  ((safe_rshift_func_int8_t_s_u(
                                       (g_1846 =
                                            ((safe_lshift_func_int8_t_s_s(
                                                 (g_220 = g_307.f0),
                                                 g_98.f0)) <=
                                             (0xD2L ^
                                              (g_360 =
                                                   (((((safe_rshift_func_int8_t_s_u(
                                                           (l_1830 ^= 0xB3L),
                                                           (safe_div_func_uint8_t_u_u(
                                                               (safe_add_func_int32_t_s_s(
                                                                   0x799CD25CL,
                                                                   (l_1845 &=
                                                                    (safe_lshift_func_uint16_t_u_s(
                                                                        ((safe_mod_func_int16_t_s_s(
                                                                             ((safe_sub_func_int16_t_s_s(
                                                                                  0x230EL,
                                                                                  (safe_rshift_func_uint8_t_u_u(
                                                                                      (safe_mod_func_int16_t_s_s(
                                                                                          ((p_26 >=
                                                                                            p_28) <
                                                                                           g_307
                                                                                               .f7),
                                                                                          1UL)),
                                                                                      g_307
                                                                                          .f7)))),
                                                                              p_28),
                                                                             l_1738)),
                                                                         p_26),
                                                                        2))))),
                                                               p_28)))) &
                                                       g_631) |
                                                      1L) &&
                                                     p_26),
                                                    p_28))))),
                                       4)) >= 1UL)) >= l_1787),
                                0x41304B91L) >= p_26),
                              g_488) > g_443)),
                           l_1775)))),
                     4294967292UL)) &&
                 l_1830);
          }
          g_98.f0 = (l_1848 |= l_1776);
          l_1848 =
              ((l_1851 = (safe_rshift_func_int8_t_s_s(g_204, 3))) !=
               ((safe_mul_func_int8_t_s_s(
                    ((~(!l_1777)) >=
                     (g_631 |= (safe_sub_func_int16_t_s_s(
                          ((-5L) >
                           (g_307.f6 <
                            (!(((7UL ^ (safe_lshift_func_uint8_t_u_u(1UL, 6))) >
                                ((safe_sub_func_uint64_t_u_u(
                                     ((g_758 || g_486) || p_26), g_701)) ||
                                 g_276)) &
                               g_204)))),
                          g_1860)))),
                    l_1778)) &&
                0x656D4D7CL));
        }
        l_1754 |= g_18;
      }
      l_1754 = (p_26 != l_1851);
      } else {
        return g_1054;
      }
      g_307.f6 =
          (((((safe_lshift_func_uint8_t_u_s(
                  (l_1754 = ((!1UL), (safe_rshift_func_uint8_t_u_s(g_103, 7)))),
                  (safe_add_func_uint32_t_u_u((g_307, 4294967295UL), 1L)))),
              ((l_1867 ^ (p_28 = (-6L))) ^
               ((l_1869 |=
                 (((((((g_220 = (l_1868 ^= 0x4BL)), 1UL), g_631) == 0UL) &
                    l_1851) &&
                   l_1714) > 0x88E8L)) ^
                p_27))) > p_26) &
            p_26) |
           l_1816);
      l_1754 &= (safe_mul_func_uint16_t_u_u(
          (((((safe_div_func_uint16_t_u_u(
                  (safe_mod_func_uint64_t_u_u(
                      ((safe_mul_func_uint8_t_u_u(
                           l_1868,
                           (((l_1878,
                              ((safe_sub_func_int64_t_s_s(
                                   (safe_div_func_uint32_t_u_u(
                                       (safe_add_func_uint8_t_u_u(
                                           ((-2L) ==
                                            ((g_220 =
                                                  ((safe_mod_func_uint32_t_u_u(
                                                       (((l_1869 = (l_1878.f3 <
                                                                    (-9L))) &
                                                         ((safe_div_func_int16_t_s_s(
                                                              (safe_mul_func_uint16_t_u_u(
                                                                  l_1878.f2,
                                                                  (65527UL <
                                                                   (l_1878.f6 &&
                                                                    ((p_27 <
                                                                      4294967291UL) >=
                                                                     l_1878
                                                                         .f5))))),
                                                              l_1878.f6)),
                                                          g_279)) ||
                                                        0x31L),
                                                       1UL)),
                                                   g_98.f0)) != 6UL)),
                                           l_1878.f5)),
                                       p_26)),
                                   p_26)) != l_1878.f6)),
                             g_281) ||
                            g_1338))) ^
                       (-2L)),
                      l_1714)),
                  0xB31EL)) > l_1878.f3) ^
             g_281),
            5UL) &
           g_103),
          l_1845));
      if ((l_1868 = (safe_lshift_func_uint8_t_u_s(5UL, 7)))) {
        uint32_t l_1902 = 0xAA8E5855L;
        int32_t l_1907 = (-1L);
        l_1869 =
            (l_1845 =
                 (((g_104 = (safe_rshift_func_int8_t_s_s(
                        (((l_1878, (l_1895 | (-1L))) & l_1845) != 9UL), 6))),
                   ((safe_mod_func_int16_t_s_s(
                        ((safe_add_func_int16_t_s_s(
                             (safe_mul_func_int16_t_s_s(p_28, l_1902)),
                             (safe_sub_func_int16_t_s_s(
                                 ((g_279 && ((safe_rshift_func_uint16_t_u_s(
                                                 (p_27 = (+1UL)), p_28)) >=
                                             l_1845)) >= p_26),
                                 g_631)))) &&
                         l_1902),
                        0xE732L)),
                    0x4360A5CEL)) == 0L));
        l_1907 = (+(l_1868 = (p_28 > g_483)));
      } else {
        uint32_t l_1910 = 3UL;
        int32_t l_1925 = 0x4520BFCBL;
        int32_t l_1928 = 1L;
        for (g_1846 = 0; (g_1846 != (-26));
             g_1846 = safe_sub_func_int32_t_s_s(g_1846, 7)) {
          int64_t l_1913 = (-1L);
          --l_1910;
          return l_1913;
        }
        l_1928 =
            (g_307.f3 = (safe_add_func_int8_t_s_s(
                 (safe_sub_func_uint64_t_u_u(
                     0xC47878A5A2F6696ALL,
                     (g_104 ^= (safe_lshift_func_int16_t_s_s(
                          ((l_1754,
                            ((g_628++),
                             (((l_1910,
                                (l_1922 >=
                                 (safe_sub_func_int8_t_s_s(
                                     ((0UL >
                                       (l_1816 ||
                                        ((((l_1925 |= l_1754) <
                                           ((0x0AA64E7AC8486078LL !=
                                             (safe_mod_func_uint32_t_u_u(
                                                 ((65535UL <= 4UL) ^ 0xEBL),
                                                 0xCAA79A1BL))) ^
                                            p_28)) >= p_28) ^
                                         0x3C0EL))) |
                                      p_27),
                                     4L)))) > 1UL) &&
                              l_1878.f3))) <= l_1714),
                          p_26))))),
                 g_1846)));
      }
    }
  }
  l_1950 = (safe_mul_func_int8_t_s_s(
      (safe_lshift_func_int16_t_s_s(
          (((l_1845,
             (!(l_1754 = (safe_rshift_func_uint8_t_u_s(
                    p_28,
                    ((safe_div_func_int8_t_s_s(
                         ((safe_rshift_func_int16_t_s_u(
                              (g_486 =
                                   (l_1845 = (safe_mul_func_int16_t_s_s(
                                        g_307.f4,
                                        ((p_27,
                                          (g_481 = (safe_rshift_func_int8_t_s_s(
                                               (0x669277AE1AEFFA84LL <
                                                (((safe_add_func_int64_t_s_s(
                                                      0x3EAA94E4FE289A8FLL,
                                                      l_1845)) ==
                                                  (safe_lshift_func_int8_t_s_s(
                                                      (((((safe_sub_func_uint16_t_u_u(
                                                              (safe_unary_minus_func_uint32_t_u(
                                                                  p_28)),
                                                              p_27)) >=
                                                          g_488) <= p_26),
                                                        0x55L) >= l_1845),
                                                      p_27))),
                                                 l_1754)),
                                               4)))) |
                                         1L))))),
                              l_1950)) |
                          0x65L),
                         g_18)) &&
                     2UL)))))) ^
            p_27) &&
           p_27),
          12)),
      0xFDL));
  return l_1951;
}

static uint32_t func_31(int64_t p_32, uint32_t p_33, uint8_t p_34,
                        uint32_t p_35) {
  int32_t l_53 = (-9L);
  int32_t l_77 = 0xD2166A3CL;
  const int64_t l_1684 = 4L;
  uint32_t l_1696 = 0xFAF3CCEFL;
  for (p_32 = 20; (p_32 > (-30)); p_32--) {
    uint64_t l_52 = 0x22CFB64730E92F9ELL;
    int32_t l_1685 = 9L;
    l_1685 =
        ((((safe_mul_func_uint16_t_u_u(
               (safe_mod_func_uint8_t_u_u(
                   (safe_mod_func_uint8_t_u_u(
                       func_46((
                           func_48(
                               ((l_52 && (l_53 = 1L)), l_52),
                               (((safe_add_func_int64_t_s_s(
                                     g_18,
                                     (func_58(
                                          (safe_div_func_int64_t_s_s(
                                              (((0xBDD2L ==
                                                 func_64(
                                                     l_52, p_33,
                                                     l_52,
                                                     (safe_div_func_int64_t_s_s(
                                                         (safe_div_func_int16_t_s_s(
                                                             (safe_mul_func_uint16_t_u_u(
                                                                 ((safe_sub_func_int32_t_s_s(
                                                                      (((0x44L ^
                                                                         p_33) &
                                                                        0x3B350B8378C3A3B2LL) !=
                                                                       l_52),
                                                                      g_18)),
                                                                  g_18),
                                                                 0x2C65L)),
                                                             l_77)),
                                                         18446744073709551615UL)))) &
                                                g_18) ||
                                               0xF1E61188795192C2LL),
                                              g_18)),
                                          g_18, l_52) ||
                                      0x711A46C428827C80LL))) &
                                 0UL),
                                0x84L),
                               g_18) &&
                           255UL)),
                       g_18)),
                   g_307.f4)),
               g_363)) |
           l_1684),
          l_52) <= 255UL);
  }
  g_307.f6 =
      (((safe_sub_func_int8_t_s_s(
            ((((0x89L &
                ((g_486 = g_307.f3) ==
                 (safe_mod_func_int32_t_s_s(
                     (((((safe_add_func_int16_t_s_s(
                             (safe_add_func_uint32_t_u_u(
                                 0UL,
                                 (g_217 =
                                      (l_1696 ^
                                       (l_53 &
                                        (safe_add_func_uint64_t_u_u(
                                            0xAFBFB0038CCC94A5LL,
                                            (safe_unary_minus_func_uint16_t_u((safe_add_func_uint32_t_u_u(
                                                (g_307.f2 = g_483),
                                                (safe_rshift_func_uint16_t_u_s(
                                                    (safe_mod_func_int16_t_s_s(
                                                        (((safe_add_func_uint32_t_u_u(
                                                              (p_33 =
                                                                   ((safe_rshift_func_uint16_t_u_u(
                                                                        ((((l_77 =
                                                                                (0x03649F42L ^
                                                                                 (((g_98,
                                                                                    0xF98DL) >=
                                                                                   (-1L)) >
                                                                                  l_1696))),
                                                                           0xE81E42986F0F7570LL) !=
                                                                          l_1696) >=
                                                                         p_32),
                                                                        l_1684)) >=
                                                                    l_1696)),
                                                              0x53BC42D6L)) &&
                                                          3UL) == p_32),
                                                        0xF44FL)),
                                                    2))))))))))))),
                             0x7480L)) > 0xE1F4090473C8BF80LL) > p_35) |
                       p_35) > p_34),
                     g_307.f0)))),
               4UL) ^
              p_35) != l_1684),
            0L)) ^
        g_98.f2) |
       l_1696);
  return p_35;
}

static uint8_t func_46(uint16_t p_47) {
  int16_t l_117 = 0x46A0L;
  int32_t l_118 = 0L;
  const uint32_t l_128 = 18446744073709551615UL;
  int32_t l_1481 = 0xB526AC16L;
  int32_t l_1493 = 0xFAE9F25CL;
  int32_t l_1549 = 0L;
  int32_t l_1590 = 0L;
  struct S0 l_1680 = {0xA8B82AB9L, 24, 1184, 3, 6820, 1, 4483, 14};
  if (((safe_div_func_int8_t_s_s(
           (0xD48F2AEC61BC9EF2LL >=
            (l_1481 =
                 (l_118 = func_109(
                      p_47, g_18,
                      ((safe_rshift_func_int16_t_s_s(
                           func_58(g_98.f3, (g_119--), l_118), 8)) <=
                       (safe_sub_func_uint64_t_u_u(
                           (((18446744073709551614UL >=
                              ((1L ^ (g_104--)) ^
                               (safe_rshift_func_uint16_t_u_s(g_98.f3, 5)))) <
                             0x43AD1FF0D8C8EF01LL) <= g_98.f0),
                           p_47))),
                      l_128, g_18)))),
           0x65L)) ^
       l_128)) {
    int32_t l_1492 = (-10L);
    const uint8_t l_1497 = 251UL;
    int32_t l_1514 = 0x8D35D7E1L;
    for (g_281 = (-24); (g_281 < 26); g_281++) {
      int64_t l_1486 = 0x101A4051A0688CE5LL;
      int8_t l_1494 = 7L;
      int32_t l_1515 = 1L;
      for (g_279 = (-22); (g_279 > 14);
           g_279 = safe_add_func_int16_t_s_s(g_279, 1)) {
        int16_t l_1504 = (-1L);
        int32_t l_1513 = 0L;
        g_307.f6 = 2L;
        l_118 = (0x8E3EFF6CL >=
                 (((l_1486 | (safe_rshift_func_int8_t_s_s(g_417, 2))),
                   0xD4BD06A9L) ||
                  (safe_unary_minus_func_int16_t_s(
                      ((safe_rshift_func_int8_t_s_s(
                           0x0CL, (l_1492 >= (l_1494 = (((((g_701 && l_1492) <=
                                                           p_47) > (-6L)) |
                                                         g_758),
                                                        l_1493))))) &&
                       g_279)))));
        for (g_360 = 0; (g_360 >= 3);
             g_360 = safe_add_func_uint32_t_u_u(g_360, 9)) {
          int64_t l_1507 = 0L;
          int32_t l_1510 = (-1L);

          g_307.f6 = 2L;

          g_307.f6 = 2L;
        }
      }
    }
  } else {
    struct S1 l_1535 = {6806, 0x968B0A25CF0D1546LL, 0x572B69DBL, 393};
    struct S0 l_1548 = {1L, 11, 1193, -0, 13233, 29, -10699, 15};
    int32_t l_1552 = 0x70647611L;
    uint16_t l_1669 = 65532UL;
    if (((!(-4L)),
         ((safe_div_func_uint64_t_u_u(
              (l_117 > ((safe_add_func_uint16_t_u_u(
                            (g_360 && 0x0642L), (safe_rshift_func_uint16_t_u_s(
                                                    0x3C9FL, g_98.f2)))) >
                        (0UL != ((p_47, g_98), 0xFF48201993DFB661LL)))),
              p_47)) <= 0x9ADFL))) {
      return p_47;
    } else {
      int16_t l_1550 = 1L;
      int32_t l_1551 = 0x1928E65BL;
      int32_t l_1553 = 0x01C707B6L;
      int32_t l_1554 = 0x6A9E6396L;
      int32_t l_1555 = 0x8CF64ACBL;
      int32_t l_1556 = 0x9B7F7B9FL;
      int32_t l_1557 = 0x322E8483L;
      int32_t l_1558 = 0x0EA0D51DL;
      g_307.f3 = 0L;
      { return p_47; }

    lbl_1561:
      l_1551 =
          ((safe_div_func_int32_t_s_s(2L, l_1481)) >
           ((safe_sub_func_int16_t_s_s(
                ((safe_add_func_uint16_t_u_u(
                     (safe_div_func_uint8_t_u_u(
                         (!(l_1535,
                            (safe_add_func_int16_t_s_s(
                                (((((~(((safe_lshift_func_uint16_t_u_u(
                                            ((((l_1549 = (safe_mul_func_uint16_t_u_u(
                                                    (safe_lshift_func_int8_t_s_u(
                                                        (safe_lshift_func_uint8_t_u_s(
                                                            (g_279 = (safe_lshift_func_uint16_t_u_u(
                                                                 (((!p_47) <
                                                                   ((0x88AF611DD5C109F3LL &
                                                                     (((g_207 =
                                                                            l_1535
                                                                                .f3),
                                                                       ((l_118 =
                                                                             (l_1548,
                                                                              0x921AL)) &&
                                                                        g_98.f3)) &
                                                                      0x3826L)),
                                                                    9L)) ^
                                                                  4294967289UL),
                                                                 l_1548.f1))),
                                                            6)),
                                                        g_631)),
                                                    g_307.f4))) &
                                               p_47) &&
                                              p_47) |
                                             g_1066),
                                            10)) &
                                        p_47),
                                       (-1L))) ||
                                    l_1493) == p_47) == g_98.f1) >=
                                 0x1A112A61L),
                                0x0A4CL)))),
                         g_307.f5)),
                     65535UL)) &
                 p_47),
                l_1550)) != l_1550));

      if (l_1535.f0)

      {
        g_307.f6 = ((g_1066++) >= l_1493);
      }

      if (l_1535.f0)
        goto lbl_1561;
    }
    g_307.f3 = l_117;
    if ((l_1535.f0 = 0x8D69824EL)) {
      int64_t l_1600 = 0L;
      const uint32_t l_1601 = 0UL;
      uint32_t l_1602 = 4UL;
      l_1602
 =
 (safe_mod_func_int16_t_s_s
  ((safe_div_func_uint8_t_u_u ((g_204 ^ (safe_mul_func_int16_t_s_s ((g_307.f0, ((safe_add_func_uint16_t_u_u ((((((((g_307.f5 ^= (safe_mul_func_int16_t_s_s ((((((((safe_div_func_uint32_t_u_u ((((safe_div_func_int16_t_s_s ((((safe_div_func_uint8_t_u_u (((safe_lshift_func_uint8_t_u_u ((((g_946 = ((((safe_add_func_int32_t_s_s ((safe_add_func_uint8_t_u_u ((!((safe_div_func_int8_t_s_s ((((((safe_mod_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_u (((0L < g_307.f6) && ((g_217 <= l_1590) & (safe_lshift_func_uint16_t_u_u ((safe_unary_minus_func_uint8_t_u ((l_1535.f0 ^= (safe_sub_func_int16_t_s_s ((safe_sub_func_uint16_t_u_u ((safe_rshift_func_int16_t_s_s (0x7335L, ((l_1549 = ((0UL <= (((!g_481), g_220) ^ g_483)), p_47)) < 0x4BL))), (-1L))), 0x5701L))))), 9)))), 3)), 0xF2L)) | p_47) || p_47) & g_307.f7) || p_47), 0x18L)) != p_47)), l_1535.f2)), l_1600)) > p_47) & l_1600) < l_1600)) >= 65535UL) != g_443), 6)), p_47), l_117)) ^ 1UL) < g_307.f0), 0x4698L)) & p_47) <= p_47), l_1493)) ^ (-2L)), 2L) < 18446744073709551615UL) <= p_47) ^ g_443) && g_98.f2), p_47))) >= g_1054), g_443) || l_117) >= 1UL) == 0L) | l_117), g_98.f1)) | 1UL)), l_1601))), (-1L))), g_363));
    } else {
      uint16_t l_1619 = 0xFF7DL;
      int32_t l_1620 = 6L;
      uint32_t l_1622 = 0UL;
    }
    g_307.f3 = l_117;

    return p_47;
  }
  return p_47;
}

static uint8_t func_48(int64_t p_49, const int8_t p_50, int8_t p_51) {
  uint16_t l_89 = 0UL;
  struct S0 l_92 = {0x67355DD1L, 7, 1276, -2, 15727, 10, -6928, 0};
  l_92.f3 =
      (g_93 = (safe_div_func_int8_t_s_s(
           (safe_rshift_func_uint16_t_u_u(
               (safe_div_func_uint32_t_u_u(
                   ((18446744073709551615UL &&
                     (l_92.f6 = (safe_unary_minus_func_int16_t_s(
                          ((7UL |
                            (safe_div_func_int32_t_s_s(
                                (p_49, l_89),
                                (((0x3FL ||
                                   ((((safe_lshift_func_uint8_t_u_u(
                                          (func_58(g_18, l_89, g_18), p_49),
                                          2)) != l_89),
                                     g_18),
                                    p_51)),
                                  l_92),
                                 g_18)))) <= p_51))))) >= g_18),
                   0xDCCD505EL)),
               1)),
           g_18)));
  for (l_89 = 0; (l_89 <= 41); ++l_89) {
    if (p_49)
      break;
    if (g_18)
      break;
    break;
  }
  for (p_51 = 0; (p_51 > 13); p_51 = safe_add_func_int32_t_s_s(p_51, 1)) {
    uint16_t l_99 = 65535UL;
    int32_t l_100 = 0xC3E41A78L;
    int32_t l_101 = 0x53ABC15DL;
    int32_t l_102 = 0x8D75FB74L;
    l_92.f6 = (g_98, l_99);
    if (g_93)

    {
      {
        if (p_49)
          break;
        if (g_18)
          break;
      }
    }
  }
  return p_49;
}

static int64_t func_58(const uint64_t p_59, const uint8_t p_60, uint32_t p_61) {
  uint16_t l_79 = 0x325EL;
  return l_79;
}

static int16_t func_64(const uint32_t p_65, int64_t p_66, uint32_t p_67,
                       int64_t p_68) {
  int64_t l_78 = 5L;
  return l_78;
}

static uint64_t func_109(int16_t p_110, int16_t p_111, int16_t p_112,
                         const int32_t p_113, uint16_t p_114) {
  int32_t l_129 = 0x7A2FDF83L;
  uint32_t l_140 = 0xDE7BC92AL;
  struct S0 l_143 = {1L, 18, 1169, 1, 5742, 15, 5886, 4};
  int32_t l_745 = 0x4CEAB69CL;
  struct S0 l_930 = {0x6F0D3EAEL, 29, 636, -3, -7272, 13, 9035, 2};
  int16_t l_972 = 0L;
  uint16_t l_1024 = 65527UL;
  struct S1 l_1114 = {-6679, 0xF7AB81215E8A9C49LL, 0xDC84F6C8L, 119};
  int64_t l_1253 = (-3L);
  uint32_t l_1336 = 0UL;
  uint16_t l_1412 = 0x05CAL;
  uint64_t l_1460 = 0x48313C83E0CFC13ELL;
  int8_t l_1480 = 0x60L;
  l_129 = 0x3368A3BAL;
  if ((l_129 <
       (safe_rshift_func_int8_t_s_s(
           0x1DL,
           ((safe_rshift_func_int8_t_s_s(
                func_134(
                    l_129, l_140, p_112,
                    (safe_div_func_uint16_t_u_u(
                        g_119,
                        (l_143, (safe_lshift_func_uint8_t_u_u(
                                    (func_146(l_143.f4, (g_93 | 1L)) != l_129),
                                    l_143.f0))))),
                    p_112),
                3)) ||
            g_488))))) {
    int32_t l_746 = 0x66E0D8BFL;
    int32_t l_757 = (-1L);
    int32_t l_765 = 0x9DF1E749L;
    struct S0 l_801 = {0xA338B530L, 7, 1172, -3, 9324, 19, -8025, 6};
    const int32_t l_814 = 3L;
    uint32_t l_880 = 0x7AD4BAC8L;
    g_307.f6 ^=
        ((safe_lshift_func_uint8_t_u_u(
             (safe_mul_func_uint8_t_u_u(
                 (g_217,
                  (safe_div_func_uint8_t_u_u(
                      (safe_lshift_func_int8_t_s_u(
                          ((l_143,
                            (((((((-1L) >= 0xCD9679E9L) |
                                 (safe_lshift_func_uint8_t_u_u(
                                     (g_207 =
                                          (((safe_add_func_uint32_t_u_u(
                                                g_281,
                                                ((safe_mod_func_int64_t_s_s(
                                                     (g_98.f1 =
                                                          (((safe_sub_func_int16_t_s_s(
                                                                ((safe_sub_func_uint16_t_u_u(
                                                                     4UL,
                                                                     (p_112 &=
                                                                      (safe_mod_func_uint16_t_u_u(
                                                                          (safe_add_func_int32_t_s_s(
                                                                              (((((l_143
                                                                                       .f6,
                                                                                   (g_631 ||
                                                                                    ((g_307
                                                                                          .f1 =
                                                                                          (-1L)) ^
                                                                                     4294967295UL))),
                                                                                  p_111),
                                                                                 p_111) ^
                                                                                p_114) ||
                                                                               l_745),
                                                                              g_104)),
                                                                          0x3A49L))))) !=
                                                                 0xBB774B55L),
                                                                p_114)),
                                                            g_281) > p_114)),
                                                     g_93)) < g_417))) &
                                            0x27857436L) ^
                                           9L)),
                                     0))) &&
                                p_113),
                               0xF9E5E86AL) &&
                              l_746) ||
                             0x424B927FL)) &
                           l_143.f7),
                          3)),
                      g_103))),
                 l_129)),
             0)),
         0xB7963571L);

  } else {
    const int64_t l_883 = (-1L);
    int32_t l_905 = 5L;
    const int32_t l_906 = 1L;
    struct S1 l_908 = {-3047, 0xD8377A5DEB66F10FLL, 18446744073709551615UL,
                       119};
    int32_t l_931 = (-2L);
    struct S0 l_993 = {-1L, -5, 1963, -3, 19942, 21, 569, 5};
    int32_t l_1261 = 0x73F73A03L;
    uint32_t l_1269 = 4UL;
    int8_t l_1314 = 0xDBL;
    int64_t l_1461 = 0x312FCB12E92E1A4ALL;
    int32_t l_1462 = 0x4ADB0A08L;
    uint8_t l_1465 = 5UL;
    if ((((g_488 =
               (p_114,
                ((safe_lshift_func_uint16_t_u_s(
                     l_883,
                     ((l_883 < g_360),
                      ((0x45B8A790L >=
                        (g_307,
                         ((safe_sub_func_int32_t_s_s(
                              (g_443 ^
                               (~(safe_unary_minus_func_uint16_t_u((
                                   p_114 ^=
                                   ((safe_unary_minus_func_uint32_t_u((
                                        ((p_111 & (g_98, g_307.f7)) || l_883) >=
                                        0x37982447L))) < l_883)))))),
                              0xE38B374BL)) |
                          4294967288UL))),
                       (-7L))))) != g_217))) >= 4UL) |
         4L)) {
      int16_t l_902 = (-1L);
      int32_t l_907 = 0x37CF8569L;
      l_143.f6 =
          ((4294967295UL ==
            (0x28L |
             (((l_907 =
                    ((g_631 = g_628) <=
                     (18446744073709551607UL !=
                      (safe_sub_func_int32_t_s_s(
                          ((safe_mod_func_uint64_t_u_u(
                               (p_114,
                                ((((safe_mul_func_uint16_t_u_u(
                                       p_114,
                                       (safe_lshift_func_int8_t_s_u(
                                           ((g_281 &
                                             ((safe_div_func_int64_t_s_s(
                                                  ((~(l_905 |=
                                                      ((safe_sub_func_int16_t_s_s(
                                                           l_902,
                                                           (~(safe_rshift_func_int16_t_s_u(
                                                               0x7F2AL,
                                                               2))))) !=
                                                       g_628))),
                                                   0x6F8F0F764324570BLL),
                                                  p_110)) >= p_112)) &&
                                            l_143.f3),
                                           7)))) &
                                   0L),
                                  l_129) < (-4L))),
                               l_883)),
                           0xC7E05AD1L),
                          l_906))))),
               l_908),
              l_907))),
           l_902);
      return p_111;
    } else {
      uint8_t l_909 = 0x4BL;
      int8_t l_949 = (-1L);
      int32_t l_971 = (-1L);
      int32_t l_973 = 8L;
      struct S1 l_1044 = {-5706, 9L, 0x34E7E85BL, 40};
      int32_t l_1200 = 1L;
      struct S0 l_1277 = {-10L, 6, 1045, 4, 9469, 26, -5317, 7};
      int32_t l_1335 = 0x55F5E5C0L;
      int32_t l_1453 = 2L;
      l_909 = (g_281 = p_110);
      l_931 = (safe_div_func_uint16_t_u_u(
          p_114,
          (((safe_lshift_func_int16_t_s_u(p_111, 15)) &&
            (safe_add_func_int16_t_s_s(
                (safe_rshift_func_int16_t_s_s((p_110 = p_110), 1)),
                (((l_908.f1,
                   (((l_908.f0 = (safe_add_func_int16_t_s_s(
                          (safe_mul_func_uint8_t_u_u(
                              (++g_701),
                              (((safe_div_func_int64_t_s_s(
                                    (l_905 = 0xF5D59AC9F51C6097LL),
                                    ((((safe_mod_func_int16_t_s_s(1L, p_114)) |
                                       (safe_add_func_uint8_t_u_u(
                                           p_113, (0L != 9L)))) > (-1L)),
                                     0xA10D964F1AB48FF5LL))) &
                                p_114) < l_909))),
                          p_114))),
                     g_483),
                    l_930)),
                  g_93) &
                 65535UL)))),
           l_909)));
      if ((((safe_lshift_func_uint8_t_u_u(6UL, g_307.f4)) |
            (+(safe_lshift_func_int8_t_s_s(
                (g_360 &=
                 ((safe_mul_func_uint8_t_u_u(
                      (g_417++),
                      (safe_lshift_func_int8_t_s_u(
                          p_114, (safe_div_func_uint32_t_u_u(
                                     (l_143.f1 = l_909), p_113)))))) <= p_113)),
                g_217)))) <= (safe_div_func_uint16_t_u_u((--g_946), p_112)))) {
        int16_t l_969 = 0L;
        int32_t l_1027 = (-1L);
        struct S1 l_1031 = {-3830, 0x9DF5E5DF50837B7ELL, 18446744073709551610UL,
                            110};
        if ((18446744073709551615UL !=
             (0UL ||
              ((l_949 |
                ((4294967288UL > p_113) >
                 ((g_104--) <=
                  ((safe_mul_func_int8_t_s_s(
                       (safe_sub_func_int8_t_s_s(
                           (g_360 = (g_220 = (l_143.f6 |= ((-1L) | l_931)))),
                           l_143.f5)),
                       (((g_98.f2 != g_276), (-1L)) | g_307.f3))),
                   l_930.f5)))) ^
               0x88C1L)))) {
          int16_t l_968 = 0xED9EL;
          int32_t l_970 = (-1L);
          struct S0 l_976 = {0xE10AEC7EL, 24, 717, -2, -18639, 22, 3885, 2};
          struct S1 l_1109 = {-2395, 0xB1577383BEA3FAB0LL, 0UL, 489};
          if ((((((((g_486 = 0x966CL) ||
                    (safe_div_func_int16_t_s_s(
                        0L,
                        (safe_sub_func_int8_t_s_s(
                            ((safe_sub_func_int8_t_s_s(
                                 (safe_sub_func_int8_t_s_s(
                                     ((g_631 &=
                                       ((safe_mod_func_uint64_t_u_u(
                                            (safe_lshift_func_int16_t_s_u(
                                                (p_112 & g_363), l_930.f2)),
                                            (((g_279++) |
                                              ((+((((l_970 | g_701), l_976),
                                                   (safe_mod_func_int16_t_s_s(
                                                       (safe_mul_func_int16_t_s_s(
                                                           0xF447L, (-7L))),
                                                       l_909))) &&
                                                  g_204)) < p_110)) &&
                                             g_481))) < 0xA1D685D0L)) ^
                                      g_104),
                                     l_973)),
                                 p_113)) ^
                             p_114),
                            p_112))))) <= l_883) < l_140) != g_488) |
                l_968) >= g_98.f0)) {
            int32_t l_1004 = 1L;
            l_1004 =
                ((safe_sub_func_uint64_t_u_u(
                     ((((l_976.f1 = (0x67L > l_976.f6)) <
                        (safe_rshift_func_int8_t_s_u(
                            (safe_sub_func_int32_t_s_s(
                                ((safe_add_func_int16_t_s_s(
                                     ((g_98.f2 >
                                       (((safe_mod_func_int32_t_s_s(
                                             ((safe_lshift_func_int8_t_s_s(
                                                  (g_360 =
                                                       (p_110, (l_993, g_204))),
                                                  0)) >=
                                              ((safe_mod_func_int8_t_s_s(
                                                   ((safe_div_func_int64_t_s_s(
                                                        (safe_mul_func_uint16_t_u_u(
                                                            65535UL,
                                                            (((safe_sub_func_int64_t_s_s(
                                                                  g_417,
                                                                  (l_976.f3 =
                                                                       ((safe_sub_func_uint16_t_u_u(
                                                                            p_110,
                                                                            (-1L))),
                                                                        0xF7866216343427CBLL)))) &
                                                              l_976.f5) ^
                                                             g_307.f0))),
                                                        p_114)) &
                                                    g_758),
                                                   g_103)) &
                                               (-1L))),
                                             g_307.f1)) ^
                                         g_119) ^
                                        l_973)) |
                                      p_114),
                                     65526UL)) &
                                 g_104),
                                l_993.f7)),
                            g_483))) < l_976.f4) ^
                      0x7B66B1D3EB509B68LL),
                     p_114)) ||
                 0xB705DFA7L);
            g_307.f6 = (safe_sub_func_int16_t_s_s(
                p_114,
                (((((g_481 = 0x6FE9L) >
                    ((safe_unary_minus_func_uint32_t_u((
                         l_930.f2 &&
                         (safe_lshift_func_uint16_t_u_u(
                             (safe_rshift_func_int16_t_s_s(
                                 (safe_div_func_int8_t_s_s(
                                     ((g_946++) !=
                                      ((safe_div_func_int8_t_s_s(
                                           ((g_758 = p_113) ==
                                            (((safe_div_func_uint16_t_u_u(
                                                  ((safe_rshift_func_uint8_t_u_u(
                                                       (g_628 == g_307.f0),
                                                       ((((safe_div_func_int8_t_s_s(
                                                              0x37L, p_114)) |
                                                          l_930.f7) <
                                                         0x314B616A4F4C3294LL) |
                                                        p_113))) ||
                                                   g_307.f0),
                                                  l_976.f2)),
                                              65531UL) <= g_307.f7)),
                                           0xE1L)) <= p_112)),
                                     (-8L))),
                                 g_98.f3)),
                             9))))) ||
                     l_969)) <= g_701),
                  p_113) < l_1004)));
          } else {
            uint64_t l_1028 = 0xBF27C34AF3FA584CLL;
            l_1024++;
            l_973 = l_908.f2;
            l_1027 ^= p_112;
            --l_1028;
          }
          l_971 = p_114;
          if ((l_969,
               (l_971 = ((((l_1031, p_111) <=
                           (safe_lshift_func_int8_t_s_u(
                               (0x5851779CL >
                                (g_631 >=
                                 (safe_sub_func_int64_t_s_s(
                                     (0xEBL &&
                                      (safe_mod_func_int32_t_s_s(
                                          (safe_mod_func_int8_t_s_s(
                                              ((g_307, (l_908.f3, g_307)), 4L),
                                              l_968)),
                                          p_114))),
                                     p_110)))),
                               p_114))) != g_307.f3) &
                         0xFAL)))) {
            int64_t l_1055 = 0L;
            int32_t l_1060 = 6L;
            int32_t l_1061 = 6L;
            g_281 =
                ((safe_add_func_uint8_t_u_u(
                     (((l_970 |=
                        ((g_701 |= g_119) ||
                         (((l_1044,
                            (safe_mul_func_int8_t_s_s(
                                (safe_unary_minus_func_int64_t_s((
                                    g_758 &=
                                    (l_993.f6 ^=
                                     (((safe_lshift_func_uint8_t_u_u(
                                           ((l_143.f7 ^
                                             ((0x21L <=
                                               ((safe_rshift_func_uint16_t_u_u(
                                                    (l_1055 &=
                                                     (g_1054 ^= (--g_946))),
                                                    ((((safe_div_func_int32_t_s_s(
                                                           (safe_sub_func_int8_t_s_s(
                                                               1L,
                                                               (l_1027 =
                                                                    (((l_1060 ==
                                                                       l_1061),
                                                                      ((((65535UL >
                                                                          (safe_add_func_int32_t_s_s(
                                                                              (safe_mul_func_uint8_t_u_u(
                                                                                  p_113,
                                                                                  l_1044
                                                                                      .f2)),
                                                                              p_113))) ||
                                                                         l_129),
                                                                        l_976),
                                                                       l_1031)),
                                                                     (-2L))))),
                                                           0x257DEB80L)) &&
                                                       1L),
                                                      0x9AL) &
                                                     l_1061))) >= g_363)) ||
                                              g_307.f5)) == g_98.f0),
                                           6)) &&
                                       p_110) == 0x3073A5AAL))))),
                                g_1066))) != g_281) == 0x3C8B14D5L))) |
                       p_111) ||
                      p_114),
                     l_140)) ^
                 g_307.f4);
            g_307.f3 &= (safe_lshift_func_uint8_t_u_u(
                ((l_976.f1 |= p_114) ^
                 ((safe_div_func_uint16_t_u_u(
                      (l_1044.f1 &&
                       (g_104 =
                            (((l_1027 ^
                               (l_908.f0 ^= (safe_sub_func_uint16_t_u_u(
                                    (l_1031.f0 = g_307.f5),
                                    (safe_div_func_int32_t_s_s(
                                        ((safe_add_func_uint32_t_u_u(
                                             0xB8FFBD81L,
                                             (safe_add_func_uint64_t_u_u(
                                                 ((safe_mod_func_uint64_t_u_u(
                                                      0x3531D677254677FFLL,
                                                      p_111)) <=
                                                  (p_111 ||
                                                   ((+((safe_add_func_uint8_t_u_u(
                                                           (g_204, 0xEBL),
                                                           0xF4L)) != g_417)) &
                                                    0x1A59L))),
                                                 p_111)))) <= p_111),
                                        p_112)))))) ^
                              1L),
                             p_110))),
                      8UL)) &
                  p_111)),
                g_307.f1));
            g_98.f0 = (safe_mod_func_int32_t_s_s(
                ((l_1031.f0 &=
                  ((+((safe_add_func_uint32_t_u_u(
                          (((safe_sub_func_uint8_t_u_u(
                                g_276,
                                ((-7L) &
                                 (~((l_972 < (safe_rshift_func_int16_t_s_s(
                                                 p_111, 6))) <=
                                    ((g_279 > 4294967295UL) !=
                                     (((safe_sub_func_uint32_t_u_u(
                                           ((g_307.f0 &
                                             (safe_div_func_int16_t_s_s(
                                                 ((l_973 =
                                                       (l_1031.f2 >
                                                        (p_114 = 0xE324L))) !=
                                                  1L),
                                                 (-1L)))) < g_93),
                                           1L)),
                                       1UL),
                                      5L))))))) >= g_1054) ^
                           l_1061),
                          0L)) != 0x25B2L)) != g_104)) ^
                 7L),
                g_307.f5));
          } else {
            uint16_t l_1115 = 0x235CL;
            l_976.f3 ^=
                ((g_307.f7 = (safe_mul_func_uint16_t_u_u(
                      ((safe_rshift_func_int8_t_s_s(
                           ((safe_mul_func_uint16_t_u_u((l_973 <= g_481),
                                                        p_113)) <
                            (safe_add_func_int16_t_s_s(
                                (((safe_mod_func_uint16_t_u_u(
                                      ((safe_sub_func_int32_t_s_s(
                                           ((safe_add_func_uint8_t_u_u(
                                                (l_143.f1 ^=
                                                 (((l_1109, 4UL) && p_110) ^
                                                  (safe_lshift_func_int16_t_s_s(
                                                      (safe_div_func_int8_t_s_s(
                                                          (p_112 <= 1L),
                                                          ((((((((l_1114,
                                                                  (-1L)) !=
                                                                 p_114) <=
                                                                0x82L) < p_110),
                                                              0xAD19L) ^
                                                             g_104),
                                                            g_307.f4),
                                                           0x21L))),
                                                      12)))),
                                                255UL)) ||
                                            p_114),
                                           g_276)),
                                       5UL),
                                      p_111)) < l_1031.f1) &
                                 p_113),
                                65527UL))),
                           3)),
                       g_307.f5),
                      8UL))) < 0xF47B3089L);
            g_307.f6 = 0x4A235587L;
            l_1115 = 0L;
            l_976.f3 |= g_758;
          }
          l_976.f1 ^= 0xFE6D830DL;
        } else {
          int16_t l_1135 = 0L;
          int32_t l_1145 = 0L;
          for (g_483 = 0; (g_483 >= (-10));
               g_483 = safe_sub_func_int64_t_s_s(g_483, 2)) {
            int64_t l_1124 = 0x4C2A28E9C6DE6068LL;
            int32_t l_1136 = 9L;
            g_307.f1 =
                (0x4AL ^
                 ((safe_mod_func_uint16_t_u_u(
                      (p_114 = 0UL),
                      (safe_add_func_int32_t_s_s(
                          (safe_mod_func_uint16_t_u_u(
                              (g_946 = l_1124),
                              ((safe_mod_func_int32_t_s_s(
                                   (safe_lshift_func_int16_t_s_u(
                                       ((((g_486 = (1L != p_111)) &
                                          ((safe_div_func_int16_t_s_s(
                                               ((safe_rshift_func_uint16_t_u_u(
                                                    (safe_add_func_uint32_t_u_u(
                                                        (p_113 < g_307.f6),
                                                        (++g_1066))),
                                                    7)),
                                                p_112),
                                               (((safe_add_func_int32_t_s_s(
                                                     (safe_sub_func_int8_t_s_s(
                                                         (0xE67A4471DFB285C8LL >
                                                          l_993.f5),
                                                         p_113)),
                                                     g_443)) |
                                                 0x39F37033L),
                                                p_111))),
                                           1L)) <= 0xDFL) < l_1044.f0),
                                       11)),
                                   l_993.f4)) ||
                               0xCC3D51A7DBA276AELL))),
                          g_207)))) == l_969));
            l_1145 = ((l_930.f1 =
                           (safe_rshift_func_int8_t_s_u((g_360 | p_111), 2))) &&
                      0xB49F041EL);
          }
        }
        for (g_1054 = 19; (g_1054 == 8);
             g_1054 = safe_sub_func_int32_t_s_s(g_1054, 4)) {
          int32_t l_1156 = 0xB924A1EEL;
          int32_t l_1159 = 0x70C37922L;
          l_1114.f0 =
              ((g_18, (0xB2L < p_114)) !=
               (0xA2B20D85L ^
                (safe_rshift_func_uint16_t_u_s(
                    (l_1159 &=
                     ((((8L !=
                         (safe_rshift_func_int8_t_s_u(
                             (safe_lshift_func_int16_t_s_s(
                                 ((g_18 >= (8L >= (safe_rshift_func_uint8_t_u_u(
                                                      (((g_417--) | 255UL) <=
                                                       (l_971 |= 65535UL)),
                                                      2)))) &&
                                  g_946),
                                 g_220)),
                             3))),
                        p_113) &
                       l_905) > (-5L))),
                    p_112))));
          for (l_971 = 6; (l_971 != 19); l_971++) {
            int8_t l_1193 = 4L;
            int32_t l_1201 = 0x30D91F6FL;
     g_281
       =
       (g_307.
        f3
        =
        (safe_mul_func_uint8_t_u_u
  ((safe_mod_func_int16_t_s_s (((l_1200 |= (((safe_div_func_uint16_t_u_u ((g_946 = (((l_1044.f0 = (safe_sub_func_uint16_t_u_u ((safe_sub_func_uint32_t_u_u ((safe_div_func_int64_t_s_s ((safe_lshift_func_int16_t_s_u ((safe_mod_func_uint8_t_u_u ((safe_sub_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_s (l_1031.f1, ((l_993.f6 = (p_110 | ((((safe_sub_func_int8_t_s_s (((((safe_add_func_int32_t_s_s (((g_276 == ((safe_rshift_func_int16_t_s_s (g_281, ((g_98, p_112) != ((safe_unary_minus_func_uint8_t_u (((((safe_rshift_func_int8_t_s_s (((l_1027 = (l_1193 = p_114)) && ((((safe_mod_func_int8_t_s_s (((-1L) <= (l_973 = (safe_div_func_int64_t_s_s (((g_104 = (safe_sub_func_uint32_t_u_u (3UL, p_113))) && g_946), 1L)))), g_98.f3)) != g_307.f5) > 0xDD17AC71L) && g_307.f4)), g_279)) == 0x4DBCA3EDL) != g_363) != g_417))) >= g_1054)))) || g_276)) <= p_112), 0xD417B71FL)) <= 0x5AL) ^ 0x2DL) & 0x76L), 0UL)) < l_1044.f0) < l_143.f3) >= 0x03L))) < (-10L)))), g_631)), p_114)), l_1031.f3)), p_111)), g_360)), p_114))), l_1156) < 0x62C41E83F4391576LL)), 0xA2FEL)) <= l_993.f7) & 0x2ABD710EL)), g_483), p_110)), l_993.f3)));
     l_1201 &=
         ((--g_279) <=
          (safe_mod_func_int8_t_s_s(
              (safe_sub_func_int32_t_s_s(
                  (safe_mul_func_uint16_t_u_u(l_969, ((g_104--) & g_307.f5))),
                  ((g_307.f4 >= 0x80FA60F4L) != p_112))),
              ((((safe_rshift_func_int16_t_s_u(
                     ((((safe_sub_func_uint64_t_u_u(
                            ((~g_98.f0) &&
                             (g_98.f1 >
                              (((l_930.f1 = l_1156) ^
                                ((l_1200 = (safe_mod_func_uint8_t_u_u(
                                      ((((safe_rshift_func_uint8_t_u_u(g_103,
                                                                       g_946)) ^
                                         l_908.f3) < 0x84L) |
                                       p_112),
                                      0x77L))) &
                                 (-7L))) != 0xD5L))),
                            p_112)) == 7L) == g_98.f0) < l_931),
                     l_1159)) == p_111) >= 2UL) ^
               p_114))));
     g_307.f1 = (((!p_113), g_98), 0L);
     l_1114.f0 |= (safe_mul_func_int8_t_s_s(
         ((!l_1193) ^
          ((safe_sub_func_int64_t_s_s(
               (l_930.f1 = (-8L)),
               (l_1044,
                ((safe_mul_func_uint8_t_u_u(
                     (safe_mul_func_int16_t_s_s(
                         ((safe_mul_func_int16_t_s_s(
                              ((((safe_unary_minus_func_int64_t_s((
                                     (safe_sub_func_int64_t_s_s(
                                         (safe_add_func_uint32_t_u_u(
                                             4294967295UL,
                                             ((safe_lshift_func_int8_t_s_u(
                                                  ((safe_mul_func_uint8_t_u_u(
                                                       (g_98,
                                                        (safe_rshift_func_int16_t_s_u(
                                                            (p_110 !=
                                                             (g_307.f1 &= 0L)),
                                                            13))),
                                                       (safe_mul_func_uint8_t_u_u(
                                                           0UL,
                                                           (((g_360 >= p_110) ^
                                                             g_217) ==
                                                            p_111))))) &
                                                   l_993.f4),
                                                  l_931)) &&
                                              0x9C8A6BFD7E7EF579LL))),
                                         l_1044.f0)) &&
                                     l_909))) |
                                 0UL) <= g_443) <= l_1193),
                              0x7521L)) != 0xFCBE4D2CAFC49587LL),
                         l_1044.f0)),
                     g_946)) ^
                 p_114)))) ||
           l_1027)),
         p_110));
          }
        }
      } else {
        uint16_t l_1260 = 0xF76EL;
        int32_t l_1262 = 1L;
        int32_t l_1316 = 0L;
        uint16_t l_1409 = 5UL;
        g_98.f0 |=
            (l_1262 =
                 (0UL &
                  ((l_930,
                    (safe_mul_func_uint8_t_u_u(
                        (safe_mod_func_int16_t_s_s(
                            (safe_lshift_func_uint8_t_u_u(
                                (safe_div_func_int64_t_s_s(
                                    ((safe_mul_func_uint16_t_u_u(
                                         l_1253,
                                         (l_1200 |
                                          (safe_add_func_uint32_t_u_u(
                                              l_1044.f2,
                                              (((safe_add_func_uint16_t_u_u(
                                                    (l_908.f0 <
                                                     (safe_mod_func_uint32_t_u_u(
                                                         (0x3C60CDE3L ||
                                                          (l_1044.f2 >
                                                           65532UL)),
                                                         l_1260))),
                                                    l_1260)) != g_93) <=
                                               l_1044.f1)))))) >= p_110),
                                    l_1261)),
                                p_112)),
                            7L)),
                        0x7DL))),
                   0x08L)));
        for (p_112 = (-17); (p_112 < 0); p_112++) {
          int32_t l_1274 = 0xB013AA90L;
          struct S1 l_1315 = {7536, 1L, 0xB9CC9785L, 464};
          int32_t l_1318 = 0x163186ABL;
          int64_t l_1339 = 0x3BE392B6E0E4206ELL;
          struct S0 l_1388 = {0L, -30, 1897, -3, 13054, 10, -9522, 9};
          int64_t l_1393 = (-1L);
          if (((safe_add_func_int8_t_s_s(
                   (safe_add_func_int8_t_s_s(l_1269, (g_486 > (!g_307.f2)))),
                   (p_113 >
                    (safe_mul_func_uint8_t_u_u(
                        ((safe_rshift_func_int8_t_s_u(
                             (l_905 =
                                  (((l_1274,
                                     ((safe_mul_func_uint16_t_u_u(
                                          ((l_143.f1 = (((g_307.f4 ^ l_745) <
                                                         (((-3L) & g_443) ==
                                                          0xE0EFAB4FL)),
                                                        0xCED0L)) == l_1262),
                                          l_971)) < g_207)) &
                                    l_908.f1) |
                                   18446744073709551607UL)),
                             6)) >= g_307.f1),
                        1UL))))) < l_1253)) {
            int8_t l_1317 = 0xFCL;
            struct S0 l_1337 = {0xD4BEC89DL, 31, 1736,  -0,
                                -15151,      14, -8909, 1};
     l_1318
       &=
       ((l_1277, (safe_rshift_func_int16_t_s_s ((safe_lshift_func_int16_t_s_s ((l_1317 = ((l_1316 = (safe_lshift_func_uint16_t_u_u (((g_946++) ^ (safe_lshift_func_uint16_t_u_u ((((safe_lshift_func_int16_t_s_s (g_279, (safe_mod_func_uint32_t_u_u (((((l_1262 ^= (safe_sub_func_uint32_t_u_u ((safe_div_func_uint64_t_u_u ((((((safe_mod_func_uint8_t_u_u (((((safe_rshift_func_uint8_t_u_s ((((safe_add_func_uint16_t_u_u (((safe_add_func_uint16_t_u_u ((safe_rshift_func_int16_t_s_u ((p_111, p_112), 15)), 0x78BBL)) > ((safe_mod_func_int16_t_s_s (0x78F8L, g_758)) > l_143.f4)), ((((((safe_add_func_uint64_t_u_u (((safe_mul_func_int16_t_s_s ((safe_lshift_func_int16_t_s_s (((g_486, g_360) && p_113), 1)), g_220)) & g_103), p_110)) | g_307.f4) != g_363), g_98), g_758) | l_1314))), g_307.f4) != g_483), p_111)) <= l_931) & 0x2DE92ED5L) == 1L), g_481)) != l_143.f1) ^ g_307.f4), l_973) > 1UL), 0x9D31D54F8F9AFA54LL)), p_111))) == (-3L)), l_883) <= p_114), 0x9AF71E28L)))), l_1315), g_93), 15))), 7))) > (-2L))), 10)), g_98.f3))) ^ g_1054);
     if (l_1315.f1)
       continue;
     l_971 =
         (((((((safe_unary_minus_func_uint8_t_u((
                   l_1277.f3 = (safe_mod_func_uint16_t_u_u(
                       (((g_1066 <= g_417) < 0xC0FADE25L) ||
                        ((+l_1318),
                         (safe_add_func_uint16_t_u_u(
                             (p_114 =
                                  ((safe_add_func_int64_t_s_s(
                                       l_1317,
                                       (((((safe_div_func_uint32_t_u_u(
                                               ((((--g_701) ||
                                                  (safe_add_func_int8_t_s_s(
                                                      (((p_114,
                                                         (g_104 &=
                                                          (l_1336 =
                                                               ((((((p_113 ||
                                                                     6UL),
                                                                    ((safe_lshift_func_uint16_t_u_u(
                                                                         ((+(((safe_unary_minus_func_int16_t_s(
                                                                                  g_481)) ||
                                                                              p_110),
                                                                             7UL)) ||
                                                                          0x22C9AB32L),
                                                                         l_1335)) |
                                                                     l_883)) ^
                                                                   0x7DL) ==
                                                                  p_111) ||
                                                                 p_111) ^
                                                                g_443)))),
                                                        l_1337),
                                                       0xC5L),
                                                      247UL))) <= g_1338),
                                                l_1260),
                                               p_112)) &&
                                           g_1054) |
                                          l_1339) == g_443) >= 0x3FL))) ==
                                   l_1315.f3)),
                             l_1315.f3)))),
                       p_112))))),
               p_113),
              0x07B13E5C198C03C2LL) ||
             p_114),
            0xBE00L),
           l_971) &
          g_946);
     l_971 = (safe_div_func_int32_t_s_s(
         ((safe_sub_func_int16_t_s_s(
              p_114,
              ((g_119,
                ((l_1337.f3 |= ((safe_add_func_uint8_t_u_u(
                                    (g_417--), (g_279 &= (g_488 &= p_114)))),
                                l_1260)),
                 l_1315)),
               ((g_98.f1 =
                     (p_114 ==
                      ((safe_mul_func_int16_t_s_s(
                           g_1066,
                           ((((safe_sub_func_int64_t_s_s(
                                  ((((safe_mul_func_uint16_t_u_u(
                                         (safe_lshift_func_uint16_t_u_u(
                                             (l_1277.f6 =
                                                  ((7UL &
                                                    (safe_lshift_func_int16_t_s_u(
                                                        (safe_mul_func_int16_t_s_s(
                                                            g_360, p_114)),
                                                        l_1337.f4))) &
                                                   l_1317)),
                                             l_1260)),
                                         l_1337.f4)) < l_971) >= g_488),
                                   g_307.f0),
                                  7L)),
                              9UL),
                             l_1337.f4) != 0xE36BB04FL))) == p_114))),
                0xAB4BL)))),
          g_628),
         0x95025769L));
          } else {
            uint16_t l_1362 = 1UL;
            int32_t l_1379 = 0x6440E957L;
            l_1379 =
                ((g_307.f5 =
                      ((l_1262 = 0xDB4CDE8FL) |
                       (((~g_18) == (l_1362 = 0xFB24L)) &
                        ((safe_rshift_func_int16_t_s_u(
                             ((safe_add_func_uint8_t_u_u(
                                  0x36L,
                                  (((safe_div_func_uint16_t_u_u(
                                        (safe_rshift_func_int16_t_s_u(0xAFA9L,
                                                                      5)),
                                        (safe_lshift_func_uint16_t_u_u(
                                            l_1277.f5,
                                            (safe_div_func_uint8_t_u_u(
                                                6UL,
                                                (safe_mod_func_uint8_t_u_u(
                                                    (safe_rshift_func_uint16_t_u_u(
                                                        g_204, g_98.f3)),
                                                    g_486)))))))),
                                    g_98.f0) >= l_973))) ||
                              g_307.f4),
                             p_112)) != g_276)))) |
                 p_114);
            return l_1277.f0;
          }
          for (l_1044.f2 = (-29); (l_1044.f2 <= 28); l_1044.f2++) {
            int8_t l_1400 = 0xD7L;
            l_1400 = (safe_rshift_func_int8_t_s_u(
                (((safe_lshift_func_int8_t_s_s(
                      (safe_rshift_func_int8_t_s_s(
                          ((((g_279,
                              (l_1388,
                               ((safe_div_func_uint16_t_u_u(
                                    (safe_sub_func_uint32_t_u_u(
                                        (((!l_1260) & l_1393) & l_1315.f3),
                                        0UL)),
                                    (((l_1114.f0 =
                                           (0xFEL ||
                                            (g_220,
                                             (safe_div_func_uint64_t_u_u(
                                                 (safe_div_func_uint64_t_u_u(
                                                     (!(l_1318 =
                                                            (safe_rshift_func_int16_t_s_u(
                                                                (0x7A19EDDDL >
                                                                 p_111),
                                                                7)))),
                                                     (-5L))),
                                                 p_112))))) &&
                                      3UL),
                                     0x0DEFL))) &
                                l_973))) &&
                             7UL),
                            l_1315.f2) &&
                           0xD6A99D5F948D13F4LL),
                          0)),
                      l_1277.f4)) > l_993.f6),
                 p_111),
                5));
          }
        }
        l_993.f6 = (safe_add_func_uint64_t_u_u(
            (((safe_rshift_func_int16_t_s_u(
                  (safe_add_func_int8_t_s_s(
                      (((safe_lshift_func_int16_t_s_u(l_1409, 9)) ^ 6L), 0x5DL),
                      (safe_sub_func_int16_t_s_s(p_111, (l_1412 < g_363))))),
                  (safe_rshift_func_uint8_t_u_s(
                      ((safe_lshift_func_uint8_t_u_u(p_113, 6)),
                       ((safe_lshift_func_uint16_t_u_u(
                            l_143.f3,
                            (~(safe_rshift_func_int16_t_s_u(
                                (safe_div_func_int16_t_s_s(
                                    ((safe_rshift_func_uint16_t_u_s(
                                         (safe_rshift_func_int8_t_s_s(
                                             (safe_div_func_int32_t_s_s(
                                                 (l_931 = (safe_lshift_func_int16_t_s_s(
                                                      (g_486 =
                                                           (safe_mul_func_uint16_t_u_u(
                                                               p_114,
                                                               0x4462L))),
                                                      0))),
                                                 0x4396D77DL)),
                                             l_1261)),
                                         9)) > 0x077EL),
                                    (-9L))),
                                g_276))))) |
                        0x8AD0427AL)),
                      5)))) ||
              l_1409) == l_909),
            1UL));
 l_973
   =
   ((l_930.f3 |= ((safe_sub_func_int32_t_s_s ((safe_add_func_uint32_t_u_u ((safe_div_func_int16_t_s_s (((g_18 <= (((p_112 > (((((l_1277.f1 = (g_276 = ((safe_lshift_func_uint16_t_u_u (p_112, 15)) <= ((l_1316 = (safe_mod_func_uint32_t_u_u ((safe_mul_func_uint16_t_u_u ((g_946 = ((l_908.f0 = (safe_mod_func_uint64_t_u_u ((l_930.f6 > (p_112, g_701)), (safe_sub_func_int32_t_s_s ((((safe_div_func_int8_t_s_s ((!((p_110 = (((safe_rshift_func_int8_t_s_u (((((((0xE2L <= (l_1453, ((p_112 && p_112) >= g_307.f6))) <= 0x3127261BL), p_111) > p_110) < l_1044.f0) == p_114), l_973)) == l_993.f1) == 0xF3BDL)) == 0xCD1FL)), 0x50L)) < (-10L)) ^ 1L), g_758))))) && l_143.f2)), g_98.f2)), g_98.f3))) <= 0x7DE090A9L)))) || g_486) && g_217) == g_93) < 8UL)) & g_483) ^ (-8L))) <= 0x3C81L), l_1409)), l_908.f2)), l_1277.f7)) > p_114)) != p_113);
      }
    }
    for (p_112 = (-28); (p_112 < 2);
         p_112 = safe_add_func_int16_t_s_s(p_112, 9)) {
      return p_112;
    }
    l_143.f6 = (~(
        ((safe_mod_func_uint32_t_u_u(
             ((((l_972,
                 ((((safe_sub_func_int32_t_s_s(
                        l_1460,
                        (l_993.f2,
                         (((l_1461 <
                            (g_481 &=
                             (((l_1462 ^ (safe_add_func_uint16_t_u_u(
                                             (((p_111 & (((p_114 & g_307.f2),
                                                          ((l_908.f3 & 2UL) <=
                                                           0x17L)) < g_98.f0)),
                                               p_110) ||
                                              g_631),
                                             65535UL))) == p_111),
                              l_1465))) < l_1462) &&
                          p_111)))) < p_114) &
                   p_110) >= 6L)) == p_114) ||
               l_143.f1),
              g_946),
             l_930.f4)) ||
         p_111) &&
        p_112));
    return l_1114.f1;
  }
  g_98.f0 =
      (((g_204, l_143.f0) |
        (safe_add_func_uint32_t_u_u(
            (safe_div_func_int64_t_s_s(
                (0L ==
                 (safe_sub_func_uint8_t_u_u(
                     (safe_mod_func_int16_t_s_s(
                         0x904BL,
                         (safe_div_func_uint32_t_u_u(
                             g_307.f3,
                             (safe_add_func_int32_t_s_s(
                                 (((safe_lshift_func_int16_t_s_s(g_443, 9)) >
                                   1UL) |
                                  ((l_143.f2 > (p_113 || g_1338)), l_1480)),
                                 0x13010DA5L)))))),
                     g_18))),
                g_1338)),
            g_217))) > g_360);
  return g_307.f1;
}

static int8_t func_134(int16_t p_135, int16_t p_136, uint32_t p_137,
                       int32_t p_138, uint64_t p_139) {
  uint16_t l_178 = 0xADD0L;
  int32_t l_179 = (-5L);
  int32_t l_218 = 0x992C773CL;
  uint16_t l_219 = 65526UL;
  uint32_t l_271 = 0x200BE11DL;
  int32_t l_272 = 0x971268E8L;
  uint32_t l_310 = 18446744073709551615UL;
  int32_t l_311 = 1L;
  int32_t l_473 = 0xDD15559FL;
  struct S0 l_497 = {0x673F8C09L, 3, 1989, -0, -14771, 30, -6985, 9};
  struct S0 l_520 = {1L, 7, 421, -2, -7589, 31, -1086, 1};
  int64_t l_550 = 0x0C10346A922429E2LL;
  uint64_t l_551 = 1UL;
  const int16_t l_574 = (-1L);
  int64_t l_588 = 3L;
  uint8_t l_676 = 1UL;
  int32_t l_721 = (-1L);
  const int64_t l_722 = 0L;
  l_179 = (p_138 = (safe_mul_func_uint8_t_u_u(
               (safe_rshift_func_int16_t_s_s(
                   0L, (safe_add_func_int16_t_s_s(
                           (((p_138 <= 4294967295UL) <= (g_104, g_18)),
                            (safe_lshift_func_uint16_t_u_u(p_136, 0))),
                           0x9342L)))),
               (safe_mul_func_uint16_t_u_u(
                   0UL,
                   ((safe_mul_func_uint8_t_u_u(
                        ((((safe_add_func_int16_t_s_s((6UL || p_138), g_104)) ==
                           1UL) >= g_98.f1) != 0xA3C6L),
                        g_119)) |
                    l_178))))));
  g_98.f0 ^= (p_138 = p_135);
  p_138 &= p_139;
  if (((g_220 = (p_138 < (p_135 = (((((p_135 && (~((((+(safe_div_func_int64_t_s_s ((((+(safe_rshift_func_uint16_t_u_s (l_178, (safe_add_func_uint16_t_u_u ((safe_rshift_func_uint16_t_u_u (65535UL, 1)), (18446744073709551615UL & (safe_mod_func_uint64_t_u_u (((safe_mul_func_uint16_t_u_u ((safe_mod_func_int8_t_s_s (((safe_div_func_uint64_t_u_u ((safe_rshift_func_uint8_t_u_s ((safe_lshift_func_int8_t_s_s ((safe_mul_func_uint8_t_u_u (0xB4L, (g_207 = (safe_rshift_func_int16_t_s_u (p_137, (g_204++)))))), (safe_unary_minus_func_uint64_t_u (((safe_mul_func_int16_t_s_s ((safe_rshift_func_uint8_t_u_s ((g_217 = (0x9456L > (safe_div_func_int16_t_s_s (((safe_lshift_func_uint8_t_u_s (l_179, 0)) && g_98.f1), 0x2281L)))), l_178)), p_135)) & p_136))))), 3)), g_98.f2)) | g_18), 3UL)), 0xA56AL)) > l_179), l_178)))))))) & 0x95ECL) == 0xD8L), l_178))) < g_98.f0) && 0xCCL) || g_204))) > l_218) || 0UL), l_179) >= l_219)))) != g_103))
  {
    uint8_t l_231 = 0x0EL;
    struct S1 l_232 = {2542, 0x307BF7950AAE0F3FLL, 0x66D6690DL, 50};
    uint16_t l_474 = 65532UL;
    int32_t l_482 = (-1L);
    int32_t l_484 = 0x69D72CE7L;
    if (g_217) {
      return p_137;
    } else {
      g_217 &= (safe_mul_func_uint16_t_u_u(p_138, g_98.f2));
    }
    for (g_98.f1 = 0; (g_98.f1 <= (-13));
         g_98.f1 = safe_sub_func_uint64_t_u_u(g_98.f1, 2)) {
      uint16_t l_241 = 65532UL;
      const int32_t l_273 = 0x370E7266L;
      int64_t l_280 = 0x47C295546736D523LL;
      int32_t l_364 = 0x8CCECE4DL;
      uint32_t l_448 = 0x52649113L;
      int32_t l_485 = 0xCA3028F6L;
      p_138 = (l_232.f0 = (safe_div_func_int32_t_s_s(
                   ((((safe_mul_func_int16_t_s_s(
                          (g_204 ^
                           (safe_sub_func_int64_t_s_s(
                               (l_231 |= g_207),
                               (((+(+(g_98.f0 |= (l_232, 0x95C3721EL)))) ||
                                 (safe_sub_func_uint16_t_u_u(
                                     ((safe_sub_func_uint32_t_u_u(
                                          ((((p_135 = l_232.f1) ^
                                             ((((((((g_103, l_179) &
                                                    (safe_mod_func_int8_t_s_s(
                                                        l_232.f3, g_98.f2))) <=
                                                   0x9786083EL) ^
                                                  (-1L)) == 1L) ||
                                                g_220) ^
                                               255UL) ^
                                              g_217)) &
                                            0xE584L),
                                           0UL),
                                          g_119)) &&
                                      g_204),
                                     1UL))) >= 0x4E49BDC695E7397ELL)))),
                          0xAE28L)),
                      p_137) > p_137),
                    l_231),
                   l_232.f2)));
      p_138 &= p_139;

      if (((p_135 & p_135),
           (safe_div_func_int16_t_s_s(
               l_241, (safe_div_func_int16_t_s_s(0x2FAAL, 65535UL)))))) {
        uint8_t l_244 = 4UL;
        uint16_t l_274 = 0xFC30L;
        int64_t l_275 = (-4L);
        uint32_t l_282 = 0x14D0C5BBL;
        l_244++;
        p_138 =
            (l_232.f0 = (safe_div_func_int32_t_s_s(
                 ((((safe_mul_func_int16_t_s_s(
                        (g_204 ^
                         (safe_sub_func_int64_t_s_s(
                             (l_231 |= g_207),
                             (((+(+(g_98.f0 |= (l_232, 0x95C3721EL)))) ||
                               (safe_sub_func_uint16_t_u_u(
                                   ((safe_sub_func_uint32_t_u_u(
                                        ((((p_135 = l_232.f1) ^
                                           ((((((((g_103, l_179) &
                                                  (safe_mod_func_int8_t_s_s(
                                                      l_232.f3, g_98.f2))) <=
                                                 0x9786083EL) ^
                                                (-1L)) == 1L) ||
                                              g_220) ^
                                             255UL) ^
                                            g_217)) &
                                          0xE584L),
                                         0UL),
                                        g_119)) &&
                                    g_204),
                                   1UL))) >= 0x4E49BDC695E7397ELL)))),
                        0xAE28L)),
                    p_137) > p_137),
                  l_231),
                 l_232.f2)));

        g_276 =
            ((1UL >=
              (((p_136 ^
                 (g_217 = (safe_mul_func_uint8_t_u_u(
                      ((safe_div_func_uint32_t_u_u(
                           (safe_add_func_int32_t_s_s(
                               (safe_sub_func_int32_t_s_s(
                                   g_98.f3,
                                   ((g_98.f0 ^= (safe_lshift_func_int16_t_s_u(
                                         ((safe_sub_func_uint8_t_u_u(
                                              (safe_div_func_uint16_t_u_u(
                                                  l_241, 0xDA6AL)),
                                              g_217)),
                                          (safe_mod_func_int32_t_s_s(
                                              (((safe_div_func_int64_t_s_s(
                                                    (((0UL <=
                                                       (((~(((safe_sub_func_uint32_t_u_u(
                                                                 (safe_sub_func_uint32_t_u_u(
                                                                     (safe_sub_func_uint8_t_u_u(
                                                                         l_271,
                                                                         9UL)),
                                                                     4294967295UL)),
                                                                 g_93)) ==
                                                             p_137) > g_204)) <
                                                         l_272) != 4L)) <
                                                      g_204) ||
                                                     l_231),
                                                    18446744073709551615UL)),
                                                l_273) <= g_119),
                                              p_138))),
                                         l_244))),
                                    1L))),
                               l_274)),
                           0xFB81D463L)) |
                       (-1L)),
                      255UL)))) &
                g_98.f3) <= 0x3E4D8844572FAC39LL)) ||
             l_275);

        l_282--;

      } else {
        int32_t l_327 = 0x3888E424L;
        int32_t l_346 = 0xADCD0BB8L;
        uint16_t l_358 = 65528UL;
        uint32_t l_379 = 0x2718014CL;
        uint16_t l_444 = 65535UL;
        int32_t l_475 = 0x6F4876AAL;
        int32_t l_476 = 0L;
        int32_t l_480 = 0x60A501B5L;
        int32_t l_487 = 0x37C0663DL;
        l_311 &=
            (((safe_mul_func_uint8_t_u_u(
                  p_137,
                  (safe_sub_func_uint32_t_u_u(
                      ((((((((l_218 |= (safe_div_func_uint64_t_u_u(
                                  g_98.f0, (safe_div_func_uint64_t_u_u(
                                               (~p_136), g_98.f1))))) &&
                             (safe_rshift_func_uint16_t_u_s(
                                 (safe_sub_func_int64_t_s_s(
                                     ((safe_lshift_func_uint8_t_u_s(
                                          (((safe_lshift_func_uint16_t_u_s(
                                                ((((g_103 =
                                                        (g_207,
                                                         ((((safe_sub_func_uint64_t_u_u(
                                                                (p_139--),
                                                                (safe_add_func_uint8_t_u_u(
                                                                    (g_307,
                                                                     (+(l_280 ==
                                                                        (((255UL <
                                                                           ((safe_sub_func_uint32_t_u_u(
                                                                                0x7E3EB81DL,
                                                                                0x48762EDCL)),
                                                                            l_272)) >=
                                                                          0x86884AE3L) ==
                                                                         l_271)))),
                                                                    p_138)))) ^
                                                            4294967286UL) >
                                                           g_204) ^
                                                          l_218))) &
                                                   l_310) > 0xA833L) ==
                                                 4294967295UL),
                                                l_272)),
                                            0x58F199D2557C3E86LL) &&
                                           g_98.f3),
                                          g_279)) ^
                                      l_232.f2),
                                     p_137)),
                                 13))) |
                            g_307.f6) >= p_135) |
                          g_279) <= l_178) != g_93) ||
                       p_139),
                      g_279)))) <= l_271),
             p_136);

        {
          uint16_t l_241 = 65532UL;
          const int32_t l_273 = 0x370E7266L;
          int64_t l_280 = 0x47C295546736D523LL;
          int32_t l_364 = 0x8CCECE4DL;
          uint32_t l_448 = 0x52649113L;
          int32_t l_485 = 0xCA3028F6L;
          p_138 =
              (l_232.f0 = (safe_div_func_int32_t_s_s(
                   ((((safe_mul_func_int16_t_s_s(
                          (g_204 ^
                           (safe_sub_func_int64_t_s_s(
                               (l_231 |= g_207),
                               (((+(+(g_98.f0 |= (l_232, 0x95C3721EL)))) ||
                                 (safe_sub_func_uint16_t_u_u(
                                     ((safe_sub_func_uint32_t_u_u(
                                          ((((p_135 = l_232.f1) ^
                                             ((((((((g_103, l_179) &
                                                    (safe_mod_func_int8_t_s_s(
                                                        l_232.f3, g_98.f2))) <=
                                                   0x9786083EL) ^
                                                  (-1L)) == 1L) ||
                                                g_220) ^
                                               255UL) ^
                                              g_217)) &
                                            0xE584L),
                                           0UL),
                                          g_119)) &&
                                      g_204),
                                     1UL))) >= 0x4E49BDC695E7397ELL)))),
                          0xAE28L)),
                      p_137) > p_137),
                    l_231),
                   l_232.f2)));
          if (((p_135 & p_135),
               (safe_div_func_int16_t_s_s(
                   l_241, (safe_div_func_int16_t_s_s(0x2FAAL, 65535UL)))))) {
            uint8_t l_244 = 4UL;
            uint16_t l_274 = 0xFC30L;
            int64_t l_275 = (-4L);
            uint32_t l_282 = 0x14D0C5BBL;
            l_244++;
            g_276 =
                ((1UL >=
                  (((p_136 ^
                     (g_217 = (safe_mul_func_uint8_t_u_u(
                          ((safe_div_func_uint32_t_u_u(
                               (safe_add_func_int32_t_s_s(
                                   (safe_sub_func_int32_t_s_s(
                                       g_98.f3,
                                       ((g_98.f0 ^=
                                         (safe_lshift_func_int16_t_s_u(
                                             ((safe_sub_func_uint8_t_u_u(
                                                  (safe_div_func_uint16_t_u_u(
                                                      l_241, 0xDA6AL)),
                                                  g_217)),
                                              (safe_mod_func_int32_t_s_s(
                                                  (((safe_div_func_int64_t_s_s(
                                                        (((0UL <=
                                                           (((~(((safe_sub_func_uint32_t_u_u(
                                                                     (safe_sub_func_uint32_t_u_u(
                                                                         (safe_sub_func_uint8_t_u_u(
                                                                             l_271,
                                                                             9UL)),
                                                                         4294967295UL)),
                                                                     g_93)) ==
                                                                 p_137) >
                                                                g_204)) <
                                                             l_272) != 4L)) <
                                                          g_204) ||
                                                         l_231),
                                                        18446744073709551615UL)),
                                                    l_273) <= g_119),
                                                  p_138))),
                                             l_244))),
                                        1L))),
                                   l_274)),
                               0xFB81D463L)) |
                           (-1L)),
                          255UL)))) &
                    g_98.f3) <= 0x3E4D8844572FAC39LL)) ||
                 l_275);
            for (g_93 = 0; (g_93 != 33); g_93++) {
              g_279 ^= (g_217 > ((g_98.f0 ^ 0UL), g_276));
            }
            l_282--;
          } else {
            int32_t l_327 = 0x3888E424L;
            int32_t l_346 = 0xADCD0BB8L;
            uint16_t l_358 = 65528UL;
            uint32_t l_379 = 0x2718014CL;
            uint16_t l_444 = 65535UL;
            int32_t l_475 = 0x6F4876AAL;
            int32_t l_476 = 0L;
            int32_t l_480 = 0x60A501B5L;
            int32_t l_487 = 0x37C0663DL;
            l_311 &=
                (((safe_mul_func_uint8_t_u_u(
                      p_137,
                      (safe_sub_func_uint32_t_u_u(
                          ((((((((l_218 |= (safe_div_func_uint64_t_u_u(
                                      g_98.f0, (safe_div_func_uint64_t_u_u(
                                                   (~p_136), g_98.f1))))) &&
                                 (safe_rshift_func_uint16_t_u_s(
                                     (safe_sub_func_int64_t_s_s(
                                         ((safe_lshift_func_uint8_t_u_s(
                                              (((safe_lshift_func_uint16_t_u_s(
                                                    ((((g_103 =
                                                            (g_207,
                                                             ((((safe_sub_func_uint64_t_u_u(
                                                                    (p_139--),
                                                                    (safe_add_func_uint8_t_u_u(
                                                                        (g_307,
                                                                         (+(l_280 ==
                                                                            (((255UL <
                                                                               ((safe_sub_func_uint32_t_u_u(
                                                                                    0x7E3EB81DL,
                                                                                    0x48762EDCL)),
                                                                                l_272)) >=
                                                                              0x86884AE3L) ==
                                                                             l_271)))),
                                                                        p_138)))) ^
                                                                4294967286UL) >
                                                               g_204) ^
                                                              l_218))) &
                                                       l_310) > 0xA833L) ==
                                                     4294967295UL),
                                                    l_272)),
                                                0x58F199D2557C3E86LL) &&
                                               g_98.f3),
                                              g_279)) ^
                                          l_232.f2),
                                         p_137)),
                                     13))) |
                                g_307.f6) >= p_135) |
                              g_279) <= l_178) != g_93) ||
                           p_139),
                          g_279)))) <= l_271),
                 p_136);
 if ((p_138 = (((safe_mod_func_int16_t_s_s (((safe_add_func_int32_t_s_s ((safe_add_func_int8_t_s_s (g_98.f1, (((((safe_sub_func_int64_t_s_s (((safe_sub_func_uint8_t_u_u ((safe_mul_func_int8_t_s_s (((l_272 = ((safe_mod_func_uint64_t_u_u (((safe_unary_minus_func_int32_t_s (((l_327, ((l_271 ^ l_232.f0), (((safe_add_func_uint16_t_u_u ((((safe_rshift_func_int16_t_s_s ((p_135 ^= g_307.f5), 8)) < (+252UL)) || (safe_add_func_uint8_t_u_u (((safe_mul_func_uint16_t_u_u ((safe_add_func_int32_t_s_s ((g_217 = (g_307, 0x4FD68CECL)), (~(p_137 = (safe_add_func_uint64_t_u_u ((safe_mod_func_int64_t_s_s ((safe_div_func_int32_t_s_s ((l_346 = (safe_mul_func_int16_t_s_s (g_307.f4, l_327))), g_98.f1)), g_307.f7)), 0x055068102F24D469LL)))))), l_219)) <= 5L), l_232.f0))), l_179)) < p_138), g_307.f3))) > l_178))), l_272), g_98.f0)) > g_98.f1)) ^ p_136), 7UL)), 0x23L)) == p_138), 2L)) == 0xB93CA6D3L) == p_139) && g_220) & g_307.f2))), l_219)), 1L), 0x7025L)) == 0xBD90L) & 1UL)))
 {
   const struct S0 l_347 = {0xECA86F70L, -13, 191, 4, -4093, 28, 2207, 15};
   uint64_t l_442 = 0x986B910D2C7DCD8CLL;
   l_364 =
       ((l_347, (l_272 ^= g_276)) &&
        (safe_mod_func_int16_t_s_s(
            ((g_204 &&
              ((p_139 = (!(
                    p_135 <=
                    (((l_347.f4 !=
                       (((safe_sub_func_int16_t_s_s(
                             (safe_mul_func_uint16_t_u_u(
                                 (((((((safe_mod_func_uint32_t_u_u(
                                           ((g_360 =
                                                 ((safe_mod_func_int64_t_s_s(
                                                      g_103, l_358)),
                                                  (safe_unary_minus_func_int64_t_s(
                                                      l_232.f2)))) >
                                            (safe_mul_func_int8_t_s_s(
                                                (1UL <= g_307.f3), g_98.f2))),
                                           l_271)) < g_103) ^
                                      g_18) <= 0xCE79L) &
                                    g_363) ^
                                   g_220) |
                                  g_204),
                                 p_138)),
                             p_137)),
                         0xBCF94D503745B357LL) == 18446744073709551610UL)) <=
                      g_307.f5),
                     g_307.f1)))) != 8L)),
             p_136),
            g_307.f0)));
   l_218 =
       (2UL !=
        ((-1L) >
         ((safe_rshift_func_int8_t_s_s(g_98.f1, 6)) ||
          (((safe_mul_func_int8_t_s_s(
                ((-2L) !=
                 ((((safe_sub_func_int16_t_s_s(
                        (((safe_lshift_func_int16_t_s_s(
                              ((safe_add_func_int8_t_s_s(g_307.f1, (~l_218))) <=
                               ((g_307, 0x7EL) |
                                (safe_rshift_func_uint16_t_u_s(
                                    (l_346 |= (safe_sub_func_int32_t_s_s(
                                         g_98.f2, p_138))),
                                    l_379)))),
                              g_360)),
                          p_137) <= 4UL),
                        p_135)) <= l_327) <= p_138) >= g_93)),
                1UL)) ||
            g_279) != 0x4DD608B5L))));
   for (l_346 = 0; (l_346 <= 23); l_346 = safe_add_func_uint8_t_u_u(l_346, 1)) {
     int8_t l_388 = (-6L);
     p_138
       =
       (((g_103 = (safe_sub_func_uint64_t_u_u ((safe_add_func_uint8_t_u_u ((safe_div_func_uint16_t_u_u (l_388, (g_417 &= ((safe_add_func_uint64_t_u_u ((~(p_139 = p_139)), ((safe_lshift_func_int16_t_s_s ((-1L), (safe_rshift_func_int16_t_s_s ((((l_364 ^= (safe_lshift_func_int8_t_s_s (l_347.f0, (safe_add_func_int32_t_s_s (((safe_sub_func_int16_t_s_s ((safe_rshift_func_uint16_t_u_s (((l_272 ^= (!p_136)) < (safe_mod_func_uint8_t_u_u ((((p_137 = (safe_sub_func_int16_t_s_s ((safe_sub_func_uint32_t_u_u ((g_98, g_281), ((safe_mul_func_int8_t_s_s ((safe_mul_func_int8_t_s_s (g_360, ((((safe_add_func_uint64_t_u_u ((safe_add_func_int32_t_s_s (g_204, g_307.f4)), l_219)) ^ 0x66FAD5BCL) > g_93) && g_281))), 246UL)) || p_136))), p_135))) & 0UL) < p_138), (-1L)))), 13)), p_138)) <= 65535UL), g_220))))) >= l_232.f0) & p_138), g_207)))) > g_360))), l_271)))), g_98.f2)), 0xA33099370A3A9BFCLL))) & l_346) ^ 0xE7750FABAB807825LL);
   }
   for (g_217 = 0; (g_217 < 17); g_217 = safe_add_func_uint16_t_u_u(g_217, 3)) {
     uint32_t l_420 = 8UL;
     int32_t l_431 = 0x8514CCE5L;
     --l_420;
     g_98.f0 |=
         ((p_137 != g_307.f2) ^
          (g_276,
           (((safe_mod_func_int32_t_s_s(
                 ((safe_add_func_int8_t_s_s(
                      ((((!2UL) <
                         (safe_div_func_uint64_t_u_u(
                             (((((l_420 ||
                                  ((safe_lshift_func_uint8_t_u_u(
                                       ((~((((p_137 && (l_431 = g_281)) &
                                             (safe_mul_func_int16_t_s_s(
                                                 (safe_rshift_func_int16_t_s_s(
                                                     (((l_272,
                                                        ((safe_rshift_func_uint8_t_u_u(
                                                             (safe_div_func_uint8_t_u_u(
                                                                 ((safe_lshift_func_uint8_t_u_u(
                                                                      (l_179 =
                                                                           l_420),
                                                                      0)) &
                                                                  l_442),
                                                                 l_379)),
                                                             g_443)) >=
                                                         0x8682L)) ^
                                                       p_135) >= p_137),
                                                     9)),
                                                 65535UL))) |
                                            p_137) == (-1L))) &
                                        g_204),
                                       5)) &
                                   0x1DL)) ||
                                 1L) |
                                l_444) != g_103) &
                              p_137),
                             g_307.f3))) ||
                        g_98.f2) &&
                       g_217),
                      p_138)),
                  0xF2498764L),
                 g_307.f6)) < p_139) <= p_139)));
   }
 } else {
   uint32_t l_445 = 0x6B6975B6L;
   int32_t l_477 = 7L;
   int32_t l_478 = 0L;
   int32_t l_479 = 1L;
   if (g_98.f3) {
     l_445++;
     g_217 = l_448;
     g_98.f0 = (safe_lshift_func_uint16_t_u_s(
         (((safe_mul_func_int8_t_s_s(
               (safe_add_func_int64_t_s_s(
                   (!(((g_207 |= (safe_sub_func_int16_t_s_s(
                            (l_218 <
                             (((l_179 = (safe_rshift_func_int8_t_s_u(
                                    (safe_sub_func_uint32_t_u_u(
                                        ((((l_232,
                                            (safe_mul_func_int16_t_s_s(
                                                (safe_mul_func_uint16_t_u_u(
                                                    (l_364 ||
                                                     (safe_rshift_func_uint8_t_u_s(
                                                         (safe_lshift_func_int8_t_s_s(
                                                             g_103, p_136)),
                                                         4))),
                                                    ((safe_div_func_int32_t_s_s(
                                                         (g_307.f6 = l_273),
                                                         p_138)) <=
                                                     (0xB42B693B70FBF4B7LL ^
                                                      0x3398E590C066BD95LL)))),
                                                l_232.f2))) &
                                           0L),
                                          l_310) == l_358),
                                        1L)),
                                    7))) ||
                               l_473) <= p_135)),
                            0xB6F6L))) <= l_358) > g_98.f3)),
                   l_219)),
               p_138)) >= l_474) <= l_445),
         g_307.f7));
     g_307.f3 |= l_358;
   } else {
     if (p_138)
       break;
   }
   --g_488;
 }
          }
          g_307.f1 =
              ((safe_mul_func_int8_t_s_s(
                   (0xF073L ^ (p_135 &= 1L)),
                   (((safe_add_func_uint64_t_u_u(
                         (l_474 <
                          ((l_497,
                            (safe_mul_func_int8_t_s_s(
                                (safe_div_func_uint64_t_u_u(
                                    ((((l_218 = (safe_add_func_int32_t_s_s(
                                            (safe_div_func_int16_t_s_s(
                                                (safe_sub_func_uint8_t_u_u(
                                                    (safe_mod_func_uint8_t_u_u(
                                                        (p_137, l_241), p_136)),
                                                    (l_497.f7 >
                                                     (safe_add_func_int16_t_s_s(
                                                         (((((safe_lshift_func_int16_t_s_u(
                                                                 (safe_mul_func_int8_t_s_s(
                                                                     (p_139 ||
                                                                      0x6BD461673076FEC5LL),
                                                                     l_232.f1)),
                                                                 p_137)) !=
                                                             l_484) ||
                                                            g_486) >=
                                                           l_232.f3) ||
                                                          g_307.f2),
                                                         g_98.f3))))),
                                                0xCCADL)),
                                            p_136))) != l_273) |
                                      p_139) ^
                                     p_139),
                                    l_280)),
                                0x91L))) >= l_178)),
                         0L)) &&
                     0xA3DEA62C9CAB9FE2LL) ||
                    l_497.f1))) < 0x09E7L);
        }
      }

      p_138 = (l_232.f0 = (safe_div_func_int32_t_s_s(
                   ((((safe_mul_func_int16_t_s_s(
                          (g_204 ^
                           (safe_sub_func_int64_t_s_s(
                               (l_231 |= g_207),
                               (((+(+(g_98.f0 |= (l_232, 0x95C3721EL)))) ||
                                 (safe_sub_func_uint16_t_u_u(
                                     ((safe_sub_func_uint32_t_u_u(
                                          ((((p_135 = l_232.f1) ^
                                             ((((((((g_103, l_179) &
                                                    (safe_mod_func_int8_t_s_s(
                                                        l_232.f3, g_98.f2))) <=
                                                   0x9786083EL) ^
                                                  (-1L)) == 1L) ||
                                                g_220) ^
                                               255UL) ^
                                              g_217)) &
                                            0xE584L),
                                           0UL),
                                          g_119)) &&
                                      g_204),
                                     1UL))) >= 0x4E49BDC695E7397ELL)))),
                          0xAE28L)),
                      p_137) > p_137),
                    l_231),
                   l_232.f2)));
    }
  } else {
    uint32_t l_549 = 0x5469C467L;
    int32_t l_552 = (-3L);
    uint64_t l_553 = 0x6ADAB0593DF1BCE8LL;
    uint32_t l_575 = 0xEAA06FA5L;
    int32_t l_595 = 1L;
    uint64_t l_708 = 0xBA745A544FD802E3LL;
    l_218
      =
      (safe_mod_func_uint32_t_u_u
       ((safe_div_func_uint64_t_u_u ((l_520, (((((g_483 &= (safe_div_func_uint8_t_u_u (p_135, (safe_rshift_func_int8_t_s_s ((safe_lshift_func_uint8_t_u_s ((safe_sub_func_uint8_t_u_u ((!(safe_mod_func_int32_t_s_s ((safe_rshift_func_int16_t_s_s ((((0xC6L != (safe_mod_func_int64_t_s_s (p_135, (((((l_272 = l_218) <= (((((safe_sub_func_uint32_t_u_u ((safe_rshift_func_uint16_t_u_s (((((safe_mul_func_uint8_t_u_u ((l_497.f6 > (safe_rshift_func_uint16_t_u_s ((safe_lshift_func_uint16_t_u_u ((((l_549 = ((((l_497.f3 = p_137) >= (safe_mod_func_uint32_t_u_u (((p_139 = ((!(safe_add_func_int8_t_s_s (g_204, ((g_207 <= p_137) & l_520.f1)))) < 18446744073709551615UL)) < p_138), 0xACBBFDDBL))) || 0xD6F986E3EFCD1EFCLL) || p_138)) >= p_137) ^ g_488), 9)), 13))), l_520.f1)) && p_139), p_139) || 0L), 6)), l_550)) != l_551) & 0x6FL) | l_552) >= p_138)) & 65531UL), 6L) & 0x64F53B5BA0EBD352LL)))) && g_18) <= p_137), l_553)), l_552))), p_138)), 7)), l_497.f5))))), p_139) & l_497.f1) == p_138) < 1L)), g_307.f7)), g_443));

    l_179 =
        (p_138 = (safe_mul_func_uint8_t_u_u(
             (safe_rshift_func_int16_t_s_s(
                 0L, (safe_add_func_int16_t_s_s(
                         (((p_138 <= 4294967295UL) <= (g_104, g_18)),
                          (safe_lshift_func_uint16_t_u_u(p_136, 0))),
                         0x9342L)))),
             (safe_mul_func_uint16_t_u_u(
                 0UL,
                 ((safe_mul_func_uint8_t_u_u(
                      ((((safe_add_func_int16_t_s_s((6UL || p_138), g_104)) ==
                         1UL) >= g_98.f1) != 0xA3C6L),
                      g_119)) |
                  l_178))))));

    p_138 ^= g_307.f3;
    p_138 =
        (0x7DL ||
         (safe_rshift_func_int8_t_s_u(
             ((((safe_lshift_func_int16_t_s_u(
                    g_207,
                    ((((((l_552 =
                              (l_595 =
                                   ((g_488 ^= ((p_136 != l_708), p_139)) ||
                                    (safe_lshift_func_int16_t_s_u(
                                        (safe_mul_func_uint16_t_u_u(
                                            (safe_div_func_int64_t_s_s(
                                                ((-1L) |
                                                 ((((safe_mod_func_uint32_t_u_u(
                                                        ((((l_179 = (+0xA7L)) ^
                                                           (++g_417)) &
                                                          (p_139 <=
                                                           4294967286UL)) ^
                                                         g_488),
                                                        l_721)),
                                                    g_363) >= 65528UL),
                                                  l_551)),
                                                l_553)),
                                            p_138)),
                                        12))))) >= g_98.f2),
                        p_136) != l_708) < p_138) |
                     g_486))) ||
                0x476FL) ^
               l_722) != g_279),
             4)));
  }
  return p_137;
}

static uint16_t func_146(uint16_t p_147, int32_t p_148) {
  uint16_t l_163 = 65535UL;
  g_98.f0 =
      ((g_119,
        (g_103 <
         (((safe_mod_func_int32_t_s_s(
               ((safe_lshift_func_uint8_t_u_s(p_147, 3)) <=
                (((g_119 ||
                   (safe_div_func_uint16_t_u_u(
                       g_98.f3,
                       (safe_rshift_func_int16_t_s_u(
                           (((safe_mul_func_uint16_t_u_u(g_98.f0, g_18)) >
                             (safe_add_func_uint16_t_u_u(
                                 ((safe_mod_func_uint32_t_u_u(l_163, l_163)) >=
                                  0xE0CEE113L),
                                 4UL))) != (-1L)),
                           14))))) ^
                  g_98.f3) == p_147)),
               g_98.f1)) < p_147) <= l_163))) > 0L);
  return g_98.f0;
}

int main(int argc, char *argv[]) {
  int print_hash_value = 0;
  if (argc == 2 && strcmp(argv[1], "1") == 0)
    print_hash_value = 1;
  crc32_gentab();
  func_1();
  transparent_crc(g_18, "g_18", print_hash_value);
  transparent_crc(g_93, "g_93", print_hash_value);
  transparent_crc(g_98.f0, "g_98.f0", print_hash_value);
  transparent_crc(g_98.f1, "g_98.f1", print_hash_value);
  transparent_crc(g_98.f2, "g_98.f2", print_hash_value);
  transparent_crc(g_98.f3, "g_98.f3", print_hash_value);
  transparent_crc(g_103, "g_103", print_hash_value);
  transparent_crc(g_104, "g_104", print_hash_value);
  transparent_crc(g_119, "g_119", print_hash_value);
  transparent_crc(g_204, "g_204", print_hash_value);
  transparent_crc(g_207, "g_207", print_hash_value);
  transparent_crc(g_217, "g_217", print_hash_value);
  transparent_crc(g_220, "g_220", print_hash_value);
  transparent_crc(g_276, "g_276", print_hash_value);
  transparent_crc(g_279, "g_279", print_hash_value);
  transparent_crc(g_281, "g_281", print_hash_value);
  transparent_crc(g_307.f0, "g_307.f0", print_hash_value);
  transparent_crc(g_307.f1, "g_307.f1", print_hash_value);
  transparent_crc(g_307.f2, "g_307.f2", print_hash_value);
  transparent_crc(g_307.f3, "g_307.f3", print_hash_value);
  transparent_crc(g_307.f4, "g_307.f4", print_hash_value);
  transparent_crc(g_307.f5, "g_307.f5", print_hash_value);
  transparent_crc(g_307.f6, "g_307.f6", print_hash_value);
  transparent_crc(g_307.f7, "g_307.f7", print_hash_value);
  transparent_crc(g_360, "g_360", print_hash_value);
  transparent_crc(g_363, "g_363", print_hash_value);
  transparent_crc(g_417, "g_417", print_hash_value);
  transparent_crc(g_443, "g_443", print_hash_value);
  transparent_crc(g_481, "g_481", print_hash_value);
  transparent_crc(g_483, "g_483", print_hash_value);
  transparent_crc(g_486, "g_486", print_hash_value);
  transparent_crc(g_488, "g_488", print_hash_value);
  transparent_crc(g_628, "g_628", print_hash_value);
  transparent_crc(g_631, "g_631", print_hash_value);
  transparent_crc(g_701, "g_701", print_hash_value);
  transparent_crc(g_758, "g_758", print_hash_value);
  transparent_crc(g_946, "g_946", print_hash_value);
  transparent_crc(g_1054, "g_1054", print_hash_value);
  transparent_crc(g_1066, "g_1066", print_hash_value);
  transparent_crc(g_1338, "g_1338", print_hash_value);
  transparent_crc(g_1814, "g_1814", print_hash_value);
  transparent_crc(g_1846, "g_1846", print_hash_value);
  transparent_crc(g_1860, "g_1860", print_hash_value);
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}

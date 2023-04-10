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

  return (si == 
               (-128)
                       ) ? ((si)) : -si;
}
static int8_t(safe_add_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return (((si1 > 0) && (si2 > 0) && (si1 > (
                                            (127) 
                                                     - si2))) ||
          ((si1 < 0) && (si2 < 0) && (si1 < (
                                            (-128) 
                                                     - si2))))
             ? ((si1))
             : (si1 + si2);
}
static int8_t(safe_sub_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~
                                                  (127)
                                                          ))) - si2) ^ si2)) <
          0)
             ? ((si1))
             : (si1 - si2);
}
static int8_t(safe_mul_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return (((si1 > 0) && (si2 > 0) && (si1 > (
                                            (127) 
                                                     / si2))) ||
          ((si1 > 0) && (si2 <= 0) && (si2 < (
                                             (-128) 
                                                      / si1))) ||
          ((si1 <= 0) && (si2 > 0) && (si1 < (
                                             (-128) 
                                                      / si2))) ||
          ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (
                                                            (127) 
                                                                     / si1))))
             ? ((si1))
             : si1 * si2;
}
static int8_t(safe_mod_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return ((si2 == 0) || ((si1 == 
                                (-128)
                                        ) && (si2 == (-1)))) ? ((si1))
                                                              : (si1 % si2);
}
static int8_t(safe_div_func_int8_t_s_s)(int8_t si1, int8_t si2) {

  return ((si2 == 0) || ((si1 == 
                                (-128)
                                        ) && (si2 == (-1)))) ? ((si1))
                                                              : (si1 / si2);
}
static int8_t(safe_lshift_func_int8_t_s_s)(int8_t left, int right) {

  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
          (left > (
                  (127) 
                           >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static int8_t(safe_lshift_func_int8_t_s_u)(int8_t left, unsigned int right) {

  return ((left < 0) || (((unsigned int)right) >= 32) ||
          (left > (
                  (127) 
                           >> ((unsigned int)right))))
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
static int16_t(safe_unary_minus_func_int16_t_s)(int16_t si) {

  return (si == 
               (-32767-1)
                        ) ? ((si)) : -si;
}
static int16_t(safe_add_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return (((si1 > 0) && (si2 > 0) && (si1 > (
                                            (32767) 
                                                      - si2))) ||
          ((si1 < 0) && (si2 < 0) && (si1 < (
                                            (-32767-1) 
                                                      - si2))))
             ? ((si1))
             : (si1 + si2);
}
static int16_t(safe_sub_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~
                                                  (32767)
                                                           ))) - si2) ^ si2)) <
          0)
             ? ((si1))
             : (si1 - si2);
}
static int16_t(safe_mul_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return (((si1 > 0) && (si2 > 0) && (si1 > (
                                            (32767) 
                                                      / si2))) ||
          ((si1 > 0) && (si2 <= 0) && (si2 < (
                                             (-32767-1) 
                                                       / si1))) ||
          ((si1 <= 0) && (si2 > 0) && (si1 < (
                                             (-32767-1) 
                                                       / si2))) ||
          ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (
                                                            (32767) 
                                                                      / si1))))
             ? ((si1))
             : si1 * si2;
}
static int16_t(safe_mod_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return ((si2 == 0) || ((si1 == 
                                (-32767-1)
                                         ) && (si2 == (-1)))) ? ((si1))
                                                               : (si1 % si2);
}
static int16_t(safe_div_func_int16_t_s_s)(int16_t si1, int16_t si2) {

  return ((si2 == 0) || ((si1 == 
                                (-32767-1)
                                         ) && (si2 == (-1)))) ? ((si1))
                                                               : (si1 / si2);
}
static int16_t(safe_lshift_func_int16_t_s_s)(int16_t left, int right) {

  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
          (left > (
                  (32767) 
                            >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static int16_t(safe_lshift_func_int16_t_s_u)(int16_t left, unsigned int right) {

  return ((left < 0) || (((unsigned int)right) >= 32) ||
          (left > (
                  (32767) 
                            >> ((unsigned int)right))))
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

  return (si == 
               (-2147483647-1)
                        ) ? ((si)) : -si;
}
static int32_t(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return (((si1 > 0) && (si2 > 0) && (si1 > (
                                            (2147483647) 
                                                      - si2))) ||
          ((si1 < 0) && (si2 < 0) && (si1 < (
                                            (-2147483647-1) 
                                                      - si2))))
             ? ((si1))
             : (si1 + si2);
}
static int32_t(safe_sub_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~
                                                  (2147483647)
                                                           ))) - si2) ^ si2)) <
          0)
             ? ((si1))
             : (si1 - si2);
}
static int32_t(safe_mul_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return (((si1 > 0) && (si2 > 0) && (si1 > (
                                            (2147483647) 
                                                      / si2))) ||
          ((si1 > 0) && (si2 <= 0) && (si2 < (
                                             (-2147483647-1) 
                                                       / si1))) ||
          ((si1 <= 0) && (si2 > 0) && (si1 < (
                                             (-2147483647-1) 
                                                       / si2))) ||
          ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (
                                                            (2147483647) 
                                                                      / si1))))
             ? ((si1))
             : si1 * si2;
}
static int32_t(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return ((si2 == 0) || ((si1 == 
                                (-2147483647-1)
                                         ) && (si2 == (-1)))) ? ((si1))
                                                               : (si1 % si2);
}
static int32_t(safe_div_func_int32_t_s_s)(int32_t si1, int32_t si2) {

  return ((si2 == 0) || ((si1 == 
                                (-2147483647-1)
                                         ) && (si2 == (-1)))) ? ((si1))
                                                               : (si1 / si2);
}
static int32_t(safe_lshift_func_int32_t_s_s)(int32_t left, int right) {

  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
          (left > (
                  (2147483647) 
                            >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static int32_t(safe_lshift_func_int32_t_s_u)(int32_t left, unsigned int right) {

  return ((left < 0) || (((unsigned int)right) >= 32) ||
          (left > (
                  (2147483647) 
                            >> ((unsigned int)right))))
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
static int64_t(safe_unary_minus_func_int64_t_s)(int64_t si) {

  return (si == 
               (-9223372036854775807LL -1)
                        ) ? ((si)) : -si;
}
static int64_t(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return (((si1 > 0) && (si2 > 0) && (si1 > (
                                            (9223372036854775807LL) 
                                                      - si2))) ||
          ((si1 < 0) && (si2 < 0) && (si1 < (
                                            (-9223372036854775807LL -1) 
                                                      - si2))))
             ? ((si1))
             : (si1 + si2);
}
static int64_t(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return (((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~
                                                  (9223372036854775807LL)
                                                           ))) - si2) ^ si2)) <
          0)
             ? ((si1))
             : (si1 - si2);
}
static int64_t(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return (((si1 > 0) && (si2 > 0) && (si1 > (
                                            (9223372036854775807LL) 
                                                      / si2))) ||
          ((si1 > 0) && (si2 <= 0) && (si2 < (
                                             (-9223372036854775807LL -1) 
                                                       / si1))) ||
          ((si1 <= 0) && (si2 > 0) && (si1 < (
                                             (-9223372036854775807LL -1) 
                                                       / si2))) ||
          ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (
                                                            (9223372036854775807LL) 
                                                                      / si1))))
             ? ((si1))
             : si1 * si2;
}
static int64_t(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return ((si2 == 0) || ((si1 == 
                                (-9223372036854775807LL -1)
                                         ) && (si2 == (-1)))) ? ((si1))
                                                               : (si1 % si2);
}
static int64_t(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2) {

  return ((si2 == 0) || ((si1 == 
                                (-9223372036854775807LL -1)
                                         ) && (si2 == (-1)))) ? ((si1))
                                                               : (si1 / si2);
}
static int64_t(safe_lshift_func_int64_t_s_s)(int64_t left, int right) {

  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
          (left > (
                  (9223372036854775807LL) 
                            >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static int64_t(safe_lshift_func_int64_t_s_u)(int64_t left, unsigned int right) {

  return ((left < 0) || (((unsigned int)right) >= 32) ||
          (left > (
                  (9223372036854775807LL) 
                            >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static int64_t(safe_rshift_func_int64_t_s_s)(int64_t left, int right) {

  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
             ? ((left))
             : (left >> ((int)right));
}
static int64_t(safe_rshift_func_int64_t_s_u)(int64_t left, unsigned int right) {

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
          (left > (
                  (255) 
                            >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static uint8_t(safe_lshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {

  return ((((unsigned int)right) >= 32) ||
          (left > (
                  (255) 
                            >> ((unsigned int)right))))
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
          (left > (
                  (65535) 
                             >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static uint16_t(safe_lshift_func_uint16_t_u_u)(uint16_t left,
                                               unsigned int right) {

  return ((((unsigned int)right) >= 32) ||
          (left > (
                  (65535) 
                             >> ((unsigned int)right))))
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
          (left > (
                  (4294967295U) 
                             >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static uint32_t(safe_lshift_func_uint32_t_u_u)(uint32_t left,
                                               unsigned int right) {

  return ((((unsigned int)right) >= 32) ||
          (left > (
                  (4294967295U) 
                             >> ((unsigned int)right))))
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

  return (ui2 == 0) ? ((ui1)) : (ui1 % ui2);
}
static uint64_t(safe_div_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {

  return (ui2 == 0) ? ((ui1)) : (ui1 / ui2);
}
static uint64_t(safe_lshift_func_uint64_t_u_s)(uint64_t left, int right) {

  return ((((int)right) < 0) || (((int)right) >= 32) ||
          (left > (
                  (18446744073709551615ULL) 
                             >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static uint64_t(safe_lshift_func_uint64_t_u_u)(uint64_t left,
                                               unsigned int right) {

  return ((((unsigned int)right) >= 32) ||
          (left > (
                  (18446744073709551615ULL) 
                             >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static uint64_t(safe_rshift_func_uint64_t_u_s)(uint64_t left, int right) {

  return ((((int)right) < 0) || (((int)right) >= 32)) ? ((left))
                                                      : (left >> ((int)right));
}
static uint64_t(safe_rshift_func_uint64_t_u_u)(uint64_t left,
                                               unsigned int right) {

  return (((unsigned int)right) >= 32) ? ((left))
                                       : (left >> ((unsigned int)right));
}
static float(safe_add_func_float_f_f)(float sf1, float sf2) {

  return (fabsf((0.5f * sf1) + (0.5f * sf2)) > (0.5f * 3.40282346638528859812e+38F)) ? (sf1)
                                                                 : (sf1 + sf2);
}
static float(safe_sub_func_float_f_f)(float sf1, float sf2) {

  return (fabsf((0.5f * sf1) - (0.5f * sf2)) > (0.5f * 3.40282346638528859812e+38F)) ? (sf1)
                                                                 : (sf1 - sf2);
}
static float(safe_mul_func_float_f_f)(float sf1, float sf2) {

  return (fabsf((0x1.0p-100f * sf1) * (0x1.0p-28f * sf2)) >
          (0x1.0p-100f * (0x1.0p-28f * 3.40282346638528859812e+38F)))
             ? (sf1)
             : (sf1 * sf2);
}
static float(safe_div_func_float_f_f)(float sf1, float sf2) {

  return ((fabsf(sf2) < 1.0f) &&
          (((sf2 == 0.0f) || (fabsf((0x1.0p-49f * sf1) / (0x1.0p100f * sf2))) >
                                 (0x1.0p-100f * (0x1.0p-49f * 3.40282346638528859812e+38F)))))
             ? (sf1)
             : (sf1 / sf2);
}
static double(safe_add_func_double_f_f)(double sf1, double sf2) {

  return (fabs((0.5 * sf1) + (0.5 * sf2)) > (0.5 * ((double)1.79769313486231570815e+308L))) ? (sf1)
                                                             : (sf1 + sf2);
}
static double(safe_sub_func_double_f_f)(double sf1, double sf2) {

  return (fabs((0.5 * sf1) - (0.5 * sf2)) > (0.5 * ((double)1.79769313486231570815e+308L))) ? (sf1)
                                                             : (sf1 - sf2);
}
static double(safe_mul_func_double_f_f)(double sf1, double sf2) {

  return (fabs((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) >
          (0x1.0p-100 * (0x1.0p-924 * ((double)1.79769313486231570815e+308L))))
             ? (sf1)
             : (sf1 * sf2);
}
static double(safe_div_func_double_f_f)(double sf1, double sf2) {

  return ((fabs(sf2) < 1.0) &&
          (((sf2 == 0.0) || (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) >
                                (0x1.0p-100 * (0x1.0p-974 * ((double)1.79769313486231570815e+308L))))))
             ? (sf1)
             : (sf1 / sf2);
}
static int32_t(safe_convert_func_float_to_int32_t)(float sf1) {

  return ((sf1 <= 
                 (-2147483647-1)
                          ) || (sf1 >= 
                                       (2147483647)
                                                )) ? (
                                                      (2147483647)
                                                               )
                                                    : ((int32_t)(sf1));
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
static int32_t g_2 = 0x24A8C6A5L;
static uint8_t g_5 = 0x28L;
static int8_t g_8 = 0x82L;
static int32_t g_53 = (-4L);
static int32_t g_55 = (-9L);
static int32_t g_59 = 0xDDD0C6A3L;
static int32_t g_64 = 0x1F04FECCL;
static int16_t g_65 = 0x2B72L;
static int32_t g_66 = 0xD027BAEDL;
static uint32_t g_67 = 4294967295UL;
static uint32_t g_130 = 4294967295UL;
static int32_t g_137[9][10] = {{3L, (-2L), 5L, (-1L), 0x4424CFB0L, 0xC55B1586L,
                                8L, 0x07F38625L, 0x660488F6L, 9L},
                               {3L, (-2L), 5L, (-1L), 0x4424CFB0L, 0xC55B1586L,
                                8L, 0x07F38625L, 0x660488F6L, 9L},
                               {3L, (-2L), 5L, (-1L), 0x4424CFB0L, 0xC55B1586L,
                                8L, 0x07F38625L, 0x660488F6L, 9L},
                               {3L, (-2L), 5L, (-1L), 0x4424CFB0L, 0xC55B1586L,
                                8L, 0x07F38625L, 0x660488F6L, 9L},
                               {3L, (-2L), 5L, (-1L), 0x4424CFB0L, 0xC55B1586L,
                                8L, 0x07F38625L, 0x660488F6L, 9L},
                               {3L, (-2L), 5L, (-1L), 0x4424CFB0L, 0xC55B1586L,
                                8L, 0x07F38625L, 0x660488F6L, 9L},
                               {3L, (-2L), 5L, (-1L), 0x4424CFB0L, 0xC55B1586L,
                                8L, 0x07F38625L, 0x660488F6L, 9L},
                               {3L, (-2L), 5L, (-1L), 0x4424CFB0L, 0xC55B1586L,
                                8L, 0x07F38625L, 0x660488F6L, 9L},
                               {3L, (-2L), 5L, (-1L), 0x4424CFB0L, 0xC55B1586L,
                                8L, 0x07F38625L, 0x660488F6L, 9L}};
static int32_t g_230 = 1L;
static uint32_t g_867 = 1UL;
static int8_t g_1103 = 1L;
static uint8_t g_1552 = 0xC9L;
static int32_t g_1766[7][10][3] = {{{0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L}},
                                   {{0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L}},
                                   {{0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L}},
                                   {{0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L}},
                                   {{0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L}},
                                   {{0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L}},
                                   {{0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L},
                                    {0L, 0x65D3430EL, 0xD0412C96L}}};
static uint16_t func_1(void);
static uint8_t func_14(int16_t p_15, uint32_t p_16, int8_t p_17);
static uint8_t func_20(uint32_t p_21, uint8_t p_22);
static uint8_t func_23(int32_t p_24, uint32_t p_25);
static uint32_t func_34(uint32_t p_35, int8_t p_36);
static uint32_t func_37(int32_t p_38);
static int32_t func_41(int32_t p_42, uint32_t p_43, int32_t p_44, int32_t p_45);
static uint16_t func_73(int8_t p_74, uint16_t p_75, uint16_t p_76);
static uint32_t func_80(int32_t p_81, uint32_t p_82, uint8_t p_83,
                        uint16_t p_84);
static int8_t func_87(int16_t p_88, uint32_t p_89, int32_t p_90, int32_t p_91);
static uint16_t func_1(void) {
  uint32_t l_9 = 1UL;
  int32_t l_1098 = 0x2E1AA177L;
  int32_t l_1101 = 0xB36D0991L;
  int32_t l_1104[4] = {0L, 0xA578909DL, 0L, 0xA578909DL};
  uint32_t l_1122 = 18446744073709551615UL;
  uint16_t l_1193[6][10] = {{0x5D6BL, 1UL, 0xF7E7L, 1UL, 0xF7E7L, 1UL, 0x5D6BL,
                             0xD908L, 2UL, 65535UL},
                            {0x5D6BL, 1UL, 0xF7E7L, 1UL, 0xF7E7L, 1UL, 0x5D6BL,
                             0xD908L, 2UL, 65535UL},
                            {0x5D6BL, 1UL, 0xF7E7L, 1UL, 0xF7E7L, 1UL, 0x5D6BL,
                             0xD908L, 2UL, 65535UL},
                            {0x5D6BL, 1UL, 0xF7E7L, 1UL, 0xF7E7L, 1UL, 0x5D6BL,
                             0xD908L, 2UL, 65535UL},
                            {0x5D6BL, 1UL, 0xF7E7L, 1UL, 0xF7E7L, 1UL, 0x5D6BL,
                             0xD908L, 2UL, 65535UL},
                            {0x5D6BL, 1UL, 0xF7E7L, 1UL, 0xF7E7L, 1UL, 0x5D6BL,
                             0xD908L, 2UL, 65535UL}};
  uint32_t l_1235 = 0xEDE32C6EL;
  uint32_t l_1258[1][10][1] = {
      {{0UL}, {0UL}, {0UL}, {0UL}, {0UL}, {0UL}, {0UL}, {0UL}, {0UL}, {0UL}}};
  int8_t l_1393[7][8] = {{(-1L), 4L, (-1L), 4L, (-1L), 4L, (-1L), 4L},
                         {(-1L), 4L, (-1L), 4L, (-1L), 4L, (-1L), 4L},
                         {(-1L), 4L, (-1L), 4L, (-1L), 4L, (-1L), 4L},
                         {(-1L), 4L, (-1L), 4L, (-1L), 4L, (-1L), 4L},
                         {(-1L), 4L, (-1L), 4L, (-1L), 4L, (-1L), 4L},
                         {(-1L), 4L, (-1L), 4L, (-1L), 4L, (-1L), 4L},
                         {(-1L), 4L, (-1L), 4L, (-1L), 4L, (-1L), 4L}};
  uint16_t l_1420[8] = {0x27F1L, 0x27F1L, 0x7A6BL, 0x27F1L,
                        0x27F1L, 0x7A6BL, 0x27F1L, 0x27F1L};
  int16_t l_1505 = 0x0892L;
  int8_t l_1508 = 0x75L;
  int16_t l_1531[10][6] = {
      {0x4535L, 0xF4F1L, (-9L), 0xF4F1L, 0x4535L, 0xF4F1L},
      {0x4535L, 0xF4F1L, (-9L), 0xF4F1L, 0x4535L, 0xF4F1L},
      {0x4535L, 0xF4F1L, (-9L), 0xF4F1L, 0x4535L, 0xF4F1L},
      {0x4535L, 0xF4F1L, (-9L), 0xF4F1L, 0x4535L, 0xF4F1L},
      {0x4535L, 0xF4F1L, (-9L), 0xF4F1L, 0x4535L, 0xF4F1L},
      {0x4535L, 0xF4F1L, (-9L), 0xF4F1L, 0x4535L, 0xF4F1L},
      {0x4535L, 0xF4F1L, (-9L), 0xF4F1L, 0x4535L, 0xF4F1L},
      {0x4535L, 0xF4F1L, (-9L), 0xF4F1L, 0x4535L, 0xF4F1L},
      {0x4535L, 0xF4F1L, (-9L), 0xF4F1L, 0x4535L, 0xF4F1L},
      {0x4535L, 0xF4F1L, (-9L), 0xF4F1L, 0x4535L, 0xF4F1L}};
  int16_t l_1549 = 0xC3B3L;
  int32_t l_1558 = 0x000F0E13L;
  uint32_t l_1573 = 8UL;
  int16_t l_1599 = 0x9D74L;
  uint32_t l_1625 = 1UL;
  int32_t l_1674[7][5][7] = {{{(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L}},
                             {{(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L}},
                             {{(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L}},
                             {{(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L}},
                             {{(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L}},
                             {{(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L}},
                             {{(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L},
                              {(-3L), 1L, 0L, 0xB0979578L, (-2L), 0L, 0L}}};
  uint16_t l_1702[3][7] = {
      {0xAF16L, 1UL, 2UL, 65535UL, 0x0569L, 0x1263L, 0x0569L},
      {0xAF16L, 1UL, 2UL, 65535UL, 0x0569L, 0x1263L, 0x0569L},
      {0xAF16L, 1UL, 2UL, 65535UL, 0x0569L, 0x1263L, 0x0569L}};
  uint32_t l_1707 = 18446744073709551615UL;
  uint16_t l_1781[10] = {0x7AEEL, 0x7AEEL, 0x7FA4L, 0x7AEEL, 0x7AEEL,
                         0x7FA4L, 0x7AEEL, 0x7AEEL, 0x7FA4L, 0x7AEEL};
  int32_t l_1876 = 0xB6EA205EL;
  int i, j, k;
  for (g_2 = 0; (g_2 == 3); g_2++) {
    --g_5;
  }
  if ((((safe_rshift_func_uint8_t_u_u(
            func_14(
                (safe_mul_func_uint16_t_u_u(
                    (func_20(l_9, func_23(l_9, g_2)) !=
                     (((safe_mod_func_uint32_t_u_u(
                           0x714130E5L,
                           (safe_rshift_func_int16_t_s_s(
                               (safe_rshift_func_uint16_t_u_s(
                                   (safe_lshift_func_uint16_t_u_u(g_8, g_130)),
                                   g_8)),
                               2)))) < g_130) &&
                      l_9)),
                    l_9)),
                g_66, l_9),
            1)) &
        l_9) == g_867)) {
    uint16_t l_1046 = 0UL;
    int16_t l_1057[3];
    int32_t l_1095[5] = {0x92DDF8DAL, 1L, 0x92DDF8DAL, 1L, 0x92DDF8DAL};
    int8_t l_1110 = 0x05L;
    int8_t l_1117 = 5L;
    int8_t l_1195 = 0x12L;
    uint32_t l_1200 = 0x10EAD486L;
    int16_t l_1361 = 0x5071L;
    int32_t l_1456 = 9L;
    uint16_t l_1509 = 0xD357L;
    uint8_t l_1598 = 8UL;
    int32_t l_1780[10][6] = {
        {2L, 0L, 0x03B97211L, 0L, 2L, 0L}, {2L, 0L, 0x03B97211L, 0L, 2L, 0L},
        {2L, 0L, 0x03B97211L, 0L, 2L, 0L}, {2L, 0L, 0x03B97211L, 0L, 2L, 0L},
        {2L, 0L, 0x03B97211L, 0L, 2L, 0L}, {2L, 0L, 0x03B97211L, 0L, 2L, 0L},
        {2L, 0L, 0x03B97211L, 0L, 2L, 0L}, {2L, 0L, 0x03B97211L, 0L, 2L, 0L},
        {2L, 0L, 0x03B97211L, 0L, 2L, 0L}, {2L, 0L, 0x03B97211L, 0L, 2L, 0L}};
    int32_t l_1789 = (-6L);
    int16_t l_1842 = 0x91FEL;
    int i, j;
    for (i = 0; i < 3; i++)
      l_1057[i] = 0L;
    g_64 ^= g_137[8][0];
    if ((safe_mod_func_int8_t_s_s(
            (0xD43DL >=
             ((safe_mul_func_int8_t_s_s(
                  ((!g_130) &&
                   (safe_mul_func_int8_t_s_s(
                       0x0EL,
                       ((((safe_add_func_uint32_t_u_u(
                              (safe_sub_func_int8_t_s_s(
                                  g_55,
                                  (safe_mod_func_uint32_t_u_u(
                                      (l_9 &&
                                       (safe_sub_func_uint8_t_u_u(
                                           ((l_1046 ^
                                             (safe_rshift_func_uint16_t_u_s(
                                                 (safe_mul_func_int16_t_s_s(
                                                     l_1046,
                                                     (safe_mul_func_uint16_t_u_u(
                                                         0xAED6L,
                                                         (safe_rshift_func_int8_t_s_u(
                                                             (safe_mod_func_int32_t_s_s(
                                                                 ((l_9 ==
                                                                   l_1057[0]) ||
                                                                  l_9),
                                                                 g_230)),
                                                             l_9)))))),
                                                 0))) <= g_230),
                                           g_867))),
                                      g_59)))),
                              l_9)) == l_1057[1]) &&
                         1UL) |
                        g_55)))),
                  g_59)) <= (-3L))),
            l_1057[1]))) {
      uint32_t l_1074[1];
      int32_t l_1102 = 1L;
      int32_t l_1106 = 0x9AFB550FL;
      int32_t l_1107 = 2L;
      int32_t l_1116 = 0xEFAE687AL;
      int i;
      for (i = 0; i < 1; i++)
        l_1074[i] = 2UL;
      for (g_65 = 0; (g_65 <= 2); g_65 += 1) {
        int32_t l_1099 = (-1L);
        int32_t l_1109 = 0L;
        int8_t l_1112 = 0x31L;
        int32_t l_1113 = 3L;
        int32_t l_1114 = (-10L);
        int32_t l_1119[4];
        uint32_t l_1179 = 0xEEF5FCDDL;
        uint16_t l_1182 = 65529UL;
        int i;
        for (i = 0; i < 4; i++)
          l_1119[i] = 0xC2B10BA8L;
        g_2 = (safe_add_func_uint32_t_u_u(
            (((4L & (safe_mod_func_uint8_t_u_u(l_1057[g_65], g_5))) > 0L) <=
             (l_1057[g_65] ^ g_867)),
            ((safe_mul_func_uint8_t_u_u(
                 (safe_mul_func_uint16_t_u_u(
                     ((safe_div_func_uint32_t_u_u(
                          (safe_add_func_int32_t_s_s(
                              ((safe_sub_func_int32_t_s_s((l_1057[2] <= g_8),
                                                          (-5L))) < g_67),
                              g_59)),
                          0xF46F254AL)) < g_230),
                     l_1057[0])),
                 l_1074[0])) > g_137[0][9])));
        if ((g_64 ==
             (safe_add_func_int32_t_s_s(
                 (((safe_add_func_uint8_t_u_u(
                       (safe_sub_func_uint32_t_u_u(
                           (safe_rshift_func_int8_t_s_s(
                               ((l_1074[0] >= l_1074[0]) <= 0UL), 0)),
                           ((safe_sub_func_uint8_t_u_u(
                                (safe_lshift_func_int16_t_s_s(
                                    (safe_rshift_func_int16_t_s_u(
                                        (g_55 &
                                         (g_230 ^
                                          ((safe_div_func_uint8_t_u_u(
                                               (safe_mul_func_int16_t_s_s(
                                                   l_1057[0],
                                                   (l_1057[0] |
                                                    ((safe_sub_func_uint32_t_u_u(
                                                         (0xE627L >= 65532UL),
                                                         0x8ED71005L)) ^
                                                     0xDCAB6DA9L)))),
                                               g_137[0][0])) >= 0x5EF0C82AL))),
                                        13)),
                                    7)),
                                l_1074[0])) < l_1074[0]))),
                       l_1057[2])) ||
                   l_1057[g_65]) ||
                  0xA92BL),
                 g_5)))) {
          int8_t l_1105 = (-3L);
          int32_t l_1108 = (-4L);
          int32_t l_1115 = 2L;
          int32_t l_1118 = (-10L);
          int32_t l_1121 = 0x4667BE55L;
          int16_t l_1157 = 0x2AB8L;
          int32_t l_1163 = 5L;
          for (g_2 = 0; (g_2 != 22); ++g_2) {
            int32_t l_1100 = 7L;
            int32_t l_1111 = 0x2474AFADL;
            int32_t l_1120 = (-4L);
            if (l_1100) {
        {
                  ;
        }
      }
          }
          for (l_1107 = 0; (l_1107 > 10); ++l_1107) {
            uint32_t l_1127 = 0x1983C1CCL;
            g_53 = 0xA8E5B83EL;
            g_55 = (safe_mod_func_int16_t_s_s(
                ((g_230 ==
                  (((safe_mul_func_int16_t_s_s(
                        ((-1L) >
                         (0x80D2L ^
                          (((-3L) && ((0xFD00C3BBL ==
                                       (((safe_mul_func_uint8_t_u_u(
                                             g_1103, 0x7CL)) == l_1105) !=
                                        ((safe_lshift_func_int8_t_s_u(
                                             (0xF377L == l_1109), 5)) |
                                         l_1121))) >= 0x36L)) >= 0x5085L))),
                        g_1103)) &
                    l_1057[0]) > 0x6F2229D4L)) != 0x6442L),
                l_1057[1]));
            g_53 = (safe_div_func_int16_t_s_s(
                (safe_sub_func_int8_t_s_s(
                    (g_1103 ==
                     ((safe_mod_func_uint32_t_u_u(
                          (((safe_lshift_func_uint8_t_u_u(
                                (safe_rshift_func_uint16_t_u_s(
                                    ((safe_unary_minus_func_int32_t_s(
                                         (safe_mul_func_int16_t_s_s(
                                             (((safe_mod_func_int16_t_s_s(
                                                   (l_1112 & l_1157),
                                                   (safe_add_func_int32_t_s_s(
                                                       (l_1105 ^ 65527UL),
                                                       ((((safe_add_func_uint32_t_u_u(
                                                              (g_867 |
                                                               (((g_137[8][6] <=
                                                                  l_1127) >=
                                                                 ((+248UL) <
                                                                  g_67)) !=
                                                                4294967295UL)),
                                                              g_5)) !=
                                                          0x6A3FE687L) ==
                                                         l_1127) ||
                                                        g_130))))) > l_1127) <=
                                              g_53),
                                             l_1102)))) ^
                                     l_1163),
                                    8)),
                                2)) != 0x4447L) |
                           l_1105),
                          0xE78696FBL)) &
                      g_137[0][9])),
                    0x5AL)),
                1L));
          }
          g_137[4][4] =
              (((g_8 !=
                 ((safe_mul_func_uint16_t_u_u(
                      (safe_rshift_func_uint16_t_u_u(
                          l_1098,
                          (safe_sub_func_uint8_t_u_u(
                              (safe_add_func_int16_t_s_s(
                                  ((safe_div_func_int8_t_s_s(2L, g_8)) <=
                                   (g_66 &
                                    (((((!4L) != ((7L < (-1L)) !=
                                                  (g_137[0][9] == l_1115))) ==
                                       g_137[7][8]) >= l_1163) &
                                     0xE96A4512L))),
                                  l_1109)),
                              l_1057[0])))),
                      g_1103)) != l_1057[0])) |
                0x50L) > l_1106);
        } else {
          int32_t l_1177 = 6L;
          int32_t l_1178 = 1L;
          for (l_1107 = 0; l_1107 < 5; l_1107 += 1) {
            l_1095[l_1107] = (-4L);
          }
          --l_1179;
          l_1182 = l_1057[0];
        }
      }
    } else {
      uint32_t l_1201 = 0x566B8F71L;
      int32_t l_1236 = 0x5680FF4CL;
      int32_t l_1259 = 0xE03FDD0FL;
      uint32_t l_1374 = 0x79E9465FL;
      int32_t l_1376[5][8] = {
          {0xE3F0A255L, 1L, 1L, 1L, 0xE3F0A255L, 1L, 1L, 1L},
          {0xE3F0A255L, 1L, 1L, 1L, 0xE3F0A255L, 1L, 1L, 1L},
          {0xE3F0A255L, 1L, 1L, 1L, 0xE3F0A255L, 1L, 1L, 1L},
          {0xE3F0A255L, 1L, 1L, 1L, 0xE3F0A255L, 1L, 1L, 1L},
          {0xE3F0A255L, 1L, 1L, 1L, 0xE3F0A255L, 1L, 1L, 1L}};
      uint16_t l_1452 = 4UL;
      int i, j;
      l_1095[1] = 0x12803B1AL;
      if (((safe_mul_func_uint8_t_u_u(
               (safe_lshift_func_int16_t_s_s(0L, 15)),
               (safe_div_func_uint32_t_u_u(
                   (safe_mod_func_int16_t_s_s(
                       (((safe_add_func_uint16_t_u_u(
                             ((l_1104[0] >=
                               (g_2 == (l_1193[4][0] >=
                                        (safe_unary_minus_func_uint32_t_u(
                                            l_1195))))) ||
                              (safe_rshift_func_uint16_t_u_s(
                                  (g_55 < 0x5D96B6C5L),
                                  (safe_add_func_uint16_t_u_u(l_1200,
                                                              l_1201))))),
                             l_1201)) >= l_1201) |
                        l_1201),
                       g_55)),
                   (-5L))))) &
           (-3L))) {
        uint16_t l_1219 = 65535UL;
        int32_t l_1247[3][6] = {{(-1L), 6L, (-10L), (-10L), 6L, (-1L)},
                                {(-1L), 6L, (-10L), (-10L), 6L, (-1L)},
                                {(-1L), 6L, (-10L), (-10L), 6L, (-1L)}};
        uint32_t l_1375[3];
        int i, j;
        return l_1219;
      } else {
        l_1376[1][3] = g_2;
        return g_1103;
      }
    }
    l_1095[1] ^= (safe_sub_func_uint16_t_u_u(
        (l_1110 >= (safe_rshift_func_uint16_t_u_s(l_1393[4][7], 3))), 0UL));
    for (l_1117 = (-4); (l_1117 >= 2); ++l_1117) {
      int32_t l_1487 = 0xD56E3826L;
      int32_t l_1529 = 0x5D84583DL;
      int32_t l_1530 = 0x2C11212BL;
      int32_t l_1560 = (-1L);
      int32_t l_1561 = 0x7C9BE380L;
      int32_t l_1562 = 0L;
      int32_t l_1571 = 0xBBF2409EL;
      int32_t l_1620[7] = {(-1L), (-1L), 0L, (-1L), (-1L), 0L, (-1L)};
      int8_t l_1673 = 0xB5L;
      int i;
      for (l_1110 = 0; (l_1110 <= 2); l_1110 += 1) {
        int32_t l_1526 = 0x3828A98EL;
        int32_t l_1527 = (-7L);
        int32_t l_1556 = 7L;
        int32_t l_1557 = 0L;
        int32_t l_1559 = (-1L);
        int i;
        if ((safe_sub_func_int32_t_s_s((l_1057[l_1110] && 0x87L), l_1420[3]))) {
          int8_t l_1476 = 0x0BL;
          int8_t l_1504 = (-7L);
          int32_t l_1523 = 0xF695CC9CL;
          int32_t l_1524 = 0xCD5AA1C2L;
          int32_t l_1525 = 7L;
          int32_t l_1528[6] = {9L, 9L, 1L, 9L, 9L, 1L};
          uint32_t l_1532[6];
          int i;
          if (((safe_mod_func_int16_t_s_s(
                   (safe_mod_func_int32_t_s_s(
                       (l_1193[4][0] <
                        ((safe_lshift_func_uint16_t_u_s(2UL, g_65)) >=
                         (((safe_rshift_func_uint8_t_u_u(l_1476, 1)) >=
                           ((((safe_sub_func_int8_t_s_s(
                                  (l_1057[l_1110] |
                                   (safe_mul_func_int16_t_s_s(
                                       1L,
                                       ((safe_add_func_int32_t_s_s(
                                            l_1095[1],
                                            (safe_sub_func_int16_t_s_s(
                                                (safe_lshift_func_int8_t_s_s(
                                                    l_1101, 5)),
                                                ((g_64 > l_1195) <= g_67))))) ||
                                        g_67)))),
                                  g_5)) != 0x8132L) != 7L) > 0x58L)) >
                          0x4185L))),
                       g_867)),
                   1UL)) == 0xBFL)) {
            l_1487 = 0x909D2D7DL;
          } else {
            int32_t l_1488 = (-9L);
            l_1488 = ((0x8DCCL && g_130) < l_1488);
            g_2 = (safe_mod_func_uint8_t_u_u(
                (safe_mul_func_int16_t_s_s(
                    (((safe_sub_func_int32_t_s_s(
                          ((~(((safe_mod_func_uint16_t_u_u(
                                   (safe_mul_func_uint8_t_u_u(
                                       (safe_mul_func_int8_t_s_s(
                                           (-10L), (1UL != 0x2BFBEDCEL))),
                                       255UL)),
                                   ((l_1193[4][0] | g_67) |
                                    ((l_1057[l_1110] ^ 0xF848L) != g_230)))) &&
                               l_1504) &&
                              l_1117)) &
                           0xF4L),
                          0xF2090AF4L)) >= 0x620FL) ||
                     4294967286UL),
                    2L)),
                g_867));
          }
          for (l_1456 = 0; (l_1456 <= 0); l_1456 += 1) {
            int32_t l_1550 = (-4L);
            int32_t l_1551 = (-3L);
            int32_t l_1555 = 0x303E4832L;
            uint8_t l_1563 = 253UL;
            int i, j, k;
            g_1552--;
            l_1524 = l_1258[l_1456][(l_1110 + 2)][l_1456];
          }
        } else {
          uint16_t l_1570 = 0x35DCL;
          for (l_1456 = 7; (l_1456 >= 2); l_1456 -= 1) {
            int i, j;
            g_137[0][9] &= (l_1420[l_1110] > l_1393[(l_1110 + 2)][l_1110]);
          }
        }
        for (g_53 = 4; (g_53 >= 0); g_53 -= 1) {
          int i;
        }
        g_64 =
            ((l_1556 & l_1530) ||
             (!((l_1117 &
                 ((g_65 >
                   (0xBE88L <=
                    ((safe_lshift_func_uint16_t_u_s(
                         ((safe_sub_func_int16_t_s_s((0UL || l_1562), 6L)) &
                          ((((((safe_mul_func_int8_t_s_s(
                                   (((safe_add_func_int32_t_s_s(
                                         (((safe_div_func_uint32_t_u_u(
                                               ((safe_div_func_int8_t_s_s(
                                                    ((safe_unary_minus_func_int16_t_s(
                                                         (safe_mul_func_uint8_t_u_u(
                                                             1UL, l_1571)))) ^
                                                     l_1556),
                                                    0xA2L)) &&
                                                3UL),
                                               l_1526)) ||
                                           l_1561) > 0L),
                                         0x601AF1FAL)) ||
                                     l_1420[4]) != 0L),
                                   250UL)) |
                               3L) >= g_55) == 0x720EL) <= l_1258[0][0][0]) >=
                           l_1620[5])),
                         2)) &
                     255UL))) <= l_1095[1])) |
                0x43L)));
      }
      if (g_1552)
        break;
    }
  } else {
    int32_t l_1859 = 0xB83D4267L;
    l_1098 =
        ((l_1549 &
          (safe_add_func_uint8_t_u_u(
              (safe_sub_func_uint32_t_u_u(
                  g_59,
                  (7L ||
                   (safe_mod_func_int16_t_s_s(
                       ((((l_1859 ||
                           (((safe_sub_func_int32_t_s_s(
                                 (safe_rshift_func_int16_t_s_u(g_2, 7)),
                                 l_1859)) !=
                             ((0x617C32A5L != g_1766[3][2][1]) >=
                              ((safe_lshift_func_int8_t_s_s(
                                   (safe_mod_func_uint32_t_u_u(
                                       (safe_lshift_func_uint8_t_u_s(
                                           ((safe_div_func_int32_t_s_s(
                                                (safe_rshift_func_uint16_t_u_s(
                                                    (safe_div_func_uint8_t_u_u(
                                                        g_55, g_53)),
                                                    10)),
                                                0xFD6CF5AFL)) ||
                                            l_1859),
                                           5)),
                                       l_1859)),
                                   1)) &
                               7UL))) &&
                            l_1876)) > 0xC1L) < 0xCBL) <= 0L),
                       g_64))))),
              0xE6L))) |
         l_1573);
  }
  return l_1104[3];
}
static uint8_t func_14(int16_t p_15, uint32_t p_16, int8_t p_17) {
  int32_t l_731 = 2L;
  int32_t l_745 = (-1L);
  int32_t l_791 = 0x6AC2BE25L;
  uint16_t l_812 = 3UL;
  int32_t l_818 = (-1L);
  int32_t l_819 = 0L;
  int32_t l_820 = 3L;
  int16_t l_888 = 1L;
  uint32_t l_934[7];
  uint8_t l_935 = 0xCBL;
  int16_t l_1001 = 0x191AL;
  int32_t l_1003 = 0x96E83B6EL;
  int32_t l_1004[9][5][2] = {{{0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)}},
                             {{0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)}},
                             {{0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)}},
                             {{0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)}},
                             {{0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)}},
                             {{0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)}},
                             {{0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)}},
                             {{0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)}},
                             {{0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)},
                              {0x2A2D5733L, (-2L)}}};
  uint32_t l_1024 = 1UL;
  int i, j, k;
  for (i = 0; i < 7; i++)
    l_934[i] = 6UL;
  l_745 = (((safe_sub_func_int32_t_s_s(
                g_2, (safe_sub_func_uint32_t_u_u(
                         (65529UL >= l_731),
                         (safe_add_func_uint8_t_u_u(
                             ((safe_lshift_func_uint16_t_u_s(0x5EE4L, p_15)) &
                              0x7E6ECF76L),
                             p_17)))))) ==
            ((safe_add_func_uint32_t_u_u(
                 (g_5 ^ (((safe_mul_func_int16_t_s_s(
                              (safe_div_func_int16_t_s_s(
                                  (safe_div_func_uint32_t_u_u(
                                      (+((0UL <= g_8) | 0x2DL)), g_130)),
                                  l_731)),
                              l_731)) ^
                          0x768DL) &&
                         8UL)),
                 l_731)) <= p_16)) ||
           p_17);
  for (g_55 = 7; (g_55 >= 1); g_55 -= 1) {
    int32_t l_759[2][2][9] = {{{(-3L), 0x8357A014L, 0L, 0x8357A014L, (-3L),
                                (-5L), (-3L), 0x8357A014L, 0L},
                               {(-3L), 0x8357A014L, 0L, 0x8357A014L, (-3L),
                                (-5L), (-3L), 0x8357A014L, 0L}},
                              {{(-3L), 0x8357A014L, 0L, 0x8357A014L, (-3L),
                                (-5L), (-3L), 0x8357A014L, 0L},
                               {(-3L), 0x8357A014L, 0L, 0x8357A014L, (-3L),
                                (-5L), (-3L), 0x8357A014L, 0L}}};
    int32_t l_794 = 0x0B2CFCE5L;
    int32_t l_813 = 0x490B274EL;
    int32_t l_816 = (-1L);
    int32_t l_817[3][7] = {
        {(-2L), 0x051BF286L, 0L, 0x051BF286L, (-2L), 0L, (-2L)},
        {(-2L), 0x051BF286L, 0L, 0x051BF286L, (-2L), 0L, (-2L)},
        {(-2L), 0x051BF286L, 0L, 0x051BF286L, (-2L), 0L, (-2L)}};
    uint8_t l_936 = 0xD2L;
    int i, j, k;
    g_137[0][9] =
        ((((0x2AB7L |
            ((safe_mod_func_uint32_t_u_u(
                 ((safe_rshift_func_uint16_t_u_u(
                      (safe_div_func_uint8_t_u_u(p_16, 0x35L)), 12)) ==
                  ((((+p_16) >= 0x3795797BL) !=
                    (((safe_rshift_func_uint8_t_u_s(
                          p_15, ((safe_sub_func_int32_t_s_s(
                                     8L, (((safe_sub_func_int32_t_s_s(
                                               l_759[1][1][4],
                                               (safe_mul_func_uint16_t_u_u(
                                                   0UL, g_64)))) &
                                           l_759[1][1][4]) |
                                          0x29L))) >= p_15))) < 0xC11CL) &
                     p_17)) >= l_759[0][1][7])),
                 p_16)) |
             g_67)) |
           l_745) &&
          5L) &&
         0x1BL);
    for (p_17 = 0; (p_17 <= 8); p_17 += 1) {
      uint8_t l_766 = 0xFCL;
      int32_t l_811 = 0xE9BF8091L;
      int i, j;
      if (g_137[p_17][p_17]) {
        int i, j;
        l_745 |=
            (((((safe_mul_func_int8_t_s_s(
                    ((safe_mul_func_uint16_t_u_u(0x17A5L, g_137[0][9])) ^
                     l_766),
                    (safe_mul_func_uint16_t_u_u(65533UL, 0xE9ECL)))) &&
                0x81803727L) ==
               (p_17 |
                (safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u(
                                               p_15, (l_731 == g_137[0][9]))),
                                           (-9L))))) == 0xCBB896A2L) &&
             l_731);
        l_794 ^= (safe_rshift_func_uint8_t_u_u(
            (((safe_lshift_func_int16_t_s_u(
                  ((safe_mod_func_uint16_t_u_u(
                       (safe_div_func_uint8_t_u_u(
                           ((l_759[1][0][5] & p_16) <=
                            ((safe_sub_func_uint8_t_u_u(
                                 (safe_lshift_func_int8_t_s_u(
                                     ((-7L) ^ g_137[g_55][(g_55 + 1)]), 4)),
                                 (safe_sub_func_uint16_t_u_u(
                                     (safe_sub_func_int8_t_s_s(
                                         g_137[0][9],
                                         (safe_lshift_func_int8_t_s_s(
                                             (((l_791 < 65534UL) || g_55) >
                                              (safe_sub_func_int32_t_s_s(
                                                  p_15, l_759[0][1][7]))),
                                             g_59)))),
                                     g_53)))) >= g_2)),
                           g_137[g_55][(g_55 + 1)])),
                       l_759[1][1][1])) ||
                   p_17),
                  l_759[0][1][3])) < l_759[1][1][4]) >= 6UL),
            g_66));
        g_53 =
            ((safe_rshift_func_uint16_t_u_s(
                 (((p_15 <
                    (safe_mod_func_uint16_t_u_u(
                        g_137[g_55][(g_55 + 1)],
                        (safe_rshift_func_int16_t_s_s(
                            (safe_unary_minus_func_uint32_t_u((g_65 >= p_17))),
                            ((0x07L >=
                              ((safe_sub_func_int8_t_s_s(
                                   (((((+(safe_lshift_func_int16_t_s_u(
                                           (safe_rshift_func_uint16_t_u_s(
                                               ((safe_mod_func_uint16_t_u_u(
                                                    ((255UL <= g_2) ==
                                                     ((p_15 && 4294967295UL) ^
                                                      1UL)),
                                                    l_766)) == g_64),
                                               4)),
                                           l_745))) ||
                                       l_811) == 0x7EL) |
                                     p_16) > l_812),
                                   g_66)) <= p_15)) >= l_731)))))) != g_59) ^
                  g_5),
                 g_130)) <= (-1L));
      } else {
        int32_t l_862 = 0x54A66285L;
        int32_t l_868[9][5] = {{(-1L), 0x83E85982L, (-1L), 0x83E85982L, (-1L)},
                               {(-1L), 0x83E85982L, (-1L), 0x83E85982L, (-1L)},
                               {(-1L), 0x83E85982L, (-1L), 0x83E85982L, (-1L)},
                               {(-1L), 0x83E85982L, (-1L), 0x83E85982L, (-1L)},
                               {(-1L), 0x83E85982L, (-1L), 0x83E85982L, (-1L)},
                               {(-1L), 0x83E85982L, (-1L), 0x83E85982L, (-1L)},
                               {(-1L), 0x83E85982L, (-1L), 0x83E85982L, (-1L)},
                               {(-1L), 0x83E85982L, (-1L), 0x83E85982L, (-1L)},
                               {(-1L), 0x83E85982L, (-1L), 0x83E85982L, (-1L)}};
        uint16_t l_870 = 8UL;
        int i, j;
        for (g_67 = 0; (g_67 <= 8); g_67 += 1) {
          uint8_t l_821 = 1UL;
          int32_t l_846 = 0xC30DC48EL;
          int32_t l_869 = 0L;
          for (l_794 = 2; (l_794 <= 8); l_794 += 1) {
            int32_t l_814 = 0x4918D01AL;
            int32_t l_815 = 0xBDE8EF1BL;
            int i, j;
            --l_821;
          }
        }
        l_745 = ((-1L) |
                 ((l_811 != 0xDE380E67L) !=
                  (((safe_div_func_uint8_t_u_u(
                        (l_817[1][1] ==
                         (((0x5C452818L !=
                            ((~l_759[1][1][4]) !=
                             (safe_mul_func_int8_t_s_s(
                                 (safe_sub_func_int32_t_s_s(
                                     ((safe_lshift_func_uint8_t_u_s(
                                          (safe_div_func_uint32_t_u_u(
                                              (safe_rshift_func_uint16_t_u_s(
                                                  (7UL > 0xDA542E61L), 6)),
                                              (safe_sub_func_int8_t_s_s(
                                                  l_812, l_862)))),
                                          3)) < l_888),
                                     g_55)),
                                 g_137[0][9])))) ^
                           g_8) |
                          g_137[p_17][p_17])),
                        g_8)) > p_17) ||
                   9L)));
      }
    }
    for (l_819 = 0; (l_819 == 19);
         l_819 = safe_add_func_uint32_t_u_u(l_819, 1)) {
      if ((g_2 &&
           (((safe_rshift_func_uint16_t_u_u(
                 (((safe_sub_func_uint16_t_u_u(
                       (251UL & 0xDAL),
                       (((0x89L >
                          (safe_add_func_int8_t_s_s(
                              (safe_mul_func_int16_t_s_s(
                                  (safe_add_func_int16_t_s_s(
                                      (((p_15 != 1UL) <=
                                        (safe_add_func_uint16_t_u_u(
                                            ((4294967295UL ||
                                              ((safe_add_func_int8_t_s_s(
                                                   (safe_add_func_int16_t_s_s(
                                                       ((g_67 >=
                                                         (safe_rshift_func_uint16_t_u_s(
                                                             ((safe_rshift_func_int8_t_s_u(
                                                                  (p_15 || g_2),
                                                                  g_137[7]
                                                                       [5])) <=
                                                              g_64),
                                                             6))) == 8L),
                                                       4L)),
                                                   0xFCL)) != g_137[2][0])) ||
                                             p_17),
                                            g_137[0][9]))) &
                                       g_137[5][1]),
                                      0x9AA5L)),
                                  l_759[1][1][4])),
                              1L))) ^
                         l_791) |
                        0UL))) &&
                   l_934[6]) != l_935),
                 g_59)) &
             7UL) ^
            p_17))) {
      } else {
        int16_t l_958[6][5][7] = {
            {{(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL}},
            {{(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL}},
            {{(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL}},
            {{(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL}},
            {{(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL}},
            {{(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL},
             {(-5L), 0xC779L, (-1L), 0x7819L, 0x917EL, 0x2F68L, 0x2CFCL}}};
        int i, j, k;
      }
      l_816 = 0L;
    }
    g_137[0][9] =
        ((safe_rshift_func_int8_t_s_s(
             (safe_rshift_func_uint8_t_u_u(
                 (0xDC109275L |
                  (safe_div_func_int32_t_s_s(
                      (safe_unary_minus_func_uint32_t_u(g_230)),
                      (safe_mul_func_uint16_t_u_u(
                          (safe_div_func_uint32_t_u_u(g_2, p_15)),
                          (g_2 |
                           (g_8 ==
                            (safe_sub_func_int8_t_s_s(
                                ((l_817[1][1] !=
                                  (safe_rshift_func_int16_t_s_u(
                                      ((safe_add_func_int16_t_s_s(
                                           (((safe_mod_func_int16_t_s_s(
                                                 (safe_lshift_func_int16_t_s_s(
                                                     g_867, l_745)),
                                                 p_16)) > l_759[1][0][7]) ==
                                            g_5),
                                           p_15)) |
                                       g_8),
                                      3))) >= g_230),
                                l_759[0][1][8]))))))))),
                 0)),
             g_67)) < 3L);
  }
  l_819 = (safe_rshift_func_int8_t_s_s(1L, l_820));
  if ((g_2 ||
       (safe_sub_func_int32_t_s_s(
           (p_17 |
            (safe_rshift_func_uint16_t_u_u(
                ((g_53 >=
                  (safe_add_func_uint8_t_u_u(
                      ((l_934[6] |
                        ((safe_lshift_func_int16_t_s_s(0x5D07L, 15)) ==
                         (((((p_15 ||
                              (((((safe_rshift_func_uint8_t_u_u(
                                      (safe_lshift_func_int8_t_s_u(
                                          ((safe_div_func_uint32_t_u_u(
                                               (0x56CF6FDCL > p_15), g_130)) |
                                           g_867),
                                          0)),
                                      l_934[6])) != l_731) ||
                                 g_67) >= 0UL) |
                               l_888)) >= 4294967295UL) < p_16) < g_65) !=
                          g_66))) >= g_64),
                      g_64))) &&
                 0x77CEL),
                g_65))),
           l_934[6])))) {
    int32_t l_1000[2];
    int32_t l_1002 = 0L;
    int32_t l_1005 = 0x9FECC935L;
    int32_t l_1006 = 0xA9FF5DD6L;
    int32_t l_1007 = 0x7D45F815L;
    int32_t l_1008 = 0xA2D395C6L;
    int32_t l_1009 = 0xBF52A11FL;
    int32_t l_1010 = 1L;
    uint8_t l_1011 = 0x84L;
    int i;
    for (i = 0; i < 2; i++)
      l_1000[i] = 0x78B61907L;
    l_1011++;
  } else {
    uint32_t l_1025[10][8][3] = {{{8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L}},
                                 {{8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L}},
                                 {{8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L}},
                                 {{8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L}},
                                 {{8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L}},
                                 {{8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L}},
                                 {{8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L}},
                                 {{8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L}},
                                 {{8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L}},
                                 {{8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L},
                                  {8UL, 0UL, 0x6D38DFD3L}}};
    int16_t l_1027 = (-1L);
    int32_t l_1028[4];
    int i, j, k;
    for (i = 0; i < 4; i++)
      ;
    g_137[3][8] =
        (0UL ||
         ((0xE3AEL <=
           (g_137[0][9] ^
            (((((((((((safe_mul_func_uint8_t_u_u(
                          (((g_55 != p_16) ^
                            (safe_sub_func_uint32_t_u_u(
                                (g_66 <= (((safe_mul_func_int8_t_s_s(
                                               (p_16 == 0L),
                                               (safe_lshift_func_uint8_t_u_s(
                                                   l_1024, 7)))) |
                                           l_935) <= g_230)),
                                p_17))) ||
                           g_67),
                          p_17)) == l_935) == l_818) ||
                    l_1025[0][2][1]) >= l_1025[5][1][1]) < p_17) &&
                 g_137[6][0]) > 0L) ||
               1UL) <= g_130) >= g_65))) >= l_1025[5][2][1]));
    g_137[0][9] =
        (l_1025[0][2][1] | (((+p_17) && 0xB9BDL) > (p_17 != l_1025[6][7][2])));
    for (l_820 = 0; (l_820 <= 1); l_820 += 1) {
    }
    l_1028[1] = 0L;
  }
  return l_820;
}
static uint8_t func_20(uint32_t p_21, uint8_t p_22) {
  uint8_t l_30 = 0xA4L;
  uint8_t l_31[3];
  uint32_t l_48 = 0xE3AA9C1CL;
  int16_t l_49 = (-6L);
  int32_t l_655[9][10][2] = {{{1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)}},
                             {{1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)}},
                             {{1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)}},
                             {{1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)}},
                             {{1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)}},
                             {{1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)}},
                             {{1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)}},
                             {{1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)}},
                             {{1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)},
                              {1L, (-8L)}}};
  int16_t l_718 = (-5L);
  int i, j, k;
  for (i = 0; i < 3; i++)
    l_31[i] = 0x2EL;
  l_30 = (safe_sub_func_uint8_t_u_u(p_22, (p_21 >= 0x68AA2D34L)));
  if (func_23(p_21, p_22)) {
    int32_t l_33 = 0L;
    if ((p_22 <= p_22)) {
      int16_t l_32 = 0x0E2EL;
      l_32 = l_31[2];
    } else {
      return l_33;
    }
  } else {
    uint8_t l_50 = 0xE5L;
    int32_t l_647 = 0x9F24E1B9L;
    uint16_t l_669[6][10][3] = {{{1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL}},
                                {{1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL}},
                                {{1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL}},
                                {{1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL}},
                                {{1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL}},
                                {{1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL},
                                 {1UL, 5UL, 4UL}}};
    uint32_t l_670 = 0x22B34C74L;
    int32_t l_671[6];
    int i, j, k;
    for (i = 0; i < 6; i++)
      l_671[i] = 0x12C7BB83L;
    l_647 |=
        (((func_34(func_37(((safe_lshift_func_uint16_t_u_s(
                                0x37D4L,
                                (func_23(func_41(g_5, l_30, g_2,
                                                 (p_21 &
                                                  ((l_48 != l_49) &&
                                                   (l_50 != (((~0x156BL) ||
                                                              0UL) == g_2))))),
                                         l_30) == 0xD0C5FD78L))) < p_21)),
                   p_22) > l_30) ^
          g_130) >= l_50);
    l_655[6][2][1] &= (safe_mul_func_int16_t_s_s(
        0x78A1L,
        (!(0xFF908808L ^ (safe_div_func_int16_t_s_s(
                             (safe_rshift_func_int8_t_s_s(6L, 1)), l_48))))));
    g_53 =
        ((((safe_rshift_func_uint8_t_u_s(
               (safe_sub_func_uint32_t_u_u(
                   g_59,
                   ((((p_21 >= l_647) == g_59) ||
                     (((safe_div_func_int8_t_s_s(0x14L, 0x78L)) <= 0x94A2L) <
                      (+((safe_mod_func_uint16_t_u_u(
                             (0xF48C939FL &
                              (safe_lshift_func_uint8_t_u_u(
                                  (safe_mod_func_int32_t_s_s(
                                      ((g_55 >= g_66) | l_31[0]), 0x4E6BB63AL)),
                                  p_22))),
                             p_22)) ^
                         g_65)))) > g_53))),
               5)) >= l_669[0][2][2]) &
          l_670) &
         l_671[1]);
  }
  l_655[7][5][1] = (safe_sub_func_uint32_t_u_u(
      (safe_rshift_func_int16_t_s_u(
          ((+(safe_unary_minus_func_uint16_t_u((
               (safe_rshift_func_uint8_t_u_s(p_21, 3)) ||
               ((((safe_mul_func_int16_t_s_s(
                      (safe_rshift_func_int16_t_s_s(1L, 0)),
                      (0x4A68L ^
                       (safe_add_func_uint8_t_u_u(
                           (safe_add_func_int16_t_s_s((g_8 & p_22), 1L)),
                           (safe_div_func_uint16_t_u_u(
                               (p_22 || (((((safe_add_func_uint8_t_u_u(
                                                (0x010F4C15L >= p_21), p_21)) &&
                                            g_137[0][2]) ||
                                           l_48) != l_49) >= g_137[0][9])),
                               g_66))))))) > 0x50L) &
                 0UL) ^
                p_21))))) <= 0xE57011C1L),
          6)),
      g_64));
  l_718 ^=
      ((safe_rshift_func_uint16_t_u_s(
           ((safe_add_func_int32_t_s_s(
                ((safe_sub_func_uint8_t_u_u(
                     l_30,
                     ((safe_sub_func_uint16_t_u_u(
                          (safe_unary_minus_func_uint32_t_u((
                              ((1UL <
                                ((safe_mul_func_uint16_t_u_u(l_30, p_21)) >
                                 (!((((safe_mul_func_uint8_t_u_u(
                                          g_66,
                                          ((l_30 ^
                                            (safe_sub_func_uint8_t_u_u(
                                                l_31[0],
                                                (safe_add_func_uint8_t_u_u(
                                                    ((safe_mul_func_uint8_t_u_u(
                                                         (0x61L ==
                                                          ((safe_sub_func_int16_t_s_s(
                                                               (!(safe_lshift_func_uint16_t_u_s(
                                                                   ((((safe_unary_minus_func_uint8_t_u(
                                                                          (g_130 &
                                                                           l_49))) >=
                                                                      l_31[1]) >=
                                                                     6L) <=
                                                                    g_66),
                                                                   8))),
                                                               1L)) == g_230)),
                                                         253UL)) ||
                                                     g_137[0][9]),
                                                    l_30))))) &
                                           (-1L)))) ^
                                      p_21) &
                                     0x0949L) == p_21)))) |
                               l_655[6][2][1]) ^
                              65534UL))),
                          g_59)) ||
                      p_21))) == p_21),
                g_65)) > g_2),
           g_137[0][9])) &&
       g_64);
  return g_53;
}
static uint8_t func_23(int32_t p_24, uint32_t p_25) {
  for (p_24 = (-3); (p_24 > 9); p_24++) {
    return g_2;
  }
  return p_25;
}
static uint32_t func_34(uint32_t p_35, int8_t p_36) {
  int32_t l_644 = 0L;
  int32_t l_645 = 0xF9C36837L;
  int32_t l_646 = 0x4197A594L;
  l_645 = l_644;
  l_646 ^= ((l_645 >= 0x4A3604C4L) != ((g_130 != g_2) | p_35));
  return p_35;
}
static uint32_t func_37(int32_t p_38) {
  uint32_t l_92 = 1UL;
  uint32_t l_95 = 18446744073709551608UL;
  uint32_t l_580 = 7UL;
  g_53 = (safe_mul_func_uint16_t_u_u(
      ((+func_73(
           (+(safe_rshift_func_uint16_t_u_u(
               func_41(g_55, g_53,
                       ((((4294967295UL ^
                           func_80(((safe_rshift_func_int8_t_s_s(
                                        (0xE53FL | 0xE835L),
                                        func_87(p_38, l_92,
                                                (safe_lshift_func_int16_t_s_s(
                                                    g_5, 15)),
                                                l_95))) > g_130),
                                   g_53, g_130, p_38)) &&
                          g_59) >= l_92) != p_38),
                       g_59),
               2))),
           l_92, l_580)) ^
       0UL),
      65535UL));
  return g_137[0][9];
}
static int32_t func_41(int32_t p_42, uint32_t p_43, int32_t p_44,
                       int32_t p_45) {
  uint32_t l_52 = 0UL;
  int32_t l_54 = (-7L);
  int32_t l_56 = 0x9025B0D6L;
  int32_t l_57 = 0x7B254764L;
  int32_t l_58 = 0x42069719L;
  int32_t l_60 = 0L;
  int32_t l_61 = 0x34D1CD05L;
  int32_t l_62 = 0L;
  int32_t l_63[6] = {(-3L), (-3L), (-1L), (-3L), (-3L), (-1L)};
  int i;
  l_52 = 0x1C250287L;
  g_67--;
  return g_55;
}
static uint16_t func_73(int8_t p_74, uint16_t p_75, uint16_t p_76) {
  int32_t l_587[1];
  uint16_t l_604 = 0UL;
  int32_t l_640 = (-1L);
  uint32_t l_641 = 0UL;
  int i;
  for (i = 0; i < 1; i++)
    l_587[i] = (-4L);
  g_55 = (safe_add_func_int8_t_s_s(
      ((p_75 == p_76) ==
       (0UL |
        ((safe_div_func_uint16_t_u_u(
             0x8AEFL,
             ((l_587[0] &
               ((l_587[0] >
                 (safe_sub_func_uint8_t_u_u(
                     (l_587[0] | (((!p_75) == (safe_lshift_func_int8_t_s_u(
                                                  (safe_sub_func_uint8_t_u_u(
                                                      0xA5L, 0x12L)),
                                                  1))) >= g_2)),
                     0x6CL))) == (-9L))) |
              p_75))) != g_8))),
      8UL));
  for (g_5 = 0; (g_5 <= 56); g_5 = safe_add_func_uint8_t_u_u(g_5, 1)) {
    int8_t l_597 = 0x03L;
    int32_t l_598 = 0x9C4BD882L;
    int32_t l_599 = 2L;
    int32_t l_600 = 0xA6B289DDL;
    int32_t l_601 = 0xF7335CC2L;
    int32_t l_602 = (-1L);
    int32_t l_603[6] = {0xDB01D121L, 0xDB01D121L, 0xD3C3C058L,
                        0xDB01D121L, 0xDB01D121L, 0xD3C3C058L};
    int i;
    l_604++;
    l_587[0] = (p_76 & l_602);
    for (g_59 = 3; (g_59 <= 8); g_59 += 1) {
      int i, j;
      if (g_137[g_59][g_59]) {
        return g_137[4][8];
      } else {
        uint8_t l_609 = 0x1BL;
        int32_t l_639 = 1L;
        l_609 &= (safe_lshift_func_uint16_t_u_u(((p_76 | g_55) >= 0x09L), 10));
        l_639 |= (safe_add_func_int32_t_s_s(
            0x744CDEB4L,
            ((safe_add_func_uint8_t_u_u(
                 (safe_mod_func_uint8_t_u_u(
                     (safe_sub_func_int16_t_s_s(p_74, p_76)),
                     (((+l_587[0]) ^
                       ((safe_sub_func_int8_t_s_s(
                            ((safe_sub_func_int32_t_s_s(
                                 (safe_mod_func_int16_t_s_s(
                                     (((safe_lshift_func_int8_t_s_u(
                                           (safe_lshift_func_int16_t_s_u(
                                               (safe_lshift_func_uint16_t_u_u(
                                                   p_74, 12)),
                                               6)),
                                           ((safe_lshift_func_int16_t_s_u(
                                                g_137[g_59][g_59], 8)) <=
                                            (safe_add_func_uint8_t_u_u(
                                                ((safe_rshift_func_int16_t_s_s(
                                                     (safe_add_func_uint32_t_u_u(
                                                         0x7340A80CL, g_53)),
                                                     p_74)) <= p_76),
                                                l_609))))) &
                                       g_137[g_59][g_59]) < 0x0926L),
                                     l_609)),
                                 4UL)) &&
                             p_76),
                            p_76)) &
                        p_75)) &
                      6UL))),
                 1L)) <= l_609)));
        return p_75;
      }
    }
  }
  --l_641;
  return g_59;
}
static uint32_t func_80(int32_t p_81, uint32_t p_82, uint8_t p_83,
                        uint16_t p_84) {
  uint16_t l_563 = 65526UL;
  int32_t l_579 = 0x6A8E26A4L;
  g_2 = l_563;
  l_579 = (safe_mod_func_uint16_t_u_u(
      (safe_mul_func_uint8_t_u_u(
          ((g_55 >
            (safe_mod_func_uint32_t_u_u(
                (((~((safe_rshift_func_uint8_t_u_u(
                         (safe_rshift_func_uint8_t_u_u((l_563 >= 2UL), 2)),
                         (safe_rshift_func_int8_t_s_u(
                             (((safe_div_func_uint16_t_u_u(3UL, g_67)) &&
                               l_563) > p_84),
                             7)))) <= l_563)) >= p_83) &
                 1UL),
                l_563))) < 0x7DFDL),
          g_2)),
      0x26BEL));
  return l_563;
}
static int8_t func_87(int16_t p_88, uint32_t p_89, int32_t p_90, int32_t p_91) {
  uint16_t l_100 = 2UL;
  uint8_t l_105 = 0xA8L;
  int32_t l_110 = (-7L);
  int32_t l_195[6];
  int32_t l_418[9] = {(-1L), (-1L), 0xFC91880AL, (-1L), (-1L),
                      0xFC91880AL, (-1L), (-1L), 0xFC91880AL};
  uint8_t l_450 = 0x37L;
  uint8_t l_527 = 3UL;
  int i;
  for (i = 0; i < 6; i++)
    l_195[i] = (-1L);
  l_110 =
      (((safe_sub_func_uint16_t_u_u(
            (safe_rshift_func_int16_t_s_s(
                (l_100 &
                 (safe_rshift_func_uint16_t_u_u(
                     (safe_sub_func_uint8_t_u_u((l_105 > 0x5EE7416AL), l_105)),
                     2))),
                (g_65 <=
                 ((l_100 > (g_55 < ((safe_mul_func_uint16_t_u_u(
                                        (safe_sub_func_int8_t_s_s(l_105, g_66)),
                                        l_105)) != p_88))) > 1UL)))),
            0x15C0L)) ^
        0x8B95L) != g_59);
  if ((safe_mod_func_int32_t_s_s(g_8, g_67))) {
    uint32_t l_129 = 18446744073709551615UL;
  } else {
    uint8_t l_138[5][9] = {
        {1UL, 5UL, 0xB1L, 0x83L, 0xB1L, 5UL, 1UL, 0xFEL, 0x0BL},
        {1UL, 5UL, 0xB1L, 0x83L, 0xB1L, 5UL, 1UL, 0xFEL, 0x0BL},
        {1UL, 5UL, 0xB1L, 0x83L, 0xB1L, 5UL, 1UL, 0xFEL, 0x0BL},
        {1UL, 5UL, 0xB1L, 0x83L, 0xB1L, 5UL, 1UL, 0xFEL, 0x0BL},
        {1UL, 5UL, 0xB1L, 0x83L, 0xB1L, 5UL, 1UL, 0xFEL, 0x0BL}};
    uint8_t l_191 = 255UL;
    int32_t l_192 = 0xBA7A0367L;
    int32_t l_238 = (-1L);
    uint32_t l_257 = 0x01866F3FL;
    uint16_t l_295[1][5] = {{0x225AL, 0x17D3L, 0x225AL, 0x17D3L, 0x225AL}};
    int32_t l_298 = (-1L);
    int32_t l_300 = 0x239EC288L;
    int32_t l_302 = 0x193FF477L;
    uint32_t l_342[4][5][9] = {
        {{18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L}},
        {{18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L}},
        {{18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L}},
        {{18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L},
         {18446744073709551615UL, 18446744073709551615UL, 0x62709E71L,
          0x12C240C7L, 18446744073709551614UL, 0x0E7BC498L,
          18446744073709551614UL, 0x12C240C7L, 0x62709E71L}}};
    uint16_t l_519 = 0x033CL;
    int32_t l_533 = 0x1A28FC56L;
    int32_t l_534 = 0x3CA43624L;
    int32_t l_535[3][5][5] = {
        {{0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL},
         {0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL},
         {0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL},
         {0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL},
         {0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL}},
        {{0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL},
         {0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL},
         {0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL},
         {0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL},
         {0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL}},
        {{0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL},
         {0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL},
         {0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL},
         {0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL},
         {0xB642941FL, 0x55B21C62L, (-1L), 0x55B21C62L, 0xB642941FL}}};
    uint8_t l_547 = 2UL;
    int i, j, k;
    if (p_88) {
      int32_t l_136[4] = {0xBC35819BL, 5L, 0xBC35819BL, 5L};
      int32_t l_178 = 0L;
      int32_t l_359 = 0x4A83407AL;
      uint16_t l_360[1][4] = {{0x7824L, 65535UL, 0x7824L, 65535UL}};
      uint32_t l_448 = 5UL;
      int i, j;
      --l_138[1][8];
      l_136[3] =
          ((safe_mul_func_int16_t_s_s(0x1D65L, 0L)) <
           ((safe_add_func_uint8_t_u_u(
                (2UL < l_360[0][3]),
                (safe_mod_func_uint32_t_u_u(
                    (((((safe_rshift_func_int16_t_s_s(g_59, 9)) >=
                        (safe_add_func_int8_t_s_s(
                            ((safe_mul_func_int16_t_s_s(l_418[5], 0x7D06L)) ||
                             (safe_mod_func_int32_t_s_s((l_178 <= g_130),
                                                        g_137[8][0]))),
                            p_88))) |
                       0UL) ||
                      65535UL) == g_130),
                    l_300)))) ||
            l_418[5]));
    } else {
      uint32_t l_522 = 1UL;
      int32_t l_532 = 1L;
      int32_t l_536 = (-8L);
      int32_t l_537 = 0x286DF23CL;
      int32_t l_538 = 0xB2FF8A7FL;
      int32_t l_539 = 8L;
      int32_t l_540 = (-9L);
      int32_t l_541 = 0x73AB32B6L;
      int32_t l_542 = 7L;
      int32_t l_543 = (-1L);
      int32_t l_544 = 3L;
      int32_t l_545 = 0x69DA250BL;
      int32_t l_546 = 0x77F8ABC9L;
      l_418[7] &= l_522;
      l_192 |=
          (g_2 >
           (g_67 >
            (((safe_rshift_func_uint16_t_u_u(
                  ((((p_91 <=
                      (safe_add_func_uint8_t_u_u(
                          l_527, ((0x100AL | (((((safe_sub_func_uint8_t_u_u(
                                                     g_59, g_230)) > g_5) >=
                                                0xC786L) < 65529UL) &
                                              l_298)) &
                                  0L)))) >= l_105) == g_137[0][9]) <= l_238),
                  3)) |
              (-1L)) < g_55)));
      --l_547;
    }
    g_137[0][9] |= 0x1C1ADFDEL;
    g_64 &=
        ((((safe_mod_func_uint16_t_u_u(65531UL, p_88)) | l_195[0]) &
          ((safe_rshift_func_int8_t_s_u(
               (+(safe_rshift_func_uint16_t_u_u(
                   (((safe_div_func_int8_t_s_s(
                         1L,
                         ((safe_div_func_uint16_t_u_u(
                              (((safe_rshift_func_int16_t_s_s(
                                    ((p_91 ^ 0x3615L) >= l_302), 6)) != p_91) <=
                               (((((((l_195[0] >= l_105) <= p_89) & p_88) &&
                                   p_88) >= 4L) |
                                 0xE2L) > 0xBD513DE3L)),
                              p_91)) |
                          p_88))) ||
                     p_89) > 0xEBL),
                   p_88))),
               3)) < p_91)) < g_130);
    return l_195[3];
  }
  return p_89;
}
int main(void) {
  int i, j, k;
  int print_hash_value = 0;
  crc32_gentab();
  func_1();
  transparent_crc(g_2, "g_2", print_hash_value);
  transparent_crc(g_5, "g_5", print_hash_value);
  transparent_crc(g_8, "g_8", print_hash_value);
  transparent_crc(g_53, "g_53", print_hash_value);
  transparent_crc(g_55, "g_55", print_hash_value);
  transparent_crc(g_59, "g_59", print_hash_value);
  transparent_crc(g_64, "g_64", print_hash_value);
  transparent_crc(g_65, "g_65", print_hash_value);
  transparent_crc(g_66, "g_66", print_hash_value);
  transparent_crc(g_67, "g_67", print_hash_value);
  transparent_crc(g_130, "g_130", print_hash_value);
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 10; j++) {
      transparent_crc(g_137[i][j], "g_137[i][j]", print_hash_value);
      if (print_hash_value)
        printf("index = [%d][%d]\n", i, j);
    }
  }
  transparent_crc(g_230, "g_230", print_hash_value);
  transparent_crc(g_867, "g_867", print_hash_value);
  transparent_crc(g_1103, "g_1103", print_hash_value);
  transparent_crc(g_1552, "g_1552", print_hash_value);
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 10; j++) {
      for (k = 0; k < 3; k++) {
        transparent_crc(g_1766[i][j][k], "g_1766[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}

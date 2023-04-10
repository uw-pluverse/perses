typedef unsigned int size_t;
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long long int int64_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;
int printf (const char *, ...);
void __assert_fail (const char *__assertion, const char *__file, unsigned int __line, const char *__function);
static void
platform_main_end(uint32_t crc, int flag) {
 printf ("checksum = %X\n", crc);
}
static int8_t
(safe_unary_minus_func_int8_t_s)(int8_t si )
{

  return
    (si==
        (-128)
                ) ?
    ((si)) :
    -si;
}
static int8_t
(safe_add_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return
    (((si1>0) && (si2>0) && (si1 > (
                                   (127)
                                           -si2))) || ((si1<0) && (si2<0) && (si1 < (
                                                                                     (-128)
                                                                                             -si2)))) ?
    ((si1)) :
    (si1 + si2);
}
static int8_t
(safe_sub_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return
    (((si1^si2) & (((si1 ^ ((si1^si2) & (~
                                         (127)
                                                 )))-si2)^si2)) < 0) ?
    ((si1)) :
    (si1 - si2);
}
static int8_t
(safe_mul_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return
    (((si1 > 0) && (si2 > 0) && (si1 > (
                                       (127) 
                                                / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < (
                                                                                                (-128) 
                                                                                                         / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < (
                                                                                                                                                         (-128) 
                                                                                                                                                                  / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (
                                                                                                                                                                                                                                 (127) 
                                                                                                                                                                                                                                          / si1)))) ?
    ((si1)) :
    si1 * si2;
}
static int8_t
(safe_mod_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return
    ((si2 == 0) || ((si1 == 
                           (-128)
                                   ) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 % si2);
}
static int8_t
(safe_div_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return
    ((si2 == 0) || ((si1 == 
                           (-128)
                                   ) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 / si2);
}
static int8_t
(safe_lshift_func_int8_t_s_s)(int8_t left, int right )
{

  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > (
                                                                         (127) 
                                                                                  >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static int8_t
(safe_lshift_func_int8_t_s_u)(int8_t left, unsigned int right )
{

  return
    ((left < 0) || (((unsigned int)right) >= 32) || (left > (
                                                            (127) 
                                                                     >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static int8_t
(safe_rshift_func_int8_t_s_s)(int8_t left, int right )
{

  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))?
    ((left)) :
    (left >> ((int)right));
}
static int8_t
(safe_rshift_func_int8_t_s_u)(int8_t left, unsigned int right )
{

  return
    ((left < 0) || (((unsigned int)right) >= 32)) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static int16_t
(safe_unary_minus_func_int16_t_s)(int16_t si )
{

  return
    (si==
        (-32767-1)
                 ) ?
    ((si)) :
    -si;
}
static int16_t
(safe_add_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return
    (((si1>0) && (si2>0) && (si1 > (
                                   (32767)
                                            -si2))) || ((si1<0) && (si2<0) && (si1 < (
                                                                                      (-32767-1)
                                                                                               -si2)))) ?
    ((si1)) :
    (si1 + si2);
}
static int16_t
(safe_sub_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return
    (((si1^si2) & (((si1 ^ ((si1^si2) & (~
                                         (32767)
                                                  )))-si2)^si2)) < 0) ?
    ((si1)) :
    (si1 - si2);
}
static int16_t
(safe_mul_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return
    (((si1 > 0) && (si2 > 0) && (si1 > (
                                       (32767) 
                                                 / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < (
                                                                                                 (-32767-1) 
                                                                                                           / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < (
                                                                                                                                                           (-32767-1) 
                                                                                                                                                                     / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (
                                                                                                                                                                                                                                    (32767) 
                                                                                                                                                                                                                                              / si1)))) ?
    ((si1)) :
    si1 * si2;
}
static int16_t
(safe_mod_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return
    ((si2 == 0) || ((si1 == 
                           (-32767-1)
                                    ) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 % si2);
}
static int16_t
(safe_div_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return
    ((si2 == 0) || ((si1 == 
                           (-32767-1)
                                    ) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 / si2);
}
static int16_t
(safe_lshift_func_int16_t_s_s)(int16_t left, int right )
{

  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > (
                                                                         (32767) 
                                                                                   >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static int16_t
(safe_lshift_func_int16_t_s_u)(int16_t left, unsigned int right )
{

  return
    ((left < 0) || (((unsigned int)right) >= 32) || (left > (
                                                            (32767) 
                                                                      >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static int16_t
(safe_rshift_func_int16_t_s_s)(int16_t left, int right )
{

  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))?
    ((left)) :
    (left >> ((int)right));
}
static int16_t
(safe_rshift_func_int16_t_s_u)(int16_t left, unsigned int right )
{

  return
    ((left < 0) || (((unsigned int)right) >= 32)) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static int32_t
(safe_unary_minus_func_int32_t_s)(int32_t si )
{

  return
    (si==
        (-2147483647-1)
                 ) ?
    ((si)) :
    -si;
}
static int32_t
(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return
    (((si1>0) && (si2>0) && (si1 > (
                                   (2147483647)
                                            -si2))) || ((si1<0) && (si2<0) && (si1 < (
                                                                                      (-2147483647-1)
                                                                                               -si2)))) ?
    ((si1)) :
    (si1 + si2);
}
static int32_t
(safe_sub_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return
    (((si1^si2) & (((si1 ^ ((si1^si2) & (~
                                         (2147483647)
                                                  )))-si2)^si2)) < 0) ?
    ((si1)) :
    (si1 - si2);
}
static int32_t
(safe_mul_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return
    (((si1 > 0) && (si2 > 0) && (si1 > (
                                       (2147483647) 
                                                 / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < (
                                                                                                 (-2147483647-1) 
                                                                                                           / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < (
                                                                                                                                                           (-2147483647-1) 
                                                                                                                                                                     / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (
                                                                                                                                                                                                                                    (2147483647) 
                                                                                                                                                                                                                                              / si1)))) ?
    ((si1)) :
    si1 * si2;
}
static int32_t
(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return
    ((si2 == 0) || ((si1 == 
                           (-2147483647-1)
                                    ) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 % si2);
}
static int32_t
(safe_div_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return
    ((si2 == 0) || ((si1 == 
                           (-2147483647-1)
                                    ) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 / si2);
}
static int32_t
(safe_lshift_func_int32_t_s_s)(int32_t left, int right )
{

  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > (
                                                                         (2147483647) 
                                                                                   >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static int32_t
(safe_lshift_func_int32_t_s_u)(int32_t left, unsigned int right )
{

  return
    ((left < 0) || (((unsigned int)right) >= 32) || (left > (
                                                            (2147483647) 
                                                                      >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static int32_t
(safe_rshift_func_int32_t_s_s)(int32_t left, int right )
{

  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))?
    ((left)) :
    (left >> ((int)right));
}
static int32_t
(safe_rshift_func_int32_t_s_u)(int32_t left, unsigned int right )
{

  return
    ((left < 0) || (((unsigned int)right) >= 32)) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static int64_t
(safe_unary_minus_func_int64_t_s)(int64_t si )
{

  return
    (si==
        (-9223372036854775807LL -1)
                 ) ?
    ((si)) :
    -si;
}
static int64_t
(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return
    (((si1>0) && (si2>0) && (si1 > (
                                   (9223372036854775807LL)
                                            -si2))) || ((si1<0) && (si2<0) && (si1 < (
                                                                                      (-9223372036854775807LL -1)
                                                                                               -si2)))) ?
    ((si1)) :
    (si1 + si2);
}
static int64_t
(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return
    (((si1^si2) & (((si1 ^ ((si1^si2) & (~
                                         (9223372036854775807LL)
                                                  )))-si2)^si2)) < 0) ?
    ((si1)) :
    (si1 - si2);
}
static int64_t
(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return
    (((si1 > 0) && (si2 > 0) && (si1 > (
                                       (9223372036854775807LL) 
                                                 / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < (
                                                                                                 (-9223372036854775807LL -1) 
                                                                                                           / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < (
                                                                                                                                                           (-9223372036854775807LL -1) 
                                                                                                                                                                     / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (
                                                                                                                                                                                                                                    (9223372036854775807LL) 
                                                                                                                                                                                                                                              / si1)))) ?
    ((si1)) :
    si1 * si2;
}
static int64_t
(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return
    ((si2 == 0) || ((si1 == 
                           (-9223372036854775807LL -1)
                                    ) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 % si2);
}
static int64_t
(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return
    ((si2 == 0) || ((si1 == 
                           (-9223372036854775807LL -1)
                                    ) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 / si2);
}
static int64_t
(safe_lshift_func_int64_t_s_s)(int64_t left, int right )
{

  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > (
                                                                         (9223372036854775807LL) 
                                                                                   >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static int64_t
(safe_lshift_func_int64_t_s_u)(int64_t left, unsigned int right )
{

  return
    ((left < 0) || (((unsigned int)right) >= 32) || (left > (
                                                            (9223372036854775807LL) 
                                                                      >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static int64_t
(safe_rshift_func_int64_t_s_s)(int64_t left, int right )
{

  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))?
    ((left)) :
    (left >> ((int)right));
}
static int64_t
(safe_rshift_func_int64_t_s_u)(int64_t left, unsigned int right )
{

  return
    ((left < 0) || (((unsigned int)right) >= 32)) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static uint8_t
(safe_unary_minus_func_uint8_t_u)(uint8_t ui )
{

  return -ui;
}
static uint8_t
(safe_add_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{

  return ui1 + ui2;
}
static uint8_t
(safe_sub_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{

  return ui1 - ui2;
}
static uint8_t
(safe_mul_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{

  return ((unsigned int)ui1) * ((unsigned int)ui2);
}
static uint8_t
(safe_mod_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{

  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 % ui2);
}
static uint8_t
(safe_div_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{

  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 / ui2);
}
static uint8_t
(safe_lshift_func_uint8_t_u_s)(uint8_t left, int right )
{

  return
    ((((int)right) < 0) || (((int)right) >= 32) || (left > (
                                                           (255) 
                                                                     >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static uint8_t
(safe_lshift_func_uint8_t_u_u)(uint8_t left, unsigned int right )
{

  return
    ((((unsigned int)right) >= 32) || (left > (
                                              (255) 
                                                        >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static uint8_t
(safe_rshift_func_uint8_t_u_s)(uint8_t left, int right )
{

  return
    ((((int)right) < 0) || (((int)right) >= 32)) ?
    ((left)) :
    (left >> ((int)right));
}
static uint8_t
(safe_rshift_func_uint8_t_u_u)(uint8_t left, unsigned int right )
{

  return
    (((unsigned int)right) >= 32) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static uint16_t
(safe_unary_minus_func_uint16_t_u)(uint16_t ui )
{

  return -ui;
}
static uint16_t
(safe_add_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{

  return ui1 + ui2;
}
static uint16_t
(safe_sub_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{

  return ui1 - ui2;
}
static uint16_t
(safe_mul_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{

  return ((unsigned int)ui1) * ((unsigned int)ui2);
}
static uint16_t
(safe_mod_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{

  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 % ui2);
}
static uint16_t
(safe_div_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{

  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 / ui2);
}
static uint16_t
(safe_lshift_func_uint16_t_u_s)(uint16_t left, int right )
{

  return
    ((((int)right) < 0) || (((int)right) >= 32) || (left > (
                                                           (65535) 
                                                                      >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static uint16_t
(safe_lshift_func_uint16_t_u_u)(uint16_t left, unsigned int right )
{

  return
    ((((unsigned int)right) >= 32) || (left > (
                                              (65535) 
                                                         >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static uint16_t
(safe_rshift_func_uint16_t_u_s)(uint16_t left, int right )
{

  return
    ((((int)right) < 0) || (((int)right) >= 32)) ?
    ((left)) :
    (left >> ((int)right));
}
static uint16_t
(safe_rshift_func_uint16_t_u_u)(uint16_t left, unsigned int right )
{

  return
    (((unsigned int)right) >= 32) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static uint32_t
(safe_unary_minus_func_uint32_t_u)(uint32_t ui )
{

  return -ui;
}
static uint32_t
(safe_add_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{

  return ui1 + ui2;
}
static uint32_t
(safe_sub_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{

  return ui1 - ui2;
}
static uint32_t
(safe_mul_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{

  return ((unsigned int)ui1) * ((unsigned int)ui2);
}
static uint32_t
(safe_mod_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{

  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 % ui2);
}
static uint32_t
(safe_div_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{

  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 / ui2);
}
static uint32_t
(safe_lshift_func_uint32_t_u_s)(uint32_t left, int right )
{

  return
    ((((int)right) < 0) || (((int)right) >= 32) || (left > (
                                                           (4294967295U) 
                                                                      >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static uint32_t
(safe_lshift_func_uint32_t_u_u)(uint32_t left, unsigned int right )
{

  return
    ((((unsigned int)right) >= 32) || (left > (
                                              (4294967295U) 
                                                         >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static uint32_t
(safe_rshift_func_uint32_t_u_s)(uint32_t left, int right )
{

  return
    ((((int)right) < 0) || (((int)right) >= 32)) ?
    ((left)) :
    (left >> ((int)right));
}
static uint32_t
(safe_rshift_func_uint32_t_u_u)(uint32_t left, unsigned int right )
{

  return
    (((unsigned int)right) >= 32) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static uint64_t
(safe_unary_minus_func_uint64_t_u)(uint64_t ui )
{

  return -ui;
}
static uint64_t
(safe_add_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{

  return ui1 + ui2;
}
static uint64_t
(safe_sub_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{

  return ui1 - ui2;
}
static uint64_t
(safe_mul_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{

  return ((unsigned long long)ui1) * ((unsigned long long)ui2);
}
static uint64_t
(safe_mod_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{

  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 % ui2);
}
static uint64_t
(safe_div_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{

  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 / ui2);
}
static uint64_t
(safe_lshift_func_uint64_t_u_s)(uint64_t left, int right )
{

  return
    ((((int)right) < 0) || (((int)right) >= 32) || (left > (
                                                           (18446744073709551615ULL) 
                                                                      >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static uint64_t
(safe_lshift_func_uint64_t_u_u)(uint64_t left, unsigned int right )
{

  return
    ((((unsigned int)right) >= 32) || (left > (
                                              (18446744073709551615ULL) 
                                                         >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static uint64_t
(safe_rshift_func_uint64_t_u_s)(uint64_t left, int right )
{

  return
    ((((int)right) < 0) || (((int)right) >= 32)) ?
    ((left)) :
    (left >> ((int)right));
}
static uint64_t
(safe_rshift_func_uint64_t_u_u)(uint64_t left, unsigned int right )
{

  return
    (((unsigned int)right) >= 32) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static float
(safe_add_func_float_f_f)(float sf1, float sf2 )
{

  return
    (fabsf((0.5f * sf1) + (0.5f * sf2)) > (0.5f * 3.40282346638528859812e+38F)) ?
    (sf1) :
    (sf1 + sf2);
}
static float
(safe_sub_func_float_f_f)(float sf1, float sf2 )
{

  return
    (fabsf((0.5f * sf1) - (0.5f * sf2)) > (0.5f * 3.40282346638528859812e+38F)) ?
    (sf1) :
    (sf1 - sf2);
}
static float
(safe_mul_func_float_f_f)(float sf1, float sf2 )
{

  return
    (fabsf((0x1.0p-100f * sf1) * (0x1.0p-28f * sf2)) > (0x1.0p-100f * (0x1.0p-28f * 3.40282346638528859812e+38F))) ?
    (sf1) :
    (sf1 * sf2);
}
static float
(safe_div_func_float_f_f)(float sf1, float sf2 )
{

  return
    ((fabsf(sf2) < 1.0f) && (((sf2 == 0.0f) || (fabsf((0x1.0p-49f * sf1) / (0x1.0p100f * sf2))) > (0x1.0p-100f * (0x1.0p-49f * 3.40282346638528859812e+38F))))) ?
    (sf1) :
    (sf1 / sf2);
}
static double
(safe_add_func_double_f_f)(double sf1, double sf2 )
{

  return
    (fabs((0.5 * sf1) + (0.5 * sf2)) > (0.5 * ((double)1.79769313486231570815e+308L))) ?
    (sf1) :
    (sf1 + sf2);
}
static double
(safe_sub_func_double_f_f)(double sf1, double sf2 )
{

  return
    (fabs((0.5 * sf1) - (0.5 * sf2)) > (0.5 * ((double)1.79769313486231570815e+308L))) ?
    (sf1) :
    (sf1 - sf2);
}
static double
(safe_mul_func_double_f_f)(double sf1, double sf2 )
{

  return
    (fabs((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) > (0x1.0p-100 * (0x1.0p-924 * ((double)1.79769313486231570815e+308L)))) ?
    (sf1) :
    (sf1 * sf2);
}
static double
(safe_div_func_double_f_f)(double sf1, double sf2 )
{

  return
    ((fabs(sf2) < 1.0) && (((sf2 == 0.0) || (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) > (0x1.0p-100 * (0x1.0p-974 * ((double)1.79769313486231570815e+308L)))))) ?
    (sf1) :
    (sf1 / sf2);
}
static int32_t
(safe_convert_func_float_to_int32_t)(float sf1 )
{

  return
    ((sf1 <= 
            (-2147483647-1)
                     ) || (sf1 >= 
                                  (2147483647)
                                           )) ?
    (
    (2147483647)
             ) :
    ((int32_t)(sf1));
}
static uint32_t crc32_tab[256];
static uint32_t crc32_context = 0xFFFFFFFFUL;
static void
crc32_gentab (void)
{
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
static void
crc32_byte (uint8_t b) {
 crc32_context =
  ((crc32_context >> 8) & 0x00FFFFFF) ^
  crc32_tab[(crc32_context ^ b) & 0xFF];
}
static void
crc32_8bytes (uint64_t val)
{
 crc32_byte ((val>>0) & 0xff);
 crc32_byte ((val>>8) & 0xff);
 crc32_byte ((val>>16) & 0xff);
 crc32_byte ((val>>24) & 0xff);
 crc32_byte ((val>>32) & 0xff);
 crc32_byte ((val>>40) & 0xff);
 crc32_byte ((val>>48) & 0xff);
 crc32_byte ((val>>56) & 0xff);
}
static void
transparent_crc (uint64_t val, char* vname, int flag)
{
 crc32_8bytes(val);
 if (flag) {
    printf("...checksum after hashing %s : %lX\n", vname, crc32_context ^ 0xFFFFFFFFUL);
 }
}
static void
transparent_crc_bytes (char *ptr, int nbytes, char* vname, int flag)
{
    int i;
    for (i=0; i<nbytes; i++) {
        crc32_byte(ptr[i]);
    }
 if (flag) {
    printf("...checksum after hashing %s : %lX\n", vname, crc32_context ^ 0xFFFFFFFFUL);
 }
}
static long __undefined;
static volatile int32_t g_3 = 0x13DCE9D0L;
static uint16_t g_35 = 65531UL;
static int32_t g_139 = 5L;
static uint16_t g_141 = 0x3552L;
static uint8_t g_151 = 1UL;
static int32_t g_189 = (-1L);
static int16_t g_202 = 6L;
static uint32_t g_203 = 0xD1308C90L;
static uint32_t g_206 = 1UL;
static uint32_t g_244 = 0x933B74F7L;
static uint8_t g_252[4][7] = {{0xFDL, 0xE0L, 0xFDL, 0xE0L, 0xFDL, 0xE0L, 0xFDL}, {0xFDL, 0xE0L, 0xFDL, 0xE0L, 0xFDL, 0xE0L, 0xFDL}, {0xFDL, 0xE0L, 0xFDL, 0xE0L, 0xFDL, 0xE0L, 0xFDL}, {0xFDL, 0xE0L, 0xFDL, 0xE0L, 0xFDL, 0xE0L, 0xFDL}};
static volatile uint32_t g_316 = 0x43CCBAE7L;
static int8_t g_317 = 3L;
static uint8_t g_321[4][3][9] = {{{1UL, 0UL, 251UL, 0x5CL, 255UL, 0x3BL, 0xB6L, 0xF3L, 251UL}, {1UL, 0UL, 251UL, 0x5CL, 255UL, 0x3BL, 0xB6L, 0xF3L, 251UL}, {1UL, 0UL, 251UL, 0x5CL, 255UL, 0x3BL, 0xB6L, 0xF3L, 251UL}}, {{1UL, 0UL, 251UL, 0x5CL, 255UL, 0x3BL, 0xB6L, 0xF3L, 251UL}, {1UL, 0UL, 251UL, 0x5CL, 255UL, 0x3BL, 0xB6L, 0xF3L, 251UL}, {1UL, 0UL, 251UL, 0x5CL, 255UL, 0x3BL, 0xB6L, 0xF3L, 251UL}}, {{1UL, 0UL, 251UL, 0x5CL, 255UL, 0x3BL, 0xB6L, 0xF3L, 251UL}, {1UL, 0UL, 251UL, 0x5CL, 255UL, 0x3BL, 0xB6L, 0xF3L, 251UL}, {1UL, 0UL, 251UL, 0x5CL, 255UL, 0x3BL, 0xB6L, 0xF3L, 251UL}}, {{1UL, 0UL, 251UL, 0x5CL, 255UL, 0x3BL, 0xB6L, 0xF3L, 251UL}, {1UL, 0UL, 251UL, 0x5CL, 255UL, 0x3BL, 0xB6L, 0xF3L, 251UL}, {1UL, 0UL, 251UL, 0x5CL, 255UL, 0x3BL, 0xB6L, 0xF3L, 251UL}}};
static uint16_t g_326[8] = {65535UL, 65535UL, 65535UL, 65535UL, 65535UL, 65535UL, 65535UL, 65535UL};
static int32_t g_327[4][1] = {{1L}, {1L}, {1L}, {1L}};
static volatile int32_t g_328 = 0x1421FC0DL;
static int8_t g_332 = 0L;
static int32_t g_347 = 0x8D22E013L;
static int32_t g_348 = 0xA0EF96F8L;
static volatile uint32_t g_349 = 0UL;
static volatile int32_t g_352 = 8L;
static volatile uint8_t g_353 = 0x6BL;
static int32_t g_370[6] = {4L, 1L, 4L, 1L, 4L, 1L};
static uint8_t g_371 = 2UL;
static uint8_t g_407 = 0UL;
static int16_t g_408 = (-1L);
static uint16_t g_511 = 1UL;
static volatile int32_t g_539[9] = {(-1L), (-1L), 0x5235FB33L, (-1L), (-1L), 0x5235FB33L, (-1L), (-1L), 0x5235FB33L};
static uint8_t g_595[10] = {0x39L, 254UL, 0x39L, 254UL, 0x39L, 254UL, 0x39L, 254UL, 0x39L, 254UL};
static int32_t g_630 = 0xA10FEBB5L;
static uint8_t g_769 = 0UL;
static int32_t g_770 = 0xE0649A8FL;
static uint8_t g_973 = 4UL;
static int8_t g_1271 = 0x3CL;
static int32_t g_1297 = 0x3F0C073AL;
static int8_t g_1374 = 6L;
static volatile int8_t g_1442 = 0x18L;
static int16_t g_1985[10] = {0x3CB9L, 0xA021L, 7L, 7L, 0xA021L, 0x3CB9L, 0xA021L, 7L, 7L, 0xA021L};
static uint32_t g_2037 = 0x7883140CL;
static int32_t g_2205 = (-6L);
static int16_t g_2281[8][4] = {{0x8B20L, (-1L), 0x8B20L, (-1L)}, {0x8B20L, (-1L), 0x8B20L, (-1L)}, {0x8B20L, (-1L), 0x8B20L, (-1L)}, {0x8B20L, (-1L), 0x8B20L, (-1L)}, {0x8B20L, (-1L), 0x8B20L, (-1L)}, {0x8B20L, (-1L), 0x8B20L, (-1L)}, {0x8B20L, (-1L), 0x8B20L, (-1L)}, {0x8B20L, (-1L), 0x8B20L, (-1L)}};
static uint32_t g_2414 = 0xD114DFA1L;
static uint32_t g_2447 = 0x8E66C732L;
static volatile int8_t g_2888 = 5L;
static uint8_t g_2935[3] = {0xB4L, 0xB4L, 0xB4L};
static volatile int16_t g_2940[9][7] = {{0x081BL, 4L, (-8L), 4L, 0x081BL, 1L, 0x904CL}, {0x081BL, 4L, (-8L), 4L, 0x081BL, 1L, 0x904CL}, {0x081BL, 4L, (-8L), 4L, 0x081BL, 1L, 0x904CL}, {0x081BL, 4L, (-8L), 4L, 0x081BL, 1L, 0x904CL}, {0x081BL, 4L, (-8L), 4L, 0x081BL, 1L, 0x904CL}, {0x081BL, 4L, (-8L), 4L, 0x081BL, 1L, 0x904CL}, {0x081BL, 4L, (-8L), 4L, 0x081BL, 1L, 0x904CL}, {0x081BL, 4L, (-8L), 4L, 0x081BL, 1L, 0x904CL}, {0x081BL, 4L, (-8L), 4L, 0x081BL, 1L, 0x904CL}};
static volatile uint32_t g_3311 = 0x0B6075C1L;
static volatile int8_t g_3612[1] = {(-6L)};
static int32_t g_3804 = 0x8638B8DEL;
static uint8_t g_3890 = 0xE6L;
static int32_t g_3893 = 0xFD4A8983L;
inline static uint16_t func_1(void);
inline static uint32_t func_4(uint32_t p_5, int16_t p_6);
inline static uint16_t func_7(uint16_t p_8, int32_t p_9, int32_t p_10, uint32_t p_11);
inline static int8_t func_15(int32_t p_16, uint16_t p_17, uint8_t p_18);
static int32_t func_19(int8_t p_20, int32_t p_21, int32_t p_22);
inline static int8_t func_25(uint8_t p_26, uint16_t p_27, int32_t p_28);
static int32_t func_42(uint8_t p_43);
inline static uint8_t func_44(int32_t p_45, int32_t p_46);
inline static uint16_t func_77(int16_t p_78);
inline static uint8_t func_94(uint32_t p_95, uint32_t p_96);
inline static uint16_t func_1(void)
{
    int32_t l_14[6];
    int32_t l_41 = 0xE67E784BL;
    int32_t l_3891 = 0x39CE0225L;
    int8_t l_4549[2];
    int32_t l_4550[4][3];
    uint16_t l_4551 = 0x6522L;
    int i, j;
    for (i = 0; i < 6; i++)
        l_14[i] = 7L;
    for (i = 0; i < 2; i++)
        l_4549[i] = 0xBAL;
                      if (( g_189 < -1) )
{
if (g_2205) printf("index = [%d]\n", i);
}
for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
            l_4550[i][j] = 1L;
    }
    l_4549[1] = (+(g_3 || func_4((((g_3893 ^= (0xA66EL == func_7((l_3891 = (safe_mul_func_uint16_t_u_u(l_14[1], (func_15(func_19((safe_sub_func_int8_t_s_s(func_25(((0x23L || (safe_add_func_int32_t_s_s(((((safe_rshift_func_int8_t_s_s(((safe_mul_func_uint8_t_u_u(((g_3 & (g_35 == (!g_35))) == (safe_mul_func_int16_t_s_s(g_35, (safe_rshift_func_int8_t_s_s(g_35, l_14[1]))))), (-10L))) || 2L), 2)) < 0UL) < g_35) && l_14[0]), l_41))) != 0x60L), l_14[1], g_35), 0xECL)), g_630, g_630), g_630, l_41) == 1L)))), l_14[1], l_41, l_14[1]))) != 255UL) ^ g_630), l_41)));
    ++l_4551;
    return l_4551;
}
inline static uint32_t func_4(uint32_t p_5, int16_t p_6)
{
    uint32_t l_3894 = 0x8043B386L;
    uint16_t l_3920[8] = {0x9FAEL, 0x62DFL, 0x9FAEL, 0x62DFL, 0x9FAEL, 0x62DFL, 0x9FAEL, 0x62DFL};
    int32_t l_3923 = 0L;
    int32_t l_3924[10][6][4] = {{{(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}}, {{(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}}, {{(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}}, {{(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}}, {{(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}}, {{(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}}, {{(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}}, {{(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}}, {{(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}}, {{(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}, {(-9L), 0xD2CCAB8EL, 0x63459374L, (-1L)}}};
    int32_t l_3925 = 0xCE7E93BFL;
    uint32_t l_3987[2][8][6] = {{{4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}}, {{4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}, {4294967295UL, 0x3AB65B82L, 0xA7A02942L, 0x855DCEB6L, 0xA7A02942L, 0x3AB65B82L}}};
    int32_t l_3991 = 7L;
    int8_t l_4078 = 0x8EL;
    uint32_t l_4168 = 0xE9307A3EL;
    int16_t l_4269[10][6][4] = {{{1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}}, {{1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}}, {{1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}}, {{1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}}, {{1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}}, {{1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}}, {{1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}}, {{1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}}, {{1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}}, {{1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}, {1L, 6L, (-8L), 1L}}};
    uint32_t l_4415 = 0xFAAA08D4L;
    uint16_t l_4494[5];
    uint32_t l_4502 = 4UL;
    int32_t l_4530 = 0xBCEBC347L;
    int16_t l_4546 = (-1L);
    int8_t l_4548 = (-1L);
    int i, j, k;
    for (i = 0; i < 5; i++)
        {
if (g_1271)
                break;
l_4494[i] = 0UL;}
{
                        return g_202;
                    }
if ((l_3894 &= 1L))
    {
        uint32_t l_3907[8] = {2UL, 2UL, 0x512B63C5L, 2UL, 2UL, 0x512B63C5L, 2UL, 2UL};
        int32_t l_3914 = 0x24024D2CL;
        int8_t l_3921 = (-8L);
        int8_t l_3922 = 0x46L;
        uint32_t l_3948 = 0x4593117EL;
        int32_t l_4101 = 0xF70B5938L;
        int32_t l_4102 = 0x712B81C2L;
        int16_t l_4141 = 0x89F2L;
        uint8_t l_4157 = 0x1CL;
        uint32_t l_4231 = 0x7EE282B4L;
        uint32_t l_4302 = 9UL;
        int i;
        if ((l_3925 = ((safe_rshift_func_uint16_t_u_s(((safe_add_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((safe_mul_func_uint8_t_u_u(((((safe_mod_func_uint8_t_u_u(g_2414, l_3907[1])) < ((l_3924[5][1][0] = (safe_sub_func_uint32_t_u_u((((1UL >= ((p_5 | (l_3923 ^= (safe_rshift_func_int8_t_s_s((((safe_rshift_func_int16_t_s_s((l_3914 = 0L), 15)) < 0UL) && (safe_mod_func_uint8_t_u_u((((-1L) >= (((((-1L) < (+(safe_mod_func_uint16_t_u_u(l_3920[5], g_3311)))) < p_6) > 0xA8L) > l_3914)) != l_3921), l_3922))), l_3907[3])))) == l_3907[1])) <= l_3907[6]) & l_3894), g_2205))) || g_3890)) < 1UL) <= p_5), l_3921)), l_3894)), p_6)) && l_3921), l_3920[5])) & g_1297), 1)) & l_3920[5])))
        {
            uint32_t l_3943 = 18446744073709551612UL;
            int32_t l_3946 = 0L;
            int32_t l_3947 = (-5L);
            l_3948 = ((((safe_sub_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s((((safe_mul_func_uint8_t_u_u(g_370[1], ((l_3923 = ((safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_u(g_2447, 6)), 0)) != g_370[1])) > (!g_371)))) | (safe_rshift_func_uint16_t_u_u(((4294967292UL & ((p_5 && ((0xC2L == (safe_sub_func_int32_t_s_s(g_1985[5], (l_3946 ^= ((l_3943++) == ((g_244 = p_6) || g_2940[3][3])))))) && 0x87L)) & l_3907[1])) <= l_3924[2][3][2]), 7))) != l_3947), 247UL)), g_347)), 0x76L)) != 0x29L) != p_5) || l_3924[1][0][1]);
            for (g_769 = 0; (g_769 != 8); ++g_769)
            {
                int32_t l_3953 = 0x9E485A6FL;
g_3890 += 1;
l_3924[5][1][0] = (g_1297 &= (safe_mul_func_int8_t_s_s(p_6, (g_252[1][3] &= g_3890))));
                return l_3953;
            }
            if ((safe_mul_func_uint8_t_u_u((l_3925 = ((0x14L < (g_244 || (safe_add_func_uint32_t_u_u((2UL <= (safe_mod_func_uint32_t_u_u((l_3924[5][1][0] >= (safe_mul_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((((((safe_mul_func_int8_t_s_s(l_3924[5][1][0], (safe_mul_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(((l_3947 = (((((g_3311 | g_139) >= (l_3948 >= g_189)) | 1UL) <= 0xD6L) == 0x3DL)) & 8UL), p_5)), l_3921)))) <= 0xE935C2ABL) | g_770) > l_3920[5]) & 0xD420L), 3)), p_5))), p_6))), g_332)))) || g_252[2][6])), p_5)))
            {
                l_3914 = g_1985[7];
            }
            else
            {
                int32_t l_3982[1][6][9] = {{{1L, 1L, 0xE5D380EAL, 1L, 1L, 0xE5D380EAL, 1L, 1L, 0xE5D380EAL}, {1L, 1L, 0xE5D380EAL, 1L, 1L, 0xE5D380EAL, 1L, 1L, 0xE5D380EAL}, {1L, 1L, 0xE5D380EAL, 1L, 1L, 0xE5D380EAL, 1L, 1L, 0xE5D380EAL}, {1L, 1L, 0xE5D380EAL, 1L, 1L, 0xE5D380EAL, 1L, 1L, 0xE5D380EAL}, {1L, 1L, 0xE5D380EAL, 1L, 1L, 0xE5D380EAL, 1L, 1L, 0xE5D380EAL}, {1L, 1L, 0xE5D380EAL, 1L, 1L, 0xE5D380EAL, 1L, 1L, 0xE5D380EAL}}};
                int32_t l_4014 = 0x9BA6BFD0L;
                uint32_t l_4050[7][6] = {{0xA6118FB4L, 0UL, 0xA6118FB4L, 0x00CDB327L, 4UL, 0UL}, {0xA6118FB4L, 0UL, 0xA6118FB4L, 0x00CDB327L, 4UL, 0UL}, {0xA6118FB4L, 0UL, 0xA6118FB4L, 0x00CDB327L, 4UL, 0UL}, {0xA6118FB4L, 0UL, 0xA6118FB4L, 0x00CDB327L, 4UL, 0UL}, {0xA6118FB4L, 0UL, 0xA6118FB4L, 0x00CDB327L, 4UL, 0UL}, {0xA6118FB4L, 0UL, 0xA6118FB4L, 0x00CDB327L, 4UL, 0UL}, {0xA6118FB4L, 0UL, 0xA6118FB4L, 0x00CDB327L, 4UL, 0UL}};
                int i, j, k;
                if ((g_252[2][6] != ((safe_rshift_func_int16_t_s_u(l_3922, 9)) | (g_326[7]++))))
                {
                    uint16_t l_3981 = 1UL;
                    for (g_139 = 7; (g_139 == 7); ++g_139)
                    {
                        int32_t l_3976 = 0xBD61E716L;
                        uint32_t l_3992[9][1] = {{0xD99FDE87L}, {0xD99FDE87L}, {0xD99FDE87L}, {0xD99FDE87L}, {0xD99FDE87L}, {0xD99FDE87L}, {0xD99FDE87L}, {0xD99FDE87L}, {0xD99FDE87L}};
                        int32_t l_3993 = 1L;
                        int i, j;
                        l_3993 = (((0xCF25L > (l_3976 & ((safe_lshift_func_uint8_t_u_s((((safe_rshift_func_int16_t_s_s((l_3981 != l_3982[0][5][4]), (((safe_mod_func_uint16_t_u_u(((p_5 && ((safe_mod_func_uint8_t_u_u(l_3987[1][7][2], g_347)) ^ ((((l_3914 = ((safe_mul_func_int16_t_s_s((255UL && (safe_unary_minus_func_int8_t_s(((((((l_3991 < l_3921) >= p_5) || p_6) | 0xE613D668L) > 0x87E2D3FCL) != g_973)))), p_6)) < 0xED790C66L)) & 1UL) > p_5) >= 0xA974F596L))) > l_3894), 0x105EL)) >= g_407) > l_3943))) & l_3982[0][5][4]) < (-1L)), 6)) ^ p_6))) && l_3992[8][0]) < g_332);
                        l_4014 ^= (safe_lshift_func_uint16_t_u_s(((l_3914 = (g_3893 |= ((l_3924[0][3][0] = (safe_add_func_int32_t_s_s(p_5, ((safe_lshift_func_uint16_t_u_u(65528UL, 8)) == (safe_mod_func_int8_t_s_s((safe_mul_func_int16_t_s_s((0xA8L > g_539[4]), (safe_add_func_uint16_t_u_u(0x884CL, (l_3981 < 0x9974145FL))))), (safe_sub_func_int8_t_s_s((0xFEL && (safe_mod_func_int32_t_s_s(((safe_lshift_func_uint8_t_u_s((((safe_mul_func_int8_t_s_s((g_1271 = p_5), 255UL)) | l_3907[0]) || 0x3FL), 3)) < (-1L)), l_3982[0][0][8]))), 2UL)))))))) > p_5))) <= p_5), 14));
                    }
                    for (g_244 = 0; (g_244 < 15); g_244 = safe_add_func_uint32_t_u_u(g_244, 3))
                    {
                        return p_6;
                    }
                    for (l_3921 = 0; (l_3921 == 14); ++l_3921)
                    {
                        uint8_t l_4021[1];
                        int32_t l_4022 = 0x876466C1L;
                        int i;
                        for (i = 0; i < 1; i++)
                            l_4021[i] = 0UL;
                        l_4022 = (safe_add_func_int32_t_s_s(g_2281[6][2], l_4021[0]));
                        if (l_3987[1][4][1])
                            continue;
                    }
                    g_2205 = (((((safe_rshift_func_int8_t_s_s((safe_add_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(((safe_sub_func_int32_t_s_s(((safe_sub_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u((g_595[0] & ((0xC4L | (65535UL <= (safe_unary_minus_func_uint16_t_u(g_151)))) != (p_6 || (safe_rshift_func_uint16_t_u_s(((safe_mod_func_int32_t_s_s((safe_lshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_u(0x26L, (safe_rshift_func_uint8_t_u_s((safe_rshift_func_int8_t_s_s((-1L), 7)), 2)))), 5)), (safe_mul_func_uint16_t_u_u((0x8074D2BCL == (1L < p_5)), p_5)))) >= p_6), g_244))))), p_5)) >= g_328), p_5)) | l_3921), g_1985[5])) >= l_3982[0][5][4]), 7)), g_3804)), 4)) != g_35) < 0xB5D1AEF0L) <= g_1985[6]) ^ l_4050[4][3]);
                }
                else
                {
                    for (l_3991 = 0; (l_3991 != 16); l_3991 = safe_add_func_uint16_t_u_u(l_3991, 9))
                    {
                        int32_t l_4065 = 2L;
                        g_139 = ((safe_rshift_func_uint8_t_u_u(((p_6 >= (((safe_rshift_func_int16_t_s_u(((g_202 != (~l_3948)) >= g_252[2][6]), 15)) && (((l_3914 >= (0x3AL == g_328)) == (safe_mod_func_int32_t_s_s(((!(((safe_add_func_uint16_t_u_u(p_5, ((safe_sub_func_uint8_t_u_u(255UL, 0xA8L)) > l_3924[6][4][0]))) < l_3946) <= l_3943)) && (-1L)), 8UL))) || 0x87B2L)) || l_4065)) < p_6), g_1985[3])) >= p_6);
                    }
                    for (g_371 = 0; (g_371 <= 1); g_371 += 1)
                    {
                        int32_t l_4079 = 0L;
                        int i;
                        l_4079 &= (((0x3E6CDD8DL > (g_539[(g_371 + 2)] < ((0x6AB15F32L < ((-1L) > g_327[3][0])) < (((safe_lshift_func_uint8_t_u_s((safe_sub_func_int8_t_s_s(((0x7DD81061L || p_5) && g_189), (safe_lshift_func_int16_t_s_s(((((safe_rshift_func_int8_t_s_u(((safe_mod_func_int16_t_s_s((l_4078 && 0x7DE6L), l_3947)) || 4294967289UL), 5)) <= 1L) | 0xAD6AL) == g_244), p_6)))), l_3946)) == g_2281[2][1]) & 0x91L)))) || p_6) < 0xF5E94645L);
                        if (g_539[(g_371 + 2)])
                            continue;
                        if (g_1271)
                            continue;
                    }
                }
                if ((((safe_lshift_func_int16_t_s_s(g_316, (l_3925 = l_3943))) == (0x0321A37AL > p_6)) ^ ((!(l_4102 = ((safe_mod_func_uint32_t_u_u((safe_mul_func_int16_t_s_s(((0x131DL & 6UL) <= (l_4101 = (safe_mul_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((l_3914 = 0x2EL), 7)), (safe_rshift_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u((g_206 |= (252UL && (g_252[2][6] <= 0UL))), p_6)) == p_6), 13)), 0x10L)) & 0xE833L), 2)))))), 0xE80CL)), p_5)) > p_6))) ^ l_3946)))
                {
                    int16_t l_4118 = 0xB755L;
                    g_1297 &= (g_139 = 0x0EBE0120L);
                    g_139 = (safe_sub_func_uint8_t_u_u((safe_add_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s(l_3922, 65530UL)), 2)) ^ (((65528UL != (safe_lshift_func_uint8_t_u_u(((0x74FA96B1L == (l_3914 > ((g_139 > 0xC930L) | p_5))) == (+((g_2414 = l_3982[0][5][4]) != p_5))), 3))) | g_321[2][1][8]) && 255UL)) || l_4102), l_4050[4][3])), 0xB1L));
                    l_4118 = (safe_rshift_func_uint16_t_u_s(((safe_mod_func_uint32_t_u_u(l_3946, g_326[3])) <= p_5), 10));
                }
                else
                {
                    uint32_t l_4121 = 0x8820E23EL;
                    g_139 = (safe_lshift_func_uint8_t_u_u(((l_4121 || l_3982[0][1][7]) == ((g_511--) == (safe_lshift_func_uint8_t_u_u((g_595[8] ^= (safe_mul_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((p_6 != l_3982[0][4][7]), 14)), p_6)) | (l_3894 | ((((l_4014 &= ((~(g_2935[0] || (safe_mul_func_int8_t_s_s((safe_lshift_func_int8_t_s_u((((-5L) < ((l_3946 = (safe_sub_func_uint8_t_u_u((((l_4141 > p_5) || p_6) < g_1442), 0L))) >= g_317)) >= 0x63L), 6)), 0x16L)))) | 0x2452L)) & g_630) | p_6) && p_5))), 5)), 0UL))), g_141)))), p_5));
                }
            }
        }
        else
        {
            int32_t l_4144 = 0x5F11F42CL;
            uint32_t l_4230 = 0x4E8B98B4L;
            int8_t l_4232 = 0x1CL;
            if ((0xD320L >= p_5))
            {
                uint16_t l_4167 = 0xA9FBL;
                l_3923 = (safe_sub_func_uint16_t_u_u((0xAAL & 0xAFL), l_3924[5][1][0]));
                l_4144 = p_6;
                for (l_3914 = 0; (l_3914 >= 6); ++l_3914)
                {
                    int8_t l_4166[5] = {0x80L, 3L, 0x80L, 3L, 0x80L};
                    int i;
                    g_2205 |= (((safe_sub_func_uint16_t_u_u((safe_sub_func_int16_t_s_s(((safe_sub_func_int8_t_s_s((g_1374 = ((g_2940[3][3] && (((safe_sub_func_int32_t_s_s((0x82L == ((((safe_sub_func_uint32_t_u_u(((g_1271 = l_4157) <= (((safe_lshift_func_uint16_t_u_u((safe_mul_func_int16_t_s_s((p_6 & l_3991), (((0x546AAF20L < ((safe_mod_func_uint16_t_u_u((p_6 | ((safe_mod_func_uint8_t_u_u(249UL, g_139)) || g_539[4])), 65535UL)) >= g_370[4])) == p_6) && (-1L)))), p_6)) > p_5) > 0x8A1C4B04L)), g_1297)) || p_5) >= 0xA0E7FEE3L) < g_3890)), 0xE858B727L)) < p_5) == l_4166[3])) <= l_4166[3])), 6UL)) ^ l_3894), l_3923)), p_6)) && 0x8DL) & l_4167);
                }
            }
            else
            {
                int8_t l_4187 = 0x36L;
                int32_t l_4196 = 0x1EE98595L;
                l_4168 = 0xE5728E95L;
                if (p_6)
                {
                    uint16_t l_4169 = 0UL;
                    return l_4169;
                }
                else
                {
                    uint32_t l_4195 = 0x0BEB066EL;
                    int32_t l_4197 = 2L;
                    g_1297 |= ((--g_511) | ((((safe_mod_func_int16_t_s_s((((!((g_3 ^ g_151) <= ((safe_rshift_func_int8_t_s_u((g_203 > (safe_mod_func_int32_t_s_s((safe_mod_func_int32_t_s_s((l_4197 = (((p_5 >= (l_4196 = ((safe_sub_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_u((safe_sub_func_int32_t_s_s(l_4187, 0UL)), (((((!(safe_mod_func_uint8_t_u_u(((p_6 | ((g_595[9] = 0xBFL) < ((safe_lshift_func_int8_t_s_u(((safe_mul_func_uint16_t_u_u((g_973 || g_3890), l_4157)) > g_326[7]), 5)) != 0xEBL))) == l_4195), p_6))) ^ p_6) && g_2447) ^ l_4195) == 0xA614L))) == p_6), p_5)) ^ 0x1DL))) | 6UL) < 0x99L)), p_6)), g_203))), 6)) || g_244))) <= g_332) > 0UL), p_5)) != g_2935[2]) && 4L) != g_1271));
g_630 |= g_203;
return g_539[3];
                }
            }
            if ((safe_add_func_uint8_t_u_u((g_244 > ((safe_mod_func_int8_t_s_s((g_1374 = (safe_add_func_int8_t_s_s(((safe_mod_func_uint32_t_u_u((g_1297 & (((((safe_add_func_uint32_t_u_u(p_5, (((safe_mul_func_uint16_t_u_u(g_151, (p_6 = (((g_371 ^= (g_1985[5] < (~(((safe_rshift_func_int8_t_s_u((g_2940[3][3] >= (((safe_rshift_func_int8_t_s_u((((safe_add_func_int8_t_s_s((g_2281[3][2] > l_3987[1][1][2]), ((((0xE0L || 0xF7L) >= g_370[4]) >= 1L) | 253UL))) && (-9L)) != l_4144), p_5)) || 0xA918884BL) <= p_6)), 6)) <= g_252[1][2]) <= 4294967295UL)))) == l_4144) < p_5)))) > 0x5FD3L) && l_3922))) != g_348) == g_332) | p_5) == 255UL)), g_321[1][2][1])) > p_5), l_3907[1]))), 0x02L)) <= g_327[3][0])), 0xBBL)))
            {
                uint16_t l_4234 = 65527UL;
                int32_t l_4235[7][1][6] = {{{0L, 0L, 0L, 7L, (-4L), 0xA9486EE7L}}, {{0L, 0L, 0L, 7L, (-4L), 0xA9486EE7L}}, {{0L, 0L, 0L, 7L, (-4L), 0xA9486EE7L}}, {{0L, 0L, 0L, 7L, (-4L), 0xA9486EE7L}}, {{0L, 0L, 0L, 7L, (-4L), 0xA9486EE7L}}, {{0L, 0L, 0L, 7L, (-4L), 0xA9486EE7L}}, {{0L, 0L, 0L, 7L, (-4L), 0xA9486EE7L}}};
                int32_t l_4268 = 0x71077AB4L;
                int i, j, k;
                l_3914 = ((0UL <= ((safe_lshift_func_int16_t_s_s(((p_6 < ((((((safe_add_func_int8_t_s_s((l_3924[4][2][1] = (safe_mod_func_uint32_t_u_u((((safe_unary_minus_func_uint16_t_u(((((l_4144 == (p_5 > ((safe_sub_func_int8_t_s_s((safe_sub_func_int16_t_s_s(p_6, ((safe_sub_func_int32_t_s_s(l_3907[0], (p_6 | (g_370[1] >= p_6)))) <= p_5))), g_1271)) >= 253UL))) > l_4230) ^ l_4078) >= 0UL))) || l_4231) == p_6), 0x417A891FL))), 1UL)) | g_252[1][4]) || g_3311) & l_4144) && p_5) > p_6)) < p_5), g_630)) > 0x00111E94L)) ^ 247UL);
                for (g_371 = 0; (g_371 <= 6); g_371 += 1)
                {
                    int32_t l_4263 = 1L;
                    g_539[4] = ((0UL > l_4232) >= (~l_4234));
                    if (p_6)
                        break;
                    l_4144 &= ((l_4235[0][0][5] = 4294967287UL) & (((-9L) && (safe_add_func_int16_t_s_s((!((g_141 = (p_6 & ((safe_mul_func_int8_t_s_s((p_6 <= p_6), ((((safe_mul_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(p_5, ((safe_mod_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(l_4234, (((((((l_4102 = ((safe_add_func_uint16_t_u_u((safe_mul_func_uint16_t_u_u((g_511 &= (l_3914 = 0x9D46L)), (safe_add_func_int32_t_s_s((safe_sub_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((safe_mul_func_uint16_t_u_u((g_35--), ((((safe_mul_func_int8_t_s_s((5L > 0UL), g_2935[0])) > l_4101) || 7UL) >= 3L))), p_6)), p_5)), p_5)))), 0L)) == l_3925)) < l_4234) && l_4268) && p_5) || g_2888) == l_3924[5][1][0]) | 0xC636L))), 12)), 65535UL)) > l_3987[1][6][4]))), l_3923)) <= 0UL) >= p_5) & l_4269[0][2][1]))) >= 0x72L))) == g_321[0][1][8])), g_202))) ^ (-1L)));
                    for (g_769 = 0; (g_769 <= 6); g_769 += 1)
                    {
                        int32_t l_4300[3];
                        uint32_t l_4301[5][10];
                        int i, j;
if (g_202)
                        break;
for (i = 0; i < 3; i++)
                            l_4300[i] = 0xC492EB12L;
                        for (i = 0; i < 5; i++)
                        {
                            for (j = 0; j < 10; j++)
                                l_4301[i][j] = 0x4AB7CBC2L;
                        }
                        g_539[4] = (((safe_lshift_func_int8_t_s_s((safe_mul_func_uint8_t_u_u((safe_sub_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(((((~((-1L) <= ((safe_lshift_func_uint16_t_u_u(0x2BBEL, (safe_lshift_func_uint16_t_u_u(((safe_sub_func_int32_t_s_s(0x19BDFE13L, (l_4144 &= (g_2940[(g_371 + 1)][g_371] < 0x3D9EL)))) ^ p_5), ((safe_mod_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(0UL, 0)), (safe_unary_minus_func_uint32_t_u((0x29L && 1UL))))) > p_6))))) | l_3991))) || g_2935[1]) < p_6) && l_3923), l_4263)), l_4263)), l_4230)), g_252[2][6])) > p_6) <= (-3L));
                        l_3923 = (p_5 < (g_189 < (safe_sub_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(((l_4269[6][2][1] ^ (-1L)) < (((((safe_mul_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s(p_6, l_4235[0][0][5])) == ((((l_4144 = l_4230) != ((l_4300[1] &= ((g_1297 != p_5) | g_352)) > p_6)) >= l_4301[4][4]) <= l_4302)), g_327[3][0])) || 1L) != g_35) != g_347) | l_3922)), p_6)), g_595[1])), p_6))));
                    }
                }
                return g_2935[0];
            }
            else
            {
                uint16_t l_4303 = 0xA6B4L;
                g_139 = (l_4303 = p_5);
                return l_3907[1];
            }
        }
    }
    else
    {
        uint16_t l_4317 = 65527UL;
        int16_t l_4369 = 1L;
        int32_t l_4423[2];
        int32_t l_4437 = 0xF2193F4EL;
        int i;
        for (i = 0; i < 2; i++)
            l_4423[i] = 3L;
        l_3923 = (((0xA32E4261L == ((safe_sub_func_uint16_t_u_u(8UL, p_5)) && (g_2281[1][3] |= ((((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u((((l_3920[5] & p_6) ^ (safe_mod_func_int16_t_s_s(((~g_2037) >= (safe_add_func_uint16_t_u_u(((65531UL == (((0x16L <= (((safe_lshift_func_uint16_t_u_u(0x6ADDL, 7)) > 1UL) != g_539[4])) != 0L) > p_6)) >= g_2447), 9L))), l_4317))) && 5UL), p_6)), 4)) <= l_4269[3][5][2]) | l_3925) ^ p_5)))) <= p_6) || 0xC6L);
        for (l_4168 = 0; (l_4168 == 9); l_4168 = safe_add_func_int8_t_s_s(l_4168, 7))
        {
            int32_t l_4326 = 0L;
            int8_t l_4342 = 1L;
            int32_t l_4395 = 0x74622826L;
            int32_t l_4433 = (-8L);
            int32_t l_4441 = 0x86BE7980L;
            int32_t l_4444 = (-7L);
            int32_t l_4445[2][2];
            int32_t l_4477 = 0x76B41BD1L;
            uint32_t l_4478 = 3UL;
            int i, j;
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                    l_4445[i][j] = 0x94889E6EL;
            }
            if ((safe_rshift_func_int8_t_s_u((safe_add_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u((0xEFB9L <= (l_4317 == ((p_5 == l_4326) | ((0x62L >= ((safe_rshift_func_int8_t_s_u(((safe_lshift_func_int8_t_s_u(l_3987[1][4][5], 5)) != (safe_mul_func_int16_t_s_s(((((0x2E5FL & (!(safe_lshift_func_int16_t_s_s((((((-1L) != ((safe_mod_func_uint8_t_u_u(((safe_lshift_func_int8_t_s_s((((++g_141) == (p_6 & l_4326)) | p_5), l_4317)) | g_35), g_2205)) != l_3923)) < 255UL) && l_4342) && 0x91L), 8)))) & 0xE4ED6C19L) ^ g_203) == 255UL), (-1L)))), g_326[7])) && g_244)) | l_4317)))), p_5)), l_4317)), g_353)))
            {
                return l_4342;
            }
            else
            {
                int32_t l_4358[4][5] = {{0x41B62FBDL, 0x8B33B517L, 0x7C579B24L, (-1L), (-1L)}, {0x41B62FBDL, 0x8B33B517L, 0x7C579B24L, (-1L), (-1L)}, {0x41B62FBDL, 0x8B33B517L, 0x7C579B24L, (-1L), (-1L)}, {0x41B62FBDL, 0x8B33B517L, 0x7C579B24L, (-1L), (-1L)}};
                int32_t l_4368 = 0x8BF67943L;
                int32_t l_4370 = (-1L);
                int i, j;
                l_4370 ^= ((safe_lshift_func_uint8_t_u_s(0x5CL, 5)) == ((safe_lshift_func_int8_t_s_s(((l_3923 |= ((((safe_unary_minus_func_int16_t_s((safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s((safe_sub_func_uint16_t_u_u(((((safe_rshift_func_int8_t_s_u((((g_1985[5] ^= ((safe_add_func_int32_t_s_s(((l_4358[3][3] = g_595[9]) ^ ((((safe_add_func_uint16_t_u_u(g_206, (safe_rshift_func_uint8_t_u_s(l_4317, (g_1374 = p_6))))) != ((!(safe_add_func_int32_t_s_s(p_6, (safe_mul_func_uint8_t_u_u((((l_4368 = (p_6 || g_203)) || g_3804) || 0xF501L), l_4269[8][4][1]))))) & 0x4205A092L)) != 0xA29EL) && l_3925)), 0x247A525BL)) && l_4369)) & g_1442) | p_5), g_2281[2][1])) > 1UL) ^ 0xCFL) < g_141), g_2281[2][1])), g_770)), 0xDDDEL)))) != p_5) | g_2935[0]) < g_321[0][2][3])) & 0x250A4C34L), p_5)) ^ p_5));
            }
            if (g_317)
                break;
            if ((253UL == (p_5 >= g_151)))
            {
                uint32_t l_4371[6][8] = {{0x05DB88A5L, 8UL, 1UL, 0x80225B0EL, 0x80225B0EL, 1UL, 8UL, 0x05DB88A5L}, {0x05DB88A5L, 8UL, 1UL, 0x80225B0EL, 0x80225B0EL, 1UL, 8UL, 0x05DB88A5L}, {0x05DB88A5L, 8UL, 1UL, 0x80225B0EL, 0x80225B0EL, 1UL, 8UL, 0x05DB88A5L}, {0x05DB88A5L, 8UL, 1UL, 0x80225B0EL, 0x80225B0EL, 1UL, 8UL, 0x05DB88A5L}, {0x05DB88A5L, 8UL, 1UL, 0x80225B0EL, 0x80225B0EL, 1UL, 8UL, 0x05DB88A5L}, {0x05DB88A5L, 8UL, 1UL, 0x80225B0EL, 0x80225B0EL, 1UL, 8UL, 0x05DB88A5L}};
                int i, j;
                --l_4371[3][2];
            }
            else
            {
                int32_t l_4391 = (-1L);
                int32_t l_4394 = 0x844A9011L;
                int32_t l_4428 = 0xE7267A73L;
                int32_t l_4429 = 0L;
                int32_t l_4430 = 0x5D8A129CL;
                int32_t l_4435 = 4L;
                int32_t l_4436 = 0xA89D7904L;
                int32_t l_4438 = 0x51C159DDL;
                int32_t l_4446 = 1L;
                int32_t l_4448 = 0L;
                for (g_3890 = 0; (g_3890 != 43); g_3890 = safe_add_func_uint8_t_u_u(g_3890, 7))
                {
                    int16_t l_4388 = 1L;
                    int16_t l_4400 = 1L;
                    if (g_1985[5])
                        break;
                    if (p_5)
                    {
                        uint32_t l_4392 = 0xD55DFBC2L;
                        int32_t l_4393[6][9][4] = {{{(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}}, {{(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}}, {{(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}}, {{(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}}, {{(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}}, {{(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}, {(-3L), 0L, 0x640DCB94L, 0x640DCB94L}}};
                        int i, j, k;
                        l_4395 = ((((g_332 = (g_408 >= p_5)) || (safe_rshift_func_uint16_t_u_u(g_2447, 2))) & (safe_sub_func_uint16_t_u_u(g_1442, (l_4394 = (l_4393[1][0][1] = (safe_lshift_func_uint8_t_u_u((((-10L) > ((safe_add_func_uint32_t_u_u((l_3923 = (l_4392 &= ((((safe_mul_func_int16_t_s_s((l_4391 = (p_6 = (((l_4326 = (safe_rshift_func_int8_t_s_s(l_4388, g_2414))) || ((safe_sub_func_uint32_t_u_u((g_244 = (0x71A1L <= g_2414)), 0UL)) | 65532UL)) || 0xAAE904B0L))), g_202)) & g_348) == p_5) < l_4369))), p_5)) >= 0xE453B4E5L)) ^ p_5), 2))))))) && 3UL);
                        g_139 = (safe_mul_func_int8_t_s_s(((0L | (l_4393[1][0][1] ^= (safe_add_func_uint8_t_u_u(l_4392, l_4400)))) > (((l_4269[0][2][1] || (p_6 ^ (safe_lshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s(((!(safe_lshift_func_int8_t_s_s(3L, (g_317 ^= (((l_4392 | ((safe_lshift_func_int16_t_s_u((safe_mul_func_int8_t_s_s((+(0xE756L & (((((safe_rshift_func_uint16_t_u_s((p_6 || p_5), 8)) || 0UL) > p_5) < g_348) > p_5))), l_3894)), 7)) | 0x07EFL)) & (-1L)) <= p_5))))) >= g_3612[0]), 0xC86AL)), 3)))) & 1UL) | 1UL)), l_3987[1][2][4]));
                        l_4415++;
                        g_2205 ^= 0x2E4A146BL;
                    }
                    else
                    {
                        uint16_t l_4418[2];
                        int32_t l_4419[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_4418[i] = 0UL;
                        for (i = 0; i < 2; i++)
                            l_4419[i] = 0x469AB047L;
                        l_4418[0] ^= g_3890;
                        l_4419[0] = g_408;
                    }
                }
                for (g_769 = 0; (g_769 < 49); g_769 = safe_add_func_int32_t_s_s(g_769, 9))
                {
                    int8_t l_4422 = 0x55L;
                    int32_t l_4424 = 0x3EC3087BL;
                    int32_t l_4425 = 0x36305299L;
                    int32_t l_4427 = 1L;
                    int32_t l_4432 = 0xC927B1DEL;
                    int32_t l_4439 = 0xBDD24091L;
                    int32_t l_4440 = (-5L);
                    int32_t l_4442 = 1L;
                    int32_t l_4443 = 0xF8C6678EL;
                    int32_t l_4447[8][2][8] = {{{(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}, {(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}}, {{(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}, {(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}}, {{(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}, {(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}}, {{(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}, {(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}}, {{(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}, {(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}}, {{(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}, {(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}}, {{(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}, {(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}}, {{(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}, {(-9L), (-6L), 0x744250C5L, 0L, 0xCCED5418L, 0x4FC11C8CL, 0xD168A6DCL, 0xD168A6DCL}}};
                    uint32_t l_4487 = 2UL;
                    uint8_t l_4492 = 0UL;
                    int8_t l_4493[7] = {0x9AL, 0x6AL, 0x9AL, 0x6AL, 0x9AL, 0x6AL, 0x9AL};
                    int i, j, k;
                    if (((l_4422 = (g_3893 = (p_6 & p_6))) != 1UL))
                    {
                        return l_3923;
                    }
                    else
                    {
                        int32_t l_4426 = 0xD90F0E53L;
                        int32_t l_4431 = 0xCD591A28L;
                        int32_t l_4434 = (-5L);
                        uint32_t l_4449 = 2UL;
                        --l_4449;
                        l_4442 = ((l_4425 |= (safe_add_func_int32_t_s_s(1L, (-1L)))) <= (safe_mul_func_uint8_t_u_u((safe_sub_func_int16_t_s_s((+(safe_sub_func_uint32_t_u_u(((g_408 = (safe_unary_minus_func_uint32_t_u(l_4428))) < (!((p_6 ^ ((g_2447 = (p_5 && (safe_mul_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((safe_add_func_int8_t_s_s((safe_lshift_func_int16_t_s_u((((safe_sub_func_int8_t_s_s(0L, g_2940[7][3])) != (safe_mod_func_int32_t_s_s((1UL <= g_348), 0x9379F07EL))) != g_151), 6)), 0x31L)), 14)), g_321[0][1][8])), 0x0BL)))) ^ g_141)) >= 0x3FL))), p_5))), l_3920[5])), p_5)));
                        if (p_6)
                            continue;
                    }
                    l_4478++;
                    for (g_2205 = 9; (g_2205 >= 1); g_2205 -= 1)
                    {
                        int32_t l_4483 = 0xD851FFB7L;
                        int i;
                        l_4423[0] = 0x2A1C6B86L;
g_141 &= (l_4429 = 0x9D46L);
l_3924[5][1][0] = (safe_add_func_uint32_t_u_u(g_1985[g_2205], ((l_4483 &= (p_5 != (-10L))) <= (g_151 = g_1985[g_2205]))));
                        l_3924[6][1][3] ^= ((safe_unary_minus_func_uint16_t_u((l_4326 != (l_4494[2] = (safe_lshift_func_int8_t_s_s(((++l_4487) <= 65535UL), ((safe_rshift_func_uint16_t_u_u(p_6, g_595[7])) & (l_4424 = (((((0x3FECL >= ((g_3 || (0x51E0F1CBL || ((l_4492 || ((g_1985[g_2205] < l_4493[0]) & g_1985[g_2205])) & l_3920[2]))) > p_5)) ^ l_4423[0]) || p_5) | p_5) ^ l_4423[0]))))))))) <= (-10L));
                    }
                }
            }
        }
        l_3925 ^= g_2940[0][1];
        g_139 = p_6;
    }
    l_3923 = (g_1442 & (l_4494[4] | 0x24L));
    if (l_3991)
    {
        uint16_t l_4503 = 0x0B1FL;
        int32_t l_4504 = 0xBE3D8E90L;
        l_4504 |= (l_3925 = ((l_3923 &= (!((p_6 != ((-1L) & p_6)) ^ g_769))) & ((safe_sub_func_uint32_t_u_u((l_3924[5][1][0] &= ((p_5 <= (-4L)) | (safe_lshift_func_int8_t_s_s((safe_sub_func_uint8_t_u_u(((((0x9CF2B8DBL < g_244) <= l_4502) > g_1297) > g_2940[6][2]), l_4503)), 7)))), p_5)) || l_3924[9][2][1])));
    }
    else
    {
        int8_t l_4520 = (-1L);
        int32_t l_4529[5] = {0x83ED08B0L, (-9L), 0x83ED08B0L, (-9L), 0x83ED08B0L};
        int32_t l_4537 = 0L;
        int32_t l_4547 = 0x70F01339L;
        int i;
        for (l_3925 = 0; (l_3925 == (-30)); l_3925 = safe_sub_func_int16_t_s_s(l_3925, 6))
        {
            for (g_348 = 0; (g_348 != 18); g_348 = safe_add_func_int16_t_s_s(g_348, 3))
            {
                uint8_t l_4519 = 0x68L;
                for (g_769 = 0; (g_769 <= 2); g_769 += 1)
                {
                    int i, j, k;
                    g_539[(g_769 + 5)] = (g_252[g_769][(g_769 + 1)] | ((((((safe_rshift_func_uint16_t_u_u((g_252[g_769][(g_769 + 3)] | (g_252[(g_769 + 1)][(g_769 + 3)] < ((0x58DEA204L || (((g_321[(g_769 + 1)][g_769][(g_769 + 6)] ^ (safe_lshift_func_int16_t_s_u((p_6 ^= 0x2CF1L), g_327[3][0]))) < g_630) < (g_326[7] | p_5))) == p_5))), p_5)) && g_1271) | g_630) & g_317) & p_5) ^ 5UL));
                    for (g_2414 = 3; (g_2414 <= 8); g_2414 += 1)
                    {
                        int i;
                        g_539[(g_769 + 1)] = (0x57L & (safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint8_t_u_s(g_252[g_769][(g_769 + 1)], (safe_rshift_func_uint16_t_u_u(0x5EA1L, g_206)))) ^ g_3612[0]), l_4519)));
                    }
                    for (g_1374 = 8; (g_1374 >= 2); g_1374 -= 1)
                    {
                        return l_4520;
                    }
                }
            }
        }
        l_3925 = ((safe_add_func_uint32_t_u_u(((+(safe_lshift_func_int16_t_s_u((0x52L != (l_3923 = p_6)), g_407))) | (l_3924[4][1][3] = 0xDB6CL)), (safe_rshift_func_int16_t_s_s((~g_3890), ((l_4529[1] = 1L) ^ (((l_4530 = l_4530) && (safe_add_func_uint8_t_u_u((l_4537 = ((((safe_mod_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_u(((++g_35) <= (l_4547 ^= ((g_1297 = ((safe_mul_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_s(((((safe_mod_func_uint32_t_u_u(p_5, l_4520)) < l_4537) == g_348) || l_3925), g_1271)) >= l_4537), g_1271)) < g_1297)) && l_4546))), 6)) != 0xB2L), g_770)) == l_4548) ^ p_5) == l_4530)), (-2L)))) != 0x0CL)))))) != 1UL);
    }
    return p_5;
}
inline static uint16_t func_7(uint16_t p_8, int32_t p_9, int32_t p_10, uint32_t p_11)
{
    int32_t l_3892 = 0x90DED701L;
    l_3892 = p_9;
    p_10 = p_9;
    return l_3892;
}
inline static int8_t func_15(int32_t p_16, uint16_t p_17, uint8_t p_18)
{
    uint32_t l_3858 = 18446744073709551615UL;
    int32_t l_3859 = 0x0C863A66L;
    int32_t l_3888 = 0L;
    int32_t l_3889 = 6L;
    p_16 = (safe_sub_func_int16_t_s_s((safe_mod_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u(g_326[2], (((((p_18 < (~(safe_lshift_func_int16_t_s_s(((g_769--) <= (safe_mod_func_int8_t_s_s(((l_3859 |= l_3858) > (5UL < (safe_mod_func_uint8_t_u_u((~(safe_mul_func_uint8_t_u_u(0x3DL, (((safe_lshift_func_int16_t_s_s(((safe_mul_func_uint16_t_u_u((g_511 = ((safe_add_func_int32_t_s_s(((safe_mul_func_int16_t_s_s((g_1985[5] & (safe_sub_func_uint32_t_u_u(((l_3889 |= (((~((safe_rshift_func_uint16_t_u_u(65531UL, 2)) < (safe_sub_func_uint8_t_u_u((safe_add_func_int16_t_s_s((safe_mod_func_uint32_t_u_u((((safe_mod_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s(g_326[7], 12)), (-4L))) >= l_3858) | (-9L)), p_17)), l_3888)), l_3888)))) == 0x1269L) == g_539[4])) && 0xE4ABL), g_3890))), 1L)) < g_139), 0x3BAB70BAL)) > (-10L))), 65535UL)) == 0x59A2L), 8)) > 0xF413060EL) || p_17)))), 0xBFL)))), g_408))), p_16)))) ^ 0xF9L) < g_595[6]) <= 4L) < (-1L)))), p_16)), 0x9BD6L));
    return l_3859;
}
static int32_t func_19(int8_t p_20, int32_t p_21, int32_t p_22)
{
    uint8_t l_3343[1];
    int32_t l_3346 = 0x51E3D795L;
    int32_t l_3416 = 0x40358BF6L;
    int32_t l_3425 = 1L;
    uint16_t l_3477 = 0UL;
    uint8_t l_3501 = 255UL;
    int16_t l_3504 = 0x8F68L;
    int32_t l_3505[3];
    uint8_t l_3543[1][5];
    int32_t l_3549 = 0x46E6B259L;
    uint32_t l_3613[4];
    uint32_t l_3809 = 18446744073709551612UL;
    int8_t l_3844 = 1L;
    int i, j;
    for (i = 0; i < 1; i++)
        l_3343[i] = 4UL;
    for (i = 0; i < 3; i++)
        l_3505[i] = (-1L);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 5; j++)
            l_3543[i][j] = 0x5CL;
    }
    for (i = 0; i < 4; i++)
        {
g_347 &= (safe_unary_minus_func_int16_t_s(0x82C1L));
l_3613[i] = 0xCB66470CL;}
    for (g_769 = 0; (g_769 <= 2); g_769 += 1)
    {
        uint32_t l_3340[5];
        int32_t l_3362 = 7L;
        uint8_t l_3397 = 0xB9L;
        int32_t l_3413 = 0x22714295L;
        int32_t l_3414 = 0x32BE2807L;
        int32_t l_3415[8];
        uint32_t l_3426 = 0UL;
        uint16_t l_3457 = 0x69E6L;
        int32_t l_3479 = 0x0BE39DC0L;
        uint32_t l_3506 = 8UL;
        int i;
        for (i = 0; i < 5; i++)
            l_3340[i] = 7UL;
        for (i = 0; i < 8; i++)
            l_3415[i] = 0x00F530CFL;
        for (g_2205 = 0; (g_2205 <= 2); g_2205 += 1)
        {
            uint8_t l_3339 = 0x55L;
            int32_t l_3355 = 0x6ED154E9L;
            if (((!p_21) <= (safe_add_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((g_2414 = (safe_mod_func_uint16_t_u_u((safe_mod_func_int32_t_s_s(g_2935[0], (-7L))), 0xC8A4L))), ((2L && (safe_sub_func_int8_t_s_s(l_3339, (g_1374 = (((((-1L) | l_3340[3]) ^ l_3339) && p_20) || (-7L)))))) || g_328))), g_2935[0]))))
            {
                for (g_35 = 0; (g_35 <= 2); g_35 += 1)
                {
                    for (p_22 = 0; (p_22 <= 2); p_22 += 1)
                    {
                        p_21 = ((g_2414 & (safe_sub_func_int8_t_s_s(l_3343[0], (safe_rshift_func_int8_t_s_s(p_21, 5))))) == l_3340[0]);
                    }
                }
            }
            else
            {
                uint16_t l_3347 = 0xD94BL;
                for (g_347 = 0; (g_347 <= 2); g_347 += 1)
                {
                    l_3347--;
                    for (g_151 = 0; (g_151 <= 2); g_151 += 1)
                    {
                        return p_22;
                    }
                }
                p_21 = (l_3343[0] != ((-10L) <= (safe_rshift_func_int8_t_s_s((!(((safe_add_func_int16_t_s_s(((((p_20 = (l_3355 &= g_595[2])) == (safe_sub_func_uint8_t_u_u((g_244 | l_3347), ((0L & (g_252[0][2] = p_21)) <= (0x69L || (safe_sub_func_int16_t_s_s((((((((safe_lshift_func_int16_t_s_u(p_21, 14)) < 0xB4L) < 0x42DCL) | 65534UL) & p_22) == p_21) != p_21), g_2935[0]))))))) | 1L) | p_22), g_316)) ^ 1UL) & g_1985[4])), 3))));
            }
            if (p_21)
                continue;
            l_3362 = 0L;
            for (g_2447 = 0; (g_2447 <= 2); g_2447 += 1)
            {
                int16_t l_3379[4][7];
                int i, j;
g_189 |= (((~((safe_rshift_func_uint16_t_u_u(65531UL, 2)) < (safe_sub_func_uint8_t_u_u((safe_add_func_int16_t_s_s((safe_mod_func_uint32_t_u_u((((safe_mod_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s(g_326[7], 12)), (-4L))) >= g_244) | (-9L)), l_3477)), g_348)), g_348)))) == 0x1269L) == g_539[4]);
for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 7; j++)
                        l_3379[i][j] = 1L;
                }
                for (g_1271 = 2; (g_1271 >= 0); g_1271 -= 1)
                {
                    int i, j, k;
                    g_352 = (safe_lshift_func_uint16_t_u_s((l_3362 &= ((safe_lshift_func_int16_t_s_s((((((((g_206 == (safe_sub_func_uint8_t_u_u((p_22 & p_20), (l_3379[1][0] = (+((safe_unary_minus_func_uint8_t_u((safe_mul_func_uint8_t_u_u((g_321[(g_2205 + 1)][g_1271][(g_2205 + 3)] = (safe_mul_func_uint8_t_u_u(p_20, ((((1L ^ (-1L)) == p_20) > (g_332 = ((safe_add_func_uint16_t_u_u((safe_sub_func_int8_t_s_s(g_371, (1L || g_408))), g_2414)) != 1L))) || 0x3A34L)))), g_139)))) & 4L)))))) < 0xCEL) | g_1297) == l_3339) && p_20) & l_3343[0]) > l_3339), 1)) && 7L)), g_2940[3][3]));
                }
                g_539[3] = g_539[4];
                p_21 = ((safe_lshift_func_int16_t_s_s((-9L), g_2281[2][1])) & (g_2205 > (g_630 <= (((safe_sub_func_uint16_t_u_u(((((safe_lshift_func_uint8_t_u_u(g_2888, p_20)) >= g_206) > ((safe_sub_func_uint8_t_u_u(((+(safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((safe_mod_func_uint8_t_u_u((0xFF20B687L <= ((safe_rshift_func_uint16_t_u_s((g_244 ^ l_3397), 1)) < g_370[3])), p_21)), g_2935[0])), 0x9CADL))) >= 4294967295UL), 0x22L)) >= p_22)) < l_3340[4]), g_326[7])) && l_3343[0]) & 1L))));
            }
        }
        if (g_371)
            {
{
                        uint32_t l_1779 = 0x8877290CL;
                        ++l_1779;
                    }
break;}
        if (((g_317 = (0x82L | 0xCDL)) > (p_21 & 0x03L)))
        {
            int16_t l_3398 = 9L;
            int32_t l_3411 = 0xB86EAAE3L;
            int32_t l_3412 = 0x0D8A4525L;
            int32_t l_3419 = 0xC4F9C5EAL;
            int32_t l_3420 = 0L;
            int32_t l_3421 = (-9L);
            int32_t l_3422 = 1L;
            int32_t l_3424[10];
            int32_t l_3475 = 0xB5ABB780L;
            int i;
            for (i = 0; i < 10; i++)
                l_3424[i] = (-5L);
            if (((p_22 = 0xFB21B00DL) > (l_3398 > (safe_add_func_uint32_t_u_u(g_353, ((~(safe_mod_func_int32_t_s_s(((0UL || g_1985[5]) <= (safe_lshift_func_int8_t_s_s((p_20 = (((p_20 > (safe_add_func_int16_t_s_s(((g_370[5] < (safe_lshift_func_uint8_t_u_u(l_3343[0], ((g_326[7] == 0xE1L) != l_3362)))) && p_20), p_21))) >= l_3362) != g_973)), 2))), p_21))) & p_21))))))
            {
                int16_t l_3410 = 1L;
                int32_t l_3417 = 0xB585A917L;
                int32_t l_3418[1];
                int8_t l_3423[7][10] = {{0x0FL, (-10L), (-9L), 0x0DL, 0x0DL, (-9L), (-10L), 0x0FL, (-9L), 0x0FL}, {0x0FL, (-10L), (-9L), 0x0DL, 0x0DL, (-9L), (-10L), 0x0FL, (-9L), 0x0FL}, {0x0FL, (-10L), (-9L), 0x0DL, 0x0DL, (-9L), (-10L), 0x0FL, (-9L), 0x0FL}, {0x0FL, (-10L), (-9L), 0x0DL, 0x0DL, (-9L), (-10L), 0x0FL, (-9L), 0x0FL}, {0x0FL, (-10L), (-9L), 0x0DL, 0x0DL, (-9L), (-10L), 0x0FL, (-9L), 0x0FL}, {0x0FL, (-10L), (-9L), 0x0DL, 0x0DL, (-9L), (-10L), 0x0FL, (-9L), 0x0FL}, {0x0FL, (-10L), (-9L), 0x0DL, 0x0DL, (-9L), (-10L), 0x0FL, (-9L), 0x0FL}};
                int i, j;
                for (i = 0; i < 1; i++)
                    l_3418[i] = 1L;
                l_3426--;
                if (l_3340[4])
                    continue;
            }
            else
            {
                int32_t l_3476 = (-1L);
                uint8_t l_3478 = 5UL;
                l_3416 = (((safe_sub_func_uint32_t_u_u(0UL, (((l_3424[8] = (safe_mod_func_int8_t_s_s((safe_mul_func_uint8_t_u_u((((++g_326[7]) || (l_3397 > (safe_add_func_int32_t_s_s((p_21 & p_22), ((l_3425 ^= 0x21L) == (p_21 ^ (safe_rshift_func_int8_t_s_s(l_3422, 1)))))))) ^ ((safe_sub_func_int32_t_s_s(9L, 0x6FC78F7CL)) & p_21)), l_3422)), (-1L)))) ^ p_21) >= 3L))) < 0x6CL) || p_22);
                for (g_203 = 0; (g_203 == 38); g_203 = safe_add_func_uint32_t_u_u(g_203, 4))
                {
                    if (g_206)
                        break;
                    g_539[4] = ((safe_add_func_int8_t_s_s((g_332 = ((safe_sub_func_uint32_t_u_u((p_21 & (0x474A18BDL < ((safe_lshift_func_int16_t_s_u(((safe_add_func_uint8_t_u_u(((safe_add_func_int16_t_s_s((p_20 == ((safe_mul_func_uint16_t_u_u((l_3415[4] ^= l_3457), (l_3424[6] &= ((safe_add_func_uint32_t_u_u(1UL, p_21)) ^ (l_3346 &= ((l_3476 = (safe_rshift_func_int8_t_s_s(((safe_unary_minus_func_int32_t_s((safe_mod_func_int16_t_s_s((l_3362 ^= ((((safe_mul_func_uint16_t_u_u(g_595[6], (safe_mul_func_uint16_t_u_u((safe_add_func_uint16_t_u_u(g_3, (safe_lshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_u(l_3413, g_595[3])), l_3421)))), g_1297)))) == l_3425) == 0x1AL) < p_21)), g_327[3][0])))) >= l_3475), 4))) | g_2414)))))) || l_3343[0])), 6L)) <= 0xFA39C599L), g_630)) ^ l_3477), 0)) || l_3478))), g_321[0][1][8])) < l_3343[0])), p_20)) > 65528UL);
                }
                l_3479 = 0x83157B27L;
                for (g_408 = 0; (g_408 <= (-16)); --g_408)
                {
                    return l_3476;
                }
            }
        }
        else
        {
            uint32_t l_3484 = 0x13895B77L;
            if (((((safe_mul_func_int8_t_s_s(l_3484, ((safe_mod_func_int16_t_s_s((l_3425 ^= (0xAD213919L != (safe_add_func_int32_t_s_s(((0x3F513112L | ((safe_add_func_uint8_t_u_u((safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u(g_317, 2)), ((safe_mod_func_uint32_t_u_u(((0x1FD5L <= (l_3416 = ((safe_rshift_func_int16_t_s_u((l_3346 = (((g_2205 |= (0x1D9EB6B4L < (g_2935[2] <= (g_326[1] = (safe_add_func_int32_t_s_s(g_370[5], 3UL)))))) != g_407) < l_3416)), l_3484)) ^ (-1L)))) < l_3484), l_3343[0])) ^ p_22))), l_3415[4])) <= l_3501)) == 65532UL), 0L)))), l_3426)) == p_20))) <= p_21) > p_22) <= 0L))
            {
                if (g_317)
                    break;
            }
            else
            {
                g_539[7] ^= (safe_lshift_func_uint8_t_u_s(l_3346, 3));
            }
            if (g_2037)
                break;
            if (p_22)
                break;
        }
        l_3506++;
    }
    if ((safe_mod_func_int16_t_s_s((l_3416 = ((safe_add_func_int16_t_s_s((safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(((l_3543[0][3] = (safe_rshift_func_int8_t_s_u((safe_rshift_func_uint16_t_u_u(((((safe_rshift_func_uint16_t_u_u((safe_add_func_uint32_t_u_u((l_3346 = (g_206 ^= 4UL)), (0L & (((safe_lshift_func_int16_t_s_u((((safe_mod_func_uint8_t_u_u((l_3505[2] ^= (safe_add_func_uint32_t_u_u(9UL, 0x8B6AC579L))), g_326[5])) || ((++g_511) && (((0x78L < (safe_mod_func_uint8_t_u_u(((safe_mul_func_uint16_t_u_u((safe_add_func_int16_t_s_s((g_347 | p_22), (safe_mul_func_uint16_t_u_u(((((safe_add_func_int32_t_s_s(l_3343[0], 0x4CAD00D3L)) <= 0x7F36L) & p_21) != 65530UL), l_3501)))), 8L)) != 0x406AL), 0x45L))) | 0UL) | g_2281[2][1]))) & 0xFF3937C0L), 12)) && g_3311) || 0xF9D8L)))), g_139)) != 65527UL) != 0x2173C77CL) == 251UL), g_407)), 6))) >= l_3477), p_21)), 1L)), l_3504)) | l_3343[0])), l_3504)))
    {
        uint8_t l_3544 = 0xFBL;
        int32_t l_3545 = 0L;
        int32_t l_3550 = (-5L);
        uint32_t l_3670 = 0x8704473BL;
        int32_t l_3717[5];
        int8_t l_3756[10] = {0xF8L, 0xF8L, 1L, 0xF8L, 0xF8L, 1L, 0xF8L, 0xF8L, 1L, 0xF8L};
        int16_t l_3797 = 1L;
        int i;
        for (i = 0; i < 5; i++)
            l_3717[i] = 0x6AF3258EL;
{
                    for (p_21 = 3; (p_21 >= 0); p_21 -= 1)
                    {
                        int i, j;
                        g_1297 ^= g_252[p_21][g_3890];
                    }
                    g_332 = 0x2307333BL;
                }
l_3544 = g_202;
        for (g_408 = 0; (g_408 >= 0); g_408 -= 1)
        {
            uint16_t l_3546 = 0x82F9L;
            int32_t l_3565 = 0xDEF9688DL;
            --l_3546;
            for (g_1271 = 0; (g_1271 <= 0); g_1271 += 1)
            {
                uint16_t l_3551 = 65534UL;
                int32_t l_3562 = (-2L);
                int32_t l_3563 = (-1L);
                int i, j;
                --l_3551;
                g_139 ^= (l_3563 = (safe_lshift_func_uint8_t_u_u(0x54L, (0xF907L < ((g_327[(g_1271 + 2)][g_408] == ((safe_sub_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u((g_2281[2][1] = p_22), (l_3562 = (((safe_lshift_func_int16_t_s_u(0x1DB4L, (0x2CL | (g_511 ^ ((0xA0L | ((1UL & 0xD496A378L) || 1L)) ^ g_539[4]))))) || p_21) ^ p_22)))), 0x4CL)) != g_189)) == 1UL)))));
                l_3565 = ((!(-6L)) != (-3L));
            }
        }
        for (g_35 = 0; (g_35 > 33); g_35++)
        {
            uint16_t l_3576[1];
            int32_t l_3614[10] = {0x3FD4E721L, 0x2180304FL, 0x3FD4E721L, 0x2180304FL, 0x3FD4E721L, 0x2180304FL, 0x3FD4E721L, 0x2180304FL, 0x3FD4E721L, 0x2180304FL};
            int i;
            for (i = 0; i < 1; i++)
                l_3576[i] = 65528UL;
            if ((l_3545 = (-3L)))
            {
                return l_3550;
            }
            else
            {
                uint16_t l_3573 = 0x6545L;
                int32_t l_3611 = 8L;
                for (g_332 = 0; (g_332 == 28); g_332 = safe_add_func_uint16_t_u_u(g_332, 4))
                {
                    int16_t l_3572 = 0x2110L;
                    for (l_3550 = (-23); (l_3550 != (-17)); l_3550 = safe_add_func_uint16_t_u_u(l_3550, 3))
                    {
g_203 ^= g_973;
g_1297 &= g_1374;
                    }
                    l_3573--;
                    p_21 = l_3549;
                    p_21 = (-4L);
                }
                p_21 = ((l_3576[0] & (safe_add_func_int16_t_s_s((g_252[2][1] > (g_206 = ((g_2940[7][0] ^ 0x1FL) <= p_22))), (safe_rshift_func_int8_t_s_s(9L, ((safe_lshift_func_int8_t_s_s((safe_add_func_uint8_t_u_u(l_3573, ((safe_sub_func_uint16_t_u_u(p_22, ((l_3550 = ((safe_rshift_func_int8_t_s_s(1L, l_3576[0])) <= l_3573)) != 0x48L))) ^ 1UL))), g_326[0])) && p_20)))))) > g_1374);
                l_3545 ^= (safe_add_func_int32_t_s_s(((safe_sub_func_uint16_t_u_u(65535UL, (g_141 = (safe_rshift_func_int16_t_s_s((g_1985[5] = (~((+(safe_add_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(0xA583L, 15)), g_511))) && (safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s(((l_3613[0] = (l_3343[0] > (safe_mul_func_int8_t_s_s(((0x4AL <= (l_3611 ^= ((safe_rshift_func_int16_t_s_u(p_22, ((l_3576[0] == 0x980BL) ^ l_3543[0][3]))) >= l_3504))) != g_3612[0]), p_21)))) > 1UL), l_3614[6])), 13)), p_20))))), 6))))) >= g_151), 4294967291UL));
                g_2205 |= g_321[0][1][8];
            }
            p_22 ^= (l_3346 = (-1L));
            g_539[4] |= (~((safe_lshift_func_int16_t_s_s(((p_22 < l_3614[0]) < (((safe_sub_func_int32_t_s_s((safe_lshift_func_int8_t_s_s((3L & (l_3545 = l_3613[0])), p_20)), ((safe_sub_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_s(((((1L && (((0x34L && (safe_lshift_func_uint16_t_u_s(65534UL, (65529UL < 1UL)))) == g_202) || 0xD5A2L)) <= p_22) < l_3425) >= g_252[2][6]), p_21)) < l_3544), p_21)), 4)), l_3614[6])) & 0x432158CEL))) & g_203) != 0L)), l_3614[6])) ^ 0xE5L));
        }
        for (l_3416 = 19; (l_3416 < 0); --l_3416)
        {
            int16_t l_3671 = 0x8474L;
            int32_t l_3781 = 0x0C69FEFCL;
            int32_t l_3783 = 1L;
            int32_t l_3803 = 1L;
            int32_t l_3805 = (-5L);
            int32_t l_3806 = 0x53FC20FEL;
            int32_t l_3807 = 0xDF876C5BL;
            l_3425 |= ((safe_add_func_uint32_t_u_u(0x92C0CD19L, ((((((((safe_mod_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_u((safe_mul_func_int8_t_s_s((g_317 = (safe_add_func_uint32_t_u_u(p_22, (((((((l_3549 &= 65526UL) & (g_511 = p_22)) || (g_139 = 0L)) ^ l_3544) & (safe_add_func_int16_t_s_s(l_3543[0][3], (g_1985[5] && ((l_3550 || l_3550) > p_20))))) != 8UL) == g_370[1])))), p_20)), p_20)), 0x63L)) & (-10L)) && p_22) && 0x71L) ^ p_20) ^ g_326[7]) || (-1L)) >= p_21))) && g_370[2]);
            g_539[4] &= ((safe_sub_func_uint16_t_u_u((((safe_mul_func_uint8_t_u_u((0x6AL >= ((0xD21DA144L >= 0x6BA5330FL) <= (!(l_3549 = ((g_326[7]++) || (safe_rshift_func_int8_t_s_u((safe_add_func_int16_t_s_s(((((safe_mul_func_uint16_t_u_u(((~l_3416) | (((safe_mod_func_uint32_t_u_u((p_21 <= (((safe_rshift_func_int16_t_s_s(p_20, 12)) != p_21) > (g_2205 &= (l_3346 &= (((((l_3343[0] & ((safe_sub_func_uint16_t_u_u((l_3549 == g_35), l_3670)) & p_21)) > 0x68L) && l_3671) ^ l_3671) | 0UL))))), l_3425)) || p_22) < p_20)), 0x7E60L)) | g_141) < p_20) & l_3550), (-1L))), 7))))))), 0xD1L)) <= 9UL) < 1UL), 0xFC67L)) != g_371);
            for (g_35 = 0; (g_35 <= 3); g_35 += 1)
            {
                uint8_t l_3679[7] = {246UL, 0xB3L, 246UL, 0xB3L, 246UL, 0xB3L, 246UL};
                int32_t l_3681 = 1L;
                uint32_t l_3702[7][9][4] = {{{0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}}, {{0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}}, {{0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}}, {{0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}}, {{0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}}, {{0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}}, {{0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}, {0xC1A4C303L, 0x9E9193C4L, 0x3CB1D23EL, 0UL}}};
                int32_t l_3716 = 4L;
                int i, j, k;
                for (l_3671 = 0; (l_3671 >= 0); l_3671 -= 1)
                {
                    int16_t l_3672 = 4L;
                    for (l_3501 = 0; (l_3501 <= 0); l_3501 += 1)
                    {
                        int i;
                        if (l_3613[(l_3501 + 2)])
                            break;
                        if (p_22)
                            break;
                        p_22 = ((p_21 = (l_3672 <= ((g_252[3][5] |= g_2935[0]) & (p_20 ^ p_20)))) ^ (safe_mul_func_int8_t_s_s((safe_mul_func_uint16_t_u_u((g_511++), (l_3679[3] = 0x3C1EL))), (!((((p_22 < 0xA27186ECL) | (g_332 != l_3681)) <= l_3613[0]) ^ p_20)))));
                        return p_20;
                    }
                    g_139 = g_348;
                    for (l_3501 = 0; (l_3501 <= 3); l_3501 += 1)
                    {
                        p_21 = (g_2205 = (g_3612[0] <= (~(g_408 = (l_3545 ^ (l_3550 = (~p_22)))))));
                    }
                }
                for (p_21 = 0; (p_21 <= 3); p_21 += 1)
                {
                    uint16_t l_3715 = 65532UL;
                    for (g_770 = 0; (g_770 <= 3); g_770 += 1)
                    {
                        uint16_t l_3713 = 0x1C24L;
                        uint32_t l_3714 = 18446744073709551615UL;
                        g_539[7] = (safe_add_func_int32_t_s_s(l_3671, (g_3 == (safe_lshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u((((p_21 != 0x5190F697L) >= ((-5L) ^ 0xD7L)) < l_3416), 3)), 5)))));
                        l_3717[3] &= ((safe_add_func_int8_t_s_s((p_20 ^ 65535UL), ((l_3505[2] |= (l_3716 &= (l_3715 |= (((safe_mod_func_int8_t_s_s(((l_3545 = (safe_mul_func_uint16_t_u_u(((safe_mul_func_int8_t_s_s((-8L), (safe_add_func_int16_t_s_s(l_3545, (((safe_sub_func_uint32_t_u_u((--l_3702[1][3][1]), ((safe_mod_func_int16_t_s_s((g_1297 ^ (l_3681 || ((((safe_lshift_func_int8_t_s_u((l_3550 |= (g_2037 < ((p_22 == (safe_mul_func_uint16_t_u_u(((l_3425 = (safe_sub_func_int16_t_s_s((l_3681 <= p_22), 1L))) <= 0x4E0BL), l_3713))) || p_21))), 2)) || g_3612[0]) && g_206) >= p_21))), l_3714)) | g_321[3][1][7]))) && p_21) ^ p_22))))) != l_3671), g_1985[5]))) <= 65531UL), g_206)) | l_3713) & p_21)))) | l_3671))) & 0xC3C91A62L);
                    }
                }
g_203 |= (((safe_sub_func_uint8_t_u_u(0xBFL, g_371)) & (g_973 <= (safe_sub_func_int32_t_s_s(4L, (safe_mul_func_int8_t_s_s((safe_mod_func_int8_t_s_s((g_3804 = (safe_mul_func_int16_t_s_s(g_973, g_770))), g_244)), 0L)))))) & g_206);
l_3717[1] = (p_21 = (safe_mod_func_int8_t_s_s((safe_mod_func_int8_t_s_s((safe_mod_func_int16_t_s_s((l_3549 >= (l_3501 & (safe_rshift_func_int16_t_s_s((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_s(((l_3505[2] ^= (safe_add_func_int8_t_s_s(l_3702[4][1][0], (safe_rshift_func_int8_t_s_u(l_3716, 7))))) == p_20), l_3613[3])) <= g_347), (g_2935[1] |= 0x56L))), 0UL)), g_317)))), (-2L))), g_407)), g_349)));
                for (g_2037 = 0; (g_2037 <= 0); g_2037 += 1)
                {
                    uint32_t l_3782 = 4294967289UL;
                    int32_t l_3788 = 0L;
                    int32_t l_3792 = 0x65E1F16EL;
                    for (l_3670 = 0; (l_3670 <= 0); l_3670 += 1)
                    {
                        int32_t l_3784[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_3784[i] = 0L;
                        l_3505[0] = (safe_mod_func_int16_t_s_s((-2L), ((((safe_mul_func_int16_t_s_s((safe_add_func_uint16_t_u_u((g_321[0][1][8] < (((((g_317 = 0xD7L) & l_3702[1][3][1]) <= (safe_mod_func_int32_t_s_s(((safe_mod_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u((l_3783 = (safe_sub_func_uint8_t_u_u(0x00L, ((g_407 ^= (safe_mul_func_int16_t_s_s((-2L), ((safe_mod_func_uint32_t_u_u(((safe_mul_func_int16_t_s_s(l_3756[4], (((safe_lshift_func_int16_t_s_s(((l_3549 |= (g_332 |= (safe_mod_func_int8_t_s_s((((((safe_mul_func_int16_t_s_s((safe_add_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u((l_3781 = ((safe_sub_func_int32_t_s_s((safe_lshift_func_int16_t_s_u((l_3545 = (safe_lshift_func_int16_t_s_u(5L, 13))), ((safe_lshift_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u((((g_244++) && (((safe_lshift_func_uint16_t_u_u(0UL, 1)) || p_20) ^ p_22)) & g_2935[0]), g_630)), l_3679[5])) & l_3425))), g_595[0])) == g_2205)), g_2447)), p_20)), 0xF255L)) != 0UL) & g_326[1]) != 1L) != p_22), 0x73L)))) || l_3782), 3)) & 255UL) ^ l_3782))) ^ l_3756[4]), 0xCC081419L)) & g_321[0][0][5])))) | l_3671)))), g_2935[0])), p_22)) > g_141), p_21))) | g_2281[2][1]) >= l_3782)), l_3784[0])), l_3782)) ^ g_252[2][6]) & g_252[2][6]) || g_408)));
                        l_3716 |= (safe_add_func_uint32_t_u_u(((g_630 >= ((~(l_3788 = ((0L & (-1L)) & g_2281[2][1]))) >= (g_630 > (safe_lshift_func_int8_t_s_s(p_22, ((((0xCEL | (!((l_3792 |= p_20) != l_3782))) != 4294967286UL) < 7UL) <= l_3781)))))) && (-1L)), 4UL));
                        g_539[4] = 0xDA5CCC56L;
                        if (g_353)
                            continue;
                    }
                    if (l_3782)
                        continue;
g_539[4] ^= 2L;
for (g_189 = 0; (g_189 <= 0); g_189 += 1)
                    {
                        p_22 = (g_1297 = 0x53E61389L);
                    }
                }
            }
            for (g_371 = 0; (g_371 > 47); ++g_371)
            {
                uint32_t l_3800 = 0x5C7CEF5EL;
                int32_t l_3801 = 0x95F02646L;
                int32_t l_3802 = 9L;
                int32_t l_3808[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_3808[i] = 0x886ECA44L;
for (l_3783 = 0; l_3783 < 4; l_3783++)
        {
            transparent_crc(g_2281[i][l_3783], "g_2281[i][l_3783]", g_348);
            if (g_348) printf("index = [%d][%d]\n", i, l_3783);
        };
p_22 = (safe_sub_func_uint32_t_u_u(l_3797, ((safe_sub_func_uint32_t_u_u(0x005037B5L, l_3800)) || ((((((0xA6BCL | l_3800) != p_22) < 0x63A4L) < (l_3801 = (g_370[1] & (p_22 ^ 1UL)))) | 0x3BL) == l_3781))));
                l_3809--;
            }
        }
    }
    else
    {
        uint8_t l_3826 = 2UL;
        p_21 = ((safe_lshift_func_uint8_t_u_s((0xD8L >= (l_3346 < (safe_rshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u(((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u((safe_add_func_int32_t_s_s((((l_3826 || (g_1374 &= (g_317 = (0x5DL != (safe_lshift_func_uint8_t_u_u((!(l_3501 == ((-1L) < g_370[1]))), (safe_sub_func_int8_t_s_s((p_20 = (0x5FE0L ^ 0x6BEFL)), 1L)))))))) <= g_370[4]) ^ g_630), g_326[0])), l_3826)), (-1L))) < l_3613[0]), g_973)) ^ 0UL), 8)))), g_2935[1])) > p_22);
        g_139 = (safe_rshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u(g_151, ((0x379AF9DBL & (((safe_sub_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u(2L, 6)) | 0xCA57L), (g_3 ^ (((l_3826 < (p_21 && ((((((((safe_rshift_func_uint16_t_u_s((p_22 | (((l_3826 != l_3425) < p_21) != l_3844)), 9)) & p_21) <= 0xB791L) ^ g_371) | 0x6112L) | g_252[2][6]) & p_22) | 0x83L))) && p_21) < g_327[2][0])))) < g_370[1]) >= 0x04552B43L)) | g_347))), l_3826)), p_22));
    }
    return l_3613[0];
}
inline static int8_t func_25(uint8_t p_26, uint16_t p_27, int32_t p_28)
{
    int8_t l_47 = 0L;
    int32_t l_3147[4];
    int32_t l_3152[9];
    int32_t l_3162 = 0xD606DA60L;
    int8_t l_3167 = 0xAAL;
    uint32_t l_3234 = 0x1E514D86L;
    int32_t l_3304[6][8][5] = {{{0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}}, {{0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}}, {{0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}}, {{0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}}, {{0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}}, {{0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}, {0xEEA04F0CL, (-3L), 0x974B9946L, 0x0B4C8DAEL, 0x95B201DBL}}};
    int32_t l_3305[5][8] = {{0xFFD75F41L, 1L, 0xBA9BF420L, 0xF869BC43L, 7L, 1L, 7L, 0xF869BC43L}, {0xFFD75F41L, 1L, 0xBA9BF420L, 0xF869BC43L, 7L, 1L, 7L, 0xF869BC43L}, {0xFFD75F41L, 1L, 0xBA9BF420L, 0xF869BC43L, 7L, 1L, 7L, 0xF869BC43L}, {0xFFD75F41L, 1L, 0xBA9BF420L, 0xF869BC43L, 7L, 1L, 7L, 0xF869BC43L}, {0xFFD75F41L, 1L, 0xBA9BF420L, 0xF869BC43L, 7L, 1L, 7L, 0xF869BC43L}};
    int i, j, k;
    for (i = 0; i < 4; i++)
        l_3147[i] = 0xE67C8840L;
    for (i = 0; i < 9; i++)
        l_3152[i] = 6L;
    if ((p_28 = func_42(func_44(l_47, l_47))))
    {
        uint16_t l_3148[1];
        int32_t l_3149 = (-1L);
        int8_t l_3150[7] = {0xC4L, (-4L), 0xC4L, (-4L), 0xC4L, (-4L), 0xC4L};
        uint8_t l_3151 = 255UL;
        int16_t l_3153 = 0x4EBDL;
        int i;
        for (i = 0; i < 1; i++)
            l_3148[i] = 65530UL;
        g_139 = (((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint8_t_u_s((safe_sub_func_uint8_t_u_u(6UL, l_47)), 7)) < ((l_3152[3] = (safe_add_func_uint8_t_u_u(((safe_mul_func_int8_t_s_s((l_3151 = ((safe_rshift_func_int8_t_s_u((safe_mod_func_int32_t_s_s(g_2940[3][3], (+((safe_rshift_func_uint16_t_u_s((safe_mod_func_int8_t_s_s((!((safe_lshift_func_uint8_t_u_u(((((g_595[9] |= (g_252[2][6] |= ((p_27 <= g_327[2][0]) <= (g_348 >= (l_3149 = (l_47 != (p_28 >= (((safe_mul_func_uint16_t_u_u((l_3147[2] &= (safe_add_func_int32_t_s_s(l_47, g_2281[2][1]))), p_26)) < 0x49E2CD40L) < l_3148[0])))))))) || p_28) < 0x2C55L) < 0x3BL), p_26)) < g_1271)), (-10L))), l_3148[0])) ^ g_2205)))), g_370[1])) != l_3150[5])), g_326[4])) != g_326[7]), g_327[3][0]))) ^ l_3153)), p_27)) == g_317) ^ p_26);
        g_139 = g_326[7];
    }
    else
    {
        int8_t l_3157 = 0x6FL;
        int32_t l_3165 = 3L;
        uint8_t l_3166 = 1UL;
        int8_t l_3198 = 0x99L;
        uint32_t l_3212 = 0UL;
        int32_t l_3238[3][3][5] = {{{(-6L), 0xF29A3864L, 0x1F895668L, (-6L), 7L}, {(-6L), 0xF29A3864L, 0x1F895668L, (-6L), 7L}, {(-6L), 0xF29A3864L, 0x1F895668L, (-6L), 7L}}, {{(-6L), 0xF29A3864L, 0x1F895668L, (-6L), 7L}, {(-6L), 0xF29A3864L, 0x1F895668L, (-6L), 7L}, {(-6L), 0xF29A3864L, 0x1F895668L, (-6L), 7L}}, {{(-6L), 0xF29A3864L, 0x1F895668L, (-6L), 7L}, {(-6L), 0xF29A3864L, 0x1F895668L, (-6L), 7L}, {(-6L), 0xF29A3864L, 0x1F895668L, (-6L), 7L}}};
        int32_t l_3265 = 0x3A15E26FL;
        uint8_t l_3281 = 250UL;
        int i, j, k;
        g_539[3] = (0x1DA2L == (safe_add_func_uint32_t_u_u((l_3152[3] = ((((safe_unary_minus_func_uint32_t_u(((g_2447 | ((g_35 &= l_3157) >= ((safe_rshift_func_int8_t_s_s((l_3157 >= (l_3165 |= (safe_mod_func_uint8_t_u_u(((-3L) != ((l_3147[1] > l_3162) && (g_2935[1] &= (p_26 ^ (p_27 = (((safe_mul_func_int16_t_s_s((((((0UL > l_3162) ^ g_1985[1]) <= p_28) | g_321[0][1][8]) > l_3162), 0L)) <= 6L) < 0x86D50268L)))))), p_26)))), 2)) >= 65535UL))) == l_3157))) < p_28) == l_3166) >= g_252[2][6])), l_3167)));
        for (p_28 = 5; (p_28 >= 1); p_28 -= 1)
        {
            uint16_t l_3176 = 65527UL;
            int16_t l_3197 = 0xEB7EL;
            int32_t l_3201 = 0L;
            int32_t l_3236 = 0x4BECF965L;
            int32_t l_3237[1][9] = {{0xED7A4D75L, 0xAE416057L, 0xED7A4D75L, 0xAE416057L, 0xED7A4D75L, 0xAE416057L, 0xED7A4D75L, 0xAE416057L, 0xED7A4D75L}};
            int8_t l_3284 = 8L;
            int i, j;
            for (p_26 = 1; (p_26 <= 5); p_26 += 1)
            {
                int32_t l_3235[1];
                uint32_t l_3239 = 18446744073709551611UL;
                int i;
                for (i = 0; i < 1; i++)
                    l_3235[i] = 0x409C3C7DL;
                if (((((g_2281[2][1] = g_370[p_26]) >= (p_26 != p_27)) != ((g_317 != g_2447) && (safe_lshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((l_3166 == (safe_mul_func_uint16_t_u_u((((safe_add_func_int8_t_s_s(l_3176, (safe_mul_func_int16_t_s_s(0x7979L, (safe_lshift_func_uint16_t_u_s((safe_mul_func_uint16_t_u_u(l_47, l_3147[3])), l_3165)))))) && l_3152[3]) != p_28), p_27))) ^ p_27), 0xE468L)), p_27)))) != g_370[p_26]))
                {
                    g_539[4] ^= l_47;
                }
                else
                {
                    l_3147[0] = (safe_mod_func_uint16_t_u_u(((g_328 && (safe_sub_func_uint32_t_u_u(((l_3176 ^ (!(p_26 ^ (safe_add_func_uint8_t_u_u((g_349 > (0L | (7L | (g_2037 > (safe_add_func_int8_t_s_s(((~((((safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(p_27, 8)), l_3197)) <= g_1374) || l_3198) > (-5L))) < 0x35CBL), 9UL)))))), l_3147[3]))))) != 4294967294UL), 0xAAFD55BEL))) | g_370[p_26]), p_28));
                    l_3147[1] = (safe_rshift_func_uint8_t_u_s((g_370[p_26] < ((l_3201 ^= (0L | (l_3152[3] = p_28))) >= (~(g_206--)))), 4));
                }
                if (g_973)
                    continue;
                for (g_347 = 5; (g_347 >= 0); g_347 -= 1)
                {
                    int32_t l_3233[10] = {(-3L), (-1L), 0x16D211A9L, 0x16D211A9L, (-1L), (-3L), (-1L), 0x16D211A9L, 0x16D211A9L, (-1L)};
                    int i;
                    l_3201 ^= (1L ^ 0x85L);
                    l_3165 = ((safe_mul_func_int16_t_s_s(0xCFE9L, (((safe_add_func_uint8_t_u_u((g_595[p_28] = 0x5DL), (~(g_347 >= g_326[7])))) == (((p_28 != ((g_35 = 7UL) ^ p_26)) >= ((g_370[p_26] & (((safe_rshift_func_int16_t_s_u(((((((0x2C2192B5L == l_3212) > 8L) || (-1L)) <= (-1L)) & 0x09L) < g_1442), 11)) || 1L) < 0x8AL)) ^ 0x38A8L)) >= l_3157)) < 0xCB27L))) && p_26);
                    for (l_3166 = 0; (l_3166 <= 5); l_3166 += 1)
                    {
                        int8_t l_3226[1][3];
                        int i, j;
                        for (i = 0; i < 1; i++)
                        {
                            for (j = 0; j < 3; j++)
                                l_3226[i][j] = (-1L);
                        }
                        g_539[2] = (p_27 & 0L);
                        g_2205 &= (safe_add_func_uint16_t_u_u(0xD128L, (l_3197 >= (g_407 < (safe_rshift_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((safe_unary_minus_func_uint32_t_u(((safe_lshift_func_int8_t_s_u((safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(((l_3226[0][2] ^ (l_3165 = ((safe_rshift_func_uint8_t_u_s((((g_202 = 0x80E2L) ^ (safe_rshift_func_int8_t_s_u((g_370[p_26] >= ((g_1442 == 0xFFB4L) < ((l_3233[5] = (safe_add_func_int8_t_s_s(((p_27 >= 255UL) < 65535UL), 0x70L))) | 0xDC6EL))), p_27))) <= g_139), l_3234)) || 0x44L))) >= (-10L)), 14)), 0xE5337C48L)), g_595[p_28])) || g_370[p_26]))) < 0x5CL), p_28)), 5))))));
                    }
                    --l_3239;
                }
                if (((g_1271 = l_3162) > (safe_sub_func_int16_t_s_s((((p_26 & ((p_26 != (0xED30L <= (safe_lshift_func_uint8_t_u_u(0x5FL, 7)))) && (safe_rshift_func_uint8_t_u_u(((((safe_lshift_func_int8_t_s_u(((safe_mod_func_int16_t_s_s(0xB563L, ((safe_rshift_func_uint8_t_u_u(0xD7L, 6)) ^ (l_3265 &= (safe_lshift_func_int8_t_s_u((((((l_3237[0][1] <= ((safe_mul_func_uint8_t_u_u((+((((safe_lshift_func_int8_t_s_u(((((safe_mul_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(g_352, 255UL)) == 0UL), g_2281[7][3])) < g_332) < g_973) < g_2447), 1)) || p_28) >= 0x4A10L) && g_2281[0][2])), l_3236)) < p_28)) <= 0x3BFB6AB9L) >= g_2414) < l_3235[0]) | l_3235[0]), 4)))))) && p_28), l_3235[0])) >= g_770) ^ 0xFBA5L) > g_769), l_3235[0])))) && g_2935[2]) || 0xE5L), l_3198))))
                {
                    int8_t l_3274 = (-7L);
                    int32_t l_3275 = (-2L);
                    int32_t l_3279[5];
                    int i;
                    for (i = 0; i < 5; i++)
                        l_3279[i] = 0xD5C3A27AL;
                    for (g_973 = 1; (g_973 <= 5); g_973 += 1)
                    {
                        uint8_t l_3276 = 255UL;
                        l_3235[0] = (l_3238[2][2][4] <= (~((g_244 != (g_1374 != l_3237[0][1])) != (~((1UL && (((safe_mod_func_uint16_t_u_u(p_26, 0x85E5L)) | g_244) > (((safe_rshift_func_int16_t_s_s(((safe_sub_func_int32_t_s_s(p_26, p_28)) && 0x81100BC0L), 0)) | l_3166) <= l_3274))) | 0xE8DDL)))));
                        if (g_332)
                            continue;
                        ++l_3276;
                        if (l_3176)
                            {
for (g_317 = 0; (g_317 == 28); g_317 = safe_add_func_uint16_t_u_u(g_317, 4))
                {
                    int16_t l_3572 = 0x2110L;
                    for (g_347 = (-23); (g_347 != (-17)); g_347 = safe_add_func_uint16_t_u_u(g_347, 3))
                    {
                        l_3201 &= l_3198;
                    }
                    g_35--;
                    l_3265 = l_3201;
                    l_3265 = (-4L);
                };
break;}
                    }
                    l_3275 ^= 0x12EA8682L;
                    for (l_3234 = 0; (l_3234 <= 3); l_3234 += 1)
                    {
                        int32_t l_3280[8] = {0x1AFA9DCFL, 0x1AFA9DCFL, 0x9F3165B0L, 0x1AFA9DCFL, 0x1AFA9DCFL, 0x9F3165B0L, 0x1AFA9DCFL, 0x1AFA9DCFL};
                        int i;
                        --l_3281;
                        return g_595[(p_26 + 1)];
                    }
                }
                else
                {
                    for (l_3236 = 3; (l_3236 >= 0); l_3236 -= 1)
                    {
                        int i, j;
                        g_139 ^= g_252[l_3236][p_26];
                    }
                    l_3284 = 0x2307333BL;
                }
            }
            l_3201 = 0L;
            l_3237[0][7] = 0x033D0BF8L;
if (p_28) printf("index = [%d]\n", g_630);
l_3236 = (g_206 <= p_27);
        }
    }
    g_352 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_s((0xC6C1BF4DL <= 0xB9F2CFB6L), 14)), 6));
    l_3305[0][7] = (((65529UL ^ (g_1985[5] = 7L)) | (0L <= (safe_add_func_uint16_t_u_u(p_28, ((safe_rshift_func_int8_t_s_u(p_26, (safe_rshift_func_int8_t_s_s((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u(((safe_add_func_uint32_t_u_u((l_3152[3] |= 0x00FE4291L), l_47)) || (l_3304[2][3][1] = (~(l_3147[0] &= ((((l_3152[3] |= (0x4E33L || ((safe_lshift_func_int16_t_s_u(g_139, 11)) && 7L))) | g_189) && 0x643F99B1L) == l_3167))))), g_206)), 0x21L)), l_3234)))) > g_328))))) | g_1374);
    g_352 = (safe_add_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(((+p_28) > (g_3311 != (safe_lshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(((l_3305[0][7] = g_317) && (safe_unary_minus_func_int16_t_s(((safe_sub_func_uint32_t_u_u((g_244 = (g_206--)), 6L)) || (l_3167 <= 0x8D1BL))))), 6)), 13)))), (safe_mul_func_int8_t_s_s((((safe_rshift_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((+((p_26 < 4294967292UL) > (0x30L && p_26))), l_3167)), 0)) & (-8L)) == p_27), l_3152[2])))), g_370[0]));
    return l_3167;
}
static int32_t func_42(uint8_t p_43)
{
    int32_t l_68[4][8] = {{0xC6E20B39L, 0xF74462D1L, 0xC6E20B39L, 0xF74462D1L, 0xC6E20B39L, 0xF74462D1L, 0xC6E20B39L, 0xF74462D1L}, {0xC6E20B39L, 0xF74462D1L, 0xC6E20B39L, 0xF74462D1L, 0xC6E20B39L, 0xF74462D1L, 0xC6E20B39L, 0xF74462D1L}, {0xC6E20B39L, 0xF74462D1L, 0xC6E20B39L, 0xF74462D1L, 0xC6E20B39L, 0xF74462D1L, 0xC6E20B39L, 0xF74462D1L}, {0xC6E20B39L, 0xF74462D1L, 0xC6E20B39L, 0xF74462D1L, 0xC6E20B39L, 0xF74462D1L, 0xC6E20B39L, 0xF74462D1L}};
    int32_t l_79[9][7][4] = {{{5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}}, {{5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}}, {{5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}}, {{5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}}, {{5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}}, {{5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}}, {{5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}}, {{5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}}, {{5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}, {5L, 0L, 0xAD406D4EL, 0x51D4F00DL}}};
    int32_t l_2933 = 0x482321A5L;
    int32_t l_2934 = 0x6778DE9BL;
    int32_t l_2936 = 0xC2EFA380L;
    uint8_t l_2949[9] = {0xCDL, 0xCDL, 8UL, 0xCDL, 0xCDL, 8UL, 0xCDL, 0xCDL, 8UL};
    uint32_t l_2968 = 1UL;
    int32_t l_2973 = 0x0463F3BEL;
    int32_t l_3013 = 0x386E66E9L;
    uint16_t l_3118 = 65529UL;
    int i, j, k;
    if ((safe_add_func_int8_t_s_s(((func_44((safe_rshift_func_uint16_t_u_s(((safe_add_func_int8_t_s_s(g_35, (((safe_lshift_func_uint8_t_u_s((5UL <= func_44((safe_add_func_int32_t_s_s(p_43, (safe_sub_func_int16_t_s_s((l_68[3][7] = p_43), ((safe_mul_func_uint8_t_u_u((func_44((safe_mul_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u((safe_mul_func_int8_t_s_s((func_77(l_79[4][3][3]) >= ((0xECD14699L && (0x61B6C80DL == (~(safe_mod_func_uint8_t_u_u((g_2935[0] = ((l_2934 |= (safe_lshift_func_uint8_t_u_u(((l_2933 &= (safe_unary_minus_func_int16_t_s(0x82C1L))) < g_630), g_35))) <= p_43)), 0x99L))))) ^ 0xFACBF2A3L)), l_79[4][3][3])), l_79[6][5][3])), 1UL)), l_2936) && g_151), l_79[3][6][1])) <= 1L))))), g_35)), p_43)) || l_2934) > 1UL))) == l_79[7][6][0]), g_630)), g_35) | 0x3422L) && (-9L)), l_79[4][3][3])))
    {
        int32_t l_2937 = 1L;
        int32_t l_2938 = 1L;
        int32_t l_2939 = 0x3572CB92L;
        int32_t l_2941 = 0x7E652204L;
        int32_t l_2942 = 1L;
        int32_t l_2943 = 0x04EFE9B0L;
        int16_t l_2944 = 1L;
        int32_t l_2945 = 0x671156B3L;
        int32_t l_2946 = 1L;
        int32_t l_2947 = (-6L);
        int32_t l_2948[3][1][7] = {{{0L, (-1L), 0xF9A0E1FFL, (-1L), 0L, 0xFB74DC25L, 0L}}, {{0L, (-1L), 0xF9A0E1FFL, (-1L), 0L, 0xFB74DC25L, 0L}}, {{0L, (-1L), 0xF9A0E1FFL, (-1L), 0L, 0xFB74DC25L, 0L}}};
        int8_t l_2967 = 0x76L;
        int i, j, k;
        l_79[4][3][3] = ((-1L) == (l_2934 = g_353));
        --l_2949[5];
        g_352 = (l_2933 ^ ((-2L) && ((safe_sub_func_int16_t_s_s(((((((safe_sub_func_uint32_t_u_u(g_348, ((safe_add_func_int16_t_s_s(l_2939, ((-10L) <= (((safe_mod_func_uint32_t_u_u(((((-1L) | (safe_mul_func_int8_t_s_s(g_2281[2][1], ((((safe_lshift_func_int8_t_s_s(((!l_2934) != (((l_2936 = (g_252[2][6] |= (safe_add_func_int8_t_s_s(g_321[0][1][8], p_43)))) >= l_2937) != g_244)), 0)) <= p_43) <= g_326[0]) | l_2967)))) & (-1L)) && g_407), g_2447)) != l_2968) >= p_43)))) || l_79[6][1][0]))) || p_43) != l_68[3][7]) && g_371) ^ 1UL) == g_353), 65535UL)) >= g_2281[6][0])));
        g_1297 = (safe_mul_func_uint16_t_u_u(((safe_add_func_uint16_t_u_u(0x484CL, l_2941)) >= 0x26B971C8L), l_2973));
    }
    else
    {
        int32_t l_2975 = 0x7CD20DD5L;
        int32_t l_2977 = 0x50B93C98L;
        int32_t l_2980 = 5L;
        int32_t l_2981 = 1L;
        int32_t l_2982 = 3L;
        int32_t l_2983 = 0xFD10FB09L;
        int32_t l_2984[4][6] = {{0xB604F351L, 1L, 0xB604F351L, 1L, 0xB604F351L, 1L}, {0xB604F351L, 1L, 0xB604F351L, 1L, 0xB604F351L, 1L}, {0xB604F351L, 1L, 0xB604F351L, 1L, 0xB604F351L, 1L}, {0xB604F351L, 1L, 0xB604F351L, 1L, 0xB604F351L, 1L}};
        uint16_t l_2987 = 0xE6FAL;
        uint16_t l_3088 = 9UL;
        int i, j;
        for (g_203 = 0; (g_203 <= 7); g_203 += 1)
        {
            int8_t l_2974[1];
            int32_t l_2978[5] = {0x94BDD908L, (-1L), 0x94BDD908L, (-1L), 0x94BDD908L};
            int32_t l_3062[5][8][6] = {{{(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}}, {{(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}}, {{(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}}, {{(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}}, {{(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}, {(-1L), 1L, 0L, 0x778B47F2L, 1L, (-9L)}}};
            int8_t l_3073[1];
            int32_t l_3079 = 0L;
            int i, j, k;
            for (i = 0; i < 1; i++)
                l_2974[i] = 7L;
g_3893 |= 4294967292UL;
for (i = 0; i < 1; i++)
                l_3073[i] = 0L;
            for (l_2973 = 3; (l_2973 >= 0); l_2973 -= 1)
            {
                int8_t l_2976 = (-1L);
                int32_t l_2979 = 0x5718FE15L;
                int32_t l_2985 = 1L;
                int32_t l_2986[9] = {(-1L), 0xB0E8D0C6L, (-1L), 0xB0E8D0C6L, (-1L), 0xB0E8D0C6L, (-1L), 0xB0E8D0C6L, (-1L)};
                int32_t l_3061[6] = {(-5L), (-6L), (-5L), (-6L), (-5L), (-6L)};
                int8_t l_3080 = 0L;
                int16_t l_3087 = (-1L);
                int i;
                l_2987--;
                l_2979 ^= (safe_lshift_func_int16_t_s_u(g_595[(l_2973 + 2)], ((safe_mul_func_int8_t_s_s(0x59L, ((safe_mod_func_uint32_t_u_u((~(safe_lshift_func_int16_t_s_u(((safe_rshift_func_int16_t_s_s((safe_sub_func_uint16_t_u_u(0xFA0DL, g_595[(l_2973 + 3)])), (safe_rshift_func_int8_t_s_u((((((((g_139 = (((safe_add_func_uint8_t_u_u(((safe_add_func_uint16_t_u_u(l_2978[0], (l_2985 |= l_2986[4]))) == p_43), (++g_2935[0]))) | (safe_rshift_func_uint8_t_u_s((((l_2983 = g_327[3][0]) == ((4294967287UL & g_1271) <= p_43)) && 0x2B05EA33L), 6))) == 0x9A02L)) || p_43) && p_43) ^ (-3L)) || l_3013) <= g_595[5]) >= g_1297), g_539[2])))) < l_2976), g_371))), p_43)) || p_43))) | 7L)));
if (l_2980)
                    break;
g_352 = p_43;
                if ((safe_mod_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((safe_add_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((safe_add_func_int32_t_s_s((((g_408 ^ ((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u(((l_3013 = 0x80L) < l_2985), g_770)), (l_2979 = (g_326[g_203] = ((0x5D3BL ^ (safe_sub_func_uint16_t_u_u(65535UL, ((g_348 >= (p_43 > (safe_mul_func_int16_t_s_s(((((g_332 || p_43) != l_2986[2]) < 0x7CABL) < g_769), p_43)))) > p_43)))) && 0x279296E0L))))) && g_595[(l_2973 + 3)])) ^ p_43) || g_347), l_2974[0])), 1L)), l_2975)), g_189)), g_353)))
                {
                    int8_t l_3048 = (-1L);
                    int32_t l_3067 = (-2L);
                    int32_t l_3068 = 0x31C674C6L;
                    int32_t l_3069 = 0x8491C0BDL;
                    int32_t l_3070 = 0x22495ADAL;
                    int32_t l_3071 = 0x11EEB853L;
                    int32_t l_3075 = (-1L);
                    int32_t l_3076 = 0xD6B830CBL;
                    int32_t l_3077[9][6] = {{0xEE57CBA1L, 1L, 0x2C9718DBL, 0x4207CBFEL, 1L, 1L}, {0xEE57CBA1L, 1L, 0x2C9718DBL, 0x4207CBFEL, 1L, 1L}, {0xEE57CBA1L, 1L, 0x2C9718DBL, 0x4207CBFEL, 1L, 1L}, {0xEE57CBA1L, 1L, 0x2C9718DBL, 0x4207CBFEL, 1L, 1L}, {0xEE57CBA1L, 1L, 0x2C9718DBL, 0x4207CBFEL, 1L, 1L}, {0xEE57CBA1L, 1L, 0x2C9718DBL, 0x4207CBFEL, 1L, 1L}, {0xEE57CBA1L, 1L, 0x2C9718DBL, 0x4207CBFEL, 1L, 1L}, {0xEE57CBA1L, 1L, 0x2C9718DBL, 0x4207CBFEL, 1L, 1L}, {0xEE57CBA1L, 1L, 0x2C9718DBL, 0x4207CBFEL, 1L, 1L}};
                    uint32_t l_3082 = 18446744073709551615UL;
                    int i, j;
                    l_2978[0] &= (((g_189 >= ((+((g_2205 = (g_139 |= (!p_43))) < (safe_mul_func_int8_t_s_s(5L, (((p_43 > (((safe_rshift_func_uint8_t_u_u((safe_add_func_uint16_t_u_u(((!(((safe_rshift_func_int8_t_s_u(l_2975, (safe_unary_minus_func_int16_t_s((safe_mod_func_uint32_t_u_u(0x7410DB83L, g_539[3])))))) == (((safe_add_func_uint16_t_u_u(g_2037, (l_2979 & g_770))) == l_3048) != p_43)) == g_252[2][6])) && p_43), p_43)), g_317)) < g_1271) > 0x1467F207L)) || g_539[4]) & 0xF7L))))) == p_43)) > g_370[5]) >= g_1985[5]);
                    for (g_348 = 0; (g_348 <= 3); g_348 += 1)
                    {
                        int32_t l_3063 = 0xC8E0421CL;
                        int32_t l_3064 = 0L;
                        int32_t l_3065 = (-1L);
                        int32_t l_3066 = 0x6D95C101L;
                        int32_t l_3072 = 0x88F102C0L;
                        int32_t l_3074 = 0x7335BFEAL;
                        int32_t l_3078 = 2L;
                        int32_t l_3081[3][6][5] = {{{0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}}, {{0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}}, {{0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}, {0x74E8EBEAL, (-1L), 0x74E8EBEAL, (-1L), 0xDC22C5F3L}}};
                        int i, j, k;
                        l_3062[2][1][1] &= ((((safe_mod_func_int8_t_s_s(l_79[(l_2973 + 2)][l_2973][l_2973], (safe_add_func_int16_t_s_s(1L, 0x47F8L)))) & (safe_add_func_int8_t_s_s(((l_2979 = (safe_sub_func_uint32_t_u_u(((g_202 & p_43) != ((g_1374 = ((g_1374 != g_2940[8][5]) < ((safe_sub_func_uint32_t_u_u((safe_mul_func_int16_t_s_s(0L, ((65533UL | 5UL) | l_2978[1]))), l_2980)) == l_3061[4]))) <= 0xBAL)), g_326[4]))) | 0x35592BB1L), g_244))) && g_2414) != g_317);
                        l_3082--;
                    }
                    for (g_2447 = 0; (g_2447 != 17); g_2447 = safe_add_func_int8_t_s_s(g_2447, 7))
                    {
                        if (p_43)
                            break;
                        l_3088--;
                    }
                }
                else
                {
                    uint32_t l_3091 = 1UL;
                    if (l_3091)
                        break;
                }
            }
        }
        for (l_2968 = (-20); (l_2968 >= 25); l_2968++)
        {
            uint16_t l_3094[10] = {65535UL, 65535UL, 0xF166L, 65535UL, 65535UL, 0xF166L, 65535UL, 65535UL, 0xF166L, 65535UL};
            uint32_t l_3109 = 18446744073709551613UL;
            int i;
            l_2982 = ((65531UL > ((l_3094[6] ^ (safe_add_func_uint16_t_u_u(g_347, g_203))) != (++g_2037))) | (safe_add_func_int16_t_s_s((0x789CL == (p_43 | (safe_sub_func_uint8_t_u_u(((safe_mul_func_int16_t_s_s((safe_mod_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((g_321[0][1][8] < p_43), 3)) || (l_3109 = p_43)), g_252[2][6])), 65527UL)) || p_43), p_43)))), l_68[0][2])));
        }
    }
    l_2934 &= ((((((g_2037 ^= p_43) ^ (g_2281[2][1] || p_43)) || (p_43 >= (p_43 & g_973))) != (safe_rshift_func_int8_t_s_u((l_2933 |= (safe_rshift_func_uint8_t_u_s((safe_mul_func_uint8_t_u_u(l_2936, ((safe_lshift_func_uint16_t_u_s(p_43, 3)) == (4294967289UL == p_43)))), 7))), g_352))) ^ g_1297) ^ l_2973);
    l_3118++;
    g_539[6] = l_68[3][7];
    return g_326[2];
}
inline static uint8_t func_44(int32_t p_45, int32_t p_46)
{
    int32_t l_50 = 0x280DDA25L;
    p_45 = ((safe_rshift_func_uint8_t_u_u(0x4CL, 2)) != 0x9A01L);
    l_50 &= 1L;
    p_45 = 0x3DEE6EE3L;
    for (p_45 = 18; (p_45 > (-26)); p_45--)
    {
        uint8_t l_53 = 5UL;
        if (p_46)
            break;
        l_53++;
    }
    return g_35;
}
inline static uint16_t func_77(int16_t p_78)
{
    int32_t l_81 = 5L;
    int32_t l_83 = 0x368EC64CL;
    int32_t l_1315[9][1] = {{0xD33787ACL}, {0xD33787ACL}, {0xD33787ACL}, {0xD33787ACL}, {0xD33787ACL}, {0xD33787ACL}, {0xD33787ACL}, {0xD33787ACL}, {0xD33787ACL}};
    int8_t l_1375 = 0L;
    uint32_t l_1445 = 0UL;
    int16_t l_1584[3][9][9] = {{{0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}}, {{0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}}, {{0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}, {0x4871L, (-1L), (-8L), 0L, 0x1476L, 0x23A9L, 0L, (-1L), (-1L)}}};
    uint32_t l_1720 = 0x92AD4DBAL;
    int32_t l_1771 = 0xC70B84B0L;
    int32_t l_1772 = 0L;
    int16_t l_1774 = 0xB01BL;
    int16_t l_1787 = 0xC496L;
    uint32_t l_2083 = 0x9A983AECL;
    uint16_t l_2158 = 65527UL;
    int8_t l_2175 = 1L;
    int32_t l_2195 = 1L;
    uint8_t l_2201 = 0x29L;
    int8_t l_2253 = 0x4FL;
    int8_t l_2318 = 0xE7L;
    uint16_t l_2319 = 0x6CE7L;
    int8_t l_2360 = 0xA4L;
    int8_t l_2388 = 0x02L;
    int32_t l_2597 = 0x35058B13L;
    int16_t l_2598 = (-3L);
    uint32_t l_2600[9][1][8] = {{{0x3C0B4BCAL, 4294967295UL, 4294967295UL, 0xF74F336AL, 0x27C01B3EL, 4294967295UL, 0x27C01B3EL, 0xF74F336AL}}, {{0x3C0B4BCAL, 4294967295UL, 4294967295UL, 0xF74F336AL, 0x27C01B3EL, 4294967295UL, 0x27C01B3EL, 0xF74F336AL}}, {{0x3C0B4BCAL, 4294967295UL, 4294967295UL, 0xF74F336AL, 0x27C01B3EL, 4294967295UL, 0x27C01B3EL, 0xF74F336AL}}, {{0x3C0B4BCAL, 4294967295UL, 4294967295UL, 0xF74F336AL, 0x27C01B3EL, 4294967295UL, 0x27C01B3EL, 0xF74F336AL}}, {{0x3C0B4BCAL, 4294967295UL, 4294967295UL, 0xF74F336AL, 0x27C01B3EL, 4294967295UL, 0x27C01B3EL, 0xF74F336AL}}, {{0x3C0B4BCAL, 4294967295UL, 4294967295UL, 0xF74F336AL, 0x27C01B3EL, 4294967295UL, 0x27C01B3EL, 0xF74F336AL}}, {{0x3C0B4BCAL, 4294967295UL, 4294967295UL, 0xF74F336AL, 0x27C01B3EL, 4294967295UL, 0x27C01B3EL, 0xF74F336AL}}, {{0x3C0B4BCAL, 4294967295UL, 4294967295UL, 0xF74F336AL, 0x27C01B3EL, 4294967295UL, 0x27C01B3EL, 0xF74F336AL}}, {{0x3C0B4BCAL, 4294967295UL, 4294967295UL, 0xF74F336AL, 0x27C01B3EL, 4294967295UL, 0x27C01B3EL, 0xF74F336AL}}};
    int16_t l_2670 = 0L;
    int16_t l_2832 = 0x9FF2L;
    int i, j, k;
    if ((+p_78))
    {
        int8_t l_82 = 0x97L;
        int32_t l_97 = 1L;
        int32_t l_1274 = 0L;
        l_82 = (l_81 > l_81);
        l_83 = l_81;
        for (l_83 = (-21); (l_83 <= 28); l_83++)
        {
            uint8_t l_1277 = 0x1EL;
            uint32_t l_1285 = 18446744073709551610UL;
            int32_t l_1288 = 0xCCAB0AE4L;
            int32_t l_1298 = (-1L);
g_189 &= 1L;
if ((((safe_rshift_func_int8_t_s_u(func_44((((0xBE7BL & (safe_add_func_uint8_t_u_u(p_78, (((safe_mod_func_int32_t_s_s(l_83, 4294967292UL)) <= 9UL) < (safe_mod_func_uint8_t_u_u((g_1271 &= func_94(g_3, l_97)), (safe_lshift_func_int16_t_s_u((l_1274 ^= 0xB1A0L), g_595[7])))))))) | 0L) != p_78), p_78), 7)) < p_78) && 0x8AL))
            {
                uint8_t l_1276 = 0x06L;
                l_1276 = (+l_83);
                l_1277 = g_371;
            }
            else
            {
                int8_t l_1296 = 0xAEL;
                if (g_770)
                    break;
                for (g_141 = (-18); (g_141 > 35); ++g_141)
                {
                    uint32_t l_1303 = 18446744073709551615UL;
                    g_539[4] &= (l_1298 = (safe_rshift_func_int16_t_s_s(((~g_1271) >= 0x56D81513L), (g_1297 = (safe_add_func_uint32_t_u_u(g_202, (l_1285 > (safe_add_func_uint8_t_u_u((g_151 = ((l_1288 = l_1277) < (safe_unary_minus_func_int8_t_s((safe_rshift_func_uint16_t_u_u(((0x0A6499CCL == (l_1277 > (((safe_sub_func_int32_t_s_s(((safe_sub_func_uint16_t_u_u(g_321[0][1][8], (p_78 = ((0L != p_78) || p_78)))) != 0x24DDD47AL), l_1274)) <= l_97) & l_1296))) != l_81), 0)))))), g_408)))))))));
                    l_1315[7][0] ^= (safe_mod_func_uint8_t_u_u((safe_mod_func_int32_t_s_s(g_407, l_1303)), (0xECL || ((-1L) != (safe_rshift_func_uint8_t_u_s(((safe_rshift_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s(l_1303, 1)), 7)) & (!((l_1298 = (p_78 == (((g_321[0][1][8] != ((((safe_lshift_func_int16_t_s_u(g_252[2][6], 4)) & 0UL) < p_78) && g_151)) | 0x6BAED322L) != p_78))) >= l_1277))), g_1271))))));
                }
                l_97 = (l_1274 = (p_78 < (safe_sub_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_u((((~(((safe_add_func_int16_t_s_s((!(((safe_mod_func_int16_t_s_s(((((safe_lshift_func_int8_t_s_s((p_78 <= (l_1288 = (g_328 == p_78))), (p_78 | ((safe_unary_minus_func_uint32_t_u(g_370[1])) >= ((((safe_lshift_func_int16_t_s_u(l_1315[5][0], 7)) || (safe_mul_func_uint16_t_u_u(g_252[2][5], g_408))) != p_78) & l_1274))))) < p_78) & l_81) > 0x3D9FL), p_78)) & l_1296) >= g_252[2][2])), g_973)) && g_370[4]) == l_1296)) != 0x5FL) ^ g_139), l_1296)) || 0x329AD08EL), 0x63L))));
                l_1288 = 0x32DA00A3L;
            }
        }
    }
    else
    {
        int32_t l_1350 = 0x0B449751L;
        int32_t l_1351 = 0x6DF18F5DL;
        int32_t l_1361 = 0x89834F0CL;
        int16_t l_1364 = 0x870FL;
        int32_t l_1366 = (-1L);
        int32_t l_1368[2];
        uint32_t l_1369[8][6] = {{0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL}, {0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL}, {0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL}, {0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL}, {0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL}, {0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL}, {0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL}, {0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL, 0x9433471CL, 0xBCA407ECL}};
        int32_t l_1443[8][6][5] = {{{0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}}, {{0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}}, {{0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}}, {{0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}}, {{0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}}, {{0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}}, {{0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}}, {{0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}, {0x993967BEL, 0xF6856EA2L, 0xEC11EF70L, 0xF46B3D2AL, 0x68E8340AL}}};
        int8_t l_1536[5][8][6] = {{{4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}}, {{4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}}, {{4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}}, {{4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}}, {{4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}, {4L, 0x05L, 0xB8L, 0xAFL, 5L, 0xFDL}}};
        uint16_t l_1604[7];
        int16_t l_1679 = 0x9F7DL;
        uint32_t l_1695 = 0x2425D7F3L;
        uint32_t l_1747[6];
        int32_t l_1770 = 1L;
        int32_t l_1783 = 0L;
        int8_t l_1927 = 0x89L;
        uint32_t l_2111 = 0x8FF326D3L;
        int i, j, k;
        for (i = 0; i < 2; i++)
            l_1368[i] = 0x44A40841L;
        for (i = 0; i < 7; i++)
            l_1604[i] = 65531UL;
        for (i = 0; i < 6; i++)
            l_1747[i] = 18446744073709551608UL;
        for (g_407 = 0; (g_407 != 38); g_407 = safe_add_func_int16_t_s_s(g_407, 3))
        {
            uint8_t l_1349[2][5] = {{0xACL, 255UL, 0xABL, 0xABL, 255UL}, {0xACL, 255UL, 0xABL, 0xABL, 255UL}};
            int32_t l_1354 = 0xE74996D7L;
            int32_t l_1358 = 0x28F68523L;
            int32_t l_1360 = 0x4CE51867L;
            int32_t l_1362[7] = {1L, 1L, 1L, 1L, 1L, 1L, 1L};
            int32_t l_1603 = 0x2E126FCCL;
            int i, j;
            if (((((safe_mul_func_int16_t_s_s((((l_1350 = (safe_add_func_uint8_t_u_u((g_326[2] > (((p_78 <= g_630) && ((safe_lshift_func_uint8_t_u_u(0UL, (safe_add_func_uint16_t_u_u((safe_mul_func_int16_t_s_s((l_81 ^ (p_78 ^ (g_206 < (safe_mod_func_int16_t_s_s((((((((g_244 = 1UL) ^ (safe_add_func_int32_t_s_s((g_327[3][0] > p_78), 0xCE22E61EL))) >= l_1349[0][2]) & 0xA9L) | 0x2FL) > 255UL) != p_78), p_78))))), l_1350)), l_1349[0][4])))) & p_78)) ^ p_78)), (-1L)))) >= g_407) && l_1315[7][0]), l_1349[0][2])) < 0L) == l_1351) == (-8L)))
            {
                int32_t l_1355 = 5L;
                int32_t l_1356 = 0xEBEE0127L;
                int32_t l_1357 = 0x3784E073L;
                int32_t l_1359 = 0L;
                int32_t l_1363 = 8L;
                int32_t l_1365 = 3L;
                int32_t l_1367[4] = {0x24A33BDFL, 0x5E6EE466L, 0x24A33BDFL, 0x5E6EE466L};
                int32_t l_1437 = 8L;
                int8_t l_1440 = (-1L);
                uint32_t l_1458 = 0xC705A14AL;
                int i;
                l_1354 = (safe_mul_func_int16_t_s_s((p_78 < 7UL), 0xD36AL));
                l_1369[2][5]--;
                if ((l_1375 = (safe_mod_func_int16_t_s_s((g_408 &= g_1374), p_78))))
                {
                    uint8_t l_1376 = 0UL;
                    int32_t l_1429[2];
                    int32_t l_1434 = 1L;
                    int32_t l_1435 = 0xFCBD2065L;
                    int32_t l_1436 = (-8L);
                    int32_t l_1438 = 7L;
                    int32_t l_1439 = 9L;
                    int32_t l_1441 = (-1L);
                    int32_t l_1444 = 0x3FF1D380L;
                    int i;
                    for (i = 0; i < 2; i++)
                        l_1429[i] = (-1L);
                    l_1363 = ((l_1376 = l_1366) >= (safe_rshift_func_uint16_t_u_s(g_141, 0)));
                    for (g_244 = 0; (g_244 > 55); g_244 = safe_add_func_int32_t_s_s(g_244, 6))
                    {
                        int32_t l_1409 = 0x00759AFCL;
                        int32_t l_1410 = 0L;
                        int32_t l_1411 = 0xA8E903BAL;
                        l_1411 = (g_1297 = ((l_1410 = ((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s(0x3CEDL, 14)), (safe_add_func_uint32_t_u_u(g_769, (safe_sub_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_s(g_327[1][0], 2)) || (((safe_rshift_func_uint8_t_u_u((safe_mod_func_int32_t_s_s((safe_sub_func_int32_t_s_s(((((g_408 = l_1358) || (((((g_770 > p_78) && (safe_mul_func_int16_t_s_s((safe_mul_func_uint16_t_u_u((safe_sub_func_int32_t_s_s(p_78, 2UL)), (safe_mod_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s((p_78 ^ l_1358), g_141)), g_769)))), 0xB434L))) == 0xBCB2L) & (-1L)) <= l_1376)) <= p_78) ^ l_1375), l_1368[1])), 0x87684D95L)), 5)) == p_78) || l_1361)), g_244)))))), l_1409)) > g_539[4])) | p_78));
                    }
                    if ((safe_mod_func_int16_t_s_s((safe_sub_func_int32_t_s_s((0x9DL < (((250UL < (0x5B9DL | (safe_sub_func_uint8_t_u_u(l_1357, (l_1356 &= (((~g_151) & (safe_add_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(g_252[1][4], p_78)), ((safe_add_func_uint32_t_u_u((safe_rshift_func_int8_t_s_u(((l_1358 = 0x6AB19D90L) != (safe_mul_func_int16_t_s_s(g_244, g_3))), p_78)), l_1367[1])) & 0xC3L)))) & p_78)))))) ^ l_1375) < l_1429[0])), 0x64D73401L)), (-8L))))
                    {
                        uint16_t l_1430 = 65531UL;
                        int32_t l_1433[6];
                        int32_t l_1454[1][7];
                        int i, j;
                        for (i = 0; i < 6; i++)
                            l_1433[i] = 9L;
g_139 &= l_1367[l_1770];
for (i = 0; i < 1; i++)
                        {
                            for (j = 0; j < 7; j++)
                                l_1454[i][j] = 0x50C4CE3BL;
                        }
                        l_1430++;
                        ++l_1445;
                        l_1454[0][6] &= (safe_mod_func_int32_t_s_s((65535UL <= (safe_add_func_uint8_t_u_u((++g_769), ((g_1374 = g_511) >= 0x16L)))), 0xC54C606FL));
                    }
                    else
                    {
                        if (p_78)
                            break;
                        return l_1436;
                    }
                    if (((g_408 = p_78) >= 0x5BC0L))
                    {
                        l_83 = l_1349[1][1];
                        return g_327[3][0];
                    }
                    else
                    {
                        int8_t l_1457 = 0xD7L;
                        l_1457 |= (((safe_rshift_func_uint16_t_u_u(p_78, 12)) <= p_78) || 6UL);
                        l_1458++;
                        l_1368[1] = l_1367[3];
                    }
                }
                else
                {
                    l_83 = p_78;
                }
                g_1297 = p_78;
            }
            else
            {
                uint8_t l_1461 = 0x2BL;
                int32_t l_1470 = (-1L);
                uint32_t l_1484 = 4294967295UL;
                uint8_t l_1652[9][9][3] = {{{0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}}, {{0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}}, {{0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}}, {{0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}}, {{0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}}, {{0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}}, {{0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}}, {{0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}}, {{0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}, {0UL, 0xDCL, 1UL}}};
                uint32_t l_1661[8][8][4] = {{{4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}}, {{4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}}, {{4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}}, {{4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}}, {{4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}}, {{4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}}, {{4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}}, {{4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}, {4294967289UL, 1UL, 0x7C7B75FEL, 4294967295UL}}};
                int32_t l_1690 = 0x393F3398L;
                int32_t l_1694 = 0x2DD89EDDL;
                int32_t l_1717 = (-1L);
                int32_t l_1718 = 1L;
                int32_t l_1719[8] = {9L, 9L, (-8L), 9L, 9L, (-8L), 9L, 9L};
                int i, j, k;
                l_1315[7][0] &= 0xEC27F8D8L;
                if ((l_1461 >= (g_139 = (l_83 = (safe_sub_func_int32_t_s_s(l_1461, (((g_1374 |= (-1L)) == (((+(safe_mul_func_int8_t_s_s((g_1271 &= (safe_mod_func_uint32_t_u_u(((safe_unary_minus_func_int32_t_s(((g_321[0][1][8]++) < (safe_mul_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((safe_mul_func_int16_t_s_s((!((+0UL) == ((safe_add_func_int16_t_s_s((+0xC215L), (l_1484 == (safe_sub_func_uint16_t_u_u(l_1369[2][5], ((l_1350 |= p_78) >= 0x712BL)))))) || l_1364))), p_78)), g_408)), l_1366))))) == g_252[2][6]), g_407))), g_35))) > 0x4DL) || p_78)) < p_78)))))))
                {
                    if (p_78)
                        break;
                }
                else
                {
                    int16_t l_1516[9][10][2] = {{{(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}}, {{(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}}, {{(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}}, {{(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}}, {{(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}}, {{(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}}, {{(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}}, {{(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}}, {{(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}, {(-9L), (-1L)}}};
                    int32_t l_1534 = 0x4AEDB0C7L;
                    int32_t l_1535 = 0xC66200BDL;
                    int i, j, k;
                    if (l_1361)
                    {
                        return g_316;
                    }
                    else
                    {
                        int16_t l_1514 = (-3L);
                        int32_t l_1515 = 0L;
                        g_1297 = (l_1515 = (l_1362[0] = ((-6L) | (safe_mul_func_int16_t_s_s(1L, ((safe_mul_func_uint8_t_u_u((0x0CL >= (safe_add_func_int8_t_s_s(p_78, (g_317 = (safe_add_func_int8_t_s_s(((safe_mul_func_int8_t_s_s(g_252[2][6], (((safe_rshift_func_uint16_t_u_u((((safe_rshift_func_int16_t_s_s(((((safe_mod_func_int8_t_s_s((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s(((!((g_348 | (((0xD4C8L < (safe_mul_func_uint16_t_u_u((safe_add_func_int8_t_s_s(l_1445, ((g_408 &= (safe_add_func_uint8_t_u_u(((g_371 > l_1368[1]) == 65535UL), l_1375))) > 1UL))), 9UL))) || l_1514) || 4294967295UL)) || p_78)) > l_1514), p_78)), g_407)), g_332)) < p_78) != 1UL) ^ l_1375), 4)) & g_1297) >= p_78), 5)) <= 0x714FL) != l_1368[1]))) != 0xD6B5L), 0L)))))), g_321[0][1][8])) == 0x14BA4D34L))))));
                        l_1360 &= 0xA433A506L;
                        l_1536[0][2][3] = ((l_1516[6][9][1] == (safe_rshift_func_uint8_t_u_s((l_1360 | g_328), 2))) == (safe_add_func_int8_t_s_s((0x98L ^ (-5L)), (0x8FL == (safe_add_func_int16_t_s_s((safe_sub_func_int32_t_s_s(((((safe_mod_func_int8_t_s_s((l_1535 = (safe_mul_func_uint16_t_u_u(((l_1534 = (safe_sub_func_int8_t_s_s(((safe_unary_minus_func_uint8_t_u((l_1515 = l_1515))) && l_1514), (safe_rshift_func_int16_t_s_u(p_78, 5))))) >= l_1514), p_78))), p_78)) > 0x81L) && p_78) && (-1L)), 0x5AC2C278L)), g_370[4]))))));
                    }
                }
                if ((l_1443[7][5][2] = (((safe_mod_func_uint16_t_u_u((((((safe_sub_func_int32_t_s_s((safe_add_func_int16_t_s_s((((p_78 < 0x5687D3ABL) & ((((safe_sub_func_int16_t_s_s((g_202 &= (safe_add_func_uint16_t_u_u(l_1358, (safe_lshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s(g_321[0][2][8], p_78)), 2))))), (-1L))) < (((safe_add_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(((safe_rshift_func_int8_t_s_u((l_1349[1][2] >= ((safe_rshift_func_uint16_t_u_u((safe_sub_func_int8_t_s_s(((safe_mul_func_int8_t_s_s(g_371, (safe_rshift_func_uint16_t_u_u(((((safe_mul_func_uint16_t_u_u((l_1315[3][0] ^= 0xA79AL), p_78)) ^ g_332) < 1L) | 250UL), g_206)))) == 65535UL), p_78)), 10)) == l_1375)), g_595[7])) || l_1445), 0x763F5129L)), g_35)) < l_1470) || 0x78A8L)) > 8L) ^ 65532UL)) || g_3), l_81)), g_347)) > l_1461) > l_1349[1][2]) > l_1445) >= g_317), g_151)) ^ (-1L)) == (-4L))))
                {
                    uint32_t l_1567[1][7][6] = {{{0xEBAD8823L, 0x3DBEFD02L, 0xC226F01DL, 0xF174CE18L, 4294967291UL, 0xF174CE18L}, {0xEBAD8823L, 0x3DBEFD02L, 0xC226F01DL, 0xF174CE18L, 4294967291UL, 0xF174CE18L}, {0xEBAD8823L, 0x3DBEFD02L, 0xC226F01DL, 0xF174CE18L, 4294967291UL, 0xF174CE18L}, {0xEBAD8823L, 0x3DBEFD02L, 0xC226F01DL, 0xF174CE18L, 4294967291UL, 0xF174CE18L}, {0xEBAD8823L, 0x3DBEFD02L, 0xC226F01DL, 0xF174CE18L, 4294967291UL, 0xF174CE18L}, {0xEBAD8823L, 0x3DBEFD02L, 0xC226F01DL, 0xF174CE18L, 4294967291UL, 0xF174CE18L}, {0xEBAD8823L, 0x3DBEFD02L, 0xC226F01DL, 0xF174CE18L, 4294967291UL, 0xF174CE18L}}};
                    int32_t l_1617 = 0xD86A3D4BL;
                    int32_t l_1623 = 0L;
                    uint32_t l_1636 = 0x186EFE19L;
                    int i, j, k;
                    l_1470 = (((l_1315[2][0] = ((l_1360 >= (g_973 || l_1567[0][0][4])) < 5UL)) | (safe_mul_func_int16_t_s_s((p_78 > (safe_rshift_func_uint16_t_u_u((((g_139 = (((((p_78 ^ (0x2E582DEEL >= (safe_sub_func_uint32_t_u_u(g_139, (g_244 = ((g_595[4] >= p_78) || l_1536[0][6][1])))))) == l_1536[2][5][5]) > p_78) <= l_1461) && 0xD0L)) != 0x1548BA07L) < p_78), 2))), g_370[1]))) >= g_141);
                    for (g_1374 = 0; (g_1374 <= 6); g_1374 += 1)
                    {
                        int32_t l_1637[6] = {0x6763FFA5L, 0x6763FFA5L, 1L, 0x6763FFA5L, 0x6763FFA5L, 1L};
                        int i;
                        l_1362[g_1374] = (l_1362[g_1374] > ((p_78 <= (g_408 = (g_202 ^= (((safe_add_func_uint8_t_u_u((safe_mul_func_uint8_t_u_u((safe_add_func_uint16_t_u_u((safe_mul_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(l_1584[1][8][6], (safe_rshift_func_int16_t_s_u((safe_rshift_func_int8_t_s_u(0x9CL, 7)), 5)))), (((0x71L | ((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s(((((!(((safe_mod_func_int16_t_s_s((+p_78), (safe_rshift_func_uint16_t_u_s((safe_mul_func_int16_t_s_s(g_327[0][0], ((((((safe_add_func_int8_t_s_s(0x54L, p_78)) ^ 6L) >= p_78) && p_78) && l_1354) && g_252[2][6]))), 14)))) ^ g_203) > p_78)) ^ l_1603) > g_206) | l_1604[1]), 0)), 0x5BE8L)) & g_539[5])) >= 0x3DF2L) && g_595[0]))), 0xAD80L)), 0UL)), g_1271)) & p_78) == 0x027CL)))) != l_1315[7][0]));
                        l_1315[4][0] = (safe_mod_func_uint16_t_u_u(((safe_mul_func_uint8_t_u_u(p_78, l_1584[1][7][0])) <= (p_78 ^ (((safe_rshift_func_int8_t_s_s((0x1B77B6E5L | g_151), (safe_rshift_func_int8_t_s_s((safe_mod_func_uint8_t_u_u(p_78, (l_1623 |= (safe_rshift_func_int8_t_s_s(((l_1617 = (l_1362[g_1374] = 0xBC447BE3L)) | (safe_add_func_int8_t_s_s((~0xA499L), (safe_lshift_func_int16_t_s_u(0xE4B0L, p_78))))), g_349))))), 4)))) == g_370[1]) > g_348))), 3L));
                        g_1297 = (safe_rshift_func_int8_t_s_u(0xC9L, (p_78 | (safe_add_func_int8_t_s_s(((l_1623 >= p_78) ^ l_1362[g_1374]), (l_1637[0] ^= (safe_rshift_func_uint16_t_u_u(0x1CCDL, (safe_mod_func_int8_t_s_s((safe_mul_func_int8_t_s_s(((safe_add_func_uint16_t_u_u(((g_1374 && l_1315[7][0]) > p_78), l_1636)) & p_78), l_1349[0][2])), p_78))))))))));
                    }
                    if (l_1366)
                    {
                        l_1470 = g_1297;
                    }
                    else
                    {
                        int16_t l_1642 = 1L;
                        l_83 = g_630;
                        l_1652[0][4][1] |= ((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint16_t_u_u(((l_1642 == g_1297) > l_1642), (safe_mul_func_int8_t_s_s(g_327[3][0], ((safe_rshift_func_uint8_t_u_u((0L ^ (safe_lshift_func_int16_t_s_u(0xB5A6L, 11))), ((l_1354 || (~(((safe_sub_func_uint8_t_u_u(l_1484, (0xF99FL >= 1L))) && 0x32L) ^ p_78))) | l_1443[2][5][4]))) && l_1375))))), l_1484)) == l_1461);
                    }
                    g_352 = (safe_sub_func_uint8_t_u_u(((((l_1567[0][4][1] > ((((-10L) <= (safe_sub_func_uint16_t_u_u(((g_139 > (safe_lshift_func_int8_t_s_s(((g_203 >= (safe_lshift_func_int8_t_s_u(p_78, (l_1360 || 0xCCFF728BL)))) > (l_83 = 0xE9L)), 5))) || (l_1661[6][6][3] = 0x97D7L)), 65535UL))) > 0x3665458CL) < 0x84L)) >= 0UL) == 0L) || l_1358), 248UL));
                }
                else
                {
                    int32_t l_1662 = (-9L);
                    int32_t l_1663 = (-1L);
                    uint32_t l_1680 = 0x082D1341L;
                    int32_t l_1693 = 0xD2B930C8L;
                    int32_t l_1714 = 0x0923846EL;
                    int32_t l_1715 = (-6L);
                    int32_t l_1716[5][7] = {{0xD871F9F3L, 0x7AF274EAL, 0L, 2L, 2L, 0L, 0x7AF274EAL}, {0xD871F9F3L, 0x7AF274EAL, 0L, 2L, 2L, 0L, 0x7AF274EAL}, {0xD871F9F3L, 0x7AF274EAL, 0L, 2L, 2L, 0L, 0x7AF274EAL}, {0xD871F9F3L, 0x7AF274EAL, 0L, 2L, 2L, 0L, 0x7AF274EAL}, {0xD871F9F3L, 0x7AF274EAL, 0L, 2L, 2L, 0L, 0x7AF274EAL}};
                    int i, j;
                    l_1663 = (0x19L != l_1662);
                    if (g_326[7])
                    {
                        int32_t l_1681 = 0x4EFB6E50L;
                        int32_t l_1682 = 9L;
                        int32_t l_1683 = (-10L);
                        if (g_244)
                            break;
                        g_539[4] = (g_1297 = (safe_mul_func_uint16_t_u_u((g_511 = (l_1683 = (0L ^ ((safe_mul_func_int8_t_s_s((safe_add_func_int32_t_s_s((((-1L) && (((+((p_78 && p_78) > p_78)) > 0xA389EFD2L) ^ (safe_rshift_func_int8_t_s_u((1UL | (l_1682 = (((safe_sub_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u((((p_78 ^ (safe_mod_func_uint8_t_u_u(l_81, l_1679))) < l_1680) < g_202), 7)) ^ g_139) & l_1681) ^ p_78) == g_511), 0UL)) ^ (-2L)) != p_78))), 2)))) || 0x1ABFB2AAL), p_78)), 255UL)) < g_321[3][2][2])))), p_78)));
                        g_352 = 0x7D8D76A0L;
                        return g_1374;
                    }
                    else
                    {
                        uint32_t l_1684 = 18446744073709551615UL;
                        int32_t l_1687 = 0x60F3C977L;
                        int32_t l_1688 = 0xFD83D903L;
                        int32_t l_1689 = (-1L);
                        int32_t l_1691 = 0x942FE7C2L;
                        int32_t l_1692[4];
                        int i;
                        for (i = 0; i < 4; i++)
                            l_1692[i] = 0x142AC48EL;
{
        transparent_crc(g_370[g_3804], "g_370[g_3804]", l_1717);
        if (l_1717) printf("index = [%d]\n", g_3804);
    }
l_1684++;
                        l_1695--;
                    }
                    g_352 = (((safe_add_func_uint8_t_u_u(0x4EL, (0UL || (g_141 ^= (safe_mod_func_int32_t_s_s((safe_mod_func_uint16_t_u_u(g_203, p_78)), (((safe_mod_func_uint8_t_u_u((g_595[7] == (safe_lshift_func_int8_t_s_u(((safe_lshift_func_int16_t_s_s(g_202, 0)) ^ (l_1315[7][0] ^= (safe_add_func_uint32_t_u_u(p_78, (g_1297 = l_1470))))), ((safe_sub_func_uint32_t_u_u((p_78 ^ 1UL), p_78)) || g_347)))), p_78)) > p_78) ^ l_1470))))))) & p_78) || p_78);
                    --l_1720;
                }
            }
            l_1361 = (g_189 && p_78);
            return g_1297;
        }
        l_1361 = ((p_78 = ((+p_78) & (g_141 = (safe_lshift_func_int16_t_s_u(l_1364, 1))))) & ((((safe_sub_func_int32_t_s_s(0xAE174513L, (g_1297 = (safe_mul_func_int8_t_s_s((-1L), (safe_add_func_int8_t_s_s((safe_sub_func_int32_t_s_s((l_1315[8][0] = (((!(safe_rshift_func_uint8_t_u_u(((safe_mod_func_int8_t_s_s((((249UL | ((safe_mod_func_uint8_t_u_u(l_1375, (safe_lshift_func_int8_t_s_u(l_1315[7][0], l_1747[2])))) == ((l_1443[3][3][2] <= g_348) <= 0x9F13L))) & g_327[2][0]) & 0x1A08A9A2L), 0x40L)) > l_1369[2][5]), 1))) || g_370[5]) ^ 0xE5L)), l_1720)), 255UL))))))) && l_1720) == l_1747[5]) == g_770));
        for (g_332 = (-11); (g_332 >= 3); g_332++)
        {
            uint32_t l_1750 = 0xBB766B90L;
            int32_t l_1756 = 0xA4C29BEDL;
            int32_t l_1757 = 0x8420632FL;
            int32_t l_1760 = 0xD57AF817L;
            int32_t l_1761 = 8L;
            int32_t l_1762 = 0x402D418AL;
            int32_t l_1763 = 3L;
            int32_t l_1765 = 0xEDD0438DL;
            int32_t l_1768 = (-1L);
            int32_t l_1769[4];
            int16_t l_1773 = (-1L);
            int16_t l_1775 = 0x60C1L;
            uint32_t l_1776 = 2UL;
            uint32_t l_1784 = 0x85473E6CL;
            int i;
            for (i = 0; i < 4; i++)
                {
{
                    int32_t l_3233[10] = {(-3L), (-1L), 0x16D211A9L, 0x16D211A9L, (-1L), (-3L), (-1L), 0x16D211A9L, 0x16D211A9L, (-1L)};
                    int i;
                    l_1765 ^= (1L ^ 0x85L);
                    l_1772 = ((safe_mul_func_int16_t_s_s(0xCFE9L, (((safe_add_func_uint8_t_u_u((g_595[l_1757] = 0x5DL), (~(g_347 >= g_326[7])))) == (((l_1757 != ((g_35 = 7UL) ^ l_2201)) >= ((g_370[l_2201] & (((safe_rshift_func_int16_t_s_u(((((((0x2C2192B5L == l_1776) > 8L) || (-1L)) <= (-1L)) & 0x09L) < g_2888), 11)) || 1L) < 0x8AL)) ^ 0x38A8L)) >= g_332)) < 0xCB27L))) && l_2201);
                    for (g_769 = 0; (g_769 <= 5); g_769 += 1)
                    {
                        int8_t l_3226[1][3];
                        int i, j;
                        for (i = 0; i < 1; i++)
                        {
                            for (j = 0; j < 3; j++)
                                l_3226[i][j] = (-1L);
                        }
                        g_539[2] = (l_2158 & 0L);
                        l_1756 &= (safe_add_func_uint16_t_u_u(0xD128L, (g_408 >= (g_371 < (safe_rshift_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((safe_unary_minus_func_uint32_t_u(((safe_lshift_func_int8_t_s_u((safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(((l_3226[0][2] ^ (l_1772 = ((safe_rshift_func_uint8_t_u_s((((l_1775 = 0x80E2L) ^ (safe_rshift_func_int8_t_s_u((g_370[l_2201] >= ((g_2888 == 0xFFB4L) < ((l_3233[5] = (safe_add_func_int8_t_s_s(((l_2158 >= 255UL) < 65535UL), 0x70L))) | 0xDC6EL))), l_2158))) <= g_3804), g_206)) || 0x44L))) >= (-10L)), 14)), 0xE5337C48L)), g_595[l_1757])) || g_370[l_2201]))) < 0x5CL), l_1757)), 5))))));
                    }
                    --l_1720;
                }
l_1769[i] = 0x11F627F0L;}
            l_1750--;
            for (l_1364 = 1; (l_1364 >= 0); l_1364 -= 1)
            {
                int32_t l_1753 = 0L;
                int32_t l_1754 = (-6L);
                int32_t l_1755 = 1L;
                int32_t l_1758 = (-1L);
                int32_t l_1759 = 0xB2116104L;
                int32_t l_1764 = 1L;
                int32_t l_1766 = 0xB351AB9CL;
                int32_t l_1767[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_1767[i] = 7L;
                ++l_1776;
                for (l_1760 = 0; (l_1760 <= 1); l_1760 += 1)
                {
                    int i;
                    if (l_1368[l_1364])
                    {
                        uint32_t l_1779 = 0x8877290CL;
                        ++l_1779;
                    }
                    else
                    {
                        if (p_78)
                            break;
                    }
                }
                if ((~l_1783))
                {
                    uint32_t l_1788 = 0x66C481CDL;
for (l_1351 = 0; l_1351 < 9; l_1351++)
            {
                transparent_crc(g_321[l_1350][l_1759][l_1351], "g_321[l_1350][l_1759][l_1351]", l_1772);
                if (l_1772) printf("index = [%d][%d][%d]\n", l_1350, l_1759, l_1351);
            };
++l_1784;
                    ++l_1788;
                }
                else
                {
                    uint32_t l_1793 = 0UL;
                    int32_t l_1811 = 0L;
                    for (g_348 = 5; (g_348 >= 18); ++g_348)
                    {
                        int32_t l_1802 = 0x59FCC28CL;
                        int32_t l_1812 = 0x066B8299L;
                        l_1793++;
                        l_1812 = (0x71L != (l_1811 ^= ((((safe_mod_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_u(0xB5DDL, g_539[4])) ^ (safe_add_func_int32_t_s_s(p_78, (6L == (g_595[7]--))))), 0x2A7FFF14L)) || ((safe_mul_func_int8_t_s_s((safe_sub_func_uint32_t_u_u((g_206 ^= (((((g_769++) || l_1802) < 1UL) & (g_139 | l_1584[2][0][3])) || 252UL)), l_1769[2])), (-9L))) <= g_139)) == g_327[2][0]) < p_78)));
                        l_1315[0][0] ^= ((safe_mod_func_uint32_t_u_u((safe_mul_func_uint16_t_u_u(((l_1812 |= (((((((safe_add_func_int16_t_s_s((g_408 |= (safe_mul_func_int8_t_s_s((safe_add_func_int16_t_s_s(l_1695, (safe_sub_func_int32_t_s_s((((safe_add_func_uint16_t_u_u(l_1802, g_321[3][1][3])) <= (safe_rshift_func_uint8_t_u_s((g_595[7] = g_206), 1))) ^ (+p_78)), ((safe_sub_func_int32_t_s_s(((l_1771 ^= (l_1811 |= (((0x04ABL && ((((safe_rshift_func_int8_t_s_s(g_511, 1)) | (g_151 = ((safe_rshift_func_int16_t_s_u((g_202 = (safe_lshift_func_int8_t_s_s((safe_lshift_func_int8_t_s_s((g_1374 = (safe_sub_func_int16_t_s_s((safe_lshift_func_uint8_t_u_u(0x05L, p_78)), g_321[2][0][7]))), 1)), p_78))), p_78)) | l_1720))) > 0x4F77D6D2L) <= 0x98L)) <= l_1750) | 0x9770L))) != p_78), 0xAA84FC01L)) < g_141))))), p_78))), g_1297)) <= g_1297) ^ 0x2AE3D0CCL) == 0xC2D1L) == 6L) || l_1811) <= 0x2CL)) < 65535UL), 8UL)), p_78)) == l_1604[1]);
                    }
                    if (g_370[1])
                        continue;
                }
            }
            for (l_1787 = 0; (l_1787 <= 24); l_1787 = safe_add_func_int32_t_s_s(l_1787, 7))
            {
                uint32_t l_1860 = 3UL;
                int32_t l_1895 = 0x332358ADL;
                int32_t l_1905[10] = {3L, 3L, (-1L), 3L, 3L, (-1L), 3L, 3L, (-1L), 3L};
                int32_t l_1926 = 0xC092F75EL;
                int32_t l_2136 = 1L;
                int i;
                for (g_141 = 15; (g_141 >= 58); g_141 = safe_add_func_int32_t_s_s(g_141, 8))
                {
                    int8_t l_1856 = 0L;
                    int32_t l_1857 = 0x9098AB6CL;
                    int32_t l_1899 = 0x7AC02F27L;
                    int8_t l_1902 = 0xDEL;
                    int32_t l_1903 = 0x3FDF45C9L;
                    int32_t l_1904 = (-8L);
                    int32_t l_1906 = 0x84EA8534L;
                    int32_t l_1907 = 0xDA4BF0DDL;
                    int32_t l_1908 = (-4L);
                    int32_t l_1909 = 0x3B6327A5L;
                    int32_t l_1910[5][1][8] = {{{3L, 3L, 0xAA918D4FL, 3L, 3L, 0x127A4ADFL, 3L, 3L}}, {{3L, 3L, 0xAA918D4FL, 3L, 3L, 0x127A4ADFL, 3L, 3L}}, {{3L, 3L, 0xAA918D4FL, 3L, 3L, 0x127A4ADFL, 3L, 3L}}, {{3L, 3L, 0xAA918D4FL, 3L, 3L, 0x127A4ADFL, 3L, 3L}}, {{3L, 3L, 0xAA918D4FL, 3L, 3L, 0x127A4ADFL, 3L, 3L}}};
                    uint32_t l_1943 = 0xFEAD584EL;
                    int32_t l_1958 = 0xBEF7C09FL;
                    int i, j, k;
                    if (((safe_add_func_uint32_t_u_u((l_1765 = p_78), 0x09FCF980L)) != (safe_mul_func_int8_t_s_s((safe_lshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(p_78, (l_1857 = l_1856))), 4)), (safe_rshift_func_int8_t_s_s(((l_1860 = l_1776) < (p_78 == ((0xE710L ^ p_78) ^ ((l_1763 = g_3) <= g_630)))), l_1761))))))
                    {
                        uint16_t l_1870 = 1UL;
                        l_1443[3][3][2] |= (l_83 | (safe_unary_minus_func_uint8_t_u(g_326[4])));
                        g_539[4] = ((safe_add_func_uint16_t_u_u((l_1857 > ((safe_mod_func_uint8_t_u_u((safe_mul_func_uint8_t_u_u((0xAB708579L <= 0x9AD947DDL), (((l_1366 = (l_1772 || ((g_317 = 0xEBL) == (safe_sub_func_int16_t_s_s((g_202 = (p_78 != l_1870)), (safe_mul_func_int16_t_s_s((p_78 || ((safe_add_func_uint32_t_u_u(((0UL >= p_78) >= 2L), p_78)) | g_326[7])), g_511))))))) == g_371) != 246UL))), l_1870)) != l_1536[0][2][3])), 0x733BL)) < g_349);
                    }
                    else
                    {
                        int8_t l_1896 = 0L;
                        int32_t l_1897 = 1L;
                        int32_t l_1898 = 0xA58EA62FL;
                        int32_t l_1900[8] = {(-8L), (-8L), 0L, (-8L), (-8L), 0L, (-8L), (-8L)};
                        int32_t l_1901 = 6L;
                        uint32_t l_1911 = 0xA274FA38L;
                        int i;
                        l_1771 = ((l_1443[2][2][2] = ((safe_mul_func_uint8_t_u_u(l_1860, (l_1315[7][0] &= p_78))) != (safe_mod_func_int32_t_s_s((!((safe_lshift_func_uint16_t_u_s((safe_add_func_int8_t_s_s((safe_sub_func_int16_t_s_s((l_1895 &= (safe_sub_func_uint16_t_u_u((1L | (0UL | ((safe_lshift_func_uint16_t_u_s(l_1760, ((((!(safe_mod_func_uint32_t_u_u(p_78, g_35))) && 0x32C17F6AL) > (((safe_sub_func_uint8_t_u_u(g_327[2][0], p_78)) > g_349) && p_78)) == g_206))) < (-1L)))), 0x9ECBL))), 0UL)), 1L)), 2)) && l_1860)), l_83)))) | p_78);
                        ++l_1911;
                    }
                    if (((65526UL && (safe_add_func_int32_t_s_s(((p_78 || p_78) < ((l_1906 || 0xE75153D6L) ^ ((g_326[1] = (safe_unary_minus_func_uint32_t_u((l_1769[2] = l_1315[7][0])))) != (safe_mul_func_uint16_t_u_u((safe_add_func_int8_t_s_s((((((safe_mod_func_int8_t_s_s((p_78 < ((safe_unary_minus_func_uint32_t_u((safe_mul_func_int16_t_s_s((((p_78 || g_139) <= g_3) ^ p_78), l_1926)))) ^ g_595[7])), p_78)) || p_78) || l_1584[1][8][6]) && g_539[6]) & l_1927), l_1904)), l_1761))))), g_595[7]))) == p_78))
                    {
                        if (l_1350)
                            break;
                    }
                    else
                    {
                        int32_t l_1948 = 0x22D08726L;
                        g_539[4] = (safe_mod_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(p_78, ((((safe_add_func_uint8_t_u_u((safe_mul_func_uint16_t_u_u((safe_mod_func_int32_t_s_s(0xCE40BE79L, 4294967293UL)), (safe_lshift_func_int16_t_s_s((l_1315[4][0] = (l_83 = (g_1271 ^ (safe_rshift_func_int8_t_s_s((0x35C8L | ((~(l_1943 & ((p_78 == (0UL > (safe_lshift_func_int16_t_s_u(0x8B25L, 6)))) & g_973))) >= l_1948)), 1))))), g_595[0])))), p_78)) ^ g_141) > p_78) == g_321[2][1][5]))), p_78));
                        l_1368[1] = 0L;
                    }
                    g_1297 &= (((l_1315[4][0] |= ((((safe_mod_func_int16_t_s_s(((safe_sub_func_int8_t_s_s(0x46L, (g_511 >= ((p_78 || ((g_1374 != 0UL) == ((l_1756 = (l_83 & (safe_rshift_func_uint8_t_u_s((safe_sub_func_int32_t_s_s((l_1351 |= p_78), (safe_unary_minus_func_uint16_t_u(l_1604[1])))), ((((p_78 && g_973) <= g_370[1]) <= g_244) != p_78))))) != 0x1AL))) < p_78)))) > p_78), g_1442)) != g_347) >= g_769) ^ 0xC855L)) >= 0xD14B8EB9L) <= l_1958);
                }
                for (g_348 = (-18); (g_348 <= 21); ++g_348)
                {
                    uint32_t l_1989[1];
                    int32_t l_2003 = (-8L);
                    uint8_t l_2019 = 0xEFL;
                    uint8_t l_2080 = 249UL;
                    int i;
                    for (i = 0; i < 1; i++)
                        l_1989[i] = 18446744073709551612UL;
                    g_352 = (safe_mul_func_uint16_t_u_u((l_1368[1] != (g_141 &= 9UL)), (safe_add_func_uint8_t_u_u((p_78 >= (safe_rshift_func_int8_t_s_u((safe_add_func_int32_t_s_s((safe_lshift_func_int16_t_s_u((safe_lshift_func_uint16_t_u_s(1UL, ((safe_lshift_func_uint16_t_u_u(((g_326[3] |= 1UL) <= (safe_sub_func_int32_t_s_s(((safe_sub_func_int16_t_s_s((safe_add_func_uint16_t_u_u(1UL, p_78)), (safe_rshift_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(g_189, 7)), l_1775)))) < g_317), p_78))), g_1985[5])) | 0xAEED6C69L))), l_1763)), 1UL)), 5))), 0x97L))));
                    if ((0x15L | ((+(((l_1989[0] <= ((l_1761 ^= ((safe_rshift_func_int16_t_s_s(((((l_2003 = ((safe_mul_func_int16_t_s_s(((g_139 = g_1442) < 1UL), 1UL)) && (+(g_206 != (((((g_252[2][2] | ((p_78 |= (safe_sub_func_uint8_t_u_u((!((safe_add_func_int32_t_s_s((safe_mul_func_int8_t_s_s(g_1985[5], ((~0x69BEL) != l_1757))), l_1905[6])) != 248UL)), l_1769[2]))) == 0x9EEAL)) == l_1989[0]) || 0xB3L) < l_1989[0]) == l_1989[0]))))) & l_1756) == (-6L)) <= g_973), g_321[2][0][5])) <= g_202)) < l_1989[0])) < g_347) || p_78)) || g_347)))
                    {
                        int32_t l_2016 = 1L;
                        int32_t l_2041[6] = {0xCD81E881L, 0xCF12D317L, 0xCD81E881L, 0xCF12D317L, 0xCD81E881L, 0xCF12D317L};
                        int i;
                        g_1297 ^= ((((l_1905[5] = (g_1442 > (l_1895 ^= ((safe_rshift_func_int16_t_s_u((l_1926 &= 1L), 4)) == (((safe_add_func_uint32_t_u_u(0x9E7FA27AL, 0x24009ACBL)) > (safe_sub_func_uint32_t_u_u((safe_mul_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s(p_78, 0xADL)) < ((((safe_lshift_func_uint8_t_u_s(l_2016, 6)) < ((safe_mul_func_uint8_t_u_u(l_1775, g_151)) || 0UL)) >= l_2019) ^ p_78)), g_630)), g_371))) <= p_78))))) == l_1604[1]) && l_1989[0]) != p_78);
                        g_139 = ((safe_sub_func_int8_t_s_s((0x8C6EBA85L & ((safe_mul_func_int8_t_s_s(7L, (((safe_mul_func_uint8_t_u_u(0x14L, (safe_unary_minus_func_int32_t_s(g_328)))) > (p_78 <= ((l_1769[3] = (((((((safe_add_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_u((safe_rshift_func_uint8_t_u_u(((((l_1443[3][3][2] &= ((safe_add_func_uint32_t_u_u(((safe_add_func_int8_t_s_s(6L, 0xD7L)) ^ (((((l_2019 & g_2037) != 2L) ^ p_78) < l_1905[6]) | l_2003)), g_370[1])) == p_78)) | p_78) <= (-1L)) > p_78), g_1374)), p_78)) && 1L), g_347)) > l_1784) | 0x7C988142L) <= l_1750) > l_1765) != l_2016) && 0xB9L)) || (-8L)))) == 0xA4L))) >= l_1760)), 1L)) && 1UL);
                        l_2041[2] |= ((l_2016 > g_139) ^ ((((((l_2016 != l_1763) == g_370[5]) >= 0x39L) ^ p_78) >= (safe_mul_func_int8_t_s_s(((((((((0xAD32L != (~p_78)) || g_141) != g_202) < g_770) == 4294967288UL) == 6L) <= 0x4AL) <= g_326[7]), g_1374))) >= p_78));
                        l_2016 &= (safe_mul_func_uint8_t_u_u((safe_add_func_int32_t_s_s(0x8FCDE01DL, (((safe_lshift_func_int8_t_s_s(0x61L, 5)) && (safe_add_func_uint8_t_u_u(g_770, ((p_78 & ((((l_2003 &= (safe_lshift_func_uint16_t_u_u(l_2041[5], (p_78 == (((p_78 > (5UL | (+(p_78 > 0UL)))) && 0x40L) < 0x15L))))) >= l_1784) > p_78) > p_78)) != p_78)))) >= g_1297))), g_352));
                    }
                    else
                    {
                        int8_t l_2067 = (-8L);
                        int32_t l_2070[1][9] = {{0x988F644CL, (-1L), 0x988F644CL, (-1L), 0x988F644CL, (-1L), 0x988F644CL, (-1L), 0x988F644CL}};
                        uint8_t l_2077 = 0UL;
                        int i, j;
                        g_139 = l_1679;
                        l_2003 = (safe_add_func_uint16_t_u_u((((g_769 <= (~0x6066ABFFL)) | l_1750) > ((safe_sub_func_uint16_t_u_u(0x99D7L, g_327[3][0])) < (g_408 = (safe_sub_func_int32_t_s_s(((safe_unary_minus_func_uint32_t_u(0x4E7FC925L)) ^ (((safe_sub_func_int32_t_s_s(((safe_mul_func_uint8_t_u_u(0x26L, (safe_add_func_int8_t_s_s((g_2037 & l_2067), (-1L))))) > 2L), g_327[3][0])) <= p_78) ^ g_326[7])), 0UL))))), g_139));
                        g_352 = (p_78 == (safe_mod_func_int8_t_s_s(((0xE9L >= (l_1768 = (l_1315[7][0] = ((0x74DEL & (l_2070[0][0] = (1L <= l_1905[3]))) <= (g_348 == l_1905[6]))))) >= ((((safe_add_func_uint8_t_u_u(g_189, ((safe_mul_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u(l_1772, p_78)), g_539[4])) < 0xA6L))) == l_1350) >= p_78) ^ l_2067)), g_348)));
                        l_2077--;
                    }
for (l_1765 = 18; (l_1765 > (-26)); l_1765--)
    {
        uint8_t l_53 = 5UL;
        if (l_2597)
            break;
        l_53++;
    };
--l_2080;
                    l_2083--;
                }
                g_139 = ((safe_lshift_func_uint16_t_u_s(g_141, (((safe_sub_func_uint16_t_u_u(0xC2BEL, (safe_mod_func_int8_t_s_s((safe_rshift_func_int8_t_s_u(((safe_add_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u(((((l_1315[0][0] = ((safe_mul_func_uint16_t_u_u((((~0x8B882D0CL) == (1L ^ (((g_511 = (safe_lshift_func_uint16_t_u_s((safe_mul_func_int8_t_s_s(((safe_mul_func_uint16_t_u_u((g_326[7] = l_1763), ((p_78 ^= (-1L)) >= (((safe_rshift_func_uint16_t_u_u(((g_1374 & l_1750) ^ l_1375), l_1769[3])) >= g_595[7]) < l_1769[2])))) > l_1761), l_1760)), 4))) ^ 0xC2FBL) < l_2111))) != 0xC4D25F0AL), g_35)) ^ l_1905[4])) > 65535UL) ^ 0xAB2AL) >= 1UL), g_371)), l_1757)) || l_1895), 4)), 4UL)))) != l_1772) != g_328))) ^ l_1747[0]);
                g_1297 ^= (p_78 <= (l_1895 = (p_78 > ((safe_unary_minus_func_uint16_t_u(0xA051L)) ^ ((g_139 = g_332) != (p_78 >= (safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_u(l_1695, 10)), (safe_mod_func_int16_t_s_s(g_349, (safe_rshift_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(1UL, (safe_add_func_uint32_t_u_u((safe_mod_func_int32_t_s_s((safe_mul_func_uint8_t_u_u((safe_mul_func_uint8_t_u_u((--g_252[2][6]), ((((!(--g_244)) == 5UL) ^ 0UL) & l_2136))), p_78)), 0x253DBCA8L)), g_1985[5])))) > g_769), 12))))))))))));
            }
            l_1771 |= (g_139 = (safe_add_func_uint8_t_u_u(((((((((((+((l_1774 > ((safe_mul_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((l_83 &= (safe_mod_func_int8_t_s_s(p_78, p_78))), g_770)), (safe_rshift_func_int16_t_s_u((safe_rshift_func_int8_t_s_s((((0xF0L | ((l_1769[2] = 0xC6L) ^ (p_78 == (((--g_141) > (safe_sub_func_uint32_t_u_u((l_1757 = p_78), (((safe_rshift_func_int8_t_s_u(((((safe_mul_func_uint16_t_u_u(g_202, 65535UL)) | g_1442) || l_2158) == 0UL), 2)) ^ l_1369[1][4]) & p_78)))) != l_1773)))) && g_349) != 0xB395L), 6)), l_1695)))) ^ g_327[1][0])) >= g_407)) & p_78) >= l_1369[7][5]) | l_1584[1][8][6]) || p_78) & g_189) > (-1L)) == p_78) == g_630) <= 0x2B42BEDEL), l_1361)));
        }
        l_1315[8][0] = (g_327[3][0] > (((((g_139 = (((safe_mod_func_uint8_t_u_u(g_348, (safe_rshift_func_int8_t_s_u((0xE2F84A6FL ^ g_973), l_1747[2])))) & (p_78 >= ((g_595[7] = (0UL >= (safe_add_func_int16_t_s_s((safe_rshift_func_int16_t_s_s((l_83 = ((safe_lshift_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_u((++g_151), 5)), (g_2037 = (g_244 = l_1445)))), 1)) && 1UL)), l_2175)), p_78)))) && g_1985[6]))) < g_973)) & g_347) >= p_78) <= g_1297) & 8UL));
    }
    if ((g_139 = ((safe_mul_func_int16_t_s_s((-6L), (247UL <= (3UL || (safe_rshift_func_int8_t_s_s((g_1271 = 0xA6L), ((8L > (p_78 < (safe_sub_func_uint8_t_u_u(((0xEC47L > (safe_mod_func_int8_t_s_s(((safe_add_func_int8_t_s_s(((((((~(safe_lshift_func_uint16_t_u_u(g_371, (safe_rshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_s((g_769 && l_83), 10)), g_327[3][0]))))) > g_252[2][4]) || 0xD42F7AF2L) > g_1297) != 0x42852CA7L) || g_328), g_770)) ^ p_78), l_2195))) ^ g_630), p_78)))) < l_1315[7][0]))))))) || l_1315[7][0])))
    {
        int32_t l_2204 = 0x06B5FF87L;
        int32_t l_2212 = 0x24DCFA2CL;
        l_2212 = (safe_mul_func_int8_t_s_s(p_78, (+(safe_mod_func_int16_t_s_s((g_539[4] >= (l_1315[7][0] = ((l_2201 = (g_202 = l_81)) >= ((g_511 < (safe_add_func_uint16_t_u_u(g_189, l_2204))) >= (((g_2205 < (((safe_mul_func_uint8_t_u_u((0x25F27405L || ((safe_sub_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u(g_327[0][0], g_252[0][2])) | 7UL), 0x83L)) | g_347)), g_769)) >= p_78) && g_326[7])) == p_78) ^ l_1772))))), g_321[2][1][6])))));
        for (g_347 = 0; (g_347 <= 23); g_347 = safe_add_func_int8_t_s_s(g_347, 8))
        {
            uint32_t l_2215 = 3UL;
            --l_2215;
        }
    }
    else
    {
        int16_t l_2223 = 0x3445L;
        int32_t l_2236 = 6L;
        int32_t l_2237[2];
        int i;
        for (i = 0; i < 2; i++)
            l_2237[i] = 0x37559B5FL;
        g_352 = (((safe_lshift_func_int8_t_s_u(l_2201, ((((safe_unary_minus_func_uint32_t_u((safe_sub_func_int8_t_s_s(l_2223, (safe_rshift_func_int16_t_s_s((-1L), (safe_mul_func_int16_t_s_s(p_78, (safe_mul_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s((((safe_mod_func_uint8_t_u_u(l_1774, (safe_mod_func_int8_t_s_s((((g_2037--) || (((safe_mod_func_int32_t_s_s(((l_1771 |= (l_2083 | (~(l_2236 = (g_2205 = (!g_244)))))) == (~(l_1315[1][0] |= (g_1985[5] = (safe_mul_func_int16_t_s_s(((7L | (safe_lshift_func_uint16_t_u_s(((((safe_rshift_func_int16_t_s_u((safe_lshift_func_uint16_t_u_u((((l_2237[0] &= 0L) > g_1271) < l_2253), p_78)), 1)) & 65535UL) & 8L) > 4294967293UL), 8))) != p_78), p_78)))))), l_2223)) | p_78) ^ p_78)) | g_370[1]), p_78)))) > l_2223) ^ l_2223), p_78)), g_189)))))))))) > g_317) > g_770) >= 0x881A80B9L))) != (-8L)) & 4294967286UL);
        if ((0x2E23L > ((l_81 && (safe_sub_func_uint8_t_u_u((((p_78 ^ ((safe_sub_func_int32_t_s_s(((((g_2205 |= 0L) <= (safe_mul_func_int16_t_s_s(p_78, (((((1UL ^ (safe_mod_func_uint32_t_u_u(l_1584[2][4][3], (((safe_rshift_func_int8_t_s_s((p_78 <= ((safe_sub_func_int8_t_s_s(0x41L, (-1L))) != p_78)), 3)) <= p_78) && 0x4683L)))) || 0x8FL) ^ l_2237[1]) && l_2237[0]) > l_2175)))) | p_78) <= l_1584[0][2][6]), l_2237[0])) > 0x00L)) & 0UL) || g_321[3][0][5]), 0xFFL))) | g_317)))
        {
            l_83 = (safe_mod_func_int16_t_s_s(p_78, (safe_add_func_uint16_t_u_u(1UL, 0xF240L))));
        }
        else
        {
            int16_t l_2276 = 0x7579L;
            int32_t l_2282 = (-1L);
            int32_t l_2283 = 0L;
            l_1771 &= (~(l_2283 = (((((safe_lshift_func_int16_t_s_u(p_78, 0)) == ((p_78 < (~g_332)) <= (g_317 |= ((g_1374 &= (safe_mul_func_uint8_t_u_u((l_2282 = ((0xAAL >= (p_78 | ((l_2276 | (safe_sub_func_int8_t_s_s(((((g_2281[2][1] = (safe_add_func_uint32_t_u_u(p_78, (((-1L) | (0UL >= l_2276)) ^ 1UL)))) | l_2158) & l_2276) | 0x07258BE8L), l_2282))) && 65526UL))) <= 0xCEC87E3CL)), l_2276))) <= (-1L))))) == (-1L)) >= g_408) >= 0xD9L)));
        }
    }
k &= ((safe_mod_func_int32_t_s_s(g_1271, g_202)) ^ 255UL);
for (l_1772 = 0; (l_1772 == 11); l_1772 = safe_add_func_uint32_t_u_u(l_1772, 1))
    {
        int32_t l_2306 = 0x3B5F4BBBL;
        int32_t l_2320 = 0L;
        int32_t l_2343 = (-9L);
        int32_t l_2344 = (-1L);
        int32_t l_2346 = 0x6999BF05L;
        int32_t l_2348 = (-1L);
        int32_t l_2349 = 0xB7F009C8L;
        int32_t l_2355[8][4] = {{0xE0C706E0L, 0L, 0x16D7AEDBL, 1L}, {0xE0C706E0L, 0L, 0x16D7AEDBL, 1L}, {0xE0C706E0L, 0L, 0x16D7AEDBL, 1L}, {0xE0C706E0L, 0L, 0x16D7AEDBL, 1L}, {0xE0C706E0L, 0L, 0x16D7AEDBL, 1L}, {0xE0C706E0L, 0L, 0x16D7AEDBL, 1L}, {0xE0C706E0L, 0L, 0x16D7AEDBL, 1L}, {0xE0C706E0L, 0L, 0x16D7AEDBL, 1L}};
        uint32_t l_2363 = 0x821B6865L;
        uint32_t l_2413[8][1];
        int16_t l_2579 = 0x87D3L;
        int16_t l_2669[4] = {0L, 0xDBB6L, 0L, 0xDBB6L};
        int8_t l_2759 = 0x3FL;
        int32_t l_2915 = (-1L);
        int16_t l_2925 = 0L;
        uint32_t l_2926[3][8][8] = {{{0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}}, {{0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}}, {{0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}, {0UL, 0UL, 0x6C36949DL, 0UL, 18446744073709551615UL, 0UL, 0UL, 0x8C17601BL}}};
        int i, j, k;
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 1; j++)
                l_2413[i][j] = 0xA4CE00A4L;
        }
        for (g_139 = 16; (g_139 == (-9)); --g_139)
        {
            int16_t l_2305 = 0x9D0DL;
            int32_t l_2321 = 6L;
            int32_t l_2322 = 0L;
            int32_t l_2354 = 0x6A4E2F7BL;
            int32_t l_2359 = (-1L);
            int32_t l_2362[3][7] = {{0x02DCA95AL, 0x02DCA95AL, 0x7780E85AL, 0xAF6D29D9L, (-4L), 0xAF6D29D9L, 0x7780E85AL}, {0x02DCA95AL, 0x02DCA95AL, 0x7780E85AL, 0xAF6D29D9L, (-4L), 0xAF6D29D9L, 0x7780E85AL}, {0x02DCA95AL, 0x02DCA95AL, 0x7780E85AL, 0xAF6D29D9L, (-4L), 0xAF6D29D9L, 0x7780E85AL}};
            uint32_t l_2368 = 18446744073709551611UL;
            uint8_t l_2410[7];
            int i, j;
            for (i = 0; i < 7; i++)
                l_2410[i] = 7UL;
            l_2320 = (safe_rshift_func_uint16_t_u_s((0xA4L < (((safe_rshift_func_uint16_t_u_u(g_370[0], ((safe_rshift_func_uint8_t_u_s((g_539[3] && p_78), 0)) != (((safe_mod_func_uint8_t_u_u((((safe_unary_minus_func_uint32_t_u((((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u(p_78, (safe_rshift_func_int8_t_s_u(((safe_lshift_func_int16_t_s_u(((l_2306 = l_2305) | ((!((safe_add_func_uint8_t_u_u((9UL != ((((((l_2322 = (((~(l_2321 = ((safe_add_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(((-4L) > ((((safe_add_func_uint16_t_u_u(((~0x9CL) | 1L), l_2318)) || p_78) | p_78) > 0xF614B336L)), l_2319)), l_2320)) == l_2305))) == l_2305) & 0x24C07629L)) | l_2320) != 1L) | 0xF6C4L) || g_348) >= 0xE2L)), l_2320)) & 1L)) & 9UL)), 14)) < 0xCB763CC7L), p_78)))), 0xC92CL)) == 0xD9907E37L) == p_78))) & p_78) & g_321[2][1][3]), p_78)) | 0x64L) <= 0x7715L)))) & 65535UL) == g_1297)), l_2195));
            l_1315[3][0] = (g_2205 |= 0x4A48EC04L);
            for (l_1375 = 0; (l_1375 == (-15)); l_1375 = safe_sub_func_uint8_t_u_u(l_1375, 2))
            {
                uint32_t l_2327 = 1UL;
                int32_t l_2328 = 0L;
                int32_t l_2350 = 0x6D5C394DL;
                int32_t l_2351 = 3L;
                int32_t l_2352 = (-1L);
                int32_t l_2353 = (-9L);
                int32_t l_2356 = 0L;
                int32_t l_2358 = (-4L);
                int32_t l_2361 = 0xDD035D2BL;
                for (l_2253 = 0; (l_2253 <= 9); l_2253 += 1)
                {
                    int32_t l_2341[3][8] = {{0x9DF90294L, 0x792DFA92L, 0x9DF90294L, 0x792DFA92L, 0x9DF90294L, 0x792DFA92L, 0x9DF90294L, 0x792DFA92L}, {0x9DF90294L, 0x792DFA92L, 0x9DF90294L, 0x792DFA92L, 0x9DF90294L, 0x792DFA92L, 0x9DF90294L, 0x792DFA92L}, {0x9DF90294L, 0x792DFA92L, 0x9DF90294L, 0x792DFA92L, 0x9DF90294L, 0x792DFA92L, 0x9DF90294L, 0x792DFA92L}};
                    int32_t l_2411 = 0x20E38AEEL;
                    int i, j;
                    if (((((((-1L) | g_1985[l_2253]) >= (safe_add_func_int8_t_s_s(g_203, ((l_2328 = l_2327) && ((g_139 ^ ((safe_mul_func_int8_t_s_s((((safe_sub_func_int8_t_s_s((((((safe_rshift_func_uint16_t_u_s(((!((((l_2328 |= (-2L)) <= (g_1985[l_2253] || (0xF1L >= (((safe_sub_func_uint16_t_u_u(0x8282L, g_244)) & p_78) && 0x8EL)))) ^ l_1375) && l_2322)) ^ 0x79L), 4)) && g_769) != l_2327) <= l_2305) || p_78), 7L)) | p_78) <= 0UL), 0L)) < g_1271)) > 0xCB9FL))))) != 0x7325C4A9L) != g_328) >= 0x2311L))
                    {
                        int8_t l_2340[8][4][6] = {{{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}};
                        int i, j, k;
                        g_539[0] = (l_81 ^ (safe_mod_func_int32_t_s_s((g_370[3] <= l_2340[5][3][3]), (l_2328 &= (g_3 & 5UL)))));
                    }
                    else
                    {
                        int16_t l_2342 = 0x38EFL;
                        int32_t l_2345 = 0L;
                        int32_t l_2347 = 9L;
                        int32_t l_2357[6][9] = {{0x58A84853L, 0x95EF7520L, (-6L), 0xC7F6F5C7L, 0xC7F6F5C7L, (-6L), 0x95EF7520L, 0x58A84853L, (-6L)}, {0x58A84853L, 0x95EF7520L, (-6L), 0xC7F6F5C7L, 0xC7F6F5C7L, (-6L), 0x95EF7520L, 0x58A84853L, (-6L)}, {0x58A84853L, 0x95EF7520L, (-6L), 0xC7F6F5C7L, 0xC7F6F5C7L, (-6L), 0x95EF7520L, 0x58A84853L, (-6L)}, {0x58A84853L, 0x95EF7520L, (-6L), 0xC7F6F5C7L, 0xC7F6F5C7L, (-6L), 0x95EF7520L, 0x58A84853L, (-6L)}, {0x58A84853L, 0x95EF7520L, (-6L), 0xC7F6F5C7L, 0xC7F6F5C7L, (-6L), 0x95EF7520L, 0x58A84853L, (-6L)}, {0x58A84853L, 0x95EF7520L, (-6L), 0xC7F6F5C7L, 0xC7F6F5C7L, (-6L), 0x95EF7520L, 0x58A84853L, (-6L)}};
                        int32_t l_2366 = (-1L);
                        int8_t l_2367 = (-1L);
                        int i, j;
                        l_2363++;
                        --l_2368;
                        return p_78;
                    }
                    g_2205 = 0L;
                    if ((safe_mul_func_int16_t_s_s(1L, ((0xFEL == ((--g_511) < (((l_2346 &= (g_326[0] < (safe_rshift_func_int16_t_s_s((+(safe_mul_func_int16_t_s_s(((g_1374 |= (safe_mod_func_int32_t_s_s(l_2361, (((((0x9FL >= p_78) != 0xAB7EA391L) >= (l_2362[0][5] ^ (safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(((safe_sub_func_uint8_t_u_u(g_371, g_332)) & l_2158), 4)), 9)))) || (-8L)) || p_78)))) | p_78), g_348))), 1)))) & 0x8AL) && 0UL))) <= g_1985[5]))))
                    {
                        int16_t l_2409 = 0x9D8CL;
                        int32_t l_2412 = 0xCB067F4BL;
                        int i;
                        l_2341[2][6] &= l_2319;
                        l_2388 = g_244;
                        l_2349 = (0xF17EL | (l_2412 = (safe_mod_func_int32_t_s_s((((safe_mul_func_int16_t_s_s((g_1985[l_2253] = ((safe_rshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((((safe_mod_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(((g_2281[2][1] <= (((l_2343 |= (l_2354 = ((((9UL || (l_2341[1][5] = (safe_mod_func_uint32_t_u_u((l_2409 = (safe_lshift_func_uint16_t_u_s((p_78 <= (safe_rshift_func_int16_t_s_u((((0x78EBDEE1L ^ (l_2175 < (safe_mod_func_int8_t_s_s(((g_352 != p_78) <= 0L), g_1374)))) >= g_1374) && 0xB2L), 13))), p_78))), g_1374)))) <= l_2410[6]) == 1UL) < g_2205))) || g_1985[5]) <= 0x5EL)) && g_189), l_2355[7][3])) <= 0x0422L), 1UL)) ^ g_407) < l_2411), l_2355[6][2])), l_2346)) >= (-4L))), g_244)) && 0x171722C9L) < g_2281[2][1]), g_202))));
                        g_2414 = (0xDBL ^ l_2413[4][0]);
                    }
                    else
                    {
                        return l_2321;
                    }
                }
                l_2343 = (safe_mod_func_uint32_t_u_u((safe_mul_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u((g_332 <= (!(l_2346 > ((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint8_t_u_u((safe_mul_func_int16_t_s_s((!(l_2328 |= (safe_rshift_func_uint8_t_u_u(((~(l_2355[0][1] &= (safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s(l_2343, (0x94L && l_2362[2][4]))), ((g_1297 = (safe_sub_func_uint32_t_u_u(((safe_sub_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s((0xA76F3426L <= (safe_unary_minus_func_int32_t_s((-1L)))), 4)), g_326[7])), 0xE705L)) < l_1772), p_78))) & g_2447))))) | 0x310DL), g_595[9])))), 0xF050L)), 0xF1L)), 5)), g_1374)) ^ l_2363)))), g_327[3][0])), l_2349)), 7UL));
                return g_407;
            }
        }
        if ((l_1771 ^= (l_1315[0][0] = p_78)))
        {
            uint8_t l_2464[2];
            int32_t l_2517 = 0L;
            int32_t l_2518 = 1L;
            int i;
            for (i = 0; i < 2; i++)
                l_2464[i] = 0xF0L;
            for (l_2253 = 0; (l_2253 == (-22)); l_2253--)
            {
                int32_t l_2471 = 0L;
                int32_t l_2472[9] = {0x9DA1E28CL, 0xDBED0D0FL, 0x9DA1E28CL, 0xDBED0D0FL, 0x9DA1E28CL, 0xDBED0D0FL, 0x9DA1E28CL, 0xDBED0D0FL, 0x9DA1E28CL};
                int32_t l_2475 = 0x9E2C2DEAL;
                int32_t l_2484[6];
                int i;
                for (i = 0; i < 6; i++)
                    l_2484[i] = (-8L);
                for (g_189 = 0; (g_189 == (-22)); g_189 = safe_sub_func_int16_t_s_s(g_189, 1))
                {
                    uint32_t l_2465 = 0xA9F9FF1BL;
                    int32_t l_2466 = (-8L);
                    if (((p_78 & ((9UL < (safe_add_func_int16_t_s_s((~(l_2320 > g_317)), (65534UL || ((safe_sub_func_int16_t_s_s(l_1375, l_2320)) >= (!(((l_1771 &= g_189) & (safe_mul_func_int8_t_s_s((safe_sub_func_int16_t_s_s((l_2464[1] = p_78), p_78)), p_78))) != p_78))))))) < l_2465)) ^ l_2465))
                    {
                        l_2466 = (g_1297 = g_189);
                        l_2484[5] = ((((+(safe_add_func_uint32_t_u_u(p_78, ((l_2471 |= (+65531UL)) == (l_1315[7][0] = g_348))))) ^ ((l_2472[5] = 0xEE220E93L) <= (safe_lshift_func_int16_t_s_s(l_2475, 6)))) || (safe_add_func_int8_t_s_s((((safe_mul_func_int16_t_s_s((((safe_mul_func_int8_t_s_s((((l_2466 == (l_2355[1][2] = (p_78 ^ (safe_lshift_func_uint8_t_u_s((g_141 < ((l_2475 = g_3) == g_326[0])), 5))))) || l_2464[1]) > 65533UL), 6L)) > l_2413[4][0]) | l_2464[1]), 0x0772L)) | g_321[1][0][2]) && 0xBD01L), l_2472[4]))) != l_2465);
                    }
                    else
                    {
for (l_1772 = 0; l_1772 < 4; l_1772++)
    {
        for (l_2517 = 0; l_2517 < 7; l_2517++)
        {
            transparent_crc(g_252[l_1772][l_2517], "g_252[l_1772][l_2517]", l_2344);
            if (l_2344) printf("index = [%d][%d]\n", l_1772, l_2517);
        }
    };
l_1771 &= ((((p_78 || ((l_2466 = l_2464[1]) & (0x7169L || (l_2484[5] && (safe_lshift_func_int16_t_s_s((l_2465 ^ (safe_mul_func_uint8_t_u_u(l_2464[1], (l_1315[7][0] = p_78)))), (g_2281[0][3] = p_78))))))) == ((safe_mod_func_int32_t_s_s((safe_mod_func_int32_t_s_s((safe_sub_func_int32_t_s_s(((g_370[1] | l_2464[0]) && 0xEEA0285AL), l_2465)), p_78)), g_630)) && p_78)) ^ p_78) <= g_321[0][0][6]);
                    }
                }
                if (((((safe_mul_func_int8_t_s_s((((!(((safe_add_func_int32_t_s_s((safe_lshift_func_int16_t_s_u((!(safe_mod_func_int16_t_s_s(((((p_78 != g_35) && (safe_sub_func_int8_t_s_s(((((safe_mul_func_uint8_t_u_u(((safe_sub_func_int32_t_s_s(((((safe_mod_func_int32_t_s_s(p_78, (safe_mul_func_int8_t_s_s(((p_78 != (g_2037 ^= (0x42B1C396L & (0x7B1E0BEBL != (safe_add_func_int16_t_s_s((l_2517 = ((l_2484[5] = 0xE720F6F6L) >= (g_1297 = ((p_78 > ((l_2158 || g_370[1]) != l_2346)) | p_78)))), 0x1F7DL)))))) <= l_2464[1]), l_2464[1])))) == p_78) >= g_595[3]) <= g_332), l_2346)) != 0x08F8L), g_349)) | 4294967288UL) && p_78) < 0x9989L), 0L))) < p_78) > l_2518), l_2158))), 0)), g_317)) >= l_2346) != 0x6E34CDDCL)) < 0L) <= 0xD690L), l_2464[0])) == p_78) < p_78) >= g_595[7]))
                {
                    uint16_t l_2535 = 0UL;
                    int32_t l_2578 = (-10L);
                    int32_t l_2599 = 0xC8C15CE7L;
                    int16_t l_2619 = 1L;
                    if ((safe_sub_func_uint8_t_u_u(((g_2447 = ((+(safe_mod_func_uint16_t_u_u((p_78 < (!0x9CL)), (safe_rshift_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((safe_sub_func_int32_t_s_s((safe_mul_func_int8_t_s_s((g_1271 = (-9L)), (((g_2281[6][1] > (safe_lshift_func_int16_t_s_u(((l_2355[6][2] = g_326[7]) | (l_2319 ^ p_78)), (g_2447 && ((l_2484[5] = ((g_332 ^= ((l_1315[5][0] = l_2535) || p_78)) > p_78)) && g_141))))) ^ (-5L)) >= g_539[4]))), g_202)), 0x05L)), l_2344))))) || l_2535)) >= 4294967291UL), 0L)))
                    {
                        uint8_t l_2559 = 253UL;
                        int32_t l_2562 = 0x57F85F02L;
                        g_539[5] ^= (safe_rshift_func_uint8_t_u_u((safe_mul_func_int8_t_s_s((-1L), ((l_2535 != (safe_lshift_func_int16_t_s_u(((-10L) & (-1L)), (((safe_sub_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((g_1374 = ((safe_sub_func_int8_t_s_s(((g_139 &= ((+(((safe_rshift_func_uint16_t_u_s((safe_mod_func_uint16_t_u_u(0x79F9L, ((safe_mod_func_uint16_t_u_u((safe_sub_func_int16_t_s_s(((safe_mod_func_int8_t_s_s(((l_2517 = l_2559) | (safe_add_func_int8_t_s_s(p_78, 0x20L))), ((g_511++) & 3UL))) || g_252[2][6]), 0xB3AFL)), 0xC31BL)) && p_78))), 3)) && p_78) == 1L)) & 0xBE89L)) <= 0x574E2B52L), (-8L))) >= p_78)), l_2472[5])), p_78)) && l_2535) >= p_78)))) != p_78))), l_2464[0]));
                        g_2205 ^= (((safe_mod_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s(g_316, (+((g_1985[2] |= ((safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(l_2195, ((p_78 < 0xE603L) & (l_1315[0][0] > (safe_mul_func_uint8_t_u_u(g_189, (l_1772 && ((((g_326[7] = (l_2578 &= ((safe_mod_func_int32_t_s_s(l_1375, p_78)) ^ 255UL))) == g_321[1][0][6]) <= l_2484[4]) != l_1315[5][0])))))))), 6)) == p_78)) != g_511)))) && 0L), p_78)) >= g_630) != g_252[0][5]);
                        return p_78;
                    }
                    else
                    {
                        uint16_t l_2580[8] = {0xAAF3L, 0xF76EL, 0xAAF3L, 0xF76EL, 0xAAF3L, 0xF76EL, 0xAAF3L, 0xF76EL};
                        int32_t l_2603 = 0x5EE68481L;
                        int i;
                        l_2580[6]--;
                        l_2599 &= (~(l_2518 &= ((((0x4B950357L | ((0L < ((!((safe_lshift_func_uint8_t_u_u((+p_78), ((safe_lshift_func_uint16_t_u_u((+(1L < l_2578)), (safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint8_t_u_u(g_189, (l_1787 >= ((g_348 & ((((safe_mul_func_int8_t_s_s((l_83 = l_2597), 0x8BL)) < l_2580[6]) > 8UL) ^ p_78)) > p_78)))), l_2484[4])))) > p_78))) >= p_78)) | l_1771)) == g_347)) > g_151) > l_2598) & l_2319)));
                        g_2205 |= p_78;
                        l_2603 &= (l_2600[6][0][6] && (g_2281[2][1] = (((1UL && (safe_sub_func_uint32_t_u_u(g_352, l_2580[6]))) <= g_252[0][3]) | 0x5DL)));
                    }
                    for (l_2195 = 0; (l_2195 <= 2); l_2195 += 1)
                    {
                        int32_t l_2614 = 8L;
                        int i;
                        l_2517 = (safe_mul_func_int16_t_s_s((2UL && ((safe_rshift_func_uint16_t_u_s((safe_add_func_uint8_t_u_u((g_595[(l_2195 + 3)] ^= ((safe_sub_func_int16_t_s_s((p_78 = g_2447), l_2579)) < (safe_rshift_func_int16_t_s_s(l_2614, ((safe_sub_func_int8_t_s_s(((safe_add_func_uint32_t_u_u(l_2253, ((l_2619 |= g_151) < ((l_1315[4][0] = l_2614) && ((g_326[(l_2195 + 4)] = ((l_2484[5] = 0x9AL) == (((safe_add_func_int16_t_s_s(l_2578, g_1985[9])) >= 0x48L) == l_2614))) < 1UL))))) | l_2578), l_2471)) >= l_2599))))), (-1L))), 5)) < l_2614)), g_203));
                        if (g_1271)
                            continue;
                        if (g_371)
                            continue;
                    }
                    for (l_2175 = (-9); (l_2175 != (-14)); l_2175--)
                    {
                        return l_2306;
                    }
                    if ((safe_unary_minus_func_uint32_t_u(4294967295UL)))
                    {
                        uint32_t l_2625 = 4294967291UL;
for (g_3804 = 0; g_3804 < 1; g_3804++)
                l_2413[l_83][g_3804] = 0xA4CE00A4L;
l_2625++;
                    }
                    else
                    {
                        l_2472[7] = (-1L);
                        l_2355[2][0] = (p_78 | l_2464[1]);
                    }
                }
                else
                {
                    if (g_595[7])
                        break;
                }
                if (l_1315[7][0])
                    break;
            }
            g_2205 = 0x1AAEAEF6L;
        }
        else
        {
            uint32_t l_2664 = 0x4A8B9610L;
            int32_t l_2666 = 8L;
            int32_t l_2668[2][2] = {{(-5L), 1L}, {(-5L), 1L}};
            uint8_t l_2825 = 0xEBL;
            int16_t l_2865 = 0xFE25L;
            int i, j;
            if ((l_1315[4][0] = (l_2349 = ((safe_lshift_func_int16_t_s_s(p_78, 10)) < (l_2320 &= g_327[3][0])))))
            {
                int16_t l_2662 = (-1L);
                int32_t l_2667[7][4] = {{0L, 0L, 0xE2CEC03BL, 0L}, {0L, 0L, 0xE2CEC03BL, 0L}, {0L, 0L, 0xE2CEC03BL, 0L}, {0L, 0L, 0xE2CEC03BL, 0L}, {0L, 0L, 0xE2CEC03BL, 0L}, {0L, 0L, 0xE2CEC03BL, 0L}, {0L, 0L, 0xE2CEC03BL, 0L}};
                uint32_t l_2674 = 4294967290UL;
                int i, j;
                for (l_2320 = 0; (l_2320 != 9); l_2320 = safe_add_func_int32_t_s_s(l_2320, 1))
                {
                    int16_t l_2634 = 0x4038L;
                    int32_t l_2647 = 0xCDC61EAFL;
                    int32_t l_2663 = 1L;
                    int32_t l_2665 = (-1L);
                    int32_t l_2671 = 1L;
                    int32_t l_2672 = 0x7286A018L;
                    int32_t l_2673 = 0L;
                    l_2665 &= (safe_lshift_func_uint8_t_u_s((l_2634 < (safe_mul_func_int8_t_s_s(0x7FL, ((safe_mod_func_uint16_t_u_u(p_78, 0x7E73L)) >= (((safe_add_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s((g_408 &= (safe_add_func_int8_t_s_s(((l_1771 = ((l_2647 = 0xA3L) >= ((+((l_1774 ^ (l_2663 = (safe_rshift_func_uint16_t_u_u((0x4277D4B6L || (safe_mod_func_int16_t_s_s(0x9B7FL, ((safe_mul_func_int16_t_s_s(((~(((safe_mul_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u((safe_rshift_func_int8_t_s_u((0L > (-8L)), 1)), 0x2324L)), g_370[5])) ^ p_78) || p_78)) != p_78), 0x2FBAL)) && g_316)))), l_2662)))) && 0xDF9CL)) <= p_78))) | g_1271), (-1L)))), (-1L))), p_78)) && g_1985[4]), p_78)) | l_2664) | 0xBEL))))), 7));
                    l_2674--;
                }
                for (l_2344 = 0; (l_2344 <= 1); l_2344 += 1)
                {
                    int32_t l_2709[8][5] = {{(-1L), 0x4AD52761L, 0x0C24ADBAL, 0x0C24ADBAL, 0x4AD52761L}, {(-1L), 0x4AD52761L, 0x0C24ADBAL, 0x0C24ADBAL, 0x4AD52761L}, {(-1L), 0x4AD52761L, 0x0C24ADBAL, 0x0C24ADBAL, 0x4AD52761L}, {(-1L), 0x4AD52761L, 0x0C24ADBAL, 0x0C24ADBAL, 0x4AD52761L}, {(-1L), 0x4AD52761L, 0x0C24ADBAL, 0x0C24ADBAL, 0x4AD52761L}, {(-1L), 0x4AD52761L, 0x0C24ADBAL, 0x0C24ADBAL, 0x4AD52761L}, {(-1L), 0x4AD52761L, 0x0C24ADBAL, 0x0C24ADBAL, 0x4AD52761L}, {(-1L), 0x4AD52761L, 0x0C24ADBAL, 0x0C24ADBAL, 0x4AD52761L}};
                    int i, j;
                    if (((safe_rshift_func_int8_t_s_u((((safe_mod_func_int32_t_s_s(((+(g_1271 = ((safe_lshift_func_int16_t_s_u(0x74A0L, 14)) > (safe_add_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s(8L, (safe_mod_func_int16_t_s_s(((!l_2668[l_2344][l_2344]) || (g_2281[1][2] = (((p_78 = (65535UL > 65535UL)) || (2UL == (safe_lshift_func_int16_t_s_u((l_2668[l_2344][l_2344] <= 1UL), 15)))) && (!(l_2667[4][0] = ((safe_lshift_func_int8_t_s_s(((1UL ^ g_370[(l_2344 + 3)]) < g_370[(l_2344 + 4)]), 7)) < g_1297)))))), l_2306)))), g_327[3][0])), l_2664))))) & 0L), l_2668[1][1])) || 0x3218L) > l_2343), 2)) ^ 1L))
                    {
                        return g_370[(l_2344 + 3)];
                    }
                    else
                    {
                        uint32_t l_2704 = 1UL;
                        uint16_t l_2733 = 0UL;
                        int16_t l_2734 = (-1L);
                        volatile int32_t l_2735 = 0xC144067DL;
                        l_2355[3][1] ^= (safe_sub_func_uint32_t_u_u((((p_78 |= 1L) <= (l_2668[l_2344][l_2344] = (safe_sub_func_uint8_t_u_u((g_408 || ((l_2662 ^ (-6L)) || l_2704)), g_2281[2][1])))) != ((((((safe_mod_func_int16_t_s_s(l_2664, (safe_lshift_func_uint16_t_u_s((--g_511), 2)))) & (((safe_mod_func_uint32_t_u_u((g_244 = (safe_add_func_int32_t_s_s(((((safe_mod_func_int8_t_s_s((((!(safe_mod_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((l_1315[1][0] = (safe_mod_func_uint8_t_u_u((safe_mul_func_int16_t_s_s((safe_add_func_uint32_t_u_u((((safe_rshift_func_int8_t_s_s((5UL && ((safe_lshift_func_int16_t_s_u((0x5BL < (-8L)), 10)) < l_2664)), 5)) == l_2733) > l_2662), l_1772)), 0x51F1L)), 0xC7L))) != l_2306), l_2600[3][0][6])), g_1374))) | g_202) | l_81), l_2666)) <= g_1374) > 0x84E8A476L) == l_2733), l_2346))), 0x87F6B1F9L)) && l_2709[0][1]) == g_2414)) >= 0L) & g_370[(l_2344 + 3)]) >= g_370[(l_2344 + 3)]) < l_2733)), l_2734));
                        l_2709[5][1] = g_352;
                        l_2735 = g_352;
                        if (l_1787)
                            continue;
                    }
                    for (l_2320 = 0; (l_2320 <= 5); l_2320 += 1)
                    {
                        l_2667[1][1] = ((l_2413[4][0] && ((p_78 == p_78) != ((safe_add_func_uint8_t_u_u(g_1985[5], 0x6AL)) && 251UL))) == (safe_rshift_func_uint8_t_u_s(p_78, (safe_mod_func_int16_t_s_s((((safe_rshift_func_uint8_t_u_u((safe_mod_func_int16_t_s_s(((0x24L == l_2668[l_2344][l_2344]) && 2UL), 0x186BL)), 6)) <= g_511) != g_630), (-1L))))));
                        l_2759 &= (!((g_321[3][1][1] && (!p_78)) != (safe_mod_func_uint8_t_u_u((l_2667[2][0] = (l_2318 & ((-1L) <= (g_151 | (safe_mod_func_uint8_t_u_u((safe_add_func_int32_t_s_s(7L, (!(safe_lshift_func_uint8_t_u_u(((255UL ^ (-8L)) || (g_1374 >= 0x11L)), 7))))), p_78)))))), p_78))));
                        l_2668[1][1] = (g_139 = (safe_mod_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((l_2709[5][4] ^ (((p_78 && (safe_mul_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u((l_2667[6][0] = ((g_973 < (g_1271 = ((g_2414 = (safe_sub_func_int8_t_s_s(((((0UL < (safe_lshift_func_uint8_t_u_s(((safe_mod_func_uint16_t_u_u((p_78 < (l_2669[0] && (g_352 > (safe_rshift_func_int16_t_s_s(p_78, g_630))))), p_78)) <= 1L), 5))) > 0x51L) ^ l_2666) >= l_2598), p_78))) & p_78))) < 0x3403L)), g_2281[3][1])), 1UL))) == l_1375) != (-2L))), 2)), g_151)));
                    }
                    for (g_1374 = 0; (g_1374 <= 7); g_1374 += 1)
                    {
                        uint32_t l_2778 = 0xC83BF742L;
                        l_2778++;
                    }
                }
                for (g_407 = 18; (g_407 == 43); g_407++)
                {
                    uint32_t l_2808 = 18446744073709551615UL;
                    l_2667[0][0] = (((g_141--) <= ((l_2666 = (((0x53L != (p_78 <= (safe_add_func_uint8_t_u_u(((l_1315[0][0] = g_321[1][2][2]) && ((g_2447--) == 1UL)), (((safe_rshift_func_uint8_t_u_u(p_78, g_326[6])) || ((safe_lshift_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s(((g_326[7]++) || (safe_rshift_func_int16_t_s_u(((((g_973 = ((safe_rshift_func_uint16_t_u_s((safe_sub_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(g_244, 5)), l_2600[5][0][0])), 4)) > (!g_348))) & g_2205) & p_78) && (-10L)), 14))), 3)), p_78)) > 0x35E0163BL)) & l_2808))))) < l_2668[1][0]) >= 1L)) && 1L)) & (-1L));
                    l_83 ^= ((((g_139 &= ((p_78 == ((((g_352 > ((safe_mod_func_uint16_t_u_u(l_1315[7][0], (safe_mod_func_int8_t_s_s(((safe_rshift_func_int8_t_s_s((safe_add_func_uint8_t_u_u(((((g_408 = ((g_348 <= g_408) > (((((l_2597 &= (safe_lshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_s(l_2666, p_78)), 11))) && g_327[1][0]) >= (safe_add_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u(l_2808, p_78)) || g_203), p_78))) && p_78) <= g_2414))) <= l_2413[4][0]) ^ l_2808) && l_2666), g_2447)), g_407)) >= g_202), g_769)))) > g_370[1])) ^ p_78) ^ 3UL) == p_78)) || 0x819BE890L)) ^ l_2825) == 4294967289UL) | 0x11E1L);
                }
            }
            else
            {
                int32_t l_2831[2];
                int i;
                for (i = 0; i < 2; i++)
                    l_2831[i] = 0x4F882679L;
                for (g_973 = 0; (g_973 >= 38); g_973++)
                {
                    int8_t l_2862 = 0x05L;
for (l_1772 = 0; l_1772 < 1; l_1772++)
    {
        transparent_crc(g_3612[l_1772], "g_3612[l_1772]", g_2205);
        if (g_2205) printf("index = [%d]\n", l_1772);
    };
g_139 |= (g_252[2][6] >= (safe_unary_minus_func_int32_t_s(((l_2831[0] ^= (safe_mod_func_int16_t_s_s(p_78, g_1271))) ^ l_2832))));
                    if (p_78)
                    {
                        int32_t l_2863 = 0L;
                        int32_t l_2864 = 0xAA6A9740L;
                        g_1297 &= (safe_lshift_func_int8_t_s_s(((p_78 & (l_2864 = (g_203 | (((safe_sub_func_uint8_t_u_u(((safe_mod_func_uint32_t_u_u(((((((safe_lshift_func_uint16_t_u_s((safe_add_func_int32_t_s_s((0x29L ^ (g_1374 = (safe_lshift_func_int8_t_s_s(p_78, 2)))), ((safe_add_func_uint8_t_u_u(((g_328 > (1L && ((safe_lshift_func_int8_t_s_u(0x7FL, 4)) && (l_2862 = (((safe_mod_func_int16_t_s_s((g_1985[5] = ((safe_rshift_func_int8_t_s_u((l_2831[0] = (safe_add_func_int8_t_s_s((!((safe_add_func_uint32_t_u_u((safe_mod_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(g_2281[6][3], g_321[0][1][8])), p_78)), g_2205)) <= l_2825)), 0x7FL))), 3)) && 0L)), p_78)) < 0xDAL) ^ 0xB4L))))) | (-1L)), 1UL)) > 0xBFL))), l_2668[1][1])) >= l_2863) && 0xBFFF5383L) <= 0xA722L) | p_78) > l_2863), p_78)) < g_321[0][1][8]), l_2759)) != 0x1AL) && l_2831[0])))) < 1L), g_203));
                        g_539[8] = 0x04D91F01L;
                        l_2865 ^= (4L <= p_78);
                    }
                    else
                    {
                        int16_t l_2872 = 1L;
                        int32_t l_2877 = (-1L);
                        g_352 = ((safe_lshift_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s(((safe_sub_func_uint16_t_u_u(g_349, (p_78 &= l_2872))) <= g_2447), 6)), l_2865)) < (safe_rshift_func_uint8_t_u_u((1UL >= (safe_mul_func_int8_t_s_s((-5L), (l_2877 = 0xFAL)))), (safe_add_func_int16_t_s_s((safe_add_func_int32_t_s_s((+g_371), (((safe_add_func_int8_t_s_s(g_1374, l_2348)) & l_2668[0][0]) >= l_2872))), g_252[2][6])))));
g_141 &= (j = 0x9D46L);
g_2205 = ((((~((safe_lshift_func_uint8_t_u_s(5UL, (((l_83 = (g_202 = (g_2888 < (safe_mul_func_int16_t_s_s(0x7240L, ((0x1DL < (g_973 ^ (l_1315[7][0] = (p_78 = (((l_2877 |= ((g_1271 = (l_2668[1][1] = p_78)) == (safe_mod_func_uint32_t_u_u(((safe_mod_func_uint16_t_u_u((!p_78), l_1774)) ^ p_78), l_2872)))) ^ l_2664) != 0xCA4FC1E9L))))) > g_511)))))) <= 0x0739L) && 255UL))) <= l_1720)) > g_2447) <= g_1374) != l_2872);
                        return l_2877;
                    }
                }
                l_83 = ((p_78 < (g_151 = l_2825)) > ((g_595[4] = l_2831[0]) ^ p_78));
            }
            l_2346 = ((((safe_mul_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(g_539[3], g_2037)), (((!((((((p_78 <= ((65535UL || ((((safe_add_func_uint32_t_u_u(((4294967295UL && ((p_78 > 0x5EL) ^ l_2600[6][0][6])) & (safe_add_func_int16_t_s_s(p_78, 0x13C5L))), p_78)) || l_2865) & (-2L)) && g_370[1])) | p_78)) || p_78) == l_2349) ^ 0x5FL) < g_2205) || l_2668[1][1])) != g_370[0]) > 251UL))) > p_78) && l_1375) ^ 0xB3L);
            l_2915 = ((safe_rshift_func_int8_t_s_u((safe_rshift_func_int16_t_s_s((((safe_mod_func_int16_t_s_s((g_206 & (l_2668[0][1] >= (safe_mul_func_uint8_t_u_u(((safe_sub_func_uint16_t_u_u((l_2360 > l_2915), 0x07DEL)) > l_2344), p_78)))), (safe_lshift_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((l_2349 >= ((safe_sub_func_int16_t_s_s(((+(safe_rshift_func_uint16_t_u_u((l_2925 & l_2668[1][1]), 15))) < 5UL), 0x8EC0L)) < l_2320)), 1)), l_1771)))) < g_141) >= l_2926[1][2][5]), 11)), l_2865)) == l_2668[0][0]);
            if (g_2281[4][1])
                continue;
        }
        l_2915 = (0x3E58L > 0UL);
        return l_2344;
    }
    return g_327[1][0];
}
inline static uint8_t func_94(uint32_t p_95, uint32_t p_96)
{
    uint8_t l_100[5][8][6] = {{{255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}}, {{255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}}, {{255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}}, {{255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}}, {{255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}, {255UL, 0xD6L, 254UL, 246UL, 0xF5L, 0UL}}};
    uint16_t l_113[9][6] = {{0xBF6CL, 1UL, 0xBF6CL, 65531UL, 65529UL, 0x1128L}, {0xBF6CL, 1UL, 0xBF6CL, 65531UL, 65529UL, 0x1128L}, {0xBF6CL, 1UL, 0xBF6CL, 65531UL, 65529UL, 0x1128L}, {0xBF6CL, 1UL, 0xBF6CL, 65531UL, 65529UL, 0x1128L}, {0xBF6CL, 1UL, 0xBF6CL, 65531UL, 65529UL, 0x1128L}, {0xBF6CL, 1UL, 0xBF6CL, 65531UL, 65529UL, 0x1128L}, {0xBF6CL, 1UL, 0xBF6CL, 65531UL, 65529UL, 0x1128L}, {0xBF6CL, 1UL, 0xBF6CL, 65531UL, 65529UL, 0x1128L}, {0xBF6CL, 1UL, 0xBF6CL, 65531UL, 65529UL, 0x1128L}};
    uint8_t l_118 = 0x29L;
    int32_t l_119[2];
    int32_t l_120 = 1L;
    int32_t l_121 = 0x393CC16AL;
    uint32_t l_170 = 0UL;
    int32_t l_201 = 0x86D0EF2AL;
    uint32_t l_520 = 0xB83F8AA4L;
    int16_t l_633 = 9L;
    int16_t l_671[2][2];
    uint8_t l_732 = 0x7EL;
    uint16_t l_846 = 0x0929L;
    uint8_t l_932 = 0UL;
    int8_t l_1072 = 0xC4L;
    int32_t l_1073 = 0x2134D653L;
    int32_t l_1213 = (-9L);
    int16_t l_1266 = 0x0E0FL;
    int i, j, k;
    for (i = 0; i < 2; i++)
        l_119[i] = 0xD9FCA902L;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            l_671[i][j] = 0xF53BL;
    }
g_139 |= p_96;
if ((safe_mul_func_uint8_t_u_u((((((l_100[3][2][0] || (((0x0493L ^ l_100[4][4][5]) & (safe_mul_func_uint16_t_u_u((safe_mul_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s(((0xA3D26D73L | ((safe_mod_func_int32_t_s_s((l_121 |= (0x9B1DFB68L != (((safe_rshift_func_uint16_t_u_s((l_113[0][4] < ((-1L) == ((((l_119[0] = (safe_mul_func_uint16_t_u_u((safe_mod_func_int32_t_s_s(0x8FB3CF24L, ((l_118 ^ g_35) || p_95))), 0xDEA1L))) <= l_113[0][4]) == g_3) ^ l_120))), l_100[4][2][4])) < g_35) < 0x4236L))), g_35)) < g_35)) != p_95), p_96)) <= 0x74L), 0xE7L)), g_35))) || g_35)) != 0x7174L) || (-1L)) < l_120) == l_118), p_96)))
    {
        int8_t l_146[1][6];
        int32_t l_166[4];
        int32_t l_195 = 0x45B68A7DL;
        int32_t l_279 = 8L;
        int16_t l_552 = 5L;
        int16_t l_553 = 0L;
        int32_t l_582[4][9][4] = {{{(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}}, {{(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}}, {{(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}}, {{(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}, {(-1L), 0L, 0L, 7L}}};
        uint32_t l_715 = 0xC7AF61AAL;
        int i, j, k;
        for (i = 0; i < 1; i++)
        {
            for (j = 0; j < 6; j++)
                l_146[i][j] = 0xB0L;
        }
        for (i = 0; i < 4; i++)
            l_166[i] = 0x59C151ECL;
        for (l_118 = 0; (l_118 > 35); l_118++)
        {
            uint32_t l_140 = 4294967289UL;
            int32_t l_143 = 0x25659527L;
            for (p_95 = 29; (p_95 <= 58); p_95 = safe_add_func_int8_t_s_s(p_95, 8))
            {
                int8_t l_130 = (-9L);
                int32_t l_144 = 5L;
                for (l_120 = 0; (l_120 <= 1); l_120 += 1)
                {
                    int32_t l_142 = 0L;
                    int32_t l_165[10][6] = {{1L, 7L, (-1L), 1L, 0L, 0x7AAF5FA4L}, {1L, 7L, (-1L), 1L, 0L, 0x7AAF5FA4L}, {1L, 7L, (-1L), 1L, 0L, 0x7AAF5FA4L}, {1L, 7L, (-1L), 1L, 0L, 0x7AAF5FA4L}, {1L, 7L, (-1L), 1L, 0L, 0x7AAF5FA4L}, {1L, 7L, (-1L), 1L, 0L, 0x7AAF5FA4L}, {1L, 7L, (-1L), 1L, 0L, 0x7AAF5FA4L}, {1L, 7L, (-1L), 1L, 0L, 0x7AAF5FA4L}, {1L, 7L, (-1L), 1L, 0L, 0x7AAF5FA4L}, {1L, 7L, (-1L), 1L, 0L, 0x7AAF5FA4L}};
                    int i, j;
                    l_119[l_120] = l_121;
                    l_144 = (safe_add_func_int8_t_s_s((safe_sub_func_int32_t_s_s((l_119[l_120] && (g_35 & l_130)), ((safe_mul_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s(((safe_add_func_uint8_t_u_u(((l_142 = (p_96 > (g_141 &= (((safe_add_func_uint32_t_u_u(0UL, l_130)) > g_3) ^ ((g_139 &= g_35) >= (l_140 |= (p_96 < g_35))))))) || g_3), 0x1FL)) | l_143), 3)), 255UL)) & g_35))), g_35));
                    l_143 |= ((((l_146[0][4] = (~g_139)) || (l_140 == ((l_166[0] = (((l_165[3][3] &= ((l_146[0][4] != 0x9DL) || (safe_mul_func_uint8_t_u_u(((g_139 > g_141) == ((0x69DCB871L || (l_144 = (((l_119[l_120] |= 0xF41BL) >= (safe_sub_func_int16_t_s_s(((g_151--) ^ (safe_lshift_func_uint16_t_u_s((safe_mul_func_uint16_t_u_u(((safe_sub_func_int16_t_s_s((safe_sub_func_int32_t_s_s((safe_mul_func_uint16_t_u_u(((safe_unary_minus_func_int32_t_s(p_96)) >= 8L), l_142)), 0x52D1B5B4L)), p_96)) == g_139), p_96)), g_3))), p_95))) ^ l_146[0][4]))) | l_130)), 252UL)))) == 0x5B22CD46L) | 0x9E99L)) || 4294967293UL))) | g_141) <= 4294967295UL);
                }
            }
        }
        if (((p_95 ^ (0xC4L < (l_119[0] = (!((safe_add_func_uint16_t_u_u((((0xF7C8C0EFL <= l_170) ^ ((0x01L && (g_189 = (((safe_rshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_s((safe_lshift_func_uint8_t_u_s((((safe_sub_func_int8_t_s_s((safe_lshift_func_int8_t_s_s(p_95, (l_166[0] = ((safe_mod_func_int16_t_s_s(0x9511L, (l_120 && (safe_mod_func_uint32_t_u_u((((safe_sub_func_uint16_t_u_u((safe_sub_func_int8_t_s_s(((0x1776L ^ 0x3A1DL) != (-4L)), g_141)), g_141)) | g_151) | 0x6230L), g_35))))) & p_95)))), 0x91L)) != p_96) <= l_119[0]), 7)), p_95)), l_118)) ^ 2L) || 9UL))) ^ l_119[0])) == 0x597B2851L), l_118)) <= l_100[3][2][0]))))) == 0UL))
        {
            l_121 = (p_95 & l_146[0][1]);
        }
        else
        {
            int16_t l_210[6] = {0x6F54L, 0x6F54L, 0x8150L, 0x6F54L, 0x6F54L, 0x8150L};
            int32_t l_211 = (-1L);
            int32_t l_212[10][2][2] = {{{0L, 0xFE30F79AL}, {0L, 0xFE30F79AL}}, {{0L, 0xFE30F79AL}, {0L, 0xFE30F79AL}}, {{0L, 0xFE30F79AL}, {0L, 0xFE30F79AL}}, {{0L, 0xFE30F79AL}, {0L, 0xFE30F79AL}}, {{0L, 0xFE30F79AL}, {0L, 0xFE30F79AL}}, {{0L, 0xFE30F79AL}, {0L, 0xFE30F79AL}}, {{0L, 0xFE30F79AL}, {0L, 0xFE30F79AL}}, {{0L, 0xFE30F79AL}, {0L, 0xFE30F79AL}}, {{0L, 0xFE30F79AL}, {0L, 0xFE30F79AL}}, {{0L, 0xFE30F79AL}, {0L, 0xFE30F79AL}}};
            int8_t l_221[5] = {(-4L), 1L, (-4L), 1L, (-4L)};
            int16_t l_369 = 1L;
            uint16_t l_476 = 65535UL;
            int8_t l_512[1];
            int32_t l_536 = 0x6F4701A0L;
            int8_t l_542 = 0x17L;
            int32_t l_566 = 1L;
            int8_t l_729 = 0xC0L;
            uint8_t l_758 = 0UL;
            int16_t l_766 = 0xF985L;
            int i, j, k;
            for (i = 0; i < 1; i++)
                l_512[i] = (-1L);
            for (g_139 = 4; (g_139 >= 0); g_139 -= 1)
            {
                int32_t l_200 = 0x90B94B68L;
                int32_t l_209[4];
                uint32_t l_243 = 0x20C38ADFL;
                int i;
                for (i = 0; i < 4; i++)
                    l_209[i] = 0x199E9942L;
                if ((safe_add_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s((l_119[0] = ((safe_unary_minus_func_int8_t_s((l_195 || p_96))) <= (safe_mod_func_int32_t_s_s(((safe_mul_func_uint16_t_u_u((l_200 = p_96), ((l_119[1] | (l_121 = 0x5CBCL)) <= (g_206 = (g_203++))))) ^ (safe_add_func_uint8_t_u_u((((l_201 = (((g_151--) >= (safe_unary_minus_func_uint16_t_u(g_3))) == ((~(safe_lshift_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u(65535UL, 12)), 1))) ^ l_113[1][1]))) >= p_96) <= 0xCF50F0EDL), g_202))), g_35)))), l_221[1])), l_212[0][1][1])))
                {
                    uint8_t l_234 = 0xD7L;
                    uint32_t l_245[3];
                    int16_t l_280 = 8L;
                    int32_t l_281[6];
                    int i;
                    for (i = 0; i < 3; i++)
                        l_245[i] = 0UL;
                    for (i = 0; i < 6; i++)
                        l_281[i] = 0x13051B3FL;
                    if ((0x4CL & (((safe_sub_func_int16_t_s_s(0x02C9L, (safe_lshift_func_int16_t_s_u((safe_sub_func_int32_t_s_s(((safe_mod_func_int16_t_s_s((safe_lshift_func_uint8_t_u_u((g_244 |= (((safe_sub_func_uint8_t_u_u(0xBFL, g_151)) & (l_234 <= (safe_sub_func_int32_t_s_s(4L, (safe_mul_func_int8_t_s_s((safe_mod_func_int8_t_s_s((l_211 = (safe_mul_func_int16_t_s_s(l_234, l_195))), p_96)), 0L)))))) & l_243)), l_118)), l_209[0])) | g_35), 0xEB9CEF92L)), 6)))) && l_245[2]) && g_206)))
                    {
                        return g_244;
                    }
                    else
                    {
                        int32_t l_255[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_255[i] = 0xB1AC60CBL;
                        l_255[1] ^= (p_96 < (0xF701L <= (safe_add_func_int32_t_s_s((safe_mul_func_int16_t_s_s((g_139 < ((p_96 < 0x31L) < (safe_rshift_func_int8_t_s_u(((g_252[2][6] = g_35) && 0x21351B3BL), 1)))), ((safe_mul_func_int8_t_s_s(g_189, g_151)) | 65534UL))), l_245[0]))));
                        l_281[5] = (g_202 == (safe_mul_func_int8_t_s_s(g_151, ((l_210[1] || ((safe_mod_func_uint32_t_u_u(((safe_mul_func_uint8_t_u_u((((((safe_mul_func_uint8_t_u_u((((safe_mod_func_uint8_t_u_u(((l_211 = (safe_sub_func_int8_t_s_s((((l_279 = (safe_mul_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u((safe_unary_minus_func_uint32_t_u(((safe_lshift_func_uint16_t_u_s((l_201 |= (l_212[8][1][1] = ((safe_sub_func_int16_t_s_s(g_244, l_170)) != l_234))), 12)) != ((l_166[2] = p_96) == (l_119[0] = (p_96 < (safe_rshift_func_uint8_t_u_s(((l_200 = l_146[0][4]) | 0xFCL), g_203)))))))), p_95)), p_96))) || p_95) > p_96), p_95))) <= g_252[2][6]), p_96)) <= g_141) < p_95), g_252[1][4])) || l_280) < l_100[3][2][0]) && l_212[8][1][0]) == p_96), 0xA3L)) || 2UL), g_252[1][4])) >= g_206)) ^ g_252[2][6]))));
                    }
                    if ((safe_mul_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((((0UL || (safe_rshift_func_uint16_t_u_s(p_96, (safe_rshift_func_int16_t_s_s((g_252[0][5] == g_139), 0))))) ^ 0xFA67B818L) ^ (safe_add_func_uint32_t_u_u(g_151, g_202))), l_221[3])), (((safe_lshift_func_uint16_t_u_s(p_95, 11)) <= l_211) || g_206))))
                    {
                        int32_t l_298 = 0L;
                        g_317 ^= ((((safe_sub_func_int32_t_s_s((g_202 > (safe_lshift_func_int16_t_s_s(p_95, 4))), l_298)) || p_95) ^ (safe_sub_func_uint32_t_u_u(((safe_unary_minus_func_int32_t_s((p_95 <= (!(~(safe_mod_func_int16_t_s_s((safe_add_func_int16_t_s_s(g_139, ((safe_mul_func_int16_t_s_s((safe_mod_func_int32_t_s_s((l_209[0] = (safe_sub_func_uint32_t_u_u((safe_rshift_func_int8_t_s_u(g_316, 3)), l_281[5]))), l_212[9][1][1])), l_281[5])) ^ g_202))), l_245[2]))))))) && 0xBD2F91FEL), (-1L)))) > 0x1367L);
                    }
                    else
                    {
                        int32_t l_320 = 0L;
                        l_281[5] |= (safe_add_func_int8_t_s_s((l_166[0] |= g_203), (l_320 = (1L < p_96))));
                        --g_321[0][1][8];
                    }
                    return g_316;
                }
                else
                {
                    for (l_211 = 5; (l_211 >= 1); l_211 -= 1)
                    {
                        int i, j;
                        l_209[2] = ((g_327[3][0] = (l_279 &= (g_326[7] = (safe_mul_func_int16_t_s_s(l_113[g_139][l_211], g_189))))) != p_95);
                    }
                    g_328 &= 0x6EC8D345L;
                    for (l_121 = 0; (l_121 <= 3); l_121 += 1)
                    {
                        int i;
                        return l_221[l_121];
                    }
                }
                for (g_141 = 0; (g_141 <= 5); g_141 += 1)
                {
                    uint16_t l_331 = 65535UL;
                    int32_t l_409[1];
                    int i, j;
                    for (i = 0; i < 1; i++)
                        l_409[i] = 0x241E8053L;
                    g_332 = (0x8AA5749FL <= (l_331 = ((l_212[9][1][1] ^= (safe_rshift_func_uint8_t_u_s(255UL, 3))) < (g_317 &= 0xB9L))));
                    for (l_201 = 0; (l_201 <= 4); l_201 += 1)
                    {
                        g_347 |= (((-2L) | p_96) != (safe_mul_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u((((safe_add_func_uint32_t_u_u(p_95, (safe_lshift_func_uint8_t_u_u(0x21L, (0x94D3L <= (safe_add_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u(255UL, (safe_mul_func_int16_t_s_s(p_95, (l_212[9][1][1] = l_118))))), l_100[3][2][0]))))))) == g_203) && p_95), g_203)), 0UL)));
                        g_349++;
                        if (g_327[3][0])
                            {
for (i = 0; i < 4; i++)
                    l_209[i] = 0x4ED5E062L;
continue;}
                        g_353--;
                    }
                    g_352 = (g_371 &= (g_370[1] = (((((safe_mod_func_int32_t_s_s(((-4L) > ((safe_add_func_uint8_t_u_u(((2L >= ((safe_sub_func_uint16_t_u_u(((safe_mul_func_int16_t_s_s((p_95 == ((l_209[0] ^ (((safe_sub_func_int8_t_s_s(g_252[2][6], ((l_212[9][1][1] = g_3) >= (~(p_95 <= g_252[2][6]))))) > ((((safe_unary_minus_func_uint8_t_u((safe_unary_minus_func_uint32_t_u(((((0x0FL <= p_95) != 4L) != l_369) > l_331))))) >= l_331) < l_209[0]) | g_202)) != 0xAC76L)) == (-3L))), p_95)) >= g_332), 65533UL)) != p_96)) == p_96), 250UL)) != g_348)), g_327[3][0])) == l_243) == g_252[2][6]) & 0L) | l_201)));
                    if (((l_409[0] = (+(safe_add_func_uint32_t_u_u((p_95 ^ ((g_370[1] >= (((safe_add_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_s((safe_lshift_func_int16_t_s_u((0UL > p_95), 4)), 9)) < (safe_mul_func_int16_t_s_s((g_202 = (l_166[0] = (safe_rshift_func_int8_t_s_s(l_369, ((~(((safe_sub_func_int32_t_s_s((((safe_add_func_uint32_t_u_u(4294967290UL, ((((safe_add_func_int32_t_s_s(p_96, (((safe_unary_minus_func_uint8_t_u((((l_121 = (safe_rshift_func_uint16_t_u_u((((safe_add_func_uint16_t_u_u(((g_408 |= (g_332 &= (g_317 = (safe_rshift_func_int8_t_s_s((l_209[3] <= (safe_mod_func_int8_t_s_s(((safe_mod_func_int32_t_s_s((safe_mul_func_int8_t_s_s((((((safe_lshift_func_uint16_t_u_s((g_326[2] |= (l_113[(g_139 + 2)][g_141] = 0xA15FL)), p_96)) || (-1L)) && (-1L)) < 1L) <= g_407), l_146[0][0])), 0x6C8E8B94L)) < p_95), 0xC5L))), p_96))))) <= p_96), g_139)) && g_347) ^ p_96), 10))) ^ l_331) & l_279))) != 0xD0L) != g_3))) ^ 0xA440L) != l_243) == 1UL))) <= g_35) ^ l_212[9][1][1]), g_370[1])) == l_146[0][4]) > p_96)) >= l_221[2]))))), g_370[1]))), l_209[2])) && l_243) & 1L)) & p_95)), l_146[0][4])))) && l_209[2]))
                    {
                        int32_t l_420 = 0x33C2831BL;
                        g_352 = (safe_mul_func_uint8_t_u_u((((g_206 < p_95) && ((g_141 != (((safe_lshift_func_int16_t_s_s((l_119[0] ^= 0x5373L), (safe_lshift_func_uint8_t_u_u((4294967293UL ^ (safe_mul_func_uint16_t_u_u((l_121 > (l_279 = 0x984FL)), (l_200 = (safe_sub_func_int8_t_s_s(((((l_420 = p_95) <= (l_209[0] = 0x1A9D1914L)) > 4294967295UL) > l_210[3]), (-9L))))))), 7)))) > g_371) < l_118)) ^ 0x282AL)) != 0xE3L), (-1L)));
                        g_352 = g_203;
                        g_352 ^= 0x77B47BBFL;
                    }
                    else
                    {
                        uint32_t l_421 = 0xB574CE6EL;
                        l_421--;
                        if (g_139)
                            break;
                        if (g_349)
                            continue;
                        return p_96;
                    }
                    for (g_206 = 1; (g_206 <= 4); g_206 += 1)
                    {
                        l_211 = l_369;
                        return g_371;
                    }
                }
            }
            if (p_95)
            {
                int32_t l_424 = 0x2F012C45L;
                int32_t l_453 = (-4L);
                if (l_424)
                {
for (i = 0; i < 2; i++)
        l_119[i] = 0xD9FCA902L;
for (g_348 = 0; (g_348 >= (-6)); --g_348)
                    {
for (g_139 = 0; g_139 < 9; g_139++)
            {
                transparent_crc(g_321[g_1297][j][g_139], "g_321[g_1297][j][g_139]", l_121);
                if (l_121) printf("index = [%d][%d][%d]\n", g_1297, j, g_139);
            };
if (g_348)
                            break;
                        if (p_95)
                            break;
                    }
                }
                else
                {
                    uint32_t l_450[3][10] = {{4294967288UL, 4294967288UL, 1UL, 0x4BAC0EDAL, 0x9172D43EL, 0x8350BCA1L, 0x9172D43EL, 0x4BAC0EDAL, 1UL, 4294967288UL}, {4294967288UL, 4294967288UL, 1UL, 0x4BAC0EDAL, 0x9172D43EL, 0x8350BCA1L, 0x9172D43EL, 0x4BAC0EDAL, 1UL, 4294967288UL}, {4294967288UL, 4294967288UL, 1UL, 0x4BAC0EDAL, 0x9172D43EL, 0x8350BCA1L, 0x9172D43EL, 0x4BAC0EDAL, 1UL, 4294967288UL}};
                    int i, j;
l_424 -= 1;
if ((!((safe_sub_func_int16_t_s_s(l_424, (l_279 &= (l_166[0] = ((safe_mul_func_uint8_t_u_u(p_95, p_95)) < ((safe_rshift_func_int16_t_s_u(p_95, (l_201 &= (++g_141)))) <= (safe_rshift_func_uint8_t_u_s(((safe_sub_func_uint32_t_u_u((safe_mul_func_uint16_t_u_u(l_146[0][4], (safe_lshift_func_uint16_t_u_s(l_210[3], 8)))), ((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(8L, (safe_lshift_func_int8_t_s_s(p_95, ((0L != p_95) < 0x6C5B90CCL))))), 14)) >= 6L))) >= 1L), 1)))))))) | l_424)))
                    {
                        g_352 = (-5L);
                    }
                    else
                    {
                        uint16_t l_454 = 65535UL;
                        --l_450[0][4];
                        l_119[0] = 0x7AAC8604L;
                        l_454++;
                    }
                    g_352 = 0x2E0544A2L;
                    g_139 = ((l_279 = (safe_rshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_s((g_317 = p_96), l_113[0][4])), 9)) < (p_96 != l_119[0])), (0xE14CE5E2L ^ p_95))), (safe_mod_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(((((l_212[9][1][1] = 0xAE98L) || (safe_add_func_uint32_t_u_u((+(p_96 >= (safe_rshift_func_int8_t_s_s((g_332 &= (p_95 < 0x178FB9EDL)), p_96)))), g_407))) <= g_347) > l_450[0][4]), l_476)), g_349)))), 6))) != p_96);
                }
            }
            else
            {
                uint32_t l_487 = 0x97DDFD42L;
                int32_t l_513 = (-1L);
                int32_t l_537 = 0x0BED18ACL;
                int32_t l_538[7] = {(-1L), (-10L), (-1L), (-10L), (-1L), (-10L), (-1L)};
                uint32_t l_587[6][6] = {{0x8151DAF6L, 0x367D935BL, 0x8151DAF6L, 0x367D935BL, 0x8151DAF6L, 0x367D935BL}, {0x8151DAF6L, 0x367D935BL, 0x8151DAF6L, 0x367D935BL, 0x8151DAF6L, 0x367D935BL}, {0x8151DAF6L, 0x367D935BL, 0x8151DAF6L, 0x367D935BL, 0x8151DAF6L, 0x367D935BL}, {0x8151DAF6L, 0x367D935BL, 0x8151DAF6L, 0x367D935BL, 0x8151DAF6L, 0x367D935BL}, {0x8151DAF6L, 0x367D935BL, 0x8151DAF6L, 0x367D935BL, 0x8151DAF6L, 0x367D935BL}, {0x8151DAF6L, 0x367D935BL, 0x8151DAF6L, 0x367D935BL, 0x8151DAF6L, 0x367D935BL}};
                int8_t l_625 = 0L;
                int32_t l_628 = 0L;
                int16_t l_629 = (-1L);
                uint32_t l_676 = 1UL;
                int32_t l_723 = (-1L);
                uint32_t l_726 = 1UL;
                int i, j;
                if ((safe_lshift_func_uint8_t_u_s(((safe_sub_func_uint16_t_u_u((l_166[3] > (l_201 |= (l_212[9][1][1] |= l_166[0]))), l_119[0])) < (safe_mod_func_int16_t_s_s(l_146[0][4], (safe_mod_func_uint8_t_u_u(((l_211 = (((l_221[4] ^ ((safe_rshift_func_int8_t_s_u((0UL <= ((l_119[0] || (l_487 = 0UL)) && (safe_sub_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(((g_317 = l_487) != p_96), l_120)), p_95)))), 3)) <= (-1L))) ^ p_96) == p_96)) > l_113[0][4]), 5L))))), 3)))
                {
                    uint8_t l_508[9] = {1UL, 255UL, 1UL, 255UL, 1UL, 255UL, 1UL, 255UL, 1UL};
                    int32_t l_534 = 0x735E1940L;
                    int32_t l_544 = (-1L);
                    int32_t l_547 = 1L;
                    int32_t l_549 = 0xE631E34AL;
                    int32_t l_550 = 1L;
                    int32_t l_551[4];
                    int i;
                    for (i = 0; i < 4; i++)
                        l_551[i] = 0xF292811CL;
                    if ((0x5EL || 248UL))
                    {
                        uint8_t l_492 = 5UL;
                        int32_t l_535 = 0xDFF2E105L;
                        int32_t l_540 = (-1L);
                        int32_t l_541 = 0x21FD1DCEL;
                        int32_t l_543 = 0x54458521L;
                        int32_t l_545 = 0L;
                        int32_t l_546 = 0L;
                        int32_t l_548[10] = {(-10L), (-10L), 0x543E1A35L, (-10L), (-10L), 0x543E1A35L, (-10L), (-10L), 0x543E1A35L, (-10L)};
                        uint8_t l_554 = 0x9BL;
                        int i;
                        l_492--;
                        l_513 = (g_139 = (((((g_321[2][1][1]++) <= (safe_add_func_uint16_t_u_u(1UL, p_96))) < (safe_add_func_uint16_t_u_u(((safe_mul_func_int8_t_s_s(l_369, (((g_141 = (((safe_mul_func_uint16_t_u_u(((+(safe_add_func_uint16_t_u_u(0UL, l_508[0]))) <= 250UL), ((safe_lshift_func_int8_t_s_s((g_511 = ((l_487 & (l_166[0] == p_95)) || l_279)), 0)) && g_407))) ^ 0x6CL) || p_96)) | g_328) & l_512[0]))) >= g_189), l_487))) && g_252[2][6]) | p_96));
                        l_534 = ((((safe_rshift_func_uint16_t_u_s((g_326[5] == (safe_sub_func_uint8_t_u_u((safe_mod_func_int32_t_s_s(g_139, l_520)), (safe_sub_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((1L || 0xACE96913L), ((safe_unary_minus_func_uint8_t_u((0xF8L > ((safe_mul_func_uint16_t_u_u((safe_sub_func_int16_t_s_s(((safe_add_func_int8_t_s_s(((l_508[2] < ((safe_mul_func_int8_t_s_s((p_95 >= p_96), (-5L))) ^ l_146[0][0])) && l_512[0]), 1UL)) & g_317), l_512[0])), l_513)) != g_332)))) < l_492))), 2L))))), g_202)) | p_95) >= 0x52L) || p_96);
                        --l_554;
                    }
                    else
                    {
                        g_352 &= (0x12L != ((p_95 ^ 1L) ^ (~(l_538[1] &= (safe_lshift_func_int16_t_s_u((safe_lshift_func_uint16_t_u_s((((-1L) >= 0xDBF1L) <= (0x44A9BF5BL ^ ((g_139 &= ((l_536 = 0x3586771EL) == (g_327[3][0] >= (safe_sub_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(0xD051A042L, p_95)), l_552))))) | 0x11031876L))), p_95)), l_566))))));
                        return g_347;
                    }
{
            int16_t l_838 = 0L;
            int32_t l_839[7][3][2] = {{{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}, {{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}, {{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}, {{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}, {{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}, {{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}, {{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}};
            int i, j, k;
            l_476--;
        }
for (g_332 = 0; (g_332 != (-8)); g_332--)
                    {
                        g_352 = l_201;
                        g_539[6] = 0x55AFDD2CL;
                        g_352 |= (safe_mul_func_uint16_t_u_u(p_96, (l_553 >= g_139)));
g_1271 += 1;
return l_476;
                    }
{
                        int8_t l_2340[8][4][6] = {{{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}, {{0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}, {0x85L, 0x79L, 0x4BL, 0x79L, 0x85L, 0x79L}}};
                        int i, j, k;
                        g_539[0] = (l_1213 ^ (safe_mod_func_int32_t_s_s((g_370[3] <= l_2340[5][3][3]), (g_189 &= (g_352 & 5UL)))));
                    }
for (l_118 = 0; l_118 < 4; l_118 += 1)
                    {
                        l_166[l_118] = 9L;
                    }
                }
                else
                {
                    int32_t l_576 = 0x71240FBBL;
                    int32_t l_581 = 1L;
                    int32_t l_616 = 0xC10AE0B7L;
                    int32_t l_631[5];
                    int i;
                    for (i = 0; i < 5; i++)
                        l_631[i] = 0x006A98C3L;
                    for (l_369 = 1; (l_369 >= 0); l_369 -= 1)
                    {
                        int i;
                        g_539[3] &= ((l_537 = (((safe_rshift_func_int8_t_s_s(l_119[l_369], (safe_rshift_func_int8_t_s_u((((safe_unary_minus_func_int8_t_s(((((l_576 ^ (safe_add_func_int32_t_s_s((l_576 || (safe_add_func_uint16_t_u_u((g_511--), ((g_332 |= (safe_add_func_int8_t_s_s((0x965EL != 0x43C9L), (0x4957L == g_244)))) & ((p_96 ^ 0x8CL) >= p_96))))), p_96))) || l_582[1][1][1]) & p_96) <= g_371))) <= g_347) >= l_576), l_119[l_369])))) >= l_119[l_369]) > l_212[3][0][0])) == l_581);
                        l_201 = p_96;
                        l_587[5][2] &= p_96;
                    }
                    l_279 = (g_252[1][4] != (((safe_rshift_func_int16_t_s_s((g_3 >= (l_576 >= 0x342B7D1FL)), (~(safe_rshift_func_int16_t_s_u(4L, ((safe_lshift_func_int8_t_s_u(p_96, (g_595[7] <= ((((safe_lshift_func_int8_t_s_u((l_119[1] | (g_348 | 3UL)), 1)) == g_252[2][6]) == 3UL) >= 0x8BL)))) != 65530UL)))))) == l_576) != l_538[1]));
                    l_212[7][1][1] ^= (l_195 < 246UL);
                    for (l_513 = 0; (l_513 < (-11)); l_513--)
                    {
                        uint32_t l_624 = 0x0454CC60L;
                        int32_t l_626 = 0L;
                        int32_t l_627 = (-2L);
                        int32_t l_632[8][3] = {{0L, 0x79842537L, 0xB663D698L}, {0L, 0x79842537L, 0xB663D698L}, {0L, 0x79842537L, 0xB663D698L}, {0L, 0x79842537L, 0xB663D698L}, {0L, 0x79842537L, 0xB663D698L}, {0L, 0x79842537L, 0xB663D698L}, {0L, 0x79842537L, 0xB663D698L}, {0L, 0x79842537L, 0xB663D698L}};
                        uint32_t l_634[10][4] = {{0UL, 0xC00EC5AAL, 0UL, 0xC00EC5AAL}, {0UL, 0xC00EC5AAL, 0UL, 0xC00EC5AAL}, {0UL, 0xC00EC5AAL, 0UL, 0xC00EC5AAL}, {0UL, 0xC00EC5AAL, 0UL, 0xC00EC5AAL}, {0UL, 0xC00EC5AAL, 0UL, 0xC00EC5AAL}, {0UL, 0xC00EC5AAL, 0UL, 0xC00EC5AAL}, {0UL, 0xC00EC5AAL, 0UL, 0xC00EC5AAL}, {0UL, 0xC00EC5AAL, 0UL, 0xC00EC5AAL}, {0UL, 0xC00EC5AAL, 0UL, 0xC00EC5AAL}, {0UL, 0xC00EC5AAL, 0UL, 0xC00EC5AAL}};
                        int i, j;
                        l_581 = ((safe_rshift_func_int8_t_s_s(((l_581 > ((((safe_sub_func_uint8_t_u_u(((safe_mul_func_uint8_t_u_u(248UL, p_96)) && l_170), ((safe_add_func_uint8_t_u_u((((safe_sub_func_int8_t_s_s(((0xEFL < (g_206 || ((safe_lshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u(((l_119[1] = (safe_rshift_func_uint8_t_u_s(l_616, (safe_rshift_func_int16_t_s_u((safe_mul_func_uint8_t_u_u((safe_mul_func_int8_t_s_s((+(-3L)), 0xA9L)), p_96)), g_348))))) > l_624), p_96)), 5)) < p_96))) & p_95), p_95)) >= l_624) & l_121), p_96)) ^ p_95))) == 0x89L) ^ 0x29FCL) > g_321[0][1][8])) ^ g_326[7]), 5)) >= g_321[0][1][8]);
                        ++l_634[0][3];
                    }
                }
                if (l_587[5][2])
                {
                    int32_t l_648 = 0x3E751481L;
                    for (l_121 = 0; (l_121 >= 0); l_121 -= 1)
                    {
                        l_513 |= p_96;
                        l_648 |= (((safe_unary_minus_func_uint8_t_u((++g_252[1][2]))) < (~0x6D6071C2L)) | (safe_add_func_uint16_t_u_u((+(l_119[0] |= (safe_mod_func_int16_t_s_s(g_321[0][1][8], (safe_rshift_func_int8_t_s_u(p_95, 1)))))), g_370[0])));
                    }
                }
                else
                {
                    uint8_t l_649 = 4UL;
                    l_649++;
                }
                l_582[1][1][1] = (safe_rshift_func_int16_t_s_u(((((safe_lshift_func_int16_t_s_u((safe_mul_func_uint16_t_u_u((((((g_139 = 1L) < ((l_166[2] ^= l_625) >= l_513)) == l_553) || 0x93L) || (l_119[0] | g_539[4])), ((safe_lshift_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_u((g_202 |= (l_201 = (safe_rshift_func_int8_t_s_s((l_537 = p_96), g_206)))), p_95)) && l_629), l_625)), 8)) != l_633))), 8)) | l_512[0]) < 1L) & p_96), 5));
                if ((l_212[9][1][1] = (((safe_mod_func_uint8_t_u_u((g_332 >= l_625), (g_189 | ((l_119[0] = ((((safe_unary_minus_func_int32_t_s((safe_add_func_int32_t_s_s((p_95 == (l_671[1][0] = (-1L))), p_95)))) && (safe_add_func_int8_t_s_s(g_252[2][6], (safe_rshift_func_int16_t_s_u(((g_326[7] && p_96) & g_202), g_151))))) > 0L) || 0xF7C4L)) || l_476)))) <= p_96) | g_321[0][1][8])))
                {
                    uint32_t l_679[7][7][5] = {{{7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}}, {{7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}}, {{7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}}, {{7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}}, {{7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}}, {{7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}}, {{7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}, {7UL, 0xCC6C0EA5L, 0xD21FE613L, 0UL, 4294967295UL}}};
                    int i, j, k;
                    for (g_511 = 0; (g_511 <= 4); g_511 += 1)
                    {
                        --l_676;
                        return l_679[3][0][0];
                    }
                }
                else
                {
                    int32_t l_680 = 0xF315753DL;
                    int32_t l_702 = (-1L);
                    if ((l_680 < l_212[3][1][1]))
                    {
                        uint16_t l_683 = 0UL;
                        g_539[0] ^= (g_139 = (safe_rshift_func_uint8_t_u_u((l_683 == g_141), 0)));
                        return l_221[4];
                    }
                    else
                    {
                        uint32_t l_684 = 4UL;
                        int32_t l_701 = 0xBC76516FL;
                        l_684--;
                        l_537 = (4UL > (safe_mul_func_uint16_t_u_u(5UL, ((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s((((g_327[0][0] | l_628) == (safe_rshift_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(p_95, ((safe_rshift_func_uint8_t_u_u(p_96, ((safe_add_func_uint8_t_u_u((l_538[3] &= ((l_121 &= (g_371++)) ^ (((p_96 & (safe_add_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((safe_add_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_s((safe_rshift_func_uint8_t_u_u((((p_96 > g_630) != 0xF94B279FL) == l_369), 6)), 3)) != p_96), g_206)), l_512[0])), l_582[2][3][1]))) > l_120) > 0x9BCBL))), g_347)) > l_537))) != p_96))) | g_202), 13))) || g_328), p_96)), p_96)) == p_96))));
                    }
                    l_715 = (0x4643L | p_96);
                    if ((65535UL < (l_166[0] = 1UL)))
                    {
                        l_582[1][6][2] = l_146[0][2];
                    }
                    else
                    {
                        uint32_t l_716 = 1UL;
                        int32_t l_724 = 0x332B24E3L;
                        int32_t l_725 = 0x0AA956C4L;
                        l_716++;
                        l_119[0] = l_553;
                        g_139 &= (safe_mod_func_uint32_t_u_u((g_206 |= (l_166[2] && g_349)), (((safe_mod_func_uint8_t_u_u(p_95, 0x1BL)) && 1UL) & 0x306AL)));
                        --l_726;
                    }
                }
            }
            if ((0x907DL <= l_146[0][4]))
            {
                l_729 = l_113[2][5];
            }
            else
            {
                uint32_t l_739 = 4294967292UL;
                int32_t l_767 = (-1L);
                int32_t l_768 = 0xCBEC45E6L;
                g_770 ^= (g_769 ^= (safe_rshift_func_uint8_t_u_s((--l_732), (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u(0x43L, (((g_511 = (l_739 = 0xB8A0L)) == ((((safe_add_func_int32_t_s_s((l_119[0] = (((safe_rshift_func_uint16_t_u_s((safe_lshift_func_uint16_t_u_s(1UL, 11)), (g_244 > ((((safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(p_95, (safe_add_func_uint32_t_u_u(((safe_mul_func_uint8_t_u_u((g_407 = (l_767 ^= (safe_add_func_uint8_t_u_u(255UL, (((((safe_sub_func_int16_t_s_s(((p_95 <= (l_758 ^= p_96)) == ((((safe_rshift_func_int16_t_s_u(((safe_mul_func_uint16_t_u_u((safe_mul_func_uint8_t_u_u(((((+((0x95CDL >= l_552) <= 0x79L)) == g_327[2][0]) & p_95) | p_96), p_96)), p_95)) & g_321[0][1][8]), p_96)) == p_96) < p_96) || p_95)), 0UL)) <= l_766) > g_353) > 1UL) & l_201))))), 1L)) ^ (-4L)), 0xEEC79DDFL)))) != 0UL), g_202)) >= g_408) && l_113[0][4]) | p_96)))) && l_767) | 1L)), 0x508A925BL)) > g_139) & l_768) ^ l_542)) | g_326[7]))), p_95)))));
            }
        }
        if ((l_119[0] = (!l_100[3][2][0])))
        {
            int16_t l_780 = 9L;
            int32_t l_790 = 0x8860F435L;
            int32_t l_791[1][6][2] = {{{(-1L), 5L}, {(-1L), 5L}, {(-1L), 5L}, {(-1L), 5L}, {(-1L), 5L}, {(-1L), 5L}}};
            int i, j, k;
            l_279 = (safe_lshift_func_int16_t_s_u(p_96, (safe_add_func_int32_t_s_s((l_113[0][4] < (safe_sub_func_uint32_t_u_u((safe_mul_func_int8_t_s_s(l_780, (safe_lshift_func_uint16_t_u_s((l_201 = (l_166[3] <= (((l_791[0][5][1] = ((l_121 &= ((safe_mod_func_uint32_t_u_u(p_96, (safe_mul_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((g_326[5] == ((safe_unary_minus_func_uint32_t_u((p_96 == ((((l_119[0] = p_95) == ((l_790 = 0xC7431E75L) >= g_769)) > 5L) != p_96)))) && 0xF3L)), 0xBEBBL)) != g_252[1][4]), g_252[2][6])))) != g_595[7])) < g_770)) ^ 65531UL) != 0xC6L))), 1)))), p_96))), g_332))));
        }
        else
        {
            int32_t l_825 = (-7L);
            if (g_347)
            {
                uint8_t l_792 = 0xA7L;
                l_792 = 0x6F39D5E6L;
            }
            else
            {
                int32_t l_808 = 0x4E712590L;
                int32_t l_809 = 0xD1DA26A9L;
                for (g_189 = 0; (g_189 >= 0); g_189 -= 1)
                {
                    int i;
                    l_166[(g_189 + 1)] = ((l_166[(g_189 + 3)] < (--g_141)) > ((l_166[g_189] > (safe_mul_func_int16_t_s_s((!p_95), (l_166[(g_189 + 3)] != p_95)))) <= (safe_mul_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_u(p_96, 7)) || p_96), g_316))));
                    l_809 = ((p_96 | 0x7BL) > (safe_lshift_func_int16_t_s_u(((safe_mul_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_u(((l_808 &= l_166[g_189]) | 0UL), 7)) || (((0x03A74259L == g_352) >= ((g_370[3] || 0x0A74FBB1L) == (((g_139 = ((255UL > 0x07L) && 0xDF25L)) < 4294967294UL) && l_166[0]))) ^ 0x02L)), g_326[7])) & 0x39L), l_166[(g_189 + 1)])));
                    for (l_170 = 0; (l_170 <= 0); l_170 += 1)
                    {
                        int i, j;
                        g_139 |= (l_146[g_189][(l_170 + 5)] <= (safe_mod_func_int32_t_s_s((~((safe_lshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_u((0x3BF38E63L > ((safe_lshift_func_int16_t_s_s((-1L), 15)) || (l_825 |= (0x2B777E0EL >= (l_146[l_170][l_170] == (safe_add_func_uint16_t_u_u(l_146[l_170][(g_189 + 5)], (g_326[3] &= (safe_lshift_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_s(l_146[l_170][(l_170 + 1)], 6)) | (g_321[0][1][8] <= (g_539[4] || 65535UL))), 13)))))))))), g_769)) <= 0x23L), 8)) ^ p_95)), (-2L))));
                    }
                }
            }
        }
    }
    else
    {
        uint16_t l_837 = 0x34A3L;
        int32_t l_840 = 0xDFD5D61BL;
        int32_t l_841 = 1L;
        int32_t l_842 = 0x01AA8C37L;
        int32_t l_843 = 0L;
        int32_t l_844 = 9L;
        int32_t l_845[5];
        int16_t l_873 = 0x0552L;
        int32_t l_874[2][8] = {{0xEFF56801L, 0xEFF56801L, 0x2F971169L, 0xEFF56801L, 0xEFF56801L, 0x2F971169L, 0xEFF56801L, 0xEFF56801L}, {0xEFF56801L, 0xEFF56801L, 0x2F971169L, 0xEFF56801L, 0xEFF56801L, 0x2F971169L, 0xEFF56801L, 0xEFF56801L}};
        int32_t l_927 = 0L;
        uint16_t l_1076[10][7] = {{0x3357L, 65535UL, 1UL, 5UL, 0x3357L, 0UL, 0xEAC0L}, {0x3357L, 65535UL, 1UL, 5UL, 0x3357L, 0UL, 0xEAC0L}, {0x3357L, 65535UL, 1UL, 5UL, 0x3357L, 0UL, 0xEAC0L}, {0x3357L, 65535UL, 1UL, 5UL, 0x3357L, 0UL, 0xEAC0L}, {0x3357L, 65535UL, 1UL, 5UL, 0x3357L, 0UL, 0xEAC0L}, {0x3357L, 65535UL, 1UL, 5UL, 0x3357L, 0UL, 0xEAC0L}, {0x3357L, 65535UL, 1UL, 5UL, 0x3357L, 0UL, 0xEAC0L}, {0x3357L, 65535UL, 1UL, 5UL, 0x3357L, 0UL, 0xEAC0L}, {0x3357L, 65535UL, 1UL, 5UL, 0x3357L, 0UL, 0xEAC0L}, {0x3357L, 65535UL, 1UL, 5UL, 0x3357L, 0UL, 0xEAC0L}};
        int32_t l_1225 = 0L;
        int i, j;
        for (i = 0; i < 5; i++)
            l_845[i] = 0xB6062C41L;
        g_539[4] = ((((+(safe_rshift_func_uint16_t_u_s(((l_113[0][4] ^ p_95) | (safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((((((0x287CL >= (g_206 < 0xE909L)) < g_407) <= (safe_add_func_int32_t_s_s((safe_mul_func_int8_t_s_s((g_321[0][1][8] && (l_837 ^= g_370[1])), l_113[0][4])), p_96))) < p_95) == g_141), p_95)), 0x1DL))), 4))) != g_252[1][0]) ^ 0x25251C35L) ^ l_671[1][1]);
        if (g_407)
        {
            int16_t l_838 = 0L;
            int32_t l_839[7][3][2] = {{{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}, {{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}, {{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}, {{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}, {{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}, {{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}, {{0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}, {0x433FF1CBL, 1L}}};
            int i, j, k;
            l_846--;
        }
        else
        {
            uint32_t l_857 = 0x25516012L;
            int32_t l_872 = 0x996E9FEFL;
            int32_t l_875[2];
            uint8_t l_884 = 255UL;
            int32_t l_933 = 0x3148C617L;
            uint32_t l_1008 = 5UL;
            int8_t l_1035 = 0xC8L;
            int32_t l_1074 = 8L;
            int32_t l_1075 = (-4L);
            uint8_t l_1079 = 254UL;
            uint32_t l_1092[5][5] = {{4294967291UL, 4294967295UL, 1UL, 1UL, 4294967295UL}, {4294967291UL, 4294967295UL, 1UL, 1UL, 4294967295UL}, {4294967291UL, 4294967295UL, 1UL, 1UL, 4294967295UL}, {4294967291UL, 4294967295UL, 1UL, 1UL, 4294967295UL}, {4294967291UL, 4294967295UL, 1UL, 1UL, 4294967295UL}};
            int i, j;
            for (i = 0; i < 2; i++)
                l_875[i] = (-2L);
            if ((safe_add_func_uint8_t_u_u(g_353, (l_872 = ((safe_sub_func_int8_t_s_s((safe_mod_func_uint8_t_u_u((safe_add_func_int8_t_s_s(l_857, (g_189 >= (safe_sub_func_int16_t_s_s(((((g_206 == (safe_add_func_int8_t_s_s(((safe_sub_func_int8_t_s_s((((((g_408 = 0xD914L) < (safe_mod_func_int16_t_s_s(((((safe_mod_func_int8_t_s_s(p_96, (safe_mod_func_int16_t_s_s(0xB240L, g_332)))) || ((((((((++g_244) <= g_141) | g_189) && l_872) || l_873) ^ g_151) == l_843) || 1L)) != p_95) ^ g_326[6]), 7UL))) ^ 0x00L) && p_95) ^ l_840), g_407)) != 0L), l_119[1]))) || 4294967294UL) || p_96) || p_95), l_874[1][6]))))), l_875[0])), 7UL)) | g_347)))))
            {
                uint16_t l_892 = 65529UL;
                int32_t l_894[4];
                int32_t l_918 = (-9L);
                uint32_t l_952 = 0x30CDF267L;
                int8_t l_1036 = 1L;
                int i;
                for (i = 0; i < 4; i++)
                    l_894[i] = 0x4ED5E062L;
                if ((safe_add_func_int8_t_s_s(l_840, (((((safe_mod_func_uint8_t_u_u((g_326[7] < (((safe_mod_func_int32_t_s_s((-2L), l_845[3])) & (safe_mod_func_uint8_t_u_u((l_884 || (safe_mod_func_uint16_t_u_u((((g_408 <= ((p_96 && (((safe_mod_func_int16_t_s_s(((!(p_96 & ((l_119[0] = (safe_lshift_func_int16_t_s_s(l_119[0], l_845[3]))) == (-5L)))) | l_845[4]), p_95)) | l_884) | 0x26BAL)) & 0UL)) ^ g_407) || 0x2BB7L), g_408))), g_328))) && g_328)), l_201)) ^ 0x59L) <= 1L) > 1UL) && 0x4EL))))
                {
                    uint32_t l_901[6] = {4294967288UL, 0x721D0B79L, 4294967288UL, 0x721D0B79L, 4294967288UL, 0x721D0B79L};
                    uint8_t l_955 = 248UL;
                    int32_t l_972 = 6L;
                    int i;
                    g_139 ^= ((p_95 <= (l_892 ^= (-7L))) != (+(l_894[3] && ((l_845[1] = ((l_170 > (safe_lshift_func_int8_t_s_s((-1L), 1))) | g_347)) | (((p_95 <= ((g_408 = (safe_sub_func_uint8_t_u_u(l_840, (safe_add_func_uint16_t_u_u((l_901[2] &= l_100[3][2][0]), g_371))))) & p_95)) & p_95) ^ p_95)))));
                    if ((((safe_rshift_func_uint8_t_u_s((((safe_sub_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(2L, l_633)), (safe_mul_func_uint16_t_u_u(g_3, ((0x1EBABE45L && 0xFD2848D8L) == 1L))))) >= g_327[1][0]) > (p_96 == (safe_lshift_func_int16_t_s_u((safe_rshift_func_int8_t_s_s((safe_sub_func_int16_t_s_s(((safe_mul_func_int16_t_s_s(((g_595[7] >= 0xD038L) > 0x6096L), 5UL)) == 0x6366D070L), l_884)), 6)), p_96)))), 7)) != l_901[4]) ^ g_511))
                    {
                        g_539[8] |= (l_119[0] |= (l_918 || g_139));
                        l_933 = (((((g_511 = (p_96 | (l_872 |= (safe_mod_func_uint32_t_u_u(((g_317 = (((0xD0BCL == ((safe_rshift_func_int8_t_s_u((((((8L <= 0UL) ^ g_511) >= ((safe_add_func_uint16_t_u_u((g_326[7]++), (l_927 > (g_317 != (safe_rshift_func_int16_t_s_s(g_511, ((safe_mul_func_uint16_t_u_u((l_857 < 0x293D6469L), 8L)) < l_884))))))) & 8L)) != 1UL) >= l_932), l_933)) ^ l_894[2])) == 0x3BFB04E2L) ^ 0x896AL)) <= g_769), g_370[1]))))) && 0xCDAAL) ^ p_95) ^ p_95) < l_918);
                        l_840 = ((safe_mod_func_uint8_t_u_u((l_872 = (0xEA4A7315L < (safe_mul_func_uint8_t_u_u((g_769 = ((safe_sub_func_uint8_t_u_u((l_894[3] && (safe_add_func_int8_t_s_s((safe_sub_func_int32_t_s_s(((-1L) >= (0x7F53B32DL && (g_371 || g_317))), ((((((1L ^ (((safe_mod_func_int8_t_s_s((safe_mul_func_int16_t_s_s(0x42B6L, (safe_mul_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_s((g_408 = g_353), 15)) >= 3UL), g_630)))), g_326[7])) ^ l_918) && 0x3B94L)) <= l_732) == g_151) && g_317) && l_901[1]) ^ 0xA457E1FCL))), p_96))), g_327[0][0])) || p_96)), p_95)))), l_901[0])) > p_96);
                    }
                    else
                    {
                        l_952--;
                        l_955 = 0x03D5BBCAL;
                    }
                    if ((g_973 = (((g_511 | (l_845[3] ^ ((safe_lshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u(g_203, ((safe_sub_func_int32_t_s_s((g_139 = ((safe_mul_func_uint8_t_u_u(p_96, (l_972 = (~(((safe_mod_func_uint16_t_u_u((l_894[3] &= (g_141 = g_139)), p_95)) != p_95) == ((g_317 = (safe_mul_func_int8_t_s_s(((safe_sub_func_int32_t_s_s(0xD2DE29F0L, ((safe_unary_minus_func_int8_t_s(0x21L)) >= g_347))) > 0L), p_95))) >= g_139)))))) && l_932)), p_95)) & p_96))), 7)) <= p_95))) & p_96) ^ p_95)))
                    {
                        g_539[3] = (l_119[0] = g_3);
                        return p_95;
                    }
                    else
                    {
                        uint32_t l_1007 = 6UL;
                        int32_t l_1009[7][5][7] = {{{0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}}, {{0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}}, {{0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}}, {{0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}}, {{0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}}, {{0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}}, {{0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}, {0L, 0L, 0x1D81E356L, (-1L), 0xFA12E5F0L, 0x52975E8DL, 0xD239411AL}}};
                        int i, j, k;
                        l_1009[6][1][3] = ((safe_mul_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(1UL, (safe_mod_func_uint32_t_u_u(((~g_352) >= (safe_mul_func_int16_t_s_s((~(safe_lshift_func_int16_t_s_u((4UL && ((g_595[7] > (safe_mul_func_uint16_t_u_u((g_511 = l_872), (safe_rshift_func_uint16_t_u_u(((0xC2L >= (~(((safe_mul_func_uint16_t_u_u(((safe_unary_minus_func_int32_t_s(((((safe_lshift_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s(0x1CL, (l_633 && (l_933 = (safe_mod_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u((safe_mul_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u((safe_unary_minus_func_int8_t_s((l_1007 > g_408))), 11)), l_1008)), 1)), p_96)))))), 6)) != l_845[3]) >= l_1007) > g_203))) <= l_1007), (-8L))) < g_252[2][6]) & 0xB7A9CA8EL))) & 3UL), g_252[2][6]))))) < g_252[2][4])), g_348))), 0x3C3FL))), l_120)))), 65528UL)) < 0xBBL);
                        g_352 = ((p_95 | l_844) & (((((g_630 && (++g_326[2])) >= ((safe_mul_func_int16_t_s_s((((-10L) && (safe_add_func_uint32_t_u_u((g_244--), (g_595[5] || 0x520FL)))) == (-1L)), (l_901[2] == ((safe_add_func_uint16_t_u_u((safe_mul_func_int8_t_s_s(p_96, g_539[5])), 1L)) & 65535UL)))) || g_321[1][0][0])) > l_840) < g_252[2][0]) | 0x7AL));
                        g_539[4] |= (l_119[0] = (l_857 & ((l_972 |= (g_317 |= ((safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(g_332, 5)), (safe_add_func_uint16_t_u_u(0UL, (9L != ((safe_sub_func_uint8_t_u_u(l_955, ((((l_844 &= (safe_lshift_func_int16_t_s_u((0L || ((safe_unary_minus_func_uint8_t_u(g_348)) & (g_326[1] = (p_95 && (safe_mul_func_uint16_t_u_u(l_1035, 0xDB7EL)))))), 6))) == (-10L)) ^ l_1036) >= g_769))) < p_95)))))) | 0L))) >= 3UL)));
                    }
                    l_894[3] &= 0x216375BBL;
                }
                else
                {
                    for (g_189 = 26; (g_189 >= (-28)); g_189 = safe_sub_func_int16_t_s_s(g_189, 9))
                    {
                        return l_932;
                    }
                    g_352 = (((p_96 || (((g_353 & g_327[3][0]) < ((g_321[0][1][8] > (l_845[0] |= ((safe_add_func_int16_t_s_s((safe_mod_func_int32_t_s_s(g_407, (safe_mod_func_uint32_t_u_u(l_671[1][0], g_407)))), (safe_mul_func_int16_t_s_s((safe_add_func_uint32_t_u_u(g_202, (g_35 == p_95))), 1L)))) <= 0x1AL))) | g_595[7])) & g_370[4])) <= p_96) || p_96);
                }
                g_539[4] = ((l_845[4] = ((safe_add_func_int8_t_s_s(g_321[2][0][7], ((safe_lshift_func_int16_t_s_s(l_894[2], 4)) && (safe_sub_func_uint8_t_u_u((((((l_894[3] = (l_872 &= ((((safe_rshift_func_uint16_t_u_u((!0x91952113L), 4)) || (safe_add_func_uint32_t_u_u((((((((safe_lshift_func_uint16_t_u_s(0x58F7L, (safe_lshift_func_uint16_t_u_u((l_927 && l_120), 4)))) != p_95) ^ (l_894[2] == ((((((safe_mul_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_u(((((((safe_mod_func_int32_t_s_s((65535UL && p_96), l_892)) ^ g_348) != l_845[4]) < g_539[4]) || 0L) >= 1L), 3)) <= g_252[1][2]), 255UL)), p_95)) != l_671[0][1]) & p_95) >= 1L) || l_671[0][1]) >= p_95))) != 0x22751874L) | 0x11L) != 1L) & p_95), g_347))) && l_119[1]) > l_842))) < l_1072) >= 0x57L) || 0x9CL) | 0L), g_370[1]))))) ^ p_95)) != l_1073);
                l_1076[0][0]++;
                l_1079--;
            }
            else
            {
                int16_t l_1096 = (-6L);
                int32_t l_1114[9];
                int32_t l_1117[6];
                uint32_t l_1121 = 2UL;
                uint32_t l_1123 = 0x5EB60DEDL;
                int32_t l_1230 = (-1L);
                int8_t l_1238 = (-1L);
                int i;
                for (i = 0; i < 9; i++)
                    l_1114[i] = (-1L);
                for (i = 0; i < 6; i++)
                    l_1117[i] = 0x9DCA5F19L;
                if (((safe_lshift_func_uint8_t_u_s(((safe_add_func_int32_t_s_s((p_95 && 9L), (safe_sub_func_uint8_t_u_u((g_407 = (((safe_lshift_func_uint16_t_u_s(g_973, (9UL < (l_872 & (l_841 |= 4294967292UL))))) == (safe_sub_func_int32_t_s_s(((g_141 == 0x8D48L) <= p_96), 0x8314A797L))) | p_95)), g_206)))) >= g_352), l_844)) && 0x07L))
                {
                    uint32_t l_1097[6] = {0x41663729L, 2UL, 0x41663729L, 2UL, 0x41663729L, 2UL};
                    int32_t l_1122 = 0L;
                    int i;
                    g_139 |= p_95;
                    g_539[7] = 0xEB9971B4L;
                    if ((l_872 = g_370[1]))
                    {
                        int16_t l_1095 = 0x49F6L;
                        uint16_t l_1113[7][5] = {{0x4885L, 65535UL, 0x9C7EL, 65530UL, 0xCBFAL}, {0x4885L, 65535UL, 0x9C7EL, 65530UL, 0xCBFAL}, {0x4885L, 65535UL, 0x9C7EL, 65530UL, 0xCBFAL}, {0x4885L, 65535UL, 0x9C7EL, 65530UL, 0xCBFAL}, {0x4885L, 65535UL, 0x9C7EL, 65530UL, 0xCBFAL}, {0x4885L, 65535UL, 0x9C7EL, 65530UL, 0xCBFAL}, {0x4885L, 65535UL, 0x9C7EL, 65530UL, 0xCBFAL}};
                        int32_t l_1135 = 0xCB3446B2L;
                        uint32_t l_1136 = 6UL;
                        int i, j;
{
                        l_119[0] = 0x7C3F12FEL;
                        return g_203;
                    }
l_1092[3][0]++;
                        l_1097[5]++;
                        l_872 = (safe_lshift_func_int8_t_s_u(((safe_sub_func_int16_t_s_s((safe_mod_func_int32_t_s_s(p_96, ((safe_sub_func_uint8_t_u_u(p_95, ((l_201 = ((l_1075 >= (~p_96)) == (safe_rshift_func_uint8_t_u_s((safe_sub_func_int32_t_s_s(l_1113[1][1], (l_1114[4] &= (l_118 | g_348)))), 0)))) ^ (l_1122 |= (((safe_lshift_func_uint16_t_u_u((l_1117[4] = g_539[4]), 9)) && (l_1121 = (safe_sub_func_int32_t_s_s((safe_unary_minus_func_uint32_t_u(((((((l_1117[4] = g_352) < l_1076[0][0]) == 0x8234L) >= g_321[3][2][0]) ^ l_1097[3]) ^ 0x83L))), 0L)))) & (-1L)))))) & g_139))), l_1123)) > p_95), p_95));
                        g_139 |= (g_328 & (safe_mul_func_int16_t_s_s((g_327[2][0] & (!(l_1117[3] = ((((((l_1135 = (p_96 || ((((((l_1114[4] &= ((((safe_mul_func_int16_t_s_s(l_1117[4], 0x6245L)) == (safe_mod_func_int32_t_s_s((l_1113[1][1] <= (p_96 | ((safe_add_func_uint32_t_u_u((safe_mod_func_uint16_t_u_u(((-10L) != (g_370[5] >= 0x77L)), 0x00CEL)), 0x13D7889DL)) | 1L))), 0xA98EA71CL))) ^ 0x51L) | g_370[5])) == g_321[0][1][8]) || g_327[0][0]) || 0xF83DL) & p_96) < 0x88D4L))) != 0x6534L) & 1UL) <= l_1136) && 5UL) & p_95)))), l_1074)));
                    }
                    else
                    {
                        uint32_t l_1156 = 0x6DDCA408L;
                        int32_t l_1163 = 0xBAD241ADL;
                        int32_t l_1164[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_1164[i] = (-1L);
                        l_1164[0] |= ((safe_sub_func_uint16_t_u_u(((0x30L & ((g_139 = (safe_lshift_func_int16_t_s_s((l_1097[5] >= (safe_sub_func_int8_t_s_s((safe_mul_func_uint16_t_u_u((+((safe_lshift_func_uint16_t_u_s((safe_add_func_int16_t_s_s((safe_rshift_func_int8_t_s_s((safe_mul_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(0xFAFCL, 6)), l_1156)), (((l_840 ^= (safe_mul_func_uint8_t_u_u(0xADL, ((((safe_mul_func_uint8_t_u_u(p_95, l_1114[4])) <= 0x30DCF539L) >= ((safe_rshift_func_int8_t_s_u((l_1114[4] >= l_1073), l_1163)) || 1UL)) < p_95)))) & p_96) ^ p_96))), 0UL)), 7)) <= l_671[1][1])), g_630)), l_874[1][6]))), g_352))) || l_1035)) == l_1123), (-1L))) < g_347);
                    }
                    for (l_842 = 0; (l_842 >= 23); l_842 = safe_add_func_int8_t_s_s(l_842, 3))
                    {
{
                        g_3 = l_844;
                        g_539[6] = 0x55AFDD2CL;
                        g_3 |= (safe_mul_func_uint16_t_u_u(g_203, (l_1096 >= g_1297)));
                        return g_141;
                    }
l_119[0] = 0x7C3F12FEL;
                        return g_203;
                    }
                }
                else
                {
                    uint32_t l_1167[3][9][5] = {{{4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}}, {{4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}}, {{4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}, {4294967295UL, 0xBB5D4351L, 0x52DE6F55L, 0x18466C6AL, 0UL}}};
                    int32_t l_1192 = 0x4BF8560FL;
                    int32_t l_1214[9][6] = {{(-1L), 6L, 1L, 0x1DAF57B0L, 0xFF80EE6DL, 3L}, {(-1L), 6L, 1L, 0x1DAF57B0L, 0xFF80EE6DL, 3L}, {(-1L), 6L, 1L, 0x1DAF57B0L, 0xFF80EE6DL, 3L}, {(-1L), 6L, 1L, 0x1DAF57B0L, 0xFF80EE6DL, 3L}, {(-1L), 6L, 1L, 0x1DAF57B0L, 0xFF80EE6DL, 3L}, {(-1L), 6L, 1L, 0x1DAF57B0L, 0xFF80EE6DL, 3L}, {(-1L), 6L, 1L, 0x1DAF57B0L, 0xFF80EE6DL, 3L}, {(-1L), 6L, 1L, 0x1DAF57B0L, 0xFF80EE6DL, 3L}, {(-1L), 6L, 1L, 0x1DAF57B0L, 0xFF80EE6DL, 3L}};
                    uint32_t l_1226 = 0x37424E7EL;
                    int i, j, k;
                    if ((l_927 = (p_95 > (g_327[2][0] || g_202))))
                    {
                        uint8_t l_1177 = 7UL;
                        l_1167[0][1][0]++;
                        l_845[2] = (safe_unary_minus_func_uint16_t_u(p_96));
                        l_1192 = (((safe_sub_func_int32_t_s_s((l_118 || (safe_sub_func_int8_t_s_s((safe_mod_func_uint16_t_u_u(g_189, l_1177)), (safe_mod_func_uint16_t_u_u((0xD8E2L < (((safe_sub_func_uint32_t_u_u(p_96, (safe_add_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(4294967294UL, (safe_mod_func_uint16_t_u_u((safe_mod_func_int32_t_s_s(((-7L) < (((((65526UL < (l_1035 == 0x88L)) ^ g_252[1][4]) || p_95) & 0x9D0F0BFDL) > l_1177)), p_96)), 1L)))), (-1L))))) >= l_1167[2][6][4]) == p_96)), 0x3A62L))))), g_973)) && l_884) != l_1075);
                        l_845[3] = (((safe_unary_minus_func_uint8_t_u((safe_rshift_func_int16_t_s_u(((((safe_mul_func_uint8_t_u_u(((((safe_mod_func_int32_t_s_s((safe_add_func_int16_t_s_s((safe_sub_func_int32_t_s_s((((((~(safe_rshift_func_int16_t_s_u(l_841, 2))) ^ (l_1114[1] = (0x7FD6L > (safe_lshift_func_uint8_t_u_u(((safe_sub_func_uint32_t_u_u(0x1077E5E4L, (safe_sub_func_int16_t_s_s((0xC9L != (l_1123 >= (l_840 = (0L > p_96)))), l_1213)))) == (l_884 ^ g_327[3][0])), 7))))) < g_141) | 0x85L) || p_95), l_1192)), g_326[7])), p_95)) && l_1214[1][3]) || p_96) || l_1192), 0UL)) | l_1214[5][0]) != g_973) > p_95), 2)))) != p_95) >= p_95);
                    }
                    else
                    {
                        int32_t l_1224 = 0x578B0985L;
                        l_1214[1][3] ^= ((5L > (safe_sub_func_uint16_t_u_u(((l_1226 |= ((l_1192 == ((safe_sub_func_uint32_t_u_u(((((safe_sub_func_int16_t_s_s((safe_mod_func_uint8_t_u_u(g_141, ((p_96 && (1L ^ (~(g_139 = ((((g_332 <= l_1167[0][1][0]) & 1UL) >= 8UL) > g_539[4]))))) & l_201))), l_1224)) | 4294967293UL) < g_347) >= g_595[8]), l_1225)) & l_520)) && p_95)) <= l_1224), l_1224))) != l_846);
                    }
                    if ((p_95 ^ (((l_1192 = g_348) | (l_933 ^= 255UL)) > (((safe_unary_minus_func_int8_t_s((safe_mod_func_uint8_t_u_u(l_1114[4], l_1008)))) | l_1230) | (248UL | (safe_mod_func_uint32_t_u_u(((safe_unary_minus_func_int16_t_s(((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s(((l_927 = (l_1238 < (p_95 == p_96))) | p_96), g_203)), g_206)) && l_1117[4]))) == g_769), l_1114[4])))))))
                    {
                        uint16_t l_1239 = 0UL;
                        l_933 = 1L;
                        ++l_1239;
                    }
                    else
                    {
                        uint16_t l_1242 = 0UL;
                        g_539[4] = ((p_96 >= 0x5ADE1281L) > (l_1242 & ((255UL == p_96) && ((safe_mul_func_int8_t_s_s(((l_1117[4] = (safe_rshift_func_int16_t_s_u((safe_sub_func_int32_t_s_s(g_408, (((0xDB0F197AL <= ((((safe_mod_func_int8_t_s_s((-10L), 255UL)) < 0xD1L) < 0xFA6CL) ^ g_539[4])) < l_1123) | l_1230))), l_520))) < l_1123), 1L)) > 0xABB2L))));
                    }
                }
                g_539[4] ^= 2L;
                for (g_189 = 0; (g_189 <= (-24)); --g_189)
                {
                    uint32_t l_1255 = 0xCA267B34L;
                    l_872 = (safe_add_func_int8_t_s_s(l_1255, (g_407 = ((safe_sub_func_int32_t_s_s(((0x470EL & ((((safe_mul_func_int8_t_s_s((safe_mod_func_int8_t_s_s(l_843, g_321[0][1][8])), (safe_add_func_int16_t_s_s((safe_lshift_func_uint8_t_u_s(246UL, 1)), (g_316 ^ l_1266))))) > (safe_add_func_uint16_t_u_u((safe_add_func_int32_t_s_s(p_96, p_95)), g_348))) > l_1114[4]) ^ l_857)) & 255UL), p_95)) < 1L))));
                }
            }
        }
    }
    return p_96;
}
int main (int argc, char* argv[])
{
    int i, j, k;
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
                      if (( g_3 < 333244880) )
{
for (print_hash_value = 0; print_hash_value < 6; print_hash_value++)
                    g_370[print_hash_value] = (-8L);
}
transparent_crc(g_3, "g_3", print_hash_value);
    transparent_crc(g_35, "g_35", print_hash_value);
    transparent_crc(g_139, "g_139", print_hash_value);
    transparent_crc(g_141, "g_141", print_hash_value);
    transparent_crc(g_151, "g_151", print_hash_value);
    transparent_crc(g_189, "g_189", print_hash_value);
    transparent_crc(g_202, "g_202", print_hash_value);
    transparent_crc(g_203, "g_203", print_hash_value);
    transparent_crc(g_206, "g_206", print_hash_value);
    transparent_crc(g_244, "g_244", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 7; j++)
        {
            transparent_crc(g_252[i][j], "g_252[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    transparent_crc(g_316, "g_316", print_hash_value);
    transparent_crc(g_317, "g_317", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 9; k++)
            {
                transparent_crc(g_321[i][j][k], "g_321[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_326[i], "g_326[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 1; j++)
        {
            transparent_crc(g_327[i][j], "g_327[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    transparent_crc(g_328, "g_328", print_hash_value);
    transparent_crc(g_332, "g_332", print_hash_value);
    transparent_crc(g_347, "g_347", print_hash_value);
    transparent_crc(g_348, "g_348", print_hash_value);
    transparent_crc(g_349, "g_349", print_hash_value);
    transparent_crc(g_352, "g_352", print_hash_value);
    transparent_crc(g_353, "g_353", print_hash_value);
    for (i = 0; i < 6; i++)
    {
        transparent_crc(g_370[i], "g_370[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
                      if (( g_2888 < 5) )
{
g_539[4] ^= g_1271;
}
transparent_crc(g_371, "g_371", print_hash_value);
    transparent_crc(g_407, "g_407", print_hash_value);
    transparent_crc(g_408, "g_408", print_hash_value);
    transparent_crc(g_511, "g_511", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_539[i], "g_539[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    for (i = 0; i < 10; i++)
    {
                          if (( g_2205 < -6) )
{
{
                uint32_t l_3800 = 0x5C7CEF5EL;
                int32_t l_3801 = 0x95F02646L;
                int32_t l_3802 = 9L;
                int32_t l_3808[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_3808[i] = 0x886ECA44L;
                g_630 = (safe_sub_func_uint32_t_u_u(g_408, ((safe_sub_func_uint32_t_u_u(0x005037B5L, l_3800)) || ((((((0xA6BCL | l_3800) != g_630) < 0x63A4L) < (l_3801 = (g_370[1] & (g_630 ^ 1UL)))) | 0x3BL) == g_189))));
                g_244--;
            }
}
transparent_crc(g_595[i], "g_595[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_630, "g_630", print_hash_value);
    transparent_crc(g_769, "g_769", print_hash_value);
    transparent_crc(g_770, "g_770", print_hash_value);
    transparent_crc(g_973, "g_973", print_hash_value);
    transparent_crc(g_1271, "g_1271", print_hash_value);
    transparent_crc(g_1297, "g_1297", print_hash_value);
    transparent_crc(g_1374, "g_1374", print_hash_value);
    transparent_crc(g_1442, "g_1442", print_hash_value);
    for (i = 0; i < 10; i++)
    {
                          if (( g_3804 < -2043103010) )
{
g_539[7] ^= (safe_lshift_func_uint8_t_u_s(g_3804, 3));
}
transparent_crc(g_1985[i], "g_1985[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_2037, "g_2037", print_hash_value);
    transparent_crc(g_2205, "g_2205", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 4; j++)
        {
            transparent_crc(g_2281[i][j], "g_2281[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    transparent_crc(g_2414, "g_2414", print_hash_value);
    transparent_crc(g_2447, "g_2447", print_hash_value);
    transparent_crc(g_2888, "g_2888", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_2935[i], "g_2935[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 7; j++)
        {
            transparent_crc(g_2940[i][j], "g_2940[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    transparent_crc(g_3311, "g_3311", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_3612[i], "g_3612[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_3804, "g_3804", print_hash_value);
    transparent_crc(g_3890, "g_3890", print_hash_value);
    transparent_crc(g_3893, "g_3893", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

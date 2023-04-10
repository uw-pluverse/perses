#include <string.h>
#include <float.h>
#include <math.h>
 #include <limits.h>
 #include <stdint.h>
#include <assert.h>
#include <stdio.h>
static void
platform_main_begin(void)
{
}
static void
platform_main_end(uint32_t crc, int flag)
{
 printf ("checksum = %X\n", crc);
}
static int8_t
(safe_unary_minus_func_int8_t_s)(int8_t si )
{
 
  return
    (si==INT8_MIN) ?
    ((si)) :
    -si;
}
static int8_t
(safe_add_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{
 
  return
    (((si1>0) && (si2>0) && (si1 > (INT8_MAX-si2))) || ((si1<0) && (si2<0) && (si1 < (INT8_MIN-si2)))) ?
    ((si1)) :
    (si1 + si2);
}
static int8_t
(safe_sub_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{
 
  return
    (((si1^si2) & (((si1 ^ ((si1^si2) & (~INT8_MAX)))-si2)^si2)) < 0) ?
    ((si1)) :
    (si1 - si2);
}
static int8_t
(safe_mul_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{
 
  return
    (((si1 > 0) && (si2 > 0) && (si1 > (INT8_MAX / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < (INT8_MIN / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < (INT8_MIN / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (INT8_MAX / si1)))) ?
    ((si1)) :
    si1 * si2;
}
static int8_t
(safe_mod_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == INT8_MIN) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 % si2);
}
static int8_t
(safe_div_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == INT8_MIN) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 / si2);
}
static int8_t
(safe_lshift_func_int8_t_s_s)(int8_t left, int right )
{
 
  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > (INT8_MAX >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static int8_t
(safe_lshift_func_int8_t_s_u)(int8_t left, unsigned int right )
{
 
  return
    ((left < 0) || (((unsigned int)right) >= 32) || (left > (INT8_MAX >> ((unsigned int)right)))) ?
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
    (si==INT16_MIN) ?
    ((si)) :
    -si;
}
static int16_t
(safe_add_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{
 
  return
    (((si1>0) && (si2>0) && (si1 > (INT16_MAX-si2))) || ((si1<0) && (si2<0) && (si1 < (INT16_MIN-si2)))) ?
    ((si1)) :
    (si1 + si2);
}
static int16_t
(safe_sub_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{
 
  return
    (((si1^si2) & (((si1 ^ ((si1^si2) & (~INT16_MAX)))-si2)^si2)) < 0) ?
    ((si1)) :
    (si1 - si2);
}
static int16_t
(safe_mul_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{
 
  return
    (((si1 > 0) && (si2 > 0) && (si1 > (INT16_MAX / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < (INT16_MIN / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < (INT16_MIN / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (INT16_MAX / si1)))) ?
    ((si1)) :
    si1 * si2;
}
static int16_t
(safe_mod_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == INT16_MIN) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 % si2);
}
static int16_t
(safe_div_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == INT16_MIN) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 / si2);
}
static int16_t
(safe_lshift_func_int16_t_s_s)(int16_t left, int right )
{
 
  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > (INT16_MAX >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static int16_t
(safe_lshift_func_int16_t_s_u)(int16_t left, unsigned int right )
{
 
  return
    ((left < 0) || (((unsigned int)right) >= 32) || (left > (INT16_MAX >> ((unsigned int)right)))) ?
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
    (si==INT32_MIN) ?
    ((si)) :
    -si;
}
static int32_t
(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{
 
  return
    (((si1>0) && (si2>0) && (si1 > (INT32_MAX-si2))) || ((si1<0) && (si2<0) && (si1 < (INT32_MIN-si2)))) ?
    ((si1)) :
    (si1 + si2);
}
static int32_t
(safe_sub_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{
 
  return
    (((si1^si2) & (((si1 ^ ((si1^si2) & (~INT32_MAX)))-si2)^si2)) < 0) ?
    ((si1)) :
    (si1 - si2);
}
static int32_t
(safe_mul_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{
 
  return
    (((si1 > 0) && (si2 > 0) && (si1 > (INT32_MAX / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < (INT32_MIN / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < (INT32_MIN / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (INT32_MAX / si1)))) ?
    ((si1)) :
    si1 * si2;
}
static int32_t
(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == INT32_MIN) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 % si2);
}
static int32_t
(safe_div_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == INT32_MIN) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 / si2);
}
static int32_t
(safe_lshift_func_int32_t_s_s)(int32_t left, int right )
{
 
  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > (INT32_MAX >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static int32_t
(safe_lshift_func_int32_t_s_u)(int32_t left, unsigned int right )
{
 
  return
    ((left < 0) || (((unsigned int)right) >= 32) || (left > (INT32_MAX >> ((unsigned int)right)))) ?
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
    (si==INT64_MIN) ?
    ((si)) :
    -si;
}
static int64_t
(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return
    (((si1>0) && (si2>0) && (si1 > (INT64_MAX-si2))) || ((si1<0) && (si2<0) && (si1 < (INT64_MIN-si2)))) ?
    ((si1)) :
    (si1 + si2);
}
static int64_t
(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return
    (((si1^si2) & (((si1 ^ ((si1^si2) & (~INT64_MAX)))-si2)^si2)) < 0) ?
    ((si1)) :
    (si1 - si2);
}
static int64_t
(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return
    (((si1 > 0) && (si2 > 0) && (si1 > (INT64_MAX / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < (INT64_MIN / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < (INT64_MIN / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < (INT64_MAX / si1)))) ?
    ((si1)) :
    si1 * si2;
}
static int64_t
(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == INT64_MIN) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 % si2);
}
static int64_t
(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == INT64_MIN) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 / si2);
}
static int64_t
(safe_lshift_func_int64_t_s_s)(int64_t left, int right )
{
 
  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > (INT64_MAX >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static int64_t
(safe_lshift_func_int64_t_s_u)(int64_t left, unsigned int right )
{
 
  return
    ((left < 0) || (((unsigned int)right) >= 32) || (left > (INT64_MAX >> ((unsigned int)right)))) ?
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
    ((((int)right) < 0) || (((int)right) >= 32) || (left > (UINT8_MAX >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static uint8_t
(safe_lshift_func_uint8_t_u_u)(uint8_t left, unsigned int right )
{
 
  return
    ((((unsigned int)right) >= 32) || (left > (UINT8_MAX >> ((unsigned int)right)))) ?
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
    ((((int)right) < 0) || (((int)right) >= 32) || (left > (UINT16_MAX >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static uint16_t
(safe_lshift_func_uint16_t_u_u)(uint16_t left, unsigned int right )
{
 
  return
    ((((unsigned int)right) >= 32) || (left > (UINT16_MAX >> ((unsigned int)right)))) ?
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
    ((((int)right) < 0) || (((int)right) >= 32) || (left > (UINT32_MAX >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static uint32_t
(safe_lshift_func_uint32_t_u_u)(uint32_t left, unsigned int right )
{
 
  return
    ((((unsigned int)right) >= 32) || (left > (UINT32_MAX >> ((unsigned int)right)))) ?
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
    ((((int)right) < 0) || (((int)right) >= 32) || (left > (UINT64_MAX >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static uint64_t
(safe_lshift_func_uint64_t_u_u)(uint64_t left, unsigned int right )
{
 
  return
    ((((unsigned int)right) >= 32) || (left > (UINT64_MAX >> ((unsigned int)right)))) ?
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
    (fabsf((0.5f * sf1) + (0.5f * sf2)) > (0.5f * FLT_MAX)) ?
    (sf1) :
    (sf1 + sf2);
}
static float
(safe_sub_func_float_f_f)(float sf1, float sf2 )
{
 
  return
    (fabsf((0.5f * sf1) - (0.5f * sf2)) > (0.5f * FLT_MAX)) ?
    (sf1) :
    (sf1 - sf2);
}
static float
(safe_mul_func_float_f_f)(float sf1, float sf2 )
{
 
  return
    (fabsf((0x1.0p-100f * sf1) * (0x1.0p-28f * sf2)) > (0x1.0p-100f * (0x1.0p-28f * FLT_MAX))) ?
    (sf1) :
    (sf1 * sf2);
}
static float
(safe_div_func_float_f_f)(float sf1, float sf2 )
{
 
  return
    ((fabsf(sf2) < 1.0f) && (((sf2 == 0.0f) || (fabsf((0x1.0p-49f * sf1) / (0x1.0p100f * sf2))) > (0x1.0p-100f * (0x1.0p-49f * FLT_MAX))))) ?
    (sf1) :
    (sf1 / sf2);
}
static double
(safe_add_func_double_f_f)(double sf1, double sf2 )
{
 
  return
    (fabs((0.5 * sf1) + (0.5 * sf2)) > (0.5 * DBL_MAX)) ?
    (sf1) :
    (sf1 + sf2);
}
static double
(safe_sub_func_double_f_f)(double sf1, double sf2 )
{
 
  return
    (fabs((0.5 * sf1) - (0.5 * sf2)) > (0.5 * DBL_MAX)) ?
    (sf1) :
    (sf1 - sf2);
}
static double
(safe_mul_func_double_f_f)(double sf1, double sf2 )
{
 
  return
    (fabs((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) > (0x1.0p-100 * (0x1.0p-924 * DBL_MAX))) ?
    (sf1) :
    (sf1 * sf2);
}
static double
(safe_div_func_double_f_f)(double sf1, double sf2 )
{
 
  return
    ((fabs(sf2) < 1.0) && (((sf2 == 0.0) || (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) > (0x1.0p-100 * (0x1.0p-974 * DBL_MAX))))) ?
    (sf1) :
    (sf1 / sf2);
}
static int32_t
(safe_convert_func_float_to_int32_t)(float sf1 )
{
 
  return
    ((sf1 <= INT32_MIN) || (sf1 >= INT32_MAX)) ?
    (INT32_MAX) :
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
union U0 {
   uint32_t f0;
   volatile int32_t f1;
   int32_t f2;
};
static volatile int32_t g_2 = 0L;
static volatile int32_t g_3 = 0x32A27689L;
static volatile int32_t g_4 = 0L;
static int32_t g_5 = 1L;
static int32_t g_8 = 0xD2D672A8L;
static int32_t g_11[8] = {(-1L), (-1L), 0x23FE5E81L, (-1L), (-1L), 0x23FE5E81L, (-1L), (-1L)};
static int32_t g_80 = 0xA90D2634L;
static int16_t g_100[1][2] = {{0x7242L, 0x7242L}};
static uint32_t g_112[5] = {0x2CBA3753L, 0UL, 0x2CBA3753L, 0UL, 0x2CBA3753L};
static int32_t g_114 = 0x5DEB7CA3L;
static uint32_t g_145 = 4294967288UL;
static int32_t g_155 = 0x1030EC2AL;
static uint32_t g_158 = 0x603FA023L;
static int32_t g_172 = 0x1836AFDFL;
static uint32_t g_176[9] = {0x9D596B0AL, 0x9D596B0AL, 4294967295UL, 0x9D596B0AL, 0x9D596B0AL, 4294967295UL, 0x9D596B0AL, 0x9D596B0AL, 4294967295UL};
static int32_t g_186[4][8][5] = {{{0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}}, {{0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}}, {{0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}}, {{0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}, {0x1A4B0108L, 0x4DB03F72L, 0L, 7L, 1L}}};
static int32_t g_187 = 0x53D48F03L;
static uint8_t g_189 = 255UL;
static int32_t * volatile g_200 = &g_8;
static int32_t * volatile *g_199[3] = {&g_200, &g_200, &g_200};
static int32_t g_322 = 1L;
static uint32_t g_339 = 0x34ACBDE0L;
static int32_t g_400 = 0x04868CA1L;
static volatile int32_t g_486 = 0L;
static volatile int32_t *g_485 = &g_486;
static uint16_t g_518 = 0x4D0CL;
static union U0 g_538 = {0UL};
static union U0 *g_596 = (void*)0;
static union U0 g_652[3] = {{4294967293UL}, {4294967293UL}, {4294967293UL}};
static int32_t *g_712 = (void*)0;
static int8_t g_725 = (-7L);
static union U0 g_742 = {3UL};
static union U0 g_744 = {1UL};
static uint32_t g_771 = 1UL;
static uint16_t g_778[7] = {1UL, 3UL, 1UL, 3UL, 1UL, 3UL, 1UL};
static volatile union U0 g_1022 = {0xA61621B3L};
static volatile union U0 * volatile g_1021 = &g_1022;
static volatile union U0 * volatile * volatile g_1020 = &g_1021;
static volatile union U0 * volatile * volatile *g_1019 = &g_1020;
static int32_t g_1035 = 0x752011B8L;
static int32_t g_1151 = 0x870D206EL;
static union U0 g_1214 = {0x42619519L};
static union U0 g_1224 = {0xD9111926L};
static int32_t g_1271 = 0xF4919CE8L;
static int32_t g_1288[2] = {0x149C700FL, 0x149C700FL};
static int8_t g_1290 = 1L;
static int32_t ** volatile g_1328[8] = {&g_712, &g_712, &g_712, &g_712, &g_712, &g_712, &g_712, &g_712};
static int32_t ** volatile g_1329 = (void*)0;
static uint8_t g_1340[3] = {0xBFL, 0xBFL, 0xBFL};
static union U0 g_1371 = {9UL};
static volatile union U0 g_1372 = {0xA5629FABL};
static union U0 g_1399 = {4294967295UL};
static union U0 * volatile *g_1405 = &g_596;
static int32_t ** volatile g_1418 = &g_712;
static union U0 g_1444[7][9] = {{{4294967295UL}, {0x0A89104AL}, {9UL}, {1UL}, {0x815AAEBDL}, {0x883591C3L}, {0x5D9FD935L}, {4294967295UL}, {9UL}}, {{4294967295UL}, {0x0A89104AL}, {9UL}, {1UL}, {0x815AAEBDL}, {0x883591C3L}, {0x5D9FD935L}, {4294967295UL}, {9UL}}, {{4294967295UL}, {0x0A89104AL}, {9UL}, {1UL}, {0x815AAEBDL}, {0x883591C3L}, {0x5D9FD935L}, {4294967295UL}, {9UL}}, {{4294967295UL}, {0x0A89104AL}, {9UL}, {1UL}, {0x815AAEBDL}, {0x883591C3L}, {0x5D9FD935L}, {4294967295UL}, {9UL}}, {{4294967295UL}, {0x0A89104AL}, {9UL}, {1UL}, {0x815AAEBDL}, {0x883591C3L}, {0x5D9FD935L}, {4294967295UL}, {9UL}}, {{4294967295UL}, {0x0A89104AL}, {9UL}, {1UL}, {0x815AAEBDL}, {0x883591C3L}, {0x5D9FD935L}, {4294967295UL}, {9UL}}, {{4294967295UL}, {0x0A89104AL}, {9UL}, {1UL}, {0x815AAEBDL}, {0x883591C3L}, {0x5D9FD935L}, {4294967295UL}, {9UL}}};
static union U0 *** volatile g_1524 = (void*)0;
static uint16_t g_1566 = 0xB63CL;
static volatile uint32_t g_1591 = 0x994D66EFL;
static volatile uint32_t g_1622 = 1UL;
static union U0 g_1628 = {4294967291UL};
static volatile union U0 g_1646[7] = {{0x53D47EBDL}, {0x53D47EBDL}, {0xE4A53E8AL}, {0x53D47EBDL}, {0x53D47EBDL}, {0xE4A53E8AL}, {0x53D47EBDL}};
static union U0 g_1653 = {0x3A35E06CL};
static int32_t ** volatile g_1691 = (void*)0;
static int32_t ** volatile g_1693 = &g_712;
static uint32_t g_1703[4][1][6] = {{{3UL, 0xF7DC92B2L, 0x2E98D357L, 8UL, 8UL, 0x2E98D357L}}, {{3UL, 0xF7DC92B2L, 0x2E98D357L, 8UL, 8UL, 0x2E98D357L}}, {{3UL, 0xF7DC92B2L, 0x2E98D357L, 8UL, 8UL, 0x2E98D357L}}, {{3UL, 0xF7DC92B2L, 0x2E98D357L, 8UL, 8UL, 0x2E98D357L}}};
static uint32_t g_1731 = 1UL;
static int32_t ** volatile g_1732 = (void*)0;
static int32_t ** volatile g_1733 = &g_712;
static volatile union U0 g_1767 = {2UL};
static union U0 g_1806 = {2UL};
static volatile union U0 g_1814[4][10][1] = {{{{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}}, {{{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}}, {{{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}}, {{{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}, {{0x474130F5L}}}};
static volatile uint8_t g_1864[7][8][4] = {{{0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}}, {{0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}}, {{0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}}, {{0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}}, {{0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}}, {{0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}}, {{0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}, {0xB7L, 0x3FL, 0x7EL, 0x69L}}};
static uint32_t g_1882 = 0xEB5BE354L;
static uint16_t func_1(void);
static uint16_t func_14(uint32_t p_15, uint16_t p_16);
static uint8_t func_19(int8_t p_20, uint16_t p_21, uint32_t p_22, int32_t p_23);
static int8_t func_27(uint16_t p_28, int32_t p_29, int32_t p_30, uint32_t p_31);
static int16_t func_32(int16_t p_33, int32_t p_34, uint32_t p_35, uint8_t p_36);
static uint16_t func_44(uint32_t p_45, uint32_t p_46, uint32_t p_47);
static uint32_t func_51(int32_t p_52, int32_t p_53);
static int8_t func_56(uint32_t p_57, uint32_t p_58);
static uint8_t func_63(int8_t p_64, int32_t p_65, uint16_t p_66, uint16_t p_67, uint8_t p_68);
static int32_t func_91(int32_t * p_92, int8_t p_93, int32_t * p_94);
static uint16_t func_1(void)
{
    uint16_t l_25 = 0x6B34L;
    int32_t l_2002 = 0xF45BBAE9L;
    int32_t l_2008 = 0x86A31A9CL;
    for (g_5 = 4; (g_5 > (-30)); --g_5)
    {
        uint32_t l_37 = 0xAD33D2AFL;
        int32_t l_2000 = 0L;
        int32_t *l_2003 = &g_114;
        int32_t *l_2004 = &g_172;
        int32_t *l_2005 = &g_538.f2;
        int32_t *l_2006 = (void*)0;
        int32_t *l_2007[9][4] = {{&l_2002, &g_1371.f2, (void*)0, &g_80}, {&l_2002, &g_1371.f2, (void*)0, &g_80}, {&l_2002, &g_1371.f2, (void*)0, &g_80}, {&l_2002, &g_1371.f2, (void*)0, &g_80}, {&l_2002, &g_1371.f2, (void*)0, &g_80}, {&l_2002, &g_1371.f2, (void*)0, &g_80}, {&l_2002, &g_1371.f2, (void*)0, &g_80}, {&l_2002, &g_1371.f2, (void*)0, &g_80}, {&l_2002, &g_1371.f2, (void*)0, &g_80}};
        uint16_t l_2009 = 7UL;
        int i, j;
        for (g_8 = (-1); (g_8 != (-26)); g_8 = safe_sub_func_int8_t_s_s(g_8, 1))
        {
            uint32_t l_24 = 0xA07B3049L;
            uint8_t l_1212 = 0UL;
            int32_t *l_2001 = &g_172;
            for (g_11[2] = 0; (g_11[2] < (-18)); g_11[2]--)
            {
                uint32_t l_26[2][8] = {{0xFBEBF0A0L, 6UL, 0x3BED162CL, 6UL, 0xFBEBF0A0L, 6UL, 0x3BED162CL, 6UL}, {0xFBEBF0A0L, 6UL, 0x3BED162CL, 6UL, 0xFBEBF0A0L, 6UL, 0x3BED162CL, 6UL}};
                int i, j;
            }
            (*l_2001) = ((((((g_744.f0 , func_27(g_176[8], l_25, (2 , func_91(0, l_37, &l_2000)), g_538.f2)) | g_1214.f2) , l_2001) == (void*)0)) >= l_25);
        }
        --l_2009;
    }
    (*g_485) ^= l_2008;
    return l_2002;
}
static uint16_t func_14(uint32_t p_15, uint16_t p_16)
{
    int32_t *l_1327 = (void*)0;
    int32_t l_1331 = (-1L);
    int16_t l_1364 = (-1L);
    union U0 *l_1365 = (void*)0;
    int16_t l_1367 = 0x42FBL;
    int32_t l_1368 = 0xFB98D53CL;
    int32_t l_1378 = 0x1882E787L;
    int32_t *l_1406[5][5][2] = {{{&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}}, {{&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}}, {{&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}}, {{&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}}, {{&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}, {&g_8, (void*)0}}};
    uint32_t l_1407[4];
    int32_t l_1408 = (-8L);
    uint32_t l_1441 = 0x31659B69L;
    int8_t l_1453 = 0x52L;
    int16_t l_1522 = 1L;
    uint8_t l_1523 = 255UL;
    int16_t l_1536[7][6] = {{2L, 0xA845L, 3L, (-3L), 2L, (-1L)}, {2L, 0xA845L, 3L, (-3L), 2L, (-1L)}, {2L, 0xA845L, 3L, (-3L), 2L, (-1L)}, {2L, 0xA845L, 3L, (-3L), 2L, (-1L)}, {2L, 0xA845L, 3L, (-3L), 2L, (-1L)}, {2L, 0xA845L, 3L, (-3L), 2L, (-1L)}, {2L, 0xA845L, 3L, (-3L), 2L, (-1L)}};
    uint8_t l_1574[10] = {0x20L, 0x20L, 0x95L, 0x20L, 0x20L, 0x95L, 0x20L, 0x20L, 0x95L, 0x20L};
    int16_t l_1715[4][7][3] = {{{0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}}, {{0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}}, {{0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}}, {{0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}, {0L, (-1L), 0L}}};
    int16_t l_1744 = (-4L);
    int32_t **l_1771 = &l_1406[2][0][1];
    int32_t ***l_1770 = &l_1771;
    uint32_t l_1785[9][10] = {{4294967295UL, 0x945D53B1L, 0xF8CB5B8BL, 0UL, 0UL, 5UL, 0xFEA0A6ECL, 0UL, 0UL, 0xFEA0A6ECL}, {4294967295UL, 0x945D53B1L, 0xF8CB5B8BL, 0UL, 0UL, 5UL, 0xFEA0A6ECL, 0UL, 0UL, 0xFEA0A6ECL}, {4294967295UL, 0x945D53B1L, 0xF8CB5B8BL, 0UL, 0UL, 5UL, 0xFEA0A6ECL, 0UL, 0UL, 0xFEA0A6ECL}, {4294967295UL, 0x945D53B1L, 0xF8CB5B8BL, 0UL, 0UL, 5UL, 0xFEA0A6ECL, 0UL, 0UL, 0xFEA0A6ECL}, {4294967295UL, 0x945D53B1L, 0xF8CB5B8BL, 0UL, 0UL, 5UL, 0xFEA0A6ECL, 0UL, 0UL, 0xFEA0A6ECL}, {4294967295UL, 0x945D53B1L, 0xF8CB5B8BL, 0UL, 0UL, 5UL, 0xFEA0A6ECL, 0UL, 0UL, 0xFEA0A6ECL}, {4294967295UL, 0x945D53B1L, 0xF8CB5B8BL, 0UL, 0UL, 5UL, 0xFEA0A6ECL, 0UL, 0UL, 0xFEA0A6ECL}, {4294967295UL, 0x945D53B1L, 0xF8CB5B8BL, 0UL, 0UL, 5UL, 0xFEA0A6ECL, 0UL, 0UL, 0xFEA0A6ECL}, {4294967295UL, 0x945D53B1L, 0xF8CB5B8BL, 0UL, 0UL, 5UL, 0xFEA0A6ECL, 0UL, 0UL, 0xFEA0A6ECL}};
    int8_t l_1837[5];
    int32_t l_1844 = 0x2D859095L;
    uint32_t l_1851 = 1UL;
    int32_t l_1856 = 0xAF53FA4BL;
    uint32_t l_1859 = 0x3C447E2CL;
    uint32_t l_1924 = 1UL;
    int i, j, k;
    for (i = 0; i < 4; i++)
        ;
    for (i = 0; i < 5; i++)
        ;
    for (g_1214.f2 = 0; (g_1214.f2 != 26); g_1214.f2 = safe_add_func_int32_t_s_s(g_1214.f2, 8))
    {
        int32_t **l_1330[9] = {&l_1327, &l_1327, &l_1327, &l_1327, &l_1327, &l_1327, &l_1327, &l_1327, &l_1327};
        int32_t *l_1342 = (void*)0;
        uint16_t l_1363 = 65535UL;
        int16_t l_1366 = 0x52D2L;
        int32_t *l_1370 = &g_11[2];
        int32_t l_1387 = 0x2168DD71L;
        int i;
        l_1327 = l_1327;
        for (g_1224.f0 = 0; (g_1224.f0 == 29); g_1224.f0++)
        {
            int32_t *l_1341 = &g_538.f2;
            int32_t l_1346 = 0L;
            assert (g_712 == 0);
            for (g_187 = 14; (g_187 <= 2); g_187 = safe_sub_func_uint8_t_u_u(g_187, 5))
            {
                uint8_t l_1362 = 0xA9L;
                for (l_1331 = 8; (l_1331 >= 1); l_1331 -= 1)
                {
                    union U0 **l_1345 = &g_596;
                    uint32_t l_1361 = 0xB84C99F0L;
                    int i;
                    l_1346 ^= ((*l_1341) ^ ((l_1345 == (void*)0) == p_16));
                    if (p_15)
                        break;
                    (*l_1341) = ((safe_rshift_func_int16_t_s_u(((safe_sub_func_int32_t_s_s((((((safe_rshift_func_uint8_t_u_s((safe_rshift_func_uint8_t_u_s(((+(~(((safe_sub_func_int16_t_s_s((func_44((safe_mul_func_uint8_t_u_u(g_11[7], (((safe_sub_func_int16_t_s_s(l_1361, g_1224.f1)) , &l_1341) == l_1330[l_1331]))), ((~(&g_172 == &l_1346)) < (l_1362 >= 2L)), g_725) || 8L), p_15)) > g_172) < g_5))) >= p_16), 6)), 2)) && 0x08L) == p_15) > 0x80A0L) | p_15), l_1363)) , p_15), 12)) & 0UL);
                }
            }
        }
    }
    assert (g_712 == 0);
    l_1408 ^= ((void*)0 == l_1365);
    if ((((*g_1019) == &l_1365) | func_56(p_16, g_1271)))
    {
        uint32_t l_1413 = 0xB86B69E5L;
        int32_t *l_1414 = (void*)0;
        union U0 *l_1426 = (void*)0;
        uint32_t l_1450 = 1UL;
        int32_t l_1481 = 0xD3467DD2L;
        int32_t l_1532 = 0xD46660F0L;
        int32_t l_1533[9][7] = {{(-9L), (-9L), 0xE33F2CBFL, 0x3B365972L, 0xEACEC738L, 0L, 0xE2518014L}, {(-9L), (-9L), 0xE33F2CBFL, 0x3B365972L, 0xEACEC738L, 0L, 0xE2518014L}, {(-9L), (-9L), 0xE33F2CBFL, 0x3B365972L, 0xEACEC738L, 0L, 0xE2518014L}, {(-9L), (-9L), 0xE33F2CBFL, 0x3B365972L, 0xEACEC738L, 0L, 0xE2518014L}, {(-9L), (-9L), 0xE33F2CBFL, 0x3B365972L, 0xEACEC738L, 0L, 0xE2518014L}, {(-9L), (-9L), 0xE33F2CBFL, 0x3B365972L, 0xEACEC738L, 0L, 0xE2518014L}, {(-9L), (-9L), 0xE33F2CBFL, 0x3B365972L, 0xEACEC738L, 0L, 0xE2518014L}, {(-9L), (-9L), 0xE33F2CBFL, 0x3B365972L, 0xEACEC738L, 0L, 0xE2518014L}, {(-9L), (-9L), 0xE33F2CBFL, 0x3B365972L, 0xEACEC738L, 0L, 0xE2518014L}};
        uint32_t l_1538 = 0x01881744L;
        uint16_t l_1543 = 0UL;
        int8_t l_1615 = 0x90L;
        int16_t l_1662 = 0L;
        uint16_t l_1673[9] = {8UL, 8UL, 65534UL, 8UL, 8UL, 65534UL, 8UL, 8UL, 65534UL};
        uint32_t l_1714 = 0x493B5762L;
        int16_t l_1719 = 0x75B2L;
        uint32_t l_1766 = 18446744073709551608UL;
        int i, j;
        if ((safe_mod_func_uint16_t_u_u((p_15 < (safe_add_func_uint8_t_u_u((l_1413 && 1UL), g_322))), g_112[4])))
        {
            uint8_t l_1417 = 255UL;
            int32_t *l_1421 = &g_1288[0];
            uint32_t l_1470 = 0x427758F6L;
            if ((l_1414 != &l_1408))
            {
                union U0 **l_1432 = &g_596;
                int32_t **l_1433 = &l_1406[0][4][1];
                int32_t l_1474 = (-10L);
                (*g_1418) = ((g_1372.f2 ^ ((safe_add_func_int8_t_s_s(p_15, (((func_44(p_15, p_16, l_1417) , g_771) && (((g_11[2] , p_16) | 4L) ^ 0x53L)) & p_16))) != 4294967291UL)) , l_1414);
                assert (g_712 == 0);
                for (g_145 = 0; (g_145 != 45); ++g_145)
                {
                    int32_t l_1429 = 0L;
                    int32_t **l_1431 = &l_1406[0][4][0];
                    int32_t ***l_1430 = &l_1431;
                    uint16_t l_1449 = 65531UL;
                    l_1421 = &l_1331;
                    assert (l_1421 == &l_1331);
                    if ((p_15 , ((((safe_add_func_uint8_t_u_u((*l_1421), (safe_lshift_func_int8_t_s_s(0x4BL, 2)))) , &l_1408) != (void*)0) <= ((l_1426 == (*g_1020)) >= (safe_div_func_uint8_t_u_u((l_1429 , (((l_1430 != (void*)0) , &l_1426) != l_1432)), 0x2EL))))))
                    {
                        uint32_t l_1438[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            ;
                        (*l_1421) |= (((((((void*)0 != l_1433) , p_15) > (safe_sub_func_uint8_t_u_u(((safe_mod_func_uint16_t_u_u(g_1371.f2, l_1438[0])) == p_15), 0x3AL))) , (safe_sub_func_int16_t_s_s((func_63((0xD04BL <= g_339), p_16, g_1271, g_1214.f1, p_16) > p_15), l_1441))) , 0xA286DBF6L) < p_15);
                        (*l_1421) = func_63((safe_rshift_func_int16_t_s_u((&g_712 == (g_1444[6][5] , ((safe_add_func_int16_t_s_s(p_16, (9UL == ((safe_div_func_int16_t_s_s(((*g_1019) == (void*)0), p_15)) > g_518)))) , (void*)0))), p_16)), (*l_1421), g_1444[6][5].f2, l_1449, l_1450);
                    }
                    else
                    {
                        if (p_15)
                            ;
                        (*l_1421) ^= 5L;
                    }
                    for (g_189 = 0; (g_189 <= 2); g_189 += 1)
                    {
                        uint16_t l_1471 = 0x72C6L;
                        return l_1471;
                    }
                    if (p_15)
                        ;
                }
                assert (l_1421 == &l_1331 || (l_1421 >= &g_1288[0] && l_1421 <= &g_1288[1]));
                l_1474 ^= (g_1288[0] , (4294967295UL < (0xAFL | (!(safe_sub_func_int32_t_s_s((g_538.f1 == (((&g_199[2] == (void*)0) >= (((0x80EDL > p_15) || (func_91(&l_1408, g_744.f2, &g_1151) == 0xABA9L)) , g_1035)) > g_1035)), 0xFF3C01DCL))))));
                for (g_322 = 0; (g_322 <= (-19)); g_322 = safe_sub_func_uint8_t_u_u(g_322, 4))
                {
                    int16_t l_1477 = 0x70AFL;
                    return l_1477;
                }
            }
            else
            {
                int32_t l_1480 = (-9L);
                l_1480 = (safe_rshift_func_uint8_t_u_s((g_652[1].f1 == 1UL), 1));
            }
            assert (l_1421 == &l_1331 || (l_1421 >= &g_1288[0] && l_1421 <= &g_1288[1]));
            l_1481 ^= (0xF8L <= g_1340[0]);
        }
        else
        {
            int16_t l_1488 = 7L;
            int32_t l_1489 = (-1L);
            union U0 *l_1511 = &g_1444[1][6];
            int32_t l_1528 = 1L;
            int32_t l_1530 = 0xA3641F29L;
            int32_t l_1537[9];
            int i;
            for (i = 0; i < 9; i++)
                l_1537[i] = 0xD46EF763L;
            for (l_1378 = 12; (l_1378 == 25); l_1378++)
            {
                uint32_t l_1486 = 0x61095666L;
                int32_t l_1487 = 0x7F8254F1L;
                int32_t l_1526 = 3L;
                int32_t l_1527 = 0xEED0750EL;
                int32_t l_1529 = (-1L);
                int32_t l_1531 = 1L;
                int32_t l_1534[2];
                int8_t l_1535 = 0L;
                int i;
                for (i = 0; i < 2; i++)
                    l_1534[i] = 0L;
                for (g_1214.f0 = 0; (g_1214.f0 <= 2); g_1214.f0 += 1)
                {
                    union U0 **l_1500 = &l_1426;
                    int i;
                    if (func_63(g_778[g_1214.f0], p_15, l_1488, l_1487, ((l_1489 || l_1486) >= ((1UL == ((safe_lshift_func_int16_t_s_u((~(safe_lshift_func_uint8_t_u_u(g_155, (safe_sub_func_uint16_t_u_u((((p_16 , g_778[g_1214.f0]) & l_1488) & p_16), 0xB1FEL))))), 15)) , 0x27L)) != l_1488))))
                    {
                        l_1489 = ((l_1487 || (safe_div_func_uint32_t_u_u(g_771, p_15))) && (safe_sub_func_uint16_t_u_u((((((l_1500 == (void*)0) & p_15) < p_15) && p_16) > ((((!((0x90L <= g_1372.f1) > p_16)) | p_16) & p_16) > 0UL)), g_11[2])));
                        l_1481 = (&l_1414 != &g_712);
                        l_1487 = func_44((safe_rshift_func_uint8_t_u_s((safe_mod_func_int32_t_s_s(0x407ED192L, ((safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s(func_51((l_1511 == l_1426), (((safe_sub_func_uint16_t_u_u(((**g_1020) , (safe_lshift_func_int16_t_s_s(0x171DL, 13))), (safe_rshift_func_uint16_t_u_u((((func_27((0xC973L > (safe_sub_func_uint16_t_u_u((g_725 <= ((p_16 || (safe_sub_func_int32_t_s_s(p_15, p_16))) && g_189)), p_15))), p_16, g_1214.f0, l_1450) , p_16) & p_15) , l_1488), 1)))) <= 0xDA38E401L) , (*g_200))), p_15)) != l_1522), 4)), p_15)) & g_176[5]))), 1)), l_1523, p_15);
                        assert (g_712 == 0);
                    }
                    else
                    {
                        union U0 ***l_1525 = &l_1500;
                    }
                    return p_15;
                }
                for (l_1535 = 4; (l_1535 >= 0); l_1535 -= 1)
                {
                    int i, j;
                    l_1489 = l_1536[(l_1535 + 2)][l_1535];
                }
            }
        }
        if (((safe_sub_func_uint32_t_u_u(((g_1022.f2 , g_742.f0) , g_771), (&l_1426 != (g_1214.f2 , (void*)0)))) >= (safe_lshift_func_int16_t_s_u(p_15, 3))))
        {
            int32_t l_1548 = 0x3A03E954L;
            int32_t l_1549 = 0L;
            int32_t l_1550 = (-4L);
            uint8_t l_1551[8];
            int32_t **l_1564 = &l_1406[0][0][0];
            int32_t ***l_1563[5] = {(void*)0, &l_1564, (void*)0, &l_1564, (void*)0};
            int32_t **l_1565 = &g_712;
            int i;
            for (i = 0; i < 8; i++)
                ;
            --l_1551[6];
            for (g_538.f2 = 0; (g_538.f2 != 14); ++g_538.f2)
            {
                int16_t l_1556[5] = {1L, (-2L), 1L, (-2L), 1L};
                int i;
                l_1532 = (l_1556[0] >= (((func_63(p_15, l_1556[0], (((g_80 , (((safe_rshift_func_uint8_t_u_s(251UL, (safe_sub_func_int16_t_s_s(1L, (p_16 && ((safe_sub_func_uint8_t_u_u((l_1551[6] ^ g_187), g_744.f1)) != l_1551[4])))))) , l_1563[4]) != (void*)0)) , &l_1414) != l_1565), g_1566, g_652[1].f2) , &l_1365) != &l_1426) , p_16));
            }
            for (g_145 = 0; (g_145 <= 7); g_145 += 1)
            {
                int32_t l_1569[1][6] = {{0x3D46B447L, 0x3D46B447L, 0x6A7BB0FAL, 0x3D46B447L, 0x3D46B447L, 0x6A7BB0FAL}};
                int32_t l_1570 = 0x80A50794L;
                int i, j;
                for (g_744.f2 = 0; (g_744.f2 <= 7); g_744.f2 += 1)
                {
                    if (p_15)
                        ;
                }
                if ((((*g_1021) , (((g_1214.f1 >= 0x70B2L) , func_27((g_4 , ((&l_1565 == &l_1565) , (safe_rshift_func_int8_t_s_s((-7L), 0)))), ((&g_712 == (void*)0) <= 1UL), l_1569[0][5], p_16)) != 0x4D7FL)) & p_16))
                {
                    for (g_1566 = 0; (g_1566 <= 2); g_1566 += 1)
                    {
                    }
                }
                else
                {
                    if ((*g_200))
                        ;
                }
                for (l_1549 = 7; (l_1549 >= 0); l_1549 -= 1)
                {
                    uint32_t l_1571 = 0xC04F7835L;
                    uint32_t l_1590 = 1UL;
                    int32_t l_1596 = (-1L);
                    for (g_742.f2 = 2; (g_742.f2 <= 7); g_742.f2 += 1)
                    {
                        union U0 **l_1581 = &l_1426;
                        int i;
                        if (p_16)
                            continue;
                        assert (g_712 == 0);
                    }
                    if (func_44((&l_1406[0][4][0] != &g_712), g_1371.f1, ((safe_add_func_int32_t_s_s((safe_sub_func_uint32_t_u_u(((6L ^ ((safe_rshift_func_uint16_t_u_u(((g_725 != (((safe_add_func_int8_t_s_s((p_16 ^ 0x2329L), (&g_1405 == (void*)0))) , l_1569[0][5]) && l_1590)) <= g_744.f2), p_15)) < 0x4CL)) && l_1570), p_16)), p_16)) , p_16)))
                    {
                        return p_15;
                    }
                    else
                    {
                        (*l_1564) = (void*)0;
                    }
                    assert (g_712 == 0);
                    if (g_1591)
                        break;
                    l_1596 = ((safe_lshift_func_int8_t_s_u(0x32L, 2)) < (safe_rshift_func_uint16_t_u_s(0xC087L, 8)));
                }
            }
        }
        else
        {
            uint32_t l_1610 = 1UL;
            int32_t l_1612 = 9L;
            int32_t l_1613 = 0xC6619F03L;
            int32_t l_1616 = (-7L);
            int32_t l_1617 = 0xC1C094FDL;
            int32_t l_1618 = 0x555B3D8DL;
            int32_t l_1619 = (-10L);
            int32_t l_1620 = (-2L);
            int32_t l_1621 = (-5L);
            union U0 **l_1631 = &l_1426;
            int8_t l_1720 = 0x93L;
            uint8_t l_1745[4][2][5] = {{{1UL, 3UL, 0UL, 0x38L, 0xBCL}, {1UL, 3UL, 0UL, 0x38L, 0xBCL}}, {{1UL, 3UL, 0UL, 0x38L, 0xBCL}, {1UL, 3UL, 0UL, 0x38L, 0xBCL}}, {{1UL, 3UL, 0UL, 0x38L, 0xBCL}, {1UL, 3UL, 0UL, 0x38L, 0xBCL}}, {{1UL, 3UL, 0UL, 0x38L, 0xBCL}, {1UL, 3UL, 0UL, 0x38L, 0xBCL}}};
            int i, j, k;
            for (l_1368 = 21; (l_1368 >= 23); l_1368++)
            {
                int8_t l_1604 = 0x04L;
                int32_t l_1614[9] = {(-6L), 0x121EBDCAL, (-6L), 0x121EBDCAL, (-6L), 0x121EBDCAL, (-6L), 0x121EBDCAL, (-6L)};
                uint16_t l_1640 = 0x5243L;
                int i;
                for (l_1367 = 2; (l_1367 >= 0); l_1367 -= 1)
                {
                    uint8_t l_1600[1];
                    uint8_t l_1601 = 2UL;
                    int32_t *l_1611[5][4] = {{&g_155, &g_155, &g_1035, &g_155}, {&g_155, &g_155, &g_1035, &g_155}, {&g_155, &g_155, &g_1035, &g_155}, {&g_155, &g_155, &g_1035, &g_155}, {&g_155, &g_155, &g_1035, &g_155}};
                    int i, j;
                    for (i = 0; i < 1; i++)
                        ;
                    if (p_15)
                    {
                        int32_t l_1599 = (-6L);
                        if (l_1600[0])
                            continue;
                        ++l_1601;
                    }
                    else
                    {
                        uint16_t l_1605 = 0x9FD0L;
                        l_1610 ^= ((0x6710L ^ (safe_lshift_func_int8_t_s_u(g_1214.f0, (((p_15 || p_15) , 65528UL) == (g_1372.f2 | ((l_1543 , (g_744.f0 || ((l_1604 && l_1604) , 1UL))) >= 0x28C0EBCEL)))))) , l_1605);
                        l_1612 = p_16;
                    }
                }
                ++g_1622;
                if ((safe_div_func_uint8_t_u_u(g_172, ((g_172 > p_16) && l_1614[8]))))
                {
                    union U0 *l_1627 = &g_1628;
                    int32_t l_1634 = 0xAE6425A5L;
                    int32_t l_1639[7][9] = {{0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L}, {0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L}, {0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L}, {0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L}, {0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L}, {0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L}, {0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L, 0L, 0L, 0x846809D8L}};
                    int16_t l_1658 = 1L;
                    int i, j;
                    if ((func_19(((**g_1019) == l_1627), ((func_19(g_1214.f0, p_16, p_15, (l_1620 >= (func_63((((void*)0 == l_1631) && 0x50L), p_16, g_100[0][1], p_16, g_1224.f2) != g_1628.f0))) | p_16) && g_538.f0), g_1399.f0, p_15) <= 0xD2L))
                    {
                        int32_t *l_1632 = &g_400;
                        int32_t l_1633 = 0x03DCC2CDL;
                        int32_t l_1635 = 0xBF768541L;
                        int32_t l_1636 = 0x231ED93DL;
                        int32_t l_1637 = 0x47764535L;
                        int32_t l_1638 = 0L;
                        l_1632 = (*g_1418);
                        assert (l_1632 == &g_1035 || l_1632 == &g_172 || l_1632 == &g_538.f2 || l_1632 == 0);
                        l_1640++;
                    }
                    else
                    {
                        uint32_t l_1643[8][8] = {{0xFFA36FE5L, 4294967286UL, 0UL, 0xABDC9A81L, 0UL, 4294967286UL, 0xFFA36FE5L, 0x674643A6L}, {0xFFA36FE5L, 4294967286UL, 0UL, 0xABDC9A81L, 0UL, 4294967286UL, 0xFFA36FE5L, 0x674643A6L}, {0xFFA36FE5L, 4294967286UL, 0UL, 0xABDC9A81L, 0UL, 4294967286UL, 0xFFA36FE5L, 0x674643A6L}, {0xFFA36FE5L, 4294967286UL, 0UL, 0xABDC9A81L, 0UL, 4294967286UL, 0xFFA36FE5L, 0x674643A6L}, {0xFFA36FE5L, 4294967286UL, 0UL, 0xABDC9A81L, 0UL, 4294967286UL, 0xFFA36FE5L, 0x674643A6L}, {0xFFA36FE5L, 4294967286UL, 0UL, 0xABDC9A81L, 0UL, 4294967286UL, 0xFFA36FE5L, 0x674643A6L}, {0xFFA36FE5L, 4294967286UL, 0UL, 0xABDC9A81L, 0UL, 4294967286UL, 0xFFA36FE5L, 0x674643A6L}, {0xFFA36FE5L, 4294967286UL, 0UL, 0xABDC9A81L, 0UL, 4294967286UL, 0xFFA36FE5L, 0x674643A6L}};
                        int i, j;
                        l_1643[7][7]++;
                    }
                    assert (g_712 == &g_1035 || g_712 == &g_172 || g_712 == &g_538.f2 || g_712 == 0);
                    for (g_1151 = 0; (g_1151 < 9); g_1151++)
                    {
                        int32_t **l_1657 = &l_1406[4][4][0];
                        int32_t ***l_1656 = &l_1657;
                    }
                    return l_1634;
                }
                else
                {
                    uint16_t l_1659[8] = {1UL, 0xDC18L, 1UL, 0xDC18L, 1UL, 0xDC18L, 1UL, 0xDC18L};
                    int i;
                    l_1659[1]--;
                }
            }
            if (func_32(l_1662, (g_771 | p_16), g_1224.f2, (p_15 , (safe_add_func_uint8_t_u_u(((l_1618 , ((safe_rshift_func_int8_t_s_s(p_16, 3)) , p_15)) == (1UL <= l_1617)), p_15)))))
            {
                uint16_t l_1686 = 0x6667L;
                int32_t l_1709 = 1L;
                int32_t l_1713 = 0x73D59F12L;
                for (l_1543 = 0; l_1543 < 4; l_1543 += 1)
                {
                    for (g_187 = 0; g_187 < 8; g_187 += 1)
                    {
                    }
                }
                if ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(65531UL, g_8)), 8)))
                {
                    int32_t **l_1692 = (void*)0;
                    int32_t **l_1694 = &l_1406[0][2][0];
                    union U0 **l_1710 = &l_1426;
                    assert (g_712 == &l_1613);
                    (*l_1694) = (*g_1418);
                }
                else
                {
                    uint16_t l_1721 = 0x6C9AL;
                    int32_t l_1743 = 8L;
                    if ((safe_mod_func_uint16_t_u_u((((l_1709 <= (-9L)) ^ l_1713) , p_15), l_1714)))
                    {
                        uint32_t l_1716 = 0xD0AF2EBDL;
                        l_1719 ^= (p_16 & (+(p_16 | p_15)));
                    }
                    else
                    {
                        int32_t l_1730 = 4L;
                        uint16_t l_1740 = 0x5E83L;
                        l_1721 = (g_1224.f2 || l_1720);
                        g_1731 ^= (((p_15 >= (safe_rshift_func_int16_t_s_s(g_176[7], (safe_lshift_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s(p_16, 12)), 0))))) , (safe_add_func_int32_t_s_s(p_15, func_19(g_744.f0, g_1271, (l_1730 >= l_1686), g_1444[6][5].f2)))) && p_15);
                        assert (g_712 == &g_1035 || g_712 == 0);
                        (*g_1733) = &l_1730;
                        assert (g_712 == &l_1730);
                        l_1743 = (safe_sub_func_int8_t_s_s((safe_div_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(l_1740, (g_1224.f1 ^ (0x289BL || func_44(g_652[1].f2, l_1713, (safe_lshift_func_uint8_t_u_s((p_15 , 0x55L), p_16))))))), p_15)), g_1035));
                        assert (g_712 == &l_1730 || g_712 == 0);
                    }
                    l_1743 ^= l_1721;
                    return p_15;
                }
                assert (g_712 == &l_1613);
            }
            else
            {
                uint8_t l_1748 = 0UL;
                l_1748 ^= (g_1399.f1 , p_16);
                for (l_1616 = 0; (l_1616 < (-16)); --l_1616)
                {
                    uint32_t l_1751 = 0xF6FCE940L;
                    l_1481 ^= p_16;
                    l_1751 |= (-7L);
                }
            }
            assert (g_712 == 0 || g_712 == &l_1613);
        }
        for (g_1151 = 0; (g_1151 < (-18)); g_1151 = safe_sub_func_int16_t_s_s(g_1151, 5))
        {
            uint32_t l_1778 = 0x1FC836E9L;
            int32_t l_1779 = 0x0EE66877L;
            l_1779 = p_16;
        }
        for (g_1371.f2 = 0; (g_1371.f2 >= (-16)); --g_1371.f2)
        {
            int32_t l_1782[6] = {0xB922D4D5L, 0L, 0xB922D4D5L, 0L, 0xB922D4D5L, 0L};
            int32_t l_1783 = 0L;
            int32_t l_1784[1][2];
            int i, j;
            for (i = 0; i < 1; i++)
            {
                for (j = 0; j < 2; j++)
                    l_1784[i][j] = 0x1DAF6D62L;
            }
            l_1782[4] = 3L;
            l_1785[2][4]++;
        }
    }
    else
    {
        uint8_t l_1804 = 255UL;
        int32_t *l_1807 = &g_8;
        int32_t ***l_1833 = &l_1771;
        int32_t l_1838 = 6L;
        int32_t l_1841 = 0L;
        int32_t l_1842 = 0xB00395D2L;
        int32_t l_1843 = 0L;
        int32_t l_1845 = 2L;
        int32_t l_1846 = (-1L);
        int32_t l_1847 = 0x6A94C78AL;
        int16_t l_1848 = (-4L);
        int32_t l_1849 = 1L;
        int32_t l_1850 = 0x5A57995AL;
        uint32_t l_1911[8][10][3] = {{{18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}}, {{18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}}, {{18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}}, {{18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}}, {{18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}}, {{18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}}, {{18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}}, {{18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}, {18446744073709551615UL, 0x9E502F8BL, 0UL}}};
        uint32_t l_1934 = 0UL;
        int8_t l_1957 = (-9L);
        int32_t l_1973 = 0xEAC6BB29L;
        int32_t l_1974[7] = {(-1L), (-1L), 0x25AAB718L, (-1L), (-1L), 0x25AAB718L, (-1L)};
        int8_t l_1989 = (-8L);
        uint32_t l_1995 = 0x15B31ADBL;
        uint16_t l_1996 = 65534UL;
        int i, j, k;
        for (g_189 = 7; (g_189 >= 28); g_189++)
        {
            uint8_t l_1796[10][10] = {{0x62L, 2UL, 0x23L, 0x97L, 246UL, 0x8DL, 6UL, 4UL, 9UL, 0x15L}, {0x62L, 2UL, 0x23L, 0x97L, 246UL, 0x8DL, 6UL, 4UL, 9UL, 0x15L}, {0x62L, 2UL, 0x23L, 0x97L, 246UL, 0x8DL, 6UL, 4UL, 9UL, 0x15L}, {0x62L, 2UL, 0x23L, 0x97L, 246UL, 0x8DL, 6UL, 4UL, 9UL, 0x15L}, {0x62L, 2UL, 0x23L, 0x97L, 246UL, 0x8DL, 6UL, 4UL, 9UL, 0x15L}, {0x62L, 2UL, 0x23L, 0x97L, 246UL, 0x8DL, 6UL, 4UL, 9UL, 0x15L}, {0x62L, 2UL, 0x23L, 0x97L, 246UL, 0x8DL, 6UL, 4UL, 9UL, 0x15L}, {0x62L, 2UL, 0x23L, 0x97L, 246UL, 0x8DL, 6UL, 4UL, 9UL, 0x15L}, {0x62L, 2UL, 0x23L, 0x97L, 246UL, 0x8DL, 6UL, 4UL, 9UL, 0x15L}, {0x62L, 2UL, 0x23L, 0x97L, 246UL, 0x8DL, 6UL, 4UL, 9UL, 0x15L}};
            int16_t l_1803 = (-8L);
            int32_t *l_1805 = (void*)0;
            int i, j;
            for (p_16 = (-20); (p_16 >= 45); ++p_16)
            {
                return g_1444[6][5].f0;
            }
            for (g_1371.f0 = 0; (g_1371.f0 <= 3); g_1371.f0 += 1)
            {
                int32_t *l_1792 = (void*)0;
                uint16_t l_1793 = 65528UL;
                int i;
                l_1793 = p_16;
            }
            for (g_1271 = 0; (g_1271 <= (-20)); g_1271 = safe_sub_func_uint16_t_u_u(g_1271, 2))
            {
                l_1804 ^= (+(((p_15 < l_1796[2][5]) >= (p_15 >= ((~(safe_add_func_int32_t_s_s(func_27(g_1151, (safe_sub_func_int8_t_s_s(p_16, (((func_27(g_1022.f0, p_15, (g_158 == (l_1796[2][5] ^ 0xD7L)), l_1796[2][5]) , (void*)0) == &g_596) > l_1803))), g_400, g_1653.f0), 0x08FF8841L))) <= 0L))) > p_15));
            }
            (**l_1770) = l_1805;
        }
        for (l_1804 = 0; (l_1804 <= 0); l_1804 += 1)
        {
            uint16_t l_1813 = 0UL;
            int32_t *l_1836[3];
            int i;
            for (i = 0; i < 3; i++)
                ;
            for (l_1331 = 0; (l_1331 >= 0); l_1331 -= 1)
            {
                uint32_t l_1812 = 0x2EBD1B2AL;
                uint32_t l_1815 = 0xD4578176L;
                uint16_t l_1819 = 0UL;
                union U0 **l_1824 = &l_1365;
                union U0 ***l_1823 = &l_1824;
                int32_t *l_1826 = &g_1371.f2;
                for (g_1566 = 1; (g_1566 <= 4); g_1566 += 1)
                {
                    union U0 **l_1821 = &g_596;
                    union U0 ***l_1820[7][4][5] = {{{&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}}, {{&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}}, {{&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}}, {{&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}}, {{&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}}, {{&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}}, {{&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}, {&l_1821, &l_1821, &l_1821, &l_1821, &l_1821}}};
                    int i, j, k;
                    l_1815 = (g_1806 , (((g_189 && (-4L)) , g_1814[2][5][0]) , 0L));
                    for (g_1806.f0 = 0; (g_1806.f0 <= 2); g_1806.f0 += 1)
                    {
                        uint32_t l_1822[10] = {1UL, 8UL, 1UL, 8UL, 1UL, 8UL, 1UL, 8UL, 1UL, 8UL};
                        int32_t * volatile **l_1825 = &g_199[0];
                        int i;
                        if (p_15)
                            break;
                        if (p_16)
                            continue;
                        assert (g_200 == 0);
                    }
                }
                (**l_1770) = l_1826;
                if ((*l_1807))
                    ;
                return l_1813;
            }
            assert (g_712 == 0);
            for (g_158 = 1; (g_158 <= 4); g_158 += 1)
            {
                int32_t l_1839 = 4L;
                int32_t l_1840[10];
                int i, j;
                for (i = 0; i < 10; i++)
                    ;
                l_1840[3] &= (safe_div_func_uint32_t_u_u(((g_100[l_1804][l_1804] , ((+((g_1444[6][5].f2 || ((-1L) == g_538.f2)) , g_1628.f2)) , (func_44(p_16, g_322, p_15) | 0xD4L))) <= l_1856), 4294967295UL));
            }
        }
        assert (g_200 == 0 || g_200 == &g_8);
        if (func_56((safe_lshift_func_int8_t_s_s(l_1859, (((((((((*l_1771) == (**l_1770)) , (safe_sub_func_int16_t_s_s(p_15, (safe_rshift_func_uint16_t_u_u(((p_15 , func_56((((+(*l_1807)) , 6L) != (+1L)), p_15)) , 0x5199L), g_1864[4][6][2]))))) && g_172) && g_486) >= 0xFD36144FL) | p_16) && p_16) || 1UL))), g_187))
        {
            uint8_t l_1880 = 2UL;
            int32_t l_1888 = 0x48B7FE5EL;
            int32_t l_1938 = 3L;
            int32_t l_1939 = 2L;
            int32_t l_1940 = 0x0544F468L;
            int32_t l_1941 = (-5L);
            int32_t l_1942 = 0x57A0F713L;
            int32_t l_1944 = 0x9E13BADAL;
            if (p_16)
            {
                uint16_t l_1881 = 1UL;
                uint16_t l_1883 = 0x65E7L;
                int32_t *l_1889 = &g_652[1].f2;
                if (((safe_div_func_uint8_t_u_u((g_114 && 255UL), ((safe_lshift_func_uint16_t_u_u(((safe_unary_minus_func_uint16_t_u(func_44(p_16, (((func_63((safe_sub_func_int16_t_s_s(p_15, ((func_44((safe_div_func_int32_t_s_s((((((0xCC360016L >= ((safe_mod_func_uint8_t_u_u((safe_mod_func_int32_t_s_s((g_1224.f0 > p_15), l_1880)), l_1880)) <= 1L)) >= 0xDEF45496L) == p_15) , 0xD9A5322FL) < 0xB9676EB1L), p_15)), l_1881, (*l_1807)) , p_15) != 0UL))), p_16, g_112[4], l_1880, g_1882) , 0xA62D9222L) , (**g_1019)) == (void*)0), l_1880))) || p_16), l_1883)) || 2L))) < (-1L)))
                {
                    return p_15;
                }
                else
                {
                    l_1888 = (safe_sub_func_uint8_t_u_u(p_15, (safe_add_func_uint16_t_u_u(0xF892L, 0x3179L))));
                    (**l_1833) = l_1889;
                }
                assert (g_712 == 0);
                for (l_1881 = 0; (l_1881 <= 4); l_1881 += 1)
                {
                    if (p_15)
                        ;
                }
            }
            else
            {
                int32_t *l_1899[10];
                int i;
                for (i = 0; i < 10; i++)
                    l_1899[i] = &l_1846;
                for (l_1845 = 0; (l_1845 >= 10); l_1845 = safe_add_func_uint8_t_u_u(l_1845, 3))
                {
                    uint8_t l_1896[2][5] = {{0xE9L, 0x2EL, 0xE9L, 0x2EL, 0xE9L}, {0xE9L, 0x2EL, 0xE9L, 0x2EL, 0xE9L}};
                    int32_t *l_1910 = &l_1850;
                    int i, j;
                    l_1888 = (safe_rshift_func_int16_t_s_u((safe_rshift_func_uint8_t_u_s((l_1896[0][0] < p_16), 2)), 9));
                    for (l_1846 = (-18); (l_1846 <= (-28)); l_1846 = safe_sub_func_int32_t_s_s(l_1846, 1))
                    {
                        int32_t ***l_1908 = &l_1771;
                        int32_t l_1909 = (-1L);
                        l_1909 &= ((func_44(g_1214.f1, ((void*)0 == l_1899[0]), (safe_sub_func_int32_t_s_s(func_56(((safe_mod_func_int16_t_s_s(func_51((*l_1807), l_1880), ((safe_sub_func_uint16_t_u_u(((0xCA93L != ((void*)0 != l_1908)) || g_112[4]), p_16)) ^ g_1444[6][5].f0))) , 4294967295UL), p_15), l_1896[0][1]))) < 0xCF18E7FEL) || p_15);
                        assert (g_712 == 0);
                        l_1910 = &l_1888;
                        assert (l_1910 == &l_1888);
                    }
                    assert (l_1910 == &l_1888 || l_1910 == &l_1850);
                }
            }
            if (((p_16 && ((*l_1833) == (void*)0)) || (safe_sub_func_uint8_t_u_u(p_16, g_155))))
            {
                int32_t l_1922 = 0xFE3B7CF4L;
                int32_t l_1923 = 1L;
                int32_t l_1933[9];
                int i;
                for (i = 0; i < 9; i++)
                    l_1933[i] = 0L;
                for (g_1628.f0 = 1; (g_1628.f0 <= 8); g_1628.f0 += 1)
                {
                    int32_t l_1920 = (-1L);
                    int i;
                    l_1920 &= func_56((safe_add_func_uint32_t_u_u(g_176[g_1628.f0], (p_16 && func_56(g_1628.f0, p_15)))), g_652[1].f2);
                    for (g_725 = 0; (g_725 <= 2); g_725 += 1)
                    {
                        int32_t l_1921 = 0xC2DEC06CL;
                        l_1921 &= ((void*)0 == (**g_1019));
                        --l_1924;
                    }
                }
                for (g_1628.f2 = 8; (g_1628.f2 == (-4)); g_1628.f2--)
                {
                    int16_t l_1932 = 1L;
                    for (g_538.f2 = 0; (g_538.f2 < (-25)); g_538.f2 = safe_sub_func_uint32_t_u_u(g_538.f2, 7))
                    {
                        int32_t *l_1931[5][6][4] = {{{&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}}, {{&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}}, {{&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}}, {{&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}}, {{&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}, {&g_1288[0], (void*)0, &l_1841, (void*)0}}};
                        int i, j, k;
                        (*l_1771) = l_1931[4][0][2];
                    }
                    (*l_1771) = (void*)0;
                }
            }
            else
            {
                uint8_t l_1937 = 1UL;
                int32_t l_1943[8][9] = {{0x9EFB1165L, 9L, 0x6002062CL, 0x5629D4B7L, (-1L), 7L, 0xCE8065F4L, 0x683D84E1L, 0x6002062CL}, {0x9EFB1165L, 9L, 0x6002062CL, 0x5629D4B7L, (-1L), 7L, 0xCE8065F4L, 0x683D84E1L, 0x6002062CL}, {0x9EFB1165L, 9L, 0x6002062CL, 0x5629D4B7L, (-1L), 7L, 0xCE8065F4L, 0x683D84E1L, 0x6002062CL}, {0x9EFB1165L, 9L, 0x6002062CL, 0x5629D4B7L, (-1L), 7L, 0xCE8065F4L, 0x683D84E1L, 0x6002062CL}, {0x9EFB1165L, 9L, 0x6002062CL, 0x5629D4B7L, (-1L), 7L, 0xCE8065F4L, 0x683D84E1L, 0x6002062CL}, {0x9EFB1165L, 9L, 0x6002062CL, 0x5629D4B7L, (-1L), 7L, 0xCE8065F4L, 0x683D84E1L, 0x6002062CL}, {0x9EFB1165L, 9L, 0x6002062CL, 0x5629D4B7L, (-1L), 7L, 0xCE8065F4L, 0x683D84E1L, 0x6002062CL}, {0x9EFB1165L, 9L, 0x6002062CL, 0x5629D4B7L, (-1L), 7L, 0xCE8065F4L, 0x683D84E1L, 0x6002062CL}};
                uint32_t l_1945 = 0x696D34E7L;
                int i, j;
                l_1888 &= func_44(p_15, g_652[1].f1, ((void*)0 == &g_485));
                assert (g_712 == 0);
            }
        }
        else
        {
            int32_t l_1956 = 0x073C874FL;
            int32_t l_1960 = 0x85D9CA60L;
            int32_t l_1961 = 0xC53A6CB5L;
            int32_t l_1962 = 1L;
            int32_t l_1963 = 0x12ACE2FDL;
            int32_t l_1964 = (-1L);
            int32_t l_1967[7][3][10] = {{{0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}}, {{0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}}, {{0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}}, {{0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}}, {{0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}}, {{0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}}, {{0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}, {0xD86601E1L, 0x534A2DFFL, 0x899232DEL, 0L, (-8L), (-5L), 1L, 0x08BB041CL, 0xCC53C94FL, 0x52717195L}}};
            int i, j, k;
            for (g_1035 = (-28); (g_1035 > (-7)); ++g_1035)
            {
                uint32_t l_1953 = 0xA3995F67L;
                int32_t l_1954 = 8L;
                int32_t l_1955[6];
                uint16_t l_1976 = 0x1527L;
                int i;
                for (g_771 = 0; (g_771 <= 51); g_771++)
                {
                    int16_t l_1952 = 0xBB03L;
                    int32_t l_1958 = 0xBB92D8DCL;
                    int32_t l_1959 = 6L;
                    int32_t l_1965 = 9L;
                    int32_t l_1966 = 0xED49AA1AL;
                    int32_t l_1968 = 0xBC73BB52L;
                    int32_t l_1969 = 0x11331BE5L;
                    int32_t l_1970 = 0x2C7134CAL;
                    int32_t l_1971 = (-1L);
                    int32_t l_1972 = 8L;
                    int32_t l_1975 = 1L;
                    l_1953 = ((p_15 || g_652[1].f2) , l_1952);
                }
            }
        }
        for (g_744.f2 = 0; (g_744.f2 >= 0); g_744.f2 -= 1)
        {
            int8_t l_1981 = 0x8BL;
            union U0 **l_1994 = &g_596;
            int32_t *l_1997 = (void*)0;
            l_1842 = l_1981;
            if ((4294967295UL || func_56((~func_27((safe_sub_func_uint32_t_u_u(((safe_add_func_int8_t_s_s(p_15, (safe_rshift_func_int16_t_s_s((func_56((safe_unary_minus_func_uint8_t_u(p_15)), (l_1989 == ((g_1628.f1 , ((void*)0 == &g_1328[7])) && ((safe_lshift_func_int8_t_s_s(((safe_div_func_int16_t_s_s((((func_63((((((g_1646[1].f2 , l_1994) == &l_1365) != l_1995) , p_16) , 0x65L), g_158, p_16, p_15, g_1703[3][0][4]) <= p_15) > l_1981) & p_15), g_1035)) ^ 4294967294UL), l_1996)) != p_16)))) & l_1981), 14)))) , 9UL), (-5L))), (*l_1807), p_16, g_1224.f0)), g_1214.f0)))
            {
                for (l_1848 = 0; (l_1848 <= 0); l_1848 += 1)
                {
                    uint32_t l_1998 = 0x4709322AL;
                    if ((*l_1807))
                        break;
                    if (p_16)
                        ;
                    (**l_1833) = l_1997;
                    l_1998 = p_16;
                    for (l_1845 = 0; (l_1845 <= 0); l_1845 += 1)
                    {
                        int i, j, k;
                        if (g_1703[(g_744.f2 + 1)][l_1848][(g_744.f2 + 3)])
                            ;
                        (*l_1771) = (**l_1833);
                        return g_1864[(l_1845 + 5)][l_1845][(l_1848 + 3)];
                    }
                }
                (*l_1994) = (g_1566 , l_1365);
            }
            else
            {
                int32_t l_1999[9][2][5] = {{{0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}, {0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}}, {{0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}, {0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}}, {{0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}, {0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}}, {{0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}, {0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}}, {{0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}, {0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}}, {{0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}, {0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}}, {{0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}, {0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}}, {{0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}, {0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}}, {{0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}, {0x0CEFA9CAL, 0x46C0BA1AL, 8L, 0x0C313562L, 0x6C85D354L}}};
                int i, j, k;
                return l_1999[6][1][3];
            }
            return g_158;
        }
    }
    assert (g_200 == 0 || g_200 == &g_8);
    return p_16;
}
static uint8_t func_19(int8_t p_20, uint16_t p_21, uint32_t p_22, int32_t p_23)
{
    int16_t l_1241[8] = {0x8B1BL, 0xC97BL, 0x8B1BL, 0xC97BL, 0x8B1BL, 0xC97BL, 0x8B1BL, 0xC97BL};
    uint16_t l_1244 = 0xF0D2L;
    int32_t l_1245 = (-10L);
    uint32_t l_1246 = 0x3E883D86L;
    int32_t l_1267[6][9][4] = {{{0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}}, {{0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}}, {{0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}}, {{0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}}, {{0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}}, {{0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}, {0xC9B04A4CL, 0x0675F2A6L, 0x7C497818L, 0x70795A95L}}};
    int32_t l_1274 = 0x9D8B320DL;
    uint16_t l_1278 = 0x623CL;
    uint8_t l_1318 = 0UL;
    int i, j, k;
    for (p_22 = 0; (p_22 <= 21); p_22 = safe_add_func_int16_t_s_s(p_22, 1))
    {
        union U0 *l_1223 = &g_1224;
        uint8_t l_1227 = 0UL;
        int8_t l_1240 = 5L;
        int32_t l_1266 = (-1L);
        int32_t l_1268 = (-9L);
        int32_t l_1270[5];
        int32_t l_1273 = 0L;
        int16_t l_1276[2];
        uint16_t l_1293 = 65534UL;
        int32_t **l_1324 = &g_712;
        int i;
        for (i = 0; i < 5; i++)
            l_1270[i] = 0x8AC28C55L;
        for (g_744.f0 = 0; (g_744.f0 <= 2); g_744.f0 += 1)
        {
            uint16_t l_1220 = 0UL;
            int32_t l_1230 = 8L;
            int32_t *l_1239 = &g_11[2];
            int16_t l_1242 = 0L;
            uint8_t l_1243 = 3UL;
            int32_t l_1249[10] = {0xAE7C2C41L, 0x1795D9E1L, 0xAE7C2C41L, 0x1795D9E1L, 0xAE7C2C41L, 0x1795D9E1L, 0xAE7C2C41L, 0x1795D9E1L, 0xAE7C2C41L, 0x1795D9E1L};
            int32_t l_1258[4][7][6] = {{{0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}}, {{0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}}, {{0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}}, {{0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}, {0xC8F89147L, (-1L), 6L, (-1L), 0x2F5F8C47L, (-3L)}}};
            int16_t l_1277 = 0x24B4L;
            int8_t l_1291 = 0L;
            uint8_t l_1302 = 0UL;
            int i, j, k;
            l_1220 = p_20;
            l_1245 = ((safe_add_func_uint16_t_u_u((((g_778[0] , l_1223) == (void*)0) , ((safe_add_func_uint8_t_u_u((l_1227 , g_339), (safe_add_func_uint32_t_u_u(((l_1230 & (((safe_add_func_uint8_t_u_u((((safe_sub_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(func_56((l_1227 , ((&g_199[2] == (((safe_lshift_func_int16_t_s_u((l_1239 == &l_1230), g_1224.f2)) ^ l_1240) , &g_199[1])) , g_8)), g_155), (*l_1239))) < l_1227), 8L)) , &g_8) == (void*)0), 1L)) , p_22) < 0x6AL)) , l_1227), l_1241[5])))) && l_1242)), l_1243)) && l_1244);
            for (g_400 = 3; (g_400 >= 0); g_400 -= 1)
            {
                int32_t l_1260[2];
                int16_t l_1272[5];
                int8_t l_1275 = 0x98L;
                int8_t l_1289 = 0x1AL;
                int32_t *l_1297 = &g_742.f2;
                uint32_t l_1312 = 0x6994FB2DL;
                int i, j, k;
                for (i = 0; i < 2; i++)
                    l_1260[i] = (-3L);
                for (i = 0; i < 5; i++)
                    ;
                assert (l_1297 == &g_742.f2 || (l_1297 >= &l_1260[0] && l_1297 <= &l_1260[1]));
            }
        }
        for (g_1214.f2 = 0; (g_1214.f2 == 4); ++g_1214.f2)
        {
            int32_t **l_1323 = &g_712;
            (*l_1323) = &l_1245;
            assert (g_712 == &l_1245);
        }
        assert (g_712 == &g_1035);
    }
    return l_1245;
}
static int8_t func_27(uint16_t p_28, int32_t p_29, int32_t p_30, uint32_t p_31)
{
    union U0 *l_1213[9];
    union U0 **l_1215 = &l_1213[2];
    int32_t *l_1216 = &g_114;
    int32_t *l_1217 = &g_652[1].f2;
    int i;
    for (i = 0; i < 9; i++)
        l_1213[i] = &g_1214;
    (*l_1215) = l_1213[5];
    (*l_1216) ^= p_30;
    (*l_1217) ^= (*l_1216);
    return (*l_1217);
}
static int16_t func_32(int16_t p_33, int32_t p_34, uint32_t p_35, uint8_t p_36)
{
    uint16_t l_48 = 0x2A41L;
    int16_t l_1161 = 0x3B11L;
    uint8_t l_1200 = 0x29L;
    int32_t *l_1210 = &g_742.f2;
    if ((((safe_mod_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u((g_11[2] == func_44(l_48, ((safe_div_func_uint32_t_u_u(((~((p_36 < (func_51((safe_lshift_func_int8_t_s_s(g_11[4], func_56(p_34, ((l_48 == (safe_lshift_func_int8_t_s_u((((safe_div_func_uint8_t_u_u(func_63(((safe_div_func_int32_t_s_s((safe_lshift_func_int8_t_s_s((((l_48 != ((-5L) != (safe_add_func_int8_t_s_s(((safe_add_func_uint16_t_u_u((l_48 | 0L), g_11[2])) <= p_35), l_48)))) , 0x33C58D4CL) , l_48), 5)), g_8)) || p_34), g_5, p_34, p_33, l_48), p_36)) || 0xEE08L) == l_48), 7))) | 1UL)))), l_48) <= l_48)) , g_339)) | 65528UL), l_48)) == g_176[7]), l_1161)), 0x91423942L)), 0xB7EDL)) , g_725), 0x7C26L)) , l_1200) || g_8))
    {
        int32_t l_1205 = 0x72C6156BL;
        int32_t l_1211 = 0L;
        l_1211 |= (((safe_add_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((-1L), 13)), l_1205)) & (((safe_rshift_func_uint8_t_u_s(0UL, 1)) >= (((p_35 > ((((safe_lshift_func_int16_t_s_u((p_33 < ((((g_652[1].f2 >= p_34) < g_80) <= 0xD3L) , p_35)), 10)) , (*l_1210)) || l_1205) == l_1205)) >= p_33) , (-1L))) && p_33)) ^ (*l_1210));
    }
    else
    {
        return p_34;
    }
    assert (g_712 == 0);
    return (*l_1210);
}
static uint16_t func_44(uint32_t p_45, uint32_t p_46, uint32_t p_47)
{
    int32_t **l_1162 = (void*)0;
    int32_t **l_1163 = (void*)0;
    int32_t **l_1164 = &g_712;
    int32_t *l_1165 = (void*)0;
    int32_t l_1166 = 0L;
    uint32_t l_1189[5][1][9] = {{{0UL, 0x58B35299L, 0UL, 0xC9A23F6DL, 18446744073709551614UL, 0x6A8E8682L, 0x351213CBL, 0x351213CBL, 0x6A8E8682L}}, {{0UL, 0x58B35299L, 0UL, 0xC9A23F6DL, 18446744073709551614UL, 0x6A8E8682L, 0x351213CBL, 0x351213CBL, 0x6A8E8682L}}, {{0UL, 0x58B35299L, 0UL, 0xC9A23F6DL, 18446744073709551614UL, 0x6A8E8682L, 0x351213CBL, 0x351213CBL, 0x6A8E8682L}}, {{0UL, 0x58B35299L, 0UL, 0xC9A23F6DL, 18446744073709551614UL, 0x6A8E8682L, 0x351213CBL, 0x351213CBL, 0x6A8E8682L}}, {{0UL, 0x58B35299L, 0UL, 0xC9A23F6DL, 18446744073709551614UL, 0x6A8E8682L, 0x351213CBL, 0x351213CBL, 0x6A8E8682L}}};
    int i, j, k;
    assert (g_712 == 0);
    l_1166 = p_46;
    for (g_538.f0 = 16; (g_538.f0 > 22); g_538.f0++)
    {
        uint32_t l_1173 = 0x9B8FAF7EL;
        int32_t *l_1180 = &g_8;
        int32_t *l_1181 = (void*)0;
        int32_t *l_1182 = &g_155;
        (*l_1182) = (safe_div_func_uint16_t_u_u((~func_63((safe_mod_func_uint8_t_u_u(g_158, l_1173)), (~l_1173), p_47, (((safe_sub_func_uint8_t_u_u(g_176[7], (((65535UL == (((func_63((safe_mod_func_int8_t_s_s(0xF1L, g_100[0][0])), g_8, p_46, g_339, l_1173) , p_45) != g_5) > 0x4C291DCDL)) , 0UL) , l_1173))) , l_1180) == l_1180), g_771)), 0x0990L));
    }
    for (g_538.f0 = 0; (g_538.f0 == 29); g_538.f0 = safe_add_func_int16_t_s_s(g_538.f0, 1))
    {
        int32_t l_1185[5] = {(-1L), (-1L), (-1L), (-1L), (-1L)};
        int32_t *l_1186 = &l_1185[0];
        int32_t *l_1187 = &g_652[1].f2;
        int32_t *l_1188 = (void*)0;
        union U0 **l_1198 = (void*)0;
        int32_t ***l_1199 = &l_1163;
        int i;
        l_1189[3][0][4]--;
        (*l_1187) |= p_45;
    }
    return g_742.f2;
}
static uint32_t func_51(int32_t p_52, int32_t p_53)
{
    uint32_t l_729 = 18446744073709551612UL;
    int32_t l_732 = 1L;
    union U0 *l_743 = &g_744;
    int32_t *l_805 = &g_400;
    int32_t l_836 = (-7L);
    uint32_t l_840 = 0UL;
    int16_t l_858[1][7][3] = {{{(-4L), (-4L), 0xD183L}, {(-4L), (-4L), 0xD183L}, {(-4L), (-4L), 0xD183L}, {(-4L), (-4L), 0xD183L}, {(-4L), (-4L), 0xD183L}, {(-4L), (-4L), 0xD183L}, {(-4L), (-4L), 0xD183L}}};
    int32_t *l_871[2];
    uint32_t l_887 = 4294967295UL;
    uint8_t l_900 = 0x56L;
    uint8_t l_1150 = 246UL;
    uint32_t l_1158 = 4294967293UL;
    int i, j, k;
    for (i = 0; i < 2; i++)
        ;
    for (g_155 = 1; (g_155 <= (-17)); g_155--)
    {
        int32_t **l_733 = (void*)0;
        int32_t **l_734[1][1][10] = {{{&g_712, &g_712, &g_712, &g_712, &g_712, &g_712, &g_712, &g_712, &g_712, &g_712}}};
        union U0 *l_741 = &g_742;
        int32_t **l_764 = (void*)0;
        int i, j, k;
        l_732 = (l_729 != (safe_add_func_int8_t_s_s(p_52, 0UL)));
        assert (g_712 == &l_732);
        if ((l_732 , (safe_lshift_func_int16_t_s_s((safe_add_func_uint16_t_u_u(((1L || g_100[0][0]) > (!func_63(p_52, g_5, (((safe_rshift_func_uint16_t_u_u(((((((((((g_11[0] > ((((g_155 || ((l_732 || ((0x45B3L == g_114) != g_187)) & g_339)) > 0x2EBDL) && g_176[4]) != p_53)) <= 0UL) , 0x4F65L) <= 0xC413L) , l_741) != l_743) , p_53) > g_172) < 0xA283L) , 65535UL), p_53)) | 0x6CF60C06L) >= l_729), l_729, g_112[4]))), 0x4BB1L)), 0))))
        {
            uint16_t l_747 = 65535UL;
            for (g_744.f2 = 0; (g_744.f2 < 14); g_744.f2++)
            {
                for (g_339 = 0; (g_339 <= 8); g_339 += 1)
                {
                    uint16_t l_748 = 3UL;
                    if (p_53)
                        break;
                    l_747 &= 1L;
                    l_748--;
                }
                return g_339;
            }
            if (p_53)
                ;
            for (g_744.f2 = 0; (g_744.f2 <= 0); g_744.f2 += 1)
            {
                uint32_t l_758[1][2];
                int32_t l_761 = 0xD78B5A6CL;
                int8_t l_762 = 0xBEL;
                int i, j;
                for (i = 0; i < 1; i++)
                {
                    for (j = 0; j < 2; j++)
                        ;
                }
                for (g_742.f0 = 0; (g_742.f0 <= 0); g_742.f0 += 1)
                {
                    int32_t l_757 = (-1L);
                    int i, j, k;
                    p_53 ^= p_52;
                }
                if (l_762)
                    ;
            }
        }
        else
        {
            uint32_t l_763 = 4UL;
            uint32_t l_772 = 4294967295UL;
            int32_t *l_773 = &g_5;
            union U0 **l_779 = &l_741;
            uint32_t l_781 = 1UL;
            l_763 = (*g_712);
            if ((((&g_5 == &p_53) || ((-2L) | ((l_764 == (void*)0) != (((func_91(&p_53, (safe_lshift_func_uint16_t_u_s((safe_lshift_func_uint16_t_u_s((safe_div_func_int8_t_s_s((((g_771 , l_729) ^ p_52) | p_52), g_187)), l_772)), 15)), &g_80) , &l_732) != l_773) >= 0xEEB1L)))) | 7L))
            {
                for (g_518 = (-20); (g_518 != 37); g_518 = safe_add_func_uint32_t_u_u(g_518, 9))
                {
                    for (l_732 = 7; (l_732 == 7); l_732++)
                    {
                        union U0 ***l_780 = &l_779;
                        g_778[0] = p_53;
                    }
                    p_53 = p_52;
                }
            }
            else
            {
                l_781--;
                return p_53;
            }
        }
    }
    assert (g_712 == &l_732 || g_712 == &g_172 || g_712 == &g_538.f2 || g_712 == 0 || g_712 == &g_1035);
    assert ((g_712 >= &g_11[0] && g_712 <= &g_11[7]) || g_712 == &l_732 || g_712 == &g_172 || g_712 == &g_538.f2 || g_712 == 0 || g_712 == &g_5 || g_712 == &p_53 || g_712 == &g_1035);
    return g_778[1];
}
static int8_t func_56(uint32_t p_57, uint32_t p_58)
{
    int32_t *l_87 = (void*)0;
    int32_t l_88 = 6L;
    int32_t l_218 = 0xD438A0F6L;
    uint32_t l_219 = 4294967295UL;
    int16_t l_265 = 0x9FEDL;
    int16_t l_272 = 0L;
    int8_t l_286 = 0x1EL;
    int32_t l_305 = (-6L);
    int32_t l_306 = 0xF9EFFBC4L;
    int32_t l_327 = 0x725184AEL;
    int32_t l_328[3][2] = {{0x17EB9657L, 0x17EB9657L}, {0x17EB9657L, 0x17EB9657L}, {0x17EB9657L, 0x17EB9657L}};
    int8_t l_333[1];
    int32_t **l_361 = (void*)0;
    int32_t ***l_360 = &l_361;
    uint8_t l_386 = 8UL;
    int16_t l_410 = (-1L);
    uint16_t l_449 = 1UL;
    int32_t l_454 = 1L;
    uint32_t l_550 = 0x663547C6L;
    union U0 *l_651 = &g_652[1];
    union U0 **l_653 = &l_651;
    int i, j;
    for (i = 0; i < 1; i++)
        l_333[i] = 2L;
    if ((p_57 ^ ((((safe_sub_func_int32_t_s_s(func_91((((safe_mod_func_uint8_t_u_u(p_58, (p_58 || (p_58 , (0xB4L & (((safe_sub_func_uint32_t_u_u((g_80 , 0x3C451EDCL), (g_8 && p_57))) , g_5) , p_57)))))) >= p_58) , (void*)0), p_58, &g_11[2]), l_88)) , &g_5) != &l_88) != p_57)))
    {
        int32_t **l_213 = &l_87;
        int32_t *l_214 = &g_155;
        int32_t *l_215 = (void*)0;
        int32_t *l_216 = &g_155;
        int32_t *l_217 = &g_155;
        assert (l_87 == &l_88);
        l_219++;
    }
    else
    {
        int8_t l_224[7][3] = {{0x93L, 1L, 0L}, {0x93L, 1L, 0L}, {0x93L, 1L, 0L}, {0x93L, 1L, 0L}, {0x93L, 1L, 0L}, {0x93L, 1L, 0L}, {0x93L, 1L, 0L}};
        int32_t *l_238 = &g_80;
        uint32_t l_271[6][2] = {{0xDFA7AC64L, 3UL}, {0xDFA7AC64L, 3UL}, {0xDFA7AC64L, 3UL}, {0xDFA7AC64L, 3UL}, {0xDFA7AC64L, 3UL}, {0xDFA7AC64L, 3UL}};
        int32_t l_291[6] = {0x9CD995C9L, 0x9CD995C9L, 0L, 0x9CD995C9L, 0x9CD995C9L, 0L};
        uint32_t l_293 = 4294967288UL;
        int32_t l_326 = 0L;
        uint8_t l_336 = 1UL;
        int32_t ***l_395 = &l_361;
        uint16_t l_483 = 0x46DEL;
        uint16_t l_529 = 0x8D1BL;
        int16_t l_549 = 0x8BEBL;
        int32_t l_610 = 0x5D763FB9L;
        int i, j;
        if (((safe_div_func_int32_t_s_s(((l_224[5][1] ^ p_58) , (((safe_lshift_func_int16_t_s_u(func_91(&l_88, ((safe_add_func_uint32_t_u_u(((((safe_lshift_func_uint16_t_u_u(g_5, 2)) > 4294967287UL) >= (safe_div_func_uint16_t_u_u(0xB2F8L, (safe_div_func_int8_t_s_s(g_80, g_172))))) , (0L != g_189)), p_58)) == g_80), &l_88), p_57)) == g_112[4]) == 0x084CL)), p_58)) , l_224[5][1]))
        {
            int16_t l_237 = 1L;
            int32_t l_249 = 0xE4C70D5BL;
            int32_t l_303 = 1L;
            int32_t l_304 = 5L;
            int32_t l_307 = (-9L);
            uint32_t l_309[5] = {0UL, 0UL, 0UL, 0UL, 0UL};
            int32_t *l_312 = &l_306;
            int32_t l_329 = 0xDAAA1835L;
            int32_t l_331 = 0L;
            int32_t l_334[8] = {7L, 0L, 7L, 0L, 7L, 0L, 7L, 0L};
            int8_t l_335 = (-6L);
            uint16_t l_378[5] = {0UL, 65535UL, 0UL, 65535UL, 0UL};
            int32_t *l_401 = &g_11[2];
            int32_t ***l_402 = (void*)0;
            uint8_t l_437[5][5] = {{252UL, 0UL, 0x9EL, 0UL, 252UL}, {252UL, 0UL, 0x9EL, 0UL, 252UL}, {252UL, 0UL, 0x9EL, 0UL, 252UL}, {252UL, 0UL, 0x9EL, 0UL, 252UL}, {252UL, 0UL, 0x9EL, 0UL, 252UL}};
            int8_t l_459[9];
            int i, j;
            for (i = 0; i < 9; i++)
                ;
            if ((safe_mod_func_uint16_t_u_u((l_237 <= ((((l_224[0][2] > g_145) , ((((((void*)0 == l_238) == (safe_lshift_func_int8_t_s_s((l_237 , g_158), (((safe_rshift_func_uint16_t_u_s(g_155, (safe_lshift_func_int8_t_s_u((safe_mod_func_uint32_t_u_u((safe_add_func_int32_t_s_s((p_57 < p_57), (-8L))), (*l_238))), 0)))) , p_58) , g_189)))) ^ g_145) & g_114) && (*l_238))) , g_145) & g_11[2])), l_249)))
            {
                int8_t l_260 = 0xF6L;
                int32_t l_270 = 1L;
                int32_t l_287 = 1L;
                int32_t l_308 = 0L;
                for (g_189 = 0; (g_189 <= 4); g_189 += 1)
                {
                    int32_t *l_254 = &g_11[2];
                    if (((safe_mod_func_int8_t_s_s(g_11[2], (safe_rshift_func_uint16_t_u_u(((l_254 == &g_80) <= func_63(g_112[4], (p_57 , p_57), g_114, (safe_mod_func_uint16_t_u_u(((safe_mod_func_int16_t_s_s(((func_63(g_100[0][1], g_100[0][1], (*l_254), p_58, g_186[0][6][0]) , g_145) == 0xBF8AL), g_145)) && p_57), g_187)), g_5)), g_112[0])))) , (*l_238)))
                    {
                        int32_t **l_259 = &l_238;
                        (*l_259) = &l_218;
                        assert (l_238 == &l_218);
                    }
                    else
                    {
                        return l_260;
                    }
                    assert (l_238 == &l_218);
                    return p_57;
                }
                if ((safe_mod_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(g_155, (func_91(&g_114, g_189, &l_218) & g_11[2]))) & (l_265 != (g_8 && ((safe_div_func_uint8_t_u_u(((((((safe_rshift_func_int16_t_s_u(l_270, p_58)) & l_270) , 0x95L) >= 0x9CL) != l_271[5][0]) && p_57), l_237)) != l_272)))), p_58)))
                {
                    return p_58;
                }
                else
                {
                    int32_t *l_284 = &g_172;
                    int32_t l_285 = 0x9D2F2F3AL;
                    int32_t l_290 = 0x9F1C9D62L;
                    l_287 &= func_63(((((safe_mod_func_int32_t_s_s(l_249, (safe_lshift_func_int8_t_s_s(((safe_add_func_uint16_t_u_u(((g_176[7] >= p_57) > 0x84L), (safe_unary_minus_func_int16_t_s((1L == 1L))))) > 0L), (safe_lshift_func_int8_t_s_s((~(safe_rshift_func_int16_t_s_u(((func_63(p_58, (&g_114 != l_284), g_114, p_57, p_57) , 4UL) | g_155), 2))), 7)))))) , p_57) && l_285) <= 0x3A026879L), p_58, p_58, p_58, l_286);
                    (*l_238) ^= p_58;
                }
                assert ((l_312 >= &l_291[0] && l_312 <= &l_291[5]) || l_312 == &l_306);
            }
            else
            {
                int32_t *l_315 = (void*)0;
                int32_t **l_316 = &l_315;
                int32_t l_324 = 1L;
                int32_t l_330 = 0x666A5D62L;
                int32_t l_332[2];
                int i;
                for (i = 0; i < 2; i++)
                    l_332[i] = 0xC56E4C11L;
                for (l_305 = (-7); (l_305 >= 7); l_305 = safe_add_func_int8_t_s_s(l_305, 8))
                {
                    int8_t l_323[2];
                    int32_t l_325[1][2];
                    int32_t *l_354[9] = {&l_249, &l_332[1], &l_249, &l_332[1], &l_249, &l_332[1], &l_249, &l_332[1], &l_249};
                    int i, j;
                    for (i = 0; i < 2; i++)
                        ;
                    for (i = 0; i < 1; i++)
                    {
                        for (j = 0; j < 2; j++)
                            l_325[i][j] = 0x0E1AF0F9L;
                    }
                    for (g_189 = 0; (g_189 != 9); g_189++)
                    {
                        int32_t *l_321[6][2] = {{&g_5, (void*)0}, {&g_5, (void*)0}, {&g_5, (void*)0}, {&g_5, (void*)0}, {&g_5, (void*)0}, {&g_5, (void*)0}};
                        int i, j;
                        l_336++;
                    }
                    l_334[3] ^= (func_91(&l_334[5], p_58, &l_329) , (0xBBE3L | (safe_div_func_uint32_t_u_u(1UL, (safe_add_func_int32_t_s_s((safe_div_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s((((!(((safe_rshift_func_uint8_t_u_u((0UL < 0x8371L), (safe_mod_func_int32_t_s_s((safe_rshift_func_int16_t_s_s(g_176[4], 11)), 3UL)))) ^ (*l_238)) >= p_58)) <= 0xA7L) && 0x7EECL), (*l_312))), g_11[2])), 0x7184DA73L))))));
                }
                assert ((l_315 >= &l_291[0] && l_315 <= &l_291[5]));
            }
            assert ((l_312 >= &l_291[0] && l_312 <= &l_291[5]) || l_312 == &l_306);
            for (l_327 = 1; (l_327 <= 4); l_327 += 1)
            {
                int32_t l_373[4][6] = {{0xFBE7C8B4L, 0x43AE6555L, 0x86C95569L, 0x43AE6555L, 0xFBE7C8B4L, 0xF8F39D72L}, {0xFBE7C8B4L, 0x43AE6555L, 0x86C95569L, 0x43AE6555L, 0xFBE7C8B4L, 0xF8F39D72L}, {0xFBE7C8B4L, 0x43AE6555L, 0x86C95569L, 0x43AE6555L, 0xFBE7C8B4L, 0xF8F39D72L}, {0xFBE7C8B4L, 0x43AE6555L, 0x86C95569L, 0x43AE6555L, 0xFBE7C8B4L, 0xF8F39D72L}};
                int32_t **l_383[2];
                int i, j;
                for (i = 0; i < 2; i++)
                    l_383[i] = &l_238;
                if (l_309[l_327])
                {
                    int32_t *l_357 = &l_334[2];
                    for (l_249 = 0; (l_249 >= 16); l_249++)
                    {
                        assert ((l_238 >= &l_334[0] && l_238 <= &l_334[7]));
                    }
                    assert ((l_238 >= &l_334[0] && l_238 <= &l_334[7]) || l_238 == &g_80);
                    for (l_303 = (-6); (l_303 < 0); l_303 = safe_add_func_int16_t_s_s(l_303, 4))
                    {
                        (*l_238) = (~((void*)0 != l_360));
                        if (p_58)
                            break;
                    }
                    return p_57;
                }
                else
                {
                    int32_t l_372 = (-1L);
                    int32_t l_374 = 6L;
                    int32_t l_375 = 0xAB106587L;
                    int32_t l_376 = (-1L);
                    int32_t l_377[2];
                    int i;
                    for (l_219 = 0; (l_219 > 50); l_219 = safe_add_func_uint16_t_u_u(l_219, 8))
                    {
                        int32_t **l_364[7] = {&l_312, &l_312, &l_238, &l_312, &l_312, &l_238, &l_312};
                        int i;
                    }
                    (*l_238) = (safe_lshift_func_int16_t_s_s(8L, p_58));
                    if ((l_383[0] == g_199[2]))
                    {
                        int16_t l_384 = 0x7E6BL;
                        int32_t l_385 = (-3L);
                        (*l_238) |= p_57;
                        --l_386;
                        return g_155;
                    }
                    else
                    {
                        uint32_t l_396[10] = {18446744073709551615UL, 1UL, 18446744073709551615UL, 1UL, 18446744073709551615UL, 1UL, 18446744073709551615UL, 1UL, 18446744073709551615UL, 1UL};
                        int32_t *l_397 = &l_303;
                        int i;
                        if ((*l_238))
                            ;
                        l_397 = (((safe_rshift_func_int16_t_s_u((g_11[0] ^ ((safe_mod_func_uint32_t_u_u(g_176[3], func_63(((safe_rshift_func_uint8_t_u_u(0x25L, p_58)) , (l_396[2] == p_57)), g_155, p_57, (*l_238), l_374))) || 0L)), 8)) && 0x03L) , (void*)0);
                        assert (l_397 == 0);
                    }
                }
            }
        }
        else
        {
            int32_t **l_489 = &l_238;
            int32_t l_499 = 0x1A11C084L;
            uint32_t l_502 = 0x544E36F7L;
            uint8_t l_519 = 5UL;
            int32_t l_545[2][1];
            int8_t l_569 = 0x39L;
            uint32_t l_611 = 1UL;
            int i, j;
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 1; j++)
                    l_545[i][j] = (-8L);
            }
            (*l_489) = &g_114;
            assert (l_238 == &g_114);
            assert (l_238 == &g_400 || l_238 == &g_114);
            for (l_305 = 0; (l_305 <= 5); l_305 += 1)
            {
                int i;
                assert ((l_238 >= &l_291[0] && l_238 <= &l_291[5]));
                return p_57;
            }
        }
        assert (l_238 == &g_400 || l_238 == &g_114 || l_238 == &g_80);
    }
    assert (l_87 == 0 || l_87 == &l_88);
    for (g_155 = 0; (g_155 == 16); ++g_155)
    {
        int32_t ***l_658 = &l_361;
        int32_t *l_659 = &g_172;
        union U0 **l_660 = (void*)0;
        int32_t l_662 = (-1L);
        int32_t l_667 = 1L;
        int32_t l_669 = (-1L);
        int32_t l_670 = 0xE665230BL;
        int32_t l_671[3][8] = {{0x13767CC7L, 1L, 0x13767CC7L, 0xAF1DF6ADL, 0x6B204A71L, 0x5F672321L, (-6L), (-6L)}, {0x13767CC7L, 1L, 0x13767CC7L, 0xAF1DF6ADL, 0x6B204A71L, 0x5F672321L, (-6L), (-6L)}, {0x13767CC7L, 1L, 0x13767CC7L, 0xAF1DF6ADL, 0x6B204A71L, 0x5F672321L, (-6L), (-6L)}};
        uint16_t l_695 = 1UL;
        int i, j;
        if (func_63(g_158, p_57, p_57, (safe_sub_func_int16_t_s_s((safe_lshift_func_int16_t_s_u((((*l_360) != &g_712) ^ (safe_mod_func_uint8_t_u_u(g_114, p_58))), 14)), ((((p_57 | (safe_sub_func_int16_t_s_s(g_538.f2, p_57))) <= 0xEDL) || p_58) == 0L))), g_112[1]))
        {
            for (l_695 = (-29); (l_695 == 42); l_695 = safe_add_func_uint8_t_u_u(l_695, 7))
            {
                int32_t *l_726 = &l_306;
                l_726 = l_726;
            }
            if (p_58)
                ;
        }
        else
        {
            (*l_659) = 0x4C783421L;
            assert (g_712 == &g_172);
        }
    }
    assert (l_87 == 0 || l_87 == &l_88 || l_87 == &g_538.f2);
    return g_8;
}
static uint8_t func_63(int8_t p_64, int32_t p_65, uint16_t p_66, uint16_t p_67, uint8_t p_68)
{
    int32_t *l_79 = &g_80;
    int32_t l_81 = 0L;
    int32_t *l_82 = &l_81;
    int32_t *l_83[5][3][6] = {{{&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}, {&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}, {&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}}, {{&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}, {&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}, {&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}}, {{&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}, {&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}, {&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}}, {{&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}, {&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}, {&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}}, {{&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}, {&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}, {&g_11[2], &g_8, &g_5, &g_5, (void*)0, &g_5}}};
    uint8_t l_84 = 0x2FL;
    int i, j, k;
    --l_84;
    return p_65;
}
static int32_t func_91(int32_t * p_92, int8_t p_93, int32_t * p_94)
{
    int8_t l_99 = 1L;
    int32_t *l_117 = &g_5;
    uint16_t l_134 = 65535UL;
    int32_t l_153 = (-1L);
    int32_t *l_194 = (void*)0;
    uint32_t l_212[2][7] = {{1UL, 0x9BF6C6B0L, 1UL, 0x9BF6C6B0L, 1UL, 0x9BF6C6B0L, 1UL}, {1UL, 0x9BF6C6B0L, 1UL, 0x9BF6C6B0L, 1UL, 0x9BF6C6B0L, 1UL}};
    int i, j;
    l_99 = (*p_94);
    for (l_99 = 0; (l_99 <= 0); l_99 += 1)
    {
        int32_t *l_107 = &g_80;
        int32_t *l_113 = &g_114;
        int32_t l_152[8] = {0xDE25C1C2L, 0x953674B7L, 0xDE25C1C2L, 0x953674B7L, 0xDE25C1C2L, 0x953674B7L, 0xDE25C1C2L, 0x953674B7L};
        int i;
        (*l_113) |= func_63(((safe_mod_func_int16_t_s_s(p_93, ((safe_lshift_func_uint8_t_u_s(func_63(((safe_mod_func_int32_t_s_s((l_107 != ((g_11[2] && ((safe_lshift_func_uint16_t_u_s(l_99, 0)) | (*p_94))) , &g_11[2])), (safe_lshift_func_uint16_t_u_u(func_63(g_11[4], l_99, (1L && g_5), l_99, p_93), l_99)))) , (-3L)), g_8, p_93, p_93, p_93), g_112[4])) , (*l_107)))) ^ (-4L)), l_99, (*l_107), p_93, (*l_107));
        if ((p_93 & (p_93 ^ (safe_lshift_func_int16_t_s_u(func_63(p_93, p_93, (((p_93 , p_92) == l_117) , (safe_rshift_func_uint16_t_u_s(((safe_rshift_func_int16_t_s_s(g_8, 3)) , (safe_rshift_func_int16_t_s_s(func_63(g_5, g_8, p_93, p_93, p_93), g_80))), p_93))), g_80, g_112[2]), 13)))))
        {
            int32_t **l_128[6] = {&l_117, &l_117, &l_113, &l_117, &l_117, &l_113};
            int32_t **l_133 = &l_113;
            uint16_t l_135 = 1UL;
            int i;
            (*l_107) ^= (safe_lshift_func_uint16_t_u_s((safe_add_func_int32_t_s_s(0x0442C135L, (*l_117))), 10));
            if (g_11[0])
                break;
            assert (p_92 == &g_80);
            if ((g_8 <= ((safe_mod_func_int16_t_s_s((8UL != ((safe_rshift_func_uint8_t_u_u((0xCBL ^ (&p_94 != (p_93 , l_133))), (*l_117))) , ((~(l_134 || func_63((l_135 , g_11[0]), (*l_117), p_93, p_93, g_5))) != (-10L)))), 65535UL)) != (*l_107))))
            {
                int32_t l_146[6] = {(-6L), (-6L), 1L, (-6L), (-6L), 1L};
                int32_t l_154 = (-3L);
                int32_t l_156 = (-10L);
                int32_t **l_166 = (void*)0;
                int i;
                assert (l_113 == &g_8);
                for (g_114 = 0; (g_114 >= 0); g_114 -= 1)
                {
                    int32_t l_157 = 8L;
                    int i, j;
                    if (g_100[l_99][g_114])
                        ;
                    for (l_135 = 0; (l_135 <= 0); l_135 += 1)
                    {
                        int i, j;
                        (*p_92) |= (g_100[l_135][(l_99 + 1)] , (safe_rshift_func_uint8_t_u_s(g_8, 3)));
                        assert (l_117 == 0);
                        return (*l_113);
                    }
                    if ((g_100[0][0] == g_100[l_99][g_114]))
                    {
                        uint8_t l_138 = 0xEAL;
                        g_80 = ((~p_93) >= (((g_11[3] == l_138) | g_114) , ((g_100[0][1] <= g_11[1]) , (4294967286UL | (safe_sub_func_uint32_t_u_u((safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(65528UL, 6)), (l_117 == (void*)0))), g_145))))));
                        assert (l_113 == &g_80);
                        return l_146[4];
                    }
                    else
                    {
                        uint8_t l_151[1][9] = {{255UL, 2UL, 255UL, 2UL, 255UL, 2UL, 255UL, 2UL, 255UL}};
                        int i, j;
                        (*l_107) = ((safe_div_func_int16_t_s_s(p_93, ((safe_rshift_func_uint8_t_u_s((g_100[0][0] < func_63(l_151[0][1], func_63(p_93, p_93, (((g_100[0][0] || g_80) ^ ((g_5 ^ p_93) >= (*l_107))) > (*l_117)), g_145, g_11[2]), g_100[0][1], p_93, p_93)), 3)) , g_5))) | g_11[7]);
                        if ((*l_113))
                            break;
                        (*l_107) = g_114;
                        g_158++;
                    }
                }
                if ((*p_94))
                    continue;
            }
            else
            {
                uint8_t l_181[2];
                int i;
                for (i = 0; i < 2; i++)
                    l_181[i] = 0x94L;
                p_94 = (g_11[2] , (*l_133));
                assert (p_94 == &g_114);
            }
            assert (l_113 == &g_114 || l_113 == &g_8);
        }
        else
        {
            int8_t l_211 = 4L;
            for (p_93 = 0; (p_93 <= 0); p_93 += 1)
            {
                int32_t *l_184 = &g_172;
                int32_t *l_185[2][8][5] = {{{(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}}, {{(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}, {(void*)0, &g_114, &l_152[3], (void*)0, &g_11[5]}}};
                int16_t l_188 = 0x9444L;
                int i, j, k;
                g_189--;
                for (g_145 = 0; (g_145 <= 7); g_145 += 1)
                {
                    int i, j, k;
                    assert (p_92 == &g_155 || p_92 == &g_5 || (p_92 >= &g_11[0] && p_92 <= &g_11[7]) || p_92 == &g_114 || p_92 == 0 || (p_92 >= &l_152[0] && p_92 <= &l_152[7]) || p_92 == &g_172);
                }
            }
        }
        assert (l_113 == &g_114 || l_113 == &g_8);
        return (*l_107);
    }
    return (*p_94);
}
int main (void)
{
    int i, j, k;
    int print_hash_value = 0;
    platform_main_begin();
    crc32_gentab();
    func_1();
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_3, "g_3", print_hash_value);
    transparent_crc(g_4, "g_4", print_hash_value);
    transparent_crc(g_5, "g_5", print_hash_value);
    transparent_crc(g_8, "g_8", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_11[i], "g_11[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_80, "g_80", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 2; j++)
        {
            transparent_crc(g_100[i][j], "g_100[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    for (i = 0; i < 5; i++)
    {
        transparent_crc(g_112[i], "g_112[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_114, "g_114", print_hash_value);
    transparent_crc(g_145, "g_145", print_hash_value);
    transparent_crc(g_155, "g_155", print_hash_value);
    transparent_crc(g_158, "g_158", print_hash_value);
    transparent_crc(g_172, "g_172", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_176[i], "g_176[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 8; j++)
        {
            for (k = 0; k < 5; k++)
            {
                transparent_crc(g_186[i][j][k], "g_186[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    transparent_crc(g_187, "g_187", print_hash_value);
    transparent_crc(g_189, "g_189", print_hash_value);
    transparent_crc(g_322, "g_322", print_hash_value);
    transparent_crc(g_339, "g_339", print_hash_value);
    transparent_crc(g_400, "g_400", print_hash_value);
    transparent_crc(g_486, "g_486", print_hash_value);
    transparent_crc(g_518, "g_518", print_hash_value);
    transparent_crc(g_538.f0, "g_538.f0", print_hash_value);
    transparent_crc(g_538.f1, "g_538.f1", print_hash_value);
    transparent_crc(g_538.f2, "g_538.f2", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_652[i].f0, "g_652[i].f0", print_hash_value);
        transparent_crc(g_652[i].f1, "g_652[i].f1", print_hash_value);
        transparent_crc(g_652[i].f2, "g_652[i].f2", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_725, "g_725", print_hash_value);
    transparent_crc(g_742.f0, "g_742.f0", print_hash_value);
    transparent_crc(g_742.f1, "g_742.f1", print_hash_value);
    transparent_crc(g_742.f2, "g_742.f2", print_hash_value);
    transparent_crc(g_744.f0, "g_744.f0", print_hash_value);
    transparent_crc(g_744.f1, "g_744.f1", print_hash_value);
    transparent_crc(g_744.f2, "g_744.f2", print_hash_value);
    transparent_crc(g_771, "g_771", print_hash_value);
    for (i = 0; i < 7; i++)
    {
        transparent_crc(g_778[i], "g_778[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_1022.f0, "g_1022.f0", print_hash_value);
    transparent_crc(g_1022.f1, "g_1022.f1", print_hash_value);
    transparent_crc(g_1022.f2, "g_1022.f2", print_hash_value);
    transparent_crc(g_1035, "g_1035", print_hash_value);
    transparent_crc(g_1151, "g_1151", print_hash_value);
    transparent_crc(g_1214.f0, "g_1214.f0", print_hash_value);
    transparent_crc(g_1214.f1, "g_1214.f1", print_hash_value);
    transparent_crc(g_1214.f2, "g_1214.f2", print_hash_value);
    transparent_crc(g_1224.f0, "g_1224.f0", print_hash_value);
    transparent_crc(g_1224.f1, "g_1224.f1", print_hash_value);
    transparent_crc(g_1224.f2, "g_1224.f2", print_hash_value);
    transparent_crc(g_1271, "g_1271", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        transparent_crc(g_1288[i], "g_1288[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_1290, "g_1290", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_1340[i], "g_1340[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_1371.f0, "g_1371.f0", print_hash_value);
    transparent_crc(g_1371.f1, "g_1371.f1", print_hash_value);
    transparent_crc(g_1371.f2, "g_1371.f2", print_hash_value);
    transparent_crc(g_1372.f0, "g_1372.f0", print_hash_value);
    transparent_crc(g_1372.f1, "g_1372.f1", print_hash_value);
    transparent_crc(g_1372.f2, "g_1372.f2", print_hash_value);
    transparent_crc(g_1399.f0, "g_1399.f0", print_hash_value);
    transparent_crc(g_1399.f1, "g_1399.f1", print_hash_value);
    transparent_crc(g_1399.f2, "g_1399.f2", print_hash_value);
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 9; j++)
        {
            transparent_crc(g_1444[i][j].f0, "g_1444[i][j].f0", print_hash_value);
            transparent_crc(g_1444[i][j].f1, "g_1444[i][j].f1", print_hash_value);
            transparent_crc(g_1444[i][j].f2, "g_1444[i][j].f2", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    transparent_crc(g_1566, "g_1566", print_hash_value);
    transparent_crc(g_1591, "g_1591", print_hash_value);
    transparent_crc(g_1622, "g_1622", print_hash_value);
    transparent_crc(g_1628.f0, "g_1628.f0", print_hash_value);
    transparent_crc(g_1628.f1, "g_1628.f1", print_hash_value);
    transparent_crc(g_1628.f2, "g_1628.f2", print_hash_value);
    for (i = 0; i < 7; i++)
    {
        transparent_crc(g_1646[i].f0, "g_1646[i].f0", print_hash_value);
        transparent_crc(g_1646[i].f1, "g_1646[i].f1", print_hash_value);
        transparent_crc(g_1646[i].f2, "g_1646[i].f2", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_1653.f0, "g_1653.f0", print_hash_value);
    transparent_crc(g_1653.f1, "g_1653.f1", print_hash_value);
    transparent_crc(g_1653.f2, "g_1653.f2", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 1; j++)
        {
            for (k = 0; k < 6; k++)
            {
                transparent_crc(g_1703[i][j][k], "g_1703[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    transparent_crc(g_1731, "g_1731", print_hash_value);
    transparent_crc(g_1767.f0, "g_1767.f0", print_hash_value);
    transparent_crc(g_1767.f1, "g_1767.f1", print_hash_value);
    transparent_crc(g_1767.f2, "g_1767.f2", print_hash_value);
    transparent_crc(g_1806.f0, "g_1806.f0", print_hash_value);
    transparent_crc(g_1806.f1, "g_1806.f1", print_hash_value);
    transparent_crc(g_1806.f2, "g_1806.f2", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 1; k++)
            {
                transparent_crc(g_1814[i][j][k].f0, "g_1814[i][j][k].f0", print_hash_value);
                transparent_crc(g_1814[i][j][k].f1, "g_1814[i][j][k].f1", print_hash_value);
                transparent_crc(g_1814[i][j][k].f2, "g_1814[i][j][k].f2", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 8; j++)
        {
            for (k = 0; k < 4; k++)
            {
                transparent_crc(g_1864[i][j][k], "g_1864[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    transparent_crc(g_1882, "g_1882", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

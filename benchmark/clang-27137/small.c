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
platform_main_end(uint32_t crc, int flag)
{





 printf ("checksum = %X\n", crc);
}
static int8_t
(safe_unary_minus_func_int8_t_s)(int8_t si )
{

  return






    -si;
}

static int8_t
(safe_add_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return






    (si1 + si2);
}

static int8_t
(safe_sub_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return






    (si1 - si2);
}

static int8_t
(safe_mul_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return






    si1 * si2;
}

static int8_t
(safe_mod_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return

    ((si2 == 0) || ((si1 == (-128)) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 % si2);
}

static int8_t
(safe_div_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{

  return

    ((si2 == 0) || ((si1 == (-128)) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 / si2);
}

static int8_t
(safe_lshift_func_int8_t_s_s)(int8_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > ((127) >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static int8_t
(safe_lshift_func_int8_t_s_u)(int8_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32) || (left > ((127) >> ((unsigned int)right)))) ?
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






    -si;
}

static int16_t
(safe_add_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return






    (si1 + si2);
}

static int16_t
(safe_sub_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return






    (si1 - si2);
}

static int16_t
(safe_mul_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return






    si1 * si2;
}

static int16_t
(safe_mod_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return

    ((si2 == 0) || ((si1 == (-32767-1)) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 % si2);
}

static int16_t
(safe_div_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{

  return

    ((si2 == 0) || ((si1 == (-32767-1)) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 / si2);
}

static int16_t
(safe_lshift_func_int16_t_s_s)(int16_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > ((32767) >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static int16_t
(safe_lshift_func_int16_t_s_u)(int16_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32) || (left > ((32767) >> ((unsigned int)right)))) ?
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


    (si==(-2147483647-1)) ?
    ((si)) :


    -si;
}

static int32_t
(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return


    (((si1>0) && (si2>0) && (si1 > ((2147483647)-si2))) || ((si1<0) && (si2<0) && (si1 < ((-2147483647-1)-si2)))) ?
    ((si1)) :


    (si1 + si2);
}

static int32_t
(safe_sub_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return


    (((si1^si2) & (((si1 ^ ((si1^si2) & (~(2147483647))))-si2)^si2)) < 0) ?
    ((si1)) :


    (si1 - si2);
}

static int32_t
(safe_mul_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return


    (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < ((-2147483647-1) / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < ((-2147483647-1) / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((2147483647) / si1)))) ?
    ((si1)) :


    si1 * si2;
}

static int32_t
(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return

    ((si2 == 0) || ((si1 == (-2147483647-1)) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 % si2);
}

static int32_t
(safe_div_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{

  return

    ((si2 == 0) || ((si1 == (-2147483647-1)) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 / si2);
}

static int32_t
(safe_lshift_func_int32_t_s_s)(int32_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > ((2147483647) >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static int32_t
(safe_lshift_func_int32_t_s_u)(int32_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32) || (left > ((2147483647) >> ((unsigned int)right)))) ?
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


    (si==(-9223372036854775807LL -1)) ?
    ((si)) :


    -si;
}

static int64_t
(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return


    (((si1>0) && (si2>0) && (si1 > ((9223372036854775807LL)-si2))) || ((si1<0) && (si2<0) && (si1 < ((-9223372036854775807LL -1)-si2)))) ?
    ((si1)) :


    (si1 + si2);
}

static int64_t
(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return


    (((si1^si2) & (((si1 ^ ((si1^si2) & (~(9223372036854775807LL))))-si2)^si2)) < 0) ?
    ((si1)) :


    (si1 - si2);
}

static int64_t
(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return


    (((si1 > 0) && (si2 > 0) && (si1 > ((9223372036854775807LL) / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < ((-9223372036854775807LL -1) / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < ((-9223372036854775807LL -1) / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((9223372036854775807LL) / si1)))) ?
    ((si1)) :


    si1 * si2;
}

static int64_t
(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return

    ((si2 == 0) || ((si1 == (-9223372036854775807LL -1)) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 % si2);
}

static int64_t
(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return

    ((si2 == 0) || ((si1 == (-9223372036854775807LL -1)) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 / si2);
}

static int64_t
(safe_lshift_func_int64_t_s_s)(int64_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > ((9223372036854775807LL) >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static int64_t
(safe_lshift_func_int64_t_s_u)(int64_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32) || (left > ((9223372036854775807LL) >> ((unsigned int)right)))) ?
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

    ((((int)right) < 0) || (((int)right) >= 32) || (left > ((255) >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static uint8_t
(safe_lshift_func_uint8_t_u_u)(uint8_t left, unsigned int right )
{

  return

    ((((unsigned int)right) >= 32) || (left > ((255) >> ((unsigned int)right)))) ?
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

    ((((int)right) < 0) || (((int)right) >= 32) || (left > ((65535) >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static uint16_t
(safe_lshift_func_uint16_t_u_u)(uint16_t left, unsigned int right )
{

  return

    ((((unsigned int)right) >= 32) || (left > ((65535) >> ((unsigned int)right)))) ?
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

    ((((int)right) < 0) || (((int)right) >= 32) || (left > ((4294967295U) >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static uint32_t
(safe_lshift_func_uint32_t_u_u)(uint32_t left, unsigned int right )
{

  return

    ((((unsigned int)right) >= 32) || (left > ((4294967295U) >> ((unsigned int)right)))) ?
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

    ((((int)right) < 0) || (((int)right) >= 32) || (left > ((18446744073709551615ULL) >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static uint64_t
(safe_lshift_func_uint64_t_u_u)(uint64_t left, unsigned int right )
{

  return

    ((((unsigned int)right) >= 32) || (left > ((18446744073709551615ULL) >> ((unsigned int)right)))) ?
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

    (fabsf((0.5f * sf1) + (0.5f * sf2)) > (0.5f * 3.40282347e+38F)) ?
    (sf1) :

    (sf1 + sf2);
}

static float
(safe_sub_func_float_f_f)(float sf1, float sf2 )
{

  return

    (fabsf((0.5f * sf1) - (0.5f * sf2)) > (0.5f * 3.40282347e+38F)) ?
    (sf1) :

    (sf1 - sf2);
}

static float
(safe_mul_func_float_f_f)(float sf1, float sf2 )
{

  return


    (fabsf((0x1.0p-100f * sf1) * (0x1.0p-28f * sf2)) > (0x1.0p-100f * (0x1.0p-28f * 3.40282347e+38F))) ?



    (sf1) :

    (sf1 * sf2);
}

static float
(safe_div_func_float_f_f)(float sf1, float sf2 )
{

  return


    ((fabsf(sf2) < 1.0f) && (((sf2 == 0.0f) || (fabsf((0x1.0p-49f * sf1) / (0x1.0p100f * sf2))) > (0x1.0p-100f * (0x1.0p-49f * 3.40282347e+38F))))) ?



    (sf1) :

    (sf1 / sf2);
}




static double
(safe_add_func_double_f_f)(double sf1, double sf2 )
{

  return

    (fabs((0.5 * sf1) + (0.5 * sf2)) > (0.5 * 1.7976931348623157e+308)) ?
    (sf1) :

    (sf1 + sf2);
}

static double
(safe_sub_func_double_f_f)(double sf1, double sf2 )
{

  return

    (fabs((0.5 * sf1) - (0.5 * sf2)) > (0.5 * 1.7976931348623157e+308)) ?
    (sf1) :

    (sf1 - sf2);
}

static double
(safe_mul_func_double_f_f)(double sf1, double sf2 )
{

  return


    (fabs((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) > (0x1.0p-100 * (0x1.0p-924 * 1.7976931348623157e+308))) ?



    (sf1) :

    (sf1 * sf2);
}

static double
(safe_div_func_double_f_f)(double sf1, double sf2 )
{

  return


    ((fabs(sf2) < 1.0) && (((sf2 == 0.0) || (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) > (0x1.0p-100 * (0x1.0p-974 * 1.7976931348623157e+308))))) ?



    (sf1) :

    (sf1 / sf2);
}
static int32_t
(safe_convert_func_float_to_int32_t)(float sf1 )
{

  return

    ((sf1 <= (-2147483647-1)) || (sf1 >= (2147483647))) ?
    ((2147483647)) :

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
void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);static long __undefined;



static uint8_t g_9 = 0xC2L;
static int16_t g_13[7] = {6L,6L,6L,6L,6L,6L,6L};
static uint8_t g_34[1] = {255UL};
static int16_t g_35 = (-1L);
static uint32_t g_68 = 0x826FFEA1L;
static uint32_t g_76 = 0x0DA8F9E1L;
static uint8_t g_87 = 8UL;
static uint16_t g_98[5][5] = {{0x7EEBL,0xD5CEL,0xD5CEL,0x7EEBL,0xD5CEL},{0UL,0x4B89L,65529UL,0x4B89L,0UL},{0xD5CEL,0x7EEBL,0xD5CEL,0xD5CEL,0x7EEBL},{0UL,0x618CL,9UL,0x4B89L,9UL},{0x7EEBL,0x7EEBL,0x38F9L,0x7EEBL,0x7EEBL}};
static int8_t g_154 = 1L;
static uint16_t g_172 = 3UL;
static uint32_t g_184 = 4294967290UL;
static int32_t g_204 = 0xC3769B55L;
static int32_t g_240 = 0x022D0BABL;
static int32_t g_275 = (-1L);
static int16_t g_335 = 0x4348L;
static uint32_t g_352 = 0xA0F0610EL;
static uint32_t g_469 = 1UL;
static uint8_t g_472 = 0x82L;
static const int8_t g_496[4] = {(-5L),(-5L),(-5L),(-5L)};
static int32_t g_506 = 1L;
static int32_t g_573 = 1L;
static uint32_t g_759 = 2UL;
static int16_t g_897 = 2L;
static uint32_t g_982 = 9UL;
static uint32_t g_1138 = 0UL;
static int16_t g_1288 = 0x6F0FL;
static uint32_t g_1345 = 0UL;
static int16_t g_1352 = (-10L);
static uint32_t g_1368 = 0x7E530F86L;
static uint8_t g_1369 = 255UL;
static int32_t g_1370[3] = {3L,3L,3L};
static uint16_t g_1599 = 0x499AL;
static int16_t g_1684[1] = {1L};
static uint32_t g_1798[9][8] = {{0x56E2FFE9L,18446744073709551615UL,18446744073709551615UL,18446744073709551615UL,0x56E2FFE9L,18446744073709551615UL,0xDA781D62L,18446744073709551615UL},{18446744073709551615UL,18446744073709551615UL,0xDA781D62L,18446744073709551615UL,0xDA781D62L,18446744073709551615UL,18446744073709551615UL,0xDA781D62L},{18446744073709551615UL,0xDA781D62L,0xDA781D62L,18446744073709551615UL,0x56E2FFE9L,18446744073709551615UL,0xDA781D62L,0xDA781D62L},{0xDA781D62L,0x56E2FFE9L,18446744073709551615UL,18446744073709551615UL,0x56E2FFE9L,0xDA781D62L,0x56E2FFE9L,18446744073709551615UL},{18446744073709551615UL,0x56E2FFE9L,18446744073709551615UL,0xDA781D62L,0xDA781D62L,18446744073709551615UL,0x56E2FFE9L,18446744073709551615UL},{18446744073709551615UL,0xDA781D62L,18446744073709551615UL,0xDA781D62L,18446744073709551615UL,18446744073709551615UL,0xDA781D62L,18446744073709551615UL},{18446744073709551615UL,18446744073709551615UL,0xDA781D62L,18446744073709551615UL,0xDA781D62L,18446744073709551615UL,18446744073709551615UL,0xDA781D62L},{18446744073709551615UL,0xDA781D62L,0xDA781D62L,18446744073709551615UL,0x56E2FFE9L,18446744073709551615UL,0xDA781D62L,0xDA781D62L},{0xDA781D62L,0x56E2FFE9L,18446744073709551615UL,18446744073709551615UL,0x56E2FFE9L,0xDA781D62L,0x56E2FFE9L,18446744073709551615UL}};
static int32_t g_2043 = 1L;
static int8_t g_2422 = 0L;
static int32_t g_2440 = 0x5D5CCD00L;
static int8_t g_2467 = 0x0BL;
static int32_t g_2580[4][10] = {{(-6L),7L,(-6L),7L,(-6L),7L,(-6L),7L,(-6L),7L},{(-7L),7L,(-7L),7L,(-7L),7L,(-7L),7L,(-7L),7L},{(-6L),7L,(-6L),7L,(-6L),7L,(-6L),7L,(-6L),7L},{(-7L),7L,(-7L),7L,(-7L),7L,(-7L),7L,(-7L),7L}};
static uint8_t g_2852 = 0xF5L;
static int32_t g_2853[4][9][7] = {{{1L,8L,1L,(-2L),1L,0x9162827DL,0x2AEB18CDL},{0x22889FBDL,0xFE393A3EL,0x72689436L,1L,(-5L),0xA7638D47L,(-7L)},{(-7L),7L,0x2E60C645L,0x922280B4L,0x2CD7B01AL,0x9162827DL,0x165B162BL},{8L,0xBC24BBA0L,0xEF644D30L,0x29CDD46AL,(-7L),0x2E60C645L,0x3B7B7FB6L},{5L,0x2956CC64L,0x7E7AE4D9L,5L,0xBAC0718BL,(-10L),(-10L)},{0x922280B4L,(-5L),0x2E60C645L,0x2956CC64L,0x5455B5EAL,0x29CDD46AL,0x1E7F4047L},{7L,0x22889FBDL,5L,0L,0xBC24BBA0L,0x2CD7B01AL,0x2E60C645L},{0x45A3EBD2L,1L,0L,(-7L),0xFE393A3EL,0xDAA941AEL,(-7L)},{0xE2A7F447L,0x2CD7B01AL,(-8L),(-7L),1L,0x037CD66FL,0x165B162BL}},{{0xEF644D30L,3L,(-4L),0L,1L,0x5455B5EAL,0xB22D563CL},{8L,0xE2A7F447L,0L,0x2956CC64L,0x22889FBDL,0xCB7BB8D8L,1L},{0x2956CC64L,0L,1L,5L,(-8L),0x57A8756FL,0x45A3EBD2L},{0x3715B254L,0L,4L,4L,0L,0x3715B254L,(-2L)},{3L,0xECFAD87DL,0x45A3EBD2L,0xEF644D30L,1L,(-10L),1L},{(-8L),0xCB7BB8D8L,0xDB9C0739L,1L,0x4EB927D7L,0xA7638D47L,0xEF644D30L},{0x7E7AE4D9L,0xECFAD87DL,0xCB7BB8D8L,(-2L),0x4B49E98FL,0xECEDB848L,4L},{0x57A8756FL,0L,(-2L),3L,0L,(-1L),0x57A8756FL},{0xECB0BC40L,1L,0L,0x2E60C645L,(-2L),0xA7638D47L,0x3B7B7FB6L}},{{0L,0x4B49E98FL,0L,0L,(-1L),0x4EB927D7L,1L},{1L,0xB22D563CL,0x2BD64D8CL,7L,0x2CD7B01AL,0x45A3EBD2L,0x9162827DL},{0xB22D563CL,0xDB9C0739L,0L,(-5L),0L,0L,0x9162827DL},{0x73EF0EC5L,1L,0xCB7BB8D8L,(-10L),0x9162827DL,(-2L),1L},{1L,1L,8L,5L,8L,8L,0x3B7B7FB6L},{0x9162827DL,(-8L),0x3715B254L,0L,0L,(-1L),0x57A8756FL},{(-2L),0x3B7B7FB6L,4L,0L,0L,0L,4L},{0x2AEB18CDL,0x2AEB18CDL,0xE2A7F447L,7L,0x5455B5EAL,8L,0xEF644D30L},{0x9162827DL,0xA08F48A9L,0xD4E37EFFL,0xECFAD87DL,(-4L),4L,1L}},{{(-4L),0L,0x72689436L,0x4EB927D7L,0x5455B5EAL,0L,(-2L)},{(-1L),0x29CDD46AL,(-1L),3L,0L,1L,3L},{0xB22D563CL,1L,0x7F6BF62EL,0x2AEB18CDL,0L,(-5L),0x2E60C645L},{0xA7638D47L,0L,0xAB9529BDL,0L,8L,(-4L),0L},{(-5L),(-8L),1L,0xEF644D30L,0x9162827DL,1L,7L},{0xECB0BC40L,(-2L),0xDAA941AEL,8L,0L,(-10L),(-5L)},{0xAB9529BDL,0x3B7B7FB6L,0xDAA941AEL,0xAB9529BDL,0x2CD7B01AL,0L,(-10L)},{0xEF644D30L,7L,1L,0x3B7B7FB6L,(-1L),0xC093BDB0L,5L},{(-8L),0xA7638D47L,0xAB9529BDL,(-4L),(-2L),0xDB9C0739L,0L}}};
static uint16_t g_3109[3] = {0xAEF2L,0xAEF2L,0xAEF2L};
static int8_t g_3172 = 0xC1L;
static uint8_t g_3193 = 0UL;
static uint16_t g_3317 = 1UL;
static uint32_t g_3463 = 0x33A4172FL;
static int32_t g_3486 = 0L;
static int8_t g_3600 = 0xA8L;
static int32_t g_3935[8][5] = {{8L,0x6D7DF5BFL,0xACB7A77CL,0xCFF4EF85L,0x6D7DF5BFL},{(-1L),0xACB7A77CL,0xACB7A77CL,(-1L),0xCFF4EF85L},{0L,(-1L),(-1L),0x6D7DF5BFL,0x6D7DF5BFL},{8L,(-1L),8L,0xCFF4EF85L,0xACB7A77CL},{8L,(-1L),(-9L),8L,(-9L)},{8L,8L,0x6D7DF5BFL,0xACB7A77CL,0xCFF4EF85L},{(-1L),0xCFF4EF85L,(-9L),(-9L),0xCFF4EF85L},{0xCFF4EF85L,(-1L),(-1L),0xCFF4EF85L,(-9L)}};
static uint8_t g_4423[7] = {250UL,250UL,250UL,250UL,250UL,250UL,250UL};
static uint8_t g_4475 = 0x33L;
static int8_t g_4689 = 9L;
static int32_t g_5210[1] = {(-1L)};
static const int32_t g_5225 = 0xAF6272FEL;
static int32_t g_5446[9] = {0L,0L,0L,0L,0L,0L,0L,0L,0L};
static int16_t g_5512 = (-9L);
static int16_t g_5844 = 0xA81BL;
static uint8_t g_6029 = 1UL;
static int16_t g_6428 = 2L;
static uint32_t g_6771 = 7UL;



inline static int8_t func_1(void);
inline static int32_t func_2(uint8_t p_3, uint8_t p_4, uint32_t p_5, int32_t p_6);
static uint16_t func_15(int16_t p_16, uint8_t p_17);
inline static int16_t func_18(int32_t p_19, uint32_t p_20, const uint16_t p_21);
inline static uint32_t func_28(uint32_t p_29, int32_t p_30, int32_t p_31, const uint16_t p_32);
static uint8_t func_37(uint16_t p_38, int32_t p_39, int32_t p_40, int8_t p_41, const int8_t p_42);
inline static uint16_t func_43(int32_t p_44);
static uint16_t func_51(uint32_t p_52);
static uint16_t func_54(int32_t p_55, uint16_t p_56, uint32_t p_57, const int16_t p_58, int16_t p_59);
static int32_t func_60(uint8_t p_61);
inline static int8_t func_1(void)
{
    int32_t l_10 = 0xE30F5872L;
    int32_t l_33 = 0xBF5F40E1L;
    int32_t l_5910 = 0L;
    int16_t l_5913 = 0x1E08L;
    const int32_t l_6074 = 2L;
    uint32_t l_6137 = 0x0644BDCEL;
    uint16_t l_6147 = 9UL;
    int32_t l_6160 = 0xBC1CE112L;
    uint32_t l_6167 = 0x19A4727FL;
    uint32_t l_6261 = 0x88ADAE8CL;
    int32_t l_6536 = 0L;
    int32_t l_6627 = 0xA1B7E97EL;
    int8_t l_6823 = (-1L);
    uint8_t l_6825 = 0x44L;
    l_33 = func_2(((safe_div_func_int16_t_s_s(((((g_13[4] = ((l_10 = g_9) , (safe_sub_func_int8_t_s_s(l_10, 5L)))) <= (!((func_15((g_9 > (func_18((safe_rshift_func_uint8_t_u_u(g_9, 7)), g_9, (((safe_mod_func_int16_t_s_s((safe_rshift_func_int8_t_s_s(g_9, 3)), (func_28(l_33, g_9, g_9, g_9) , 1UL))) <= 1UL) && g_172)) | l_33)), l_33) <= 0x5718L) , g_759))) < l_33) ^ 4294967295UL), 0x0918L)) == l_33), g_1798[4][6], g_5225, g_496[2]);
                                   uint8_t BpBpBg_1369 = (~(((~((~((((~((~(g_3317)))) | ((~(g_352)) ^ (~(g_154)))) ^ (~((~((l_5913 | g_897)))))))))) || ((~(((g_76 || g_1369) % (l_6137 || g_9)))) || g_6029))));
uint8_t BpBpBbg_6029 = (~(((~(((~((~(((~(((~(l_6137)) ^ g_154))) & l_5913))))) || (~(((~((~((~(BpBpBg_1369)))))) % (((g_76 & g_3317) >> g_6029) ^ (~((~(g_9))))))))))) % (~((g_897 | ((~(g_1369)) ^ (~(g_352)))))))));
uint16_t BpBpBcg_3317 = (~((((BpBpBg_1369 | (~((~(g_352))))) || ((g_76 ^ (~(g_6029))) & (~(BpBpBbg_6029)))) & ((~((g_9 & (~((g_1369 & l_5913)))))) ^ (~(((~(g_154)) | ((g_897 % g_3317) ^ l_6137))))))));
int8_t BpBpBdg_154 = (~((((l_5913 ^ BpBpBg_1369) >> ((~((g_9 << (g_3317 & g_1369)))) || (~(g_154)))) % (l_6137 << (((~(g_897)) & g_6029) | (((g_76 ^ BpBpBbg_6029) || BpBpBcg_3317) & (~(g_352))))))));
uint32_t BpBpBeg_352 = (~(((~(((BpBpBdg_154 | (~((l_6137 & g_897)))) || (~((g_6029 & ((g_3317 ^ BpBpBcg_3317) & (~((g_9 & BpBpBg_1369)))))))))) & (~(((~((~((~(BpBpBbg_6029)))))) ^ ((l_5913 % (g_1369 || (~(g_352)))) % ((~(g_76)) ^ g_154))))))));
uint8_t BpBpBfg_9 = (~(((((g_897 << (g_3317 % BpBpBeg_352)) | (g_1369 & (g_352 | (BpBpBcg_3317 ^ l_5913)))) ^ (~((~(((l_6137 ^ g_154) || (g_9 ^ (((~(g_6029)) | (BpBpBbg_6029 | BpBpBdg_154)) ^ (~(g_76)))))))))) | (~((~((~((~(BpBpBg_1369)))))))))));
if(!(((g_6029 < g_352) && (!g_6029)))){
BpBpBg_1369 = g_1369;
BpBpBbg_6029 = g_6029;
BpBpBcg_3317 = g_3317;
BpBpBdg_154 = g_154;
BpBpBeg_352 = g_352;
                                   if (((g_172<=3) || (!g_469)))
                    BpBpBfg_9 = g_9;
g_1369 = (~((((~((~(((~((~(((~(BpBpBcg_3317)) || (~((~(g_3317))))))))) ^ (~((~(l_5913))))))))) || (~((~((~((BpBpBbg_6029 ^ (BpBpBfg_9 & (~((BpBpBg_1369 % (g_9 | g_154))))))))))))) || (((~((((~(l_6137)) | (~(g_6029))) || (~((~((~(g_352))))))))) | (~((~((g_897 & (BpBpBdg_154 & BpBpBeg_352))))))) | (g_76 & g_1369)))));
g_6029 = (~(((((~((l_6137 ^ (BpBpBfg_9 || g_897)))) & (~((~(g_3317))))) || (~((~((~((g_9 & (BpBpBeg_352 || g_6029))))))))) | (~((~((((~((~(g_1369)))) ^ ((~(g_352)) || ((~((g_76 >> BpBpBbg_6029))) || g_154))) | ((BpBpBg_1369 % (~(l_5913))) | (BpBpBcg_3317 | BpBpBdg_154))))))))));
                                    while ((((g_3172 < l_33) && (l_5910<=0)) && (!l_6261)) )
{

g_469 += 1;


}
                    g_3317 = (~(((~((((~(BpBpBbg_6029)) ^ (~((BpBpBcg_3317 << g_154)))) | (~((l_5913 | l_6137)))))) | ((((~(BpBpBdg_154)) ^ g_6029) ^ ((~(((BpBpBeg_352 % BpBpBg_1369) & g_3317))) ^ ((g_897 | g_1369) % (g_76 || g_9)))) ^ (~((g_352 % BpBpBfg_9)))))));
g_154 = (~((((((~((g_154 | (g_6029 & g_1369)))) | (BpBpBfg_9 & BpBpBeg_352)) | g_9) || (~(BpBpBdg_154))) ^ (((~((BpBpBbg_6029 | BpBpBg_1369))) & (~(l_5913))) || ((g_352 | (~(BpBpBcg_3317))) >> (((g_897 ^ g_76) % (~(l_6137))) || (~((~(g_3317))))))))));
g_352 = (~(((~((BpBpBcg_3317 % l_5913))) % ((((g_76 % g_352) >> ((~((~((g_3317 & BpBpBg_1369))))) ^ (BpBpBdg_154 || g_154))) >> (g_9 || l_6137)) | ((~(((BpBpBbg_6029 ^ BpBpBeg_352) % (BpBpBfg_9 ^ g_6029)))) % ((~(g_897)) | g_1369))))));
                                    while (((l_33<=233) && (!g_5512)) )
{

g_5512 += 1;


}
                    g_9 = (~(((~(((~(((g_1369 % (((~((g_76 ^ l_6137))) || BpBpBg_1369) << (~(BpBpBeg_352)))) >> ((g_3317 >> BpBpBcg_3317) & (((~(((BpBpBdg_154 | g_352) << g_897))) & (~(BpBpBfg_9))) | BpBpBbg_6029))))) || (~(((~(g_9)) | (~((~(g_6029)))))))))) & (~(((~(g_154)) & l_5913))))));
if(!(((l_6137<=105168334U) || (g_9<1)))){
printf("g_1369=%llu\n", (unsigned long long)g_1369);

for (l_33 = 0; l_33 < 8; l_33++)
    {
        for (g_275 = 0; g_275 < 5; g_275++)
        {
            transparent_crc(g_3935[l_33][g_275], "g_3935[l_33][g_275]", g_2043);
            if (g_2043) printf("index = [%d][%d]\n", l_33, g_275);

        }
    };


                    BpBpBeg_352 = (~((((~((~(BpBpBdg_154)))) << (~(((((~((g_352 >> g_6029))) || (~(BpBpBcg_3317))) ^ g_897) >> (~((~((BpBpBfg_9 & g_9))))))))) ^ (~(((~((((BpBpBeg_352 % (g_154 % g_3317)) % (g_1369 % l_6137)) | (~((BpBpBbg_6029 >> l_5913)))))) | (g_76 >> BpBpBg_1369)))))));
g_6029 = (~((((~(((~(g_352)) % (~((BpBpBeg_352 << (g_897 ^ BpBpBbg_6029))))))) || (~((~(BpBpBg_1369))))) << ((~((((~(BpBpBdg_154)) >> (BpBpBcg_3317 % g_9)) || (~(((~(l_6137)) % ((~((~(l_5913)))) ^ ((~(g_76)) ^ (g_3317 ^ (~(g_154))))))))))) & (g_1369 || (~((g_6029 || BpBpBfg_9))))))));
}
                                    while ((g_2467 > g_3193) )
{

g_2852 += 1;


}
                    LABEL_pBpBg: if((BpBpBbg_6029 > BpBpBeg_352)){
printf("g_6029=%llu\n", (unsigned long long)g_6029);
goto LABEL_pBpBg;
}
if(((g_76>432544659U) && ((!g_897) || (!g_154)))){
;
g_1369 = (~(((~((~(((~((~(BpBpBfg_9)))) | (l_5913 & g_9)))))) >> (~((((~(((BpBpBeg_352 << (~(BpBpBg_1369))) & ((~(((g_1369 ^ BpBpBbg_6029) || (BpBpBdg_154 ^ (~(g_6029)))))) >> l_6137)))) & ((g_3317 || (g_897 << g_154)) % (~(BpBpBcg_3317)))) % (~(((~(g_76)) | g_352)))))))));
g_3317 = (~((((~((~((~((~(BpBpBdg_154)))))))) || ((~((((g_6029 >> (~(g_9))) & g_352) >> (~(l_6137))))) >> (g_1369 >> BpBpBcg_3317))) ^ ((~((~(BpBpBbg_6029)))) || (((g_897 || (~(((~(BpBpBfg_9)) << (BpBpBg_1369 & g_76))))) % g_3317) & (((~(BpBpBeg_352)) ^ g_154) >> l_5913))))));
goto LABEL_pBpBg;
}
if(((BpBpBdg_154>0) && (!l_5913))){

{
                        uint32_t l_1366 = 0x006BF911L;
                        int8_t l_1367[2];
                        int i;
                        ;
                        g_506 = 1L;

for (l_5910 = 29; (l_5910 != 28); l_5910 = safe_sub_func_int16_t_s_s(l_5910, 7))
                    {
                        g_240 = g_204;
                        g_240 = (((BpBpBdg_154 = (-5L)) , (~(7UL && ((g_34[0] && g_3193) != (safe_mod_func_uint8_t_u_u(1UL, (safe_div_func_uint16_t_u_u((((l_5910 | (1UL ^ (g_3193 <= (i ^ g_5844)))) >= 0x083A407DL) ^ g_3193), 0x8056L)))))))) >= g_3193);
                    };


                    g_1370[2] = (g_87 = (g_1368 = (g_506 = ((safe_add_func_uint16_t_u_u((!(g_5512 = 0xD302L)), ((((((safe_rshift_func_uint16_t_u_s((g_3317 = ((((g_1369 != (safe_div_func_int8_t_s_s(((((l_5910 | (safe_lshift_func_uint8_t_u_u(((((safe_lshift_func_int8_t_s_u(0xB0L, ((safe_div_func_uint8_t_u_u(g_34[0], (((0x1E1D4A8BL ^ (-9L)) > (g_897 = 0xF6A0L)) | (safe_lshift_func_uint8_t_u_u(((~g_1369) < g_1369), 6))))) ^ 0x33E45DBAL))) | g_1369) && g_34[0]) > g_275), l_1366))) != g_1369) , g_496[2]) != g_68), g_506))) >= l_1367[1]) , g_1369) & 7UL)), g_1368)) >= 7L) , 2UL) ^ l_1367[1]) <= 0x428C0265L) | l_1366))) ^ g_472))));
                        g_506 = 0L;
                    }



{
                        g_204 = g_982;
                    }

                    g_897 += 1;


                    printf("g_154=%lld\n", (long long)g_154);

g_2440 -= 1;


                    goto LABEL_pBpBg;
}
if((l_6137 > BpBpBeg_352)){
;
goto LABEL_pBpBg;
}
if((l_6137 < BpBpBdg_154)){
printf("g_9=%llu\n", (unsigned long long)g_9);
g_6029 = (~(((~((~((~(((~(((g_76 << (~(((~(BpBpBbg_6029)) & (~((~(l_5913)))))))) % (~(g_9))))) >> (~((g_6029 | (~(BpBpBeg_352)))))))))))) | (~(((g_1369 % g_897) % (((BpBpBg_1369 ^ g_3317) % (~((BpBpBdg_154 | g_352)))) | (((~(g_154)) || (~(l_6137))) & (BpBpBcg_3317 << BpBpBfg_9)))))))));
g_3317 = (~(((~((((((~(((g_3317 & (~(l_6137))) % g_76))) | (~(((BpBpBeg_352 | (~(g_6029))) >> (BpBpBdg_154 || BpBpBbg_6029))))) & g_9) | g_154) >> (~((((~((~(BpBpBg_1369)))) | (g_897 % g_352)) << ((~((~(l_5913)))) >> (~(g_1369))))))))) >> (~((~((BpBpBfg_9 & BpBpBcg_3317))))))));
goto LABEL_pBpBg;
}
}
g_1369 = BpBpBg_1369;
g_6029 = BpBpBbg_6029;
g_3317 = BpBpBcg_3317;
g_154 = BpBpBdg_154;
                                   if ((g_68 > g_6428))
                    g_352 = BpBpBeg_352;
g_9 = BpBpBfg_9;

                                                   uint32_t BGBGBg_352 = (~((((~((~(((g_87 | g_5844) ^ (~(g_352))))))) / g_275) ^ ((~(l_6147)) % ((~(g_5225)) >> (((~(((~(g_1368)) & g_335))) ^ (~(g_897))) % (~(g_68))))))));
int16_t BGBGBbg_335 = (~((((~((((~(g_1368)) >> (BGBGBg_352 & (g_68 ^ l_6147))) % (~(g_5844))))) | (~(((g_5225 || g_275) ^ (~(g_335)))))) / (~(((g_352 / g_897) ^ g_87))))));
uint32_t BGBGBcg_1368 = (~(((((((~(g_1368)) & (~(l_6147))) || g_275) ^ ((~(g_352)) % (~(BGBGBg_352)))) & ((g_335 % (g_897 | g_5844)) | (~(g_5225)))) & (~((~((~(((g_68 | g_87) ^ BGBGBbg_335))))))))));
uint8_t BGBGBdg_87 = (~((((~((g_275 % (~(g_5844))))) ^ (((l_6147 || g_68) ^ ((((g_897 % BGBGBg_352) & (~((~(g_335))))) / BGBGBcg_1368) || (~(g_1368)))) & ((BGBGBbg_335 / g_352) || g_87))) || (~(g_5225)))));
int16_t BGBGBeg_897 = (~((((~(g_5844)) || (BGBGBdg_87 & (~((g_68 || BGBGBbg_335))))) % ((((((~(l_6147)) || (~(BGBGBcg_1368))) % g_87) & (~((~(g_5225))))) & BGBGBg_352) ^ (~(((g_1368 ^ (g_352 || g_275)) % ((~(g_335)) % g_897))))))));
if((g_5225 || (l_6147 < g_897))){
LABEL_GBGBf: BGBGBg_352 = g_352;
BGBGBbg_335 = g_335;
                                   if ((g_87<=251))
                    BGBGBcg_1368 = g_1368;
BGBGBdg_87 = g_87;
BGBGBeg_897 = g_897;
g_352 = (~(((~(((~(((g_1368 % BGBGBeg_897) || ((~(g_5844)) / (~(BGBGBg_352)))))) ^ (~((~(((l_6147 || (g_335 & g_897)) & (~((~(((BGBGBbg_335 | ((~(g_5225)) % g_68)) | g_352))))))))))))) % (~((((~(g_275)) | ((~((~(BGBGBcg_1368)))) || g_87)) % BGBGBdg_87))))));
g_335 = (~(((~((~((~(BGBGBdg_87)))))) || (~(((((~(g_68)) << ((~((g_897 || (g_1368 & BGBGBbg_335)))) / ((~((((~(g_335)) & g_87) >> (~((BGBGBg_352 ^ (g_352 & BGBGBcg_1368))))))) / (~((~(g_275))))))) || g_5225) & (~((BGBGBeg_897 % ((~(g_5844)) ^ l_6147))))))))));
g_1368 = (~((((~((((g_5225 & g_5844) | ((g_68 & (l_6147 ^ (~(g_897)))) ^ (~(BGBGBbg_335)))) || (~(((g_352 / g_87) & (~(g_275)))))))) | (BGBGBcg_1368 / BGBGBg_352)) | (~(((~(((~(g_1368)) >> BGBGBeg_897))) & (~(((~(g_335)) | BGBGBdg_87)))))))));
LABEL_GBGBg: g_87 = (~(((~(((~((~((((g_1368 & (BGBGBbg_335 % g_87)) & (~((g_335 ^ (g_5844 || BGBGBeg_897))))) % (BGBGBdg_87 | (~(g_897)))))))) | (~(((~(g_352)) & (~(BGBGBcg_1368)))))))) & (~(((~((~(BGBGBg_352)))) & (((~(((~(l_6147)) / g_5225))) % (~(g_68))) >> (~(g_275)))))))));
g_897 = (~(((~(((~(((g_5844 & ((g_897 | (~(BGBGBg_352))) << ((((g_352 & g_87) ^ g_68) & (~(BGBGBcg_1368))) / (((~(g_1368)) || l_6147) ^ g_335)))) | (~((g_5225 % (~((BGBGBeg_897 % g_275))))))))) % (~(BGBGBbg_335))))) & (~(BGBGBdg_87)))));
if((!BGBGBg_352)){
;
g_352 = (~(((~((((~(((g_5225 & g_5844) << BGBGBeg_897))) << (BGBGBcg_1368 & g_1368)) >> (~(((g_897 >> g_68) >> (~(g_275)))))))) % (((~(BGBGBg_352)) || (~(((~(BGBGBdg_87)) | (((~((~(g_335)))) >> (BGBGBbg_335 / (~(g_87)))) >> l_6147))))) >> g_352))));
}
if((g_352>4294967295U)){
printf("g_335=%lld\n", (long long)g_335);
goto LABEL_pBpBg;
}
if((!g_897)){

{
            transparent_crc(g_3935[g_2440][l_6160], "g_3935[g_2440][l_6160]", l_5910);
            if (l_5910) printf("index = [%d][%d]\n", g_2440, l_6160);

        }

                    printf("g_1368=%llu\n", (unsigned long long)g_1368);
BGBGBg_352 = (~(((((g_275 & (g_1368 << g_87)) & l_6147) >> BGBGBbg_335) | (~((((~((~(((~(BGBGBeg_897)) | BGBGBg_352))))) >> (BGBGBdg_87 ^ ((~(((~((~(g_5844)))) | g_897))) >> (g_68 << BGBGBcg_1368)))) || (~((~(((g_5225 | (~(g_352))) || g_335)))))))))));

{
                        uint32_t l_1366 = 0x006BF911L;
                        int8_t l_1367[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            {
{
                    for (g_2043 = 24; (g_2043 != 8); g_2043 = safe_sub_func_int8_t_s_s(g_2043, 7))
                    {
                        if (BpBpBg_1369)
                            break;
                        l_6137 = g_897;
                    }
                }

                    l_1367[i] = 1L;}
                        l_10 = 1L;
                        g_1370[2] = (BpBpBg_1369 = (g_1138 = (l_10 = ((safe_add_func_uint16_t_u_u((!(g_6428 = 0xD302L)), ((((((safe_rshift_func_uint16_t_u_s((g_1599 = ((((BGBGBdg_87 != (safe_div_func_int8_t_s_s(((((g_3486 | (safe_lshift_func_uint8_t_u_u(((((safe_lshift_func_int8_t_s_u(0xB0L, ((safe_div_func_uint8_t_u_u(g_34[0], (((0x1E1D4A8BL ^ (-9L)) > (l_5913 = 0xF6A0L)) | (safe_lshift_func_uint8_t_u_u(((~BGBGBdg_87) < BGBGBdg_87), 6))))) ^ 0x33E45DBAL))) | BGBGBdg_87) && g_34[0]) > l_6627), l_1366))) != BGBGBdg_87) , g_496[2]) != BGBGBcg_1368), l_10))) >= l_1367[1]) , BGBGBdg_87) & 7UL)), g_1368)) >= 7L) , 2UL) ^ l_1367[1]) <= 0x428C0265L) | l_1366))) ^ g_2852))));
                        l_10 = 0L;
                    }

                    goto LABEL_pBpBg;
}
if(!((g_5844 < g_897))){

g_982 += 1;


                    printf("g_87=%llu\n", (unsigned long long)g_87);

{
                        int32_t l_2330 = 0xB0B48C1AL;
                        g_573 = (safe_rshift_func_int16_t_s_s(6L, l_2330));
                        l_6160 = g_35;
                    }

                    BGBGBdg_87 = (~((((g_897 >> g_5225) / (~((g_68 % ((BGBGBeg_897 & ((~((~((g_5844 % BGBGBdg_87))))) / g_352)) / (g_1368 / l_6147)))))) % (((~((~((((~((~(g_275)))) ^ g_87) / (~((BGBGBg_352 / (~(g_335)))))))))) & BGBGBcg_1368) << (~(BGBGBbg_335))))));
;
}
if((g_68 < BGBGBdg_87)){
printf("g_897=%lld\n", (long long)g_897);
g_352 = (~(((~(g_1368)) | ((((BGBGBcg_1368 % BGBGBbg_335) | ((~((BGBGBg_352 / g_5225))) || BGBGBdg_87)) | g_335) ^ (((g_68 << (~(g_87))) << (((g_897 | g_5844) | (g_275 / g_352)) || (~(BGBGBeg_897)))) & l_6147)))));
goto LABEL_GBGBf;
}
}
g_352 = BGBGBg_352;
g_335 = BGBGBbg_335;
g_1368 = BGBGBcg_1368;
                                   if ((g_3463 && (l_6825>=68)))
                    g_87 = BGBGBdg_87;
g_897 = BGBGBeg_897;

                    if ((g_275 > g_3600))
    {
        int8_t l_5835[9] = {1L,1L,1L,1L,1L,1L,1L,1L,1L};
        int16_t l_5888 = 0x3337L;
        uint32_t l_5929 = 0xA1740709L;
        int32_t l_5943 = 0x3E7952D3L;
        int32_t l_5986 = 0x2FC02A58L;
        uint32_t l_6086 = 0x310B84EAL;
        int32_t l_6136[4];
        int16_t l_6152 = (-9L);
        int32_t l_6280 = 0L;
        uint32_t l_6318 = 1UL;
        int32_t l_6479[2];
        int8_t l_6486 = 0x18L;
        uint16_t l_6500 = 0x1711L;
        uint32_t l_6600 = 1UL;
        int8_t l_6646 = 0xB6L;
        uint16_t l_6647[10][3] = {{0x588CL,0x588CL,0x4801L},{65533UL,0x4801L,0x4801L},{0x4801L,7UL,0x0738L},{65533UL,7UL,65533UL},{0x588CL,0x4801L,0x0738L},{0x588CL,0x588CL,0x4801L},{65533UL,0x4801L,0x4801L},{0x4801L,7UL,0x0738L},{65533UL,7UL,65533UL},{0x588CL,0x4801L,0x0738L}};
        int32_t l_6762 = 0xD148A94AL;
        uint8_t l_6774[4][8][8] = {{{2UL,0x21L,3UL,254UL,0x20L,0x56L,0x9EL,1UL},{0x78L,0x8FL,1UL,0x68L,4UL,4UL,0x68L,1UL},{255UL,255UL,4UL,9UL,0xABL,0x44L,0x9DL,0x9EL},{0x9EL,251UL,0x89L,255UL,1UL,0x68L,0x78L,0x9EL},{251UL,254UL,5UL,9UL,254UL,0xFBL,3UL,1UL},{246UL,0x56L,5UL,0x68L,0xDEL,254UL,4UL,1UL},{0xE0L,0xFBL,0x9DL,254UL,9UL,0x24L,0xCBL,0xDEL},{254UL,1UL,251UL,0xFBL,0x9EL,0xA6L,0x9EL,0xFBL}},{{0x12L,5UL,0x12L,0xCBL,9UL,4UL,0x89L,0x78L},{9UL,254UL,1UL,0x56L,0xABL,2UL,9UL,0x8FL},{9UL,0x12L,0x68L,255UL,9UL,0UL,0x21L,9UL},{0x12L,2UL,5UL,0xE0L,0x9EL,246UL,1UL,0x21L},{254UL,0x56L,6UL,0UL,9UL,0xFBL,1UL,0x6DL},{0xE0L,0xFBL,9UL,1UL,0xDEL,6UL,6UL,0xDEL},{246UL,0x78L,2UL,3UL,0x01L,0xCBL,0x74L,1UL},{9UL,0xABL,0x44L,0x9DL,0x9EL,0x20L,255UL,0xA6L}},{{0x74L,0xABL,254UL,0x24L,254UL,0xCBL,0x8FL,0UL},{0UL,2UL,4UL,254UL,0x20L,1UL,0x44L,0UL},{2UL,1UL,0UL,5UL,0xABL,251UL,0xA6L,0xDEL},{252UL,0x68L,9UL,1UL,6UL,3UL,254UL,3UL},{0UL,252UL,0x8FL,252UL,0UL,255UL,0x9DL,0xCBL},{0x12L,0xA6L,0x56L,1UL,0xE3L,6UL,0x74L,252UL},{0x44L,0x01L,0x56L,0x28L,5UL,0x20L,0x9DL,9UL},{0xE3L,0UL,0x8FL,0xCBL,254UL,0x24L,254UL,0xABL}},{{0x01L,0xE0L,9UL,254UL,0x8FL,4UL,0xA6L,0x01L},{0xE0L,251UL,0UL,6UL,0UL,0x78L,0x44L,0x44L},{1UL,0x68L,4UL,4UL,0x68L,1UL,0x8FL,0x78L},{0UL,0x78L,254UL,0x12L,0x24L,0x86L,255UL,0xCBL},{0x21L,9UL,0x44L,0x12L,0UL,5UL,0x74L,0x78L},{0xDEL,0UL,2UL,4UL,254UL,0x20L,1UL,0x44L},{0UL,0xE3L,255UL,6UL,254UL,0x68L,0x9EL,0x01L},{0xABL,0x56L,1UL,254UL,9UL,0x28L,0xE0L,0xABL}}};
        int i, j, k;
        for (i = 0; i < 4; i++)
            l_6136[i] = 0xAA93D3A9L;
        for (i = 0; i < 2; i++)
            l_6479[i] = (-1L);
        l_10 = l_5835[0];
                                            while ((g_3486 < g_1352) )
{

BGBGBcg_1368 += 1;


}
                    if (((l_33 = g_1798[5][2]) > (-1L)))
        {
            uint32_t l_5849 = 1UL;
            int32_t l_5850 = (-1L);
            int32_t l_5860 = (-2L);
            const int32_t l_5861 = 6L;
            int32_t l_5862 = 0x1DA25D6DL;
            uint8_t l_5889 = 251UL;
            uint8_t l_5911[6][7] = {{1UL,0x93L,0UL,1UL,1UL,0UL,0x93L},{255UL,8UL,0UL,255UL,0x5BL,0x5BL,255UL},{1UL,0x93L,1UL,0x81L,0x93L,250UL,250UL},{0UL,255UL,0x47L,255UL,0UL,0x47L,251UL},{1UL,250UL,0x81L,1UL,0x81L,250UL,1UL},{0UL,251UL,8UL,0x5BL,251UL,0x5BL,8UL}};
            int32_t l_5912 = 0xF8C4C3B2L;
            int i, j;
            ;
            for (g_154 = 0; (g_154 <= (-20)); --g_154)
            {
                int32_t l_5871 = 8L;
                ;
                l_5871 = (((safe_lshift_func_int16_t_s_u(((0x1892C121L > (l_10 = (safe_add_func_int16_t_s_s((((((safe_rshift_func_uint8_t_u_s(l_5871, 4)) > ((g_1684[0] | 1UL) ^ (g_5844 & (((safe_rshift_func_uint8_t_u_s((((((safe_mod_func_uint32_t_u_u(((safe_div_func_int32_t_s_s((safe_div_func_int8_t_s_s(0x44L, (safe_add_func_int16_t_s_s((safe_mul_func_uint32_t_u_u(g_1368, (((safe_add_func_uint16_t_u_u(0UL, (safe_rshift_func_int8_t_s_u((g_1599 ^ 1L), 7)))) , l_5871) < g_13[4]))), l_5835[0])))), l_5888)) & l_5871), g_3935[1][2])) != l_5871) , g_982) , g_1138) , 3UL), g_35)) < g_5844) || l_5860)))) , 0xD982L) <= l_5871) != l_5889), g_5210[0])))) >= l_5889), g_3193)) < 0x365E12C7L) & l_33);
            }

{
        for (l_10 = 0; l_10 < 5; l_10++)
        {
            transparent_crc(g_98[l_6762][l_10], "g_98[l_6762][l_10]", g_240);
            if (g_240) {
for (g_1368 = 0; (g_1368 <= 3); g_1368 += 1)
                    {
                        int16_t l_6079 = 1L;
                        if (g_897)
                            break;
                        g_2853[0][6][6] = (safe_sub_func_int8_t_s_s(0L, (g_6428 ^ (safe_sub_func_uint16_t_u_u(l_6079, l_6261)))));
                        if (l_6079)
                            continue;
                        if (l_5835[k])
                            continue;
                    };


                    printf("index = [%d][%d]\n", l_6762, l_10);}

        }
    }

                    l_5913 = (((safe_lshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((safe_rshift_func_uint8_t_u_s(((((((g_1369 == ((7L || (safe_sub_func_uint32_t_u_u((8L >= ((l_5850 = (safe_div_func_int16_t_s_s((~((safe_sub_func_int8_t_s_s(4L, (0UL ^ ((((1UL ^ (l_10 , ((!((safe_rshift_func_uint16_t_u_u(((g_13[0] = g_2853[1][5][6]) < ((((safe_div_func_uint8_t_u_u((g_506 >= g_3317), l_5888)) , g_3109[0]) , l_5888) || l_5910)), 0)) > (-1L))) , g_3172))) | g_98[1][3]) == l_5889) & l_10)))) , l_10)), l_5911[2][4]))) == g_573)), g_275))) , g_3486)) > g_2580[1][9]) & g_2852) >= g_1684[0]) , 6UL) & l_33), 3)), l_5912)), 0)), l_5860)) >= l_5910) ^ g_5225);

if (l_6536) printf("index = [%d]\n", g_506);


if (g_506) printf("index = [%d]\n", l_33);

                    ;
        }
        else
        {
            const int8_t l_5928 = 0x04L;
            int8_t l_5945[8][4] = {{0xE1L,1L,0L,0xE1L},{0xAEL,4L,0x8CL,1L},{1L,0xE5L,3L,3L},{4L,4L,0xE1L,(-1L)},{0x8CL,0x0EL,1L,1L},{1L,1L,1L,1L},{4L,1L,0L,1L},{1L,0x0EL,3L,(-1L)}};
            int32_t l_6041 = 0x745A8996L;
            int i, j;
            for (l_5913 = (-28); (l_5913 < (-7)); l_5913 = safe_add_func_int32_t_s_s(l_5913, 8))
            {
                g_3935[3][2] = g_68;
                g_2853[0][6][6] = (-6L);
            }
            for (g_1345 = 0; (g_1345 > 38); g_1345 = safe_add_func_uint16_t_u_u(g_1345, 7))
            {
                uint32_t l_5930[8] = {0xF7688CC0L,0xF7688CC0L,0xF7688CC0L,0xF7688CC0L,0xF7688CC0L,0xF7688CC0L,0xF7688CC0L,0xF7688CC0L};
                int32_t l_5931 = 0x4B1A972DL;
                int32_t l_5942[8] = {0L,0L,0L,0L,0L,0L,0L,0L};
                int32_t l_5944[2][5][9] = {{{0x511436E0L,3L,(-1L),(-1L),3L,0x511436E0L,(-2L),(-1L),(-8L)},{0L,(-5L),0x34699F01L,0x23972C76L,0x34699F01L,(-5L),0L,(-8L),0x23E3115FL},{1L,(-2L),0xBAEE5A71L,0x511436E0L,0x511436E0L,0xBAEE5A71L,(-2L),1L,0x511436E0L},{0x7ABFC440L,(-8L),(-2L),0xD97D4396L,(-1L),0xD97D4396L,(-2L),(-8L),0x7ABFC440L},{(-1L),0x511436E0L,(-1L),0x6B86C82DL,(-1L),(-1L),0x6B86C82DL,(-1L),0x511436E0L}},{{0x34699F01L,0x268C6580L,0x23E3115FL,0x23972C76L,(-2L),(-8L),(-2L),0x23972C76L,0x23E3115FL},{(-1L),0xAB4AF56DL,0x6B86C82DL,(-8L),0x511436E0L,0xAB4AF56DL,0xAB4AF56DL,0x511436E0L,(-8L)},{0x7ABFC440L,0x268C6580L,0x7ABFC440L,(-8L),(-2L),0xD97D4396L,(-1L),0xD97D4396L,(-2L)},{1L,0x511436E0L,0x6B86C82DL,0xBAEE5A71L,3L,1L,0x6B86C82DL,0x6B86C82DL,1L},{0L,(-8L),0x23E3115FL,(-8L),0L,(-5L),0x34699F01L,0x23972C76L,0x34699F01L}}};
                int i, j, k;
                if ((((g_5446[5] = (0L == (safe_add_func_uint32_t_u_u(((safe_rshift_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(0xBFA76C8CL, ((safe_add_func_uint8_t_u_u(1UL, (g_496[2] , (((l_5928 == (g_1370[1] = l_5929)) || l_5928) && 0x6530C917L)))) != g_2853[0][6][6]))), 4)) | l_5930[2]), l_5928)))) ^ g_87) > 0x3BL))
                {
                    g_1370[0] = l_5931;
                }
                else
                {
                    const uint32_t l_5936 = 0xDBF7CC07L;
                    int32_t l_5958 = 0x5EEF5CB5L;
                    if ((l_5930[5] > (((safe_lshift_func_int16_t_s_s((l_5945[2][2] = (safe_lshift_func_int16_t_s_s((((((l_5913 && (((g_1370[0] > 1L) && g_240) != (g_4423[1] = (l_5936 && ((+0x68L) , ((l_5944[0][2][0] = (l_5943 = ((((l_5942[7] = ((safe_rshift_func_int16_t_s_s(g_2467, 7)) > (safe_div_func_int8_t_s_s((g_1352 , 0x03L), 4UL)))) > (-3L)) & l_5936) , 0x04C3D277L))) , 0UL)))))) & 0x7F7D98E7L) ^ 0UL) ^ l_5888) == 0xE6L), 9))), g_5210[0])) >= g_184) && g_3463)))
                    {
                        const int32_t l_5947 = 0xF90851B5L;
                        g_1370[2] = (safe_unary_minus_func_uint32_t_u(4294967288UL));
                        if (g_5512)
                            {
if (g_4475)
                            break;

                    break;}

g_2043 -= 1;


                    ;
                        ;
                    }
                    else
                    {
                        int32_t l_5969 = 0xE15EC49AL;

g_3317 += 1;


                    g_5446[5] = (0xC213CFF9L && (safe_rshift_func_uint16_t_u_s((g_98[2][1] = (g_34[0] < (0x8F714204L && ((0x27CDL > (g_3109[0] = (g_1599 = 3UL))) > (g_68 , l_5942[5]))))), (safe_mod_func_int16_t_s_s(((safe_mod_func_int8_t_s_s(0L, (safe_div_func_int16_t_s_s((safe_sub_func_uint16_t_u_u(((((l_5910 = (((g_1138 = l_5910) <= (-1L)) && g_1138)) > g_9) & 0x0EL) == l_5969), l_10)), l_5943)))) & g_1370[2]), g_573)))));

for (l_5929 = 0; (l_5929 != 18); l_5929 = safe_add_func_uint8_t_u_u(l_5929, 4))
                    {
                        uint32_t l_572 = 0xC7D5EA36L;
                        int32_t l_576 = 0xC922E228L;
                        g_1370[0] = l_6825;
                        l_5986 = (safe_lshift_func_int16_t_s_u((safe_add_func_uint32_t_u_u(l_6500, (~0xC3L))), 12));

for (l_6041 = 0; l_6041 < 3; l_6041++)
            g_1370[l_6041] = (-2L);

                    l_6280 = (l_5910 , ((safe_rshift_func_int8_t_s_u(((safe_div_func_uint32_t_u_u(1UL, (safe_lshift_func_uint8_t_u_s((BpBpBbg_6029 = (((safe_unary_minus_func_uint8_t_u((safe_rshift_func_int16_t_s_u((safe_rshift_func_uint8_t_u_s((g_506 < l_6825), (safe_sub_func_int16_t_s_s((((safe_lshift_func_int16_t_s_u(g_759, 9)) , (safe_add_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_lshift_func_int8_t_s_u((l_572 , (g_275 >= (((l_6825 < (safe_lshift_func_int16_t_s_u((0xD2672DD7L < g_5844), 10))) >= g_506) == l_5931))), 3)), l_6825)), g_1288))) | 0x5067L), l_6825)))), g_34[0])))) | 0x6831L) == 0xCB61BDDEL)), 7)))) < g_506), 0)) || l_5986));
                        l_576 = l_5910;
                    };



l_5929 += 1;


                    if (g_1370[2])
                            {
{
                    uint8_t l_2034 = 0x2AL;
                    g_1370[2] = (l_5910 >= (((safe_add_func_int16_t_s_s(((((safe_add_func_uint32_t_u_u((l_6280 = (((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u((l_5910 || ((l_6627 = 0xD31DC9A5L) > (safe_sub_func_int8_t_s_s(l_6318, ((g_154 < g_1288) , (((((l_6261 || (((safe_rshift_func_uint16_t_u_u((safe_div_func_int16_t_s_s((l_6627 = 0L), 0x5E9EL)), 0)) || l_6261) >= g_3193)) & l_2034) & l_6261) != 0xDA33A5C5L) < l_6086)))))), l_6261)) > l_2034), 0x314EL)) & 0x578DD792L) > 0x16L)), l_2034)) >= 0x2CA5L) || g_496[1]) , 8L), l_5929)) > 0x6F16L) > l_6261));
                    g_1370[0] = l_6261;
                }



{
                        uint32_t l_1819 = 0x9606BD0BL;
                        int32_t l_1866 = 0x00F4FFB0L;
                        g_240 = (((safe_add_func_int8_t_s_s((l_6136[0] = g_506), 255UL)) ^ ((((1L || ((g_1370[2] == 6L) >= (g_172 = (((l_1819 = BGBGBg_352) || (((safe_sub_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s(65530UL, (BGBGBg_352 <= (safe_sub_func_int16_t_s_s(g_98[1][4], g_3193))))), BGBGBg_352)) , g_759) != l_1819)) ^ g_2467)))) > g_240) != g_6771) > 0x47EFL)) < g_34[0]);
                        g_68 = BGBGBdg_87;
                        l_6536 = (safe_lshift_func_uint16_t_u_u((g_204 = (safe_lshift_func_int16_t_s_u((1L | (safe_lshift_func_int16_t_s_u((((l_6500 >= ((BGBGBg_352 >= ((g_2440 = (safe_lshift_func_uint16_t_u_u(k, ((safe_lshift_func_uint16_t_u_s((g_2440 , (safe_rshift_func_uint8_t_u_u(g_3193, 5))), 0)) , g_3317)))) > (safe_sub_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u((((safe_sub_func_uint32_t_u_u((safe_sub_func_int32_t_s_s((((safe_div_func_int8_t_s_s((safe_mod_func_int32_t_s_s((safe_add_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((l_5942[3] = (safe_add_func_int32_t_s_s((((safe_sub_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u(0xC44DL, l_6137)), BGBGBg_352)) < g_1370[2]) < g_469), 0xD148CE91L))), g_1288)) < 0x23L), BGBGBg_352)), l_6137)), BGBGBg_352)) , g_68) < g_469), g_34[0])), 0UL)) < BGBGBg_352) == l_6136[0]), BGBGBg_352)), (-1L))))) || (-1L))) , g_275) < l_6479[0]), g_1798[2][7]))), l_1866))), g_1798[5][2]));
                        if (k)
                            break;
                    }

                    BpBpBeg_352 += 1;


                    continue;}

;


                    ;
                        g_2853[1][5][6] = (safe_rshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u((-1L), g_573)), 3));
                    }


l_33 += 1;


                    g_3600 += 1;



{
                g_2440 = (safe_rshift_func_uint16_t_u_s(g_34[0], 3));
            }

                    g_1370[2] = (g_2422 , l_5986);
                    for (g_1599 = 0; (g_1599 <= 0); g_1599 += 1)
                    {
                        int i;
                        ;

if (l_6041)
                        {
if (l_5943)
                            ;;

                    break;}


for (g_1368 = 0; (g_1368 <= 7); g_1368 += 1)
                    {
                        uint32_t l_6789 = 0x738E9352L;

{
                        int32_t l_2330 = 0xB0B48C1AL;
                        g_204 = (safe_rshift_func_int16_t_s_s(6L, l_2330));

{
                        int16_t l_905 = 0L;
                        l_905 = (l_5910 = g_184);
                    }

                    i = l_5913;
                    }

                    l_6041 = (safe_sub_func_int8_t_s_s(((safe_add_func_uint16_t_u_u(8UL, 0x9698L)) >= ((BpBpBg_1369 > (safe_div_func_int8_t_s_s(0xEAL, l_6280))) | ((safe_add_func_uint8_t_u_u(g_34[0], (g_1369 = (safe_div_func_uint16_t_u_u(((((safe_lshift_func_uint8_t_u_u((g_5225 || g_1352), 2)) >= (safe_sub_func_int32_t_s_s((((l_6789 ^ g_1352) || g_34[0]) || g_335), g_2580[0][7]))) | g_4423[3]) | l_10), l_6774[0][7][2]))))) || g_204))), g_469));
                    };


                    ;
                        return g_98[1][3];
                    }
                }
                return g_5446[5];
            }
            for (g_506 = 8; (g_506 >= 0); g_506 -= 1)
            {
                int32_t l_6042[7];
                int i;
                for (i = 0; i < 7; i++)
                    l_6042[i] = 2L;
                                                                                       if ((!((g_2043<=1)) || ((g_3172<=1) && (g_1345 > g_3172))) )
{

g_87 += 1;


}
                    if ((l_6486 < l_6041))
                    { int32_t BhChCg_3486 = (~((((~((g_3463 && g_87))) + ((l_6536 && (-((-(g_3486))))) + g_5225)) ^ (~((~((-(((-(g_204)) | (~((g_506 && ((l_6486 * g_1345) * g_172))))))))))))));
int32_t BhChCbl_6536 = (-((((g_506 << g_1345) && (g_5225 * l_6536)) * (((((~((~(g_3463)))) * (~((g_87 && (~(l_6486)))))) & (~(g_204))) * ((~((~(g_3486)))) + g_172)) ^ BhChCg_3486))));
int32_t BhChCcg_204 = (~(((~(((g_204 + (~(BhChCg_3486))) & ((~(g_3486)) | (g_87 | (~(g_3463))))))) | (((-(g_1345)) | ((g_506 ^ g_5225) + l_6486)) * (BhChCbl_6536 * (~((g_172 << l_6536))))))));
uint32_t BhChCdg_3463 = (-((((l_6536 & ((((~(g_87)) + BhChCg_3486) ^ (-(l_6486))) + (~(g_3486)))) && (~((-((~(((BhChCbl_6536 | g_172) ^ (~(g_506)))))))))) | (((~((g_5225 && g_204))) + (~(BhChCcg_204))) & (~((g_1345 & g_3463)))))));
uint16_t BhChCeg_172 = (~(((~((((((~(BhChCg_3486)) ^ (BhChCcg_204 ^ l_6536)) >> (-((~(l_6486))))) ^ g_3463) | ((g_506 ^ g_5225) & ((-(BhChCbl_6536)) & ((~((g_204 & (BhChCdg_3463 * (~((~(g_87)))))))) ^ (g_172 & g_1345))))))) + (~((~((~(g_3486)))))))));
                               int32_t BGCGCl_6280 = (~(((~(((((g_172 + (~(l_6823))) - (~(((~(l_6486)) + (~(l_6137)))))) | (~((~(g_573))))) && ((~((g_1369 && l_5913))) | (~(((~(g_87)) && g_335))))))) - (~(l_6280)))));
uint32_t BGCGCbl_6137 = (~((((~(((~(l_6280)) + g_172))) / ((g_335 & BGCGCl_6280) - (g_87 ^ l_6137))) && (~(((l_6486 ^ l_6823) & (~((l_5913 / (g_1369 && g_573))))))))));
int8_t BGCGCcl_6823 = (~((((~((~(((((g_87 + l_6823) + (~(l_6137))) | BGCGCl_6280) >> g_172))))) - (((~(g_335)) & (~((~(l_5913))))) + (((~(l_6280)) ^ g_573) & ((~((~(l_6486)))) & (~(BGCGCbl_6137)))))) + g_1369)));
int8_t BGCGCdl_6486 = (~(((~((((BGCGCcl_6823 - (~(g_87))) << (BGCGCl_6280 & (~((l_5913 & (~(l_6823))))))) && (~(((~((((l_6280 | BGCGCbl_6137) >> l_6486) && (~(((~((~(g_573)))) >> (g_335 / g_1369))))))) + g_172)))))) + (~((~(l_6137)))))));
int16_t BGCGCel_5913 = (~(((((l_6280 ^ ((l_6823 - g_1369) | ((~(g_172)) - (l_6486 && BGCGCdl_6486)))) ^ (BGCGCcl_6823 + (l_5913 && (~(g_87))))) | ((BGCGCbl_6137 / (~(BGCGCl_6280))) >> (~((~((g_573 && l_6137))))))) ^ g_335)));
uint16_t BGCGCfg_172 = (~(((~((((~((g_87 && g_335))) + (l_5913 - ((BGCGCbl_6137 | ((g_172 - BGCGCdl_6486) & BGCGCcl_6823)) & ((l_6823 && (BGCGCel_5913 >> BGCGCl_6280)) | (l_6486 - g_573))))) / (~((~((~(l_6137))))))))) ^ ((~((~(g_1369)))) | (~((~(l_6280))))))));
if((BGCGCdl_6486 > BGCGCl_6280)){
BGCGCl_6280 = l_6280;
BGCGCbl_6137 = l_6137;
BGCGCcl_6823 = l_6823;
BGCGCdl_6486 = l_6486;
BGCGCel_5913 = l_5913;
BGCGCfg_172 = g_172;
l_6280 = (~((((((~(g_87)) - (g_335 >> BGCGCdl_6486)) && (~(g_1369))) & (~((~(BGCGCfg_172))))) | ((((~(BGCGCcl_6823)) & ((l_6486 >> g_573) & (((~(BGCGCel_5913)) / l_6137) - l_5913))) && (~(l_6823))) >> (~(((~(((BGCGCbl_6137 / (~(g_172))) + l_6280))) | BGCGCl_6280)))))));
l_6137 = (~((((((BGCGCcl_6823 | ((l_6823 | (g_1369 - l_6137)) & l_6280)) + ((~((~(g_172)))) | (~((~(BGCGCl_6280)))))) | ((~((BGCGCdl_6486 ^ (~(g_573))))) ^ (g_87 && l_5913))) && (~(((BGCGCbl_6137 && l_6486) ^ (BGCGCel_5913 + BGCGCfg_172))))) & (~((~(g_335)))))));
l_6823 = (~(((~((BGCGCfg_172 ^ (~((l_6280 - l_6486)))))) - (~(((~((~(((~((((~(l_6137)) & BGCGCcl_6823) - g_172))) && (~((~(g_335))))))))) - ((~((~(l_5913)))) + ((~((((~(g_573)) + (BGCGCbl_6137 - BGCGCl_6280)) && BGCGCdl_6486))) & (~((((BGCGCel_5913 | g_87) && g_1369) + l_6823)))))))))));
l_6486 = (~(((~(g_172)) & ((~((((~(((~(BGCGCbl_6137)) ^ g_573))) + BGCGCdl_6486) >> (~(BGCGCcl_6823))))) / ((((l_6486 + BGCGCfg_172) | (l_6280 & ((~(g_87)) & BGCGCel_5913))) - (~(((~(l_6137)) ^ g_1369)))) & ((~((l_6823 - (BGCGCl_6280 | l_5913)))) + g_335))))));
l_5913 = (~(((~((~(((((~((~((l_6280 & l_5913))))) | g_172) - (~(BGCGCdl_6486))) && BGCGCl_6280))))) ^ ((~(((~((~((~(l_6486)))))) & ((~(((~(((BGCGCfg_172 << l_6823) - (~((~(g_573))))))) | (BGCGCel_5913 & BGCGCcl_6823)))) + (l_6137 >> ((~(g_1369)) && BGCGCbl_6137)))))) | (g_87 + g_335)))));
g_172 = (~(((((~((~(((~(l_6823)) && BGCGCel_5913))))) + (~(g_573))) / ((~(BGCGCbl_6137)) + BGCGCdl_6486)) / (~((((~(g_172)) && (~((g_335 / g_87)))) ^ (~((~(((((BGCGCcl_6823 ^ g_1369) && BGCGCl_6280) ^ ((~(l_6137)) - l_6280)) / ((l_6486 - (~(l_5913))) | (~(BGCGCfg_172))))))))))))));
if(((BGCGCbl_6137 < l_6823) || (!BGCGCdl_6486))){
printf("l_6280=%lld\n", (long long)l_6280);
goto LABEL_hChCg;
}
if(!(g_87)){
printf("l_6137=%llu\n", (unsigned long long)l_6137);
l_6823 = (~((((l_6137 >> (~(((~(g_573)) / BGCGCcl_6823)))) / ((~(((~(g_172)) / (((l_6280 ^ BGCGCbl_6137) ^ (l_6823 << BGCGCfg_172)) + (BGCGCel_5913 & g_335))))) << (~((g_1369 >> ((BGCGCdl_6486 | l_6486) >> (~(g_87)))))))) - (~((l_5913 | (~(BGCGCl_6280))))))));
goto LABEL_pBpBg;
}
if(!((l_5913 > BGCGCel_5913))){
printf("l_6823=%lld\n", (long long)l_6823);
BGCGCbl_6137 = (~((((~((l_6486 && (BGCGCdl_6486 + BGCGCbl_6137)))) ^ ((~(l_6823)) << (~(g_172)))) ^ ((((~(((~((~(l_5913)))) | (~(g_1369))))) - (~((g_87 / (g_335 - (~(((~(BGCGCel_5913)) - BGCGCl_6280)))))))) & (~(((l_6137 + BGCGCcl_6823) ^ BGCGCfg_172)))) ^ (~((~(((~(l_6280)) >> g_573)))))))));
continue;
}
if(((BGCGCcl_6823<=-1) && (!BGCGCcl_6823))){
printf("l_6486=%lld\n", (long long)l_6486);
BGCGCl_6280 = (~(((g_573 << (~(((l_6486 ^ (~(BGCGCel_5913))) | BGCGCfg_172)))) + (~(((~(g_172)) | (~(((~(l_6280)) - ((~((~((l_6137 - (BGCGCl_6280 && (~(g_335)))))))) >> (((l_5913 - g_1369) + (l_6823 | BGCGCbl_6137)) >> (~((g_87 ^ (BGCGCcl_6823 | (~(BGCGCdl_6486)))))))))))))))));
BGCGCfg_172 = (~(((~((~(((~(((((g_1369 & g_172) && (BGCGCfg_172 & (~(BGCGCcl_6823)))) ^ BGCGCel_5913) << (~((l_6486 ^ BGCGCl_6280)))))) | BGCGCbl_6137))))) - ((~(((~(l_6137)) | ((BGCGCdl_6486 | g_87) - (~(g_335)))))) ^ ((g_573 >> l_6823) & (~((~(((~(l_5913)) - (~(l_6280))))))))))));
l_5913 = (~(((g_87 >> (g_573 && BGCGCbl_6137)) / ((~(((~(BGCGCl_6280)) & (((~(g_1369)) >> (l_5913 & ((~(l_6486)) ^ g_335))) << l_6823)))) && (~((BGCGCel_5913 + ((~((l_6137 >> g_172))) && ((~((BGCGCfg_172 | (~(l_6280))))) && ((~(BGCGCcl_6823)) | (~((~(BGCGCdl_6486))))))))))))));
}
if(!(l_6280)){
printf("l_5913=%lld\n", (long long)l_5913);
BGCGCfg_172 = (~(((~(((~(l_5913)) & ((g_87 ^ (g_172 >> BGCGCbl_6137)) - ((~(BGCGCel_5913)) & ((~((~(g_1369)))) && (l_6137 | BGCGCl_6280))))))) << (~(((~(((~((~(g_335)))) | ((~((l_6823 >> l_6280))) | BGCGCcl_6823)))) - ((BGCGCdl_6486 << (~(g_573))) | (~((~((l_6486 ^ BGCGCfg_172))))))))))));
goto LABEL_hChCg;
}
if(((BGCGCfg_172 < BGCGCl_6280) || (BGCGCl_6280>0))){
printf("g_172=%llu\n", (unsigned long long)g_172);
BGCGCfg_172 = (~(((~(((~(BGCGCdl_6486)) / (~((((~((~(BGCGCel_5913)))) & (((((g_573 && BGCGCcl_6823) / BGCGCfg_172) & g_1369) >> (~(l_6137))) - ((BGCGCbl_6137 | (~(g_335))) - g_172))) && l_6280)))))) | ((~((l_6823 >> BGCGCl_6280))) | (~((l_6486 | (l_5913 ^ g_87))))))));
l_6823 = (~(((BGCGCl_6280 | ((~(((g_172 & (l_6823 && g_573)) << (BGCGCdl_6486 && g_1369)))) >> ((l_6137 && (~(l_6486))) - (~((~((g_335 - BGCGCcl_6823)))))))) & ((~((~(g_87)))) + (((BGCGCfg_172 - (~(BGCGCbl_6137))) >> BGCGCel_5913) & ((~(l_6280)) - (~(l_5913))))))));
}
}
l_6280 = BGCGCl_6280;
l_6137 = BGCGCbl_6137;
l_6823 = BGCGCcl_6823;
l_6486 = BGCGCdl_6486;
l_5913 = BGCGCel_5913;
g_172 = BGCGCfg_172;

                    if(!(!(BhChCdg_3463))){
BhChCg_3486 = g_3486;
BhChCbl_6536 = l_6536;
                                    if ((l_5929<2708735753U) )
{

if (g_2440) printf("index = [%d]\n", l_6280);

}
                    BhChCcg_204 = g_204;
BhChCdg_3463 = g_3463;
BhChCeg_172 = g_172;
g_3486 = (~(((g_3486 * (((BhChCg_3486 && g_172) * BhChCdg_3463) ^ BhChCcg_204)) ^ ((~((g_3463 | g_87))) & (~((((~((~(l_6536)))) && ((g_1345 ^ BhChCeg_172) << g_506)) & (-((BhChCbl_6536 && ((g_204 | l_6486) ^ g_5225)))))))))));
LABEL_hChCf: l_6536 = (~(((-((((BhChCeg_172 ^ (~((~(g_1345))))) + (g_5225 && BhChCg_3486)) ^ (g_3463 >> (l_6486 + (-(BhChCbl_6536))))))) && ((~(((~((l_6536 * g_204))) && (BhChCdg_3463 && g_172)))) && (g_3486 | (BhChCcg_204 * (~((g_87 && g_506)))))))));
g_204 = (~((((~(((~(((-(BhChCg_3486)) >> (BhChCcg_204 * BhChCbl_6536)))) & (~(((~((l_6536 && g_3486))) | (~(l_6486)))))))) + (~(((~(g_3463)) & (~(g_506)))))) && (~((~(((BhChCeg_172 ^ (g_204 | g_5225)) ^ (~(((-(g_172)) ^ ((~((BhChCdg_3463 + g_87))) & g_1345))))))))))));
g_3463 = (-(((-(((BhChCcg_204 | g_5225) && g_3486))) * (~((((-(g_506)) ^ ((-(((g_3463 && (((l_6486 * BhChCg_3486) * g_172) * ((~(BhChCbl_6536)) ^ (~(l_6536))))) >> (-((-(BhChCeg_172))))))) && (-(((~(g_87)) && g_1345))))) & (~(((~((~((~((-(BhChCdg_3463)))))))) ^ g_204)))))))));
LABEL_hChCg: g_172 = (~((((BhChCg_3486 * g_3463) << (-(g_1345))) ^ (BhChCeg_172 && (~((((BhChCbl_6536 >> g_172) + (~((-((l_6536 * (l_6486 + BhChCcg_204))))))) + ((~((-((g_204 * ((g_87 * BhChCdg_3463) << g_506)))))) && (-((g_5225 & (~(g_3486)))))))))))));
if((!BhChCdg_3463)){
printf("g_3486=%lld\n", (long long)g_3486);
continue;
}
if((!BhChCeg_172)){
printf("l_6536=%lld\n", (long long)l_6536);

{
        transparent_crc(g_34[l_6280], "g_34[l_6280]", l_6762);
        if (l_6762) printf("index = [%d]\n", l_6280);

    }

                    break;
}
if((g_506 < g_5225)){
printf("g_204=%lld\n", (long long)g_204);
l_6536 = (-(((~(((BhChCcg_204 && (-((BhChCg_3486 + (~((~((-(g_506)))))))))) & (((-(g_204)) + (-((~((((-(((~(l_6536)) & (g_87 ^ g_3486)))) && g_5225) + g_1345)))))) + (~(((~(((-(BhChCdg_3463)) | (-(g_172))))) | (~((g_3463 & (BhChCbl_6536 & BhChCeg_172))))))))))) >> (-(l_6486)))));
g_172 = (~((((-((~(g_3486)))) & ((~((BhChCbl_6536 && ((~((BhChCeg_172 && BhChCcg_204))) * (g_204 | BhChCg_3486))))) + (g_87 << ((~(((-((~(g_1345)))) + g_172))) ^ ((~(g_3463)) + g_5225))))) | (~(((BhChCdg_3463 >> l_6536) << ((-(g_506)) ^ l_6486)))))));
BhChCbl_6536 = (~((((~((~(BhChCg_3486)))) >> (((~((BhChCcg_204 + l_6536))) + (-((g_3463 && (~(g_172)))))) + (~(((BhChCdg_3463 >> BhChCeg_172) ^ (g_204 << g_3486)))))) & ((g_506 << ((-(g_87)) ^ g_1345)) << ((-(l_6486)) << (~(((~(g_5225)) && BhChCbl_6536))))))));
}
if((((!l_6486) && (g_1345 > l_6486)) || ((l_6536 > g_5225) && (!BhChCeg_172)))){
printf("g_3463=%llu\n", (unsigned long long)g_3463);
continue;
}
if(((g_5225 > g_506) || (g_87 < g_506))){
printf("g_172=%llu\n", (unsigned long long)g_172);
BhChCbl_6536 = (-((((g_87 & (-(BhChCdg_3463))) >> ((g_3463 & (g_3486 & (-(g_5225)))) >> (~(((~((g_204 * g_1345))) << l_6486))))) ^ (((BhChCcg_204 * (l_6536 + ((BhChCg_3486 ^ BhChCbl_6536) >> g_506))) & g_172) + (-((~((-(BhChCeg_172))))))))));
continue;
}
}
g_3486 = BhChCg_3486;
l_6536 = BhChCbl_6536;
g_204 = BhChCcg_204;
g_3463 = BhChCdg_3463;
g_172 = BhChCeg_172;

                    if ((((g_5210[0] = l_5835[g_506]) , ((safe_add_func_uint16_t_u_u((((safe_sub_func_uint8_t_u_u((((l_5835[g_506] , l_5835[g_506]) & g_34[0]) || (0xEEL & g_759)), (((safe_sub_func_int16_t_s_s(l_10, (safe_sub_func_int8_t_s_s(l_5929, g_897)))) <= g_2440) || 0x251BEB3CL))) , l_5835[0]) , g_87), l_5835[g_506])) < 0xA8CC175AL)) & l_5945[2][2]))
                {
                    uint32_t l_6025 = 1UL;
                    int16_t l_6026 = 0x85CEL;
                    int32_t l_6027 = 0x12859164L;
                                                        if ((!g_573) )
{

{
                int i;
                return g_13[l_6536];
            }

}
                    for (g_3193 = 0; (g_3193 <= 3); g_3193 += 1)
                    {
                        int i, j;
                                                            while ((l_6147 > l_6486) )
{

{
                        uint8_t l_1049 = 0x11L;
                        int32_t l_1055[7] = {0L,0L,0L,0L,0L,0L,0L};
                        int i;
                        l_1049 = (0x70L && (BpBpBeg_352 != (g_98[3][3] <= (safe_mod_func_int8_t_s_s((safe_div_func_uint32_t_u_u((0xC84EL < (BhChCcg_204 , (((safe_rshift_func_int16_t_s_u(((((safe_mod_func_uint32_t_u_u(3UL, (safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((g_759 = ((safe_add_func_uint32_t_u_u(0UL, (safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_s((((g_506 = ((safe_div_func_uint32_t_u_u((4294967293UL == ((0x53D2L > l_6160) | l_6160)), l_6160)) != 0xF29CL)) & BhChCeg_172) , g_2852), 5)), g_2852)))) ^ BGBGBbg_335)) || g_1369), 6)), 255UL)))) == 0xFEB37081L) != l_6086) | l_5943), g_2852)) , g_2852) & g_2852))), g_6771)), g_1369)))));
                        BhChCbl_6536 = (l_1049 , (((l_6280 = (g_2852 || ((((safe_div_func_int32_t_s_s(((0x56D9L && l_5913) >= ((g_2852 > ((1UL < (((((l_1055[0] = (0x1FL || (g_1369 = (+(safe_mod_func_uint8_t_u_u(252UL, (g_1138 , l_6280))))))) >= g_3463) <= 1L) & l_5913) & g_2852)) || g_2852)) > BhChCcg_204)), (-2L))) > g_98[1][3]) | l_5913) ^ 0xA113L))) , l_5913) < g_1138));
                    }

}
                    g_2580[g_3193][(g_506 + 1)] = ((0xFA952407L || (safe_div_func_uint32_t_u_u(((l_6027 = (((((g_2580[g_3193][(g_506 + 1)] >= (safe_mod_func_uint16_t_u_u(((safe_add_func_int8_t_s_s(g_5210[0], ((g_2580[g_3193][(g_506 + 1)] > (safe_sub_func_uint16_t_u_u(((l_5986 = (g_4475 = (g_3109[0] ^ (l_6025 , 0xF7L)))) < (g_35 != l_5945[6][0])), 0x4801L))) ^ l_33))) <= g_87), g_3486))) , (-1L)) || l_6026) | g_34[0]) , 0x78E3L)) < g_4423[1]), g_3109[1]))) , g_2580[g_3193][(g_506 + 1)]);
                                                            if ((g_1138 > g_6029) )
{

;


}
                    g_5446[3] = (safe_unary_minus_func_uint8_t_u(g_6029));
                    }
                                                        if ((g_3193>4) )
{


;

                    if (g_204)
                            {
l_6486 -= 1;


                    break;}

}
                    for (g_2852 = 3; (g_2852 <= 8); g_2852 += 1)
                    {
                        uint32_t l_6040 = 0UL;
                        int i;
                        g_204 = ((l_5943 , (safe_div_func_int32_t_s_s(g_573, ((((((((safe_rshift_func_uint8_t_u_s(((g_5446[6] | (((g_34[0] & (((safe_div_func_uint32_t_u_u((safe_rshift_func_int8_t_s_u(((!0L) , (l_5835[g_506] = ((g_2853[0][6][6] = ((+g_496[2]) , ((l_5928 >= l_6040) || (g_759 != 0x71C8E275L)))) < l_5928))), g_98[1][3])), g_1138)) , g_240) < l_6040)) , l_6041) ^ l_5929)) | 3L), 4)) || l_6027) ^ l_6042[1]) < l_10) , 251UL) && l_5913) > g_4475) || 0xB5L)))) > 0xE0FCL);
                        if (l_5913)
                            break;
                    }
                }
                else
                {
                    int16_t l_6071 = 0xE140L;
                    l_6042[1] = (safe_sub_func_uint8_t_u_u(((safe_lshift_func_int8_t_s_u(((safe_div_func_int32_t_s_s((((g_2440 ^ (((((safe_mod_func_int32_t_s_s(((g_6029 | (safe_sub_func_int32_t_s_s(((safe_div_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_s(0x263FL, 13)) , (safe_sub_func_uint32_t_u_u((safe_mod_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_s(((g_1345 & g_506) ^ ((safe_div_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_s((g_3109[0] = 0x2E3EL), ((safe_mod_func_uint32_t_u_u((((l_6042[0] > g_2422) | ((((safe_lshift_func_int16_t_s_s(((g_1288 && 0x9CL) , g_1370[2]), g_2853[0][6][6])) == g_172) && 1L) | 0L)) & g_3317), 3UL)) < l_5945[2][2]))) != g_4475), g_472)) >= g_1345)), 11)) && l_6071), l_5835[0])), l_6071))) , 0UL) || 0x814EF7DDL) >= 0xCEL), (-3L))) ^ l_5888), 3L))) & l_6042[1]), g_3935[3][2])) <= l_6042[6]) ^ g_506) && 9UL) && 8UL)) , 255UL) >= 4UL), l_5945[2][2])) | g_1345), l_6042[1])) > g_1369), 0xB0L));
                    for (g_35 = 5; (g_35 >= 0); g_35 -= 1)
                    {
                        ;
                        ;

g_4475 += 1;


                    if (g_3109[0])
                            continue;
                    }

{
            transparent_crc(g_98[l_6762][l_6762], "g_98[l_6762][l_6762]", l_6160);
            if (l_6160) printf("index = [%d][%d]\n", l_6762, l_6762);

        }

                    for (g_184 = 0; (g_184 <= 3); g_184 += 1)
                    {
                        int16_t l_6079 = 1L;
                        if (l_5888)
                            {
;

                    break;}
                        g_2853[0][6][6] = (safe_sub_func_int8_t_s_s(0L, (l_6071 ^ (safe_sub_func_uint16_t_u_u(l_6079, g_3463)))));


                    }

for (g_5844 = 6; (g_5844 > 5); --g_5844)
                    {
                        uint32_t l_666 = 4294967292UL;
                        int32_t l_677 = 0xC2919148L;
                        g_573 = (g_6428 == (safe_lshift_func_int16_t_s_u((l_666 >= 0xCA1FA15DL), 10)));
                        g_506 = (l_33 = (~(!(g_6428 <= (((0xBD3024CCL || (0x0624L == l_6825)) <= 0UL) > (g_1369 == (safe_add_func_int16_t_s_s(((l_6160 = (((safe_mod_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((l_677 = 1UL), ((safe_div_func_uint8_t_u_u((l_6825 < (l_666 || l_6825)), 0x7AL)) > l_6825))), 0xCE57L)) & 0xC6L) && 1L)) >= l_6825), l_5986))))))));
                    };


                    if (g_759)
                        continue;
                }}
                                                    while ((l_6825>68) )
{

;


}
                    l_33 = ((safe_div_func_int8_t_s_s((safe_add_func_uint16_t_u_u(((safe_add_func_int16_t_s_s(0x1E32L, l_6086)) != l_5945[2][2]), (g_1684[0] = 0x5BE7L))), 0x1EL)) , l_6042[1]);
            }
        }
                                            if ((l_6486>24) )
{

{

for (l_5910 = 0; l_5910 < 3; l_5910++)
                g_1370[l_5910] = (-5L);

                    g_2440 = (safe_rshift_func_uint16_t_u_s(g_34[0], 3));
            }

}
                    if ((g_13[4] || ((safe_rshift_func_int8_t_s_u((l_10 = (safe_mod_func_uint32_t_u_u((l_6074 , g_3935[1][3]), g_506))), (((((safe_add_func_int32_t_s_s(((l_5986 = (safe_rshift_func_int16_t_s_u((-1L), 10))) , (safe_add_func_int8_t_s_s(((((-2L) >= g_35) && 0L) | ((safe_lshift_func_uint16_t_u_s((+(safe_add_func_int32_t_s_s(((g_3600 = (safe_rshift_func_int8_t_s_u(((safe_mod_func_int32_t_s_s((safe_add_func_int8_t_s_s((safe_div_func_uint16_t_u_u((((((safe_div_func_int8_t_s_s((g_2422 = (+((safe_lshift_func_uint8_t_u_s(g_13[3], 7)) == l_33))), l_5986)) | l_5943) , 255UL) ^ g_3193) | l_6086), 65533UL)), 0L)), 0x80E5C42AL)) == g_35), l_33))) , l_5913), 0L))), g_4475)) || l_5888)), (-7L)))), 0xFE00AAE6L)) | g_1798[5][2]) && 6L) | 3L) | l_6086))) | 0x6A183853L)))
        {
            int16_t l_6125 = 8L;
            uint32_t l_6135 = 18446744073709551610UL;
            int32_t l_6138 = 5L;
            int8_t l_6180 = 0L;
            int32_t l_6181 = 0xE1C683ACL;
            uint16_t l_6189 = 65531UL;
            int32_t l_6260 = 0xDB8BE864L;
            int8_t l_6315 = 0x66L;
            int32_t l_6342 = 0x65AEC415L;
            uint32_t l_6400 = 0x7237AF67L;
            l_6138 = (safe_lshift_func_int16_t_s_s(((safe_add_func_int32_t_s_s((((((l_5929 & l_5888) == ((safe_mod_func_int16_t_s_s((((1UL || ((g_3600 = ((g_1368 = ((((safe_sub_func_int16_t_s_s(((safe_div_func_uint32_t_u_u((l_33 = l_6125), g_275)) > g_5210[0]), (safe_add_func_int8_t_s_s(l_5986, (l_5943 = (safe_div_func_int8_t_s_s((((((safe_unary_minus_func_int16_t_s(((l_5910 = ((1UL || (safe_mod_func_uint8_t_u_u(((safe_div_func_uint8_t_u_u(((l_6136[1] = ((l_6135 <= l_5943) && g_13[4])) == l_5913), l_6135)) , g_5512), g_2853[0][6][6]))) & l_6125)) , 0x183CL))) != g_5225) || 255UL) & g_35) < l_6125), g_2467))))))) <= l_5986) , 4294967286UL) != 0xEE33405DL)) , 0xBEL)) != g_68)) , g_2580[0][7]) && 0x96L), l_6135)) , l_6137)) | 4L) , (-1L)) < g_1370[1]), 0x68F6D786L)) && g_3172), g_3193));
            for (g_172 = 0; (g_172 <= 0); g_172 += 1)
            {
                uint16_t l_6166 = 0xFB36L;
                uint32_t l_6212 = 8UL;
                int32_t l_6239 = 0xC0CB8384L;
                int32_t l_6317 = 0xD67785DCL;
                int8_t l_6399 = 0L;
                int i;
                                                   if ((g_335<=184))
                    g_2580[0][7] = (((((safe_lshift_func_uint16_t_u_s(g_34[g_172], l_6137)) < g_3109[1]) < g_2467) >= (safe_rshift_func_uint16_t_u_s(0x7203L, ((((g_1369 = 1UL) | l_6138) >= (safe_lshift_func_int16_t_s_u(((safe_rshift_func_int16_t_s_s(((l_6147 = 251UL) >= (safe_mod_func_int8_t_s_s((safe_sub_func_uint8_t_u_u(g_4475, l_5986)), g_98[1][3]))), g_34[g_172])) , g_13[4]), 6))) || l_6135)))) | g_34[g_172]);
                                                   if ((l_6400 && (l_10 > g_1352)))
                    if ((((l_6152 , 0x97L) < ((+(safe_add_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_s(g_34[g_172], 5)) , (65535UL != (safe_add_func_uint8_t_u_u(255UL, (l_6160 , g_5210[0]))))), (safe_rshift_func_int8_t_s_u(((safe_lshift_func_uint16_t_u_u(((l_6138 & ((~g_3109[0]) | g_1684[0])) , l_6166), l_6167)) , 0L), g_1798[3][1]))))) > l_6166)) || g_982))
                {
                    uint16_t l_6174[4];
                    int32_t l_6213 = 0x5BA6D280L;
                    int i;
                    for (i = 0; i < 4; i++)
                        { int32_t BhChChl_6260 = (~((((~(((g_204 | (g_87 && g_5512)) & l_6260))) + (~((l_6536 && l_6261)))) && ((g_982 * (~(l_6399))) && (g_3172 & g_5225)))));
int8_t BhChCil_6399 = (-((((~(g_5225)) + (-((~((l_6536 | l_6260)))))) | ((g_87 & (((g_204 ^ l_6261) && BhChChl_6260) | (~((-((g_3172 + g_5512))))))) ^ (~((-((g_982 & l_6399)))))))));
int32_t BhChCjl_6536 = (~(((~(l_6261)) + ((l_6536 & g_5225) << ((BhChChl_6260 ^ (~(g_204))) & ((~((g_982 * ((l_6260 | g_87) && (l_6399 * BhChCil_6399))))) << ((~(g_3172)) && (~(g_5512)))))))));
uint32_t BhChCkg_982 = (-(((~((-((g_204 + BhChChl_6260))))) && ((BhChCjl_6536 | (((g_87 + (l_6536 | (l_6399 + (~(g_5225))))) ^ (((~(l_6260)) * (~(g_982))) & (g_5512 * (~(BhChCil_6399))))) + (~(l_6261)))) ^ g_3172))));
int8_t BhChClg_3172 = (-(((~(((~((-((-((~(g_5225)))))))) * (~((((l_6399 ^ (BhChCil_6399 + l_6260)) & l_6536) && ((~((g_204 & (g_5512 & (g_87 + (g_982 + g_3172)))))) + (~(l_6261))))))))) & (~(((~(BhChCjl_6536)) && ((-((-(BhChChl_6260)))) | BhChCkg_982)))))));
LABEL_hChCm: if(!((BhChClg_3172 < g_3172))){
BhChChl_6260 = l_6260;
BhChCil_6399 = l_6399;
BhChCjl_6536 = l_6536;
BhChCkg_982 = g_982;
BhChClg_3172 = g_3172;
l_6260 = (~(((-(((~((-(g_3172)))) && ((~(g_87)) * (~(g_204)))))) && ((~((~(((~((BhChChl_6260 | (~(g_5225))))) * (~(BhChClg_3172))))))) * (((l_6260 ^ BhChCjl_6536) * ((g_5512 ^ BhChCkg_982) + l_6261)) & ((l_6536 | (g_982 ^ BhChCil_6399)) >> l_6399))))));
l_6399 = (~((((-(g_5512)) & (~((BhChClg_3172 + (-((-(BhChCil_6399)))))))) | ((BhChCkg_982 | g_982) << ((((~(l_6536)) * g_87) && (~(((((-(((-(l_6399)) | l_6260))) * g_5225) | g_3172) ^ BhChChl_6260)))) + ((l_6261 * BhChCjl_6536) >> g_204))))));
l_6536 = (~(((-((-((((-((~((~(BhChClg_3172)))))) && (((((-((g_204 & BhChChl_6260))) & g_87) && (BhChCkg_982 >> BhChCjl_6536)) & ((~(l_6536)) & (~(g_3172)))) ^ (~(g_982)))) ^ (~((g_5512 && BhChCil_6399)))))))) | ((-((~((~(l_6261)))))) << (~((~(((~(g_5225)) && (l_6260 + l_6399))))))))));
g_982 = (~((((-((~(l_6261)))) & (~(BhChCjl_6536))) ^ ((~((-((~((g_5225 + BhChChl_6260))))))) ^ ((~((((g_204 * (g_982 ^ g_87)) ^ (((~(BhChCkg_982)) + l_6399) && l_6260)) >> ((-(BhChClg_3172)) && (~(g_3172)))))) + (~((~((g_5512 | (BhChCil_6399 << l_6536)))))))))));
g_3172 = (~((((~((~(BhChCil_6399)))) * ((g_204 + (g_5512 && BhChCkg_982)) + (g_5225 + (~(((g_982 && l_6536) | ((-(l_6261)) | BhChChl_6260))))))) && (~((-(((BhChClg_3172 >> (((~(g_3172)) | l_6260) && ((~(g_87)) + l_6399))) << BhChCjl_6536))))))));
if((!BhChClg_3172)){
printf("l_6260=%lld\n", (long long)l_6260);
goto LABEL_GBGBg;
}
if((g_5225 > g_5512)){
printf("l_6399=%lld\n", (long long)l_6399);
continue;
}
if((!g_87)){
printf("l_6536=%lld\n", (long long)l_6536);
break;
}
if((!g_5512)){
printf("g_982=%llu\n", (unsigned long long)g_982);
continue;
}
if((!l_6261)){
printf("g_3172=%lld\n", (long long)g_3172);
break;
}
}
l_6260 = BhChChl_6260;
l_6399 = BhChCil_6399;
l_6536 = BhChCjl_6536;
g_982 = BhChCkg_982;
g_3172 = BhChClg_3172;

                    if ((((g_472 < g_68) || g_68) && !((g_472 < g_2852))))
                    { if (g_6771)
                    l_6174[i] = 65527UL;}}
                                                   uint32_t BGBGBhg_76 = (~((((~((((~(g_3486)) | ((~(g_472)) || l_6486)) | ((l_6189 / l_6500) % (~(g_573)))))) || ((~((g_3463 & l_6135))) | (~((~(g_76)))))) << (~(g_275)))));
int32_t BGBGBig_275 = (~(((((~((~(((~((g_472 || l_6500))) | (~((~(g_76))))))))) << ((~((~(((~(g_3486)) | g_573))))) || (~(((~(l_6189)) & (~((g_275 / g_3463)))))))) % l_6135) | (~((l_6486 | BGBGBhg_76))))));
int32_t BGBGBjg_573 = (~(((((~((l_6135 / l_6189))) / (g_472 | g_275)) / (~((((~((~((g_3463 || (BGBGBhg_76 | l_6486)))))) || (~((g_76 || g_3486)))) || (~(g_573)))))) / (~((~((BGBGBig_275 || l_6500))))))));
uint8_t BGBGBkg_472 = (~(((~((((BGBGBjg_573 | (BGBGBig_275 | g_275)) ^ g_76) % (g_472 / g_573)))) % ((~(((~(l_6135)) % ((~(g_3486)) ^ (g_3463 % (~(BGBGBhg_76))))))) || ((~(l_6486)) & (l_6500 % l_6189))))));
uint32_t BGBGBlg_3463 = (~((((~((~(g_76)))) | ((~((~((~(BGBGBhg_76)))))) ^ ((~(((g_275 & BGBGBkg_472) ^ (BGBGBjg_573 & BGBGBig_275)))) / ((l_6135 & (g_3486 | (~(l_6486)))) || ((~(l_6189)) ^ l_6500))))) / ((~((g_573 || g_3463))) ^ g_472))));
int32_t BGBGBmg_3486 = (~((((~(((~(((~((~(g_3486)))) | ((((~(g_76)) & g_275) | (g_472 || l_6500)) & BGBGBig_275)))) || (~(l_6486))))) | (~(((~(((~(l_6189)) || BGBGBjg_573))) | (~(((~(g_3463)) / ((~((~(((~((~(BGBGBhg_76)))) / (BGBGBlg_3463 || (~(g_573)))))))) | BGBGBkg_472)))))))) & (~(l_6135)))));
if(!(!(l_6189))){
BGBGBhg_76 = g_76;
BGBGBig_275 = g_275;
                                    if (!((g_3193 > g_6029)) )
{

{
                        if (l_6317)
                            break;
                    }

}
                    BGBGBjg_573 = g_573;
BGBGBkg_472 = g_472;
                                    if ((g_469>1U) )
{

for (g_4689 = 0; (g_4689 >= 0); g_4689 -= 1)
                    {
                        int8_t l_4920 = 0xD6L;
                        g_2580[0][7] = (((l_5986 & (safe_unary_minus_func_int32_t_s(g_759))) > (0L != g_2440)) && BpBpBbg_6029);
                        BGBGBcg_1368 = l_4920;
                    };


}
                    BGBGBlg_3463 = g_3463;
BGBGBmg_3486 = g_3486;
g_76 = (~(((~((((((~((BGBGBkg_472 || BGBGBjg_573))) ^ (~(l_6500))) & (~((~(BGBGBmg_3486))))) || g_3486) / l_6135))) | (~((((~((g_76 || l_6189))) || (g_472 || (~((g_275 % BGBGBig_275))))) / ((((BGBGBlg_3463 / g_3463) / BGBGBhg_76) ^ l_6486) << g_573)))))));
LABEL_GBGBn: g_275 = (~((((((g_573 ^ g_76) | (~(l_6189))) || (~((~(BGBGBjg_573))))) || (((~(l_6135)) / BGBGBig_275) % ((~((~(BGBGBhg_76)))) || (BGBGBmg_3486 >> (g_472 || g_275))))) || ((((~(l_6500)) | (g_3486 || l_6486)) / BGBGBlg_3463) || (~(((~((~(BGBGBkg_472)))) / (~(g_3463)))))))));
g_573 = (~(((~((((g_3486 | BGBGBmg_3486) & BGBGBhg_76) & (~(((BGBGBjg_573 & (l_6135 ^ l_6486)) || (g_3463 | (BGBGBlg_3463 ^ g_472)))))))) << (~(((~((l_6189 % BGBGBkg_472))) ^ (~(((~(g_573)) % ((~(l_6500)) | ((~(g_275)) || (g_76 | BGBGBig_275))))))))))));
                               uint32_t BhChCnl_6261 = (~(((((~(l_6399)) + g_759) | (~((~(g_2440))))) + ((-(((~((l_6261 + (~(g_1369))))) ^ (~(l_6260))))) && ((-((l_6167 | l_6600))) && (l_6135 && g_335))))));
int8_t BhChCol_6399 = (-(((((-((~(l_6399)))) ^ (~(l_6600))) * (~((l_6260 & (((~(l_6135)) & g_1369) && BhChCnl_6261))))) ^ ((l_6261 & (g_335 * (-(l_6167)))) & (g_759 | g_2440)))));
uint8_t BhChCpg_1369 = (~(((~((((l_6600 | (l_6260 && BhChCnl_6261)) & (~((~((~(l_6261))))))) + ((-((-((((g_2440 << l_6399) | (-(l_6135))) ^ g_1369))))) * (-(g_335)))))) | ((-((BhChCol_6399 * g_759))) * (-((~(l_6167))))))));
uint32_t BhChCql_6167 = (~(((-(((BhChCpg_1369 << ((~((BhChCnl_6261 * l_6600))) + (~(g_2440)))) & (-(((~(l_6135)) & g_1369)))))) && (~((((~((l_6261 * (l_6167 ^ l_6260)))) * (~(((~((~(g_759)))) + (g_335 & BhChCol_6399))))) && (~(l_6399))))))));
int16_t BhChCrg_335 = (~((((BhChCpg_1369 | (g_1369 * BhChCql_6167)) && (g_759 * (((-(l_6600)) ^ (l_6260 + g_2440)) & (l_6399 | l_6167)))) && (~((~(((~(l_6261)) * ((((~(l_6135)) | (-(BhChCnl_6261))) + BhChCol_6399) | (~(g_335)))))))))));
int32_t BhChCsg_2440 = (~(((~((~((~(BhChCrg_335)))))) & ((~((((g_335 && ((-((-(l_6167)))) + (l_6135 && BhChCnl_6261))) | (-(l_6261))) & (-((-(((g_1369 >> l_6600) | (((BhChCql_6167 * g_2440) ^ l_6260) ^ BhChCpg_1369))))))))) + ((BhChCol_6399 + l_6399) + g_759)))));
if(((l_6167>=430207615U) || (g_759 < g_335))){
BhChCnl_6261 = l_6261;
BhChCol_6399 = l_6399;
BhChCpg_1369 = g_1369;
BhChCql_6167 = l_6167;
BhChCrg_335 = g_335;
BhChCsg_2440 = g_2440;
l_6261 = (~(((~((l_6399 << (~((-(g_1369))))))) && (((((g_335 + l_6261) * BhChCql_6167) * (((~((g_759 + BhChCnl_6261))) + l_6135) + (-((~((-(g_2440)))))))) && (l_6167 * (-(BhChCrg_335)))) * (~(((-((~(((l_6260 | (BhChCsg_2440 && BhChCol_6399)) && l_6600))))) ^ (~((-(BhChCpg_1369)))))))))));
l_6399 = (~(((~((~((-((((g_2440 & l_6135) + BhChCrg_335) && (BhChCol_6399 && BhChCsg_2440)))))))) & ((~((~(g_759)))) << (-((~(((-(g_335)) * ((((-((~(BhChCql_6167)))) + (l_6600 & (~((~(l_6261)))))) && (~((~(l_6260))))) * (((l_6399 | l_6167) && (-(BhChCpg_1369))) && (~(((~(BhChCnl_6261)) | (~(g_1369))))))))))))))));
g_1369 = (~(((~((~(((l_6399 | (-(BhChCol_6399))) * (~((BhChCpg_1369 | g_2440)))))))) && ((g_1369 + (~((l_6600 | g_335)))) && (((-((g_759 & l_6260))) & (-((~(((BhChCql_6167 * l_6167) + (~(BhChCsg_2440)))))))) && (BhChCrg_335 * ((~((BhChCnl_6261 + l_6261))) && l_6135)))))));
l_6167 = (-(((-((~(((~((l_6167 | (g_335 + g_1369)))) * ((~(BhChCsg_2440)) + (~(l_6260)))))))) & (((~((~(BhChCnl_6261)))) && (-((BhChCpg_1369 + BhChCrg_335)))) & ((-((((BhChCol_6399 ^ g_759) && (BhChCql_6167 << l_6600)) && (l_6261 | l_6135)))) & ((~(g_2440)) * (~(l_6399))))))));
g_335 = (~(((~((BhChCql_6167 && ((BhChCpg_1369 && g_2440) & (BhChCnl_6261 ^ BhChCol_6399))))) * (~(((~(((~((g_759 * l_6135))) && (BhChCrg_335 ^ (~((-((-(l_6261)))))))))) * ((-(g_335)) + (((g_1369 * l_6399) ^ ((~(l_6167)) | BhChCsg_2440)) + ((~((-(l_6260)))) & (-(l_6600)))))))))));
LABEL_hChCt: g_2440 = (~((((~((~(BhChCql_6167)))) | (~((g_335 * (-(((-((-((~(BhChCsg_2440)))))) && l_6260))))))) && (((~(((~(l_6399)) ^ g_1369))) * ((-((BhChCol_6399 | l_6261))) * (~((~((BhChCpg_1369 + ((~(BhChCnl_6261)) + BhChCrg_335)))))))) & (((~(l_6600)) && (~(((l_6135 && g_2440) << l_6167)))) && g_759)))));
if(((!BhChCsg_2440) && (g_759>13U))){
printf("l_6261=%llu\n", (unsigned long long)l_6261);
break;
}
if((((BhChCsg_2440 < g_2440) || (!l_6260)) && !(BhChCsg_2440))){
printf("l_6399=%lld\n", (long long)l_6399);
BhChCsg_2440 = (~((((~(((~(g_759)) | g_2440))) >> (((l_6600 ^ (~((~(l_6260))))) << (BhChCol_6399 & g_335)) && (-((~((-(((BhChCql_6167 << l_6261) & ((-((BhChCnl_6261 & BhChCrg_335))) | l_6135)))))))))) * (((l_6399 | (BhChCpg_1369 & (~(g_1369)))) >> (~((~((~(l_6167))))))) ^ (~((-((-(BhChCsg_2440))))))))));
continue;
}
if(((!BhChCrg_335) && (!g_759))){
printf("g_1369=%llu\n", (unsigned long long)g_1369);
l_6167 = (~(((g_1369 >> (~(BhChCrg_335))) | ((BhChCnl_6261 && ((-(BhChCql_6167)) ^ (-(((g_2440 && BhChCol_6399) & (-(g_759))))))) ^ (((~((l_6260 & l_6135))) >> BhChCpg_1369) | (((BhChCsg_2440 << (l_6167 >> l_6600)) * ((~(g_335)) + l_6261)) + l_6399))))));
continue;
}
if(((!l_6135) && (BhChCsg_2440>1566362880))){
printf("l_6167=%llu\n", (unsigned long long)l_6167);
BhChCql_6167 = (-(((~(((-(g_2440)) * l_6600))) | (((((BhChCql_6167 && (-(l_6135))) + (((~(g_335)) << (BhChCnl_6261 * BhChCpg_1369)) ^ (~(BhChCrg_335)))) << (~(l_6260))) | (((~(l_6261)) ^ (~((~((l_6399 ^ (BhChCsg_2440 & BhChCol_6399))))))) >> g_1369)) * (l_6167 | g_759)))));
continue;
}
if(!(!((l_6600 > BhChCrg_335)))){
printf("g_335=%lld\n", (long long)g_335);
g_2440 = (-(((g_335 + (~(((~(((~((~(((BhChCnl_6261 ^ (~((~(((l_6600 << (l_6261 ^ g_1369)) << l_6260)))))) | ((-((BhChCrg_335 && BhChCol_6399))) * l_6167)))))) << (~(((-((l_6135 >> g_2440))) | (~(l_6399)))))))) << ((~((~(BhChCsg_2440)))) ^ (BhChCpg_1369 ^ BhChCql_6167)))))) && (-((~((-((~((-(g_759)))))))))))));
l_6261 = (-(((~(((((~(l_6399)) << (-(l_6135))) & (~((~(g_2440))))) & ((~(((~(BhChCpg_1369)) << (((~((~((BhChCol_6399 + g_335))))) >> l_6260) * ((BhChCsg_2440 >> BhChCrg_335) >> g_759))))) + (~(((g_1369 << l_6261) | (-(l_6167))))))))) * ((-((~(BhChCnl_6261)))) + (l_6600 && BhChCql_6167)))));
}
if((!l_6261)){
printf("g_2440=%lld\n", (long long)g_2440);
continue;
}
}
l_6261 = BhChCnl_6261;
l_6399 = BhChCol_6399;
g_1369 = BhChCpg_1369;
l_6167 = BhChCql_6167;
g_335 = BhChCrg_335;
g_2440 = BhChCsg_2440;

                    g_472 = (~(((~((~((BGBGBkg_472 >> (~(BGBGBig_275))))))) / ((~((((l_6486 & (~(g_76))) ^ g_275) || BGBGBjg_573))) / (g_573 || ((~(((BGBGBmg_3486 | (~(BGBGBhg_76))) / (g_3486 || BGBGBlg_3463)))) % (((~(g_3463)) || (l_6189 / l_6135)) | (l_6500 / (~(g_472))))))))));
g_3463 = (~(((~((~(((~((~(BGBGBmg_3486)))) / (BGBGBhg_76 << (~((~(((((~((BGBGBjg_573 | l_6189))) / l_6135) ^ (~(g_275))) || ((~((~(g_3486)))) >> (g_76 & g_573))))))))))))) | (~((~(((((BGBGBkg_472 & BGBGBlg_3463) ^ l_6500) || (g_472 | g_3463)) | ((~(l_6486)) & BGBGBig_275)))))))));
g_3486 = (~(((~((((~((BGBGBmg_3486 | ((~(g_3463)) / (~((((~(g_3486)) & (g_76 / BGBGBkg_472)) % g_472))))))) % (g_275 % g_573)) & (~((((~(BGBGBlg_3463)) & l_6189) ^ (~((l_6500 || (l_6135 << l_6486)))))))))) ^ (BGBGBig_275 ^ (BGBGBhg_76 ^ BGBGBjg_573)))));
if((!BGBGBjg_573)){
;
BGBGBkg_472 = (~(((~((~((~((~((l_6486 << l_6189))))))))) & (~((((~(((l_6135 / (g_3486 % BGBGBjg_573)) || (BGBGBig_275 ^ l_6500)))) | (~(((~(((~((((~(BGBGBkg_472)) || (BGBGBmg_3486 & g_472)) / BGBGBlg_3463))) / (~((~(g_573))))))) >> g_76)))) / (g_3463 | (~((BGBGBhg_76 / (~(g_275))))))))))));
BGBGBhg_76 = (~(((~((~((~(g_3486)))))) / ((~((~(BGBGBkg_472)))) | (((l_6500 >> (((~((((g_275 << l_6135) & (~(((BGBGBhg_76 % g_3463) | (~(l_6189)))))) & (~(BGBGBmg_3486))))) % ((~(BGBGBjg_573)) / (BGBGBig_275 >> l_6486))) % (~((~((g_76 ^ g_573))))))) & (~((~(g_472))))) & (~((~((~((~(BGBGBlg_3463)))))))))))));

{
                    int i;
                    if (g_1370[(l_6189 + 1)])
                    {
                        int i, j;
                        g_1370[(l_6189 + 1)] = (((((((((g_98[g_6771][g_6771] = g_1370[(l_6189 + 1)]) & g_1370[(l_6189 + 2)]) != (safe_add_func_uint32_t_u_u((safe_sub_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s(((~((safe_rshift_func_uint8_t_u_s(g_1370[(l_6189 + 1)], 1)) >= (safe_rshift_func_int8_t_s_s((safe_unary_minus_func_uint8_t_u((safe_sub_func_int32_t_s_s((g_1370[(l_6189 + 1)] >= (safe_unary_minus_func_int32_t_s(g_34[0]))), (((((safe_mod_func_int32_t_s_s((safe_sub_func_uint32_t_u_u(l_6212, (l_6400 = ((l_6315 = 1L) , (safe_rshift_func_int16_t_s_u(g_2580[0][7], ((((safe_add_func_uint8_t_u_u(0UL, g_34[l_6189])) | l_6213) <= j) , 0x0849L))))))), 4294967287UL)) <= 4294967291UL) , 0xEDL) , g_172) <= 0xF9B9B50EL))))), 4)))) | k), 1)), (-1L))), k))) <= l_6213) <= 246UL) | g_13[0]) & (-1L)) != g_1370[(l_6189 + 1)]) < l_5910);
                        g_1370[(l_6189 + 1)] = (((g_335 || (safe_add_func_int16_t_s_s(((safe_sub_func_uint8_t_u_u(2UL, (((((safe_mod_func_int8_t_s_s((BGBGBcg_1368 | ((safe_rshift_func_int8_t_s_s(l_6189, ((((((((((safe_add_func_uint8_t_u_u(0xFCL, ((((safe_add_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(g_34[0], (safe_sub_func_uint16_t_u_u((safe_sub_func_int16_t_s_s((((+(4294967295UL > ((~(((g_4689 || g_6771) & l_6212) , 0xC5CA8165L)) == g_34[l_6189]))) & 0xA24B7619L) || 0x35C36BF4L), l_6400)), g_34[l_6189])))), l_6315)) ^ l_5910) < (-1L)) >= l_5835[0]))) ^ l_5835[6]) , g_6771) == g_98[4][4]) , 0xF0L) , g_34[0]) >= g_1370[(l_6189 + 1)]) , g_2043) != 1L) || g_3109[2]))) , l_6400)), 255UL)) < 1UL) == g_13[1]) < g_4423[2]) > l_6136[0]))) , l_33), g_1370[(l_6189 + 1)]))) < g_3486) > l_6181);
                        g_5446[4] = (~(0xDDCCL == ((((safe_div_func_int16_t_s_s(l_6400, (safe_mod_func_int8_t_s_s(k, 0xAFL)))) , (safe_sub_func_int16_t_s_s((safe_div_func_uint8_t_u_u(g_6771, l_33)), (g_98[1][3] >= ((safe_rshift_func_uint16_t_u_u((g_34[0] == 9L), 13)) , (-10L)))))) != l_6086) <= g_2043)));
                        g_2580[3][6] = (l_6260 = (safe_div_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_u((safe_div_func_int8_t_s_s((!((safe_add_func_int16_t_s_s(l_5910, ((safe_div_func_int8_t_s_s((l_6400 < (9UL ^ (safe_rshift_func_int16_t_s_u((safe_mod_func_int32_t_s_s((BpBpBdg_154 = ((((g_5446[5] >= (-4L)) < (g_6771 == (g_2467 = (safe_rshift_func_uint16_t_u_u((255UL == g_1352), 13))))) >= ((((safe_sub_func_int8_t_s_s((safe_lshift_func_int8_t_s_s((((l_6318 && 0xF1L) , g_3935[3][2]) & 0x4AL), 4)), g_1370[(l_6189 + 1)])) , l_6189) , (-1L)) & k)) | g_1370[(l_6189 + 1)])), l_6400)), g_335)))), 0x99L)) , g_1370[(l_6189 + 1)]))) != 0x11739D61L)), g_496[2])), 5)) , BGBGBcg_1368), l_6400)));
                    }
                    else
                    {
                        const int32_t l_6407 = 0x90A736CAL;
                        g_2853[0][6][6] = ((g_2043 , ((safe_div_func_uint8_t_u_u(g_1368, ((g_1138 > g_1370[1]) , k))) , l_5835[0])) , (safe_div_func_uint8_t_u_u(((g_5225 , (safe_rshift_func_uint16_t_u_u(g_2580[0][7], g_1138))) , 0xC0L), l_6407)));
                    }
                    g_3935[3][2] = ((safe_rshift_func_uint16_t_u_s(l_6147, 2)) > (safe_div_func_uint16_t_u_u((safe_add_func_int8_t_s_s(g_6771, ((safe_add_func_int16_t_s_s((g_1368 && (safe_div_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(g_1370[1], (((safe_add_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_s((safe_add_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((BpBpBbg_6029 = 0x28L), BpBpBg_1369)), ((g_1370[(l_6189 + 1)] , 0x7DL) == g_1288))), 6)) < g_1370[(l_6189 + 1)]), g_4475)) != g_1684[0]) , 0x94B1L))), BGBGBcg_1368))), g_1352)) <= g_6771))), 1UL)));
                }

                    break;
}
if((BGBGBhg_76 < BGBGBmg_3486)){
printf("g_275=%lld\n", (long long)g_275);
BGBGBlg_3463 = (~(((~(((~((((g_3463 | (l_6135 / g_76)) ^ g_472) << (~(l_6486))))) % ((~((~((BGBGBlg_3463 >> BGBGBjg_573))))) & (((g_3486 >> l_6189) / BGBGBmg_3486) & (~((~(BGBGBhg_76))))))))) || (~((BGBGBkg_472 << (BGBGBig_275 << (~((g_573 & (g_275 | l_6500)))))))))));
continue;
}
if((!g_275)){
printf("g_573=%lld\n", (long long)g_573);
break;
}
if(!(BGBGBjg_573)){
;
g_573 = (~(((~(((~((~(((((g_76 | BGBGBig_275) | ((~(l_6500)) || (BGBGBkg_472 % g_472))) ^ (~(BGBGBjg_573))) / ((~(((BGBGBhg_76 / BGBGBmg_3486) >> (~(g_3463))))) << (~(l_6135)))))))) & (g_275 << (~(BGBGBlg_3463)))))) || ((l_6486 || ((~(g_573)) >> g_3486)) / (~((~(l_6189))))))));
BGBGBhg_76 = (~((((~(((~(g_76)) ^ (~(g_275))))) || ((BGBGBkg_472 & g_573) / ((l_6486 | (BGBGBmg_3486 & g_3486)) | BGBGBjg_573))) || (~((~((((~((g_472 || ((~((l_6500 >> (~(l_6135))))) | (~(BGBGBhg_76)))))) & (~(((~(BGBGBig_275)) || (BGBGBlg_3463 << g_3463))))) || (~((~((~(l_6189))))))))))))));
continue;
}
if((!g_3463)){
printf("g_3486=%lld\n", (long long)g_3486);
;
goto LABEL_pBpBg;
}
}
g_76 = BGBGBhg_76;
                                    if ((!g_982) )
{

for (l_6762 = 0; l_6762 < 1; l_6762++)
        g_5210[l_6762] = 0L;

}
                    g_275 = BGBGBig_275;
g_573 = BGBGBjg_573;
g_472 = BGBGBkg_472;
g_3463 = BGBGBlg_3463;
g_3486 = BGBGBmg_3486;

                    if ((l_6166 <= ((safe_div_func_uint16_t_u_u((((safe_div_func_int16_t_s_s(((g_759 = ((g_154 | (((l_6181 = (safe_div_func_uint32_t_u_u(4294967295UL, ((g_1684[g_172] = ((l_6174[1] = (-1L)) ^ (safe_lshift_func_int8_t_s_s(0xC1L, 6)))) | (l_6180 = (+(g_6029 = (g_34[g_172] | (((g_3935[3][2] = (l_6138 = (safe_sub_func_uint32_t_u_u((((g_2853[0][6][6] != (g_4423[1] = g_34[g_172])) , g_3935[5][2]) <= g_1138), (-6L))))) ^ l_33) < (-1L)))))))))) , g_1288) , g_2580[0][7])) | (-1L))) || g_184), g_68)) , 252UL) >= g_34[g_172]), g_2853[3][6][2])) , l_6136[3])))
                    {
                        uint16_t l_6186 = 0UL;

;



{
                int i;
                return g_13[k];
            }


if (g_1798[5][2])
                            continue;

                    g_2580[0][0] = (safe_lshift_func_int8_t_s_u(((l_6186 && ((g_573 && (safe_div_func_int32_t_s_s(l_6189, (safe_sub_func_int8_t_s_s((65535UL ^ (~(l_6147 > (g_1798[7][4] | (((safe_div_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u((safe_div_func_uint32_t_u_u(((safe_div_func_uint16_t_u_u((safe_div_func_uint8_t_u_u((l_6213 = ((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_int16_t_s_s(g_184, ((safe_unary_minus_func_uint8_t_u(((safe_rshift_func_int8_t_s_u(((((safe_add_func_uint32_t_u_u((4294967291UL < (l_6160 == 0UL)), l_6125)) && g_5446[3]) & g_34[g_172]) ^ 0xB6L), g_1369)) , g_4423[1]))) , g_3935[0][0]))) | (-1L)), 6)) , l_6212)), l_6186)), g_1684[g_172])) & l_6181), g_13[4])), 1)), 0x9145398FL)) & 0x92L) > g_3935[2][4]))))), (-1L)))))) != 5UL)) , g_35), l_6186));
                    }
                    else
                    {
                        if (g_34[0])
                            break;
                        g_1370[2] = g_1288;
                        return g_1368;
                    }
                }
                else
                {
                    int8_t l_6242 = (-5L);
                    int32_t l_6257[6][6] = {{7L,7L,0xC2561099L,0x798B21A8L,1L,0x798B21A8L},{0x9B52C605L,7L,0x9B52C605L,(-5L),0xC2561099L,0xC2561099L},{1L,0x9B52C605L,0x9B52C605L,1L,7L,0x798B21A8L},{0x798B21A8L,1L,0xC2561099L,1L,0x798B21A8L,(-5L)},{1L,0x798B21A8L,(-5L),(-5L),0x798B21A8L,1L},{0x9B52C605L,1L,7L,0x798B21A8L,7L,1L}};
                    uint8_t l_6278 = 0x7BL;
                    int32_t l_6295[6][1][5] = {{{0x20128B80L,(-1L),(-5L),(-1L),0x20128B80L}},{{0x20128B80L,(-1L),(-5L),(-1L),0x20128B80L}},{{0x20128B80L,(-1L),(-5L),(-1L),0x20128B80L}},{{0x20128B80L,(-1L),(-5L),(-1L),0x20128B80L}},{{0x20128B80L,(-1L),(-5L),(-1L),(-1L)}},{{(-1L),0x12EF6116L,3L,0x12EF6116L,(-1L)}}};
                    uint8_t l_6314 = 6UL;
                    uint8_t l_6316[5][5][2] = {{{0xE1L,0x7DL},{0xE1L,0xB3L},{0x96L,0x96L},{0xB3L,0xE1L},{0x7DL,0xE1L}},{{0xB3L,0x96L},{0x96L,0xB3L},{0xE1L,0x7DL},{0xE1L,0xB3L},{0x96L,0x96L}},{{0xB3L,0xE1L},{0x7DL,0xE1L},{0xB3L,0x96L},{0x96L,0xB3L},{0xE1L,0x7DL}},{{0xE1L,0xB3L},{0x96L,0x96L},{0xB3L,0xE1L},{0x7DL,0xE1L},{0xB3L,0x96L}},{{0x96L,0xB3L},{0xE1L,0x7DL},{0xE1L,0xB3L},{0x96L,0x96L},{0xB3L,0xE1L}}};
                    int i, j, k;
                    if (g_1370[2])
                    {
                        return g_1684[0];
                    }
                    else
                    {
                        int32_t l_6235 = 0xAC4FACC5L;
                        int32_t l_6236 = 8L;
                        const uint8_t l_6237 = 2UL;
                        uint32_t l_6238[4][8] = {{0x0C807529L,0xF3353C93L,0xF9E91C24L,0xF3353C93L,0x0C807529L,1UL,1UL,0x0C807529L},{0xF3353C93L,0xCA95C587L,0xCA95C587L,0xF3353C93L,5UL,0x0C807529L,5UL,0xF3353C93L},{0xCA95C587L,5UL,0xCA95C587L,1UL,0xF9E91C24L,0xF9E91C24L,1UL,0xCA95C587L},{5UL,5UL,0xF9E91C24L,0x0C807529L,0x4CB466C0L,0x0C807529L,0xF9E91C24L,5UL}};
                        int i, j;



g_87 += 1;


                    for (g_68 = 0; (g_68 < 1); ++g_68)
                {
                    int16_t l_4268 = 0x35F2L;

{
                        int8_t l_5764 = 0xC3L;
                        g_5210[0] = ((safe_unary_minus_func_int16_t_s((-1L))) == (((safe_rshift_func_int8_t_s_u(((BpBpBg_1369 = (((l_6280 = ((g_472 = g_6029) ^ ((safe_mod_func_int8_t_s_s(g_5210[0], (safe_rshift_func_int16_t_s_u((l_6318 ^ (safe_add_func_uint16_t_u_u((safe_mod_func_int32_t_s_s(4L, (g_35 , g_1798[5][2]))), ((-1L) | (safe_lshift_func_uint16_t_u_s(((l_5929 = (l_33 <= BGBGBeg_897)) <= g_6029), g_35)))))), g_35)))) <= l_6239))) , l_6536) ^ g_35)) & g_35), l_5764)) != 0xC85B220FL) & l_5764));
                    }

                    l_4268 = g_9;
                    g_204 = (1L > ((!(safe_lshift_func_uint8_t_u_u(l_6235, 6))) != l_6235));
                };


                    ;


                    l_6138 = (!(safe_mod_func_int32_t_s_s((safe_div_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_s((safe_unary_minus_func_int8_t_s((((g_4689 = g_1599) || ((g_3172 = l_6136[1]) >= g_87)) <= (0x84469A5DL || ((((((g_154 = l_10) ^ (l_6235 = (safe_lshift_func_int16_t_s_s(0L, ((safe_unary_minus_func_int8_t_s((safe_sub_func_uint16_t_u_u((((g_5512 < (safe_lshift_func_int8_t_s_s(g_5210[0], g_5512))) , 0x62A52B1EL) && g_2422), 0xAD7BL)))) , l_6166))))) , l_6136[1]) & g_184) < l_6236) , l_6125))))), 4)) > g_5225) || l_6235), g_2853[2][6][4])) || l_6237), 0xE1F7L)), l_6236)), l_6238[2][1])));
                        l_6239 = g_6029;
                        ;
                    }
                    ;
                    if ((((safe_div_func_uint8_t_u_u((safe_div_func_uint32_t_u_u((l_6181 & (g_4423[2] = ((g_982 = g_184) , (((g_5446[5] ^ ((safe_sub_func_int16_t_s_s(((0x7877C371L | (l_6138 = (l_6261 = ((safe_sub_func_int8_t_s_s((safe_div_func_int32_t_s_s((g_3935[1][1] = (safe_lshift_func_int8_t_s_s((((((((l_6257[4][3] = g_1684[0]) & ((-1L) > l_6136[3])) && (((safe_div_func_int8_t_s_s((((((255UL == (l_6260 , 0x54L)) , 0xB04B55FEL) , g_13[4]) < 0xBEA82B57L) > l_6239), 1L)) != g_204) , g_352)) >= g_3600) == 0x57L) , g_6029) | l_6242), g_2853[0][5][4]))), 4294967287UL)), g_897)) == g_1684[0])))) < g_3193), g_204)) > l_5835[0])) | 0xABL) , 0xACL)))), 0x59EEDA58L)), g_469)) , g_5446[5]) == g_6029))
                    {
                        uint32_t l_6277 = 0UL;
                        int32_t l_6279 = 0x27557BC7L;

{
                        l_6627 = (safe_sub_func_uint32_t_u_u(4294967288UL, g_4475));
                    }

                    l_6160 = (safe_mod_func_int32_t_s_s(g_1370[2], (safe_div_func_int32_t_s_s((((safe_sub_func_uint8_t_u_u(0x6CL, ((safe_add_func_uint32_t_u_u(((g_4475 = ((safe_unary_minus_func_uint16_t_u(((((((l_6257[4][3] = (safe_rshift_func_int16_t_s_u(((safe_add_func_uint16_t_u_u((255UL != (safe_mod_func_int8_t_s_s((g_2467 = (l_6278 = ((l_6189 >= (((l_6189 == (-1L)) ^ 0x12D29ED7L) , (l_6277 = (0xBAL && 1UL)))) | 0xCEL))), 1L))), l_6279)) || 0L), g_5210[0]))) , 254UL) | l_6279) > 0x2908L) | 0x90L) > g_3109[0]))) >= l_6280)) < 0x91L), g_204)) && g_5225))) | l_6242) ^ l_6125), g_2580[0][7]))));
                        ;
                        if (g_76)
                            {
{
                        int32_t l_1918 = 0x53669838L;
                        int i;

{
            l_6160 = g_4423[4];
            return l_6315;
        }

                    l_1918 = (safe_sub_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((l_6479[l_6318] , (g_1684[l_6318] || ((l_6086 , l_6086) && (+(g_3172 = (!(+(safe_add_func_int32_t_s_s(l_6086, 0x6F544798L))))))))), 0x80479FE7L)), 0x483FL));
                    }



if (g_275)
                            continue;


for (l_5943 = 0; l_5943 < 5; l_5943++)
        {
            transparent_crc(g_3935[l_6317][l_5943], "g_3935[l_6317][l_5943]", g_2440);
            if (g_2440) printf("index = [%d][%d]\n", l_6317, l_5943);

        };


                    if (((((safe_unary_minus_func_uint16_t_u((((l_6486 , (0x40L != g_335)) , (g_184 = (safe_mod_func_int8_t_s_s((l_6762 = (safe_lshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_s(1L, (~(-1L)))) , (safe_div_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s(l_6138, 1)) , (l_6486 ^ (g_2852 >= (((g_184 & l_33) <= g_3172) <= g_2580[3][7])))), g_3486))), (-1L))), g_335))), g_352)))) & g_506))) <= 0xAAL) > 1L) == 0xCEB4L))
                    {
                        int16_t l_4243 = (-1L);
                        ;
                        if (l_6762)
                            ;;
                    }
                    else
                    {
                        g_5210[0] = (safe_mod_func_int16_t_s_s((0xF1303593L > ((g_352 != ((g_4689 = (g_240 = ((((0xEEL | g_1684[0]) || ((((l_33 > (safe_lshift_func_uint16_t_u_u(l_33, 1))) , (safe_mod_func_uint32_t_u_u(((-4L) != l_6400), 0x3D51BA8BL))) || 0L) < 1L)) <= g_897) , g_506))) & l_33)) ^ 0xC41FL)), l_33));

for (g_759 = 0; (g_759 <= 1); g_759 += 1)
                    {
                        int i;
                        if (l_6479[g_759])
                            break;
                    };


                    l_6762 = (g_2043 = ((safe_rshift_func_int8_t_s_u((l_6278 != 255UL), 6)) != ((g_1684[0] | ((((l_33 , 0UL) , (safe_lshift_func_int16_t_s_u(0xB99EL, ((safe_sub_func_uint8_t_u_u(g_897, (safe_div_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(0xFD67L, (g_496[2] >= l_6823))), l_33)))) >= g_2852)))) ^ 0UL) <= 0L)) >= g_1345)));
                    }
BpBpBg_1369 += 1;


                    ;


                    continue;}
                    }
                    else
                    {
                        g_5446[5] = g_9;
                    }
                }
                for (g_1345 = 0; (g_1345 <= 4); g_1345 += 1)
                {
                    int i;
                    if (g_1370[(g_172 + 1)])
                    {
                        int i, j;
                        g_1370[(g_172 + 1)] = (((((((((g_98[g_1345][g_1345] = g_1370[(g_172 + 1)]) & g_1370[(g_172 + 2)]) != (safe_add_func_uint32_t_u_u((safe_sub_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s(((~((safe_rshift_func_uint8_t_u_s(g_1370[(g_172 + 1)], 1)) >= (safe_rshift_func_int8_t_s_s((safe_unary_minus_func_uint8_t_u((safe_sub_func_int32_t_s_s((g_1370[(g_172 + 1)] >= (safe_unary_minus_func_int32_t_s(g_34[0]))), (((((safe_mod_func_int32_t_s_s((safe_sub_func_uint32_t_u_u(g_3463, (g_76 = ((g_3172 = 1L) , (safe_rshift_func_int16_t_s_u(g_2580[0][7], ((((safe_add_func_uint8_t_u_u(0UL, g_34[g_172])) | g_2043) <= g_573) , 0x0849L))))))), 4294967287UL)) <= 4294967291UL) , 0xEDL) , l_6166) <= 0xF9B9B50EL))))), 4)))) | g_506), 1)), (-1L))), l_6342))) <= g_2043) <= 246UL) | g_13[0]) & (-1L)) != g_1370[(g_172 + 1)]) < l_5986);

for (l_6627 = 0; l_6627 < 1; l_6627++)
        g_5210[l_6627] = 1L;

                    g_1370[(g_172 + 1)] = (((g_5512 || (safe_add_func_int16_t_s_s(((safe_sub_func_uint8_t_u_u(2UL, (((((safe_mod_func_int8_t_s_s((l_6135 | ((safe_rshift_func_int8_t_s_s(g_172, ((((((((((safe_add_func_uint8_t_u_u(0xFCL, ((((safe_add_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(g_34[0], (safe_sub_func_uint16_t_u_u((safe_sub_func_int16_t_s_s((((+(4294967295UL > ((~(((g_3600 || g_1345) & g_3463) , 0xC5CA8165L)) == g_34[g_172]))) & 0xA24B7619L) || 0x35C36BF4L), l_5929)), g_34[g_172])))), g_3172)) ^ l_5986) < (-1L)) >= l_5835[0]))) ^ l_5835[6]) , g_1345) == g_98[4][4]) , 0xF0L) , g_34[0]) >= g_1370[(g_172 + 1)]) , l_6317) != 1L) || g_3109[2]))) , g_76)), 255UL)) < 1UL) == g_13[1]) < g_4423[2]) > l_6136[0]))) , g_275), g_1370[(g_172 + 1)]))) < l_6239) > l_5943);

{
                        return g_1684[0];
                    }


{
                        uint32_t l_6538[6][1];
                        int i, j;
                        for (i = 0; i < 6; i++)
                        {
                            for (j = 0; j < 1; j++)
                                l_6538[i][j] = 0x22EB942DL;
                        }
                        l_6538[2][0] = g_4475;
                        j = ((l_6180 = l_6074) >= j);
                    }

                    g_5446[4] = (~(0xDDCCL == ((((safe_div_func_int16_t_s_s(l_5929, (safe_mod_func_int8_t_s_s(l_10, 0xAFL)))) , (safe_sub_func_int16_t_s_s((safe_div_func_uint8_t_u_u(g_352, g_275)), (g_98[1][3] >= ((safe_rshift_func_uint16_t_u_u((g_34[0] == 9L), 13)) , (-10L)))))) != g_184) <= l_6317)));


if (j) printf("index = [%d]\n", g_506);

                    ;

                    g_2580[3][6] = (g_204 = (safe_div_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_u((safe_div_func_int8_t_s_s((!((safe_add_func_int16_t_s_s(l_5986, ((safe_div_func_int8_t_s_s((l_5929 < (9UL ^ (safe_rshift_func_int16_t_s_u((safe_mod_func_int32_t_s_s((l_6399 = ((((g_5446[5] >= (-4L)) < (g_1345 == (g_2422 = (safe_rshift_func_uint16_t_u_u((255UL == l_6152), 13))))) >= ((((safe_sub_func_int8_t_s_s((safe_lshift_func_int8_t_s_s((((g_1138 && 0xF1L) , g_3935[3][2]) & 0x4AL), 4)), g_1370[(g_172 + 1)])) , g_172) , (-1L)) & l_6138)) | g_1370[(g_172 + 1)])), l_5929)), g_5512)))), 0x99L)) , g_1370[(g_172 + 1)]))) != 0x11739D61L)), g_496[2])), 5)) , l_6135), l_6400)));
                    }
                    else
                    {
                        const int32_t l_6407 = 0x90A736CAL;

BpBpBcg_3317 += 1;


                    ;
                    }

{
                    l_6536 = (9UL >= g_2852);
                }

                    g_3935[3][2] = ((safe_rshift_func_uint16_t_u_s(g_3317, 2)) > (safe_div_func_uint16_t_u_u((safe_add_func_int8_t_s_s(g_352, ((safe_add_func_int16_t_s_s((g_469 && (safe_div_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(g_1370[1], (((safe_add_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_s((safe_add_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((g_6029 = 0x28L), g_87)), ((g_1370[(g_172 + 1)] , 0x7DL) == g_6428))), 6)) < g_1370[(g_172 + 1)]), g_3193)) != g_1684[0]) , 0x94B1L))), l_6135))), g_5844)) <= g_352))), 1UL)));
                }
            }
                                                while ((!((l_6152 < l_6762)) && !((l_6762 < l_6260))) )
{

{
                        g_1370[1] = ((l_5943 = l_6147) ^ ((safe_sub_func_uint8_t_u_u(((+l_6167) , l_6160), (-10L))) || g_9));
                    }

}
                    for (g_472 = (-27); (g_472 <= 23); g_472 = safe_add_func_int16_t_s_s(g_472, 6))
            {
                uint8_t l_6448 = 253UL;
                int32_t l_6458 = 0x0B95517EL;
                uint16_t l_6459 = 0x900EL;
                ;
            }
        }
        else
        {
            int16_t l_6473 = (-1L);

for (g_275 = 0; g_275 < 9; g_275++)
    {
        for (l_5910 = 0; l_5910 < 8; l_5910++)
        {
            transparent_crc(g_1798[g_275][l_5910], "g_1798[g_275][l_5910]", l_6160);
            if (l_6160) printf("index = [%d][%d]\n", g_275, l_5910);

        }
    };


                    l_5943 = ((safe_sub_func_uint8_t_u_u(g_759, (0x84F034BFL && (safe_lshift_func_int16_t_s_s((g_335 = (safe_unary_minus_func_uint16_t_u((safe_lshift_func_int8_t_s_s((((safe_add_func_int8_t_s_s(((((safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s(255UL, 6)), (l_6473 && 1L))) & l_6261) , l_6473) > ((+(safe_add_func_int16_t_s_s(l_10, (safe_rshift_func_uint8_t_u_u((g_506 < 65534UL), l_6473))))) , 255UL)), l_6479[0])) > g_87) , (-1L)), l_6280))))), 8))))) && 0x97L);
            for (g_275 = 4; (g_275 >= 0); g_275 -= 1)
            {
                int i;
                return g_13[g_275];
            }
        }
        if ((g_2853[0][6][6] = (safe_sub_func_uint32_t_u_u((safe_add_func_int16_t_s_s((((l_5910 == 0x27A1L) <= g_2852) , (((safe_lshift_func_int8_t_s_u(l_6486, 7)) || (safe_sub_func_int16_t_s_s((~((safe_add_func_uint8_t_u_u(((l_6152 >= (safe_add_func_uint16_t_u_u(0xE3AAL, (((g_5446[5] == (safe_lshift_func_uint8_t_u_u(g_68, (g_4475 = ((safe_lshift_func_int16_t_s_s((l_5943 = (safe_lshift_func_int16_t_s_u((-3L), g_1368))), l_6147)) , g_1288))))) < g_2853[0][6][6]) , 65534UL)))) <= g_2580[3][7]), 0UL)) == l_33)), g_204))) , g_1798[5][2])), l_6500)), g_4689))))
        {
            uint8_t l_6518 = 0xF6L;
            int32_t l_6533 = 1L;
            int16_t l_6548[2][3] = {{0x396CL,0x396CL,0x396CL},{0x32CDL,0x32CDL,0x32CDL}};
            int32_t l_6564[10];
            uint32_t l_6601 = 0x3C01C967L;
            int8_t l_6625 = (-6L);
            int32_t l_6711 = (-1L);
            uint32_t l_6712 = 0x1EBB175BL;
            int32_t l_6726 = 1L;
            uint32_t l_6800 = 1UL;
            int i, j;
            for (i = 0; i < 10; i++)
                { while ((l_5913 > l_6726) )
{

l_5913 -= 1;


}
                    l_6564[i] = 0x3F83C38EL;}
            if ((safe_mod_func_int32_t_s_s(((safe_div_func_int8_t_s_s(0x0EL, l_6167)) & (g_98[0][1] != (g_897 = (safe_sub_func_int16_t_s_s(((l_6136[1] , ((((!g_496[2]) != (l_5986 = (((((g_4689 = (safe_mod_func_uint8_t_u_u((((safe_lshift_func_uint16_t_u_s(((safe_add_func_uint32_t_u_u((((safe_unary_minus_func_uint32_t_u(((g_3193 = l_5986) == (safe_add_func_int32_t_s_s(((65534UL > (((~(l_6136[1] , ((((l_6518 && g_469) ^ g_3935[3][0]) <= l_6074) | g_897))) & l_5910) >= l_6518)) && 0x470D685FL), l_6518))))) != g_3172) < g_1798[6][0]), 0UL)) & 4294967287UL), 0)) < g_3486) | l_5913), l_6479[0]))) && 0xE4L) > g_352) == g_9) != g_469))) <= g_1684[0]) != 0xDCL)) & 1UL), g_1370[2]))))), g_13[4])))
            {
                int32_t l_6539 = 0x35BBF772L;
                uint16_t l_6748 = 0x6A93L;

{
                    const int16_t l_6537 = 0x730CL;
                    int32_t l_6602[10][9] = {{(-1L),(-1L),0xD0093E75L,(-10L),0xD0093E75L,(-1L),(-1L),0xD0093E75L,(-10L)},{0xC8936D7EL,0x50179415L,0xC8936D7EL,0x93DFA981L,0x93DFA981L,0xC8936D7EL,0x50179415L,0xC8936D7EL,0x93DFA981L},{(-1L),0xD0093E75L,0xD0093E75L,(-1L),0x85A5A9EFL,(-1L),0xD0093E75L,0xD0093E75L,(-1L)},{(-3L),0x93DFA981L,1L,0x93DFA981L,(-3L),(-3L),0x93DFA981L,1L,0x93DFA981L},{0xD0093E75L,0x85A5A9EFL,(-10L),(-10L),0x85A5A9EFL,0xD0093E75L,0x85A5A9EFL,(-10L),(-10L)},{(-3L),(-3L),0x93DFA981L,1L,0x93DFA981L,(-3L),(-3L),0x93DFA981L,1L},{(-1L),0x85A5A9EFL,(-1L),0xD0093E75L,0xD0093E75L,(-1L),0x85A5A9EFL,(-1L),0xD0093E75L},{0xC8936D7EL,0x93DFA981L,0x93DFA981L,0xC8936D7EL,0x50179415L,0xC8936D7EL,0x93DFA981L,0x93DFA981L,0xC8936D7EL},{(-1L),0xD0093E75L,(-10L),0xD0093E75L,(-1L),(-1L),0xD0093E75L,(-10L),0xD0093E75L},{0x93DFA981L,0x50179415L,1L,1L,0x50179415L,0x93DFA981L,0x50179415L,1L,1L}};
                    uint8_t l_6683[8][1][2];
                    uint16_t l_6691 = 0UL;
                    uint32_t l_6714 = 0x983D8C45L;
                    int i, j, k;




for (l_5943 = 0; l_5943 < 1; l_5943++)
    {

for (l_6539 = 0; l_6539 < 2; l_6539++)
        l_6479[l_6539] = (-3L);

                    ;
        if (l_6762) printf("index = [%d]\n", l_5943);

    };




                }

                    for (l_6167 = (-16); (l_6167 != 59); l_6167++)
                {
                    const int16_t l_6537 = 0x730CL;
                    int32_t l_6602[10][9] = {{(-1L),(-1L),0xD0093E75L,(-10L),0xD0093E75L,(-1L),(-1L),0xD0093E75L,(-10L)},{0xC8936D7EL,0x50179415L,0xC8936D7EL,0x93DFA981L,0x93DFA981L,0xC8936D7EL,0x50179415L,0xC8936D7EL,0x93DFA981L},{(-1L),0xD0093E75L,0xD0093E75L,(-1L),0x85A5A9EFL,(-1L),0xD0093E75L,0xD0093E75L,(-1L)},{(-3L),0x93DFA981L,1L,0x93DFA981L,(-3L),(-3L),0x93DFA981L,1L,0x93DFA981L},{0xD0093E75L,0x85A5A9EFL,(-10L),(-10L),0x85A5A9EFL,0xD0093E75L,0x85A5A9EFL,(-10L),(-10L)},{(-3L),(-3L),0x93DFA981L,1L,0x93DFA981L,(-3L),(-3L),0x93DFA981L,1L},{(-1L),0x85A5A9EFL,(-1L),0xD0093E75L,0xD0093E75L,(-1L),0x85A5A9EFL,(-1L),0xD0093E75L},{0xC8936D7EL,0x93DFA981L,0x93DFA981L,0xC8936D7EL,0x50179415L,0xC8936D7EL,0x93DFA981L,0x93DFA981L,0xC8936D7EL},{(-1L),0xD0093E75L,(-10L),0xD0093E75L,(-1L),(-1L),0xD0093E75L,(-10L),0xD0093E75L},{0x93DFA981L,0x50179415L,1L,1L,0x50179415L,0x93DFA981L,0x50179415L,1L,1L}};
                    uint8_t l_6683[8][1][2];
                    uint16_t l_6691 = 0UL;
                    uint32_t l_6714 = 0x983D8C45L;
                    int i, j, k;

g_2852 += 1;


                    for (i = 0; i < 8; i++)
                    {
                        for (j = 0; j < 1; j++)
                        {



for (g_240 = 0; g_240 < 4; g_240++)
                        l_6136[g_240] = 6L;

                    if (g_1369)
                    ;
for (l_6625 = 0; (l_6625 <= 2); l_6625 += 1)
                    {
                        uint32_t l_3777 = 0x65B9FE36L;
                        i = g_3109[1];
                        g_5844 = (l_6261 , (safe_rshift_func_int16_t_s_s((l_6726 | l_6726), (!l_3777))));
                    };


                    ;

                    if (g_35)
                            break;


if ((g_2853[0][6][6] = (safe_sub_func_uint32_t_u_u((safe_add_func_int16_t_s_s((((g_240 == 0x27A1L) <= g_472) , (((safe_lshift_func_int8_t_s_u(g_2422, 7)) || (safe_sub_func_int16_t_s_s((~((safe_add_func_uint8_t_u_u(((l_6152 >= (safe_add_func_uint16_t_u_u(0xE3AAL, (((g_5446[5] == (safe_lshift_func_uint8_t_u_u(g_469, (g_3193 = ((safe_lshift_func_int16_t_s_s((l_6539 = (safe_lshift_func_int16_t_s_u((-3L), g_1345))), l_6748)) , l_5888))))) < g_2853[0][6][6]) , 65534UL)))) <= g_2580[3][7]), 0UL)) == l_6539)), g_240))) , g_1798[5][2])), l_6147)), l_6646))))
        {
            uint8_t l_6518 = 0xF6L;
            int32_t l_6533 = 1L;
            int16_t l_6548[2][3] = {{0x396CL,0x396CL,0x396CL},{0x32CDL,0x32CDL,0x32CDL}};
            int32_t l_6564[10];
            uint32_t l_6601 = 0x3C01C967L;
            int8_t l_6625 = (-6L);
            int32_t l_6711 = (-1L);
            uint32_t l_6712 = 0x1EBB175BL;
            int32_t l_6726 = 1L;
            uint32_t l_6800 = 1UL;
            int i, j;
            ;
            if ((safe_mod_func_int32_t_s_s(((safe_div_func_int8_t_s_s(0x0EL, g_3463)) & (g_98[0][1] != (g_1288 = (safe_sub_func_int16_t_s_s(((l_6136[1] , ((((!g_496[2]) != (g_506 = (((((l_6646 = (safe_mod_func_uint8_t_u_u((((safe_lshift_func_uint16_t_u_s(((safe_add_func_uint32_t_u_u((((safe_unary_minus_func_uint32_t_u(((l_6518 = g_506) == (safe_add_func_int32_t_s_s(((65534UL > (((~(l_6136[1] , ((((l_6518 && g_3463) ^ g_3935[3][0]) <= g_5225) | g_1288))) & g_240) >= l_6518)) && 0x470D685FL), l_6518))))) != g_2467) < g_1798[6][0]), 0UL)) & 4294967287UL), 0)) < g_275) | g_5512), l_6479[0]))) && 0xE4L) > g_352) == g_9) != g_3463))) <= g_1684[0]) != 0xDCL)) & 1UL), g_1370[2]))))), g_13[4])))
            {
                int32_t l_6539 = 0x35BBF772L;
                uint16_t l_6748 = 0x6A93L;
                for (g_3463 = (-16); (g_3463 != 59); g_3463++)
                {
                    const int16_t l_6537 = 0x730CL;
                    int32_t l_6602[10][9] = {{(-1L),(-1L),0xD0093E75L,(-10L),0xD0093E75L,(-1L),(-1L),0xD0093E75L,(-10L)},{0xC8936D7EL,0x50179415L,0xC8936D7EL,0x93DFA981L,0x93DFA981L,0xC8936D7EL,0x50179415L,0xC8936D7EL,0x93DFA981L},{(-1L),0xD0093E75L,0xD0093E75L,(-1L),0x85A5A9EFL,(-1L),0xD0093E75L,0xD0093E75L,(-1L)},{(-3L),0x93DFA981L,1L,0x93DFA981L,(-3L),(-3L),0x93DFA981L,1L,0x93DFA981L},{0xD0093E75L,0x85A5A9EFL,(-10L),(-10L),0x85A5A9EFL,0xD0093E75L,0x85A5A9EFL,(-10L),(-10L)},{(-3L),(-3L),0x93DFA981L,1L,0x93DFA981L,(-3L),(-3L),0x93DFA981L,1L},{(-1L),0x85A5A9EFL,(-1L),0xD0093E75L,0xD0093E75L,(-1L),0x85A5A9EFL,(-1L),0xD0093E75L},{0xC8936D7EL,0x93DFA981L,0x93DFA981L,0xC8936D7EL,0x50179415L,0xC8936D7EL,0x93DFA981L,0x93DFA981L,0xC8936D7EL},{(-1L),0xD0093E75L,(-10L),0xD0093E75L,(-1L),(-1L),0xD0093E75L,(-10L),0xD0093E75L},{0x93DFA981L,0x50179415L,1L,1L,0x50179415L,0x93DFA981L,0x50179415L,1L,1L}};
                    uint8_t l_6683[8][1][2];
                    uint16_t l_6691 = 0UL;
                    uint32_t l_6714 = 0x983D8C45L;
                    int i, j, k;
                    for (i = 0; i < 8; i++)
                    {
                        for (j = 0; j < 1; j++)
                        {
                            for (k = 0; k < 2; k++)
                                ;
l_6800 += 1;


                    ;
                        }
                    }

                    for (g_3317 = 0; (g_3317 > 60); g_3317 = safe_add_func_int32_t_s_s(g_3317, 7))
                    {
                        int32_t l_6563 = 0x5FDE8295L;
                        g_240 = ((0x56FDL ^ ((g_5446[5] = (g_2580[0][7] = (i = ((safe_sub_func_uint8_t_u_u((g_4423[5] = ((safe_lshift_func_uint16_t_u_s((0xD1L & g_2580[1][1]), 4)) , ((safe_sub_func_int8_t_s_s(((((((l_6564[6] = (l_6533 = (l_6537 == (l_6548[1][0] || (safe_lshift_func_int16_t_s_u(((safe_div_func_int16_t_s_s((safe_add_func_uint8_t_u_u((l_6539 = (safe_lshift_func_int16_t_s_s(l_6539, 7))), g_3463)), (safe_sub_func_uint32_t_u_u((safe_add_func_int32_t_s_s((l_6479[0] , (safe_mod_func_int16_t_s_s((g_4423[1] , l_6563), g_13[4]))), l_6261)), g_5512)))) && g_3193), l_6537)))))) && 1L) >= g_1368) , 0x0E33C989L) < l_6539) , g_496[2]), g_98[1][3])) , 0xCFL))), l_6518)) , 0xDE943ADAL)))) , (-8L))) <= l_6548[0][0]);
                    }
                    for (g_3463 = 0; (g_3463 > 6); g_3463 = safe_add_func_uint8_t_u_u(g_3463, 3))
                    {
                        uint16_t l_6626 = 0xCAB1L;
                        l_6602[4][3] = (((safe_add_func_int8_t_s_s((+((((safe_mod_func_int32_t_s_s(((((safe_div_func_int16_t_s_s((safe_mod_func_uint16_t_u_u((safe_rshift_func_int16_t_s_s((-5L), ((safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(g_9, (safe_div_func_uint8_t_u_u(((!(g_3109[1] , (safe_sub_func_int8_t_s_s((g_3935[3][2] , (~((safe_rshift_func_int8_t_s_u(((safe_rshift_func_int8_t_s_u((safe_add_func_uint16_t_u_u((g_3109[0] = (((((safe_lshift_func_int8_t_s_u((0xB1FCL == ((safe_lshift_func_int8_t_s_u(((g_5225 < (5UL > ((l_6537 , g_275) < BpBpBbg_6029))) || l_5888), l_6518)) && g_3193)), 2)) >= g_154) , 0UL) || 0UL) >= 0xEF1D057DL)), g_5210[0])), l_6539)) != l_6539), 5)) ^ l_6137))), g_1684[0])))) | l_6147), g_2467)))), l_6748)) & g_1368))), l_5888)), g_1368)) >= 1UL) , l_6548[1][0]) > g_469), l_6537)) > 65528UL) > l_6539) , l_6537)), g_2853[1][6][5])) | l_6601) != l_6539);
                        ;
                        ;
                        ;
                    }
                    if ((0x67L < (safe_sub_func_uint8_t_u_u((!l_6537), l_6539))))
                    {
                        int16_t l_6663[7][2][3] = {{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}},{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}},{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}},{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}},{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}},{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}},{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}}};
                        int i, j, k;

for (k = 0; k < 7; k++)
    {
        transparent_crc(g_4423[k], "g_4423[k]", g_204);
        if (g_204) printf("index = [%d]\n", k);

    };


                    ;

for (BGBGBcg_1368 = 14; (BGBGBcg_1368 == 2); BGBGBcg_1368 = safe_sub_func_uint16_t_u_u(BGBGBcg_1368, 2))
                    {
                        l_6646 = ((safe_lshift_func_int16_t_s_s((((-4L) && 0x69F87D9EL) > ((((safe_div_func_uint8_t_u_u((0x8D41E633L == 0xDFEC0DF3L), (safe_add_func_int16_t_s_s((((safe_lshift_func_uint8_t_u_s(l_6479[0], 3)) == (((safe_lshift_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u(l_6539, (l_6539 = (safe_mod_func_int32_t_s_s(((safe_lshift_func_uint8_t_u_u(l_5910, l_6533)) != 0xD3B415BAL), g_335))))) && g_1370[2]), 14)) < g_5446[2]) , 0UL)) && g_1368), l_5910)))) >= 9UL) | g_34[0]) , 0UL)), 3)) >= (-9L));
                        if (g_1798[5][2])
                            continue;
                        return g_3486;
                    };


                    l_6602[3][3] = (((safe_add_func_uint8_t_u_u((((((~(g_13[4] || l_6646)) , (-6L)) == ((((l_6152 , (!0x19144B7AL)) == ((l_6539 ^ ((g_1684[0] = g_2422) & ((safe_sub_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(l_6683[1][0][1], (g_1368 = (safe_sub_func_uint32_t_u_u((safe_sub_func_int8_t_s_s(0x85L, 1L)), l_6663[4][1][2]))))), 0x49BEBD1CL)) > g_204))) != 0xF833L)) ^ l_6539) > g_472)) != 0UL) > g_275), 8L)) < 9L) , g_240);
                        return g_1288;
                    }
                    else
                    {
                        int8_t l_6690 = 0x3BL;
                        uint8_t l_6713 = 250UL;
                        l_6690 = (safe_add_func_uint16_t_u_u((g_275 <= 0x48E5L), g_2580[0][7]));
                        g_2580[1][6] = (l_6539 = 1L);
                        ;
                        l_6711 = (safe_add_func_int16_t_s_s((+l_6691), (((safe_rshift_func_uint8_t_u_u((l_6713 = ((g_469 = ((safe_sub_func_int8_t_s_s((safe_mod_func_int32_t_s_s((l_6539 = (l_6602[4][3] > (safe_lshift_func_int16_t_s_s(g_5210[0], 14)))), (g_240 = (safe_lshift_func_uint16_t_u_s(0xC06CL, (((g_5512 , (safe_div_func_uint32_t_u_u((l_6539 <= l_6690), (safe_div_func_uint8_t_u_u((g_154 & (((safe_sub_func_uint16_t_u_u(l_33, g_3463)) >= l_6539) | l_6711)), 7UL))))) > 0xA138B695L) || l_6712)))))), 0x4DL)) && g_5225)) , g_275)), l_5888)) < l_6714) >= l_6539)));
                    }
                }

for (g_2440 = 0; g_2440 < 1; g_2440++)
                        {
                            for (l_5986 = 0; l_5986 < 2; l_5986++)
                                l_6683[l_5986][g_2440][l_5986] = 253UL;
                        };


                    l_6726 = (safe_sub_func_int8_t_s_s(((0x4536L <= (l_6137 < (safe_rshift_func_int16_t_s_u(5L, 5)))) ^ ((((g_506 = ((+(((safe_mod_func_int8_t_s_s((safe_sub_func_int32_t_s_s((g_3193 , (0x210FF5B6L | (0x74DCL < 0xB288L))), (g_98[2][4] != (((((safe_sub_func_uint8_t_u_u(l_6748, 0xF7L)) >= g_1684[0]) & l_6711) <= g_496[0]) | 0UL)))), g_1798[5][2])) & l_6539) <= l_5888)) ^ 0x4460A150L)) < g_240) < (-1L)) , l_6711)), g_472));
                g_240 = (g_506 = (safe_mod_func_uint32_t_u_u(((g_2422 = l_6539) > ((0L == (((safe_sub_func_int16_t_s_s(((safe_add_func_int32_t_s_s((~0xDDL), (safe_lshift_func_int16_t_s_u(((((((safe_rshift_func_uint16_t_u_u((((safe_div_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((g_759 >= (((safe_mod_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(BpBpBbg_6029, g_275)) , 0x54C7L), (l_6539 = l_6539))) >= (safe_div_func_uint16_t_u_u(g_3317, 0xC528L))) , 0xF1BECB8DL)) > 0x87L), 254UL)) < 0x85L) > l_6748), g_5225)) , l_33) == l_6147), 11)) <= g_2422) > g_3317) && g_3109[2]) , l_6625) < l_6137), 11)))) > l_6147), l_6646)) , 7UL) != l_6147)) <= l_6646)), 0xF898E381L)));
            }
            else
            {
                int32_t l_6759 = 0x3A01636DL;
                int32_t l_6768 = 0x6F04516FL;
                int8_t l_6844 = 0L;
                ;
                for (g_1345 = 19; (g_1345 >= 30); ++g_1345)
                {
                    int8_t l_6760 = 0L;
                    int32_t l_6772[5];
                    int32_t l_6824 = (-4L);
                    int i;
                    ;

for (l_6600 = 0; (l_6600 != 18); l_6600 = safe_add_func_uint8_t_u_u(l_6600, 4))
                    {
                        uint32_t l_572 = 0xC7D5EA36L;
                        int32_t l_576 = 0xC922E228L;
                        g_1370[0] = g_3193;
                        g_573 = (safe_lshift_func_int16_t_s_u((safe_add_func_uint32_t_u_u(l_6691, (~0xC3L))), 12));
                        l_6160 = (j , ((safe_rshift_func_int8_t_s_u(((safe_div_func_uint32_t_u_u(1UL, (safe_lshift_func_uint8_t_u_s((g_1369 = (((safe_unary_minus_func_uint8_t_u((safe_rshift_func_int16_t_s_u((safe_rshift_func_uint8_t_u_s((l_6711 < g_3193), (safe_sub_func_int16_t_s_s((((safe_lshift_func_int16_t_s_u(l_5929, 9)) , (safe_add_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_lshift_func_int8_t_s_u((l_572 , (l_6762 >= (((g_3193 < (safe_lshift_func_int16_t_s_u((0xD2672DD7L < g_897), 10))) >= l_6711) == l_6762))), 3)), g_3193)), BGBGBbg_335))) | 0x5067L), g_3193)))), g_34[0])))) | 0x6831L) == 0xCB61BDDEL)), 7)))) < l_6711), 0)) || g_573));
                        l_576 = l_6280;
                    };


                    if ((g_472 == (l_6147 = l_6564[6])))
                    {
                        int32_t l_6761 = 0x97130E1AL;
                        uint32_t l_6767 = 0UL;
                        ;
                    }
                    else
                    {
                        int16_t l_6773[2][2][4];
                        int i, j, k;
                        for (i = 0; i < 2; i++)
                        {

                        }
                        l_6772[1] = (safe_lshift_func_uint16_t_u_u(g_3463, 8));
                        l_6773[0][1][3] = ((g_469 >= g_13[2]) > l_6261);
                        l_6774[2][6][1] = BpBpBbg_6029;
                        g_2580[2][8] = (255UL >= (-1L));
                    }

                    for (l_6748 = 0; (l_6748 == 48); l_6748 = safe_add_func_int8_t_s_s(l_6748, 8))
                    {
                        uint8_t l_6812 = 0xF2L;
                        int32_t l_6821 = 2L;
                        const int32_t l_6822 = 1L;
                        g_2853[1][5][5] = (((safe_mod_func_uint32_t_u_u((248UL ^ (((-1L) < 0x329899BCL) < 0xE371L)), (safe_mod_func_int32_t_s_s(((safe_add_func_int8_t_s_s((((l_6136[0] , (safe_rshift_func_int8_t_s_s(l_6800, 0))) ^ 0x1EB49F35L) >= (((safe_unary_minus_func_uint32_t_u(l_6768)) ^ l_6772[1]) < g_506)), g_3193)) && (-8L)), 0x148CBAA3L)))) > 0x3D42L) , l_6759);
                        g_5446[7] = (safe_rshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u((l_6518 = ((l_6824 = (l_6772[4] , (l_6712 & (l_6646 = ((g_240 != (safe_lshift_func_int8_t_s_u(((l_6812 | (((g_5446[5] > (l_6152 = l_6759)) , (l_6768 & ((l_6759 = (((safe_mod_func_int16_t_s_s((g_1288 = (safe_rshift_func_uint16_t_u_s((((safe_mod_func_uint8_t_u_u(((((l_6772[0] = l_6261) > l_6821) <= l_6759) > 0x2E61L), 0x04L)) >= l_6822) < 0UL), 14))), g_2853[0][6][6])) >= 0xD5ADL) == l_6768)) & g_34[0]))) == 0x9711BB0FL)) && g_2580[1][7]), 2))) != (-2L)))))) == g_2852)), g_5210[0])) & l_5888), 2)) <= l_6147), g_5512)), g_3935[3][2]));
                        g_3935[3][2] = 0x29BBFD1AL;
                    }

for (i = 0; i < 3; i++)
                    g_1370[i] = 0L;

                    for (g_1138 = 14; (g_1138 == 2); g_1138 = safe_sub_func_uint16_t_u_u(g_1138, 2))
                    {
                        ;
                        ;
                        return g_240;
                    }
                }
            }
        }
        else
        {
            l_6539 = g_4423[4];
            return g_2467;
        };


                    for (k = 0; k < 2; k++)
                                l_6683[i][j][k] = 253UL;
                        }
                    }


l_6825 += 1;




{
                    uint8_t l_5432 = 5UL;
                    if (l_5432)
                        break;
                }


                    if ((0x67L < (safe_sub_func_uint8_t_u_u((!l_6537), l_5943))))
                    {
                        int16_t l_6663[7][2][3] = {{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}},{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}},{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}},{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}},{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}},{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}},{{0x0BC1L,0x0BC1L,0x0BC1L},{3L,3L,3L}}};
                        int i, j, k;


{
                        int i, j;
                        g_204 = (safe_mod_func_int32_t_s_s(((l_6711 = ((safe_div_func_int16_t_s_s(g_2580[l_6627][l_6627], l_6536)) || (safe_add_func_uint8_t_u_u((g_3486 = (safe_add_func_uint16_t_u_u(l_6147, ((g_2422 , ((0x55D10309L == ((safe_div_func_int32_t_s_s((safe_div_func_int32_t_s_s((246UL < (((BpBpBfg_9 < (!((((l_6539 = ((65526UL & 0xCE64L) | (-10L))) ^ 0x6261DD20L) < 0x84L) & l_6711))) != 0x9048L) <= g_3486)), l_6536)), g_4475)) <= l_6152)) , g_68)) >= 0xE2C7L)))), 0x0EL)))) || 0xB02CL), 2UL));
                    }

                    ;



for (g_240 = 0; g_240 < 9; g_240++)
        {

        }
if (g_98[1][3])
                break;

                    ;


                    g_3935[3][2] = (((g_6029 = (safe_div_func_uint32_t_u_u((safe_mod_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s(((g_98[4][4] = (safe_rshift_func_uint8_t_u_u((l_6602[2][6] ^ (l_6663[4][1][2] ^ ((((-9L) & ((safe_sub_func_int16_t_s_s(g_6029, (0x19983A2CL ^ ((safe_unary_minus_func_int32_t_s((g_1288 , 0x0D7EF8BEL))) || (safe_lshift_func_uint16_t_u_s(((safe_div_func_uint32_t_u_u(l_6663[0][1][2], (safe_lshift_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(g_1370[2], g_2852)), 1)))) && g_2422), g_2853[3][0][6])))))) | l_6074)) > l_6539) && 0x67C1L))), g_469))) <= g_2852), 1UL)), 3)), l_6548[1][0])), l_6602[4][3])), l_10))) & l_6663[4][1][2]) >= 0x77L);


if ((g_6428 & (((g_240 = ((safe_rshift_func_uint16_t_u_u((((((((safe_div_func_int32_t_s_s(g_335, (safe_mod_func_int32_t_s_s(((safe_mod_func_int16_t_s_s(1L, (-8L))) < (((safe_div_func_uint16_t_u_u((g_1369 != ((safe_div_func_uint8_t_u_u((0x57L <= ((l_5888 = ((k = l_10) >= (((safe_mod_func_int16_t_s_s(l_6167, g_2580[2][1])) , 0UL) >= g_3109[0]))) , 0xB3L)), l_6136[1])) <= g_1370[1])), k)) != 0L) ^ 65526UL)), k)))) == 0x9FE2L) || l_6537) < l_6646) <= 0xB7FBL) >= g_3109[2]) ^ l_5888), 1)) || l_6500)) | (-1L)) <= 0xBEB42813L)))
                    {
                        uint32_t l_6538[6][1];
                        int i, j;
                        for (i = 0; i < 6; i++)
                        {
                            for (j = 0; j < 1; j++)
                                l_6538[i][j] = 0x22EB942DL;
                        }
                        l_6538[2][0] = g_1369;
                        g_275 = ((g_154 = g_5225) >= g_275);
                    }
                    else
                    {
                        g_1370[2] = g_759;
                        g_5446[5] = g_1369;
                    };


                    g_3172 -= 1;



{
                        l_10 = (g_1370[2] = (g_6428 | (safe_sub_func_int8_t_s_s(g_2580[0][7], g_76))));
                        g_2853[0][0][3] = ((safe_mod_func_uint8_t_u_u(g_76, l_5943)) ^ (0x9780L ^ (safe_rshift_func_int8_t_s_s(0xA1L, 2))));
                    }

                    l_6602[3][3] = (((safe_add_func_uint8_t_u_u((((((~(g_13[4] || g_4689)) , (-6L)) == ((((g_5512 , (!0x19144B7AL)) == ((l_6160 ^ ((g_1684[0] = g_2467) & ((safe_sub_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(l_6683[1][0][1], (g_184 = (safe_sub_func_uint32_t_u_u((safe_sub_func_int8_t_s_s(0x85L, 1L)), l_6663[4][1][2]))))), 0x49BEBD1CL)) > g_2043))) != 0xF833L)) ^ l_6539) > g_2852)) != 0UL) > g_506), 8L)) < 9L) , g_204);

{
                        uint32_t l_3777 = 0x65B9FE36L;

{
            transparent_crc(g_98[l_33][g_240], "g_98[l_33][g_240]", l_6627);
            ;

        }

                    l_6533 = g_3109[1];
                        ;
                    }


{
                        g_3935[(l_6646 + 2)][l_6762] = BGBGBg_352;
                        if (g_335)
                            break;
                        if (g_3935[(l_6646 + 2)][l_6762])
                            break;
                    }

                    return g_897;
                    }
                    else
                    {
                        int8_t l_6690 = 0x3BL;
                        uint8_t l_6713 = 250UL;

l_6539 += 1;


                    l_6690 = (safe_add_func_uint16_t_u_u((g_275 <= 0x48E5L), g_2580[0][7]));

{
                        int32_t l_2330 = 0xB0B48C1AL;
                        k = (safe_rshift_func_int16_t_s_s(6L, l_2330));
                        l_6536 = BGBGBbg_335;
                    }


{
                    for (l_5888 = 0; (l_5888 >= (-12)); l_5888 = safe_sub_func_uint32_t_u_u(l_5888, 8))
                    {
                        int8_t l_1197[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_1197[i] = 0xC1L;
                        l_33 = g_9;
                        if (g_3463)
                            continue;
                        l_33 = g_3193;
                        l_5986 = l_1197[0];
                    }
                    l_33 = (safe_rshift_func_uint8_t_u_s((g_9 | (~(-1L))), g_9));
                    l_6539 = ((safe_rshift_func_int8_t_s_u(g_3193, 4)) , g_3172);
                }

                    ;

{
                        uint32_t l_6538[6][1];
                        int i, j;

{
                        uint16_t l_6186 = 0UL;
                        g_2580[0][0] = (safe_lshift_func_int8_t_s_u(((l_6186 && ((l_6280 && (safe_div_func_int32_t_s_s(g_1599, (safe_sub_func_int8_t_s_s((65535UL ^ (~(g_172 > (g_1798[7][4] | (((safe_div_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u((safe_div_func_uint32_t_u_u(((safe_div_func_uint16_t_u_u((safe_div_func_uint8_t_u_u((g_573 = ((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_int16_t_s_s(g_352, ((safe_unary_minus_func_uint8_t_u(((safe_rshift_func_int8_t_s_u(((((safe_add_func_uint32_t_u_u((4294967291UL < (g_240 == 0UL)), g_5844)) && g_5446[3]) & g_34[l_6748]) ^ 0xB6L), g_1369)) , g_4423[1]))) , g_3935[0][0]))) | (-1L)), 6)) , g_1368)), l_6186)), g_1684[l_6748])) & l_6280), g_13[4])), 1)), 0x9145398FL)) & 0x92L) > g_3935[2][4]))))), (-1L)))))) != 5UL)) , g_335), l_6186));
                    }

                    for (i = 0; i < 6; i++)
                        {

if (l_6600)
                        continue;

                    for (j = 0; j < 1; j++)
                                l_6538[i][j] = 0x22EB942DL;
                        }
                        ;
                        l_33 = ((l_6823 = l_6074) >= l_33);
                    }

                    l_6691 = l_6537;

{
                        uint16_t l_6626 = 0xCAB1L;
                        l_6602[4][3] = (((safe_add_func_int8_t_s_s((+((((safe_mod_func_int32_t_s_s(((((safe_div_func_int16_t_s_s((safe_mod_func_uint16_t_u_u((safe_rshift_func_int16_t_s_s((-5L), ((safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(BpBpBbg_6029, (safe_div_func_uint8_t_u_u(((!(g_3109[1] , (safe_sub_func_int8_t_s_s((g_3935[3][2] , (~((safe_rshift_func_int8_t_s_u(((safe_rshift_func_int8_t_s_u((safe_add_func_uint16_t_u_u((g_3109[0] = (((((safe_lshift_func_int8_t_s_u((0xB1FCL == ((safe_lshift_func_int8_t_s_u(((g_5225 < (5UL > ((l_6537 , l_6726) < BpBpBbg_6029))) || l_5888), g_6029)) && BpBpBbg_6029)), 2)) >= l_6486) , 0UL) || 0UL) >= 0xEF1D057DL)), g_5210[0])), g_506)) != g_506), 5)) ^ l_6712))), g_1684[0])))) | g_3317), g_2467)))), BpBpBcg_3317)) & l_6800))), g_5844)), g_352)) >= 1UL) , l_6548[1][0]) > l_6137), l_6537)) > 65528UL) > g_506) , l_6537)), g_2853[1][6][5])) | g_352) != g_506);

BpBpBdg_154 -= 1;


                    ;
                        g_5446[7] = BpBpBbg_6029;
                        g_2580[0][7] = (((g_2853[0][6][6] = (safe_add_func_int16_t_s_s((((((safe_sub_func_uint16_t_u_u(l_6537, g_4423[1])) ^ (safe_rshift_func_uint16_t_u_s((l_6602[4][3] , (g_506 >= (((safe_rshift_func_int16_t_s_s((safe_div_func_uint8_t_u_u((safe_div_func_int16_t_s_s((g_240 || (safe_add_func_uint16_t_u_u(0x5F6EL, (((safe_sub_func_int32_t_s_s(((g_5844 = ((g_98[4][0] = 65535UL) || (safe_rshift_func_uint16_t_u_s(0x5B16L, ((BpBpBbg_6029 = g_98[1][3]) > g_5844))))) < g_2043), BpBpBbg_6029)) & l_5835[7]) , g_3600)))), 0x816DL)), l_6548[1][0])), 3)) | l_6261) || l_6647[9][1]))), 15))) ^ 0x30BAL) , g_3486) ^ g_1684[0]), (-1L)))) , 0x3FL) | 1UL);
                    }

                    ;
                    }
                }

for (l_5910 = 0; l_5910 < 2; l_5910++)
        l_6479[l_5910] = (-3L);

                    l_6726 = (safe_sub_func_int8_t_s_s(((0x4536L <= (g_1345 < (safe_rshift_func_int16_t_s_u(5L, 5)))) ^ ((((l_5986 = ((+(((safe_mod_func_int8_t_s_s((safe_sub_func_int32_t_s_s((g_4475 , (0x210FF5B6L | (0x74DCL < 0xB288L))), (g_98[2][4] != (((((safe_sub_func_uint8_t_u_u(l_6147, 0xF7L)) >= g_1684[0]) & l_6711) <= g_496[0]) | 0UL)))), g_1798[5][2])) & l_6539) <= g_335)) ^ 0x4460A150L)) < l_5910) < (-1L)) , l_6711)), g_2852));
                g_204 = (l_5986 = (safe_mod_func_uint32_t_u_u(((g_2422 = l_33) > ((0L == (((safe_sub_func_int16_t_s_s(((safe_add_func_int32_t_s_s((~0xDDL), (safe_lshift_func_int16_t_s_u(((((((safe_rshift_func_uint16_t_u_u((((safe_div_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((l_5929 >= (((safe_mod_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(g_6029, g_506)) , 0x54C7L), (l_6539 = l_6539))) >= (safe_div_func_uint16_t_u_u(g_3317, 0xC528L))) , 0xF1BECB8DL)) > 0x87L), 254UL)) < 0x85L) > l_6748), l_6074)) , l_6627) == g_1599), 11)) <= g_154) > g_3317) && g_3109[2]) , l_6625) < g_1345), 11)))) > g_1599), g_4689)) , 7UL) != l_6500)) <= g_4689)), 0xF898E381L)));
            }
            else
            {
                int32_t l_6759 = 0x3A01636DL;
                int32_t l_6768 = 0x6F04516FL;
                int8_t l_6844 = 0L;
                g_1370[1] = (0xB3D2CF8FL & g_13[0]);
                for (g_1368 = 19; (g_1368 >= 30); ++g_1368)
                {
                    int8_t l_6760 = 0L;
                    int32_t l_6772[5];
                    int32_t l_6824 = (-4L);
                    int i;

{
                        int16_t l_6079 = 1L;
                        if (l_5913)
                            break;

for (g_35 = 0; g_35 < 2; g_35 += 1)
                    {
                        l_6479[g_35] = 0x630AF406L;
                    };


                    g_2853[0][6][6] = (safe_sub_func_int8_t_s_s(0L, (g_1352 ^ (safe_sub_func_uint16_t_u_u(l_6079, g_76)))));
                        if (l_6079)
                            continue;

if (g_5512)
                            break;

                    if (l_5835[l_6759])
                            ;;
                    }

                    for (i = 0; i < 5; i++)
                        {
for (g_2440 = 0; g_2440 < 1; g_2440++)
                    g_5210[g_2440] = 0xAFDB92F1L;

                    l_6772[i] = 0L;}
                    if ((g_2852 == (g_1599 = l_6564[6])))
                    {
                        int32_t l_6761 = 0x97130E1AL;
                        uint32_t l_6767 = 0UL;
                        l_5943 = ((g_184 = (~(safe_mod_func_int16_t_s_s((((((+((safe_div_func_int32_t_s_s(((((safe_lshift_func_int16_t_s_u(((((l_6759 = (-1L)) & (l_6761 = (l_5910 , (l_6760 & g_1345)))) < l_6712) | 0x3AL), ((l_6762 = g_1370[0]) , (2UL >= (((safe_div_func_int16_t_s_s((((g_98[2][2] = (g_172 = ((((g_2853[0][6][6] = (safe_div_func_uint32_t_u_u((l_6627 = l_6760), g_3600))) , g_506) ^ l_6767) ^ l_6760))) ^ 1UL) | l_6768), 4L)) && 0x74CC71B1L) , 0x5542L))))) >= g_1370[2]) == 0x03L) & l_6760), g_2440)) ^ 4294967291UL)) , 1UL) <= g_3486) < g_1798[5][2]) > 0xFD327552L), l_6760)))) <= l_6147);
                    }
                    else
                    {
                        int16_t l_6773[2][2][4];
                        int i, j, k;
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 2; j++)
                            {
                                for (k = 0; k < 4; k++)
                                    ;;
                            }
                        }
                        l_6772[1] = (safe_lshift_func_uint16_t_u_u(g_6771, 8));
                        l_6773[0][1][3] = ((g_68 >= g_13[2]) > l_6261);


{
                        int i, j;
                        g_506 = (safe_mod_func_int32_t_s_s(((l_6759 = ((safe_div_func_int16_t_s_s(g_2580[l_6768][l_6768], l_5910)) || (safe_add_func_uint8_t_u_u((l_6160 = (safe_add_func_uint16_t_u_u(BpBpBcg_3317, ((l_6823 , ((0x55D10309L == ((safe_div_func_int32_t_s_s((safe_div_func_int32_t_s_s((246UL < (((g_3193 < (!((((l_6762 = ((65526UL & 0xCE64L) | (-10L))) ^ 0x6261DD20L) < 0x84L) & l_6759))) != 0x9048L) <= l_6160)), l_6536)), g_2852)) <= g_5512)) , g_6771)) >= 0xE2C7L)))), 0x0EL)))) || 0xB02CL), 2UL));
                    }

                    ;



{
                int16_t l_2060 = 0xDC69L;
                int32_t l_2061 = 0L;
                int32_t l_2062 = (-1L);
                int32_t l_2065 = 0xE44D0044L;
                l_2062 = ((g_172 != (l_2061 = l_2060)) >= 0x51BFL);
                if (l_2060)
                    continue;
                if (k)
                    continue;
                j = (0x49C60D4FL < ((g_759 , (((safe_lshift_func_uint16_t_u_s((0xDFC8L != l_2065), ((safe_sub_func_uint32_t_u_u(g_204, ((l_5929 == ((g_1370[1] = g_759) ^ g_759)) < (l_2065 && g_204)))) > g_759))) || g_76) == l_2065)) < g_759));
            }

                    l_6774[2][6][1] = g_6029;

for (g_3486 = 0; g_3486 < 10; g_3486++)
                l_6564[g_3486] = 0x3F83C38EL;

                    g_2580[2][8] = (255UL >= (-1L));
                    }

for (l_6726 = 0; l_6726 < 1; l_6726++)
                    {
{
                        l_6627 = (safe_sub_func_uint32_t_u_u(4294967288UL, BpBpBg_1369));
                    }

                    ;;}

                    for (g_759 = 0; (g_759 <= 7); g_759 += 1)
                    {
                        uint32_t l_6789 = 0x738E9352L;
                        g_204 = (safe_sub_func_int8_t_s_s(((safe_add_func_uint16_t_u_u(8UL, 0x9698L)) >= ((g_3193 > (safe_div_func_int8_t_s_s(0xEAL, g_506))) | ((safe_add_func_uint8_t_u_u(g_34[0], (g_9 = (safe_div_func_uint16_t_u_u(((((safe_lshift_func_uint8_t_u_u((l_6074 || g_6428), 2)) >= (safe_sub_func_int32_t_s_s((((l_6789 ^ g_5844) || g_34[0]) || g_897), g_2580[0][7]))) | g_4423[3]) | g_573), l_6774[0][7][2]))))) || l_6711))), g_184));
                    }
                    for (l_6147 = 0; (l_6147 == 48); l_6147 = safe_add_func_int8_t_s_s(l_6147, 8))
                    {
                        uint8_t l_6812 = 0xF2L;
                        int32_t l_6821 = 2L;
                        const int32_t l_6822 = 1L;
                        g_2853[1][5][5] = (((safe_mod_func_uint32_t_u_u((248UL ^ (((-1L) < 0x329899BCL) < 0xE371L)), (safe_mod_func_int32_t_s_s(((safe_add_func_int8_t_s_s((((l_6136[0] , (safe_rshift_func_int8_t_s_s(l_6800, 0))) ^ 0x1EB49F35L) >= (((safe_unary_minus_func_uint32_t_u(l_6768)) ^ l_6772[1]) < l_5986)), g_4475)) && (-8L)), 0x148CBAA3L)))) > 0x3D42L) , l_6759);

{

for (i = 29; (i != 28); i = safe_sub_func_int16_t_s_s(i, 7))
                    {
                        l_6627 = g_204;

g_1352 += 1;


                    l_6627 = (((g_4689 = (-5L)) , (~(7UL && ((g_34[0] && g_4475) != (safe_mod_func_uint8_t_u_u(1UL, (safe_div_func_uint16_t_u_u((((g_506 | (1UL ^ (g_4475 <= (l_5910 ^ g_5844)))) >= 0x083A407DL) ^ g_4475), 0x8056L)))))))) >= g_4475);
                    };


                    transparent_crc(g_4423[g_2440], "g_4423[g_2440]", g_2440);


    }

                    ;

{
        for (g_573 = 0; g_573 < 5; g_573++)
        {

g_87 += 1;


                    ;
            ;

        }
    }

                    g_3935[3][2] = 0x29BBFD1AL;
                    }

{
                    int16_t l_4268 = 0x35F2L;
                    l_4268 = g_2852;
                    ;
                }

                    for (l_6318 = 14; (l_6318 == 2); l_6318 = safe_sub_func_uint16_t_u_u(l_6318, 2))
                    {
                        l_6844 = ((safe_lshift_func_int16_t_s_s((((-4L) && 0x69F87D9EL) > ((((safe_div_func_uint8_t_u_u((0x8D41E633L == 0xDFEC0DF3L), (safe_add_func_int16_t_s_s((((safe_lshift_func_uint8_t_u_s(l_6479[0], 3)) == (((safe_lshift_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u(l_6824, (l_5943 = (safe_mod_func_int32_t_s_s(((safe_lshift_func_uint8_t_u_u(l_6536, l_6768)) != 0xD3B415BAL), g_5844))))) && g_1370[2]), 14)) < g_5446[2]) , 0UL)) && g_76), l_5986)))) >= 9UL) | g_34[0]) , 0UL)), 3)) >= (-9L));
                        if (g_1798[5][2])
                            {
if (g_34[0])
                            {
if (g_1370[(l_6500 + 1)])
                    {
                        int i, j;

{
                        uint8_t l_6812 = 0xF2L;
                        int32_t l_6821 = 2L;
                        const int32_t l_6822 = 1L;
                        g_2853[1][5][5] = (((safe_mod_func_uint32_t_u_u((248UL ^ (((-1L) < 0x329899BCL) < 0xE371L)), (safe_mod_func_int32_t_s_s(((safe_add_func_int8_t_s_s((((l_6136[0] , (safe_rshift_func_int8_t_s_s(g_1138, 0))) ^ 0x1EB49F35L) >= (((safe_unary_minus_func_uint32_t_u(l_10)) ^ l_6772[1]) < l_6536)), BpBpBfg_9)) && (-8L)), 0x148CBAA3L)))) > 0x3D42L) , l_10);
                        g_5446[7] = (safe_rshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u((BpBpBg_1369 = ((l_5943 = (l_6772[4] , (g_3463 & (l_6844 = ((g_2043 != (safe_lshift_func_int8_t_s_u(((l_6812 | (((g_5446[5] > (g_5844 = l_10)) , (l_10 & ((l_10 = (((safe_mod_func_int16_t_s_s((g_5844 = (safe_rshift_func_uint16_t_u_s((((safe_mod_func_uint8_t_u_u(((((l_6772[0] = g_1138) > l_6821) <= l_10) > 0x2E61L), 0x04L)) >= l_6822) < 0UL), 14))), g_2853[0][6][6])) >= 0xD5ADL) == l_10)) & g_34[0]))) == 0x9711BB0FL)) && g_2580[1][7]), 2))) != (-2L)))))) == l_6825)), g_5210[0])) & BGBGBeg_897), 2)) <= l_6147), l_5913)), g_3935[3][2]));
                        g_3935[3][2] = 0x29BBFD1AL;
                    }

                    ;
                        g_1370[(l_6500 + 1)] = (((g_335 || (safe_add_func_int16_t_s_s(((safe_sub_func_uint8_t_u_u(2UL, (((((safe_mod_func_int8_t_s_s((g_76 | ((safe_rshift_func_int8_t_s_s(l_6500, ((((((((((safe_add_func_uint8_t_u_u(0xFCL, ((((safe_add_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(g_34[0], (safe_sub_func_uint16_t_u_u((safe_sub_func_int16_t_s_s((((+(4294967295UL > ((~(((l_6760 || l_6800) & g_1138) , 0xC5CA8165L)) == g_34[l_6500]))) & 0xA24B7619L) || 0x35C36BF4L), g_1138)), g_34[l_6500])))), l_6760)) ^ l_10) < (-1L)) >= l_5835[0]))) ^ l_5835[6]) , l_6800) == g_98[4][4]) , 0xF0L) , g_34[0]) >= g_1370[(l_6500 + 1)]) , k) != 1L) || g_3109[2]))) , g_352)), 255UL)) < 1UL) == g_13[1]) < g_4423[2]) > l_6136[0]))) , k), g_1370[(l_6500 + 1)]))) < l_6533) > k);
                        ;
                        g_2580[3][6] = (k = (safe_div_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_u((safe_div_func_int8_t_s_s((!((safe_add_func_int16_t_s_s(l_10, ((safe_div_func_int8_t_s_s((g_1138 < (9UL ^ (safe_rshift_func_int16_t_s_u((safe_mod_func_int32_t_s_s((l_6760 = ((((g_5446[5] >= (-4L)) < (l_6800 == (l_6760 = (safe_rshift_func_uint16_t_u_u((255UL == l_5888), 13))))) >= ((((safe_sub_func_int8_t_s_s((safe_lshift_func_int8_t_s_s((((l_6600 && 0xF1L) , g_3935[3][2]) & 0x4AL), 4)), g_1370[(l_6500 + 1)])) , l_6500) , (-1L)) & l_10)) | g_1370[(l_6500 + 1)])), g_1138)), g_335)))), 0x99L)) , g_1370[(l_6500 + 1)]))) != 0x11739D61L)), g_496[2])), 5)) , g_76), g_759)));
                    }
                    else
                    {
                        const int32_t l_6407 = 0x90A736CAL;

{
                    for (g_240 = 7; (g_240 >= 1); g_240 -= 1)
                    {
                        int i, j;
                        l_6564[4] = g_1798[(l_6823 + 2)][g_240];
                    }
                }

                    g_2853[0][6][6] = ((k , ((safe_div_func_uint8_t_u_u(BpBpBeg_352, ((l_6800 > g_1370[1]) , l_6533))) , l_5835[0])) , (safe_div_func_uint8_t_u_u(((g_5225 , (safe_rshift_func_uint16_t_u_u(g_2580[0][7], l_6800))) , 0xC0L), l_6407)));
                    };


                    break;}


l_6760 += 1;


                    continue;}
                        return g_573;
                    }
                }
            }
        }
        else
        {
            ;
            return g_3172;
        }
    }
    else
    {
        int16_t l_6846 = 1L;
        ;
    }
    return g_2440;
}







inline static int32_t func_2(uint8_t p_3, uint8_t p_4, uint32_t p_5, int32_t p_6)
{
    return p_4;
}







static uint16_t func_15(int16_t p_16, uint8_t p_17)
{
    int32_t l_4564 = (-8L);
    int8_t l_4583 = (-1L);
    int32_t l_4584 = 9L;
    int32_t l_4585 = (-1L);
    int32_t l_4586 = 1L;
    int16_t l_4828 = 0xEB12L;
    int16_t l_4906 = 0L;
    uint32_t l_4921 = 18446744073709551615UL;
    uint32_t l_5181 = 0x7753BD21L;
    int16_t l_5308 = 0x3E8EL;
    int16_t l_5309 = 1L;
    uint16_t l_5358 = 0x6EFBL;
    uint8_t l_5406 = 255UL;
    int32_t l_5599 = (-9L);
    int8_t l_5729 = 0L;
    int32_t l_5763 = 9L;
lbl_5265:
    l_4586 = (safe_sub_func_uint16_t_u_u(65535UL, (safe_rshift_func_int8_t_s_s((((safe_mod_func_int8_t_s_s((l_4564 = ((safe_mod_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_sub_func_int16_t_s_s((safe_add_func_int32_t_s_s((((safe_div_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u(((l_4564 == (l_4585 = (l_4564 >= (safe_add_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u((safe_add_func_uint32_t_u_u((((g_4475 = g_1684[0]) | (safe_unary_minus_func_int32_t_s((g_573 ^ (+1L))))) | ((0x9F0EB56FL >= (((l_4584 = ((safe_mod_func_int32_t_s_s((((((safe_mod_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(7UL, (((safe_mod_func_uint16_t_u_u(l_4583, g_204)) , (-8L)) >= p_16))), g_184)), l_4564)) , 65535UL) && l_4564) >= l_4583) , l_4583), 0xBB7A2DCAL)) <= 4294967295UL)) ^ l_4564) < l_4564)) | g_496[2])), 4294967293UL)), g_1369)), (-1L)))))) | g_335), 0)), p_17)) ^ g_2853[2][1][4]) & 0x016AFD81L), g_2422)), p_16)), l_4583)), 0xF2CB1982L)) != l_4583)), l_4583)) < l_4583) , 1L), l_4583))));
    if (p_16)
    {
        uint32_t l_4603[2][5] = {{4294967295UL,0xDB78D99EL,4294967295UL,0xDB78D99EL,4294967295UL},{4294967295UL,0xDB78D99EL,4294967295UL,0xDB78D99EL,4294967295UL}};
        int32_t l_4604 = 0xF5237A90L;
        int i, j;
        l_4564 = (safe_add_func_int32_t_s_s((l_4604 = ((p_16 < g_1798[5][2]) && (((l_4585 & ((safe_lshift_func_uint8_t_u_u(((((p_17 == (((safe_lshift_func_uint16_t_u_s((safe_div_func_int16_t_s_s((g_1684[0] = ((g_1368 = (safe_div_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_s(((safe_lshift_func_int8_t_s_u((((p_16 , l_4584) <= (safe_add_func_int32_t_s_s(l_4603[1][0], (g_3486 == 0x68L)))) , p_17), 7)) != 0x8D6DE5E7L), 2)), 0x79084F30L))) & p_16)), 65532UL)), 8)) && l_4586) && 0x1FL)) & g_9) && 1L) != l_4585), g_1352)) < (-1L))) && l_4603[0][3]) ^ g_897))), g_1352));
        return g_897;
    }
    else
    {
        int32_t l_4634 = 0x0E74DC79L;
        int32_t l_4635 = 0x09FDD7E9L;
        int32_t l_4663[1][4][7] = {{{0x34AE393EL,0x34AE393EL,0x34AE393EL,0x34AE393EL,0x34AE393EL,0x34AE393EL,0x34AE393EL},{8L,0xFD0D9A2CL,8L,0xFD0D9A2CL,8L,0xFD0D9A2CL,8L},{0x34AE393EL,0x34AE393EL,0x34AE393EL,0x34AE393EL,0x34AE393EL,0x34AE393EL,0x34AE393EL},{8L,0xFD0D9A2CL,8L,0xFD0D9A2CL,8L,0xFD0D9A2CL,8L}}};
        int32_t l_4665 = 0x4E35623BL;
        int32_t l_4667 = 0xEF4287E4L;
        uint16_t l_4686 = 1UL;
        int32_t l_4917 = 0x67041EC9L;
        int16_t l_5006 = 7L;
        int16_t l_5122 = 0x6D14L;
        int32_t l_5135[4][8][5] = {{{0xE2C3793FL,0x21E523A7L,0x2C98830FL,0xD9F1031CL,0xD9F1031CL},{0x15EEF8F9L,0xD69AD587L,0x15EEF8F9L,0x7DDDAA8FL,0xFF6CD93CL},{0x2C98830FL,0x21E523A7L,0xE2C3793FL,0x3BA06D40L,0x1965DA30L},{0xE36F8E0CL,0L,0L,0xE36F8E0CL,0x15EEF8F9L},{0x5687220DL,0xFEA49462L,0xE2C3793FL,0x1965DA30L,0x21E523A7L},{0x21C70A9CL,0x1AE73F42L,0x15EEF8F9L,0x1AE73F42L,0x21C70A9CL},{0xFEA49462L,0x3BA06D40L,0x2C98830FL,0x1965DA30L,0x6C118C3AL},{(-1L),0x7D105BD0L,0xE36F8E0CL,0xE36F8E0CL,0x7D105BD0L}},{{0xD9F1031CL,0xE2C3793FL,0x5687220DL,0x3BA06D40L,0x6C118C3AL},{0x1AE73F42L,0xE36F8E0CL,0x21C70A9CL,0x7DDDAA8FL,0x21C70A9CL},{0x6C118C3AL,0x6C118C3AL,0xFEA49462L,0xD9F1031CL,0x21E523A7L},{0x1AE73F42L,0x9804F118L,(-1L),0x15EEF8F9L,0x15EEF8F9L},{0xD9F1031CL,9L,0xD9F1031CL,0x02EC1690L,0x1965DA30L},{(-1L),0x9804F118L,0x1AE73F42L,0x7D105BD0L,0xFF6CD93CL},{0xFEA49462L,0x6C118C3AL,0x6C118C3AL,0xFEA49462L,0xD9F1031CL},{0x21C70A9CL,0xE36F8E0CL,0x1AE73F42L,0xFF6CD93CL,0x9804F118L}},{{0x5687220DL,0xE2C3793FL,0xD9F1031CL,0xE2C3793FL,0x5687220DL},{0xE36F8E0CL,0x7D105BD0L,(-1L),0xFF6CD93CL,0L},{0x2C98830FL,0x3BA06D40L,0xFEA49462L,0xFEA49462L,0x3BA06D40L},{0x15EEF8F9L,0x1AE73F42L,0x21C70A9CL,0x7D105BD0L,0L},{0xE2C3793FL,0xFEA49462L,0x5687220DL,0x02EC1690L,0x5687220DL},{0L,0L,0xE36F8E0CL,0x15EEF8F9L,0x9804F118L},{0xE2C3793FL,0x21E523A7L,0x2C98830FL,0xD9F1031CL,0xD9F1031CL},{0x15EEF8F9L,0xD69AD587L,0x7D105BD0L,0x1AE73F42L,0x9804F118L}},{{0xD9F1031CL,0x5687220DL,9L,0xFEA49462L,0x21E523A7L},{0L,0x7DDDAA8FL,0x7DDDAA8FL,0L,0x7D105BD0L},{0x2C98830FL,0x6C118C3AL,9L,0x21E523A7L,0x5687220DL},{(-1L),0xD69AD587L,0x7D105BD0L,0xD69AD587L,(-1L)},{0x6C118C3AL,0xFEA49462L,0xD9F1031CL,0x21E523A7L,0x02EC1690L},{0x15EEF8F9L,0xE36F8E0CL,0L,0L,0xE36F8E0CL},{0x3BA06D40L,9L,0x2C98830FL,0xFEA49462L,0x02EC1690L},{0xD69AD587L,0L,(-1L),0x1AE73F42L,(-1L)}}};
        uint32_t l_5222[3];
        uint8_t l_5223 = 0xDBL;
        const uint32_t l_5262 = 0UL;
        int16_t l_5421 = 0xAAFAL;
        int32_t l_5511 = 1L;
        int32_t l_5554 = 1L;
        uint32_t l_5591[4] = {4294967295UL,4294967295UL,4294967295UL,4294967295UL};
        uint8_t l_5696 = 1UL;
        uint32_t l_5834[5][4] = {{4294967295UL,4294967295UL,4294967295UL,0x3AD11B73L},{4294967295UL,0x3AD11B73L,0x3AD11B73L,4294967295UL},{0x43C70C55L,0x3AD11B73L,4294967295UL,0x3AD11B73L},{0x3AD11B73L,4294967295UL,4294967295UL,4294967295UL},{0x43C70C55L,0x43C70C55L,0x3AD11B73L,4294967295UL}};
        int i, j, k;
        for (i = 0; i < 3; i++)
            l_5222[i] = 4294967295UL;

;


                    if (((l_4586 = (safe_add_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(((safe_unary_minus_func_uint32_t_u((safe_rshift_func_uint16_t_u_s(g_2580[0][5], 13)))) , (safe_sub_func_uint8_t_u_u(g_352, (safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s((0x11B74D00L < ((((safe_div_func_int8_t_s_s((safe_add_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(((l_4635 = (safe_mod_func_uint32_t_u_u(((safe_div_func_uint8_t_u_u(0xAFL, l_4584)) , (0x9366D778L && (safe_add_func_int32_t_s_s((p_16 == (2L & (safe_lshift_func_int16_t_s_s(g_335, 2)))), l_4634)))), (-7L)))) ^ g_275), g_3935[1][1])), p_17)), g_240)), l_4634)) <= p_17) , p_17) > l_4564)), 1)), p_17))))), 9)), 0x90L))) , (-1L)))
        {
            int16_t l_4650 = 0xE767L;
            int32_t l_4651 = 0x1DAA88FAL;
            const int8_t l_4664 = 1L;
            if ((safe_add_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u(((((+(safe_lshift_func_uint8_t_u_s(l_4635, g_154))) || ((((g_897 = ((((safe_div_func_int32_t_s_s(((safe_mod_func_int8_t_s_s((safe_sub_func_int32_t_s_s(l_4634, (g_2853[0][6][6] = (l_4651 = (~(g_1352 && (((p_17 && (((0xF445F9B3L ^ 0x69972517L) , (g_335 && (g_1352 = l_4650))) != 0xD406L)) != g_1798[5][2]) == p_16))))))), 4L)) ^ p_16), 0x77C0CDE8L)) > g_496[1]) == p_16) != p_16)) & g_3193) & l_4635) || p_16)) < 0x071C84E0L) == l_4586), p_16)), p_17)))
            {
                int8_t l_4666[8][2] = {{(-1L),(-1L)},{(-1L),(-1L)},{(-1L),(-1L)},{(-1L),(-1L)},{(-1L),(-1L)},{(-1L),(-1L)},{(-1L),(-1L)},{(-1L),(-1L)}};
                int32_t l_4687[1];
                uint32_t l_4688 = 0xB2CF736BL;
                int i, j;
                for (i = 0; i < 1; i++)
                    {
for (g_3486 = 0; g_3486 < 5; g_3486++)
        {
            transparent_crc(g_3935[l_4917][g_3486], "g_3935[l_4917][g_3486]", l_4667);
            if (l_4667) printf("index = [%d][%d]\n", l_4917, g_3486);

        };


                    l_4687[i] = 0xAFDB92F1L;}
                l_4667 = ((0x8BE15938L != (((safe_mod_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s(((l_4665 = ((((g_2422 = ((safe_rshift_func_uint16_t_u_u((~l_4584), (l_4635 = g_496[2]))) || ((((g_34[0] = (((l_4564 = ((((l_4635 < ((((0x1FL == l_4651) , (safe_add_func_uint16_t_u_u(g_472, p_16))) ^ (l_4663[0][3][4] = g_2580[0][7])) <= l_4650)) , p_16) && l_4564) <= l_4583)) & l_4664) != p_16)) & 0x92L) == p_16) < p_16))) ^ p_17) == p_17) != p_17)) <= l_4586), l_4634)), l_4666[5][0])), l_4634)) & l_4585) , 0xF63D4785L)) && l_4663[0][0][1]);
                if ((safe_unary_minus_func_uint16_t_u(l_4666[0][0])))
                {
                    const uint32_t l_4682 = 2UL;
                    int32_t l_4683[6][5][3] = {{{0x7C576993L,0x7C576993L,0x2596989BL},{(-1L),0xDD66A706L,(-1L)},{0x2596989BL,0x20D51271L,0L},{0x4AC91297L,1L,8L},{0xE349AC0DL,0x2596989BL,0L}},{{1L,0x7C576993L,(-1L)},{(-9L),0x6E4E5960L,0x2596989BL},{0x2596989BL,0x700BCBCBL,0L},{8L,0x700BCBCBL,8L},{0xD844DD7EL,0x6E4E5960L,0L}},{{(-6L),0x7C576993L,0x6E4E5960L},{3L,0x2596989BL,0xDD66A706L},{0x2596989BL,1L,0xBF153F82L},{3L,0x20D51271L,8L},{(-6L),0xDD66A706L,1L}},{{0xD844DD7EL,0x7C576993L,0L},{8L,0L,0L},{0x2596989BL,0x822ECC79L,1L},{(-9L),0x5B23A06AL,8L},{1L,(-1L),0xBF153F82L}},{{0xE349AC0DL,0x7C576993L,0xDD66A706L},{0x4AC91297L,(-1L),0x6E4E5960L},{0x2596989BL,0x5B23A06AL,0L},{(-1L),0x822ECC79L,8L},{0x7C576993L,0L,0L}},{{0x7C576993L,0x7C576993L,0x2596989BL},{(-1L),0xDD66A706L,(-1L)},{0x2596989BL,0x20D51271L,0L},{0x4AC91297L,1L,8L},{0xE349AC0DL,0x2596989BL,0L}}};
                    int i, j, k;

                }
                else
                {
                    return p_17;
                }
            }
            else
            {
                const int32_t l_4714 = 8L;
                int32_t l_4727 = 5L;
                ;


{
                    int32_t l_1178 = 0x6371896CL;
                    l_4667 = (l_1178 = 1L);
                    l_5554 = g_1138;
                    for (l_4727 = 29; (l_4727 != 28); l_4727 = safe_sub_func_int16_t_s_s(l_4727, 7))
                    {
                        l_5554 = g_2440;
                        l_5554 = (((g_2422 = (-5L)) , (~(7UL && ((g_34[0] && g_6029) != (safe_mod_func_uint8_t_u_u(1UL, (safe_div_func_uint16_t_u_u((((l_1178 | (1UL ^ (g_6029 <= (l_4585 ^ g_1288)))) >= 0x083A407DL) ^ g_6029), 0x8056L)))))))) >= g_6029);
                    }
                    for (g_68 = 0; (g_68 >= 21); g_68 = safe_add_func_uint16_t_u_u(g_68, 2))
                    {
                        uint32_t l_1192 = 0UL;
                        l_4635 = (safe_unary_minus_func_uint16_t_u((g_34[0] || g_6029)));
                        l_1192 = g_1288;
                    }
                }

                    for (g_204 = 0; g_204 < 1; g_204++)
                    g_5210[g_204] = 0xAFDB92F1L;

                    lbl_4784:
                for (g_4475 = 0; (g_4475 <= 0); g_4475 += 1)
                {
                    int32_t l_4711 = 0x150A892AL;
                    return l_4711;
                }
                l_4727 = (g_496[3] , ((0x95CFB441L < l_4665) == ((l_4714 > ((safe_div_func_int8_t_s_s((safe_div_func_int16_t_s_s((g_3935[3][2] != ((safe_add_func_int8_t_s_s((g_3600 = (safe_rshift_func_uint16_t_u_u((l_4651 , ((((p_16 > (((safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u(p_17, 4)), (g_1345 | 0xBFL))) , g_2440) , p_17)) != g_1599) != 0x4888L) | p_16)), p_17))), p_17)) <= l_4686)), 65535UL)), g_2853[2][0][0])) >= 0x9285L)) <= 0xCF7DA8D6L)));

g_172 += 1;


                    if ((g_2853[0][6][6] = (((safe_lshift_func_int16_t_s_u(g_496[2], g_1370[1])) < (safe_add_func_int8_t_s_s((!(safe_lshift_func_uint8_t_u_u((p_17 , 0x87L), 7))), l_4727))) == (safe_sub_func_uint16_t_u_u((safe_div_func_int8_t_s_s((safe_sub_func_int32_t_s_s(g_4423[4], (l_4635 = (safe_lshift_func_uint16_t_u_u(8UL, 15))))), p_17)), (safe_add_func_int8_t_s_s((l_4586 && g_68), p_16)))))))
                {
                    uint32_t l_4757[2][4][8] = {{{7UL,18446744073709551615UL,18446744073709551615UL,7UL,1UL,18446744073709551615UL,1UL,7UL},{18446744073709551615UL,1UL,18446744073709551615UL,18446744073709551615UL,0x6058AFA6L,0x6058AFA6L,18446744073709551615UL,18446744073709551615UL},{1UL,1UL,1UL,18446744073709551615UL,7UL,18446744073709551615UL,1UL,2UL},{2UL,18446744073709551615UL,0x6058AFA6L,1UL,1UL,0x6058AFA6L,18446744073709551615UL,2UL}},{{18446744073709551615UL,18446744073709551615UL,2UL,18446744073709551615UL,2UL,18446744073709551615UL,18446744073709551615UL,18446744073709551615UL},{18446744073709551615UL,18446744073709551615UL,0x6058AFA6L,0x6058AFA6L,18446744073709551615UL,18446744073709551615UL,1UL,18446744073709551615UL},{18446744073709551615UL,18446744073709551615UL,1UL,18446744073709551615UL,18446744073709551615UL,0x6058AFA6L,0x6058AFA6L,18446744073709551615UL},{18446744073709551615UL,18446744073709551615UL,18446744073709551615UL,18446744073709551615UL,2UL,18446744073709551615UL,2UL,18446744073709551615UL}}};
                    int i, j, k;
                    for (l_4727 = 6; (l_4727 < 11); l_4727++)
                    {
                        int16_t l_4762[8][8] = {{0x0037L,8L,0xF5D9L,0xD074L,0x7D90L,0xF907L,0xD074L,0x0037L},{2L,8L,0xBD15L,0x0127L,(-9L),0x0127L,0xBD15L,8L},{8L,0xBF8FL,1L,0x7D90L,0xBD15L,1L,0x0037L,2L},{0x0037L,0x72D3L,0xE4EFL,0x3542L,8L,0xF5A0L,0x0037L,0x0037L},{0x6055L,0x3542L,1L,1L,0x3542L,0x6055L,0xBD15L,0x72D3L},{0x3542L,0x6055L,0xBD15L,0x72D3L,0x0127L,1L,0xD074L,0x0127L},{0x72D3L,0x0037L,0xF5D9L,0x72D3L,8L,0xC4CCL,8L,0x72D3L},{0xBF8FL,8L,0xBF8FL,1L,0x7D90L,0xBD15L,1L,0x0037L}};
                        int32_t l_4763 = 1L;
                        int i, j;
                        l_4763 = (((l_4585 = ((safe_lshift_func_int8_t_s_s((((((l_4651 < (safe_mod_func_int8_t_s_s(g_3193, 0x65L))) , (l_4663[0][3][0] | (((((safe_add_func_int16_t_s_s(((((safe_div_func_uint8_t_u_u(((p_17 == (safe_mod_func_uint32_t_u_u(0UL, (l_4757[0][0][5] | ((safe_div_func_int8_t_s_s(0x9DL, (l_4762[2][0] = (safe_div_func_uint32_t_u_u(0x49F51FA9L, p_17))))) < 0x63F9F56CL))))) & 6L), l_4714)) , g_154) & g_335) , p_16), 1UL)) >= g_352) < 0x25389E08L) >= 0x8AD97483L) | p_16))) , p_17) > 0xE9L) , p_17), g_3109[1])) == p_16)) , 0x21L) == g_1684[0]);
                        if (g_154)
                            break;
                        l_4763 = (g_759 >= 0x0BA0C5D4L);
                    }
                }
                else
                {
                    l_4727 = ((safe_rshift_func_int16_t_s_u(p_16, 11)) & (safe_div_func_uint16_t_u_u(l_4714, (g_3193 ^ ((((l_4714 || (g_34[0] || g_98[1][2])) || (l_4585 >= ((((safe_lshift_func_uint8_t_u_s((l_4564 = g_496[2]), 6)) , l_4634) & p_17) != 0L))) , 1UL) , 0xFACEBDBFL)))));
                    for (g_2440 = 14; (g_2440 <= 24); ++g_2440)
                    {
                        uint32_t l_4783 = 0xFA8003DAL;


g_3463 += 1;


                    g_982 += 1;



g_1345 += 1;


                    g_2580[0][7] = ((safe_lshift_func_uint16_t_u_u((g_3109[1] = 1UL), g_1684[0])) && ((safe_add_func_uint32_t_u_u(p_17, (safe_sub_func_uint16_t_u_u((safe_mod_func_int32_t_s_s(((l_4663[0][3][4] = 0x23B55B44L) < (~((l_4651 = 3L) || ((safe_mod_func_uint16_t_u_u((l_4714 == 1L), g_184)) != (g_4689 , l_4583))))), g_1352)), l_4783)))) & 0x0F52FF10L));
                        if (p_16)
                            ;;
                        ;
                    }
                    ;
                }
            }
            ;
        }
        else
        {
            uint16_t l_4795[1];
            int32_t l_4808 = 1L;
            uint32_t l_4809 = 7UL;
            uint32_t l_4846 = 0xD9986394L;
            int32_t l_4868 = 0x86F8EDA4L;
            uint32_t l_4959 = 0x50188CF7L;
            int32_t l_4964 = 0x77963ADFL;
            int i;

;


                    ;

g_3317 += 1;


                    if ((g_1370[2] = (((safe_mod_func_uint32_t_u_u((safe_lshift_func_int8_t_s_u((safe_div_func_int32_t_s_s(((l_4808 = (p_16 && (safe_sub_func_int32_t_s_s((((((0x7EL || (g_4475 < g_98[1][3])) >= (((((((g_2853[2][0][6] = ((l_4585 = (l_4795[0] = (safe_rshift_func_int16_t_s_s(0xD965L, 1)))) < (safe_sub_func_uint32_t_u_u((l_4586 = (safe_lshift_func_int16_t_s_u((safe_rshift_func_int8_t_s_s((-5L), (l_4584 >= (safe_add_func_int16_t_s_s((safe_sub_func_int8_t_s_s((l_4564 = (p_17 , ((safe_mod_func_uint32_t_u_u(((((g_4689 >= l_4808) <= 0x0AE18CFDL) < p_17) && l_4635), 0x9E6D87A7L)) == (-7L)))), g_1599)), 4UL))))), l_4586))), 0xC35620DCL)))) <= g_240) == g_3463) | l_4584) & 0x4B90L) <= l_4809) == p_16)) <= 0UL) == 0x5F1DEF4DL) >= g_98[1][3]), l_4808)))) ^ 0x13DF8607L), l_4583)), p_16)), l_4583)) < 1L) | g_3486)))
            {
                int8_t l_4823 = (-7L);
                g_2580[0][7] = ((safe_sub_func_uint8_t_u_u((0xF3ABL <= 0UL), (g_1684[0] | (+(safe_lshift_func_int8_t_s_u((l_4665 , (0xAD75L == ((0x383731BAL == ((((g_4423[1] = (((((l_4586 | ((((((safe_add_func_uint16_t_u_u((((safe_add_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u(l_4823, (safe_mod_func_int32_t_s_s((safe_add_func_uint8_t_u_u(((l_4828 ^ g_4689) ^ l_4828), p_16)), l_4823)))), 0xD059L)), l_4823)) , l_4586) < 0L), g_4689)) || 6L) || g_1345) & l_4823) && g_1288) | g_759)) > g_352) >= 0xEBL) & p_16) , p_16)) & g_76) == 0x2F953A1DL) <= g_34[0])) <= p_17))), g_275)))))) || p_16);
            }
            else
            {
                uint32_t l_4859[5][7] = {{0x9E75FC84L,0x9E75FC84L,0x9E75FC84L,0x9E75FC84L,0x9E75FC84L,0x9E75FC84L,0x9E75FC84L},{4294967295UL,1UL,4294967295UL,1UL,4294967295UL,1UL,4294967295UL},{0x9E75FC84L,0x9E75FC84L,0x9E75FC84L,0x9E75FC84L,0x9E75FC84L,0x9E75FC84L,0x9E75FC84L},{4294967295UL,1UL,4294967295UL,1UL,4294967295UL,1UL,4294967295UL},{0x9E75FC84L,0x9E75FC84L,0x9E75FC84L,0x9E75FC84L,0x9E75FC84L,0x9E75FC84L,0x9E75FC84L}};
                int32_t l_4866 = (-7L);
                int32_t l_4914 = 0x4FE08E87L;
                int i, j;

l_5511 += 1;


                    lbl_4918:
                if (g_2580[0][7])
                {
                    int32_t l_4863 = 0xE0A13621L;
                    int32_t l_4869[4][8] = {{0xA43D8C7DL,(-1L),(-1L),0xA43D8C7DL,4L,0xA43D8C7DL,(-1L),(-1L)},{(-1L),4L,1L,1L,4L,(-1L),4L,1L},{0xA43D8C7DL,4L,0xA43D8C7DL,(-1L),(-1L),0xA43D8C7DL,4L,0xA43D8C7DL},{1L,(-1L),1L,(-1L),1L,1L,(-1L),1L}};
                    int i, j;
lbl_4870:
                    l_4846 = ((safe_add_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((safe_sub_func_int32_t_s_s(g_35, g_469)), (safe_add_func_int8_t_s_s((+(+l_4585)), (safe_rshift_func_uint16_t_u_s((g_506 >= g_4475), ((l_4586 != l_4663[0][0][4]) | l_4634))))))), (safe_rshift_func_int16_t_s_u((~(safe_rshift_func_uint16_t_u_s(l_4809, l_4586))), l_4795[0])))) , p_17);
                    for (g_1138 = 24; (g_1138 <= 29); ++g_1138)
                    {
                        return p_16;
                    }
                    for (l_4586 = 0; (l_4586 <= 26); ++l_4586)
                    {
                        uint32_t l_4867 = 0x16E59217L;
                        l_4584 = (safe_add_func_int16_t_s_s((p_17 | (safe_mod_func_uint8_t_u_u((((l_4869[0][0] = ((((l_4868 = (l_4585 = ((l_4635 = (g_1138 || (((((((+((~((((((((l_4859[0][6] = g_2580[0][7]) != ((p_16 >= (-1L)) < ((-1L) <= (!((g_2853[0][6][6] , (safe_lshift_func_uint16_t_u_u((l_4863 & (safe_sub_func_int8_t_s_s((p_17 ^ 0xADL), 0UL))), 11))) > g_1368))))) & l_4866) > 0L) >= g_3486) || 0xFCC8L) > l_4635) , g_573)) , 0x9BL)) >= g_2043) == l_4867) < l_4828) & p_17) , p_17) & 0L))) == 0x98L))) > 6L) ^ l_4867) == 4L)) <= 0x64CCL) == p_16), l_4866))), g_2580[0][0]));
                    }
                    if (g_2852)
                        goto lbl_4870;
                }
                else
                {
                    g_2580[0][7] = g_76;
                }

{
                        uint8_t l_1049 = 0x11L;
                        int32_t l_1055[7] = {0L,0L,0L,0L,0L,0L,0L};
                        int i;
                        l_1049 = (0x70L && (g_1345 != (g_98[3][3] <= (safe_mod_func_int8_t_s_s((safe_div_func_uint32_t_u_u((0xC84EL < (l_4586 , (((safe_rshift_func_int16_t_s_u(((((safe_mod_func_uint32_t_u_u(3UL, (safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((g_76 = ((safe_add_func_uint32_t_u_u(0UL, (safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_s((((l_5599 = ((safe_div_func_uint32_t_u_u((4294967293UL == ((0x53D2L > l_4914) | l_4914)), l_4914)) != 0xF29CL)) & g_1599) , g_1369), 5)), g_1369)))) ^ l_4828)) || l_5406), 6)), 255UL)))) == 0xFEB37081L) != l_4921) | l_4866), g_1369)) , g_1369) & g_1369))), l_5181)), l_5406)))));
                        l_4917 = (l_1049 , (((i = (g_1369 || ((((safe_div_func_int32_t_s_s(((0x56D9L && l_4828) >= ((g_1369 > ((1UL < (((((l_1055[0] = (0x1FL || (p_17 = (+(safe_mod_func_uint8_t_u_u(252UL, (l_4846 , i))))))) >= l_4809) <= 1L) & l_4828) & g_1369)) || g_1369)) > l_4586)), (-2L))) > g_98[1][3]) | l_4828) ^ 0xA113L))) , l_4828) < l_4846));
                    }


                l_4564 = ((g_3172 = (p_16 && (((((safe_lshift_func_uint8_t_u_u((l_4866 = ((safe_rshift_func_uint16_t_u_s(0xA4B0L, 13)) <= (((g_172 = l_4564) ^ ((safe_lshift_func_int16_t_s_u(((safe_rshift_func_int16_t_s_s((safe_add_func_int32_t_s_s(l_4564, p_16)), (safe_div_func_uint32_t_u_u(((0xB83684CAL > l_4809) < ((~g_76) >= ((((l_4795[0] >= g_184) == l_4686) , 0x9DL) | 0x6EL))), p_17)))) || 255UL), 2)) , p_16)) & (-1L)))), g_68)) | 7UL) < l_4859[0][6]) , p_17) >= l_4868))) == p_16);

for (l_4868 = 0; l_4868 < 9; l_4868++)
    {
        for (g_3486 = 0; g_3486 < 8; g_3486++)
        {

{
                        uint32_t l_1192 = 0UL;
                        l_4868 = (safe_unary_minus_func_uint16_t_u((g_34[0] || g_3193)));
                        l_1192 = l_5421;
                    }

                    transparent_crc(g_1798[l_4868][g_3486], "g_1798[l_4868][g_3486]", l_5511);
            if (l_5511) {
for (g_68 = 0; (g_68 != 49); g_68 = safe_add_func_uint16_t_u_u(g_68, 6))
                    {
                        g_5210[0] = 1L;
                        l_5763 = g_34[0];
                    };


                    printf("index = [%d][%d]\n", l_4868, g_3486);}

        }
    };


                    if ((safe_add_func_uint8_t_u_u((p_16 && (((safe_rshift_func_int8_t_s_u((255UL < ((safe_add_func_int16_t_s_s(g_2422, (safe_sub_func_int8_t_s_s((g_35 ^ (g_496[2] & ((g_1684[0] = (((l_4859[4][5] >= (safe_mod_func_uint32_t_u_u(g_3172, (safe_div_func_uint8_t_u_u(((((p_17 | l_4906) < p_16) , l_4859[0][6]) == g_172), (-8L)))))) & g_3935[3][2]) != l_4686)) ^ 0x3A2FL))), p_16)))) && 0xAA848B10L)), l_4583)) && p_16) , p_17)), g_496[2])))
                {
                    int32_t l_4907 = (-1L);
                    int32_t l_4916 = 1L;
                    l_4866 = 1L;
                    l_4808 = (l_4916 = (((g_2467 = (((l_4907 = l_4859[4][1]) ^ g_34[0]) > 250UL)) & ((((l_4866 = (safe_rshift_func_int16_t_s_s((((((((safe_rshift_func_int8_t_s_s((0x3D9BC1F6L >= (((-9L) != ((((p_16 = ((l_4859[0][6] && (((l_4866 == (l_4914 = p_17)) && (l_4914 = (safe_unary_minus_func_uint8_t_u((l_4916 < 1UL))))) != l_4859[4][3])) <= p_16)) ^ g_2043) & p_17) == l_4686)) >= l_4917)), p_17)) > p_17) != g_68) > 0xAF240145L) == 0x1B99L) & l_4916) == 1UL), 3))) & p_17) , 0UL) > l_4859[0][6])) <= 0x5577L));

for (l_4686 = 0; (l_4686 <= 4); l_4686 += 1)
                {
                    int32_t l_5042 = 0xDF7BA6E3L;
                    int32_t l_5059[7][6] = {{(-1L),0xEE5C0CA4L,(-1L),(-1L),0xEE5C0CA4L,(-1L)},{(-1L),0xEE5C0CA4L,(-1L),(-1L),0xEE5C0CA4L,(-1L)},{(-1L),(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL}};
                    int i, j;
                    if ((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((((g_1288 >= (l_5223 & (safe_sub_func_int16_t_s_s((l_4808 <= ((safe_mod_func_uint16_t_u_u(((safe_add_func_int8_t_s_s(g_1345, g_68)) , ((((g_3935[3][2] = (0x04L <= 0x1EL)) && (safe_mod_func_uint16_t_u_u((((safe_lshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u((g_1370[2] || (((g_1369 = g_34[0]) >= (-1L)) <= l_4846)), g_1288)), l_4868)) | 0x60L) < g_3109[0]), k))) , l_5042) && g_1288)), l_4584)) , l_5223)), 1L)))) < g_5844) > 0x060AL), 15)), l_5763)))
                    {
                        k = (safe_sub_func_uint32_t_u_u(4294967288UL, l_5223));
                    }
                    else
                    {
                        int32_t l_5054 = 0x212F6087L;
                        int32_t l_5057 = 0x47C4678DL;
                        int32_t l_5058 = 0xF147EEABL;
                        g_2580[3][0] = l_5223;
                        l_5059[6][4] = ((((((j = (+(((safe_rshift_func_uint16_t_u_s(((((l_5223 != (safe_add_func_int8_t_s_s((g_204 = (safe_lshift_func_int16_t_s_u((l_5042 = ((safe_add_func_uint8_t_u_u(0x2FL, (g_154 == (l_5054 = (252UL || g_1288))))) < 8UL)), ((((l_5729 <= (l_5058 = ((g_573 = (safe_rshift_func_int8_t_s_u((l_4808 || (l_5057 = (((g_98[1][3] >= g_3935[2][4]) <= 0x9716L) > 0xA7L))), g_1288))) && g_1798[7][0]))) ^ (-2L)) ^ g_2580[g_204][(g_204 + 3)]) == 1L)))), l_5059[6][0]))) | g_1798[5][0]) & g_1288) == l_5554), g_4475)) , 0xA1L) && g_34[0]))) , g_1288) >= 65535UL) <= g_1288) , g_2580[g_204][(g_204 + 3)]) < g_68);
                    }
                    l_4663[0][2][5] = l_5223;
                    for (g_3172 = 4; (g_3172 >= 0); g_3172 -= 1)
                    {
                        uint16_t l_5085 = 8UL;
                        int i, j;
                        k = (safe_div_func_uint16_t_u_u((((safe_div_func_uint16_t_u_u((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(((0x0B0296A1L | l_5223) >= ((g_1288 , l_5223) ^ (((+(j , (safe_lshift_func_int8_t_s_s((safe_div_func_int8_t_s_s((safe_div_func_int8_t_s_s(((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_int8_t_s_s(0x97L, 6)) <= ((safe_sub_func_uint16_t_u_u(g_3172, g_5844)) | (safe_sub_func_uint16_t_u_u(((g_1138 = ((safe_mod_func_int32_t_s_s((~l_5223), 0xEF43C697L)) <= l_5085)) | g_1288), l_5085)))))) && g_68), 0xD5L)), g_1138)), g_573)))) > g_98[(g_204 + 1)][g_204]) > 0xAB38C5B5L))), 0UL)) || l_5223), 1L)), g_3935[3][2])) <= 0xB7L) <= 0L), 0x9B54L));
                        g_573 = (safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((safe_sub_func_uint32_t_u_u(0UL, (g_1288 <= (((safe_mod_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s(g_1288, 3)) == (0x02L >= (l_5223 = (((g_98[g_3172][g_3172] = ((safe_sub_func_int32_t_s_s((safe_lshift_func_int8_t_s_s((g_3172 = (l_5059[6][0] <= 0UL)), 2)), (safe_div_func_int8_t_s_s(((((1UL || (safe_add_func_int32_t_s_s((g_2580[2][8] = g_335), ((safe_mod_func_int16_t_s_s(g_1288, g_1138)) <= i)))) , l_5223) < 0x98E0L) | g_573), l_5223)))) > 0xEC1458CBL)) == 4L) , g_2580[2][8])))), g_573)) || g_1345) , g_98[(g_204 + 1)][g_204])))) == g_4475), j)), 0L)) < g_573) == g_1288), g_4475));
                        l_4916 = ((g_2580[g_204][(g_204 + 3)] = (safe_sub_func_uint8_t_u_u(g_35, (g_4423[1] = ((safe_add_func_int16_t_s_s(((l_4846 = (((g_34[0] = ((g_573 = (safe_mod_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_u(g_573, l_4663[0][3][4])), (safe_add_func_uint8_t_u_u(l_5223, (k = l_4663[0][1][2])))))) || (safe_sub_func_uint8_t_u_u((((safe_div_func_int32_t_s_s(g_5844, (~(safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_u((l_5223 , (safe_rshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_u(g_2580[g_204][(i + 3)], (g_573 = ((+(0x99L >= l_5554)) < l_5085)))), g_1288))), g_1798[7][3])), g_1288)), g_1369))))) | g_1288) & g_3172), l_5223)))) , k) , l_5135[2][5][3])) == 0xF35EA988L), g_3935[2][0])) & l_5059[6][0]))))) >= 65535UL);
                    }
                    g_2853[0][6][6] = (l_5223 , g_1288);
                };


                    if (g_240)
                        goto lbl_4918;
                }
                else
                {
                    int16_t l_4924 = (-10L);
                    uint8_t l_4939 = 255UL;
                    uint32_t l_4957 = 18446744073709551613UL;

g_3463 += 1;


                    for (g_3600 = 0; (g_3600 >= 0); g_3600 -= 1)
                    {
                        int8_t l_4920 = 0xD6L;
                        g_2580[0][7] = (((l_4808 & (safe_unary_minus_func_int32_t_s(g_469))) > (0L != l_4585)) && p_17);

{
        ;
        if (l_4866) printf("index = [%d]\n", l_4866);

    }

                    l_4921 = l_4920;
                    }
                    for (l_4868 = 0; (l_4868 == 8); l_4868++)
                    {
                        if (p_16)
                            break;

g_3317 += 1;



{
        transparent_crc(g_1370[l_5599], "g_1370[l_5599]", l_4564);
        if (l_4564) printf("index = [%d]\n", l_5599);

    }

                    l_4924 = 1L;
                        if (l_4859[2][2])
                            break;
                    }

{
                    int32_t l_5042 = 0xDF7BA6E3L;
                    int32_t l_5059[7][6] = {{(-1L),0xEE5C0CA4L,(-1L),(-1L),0xEE5C0CA4L,(-1L)},{(-1L),0xEE5C0CA4L,(-1L),(-1L),0xEE5C0CA4L,(-1L)},{(-1L),(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL}};
                    int i, j;

                    ;

                    g_2853[0][6][6] = (l_5223 , l_5006);
                }

                    ;
lbl_4940:
                    l_4564 = (safe_rshift_func_int16_t_s_s(((!(((((((-3L) <= ((g_3109[0] , (safe_rshift_func_int16_t_s_s(((g_3935[4][3] , (0UL || (safe_lshift_func_int8_t_s_u(((l_4795[0] > (safe_unary_minus_func_uint16_t_u(g_897))) , (((~(p_16 != (safe_sub_func_uint16_t_u_u((0xF7147FAFL ^ (safe_rshift_func_int8_t_s_u((l_4808 = (l_4663[0][3][4] = (safe_unary_minus_func_uint32_t_u(((g_2853[3][1][0] = (((-1L) >= g_4423[1]) > 0x284D07EAL)) <= l_4808))))), l_4667))), l_4809)))) ^ 0x28AF1D3FL) | l_4868)), 5)))) , g_35), p_17))) >= l_4585)) >= g_154) ^ 0L) | l_4939) , (-1L)) , 255UL)) & g_98[3][1]), 1));
                    for (g_172 = (-11); (g_172 >= 41); g_172 = safe_add_func_uint32_t_u_u(g_172, 5))
                    {
                        int8_t l_4958 = 7L;
                        l_4635 = ((safe_mod_func_uint32_t_u_u((safe_div_func_uint16_t_u_u(((l_4859[0][5] != ((((safe_sub_func_int32_t_s_s(0x929C5066L, (l_4586 = ((((safe_add_func_uint8_t_u_u(g_3172, (safe_rshift_func_uint16_t_u_s(g_2422, ((safe_div_func_uint16_t_u_u(l_4924, 1L)) >= l_4859[0][6]))))) > (l_4958 = (((p_17 ^ (safe_div_func_uint32_t_u_u((0x4E0E5951L | l_4828), g_2422))) , l_4957) ^ l_4868))) , 0x33L) || l_4959)))) , l_4859[0][6]) || l_4958) , g_4423[3])) || 0xCFL), p_17)), l_4866)) | 0x5FFE36B1L);

{
                    int32_t l_4907 = (-1L);
                    int32_t l_4916 = 1L;

{
                        if (g_240)
                            {
if (l_4584)
                    break;

                    break;}
                    }

                    l_5599 = 1L;
                    g_204 = (l_4916 = (((g_3600 = (((l_4907 = l_4859[4][1]) ^ g_34[0]) > 250UL)) & ((((l_5599 = (safe_rshift_func_int16_t_s_s((((((((safe_rshift_func_int8_t_s_s((0x3D9BC1F6L >= (((-9L) != ((((l_4924 = ((l_4859[0][6] && (((l_5599 == (g_2440 = g_3193)) && (g_2440 = (safe_unary_minus_func_uint8_t_u((l_4916 < 1UL))))) != l_4859[4][3])) <= l_4924)) ^ g_3486) & g_3193) == g_3317)) >= i)), g_3193)) > g_3193) != g_184) > 0xAF240145L) == 0x1B99L) & l_4916) == 1UL), 3))) & g_3193) , 0UL) > l_4859[0][6])) <= 0x5577L));

{
                        int16_t l_905 = 0L;
                        l_905 = (l_5554 = g_759);
                    }

                    if (l_4964)
                        {
{
                        if (l_4957)
                            break;
                        l_4808 = g_98[g_3600][(l_4846 + 2)];
                    }

                    ;;}
                }

                    ;
                        l_4663[0][3][4] = (((l_4939 < l_4914) & ((safe_mul_func_int32_t_s_s(1L, ((((safe_mod_func_uint32_t_u_u(g_897, g_275)) , g_2440) , g_1368) < (~(g_9 , g_68))))) && 0xB54CL)) , g_240);

                    }
                }
            }
        }

for (l_4585 = 0; l_4585 < 3; l_4585++)
                g_1370[l_4585] = (-5L);

                    ;

{
            transparent_crc(g_1798[g_573][l_4564], "g_1798[g_573][l_4564]", l_4634);
            if (l_4634) printf("index = [%d][%d]\n", g_573, l_4564);

        }


{
        int16_t l_6846 = 1L;
        l_6846 = (+(l_5006 & k));
    }

                    for (g_573 = 3; (g_573 >= 0); g_573 -= 1)
        {
            int32_t l_5025 = 0xB3C9A080L;
            const int16_t l_5224 = 0L;
            uint8_t l_5310 = 0x2AL;
            uint32_t l_5312 = 9UL;

for (l_4665 = 0; l_4665 < 7; l_4665++)
    {
        transparent_crc(g_4423[l_4665], "g_4423[l_4665]", l_4585);
        if (l_4585) printf("index = [%d]\n", l_4665);

    };


                    for (g_275 = 3; (g_275 >= 0); g_275 -= 1)
            {
                int i, j;
                g_1370[0] = ((g_1684[0] = (((-1L) ^ (safe_add_func_int32_t_s_s((g_2580[g_573][(g_275 + 3)] , (l_4635 = (safe_add_func_int16_t_s_s((l_5025 = (((((safe_add_func_uint32_t_u_u(g_2580[g_573][(g_573 + 3)], ((g_98[g_275][(g_573 + 1)] = 2UL) | 0UL))) > (g_2580[g_573][(g_275 + 3)] <= ((((g_2580[g_573][(g_275 + 3)] >= (g_87 = ((safe_lshift_func_int16_t_s_u((+(safe_rshift_func_int8_t_s_s((safe_add_func_uint8_t_u_u((+(g_3486 && (safe_lshift_func_uint16_t_u_s((p_17 <= g_87), g_2580[g_573][(g_573 + 3)])))), g_496[2])), g_1369))), p_17)) , g_2580[g_573][(g_275 + 3)]))) & p_16) || 0x85CAL) & l_4564))) == g_2467) , 0xE83AL) & 0x097CL)), g_2580[g_573][(g_275 + 3)])))), l_5006))) < g_172)) == l_4586);

                return g_76;
            }

for (l_5025 = 0; l_5025 < 5; l_5025++)
        {
            transparent_crc(g_3935[l_4917][l_5025], "g_3935[l_4917][l_5025]", g_506);
            if (g_506) {
j += 1;


                    printf("index = [%d][%d]\n", l_4917, l_5025);}

        };


                    if ((safe_add_func_uint8_t_u_u((g_87 & g_1352), ((g_3600 = g_1798[5][2]) < p_16))))
            {
                uint8_t l_5156 = 0xAAL;
                int8_t l_5157 = 4L;
                int32_t l_5158 = 0x1759F4A0L;
                int32_t l_5182 = (-1L);
                uint8_t l_5199 = 255UL;
                if ((l_4635 == (l_5025 = (safe_mod_func_uint8_t_u_u((((safe_mod_func_uint32_t_u_u(4294967287UL, (((l_4663[0][1][2] = (+(((safe_mod_func_uint32_t_u_u((((safe_add_func_uint32_t_u_u((l_5158 = (~(((l_4634 < ((((safe_lshift_func_int16_t_s_s((l_4663[0][3][4] > 65527UL), (((((l_4585 = (safe_mod_func_uint16_t_u_u((safe_add_func_int32_t_s_s(((safe_rshift_func_uint16_t_u_u(((l_5025 | (l_4667 = ((g_2580[2][0] || ((p_16 = p_17) ^ 4UL)) , 0L))) & 65529UL), g_2853[2][8][6])) >= (-8L)), 2UL)), p_17))) < 7L) , p_17) <= l_5156) | g_1352))) >= g_1798[5][2]) , p_17) & l_5025)) <= l_5157) > g_2043))), 6L)) != l_5025) && 1UL), g_3109[1])) > 0x305DL) <= p_17))) | p_17) , p_16))) == 0x1CCDL) >= g_1352), g_1798[5][2])))))
                {
                    uint32_t l_5180 = 0x260E95ADL;
                    int32_t l_5198 = (-10L);
                    int32_t l_5226[10];
                    int i;
                    for (i = 0; i < 10; i++)
                        {
{
                        l_4634 = (l_4667 && l_4667);
                    }


;


                    l_5226[i] = 0xBB4BBFE2L;}

{
            transparent_crc(g_3935[g_2043][l_5198], "g_3935[g_2043][l_5198]", l_4586);
            if (l_4586) printf("index = [%d][%d]\n", g_2043, l_5198);

        }

                    l_5182 = (((safe_sub_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u(((4294967293UL & p_17) && ((l_4665 == ((safe_lshift_func_int16_t_s_u(((p_17 <= ((g_87 = ((p_16 ^ ((safe_sub_func_int16_t_s_s(g_759, ((safe_rshift_func_int8_t_s_u((g_2422 = (safe_add_func_uint32_t_u_u((((safe_div_func_uint32_t_u_u((((!g_9) , ((safe_div_func_uint16_t_u_u(g_3109[0], (((safe_mod_func_int32_t_s_s((((l_5158 = (((((safe_div_func_int16_t_s_s(((((g_335 = 0x73C8L) > 2UL) == 1L) || l_5180), p_17)) || l_5157) , l_5025) & p_17) , g_472)) || p_16) , g_2467), p_17)) <= (-1L)) , 0x1124L))) > 0x9CL)) , 4294967295UL), 0xFB7E382CL)) || 0x7BL) , l_4686), 0x6E5593D7L))), 5)) == 0L))) , l_5180)) , p_17)) && 1UL)) >= l_5181), 0)) != p_16)) , 9UL)), 0x0A2BL)) | p_16), g_2852)) > 9L) , p_16);

;


                    l_5226[9] = (g_472 & (safe_sub_func_uint8_t_u_u((l_4586 >= ((((((3UL ^ (safe_add_func_int8_t_s_s((p_17 >= (safe_div_func_int32_t_s_s((-1L), (safe_div_func_uint16_t_u_u((g_5210[0] && (((g_2467 = ((safe_div_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((((l_5198 = (((g_4423[1] = ((!(safe_rshift_func_uint16_t_u_u((l_4585 = ((safe_rshift_func_uint8_t_u_s(((l_5025 = 0x59D11AA8L) ^ 1UL), 4)) | ((g_98[1][3] = (((safe_mod_func_uint8_t_u_u(6UL, p_16)) || l_5198) > l_5222[0])) | 0xFC5BL))), 6))) > g_1599)) ^ 0L) & 0xFF2AE093L)) < l_4828) , g_472), 9)), 0xA844L)) == l_5223)) , l_5224) < 0xF290L)), 0x519CL))))), 255UL))) ^ 1UL) <= (-7L)) != g_5225) | p_17) , l_4564)), l_5224)));
                }
                else
                {
                    uint32_t l_5231[1][1];
                    int32_t l_5261 = 0x3B65DE0DL;
                    int i, j;

if (g_2467)
                            {
for (l_4564 = (-22); (l_4564 > 14); l_4564 = safe_add_func_uint8_t_u_u(l_4564, 4))
            {
                g_1370[2] = g_204;
                return l_4586;
            };


                    ;;}


if (l_5554) printf("index = [%d]\n", g_240);

                    for (i = 0; i < 1; i++)
                    {
                        for (j = 0; j < 1; j++)
                            l_5231[i][j] = 0x78281221L;
                    }

if (j)
                    ;;

                    l_5182 = (p_17 != p_17);
                    l_4586 = ((~(((!(((safe_mod_func_int32_t_s_s((l_5231[0][0] = g_3486), (safe_sub_func_uint8_t_u_u(((((-8L) <= ((safe_rshift_func_int16_t_s_s((((0x5BADL | p_17) ^ ((safe_rshift_func_int16_t_s_u((safe_add_func_uint16_t_u_u((((safe_sub_func_int16_t_s_s(((p_16 , ((0x616AL || (((((((safe_mod_func_uint8_t_u_u(((+(safe_rshift_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u((safe_div_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s((safe_sub_func_uint8_t_u_u((l_5224 ^ (((l_4663[0][3][0] | (safe_add_func_int16_t_s_s((((safe_unary_minus_func_uint32_t_u(((safe_lshift_func_uint16_t_u_s((safe_unary_minus_func_int32_t_s(6L)), p_16)) > g_335))) || g_496[2]) < 5L), g_3317))) > p_16) <= l_5261)), g_3172)), 5)), l_5006)), l_5025)), p_16))) == 65531UL), l_4663[0][1][5])) != g_2580[2][0]) , l_5261) == 0x029991F0L) & g_172) , 0xDBE5L) , g_3109[1])) < p_16)) , g_2440), p_16)) ^ l_5261) , g_469), 0L)), 12)) , 0xA0DF16C0L)) != g_1798[5][2]), 10)) ^ p_17)) , g_5210[0]) , p_16), l_4663[0][3][4])))) < l_5262) != (-6L))) & p_16) && p_16)) <= p_16);

                    l_4635 = l_5231[0][0];
                }
                return g_1138;
            }
            else
            {
                int16_t l_5311 = 0x5AF2L;
                int32_t l_5344 = 0L;
                int32_t l_5355 = 0x052C11BDL;
                int32_t l_5356 = 9L;
                int32_t l_5357 = 0xAEF04337L;


{
        for (l_5357 = 0; l_5357 < 10; l_5357++)
        {

l_5356 += 1;


                    transparent_crc(g_2580[l_5554][l_5357], "g_2580[l_5554][l_5357]", g_2043);
            if (g_2043) printf("index = [%d][%d]\n", l_5554, l_5357);

        }
    }

                    l_4564 += 1;




{
                transparent_crc(g_2853[l_5344][l_5763][l_5355], "g_2853[l_5344][l_5763][l_5355]", l_5025);
                if (l_5025) printf("index = [%d][%d][%d]\n", l_5344, l_5763, l_5355);

            }


for (g_3317 = 0; (g_3317 <= 4); g_3317 += 1)
                {
                    int32_t l_5042 = 0xDF7BA6E3L;
                    int32_t l_5059[7][6] = {{(-1L),0xEE5C0CA4L,(-1L),(-1L),0xEE5C0CA4L,(-1L)},{(-1L),0xEE5C0CA4L,(-1L),(-1L),0xEE5C0CA4L,(-1L)},{(-1L),(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL}};
                    int i, j;
                    if ((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((((g_897 >= (g_87 & (safe_sub_func_int16_t_s_s((g_240 <= ((safe_mod_func_uint16_t_u_u(((safe_add_func_int8_t_s_s(l_5181, l_5312)) , ((((g_3935[3][2] = (0x04L <= 0x1EL)) && (safe_mod_func_uint16_t_u_u((((safe_lshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u((g_1370[2] || (((g_3193 = g_34[0]) >= (-1L)) <= g_68)), g_897)), l_5357)) | 0x60L) < g_3109[0]), g_2440))) , l_5042) && g_897)), l_5357)) , g_87)), 1L)))) < g_1288) > 0x060AL), 15)), l_5554)))
                    {
                        g_2440 = (safe_sub_func_uint32_t_u_u(4294967288UL, g_87));
                    }
                    else
                    {
                        int32_t l_5054 = 0x212F6087L;
                        int32_t l_5057 = 0x47C4678DL;
                        int32_t l_5058 = 0xF147EEABL;
                        g_2580[3][0] = g_87;
                        l_5059[6][4] = ((((((l_5356 = (+(((safe_rshift_func_uint16_t_u_s(((((l_5696 != (safe_add_func_int8_t_s_s((g_2440 = (safe_lshift_func_int16_t_s_u((l_5042 = ((safe_add_func_uint8_t_u_u(0x2FL, (g_2422 == (l_5054 = (252UL || g_897))))) < 8UL)), ((((g_154 <= (l_5058 = ((l_5357 = (safe_rshift_func_int8_t_s_u((g_240 || (l_5057 = (((g_98[1][3] >= g_3935[2][4]) <= 0x9716L) > 0xA7L))), g_897))) && g_1798[7][0]))) ^ (-2L)) ^ g_2580[l_5355][(l_5355 + 3)]) == 1L)))), l_5059[6][0]))) | g_1798[5][0]) & g_897) == l_5344), g_3193)) , 0xA1L) && g_34[0]))) , g_897) >= 65535UL) <= g_897) , g_2580[l_5355][(l_5355 + 3)]) < l_5312);
                    }
                    l_4663[0][2][5] = g_87;
                    for (g_3600 = 4; (g_3600 >= 0); g_3600 -= 1)
                    {
                        uint16_t l_5085 = 8UL;
                        int i, j;
                        l_5357 = (safe_div_func_uint16_t_u_u((((safe_div_func_uint16_t_u_u((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(((0x0B0296A1L | l_5696) >= ((g_897 , g_87) ^ (((+(l_5356 , (safe_lshift_func_int8_t_s_s((safe_div_func_int8_t_s_s((safe_div_func_int8_t_s_s(((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_int8_t_s_s(0x97L, 6)) <= ((safe_sub_func_uint16_t_u_u(g_154, g_1288)) | (safe_sub_func_uint16_t_u_u(((l_5181 = ((safe_mod_func_int32_t_s_s((~g_87), 0xEF43C697L)) <= l_5085)) | g_897), l_5085)))))) && l_5312), 0xD5L)), g_6771)), l_5344)))) > g_98[(l_5355 + 1)][l_5355]) > 0xAB38C5B5L))), 0UL)) || g_87), 1L)), g_3935[3][2])) <= 0xB7L) <= 0L), 0x9B54L));
                        l_5344 = (safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((safe_sub_func_uint32_t_u_u(0UL, (g_897 <= (((safe_mod_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s(g_897, 3)) == (0x02L >= (g_87 = (((g_98[g_3600][g_3600] = ((safe_sub_func_int32_t_s_s((safe_lshift_func_int8_t_s_s((g_154 = (l_5059[6][0] <= 0UL)), 2)), (safe_div_func_int8_t_s_s(((((1UL || (safe_add_func_int32_t_s_s((g_2580[2][8] = g_335), ((safe_mod_func_int16_t_s_s(g_897, l_5181)) <= l_4665)))) , g_87) < 0x98E0L) | l_5344), g_87)))) > 0xEC1458CBL)) == 4L) , g_2580[2][8])))), l_5344)) || l_5181) , g_98[(l_5355 + 1)][l_5355])))) == g_6029), l_5356)), 0L)) < l_5344) == g_897), g_6029));
                        l_5355 = ((g_2580[l_5355][(l_5355 + 3)] = (safe_sub_func_uint8_t_u_u(l_5309, (g_4423[1] = ((safe_add_func_int16_t_s_s(((g_68 = (((g_34[0] = ((l_5344 = (safe_mod_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_u(l_5344, l_4663[0][3][4])), (safe_add_func_uint8_t_u_u(g_87, (g_2440 = l_4663[0][1][2])))))) || (safe_sub_func_uint8_t_u_u((((safe_div_func_int32_t_s_s(l_4828, (~(safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_u((g_87 , (safe_rshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_u(g_2580[l_5355][(l_4665 + 3)], (l_5357 = ((+(0x99L >= l_5344)) < l_5085)))), g_897))), g_1798[7][3])), g_897)), g_3193))))) | g_897) & g_2422), g_87)))) , l_5357) , l_5135[2][5][3])) == 0xF35EA988L), g_3935[2][0])) & l_5059[6][0]))))) >= 65535UL);
                    }
                    g_2853[0][6][6] = (g_87 , g_897);
                };


                    ;


                    l_4667 = (((-1L) & ((g_34[0] = (safe_mod_func_int16_t_s_s((safe_add_func_uint16_t_u_u(((0x09L < 0x19L) <= ((p_16 = (safe_lshift_func_uint8_t_u_u((0L && (l_5025 == (safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((safe_mod_func_int32_t_s_s(((5UL ^ (((g_9 , (safe_sub_func_int16_t_s_s((safe_unary_minus_func_uint16_t_u(p_17)), (p_17 , l_5308)))) != (-10L)) || 0x8BL)) ^ l_5309), 0x8D033BFCL)), g_68)), l_5310)))), g_2043))) & 0x927AL)), l_5311)), l_5312))) , p_17)) < l_5311);
                ;
                if (g_4689)
                    goto lbl_5265;

{
                        ;
                        l_4667 = g_34[0];
                    }


if (l_5763)
                            break;

                    l_5357 = (safe_rshift_func_uint8_t_u_s((g_4423[2] = (safe_sub_func_uint8_t_u_u((l_4686 <= (((l_5356 = (+(l_5355 = ((((l_4586 || (0xF0L == (!(safe_div_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(((((l_5344 = (safe_mod_func_int8_t_s_s((l_5025 = (p_17 && (0x3826AE43L && p_16))), (+p_16)))) & (safe_sub_func_int16_t_s_s(((l_4663[0][3][4] = (safe_lshift_func_uint16_t_u_u((safe_div_func_int32_t_s_s(((((((((g_1368 = ((safe_sub_func_int32_t_s_s(1L, ((safe_div_func_uint32_t_u_u(p_16, (-1L))) , g_3935[3][2]))) <= (-9L))) == g_3935[3][2]) <= l_5311) > 0x6759FA01L) , 0xE5L) && 0xF4L) , 4L) & 0xAE6AL), l_5311)), l_4663[0][0][1]))) | 4294967295UL), p_16))) || l_5224) > p_17), p_17)), l_5006)), p_17))))) == g_34[0]) == l_5311) < 0x61CE52DFL)))) <= l_5222[2]) == l_5310)), g_1288))), l_5311));
            }
        }
        if (l_5358)
        {
            int32_t l_5425 = 0x74B2804FL;
            int32_t l_5427 = 0x1547EA9EL;

{
        transparent_crc(g_4423[k], "g_4423[k]", l_4634);
        if (l_4634) {
{
            const int8_t l_5513 = (-1L);
            int32_t l_5514 = 0xA110A837L;
            int32_t l_5542 = (-10L);
            int32_t l_5822 = 0L;
            uint16_t l_5833 = 0UL;

g_2467 += 1;


                    for (l_4686 = 0; (l_4686 < 52); l_4686++)
            {
                uint32_t l_5500 = 4294967295UL;
                int32_t l_5529 = 0x73A6F5D6L;
                int32_t l_5553 = (-5L);
                k = ((((safe_lshift_func_uint16_t_u_s(((((g_472 == ((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_s((safe_mod_func_uint32_t_u_u(((l_5514 = (safe_sub_func_uint16_t_u_u((((((g_897 && (1L == l_4906)) , (safe_mod_func_int16_t_s_s((g_5512 = (g_5512 = (((safe_add_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u(l_5500, ((safe_mod_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u((((g_472 | (g_472 & (safe_rshift_func_int8_t_s_s((safe_div_func_int32_t_s_s(0xB013770DL, (safe_mod_func_int16_t_s_s(((((0xAAL != g_4689) >= l_5500) && 0L) != 1UL), l_4634)))), 7)))) > l_5500) , 0x74B8L), 0UL)), g_472)) < g_897))), 0xCF82E3BFL)), l_4564)) < g_472) <= l_4906))), g_35))) < 1L) > l_5223) , g_1345), l_5513))) >= 0L), g_34[0])), 15)), g_4423[1])) && 0L)) != g_1138) & l_4906) <= (-10L)), 5)) , g_472) >= l_4906) == g_154);

if (l_5309)
                            break;

                    if (((safe_rshift_func_uint16_t_u_s(l_5500, (safe_add_func_int8_t_s_s(((((((safe_mod_func_int8_t_s_s((((+((l_5529 = (safe_add_func_int16_t_s_s((safe_add_func_int8_t_s_s((((l_4634 == (l_4906 > ((+((safe_div_func_int8_t_s_s(l_5529, (l_5514 = (g_472 = (safe_sub_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_u((((safe_mod_func_uint16_t_u_u((g_1599 = ((l_5553 = (safe_add_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((k = l_5542), (l_4663[0][3][4] = (safe_rshift_func_uint8_t_u_s((safe_div_func_int8_t_s_s((((safe_lshift_func_int8_t_s_u(((safe_add_func_int32_t_s_s((-4L), (((((g_1345 || (g_1345 = (g_1138 = 1UL))) < (safe_mod_func_uint32_t_u_u(l_5513, g_472))) && 0xD9F73B96L) <= 0x0F6CL) && 8L))) == 0x7F73L), g_1370[2])) < l_4906) != g_3109[0]), 246UL)), 0))))), g_472)) || g_2852), l_5500))) || l_4906)), g_2043)) != g_472) ^ g_472), g_4423[6])) , 8UL), g_472)))))) != 1UL)) < g_3935[3][2]))) >= 0x32354B20L) > 9UL), 3UL)), g_4423[1]))) , l_5553)) == l_5500) > l_4906), 0xE0L)) == (-7L)) | l_4906) >= 0xFEC3L) & l_5223) > i), 1UL)))) , l_5500))
                {
                    uint32_t l_5567[5][7] = {{5UL,18446744073709551609UL,0x909CF5E8L,0xCFF8EDB2L,0x909CF5E8L,18446744073709551609UL,5UL},{18446744073709551610UL,0xA6F551C9L,8UL,0x75111B36L,0xCFF8EDB2L,0UL,5UL},{0xCFF8EDB2L,5UL,0x96530A5CL,0x96530A5CL,5UL,0xCFF8EDB2L,18446744073709551610UL},{18446744073709551609UL,0x96530A5CL,8UL,18446744073709551610UL,0xA77667EBL,0xCFF8EDB2L,0xCFF8EDB2L},{0x75111B36L,0xA77667EBL,0x909CF5E8L,0xA77667EBL,0x75111B36L,0UL,18446744073709551609UL}};
                    int32_t l_5568 = 0xF1F27906L;
                    int32_t l_5569 = 0L;
                    int i, j;

{

{
                        if (g_759)
                            break;
                        g_573 = g_98[g_2422][(g_76 + 2)];
                    }

                    return g_1370[2];
                    }

                    l_5569 = ((l_5568 = ((g_352 = (((((((safe_sub_func_int32_t_s_s(((((safe_sub_func_int16_t_s_s((safe_div_func_uint8_t_u_u((safe_div_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(g_472, l_5529)) | 0x74L), g_472)), 8L)), (l_4906 = (l_4686 >= ((safe_lshift_func_uint16_t_u_s(0UL, g_472)) != (l_4906 && g_5512)))))) && l_5500) != 0UL) , 5L), l_5529)) , l_5553) & l_5567[2][5]) > 0x08L) || 0xE764B52EL) ^ g_472) <= l_5529)) , 6L)) || l_5529);
                    g_5446[5] = 8L;
                    ;
                    for (l_5569 = 0; (l_5569 >= 0); l_5569 -= 1)
                    {
                        int i;
                        l_5591[3] = ((safe_add_func_uint16_t_u_u((g_1599 = (l_5514 = ((((l_5222[l_5569] != (65528UL || ((g_2043 = ((safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s(((safe_rshift_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_s(((3UL & (0xBB49D088L < ((safe_rshift_func_uint8_t_u_s(g_34[l_5569], (safe_add_func_int32_t_s_s((0x0F671AB7L ^ ((safe_add_func_int32_t_s_s(((l_4586 = (g_472 = ((g_34[l_5569] > (((((safe_add_func_int32_t_s_s((+((l_4564 = (g_5225 | ((((safe_div_func_uint16_t_u_u(0x578FL, l_5222[l_5569])) ^ 5UL) > 0x851AL) >= l_4906))) < g_5844)), g_5446[5])) ^ g_472) && l_4906) == 0UL) > 0xCEL)) < 0x217F7CF0L))) >= g_1352), 0L)) >= 0xB793C0CBL)), g_3109[1])))) == 0xBAL))) <= 0xECL), 5)) >= g_3935[3][2]), l_5542)) , 5L), l_5529)), g_2853[1][7][2])) >= g_2580[0][2])) >= l_4564))) > l_5542) , g_3935[3][2]) ^ 0x7010L))), l_4906)) < 1L);
                        return l_4906;
                    }
                }
                else
                {
                    ;
                    return g_5446[0];
                }
                for (g_154 = (-7); (g_154 > 27); g_154++)
                {
                    l_5553 = (safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u((l_5223 & ((-6L) | l_4906)), 8)), g_472));
                }
            }

g_1138 += 1;


                    if ((safe_rshift_func_int16_t_s_u((l_5514 = l_4564), 3)))
            {
                int32_t l_5622 = 0x4115D784L;
                int8_t l_5717 = 0L;
                int32_t l_5728[1];
                uint32_t l_5749[6][9][3] = {{{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL}},{{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL}},{{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL}},{{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL}},{{0UL,0xCC33B38DL,1UL},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL},{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL},{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL}},{{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL},{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL},{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL}}};
                const uint8_t l_5781[3][6][1] = {{{0xC6L},{4UL},{4UL},{0xDDL},{4UL},{4UL}},{{0xC6L},{4UL},{4UL},{0xDDL},{4UL},{4UL}},{{0xC6L},{4UL},{4UL},{0xDDL},{4UL},{4UL}}};
                int i, j, k;
                for (i = 0; i < 1; i++)
                    l_5728[i] = 0x2FECE2D3L;
                for (l_4564 = 9; (l_4564 > 24); l_4564++)
                {
                    int16_t l_5614 = 0x9D0FL;
                    int32_t l_5625 = (-2L);
                    int16_t l_5727 = 0xE03EL;

if (g_184)
                            break;

                    if ((safe_rshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_s(0xDBL, 3)) & ((l_5614 <= g_472) >= 0x0C2BL)), (safe_sub_func_int16_t_s_s(0x7363L, ((safe_lshift_func_int8_t_s_u((safe_unary_minus_func_uint8_t_u((0x6F64943CL > (((safe_div_func_int32_t_s_s((l_5591[3] && ((g_1345 = ((g_68 = l_5622) | 0x28E1A48FL)) < g_2580[0][7])), g_1352)) & l_4906) || g_1370[2])))), l_5614)) & g_472))))))
                    {
                        l_4635 = 0xC846F6BAL;
                    }
                    else
                    {
                        uint32_t l_5652 = 3UL;
                        int32_t l_5679 = 0x62C2DA79L;
                        int32_t l_5695[10] = {(-3L),(-3L),(-3L),(-3L),(-3L),(-3L),(-3L),(-3L),(-3L),(-3L)};
                        int i;
                        ;

if (g_1684[0])
                        continue;

                    ;
                        ;
                        l_4635 = (((safe_sub_func_uint32_t_u_u(((safe_div_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u(g_472, 6)), (g_2467 = g_3109[0]))) | (safe_lshift_func_uint16_t_u_s(((((g_472 | (safe_sub_func_uint32_t_u_u((g_1138 = ((l_4663[0][0][2] = ((((((((~l_5679) < (((safe_sub_func_int8_t_s_s(l_4634, (((safe_sub_func_uint32_t_u_u(l_4906, (safe_add_func_uint32_t_u_u(((g_1345 = (((safe_mod_func_uint8_t_u_u(((l_5262 && (((safe_lshift_func_int8_t_s_s((i = ((l_5695[2] = (!((safe_sub_func_int32_t_s_s(((((0x1EL && ((safe_sub_func_int32_t_s_s(((g_98[3][3] = (g_472 != 4294967295UL)) != l_5223), 0x984A2A0DL)) | l_5223)) >= j) ^ 8UL) != g_1370[1]), g_472)) != 6L))) < 4294967295UL)), 0)) && 0x3550AFCBL) && 0UL)) , g_472), l_4564)) , g_3317) > 0x627D0751L)) ^ l_5652), g_5512)))) ^ 0x025ADBE1L) , l_5513))) && g_2852) , 0x0A48DBD9L)) , l_5622) , g_472) , 255UL) > g_1345) || g_472) , l_5622)) && g_472)), l_4635))) & l_5223) >= 0x8478L) | l_4906), g_472))), l_5223)) && l_4906) ^ 1L);
                    }
                    if ((+0x78ABDE30L))
                    {
                        uint32_t l_5707 = 6UL;
                        g_2467 = ((safe_sub_func_int16_t_s_s(l_4906, (l_5625 = g_68))) , ((l_4635 = (~(safe_div_func_int16_t_s_s(((safe_mod_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(l_5707, (safe_div_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s(((((((safe_lshift_func_int16_t_s_u(g_1370[2], 2)) | l_5707) ^ (safe_sub_func_int8_t_s_s((~g_472), l_5717))) > ((l_5728[0] = ((((((((safe_add_func_int32_t_s_s((l_5622 = (safe_add_func_uint8_t_u_u((((0x64689EF7L ^ ((safe_lshift_func_uint8_t_u_s(((safe_unary_minus_func_int32_t_s(((safe_mod_func_uint8_t_u_u((l_5223 | (-1L)), g_2043)) || l_5717))) < l_5513), g_2852)) | g_3935[3][2])) || l_4906) , l_5727), 0x41L))), g_472)) == l_4906) , 1UL) < (-7L)) && 0xA701L) , 0xB060L) == g_2043) ^ g_1138)) == g_2467)) & (-1L)) != l_5707), l_5717)), l_5513)))), l_5625)) ^ g_98[1][3]), l_5514)))) ^ 4294967295UL));
                        ;
                    }
                    else
                    {
                        int8_t l_5764 = 0xC3L;
                        l_5728[0] = ((safe_unary_minus_func_int16_t_s((-1L))) == (((safe_rshift_func_int8_t_s_u(((l_5223 = (((k = ((g_472 = l_5223) ^ ((safe_mod_func_int8_t_s_s(l_5728[0], (safe_rshift_func_int16_t_s_u((g_68 ^ (safe_add_func_uint16_t_u_u((safe_mod_func_int32_t_s_s(4L, (l_4906 , g_1798[5][2]))), ((-1L) | (safe_lshift_func_uint16_t_u_s(((g_1138 = (g_2043 <= g_5844)) <= l_5223), l_4906)))))), l_4906)))) <= l_5542))) , g_2043) ^ l_4906)) & l_4906), l_5764)) != 0xC85B220FL) & l_5764));
                    }
                }
                for (l_5223 = 0; (l_5223 != 20); l_5223 = safe_add_func_int16_t_s_s(l_5223, 5))
                {
                    int32_t l_5782[1][2];
                    int i, j;
                    for (i = 0; i < 1; i++)
                    {

if (p_16)
                            break;

                    for (j = 0; j < 2; j++)
                            ;;
                    }
                    g_1370[1] = (l_4564 = (((g_2467 < ((g_2043 , j) <= g_1138)) , (safe_div_func_int16_t_s_s((safe_sub_func_int16_t_s_s(((safe_add_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u((safe_lshift_func_uint16_t_u_u((l_4634 ^ (l_5728[0] = (g_1352 = (g_1684[0] = (g_2853[0][6][6] ^ (((safe_mod_func_uint16_t_u_u(((g_4423[1] <= (safe_lshift_func_uint16_t_u_s(l_4906, (((((g_1138 > l_5749[5][7][1]) > 0x14DCL) > g_472) >= 0x5C4EL) < 0x27L)))) | g_472), 1L)) ^ 0xA9L) ^ l_5513)))))), g_2043)), l_4906)), l_5781[1][3][0])) == 0x7BL), l_4906)), l_4634))) && l_5782[0][1]));
                    for (l_5223 = (-14); (l_5223 > 15); l_5223 = safe_add_func_int32_t_s_s(l_5223, 7))
                    {
                        int8_t l_5789 = (-1L);
                        int32_t l_5790 = 0x8B610670L;
                        l_5728[0] = (((0x11C38EDCL || (((safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((g_472 < 1L) || g_5844), ((l_4906 = (g_68 || l_5789)) & g_1352))), (-1L))) ^ 252UL) , 0x0F7F1C95L)) != 0xC2L) || 4294967287UL);
                        l_4634 = ((g_2467 == ((l_5790 = (g_1370[2] = l_4906)) , (1UL && (((g_35 >= (l_5514 = 0x8608L)) == ((((-1L) && 5UL) && l_4906) | (((k ^ l_5781[0][5][0]) & g_2043) || g_496[1]))) || g_1352)))) | g_5210[0]);
                    }
                }

l_4686 += 1;


                    l_5728[0] = (safe_mod_func_int32_t_s_s(((g_4423[1] = 255UL) != (g_472 <= ((safe_mod_func_int16_t_s_s((safe_add_func_int32_t_s_s((l_4906 , (g_1370[1] = (((((((((safe_rshift_func_uint16_t_u_u((safe_add_func_int32_t_s_s((safe_rshift_func_int8_t_s_s(g_2043, 6)), l_4906)), (safe_rshift_func_uint8_t_u_s((((safe_rshift_func_int16_t_s_u((((l_4906 != 0UL) <= (((g_1345 > (safe_rshift_func_uint16_t_u_u((safe_div_func_int32_t_s_s((safe_rshift_func_int8_t_s_s((safe_add_func_uint16_t_u_u(g_68, 0xEEE0L)), 6)), l_4686)), k))) != l_4663[0][3][4]) < l_4634)) >= g_1798[8][6]), l_5223)) > g_4689) , l_4906), g_897)))) >= l_5749[1][4][1]) < l_4634) ^ 249UL) >= g_2852) || g_5210[0]) & 8L) && g_1352) != g_5512))), 0x0D1E55A5L)), 0x6461L)) == g_1138))), 0x7276E9ACL));
            }
            else
            {

            }
            l_5834[1][1] = ((safe_lshift_func_int16_t_s_u(l_4634, ((((l_5514 = (65533UL < 0x3B57L)) == (((safe_mod_func_int32_t_s_s((i = (l_5822 = l_4906)), 0x239B190CL)) | ((((l_4906 == (((safe_div_func_uint16_t_u_u(((((safe_lshift_func_int16_t_s_u((safe_div_func_uint32_t_u_u(0x9C949002L, (((safe_mod_func_uint8_t_u_u((safe_add_func_int8_t_s_s(((l_4906 != g_5446[3]) && l_4906), l_5262)), g_3109[1])) , g_472) || 0x302513DCL))), 13)) , g_472) < l_4906) ^ l_4634), g_1684[0])) || g_2467) , l_5833)) != 0x53L) && l_5262) , g_154)) || 1L)) >= l_4906) < 4294967295UL))) , 3L);
        }


for (l_5599 = 0; l_5599 < 1; l_5599++)
        g_5210[l_5599] = 1L;

                    printf("index = [%d]\n", k);}

    }


for (l_4584 = 0; l_4584 < 1; l_4584++)
                        g_1684[l_4584] = 0x5E55L;

                    for (l_4583 = 3; (l_4583 >= 0); l_4583 -= 1)
            {
                uint8_t l_5387 = 250UL;
                int8_t l_5393 = 0xB9L;
                ;
                l_4584 = (g_2853[0][0][5] = g_1684[0]);
                for (l_4585 = 4; (l_4585 >= 1); l_4585 -= 1)
                {
                    int i, j;

l_4686 += 1;



for (g_469 = 0; (g_469 != 49); g_469 = safe_add_func_uint16_t_u_u(g_469, 6))
                    {

if (g_68)
                        goto lbl_4940;

                    g_5210[0] = 1L;
                        l_4635 = g_34[0];
                    };


                    g_3935[(l_4583 + 2)][l_4585] = g_3935[(l_4583 + 3)][l_4585];

if (g_1370[2])
                            continue;

                    for (g_1368 = 0; (g_1368 <= 3); g_1368 += 1)
                    {
                        int16_t l_5394 = 0x3D45L;
                        int i, j, k;
                        l_4635 = ((safe_lshift_func_uint16_t_u_u(((((safe_sub_func_int32_t_s_s(0x161E66C8L, (safe_add_func_uint16_t_u_u(((safe_mod_func_uint8_t_u_u((safe_div_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s((safe_add_func_int32_t_s_s(((safe_lshift_func_uint8_t_u_s((safe_lshift_func_int8_t_s_s(((((g_98[3][2] = 0x0CC0L) && (safe_mod_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((((safe_div_func_int8_t_s_s((-6L), l_5135[g_1368][(g_1368 + 1)][l_4583])) | (safe_mod_func_int8_t_s_s((l_5135[g_1368][(g_1368 + 1)][l_4585] >= (l_5387 <= ((g_3935[5][4] >= l_4564) , (((((safe_rshift_func_uint8_t_u_s(((p_17 = (((((safe_sub_func_int8_t_s_s(((!p_17) | 0x7EFDE313L), g_1370[2])) != g_1138) <= g_4423[1]) || g_98[3][2]) , g_3935[(l_4583 + 3)][l_4585])) && 0L), 4)) <= 0x27CB126EL) <= l_5393) || 1UL) != g_3935[1][0])))), 0x02L))) != l_5394), p_16)), 1UL))) | g_2467) && l_4686), l_5387)), l_5387)) || g_154), g_1352)), g_154)), g_4475)), p_16)), g_154)) > 0UL), (-2L))))) , g_469) >= 0x92L) <= p_16), l_5393)) , p_16);
                    }

if (g_1370[1])
                            break;

                    for (g_275 = 21; (g_275 != (-13)); g_275--)
                    {
                        int16_t l_5399[7] = {(-1L),0xDCE8L,(-1L),(-1L),0xDCE8L,(-1L),(-1L)};
                        int i;

{
                        int16_t l_4243 = (-1L);
                        g_2853[3][2][5] = ((g_6771 = ((((safe_sub_func_int32_t_s_s(0x8CE52AFEL, g_184)) < (!(safe_sub_func_uint32_t_u_u((g_3463 , (safe_add_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(((l_5554 , ((((l_5554 , (g_5210[0] = g_184)) != ((g_1138 || (l_4243 < g_3109[1])) , 0x9A66B615L)) < l_5554) > g_184)) ^ 0x96A3L), l_5554)), g_1798[5][2]))), l_4634)))) & g_1138) | g_3463)) && l_5406);
                        if (g_2440)
                            continue;
                    }

                    g_1370[1] = (-5L);

{
                        uint32_t l_1192 = 0UL;
                        ;
                        l_1192 = g_5844;
                    }

                    l_5399[0] = (safe_add_func_uint16_t_u_u((g_3317 = 1UL), p_16));
                    }
                    if ((safe_lshift_func_uint16_t_u_u(l_4634, 1)))
                    {
                        if (p_16)
                            break;
                        if (l_4634)
                            {
if (l_5181)
                        goto lbl_4940;

                    break;}
                    }
                    else
                    {

{
                        int32_t l_6761 = 0x97130E1AL;
                        uint32_t l_6767 = 0UL;
                        g_2043 = ((g_184 = (~(safe_mod_func_int16_t_s_s((((((+((safe_div_func_int32_t_s_s(((((safe_lshift_func_int16_t_s_u(((((l_4917 = (-1L)) & (l_6761 = (l_4634 , (l_5393 & g_469)))) < g_6771) | 0x3AL), ((g_275 = g_1370[0]) , (2UL >= (((safe_div_func_int16_t_s_s((((g_98[2][2] = (l_5358 = ((((g_2853[0][6][6] = (safe_div_func_uint32_t_u_u((l_5425 = l_5393), g_3172))) , l_5427) ^ l_6767) ^ l_5393))) ^ 1UL) | g_275), 4L)) && 0x74CC71B1L) , 0x5542L))))) >= g_1370[2]) == 0x03L) & l_5393), l_4667)) ^ 4294967291UL)) , 1UL) <= l_4667) < g_1798[5][2]) > 0xFD327552L), l_5393)))) <= l_4686);
                    }


if (g_1370[1])
                            {
if (l_5122)
                            break;

                    break;}


{
        transparent_crc(g_4423[l_4584], "g_4423[l_4584]", l_4917);
        if (l_4917) printf("index = [%d]\n", l_4584);

    }

                    g_3935[(l_4583 + 2)][l_4585] = g_1345;
                        if (p_16)
                            break;
                        if (g_3935[(l_4583 + 2)][l_4585])
                            ;;
                    }
                }
            }
            if ((((safe_lshift_func_int8_t_s_u((-2L), (p_17 = g_87))) < 1UL) , (safe_mod_func_int8_t_s_s(g_2853[0][6][6], (((g_4423[0] ^ ((l_5406 > p_17) < ((g_98[1][3] , ((safe_sub_func_int32_t_s_s((l_4663[0][3][0] = (safe_div_func_int8_t_s_s((((+(p_16 != p_17)) <= (-1L)) & 3L), p_16))), 3UL)) >= 0UL)) , 0x3B6EA387L))) ^ l_4906) ^ l_5308)))))
            {
                int8_t l_5428 = (-1L);
                int32_t l_5429 = (-6L);
                l_5429 = (safe_sub_func_uint32_t_u_u((safe_mod_func_int16_t_s_s((safe_div_func_int16_t_s_s((((~(((((safe_sub_func_uint16_t_u_u((l_5421 != p_16), 1L)) ^ (((~(0x3FL == g_982)) & ((l_4586 = p_17) && (safe_mod_func_int32_t_s_s(((l_5425 & ((((~p_17) < (((((l_5427 = 5L) != p_17) & 0x02B33D1CL) != p_17) , 0x73E4L)) ^ p_16) <= l_5425)) && l_4634), g_3109[0])))) > (-3L))) > g_335) && l_4667) && l_5428)) && g_98[1][3]) | g_98[2][0]), g_2853[0][6][6])), g_1798[3][2])), l_5425));

l_5729 += 1;


                    for (g_335 = 13; (g_335 >= 9); g_335--)
                {
                    uint8_t l_5432 = 5UL;

if (g_1798[5][2])
                            continue;

                    if (l_5432)
                        {
for (j = 0; j < 9; j++)
    {
        transparent_crc(g_5446[j], "g_5446[j]", l_4665);
        if (l_4665) printf("index = [%d]\n", j);

    };


                    break;}
                }

            }
            else
            {
                uint32_t l_5467[1][9] = {{18446744073709551609UL,18446744073709551609UL,18446744073709551609UL,18446744073709551609UL,18446744073709551609UL,18446744073709551609UL,18446744073709551609UL,18446744073709551609UL,18446744073709551609UL}};
                int32_t l_5474 = 0xBCC584FDL;
                uint32_t l_5477 = 0x31EC109FL;
                int i, j;
                for (l_4634 = 0; (l_4634 == 11); l_4634++)
                {
                    uint8_t l_5436 = 0x0CL;
                    ;
                }
                if ((((((l_4667 = p_17) , (safe_rshift_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(0UL, (safe_div_func_int8_t_s_s(g_5210[0], ((safe_rshift_func_int16_t_s_s((((l_4584 = p_16) <= (safe_sub_func_uint8_t_u_u(0xEEL, (safe_div_func_uint8_t_u_u((((safe_div_func_uint16_t_u_u(g_5446[5], (safe_add_func_uint32_t_u_u((safe_div_func_int16_t_s_s(((l_5467[0][4] >= (((((l_4663[0][3][4] = (((((safe_sub_func_uint8_t_u_u((~(safe_lshift_func_int16_t_s_u((l_5474 = (1L == (+(p_17 ^ 0x158FL)))), p_17))), (-1L))) < p_16) || l_4634) && p_16) && l_5309)) & (-5L)) , p_17) ^ g_496[1]) <= 0x93782DD3L)) , 0x5845L), g_3317)), (-5L))))) < 0L) == g_472), 251UL))))) < 1UL), g_1370[2])) | 0x98L))))), p_17))) , 3L) & l_5467[0][1]) > g_897))
                {

g_1599 += 1;


                    return g_335;
                }
                else
                {


g_6029 += 1;


                    if (l_4667) {
{
                ;

for (g_982 = 0; (g_982 <= 1); g_982 += 1)
                    {
                        uint8_t l_1049 = 0x11L;
                        int32_t l_1055[7] = {0L,0L,0L,0L,0L,0L,0L};
                        int i;
                        l_1049 = (0x70L && (g_68 != (g_98[3][3] <= (safe_mod_func_int8_t_s_s((safe_div_func_uint32_t_u_u((0xC84EL < (l_5474 , (((safe_rshift_func_int16_t_s_u(((((safe_mod_func_uint32_t_u_u(3UL, (safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((g_184 = ((safe_add_func_uint32_t_u_u(0UL, (safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_s((((k = ((safe_div_func_uint32_t_u_u((4294967293UL == ((0x53D2L > g_506) | g_506)), g_506)) != 0xF29CL)) & g_172) , g_87), 5)), g_87)))) ^ l_5308)) || g_4475), 6)), 255UL)))) == 0xFEB37081L) != g_3463) | g_573), g_87)) , g_87) & g_87))), g_1368)), g_4475)))));
                        k = (l_1049 , (((l_5427 = (g_87 || ((((safe_div_func_int32_t_s_s(((0x56D9L && g_897) >= ((g_87 > ((1UL < (((((l_1055[0] = (0x1FL || (g_87 = (+(safe_mod_func_uint8_t_u_u(252UL, (g_982 , l_5427))))))) >= g_3463) <= 1L) & g_897) & g_87)) || g_87)) > l_5474)), (-2L))) > g_98[1][3]) | g_897) ^ 0xA113L))) , g_897) < g_982));
                    };


                    g_2853[0][6][6] = (-6L);
            }


{
                        l_4584 = (safe_sub_func_uint32_t_u_u(4294967288UL, g_87));
                    }

                    printf("index = [%d]\n", l_4917);}


{
                        uint32_t l_1192 = 0UL;
                        ;
                        l_1192 = p_16;
                    }

                    for (g_2043 = 24; (g_2043 != 8); g_2043 = safe_sub_func_int8_t_s_s(g_2043, 7))
                    {
                        if (p_17)
                            break;

if (g_35)
                            continue;

                    l_5477 = g_35;
                    }
                }
            }
        }
        else
        {
            const int8_t l_5513 = (-1L);
            int32_t l_5514 = 0xA110A837L;
            int32_t l_5542 = (-10L);
            int32_t l_5822 = 0L;
            uint16_t l_5833 = 0UL;
            for (l_4686 = 0; (l_4686 < 52); l_4686++)
            {
                uint32_t l_5500 = 4294967295UL;
                int32_t l_5529 = 0x73A6F5D6L;
                int32_t l_5553 = (-5L);

{
                        ;
                    }



for (k = 0; k < 9; k++)
    {
        for (l_5763 = 0; l_5763 < 8; l_5763++)
        {
            transparent_crc(g_1798[k][l_5763], "g_1798[k][l_5763]", g_3486);
            if (g_3486) {
{
                for (g_3463 = 0; (g_3463 < 11); g_3463 = safe_add_func_uint32_t_u_u(g_3463, 3))
                {
                    l_4586 = (safe_unary_minus_func_uint32_t_u(0xF6FB99F5L));
                }
            }

                    printf("index = [%d][%d]\n", k, l_5763);}

        }
    };


                    ;



{
                    uint32_t l_1551 = 0x9416B214L;
                    uint32_t l_1556 = 18446744073709551607UL;
                    int32_t l_1579 = 8L;
                    int32_t l_1580 = 0x8D7AA905L;
                    g_1370[1] = (g_469 <= (safe_add_func_int32_t_s_s(((safe_div_func_int32_t_s_s((safe_add_func_uint16_t_u_u((0x50CDAC7AL ^ 0UL), (safe_div_func_uint8_t_u_u((((l_5500 = ((safe_rshift_func_uint8_t_u_s(((((l_5421 | l_1551) <= (safe_div_func_uint32_t_u_u((((safe_sub_func_int16_t_s_s(l_1556, 0x6B79L)) , (+(l_5696 && 0xDD0D3C63L))) == 0xADL), g_98[4][0]))) >= 3UL) , g_172), l_5696)) , g_469)) || l_5696) || l_5421), l_5696)))), l_5729)) , l_5181), 0x2CF1C0D2L)));
                    l_5511 = (safe_div_func_int32_t_s_s((l_5696 <= ((safe_mod_func_int8_t_s_s(1L, ((!((g_1288 | (safe_rshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(((safe_sub_func_uint32_t_u_u(g_5225, ((((l_1580 = (safe_div_func_uint8_t_u_u(((65533UL < g_34[0]) == (((safe_rshift_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((g_34[0] | (~((safe_lshift_func_int8_t_s_s(((l_5696 <= ((((((l_1579 = (l_5696 != 0x80L)) == 4UL) & 1UL) >= 0xA35CF382L) >= l_5696) , 246UL)) && l_5696), l_1551)) != l_5696))), l_5696)), 2)) ^ 0xB08CL) == l_5554)), 1L))) && g_1138) != g_87) & l_5696))) > 65528UL), g_172)), 3))) < 0xA6E2C9A9L)) , g_98[3][2]))) >= g_5844)), 0x633B263DL));
                }

                    l_4667 = ((((safe_lshift_func_uint16_t_u_s(((((p_17 == ((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_s((safe_mod_func_uint32_t_u_u(((l_5514 = (safe_sub_func_uint16_t_u_u((((((l_5308 && (1L == p_16)) , (safe_mod_func_int16_t_s_s((g_335 = (g_35 = (((safe_add_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u(l_5500, ((safe_mod_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u((((p_17 | (p_17 & (safe_rshift_func_int8_t_s_s((safe_div_func_int32_t_s_s(0xB013770DL, (safe_mod_func_int16_t_s_s(((((0xAAL != g_3172) >= l_5500) && 0L) != 1UL), l_5511)))), 7)))) > l_5500) , 0x74B8L), 0UL)), p_17)) < g_5512))), 0xCF82E3BFL)), l_4917)) < p_17) <= p_16))), g_897))) < 1L) > g_472) , g_76), l_5513))) >= 0L), g_34[0])), 15)), g_4423[1])) && 0L)) != g_184) & p_16) <= (-10L)), 5)) , p_17) >= p_16) == g_2467);

if (g_352)
                            break;

                    if (((safe_rshift_func_uint16_t_u_s(l_5500, (safe_add_func_int8_t_s_s(((((((safe_mod_func_int8_t_s_s((((+((l_5529 = (safe_add_func_int16_t_s_s((safe_add_func_int8_t_s_s((((g_204 == (p_16 > ((+((safe_div_func_int8_t_s_s(l_5529, (l_5514 = (p_17 = (safe_sub_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_u((((safe_mod_func_uint16_t_u_u((g_1599 = ((l_5553 = (safe_add_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((l_4635 = l_5542), (l_4663[0][3][4] = (safe_rshift_func_uint8_t_u_s((safe_div_func_int8_t_s_s((((safe_lshift_func_int8_t_s_u(((safe_add_func_int32_t_s_s((-4L), (((((g_1368 || (g_1368 = (g_3463 = 1UL))) < (safe_mod_func_uint32_t_u_u(l_5513, p_17))) && 0xD9F73B96L) <= 0x0F6CL) && 8L))) == 0x7F73L), g_1370[2])) < p_16) != g_3109[0]), 246UL)), 0))))), p_17)) || g_4475), l_5500))) || p_16)), g_573)) != p_17) ^ p_17), g_4423[6])) , 8UL), p_17)))))) != 1UL)) < g_3935[3][2]))) >= 0x32354B20L) > 9UL), 3UL)), g_4423[1]))) , l_5553)) == l_5500) > p_16), 0xE0L)) == (-7L)) | p_16) >= 0xFEC3L) & g_9) > l_5554), 1UL)))) , l_5500))
                {
                    uint32_t l_5567[5][7] = {{5UL,18446744073709551609UL,0x909CF5E8L,0xCFF8EDB2L,0x909CF5E8L,18446744073709551609UL,5UL},{18446744073709551610UL,0xA6F551C9L,8UL,0x75111B36L,0xCFF8EDB2L,0UL,5UL},{0xCFF8EDB2L,5UL,0x96530A5CL,0x96530A5CL,5UL,0xCFF8EDB2L,18446744073709551610UL},{18446744073709551609UL,0x96530A5CL,8UL,18446744073709551610UL,0xA77667EBL,0xCFF8EDB2L,0xCFF8EDB2L},{0x75111B36L,0xA77667EBL,0x909CF5E8L,0xA77667EBL,0x75111B36L,0UL,18446744073709551609UL}};
                    int32_t l_5568 = 0xF1F27906L;
                    int32_t l_5569 = 0L;
                    int i, j;


{
                g_1370[2] = l_4634;
                return l_5542;
            }

                    for (g_3317 = 16; (g_3317 > 46); g_3317 = safe_add_func_uint16_t_u_u(g_3317, 5))
                    {
                        int16_t l_905 = 0L;
                        l_905 = (l_5529 = g_3463);
                    };


                    l_5569 = ((l_5568 = ((g_352 = (((((((safe_sub_func_int32_t_s_s(((((safe_sub_func_int16_t_s_s((safe_div_func_uint8_t_u_u((safe_div_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(p_17, l_5529)) | 0x74L), p_17)), 8L)), (p_16 = (l_5358 >= ((safe_lshift_func_uint16_t_u_s(0UL, p_17)) != (p_16 && g_335)))))) && l_5500) != 0UL) , 5L), l_5529)) , l_5553) & l_5567[2][5]) > 0x08L) || 0xE764B52EL) ^ p_17) <= l_5529)) , 6L)) || l_5529);
                    g_5446[5] = 8L;
                    g_2853[0][3][1] = (g_3172 && (l_4585 = p_17));

{
                    uint32_t l_4757[2][4][8] = {{{7UL,18446744073709551615UL,18446744073709551615UL,7UL,1UL,18446744073709551615UL,1UL,7UL},{18446744073709551615UL,1UL,18446744073709551615UL,18446744073709551615UL,0x6058AFA6L,0x6058AFA6L,18446744073709551615UL,18446744073709551615UL},{1UL,1UL,1UL,18446744073709551615UL,7UL,18446744073709551615UL,1UL,2UL},{2UL,18446744073709551615UL,0x6058AFA6L,1UL,1UL,0x6058AFA6L,18446744073709551615UL,2UL}},{{18446744073709551615UL,18446744073709551615UL,2UL,18446744073709551615UL,2UL,18446744073709551615UL,18446744073709551615UL,18446744073709551615UL},{18446744073709551615UL,18446744073709551615UL,0x6058AFA6L,0x6058AFA6L,18446744073709551615UL,18446744073709551615UL,1UL,18446744073709551615UL},{18446744073709551615UL,18446744073709551615UL,1UL,18446744073709551615UL,18446744073709551615UL,0x6058AFA6L,0x6058AFA6L,18446744073709551615UL},{18446744073709551615UL,18446744073709551615UL,18446744073709551615UL,18446744073709551615UL,2UL,18446744073709551615UL,2UL,18446744073709551615UL}}};
                    int i, j, k;
                    for (l_5511 = 6; (l_5511 < 11); l_5511++)
                    {
                        int16_t l_4762[8][8] = {{0x0037L,8L,0xF5D9L,0xD074L,0x7D90L,0xF907L,0xD074L,0x0037L},{2L,8L,0xBD15L,0x0127L,(-9L),0x0127L,0xBD15L,8L},{8L,0xBF8FL,1L,0x7D90L,0xBD15L,1L,0x0037L,2L},{0x0037L,0x72D3L,0xE4EFL,0x3542L,8L,0xF5A0L,0x0037L,0x0037L},{0x6055L,0x3542L,1L,1L,0x3542L,0x6055L,0xBD15L,0x72D3L},{0x3542L,0x6055L,0xBD15L,0x72D3L,0x0127L,1L,0xD074L,0x0127L},{0x72D3L,0x0037L,0xF5D9L,0x72D3L,8L,0xC4CCL,8L,0x72D3L},{0xBF8FL,8L,0xBF8FL,1L,0x7D90L,0xBD15L,1L,0x0037L}};
                        int32_t l_4763 = 1L;
                        int i, j;

if ((((safe_lshift_func_int8_t_s_u((-2L), (g_4475 = g_472))) < 1UL) , (safe_mod_func_int8_t_s_s(g_2853[0][6][6], (((g_4423[0] ^ ((g_6029 > g_4475) < ((g_98[1][3] , ((safe_sub_func_int32_t_s_s((l_4663[0][3][0] = (safe_div_func_int8_t_s_s((((+(l_4906 != g_4475)) <= (-1L)) & 3L), l_4906))), 3UL)) >= 0UL)) , 0x3B6EA387L))) ^ g_1288) ^ l_4906)))))
            {
                int8_t l_5428 = (-1L);
                int32_t l_5429 = (-6L);
                l_5429 = (safe_sub_func_uint32_t_u_u((safe_mod_func_int16_t_s_s((safe_div_func_int16_t_s_s((((~(((((safe_sub_func_uint16_t_u_u((l_5309 != l_4906), 1L)) ^ (((~(0x3FL == l_4921)) & ((l_5763 = g_4475) && (safe_mod_func_int32_t_s_s(((l_5568 & ((((~g_4475) < (((((l_5529 = 5L) != g_4475) & 0x02B33D1CL) != g_4475) , 0x73E4L)) ^ l_4906) <= l_5568)) && l_5529), g_3109[0])))) > (-3L))) > l_5122) && l_4585) && l_5428)) && g_98[1][3]) | g_98[2][0]), g_2853[0][6][6])), g_1798[3][2])), l_5568));

{
                int32_t l_5622 = 0x4115D784L;
                int8_t l_5717 = 0L;
                int32_t l_5728[1];
                uint32_t l_5749[6][9][3] = {{{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL}},{{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL}},{{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL}},{{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL}},{{0UL,0xCC33B38DL,1UL},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL},{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL},{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL}},{{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL},{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL},{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL}}};
                const uint8_t l_5781[3][6][1] = {{{0xC6L},{4UL},{4UL},{0xDDL},{4UL},{4UL}},{{0xC6L},{4UL},{4UL},{0xDDL},{4UL},{4UL}},{{0xC6L},{4UL},{4UL},{0xDDL},{4UL},{4UL}}};
                int i, j, k;
                for (i = 0; i < 1; i++)
                    l_5728[i] = 0x2FECE2D3L;
                for (l_4564 = 9; (l_4564 > 24); l_4564++)
                {
                    int16_t l_5614 = 0x9D0FL;
                    int32_t l_5625 = (-2L);
                    int16_t l_5727 = 0xE03EL;
                    if ((safe_rshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_s(0xDBL, 3)) & ((l_5614 <= p_17) >= 0x0C2BL)), (safe_sub_func_int16_t_s_s(0x7363L, ((safe_lshift_func_int8_t_s_u((safe_unary_minus_func_uint8_t_u((0x6F64943CL > (((safe_div_func_int32_t_s_s((l_5591[3] && ((l_5500 = ((g_1345 = l_5622) | 0x28E1A48FL)) < g_2580[0][7])), l_5006)) & g_335) || g_1370[2])))), l_5614)) & p_17))))))
                    {
                        l_5514 = 0xC846F6BAL;
                    }
                    else
                    {
                        uint32_t l_5652 = 3UL;
                        int32_t l_5679 = 0x62C2DA79L;
                        int32_t l_5695[10] = {(-3L),(-3L),(-3L),(-3L),(-3L),(-3L),(-3L),(-3L),(-3L),(-3L)};
                        int i;
                        l_5625 = (safe_sub_func_int16_t_s_s(g_1345, g_98[1][3]));
                        g_3935[3][2] = (g_3193 , (((safe_rshift_func_uint16_t_u_u((safe_add_func_int8_t_s_s((g_154 = (safe_div_func_uint16_t_u_u((+(g_335 < (((((safe_div_func_int32_t_s_s((0x2F67L >= (safe_mod_func_uint8_t_u_u((safe_div_func_uint16_t_u_u((((g_1345 > (safe_div_func_uint32_t_u_u((safe_sub_func_uint8_t_u_u(((safe_sub_func_int32_t_s_s(0xAF911F44L, (((safe_lshift_func_uint16_t_u_u((((safe_unary_minus_func_uint8_t_u((l_5428 == (p_17 < ((safe_div_func_uint16_t_u_u(p_17, (safe_mod_func_uint32_t_u_u((g_2043 ^ g_335), g_335)))) , p_17))))) , p_17) >= 0xF0899875L), 1)) & 4L) || 5UL))) & l_5614), l_5006)), g_3193))) , p_17) & p_17), p_17)), 255UL))), g_2580[2][8])) , 0xE51A63BFL) && g_335) ^ (-1L)) >= 1UL))), 65533UL))), 0x47L)), g_472)) == 0UL) , l_5652));
                        g_5446[5] = ((safe_rshift_func_int8_t_s_u((g_506 = (((~0L) != ((-1L) && (((((l_5514 = (safe_lshift_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((l_5622 && ((safe_sub_func_uint16_t_u_u((l_5006 < ((((g_3109[2] = l_4921) && (((g_3935[3][2] & ((g_335 | (safe_mod_func_int8_t_s_s((p_17 && (((l_5622 = (safe_mod_func_int8_t_s_s(((safe_lshift_func_int16_t_s_u((g_6428 > l_5652), 12)) >= 0xBC1EAF97L), 0xC1L))) >= 1L) , 0xC128L)), g_3317))) || 0xB64EL)) , l_5652) <= 0x11L)) >= l_5614) , l_5652)), 65535UL)) != 0x45EAL)), p_17)), l_5358))) != 0x5E36L) <= p_17) & l_4564) | 0UL))) <= l_4584)), g_335)) , 0xB6B4A457L);
                        l_5514 = (((safe_sub_func_uint32_t_u_u(((safe_div_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u(p_17, 6)), (l_5428 = g_3109[0]))) | (safe_lshift_func_uint16_t_u_s(((((p_17 | (safe_sub_func_uint32_t_u_u((g_352 = ((l_4663[0][0][2] = ((((((((~l_5679) < (((safe_sub_func_int8_t_s_s(l_5568, (((safe_sub_func_uint32_t_u_u(g_335, (safe_add_func_uint32_t_u_u(((l_5500 = (((safe_mod_func_uint8_t_u_u(((l_5262 && (((safe_lshift_func_int8_t_s_s((l_4586 = ((l_5695[2] = (!((safe_sub_func_int32_t_s_s(((((0x1EL && ((safe_sub_func_int32_t_s_s(((g_98[3][3] = (p_17 != 4294967295UL)) != g_9), 0x984A2A0DL)) | g_472)) >= l_5514) ^ 8UL) != g_1370[1]), p_17)) != 6L))) < 4294967295UL)), 0)) && 0x3550AFCBL) && 0UL)) , p_17), l_5568)) , l_5833) > 0x627D0751L)) ^ l_5652), g_6428)))) ^ 0x025ADBE1L) , l_5513))) && g_3193) , 0x0A48DBD9L)) , l_5622) , p_17) , 255UL) > l_4921) || g_87) , l_5622)) && p_17)), l_5514))) & g_472) >= 0x8478L) | g_335), p_17))), g_1369)) && g_335) ^ 1L);
                    }
                    if ((+0x78ABDE30L))
                    {
                        uint32_t l_5707 = 6UL;
                        l_5428 = ((safe_sub_func_int16_t_s_s(g_335, (l_5625 = g_1345))) , ((l_5514 = (~(safe_div_func_int16_t_s_s(((safe_mod_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(l_5707, (safe_div_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s(((((((safe_lshift_func_int16_t_s_u(g_1370[2], 2)) | l_5707) ^ (safe_sub_func_int8_t_s_s((~p_17), l_5717))) > ((l_5728[0] = ((((((((safe_add_func_int32_t_s_s((l_5622 = (safe_add_func_uint8_t_u_u((((0x64689EF7L ^ ((safe_lshift_func_uint8_t_u_s(((safe_unary_minus_func_int32_t_s(((safe_mod_func_uint8_t_u_u((p_17 | (-1L)), l_4635)) || l_5717))) < l_5513), g_3193)) | g_3935[3][2])) || g_335) , l_5727), 0x41L))), p_17)) == g_335) , 1UL) < (-7L)) && 0xA701L) , 0xB060L) == l_4586) ^ g_352)) == l_5428)) & (-1L)) != l_5707), l_5717)), l_5513)))), l_5625)) ^ g_98[1][3]), l_5514)))) ^ 4294967295UL));
                        l_4586 = (((l_5833 = ((safe_div_func_uint32_t_u_u((g_1368 = (l_5514 = ((((safe_unary_minus_func_uint16_t_u((safe_div_func_int8_t_s_s((0xDC9BL || (safe_sub_func_int16_t_s_s(l_5833, (((safe_lshift_func_uint16_t_u_u(l_5707, ((((l_5514 ^ (g_335 = ((safe_add_func_uint8_t_u_u(l_5717, (safe_rshift_func_uint16_t_u_s(l_5707, 4)))) < ((safe_sub_func_uint32_t_u_u(g_5446[0], (safe_mod_func_uint8_t_u_u((safe_sub_func_int8_t_s_s(p_17, l_5749[1][4][1])), k)))) >= l_4584)))) <= g_1370[2]) > l_5749[1][4][1]) < l_5514))) ^ 0L) , g_9)))), l_5428)))) , 252UL) <= 1UL) | p_17))), p_17)) , l_5707)) & g_335) && l_5625);
                    }
                    else
                    {
                        int8_t l_5764 = 0xC3L;
                        l_5728[0] = ((safe_unary_minus_func_int16_t_s((-1L))) == (((safe_rshift_func_int8_t_s_u(((p_17 = (((l_4635 = ((p_17 = g_9) ^ ((safe_mod_func_int8_t_s_s(l_5728[0], (safe_rshift_func_int16_t_s_u((g_1345 ^ (safe_add_func_uint16_t_u_u((safe_mod_func_int32_t_s_s(4L, (g_335 , g_1798[5][2]))), ((-1L) | (safe_lshift_func_uint16_t_u_s(((g_1368 = (l_4763 <= g_335)) <= g_472), g_335)))))), g_335)))) <= l_4584))) , l_4586) ^ g_335)) & g_335), l_5764)) != 0xC85B220FL) & l_5764));
                    }
                }
                for (g_9 = 0; (g_9 != 20); g_9 = safe_add_func_int16_t_s_s(g_9, 5))
                {
                    int32_t l_5782[1][2];
                    int i, j;
                    for (i = 0; i < 1; i++)
                    {
                        for (j = 0; j < 2; j++)
                            l_5782[i][j] = 0x0C8073CEL;
                    }
                    g_1370[1] = (g_506 = (((l_5428 < ((g_2043 , l_4564) <= g_352)) , (safe_div_func_int16_t_s_s((safe_sub_func_int16_t_s_s(((safe_add_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u((safe_lshift_func_uint16_t_u_u((g_2043 ^ (l_5728[0] = (l_5006 = (g_1684[0] = (g_2853[0][6][6] ^ (((safe_mod_func_uint16_t_u_u(((g_4423[1] <= (safe_lshift_func_uint16_t_u_s(g_335, (((((g_352 > l_5749[5][7][1]) > 0x14DCL) > p_17) >= 0x5C4EL) < 0x27L)))) | p_17), 1L)) ^ 0xA9L) ^ l_5513)))))), l_4586)), g_335)), l_5781[1][3][0])) == 0x7BL), g_335)), l_5514))) && l_5782[0][1]));
                    for (g_472 = (-14); (g_472 > 15); g_472 = safe_add_func_int32_t_s_s(g_472, 7))
                    {
                        int8_t l_5789 = (-1L);
                        int32_t l_5790 = 0x8B610670L;
                        l_5728[0] = (((0x11C38EDCL || (((safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((g_87 < 1L) || g_335), ((g_335 = (g_1345 || l_5789)) & l_5006))), (-1L))) ^ 252UL) , 0x0F7F1C95L)) != 0xC2L) || 4294967287UL);
                        k = ((l_5428 == ((l_5790 = (g_1370[2] = g_335)) , (1UL && (((g_6428 >= (l_5514 = 0x8608L)) == ((((-1L) && 5UL) && g_335) | (((g_2043 ^ l_5781[0][5][0]) & l_4586) || g_496[1]))) || g_6428)))) | g_5210[0]);
                    }
                }
                l_5728[0] = (safe_mod_func_int32_t_s_s(((g_4423[1] = 255UL) != (p_17 <= ((safe_mod_func_int16_t_s_s((safe_add_func_int32_t_s_s((g_335 , (g_1370[1] = (((((((((safe_rshift_func_uint16_t_u_u((safe_add_func_int32_t_s_s((safe_rshift_func_int8_t_s_s(g_2043, 6)), g_335)), (safe_rshift_func_uint8_t_u_s((((safe_rshift_func_int16_t_s_u((((g_335 != 0UL) <= (((l_4921 > (safe_rshift_func_uint16_t_u_u((safe_div_func_int32_t_s_s((safe_rshift_func_int8_t_s_s((safe_add_func_uint16_t_u_u(l_4921, 0xEEE0L)), 6)), l_5358)), l_4635))) != l_4663[0][3][4]) < l_5568)) >= g_1798[8][6]), g_472)) > l_4583) , g_335), g_335)))) >= l_5749[1][4][1]) < g_2043) ^ 249UL) >= g_3193) || g_5210[0]) & 8L) && g_6428) != g_335))), 0x0D1E55A5L)), 0x6461L)) == g_352))), 0x7276E9ACL));
            }

                    for (l_5122 = 13; (l_5122 >= 9); l_5122--)
                {
                    uint8_t l_5432 = 5UL;
                    if (l_5432)
                        break;
                }
                for (g_6428 = 6; (g_6428 >= 0); g_6428 -= 1)
                {
                    int i;
                    return g_4423[g_6428];
                }
            }
            else
            {
                uint32_t l_5467[1][9] = {{18446744073709551609UL,18446744073709551609UL,18446744073709551609UL,18446744073709551609UL,18446744073709551609UL,18446744073709551609UL,18446744073709551609UL,18446744073709551609UL,18446744073709551609UL}};
                int32_t l_5474 = 0xBCC584FDL;
                uint32_t l_5477 = 0x31EC109FL;
                int i, j;
                for (l_5529 = 0; (l_5529 == 11); l_5529++)
                {
                    uint8_t l_5436 = 0x0CL;

{
        return g_68;
    }

                    g_1370[1] = (~(((g_2852 > (g_5210[0] , ((l_5436 ^ g_472) <= (((safe_rshift_func_int16_t_s_u((((safe_sub_func_int32_t_s_s((((5L > (safe_rshift_func_uint16_t_u_u(65535UL, (safe_unary_minus_func_uint16_t_u(((safe_div_func_int8_t_s_s(0xA7L, g_5446[5])) && 0x30381104L)))))) , g_154) ^ l_4585), 0x795A4A13L)) && g_759) , 0x3533L), l_4906)) ^ 0xD4L) || l_4584)))) && (-7L)) == g_4475));
                }
                if ((((((l_4585 = g_4475) , (safe_rshift_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(0UL, (safe_div_func_int8_t_s_s(g_5210[0], ((safe_rshift_func_int16_t_s_s((((g_240 = l_4906) <= (safe_sub_func_uint8_t_u_u(0xEEL, (safe_div_func_uint8_t_u_u((((safe_div_func_uint16_t_u_u(g_5446[5], (safe_add_func_uint32_t_u_u((safe_div_func_int16_t_s_s(((l_5467[0][4] >= (((((l_4663[0][3][4] = (((((safe_sub_func_uint8_t_u_u((~(safe_lshift_func_int16_t_s_u((l_5474 = (1L == (+(g_4475 ^ 0x158FL)))), g_4475))), (-1L))) < l_4906) || l_5529) && l_4906) && l_4906)) & (-5L)) , g_4475) ^ g_496[1]) <= 0x93782DD3L)) , 0x5845L), l_5358)), (-5L))))) < 0L) == g_1369), 251UL))))) < 1UL), g_1370[2])) | 0x98L))))), g_4475))) , 3L) & l_5467[0][1]) > g_6428))
                {
                    return l_5122;
                }
                else
                {
                    for (l_5569 = 24; (l_5569 != 8); l_5569 = safe_sub_func_int8_t_s_s(l_5569, 7))
                    {
                        if (g_4475)
                            break;
                        l_5477 = l_4906;
                    }
                }
            }
l_4635 -= 1;


                    ;


                    l_4763 = (((g_275 = ((safe_lshift_func_int8_t_s_s((((((l_4586 < (safe_mod_func_int8_t_s_s(g_1369, 0x65L))) , (l_4663[0][3][0] | (((((safe_add_func_int16_t_s_s(((((safe_div_func_uint8_t_u_u(((g_4475 == (safe_mod_func_uint32_t_u_u(0UL, (l_4757[0][0][5] | ((safe_div_func_int8_t_s_s(0x9DL, (l_4762[2][0] = (safe_div_func_uint32_t_u_u(0x49F51FA9L, g_4475))))) < 0x63F9F56CL))))) & 6L), g_5225)) , g_4689) & g_335) , g_6428), 1UL)) >= l_5181) < 0x25389E08L) >= 0x8AD97483L) | g_6428))) , g_4475) > 0xE9L) , g_4475), g_3109[1])) == g_6428)) , 0x21L) == g_1684[0]);
                        if (g_4689)
                            break;
                        ;
                    }
                }

                    for (l_5569 = 0; (l_5569 >= 0); l_5569 -= 1)
                    {
                        int i;

{
                    int32_t l_5042 = 0xDF7BA6E3L;
                    int32_t l_5059[7][6] = {{(-1L),0xEE5C0CA4L,(-1L),(-1L),0xEE5C0CA4L,(-1L)},{(-1L),0xEE5C0CA4L,(-1L),(-1L),0xEE5C0CA4L,(-1L)},{(-1L),(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL}};
                    int i, j;
                    if ((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((((g_35 >= (l_5406 & (safe_sub_func_int16_t_s_s((l_5553 <= ((safe_mod_func_uint16_t_u_u(((safe_add_func_int8_t_s_s(g_6771, g_184)) , ((((g_3935[3][2] = (0x04L <= 0x1EL)) && (safe_mod_func_uint16_t_u_u((((safe_lshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u((g_1370[2] || (((l_5406 = g_34[0]) >= (-1L)) <= g_1345)), g_35)), l_5763)) | 0x60L) < g_3109[0]), j))) , l_5042) && g_35)), l_4635)) , l_5406)), 1L)))) < l_4906) > 0x060AL), 15)), k)))
                    {
                        j = (safe_sub_func_uint32_t_u_u(4294967288UL, l_5406));
                    }
                    else
                    {
                        int32_t l_5054 = 0x212F6087L;
                        int32_t l_5057 = 0x47C4678DL;
                        int32_t l_5058 = 0xF147EEABL;
                        g_2580[3][0] = l_5406;
                        ;
                    }
                    l_4663[0][2][5] = l_5406;
                    for (g_3172 = 4; (g_3172 >= 0); g_3172 -= 1)
                    {
                        uint16_t l_5085 = 8UL;
                        int i, j;
                        g_2440 = (safe_div_func_uint16_t_u_u((((safe_div_func_uint16_t_u_u((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(((0x0B0296A1L | g_2852) >= ((g_35 , l_5406) ^ (((+(l_5514 , (safe_lshift_func_int8_t_s_s((safe_div_func_int8_t_s_s((safe_div_func_int8_t_s_s(((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_int8_t_s_s(0x97L, 6)) <= ((safe_sub_func_uint16_t_u_u(g_4689, l_4906)) | (safe_sub_func_uint16_t_u_u(((g_68 = ((safe_mod_func_int32_t_s_s((~l_5406), 0xEF43C697L)) <= l_5085)) | g_35), l_5085)))))) && g_184), 0xD5L)), g_6771)), l_4634)))) > g_98[(l_5511 + 1)][l_5511]) > 0xAB38C5B5L))), 0UL)) || l_5406), 1L)), g_3935[3][2])) <= 0xB7L) <= 0L), 0x9B54L));
                        l_4634 = (safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((safe_sub_func_uint32_t_u_u(0UL, (g_35 <= (((safe_mod_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s(g_35, 3)) == (0x02L >= (l_5406 = (((g_98[g_3172][g_3172] = ((safe_sub_func_int32_t_s_s((safe_lshift_func_int8_t_s_s((g_4689 = (l_5059[6][0] <= 0UL)), 2)), (safe_div_func_int8_t_s_s(((((1UL || (safe_add_func_int32_t_s_s((g_2580[2][8] = g_897), ((safe_mod_func_int16_t_s_s(g_35, g_68)) <= l_5511)))) , l_5406) < 0x98E0L) | l_4634), l_5406)))) > 0xEC1458CBL)) == 4L) , g_2580[2][8])))), l_5569)) || g_6771) , g_98[(l_5511 + 1)][l_5511])))) == l_5406), l_5514)), 0L)) < l_5569) == g_35), l_5406));
                        l_5542 = ((g_2580[l_5511][(l_5511 + 3)] = (safe_sub_func_uint8_t_u_u(l_5421, (g_4423[1] = ((safe_add_func_int16_t_s_s(((g_1345 = (((g_34[0] = ((l_4634 = (safe_mod_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_u(l_4634, l_4663[0][3][4])), (safe_add_func_uint8_t_u_u(l_5406, (j = l_4663[0][1][2])))))) || (safe_sub_func_uint8_t_u_u((((safe_div_func_int32_t_s_s(g_1288, (~(safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_u((l_5406 , (safe_rshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_u(g_2580[l_5511][(l_5511 + 3)], (l_5553 = ((+(0x99L >= l_5569)) < l_5085)))), g_35))), g_1798[7][3])), g_35)), l_5406))))) | g_35) & l_5729), l_5406)))) , g_2440) , l_5135[2][5][3])) == 0xF35EA988L), g_3935[2][0])) & l_5059[6][0]))))) >= 65535UL);
                    }
                    ;
                }

                    l_5591[3] = ((safe_add_func_uint16_t_u_u((g_1599 = (l_5514 = ((((l_5222[l_5569] != (65528UL || ((l_4585 = ((safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s(((safe_rshift_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_s(((3UL & (0xBB49D088L < ((safe_rshift_func_uint8_t_u_s(g_34[l_5569], (safe_add_func_int32_t_s_s((0x0F671AB7L ^ ((safe_add_func_int32_t_s_s(((l_4586 = (p_17 = ((g_34[l_5569] > (((((safe_add_func_int32_t_s_s((+((l_4564 = (g_5225 | ((((safe_div_func_uint16_t_u_u(0x578FL, l_5222[l_5569])) ^ 5UL) > 0x851AL) >= p_16))) < l_4906)), g_5446[5])) ^ p_17) && p_16) == 0UL) > 0xCEL)) < 0x217F7CF0L))) >= g_1352), 0L)) >= 0xB793C0CBL)), g_3109[1])))) == 0xBAL))) <= 0xECL), 5)) >= g_3935[3][2]), l_5542)) , 5L), l_5529)), g_2853[1][7][2])) >= g_2580[0][2])) >= l_4634))) > l_5542) , g_3935[3][2]) ^ 0x7010L))), p_16)) < 1L);
                        return p_16;
                    }
                }
                else
                {
                    ;

{
                        uint8_t l_1049 = 0x11L;
                        int32_t l_1055[7] = {0L,0L,0L,0L,0L,0L,0L};
                        int i;


g_759 += 1;


                    g_982 += 1;


                    l_1049 = (0x70L && (l_4921 != (g_98[3][3] <= (safe_mod_func_int8_t_s_s((safe_div_func_uint32_t_u_u((0xC84EL < (l_5511 , (((safe_rshift_func_int16_t_s_u(((((safe_mod_func_uint32_t_u_u(3UL, (safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((g_1138 = ((safe_add_func_uint32_t_u_u(0UL, (safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_s((((g_2440 = ((safe_div_func_uint32_t_u_u((4294967293UL == ((0x53D2L > g_275) | g_275)), g_275)) != 0xF29CL)) & l_5358) , l_5696), 5)), l_5696)))) ^ l_5006)) || g_472), 6)), 255UL)))) == 0xFEB37081L) != g_352) | g_2043), l_5696)) , l_5696) & l_5696))), g_3463)), g_472)))));
                        l_4917 = (l_1049 , (((l_5542 = (l_5696 || ((((safe_div_func_int32_t_s_s(((0x56D9L && l_4906) >= ((l_5696 > ((1UL < (((((l_1055[0] = (0x1FL || (g_472 = (+(safe_mod_func_uint8_t_u_u(252UL, (g_1345 , l_5542))))))) >= g_1345) <= 1L) & l_4906) & l_5696)) || l_5696)) > l_5511)), (-2L))) > g_98[1][3]) | l_4906) ^ 0xA113L))) , l_4906) < g_1345));
                    }


for (l_4585 = 21; (l_4585 != (-13)); l_4585--)
                    {
                        int16_t l_5399[7] = {(-1L),0xDCE8L,(-1L),(-1L),0xDCE8L,(-1L),(-1L)};
                        int i;
                        g_1370[1] = (-5L);
                        l_5399[0] = (safe_add_func_uint16_t_u_u((g_1599 = 1UL), g_35));
                    };


                    return g_5446[0];
                }
                for (g_2467 = (-7); (g_2467 > 27); g_2467++)
                {


{
                    uint8_t l_5432 = 5UL;
                    if (l_5432)
                        break;
                }

                    for (l_4585 = 0; l_4585 < 1; l_4585++)
                        {
g_172 += 1;


                    g_1684[l_4585] = 0x5E55L;}

                    ;
                }
            }


if (g_469)
                        {
for (l_5511 = 3; (l_5511 >= 0); l_5511 -= 1)
            {
                int i, j;
                g_1370[0] = ((g_1684[0] = (((-1L) ^ (safe_add_func_int32_t_s_s((g_2580[g_2440][(l_5511 + 3)] , (g_204 = (safe_add_func_int16_t_s_s((l_5542 = (((((safe_add_func_uint32_t_u_u(g_2580[g_2440][(g_2440 + 3)], ((g_98[l_5511][(g_2440 + 1)] = 2UL) | 0UL))) > (g_2580[g_2440][(l_5511 + 3)] <= ((((g_2580[g_2440][(l_5511 + 3)] >= (l_5696 = ((safe_lshift_func_int16_t_s_u((+(safe_rshift_func_int8_t_s_s((safe_add_func_uint8_t_u_u((+(l_5599 && (safe_lshift_func_uint16_t_u_s((g_4475 <= l_5696), g_2580[g_2440][(g_2440 + 3)])))), g_496[2])), l_5696))), g_4475)) , g_2580[g_2440][(l_5511 + 3)]))) & g_5512) || 0x85CAL) & g_2440))) == g_2467) , 0xE83AL) & 0x097CL)), g_2580[g_2440][(l_5511 + 3)])))), l_5309))) < l_5833)) == l_5599);
                for (l_4686 = 0; (l_4686 <= 4); l_4686 += 1)
                {
                    int32_t l_5042 = 0xDF7BA6E3L;
                    int32_t l_5059[7][6] = {{(-1L),0xEE5C0CA4L,(-1L),(-1L),0xEE5C0CA4L,(-1L)},{(-1L),0xEE5C0CA4L,(-1L),(-1L),0xEE5C0CA4L,(-1L)},{(-1L),(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL},{0x1CBEA57EL,(-1L),0x1CBEA57EL,0x1CBEA57EL,(-1L),0x1CBEA57EL}};
                    int i, j;
                    if ((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((((g_5512 >= (g_4475 & (safe_sub_func_int16_t_s_s((k <= ((safe_mod_func_uint16_t_u_u(((safe_add_func_int8_t_s_s(l_4921, g_6771)) , ((((g_3935[3][2] = (0x04L <= 0x1EL)) && (safe_mod_func_uint16_t_u_u((((safe_lshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u((g_1370[2] || (((l_5696 = g_34[0]) >= (-1L)) <= l_5181)), g_5512)), l_5599)) | 0x60L) < g_3109[0]), l_5599))) , l_5042) && g_5512)), l_5542)) , g_4475)), 1L)))) < g_1352) > 0x060AL), 15)), l_5542)))
                    {
                        l_5599 = (safe_sub_func_uint32_t_u_u(4294967288UL, g_4475));
                    }
                    else
                    {
                        int32_t l_5054 = 0x212F6087L;
                        int32_t l_5057 = 0x47C4678DL;
                        int32_t l_5058 = 0xF147EEABL;
                        g_2580[3][0] = g_4475;
                        l_5059[6][4] = ((((((l_4665 = (+(((safe_rshift_func_uint16_t_u_s(((((l_5696 != (safe_add_func_int8_t_s_s((g_204 = (safe_lshift_func_int16_t_s_u((l_5042 = ((safe_add_func_uint8_t_u_u(0x2FL, (g_2467 == (l_5054 = (252UL || g_5512))))) < 8UL)), ((((g_3600 <= (l_5058 = ((l_5599 = (safe_rshift_func_int8_t_s_u((k || (l_5057 = (((g_98[1][3] >= g_3935[2][4]) <= 0x9716L) > 0xA7L))), g_5512))) && g_1798[7][0]))) ^ (-2L)) ^ g_2580[g_2440][(g_2440 + 3)]) == 1L)))), l_5059[6][0]))) | g_1798[5][0]) & g_5512) == l_5511), l_5696)) , 0xA1L) && g_34[0]))) , g_5512) >= 65535UL) <= g_5512) , g_2580[g_2440][(g_2440 + 3)]) < g_1138);
                    }
                    l_4663[0][2][5] = g_4475;
                    for (g_2467 = 4; (g_2467 >= 0); g_2467 -= 1)
                    {
                        uint16_t l_5085 = 8UL;
                        int i, j;
                        g_2440 = (safe_div_func_uint16_t_u_u((((safe_div_func_uint16_t_u_u((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(((0x0B0296A1L | l_5696) >= ((g_5512 , g_4475) ^ (((+(l_4665 , (safe_lshift_func_int8_t_s_s((safe_div_func_int8_t_s_s((safe_div_func_int8_t_s_s(((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_int8_t_s_s(0x97L, 6)) <= ((safe_sub_func_uint16_t_u_u(g_3600, g_1352)) | (safe_sub_func_uint16_t_u_u(((l_5181 = ((safe_mod_func_int32_t_s_s((~g_4475), 0xEF43C697L)) <= l_5085)) | g_5512), l_5085)))))) && g_6771), 0xD5L)), g_6771)), l_5542)))) > g_98[(g_2440 + 1)][g_2440]) > 0xAB38C5B5L))), 0UL)) || g_4475), 1L)), g_3935[3][2])) <= 0xB7L) <= 0L), 0x9B54L));
                        l_5542 = (safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((safe_sub_func_uint32_t_u_u(0UL, (g_5512 <= (((safe_mod_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s(g_5512, 3)) == (0x02L >= (g_4475 = (((g_98[g_2467][g_2467] = ((safe_sub_func_int32_t_s_s((safe_lshift_func_int8_t_s_s((g_3600 = (l_5059[6][0] <= 0UL)), 2)), (safe_div_func_int8_t_s_s(((((1UL || (safe_add_func_int32_t_s_s((g_2580[2][8] = g_6428), ((safe_mod_func_int16_t_s_s(g_5512, l_5181)) <= l_5511)))) , g_4475) < 0x98E0L) | l_5542), g_4475)))) > 0xEC1458CBL)) == 4L) , g_2580[2][8])))), g_573)) || l_4921) , g_98[(g_2440 + 1)][g_2440])))) == g_9), l_4665)), 0L)) < g_573) == g_5512), g_9));
                        l_5554 = ((g_2580[g_2440][(g_2440 + 3)] = (safe_sub_func_uint8_t_u_u(g_5512, (g_4423[1] = ((safe_add_func_int16_t_s_s(((l_5181 = (((g_34[0] = ((l_5542 = (safe_mod_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_u(l_5542, l_4663[0][3][4])), (safe_add_func_uint8_t_u_u(g_4475, (l_5599 = l_4663[0][1][2])))))) || (safe_sub_func_uint8_t_u_u((((safe_div_func_int32_t_s_s(g_6428, (~(safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_u((g_4475 , (safe_rshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_u(g_2580[g_2440][(l_5511 + 3)], (l_5599 = ((+(0x99L >= l_5511)) < l_5085)))), g_5512))), g_1798[7][3])), g_5512)), l_5696))))) | g_5512) & g_3600), g_4475)))) , g_2440) , l_5135[2][5][3])) == 0xF35EA988L), g_3935[2][0])) & l_5059[6][0]))))) >= 65535UL);
                    }
                    g_2853[0][6][6] = (g_4475 , g_5512);
                }
                return l_4921;
            };


                    goto lbl_4940;}


g_9 += 1;


                    ;



{
                    g_1370[0] = l_4917;
                }

                    if ((safe_rshift_func_int16_t_s_u((l_5514 = l_4584), 3)))
            {
                int32_t l_5622 = 0x4115D784L;
                int8_t l_5717 = 0L;
                int32_t l_5728[1];
                uint32_t l_5749[6][9][3] = {{{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL}},{{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL}},{{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL}},{{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL},{0UL,0xCC33B38DL,1UL},{0UL,4294967293UL,0UL},{0UL,9UL,0xB37F2D8BL}},{{0UL,0xCC33B38DL,1UL},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL},{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL},{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL}},{{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL},{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL},{0x2DDE8E14L,1UL,0xD2EC4CA3L},{0x2DDE8E14L,0xB37F2D8BL,0x2DDE8E14L},{0x2DDE8E14L,0UL,0UL}}};
                const uint8_t l_5781[3][6][1] = {{{0xC6L},{4UL},{4UL},{0xDDL},{4UL},{4UL}},{{0xC6L},{4UL},{4UL},{0xDDL},{4UL},{4UL}},{{0xC6L},{4UL},{4UL},{0xDDL},{4UL},{4UL}}};
                int i, j, k;

{
                        uint32_t l_6538[6][1];
                        int i, j;
                        for (i = 0; i < 6; i++)
                        {
                            for (j = 0; j < 1; j++)
                                l_6538[i][j] = 0x22EB942DL;
                        }
                        ;
                        g_3486 = ((g_154 = g_5225) >= g_3486);
                    }


for (l_5822 = 0; l_5822 < 1; l_5822++)
                        g_1684[l_5822] = 0x5E55L;


if (((safe_rshift_func_uint16_t_u_s(g_3463, (safe_add_func_int8_t_s_s(((((((safe_mod_func_int8_t_s_s((((+((g_506 = (safe_add_func_int16_t_s_s((safe_add_func_int8_t_s_s((((l_5763 == (g_5512 > ((+((safe_div_func_int8_t_s_s(g_506, (j = (l_5223 = (safe_sub_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_u((((safe_mod_func_uint16_t_u_u((g_3317 = ((l_4635 = (safe_add_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((g_573 = l_5763), (l_4663[0][3][4] = (safe_rshift_func_uint8_t_u_s((safe_div_func_int8_t_s_s((((safe_lshift_func_int8_t_s_u(((safe_add_func_int32_t_s_s((-4L), (((((g_1138 || (g_1138 = (g_184 = 1UL))) < (safe_mod_func_uint32_t_u_u(l_5513, l_5223))) && 0xD9F73B96L) <= 0x0F6CL) && 8L))) == 0x7F73L), g_1370[2])) < g_5512) != g_3109[0]), 246UL)), 0))))), l_5223)) || g_2852), g_3463))) || g_5512)), g_573)) != l_5223) ^ l_5223), g_4423[6])) , 8UL), l_5223)))))) != 1UL)) < g_3935[3][2]))) >= 0x32354B20L) > 9UL), 3UL)), g_4423[1]))) , l_4635)) == g_3463) > g_5512), 0xE0L)) == (-7L)) | g_5512) >= 0xFEC3L) & l_5406) > g_573), 1UL)))) , g_3463))
                {
                    uint32_t l_5567[5][7] = {{5UL,18446744073709551609UL,0x909CF5E8L,0xCFF8EDB2L,0x909CF5E8L,18446744073709551609UL,5UL},{18446744073709551610UL,0xA6F551C9L,8UL,0x75111B36L,0xCFF8EDB2L,0UL,5UL},{0xCFF8EDB2L,5UL,0x96530A5CL,0x96530A5CL,5UL,0xCFF8EDB2L,18446744073709551610UL},{18446744073709551609UL,0x96530A5CL,8UL,18446744073709551610UL,0xA77667EBL,0xCFF8EDB2L,0xCFF8EDB2L},{0x75111B36L,0xA77667EBL,0x909CF5E8L,0xA77667EBL,0x75111B36L,0UL,18446744073709551609UL}};
                    int32_t l_5568 = 0xF1F27906L;
                    int32_t l_5569 = 0L;
                    int i, j;
                    l_5569 = ((l_5568 = ((g_184 = (((((((safe_sub_func_int32_t_s_s(((((safe_sub_func_int16_t_s_s((safe_div_func_uint8_t_u_u((safe_div_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(l_5223, g_506)) | 0x74L), l_5223)), 8L)), (g_5512 = (l_5358 >= ((safe_lshift_func_uint16_t_u_s(0UL, l_5223)) != (g_5512 && g_1352)))))) && g_3463) != 0UL) , 5L), g_506)) , l_4635) & l_5567[2][5]) > 0x08L) || 0xE764B52EL) ^ l_5223) <= g_506)) , 6L)) || g_506);
                    g_5446[5] = 8L;
                    g_2853[0][3][1] = (g_154 && (l_4665 = l_5223));
                    for (l_5569 = 0; (l_5569 >= 0); l_5569 -= 1)
                    {
                        int i;
                        l_5591[3] = ((safe_add_func_uint16_t_u_u((g_3317 = (j = ((((l_5222[l_5569] != (65528UL || ((l_4665 = ((safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s(((safe_rshift_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_s(((3UL & (0xBB49D088L < ((safe_rshift_func_uint8_t_u_s(g_34[l_5569], (safe_add_func_int32_t_s_s((0x0F671AB7L ^ ((safe_add_func_int32_t_s_s(((g_573 = (l_5223 = ((g_34[l_5569] > (((((safe_add_func_int32_t_s_s((+((g_506 = (g_5225 | ((((safe_div_func_uint16_t_u_u(0x578FL, l_5222[l_5569])) ^ 5UL) > 0x851AL) >= g_5512))) < l_5006)), g_5446[5])) ^ l_5223) && g_5512) == 0UL) > 0xCEL)) < 0x217F7CF0L))) >= l_5122), 0L)) >= 0xB793C0CBL)), g_3109[1])))) == 0xBAL))) <= 0xECL), 5)) >= g_3935[3][2]), l_5763)) , 5L), g_506)), g_2853[1][7][2])) >= g_2580[0][2])) >= l_5763))) > l_5763) , g_3935[3][2]) ^ 0x7010L))), g_5512)) < 1L);
                        return g_5512;
                    }
                }
                else
                {
                    g_3935[6][0] = ((246UL && (+(g_573 ^ ((j = (g_5512 != (((0xD2D6L < (g_335 > 0x36L)) < ((((safe_sub_func_int16_t_s_s(((l_4665 = l_5181) ^ g_496[2]), ((l_4663[0][3][4] = 0x3C4DL) <= 0x500EL))) > 0xE9L) && l_5223) || l_5542)) <= 0xB4B8L))) < 0xD2L)))) < g_5512);
                    return g_5446[0];
                };


                    for (i = 0; i < 1; i++)
                    l_5728[i] = 0x2FECE2D3L;

for (l_4917 = (-22); (l_4917 > 14); l_4917 = safe_add_func_uint8_t_u_u(l_4917, 4))
            {
                g_1370[2] = g_3486;
                return g_240;
            };


                    for (l_4634 = 9; (l_4634 > 24); l_4634++)
                {
                    int16_t l_5614 = 0x9D0FL;
                    int32_t l_5625 = (-2L);
                    int16_t l_5727 = 0xE03EL;


                }

                l_5728[0] = (safe_mod_func_int32_t_s_s(((g_4423[1] = 255UL) != (p_17 <= ((safe_mod_func_int16_t_s_s((safe_add_func_int32_t_s_s((p_16 , (g_1370[1] = (((((((((safe_rshift_func_uint16_t_u_u((safe_add_func_int32_t_s_s((safe_rshift_func_int8_t_s_s(g_3486, 6)), p_16)), (safe_rshift_func_uint8_t_u_s((((safe_rshift_func_int16_t_s_u((((p_16 != 0UL) <= (((g_1345 > (safe_rshift_func_uint16_t_u_u((safe_div_func_int32_t_s_s((safe_rshift_func_int8_t_s_s((safe_add_func_uint16_t_u_u(l_5181, 0xEEE0L)), 6)), l_5358)), l_4635))) != l_4663[0][3][4]) < g_2440)) >= g_1798[8][6]), g_9)) > g_3172) , p_16), l_5309)))) >= l_5749[1][4][1]) < l_4665) ^ 249UL) >= l_5223) || g_5210[0]) & 8L) && l_5122) != l_5421))), 0x0D1E55A5L)), 0x6461L)) == g_1138))), 0x7276E9ACL));
            }
            else
            {

if (l_5763) printf("index = [%d]\n", l_4585);

                    for (g_1345 = 0; (g_1345 < 11); g_1345 = safe_add_func_uint32_t_u_u(g_1345, 3))
                {

{
lbl_3126:
            j = (g_3463 < ((safe_rshift_func_int16_t_s_u((-7L), 12)) ^ l_5358));
            return g_3463;
        }

                    ;
                }
            }
            l_5834[1][1] = ((safe_lshift_func_int16_t_s_u(l_5511, ((((l_5514 = (65533UL < 0x3B57L)) == (((safe_mod_func_int32_t_s_s((l_5554 = (l_5822 = p_16)), 0x239B190CL)) | ((((p_16 == (((safe_div_func_uint16_t_u_u(((((safe_lshift_func_int16_t_s_u((safe_div_func_uint32_t_u_u(0x9C949002L, (((safe_mod_func_uint8_t_u_u((safe_add_func_int8_t_s_s(((p_16 != g_5446[3]) && p_16), l_5262)), g_3109[1])) , p_17) || 0x302513DCL))), 13)) , p_17) < p_16) ^ g_204), g_1684[0])) || l_4583) , l_5833)) != 0x53L) && l_5262) , g_3600)) || 1L)) >= p_16) < 4294967295UL))) , 3L);
        }
    }
    return p_17;
}







inline static int16_t func_18(int32_t p_19, uint32_t p_20, const uint16_t p_21)
{
    const uint8_t l_4531 = 0x25L;
    g_2580[0][7] = ((((l_4531 < (((((safe_lshift_func_int16_t_s_u(((safe_add_func_int32_t_s_s((((safe_rshift_func_int8_t_s_s(g_496[2], 3)) >= 0x219F7F5FL) >= (g_2422 = ((((65532UL < (((safe_lshift_func_int8_t_s_s(p_19, ((safe_mul_func_uint8_t_u_u(l_4531, (((0x2DL & (safe_lshift_func_uint8_t_u_s(255UL, 6))) , ((p_20 == p_19) && (-3L))) == 254UL))) > l_4531))) >= p_21) >= 0L)) || p_21) < p_21) && l_4531))), l_4531)) | 1L), l_4531)) < l_4531) != l_4531) && g_3317) != l_4531)) != g_184) >= p_19) < p_20);
                                        while ((g_3317 > l_4531) )
{

{

for (g_573 = 0; g_573 < 1; g_573++)
            g_34[g_573] = 0x22L;

        g_3486 = (9UL >= g_9);
                }

}
        return p_21;
}







inline static uint32_t func_28(uint32_t p_29, int32_t p_30, int32_t p_31, const uint16_t p_32)
{
    uint16_t l_45 = 0x074FL;
    int32_t l_46 = 1L;
    int32_t l_4528 = 0xD2BBE338L;
    g_34[0] = 0xD77CCCAEL;
    g_35 = (-1L);
    l_4528 = (((+(g_35 & (p_31 = g_35))) >= func_37(func_43((l_45 != (l_46 = g_34[0]))), (g_1798[6][5] , g_1798[5][2]), ((safe_div_func_int16_t_s_s((((p_30 < (safe_add_func_int16_t_s_s(0x82FEL, p_30))) != 0x76F37551L) , l_4528), 0x6DD7L)) || g_3486), g_1798[5][2], g_496[2])) < g_9);
    return g_3486;
}







static uint8_t func_37(uint16_t p_38, int32_t p_39, int32_t p_40, int8_t p_41, const int8_t p_42)
{
    uint32_t l_4529 = 3UL;
    int32_t l_4530 = 0x06E3BB14L;
                                                                            if (((l_4530>115587860) || (l_4529>3U)) )
{

{
                        int16_t l_905 = 0L;
                        l_905 = (g_2440 = g_1368);
                    }

}
      while ((l_4530 < l_4529) )
{

for (l_4530 = 0; l_4530 < 9; l_4530++)
    {
        for (g_204 = 0; g_204 < 8; g_204++)
        {
            transparent_crc(g_1798[l_4530][g_204], "g_1798[l_4530][g_204]", g_506);
            if (g_506) {
if (g_275) printf("index = [%d]\n", l_4530);

      printf("index = [%d][%d]\n", l_4530, g_204);}

        }
    };


}
      l_4530 = (l_4529 = g_34[0]);
    return g_1288;
}







inline static uint16_t func_43(int32_t p_44)
{
    int32_t l_3204[2];
    int32_t l_3209 = 0x374484A8L;
    int8_t l_3212[6];
    int32_t l_3230[1];
    int32_t l_3277 = (-1L);
    int16_t l_3278 = 0xB713L;
    int32_t l_3464 = (-8L);
    uint8_t l_3607 = 0xE2L;
    uint16_t l_3794 = 0x4C41L;
    uint32_t l_3803[1][4] = {{0x5B7E570BL,0x5B7E570BL,0x5B7E570BL,0x5B7E570BL}};
    uint32_t l_3887 = 4294967292UL;
    int16_t l_4044 = 0xA478L;
    uint32_t l_4090 = 0x5D8E2B98L;
    uint32_t l_4232 = 0xE31D4304L;
    int32_t l_4272 = 0xC3DE9FD2L;
    int32_t l_4273 = 0L;
    int8_t l_4321 = 0L;
    int32_t l_4476 = 0xC33FFF76L;
    int32_t l_4489[10][1] = {{0xFEB7A305L},{4L},{0xFEB7A305L},{0xFEB7A305L},{4L},{0xFEB7A305L},{0xFEB7A305L},{4L},{0xFEB7A305L},{0xFEB7A305L}};
    int i, j;
                                        if ((g_335>17224) )
{

;


}
                    for (i = 0; i < 2; i++)
        { while ((l_3607>226) )
{

{
                    uint8_t l_5432 = 5UL;
                    if (l_5432)
                        break;
                }

}
                    l_3204[i] = 0x3FE78DE6L;}
    for (i = 0; i < 6; i++)
        { if ((!g_2467) )
{

for (l_3277 = 0; l_3277 < 1; l_3277++)
            g_34[l_3277] = 0x22L;

}
                    if (!((g_1288 > g_3172)) )
{

{

{
                        int8_t l_4920 = 0xD6L;
                        g_2580[0][7] = (((l_4476 & (safe_unary_minus_func_int32_t_s(g_1138))) > (0L != l_3209)) && g_3193);
                        g_184 = l_4920;
                    }

                    return l_3204[1];
            }

}
                    l_3212[i] = 0x7CL;}
    for (i = 0; i < 1; i++)
        { uint8_t BJCJCgg_472 = (~((((~(((l_3794 ^ g_240) | (~(g_472))))) - (~((~((~(l_3278))))))) ^ ((~(((~(g_982)) / (~(g_1368))))) & (l_4272 - ((g_3486 >> g_759) & g_1352))))));
uint32_t BJCJChg_759 = (~(((~((g_1352 ^ ((~(l_3278)) & (g_982 ^ l_3794))))) / ((g_759 & (g_3486 | (g_1368 | l_4272))) ^ ((~((~((~(g_472)))))) / (g_240 ^ BJCJCgg_472))))));
uint32_t BJCJCig_982 = (~(((((l_4272 + (~((~((~(g_3486))))))) && (l_3278 ^ ((g_1368 & (g_472 + g_240)) + g_759))) << (~((~(g_982))))) | ((~((BJCJCgg_472 ^ (BJCJChg_759 - l_3794)))) >> (~(g_1352))))));
int32_t BJCJCjg_240 = (~(((~(((~((l_3794 / g_1352))) - ((~(BJCJCgg_472)) ^ (~((~((~((~((g_472 ^ g_3486))))))))))))) && ((~((~(g_759)))) ^ ((~((((l_4272 & BJCJChg_759) ^ (l_3278 | (~(g_1368)))) & BJCJCig_982))) / (g_240 | (~(g_982))))))));
int32_t BJCJCkl_4272 = (~(((((~(((~(((~(g_1352)) && l_3794))) - ((BJCJChg_759 | l_3278) && g_3486)))) | ((~((~(BJCJCjg_240)))) ^ (~((l_4272 / (g_759 - g_1368)))))) + ((~((BJCJCig_982 & g_982))) ^ (BJCJCgg_472 - g_240))) | (~((~(g_472)))))));
int16_t BJCJCll_3278 = (~(((~((~((~((~((((~((g_240 | (~(BJCJCgg_472))))) && (l_3794 - g_3486)) && ((~(BJCJCjg_240)) + (l_4272 | (~(l_3278))))))))))))) & (((~((g_759 & g_1368))) & ((g_472 - (~(BJCJChg_759))) ^ BJCJCig_982)) | (~(((~((~((BJCJCkl_4272 | g_982))))) && g_1352)))))));
if(((g_240<=36506539) || !((l_4272 < g_3486)))){
BJCJCgg_472 = g_472;
BJCJChg_759 = g_759;
BJCJCig_982 = g_982;
LABEL_JCJCm: BJCJCjg_240 = g_240;
BJCJCkl_4272 = l_4272;
BJCJCll_3278 = l_3278;
g_472 = (~(((BJCJCgg_472 && l_3794) | (((~(((~((BJCJCig_982 ^ BJCJCll_3278))) && (~((((l_3278 && (~(g_759))) + (BJCJCjg_240 ^ g_472)) ^ (~(BJCJCkl_4272)))))))) + (~((g_1368 ^ (~(BJCJChg_759)))))) ^ (~(((g_1352 && (~((l_4272 & ((~(g_240)) + g_982))))) - g_3486)))))));
g_759 = (~(((~((~(((((~((BJCJCgg_472 | (~((~(l_3278))))))) && g_1352) + BJCJCjg_240) - (~((~((BJCJChg_759 - g_472)))))))))) + ((((g_3486 >> g_982) << BJCJCig_982) | ((g_759 + g_1368) && (~(BJCJCkl_4272)))) >> (~((~(((~((l_4272 & g_240))) && ((~(l_3794)) ^ BJCJCll_3278))))))))));
g_982 = (~((((~((~(((~((g_240 | (~(l_3278))))) && g_1352))))) - (~((((BJCJCjg_240 + (BJCJCkl_4272 ^ BJCJChg_759)) + (((~(l_4272)) + g_982) - (~((g_3486 / BJCJCig_982))))) && g_759)))) / ((~(l_3794)) / (((~(g_472)) + (BJCJCgg_472 & (~(g_1368)))) ^ (~((~(BJCJCll_3278)))))))));
g_240 = (~((((~(((~(g_759)) | (~((~((~(g_240))))))))) && (~(((~(BJCJCkl_4272)) & (~((l_4272 - (BJCJCjg_240 - (g_472 - BJCJCig_982))))))))) + (~((~(((BJCJCll_3278 - (~((~(((~((g_1368 / g_982))) | (~((~((l_3794 >> (~(g_1352))))))))))))) << (BJCJCgg_472 & (BJCJChg_759 && (~((g_3486 && l_3278)))))))))))));
l_4272 = (~(((((g_1352 && ((~(((~(l_3794)) - (~(g_472))))) ^ g_982)) / (BJCJCgg_472 | g_759)) + ((BJCJChg_759 + g_1368) ^ ((g_240 ^ BJCJCjg_240) & (l_3278 + BJCJCig_982)))) / ((~(BJCJCkl_4272)) ^ (~((~(((~(BJCJCll_3278)) << (l_4272 && (~(g_3486))))))))))));
l_3278 = (~(((((g_982 | g_3486) + (g_1368 / g_240)) / (~((~((~(l_3794))))))) - ((~(((g_759 && (~(BJCJCgg_472))) ^ (BJCJCll_3278 && l_3278)))) & ((~((~(((BJCJCig_982 + ((g_1352 / (BJCJCkl_4272 / BJCJChg_759)) | BJCJCjg_240)) - (~(g_472))))))) + (~(l_4272)))))));
if((((BJCJChg_759 < g_240) && (!BJCJCig_982)) && !((g_3486<0)))){
printf("g_472=%llu\n", (unsigned long long)g_472);
BJCJCgg_472 = (~((((~((~(BJCJCkl_4272)))) | ((~((~((g_472 & (BJCJChg_759 - g_982)))))) << ((~(((~(((BJCJCgg_472 + l_3278) ^ (~(BJCJCjg_240))))) ^ (~((~(g_240))))))) & (~((l_4272 / g_1352)))))) && (~((~((l_3794 - ((~(g_3486)) | ((~((g_759 && (~(BJCJCig_982))))) + (g_1368 & BJCJCll_3278)))))))))));
continue;
}
if((!BJCJCjg_240)){
printf("g_759=%llu\n", (unsigned long long)g_759);
goto LABEL_jCjCA;
}
if(((!l_3794) || (BJCJCkl_4272 > g_1352))){
printf("g_982=%llu\n", (unsigned long long)g_982);
continue;
}
if((((g_982<4294967295U) && (BJCJCjg_240 < BJCJCgg_472)) || !(BJCJCll_3278))){
printf("g_240=%lld\n", (long long)g_240);
BJCJChg_759 = (~((((BJCJCkl_4272 ^ BJCJCjg_240) ^ (~(((BJCJCll_3278 / (l_3278 && (~(g_759)))) - (~((~((~(BJCJChg_759)))))))))) && (~((((BJCJCgg_472 && g_1368) / ((~((((g_240 | l_4272) >> l_3794) + (~(BJCJCig_982))))) & (~((g_1352 & g_982))))) << (g_3486 ^ (~(g_472)))))))));
g_982 = (~(((~((~(g_472)))) | ((BJCJCgg_472 / (~(((~((l_3794 ^ (~(g_1352))))) && (~(l_3278)))))) && ((((~(g_3486)) && ((~((~((~(BJCJChg_759)))))) - (~(((g_240 << BJCJCll_3278) | (g_759 << (BJCJCig_982 && l_4272))))))) && (~((BJCJCjg_240 / g_1368)))) << (~(((~((~(BJCJCkl_4272)))) << g_982))))))));
continue;
}
if((BJCJCgg_472 > g_759)){
printf("l_4272=%lld\n", (long long)l_4272);
goto LABEL_rBrBn;
}
if((!BJCJChg_759)){
printf("l_3278=%lld\n", (long long)l_3278);
BJCJCkl_4272 = (~(((~((~(((~((BJCJCjg_240 | BJCJCgg_472))) << (~((BJCJCkl_4272 & g_1352)))))))) & (~(((((g_3486 + g_759) ^ g_982) + (~(g_240))) ^ (~(((~((((l_4272 / g_1368) / (~((BJCJCig_982 & BJCJChg_759)))) | (~(g_472))))) - (~(((BJCJCll_3278 & l_3794) >> l_3278))))))))))));
continue;
}
}
g_472 = BJCJCgg_472;
g_759 = BJCJChg_759;
g_982 = BJCJCig_982;
g_240 = BJCJCjg_240;
l_4272 = BJCJCkl_4272;
l_3278 = BJCJCll_3278;

                    l_3230[i] = 1L;}
                               int16_t BJBJBog_335 = (~(((~((~(g_335)))) ^ (~((~((((((~(g_76)) | g_1352) << (((l_3278 & g_1138) << g_506) / g_469)) >> (~((~((g_759 / (~(g_2467)))))))) ^ (~(l_3794))))))))));
uint32_t BJBJBpg_759 = (~(((~((~(((g_506 >> (((g_76 % g_1352) || l_3794) || BJBJBog_335)) & (~(((~((g_335 | (~(((~(l_3278)) / g_469)))))) ^ (~(g_759)))))))))) || (~(((~((~(g_1138)))) | g_2467))))));
int16_t BJBJBql_3278 = (~((((g_759 | g_2467) / ((~((BJBJBog_335 ^ g_1352))) || l_3794)) ^ (((((~(g_1138)) || (g_76 % BJBJBpg_759)) | (g_506 & l_3278)) ^ g_335) / (~(g_469))))));
int16_t BJBJBrg_1352 = (~(((((~((g_1352 | (g_1138 & g_759)))) % g_2467) || ((l_3794 & ((~(l_3278)) % BJBJBpg_759)) ^ (BJBJBql_3278 ^ (~(BJBJBog_335))))) | (g_335 ^ ((g_76 || g_506) / (~(g_469)))))));
int8_t BJBJBsg_2467 = (~((((BJBJBpg_759 / (~((g_2467 >> ((~((l_3278 % g_506))) / g_76))))) % ((~((~(((~((((~(BJBJBrg_1352)) / (BJBJBql_3278 | g_1352)) / (~(g_1138))))) / (BJBJBog_335 || l_3794)))))) | ((~(g_759)) / (~(g_335))))) / (~((~(g_469)))))));
uint32_t BJBJBtg_1138 = (~((((~((g_76 & g_469))) & (~((((~(g_335)) / (BJBJBrg_1352 & g_2467)) ^ ((~(g_506)) | ((BJBJBpg_759 & (~(g_1138))) / (~(BJBJBog_335)))))))) / (((l_3794 % g_759) % l_3278) << ((BJBJBsg_2467 | g_1352) & (~(BJBJBql_3278)))))));
if(g_1352){
BJBJBog_335 = g_335;
BJBJBpg_759 = g_759;
BJBJBql_3278 = l_3278;
BJBJBrg_1352 = g_1352;
BJBJBsg_2467 = g_2467;
BJBJBtg_1138 = g_1138;
g_335 = (~((((~((~((~((~((g_506 || g_76))))))))) & ((~(BJBJBrg_1352)) / (~((((g_469 << (BJBJBpg_759 || l_3794)) & g_335) & (~(BJBJBql_3278))))))) | (~(((~((g_2467 >> BJBJBtg_1138))) ^ ((BJBJBsg_2467 & ((~(g_1352)) << g_759)) | ((BJBJBog_335 | (~((~(l_3278))))) ^ (~(g_1138))))))))));
                                    if ((g_204>-1015637163) )
{

{
        transparent_crc(g_5446[p_44], "g_5446[p_44]", l_4273);
        if (l_4273) printf("index = [%d]\n", p_44);

    }

}
                    g_759 = (~((((~(((~(BJBJBog_335)) ^ (~(g_335))))) / (~((~((~(g_759))))))) | (((~((BJBJBrg_1352 & (BJBJBsg_2467 || g_469)))) % (g_506 >> (l_3278 % (BJBJBpg_759 || (~(BJBJBql_3278)))))) ^ (((~(((~(l_3794)) & (BJBJBtg_1138 ^ g_76)))) % (~((g_2467 << g_1138)))) & (~(g_1352)))))));
l_3278 = (~(((~((~(((~((~((~((l_3794 << (~(g_759))))))))) / (~(((((BJBJBpg_759 || (l_3278 & BJBJBog_335)) || BJBJBsg_2467) ^ (~(g_335))) | (~((g_76 ^ BJBJBrg_1352))))))))))) % (~(((~((BJBJBql_3278 || ((g_2467 >> (~(g_1352))) & (~(g_469)))))) & (~((g_1138 << (g_506 >> BJBJBtg_1138))))))))));
g_1352 = (~((((~((~((~(BJBJBql_3278)))))) ^ (~((~(g_76))))) | (~(((~(((~((~(l_3278)))) || (((g_1352 % BJBJBog_335) || (g_506 % BJBJBrg_1352)) | ((g_335 % g_759) || (g_2467 & ((g_1138 & (BJBJBpg_759 / (g_469 ^ BJBJBsg_2467))) % l_3794))))))) / (~(BJBJBtg_1138))))))));
g_2467 = (~(((~(((g_1138 & (~((~(((~(g_1352)) ^ (g_469 || g_2467))))))) || (~((~((g_506 / (~(BJBJBql_3278)))))))))) % ((~(((~(l_3794)) / (~((~((~(BJBJBsg_2467))))))))) % ((~((g_76 ^ (~((BJBJBrg_1352 | BJBJBtg_1138)))))) & ((~((BJBJBog_335 & BJBJBpg_759))) ^ (((~(g_759)) || l_3278) & (~(g_335)))))))));
g_1138 = (~((((BJBJBog_335 & (~(((~((~(l_3278)))) ^ (((~(g_469)) >> g_1352) | (~((~((~((g_76 / (g_335 ^ g_506))))))))))))) % (~((~((~((g_759 / BJBJBql_3278)))))))) || (((~(g_2467)) & (~(BJBJBsg_2467))) ^ ((BJBJBpg_759 & (~(g_1138))) % ((~(BJBJBrg_1352)) ^ (BJBJBtg_1138 | l_3794)))))));
                                   if (l_3887)
                    if(((g_2467 < BJBJBpg_759) || (BJBJBog_335 < l_3278))){
printf("g_335=%lld\n", (long long)g_335);
goto lbl_4478;
}
                               int8_t BjCjCug_3172 = (~((((-(((((~(l_4273)) ^ g_4475) + g_3463) * (g_3600 ^ g_897)))) + (~((g_87 >> (~(l_3278)))))) | (g_2043 * (g_573 * g_3172)))));
uint8_t BjCjCvg_4475 = (-(((g_3600 ^ (g_3172 && (l_3278 | l_4273))) && (((g_573 + ((-(g_2043)) ^ g_4475)) ^ (-((~((g_897 & BjCjCug_3172)))))) && (~((g_87 && g_3463)))))));
int8_t BjCjCwg_3600 = (-(((~((~(((~(g_3463)) & g_4475))))) & ((((~(g_573)) | (-((BjCjCvg_4475 * (-((~(g_3172)))))))) * (l_3278 * g_897)) & (~((-(((BjCjCug_3172 * g_3600) + (l_4273 + (g_2043 + (-(g_87)))))))))))));
int16_t BjCjCxg_897 = (~((((~((-((g_897 << g_2043))))) * ((((~(((-(l_4273)) + (g_3600 * g_3172)))) * (BjCjCwg_3600 | BjCjCug_3172)) & BjCjCvg_4475) << g_87)) ^ ((-((-(((~((-(l_3278)))) | g_3463))))) + (g_4475 << g_573)))));
uint32_t BjCjCyg_3463 = (-((((l_3278 && (~((-((~((~((~((g_4475 | ((l_4273 && g_573) | (~(BjCjCug_3172))))))))))))))) * (g_3172 ^ (BjCjCwg_3600 * g_3463))) << ((g_3600 + (~(g_2043))) && ((~((~(BjCjCxg_897)))) * ((g_897 >> g_87) * BjCjCvg_4475))))));
int32_t BjCjCzl_4273 = (~(((((-(g_3463)) * (g_897 ^ g_4475)) | l_3278) && (~(((-((((g_2043 + (-(g_573))) * BjCjCwg_3600) & BjCjCvg_4475))) * (~((~(((BjCjCxg_897 ^ l_4273) ^ (~(((g_3172 && g_87) & ((g_3600 + BjCjCug_3172) * BjCjCyg_3463)))))))))))))));
if((BjCjCug_3172 || (g_3172>-63))){
BjCjCug_3172 = g_3172;
BjCjCvg_4475 = g_4475;
BjCjCwg_3600 = g_3600;
                               int32_t BJCJCng_2440 = (~((((~((~(g_3600)))) && ((~(g_184)) / ((~(g_2440)) ^ ((g_2043 + g_3193) - g_3486)))) & ((l_3209 ^ g_982) / (~((g_1599 & g_4475)))))));
uint8_t BJCJCog_4475 = (~(((~((~(((~((~(g_982)))) - (~(((g_3486 & (g_2043 ^ g_4475)) ^ (BJCJCng_2440 && g_1599))))))))) / (((~(((~((~(l_3209)))) ^ g_184))) ^ (g_2440 | g_3193)) & g_3600))));
uint32_t BJCJCpg_184 = (~(((((~((~((g_4475 - g_2043))))) + (g_3193 ^ g_1599)) & ((g_982 ^ g_3486) >> (BJCJCng_2440 && ((~(l_3209)) | (BJCJCog_4475 && g_3600))))) | ((~(g_2440)) / g_184))));
int32_t BJCJCqg_2043 = (~((((~(((~((~(g_2440)))) | (BJCJCog_4475 >> g_2043)))) ^ (~(((~((g_184 ^ l_3209))) << (((g_4475 | g_1599) ^ g_3486) & (~(BJCJCng_2440))))))) ^ ((~(((~((g_3193 & g_3600))) - g_982))) && (~(BJCJCpg_184))))));
uint32_t BJCJCrg_982 = (~(((((((~(BJCJCpg_184)) >> g_3193) ^ BJCJCqg_2043) & g_3600) && ((~(BJCJCog_4475)) / (g_2440 | BJCJCng_2440))) && (((~(g_1599)) - ((g_982 - l_3209) && ((g_2043 - g_184) / g_4475))) && g_3486))));
int32_t BJCJCsg_3486 = (~(((~(((~(((~((g_4475 | g_2440))) ^ ((g_2043 & l_3209) / g_184)))) && (g_982 | (~(BJCJCog_4475)))))) & ((~(g_3193)) ^ (((~((~(BJCJCqg_2043)))) + (~((~(g_3486))))) ^ (((g_3600 ^ BJCJCng_2440) + (BJCJCpg_184 & BJCJCrg_982)) - (~((~((~(g_1599))))))))))));
if(!((BJCJCng_2440>-1))){
BJCJCng_2440 = g_2440;
BJCJCog_4475 = g_4475;
BJCJCpg_184 = g_184;
BJCJCqg_2043 = g_2043;
BJCJCrg_982 = g_982;
BJCJCsg_3486 = g_3486;
g_2440 = (~(((~((~(((~(g_184)) && (~(((~(((g_3486 ^ (~((~(BJCJCrg_982))))) / ((~((((~(BJCJCng_2440)) | g_1599) && g_2440))) ^ (~((BJCJCog_4475 | g_3600))))))) & ((g_982 - BJCJCpg_184) ^ (~((~((~((g_3193 << g_2043)))))))))))))))) >> (~((~(((g_4475 && (BJCJCsg_3486 / l_3209)) << BJCJCqg_2043))))))));
g_4475 = (~(((~(((~((~((g_3600 & ((~((g_3193 << g_982))) - (~((~(g_3486)))))))))) + ((~((BJCJCog_4475 / g_1599))) ^ BJCJCpg_184)))) ^ (~((~(((((g_184 && g_4475) && (BJCJCrg_982 | (~(((~((g_2440 && l_3209))) & g_2043))))) / (BJCJCqg_2043 - BJCJCsg_3486)) / (~(BJCJCng_2440))))))))));
g_184 = (~(((((~(((~(((~(BJCJCqg_2043)) + (~(BJCJCpg_184))))) - ((g_2043 / g_2440) && (g_982 - BJCJCng_2440))))) - (~(g_1599))) ^ (BJCJCog_4475 ^ (~((BJCJCrg_982 + (g_3193 | g_3600)))))) / (~((~(((~(g_4475)) && ((~((~((((~(l_3209)) - g_184) ^ (~(BJCJCsg_3486))))))) | (~((~(g_3486)))))))))))));
g_2043 = (~(((~((~((g_1599 / g_2043))))) & (~((((g_982 & ((~(BJCJCqg_2043)) - (BJCJCsg_3486 ^ ((g_3486 / g_184) - ((~(l_3209)) ^ BJCJCrg_982))))) - ((g_4475 & BJCJCng_2440) | (BJCJCog_4475 ^ (BJCJCpg_184 | g_2440)))) && (g_3193 | g_3600)))))));
g_982 = (~(((((BJCJCng_2440 - (BJCJCsg_3486 && g_982)) & (((~((BJCJCrg_982 / ((~(g_3600)) + g_4475)))) / BJCJCog_4475) ^ (~(l_3209)))) ^ (~((~((~(g_2043))))))) + (~((~((g_3193 && ((BJCJCqg_2043 & (g_2440 / (~(BJCJCpg_184)))) & ((~((g_184 >> g_3486))) | (~(g_1599))))))))))));
g_3486 = (~((((((~(g_184)) >> BJCJCrg_982) && ((~(g_3600)) / BJCJCpg_184)) + ((((g_3193 + g_2440) && (g_1599 | (l_3209 | (g_3486 & BJCJCog_4475)))) << BJCJCqg_2043) | ((~(g_982)) >> (g_2043 / BJCJCng_2440)))) ^ (~((BJCJCsg_3486 | g_4475))))));
if((!g_4475)){
printf("g_2440=%lld\n", (long long)g_2440);
goto lbl_4478;
}
LABEL_JCJCt: if(((g_2043>=-18843) && !(g_4475))){
printf("g_4475=%llu\n", (unsigned long long)g_4475);
goto LABEL_JCJCt;
}
if(((BJCJCsg_3486 > g_184) || (!g_2043))){
printf("g_184=%llu\n", (unsigned long long)g_184);
g_2440 = (~(((~((((~(g_2440)) >> (g_3193 - ((~((BJCJCpg_184 - BJCJCsg_3486))) / g_3600))) / ((~((BJCJCqg_2043 + l_3209))) + (g_3486 | (BJCJCng_2440 >> g_2043)))))) && (((g_184 | (~((~((~((~(g_982))))))))) + BJCJCrg_982) >> (~((((~((~(g_1599)))) + (~((~(BJCJCog_4475))))) & (~((~(g_4475)))))))))));
goto lbl_3126;
}
if((g_3486 < BJCJCqg_2043)){
printf("g_2043=%lld\n", (long long)g_2043);
goto lbl_3967;
}
if(!(((BJCJCog_4475 < g_184) && (BJCJCrg_982 < g_4475)))){
printf("g_982=%llu\n", (unsigned long long)g_982);
goto LABEL_rBrBn;
}
if((((BJCJCrg_982 < g_3193) || (!BJCJCng_2440)) && ((BJCJCrg_982<=9U) && (!BJCJCog_4475)))){
printf("g_3486=%lld\n", (long long)g_3486);
g_982 = (~(((~(((~((((~(((g_3600 - (~(BJCJCsg_3486))) / g_982))) << g_184) ^ (BJCJCng_2440 + (~(BJCJCog_4475)))))) << (~((~(l_3209))))))) / (~((((~((((~(((g_2043 / BJCJCrg_982) - g_4475))) - g_1599) - (((~(BJCJCqg_2043)) >> BJCJCpg_184) & (~(g_3193)))))) << (~(g_3486))) ^ (~(g_2440))))))));
g_4475 = (~((((~(((~((~(g_3193)))) + (g_2440 / BJCJCpg_184)))) & (~(((~((((l_3209 >> BJCJCqg_2043) - g_1599) & (BJCJCrg_982 + BJCJCng_2440)))) >> (g_982 + BJCJCsg_3486))))) / (~(((~(((~(g_2043)) / ((~(g_184)) | (g_3486 ^ g_3600))))) & (BJCJCog_4475 << (~(g_4475)))))))));
}
}
g_2440 = BJCJCng_2440;
g_4475 = BJCJCog_4475;
g_184 = BJCJCpg_184;
g_2043 = BJCJCqg_2043;
g_982 = BJCJCrg_982;
g_3486 = BJCJCsg_3486;

                    BjCjCxg_897 = g_897;
BjCjCyg_3463 = g_3463;
BjCjCzl_4273 = l_4273;
g_3172 = (~(((~((g_897 * (~(((((~(g_87)) | (~(g_4475))) ^ g_2043) ^ (-(BjCjCxg_897)))))))) + ((-((~(((~(g_573)) + (l_3278 + (~(g_3172)))))))) && (((-(BjCjCyg_3463)) + BjCjCvg_4475) + ((-((~((~(g_3463)))))) * (((BjCjCwg_3600 * g_3600) | BjCjCug_3172) ^ (-((~((BjCjCzl_4273 ^ l_4273))))))))))));
g_4475 = (~(((~((~(BjCjCvg_4475)))) & (((g_2043 * (-(BjCjCug_3172))) ^ ((BjCjCzl_4273 * (-(((g_3172 + g_4475) + g_3600)))) && (g_87 + (BjCjCwg_3600 | l_3278)))) * ((-((-(((~(g_573)) | (~((BjCjCyg_3463 | g_897)))))))) && (~(((g_3463 | BjCjCxg_897) | (-((~(l_4273))))))))))));
g_3600 = (-((((-((~((g_3600 + BjCjCwg_3600))))) & BjCjCyg_3463) && (~(((-(((-((l_3278 ^ l_4273))) | (~(((~(((~((BjCjCug_3172 | BjCjCxg_897))) << ((g_897 & BjCjCzl_4273) && (~(g_3172)))))) * g_3463)))))) && ((((~(BjCjCvg_4475)) && g_2043) << g_87) ^ (~((g_573 ^ g_4475))))))))));
g_897 = (-(((BjCjCug_3172 * (~((g_4475 << g_2043)))) | (((g_87 ^ (BjCjCyg_3463 & g_573)) | (~((BjCjCwg_3600 * (((~(g_3600)) + ((BjCjCzl_4273 | (~((g_3463 & (-(BjCjCxg_897)))))) * (~(l_4273)))) + (~((l_3278 ^ BjCjCvg_4475)))))))) | (-((g_897 && g_3172)))))));
g_3463 = (-((((BjCjCvg_4475 << (l_4273 * ((g_897 | BjCjCxg_897) & (~(BjCjCzl_4273))))) * ((-(((-(((~((BjCjCug_3172 ^ (~(g_3600))))) + (l_3278 | BjCjCyg_3463)))) && (~(g_87))))) | (-((-((-((-(g_3172)))))))))) & (~((-(((~(g_4475)) + ((BjCjCwg_3600 && (g_573 ^ g_3463)) | (~(g_2043)))))))))));
l_4273 = (~(((~(((-((BjCjCwg_3600 ^ BjCjCzl_4273))) & g_897))) | (~(((~((-(BjCjCxg_897)))) && ((-(((~((~(((g_87 ^ (l_4273 ^ g_2043)) | (~((BjCjCvg_4475 ^ g_3172)))))))) | ((g_573 | (g_3600 * g_3463)) & (BjCjCyg_3463 | (-(l_3278))))))) | ((~(BjCjCug_3172)) ^ (~(g_4475))))))))));
if((g_87 < g_897)){
printf("g_3172=%lld\n", (long long)g_3172);
g_4475 = (~(((((~(BjCjCyg_3463)) * (BjCjCwg_3600 >> (~(g_897)))) ^ ((g_3172 >> l_3278) >> BjCjCzl_4273)) & (((~((~((BjCjCxg_897 << ((g_2043 ^ BjCjCvg_4475) << (-(g_3463)))))))) << (~(((g_573 & (-(g_3600))) << (~((~(BjCjCug_3172)))))))) ^ (-((g_87 | ((~(g_4475)) * l_4273))))))));
goto LABEL_rBrBo;
}
if((g_2043 < BjCjCug_3172)){
printf("g_4475=%llu\n", (unsigned long long)g_4475);
g_3172 = (-((((~(g_3172)) << (~(l_4273))) & ((-(BjCjCwg_3600)) >> (((-((((BjCjCzl_4273 >> (~(BjCjCyg_3463))) >> g_3600) + (~(g_87))))) ^ ((((-((BjCjCxg_897 * g_573))) & l_3278) * (g_4475 * (~(g_897)))) >> g_2043)) + (-((~(((BjCjCvg_4475 && BjCjCug_3172) | (-(g_3463))))))))))));
goto lbl_3967;
}
if(!((BjCjCxg_897 > g_897))){
printf("g_3600=%lld\n", (long long)g_3600);
goto LABEL_rBrBo;
}
                                    while (!((g_2440 < l_4232)) )
{

for (g_275 = 0; g_275 < 2; g_275++)
                l_3204[g_275] = 1L;

}
                    if((g_897<1)){

g_3486 -= 1;


                    printf("g_897=%lld\n", (long long)g_897);
BjCjCxg_897 = (~(((((((((g_2043 & g_4475) | BjCjCvg_4475) ^ (~(g_3172))) ^ ((-(BjCjCwg_3600)) << ((-(BjCjCyg_3463)) | g_897))) | ((~((~(l_3278)))) | g_3600)) + (-((g_573 && (BjCjCzl_4273 & g_3463))))) >> (-((BjCjCxg_897 + g_87)))) >> (~(((~(BjCjCug_3172)) && l_4273))))));
BjCjCvg_4475 = (~(((-((-((~((((~(BjCjCxg_897)) & g_3463) * (g_87 + g_2043)))))))) ^ ((-(((-((-((g_3600 >> (g_3172 >> g_897)))))) << (-((g_4475 << (-(BjCjCug_3172)))))))) >> ((~(BjCjCyg_3463)) | (((BjCjCwg_3600 << g_573) >> ((l_3278 ^ BjCjCvg_4475) << BjCjCzl_4273)) ^ l_4273))))));
goto lbl_4478;
}
if((g_3463<255U)){
printf("g_3463=%llu\n", (unsigned long long)g_3463);
goto lbl_3126;
}
LABEL_jCjCA: if(((g_2043 < g_87) && (!BjCjCxg_897))){
printf("l_4273=%lld\n", (long long)l_4273);
l_4273 = (~(((((g_87 + g_897) | ((BjCjCyg_3463 | l_3278) && BjCjCxg_897)) ^ (((~(BjCjCvg_4475)) && (g_3463 + g_2043)) ^ ((~(g_4475)) >> (g_573 << (~(l_4273)))))) & (-((~((((~(BjCjCwg_3600)) && (~(g_3600))) + (~((~(((-(g_3172)) + (BjCjCug_3172 + BjCjCzl_4273))))))))))))));
g_3463 = (~((((((g_3172 * ((l_3278 << BjCjCwg_3600) | BjCjCxg_897)) & (~(g_4475))) | ((~((~(BjCjCzl_4273)))) | (((~(BjCjCug_3172)) * BjCjCvg_4475) + (l_4273 ^ BjCjCyg_3463)))) << (g_2043 * ((g_573 | (g_87 && (-(g_897)))) * g_3463))) << g_3600)));
goto LABEL_rBrBo;
}
}
g_3172 = BjCjCug_3172;
g_4475 = BjCjCvg_4475;
g_3600 = BjCjCwg_3600;
g_897 = BjCjCxg_897;
g_3463 = BjCjCyg_3463;
l_4273 = BjCjCzl_4273;

                    if((!g_759)){
;
g_1138 = (~(((((((~(g_1138)) | ((~(BJBJBql_3278)) << BJBJBtg_1138)) & ((((~(l_3794)) ^ BJBJBrg_1352) | g_76) || (~((~(BJBJBsg_2467)))))) >> ((~((~(g_759)))) >> (BJBJBog_335 << ((~((~((~(l_3278)))))) << ((g_2467 & g_335) & g_506))))) ^ (~(BJBJBpg_759))) & ((~((~(g_469)))) << g_1352))));
goto lbl_3517;
}
if((!BJBJBpg_759)){
;
goto lbl_3688;
}
if((g_759>4294967286U)){
;
g_1138 = (~(((~(((((~(l_3278)) << (~((~((((g_335 % (BJBJBrg_1352 % g_1352)) >> BJBJBtg_1138) << g_76)))))) >> (~((BJBJBog_335 / g_1138)))) || (~((~(g_469))))))) ^ ((~((~((~((g_506 & l_3794))))))) ^ (~(((~((~(g_2467)))) || ((BJBJBql_3278 << g_759) >> (BJBJBsg_2467 >> BJBJBpg_759)))))))));
goto lbl_3517;
}
if((g_759<4294967286U)){
;
goto LABEL_rBrBn;
}
if(!(((g_2467 > BJBJBtg_1138) || g_469))){
printf("g_1138=%llu\n", (unsigned long long)g_1138);
;

{
            transparent_crc(g_98[g_204][i], "g_98[g_204][i]", g_573);
            if (g_573) printf("index = [%d][%d]\n", g_204, i);

        }

                    goto lbl_3967;
}
}
g_335 = BJBJBog_335;
g_759 = BJBJBpg_759;
l_3278 = BJBJBql_3278;
g_1352 = BJBJBrg_1352;
g_2467 = BJBJBsg_2467;
g_1138 = BJBJBtg_1138;

                    lbl_3688:
    g_1370[2] = ((g_34[0] ^ (safe_rshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(func_51(p_44), (0x71021F5EL != 4294967294UL))) >= 0L), 2))) & (g_1798[3][3] | (((((safe_sub_func_uint16_t_u_u((safe_div_func_int32_t_s_s((((l_3204[1] < ((safe_sub_func_uint8_t_u_u((safe_add_func_uint16_t_u_u(0x4199L, g_9)), 0x79L)) ^ g_35)) != g_573) , 3L), p_44)), 1UL)) | l_3209) >= l_3209) || l_3209) <= p_44)));
                               int16_t BfBfBg_1352 = (~(((~(g_1352)) ^ (g_1288 & (((~((~(g_4475)))) % (~((g_1368 + (~(g_573)))))) % ((~(l_4321)) ^ ((g_2852 && (g_2043 * g_68)) + g_184)))))));
uint8_t BfBfBbg_4475 = (~(((~((((~(l_4321)) && ((~(g_68)) + (~(g_184)))) * (g_4475 + ((~((~(((g_2043 * g_1288) ^ g_2852))))) * (g_573 & (g_1368 % g_1352))))))) + (~(BfBfBg_1352)))));
int32_t BfBfBcg_573 = (~((((~(((BfBfBbg_4475 % g_68) % ((~(g_2043)) % g_2852)))) * (((l_4321 % g_1352) % ((BfBfBg_1352 & g_1288) * g_4475)) % (~(g_573)))) & (~((~((~(((~(g_1368)) | g_184))))))))));
int16_t BfBfBdg_1288 = (~((((((~(g_4475)) * (g_1288 >> g_184)) && (~((~(g_573))))) * (((l_4321 + g_2852) && g_1352) * ((~((((~(g_68)) | BfBfBcg_573) + (~((~(BfBfBg_1352))))))) ^ g_1368))) ^ (~((~(((~(BfBfBbg_4475)) % (~(g_2043))))))))));
int32_t BfBfBeg_2043 = (~(((~((~((((~(l_4321)) | (((~(g_4475)) & ((~(BfBfBdg_1288)) * g_1368)) && (~((g_2852 * BfBfBcg_573))))) & (((((~((~(g_1352)))) ^ ((~(g_2043)) * (g_573 | g_1288))) * g_68) ^ BfBfBbg_4475) & (~((~(g_184)))))))))) + BfBfBg_1352)));
uint32_t BfBfBfg_184 = (~(((~(((~((BfBfBg_1352 && (~(BfBfBdg_1288))))) + (~((~(((g_1352 & l_4321) ^ (g_573 ^ g_2852))))))))) % (((BfBfBcg_573 + (~(g_4475))) ^ (((g_184 ^ g_68) << g_2043) + (g_1288 ^ BfBfBbg_4475))) + (~((g_1368 ^ (~((~(BfBfBeg_2043)))))))))));
if(g_573){
                                    while ((g_3172>-63) )
{

{
                        int16_t l_905 = 0L;
                        l_905 = (l_3277 = g_68);
                    }

}
                    BfBfBg_1352 = g_1352;
BfBfBbg_4475 = g_4475;
                                    while ((g_76 < g_1369) )
{

{
                    uint8_t l_2034 = 0x2AL;

{
                        return g_1345;
                    }


{
        for (BfBfBeg_2043 = 0; BfBfBeg_2043 < 10; BfBfBeg_2043++)
        {
            transparent_crc(g_2580[g_275][BfBfBeg_2043], "g_2580[g_275][BfBfBeg_2043]", g_3486);
            if (g_3486) printf("index = [%d][%d]\n", g_275, BfBfBeg_2043);

        }
    }

                    g_1370[2] = (g_506 >= (((safe_add_func_int16_t_s_s(((((safe_add_func_uint32_t_u_u((g_573 = (((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u((g_506 || ((g_240 = 0xD31DC9A5L) > (safe_sub_func_int8_t_s_s(g_982, ((g_3172 < g_1288) , (((((l_4090 || (((safe_rshift_func_uint16_t_u_u((safe_div_func_int16_t_s_s((i = 0L), 0x5E9EL)), 0)) || l_4090) >= g_6029)) & l_2034) & l_4090) != 0xDA33A5C5L) < g_76)))))), l_4090)) > l_2034), 0x314EL)) & 0x578DD792L) > 0x16L)), l_2034)) >= 0x2CA5L) || g_496[1]) , 8L), l_4232)) > 0x6F16L) > l_4090));

{
        int16_t l_4164 = 0x2935L;
        int32_t l_4175 = 0xDAAB51D4L;
        int32_t l_4322 = 0x53B54A20L;
        uint32_t l_4358 = 1UL;
        int32_t l_4384 = 0xDD851F01L;
        uint16_t l_4453 = 0UL;
        for (p_44 = (-14); (p_44 < 9); p_44 = safe_add_func_int32_t_s_s(p_44, 7))
        {
            int8_t l_4176 = 1L;
            int32_t l_4217 = 0L;
            int32_t l_4292[6][10][4] = {{{1L,(-3L),1L,0xBA00F2ACL},{0L,0xD6C874E7L,0L,0L},{0x8F2748BFL,0xBA00F2ACL,0L,0xD6C874E7L},{0xBA00F2ACL,(-3L),0L,0L},{0x8F2748BFL,0x8F2748BFL,0L,0L},{0L,(-10L),1L,0xD6C874E7L},{1L,0xD6C874E7L,0xBA00F2ACL,1L},{0x8F2748BFL,0xD6C874E7L,0x7948E1FDL,0xD6C874E7L},{0xD6C874E7L,(-10L),0L,0L},{0xD1747684L,0x8F2748BFL,0xBA00F2ACL,0L}},{{0L,(-3L),(-10L),0xD6C874E7L},{0L,0xBA00F2ACL,0xBA00F2ACL,0L},{0xD1747684L,0xD6C874E7L,0L,0xBA00F2ACL},{0xD6C874E7L,(-3L),0x7948E1FDL,0L},{0xBA00F2ACL,0L,(-10L),(-10L)},{0x7948E1FDL,0xD1747684L,0x7948E1FDL,(-10L)},{0L,1L,0L,0L},{0xBA00F2ACL,(-10L),0xAFB907FFL,1L},{(-10L),0xD1747684L,0xAFB907FFL,0xAFB907FFL},{0xBA00F2ACL,0xBA00F2ACL,0L,(-10L)}},{{0L,0L,0x7948E1FDL,1L},{0x7948E1FDL,1L,(-10L),0x7948E1FDL},{0xBA00F2ACL,1L,(-3L),1L},{1L,0L,0xAFB907FFL,(-10L)},{0L,0xBA00F2ACL,(-10L),0xAFB907FFL},{0L,0xD1747684L,0L,1L},{0L,(-10L),(-10L),0L},{0L,1L,0xAFB907FFL,(-10L)},{1L,0xD1747684L,(-3L),(-10L)},{0xBA00F2ACL,0L,(-10L),(-10L)}},{{0x7948E1FDL,0xD1747684L,0x7948E1FDL,(-10L)},{0L,1L,0L,0L},{0xBA00F2ACL,(-10L),0xAFB907FFL,1L},{(-10L),0xD1747684L,0xAFB907FFL,0xAFB907FFL},{0xBA00F2ACL,0xBA00F2ACL,0L,(-10L)},{0L,0L,0x7948E1FDL,1L},{0x7948E1FDL,1L,(-10L),0x7948E1FDL},{0xBA00F2ACL,1L,(-3L),1L},{1L,0L,0xAFB907FFL,(-10L)},{0L,0xBA00F2ACL,(-10L),0xAFB907FFL}},{{0L,0xD1747684L,0L,1L},{0L,(-10L),(-10L),0L},{0L,1L,0xAFB907FFL,(-10L)},{1L,0xD1747684L,(-3L),(-10L)},{0xBA00F2ACL,0L,(-10L),(-10L)},{0x7948E1FDL,0xD1747684L,0x7948E1FDL,(-10L)},{0L,1L,0L,0L},{0xBA00F2ACL,(-10L),0xAFB907FFL,1L},{(-10L),0xD1747684L,0xAFB907FFL,0xAFB907FFL},{0xBA00F2ACL,0xBA00F2ACL,0L,(-10L)}},{{0L,0L,0x7948E1FDL,1L},{0x7948E1FDL,1L,(-10L),0x7948E1FDL},{0xBA00F2ACL,1L,(-3L),1L},{1L,0L,0xAFB907FFL,(-10L)},{0L,0xBA00F2ACL,(-10L),0xAFB907FFL},{0L,0xD1747684L,0L,1L},{0L,(-10L),(-10L),0L},{0L,1L,0xAFB907FFL,(-10L)},{1L,0xD1747684L,(-3L),(-10L)},{0xBA00F2ACL,0L,(-10L),(-10L)}}};
            int i, j, k;
            if (((safe_div_func_uint32_t_u_u(((safe_rshift_func_int8_t_s_u((1L | (safe_add_func_int8_t_s_s((!(safe_sub_func_uint32_t_u_u((l_4164 && ((safe_unary_minus_func_uint16_t_u(((g_352 = p_44) , (g_98[4][3] = (+(safe_add_func_int8_t_s_s((safe_div_func_uint32_t_u_u((l_4164 || ((((g_5210[0] = ((p_44 & (safe_mod_func_int16_t_s_s((l_4175 = (p_44 , (((safe_mod_func_uint8_t_u_u((g_1369 < (65528UL ^ 0UL)), l_4164)) == p_44) < l_4164))), g_352))) <= g_4689)) , l_4176) >= l_4176) , 0xD077BD4FL)), (-1L))), l_4176))))))) > l_4164)), l_4176))), 1L))), 4)) >= (-4L)), l_4164)) <= (-7L)))
            {
                int16_t l_4183 = 0xCCC9L;
                int32_t l_4216 = 0x08B7903DL;
                uint32_t l_4242 = 0xF5285B0EL;
                for (g_4689 = (-10); (g_4689 == 16); g_4689++)
                {
                    uint32_t l_4215 = 0xB7F28421L;
                    uint32_t l_4244 = 9UL;
                    int32_t l_4265 = (-9L);
                    g_3935[6][4] = (safe_sub_func_int32_t_s_s((g_2580[0][7] = ((l_4175 = g_2043) == (((safe_rshift_func_int8_t_s_s(g_3193, l_4183)) < (safe_div_func_int32_t_s_s(g_1369, (safe_rshift_func_uint16_t_u_u(g_204, (safe_sub_func_int32_t_s_s(p_44, ((((g_472 = (((safe_sub_func_uint32_t_u_u((((((BJBJBrg_1352 = 0L) , (p_44 >= (l_4164 < g_1288))) | BfBfBcg_573) != 0x9E2DBD5AL) == 0L), l_4176)) == g_3172) ^ 0UL)) >= p_44) && g_1684[0]) ^ 0x6FL)))))))) || 0x4297L))), g_87));
                    for (i = 0; (i <= 0); i += 1)
                    {
                        int i;
                        l_4217 = (((!((0x00L <= (safe_sub_func_uint32_t_u_u((g_5210[0] = g_1684[i]), (safe_mod_func_int16_t_s_s((safe_add_func_uint8_t_u_u((g_1684[0] | (safe_lshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_s(p_44, 4)), 4)), 4L)), 5))), (((safe_rshift_func_uint16_t_u_u((safe_div_func_uint8_t_u_u((0x6FL >= p_44), (l_4216 = ((safe_mod_func_uint32_t_u_u(((((safe_sub_func_int16_t_s_s((g_1684[i] ^ g_2580[0][7]), g_1368)) > p_44) ^ BfBfBbg_4475) ^ 0xF73BL), l_4215)) , g_172)))), 12)) , g_3935[3][2]) > p_44))), g_172))))) , g_204)) == p_44) || p_44);
                        return p_44;
                    }
                    if (((((safe_unary_minus_func_uint16_t_u((((l_4176 , (0x40L != l_4164)) , (g_1368 = (safe_mod_func_int8_t_s_s((l_4175 = (safe_lshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_s(1L, (~(-1L)))) , (safe_div_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s(i, 1)) , (l_4176 ^ (g_3193 >= (((g_1368 & p_44) <= g_4689) <= g_2580[3][7])))), i))), (-1L))), g_5844))), BfBfBfg_184)))) & l_4216))) <= 0xAAL) > 1L) == 0xCEB4L))
                    {
                        int16_t l_4243 = (-1L);
                        g_2853[3][2][5] = ((g_759 = ((((safe_sub_func_int32_t_s_s(0x8CE52AFEL, l_4215)) < (!(safe_sub_func_uint32_t_u_u((g_1368 , (safe_add_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(((p_44 , ((((p_44 , (g_5210[0] = l_4215)) != ((l_4242 || (l_4243 < g_3109[1])) , 0x9A66B615L)) < p_44) > l_4244)) ^ 0x96A3L), p_44)), g_1798[5][2]))), i)))) & g_1368) | g_1368)) && g_1369);
                        if (l_4175)
                            continue;
                    }
                    else
                    {

for (p_44 = 0; p_44 < 6; p_44++)
        l_3212[p_44] = 0x7CL;

                    g_5210[0] = (safe_mod_func_int16_t_s_s((0xF1303593L > ((l_4242 != ((g_154 = (g_204 = ((((0xEEL | g_1684[0]) || ((((p_44 > (safe_lshift_func_uint16_t_u_u(p_44, 1))) , (safe_mod_func_uint32_t_u_u(((-4L) != l_4244), 0x3D51BA8BL))) || 0L) < 1L)) <= BJBJBrg_1352) , l_4216))) & p_44)) ^ 0xC41FL)), p_44));
                        l_4175 = (l_4265 = ((safe_rshift_func_int8_t_s_u((g_1369 != 255UL), 6)) != ((g_1684[0] | ((((p_44 , 0UL) , (safe_lshift_func_int16_t_s_u(0xB99EL, ((safe_sub_func_uint8_t_u_u(BJBJBrg_1352, (safe_div_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(0xFD67L, (g_496[2] >= g_154))), p_44)))) >= g_3193)))) ^ 0UL) <= 0L)) >= g_1368)));
                    }

for (g_2440 = 0; g_2440 < 3; g_2440++)
                    g_1370[g_2440] = 0L;

                    if (p_44)
                        break;
                }
                l_4175 = (-1L);
                for (g_3463 = 0; (g_3463 < 1); ++g_3463)
                {
                    int16_t l_4268 = 0x35F2L;
                    l_4268 = g_1369;
                    l_4217 = (1L > ((!(safe_lshift_func_uint8_t_u_u(p_44, 6))) != i));
                }
            }
            else
            {
                int32_t l_4291[4][6][6] = {{{0x9D48C12EL,0L,0L,0x21F6396FL,0L,1L},{0xE70FB94DL,1L,(-2L),0L,0L,(-2L)},{1L,1L,1L,(-2L),5L,1L},{1L,0x9D48C12EL,1L,1L,0x69DF6F92L,1L},{0xAA603F92L,1L,1L,0xE70FB94DL,1L,1L},{(-1L),0xE70FB94DL,1L,0L,0L,(-2L)}},{{0L,0L,(-2L),1L,0x21F6396FL,0x11ED91A7L},{(-1L),0L,5L,5L,0L,(-1L)},{0L,0xE70FB94DL,1L,0x9D48C12EL,1L,1L},{5L,1L,0x21F6396FL,0xAA603F92L,0x69DF6F92L,0L},{5L,0x9D48C12EL,0xAA603F92L,0x9D48C12EL,5L,1L},{0L,1L,0x69DF6F92L,5L,0L,(-1L)}},{{(-1L),1L,0L,1L,(-1L),(-1L)},{0L,0x69DF6F92L,0x69DF6F92L,0L,0x11ED91A7L,1L},{(-1L),1L,0xAA603F92L,0xE70FB94DL,0x9D48C12EL,0L},{0xAA603F92L,(-1L),0x21F6396FL,1L,0x9D48C12EL,1L},{1L,1L,1L,(-2L),0x11ED91A7L,(-1L)},{1L,0x69DF6F92L,5L,0L,(-1L),0x11ED91A7L}},{{0xE70FB94DL,1L,(-2L),0L,0L,(-2L)},{1L,1L,1L,(-2L),5L,1L},{1L,0x9D48C12EL,1L,1L,0x69DF6F92L,1L},{0xAA603F92L,1L,1L,0xE70FB94DL,1L,1L},{(-1L),0xE70FB94DL,1L,0L,0L,(-2L)},{0L,0L,(-2L),1L,0x21F6396FL,0x11ED91A7L}}};
                int i, j, k;
                g_3935[3][2] = (safe_rshift_func_uint8_t_u_u(253UL, ((g_98[1][3] = ((((((+((safe_rshift_func_uint8_t_u_u(((safe_add_func_int8_t_s_s(g_472, ((l_4292[3][6][1] = (g_472 || ((((((0x00L != (safe_div_func_uint8_t_u_u(p_44, p_44))) <= ((((safe_rshift_func_uint16_t_u_s(((g_5844 = (safe_mod_func_uint16_t_u_u((l_4217 , ((safe_add_func_int32_t_s_s((((((safe_lshift_func_int16_t_s_s(((l_4175 = p_44) != (255UL || 0x87L)), l_4291[3][3][4])) , 0UL) <= l_4176) == l_4291[2][1][2]) , p_44), 0x93F5B890L)) && p_44)), 1L))) <= (-1L)), 10)) ^ 0UL) && l_4291[3][3][4]) ^ p_44)) && g_1288) & 0x11BCC8A6L) | l_4291[3][3][4]) , l_4175))) , l_4175))) > g_4689), l_3204[1])) == l_4291[3][3][1])) > g_3935[3][0]) > 255UL) > g_1798[5][2]) < 0x05E4L) , g_1599)) != l_4164)));
            }
        }
        i = ((+((((~(((safe_sub_func_uint32_t_u_u((safe_add_func_int16_t_s_s(((((safe_mod_func_uint8_t_u_u((p_44 = (safe_lshift_func_int16_t_s_u(g_6428, l_4175))), (safe_div_func_uint8_t_u_u(((((safe_mod_func_int8_t_s_s(((safe_rshift_func_int16_t_s_s(0xD693L, 9)) & (safe_add_func_int32_t_s_s(l_4164, (safe_div_func_uint8_t_u_u(((g_5210[0] = (l_4322 = ((safe_lshift_func_uint16_t_u_s((safe_lshift_func_uint8_t_u_s(0xBDL, ((!((!(0x2AL <= p_44)) & (safe_rshift_func_int16_t_s_s((g_2580[1][5] , ((g_496[3] || 0xAB82L) < g_154)), g_1368)))) , g_1370[0]))), p_44)) & g_4689))) ^ l_4175), g_5844))))), p_44)) > g_2043) < p_44) ^ 0x3878368DL), p_44)))) <= l_3212[4]) > 0x69AD9E7CL) != l_3204[1]), p_44)), g_1798[4][2])) || BJBJBrg_1352) <= 0x8211L)) == 0x6DL) > BJBJBpg_759) && 4294967295UL)) & 0x22C2L);
        for (BfBfBeg_2043 = 0; (BfBfBeg_2043 < (-21)); BfBfBeg_2043 = safe_sub_func_int16_t_s_s(BfBfBeg_2043, 4))
        {
            uint32_t l_4359 = 0x6CE1B8FCL;
            int32_t l_4360[7][6] = {{0x4D52E69AL,(-3L),(-3L),0x4D52E69AL,(-2L),0x4D52E69AL},{0x4D52E69AL,(-2L),0x4D52E69AL,(-3L),(-3L),0x4D52E69AL},{0x9A51126EL,0x9A51126EL,(-3L),(-1L),(-3L),0x9A51126EL},{(-3L),(-2L),(-1L),(-1L),(-2L),(-3L)},{0x9A51126EL,(-3L),(-1L),(-3L),0x9A51126EL,0x9A51126EL},{0x4D52E69AL,(-3L),(-3L),0x4D52E69AL,(-2L),0x4D52E69AL},{0x4D52E69AL,(-2L),0x4D52E69AL,(-3L),(-3L),0x4D52E69AL}};
            int8_t l_4432 = 0x9DL;
            int32_t l_4439 = 0x46340F21L;
            int32_t l_4440 = 0x308E2A13L;
            int i, j;

if (l_3794)
                            goto lbl_3688;

                    for (g_4689 = 0; (g_4689 > 8); g_4689++)
            {
                uint8_t l_4337 = 255UL;
                int32_t l_4361 = 0xD7E3B922L;
                if ((0UL & l_4175))
                {
                    uint8_t l_4366 = 1UL;
                    int32_t l_4383 = (-1L);
                    if (((((g_5844 = ((l_4361 = (safe_div_func_uint32_t_u_u((safe_add_func_int32_t_s_s((safe_lshift_func_int16_t_s_u((((safe_sub_func_int8_t_s_s(((safe_lshift_func_int16_t_s_s(g_1798[5][2], l_4337)) , ((1L & (((g_5210[0] = p_44) != (((l_4360[1][1] = ((l_4175 <= (safe_div_func_uint32_t_u_u((safe_div_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_lshift_func_uint16_t_u_u((safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_lshift_func_int16_t_s_s((((((safe_sub_func_int8_t_s_s(((65534UL <= (g_34[0] , (safe_rshift_func_uint8_t_u_u(((((p_44 && (((((safe_add_func_int16_t_s_s((l_4358 = p_44), 7L)) < p_44) , 4L) < p_44) , 9L)) & (-8L)) && p_44) , g_204), 7)))) <= p_44), p_44)) && p_44) != g_1684[0]) == 0xB4L) != l_4337), 1)), 13)), l_4359)), l_4164)), p_44)), l_4359)), 4294967295UL))) & 0x5B367826L)) <= p_44) & 0x0C8BL)) , p_44)) || 252UL)), 0x0CL)) | (-4L)) > l_4359), 0)), p_44)), g_352))) != 0xF21C8443L)) && l_4360[1][1]) & 0x3215L) == g_2043))
                    {
                        int32_t l_4367[9] = {9L,3L,9L,9L,3L,9L,9L,3L,9L};
                        int i;
                        g_3935[2][3] = (BfBfBcg_573 , (((p_44 , p_44) > (l_4322 = g_2853[1][5][6])) > (l_4367[5] = ((p_44 , (safe_lshift_func_uint16_t_u_s((g_1599 = (safe_add_func_uint16_t_u_u(g_4689, l_4366))), 5))) != 0x3B41L))));
                        return p_44;
                    }
                    else
                    {
                        l_4384 = (l_4383 = (safe_lshift_func_int16_t_s_s((BJBJBpg_759 ^ (~(((safe_div_func_uint8_t_u_u((g_1370[2] , (p_44 != ((l_4175 = (safe_div_func_int16_t_s_s((l_4322 = 1L), g_2853[0][1][0]))) == l_3803[0][2]))), (safe_rshift_func_uint8_t_u_s(((-4L) | ((((safe_rshift_func_int8_t_s_s((g_3172 = ((safe_lshift_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(((((p_44 = g_34[0]) <= p_44) ^ g_1368) & p_44), 0)), 2)) <= l_4337)), 0)) | p_44) == p_44) <= 249UL)), g_352)))) || g_496[1]) <= p_44))), 11)));
                    }
                }
                else
                {
                    int32_t l_4403[6][3][4] = {{{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L}},{{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L}},{{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L}},{{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L}},{{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L}},{{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L}}};
                    int i, j, k;
                    g_5210[0] = (safe_add_func_uint32_t_u_u(((~(safe_mod_func_int32_t_s_s((p_44 == (g_352 , (safe_lshift_func_uint16_t_u_u((safe_add_func_int32_t_s_s((p_44 || (safe_mod_func_int16_t_s_s(p_44, 0x8EFEL))), (safe_lshift_func_int16_t_s_u(0xD408L, 14)))), ((g_98[1][3] = 0xDC2BL) != g_1684[0]))))), (g_204 = ((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint8_t_u_u((l_4361 = ((!l_4359) >= 0UL)), g_4689)) == 0xF0L) > l_4403[2][2][1]) > p_44), 0x8D57L)) ^ l_3803[0][2]))))) <= g_172), l_4359));
                    return l_4360[4][1];
                }
                g_3935[5][3] = (+((0xE0F6L >= ((l_4361 = (((safe_lshift_func_int8_t_s_u((0x56L == (((p_44 & p_44) , 0x7D5CL) < g_204)), 1)) <= (0xEEF94759L < l_4384)) && p_44)) | g_1352)) || l_4359));
                g_2580[0][7] = (safe_sub_func_uint8_t_u_u((((((i = (p_44 , 0UL)) >= (l_4384 = (((l_4384 && (safe_lshift_func_int8_t_s_u((1UL && (safe_sub_func_int8_t_s_s((safe_div_func_uint16_t_u_u((((-3L) < (safe_lshift_func_int8_t_s_u(((g_352 = (safe_add_func_uint8_t_u_u((p_44 ^ 0L), (((g_3935[1][3] = 0x4F09064BL) > ((safe_mod_func_int8_t_s_s((safe_sub_func_int8_t_s_s(((((((((((g_352 || p_44) | 1UL) ^ g_496[2]) && 0xC6L) ^ g_3109[2]) , (-1L)) && g_1288) <= BfBfBfg_184) < (-8L)) | l_4384), 0x73L)), l_4360[2][4])) == 1UL)) & g_4423[1])))) < g_172), 2))) , p_44), l_4359)), 0x3DL))), p_44))) && 0x51L) | g_3193))) , g_2853[0][6][6]) || p_44) , 0x4DL), p_44));
            }
            for (g_4689 = 12; (g_4689 < 17); g_4689++)
            {
                return l_3204[1];
            }
            g_2853[0][6][6] = (((safe_sub_func_uint8_t_u_u(((((((g_154 = ((l_4360[1][1] = ((((safe_add_func_uint16_t_u_u((0xD0CFL <= p_44), 4L)) && (((safe_mod_func_int8_t_s_s((g_154 = ((((g_472 = ((l_4432 = l_4360[3][5]) || g_3109[0])) & g_469) == ((i = ((safe_mod_func_int16_t_s_s((l_4439 = (((BfBfBbg_4475 = ((safe_mod_func_int32_t_s_s(((g_3193 = 3UL) != (p_44 & (safe_div_func_int16_t_s_s((6UL >= l_3212[4]), p_44)))), g_204)) == g_172)) | l_4360[5][2]) <= 4294967290UL)), p_44)) != p_44)) >= 1L)) <= l_4360[5][5])), p_44)) , 249UL) > p_44)) , (-1L)) <= 0x1470L)) || g_496[3])) , g_1370[2]) & g_1370[2]) != p_44) , g_3172) , 0UL), g_98[1][3])) > l_4440) && BfBfBeg_2043);
            for (g_172 = 0; (g_172 <= 3); g_172 += 1)
            {
                int32_t l_4458 = (-1L);
                const int16_t l_4505 = 0L;
                int i, j;
                if (((safe_lshift_func_uint8_t_u_s((safe_sub_func_int8_t_s_s(((g_2580[g_172][g_172] = (!0x9726E743L)) <= (0x9AEAD830L >= (!(safe_rshift_func_uint8_t_u_u((safe_div_func_int32_t_s_s(((l_4384 >= ((p_44 < p_44) <= ((l_4322 = ((g_2853[0][6][6] & (((g_4423[1] <= ((l_4175 = (safe_lshift_func_int8_t_s_s(l_4453, ((safe_mod_func_uint32_t_u_u((safe_add_func_uint32_t_u_u(0UL, 0x547154BBL)), 1L)) ^ 0x10L)))) , 1UL)) != g_1352) , p_44)) < l_4458)) > 0xBB173593L))) > 0x29B6L), 8L)), 4))))), l_4458)), l_4360[4][3])) < p_44))
                {
                    const uint32_t l_4477 = 0xFB4474FFL;
                    for (l_4358 = 0; (l_4358 < 5); l_4358 = safe_add_func_int16_t_s_s(l_4358, 1))
                    {
                        l_4458 = 0L;
                    }
                    g_2580[g_172][g_172] = (g_4423[1] , (((p_44 < l_4439) <= g_1684[0]) || (safe_add_func_int16_t_s_s((safe_add_func_int32_t_s_s((((1UL | (((((safe_lshift_func_uint16_t_u_s(0xAA14L, 2)) == (g_6428 ^ (safe_sub_func_int32_t_s_s((safe_sub_func_int32_t_s_s((p_44 == (g_275 = ((safe_div_func_uint16_t_u_u((safe_sub_func_int16_t_s_s(g_87, g_1288)), p_44)) != p_44))), 0x6FFD75EDL)), p_44)))) <= p_44) , 0x7C5F6ACEL) , 0x9B9B816CL)) > 0x34L) | BJBJBpg_759), l_4477)), i))));

{
                        int16_t l_4243 = (-1L);
                        g_2853[3][2][5] = ((g_68 = ((((safe_sub_func_int32_t_s_s(0x8CE52AFEL, g_68)) < (!(safe_sub_func_uint32_t_u_u((g_6771 , (safe_add_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(((i , ((((i , (g_5210[0] = g_68)) != ((g_76 || (l_4243 < g_3109[1])) , 0x9A66B615L)) < i) > g_68)) ^ 0x96A3L), i)), g_1798[5][2]))), l_4384)))) & g_469) | g_6771)) && g_472);
                        if (l_3209)
                            continue;
                    }

                    if (g_4689)
                        goto lbl_4478;
                }
                else
                {
                    uint16_t l_4481 = 0x0B37L;
                    int32_t l_4490 = 0x5D6B754AL;
                    l_4490 = (l_4360[3][0] = ((((safe_rshift_func_uint8_t_u_s(l_4481, 1)) == (g_204 = (BJBJBpg_759 = (g_2580[g_172][g_172] , (safe_rshift_func_uint16_t_u_u(g_5210[0], 13)))))) ^ (g_2580[g_172][g_172] , p_44)) != ((~(l_4489[4][0] = (0x9BE7L >= (p_44 = ((p_44 <= (safe_div_func_int16_t_s_s(((l_4322 = (((safe_sub_func_uint16_t_u_u((l_4458 = (p_44 >= (g_3935[4][1] < 5UL))), i)) <= g_352) , (-9L))) , 0xBC74L), g_1368))) != 0UL))))) , 0x1BL)));
                    BfBfBeg_2043 = ((p_44 , l_4489[4][0]) > (safe_rshift_func_int8_t_s_u((g_4689 = ((safe_mod_func_int32_t_s_s(((g_154 = (g_2580[g_172][g_172] = p_44)) | (l_4458 = ((l_4439 = (safe_div_func_int16_t_s_s(0x0BC8L, 0x90FAL))) > (g_5210[0] = (((((safe_div_func_uint16_t_u_u((g_1599 = g_1368), (safe_add_func_int16_t_s_s(p_44, i)))) || (safe_rshift_func_int8_t_s_u(((g_1370[2] = (safe_lshift_func_uint8_t_u_u(1UL, p_44))) && l_4358), 4))) ^ l_4505) >= p_44) ^ l_4440))))), p_44)) | g_4423[1])), p_44)));
                    return l_4384;
                }
                i = 0xCD96DF4EL;
                g_5210[0] = ((safe_sub_func_int16_t_s_s((((safe_div_func_uint8_t_u_u(p_44, (g_4423[1] = ((safe_div_func_int8_t_s_s(((((((0x37CA17FCL >= (((safe_sub_func_uint32_t_u_u(((g_4689 | (safe_add_func_int8_t_s_s(0x4DL, 7L))) , (safe_mod_func_uint16_t_u_u(p_44, p_44))), (BfBfBcg_573 < ((safe_mod_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s((safe_add_func_uint32_t_u_u(g_2043, l_4505)), 7)) ^ l_4453) >= l_4360[4][3]), 1L)) > 0xEDL)))) ^ l_4489[4][0]) , l_4440)) & g_352) , p_44) , g_5844) < 1L) ^ g_2580[g_172][g_172]), g_3935[4][2])) | l_4489[4][0])))) && p_44) ^ BfBfBbg_4475), g_2580[0][7])) | p_44);
            }
        }
    }

                    ;
                }

}
                    BfBfBcg_573 = g_573;
BfBfBdg_1288 = g_1288;
BfBfBeg_2043 = g_2043;
BfBfBfg_184 = g_184;
g_1352 = (~(((((BfBfBg_1352 && ((BfBfBcg_573 + BfBfBdg_1288) ^ (~(g_1368)))) & (~((~(g_2043))))) & ((~(g_184)) | (~((~((~(g_68)))))))) * (~((~((~(((((~(g_573)) + (BfBfBbg_4475 * l_4321)) ^ ((g_4475 % (~((g_1352 | BfBfBeg_2043)))) && ((~(g_1288)) * BfBfBfg_184))) & g_2852))))))))));
                                    while ((!g_352) )
{

l_3887 += 1;


}
                    g_4475 = (~(((~((~(((~(BfBfBdg_1288)) + g_1368))))) && (((~((~((~(g_573)))))) && (~(((((g_4475 & g_2043) << g_184) & g_68) * (~((BfBfBcg_573 | BfBfBbg_4475))))))) & ((((g_1288 | BfBfBfg_184) * BfBfBg_1352) + g_2852) * (~((~((g_1352 ^ (l_4321 & BfBfBeg_2043)))))))))));
g_573 = (~((((~(BfBfBcg_573)) && (~((~((BfBfBdg_1288 * g_4475)))))) && (~((~((((~((g_2852 ^ g_573))) + (g_1368 && (((g_2043 && (~(l_4321))) >> ((~(g_1352)) * BfBfBg_1352)) + (~((BfBfBbg_4475 && g_68)))))) + (~((BfBfBeg_2043 & (~((BfBfBfg_184 | ((~(g_184)) & (~(g_1288)))))))))))))))));
                               int32_t BrBrBhg_573 = (~((((~(g_1352)) & (~(((~(g_154)) ^ (~(l_4273)))))) ^ (~((~((g_506 & (~(((l_4321 & (~(g_3486))) & ((g_573 % (g_3193 & l_4090)) | g_184))))))))))));
int8_t BrBrBil_4321 = (~(((~((g_154 || g_3193))) || ((((~(g_184)) & (~(l_4273))) | (g_573 % (~(g_3486)))) & ((l_4321 || (g_506 | (BrBrBhg_573 % l_4090))) << (~(g_1352)))))));
uint32_t BrBrBjl_4090 = (~(((~((((~(BrBrBhg_573)) % (l_4273 | l_4090)) || (g_3193 ^ ((g_154 << (~(g_573))) & g_3486))))) | (~((((g_184 % BrBrBil_4321) & (~((g_506 ^ g_1352)))) % (~(l_4321))))))));
int32_t BrBrBkg_3486 = (~(((((~(((~((g_3193 || l_4090))) % g_506))) % (~(((g_184 & g_573) ^ BrBrBjl_4090)))) | (~((~(((l_4321 >> g_3486) ^ (~(l_4273)))))))) ^ ((~((g_1352 ^ (~(BrBrBil_4321))))) || (BrBrBhg_573 | g_154)))));
int32_t BrBrBlg_506 = (~((((l_4090 || ((g_506 << g_3486) ^ ((~(BrBrBhg_573)) & (g_573 | BrBrBkg_3486)))) ^ (~(((g_1352 ^ (~((~(g_3193))))) | (((l_4321 | g_154) << l_4273) ^ ((~(BrBrBil_4321)) % (~(BrBrBjl_4090)))))))) >> (~((~(g_184)))))));
uint8_t BrBrBmg_3193 = (~(((~(g_184)) || (~((~((((((g_506 || g_3486) % ((~(l_4090)) ^ (BrBrBil_4321 | ((~(g_154)) || l_4321)))) | g_3193) << (~((((~((BrBrBjl_4090 ^ g_573))) & (~((BrBrBlg_506 ^ l_4273)))) ^ (~((~(g_1352)))))))) | ((~((~(BrBrBkg_3486)))) & BrBrBhg_573)))))))));
if(!(((!BrBrBhg_573) && (BrBrBmg_3193<=254)))){
BrBrBhg_573 = g_573;
BrBrBil_4321 = l_4321;
LABEL_rBrBn: BrBrBjl_4090 = l_4090;
                                    if ((!g_1368) )
{

{
                        l_3209 = 0xC846F6BAL;
                    }

}
                    BrBrBkg_3486 = g_3486;
                                   if (!((g_2467<11)))
                    BrBrBlg_506 = g_506;
BrBrBmg_3193 = g_3193;
                               int16_t BkCkCBg_335 = (-(((~((((g_3193 + g_172) & (g_1288 * (-((g_76 * g_335))))) >> (((-(g_240)) & (~((~((-(g_573))))))) * (g_2422 & g_1599))))) * (~((~((~(l_4272)))))))));
int32_t BkCkCCg_573 = (~(((~((~((-(BkCkCBg_335)))))) & ((~((g_2422 && g_335))) * ((~(((~(((g_3193 + g_1599) ^ (~(g_573))))) & ((g_1288 | l_4272) | g_172)))) & ((~(g_240)) && (~(g_76))))))));
int8_t BkCkCDg_2422 = (-(((((l_4272 && g_172) ^ (-(g_2422))) * (-(g_573))) ^ (~(((-((-(BkCkCBg_335)))) * (((BkCkCCg_573 && (g_1288 ^ g_1599)) * (~((g_76 * (g_3193 << g_240))))) && (~(g_335)))))))));
int32_t BkCkCEg_240 = (-(((~((-((~((((-((~((-(g_3193)))))) ^ ((g_1599 + (g_240 * BkCkCDg_2422)) & BkCkCBg_335)) & g_172))))))) & ((((g_76 && l_4272) ^ (-((-(g_2422))))) && (-(((g_1288 * (-(g_573))) + BkCkCCg_573)))) && g_335))));
int16_t BkCkCFg_1288 = (~(((~((((g_76 * (-((~(g_335))))) && (-((((BkCkCBg_335 >> g_240) | (g_573 & g_172)) + (-(((~(BkCkCEg_240)) && (BkCkCDg_2422 | (l_4272 & g_1288))))))))) & (~(((~((BkCkCCg_573 + g_1599))) * (~((~(g_2422)))))))))) + g_3193)));
int32_t BkCkCGl_4272 = (-(((((g_573 ^ BkCkCCg_573) && (g_1599 + (~(BkCkCBg_335)))) + ((~((~(((BkCkCDg_2422 ^ l_4272) + (~(BkCkCFg_1288))))))) * ((~((~(((g_172 + g_76) & (~((BkCkCEg_240 | (g_3193 & g_335))))))))) & g_1288))) ^ (~((~((-((g_240 && (~(g_2422))))))))))));
if((((g_76 > g_3193) && g_76) || ((g_335 < g_1599) && (BkCkCDg_2422<=-60)))){
BkCkCBg_335 = g_335;
BkCkCCg_573 = g_573;
BkCkCDg_2422 = g_2422;
BkCkCEg_240 = g_240;
BkCkCFg_1288 = g_1288;
BkCkCGl_4272 = l_4272;
g_335 = (~(((((((~(((~(BkCkCEg_240)) ^ g_76))) + (~(l_4272))) * g_2422) && ((~(BkCkCCg_573)) && (BkCkCGl_4272 ^ ((-(g_1288)) & (BkCkCDg_2422 | g_573))))) + ((~((g_3193 * g_335))) + (~(g_240)))) | (~((((~((~(g_172)))) * (~(((~(BkCkCBg_335)) && g_1599)))) | (~(BkCkCFg_1288))))))));
g_573 = (-(((~((~((~((g_172 << BkCkCEg_240))))))) & (-((((~(((-((~(BkCkCGl_4272)))) && (~(g_335))))) & (((~((BkCkCCg_573 & (~(g_573))))) && (~(((g_2422 && (~((~(l_4272))))) && (~((g_240 & g_1288))))))) * ((BkCkCDg_2422 * (BkCkCFg_1288 | g_1599)) && g_76))) * ((~(BkCkCBg_335)) && g_3193)))))));
g_2422 = (~(((-((-(((g_240 && g_573) >> ((BkCkCEg_240 && l_4272) + ((g_335 + ((g_1599 & BkCkCBg_335) ^ (-(BkCkCCg_573)))) >> BkCkCDg_2422))))))) | ((~(((~(((-(BkCkCGl_4272)) + ((-((g_3193 ^ g_2422))) && (g_1288 ^ (~(BkCkCFg_1288))))))) | (~((~((~(g_76))))))))) & g_172))));
g_240 = (~((((BkCkCBg_335 & g_1599) << g_573) & ((((BkCkCEg_240 * BkCkCDg_2422) ^ ((-(g_335)) * g_172)) * ((~(((g_1288 ^ g_3193) & g_240))) | g_76)) && (-((-(((-(((-((BkCkCCg_573 | BkCkCGl_4272))) + (~(g_2422))))) && (~((l_4272 ^ (-(BkCkCFg_1288))))))))))))));
g_1288 = (~((((-((~(g_76)))) * ((g_573 >> BkCkCEg_240) + (BkCkCBg_335 + g_335))) ^ (((~(l_4272)) & (-(BkCkCFg_1288))) + ((~(g_1288)) ^ ((~((g_240 ^ ((-((g_3193 && BkCkCCg_573))) ^ g_2422)))) * ((g_1599 && BkCkCGl_4272) + (g_172 << BkCkCDg_2422))))))));
l_4272 = (~((((~(((-(((BkCkCCg_573 & (BkCkCBg_335 + g_335)) | g_1288))) + ((BkCkCEg_240 + g_1599) ^ (~((g_76 >> g_573))))))) && ((((g_240 ^ BkCkCFg_1288) & (~(BkCkCDg_2422))) && BkCkCGl_4272) * (~(g_2422)))) | (((~(l_4272)) + g_3193) >> (~((~(g_172))))))));
if((g_1288>-30229)){
printf("g_335=%lld\n", (long long)g_335);
BkCkCEg_240 = (~(((~((~(((-((((g_1599 | g_573) ^ g_2422) | (~(g_172))))) * ((~(BkCkCDg_2422)) ^ (g_1288 << (~(BkCkCGl_4272))))))))) && (((BkCkCEg_240 >> (g_76 && (-(l_4272)))) | (-((~(((-(((~(g_3193)) ^ g_240))) & (~(((g_335 | BkCkCFg_1288) & BkCkCCg_573))))))))) && BkCkCBg_335))));

for (g_982 = 0; (g_982 != 49); g_982 = safe_add_func_uint16_t_u_u(g_982, 6))
                    {
                        g_5210[0] = 1L;
                        BkCkCEg_240 = g_34[0];
                    };


                    goto lbl_4478;
}
if(((g_573 < BkCkCBg_335) && (!BkCkCFg_1288))){
printf("g_573=%lld\n", (long long)g_573);
goto LABEL_rBrBn;
}
if(((g_573 > BkCkCFg_1288) || !(BkCkCBg_335))){
printf("g_2422=%lld\n", (long long)g_2422);
goto LABEL_rBrBo;
}
                                    while ((!((l_4321 > g_275)) || (g_9>194)) )
{

if (g_506) printf("index = [%d][%d]\n", BrBrBkg_3486, l_4476);

}
                    if((g_1288>-30229)){
printf("g_240=%lld\n", (long long)g_240);
goto LABEL_rBrBo;
}
if((g_76>432544659U)){
printf("g_1288=%lld\n", (long long)g_1288);
BkCkCEg_240 = (-(((-(((-((((BkCkCBg_335 + ((-((BkCkCFg_1288 ^ (g_76 ^ g_573)))) >> BkCkCCg_573)) >> (g_2422 & (BkCkCDg_2422 * ((~(BkCkCEg_240)) & g_1288)))) & (g_335 && l_4272)))) >> (-(g_240))))) & (-((-((~(((~((~(g_1599)))) | (g_172 ^ (BkCkCGl_4272 + (~(g_3193))))))))))))));
BkCkCFg_1288 = (~(((~((-(((~(((BkCkCCg_573 ^ g_573) >> ((g_172 << (~((~(BkCkCEg_240))))) << (~((l_4272 >> g_335))))))) * ((BkCkCGl_4272 << (-(g_1599))) & (-((((-(BkCkCFg_1288)) ^ BkCkCBg_335) & (-(g_76))))))))))) >> ((-((~(((~(g_3193)) + (g_2422 >> g_1288)))))) + (-(((-(BkCkCDg_2422)) << g_240)))))));
goto lbl_3126;
}
}
g_335 = BkCkCBg_335;
g_573 = BkCkCCg_573;
g_2422 = BkCkCDg_2422;
g_240 = BkCkCEg_240;
g_1288 = BkCkCFg_1288;
l_4272 = BkCkCGl_4272;

                    g_573 = (~((((~((BrBrBil_4321 % (~((~((l_4090 || ((~(BrBrBhg_573)) || (BrBrBmg_3193 || BrBrBjl_4090)))))))))) ^ g_506) & ((~((((~(l_4321)) || (BrBrBlg_506 || g_154)) >> (~(g_1352))))) % (~((((~(g_3486)) % ((g_184 >> l_4273) << ((~((~(g_3193)))) || (~(BrBrBkg_3486))))) >> (~(g_573)))))))));
l_4321 = (~(((((l_4321 | ((~(g_3193)) || (l_4273 | (~(BrBrBmg_3193))))) ^ (~(BrBrBkg_3486))) || (~(BrBrBlg_506))) || (~(((BrBrBjl_4090 ^ g_573) & (((((~((~(l_4090)))) % g_184) >> g_3486) || (g_506 || g_1352)) & (~(((BrBrBil_4321 | (~(BrBrBhg_573))) | g_154))))))))));
l_4090 = (~((((~((((~(g_506)) & ((~(l_4273)) || BrBrBlg_506)) || ((~(g_1352)) | (BrBrBil_4321 || ((~(g_154)) ^ (g_3486 << g_184))))))) | ((BrBrBhg_573 || BrBrBmg_3193) << (((g_3193 % l_4321) || BrBrBkg_3486) & (l_4090 | g_573)))) % BrBrBjl_4090)));
g_3486 = (~((((g_573 ^ BrBrBhg_573) ^ ((((~((~(((~(l_4090)) | (BrBrBmg_3193 & (BrBrBjl_4090 >> l_4273))))))) << ((l_4321 || BrBrBkg_3486) & g_1352)) & (~((~(g_506))))) ^ ((~((g_3193 >> BrBrBlg_506))) ^ ((g_154 >> g_3486) << g_184)))) | (~(BrBrBil_4321)))));
g_506 = (~(((~(((~(((~((((~((l_4090 ^ l_4321))) || BrBrBlg_506) & (BrBrBkg_3486 % (~(g_184)))))) << ((~(((~(g_573)) ^ (~(g_154))))) & ((((~(g_506)) ^ (g_3193 % BrBrBmg_3193)) | (~(BrBrBil_4321))) % (BrBrBhg_573 || (~(l_4273)))))))) ^ (~((~(g_1352))))))) << (~((~((~((~((g_3486 || BrBrBjl_4090))))))))))));
LABEL_rBrBo: g_3193 = (~(((~((((~(((g_184 ^ (~((~(g_506))))) || (g_3193 >> BrBrBlg_506)))) & (((g_573 ^ ((BrBrBmg_3193 || BrBrBjl_4090) % l_4090)) >> (l_4321 % (~(g_154)))) ^ ((~((g_1352 || g_3486))) % (~(l_4273))))) || ((~(BrBrBkg_3486)) & BrBrBhg_573)))) % (~(BrBrBil_4321)))));
if(!((l_4273 < BrBrBlg_506))){
;
g_3193 = (~(((((~(((~(((~(BrBrBmg_3193)) % (g_506 << BrBrBlg_506)))) & ((l_4273 || (l_4090 << g_1352)) & (~(BrBrBil_4321)))))) || (((~((g_3193 | g_573))) & BrBrBkg_3486) ^ BrBrBhg_573)) & (~((~((~(g_184))))))) << ((~(l_4321)) >> (~(((g_3486 & (~(BrBrBjl_4090))) >> g_154)))))));
goto lbl_3967;
}
                                   if ((g_204<=9))
                    { if ((g_1138 < g_2852))
                    if(((!g_184) && ((g_506 > l_4321) && (!BrBrBmg_3193)))){

{
                        uint32_t l_666 = 4294967292UL;
                        int32_t l_677 = 0xC2919148L;
                        j = (g_5844 == (safe_lshift_func_int16_t_s_u((l_666 >= 0xCA1FA15DL), 10)));
                        l_4476 = (g_2043 = (~(!(g_5844 <= (((0xBD3024CCL || (0x0624L == l_3607)) <= 0UL) > (g_472 == (safe_add_func_int16_t_s_s(((BfBfBcg_573 = (((safe_mod_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((l_677 = 1UL), ((safe_div_func_uint8_t_u_u((l_3607 < (l_666 || l_3607)), 0x7AL)) > l_3607))), 0xCE57L)) & 0xC6L) && 1L)) >= l_3607), l_4272))))))));
                    }

                    ;
BrBrBlg_506 = (~((g_154 >> ((((g_506 ^ (~(g_1352))) ^ (g_184 << (~((g_3193 >> (BrBrBkg_3486 || (~((~(l_4321)))))))))) || (~((((~(BrBrBlg_506)) ^ l_4090) & (~(g_3486)))))) || (((BrBrBhg_573 << (BrBrBjl_4090 >> l_4273)) || g_573) | (BrBrBil_4321 || BrBrBmg_3193))))));
goto lbl_4478;
}}
                                    while ((g_1138 > g_3463) )
{

if (BJBJBpg_759)
                        goto lbl_3688;

}
                    if((g_3193<255)){
printf("l_4090=%llu\n", (unsigned long long)l_4090);
goto LABEL_rBrBn;
}
if(((!l_4090) && g_184)){
printf("g_506=%lld\n", (long long)g_506);

if (l_4272) printf("index = [%d]\n", p_44);

                    BrBrBlg_506 = (~(((~(((((l_4273 % (~((g_573 % l_4321)))) & g_184) | (~(((~((BrBrBjl_4090 | g_506))) | ((BrBrBmg_3193 || g_1352) << l_4090))))) & (g_154 ^ (BrBrBlg_506 >> BrBrBhg_573))))) % (~(((BrBrBil_4321 << (~(BrBrBkg_3486))) || ((~(g_3193)) >> g_3486)))))));
goto lbl_3517;
}
if(!(!((l_4090>3139196721U)))){

{
                        int i, j;
                        return l_3803[g_1599][g_1599];
                    }

                    printf("g_3193=%llu\n", (unsigned long long)g_3193);
g_573 = (~(((~((~((g_3193 << BrBrBlg_506))))) ^ ((~((~((~(g_506)))))) ^ (~((((~(BrBrBhg_573)) | ((~(g_154)) ^ (~((l_4090 & g_1352))))) || ((~(BrBrBmg_3193)) ^ ((((l_4273 % (~((BrBrBjl_4090 % BrBrBil_4321)))) ^ g_3486) >> BrBrBkg_3486) | (g_184 << (~((l_4321 || g_573)))))))))))));
;
}
}
g_573 = BrBrBhg_573;
l_4321 = BrBrBil_4321;
l_4090 = BrBrBjl_4090;
g_3486 = BrBrBkg_3486;
                                   if (((g_76<=432544659U) || (g_68<=4294967289U)))
                    g_506 = BrBrBlg_506;
                                    if ((g_2852>245) )
{

{
                    const uint32_t l_4477 = 0xFB4474FFL;
                    for (BrBrBjl_4090 = 0; (BrBrBjl_4090 < 5); BrBrBjl_4090 = safe_add_func_int16_t_s_s(BrBrBjl_4090, 1))
                    {
                        g_240 = 0L;
                    }
                    g_2580[l_3794][l_3794] = (g_4423[1] , (((g_240 < g_3486) <= g_1684[0]) || (safe_add_func_int16_t_s_s((safe_add_func_int32_t_s_s((((1UL | (((((safe_lshift_func_uint16_t_u_s(0xAA14L, 2)) == (g_1288 ^ (safe_sub_func_int32_t_s_s((safe_sub_func_int32_t_s_s((g_240 == (BfBfBcg_573 = ((safe_div_func_uint16_t_u_u((safe_sub_func_int16_t_s_s(g_87, g_335)), g_240)) != g_240))), 0x6FFD75EDL)), g_240)))) <= g_240) , 0x7C5F6ACEL) , 0x9B9B816CL)) > 0x34L) | g_68), l_4477)), g_2440))));
                    if (BJBJBsg_2467)
                        goto lbl_4478;
                }

}
                    g_3193 = BrBrBmg_3193;

                    g_1288 = (~((((~((~((g_1288 ^ g_184))))) * (~(((~(((~(BfBfBeg_2043)) + (~(l_4321))))) ^ (((((~(g_4475)) ^ BfBfBfg_184) && BfBfBdg_1288) % g_2852) << BfBfBcg_573))))) % ((~((~((~((~(g_1352)))))))) + (~(((~(((g_573 & (~(g_68))) + BfBfBbg_4475))) * (g_1368 * (~((BfBfBg_1352 & g_2043)))))))))));
g_2043 = (~(((~((((~(((~(g_573)) | (~(((~(l_4321)) | g_68)))))) * (g_4475 * (((~(g_1368)) | (BfBfBbg_4475 && (BfBfBdg_1288 & g_184))) && BfBfBeg_2043))) && ((g_1288 ^ BfBfBg_1352) ^ (~((BfBfBcg_573 & (~(g_1352))))))))) * (~((~(((~((~((g_2852 | g_2043))))) + (~(BfBfBfg_184))))))))));
                                    if ((g_68<4294967289U) )
{


g_759 += 1;


                    for (l_4273 = 0; l_4273 < 9; l_4273++)
    {
        for (l_4273 = 0; l_4273 < 8; l_4273++)
        {
            transparent_crc(g_1798[l_4273][l_4273], "g_1798[l_4273][l_4273]", l_4272);
            if (l_4272) printf("index = [%d][%d]\n", l_4273, l_4273);

        }
    };


}
                    g_184 = (~((((~((~((BfBfBeg_2043 % (~(g_573))))))) && (~((BfBfBcg_573 | l_4321)))) & (((~(g_2852)) ^ (~(BfBfBdg_1288))) & (~((((~(g_1288)) ^ (~((~(BfBfBbg_4475))))) ^ ((~(((~(g_4475)) && (g_1352 % BfBfBg_1352)))) | ((~(BfBfBfg_184)) % (g_68 && (((~(g_2043)) * g_184) % g_1368)))))))))));
                                                                   uint32_t BJBJBug_1345 = (~(((~((~((~(((~(l_4044)) / (~(l_4476))))))))) / ((~(((~(((~(((g_204 & l_3607) & (g_87 / g_469)))) ^ g_3486))) & (~(g_9))))) / (~((l_4232 | (~((~(g_1345)))))))))));
uint8_t BJBJBvg_87 = (~((((~((l_4232 | g_204))) ^ ((((g_469 / l_4044) || g_3486) % g_9) & (g_1345 | (~(l_3607))))) | (~(((~((~((BJBJBug_1345 ^ (~(l_4476))))))) || (~(g_87))))))));
int32_t BJBJBwg_3486 = (~((((~((g_9 | g_469))) ^ ((~(BJBJBvg_87)) / (((l_4044 | (~(g_3486))) || (~((l_4476 | g_1345)))) || (~((l_3607 ^ ((~(g_87)) | g_204))))))) || (~((BJBJBug_1345 % (~(l_4232))))))));
int32_t BJBJBxg_204 = (~((((g_1345 & g_87) | (((~((~(g_204)))) || (~((BJBJBug_1345 | ((BJBJBvg_87 % l_4044) ^ l_4232))))) >> (((~((~(g_9)))) / (l_3607 || g_3486)) & g_469))) & (~(((~(l_4476)) || BJBJBwg_3486))))));
int32_t BJBJByl_4476 = (~(((~(((~(((~(g_87)) ^ (~((l_3607 / BJBJBwg_3486)))))) / ((~(l_4044)) / (~(((~((g_9 || (g_469 | l_4232)))) || ((BJBJBxg_204 || g_204) & (~(g_1345)))))))))) & ((l_4476 | BJBJBug_1345) ^ (BJBJBvg_87 << g_3486)))));
uint32_t BJBJBzl_4232 = (~(((~(((~((g_3486 | (BJBJByl_4476 >> (~((g_9 | (~((~(BJBJBxg_204))))))))))) & (~((~(g_204))))))) || (~(((~(((~(l_4044)) || (g_87 & (~(g_469)))))) & (((l_3607 | (BJBJBwg_3486 | l_4476)) & (BJBJBvg_87 & g_1345)) / (BJBJBug_1345 % l_4232))))))));
                                    if ((g_469 > g_1368) )
{

for (g_2043 = 0; g_2043 < 5; g_2043++)
        {
            transparent_crc(g_98[i][g_2043], "g_98[i][g_2043]", l_4476);
            if (l_4476) printf("index = [%d][%d]\n", i, g_2043);

        };


}
                    if((!((!BJBJBzl_4232)) || (l_4232<=3810345732U))){
                                    while ((!g_472) )
{

{
                        int32_t l_4367[9] = {9L,3L,9L,9L,3L,9L,9L,3L,9L};
                        int i;
                        g_3935[2][3] = (g_573 , (((g_573 , g_573) > (l_3209 = g_2853[1][5][6])) > (l_4367[5] = ((g_573 , (safe_lshift_func_uint16_t_u_s((l_3794 = (safe_add_func_uint16_t_u_u(g_3172, BfBfBbg_4475))), 5))) != 0x3B41L))));
                        return g_573;
                    }

}
                    BJBJBug_1345 = g_1345;
                                   if ((g_3600 && g_3463))
                    BJBJBvg_87 = g_87;
                                    while (((g_1138<0U) || (!g_469)) )
{

p_44 += 1;


}
                    BJBJBwg_3486 = g_3486;
BJBJBxg_204 = g_204;
BJBJByl_4476 = l_4476;
BJBJBzl_4232 = l_4232;
g_1345 = (~(((~(((~(((~(g_204)) & g_1345))) | (((~((BJBJBvg_87 | l_4476))) / (~(BJBJBzl_4232))) | ((g_3486 / (~((g_87 ^ (~(BJBJBxg_204)))))) | (~((g_469 ^ l_4232)))))))) % (~((((~(BJBJBug_1345)) ^ BJBJBwg_3486) << (~(((BJBJByl_4476 % l_3607) | (g_9 & l_4044))))))))));
g_87 = (~((((((~((BJBJBwg_3486 / (~(l_4476))))) & ((~((BJBJByl_4476 ^ ((BJBJBvg_87 ^ g_87) || (g_3486 & (g_469 ^ BJBJBug_1345)))))) % (~((~(l_4232)))))) | (BJBJBxg_204 ^ (~((~(g_204)))))) / ((~(g_9)) / (~(((~((~((~(l_3607)))))) | l_4044))))) % (~((BJBJBzl_4232 ^ (~(g_1345))))))));
g_3486 = (~(((((~((~(g_469)))) % ((BJBJBzl_4232 | l_4232) || BJBJBug_1345)) & ((~((~((~(l_4476)))))) >> (~((~((~(g_1345)))))))) & (((g_3486 ^ l_4044) | (((~(g_87)) ^ (~((BJBJBwg_3486 | ((~(g_204)) / g_9))))) & ((~(BJBJBxg_204)) | BJBJByl_4476))) & (~((BJBJBvg_87 | l_3607)))))));
                                   if ((l_3464 < g_154))
                    g_204 = (~(((~((~(((((l_4232 / (g_3486 || ((~(BJBJBug_1345)) & (~(g_469))))) % (((l_4476 / BJBJBvg_87) | g_87) | ((~((~(BJBJBwg_3486)))) / l_4044))) ^ (~((~(l_3607))))) || (~((~((~(BJBJBzl_4232))))))))))) ^ ((~(((g_1345 ^ BJBJBxg_204) || (~(BJBJByl_4476))))) & (g_9 << g_204)))));
                                                                        if ((!g_472) )
{

if (g_1599)
                            goto lbl_3688;

}
                    if ((!g_3317) )
{

g_1369 += 1;


}
                    l_4476 = (~(((((~(BJBJBvg_87)) ^ (BJBJByl_4476 ^ g_204)) & ((~((~((~((BJBJBwg_3486 / g_9))))))) / (~(l_3607)))) ^ (~(((~((~((~(l_4232)))))) % (((~(BJBJBxg_204)) || (g_469 & (BJBJBzl_4232 ^ g_1345))) | ((l_4476 % (BJBJBug_1345 | l_4044)) % (~((g_3486 / g_87)))))))))));
l_4232 = (~(((((l_4044 % g_1345) / ((((~(g_9)) | (BJBJByl_4476 % BJBJBzl_4232)) || BJBJBug_1345) || l_4232)) | ((~(l_3607)) & BJBJBwg_3486)) || (~((((~((~((g_469 ^ (~(((BJBJBvg_87 ^ g_204) ^ (~(l_4476)))))))))) / (~((~((~((g_87 ^ (~(g_3486)))))))))) | BJBJBxg_204))))));
if(!(!((g_3486>-1)))){

for (l_3607 = 0; (l_3607 <= 0); l_3607 += 1)
                {
                    int32_t l_4711 = 0x150A892AL;
                    return l_4711;
                }
for (g_240 = 0; g_240 < 1; g_240++)
    {
        transparent_crc(g_1684[g_240], "g_1684[g_240]", BJBJBwg_3486);
        if (BJBJBwg_3486) printf("index = [%d]\n", g_240);

    };


                    ;


                    printf("g_1345=%llu\n", (unsigned long long)g_1345);

{
                        BrBrBkg_3486 = (j && j);
                    }

                    ;
}
                               uint32_t BJCJCug_982 = (~(((~(((~((~(l_3278)))) + (~(((~(l_4232)) << (g_897 / g_506))))))) && (~(((g_2440 & l_4044) & ((~(g_76)) + (g_35 ^ (g_1345 && g_982)))))))));
uint32_t BJCJCvg_1345 = (~(((~((g_2440 & ((((g_982 - l_3278) + (~(l_4232))) & (~(BJCJCug_982))) + g_35)))) / (g_897 && ((g_506 - l_4044) & (g_1345 - g_76))))));
int32_t BJCJCwg_2440 = (~((((~(((((l_3278 && g_897) && (~(g_982))) / l_4232) << ((~(g_1345)) && (~(g_76)))))) ^ (((l_4044 + (~(BJCJCug_982))) & g_506) && BJCJCvg_1345)) / (~((~(((~((~(g_2440)))) - (~(g_35))))))))));
uint32_t BJCJCxl_4232 = (~(((~(((g_1345 & (((~((~(l_4232)))) & l_3278) - (~((g_2440 + BJCJCwg_2440))))) ^ (~(((((BJCJCug_982 & g_506) / (~(g_982))) / g_897) | (~(l_4044)))))))) + ((BJCJCvg_1345 | (~(g_35))) && g_76))));
uint32_t BJCJCyg_76 = (~((((~(((~(l_3278)) && (~((~((~((~(((~((g_982 && BJCJCxl_4232))) - ((g_2440 + g_35) / g_897))))))))))))) + ((~((g_506 + BJCJCvg_1345))) / (l_4044 - BJCJCwg_2440))) && ((l_4232 | (g_1345 | (~(BJCJCug_982)))) + (~(g_76))))));
int16_t BJCJCzg_897 = (~((g_1345 | ((~((~(((~((~(((~((BJCJCyg_76 | g_982))) | (~(BJCJCxl_4232))))))) && (~((((~((~(g_35)))) - BJCJCvg_1345) | ((~(BJCJCwg_2440)) + g_2440))))))))) + (((~((g_76 && g_897))) + (((l_3278 / l_4044) & BJCJCug_982) / l_4232)) ^ (~((~(g_506)))))))));
if(!((!BJCJCug_982))){
BJCJCug_982 = g_982;
BJCJCvg_1345 = g_1345;
BJCJCwg_2440 = g_2440;
LABEL_JCJCA: BJCJCxl_4232 = l_4232;
BJCJCyg_76 = g_76;
BJCJCzg_897 = g_897;
g_982 = (~((((~((((g_1345 | (~(g_35))) & BJCJCxl_4232) + g_982))) + ((~((g_76 | l_3278))) ^ (~((~(((~(g_897)) + g_2440))))))) + (~(((BJCJCug_982 ^ (~(BJCJCzg_897))) && ((~((~((~((l_4232 | (~(BJCJCvg_1345))))))))) & (~(((~((BJCJCyg_76 ^ (~(l_4044))))) & (g_506 - BJCJCwg_2440)))))))))));
g_1345 = (~((((((((BJCJCwg_2440 - (~(l_4232))) | BJCJCug_982) + (~(BJCJCyg_76))) ^ (~(g_1345))) / g_897) ^ (~((~((~(g_982))))))) - ((~((~(((~(g_35)) + (BJCJCvg_1345 + l_3278)))))) - ((~(g_76)) ^ ((g_2440 + BJCJCzg_897) / ((~((l_4044 && BJCJCxl_4232))) - g_506)))))));
g_2440 = (~(((((~(BJCJCug_982)) && (~(BJCJCxl_4232))) / (~((((((l_3278 / BJCJCzg_897) - l_4232) && (BJCJCvg_1345 | (~(BJCJCwg_2440)))) - (l_4044 / g_506)) + ((~(g_76)) ^ g_897))))) - (~(((~(g_982)) | (((~(g_1345)) ^ BJCJCyg_76) | (~((g_2440 / g_35))))))))));
l_4232 = (~(((((~(((BJCJCyg_76 & BJCJCvg_1345) + (~((~((~((BJCJCzg_897 ^ ((~(l_4044)) | (g_1345 & l_4232)))))))))))) | (~(g_35))) / (((~((~(((g_506 && g_76) << (~(BJCJCxl_4232))))))) | (~(g_897))) / (l_3278 & ((~(((~(BJCJCwg_2440)) / (~(g_2440))))) / g_982)))) & (~((~((~((~(BJCJCug_982)))))))))));
g_76 = (~((((((~((~((~(BJCJCzg_897)))))) | (((~(l_3278)) ^ ((g_76 & g_1345) + BJCJCug_982)) & (~(g_982)))) - (~(((~(g_2440)) + ((~((BJCJCwg_2440 ^ (g_35 ^ BJCJCxl_4232)))) & g_897))))) & (~((~((~(BJCJCvg_1345))))))) >> (~((~((~((~(((~(((~(l_4044)) | BJCJCyg_76))) && (~((l_4232 + g_506)))))))))))))));
g_897 = (~(((BJCJCwg_2440 ^ ((((((~(g_506)) - (BJCJCug_982 && (l_4044 + g_1345))) + (~((~((~(BJCJCvg_1345))))))) + BJCJCxl_4232) - (g_35 - g_2440)) + (~((g_897 && (BJCJCzg_897 ^ g_76)))))) & (~((~((g_982 | ((~(((~(l_3278)) - BJCJCyg_76))) | l_4232)))))))));
if((!g_506)){
printf("g_982=%llu\n", (unsigned long long)g_982);
BJCJCvg_1345 = (~((((((~((~(((g_897 && (g_506 >> ((~(g_982)) + l_4232))) - BJCJCvg_1345))))) | (~(l_4044))) - (~((~((~((BJCJCyg_76 << g_35)))))))) << ((~((~(g_2440)))) / l_3278)) | (~(((~((~(((~((BJCJCug_982 + (BJCJCxl_4232 ^ g_76)))) >> g_1345))))) && (BJCJCwg_2440 && BJCJCzg_897)))))));
goto LABEL_rBrBn;
}
if(!((g_982<=2728620929U))){
printf("g_1345=%llu\n", (unsigned long long)g_1345);
g_897 = (~(((((~((((l_4044 >> g_35) & l_4232) && ((l_3278 / g_76) >> (BJCJCzg_897 - g_1345))))) | (~(((~((BJCJCvg_1345 >> (~(g_982))))) + BJCJCug_982)))) ^ BJCJCwg_2440) - ((~((g_506 << (g_2440 << (BJCJCyg_76 + g_897))))) && (~(BJCJCxl_4232))))));
BJCJCug_982 = (~((((l_4044 ^ (((~(g_982)) << ((~((((~(g_2440)) + g_506) && (~(BJCJCzg_897))))) << (g_897 / BJCJCxl_4232))) ^ ((~(((BJCJCug_982 & BJCJCyg_76) + l_4232))) / (~(g_35))))) ^ ((BJCJCwg_2440 && BJCJCvg_1345) << ((~(g_1345)) ^ g_76))) + (~((~((~(l_3278)))))))));
goto lbl_3967;
}
if(!((BJCJCyg_76 || (l_4044 < BJCJCwg_2440)))){
printf("g_2440=%lld\n", (long long)g_2440);
BJCJCxl_4232 = (~(((~((((BJCJCxl_4232 && (~(((~(g_1345)) << (l_4232 | g_506))))) - (~((~((~((~(l_3278))))))))) & (~((((~(g_35)) + (g_76 - g_982)) - (~(g_897)))))))) && (~(((~((~((g_2440 << BJCJCug_982))))) / (((BJCJCyg_76 << BJCJCvg_1345) + (BJCJCzg_897 / l_4044)) / (~((~(BJCJCwg_2440)))))))))));
}
if(((g_897<4870) || (BJCJCzg_897 > BJCJCvg_1345))){
printf("l_4232=%llu\n", (unsigned long long)l_4232);
goto lbl_3517;
}
if((BJCJCyg_76 < g_897)){
printf("g_76=%llu\n", (unsigned long long)g_76);
goto lbl_3517;
}
if((!g_982)){
printf("g_897=%lld\n", (long long)g_897);
goto lbl_3967;
}
}
g_982 = BJCJCug_982;
g_1345 = BJCJCvg_1345;
g_2440 = BJCJCwg_2440;
l_4232 = BJCJCxl_4232;
g_76 = BJCJCyg_76;
g_897 = BJCJCzg_897;

                    if(!((l_3607 && (l_3607 < BJBJBvg_87)))){
;
g_204 = (~((((~((~((((g_9 || g_1345) || g_204) & l_4044))))) % (g_87 || BJBJBzl_4232)) | (((~((BJBJBvg_87 / l_4232))) >> (((BJBJBug_1345 | g_3486) & (~((~(l_3607))))) & (~(((BJBJBwg_3486 & (~(BJBJByl_4476))) >> (~((~((~(g_469))))))))))) ^ (~((l_4476 | BJBJBxg_204)))))));
BJBJByl_4476 = (~(((~((~((BJBJByl_4476 << (g_204 & BJBJBvg_87)))))) || (((~((~((BJBJBwg_3486 | (BJBJBug_1345 >> (~(g_87)))))))) & ((g_9 / (g_469 % l_4232)) / ((~((~(((BJBJBxg_204 >> g_1345) ^ (l_4044 / l_4476)))))) ^ l_3607))) >> (~((BJBJBzl_4232 >> g_3486)))))));
;
}
if(((g_9 > g_1345) && (g_3486<=-1))){
;
;
;
}
                                   if ((l_3887<=4294967292U))
                    if(((l_4044 > g_3486) && ((g_3486 > BJBJBwg_3486) || (g_1345 < g_87)))){
printf("g_204=%lld\n", (long long)g_204);
g_204 = (~((((~((l_3607 % (g_1345 || BJBJBwg_3486)))) % (g_3486 % l_4232)) | (((~((~(((l_4044 / ((~(l_4476)) || g_204)) || BJBJBvg_87))))) || ((~((~((~(BJBJBug_1345)))))) << ((~(g_87)) << (g_469 ^ BJBJByl_4476)))) / (~(((~(((~(BJBJBxg_204)) & BJBJBzl_4232))) >> (~((~(g_9)))))))))));

{
                        int i, j;
                        BfBfBeg_2043 = (safe_mod_func_int32_t_s_s(((BJBJBxg_204 = ((safe_div_func_int16_t_s_s(g_2580[l_4273][l_4273], l_4273)) || (safe_add_func_uint8_t_u_u((l_4273 = (safe_add_func_uint16_t_u_u(g_172, ((g_2422 , ((0x55D10309L == ((safe_div_func_int32_t_s_s((safe_div_func_int32_t_s_s((246UL < (((g_472 < (!((((j = ((65526UL & 0xCE64L) | (-10L))) ^ 0x6261DD20L) < 0x84L) & BJBJBxg_204))) != 0x9048L) <= l_4273)), BJBJByl_4476)), l_3607)) <= g_6428)) , g_6771)) >= 0xE2C7L)))), 0x0EL)))) || 0xB02CL), 2UL));
                    }

                    BJBJBug_1345 = (~((((~((g_87 % ((~(l_4044)) & (BJBJBug_1345 % l_4232))))) << ((~((~(g_204)))) ^ ((g_1345 << BJBJBxg_204) >> (~(((~(BJBJByl_4476)) << (~(g_469)))))))) % ((((((BJBJBzl_4232 / (~(BJBJBvg_87))) || l_4476) / g_3486) >> (~(g_9))) << (~(BJBJBwg_3486))) >> (~(l_3607))))));
BJBJBwg_3486 = (~((((((~((~((~(g_3486)))))) / (g_1345 >> (((BJBJByl_4476 ^ BJBJBzl_4232) | (g_469 | (~(g_87)))) >> (BJBJBwg_3486 << l_4044)))) || ((~((~(l_4476)))) >> ((~(BJBJBxg_204)) % (g_9 || (~(l_4232)))))) >> (~(((~(g_204)) || (~(BJBJBug_1345)))))) / (~((~((~((~(((~(BJBJBvg_87)) | l_3607))))))))))));
}
if((!g_469)){
printf("l_4476=%lld\n", (long long)l_4476);

{

for (BrBrBhg_573 = 0; BrBrBhg_573 < 1; BrBrBhg_573++)
        l_3230[BrBrBhg_573] = 0L;

                    for (BJBJBwg_3486 = 0; BJBJBwg_3486 < 10; BJBJBwg_3486++)
        {
            transparent_crc(g_2580[g_2440][BJBJBwg_3486], "g_2580[g_2440][BJBJBwg_3486]", BJBJByl_4476);
            if (BJBJByl_4476) printf("index = [%d][%d]\n", g_2440, BJBJBwg_3486);

        }
    }

                    BJBJBzl_4232 = (~((((~((~((~(((~(BJBJBxg_204)) & BJBJByl_4476))))))) | (((l_4232 | l_4476) >> (((BJBJBzl_4232 ^ g_204) << g_3486) | BJBJBwg_3486)) >> (~((g_1345 / BJBJBvg_87))))) << (~((~(((~((~((((~((~((l_4044 ^ (g_87 || (~(l_3607)))))))) % BJBJBug_1345) & g_469))))) << g_9))))))));
;

l_3794 += 1;


                    BJBJBwg_3486 = (~(((((g_204 % (BJBJBvg_87 ^ (~((l_4044 || BJBJByl_4476))))) >> (~(((g_1345 >> g_469) >> ((~((BJBJBzl_4232 << (~(g_9))))) >> (~((~(((l_4232 | BJBJBxg_204) / BJBJBug_1345)))))))))) || g_3486) | (~((~(((~(((~(l_3607)) ^ (~((~(BJBJBwg_3486))))))) >> (~((g_87 | l_4476)))))))))));
}
if(((!g_1345) || (l_4232>4294967294U))){
printf("l_4232=%llu\n", (unsigned long long)l_4232);
goto lbl_3517;
}
}
g_1345 = BJBJBug_1345;
g_87 = BJBJBvg_87;
                                   if (((!g_759) || (g_2440 > l_3278)))
                    g_3486 = BJBJBwg_3486;
g_204 = BJBJBxg_204;
l_4476 = BJBJByl_4476;
l_4232 = BJBJBzl_4232;

                    if ((g_2422 < l_4044) )
{



{
        for (l_3464 = 0; l_3464 < 5; l_3464++)
        {
            transparent_crc(g_3935[BfBfBcg_573][l_3464], "g_3935[BfBfBcg_573][l_3464]", l_3464);
            if (l_3464) printf("index = [%d][%d]\n", BfBfBcg_573, l_3464);

        }
    }

                    ;

                    if (g_154)
                        {

BJBJByl_4476 += 1;


                    if (l_4321)
                        goto lbl_4478;

                    goto lbl_4478;}

}
                                                        if (!(g_2440) )
{

for (p_44 = 0; p_44 < 10; p_44++)
        {
            transparent_crc(g_2580[BfBfBcg_573][p_44], "g_2580[BfBfBcg_573][p_44]", BrBrBkg_3486);
            if (BrBrBkg_3486) printf("index = [%d][%d]\n", BfBfBcg_573, p_44);

        };


}
                                                       if ((g_1352<=-1))
                    if((g_2043>485)){

for (BfBfBcg_573 = 0; BfBfBcg_573 < 4; BfBfBcg_573++)
    {
        for (l_3277 = 0; l_3277 < 9; l_3277++)
        {
            for (l_4476 = 0; l_4476 < 7; l_4476++)
            {
                transparent_crc(g_2853[BfBfBcg_573][l_3277][l_4476], "g_2853[BfBfBcg_573][l_3277][l_4476]", g_204);
                if (g_204) printf("index = [%d][%d][%d]\n", BfBfBcg_573, l_3277, l_4476);

            }
        }
    };


                    ;
g_1352 = (~(((l_4321 >> g_2043) && (((~(((~((~((~(BfBfBeg_2043)))))) & (~((g_1352 | (g_4475 | g_184))))))) * (~((~(g_1288))))) * ((~(((~((g_573 + (BfBfBdg_1288 * (~(BfBfBcg_573)))))) << ((g_2852 << BfBfBfg_184) & (g_68 + g_1368))))) + (~((~((BfBfBg_1352 % BfBfBbg_4475))))))))));

{
                    BJBJByl_4476 = (safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u((g_6029 & ((-6L) | g_35)), 8)), g_2852));
                }

                    goto lbl_3967;
}
if((((l_4321 > BfBfBdg_1288) || (g_1368>2119372678U)) && (g_4475 < g_68))){
printf("g_4475=%llu\n", (unsigned long long)g_4475);

i -= 1;


                    goto lbl_4478;
}
if(!(!((g_4475<254)))){

{
                        int16_t l_905 = 0L;
                        l_905 = (j = g_1138);
                    }

                    ;
g_573 = (~(((((BfBfBdg_1288 >> (BfBfBg_1352 && g_184)) && ((g_68 * g_1288) & ((BfBfBcg_573 << g_2852) && g_4475))) ^ (g_2043 << (~(BfBfBfg_184)))) ^ ((~((l_4321 & (~(((~(g_1352)) + g_1368)))))) + (~((((~(BfBfBbg_4475)) << g_573) && (~(BfBfBeg_2043)))))))));
goto lbl_4478;
}
if((BfBfBcg_573 < l_4321)){
printf("g_1288=%lld\n", (long long)g_1288);

g_76 += 1;


                    goto lbl_3517;
}
if(((g_1352 > l_4321) || (g_2852>245))){
printf("g_2043=%lld\n", (long long)g_2043);
BfBfBg_1352 = (~(((~(((~((BfBfBeg_2043 | (g_2043 & BfBfBg_1352)))) % (((~((g_2852 >> g_68))) * (~(l_4321))) & ((BfBfBbg_4475 ^ g_573) % g_1352))))) && ((~((~(((~((~(g_1288)))) % (~((~(((~(BfBfBcg_573)) * (g_1368 + BfBfBdg_1288))))))))))) & (BfBfBfg_184 >> ((~(g_4475)) && g_184))))));

for (p_44 = 0; p_44 < 9; p_44++)
    {

    };


                    goto lbl_3517;
}
if(!((BfBfBdg_1288<=28431))){
printf("g_184=%llu\n", (unsigned long long)g_184);
goto lbl_4478;
}
}
g_1352 = BfBfBg_1352;
                                    while ((g_1369 > l_4090) )
{

{
            uint8_t l_3689 = 0UL;
            l_3689 = 1L;
            for (g_240 = (-22); (g_240 > 14); g_240 = safe_add_func_uint8_t_u_u(g_240, 4))
            {
                g_1370[2] = i;
                return i;
            }
        }

}
                    g_4475 = BfBfBbg_4475;
                                   if ((g_472<=49))
                    g_573 = BfBfBcg_573;
g_1288 = BfBfBdg_1288;
                                   if ((((g_2467>11) || (!g_472)) || !((!g_3172))))
                    g_2043 = BfBfBeg_2043;
g_184 = BfBfBfg_184;

                    lbl_3967:
    if ((safe_sub_func_int8_t_s_s((l_3212[4] , (safe_lshift_func_uint8_t_u_u(((p_44 & p_44) == (((safe_mod_func_int16_t_s_s(l_3209, (((safe_rshift_func_int8_t_s_s(((safe_unary_minus_func_int16_t_s(g_2467)) | 9UL), ((safe_rshift_func_uint16_t_u_s((g_98[2][1] = ((l_3230[0] = (safe_add_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u((g_1369 = (safe_sub_func_int16_t_s_s((0x149AL & l_3209), g_1684[0]))), p_44)), 0x77E1L))) == l_3212[2])), 8)) && g_2580[2][6]))) || 0xE9L) & l_3212[1]))) || p_44) < 0xCAL)), 3))), p_44)))
    {
        int16_t l_3251 = 0x89D3L;
        int32_t l_3252[7] = {0L,0L,0L,0L,0L,0L,0L};
        int8_t l_3274 = (-7L);
        int16_t l_3275 = 1L;
        uint32_t l_3276 = 0xFB4D153BL;
        int8_t l_3374 = 0xD8L;
        int32_t l_3420[8][9] = {{0x87B3A4D1L,0L,(-5L),1L,1L,(-5L),0L,0x87B3A4D1L,5L},{0x87B3A4D1L,1L,5L,0x87B3A4D1L,0L,(-5L),1L,1L,(-5L)},{0x1045D443L,1L,(-1L),1L,0x1045D443L,0x0E5D44BBL,1L,(-4L),5L},{1L,0L,(-1L),(-4L),0L,5L,0L,(-4L),(-1L)},{0x1045D443L,0x1045D443L,5L,(-4L),1L,0x0E5D44BBL,0x1045D443L,1L,(-1L)},{0x87B3A4D1L,0L,(-5L),1L,1L,(-5L),0L,0x87B3A4D1L,5L},{0x87B3A4D1L,1L,5L,0x87B3A4D1L,0L,(-5L),1L,1L,(-5L)},{0x1045D443L,1L,(-1L),1L,0x1045D443L,0x0E5D44BBL,1L,(-4L),5L}};
        uint8_t l_3544[5][9][5] = {{{255UL,0xBBL,0xA8L,0x94L,8UL},{1UL,5UL,0xF4L,0xF4L,5UL},{0x83L,0xE5L,249UL,6UL,0x47L},{0x2EL,5UL,0x0AL,0UL,0x60L},{0x32L,0xE7L,0x93L,3UL,0xE7L},{0UL,249UL,1UL,0xD6L,254UL},{0x18L,0x44L,0xBBL,0x31L,0xE7L},{0x38L,0x60L,248UL,247UL,0x60L},{0UL,254UL,3UL,0x31L,0UL}},{{0xD3L,255UL,255UL,0xD6L,251UL},{0x32L,255UL,3UL,3UL,255UL},{0x5AL,249UL,248UL,0UL,254UL},{0UL,255UL,0xBBL,0x47L,0x44L},{0x38L,255UL,1UL,247UL,255UL},{0UL,254UL,0x93L,0xE5L,0UL},{0x5AL,0x60L,255UL,0xCBL,255UL},{0x32L,0x44L,0xC2L,3UL,0x44L},{0xD3L,249UL,247UL,0xCBL,254UL}},{{0UL,0xE7L,0xBBL,0xE5L,255UL},{0x38L,251UL,247UL,247UL,251UL},{0x18L,254UL,0xC2L,0x47L,0UL},{0UL,251UL,255UL,0UL,0x60L},{0x32L,0xE7L,0x93L,3UL,0xE7L},{0UL,249UL,1UL,0xD6L,254UL},{0x18L,0x44L,0xBBL,0x31L,0xE7L},{0x38L,0x60L,248UL,247UL,0x60L},{0UL,254UL,3UL,0x31L,0UL}},{{0xD3L,255UL,255UL,0xD6L,251UL},{0x32L,255UL,3UL,3UL,255UL},{0x5AL,249UL,248UL,0UL,254UL},{0UL,255UL,0xBBL,0x47L,0x44L},{0x38L,255UL,1UL,247UL,255UL},{0UL,254UL,0x93L,0xE5L,0UL},{0x5AL,0x60L,255UL,0xCBL,255UL},{0x32L,0x44L,0xC2L,3UL,0x44L},{0xD3L,249UL,247UL,0xCBL,254UL}},{{0UL,0xE7L,0xBBL,0xE5L,255UL},{0x38L,251UL,247UL,247UL,251UL},{0x18L,254UL,0xC2L,0x47L,0UL},{0UL,251UL,255UL,0UL,0x60L},{0x32L,0xE7L,0x93L,3UL,0xE7L},{0UL,249UL,1UL,0xD6L,0x2EL},{0xD8L,0UL,0xE7L,0UL,0xBDL},{0UL,255UL,0UL,0UL,255UL},{0xA5L,255UL,0x9CL,0UL,0x76L}}};
        uint8_t l_3658[1];
        int i, j, k;
        for (i = 0; i < 1; i++)
            l_3658[i] = 0x22L;
lbl_3517:
        g_2580[3][2] = g_3193;
        g_1370[2] = g_1798[3][4];
        for (g_2422 = 19; (g_2422 != 22); ++g_2422)
        {
            uint32_t l_3233 = 0x31AC0EF1L;
            uint8_t l_3238 = 0x2BL;
            uint32_t l_3271 = 0x1A71B093L;
            int32_t l_3279 = 0x4DE7E067L;
            uint16_t l_3314[8] = {0xC6D3L,0xC6D3L,0xC6D3L,0xC6D3L,0xC6D3L,0xC6D3L,0xC6D3L,0xC6D3L};
            int i;
            l_3230[0] = (l_3233 && (g_2467 == ((safe_mod_func_uint16_t_u_u((p_44 ^ (g_87 > ((0UL < ((((l_3238 , ((safe_rshift_func_uint8_t_u_s(0xA5L, (~g_68))) != (p_44 , p_44))) > 0L) , g_1352) <= g_1368)) >= 0x6755L))), g_1798[8][7])) , 0x61CA2EBDL)));
            if ((g_98[2][4] != (-9L)))
            {
                l_3279 = (((p_44 <= ((~(safe_sub_func_int8_t_s_s(((safe_lshift_func_int8_t_s_s(((l_3276 = ((safe_add_func_int16_t_s_s(((l_3252[3] = l_3251) & (g_3172 = ((safe_mod_func_uint32_t_u_u(((((safe_add_func_uint32_t_u_u(((safe_div_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((+p_44), (safe_add_func_int16_t_s_s(0x9BD4L, ((((safe_add_func_int32_t_s_s((!((safe_sub_func_int8_t_s_s((g_34[0] ^ (safe_lshift_func_int8_t_s_u(l_3271, 3))), (0x9FL ^ (7UL < (((safe_rshift_func_uint16_t_u_u(0x848AL, 8)) <= l_3233) <= l_3274))))) > (-1L))), p_44)) , p_44) || l_3275) | p_44))))), l_3230[0])) | 0L), l_3271)) <= p_44) || 0x01L) ^ l_3275), g_335)) == 0L))), g_496[0])) && l_3209)) | l_3238), 3)) >= l_3275), l_3277))) == 1UL)) != l_3278) && p_44);
                return g_98[1][3];
            }
            else
            {
                uint8_t l_3298 = 0x39L;
                l_3252[4] = (l_3298 = (safe_sub_func_uint32_t_u_u((0xAF60L <= ((safe_mod_func_uint8_t_u_u((0x53B50BCEL <= ((l_3279 || g_87) < (((safe_mod_func_uint32_t_u_u((g_1368 = (((p_44 <= (safe_lshift_func_int8_t_s_s(p_44, ((4294967287UL ^ (g_1684[0] <= ((safe_add_func_uint32_t_u_u(((safe_add_func_int16_t_s_s(l_3212[5], l_3209)) < 9UL), 0x4380B9C8L)) , 0UL))) <= 0xFDL)))) > p_44) , 0x34A561BDL)), p_44)) < 0UL) != 4294967295UL))), l_3252[6])) | g_2580[0][3])), 0x0CF43AC6L)));
            }
            l_3252[3] = ((((safe_rshift_func_uint16_t_u_s(l_3279, ((((((((p_44 || ((safe_lshift_func_int8_t_s_u(p_44, (!(safe_mod_func_int32_t_s_s((l_3230[0] = (safe_add_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s(((safe_add_func_uint16_t_u_u((((safe_div_func_int8_t_s_s(l_3314[0], 0x7FL)) ^ ((p_44 >= ((safe_add_func_uint8_t_u_u((g_2853[2][4][1] || ((((l_3230[0] , (p_44 == 0x62EB872BL)) == 4294967287UL) & 4UL) & 0x81L)), p_44)) & l_3314[0])) & g_3317)) , 1UL), p_44)) >= p_44), g_1599)), g_2422))), p_44))))) <= g_469)) | g_3172) || 0xFA99L) , l_3275) , l_3271) >= 7L) <= l_3252[3]) & 248UL))) , 0xB239F508L) & g_2422) , l_3314[0]);
            if (p_44)
            {
                int16_t l_3349 = 7L;
                int32_t l_3350 = 9L;
                int32_t l_3373 = 0x5407840EL;
                const int32_t l_3390 = (-1L);
                for (g_335 = 22; (g_335 <= 27); g_335++)
                {
                    uint32_t l_3348 = 0x7DAE833BL;
                    int32_t l_3375[3][3] = {{3L,0x55FBD205L,3L},{3L,0x55FBD205L,3L},{3L,0x55FBD205L,3L}};
                    int i, j;
                    if (((safe_rshift_func_uint16_t_u_s(g_2853[1][5][5], 15)) & ((((safe_mod_func_int32_t_s_s(p_44, (safe_sub_func_uint32_t_u_u(0xE60E50EEL, ((safe_mod_func_int32_t_s_s(p_44, (safe_sub_func_uint8_t_u_u(((((safe_add_func_int16_t_s_s((safe_add_func_uint8_t_u_u((safe_div_func_uint32_t_u_u(((safe_add_func_int16_t_s_s(((l_3279 = (l_3350 = ((g_2580[0][7] = ((safe_add_func_uint8_t_u_u(((safe_rshift_func_uint8_t_u_s(0xAEL, 7)) ^ (g_172 == (p_44 > (safe_add_func_int32_t_s_s(5L, (((safe_lshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_s((g_1684[0] = (l_3252[3] = p_44)), 7)), 13)) | l_3348) || g_98[0][1])))))), l_3348)) | l_3349)) >= g_1352))) <= l_3212[0]), g_154)) < g_2440), l_3233)), 0x63L)), g_1370[2])) || 0x62L) , p_44) != 1L), 0x0CL)))) , l_3276))))) , p_44) > p_44) != l_3233)))
                    {
                        int32_t l_3364 = (-1L);
                        l_3375[2][0] = (g_34[0] <= (safe_add_func_int32_t_s_s((safe_div_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u(((((l_3279 = l_3350) ^ (!(((safe_lshift_func_int8_t_s_s((p_44 > (g_2853[0][2][1] = (((safe_lshift_func_uint8_t_u_u(g_2467, (safe_mod_func_uint8_t_u_u((g_1369 = (l_3364 = 8UL)), (safe_rshift_func_uint16_t_u_s((((safe_add_func_uint16_t_u_u(((l_3373 = ((safe_add_func_int16_t_s_s(g_34[0], 0UL)) & (safe_sub_func_int8_t_s_s(1L, ((g_3193 || l_3348) != l_3209))))) || p_44), g_335)) && l_3238) == p_44), p_44)))))) != 0xE58EL) & 0xC46AL))), 1)) == 0xA0L) , l_3348))) | l_3274) || g_9), g_3109[0])), l_3374)), 1UL)));
                        l_3364 = (safe_add_func_uint16_t_u_u(l_3212[4], 0x82C6L));
                    }
                    else
                    {
                        int16_t l_3419 = 0L;
                        int32_t l_3421 = 0L;
                        l_3375[2][0] = (safe_lshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u(l_3252[6], (l_3421 = (((safe_rshift_func_uint16_t_u_u(0xBC67L, (g_3109[2] = (((safe_add_func_int8_t_s_s(((l_3348 && ((!(~g_496[3])) && (safe_add_func_int32_t_s_s((0UL & l_3390), ((l_3350 = ((safe_add_func_int8_t_s_s((((((safe_add_func_int32_t_s_s(((safe_div_func_uint16_t_u_u((~(safe_mod_func_int32_t_s_s((safe_div_func_uint32_t_u_u(((g_1599 = g_3317) > ((safe_sub_func_int32_t_s_s((~((((safe_add_func_uint16_t_u_u(((l_3420[3][1] = (safe_sub_func_uint32_t_u_u(((p_44 , (safe_mod_func_int8_t_s_s((safe_div_func_int32_t_s_s(((((safe_mod_func_int16_t_s_s((safe_div_func_int8_t_s_s(0xCDL, g_154)), g_204)) || 0UL) < p_44) , l_3230[0]), g_335)), 1L))) <= l_3419), l_3271))) < l_3419), p_44)) ^ 0x2AL) || 6L) | (-1L))), 1L)) == (-3L))), 4294967295UL)), p_44))), p_44)) < l_3419), 1L)) && l_3238) == p_44) & (-8L)) && 0xC27B40A8L), (-9L))) , p_44)) < 0x216C10DFL))))) & p_44), g_1369)) >= g_1352) == g_34[0])))) & 0xBCL) < 0x7787L)))), 10));
                        g_2853[0][6][6] = l_3420[3][1];
                        g_2853[0][0][4] = (l_3277 = g_335);
                    }
                    for (g_472 = 0; (g_472 <= 17); ++g_472)
                    {
                        uint16_t l_3436 = 65529UL;
                        int32_t l_3462 = 0x81AA495BL;
                        l_3420[1][3] = (0x53BE719AL | (p_44 > (((g_1684[0] = ((l_3436 = (~(safe_lshift_func_uint8_t_u_u((!(safe_rshift_func_uint8_t_u_s(((((l_3350 = (0L | (((safe_mod_func_uint32_t_u_u(p_44, (0x4C425AE9L ^ (safe_sub_func_int32_t_s_s(0x91A37324L, ((safe_rshift_func_int16_t_s_u(g_184, ((4294967293UL >= g_1345) , 0x58F6L))) , p_44)))))) , p_44) , p_44))) && 0UL) == p_44) != 0xB1B7L), p_44))), 2)))) , l_3349)) || 0xAE06L) ^ 65535UL)));
                        l_3464 = (l_3230[0] ^ ((safe_lshift_func_uint16_t_u_s(g_1138, 1)) || ((safe_div_func_uint16_t_u_u((((safe_rshift_func_int8_t_s_s((l_3277 = ((safe_rshift_func_uint16_t_u_u(p_44, 7)) < (((((-10L) ^ ((((safe_mod_func_int32_t_s_s(((safe_add_func_uint32_t_u_u((safe_mod_func_int32_t_s_s((+(safe_rshift_func_int16_t_s_u(p_44, 2))), (0UL ^ p_44))), (((safe_mod_func_uint16_t_u_u((safe_add_func_int32_t_s_s((p_44 != ((safe_rshift_func_int8_t_s_s((safe_sub_func_uint32_t_u_u((l_3462 = 0xA4AFEE0EL), g_1345)), g_1368)) | (-1L))), 0UL)), 1L)) < l_3436) && l_3375[2][2]))) , g_3172), l_3374)) >= l_3252[3]) ^ l_3276) , g_3463)) , 0xCB99L) & g_1370[2]) || 0x1C3BL))), 3)) , g_3317) | 0x55L), p_44)) <= p_44)));
                        g_2853[0][1][6] = (safe_div_func_int32_t_s_s((l_3462 = (safe_sub_func_int16_t_s_s((safe_div_func_uint8_t_u_u(0x98L, g_154)), (safe_mod_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u(((((safe_rshift_func_int8_t_s_u((g_3172 = 0x88L), ((l_3464 = (g_9 != p_44)) | (p_44 <= (safe_lshift_func_int8_t_s_s(((g_1684[0] < (g_275 >= (l_3436 ^ 0L))) , 0x62L), 7)))))) > p_44) || l_3374) >= l_3348), 6L)) < 0x459DL), l_3436))))), 0x447B2E25L));
                    }
                    if (p_44)
                        continue;
                }
                if ((safe_unary_minus_func_uint32_t_u((safe_div_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_u(((l_3350 < g_3486) , ((g_34[0] = (safe_lshift_func_int8_t_s_s(((((((g_335 || l_3238) , (g_3172 = (p_44 > (safe_add_func_uint8_t_u_u(((((g_1369 >= (safe_div_func_int8_t_s_s((+((p_44 && (g_2853[3][3][5] = (g_2580[3][8] = ((l_3230[0] | (safe_add_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(l_3373, 4)), g_352))) > p_44)))) ^ 1UL)), l_3275))) > 4294967286UL) | 0xFF0F1770L) ^ l_3314[4]), p_44))))) & p_44) || 2UL) & l_3374) , (-10L)), 6))) > p_44)), g_3109[0])) ^ 65535UL), g_76)), l_3390)))))
                {
                    int8_t l_3514 = 0xC1L;
                    uint16_t l_3515 = 3UL;
                    int32_t l_3516 = 0xEA4EE1F3L;
                    l_3420[4][8] = ((4294967288UL <= (g_1370[1] = (safe_mod_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_s(0x72L, (((safe_div_func_int16_t_s_s((safe_mod_func_uint8_t_u_u(((((l_3516 = ((l_3420[3][1] && ((0xD4L <= (g_2853[0][6][6] | p_44)) | (safe_lshift_func_uint16_t_u_s(g_35, ((safe_mod_func_uint8_t_u_u(((((safe_sub_func_int8_t_s_s((((((((safe_sub_func_uint16_t_u_u(((g_3463 = (p_44 <= g_1370[0])) > g_3172), l_3230[0])) ^ 255UL) >= p_44) , 0xE5L) > l_3514) == l_3515) < l_3390), 0x55L)) || p_44) > (-1L)) == 0x017DL), 0xA2L)) | (-10L)))))) , l_3278)) , 0x6509FBC4L) , g_1352) == 0xC69FL), l_3271)), 0x0331L)) != p_44) & p_44))), p_44)))) > p_44);
                    if (l_3420[7][1])
                        continue;
                }
                else
                {
                    if (g_2043)
                        goto lbl_3517;
                }
            }
            else
            {
                int16_t l_3543[5][9][5] = {{{0L,0xD35EL,0xE372L,(-1L),0x972BL},{1L,0x7182L,0x2441L,0x6683L,0xA6CDL},{0xD35EL,0x6683L,0xE955L,0L,0L},{1L,(-1L),1L,0L,0x9D3AL},{0xC56CL,0xE372L,0x933DL,0xD35EL,0x7182L},{0x6314L,0x6683L,6L,0L,0xC56CL},{0xFC77L,0x1CA1L,0x933DL,0x7182L,0xAC5AL},{0x972BL,(-1L),1L,0x1CA1L,0x2441L},{1L,0x972BL,0xE955L,0L,0xF7B3L}},{{0x933DL,1L,0x2441L,(-1L),0L},{0L,0x2441L,0xE372L,0x486CL,0xFC77L},{0L,3L,0xC46BL,0L,0xC56CL},{0x933DL,0x6314L,5L,0x6509L,0x1CA1L},{1L,0xA6CDL,0xA6CDL,1L,0xA535L},{0x972BL,0L,0L,0xAC5AL,0L},{0xFC77L,1L,5L,0x933DL,3L},{0x6314L,0xBB2EL,0xFC77L,0xAC5AL,0xBB2EL},{0xC56CL,0xD35EL,(-1L),1L,0x972BL}},{{1L,0x1CA1L,0x2441L,0x6509L,3L},{0xD35EL,0x6509L,0L,0L,(-1L)},{1L,(-1L),0L,0x486CL,0x9D3AL},{0L,(-1L),0x933DL,(-1L),0x1CA1L},{0x6314L,0x6509L,(-1L),0L,0L},{0xAC5AL,0x1CA1L,0x571DL,0x1CA1L,0xAC5AL},{0xBB2EL,0xD35EL,1L,0x7182L,0L},{1L,0xBB2EL,0L,0L,5L},{0x57DEL,1L,0xAD48L,0xD35EL,0L}},{{0x2441L,0L,0xE372L,0L,0xAC5AL},{0L,0xA6CDL,0xFC77L,0L,0L},{0x57DEL,0x6314L,7L,0x6683L,0x1CA1L},{(-1L),3L,0xA6CDL,(-1L),0x9D3AL},{0x972BL,0x2441L,0xA6CDL,1L,0xC46BL},{1L,0xA535L,0L,(-1L),5L},{0xFFB3L,0xA6CDL,0L,0L,0xA6CDL},{0L,0x3158L,(-5L),0L,0L},{0xA535L,0x2441L,0x57DEL,8L,5L}},{{0x3158L,8L,(-8L),0xC46BL,0xFC77L},{0xA535L,(-5L),(-1L),0xBB2EL,(-1L)},{0L,0x6509L,0xD35EL,(-1L),0x2441L},{0xFFB3L,8L,0xC46BL,0x571DL,0L},{1L,0xAD48L,0x48F3L,0x2441L,0L},{0xA6CDL,(-1L),0x9D3AL,0x2441L,0x933DL},{(-6L),0xA6CDL,(-8L),0x571DL,(-1L)},{(-1L),(-1L),0x571DL,(-1L),0x571DL},{0x933DL,0x933DL,0x6683L,0xBB2EL,1L}}};
                int32_t l_3563 = 1L;
                int32_t l_3578[8] = {9L,9L,9L,9L,9L,9L,9L,9L};
                uint32_t l_3610[9][7] = {{1UL,1UL,1UL,1UL,1UL,1UL,1UL},{4294967295UL,0UL,4294967295UL,4294967295UL,0UL,4294967295UL,4294967295UL},{1UL,1UL,1UL,1UL,1UL,1UL,1UL},{0UL,4294967295UL,4294967295UL,0UL,4294967295UL,4294967295UL,0UL},{1UL,1UL,1UL,1UL,1UL,1UL,1UL},{0UL,0UL,1UL,0UL,0UL,1UL,0UL},{1UL,1UL,1UL,1UL,1UL,1UL,1UL},{4294967295UL,0UL,4294967295UL,4294967295UL,0UL,4294967295UL,4294967295UL},{1UL,1UL,1UL,1UL,1UL,1UL,1UL}};
                int i, j, k;
                if ((g_154 != g_472))
                {
                    uint8_t l_3522[9] = {1UL,1UL,1UL,1UL,1UL,1UL,1UL,1UL,1UL};
                    int32_t l_3539 = (-1L);
                    int16_t l_3597 = (-7L);
                    int16_t l_3657 = 0xFBA8L;
                    int i;
                    for (l_3276 = 4; (l_3276 != 57); l_3276 = safe_add_func_int16_t_s_s(l_3276, 6))
                    {
                        l_3252[3] = 0L;
                        g_2580[0][7] = (safe_sub_func_int32_t_s_s(l_3252[3], p_44));
                        l_3522[7] = 8L;
                    }
                    if ((safe_lshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(((p_44 | (((((safe_lshift_func_uint16_t_u_u(((g_1684[0] = p_44) & ((safe_div_func_uint16_t_u_u(((((l_3279 = (safe_mod_func_uint32_t_u_u((3L < ((safe_unary_minus_func_int32_t_s(l_3464)) == g_1288)), ((safe_sub_func_uint16_t_u_u((safe_unary_minus_func_int32_t_s((0x8367C925L < (safe_sub_func_int32_t_s_s(((l_3539 = p_44) && (safe_lshift_func_int8_t_s_u((((l_3543[1][5][3] = (+6L)) , ((((-1L) == p_44) == p_44) || l_3230[0])) < p_44), 1))), 7UL))))), p_44)) ^ l_3544[4][0][3])))) || g_68) >= g_2467) & p_44), p_44)) < g_469)), 12)) , g_2440) || 0x38L) >= 0x243FL) , l_3543[1][5][3])) | 1UL), p_44)), 11)))
                    {
                        uint32_t l_3550 = 0x43FE2EC4L;
                        int32_t l_3562 = 6L;
                        l_3563 = (!((((((safe_rshift_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_u(p_44, (l_3550 = g_472))) & 0xF3F658A3L) == ((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_s(((~1L) && (((g_2853[0][6][6] = (((safe_unary_minus_func_uint16_t_u(((safe_sub_func_int16_t_s_s(g_2853[0][6][6], (+(g_2422 <= (safe_rshift_func_uint8_t_u_s((g_2852 || ((0L || g_1288) < g_98[2][1])), 6)))))) , l_3543[4][8][4]))) || g_3172) >= l_3562)) , l_3271) | 0xDCL)), 9)), 0UL)) || g_1599)), g_1345)) != l_3314[4]) & p_44) && 1UL) , 0L) ^ 8UL));
                        l_3562 = (l_3578[2] = (safe_div_func_uint32_t_u_u(((((((safe_sub_func_uint16_t_u_u(g_3317, ((g_1345 && (safe_div_func_int16_t_s_s(0xED8FL, ((g_98[1][3] , (l_3563 = 18446744073709551607UL)) , 0xD047L)))) && (safe_add_func_int8_t_s_s((-1L), (((safe_add_func_int8_t_s_s((g_154 = (safe_add_func_int8_t_s_s(g_34[0], (safe_mod_func_int16_t_s_s(0x62C8L, p_44))))), l_3238)) & l_3230[0]) ^ g_2853[3][7][5])))))) >= g_2580[0][7]) & g_204) != g_3317) , 0x795FL) , 0x2A7BF1E7L), 0x242AB39AL)));
                        l_3279 = g_35;
                        return g_2440;
                    }
                    else
                    {
                        l_3420[0][7] = (2L <= (safe_rshift_func_uint8_t_u_u(g_76, g_1370[2])));
                    }
                    if (g_76)
                    {
                        l_3420[3][1] = (l_3252[3] = (g_1370[2] = ((((l_3539 = (safe_rshift_func_int16_t_s_u(((((g_3172 = (safe_rshift_func_uint8_t_u_u(l_3522[7], g_2853[0][6][6]))) == p_44) | ((safe_add_func_uint32_t_u_u(l_3420[3][1], (safe_add_func_int32_t_s_s(((l_3252[5] & 0xB5F97AF9L) != (safe_lshift_func_int8_t_s_s(1L, 7))), (safe_rshift_func_int8_t_s_s((safe_add_func_uint8_t_u_u(p_44, ((safe_add_func_int8_t_s_s(g_2422, l_3522[4])) , p_44))), p_44)))))) <= 4UL)) & l_3597), 15))) == g_2852) <= p_44) > g_573)));
                    }
                    else
                    {
                        int16_t l_3634[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_3634[i] = 0x1B6AL;
                        l_3578[2] = (safe_add_func_uint8_t_u_u((g_3600 ^ (safe_add_func_uint8_t_u_u((safe_add_func_int32_t_s_s((safe_add_func_uint32_t_u_u(g_2580[0][7], (l_3607 < (safe_mod_func_uint32_t_u_u(((l_3464 , ((l_3314[3] >= (l_3539 = 0x7EL)) || (l_3610[8][5] | (safe_div_func_int32_t_s_s((-10L), ((g_1345 = ((p_44 , 65535UL) , g_172)) || p_44)))))) && 0x35CBL), 0x9A07E162L))))), l_3277)), g_1798[5][2]))), l_3278));
                        if (p_44)
                            goto lbl_3517;
                        l_3539 = (p_44 > ((((safe_unary_minus_func_uint16_t_u((safe_rshift_func_int16_t_s_u((g_1352 = (safe_mod_func_uint16_t_u_u(g_2422, (safe_lshift_func_int16_t_s_s((safe_sub_func_int16_t_s_s((safe_mod_func_uint8_t_u_u((((l_3314[0] == ((safe_add_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_u(1UL, p_44)), (g_496[1] >= (safe_add_func_uint16_t_u_u(((l_3464 = (safe_sub_func_int32_t_s_s(((l_3314[4] ^ l_3522[4]) && ((l_3420[3][1] = l_3209) | l_3563)), 0UL))) ^ l_3610[8][5]), l_3634[2]))))) | l_3597)) & g_1370[2]) & 0x5AB4L), p_44)), 0xD1F5L)), l_3539))))), 15)))) & l_3204[1]) & l_3522[4]) != l_3276));
                        g_2853[2][4][5] = (((safe_add_func_int8_t_s_s((safe_mod_func_int16_t_s_s(((safe_rshift_func_int8_t_s_s(p_44, ((safe_sub_func_uint8_t_u_u(((safe_add_func_uint32_t_u_u(((safe_div_func_int8_t_s_s((((l_3271 && g_1599) , (safe_add_func_uint16_t_u_u((safe_add_func_int32_t_s_s((g_2580[1][4] = (-1L)), 7UL)), (l_3230[0] = 0x8164L)))) , ((l_3658[0] = ((safe_sub_func_int32_t_s_s(((((0x05L | ((safe_sub_func_uint32_t_u_u((safe_mod_func_int8_t_s_s((p_44 <= p_44), g_1370[2])), l_3657)) || p_44)) > 0L) < p_44) , g_98[3][0]), g_154)) , 0x04AA69F6L)) , g_472)), 0xB1L)) | g_9), l_3314[0])) >= 0L), l_3374)) && p_44))) < p_44), p_44)), l_3271)) >= 4294967295UL) > 4294967291UL);
                    }
                    for (l_3238 = 0; (l_3238 == 24); ++l_3238)
                    {
                        int8_t l_3665[5][10][5] = {{{0xF1L,0x42L,0x42L,0xF1L,(-1L)},{0xF1L,0x42L,0x42L,0xF1L,(-1L)},{0xF1L,0x42L,0x42L,0xF1L,(-1L)},{0xF1L,0x42L,0x42L,0xF1L,(-1L)},{0xF1L,0x42L,0x42L,0xF1L,(-1L)},{0xF1L,0x42L,0x42L,0xF1L,(-1L)},{0xF1L,0x42L,0x42L,0xF1L,(-1L)},{0xF1L,0x42L,0x42L,0xF1L,(-1L)},{0xF1L,0x42L,0x42L,0xF1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L}},{{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L}},{{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L}},{{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L}},{{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{1L,0xF1L,0xF1L,1L,0x26L},{(-1L),1L,1L,(-1L),0x42L},{(-1L),1L,1L,(-1L),0x42L},{(-1L),1L,1L,(-1L),0x42L}}};
                        int i, j, k;
                        l_3539 = ((safe_add_func_int32_t_s_s(((((((l_3610[8][5] <= ((safe_sub_func_int8_t_s_s((g_573 <= p_44), (l_3271 ^ ((g_982 , g_3463) , 0x7BL)))) >= ((4294967292UL <= (l_3665[1][8][1] , p_44)) || l_3665[2][3][1]))) | g_1370[2]) ^ l_3212[4]) || p_44) && (-8L)) ^ g_1288), l_3252[0])) > 0xCA21D270L);
                    }
                }
                else
                {
                    int32_t l_3670 = 0xF591201DL;
                    int32_t l_3686 = 0x97BEDB9DL;
                    for (g_472 = 0; (g_472 <= 0); g_472 += 1)
                    {
                        int i;
                        l_3230[0] = (((safe_add_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s((l_3670 = (g_34[g_472] < g_34[0])), (safe_lshift_func_int8_t_s_u((((g_87 = (safe_mod_func_uint32_t_u_u(4294967295UL, (safe_rshift_func_uint16_t_u_s(((g_204 && (safe_lshift_func_uint8_t_u_u((l_3578[6] >= ((safe_div_func_uint16_t_u_u((safe_mod_func_int8_t_s_s((((+(g_76 = 0xA55B8ACAL)) <= (safe_add_func_uint32_t_u_u((l_3686 = l_3276), (((g_1368 <= (!1L)) <= p_44) & 3L)))) == g_275), g_34[g_472])), g_1138)) & g_573)), 4))) > (-10L)), 6))))) < g_2422) == g_2853[3][3][0]), p_44)))) | 0x7747L), 0x22E1L)) > g_34[g_472]) & g_2852);
                        if (g_982)
                            goto lbl_3688;
                    }
                    if (g_759)
                        goto lbl_3517;
                }
            }
        }
    }
    else
    {
        uint8_t l_3694[2];
        uint8_t l_3709 = 0xABL;
        int32_t l_3765 = 0x33801A11L;
        uint16_t l_3770 = 0x0E73L;
        int32_t l_3814[5];
        int i;
        for (i = 0; i < 2; i++)
            l_3694[i] = 0xA2L;
        for (i = 0; i < 5; i++)
            l_3814[i] = 0xF493DF09L;
        if (g_573)
        {
            uint8_t l_3689 = 0UL;
            l_3689 = 1L;
            for (l_3277 = (-22); (l_3277 > 14); l_3277 = safe_add_func_uint8_t_u_u(l_3277, 4))
            {
                g_1370[2] = g_204;
                return p_44;
            }
        }
        else
        {
            uint8_t l_3705 = 251UL;
            uint32_t l_3706 = 0UL;
            uint32_t l_3739 = 0x898F2601L;
            int16_t l_3778 = 0xB16BL;
            int8_t l_3812 = 0x9CL;
            int32_t l_3815 = 0xCF04AE1EL;
            int32_t l_3866 = 2L;
            if (((safe_add_func_uint32_t_u_u(((4UL && (p_44 , (((l_3694[1] | ((safe_sub_func_int16_t_s_s((p_44 | ((255UL == ((((((-7L) & (safe_div_func_uint16_t_u_u(((l_3464 == ((safe_sub_func_int8_t_s_s(((((safe_mod_func_uint32_t_u_u(((((((((0x99A5FCF5L ^ (p_44 & 4294967295UL)) , 0x6DC1A55DL) || l_3705) | g_3463) == p_44) == 8L) , l_3705) ^ l_3706), 0x0533C7EFL)) <= p_44) >= l_3706) , 0x85L), g_1684[0])) , 0x9DA30156L)) ^ l_3230[0]), g_1798[1][2]))) < 0x55L) , 65535UL) <= l_3204[1]) ^ l_3706)) < 0xDAA1L)), p_44)) , l_3230[0])) & 0x9D3E77C2L) || p_44))) != 0xC1D6C0E9L), g_2043)) ^ p_44))
            {
                uint32_t l_3730 = 0xA356F701L;
                for (g_759 = 0; (g_759 <= 17); g_759 = safe_add_func_int8_t_s_s(g_759, 8))
                {
                    uint32_t l_3729[5];
                    int i;
                    for (i = 0; i < 5; i++)
                        l_3729[i] = 0x174C6A9DL;
                    if ((g_1352 , l_3709))
                    {
                        int32_t l_3727 = 0x71EAE63EL;
                        int16_t l_3728 = 0L;
                        l_3727 = ((((safe_mod_func_int16_t_s_s(((safe_div_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_u(p_44, 3)) <= (l_3694[0] & (safe_unary_minus_func_uint16_t_u((safe_sub_func_int32_t_s_s((((((g_2467 > ((g_275 < (safe_rshift_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u(((safe_sub_func_uint32_t_u_u((p_44 | ((6UL == g_184) < (g_240 == (g_3600 >= g_1684[0])))), l_3727)) < l_3728), 5)), 2))) >= l_3729[2])) ^ l_3212[4]) | 0x0AB4L) , l_3277) && l_3730), g_34[0])))))), p_44)) | p_44), 5L)) != g_2043) & p_44) & p_44);
                    }
                    else
                    {
                        if (p_44)
                            break;
                    }
                    if (l_3729[1])
                        continue;
                    if (g_3463)
                        continue;
                    if (g_982)
                        goto lbl_3688;
                }
                return l_3694[1];
            }
            else
            {
                if (g_184)
                    goto lbl_3688;
            }
            g_204 = ((safe_div_func_int32_t_s_s((0x38L && (g_3172 = (((safe_sub_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_s(g_2580[0][7], (((l_3739 < l_3694[1]) ^ ((safe_lshift_func_int8_t_s_s(p_44, ((1UL >= 0x09L) , (safe_add_func_uint16_t_u_u(l_3706, 0L))))) >= p_44)) != l_3694[1]))), l_3607)) < p_44) < 65535UL))), g_1288)) , 0xF0EC3F2DL);
            for (g_1288 = 0; (g_1288 > 3); g_1288 = safe_add_func_int32_t_s_s(g_1288, 2))
            {
                uint8_t l_3771 = 0x3EL;
                int32_t l_3772 = 0x836E7E63L;
                uint32_t l_3827 = 4294967295UL;
                l_3771 = ((safe_sub_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u((((((((safe_add_func_int32_t_s_s(2L, ((g_98[1][3] = ((safe_add_func_uint16_t_u_u(65527UL, 0x2CA3L)) | (safe_rshift_func_uint16_t_u_u(((safe_div_func_int16_t_s_s(g_2580[0][7], (safe_lshift_func_int16_t_s_s((((p_44 | (((!(g_184 = p_44)) == g_1345) != (safe_lshift_func_int16_t_s_u((((((l_3765 = (safe_rshift_func_int16_t_s_s(l_3230[0], 9))) >= ((safe_lshift_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_u(l_3770, 13)) ^ p_44), g_240)) , l_3694[1])) , g_3109[2]) && 0x1460715CL) == (-2L)), 8)))) & l_3770) , 0xF4F2L), g_496[2])))) && (-6L)), g_240)))) >= p_44))) || 1UL) , g_3600) | g_506) | p_44) == g_3109[0]) | 4UL), l_3706)), p_44)) ^ (-4L));
                if ((l_3705 & g_1599))
                {
                    uint32_t l_3773 = 0xDE23EB3AL;
                    for (g_3172 = 0; (g_3172 <= 2); g_3172 += 1)
                    {
                        uint32_t l_3777 = 0x65B9FE36L;
                        l_3772 = g_3109[1];
                        l_3778 = (l_3773 , (safe_rshift_func_int16_t_s_s((p_44 | p_44), (!l_3777))));
                    }
                }
                else
                {
                    uint16_t l_3795 = 5UL;
                    if ((safe_mod_func_uint16_t_u_u(((safe_mod_func_uint16_t_u_u((1L ^ (+(safe_sub_func_int32_t_s_s((safe_sub_func_int32_t_s_s(((safe_rshift_func_uint16_t_u_u(((l_3765 = 8UL) , (249UL >= 253UL)), (safe_sub_func_int32_t_s_s((g_1370[2] = ((255UL <= (safe_mod_func_int32_t_s_s(((l_3794 || ((((l_3230[0] = p_44) & g_1370[0]) >= (p_44 & 4294967288UL)) > 0xDF5487C4L)) & p_44), p_44))) == g_3109[0])), g_1345)))) & 0xEF16101AL), l_3778)), g_3317)))), 1UL)) <= 7L), 0xB154L)))
                    {
                        return g_2580[0][7];
                    }
                    else
                    {
                        int32_t l_3813 = 0x4D7A9F40L;
                        l_3815 = ((((((l_3795 , (~(safe_div_func_uint32_t_u_u(g_3463, (l_3814[3] = (safe_lshift_func_int8_t_s_u((safe_add_func_int8_t_s_s((0x06D7A64AL > l_3803[0][1]), p_44)), ((((((l_3813 = ((safe_rshift_func_uint16_t_u_u((l_3765 = ((safe_lshift_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s(((l_3795 && (safe_sub_func_uint16_t_u_u((l_3812 > ((((p_44 , g_352) < g_34[0]) | p_44) & 0xE2DDL)), 0x5F8CL))) , g_1370[0]), l_3771)) != 0xE4CF1F7AL) ^ l_3813), l_3739)) || 0xC44EL)), 12)) >= (-9L))) <= l_3771) , 0UL) == g_2467) & 8L) && 0xE16BL)))))))) , g_98[2][4]) < 0x973F48CCL) , l_3204[0]) > l_3812) , g_1684[0]);
                        g_1370[2] = (((safe_sub_func_int8_t_s_s(0x76L, (((((safe_sub_func_int16_t_s_s((4294967287UL == ((((g_3172 = ((l_3827 = ((((safe_add_func_int8_t_s_s((safe_div_func_uint32_t_u_u((g_184 , 0UL), (((((g_1352 || p_44) , (safe_mod_func_int32_t_s_s(p_44, (-4L)))) == ((+l_3813) >= p_44)) != 0xD0L) && 0x77185750L))), 0x53L)) , 0x00L) >= l_3772) ^ g_2580[3][7])) | 0xCAL)) && p_44) , (-3L)) == 1UL)), p_44)) & p_44) < l_3770) ^ g_240) , p_44))) > 0x3C68L) & 0x4628L);
                    }
                    for (l_3795 = 0; (l_3795 <= 0); l_3795 += 1)
                    {
                        int i, j;
                        return l_3803[l_3795][l_3795];
                    }
                }
                for (l_3778 = 0; (l_3778 < (-3)); l_3778--)
                {
                    uint32_t l_3846 = 0x0FCB872DL;
                    int32_t l_3861[9][3][9] = {{{0x4A9CC8A5L,(-8L),0x02DD7A8AL,(-10L),1L,7L,0x6B9A2241L,7L,1L},{0xA264E88CL,0x3ADDE6BAL,0x3ADDE6BAL,0xA264E88CL,0x01C2EBA1L,(-9L),0x31F9D61DL,1L,0x734A3A90L},{0x9EDBA2DFL,0xB6B7D625L,0x71B03E50L,0xAD9D3F4BL,0xD0517D56L,0xFA68401DL,1L,1L,(-8L)}},{{0xBC2F20CAL,0x31F9D61DL,(-10L),(-1L),0x01C2EBA1L,1L,(-1L),0x7A65FFEFL,0xCD12CA5CL},{0x71B03E50L,0x7524BDF4L,0L,0xD0CF8322L,1L,0x6B9A2241L,(-1L),(-1L),0x6B9A2241L},{(-1L),8L,1L,8L,(-1L),0xA264E88CL,0xB851A410L,0L,(-1L)}},{{0xD0CF8322L,0x02DD7A8AL,0x9EDBA2DFL,1L,(-10L),(-1L),0x9F3CA17CL,(-8L),0x71B03E50L},{0L,0x69F49F49L,0x2E0C0317L,0x0196139EL,(-4L),0xA264E88CL,(-2L),(-5L),0xB851A410L},{1L,0xEE0D27B1L,0xE0551176L,0x037F553CL,0xFA68401DL,0x6B9A2241L,1L,0L,1L}},{{1L,5L,0xC88F11FFL,0xC88F11FFL,5L,1L,0xF9AE201BL,(-1L),(-5L)},{1L,0x9F3CA17CL,(-10L),0L,0x914C589FL,0xFA68401DL,(-8L),0x6B9A2241L,3L},{0x69F49F49L,0x7A65FFEFL,5L,(-1L),(-2L),(-9L),0xF9AE201BL,0xA7C93FD2L,(-4L)}},{{0xAD9D3F4BL,0x6B9A2241L,(-8L),0x9433BDB1L,(-4L),7L,1L,0xEE0D27B1L,0xEE0D27B1L},{(-2L),(-3L),(-1L),0L,(-1L),(-3L),(-2L),(-1L),0x01C2EBA1L},{1L,0xF9BE9EE4L,0xEE0D27B1L,0x71B03E50L,(-5L),(-8L),0x9F3CA17CL,0L,0x4A9CC8A5L}},{{(-9L),0xA7C93FD2L,0xCD12CA5CL,0x31F9D61DL,0xA264E88CL,(-1L),0xB851A410L,(-1L),0xC88F11FFL},{0xE0551176L,0L,0x196074E6L,3L,0xD0CF8322L,0x71B03E50L,(-1L),0xEE0D27B1L,0xB6B7D625L},{0xA7C93FD2L,(-1L),6L,0x2E0C0317L,0x2E0C0317L,6L,(-1L),0xA7C93FD2L,0x69F49F49L}},{{(-8L),0xAD9D3F4BL,3L,0xF9BE9EE4L,(-1L),(-10L),1L,0x6B9A2241L,0xE181A45EL},{(-1L),0xBC2F20CAL,0L,(-1L),1L,0x2E0C0317L,0x46847825L,(-3L),0x06DEA3CBL},{(-4L),0x7524BDF4L,0xAD9D3F4BL,0x9F3CA17CL,0x914C589FL,0xE0551176L,0x9433BDB1L,(-8L),(-10L)}},{{0xA264E88CL,0x0196139EL,(-2L),0xC88F11FFL,(-1L),0xC88F11FFL,(-2L),0x0196139EL,0xA264E88CL},{0x02DD7A8AL,0L,1L,0x7524BDF4L,0x4A9CC8A5L,(-10L),0xE0551176L,(-1L),0xAD9D3F4BL},{0xA7C93FD2L,0xF9AE201BL,(-9L),(-2L),(-1L),5L,0x7A65FFEFL,0x69F49F49L,(-1L)}},{{0x02DD7A8AL,0x4A9CC8A5L,0xE0551176L,1L,1L,(-8L),0L,(-5L),0xD0CF8322L},{0xA264E88CL,8L,0xA7C93FD2L,(-1L),(-1L),(-1L),(-1L),0xA7C93FD2L,8L},{(-4L),1L,(-8L),0x02DD7A8AL,(-1L),0xEE0D27B1L,0L,3L,1L}}};
                    int32_t l_3886 = 0xB5571592L;
                    int i, j, k;
                    for (g_2440 = 0; (g_2440 <= 7); g_2440 += 1)
                    {
                        int32_t l_3883 = 9L;
                        int i, j;
                        g_2580[0][2] = ((l_3815 = g_1798[g_2440][g_2440]) >= (safe_rshift_func_int8_t_s_u(((safe_mod_func_uint8_t_u_u((safe_div_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(((g_87 = ((((safe_div_func_uint8_t_u_u(((l_3866 = (((g_1798[(g_2440 + 1)][g_2440] && (g_1798[(g_2440 + 1)][g_2440] , (l_3705 , ((safe_mod_func_uint8_t_u_u((g_2852 = (safe_rshift_func_int8_t_s_s((safe_sub_func_int16_t_s_s(((l_3846 = 4294967289UL) != (safe_rshift_func_int8_t_s_u((safe_mod_func_int16_t_s_s((p_44 < (((safe_mod_func_int32_t_s_s(((safe_div_func_int8_t_s_s(g_1798[(g_2440 + 1)][g_2440], (safe_mod_func_uint16_t_u_u(((safe_mod_func_uint32_t_u_u((safe_add_func_int32_t_s_s(((((l_3861[7][0][7] = 0xAB867F8AL) <= (safe_div_func_uint16_t_u_u((safe_add_func_int32_t_s_s((l_3705 ^ g_98[1][3]), 1L)), p_44))) , g_2467) || g_335), g_2440)), g_76)) != g_1684[0]), 0x74DEL)))) , l_3705), l_3778)) && 0x892CL) ^ 65532UL)), g_3486)), 4))), g_1798[(g_2440 + 1)][g_2440])), 5))), g_897)) >= l_3771)))) != 0xF322L) || 0x1F68L)) != 0x6FL), (-1L))) == 0xF43CL) ^ 0x787EDD2CL) && l_3812)) | 255UL), g_2580[0][7])), 0xAEC21927L)), p_44)) >= p_44), 4)));
                        g_1370[1] = (((safe_add_func_uint32_t_u_u((safe_add_func_uint16_t_u_u(((g_352 < (safe_add_func_uint16_t_u_u((l_3772 > ((((safe_lshift_func_int8_t_s_s(0L, 2)) >= ((0x77L | ((safe_mod_func_int16_t_s_s((safe_rshift_func_int8_t_s_u(((!((safe_sub_func_int32_t_s_s(((((l_3883 = ((+p_44) , g_2043)) == (safe_div_func_int16_t_s_s(p_44, l_3794))) != ((l_3866 = p_44) == g_472)) & 0xBCL), l_3694[1])) & g_1684[0])) ^ g_759), 0)), l_3765)) <= l_3278)) == 65535UL)) & 9L) , 0xCCFDL)), g_3486))) < 0xE5045A56L), l_3886)), p_44)) || l_3887) < g_1798[5][2]);
                    }
                }
            }
            l_3815 = (safe_rshift_func_uint8_t_u_u((g_472 = ((safe_rshift_func_int8_t_s_s((!(g_1288 = ((((249UL <= g_3600) > (g_240 == (safe_sub_func_int8_t_s_s((((l_3230[0] = ((safe_div_func_uint16_t_u_u(((g_3109[0] = p_44) == (safe_mod_func_int8_t_s_s(0L, (g_2852 | ((safe_mod_func_uint16_t_u_u(((g_34[0] = (safe_lshift_func_int16_t_s_u(g_335, (p_44 || ((safe_div_func_uint32_t_u_u((0xB3L ^ p_44), 0x9B88431FL)) < 0x3338L))))) <= 0xC8L), p_44)) && g_496[2]))))), 0x9FD6L)) >= 0x48E2L)) || 8L) , l_3803[0][1]), l_3709)))) , p_44) >= p_44))), 3)) & p_44)), 5));
        }
    }
lbl_4478:
    for (g_3172 = 0; (g_3172 <= (-14)); g_3172 = safe_sub_func_uint8_t_u_u(g_3172, 8))
    {
        uint32_t l_3911[9] = {1UL,1UL,1UL,1UL,1UL,1UL,1UL,1UL,1UL};
        int32_t l_3948 = 6L;
        int i;
        for (g_2852 = 0; (g_2852 <= 2); g_2852 += 1)
        {
            uint32_t l_3914 = 0x0A62ABD5L;
            uint8_t l_3962 = 0xAFL;
            uint8_t l_4022 = 2UL;
            int32_t l_4023 = 0x83182F71L;
            uint16_t l_4114[5][6] = {{65535UL,65535UL,0xA748L,0xA748L,65535UL,65535UL},{65535UL,0xA748L,0xA748L,65535UL,65535UL,0xA748L},{65535UL,65535UL,0xA748L,0xA748L,65535UL,65535UL},{65535UL,0xA748L,0xA748L,65535UL,65535UL,0xA748L},{65535UL,65535UL,0xA748L,0xA748L,65535UL,65535UL}};
            int16_t l_4133[6] = {(-1L),0x8FBCL,(-1L),(-1L),0x8FBCL,(-1L)};
            int i, j;
            l_3911[0] = ((safe_mod_func_uint16_t_u_u((((g_1370[g_2852] || g_1370[g_2852]) && (g_1370[g_2852] , 0UL)) || (l_3607 >= 0x4FL)), g_2422)) > (safe_lshift_func_uint16_t_u_s(g_1352, 3)));
            if ((g_1370[g_2852] > (g_1370[g_2852] < ((safe_mod_func_int16_t_s_s(l_3914, ((l_3911[0] == ((safe_div_func_uint16_t_u_u(((((((0xACF8L != (((l_3914 , (safe_lshift_func_int16_t_s_s((((safe_lshift_func_uint16_t_u_s((safe_mod_func_int16_t_s_s(((l_3204[0] == (1UL | (p_44 , g_759))) == 0xB6L), l_3911[7])), g_1370[g_2852])) >= 0x2AL) ^ 0xFAL), 0))) && p_44) && g_1370[g_2852])) && p_44) ^ g_68) <= 0UL) ^ l_3278) & g_204), g_2043)) | l_3803[0][0])) , p_44))) , 0x41L))))
            {
                int8_t l_3936 = (-1L);
                int32_t l_3945[3][7] = {{(-1L),0x098C8E7EL,(-1L),(-1L),0x098C8E7EL,(-1L),0x098C8E7EL},{0L,(-1L),(-1L),0L,0x098C8E7EL,0L,(-1L)},{1L,1L,(-1L),(-1L),(-1L),1L,1L}};
                int32_t l_3950[2][8][5] = {{{0x1B138628L,(-1L),(-10L),(-1L),0x1B138628L},{0xA2F7BFCFL,1L,0x521F5C0AL,0x237FC685L,0xA2F7BFCFL},{0x952DE3C7L,(-1L),(-1L),(-1L),0x952DE3C7L},{0xA2F7BFCFL,0x237FC685L,0x521F5C0AL,1L,0xA2F7BFCFL},{0x1B138628L,(-1L),(-10L),(-1L),0x1B138628L},{0xA2F7BFCFL,1L,0x521F5C0AL,0x237FC685L,0xA2F7BFCFL},{0x952DE3C7L,(-1L),(-1L),(-1L),0x952DE3C7L},{0xA2F7BFCFL,0x237FC685L,0x521F5C0AL,1L,0xA2F7BFCFL}},{{0x1B138628L,(-1L),(-10L),(-1L),0x1B138628L},{0xA2F7BFCFL,1L,0x521F5C0AL,0x237FC685L,0xA2F7BFCFL},{0x952DE3C7L,(-1L),(-1L),(-1L),0x952DE3C7L},{0xA2F7BFCFL,0x237FC685L,0x15CDBCF7L,2L,0x237FC685L},{(-2L),0xC6CFC406L,0x3C14CD7EL,0xC6CFC406L,(-2L)},{0x237FC685L,2L,0x15CDBCF7L,0x21F454D6L,0x237FC685L},{4L,0xC6CFC406L,0x2AAAF7BFL,0xC6CFC406L,4L},{0x237FC685L,0x21F454D6L,0x15CDBCF7L,2L,0x237FC685L}}};
                int16_t l_4033 = (-1L);
                int8_t l_4115 = 2L;
                int i, j, k;
                if (p_44)
                {
                    int16_t l_3949[1];
                    int i;
                    for (i = 0; i < 1; i++)
                        l_3949[i] = 0x5E55L;
                    g_2853[0][6][6] = (safe_add_func_uint16_t_u_u(((g_1352 = (safe_lshift_func_uint16_t_u_u(g_1684[0], l_3204[1]))) < (0x4935L < 0x9949L)), (((p_44 ^ (safe_div_func_uint32_t_u_u((((safe_rshift_func_int16_t_s_s((((g_35 & (g_240 >= (safe_rshift_func_int8_t_s_s((-1L), 7)))) || ((g_172 = g_98[1][1]) , g_3935[3][2])) && g_2580[3][9]), 13)) == l_3914) == 0xF6L), p_44))) , l_3936) , p_44)));
                    l_3950[1][1][0] = (((p_44 != (l_3948 = (safe_rshift_func_int16_t_s_s(((safe_sub_func_int16_t_s_s(((g_2467 & (g_1370[g_2852] = (safe_div_func_int16_t_s_s(1L, ((l_3945[1][2] = (p_44 | (safe_sub_func_uint32_t_u_u(g_2580[0][7], (p_44 | (-10L)))))) | (safe_mod_func_int8_t_s_s(0x9AL, ((4294967295UL > 4294967295UL) , 0x46L)))))))) != p_44), 0UL)) , l_3945[1][2]), p_44)))) != 4UL) && l_3949[0]);
                }
                else
                {
                    int32_t l_3976 = 1L;
                    int32_t l_3979 = 0L;
                    for (l_3209 = 0; (l_3209 >= 29); l_3209 = safe_add_func_int32_t_s_s(l_3209, 9))
                    {
                        uint8_t l_3963[4];
                        int32_t l_3964 = 0L;
                        int i;
                        for (i = 0; i < 4; i++)
                            l_3963[i] = 255UL;
                        l_3964 = (safe_add_func_uint16_t_u_u((l_3911[8] == ((safe_unary_minus_func_int16_t_s((-1L))) | (((l_3963[2] = ((safe_lshift_func_uint16_t_u_u((((safe_add_func_int32_t_s_s(0x042EF43CL, p_44)) != (((safe_add_func_int16_t_s_s(((p_44 != l_3945[1][2]) | l_3962), (((p_44 == (g_496[1] != 5L)) >= 255UL) | 2L))) != l_3950[1][3][1]) || 6UL)) | 1UL), g_3935[4][0])) | 0xC54B21BCL)) > l_3911[0]) == 0x68L))), l_3950[0][6][4]));
                    }
                    for (g_172 = 0; (g_172 >= 44); ++g_172)
                    {
                        uint32_t l_3984 = 18446744073709551611UL;
                        if (g_1599)
                            goto lbl_3688;
                        if (g_3172)
                            goto lbl_3967;
                        g_204 = ((g_1370[g_2852] = ((((safe_sub_func_int16_t_s_s(((g_35 ^ p_44) ^ (safe_rshift_func_uint8_t_u_u(((g_1684[0] >= (safe_rshift_func_uint8_t_u_u(g_184, (safe_lshift_func_int8_t_s_u((((((((((l_3976 = g_3935[1][1]) , p_44) < 4294967286UL) , (0x6040B6EAL || ((safe_div_func_uint8_t_u_u(p_44, (-2L))) >= l_3204[1]))) | g_2580[0][7]) ^ l_3979) <= l_3464) == p_44) || g_506), p_44))))) && g_34[0]), 5))), 0x3E6CL)) || g_9) < g_1370[g_2852]) < 5L)) , g_9);
                        g_1370[g_2852] = (safe_add_func_int16_t_s_s(((l_3984 = (safe_mod_func_uint8_t_u_u(g_3193, 0xCEL))) && l_3984), g_1370[2]));
                    }
                }
                l_3277 = ((((((safe_mod_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((g_1684[0] = (g_1370[g_2852] == ((g_1370[g_2852] , (safe_rshift_func_uint16_t_u_u((l_3948 && (g_3600 || (safe_add_func_int8_t_s_s((((safe_div_func_int8_t_s_s((safe_mod_func_int8_t_s_s((l_4023 = ((safe_lshift_func_uint16_t_u_s((g_1288 >= g_759), ((((l_3914 != (safe_div_func_int32_t_s_s((safe_rshift_func_int8_t_s_s((((((safe_rshift_func_int8_t_s_u(((((safe_div_func_uint16_t_u_u((((g_34[0] = (~5L)) , (safe_rshift_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s(((safe_sub_func_uint16_t_u_u(((safe_add_func_int16_t_s_s(((safe_mod_func_uint8_t_u_u(0x04L, g_1370[g_2852])) , g_184), l_3945[1][3])) < g_1798[5][2]), 0x96E2L)) > 65530UL), l_4022)) & l_3209), g_2467)), 4))) <= 0x36A0L), l_3277)) < p_44) == g_506) > g_3172), p_44)) , p_44) >= g_204) <= g_1684[0]) & l_3945[1][2]), g_2422)), p_44))) & 0xCDE5L) != g_9) & p_44))) | 0UL)), l_4022)), g_184)) | l_3945[0][1]) && 0x04L), g_98[1][3])))), 15))) < p_44))), l_3936)), l_3911[7])) && g_2580[0][7]) , 0x92928529L) < p_44) != g_352) >= l_3911[5]);
                for (l_3794 = 5; (l_3794 >= 4); l_3794 = safe_sub_func_uint32_t_u_u(l_3794, 1))
                {
                    uint32_t l_4028 = 18446744073709551610UL;
                    for (l_3278 = 29; (l_3278 >= (-13)); --l_3278)
                    {
                        l_3948 = (p_44 && p_44);
                    }
                    l_4028 = 0x54DA928EL;
                    if ((safe_sub_func_int16_t_s_s((safe_add_func_uint8_t_u_u(g_897, ((g_472 = ((((l_4033 = g_1288) != (safe_lshift_func_uint8_t_u_u((((-1L) != (safe_lshift_func_int8_t_s_s(0x37L, 1))) , (((((((((l_4028 , ((safe_lshift_func_int8_t_s_u(p_44, (l_3948 = ((safe_rshift_func_int8_t_s_u((-1L), ((65528UL | (g_3935[3][2] | 0x67L)) || 65535UL))) < l_3794)))) , g_1370[g_2852])) == p_44) , g_3109[0]) , l_4028) | 0UL) & p_44) >= 0x4740L) , 0x4A6453C2L) >= 4294967295UL)), g_2853[0][6][6]))) & 247UL) , 255UL)) , p_44))), p_44)))
                    {
                        uint32_t l_4042 = 0xF2B5B59FL;
                        int32_t l_4043[8][7][2] = {{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}},{{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L}},{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}},{{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L}},{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}}};
                        int i, j, k;
                        l_4043[6][2][0] = l_4042;
                    }
                    else
                    {
                        uint8_t l_4088 = 0x88L;
                        int32_t l_4089 = 0xC81261FAL;
                        if (l_4044)
                            break;
                        g_3935[3][2] = ((safe_add_func_int8_t_s_s(((((((-1L) > 0xDC84L) > (safe_sub_func_uint8_t_u_u(((((((safe_add_func_uint16_t_u_u((l_4089 = (safe_rshift_func_int8_t_s_u(((((safe_mod_func_uint32_t_u_u((g_2852 == (safe_add_func_uint8_t_u_u(((l_3945[1][2] = (g_1370[g_2852] = ((safe_add_func_int8_t_s_s(((((safe_mod_func_int16_t_s_s((((((l_3950[1][1][0] = (safe_add_func_int32_t_s_s(((((l_3948 & (safe_sub_func_int8_t_s_s((((safe_add_func_int32_t_s_s(((safe_div_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(2UL, ((+(safe_add_func_uint32_t_u_u((g_3463 = p_44), (safe_div_func_uint8_t_u_u(((((safe_lshift_func_int8_t_s_u(((((p_44 >= ((safe_div_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_s(((safe_add_func_int32_t_s_s((-1L), p_44)) != p_44), 12)), g_68)) , 0L)) != g_982) <= 1UL) ^ p_44), 0)) , p_44) > g_1370[g_2852]) >= (-1L)), p_44))))) , g_759))), 6)), p_44)) , 0L), g_1684[0])) , p_44) <= 6UL), p_44))) <= g_573) , 253UL) && 0x91L), l_3911[0]))) < 0xF7L) >= 1L) <= l_3230[0]) , 0xC0B5L), 4UL)) | g_496[2]) || l_4028) ^ 0x8F88C931L), l_4088)) < l_3948))) != g_1369), l_4028))), 0x103084B7L)) >= 0x38L) <= l_4028) >= p_44), 0))), 0x84C0L)) | g_172) || g_3193) == p_44) < g_34[0]) == l_4088), l_3212[5]))) & 0x8146L) ^ l_4090) , 5L), l_3936)) , 1L);
                        l_4023 = l_3204[1];
                    }
                    g_3935[3][2] = ((safe_div_func_int16_t_s_s(((((((g_2580[3][0] = (l_3464 = p_44)) & (g_204 = p_44)) >= (safe_div_func_int32_t_s_s((safe_sub_func_int16_t_s_s((0x2C5DL > (safe_lshift_func_int8_t_s_s(p_44, 3))), ((g_3463 > ((((safe_sub_func_int16_t_s_s(1L, ((safe_sub_func_int32_t_s_s((safe_rshift_func_int8_t_s_u(((safe_sub_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(p_44, 11)), (safe_mod_func_int16_t_s_s(((l_3948 = (l_4115 = (((g_34[0] = ((g_573 = l_3936) , (safe_sub_func_uint16_t_u_u(((~(l_4114[1][4] = 5UL)) , 65535UL), l_3204[1])))) & g_87) || l_3911[6]))) != g_76), l_3803[0][3])))) , g_3935[3][2]), g_3317)), (-1L))) | g_9))) && l_4114[4][0]) > p_44) ^ 0xB4L)) || 1UL))), g_2852))) , 0x6B317E62L) && g_506) ^ 0UL), p_44)) < p_44);
                }
            }
            else
            {
                int32_t l_4132 = 0x864A84DEL;
                l_4133[5] = (((((((safe_sub_func_int32_t_s_s(((safe_add_func_int16_t_s_s(g_98[1][3], (g_3317 = ((0x728DF7C8L & (safe_add_func_int16_t_s_s((((safe_lshift_func_int8_t_s_s(p_44, (g_2422 = 0x42L))) > (p_44 != p_44)) <= ((g_1370[g_2852] || 1L) , (safe_rshift_func_int16_t_s_u((((safe_add_func_int32_t_s_s((safe_lshift_func_int8_t_s_u(0x1FL, 5)), 0x11C01581L)) == 65535UL) & l_4090), p_44)))), l_4090))) != g_496[2])))) >= l_3911[0]), 0x7973AEEBL)) , l_3212[4]) || 0UL) <= l_4132) > p_44) <= p_44) >= g_1370[g_2852]);
            }
            l_4023 = (g_1370[2] = (g_2580[3][1] = 7L));
        }
        if (l_3204[0])
            break;
        g_1370[2] = ((safe_div_func_int16_t_s_s(g_154, (safe_div_func_uint32_t_u_u(0x56CA83FCL, g_3935[6][3])))) , (safe_rshift_func_uint8_t_u_u((l_3948 = (((p_44 > ((((((((l_3230[0] = (+(g_472 ^ p_44))) != (l_3204[1] ^ (safe_add_func_int32_t_s_s(((safe_div_func_int8_t_s_s((0x76F09328L ^ (safe_add_func_uint32_t_u_u(p_44, p_44))), 0xA8L)) < p_44), p_44)))) <= 2L) && p_44) && p_44) && l_3209) <= 0x80D9DA1EL) < g_1798[7][6])) || g_1798[6][3]) ^ g_469)), 7)));
        for (g_982 = (-15); (g_982 != 5); g_982 = safe_add_func_uint32_t_u_u(g_982, 8))
        {
            for (g_759 = 0; (g_759 < 17); g_759++)
            {
                for (g_1352 = 0; (g_1352 <= 0); g_1352 += 1)
                {
                    if (g_2043)
                        goto lbl_3967;
                    for (g_506 = 0; (g_506 >= 0); g_506 -= 1)
                    {
                        if (g_1370[1])
                            break;
                    }
                    for (l_4044 = 0; l_4044 < 2; l_4044 += 1)
                    {
                        l_3204[l_4044] = 0x630AF406L;
                    }
                }
            }
        }
    }
    for (g_68 = 0; (g_68 <= 47); g_68++)
    {
        int16_t l_4164 = 0x2935L;
        int32_t l_4175 = 0xDAAB51D4L;
        int32_t l_4322 = 0x53B54A20L;
        uint32_t l_4358 = 1UL;
        int32_t l_4384 = 0xDD851F01L;
        uint16_t l_4453 = 0UL;
        for (p_44 = (-14); (p_44 < 9); p_44 = safe_add_func_int32_t_s_s(p_44, 7))
        {
            int8_t l_4176 = 1L;
            int32_t l_4217 = 0L;
            int32_t l_4292[6][10][4] = {{{1L,(-3L),1L,0xBA00F2ACL},{0L,0xD6C874E7L,0L,0L},{0x8F2748BFL,0xBA00F2ACL,0L,0xD6C874E7L},{0xBA00F2ACL,(-3L),0L,0L},{0x8F2748BFL,0x8F2748BFL,0L,0L},{0L,(-10L),1L,0xD6C874E7L},{1L,0xD6C874E7L,0xBA00F2ACL,1L},{0x8F2748BFL,0xD6C874E7L,0x7948E1FDL,0xD6C874E7L},{0xD6C874E7L,(-10L),0L,0L},{0xD1747684L,0x8F2748BFL,0xBA00F2ACL,0L}},{{0L,(-3L),(-10L),0xD6C874E7L},{0L,0xBA00F2ACL,0xBA00F2ACL,0L},{0xD1747684L,0xD6C874E7L,0L,0xBA00F2ACL},{0xD6C874E7L,(-3L),0x7948E1FDL,0L},{0xBA00F2ACL,0L,(-10L),(-10L)},{0x7948E1FDL,0xD1747684L,0x7948E1FDL,(-10L)},{0L,1L,0L,0L},{0xBA00F2ACL,(-10L),0xAFB907FFL,1L},{(-10L),0xD1747684L,0xAFB907FFL,0xAFB907FFL},{0xBA00F2ACL,0xBA00F2ACL,0L,(-10L)}},{{0L,0L,0x7948E1FDL,1L},{0x7948E1FDL,1L,(-10L),0x7948E1FDL},{0xBA00F2ACL,1L,(-3L),1L},{1L,0L,0xAFB907FFL,(-10L)},{0L,0xBA00F2ACL,(-10L),0xAFB907FFL},{0L,0xD1747684L,0L,1L},{0L,(-10L),(-10L),0L},{0L,1L,0xAFB907FFL,(-10L)},{1L,0xD1747684L,(-3L),(-10L)},{0xBA00F2ACL,0L,(-10L),(-10L)}},{{0x7948E1FDL,0xD1747684L,0x7948E1FDL,(-10L)},{0L,1L,0L,0L},{0xBA00F2ACL,(-10L),0xAFB907FFL,1L},{(-10L),0xD1747684L,0xAFB907FFL,0xAFB907FFL},{0xBA00F2ACL,0xBA00F2ACL,0L,(-10L)},{0L,0L,0x7948E1FDL,1L},{0x7948E1FDL,1L,(-10L),0x7948E1FDL},{0xBA00F2ACL,1L,(-3L),1L},{1L,0L,0xAFB907FFL,(-10L)},{0L,0xBA00F2ACL,(-10L),0xAFB907FFL}},{{0L,0xD1747684L,0L,1L},{0L,(-10L),(-10L),0L},{0L,1L,0xAFB907FFL,(-10L)},{1L,0xD1747684L,(-3L),(-10L)},{0xBA00F2ACL,0L,(-10L),(-10L)},{0x7948E1FDL,0xD1747684L,0x7948E1FDL,(-10L)},{0L,1L,0L,0L},{0xBA00F2ACL,(-10L),0xAFB907FFL,1L},{(-10L),0xD1747684L,0xAFB907FFL,0xAFB907FFL},{0xBA00F2ACL,0xBA00F2ACL,0L,(-10L)}},{{0L,0L,0x7948E1FDL,1L},{0x7948E1FDL,1L,(-10L),0x7948E1FDL},{0xBA00F2ACL,1L,(-3L),1L},{1L,0L,0xAFB907FFL,(-10L)},{0L,0xBA00F2ACL,(-10L),0xAFB907FFL},{0L,0xD1747684L,0L,1L},{0L,(-10L),(-10L),0L},{0L,1L,0xAFB907FFL,(-10L)},{1L,0xD1747684L,(-3L),(-10L)},{0xBA00F2ACL,0L,(-10L),(-10L)}}};
            int i, j, k;

{

{
            transparent_crc(g_2580[l_3464][p_44], "g_2580[l_3464][p_44]", g_573);
            ;

        }


g_35 -= 1;


                    for (k = 0; k < 5; k++)
        {

g_506 -= 1;


                    ;
            if (l_4322) printf("index = [%d][%d]\n", i, k);

        }
    }

                    if (((safe_div_func_uint32_t_u_u(((safe_rshift_func_int8_t_s_u((1L | (safe_add_func_int8_t_s_s((!(safe_sub_func_uint32_t_u_u((l_4164 && ((safe_unary_minus_func_uint16_t_u(((g_352 = p_44) , (g_98[4][3] = (+(safe_add_func_int8_t_s_s((safe_div_func_uint32_t_u_u((l_4164 || ((((l_3230[0] = ((p_44 & (safe_mod_func_int16_t_s_s((l_4175 = (p_44 , (((safe_mod_func_uint8_t_u_u((g_9 < (65528UL ^ 0UL)), l_4164)) == p_44) < l_4164))), g_1138))) <= g_2467)) , l_4176) >= l_4176) , 0xD077BD4FL)), (-1L))), l_4176))))))) > l_4164)), l_4176))), 1L))), 4)) >= (-4L)), l_4164)) <= (-7L)))
            {
                int16_t l_4183 = 0xCCC9L;
                int32_t l_4216 = 0x08B7903DL;
                uint32_t l_4242 = 0xF5285B0EL;
                for (g_2467 = (-10); (g_2467 == 16); g_2467++)
                {
                    uint32_t l_4215 = 0xB7F28421L;
                    uint32_t l_4244 = 9UL;
                    int32_t l_4265 = (-9L);

{
                        if (g_1370[1])
                            break;
                    }


for (g_2440 = 0; g_2440 < 1; g_2440++)
        g_5210[g_2440] = 1L;

                    g_3935[6][4] = (safe_sub_func_int32_t_s_s((g_2580[0][7] = ((l_4175 = l_3209) == (((safe_rshift_func_int8_t_s_s(g_87, l_4183)) < (safe_div_func_int32_t_s_s(g_9, (safe_rshift_func_uint16_t_u_u(g_506, (safe_sub_func_int32_t_s_s(p_44, ((((g_472 = (((safe_sub_func_uint32_t_u_u((((((g_1352 = 0L) , (p_44 >= (l_4164 < g_335))) | g_240) != 0x9E2DBD5AL) == 0L), l_4176)) == g_3172) ^ 0UL)) >= p_44) && g_1684[0]) ^ 0x6FL)))))))) || 0x4297L))), l_3607));
                    for (g_573 = 0; (g_573 <= 0); g_573 += 1)
                    {
                        int i;
                        l_4217 = (((!((0x00L <= (safe_sub_func_uint32_t_u_u((l_3230[0] = g_1684[g_573]), (safe_mod_func_int16_t_s_s((safe_add_func_uint8_t_u_u((g_1684[0] | (safe_lshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_s(p_44, 4)), 4)), 4L)), 5))), (((safe_rshift_func_uint16_t_u_u((safe_div_func_uint8_t_u_u((0x6FL >= p_44), (l_4216 = ((safe_mod_func_uint32_t_u_u(((((safe_sub_func_int16_t_s_s((g_1684[g_573] ^ g_2580[0][7]), g_184)) > p_44) ^ g_3193) ^ 0xF73BL), l_4215)) , l_3794)))), 12)) , g_3935[3][2]) > p_44))), l_3794))))) , g_506)) == p_44) || l_3464);
                        return p_44;
                    }

for (l_4090 = 0; (l_4090 <= 1); l_4090 += 1)
                    {
                        uint8_t l_1049 = 0x11L;
                        int32_t l_1055[7] = {0L,0L,0L,0L,0L,0L,0L};
                        int i;
                        l_1049 = (0x70L && (g_3463 != (g_98[3][3] <= (safe_mod_func_int8_t_s_s((safe_div_func_uint32_t_u_u((0xC84EL < (l_4272 , (((safe_rshift_func_int16_t_s_u(((((safe_mod_func_uint32_t_u_u(3UL, (safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((l_4215 = ((safe_add_func_uint32_t_u_u(0UL, (safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_s((((l_4265 = ((safe_div_func_uint32_t_u_u((4294967293UL == ((0x53D2L > l_4384) | l_4384)), l_4384)) != 0xF29CL)) & l_3794) , g_1369), 5)), g_1369)))) ^ g_35)) || g_3193), 6)), 255UL)))) == 0xFEB37081L) != g_469) | l_4272), g_1369)) , g_1369) & g_1369))), g_76)), g_3193)))));
                        l_4265 = (l_1049 , (((l_4272 = (g_1369 || ((((safe_div_func_int32_t_s_s(((0x56D9L && l_4183) >= ((g_1369 > ((1UL < (((((l_1055[0] = (0x1FL || (g_87 = (+(safe_mod_func_uint8_t_u_u(252UL, (l_4090 , l_4272))))))) >= g_1138) <= 1L) & l_4183) & g_1369)) || g_1369)) > l_4272)), (-2L))) > g_98[1][3]) | l_4183) ^ 0xA113L))) , l_4183) < l_4090));
                    };



if (l_3607)
                            break;




{
                        uint32_t l_3777 = 0x65B9FE36L;
                        g_2043 = g_3109[1];

{
        transparent_crc(g_4423[l_4476], "g_4423[l_4476]", BfBfBeg_2043);
        if (BfBfBeg_2043) printf("index = [%d]\n", l_4476);

    }

                    g_5512 = (g_352 , (safe_rshift_func_int16_t_s_s((j | j), (!l_3777))));
                    }

                    for (g_76 = 0; (g_76 >= 21); g_76 = safe_add_func_uint16_t_u_u(g_76, 2))
                    {
                        uint32_t l_1192 = 0UL;
                        ;
                        l_1192 = l_4183;
                    };


                    if (p_44)
                        {
{
                        uint32_t l_4042 = 0xF2B5B59FL;
                        int32_t l_4043[8][7][2] = {{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}},{{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L}},{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}},{{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L}},{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}}};
                        int i, j, k;
                        l_4043[6][2][0] = l_4042;
                    }

                    break;}
                }

if (g_1798[5][2])
                            continue;

                    l_4175 = (-1L);

            }
            else
            {
                int32_t l_4291[4][6][6] = {{{0x9D48C12EL,0L,0L,0x21F6396FL,0L,1L},{0xE70FB94DL,1L,(-2L),0L,0L,(-2L)},{1L,1L,1L,(-2L),5L,1L},{1L,0x9D48C12EL,1L,1L,0x69DF6F92L,1L},{0xAA603F92L,1L,1L,0xE70FB94DL,1L,1L},{(-1L),0xE70FB94DL,1L,0L,0L,(-2L)}},{{0L,0L,(-2L),1L,0x21F6396FL,0x11ED91A7L},{(-1L),0L,5L,5L,0L,(-1L)},{0L,0xE70FB94DL,1L,0x9D48C12EL,1L,1L},{5L,1L,0x21F6396FL,0xAA603F92L,0x69DF6F92L,0L},{5L,0x9D48C12EL,0xAA603F92L,0x9D48C12EL,5L,1L},{0L,1L,0x69DF6F92L,5L,0L,(-1L)}},{{(-1L),1L,0L,1L,(-1L),(-1L)},{0L,0x69DF6F92L,0x69DF6F92L,0L,0x11ED91A7L,1L},{(-1L),1L,0xAA603F92L,0xE70FB94DL,0x9D48C12EL,0L},{0xAA603F92L,(-1L),0x21F6396FL,1L,0x9D48C12EL,1L},{1L,1L,1L,(-2L),0x11ED91A7L,(-1L)},{1L,0x69DF6F92L,5L,0L,(-1L),0x11ED91A7L}},{{0xE70FB94DL,1L,(-2L),0L,0L,(-2L)},{1L,1L,1L,(-2L),5L,1L},{1L,0x9D48C12EL,1L,1L,0x69DF6F92L,1L},{0xAA603F92L,1L,1L,0xE70FB94DL,1L,1L},{(-1L),0xE70FB94DL,1L,0L,0L,(-2L)},{0L,0L,(-2L),1L,0x21F6396FL,0x11ED91A7L}}};
                int i, j, k;
                g_3935[3][2] = (safe_rshift_func_uint8_t_u_u(253UL, ((g_98[1][3] = ((((((+((safe_rshift_func_uint8_t_u_u(((safe_add_func_int8_t_s_s(g_472, ((l_4292[3][6][1] = (g_472 || ((((((0x00L != (safe_div_func_uint8_t_u_u(p_44, p_44))) <= ((((safe_rshift_func_uint16_t_u_s(((g_897 = (safe_mod_func_uint16_t_u_u((l_4217 , ((safe_add_func_int32_t_s_s((((((safe_lshift_func_int16_t_s_s(((l_4175 = p_44) != (255UL || 0x87L)), l_4291[3][3][4])) , 0UL) <= l_4176) == l_4291[2][1][2]) , p_44), 0x93F5B890L)) && p_44)), 1L))) <= (-1L)), 10)) ^ 0UL) && l_4291[3][3][4]) ^ p_44)) && g_335) & 0x11BCC8A6L) | l_4291[3][3][4]) , l_4175))) , l_4175))) > g_3600), l_3204[1])) == l_4291[3][3][1])) > g_3935[3][0]) > 255UL) > g_1798[5][2]) < 0x05E4L) , g_172)) != l_4164)));
            }
        }
        l_4273 = ((+((((~(((safe_sub_func_uint32_t_u_u((safe_add_func_int16_t_s_s(((((safe_mod_func_uint8_t_u_u((l_3464 = (safe_lshift_func_int16_t_s_u(g_1288, l_4175))), (safe_div_func_uint8_t_u_u(((((safe_mod_func_int8_t_s_s(((safe_rshift_func_int16_t_s_s(0xD693L, 9)) & (safe_add_func_int32_t_s_s(l_4164, (safe_div_func_uint8_t_u_u(((l_3230[0] = (l_4322 = ((safe_lshift_func_uint16_t_u_s((safe_lshift_func_uint8_t_u_s(0xBDL, ((!((!(0x2AL <= p_44)) & (safe_rshift_func_int16_t_s_s((g_2580[1][5] , ((g_496[3] || 0xAB82L) < g_154)), g_184)))) , g_1370[0]))), p_44)) & l_4321))) ^ l_4175), g_897))))), p_44)) > l_3209) < p_44) ^ 0x3878368DL), p_44)))) <= l_3212[4]) > 0x69AD9E7CL) != l_3204[1]), p_44)), g_1798[4][2])) || g_1352) <= 0x8211L)) == 0x6DL) > g_982) && 4294967295UL)) & 0x22C2L);

{
                    return g_5512;
                }


g_3463 += 1;


                    for (g_275 = 0; (g_275 < (-21)); g_275 = safe_sub_func_int16_t_s_s(g_275, 4))
        {
            uint32_t l_4359 = 0x6CE1B8FCL;
            int32_t l_4360[7][6] = {{0x4D52E69AL,(-3L),(-3L),0x4D52E69AL,(-2L),0x4D52E69AL},{0x4D52E69AL,(-2L),0x4D52E69AL,(-3L),(-3L),0x4D52E69AL},{0x9A51126EL,0x9A51126EL,(-3L),(-1L),(-3L),0x9A51126EL},{(-3L),(-2L),(-1L),(-1L),(-2L),(-3L)},{0x9A51126EL,(-3L),(-1L),(-3L),0x9A51126EL,0x9A51126EL},{0x4D52E69AL,(-3L),(-3L),0x4D52E69AL,(-2L),0x4D52E69AL},{0x4D52E69AL,(-2L),0x4D52E69AL,(-3L),(-3L),0x4D52E69AL}};
            int8_t l_4432 = 0x9DL;
            int32_t l_4439 = 0x46340F21L;
            int32_t l_4440 = 0x308E2A13L;
            int i, j;

if (l_3887)
                        {
if (g_3486) printf("index = [%d]\n", l_4272);

                    goto lbl_3517;}



g_1368 += 1;


                    if (l_3209) printf("index = [%d]\n", p_44);

                    for (g_3600 = 0; (g_3600 > 8); g_3600++)
            {
                uint8_t l_4337 = 255UL;
                int32_t l_4361 = 0xD7E3B922L;
                if ((0UL & l_4175))
                {
                    uint8_t l_4366 = 1UL;
                    int32_t l_4383 = (-1L);

{
lbl_3126:
            l_3209 = (BfBfBfg_184 < ((safe_rshift_func_int16_t_s_u((-7L), 12)) ^ l_4453));
            return BfBfBfg_184;
        }

                    if (((((g_897 = ((l_4361 = (safe_div_func_uint32_t_u_u((safe_add_func_int32_t_s_s((safe_lshift_func_int16_t_s_u((((safe_sub_func_int8_t_s_s(((safe_lshift_func_int16_t_s_s(g_1798[5][2], l_4337)) , ((1L & (((l_3230[0] = p_44) != (((l_4360[1][1] = ((l_4175 <= (safe_div_func_uint32_t_u_u((safe_div_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_lshift_func_uint16_t_u_u((safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_lshift_func_int16_t_s_s((((((safe_sub_func_int8_t_s_s(((65534UL <= (g_34[0] , (safe_rshift_func_uint8_t_u_u(((((p_44 && (((((safe_add_func_int16_t_s_s((l_4358 = p_44), 7L)) < p_44) , 4L) < p_44) , 9L)) & (-8L)) && p_44) , l_3277), 7)))) <= p_44), p_44)) && p_44) != g_1684[0]) == 0xB4L) != l_4337), 1)), 13)), l_4359)), l_4164)), p_44)), l_4359)), 4294967295UL))) & 0x5B367826L)) <= p_44) & 0x0C8BL)) , p_44)) || 252UL)), 0x0CL)) | (-4L)) > l_4359), 0)), p_44)), g_1138))) != 0xF21C8443L)) && l_4360[1][1]) & 0x3215L) == l_3209))
                    {
                        int32_t l_4367[9] = {9L,3L,9L,9L,3L,9L,9L,3L,9L};
                        int i;
                        g_3935[2][3] = (g_240 , (((p_44 , p_44) > (l_4322 = g_2853[1][5][6])) > (l_4367[5] = ((p_44 , (safe_lshift_func_uint16_t_u_s((g_172 = (safe_add_func_uint16_t_u_u(g_3600, l_4366))), 5))) != 0x3B41L))));
                        return p_44;
                    }
                    else
                    {
                        l_4384 = (l_4383 = (safe_lshift_func_int16_t_s_s((g_982 ^ (~(((safe_div_func_uint8_t_u_u((g_1370[2] , (p_44 != ((l_4175 = (safe_div_func_int16_t_s_s((l_4322 = 1L), g_2853[0][1][0]))) == l_3803[0][2]))), (safe_rshift_func_uint8_t_u_s(((-4L) | ((((safe_rshift_func_int8_t_s_s((g_3172 = ((safe_lshift_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(((((l_3464 = g_34[0]) <= p_44) ^ g_1368) & p_44), 0)), 2)) <= l_4337)), 0)) | p_44) == p_44) <= 249UL)), g_1138)))) || g_496[1]) <= p_44))), 11)));
                    }
                }
                else
                {
                    int32_t l_4403[6][3][4] = {{{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L}},{{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L}},{{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L}},{{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L}},{{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L}},{{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L},{0xE02745A9L,0xE02745A9L,0xE02745A9L,0xE02745A9L}}};
                    int i, j, k;
                    l_3230[0] = (safe_add_func_uint32_t_u_u(((~(safe_mod_func_int32_t_s_s((p_44 == (g_1138 , (safe_lshift_func_uint16_t_u_u((safe_add_func_int32_t_s_s((p_44 || (safe_mod_func_int16_t_s_s(p_44, 0x8EFEL))), (safe_lshift_func_int16_t_s_u(0xD408L, 14)))), ((g_98[1][3] = 0xDC2BL) != g_1684[0]))))), (l_3277 = ((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint8_t_u_u((l_4361 = ((!l_4359) >= 0UL)), g_2467)) == 0xF0L) > l_4403[2][2][1]) > p_44), 0x8D57L)) ^ l_3803[0][2]))))) <= l_3794), l_4359));
                    return l_4360[4][1];
                }

if (g_2440) printf("index = [%d][%d]\n", l_4384, g_204);


if (g_6428)
                            break;

                    g_3935[5][3] = (+((0xE0F6L >= ((l_4361 = (((safe_lshift_func_int8_t_s_u((0x56L == (((p_44 & p_44) , 0x7D5CL) < g_506)), 1)) <= (0xEEF94759L < l_4384)) && p_44)) | l_3278)) || l_4359));


if (l_4440)
                        break;

                    l_4337 += 1;


                    ;
            }


{
        transparent_crc(g_4423[g_573], "g_4423[g_573]", l_4322);
        ;

    }


;


                    g_2853[0][6][6] = (((safe_sub_func_uint8_t_u_u(((((((g_2422 = ((l_4360[1][1] = ((((safe_add_func_uint16_t_u_u((0xD0CFL <= p_44), 4L)) && (((safe_mod_func_int8_t_s_s((g_154 = ((((g_472 = ((l_4432 = l_4360[3][5]) || g_3109[0])) & g_469) == ((l_4273 = ((safe_mod_func_int16_t_s_s((l_4439 = (((g_3193 = ((safe_mod_func_int32_t_s_s(((g_87 = 3UL) != (p_44 & (safe_div_func_int16_t_s_s((6UL >= l_3212[4]), p_44)))), l_3277)) == g_3317)) | l_4360[5][2]) <= 4294967290UL)), p_44)) != p_44)) >= 1L)) <= l_4360[5][5])), p_44)) , 249UL) > p_44)) , (-1L)) <= 0x1470L)) || g_496[3])) , g_1370[2]) & g_1370[2]) != l_3464) , g_3172) , 0UL), g_98[1][3])) > l_4440) && g_204);
            for (l_3794 = 0; (l_3794 <= 3); l_3794 += 1)
            {
                int32_t l_4458 = (-1L);
                const int16_t l_4505 = 0L;
                int i, j;


l_4453 += 1;


                    ;


                    if (((safe_lshift_func_uint8_t_u_s((safe_sub_func_int8_t_s_s(((g_2580[l_3794][l_3794] = (!0x9726E743L)) <= (0x9AEAD830L >= (!(safe_rshift_func_uint8_t_u_u((safe_div_func_int32_t_s_s(((l_4384 >= ((p_44 < p_44) <= ((l_4322 = ((g_2853[0][6][6] & (((g_4423[1] <= ((l_4175 = (safe_lshift_func_int8_t_s_s(l_4453, ((safe_mod_func_uint32_t_u_u((safe_add_func_uint32_t_u_u(0UL, 0x547154BBL)), 1L)) ^ 0x10L)))) , 1UL)) != l_3278) , p_44)) < l_4458)) > 0xBB173593L))) > 0x29B6L), 8L)), 4))))), l_4458)), l_4360[4][3])) < p_44))
                {
                    const uint32_t l_4477 = 0xFB4474FFL;

for (l_4458 = 0; l_4458 < 2; l_4458++)
            ;;

                    for (l_4358 = 0; (l_4358 < 5); l_4358 = safe_add_func_int16_t_s_s(l_4358, 1))
                    {

{
        for (l_4175 = 0; l_4175 < 10; l_4175++)
        {
            transparent_crc(g_2580[l_4272][l_4175], "g_2580[l_4272][l_4175]", l_4322);
            if (l_4322) {
if (BJBJBog_335)
                            break;

                    printf("index = [%d][%d]\n", l_4272, l_4175);}

        }
    }

                    l_4458 = 0L;
                    }


g_3486 -= 1;



if (g_2043) printf("index = [%d][%d][%d]\n", p_44, l_3277, i);

                    for (g_5512 = 6; (g_5512 >= 0); g_5512 -= 1)
                {
                    int i;

;


                    return g_4423[g_5512];
                }

for (l_4044 = 6; (l_4044 > 5); --l_4044)
                    {
                        uint32_t l_666 = 4294967292UL;
                        int32_t l_677 = 0xC2919148L;
                        g_3486 = (BJBJBog_335 == (safe_lshift_func_int16_t_s_u((l_666 >= 0xCA1FA15DL), 10)));
                        BfBfBcg_573 = (BfBfBcg_573 = (~(!(BJBJBog_335 <= (((0xBD3024CCL || (0x0624L == g_3193)) <= 0UL) > (g_1369 == (safe_add_func_int16_t_s_s(((g_2440 = (((safe_mod_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((l_677 = 1UL), ((safe_div_func_uint8_t_u_u((g_3193 < (l_666 || g_3193)), 0x7AL)) > g_3193))), 0xCE57L)) & 0xC6L) && 1L)) >= g_3193), l_4175))))))));
                    };


                    l_4232 += 1;


                    ;


                    g_2580[l_3794][l_3794] = (g_4423[1] , (((p_44 < l_4439) <= g_1684[0]) || (safe_add_func_int16_t_s_s((safe_add_func_int32_t_s_s((((1UL | (((((safe_lshift_func_uint16_t_u_s(0xAA14L, 2)) == (g_35 ^ (safe_sub_func_int32_t_s_s((safe_sub_func_int32_t_s_s((p_44 == (l_4476 = ((safe_div_func_uint16_t_u_u((safe_sub_func_int16_t_s_s(g_4475, g_335)), p_44)) != p_44))), 0x6FFD75EDL)), p_44)))) <= p_44) , 0x7C5F6ACEL) , 0x9B9B816CL)) > 0x34L) | g_759), l_4477)), g_2043))));
                    if (g_3600)
                        {
if (l_4090)
                        goto lbl_3517;


if (l_4458) printf("index = [%d][%d]\n", g_3486, l_4439);

                    goto lbl_4478;}
                }
                else
                {
                    uint16_t l_4481 = 0x0B37L;
                    int32_t l_4490 = 0x5D6B754AL;

for (l_4439 = 0; l_4439 < 7; l_4439++)
    {

{
                        return g_1370[2];
                    }

                    ;
        if (g_3486) printf("index = [%d]\n", l_4439);

    }
if (g_1370[2])
                            continue;

                    ;



g_982 += 1;


                    l_4490 = (l_4360[3][0] = ((((safe_rshift_func_uint8_t_u_s(l_4481, 1)) == (l_3277 = (g_759 = (g_2580[l_3794][l_3794] , (safe_rshift_func_uint16_t_u_u(l_3230[0], 13)))))) ^ (g_2580[l_3794][l_3794] , p_44)) != ((~(l_4489[4][0] = (0x9BE7L >= (l_3464 = ((p_44 <= (safe_div_func_int16_t_s_s(((l_4322 = (((safe_sub_func_uint16_t_u_u((l_4458 = (p_44 >= (g_3935[4][1] < 5UL))), g_2440)) <= g_1138) , (-9L))) , 0xBC74L), g_1345))) != 0UL))))) , 0x1BL)));
                    g_204 = ((p_44 , l_4489[4][0]) > (safe_rshift_func_int8_t_s_u((g_2467 = ((safe_mod_func_int32_t_s_s(((g_154 = (g_2580[l_3794][l_3794] = p_44)) | (l_4458 = ((l_4439 = (safe_div_func_int16_t_s_s(0x0BC8L, 0x90FAL))) > (l_3230[0] = (((((safe_div_func_uint16_t_u_u((g_172 = g_1368), (safe_add_func_int16_t_s_s(p_44, g_2440)))) || (safe_rshift_func_int8_t_s_u(((g_1370[2] = (safe_lshift_func_uint8_t_u_u(1UL, p_44))) && l_4358), 4))) ^ l_4505) >= p_44) ^ l_4440))))), p_44)) | g_4423[1])), p_44)));
                    return l_4384;
                }
                l_4273 = 0xCD96DF4EL;

{
                for (g_1352 = 0; (g_1352 <= 0); g_1352 += 1)
                {
                    ;


if (g_204) printf("index = [%d]\n", g_506);

                    for (g_5512 = 0; g_5512 < 2; g_5512 += 1)
                    {
                        ;
                    }
                }
            }

                    l_3230[0] = ((safe_sub_func_int16_t_s_s((((safe_div_func_uint8_t_u_u(p_44, (g_4423[1] = ((safe_div_func_int8_t_s_s(((((((0x37CA17FCL >= (((safe_sub_func_uint32_t_u_u(((g_3600 | (safe_add_func_int8_t_s_s(0x4DL, 7L))) , (safe_mod_func_uint16_t_u_u(p_44, p_44))), (g_240 < ((safe_mod_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s((safe_add_func_uint32_t_u_u(l_3209, l_4505)), 7)) ^ l_4453) >= l_4360[4][3]), 1L)) > 0xEDL)))) ^ l_4489[4][0]) , l_4440)) & g_68) , p_44) , l_4044) < 1L) ^ g_2580[l_3794][l_3794]), g_3935[4][2])) | l_4489[4][0])))) && p_44) ^ g_3193), g_2580[0][7])) | p_44);
            }
        }
    }


g_352 += 1;


                    ;


                    return g_76;
}







static uint16_t func_51(uint32_t p_52)
{
    uint16_t l_69 = 0xAAF0L;
    int32_t l_75 = 0xF781BE2FL;
    int32_t l_1706 = 0xAADEC7F0L;
    uint16_t l_1721 = 0xA004L;
    const uint8_t l_1724[5] = {255UL,255UL,255UL,255UL,255UL};
    int32_t l_1734[5];
    int8_t l_1774 = (-1L);
    uint32_t l_1826 = 1UL;
    int32_t l_1865[2];
    uint32_t l_1867 = 18446744073709551615UL;
    uint32_t l_2002 = 4UL;
    int16_t l_2072 = 0x44B4L;
    uint32_t l_2098 = 0xDF982D3FL;
    int8_t l_2161 = 0x81L;
    uint32_t l_2274[10] = {0x9192CB57L,0xD6D698ECL,0xCD3A9739L,0xCD3A9739L,0xD6D698ECL,0x9192CB57L,0xD6D698ECL,0xCD3A9739L,0xCD3A9739L,0xD6D698ECL};
    int8_t l_2354 = 9L;
    uint32_t l_2421 = 0x9719CA75L;
    const uint16_t l_2424[6][8] = {{4UL,7UL,1UL,0xE2FBL,0UL,9UL,1UL,1UL},{1UL,4UL,0xE606L,0xE606L,4UL,1UL,1UL,0xB883L},{65535UL,0xE606L,1UL,9UL,0xE2FBL,0x7909L,0xE2FBL,9UL},{0xE2FBL,0x7909L,0xE2FBL,9UL,1UL,0xE606L,65535UL,0xB883L},{1UL,1UL,4UL,0xE606L,0xE606L,4UL,1UL,1UL},{1UL,9UL,0UL,0xE2FBL,1UL,7UL,4UL,7UL}};
    int32_t l_2508 = 0x35A8E68AL;
    int8_t l_2712 = 0x75L;
    int32_t l_2829 = 2L;
    uint16_t l_2938 = 0x1C58L;
    const uint32_t l_2982 = 9UL;
    int32_t l_3032[7][5][6] = {{{0xE55F61C5L,0xB23A6AAAL,1L,0x6AF6BDAEL,0x6AF6BDAEL,1L},{(-1L),(-1L),0x6AF6BDAEL,0x26F778ECL,0x7335240EL,2L},{0xA18490A0L,1L,0x8A9BC732L,0x01CCCF67L,0xA6D9D65AL,0x6AF6BDAEL},{0L,0xA18490A0L,0x8A9BC732L,9L,(-1L),2L},{0xAACD44BBL,9L,0x6AF6BDAEL,(-2L),8L,1L}},{{(-2L),8L,1L,(-4L),1L,(-2L)},{(-9L),0L,(-10L),0x26F778ECL,(-10L),0L},{(-10L),0xB23A6AAAL,0x01CCCF67L,(-1L),0xA6D9D65AL,(-4L)},{(-1L),(-10L),(-1L),1L,1L,2L},{0x94BF3CACL,(-10L),0xA18490A0L,1L,(-1L),0x88FD6B90L}},{{0x8A9BC732L,2L,0x26F778ECL,0x94BF3CACL,0xA056D32FL,0x01CCCF67L},{(-4L),0xA18490A0L,0xE55F61C5L,0xB23A6AAAL,1L,0x6AF6BDAEL},{0x94BF3CACL,0xC7697946L,0xA6D9D65AL,0xA6D9D65AL,0xC7697946L,0x94BF3CACL},{1L,0x94BF3CACL,(-1L),1L,0x7335240EL,0xA18490A0L},{0x0E2F3977L,0xAACD44BBL,1L,0x88FD6B90L,(-1L),(-1L)}},{{0x0E2F3977L,1L,0x88FD6B90L,1L,(-2L),0x01CCCF67L},{1L,0x7335240EL,0xAACD44BBL,0xA6D9D65AL,0xE55F61C5L,(-10L)},{0x94BF3CACL,2L,8L,0xB23A6AAAL,1L,1L},{(-4L),0x94BF3CACL,1L,0x94BF3CACL,(-4L),0x6AF6BDAEL},{0x8A9BC732L,1L,1L,(-1L),0xC7697946L,0x8A9BC732L}},{{0x26F778ECL,(-9L),0x0E2F3977L,1L,0xA056D32FL,0x8A9BC732L},{0x7335240EL,1L,1L,1L,0xE55F61C5L,0x6AF6BDAEL},{0xA056D32FL,1L,1L,0L,0L,1L},{1L,0xA056D32FL,8L,1L,(-10L),(-10L)},{0x8A9BC732L,0xAACD44BBL,0xAACD44BBL,0x8A9BC732L,1L,0x01CCCF67L}},{{0x01CCCF67L,(-9L),0x88FD6B90L,0x94BF3CACL,1L,(-1L)},{0xA18490A0L,(-4L),1L,0xA6D9D65AL,1L,0xA18490A0L},{0xAACD44BBL,(-9L),(-1L),0L,1L,0x94BF3CACL},{0x7335240EL,0xAACD44BBL,0xA6D9D65AL,0xE55F61C5L,(-10L),0x6AF6BDAEL},{0x0E2F3977L,0xA056D32FL,0xE55F61C5L,0x01CCCF67L,0L,0x01CCCF67L}},{{0x26F778ECL,1L,0x26F778ECL,1L,0xE55F61C5L,0x88FD6B90L},{0xA18490A0L,1L,0xAACD44BBL,0xB23A6AAAL,0xA056D32FL,(-4L)},{1L,(-9L),1L,0xB23A6AAAL,0xC7697946L,1L},{0xA18490A0L,1L,0xA6D9D65AL,1L,(-4L),0xA18490A0L},{0x26F778ECL,0x94BF3CACL,0xA056D32FL,0x01CCCF67L,1L,0x8A9BC732L}}};
    int16_t l_3036[5];
    int32_t l_3067 = 0xB03A3733L;
    uint16_t l_3110 = 65527UL;
    int8_t l_3153 = (-7L);
    uint32_t l_3167[10][1] = {{1UL},{0x26E4145FL},{0x26E4145FL},{1UL},{0x26E4145FL},{0x26E4145FL},{1UL},{0x26E4145FL},{0x26E4145FL},{1UL}};
    int32_t l_3173[9] = {0L,0x90A23371L,0L,0x90A23371L,0L,0x90A23371L,0L,0x90A23371L,0L};
    int i, j, k;
                                                                                                                                                    while (((l_2421 > g_573) && (g_1368 < g_573)) )
{

{
                        g_1370[1] = ((i = l_2938) ^ ((safe_sub_func_uint8_t_u_u(((+g_759) , g_506), (-10L))) || g_6029));
                    }

}
                    while ((!g_352) )
{

{
                        int8_t l_4920 = 0xD6L;
                        g_2580[0][7] = (((g_2043 & (safe_unary_minus_func_int32_t_s(g_982))) > (0L != g_2043)) && g_2852);
                        g_1138 = l_4920;
                    }

}
                    if (!((g_184 < l_1867)) )
{

{
        for (g_573 = 0; g_573 < 5; g_573++)
        {

for (g_87 = 0; (g_87 <= 0); g_87 += 1)
                {
                    int32_t l_4711 = 0x150A892AL;
                    return l_4711;
                };


                    transparent_crc(g_3935[g_240][g_573], "g_3935[g_240][g_573]", g_204);

{
                        return g_1288;
                    }

                    if (g_204) {
{
                        uint32_t l_1192 = 0UL;
                        l_1706 = (safe_unary_minus_func_uint16_t_u((g_34[0] || g_1369)));
                        l_1192 = g_897;
                    }

                    printf("index = [%d][%d]\n", g_240, g_573);}

        }
    }

}
                    if (!((g_3193 < g_68)) )
{

g_204 += 1;


}
                    for (i = 0; i < 5; i++)
        { uint32_t BlClCHg_1138 = (~(((~((g_2467 && l_2938))) + (((g_1288 & (~(l_2072))) + (~(g_1369))) * (~((((l_2002 & g_1138) ^ (-(g_275))) * ((~(l_2712)) * (~(l_3110))))))))));
uint32_t BlClCIl_2002 = (-((((-((~(((-((g_1288 | g_1138))) | ((g_2467 & (~((~(l_3110))))) * (l_2938 | (l_2002 & g_275)))))))) & (-((~(g_1369))))) | ((BlClCHg_1138 | l_2712) ^ l_2072))));
int16_t BlClCJl_2072 = (~(((-((l_2938 && (l_3110 >> l_2002)))) | (((~((g_1288 * g_1138))) ^ (((~(BlClCHg_1138)) ^ (~((-(g_2467))))) | l_2712)) + (((~(g_1369)) + (~(BlClCIl_2002))) | (g_275 && l_2072))))));
uint16_t BlClCKl_2938 = (~(((~((~((g_2467 * (-(BlClCJl_2072))))))) & (-(((BlClCHg_1138 * ((l_2002 * (g_275 ^ l_2712)) + (g_1288 & (g_1138 & BlClCIl_2002)))) | (((~((~((~((~((-(l_2938)))))))))) ^ (-((~(l_3110))))) & (-(((-(g_1369)) ^ l_2072))))))))));
int8_t BlClCLg_2467 = (~(((~(((~(l_2938)) + (~((~(BlClCIl_2002))))))) && (((~((BlClCHg_1138 >> BlClCJl_2072))) + (~(g_275))) * (((~((BlClCKl_2938 | (l_2072 ^ g_1369)))) & (((g_2467 ^ l_3110) | l_2002) ^ l_2712)) * (g_1288 | g_1138))))));
int32_t BlClCMg_275 = (~((((-((~((~(((g_1369 & l_3110) ^ (~((~(BlClCJl_2072))))))))))) | (~(((-((g_2467 + (~(((~(g_1288)) + (BlClCIl_2002 * (BlClCLg_2467 ^ BlClCKl_2938)))))))) && ((-((~(l_2002)))) * (l_2938 & l_2712)))))) ^ (((g_1138 & g_275) ^ l_2072) * (~((-((~(BlClCHg_1138))))))))));
if((((g_1138 > l_2938) || (g_275 > l_2072)) || ((g_1138>=0U) || (BlClCJl_2072 > BlClCKl_2938)))){
                                    while ((g_35 > g_506) )
{

for (g_2440 = 0; g_2440 < 4; g_2440++)
    {
        for (l_1706 = 0; l_1706 < 9; l_1706++)
        {
            for (g_2440 = 0; g_2440 < 7; g_2440++)
            {
                transparent_crc(g_2853[g_2440][l_1706][g_2440], "g_2853[g_2440][l_1706][g_2440]", g_204);
                if (g_204) printf("index = [%d][%d][%d]\n", g_2440, l_1706, g_2440);

            }
        }
    };


}
                    BlClCHg_1138 = g_1138;
BlClCIl_2002 = l_2002;
BlClCJl_2072 = l_2072;
BlClCKl_2938 = l_2938;
BlClCLg_2467 = g_2467;
BlClCMg_275 = g_275;
g_1138 = (~((((~(((-(l_2072)) + l_2002))) & ((~((-((~(g_2467)))))) && (l_2712 * ((-(g_1369)) ^ BlClCIl_2002)))) * (~((~((~(((((BlClCKl_2938 + (~(BlClCLg_2467))) + g_275) * (~((-((BlClCHg_1138 & (~(((g_1288 + BlClCMg_275) && g_1138))))))))) | (-(((~((-((BlClCJl_2072 ^ l_3110))))) && l_2938)))))))))))));
l_2002 = (~(((((~((~(((BlClCJl_2072 & BlClCLg_2467) && (~(((~((~(g_1288)))) >> (~(g_275)))))))))) | (((~((-(BlClCKl_2938)))) + ((BlClCIl_2002 | l_2712) << g_2467)) | g_1369)) * (l_2002 | (~(BlClCMg_275)))) | ((-((-((~(l_2072)))))) ^ (~((-(((BlClCHg_1138 ^ (l_3110 & g_1138)) + l_2938)))))))));
l_2072 = (~(((~(((~(((-((g_1288 & g_275))) * ((-(l_2002)) | (l_3110 & l_2072))))) >> (~((~(((~(BlClCJl_2072)) && (BlClCIl_2002 && BlClCKl_2938))))))))) && (((-(BlClCLg_2467)) & (l_2712 && (g_2467 + g_1369))) ^ (~(((~((-((l_2938 * (~((~((g_1138 << (-(BlClCMg_275)))))))))))) & (-(BlClCHg_1138)))))))));
l_2938 = (~((((l_2938 | (~((~(BlClCJl_2072))))) + (~(BlClCIl_2002))) * (~(((l_2002 + (((-(l_2072)) ^ BlClCKl_2938) + g_1369)) ^ (BlClCLg_2467 && (((-(g_2467)) * ((~((~((~(l_3110)))))) * (~((BlClCHg_1138 << (BlClCMg_275 && g_275)))))) ^ ((g_1138 ^ l_2712) & (~(g_1288)))))))))));
g_2467 = (~(((-(((((BlClCHg_1138 ^ l_2712) >> BlClCLg_2467) | g_1138) + ((~((~((((~((-(l_2002)))) + (~((g_1288 && BlClCKl_2938)))) & (BlClCIl_2002 ^ g_275)))))) ^ g_2467)))) ^ (~((((~(BlClCMg_275)) ^ g_1369) | (~(((-(l_3110)) && (l_2938 && (BlClCJl_2072 | (-(l_2072)))))))))))));
g_275 = (~(((((g_1288 | (~(((~((-(g_275)))) & (g_1369 >> (((l_2072 | g_1138) | l_2712) ^ (~(BlClCLg_2467)))))))) && (~(((BlClCJl_2072 * BlClCMg_275) && l_2938)))) | (~(BlClCKl_2938))) | ((-(((~(BlClCHg_1138)) && ((~(g_2467)) * (BlClCIl_2002 * l_3110))))) & (-((~((-(l_2002))))))))));
if((!((BlClCIl_2002 > BlClCHg_1138)) || !(g_1138))){
printf("g_1138=%llu\n", (unsigned long long)g_1138);
l_2072 = (~(((-((-((~((~((-((g_1138 >> g_1369))))))))))) << (((~(l_2938)) & (~((-((g_2467 * ((l_2072 * (-(l_2712))) ^ (-(BlClCHg_1138))))))))) ^ (~((((~((((l_2002 & g_1288) & BlClCJl_2072) | BlClCLg_2467))) + g_275) >> (((-(BlClCIl_2002)) && (l_3110 << BlClCMg_275)) && BlClCKl_2938))))))));
}
if((!BlClCJl_2072)){

{
                        return g_2043;
                    }

                    printf("l_2002=%llu\n", (unsigned long long)l_2002);
g_1138 = (-(((-(((-((((~((((-(g_1288)) | ((~((~((~(g_1369)))))) ^ (BlClCIl_2002 ^ l_2072))) & BlClCLg_2467))) | (BlClCMg_275 << BlClCKl_2938)) ^ (l_2938 | (~(l_3110)))))) * ((((~(l_2712)) >> ((-(g_2467)) * (g_275 | (-(BlClCJl_2072))))) >> (~(BlClCHg_1138))) * (~((-((~(g_1138)))))))))) << (~((~((~((~((~(l_2002)))))))))))));
continue;
}
if(!((g_1288 > g_2467))){
printf("l_2072=%lld\n", (long long)l_2072);
break;
}
if((!l_2002)){
printf("l_2938=%llu\n", (unsigned long long)l_2938);
goto lbl_2983;
}
if((((l_2712<=117) && (!BlClCLg_2467)) || !((l_2938 < l_3110)))){
printf("g_2467=%lld\n", (long long)g_2467);
break;
}
}
                                    while ((!g_2467) )
{

{
                    l_2508 = l_1724[4];
                    for (g_2852 = 0; (g_2852 <= 0); g_2852 += 1)
                    {
                        int i;
                        return g_1684[g_2852];
                    }
                }

}
                    g_1138 = BlClCHg_1138;
l_2002 = BlClCIl_2002;
l_2072 = BlClCJl_2072;
l_2938 = BlClCKl_2938;
g_2467 = BlClCLg_2467;
g_275 = BlClCMg_275;

                    l_1734[i] = 0x78FC6168L;}
    for (i = 0; i < 2; i++)
        l_1865[i] = (-3L);
                                        if ((((g_1599>18842) && (l_1706<=-1428240400)) || ((!l_75) || (g_35>-1))) )
{

l_1721 += 1;


}
                    for (i = 0; i < 5; i++)
        { if ((l_2712 < g_240))
                    while ((((!l_2712) && (!l_2354)) || ((g_1352>=-10) && (l_69 < g_1599))) )
{

for (g_3172 = 0; (g_3172 >= 0); g_3172 -= 1)
                    {
                        int8_t l_4920 = 0xD6L;
                        g_2580[0][7] = (((l_2829 & (safe_unary_minus_func_int32_t_s(l_2098))) > (0L != l_75)) && g_1369);
                        g_759 = l_4920;
                    };


}
                    l_3036[i] = 0x088BL;}
lbl_2626:
    if (p_52)
    {
        int16_t l_1683[8] = {0L,0L,1L,0L,0L,1L,0L,0L};
        int32_t l_1722 = 0xB739A435L;
        uint8_t l_1735 = 0x71L;
        uint8_t l_1775 = 0UL;
        uint16_t l_1840 = 0xCFCBL;
        int16_t l_1874[9][5] = {{0L,0L,0L,0L,0L},{0x25AAL,0x25AAL,0x25AAL,0x25AAL,0x25AAL},{0L,0L,0L,0L,0L},{0x25AAL,0x25AAL,0x25AAL,0x25AAL,0x25AAL},{0L,0L,0L,0L,0L},{0x25AAL,0x25AAL,0x25AAL,0x25AAL,0x25AAL},{0L,0L,0L,0L,0L},{0x25AAL,0x25AAL,0x25AAL,0x25AAL,0x25AAL},{0L,0L,0L,0L,0L}};
        uint8_t l_1890 = 0UL;
        int8_t l_1921 = 0x65L;
        int i, j;
        l_1706 = (+((func_54(func_60(((g_76 = (safe_add_func_int32_t_s_s((l_75 = ((((safe_div_func_uint16_t_u_u((g_35 , g_9), g_35)) , g_34[0]) >= ((l_69 = (safe_rshift_func_int16_t_s_u((g_68 = (-7L)), 1))) >= (safe_sub_func_uint8_t_u_u((((g_9 >= (0x0BA8L | p_52)) >= (safe_unary_minus_func_uint32_t_u(((safe_rshift_func_int16_t_s_u((g_9 != (-1L)), 15)) , 5UL)))) >= 0x10L), 2L)))) == l_75)), 0x19C81B93L))) != g_34[0])), l_1683[5], l_1683[5], g_34[0], g_1684[0]) > p_52) >= 0xBFD5A1B5L));
        for (g_759 = 0; (g_759 != 13); ++g_759)
        {
            int8_t l_1723[7] = {(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L)};
            int32_t l_1740 = (-3L);
            int32_t l_1797 = 0xAC81288AL;
            int32_t l_1864[8];
            int i;
            for (i = 0; i < 8; i++)
                l_1864[i] = (-8L);
            if (((p_52 != g_34[0]) != (0xB2F40E9DL > (((g_154 = ((safe_mod_func_uint16_t_u_u((((((safe_add_func_int8_t_s_s((((safe_mod_func_uint8_t_u_u((((safe_mod_func_int16_t_s_s((p_52 ^ (((safe_div_func_int8_t_s_s(g_573, p_52)) != (((l_1722 = ((l_1721 >= ((0x5E5AL == ((p_52 <= p_52) || p_52)) > g_76)) && g_204)) || 0xCAL) && l_69)) ^ 0x2BL)), g_469)) , g_9) , l_1683[5]), 0xB6L)) && g_1368) && l_1723[0]), l_1683[5])) == p_52) >= (-7L)) < l_1723[3]) && g_1370[1]), l_1724[4])) == l_1723[3])) <= 7L) > g_496[2]))))
            {
                int8_t l_1729 = 6L;
                int32_t l_1748 = (-8L);
                int32_t l_1756 = 0x6BA0C233L;
                uint16_t l_1796 = 0UL;
                uint32_t l_1863 = 2UL;
                for (g_1345 = 0; (g_1345 < 22); ++g_1345)
                {
                    for (g_1138 = 4; (g_1138 != 60); ++g_1138)
                    {
                        l_1729 = (p_52 == p_52);
                        return l_1724[4];
                    }
                    for (l_1729 = 1; (l_1729 <= 7); l_1729 += 1)
                    {
                        int i;
                        g_204 = (255UL >= l_1683[l_1729]);
                    }
                }
                for (g_469 = 0; (g_469 > 16); g_469 = safe_add_func_int16_t_s_s(g_469, 2))
                {
                    int16_t l_1755[8][9] = {{(-1L),(-1L),1L,1L,(-1L),(-1L),1L,1L,(-1L)},{2L,9L,2L,9L,2L,9L,2L,9L,2L},{(-1L),1L,1L,(-1L),(-1L),1L,1L,(-1L),(-1L)},{0x1923L,9L,0x1923L,9L,0x1923L,9L,0x1923L,9L,0x1923L},{(-1L),(-1L),1L,1L,(-1L),(-1L),1L,1L,(-1L)},{2L,9L,2L,9L,2L,9L,2L,9L,2L},{(-1L),1L,1L,(-1L),(-1L),1L,1L,(-1L),(-1L)},{0x1923L,9L,0x1923L,9L,0x1923L,9L,0x1923L,9L,0x1923L}};
                    int32_t l_1776 = 5L;
                    int i, j;
                    if ((l_1740 = (safe_rshift_func_int16_t_s_s(((((((l_1734[3] == g_68) ^ 0x9CD2L) | l_1735) && (l_1729 ^ p_52)) , (safe_div_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(g_897, p_52)), l_1723[1]))) < p_52), 7))))
                    {
                        return p_52;
                    }
                    else
                    {
                        int32_t l_1747 = 0xE484789FL;
                        l_1740 = 0x9158ADCEL;
                        l_1756 = (((g_1684[0] = (safe_lshift_func_int8_t_s_s(((safe_div_func_int16_t_s_s((((0L < ((l_1722 = (safe_lshift_func_uint8_t_u_s((l_1747 > (l_1748 = (g_1370[2] ^ l_1747))), p_52))) | (((safe_div_func_uint32_t_u_u(4294967295UL, ((((0UL | ((((g_1288 = (p_52 <= (safe_sub_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u((((l_1747 | g_1684[0]) , (-4L)) & l_1755[5][0]), 0x1D10L)), g_759)))) <= l_1729) < 0UL) || p_52)) && g_759) == p_52) , g_87))) || g_1684[0]) <= l_1706))) <= l_1747) <= p_52), p_52)) & g_98[1][3]), 5))) && g_68) < p_52);
                        g_1370[2] = (safe_mod_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s((safe_add_func_int8_t_s_s(((l_1776 = (safe_sub_func_uint32_t_u_u((l_1722 = (l_1683[1] && ((safe_rshift_func_int8_t_s_s((((safe_lshift_func_int16_t_s_u((((((safe_unary_minus_func_uint16_t_u((l_1706 < l_1756))) != (1L < (((safe_rshift_func_int16_t_s_u((~((g_897 = (safe_unary_minus_func_uint32_t_u(3UL))) >= (l_1755[5][0] , g_1352))), 15)) ^ ((l_1774 && l_1740) == l_1775)) , l_1755[5][0]))) == g_1599) >= p_52) && 1UL), 11)) >= g_1352) != l_1748), l_1755[6][2])) , p_52))), (-1L)))) && p_52), g_68)), 0x21038046L)) < 0UL), p_52));
                    }
                }
                if ((safe_lshift_func_uint8_t_u_s((l_1722 = l_1724[2]), (l_1774 >= l_1735))))
                {
                    uint32_t l_1807 = 0xF6B5ED28L;
                    int32_t l_1818[4];
                    uint32_t l_1827 = 0x8A5D70FCL;
                    int i;
                    for (i = 0; i < 4; i++)
                        l_1818[i] = 6L;
                    l_1756 = (((g_982 | (safe_add_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s(((((safe_unary_minus_func_uint32_t_u(((safe_div_func_uint16_t_u_u(((safe_mod_func_int16_t_s_s(((p_52 || ((g_98[1][3] , (((safe_mod_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_u(g_897, 1)), (safe_mod_func_uint16_t_u_u((g_98[2][0] = 0xFB08L), ((l_1740 = (-1L)) || (4294967295UL > 0UL)))))) & ((((l_1797 = l_1796) | 0UL) , l_75) == 0x734F5120L)) , g_469)) == p_52)) | 0xE713L), g_1798[5][2])) ^ 2L), 3L)) <= l_1706))) , 0xADL) , p_52) >= 1L), 0xA3D3L)), l_1723[1])) | 0x652AL), 0x6B644A65L))) & g_35) != l_1796);
                    if ((((safe_mod_func_int8_t_s_s((-1L), l_1706)) == (safe_add_func_uint16_t_u_u((p_52 < g_1352), 0x5E09L))) != 0x3602L))
                    {
                        l_1797 = (((((0x12L < ((p_52 , p_52) > (g_1345 = (((safe_sub_func_uint16_t_u_u((((((g_154 = g_573) || l_1807) != ((safe_rshift_func_uint8_t_u_u((p_52 < (safe_sub_func_uint32_t_u_u(((safe_add_func_uint32_t_u_u(l_1722, 0xE508973DL)) == ((safe_mod_func_int32_t_s_s(p_52, 0x7477AD3DL)) && 1L)), 0xB06F7772L))), 1)) , l_1748)) , 0xBED97184L) , g_1368), 7L)) > (-4L)) , 4294967295UL)))) & 0L) | g_472) <= l_1807) , 0xAF8DC3C4L);
                    }
                    else
                    {
                        uint32_t l_1819 = 0x9606BD0BL;
                        int32_t l_1866 = 0x00F4FFB0L;
                        l_1748 = (((safe_add_func_int8_t_s_s((l_1818[0] = l_1756), 255UL)) ^ ((((1L || ((g_1370[2] == 6L) >= (g_172 = (((l_1819 = g_1345) || (((safe_sub_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s(65530UL, (p_52 <= (safe_sub_func_int16_t_s_s(g_98[1][4], g_87))))), g_1345)) , g_68) != l_1819)) ^ l_1729)))) > l_1748) != l_1826) > 0x47EFL)) < g_34[0]);
                        l_1827 = g_1369;
                        g_204 = (safe_lshift_func_uint16_t_u_u((l_1722 = (safe_lshift_func_int16_t_s_u((1L | (safe_lshift_func_int16_t_s_u((((l_1796 >= ((p_52 >= ((l_1797 = (safe_lshift_func_uint16_t_u_u(l_1740, ((safe_lshift_func_uint16_t_u_s((g_275 , (safe_rshift_func_uint8_t_u_u(g_87, 5))), 0)) , l_1840)))) > (safe_sub_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u((((safe_sub_func_uint32_t_u_u((safe_sub_func_int32_t_s_s((((safe_div_func_int8_t_s_s((safe_mod_func_int32_t_s_s((safe_add_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((l_1864[3] = (safe_add_func_int32_t_s_s((((safe_sub_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u(0xC44DL, l_1863)), p_52)) < g_1370[2]) < g_982), 0xD148CE91L))), g_1288)) < 0x23L), p_52)), l_1863)), p_52)) , l_1827) < g_76), g_34[0])), 0UL)) < p_52) == l_1818[0]), p_52)), (-1L))))) || (-1L))) , l_75) < l_1865[0]), g_1798[2][7]))), l_1866))), g_1798[5][2]));
                        if (l_1740)
                            break;
                    }
                    g_1370[1] = 0xD59D4E86L;
                    if (l_1867)
                        continue;
                }
                else
                {
                    l_1722 = l_1724[4];
                    for (g_87 = 0; (g_87 <= 0); g_87 += 1)
                    {
                        int i;
                        return g_1684[g_87];
                    }
                }
            }
            else
            {
                uint32_t l_1888[3][2][4];
                int32_t l_1889 = 5L;
                int i, j, k;
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 2; j++)
                    {
                        for (k = 0; k < 4; k++)
                            l_1888[i][j][k] = 0xD73C7FA9L;
                    }
                }
                g_1370[2] = p_52;
                l_75 = (safe_mod_func_uint8_t_u_u((safe_div_func_int16_t_s_s((safe_sub_func_uint8_t_u_u(l_1874[7][2], g_506)), (safe_sub_func_uint32_t_u_u(((((-1L) >= ((((((safe_rshift_func_int16_t_s_u(g_335, 3)) >= (~(!((g_1370[0] = ((((l_1797 = g_1798[5][2]) | (safe_add_func_uint32_t_u_u((p_52 , (((g_87 < (!(l_1888[0][0][1] = (((safe_lshift_func_int16_t_s_s((((l_1864[2] = ((safe_add_func_uint32_t_u_u((0xBDE8109CL >= g_1370[0]), 0xA3248063L)) , 0x4AL)) || g_496[0]) <= l_1706), 3)) ^ l_1865[0]) || 0xF2L)))) > 0L) ^ l_1740)), g_98[3][1]))) , g_573) , (-1L))) <= l_1734[4])))) || g_1599) , g_472) ^ g_506) ^ p_52)) && 0xCC41L) != 1UL), 0UL)))), (-6L)));
                for (g_240 = 0; (g_240 <= 4); g_240 += 1)
                {
                    int i;
                    g_1370[1] = l_1734[g_240];
                    g_1370[2] = (((l_1889 = (p_52 && p_52)) < ((p_52 < (((((l_1890 , l_1734[g_240]) , (((safe_div_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((((l_1706 = ((safe_add_func_uint8_t_u_u((+(l_75 = (g_34[0] , (safe_unary_minus_func_int32_t_s(((((safe_sub_func_uint8_t_u_u(255UL, (248UL && (((safe_rshift_func_uint8_t_u_s(((((g_87 = (safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_u((safe_mod_func_int8_t_s_s((g_87 >= 0x083EL), g_87)), p_52)) , p_52), 6L))) || 0xE4L) || 1L) && p_52), 6)) != g_172) == g_98[2][0])))) >= l_1867) < g_34[0]) ^ p_52)))))), g_1370[2])) | p_52)) > 0x1C69L) < 9UL), p_52)), p_52)) & p_52) , 0xD5L)) >= l_1683[7]) | 1UL) >= g_35)) != l_1888[0][0][1])) || g_1368);
                    for (g_184 = 0; (g_184 <= 0); g_184 += 1)
                    {
                        int32_t l_1918 = 0x53669838L;
                        int i;
                        l_1918 = (safe_sub_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((l_1865[g_184] , (g_1684[g_184] || ((p_52 , p_52) && (+(g_154 = (!(+(safe_add_func_int32_t_s_s(p_52, 0x6F544798L))))))))), 0x80479FE7L)), 0x483FL));
                    }
                }
            }
        }
        l_1706 = (((((safe_lshift_func_uint8_t_u_s(0x1BL, (((l_1722 = p_52) == ((l_1921 > (g_1370[1] = (g_352 & ((((0xA0L >= (safe_mod_func_uint32_t_u_u(((((((((safe_sub_func_int8_t_s_s((l_75 = ((0UL < l_1683[5]) , (l_1734[3] = g_506))), 251UL)) || l_1874[7][2]) != p_52) & 0x1AE204F1L) > g_472) , g_1352) >= g_469) != l_1683[5]), l_1867))) > l_1890) && 6UL) || 1UL)))) , l_1706)) , 0xCDL))) >= p_52) , 0x25ED2621L) && 4L) <= p_52);
    }
    else
    {
        int8_t l_1949 = 8L;
        int32_t l_1954 = 1L;
        uint32_t l_2001[5][4][9] = {{{0x7333ECC1L,0UL,1UL,0x26862E16L,0x26862E16L,1UL,0UL,0x7333ECC1L,0UL},{1UL,4294967294UL,3UL,0xC8AEC303L,7UL,0x3EB0C3A7L,0x8AB2AE4DL,1UL,4UL},{0x8D766D12L,4294967295UL,0x8D766D12L,0x8AE0572FL,0UL,0x26862E16L,0UL,0UL,0UL},{0x3E8F8446L,0x1F6A1D16L,1UL,0x3EB0C3A7L,1UL,0x1F6A1D16L,0x3E8F8446L,1UL,3UL}},{{0UL,0x26862E16L,0UL,0x8AE0572FL,0x8D766D12L,4294967295UL,0x8D766D12L,0x8AE0572FL,0UL},{0x8AB2AE4DL,0x3EB0C3A7L,7UL,0xC8AEC303L,3UL,4294967294UL,1UL,1UL,1UL},{0UL,1UL,0x26862E16L,0x26862E16L,1UL,0UL,0x7333ECC1L,0UL,0x47CE93BCL},{0xC17D3C3EL,0x91F62C94L,7UL,0x913CFEB1L,0x3E8F8446L,4294967295UL,0x27AEE651L,1UL,4294967291UL}},{{1UL,0x98F38667L,0UL,0x8D766D12L,0xAAB6C81CL,0x8AE0572FL,0x8AE0572FL,0x8AE0572FL,0x98F38667L},{0UL,0x1F6A1D16L,0xC17D3C3EL,0x1F6A1D16L,0UL,0x88911984L,4UL,1UL,0x8AB2AE4DL},{0x7333ECC1L,0xAAB6C81CL,0x26862E16L,4294967295UL,0UL,4294967295UL,0x26862E16L,0xAAB6C81CL,0x7333ECC1L},{4294967291UL,0x17AD9BBAL,1UL,4294967294UL,7UL,0x88911984L,0x27AEE651L,0x88911984L,7UL}},{{0UL,0x47CE93BCL,0x47CE93BCL,0UL,4294967295UL,0x98F38667L,0x8D766D12L,4UL,0UL},{4294967291UL,1UL,0x27AEE651L,4294967295UL,0x3E8F8446L,0x913CFEB1L,7UL,0x91F62C94L,0xC17D3C3EL},{0x7333ECC1L,1UL,0UL,0x8AE0572FL,4294967295UL,4UL,4UL,4294967295UL,0x8AE0572FL},{0UL,0xC8AEC303L,0UL,0x17AD9BBAL,7UL,4294967295UL,4294967295UL,1UL,0xC17D3C3EL}},{{0x47CE93BCL,0x7333ECC1L,0UL,4UL,0UL,0x7333ECC1L,0x47CE93BCL,0x8D766D12L,0UL},{4294967295UL,4294967295UL,7UL,0x17AD9BBAL,0UL,0xC8AEC303L,0UL,0x17AD9BBAL,7UL},{4UL,4UL,4294967295UL,0x8AE0572FL,0UL,1UL,0x7333ECC1L,0x8D766D12L,0x7333ECC1L},{7UL,0x913CFEB1L,0x3E8F8446L,4294967295UL,0x27AEE651L,1UL,4294967291UL,1UL,0x8AB2AE4DL}}};
        int i, j, k;
        for (g_352 = 0; (g_352 < 21); g_352 = safe_add_func_int32_t_s_s(g_352, 9))
        {
            int8_t l_1933 = (-5L);
            uint32_t l_1938 = 3UL;
            int32_t l_1948 = 1L;
            int32_t l_2033 = 0xCCEC66BFL;
            int32_t l_2035[3];
            int i;
            for (i = 0; i < 3; i++)
                l_2035[i] = 4L;
            g_1370[2] = ((safe_sub_func_uint8_t_u_u(((((safe_rshift_func_int16_t_s_s(1L, 6)) != p_52) , (g_1684[0] | (~(p_52 & (((((l_1933 = l_1826) , (safe_div_func_int8_t_s_s((safe_add_func_int32_t_s_s((65532UL <= ((((l_1938 != (((safe_div_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_s((g_897 = (safe_div_func_uint8_t_u_u(((!g_275) ^ (safe_rshift_func_uint16_t_u_u(65533UL, 2))), g_1352))), 8)) == p_52), p_52)) != p_52) & g_759)) > 0xEE3BL) <= p_52) | p_52)), g_184)), 255UL))) , 0xC190C067L) , 0UL) , p_52))))) <= g_1288), l_1948)) , g_1352);
            l_1949 = g_76;
            if ((0x33D28A96L != ((safe_mod_func_uint16_t_u_u((0x5C8DL > ((l_1954 = ((-10L) == g_1599)) < ((safe_sub_func_uint32_t_u_u(5UL, (p_52 <= (safe_add_func_uint32_t_u_u(p_52, 0x1E12E0FFL))))) | (safe_sub_func_int8_t_s_s(0x04L, g_1288))))), 0x13BAL)) < l_1867)))
            {
                uint32_t l_1978 = 0x136D6AF1L;
                int32_t l_1999 = 0x28C55B2EL;
                int32_t l_2003 = 1L;
                int16_t l_2059[7] = {0xEFE6L,0xEFE6L,3L,0xEFE6L,0xEFE6L,3L,0xEFE6L};
                int i;
                if (((safe_add_func_int32_t_s_s((l_1948 = (safe_lshift_func_int16_t_s_s(l_1938, 0))), (g_472 | (safe_lshift_func_uint8_t_u_u((((p_52 , l_1938) >= (safe_lshift_func_uint16_t_u_s(((((safe_add_func_int16_t_s_s(p_52, (l_75 = ((p_52 != 0x5CC8B14BL) , (~(g_1684[0] = (((safe_sub_func_uint32_t_u_u(l_1954, (((safe_lshift_func_uint16_t_u_u(((l_1706 = ((safe_rshift_func_uint16_t_u_u(l_1978, 0)) & p_52)) == g_9), 2)) > (-1L)) <= g_469))) | p_52) || l_1933))))))) <= g_1138) , p_52) ^ p_52), 7))) == l_1826), 2))))) != 0x27L))
                {
                    int8_t l_2000 = 0x8DL;
                    int32_t l_2016[5];
                    int i;
                    for (i = 0; i < 5; i++)
                        l_2016[i] = 0xD1806C17L;
                    if (g_98[1][3])
                        break;
                    l_1948 = (safe_div_func_int32_t_s_s(l_1938, ((safe_lshift_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_u(g_184, 5)), ((((safe_mod_func_int16_t_s_s(0xD452L, (g_1684[0] = 0x0A36L))) < ((safe_add_func_int16_t_s_s((safe_rshift_func_int8_t_s_u(((g_1798[5][2] & ((safe_add_func_uint32_t_u_u((((safe_rshift_func_int8_t_s_s((g_1288 == (l_2002 = ((l_1954 = (g_982 , ((l_1999 && l_2000) & l_2001[3][3][6]))) ^ 0x4EL))), g_496[2])) | l_1938) , p_52), p_52)) < p_52)) & l_1949), 4)), l_2001[3][3][6])) > 0L)) <= p_52) && g_573))), g_1370[0])) <= 1L), 2)) , g_335)));
                    l_2003 = (p_52 > g_496[2]);
                    l_2016[3] = (g_98[1][4] ^ (((safe_lshift_func_int8_t_s_u((((safe_add_func_int16_t_s_s((((p_52 == (safe_div_func_uint16_t_u_u((l_1938 & g_76), ((g_1798[5][2] || (safe_lshift_func_uint8_t_u_u(l_1954, (~g_472)))) | p_52)))) > (((safe_rshift_func_uint16_t_u_s(((+g_506) >= g_573), 9)) <= l_1938) > 1UL)) , 0xC75CL), 0x6CEEL)) >= p_52) == p_52), 1)) , l_2003) , g_472));
                }
                else
                {
                    uint8_t l_2034 = 0x2AL;
                    l_2035[2] = (g_240 >= (((safe_add_func_int16_t_s_s(((((safe_add_func_uint32_t_u_u((l_1706 = (((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u((g_240 || ((l_1948 = 0xD31DC9A5L) > (safe_sub_func_int8_t_s_s(g_982, ((l_1933 < g_35) , (((((p_52 || (((safe_rshift_func_uint16_t_u_u((safe_div_func_int16_t_s_s((l_2033 = 0L), 0x5E9EL)), 0)) || p_52) >= g_472)) & l_2034) & p_52) != 0xDA33A5C5L) < g_1345)))))), p_52)) > l_2034), 0x314EL)) & 0x578DD792L) > 0x16L)), l_2034)) >= 0x2CA5L) || g_496[1]) , 8L), l_1867)) > 0x6F16L) > p_52));
                    g_1370[0] = p_52;
                }
                for (l_1867 = 0; (l_1867 <= 3); l_1867 += 1)
                {
                    int i, j;
                    g_2043 = ((((safe_mod_func_uint8_t_u_u(((((((l_1948 = ((g_1798[(l_1867 + 2)][(l_1867 + 4)] & (((p_52 , 65527UL) || ((!(p_52 == (g_204 = p_52))) < ((safe_sub_func_int8_t_s_s(p_52, (safe_mod_func_int32_t_s_s(g_1599, l_1867)))) ^ (g_1370[0] = (g_496[2] < p_52))))) , p_52)) && g_34[0])) && g_1798[(l_1867 + 2)][(l_1867 + 4)]) <= l_1734[3]) | 0x3FL) <= p_52) & g_1798[(l_1867 + 2)][(l_1867 + 4)]), 255UL)) ^ 1UL) & l_2001[3][3][6]) != p_52);
                    for (g_87 = 0; (g_87 <= 7); g_87 += 1)
                    {
                        int i, j, k;
                        return l_2001[(l_1867 + 1)][l_1867][l_1867];
                    }
                }
                l_2033 = (l_1948 = (safe_div_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u(l_1978, l_1978)) , (safe_div_func_uint16_t_u_u(0UL, ((safe_div_func_int16_t_s_s(l_2001[3][3][6], (safe_add_func_uint32_t_u_u(0x96641578L, p_52)))) | (4L & (g_496[2] != (!((safe_div_func_int8_t_s_s(g_240, p_52)) , p_52)))))))), l_2059[0])));
            }
            else
            {
                int16_t l_2060 = 0xDC69L;
                int32_t l_2061 = 0L;
                int32_t l_2062 = (-1L);
                int32_t l_2065 = 0xE44D0044L;
                l_2062 = ((g_1599 != (l_2061 = l_2060)) >= 0x51BFL);
                if (l_2060)
                    continue;
                if (l_1948)
                    continue;
                g_204 = (0x49C60D4FL < ((p_52 , (((safe_lshift_func_uint16_t_u_s((0xDFC8L != l_2065), ((safe_sub_func_uint32_t_u_u(l_1954, ((g_759 == ((g_1370[1] = p_52) ^ p_52)) < (l_2065 && l_1954)))) > p_52))) || g_1138) == l_2065)) < p_52));
            }
        }
    }
                                        while (((g_1368<2119372678U) && (g_184 < l_2508)) )
{

for (g_2043 = 0; g_2043 < 5; g_2043++)
                        l_1734[g_2043] = 0xD1806C17L;

}
                    if ((((safe_sub_func_uint32_t_u_u((((l_2072 & ((l_1734[1] = g_759) > (safe_lshift_func_uint16_t_u_u(p_52, 9)))) == (safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((safe_div_func_int16_t_s_s(g_1369, 0x8309L)) || (safe_lshift_func_int16_t_s_u(p_52, p_52))), 15)), ((safe_div_func_uint8_t_u_u((((p_52 & (safe_add_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s(((g_1138 == g_1352) && g_1288), p_52)), 0UL))) , l_1865[1]) | l_1774), (-6L))) , g_1599)))) , p_52), p_52)) < 0xBF3DF452L) , p_52))
    {
        uint16_t l_2089 = 0UL;
        int32_t l_2099 = 0L;
        l_2089 = (4294967286UL < p_52);
        l_1734[3] = (safe_lshift_func_uint8_t_u_s((g_472 = 0x31L), (safe_rshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(p_52, (l_2099 = ((l_1734[4] && (safe_rshift_func_uint8_t_u_u(g_1369, 6))) ^ ((((((-3L) && 0x5E66456EL) == l_1724[4]) > l_2098) ^ l_2002) , l_1867))))), 14))));
    }
    else
    {
        uint8_t l_2100 = 0UL;
        int32_t l_2149 = 0x23A017E2L;
        int32_t l_2275[8] = {(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L)};
        int32_t l_2786 = 0x0F6D7D0FL;
        uint32_t l_2855 = 4294967295UL;
        int i;
        for (l_1774 = 0; (l_1774 <= 4); l_1774 += 1)
        {
            const uint32_t l_2134 = 0UL;
            uint32_t l_2137 = 0xDA2A9E8BL;
            int32_t l_2141[10] = {1L,1L,1L,0L,1L,1L,1L,1L,0L,1L};
            uint16_t l_2420 = 0xC587L;
            int32_t l_2587 = 0xB5A4BC28L;
            int8_t l_2625 = 0x39L;
            int8_t l_2700[3][10] = {{1L,0L,0L,1L,0L,0L,1L,0L,0L,1L},{0L,1L,0L,0L,1L,0L,0L,1L,0L,0L},{1L,1L,(-3L),1L,1L,(-3L),1L,1L,(-3L),1L}};
            uint32_t l_2702 = 4294967294UL;
            int32_t l_2767 = (-5L);
            int i, j;

{
                    for (g_1352 = 0; (g_1352 >= (-12)); g_1352 = safe_sub_func_uint32_t_u_u(g_1352, 8))
                    {
                        int8_t l_1197[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            ;;
                        k = g_472;
                        if (g_1138)
                            continue;
                        k = g_6029;

if (l_2786) printf("index = [%d]\n", g_275);

                    l_75 = l_1197[0];
                    }
                    ;
                    ;
                }

                    if (l_2100)
            {
                uint32_t l_2138[5][8][5] = {{{6UL,6UL,0x7E054F2FL,0xD514974CL,0x7E054F2FL},{0UL,0UL,0UL,0xCF19F6D8L,0UL},{6UL,6UL,0x7E054F2FL,0xD514974CL,0x7E054F2FL},{0UL,0UL,0UL,0xCF19F6D8L,0UL},{6UL,6UL,0x7E054F2FL,0xD514974CL,0x7E054F2FL},{0UL,0UL,0UL,0xCF19F6D8L,0UL},{6UL,6UL,0x7E054F2FL,0xD514974CL,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL}},{{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL},{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL},{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL},{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL}},{{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL},{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL},{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL},{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL}},{{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL},{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL},{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL},{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL}},{{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL},{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL},{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL},{0x7E054F2FL,0x7E054F2FL,6UL,0xB71BC3B9L,6UL},{0UL,0UL,0x008B73DDL,0x688FCF34L,0x008B73DDL}}};
                int32_t l_2140 = (-6L);
                int8_t l_2196 = 7L;
                int i, j, k;

{
            ;

{
                        l_2140 = 0L;
                    }

                    if (j) printf("index = [%d][%d]\n", k, k);

        }

                    for (g_76 = 0; (g_76 <= 4); g_76 += 1)
                {
                    int32_t l_2136 = (-1L);
                    int32_t l_2139 = 0x947871ACL;
                    int i, j;

for (l_2767 = 29; (l_2767 != 28); l_2767 = safe_sub_func_int16_t_s_s(l_2767, 7))
                    {

{
                    uint8_t l_5436 = 0x0CL;
                    g_1370[1] = (~(((g_87 > (g_5210[0] , ((l_5436 ^ l_2100) <= (((safe_rshift_func_int16_t_s_u((((safe_sub_func_int32_t_s_s((((5L > (safe_rshift_func_uint16_t_u_u(65535UL, (safe_unary_minus_func_uint16_t_u(((safe_div_func_int8_t_s_s(0xA7L, g_5446[5])) && 0x30381104L)))))) , g_3600) ^ j), 0x795A4A13L)) && l_1867) , 0x3533L), g_897)) ^ 0xD4L) || i)))) && (-7L)) == l_2100));
                }

                    l_2829 = l_3067;
                        l_2829 = (((l_2712 = (-5L)) , (~(7UL && ((g_34[0] && g_6029) != (safe_mod_func_uint8_t_u_u(1UL, (safe_div_func_uint16_t_u_u((((g_2440 | (1UL ^ (g_6029 <= (l_2508 ^ g_1288)))) >= 0x083A407DL) ^ g_6029), 0x8056L)))))))) >= g_6029);
                    }
g_68 += 1;


                    ;


                    l_2141[9] = ((safe_lshift_func_int16_t_s_u((g_98[g_76][g_76] > (((safe_sub_func_int16_t_s_s((((safe_mod_func_uint16_t_u_u(((((l_2140 = (((safe_sub_func_uint32_t_u_u((l_1734[l_1774] == (l_75 = (safe_mod_func_int16_t_s_s((l_2139 = (+((g_506 >= (safe_div_func_int32_t_s_s(((((((safe_sub_func_uint16_t_u_u((~((safe_add_func_int32_t_s_s(((!(p_52 <= ((0x19E8L > (safe_sub_func_int16_t_s_s((((l_2072 >= (safe_mod_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((safe_add_func_uint32_t_u_u((g_1345 = g_472), (((safe_div_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(l_2134, (+(g_98[2][4] && 0x76L)))), g_1138)) || 0x137CBEB3L) == l_2136))), 7)), l_2137))) | p_52) & 1L), g_1368))) ^ 0xAA92FD8EL))) , p_52), 3UL)) && 0x6EC053F0L)), 1UL)) , 1L) > l_2138[1][5][4]) || 2L) <= 0L) != l_2138[1][5][4]), p_52))) == l_2134))), (-1L))))), p_52)) ^ l_1734[0]) >= 0UL)) && l_2134) == p_52) , 65535UL), g_472)) || 0xF6L) & 0L), g_496[3])) , 0x4D789618L) & p_52)), 6)) & g_472);
                    for (l_2072 = 1; (l_2072 >= 0); l_2072 -= 1)
                    {
                        int i;
                        ;
                    }
                    l_1734[0] = ((g_1352 = (safe_lshift_func_uint8_t_u_s((g_472 = (+(safe_div_func_uint32_t_u_u(4294967295UL, g_1368)))), 3))) || ((g_98[1][3] = 0x8FA4L) , ((l_2149 = l_2100) , (g_76 != (safe_rshift_func_uint8_t_u_s((+p_52), (safe_rshift_func_int8_t_s_u((g_154 = (safe_lshift_func_uint16_t_u_s((g_172 = 0x2C78L), ((l_2149 = l_2138[1][5][4]) >= ((safe_mod_func_int32_t_s_s(((((safe_rshift_func_uint16_t_u_u(((((l_2141[9] = p_52) || 0x6FL) || g_1288) , l_2161), g_98[g_76][g_76])) >= g_1798[5][2]) != l_2100) | g_76), p_52)) == 0xBC8EL))))), l_2100))))))));
                    return g_496[2];
                }
                if (l_2141[4])
                {

for (g_184 = 4; (g_184 != 60); ++g_184)
                    {

if (g_573) printf("index = [%d][%d]\n", l_2587, g_3486);

                    l_3153 = (l_1867 == l_1867);
                        return l_1724[4];
                    }
for (g_5844 = 13; (g_5844 >= 9); g_5844--)
                {
                    uint8_t l_5432 = 5UL;
                    if (l_5432)
                        break;
                };


                    ;



if (g_1684[0])
                        ;;


{
                        uint32_t l_4042 = 0xF2B5B59FL;
                        int32_t l_4043[8][7][2] = {{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}},{{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L}},{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}},{{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L}},{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}}};
                        int i, j, k;
                        l_4043[6][2][0] = l_4042;
                    }

                    return g_68;
                }
                else
                {
                    int16_t l_2181 = 6L;
                    l_2141[9] = ((safe_sub_func_int32_t_s_s((g_1288 > (l_2149 = (safe_sub_func_uint8_t_u_u((0x6412DD75L <= ((safe_add_func_int8_t_s_s(((safe_div_func_int8_t_s_s(((-10L) & (g_1599 < (((safe_rshift_func_int8_t_s_u((((safe_lshift_func_uint8_t_u_s((+((g_98[3][1] , 0xCD324B6EL) | p_52)), 0)) == (safe_lshift_func_int16_t_s_s((g_9 , (safe_rshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u((((((l_2100 ^ 0x7D8FL) || g_759) , g_352) ^ p_52) | l_2181), 11)), 4))), l_2134))) && g_1368), g_573)) > l_2181) || p_52))), p_52)) != 0x3330L), p_52)) , p_52)), l_75)))), l_2138[1][5][4])) == p_52);

for (g_1368 = 4; (g_1368 != 60); ++g_1368)
                    {
                        l_2712 = (p_52 == p_52);
                        return l_1724[4];
                    };


                    ;
                }
            }
            else
            {
                uint32_t l_2213 = 0x11C1CD4EL;
                int16_t l_2218 = (-6L);
                int32_t l_2219 = 0x6F331932L;
                l_2219 = (safe_sub_func_uint32_t_u_u(((safe_div_func_uint8_t_u_u((safe_mod_func_int16_t_s_s(((safe_mod_func_int16_t_s_s(((1UL < g_496[3]) , ((p_52 != ((safe_mod_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s((safe_add_func_int32_t_s_s(g_76, (((l_2213 , 4294967287UL) && (g_87 , 0xF87A7B04L)) , (g_1370[2] = (safe_mod_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_u(((l_2213 > p_52) | 1L), l_2141[8])) < 0x59B71C36L), l_1867)))))), (-2L))), l_2141[9])), g_1138)) == l_2141[0])) | 2L)), l_2218)) > p_52), 1UL)), 0xF3L)) <= g_1684[0]), g_1352));
            }
            for (g_506 = 1; (g_506 <= 4); g_506 += 1)
            {
                int i, j;
                l_1734[3] = (safe_add_func_uint8_t_u_u((safe_div_func_int8_t_s_s(((((((g_98[l_1774][l_1774] , (((safe_unary_minus_func_int8_t_s(((((safe_lshift_func_uint8_t_u_s((4294967286UL <= l_1734[l_1774]), 7)) > (0xB2L == ((safe_add_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s((g_87 = (safe_lshift_func_uint16_t_u_s(((((((((safe_lshift_func_uint16_t_u_s(l_1734[g_506], 15)) >= (l_1706 = (safe_mod_func_int8_t_s_s((255UL >= (((safe_add_func_uint32_t_u_u(p_52, (safe_rshift_func_int8_t_s_u((l_2149 > ((l_75 = (((g_1138 > l_2141[6]) >= 0xC4DEL) != p_52)) < 1UL)), g_1288)))) <= g_759) >= 1L)), (-1L))))) , 0x9CDA1B5EL) & p_52) <= 0L) <= g_2043) != l_2134) >= p_52), l_1724[4]))), l_1865[0])), l_1734[l_1774])) == l_2137))) , 250UL) != g_35))) | 4294967287UL) | l_1724[4])) & l_2137) || p_52) ^ 0UL) < l_2137) >= 0x49A26682L), g_506)), 6L));

;



g_3463 += 1;


                    l_2149 = p_52;

{
                        int i;
                        l_2149 = (safe_mod_func_uint16_t_u_u(l_1865[g_5844], l_2829));
                    }

                    g_1370[1] = (p_52 ^ ((l_75 = ((safe_rshift_func_int8_t_s_u(((safe_add_func_int8_t_s_s((safe_div_func_uint16_t_u_u(l_2072, ((((g_76 , (safe_mod_func_int32_t_s_s((l_2149 = ((safe_rshift_func_uint8_t_u_u(((safe_lshift_func_int8_t_s_u((safe_rshift_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s((65527UL ^ g_335), l_2137)), (l_1706 = ((safe_lshift_func_uint8_t_u_s(255UL, 6)) || (safe_lshift_func_uint16_t_u_s((safe_mod_func_uint16_t_u_u((safe_div_func_uint16_t_u_u((((0x7CB1L & ((l_2098 < p_52) >= p_52)) != g_1352) != g_759), g_9)), g_496[2])), 12)))))), l_2134)) >= 4294967288UL), 2)) | l_1734[3])), 0x0011C35BL))) >= g_76) != 5L) , l_2141[7]))), p_52)) , 1L), 2)) <= 0x5D4BC9A8L)) != p_52));
            }

if (g_5844)
                    continue;


{
                        return g_98[2][0];
                    }

                    if ((l_2275[0] = (((l_2149 = (l_2141[9] | ((l_2149 != g_1599) , l_2100))) , ((l_75 = ((((((l_2141[0] = g_1368) ^ (safe_div_func_int16_t_s_s((+((g_240 || ((((l_1734[3] = l_2100) , (safe_lshift_func_uint8_t_u_s((((-1L) ^ (p_52 < g_154)) > 0L), 0))) || g_172) <= p_52)) < 8UL)), l_1867))) , l_2149) >= (-9L)) || p_52) | l_2274[4])) >= l_2100)) <= p_52)))
            {
                int8_t l_2278 = 0x7AL;
                int32_t l_2294 = 0x8C93B29CL;
                int8_t l_2393[8][1] = {{0x46L},{(-2L)},{0x46L},{(-2L)},{0x46L},{(-2L)},{0x46L},{(-2L)}};
                int32_t l_2419 = (-1L);
                int32_t l_2423 = 0x0864B9FAL;
                int i, j;

if (g_2043) {
{
                        l_1865[g_5844] = 0x630AF406L;
                    }

                    printf("index = [%d][%d]\n", g_506, i);}


{
                    int32_t l_2439 = (-5L);
                    int32_t l_2469 = 0x87CB6C1CL;
                    l_2439 = (safe_add_func_int16_t_s_s((safe_sub_func_uint8_t_u_u((l_1826 & (safe_div_func_uint8_t_u_u((((g_5844 = (l_2141[3] != (-1L))) && ((((safe_sub_func_uint32_t_u_u((safe_div_func_int8_t_s_s(((((l_1826 < 0UL) ^ l_2141[8]) | (l_2294 >= (safe_add_func_int32_t_s_s(((((safe_sub_func_int16_t_s_s((l_2100 | g_1352), 1UL)) <= 0xE67AL) <= l_1826) && 0xED3AL), l_1826)))) > l_1826), g_68)), g_1352)) == l_1826) > 0x08A79D27L) , 0x4A23L)) | 0x54F5L), 1L))), l_3110)), l_2141[0]));
                    if (k)
                    {
                        g_2043 = (((safe_add_func_int8_t_s_s((((l_2393[1][0] , (((l_1734[3] > (l_2767 , (l_2098 = (!((((safe_mod_func_uint16_t_u_u((((g_1369 , (((l_2098 | ((safe_unary_minus_func_uint32_t_u((safe_mod_func_int16_t_s_s((safe_mod_func_uint32_t_u_u(l_1826, l_1826)), (((safe_rshift_func_uint16_t_u_s(l_2141[9], ((safe_sub_func_uint16_t_u_u((g_172 = (safe_div_func_int16_t_s_s(((safe_div_func_int32_t_s_s(l_1826, l_2354)) != (-4L)), g_1798[0][1]))), g_1368)) >= l_2393[6][0]))) && 1UL) || l_2982))))) , l_1826)) & (-2L)) && l_1826)) ^ g_98[1][3]) & 0xD9D8L), 0xD3DDL)) >= g_68) && 0L) <= g_1370[2]))))) || l_2354) > 0x57593B1FL)) != g_34[0]) , l_1826), l_1826)) , g_1138) || l_2982);
                        return g_5844;
                    }
                    else
                    {
                        uint16_t l_2479 = 0x7795L;
                        g_2043 = (((g_1370[2] = l_1826) ^ ((((safe_div_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s((safe_add_func_int8_t_s_s(g_1352, (safe_mod_func_uint8_t_u_u((g_154 , ((((((safe_unary_minus_func_int16_t_s((l_2469 = l_2439))) | (safe_rshift_func_int8_t_s_u(1L, ((l_2141[9] = ((safe_rshift_func_uint16_t_u_u((j | ((safe_lshift_func_uint8_t_u_u((0x0E4119E3L & (l_2479 = ((~0x0EL) > (0x3F5DL <= l_2439)))), 0)) , 0UL)), l_2982)) >= l_1826)) || l_2098)))) || 0xE4963751L) != (-9L)) ^ g_352) , g_1684[0])), g_5844)))), k)) && l_1826) <= 8UL), k)) >= l_2275[0]) ^ l_2002) , g_1138)) <= l_2439);
                        g_1370[2] = ((safe_lshift_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_u((safe_mod_func_uint8_t_u_u(((g_3193 = ((!((((safe_sub_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u((safe_unary_minus_func_int32_t_s(0xEE51BA25L)), 8L)), (safe_sub_func_int16_t_s_s(((safe_div_func_uint32_t_u_u(l_2354, l_1826)) || (g_1369 = (g_5844 < (((l_2479 > (((safe_mod_func_int32_t_s_s((safe_div_func_uint32_t_u_u(((((safe_rshift_func_uint16_t_u_u(0x7321L, (l_1826 <= (safe_mod_func_uint16_t_u_u(l_1826, g_3486))))) <= (-10L)) ^ 0UL) >= 0L), 4294967290UL)), 0x3330EDF6L)) < 255UL) , l_1826)) >= g_204) < l_2100)))), l_1826)))) , l_69) & 0xBAC6L), 0x9A2EL)) && j) , l_2393[1][0]) , 0x69L)) , l_1826)) , 1UL), 249UL)), 3)) >= g_1370[2]), l_1826)) > l_1826);
                        if (l_2982)
                            break;
                        l_2141[9] = (safe_rshift_func_uint8_t_u_u(((l_2423 <= (g_1288 = l_2439)) != (g_1684[0] = ((4UL | (((((l_2423 = (g_1369 = ((g_154 != (safe_lshift_func_int8_t_s_s(((safe_div_func_int32_t_s_s(l_1826, (safe_div_func_int8_t_s_s((+l_1826), (safe_add_func_uint16_t_u_u((+0x458B72EFL), ((~l_1826) ^ (safe_mod_func_int16_t_s_s(((l_2275[4] = (safe_sub_func_uint32_t_u_u((safe_add_func_int16_t_s_s(g_98[2][2], 0x774CL)), 1UL))) || 0xAC85L), 0xB2F3L))))))))) | l_1826), 4))) ^ g_5844))) & l_1826) || 0x3031L) , l_1826) & 0xEE68L)) , 0L))), g_1138));
                    }
                    l_2423 = (l_2275[2] = (l_2469 = 1L));
                }

                    if (l_2275[0])
                {
                    uint32_t l_2297 = 0x55CBB9E4L;
                    int32_t l_2327 = 0x922B026DL;
                    for (g_1345 = 0; (g_1345 <= 1); g_1345 += 1)
                    {
                        int i;

;


                    if (l_1865[g_1345])
                            break;
                    }

{
                        uint32_t l_666 = 4294967292UL;
                        int32_t l_677 = 0xC2919148L;

if (g_3193)
                        break;

                    i = (g_5512 == (safe_lshift_func_int16_t_s_u((l_666 >= 0xCA1FA15DL), 10)));

l_1706 -= 1;


                    g_506 = (l_2149 = (~(!(g_5512 <= (((0xBD3024CCL || (0x0624L == g_3193)) <= 0UL) > (g_87 == (safe_add_func_int16_t_s_s(((l_2829 = (((safe_mod_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((l_677 = 1UL), ((safe_div_func_uint8_t_u_u((g_3193 < (l_666 || g_3193)), 0x7AL)) > g_3193))), 0xCE57L)) & 0xC6L) && 1L)) >= g_3193), g_573))))))));
                    }

                    ;

g_506 -= 1;


                    l_2149 = (g_1370[2] = (safe_add_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_u(((g_1368 = (safe_lshift_func_uint8_t_u_s(((safe_lshift_func_int16_t_s_s((l_2278 , p_52), (l_75 = ((safe_rshift_func_uint16_t_u_s((safe_sub_func_uint32_t_u_u((((p_52 < ((p_52 , ((((g_1345 , (safe_add_func_uint32_t_u_u((g_184 = ((l_1734[4] = (l_2294 = (+0x2BE699C5L))) , (((((((l_2275[2] = g_2043) & (safe_mod_func_int8_t_s_s((g_204 , ((((((((l_2297 || 65535UL) | l_2297) | 0x7AL) , 2UL) , g_1599) ^ l_2149) , (-1L)) == 0xC9L)), g_154))) , p_52) > g_496[1]) >= 5L) , l_2100) < g_204))), g_98[1][3]))) , 0x47E1831EL) == l_1867) , 0x61318196L)) || g_1684[0])) || 0xCEL) <= l_2149), 0x14C086B2L)), 0)) <= g_469)))) <= p_52), l_2149))) >= g_496[2]), p_52)) , p_52), g_1798[5][2])));
                    if ((l_2327 = (l_75 = (((safe_rshift_func_int8_t_s_s((((!0x9441L) , ((safe_sub_func_uint8_t_u_u((g_472 = (safe_add_func_int8_t_s_s((((((safe_rshift_func_uint8_t_u_s((safe_sub_func_uint16_t_u_u(((((safe_rshift_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_u((((safe_rshift_func_int8_t_s_s(l_2297, 6)) > ((((((((((((65532UL ^ l_2134) && (g_1352 = p_52)) || (safe_sub_func_uint8_t_u_u((safe_add_func_int8_t_s_s((safe_mod_func_uint8_t_u_u(((((safe_div_func_uint8_t_u_u((0xD085BC04L == (safe_lshift_func_int8_t_s_s((safe_div_func_int16_t_s_s(((g_87 = ((g_2043 | p_52) , (l_2141[5] = g_1369))) <= l_2278), l_2275[7])), l_2098))), (-5L))) , p_52) && 1L) > g_1369), 0xA7L)), 251UL)), p_52))) < p_52) , l_2137) | g_335) != g_1798[5][2]) && p_52) || 0x50L) , g_98[3][2]) , g_98[3][2]) != 65528UL)) , g_1798[4][7]), 8)) || 0xA4DFL), 3)) ^ p_52) == 0L) && 0xCB485377L), g_154)), 0)) || p_52) | l_2297) < g_506) <= l_2100), 0xE7L))), p_52)) , p_52)) , g_335), l_2275[4])) , 0x2A70L) >= g_35))))
                    {
                        int32_t l_2330 = 0xB0B48C1AL;

{
                    for (l_2587 = 24; (l_2587 != 8); l_2587 = safe_sub_func_int8_t_s_s(l_2587, 7))
                    {
                        if (g_6029)
                            break;


if (g_3486) printf("index = [%d][%d]\n", g_275, l_2508);

                    if (g_204) {
{
                        uint32_t l_6538[6][1];
                        int i, j;
                        for (i = 0; i < 6; i++)
                        {
                            for (j = 0; j < 1; j++)
                                l_6538[i][j] = 0x22EB942DL;
                        }
                        l_6538[2][0] = g_4475;
                        l_2327 = ((l_2278 = g_5225) >= l_2327);
                    }

                    printf("index = [%d]\n", l_75);}


g_506 -= 1;


                    l_2421 = g_1288;
                    }
                }


for (l_2829 = 0; l_2829 < 10; l_2829++)
                l_2141[l_2829] = 0x3F83C38EL;

                    ;

l_2421 += 1;


                    l_2327 = g_1352;
                    }
                    else
                    {


g_3193 += 1;



{
        uint32_t l_4603[2][5] = {{4294967295UL,0xDB78D99EL,4294967295UL,0xDB78D99EL,4294967295UL},{4294967295UL,0xDB78D99EL,4294967295UL,0xDB78D99EL,4294967295UL}};
        int32_t l_4604 = 0xF5237A90L;
        int i, j;

{
                        uint8_t l_2850 = 0x3FL;
                        int i;
                        if (g_1370[0])
                            break;
                        g_76 = (g_2853[2][0][3] = ((((safe_lshift_func_uint8_t_u_u(246UL, l_2297)) <= (l_2275[g_9] = (0x735CL > (((l_2297 == (~((safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((l_1734[4] = (((((safe_add_func_int16_t_s_s(((i > (l_2850 && (((0x7379E06FL | (((g_1370[0] , ((((safe_unary_minus_func_uint16_t_u(l_2297)) || 0x8FA5L) == 2L) == g_1370[2])) & l_2297) | 0x50L)) , g_1369) >= 0x1D7CL))) < 0xBD1BDA5BL), 0x667EL)) && l_2327) && l_2712) == g_2853[0][6][6]) < l_2829)) , g_982), (-1L))), l_2297)) | g_2422))) ^ 8UL) ^ g_5844)))) , g_9) | 0xCFL));
                        if (g_3193)
                            break;
                    }

                    ;
        return g_1352;
    }

                    g_352 += 1;


                    l_2275[7] = 0xC9C3F7B3L;
                    }
                }
                else
                {
                    uint16_t l_2396 = 5UL;
                    int32_t l_2397 = 0x385A9D34L;



for (l_2712 = 12; (l_2712 < 17); l_2712++)
            {
                return l_1865[1];
            };


                    l_2423 = (safe_sub_func_uint8_t_u_u((g_1138 || (-1L)), (safe_sub_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((g_2422 = (g_154 = ((((((l_1734[3] >= (((((safe_rshift_func_int16_t_s_u((l_2294 = (g_68 & 0x9253L)), 10)) != (l_2141[1] = (safe_rshift_func_int8_t_s_s((-9L), (safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_div_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(((((l_2149 = (l_2419 = (l_2275[0] = (0x9AC0L ^ ((p_52 , l_2275[0]) , p_52))))) > g_1370[1]) ^ g_204) >= l_2420), p_52)), 1UL)), 13)), l_2421)))))) | l_2278) == g_34[0]) == p_52)) | 65527UL) > (-4L)) < g_1684[0]) || p_52) ^ p_52))), p_52)), l_2397))));
                }
                if (l_2424[5][4])
                {
                    int32_t l_2439 = (-5L);
                    int32_t l_2469 = 0x87CB6C1CL;

for (j = 0; j < 3; j++)
                    ;;

                    l_2439 = (safe_add_func_int16_t_s_s((safe_sub_func_uint8_t_u_u((p_52 & (safe_div_func_uint8_t_u_u((((g_1288 = (l_2141[3] != (-1L))) && ((((safe_sub_func_uint32_t_u_u((safe_div_func_int8_t_s_s(((((p_52 < 0UL) ^ l_2141[8]) | (l_2423 >= (safe_add_func_int32_t_s_s(((((safe_sub_func_int16_t_s_s((l_2100 | l_2072), 1UL)) <= 0xE67AL) <= p_52) && 0xED3AL), p_52)))) > p_52), g_759)), l_2072)) == p_52) > 0x08A79D27L) , 0x4A23L)) | 0x54F5L), 1L))), l_2420)), l_2141[0]));


{
                    uint16_t l_2396 = 5UL;
                    int32_t l_2397 = 0x385A9D34L;

{
                        uint32_t l_3124 = 0UL;
                        int32_t l_3125 = 0xC3763125L;
                        l_3124 = (g_76 != g_275);
                        ;
                    }

                    for (l_2855 = 0; (l_2855 <= 7); l_2855 += 1)
                    {
                        int8_t l_2353 = 0L;
                        int i, j;
                        l_2439 = (((-5L) > ((g_98[l_2161][l_2161] && (((l_2275[l_2855] = (safe_rshift_func_uint16_t_u_u(l_2275[l_2855], (l_2275[l_2855] , (l_1734[3] = (safe_div_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_u(g_496[0], 4)), ((g_1368 <= g_1368) || (safe_add_func_uint8_t_u_u(((l_2439 , (((safe_mod_func_uint32_t_u_u(g_1368, 0x70F2C52EL)) < l_2002) > g_897)) != 0x456BBDACL), g_496[2])))))))))) || g_1368) || 0x5EL)) >= (-1L))) < 4294967295UL);
                        l_2275[l_2855] = (safe_lshift_func_int8_t_s_s((((l_2002 == 1L) || ((l_1734[3] = ((l_2439 , 0x78L) < (safe_rshift_func_uint8_t_u_s((+(g_1368 == (safe_mod_func_uint16_t_u_u(l_2275[l_2855], (safe_rshift_func_uint8_t_u_s((+((((safe_lshift_func_int8_t_s_s(l_2161, (0x7AF5L || l_2353))) > g_1368) , g_897) | 4294967288UL)), l_2161)))))), 4)))) , g_1368)) & 0x5330L), g_897));
                        if (g_1368)
                            break;
                    }
                    if ((((safe_div_func_uint8_t_u_u(g_1368, (l_2439 = 249UL))) && j) <= (((safe_rshift_func_uint8_t_u_s(248UL, g_34[0])) == (((l_2141[9] = (safe_lshift_func_int16_t_s_u(((safe_rshift_func_uint8_t_u_u((((+((!(((((safe_lshift_func_uint16_t_u_s((safe_add_func_int32_t_s_s(i, l_2141[3])), 2)) != 0x73L) , (((safe_add_func_int16_t_s_s(l_2702, g_1368)) , 0xBCL) , g_1368)) < l_2161) <= l_2625)) != g_1368)) == 3UL) , l_2702), g_1368)) && 0L), 2))) > g_1368) > g_1368)) <= 1L)))
                    {
                        int8_t l_2394 = 0x6AL;
                        int32_t l_2395 = 0xB0BB232FL;


{
                        return g_5512;
                    }

                    for (g_240 = 0; g_240 < 1; g_240++)
    {
        transparent_crc(g_5210[g_240], "g_5210[g_240]", g_275);
        if (g_275) printf("index = [%d]\n", g_240);

    };


                    ;
                        if (g_1370[2])
                            ;;
                    }
                    else
                    {

g_1138 += 1;


                    g_1370[1] = ((l_2397 = l_2396) ^ ((safe_sub_func_uint8_t_u_u(((+g_1368) , i), (-10L))) || g_4475));
                    }

for (l_2072 = 6; (l_2072 > 5); --l_2072)
                    {
                        uint32_t l_666 = 4294967292UL;
                        int32_t l_677 = 0xC2919148L;
                        l_1706 = (g_6428 == (safe_lshift_func_int16_t_s_u((l_666 >= 0xCA1FA15DL), 10)));
                        g_573 = (g_2440 = (~(!(g_6428 <= (((0xBD3024CCL || (0x0624L == g_4475)) <= 0UL) > (g_4475 == (safe_add_func_int16_t_s_s(((l_2829 = (((safe_mod_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((l_677 = 1UL), ((safe_div_func_uint8_t_u_u((g_4475 < (l_666 || g_4475)), 0x7AL)) > g_4475))), 0xCE57L)) & 0xC6L) && 1L)) >= g_4475), g_3486))))))));
                    };


                    g_275 = (safe_sub_func_uint8_t_u_u((l_2002 || (-1L)), (safe_sub_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((l_2625 = (l_2625 = ((((((l_1734[3] >= (((((safe_rshift_func_int16_t_s_u((l_2439 = (g_1368 & 0x9253L)), 10)) != (l_2141[1] = (safe_rshift_func_int8_t_s_s((-9L), (safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_div_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(((((l_2439 = (j = (l_2275[0] = (0x9AC0L ^ ((g_1368 , l_2275[0]) , g_1368))))) > g_1370[1]) ^ l_2829) >= g_3317), g_1368)), 1UL)), 13)), g_1368)))))) | l_2161) == g_34[0]) == g_1368)) | 65527UL) > (-4L)) < g_1684[0]) || g_1368) ^ g_1368))), g_1368)), l_2397))));
                }

                    l_2149 = (l_2275[2] = (l_2469 = 1L));
                }
                else
                {
                    uint8_t l_2586 = 0UL;
                    int32_t l_2588 = 0xF3441496L;

{


{
        int8_t l_1949 = 8L;
        int32_t l_1954 = 1L;
        uint32_t l_2001[5][4][9] = {{{0x7333ECC1L,0UL,1UL,0x26862E16L,0x26862E16L,1UL,0UL,0x7333ECC1L,0UL},{1UL,4294967294UL,3UL,0xC8AEC303L,7UL,0x3EB0C3A7L,0x8AB2AE4DL,1UL,4UL},{0x8D766D12L,4294967295UL,0x8D766D12L,0x8AE0572FL,0UL,0x26862E16L,0UL,0UL,0UL},{0x3E8F8446L,0x1F6A1D16L,1UL,0x3EB0C3A7L,1UL,0x1F6A1D16L,0x3E8F8446L,1UL,3UL}},{{0UL,0x26862E16L,0UL,0x8AE0572FL,0x8D766D12L,4294967295UL,0x8D766D12L,0x8AE0572FL,0UL},{0x8AB2AE4DL,0x3EB0C3A7L,7UL,0xC8AEC303L,3UL,4294967294UL,1UL,1UL,1UL},{0UL,1UL,0x26862E16L,0x26862E16L,1UL,0UL,0x7333ECC1L,0UL,0x47CE93BCL},{0xC17D3C3EL,0x91F62C94L,7UL,0x913CFEB1L,0x3E8F8446L,4294967295UL,0x27AEE651L,1UL,4294967291UL}},{{1UL,0x98F38667L,0UL,0x8D766D12L,0xAAB6C81CL,0x8AE0572FL,0x8AE0572FL,0x8AE0572FL,0x98F38667L},{0UL,0x1F6A1D16L,0xC17D3C3EL,0x1F6A1D16L,0UL,0x88911984L,4UL,1UL,0x8AB2AE4DL},{0x7333ECC1L,0xAAB6C81CL,0x26862E16L,4294967295UL,0UL,4294967295UL,0x26862E16L,0xAAB6C81CL,0x7333ECC1L},{4294967291UL,0x17AD9BBAL,1UL,4294967294UL,7UL,0x88911984L,0x27AEE651L,0x88911984L,7UL}},{{0UL,0x47CE93BCL,0x47CE93BCL,0UL,4294967295UL,0x98F38667L,0x8D766D12L,4UL,0UL},{4294967291UL,1UL,0x27AEE651L,4294967295UL,0x3E8F8446L,0x913CFEB1L,7UL,0x91F62C94L,0xC17D3C3EL},{0x7333ECC1L,1UL,0UL,0x8AE0572FL,4294967295UL,4UL,4UL,4294967295UL,0x8AE0572FL},{0UL,0xC8AEC303L,0UL,0x17AD9BBAL,7UL,4294967295UL,4294967295UL,1UL,0xC17D3C3EL}},{{0x47CE93BCL,0x7333ECC1L,0UL,4UL,0UL,0x7333ECC1L,0x47CE93BCL,0x8D766D12L,0UL},{4294967295UL,4294967295UL,7UL,0x17AD9BBAL,0UL,0xC8AEC303L,0UL,0x17AD9BBAL,7UL},{4UL,4UL,4294967295UL,0x8AE0572FL,0UL,1UL,0x7333ECC1L,0x8D766D12L,0x7333ECC1L},{7UL,0x913CFEB1L,0x3E8F8446L,4294967295UL,0x27AEE651L,1UL,4294967291UL,1UL,0x8AB2AE4DL}}};
        int i, j, k;
        for (l_2855 = 0; (l_2855 < 21); l_2855 = safe_add_func_int32_t_s_s(l_2855, 9))
        {
            int8_t l_1933 = (-5L);
            uint32_t l_1938 = 3UL;
            int32_t l_1948 = 1L;
            int32_t l_2033 = 0xCCEC66BFL;
            int32_t l_2035[3];
            int i;
            for (i = 0; i < 3; i++)
                l_2035[i] = 4L;
            g_1370[2] = ((safe_sub_func_uint8_t_u_u(((((safe_rshift_func_int16_t_s_s(1L, 6)) != p_52) , (g_1684[0] | (~(p_52 & (((((l_1933 = g_1368) , (safe_div_func_int8_t_s_s((safe_add_func_int32_t_s_s((65532UL <= ((((l_1938 != (((safe_div_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_s((g_897 = (safe_div_func_uint8_t_u_u(((!g_2440) ^ (safe_rshift_func_uint16_t_u_u(65533UL, 2))), g_897))), 8)) == p_52), p_52)) != p_52) & l_2702)) > 0xEE3BL) <= p_52) | p_52)), g_6771)), 255UL))) , 0xC190C067L) , 0UL) , p_52))))) <= g_5512), l_1948)) , g_897);
            l_1949 = g_469;
            if ((0x33D28A96L != ((safe_mod_func_uint16_t_u_u((0x5C8DL > ((l_1954 = ((-10L) == l_69)) < ((safe_sub_func_uint32_t_u_u(5UL, (p_52 <= (safe_add_func_uint32_t_u_u(p_52, 0x1E12E0FFL))))) | (safe_sub_func_int8_t_s_s(0x04L, g_5512))))), 0x13BAL)) < l_1826)))
            {
                uint32_t l_1978 = 0x136D6AF1L;
                int32_t l_1999 = 0x28C55B2EL;
                int32_t l_2003 = 1L;
                int16_t l_2059[7] = {0xEFE6L,0xEFE6L,3L,0xEFE6L,0xEFE6L,3L,0xEFE6L};
                int i;
                if (((safe_add_func_int32_t_s_s((l_1948 = (safe_lshift_func_int16_t_s_s(l_1938, 0))), (g_4475 | (safe_lshift_func_uint8_t_u_u((((p_52 , l_1938) >= (safe_lshift_func_uint16_t_u_s(((((safe_add_func_int16_t_s_s(p_52, (i = ((p_52 != 0x5CC8B14BL) , (~(g_1684[0] = (((safe_sub_func_uint32_t_u_u(l_1954, (((safe_lshift_func_uint16_t_u_u(((l_2588 = ((safe_rshift_func_uint16_t_u_u(l_1978, 0)) & p_52)) == l_2100), 2)) > (-1L)) <= g_184))) | p_52) || l_1933))))))) <= g_68) , p_52) ^ p_52), 7))) == g_1368), 2))))) != 0x27L))
                {
                    int8_t l_2000 = 0x8DL;
                    int32_t l_2016[5];
                    int i;
                    for (i = 0; i < 5; i++)
                        l_2016[i] = 0xD1806C17L;
                    if (g_98[1][3])
                        break;
                    l_1948 = (safe_div_func_int32_t_s_s(l_1938, ((safe_lshift_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_u(g_6771, 5)), ((((safe_mod_func_int16_t_s_s(0xD452L, (g_1684[0] = 0x0A36L))) < ((safe_add_func_int16_t_s_s((safe_rshift_func_int8_t_s_u(((g_1798[5][2] & ((safe_add_func_uint32_t_u_u((((safe_rshift_func_int8_t_s_s((g_5512 == (g_184 = ((l_1954 = (l_2098 , ((l_1999 && l_2000) & l_2001[3][3][6]))) ^ 0x4EL))), g_496[2])) | l_1938) , p_52), p_52)) < p_52)) & l_1949), 4)), l_2001[3][3][6])) > 0L)) <= p_52) && i))), g_1370[0])) <= 1L), 2)) , l_2072)));
                    l_2003 = (p_52 > g_496[2]);
                    l_2016[3] = (g_98[1][4] ^ (((safe_lshift_func_int8_t_s_u((((safe_add_func_int16_t_s_s((((p_52 == (safe_div_func_uint16_t_u_u((l_1938 & g_469), ((g_1798[5][2] || (safe_lshift_func_uint8_t_u_u(l_1954, (~g_4475)))) | p_52)))) > (((safe_rshift_func_uint16_t_u_s(((+l_2423) >= i), 9)) <= l_1938) > 1UL)) , 0xC75CL), 0x6CEEL)) >= p_52) == p_52), 1)) , l_2003) , g_4475));
                }
                else
                {
                    uint8_t l_2034 = 0x2AL;
                    l_2035[2] = (l_2149 >= (((safe_add_func_int16_t_s_s(((((safe_add_func_uint32_t_u_u((l_2588 = (((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u((l_2149 || ((l_1948 = 0xD31DC9A5L) > (safe_sub_func_int8_t_s_s(l_2098, ((l_1933 < g_5512) , (((((p_52 || (((safe_rshift_func_uint16_t_u_u((safe_div_func_int16_t_s_s((l_2033 = 0L), 0x5E9EL)), 0)) || p_52) >= g_4475)) & l_2034) & p_52) != 0xDA33A5C5L) < g_68)))))), p_52)) > l_2034), 0x314EL)) & 0x578DD792L) > 0x16L)), l_2034)) >= 0x2CA5L) || g_496[1]) , 8L), l_1826)) > 0x6F16L) > p_52));
                    g_1370[0] = p_52;
                }
                for (l_1826 = 0; (l_1826 <= 3); l_1826 += 1)
                {
                    int i, j;
                    k = ((((safe_mod_func_uint8_t_u_u(((((((l_1948 = ((g_1798[(l_1826 + 2)][(l_1826 + 4)] & (((p_52 , 65527UL) || ((!(p_52 == (l_2149 = p_52))) < ((safe_sub_func_int8_t_s_s(p_52, (safe_mod_func_int32_t_s_s(l_69, l_1826)))) ^ (g_1370[0] = (g_496[2] < p_52))))) , p_52)) && g_34[0])) && g_1798[(l_1826 + 2)][(l_1826 + 4)]) <= l_1734[3]) | 0x3FL) <= p_52) & g_1798[(l_1826 + 2)][(l_1826 + 4)]), 255UL)) ^ 1UL) & l_2001[3][3][6]) != p_52);
                    for (g_2852 = 0; (g_2852 <= 7); g_2852 += 1)
                    {
                        int i, j, k;
                        return l_2001[(l_1826 + 1)][l_1826][l_1826];
                    }
                }
                l_2033 = (l_1948 = (safe_div_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u(l_1978, l_1978)) , (safe_div_func_uint16_t_u_u(0UL, ((safe_div_func_int16_t_s_s(l_2001[3][3][6], (safe_add_func_uint32_t_u_u(0x96641578L, p_52)))) | (4L & (g_496[2] != (!((safe_div_func_int8_t_s_s(l_2149, p_52)) , p_52)))))))), l_2059[0])));
            }
            else
            {
                int16_t l_2060 = 0xDC69L;
                int32_t l_2061 = 0L;
                int32_t l_2062 = (-1L);
                int32_t l_2065 = 0xE44D0044L;
                l_2062 = ((l_69 != (l_2061 = l_2060)) >= 0x51BFL);
                if (l_2060)
                    continue;
                if (l_1948)
                    continue;
                l_2149 = (0x49C60D4FL < ((p_52 , (((safe_lshift_func_uint16_t_u_s((0xDFC8L != l_2065), ((safe_sub_func_uint32_t_u_u(l_1954, ((l_2702 == ((g_1370[1] = p_52) ^ p_52)) < (l_2065 && l_1954)))) > p_52))) || g_68) == l_2065)) < p_52));
            }
        }
    }

                    for (l_2149 = 0; l_2149 < 5; l_2149++)
    {
        for (k = 0; k < 5; k++)
        {

for (g_3463 = 0; (g_3463 <= 0); g_3463 += 1)
                {
                    int i, j;
                    if ((g_2580[(l_1826 + 1)][(l_2625 + 1)] > (safe_add_func_int8_t_s_s(g_1684[g_3463], g_1288))))
                    {
                        int32_t l_2741 = 0L;
                        int i, j;

if (g_9)
                            break;

                    g_1370[2] = g_1684[g_3463];
                        g_506 = l_2137;
                        g_1370[1] = (!(g_469 >= ((g_172 = (safe_rshift_func_int8_t_s_s((safe_unary_minus_func_uint8_t_u(((g_1684[g_3463] = ((g_3463 = ((0UL < l_2700[2][8]) ^ (safe_unary_minus_func_int8_t_s((l_1867 > ((safe_sub_func_uint32_t_u_u(l_2275[1], (l_2419 = l_2137))) >= (!((safe_sub_func_int32_t_s_s(l_2137, ((safe_div_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(l_2161, ((g_98[(g_3463 + 3)][(l_1826 + 1)] = l_1724[1]) || l_2275[0]))), (-1L))) , l_2137))) < l_2625)))))))) || l_2625)) & (-1L)))), 0))) <= l_1865[l_1826])));
                        g_506 = ((safe_mod_func_int8_t_s_s((((safe_sub_func_uint8_t_u_u((safe_div_func_int16_t_s_s((((0x6ED1L & ((g_34[0] > (g_5844 = ((g_1684[0] > ((safe_mod_func_int32_t_s_s(((((((safe_mod_func_uint32_t_u_u(0UL, ((safe_sub_func_int16_t_s_s(((safe_add_func_uint16_t_u_u((safe_sub_func_int32_t_s_s((4294967293UL >= ((safe_sub_func_uint32_t_u_u(g_2580[(l_1826 + 1)][(l_2625 + 1)], ((safe_rshift_func_int8_t_s_u((safe_add_func_uint32_t_u_u((((-1L) | ((safe_rshift_func_int16_t_s_u((safe_div_func_int8_t_s_s(g_335, ((g_335 = (((((safe_rshift_func_int8_t_s_s(g_3463, 1)) > g_472) , l_1865[l_1826]) , 6L) >= l_2137)) & g_4475))), 5)) ^ l_2137)) != l_2137), g_1288)), g_6771)) <= l_2419))) < g_1684[g_3463])), l_2161)), l_2741)) | g_1798[2][1]), (-1L))) , l_2137))) < g_506) && 65535UL) ^ l_1826) , 0UL) & 0x3FL), g_1288)) == l_1865[l_1826])) & 1L))) && 0UL)) < g_1370[2]) < l_1865[l_1826]), 0xD75EL)), 0xABL)) >= 0x5C62L) , 0x78L), l_2137)) == l_2741);
                    }
                    else
                    {
                        if (l_2137)
                            break;
                        l_2588 = g_98[l_2625][(l_1826 + 2)];
                    }
                    for (l_3110 = 7; (l_3110 < 43); l_3110++)
                    {
                        int8_t l_2744 = 0xC2L;
                        if (g_573)
                            goto lbl_2626;
                        return l_2744;
                    }
                    return l_2588;
                };


                    ;
            ;

        }
    };



{
        transparent_crc(g_13[l_2588], "g_13[l_2588]", l_2508);
        if (l_2508) printf("index = [%d]\n", l_2588);

    }

                    return j;
                    }

                    if ((g_1370[0] = ((l_1734[3] = (safe_rshift_func_int16_t_s_u((safe_add_func_int8_t_s_s((l_1865[0] , (safe_mod_func_uint8_t_u_u((safe_div_func_uint8_t_u_u((l_2294 = ((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_s((safe_mod_func_int32_t_s_s((safe_mod_func_int32_t_s_s((!(~(l_2423 && (safe_lshift_func_uint16_t_u_u((((safe_lshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((((((1UL > p_52) == ((l_1706 = (safe_div_func_uint16_t_u_u((p_52 == (safe_rshift_func_int16_t_s_s(((0x6BL & ((l_2275[3] = (p_52 && (l_2137 && (safe_mod_func_uint32_t_u_u(((g_87 = 1UL) || 0x3DL), p_52))))) | l_2294)) >= l_69), p_52))), p_52))) && p_52)) & p_52) , g_1369) >= p_52), 0x90EBL)) != 0x6EL), p_52)), 4)) < p_52) > 65531UL), 14))))), g_1798[5][2])), 4294967295UL)), p_52)), l_2141[1])) || g_1798[2][1])), 0x6AL)), l_2141[1]))), g_759)), 9))) , p_52)))
                    {
                        int32_t l_2584 = (-8L);
                        int32_t l_2585[8][2] = {{6L,0xD822505EL},{0xD822505EL,6L},{0xD822505EL,0xD822505EL},{6L,0xD822505EL},{0xD822505EL,6L},{0xD822505EL,0xD822505EL},{6L,0xD822505EL},{0xD822505EL,6L}};
                        int i, j;
                        g_204 = (safe_div_func_uint16_t_u_u(0xF765L, 0xCCADL));

{
                        uint32_t l_4042 = 0xF2B5B59FL;
                        int32_t l_4043[8][7][2] = {{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}},{{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L}},{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}},{{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L}},{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}}};
                        int i, j, k;
                        l_4043[6][2][0] = l_4042;
                    }

                    l_2587 = (safe_div_func_uint32_t_u_u((safe_add_func_int32_t_s_s((safe_sub_func_int32_t_s_s((((safe_rshift_func_uint16_t_u_u((g_1599 = (((safe_div_func_uint8_t_u_u((l_2586 = (((safe_mod_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s(g_1684[0], 6)), (l_2585[4][0] = (safe_sub_func_int8_t_s_s(g_982, (safe_add_func_uint32_t_u_u((((g_2580[0][7] & (-9L)) | (-6L)) && (p_52 ^ (!(g_472 = 0xFCL)))), (safe_lshift_func_uint16_t_u_u(l_2584, 2))))))))) ^ (g_1370[0] = l_2294)) || p_52)), l_2275[0])) < g_2580[0][7]) , g_982)), 3)) ^ l_2275[0]) ^ g_76), l_2137)), g_172)), g_982));
                        ;
                    }
                    else
                    {
                        g_2580[3][0] = (safe_sub_func_int8_t_s_s(((p_52 <= g_1369) | ((l_2294 = g_204) < ((((safe_rshift_func_uint16_t_u_s((l_2393[1][0] == ((safe_sub_func_int16_t_s_s((safe_mod_func_int8_t_s_s(g_2580[0][7], g_2043)), (safe_mod_func_uint16_t_u_u((l_2588 = 0x5676L), l_2421)))) != (g_34[0] ^ g_1138))), 7)) , p_52) , g_897) && g_154))), g_76));
                    }
                    l_2141[4] = p_52;

;



{
                        return g_1368;
                    }

                    if ((safe_sub_func_int32_t_s_s(((safe_lshift_func_uint16_t_u_s(((l_2587 = (l_2588 = ((safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_s(((safe_sub_func_int32_t_s_s((safe_lshift_func_int8_t_s_u(0x14L, g_172)), (((safe_rshift_func_uint8_t_u_s(p_52, 0)) & 0UL) || ((safe_add_func_int32_t_s_s(((((safe_mod_func_int32_t_s_s((safe_mod_func_int16_t_s_s(((((g_2422 = ((g_1599 = g_172) || ((((p_52 || ((safe_lshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s(0xC9FF823CL, (((((((((safe_lshift_func_int16_t_s_u(l_1734[4], 8)) < p_52) ^ 0L) != l_2423) != (-1L)) && 65530UL) ^ p_52) == 0xCCL) || g_204))), 4)) & 0x80AF9677L)) ^ l_2508) | p_52) < l_2072))) | 247UL) && l_2141[9]) & 8L), l_2508)), p_52)) , l_2420) , g_35) , l_2625), p_52)) , 0L)))) , l_1734[3]), l_2393[3][0])), g_1345)) > 0x76140B37L))) > g_204), l_2134)) <= p_52), p_52)))
                    {
                        uint32_t l_2630 = 0xF792695BL;
                        ;

{

{
                        int i, j;
                        l_2141[4] = g_1798[(l_2278 + 2)][l_2149];
                    }

                    l_2275[7] = 0xC9C3F7B3L;
                    }

                    l_2149 = ((l_2588 = (safe_sub_func_int8_t_s_s((l_2141[9] != (+((((((((g_759 = ((l_2630 != (((p_52 >= g_1368) <= p_52) <= (safe_div_func_int16_t_s_s((l_2588 > (((safe_mod_func_int32_t_s_s((safe_unary_minus_func_uint8_t_u(((g_1798[3][2] , (p_52 , ((p_52 ^ g_98[1][3]) && g_1684[0]))) > 0x0B0A379DL))), g_87)) & 1L) <= l_2588)), p_52)))) , g_2580[0][6])) < 0xA7E4FFD3L) , (-1L)) != g_982) ^ p_52) > 3UL) != p_52) , l_2161))), p_52))) , 0x9FE4D27DL);


for (g_1369 = 0; (g_1369 <= 0); g_1369 += 1)
                    {
                        int i;
                        return g_1684[g_1369];
                    };


                    ;


                    }
                    else
                    {
                        return l_2586;
                    }
                }
            }
            else
            {

{
        transparent_crc(g_5210[g_275], "g_5210[g_275]", j);
        ;

    }

                    return g_35;
            }
            ;
            for (g_982 = 0; (g_982 <= 1); g_982 += 1)
            {
                int32_t l_2685 = (-1L);
                const uint8_t l_2785 = 0x1AL;
                uint8_t l_2794 = 0x8AL;
                int i, j;
                l_2587 = (safe_div_func_uint16_t_u_u((((((safe_lshift_func_int16_t_s_s((l_2508 = (safe_sub_func_int8_t_s_s(((safe_sub_func_uint32_t_u_u(((((safe_lshift_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(((((safe_div_func_uint16_t_u_u((((safe_sub_func_uint32_t_u_u((((safe_rshift_func_int8_t_s_s((0xAB1BL != l_1865[g_982]), 4)) , (safe_lshift_func_int16_t_s_u(l_1865[g_982], 15))) <= ((safe_add_func_int16_t_s_s(g_98[l_1774][(g_982 + 2)], (l_2685 = 65533UL))) == (l_2141[9] = (safe_lshift_func_uint8_t_u_s((((-9L) <= (safe_rshift_func_uint16_t_u_s(((safe_div_func_int16_t_s_s(p_52, p_52)) , ((safe_rshift_func_uint8_t_u_s((l_2275[0] = 0x54L), 4)) & g_496[2])), l_2137))) && 1L), l_2149))))), 0xEAB5CBCCL)) || p_52) <= l_2137), p_52)) >= g_469) || 0x31438514L) , p_52), g_496[0])), 1)) & p_52) <= p_52) <= g_172), l_1865[0])) , g_496[2]), g_2580[1][1]))), 12)) , g_1599) && p_52) != g_1352) | 65535UL), l_2587));

                if (((safe_sub_func_int8_t_s_s((((safe_mod_func_uint16_t_u_u(((((l_1865[g_982] > ((l_1706 = (((l_2100 & (~((safe_sub_func_uint8_t_u_u((4294967287UL == (((safe_add_func_uint16_t_u_u(((l_2275[0] != (-5L)) ^ (g_2467 = ((((safe_add_func_uint16_t_u_u((safe_unary_minus_func_uint16_t_u(l_1724[4])), ((g_1599 = (((safe_rshift_func_uint16_t_u_u((l_1734[3] = 0xA143L), (safe_div_func_uint16_t_u_u(g_1370[2], ((safe_mod_func_int8_t_s_s(0x57L, 0x57L)) || (-10L)))))) , l_2275[1]) >= g_982)) != g_1370[2]))) > 9L) != l_2275[0]) | l_2149))), 0xD469L)) == g_759) ^ g_204)), 0xBBL)) && 7L))) <= 65535UL) >= 0x60L)) || 1UL)) || 0x16L) || p_52) & l_1865[g_982]), l_1774)) && l_2149) , 0xB8L), (-7L))) , g_573))
                {
                    for (g_506 = 7; (g_506 >= 1); g_506 -= 1)
                    {
                        int i, j;
                        l_2141[4] = g_1798[(l_1774 + 2)][g_506];
                    }
                }
                else
                {
                    int32_t l_2787 = 0x00407C3DL;
                    if ((safe_lshift_func_uint16_t_u_s(((l_2787 = (safe_lshift_func_uint16_t_u_u(((p_52 & l_2767) , (l_2508 = ((((l_1734[4] = (safe_add_func_uint8_t_u_u(p_52, (((safe_rshift_func_int16_t_s_u((l_2421 >= (safe_mod_func_int8_t_s_s(((!((0UL < (l_2700[2][2] <= (((safe_rshift_func_int8_t_s_s((((((p_52 ^ ((safe_mod_func_uint8_t_u_u((((safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s(0x13L, (safe_rshift_func_int8_t_s_s(p_52, 4)))), g_87)) > 65535UL) != p_52), p_52)) , l_2420)) | 2L) || l_2685) , l_2785) > l_2786), g_172)) , 0xDAF6E4CCL) > 0x98BD7112L))) ^ p_52)) <= p_52), p_52))), 15)) || 0x9EL) , g_2422)))) , 65535UL) > 65533UL) && p_52))), 8))) > l_2149), p_52)))
                    {
                        const int16_t l_2802[1][7][1] = {{{(-7L)},{(-7L)},{0x48B8L},{(-7L)},{(-7L)},{0x48B8L},{(-7L)}}};
                        int i, j, k;

{

if (l_2787)
                            {
p_52 += 1;


                    continue;}

                    l_1865[g_5512] = 0x630AF406L;
                    }


if (g_204)
                    break;

                    g_2580[1][5] = ((safe_rshift_func_int8_t_s_s((0xD2BDL >= p_52), 2)) ^ ((p_52 >= ((safe_add_func_uint16_t_u_u((((l_75 = (l_2794 & ((safe_rshift_func_int16_t_s_u(2L, g_469)) == (+65526UL)))) <= (g_34[0] > (safe_sub_func_int32_t_s_s((((safe_sub_func_int8_t_s_s(l_2802[0][0][0], p_52)) || p_52) == g_1684[0]), (-1L))))) | g_352), l_2354)) , p_52)) > 0xD4L));
                        g_204 = ((0UL != (((safe_div_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_u((((safe_div_func_int32_t_s_s((safe_rshift_func_int8_t_s_u((((safe_add_func_uint16_t_u_u((g_982 && (((g_1599 = ((safe_rshift_func_uint8_t_u_s(0xC8L, (l_2787 > g_897))) & (g_98[0][3] = (safe_div_func_uint32_t_u_u(((safe_div_func_uint16_t_u_u(((((g_2467 = 0xA7L) ^ (g_154 , g_1368)) < ((l_2275[0] = p_52) | l_2149)) | l_2787), g_1798[5][2])) != p_52), g_1138))))) & 0xCFAEL) & l_2787)), l_2802[0][4][0])) > p_52) != l_2785), l_2685)), g_496[2])) <= (-10L)) > g_35), 3)) ^ l_2712), p_52)) , l_2072) == 0x0C61L)) , 2L);
                        ;
                        ;
                    }
                    else
                    {

if (g_68)
                            continue;

                    l_2787 = (-1L);
                        return l_2787;
                    }
                }
            }
        }

l_2072 -= 1;


                    if ((safe_unary_minus_func_uint8_t_u((g_472 = (1L != 0x910BL)))))
        {
lbl_3126:
            g_204 = (p_52 < ((safe_rshift_func_int16_t_s_u((-7L), 12)) ^ g_172));
            return p_52;
        }
        else
        {
            int8_t l_2827 = 1L;
            int32_t l_2828[3];
            uint32_t l_2958 = 0xB9F46481L;
            int16_t l_2965 = (-4L);
            int8_t l_3078 = 0x55L;
            int i;
            for (i = 0; i < 3; i++)
                ;;
            if (((g_154 = ((g_76 = (g_759 = p_52)) > ((safe_rshift_func_int8_t_s_s((+(l_2828[0] = l_2827)), l_2829)) && p_52))) & (g_472 = (safe_rshift_func_uint16_t_u_s(((((p_52 , (safe_div_func_int16_t_s_s(((safe_mod_func_int32_t_s_s(0xDFEE1244L, (((safe_lshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(((p_52 , g_1599) || (l_2149 = g_506)), 2)), 9)) | l_2275[1]) , g_1345))) != g_982), (-1L)))) && p_52) < l_2827) < g_982), g_496[2])))))
            {
                uint8_t l_2840 = 1UL;
                int32_t l_2892[8][9][3] = {{{0x27B90348L,3L,3L},{(-5L),6L,0xD68CB28BL},{0L,0L,9L},{(-1L),0x07865337L,0x04DC1EA0L},{0x635C4A12L,0xB30514ADL,0x909BAC14L},{0xA7B685F7L,0x07865337L,(-9L)},{0x49EBD11CL,0L,0L},{0x1D722DA1L,6L,(-3L)},{0x3A21BC98L,3L,0x49EBD11CL}},{{6L,0xCB5A84E3L,1L},{0x97D491D9L,0xC41D3717L,(-6L)},{(-1L),(-1L),0xCB5A84E3L},{0x5354B708L,1L,0xC0A7F112L},{1L,2L,(-3L)},{0x69C13A41L,0x27B90348L,(-9L)},{(-9L),(-3L),2L},{0xF252C132L,0x635C4A12L,0xF252C132L},{(-7L),(-6L),0x5AFF5F82L}},{{0xE9112707L,0L,(-9L)},{(-1L),2L,2L},{(-1L),9L,0x635C4A12L},{(-1L),(-9L),0xFCD9A823L},{0xE9112707L,0L,(-1L)},{(-7L),0x992771E9L,(-1L)},{0xF252C132L,0L,0x7703ED07L},{(-9L),(-10L),0xA7B685F7L},{0x69C13A41L,0xBC4ACB74L,0xB30514ADL}},{{1L,0x2CB1F362L,(-1L)},{0x5354B708L,1L,(-3L)},{(-1L),(-5L),(-1L)},{0x97D491D9L,0x69C13A41L,0xA3B150ACL},{6L,(-4L),(-6L)},{0x3A21BC98L,0x3A21BC98L,(-8L)},{0x1D722DA1L,(-1L),(-1L)},{0x49EBD11CL,0x23FB1394L,0xBC4ACB74L},{0xA7B685F7L,0xFCD9A823L,9L}},{{0x635C4A12L,0x49EBD11CL,0xBC4ACB74L},{(-1L),0x5AFF5F82L,(-1L)},{0L,0xA70F41A9L,(-8L)},{(-5L),0x04DC1EA0L,(-6L)},{0x27B90348L,(-6L),0xA3B150ACL},{(-4L),0L,(-1L)},{0x3B4B2C3EL,0x909BAC14L,(-3L)},{0xD68CB28BL,(-1L),(-1L)},{(-1L),1L,0xB30514ADL}},{{9L,(-1L),0xA7B685F7L},{0xB30514ADL,0xC0A7F112L,0x7703ED07L},{0L,(-1L),(-1L)},{0xBC4ACB74L,0xF54EE735L,(-1L)},{(-4L),0xDCCB8EDCL,0xFCD9A823L},{0xC41D3717L,0x7E13CFB9L,0x635C4A12L},{0x04DC1EA0L,(-4L),2L},{(-1L),0x7E13CFB9L,(-9L)},{2L,0xDCCB8EDCL,0x5AFF5F82L}},{{0x439149D0L,0xF54EE735L,0xF252C132L},{0x992771E9L,(-1L),2L},{0xF54EE735L,0xC0A7F112L,(-9L)},{0xB6C4321AL,(-1L),(-3L)},{3L,1L,0xC0A7F112L},{3L,(-1L),0xCB5A84E3L},{(-9L),0x909BAC14L,(-6L)},{(-10L),(-1L),(-1L)},{0x69C13A41L,0xA3B150ACL,0x7E13CFB9L}},{{6L,(-5L),6L},{1L,7L,(-1L)},{1L,0xA7B685F7L,1L},{(-1L),0x7E13CFB9L,0xF252C132L},{0xC528E876L,0x992771E9L,(-5L)},{(-1L),0x69C13A41L,0x3A21BC98L},{1L,0L,0x750D8B23L},{1L,0x3B4B2C3EL,(-6L)},{6L,0xB6C4321AL,0xDCCB8EDCL}}};
                int32_t l_2893[7];
                int i, j, k;

                ;

{
                        int i;
                        g_2440 = (((!((0x00L <= (safe_sub_func_uint32_t_u_u((g_5210[0] = g_1684[k]), (safe_mod_func_int16_t_s_s((safe_add_func_uint8_t_u_u((g_1684[0] | (safe_lshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_s(l_75, 4)), 4)), 4L)), 5))), (((safe_rshift_func_uint16_t_u_u((safe_div_func_uint8_t_u_u((0x6FL >= l_75), (g_240 = ((safe_mod_func_uint32_t_u_u(((((safe_sub_func_int16_t_s_s((g_1684[k] ^ g_2580[0][7]), l_1826)) > l_75) ^ g_9) ^ 0xF73BL), l_1867)) , g_1599)))), 12)) , g_3935[3][2]) > l_75))), g_1599))))) , k)) == l_75) || g_573);

for (i = 0; i < 1; i++)
                        g_1684[i] = 0x5E55L;

                    return l_75;
                    }

                    for (l_2786 = 0; (l_2786 <= 7); l_2786 += 1)
                {
                    uint32_t l_2854 = 0UL;
                    int32_t l_2869[4] = {1L,1L,1L,1L};
                    int i;
                    for (l_2100 = 0; (l_2100 <= 7); l_2100 += 1)
                    {
                        uint8_t l_2850 = 0x3FL;
                        int i;
                        ;
                        ;

{
                        int16_t l_905 = 0L;
                        l_905 = (i = g_76);
                    }

                    if (g_87)
                            ;;
                    }
                    if (g_1684[0])
                        {
;

                    ;}
                    g_1370[1] = 0xAF1BC787L;

                }

g_3600 += 1;


                    l_2893[3] = (l_2828[0] = (l_1734[0] = ((safe_rshift_func_uint8_t_u_u((l_2149 = ((((safe_lshift_func_int8_t_s_u(((safe_rshift_func_uint8_t_u_u(9UL, ((((((l_2840 , ((((safe_rshift_func_uint8_t_u_s(((((safe_rshift_func_uint16_t_u_s((safe_div_func_int16_t_s_s(((0x88L & ((safe_div_func_uint16_t_u_u((l_2828[2] & (g_1138 , 2UL)), (safe_rshift_func_uint16_t_u_u(65535UL, 7)))) || ((safe_add_func_uint32_t_u_u(((0x0C3C3219L <= ((safe_mod_func_int32_t_s_s((((g_759 = (4294967295UL == 0x4518D099L)) ^ g_1138) | g_1352), l_1734[3])) | g_1352)) >= 0UL), g_573)) > l_2828[0]))) | g_1368), g_2043)), l_2827)) > l_2840) <= p_52) ^ 0xDE598703L), g_1369)) , 0x5BDAA71DL) , 0x55L) || p_52)) && 5UL) , 0x01L) != p_52) , p_52) || 1UL))) == 1UL), l_2100)) ^ l_2892[4][7][0]) && 0xDEL) > l_2840)), 0)) != p_52)));
            }
            else
            {
                int32_t l_2916[9][3] = {{1L,7L,0L},{(-1L),0L,(-7L)},{8L,0xD1F05BC4L,0x511543C1L},{0L,0L,0xD1F05BC4L},{(-1L),7L,0x3899019DL},{(-1L),(-1L),8L},{0L,(-7L),7L},{8L,(-1L),8L},{(-1L),0x70A87605L,0x3899019DL}};
                uint32_t l_3018 = 0xFFA35317L;
                int16_t l_3023 = (-1L);
                const int16_t l_3077 = (-1L);
                int32_t l_3083[3];
                uint32_t l_3098 = 0UL;
                int32_t l_3147[3][8];
                int i, j;

{

{
                        int32_t l_6761 = 0x97130E1AL;
                        uint32_t l_6767 = 0UL;
                        l_2786 = ((l_3098 = (~(safe_mod_func_int16_t_s_s((((((+((safe_div_func_int32_t_s_s(((((safe_lshift_func_int16_t_s_u(((((g_240 = (-1L)) & (l_6761 = (g_204 , (g_2422 & l_2421)))) < g_352) | 0x3AL), ((l_2829 = l_3083[0]) , (2UL >= (((safe_div_func_int16_t_s_s((((g_98[2][2] = (g_3317 = ((((g_2853[0][6][6] = (safe_div_func_uint32_t_u_u((l_2829 = g_2422), g_2422))) , g_275) ^ l_6767) ^ g_2422))) ^ 1UL) | k), 4L)) && 0x74CC71B1L) , 0x5542L))))) >= l_3083[2]) == 0x03L) & g_2422), l_75)) ^ 4294967291UL)) , 1UL) <= g_240) < g_1798[5][2]) > 0xFD327552L), g_2422)))) <= g_1599);
                    }

                    g_5210[0] = 1L;
                        g_573 = g_34[0];
                    }



g_87 += 1;


                    for (l_75 = 21; (l_75 != (-13)); l_75--)
                    {
                        int16_t l_5399[7] = {(-1L),0xDCE8L,(-1L),(-1L),0xDCE8L,(-1L),(-1L)};
                        int i;
                        l_2828[1] = (-5L);
                        ;
                    };


                    for (i = 0; i < 3; i++)
                    l_3083[i] = 0L;

{
                    return g_5844;
                }

                    for (i = 0; i < 3; i++)
                {
                    ;
                }

{
                transparent_crc(g_2853[l_2508][j][g_204], "g_2853[l_2508][j][g_204]", g_275);
                if (g_275) printf("index = [%d][%d][%d]\n", l_2508, j, g_204);

            }

                    g_2853[0][6][6] = (safe_add_func_uint32_t_u_u((safe_add_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((l_1706 = (-1L)) != 0x9B16L), ((((((((safe_add_func_int32_t_s_s(((safe_mod_func_int32_t_s_s(((l_2149 = (l_2275[4] = (safe_sub_func_uint32_t_u_u((~((l_2828[0] = g_1370[2]) || (safe_add_func_uint8_t_u_u((g_35 , (safe_unary_minus_func_uint8_t_u((~(+(safe_lshift_func_uint8_t_u_s(0UL, 7))))))), (safe_rshift_func_int16_t_s_s(0xF576L, 15)))))), (((0L >= 3L) | (0x66DBE6F2L & 0xEDCDF7ACL)) > g_2853[0][6][6]))))) & g_1370[0]), g_240)) ^ 0x5CL), p_52)) || p_52) | 0xBA32L) & p_52) ^ l_2916[6][0]) >= 0L) , 0xA5A73F4EL) | p_52))), l_2916[6][0])), (-2L)));
                if ((safe_unary_minus_func_int32_t_s(((0L != (safe_div_func_uint32_t_u_u((p_52 | (((((l_2828[1] = g_496[2]) & l_2827) , l_2275[0]) || ((((safe_add_func_int8_t_s_s(((l_2149 = (g_469 <= 255UL)) == (l_2275[0] = ((l_2916[6][0] > 0x4E0076C0L) < g_759))), (-9L))) <= l_2828[0]) < l_2855) ^ p_52)) || p_52)), p_52))) | 0x5DL))))
                {
                    uint16_t l_2949[6][8][4] = {{{0x7CA4L,0xF6FCL,0x9123L,0xED67L},{8UL,65535UL,1UL,65527UL},{1UL,0xAE9CL,0xDBD7L,0x9055L},{0UL,65535UL,65527UL,0x336DL},{0UL,0UL,0UL,1UL},{65535UL,0x7067L,0x9123L,0xF56EL},{0x5DA9L,0xE289L,0UL,0xF6FCL},{0xF6FCL,0xA019L,0x8B92L,0UL}},{{0x9E5CL,1UL,0x3C88L,5UL},{1UL,0x4A34L,0xED67L,0xE289L},{0xE290L,0x7067L,65535UL,0UL},{65527UL,0x88A5L,3UL,0x2CAEL},{1UL,0xA41AL,65527UL,0x9055L},{0x186CL,0x5DA9L,1UL,65529UL},{0xED67L,2UL,0xE01DL,0x8133L},{0xE290L,0xF6FCL,0x8133L,0xAFF1L}},{{1UL,65527UL,0UL,1UL},{65535UL,65535UL,0x8B92L,0x4A00L},{0xFFBAL,0x9D6EL,65531UL,0xDBD7L},{0x7CA4L,0x8C3BL,0x7CA4L,0x8133L},{65535UL,65535UL,1UL,0x8033L},{0UL,0x9123L,0xDBD7L,65535UL},{0xE289L,0xA41AL,0xDBD7L,0x336DL},{0UL,0xB3AFL,1UL,1UL}},{{65535UL,0xE8DEL,0x7CA4L,0xE289L},{0x7CA4L,0xE289L,65531UL,0x6AEBL},{0xFFBAL,65531UL,0x8B92L,65531UL},{65535UL,0xA019L,0UL,5UL},{1UL,0UL,0x8133L,8UL},{0xE290L,0xE8DEL,0xE01DL,1UL},{0xED67L,0x88A5L,1UL,0UL},{0x186CL,1UL,65527UL,65535UL}},{{0xED67L,0xD85BL,65535UL,2UL},{0x9123L,0x7067L,65535UL,0xAE9CL},{65529UL,65535UL,0xAB07L,0UL},{8UL,0xDE63L,0x6AEBL,0xDBD7L},{0x96B7L,1UL,0UL,0xAFF1L},{0x93A9L,65526UL,0xA019L,1UL},{0xA8AAL,1UL,0xE290L,0xAE9CL},{65535UL,8UL,0xE39EL,0xDE63L}},{{0xDBD7L,0xE290L,0UL,0x8B92L},{65535UL,0UL,1UL,1UL},{0xAFF1L,0x1AD0L,1UL,1UL},{65535UL,65535UL,0xE290L,2UL},{0UL,65535UL,65527UL,0x93A9L},{3UL,0xF56EL,0x9304L,65527UL},{0x96B7L,0xF56EL,0x8C3BL,0x93A9L},{0xF56EL,65535UL,0xAE9CL,2UL}}};
                    int32_t l_2966 = 0x17DD1451L;
                    int32_t l_2967[9][8] = {{(-6L),(-9L),0x4A1240D2L,0L,(-9L),0L,0x4A1240D2L,(-9L)},{0xCD7042ABL,0x4A1240D2L,(-6L),0xCD7042ABL,0L,0L,0xCD7042ABL,(-6L)},{(-9L),(-9L),(-8L),1L,0xCD7042ABL,(-8L),0xCD7042ABL,1L},{(-6L),1L,(-6L),0L,1L,0x4A1240D2L,0x4A1240D2L,1L},{1L,0x4A1240D2L,0x4A1240D2L,1L,0L,(-6L),1L,(-6L)},{1L,0xCD7042ABL,(-8L),0xCD7042ABL,1L,(-8L),(-9L),(-9L)},{(-6L),0xCD7042ABL,0L,0L,0xCD7042ABL,(-6L),0x4A1240D2L,0xCD7042ABL},{(-9L),0x4A1240D2L,0L,(-9L),0L,0x4A1240D2L,(-9L),(-6L)},{0xCD7042ABL,1L,(-8L),(-9L),(-9L),(-8L),1L,0xCD7042ABL}};
                    int i, j, k;
                    l_2828[0] = (((safe_rshift_func_uint8_t_u_s(((safe_sub_func_uint16_t_u_u((l_1706 = (((safe_add_func_uint32_t_u_u(0UL, ((safe_lshift_func_int8_t_s_s(((safe_lshift_func_int16_t_s_s(0x2BEDL, (safe_div_func_int16_t_s_s(p_52, (safe_add_func_uint8_t_u_u(251UL, ((g_506 = 0x1FEC4E9FL) , (((+g_240) < (+((0L != p_52) == (((l_2916[6][0] = (p_52 <= 0x911DL)) ^ g_759) >= l_2938)))) | g_1798[5][2])))))))) , l_2916[3][2]), 2)) & p_52))) > p_52) & p_52)), p_52)) || g_240), 6)) && p_52) > g_2043);

for (l_1706 = 0; l_1706 < 8; l_1706++)
                        l_3147[g_275][l_1706] = 0x254F9A70L;

                    if ((safe_rshift_func_int8_t_s_u((((l_2829 = (g_982 , (safe_lshift_func_int8_t_s_s((-10L), 1)))) >= (((safe_add_func_int32_t_s_s(0xA5992450L, p_52)) >= (+((safe_rshift_func_int16_t_s_u(((g_496[2] && 4294967295UL) > g_335), 11)) & l_2828[1]))) <= (p_52 == 0L))) , 0x0FL), g_2043)))
                    {
                        int32_t l_2964 = 0xE67AA87BL;
                        int32_t l_2972 = (-2L);
                        ;
                        ;
lbl_2983:
                        g_2853[2][1][1] = ((safe_lshift_func_uint16_t_u_u((l_2972 = (l_2966 = ((safe_add_func_int8_t_s_s(g_759, (p_52 , p_52))) >= 0x76L))), ((l_2149 = 0xA08AA8BCL) , ((l_2916[2][2] = p_52) && ((safe_rshift_func_uint16_t_u_u(g_1369, 8)) >= (safe_div_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((0x6AL < (safe_add_func_uint16_t_u_u((~((0xAFL != g_982) <= l_2964)), g_275))), g_1798[5][1])), 0xCBE8L))))))) == l_2982);
                        l_2972 = 4L;
                        l_2916[6][0] = ((safe_add_func_uint8_t_u_u(p_52, (safe_sub_func_uint32_t_u_u(l_2967[5][3], ((((l_2275[0] = (((safe_add_func_int8_t_s_s((g_154 = (safe_sub_func_int16_t_s_s(((safe_div_func_uint16_t_u_u(((safe_add_func_uint16_t_u_u((((!p_52) > (((safe_div_func_uint32_t_u_u(g_2580[0][7], ((((l_1734[3] = (((g_1370[2] = (safe_mod_func_uint16_t_u_u((((safe_sub_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_s((((safe_div_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(g_1369, (safe_lshift_func_uint8_t_u_s((g_472 = (safe_lshift_func_int8_t_s_s((safe_mod_func_int32_t_s_s(((l_2966 = 0xFE920EE2L) < (safe_mod_func_uint8_t_u_u((!(l_3018 ^ (safe_sub_func_int16_t_s_s((safe_sub_func_uint8_t_u_u((g_87 = l_2072), 250UL)), 0x400EL)))), l_2274[4]))), l_2964)), 5))), 7)))) | p_52), 0x2E59L)) | g_9) < l_2855), l_2964)) >= l_2100), p_52)) < l_3023) < l_2149), l_2275[7]))) ^ p_52) || p_52)) != g_76) | 0x8A6DCD90L) ^ (-10L)))) >= g_172) | p_52)) , 0xF122L), g_1368)) || g_98[4][3]), g_469)) ^ 0x428EL), g_759))), 0x76L)) != 0x4DL) < l_1724[0])) > g_982) == 0x88D0L) != p_52))))) ^ l_3023);
                    }
                    else
                    {
                        return g_1370[2];
                    }
                    if ((safe_div_func_int16_t_s_s(1L, (safe_lshift_func_int8_t_s_u(l_2967[5][3], (l_2966 = (l_3032[4][2][1] = (safe_lshift_func_uint16_t_u_u((safe_mod_func_int8_t_s_s((-8L), g_469)), g_1798[5][6])))))))))
                    {

{
                        uint32_t l_1536 = 7UL;
                        int32_t l_1540 = 0x3A68B249L;
                        l_1540 = ((!g_1368) && (((safe_mod_func_int16_t_s_s(((((l_3083[2] = ((((safe_sub_func_uint32_t_u_u((g_5210[0] = 4294967286UL), ((0UL & (((safe_mod_func_uint32_t_u_u(((safe_sub_func_int8_t_s_s(((l_2966 = (safe_lshift_func_uint16_t_u_s((l_1536 > g_5844), (((((safe_lshift_func_uint16_t_u_u(65535UL, 3)) , ((-2L) & (g_3486 , (g_3486 , l_2966)))) & l_1706) < l_1536) <= l_1774)))) , g_3486), g_6771)) , l_2966), 0x5DB84211L)) == g_1369) | 0x39L)) > 0x3F73F712L))) | 0L) && (-1L)) , g_1369)) && l_3023) > g_1369) <= l_2002), g_34[0])) == l_1536) ^ 5UL));
                        l_2966 = g_1369;
                    }

                    return g_98[2][0];
                    }
                    else
                    {
                        l_1706 = 0x2DBDC553L;
                    }

;


                    l_2967[6][0] = g_172;
                }
                else
                {
                    int32_t l_3048 = 0x7D1651CAL;
                    const int16_t l_3076 = 0x5B28L;
                    int32_t l_3079 = 6L;
lbl_3080:
                    for (l_2508 = 0; (l_2508 <= 4); l_2508 += 1)
                    {
                        int32_t l_3033 = 0xA57E4991L;
                        l_3033 = 0x28722BCFL;
                        l_1734[3] = (safe_lshift_func_int8_t_s_u(l_2149, (((-7L) >= l_3036[0]) , (~4UL))));
                        if (p_52)
                            break;
                    }

{
                        int32_t l_1918 = 0x53669838L;
                        int i;
                        l_1918 = (safe_sub_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((l_1865[g_68] , (g_1684[g_68] || ((g_759 , g_759) && (+(g_3600 = (!(+(safe_add_func_int32_t_s_s(g_759, 0x6F544798L))))))))), 0x80479FE7L)), 0x483FL));
                    }


;



                    for (g_76 = 1; (g_76 <= 4); g_76 += 1)
                    {

for (g_5512 = 0; g_5512 < 2; g_5512 += 1)
                    {
                        ;
                    };



if (g_5225)
                            continue;

                    l_75 = (l_3083[2] = (l_3023 | (safe_sub_func_int8_t_s_s(g_2580[0][7], p_52))));
                        g_2853[0][0][3] = ((safe_mod_func_uint8_t_u_u(p_52, l_3067)) ^ (0x9780L ^ (safe_rshift_func_int8_t_s_s(0xA1L, 2))));
                    }
                }

                g_2853[2][8][5] = ((safe_add_func_uint16_t_u_u((((safe_sub_func_int16_t_s_s(((g_184 = (safe_mod_func_uint16_t_u_u(l_2827, g_204))) ^ ((g_1369 , 7L) , p_52)), (l_2149 = ((((l_2828[0] = (0x80L && (l_2275[0] = (safe_div_func_uint16_t_u_u((safe_rshift_func_int16_t_s_s((g_1370[2] > (g_759 = (g_335 || (l_2958 > 5UL)))), 7)), l_3018))))) & g_352) , l_3083[2]) == 0xF9017BF7L)))) > l_3147[2][0]) || 0L), 1L)) || (-7L));
            }
        }
    }
                                   int32_t BgBgBgl_2508 = (~(((((~((~(((~(l_2938)) | g_469))))) * ((~(g_2043)) % l_2508)) | (~(((~((~((~(g_352)))))) && (g_1288 % (l_1721 % g_759)))))) && ((~((~((~(g_35)))))) << g_240))));
uint32_t BgBgBhg_469 = (~(((~((BgBgBgl_2508 * (~(((g_352 * (~((~((g_469 ^ l_2508)))))) % l_1721)))))) ^ (~(((~(l_2938)) & (~(((~((g_240 + (~((~(g_1288))))))) ^ (g_35 | (g_2043 + g_759)))))))))));
int32_t BgBgBig_240 = (~(((~(((~(((~((g_1288 % g_240))) && (~(g_352))))) & (~((((~(g_759)) + BgBgBgl_2508) | (l_2938 ^ (l_2508 ^ g_35)))))))) + (~(((BgBgBhg_469 + (g_2043 * g_469)) & (~((~((~((~((~(l_1721))))))))))))))));
uint32_t BgBgBjg_759 = (~(((~(((g_1288 & ((~(g_35)) ^ (~(BgBgBgl_2508)))) && (~(g_352))))) & ((~((~((g_469 * l_2508))))) & ((~((~(l_2938)))) % ((g_759 * (g_240 | l_1721)) % ((~((g_2043 + BgBgBig_240))) | BgBgBhg_469)))))));
int32_t BgBgBkg_2043 = (~((((~((~(((~(((g_1288 && l_2938) | (g_240 ^ (BgBgBgl_2508 && (~(BgBgBjg_759))))))) + ((~(l_2508)) & (~(l_1721)))))))) && ((~((g_469 ^ (g_2043 && BgBgBhg_469)))) ^ BgBgBig_240)) & ((~(((~(g_35)) % g_759))) + (~(g_352))))));
uint16_t BgBgBll_2938 = (~(((~((BgBgBig_240 & (BgBgBkg_2043 * (~(l_2938)))))) & ((~((l_2508 | (l_1721 & ((~(g_240)) * BgBgBjg_759))))) % ((~(((~((((~(g_469)) | ((g_759 && BgBgBhg_469) | BgBgBgl_2508)) % g_2043))) % g_35))) % ((~(g_1288)) * g_352))))));
                                   if ((g_1369 > l_2712))
                    { if (l_2508)
                    if(((BgBgBll_2938 > g_2043) && BgBgBig_240)){
BgBgBgl_2508 = l_2508;
BgBgBhg_469 = g_469;
BgBgBig_240 = g_240;
BgBgBjg_759 = g_759;
BgBgBkg_2043 = g_2043;
BgBgBll_2938 = l_2938;
                                   if ((l_2938>=7256))
                    l_2508 = (~(((l_2938 ^ ((~(g_2043)) & BgBgBll_2938)) & ((~((~((((~(g_240)) && BgBgBgl_2508) | (g_759 * (~((~(((~(g_469)) % (~(g_1288))))))))))))) ^ (((l_2508 >> (BgBgBjg_759 % BgBgBhg_469)) | g_352) >> (((g_35 + l_1721) & BgBgBkg_2043) && (~(BgBgBig_240))))))));
g_469 = (~(((((~(g_759)) % l_2938) | ((((~(((~((l_2508 * BgBgBll_2938))) >> (g_240 % BgBgBig_240)))) | BgBgBgl_2508) * (~(g_469))) + (g_2043 * g_352))) + (~((((~(g_1288)) && (~((~(((l_1721 | BgBgBkg_2043) * g_35)))))) % (~((BgBgBhg_469 + BgBgBjg_759)))))))));
g_240 = (~((g_352 << (((((~(l_2508)) & g_469) ^ (~((g_35 & BgBgBkg_2043)))) + ((((~(l_2938)) ^ g_240) ^ (~(l_1721))) & ((BgBgBhg_469 ^ BgBgBll_2938) | (~(BgBgBgl_2508))))) && (g_2043 >> ((~((~((g_759 ^ g_1288))))) * (BgBgBig_240 >> BgBgBjg_759)))))));
g_759 = (~(((~((((~(g_35)) ^ (~((~(BgBgBgl_2508))))) * (g_759 & g_240)))) ^ ((g_2043 >> BgBgBig_240) && (((BgBgBhg_469 + (g_352 + BgBgBjg_759)) + ((~((l_2508 % l_2938))) + ((~(BgBgBll_2938)) | (l_1721 % BgBgBkg_2043)))) ^ ((~((~(g_1288)))) && (~(g_469))))))));
g_2043 = (~((((~((~(((~(BgBgBll_2938)) && (g_2043 && (~(BgBgBhg_469)))))))) >> ((~((l_2508 % BgBgBjg_759))) && (((~(BgBgBig_240)) && (g_352 + ((BgBgBkg_2043 % (~((l_1721 % g_1288)))) ^ g_35))) * (~((~((l_2938 & g_240)))))))) && (~((((~((~((~(g_759)))))) & (~(g_469))) & BgBgBgl_2508))))));
l_2938 = (~((((~(g_2043)) | (((l_2938 && l_2508) % (~((l_1721 ^ (~((~(BgBgBig_240)))))))) ^ (~(((((BgBgBll_2938 + (~(g_352))) & g_759) && g_240) & (BgBgBkg_2043 + BgBgBgl_2508)))))) * ((~(((~(g_469)) ^ BgBgBhg_469))) % (~((BgBgBjg_759 | (g_1288 & g_35))))))));
if((!l_1721)){
printf("l_2508=%lld\n", (long long)l_2508);
l_2508 = (~((((~((~((~(((~((~((BgBgBgl_2508 << (~(BgBgBkg_2043))))))) & (g_240 && BgBgBhg_469)))))))) ^ (((~(((~((~(g_759)))) % (BgBgBjg_759 ^ ((~(l_2938)) + g_35))))) * (~(((l_2508 | l_1721) % g_352)))) >> ((~(((g_2043 % g_1288) >> BgBgBig_240))) << BgBgBll_2938))) >> g_469)));
goto lbl_3080;
}
if(!((g_1288 < g_759))){
;

g_9 += 1;


                    goto lbl_2983;
}
if((g_2043>-2)){
printf("g_240=%lld\n", (long long)g_240);
;
}
if(((!g_1288) || (g_35<-1))){
printf("g_759=%llu\n", (unsigned long long)g_759);
;
}
if((g_759 < BgBgBll_2938)){
;

{
                        uint32_t l_1536 = 7UL;
                        int32_t l_1540 = 0x3A68B249L;
                        l_1540 = ((!g_1345) && (((safe_mod_func_int16_t_s_s(((((g_1370[2] = ((((safe_sub_func_uint32_t_u_u((g_5210[0] = 4294967286UL), ((0UL & (((safe_mod_func_uint32_t_u_u(((safe_sub_func_int8_t_s_s(((g_506 = (safe_lshift_func_uint16_t_u_s((l_1536 > g_335), (((((safe_lshift_func_uint16_t_u_u(65535UL, 3)) , ((-2L) & (l_2829 , (l_2829 , g_506)))) & g_3486) < l_1536) <= l_3153)))) , l_2829), g_68)) , g_204), 0x5DB84211L)) == g_9) | 0x39L)) > 0x3F73F712L))) | 0L) && (-1L)) , g_9)) && g_1288) > g_9) <= l_1867), g_34[0])) == l_1536) ^ 5UL));
                        g_506 = g_9;
                    }

                    BgBgBkg_2043 = (~((((((~((~(g_352)))) | l_2508) * ((l_1721 * (~((g_2043 >> BgBgBjg_759)))) * (~((g_240 | BgBgBhg_469))))) | (~(l_2938))) * (((~(g_1288)) % (BgBgBll_2938 << BgBgBkg_2043)) >> (~(((g_759 << g_469) && (((~(BgBgBgl_2508)) | g_35) | BgBgBig_240))))))));
goto lbl_3126;
}
LABEL_gBgBm: if((BgBgBll_2938 > g_1288)){
printf("l_2938=%llu\n", (unsigned long long)l_2938);
BgBgBig_240 = (~(((~((((~((~(BgBgBll_2938)))) | ((~(((g_352 % (g_1288 % (g_759 | l_1721))) * BgBgBjg_759))) && g_35)) & (((~((~(l_2508)))) * ((BgBgBhg_469 << g_2043) && g_240)) ^ ((l_2938 ^ (BgBgBgl_2508 && g_469)) << (~(BgBgBig_240))))))) % (~((~((~((~(BgBgBkg_2043)))))))))));
goto lbl_3126;
}
}}
                                    if ((g_2043>-2) )
{

;

}
                    l_2508 = BgBgBgl_2508;
g_469 = BgBgBhg_469;
g_240 = BgBgBig_240;
                                   if ((l_69 && (l_1774>=-1)))
                    g_759 = BgBgBjg_759;
g_2043 = BgBgBkg_2043;
l_2938 = BgBgBll_2938;

                    g_2580[0][7] = (((!l_2424[5][4]) > (((safe_div_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_s(l_3153, ((l_1706 = ((safe_sub_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u((g_3109[2] , p_52), (safe_unary_minus_func_int8_t_s(((safe_lshift_func_int16_t_s_s((safe_add_func_uint16_t_u_u(0x7B64L, (((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(l_3167[2][0], 3)), (g_469 , ((safe_rshift_func_uint8_t_u_s(249UL, (safe_rshift_func_int16_t_s_u((l_1734[2] = (l_75 = (-2L))), l_2161)))) | g_204)))) < g_2852) == 0x2BL))), 3)) > l_1865[0]))))) >= g_3172), g_2853[1][3][0])) == l_2938)) || (-1L)))) , g_98[1][3]), (-3L))) && l_1706) && 1L)) | l_3173[0]);
    for (g_1369 = 18; (g_1369 < 25); ++g_1369)
    {
        uint32_t l_3194 = 0UL;
        int32_t l_3195 = 0xB03C3FA3L;
        int32_t l_3196 = 1L;
        l_75 = (l_3195 = (safe_lshift_func_int8_t_s_u(p_52, ((safe_lshift_func_uint16_t_u_s(((((((g_2422 = (safe_sub_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(p_52, (g_1798[1][4] != ((!(safe_lshift_func_int8_t_s_s(((((g_1684[0] > (safe_rshift_func_int16_t_s_u((((g_184 = ((l_1734[3] | (safe_div_func_int16_t_s_s(((l_3194 = (safe_sub_func_int16_t_s_s(0x2251L, (0x6095DBC2L | (p_52 && (g_3193 = 0x87L)))))) , l_3194), p_52))) && g_496[2])) <= p_52) > 1UL), l_3195))) || l_1724[2]) && l_3195) , 6L), p_52))) || 1L)))), 65528UL))) || l_3196) , l_2982) , 6L) , p_52) ^ l_2421), l_3195)) , 0UL))));
        l_3196 = (safe_add_func_uint16_t_u_u(p_52, ((l_3195 = (~(((((p_52 & l_3196) ^ 1L) , (g_204 = g_982)) , g_1368) , ((((1UL | g_87) | p_52) < p_52) || p_52)))) , 0x726BL)));
    }
                                        while ((l_2098>3751292223U) )
{

{

;



{
                        if (l_2002)
                            break;
                        l_75 = g_98[g_2467][(g_982 + 2)];
                    }

                    ;

if (g_35)
                            continue;

                    g_5446[5] = g_9;
                    }

}
                    return p_52;
}







static uint16_t func_54(int32_t p_55, uint16_t p_56, uint32_t p_57, const int16_t p_58, int16_t p_59)
{
    uint32_t l_1687 = 0x041CB36AL;
    int32_t l_1696 = 0x79302BB6L;
    uint32_t l_1704 = 0xC67D7B3DL;
    int32_t l_1705 = (-1L);
    for (g_897 = 20; (g_897 > (-16)); g_897 = safe_sub_func_uint8_t_u_u(g_897, 7))
    {
        return l_1687;
    }
    l_1705 = (((safe_add_func_int32_t_s_s((safe_rshift_func_int8_t_s_s((safe_sub_func_int32_t_s_s((l_1696 = (safe_mod_func_int32_t_s_s(l_1687, (g_76 = (p_59 , (g_1368 = 6UL)))))), (+(((((safe_mod_func_int32_t_s_s((safe_lshift_func_int8_t_s_s(((((safe_unary_minus_func_int16_t_s(l_1687)) >= p_59) > ((1UL != p_56) == 4294967295UL)) > (((safe_unary_minus_func_uint8_t_u(p_56)) | p_58) || l_1704)), 0)), l_1687)) < l_1687) != p_56) <= g_1138) > l_1704)))), l_1704)), g_68)) == 3L) || 0x83E6L);
    return g_98[1][1];
}







static int32_t func_60(uint8_t p_61)
{
    uint16_t l_94 = 65532UL;
    int32_t l_136 = 0xAD0BAEE1L;
    int32_t l_173[1];
    uint8_t l_206 = 4UL;
    int32_t l_287 = 0x2DAF40BCL;
    int16_t l_331[8];
    int32_t l_332 = 0x498514B6L;
    int8_t l_333[9][2][3] = {{{(-1L),2L,(-1L)},{0x33L,0xE0L,1L}},{{0x33L,7L,0x33L},{(-1L),0x8BL,(-1L)}},{{0x33L,0x16L,0xDEL},{0x33L,0x70L,1L}},{{(-1L),0x3DL,0L},{0x33L,(-8L),0x90L}},{{0x33L,0xE7L,(-1L)},{(-1L),2L,(-1L)}},{{0x33L,0xE0L,1L},{0x33L,7L,0x33L}},{{(-1L),0x8BL,(-1L)},{0x33L,0x16L,0xDEL}},{{0x33L,0x70L,1L},{(-1L),0x3DL,0L}},{{0x33L,(-8L),0x90L},{0x33L,0xE7L,(-1L)}}};
    int32_t l_334[6] = {0xF4225F34L,0x9EFBFE89L,0xF4225F34L,0xF4225F34L,0x9EFBFE89L,0xF4225F34L};
    int32_t l_336 = 0x77E4473CL;
    int8_t l_391 = 0x20L;
    const uint16_t l_397 = 0x9738L;
    uint32_t l_398 = 1UL;
    uint32_t l_483 = 4294967290UL;
    const int32_t l_617 = 0x7EB6E80EL;
    int32_t l_787[1];
    uint32_t l_964 = 0xBD91FE29L;
    int8_t l_999 = 0x11L;
    int8_t l_1000 = (-9L);
    uint16_t l_1111[8] = {0x7444L,0x7444L,0x7444L,0x7444L,0x7444L,0x7444L,0x7444L,0x7444L};
    uint32_t l_1158 = 0xE8CAA913L;
    int8_t l_1304 = 0L;
    int8_t l_1427 = (-1L);
    uint8_t l_1439 = 0xF1L;
    uint16_t l_1632 = 65535UL;
    int i, j, k;
    for (i = 0; i < 1; i++)
        { if ((g_76 > l_1439))
                    l_173[i] = 0L;}
    for (i = 0; i < 8; i++)
        l_331[i] = (-1L);
                                       if ((g_759 < l_1158))
                    { uint8_t BlClCNg_87 = (~(((~((g_87 & l_287))) && (((-((g_1352 + ((~(l_94)) ^ l_483)))) && (l_206 | g_184)) + (g_469 ^ (l_336 + l_1439))))));
uint32_t BlClCOl_483 = (~((((~((~(g_1352)))) ^ (l_1439 + (g_184 | ((g_87 ^ l_206) ^ ((l_94 ^ l_287) && (~(g_469))))))) * (-(((l_336 ^ l_483) * (-(BlClCNg_87))))))));
uint8_t BlClCPl_206 = (~(((~((-(((g_469 | ((-(g_87)) && l_1439)) * ((~(l_336)) + (~(((l_287 | g_1352) * (l_483 & g_184)))))))))) << (((BlClCNg_87 && l_94) && (~(BlClCOl_483))) ^ l_206))));
uint8_t BlClCQl_1439 = (~((((~(g_87)) | ((((g_184 & (l_1439 << l_206)) & (((~(l_336)) + (BlClCPl_206 << g_469)) + (BlClCOl_483 & (-(l_287))))) + g_1352) + (BlClCNg_87 & l_94))) ^ l_483)));
int32_t BlClCRl_287 = (~(((-(((~((-(BlClCPl_206)))) | ((-(((~(g_184)) << g_87))) ^ (~((BlClCOl_483 | (-(((BlClCNg_87 + (l_336 & g_1352)) & (~(l_94)))))))))))) && (~(((BlClCQl_1439 + (~(((l_483 | l_1439) & (l_287 ^ g_469))))) * (~(l_206))))))));
uint32_t BlClCSg_184 = (~(((~((-(((-((((BlClCNg_87 * (~((~(l_206))))) * (((l_1439 + (((l_483 + BlClCQl_1439) ^ g_1352) | g_184)) + l_336) ^ (~(g_87)))) | (~((-((-(BlClCPl_206))))))))) << (~((~(g_469))))))))) + (-(((l_94 & l_287) ^ (BlClCRl_287 * BlClCOl_483)))))));
if(((BlClCQl_1439>242) || BlClCNg_87)){
BlClCNg_87 = g_87;
BlClCOl_483 = l_483;
BlClCPl_206 = l_206;
BlClCQl_1439 = l_1439;
BlClCRl_287 = l_287;
BlClCSg_184 = g_184;
g_87 = (~(((g_184 * (-((l_483 + l_336)))) ^ (((((-(((l_287 ^ (-(g_469))) && (~((((-(BlClCOl_483)) * l_1439) && (((BlClCRl_287 && BlClCQl_1439) + (-(g_1352))) ^ g_87))))))) && BlClCPl_206) * (~((~((~(l_94))))))) & (~((BlClCNg_87 << l_206)))) + (~(BlClCSg_184))))));
                                    if ((!((g_87<=179)) || ((l_1304<=0) && (!l_206))) )
{

l_136 += 1;


}
                    l_483 = (~(((l_483 && ((-(l_206)) * (-(((l_94 & BlClCQl_1439) & (l_336 + (((((g_184 * BlClCOl_483) >> (g_87 && BlClCRl_287)) ^ g_1352) * (l_287 + g_469)) * (~(BlClCNg_87))))))))) * (~((~((~((~(((BlClCSg_184 >> BlClCPl_206) ^ l_1439))))))))))));
l_206 = (-((((~(((g_87 & l_1439) && (-(l_94))))) * (((~((-(g_184)))) & ((~(BlClCPl_206)) && ((BlClCNg_87 && l_336) && BlClCOl_483))) + (-((~(((~(BlClCSg_184)) & g_469))))))) && (-((~((l_483 ^ (BlClCRl_287 ^ ((~(BlClCQl_1439)) & (-((l_287 && (g_1352 && l_206))))))))))))));
l_1439 = (~(((~((((((l_287 & g_184) << BlClCPl_206) & l_336) * (~(((l_94 + l_483) + BlClCOl_483)))) & (~((~((BlClCSg_184 | g_87)))))))) * ((~((((~((~(l_206)))) & (l_1439 ^ BlClCRl_287)) | (-(g_469))))) | (((~(g_1352)) + BlClCQl_1439) | (~(BlClCNg_87)))))));
l_287 = (-(((~(((~((~((-((g_87 & (~((BlClCOl_483 << g_469)))))))))) << ((((~(g_184)) & (l_287 + BlClCPl_206)) & (BlClCRl_287 + (~(((-(g_1352)) && ((l_1439 ^ BlClCQl_1439) + l_206)))))) & (l_336 >> (~(BlClCSg_184))))))) | ((~(l_483)) ^ (l_94 ^ BlClCNg_87)))));
LABEL_lClCT: g_184 = (~(((~((~((((((l_483 && l_1439) + BlClCPl_206) ^ ((~((~(g_469)))) + (~(l_206)))) * ((~((~(((BlClCSg_184 ^ BlClCNg_87) + l_94))))) & ((-(BlClCRl_287)) ^ g_1352))) + (l_287 && g_184)))))) >> (BlClCQl_1439 && (~(((g_87 | BlClCOl_483) ^ l_336)))))));
if((l_287 > BlClCRl_287)){
printf("g_87=%llu\n", (unsigned long long)g_87);
goto LABEL_lClCT;
}
if((!((BlClCPl_206<=4)) || (g_1352<-10))){
printf("l_483=%llu\n", (unsigned long long)l_483);
goto lbl_1005;
}
if(!(!((!g_184)))){
printf("l_206=%llu\n", (unsigned long long)l_206);
BlClCNg_87 = (~(((-(BlClCPl_206)) * ((~(((~((((~(((~(BlClCOl_483)) | g_1352))) * ((-(l_336)) ^ l_206)) | l_483))) * (((~(l_94)) & (~((BlClCNg_87 & BlClCRl_287)))) | l_1439)))) & (~(((~(((-(BlClCSg_184)) >> BlClCQl_1439))) & (-(((g_184 && l_287) + (g_87 | (~(g_469)))))))))))));

for (l_94 = 16; (l_94 > 46); l_94 = safe_add_func_uint16_t_u_u(l_94, 5))
                    {
                        int16_t l_905 = 0L;
                        l_905 = (l_136 = g_352);
                    };


                    l_206 = (~((((~((~(((BlClCNg_87 << BlClCOl_483) * l_483))))) << g_469) & (((BlClCQl_1439 + (((l_287 && g_1352) & (g_87 | BlClCPl_206)) && (l_206 + (~(l_336))))) >> (~((-((l_1439 * g_184)))))) << (~((-(((BlClCRl_287 | BlClCSg_184) && l_94)))))))));
}
if(((g_87<=179) && (BlClCRl_287>766460092))){
printf("l_1439=%llu\n", (unsigned long long)l_1439);
goto lbl_1005;
}
if(((g_1352 && (l_287 < l_336)) && !(g_469))){
printf("l_287=%lld\n", (long long)l_287);
goto lbl_1005;
}
if((BlClCRl_287 < l_1439)){
printf("g_184=%llu\n", (unsigned long long)g_184);
goto lbl_682;
}
}
g_87 = BlClCNg_87;
l_483 = BlClCOl_483;
l_206 = BlClCPl_206;
l_1439 = BlClCQl_1439;
l_287 = BlClCRl_287;
g_184 = BlClCSg_184;

                    for (i = 0; i < 1; i++)
        { uint32_t BKCKCBg_469 = (~((((~((~((g_982 | g_1369))))) >> (g_335 && l_1304)) / (((l_336 ^ l_1000) | (~(g_275))) + ((l_136 ^ l_1632) | (~(g_469)))))));
int32_t BKCKCCl_336 = (~(((~(((~(((~(((BKCKCBg_469 ^ g_1369) + ((~(l_336)) + (~((~((~(l_1000)))))))))) | g_335))) / ((~((l_1632 ^ g_469))) + g_275)))) + (~((~((~((l_136 - ((~(g_982)) ^ l_1304)))))))))));
int8_t BKCKCDl_1304 = (~((((~((l_336 + (l_1000 - g_1369)))) | (g_982 | (~((l_1632 ^ ((~((~(g_469)))) ^ ((g_275 / BKCKCBg_469) && BKCKCCl_336))))))) | (~((~((~((l_136 && (g_335 - l_1304)))))))))));
int16_t BKCKCEg_335 = (~((((~(((g_982 + (~((((~(g_335)) ^ (~(l_1632))) && ((~(l_1304)) / l_336))))) >> (~(BKCKCBg_469))))) && ((~(g_275)) ^ (~((BKCKCCl_336 - (l_136 | (g_469 + l_1000))))))) + (~((BKCKCDl_1304 / (~(g_1369))))))));
uint16_t BKCKCFl_1632 = (~((((l_1632 / (~(BKCKCDl_1304))) | ((~((~((BKCKCCl_336 | g_275))))) + (~(g_335)))) | (~((~(((l_1304 & (~((BKCKCBg_469 | ((g_982 | l_1000) + l_136))))) >> ((l_336 & (g_469 & (~(g_1369)))) ^ (~(BKCKCEg_335)))))))))));
int32_t BKCKCGl_136 = (~(((((~(l_1632)) / ((l_136 ^ (BKCKCDl_1304 << ((~(BKCKCCl_336)) / l_336))) - (l_1000 | (g_335 | g_275)))) ^ ((~((BKCKCEg_335 | g_982))) << g_469)) | ((~((~(((BKCKCBg_469 + g_1369) & (~(l_1304))))))) & BKCKCFl_1632))));
if((BKCKCGl_136 > l_136)){
BKCKCBg_469 = g_469;
BKCKCCl_336 = l_336;
BKCKCDl_1304 = l_1304;
BKCKCEg_335 = g_335;
BKCKCFl_1632 = l_1632;
BKCKCGl_136 = l_136;
g_469 = (~(((BKCKCEg_335 / (~(g_335))) & (~(((((BKCKCCl_336 + BKCKCDl_1304) | (~((l_1632 ^ l_1000)))) | (~(l_1304))) ^ (~(((g_275 && l_336) && ((~((~((g_469 && (~(l_136))))))) | ((~(((BKCKCFl_1632 & BKCKCGl_136) + (g_982 ^ BKCKCBg_469)))) | (~(g_1369)))))))))))));
l_336 = (~(((((l_336 & (BKCKCGl_136 & g_469)) & (~(g_982))) / (~(((BKCKCEg_335 + g_275) ^ (~(((BKCKCBg_469 - BKCKCFl_1632) | BKCKCCl_336))))))) & ((((~(g_335)) ^ (~((((~(g_1369)) | l_1000) - l_1304)))) && (~((~((l_1632 && l_136)))))) ^ (~(BKCKCDl_1304))))));
l_1304 = (~(((((~(g_1369)) ^ (l_1632 + l_136)) + (~((~(BKCKCFl_1632))))) | (((g_335 >> (((((l_1304 - BKCKCCl_336) & BKCKCEg_335) / g_469) & (BKCKCGl_136 & l_1000)) && (~((g_275 / g_982))))) && BKCKCDl_1304) / (~((BKCKCBg_469 && l_336)))))));
g_335 = (~((((~((~((l_1000 && ((~(g_335)) | ((g_275 & BKCKCGl_136) & l_336))))))) + (~((((l_1304 - (~((l_1632 ^ BKCKCCl_336)))) - (((~(g_982)) - (~(BKCKCFl_1632))) && (~((BKCKCEg_335 << BKCKCDl_1304))))) & (~(g_1369)))))) + ((l_136 + g_469) & (~((~(BKCKCBg_469))))))));
l_1632 = (~(((~(((~(g_1369)) & ((~((~((~(((g_982 | BKCKCGl_136) && (l_1304 - g_469)))))))) - ((((~(BKCKCEg_335)) && (~((~((l_336 ^ g_335)))))) + (g_275 + BKCKCBg_469)) / (~((BKCKCFl_1632 & ((~((l_136 + l_1632))) + (~(BKCKCDl_1304))))))))))) + (~((BKCKCCl_336 ^ l_1000))))));
l_136 = (~(((~((((g_335 ^ (~(l_1000))) / (~(BKCKCCl_336))) ^ (l_336 ^ l_1304)))) ^ (((~(((((~(((BKCKCEg_335 - l_136) & (~(g_275))))) ^ (~(g_1369))) & (~(BKCKCBg_469))) + (~((~(((l_1632 && g_982) & BKCKCDl_1304)))))))) - BKCKCFl_1632) / (~((~((~((~(((~(g_469)) + BKCKCGl_136)))))))))))));
if((BKCKCDl_1304>0)){
printf("g_469=%llu\n", (unsigned long long)g_469);
l_136 = (~(((~((~((~((BKCKCFl_1632 / g_469))))))) << ((((BKCKCEg_335 & BKCKCBg_469) & l_1000) & ((~((((g_982 | l_136) | BKCKCDl_1304) << BKCKCCl_336))) << ((~((g_1369 - (g_335 ^ BKCKCGl_136)))) << ((~((~((~(g_275)))))) & l_336)))) && (l_1632 / l_1304)))));
g_469 = (~((((((~(((~(((l_1304 >> l_1632) - ((g_335 / BKCKCFl_1632) >> g_275)))) >> (~((~((~(g_1369))))))))) << BKCKCCl_336) - l_1000) | (~(((BKCKCDl_1304 - BKCKCEg_335) && BKCKCBg_469)))) >> ((~((~((BKCKCGl_136 & (l_136 / (g_982 >> l_336))))))) << (~((~((~(g_469))))))))));
}
if((!g_982)){
printf("l_336=%lld\n", (long long)l_336);
goto lbl_682;
}
if((!l_1000)){
printf("l_1304=%lld\n", (long long)l_1304);
continue;
}
if((!((g_1369 < BKCKCCl_336)) || ((!l_1000) && (g_1369>=255)))){
printf("g_335=%lld\n", (long long)g_335);
l_336 = (~(((~((~((BKCKCDl_1304 & l_1632))))) >> (((~((~(g_1369)))) + ((~((BKCKCFl_1632 / (~(l_336))))) + g_982)) | (~((((~((~((~((~(l_136)))))))) && (((BKCKCBg_469 & (g_275 / BKCKCGl_136)) >> g_469) & l_1000)) + (l_1304 / (BKCKCEg_335 ^ (BKCKCCl_336 - g_335))))))))));
BKCKCCl_336 = (~((((~((~((~(((~(g_275)) ^ (~(BKCKCEg_335))))))))) << (~(((~(((~(BKCKCCl_336)) & BKCKCDl_1304))) / (((~(BKCKCGl_136)) / (~(BKCKCBg_469))) & (~((l_1304 ^ l_136)))))))) + ((~((~(((~((g_335 ^ (~((g_982 | ((~(l_1000)) << l_336))))))) - ((l_1632 & g_1369) | (~(BKCKCFl_1632)))))))) / (~((~(g_469))))))));
goto lbl_682;
}
if((g_1369>255)){
printf("l_1632=%llu\n", (unsigned long long)l_1632);
l_1632 = (~((((BKCKCDl_1304 | (~(((~((~((~((~(((~((BKCKCBg_469 / l_136))) << g_335))))))))) + (~((~(BKCKCEg_335)))))))) | (~((l_1000 - g_469)))) ^ (~((~((~((((BKCKCFl_1632 & BKCKCGl_136) | (g_275 >> g_1369)) << (((l_1632 - (~(BKCKCCl_336))) + (l_1304 & g_982)) >> l_336)))))))))));
break;
}
if((!BKCKCGl_136)){
printf("l_136=%lld\n", (long long)l_136);
continue;
}
}
g_469 = BKCKCBg_469;
l_336 = BKCKCCl_336;
l_1304 = BKCKCDl_1304;
g_335 = BKCKCEg_335;
l_1632 = BKCKCFl_1632;
l_136 = BKCKCGl_136;

                    l_787[i] = (-1L);}}
                                        while (((g_759 < l_617) && (!l_617)) )
{

{
        transparent_crc(g_3109[i], "g_3109[i]", j);
        if (j) {
if (g_184)
                            continue;

                    printf("index = [%d]\n", i);}

    }

}
                    if ((safe_sub_func_uint32_t_u_u((safe_add_func_uint16_t_u_u((safe_add_func_int32_t_s_s(1L, (safe_add_func_uint32_t_u_u((((g_76 , (safe_lshift_func_int8_t_s_u((g_87 | (safe_unary_minus_func_int32_t_s((0x93B57206L || (safe_lshift_func_int16_t_s_s((((~(safe_mod_func_int8_t_s_s(p_61, g_9))) , ((g_34[0] != p_61) == l_94)) != 1UL), 11)))))), g_9))) , 0x62L) == (-1L)), 0L)))), l_94)), g_87)))
    {
        uint16_t l_100[1];
        int32_t l_162 = 1L;
        uint32_t l_187[9];
        int32_t l_219 = 0xFFE616ADL;
        int32_t l_251 = 0x539E8B65L;
        int i;
        for (i = 0; i < 1; i++)
            l_100[i] = 0x62BAL;
        for (i = 0; i < 9; i++)
            l_187[i] = 6UL;
        for (p_61 = 1; (p_61 <= 56); p_61 = safe_add_func_int32_t_s_s(p_61, 3))
        {
            int32_t l_97[2];
            int32_t l_159 = (-1L);
            int8_t l_203 = 0xFFL;
            int i;
            for (i = 0; i < 2; i++)
                l_97[i] = 1L;
            g_98[1][3] = (g_34[0] <= l_97[0]);
            for (g_87 = 0; (g_87 <= 4); g_87 += 1)
            {
                int32_t l_99 = 0x22F50FADL;
                uint32_t l_122[6][1][10] = {{{4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL}},{{4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL}},{{4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL}},{{4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL}},{{4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL}},{{4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL}}};
                int32_t l_165 = 0xA5772CECL;
                int i, j, k;
                if (l_99)
                    { while (((g_897 < l_165) || ((l_287<766460092) || (l_336 < l_1632))) )
{

;


}
                    break;}
                for (g_68 = 1; (g_68 <= 4); g_68 += 1)
                {
                    if (l_100[0])
                        ;;
                }

{
                        int32_t l_6761 = 0x97130E1AL;
                        uint32_t l_6767 = 0UL;
                        ;
                    }

                    for (g_68 = 1; (g_68 <= 4); g_68 += 1)
                {

if (l_100[0])
                        break;

                    return p_61;
                }
                for (g_76 = 0; (g_76 <= 4); g_76 += 1)
                {
                    int32_t l_123 = (-5L);
                    int32_t l_160 = 0L;
                    int32_t l_207[2];
                    int i, j;

{
                        uint32_t l_3124 = 0UL;
                        int32_t l_3125 = 0xC3763125L;
                        l_3124 = (g_76 != l_159);
                        l_3125 = l_1158;
                    }

                    for (i = 0; i < 2; i++)
                        {
{
                        l_219 = (g_1370[2] = (g_6428 | (safe_sub_func_int8_t_s_s(g_2580[0][7], g_1345))));
                        g_2853[0][0][3] = ((safe_mod_func_uint8_t_u_u(g_1345, l_99)) ^ (0x9780L ^ (safe_rshift_func_int8_t_s_s(0xA1L, 2))));
                    }

                    l_207[i] = 0x2DF446B0L;}

{
                    uint16_t l_1444 = 8UL;
                    l_287 = (~(g_172 == (safe_add_func_int32_t_s_s((safe_lshift_func_uint8_t_u_u((((((!((((((g_5844 || (((safe_rshift_func_int16_t_s_u(((0x2FA0L == (~1L)) < (((safe_add_func_uint8_t_u_u((((((3L > 0x0BD0L) , g_3193) < ((l_251 = ((g_6029 ^ (((safe_mod_func_int32_t_s_s((((safe_sub_func_int8_t_s_s(g_6029, l_1444)) | g_5844) || l_99), 0x2D55D153L)) , g_6029) < 0L)) | g_6029)) , g_6029)) > g_76) | 0UL), l_251)) != l_1444) <= g_6029)), g_172)) < g_1370[2]) != 0xB0L)) < g_6029) , g_5512) , l_332) || 0x09D949F6L) & g_6029)) == 0x3EL) != 255UL) , g_6029) , l_287), g_6029)), 0x0F264CFBL))));
                }

                    l_123 = (((safe_rshift_func_uint8_t_u_u(p_61, (safe_rshift_func_int16_t_s_s((0xA3L | (safe_mod_func_uint8_t_u_u((((l_97[1] > ((((((safe_sub_func_int8_t_s_s(((~((((g_98[g_87][g_76] = ((safe_lshift_func_int16_t_s_s(((((safe_add_func_int8_t_s_s((safe_div_func_uint16_t_u_u(((+0L) < ((safe_unary_minus_func_int8_t_s((((safe_rshift_func_int8_t_s_u(l_97[0], (safe_sub_func_int8_t_s_s(0xA0L, l_122[1][0][7])))) , (g_98[1][3] ^ l_122[1][0][7])) , 0L))) != g_35)), g_35)), g_68)) , l_97[1]) & l_99) == 0L), 0)) == p_61)) | l_97[0]) , l_100[0]) != p_61)) < 0xD733C455L), l_99)) > p_61) != p_61) > p_61) && p_61) || l_94)) & g_87) <= g_34[0]), l_100[0]))), 4)))) == 0x38L) , l_97[0]);

                    return l_173[0];
                }
            }
        }
        for (g_87 = 0; (g_87 < 57); g_87 = safe_add_func_int16_t_s_s(g_87, 5))
        {
            int32_t l_220[5];
            int i;
                                                while (!((l_136 < g_1352)) )
{

if (g_1370[1])
                            {
for (l_162 = 29; (l_162 != 28); l_162 = safe_sub_func_int16_t_s_s(l_162, 7))
                    {
                        l_287 = l_251;
                        l_287 = (((g_3172 = (-5L)) , (~(7UL && ((g_34[0] && g_9) != (safe_mod_func_uint8_t_u_u(1UL, (safe_div_func_uint16_t_u_u((((g_3486 | (1UL ^ (g_9 <= (l_287 ^ g_335)))) >= 0x083A407DL) ^ g_9), 0x8056L)))))))) >= g_9);
                    };


                    break;}

}
                    for (i = 0; i < 5; i++)
                l_220[i] = 0x9DECBAA9L;
            if ((safe_add_func_uint16_t_u_u(0xF50EL, (p_61 , ((((((safe_add_func_uint8_t_u_u(((l_100[0] || 0x3F7DL) , (!(0x56L & p_61))), (l_162 = l_173[0]))) && (safe_sub_func_int32_t_s_s(((safe_add_func_int32_t_s_s(((((9UL || (g_204 != 6UL)) != l_219) , g_34[0]) , 1L), p_61)) == g_76), g_154))) , g_204) && 0x4CDFC208L) >= l_220[1]) < 0x6383L)))))
            {
                                               int8_t BLBLBAl_1000 = (~((((~((((l_1000 & g_335) >> g_759) ^ (~(l_94))))) || (~(l_162))) / (~(((~(l_1439)) ^ ((l_206 || (~(l_397))) & ((~(l_1632)) | g_1368))))))));
int32_t BLBLBBl_162 = (~(((~(BLBLBAl_1000)) & ((~((g_1368 << (l_1000 & l_206)))) & ((l_1439 & ((~(g_335)) & l_94)) & ((~((~(l_1632)))) % ((~((g_759 >> l_162))) | l_397)))))));
uint8_t BLBLBCl_206 = (~((((~(((((~(l_162)) ^ (~(l_206))) ^ ((l_397 % g_1368) ^ l_1000)) ^ (~((~(l_1439))))))) / (~(l_1632))) >> (~(((BLBLBBl_162 || (~(l_94))) | (~((BLBLBAl_1000 || (g_335 / g_759))))))))));
uint32_t BLBLBDg_1368 = (~(((((((((g_759 / l_94) / l_1632) | (BLBLBCl_206 ^ BLBLBBl_162)) | l_397) / g_1368) << l_162) & (~((l_1439 % l_206)))) / (~(((l_1000 ^ BLBLBAl_1000) || (~((~(g_335))))))))));
uint16_t BLBLBEl_1632 = (~((((~((~((l_1439 ^ (~(l_397))))))) & ((((~(BLBLBAl_1000)) & g_335) || (~(BLBLBBl_162))) & ((~((~(BLBLBDg_1368)))) || ((~(l_1632)) | (~(((~(l_1000)) || l_94))))))) | ((l_206 | ((g_759 & BLBLBCl_206) % g_1368)) & l_162))));
if(l_1632){
                                    if (((!g_335) || (l_391 < g_35)) )
{

for (l_391 = 0; (l_391 <= 4); ++l_391)
            {
                const int8_t l_881 = 0xEDL;
                int32_t l_882 = 0x57CEB71EL;
                int32_t l_962[5][9][5] = {{{0x04993818L,0x1F12D1B3L,0x83DA8E60L,0L,0x83DA8E60L},{0x04993818L,0x04993818L,0xDD9BDD25L,0x783CF189L,2L},{1L,0x92FEEC02L,0x83DA8E60L,(-7L),2L},{0x92FEEC02L,0x1F12D1B3L,0x3ADE3604L,0x6D64A2DBL,0x83DA8E60L},{0x34A1D470L,0x92FEEC02L,0xDD9BDD25L,0x6D64A2DBL,0xE4C0BDBEL},{1L,0x04993818L,0x3CAC75C6L,6L,0xE80E69F2L},{0L,0xDD9BDD25L,0x3CAC75C6L,0x3EF6D47EL,(-5L)},{0x83DA8E60L,0L,(-1L),0x89A60667L,0xE80E69F2L},{0x4D112763L,0L,0x138E5C65L,6L,0xCA65903CL}},{{0x3ADE3604L,0xDD9BDD25L,(-5L),0x89A60667L,(-5L)},{0x3ADE3604L,0x3ADE3604L,(-1L),0x3EF6D47EL,4L},{0x4D112763L,0x83DA8E60L,(-5L),6L,4L},{0x83DA8E60L,0xDD9BDD25L,0x138E5C65L,0x628F1DA6L,(-5L)},{0L,0x83DA8E60L,(-1L),0x628F1DA6L,0xCA65903CL},{0x4D112763L,0x3ADE3604L,0x3CAC75C6L,6L,0xE80E69F2L},{0L,0xDD9BDD25L,0x3CAC75C6L,0x3EF6D47EL,(-5L)},{0x83DA8E60L,0L,(-1L),0x89A60667L,0xE80E69F2L},{0x4D112763L,0L,0x138E5C65L,6L,0xCA65903CL}},{{0x3ADE3604L,0xDD9BDD25L,(-5L),0x89A60667L,(-5L)},{0x3ADE3604L,0x3ADE3604L,(-1L),0x3EF6D47EL,4L},{0x4D112763L,0x83DA8E60L,(-5L),6L,4L},{0x83DA8E60L,0xDD9BDD25L,0x138E5C65L,0x628F1DA6L,(-5L)},{0L,0x83DA8E60L,(-1L),0x628F1DA6L,0xCA65903CL},{0x4D112763L,0x3ADE3604L,0x3CAC75C6L,6L,0xE80E69F2L},{0L,0xDD9BDD25L,0x3CAC75C6L,0x3EF6D47EL,(-5L)},{0x83DA8E60L,0L,(-1L),0x89A60667L,0xE80E69F2L},{0x4D112763L,0L,0x138E5C65L,6L,0xCA65903CL}},{{0x3ADE3604L,0xDD9BDD25L,(-5L),0x89A60667L,(-5L)},{0x3ADE3604L,0x3ADE3604L,(-1L),0x3EF6D47EL,4L},{0x4D112763L,0x83DA8E60L,(-5L),6L,4L},{0x83DA8E60L,0xDD9BDD25L,0x138E5C65L,0x628F1DA6L,(-5L)},{0L,0x83DA8E60L,(-1L),0x628F1DA6L,0xCA65903CL},{0x4D112763L,0x3ADE3604L,0x3CAC75C6L,6L,0xE80E69F2L},{0L,0xDD9BDD25L,0x3CAC75C6L,0x3EF6D47EL,(-5L)},{0x83DA8E60L,0L,(-1L),0x89A60667L,0xE80E69F2L},{0x4D112763L,0L,0x138E5C65L,6L,0xCA65903CL}},{{0x3ADE3604L,0xDD9BDD25L,(-5L),0x89A60667L,(-5L)},{0x3ADE3604L,0x3ADE3604L,(-1L),0x3EF6D47EL,4L},{0x4D112763L,0x83DA8E60L,(-5L),6L,4L},{0x83DA8E60L,0xDD9BDD25L,0x138E5C65L,0x628F1DA6L,(-5L)},{0L,0x83DA8E60L,(-1L),0x628F1DA6L,0xCA65903CL},{0x4D112763L,0x3ADE3604L,0x3CAC75C6L,6L,0xE80E69F2L},{0L,0xDD9BDD25L,0x3CAC75C6L,0x3EF6D47EL,(-5L)},{0x83DA8E60L,0L,1L,0xA3A1AEA2L,0x71DA6459L},{(-7L),0x3CAC75C6L,0x6D64A2DBL,0x34A1D470L,(-1L)}}};
                int i, j, k;
                if ((BLBLBCl_206 && (safe_lshift_func_uint16_t_u_s((((g_9 , ((g_1370[0] = (l_1000 = g_98[1][4])) == (g_9 = ((~(BLBLBCl_206 || (((safe_div_func_int32_t_s_s((BLBLBCl_206 , (~(l_882 = ((safe_mod_func_int32_t_s_s((safe_sub_func_uint32_t_u_u(((~0UL) > ((safe_rshift_func_int16_t_s_s(l_483, 9)) ^ 0xC0CFL)), (safe_add_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_u((l_398 || BLBLBCl_206), 13)) , l_881), g_9)))), g_172)) , 0xCA08L)))), (-2L))) , l_881) > (-7L)))) >= g_1599)))) , BLBLBEl_1632) || BLBLBCl_206), g_87))))
                {
                    int32_t l_896 = 0x9A1C0234L;
                    int32_t l_898 = 0x5FF7DF79L;
                    int32_t l_899 = 1L;
                    int32_t l_900 = 0x9B4DE922L;
                    l_162 = ((i != 0x8D49L) , ((safe_sub_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((BLBLBCl_206 = (((safe_add_func_uint16_t_u_u((((((((((((((l_900 = ((safe_sub_func_int8_t_s_s((l_899 = (safe_rshift_func_uint16_t_u_s((BLBLBCl_206 == ((j = ((l_398 = BLBLBCl_206) & (g_6771 && (l_898 = (!((BLBLBCl_206 < (safe_rshift_func_uint8_t_u_u((((g_1352 = (g_1370[2] = (g_34[0] <= ((4294967295UL || (j = ((BLBLBCl_206 < l_882) || l_882))) != l_896)))) , g_87) & g_6771), 0))) != l_896)))))) & 0x7AL)), 0))), 255UL)) && BLBLBCl_206)) , g_98[1][3]) > BLBLBCl_206) < BLBLBCl_206) == BLBLBCl_206) <= l_1304) < 0x41A1L) , 1L) , g_240) == 0x411DL) & 0UL) < 1L) != 65535UL), 3UL)) & g_6771) >= i)), g_34[0])), g_240)) , BLBLBCl_206));
                }
                else
                {
                    int32_t l_904 = 1L;
                    for (BLBLBEl_1632 = 16; (BLBLBEl_1632 > 46); BLBLBEl_1632 = safe_add_func_uint16_t_u_u(BLBLBEl_1632, 5))
                    {
                        int16_t l_905 = 0L;

{
                    uint16_t l_1448 = 5UL;
                    l_162 = ((safe_add_func_uint32_t_u_u((~(((l_1448 > (safe_add_func_uint16_t_u_u((l_219 = g_3193), ((((safe_mod_func_uint16_t_u_u(g_3193, (safe_rshift_func_uint16_t_u_u(0x523AL, 9)))) && ((safe_rshift_func_uint8_t_u_s((g_1370[2] , (((safe_sub_func_uint16_t_u_u((l_882 = (safe_sub_func_int32_t_s_s((l_882 || (safe_div_func_int32_t_s_s((safe_div_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(g_506, (((9UL ^ (!(g_34[0] || 1L))) | g_3317) == BLBLBEl_1632))), 7UL)), (-9L)))), g_34[0]))), g_35)) ^ g_6771) , 1UL)), l_1427)) == 0L)) != l_964) , l_136)))) | g_3193) < g_3193)), g_3317)) , g_3193);
                    if ((g_3486 = (g_5512 ^ (safe_lshift_func_int16_t_s_u((g_34[0] == ((g_2043 || (safe_sub_func_int8_t_s_s(((((g_3193 > ((((((l_964 , 0L) & (safe_add_func_uint32_t_u_u((((g_1370[2] = (safe_lshift_func_int16_t_s_u((l_287 = (safe_rshift_func_uint8_t_u_s((g_3463 == (safe_sub_func_uint32_t_u_u(g_6771, l_1448))), g_2043))), BLBLBBl_162))) , g_3193) < 0xA7L), l_1448))) ^ g_3600) , 1UL) > g_3193) && 0xD2L)) , 1L) >= g_2852) || l_287), g_759))) == l_1000)), g_3193)))))
                    {
                        uint32_t l_1490 = 0x81080423L;
                        int32_t l_1495 = 4L;
                        int32_t l_1502 = 0x7250CA9CL;
                        g_1345 = ((safe_add_func_uint16_t_u_u((g_3193 && (((l_1427 = (l_162 = (safe_lshift_func_int16_t_s_u(l_1490, (safe_sub_func_int16_t_s_s((safe_lshift_func_int8_t_s_s((l_1495 = g_3193), (((((-2L) | ((+(safe_lshift_func_int16_t_s_u(((safe_rshift_func_int16_t_s_u(((0xC617L ^ (+l_1632)) , (((l_1502 = g_3193) | (+((g_3486 = ((((((((~7UL) != ((+(0xBFL || 6UL)) , 0UL)) , l_219) <= g_6029) || g_3193) >= g_496[2]) & g_3193) <= g_3193)) ^ g_3193))) > 0x1C62L)), 14)) , 1L), l_219))) ^ 0xDBL)) ^ 1L) && 0x930BL) != 0x099DL))), g_3193)))))) , g_1345) && g_3463)), g_3193)) , l_162);
                        g_1370[0] = (safe_div_func_uint32_t_u_u(0xFA1832D6L, (g_1345 = (~(g_3193 & g_3193)))));
                        l_1502 = (safe_rshift_func_uint8_t_u_s(((((safe_add_func_uint32_t_u_u(g_2467, (safe_add_func_int32_t_s_s((g_2043 >= l_334[1]), 0UL)))) ^ l_1502) & g_3463) ^ 0x88F5L), ((safe_sub_func_uint32_t_u_u((+(l_173[0] = (safe_rshift_func_int8_t_s_u((l_1427 = (6UL || (((((safe_rshift_func_int16_t_s_s((l_1495 = 0x3722L), g_3193)) != g_3193) > g_3193) & g_3463) , l_1448))), 1)))), 0xB5F15FAEL)) <= g_472)));
                    }
                    else
                    {
                        uint32_t l_1536 = 7UL;
                        int32_t l_1540 = 0x3A68B249L;
                        l_1540 = ((!g_3463) && (((safe_mod_func_int16_t_s_s(((((g_1370[2] = ((((safe_sub_func_uint32_t_u_u((g_5210[0] = 4294967286UL), ((0UL & (((safe_mod_func_uint32_t_u_u(((safe_sub_func_int8_t_s_s(((l_219 = (safe_lshift_func_uint16_t_u_s((l_1536 > g_5512), (((((safe_lshift_func_uint16_t_u_u(65535UL, 3)) , ((-2L) & (g_240 , (BLBLBBl_162 , l_219)))) & g_3486) < l_1536) <= g_3172)))) , BLBLBBl_162), g_759)) , g_2043), 0x5DB84211L)) == g_3193) | 0x39L)) > 0x3F73F712L))) | 0L) && (-1L)) , g_3193)) && g_35) > g_3193) <= g_6771), g_34[0])) == l_1536) ^ 5UL));
                        l_219 = g_3193;
                    }
                    return g_759;
                }

                    l_905 = (l_904 = g_469);
                    }
                    i = (0UL != ((safe_rshift_func_uint8_t_u_u((g_5210[0] = (0UL >= (safe_sub_func_uint16_t_u_u((g_240 | (safe_mod_func_int32_t_s_s((l_162 = (g_1352 , (g_1352 > ((safe_sub_func_int16_t_s_s(BLBLBCl_206, (((safe_mod_func_int8_t_s_s(((((safe_div_func_uint32_t_u_u((((((safe_mod_func_int8_t_s_s(0xA2L, ((safe_lshift_func_int16_t_s_s(((safe_rshift_func_int16_t_s_u((safe_div_func_uint16_t_u_u(((safe_div_func_int32_t_s_s((l_882 = (safe_sub_func_int16_t_s_s((((~(safe_mod_func_int16_t_s_s((l_331[5] & 0UL), BLBLBCl_206))) < 0x2A04L) & g_34[0]), 0UL))), 1UL)) ^ BLBLBCl_206), 0xBBEBL)), 1)) <= 0x986DL), g_34[0])) || l_904))) && BLBLBCl_206) > BLBLBCl_206) && i) | 0xCD26EEC4L), BLBLBCl_206)) || BLBLBCl_206) & BLBLBCl_206) == g_5844), l_964)) , g_240) ^ 0UL))) , 0x5A51D983L)))), 1UL))), BLBLBCl_206)))), g_3193)) >= 8UL));
                }
                j = ((l_964 = ((l_398 = (l_1304 , l_334[1])) < (safe_lshift_func_int8_t_s_s(((BLBLBCl_206 == g_240) ^ (l_617 <= ((l_882 != (BLBLBCl_206 >= ((((safe_add_func_int16_t_s_s((safe_add_func_int32_t_s_s(((((safe_lshift_func_uint8_t_u_u((((((((((g_6771 = ((~255UL) & (safe_div_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((((+(safe_rshift_func_int16_t_s_u(((l_219 = (safe_mod_func_int8_t_s_s(((l_962[2][1][1] = (safe_lshift_func_int16_t_s_s(((j && g_87) > 0x79L), 15))) , BLBLBCl_206), BLBLBCl_206))) & g_352), 7))) & BLBLBCl_206) , i), 0xB69CL)), 3UL)))) & g_9) && BLBLBCl_206) >= BLBLBCl_206) , 255UL) < i) == g_496[2]) ^ BLBLBCl_206) <= (-1L)), 0)) >= BLBLBCl_206) || l_962[1][7][4]) | l_1000), 0L)), (-4L))) && 0L) | i) > l_964))) != (-9L)))), 1)))) <= BLBLBCl_206);
            }
{
                    int i;
                    for (g_1368 = 0; (g_1368 <= 7); g_1368 += 1)
                    {
                        int i;
                        return l_331[(g_2467 + 1)];
                    }
                    g_5210[g_2467] = (safe_lshift_func_uint8_t_u_s(l_331[(g_2467 + 2)], (l_999 = 7L)));
                    g_2043 = g_5210[g_2467];
                    return g_87;
                }

                    ;


}
                    BLBLBAl_1000 = l_1000;
BLBLBBl_162 = l_162;
BLBLBCl_206 = l_206;
BLBLBDg_1368 = g_1368;
BLBLBEl_1632 = l_1632;
l_1000 = (~((((((~(BLBLBBl_162)) || BLBLBAl_1000) & BLBLBEl_1632) || (l_206 % g_759)) || (~((((~((~(l_1439)))) || (~((~((~(g_1368))))))) % ((~((BLBLBDg_1368 & g_335))) / ((~((((l_397 | l_162) / l_94) | l_1632))) | (BLBLBCl_206 & l_1000)))))))));
l_162 = (~((((~(l_162)) & (l_1632 << BLBLBBl_162)) | ((~(((~((l_1439 / (l_1000 % l_206)))) % (~((l_94 / (~((BLBLBDg_1368 || BLBLBEl_1632))))))))) ^ (~((l_397 / ((~(((~((~((g_759 || BLBLBAl_1000))))) >> (g_1368 % BLBLBCl_206)))) % (~(g_335))))))))));
                                   if (((g_1345<=0U) || ((g_469 < l_999) && (l_136<=-1391743263))))
                    l_206 = (~((((~(((~(((~(BLBLBAl_1000)) % (l_162 ^ l_1439)))) || (~((g_759 || BLBLBEl_1632)))))) || ((~(((l_397 % l_94) % (l_1000 % BLBLBDg_1368)))) >> ((((~((l_1632 % BLBLBCl_206))) & (~(l_206))) || BLBLBBl_162) & (~(g_1368))))) ^ (~((~((~(g_335)))))))));
                                    while ((l_1304<0) )
{

l_94 += 1;


}
                    g_1368 = (~((((~((~((l_94 % BLBLBDg_1368))))) % (~((((~(g_335)) ^ ((l_206 / ((~(l_1000)) | l_1632)) % (~((BLBLBBl_162 || l_162))))) & (l_1439 ^ ((~((g_759 & (~(BLBLBEl_1632))))) ^ (~((l_397 || BLBLBCl_206))))))))) || (~(((~(g_1368)) % BLBLBAl_1000))))));
l_1632 = (~((((((l_1632 & g_1368) >> (BLBLBCl_206 % ((~(l_397)) % l_206))) & (~(BLBLBBl_162))) % (~(((~((~((~((BLBLBDg_1368 || l_94))))))) || (~((l_1000 ^ (~(g_759))))))))) << (((BLBLBEl_1632 / l_1439) / (~((g_335 << (~(BLBLBAl_1000)))))) | l_162))));
if((BLBLBCl_206 > BLBLBDg_1368)){
printf("l_1000=%lld\n", (long long)l_1000);
;
}
if(((l_206>73) || (BLBLBBl_162>0))){

for (l_483 = 0; (l_483 >= 21); l_483 = safe_add_func_uint16_t_u_u(l_483, 2))
                    {
                        uint32_t l_1192 = 0UL;
                        k = (safe_unary_minus_func_uint16_t_u((g_34[0] || l_1439)));
                        l_1192 = g_5512;
                    };


                    printf("l_162=%lld\n", (long long)l_162);
;
}
if((!l_1632)){
printf("l_206=%llu\n", (unsigned long long)l_206);
;
}
if((!l_206)){
;
break;
}
if((((!BLBLBAl_1000) && (BLBLBCl_206<4)) && ((BLBLBAl_1000<=-9) && (g_759 < BLBLBBl_162)))){
printf("l_1632=%llu\n", (unsigned long long)l_1632);
l_1632 = (~((((l_1632 >> (~(l_1439))) ^ ((~(l_397)) % g_759)) << ((~(BLBLBDg_1368)) << ((~(BLBLBAl_1000)) >> (~((((~(g_335)) || BLBLBCl_206) || ((BLBLBBl_162 >> ((~((BLBLBEl_1632 % g_1368))) << (~((l_162 | l_206))))) >> (l_1000 | (~(l_94))))))))))));
;

for (l_1632 = 16; (l_1632 > 46); l_1632 = safe_add_func_uint16_t_u_u(l_1632, 5))
                    {
                        int16_t l_905 = 0L;
                        l_905 = (BLBLBBl_162 = l_1158);
                    };


                    continue;
}
}
l_1000 = BLBLBAl_1000;
l_162 = BLBLBBl_162;
                                    if ((!g_184) )
{

if (l_251) printf("index = [%d]\n", l_136);

}
                    l_206 = BLBLBCl_206;
g_1368 = BLBLBDg_1368;
l_1632 = BLBLBEl_1632;

                    g_204 = (safe_rshift_func_uint16_t_u_s(g_34[0], 3));
            }
            else
            {
                uint16_t l_232 = 0UL;
                int32_t l_249[1];
                int32_t l_250 = 0x43E91BF3L;
                int i;
                for (i = 0; i < 1; i++)
                    {
;


                    l_249[i] = (-10L);}
                ;
            }
                                           uint16_t BLCLCHl_1632 = (~(((l_162 & (~(((~(l_1632)) / (~(g_87)))))) << ((~((~((~((l_964 & (l_251 >> g_573)))))))) / (((~(l_1427)) && (l_94 ^ l_391)) + g_352)))));
uint32_t BLCLCIl_964 = (~(((~(((~((~((~(l_94)))))) / (~((((~(l_391)) ^ l_964) && g_87)))))) | (~((((BLCLCHl_1632 - g_352) / ((~(g_573)) - ((~((~(l_1427)))) && l_162))) - (~((l_1632 / l_251)))))))));
uint32_t BLCLCJg_352 = (~((((~(((((~((l_94 ^ l_1632))) && (BLCLCIl_964 | l_162)) & (~(((~(g_352)) ^ (l_964 ^ g_87))))) / l_1427))) ^ (~((~((~(BLCLCHl_1632))))))) / ((~(l_251)) ^ (l_391 && (~(g_573)))))));
int32_t BLCLCKl_251 = (~(((~((~((~((~(l_162)))))))) & (~((((((l_391 - g_573) + l_964) && (~(g_352))) && (((BLCLCIl_964 / (BLCLCHl_1632 + l_251)) && BLCLCJg_352) ^ ((~(g_87)) ^ (~(l_94))))) + ((~(l_1427)) | l_1632)))))));
int8_t BLCLCLl_391 = (~((((~(l_391)) && (BLCLCJg_352 & ((~(l_1632)) | l_94))) / ((~((((l_964 && g_87) >> ((l_251 & (~(l_1427))) && (l_162 | BLCLCIl_964))) + g_352))) ^ (~((~((~((BLCLCHl_1632 << (g_573 & BLCLCKl_251))))))))))));
int32_t BLCLCMl_162 = (~((((~(l_94)) / ((~(l_391)) | ((~((l_162 << (l_1427 && l_964)))) && BLCLCIl_964))) | ((((~(g_87)) | BLCLCKl_251) && ((~(l_251)) & g_352)) - ((BLCLCLl_391 - ((~((~(l_1632)))) + (BLCLCJg_352 & (~((~(g_573))))))) & BLCLCHl_1632)))));
if((((!BLCLCMl_162) || (!l_1427)) || (l_94 > BLCLCIl_964))){
BLCLCHl_1632 = l_1632;
BLCLCIl_964 = l_964;
BLCLCJg_352 = g_352;
BLCLCKl_251 = l_251;
BLCLCLl_391 = l_391;
BLCLCMl_162 = l_162;
l_1632 = (~(((~((((~(BLCLCHl_1632)) && ((~(BLCLCMl_162)) + ((~((~(l_94)))) - BLCLCKl_251))) - (l_964 - l_251)))) + ((~((((~((~(g_87)))) ^ ((~(BLCLCJg_352)) - (g_573 - l_162))) ^ l_1632))) && ((~(l_1427)) ^ (((BLCLCLl_391 & l_391) ^ BLCLCIl_964) | g_352))))));
l_964 = (~((((~(l_94)) | (~((~((((~((~(BLCLCJg_352)))) & l_391) ^ ((~(((~((~(l_162)))) - ((~((~(g_352)))) && BLCLCLl_391)))) - g_87))))))) | (~((~(((~(((BLCLCKl_251 & (l_251 && g_573)) & BLCLCIl_964))) & (~(((~((l_1632 ^ BLCLCMl_162))) && ((l_964 | l_1427) / (~(BLCLCHl_1632))))))))))))));
g_352 = (~((((~((~((l_162 ^ (((~(BLCLCJg_352)) & (~((~(g_87))))) - (~(l_251)))))))) / (~((~((~((~(BLCLCHl_1632))))))))) && ((~((~(BLCLCMl_162)))) >> (((~((~(BLCLCKl_251)))) | (l_964 && l_1632)) && ((((~(BLCLCLl_391)) ^ g_352) & ((l_391 | g_573) | l_94)) | (~((BLCLCIl_964 + l_1427)))))))));
l_251 = (~(((~((~((~((((~(BLCLCIl_964)) / BLCLCKl_251) ^ (~((((~((BLCLCJg_352 & g_87))) ^ ((~((~(l_94)))) | l_251)) & (l_162 | l_1632))))))))))) + (((~((BLCLCMl_162 & (~(BLCLCHl_1632))))) + (~((g_573 / ((~(l_391)) ^ BLCLCLl_391))))) & (~(((~((~(l_964)))) && (l_1427 - (~(g_352))))))))));
l_391 = (~((((l_391 & (g_352 | (~((l_964 / (~(g_573))))))) >> (~((~((BLCLCKl_251 && ((~(BLCLCIl_964)) & l_162))))))) | ((~((l_1427 ^ BLCLCJg_352))) - ((~(((l_251 ^ l_1632) && (~(l_94))))) && (((g_87 | (~(BLCLCHl_1632))) | BLCLCMl_162) && (~(BLCLCLl_391))))))));
l_162 = (~((((BLCLCMl_162 - (~(g_573))) ^ (~((~(l_1632))))) - (~(((((l_251 | l_391) + ((~(l_1427)) - l_94)) | ((l_162 & (~(BLCLCHl_1632))) / (l_964 - BLCLCLl_391))) - ((~((~((~((g_87 & g_352))))))) && ((~(((~(BLCLCJg_352)) & BLCLCKl_251))) - BLCLCIl_964))))))));
if((l_1632<36156)){
printf("l_1632=%llu\n", (unsigned long long)l_1632);
goto lbl_486;
}
if((BLCLCLl_391>32)){
printf("l_964=%llu\n", (unsigned long long)l_964);
goto lbl_486;
}
if((l_1632 < l_964)){
printf("g_352=%llu\n", (unsigned long long)g_352);
continue;
}
LABEL_LCLCN: if(((l_1632 && (BLCLCKl_251 < g_87)) || !(BLCLCHl_1632))){
printf("l_251=%lld\n", (long long)l_251);
break;
}
if((((l_162 < l_1427) || (BLCLCJg_352>2700108046U)) || (!g_352))){
printf("l_391=%lld\n", (long long)l_391);
break;
}
if((l_162==29382)){
printf("l_162=%lld\n", (long long)l_162);
goto lbl_682;
}
}
l_1632 = BLCLCHl_1632;
l_964 = BLCLCIl_964;
g_352 = BLCLCJg_352;
l_251 = BLCLCKl_251;
l_391 = BLCLCLl_391;
l_162 = BLCLCMl_162;

                    if (g_98[1][3])
                {
{
                        if (l_162)
                            goto lbl_1005;

{
                        uint32_t l_4042 = 0xF2B5B59FL;
                        int32_t l_4043[8][7][2] = {{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}},{{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L}},{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}},{{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L}},{{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L}},{{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L},{0xF22F229CL,0L},{0L,0x6301DF73L},{0L,0L}}};
                        int i, j, k;
                        l_4043[6][2][0] = l_4042;
                    }

                    return g_9;
                    }

                    break;}
                                                if ((!g_1288) )
{

l_332 -= 1;


}
                    l_220[4] = (safe_rshift_func_uint16_t_u_s((safe_add_func_uint8_t_u_u((safe_add_func_uint16_t_u_u(l_220[1], 0x30AAL)), 0x0BL)), 14));
        }
    }
    else
    {
        int16_t l_262[7] = {0x3FDAL,0L,0L,0x3FDAL,0L,0L,0x3FDAL};
        int32_t l_264 = 0xA848BB9CL;
        int i;
        g_204 = (l_94 >= (safe_lshift_func_uint16_t_u_u((((safe_sub_func_int16_t_s_s(0L, (l_262[1] && ((!(l_264 = (0UL ^ g_172))) | (p_61 | p_61))))) , (((safe_rshift_func_uint16_t_u_u((((safe_lshift_func_int8_t_s_s(p_61, g_240)) || p_61) && g_34[0]), 4)) != l_262[1]) ^ l_173[0])) < g_9), p_61)));
        l_264 = (g_204 = 0x6EEFEC2FL);
        l_264 = (safe_add_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((safe_sub_func_int32_t_s_s((l_136 = g_275), (safe_sub_func_uint16_t_u_u(((safe_add_func_uint32_t_u_u(((((-1L) ^ p_61) | (!g_87)) < g_240), (p_61 , (safe_rshift_func_uint16_t_u_u(((((((l_173[0] != (safe_lshift_func_int8_t_s_s(((g_154 <= (((safe_lshift_func_uint16_t_u_u((1L >= g_34[0]), 10)) , g_275) != 0L)) || l_287), g_172))) < p_61) > p_61) , l_173[0]) , p_61) >= 1UL), g_9))))) | 0x28L), p_61)))) < g_204), 255UL)), p_61));
    }
    l_336 = (safe_sub_func_int32_t_s_s((safe_mod_func_int16_t_s_s((l_173[0] = (safe_add_func_int16_t_s_s((g_335 = (safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s((safe_mod_func_int8_t_s_s(l_173[0], (p_61 , p_61))), 6)), (safe_sub_func_int16_t_s_s((safe_add_func_int8_t_s_s(((safe_sub_func_int8_t_s_s((g_154 = l_173[0]), (safe_mod_func_int32_t_s_s((((safe_div_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(((4294967290UL ^ ((safe_rshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(((((l_332 = (g_184 ^ ((safe_sub_func_uint8_t_u_u((l_136 = (safe_sub_func_uint16_t_u_u((((((+(safe_sub_func_uint32_t_u_u((p_61 || g_34[0]), (safe_sub_func_int16_t_s_s(((((safe_add_func_int32_t_s_s(((safe_lshift_func_uint16_t_u_u(0xD4A5L, 3)) , 1L), 0x81C66F58L)) > 0x37CAL) > l_206) , (-1L)), 0L))))) != l_94) | 0L) <= p_61) & g_240), l_173[0]))), l_331[5])) > 0xC7ACL))) || p_61) || l_333[3][0][1]) ^ l_287), (-7L))), p_61)) || g_240)) <= g_34[0]), p_61)), 0x8078L)) <= l_334[1]) , l_287), 0x591AD4FCL)))) | l_333[1][1][2]), 247UL)), g_34[0]))))), g_76))), g_87)), 1UL));
                                        if ((l_398>1U) )
{

{
                        int8_t l_5764 = 0xC3L;
                        l_173[0] = ((safe_unary_minus_func_int16_t_s((-1L))) == (((safe_rshift_func_int8_t_s_u(((l_1439 = (((g_240 = ((g_3193 = g_87) ^ ((safe_mod_func_int8_t_s_s(l_173[0], (safe_rshift_func_int16_t_s_u((g_469 ^ (safe_add_func_uint16_t_u_u((safe_mod_func_int32_t_s_s(4L, (g_1288 , g_1798[5][2]))), ((-1L) | (safe_lshift_func_uint16_t_u_s(((g_1138 = (g_3486 <= g_1288)) <= g_87), g_1288)))))), g_1288)))) <= g_2440))) , l_136) ^ g_1288)) & g_1288), l_5764)) != 0xC85B220FL) & l_5764));
                    }

}
                    if ((((safe_div_func_int8_t_s_s((0xEC34L > (l_336 = (l_173[0] = (safe_mod_func_uint8_t_u_u((g_184 , p_61), l_136))))), (safe_add_func_uint32_t_u_u(0x59411BBBL, g_154)))) <= ((((safe_rshift_func_int8_t_s_u(g_68, 0)) != g_87) ^ (safe_div_func_uint16_t_u_u((((safe_sub_func_uint8_t_u_u((g_352 = (~(safe_mod_func_int8_t_s_s(((l_332 = ((9L & p_61) | p_61)) || 254UL), g_154)))), p_61)) <= (-1L)) || 0L), 0x3CD6L))) ^ p_61)) ^ 0x81A5ED34L))
    {
        return l_173[0];
    }
    else
    {
        int32_t l_395 = 5L;
        int32_t l_396[3];
        int32_t l_399 = 0x2D051CAAL;
        int32_t l_409 = 0x468612AFL;
        int32_t l_447 = (-6L);
        int16_t l_485 = 0xDC1FL;
        uint16_t l_549 = 0xC6FCL;
        int8_t l_593 = 0xF5L;
        int8_t l_625 = 0xA5L;
        uint32_t l_647 = 0x443CD030L;
        int16_t l_768 = 1L;
        uint8_t l_838 = 1UL;
        uint8_t l_861 = 0xD1L;
        uint32_t l_963 = 2UL;
        int32_t l_965 = 0xD3205230L;
        int8_t l_1026 = 1L;
        uint32_t l_1056 = 0x0C19864AL;
        uint32_t l_1171 = 0x59416A1DL;
        uint32_t l_1179 = 6UL;
        int8_t l_1203 = 0x17L;
        uint16_t l_1245 = 0xDD11L;
        const int32_t l_1401 = 0x33385897L;
        int32_t l_1471 = 1L;
        uint32_t l_1508 = 0x8BAEFB5FL;
        int8_t l_1539 = 0xC3L;
        int i;
        for (i = 0; i < 3; i++)
            l_396[i] = (-2L);

l_861 += 1;



for (k = 0; k < 9; k++)
    {
        transparent_crc(g_5446[k], "g_5446[k]", l_136);
        if (l_136) printf("index = [%d]\n", k);

    };


                    lbl_486:
        l_399 = (safe_add_func_uint32_t_u_u((g_76 = (safe_add_func_uint32_t_u_u((6L | ((safe_sub_func_int8_t_s_s((safe_div_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(((safe_add_func_int32_t_s_s((((l_332 = (l_336 = ((safe_add_func_int8_t_s_s(0xC8L, (safe_unary_minus_func_uint16_t_u((safe_mod_func_int8_t_s_s((safe_mod_func_int8_t_s_s((((safe_mod_func_int32_t_s_s(g_68, (safe_sub_func_uint16_t_u_u((l_396[2] = ((safe_sub_func_int8_t_s_s((!((safe_add_func_int32_t_s_s((safe_sub_func_int8_t_s_s((+(safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(((safe_unary_minus_func_uint16_t_u(0xD7A8L)) == (l_136 = (g_98[1][3] = l_391))), ((safe_div_func_uint8_t_u_u(0x53L, (l_173[0] = g_275))) , (((0xF16C2306L || ((((((!l_395) , (-4L)) && p_61) != p_61) <= p_61) <= g_204)) && 1UL) > g_172)))), p_61))), p_61)), 0x0B9372C3L)) && p_61)), 1UL)) && 0xB2L)), l_206)))) || 0x2D69L) == g_335), 0x16L)), p_61)))))) & 65535UL))) | g_87) , p_61), 0xB804852DL)) != 0UL), p_61)), 0L)) <= g_335), g_172)), l_397)) == l_398)), p_61))), (-10L)));

for (j = 29; (j != 28); j = safe_sub_func_int16_t_s_s(j, 7))
                    {
                        l_395 = l_395;
                        l_395 = (((g_3600 = (-5L)) , (~(7UL && ((g_34[0] && l_838) != (safe_mod_func_uint8_t_u_u(1UL, (safe_div_func_uint16_t_u_u((((g_506 | (1UL ^ (l_838 <= (k ^ l_768)))) >= 0x083A407DL) ^ l_838), 0x8056L)))))))) >= l_838);
                    };


                    if (((l_395 & g_275) , ((safe_add_func_uint32_t_u_u((l_136 = l_332), ((safe_rshift_func_int16_t_s_u((l_332 <= g_76), (safe_rshift_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u((((0x783CL && ((p_61 != 65530UL) , ((g_87 = ((((+((p_61 < 0UL) != g_335)) , 7UL) >= 0x52L) | p_61)) != l_396[1]))) && g_172) < p_61), p_61)), l_409)))) <= g_34[0]))) < g_98[1][3])))
        {
            int32_t l_427 = 1L;
            int32_t l_448 = (-3L);
            uint32_t l_451 = 8UL;
            int16_t l_460 = 0xFD2FL;
            int32_t l_484 = 7L;
            const int32_t l_722[4] = {0xC6DF56DFL,0xC6DF56DFL,0xC6DF56DFL,0xC6DF56DFL};
            uint32_t l_760 = 3UL;
            uint16_t l_772 = 0UL;
            int i;
            for (l_399 = 0; (l_399 > (-27)); l_399 = safe_sub_func_int8_t_s_s(l_399, 1))
            {
                uint32_t l_416 = 0x1A0C5217L;
                int32_t l_477 = 8L;
                int32_t l_521 = (-4L);
                int32_t l_542 = (-1L);

                g_472 = (safe_sub_func_int16_t_s_s(((safe_mod_func_int8_t_s_s((((safe_mod_func_uint32_t_u_u(((safe_add_func_int16_t_s_s((((l_416 ^ (l_460 , ((safe_mod_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(((p_61 | 65532UL) , p_61), 4)) <= (g_469 = ((safe_rshift_func_int16_t_s_s(p_61, 1)) , (g_204 = g_68)))), ((safe_sub_func_uint8_t_u_u(p_61, (0x02L >= g_275))) , 4L))), 0x42L)) | p_61))) & 246UL) == g_98[1][3]), 6L)) <= g_34[0]), p_61)) || l_416) ^ p_61), 250UL)) != l_448), 0x821AL));
                if (p_61)
                    break;

{
                int32_t l_1110 = 0xB35152B2L;
                uint8_t l_1157 = 8UL;
                int32_t l_1188 = 0xDE06F1DDL;


                j = (l_1026 | ((l_1110 = (safe_rshift_func_uint16_t_u_s(((safe_sub_func_int32_t_s_s((l_542 = (safe_lshift_func_uint16_t_u_s((0x76L == (g_6029 = (((safe_lshift_func_uint16_t_u_u(g_6029, 2)) | (safe_sub_func_uint32_t_u_u(((g_3600 <= g_6029) != g_34[0]), l_1471))) != g_3172))), 14))), (safe_mod_func_uint32_t_u_u(l_1157, g_6029)))) & l_1111[4]), g_6029))) >= 1L));

;


                    if ((((-1L) & j) != (l_427 , (-10L))))
                {
                    ;
                }
                else
                {
                    uint32_t l_1246 = 0xB470170CL;

                    for (g_5844 = 0; (g_5844 >= 0); g_5844 -= 1)
                    {
                        int i;
                        j = (((safe_lshift_func_uint16_t_u_u((l_334[g_5844] ^ ((safe_lshift_func_uint8_t_u_u((safe_div_func_int16_t_s_s(0x1A4BL, (l_334[(g_5844 + 2)] , (safe_sub_func_uint8_t_u_u((safe_div_func_int16_t_s_s((((g_68 == g_76) <= ((l_173[g_5844] = ((safe_lshift_func_uint16_t_u_u((+((g_6029 > ((safe_sub_func_uint8_t_u_u((+(safe_sub_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(g_98[0][4], g_6029)), (safe_unary_minus_func_int16_t_s((!(safe_sub_func_uint8_t_u_u((0xEFC2L | g_6029), 1UL))))))) , 0xDAL), l_334[(g_5844 + 2)]))), g_6029)) && 0x3DD3B09EL)) == g_34[0])), l_542)) , g_68)) != l_549)) , l_1246), g_6029)), 0x0FL))))), g_352)) != 0x62212923L)), g_6029)) > 1L) && g_496[2]);
                        if (g_6029)
                            {
{
                uint32_t l_831 = 1UL;
                int32_t l_841 = 0L;
                g_1369 = ((safe_add_func_int16_t_s_s((g_6771 && (safe_rshift_func_uint8_t_u_u((0x07L || g_6771), 7))), (safe_div_func_uint8_t_u_u((g_496[2] != 2UL), l_1539)))) < ((+l_831) , ((safe_add_func_int16_t_s_s((safe_sub_func_uint16_t_u_u(g_496[0], ((safe_mod_func_uint16_t_u_u((0x2D961B57L >= l_206), 0x0F8DL)) | 65535UL))), (-3L))) || 0xBFL)));
                for (g_154 = 0; (g_154 >= 0); g_154 -= 1)
                {
                    int i;
                    for (l_451 = 0; (l_451 <= 7); l_451 += 1)
                    {
                        int i;
                        return l_331[(g_154 + 1)];
                    }
                    g_5210[g_154] = (safe_lshift_func_uint8_t_u_s(l_331[(g_154 + 2)], (g_154 = 7L)));
                    l_841 = g_5210[g_154];
                    return l_206;
                }
            }

                    ;
{
        for (l_287 = 0; l_287 < 10; l_287++)
        {
            transparent_crc(g_2580[g_204][l_287], "g_2580[g_204][l_287]", g_2043);
            if (g_2043) printf("index = [%d][%d]\n", g_204, l_287);

        }
    }

                    ;}
                        l_173[g_5844] = (((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_s((safe_add_func_uint32_t_u_u((3L && 2L), (safe_lshift_func_int16_t_s_s(0xDBB3L, 12)))), g_6029)) | (g_6029 | ((safe_add_func_int32_t_s_s(((((safe_sub_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((g_98[0][3] != (0x4304L >= (safe_add_func_int16_t_s_s((safe_mod_func_uint8_t_u_u(l_1246, (safe_add_func_uint8_t_u_u((g_98[1][3] && l_399), g_6029)))), g_352)))), g_6029)) | 0x5FDCD7CFL), (-1L))) && l_1246) || 0L) ^ g_76), 0xE20BF935L)) == l_333[3][0][1]))) >= l_1056), g_6029)) | l_1157) != l_1471) || l_1471) < 0xF3566B6BL);
                    }
                    for (l_647 = 0; (l_647 != 49); l_647 = safe_add_func_uint16_t_u_u(l_647, 6))
                    {

for (i = 0; i < 10; i++)
        {
            transparent_crc(g_2580[g_240][i], "g_2580[g_240][i]", l_1471);
            if (l_1471) printf("index = [%d][%d]\n", g_240, i);

        };


                    g_5210[0] = 1L;
                        l_399 = g_34[0];
                    }
                }
            }

                    if ((safe_lshift_func_uint8_t_u_s(((safe_add_func_uint16_t_u_u((l_396[2] = (l_477 = (3UL || l_395))), ((0xEBL < (g_204 >= ((g_154 && (((l_485 = ((+(l_427 = g_34[0])) , (((safe_sub_func_int8_t_s_s((((p_61 > l_483) ^ 0xCFF8L) != g_34[0]), 251UL)) > l_484) || 0x6747L))) <= l_451) ^ p_61)) != 0xC7L))) != 0x66L))) >= 0x867767C0L), 4)))
                {
                    l_477 = l_416;
                }
                else
                {
                    int8_t l_507 = (-1L);
                    uint8_t l_541 = 0xD5L;
                    int32_t l_594 = 0x6BD8EFDEL;
                    l_447 = l_427;


                    l_542 = (safe_add_func_uint8_t_u_u((((((0x3CL <= p_61) <= ((2UL <= (safe_add_func_int32_t_s_s(((((((g_172 = (g_506 ^ l_521)) , (p_61 ^ l_460)) > (safe_lshift_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s((safe_sub_func_int16_t_s_s((g_335 = (((safe_rshift_func_int8_t_s_s(g_496[1], 3)) | (safe_add_func_uint8_t_u_u((safe_add_func_int8_t_s_s((g_204 < g_76), g_506)), 0xA3L))) >= l_507)), p_61)), l_541)) ^ (-1L)), 0))) , p_61) != 0x61L) && 0x7EL), l_94))) , l_593)) , g_98[1][3]) < l_594) || l_507), p_61));
                }
            }
            if ((safe_div_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u(0x0A28L, 12)), (safe_mod_func_uint32_t_u_u(g_352, (safe_add_func_uint16_t_u_u(((((p_61 | (((!g_35) | (safe_div_func_uint16_t_u_u((((8UL <= ((safe_add_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(0x56F078F2L, ((safe_unary_minus_func_int32_t_s((g_204 = (((((safe_div_func_uint32_t_u_u(4294967286UL, ((safe_rshift_func_int8_t_s_u(g_34[0], 0)) ^ (((p_61 || p_61) && 0x48L) < p_61)))) ^ g_9) , 1L) != p_61) != 4L)))) , l_451))), l_395)) & 0x0BB0L)) != l_395) && g_184), 1L))) != l_451)) > l_617) <= 0x2296L) || l_484), l_396[2])))))))
            {
                uint32_t l_620 = 0x7099546FL;
                int32_t l_621 = 0x68A61E69L;
                int32_t l_622 = 6L;
                int32_t l_626 = 3L;
                uint8_t l_646[4][9] = {{255UL,255UL,7UL,255UL,255UL,7UL,255UL,255UL,7UL},{255UL,255UL,7UL,255UL,255UL,7UL,255UL,255UL,7UL},{255UL,255UL,7UL,255UL,255UL,7UL,255UL,255UL,7UL},{255UL,255UL,7UL,255UL,255UL,7UL,255UL,255UL,7UL}};
                int32_t l_681 = 1L;
                int i, j;
                l_336 = p_61;

{
        for (l_136 = 0; l_136 < 5; l_136++)
        {
            transparent_crc(g_98[l_409][l_136], "g_98[l_409][l_136]", l_409);
            ;

        }
    }


                ;
lbl_682:
                for (l_593 = 0; (l_593 <= (-2)); l_593--)
                {
                    int16_t l_661 = 0x6BFEL;
                    int32_t l_680 = (-1L);
                    l_622 = ((((p_61 >= 0x5BL) , (l_427 = l_334[2])) & ((safe_div_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u((g_87 = (+(l_593 < ((safe_mod_func_uint8_t_u_u((l_399 = (safe_sub_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u(3UL, 5)), (((safe_mod_func_int32_t_s_s((g_472 > (((g_496[2] >= (safe_mod_func_uint16_t_u_u((((((254UL < (safe_sub_func_uint8_t_u_u(((l_646[1][2] = p_61) <= 251UL), l_485))) > g_76) | g_472) == l_448) || (-9L)), 7L))) > g_352) , g_240)), g_34[0])) > 0xAEL) > p_61)))), 0x53L)) < g_184)))), l_647)), p_61)) <= p_61)) || 0x7B78L);
                    l_399 = ((g_68 && (safe_mod_func_int8_t_s_s(((safe_unary_minus_func_int32_t_s(((((safe_sub_func_uint16_t_u_u((((((safe_rshift_func_int8_t_s_u((~(~(((l_451 || (l_549 , (l_620 && 0xB6E95DC3L))) > 0x5FL) != (0xFFDCFF3EL >= (p_61 < (safe_rshift_func_uint16_t_u_s((safe_div_func_uint16_t_u_u(((((0x2DL <= p_61) ^ 0UL) > p_61) && 0x78L), 65529UL)), 7))))))), g_496[1])) , p_61) | g_9) , g_469) , l_447), l_395)) >= 0x9BD8FBE6L) == l_646[1][8]) > l_396[2]))) , g_496[2]), g_496[0]))) , l_661);
                    for (l_460 = 6; (l_460 > 5); --l_460)
                    {
                        uint32_t l_666 = 4294967292UL;
                        int32_t l_677 = 0xC2919148L;
                        g_204 = (l_661 == (safe_lshift_func_int16_t_s_u((l_666 >= 0xCA1FA15DL), 10)));
                        l_136 = (l_448 = (~(!(l_661 <= (((0xBD3024CCL || (0x0624L == p_61)) <= 0UL) > (g_472 == (safe_add_func_int16_t_s_s(((l_680 = (((safe_mod_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((l_677 = 1UL), ((safe_div_func_uint8_t_u_u((p_61 < (l_666 || p_61)), 0x7AL)) > p_61))), 0xCE57L)) & 0xC6L) && 1L)) >= p_61), l_681))))))));
                    }
                }
                l_336 = (-5L);
            }
            else
            {
                int32_t l_692 = (-1L);
                int32_t l_769 = 0x4A00DB2CL;
                uint16_t l_807 = 65534UL;
                int32_t l_820 = (-2L);
                if (p_61)
                {
                    const uint8_t l_695 = 0xD4L;
                    int32_t l_746 = 0xE38C8ECEL;
                    for (l_483 = 0; (l_483 <= 0); l_483 += 1)
                    {
                        int i;
                        g_204 = (l_173[l_483] > (l_427 = ((safe_unary_minus_func_uint32_t_u(p_61)) >= (((1UL | (g_87 = (((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s(((g_98[1][3] = (0x149DL < (safe_rshift_func_uint8_t_u_s((safe_sub_func_uint8_t_u_u(p_61, l_692)), (safe_mod_func_int8_t_s_s(l_396[0], p_61)))))) , ((g_240 >= 3UL) >= g_87)), g_87)), 0x3945L)) == 2L) > p_61))) >= 0x5DB0L) | l_695))));
                        g_204 = g_9;
                        g_204 = (p_61 >= (((((l_331[l_483] = p_61) & (safe_lshift_func_int8_t_s_s(l_483, ((safe_div_func_uint8_t_u_u(((p_61 < 0x3922109CL) != g_496[2]), g_98[1][1])) | g_87)))) <= g_204) , 0xD4L) ^ p_61));

if (g_98[1][3])
                        ;;


if (g_3486) printf("index = [%d][%d]\n", g_2440, l_427);

                    l_399 = (((((l_173[l_483] = (safe_div_func_uint8_t_u_u(((-1L) | (((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s(g_98[2][0], (safe_mod_func_uint8_t_u_u((l_484 < ((0xC34BL < ((safe_div_func_uint8_t_u_u(((((0xAA01L & (safe_sub_func_int32_t_s_s(((((safe_rshift_func_int16_t_s_s(((safe_mod_func_int8_t_s_s((((-1L) <= (p_61 = l_173[l_483])) == (l_695 , (safe_lshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s((l_484 < 0xD6A0L), 4)), g_240)))), (-1L))) | l_448), 15)) || 0x7CL) >= 0x2F0C0610L) | 7UL), 0x548DC20CL))) , 1L) , p_61) > 0x90L), l_593)) >= l_692)) > 0xF8DF2C5EL)), l_448)))), l_695)) || (-1L)) <= 1UL)), l_397))) | l_722[3]) <= l_695) , 8UL) != l_692);
                    }


{
                uint32_t l_831 = 1UL;
                int32_t l_841 = 0L;

if (((-3L) >= g_3600))
                    {
                        l_399 = l_831;
                    }
                    else
                    {
                        return g_5210[0];
                    };


                    ;
                for (l_1203 = 0; (l_1203 >= 0); l_1203 -= 1)
                {
                    int i;

l_336 -= 1;


                    for (g_6771 = 0; (g_6771 <= 7); g_6771 += 1)
                    {
                        int i;

{
                        int16_t l_745 = 1L;
                        l_841 = (l_745 = ((safe_div_func_int16_t_s_s(((safe_rshift_func_int16_t_s_u(((l_287 = ((safe_add_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((g_472 , (safe_sub_func_int8_t_s_s((g_2043 = (l_1304 = (safe_sub_func_int16_t_s_s(((g_472 != (g_172 = (safe_div_func_int8_t_s_s(((0xC244L | ((!0x29L) & g_87)) , (-1L)), 0x04L)))) > (safe_unary_minus_func_uint32_t_u(((((l_722[3] > (g_472 > 0xE0097DD6L)) , g_275) , g_472) <= 0x1F65CFEAL)))), l_964)))), g_34[0]))) <= g_98[4][1]), l_807)), 1UL)) > 2UL)) <= l_395), 7)) ^ g_1370[2]), g_472)) , l_692));
                    }


if (l_396[0])
                            ;;

                    return l_331[(l_1203 + 1)];
                    }
                    l_787[l_1203] = (safe_lshift_func_uint8_t_u_s(l_331[(l_1203 + 2)], (g_3600 = 7L)));
                    l_841 = l_787[l_1203];
                    return g_2852;
                }
            }


if (l_336) printf("index = [%d]\n", l_692);

                    for (l_485 = 0; (l_485 != (-2)); l_485 = safe_sub_func_uint32_t_u_u(l_485, 1))
                    {
                        uint16_t l_786[7] = {1UL,1UL,65535UL,1UL,1UL,65535UL,1UL};
                        int i;
                        ;

if (l_399)
                    continue;

                    l_769 = l_485;
                        g_204 = ((l_772 >= (((((safe_unary_minus_func_uint32_t_u(((p_61 & ((safe_rshift_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(((safe_sub_func_int32_t_s_s((l_396[2] = g_34[0]), 0UL)) , (g_34[0] , ((((((safe_rshift_func_int16_t_s_u(((l_396[2] = (g_172 , l_746)) , (safe_rshift_func_int8_t_s_u((p_61 , (safe_rshift_func_uint16_t_u_s((g_172 = ((g_469 & 0x6FDFL) , 65535UL)), 4))), p_61))), p_61)) != l_786[6]) != p_61) > 0x095F09BEL) < l_786[3]) > 0x49L))), l_625)), 4)) && 1L)) | 0x4FL))) , l_331[5]) < p_61) || p_61) < 0UL)) <= 0x2CL);
                    }
                }
                else
                {
                    if (((-3L) >= g_154))
                    {
                        g_204 = l_483;
                    }
                    else
                    {
                        return l_787[0];
                    }
                }


{
                        int32_t l_1147 = 7L;
                        int32_t l_1156 = 0x3DF1483FL;
                        l_1147 = (g_1368 , ((g_34[0] , l_1147) < l_287));

if (i) printf("index = [%d][%d]\n", l_484, l_448);

                    ;
                        return g_469;
                    }

                    ;


                    ;

;


                    l_820 = ((((((safe_add_func_uint8_t_u_u(g_34[0], ((safe_lshift_func_uint8_t_u_u(p_61, 3)) | ((((safe_sub_func_uint8_t_u_u(((((((((safe_rshift_func_int16_t_s_s(((((l_769 = (safe_rshift_func_uint16_t_u_s(l_692, 9))) , p_61) > 0L) | ((((((0x62L ^ (l_448 = ((l_451 > (g_98[3][3] = (l_448 | (safe_div_func_uint16_t_u_u((l_427 = 0x967DL), g_506))))) <= g_87))) || l_807) == g_352) == g_76) != 1L) , g_352)), 2)) && 0x99FCL) && g_98[4][4]) > g_496[1]) | l_409) >= p_61) | p_61) , p_61), g_496[2])) || l_397) < g_154) , 0xA0DD0116L)))) <= (-1L)) > p_61) == 9L) && 0x1561L) != 0x38L);
            }
        }
        else
        {
            int8_t l_829 = 1L;
            for (g_172 = 0; (g_172 > 10); g_172++)
            {
                uint32_t l_831 = 1UL;
                int32_t l_841 = 0L;
                l_838 = ((safe_add_func_int16_t_s_s((g_68 && (safe_rshift_func_uint8_t_u_u((0x07L || g_352), 7))), (safe_div_func_uint8_t_u_u((g_496[2] != 2UL), l_829)))) < ((+l_831) , ((safe_add_func_int16_t_s_s((safe_sub_func_uint16_t_u_u(g_496[0], ((safe_mod_func_uint16_t_u_u((0x2D961B57L >= p_61), 0x0F8DL)) | 65535UL))), (-3L))) || 0xBFL)));

{
                    uint8_t l_5432 = 5UL;
                    ;
                }

                    for (l_625 = 0; (l_625 >= 0); l_625 -= 1)
                {
                    int i;

if (g_1345)
                            continue;

                    for (g_759 = 0; (g_759 <= 7); g_759 += 1)
                    {
                        int i;
                        return l_331[(l_625 + 1)];
                    }
                    ;
                    ;
                    return p_61;
                }
            }
        }
        if ((((((safe_rshift_func_int8_t_s_s(p_61, 5)) != (safe_div_func_int8_t_s_s((((((+((((((safe_lshift_func_int16_t_s_s((safe_div_func_int32_t_s_s(((safe_mod_func_uint32_t_u_u(g_35, p_61)) , ((g_87 = g_68) && p_61)), (p_61 , 0x36058B7BL))), (l_399 = (safe_rshift_func_uint16_t_u_s((l_447 = g_34[0]), (safe_add_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((safe_mod_func_int16_t_s_s(p_61, g_506)), 7)), l_861))))))) , 0x4118A9ADL) , g_172) ^ (-3L)) | l_391) || p_61)) && 0x62E942B4L) < g_240) , l_136) == (-9L)), p_61))) == g_184) && g_9) || 0x1ADAA88DL))
        {
            int32_t l_901 = 0x318CDFC0L;
            int32_t l_937 = (-9L);
            for (l_593 = 0; (l_593 <= 4); ++l_593)
            {
                const int8_t l_881 = 0xEDL;
                int32_t l_882 = 0x57CEB71EL;
                int32_t l_962[5][9][5] = {{{0x04993818L,0x1F12D1B3L,0x83DA8E60L,0L,0x83DA8E60L},{0x04993818L,0x04993818L,0xDD9BDD25L,0x783CF189L,2L},{1L,0x92FEEC02L,0x83DA8E60L,(-7L),2L},{0x92FEEC02L,0x1F12D1B3L,0x3ADE3604L,0x6D64A2DBL,0x83DA8E60L},{0x34A1D470L,0x92FEEC02L,0xDD9BDD25L,0x6D64A2DBL,0xE4C0BDBEL},{1L,0x04993818L,0x3CAC75C6L,6L,0xE80E69F2L},{0L,0xDD9BDD25L,0x3CAC75C6L,0x3EF6D47EL,(-5L)},{0x83DA8E60L,0L,(-1L),0x89A60667L,0xE80E69F2L},{0x4D112763L,0L,0x138E5C65L,6L,0xCA65903CL}},{{0x3ADE3604L,0xDD9BDD25L,(-5L),0x89A60667L,(-5L)},{0x3ADE3604L,0x3ADE3604L,(-1L),0x3EF6D47EL,4L},{0x4D112763L,0x83DA8E60L,(-5L),6L,4L},{0x83DA8E60L,0xDD9BDD25L,0x138E5C65L,0x628F1DA6L,(-5L)},{0L,0x83DA8E60L,(-1L),0x628F1DA6L,0xCA65903CL},{0x4D112763L,0x3ADE3604L,0x3CAC75C6L,6L,0xE80E69F2L},{0L,0xDD9BDD25L,0x3CAC75C6L,0x3EF6D47EL,(-5L)},{0x83DA8E60L,0L,(-1L),0x89A60667L,0xE80E69F2L},{0x4D112763L,0L,0x138E5C65L,6L,0xCA65903CL}},{{0x3ADE3604L,0xDD9BDD25L,(-5L),0x89A60667L,(-5L)},{0x3ADE3604L,0x3ADE3604L,(-1L),0x3EF6D47EL,4L},{0x4D112763L,0x83DA8E60L,(-5L),6L,4L},{0x83DA8E60L,0xDD9BDD25L,0x138E5C65L,0x628F1DA6L,(-5L)},{0L,0x83DA8E60L,(-1L),0x628F1DA6L,0xCA65903CL},{0x4D112763L,0x3ADE3604L,0x3CAC75C6L,6L,0xE80E69F2L},{0L,0xDD9BDD25L,0x3CAC75C6L,0x3EF6D47EL,(-5L)},{0x83DA8E60L,0L,(-1L),0x89A60667L,0xE80E69F2L},{0x4D112763L,0L,0x138E5C65L,6L,0xCA65903CL}},{{0x3ADE3604L,0xDD9BDD25L,(-5L),0x89A60667L,(-5L)},{0x3ADE3604L,0x3ADE3604L,(-1L),0x3EF6D47EL,4L},{0x4D112763L,0x83DA8E60L,(-5L),6L,4L},{0x83DA8E60L,0xDD9BDD25L,0x138E5C65L,0x628F1DA6L,(-5L)},{0L,0x83DA8E60L,(-1L),0x628F1DA6L,0xCA65903CL},{0x4D112763L,0x3ADE3604L,0x3CAC75C6L,6L,0xE80E69F2L},{0L,0xDD9BDD25L,0x3CAC75C6L,0x3EF6D47EL,(-5L)},{0x83DA8E60L,0L,(-1L),0x89A60667L,0xE80E69F2L},{0x4D112763L,0L,0x138E5C65L,6L,0xCA65903CL}},{{0x3ADE3604L,0xDD9BDD25L,(-5L),0x89A60667L,(-5L)},{0x3ADE3604L,0x3ADE3604L,(-1L),0x3EF6D47EL,4L},{0x4D112763L,0x83DA8E60L,(-5L),6L,4L},{0x83DA8E60L,0xDD9BDD25L,0x138E5C65L,0x628F1DA6L,(-5L)},{0L,0x83DA8E60L,(-1L),0x628F1DA6L,0xCA65903CL},{0x4D112763L,0x3ADE3604L,0x3CAC75C6L,6L,0xE80E69F2L},{0L,0xDD9BDD25L,0x3CAC75C6L,0x3EF6D47EL,(-5L)},{0x83DA8E60L,0L,1L,0xA3A1AEA2L,0x71DA6459L},{(-7L),0x3CAC75C6L,0x6D64A2DBL,0x34A1D470L,(-1L)}}};
                int i, j, k;


{
                        l_409 = (safe_sub_func_uint32_t_u_u(4294967288UL, g_87));
                    }

                    l_399 = ((g_76 = ((g_759 = (l_625 , l_334[1])) < (safe_lshift_func_int8_t_s_s(((p_61 == l_901) ^ (l_617 <= ((l_882 != (p_61 >= ((((safe_add_func_int16_t_s_s((safe_add_func_int32_t_s_s(((((safe_lshift_func_uint8_t_u_u((((((((((g_184 = ((~255UL) & (safe_div_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((((+(safe_rshift_func_int16_t_s_u(((l_136 = (safe_mod_func_int8_t_s_s(((l_962[2][1][1] = (safe_lshift_func_int16_t_s_s(((l_399 && g_87) > 0x79L), 15))) , l_838), p_61))) & g_68), 7))) & p_61) , l_332), 0xB69CL)), 3UL)))) & l_206) && p_61) >= p_61) , 255UL) < l_937) == g_496[2]) ^ p_61) <= (-1L)), 0)) >= p_61) || l_962[1][7][4]) | g_154), 0L)), (-4L))) && 0L) | g_506) > l_963))) != (-9L)))), 1)))) <= p_61);
            }
        }
        else
        {
            uint16_t l_975 = 0xC59EL;
            int32_t l_995 = 0x7DD91311L;
            int32_t l_998 = (-1L);
            int32_t l_1024 = 0xAA5C40A1L;
            uint32_t l_1048 = 0x7EFFCA07L;
            int16_t l_1104 = 0L;
            int8_t l_1182 = (-1L);
            uint32_t l_1470 = 0UL;
            int32_t l_1598 = 0x2AD0927FL;
            int32_t l_1622 = (-1L);
lbl_1005:
            l_964 = g_34[0];
            g_982 = ((p_61 = 255UL) < (l_965 > (g_98[4][4] >= (((safe_lshift_func_uint16_t_u_u((g_172 = 0x332EL), (((((safe_lshift_func_int16_t_s_s((g_76 , (safe_add_func_int16_t_s_s((((l_173[0] = (((g_204 = (safe_rshift_func_uint16_t_u_u(((l_409 || (((~((g_184 != (l_975 >= ((safe_sub_func_int16_t_s_s((safe_div_func_int32_t_s_s(((safe_div_func_uint8_t_u_u((l_331[5] && g_98[1][3]), l_975)) & l_333[8][0][0]), g_496[2])), g_98[3][4])) < g_335))) , l_975)) , g_34[0]) ^ 0xDFL)) && l_963), l_965))) >= (-9L)) <= g_34[0])) | g_76) && l_399), 0xC59EL))), l_332)) | g_275) > 65530UL) && l_975) || l_975))) | 0x0014L) == l_136))));
            if (((safe_mod_func_uint32_t_u_u(((0xD37FL & ((g_335 = (l_787[0] = g_506)) != p_61)) , ((safe_sub_func_uint8_t_u_u((safe_sub_func_int16_t_s_s(((safe_sub_func_int8_t_s_s(g_98[1][3], ((safe_mod_func_uint8_t_u_u((l_998 = ((safe_rshift_func_uint8_t_u_u(((l_447 = l_995) , ((((-7L) & (g_35 && g_184)) <= (safe_lshift_func_int16_t_s_s(g_335, 7))) != l_861)), 0)) < 0UL)), 0x18L)) ^ l_999))) || (-9L)), l_332)), p_61)) <= p_61)), p_61)) > l_1000))
            {
                uint32_t l_1025 = 0x77D646C6L;
                for (l_398 = 0; (l_398 <= 53); l_398++)
                {

if (l_136) printf("index = [%d]\n", l_1471);

                    for (p_61 = 0; (p_61 < 55); p_61++)
                    {

if (l_1104)
                            break;

                    if (g_573)
                            {
{
                    uint32_t l_1246 = 0xB470170CL;
                    for (l_1171 = 26; (l_1171 > 14); l_1171 = safe_sub_func_uint32_t_u_u(l_1171, 1))
                    {
                        int32_t l_1218[6];
                        int i;
                        for (i = 0; i < 6; i++)
                            l_1218[i] = 0x29984661L;
                        if (l_1218[0])
                            break;
                    }
                    for (g_35 = 0; (g_35 >= 0); g_35 -= 1)
                    {
                        int i;
                        l_332 = (((safe_lshift_func_uint16_t_u_u((l_334[g_35] ^ ((safe_lshift_func_uint8_t_u_u((safe_div_func_int16_t_s_s(0x1A4BL, (l_334[(g_35 + 2)] , (safe_sub_func_uint8_t_u_u((safe_div_func_int16_t_s_s((((g_352 == g_469) <= ((l_173[g_35] = ((safe_lshift_func_uint16_t_u_u((+((l_206 > ((safe_sub_func_uint8_t_u_u((+(safe_sub_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(g_98[0][4], l_206)), (safe_unary_minus_func_int16_t_s((!(safe_sub_func_uint8_t_u_u((0xEFC2L | l_206), 1UL))))))) , 0xDAL), l_334[(g_35 + 2)]))), l_206)) && 0x3DD3B09EL)) == g_34[0])), l_136)) , g_352)) != l_975)) , l_1246), l_206)), 0x0FL))))), l_398)) != 0x62212923L)), l_206)) > 1L) && g_496[2]);
                        if (l_206)
                            break;
                        l_173[g_35] = (((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_s((safe_add_func_uint32_t_u_u((3L && 2L), (safe_lshift_func_int16_t_s_s(0xDBB3L, 12)))), l_206)) | (g_3193 | ((safe_add_func_int32_t_s_s(((((safe_sub_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((g_98[0][3] != (0x4304L >= (safe_add_func_int16_t_s_s((safe_mod_func_uint8_t_u_u(l_1246, (safe_add_func_uint8_t_u_u((g_98[1][3] && l_1598), l_206)))), l_398)))), l_206)) | 0x5FDCD7CFL), (-1L))) && l_1246) || 0L) ^ l_1158), 0xE20BF935L)) == l_333[3][0][1]))) >= g_352), g_472)) | g_87) != l_995) || l_1471) < 0xF3566B6BL);
                    }
                    for (l_1171 = 0; (l_1171 != 49); l_1171 = safe_add_func_uint16_t_u_u(l_1171, 6))
                    {
                        l_173[0] = 1L;
                        l_1598 = g_34[0];
                    }
                }

                    ; }
{
                    int i;
                    for (g_759 = 0; (g_759 <= 7); g_759 += 1)
                    {
                        int i;
                        return l_331[(l_1000 + 1)];
                    }
                    l_787[l_1000] = (safe_lshift_func_uint8_t_u_s(l_331[(l_1000 + 2)], (g_3600 = 7L)));
                    k = l_787[l_1000];
                    return g_472;
                }

                    ;
                        return p_61;
                    }
                    return g_982;
                }
                if ((((safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_u(((((l_396[2] = (p_61 < ((safe_lshift_func_int8_t_s_s((g_34[0] <= (safe_add_func_uint32_t_u_u(l_965, (safe_add_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(((safe_add_func_int16_t_s_s(((g_275 = l_998) , ((safe_rshift_func_uint16_t_u_u((l_1024 = (p_61 <= (0L != ((((safe_mod_func_int16_t_s_s((g_759 && ((l_998 = p_61) == (p_61 == l_995))), p_61)) , l_963) >= 0xBD272950L) < (-5L))))), l_391)) , g_275)), l_1025)) & 0xBB13L), g_335)), 253UL))))), l_398)) != 0xB5CBL))) >= 0UL) <= l_1025) == l_1026), p_61)), 0)) && 0x2570L) , p_61))
                {
                    int32_t l_1047 = 1L;


{
                    uint8_t l_5436 = 0x0CL;
                    ;
                }

                    ;
                }
                else
                {
                    g_204 = l_1056;
                }

g_275 -= 1;



for (l_625 = 0; (l_625 <= 3); l_625 += 1)
                    {
                        int i, j;
                        g_3486 = (safe_mod_func_int32_t_s_s(((l_1622 = ((safe_div_func_int16_t_s_s(g_2580[j][j], l_1024)) || (safe_add_func_uint8_t_u_u((g_275 = (safe_add_func_uint16_t_u_u(l_1632, ((g_3172 , ((0x55D10309L == ((safe_div_func_int32_t_s_s((safe_div_func_int32_t_s_s((246UL < (((g_1369 < (!((((g_240 = ((65526UL & 0xCE64L) | (-10L))) ^ 0x6261DD20L) < 0x84L) & l_1622))) != 0x9048L) <= g_275)), g_2043)), l_1439)) <= g_5512)) , g_3463)) >= 0xE2C7L)))), 0x0EL)))) || 0xB02CL), 2UL));
                    }
{
        transparent_crc(g_1684[g_2440], "g_1684[g_2440]", g_573);
        if (g_573) printf("index = [%d]\n", g_2440);

    }

                    ;


                    g_204 = (l_1048 < ((safe_mod_func_uint8_t_u_u((((safe_sub_func_uint8_t_u_u(((l_396[2] = (safe_add_func_uint8_t_u_u((253UL < (1L || (p_61 < 255UL))), (safe_unary_minus_func_int8_t_s((safe_div_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u((((safe_rshift_func_int8_t_s_u((-1L), 2)) || ((l_136 = (((safe_rshift_func_int8_t_s_u((safe_rshift_func_int8_t_s_s(p_61, 2)), 7)) == ((safe_lshift_func_uint8_t_u_s((l_965 = (!(l_173[0] = (((g_982 >= (safe_mod_func_int8_t_s_s((((safe_rshift_func_int16_t_s_s(0xED2BL, g_184)) && g_172) < l_995), l_975))) ^ p_61) , 0UL)))), 3)) , 0xF77DB805L)) , 0xEB44L)) & p_61)) | (-7L)), 13)), 0xDEL))))))) >= g_9), 0x85L)) <= l_995) != p_61), l_995)) != p_61));
                l_787[0] = 0x3ADDF96AL;
            }
            else
            {
                int32_t l_1110 = 0xB35152B2L;
                uint8_t l_1157 = 8UL;
                int32_t l_1188 = 0xDE06F1DDL;

{

for (g_204 = 0; g_204 < 8; g_204++)
        {
{
                        int16_t l_5399[7] = {(-1L),0xDCE8L,(-1L),(-1L),0xDCE8L,(-1L),(-1L)};
                        int i;
                        g_1370[1] = (-5L);
                        l_5399[0] = (safe_add_func_uint16_t_u_u((g_3317 = 1UL), l_1104));
                    }

                    l_331[g_204] = (-1L);}

                    for (l_1188 = 0; l_1188 < 5; l_1188++)
        {

for (g_2043 = 0; (g_2043 > (-27)); g_2043 = safe_sub_func_int8_t_s_s(g_2043, 1))
            {
                uint32_t l_416 = 0x1A0C5217L;
                int32_t l_477 = 8L;
                int32_t l_521 = (-4L);
                int32_t l_542 = (-1L);
                if ((9L <= (l_336 < ((safe_rshift_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_u((l_416 ^ (l_333[5][1][0] < ((((safe_rshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u((1UL | (g_87 > ((((((safe_lshift_func_int16_t_s_u((l_416 >= (safe_add_func_int16_t_s_s(l_1245, ((safe_sub_func_uint8_t_u_u(g_34[0], l_1245)) == l_1598)))), g_87)) >= g_1370[2]) , g_1368) == (-1L)) , l_1598) , 9UL))), 0x43L)), l_398)) > 0x8B99E2F6L) > l_333[3][0][1]) | 0x7CL))), 6)) , l_549) && 0xD9703391L), 6)) , 0xCB6AL))))
                {
                    int32_t l_446[6][6] = {{0L,0x61F652B7L,0x7EE659F9L,0xA9C52775L,0xC8F3EE53L,0xC8F3EE53L},{0xA9C52775L,0xC8F3EE53L,0xC8F3EE53L,0xA9C52775L,0x7EE659F9L,0x61F652B7L},{0L,1L,0xEDF84B79L,0x61F652B7L,0L,0L},{0L,0x7EE659F9L,(-4L),0x7EE659F9L,0L,7L},{0L,1L,0x1EC9E225L,1L,0x7EE659F9L,0xEDF84B79L},{0xEDF84B79L,0xC8F3EE53L,1L,1L,0xC8F3EE53L,0xEDF84B79L}};
                    int i, j;
                    g_204 = (safe_div_func_int8_t_s_s(((safe_mod_func_int32_t_s_s(((safe_sub_func_int8_t_s_s((((1L && l_1024) >= (l_1471 = ((((l_1024 = g_2422) != 0xDA6FL) >= 0xCEL) < ((l_1598 = (l_331[5] & (safe_add_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((safe_add_func_int16_t_s_s((safe_div_func_int16_t_s_s((((l_1245 ^ (safe_div_func_uint16_t_u_u((g_4475 ^ ((safe_add_func_uint32_t_u_u((4294967295UL & i), l_336)) > g_87)), l_549))) & l_446[1][5]) < l_446[4][1]), i)), g_472)), 0xF47E2C16L)) < 0xBC35L), (-4L))))) && g_87)))) < 0xEEL), 255UL)) | 8UL), i)) ^ g_87), g_87));
                    g_184 = (safe_rshift_func_int16_t_s_u((-1L), 1));
                }
                else
                {
                    for (i = 5; (i >= 0); i -= 1)
                    {
                        int i;
                        return l_334[i];
                    }
                }
                g_87 = (safe_sub_func_int16_t_s_s(((safe_mod_func_int8_t_s_s((((safe_mod_func_uint32_t_u_u(((safe_add_func_int16_t_s_s((((l_416 ^ (g_35 , ((safe_mod_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(((g_87 | 65532UL) , g_87), 4)) <= (g_184 = ((safe_rshift_func_int16_t_s_s(g_87, 1)) , (i = l_398)))), ((safe_sub_func_uint8_t_u_u(g_87, (0x02L >= l_995))) , 4L))), 0x42L)) | g_87))) & 246UL) == g_98[1][3]), 6L)) <= g_34[0]), g_87)) || l_416) ^ g_87), 250UL)) != g_204), 0x821AL));

{
                        uint16_t l_786[7] = {1UL,1UL,65535UL,1UL,1UL,65535UL,1UL};
                        int i;
                        g_335 = g_3486;
                        l_995 = g_335;
                        l_136 = ((l_975 >= (((((safe_unary_minus_func_uint32_t_u(((l_1157 & ((safe_rshift_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(((safe_sub_func_int32_t_s_s((g_1370[2] = g_34[0]), 0UL)) , (g_34[0] , ((((((safe_rshift_func_int16_t_s_u(((g_1370[2] = (l_549 , j)) , (safe_rshift_func_int8_t_s_u((l_1157 , (safe_rshift_func_uint16_t_u_s((l_549 = ((l_1158 & 0x6FDFL) , 65535UL)), 4))), l_1157))), l_1157)) != l_786[6]) != l_1157) > 0x095F09BEL) < l_786[3]) > 0x49L))), g_3600)), 4)) && 1L)) | 0x4FL))) , l_331[5]) < l_1157) || l_1157) < 0UL)) <= 0x2CL);
                    }

                    if (g_87)
                    break;
                if ((safe_lshift_func_uint8_t_u_s(((safe_add_func_uint16_t_u_u((g_1370[2] = (l_477 = (3UL || g_2043))), ((0xEBL < (i >= ((g_4689 && (((g_6428 = ((+(l_1598 = g_34[0])) , (((safe_sub_func_int8_t_s_s((((g_87 > l_964) ^ 0xCFF8L) != g_34[0]), 251UL)) > l_136) || 0x6747L))) <= g_184) ^ g_87)) != 0xC7L))) != 0x66L))) >= 0x867767C0L), 4)))
                {
                    l_477 = l_416;
                }
                else
                {
                    int8_t l_507 = (-1L);
                    uint8_t l_541 = 0xD5L;
                    int32_t l_594 = 0x6BD8EFDEL;
                    l_1471 = l_1598;

{
                    for (l_1024 = 24; (l_1024 != 8); l_1024 = safe_sub_func_int8_t_s_s(l_1024, 7))
                    {
                        if (g_6029)
                            break;
                        l_1048 = g_1352;
                    }
                }

                    for (l_477 = 1; (l_477 <= 4); l_477 += 1)
                    {
                        int8_t l_505 = 3L;
                        int i, j;
                        if (l_965)
                            goto lbl_486;
                        i = (((g_98[l_477][l_477] ^ ((l_331[(l_477 + 2)] = (g_982 >= (g_87 < (l_334[1] , ((~(((safe_mod_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u(((safe_mod_func_int16_t_s_s((g_87 , g_87), g_496[2])) <= ((g_87 = ((safe_add_func_int8_t_s_s(((0x98L <= (((safe_rshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s(((safe_add_func_uint8_t_u_u(g_87, 0L)) , g_496[2]), g_87)), 14)) , 0xEF1872BAL) , l_505)) && l_1622), g_87)) | g_98[l_477][l_477])) <= g_87)), 6)), l_507)) , 1UL) < g_1370[2])) >= g_34[0]))))) || l_477)) , 249UL) & g_184);
                        i = (((g_35 <= (((safe_div_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((((safe_add_func_uint8_t_u_u(((g_87 != ((((((safe_unary_minus_func_int8_t_s((l_1024 < (safe_div_func_int16_t_s_s((((g_87 , 4294967295UL) , (safe_sub_func_int8_t_s_s(g_34[0], l_507))) > (g_87 != (g_98[l_477][l_477] = g_87))), g_472))))) , g_98[l_477][l_477]) , 0UL) != g_87) || i) < 4294967290UL)) == g_1368), 0xBBL)) == g_87) == g_87), l_521)), i)) && i) < (-10L))) != l_1622) >= i);
                        l_542 = (((g_87 < (safe_lshift_func_int8_t_s_u((((g_5210[0] = (((safe_rshift_func_uint8_t_u_u((safe_sub_func_int8_t_s_s(((~(l_998 = l_398)) ^ (safe_mod_func_int32_t_s_s(g_87, l_477))), (safe_add_func_uint16_t_u_u((!((l_416 , (!(g_4689 | (safe_mod_func_uint16_t_u_u(((i <= (g_87 != (safe_mod_func_int32_t_s_s(((safe_mod_func_int16_t_s_s((-1L), g_34[0])) | 0x92L), 4294967295UL)))) > g_87), g_982))))) == (-1L))), 0x8887L)))), i)) <= g_87) >= l_331[(l_477 + 2)])) == 0x67L) < l_541), g_184))) , g_87) | l_477);
                    }
                    for (g_1368 = 0; (g_1368 != 18); g_1368 = safe_add_func_uint8_t_u_u(g_1368, 4))
                    {
                        uint32_t l_572 = 0xC7D5EA36L;
                        int32_t l_576 = 0xC922E228L;
                        g_1370[0] = g_87;
                        l_542 = (safe_lshift_func_int16_t_s_u((safe_add_func_uint32_t_u_u(g_1599, (~0xC3L))), 12));
                        i = (l_136 , ((safe_rshift_func_int8_t_s_u(((safe_div_func_uint32_t_u_u(1UL, (safe_lshift_func_uint8_t_u_s((g_87 = (((safe_unary_minus_func_uint8_t_u((safe_rshift_func_int16_t_s_u((safe_rshift_func_uint8_t_u_s((g_2043 < g_87), (safe_sub_func_int16_t_s_s((((safe_lshift_func_int16_t_s_u(l_398, 9)) , (safe_add_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_lshift_func_int8_t_s_u((l_572 , (l_1110 >= (((g_87 < (safe_lshift_func_int16_t_s_u((0xD2672DD7L < g_35), 10))) >= g_2043) == l_1622))), 3)), g_87)), g_5844))) | 0x5067L), g_87)))), g_34[0])))) | 0x6831L) == 0xCB61BDDEL)), 7)))) < g_2043), 0)) || l_542));

if (l_485)
                            break;

                    l_576 = l_965;
                    }
                    l_542 = (safe_add_func_uint8_t_u_u((((((0x3CL <= g_87) <= ((2UL <= (safe_add_func_int32_t_s_s(((((((l_1245 = (l_1622 ^ l_521)) , (g_87 ^ g_35)) > (safe_lshift_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s((safe_sub_func_int16_t_s_s((g_5844 = (((safe_rshift_func_int8_t_s_s(g_496[1], 3)) | (safe_add_func_uint8_t_u_u((safe_add_func_int8_t_s_s((i < g_1368), l_1622)), 0xA3L))) >= l_507)), g_87)), l_541)) ^ (-1L)), 0))) , g_87) != 0x61L) && 0x7EL), l_549))) , g_4689)) , g_98[1][3]) < l_594) || l_507), g_87));
                }
            };


                    transparent_crc(g_98[l_1622][l_1188], "g_98[l_1622][l_1188]", i);
            if (i) printf("index = [%d][%d]\n", l_1622, l_1188);

        }
    }



                l_447 = (l_1026 | ((l_1110 = (safe_rshift_func_uint16_t_u_s(((safe_sub_func_int32_t_s_s((l_1024 = (safe_lshift_func_uint16_t_u_s((0x76L == (g_87 = (((safe_lshift_func_uint16_t_u_u(g_472, 2)) | (safe_sub_func_uint32_t_u_u(((g_154 <= p_61) != g_34[0]), g_240))) != l_593))), 14))), (safe_mod_func_uint32_t_u_u(l_1157, g_472)))) & l_1111[4]), p_61))) >= 1L));

{
                        l_1471 = (safe_sub_func_uint32_t_u_u(4294967288UL, l_861));
                    }

                    if ((((-1L) & g_204) != (l_965 , (-10L))))
                {


l_409 -= 1;



if (l_336) printf("index = [%d][%d][%d]\n", g_3486, g_2440, g_3486);

                    g_469 += 1;


                    l_399 = (9UL >= p_61);
                }
                else
                {
                    uint32_t l_1246 = 0xB470170CL;

g_68 += 1;


                    for (g_184 = 26; (g_184 > 14); g_184 = safe_sub_func_uint32_t_u_u(g_184, 1))
                    {
                        int32_t l_1218[6];
                        int i;
                        ;

{
                        uint32_t l_3124 = 0UL;
                        int32_t l_3125 = 0xC3763125L;
                        l_3124 = (l_964 != l_332);
                        ;
                    }

                    if (l_1218[0])
                            break;
                    }

{
                        int8_t l_5764 = 0xC3L;
                        l_787[0] = ((safe_unary_minus_func_int16_t_s((-1L))) == (((safe_rshift_func_int8_t_s_u(((l_1157 = (((k = ((p_61 = p_61) ^ ((safe_mod_func_int8_t_s_s(l_787[0], (safe_rshift_func_int16_t_s_u((l_1048 ^ (safe_add_func_uint16_t_u_u((safe_mod_func_int32_t_s_s(4L, (g_5512 , g_1798[5][2]))), ((-1L) | (safe_lshift_func_uint16_t_u_s(((l_964 = (l_1188 <= l_485)) <= g_1369), g_5512)))))), g_5512)))) <= g_240))) , l_1110) ^ g_5512)) & g_5512), l_5764)) != 0xC85B220FL) & l_5764));
                    }

                    for (l_1104 = 0; (l_1104 >= 0); l_1104 -= 1)
                    {
                        int i;

{
                    return g_4475;
                }

                    g_204 = (((safe_lshift_func_uint16_t_u_u((l_334[l_1104] ^ ((safe_lshift_func_uint8_t_u_u((safe_div_func_int16_t_s_s(0x1A4BL, (l_334[(l_1104 + 2)] , (safe_sub_func_uint8_t_u_u((safe_div_func_int16_t_s_s((((g_68 == g_469) <= ((l_787[l_1104] = ((safe_lshift_func_uint16_t_u_u((+((p_61 > ((safe_sub_func_uint8_t_u_u((+(safe_sub_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(g_98[0][4], p_61)), (safe_unary_minus_func_int16_t_s((!(safe_sub_func_uint8_t_u_u((0xEFC2L | p_61), 1UL))))))) , 0xDAL), l_334[(l_1104 + 2)]))), p_61)) && 0x3DD3B09EL)) == g_34[0])), l_336)) , g_68)) != l_1245)) , l_1246), p_61)), 0x0FL))))), g_982)) != 0x62212923L)), p_61)) > 1L) && g_496[2]);
                        if (p_61)
                            ;;
                        l_787[l_1104] = (((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_s((safe_add_func_uint32_t_u_u((3L && 2L), (safe_lshift_func_int16_t_s_s(0xDBB3L, 12)))), p_61)) | (g_87 | ((safe_add_func_int32_t_s_s(((((safe_sub_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((g_98[0][3] != (0x4304L >= (safe_add_func_int16_t_s_s((safe_mod_func_uint8_t_u_u(l_1246, (safe_add_func_uint8_t_u_u((g_98[1][3] && l_998), p_61)))), g_982)))), p_61)) | 0x5FDCD7CFL), (-1L))) && l_1246) || 0L) ^ l_1179), 0xE20BF935L)) == l_333[3][0][1]))) >= g_1138), g_472)) | l_1157) != l_409) || g_240) < 0xF3566B6BL);
                    }
                    for (l_1158 = 0; (l_1158 != 49); l_1158 = safe_add_func_uint16_t_u_u(l_1158, 6))
                    {
                        l_173[0] = 1L;

{
                int32_t l_1591 = (-1L);
                int32_t l_1600 = 1L;
                int32_t l_1601 = 1L;
                g_2440 = ((g_3600 = (safe_sub_func_int16_t_s_s((g_1352 = (g_1370[2] <= (((safe_add_func_uint32_t_u_u(g_2440, (safe_add_func_uint32_t_u_u(0xE333C790L, g_1599)))) && (-1L)) ^ ((((((((((l_1601 = (safe_rshift_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(l_1591, ((((safe_rshift_func_int8_t_s_u(((((safe_lshift_func_int16_t_s_u((l_1600 = ((l_94 = (250UL < (((g_275 = (safe_div_func_int16_t_s_s(((g_2440 = ((l_1111[2] <= (((l_398 == g_1288) >= g_204) , g_1288)) <= 255UL)) || 0x3F45E452L), l_1591))) < g_1369) | g_204))) && 4294967295UL)), 8)) > 0x729CL) || 0x30L) | 0xDEL), 4)) ^ 0xD746L) >= 0xEDL) ^ g_1369))), l_1171))) & l_1591) , (-10L)) && l_1158) >= g_1369) , g_5225) >= g_1369) == 0x9CDFL) == 0x4D91L) <= 0UL)))), g_1369))) < 0x1AL);
                if (g_204)
                {
                    int32_t l_1621 = (-1L);
                    uint16_t l_1633[4][7];
                    uint32_t l_1661 = 9UL;
                    int i, j;

g_472 += 1;


                    for (i = 0; i < 4; i++)
                    {
                        for (j = 0; j < 7; j++)
                            ;;
                    }

{
                    uint8_t l_5432 = 5UL;

for (l_398 = 1; (l_398 <= 4); l_398 += 1)
                {
                    return g_87;
                };


                    if (l_5432)
                        ;;
                }

                    if ((g_469 | (safe_div_func_uint16_t_u_u((safe_div_func_uint8_t_u_u((g_2852 = 0x6AL), g_1288)), ((-1L) | ((((safe_unary_minus_func_int16_t_s(((8UL && (safe_add_func_int32_t_s_s((l_1600 = (safe_div_func_uint8_t_u_u(g_1369, (safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((g_352 >= l_1026), 1)), ((safe_add_func_int32_t_s_s(((safe_unary_minus_func_uint16_t_u(((((((safe_lshift_func_int8_t_s_u(((((safe_unary_minus_func_uint8_t_u(g_1369)) != g_1599) < g_1369) && g_1369), g_1599)) == (-1L)) | 0L) , g_469) != l_1621) == g_469))) && l_1621), g_2440)) <= l_1026)))))), 1L))) >= g_496[1]))) && g_98[1][3]) < (-7L)) || (-1L)))))))
                    {
                        int32_t l_1631 = 5L;
                        g_1370[2] = ((65535UL <= ((safe_div_func_int16_t_s_s((((l_1622 = ((g_496[2] == ((g_2440 = g_1369) , ((g_496[1] & (g_2852 = ((((safe_lshift_func_uint8_t_u_u((safe_mod_func_int16_t_s_s((5L ^ 0x26CA033CL), (g_98[2][1] = ((safe_rshift_func_int8_t_s_u(g_34[0], 1)) , 0x63DAL)))), g_1369)) <= 0x5A15L) <= l_1631) && g_1599))) == 1UL))) == g_1369)) >= g_1369) , 1L), g_352)) > g_506)) > l_1633[3][5]);
                        g_2440 = 0L;
                    }
                    else
                    {
                        uint16_t l_1650 = 0x14C2L;
                        int32_t l_1651 = (-10L);
                        int32_t l_1662 = (-1L);
                        g_1370[2] = (safe_add_func_int32_t_s_s((safe_div_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(((safe_add_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u(249UL, g_2852)) ^ (g_2440 = ((safe_lshift_func_int16_t_s_u((((safe_sub_func_int16_t_s_s((((g_3463 , g_352) & (safe_rshift_func_uint8_t_u_s(l_1600, ((-8L) > 0x12L)))) != ((l_1650 = ((g_1369 = 1UL) ^ g_1288)) ^ g_1368)), l_333[4][0][2])) >= 0x2D2FL) | l_1633[2][0]), 13)) , (-1L)))), 0x60L)) ^ g_98[1][3]), 12)), g_2440)), l_1651));
                        l_1662 = (((4294967293UL || ((safe_mod_func_int16_t_s_s(((~(g_2852 != ((0xD212L | ((g_3463 && ((safe_rshift_func_int8_t_s_u(((l_1651 = (((((safe_lshift_func_int8_t_s_s((g_1369 , (1L || (safe_div_func_int16_t_s_s(1L, (l_1182 && 0x28L))))), 5)) < 7L) && g_4475) , 0x299164C5L) > g_1369)) || 250UL), g_1368)) > l_1661)) >= g_204)) | g_1370[0]))) , g_1288), l_1600)) <= g_2852)) > g_1288) >= g_2440);
                    }

;


                    g_1370[2] = g_1369;
                }
                else
                {
                    int32_t l_1682 = (-4L);

if ((((-1L) & l_1600) != (l_447 , (-10L))))
                {
                    ;
                }
                else
                {
                    uint32_t l_1246 = 0xB470170CL;
                    for (l_483 = 26; (l_483 > 14); l_483 = safe_sub_func_uint32_t_u_u(l_483, 1))
                    {
                        int32_t l_1218[6];
                        int i;
                        for (i = 0; i < 6; i++)
                            ;;
                        if (l_1218[0])
                            {

{
        uint16_t l_100[1];
        int32_t l_162 = 1L;
        uint32_t l_187[9];
        int32_t l_219 = 0xFFE616ADL;
        int32_t l_251 = 0x539E8B65L;
        int i;
        for (i = 0; i < 1; i++)
            l_100[i] = 0x62BAL;
        for (i = 0; i < 9; i++)
            l_187[i] = 6UL;
        for (l_1439 = 1; (l_1439 <= 56); l_1439 = safe_add_func_int32_t_s_s(l_1439, 3))
        {
            int32_t l_97[2];
            int32_t l_159 = (-1L);
            int8_t l_203 = 0xFFL;
            int i;
            for (i = 0; i < 2; i++)
                l_97[i] = 1L;
            g_98[1][3] = (g_34[0] <= l_97[0]);
            for (l_1439 = 0; (l_1439 <= 4); l_1439 += 1)
            {
                int32_t l_99 = 0x22F50FADL;
                uint32_t l_122[6][1][10] = {{{4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL}},{{4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL}},{{4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL}},{{4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL}},{{4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL}},{{4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL,4294967289UL}}};
                int32_t l_165 = 0xA5772CECL;
                int i, j, k;
                if (l_99)
                    break;
                for (g_982 = 1; (g_982 <= 4); g_982 += 1)
                {
                    if (l_100[0])
                        break;
                }
                for (g_982 = 1; (g_982 <= 4); g_982 += 1)
                {
                    return l_1439;
                }
                for (l_1179 = 0; (l_1179 <= 4); l_1179 += 1)
                {
                    int32_t l_123 = (-5L);
                    int32_t l_160 = 0L;
                    int32_t l_207[2];
                    int i, j;
                    for (i = 0; i < 2; i++)
                        l_207[i] = 0x2DF446B0L;
                    l_123 = (((safe_rshift_func_uint8_t_u_u(l_1439, (safe_rshift_func_int16_t_s_s((0xA3L | (safe_mod_func_uint8_t_u_u((((l_97[1] > ((((((safe_sub_func_int8_t_s_s(((~((((g_98[l_1439][l_1179] = ((safe_lshift_func_int16_t_s_s(((((safe_add_func_int8_t_s_s((safe_div_func_uint16_t_u_u(((+0L) < ((safe_unary_minus_func_int8_t_s((((safe_rshift_func_int8_t_s_u(l_97[0], (safe_sub_func_int8_t_s_s(0xA0L, l_122[1][0][7])))) , (g_98[1][3] ^ l_122[1][0][7])) , 0L))) != l_1104)), l_1104)), g_982)) , l_97[1]) & l_99) == 0L), 0)) == l_1439)) | l_97[0]) , l_100[0]) != l_1439)) < 0xD733C455L), l_99)) > l_1439) != l_1439) > l_1439) && l_1439) || l_975)) & l_1439) <= g_34[0]), l_100[0]))), 4)))) == 0x38L) , l_97[0]);
                    if ((safe_rshift_func_int8_t_s_s((l_1439 && (safe_rshift_func_uint8_t_u_s((safe_add_func_int32_t_s_s((l_97[0] ^ (-1L)), (((safe_lshift_func_uint8_t_u_s((((l_123 = ((((safe_add_func_uint32_t_u_u(((1UL <= ((g_34[0] < (l_975 ^ (((l_447 = (-6L)) & (((((l_1104 ^ (safe_rshift_func_uint8_t_u_s(255UL, l_100[0]))) < g_34[0]) , l_122[1][0][7]) , l_99) < 0xF14D92DBL)) > 0x1CF4EE93L))) && l_97[0])) && 0xED5AL), l_1104)) < g_98[l_1439][l_1179]) ^ l_975) , l_1439)) != l_100[0]) , l_122[3][0][4]), l_1439)) & l_1439) || l_122[2][0][8]))), 2))), g_34[0])))
                    {
                        int8_t l_161[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_161[i] = 0x38L;
                        l_162 = ((!((l_160 = (((safe_sub_func_uint16_t_u_u(0x6505L, (((safe_div_func_int32_t_s_s((((safe_lshift_func_int8_t_s_u((4UL ^ ((safe_div_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u((l_159 = ((safe_add_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s((l_1539 = 0x41L), ((g_98[1][1] ^ l_122[1][0][7]) || ((l_123 = ((l_99 || (l_97[0] >= (safe_mod_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(g_34[0], l_100[0])), l_97[1])))) , g_98[l_1439][l_1179])) < g_34[0])))), 0x70005B71L)) ^ l_122[4][0][6])), l_1439)), 0x4D08L)) && 0x43L)), l_1104)) ^ (-4L)) ^ l_1439), g_982)) && l_1439) > 0xC2L))) , g_98[1][3]) || 4UL)) | 65529UL)) || l_161[2]);
                        l_447 = l_1439;
                        g_5210[0] = (l_447 = ((safe_add_func_uint8_t_u_u(((l_1439 <= (l_165 = l_1439)) >= (l_161[2] , (safe_sub_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((safe_rshift_func_int16_t_s_s((l_1439 ^ ((l_975 = (-6L)) <= 0xB43D5122L)), 7)) > (l_1439 , l_100[0])) | l_1439), 0x19FDL)), 248UL)))), g_98[4][4])) & 0xDFL));
                        l_159 = (safe_sub_func_uint8_t_u_u(((((safe_add_func_uint16_t_u_u(g_98[1][3], l_1439)) <= (safe_rshift_func_int8_t_s_u(((safe_rshift_func_int16_t_s_u((1UL || (-8L)), 12)) , (((safe_sub_func_int16_t_s_s((l_1470 = l_122[3][0][4]), (safe_mod_func_uint16_t_u_u(((l_1439 , ((-1L) || l_1439)) && ((((l_162 = (l_187[1] || 0x96F3BD68L)) < l_1439) >= g_982) , l_1439)), l_1439)))) > l_165) < 0xA7L)), l_165))) ^ l_975) && l_161[2]), l_1439));
                    }
                    else
                    {
                        int32_t l_205 = 0xF8352AC2L;
                        if (l_160)
                            break;
                        l_207[0] = (((safe_lshift_func_uint16_t_u_s(((safe_div_func_uint32_t_u_u((((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s(((l_165 = ((((safe_rshift_func_uint8_t_u_s((l_1439 || ((l_1591 = (g_34[0] , (((((((g_98[l_1439][l_1179] | ((l_1439 & (l_1439 || ((((+l_1439) ^ (1UL > ((l_123 = (l_160 = ((safe_add_func_uint16_t_u_u((l_1439 != ((0x1D65L != l_1470) <= l_97[1])), 1UL)) == g_34[0]))) && 0x58DFD47EL))) , l_160) , g_982))) & l_99)) == g_982) , l_975) < l_1470) <= l_1104) || g_34[0]) <= l_203))) , l_1439)), l_1439)) , l_205) & l_205) <= 0x8DL)) , l_1439), 0)), l_975)) >= l_1470) || (-1L)), l_1157)) < 0UL), 9)) , g_34[0]) == l_1439);
                    }
                    return g_5210[0];
                }
            }
        }
        for (l_1439 = 0; (l_1439 < 57); l_1439 = safe_add_func_int16_t_s_s(l_1439, 5))
        {
            int32_t l_220[5];
            int i;
            for (i = 0; i < 5; i++)
                l_220[i] = 0x9DECBAA9L;
            if ((safe_add_func_uint16_t_u_u(0xF50EL, (l_1439 , ((((((safe_add_func_uint8_t_u_u(((l_100[0] || 0x3F7DL) , (!(0x56L & l_1439))), (l_162 = g_5210[0]))) && (safe_sub_func_int32_t_s_s(((safe_add_func_int32_t_s_s(((((9UL || (l_1591 != 6UL)) != l_219) , g_34[0]) , 1L), l_1439)) == l_1179), l_1539))) , l_1591) && 0x4CDFC208L) >= l_220[1]) < 0x6383L)))))
            {
                l_1591 = (safe_rshift_func_uint16_t_u_s(g_34[0], 3));
            }
            else
            {
                uint16_t l_232 = 0UL;
                int32_t l_249[1];
                int32_t l_250 = 0x43E91BF3L;
                int i;
                for (i = 0; i < 1; i++)
                    l_249[i] = (-10L);
                l_162 = ((safe_div_func_int16_t_s_s(((safe_lshift_func_int16_t_s_u((safe_unary_minus_func_int32_t_s(((safe_add_func_int32_t_s_s((l_447 = (safe_lshift_func_uint8_t_u_s(((l_232 = 0x63AE6E0BL) > 0xC106F47BL), 6))), ((safe_lshift_func_uint8_t_u_u((1UL < (+((((((safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((l_1539 = (l_1539 >= l_1539)), 7)), ((g_98[1][3] = ((g_5210[0] == ((((l_447 = l_1439) > ((((safe_sub_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_s(((safe_div_func_uint8_t_u_u(1UL, (((((l_249[0] = (((((((((safe_add_func_uint8_t_u_u(((((((l_249[0] && 1L) , g_982) > 65535UL) <= g_34[0]) , l_1439) | 0UL), 253UL)) & l_1439) ^ l_249[0]) != l_1439) ^ l_1439) <= l_249[0]) > l_100[0]) > 0xFBL) >= 0x3450L)) , l_1104) , l_1179) <= g_982) && 0x9C7174ADL))) , l_1591), l_219)) & l_187[1]), 0x7DF49458L)) > g_5210[0]) & g_34[0]) || (-1L))) <= l_250) != l_1439)) == g_34[0])) < 0x4690L))) >= l_251) || l_975) && l_1439) < (-1L)) ^ l_1439))), 0)) < (-5L)))) && l_1439))), l_1439)) | l_1439), l_1470)) < l_1439);
            }
            if (g_98[1][3])
                break;
            l_220[4] = (safe_rshift_func_uint16_t_u_s((safe_add_func_uint8_t_u_u((safe_add_func_uint16_t_u_u(l_220[1], 0x30AAL)), 0x0BL)), 14));
        }
    }

                    for (l_287 = 0; l_287 < 7; l_287++)
    {
        transparent_crc(g_13[l_287], "g_13[l_287]", l_1591);
        if (l_1591) {
{
        transparent_crc(g_496[l_1471], "g_496[l_1471]", l_399);
        if (l_399) printf("index = [%d]\n", l_1471);

    }

                    printf("index = [%d]\n", l_287);}

    };


                    break;}
                    }
                    for (l_768 = 0; (l_768 >= 0); l_768 -= 1)
                    {
                        int i;
                        l_1600 = (((safe_lshift_func_uint16_t_u_u((l_334[l_768] ^ ((safe_lshift_func_uint8_t_u_u((safe_div_func_int16_t_s_s(0x1A4BL, (l_334[(l_768 + 2)] , (safe_sub_func_uint8_t_u_u((safe_div_func_int16_t_s_s((((g_1138 == l_1158) <= ((l_787[l_768] = ((safe_lshift_func_uint16_t_u_u((+((l_206 > ((safe_sub_func_uint8_t_u_u((+(safe_sub_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(g_98[0][4], l_206)), (safe_unary_minus_func_int16_t_s((!(safe_sub_func_uint8_t_u_u((0xEFC2L | l_206), 1UL))))))) , 0xDAL), l_334[(l_768 + 2)]))), l_206)) && 0x3DD3B09EL)) == g_34[0])), l_1682)) , g_1138)) != g_1599)) , l_1246), l_206)), 0x0FL))))), g_1138)) != 0x62212923L)), l_206)) > 1L) && g_496[2]);
                        ;
                        l_787[l_768] = (((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_s((safe_add_func_uint32_t_u_u((3L && 2L), (safe_lshift_func_int16_t_s_s(0xDBB3L, 12)))), l_206)) | (l_206 | ((safe_add_func_int32_t_s_s(((((safe_sub_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((g_98[0][3] != (0x4304L >= (safe_add_func_int16_t_s_s((safe_mod_func_uint8_t_u_u(l_1246, (safe_add_func_uint8_t_u_u((g_98[1][3] && k), l_206)))), g_1138)))), l_206)) | 0x5FDCD7CFL), (-1L))) && l_1246) || 0L) ^ l_1158), 0xE20BF935L)) == l_333[3][0][1]))) >= l_963), g_9)) | g_3193) != l_336) || l_1682) < 0xF3566B6BL);
                    }
                    for (g_1345 = 0; (g_1345 != 49); g_1345 = safe_add_func_uint16_t_u_u(g_1345, 6))
                    {
                        l_173[0] = 1L;
                        k = g_34[0];
                    }
                }
{
                        int32_t l_2330 = 0xB0B48C1AL;
                        l_1622 = (safe_rshift_func_int16_t_s_s(6L, l_2330));
                        l_998 = g_897;
                    }

                    ;



                }
            }

                    l_998 = g_34[0];
                    }
                }
            }

{
                    int32_t l_446[6][6] = {{0L,0x61F652B7L,0x7EE659F9L,0xA9C52775L,0xC8F3EE53L,0xC8F3EE53L},{0xA9C52775L,0xC8F3EE53L,0xC8F3EE53L,0xA9C52775L,0x7EE659F9L,0x61F652B7L},{0L,1L,0xEDF84B79L,0x61F652B7L,0L,0L},{0L,0x7EE659F9L,(-4L),0x7EE659F9L,0L,7L},{0L,1L,0x1EC9E225L,1L,0x7EE659F9L,0xEDF84B79L},{0xEDF84B79L,0xC8F3EE53L,1L,1L,0xC8F3EE53L,0xEDF84B79L}};
                    int i, j;
                    i = (safe_div_func_int8_t_s_s(((safe_mod_func_int32_t_s_s(((safe_sub_func_int8_t_s_s((((1L && g_3486) >= (l_395 = ((((l_395 = l_999) != 0xDA6FL) >= 0xCEL) < ((l_1024 = (l_331[5] & (safe_add_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((safe_add_func_int16_t_s_s((safe_div_func_int16_t_s_s((((l_1632 ^ (safe_div_func_uint16_t_u_u((g_1369 ^ ((safe_add_func_uint32_t_u_u((4294967295UL & g_204), g_506)) > g_1369)), g_1599))) & l_446[1][5]) < l_446[4][1]), g_204)), g_9)), 0xF47E2C16L)) < 0xBC35L), (-4L))))) && g_1369)))) < 0xEEL), 255UL)) | 8UL), j)) ^ g_1369), g_1369));
                    ;
                }


        }
    }

if (l_332) printf("index = [%d][%d]\n", g_573, k);

                    return g_68;
}





int main (int argc, char* argv[])
{
    int i, j, k;
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
    transparent_crc(g_9, "g_9", print_hash_value);
    for (i = 0; i < 7; i++)
    {
        transparent_crc(g_13[i], "g_13[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_34[i], "g_34[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_35, "g_35", print_hash_value);
    transparent_crc(g_68, "g_68", print_hash_value);
    transparent_crc(g_76, "g_76", print_hash_value);
    transparent_crc(g_87, "g_87", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            transparent_crc(g_98[i][j], "g_98[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_154, "g_154", print_hash_value);
    transparent_crc(g_172, "g_172", print_hash_value);
    transparent_crc(g_184, "g_184", print_hash_value);
    transparent_crc(g_204, "g_204", print_hash_value);
    transparent_crc(g_240, "g_240", print_hash_value);
    transparent_crc(g_275, "g_275", print_hash_value);
    transparent_crc(g_335, "g_335", print_hash_value);
    transparent_crc(g_352, "g_352", print_hash_value);
    transparent_crc(g_469, "g_469", print_hash_value);
    transparent_crc(g_472, "g_472", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        transparent_crc(g_496[i], "g_496[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_506, "g_506", print_hash_value);
    transparent_crc(g_573, "g_573", print_hash_value);
    transparent_crc(g_759, "g_759", print_hash_value);
    transparent_crc(g_897, "g_897", print_hash_value);
    transparent_crc(g_982, "g_982", print_hash_value);
    transparent_crc(g_1138, "g_1138", print_hash_value);
    transparent_crc(g_1288, "g_1288", print_hash_value);
    transparent_crc(g_1345, "g_1345", print_hash_value);
    transparent_crc(g_1352, "g_1352", print_hash_value);
    transparent_crc(g_1368, "g_1368", print_hash_value);
    transparent_crc(g_1369, "g_1369", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_1370[i], "g_1370[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_1599, "g_1599", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_1684[i], "g_1684[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 8; j++)
        {
            transparent_crc(g_1798[i][j], "g_1798[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_2043, "g_2043", print_hash_value);
    transparent_crc(g_2422, "g_2422", print_hash_value);
    transparent_crc(g_2440, "g_2440", print_hash_value);
    transparent_crc(g_2467, "g_2467", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 10; j++)
        {
            transparent_crc(g_2580[i][j], "g_2580[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_2852, "g_2852", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 9; j++)
        {
            for (k = 0; k < 7; k++)
            {
                transparent_crc(g_2853[i][j][k], "g_2853[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_3109[i], "g_3109[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_3172, "g_3172", print_hash_value);
    transparent_crc(g_3193, "g_3193", print_hash_value);
    transparent_crc(g_3317, "g_3317", print_hash_value);
    transparent_crc(g_3463, "g_3463", print_hash_value);
    transparent_crc(g_3486, "g_3486", print_hash_value);
    transparent_crc(g_3600, "g_3600", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 5; j++)
        {
            transparent_crc(g_3935[i][j], "g_3935[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 7; i++)
    {
        transparent_crc(g_4423[i], "g_4423[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_4475, "g_4475", print_hash_value);
    transparent_crc(g_4689, "g_4689", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_5210[i], "g_5210[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_5225, "g_5225", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_5446[i], "g_5446[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_5512, "g_5512", print_hash_value);
    transparent_crc(g_5844, "g_5844", print_hash_value);
    transparent_crc(g_6029, "g_6029", print_hash_value);
    transparent_crc(g_6428, "g_6428", print_hash_value);
    transparent_crc(g_6771, "g_6771", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

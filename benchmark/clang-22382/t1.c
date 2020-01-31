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


    (si==(-9223372036854775807L -1)) ?
    ((si)) :


    -si;
}

static int64_t
(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return


    (((si1>0) && (si2>0) && (si1 > ((9223372036854775807L)-si2))) || ((si1<0) && (si2<0) && (si1 < ((-9223372036854775807L -1)-si2)))) ?
    ((si1)) :


    (si1 + si2);
}

static int64_t
(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return


    (((si1^si2) & (((si1 ^ ((si1^si2) & (~(9223372036854775807L))))-si2)^si2)) < 0) ?
    ((si1)) :


    (si1 - si2);
}

static int64_t
(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return


    (((si1 > 0) && (si2 > 0) && (si1 > ((9223372036854775807L) / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < ((-9223372036854775807L -1) / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < ((-9223372036854775807L -1) / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((9223372036854775807L) / si1)))) ?
    ((si1)) :


    si1 * si2;
}

static int64_t
(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return

    ((si2 == 0) || ((si1 == (-9223372036854775807L -1)) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 % si2);
}

static int64_t
(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{

  return

    ((si2 == 0) || ((si1 == (-9223372036854775807L -1)) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 / si2);
}

static int64_t
(safe_lshift_func_int64_t_s_s)(int64_t left, int right )
{

  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > ((9223372036854775807L) >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static int64_t
(safe_lshift_func_int64_t_s_u)(int64_t left, unsigned int right )
{

  return

    ((left < 0) || (((unsigned int)right) >= 32) || (left > ((9223372036854775807L) >> ((unsigned int)right)))) ?
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

    ((((int)right) < 0) || (((int)right) >= 32) || (left > ((18446744073709551615UL) >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static uint64_t
(safe_lshift_func_uint64_t_u_u)(uint64_t left, unsigned int right )
{

  return

    ((((unsigned int)right) >= 32) || (left > ((18446744073709551615UL) >> ((unsigned int)right)))) ?
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
static long __undefined;

struct S0 {
   signed f0 : 1;
   int64_t f1;
   signed f2 : 20;
   unsigned f3 : 8;
};

static int32_t g_2 = 1L;
static struct S0 g_35 = {-0,-1L,631,9};
static uint16_t g_40 = 65534UL;
static int32_t g_85 = 0x89AB98CFL;
static uint8_t g_86 = 2UL;
static int64_t g_131 = 1L;
static int16_t g_153 = 0L;
static uint32_t g_154 = 3UL;
static int16_t g_158 = 0L;
static uint32_t g_159 = 0x5CC1FFD3L;
static uint32_t g_203 = 0xBD2EE514L;
static int16_t g_250 = 0x8C40L;
static uint32_t g_251 = 0xB89A725EL;
static uint8_t g_312 = 1UL;
static int32_t g_316 = 0x123013CDL;
static uint32_t g_355 = 9UL;
static int32_t g_356 = (-1L);
static struct S0 g_388 = {0,6L,-661,1};
static int32_t g_390 = (-1L);
static uint8_t g_391 = 255UL;
static uint16_t g_420[4][10] = {{65535UL,0x88F0L,65535UL,65532UL,0x88F0L,7UL,7UL,0x88F0L,65532UL,65535UL},{0UL,0UL,0x54A8L,0x88F0L,0x8AC6L,0x54A8L,0x8AC6L,0x88F0L,0x54A8L,0UL},{0x8AC6L,7UL,65535UL,0x8AC6L,65532UL,65532UL,0x8AC6L,65535UL,7UL,0x8AC6L},{65535UL,0UL,7UL,65532UL,0UL,65532UL,7UL,0UL,65535UL,65535UL}};
static int32_t g_421[5][10][5] = {{{(-1L),0x9CC7936FL,0x733E4B69L,(-10L),3L},{0x6F17C7B4L,0x504E397CL,0xFAF5C5A5L,0x7C3E73E6L,(-1L)},{9L,0x276B277BL,(-1L),6L,6L},{(-8L),0xA1E38021L,(-8L),0x94C3BD62L,0xA7408F1FL},{0x8AC3A7DBL,0xD1F34A63L,0x05469B73L,0x41E353BDL,0x2626DBABL},{0x6F17C7B4L,0L,(-3L),1L,0xC693E4D5L},{(-1L),0x468DFB35L,0x05469B73L,0x2626DBABL,3L},{0xD2A2360EL,(-9L),(-8L),0x962C5FE5L,0x6F17C7B4L},{0x44593456L,0x9CC7936FL,(-1L),0xADF75AD1L,0xD7FDC368L},{0xC7DFE44CL,0x889A9044L,0xFAF5C5A5L,(-1L),0x504E397CL}},{{0xD1F34A63L,0x7D366DB7L,0xFA444388L,0x468DFB35L,0x4A120EAAL},{0x7C3E73E6L,0x40DD39B6L,0xD06CBE39L,0x73BCDCAEL,0x92D6179AL},{3L,0L,0xADF75AD1L,0L,0x8AC3A7DBL},{0x889A9044L,7L,0x2DC81D43L,0xB3515830L,0xFAF5C5A5L},{0xFA444388L,0x05469B73L,1L,(-5L),1L},{0x34421670L,0x34421670L,(-1L),(-1L),0x73BCDCAEL},{0xB2F5332AL,0x2626DBABL,0x7E2228E0L,0x28B7BCCEL,0x276B277BL},{0xDE5C95E5L,0L,(-4L),0xA3EA5012L,0xDA0AB8EFL},{0xD5DD3E96L,0x2626DBABL,9L,0x13025689L,1L},{0L,0x34421670L,0x57F46E1EL,0x40DD39B6L,0xC7DFE44CL}},{{0x28B7BCCEL,0x05469B73L,1L,1L,0x7D366DB7L},{(-1L),7L,0x962C5FE5L,0L,0xDFEFCE86L},{0x0B56072FL,0L,0x733E4B69L,0xD7FDC368L,0L},{(-1L),0x40DD39B6L,(-1L),0xFAF5C5A5L,0xD2A2360EL},{0xCD05DC4EL,0x7D366DB7L,1L,0x4772FBBAL,0xBB4B3D1CL},{0xDA0AB8EFL,0x889A9044L,0xA3EA5012L,0x6F17C7B4L,(-1L)},{(-1L),0x9CC7936FL,0xB2F5332AL,0xB2F5332AL,0x9CC7936FL},{0xC693E4D5L,(-9L),0x504E397CL,0xD06CBE39L,0xA3EA5012L},{1L,0x468DFB35L,9L,(-7L),0x2871C56AL},{0xD06CBE39L,0L,0xEB725935L,(-1L),1L}},{{1L,0xD1F34A63L,(-1L),1L,0x13025689L},{0xC693E4D5L,0xA1E38021L,1L,(-1L),0x5D2BDD0BL},{(-1L),0x276B277BL,0x2871C56AL,(-1L),6L},{0xDA0AB8EFL,0x504E397CL,0x5D2BDD0BL,7L,0L},{0xCD05DC4EL,(-1L),0xBB4B3D1CL,3L,0L},{(-1L),(-1L),8L,0x3E7F1E87L,0x962C5FE5L},{0x0B56072FL,0x28B7BCCEL,0L,0x2871C56AL,(-1L)},{(-1L),0x0552E894L,(-1L),0x5CF14D71L,(-8L)},{0x28B7BCCEL,(-1L),8L,(-1L),0x28B7BCCEL},{0L,(-8L),0xA7408F1FL,0L,1L}},{{(-1L),0x2871C56AL,0L,0x28B7BCCEL,0x0B56072FL},{1L,1L,(-1L),0xB7C597CEL,1L},{6L,0x28B7BCCEL,0xD1F34A63L,0x9CC7936FL,3L},{1L,0x45CBE6D6L,(-3L),0x3E7F1E87L,0xB7C597CEL},{0xBC0FE9D4L,1L,0x4772FBBAL,1L,3L},{0x40DD39B6L,0xC693E4D5L,0x0552E894L,0x6F17C7B4L,0L},{0xCD05DC4EL,(-5L),0x05469B73L,(-1L),0x7E2228E0L},{0L,0x0552E894L,1L,1L,0xFAF5C5A5L},{0xBB4B3D1CL,0x276B277BL,9L,1L,0L},{0x3E7F1E87L,0L,0x962C5FE5L,(-1L),0xD2A2360EL}}};
static uint64_t g_506 = 0UL;
static uint64_t g_559[8] = {4UL,4UL,4UL,4UL,4UL,4UL,4UL,4UL};
static int16_t g_594 = 1L;
static uint16_t g_750[1][6][1] = {{{0xE455L},{0xE455L},{0xE455L},{0xE455L},{0xE455L},{0xE455L}}};
static uint64_t g_754[6][10] = {{0x91FF780DDFEFE0BALL,0x91FF780DDFEFE0BALL,0xB71EF27D511E6B97LL,0x79AB76C8654775D1LL,0xF443B1863DBA0E6ALL,18446744073709551608UL,0x91FF780DDFEFE0BALL,0xF443B1863DBA0E6ALL,0UL,0xF443B1863DBA0E6ALL},{0x91FF780DDFEFE0BALL,0x5376858CA911C115LL,0x7F1EB7A26DC46069LL,0x79AB76C8654775D1LL,0x7F1EB7A26DC46069LL,0x5376858CA911C115LL,0x91FF780DDFEFE0BALL,0x7F1EB7A26DC46069LL,18446744073709551615UL,0xF443B1863DBA0E6ALL},{0x5376858CA911C115LL,0x91FF780DDFEFE0BALL,0x7F1EB7A26DC46069LL,18446744073709551615UL,0xF443B1863DBA0E6ALL,0x5376858CA911C115LL,0x5376858CA911C115LL,0xF443B1863DBA0E6ALL,18446744073709551615UL,0x7F1EB7A26DC46069LL},{0x91FF780DDFEFE0BALL,0x91FF780DDFEFE0BALL,0xB71EF27D511E6B97LL,0x79AB76C8654775D1LL,0xF443B1863DBA0E6ALL,18446744073709551608UL,0x91FF780DDFEFE0BALL,0xF443B1863DBA0E6ALL,0UL,0xF443B1863DBA0E6ALL},{0x91FF780DDFEFE0BALL,0x5376858CA911C115LL,0x7F1EB7A26DC46069LL,0x79AB76C8654775D1LL,0x7F1EB7A26DC46069LL,0x5376858CA911C115LL,0x91FF780DDFEFE0BALL,0x7F1EB7A26DC46069LL,18446744073709551615UL,0xF443B1863DBA0E6ALL},{0x5376858CA911C115LL,0x91FF780DDFEFE0BALL,0x7F1EB7A26DC46069LL,18446744073709551615UL,0xF443B1863DBA0E6ALL,0x5376858CA911C115LL,0x5376858CA911C115LL,0xF443B1863DBA0E6ALL,18446744073709551615UL,0x7F1EB7A26DC46069LL}};
static int32_t g_755[8] = {0x7375C0FDL,0x7375C0FDL,0x5F05B9D7L,0x7375C0FDL,0x7375C0FDL,0x5F05B9D7L,0x7375C0FDL,0x7375C0FDL};
static int32_t g_1021[5] = {1L,1L,1L,1L,1L};
static int32_t g_1031 = 1L;
static uint32_t g_1032[9] = {18446744073709551615UL,18446744073709551606UL,18446744073709551615UL,18446744073709551606UL,18446744073709551615UL,18446744073709551606UL,18446744073709551615UL,18446744073709551606UL,18446744073709551615UL};
static int32_t g_1103 = 0x44377EFEL;
static int8_t g_1109 = (-10L);
static struct S0 g_1145[8] = {{-0,-1L,887,10},{-0,-1L,887,10},{-0,-1L,887,10},{-0,-1L,887,10},{-0,-1L,887,10},{-0,-1L,887,10},{-0,-1L,887,10},{-0,-1L,887,10}};
static int64_t g_1238 = 0xEF73CDC07DB9FD50LL;
static uint64_t g_1241 = 1UL;
static uint32_t g_1304 = 0UL;
static uint32_t g_1732[2][7] = {{4294967287UL,4294967287UL,4294967287UL,4294967287UL,4294967287UL,4294967287UL,4294967287UL},{0xA22DCD37L,0UL,0xA22DCD37L,0UL,0xA22DCD37L,0UL,0xA22DCD37L}};
static uint64_t g_1756[1][1][10] = {{{1UL,2UL,1UL,1UL,2UL,1UL,1UL,2UL,1UL,1UL}}};
static uint32_t g_1935 = 3UL;
static int64_t g_1985 = 0x4E20E02FB14D3ADFLL;
static uint32_t g_2138 = 0xE3D39B8FL;
static uint8_t g_2239 = 0x2BL;
static uint32_t g_2299 = 0x533C3544L;
static int32_t g_2300 = (-1L);
static int32_t g_2342 = 0x91C31F8BL;

static int64_t func_1(void);
static int32_t func_6(uint32_t p_7, uint32_t p_8, int64_t p_9, int8_t p_10, int32_t p_11);
static uint8_t func_12(uint32_t p_13, int16_t p_14, struct S0 p_15, struct S0 p_16, int8_t p_17);
static uint8_t func_22(uint32_t p_23);
static uint8_t func_41(int32_t p_42, uint8_t p_43, int32_t p_44, int64_t p_45, uint32_t p_46);
static uint16_t func_51(int16_t p_52, uint16_t p_53, uint64_t p_54, int32_t p_55);
static struct S0 func_59(uint32_t p_60, int16_t p_61, uint64_t p_62, uint8_t p_63, struct S0 p_64);
static int32_t func_66(uint16_t p_67, struct S0 p_68);
static int32_t func_71(uint8_t p_72, uint32_t p_73, uint32_t p_74);
static uint8_t func_78(uint32_t p_79);






static int64_t func_1(void)
{
    uint32_t l_5 = 0x6DA5043CL;
    struct S0 l_34 = {0,0x5C82F744ED25E425LL,-208,14};
    int32_t l_2303[5];
    int8_t l_2308 = 3L;
    uint16_t l_2311 = 65527UL;
    uint16_t l_2345[4] = {0xEDBEL,0xEDBEL,0xEDBEL,0xEDBEL};
    uint32_t l_2354 = 0x7FA494A4L;
    int32_t l_2357 = 0x75FE5BB8L;
    uint16_t l_2358 = 0UL;
    int i;
    for (i = 0; i < 5; i++)
        l_2303[i] = (-1L);
    for (g_2 = 22; (g_2 <= (-3)); g_2 = safe_sub_func_int16_t_s_s(g_2, 2))
    {
        uint32_t l_30 = 0UL;
        uint8_t l_33 = 255UL;
        int32_t l_2301 = 0x444D8480L;
        int32_t l_2302 = (-2L);
        int32_t l_2304 = 0x33EA3733L;
        int32_t l_2305 = 0x25C00CA3L;
        int32_t l_2306 = 0L;
        int32_t l_2307 = 7L;
        int32_t l_2309 = 3L;
        int32_t l_2310[1];
        int16_t l_2343 = (-1L);
        uint32_t l_2344 = 1UL;
        int i;






{
        uint32_t l_30 = 0UL;
        uint8_t l_33 = 255UL;
        int32_t l_2301 = 0x444D8480L;
        int32_t l_2302 = (-2L);
        int32_t l_2304 = 0x33EA3733L;
        int32_t l_2305 = 0x25C00CA3L;
        int32_t l_2306 = 0L;
        int32_t l_2307 = 7L;
        int32_t l_2309 = 3L;
        int32_t l_2310[1];
        int16_t l_2343 = (-1L);
        uint32_t l_2344 = 1UL;
        int i;
        for (i = 0; i < 1; i++)
            l_2310[i] = 0xF3D959FAL;
        l_5 = g_2;
        g_2300 |= func_6(((18446744073709551615UL != 0x315362DAAB72B21ALL) > func_12((g_2 == (safe_rshift_func_uint16_t_u_u((safe_sub_func_int64_t_s_s(0x4CCFD66C4A87FCE6LL, (g_2 && func_22((safe_sub_func_uint16_t_u_u((safe_add_func_uint64_t_u_u((0UL && ((safe_mul_func_int8_t_s_s(l_30, (safe_sub_func_int64_t_s_s((4294967290UL != ((l_33 ^ g_2) > l_30)), g_2)))) & 65534UL)), 0x2AD015B01D976D99LL)), g_2)))))), l_5))), l_5, l_34, g_35, l_34.f0)), l_30, l_33, g_2, l_33);
        l_2311++;
        l_2304 = (g_35.f0 = ((((0xB378L <= (safe_mul_func_int8_t_s_s((safe_mul_func_int8_t_s_s(g_506, (safe_mul_func_int8_t_s_s((safe_lshift_func_int16_t_s_u(((g_2299--) != ((g_1756[0][0][6] = (safe_add_func_uint32_t_u_u((g_1732[0][1]--), (l_2305 && ((safe_mod_func_int8_t_s_s(((safe_rshift_func_int8_t_s_s(((safe_mod_func_int64_t_s_s((safe_rshift_func_uint8_t_u_s((g_391 |= (safe_rshift_func_int8_t_s_s(((l_2306 &= l_2308) <= (safe_rshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(l_33, l_34.f1)), (((((((l_2305 > g_755[7]) | (g_35.f2 = ((g_388.f0 = ((g_35.f3 , l_2310[0]) < g_2)) >= g_2342))) , 0x030870B0L) >= g_754[2][1]) > g_755[0]) & l_2302) && l_34.f0)))), 7))), g_1145[0].f0)), l_2343)) && g_131), 4)) | 0UL), l_2344)) , 1UL))))) < l_2345[1])), g_2138)), 0UL)))), g_1103))) && g_250) != g_131) >= l_34.f3));
    }




safe_mod_func_uint64_t_u_u((0x720FL == 0x14D4L), 0x1E7B790C5A96D6B6LL);




func_78((++g_86));



if (g_158)
                            {

g_506 &= 0x387E3CDF10492640LL;

}



safe_lshift_func_int8_t_s_s((-4L), 5);




{
                        g_85 ^= 0x5D1F78DDL;
                    }

g_1103 += 1;
g_131 -= 1;




safe_lshift_func_int8_t_s_s((-4L), 5);
safe_add_func_uint64_t_u_u((safe_lshift_func_uint16_t_u_u(0x6D2BL, 12)), g_1032[4]);
safe_rshift_func_uint8_t_u_s(g_203, 0);
safe_unary_minus_func_uint16_t_u(((((((safe_rshift_func_int16_t_s_u(g_35.f1, 3)) & g_356) , 8L) ^ 4294967295UL) <= g_159) != g_312));




safe_mod_func_uint32_t_u_u(g_388.f0, 0xD95D3B69L);




safe_lshift_func_uint16_t_u_u(0x6D2BL, 12);


    }
    g_356 |= ((safe_add_func_uint8_t_u_u(0xBEL, 253UL)) >= (g_35 , ((((0x1BF0108EL ^ (safe_mod_func_int16_t_s_s(((l_5 | (((((l_2303[2] = g_2138) , (safe_sub_func_int64_t_s_s((g_131 &= 7L), ((safe_add_func_int32_t_s_s(0x5B5F2838L, 5UL)) <= g_1935)))) , 0x0B2CL) == g_251) , g_559[3])) == 0x870BF6B6L), 65527UL))) != g_1238) , l_5) == g_559[6])));
    l_2354--;
    ++l_2358;
    return g_1756[0][0][6];
}





static int32_t func_6(uint32_t p_7, uint32_t p_8, int64_t p_9, int8_t p_10, int32_t p_11)
{
    return p_8;
}





static uint8_t func_12(uint32_t p_13, int16_t p_14, struct S0 p_15, struct S0 p_16, int8_t p_17)
{
    uint16_t l_47[9][1];
    int32_t l_48 = 0x693CE85DL;
    int32_t l_58 = 1L;
    struct S0 l_65 = {-0,0x398C3D34E0BB6923LL,83,9};
    int32_t l_2073 = 1L;
    int32_t l_2076 = 0xF76A42B0L;
    int32_t l_2077 = 0x8D8B355DL;
    int32_t l_2078 = 1L;
    int32_t l_2080[3][2][9];
    int32_t l_2166 = 0x1B7F9CF5L;
    int8_t l_2167 = 1L;
    uint16_t l_2242[1];
    int32_t l_2280 = 0xA36C0F69L;
    struct S0 l_2282[6] = {{0,-1L,256,10},{0,-1L,256,10},{0,-1L,256,10},{0,-1L,256,10},{0,-1L,256,10},{0,-1L,256,10}};
    uint32_t l_2298 = 0xB81F1C22L;
    int i, j, k;

safe_rshift_func_int16_t_s_s((-1L), 1);


safe_rshift_func_uint16_t_u_s((p_13 >= p_16.f1), 3);
safe_lshift_func_uint8_t_u_s(((safe_lshift_func_uint8_t_u_u((g_40 = p_16.f2), 0)) , func_41(p_16.f1, (l_47[0][0] = g_2), func_22(g_35.f3), l_48, ((safe_mul_func_int16_t_s_s((func_51(((safe_lshift_func_int8_t_s_s(l_58, 3)) , 1L), (func_22(((g_1103 |= (func_59((p_15.f3 ^= 0x43772679L), p_16.f3, p_15.f2, g_35.f2, l_65) , p_15.f2)) || g_1021[4])) , g_1021[3]), l_65.f1, g_1021[3]) && 0L), g_1021[3])) && 0x72B8796B4B0CDDFFLL))), 3);
safe_mod_func_uint32_t_u_u(g_388.f0, 0xD95D3B69L);




printf("index = [%d]\n", i);







g_85 ^= 0x5D1F78DDL;



safe_unary_minus_func_int8_t_s((0L < (safe_add_func_int16_t_s_s(g_35.f3, 0x16ABL))));



g_35.f0 |= 0xAF702FE3L;



g_251 += 1;




g_40 += 1;
{
                        int i, j, k;
                        return l_2080[(g_316 + 1)][(g_316 + 1)][(g_316 + 5)];
                    }

func_78((++g_86));


{
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 9; k++)
                l_2080[i][j][k] = 0L;
        }
    }

safe_mul_func_int8_t_s_s((0L > g_391), (-9L));
printf("index = [%d][%d][%d]\n", i, j, k);





safe_mod_func_uint8_t_u_u(func_78((++g_86)), g_85);


g_506 &= 0x387E3CDF10492640LL;




g_159 += 1;


for (i = 0; i < 3; i++)
    {


g_131 &= 7L;


    };
safe_lshift_func_int8_t_s_s((-4L), 5);



safe_unary_minus_func_int16_t_s(1L);





safe_mul_func_uint16_t_u_u(1UL, 0x5E27L);






g_40 += 1;




safe_sub_func_int64_t_s_s((g_131 &= 7L), ((safe_add_func_int32_t_s_s(0x5B5F2838L, 5UL)) <= g_1935));





g_251 += 1;
safe_mul_func_int8_t_s_s(g_154, g_35.f3);




safe_lshift_func_uint16_t_u_s(65535UL, 9);




safe_mul_func_int16_t_s_s((func_51(((safe_lshift_func_int8_t_s_s(l_58, 3)) , 1L), (func_22(((g_1103 |= (func_59((p_15.f3 ^= 0x43772679L), p_16.f3, p_15.f2, g_35.f2, l_65) , p_15.f2)) || g_1021[4])) , g_1021[3]), l_65.f1, g_1021[3]) && 0L), g_1021[3]);




g_388.f1 -= 1;


{


g_35.f0 |= 0xAF702FE3L;

g_159 += 1;
g_35.f1 |= ((safe_mod_func_int8_t_s_s(((safe_sub_func_uint32_t_u_u((safe_mod_func_uint64_t_u_u((g_312 == (safe_mod_func_int64_t_s_s((252UL ^ g_251), 0x54EAB2CE98B21CF8LL))), p_13)), 0UL)) && l_58), p_15.f3)) <= (-10L));



g_159 += 1;
g_1109 ^= (0xFACE4F9578FC59A3LL <= 0x61490D3A8CA6555ALL);


            }


safe_mul_func_uint8_t_u_u(g_1021[(g_388.f1 + 4)], 0x08L);
safe_add_func_uint64_t_u_u(((((0xF01A30E9L != (0x3FE1L & g_250)) , g_316) || p_16.f0) || 8L), 0xC0E07CACADAC72B0LL);


safe_mod_func_int16_t_s_s(8L, 0x9ED3L);
safe_mod_func_uint8_t_u_u(g_153, 0x1FL);


{
                for (g_159 = 0; (g_159 <= 3); g_159 += 1)
                {


                    return g_754[4][9];
                }
            }


safe_lshift_func_uint16_t_u_s(65535UL, 9);


safe_mul_func_int8_t_s_s(0xAEL, g_203);


safe_sub_func_uint32_t_u_u((g_755[7] , g_1109), 1UL);
g_35.f1 |= ((safe_mod_func_int8_t_s_s(((safe_sub_func_uint32_t_u_u((safe_mod_func_uint64_t_u_u((g_312 == (safe_mod_func_int64_t_s_s((252UL ^ g_251), 0x54EAB2CE98B21CF8LL))), p_13)), 0UL)) && l_58), p_15.f3)) <= (-10L));






safe_add_func_int32_t_s_s(p_13, ((-1L) & 1UL));


func_1();

g_1109 ^= (-1L);



safe_sub_func_int64_t_s_s((g_131 &= 7L), ((safe_add_func_int32_t_s_s(0x5B5F2838L, 5UL)) <= g_1935));







safe_mul_func_uint8_t_u_u(g_1021[(g_388.f1 + 4)], 0x08L);




safe_unary_minus_func_int16_t_s(1L);




g_1109 ^= (-1L);



for (i = 0; i < 1; i++)
        {

}

safe_mod_func_uint64_t_u_u((0x720FL == 0x14D4L), 0x1E7B790C5A96D6B6LL);



{
        uint16_t l_2247 = 2UL;
        int32_t l_2248 = 0x07CE1456L;
        uint64_t l_2249 = 0xA3F082DE2C18DA24LL;
        int64_t l_2277[3];
        int32_t l_2278 = 0xEE781271L;
        int32_t l_2279[5][10][3] = {{{0xCFD4230DL,0x5B6938F0L,0x398AD982L},{8L,0xCEB0288AL,0x40CB8E38L},{(-8L),(-1L),0x08A5BD52L},{0x695D4B9FL,0x71775154L,0x695D4B9FL},{0x08A5BD52L,(-1L),(-8L)},{0x40CB8E38L,0xCEB0288AL,8L},{0x398AD982L,0x5B6938F0L,0xCFD4230DL},{0L,0L,1L},{0x398AD982L,0x08A5BD52L,0x5B6938F0L},{0x40CB8E38L,1L,0L}},{{0x08A5BD52L,0xA008A039L,0xA008A039L},{0x695D4B9FL,0x40CB8E38L,0L},{(-8L),0L,0x5B6938F0L},{8L,(-1L),1L},{0xCFD4230DL,0L,0xCFD4230DL},{1L,(-1L),8L},{0x5B6938F0L,0L,(-8L)},{0L,0x40CB8E38L,0x695D4B9FL},{0xA008A039L,0xA008A039L,0x08A5BD52L},{0L,1L,0x40CB8E38L}},{{0x5B6938F0L,0x08A5BD52L,0x398AD982L},{1L,0L,0L},{0xCFD4230DL,0x5B6938F0L,0x398AD982L},{8L,0xCEB0288AL,0x40CB8E38L},{(-8L),(-1L),0x08A5BD52L},{0x695D4B9FL,0x71775154L,0x695D4B9FL},{0x08A5BD52L,(-1L),(-8L)},{0x40CB8E38L,0xCEB0288AL,8L},{0x398AD982L,0x5B6938F0L,0xCFD4230DL},{0L,0L,1L}},{{0x398AD982L,0x08A5BD52L,0x5B6938F0L},{0x40CB8E38L,1L,0L},{0x08A5BD52L,0xA008A039L,0xA008A039L},{0x695D4B9FL,0x40CB8E38L,0L},{(-8L),0L,0x5B6938F0L},{8L,(-1L),1L},{0xCFD4230DL,0L,0xCFD4230DL},{1L,(-1L),8L},{0x5B6938F0L,0L,(-8L)},{0L,0x40CB8E38L,0x695D4B9FL}},{{0xA008A039L,(-10L),0xA008A039L},{8L,0L,0x71775154L},{0L,0xA008A039L,(-8L)},{0L,4L,4L},{(-1L),0L,(-8L)},{0x695D4B9FL,0L,0x71775154L},{0xCFD4230DL,0x08A5BD52L,0xA008A039L},{(-1L),0x64D5E002L,(-1L)},{0xA008A039L,0x08A5BD52L,0xCFD4230DL},{0x71775154L,0L,0x695D4B9FL}}};
        int32_t l_2281 = 7L;
        uint64_t l_2297 = 0UL;
        int i, j, k;
        for (i = 0; i < 3; i++)
            {

safe_rshift_func_uint8_t_u_u((((g_388.f1 ^= p_15.f2) != (p_16 , (l_2248 &= (p_16.f1 = (safe_mod_func_uint16_t_u_u(l_2247, g_1935)))))) && 0x4FL), l_2247);

}



        g_35 = func_59(((l_2078 = (l_58 = ((--g_391) | (p_17 < ((((l_2281 = (((((g_1109 = ((l_2280 = (g_506 > ((safe_add_func_int32_t_s_s(p_16.f0, ((((((safe_mod_func_int64_t_s_s((l_2279[1][9][1] = (safe_lshift_func_uint16_t_u_s((l_65.f0 = (safe_add_func_uint64_t_u_u((safe_mod_func_uint64_t_u_u((safe_add_func_uint64_t_u_u((l_2278 = (((g_159 = (0x74L < (p_13 | (safe_lshift_func_int8_t_s_s(g_421[3][7][1], (safe_unary_minus_func_uint16_t_u((safe_mul_func_int8_t_s_s((l_2076 |= (safe_rshift_func_int16_t_s_u(((p_14 = (safe_add_func_uint16_t_u_u((g_506 <= (safe_mul_func_uint16_t_u_u((l_2248 = (l_2249 > ((safe_mul_func_int8_t_s_s(p_15.f1, g_559[6])) | 1L))), g_1145[0].f2))), g_594))) || 3UL), 13))), l_2277[2]))))))))) , l_2277[1]) >= g_1032[8])), (-1L))), l_2242[0])), p_16.f3))), 14))), (-1L))) , g_1109) && g_390) >= p_15.f0) , 0x21L) == g_312))) <= 0x9AL))) > 0UL)) ^ 255UL) != 0x697984F0L) , l_2278) && 0x84673B59ABD64EBBLL)) & g_2138) <= 0x8B1272E60FADCBF8LL) >= g_1304))))) , l_2249), g_1756[0][0][6], l_2277[1], g_1304, l_2282[2]);
        l_2298 ^= (safe_add_func_uint64_t_u_u(18446744073709551612UL, (((l_2166 = l_2277[2]) ^ (safe_sub_func_uint64_t_u_u((p_16.f0 >= (p_15.f2 = (((((((g_1238 > ((((l_2277[2] < (safe_mul_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_s((~l_2282[2].f3), 10)), 0UL)) ^ (((g_1032[4] , (((safe_unary_minus_func_int32_t_s((safe_rshift_func_uint8_t_u_u((((l_2279[1][9][1] > 0UL) ^ l_2279[2][1][0]) & g_559[4]), 0)))) && l_2297) <= l_2167)) && l_2282[2].f0) || 4294967295UL)), 0x001EL))) , l_2242[0]) >= 3UL) && l_65.f0)) <= p_15.f0) , l_2278) > l_2277[1]) <= 4UL) ^ p_15.f1) || l_2279[0][6][1]))), l_2080[1][1][7]))) , g_388.f0)));
    }
safe_lshift_func_int8_t_s_s(l_58, 3);
g_159 += 1;




safe_mul_func_int8_t_s_s(p_15.f1, g_559[6]);




safe_lshift_func_uint16_t_u_s(65535UL, 9);




safe_unary_minus_func_uint32_t_u(1UL);






g_1103 |= (func_59((p_15.f3 ^= 0x43772679L), p_16.f3, p_15.f2, g_35.f2, l_65) , p_15.f2);
safe_add_func_int32_t_s_s(0x5B5F2838L, 5UL);


    return g_2299;
}





static uint8_t func_22(uint32_t p_23)
{
    return p_23;
}





static uint8_t func_41(int32_t p_42, uint8_t p_43, int32_t p_44, int64_t p_45, uint32_t p_46)
{
    uint16_t l_1480 = 0xA686L;
    int32_t l_1505 = 0L;
    int32_t l_1506 = (-9L);
    int16_t l_1507 = 0L;
    int32_t l_1508 = 0L;
    struct S0 l_1570[3][4][5] = {{{{0,-4L,-116,7},{0,0x5F448C1F958DC280LL,-423,15},{0,8L,-490,8},{0,8L,-490,8},{0,0x5F448C1F958DC280LL,-423,15}},{{0,0xA638DFE240EFA1CBLL,-152,11},{0,0x919B657A6F0D3D43LL,-795,11},{-0,0x603356D2FC8A99DCLL,-575,2},{0,-1L,825,10},{0,-1L,825,10}},{{0,0xA0191CBE08CA11F3LL,-235,10},{-0,0L,386,13},{0,0xA0191CBE08CA11F3LL,-235,10},{0,8L,-490,8},{0,1L,900,6}},{{0,0L,88,3},{-0,0xD3427C9C5EA38133LL,50,9},{0,-1L,825,10},{-0,0xD3427C9C5EA38133LL,50,9},{0,0L,88,3}}},{{{0,0xA0191CBE08CA11F3LL,-235,10},{0,-4L,-116,7},{-0,0L,386,13},{0,0x5F448C1F958DC280LL,-423,15},{-0,0L,386,13}},{{0,0xA638DFE240EFA1CBLL,-152,11},{0,0xA638DFE240EFA1CBLL,-152,11},{0,-1L,825,10},{0,0L,88,3},{0,0xEAA05D5F758D6168LL,987,14}},{{0,-4L,-116,7},{0,0xA0191CBE08CA11F3LL,-235,10},{0,0xA0191CBE08CA11F3LL,-235,10},{0,-4L,-116,7},{-0,0L,386,13}},{{-0,0xD3427C9C5EA38133LL,50,9},{0,0L,88,3},{-0,0x603356D2FC8A99DCLL,-575,2},{-0,0x603356D2FC8A99DCLL,-575,2},{0,0L,88,3}}},{{{-0,0L,386,13},{0,0xA0191CBE08CA11F3LL,-235,10},{0,8L,-490,8},{0,1L,900,6},{0,1L,900,6}},{{0,0x919B657A6F0D3D43LL,-795,11},{0,0xA638DFE240EFA1CBLL,-152,11},{0,0x919B657A6F0D3D43LL,-795,11},{-0,0x603356D2FC8A99DCLL,-575,2},{0,-1L,825,10}},{{0,0x5F448C1F958DC280LL,-423,15},{0,-4L,-116,7},{0,1L,900,6},{0,-4L,-116,7},{0,0x5F448C1F958DC280LL,-423,15}},{{0,0x919B657A6F0D3D43LL,-795,11},{-0,0xD3427C9C5EA38133LL,50,9},{0,0xA638DFE240EFA1CBLL,-152,11},{0,0L,88,3},{0,0xA638DFE240EFA1CBLL,-152,11}}}};
    int32_t l_1694 = 0x478A7D77L;
    int32_t l_1695 = (-3L);
    int64_t l_1700 = (-2L);
    int32_t l_1701 = 1L;
    int32_t l_1702 = 0x753BEF4DL;
    int32_t l_1878 = 1L;
    uint8_t l_1943[8] = {0xFCL,0xFCL,0xFCL,0xFCL,0xFCL,0xFCL,0xFCL,0xFCL};
    int i, j, k;
lbl_1950:
    if ((l_1480 != (safe_lshift_func_int8_t_s_s(g_420[1][7], ((safe_rshift_func_int8_t_s_s(((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s((g_312 ^= ((safe_sub_func_uint16_t_u_u(((~((((((l_1508 |= (l_1507 = (((g_754[1][9] ^= l_1480) <= (safe_lshift_func_int16_t_s_s((g_250 = ((0x5A0AL <= (((((l_1506 |= (p_44 , ((safe_add_func_int64_t_s_s((p_45 &= (safe_mul_func_int8_t_s_s((((safe_lshift_func_uint8_t_u_s((0xE2L && (((+9UL) , ((p_46 = (safe_lshift_func_int16_t_s_u((g_158 |= ((((((((safe_lshift_func_int8_t_s_s((l_1505 = (((p_44 < g_506) >= 4294967289UL) | l_1480)), 0)) , l_1480) , 0x2E28L) , l_1505) < g_594) == 0xE8L) >= 1L) <= 1L)), g_594))) == 0x47E48E4FL)) >= p_42)), 1)) && g_85) & (-1L)), 0x9BL))), g_2)) < l_1480))) > l_1480) == p_44) ^ 1UL) , p_46)) == p_44)), 15))) | 0xE2L))) && 0L) , g_754[1][4]) == g_388.f1) < l_1480) & p_42)) > 255UL), p_43)) ^ g_86)), l_1480)), p_44)) > 0L), g_390)) , 0x96L)))))
    {
        int32_t l_1509 = 0xCF0D3FA9L;
        struct S0 l_1528 = {0,0L,-253,2};
        l_1508 = (g_312 , ((0L < l_1509) , p_44));
        l_1506 ^= ((safe_mod_func_int16_t_s_s(((l_1528.f0 = (p_44 || (safe_add_func_int16_t_s_s(g_754[5][3], (safe_mul_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u((g_594 = (0L || (((safe_rshift_func_uint8_t_u_s((((((safe_rshift_func_int8_t_s_u(0x7DL, 6)) | ((p_42 | (safe_mod_func_uint64_t_u_u(p_42, ((safe_sub_func_int64_t_s_s(((((((g_1145[0] = l_1528) , 0x95076570L) != ((safe_rshift_func_int16_t_s_s((safe_sub_func_int64_t_s_s((safe_unary_minus_func_uint16_t_u((safe_mul_func_uint8_t_u_u(((8UL ^ g_388.f3) , 0xF4L), 0x13L)))), p_44)), 12)) != p_44)) || 0x48774AAAL) > g_86) | l_1480), g_421[4][0][4])) || 0x61CBL)))) >= 1L)) >= p_43) || (-3L)) , 0x77L), l_1507)) || g_1109) && p_43))), 10)), p_46)))))) | p_42), l_1528.f1)) == 2UL);
    }
    else
    {
        uint32_t l_1540 = 0xD67BC027L;
        uint32_t l_1560 = 4294967294UL;
        int32_t l_1561[4] = {1L,1L,1L,1L};
        int32_t l_1595 = 0x125009E3L;
        int32_t l_1652[8][3] = {{0x51A4C3ECL,0x51A4C3ECL,0xBE2572F9L},{0xBDEF01DCL,0x4A792898L,0xBE2572F9L},{0x4A792898L,0xBDEF01DCL,0xBE2572F9L},{0x51A4C3ECL,0x51A4C3ECL,0xBE2572F9L},{0xBDEF01DCL,0x4A792898L,0xBE2572F9L},{0x4A792898L,0xBDEF01DCL,0xBE2572F9L},{0x51A4C3ECL,0x51A4C3ECL,0xBE2572F9L},{0xBDEF01DCL,0x4A792898L,0xBE2572F9L}};
        int i, j;
        for (g_355 = 0; (g_355 == 20); g_355 = safe_add_func_int32_t_s_s(g_355, 2))
        {
            struct S0 l_1553 = {0,-6L,721,14};
            if (((safe_sub_func_int32_t_s_s(g_1021[3], (l_1540 ^= g_35.f2))) && ((g_750[0][4][0] = (safe_sub_func_uint64_t_u_u((safe_rshift_func_uint8_t_u_u(((((g_131 = ((g_1109 = 0x55L) > ((4294967292UL != 0xE28497BAL) >= (safe_lshift_func_uint8_t_u_s((((safe_mul_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s(((safe_sub_func_int8_t_s_s(((l_1553 , ((safe_rshift_func_uint8_t_u_s((((safe_rshift_func_uint8_t_u_s((l_1505 |= p_46), ((safe_lshift_func_int8_t_s_s(2L, 2)) , 0x61L))) != g_1031) & l_1553.f1), l_1553.f0)) != p_42)) && l_1506), 250UL)) && p_45), p_44)), g_1304)) ^ l_1506) == (-1L)), p_46))))) , p_43) >= 0L) , l_1560), 0)), g_1241))) , l_1553.f2)))
            {
                int32_t l_1563 = (-8L);
                int32_t l_1565 = (-3L);
                struct S0 l_1569 = {-0,0L,810,1};
                l_1561[1] = 0x2F15491AL;
                for (p_44 = 3; (p_44 >= 0); p_44 -= 1)
                {
                    uint32_t l_1566 = 2UL;
                    int32_t l_1622 = 0x52D880B5L;
                    for (g_159 = 0; (g_159 <= 3); g_159 += 1)
                    {
                        int32_t l_1562 = 0xC5F11417L;
                        int32_t l_1564[4][2] = {{3L,3L},{3L,3L},{3L,3L},{3L,3L}};
                        int i, j;
                        if (g_420[g_159][(p_44 + 4)])
                            break;
                        l_1566--;
                        return g_2;
                    }
                    for (g_1241 = 0; (g_1241 <= 0); g_1241 += 1)
                    {
                        int32_t l_1581 = 0xEA029340L;
                        int i;
                        l_1570[0][1][2] = l_1569;
                        p_42 = g_1032[(g_1241 + 8)];
                        g_421[4][4][1] |= ((safe_mul_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((((((g_1032[(p_44 + 5)] , 1UL) || (safe_add_func_int8_t_s_s(g_388.f1, (safe_rshift_func_uint8_t_u_s((p_42 & g_2), 7))))) , ((safe_rshift_func_int16_t_s_u((l_1553.f2 = (((((l_1581 = 0xC8D8L) != (safe_add_func_int16_t_s_s((g_2 ^ p_43), l_1569.f3))) , 0L) < 7L) > 2UL)), p_44)) > g_390)) > g_1021[3]) & l_1566), 0)), g_158)) | p_42);
                        g_755[7] |= (p_44 , (safe_add_func_uint8_t_u_u(l_1561[1], (safe_lshift_func_int16_t_s_u(((safe_mod_func_uint32_t_u_u(((safe_mul_func_uint8_t_u_u(l_1570[0][1][2].f3, ((((+(g_1304 < ((safe_add_func_int16_t_s_s((l_1595 = ((-9L) & p_44)), g_388.f0)) < ((safe_rshift_func_uint16_t_u_u((safe_unary_minus_func_uint8_t_u(g_754[1][9])), ((((g_35.f3 ^ g_1145[0].f0) > l_1553.f0) | 0xD81381D4L) == 3L))) && g_750[0][3][0])))) & p_45) != g_355) | g_203))) , g_158), g_1109)) | 5UL), 0)))));
                    }
                    for (p_43 = (-30); (p_43 >= 2); p_43 = safe_add_func_uint16_t_u_u(p_43, 6))
                    {
                        uint32_t l_1623 = 0x19F8F8ABL;
                        int8_t l_1651 = 0xC4L;
                        g_421[2][3][3] = ((((safe_lshift_func_uint16_t_u_s(g_153, (safe_mul_func_int8_t_s_s(0xAEL, g_203)))) > (safe_lshift_func_int8_t_s_s((l_1570[0][1][2].f2 ^ ((l_1561[1] = (safe_add_func_int8_t_s_s(((safe_lshift_func_int16_t_s_u((((g_755[7] > (l_1622 = ((safe_mul_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(((g_153 & ((safe_sub_func_uint16_t_u_u((((p_44 < ((p_45 ^= l_1553.f2) & (!(safe_add_func_int8_t_s_s(g_203, l_1566))))) || g_420[3][6]) | p_42), g_35.f3)) || 0x04L)) && 0UL), 0x58F7L)), l_1566)) == g_750[0][4][0]))) , p_46) ^ p_43), l_1623)) | 0x00L), g_312))) | l_1595)), 3))) || l_1569.f3) | 1L);
                        p_42 ^= ((safe_add_func_uint16_t_u_u(g_754[1][0], (safe_add_func_int8_t_s_s(((p_43 < (safe_add_func_uint32_t_u_u((l_1622 = 1UL), (l_1553.f3 != (l_1565 ^= ((0x27751B71CBB9CA87LL && 8L) || (safe_rshift_func_int16_t_s_s(((((safe_mul_func_uint8_t_u_u((((safe_unary_minus_func_int16_t_s(((safe_add_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((((g_388.f3 = (0x4258DEEEF776DBDBLL < (p_45 > (g_1145[0].f3 = 1UL)))) <= g_203) < g_251), g_356)), p_43)) <= 0L))) , p_43) == 1UL), 0x66L)) == l_1623) ^ l_1570[0][1][2].f0) != 3L), l_1553.f2)))))))) , g_754[2][4]), 0xC7L)))) && p_43);
                        g_755[1] = ((safe_rshift_func_int8_t_s_s(((!((p_46 >= (safe_mul_func_uint16_t_u_u(l_1570[0][1][2].f1, ((p_46 > ((4L || (+l_1570[0][1][2].f1)) >= (((l_1622 = (g_391 = (((safe_sub_func_int64_t_s_s((safe_sub_func_uint64_t_u_u((((l_1565 | ((((g_1145[0] , ((((safe_sub_func_uint32_t_u_u(0xA8D8CFA5L, l_1623)) == g_1145[0].f2) , 0xE338L) , 0x455D144CAF2D42E0LL)) > 0x1DC56EAE6A15FC71LL) , 0UL) & g_1021[0])) , 1UL) ^ p_45), p_42)), l_1622)) > 0L) >= l_1651))) < 0x6EL) , g_1021[3]))) || l_1652[7][1])))) != p_43)) != l_1506), p_44)) , p_46);
                    }
                }
            }
            else
            {
                if (p_43)
                    break;
                return g_390;
            }
        }
    }
lbl_1944:
    g_755[7] = p_45;


safe_mod_func_int32_t_s_s((((0xF7L | l_1570[0][1][2].f0) > ((safe_unary_minus_func_uint32_t_u(1UL)) | ((safe_add_func_int16_t_s_s(0L, (g_1238 , 0x8542L))) , 0x90F3FAD7B2A48AA1LL))) > p_42), 0xA083447AL);




safe_mul_func_int8_t_s_s((0L > g_391), (-9L));




{




                    return g_754[4][9];
                }


g_250 -= 1;


safe_rshift_func_uint16_t_u_s(65527UL, g_203);
safe_lshift_func_int8_t_s_s(2L, 2);
safe_add_func_int32_t_s_s(0x5B5F2838L, 5UL);
safe_rshift_func_uint8_t_u_s((!p_42), g_755[7]);
    return p_42;
}





static uint16_t func_51(int16_t p_52, uint16_t p_53, uint64_t p_54, int32_t p_55)
{
    uint8_t l_1104[4][4][5] = {{{0x67L,0xA6L,0x5DL,0x66L,0UL},{0xA6L,0xAEL,0x21L,251UL,4UL},{0x67L,255UL,9UL,0xAEL,254UL},{0xC1L,1UL,1UL,0x5DL,255UL}},{{1UL,253UL,0xA6L,0UL,0x4FL},{253UL,253UL,255UL,0x33L,0x33L},{255UL,1UL,255UL,0x7DL,255UL},{255UL,255UL,253UL,0x21L,1UL}},{{251UL,0xAEL,0x12L,255UL,0xC1L},{255UL,0xA6L,253UL,1UL,0xC1L},{0x41L,7UL,255UL,0x04L,253UL},{9UL,253UL,255UL,254UL,0x6CL}},{{7UL,255UL,0xA6L,254UL,0x67L},{0x21L,0x04L,1UL,0x04L,0x21L},{0x12L,0x21L,9UL,1UL,255UL},{0x5DL,253UL,0x21L,255UL,0xAEL}}};
    struct S0 l_1144 = {0,0x2C0EE27351D2F17ALL,-548,3};
    int32_t l_1162 = 0x0D39437AL;
    int32_t l_1354 = 1L;
    int32_t l_1356[4] = {(-5L),(-5L),(-5L),(-5L)};
    uint16_t l_1363 = 0xE5EBL;
    uint16_t l_1426[2];
    struct S0 l_1427 = {0,-1L,929,12};
    int i, j, k;

safe_add_func_int8_t_s_s(g_35.f1, 9);






g_1304 += 1;


for (g_153 = (-20); (g_153 < 6); g_153 = safe_add_func_int8_t_s_s(g_153, 1))
    {
        uint32_t l_1440 = 0x3482DA34L;
        int32_t l_1452 = 0xB168BE91L;

safe_add_func_uint16_t_u_u(65535UL, (0xABL && 0xF2L));



safe_lshift_func_int8_t_s_u(g_35.f0, 2);


safe_lshift_func_int16_t_s_u((g_1756[0][0][6] || 0x096AE7FBL), 13);
safe_lshift_func_int16_t_s_u((g_1756[0][0][6] || 0x096AE7FBL), 13);




p_53 += 1;


func_22(g_35.f3);
safe_rshift_func_int16_t_s_s((l_1144.f2 = (safe_rshift_func_int16_t_s_u((g_594 = 0x925BL), 6))), 0);


{
                    g_35.f0 |= 0xAF702FE3L;
safe_mul_func_uint8_t_u_u((~g_388.f1), 0xDAL);


                }




safe_mul_func_int8_t_s_s((0L > g_391), (-9L));


    };
p_55 -= 1;


g_356 |= (safe_rshift_func_uint16_t_u_s(g_250, 12));
safe_unary_minus_func_int16_t_s(1L);
safe_rshift_func_int16_t_s_s((l_1144.f2 = (safe_rshift_func_int16_t_s_u((g_594 = 0x925BL), 6))), 0);




{
        uint32_t l_1440 = 0x3482DA34L;
        int32_t l_1452 = 0xB168BE91L;
        for (g_131 = (-16); (g_131 < 1); g_131++)
        {
            for (g_1241 = 24; (g_1241 < 34); g_1241 = safe_add_func_uint16_t_u_u(g_1241, 4))
            {
                for (g_85 = 0; (g_85 != 0); g_85 = safe_add_func_uint8_t_u_u(g_85, 1))
                {
                    uint32_t l_1437 = 0xA9A030FBL;
                    return l_1437;
                }
            }
        }
        g_388.f2 = ((0x9280DE75F5A10CCALL < g_158) ^ ((9L & ((safe_add_func_uint16_t_u_u((l_1440++), (safe_lshift_func_int16_t_s_u((g_594 = (g_316 , p_55)), 15)))) && ((+((18446744073709551611UL < (l_1356[0] = (((((safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint8_t_u_s((safe_add_func_int64_t_s_s((g_131 = p_53), (p_54 ^= p_53))), 7)), 3)) && (((0x1E1E57CAL & g_1021[1]) , 0x9FA2L) <= l_1440)) != g_750[0][4][0]) > 0x3A70L) >= g_316))) , 0x7393L)) == 0x9F7EC0A2L))) || g_35.f0));
        p_55 = (((l_1427.f2 = p_53) & (l_1452 &= (g_35.f1 , 0x2C6BL))) , ((safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_s((safe_add_func_int16_t_s_s((~((l_1452 = 0xE489E68586BFF0DDLL) ^ l_1440)), p_53)), (safe_mod_func_int8_t_s_s((0xAA7170BFL && 0x73A17C9BL), (safe_add_func_int32_t_s_s((0xAFL != 0x3BL), l_1440)))))) != p_52), 4)) & p_52));
    }


g_1109 ^= (0xFACE4F9578FC59A3LL <= 0x61490D3A8CA6555ALL);


safe_add_func_uint8_t_u_u(0xBEL, 253UL);
for (g_153 = (-20); (g_153 < 6); g_153 = safe_add_func_int8_t_s_s(g_153, 1))
    {
        uint32_t l_1440 = 0x3482DA34L;
        int32_t l_1452 = 0xB168BE91L;
        for (g_131 = (-16); (g_131 < 1); g_131++)
        {
            for (g_1241 = 24; (g_1241 < 34); g_1241 = safe_add_func_uint16_t_u_u(g_1241, 4))
            {
                for (g_85 = 0; (g_85 != 0); g_85 = safe_add_func_uint8_t_u_u(g_85, 1))
                {
                    uint32_t l_1437 = 0xA9A030FBL;
                    return l_1437;
                }
            }
        }
        g_388.f2 = ((0x9280DE75F5A10CCALL < g_158) ^ ((9L & ((safe_add_func_uint16_t_u_u((l_1440++), (safe_lshift_func_int16_t_s_u((g_594 = (g_316 , p_55)), 15)))) && ((+((18446744073709551611UL < (l_1356[0] = (((((safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint8_t_u_s((safe_add_func_int64_t_s_s((g_131 = p_53), (p_54 ^= p_53))), 7)), 3)) && (((0x1E1E57CAL & g_1021[1]) , 0x9FA2L) <= l_1440)) != g_750[0][4][0]) > 0x3A70L) >= g_316))) , 0x7393L)) == 0x9F7EC0A2L))) || g_35.f0));
        p_55 = (((l_1427.f2 = p_53) & (l_1452 &= (g_35.f1 , 0x2C6BL))) , ((safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_s((safe_add_func_int16_t_s_s((~((l_1452 = 0xE489E68586BFF0DDLL) ^ l_1440)), p_53)), (safe_mod_func_int8_t_s_s((0xAA7170BFL && 0x73A17C9BL), (safe_add_func_int32_t_s_s((0xAFL != 0x3BL), l_1440)))))) != p_52), 4)) & p_52));
    };



printf("index = [%d][%d][%d]\n", i, j, k);



safe_sub_func_int16_t_s_s(g_2, 2);
safe_lshift_func_int16_t_s_u((g_594 = (g_316 , p_55)), 15);




safe_mul_func_uint8_t_u_u((~g_388.f1), 0xDAL);




{
            for (g_1241 = 24; (g_1241 < 34); g_1241 = safe_add_func_uint16_t_u_u(g_1241, 4))
            {
                for (g_85 = 0; (g_85 != 0); g_85 = safe_add_func_uint8_t_u_u(g_85, 1))
                {
                    uint32_t l_1437 = 0xA9A030FBL;
                    return l_1437;
                }
            }
        }

safe_add_func_uint8_t_u_u(g_420[2][1], 255UL);
printf("index = [%d][%d][%d]\n", i, j, k);
{
                    g_35.f0 |= 0xAF702FE3L;
                }

safe_rshift_func_uint16_t_u_s(65527UL, g_203);


g_40 += 1;


for (g_153 = (-20); (g_153 < 6); g_153 = safe_add_func_int8_t_s_s(g_153, 1))
    {
        uint32_t l_1440 = 0x3482DA34L;
        int32_t l_1452 = 0xB168BE91L;
        for (g_131 = (-16); (g_131 < 1); g_131++)
        {


printf("index = [%d][%d][%d]\n", i, j, k);

        }
safe_rshift_func_int16_t_s_u(g_35.f1, 3);




        p_55 = (((l_1427.f2 = p_53) & (l_1452 &= (g_35.f1 , 0x2C6BL))) , ((safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_s((safe_add_func_int16_t_s_s((~((l_1452 = 0xE489E68586BFF0DDLL) ^ l_1440)), p_53)), (safe_mod_func_int8_t_s_s((0xAA7170BFL && 0x73A17C9BL), (safe_add_func_int32_t_s_s((0xAFL != 0x3BL), l_1440)))))) != p_52), 4)) & p_52));
safe_mod_func_int16_t_s_s(8L, 0x9ED3L);


    };
g_40 += 1;
g_1241 += 1;
safe_mod_func_int64_t_s_s(((((l_1162 , (safe_add_func_uint32_t_u_u(((safe_add_func_uint64_t_u_u((safe_lshift_func_uint16_t_u_u(0x6D2BL, 12)), g_1032[4])) > l_1162), (-1L)))) | g_755[6]) && p_53) < l_1144.f3), p_55);




safe_mod_func_int64_t_s_s((252UL ^ g_251), 0x54EAB2CE98B21CF8LL);




safe_mod_func_uint16_t_u_u((((safe_mod_func_int64_t_s_s(((((l_1162 , (safe_add_func_uint32_t_u_u(((safe_add_func_uint64_t_u_u((safe_lshift_func_uint16_t_u_u(0x6D2BL, 12)), g_1032[4])) > l_1162), (-1L)))) | g_755[6]) && p_53) < l_1144.f3), p_55)) > 0xD8L) <= 0x8A3AA13CL), p_54);




safe_lshift_func_int8_t_s_s(2L, 2);




safe_add_func_int64_t_s_s(g_86, 8);




g_85 -= 1;
for (g_391 = (-7); (g_391 != 54); g_391++)
    {
        struct S0 l_1479 = {0,-1L,935,13};
        l_1427 = (l_1479 = l_1427);
    };


safe_rshift_func_uint8_t_u_s(g_203, 0);
p_54 ^= p_53;


g_85 ^= 0x5D1F78DDL;
g_86 += 1;



safe_mul_func_uint16_t_u_u((~0x02L), 65535UL);




for (g_391 = (-7); (g_391 != 54); g_391++)
    {
        struct S0 l_1479 = {0,-1L,935,13};
        l_1427 = (l_1479 = l_1427);
    };




{
                        g_1145[0] = l_1144;
                    }


safe_add_func_int64_t_s_s((g_131 = p_53), (p_54 ^= p_53));





g_1238 += 1;




{
        int32_t l_1164 = (-2L);
        uint32_t l_1176 = 18446744073709551615UL;
        struct S0 l_1240 = {-0,0L,291,15};
        int32_t l_1360 = 0x5D9D81B5L;
        int32_t l_1362 = 0xBA92A2E7L;
        uint16_t l_1423[2];
        int32_t l_1428 = 0xF2E968EEL;
        int i;


safe_lshift_func_uint8_t_u_u(g_754[2][3], 0);




for (g_391 = (-7); (g_391 != 54); g_391++)
    {
        struct S0 l_1479 = {0,-1L,935,13};
        l_1427 = (l_1479 = l_1427);
    };


        g_755[p_55] = 0x572DDF76L;
p_55 -= 1;




g_1103 += 1;




safe_lshift_func_uint16_t_u_s(65535UL, 9);




g_86 |= 0xFFL;


        l_1428 ^= (safe_sub_func_uint32_t_u_u((func_59((l_1164 = 4294967289UL), g_86, p_55, (((~((((safe_sub_func_uint16_t_u_u(((g_1021[3] , (((((safe_mul_func_int8_t_s_s((g_312 || ((((safe_lshift_func_int8_t_s_u((safe_mul_func_int16_t_s_s((safe_add_func_int32_t_s_s((((l_1144.f2 = ((++g_506) , (safe_rshift_func_int16_t_s_s((0x88DAE7C37C3C3BB9LL != (((l_1240.f2 , (l_1423[0] = l_1144.f3)) >= ((((safe_mod_func_int16_t_s_s(8L, 0x9ED3L)) , 0x7B50B71F29030D9BLL) > g_420[2][1]) && g_85)) , (-7L))), g_1145[0].f0)))) <= l_1360) && 0x89L), g_131)), p_52)), l_1144.f0)) < g_355) , l_1104[3][3][4]) > l_1363)), p_53)) <= g_390) , p_54) & l_1426[0]) || g_2)) & g_594), g_391)) <= g_85) , l_1240.f0) < l_1362)) && g_390) , g_421[3][7][1]), l_1427) , 4294967295UL), p_54));
safe_mod_func_int64_t_s_s(((!((l_1144 , (g_153 = (safe_lshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((+(p_55 , g_154)), 4)), l_1240.f1)))) & 1L)) | p_55), 18446744073709551610UL);


    }
{



safe_mul_func_uint8_t_u_u((~g_388.f1), 0xDAL);


safe_rshift_func_uint16_t_u_u((g_755[5] < ((0x70E0L != (safe_sub_func_uint32_t_u_u((g_755[7] , g_1109), 1UL))) || g_1145[0].f2)), 2);
safe_mod_func_int64_t_s_s(((((l_1162 , (safe_add_func_uint32_t_u_u(((safe_add_func_uint64_t_u_u((safe_lshift_func_uint16_t_u_u(0x6D2BL, 12)), g_1032[4])) > l_1162), (-1L)))) | g_755[6]) && p_53) < l_1144.f3), p_55);


            }
{
        int32_t l_1164 = (-2L);
        uint32_t l_1176 = 18446744073709551615UL;
        struct S0 l_1240 = {-0,0L,291,15};
        int32_t l_1360 = 0x5D9D81B5L;
        int32_t l_1362 = 0xBA92A2E7L;
        uint16_t l_1423[2];
        int32_t l_1428 = 0xF2E968EEL;
        int i;


safe_rshift_func_int16_t_s_s((-1L), 1);


g_1109 ^= (-1L);






safe_unary_minus_func_uint64_t_u((safe_mod_func_int64_t_s_s(((!((l_1144 , (g_153 = (safe_lshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((+(p_55 , g_154)), 4)), l_1240.f1)))) & 1L)) | p_55), 18446744073709551610UL)));




l_1428 ^= (safe_sub_func_uint32_t_u_u((func_59((l_1164 = 4294967289UL), g_86, p_55, (((~((((safe_sub_func_uint16_t_u_u(((g_1021[3] , (((((safe_mul_func_int8_t_s_s((g_312 || ((((safe_lshift_func_int8_t_s_u((safe_mul_func_int16_t_s_s((safe_add_func_int32_t_s_s((((l_1144.f2 = ((++g_506) , (safe_rshift_func_int16_t_s_s((0x88DAE7C37C3C3BB9LL != (((l_1240.f2 , (l_1423[0] = l_1144.f3)) >= ((((safe_mod_func_int16_t_s_s(8L, 0x9ED3L)) , 0x7B50B71F29030D9BLL) > g_420[2][1]) && g_85)) , (-7L))), g_1145[0].f0)))) <= l_1360) && 0x89L), g_131)), p_52)), l_1144.f0)) < g_355) , l_1104[3][3][4]) > l_1363)), p_53)) <= g_390) , p_54) & l_1426[0]) || g_2)) & g_594), g_391)) <= g_85) , l_1240.f0) < l_1362)) && g_390) , g_421[3][7][1]), l_1427) , 4294967295UL), p_54));

{


for (g_391 = (-7); (g_391 != 54); g_391++)
    {
        struct S0 l_1479 = {0,-1L,935,13};
        l_1427 = (l_1479 = l_1427);
    };


crc32_gentab();
safe_lshift_func_uint16_t_u_u(0x6D2BL, 12);




crc32_gentab();



safe_mul_func_int8_t_s_s(g_388.f3, 7UL);


            }


g_40 += 1;




safe_rshift_func_int8_t_s_u(0x7DL, 6);




safe_add_func_int16_t_s_s(g_35.f3, 0x16ABL);


func_59((l_1164 = 4294967289UL), g_86, p_55, (((~((((safe_sub_func_uint16_t_u_u(((g_1021[3] , (((((safe_mul_func_int8_t_s_s((g_312 || ((((safe_lshift_func_int8_t_s_u((safe_mul_func_int16_t_s_s((safe_add_func_int32_t_s_s((((l_1144.f2 = ((++g_506) , (safe_rshift_func_int16_t_s_s((0x88DAE7C37C3C3BB9LL != (((l_1240.f2 , (l_1423[0] = l_1144.f3)) >= ((((safe_mod_func_int16_t_s_s(8L, 0x9ED3L)) , 0x7B50B71F29030D9BLL) > g_420[2][1]) && g_85)) , (-7L))), g_1145[0].f0)))) <= l_1360) && 0x89L), g_131)), p_52)), l_1144.f0)) < g_355) , l_1104[3][3][4]) > l_1363)), p_53)) <= g_390) , p_54) & l_1426[0]) || g_2)) & g_594), g_391)) <= g_85) , l_1240.f0) < l_1362)) && g_390) , g_421[3][7][1]), l_1427);
safe_lshift_func_uint16_t_u_u(0x6D2BL, 12);



safe_lshift_func_int8_t_s_u((0xF0L <= (g_391 = g_559[6])), g_755[3]);


safe_add_func_int64_t_s_s(g_86, 8);
{
                for (g_85 = 0; (g_85 != 0); g_85 = safe_add_func_uint8_t_u_u(g_85, 1))
                {
                    uint32_t l_1437 = 0xA9A030FBL;
                    return l_1437;
                }
            }


safe_rshift_func_uint8_t_u_u((p_52 , (safe_rshift_func_int16_t_s_s(l_1176, 15))), 0);






safe_add_func_uint8_t_u_u(g_159, 8);


{
        int32_t l_1164 = (-2L);
        uint32_t l_1176 = 18446744073709551615UL;
        struct S0 l_1240 = {-0,0L,291,15};
        int32_t l_1360 = 0x5D9D81B5L;
        int32_t l_1362 = 0xBA92A2E7L;
        uint16_t l_1423[2];
        int32_t l_1428 = 0xF2E968EEL;
        int i;


        g_755[p_55] = 0x572DDF76L;
safe_mod_func_int64_t_s_s(1L, p_52);




for (g_391 = (-7); (g_391 != 54); g_391++)
    {
        struct S0 l_1479 = {0,-1L,935,13};
        l_1427 = (l_1479 = l_1427);
    };


        l_1428 ^= (safe_sub_func_uint32_t_u_u((func_59((l_1164 = 4294967289UL), g_86, p_55, (((~((((safe_sub_func_uint16_t_u_u(((g_1021[3] , (((((safe_mul_func_int8_t_s_s((g_312 || ((((safe_lshift_func_int8_t_s_u((safe_mul_func_int16_t_s_s((safe_add_func_int32_t_s_s((((l_1144.f2 = ((++g_506) , (safe_rshift_func_int16_t_s_s((0x88DAE7C37C3C3BB9LL != (((l_1240.f2 , (l_1423[0] = l_1144.f3)) >= ((((safe_mod_func_int16_t_s_s(8L, 0x9ED3L)) , 0x7B50B71F29030D9BLL) > g_420[2][1]) && g_85)) , (-7L))), g_1145[0].f0)))) <= l_1360) && 0x89L), g_131)), p_52)), l_1144.f0)) < g_355) , l_1104[3][3][4]) > l_1363)), p_53)) <= g_390) , p_54) & l_1426[0]) || g_2)) & g_594), g_391)) <= g_85) , l_1240.f0) < l_1362)) && g_390) , g_421[3][7][1]), l_1427) , 4294967295UL), p_54));
    }



{
                    g_35.f0 |= 0xAF702FE3L;
                }






{
                    uint32_t l_1437 = 0xA9A030FBL;
                    return l_1437;
                }
    }
    return g_755[7];
}





static struct S0 func_59(uint32_t p_60, int16_t p_61, uint64_t p_62, uint8_t p_63, struct S0 p_64)
{
    int16_t l_75 = (-1L);
    int32_t l_80 = 0xDA297315L;
    int32_t l_81 = 0xEAE3254CL;
    int32_t l_82 = 0x588CB35BL;
    int64_t l_83 = (-5L);
    int32_t l_84[10][9] = {{0xA6B6B07CL,0xA9E7339AL,(-1L),0xA9E7339AL,0xA6B6B07CL,0xA9E7339AL,(-1L),0xA9E7339AL,0xA6B6B07CL},{0xF4112691L,0xAA3CE9D1L,0xD0B4E555L,0x43A44ADEL,0x43A44ADEL,0xD0B4E555L,0xAA3CE9D1L,0xF4112691L,0xF4112691L},{0xC018302AL,0xA9E7339AL,0xC018302AL,0x01D2D5FAL,0xC018302AL,0xA9E7339AL,0xC018302AL,0x01D2D5FAL,0xC018302AL},{0xF4112691L,0x43A44ADEL,0xAA3CE9D1L,0xAA3CE9D1L,0x43A44ADEL,0xF4112691L,0xD0B4E555L,0xD0B4E555L,0xF4112691L},{0xA6B6B07CL,0x01D2D5FAL,(-1L),0x01D2D5FAL,0xA6B6B07CL,0x01D2D5FAL,(-1L),0x01D2D5FAL,0xA6B6B07CL},{0x43A44ADEL,0xAA3CE9D1L,0xAA3CE9D1L,0x43A44ADEL,0xF4112691L,0xD0B4E555L,0xD0B4E555L,0xF4112691L,0x43A44ADEL},{0xC018302AL,0x01D2D5FAL,0xC018302AL,0xA9E7339AL,0xC018302AL,0x01D2D5FAL,0xC018302AL,0xA9E7339AL,0xC018302AL},{0x43A44ADEL,0x43A44ADEL,0xD0B4E555L,0xAA3CE9D1L,0xF4112691L,0xF4112691L,0xAA3CE9D1L,0xD0B4E555L,0x43A44ADEL},{0xA6B6B07CL,0xA9E7339AL,(-1L),0xA9E7339AL,0xA6B6B07CL,0xA9E7339AL,(-1L),0xA9E7339AL,0xA6B6B07CL},{0xF4112691L,0xAA3CE9D1L,0xD0B4E555L,0x43A44ADEL,0x43A44ADEL,0xD0B4E555L,0xAA3CE9D1L,0xF4112691L,0xF4112691L}};
    struct S0 l_163 = {0,0x74F8CE80C63ED81ALL,-372,13};
    int64_t l_603[2];
    uint64_t l_606 = 0UL;
    uint64_t l_712 = 0xDB55FDE756C50D62LL;
    uint32_t l_716 = 1UL;
    int32_t l_902 = 0x0DED8928L;
    int64_t l_959[4];
    int32_t l_961 = 0L;
    int i, j;

g_1109 ^= (0xFACE4F9578FC59A3LL <= 0x61490D3A8CA6555ALL);




safe_unary_minus_func_int8_t_s((0L < (safe_add_func_int16_t_s_s(g_35.f3, 0x16ABL))));






{


    }






safe_sub_func_int8_t_s_s(0x5CL, (safe_rshift_func_uint16_t_u_u(0xD7EEL, 14)));

g_158 -= 1;



safe_lshift_func_uint16_t_u_s((safe_mul_func_uint8_t_u_u(1UL, (g_420[2][1] < p_64.f3))), p_64.f0);




safe_add_func_int8_t_s_s(g_153, 1);




safe_sub_func_int64_t_s_s(g_153, 1);


g_35.f0 |= 0xAF702FE3L;

safe_lshift_func_int8_t_s_s((p_61 >= p_61), 7);




safe_lshift_func_int16_t_s_u((g_1756[0][0][6] || 0x096AE7FBL), 13);




safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u(((0xFFL && p_61) | g_153), 0)), 0x9350L);




lbl_903:
    for (g_250 = (-5); (g_250 == 28); g_250++)
    {
        int16_t l_604 = 0xB5C8L;
        int32_t l_605 = 0xB57BC166L;
        if (g_355)
            break;
        if (p_62)
            break;
        p_64.f2 = ((p_64.f3 , ((g_158 = 0L) <= (((l_163.f2 && ((g_559[7] && (g_388.f0 = g_86)) < (safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u(((0xFFL && p_61) | g_153), 0)), 0x9350L)), l_163.f1)))) != 5L) | p_62))) && l_75);
        l_606--;
    }


safe_lshift_func_int16_t_s_u((safe_add_func_uint64_t_u_u(18446744073709551608UL, (l_84[1][0] >= ((safe_sub_func_uint8_t_u_u(((safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s((((safe_lshift_func_uint8_t_u_u((((safe_mul_func_int16_t_s_s(p_64.f1, (safe_mul_func_int8_t_s_s((safe_add_func_int8_t_s_s(g_40, (g_594 = ((safe_add_func_uint8_t_u_u((~l_163.f1), g_153)) > 0x3B4629F6L)))), p_62)))) , 0x2DE3A813L) && l_81), g_355)) > 0x41687DFAAF6EBBA7LL) < (-10L)), g_131)), l_163.f3)) , l_81), 1L)) , 0x3674L)))), g_355);


safe_add_func_uint8_t_u_u(g_355, 1);

safe_lshift_func_uint8_t_u_u(g_754[2][3], 0);







if (g_316)
                goto lbl_903;
safe_sub_func_uint8_t_u_u(247UL, 0x85L);
safe_lshift_func_int8_t_s_s((-4L), 5);


safe_unary_minus_func_int8_t_s((0L < (safe_add_func_int16_t_s_s(g_35.f3, 0x16ABL))));


g_251 += 1;


safe_unary_minus_func_uint32_t_u(1UL);


if (g_316)
                goto lbl_903;



safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s((((safe_lshift_func_uint8_t_u_u((((safe_mul_func_int16_t_s_s(p_64.f1, (safe_mul_func_int8_t_s_s((safe_add_func_int8_t_s_s(g_40, (g_594 = ((safe_add_func_uint8_t_u_u((~l_163.f1), g_153)) > 0x3B4629F6L)))), p_62)))) , 0x2DE3A813L) && l_81), g_355)) > 0x41687DFAAF6EBBA7LL) < (-10L)), g_131)), l_163.f3);



safe_unary_minus_func_int16_t_s((g_506 <= (g_388.f1 < g_420[1][5])));


    return p_64;
}





static int32_t func_66(uint16_t p_67, struct S0 p_68)
{
    uint32_t l_168 = 0x3F8D3DCDL;
    int8_t l_179[1][2];
    int64_t l_185 = (-7L);
    int32_t l_228 = 0x185051ADL;
    int32_t l_230 = 0x647FE7AAL;
    uint32_t l_268 = 0x20F4CF03L;
    int16_t l_359 = (-6L);
    int32_t l_473 = 0xDCCA3664L;
    int32_t l_510 = 0L;
    int32_t l_512[1][3][8];
    uint16_t l_544 = 6UL;
    int64_t l_551 = 6L;
    int32_t l_560 = 0x0C92ECC8L;
    struct S0 l_567[2][6][5] = {{{{-0,0x71786727EA7006D1LL,552,9},{0,0x42C4DEBBA0133BA3LL,-707,0},{0,0x8519C44ADFC325C0LL,30,11},{0,0L,262,3},{-0,0L,-471,1}},{{-0,-10L,122,9},{-0,0x71786727EA7006D1LL,552,9},{0,5L,628,13},{-0,0L,-471,1},{-0,0xC86EFBAF48BD29F1LL,-736,6}},{{0,1L,478,4},{0,0x8519C44ADFC325C0LL,30,11},{-0,0L,-471,1},{0,0x42C4DEBBA0133BA3LL,-707,0},{-0,0L,-471,1}},{{-0,0L,-471,1},{-0,0L,-471,1},{-0,-1L,-604,9},{0,5L,628,13},{0,-1L,-35,12}},{{-0,0L,-471,1},{-0,7L,693,13},{0,-1L,-35,12},{0,0xD0D1A3F0EE69D5CDLL,-352,14},{0,-3L,-677,2}},{{0,1L,478,4},{0,0x7C6C453A6D93444DLL,535,5},{-0,0xC86EFBAF48BD29F1LL,-736,6},{-0,0L,-902,5},{0,0L,262,3}}},{{{-0,-10L,122,9},{-0,7L,693,13},{-0,7L,693,13},{-0,-10L,122,9},{-0,1L,344,2}},{{-0,0x71786727EA7006D1LL,552,9},{-0,0L,-471,1},{-0,7L,693,13},{0,-1L,-35,12},{0,0xD0D1A3F0EE69D5CDLL,-352,14}},{{0,-1L,-35,12},{0,0x8519C44ADFC325C0LL,30,11},{-0,0xC86EFBAF48BD29F1LL,-736,6},{0,1L,478,4},{-0,7L,693,13}},{{0,0x7C6C453A6D93444DLL,535,5},{-0,0x71786727EA7006D1LL,552,9},{0,-1L,-35,12},{0,-1L,-35,12},{-0,0x71786727EA7006D1LL,552,9}},{{0,-3L,-677,2},{0,0x42C4DEBBA0133BA3LL,-707,0},{-0,-1L,-604,9},{-0,-10L,122,9},{-0,0x71786727EA7006D1LL,552,9}},{{0,0x8519C44ADFC325C0LL,30,11},{0,0L,262,3},{-0,0L,-471,1},{-0,0L,-902,5},{-0,7L,693,13}}}};
    int i, j, k;

safe_add_func_uint8_t_u_u(0xBEL, 253UL);


printf("index = [%d][%d][%d]\n", i, j, k);
safe_add_func_uint8_t_u_u(g_85, 1);






safe_rshift_func_int8_t_s_u(((safe_lshift_func_uint16_t_u_u(g_158, 12)) == 0x70B449B74578E65ALL), 2);






{


                    }


safe_rshift_func_uint16_t_u_u((g_755[5] < ((0x70E0L != (safe_sub_func_uint32_t_u_u((g_755[7] , g_1109), 1UL))) || g_1145[0].f2)), 2);




safe_unary_minus_func_int8_t_s((safe_mul_func_uint16_t_u_u(1UL, 0x5E27L)));



for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 8; k++)
                l_512[i][j][k] = 0x3331D5D9L;
        };


safe_rshift_func_uint16_t_u_u(0xD7EEL, 14);
safe_rshift_func_int8_t_s_u(((safe_lshift_func_uint16_t_u_u(g_158, 12)) == 0x70B449B74578E65ALL), 2);





safe_unary_minus_func_int8_t_s((0L < (safe_add_func_int16_t_s_s(g_35.f3, 0x16ABL))));
g_506 &= 0x387E3CDF10492640LL;
func_22(g_35.f3);


safe_rshift_func_uint8_t_u_s(g_203, 0);
safe_rshift_func_uint8_t_u_u(0xACL, 1);


safe_lshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(g_388.f0, 0xD95D3B69L)), (g_1032[4] , 0x46L));


safe_unary_minus_func_int8_t_s((safe_mul_func_uint16_t_u_u(1UL, 0x5E27L)));




safe_mod_func_int16_t_s_s(8L, 0x9ED3L);
safe_lshift_func_int8_t_s_s(l_544, 6);


safe_lshift_func_uint8_t_u_u(g_754[2][3], 0);
safe_add_func_uint8_t_u_u(g_85, 1);



safe_add_func_uint8_t_u_u(0xBEL, 253UL);


l_168 += 1;




g_86 |= 0xFFL;




safe_mod_func_int64_t_s_s((252UL ^ g_251), 0x54EAB2CE98B21CF8LL);






{


                    }







g_251 += 1;
safe_mul_func_int8_t_s_s(g_388.f3, 7UL);







safe_mod_func_int64_t_s_s((252UL ^ g_251), 0x54EAB2CE98B21CF8LL);



safe_lshift_func_uint8_t_u_u(l_168, 7);



printf("index = [%d]\n", i);


safe_lshift_func_int8_t_s_s(2L, 2);




g_251 += 1;


{


safe_lshift_func_int8_t_s_u((0xF0L <= (g_391 = g_559[6])), g_755[3]);


safe_add_func_uint8_t_u_u(g_355, 1);
for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 2; j++)
            l_179[i][j] = 0x69L;
    };




printf("index = [%d][%d]\n", i, j);



safe_rshift_func_int8_t_s_u(((0xBAD58878L < 7UL) != g_594), 4);


safe_mod_func_uint64_t_u_u((0x720FL == 0x14D4L), 0x1E7B790C5A96D6B6LL);
printf("index = [%d][%d][%d]\n", i, j, k);


{
                        g_35.f0 ^= (g_35.f2 = ((g_250 > (p_68.f3 , l_228)) , ((safe_rshift_func_uint8_t_u_u((6UL != g_158), p_68.f1)) < ((safe_sub_func_uint16_t_u_u(((safe_mul_func_uint8_t_u_u(l_230, (g_391 |= (g_312++)))) != g_35.f2), ((g_35.f1 || 0xCB7D202A44838C9CLL) <= p_68.f3))) , g_356))));
                    }

                }


func_78((++g_86));


safe_sub_func_uint8_t_u_u(9UL, (safe_mul_func_int8_t_s_s((safe_mul_func_uint16_t_u_u((p_68.f2 <= 0x35C9L), l_230)), g_40)));

printf("index = [%d]\n", i);


safe_lshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(g_388.f0, 0xD95D3B69L)), (g_1032[4] , 0x46L));

g_40 += 1;




for (k = 0; k < 8; k++)
                l_512[i][j][k] = 0x3331D5D9L;


g_1304 += 1;






safe_rshift_func_uint16_t_u_s(g_250, 12);


safe_lshift_func_uint16_t_u_s(g_35.f3, 14);
safe_mul_func_int8_t_s_s(g_2, 251UL);




safe_mod_func_int16_t_s_s(8L, 0x9ED3L);




    return p_67;
}





static int32_t func_71(uint8_t p_72, uint32_t p_73, uint32_t p_74)
{
    int32_t l_145 = 1L;
    int32_t l_148[4];
    int32_t l_151[6] = {(-1L),0x6C71F3ECL,0x6C71F3ECL,(-1L),0x6C71F3ECL,0x6C71F3ECL};
    int32_t l_152 = 0xF6C6AD03L;
    int32_t l_155 = 3L;
    int8_t l_162 = 0x2DL;
    int i;







{

safe_lshift_func_int8_t_s_u((0xF0L <= (g_391 = g_559[6])), g_755[3]);
g_35.f0 |= 0xAF702FE3L;

    }

safe_rshift_func_int8_t_s_s(g_250, 5);


{


crc32_gentab();

                    }
g_251 += 1;
g_388.f1 -= 1;


safe_unary_minus_func_uint64_t_u(0xA46D5F4F3D787CA5LL);




g_506 &= 0x387E3CDF10492640LL;


safe_mod_func_uint8_t_u_u(func_78((++g_86)), g_85);

safe_unary_minus_func_uint8_t_u(g_754[1][9]);




safe_unary_minus_func_int16_t_s((g_506 <= (g_388.f1 < g_420[1][5])));




g_388.f1 -= 1;



g_355 += 1;



safe_add_func_uint64_t_u_u((safe_lshift_func_uint16_t_u_u(0x6D2BL, 12)), g_1032[4]);



{
        g_35.f2 = (65535UL ^ (safe_lshift_func_uint16_t_u_s(g_35.f3, 14)));
    }

safe_rshift_func_int16_t_s_u(0x1823L, 11);


safe_lshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(g_388.f0, 0xD95D3B69L)), (g_1032[4] , 0x46L));


safe_add_func_uint8_t_u_u(g_355, 1);


safe_mul_func_int8_t_s_s(g_388.f3, 7UL);

g_1985 -= 1;



safe_mul_func_int8_t_s_s((0L > g_391), (-9L));




g_159 += 1;




g_158 -= 1;






g_86 += 1;


safe_mul_func_uint16_t_u_u(1UL, 0x5E27L);
for (i = 0; i < 4; i++)
        {


safe_mul_func_int8_t_s_s((safe_lshift_func_int8_t_s_s((g_154 = ((g_153 = (((safe_sub_func_uint32_t_u_u(p_74, 0x0C8DCDBDL)) != (safe_add_func_int64_t_s_s((g_35.f3 , (safe_lshift_func_uint8_t_u_u(l_145, ((l_152 = ((g_131 , l_145) , (l_151[5] = (safe_add_func_int8_t_s_s((l_148[1] = 0L), ((p_73 & (safe_sub_func_uint32_t_u_u(0xA808B72AL, 0x6805FA10L))) > 3L)))))) ^ p_73)))), 8UL))) , 0xC672L)) > g_35.f2)), l_145)), 0x5DL);
g_391 |= (g_312++);




}
g_251 += 1;


l_155 |= (g_85 = (safe_mul_func_int8_t_s_s((safe_lshift_func_int8_t_s_s((g_154 = ((g_153 = (((safe_sub_func_uint32_t_u_u(p_74, 0x0C8DCDBDL)) != (safe_add_func_int64_t_s_s((g_35.f3 , (safe_lshift_func_uint8_t_u_u(l_145, ((l_152 = ((g_131 , l_145) , (l_151[5] = (safe_add_func_int8_t_s_s((l_148[1] = 0L), ((p_73 & (safe_sub_func_uint32_t_u_u(0xA808B72AL, 0x6805FA10L))) > 3L)))))) ^ p_73)))), 8UL))) , 0xC672L)) > g_35.f2)), l_145)), 0x5DL)));


g_86 += 1;




{


g_85 ^= 0x5D1F78DDL;

        return g_131;
    }


safe_add_func_int32_t_s_s(g_355, 2);
safe_rshift_func_int16_t_s_u((g_594 = 0x925BL), 6);
safe_add_func_int64_t_s_s((g_35.f3 , (safe_lshift_func_uint8_t_u_u(l_145, ((l_152 = ((g_131 , l_145) , (l_151[5] = (safe_add_func_int8_t_s_s((l_148[1] = 0L), ((p_73 & (safe_sub_func_uint32_t_u_u(0xA808B72AL, 0x6805FA10L))) > 3L)))))) ^ p_73)))), 8UL);


safe_lshift_func_uint8_t_u_u(l_145, ((l_152 = ((g_131 , l_145) , (l_151[5] = (safe_add_func_int8_t_s_s((l_148[1] = 0L), ((p_73 & (safe_sub_func_uint32_t_u_u(0xA808B72AL, 0x6805FA10L))) > 3L)))))) ^ p_73));


safe_unary_minus_func_uint8_t_u(g_754[1][9]);




safe_lshift_func_int16_t_s_u((g_1756[0][0][6] || 0x096AE7FBL), 13);




safe_sub_func_int8_t_s_s(0x5CL, (safe_rshift_func_uint16_t_u_u(0xD7EEL, 14)));


safe_unary_minus_func_uint16_t_u(((((((safe_rshift_func_int16_t_s_u(g_35.f1, 3)) & g_356) , 8L) ^ 4294967295UL) <= g_159) != g_312));
safe_lshift_func_int8_t_s_s((g_154 = ((g_153 = (((safe_sub_func_uint32_t_u_u(p_74, 0x0C8DCDBDL)) != (safe_add_func_int64_t_s_s((g_35.f3 , (safe_lshift_func_uint8_t_u_u(l_145, ((l_152 = ((g_131 , l_145) , (l_151[5] = (safe_add_func_int8_t_s_s((l_148[1] = 0L), ((p_73 & (safe_sub_func_uint32_t_u_u(0xA808B72AL, 0x6805FA10L))) > 3L)))))) ^ p_73)))), 8UL))) , 0xC672L)) > g_35.f2)), l_145);
    return g_85;
}





static uint8_t func_78(uint32_t p_79)
{
    int8_t l_93 = 0xFCL;
    uint32_t l_94 = 0xE62B9925L;
    uint8_t l_95 = 1UL;
    int32_t l_96 = 0x683588D2L;
    int32_t l_105 = 0x05D52AEBL;
    int64_t l_124[9] = {0x184C74488338C196LL,0x184C74488338C196LL,0x184C74488338C196LL,0x184C74488338C196LL,0x184C74488338C196LL,0x184C74488338C196LL,0x184C74488338C196LL,0x184C74488338C196LL,0x184C74488338C196LL};
    int i;


safe_unary_minus_func_uint64_t_u(0xA46D5F4F3D787CA5LL);


for (g_159 = 0; (g_159 <= 3); g_159 += 1)
                {


                    return g_754[4][9];
                };



safe_lshift_func_uint16_t_u_s(65535UL, 9);



safe_unary_minus_func_uint16_t_u((safe_mul_func_uint8_t_u_u(((8UL ^ g_388.f3) , 0xF4L), 0x13L)));


if ((safe_unary_minus_func_uint16_t_u(((l_105 = l_94) , p_79))))
    {
        return p_79;
    }
    else
    {
        l_96 = 0xA4836ABEL;
    };
safe_rshift_func_uint16_t_u_u((g_755[5] < ((0x70E0L != (safe_sub_func_uint32_t_u_u((g_755[7] , g_1109), 1UL))) || g_1145[0].f2)), 2);




safe_rshift_func_uint16_t_u_u(0xD7EEL, 14);




safe_add_func_int16_t_s_s(g_35.f3, 0x16ABL);






safe_mod_func_uint8_t_u_u(g_153, 0x1FL);


g_159 += 1;
g_86 += 1;
safe_mod_func_uint8_t_u_u(func_78((++g_86)), g_85);

g_159 += 1;




safe_lshift_func_int16_t_s_u((g_1756[0][0][6] || 0x096AE7FBL), 13);





safe_rshift_func_uint8_t_u_s(g_203, 0);


{


{
                        g_85 ^= 0x5D1F78DDL;
                    }

                }

safe_mod_func_int16_t_s_s(8L, 0x9ED3L);


{

safe_lshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(g_388.f0, 0xD95D3B69L)), (g_1032[4] , 0x46L));


    }

safe_rshift_func_uint8_t_u_u(0xACL, 1);




safe_unary_minus_func_uint64_t_u(0xA46D5F4F3D787CA5LL);


safe_rshift_func_int8_t_s_s(g_250, 5);


    return g_40;
}

int main (void)
{
    int i, j, k;
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_35.f0, "g_35.f0", print_hash_value);
    transparent_crc(g_35.f1, "g_35.f1", print_hash_value);
    transparent_crc(g_35.f2, "g_35.f2", print_hash_value);
    transparent_crc(g_35.f3, "g_35.f3", print_hash_value);
    transparent_crc(g_40, "g_40", print_hash_value);
    transparent_crc(g_85, "g_85", print_hash_value);
    transparent_crc(g_86, "g_86", print_hash_value);
    transparent_crc(g_131, "g_131", print_hash_value);
    transparent_crc(g_153, "g_153", print_hash_value);
    transparent_crc(g_154, "g_154", print_hash_value);
    transparent_crc(g_158, "g_158", print_hash_value);
    transparent_crc(g_159, "g_159", print_hash_value);
    transparent_crc(g_203, "g_203", print_hash_value);
    transparent_crc(g_250, "g_250", print_hash_value);
    transparent_crc(g_251, "g_251", print_hash_value);
    transparent_crc(g_312, "g_312", print_hash_value);
    transparent_crc(g_316, "g_316", print_hash_value);
    transparent_crc(g_355, "g_355", print_hash_value);
    transparent_crc(g_356, "g_356", print_hash_value);
    transparent_crc(g_388.f0, "g_388.f0", print_hash_value);
    transparent_crc(g_388.f1, "g_388.f1", print_hash_value);
    transparent_crc(g_388.f2, "g_388.f2", print_hash_value);
    transparent_crc(g_388.f3, "g_388.f3", print_hash_value);
    transparent_crc(g_390, "g_390", print_hash_value);
    transparent_crc(g_391, "g_391", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 10; j++)
        {
            transparent_crc(g_420[i][j], "g_420[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 5; k++)
            {
                transparent_crc(g_421[i][j][k], "g_421[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    transparent_crc(g_506, "g_506", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_559[i], "g_559[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_594, "g_594", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 6; j++)
        {
            for (k = 0; k < 1; k++)
            {
                transparent_crc(g_750[i][j][k], "g_750[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 10; j++)
        {
            transparent_crc(g_754[i][j], "g_754[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_755[i], "g_755[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    for (i = 0; i < 5; i++)
    {
        transparent_crc(g_1021[i], "g_1021[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_1031, "g_1031", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_1032[i], "g_1032[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_1103, "g_1103", print_hash_value);
    transparent_crc(g_1109, "g_1109", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_1145[i].f0, "g_1145[i].f0", print_hash_value);
        transparent_crc(g_1145[i].f1, "g_1145[i].f1", print_hash_value);
        transparent_crc(g_1145[i].f2, "g_1145[i].f2", print_hash_value);
        transparent_crc(g_1145[i].f3, "g_1145[i].f3", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_1238, "g_1238", print_hash_value);
    transparent_crc(g_1241, "g_1241", print_hash_value);
    transparent_crc(g_1304, "g_1304", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 7; j++)
        {
            transparent_crc(g_1732[i][j], "g_1732[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 1; j++)
        {
            for (k = 0; k < 10; k++)
            {
                transparent_crc(g_1756[i][j][k], "g_1756[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    transparent_crc(g_1935, "g_1935", print_hash_value);
    transparent_crc(g_1985, "g_1985", print_hash_value);
    transparent_crc(g_2138, "g_2138", print_hash_value);
    transparent_crc(g_2239, "g_2239", print_hash_value);
    transparent_crc(g_2299, "g_2299", print_hash_value);
    transparent_crc(g_2300, "g_2300", print_hash_value);
    transparent_crc(g_2342, "g_2342", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

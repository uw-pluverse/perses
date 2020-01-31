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


static int32_t g_3 = 0xB2006887L;
static uint32_t g_4 = 0x80BFB3A4L;
static uint32_t g_57 = 0x8275BAEDL;
static int8_t g_75 = 0L;
static int8_t g_106 = 0x88L;
static uint32_t g_139 = 0x79D400EAL;
static uint32_t g_144 = 0x10C71A7AL;
static int16_t g_161 = 0x23A9L;
static int64_t g_162[6][5][1] = {{{(-9L)},{1L},{(-1L)},{0xB88CA99809853766LL},{(-1L)}},{{1L},{(-9L)},{1L},{(-1L)},{0xB88CA99809853766LL}},{{(-1L)},{1L},{(-9L)},{1L},{(-1L)}},{{0xB88CA99809853766LL},{(-1L)},{1L},{(-9L)},{1L}},{{(-1L)},{0xB88CA99809853766LL},{(-1L)},{1L},{(-9L)}},{{1L},{(-1L)},{0xB88CA99809853766LL},{(-1L)},{1L}}};
static uint32_t g_164 = 0x125FC94FL;
static int64_t g_170 = 0xB2E1E59718C347C6LL;
static uint16_t g_175[1][3] = {{0xB83BL,0xB83BL,0xB83BL}};
static int32_t g_177 = 0x1CE45A5EL;
static int64_t g_180 = 0x037CA2DBAE0E4194LL;
static uint32_t g_224 = 18446744073709551615UL;
static int16_t g_253 = 0x669AL;
static int8_t g_281 = 1L;
static int32_t g_284 = 0xC5FA31A8L;
static uint64_t g_301 = 18446744073709551609UL;
static int64_t g_311 = 0x1D3FF564315EF98ALL;
static int8_t g_312 = 0x66L;
static int16_t g_329[4] = {0L,0L,0L,0L};
static int16_t g_332 = 0x9F77L;
static int64_t g_361 = 2L;
static int32_t g_381 = 0x83098027L;
static int32_t g_459 = 0x30A7D56AL;
static uint8_t g_462 = 0x3BL;
static uint64_t g_552 = 18446744073709551614UL;
static uint8_t g_777 = 1UL;
static int32_t g_810 = 0x61BF8A8EL;
static uint32_t g_836 = 0x995B2178L;
static int16_t g_877 = 1L;
static int32_t g_923 = 0xD9003AB3L;
static int16_t g_977 = 1L;
static uint8_t g_991 = 249UL;
static int32_t g_1039 = 0xEF062AE5L;
static int32_t g_1118[1] = {0L};
static uint64_t g_1147 = 0x7BAAE86401010370LL;
static uint32_t g_1284[1] = {0xA7AD44D3L};
static uint64_t g_1293[8][3] = {{0x7E5A06C1A9C55C5ALL,0x7E5A06C1A9C55C5ALL,0x7E5A06C1A9C55C5ALL},{0x742FB213869889FCLL,0x742FB213869889FCLL,0x742FB213869889FCLL},{0x7E5A06C1A9C55C5ALL,0x7E5A06C1A9C55C5ALL,0x7E5A06C1A9C55C5ALL},{0x742FB213869889FCLL,0x742FB213869889FCLL,0x742FB213869889FCLL},{0x7E5A06C1A9C55C5ALL,0x7E5A06C1A9C55C5ALL,0x7E5A06C1A9C55C5ALL},{0x742FB213869889FCLL,0x742FB213869889FCLL,0x742FB213869889FCLL},{0x7E5A06C1A9C55C5ALL,0x7E5A06C1A9C55C5ALL,0x7E5A06C1A9C55C5ALL},{0x742FB213869889FCLL,0x742FB213869889FCLL,0x742FB213869889FCLL}};
static int16_t g_1434 = 3L;
static const int32_t g_1501 = 0L;
static int8_t g_1589 = 7L;
static uint8_t g_1701[5] = {0UL,0UL,0UL,0UL,0UL};
static int32_t g_1717[6] = {(-1L),(-1L),(-1L),(-1L),(-1L),(-1L)};
static int64_t g_1735[4] = {0L,0L,0L,0L};
static int16_t g_1756 = 0x107DL;
static int8_t g_2063[2][10] = {{0x88L,1L,0x88L,0x88L,1L,0x88L,0x88L,1L,0x88L,0x88L},{1L,1L,4L,1L,1L,4L,1L,1L,4L,1L}};
static int64_t g_2158 = 0xB6925F978A47DC55LL;
static int8_t g_2188 = 0xF2L;
static int32_t g_2228 = 0x516B0020L;
static uint32_t g_2236 = 0x4F333AFEL;
static uint32_t g_2247 = 0x8085FFE9L;
static uint32_t g_2424[6][2][3] = {{{0x4B63432BL,18446744073709551615UL,7UL},{6UL,18446744073709551615UL,0x174C4646L}},{{0UL,0x2E164FDEL,0x3049CF58L},{0x44BD1C72L,0UL,0UL}},{{0UL,8UL,0UL},{6UL,0x2EB20443L,0UL}},{{0x4B63432BL,0UL,0UL},{18446744073709551615UL,0x174C4646L,0x3049CF58L}},{{0UL,0UL,0x174C4646L},{0x2E164FDEL,0x2EB20443L,7UL}},{{0x2E164FDEL,8UL,18446744073709551615UL},{0UL,0UL,0x2EB20443L}}};
static int16_t g_2426 = (-3L);
static uint64_t g_2427 = 18446744073709551615UL;
static uint64_t g_2452 = 18446744073709551614UL;
static int32_t g_2465 = 2L;
static uint32_t g_2764 = 0x046A17DAL;
static int64_t g_2806[4] = {0x7F419F4420CCC24DLL,0x7F419F4420CCC24DLL,0x7F419F4420CCC24DLL,0x7F419F4420CCC24DLL};
static uint64_t g_2811 = 9UL;

inline static int32_t func_1(void);
inline static int8_t func_11(uint8_t p_12);
inline static uint8_t func_13(uint64_t p_14, uint16_t p_15);
static int32_t func_18(uint8_t p_19, int16_t p_20, int16_t p_21);
static uint8_t func_26(uint8_t p_27, uint32_t p_28, int32_t p_29, const uint16_t p_30);
static int16_t func_39(int32_t p_40, int32_t p_41, uint8_t p_42, int16_t p_43, uint64_t p_44);
inline static int32_t func_45(int32_t p_46, uint8_t p_47, uint32_t p_48, const int16_t p_49, int16_t p_50);
inline static uint64_t func_55(int8_t p_56);
static uint8_t func_62(int32_t p_63);
static int16_t func_71(int32_t p_72, int64_t p_73);






inline static int32_t func_1(void)
{
    uint8_t l_2[6][6][4] = {{{0x73L,0xF0L,255UL,1UL},{0xF1L,1UL,0xACL,249UL},{9UL,1UL,0UL,0x48L},{0xD9L,0x79L,1UL,0x79L},{0x96L,0xF1L,0x96L,0UL},{0UL,0xD9L,0xF1L,0xACL}},{{255UL,0x71L,0x48L,0xD9L},{0x07L,0xDFL,0x48L,255UL},{255UL,0x13L,0xF1L,0x29L},{0UL,0x73L,0x96L,0xE6L},{0x96L,0xE6L,1UL,0x13L},{0xD9L,0x07L,0UL,0UL}},{{9UL,9UL,0xACL,0x73L},{0xF1L,0UL,255UL,1UL},{0x73L,0x29L,249UL,255UL},{0xACL,0x29L,0xDFL,1UL},{0x29L,0UL,0x07L,0x73L},{0x65L,9UL,1UL,0UL}},{{249UL,0x07L,0x79L,0x13L},{1UL,0xE6L,0UL,0xE6L},{255UL,0x73L,0x13L,0x29L},{6UL,0x13L,0x79L,255UL},{0xE6L,0xDFL,255UL,0xD9L},{0xE6L,0x71L,0x79L,0xACL}},{{6UL,0xD9L,0x13L,0xDFL},{255UL,249UL,0x79L,0x48L},{0xF0L,0x29L,0x48L,255UL},{1UL,0xF0L,0xF0L,1UL},{0x13L,0x65L,0UL,0xD9L},{0x79L,0UL,0xF1L,255UL}},{{9UL,0x48L,1UL,255UL},{6UL,0UL,255UL,0xD9L},{249UL,0x65L,9UL,1UL},{0x6EL,0xF0L,1UL,255UL},{0xE6L,0x29L,0x65L,0x48L},{255UL,249UL,255UL,0xDFL}}};
    int32_t l_2186 = (-1L);
    int8_t l_2201 = 0x50L;
    const uint8_t l_2225 = 251UL;
    uint64_t l_2229 = 18446744073709551615UL;
    int64_t l_2248[7][8] = {{0xE4E3F1305A78625BLL,5L,0xE14B505BA6A4220ALL,0L,0xF1FFA7ED4D98AF90LL,8L,0xF1FFA7ED4D98AF90LL,0L},{0x9001A873716AA46BLL,1L,0x9001A873716AA46BLL,0L,0L,8L,0xE14B505BA6A4220ALL,0xE14B505BA6A4220ALL},{0xE14B505BA6A4220ALL,5L,0xE4E3F1305A78625BLL,0xE4E3F1305A78625BLL,5L,0xE14B505BA6A4220ALL,0L,0xF1FFA7ED4D98AF90LL},{0xE14B505BA6A4220ALL,0L,0x641CB0C0720394A4LL,5L,0L,5L,0x641CB0C0720394A4LL,0L},{0x9001A873716AA46BLL,0x641CB0C0720394A4LL,8L,5L,0xF1FFA7ED4D98AF90LL,0L,0L,0xF1FFA7ED4D98AF90LL},{0xE4E3F1305A78625BLL,0xF1FFA7ED4D98AF90LL,0xF1FFA7ED4D98AF90LL,0xE4E3F1305A78625BLL,0x9001A873716AA46BLL,0L,0L,0xE14B505BA6A4220ALL},{0x641CB0C0720394A4LL,0xE4E3F1305A78625BLL,8L,0L,8L,0xE4E3F1305A78625BLL,0x641CB0C0720394A4LL,0L}};
    int16_t l_2328 = 0xE04DL;
    uint32_t l_2441 = 0x64BB7317L;
    uint32_t l_2464[7][6][4] = {{{4294967295UL,1UL,0x46A0EF4CL,4294967292UL},{0x2A9AC9EAL,0xF25C2B17L,0x9151123EL,0UL},{0xF42A1EF4L,6UL,4294967295UL,1UL},{0UL,0x1232699FL,0x03E5E20EL,0xF25C2B17L},{1UL,0x03F43EB9L,4294967292UL,4294967295UL},{0x82FCA927L,3UL,1UL,0x27B2D45DL}},{{0x03F43EB9L,0UL,0UL,4294967294UL},{1UL,0xF42A1EF4L,0x50DAB6E2L,0x39315210L},{0x39315210L,0xF25C2B17L,4294967295UL,4294967287UL},{3UL,0UL,4294967295UL,0x472E7175L},{9UL,0xEDADAE61L,0x82FCA927L,0xB6471114L},{1UL,0UL,3UL,4294967292UL}},{{0x39850C37L,0x74923AB5L,0UL,4294967295UL},{0x5F23729EL,1UL,4294967295UL,4294967294UL},{0xE56C5158L,0UL,0x46A0EF4CL,4294967295UL},{4294967288UL,0x03F43EB9L,1UL,0x03F43EB9L},{4294967292UL,0x03E5E20EL,4294967295UL,0x56D2D227L},{0x03F43EB9L,0x1232699FL,0x39850C37L,9UL}},{{0UL,0x5F23729EL,0xF42A1EF4L,0x39315210L},{0UL,0x74923AB5L,0x39850C37L,4294967295UL},{0x03F43EB9L,0x39315210L,4294967295UL,0xA6E468EDL},{4294967292UL,0x786DFA08L,1UL,2UL},{4294967288UL,6UL,0x786DFA08L,0x1232699FL},{1UL,0x39315210L,0x50DAB6E2L,0xF42A1EF4L}},{{0UL,2UL,1UL,4294967295UL},{8UL,1UL,4294967293UL,4294967295UL},{0x2A9AC9EAL,4294967293UL,4294967295UL,0xC71981A2L},{4294967295UL,2UL,4294967295UL,0x9151123EL},{4294967293UL,4294967289UL,4294967292UL,0x27B2D45DL},{0UL,0UL,0x0C5BF5C5L,6UL}},{{0xB9CB22E3L,0x39315210L,1UL,0UL},{0xEDADAE61L,1UL,0x2A9AC9EAL,0x03E5E20EL},{4294967295UL,0xC3749F1AL,0UL,0xF0D9632DL},{0x2A9AC9EAL,0xB9CB22E3L,4UL,0x9CCAE56CL},{0x82FCA927L,4294967295UL,0x50DAB6E2L,0x50DAB6E2L},{1UL,1UL,0xF42A1EF4L,0x27B2D45DL}},{{4294967294UL,1UL,0x786DFA08L,0UL},{0xAFC1573AL,4UL,0x56D2D227L,0x786DFA08L},{4294967295UL,4UL,0x2A9AC9EAL,0UL},{4UL,1UL,1UL,0x27B2D45DL},{1UL,1UL,2UL,0x50DAB6E2L},{6UL,4294967295UL,1UL,0x9CCAE56CL}}};
    uint64_t l_2536 = 0UL;
    int32_t l_2554 = 1L;
    int32_t l_2555 = 0xB170D9C6L;
    uint16_t l_2556 = 0x09BDL;
    int64_t l_2585 = (-5L);
    uint8_t l_2587 = 0xFCL;
    uint64_t l_2634 = 0x624A497F8BEAF9BDLL;
    int8_t l_2644 = 0L;
    int8_t l_2645 = 0xA0L;
    int32_t l_2810 = 1L;
    int16_t l_2812 = 0L;
    uint64_t l_2930[3];
    uint32_t l_2933 = 0x86A70711L;
    uint8_t l_3009 = 0x35L;
    uint16_t l_3032 = 1UL;
    int i, j, k;
    for (i = 0; i < 3; i++)
        l_2930[i] = 18446744073709551608UL;
    for (g_3 = 3; (g_3 >= 0); g_3 -= 1)
    {
        uint16_t l_22 = 0xDB88L;
        int64_t l_2187 = 1L;
        int8_t l_2192 = (-1L);
        uint64_t l_2200 = 5UL;
        int32_t l_2226 = 0xAAC61ADCL;
        int32_t l_2271 = 1L;
        int32_t l_2272 = 0xC7594353L;
        uint8_t l_2288 = 0x6EL;
        const uint8_t l_2364 = 0x33L;
        int16_t l_2466 = 0xBBA4L;
        g_4 = (18446744073709551607UL ^ g_3);
        g_2188 = ((safe_add_func_int32_t_s_s(((((safe_lshift_func_uint8_t_u_s((l_2[4][4][3] , (((l_2186 = (safe_rshift_func_int8_t_s_u(((func_11(func_13((safe_sub_func_int32_t_s_s(func_18(g_4, l_22, l_22), (!0xB607800FL))), g_3)) & 252UL) < 7UL), l_22))) ^ g_1118[0]) && l_2187)), 6)) < l_2[0][3][0]) & 8L) , (-4L)), 0xE463EC33L)) <= g_1118[0]);
        if (((~((l_22 || (g_991 == ((safe_sub_func_int32_t_s_s(((l_2192 , ((+l_2[5][4][0]) < g_253)) == g_836), (l_2201 = (safe_lshift_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(65535UL, (-1L))), ((((safe_sub_func_int32_t_s_s((0L > g_877), g_1284[0])) , g_361) ^ g_923) | l_2200)))))) == 0x433B7C2B24F150C8LL))) <= g_75)) || g_164))
        {
            uint32_t l_2206 = 4UL;
            int32_t l_2227 = 9L;
            uint16_t l_2230 = 65535UL;
            uint16_t l_2245 = 65530UL;
            int32_t l_2330 = 0x6B90BF3CL;
            int32_t l_2352 = 0x871C638AL;
            if ((g_923 = ((((g_1293[3][0] == (g_810 = (((((((((safe_lshift_func_uint16_t_u_u((g_175[0][1] = (((safe_rshift_func_uint8_t_u_u(l_2206, 3)) & l_2187) && (safe_mod_func_uint8_t_u_u((g_462 = (safe_sub_func_int16_t_s_s((((l_2187 , 9UL) & ((safe_add_func_uint64_t_u_u(((g_281 = ((safe_add_func_uint64_t_u_u((safe_sub_func_uint16_t_u_u((0xBD1E274CL || ((l_2226 = ((((0UL & (((l_2206 == ((((l_2186 = (((g_836 = ((safe_rshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u(g_1293[3][0], l_2201)), l_2206)), l_2201)) | 0UL)) != l_2225) & 0UL)) && g_810) > g_2063[1][6]) == (-3L))) || g_253) >= 0x7694L)) != g_2063[1][6]) > g_1589) > l_2206)) | g_2158)), l_2206)), g_1501)) , l_2227)) , l_2201), g_2228)) != g_1293[3][0])) || l_2192), 65526UL))), l_2[0][0][3])))), g_1293[1][1])) & l_2227) & l_2229) <= g_312) & 0x8BE9BAB8L) ^ l_2187) || g_462) && 0x3D3226AFDE9E8D0CLL) | g_1501))) < l_2230) | g_877) >= g_2228)))
            {
                uint64_t l_2246 = 9UL;

            }
            else
            {
                uint16_t l_2249 = 65533UL;
                return l_2249;
            }


        }
        else
        {
            uint32_t l_2367 = 0x33CE11EDL;
            int32_t l_2425 = 0xC17521E3L;
            int32_t l_2442 = 0xE1E22E56L;
            int32_t l_2520 = (-6L);
            for (g_2158 = 0; (g_2158 <= 3); g_2158 += 1)
            {
                int32_t l_2376 = 0x2DB9F27AL;
                uint32_t l_2402 = 4294967288UL;
                uint32_t l_2440 = 0x1CCF8214L;
                l_2376 = (safe_unary_minus_func_int16_t_s((g_162[4][1][0] != (l_2367 , (safe_add_func_uint32_t_u_u(((l_2367 == 0xE899EF6F71413140LL) >= ((g_164 || (safe_rshift_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_sub_func_uint16_t_u_u((((((g_552 || l_2376) || (safe_mod_func_int32_t_s_s(((0UL > 18446744073709551615UL) , l_2226), g_2063[1][6]))) , l_2376) >= l_2187) != g_224), g_877)), g_2228)), g_329[2]))) < g_459)), l_2201))))));
                l_2226 = (safe_mod_func_int8_t_s_s((l_2288 > (((safe_add_func_int16_t_s_s((safe_lshift_func_uint8_t_u_u(((g_1735[1] , (((safe_sub_func_int64_t_s_s((l_2376 ^ (((safe_add_func_int8_t_s_s((safe_sub_func_int64_t_s_s(l_2376, ((safe_sub_func_uint32_t_u_u(0x009CEBDEL, (safe_add_func_uint32_t_u_u((((((+((((((l_2[0][3][2] == (safe_mod_func_uint64_t_u_u((safe_lshift_func_int16_t_s_u(((safe_mod_func_uint64_t_u_u((g_1293[3][0] = l_2364), 4L)) & l_2226), l_2367)), l_2192))) && l_2[2][2][0]) < l_2272) , 0xEA93L) , 0x561E7906L) | l_2201)) <= 0xAC56L) == g_1434) > g_180) == g_253), g_329[2])))) && (-1L)))), g_4)) <= 0xE115L) == l_2376)), l_2229)) == g_1284[0]) < 0xDE6CL)) == 0x4CL), l_2376)), l_2187)) <= l_2402) , 0x6F1FDDF3L)), 0x07L));
                for (g_2247 = 0; (g_2247 <= 3); g_2247 += 1)
                {
                    for (g_106 = 0; (g_106 <= 3); g_106 += 1)
                    {
                        l_2272 = g_164;
                        if (g_1434)
                            break;
                    }
                }
                for (g_224 = 0; (g_224 <= 3); g_224 += 1)
                {
                    uint32_t l_2423 = 0x8459F5D3L;
                    uint16_t l_2443 = 65531UL;
                    int16_t l_2472 = (-10L);
                    int32_t l_2488 = 0xF2223B52L;
                    uint8_t l_2489 = 1UL;
                    for (g_1434 = 3; (g_1434 >= 0); g_1434 -= 1)
                    {
                        int8_t l_2416[7][9] = {{0L,0L,0L,0L,0L,0L,0L,0L,0L},{0x31L,(-1L),0x31L,(-1L),0x31L,(-1L),0x31L,(-1L),0x31L},{0L,0L,0L,0L,0L,0L,0L,0L,0L},{0x31L,(-1L),0x31L,(-1L),0x31L,(-1L),0x31L,(-1L),0x31L},{0L,0L,0L,0L,0L,0L,0L,0L,0L},{0x31L,(-1L),0x31L,(-1L),0x31L,(-1L),0x31L,(-1L),0x31L},{0L,0L,0L,0L,0L,0L,0L,0L,0L}};
                        int i, j, k;
                        g_923 = (safe_mod_func_uint32_t_u_u((l_2402 ^ (safe_rshift_func_int8_t_s_s((safe_add_func_int32_t_s_s((safe_sub_func_int64_t_s_s((g_164 ^ (l_2186 = (((g_2426 = (g_175[0][0] = (safe_lshift_func_int16_t_s_u((((safe_unary_minus_func_int64_t_s((((safe_mod_func_uint32_t_u_u(((g_1147 = ((l_2416[5][2] >= ((l_2[(g_1434 + 1)][(g_224 + 2)][g_224] = (((0x7863L < ((g_381 = (l_2425 = (safe_sub_func_uint16_t_u_u(l_2229, ((safe_add_func_uint8_t_u_u((((((((safe_sub_func_uint32_t_u_u(l_2423, 0x437EBE41L)) >= (g_281 || 0x13E94712L)) | g_1589) == l_2272) | g_177) | g_2424[3][0][1]) , g_836), g_1701[2])) & g_877))))) && l_2364)) < g_301) < 0UL)) , g_1701[2])) ^ 0xB44BL)) , l_2425), g_1293[1][0])) ^ 0xFE6BF91F90481E63LL) ^ l_2376))) == l_2225) || l_2367), g_139)))) , 0UL) == g_1501))), g_2427)), g_329[1])), g_1293[5][1]))), g_2424[4][1][1]));
                        l_2443 = ((l_2442 = ((g_810 = (safe_lshift_func_int16_t_s_u((((l_2186 = (safe_lshift_func_int16_t_s_u(((((safe_mod_func_int16_t_s_s((0UL < ((((safe_add_func_int16_t_s_s(g_1293[7][0], (((((65533UL | (g_301 >= ((0xCAD1363B1BB94AB0LL > ((((((l_2440 = ((l_2425 = (((safe_mod_func_int32_t_s_s(g_923, 0x35F13E38L)) , ((((((((safe_mod_func_uint16_t_u_u((0UL > g_177), l_2416[3][6])) == l_2402) | g_175[0][0]) == g_361) | g_2427) <= l_2248[6][5]) > g_162[0][0][0]) < 0xBCFFL)) || l_2416[5][3])) >= g_2247)) | 0xB7C4L) != l_2328) , l_2440) , 0x614C513EL) || g_1701[0])) > g_977))) , 0xF7A9DB61EC0FD3A3LL) , 0x65DF7290L) & l_2423) == 0x695CL))) != l_2367) != g_1735[1]) == 0UL)), l_2226)) & 6L) != l_2441) , l_2271), 7))) <= 0x691FL) == l_2416[5][2]), 12))) | 0x9C171C7DL)) , g_162[4][1][0]);
                    }
                    for (l_2272 = 0; (l_2272 <= 3); l_2272 += 1)
                    {
                        int i, j, k;
                        l_2466 = (safe_add_func_uint64_t_u_u(((safe_sub_func_uint8_t_u_u((safe_add_func_int64_t_s_s(l_2442, (g_311 ^ ((safe_lshift_func_int8_t_s_s(l_2443, g_2452)) > (((l_2[l_2272][(g_2158 + 2)][g_2158] = g_1717[4]) < 0x68L) ^ (((safe_mod_func_uint64_t_u_u(g_301, g_2063[1][6])) ^ ((g_1701[1] = (safe_unary_minus_func_uint64_t_u((safe_add_func_uint16_t_u_u((safe_add_func_int16_t_s_s((((safe_sub_func_int16_t_s_s(((safe_mod_func_int64_t_s_s((l_2425 = 0xC89FD9C7998D9816LL), g_281)) ^ 0x03L), l_2443)) ^ g_2236) , l_2464[4][5][0]), 0xE7E2L)), l_2442))))) , g_1293[3][0])) , 1L)))))), g_2465)) <= g_3), 0xC604C5F35BE95151LL));
                        l_2186 = (safe_unary_minus_func_uint16_t_u((g_175[0][0] = 0xED19L)));
                        l_2186 = (((safe_sub_func_uint8_t_u_u((g_1701[0] = ((safe_lshift_func_uint8_t_u_u((l_2488 = (((l_2472 < ((l_2376 = (255UL >= (safe_mod_func_uint16_t_u_u((l_2[g_3][(g_224 + 2)][l_2272] > (safe_rshift_func_uint16_t_u_s(((((g_2188 , ((~(~(l_2248[5][7] >= 1L))) , (safe_add_func_int16_t_s_s((+(((safe_sub_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s((((((l_2367 < (safe_rshift_func_int16_t_s_s(((-1L) != l_2425), 6))) ^ g_1717[5]) , g_75) >= g_2424[3][0][1]) & g_180), g_2424[3][0][1])), g_462)) < l_2440) > (-9L))), l_2[g_3][(g_224 + 2)][l_2272])))) && 0xDC7B3DD0L) <= 0xD20C8370L) || g_2063[0][6]), 13))), (-1L))))) == g_281)) ^ g_224) | g_459)), 4)) , l_2225)), l_2[l_2272][(g_2158 + 2)][g_2158])) , g_459) <= l_2464[4][5][0]);
                    }
                    l_2489 = l_2402;
                }
            }
            for (l_2466 = 12; (l_2466 <= (-21)); l_2466 = safe_sub_func_uint64_t_u_u(l_2466, 5))
            {
                const uint8_t l_2504[1][4] = {{0x07L,0x07L,0x07L,0x07L}};
                const int8_t l_2515 = 0xBBL;
                int32_t l_2519 = 0x34F1D10FL;
                int32_t l_2521 = 0xA3CDFF06L;
                int i, j;
                l_2186 = (((g_1284[0] = ((((safe_add_func_uint8_t_u_u((safe_add_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s((l_2226 = (((4294967294UL == ((safe_sub_func_uint32_t_u_u((0L == 1UL), (((safe_mod_func_uint64_t_u_u(((((safe_sub_func_uint16_t_u_u(l_2367, l_2504[0][1])) ^ (safe_sub_func_int64_t_s_s(((-1L) ^ (safe_add_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((g_312 < ((safe_sub_func_uint8_t_u_u(((g_1701[3] ^ (((g_180 , l_22) ^ l_2367) <= l_2248[5][7])) == l_2186), l_22)) | g_459)), g_2063[1][6])), l_2504[0][1]))), l_2504[0][0]))) > l_2187) || g_281), 0xFB380D24146FF331LL)) ^ l_2504[0][2]) ^ l_2367))) | l_2442)) , l_2225) != l_2225)), 2)), 1L)), 0xB9L)) & g_301) , 1L) < l_2464[4][5][0])) != g_2158) | g_1717[3]);
                l_2521 = (((l_2441 , (safe_rshift_func_int8_t_s_s((l_2515 >= (l_2272 >= (g_1293[0][1] = (g_552 = g_1735[3])))), (g_312 = (safe_rshift_func_int16_t_s_s(0x895CL, (~((l_2515 || ((0xAC9AL <= ((g_170 , (l_2519 = l_2504[0][0])) < 18446744073709551615UL)) < l_2520)) < 0xCD11L)))))))) <= 8L) != 3L);
                g_923 = (0x97L ^ ((safe_rshift_func_uint8_t_u_s(l_2[5][1][0], 0)) & (g_836 , ((safe_rshift_func_int8_t_s_s((g_312 = ((l_2521 = ((safe_sub_func_uint32_t_u_u(((((((((l_2367 ^ ((l_2186 = g_106) != 1L)) & (safe_sub_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s(3L, 14)), ((safe_rshift_func_int8_t_s_s((l_2425 = l_2442), 3)) | (l_2520 >= l_2288))))) ^ g_810) && 0xC01BL) ^ g_1118[0]) && l_2367) == l_2464[5][5][0]) && l_2536), g_2452)) , l_2520)) < 7UL)), 5)) && l_2442))));
                return g_2063[1][6];
            }
        }
    }
lbl_2878:
    g_381 = ((l_2441 <= 1L) > l_2328);
    if (((((safe_mod_func_int16_t_s_s(((g_2063[1][6] = ((safe_sub_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(((~((((g_2247 = ((l_2464[2][0][2] || (g_459 >= (((l_2555 = ((((~l_2201) | (l_2464[0][0][1] || (((l_2186 = (-8L)) ^ (l_2554 = (((((safe_mod_func_int16_t_s_s((g_1756 = (l_2201 != (safe_lshift_func_int16_t_s_s(g_991, 1)))), (l_2536 & (+(safe_add_func_uint32_t_u_u((((safe_lshift_func_uint8_t_u_u(g_177, g_4)) || g_2465) <= l_2248[5][7]), l_2225)))))) & 8L) >= l_2[2][2][0]) > l_2229) < 0xA05E4758D346546FLL))) < l_2201))) , 1UL) == 0xE93E90EAAB5A1608LL)) , l_2441) < 0xEF174F40676D0005LL))) | 0x1F9EA916L)) < g_381) >= 0x4B950873L) && l_2229)) & 0xA60B692180B5FCC6LL), l_2248[0][3])), 251UL)) < l_2556)) <= l_2248[4][0]), 0x3A8BL)) < g_3) & 2L) != l_2464[4][5][0]))
    {
        int64_t l_2572 = 0x2D62A29E6055D5F5LL;
        uint32_t l_2578 = 0x68F04B9AL;
        int32_t l_2586[5] = {(-10L),(-10L),(-10L),(-10L),(-10L)};
        uint16_t l_2588 = 0x5F59L;
        uint8_t l_2622 = 0x85L;
        uint32_t l_2662 = 4294967294UL;
        uint8_t l_2906 = 7UL;
        const int32_t l_2932[7][5][7] = {{{0x83D5683CL,0x9E647D65L,(-1L),(-1L),0x9E647D65L,0x83D5683CL,0L},{(-5L),(-3L),4L,(-1L),(-1L),0x274FA118L,0x63178792L},{0x83D5683CL,0x9E647D65L,(-1L),(-1L),0x9E647D65L,0x83D5683CL,0L},{(-5L),(-3L),4L,(-1L),(-1L),0x274FA118L,0x63178792L},{0x83D5683CL,0x9E647D65L,(-1L),(-1L),(-1L),3L,(-1L)}},{{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL},{3L,(-1L),0L,0L,(-1L),3L,(-1L)},{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL},{3L,(-1L),0L,0L,(-1L),3L,(-1L)},{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL}},{{3L,(-1L),0L,0L,(-1L),3L,(-1L)},{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL},{3L,(-1L),0L,0L,(-1L),3L,(-1L)},{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL},{3L,(-1L),0L,0L,(-1L),3L,(-1L)}},{{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL},{3L,(-1L),0L,0L,(-1L),3L,(-1L)},{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL},{3L,(-1L),0L,0L,(-1L),3L,(-1L)},{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL}},{{3L,(-1L),0L,0L,(-1L),3L,(-1L)},{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL},{3L,(-1L),0L,0L,(-1L),3L,(-1L)},{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL},{3L,(-1L),0L,0L,(-1L),3L,(-1L)}},{{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL},{3L,(-1L),0L,0L,(-1L),3L,(-1L)},{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL},{3L,(-1L),0L,0L,(-1L),3L,(-1L)},{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,0xCE6212CEL}},{{3L,(-1L),0L,0L,(-1L),3L,(-1L)},{(-4L),(-1L),0x63178792L,0xF744D257L,4L,6L,(-7L)},{0x9E647D65L,0L,(-1L),(-1L),0L,0x9E647D65L,0x366FA596L},{(-1L),0xF744D257L,0xCE6212CEL,0x1A192B8CL,0x63178792L,(-3L),(-7L)},{0x9E647D65L,0L,(-1L),(-1L),0L,0x9E647D65L,0x366FA596L}}};
        int8_t l_2943 = (-1L);
        int32_t l_2988[7][3] = {{0x2305C203L,0xBDAC9935L,0x8E1A1BEDL},{0x2305C203L,0x2305C203L,0xBDAC9935L},{(-1L),0xBDAC9935L,0xBDAC9935L},{0xBDAC9935L,0x6A3A427FL,0x8E1A1BEDL},{(-1L),0x6A3A427FL,(-1L)},{0x2305C203L,0xBDAC9935L,0x8E1A1BEDL},{0x2305C203L,0x2305C203L,0xBDAC9935L}};
        int i, j, k;







        if ((((g_144 , (((((safe_lshift_func_uint16_t_u_s(g_175[0][2], 8)) == (l_2248[5][7] | (0xACL > ((((safe_sub_func_uint64_t_u_u((l_2572 , (l_2578 >= ((l_2586[1] = (l_2572 & (l_2585 = (safe_lshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((-1L), ((((safe_sub_func_int32_t_s_s(l_2556, g_1118[0])) > l_2578) , l_2186) > g_301))), 11))))) , g_1501))), l_2555)) | l_2587) | g_1284[0]) , l_2588)))) != g_977) && g_162[4][1][0]) && l_2[3][2][1])) , l_2585) || l_2588))
        {
            uint16_t l_2631[1][10][3] = {{{0x71C1L,0x9DDBL,1UL},{65530UL,0x15DFL,65530UL},{65528UL,0x71C1L,0xA990L},{0xC048L,65530UL,65530UL},{0xA990L,65528UL,1UL},{65527UL,0xC048L,1UL},{0xA990L,0xA990L,0x8699L},{0xC048L,65527UL,0x35FCL},{65528UL,0xA990L,65528UL},{65530UL,0xC048L,0x15DFL}}};
            int i, j, k;







{
            int32_t l_2566 = (-1L);
            uint32_t l_2571 = 0UL;
            uint32_t l_2573 = 0x6E35B7D1L;

        }

        }
        else
        {
            uint8_t l_2648 = 254UL;
            int32_t l_2649 = 0L;
            int16_t l_2650 = 0x5605L;
            int32_t l_2661 = 0L;
            uint32_t l_2748 = 0xD6FFC8DFL;
            uint32_t l_2763 = 0UL;
            uint32_t l_2813 = 4294967295UL;
            uint32_t l_2877 = 0x835C9623L;







            if ((((safe_lshift_func_int16_t_s_s((l_2650 == ((safe_lshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(249UL, 6)), 0)) & 0x5AL)), 6)) < l_2622) || (safe_mod_func_uint32_t_u_u((((safe_add_func_int8_t_s_s(((l_2248[2][6] != l_2649) != g_777), (l_2556 , ((((l_2661 != l_2586[0]) , g_1147) < 0x99C8B6690AFF6285LL) , 0xDDL)))) ^ 9L) & 0xB64FL), l_2662))))
            {
                const int32_t l_2667 = 0L;
                int32_t l_2691 = 0x694D2B5FL;
                int32_t l_2734 = 0x32AF72DAL;
                int16_t l_2849 = 0x900DL;
                uint32_t l_2864 = 0x7D7711BDL;
                uint16_t l_2872[9][9] = {{0UL,8UL,0UL,1UL,1UL,0x6594L,0x67D2L,1UL,0x0FD6L},{0UL,1UL,0x04F0L,1UL,0xACBBL,5UL,0x67D2L,0xACBBL,0xC6A7L},{0UL,0xACBBL,65535UL,1UL,8UL,0x67D2L,0x67D2L,8UL,1UL},{0UL,8UL,0UL,1UL,1UL,0x6594L,0x67D2L,1UL,0x0FD6L},{0UL,1UL,0x04F0L,1UL,0xACBBL,5UL,0x67D2L,0xACBBL,0xC6A7L},{0UL,0xACBBL,65535UL,1UL,8UL,0x67D2L,0x67D2L,8UL,1UL},{0UL,8UL,0UL,1UL,1UL,0x6594L,0x67D2L,1UL,0x0FD6L},{0UL,1UL,0x04F0L,1UL,0xACBBL,5UL,0x67D2L,0xACBBL,0xC6A7L},{0UL,0xACBBL,65535UL,1UL,8UL,0x67D2L,0x67D2L,8UL,1UL}};
                int i, j;
lbl_2881:
                if (((g_2158 || ((18446744073709551614UL <= g_139) == g_1284[0])) , (l_2586[1] = 0x7565947AL)))
                {
                    uint8_t l_2676 = 0xC6L;
                    int32_t l_2702 = (-1L);
                    uint8_t l_2718 = 0xE2L;
                    for (g_253 = 0; (g_253 < 22); g_253++)
                    {
                        int16_t l_2668 = 7L;
                        g_381 = (((safe_rshift_func_int16_t_s_s((l_2667 , ((((l_2668 | (~1L)) >= (((safe_sub_func_int32_t_s_s(((safe_add_func_int32_t_s_s(l_2667, ((safe_lshift_func_uint16_t_u_u(g_1589, 4)) && 1L))) > (g_2188 ^ ((((l_2586[1] > l_2676) == g_2465) | 0xF9C8AC4DL) && g_2228))), l_2668)) | l_2578) & 8UL)) <= g_361) , g_1293[3][0])), g_161)) <= l_2661) >= l_2676);
                        if (l_2649)
                            continue;
                        if (l_2662)
                            continue;
                        l_2691 = (g_2465 = (safe_add_func_uint32_t_u_u(0x6B4BC7CEL, (((-1L) >= (safe_sub_func_int32_t_s_s(0x28243A43L, g_381))) || ((g_1501 >= g_312) & (safe_mod_func_int64_t_s_s((safe_add_func_int8_t_s_s(((safe_rshift_func_int16_t_s_s(((-9L) != ((safe_mod_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s((g_836 | (0xFDL >= l_2622)), 0xD5FAC122L)) == 0xDFA831EBL), l_2644)) == g_57)), g_1735[1])) > (-4L)), l_2622)), 0x102278213AF72B57LL)))))));
                    }
                    g_923 = (safe_lshift_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((safe_lshift_func_int8_t_s_u(0xEDL, 3)), 5)) < (safe_lshift_func_uint8_t_u_u((l_2702 = l_2667), ((safe_mod_func_int16_t_s_s(((l_2622 , (((l_2661 = (((((safe_add_func_uint16_t_u_u(l_2676, (-1L))) >= ((~(l_2586[3] = (safe_rshift_func_uint8_t_u_u((safe_unary_minus_func_uint8_t_u((safe_lshift_func_uint16_t_u_s((0x2B2EL || ((safe_unary_minus_func_uint16_t_u((l_2691 = (safe_rshift_func_uint16_t_u_u(0x6BDAL, (g_1501 != (safe_lshift_func_uint16_t_u_u(0x8A87L, g_1501)))))))) , l_2676)), 14)))), l_2667)))) , 0x4A73L)) != g_329[1]) != 0x438EL) & 0L)) >= l_2649) , 0xAF849FB9L)) == l_2718), 0xACDDL)) , g_1756)))), l_2667)) == 0xDEC53312A7FAD540LL) ^ 248UL), l_2649));
                }
                else
                {
                    int32_t l_2727 = 0x7C9A7B2EL;
                    int32_t l_2728 = 0L;
                    uint32_t l_2815 = 18446744073709551615UL;
                    if (((safe_add_func_uint64_t_u_u((safe_rshift_func_uint8_t_u_u((g_144 != (((g_312 & l_2661) ^ ((l_2728 = (safe_add_func_uint32_t_u_u(g_1434, (l_2649 = (safe_add_func_int32_t_s_s(0x7FC3FE76L, l_2727)))))) , (safe_rshift_func_uint8_t_u_u((l_2588 >= (safe_add_func_int16_t_s_s(((+(l_2728 = (l_2734 && (0xCAD70698L < l_2691)))) >= (-5L)), 0xEBB6L))), 2)))) , g_2228)), 3)), l_2727)) > 0UL))
                    {
                        uint16_t l_2742[5][3][6] = {{{0x6E54L,1UL,0x6E54L,0xB72CL,1UL,0UL},{0x6E54L,0x76E6L,0xB72CL,0xB72CL,0x76E6L,0x6E54L},{0x6E54L,0xEF21L,0UL,0xB72CL,0xEF21L,0xB72CL}},{{0x6E54L,1UL,0x6E54L,0xB72CL,1UL,0UL},{0x6E54L,0x76E6L,0xB72CL,0xB72CL,0x76E6L,0x6E54L},{0x6E54L,0xEF21L,0UL,0xB72CL,0xEF21L,0xB72CL}},{{0x6E54L,0UL,1UL,4UL,0UL,0xEDEBL},{1UL,0xB72CL,4UL,4UL,0xB72CL,1UL},{1UL,0x6E54L,0xEDEBL,4UL,0x6E54L,4UL}},{{1UL,0UL,1UL,4UL,0UL,0xEDEBL},{1UL,0xB72CL,4UL,4UL,0xB72CL,1UL},{1UL,0x6E54L,0xEDEBL,4UL,0x6E54L,4UL}},{{1UL,0UL,1UL,4UL,0UL,0xEDEBL},{1UL,0xB72CL,4UL,4UL,0xB72CL,1UL},{1UL,0x6E54L,0xEDEBL,4UL,0x6E54L,4UL}}};
                        int i, j, k;
                        g_2465 = (safe_rshift_func_int8_t_s_u(((g_329[1] & ((g_977 = (safe_mod_func_int32_t_s_s((((g_2465 == (g_162[4][1][0] = ((l_2186 = (((~g_1147) & (safe_rshift_func_int16_t_s_s(l_2587, (g_332 != (l_2742[2][1][3] & (safe_rshift_func_int16_t_s_u((l_2734 = (8L || ((+0x0BL) >= ((safe_mod_func_int8_t_s_s(((((0x228CL && g_175[0][0]) == g_2228) < g_329[1]) < g_1735[3]), 0x30L)) && l_2648)))), g_361))))))) >= l_2588)) < 0xA050D6AE9E85C28ELL))) , 0x6B9930EDDB647B0CLL) && g_281), g_2236))) | g_1501)) <= l_2728), l_2328));
                        l_2748 = g_312;
                        g_381 = (((l_2648 < (((((safe_lshift_func_uint8_t_u_s((((!((((safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(((g_1293[3][0] > 0xB22D3B6D3E8DF325LL) > (0x191DL & (safe_unary_minus_func_int32_t_s((0x4BE3L | (0x30C50D1B5CEFCB9DLL > (safe_lshift_func_int8_t_s_u((((safe_sub_func_uint32_t_u_u(((0xC86622CCL == (((safe_sub_func_int16_t_s_s((0x0E7447E3892391BELL || 0xC8DD589E83D4860CLL), 0x6B9EL)) >= l_2742[0][0][5]) , (-1L))) > l_2667), g_2236)) <= g_180) & g_180), l_2763)))))))), 3)), g_75)) , l_2727) , g_284) & 0x343BB5AFL)) , 0xF46991E3L) < g_311), l_2586[4])) <= g_2764) && g_1717[3]) && 255UL) ^ 0xA1L)) & 0x98DEL) ^ 0x08L);
                    }
                    else
                    {
                        uint32_t l_2774[10] = {0UL,7UL,0UL,9UL,9UL,0UL,7UL,0UL,9UL,9UL};
                        int32_t l_2775[6][9] = {{4L,4L,6L,0x003707C2L,(-7L),6L,(-7L),0x003707C2L,6L},{4L,4L,6L,0x003707C2L,(-7L),6L,(-7L),0x003707C2L,6L},{4L,4L,6L,0x003707C2L,(-7L),6L,(-7L),0x003707C2L,6L},{4L,4L,6L,0x003707C2L,(-7L),6L,(-7L),0x003707C2L,6L},{4L,4L,6L,0x003707C2L,(-7L),6L,(-7L),0x003707C2L,6L},{4L,4L,6L,0x003707C2L,(-7L),6L,(-7L),0x003707C2L,6L}};
                        int64_t l_2809 = 6L;
                        uint32_t l_2814 = 9UL;
                        int i, j;
                        g_2465 = (g_2063[1][2] == ((safe_rshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(g_923, 7)), 6)) >= (g_175[0][0] = (safe_add_func_int32_t_s_s((safe_unary_minus_func_int8_t_s((((((0x389797D0L != ((9UL & l_2728) < g_161)) , ((0xCEL ^ g_4) , (l_2774[3] = (safe_rshift_func_uint16_t_u_u(((g_1701[0] = (g_991 = g_1039)) > g_180), 3))))) & g_1147) <= 0UL) > l_2691))), l_2775[0][7])))));
                        g_3 = (l_2186 = (safe_sub_func_uint32_t_u_u((((((safe_mod_func_uint16_t_u_u(l_2691, ((0L >= (g_332 = 0x05BBL)) & (((~(g_170 , (((!(safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint8_t_u_s((safe_rshift_func_int8_t_s_s((((safe_rshift_func_int16_t_s_s(((l_2661 = (+(l_2812 = (g_2811 = (g_175[0][0] = (safe_rshift_func_int8_t_s_s(((((g_224 || (((safe_sub_func_int32_t_s_s(l_2691, (l_2810 = (g_381 = ((((~((l_2727 && ((~(~(safe_lshift_func_uint16_t_u_u(((safe_sub_func_int64_t_s_s((safe_rshift_func_uint16_t_u_u((l_2809 = ((safe_add_func_uint16_t_u_u(((g_2806[0] = g_175[0][1]) >= (safe_lshift_func_int8_t_s_u(g_329[1], 6))), 0UL)) <= g_2424[3][0][1])), 8)), l_2649)) ^ 0xD2973853L), g_923)))) == 9L)) < g_1756)) && g_2236) & 4294967288UL) , l_2810))))) || 0xBEC3B116L) , l_2728)) , l_2662) <= 0x1BBFL) > l_2441), g_311))))))) > l_2748), l_2587)) , g_180) , g_1589), g_1701[3])), 2)), 1))) | g_2426) <= l_2813))) <= g_144) & g_4)))) == g_2063[1][6]) , 0xE561L) || l_2814) >= g_977), l_2815)));
                        g_2465 = l_2645;
                    }
                    if ((safe_rshift_func_uint16_t_u_s(0x33D7L, 0)))
                    {
                        int32_t l_2826 = 0L;
                        l_2728 = (0x44C0915FC1EA6490LL & (g_106 , (safe_mod_func_int8_t_s_s((l_2186 = ((safe_unary_minus_func_int32_t_s(l_2661)) , l_2727)), ((g_175[0][2] , (0x3EC0L == (g_977 = g_1735[1]))) || (safe_sub_func_uint32_t_u_u(((((!l_2667) >= (((safe_add_func_uint32_t_u_u(8UL, l_2763)) && l_2826) != g_2063[1][3])) , 0L) ^ 9UL), 0UL)))))));
                    }
                    else
                    {
                        uint64_t l_2827[6][3];
                        int i, j;
                        for (i = 0; i < 6; i++)
                        {
                            for (j = 0; j < 3; j++)
                                l_2827[i][j] = 0UL;
                        }
                        l_2691 = l_2827[0][0];
                    }
                }






            }
            else
            {
                uint32_t l_2940[2][5] = {{4294967292UL,4294967292UL,4294967292UL,4294967292UL,4294967292UL},{1UL,1UL,1UL,1UL,1UL}};
                int i, j;
{
                    int32_t l_809 = (-1L);
                    g_810 = (g_381 = l_809);

safe_rshift_func_int8_t_s_u(0x00L, 3);




                }
            }

safe_add_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u(0xB7E3L, 11)), 0x93L);
safe_lshift_func_uint16_t_u_u(0x8A87L, g_1501);
safe_lshift_func_uint16_t_u_s(g_175[0][2], 8);






safe_add_func_int32_t_s_s(g_170, 8);
        }
    }
    else
    {
        const int8_t l_2993 = 0x31L;
        uint16_t l_3004 = 0x682BL;


{
    return g_3;
}


    }





    return l_3032;
}





inline static int8_t func_11(uint8_t p_12)
{
    int32_t l_1835 = 0xE247C6B1L;
    int32_t l_1842 = 0x035E1B4DL;
    int32_t l_1849 = 0x8622C1AAL;
    int32_t l_1864[3][5] = {{0x1D95DE8CL,0x1D95DE8CL,0x1D95DE8CL,0x1D95DE8CL,0x1D95DE8CL},{0xB28CE4ABL,0xB28CE4ABL,0xB28CE4ABL,0xB28CE4ABL,0xB28CE4ABL},{0x1D95DE8CL,0x1D95DE8CL,0x1D95DE8CL,0x1D95DE8CL,0x1D95DE8CL}};
    int16_t l_1903 = 1L;
    int8_t l_1917 = 1L;
    int16_t l_1970[8][10] = {{1L,1L,1L,1L,1L,1L,1L,1L,1L,1L},{1L,1L,1L,1L,1L,1L,1L,1L,1L,1L},{1L,1L,1L,1L,1L,1L,1L,1L,1L,1L},{1L,1L,1L,1L,1L,1L,1L,1L,1L,1L},{1L,1L,1L,1L,1L,1L,1L,1L,1L,1L},{1L,1L,1L,1L,1L,1L,1L,1L,1L,1L},{1L,1L,1L,1L,1L,1L,1L,1L,1L,1L},{1L,1L,1L,1L,1L,1L,1L,1L,1L,1L}};
    uint8_t l_2122[8][10] = {{0xF0L,0xF7L,0xF0L,0xF0L,0xF7L,0xF0L,0xF0L,0xF7L,0xF0L,0xF0L},{0xF7L,0xF7L,0x4AL,0xF7L,0xF7L,0x4AL,0xF7L,0xF7L,0x4AL,0xF7L},{0xF7L,0xF0L,0xF0L,0xF7L,0xF0L,0xF0L,0xF7L,0xF0L,0xF0L,0xF7L},{0xF0L,0xF7L,0xF0L,0xF0L,0xF7L,0xF0L,0xF0L,0xF7L,0xF0L,0xF0L},{0xF7L,0xF7L,0x4AL,0xF7L,0xF7L,0x4AL,0xF7L,0xF7L,0x4AL,0xF7L},{0xF7L,0xF0L,0xF0L,0xF7L,0xF0L,0xF0L,0xF7L,0xF0L,0xF0L,0xF7L},{0xF0L,0xF7L,0xF0L,0xF0L,0xF7L,0xF0L,0xF0L,0xF7L,0xF0L,0xF0L},{0xF7L,0xF7L,0x4AL,0xF7L,0xF7L,0x4AL,0xF7L,0xF7L,0x4AL,0xF7L}};
    uint64_t l_2127 = 3UL;
    uint64_t l_2130 = 8UL;
    int32_t l_2174 = 0xC0369A03L;
    int i, j;
    if ((safe_rshift_func_int8_t_s_u(((g_1293[3][0] = (((l_1835 > l_1835) <= p_12) < l_1835)) , (((safe_lshift_func_int16_t_s_u((0x9049D157ABB000DCLL && (safe_add_func_int8_t_s_s(((((((g_284 <= ((safe_sub_func_int8_t_s_s(((((l_1842 = g_1756) <= p_12) < (safe_lshift_func_uint16_t_u_u(((safe_sub_func_uint16_t_u_u((l_1849 = ((safe_lshift_func_uint16_t_u_s(l_1835, p_12)) != 0UL)), g_991)) , g_224), p_12))) != l_1835), 252UL)) | l_1835)) >= 0x0B07D658L) && 0x48L) ^ 6UL) < g_332) && g_162[2][4][0]), 1UL))), g_977)) >= 0x265773EF595CBFEALL) , g_312)), l_1835)))
    {
        return p_12;
    }
    else
    {
        uint16_t l_1860 = 4UL;
        uint16_t l_1863 = 1UL;
        int32_t l_1883 = 0x60F38B19L;
        int32_t l_1885[1];
        int8_t l_2159 = 0L;
        uint16_t l_2185 = 65534UL;
        int i;
safe_sub_func_uint32_t_u_u((l_1864[2][4] = ((l_1842 || ((g_329[1] == (((p_12 ^ (safe_add_func_uint64_t_u_u((g_1293[3][0] = (safe_lshift_func_int16_t_s_s(p_12, g_1501))), p_12))) ^ 4294967294UL) , 4L)) || 0x3072L)) ^ (-4L))), p_12);

safe_add_func_uint16_t_u_u(g_1589, 7);







safe_sub_func_int16_t_s_s((0x0E7447E3892391BELL || 0xC8DD589E83D4860CLL), 0x6B9EL);
safe_rshift_func_int16_t_s_s(p_12, 9);

safe_add_func_int32_t_s_s((((safe_add_func_int8_t_s_s(((0xCFL & g_777) < g_459), p_12)) | l_1849) | (-8L)), 0L);
safe_rshift_func_int8_t_s_s(g_381, g_253);
safe_sub_func_uint16_t_u_u(g_170, 5);


g_301 += 1;



safe_sub_func_uint16_t_u_u(65535UL, (-1L));
safe_sub_func_uint32_t_u_u(g_224, 0xA7BB40B2L);



safe_unary_minus_func_int8_t_s(g_180);

{
        uint16_t l_1860 = 4UL;
        uint16_t l_1863 = 1UL;
        int32_t l_1883 = 0x60F38B19L;
        int32_t l_1885[1];
        int8_t l_2159 = 0L;
        uint16_t l_2185 = 65534UL;
        int i;
        for (i = 0; i < 1; i++)
            l_1885[i] = 0x42BD9F1EL;
        if ((((safe_rshift_func_uint8_t_u_s(((safe_sub_func_int64_t_s_s((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s(((l_1842 = l_1860) <= (safe_mod_func_int16_t_s_s(l_1863, 0x2FE0L))), (l_1860 > 0x9AL))), ((l_1849 == (l_1864[1][0] = l_1863)) == (+(safe_rshift_func_int16_t_s_u(p_12, g_1039)))))), g_1293[3][0])) > g_810), p_12)) && 0L) > g_1147))
        {
            int16_t l_1884 = 0x752FL;
            int32_t l_1898 = 0xB322CD89L;
            int32_t l_1904 = 0x16301C87L;
            int64_t l_1961 = 0x7543567F478F8BE7LL;
            int32_t l_2088 = 0L;
            int8_t l_2098 = 0x0FL;
            for (g_139 = (-1); (g_139 > 25); g_139 = safe_add_func_uint32_t_u_u(g_139, 3))
            {
                uint32_t l_1882 = 0x4F7BD357L;
                int32_t l_1905 = 0x484CB44CL;
                int32_t l_1920 = 0x5D27A41CL;
                for (g_301 = 0; (g_301 >= 13); ++g_301)
                {
                    uint64_t l_1888 = 0UL;
                    int32_t l_1906 = 0xA82334B6L;
                    l_1885[0] = ((((g_175[0][0] == 247UL) <= (g_361 == (g_836 = (safe_rshift_func_int8_t_s_u(0x00L, 3))))) > ((~(((l_1883 = (((safe_add_func_uint64_t_u_u((((p_12 < (p_12 , ((-6L) > (g_1756 = (safe_sub_func_uint64_t_u_u((safe_lshift_func_int16_t_s_s((safe_unary_minus_func_int64_t_s(g_170)), 13)), (((p_12 & g_1434) < 9UL) && (-1L)))))))) > l_1882) ^ p_12), 0xB5C5899EE7524D24LL)) && 0x4D75E836L) && g_75)) < (-1L)) > l_1884)) || 0UL)) <= 0x6A96L);
                    l_1906 = (l_1905 = (safe_add_func_int64_t_s_s((((l_1888 | l_1864[1][0]) , 255UL) > (safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(g_1118[0], 12)), g_139))), ((!((l_1904 = (safe_rshift_func_uint8_t_u_s((((l_1898 = 0xCA454B1DDBF166A8LL) | (l_1864[1][0] != ((l_1885[0] = g_301) > (((((safe_lshift_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u(l_1863, l_1884)), 14)) >= l_1903) >= l_1883) , l_1864[1][1]) , 6L)))) < p_12), p_12))) && l_1864[1][0])) >= l_1888))));
                    l_1920 = (safe_lshift_func_int8_t_s_u((p_12 , (safe_mod_func_uint8_t_u_u((l_1842 = (((((safe_add_func_int32_t_s_s((safe_sub_func_int16_t_s_s((safe_sub_func_uint8_t_u_u(((((l_1882 > p_12) , l_1917) & 0xEC904534L) || g_977), (((0xD9L >= (l_1906 = p_12)) , ((safe_rshift_func_uint8_t_u_u((((-7L) <= 0xECL) || 65528UL), 4)) >= l_1905)) , g_224))), p_12)), g_57)) ^ l_1884) >= 0xB955L) & p_12) > 1UL)), 0x95L))), 0));
                }
                g_381 = l_1885[0];
                for (g_170 = (-26); (g_170 != (-6)); g_170 = safe_add_func_int32_t_s_s(g_170, 8))
                {
                    int16_t l_1923[3][8][7] = {{{6L,0x1F79L,0xB939L,6L,6L,0x85F6L,(-1L)},{0L,0x5BA4L,0xB939L,0xA57EL,(-1L),0xF91AL,0xF91AL},{0x5BA4L,(-1L),0x6608L,(-1L),0x5BA4L,0x04FFL,0x9A4AL},{0x318CL,(-6L),0x85F6L,0x9A4AL,0xBAACL,0xCB6FL,0x636AL},{0xB939L,0x636AL,9L,0xA57EL,0x636AL,0xBAACL,(-6L)},{0x318CL,0x9A4AL,0x0F4DL,0x4BBCL,(-1L),(-6L),(-1L)},{0x5BA4L,0xF91AL,0x1F79L,0x275CL,0xBAACL,0L,0x5BA4L},{0L,(-1L),0xA57EL,0xBAACL,(-4L),0L,0x1F79L}},{{6L,(-1L),(-6L),0x9A4AL,0x9A4AL,(-6L),(-1L)},{(-1L),(-6L),0x5A36L,1L,6L,0xBAACL,(-1L)},{0x8F83L,(-1L),0xB939L,0x85F6L,0xF91AL,0x6608L,(-6L)},{0x1F79L,0xBAACL,0x318CL,6L,0xCB6FL,0x9A4AL,0xB939L},{0xB939L,(-6L),0x08F4L,0x8F83L,7L,0x0F4DL,0x8F83L},{0x215EL,0L,0x6608L,0xA1E0L,0x8F83L,0L,0x04FFL},{0x8F83L,0L,0x636AL,(-6L),0L,0x318CL,0L},{9L,(-6L),(-6L),9L,(-1L),0x215EL,0xCB6FL}},{{(-10L),0xBAACL,0xA1E0L,0x08F4L,0x85F6L,(-10L),0x0F4DL},{0xBAACL,0xCB6FL,0x636AL,0x8F83L,0xB939L,0x9A4AL,0xCB6FL},{0xA57EL,0x04FFL,0x215EL,0x85F6L,0xA1E0L,0L,0L},{5L,0xF91AL,0x54F2L,0x08F4L,0xF91AL,(-6L),0x04FFL},{9L,0x85F6L,0x318CL,0xA57EL,0xF91AL,0xE764L,0x8F83L},{0xB939L,0x0F4DL,0xA1E0L,0xDDDAL,0xA1E0L,0x0F4DL,0xB939L},{(-10L),0x8F83L,0x92BFL,0xA1E0L,0xB939L,7L,(-6L)},{0x5A36L,0L,0xE764L,0xCB6FL,0x85F6L,0xE764L,0L}}};
                    int16_t l_1954 = 0xF5A2L;
                    int32_t l_1969 = 0x8A518A59L;
                    int i, j, k;
                    for (g_552 = 0; (g_552 <= 3); g_552 += 1)
                    {
                        int i;
                        l_1923[0][7][6] = g_1735[g_552];
                        g_381 = (g_161 >= ((l_1849 <= 0UL) && (safe_add_func_int8_t_s_s((safe_mod_func_uint64_t_u_u((safe_sub_func_uint16_t_u_u((((safe_rshift_func_int8_t_s_s((0x63DA4CD192DDA58ELL != l_1923[0][7][6]), (((p_12 ^ ((safe_add_func_int32_t_s_s((((safe_add_func_int8_t_s_s(((0xCFL & g_777) < g_459), p_12)) | l_1849) | (-8L)), 0L)) != g_139)) == 2L) >= l_1904))) > l_1860) ^ p_12), l_1898)), 0xB9E6DB22738977A6LL)), p_12))));
                        l_1920 = (g_923 = ((g_164 & ((safe_add_func_int16_t_s_s((((safe_mod_func_int16_t_s_s(((g_75 , ((((safe_add_func_int8_t_s_s((~(safe_sub_func_uint64_t_u_u((+(safe_rshift_func_int16_t_s_u((0xA463L != 0xC86EL), ((g_923 < (((safe_mul_func_uint8_t_u_u(g_1735[g_552], (l_1923[2][4][2] >= l_1905))) && (0xB76C3D28L & l_1898)) & g_923)) || (-1L))))), p_12))), l_1923[0][1][2])) ^ l_1923[0][7][6]) && l_1954) == 0xEEL)) >= 4UL), 1UL)) ^ 0UL) > p_12), p_12)) , p_12)) != l_1860));
                    }
                    l_1864[0][3] = (((((0xA7L != g_175[0][0]) < ((g_1717[1] & g_810) && (safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(p_12, 15)), 5)))) , (l_1882 ^ g_1039)) == (0UL >= (((((safe_lshift_func_int16_t_s_u((((((0xA7C8L && g_836) ^ p_12) || 0x2D82A409L) == l_1961) == p_12), g_177)) & p_12) || g_284) && p_12) && 5L))) > 0xF3B5L);
                    g_810 = (((l_1898 = g_162[2][1][0]) >= ((l_1883 = (safe_rshift_func_uint16_t_u_s((0x05B37687L & (0x8272L && (g_1701[0] > 8L))), (((l_1970[7][3] = (((safe_add_func_int64_t_s_s(l_1905, (p_12 & (p_12 <= (safe_sub_func_uint16_t_u_u((l_1969 = (!((l_1885[0] = l_1961) <= 0x3AL))), g_281)))))) , 0xE7EACC6AA4D88E93LL) && g_175[0][0])) > g_462) != g_164)))) || 0UL)) && 1L);
                    g_923 = 9L;
                }
            }
            if ((((l_1885[0] == (((((l_1898 > ((safe_lshift_func_uint16_t_u_u(((g_1735[2] = ((safe_rshift_func_int16_t_s_u(g_459, ((l_1904 = l_1904) && l_1883))) <= ((safe_sub_func_int32_t_s_s(g_361, (65534UL || ((((safe_add_func_int64_t_s_s((((((-9L) < 1L) != p_12) < p_12) == g_139), g_1735[3])) < g_1293[5][1]) , l_1885[0]) < g_1147)))) & 5L))) >= g_329[0]), l_1864[1][0])) >= (-6L))) <= l_1849) && 0x42L) >= p_12) > p_12)) | p_12) >= l_1898))
            {
                uint32_t l_1997 = 0x03C6C79EL;
                int32_t l_1998[7] = {(-1L),8L,8L,(-1L),8L,8L,(-1L)};
                int i;
                if (((((safe_sub_func_uint32_t_u_u((((0x6958CDAAE2819A2ELL || 0x1E41E926CACE1CCALL) , (safe_add_func_int32_t_s_s(((((safe_sub_func_uint64_t_u_u((((((l_1898 = (safe_sub_func_int16_t_s_s((~((p_12 | (safe_mod_func_int16_t_s_s(((((18446744073709551615UL < ((1UL <= (((((1UL | ((g_1284[0] = ((g_106 = l_1898) ^ (l_1997 = (g_462 = (safe_sub_func_uint32_t_u_u((safe_mod_func_uint64_t_u_u(((~(((g_381 & l_1849) <= g_1284[0]) <= g_923)) > 1L), p_12)), p_12)))))) != (-6L))) == 7L) > l_1860) & g_281) && g_1735[1])) == 4294967292UL)) , 1L) > g_1039) > p_12), p_12))) <= l_1860)), p_12))) & 0xE2C095C0L) ^ l_1970[7][3]) != p_12) < g_1735[2]), g_329[1])) , g_777) != 0x411082D0L) != 1UL), p_12))) < l_1998[2]), 0xF1417ED4L)) < p_12) , 0x9D33L) < g_332))
                {
                    uint32_t l_2012 = 0xE37D7E1CL;
                    int32_t l_2013 = 0x6CCB5A23L;
                    int32_t l_2014 = 1L;
                    uint32_t l_2030 = 1UL;
                    l_2014 = (safe_lshift_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_s((safe_sub_func_uint64_t_u_u(g_1701[4], ((255UL ^ (((((+(safe_add_func_int32_t_s_s((l_1849 = (((l_1998[2] = (g_552 = l_1970[7][3])) > (safe_rshift_func_uint8_t_u_s(g_329[1], (0xF8DFEB9DL >= (((safe_rshift_func_uint8_t_u_u((((l_2012 != ((((l_1883 = 65535UL) | (p_12 == (l_1885[0] < l_2012))) > l_1997) > p_12)) , g_175[0][0]) ^ p_12), p_12)) >= 0UL) <= l_1835))))) | (-5L))), 0x68D13FB3L))) < 0x4F29424D52197588LL) & 0x8F2CE4E1L) < p_12) < l_1917)) >= l_1885[0]))), 5)) & l_2013), 10));
                    l_2030 = ((g_1293[3][0] < (((g_175[0][0] = ((!((l_1998[4] = p_12) , (((((((((((safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_s((l_1885[0] = (((safe_mod_func_int64_t_s_s(l_1917, (g_57 , 1L))) < (((safe_mod_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(g_1284[0], 3)) == ((l_1842 = 0x4099FCCCL) , (safe_rshift_func_int16_t_s_s((g_977 = (safe_mod_func_int8_t_s_s(0x67L, 0xF1L))), p_12)))), l_1970[7][3])) < 6UL) < 0xF4A4L)) || l_2012)), 12)) || 0x14F4L), 1)) , 4294967289UL) < 0xB1E20FFDL) && l_1898) > g_332) | p_12) ^ g_75) > l_1998[1]) != 0x04L) ^ (-9L)) ^ 0UL))) > p_12)) | p_12) , p_12)) && g_106);
                }
                else
                {
                    int8_t l_2043 = (-5L);
                    uint16_t l_2099[4][3][7] = {{{0x4905L,0x266FL,0x686AL,0x686AL,0x266FL,0x4905L,0x08D4L},{0x5E77L,0x266FL,0x76E6L,0xC0B6L,0x266FL,1UL,0x75EEL},{0x5E77L,1UL,0x686AL,0xC0B6L,1UL,0x4905L,0x75EEL}},{{0x4905L,0x266FL,0x686AL,0x686AL,0x266FL,0x4905L,0x08D4L},{0x5E77L,0x266FL,0x76E6L,0xC0B6L,0x266FL,1UL,0x75EEL},{0x5E77L,1UL,0x686AL,0xC0B6L,1UL,0x4905L,0x75EEL}},{{0x4905L,0x266FL,0x686AL,0x686AL,0x266FL,0x4905L,0x08D4L},{0x5E77L,0x266FL,0x76E6L,0xC0B6L,0x266FL,1UL,0x75EEL},{0x5E77L,1UL,0x686AL,0xC0B6L,1UL,0x4905L,0x75EEL}},{{0x4905L,0x266FL,0x686AL,0x686AL,0x266FL,0x4905L,0x08D4L},{0x5E77L,0x266FL,0x76E6L,0xC0B6L,0x266FL,1UL,0x75EEL},{0x5E77L,1UL,0x686AL,0xC0B6L,1UL,0x4905L,0x75EEL}}};
                    int i, j, k;
                    for (g_144 = 0; (g_144 == 22); g_144 = safe_add_func_int16_t_s_s(g_144, 8))
                    {
                        l_1885[0] = (safe_mod_func_uint8_t_u_u(g_224, (safe_rshift_func_int16_t_s_u((safe_add_func_int32_t_s_s((-1L), (((safe_sub_func_uint8_t_u_u((((l_2043 = (safe_add_func_int16_t_s_s(l_1884, 0x4A96L))) , (safe_add_func_uint32_t_u_u(((g_175[0][0] = (safe_rshift_func_int8_t_s_s((g_75 = l_1961), (safe_add_func_int8_t_s_s((-1L), ((p_12 && (safe_rshift_func_uint16_t_u_s((((0x738BF81FL ^ ((g_1717[3] ^ g_1118[0]) && 6L)) && 65535UL) == 0xD9L), 2))) < l_2043)))))) >= g_1701[1]), 2L))) && l_2043), l_1860)) & l_1997) >= l_1998[2]))), 8))));
                        return p_12;
                    }
                    for (g_301 = 0; (g_301 <= 2); g_301 += 1)
                    {
                        int64_t l_2054 = (-4L);
                        int32_t l_2071[6][7] = {{0xD3403C41L,0x2D9F4264L,0x975CCF2FL,0x2D9F4264L,0xD3403C41L,0xD3403C41L,0xACFB9A36L},{0x975CCF2FL,0xD3403C41L,0x975CCF2FL,0xACFB9A36L,0xACFB9A36L,0x975CCF2FL,0xD3403C41L},{0xACFB9A36L,0xD3403C41L,9L,9L,0xD3403C41L,0xACFB9A36L,0xD3403C41L},{0x975CCF2FL,0xACFB9A36L,0xACFB9A36L,0x975CCF2FL,0xD3403C41L,0x975CCF2FL,0xACFB9A36L},{0x2D9F4264L,0x2D9F4264L,0xACFB9A36L,9L,0xACFB9A36L,0x2D9F4264L,0x2D9F4264L},{0x2D9F4264L,0xACFB9A36L,9L,0xACFB9A36L,0x2D9F4264L,0x2D9F4264L,0xACFB9A36L}};
                        int i, j;
                        l_1998[2] = (safe_sub_func_int64_t_s_s(((g_1701[0] < (l_2054 = 0xFCL)) || ((g_175[0][1] = (safe_rshift_func_uint8_t_u_s(((((safe_mod_func_uint16_t_u_u(l_1835, ((18446744073709551615UL ^ (((safe_lshift_func_int8_t_s_s((safe_mod_func_int16_t_s_s(0x1F7BL, g_2063[1][6])), (((l_2071[1][5] = (((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u(((+((safe_sub_func_uint8_t_u_u(l_1998[5], (((g_777 < ((((((p_12 < g_144) ^ g_312) ^ 8UL) >= g_1589) <= l_1885[0]) == g_1717[0])) , l_2054) != l_1860))) , g_991)) == p_12), l_1898)) , g_991), g_75)) | g_1701[2]) > 1L)) & 0x45L) > g_57))) < 0x651A5EDAB9B228E2LL) == 0x978E6F20L)) || 0x9AE39C1C8155FE18LL))) != p_12) ^ l_1864[1][0]) , l_1835), 0))) && p_12)), p_12));
                        g_810 = (((safe_add_func_int8_t_s_s((((safe_rshift_func_int8_t_s_u(0L, 4)) || g_923) >= (safe_mod_func_int64_t_s_s((l_1885[0] = (((l_1842 = (l_1864[1][2] = ((safe_mod_func_int64_t_s_s((safe_rshift_func_int16_t_s_s((g_2063[1][6] != ((safe_mod_func_uint8_t_u_u(1UL, (p_12 = (safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u((((g_462 | (l_2054 && l_1998[2])) > 0x1700L) , l_1884), l_1961)), g_1717[2]))))) < g_175[0][0])), l_2043)), l_2088)) == l_1970[7][3]))) , (-1L)) > 0xA5C9282930A53716LL)), (-2L)))), g_1589)) , p_12) , p_12);
                        l_2099[0][2][5] = (((0x19L >= (((g_777 >= (((g_923 = (safe_sub_func_uint16_t_u_u(65535UL, 2L))) , (l_1885[0] > (safe_sub_func_uint16_t_u_u((!((safe_sub_func_int32_t_s_s((l_1864[1][0] = g_164), (p_12 , (((~(((~g_1434) | 0xE2CA3A0FL) || g_4)) > g_1147) > 1L)))) ^ p_12)), p_12)))) | l_2098)) && p_12) == (-1L))) != g_877) > 250UL);
                        g_810 = g_4;
                    }
                }
                for (l_1842 = 0; (l_1842 >= 19); l_1842 = safe_add_func_uint32_t_u_u(l_1842, 5))
                {
                    uint32_t l_2115 = 0xF38EF585L;
                    int32_t l_2123 = 0L;
                    int32_t l_2124 = 0x696DA47DL;
                    l_2124 = (safe_lshift_func_int8_t_s_u(((((((safe_lshift_func_uint8_t_u_s((((((p_12 && ((safe_rshift_func_int8_t_s_s(l_2088, 5)) == (p_12 != ((g_923 = l_1835) != ((((l_1998[2] = ((l_2123 = ((!(safe_lshift_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u(((safe_mod_func_int8_t_s_s((-3L), p_12)) & ((((l_2115 ^ ((safe_sub_func_int8_t_s_s(p_12, ((safe_rshift_func_int8_t_s_u((g_281 = ((((safe_sub_func_int32_t_s_s(l_1998[2], 4294967291UL)) > 0x73E0L) , l_2115) < l_2098)), g_284)) >= 0xE52E3BEDL))) | g_253)) > l_2122[2][2]) > (-3L)) != g_329[0])), p_12)) | l_1885[0]), 0))) != 0x4BL)) | 0xCA28L)) || 0x152EL) , g_162[4][1][0]) == 18446744073709551615UL))))) | g_253) >= 0xF901189BEDD87DFALL) , 65535UL) | g_3), p_12)) & 0xCAED07D3273747C7LL) & p_12) == p_12) >= p_12) & p_12), 0));
                }
                l_1842 = (((((safe_add_func_uint8_t_u_u((((l_2088 > p_12) , g_991) > ((((g_170 < 65535UL) || (l_2127 , ((safe_sub_func_uint16_t_u_u((g_175[0][0] = ((l_1864[1][0] = 18446744073709551615UL) != l_2130)), (((g_1735[1] = l_1904) >= g_1118[0]) , l_1885[0]))) || l_1864[1][2]))) >= 0UL) >= g_253)), l_1917)) , g_1118[0]) < l_1863) | l_1998[2]) == g_1756);
            }
            else
            {
                for (g_1039 = 0; (g_1039 >= (-3)); g_1039 = safe_sub_func_uint8_t_u_u(g_1039, 7))
                {
                    int32_t l_2133 = (-2L);
                    l_1885[0] = 1L;
                    l_2133 = g_1589;
                }
                g_810 = 1L;
            }
        }
        else
        {
            int32_t l_2151 = 0x971B2752L;
            uint16_t l_2156 = 0x2E9DL;
            int32_t l_2157[6];
            int i;
            for (i = 0; i < 6; i++)
                l_2157[i] = 0x50304BC7L;
            l_2151 = (((safe_sub_func_int32_t_s_s((safe_mod_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u((((((safe_mod_func_uint8_t_u_u(((safe_lshift_func_int8_t_s_s(((((safe_unary_minus_func_uint64_t_u((safe_rshift_func_int16_t_s_s(p_12, 9)))) ^ (((safe_sub_func_int32_t_s_s(g_2063[1][6], 0UL)) > (safe_lshift_func_uint16_t_u_u((p_12 ^ (l_2151 ^ ((safe_add_func_int64_t_s_s(((0x73B2D50718B118B6LL > (safe_add_func_int32_t_s_s((l_2156 = g_301), (p_12 ^ (((l_2157[3] = g_462) & p_12) != l_1885[0]))))) , l_2151), g_1293[3][0])) <= (-1L)))), p_12))) < p_12)) && g_1701[2]) , (-1L)), g_301)) == g_1284[0]), g_977)) <= g_4) > 0UL) == l_1885[0]) == g_2158), l_2159)) < p_12), g_180)), 0x52AEE8B1L)) ^ 0x1A34F29B12B1BF54LL) || 1L);
        }
        l_1842 = (safe_unary_minus_func_int64_t_s((safe_rshift_func_int8_t_s_s((g_2063[1][6] = 1L), 3))));
        l_1885[0] = l_1864[0][3];
        l_1883 = (safe_lshift_func_int8_t_s_s(((l_1885[0] = (safe_sub_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(g_1701[0], (safe_lshift_func_uint8_t_u_s((~(safe_lshift_func_uint8_t_u_u((p_12 <= (l_2174 | ((l_2185 = ((safe_sub_func_int32_t_s_s((g_810 = (18446744073709551615UL >= (safe_add_func_int8_t_s_s((g_281 | (safe_sub_func_uint32_t_u_u((l_1864[2][4] = ((l_1842 || ((g_329[1] == (((p_12 ^ (safe_add_func_uint64_t_u_u((g_1293[3][0] = (safe_lshift_func_int16_t_s_s(p_12, g_1501))), p_12))) ^ 4294967294UL) , 4L)) || 0x3072L)) ^ (-4L))), p_12))), g_253)))), g_170)) , p_12)) & 0x0EDDB7A2L))), 1))), p_12)))), l_1885[0]))) || p_12), p_12));
    }
{
            int16_t l_1884 = 0x752FL;
            int32_t l_1898 = 0xB322CD89L;
            int32_t l_1904 = 0x16301C87L;
            int64_t l_1961 = 0x7543567F478F8BE7LL;
            int32_t l_2088 = 0L;
            int8_t l_2098 = 0x0FL;


        }



{
                    int32_t l_809 = (-1L);





safe_rshift_func_int16_t_s_s(p_12, 9);





safe_rshift_func_uint8_t_u_u(0xA9L, 2);



                }
    }
    return g_810;
}





inline static uint8_t func_13(uint64_t p_14, uint16_t p_15)
{
    uint32_t l_24[5][10] = {{1UL,1UL,1UL,1UL,1UL,1UL,4294967295UL,1UL,4294967295UL,1UL},{0x888AD88CL,1UL,0x4BC795C3L,1UL,0x888AD88CL,0x4BC795C3L,0x12EF314DL,0x12EF314DL,0x4BC795C3L,0x888AD88CL},{0x888AD88CL,4294967295UL,4294967295UL,0x888AD88CL,1UL,1UL,0x888AD88CL,1UL,1UL,0x888AD88CL},{1UL,0x888AD88CL,1UL,1UL,0x888AD88CL,4294967295UL,4294967295UL,0x888AD88CL,1UL,1UL},{0x12EF314DL,0x12EF314DL,0x4BC795C3L,0x888AD88CL,1UL,0x4BC795C3L,1UL,0x888AD88CL,0x4BC795C3L,0x12EF314DL}};
    int32_t l_1829 = 0x2F2F6D26L;
    int i, j;
    for (g_4 = 0; (g_4 <= 4); g_4 += 1)
    {
        uint8_t l_25 = 248UL;
        uint8_t l_1830 = 0x2FL;
        l_1830 = ((l_1829 = (l_25 & (g_3 < (((func_26((safe_mod_func_uint8_t_u_u(((-2L) > (safe_lshift_func_int8_t_s_s(func_18(p_15, p_15, l_25), l_25))), ((g_4 > 18446744073709551607UL) ^ p_15))), l_25, p_15, l_24[1][2]) ^ 0xA8L) , p_15) ^ 18446744073709551615UL)))) | l_24[2][0]);
        for (g_301 = 0; (g_301 <= 4); g_301 += 1)
        {
            int i, j;
            return l_24[g_4][(g_4 + 5)];
        }
    }
safe_mod_func_int16_t_s_s(0x1F7BL, g_2063[1][6]);
safe_rshift_func_int16_t_s_s(g_1118[0], 12);

safe_add_func_int32_t_s_s(g_144, 9);




printf("index = [%d][%d]\n", i, j);
{
                        int i, j;





                    }
    return l_1829;
}





static int32_t func_18(uint8_t p_19, int16_t p_20, int16_t p_21)
{
    return g_3;
}





static uint8_t func_26(uint8_t p_27, uint32_t p_28, int32_t p_29, const uint16_t p_30)
{
    int64_t l_38 = (-7L);
    int32_t l_1129 = (-1L);
    int32_t l_1577 = 0xD2CEBEDCL;
    int16_t l_1584 = 0xD58FL;
    int8_t l_1585 = 8L;
    uint16_t l_1605 = 0UL;
    int64_t l_1758 = 0x20F90006452B46EDLL;
    uint32_t l_1807 = 4294967288UL;
    int32_t l_1808 = 0x483A03A9L;
    int32_t l_1809[2][2];
    const int32_t l_1821 = (-1L);
    uint16_t l_1827 = 1UL;
    int8_t l_1828 = 6L;
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            l_1809[i][j] = 2L;
    }
lbl_1595:
    l_1577 = ((~((safe_mod_func_uint16_t_u_u(l_38, func_39((l_1129 = func_45(func_18(l_38, (safe_add_func_uint8_t_u_u((((safe_add_func_uint64_t_u_u(func_55(((((255UL <= ((g_57 = 0UL) , 1UL)) , (safe_lshift_func_int8_t_s_u((0x14L >= (0x0229B020L && (l_38 , (safe_lshift_func_int8_t_s_u((-1L), 0))))), p_27))) != p_28) <= g_4)), g_1118[0])) <= l_38) & l_38), l_38)), g_1118[0]), g_1118[0], l_38, g_4, p_27)), l_38, p_27, g_1118[0], p_27))) >= p_28)) <= p_28);
    if ((((((g_311 = (l_1129 = (((g_1501 != l_1577) < g_836) < l_1577))) || (g_462 < ((!(p_28 >= (((((l_1577 = ((((g_836 , ((safe_rshift_func_uint8_t_u_u(g_1118[0], ((g_1284[0] = (!((safe_lshift_func_int16_t_s_s(((p_28 | 0x7D87L) ^ p_27), 12)) != l_1584))) || l_1585))) < l_1584)) >= 0xD5AA399BL) ^ p_28) != p_29)) || 0x0096L) | g_462) != g_253) && g_1293[6][2]))) > 0xE8L))) & 5UL) <= l_1584) <= l_1584))
    {
        uint16_t l_1588 = 0xC67DL;
        int32_t l_1590 = 0xAD341242L;




{
                    int32_t l_809 = (-1L);




{





                    }




safe_mod_func_uint64_t_u_u((g_552 = g_329[2]), g_877);
{
                    return g_106;
                }


safe_lshift_func_int8_t_s_u((-1L), 0);




                }
    }
    else
    {
        int8_t l_1622 = (-2L);
        int32_t l_1676[4][5] = {{0L,0xE8D11F00L,0xE8D11F00L,0L,0xE8D11F00L},{1L,1L,1L,1L,1L},{0xE8D11F00L,0L,0xE8D11F00L,0xE8D11F00L,0L},{1L,1L,1L,1L,1L}};
        int32_t l_1677 = 0x30BB59D2L;
        int32_t l_1781 = 0x251908C6L;
        int32_t l_1782 = 7L;
        int i, j;
        for (g_144 = (-3); (g_144 < 7); g_144 = safe_add_func_int32_t_s_s(g_144, 9))
        {
            uint64_t l_1623[3][1];
            int32_t l_1646 = 1L;
            int16_t l_1678 = 0x96FFL;
            int i, j;
        }
        l_1782 = (((safe_sub_func_uint16_t_u_u((l_1676[1][0] = (safe_rshift_func_uint8_t_u_s((7UL || 1UL), 5))), (((+g_175[0][0]) < (((p_29 , p_28) , (l_1781 = (p_28 > ((((((g_281 = (g_1589 = g_1701[0])) , g_1434) != ((safe_sub_func_uint32_t_u_u(((safe_sub_func_uint32_t_u_u(((safe_rshift_func_int8_t_s_u(((safe_mod_func_uint8_t_u_u(((l_1677 = 4L) <= l_1781), g_777)) <= g_329[1]), g_329[1])) < l_1622), (-8L))) | g_1293[4][0]), p_30)) != l_1781)) && (-1L)) >= 1L) && 0UL)))) >= 0x5C73L)) ^ p_29))) || l_1585) >= p_28);
        l_1809[0][0] = (l_1676[3][3] = (safe_add_func_int8_t_s_s(((((((0x1BL && (g_1701[1] = (l_1808 = (safe_rshift_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_s((((g_1284[0] = ((l_1676[1][2] <= ((g_311 = ((0x3D35D89EBF09384DLL || ((safe_sub_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(((safe_mod_func_uint8_t_u_u((l_1129 = (1UL >= g_1756)), (safe_lshift_func_int8_t_s_s((safe_mod_func_uint64_t_u_u(((((((safe_mod_func_uint32_t_u_u((p_28 && (safe_rshift_func_int8_t_s_u((g_106 = (((((l_1577 = ((((g_1284[0] | 9L) | (safe_add_func_int8_t_s_s((l_1782 = ((((safe_add_func_uint32_t_u_u((4294967295UL == l_1677), g_381)) < l_1605) && g_977) && g_1735[1])), l_1781))) <= 1L) == p_29)) && 65532UL) <= 1L) || 0L) & p_30)), 0))), p_30)) <= l_1807) , 0xE5L) != g_1589) < g_459) < g_991), 8UL)), p_30)))) <= g_1717[3]), 0x77AE8A74L)), 0xF3ABL)) | (-1L))) || 0x46L)) , p_27)) < p_27)) <= 0x0E0ED56DL) && p_30), g_329[1])) <= 18446744073709551614UL), p_29))))) != l_1585) & 0x976DA143A981496FLL) < 0xA8191FA1L) || 1L) & l_1584), p_30)));
        l_1781 = (((l_1129 = l_1677) < (safe_sub_func_int32_t_s_s((1L & (((((safe_sub_func_int64_t_s_s(((p_27 | (l_1577 >= (((0x9B62291B0270610DLL >= ((((l_1809[0][0] = ((-1L) < g_381)) != (safe_add_func_int64_t_s_s((l_1808 = p_29), ((safe_mod_func_uint16_t_u_u(((((safe_unary_minus_func_uint64_t_u((safe_rshift_func_uint16_t_u_s((g_977 , l_1676[1][2]), 13)))) >= 9L) != g_1118[0]) || 0x9A533341538C4D18LL), p_29)) <= 0UL)))) == g_381) | l_1622)) ^ l_1584) || 1L))) < p_29), l_1821)) , p_28) && 246UL) & 0x3FBCL) || p_29)), 4294967287UL))) != g_1284[0]);
    }
    g_923 = (((((safe_add_func_int16_t_s_s((((0xD8L || g_1735[1]) < (p_27 = l_1808)) <= ((safe_rshift_func_uint8_t_u_s(((!((((g_1147 , l_1808) != l_1821) >= (0L > ((l_1129 = (((l_1827 = g_361) || l_1808) , 1L)) & l_1828))) , g_777)) & 0x4FL), p_30)) < (-1L))), 0xB565L)) < l_1577) > g_1717[4]) , p_30) | 0xDEL);
    return l_1827;
}





static int16_t func_39(int32_t p_40, int32_t p_41, uint8_t p_42, int16_t p_43, uint64_t p_44)
{
    int32_t l_1146 = (-3L);
    int32_t l_1333 = 0L;
    int32_t l_1477 = 0L;
    uint8_t l_1498 = 0x6FL;
    int64_t l_1533 = 0x5856E5085670BE8BLL;
    uint16_t l_1547 = 65535UL;
    const uint16_t l_1563 = 5UL;
    for (g_177 = 0; (g_177 <= 3); g_177 += 1)
    {
        int64_t l_1145 = 0x268351B43BFD7F0ALL;
        int64_t l_1165 = (-1L);
        int32_t l_1166 = 0L;
        int16_t l_1224[6] = {0xED54L,0xBA19L,0xBA19L,0xED54L,0xBA19L,0xBA19L};
        int32_t l_1240 = 0x0A242F05L;
        int8_t l_1294 = 1L;
        int i;
        for (g_332 = 3; (g_332 >= 0); g_332 -= 1)
        {
            int32_t l_1164 = 0x42FDD4A8L;
            int32_t l_1223[9][5] = {{0L,0x1ABBA624L,0x1ABBA624L,0L,0x1ABBA624L},{4L,1L,0xD60A74D5L,1L,4L},{0x1ABBA624L,0L,0x1ABBA624L,0x1ABBA624L,0L},{4L,0x32CC7F24L,0xBD2B6D24L,1L,0xBD2B6D24L},{0L,0L,0x41CEA2CCL,0L,0L},{0xBD2B6D24L,1L,0xBD2B6D24L,0x32CC7F24L,4L},{0L,0x1ABBA624L,0x1ABBA624L,0L,0x1ABBA624L},{4L,1L,0xD60A74D5L,1L,4L},{0x1ABBA624L,0L,0x1ABBA624L,0x1ABBA624L,0L}};
            uint64_t l_1300[5][3][7] = {{{0UL,0x79B3F9D776FDF340LL,0x6CE295112A9E9384LL,0xB661A51D37F22711LL,18446744073709551610UL,1UL,0xDB6D5FC273433E81LL},{0x034836C03B2DC689LL,1UL,18446744073709551608UL,1UL,7UL,1UL,18446744073709551608UL},{0xDB6D5FC273433E81LL,0xDB6D5FC273433E81LL,0UL,0x05D16A1C76A53D57LL,1UL,0xB661A51D37F22711LL,0x6CE295112A9E9384LL}},{{0x6CE295112A9E9384LL,1UL,18446744073709551612UL,0x3252ECEFE5E9D757LL,1UL,0x034836C03B2DC689LL,7UL},{18446744073709551610UL,0x3252ECEFE5E9D757LL,18446744073709551608UL,1UL,1UL,18446744073709551606UL,1UL},{0x05D16A1C76A53D57LL,18446744073709551615UL,2UL,0x79B3F9D776FDF340LL,7UL,0x8F7FB2F70B296FEELL,0x6CE295112A9E9384LL}},{{0xA2B6E572CD4F4A3DLL,18446744073709551612UL,18446744073709551610UL,0x79B3F9D776FDF340LL,18446744073709551610UL,18446744073709551612UL,0xA2B6E572CD4F4A3DLL},{18446744073709551612UL,5UL,0x034836C03B2DC689LL,1UL,0xDB6D5FC273433E81LL,18446744073709551610UL,0UL},{0x3252ECEFE5E9D757LL,0xDB6D5FC273433E81LL,0x491AF1FE4A5913F0LL,0x3252ECEFE5E9D757LL,0x05D16A1C76A53D57LL,0UL,0x79B3F9D776FDF340LL}},{{0xA2B6E572CD4F4A3DLL,18446744073709551606UL,0x034836C03B2DC689LL,0x05D16A1C76A53D57LL,0xA348622ADBEC72ABLL,0x034836C03B2DC689LL,1UL},{0xA348622ADBEC72ABLL,0xA2B6E572CD4F4A3DLL,18446744073709551610UL,1UL,0xDB6D5FC273433E81LL,1UL,1UL},{0x6EC98794B3C73DFCLL,0xA2B6E572CD4F4A3DLL,2UL,0xA2B6E572CD4F4A3DLL,0x6EC98794B3C73DFCLL,0xEF844FAB78DC1EB3LL,0xDB6D5FC273433E81LL}},{{0x6CE295112A9E9384LL,18446744073709551606UL,18446744073709551608UL,5UL,1UL,1UL,0xA2B6E572CD4F4A3DLL},{0UL,0xDB6D5FC273433E81LL,18446744073709551612UL,0xA348622ADBEC72ABLL,1UL,1UL,0x034836C03B2DC689LL},{0x6CE295112A9E9384LL,5UL,0UL,0x3252ECEFE5E9D757LL,5UL,0xCB6B9AAA9EFB2E9ELL,7UL}}};
            uint8_t l_1321 = 0x03L;
            uint64_t l_1448 = 3UL;
            int i, j, k;
            g_810 = ((!((safe_mod_func_int64_t_s_s(g_329[g_332], (safe_add_func_int8_t_s_s(0L, 0x4BL)))) || (!((safe_rshift_func_int8_t_s_s((p_44 && ((safe_rshift_func_int8_t_s_s(((((p_41 <= (safe_mod_func_int8_t_s_s(g_329[g_332], (safe_lshift_func_uint16_t_u_u(((((l_1146 = ((+l_1145) , (p_40 < ((((0x6CL < 0xB5L) <= 0x45966673L) == p_41) , p_44)))) > l_1145) < g_164) ^ g_1147), 15))))) , p_41) , g_329[0]) <= g_329[g_332]), 0)) , l_1145)), p_43)) && 255UL)))) < p_42);
            if (((p_42 = (g_777 = (((65527UL >= (((((g_329[g_332] = 0x0964L) > (0x896AL <= (safe_lshift_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((((((g_3 ^ ((safe_unary_minus_func_int8_t_s(g_180)) ^ (l_1166 = (safe_lshift_func_int8_t_s_s(((safe_sub_func_int64_t_s_s((g_836 >= (safe_add_func_int64_t_s_s((g_332 >= (((safe_mod_func_uint8_t_u_u((((safe_add_func_uint16_t_u_u((((((+(l_1164 <= l_1164)) >= l_1146) & g_332) && l_1164) , g_977), l_1164)) | g_311) <= l_1165), 4L)) && l_1145) && 0x82E1L)), l_1145))), g_180)) < 250UL), 4))))) >= l_1145) < 0xCDL) <= l_1146) < l_1146), 0x09L)) , g_332), 3)))) & g_877) < p_43) != l_1146)) , l_1146) > g_311))) | l_1145))
            {
                int64_t l_1222 = 7L;
                int32_t l_1239 = 0L;
                int64_t l_1271 = 0xE90FF5F42886629FLL;
                g_923 = (p_41 = (0xB515D37B249F97A6LL ^ ((safe_lshift_func_uint16_t_u_s((safe_add_func_uint32_t_u_u(g_836, g_877)), 6)) || (safe_add_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((p_42 = (safe_rshift_func_int16_t_s_u(((safe_add_func_int8_t_s_s((!((l_1166 = g_329[g_332]) == 0x294A85636008822DLL)), (safe_add_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u(((~p_43) , (safe_add_func_int64_t_s_s((l_1145 > (0x3F77C373L >= (((0x1BCE859916530500LL && 0xF180D4E1F6AD28F0LL) || 0x76L) || 0x406EE5E5F08477A3LL))), 0xC9C24AD94F01C2F5LL))), p_43)), g_139)))) | 3UL), 1))), 0)), g_977)), 3)), (-3L))))));
                if (g_977)
                {
                    const int16_t l_1196 = 0xBCD1L;
                    if ((+((safe_sub_func_int32_t_s_s((safe_sub_func_int64_t_s_s(l_1196, (safe_sub_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(((((l_1145 , (0x665C3853L ^ p_42)) , ((p_44 == (0x0B3C883CL && (p_44 , p_43))) > 0x63E54E52L)) , p_44) , l_1165), l_1166)), 0xECL)))), p_41)) & 1UL)))
                    {
                        int64_t l_1238 = 0L;
                        p_41 = ((safe_lshift_func_int8_t_s_u(((((safe_rshift_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_s((((g_170 = (safe_mod_func_uint64_t_u_u(1UL, (l_1164 = p_41)))) == (safe_mod_func_uint8_t_u_u(p_42, ((g_1147 = (safe_mod_func_int64_t_s_s((((-4L) ^ g_836) > (l_1223[6][1] = (safe_add_func_uint32_t_u_u(0xCF829F83L, (p_43 || (((~0L) ^ ((safe_add_func_uint8_t_u_u((((((safe_add_func_int32_t_s_s((safe_sub_func_int16_t_s_s(l_1222, 0x4603L)), 0x8AAE4AB0L)) > g_161) == 0x49EC99E9D11B8284LL) , p_43) >= l_1222), (-9L))) == 0xC67EL)) && p_43)))))), l_1224[1]))) && l_1196)))) < g_329[g_332]), g_161)) || 0xA0F6C851L), 6)) != p_44) , p_43) | p_43), 5)) ^ p_40);
                        l_1240 = (safe_lshift_func_uint8_t_u_s(0x5BL, ((safe_mod_func_int32_t_s_s((safe_rshift_func_int16_t_s_u(p_42, 1)), 3UL)) | (l_1239 = ((((safe_add_func_uint32_t_u_u((l_1166 = (((0x28185C1622F47FA4LL & l_1146) || (~(p_42 > (safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_u(0xB5L, 7)), (l_1238 = (p_41 = g_459))))))) <= (p_44 >= l_1146))), 0x5A7C9412L)) <= p_43) ^ g_161) != p_43)))));
                        g_923 = 0xD5BDB3DAL;
                        return p_42;
                    }
                    else
                    {






safe_rshift_func_uint16_t_u_u(0x6BDAL, (g_1501 != (safe_lshift_func_uint16_t_u_u(0x8A87L, g_1501))));



safe_lshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(249UL, 6)), 0);






{
                        if (g_329[1])
                            break;
                        if (g_106)
                            break;
                    }
                        return l_1222;
                    }
                }
                else
                {
{
        int64_t l_1145 = 0x268351B43BFD7F0ALL;
        int64_t l_1165 = (-1L);
        int32_t l_1166 = 0L;
        int16_t l_1224[6] = {0xED54L,0xBA19L,0xBA19L,0xED54L,0xBA19L,0xBA19L};
        int32_t l_1240 = 0x0A242F05L;
        int8_t l_1294 = 1L;
        int i;


    }
{
            int32_t l_1164 = 0x42FDD4A8L;
            int32_t l_1223[9][5] = {{0L,0x1ABBA624L,0x1ABBA624L,0L,0x1ABBA624L},{4L,1L,0xD60A74D5L,1L,4L},{0x1ABBA624L,0L,0x1ABBA624L,0x1ABBA624L,0L},{4L,0x32CC7F24L,0xBD2B6D24L,1L,0xBD2B6D24L},{0L,0L,0x41CEA2CCL,0L,0L},{0xBD2B6D24L,1L,0xBD2B6D24L,0x32CC7F24L,4L},{0L,0x1ABBA624L,0x1ABBA624L,0L,0x1ABBA624L},{4L,1L,0xD60A74D5L,1L,4L},{0x1ABBA624L,0L,0x1ABBA624L,0x1ABBA624L,0L}};
            uint64_t l_1300[5][3][7] = {{{0UL,0x79B3F9D776FDF340LL,0x6CE295112A9E9384LL,0xB661A51D37F22711LL,18446744073709551610UL,1UL,0xDB6D5FC273433E81LL},{0x034836C03B2DC689LL,1UL,18446744073709551608UL,1UL,7UL,1UL,18446744073709551608UL},{0xDB6D5FC273433E81LL,0xDB6D5FC273433E81LL,0UL,0x05D16A1C76A53D57LL,1UL,0xB661A51D37F22711LL,0x6CE295112A9E9384LL}},{{0x6CE295112A9E9384LL,1UL,18446744073709551612UL,0x3252ECEFE5E9D757LL,1UL,0x034836C03B2DC689LL,7UL},{18446744073709551610UL,0x3252ECEFE5E9D757LL,18446744073709551608UL,1UL,1UL,18446744073709551606UL,1UL},{0x05D16A1C76A53D57LL,18446744073709551615UL,2UL,0x79B3F9D776FDF340LL,7UL,0x8F7FB2F70B296FEELL,0x6CE295112A9E9384LL}},{{0xA2B6E572CD4F4A3DLL,18446744073709551612UL,18446744073709551610UL,0x79B3F9D776FDF340LL,18446744073709551610UL,18446744073709551612UL,0xA2B6E572CD4F4A3DLL},{18446744073709551612UL,5UL,0x034836C03B2DC689LL,1UL,0xDB6D5FC273433E81LL,18446744073709551610UL,0UL},{0x3252ECEFE5E9D757LL,0xDB6D5FC273433E81LL,0x491AF1FE4A5913F0LL,0x3252ECEFE5E9D757LL,0x05D16A1C76A53D57LL,0UL,0x79B3F9D776FDF340LL}},{{0xA2B6E572CD4F4A3DLL,18446744073709551606UL,0x034836C03B2DC689LL,0x05D16A1C76A53D57LL,0xA348622ADBEC72ABLL,0x034836C03B2DC689LL,1UL},{0xA348622ADBEC72ABLL,0xA2B6E572CD4F4A3DLL,18446744073709551610UL,1UL,0xDB6D5FC273433E81LL,1UL,1UL},{0x6EC98794B3C73DFCLL,0xA2B6E572CD4F4A3DLL,2UL,0xA2B6E572CD4F4A3DLL,0x6EC98794B3C73DFCLL,0xEF844FAB78DC1EB3LL,0xDB6D5FC273433E81LL}},{{0x6CE295112A9E9384LL,18446744073709551606UL,18446744073709551608UL,5UL,1UL,1UL,0xA2B6E572CD4F4A3DLL},{0UL,0xDB6D5FC273433E81LL,18446744073709551612UL,0xA348622ADBEC72ABLL,1UL,1UL,0x034836C03B2DC689LL},{0x6CE295112A9E9384LL,5UL,0UL,0x3252ECEFE5E9D757LL,5UL,0xCB6B9AAA9EFB2E9ELL,7UL}}};
            uint8_t l_1321 = 0x03L;
            uint64_t l_1448 = 3UL;
            int i, j, k;






{






if (g_977)
                {
                    const int16_t l_1196 = 0xBCD1L;
                    if ((+((safe_sub_func_int32_t_s_s((safe_sub_func_int64_t_s_s(l_1196, (safe_sub_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(((((l_1145 , (0x665C3853L ^ p_42)) , ((p_44 == (0x0B3C883CL && (p_44 , p_43))) > 0x63E54E52L)) , p_44) , l_1165), l_1166)), 0xECL)))), p_41)) & 1UL)))
                    {
                        int64_t l_1238 = 0L;
                        p_41 = ((safe_lshift_func_int8_t_s_u(((((safe_rshift_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_s((((g_170 = (safe_mod_func_uint64_t_u_u(1UL, (l_1164 = p_41)))) == (safe_mod_func_uint8_t_u_u(p_42, ((g_1147 = (safe_mod_func_int64_t_s_s((((-4L) ^ g_836) > (l_1223[6][1] = (safe_add_func_uint32_t_u_u(0xCF829F83L, (p_43 || (((~0L) ^ ((safe_add_func_uint8_t_u_u((((((safe_add_func_int32_t_s_s((safe_sub_func_int16_t_s_s(l_1222, 0x4603L)), 0x8AAE4AB0L)) > g_161) == 0x49EC99E9D11B8284LL) , p_43) >= l_1222), (-9L))) == 0xC67EL)) && p_43)))))), l_1224[1]))) && l_1196)))) < g_329[g_332]), g_161)) || 0xA0F6C851L), 6)) != p_44) , p_43) | p_43), 5)) ^ p_40);

printf("index = [%d]\n", i);



                        l_1240 = (safe_lshift_func_uint8_t_u_s(0x5BL, ((safe_mod_func_int32_t_s_s((safe_rshift_func_int16_t_s_u(p_42, 1)), 3UL)) | (l_1239 = ((((safe_add_func_uint32_t_u_u((l_1166 = (((0x28185C1622F47FA4LL & l_1146) || (~(p_42 > (safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_u(0xB5L, 7)), (l_1238 = (p_41 = g_459))))))) <= (p_44 >= l_1146))), 0x5A7C9412L)) <= p_43) ^ g_161) != p_43)))));



safe_add_func_int16_t_s_s(l_1146, 8);



                        return p_42;
                    }
                    else
                    {



safe_unary_minus_func_int64_t_s((safe_rshift_func_int8_t_s_s((g_2063[1][6] = 1L), 3)));



                        return l_1222;
                    }

safe_rshift_func_int16_t_s_u(p_42, 1);




                }
                else
                {
                    g_810 = (safe_rshift_func_uint16_t_u_s(p_41, ((!((((0UL > (p_44 ^ (+((safe_lshift_func_int8_t_s_u((((safe_rshift_func_uint16_t_u_u(g_329[1], 3)) == ((safe_mod_func_int8_t_s_s((l_1164 = (g_923 , (((((safe_sub_func_int64_t_s_s(g_459, (g_281 <= (safe_add_func_int64_t_s_s((((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u(0xA9L, 2)), 12)) , l_1146) && 0xA3L), l_1222))))) || 0x1FDDL) > l_1239) && l_1239) >= 1L))), 0xACL)) ^ g_284)) , l_1222), 2)) || p_40)))) && g_162[4][1][0]) >= 0x1D48E23BD2EB54B1LL) && p_41)) == l_1166)));
                    l_1239 = (safe_add_func_uint16_t_u_u(p_44, ((255UL != ((safe_sub_func_uint16_t_u_u(7UL, (((+0xA2615DE1L) < (safe_mod_func_uint64_t_u_u(p_41, (safe_rshift_func_uint8_t_u_s((safe_mod_func_int32_t_s_s((((+(((l_1271 < (safe_rshift_func_uint8_t_u_u(0UL, ((g_175[0][0] > (((p_40 ^ p_43) >= p_42) < 0x64483C33C346B614LL)) || 0xA6L)))) >= 0x2EL) | 0xC129L)) || l_1165) && g_75), l_1146)), g_139))))) <= l_1271))) < g_329[g_332])) ^ p_44)));

safe_lshift_func_int16_t_s_u(1L, (g_923 > ((+((g_836 < (g_175[0][0] = (((-1L) != 0x7AL) , g_164))) >= l_1223[0][0])) | 1L)));




                };
safe_lshift_func_uint16_t_u_s(g_2228, 5);







safe_unary_minus_func_uint8_t_u(((g_2228 == 0xE43EB50BL) != 4294967295UL));

{
            int32_t l_1164 = 0x42FDD4A8L;
            int32_t l_1223[9][5] = {{0L,0x1ABBA624L,0x1ABBA624L,0L,0x1ABBA624L},{4L,1L,0xD60A74D5L,1L,4L},{0x1ABBA624L,0L,0x1ABBA624L,0x1ABBA624L,0L},{4L,0x32CC7F24L,0xBD2B6D24L,1L,0xBD2B6D24L},{0L,0L,0x41CEA2CCL,0L,0L},{0xBD2B6D24L,1L,0xBD2B6D24L,0x32CC7F24L,4L},{0L,0x1ABBA624L,0x1ABBA624L,0L,0x1ABBA624L},{4L,1L,0xD60A74D5L,1L,4L},{0x1ABBA624L,0L,0x1ABBA624L,0x1ABBA624L,0L}};
            uint64_t l_1300[5][3][7] = {{{0UL,0x79B3F9D776FDF340LL,0x6CE295112A9E9384LL,0xB661A51D37F22711LL,18446744073709551610UL,1UL,0xDB6D5FC273433E81LL},{0x034836C03B2DC689LL,1UL,18446744073709551608UL,1UL,7UL,1UL,18446744073709551608UL},{0xDB6D5FC273433E81LL,0xDB6D5FC273433E81LL,0UL,0x05D16A1C76A53D57LL,1UL,0xB661A51D37F22711LL,0x6CE295112A9E9384LL}},{{0x6CE295112A9E9384LL,1UL,18446744073709551612UL,0x3252ECEFE5E9D757LL,1UL,0x034836C03B2DC689LL,7UL},{18446744073709551610UL,0x3252ECEFE5E9D757LL,18446744073709551608UL,1UL,1UL,18446744073709551606UL,1UL},{0x05D16A1C76A53D57LL,18446744073709551615UL,2UL,0x79B3F9D776FDF340LL,7UL,0x8F7FB2F70B296FEELL,0x6CE295112A9E9384LL}},{{0xA2B6E572CD4F4A3DLL,18446744073709551612UL,18446744073709551610UL,0x79B3F9D776FDF340LL,18446744073709551610UL,18446744073709551612UL,0xA2B6E572CD4F4A3DLL},{18446744073709551612UL,5UL,0x034836C03B2DC689LL,1UL,0xDB6D5FC273433E81LL,18446744073709551610UL,0UL},{0x3252ECEFE5E9D757LL,0xDB6D5FC273433E81LL,0x491AF1FE4A5913F0LL,0x3252ECEFE5E9D757LL,0x05D16A1C76A53D57LL,0UL,0x79B3F9D776FDF340LL}},{{0xA2B6E572CD4F4A3DLL,18446744073709551606UL,0x034836C03B2DC689LL,0x05D16A1C76A53D57LL,0xA348622ADBEC72ABLL,0x034836C03B2DC689LL,1UL},{0xA348622ADBEC72ABLL,0xA2B6E572CD4F4A3DLL,18446744073709551610UL,1UL,0xDB6D5FC273433E81LL,1UL,1UL},{0x6EC98794B3C73DFCLL,0xA2B6E572CD4F4A3DLL,2UL,0xA2B6E572CD4F4A3DLL,0x6EC98794B3C73DFCLL,0xEF844FAB78DC1EB3LL,0xDB6D5FC273433E81LL}},{{0x6CE295112A9E9384LL,18446744073709551606UL,18446744073709551608UL,5UL,1UL,1UL,0xA2B6E572CD4F4A3DLL},{0UL,0xDB6D5FC273433E81LL,18446744073709551612UL,0xA348622ADBEC72ABLL,1UL,1UL,0x034836C03B2DC689LL},{0x6CE295112A9E9384LL,5UL,0UL,0x3252ECEFE5E9D757LL,5UL,0xCB6B9AAA9EFB2E9ELL,7UL}}};
            uint8_t l_1321 = 0x03L;
            uint64_t l_1448 = 3UL;
            int i, j, k;
            g_810 = ((!((safe_mod_func_int64_t_s_s(g_329[g_332], (safe_add_func_int8_t_s_s(0L, 0x4BL)))) || (!((safe_rshift_func_int8_t_s_s((p_44 && ((safe_rshift_func_int8_t_s_s(((((p_41 <= (safe_mod_func_int8_t_s_s(g_329[g_332], (safe_lshift_func_uint16_t_u_u(((((l_1146 = ((+l_1145) , (p_40 < ((((0x6CL < 0xB5L) <= 0x45966673L) == p_41) , p_44)))) > l_1145) < g_164) ^ g_1147), 15))))) , p_41) , g_329[0]) <= g_329[g_332]), 0)) , l_1145)), p_43)) && 255UL)))) < p_42);
            if (((p_42 = (g_777 = (((65527UL >= (((((g_329[g_332] = 0x0964L) > (0x896AL <= (safe_lshift_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((((((g_3 ^ ((safe_unary_minus_func_int8_t_s(g_180)) ^ (l_1166 = (safe_lshift_func_int8_t_s_s(((safe_sub_func_int64_t_s_s((g_836 >= (safe_add_func_int64_t_s_s((g_332 >= (((safe_mod_func_uint8_t_u_u((((safe_add_func_uint16_t_u_u((((((+(l_1164 <= l_1164)) >= l_1146) & g_332) && l_1164) , g_977), l_1164)) | g_311) <= l_1165), 4L)) && l_1145) && 0x82E1L)), l_1145))), g_180)) < 250UL), 4))))) >= l_1145) < 0xCDL) <= l_1146) < l_1146), 0x09L)) , g_332), 3)))) & g_877) < p_43) != l_1146)) , l_1146) > g_311))) | l_1145))
            {
                int64_t l_1222 = 7L;
                int32_t l_1239 = 0L;
                int64_t l_1271 = 0xE90FF5F42886629FLL;
                g_923 = (p_41 = (0xB515D37B249F97A6LL ^ ((safe_lshift_func_uint16_t_u_s((safe_add_func_uint32_t_u_u(g_836, g_877)), 6)) || (safe_add_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((p_42 = (safe_rshift_func_int16_t_s_u(((safe_add_func_int8_t_s_s((!((l_1166 = g_329[g_332]) == 0x294A85636008822DLL)), (safe_add_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u(((~p_43) , (safe_add_func_int64_t_s_s((l_1145 > (0x3F77C373L >= (((0x1BCE859916530500LL && 0xF180D4E1F6AD28F0LL) || 0x76L) || 0x406EE5E5F08477A3LL))), 0xC9C24AD94F01C2F5LL))), p_43)), g_139)))) | 3UL), 1))), 0)), g_977)), 3)), (-3L))))));
                if (g_977)
                {
                    const int16_t l_1196 = 0xBCD1L;
                    if ((+((safe_sub_func_int32_t_s_s((safe_sub_func_int64_t_s_s(l_1196, (safe_sub_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(((((l_1145 , (0x665C3853L ^ p_42)) , ((p_44 == (0x0B3C883CL && (p_44 , p_43))) > 0x63E54E52L)) , p_44) , l_1165), l_1166)), 0xECL)))), p_41)) & 1UL)))
                    {
                        int64_t l_1238 = 0L;
                        p_41 = ((safe_lshift_func_int8_t_s_u(((((safe_rshift_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_s((((g_170 = (safe_mod_func_uint64_t_u_u(1UL, (l_1164 = p_41)))) == (safe_mod_func_uint8_t_u_u(p_42, ((g_1147 = (safe_mod_func_int64_t_s_s((((-4L) ^ g_836) > (l_1223[6][1] = (safe_add_func_uint32_t_u_u(0xCF829F83L, (p_43 || (((~0L) ^ ((safe_add_func_uint8_t_u_u((((((safe_add_func_int32_t_s_s((safe_sub_func_int16_t_s_s(l_1222, 0x4603L)), 0x8AAE4AB0L)) > g_161) == 0x49EC99E9D11B8284LL) , p_43) >= l_1222), (-9L))) == 0xC67EL)) && p_43)))))), l_1224[1]))) && l_1196)))) < g_329[g_332]), g_161)) || 0xA0F6C851L), 6)) != p_44) , p_43) | p_43), 5)) ^ p_40);
                        l_1240 = (safe_lshift_func_uint8_t_u_s(0x5BL, ((safe_mod_func_int32_t_s_s((safe_rshift_func_int16_t_s_u(p_42, 1)), 3UL)) | (l_1239 = ((((safe_add_func_uint32_t_u_u((l_1166 = (((0x28185C1622F47FA4LL & l_1146) || (~(p_42 > (safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_u(0xB5L, 7)), (l_1238 = (p_41 = g_459))))))) <= (p_44 >= l_1146))), 0x5A7C9412L)) <= p_43) ^ g_161) != p_43)))));
                        g_923 = 0xD5BDB3DAL;
                        return p_42;
                    }
                    else
                    {
                        l_1146 = ((g_253 = g_57) && l_1196);
                        return l_1222;
                    }
                }
                else
                {
                    g_810 = (safe_rshift_func_uint16_t_u_s(p_41, ((!((((0UL > (p_44 ^ (+((safe_lshift_func_int8_t_s_u((((safe_rshift_func_uint16_t_u_u(g_329[1], 3)) == ((safe_mod_func_int8_t_s_s((l_1164 = (g_923 , (((((safe_sub_func_int64_t_s_s(g_459, (g_281 <= (safe_add_func_int64_t_s_s((((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u(0xA9L, 2)), 12)) , l_1146) && 0xA3L), l_1222))))) || 0x1FDDL) > l_1239) && l_1239) >= 1L))), 0xACL)) ^ g_284)) , l_1222), 2)) || p_40)))) && g_162[4][1][0]) >= 0x1D48E23BD2EB54B1LL) && p_41)) == l_1166)));
                    l_1239 = (safe_add_func_uint16_t_u_u(p_44, ((255UL != ((safe_sub_func_uint16_t_u_u(7UL, (((+0xA2615DE1L) < (safe_mod_func_uint64_t_u_u(p_41, (safe_rshift_func_uint8_t_u_s((safe_mod_func_int32_t_s_s((((+(((l_1271 < (safe_rshift_func_uint8_t_u_u(0UL, ((g_175[0][0] > (((p_40 ^ p_43) >= p_42) < 0x64483C33C346B614LL)) || 0xA6L)))) >= 0x2EL) | 0xC129L)) || l_1165) && g_75), l_1146)), g_139))))) <= l_1271))) < g_329[g_332])) ^ p_44)));
                }
                for (g_312 = (-13); (g_312 == 22); g_312 = safe_add_func_int32_t_s_s(g_312, 6))
                {
                    int8_t l_1292 = (-3L);
                    if (g_462)
                    {
                        return g_253;
                    }
                    else
                    {
                        g_810 = 1L;
                        g_923 = (g_810 = ((((safe_lshift_func_uint16_t_u_s((0xEAL || g_312), 15)) , 0xFAL) != (((safe_sub_func_int32_t_s_s((safe_rshift_func_uint8_t_u_s(((g_329[g_332] | ((safe_sub_func_uint32_t_u_u(g_1284[0], (l_1166 = (safe_add_func_int64_t_s_s(((safe_mod_func_uint16_t_u_u(((((((safe_lshift_func_int16_t_s_u(1L, (g_923 > ((+((g_836 < (g_175[0][0] = (((-1L) != 0x7AL) , g_164))) >= l_1223[0][0])) | 1L)))) , g_777) ^ g_332) , g_810) > 0xB2C6CCC9L) , p_41), 0xE1D2L)) && 18446744073709551615UL), g_253))))) > p_42)) , g_312), p_41)), 0xB9EA4649L)) , p_44) | 0x2E010650L)) >= l_1146));
                        l_1292 = 0x1CB84381L;
                        if (l_1146)
                            continue;
                    }
                    if (p_44)
                        continue;
                    l_1239 = l_1146;
                    g_1293[3][0] = g_991;
                }
            }
            else
            {
                int16_t l_1301[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_1301[i] = (-5L);
                l_1294 = p_44;
                l_1146 = 0x12282C6DL;
                if (((!(l_1224[1] < ((safe_add_func_uint64_t_u_u((l_1164 && 1UL), (l_1294 < (p_42 = (((((safe_rshift_func_int8_t_s_u((p_41 | g_175[0][0]), 4)) != (l_1300[3][0][5] != g_161)) != ((l_1301[2] = (g_1284[0] || 0xFBF20896BDA39544LL)) != g_462)) | l_1240) > p_44))))) > 18446744073709551614UL))) < g_381))
                {
                    int16_t l_1302 = 0x4DD2L;
                    int32_t l_1305 = 6L;
                    p_41 = g_281;
                    g_381 = (p_41 = l_1302);
                    for (g_552 = (-4); (g_552 < 39); g_552 = safe_add_func_uint64_t_u_u(g_552, 1))
                    {
                        l_1305 = g_224;
                        p_41 = p_41;
                    }
                }
                else
                {
                    uint32_t l_1312 = 0x5A26CB73L;
                    if (l_1301[1])
                        break;
                    g_381 = (g_923 = (safe_add_func_int16_t_s_s((safe_mod_func_int8_t_s_s(p_42, (((g_175[0][1] = (g_284 <= g_777)) & (safe_lshift_func_int16_t_s_s((p_43 = (l_1312 > l_1223[0][2])), 10))) ^ ((((l_1321 = (safe_add_func_int32_t_s_s(g_170, (((((g_552 = (((safe_mod_func_int64_t_s_s(((safe_sub_func_int8_t_s_s(g_923, 0x3EL)) , g_1039), l_1300[3][0][5])) && (-10L)) >= g_284)) == (-10L)) >= 0UL) | g_977) || 0L)))) & l_1166) > g_57) >= p_41)))), 0x9CA8L)));
                }
                p_41 = l_1146;
            }
            for (l_1166 = (-2); (l_1166 != 24); l_1166 = safe_add_func_uint16_t_u_u(l_1166, 3))
            {
                int64_t l_1332 = 1L;
                uint32_t l_1340 = 5UL;
                int32_t l_1354 = 7L;
                uint32_t l_1370 = 0x3880CD47L;
                int32_t l_1384[6] = {0x1F96687BL,(-9L),(-9L),0x1F96687BL,(-9L),(-9L)};
                int i;
                if ((l_1240 = ((g_311 = (safe_sub_func_int16_t_s_s((l_1146 , ((0xC598F3B9L > (safe_rshift_func_int16_t_s_u(g_777, ((((((l_1146 = l_1146) | ((0x2C880FCAL <= ((safe_rshift_func_uint16_t_u_u(((((((l_1164 = p_41) != p_41) <= g_4) ^ ((((safe_lshift_func_int16_t_s_s((0L & g_281), 10)) , 0x2A924B8E267FA17ELL) > l_1332) & 0x205BBF4EL)) || p_44) != p_42), 6)) ^ l_1300[4][1][5])) ^ 5UL)) != l_1333) && p_42) == 4UL) <= l_1240)))) , g_977)), l_1300[3][0][5]))) < (-8L))))
                {
                    uint32_t l_1383 = 18446744073709551615UL;
                    for (g_164 = 0; (g_164 > 48); g_164 = safe_add_func_int8_t_s_s(g_164, 5))
                    {
                        g_810 = 0x181F8850L;
                        g_810 = p_44;
                        p_41 = (safe_rshift_func_int8_t_s_u(g_361, 7));
                        p_41 = l_1300[1][0][1];
                    }
                    p_41 = (l_1354 = ((0x4D284E96L ^ p_42) > ((g_175[0][1] = ((safe_mod_func_uint64_t_u_u((((g_75 = 1L) & ((((0x2BEB6C96016B513ELL != ((((g_810 = ((l_1340 , (safe_rshift_func_int16_t_s_s(((safe_mod_func_int16_t_s_s((g_329[1] = g_164), (safe_add_func_int64_t_s_s((safe_sub_func_uint16_t_u_u((safe_add_func_int32_t_s_s(g_810, ((p_40 & ((+(((((safe_rshift_func_uint8_t_u_u((g_224 & 0UL), p_43)) | 5UL) | p_44) < 0xD0L) == g_162[0][0][0])) == g_810)) > g_1147))), p_43)), p_41)))) >= 0xF4CBL), 14))) < g_177)) , g_329[1]) ^ g_177) , l_1223[4][2])) == l_1165) || 0xABL) < l_1164)) != g_361), g_175[0][0])) , 65530UL)) != 1L)));
                    for (l_1146 = 0; (l_1146 > 10); l_1146 = safe_add_func_int16_t_s_s(l_1146, 8))
                    {
                        uint32_t l_1382[7][10] = {{0x9410B6A4L,0x5E4BB901L,0xB8AB1B87L,0xE4DB0C36L,8UL,1UL,4294967288UL,0xDB352E1BL,4294967286UL,7UL},{0x56D101F7L,0x8520A335L,8UL,0UL,1UL,0UL,8UL,0x8520A335L,0x56D101F7L,0UL},{7UL,1UL,0UL,0UL,5UL,0xDB352E1BL,1UL,4294967286UL,0xB8AB1B87L,0x56D101F7L},{4294967286UL,0x59F369F9L,0x1C0FFB8AL,0UL,1UL,5UL,1UL,3UL,0x56D101F7L,0xDB352E1BL},{4294967288UL,4294967286UL,4294967286UL,0UL,0x854C9413L,0x854C9413L,0UL,4294967286UL,4294967286UL,4294967288UL},{5UL,4294967286UL,0x8520A335L,0xE4DB0C36L,2UL,1UL,0xDB352E1BL,0xB8AB1B87L,1UL,1UL},{0UL,0x4B624222L,3UL,4294967286UL,2UL,0x5E4BB901L,5UL,1UL,0xCEF3A793L,4294967288UL}};
                        int i, j;
                        g_381 = ((safe_lshift_func_uint8_t_u_u(((p_44 & (!(((l_1384[0] = (safe_lshift_func_int16_t_s_u(0x09A9L, ((safe_mod_func_int32_t_s_s((safe_sub_func_int8_t_s_s((safe_mod_func_int16_t_s_s((l_1370 = (safe_lshift_func_uint8_t_u_u((0L <= (g_1118[0] & l_1224[1])), (l_1354 = p_41)))), (((((safe_mod_func_int16_t_s_s(((((l_1383 = (safe_rshift_func_int16_t_s_s((~((safe_sub_func_uint32_t_u_u((((((((safe_lshift_func_uint8_t_u_s((((safe_add_func_int32_t_s_s(0x6FA72E24L, ((((((((p_41 != g_1284[0]) >= p_41) ^ g_139) && g_991) <= g_311) ^ g_329[1]) > g_777) != p_43))) || 0xD049D5F010CE4FECLL) && p_40), g_175[0][0])) | g_1284[0]) <= 0xF2L) != (-1L)) , 1L) && g_1293[3][0]) > 0x1307DFC3F76346B1LL), p_44)) <= p_44)), l_1382[1][2]))) , p_41) | p_42) , l_1383), l_1300[2][1][3])) && p_41) ^ 0xCFF352DCL) && g_4) & g_75))), l_1340)), g_1147)) >= l_1382[0][0])))) , 0L) , g_75))) <= 8UL), 5)) & g_301);
                        g_381 = ((0UL <= 0xCE49L) < ((safe_add_func_uint64_t_u_u(((+(1L <= ((((l_1333 = ((safe_lshift_func_int8_t_s_s((safe_unary_minus_func_uint8_t_u(247UL)), 2)) > (l_1382[1][4] , ((safe_sub_func_uint32_t_u_u((((+((l_1223[2][4] = ((safe_mod_func_uint64_t_u_u((g_552 = g_329[2]), g_877)) , ((g_162[4][1][0] && ((p_42 = 0xEBL) <= 0xA3L)) < 0xB2984E3CL))) , 0x74C1D976L)) < l_1384[0]) >= p_44), (-2L))) && g_139)))) && l_1382[0][8]) >= 4294967288UL) != 1UL))) , l_1332), p_44)) || 1UL));
                        if (l_1382[1][2])
                            break;
                    }
                }
                else
                {
                    int32_t l_1410 = (-10L);
                    int32_t l_1411[3][8][2] = {{{4L,6L},{6L,4L},{6L,6L},{4L,6L},{6L,4L},{6L,6L},{4L,6L},{4L,(-5L)}},{{4L,4L},{(-5L),4L},{4L,(-5L)},{4L,4L},{(-5L),4L},{4L,(-5L)},{4L,4L},{(-5L),4L}},{{4L,(-5L)},{4L,4L},{(-5L),4L},{4L,(-5L)},{4L,4L},{(-5L),4L},{4L,(-5L)},{4L,4L}}};
                    int i, j, k;
                    g_381 = (((l_1223[4][1] = (((-3L) ^ (p_41 = ((safe_mod_func_int16_t_s_s((g_877 = (safe_rshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u((65535UL > (((safe_add_func_uint8_t_u_u(p_40, (((l_1410 = (safe_mod_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u(g_1284[0], (0x99L || (((((g_170 && 0UL) && ((-1L) | p_40)) , 0xB02912D7L) > p_44) || l_1223[6][1])))) > 0x94FC9523EB2B033FLL) ^ p_44), l_1333)), 0x77BBL))) <= 1UL) != l_1384[0]))) & l_1411[2][4][0]) <= l_1240)), 0xA46F5777L)) , 0x2F43L), 10))), g_162[4][1][0])) < l_1384[3]))) & g_57)) , p_44) || l_1300[1][1][4]);
                    l_1223[2][1] = (p_41 = (((!(-4L)) > p_40) , (+(safe_sub_func_int16_t_s_s(((safe_sub_func_uint8_t_u_u(((safe_unary_minus_func_uint8_t_u((((((((((0xB2L != ((!((safe_unary_minus_func_int16_t_s(((g_301 & (safe_rshift_func_int16_t_s_u((p_43 = ((l_1240 = (((((g_311 = ((safe_mod_func_int8_t_s_s(p_44, (safe_add_func_uint8_t_u_u(((safe_unary_minus_func_int8_t_s((0x9F1CF9F1C6DA929BLL | (g_1293[4][1] = (safe_add_func_int16_t_s_s(p_41, g_1118[0])))))) | (safe_sub_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_u((255UL == g_1434), l_1224[1])) , 0xB6A4BF32L), g_224))), 0x3CL)))) & 0x28L)) != g_281) || g_459) ^ g_329[g_332]) > 1L)) , 8L)), 15))) && p_43))) & g_164)) , p_43)) < l_1384[1]) <= 0x4EL) , (-1L)) | (-10L)) || 0xE50174D44DBABA5ALL) & 0x0A2B2D7FL) ^ l_1166) ^ 0xB9L))) && 0x34F19B84L), 0L)) , 7L), p_44)))));
                    for (p_42 = (-3); (p_42 > 45); ++p_42)
                    {
                        g_381 = p_42;
                        if (p_44)
                            break;
                        if (l_1321)
                            break;
                        return g_1293[3][0];
                    }
                }
                g_381 = (safe_lshift_func_int8_t_s_s((((safe_mod_func_uint32_t_u_u(l_1370, (safe_lshift_func_uint16_t_u_u(((l_1333 = ((g_329[2] = (safe_unary_minus_func_int64_t_s(p_40))) > 0xB5C9L)) > (safe_sub_func_int8_t_s_s(3L, (p_44 > 0UL)))), 14)))) | (((safe_rshift_func_uint16_t_u_s((l_1448 = l_1146), g_1118[0])) , ((safe_add_func_uint64_t_u_u(((l_1384[0] || g_1284[0]) == g_170), p_41)) , 0L)) > 0x9AL)) , 0x71L), 7));
                if (p_41)
                    continue;
            }
            l_1223[6][1] = ((safe_add_func_int32_t_s_s(((((safe_sub_func_uint64_t_u_u(g_462, (1L && (g_991 && ((safe_add_func_uint64_t_u_u(g_144, (((g_991 = (safe_lshift_func_int16_t_s_s((l_1333 = (g_329[1] = ((~(l_1294 >= ((l_1321 , (safe_mod_func_uint8_t_u_u((((safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(g_175[0][0], g_106)), (safe_mod_func_int64_t_s_s((+((0x0CL < 0xD4L) > 0x7F384AABL)), p_44)))) | p_40) < g_1293[3][0]), l_1321))) , p_40))) | l_1165))), 4))) >= p_41) < g_144))) <= g_977))))) <= g_877) , g_170) , l_1333), 9UL)) ^ g_311);
        }
                        return g_1293[3][0];
                    }

            for (l_1166 = (-2); (l_1166 != 24); l_1166 = safe_add_func_uint16_t_u_u(l_1166, 3))
            {
                int64_t l_1332 = 1L;
                uint32_t l_1340 = 5UL;
                int32_t l_1354 = 7L;
                uint32_t l_1370 = 0x3880CD47L;
                int32_t l_1384[6] = {0x1F96687BL,(-9L),(-9L),0x1F96687BL,(-9L),(-9L)};
                int i;


safe_rshift_func_int16_t_s_u((p_43 = ((l_1240 = (((((g_311 = ((safe_mod_func_int8_t_s_s(p_44, (safe_add_func_uint8_t_u_u(((safe_unary_minus_func_int8_t_s((0x9F1CF9F1C6DA929BLL | (g_1293[4][1] = (safe_add_func_int16_t_s_s(p_41, g_1118[0])))))) | (safe_sub_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_u((255UL == g_1434), l_1224[1])) , 0xB6A4BF32L), g_224))), 0x3CL)))) & 0x28L)) != g_281) || g_459) ^ g_329[g_332]) > 1L)) , 8L)), 15);

                g_381 = (safe_lshift_func_int8_t_s_s((((safe_mod_func_uint32_t_u_u(l_1370, (safe_lshift_func_uint16_t_u_u(((l_1333 = ((g_329[2] = (safe_unary_minus_func_int64_t_s(p_40))) > 0xB5C9L)) > (safe_sub_func_int8_t_s_s(3L, (p_44 > 0UL)))), 14)))) | (((safe_rshift_func_uint16_t_u_s((l_1448 = l_1146), g_1118[0])) , ((safe_add_func_uint64_t_u_u(((l_1384[0] || g_1284[0]) == g_170), p_41)) , 0L)) > 0x9AL)) , 0x71L), 7));


safe_rshift_func_uint16_t_u_s((((0x738BF81FL ^ ((g_1717[3] ^ g_1118[0]) && 6L)) && 65535UL) == 0xD9L), 2);

            }
for (p_42 = (-3); (p_42 > 45); ++p_42)
                    {
                        g_381 = p_42;
                        if (p_44)
                            break;
                        if (l_1321)
                            break;
                        return g_1293[3][0];
                    };



if (g_162[4][1][0])
                            continue;

        }







                }




            }
            else
            {
                int16_t l_1301[3];
                int i;
{







                    }
printf("index = [%d][%d][%d]\n", i, j, k);

printf("index = [%d][%d]\n", i, j);



safe_rshift_func_uint8_t_u_s(0xB7L, 7);

safe_lshift_func_uint16_t_u_u(0x8A87L, g_1501);






safe_sub_func_uint32_t_u_u(g_224, 0xA7BB40B2L);

g_164 += 1;






{
                    int16_t l_1302 = 0x4DD2L;
                    int32_t l_1305 = 6L;






g_3 -= 1;

safe_lshift_func_uint16_t_u_s(l_1547, (((safe_unary_minus_func_uint16_t_u(g_361)) , p_43) < (((p_44 = 18446744073709551615UL) > 0xE365929AE54D6ACCLL) <= (safe_lshift_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u((l_1563 , 0x03L), 3)), g_777)))));
safe_lshift_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u((l_1563 , 0x03L), 3)), g_777);


                    for (g_552 = (-4); (g_552 < 39); g_552 = safe_add_func_uint64_t_u_u(g_552, 1))
                    {





safe_lshift_func_int16_t_s_u(g_329[1], g_281);




                        p_41 = p_41;

safe_rshift_func_uint8_t_u_u(0xA9L, 2);







safe_sub_func_int32_t_s_s((safe_rshift_func_uint8_t_u_s(((g_329[g_332] | ((safe_sub_func_uint32_t_u_u(g_1284[0], (l_1166 = (safe_add_func_int64_t_s_s(((safe_mod_func_uint16_t_u_u(((((((safe_lshift_func_int16_t_s_u(1L, (g_923 > ((+((g_836 < (g_175[0][0] = (((-1L) != 0x7AL) , g_164))) >= l_1223[0][0])) | 1L)))) , g_777) ^ g_332) , g_810) > 0xB2C6CCC9L) , p_41), 0xE1D2L)) && 18446744073709551615UL), g_253))))) > p_42)) , g_312), p_41)), 0xB9EA4649L);



safe_lshift_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((((((g_3 ^ ((safe_unary_minus_func_int8_t_s(g_180)) ^ (l_1166 = (safe_lshift_func_int8_t_s_s(((safe_sub_func_int64_t_s_s((g_836 >= (safe_add_func_int64_t_s_s((g_332 >= (((safe_mod_func_uint8_t_u_u((((safe_add_func_uint16_t_u_u((((((+(l_1164 <= l_1164)) >= l_1146) & g_332) && l_1164) , g_977), l_1164)) | g_311) <= l_1165), 4L)) && l_1145) && 0x82E1L)), l_1145))), g_180)) < 250UL), 4))))) >= l_1145) < 0xCDL) <= l_1146) < l_1146), 0x09L)) , g_332), 3);

safe_rshift_func_int8_t_s_u(0L, 4);






                    }

for (p_42 = (-3); (p_42 > 45); ++p_42)
                    {
                        g_381 = p_42;
                        if (p_44)
                            break;
                        if (l_1321)
                            break;
                        return g_1293[3][0];
                    };
                }
{
                int16_t l_1301[3];
                int i;
safe_add_func_int32_t_s_s(g_144, 9);

safe_lshift_func_int16_t_s_u(1L, (g_923 > ((+((g_836 < (g_175[0][0] = (((-1L) != 0x7AL) , g_164))) >= l_1223[0][0])) | 1L)));
            }
            }





        }
    }

    return l_1146;
}





inline static int32_t func_45(int32_t p_46, uint8_t p_47, uint32_t p_48, const int16_t p_49, int16_t p_50)
{
    int8_t l_1128 = (-4L);
    for (g_170 = (-5); (g_170 != (-13)); g_170 = safe_sub_func_uint16_t_u_u(g_170, 8))
    {
        return g_180;
    }


{
                    }

    return g_991;
}





inline static uint64_t func_55(int8_t p_56)
{
    uint32_t l_64 = 0x66AB0C02L;
    int32_t l_1123 = 0xC7529DAAL;
    l_1123 = (0x3DL && (func_62(l_64) <= l_64));
    return g_175[0][0];
}





static uint8_t func_62(int32_t p_63)
{
    uint16_t l_65 = 9UL;
    int64_t l_104[7];
    int32_t l_105[10] = {(-2L),(-2L),(-5L),(-2L),(-2L),(-5L),(-2L),(-2L),(-5L),(-2L)};
    int32_t l_134[3][5][1] = {{{0L},{(-4L)},{0L},{0L},{(-4L)}},{{0L},{0L},{(-4L)},{0L},{0L}},{{(-4L)},{0L},{0L},{(-4L)},{0L}}};
    uint16_t l_136 = 65532UL;
    int32_t l_137 = (-9L);
    uint8_t l_328 = 0x79L;
    uint32_t l_330 = 1UL;
    int16_t l_441[3][10] = {{1L,4L,4L,1L,4L,4L,1L,4L,4L,1L},{4L,1L,4L,4L,1L,4L,4L,1L,4L,4L},{1L,1L,0xF7EEL,1L,1L,0xF7EEL,1L,1L,0xF7EEL,1L}};
    int8_t l_508 = (-3L);
    uint16_t l_689 = 0xE86CL;
    int32_t l_1015 = 0xC15DBA19L;
    int8_t l_1038 = 0xD3L;
    uint32_t l_1104 = 0x16E03CB8L;
    int i, j, k;
    for (i = 0; i < 7; i++)
        l_104[i] = 1L;
lbl_1120:
    if (((l_105[7] = (g_3 & ((1L || (l_65 || ((l_65 , l_65) <= g_57))) != func_18(((func_18(g_3, (safe_unary_minus_func_uint16_t_u(((g_106 = (((((((l_105[7] = (func_18((safe_mod_func_int16_t_s_s(((safe_rshift_func_int8_t_s_u((func_71(l_65, (((l_65 <= 0x3A649E5A9921A3E7LL) , 0UL) , l_65)) != 0x9FA0L), l_104[5])) <= 0x3EL), g_57)), l_104[5], g_57) <= l_65)) >= p_63) < 0x3C89L) > l_65) || g_4) <= g_3) <= 0x2229L)) || l_105[4]))), g_3) , 65535UL) >= l_104[0]), p_63, p_63)))) , p_63))
    {
        int32_t l_113 = 0x9D6AE766L;
        uint8_t l_135 = 255UL;
        int16_t l_138 = 0x13D6L;
        uint32_t l_140[10][8][3] = {{{0UL,0xEB405AA7L,18446744073709551615UL},{0x791A1269L,0xA8B0A815L,0UL},{5UL,18446744073709551615UL,0x506A2FBDL},{0x4288E96AL,18446744073709551613UL,0x4288E96AL},{1UL,0x5474206EL,0x2682AE03L},{0xA70A41DFL,18446744073709551615UL,0UL},{0xAF555DEFL,18446744073709551615UL,2UL},{0xA473E467L,18446744073709551613UL,0x46DF66ADL}},{{0xAF555DEFL,0x325ED220L,0xDD3F592DL},{0xA70A41DFL,0xA8B0A815L,0x89039BF0L},{0x76BD683BL,0xEF36B230L,18446744073709551615UL},{18446744073709551615UL,18446744073709551615UL,0x88608D2DL},{0x325ED220L,0xF2E056CAL,0x890DC26BL},{0xD2D4BDACL,1UL,1UL},{0xE8D4ABBEL,0UL,0xAF555DEFL},{1UL,18446744073709551615UL,6UL}},{{18446744073709551615UL,18446744073709551608UL,0xC583338DL},{9UL,0xD2D4BDACL,1UL},{1UL,0x2A7893A0L,0x8F621FC3L},{0xF2AD2962L,0xF2AD2962L,18446744073709551606UL},{0x37C55731L,0xC0FF1A9AL,0x17A08BB5L},{0xECB71139L,0x791A1269L,1UL},{0x890DC26BL,0xDD3F592DL,0x41CDB462L},{0x46DF66ADL,0xECB71139L,1UL}},{{0x865C7AE3L,0x2682AE03L,0x17A08BB5L},{18446744073709551615UL,18446744073709551607UL,18446744073709551606UL},{18446744073709551608UL,1UL,0x8F621FC3L},{0xFDFF98C6L,0x78152941L,1UL},{0x42BE2F30L,0x96934F3FL,0xC583338DL},{0x5446B8ABL,0x4288E96AL,6UL},{0xAA970772L,0x17A08BB5L,0xAF555DEFL},{0x89039BF0L,0x31F71B9FL,1UL}},{{5UL,0x865C7AE3L,0x890DC26BL},{1UL,18446744073709551609UL,0x88608D2DL},{0x96934F3FL,18446744073709551615UL,18446744073709551615UL},{1UL,18446744073709551614UL,0x89039BF0L},{0x2A7893A0L,0x171A507DL,0xDD3F592DL},{18446744073709551609UL,1UL,0x46DF66ADL},{1UL,0x42BE2F30L,2UL},{0xD2E18EF8L,1UL,0UL}},{{18446744073709551615UL,0x171A507DL,0x2682AE03L},{0x73FAD3D2L,18446744073709551614UL,18446744073709551615UL},{0xEF36B230L,18446744073709551615UL,18446744073709551615UL},{18446744073709551614UL,18446744073709551609UL,0x26EBD826L},{0x8FBBB315L,0x865C7AE3L,1UL},{0x679AD97AL,0x31F71B9FL,18446744073709551609UL},{0UL,0x17A08BB5L,0x06F4486BL},{0x26EBD826L,0x4288E96AL,0x78152941L}},{{0xF2E056CAL,0x96934F3FL,0xE8D4ABBEL},{0x791A1269L,0x78152941L,0xECB71139L},{0xB4891D5CL,1UL,0xB4891D5CL},{1UL,18446744073709551607UL,18446744073709551615UL},{0xE32BD85DL,0x2682AE03L,0UL},{0x68102DB9L,0xECB71139L,0x4288E96AL},{0x8F621FC3L,0xDD3F592DL,1UL},{0x68102DB9L,0x791A1269L,18446744073709551613UL}},{{0xE32BD85DL,0xC0FF1A9AL,0xAA970772L},{1UL,0xF2AD2962L,0x679AD97AL},{0xB4891D5CL,0x2A7893A0L,0x9D11088DL},{0x791A1269L,0xD2D4BDACL,0xD2E18EF8L},{0xF2E056CAL,18446744073709551608UL,0x42BE2F30L},{0x26EBD826L,18446744073709551615UL,0x68102DB9L},{0UL,0UL,18446744073709551608UL},{0x679AD97AL,1UL,0x31F71B9FL}},{{0x8FBBB315L,0xF2E056CAL,0x76BD683BL},{18446744073709551614UL,18446744073709551615UL,0xA473E467L},{0xEF36B230L,0xEF36B230L,0x9DAF4E67L},{0x73FAD3D2L,0xA8B0A815L,18446744073709551615UL},{18446744073709551615UL,0xF2E056CAL,0x06F4486BL},{0x68102DB9L,0xF2AD2962L,18446744073709551615UL},{18446744073709551608UL,18446744073709551615UL,0x06F4486BL},{1UL,0xD2E18EF8L,18446744073709551607UL}},{{0x8FBBB315L,0x9A9CB853L,0xE32BD85DL},{18446744073709551609UL,1UL,0x88608D2DL},{0x17A08BB5L,0x76BD683BL,0xC583338DL},{0x4F879874L,18446744073709551615UL,1UL},{0x325ED220L,0xB4891D5CL,0x506A2FBDL},{18446744073709551615UL,18446744073709551607UL,0x89039BF0L},{0x8876CA19L,0x41CDB462L,18446744073709551607UL},{0x791A1269L,1UL,0x68102DB9L}}};
        int32_t l_141 = (-6L);
        int32_t l_163 = 0L;
        uint16_t l_234 = 0x7218L;
        uint64_t l_252[9];
        int i, j, k;
        for (i = 0; i < 9; i++)
            l_252[i] = 0UL;
        l_141 = ((((safe_lshift_func_int8_t_s_u((l_113 = (safe_rshift_func_uint8_t_u_s((g_139 = ((safe_rshift_func_int16_t_s_s((l_113 , (p_63 || ((l_65 , (safe_lshift_func_int8_t_s_u((l_138 = ((l_137 = (p_63 & (safe_rshift_func_uint16_t_u_s(((l_113 , (((safe_lshift_func_uint8_t_u_u(((safe_mod_func_int16_t_s_s((0x71BCF00EL | ((safe_sub_func_uint64_t_u_u((safe_lshift_func_int8_t_s_s((l_135 = (safe_sub_func_uint32_t_u_u((((safe_rshift_func_int16_t_s_u((l_134[1][4][0] = (((safe_lshift_func_uint8_t_u_s((((0xABL ^ (l_105[7] = 0x09L)) , g_106) > l_113), 1)) == g_57) > g_106)), g_3)) & p_63) > 0xC5977F73L), 0xF6EF7C0EL))), p_63)), l_104[5])) > g_57)), l_136)) && g_57), p_63)) | 0xB7EED95DL) < 0x3CA94711L)) ^ (-1L)), 14)))) > 1L)), 5))) == g_57))), g_57)) || 0x85517B9ED38AF219LL)), l_140[3][3][1]))), 2)) <= 0x5F6FD868L) , l_135) ^ 1L);
lbl_313:
        g_164 = (g_57 == ((((safe_add_func_uint16_t_u_u((g_144 = l_113), (((l_163 = (safe_add_func_int64_t_s_s(((g_162[4][1][0] = (((safe_lshift_func_uint8_t_u_u(p_63, 5)) | (safe_sub_func_uint16_t_u_u((((((0x764AL | (g_4 , l_140[3][3][1])) <= ((safe_add_func_uint64_t_u_u((safe_lshift_func_uint16_t_u_s((((l_141 = (safe_sub_func_int16_t_s_s((g_161 = (0x05L == ((safe_sub_func_uint8_t_u_u(255UL, 0x98L)) > p_63))), 1L))) >= l_140[3][3][0]) ^ 0xFE48L), p_63)), p_63)) , p_63)) == 0x9534532C3757FDF3LL) , 8L) & 0xA08AL), g_106))) && l_141)) || 0xF0L), g_106))) > p_63) != g_4))) >= g_139) , p_63) && l_65));
        for (l_136 = 19; (l_136 <= 16); l_136 = safe_sub_func_uint8_t_u_u(l_136, 3))
        {
            uint8_t l_169[9][6] = {{2UL,255UL,0x0AL,2UL,0x0AL,255UL},{252UL,255UL,254UL,252UL,0x0AL,0x0AL},{0x05L,255UL,255UL,0x05L,0x0AL,254UL},{2UL,255UL,0x0AL,2UL,0x0AL,255UL},{252UL,255UL,254UL,252UL,0x0AL,0x0AL},{0x05L,255UL,255UL,0x05L,0x0AL,254UL},{2UL,255UL,0x0AL,2UL,0x0AL,255UL},{252UL,255UL,254UL,252UL,0x0AL,0x0AL},{0x05L,255UL,255UL,0x05L,0x0AL,254UL}};
            int32_t l_176 = 0x1FB21830L;
            int i, j;
            for (g_57 = 0; (g_57 <= 21); g_57++)
            {
                g_177 = (((((((g_170 = (l_169[8][2] = g_106)) == (((g_162[1][4][0] || 7L) , 9UL) < ((safe_mod_func_int64_t_s_s(((safe_add_func_uint64_t_u_u(p_63, l_141)) | ((((p_63 < ((((g_144 > (g_175[0][0] = (0xF82AL && 65527UL))) == p_63) && 1L) <= 4294967294UL)) < p_63) > 0xAC8DL) && l_176)), 0x9BDCCDAA94D8C579LL)) < 0xBDF61FF8L))) | p_63) && l_169[7][4]) , 0x8942CFE6L) == 0xC23F0BA9L) == p_63);
            }
            for (g_106 = (-10); (g_106 >= (-24)); g_106 = safe_sub_func_int8_t_s_s(g_106, 5))
            {
                uint8_t l_198 = 0UL;
                int32_t l_199 = 0x3A0AF4F7L;
                uint32_t l_223 = 0x6988B79AL;
                int32_t l_225 = 0x4C801F5DL;
                int16_t l_298[1];
                int i;
                for (i = 0; i < 1; i++)
                    l_298[i] = (-4L);
                for (g_164 = 1; (g_164 <= 5); g_164 += 1)
                {
                    int i;
                    l_105[(g_164 + 3)] = p_63;
                }
                g_180 = l_140[6][7][0];
                for (l_113 = 0; (l_113 <= (-23)); --l_113)
                {
                    const int16_t l_202 = 0L;
                    int32_t l_268 = 1L;
                    int32_t l_290 = (-1L);
                    l_199 = (safe_rshift_func_uint8_t_u_s(((((((safe_lshift_func_uint8_t_u_s(((safe_lshift_func_int16_t_s_s((1UL & ((safe_rshift_func_int8_t_s_s((l_104[3] | ((safe_lshift_func_uint16_t_u_u((safe_sub_func_int8_t_s_s(l_135, (~(-1L)))), 6)) ^ (safe_rshift_func_int16_t_s_s((l_141 == l_163), 2)))), l_141)) >= ((g_170 , ((((g_106 < l_136) || 0x9D36E7CB702D6E2BLL) && 0xF5L) | 1L)) == p_63))), l_176)) & g_106), g_170)) | p_63) >= g_177) > l_134[2][0][0]) & 3UL) || l_198), 1));
                    if (((safe_rshift_func_uint8_t_u_u(l_202, 7)) & (safe_add_func_int64_t_s_s((safe_sub_func_uint16_t_u_u(((0x3DD3832468EDAAE2LL < (((g_224 = (p_63 >= ((p_63 & ((safe_rshift_func_int16_t_s_u(((l_176 = (safe_mod_func_uint16_t_u_u((((safe_mod_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u(0xB7E3L, 11)), 0x93L)) <= (g_57 = ((safe_sub_func_uint32_t_u_u(g_162[4][1][0], ((safe_sub_func_uint8_t_u_u((l_65 == (safe_add_func_uint64_t_u_u((4294967293UL >= g_162[5][0][0]), p_63))), g_4)) < l_163))) || l_105[1]))), g_162[5][0][0])) == g_106) >= l_202), l_202))) , g_144), g_162[5][1][0])) , l_223)) & g_180))) , l_225) ^ l_169[2][3])) == 0xB602L), g_162[4][1][0])), p_63))))
                    {
                        int64_t l_233 = (-6L);
                        int32_t l_235 = 0x4C77BC79L;
                        int8_t l_269[6][2] = {{(-1L),0L},{0x9FL,(-1L)},{0x57L,0x57L},{0x57L,(-1L)},{0x9FL,0L},{(-1L),0L}};
                        int i, j;
                        l_163 = ((g_161 , p_63) , (0x7A97A70E4DF972C4LL < ((((+g_162[4][1][0]) | 0xB2L) || g_175[0][0]) >= (l_176 = (l_141 = (safe_rshift_func_uint8_t_u_u(((l_65 | (((safe_rshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((((p_63 , (l_233 = 0x335C8890L)) , (-1L)) >= l_234), g_170)), 8)) >= p_63) & 0x02L)) , g_162[4][1][0]), 5)))))));
                        l_235 = ((-1L) <= p_63);
                        g_253 = (((safe_add_func_int64_t_s_s(l_235, (safe_lshift_func_int8_t_s_u(((safe_sub_func_int16_t_s_s(l_233, ((safe_add_func_int16_t_s_s((((safe_rshift_func_int8_t_s_u(((safe_add_func_uint64_t_u_u((p_63 , (safe_add_func_int64_t_s_s(((g_75 = (p_63 ^ ((0x6E31L <= p_63) , p_63))) , (safe_lshift_func_uint8_t_u_u(g_57, ((((g_180 = (0x70AE17FB4F8F4AA5LL > l_252[6])) >= p_63) >= 255UL) | g_161)))), g_106))), 0L)) != (-3L)), 0)) , 65535UL) >= p_63), p_63)) != 0x13689FBD98F6770FLL))) ^ g_4), 0)))) | g_161) , l_233);
                        l_269[5][0] = ((p_63 || ((l_134[1][3][0] = ((safe_mod_func_int16_t_s_s(((safe_lshift_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint64_t_u_u((((65535UL < (l_268 = (safe_lshift_func_int16_t_s_u((((g_175[0][1] = (((l_202 || ((-6L) < 0UL)) && (l_105[7] = 0x1A13EBE0L)) == 0L)) > (g_139 <= (l_163 = (l_137 = ((0xAAF9CA1D855957BALL || g_164) <= (-1L)))))) || l_202), 9)))) && 1L) < p_63), l_202)) != (-3L)), g_253)), p_63)), g_162[4][1][0])) , l_198), l_140[3][3][1])) != g_164)) == g_144)) && 0xC9L);
                    }
                    else
                    {
                        int32_t l_289 = 0xE22492B1L;
                        int32_t l_291 = 0L;
                        if (p_63)
                            break;
                        l_291 = ((safe_add_func_uint64_t_u_u(((!(((safe_sub_func_uint8_t_u_u((safe_add_func_int16_t_s_s(((l_163 && ((safe_rshift_func_uint8_t_u_u(g_3, 3)) < ((g_4 , (g_162[4][1][0] = p_63)) != ((safe_sub_func_int8_t_s_s(((l_176 = (((g_281 = 0x275A1432ED5F9B65LL) <= (safe_add_func_uint16_t_u_u(g_284, g_144))) ^ ((safe_lshift_func_uint8_t_u_s(((g_161 , ((safe_lshift_func_int16_t_s_s(((p_63 > l_289) > p_63), p_63)) == l_223)) , 1UL), 4)) < 0xD0L))) >= g_57), 249UL)) & g_164)))) & 1L), l_202)), l_223)) , l_105[8]) & 65533UL)) && p_63), p_63)) , l_290);
                        l_199 = (g_3 , (0xF28B1D9B135E689BLL && ((l_223 <= g_144) && (g_4 | (7UL >= p_63)))));
                        g_312 = (((((-1L) || (safe_sub_func_int16_t_s_s((((0x0AA87E99L <= ((((safe_lshift_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_u((p_63 < (l_298[0] == (((safe_mod_func_int16_t_s_s(((p_63 >= ((g_301 = 0xE867DAB276F4076CLL) && 0x894F974B269E6272LL)) | (~(l_291 = (safe_sub_func_int16_t_s_s(((g_311 = (((((safe_lshift_func_int8_t_s_u(g_162[0][4][0], 3)) , (((safe_add_func_uint8_t_u_u((l_290 = (safe_mod_func_uint32_t_u_u(((4294967295UL == p_63) <= 0x569836B154859BE3LL), l_291))), 0UL)) != g_180) >= 0x3A5831BFL)) || p_63) <= p_63) | l_169[8][5])) , p_63), 7L))))), 1L)) || l_141) , p_63))), g_180)) != l_134[1][3][0]), l_198)) >= p_63) >= l_298[0]) >= (-5L))) == p_63) | 0xEA3A68A8199A5E12LL), 0x75D8L))) >= p_63) < p_63) <= 0xE9E3D709L);
                    }
                }
            }
            if (g_57)
                goto lbl_313;
        }
    }
    else
    {
        int32_t l_322 = 0x37CFC890L;
        int8_t l_331 = 1L;
        uint32_t l_358[6][1] = {{0xDCEEF8EBL},{18446744073709551615UL},{0xDCEEF8EBL},{0xDCEEF8EBL},{18446744073709551615UL},{0xDCEEF8EBL}};
        uint32_t l_365 = 0UL;
        uint32_t l_424 = 3UL;
        int i, j;
        l_137 = (((l_322 = ((((((safe_sub_func_int32_t_s_s((0x0301DC19L >= p_63), g_75)) != l_137) & (safe_mod_func_int32_t_s_s(((safe_rshift_func_int16_t_s_u(((g_144 = (((((safe_sub_func_uint64_t_u_u((l_134[1][4][0] = 0xFF04DD1FA9EB540BLL), ((((p_63 , ((l_105[7] = 1L) <= 0xE0L)) || ((18446744073709551615UL < l_136) , l_322)) >= 0x19F9L) , g_281))) | g_175[0][0]) | g_224) && p_63) , g_175[0][0])) ^ 0xB669E5A8L), l_104[5])) , g_311), 0xBC388CCCL))) <= 0x02L) | g_177) & 0xD37BL)) , p_63) >= (-1L));
lbl_382:
        l_137 = (safe_rshift_func_int16_t_s_u((0x790AEB77L || (l_322 = (g_332 = (3UL >= (g_301 = (((safe_add_func_uint64_t_u_u((((0x8DC8AE235981C336LL && (((l_134[1][4][0] = l_322) , (((((g_329[1] = ((+l_328) <= p_63)) & (g_106 = (g_164 == ((l_134[1][4][0] = ((g_4 & l_322) & l_105[1])) > 0L)))) != g_75) ^ 0x42703DA147851FA4LL) , l_330)) == l_331)) == 0x0982CF0FL) && p_63), p_63)) || 0xF7L) , 0x0750AB3EE35A2FDCLL)))))), p_63));
        for (g_253 = (-10); (g_253 != 17); g_253 = safe_add_func_int64_t_s_s(g_253, 3))
        {
            uint16_t l_357 = 0x4A9FL;
            int32_t l_362 = 1L;
            int64_t l_363[1][1][4] = {{{0x3CABBDACC74AFD26LL,0x3CABBDACC74AFD26LL,0x3CABBDACC74AFD26LL,0x3CABBDACC74AFD26LL}}};
            int32_t l_443 = 0x64A9273BL;
            int32_t l_488 = 0xE450C33DL;
            int i, j, k;
            for (g_224 = 0; (g_224 <= 21); ++g_224)
            {
                uint8_t l_349 = 4UL;
                int32_t l_394 = 0x89B81FC5L;
                int32_t l_396 = 0xC3D7A1A4L;
                uint16_t l_442 = 0x855FL;
                for (l_330 = (-11); (l_330 == 21); l_330 = safe_add_func_int32_t_s_s(l_330, 4))
                {
                    uint32_t l_364 = 0x3002C48CL;
                    if (g_281)
                        break;
                    if (((p_63 >= (safe_add_func_int32_t_s_s(p_63, (((safe_add_func_int32_t_s_s(((safe_rshift_func_uint16_t_u_s((((((((safe_rshift_func_int16_t_s_s(((safe_mod_func_uint64_t_u_u(l_322, ((l_349 = l_331) , (((p_63 == (g_312 = (safe_add_func_int8_t_s_s((((!((((((safe_add_func_int8_t_s_s((g_281 = (l_358[4][0] = (0xF78F5D8F846B0A71LL >= (safe_add_func_uint8_t_u_u(g_175[0][0], l_357))))), (l_362 = (safe_mod_func_int32_t_s_s((g_361 = p_63), 0xAF87F9D4L))))) ^ l_363[0][0][1]) ^ g_57) , g_311) || g_312) && g_301)) , 0UL) , l_364), 255UL)))) & l_365) , l_330)))) , p_63), l_363[0][0][1])) , l_365) >= p_63) & 0x3357L) && l_364) > 0x7FL) && g_162[4][1][0]), 2)) >= l_105[7]), g_162[3][0][0])) , (-1L)) , g_162[4][1][0])))) , 0L))
                    {
                        int16_t l_366 = 6L;
                        if (l_366)
                            break;
                        g_381 = (safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((((l_349 <= p_63) , 0x4F94L) && ((safe_mod_func_uint64_t_u_u(1UL, p_63)) < p_63)), ((((safe_sub_func_uint32_t_u_u(0xD7494F00L, ((safe_lshift_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s(((7UL && (l_322 || (-10L))) != g_4), 6)), 2)) > l_366))) <= p_63) & p_63) <= l_365))), 7)), l_364));
                        if (p_63)
                            continue;
                    }
                    else
                    {
                        if (l_331)
                            goto lbl_382;
                    }
                    for (l_364 = 0; (l_364 <= 0); l_364 += 1)
                    {
                        int32_t l_395 = (-3L);
                        int i, j, k;
                        l_396 = (l_105[2] = (l_363[l_364][l_364][(l_364 + 2)] > (((safe_lshift_func_uint16_t_u_s((~(safe_add_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((g_161 = (l_363[l_364][l_364][(l_364 + 1)] >= 0x9DC002C6D1CEE5DELL)), 10)), (g_162[l_364][(l_364 + 4)][l_364] , (safe_rshift_func_uint8_t_u_u(((g_106 = ((246UL < (safe_sub_func_int64_t_s_s(((l_394 = p_63) ^ ((g_175[0][0] = l_331) < 65535UL)), (g_162[(l_364 + 4)][l_364][l_364] = (((l_395 = ((((p_63 ^ g_332) > g_170) ^ l_349) , g_177)) , 0L) || p_63))))) | g_329[1])) && 0x86L), l_349)))))), 9)) > 1L) , (-1L))));
                    }
                    if (l_362)
                        break;
                }
                if (((!(l_322 = p_63)) , ((l_105[7] = (((((((l_322 = ((((((safe_sub_func_int32_t_s_s((l_394 = (safe_mod_func_int8_t_s_s((p_63 || ((((p_63 > ((((safe_rshift_func_uint8_t_u_u(p_63, 5)) && ((safe_rshift_func_int16_t_s_s((safe_sub_func_uint64_t_u_u(((safe_rshift_func_uint16_t_u_s(((safe_mod_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_s((0x605D1BA7199D1877LL > (l_396 , ((safe_add_func_int8_t_s_s(0x97L, (safe_add_func_uint32_t_u_u(g_161, (((safe_add_func_int8_t_s_s(((l_424 = (((safe_mod_func_int8_t_s_s(l_394, 0xE0L)) >= 0x4FDCL) || 0x5D91D15DDF07EBC8LL)) | l_104[5]), 0xF6L)) || (-1L)) ^ g_170))))) > p_63))), g_162[3][4][0])), g_329[1])), l_357)) & l_362), g_57)) && p_63), 0x13F8848AD8FBCBA9LL)), 0)) >= g_224)) , p_63) == 1L)) >= l_396) & 7UL) , l_358[4][0])), p_63))), g_311)) ^ g_311) ^ p_63) == p_63) && g_162[5][1][0]) > p_63)) || p_63) && p_63) , 0x06L) > g_177) & p_63) ^ g_162[4][1][0])) , (-1L))))
                {
                    uint32_t l_427 = 0UL;
                    l_443 = ((l_362 = ((((g_164 & (safe_rshift_func_uint16_t_u_s(l_427, 1))) ^ ((g_162[4][1][0] = (safe_add_func_uint32_t_u_u((((((l_322 = ((safe_mod_func_int8_t_s_s((safe_mod_func_uint64_t_u_u(((safe_lshift_func_uint16_t_u_s(((65526UL | l_362) >= (((((l_394 = ((+g_57) & ((0UL == (safe_mod_func_int64_t_s_s((safe_mod_func_uint64_t_u_u(((((l_441[0][7] = p_63) == (255UL <= (0UL || 0x4956B785C5EC6427LL))) == 0xD46AF7CBD1DEC3E6LL) , g_332), l_365)), g_180))) & 1L))) | 0xB7B30645L) < l_137) < 0x77L) , g_281)), 7)) ^ (-8L)), g_4)), l_358[4][0])) <= g_139)) > l_105[4]) == l_442) , p_63) && 0x475C6609L), 0x4B2862F6L))) > (-2L))) && l_331) , g_281)) == g_139);
                    if (g_177)
                    {
                        int8_t l_460 = (-1L);
                        l_460 = ((((p_63 > 0L) , 0x9CL) ^ ((+((p_63 && (((((0x8C40E1DFD85E0CFCLL || ((4UL != (g_459 = ((safe_add_func_uint64_t_u_u((g_301 = (safe_add_func_uint8_t_u_u((g_106 == (((safe_sub_func_int16_t_s_s((safe_mod_func_uint64_t_u_u((safe_add_func_int32_t_s_s((l_331 == ((safe_lshift_func_int16_t_s_u(g_329[1], g_281)) == p_63)), g_161)), g_170)), p_63)) == 0L) != p_63)), 0UL))), l_358[4][0])) > 4L))) , l_331)) > l_427) == 0x4DL) ^ p_63) ^ l_358[4][0])) & l_349)) , g_162[4][1][0])) > g_332);
                    }
                    else
                    {
                        int16_t l_461 = 6L;
                        if (l_442)
                            break;
                        g_462 = l_461;
                    }
                    g_381 = g_301;
                }
                else
                {
                    int8_t l_481 = 0x3BL;
                    for (l_443 = 0; (l_443 <= 0); l_443 += 1)
                    {
                        int i, j;
                        l_137 = ((((0x430609F07F1982D9LL || 0xAA602BFDE3D342A5LL) >= l_358[(l_443 + 1)][l_443]) <= ((safe_sub_func_int64_t_s_s(((l_358[(l_443 + 5)][l_443] | (0xBF298BF1E59B3B48LL & (safe_unary_minus_func_int16_t_s(0L)))) , (((l_358[(l_443 + 2)][l_443] && (safe_sub_func_int8_t_s_s(g_161, (+(safe_mod_func_int8_t_s_s((safe_mod_func_int32_t_s_s(l_105[7], l_424)), g_381)))))) && l_134[1][4][0]) , p_63)), p_63)) && p_63)) , 0x72F09818L);
                        return g_329[1];
                    }
                    if (g_312)
                        continue;
                    l_488 = (safe_lshift_func_uint16_t_u_s((((g_139 , ((safe_sub_func_int16_t_s_s((+l_357), ((safe_add_func_uint32_t_u_u(((l_481 = (safe_unary_minus_func_uint8_t_u(p_63))) ^ (l_443 = (g_462 = (p_63 <= ((safe_lshift_func_int8_t_s_s((0x09L < (safe_unary_minus_func_uint16_t_u(((((l_134[1][4][0] = 0xEFL) | (((safe_mod_func_int32_t_s_s(p_63, 0xC7FFF42AL)) == (g_75 = (~0UL))) , l_65)) || 0x7659C53DL) & p_63)))), 7)) < l_365))))), p_63)) && g_301))) <= g_170)) && 0xFE4E48045BAF679CLL) != g_144), 7));
                    l_394 = g_170;
                }
                for (g_459 = 22; (g_459 == (-24)); g_459--)
                {
                    uint16_t l_491[1][4] = {{0x76ABL,0x76ABL,0x76ABL,0x76ABL}};
                    uint64_t l_507 = 0x80D91EA27728EC3CLL;
                    int32_t l_509 = 0x0FF98841L;
                    int i, j;
                    if (l_491[0][0])
                    {
                        return l_491[0][0];
                    }
                    else
                    {
                        uint32_t l_497 = 4294967291UL;
                        l_509 = ((p_63 || (safe_add_func_uint32_t_u_u(((l_105[7] && (safe_lshift_func_uint16_t_u_s(((!0xB1D5EC492C4B8B75LL) || (((l_497 != (safe_unary_minus_func_int16_t_s((safe_lshift_func_int16_t_s_u(p_63, (safe_rshift_func_uint16_t_u_u(((((g_106 = ((l_322 = l_365) >= ((((safe_rshift_func_int16_t_s_u(g_144, (safe_sub_func_uint32_t_u_u((0xF70DL < ((((((2UL != l_491[0][0]) >= 0xCDE1FB7BL) != 0UL) == 0x5192L) , l_424) , (-6L))), 1L)))) >= g_106) >= (-10L)) || g_162[1][3][0]))) >= p_63) ^ 0xD51D8DA9810C119ALL) >= l_507), l_508))))))) , g_329[1]) , 0x69651BAFL)), g_329[1]))) ^ p_63), p_63))) | 1UL);
                        g_381 = 0x90AA2A39L;
                    }
                    for (p_63 = 0; (p_63 != 23); p_63 = safe_add_func_uint32_t_u_u(p_63, 8))
                    {
                        return p_63;
                    }
                    g_381 = (safe_mod_func_uint16_t_u_u(((safe_mod_func_uint64_t_u_u((((l_442 == (((((-3L) || (((0x92L >= (((p_63 & ((((safe_rshift_func_int8_t_s_u((0xCCL & (g_462 = (((((-4L) ^ g_175[0][0]) , ((((safe_lshift_func_uint16_t_u_u((0UL || (g_162[0][3][0] = (((safe_sub_func_int64_t_s_s(((safe_rshift_func_int8_t_s_u(p_63, 4)) , p_63), g_175[0][2])) , l_65) != l_134[1][4][0]))), 6)) , l_491[0][0]) && g_3) == 0xC6F72A4374E7C4F2LL)) <= g_284) & 0x1FL))), 5)) <= 0x0570B0E097595410LL) >= 0x3B91FB55890E678FLL) ^ g_329[3])) > g_4) <= p_63)) ^ 0x04L) || p_63)) & p_63) != p_63) >= l_442)) || g_253) > 248UL), g_106)) & 0x462EL), g_284));
                }
            }
            l_134[1][4][0] = l_105[7];
            l_105[7] = ((((safe_lshift_func_int8_t_s_s((((p_63 , (((l_134[1][4][0] = ((g_329[3] < (g_281 = ((g_175[0][0] = 0xE46FL) > (safe_unary_minus_func_int64_t_s(l_331))))) | ((g_552 = (safe_mod_func_int16_t_s_s(((((safe_mod_func_int8_t_s_s((g_57 & (safe_add_func_uint64_t_u_u(g_301, (safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u(g_332, ((safe_mod_func_uint64_t_u_u(((((safe_mod_func_uint64_t_u_u(((safe_add_func_int64_t_s_s((safe_add_func_int8_t_s_s(((((safe_unary_minus_func_int16_t_s((safe_add_func_uint16_t_u_u((safe_add_func_int64_t_s_s((safe_sub_func_int8_t_s_s((-8L), g_332)), 0xD6F4CE22D36DB7B0LL)), g_139)))) != g_144) && 0xFDL) , p_63), p_63)), p_63)) < 0xEAL), (-1L))) == 0L) | l_322) < 0x58D39A2DL), 0x2D29A1CD21FC2287LL)) >= p_63))), l_363[0][0][2]))))), p_63)) | 0UL) || g_301) ^ p_63), g_57))) > 0xE00AL))) , 0x21A81BEDL) & l_136)) != g_253) != 0UL), g_106)) || l_441[0][7]) | 0x98FB6D77FFB56C65LL) || g_162[2][2][0]);
            g_381 = (g_552 && ((p_63 < 3L) <= 0x6E9BL));
        }
    }
    for (l_508 = 0; (l_508 <= 3); l_508 += 1)
    {
        int16_t l_553 = 9L;
        int32_t l_573[6][7][6] = {{{3L,0xEDD76851L,0x1A136FD8L,(-1L),(-3L),0L},{0x6188BC2BL,(-1L),0x9CE4A374L,0x3671F6E4L,(-1L),0x0B0570FEL},{1L,0x0B0570FEL,0xCE321BFDL,(-1L),1L,1L},{0x87136DF8L,(-1L),0xA2ACCE90L,0xDC9B95A0L,0xDB8AA1DEL,(-1L)},{1L,(-10L),0x056439E3L,1L,0x6188BC2BL,0xB5E5629AL},{0x056439E3L,0x87136DF8L,5L,(-1L),1L,3L},{0x550EAA4AL,(-3L),1L,6L,1L,(-1L)}},{{(-7L),0x0ED305E4L,3L,0xE4DB74A8L,0xE4DB74A8L,3L},{0L,0L,0xCA879651L,0x65C0062CL,(-1L),(-1L)},{0xCE321BFDL,0x53E24415L,0xDC9B95A0L,1L,(-1L),0xCA879651L},{0x4B0117D4L,0xCE321BFDL,0xDC9B95A0L,(-1L),0L,(-1L)},{0x2392891BL,(-1L),0xCA879651L,(-3L),1L,3L},{(-3L),1L,3L,0x4B0117D4L,0L,0xCA879651L},{0x53E24415L,(-1L),(-1L),0x5C2A6F27L,(-10L),(-1L)}},{{(-10L),0x1A136FD8L,(-1L),0x550EAA4AL,0L,3L},{0xDC9B95A0L,1L,(-9L),0xCE321BFDL,0L,0x87136DF8L},{(-3L),0xE4DB74A8L,1L,6L,(-1L),0xA2ACCE90L},{3L,0xEDD76851L,(-1L),(-6L),0x5C2A6F27L,0L},{0x69759C29L,0L,0x0ED305E4L,2L,0L,(-1L)},{1L,0x145D9A16L,0x2392891BL,5L,(-8L),5L},{(-9L),0x53E24415L,(-9L),0xAC49D6E1L,(-3L),0x41BEB88BL}},{{2L,0x3671F6E4L,(-8L),0xE4DB74A8L,1L,0x63D64212L},{(-8L),(-7L),(-1L),0xE4DB74A8L,0L,0xAC49D6E1L},{2L,0x056439E3L,0xB5E5629AL,0xAC49D6E1L,0x550EAA4AL,1L},{(-9L),(-1L),0xBECEBECDL,5L,(-8L),0x9CE4A374L},{1L,0x0ED305E4L,1L,2L,0x53E24415L,0x056439E3L},{0x69759C29L,0L,6L,(-6L),0xAC49D6E1L,0x0ED305E4L},{3L,0x4B0117D4L,0x3671F6E4L,6L,0xCA879651L,2L}},{{(-3L),3L,0x41BEB88BL,0xCE321BFDL,0x0ED305E4L,0L},{0xDC9B95A0L,0L,3L,0x550EAA4AL,(-7L),(-9L)},{(-10L),(-7L),0L,0x5C2A6F27L,(-3L),(-3L)},{0x53E24415L,0x63D64212L,(-10L),0x4B0117D4L,(-7L),(-7L)},{1L,0x65C0062CL,0x65C0062CL,1L,(-1L),(-1L)},{0x9CE4A374L,0xCE321BFDL,0x53E24415L,0xDC9B95A0L,1L,(-1L)},{(-7L),0xBECEBECDL,0L,(-8L),1L,(-6L)}},{{(-1L),0xCE321BFDL,0L,(-8L),(-1L),1L},{(-1L),0x65C0062CL,0x6188BC2BL,0x3671F6E4L,(-7L),1L},{0x056439E3L,0x63D64212L,0x1A136FD8L,(-1L),(-3L),(-1L)},{0x145D9A16L,(-7L),0xDC9B95A0L,7L,(-7L),0x4B0117D4L},{(-9L),0L,(-1L),(-9L),0x0ED305E4L,0x1A136FD8L},{0xCE321BFDL,3L,(-3L),0x63D64212L,0xCA879651L,0x3671F6E4L},{5L,0x4B0117D4L,(-6L),0x87136DF8L,0xAC49D6E1L,1L}}};
        int8_t l_776 = 0xCDL;
        int32_t l_847 = 0x633CDEFBL;
        int32_t l_848 = 2L;
        uint16_t l_873 = 0x7F97L;
        uint32_t l_934 = 0x99CCB23BL;
        int8_t l_968 = 0x92L;
        uint8_t l_992 = 0x4BL;
        uint8_t l_1000 = 0UL;
        int i, j, k;
        for (g_164 = 0; (g_164 <= 3); g_164 += 1)
        {
            uint8_t l_574 = 0x0BL;
            l_553 = 0x2DDBA6DFL;
            for (g_139 = 0; (g_139 <= 3); g_139 += 1)
            {
                uint32_t l_554 = 4294967295UL;
                for (p_63 = 0; (p_63 <= 3); p_63 += 1)
                {
                    int i;
                    l_137 = (l_554 = g_329[p_63]);
                    g_381 = (-10L);
                }
            }
            l_137 = (safe_add_func_uint32_t_u_u((safe_unary_minus_func_int8_t_s((safe_add_func_uint16_t_u_u(g_139, (safe_mod_func_int32_t_s_s((g_253 && ((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u((p_63 >= (p_63 < (safe_mod_func_uint64_t_u_u(((g_162[4][1][0] & (+((safe_unary_minus_func_int16_t_s(1L)) || p_63))) != (!(l_573[5][3][5] = (p_63 | (p_63 ^ 0x217CL))))), g_144)))), 4)) | 0xB0B1L), 0x869AL)) , l_574)), 0xD093F91BL)))))), p_63));
        }
        if ((((((p_63 , p_63) != (l_573[5][3][5] = (safe_lshift_func_uint8_t_u_u(((l_508 ^ ((g_106 | (p_63 , p_63)) , ((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u((-5L), p_63)), p_63)) > l_573[4][5][4]))) != l_330), 6)))) ^ 65528UL) && p_63) > g_281))
        {
            int64_t l_596 = 0xAB5164C391C15D86LL;
            int32_t l_599 = 0x131351A4L;
            uint16_t l_720[7] = {65532UL,65532UL,65532UL,65532UL,65532UL,65532UL,65532UL};
            uint32_t l_757 = 0x9F6A5B6EL;
            int32_t l_808[4];
            uint64_t l_894 = 0xDAC97AF0D1317217LL;
            int32_t l_993 = (-6L);
            int32_t l_1017 = 0x2E78BC95L;
            int i;
        }
        else
        {
            l_105[6] = (g_923 = (0UL >= 0x0E39L));
        }
        if (l_105[9])
            break;
    }
    for (g_977 = (-27); (g_977 <= 4); ++g_977)
    {
        return p_63;
    }
    return p_63;
}





static int16_t func_71(int32_t p_72, int64_t p_73)
{
    const int64_t l_74 = 0x696D9C50E9BCC685LL;
    int32_t l_91 = (-1L);
    int32_t l_92[7];
    int32_t l_99 = 0x65B8C0B7L;
    uint32_t l_100 = 4294967295UL;
    int32_t l_101[8] = {0x54EB9293L,0x86057917L,0x54EB9293L,0x54EB9293L,0x86057917L,0x54EB9293L,0x54EB9293L,0x86057917L};
    int i;
    for (i = 0; i < 7; i++)
        l_92[i] = 0x8AD0AF09L;
    l_92[5] = (((l_74 || (g_75 = l_74)) >= ((safe_lshift_func_uint8_t_u_s((p_73 | (safe_lshift_func_int16_t_s_u(l_74, (p_73 >= (safe_unary_minus_func_uint64_t_u(((safe_lshift_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(g_3, (safe_lshift_func_int8_t_s_u((((0x49L != ((l_91 = (safe_mod_func_uint64_t_u_u((0x9E8DF01DL || (safe_add_func_uint64_t_u_u((g_57 > l_74), p_73))), g_3))) <= l_74)) | g_57) & g_4), 7)))), p_73)) | g_3))))))), g_4)) != p_72)) <= 0xC3860FE7L);
    l_101[3] = (((g_3 & (safe_add_func_int16_t_s_s((safe_add_func_uint8_t_u_u(p_73, (l_91 = ((g_75 = (l_92[1] = p_73)) , (l_92[5] ^ 1UL))))), ((((safe_add_func_int8_t_s_s((((p_72 | (0x6AL >= (l_99 = (g_3 , g_3)))) , l_74) , l_99), 3UL)) < l_100) > 0x5931L) & 6L)))) , g_3) | g_4);
    for (l_91 = 14; (l_91 < 6); l_91--)
    {
        return p_72;
    }
    return l_101[5];
}

int main (int argc, char* argv[])
{
    int i, j, k;
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
    transparent_crc(g_3, "g_3", print_hash_value);
    transparent_crc(g_4, "g_4", print_hash_value);
    transparent_crc(g_57, "g_57", print_hash_value);
    transparent_crc(g_75, "g_75", print_hash_value);
    transparent_crc(g_106, "g_106", print_hash_value);
    transparent_crc(g_139, "g_139", print_hash_value);
    transparent_crc(g_144, "g_144", print_hash_value);
    transparent_crc(g_161, "g_161", print_hash_value);
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 5; j++)
        {
            for (k = 0; k < 1; k++)
            {
                transparent_crc(g_162[i][j][k], "g_162[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    transparent_crc(g_164, "g_164", print_hash_value);
    transparent_crc(g_170, "g_170", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transparent_crc(g_175[i][j], "g_175[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    transparent_crc(g_177, "g_177", print_hash_value);
    transparent_crc(g_180, "g_180", print_hash_value);
    transparent_crc(g_224, "g_224", print_hash_value);
    transparent_crc(g_253, "g_253", print_hash_value);
    transparent_crc(g_281, "g_281", print_hash_value);
    transparent_crc(g_284, "g_284", print_hash_value);
    transparent_crc(g_301, "g_301", print_hash_value);
    transparent_crc(g_311, "g_311", print_hash_value);
    transparent_crc(g_312, "g_312", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        transparent_crc(g_329[i], "g_329[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_332, "g_332", print_hash_value);
    transparent_crc(g_361, "g_361", print_hash_value);
    transparent_crc(g_381, "g_381", print_hash_value);
    transparent_crc(g_459, "g_459", print_hash_value);
    transparent_crc(g_462, "g_462", print_hash_value);
    transparent_crc(g_552, "g_552", print_hash_value);
    transparent_crc(g_777, "g_777", print_hash_value);
    transparent_crc(g_810, "g_810", print_hash_value);
    transparent_crc(g_836, "g_836", print_hash_value);
    transparent_crc(g_877, "g_877", print_hash_value);
    transparent_crc(g_923, "g_923", print_hash_value);
    transparent_crc(g_977, "g_977", print_hash_value);
    transparent_crc(g_991, "g_991", print_hash_value);
    transparent_crc(g_1039, "g_1039", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_1118[i], "g_1118[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_1147, "g_1147", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_1284[i], "g_1284[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transparent_crc(g_1293[i][j], "g_1293[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    transparent_crc(g_1434, "g_1434", print_hash_value);
    transparent_crc(g_1501, "g_1501", print_hash_value);
    transparent_crc(g_1589, "g_1589", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        transparent_crc(g_1701[i], "g_1701[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    for (i = 0; i < 6; i++)
    {
        transparent_crc(g_1717[i], "g_1717[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    for (i = 0; i < 4; i++)
    {
        transparent_crc(g_1735[i], "g_1735[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_1756, "g_1756", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 10; j++)
        {
            transparent_crc(g_2063[i][j], "g_2063[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    transparent_crc(g_2158, "g_2158", print_hash_value);
    transparent_crc(g_2188, "g_2188", print_hash_value);
    transparent_crc(g_2228, "g_2228", print_hash_value);
    transparent_crc(g_2236, "g_2236", print_hash_value);
    transparent_crc(g_2247, "g_2247", print_hash_value);
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 3; k++)
            {
                transparent_crc(g_2424[i][j][k], "g_2424[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    transparent_crc(g_2426, "g_2426", print_hash_value);
    transparent_crc(g_2427, "g_2427", print_hash_value);
    transparent_crc(g_2452, "g_2452", print_hash_value);
    transparent_crc(g_2465, "g_2465", print_hash_value);
    transparent_crc(g_2764, "g_2764", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        transparent_crc(g_2806[i], "g_2806[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_2811, "g_2811", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

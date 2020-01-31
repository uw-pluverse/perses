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
   volatile uint8_t f0;
   volatile uint32_t f1;
   const volatile int16_t f2;
   volatile uint32_t f3;
   int16_t f4;
   volatile uint64_t f5;
};

struct S1 {
   signed f0 : 5;
   signed f1 : 8;
   uint32_t f2;
   volatile uint16_t f3;
};


static int8_t g_16 = 0x61L;
static int32_t g_25 = 0x6EAB3CF8L;
static struct S0 g_59 = {1UL,0xED469F41L,0xF53CL,0xCBF698BAL,-1L,0x49E864ADB5D2300BLL};
static volatile int64_t g_60 = 0xE07F0936A74B4FBFLL;
static int32_t g_62 = 3L;
static volatile struct S1 g_80 = {-4,-4,0x4F663622L,0xFA2EL};
static volatile int32_t ** volatile g_108 = (void*)0;
static volatile int32_t ** volatile * const g_107 = &g_108;
static int32_t *g_116 = &g_62;
static struct S1 g_125 = {1,-5,0x24141E32L,1UL};
static volatile struct S0 g_126 = {0x0BL,0UL,0x77E3L,18446744073709551615UL,0x04C8L,5UL};
static int32_t *** volatile g_129 = (void*)0;
static int32_t **g_132 = &g_116;
static int32_t *** volatile g_131 = &g_132;
static uint8_t g_266 = 0xCCL;
static volatile struct S1 g_313 = {-4,-14,0xBCE0E0F3L,0x7A9BL};
static int64_t g_566 = (-9L);
static volatile uint16_t g_570 = 0UL;
static uint8_t g_687 = 250UL;
static volatile uint8_t g_692 = 0x82L;
static volatile struct S0 g_753 = {1UL,18446744073709551606UL,-1L,7UL,0x7256L,18446744073709551611UL};
static volatile struct S0 g_763 = {1UL,0xDC33B451L,-8L,0x53A7278CL,3L,18446744073709551615UL};
static volatile struct S0 g_792 = {255UL,0x045F4A48L,-1L,1UL,-1L,0x064B141677A4AC4CLL};
static volatile struct S1 g_793 = {3,15,0x139AF61BL,65526UL};
static volatile struct S1 g_794 = {-3,6,0x7005EE34L,0xC9B9L};
static struct S0 g_803 = {0x55L,18446744073709551615UL,0xA09CL,0xCFB1D8EFL,-4L,0xBD35DC7E0B9DB818LL};
static struct S0 g_804 = {246UL,0xAA6AA057L,-6L,0xA3680CAEL,1L,1UL};
static const struct S1 g_818 = {-4,-10,0UL,0x2C76L};
static volatile struct S1 g_847 = {-3,9,18446744073709551614UL,0x1B89L};
static struct S1 g_1163 = {-0,-13,0xBAE1CE67L,4UL};
static const struct S1 *g_1174 = (void*)0;
static const struct S1 g_1202 = {-2,-4,0x4B14E178L,0x6718L};
static uint32_t g_1416 = 0x7AEC422EL;
static struct S0 g_1441 = {0xC3L,0UL,0x3F39L,3UL,8L,0xDF5CA00CAC530F6ELL};
static volatile int32_t g_1478 = 0x647E141EL;
static struct S0 g_1530 = {0xDFL,0x6ABBDA1EL,0L,0x0F4ED0ADL,0L,0x194CD6B76CC454E7LL};
static struct S0 *g_1529 = &g_1530;
static struct S1 g_1594 = {1,-15,1UL,65529UL};
static volatile struct S1 *g_1596 = &g_847;
static volatile struct S1 ** volatile g_1595 = &g_1596;
static const struct S0 g_1639 = {253UL,0UL,0x8B90L,0UL,0xF2BCL,18446744073709551608UL};
static int32_t g_1648 = 0xE1A00619L;
static uint8_t g_2015 = 0UL;
static volatile struct S1 g_2191 = {-3,-0,0xFF05B2F0L,65531UL};
static volatile struct S1 ** volatile g_2210 = &g_1596;
static struct S1 g_2213 = {0,-0,0xE975E4D3L,0xDE00L};
static int32_t g_2243 = 0x41CCDE37L;
static int32_t * volatile g_2280 = (void*)0;
static uint32_t g_2309 = 0x78979873L;
static struct S0 g_2321 = {255UL,18446744073709551613UL,0xEB97L,9UL,0xDA48L,0xE34739B25885D871LL};
static const struct S1 g_2325 = {3,-13,0x0D605087L,65528UL};
static struct S1 g_2326 = {4,11,0xF27C41D8L,0xE835L};
static const struct S0 g_2347 = {0UL,0xFC64B101L,9L,18446744073709551615UL,0x2928L,18446744073709551607UL};
static int32_t ** volatile g_2678 = &g_116;
static const struct S1 g_2792 = {-0,11,0xAF3DB8F7L,0x8427L};
static int32_t g_2951 = 0x91FA2AD1L;
static volatile struct S1 g_2952 = {0,-7,0UL,0xC54DL};
static int32_t ** volatile g_2976 = &g_116;
static int32_t ** const volatile g_3092 = &g_116;
static int32_t ** volatile g_3383 = &g_116;
static volatile uint32_t g_3732 = 1UL;
static const struct S0 g_3771 = {0xE7L,0xBD7EB7F6L,0x3AA0L,18446744073709551613UL,0x7CECL,0xC87C56E30E774214LL};
static int32_t ** volatile g_3800 = &g_116;
static uint32_t g_4114 = 0xF64A08C1L;
static struct S0 g_4141 = {0x42L,18446744073709551611UL,-8L,0x11136A37L,-8L,0x82D87D8D374F33A5LL};
static int32_t ** volatile g_4148 = (void*)0;
static const volatile struct S1 g_4181 = {0,-7,1UL,1UL};
static const struct S0 *g_4217 = &g_2321;
static const struct S0 ** volatile g_4216 = &g_4217;
static volatile uint16_t g_4582 = 65532UL;
static struct S1 g_4585 = {1,-3,0x62F0FF62L,0xC4A2L};



static struct S1 func_1(void);
static int32_t func_2(const int8_t p_3, int8_t p_4, const uint16_t p_5, uint16_t p_6, int64_t p_7);
static int16_t func_10(uint32_t p_11, int32_t p_12, uint8_t p_13, int16_t p_14);
static uint16_t func_19(int32_t p_20);
static uint64_t func_26(int64_t p_27, int32_t * p_28, const int32_t * const p_29);
static int32_t * func_30(uint32_t p_31, int32_t * p_32);
static int16_t func_35(const uint32_t p_36);
static const uint8_t func_43(uint64_t p_44, uint32_t p_45, int32_t * p_46);
static uint64_t func_47(int32_t * p_48);
static int32_t * func_49(uint8_t p_50, int32_t * p_51, int8_t p_52, int32_t * p_53);
static struct S1 func_1(void)
{
    uint32_t l_15 = 1UL;
    int32_t l_4167 = 0xBBB51A81L;
    int32_t *l_4218 = &g_25;
    int32_t *l_4219 = (void*)0;
    int32_t *l_4220 = &g_2951;
    int32_t *l_4221 = &g_62;
    int32_t *l_4222 = &g_2951;
    int32_t *l_4223 = &g_2951;
    int32_t *l_4224 = (void*)0;
    int32_t *l_4225 = (void*)0;
    int32_t *l_4226 = (void*)0;
    int32_t *l_4227 = &g_2243;
    int32_t *l_4228 = &g_2951;
    int32_t *l_4229 = &g_25;
    int32_t *l_4230 = &g_2243;
    int32_t *l_4231 = &g_25;
    int32_t *l_4232 = &g_2951;
    int32_t *l_4233 = &g_2951;
    int32_t *l_4234 = (void*)0;
    int32_t *l_4235 = (void*)0;
    int32_t *l_4236 = &g_25;
    int32_t *l_4237 = &g_2243;
    int32_t *l_4238 = (void*)0;
    int32_t *l_4239 = &g_25;
    int32_t *l_4240 = &g_25;
    int32_t *l_4241 = &g_2951;
    int32_t *l_4242 = &g_2951;
    int32_t *l_4243 = &g_25;
    int32_t *l_4244 = &g_25;
    int32_t *l_4245 = &g_25;
    int32_t *l_4246 = &g_2951;
    int32_t *l_4247 = &g_62;
    int32_t *l_4248 = &g_2243;
    int32_t *l_4249 = &g_2243;
    int32_t l_4250 = 0L;
    int32_t *l_4251 = (void*)0;
    int32_t *l_4252 = &g_25;
    int32_t l_4253 = 0x2ABE3B11L;
    int32_t *l_4254 = &l_4250;
    int32_t *l_4255 = &l_4250;
    int32_t *l_4256 = &g_2243;
    int32_t *l_4257 = &g_2951;
    int32_t *l_4258 = (void*)0;
    int32_t *l_4259 = (void*)0;
    int32_t *l_4260 = &g_2243;
    int32_t *l_4261 = &l_4250;
    int32_t *l_4262 = (void*)0;
    int32_t *l_4263 = &g_2243;
    int32_t *l_4264 = (void*)0;
    int32_t l_4265 = 0xB26642C1L;
    int32_t *l_4266 = (void*)0;
    int32_t *l_4267 = &g_25;
    int32_t *l_4268 = &g_25;
    int32_t *l_4269 = &g_2243;
    int32_t *l_4270 = &g_62;
    int32_t *l_4271 = &g_62;
    int32_t *l_4272 = &l_4265;
    int32_t *l_4273 = &g_2243;
    int32_t *l_4274 = (void*)0;
    int32_t *l_4275 = &g_25;
    int32_t *l_4276 = &g_2951;
    int32_t l_4277 = (-3L);
    int32_t *l_4278 = &g_25;
    int32_t *l_4279 = &g_25;
    int32_t *l_4280 = (void*)0;
    int32_t *l_4281 = &g_25;
    int32_t *l_4282 = &l_4277;
    int32_t *l_4283 = &g_2243;
    int32_t *l_4284 = &g_2243;
    int32_t *l_4285 = &g_62;
    int32_t *l_4286 = (void*)0;
    int32_t *l_4287 = &l_4253;
    int32_t *l_4288 = &g_25;
    int32_t *l_4289 = (void*)0;
    int32_t *l_4290 = &g_2243;
    int32_t *l_4291 = &l_4253;
    int32_t *l_4292 = (void*)0;
    int32_t *l_4293 = &l_4253;
    int32_t *l_4294 = &l_4265;
    int32_t *l_4295 = &l_4253;
    int32_t *l_4296 = &l_4265;
    int32_t *l_4297 = &g_62;
    int32_t *l_4298 = &g_25;
    int32_t *l_4299 = &g_62;
    int32_t l_4300 = 5L;
    int32_t *l_4301 = &l_4277;
    int32_t *l_4302 = (void*)0;
    int32_t *l_4303 = (void*)0;
    int32_t *l_4304 = &l_4300;
    int32_t *l_4305 = &g_25;
    int32_t *l_4306 = &l_4277;
    int32_t *l_4307 = (void*)0;
    int32_t *l_4308 = (void*)0;
    int32_t *l_4309 = &l_4250;
    int32_t *l_4310 = (void*)0;
    int32_t *l_4311 = &g_62;
    int32_t *l_4312 = &l_4265;
    int32_t *l_4313 = &l_4253;
    int32_t *l_4314 = &l_4250;
    int32_t *l_4315 = &l_4300;
    int32_t *l_4316 = &l_4250;
    int32_t l_4317 = 0x48237BEAL;
    int32_t *l_4318 = &l_4253;
    int32_t *l_4319 = &l_4300;
    int32_t *l_4320 = &l_4300;
    int32_t *l_4321 = &g_2243;
    int32_t *l_4322 = &l_4317;
    int32_t *l_4323 = &g_2243;
    int32_t *l_4324 = &g_25;
    int32_t *l_4325 = &l_4300;
    int32_t l_4326 = 0x667759C3L;
    int32_t *l_4327 = &g_25;
    int32_t *l_4328 = &g_2243;
    int32_t *l_4329 = &g_62;
    int32_t *l_4330 = (void*)0;
    int32_t *l_4331 = &g_62;
    int32_t *l_4332 = &l_4265;
    int32_t *l_4333 = &l_4326;
    int32_t *l_4334 = (void*)0;
    int32_t *l_4335 = &g_2951;
    int32_t *l_4336 = (void*)0;
    int32_t *l_4337 = (void*)0;
    int32_t *l_4338 = &g_62;
    int32_t *l_4339 = &l_4277;
    int32_t l_4340 = 0x037F92D6L;
    int32_t *l_4341 = &l_4300;
    int32_t *l_4342 = (void*)0;
    int32_t l_4343 = 0x3F804C9EL;
    int32_t *l_4344 = &l_4343;
    int32_t *l_4345 = &l_4317;
    int32_t *l_4346 = &l_4340;
    int32_t *l_4347 = &l_4343;
    int32_t *l_4348 = &l_4343;
    int32_t *l_4349 = &l_4317;
    int32_t *l_4350 = &l_4343;
    int32_t *l_4351 = &l_4317;
    int32_t l_4352 = 0x7977F3EFL;
    int32_t *l_4353 = &l_4317;
    int32_t l_4354 = (-2L);
    int32_t *l_4355 = (void*)0;
    int32_t l_4356 = (-1L);
    int32_t *l_4357 = &l_4356;
    int32_t *l_4358 = (void*)0;
    int32_t *l_4359 = &g_25;
    int32_t *l_4360 = (void*)0;
    int32_t *l_4361 = &l_4265;
    int32_t *l_4362 = &l_4265;
    int32_t *l_4363 = &l_4340;
    int32_t *l_4364 = (void*)0;
    int32_t *l_4365 = (void*)0;
    int32_t *l_4366 = (void*)0;
    int32_t *l_4367 = (void*)0;
    int32_t *l_4368 = &l_4265;
    int32_t *l_4369 = (void*)0;
    int32_t *l_4370 = &l_4354;
    int32_t *l_4371 = &l_4354;
    int32_t *l_4372 = &l_4300;
    int32_t *l_4373 = &l_4352;
    int32_t *l_4374 = &l_4326;
    int32_t *l_4375 = &l_4265;
    int32_t *l_4376 = &l_4250;
    int32_t *l_4377 = &l_4343;
    int32_t *l_4378 = &g_62;
    int32_t *l_4379 = (void*)0;
    int32_t l_4380 = (-1L);
    int32_t *l_4381 = (void*)0;
    int32_t *l_4382 = &l_4352;
    int32_t *l_4383 = &l_4265;
    int32_t l_4384 = 0L;
    int32_t *l_4385 = (void*)0;
    int32_t *l_4386 = &l_4340;
    int32_t *l_4387 = (void*)0;
    int32_t *l_4388 = &g_62;
    int32_t *l_4389 = &l_4356;
    int32_t *l_4390 = &l_4317;
    int32_t *l_4391 = &l_4317;
    int32_t *l_4392 = &l_4300;
    int32_t *l_4393 = &l_4253;
    int32_t *l_4394 = &l_4300;
    int32_t *l_4395 = &l_4300;
    int32_t *l_4396 = (void*)0;
    int32_t *l_4397 = &l_4250;
    int32_t *l_4398 = &l_4343;
    int32_t *l_4399 = (void*)0;
    int32_t *l_4400 = &l_4354;
    int32_t *l_4401 = &l_4300;
    int32_t *l_4402 = &l_4354;
    int32_t *l_4403 = &l_4343;
    int32_t *l_4404 = &l_4340;
    int32_t *l_4405 = &l_4300;
    int32_t *l_4406 = &l_4253;
    int32_t *l_4407 = &l_4300;
    int32_t *l_4408 = &l_4384;
    int32_t *l_4409 = &l_4384;
    int32_t *l_4410 = (void*)0;
    int32_t *l_4411 = (void*)0;
    int32_t *l_4412 = &l_4343;
    int32_t *l_4413 = &g_2243;
    int32_t *l_4414 = &g_2951;
    int32_t *l_4415 = &l_4317;
    int32_t *l_4416 = &l_4384;
    int32_t *l_4417 = &l_4277;
    int32_t *l_4418 = &l_4352;
    int32_t *l_4419 = &g_2951;
    int32_t *l_4420 = &l_4354;
    int32_t *l_4421 = &l_4340;
    int32_t *l_4422 = &g_2243;
    int32_t *l_4423 = (void*)0;
    int32_t *l_4424 = (void*)0;
    int32_t *l_4425 = (void*)0;
    int32_t *l_4426 = (void*)0;
    int32_t *l_4427 = &l_4253;
    int32_t *l_4428 = &l_4340;
    int32_t l_4429 = 0x48043658L;
    int32_t *l_4430 = &l_4380;
    int32_t *l_4431 = (void*)0;
    int32_t *l_4432 = &l_4277;
    int32_t *l_4433 = (void*)0;
    int32_t *l_4434 = (void*)0;
    int32_t *l_4435 = &l_4354;
    int32_t *l_4436 = &l_4354;
    int32_t *l_4437 = &l_4300;
    int32_t l_4438 = 0xAF8CFB1DL;
    int32_t l_4439 = 0x024D4FCBL;
    int32_t *l_4440 = (void*)0;
    int32_t *l_4441 = &l_4317;
    int32_t *l_4442 = &l_4277;
    int32_t *l_4443 = &l_4439;
    int32_t *l_4444 = (void*)0;
    int32_t *l_4445 = &l_4352;
    int32_t l_4446 = 1L;
    int32_t *l_4447 = (void*)0;
    int32_t *l_4448 = &l_4317;
    int32_t *l_4449 = &g_25;
    int32_t *l_4450 = &l_4340;
    int8_t l_4451 = 0L;
    int32_t *l_4452 = &l_4352;
    int32_t *l_4453 = (void*)0;
    int32_t *l_4454 = &l_4265;
    int32_t *l_4455 = (void*)0;
    int32_t *l_4456 = &g_62;
    int32_t *l_4457 = (void*)0;
    int32_t *l_4458 = (void*)0;
    int32_t *l_4459 = &l_4253;
    int32_t *l_4460 = &l_4277;
    int32_t *l_4461 = &l_4354;
    int32_t l_4462 = 0x9ABA066EL;
    int32_t *l_4463 = &l_4354;
    int16_t l_4464 = 0x7D24L;
    int32_t *l_4465 = (void*)0;
    int32_t *l_4466 = &l_4446;
    int32_t *l_4467 = &g_25;
    int32_t *l_4468 = (void*)0;
    int32_t *l_4469 = (void*)0;
    int32_t *l_4470 = &l_4429;
    int32_t *l_4471 = (void*)0;
    int32_t *l_4472 = &l_4253;
    int32_t *l_4473 = &l_4253;
    int32_t *l_4474 = &l_4253;
    int32_t l_4475 = 1L;
    int32_t *l_4476 = (void*)0;
    int32_t *l_4477 = &g_2243;
    int32_t *l_4478 = &l_4439;
    int32_t *l_4479 = &l_4253;
    int32_t *l_4480 = (void*)0;
    int32_t *l_4481 = (void*)0;
    int32_t *l_4482 = &l_4439;
    int32_t *l_4483 = (void*)0;
    int32_t *l_4484 = &l_4356;
    int32_t l_4485 = 0x809A8F8AL;
    int32_t *l_4486 = &l_4352;
    int32_t l_4487 = 0xD6B371AEL;
    int32_t *l_4488 = &g_2243;
    int32_t *l_4489 = &l_4438;
    int32_t *l_4490 = (void*)0;
    int32_t *l_4491 = (void*)0;
    int32_t *l_4492 = &l_4429;
    int32_t *l_4493 = &g_2951;
    int32_t *l_4494 = &l_4487;
    int32_t *l_4495 = &g_2951;
    int32_t *l_4496 = &l_4265;
    int32_t *l_4497 = &g_2951;
    int32_t l_4498 = 0xFA593587L;
    int32_t *l_4499 = &l_4485;
    int32_t *l_4500 = &l_4380;
    int32_t *l_4501 = &l_4356;
    int32_t l_4502 = 5L;
    int32_t *l_4503 = (void*)0;
    int32_t *l_4504 = &l_4475;
    int32_t *l_4505 = &l_4380;
    int32_t *l_4506 = &l_4340;
    int32_t *l_4507 = &g_62;
    int32_t *l_4508 = (void*)0;
    int32_t *l_4509 = (void*)0;
    int32_t *l_4510 = (void*)0;
    int32_t l_4511 = 0L;
    int32_t *l_4512 = &l_4511;
    int32_t *l_4513 = &l_4250;
    int32_t *l_4514 = &g_25;
    int32_t *l_4515 = &g_25;
    int32_t *l_4516 = (void*)0;
    int32_t l_4517 = 0xC69CDA21L;
    int32_t *l_4518 = &l_4340;
    int32_t *l_4519 = &l_4485;
    int32_t *l_4520 = &l_4485;
    int32_t *l_4521 = (void*)0;
    int32_t *l_4522 = &l_4475;
    int32_t l_4523 = 1L;
    int32_t *l_4524 = &l_4343;
    int32_t *l_4525 = (void*)0;
    int32_t *l_4526 = &g_2243;
    int32_t *l_4527 = &g_2951;
    int32_t *l_4528 = &l_4439;
    int32_t *l_4529 = &g_25;
    int32_t *l_4530 = &l_4438;
    int32_t *l_4531 = &l_4250;
    int32_t *l_4532 = &l_4300;
    int32_t *l_4533 = &l_4517;
    int32_t *l_4534 = &g_2951;
    int32_t *l_4535 = &l_4446;
    int32_t *l_4536 = &l_4498;
    int32_t *l_4537 = &l_4250;
    int32_t *l_4538 = &g_2951;
    int32_t *l_4539 = &l_4253;
    int32_t l_4540 = 0x39F19491L;
    int32_t *l_4541 = &l_4340;
    int32_t *l_4542 = &l_4250;
    int32_t *l_4543 = &l_4326;
    int32_t *l_4544 = &l_4517;
    int32_t *l_4545 = (void*)0;
    int32_t l_4546 = 0xB2ACBA95L;
    int32_t *l_4547 = &l_4462;
    int32_t *l_4548 = &l_4253;
    int32_t l_4549 = 2L;
    int32_t *l_4550 = (void*)0;
    int32_t *l_4551 = &l_4384;
    int32_t *l_4552 = (void*)0;
    int32_t *l_4553 = &g_25;
    int32_t l_4554 = 0x700D2CB3L;
    int32_t *l_4555 = &l_4326;
    int32_t *l_4556 = &l_4429;
    int32_t *l_4557 = &l_4429;
    int32_t *l_4558 = &l_4326;
    int32_t l_4559 = 1L;
    int32_t *l_4560 = (void*)0;
    int32_t *l_4561 = &g_25;
    int32_t *l_4562 = &g_2243;
    int32_t *l_4563 = &l_4340;
    int32_t *l_4564 = &l_4462;
    int32_t *l_4565 = &l_4517;
    int32_t *l_4566 = (void*)0;
    int32_t *l_4567 = &l_4326;
    int32_t *l_4568 = (void*)0;
    int32_t *l_4569 = &l_4265;
    int32_t l_4570 = 0x26AF8350L;
    int32_t *l_4571 = &g_2951;
    int32_t *l_4572 = &l_4485;
    int32_t *l_4573 = &l_4343;
    int32_t *l_4574 = &l_4517;
    int32_t *l_4575 = &l_4380;
    int32_t *l_4576 = &l_4559;
    int32_t *l_4577 = (void*)0;
    int32_t *l_4578 = &l_4475;
    int32_t *l_4579 = &l_4554;
    int32_t *l_4580 = &l_4546;
    int32_t *l_4581 = &l_4549;
    if (func_2((0x9A57L & ((safe_rshift_func_int16_t_s_u(func_10(l_15, g_16, ((l_15 && (safe_lshift_func_uint16_t_u_u(func_19(l_15), 0))) != (l_15 <= l_15)), (0xCC8BF9E1AA18D599LL <= g_2213.f2)), l_15)) || g_793.f0)), l_15, g_2213.f0, g_2213.f1, l_15))
    {
        struct S0 **l_4142 = (void*)0;
        struct S0 **l_4143 = (void*)0;
        struct S0 **l_4144 = &g_1529;
        (*l_4144) = (g_4141 , &g_59);

        ((g_1529 == &g_59) ? (void) (0) : __assert_fail ("g_1529 == &g_59", "t.c", 500, __PRETTY_FUNCTION__));
    }
    else
    {
        int32_t *l_4147 = &g_2243;
        int16_t l_4178 = 1L;
        const struct S1 **l_4179 = &g_1174;
        int32_t *l_4209 = &g_62;
        int32_t *l_4210 = &g_25;
        int32_t *l_4211 = &g_25;
        int32_t *l_4212 = (void*)0;
        uint8_t l_4213 = 0x23L;
        for (g_2326.f2 = 19; (g_2326.f2 < 52); g_2326.f2++)
        {
            int32_t *l_4168 = &g_62;
            int32_t **l_4169 = &l_4147;
            (*g_3800) = l_4147;

            ((g_116 == &g_2243) ? (void) (0) : __assert_fail ("g_116 == &g_2243", "t.c", 518, __PRETTY_FUNCTION__));
        }

        ((g_116 == &g_2243 || g_116 == &g_62 || g_116 == &g_25 || g_116 == &g_2951) ? (void) (0) : __assert_fail ("g_116 == &g_2243 || g_116 == &g_62 || g_116 == &g_25 || g_116 == &g_2951", "t.c", 521, __PRETTY_FUNCTION__));
        for (g_1416 = 0; (g_1416 == 17); ++g_1416)
        {
            uint16_t l_4172 = 0xCB82L;
            if ((*l_4147))
                break;
            if (l_4172)
                continue;
            l_4147 = l_4147;
        }
        if (l_15)
        {
            const struct S1 **l_4180 = &g_1174;
            int32_t l_4184 = 0x3ABA727BL;
            l_4180 = ((safe_mul_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(((*g_1529) , (l_4167 || 1L)), (!(*g_116)))), l_4178)) , l_4179);
            (*g_1596) = g_4181;
            for (g_2951 = 0; (g_2951 <= 0); g_2951 = safe_add_func_int8_t_s_s(g_2951, 8))
            {
                if (l_4184)
                    break;
            }
        }
        else
        {
            int32_t ** const l_4191 = &g_116;
            int32_t l_4208 = 6L;
            l_4208 |= (((safe_lshift_func_int8_t_s_u(((safe_add_func_int16_t_s_s((safe_sub_func_int8_t_s_s((((((((void*)0 != l_4191) > (**l_4191)) , g_2321.f1) , (safe_mul_func_int16_t_s_s(((safe_add_func_int16_t_s_s(6L, (safe_add_func_uint16_t_u_u((((((**l_4191) < (((safe_lshift_func_uint8_t_u_u(((((*l_4147) , func_30((safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u((1L ^ (safe_sub_func_uint32_t_u_u(((safe_mul_func_uint16_t_u_u(((((-7L) & 0x94L) , l_15) == 1L), 3L)) > g_803.f3), (**l_4191)))), 4)), g_566)), (*l_4191))) != l_4147) <= g_1163.f1), 2)) , (**l_4191)) , 0xBC18EE71L)) != (**l_4191)) <= 0UL) < g_4141.f4), l_4167)))) >= (**l_4191)), 0x9142L))) & (*l_4147)) && 9L), g_2325.f0)), (*l_4147))) , 0xBAL), g_1163.f1)) , (*l_4147)) ^ (*l_4147));
        }
        ++l_4213;
    }

    ((g_116 == &g_2243 || g_116 == &g_62 || g_116 == &g_25 || g_116 == &g_2951) ? (void) (0) : __assert_fail ("g_116 == &g_2243 || g_116 == &g_62 || g_116 == &g_25 || g_116 == &g_2951", "t.c", 552, __PRETTY_FUNCTION__));

    ((g_1529 == &g_1530 || g_1529 == &g_59) ? (void) (0) : __assert_fail ("g_1529 == &g_1530 || g_1529 == &g_59", "t.c", 554, __PRETTY_FUNCTION__));
    (*g_4216) = &g_3771;

    ((g_4217 == &g_3771) ? (void) (0) : __assert_fail ("g_4217 == &g_3771", "t.c", 557, __PRETTY_FUNCTION__));
    --g_4582;
    return g_4585;
}







static int32_t func_2(const int8_t p_3, int8_t p_4, const uint16_t p_5, uint16_t p_6, int64_t p_7)
{
    int32_t *l_2977 = &g_25;
    int32_t *l_2978 = &g_2243;
    int32_t *l_2979 = &g_62;
    int32_t *l_2980 = &g_2243;
    int32_t l_2981 = 5L;
    int32_t *l_2982 = &g_2243;
    int32_t *l_2983 = &g_2951;
    int32_t *l_2984 = &l_2981;
    int32_t *l_2985 = &g_25;
    int32_t *l_2986 = &g_25;
    int32_t *l_2987 = (void*)0;
    int32_t *l_2988 = (void*)0;
    int32_t *l_2989 = &g_2951;
    int32_t *l_2990 = &g_62;
    int32_t *l_2991 = &g_25;
    int32_t *l_2992 = &g_25;
    int32_t *l_2993 = &g_25;
    int32_t *l_2994 = &l_2981;
    int32_t *l_2995 = &g_62;
    int32_t *l_2996 = &g_62;
    uint16_t l_2997 = 0xC9EAL;
    volatile struct S1 *l_3013 = &g_2191;
    int32_t l_3126 = 0L;
    int32_t l_3176 = 6L;
    int32_t l_3226 = (-1L);
    int32_t l_3321 = 0L;
    int32_t l_3328 = (-4L);
    int32_t l_3333 = 0L;
    int32_t l_3356 = 5L;
    int32_t l_3361 = (-1L);
    int64_t l_3747 = 0L;
    int64_t l_3749 = 0L;
    uint16_t l_3751 = 65534UL;
    int32_t l_3926 = (-1L);
    uint64_t l_4130 = 1UL;
    l_2997++;
    for (g_25 = (-6); (g_25 >= 4); g_25++)
    {
        int16_t l_3004 = 0x2013L;
        int32_t *l_3009 = &l_2981;
        uint32_t l_3041 = 0x651F90C1L;
        struct S0 * const l_3076 = &g_804;
        int32_t *l_3090 = &g_2951;
        int32_t l_3097 = 0x35609814L;
        int32_t l_3105 = 1L;
        int32_t l_3110 = 3L;
        int32_t l_3147 = 0xE69C58B4L;
        int32_t l_3269 = 0x28AD7FACL;
        int32_t l_3289 = 0xD54208E6L;
        int32_t l_3302 = 0x21E03CEAL;
        int32_t l_3317 = 0xC98A449BL;
        int32_t l_3345 = 0x41385635L;
        uint32_t l_3920 = 4294967286UL;
        int32_t *l_3923 = (void*)0;
        struct S0 **l_4140 = &g_1529;
    }
    return (*l_2977);
}







static int16_t func_10(uint32_t p_11, int32_t p_12, uint8_t p_13, int16_t p_14)
{
    uint32_t l_2958 = 0x5D6F4B1AL;
    uint32_t l_2961 = 7UL;
    int32_t *l_2975 = &g_2951;
    (*g_2976) = func_49(l_2958, (*g_2678), g_2792.f2, (((safe_lshift_func_int16_t_s_u(l_2961, 0)) | (((p_12 & (safe_lshift_func_int8_t_s_u((safe_add_func_int64_t_s_s(((~(safe_lshift_func_uint16_t_u_s(0xFDCDL, l_2961))) , (((((safe_add_func_uint8_t_u_u((((safe_mod_func_uint64_t_u_u(1UL, (safe_rshift_func_int8_t_s_u((l_2961 , (-8L)), 1)))) && (-7L)) < l_2958), l_2961)) , g_2325.f0) == 0xC1C0960FL) , (void*)0) != (void*)0)), g_1163.f1)), l_2958))) , p_14) <= g_2951)) , l_2975));

    ((g_116 == &g_62 || g_116 == &g_25 || g_116 == &g_2951) ? (void) (0) : __assert_fail ("g_116 == &g_62 || g_116 == &g_25 || g_116 == &g_2951", "t.c", 642, __PRETTY_FUNCTION__));
    return p_13;
}







static uint16_t func_19(int32_t p_20)
{
    uint16_t l_22 = 0x780EL;
    int32_t *l_23 = (void*)0;
    int32_t *l_24 = &g_25;
    int32_t *l_2950 = &g_2951;
    int32_t ***l_2953 = &g_132;
    int32_t *l_2956 = (void*)0;
    int32_t *l_2957 = &g_62;
    (*l_24) = (!l_22);
    (*l_2950) &= (func_26((*l_24), func_30(p_20, (g_16 , (((p_20 , (safe_mul_func_int16_t_s_s(func_35(g_16), ((safe_sub_func_int16_t_s_s(p_20, p_20)) || (*l_24))))) >= 1L) , (*g_2678)))), l_24) == p_20);

    ((g_116 == &g_62 || g_116 == &g_25) ? (void) (0) : __assert_fail ("g_116 == &g_62 || g_116 == &g_25", "t.c", 664, __PRETTY_FUNCTION__));

    (*l_2957) &= ((p_20 < ((g_2952 , (l_2953 != ((*l_2950) , l_2953))) == g_2325.f1)) == ((*l_24) <= (safe_sub_func_uint8_t_u_u((1L <= p_20), g_1441.f4))));
    return (*l_24);
}







static uint64_t func_26(int64_t p_27, int32_t * p_28, const int32_t * const p_29)
{
    const uint32_t l_2817 = 0UL;
    int32_t *l_2826 = &g_2243;
    int32_t *l_2827 = &g_62;
    int32_t l_2828 = 0x1ADE7B66L;
    int32_t *l_2829 = (void*)0;
    int32_t *l_2830 = &g_62;
    int32_t *l_2831 = &g_25;
    int32_t *l_2832 = &l_2828;
    int32_t *l_2833 = &g_2243;
    int32_t l_2834 = (-10L);
    int32_t *l_2835 = &l_2834;
    int32_t l_2836 = 0xB0B37AC5L;
    int32_t *l_2837 = &g_2243;
    int32_t *l_2838 = &l_2828;
    int32_t *l_2839 = &g_25;
    int32_t *l_2840 = &g_2243;
    int32_t *l_2841 = (void*)0;
    int32_t *l_2842 = &l_2836;
    int32_t *l_2843 = &g_2243;
    int32_t *l_2844 = &l_2834;
    int32_t *l_2845 = &l_2836;
    int32_t *l_2846 = (void*)0;
    int32_t *l_2847 = &l_2834;
    int32_t *l_2848 = &l_2836;
    int32_t *l_2849 = &g_25;
    int32_t *l_2850 = &g_62;
    int32_t *l_2851 = &g_62;
    int32_t *l_2852 = (void*)0;
    int32_t l_2853 = 1L;
    int32_t *l_2854 = &g_2243;
    int32_t *l_2855 = (void*)0;
    int32_t *l_2856 = (void*)0;
    int32_t *l_2857 = (void*)0;
    int32_t l_2858 = (-1L);
    int32_t *l_2859 = &l_2836;
    int8_t l_2860 = 0xFDL;
    int32_t *l_2861 = &l_2836;
    int32_t *l_2862 = &l_2853;
    int32_t l_2863 = 0x196E9328L;
    int32_t *l_2864 = (void*)0;
    int32_t *l_2865 = &l_2853;
    int32_t *l_2866 = (void*)0;
    int32_t *l_2867 = &g_62;
    int32_t *l_2868 = (void*)0;
    int32_t *l_2869 = (void*)0;
    int32_t *l_2870 = &g_25;
    int32_t *l_2871 = &l_2853;
    int32_t *l_2872 = (void*)0;
    int32_t *l_2873 = &l_2858;
    int32_t *l_2874 = &l_2853;
    int32_t l_2875 = (-1L);
    int32_t *l_2876 = &g_2243;
    int32_t *l_2877 = &l_2828;
    int32_t *l_2878 = (void*)0;
    int32_t *l_2879 = &l_2834;
    int32_t *l_2880 = &g_25;
    int32_t *l_2881 = &l_2875;
    int32_t *l_2882 = &g_62;
    int32_t *l_2883 = &g_2243;
    int32_t *l_2884 = (void*)0;
    int32_t *l_2885 = &l_2853;
    int32_t *l_2886 = (void*)0;
    int32_t *l_2887 = &g_25;
    int32_t *l_2888 = &l_2853;
    int32_t *l_2889 = (void*)0;
    int32_t *l_2890 = &l_2836;
    int32_t *l_2891 = &l_2853;
    int32_t l_2892 = (-1L);
    int32_t *l_2893 = (void*)0;
    int32_t *l_2894 = &l_2853;
    int32_t *l_2895 = &l_2853;
    int32_t *l_2896 = &l_2858;
    int32_t *l_2897 = &g_62;
    int32_t *l_2898 = &l_2858;
    int32_t *l_2899 = &g_62;
    int32_t *l_2900 = &l_2834;
    int32_t *l_2901 = &g_2243;
    int32_t *l_2902 = &g_2243;
    int32_t *l_2903 = &l_2834;
    int32_t *l_2904 = &g_25;
    int32_t *l_2905 = (void*)0;
    int32_t *l_2906 = &l_2863;
    int32_t *l_2907 = &l_2834;
    int32_t *l_2908 = &g_25;
    int32_t *l_2909 = &g_62;
    int32_t *l_2910 = &g_25;
    int32_t *l_2911 = &g_62;
    int32_t *l_2912 = &l_2863;
    int32_t *l_2913 = (void*)0;
    int32_t *l_2914 = &l_2892;
    int32_t *l_2915 = &g_2243;
    int32_t *l_2916 = &l_2863;
    int32_t *l_2917 = (void*)0;
    int32_t *l_2918 = &l_2834;
    int32_t *l_2919 = &g_2243;
    int32_t *l_2920 = &l_2892;
    int32_t *l_2921 = (void*)0;
    int32_t l_2922 = 9L;
    int32_t *l_2923 = &g_2243;
    int32_t *l_2924 = &g_62;
    int32_t *l_2925 = &l_2858;
    int32_t *l_2926 = &g_2243;
    int32_t l_2927 = 0L;
    int32_t *l_2928 = &g_25;
    int32_t *l_2929 = &l_2892;
    int32_t *l_2930 = &l_2863;
    int32_t *l_2931 = &l_2858;
    int32_t *l_2932 = &l_2858;
    int32_t *l_2933 = (void*)0;
    int32_t *l_2934 = &g_2243;
    int32_t *l_2935 = &l_2927;
    int32_t *l_2936 = &g_62;
    int32_t *l_2937 = (void*)0;
    int32_t *l_2938 = &l_2875;
    int32_t *l_2939 = (void*)0;
    int32_t *l_2940 = &l_2834;
    int32_t *l_2941 = (void*)0;
    int32_t *l_2942 = &l_2834;
    int32_t *l_2943 = &g_25;
    int32_t *l_2944 = &l_2922;
    int32_t *l_2945 = &g_2243;
    int32_t *l_2946 = (void*)0;
    uint8_t l_2947 = 0xBBL;
    (*g_2678) = func_30((+(+(safe_mod_func_int32_t_s_s(((0x8FL & ((p_27 || p_27) || ((safe_mod_func_uint16_t_u_u((((p_27 >= ((((((safe_add_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s((safe_mul_func_uint8_t_u_u((safe_add_func_uint64_t_u_u(((l_2817 ^ l_2817) || (safe_add_func_uint8_t_u_u(((safe_mod_func_uint16_t_u_u((safe_sub_func_int64_t_s_s((safe_rshift_func_int16_t_s_u((((**g_1595) , (l_2817 > 1L)) >= g_2325.f0), 8)), l_2817)), 0x05E9L)) != 0x5F87619ED5B49B04LL), p_27))), g_1163.f2)), p_27)), 3)), g_804.f4)) , p_27) || 0x64F7L) || 2L) , p_27) < l_2817)) & 0xE6L) || p_27), l_2817)) != 0xB966683A7C861535LL))) == g_16), 0x4F3C7360L)))), l_2826);
    ++l_2947;
    return g_1648;
}







static int32_t * func_30(uint32_t p_31, int32_t * p_32)
{
    struct S1 *l_2791 = &g_1594;
    int32_t l_2801 = (-1L);
    int32_t *l_2802 = &l_2801;
    l_2802 = ((safe_sub_func_uint16_t_u_u(((((!(((+p_31) > ((safe_unary_minus_func_uint32_t_u(((safe_mul_func_uint16_t_u_u((0x4DL < ((void*)0 != l_2791)), (g_2792 , (0xC02B8BA01BD72C3CLL & (g_753.f0 & (safe_rshift_func_int8_t_s_s(((+0xC23E8EFAL) <= (safe_add_func_uint32_t_u_u((safe_mod_func_int8_t_s_s(((!l_2801) >= 18446744073709551608UL), l_2801)), (*p_32)))), 3))))))) , p_31))) || p_31)) && p_31)) , 1L) != g_2213.f2) >= (-1L)), p_31)) , (void*)0);

    ((l_2802 == 0) ? (void) (0) : __assert_fail ("l_2802 == 0", "t.c", 819, __PRETTY_FUNCTION__));
    return (*g_2678);


}







static int16_t func_35(const uint32_t p_36)
{
    uint16_t l_54 = 65535UL;
    int32_t *l_57 = &g_25;
    uint32_t l_2190 = 0x41CD021CL;
    struct S1 **l_2194 = (void*)0;
    uint32_t l_2234 = 2UL;
    int32_t ***l_2319 = &g_132;
    int32_t l_2427 = 0x5F119CB9L;
    int32_t l_2459 = (-5L);
    int32_t l_2465 = 0x2E05D2B1L;
    int32_t l_2485 = (-1L);
    int32_t l_2494 = 0L;
    int32_t l_2517 = 0x33E3C823L;
    int32_t l_2568 = 0x2E6A4121L;
    int32_t l_2617 = 1L;
    struct S0 *l_2773 = &g_804;
    if (((safe_add_func_int8_t_s_s((((safe_mod_func_uint16_t_u_u(0x7B18L, ((((safe_mul_func_uint8_t_u_u(248UL, func_43((func_47(func_49((p_36 , ((l_54 | (((((safe_lshift_func_uint16_t_u_u((l_57 == (((l_57 != &g_25) ^ ((((*l_57) != (~(g_59 , g_59.f5))) , (*l_57)) , p_36)) , (void*)0)), g_16)) ^ p_36) && g_59.f5) , p_36) ^ p_36)) == 0xCA51C18CC907F7A7LL)), &g_25, g_16, l_57)) < 0x92B9A8F9557A7308LL), (*l_57), l_57))) , (*l_57)) , 0x67AC54D3FEF8CBB3LL) | 4UL))) == 0x178EEDC809F5503ELL) != 18446744073709551615UL), g_566)) > l_2190))
    {
        uint32_t l_2196 = 0xC84F78B0L;
        int32_t l_2203 = 0x8E4563EDL;
        int32_t *l_2209 = &l_2203;
        int32_t l_2238 = 0x367A2A0FL;
        (*g_1596) = g_2191;
        l_2203 &= ((safe_lshift_func_uint16_t_u_s((((g_126.f3 , l_2194) != (void*)0) != (+l_2196)), 1)) | ((((safe_add_func_uint64_t_u_u((((*l_57) && l_2196) & l_2196), (safe_mul_func_uint16_t_u_u((safe_sub_func_int32_t_s_s((g_803.f4 & l_2196), (*g_116))), g_1163.f0)))) >= g_818.f2) , (*l_57)) , 0xBA0BL));
        for (g_566 = (-13); (g_566 == (-24)); g_566--)
        {
            int32_t *l_2208 = &g_25;
            int32_t *l_2226 = (void*)0;
            int32_t *l_2227 = &g_62;
            l_2209 = ((g_1202.f1 > (((*l_57) ^ (*l_57)) || ((*g_1596) , ((safe_mul_func_uint8_t_u_u(p_36, ((&l_2203 != (void*)0) >= p_36))) >= (l_2203 ^ 0x93CCL))))) , l_2208);

            ((l_2209 == &g_25) ? (void) (0) : __assert_fail ("l_2209 == &g_25", "t.c", 863, __PRETTY_FUNCTION__));
            (*g_2210) = (*g_1595);
            (*l_2227) |= (safe_sub_func_int32_t_s_s((p_36 <= (g_2213 , (((((*g_1595) != (void*)0) < (((((g_1530.f4 ^ ((safe_mod_func_uint16_t_u_u((safe_mul_func_int16_t_s_s(((safe_mul_func_uint8_t_u_u(255UL, (safe_mod_func_int8_t_s_s(0x49L, ((safe_sub_func_int8_t_s_s((((((p_36 , ((safe_rshift_func_uint8_t_u_s((*l_2209), 3)) & 0xD4FC38EBL)) && p_36) != 1UL) != 65526UL) && p_36), g_818.f0)) && 8UL))))) != (*l_2209)), 0xA830L)), p_36)) <= 0x9BB53017L)) , (*l_2209)) , g_1530.f4) <= 6UL) && p_36)) != (*l_57)) , 1L))), (*l_57)));
        }

        ((l_2209 == &g_25 || l_2209 == &l_2203) ? (void) (0) : __assert_fail ("l_2209 == &g_25 || l_2209 == &l_2203", "t.c", 868, __PRETTY_FUNCTION__));
        l_2238 |= ((-1L) ^ ((0x9DC9L > (*l_2209)) == ((safe_rshift_func_uint8_t_u_u((safe_sub_func_int64_t_s_s(((safe_mod_func_uint64_t_u_u(p_36, 0xB143F17757A0342FLL)) < 0x7896L), g_2191.f2)), l_2234)) , ((((((safe_sub_func_uint8_t_u_u((~p_36), p_36)) > (*l_57)) & g_1441.f4) >= 5L) == (-5L)) & 0x6DL))));
    }
    else
    {
        uint64_t l_2248 = 0xDD18997FA8F6DB87LL;
        uint64_t l_2269 = 0x564BFA94CEFBE635LL;
        struct S1 *l_2271 = &g_1594;
        struct S1 **l_2270 = &l_2271;
        uint32_t l_2285 = 4294967294UL;
        int32_t * const *l_2287 = &l_57;
        int8_t l_2337 = 2L;
        int32_t l_2361 = 0x37885045L;
        int32_t l_2362 = 0xE1154088L;
        int32_t l_2363 = (-8L);
        int32_t l_2400 = 0x8E312C68L;
        int32_t l_2509 = 0x22D7CEE5L;
        int32_t l_2533 = 1L;
        int32_t l_2595 = 1L;
        int32_t l_2604 = 0xBAA8EF24L;
        int32_t l_2635 = 1L;
        int32_t l_2643 = 0L;
        uint32_t l_2762 = 4294967289UL;
        int16_t l_2779 = 0xAFD3L;
        struct S0 **l_2780 = (void*)0;
        struct S0 **l_2781 = &l_2773;
        for (g_62 = 0; (g_62 >= 25); g_62 = safe_add_func_int64_t_s_s(g_62, 5))
        {
            int32_t *l_2241 = (void*)0;
            int32_t *l_2242 = &g_2243;
            (*l_2242) ^= (-6L);
            return p_36;
        }
    }

    ((g_116 == &g_62 || g_116 == &g_25) ? (void) (0) : __assert_fail ("g_116 == &g_62 || g_116 == &g_25", "t.c", 903, __PRETTY_FUNCTION__));

    return g_2243;
}







static const uint8_t func_43(uint64_t p_44, uint32_t p_45, int32_t * p_46)
{
    int32_t *** const l_704 = &g_132;
    int32_t **l_709 = &g_116;
    const uint8_t l_777 = 1UL;
    uint16_t l_807 = 0UL;
    int32_t l_908 = 0xC5147139L;
    int32_t l_918 = 0x8B7F6920L;
    int32_t l_922 = 0xFF7BCDF7L;
    int32_t l_944 = 0xC58AB593L;
    int32_t l_958 = (-10L);
    int32_t l_997 = 0L;
    int32_t l_1015 = 0x4A7AD74EL;
    int32_t l_1016 = 0x7BD9BDBFL;
    int32_t l_1039 = 0L;
    int32_t l_1058 = 7L;
    int32_t l_1090 = 0L;
    int32_t l_1091 = (-1L);
    int32_t l_1099 = 0xC8CA76D0L;
    int32_t l_1100 = 2L;
    int32_t l_1140 = 0xED7C10AEL;
    int16_t l_1177 = 0L;
    struct S1 *l_1240 = (void*)0;
    struct S0 *l_1439 = &g_804;
    const uint32_t l_1476 = 0UL;
    uint32_t l_1593 = 4294967290UL;
    uint64_t l_1629 = 0x962AFD454BA31351LL;
    uint32_t l_1634 = 18446744073709551607UL;
    uint16_t l_1709 = 0x4026L;
    int16_t l_1946 = (-1L);
    uint64_t l_2001 = 7UL;
    uint64_t l_2011 = 0x7393A533B549B532LL;
    uint32_t l_2012 = 0UL;
    int32_t *l_2018 = &l_908;
    int32_t *l_2019 = &l_1099;
    int32_t *l_2020 = &l_1090;
    int32_t *l_2021 = &l_1099;
    int32_t *l_2022 = &l_1091;
    int32_t *l_2023 = &l_908;
    int32_t *l_2024 = &l_1090;
    int32_t *l_2025 = &l_1140;
    int32_t *l_2026 = (void*)0;
    int32_t *l_2027 = (void*)0;
    int32_t *l_2028 = &l_1058;
    int32_t *l_2029 = &l_918;
    int32_t *l_2030 = &l_922;
    int32_t *l_2031 = &l_1100;
    int32_t *l_2032 = &l_958;
    int32_t *l_2033 = &l_1140;
    int32_t *l_2034 = &l_908;
    int32_t *l_2035 = &l_918;
    int32_t *l_2036 = &l_1090;
    int32_t *l_2037 = (void*)0;
    int32_t *l_2038 = &l_1090;
    int32_t *l_2039 = (void*)0;
    int32_t *l_2040 = &l_997;
    int32_t *l_2041 = &l_997;
    int32_t *l_2042 = (void*)0;
    int32_t *l_2043 = &l_1058;
    int32_t *l_2044 = (void*)0;
    int32_t *l_2045 = &l_1039;
    int32_t *l_2046 = &l_908;
    int32_t *l_2047 = &l_1039;
    int32_t *l_2048 = &l_908;
    int32_t *l_2049 = &l_1099;
    int32_t *l_2050 = &l_997;
    int32_t *l_2051 = &l_1099;
    int32_t *l_2052 = &l_1099;
    int32_t *l_2053 = &l_922;
    int32_t *l_2054 = &l_1140;
    int32_t *l_2055 = &l_944;
    int32_t *l_2056 = &l_1090;
    int32_t *l_2057 = &l_1091;
    int32_t *l_2058 = &l_997;
    int32_t *l_2059 = &g_62;
    int32_t *l_2060 = &l_1100;
    int32_t *l_2061 = &l_1140;
    int32_t *l_2062 = &l_1091;
    int32_t *l_2063 = &l_918;
    int32_t *l_2064 = &l_922;
    int32_t *l_2065 = &l_1091;
    int32_t *l_2066 = (void*)0;
    int32_t *l_2067 = &l_1091;
    int32_t *l_2068 = &l_1016;
    int32_t *l_2069 = &l_1140;
    int32_t *l_2070 = (void*)0;
    int32_t *l_2071 = &l_1099;
    int32_t *l_2072 = (void*)0;
    int32_t *l_2073 = &l_1140;
    int32_t *l_2074 = &l_958;
    int32_t *l_2075 = &l_958;
    int32_t *l_2076 = &l_1016;
    int32_t *l_2077 = &l_922;
    int32_t *l_2078 = &l_997;
    int32_t *l_2079 = &l_1016;
    int32_t *l_2080 = (void*)0;
    int32_t *l_2081 = (void*)0;
    int32_t *l_2082 = &l_908;
    int32_t *l_2083 = &l_1090;
    int32_t *l_2084 = &g_62;
    int32_t *l_2085 = &l_997;
    int32_t *l_2086 = &l_1015;
    int32_t *l_2087 = &l_1058;
    int32_t *l_2088 = &l_958;
    int32_t *l_2089 = (void*)0;
    int32_t *l_2090 = &l_944;
    int32_t *l_2091 = &l_908;
    int32_t *l_2092 = &l_1099;
    int32_t *l_2093 = &l_1100;
    int32_t *l_2094 = (void*)0;
    int32_t *l_2095 = (void*)0;
    int32_t *l_2096 = &l_1058;
    int32_t *l_2097 = &l_1039;
    int32_t *l_2098 = &l_1140;
    int32_t *l_2099 = &l_958;
    int32_t *l_2100 = &l_1016;
    int32_t *l_2101 = &l_1099;
    int32_t *l_2102 = &l_1099;
    int32_t *l_2103 = (void*)0;
    int32_t *l_2104 = (void*)0;
    int32_t *l_2105 = &l_922;
    int32_t *l_2106 = &l_1090;
    int32_t *l_2107 = &l_908;
    int32_t *l_2108 = &l_1091;
    int32_t *l_2109 = (void*)0;
    int32_t *l_2110 = &l_1016;
    int32_t *l_2111 = &l_944;
    int32_t *l_2112 = &l_958;
    int32_t *l_2113 = &g_62;
    int32_t *l_2114 = &l_1015;
    int32_t *l_2115 = &l_958;
    int32_t *l_2116 = &l_1016;
    int32_t *l_2117 = &l_922;
    int32_t *l_2118 = &l_1016;
    int32_t *l_2119 = (void*)0;
    int32_t *l_2120 = (void*)0;
    int32_t *l_2121 = &l_1099;
    int32_t *l_2122 = &l_944;
    int32_t *l_2123 = &l_922;
    int32_t *l_2124 = &l_1090;
    int32_t l_2125 = 0xC0F997D1L;
    int32_t l_2126 = 0x97F60571L;
    int32_t *l_2127 = &l_1090;
    int32_t l_2128 = (-6L);
    int32_t *l_2129 = &l_2125;
    int32_t *l_2130 = &l_1016;
    int32_t *l_2131 = &l_1140;
    int32_t l_2132 = (-1L);
    int32_t *l_2133 = (void*)0;
    int32_t *l_2134 = (void*)0;
    int32_t *l_2135 = &l_1039;
    int32_t *l_2136 = &l_1099;
    int32_t l_2137 = 0x0EB4AA9BL;
    int32_t *l_2138 = (void*)0;
    int32_t l_2139 = 0xA18930ACL;
    int32_t *l_2140 = &l_2139;
    int32_t *l_2141 = &l_1016;
    int32_t *l_2142 = &l_2128;
    int32_t *l_2143 = &l_1058;
    int32_t l_2144 = 0x2B43A455L;
    int32_t l_2145 = 0x4D40EB13L;
    int32_t *l_2146 = &l_908;
    int32_t *l_2147 = (void*)0;
    int32_t *l_2148 = &l_2144;
    int32_t *l_2149 = (void*)0;
    int32_t *l_2150 = &l_908;
    int32_t *l_2151 = (void*)0;
    int32_t *l_2152 = &l_2125;
    int32_t *l_2153 = &l_1058;
    int32_t *l_2154 = &l_944;
    int32_t *l_2155 = &l_2125;
    int32_t *l_2156 = (void*)0;
    int32_t *l_2157 = &l_2145;
    int32_t *l_2158 = &l_2126;
    int32_t l_2159 = 0x0D3C3007L;
    int32_t *l_2160 = &l_908;
    int32_t *l_2161 = &l_908;
    int32_t *l_2162 = &g_62;
    int32_t *l_2163 = &l_2145;
    int32_t *l_2164 = (void*)0;
    int32_t *l_2165 = &l_1039;
    int32_t *l_2166 = &l_2144;
    int32_t *l_2167 = (void*)0;
    int32_t *l_2168 = (void*)0;
    int32_t l_2169 = (-6L);
    int32_t *l_2170 = &l_958;
    int32_t *l_2171 = &l_2145;
    int32_t *l_2172 = &l_2126;
    int32_t *l_2173 = (void*)0;
    int32_t *l_2174 = &l_1016;
    int32_t *l_2175 = &l_1140;
    int32_t l_2176 = 0x5C480870L;
    int32_t *l_2177 = &l_944;
    int32_t *l_2178 = (void*)0;
    int32_t *l_2179 = &l_944;
    int32_t l_2180 = (-1L);
    int32_t *l_2181 = &l_1090;
    int32_t *l_2182 = &l_1140;
    int32_t *l_2183 = (void*)0;
    int32_t *l_2184 = &l_1015;
    int32_t l_2185 = 0x7B14034FL;
    int32_t *l_2186 = &l_2185;
    uint32_t l_2187 = 18446744073709551612UL;
    if ((p_44 || ((((((safe_mul_func_int8_t_s_s(((void*)0 != l_704), (g_313 , (-5L)))) , p_44) || (p_46 == p_46)) && (safe_sub_func_int8_t_s_s(((((safe_mul_func_int16_t_s_s(((void*)0 == l_709), 9UL)) == (-6L)) >= 0x721688ACCEB7F38BLL) , p_45), 0xE2L))) >= 6L) , p_44)))
    {
        uint32_t l_714 = 4294967295UL;
        int32_t * const l_719 = &g_25;
        int32_t ***l_744 = &l_709;
        int32_t l_859 = (-1L);
        int32_t l_938 = 0x4459C922L;
        int32_t l_968 = 0L;
        int32_t l_992 = 0xD75EB5E2L;
        int32_t l_1003 = 0x40EFFD0AL;
        int32_t l_1042 = (-6L);
        int32_t l_1105 = (-3L);
        int32_t l_1119 = 0x34592800L;
        int32_t l_1136 = 0x86BCD265L;
        uint16_t l_1148 = 0x0182L;
        struct S1 *l_1450 = &g_1163;
        uint16_t l_1520 = 65535UL;
        uint16_t l_1531 = 0x7B4CL;
        int32_t *l_1597 = &g_62;
        int32_t *l_1598 = &l_1039;
        int32_t *l_1599 = &l_1091;
        int32_t *l_1600 = &l_938;
        int32_t *l_1601 = &l_1100;
        int32_t *l_1602 = &l_992;
        int32_t *l_1603 = &l_1091;
        int32_t *l_1604 = (void*)0;
        int32_t *l_1605 = &l_938;
        int32_t *l_1606 = &l_1100;
        int32_t *l_1607 = &l_944;
        int32_t *l_1608 = &g_62;
        int32_t *l_1609 = &l_1099;
        int32_t *l_1610 = &l_992;
        int32_t *l_1611 = (void*)0;
        int32_t *l_1612 = &l_938;
        int32_t *l_1613 = (void*)0;
        int32_t *l_1614 = &l_1042;
        int32_t *l_1615 = (void*)0;
        int32_t *l_1616 = (void*)0;
        int32_t *l_1617 = (void*)0;
        int32_t *l_1618 = &l_1099;
        int32_t *l_1619 = (void*)0;
        int32_t *l_1620 = &l_1016;
        int32_t *l_1621 = &l_918;
        int32_t *l_1622 = &l_922;
        int32_t *l_1623 = &l_997;
        int32_t *l_1624 = &l_944;
        int32_t *l_1625 = (void*)0;
        int32_t *l_1626 = &l_997;
        int32_t *l_1627 = &l_1100;
        int32_t *l_1628 = &l_1136;
        int32_t *l_1649 = &l_944;
        int32_t *l_1650 = &l_1099;
        int32_t *l_1651 = (void*)0;
        int32_t *l_1652 = &l_968;
        int32_t *l_1653 = &l_997;
        int32_t *l_1654 = &l_1140;
        int32_t *l_1655 = &l_1100;
        int32_t *l_1656 = &l_1099;
        int32_t *l_1657 = &l_1015;
        int32_t *l_1658 = &l_1090;
        int32_t *l_1659 = &l_1090;
        int32_t *l_1660 = &g_62;
        int32_t *l_1661 = (void*)0;
        int32_t *l_1662 = &l_1003;
        int32_t *l_1663 = &l_1100;
        int32_t *l_1664 = &l_1042;
        int32_t *l_1665 = &l_1140;
        int32_t *l_1666 = &l_859;
        int32_t *l_1667 = &l_968;
        int32_t *l_1668 = &l_1016;
        int8_t l_1669 = 1L;
        int32_t *l_1670 = &l_938;
        int32_t *l_1671 = (void*)0;
        int32_t *l_1672 = (void*)0;
        int32_t *l_1673 = &l_1105;
        int32_t *l_1674 = &l_938;
        int32_t *l_1675 = &l_958;
        int32_t *l_1676 = &l_922;
        int32_t *l_1677 = (void*)0;
        int32_t *l_1678 = &l_1042;
        int32_t *l_1679 = &l_1091;
        int32_t *l_1680 = &l_1105;
        int32_t *l_1681 = &l_1099;
        int32_t *l_1682 = &l_997;
        int32_t *l_1683 = &l_1058;
        int32_t *l_1684 = &l_1099;
        int32_t *l_1685 = &g_62;
        int32_t *l_1686 = &l_859;
        int32_t *l_1687 = &l_908;
        int32_t *l_1688 = (void*)0;
        int32_t *l_1689 = &l_1091;
        int32_t *l_1690 = &l_859;
        int32_t *l_1691 = &l_1136;
        int32_t *l_1692 = &l_1003;
        int32_t *l_1693 = &l_958;
        int32_t *l_1694 = &l_1105;
        int32_t *l_1695 = &l_938;
        int32_t *l_1696 = &l_1099;
        int32_t *l_1697 = &l_1016;
        int32_t *l_1698 = &l_1136;
        int32_t *l_1699 = &l_1090;
        int32_t *l_1700 = &l_1015;
        int32_t *l_1701 = &l_922;
        int32_t *l_1702 = &l_1090;
        int32_t *l_1703 = &l_1016;
        int32_t *l_1704 = (void*)0;
        int32_t *l_1705 = &l_1016;
        int32_t *l_1706 = (void*)0;
        int32_t *l_1707 = &l_958;
        int32_t *l_1708 = &l_992;
        if (((((**l_709) != ((*p_46) , (g_80.f2 , (safe_rshift_func_uint16_t_u_s(0x8E1FL, 3))))) & (safe_rshift_func_int16_t_s_s(((p_45 != (l_714 , g_16)) < ((safe_add_func_int32_t_s_s(((l_714 & (safe_add_func_uint64_t_u_u((((void*)0 != l_719) & (*l_719)), (*l_719)))) , 0x39589938L), (*g_116))) > 18446744073709551615UL)), (*l_719)))) < (*p_46)))
        {
            int32_t l_732 = 0xBD0EFFEFL;
            uint32_t l_737 = 0x3D1E3544L;
            int32_t ***l_745 = &g_132;
            uint8_t l_872 = 0UL;
            uint32_t l_882 = 0x3A95681EL;
            int32_t *l_885 = &l_859;
            int32_t *l_886 = &g_62;
            int32_t *l_887 = &l_732;
            int32_t *l_888 = &l_732;
            int32_t *l_889 = &l_732;
            int32_t *l_890 = &l_732;
            int32_t *l_891 = &l_732;
            int32_t *l_892 = (void*)0;
            int32_t *l_893 = &l_859;
            int32_t *l_894 = &l_859;
            int32_t *l_895 = (void*)0;
            int32_t *l_896 = (void*)0;
            int32_t *l_897 = &g_62;
            int32_t *l_898 = &g_62;
            int32_t *l_899 = &l_859;
            int32_t *l_900 = (void*)0;
            int32_t *l_901 = &g_62;
            int32_t *l_902 = (void*)0;
            int32_t *l_903 = &l_732;
            int32_t *l_904 = &l_732;
            int32_t *l_905 = &g_62;
            int32_t *l_906 = &l_859;
            int32_t *l_907 = &g_62;
            int32_t *l_909 = &l_908;
            int32_t *l_910 = &l_908;
            int32_t *l_911 = &g_62;
            int32_t *l_912 = &g_62;
            int32_t *l_913 = &l_859;
            int32_t *l_914 = &g_62;
            int32_t *l_915 = &g_62;
            int32_t *l_916 = &l_732;
            int32_t *l_917 = &l_859;
            int32_t *l_919 = &l_859;
            int32_t *l_920 = &g_62;
            int32_t *l_921 = &l_859;
            int32_t *l_923 = &l_908;
            int32_t *l_924 = &l_922;
            int32_t *l_925 = &l_918;
            int32_t *l_926 = &l_908;
            int32_t *l_927 = &l_859;
            int32_t *l_928 = &l_859;
            int32_t *l_929 = &l_908;
            int32_t *l_930 = &l_918;
            int32_t *l_931 = &l_859;
            int32_t *l_932 = &l_918;
            int32_t *l_933 = (void*)0;
            int32_t *l_934 = &g_62;
            int32_t *l_935 = &l_918;
            int32_t *l_936 = &l_922;
            int32_t *l_937 = &l_859;
            int32_t *l_939 = &l_918;
            int32_t *l_940 = &g_62;
            int32_t *l_941 = &l_908;
            int32_t *l_942 = (void*)0;
            int32_t *l_943 = &l_918;
            int32_t *l_945 = &l_918;
            int32_t *l_946 = &l_918;
            int32_t *l_947 = &l_922;
            int32_t *l_948 = (void*)0;
            int32_t *l_949 = &l_908;
            int32_t *l_950 = &l_732;
            int32_t *l_951 = (void*)0;
            int32_t *l_952 = &l_732;
            int32_t *l_953 = &l_859;
            int32_t *l_954 = &l_938;
            int32_t *l_955 = &l_732;
            int32_t *l_956 = &l_918;
            int32_t *l_957 = &l_918;
            int32_t *l_959 = &g_62;
            int32_t *l_960 = &l_922;
            int32_t *l_961 = &l_922;
            int32_t *l_962 = (void*)0;
            int32_t *l_963 = &l_938;
            int32_t l_964 = 0x130E3D8EL;
            int32_t *l_965 = &g_62;
            int32_t *l_966 = &l_964;
            int32_t *l_967 = &l_922;
            int32_t *l_969 = &l_908;
            int32_t *l_970 = (void*)0;
            int32_t *l_971 = (void*)0;
            int32_t *l_972 = &l_918;
            int32_t *l_973 = &l_732;
            int32_t *l_974 = &l_964;
            int32_t *l_975 = (void*)0;
            int32_t *l_976 = &l_922;
            int32_t *l_977 = &l_922;
            int32_t *l_978 = &l_958;
            int32_t *l_979 = &l_968;
            int32_t *l_980 = (void*)0;
            int32_t *l_981 = &l_908;
            int32_t *l_982 = (void*)0;
            int32_t *l_983 = &l_958;
            int32_t *l_984 = &l_938;
            int32_t *l_985 = (void*)0;
            int32_t *l_986 = &l_938;
            int32_t *l_987 = &g_62;
            int32_t *l_988 = &l_918;
            int32_t *l_989 = &g_62;
            int32_t *l_990 = &l_908;
            int32_t l_991 = 0L;
            int32_t *l_993 = &l_922;
            int32_t *l_994 = &l_968;
            int32_t *l_995 = &g_62;
            int32_t *l_996 = (void*)0;
            int32_t *l_998 = &l_968;
            int32_t *l_999 = &l_944;
            int32_t *l_1000 = &l_997;
            int32_t *l_1001 = &l_732;
            int32_t *l_1002 = &l_991;
            int32_t *l_1004 = &l_922;
            int32_t *l_1005 = &l_732;
            int32_t *l_1006 = &l_944;
            int32_t *l_1007 = &l_908;
            int32_t *l_1008 = &l_918;
            int32_t *l_1009 = &l_964;
            int32_t *l_1010 = &l_944;
            int32_t *l_1011 = &l_968;
            int32_t *l_1012 = &l_1003;
            int32_t *l_1013 = &l_732;
            int32_t *l_1014 = &l_958;
            int32_t *l_1017 = (void*)0;
            int32_t *l_1018 = &l_908;
            int32_t *l_1019 = &l_991;
            int32_t *l_1020 = (void*)0;
            int32_t *l_1021 = &l_1016;
            int32_t *l_1022 = &l_922;
            int32_t *l_1023 = &l_944;
            int32_t *l_1024 = &l_997;
            int32_t *l_1025 = &l_1003;
            int32_t *l_1026 = (void*)0;
            int32_t *l_1027 = (void*)0;
            int32_t *l_1028 = (void*)0;
            int32_t *l_1029 = &l_991;
            int32_t *l_1030 = &l_964;
            int32_t *l_1031 = (void*)0;
            int32_t *l_1032 = &l_1003;
            int32_t *l_1033 = (void*)0;
            int32_t *l_1034 = &l_944;
            int32_t *l_1035 = (void*)0;
            int32_t *l_1036 = &l_732;
            int32_t l_1037 = 1L;
            int32_t l_1038 = 0xBE661460L;
            int32_t *l_1040 = (void*)0;
            int32_t *l_1041 = &l_908;
            int32_t *l_1043 = &l_859;
            int32_t *l_1044 = (void*)0;
            int32_t *l_1045 = (void*)0;
            int32_t *l_1046 = (void*)0;
            int32_t *l_1047 = &l_918;
            int32_t *l_1048 = &l_1015;
            int32_t *l_1049 = &l_908;
            int32_t *l_1050 = (void*)0;
            int32_t *l_1051 = (void*)0;
            int32_t l_1052 = 0xC7B271EBL;
            int32_t *l_1053 = &l_1038;
            int32_t *l_1054 = &l_1016;
            int32_t *l_1055 = &l_1042;
            int32_t *l_1056 = &l_958;
            int32_t *l_1057 = &l_1042;
            int32_t *l_1059 = &l_1037;
            int32_t *l_1060 = &l_1037;
            int32_t *l_1061 = &l_918;
            int32_t *l_1062 = &l_1015;
            int32_t *l_1063 = (void*)0;
            int32_t *l_1064 = &g_62;
            int32_t *l_1065 = &l_1042;
            int32_t *l_1066 = (void*)0;
            int32_t *l_1067 = &l_1039;
            int32_t *l_1068 = &l_1003;
            int32_t *l_1069 = &l_1058;
            int32_t *l_1070 = (void*)0;
            int32_t *l_1071 = &l_908;
            int32_t *l_1072 = &l_968;
            int32_t *l_1073 = (void*)0;
            int32_t *l_1074 = &l_944;
            int32_t *l_1075 = &l_1058;
            int32_t *l_1076 = &l_964;
            int32_t *l_1077 = &l_997;
            int32_t *l_1078 = &l_1052;
            int32_t *l_1079 = &l_1042;
            int32_t *l_1080 = &l_997;
            int32_t *l_1081 = &l_1003;
            int32_t *l_1082 = &l_1016;
            int32_t *l_1083 = &l_938;
            int32_t *l_1084 = &l_968;
            int32_t *l_1085 = &l_1015;
            int32_t *l_1086 = &l_1015;
            int32_t *l_1087 = &l_908;
            int32_t *l_1088 = &l_992;
            int32_t *l_1089 = &l_1052;
            int32_t *l_1092 = (void*)0;
            int32_t *l_1093 = &l_991;
            int32_t *l_1094 = &l_1091;
            int32_t *l_1095 = &l_732;
            int32_t *l_1096 = &l_732;
            int32_t *l_1097 = &g_62;
            int32_t *l_1098 = (void*)0;
            int32_t *l_1101 = &l_732;
            int32_t *l_1102 = &l_732;
            int32_t *l_1103 = (void*)0;
            int32_t *l_1104 = (void*)0;
            int32_t *l_1106 = &l_1100;
            int32_t *l_1107 = &l_938;
            int32_t *l_1108 = &l_1015;
            int32_t *l_1109 = (void*)0;
            int32_t *l_1110 = &l_1037;
            int32_t *l_1111 = &l_1038;
            int32_t *l_1112 = &l_968;
            int32_t *l_1113 = (void*)0;
            int32_t *l_1114 = (void*)0;
            int32_t *l_1115 = (void*)0;
            int32_t *l_1116 = &l_1052;
            int32_t *l_1117 = (void*)0;
            int32_t *l_1118 = &l_1016;
            int32_t *l_1120 = (void*)0;
            int32_t *l_1121 = &l_859;
            int32_t l_1122 = 0L;
            int32_t *l_1123 = &l_908;
            int32_t *l_1124 = (void*)0;
            int32_t l_1125 = (-1L);
            int32_t *l_1126 = &l_1039;
            int32_t *l_1127 = &l_918;
            int32_t *l_1128 = &l_1125;
            int32_t *l_1129 = &l_1038;
            int32_t *l_1130 = &l_958;
            int32_t *l_1131 = &l_1125;
            int32_t *l_1132 = &l_1058;
            int32_t *l_1133 = &l_1015;
            int32_t *l_1134 = (void*)0;
            int32_t *l_1135 = &l_958;
            int32_t *l_1137 = &l_908;
            int32_t *l_1138 = (void*)0;
            int32_t *l_1139 = (void*)0;
            int32_t *l_1141 = &l_991;
            int32_t *l_1142 = (void*)0;
            int32_t *l_1143 = &g_62;
            int32_t *l_1144 = &l_732;
            int32_t *l_1145 = &l_1105;
            int32_t *l_1146 = &l_1122;
            int32_t *l_1147 = &l_992;
            p_46 = func_49((safe_lshift_func_uint16_t_u_u(p_44, 7)), p_46, p_44, func_49((((safe_mul_func_uint16_t_u_u(((safe_add_func_int8_t_s_s((*l_719), (((safe_add_func_uint32_t_u_u((p_44 == ((((*l_719) > (safe_sub_func_int16_t_s_s(l_732, p_45))) ^ (safe_sub_func_int8_t_s_s((safe_mod_func_uint16_t_u_u(g_126.f2, g_266)), g_266))) >= g_62)), l_737)) || g_59.f4) ^ 1L))) >= 0xF7L), 0x80F5L)) == (*l_719)) < 5L), p_46, p_45, p_46));
            if (((safe_lshift_func_int16_t_s_u(g_80.f1, 2)) >= (safe_add_func_int64_t_s_s((((safe_add_func_int16_t_s_s((l_744 == (void*)0), g_59.f4)) , ((g_59.f4 <= (l_745 != (void*)0)) | (~(safe_add_func_int16_t_s_s(((safe_sub_func_int32_t_s_s((1L <= (safe_mod_func_uint8_t_u_u(((void*)0 != p_46), l_732))), (*g_116))) , (***l_744)), p_44))))) == 0x3D0AA9BFA86D853BLL), g_125.f2))))
            {
                (***l_744) |= (*p_46);
            }
            else
            {
                int32_t ** const *l_754 = &g_132;
                int32_t **l_781 = &g_116;
                int32_t l_879 = 0L;
                if (((g_266 , l_745) == (g_753 , l_754)))
                {
                    uint8_t l_755 = 255UL;
                    const int32_t l_778 = 0xF909DA0BL;
                    (*g_116) |= (l_755 != (safe_sub_func_uint32_t_u_u((safe_mod_func_int64_t_s_s((((((safe_unary_minus_func_int32_t_s((safe_mod_func_uint32_t_u_u(p_44, ((g_763 , ((safe_rshift_func_int16_t_s_s((safe_mod_func_int64_t_s_s(g_313.f1, (((l_755 <= p_45) || (((safe_unary_minus_func_int8_t_s((safe_add_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_u((*l_719), 3)) == (((((g_59.f4 , (safe_sub_func_int32_t_s_s((((g_266 ^ g_125.f0) , &p_46) == &p_46), l_777))) & 1UL) , p_44) < g_125.f1) != g_566)), 1UL)))) >= g_125.f2) >= l_778)) | g_125.f2))), 12)) | 0xDA94L)) && 0xC51CL))))) && 0x92L) , p_45) | g_25) || (-1L)), p_44)), g_566)));
                    for (l_755 = 0; (l_755 < 36); l_755 = safe_add_func_int32_t_s_s(l_755, 4))
                    {
                        int32_t *l_791 = &g_25;
                        (*l_704) = l_781;

                        ((g_132 == &g_116) ? (void) (0) : __assert_fail ("g_132 == &g_116", "t.c", 1494, __PRETTY_FUNCTION__));
                        if ((*p_46))
                            continue;
                        (**l_704) = func_49(p_45, (p_44 , func_49(((safe_lshift_func_uint8_t_u_s(((safe_lshift_func_uint16_t_u_u(((**l_781) <= (safe_rshift_func_uint16_t_u_s((safe_unary_minus_func_int8_t_s((((!(~(p_44 && p_44))) , l_791) == ((**l_781) , (g_792 , (g_793 , (void*)0)))))), (***l_704)))), 6)) & g_566), g_566)) , p_45), (**l_744), g_25, (*g_132))), g_566, &g_25);
                    }

                    ((g_116 == &g_62 || g_116 == &g_25) ? (void) (0) : __assert_fail ("g_116 == &g_62 || g_116 == &g_25", "t.c", 1500, __PRETTY_FUNCTION__));
                }
                else
                {
                    volatile struct S1 *l_795 = &g_313;
                    const uint32_t l_802 = 18446744073709551615UL;
                    (*l_795) = g_794;
                    for (g_125.f2 = 0; (g_125.f2 > 16); g_125.f2 = safe_add_func_uint16_t_u_u(g_125.f2, 2))
                    {
                        uint8_t l_806 = 0xCAL;
                        (**l_709) = ((safe_mod_func_uint64_t_u_u(((safe_lshift_func_uint16_t_u_u(l_802, 15)) , 0x5F2D07F39E332341LL), (g_803 , ((g_804 , (((0xEAF6CD11842243E4LL < g_80.f0) != (g_125.f1 <= ((((*p_46) , ((safe_unary_minus_func_uint8_t_u(l_806)) ^ p_44)) == (*p_46)) & 0x35A51F451565E2D1LL))) || (*l_719))) & p_45)))) ^ (**l_781));
                        (***l_744) |= l_807;
                    }
                    if ((safe_mod_func_int64_t_s_s((248UL <= (((g_59.f0 != ((((safe_mul_func_int8_t_s_s(((((safe_add_func_int32_t_s_s((!(((l_802 != (safe_mod_func_int64_t_s_s((&g_116 != &g_116), (**l_781)))) , p_46) != (**l_744))), ((0L < p_44) != g_266))) >= g_125.f1) < g_62) > 2L), g_687)) != 0x71FC6B62847544DCLL) , g_25) | l_802)) , (void*)0) != p_46)), p_44)))
                    {

{
        uint32_t l_695 = 0x2763AF55L;
        const int32_t ** const l_700 = (void*)0;
        l_695++;
        (*l_1120) = ((safe_sub_func_uint8_t_u_u((l_700 != (&l_1025)), 0x43L)) != 0xE5974A446EADA6B6LL);
    }


return g_126.f4;
                    }
                    else
                    {
                        int32_t l_817 = 0xE6CD8062L;
                        (***l_744) = l_817;
                        (**l_709) = (((p_46 == p_46) < g_792.f4) > (g_803.f4 || (**l_709)));
                    }
                    (*l_795) = g_818;
                }

                ((g_116 == &g_62 || g_116 == &g_25) ? (void) (0) : __assert_fail ("g_116 == &g_62 || g_116 == &g_25", "t.c", 1535, __PRETTY_FUNCTION__));
                if (((safe_mul_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u((safe_mod_func_int8_t_s_s((p_46 != (void*)0), (safe_sub_func_uint32_t_u_u((safe_rshift_func_int16_t_s_s(0xBD78L, g_763.f0)), ((((safe_lshift_func_int8_t_s_s((g_804.f4 , (((((safe_sub_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u((18446744073709551613UL > (safe_add_func_int32_t_s_s((((18446744073709551614UL != (safe_mul_func_int8_t_s_s(0x96L, (+(((((safe_add_func_uint32_t_u_u((0x6825FD7FL >= 3UL), g_818.f1)) && g_125.f1) & (**l_781)) <= g_125.f2) <= (**l_709)))))) <= g_125.f2) && 0x7AA7L), p_44))), g_59.f4)), p_45)) > 0x9BE0B728D810C863LL) >= g_803.f4) && (*p_46)) && p_44)), p_44)) || g_818.f0) < g_818.f1) && p_45))))), 2)), g_125.f2)) != p_45))
                {
                    (*l_709) = (**l_744);
                }
                else
                {
                    int64_t l_858 = 0xE18F937B05189CCALL;
                    int32_t l_873 = (-5L);
                    int32_t *l_874 = (void*)0;
                    int32_t *l_875 = (void*)0;
                    int32_t *l_876 = &g_62;
                    int32_t *l_877 = &l_873;
                    int32_t *l_878 = &l_732;
                    int32_t *l_880 = &l_879;
                    int32_t *l_881 = (void*)0;

{
        struct S0 **l_4142 = (void*)0;
        struct S0 **l_4143 = (void*)0;
        struct S0 **l_4144 = &g_1529;
        (*l_4144) = ((*l_1439) , &(*l_1439));

        ((g_1529 == &(*l_1439)) ? (void) (0) : __assert_fail ("g_1529 == &(*l_1439)", "t.c", 1558, __PRETTY_FUNCTION__));
    }


for (g_62 = (-25); (g_62 >= (-28)); g_62 = safe_sub_func_uint8_t_u_u(g_62, 1))
                    {
                        int32_t l_846 = 0x807DE2D6L;
                        l_859 |= (((**l_781) , (((safe_mul_func_int16_t_s_s((l_846 , (g_847 , (safe_add_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_s((((g_753 , ((g_804.f2 < p_44) | (safe_lshift_func_int8_t_s_s(((0UL ^ ((p_44 , ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u(l_846, 14)), g_125.f0)) && g_818.f2)) == g_818.f0)) , g_125.f2), 1)))) == g_566) != (**l_781)), 1)) != l_858), l_846)))), (***l_744))) || g_753.f5) , (void*)0)) != (void*)0);
                    }
                    l_872 ^= ((+p_44) | ((((0x3E61D54BL || (((((safe_mod_func_uint64_t_u_u(((safe_unary_minus_func_int8_t_s((safe_sub_func_uint64_t_u_u(((((safe_lshift_func_uint8_t_u_s((~g_793.f2), 7)) <= ((g_266 >= ((safe_rshift_func_int8_t_s_s(((!0L) >= (p_44 , ((g_818.f2 >= (l_858 , (g_62 | p_44))) == g_25))), (**l_781))) , g_125.f0)) , 0x508EL)) >= g_818.f0) , p_45), 0x81D241AFD9003B1ELL)))) & (-1L)), g_125.f0)) && 0xB8A79502D20560BFLL) != g_16) == g_266) , (*p_46))) ^ p_45) > g_818.f2) , 1UL));

{
                (***l_745) |= (*l_2178);
            }


--l_882;
                }
                p_46 = (**l_744);

                ((p_46 == &g_62 || p_46 == &g_25) ? (void) (0) : __assert_fail ("p_46 == &g_62 || p_46 == &g_25", "t.c", 1578, __PRETTY_FUNCTION__));
            }

            ((g_116 == &g_62 || g_116 == &g_25) ? (void) (0) : __assert_fail ("g_116 == &g_62 || g_116 == &g_25", "t.c", 1581, __PRETTY_FUNCTION__));
            ((p_46 == &g_62 || p_46 == &g_25) ? (void) (0) : __assert_fail ("p_46 == &g_62 || p_46 == &g_25", "t.c", 1582, __PRETTY_FUNCTION__));
            l_1148--;
        }
        else
        {
            int32_t ***l_1159 = &l_709;
            int32_t l_1228 = 1L;
            int32_t l_1326 = 0x9093B55CL;
            int32_t l_1334 = 3L;
            int32_t l_1373 = 0xC929F91BL;
            int32_t l_1391 = 0xBD011F0EL;
            int32_t l_1394 = 0x73D8B77DL;
            struct S0 *l_1440 = &g_1441;
            int16_t l_1500 = 0L;
            uint16_t l_1507 = 0x6561L;
            for (l_1148 = 0; (l_1148 >= 41); l_1148 = safe_add_func_int64_t_s_s(l_1148, 1))
            {
                uint16_t l_1164 = 0x973CL;
                int32_t l_1190 = 0x90A048EEL;
            }
            for (l_1100 = 13; (l_1100 == (-30)); --l_1100)
            {
                const int32_t **l_1206 = (void*)0;
                const int32_t ***l_1205 = &l_1206;
                int32_t *l_1236 = &l_1016;
                struct S1 *l_1239 = (void*)0;
                int32_t l_1271 = 0x45209252L;
                int32_t l_1342 = 0x0EF6F63AL;
                int32_t l_1353 = 1L;
                int32_t l_1364 = 1L;
                int32_t l_1403 = 1L;
            }

{
                        return g_753.f4;
                    }


l_1440 = l_1439;

            ((l_1440 == &g_804) ? (void) (0) : __assert_fail ("l_1440 == &g_804", "t.c", 1622, __PRETTY_FUNCTION__));
            for (g_266 = 0; (g_266 < 42); ++g_266)
            {
                struct S1 * const l_1451 = &g_125;
                int32_t l_1477 = 0L;
                int32_t ***l_1486 = &g_132;
                int32_t *l_1488 = &l_944;
                int64_t l_1505 = 4L;
                if ((safe_rshift_func_int16_t_s_s(((9L == (safe_mod_func_int64_t_s_s((safe_rshift_func_uint16_t_u_u((l_1450 == l_1451), 11)), (safe_add_func_int8_t_s_s(((safe_mod_func_uint32_t_u_u((safe_add_func_int64_t_s_s((safe_add_func_uint64_t_u_u((safe_lshift_func_uint16_t_u_s((((safe_rshift_func_int16_t_s_s((((((*l_1451) , (-2L)) != (safe_lshift_func_int8_t_s_u(((safe_mul_func_uint16_t_u_u(p_45, (safe_add_func_int16_t_s_s(((safe_mod_func_int16_t_s_s(g_1202.f2, ((*l_719) | (safe_lshift_func_uint8_t_u_s((safe_add_func_int8_t_s_s(g_1441.f4, 0xDEL)), p_44))))) != l_1476), g_62)))) , l_1477), p_45))) && g_1478) < 1UL), g_1163.f1)) >= p_45) > 0xD3L), p_45)), 0x9887306885633D2CLL)), p_44)), (*p_46))) & g_1163.f1), 0xB9L))))) > p_44), 8)))
                {
                    const struct S1 *l_1485 = &g_818;
                    int32_t l_1487 = (-1L);
                    l_1487 &= (safe_mod_func_int32_t_s_s((((void*)0 == &g_132) , (safe_sub_func_uint32_t_u_u((safe_add_func_int16_t_s_s((g_1163.f0 != p_44), (l_1485 == (void*)0))), ((l_1486 == (g_126 , (void*)0)) < 4L)))), 0x2B4CDB77L));
                    l_1477 ^= ((***l_1159) , 0xAB871195L);
                }
                else
                {
                    uint32_t l_1489 = 0x89C79F56L;
                    int32_t *l_1501 = &l_938;
                    int32_t *l_1502 = &l_997;
                    int32_t *l_1503 = &l_938;
                    int32_t l_1504 = (-1L);
                    int32_t *l_1506 = (void*)0;
                    l_1488 = (void*)0;

                    ((l_1488 == 0) ? (void) (0) : __assert_fail ("l_1488 == 0", "t.c", 1647, __PRETTY_FUNCTION__));
                    (*l_1501) &= (0x2F13335EL >= ((((p_45 , (**l_1159)) != p_46) <= l_1489) | (safe_mul_func_int16_t_s_s((safe_add_func_uint32_t_u_u((safe_mod_func_int64_t_s_s(0L, (0xC2C55D5C1C62DEF3LL & (((safe_lshift_func_uint8_t_u_u(0xF0L, 2)) < (safe_sub_func_uint64_t_u_u(((252UL & g_792.f2) != (***l_1159)), l_1500))) | (-10L))))), 0x3B274A78L)), 65535UL))));
                    l_1507++;
                }

                ((l_1488 == 0 || l_1488 == &l_944) ? (void) (0) : __assert_fail ("l_1488 == 0 || l_1488 == &l_944", "t.c", 1652, __PRETTY_FUNCTION__));
            }
        }

        ((g_116 == &g_62 || g_116 == &g_25) ? (void) (0) : __assert_fail ("g_116 == &g_62 || g_116 == &g_25", "t.c", 1656, __PRETTY_FUNCTION__));
        ((p_46 == &g_62 || p_46 == &g_25) ? (void) (0) : __assert_fail ("p_46 == &g_62 || p_46 == &g_25", "t.c", 1657, __PRETTY_FUNCTION__));
        --l_1629;
        (*l_1607) = (safe_lshift_func_int8_t_s_s((-7L), (0x0AL < ((l_1634 && ((safe_mul_func_uint8_t_u_u(((safe_sub_func_int32_t_s_s(((l_1439 != l_1439) != (g_1639 , (safe_mod_func_uint8_t_u_u((p_46 == (void*)0), ((safe_rshift_func_int16_t_s_s(((safe_lshift_func_uint16_t_u_s((safe_mul_func_int8_t_s_s(g_803.f3, p_45)), 7)) < (-2L)), 4)) || p_44))))), (*p_46))) ^ p_44), g_125.f1)) ^ 0UL)) , (*l_1612)))));
        --l_1709;
    }
    else
    {
        int64_t l_1714 = 0x00BF6162B981065DLL;
        int32_t *l_1715 = &l_944;
        int32_t *l_1716 = &l_918;
        int32_t *l_1717 = (void*)0;
        int32_t *l_1718 = &l_908;
        int32_t *l_1719 = &l_922;
        int32_t *l_1720 = (void*)0;
        int32_t *l_1721 = (void*)0;
        int32_t *l_1722 = (void*)0;
        int32_t *l_1723 = &l_1015;
        int32_t *l_1724 = &l_908;
        int32_t *l_1725 = &g_62;
        int32_t *l_1726 = &l_1091;
        int32_t *l_1727 = &l_918;
        int32_t *l_1728 = &g_62;
        int32_t *l_1729 = (void*)0;
        int32_t *l_1730 = &l_908;
        int32_t *l_1731 = (void*)0;
        int32_t *l_1732 = &l_918;
        int32_t *l_1733 = (void*)0;
        int32_t *l_1734 = &l_1039;
        int32_t l_1735 = 0L;
        int32_t *l_1736 = &l_1140;
        int32_t *l_1737 = &l_1091;
        int32_t *l_1738 = &l_1090;
        int32_t *l_1739 = &l_997;
        int32_t *l_1740 = &l_908;
        int32_t *l_1741 = &l_1039;
        int32_t *l_1742 = &l_997;
        int32_t *l_1743 = &l_1100;
        int32_t *l_1744 = &l_1091;
        int32_t *l_1745 = (void*)0;
        int32_t *l_1746 = &l_1015;
        int32_t *l_1747 = &l_1039;
        int32_t *l_1748 = &l_1735;
        int32_t *l_1749 = &l_944;
        int32_t *l_1750 = (void*)0;
        int32_t *l_1751 = &l_1100;
        int32_t *l_1752 = (void*)0;
        int32_t l_1753 = 0x0780CFD1L;
        int32_t *l_1754 = &l_1039;
        int32_t *l_1755 = &l_1016;
        int32_t *l_1756 = (void*)0;
        int32_t *l_1757 = &l_997;
        int32_t *l_1758 = &l_1753;
        int32_t l_1759 = 0L;
        int32_t *l_1760 = (void*)0;
        int32_t *l_1761 = &l_1100;
        int32_t *l_1762 = &l_908;
        int32_t l_1763 = 1L;
        int32_t *l_1764 = (void*)0;
        int32_t *l_1765 = &l_1015;
        int32_t *l_1766 = &l_1099;
        int32_t *l_1767 = &l_958;
        int32_t *l_1768 = (void*)0;
        int32_t *l_1769 = &l_1016;
        int32_t *l_1770 = &l_908;
        int32_t *l_1771 = &l_1140;
        int32_t *l_1772 = (void*)0;
        int32_t *l_1773 = (void*)0;
        int32_t *l_1774 = &l_1039;
        int32_t *l_1775 = &l_944;
        int32_t *l_1776 = &l_908;
        int32_t *l_1777 = &l_1015;
        int32_t *l_1778 = &l_918;
        int32_t *l_1779 = &l_1058;
        int32_t *l_1780 = &l_1753;
        int32_t *l_1781 = &l_1015;
        int32_t *l_1782 = &l_1016;
        int32_t *l_1783 = (void*)0;
        int32_t *l_1784 = &l_1099;
        int32_t l_1785 = (-3L);
        int32_t *l_1786 = &l_918;
        int32_t *l_1787 = &l_997;
        int32_t *l_1788 = (void*)0;
        int32_t *l_1789 = &l_918;
        int32_t *l_1790 = &l_1759;
        int32_t *l_1791 = (void*)0;
        int32_t *l_1792 = &l_958;
        int32_t *l_1793 = &l_944;
        int32_t *l_1794 = (void*)0;
        int32_t *l_1795 = &l_1140;
        int32_t *l_1796 = &l_1039;
        int32_t *l_1797 = &l_918;
        int32_t *l_1798 = &l_922;
        int32_t *l_1799 = &l_1039;
        int32_t *l_1800 = &l_922;
        int32_t *l_1801 = (void*)0;
        int32_t *l_1802 = &l_922;
        int32_t *l_1803 = &l_1785;
        int32_t *l_1804 = &l_1090;
        int32_t *l_1805 = &l_1039;
        int32_t *l_1806 = &l_918;
        int32_t *l_1807 = &l_1090;
        int32_t *l_1808 = (void*)0;
        int32_t *l_1809 = &l_1099;
        int32_t *l_1810 = &g_62;
        int32_t *l_1811 = &l_908;
        int32_t *l_1812 = &l_1015;
        int32_t *l_1813 = &l_1090;
        int32_t *l_1814 = &l_997;
        int32_t *l_1815 = &l_1015;
        int32_t *l_1816 = &l_958;
        int32_t *l_1817 = &l_1753;
        int32_t *l_1818 = &l_1058;
        int32_t *l_1819 = &l_997;
        int32_t *l_1820 = &l_1015;
        int32_t *l_1821 = (void*)0;
        int32_t *l_1822 = (void*)0;
        int32_t *l_1823 = &l_1785;
        int32_t *l_1824 = &l_1753;
        int32_t *l_1825 = &l_922;
        int32_t *l_1826 = &l_1039;
        int32_t *l_1827 = (void*)0;
        int32_t *l_1828 = &l_944;
        int32_t *l_1829 = &l_1039;
        int32_t *l_1830 = &l_1090;
        int32_t *l_1831 = &l_922;
        int32_t l_1832 = 3L;
        int32_t *l_1833 = &l_1091;
        int32_t *l_1834 = (void*)0;
        int32_t l_1835 = 4L;
        int32_t *l_1836 = (void*)0;
        int32_t *l_1837 = &l_1763;
        int32_t *l_1838 = &l_1016;
        int32_t *l_1839 = &l_1753;
        int32_t *l_1840 = &l_1099;
        int32_t *l_1841 = (void*)0;
        int32_t *l_1842 = &l_1140;
        int32_t *l_1843 = &l_1835;
        int32_t *l_1844 = &l_922;
        int32_t *l_1845 = &l_1140;
        int32_t *l_1846 = &l_1785;
        int32_t *l_1847 = &l_1832;
        int32_t *l_1848 = &g_62;
        int32_t *l_1849 = (void*)0;
        int32_t *l_1850 = &l_1835;
        int32_t *l_1851 = &l_1835;
        int32_t *l_1852 = &l_918;
        int32_t *l_1853 = (void*)0;
        int32_t *l_1854 = (void*)0;
        int32_t *l_1855 = &l_1100;
        int32_t *l_1856 = (void*)0;
        int32_t *l_1857 = (void*)0;
        int32_t *l_1858 = &l_1763;
        int32_t *l_1859 = &l_922;
        int32_t *l_1860 = &l_1835;
        int32_t *l_1861 = (void*)0;
        int32_t *l_1862 = &l_908;
        int32_t *l_1863 = &l_1735;
        int32_t *l_1864 = &l_1763;
        int32_t *l_1865 = (void*)0;
        int32_t *l_1866 = &l_1058;
        int32_t *l_1867 = (void*)0;
        int32_t *l_1868 = &l_1091;
        int32_t *l_1869 = &l_1015;
        int32_t *l_1870 = &l_1039;
        int32_t l_1871 = (-1L);
        int32_t *l_1872 = &l_1759;
        int32_t *l_1873 = (void*)0;
        int32_t *l_1874 = &l_1100;
        int32_t *l_1875 = &l_958;
        int32_t *l_1876 = &l_1091;
        int32_t *l_1877 = &l_1099;
        int32_t *l_1878 = &l_1832;
        int32_t *l_1879 = &l_1058;
        int32_t *l_1880 = &l_918;
        int32_t *l_1881 = (void*)0;
        int32_t *l_1882 = &l_1100;
        int32_t *l_1883 = (void*)0;
        int32_t *l_1884 = &l_1871;
        int32_t *l_1885 = (void*)0;
        int32_t *l_1886 = &l_1835;
        int32_t *l_1887 = &l_1759;
        int32_t l_1888 = 0L;
        int32_t *l_1889 = &l_1785;
        int32_t l_1890 = 1L;
        int32_t *l_1891 = &l_1785;
        int32_t *l_1892 = &l_918;
        int32_t *l_1893 = &l_1832;
        int32_t *l_1894 = &l_1058;
        int32_t *l_1895 = (void*)0;
        int32_t *l_1896 = &l_1039;
        int32_t *l_1897 = (void*)0;
        int32_t *l_1898 = &l_1099;
        int32_t *l_1899 = &l_1753;
        int32_t *l_1900 = (void*)0;
        int32_t *l_1901 = &l_1759;
        int32_t *l_1902 = (void*)0;
        int32_t *l_1903 = &l_944;
        int32_t *l_1904 = &l_1888;
        int32_t l_1905 = (-1L);
        int32_t *l_1906 = &g_62;
        int32_t *l_1907 = &g_62;
        int32_t *l_1908 = &l_1763;
        int32_t *l_1909 = &l_1759;
        int32_t *l_1910 = &l_1015;
        int32_t *l_1911 = &l_1091;
        int32_t *l_1912 = &l_918;
        int32_t l_1913 = 0x6AC7B1C7L;
        int32_t *l_1914 = &l_1091;
        int32_t l_1915 = 7L;
        int32_t *l_1916 = &l_944;
        int32_t *l_1917 = &l_1091;
        int32_t *l_1918 = &l_1140;
        int32_t *l_1919 = &l_1058;
        int32_t *l_1920 = &l_1835;
        int32_t *l_1921 = (void*)0;
        int32_t *l_1922 = &l_944;
        int32_t *l_1923 = &l_908;
        int32_t *l_1924 = (void*)0;
        int32_t *l_1925 = &l_1140;
        int32_t *l_1926 = &l_1015;
        int32_t *l_1927 = &l_1753;
        int32_t l_1928 = 8L;
        int32_t *l_1929 = &l_997;
        int32_t l_1930 = 0x610609DDL;
        int32_t *l_1931 = &l_1140;
        int32_t *l_1932 = (void*)0;
        int32_t *l_1933 = &l_944;
        int32_t *l_1934 = &l_958;
        int32_t *l_1935 = &l_997;
        int32_t *l_1936 = &l_1091;
        int32_t l_1937 = 0x4E6E069AL;
        int32_t *l_1938 = &l_1140;
        int32_t *l_1939 = &l_1905;
        int32_t *l_1940 = &l_1785;
        int32_t *l_1941 = (void*)0;
        int32_t *l_1942 = &l_1090;
        int32_t *l_1943 = &l_1905;
        int32_t *l_1944 = &l_1100;
        int32_t *l_1945 = &l_1913;
        int32_t *l_1947 = &l_1015;
        int32_t *l_1948 = &l_1890;
        int32_t *l_1949 = &l_1905;
        int32_t *l_1950 = &l_908;
        int32_t *l_1951 = &l_1835;
        int32_t *l_1952 = &l_1753;
        int32_t *l_1953 = (void*)0;
        int32_t *l_1954 = &l_918;
        int32_t *l_1955 = &l_1930;
        int32_t *l_1956 = &l_1015;
        int32_t *l_1957 = &l_1753;
        int32_t *l_1958 = &l_997;
        int32_t l_1959 = 0xFDBF6524L;
        int32_t *l_1960 = &g_62;
        int32_t *l_1961 = &l_1785;
        int32_t *l_1962 = &l_1890;
        int32_t *l_1963 = &l_1016;
        int32_t *l_1964 = (void*)0;
        int16_t l_1965 = 0x0DB5L;
        int32_t *l_1966 = &l_1930;
        int32_t *l_1967 = &l_1140;
        int32_t *l_1968 = (void*)0;
        int32_t *l_1969 = &l_1871;
        int32_t *l_1970 = &l_997;
        int32_t *l_1971 = &l_1015;
        int32_t *l_1972 = (void*)0;
        int32_t *l_1973 = &l_1140;
        int32_t *l_1974 = &l_1016;
        int32_t *l_1975 = &g_62;
        int32_t l_1976 = 0xE7E92CBAL;
        int32_t *l_1977 = (void*)0;
        int32_t *l_1978 = (void*)0;
        int32_t *l_1979 = &l_1959;
        int32_t *l_1980 = &l_1759;
        int32_t *l_1981 = (void*)0;
        int32_t *l_1982 = &l_997;
        int32_t *l_1983 = &l_1015;
        int32_t *l_1984 = &l_958;
        int32_t *l_1985 = &l_958;
        int32_t *l_1986 = &l_1039;
        int32_t l_1987 = 0x4A8E2263L;
        int32_t *l_1988 = &l_1832;
        int32_t *l_1989 = &l_1871;
        int32_t *l_1990 = &l_922;
        int32_t *l_1991 = &l_1835;
        int32_t l_1992 = 0x92CA7C88L;
        int32_t *l_1993 = (void*)0;
        int32_t *l_1994 = &l_1763;
        int32_t l_1995 = 0x999130F0L;
        int32_t *l_1996 = &l_1763;
        int32_t *l_1997 = (void*)0;
        int32_t *l_1998 = &l_1735;
        int32_t *l_1999 = (void*)0;
        int32_t *l_2000 = &l_1140;
        (**l_709) ^= (safe_sub_func_uint64_t_u_u(g_793.f0, p_45));
        ++l_2001;
    }

    ((g_116 == &g_62 || g_116 == &g_25) ? (void) (0) : __assert_fail ("g_116 == &g_62 || g_116 == &g_25", "t.c", 1954, __PRETTY_FUNCTION__));
    ((p_46 == &g_62 || p_46 == &g_25) ? (void) (0) : __assert_fail ("p_46 == &g_62 || p_46 == &g_25", "t.c", 1955, __PRETTY_FUNCTION__));
    (*l_709) = func_49((safe_add_func_uint64_t_u_u((((!(safe_rshift_func_int8_t_s_s(p_44, ((*g_107) == &p_46)))) > ((safe_mod_func_uint64_t_u_u((l_2011 , l_2012), (safe_add_func_uint64_t_u_u(g_2015, (0xFDL ^ (l_1240 != g_1174)))))) == (**l_709))) ^ p_44), p_44)), (*l_709), p_45, p_46);
    --l_2187;
    return p_45;
}







static uint64_t func_47(int32_t * p_48)
{
    const int8_t l_139 = 9L;
    int32_t l_151 = 0x734CF679L;
    int32_t l_261 = 1L;
    int32_t l_269 = 0xFE7776E9L;
    int32_t l_398 = 0xC168BAD6L;
    int32_t l_403 = 0xBF4FE604L;
    int32_t l_448 = 0xF42D3900L;
    int32_t l_477 = 0x01E43741L;
    int32_t l_488 = 0x8E696D5FL;
    int32_t l_501 = 0L;
    int32_t l_520 = 0L;
    int64_t l_690 = 0xDAE90DB2C35B8B97LL;
    int32_t l_691 = 8L;
    int32_t **l_701 = &g_116;
                      if (( l_691 < 8) )
{

{
                const int32_t **l_1206 = (void*)0;
                const int32_t ***l_1205 = &l_1206;
                int32_t *l_1236 = &l_269;
                struct S1 *l_1239 = (void*)0;
                int32_t l_1271 = 0x45209252L;
                int32_t l_1342 = 0x0EF6F63AL;
                int32_t l_1353 = 1L;
                int32_t l_1364 = 1L;
                int32_t l_1403 = 1L;
            }

}

if (((g_126 , (p_48 == p_48)) >= (*g_116)))
    {
        uint32_t l_128 = 3UL;
        int32_t ***l_130 = (void*)0;
        int32_t l_157 = (-1L);
        int32_t l_171 = 0x574C5A94L;
        int32_t l_237 = 0xC132FBB4L;
        int32_t l_427 = (-1L);
        int32_t l_449 = 1L;
        int32_t l_450 = 0L;
        int32_t l_475 = 0x8116E444L;
        int32_t l_504 = 0x85D6A8D5L;
        if ((+((0UL ^ g_126.f1) , l_128)))
        {
            (*g_116) &= (0xD866L || g_126.f5);
        }
        else
        {
            return l_128;
        }
        (*g_131) = &p_48;

        ((g_132 == &p_48) ? (void) (0) : __assert_fail ("g_132 == &p_48", "t.c", 2022, __PRETTY_FUNCTION__));
        if ((((g_126.f5 == ((safe_rshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_s(((safe_sub_func_int8_t_s_s((((&g_116 == (((*p_48) , (((((l_128 >= l_139) != (*g_116)) != 4UL) < ((safe_mod_func_uint16_t_u_u((0xBC2055579FD63578LL & (l_139 <= l_139)), 0xCC80L)) ^ l_139)) , l_139)) , &p_48)) , 0x6EFADCADL) < (*g_116)), 251UL)) ^ 0x58EBF8EC998684FALL), 1)), g_125.f1)) ^ 0L)) , (void*)0) != p_48))
        {
            int16_t l_142 = 0x2DFFL;
            int32_t l_149 = 0xCD878405L;
            int32_t l_199 = (-4L);
            (*g_116) |= (l_142 & (((void*)0 != &g_132) , (safe_rshift_func_uint16_t_u_s(9UL, ((g_125.f1 != ((safe_unary_minus_func_uint8_t_u(g_59.f2)) && 0x26A6L)) > l_128)))));
            for (g_59.f4 = (-15); (g_59.f4 <= (-26)); g_59.f4 = safe_sub_func_uint16_t_u_u(g_59.f4, 9))
            {
                int32_t *l_148 = &g_62;
                int32_t *l_150 = &g_62;
                int32_t *l_152 = &l_151;
                int32_t l_153 = 0x5EB93CA2L;
                int32_t *l_154 = &l_149;
                int32_t *l_155 = &l_153;
                int32_t *l_156 = &l_149;
                int32_t *l_158 = &l_157;
                int32_t *l_159 = &l_153;
                int32_t *l_160 = (void*)0;
                int32_t *l_161 = &l_151;
                int32_t *l_162 = (void*)0;
                int32_t *l_163 = &l_151;
                int32_t *l_164 = &l_151;
                int32_t *l_165 = (void*)0;
                int32_t *l_166 = &l_153;
                int32_t l_167 = (-1L);
                int32_t *l_168 = &g_62;
                int32_t *l_169 = (void*)0;
                int32_t *l_170 = &l_151;
                int32_t *l_172 = (void*)0;
                int32_t *l_173 = (void*)0;
                int32_t *l_174 = &l_149;
                int32_t *l_175 = &l_157;
                int32_t *l_176 = &l_151;
                int32_t *l_177 = &l_153;
                int32_t *l_178 = &l_167;
                int32_t *l_179 = (void*)0;
                int32_t *l_180 = &g_62;
                int32_t *l_181 = &l_151;
                int32_t *l_182 = (void*)0;
                int32_t *l_183 = (void*)0;
                int32_t *l_184 = &l_151;
                int32_t *l_185 = (void*)0;
                int32_t *l_186 = (void*)0;
                int32_t *l_187 = &l_151;
                int32_t *l_188 = &l_151;
                int32_t *l_189 = &l_151;
                int32_t *l_190 = &g_62;
                int32_t *l_191 = &l_149;
                int32_t *l_192 = &l_171;
                int32_t *l_193 = &l_167;
                int32_t *l_194 = &l_167;
                int32_t *l_195 = &l_153;
                int32_t *l_196 = &l_157;
                int32_t *l_197 = (void*)0;
                int32_t *l_198 = &l_167;
                int32_t *l_200 = &l_149;
                int32_t *l_201 = &l_157;
                int32_t *l_202 = &l_153;
                int32_t *l_203 = (void*)0;
                int32_t *l_204 = &l_167;
                int32_t *l_205 = &g_62;
                int32_t *l_206 = (void*)0;
                int32_t *l_207 = &l_157;
                int32_t *l_208 = &l_157;
                int32_t *l_209 = &g_62;
                int32_t *l_210 = &l_199;
                int32_t l_211 = 7L;
                int32_t *l_212 = &l_149;
                int32_t *l_213 = &l_171;
                int32_t *l_214 = (void*)0;
                int32_t *l_215 = (void*)0;
                int32_t *l_216 = &l_211;
                int32_t *l_217 = &l_211;
                int32_t *l_218 = &l_171;
                int32_t *l_219 = &l_151;
                int32_t *l_220 = &l_157;
                int32_t *l_221 = &l_151;
                int32_t *l_222 = &l_199;
                int32_t *l_223 = (void*)0;
                int32_t *l_224 = &l_153;
                int32_t *l_225 = &l_149;
                int32_t *l_226 = &l_157;
                int32_t *l_227 = &l_151;
                int32_t l_228 = 0x76412926L;
                int32_t *l_229 = &l_171;
                int32_t *l_230 = &l_157;
                int32_t *l_231 = &l_228;
                int32_t *l_232 = &l_153;
                int32_t *l_233 = &l_151;
                int32_t *l_234 = &l_211;
                int32_t *l_235 = &l_199;
                int32_t *l_236 = &l_157;
                int32_t *l_238 = &l_151;
                int32_t *l_239 = (void*)0;
                int32_t *l_240 = &l_153;
                int32_t l_241 = (-9L);
                int32_t *l_242 = &g_62;
                int32_t *l_243 = &l_237;
                int32_t *l_244 = &l_149;
                int32_t *l_245 = &l_237;
                int32_t *l_246 = &l_151;
                int32_t *l_247 = &g_62;
                int32_t *l_248 = &l_241;
                int32_t *l_249 = (void*)0;
                int32_t *l_250 = (void*)0;
                int32_t *l_251 = &g_62;
                int32_t *l_252 = &l_151;
                int32_t *l_253 = &g_62;
                int32_t *l_254 = &l_228;
                int32_t *l_255 = &l_167;
                int32_t *l_256 = &l_149;
                int32_t *l_257 = &l_149;
                int32_t *l_258 = &l_149;
                int32_t *l_259 = &l_149;
                int32_t *l_260 = &g_62;
                int32_t *l_262 = &l_261;
                int32_t *l_263 = (void*)0;
                int32_t *l_264 = (void*)0;
                int32_t *l_265 = &l_157;
                uint32_t l_270 = 4294967295UL;
                --g_266;
                l_270++;
            }
        }
        else
        {
            uint32_t l_277 = 18446744073709551606UL;
            int32_t l_290 = 6L;
            uint16_t l_295 = 0UL;
            uint64_t l_298 = 18446744073709551615UL;
            int32_t l_404 = 0xDAC667A1L;
            int32_t l_428 = 0xB362DC11L;
            int32_t l_430 = (-4L);
            int32_t l_441 = 0x73A75D4EL;
            int32_t l_453 = 0xD382288BL;
            int32_t l_553 = (-2L);
            int32_t *l_584 = &l_151;
            int32_t *l_585 = &l_403;
            int32_t *l_586 = &l_269;
            int32_t *l_587 = &l_261;
            int32_t *l_588 = &l_448;
            int32_t *l_589 = (void*)0;
            int32_t *l_590 = &l_428;
            int32_t *l_591 = &l_441;
            int32_t *l_592 = &l_520;
            int32_t *l_593 = &l_501;
            int32_t *l_594 = &l_520;
            int32_t *l_595 = &l_488;
            int32_t *l_596 = &l_171;
            int32_t *l_597 = &l_453;
            int32_t *l_598 = &l_430;
            int32_t *l_599 = (void*)0;
            int32_t *l_600 = &l_453;
            int32_t *l_601 = (void*)0;
            int32_t *l_602 = &l_237;
            int32_t *l_603 = &l_398;
            int32_t *l_604 = &g_62;
            int32_t *l_605 = &l_430;
            int32_t *l_606 = &l_237;
            int32_t *l_607 = &l_520;
            int32_t *l_608 = &l_520;
            int32_t *l_609 = &l_430;
            int32_t *l_610 = &l_171;
            int32_t *l_611 = &l_403;
            int32_t *l_612 = &l_520;
            int32_t *l_613 = &l_157;
            int32_t *l_614 = &g_62;
            int32_t *l_615 = (void*)0;
            int32_t *l_616 = &l_504;
            int32_t *l_617 = &l_448;
            int32_t *l_618 = &l_477;
            int32_t *l_619 = &l_171;
            int32_t *l_620 = &l_428;
            int32_t *l_621 = &l_269;
            int32_t *l_622 = &l_404;
            int32_t *l_623 = &l_403;
            int32_t *l_624 = (void*)0;
            int32_t *l_625 = &l_171;
            int32_t *l_626 = (void*)0;
            int32_t *l_627 = &l_553;
            int32_t *l_628 = (void*)0;
            int32_t *l_629 = (void*)0;
            int32_t *l_630 = (void*)0;
            int32_t *l_631 = &l_398;
            int32_t *l_632 = &l_430;
            int32_t *l_633 = &l_403;
            int32_t *l_634 = &g_62;
            int32_t *l_635 = &l_475;
            int32_t *l_636 = &l_171;
            int32_t *l_637 = &l_157;
            int32_t *l_638 = &l_404;
            int32_t *l_639 = (void*)0;
            int32_t *l_640 = &l_237;
            int32_t *l_641 = &l_171;
            int32_t *l_642 = &g_62;
            int32_t *l_643 = &l_427;
            int32_t *l_644 = &l_449;
            int32_t *l_645 = (void*)0;
            int32_t *l_646 = &l_520;
            int32_t *l_647 = &l_157;
            int32_t *l_648 = &l_449;
            int32_t *l_649 = (void*)0;
            int32_t *l_650 = (void*)0;
            int32_t *l_651 = &l_449;
            int32_t *l_652 = &l_403;
            int32_t *l_653 = &l_403;
            int32_t *l_654 = &l_261;
            int32_t *l_655 = &l_398;
            int32_t *l_656 = (void*)0;
            int32_t *l_657 = (void*)0;
            int32_t *l_658 = &l_157;
            int32_t *l_659 = &l_151;
            int32_t *l_660 = &l_441;
            int32_t *l_661 = &l_553;
            int32_t *l_662 = (void*)0;
            int32_t *l_663 = &l_450;
            int32_t *l_664 = &l_453;
            int32_t *l_665 = &l_448;
            int32_t *l_666 = &l_501;
            int32_t *l_667 = &l_157;
            int32_t *l_668 = &l_430;
            int32_t *l_669 = &l_427;
            int32_t *l_670 = (void*)0;
            int32_t *l_671 = &l_504;
            int32_t *l_672 = (void*)0;
            int32_t *l_673 = &l_504;
            int32_t *l_674 = &g_62;
            int32_t *l_675 = &l_520;
            int32_t *l_676 = (void*)0;
            int32_t *l_677 = &l_501;
            int32_t *l_678 = &l_151;
            int32_t *l_679 = &l_520;
            int32_t *l_680 = &g_62;
            int32_t *l_681 = &l_449;
            int32_t *l_682 = &l_504;
            int32_t *l_683 = &l_398;
            int32_t *l_684 = &l_398;
            int32_t *l_685 = (void*)0;
            int32_t *l_686 = &l_269;
            for (l_171 = 0; (l_171 <= (-17)); l_171 = safe_sub_func_int8_t_s_s(l_171, 1))
            {
                int32_t l_293 = (-9L);
                int32_t ***l_294 = &g_132;
                int32_t l_324 = 0L;
                int32_t l_340 = 0xEB9D798BL;
                int32_t l_379 = 0xFF7825D7L;
                int32_t l_484 = 0x5169D787L;
                int32_t l_514 = 0x60D45001L;
                int32_t l_562 = 0x6B93C577L;
                (*g_116) = (safe_mul_func_int8_t_s_s((((g_126.f2 || l_277) & ((safe_rshift_func_int8_t_s_s((((safe_add_func_uint64_t_u_u(((safe_add_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_s((((((safe_add_func_uint8_t_u_u((((safe_add_func_int64_t_s_s(l_290, (g_125.f0 , (safe_rshift_func_int8_t_s_s((l_151 & g_125.f2), (((l_293 | (l_261 , 18446744073709551614UL)) , g_16) > l_293)))))) , l_293) <= l_269), g_125.f2)) <= g_25) , (void*)0) == l_294) , g_62), 7)), (*p_48))) > l_295), (***l_294))) == g_16) && g_59.f4), g_125.f1)) != 4294967292UL)) && g_16), (***l_294)));
                for (l_151 = 11; (l_151 <= (-22)); l_151 = safe_sub_func_uint16_t_u_u(l_151, 3))
                {
                    uint32_t l_316 = 0xC1CD0E78L;
                    int32_t *l_317 = &l_293;
                    int32_t *l_318 = &l_237;
                    int32_t *l_319 = &l_261;
                    int32_t *l_320 = &l_237;
                    int32_t *l_321 = &l_261;
                    int32_t l_322 = 0x4CFDC269L;
                    int32_t *l_323 = &g_62;
                    int32_t *l_325 = &l_322;
                    int32_t *l_326 = (void*)0;
                    int32_t *l_327 = (void*)0;
                    int32_t *l_328 = &l_261;
                    int32_t *l_329 = &l_293;
                    int32_t *l_330 = &l_324;
                    int32_t *l_331 = &l_324;
                    int32_t *l_332 = (void*)0;
                    int32_t *l_333 = (void*)0;
                    int32_t *l_334 = &l_324;
                    int32_t *l_335 = &l_322;
                    int32_t l_336 = (-8L);
                    int32_t *l_337 = &l_324;
                    int32_t *l_338 = &l_261;
                    int32_t *l_339 = (void*)0;
                    int32_t *l_341 = &l_293;
                    int32_t *l_342 = &l_324;
                    int32_t *l_343 = &l_336;
                    int32_t *l_344 = &l_322;
                    int32_t *l_345 = &l_269;
                    int32_t *l_346 = &l_261;
                    int32_t *l_347 = (void*)0;
                    int32_t *l_348 = &l_336;
                    int32_t *l_349 = &l_324;
                    int32_t *l_350 = &l_336;
                    int32_t *l_351 = &l_157;
                    int32_t *l_352 = &l_237;
                    int32_t *l_353 = &l_261;
                    int32_t *l_354 = &l_157;
                    int32_t *l_355 = (void*)0;
                    int32_t *l_356 = (void*)0;
                    int32_t *l_357 = (void*)0;
                    int32_t *l_358 = &l_261;
                    int32_t *l_359 = (void*)0;
                    int32_t *l_360 = &l_237;
                    int32_t *l_361 = (void*)0;
                    int32_t *l_362 = &l_261;
                    int32_t *l_363 = &l_261;
                    int32_t *l_364 = &l_322;
                    int32_t *l_365 = &l_237;
                    int32_t *l_366 = &l_237;
                    int32_t *l_367 = &l_340;
                    int32_t *l_368 = &l_269;
                    int32_t *l_369 = (void*)0;
                    int32_t *l_370 = &l_269;
                    int32_t *l_371 = (void*)0;
                    int32_t *l_372 = &l_261;
                    int32_t *l_373 = &l_237;
                    int32_t *l_374 = &l_269;
                    int32_t *l_375 = &l_336;
                    int32_t *l_376 = &l_322;
                    int32_t *l_377 = (void*)0;
                    int32_t *l_378 = &l_336;
                    int32_t *l_380 = (void*)0;
                    int32_t *l_381 = &l_336;
                    int32_t *l_382 = &l_322;
                    int32_t *l_383 = &l_157;
                    int32_t *l_384 = &l_293;
                    int32_t *l_385 = &l_336;
                    int32_t *l_386 = &l_237;
                    int32_t *l_387 = &l_324;
                    int32_t l_388 = 0xFA146DEBL;
                    int32_t *l_389 = &l_322;
                    int32_t *l_390 = (void*)0;
                    int32_t *l_391 = &l_237;
                    int32_t *l_392 = &l_322;
                    int32_t *l_393 = &l_340;
                    int32_t *l_394 = &l_293;
                    int32_t *l_395 = &l_340;
                    int32_t *l_396 = &l_322;
                    int32_t *l_397 = &l_340;
                    int32_t l_399 = 0x03B29E0AL;
                    int32_t *l_400 = &l_399;
                    int32_t *l_401 = &l_340;
                    int32_t *l_402 = &l_398;
                    int32_t *l_405 = &g_62;
                    int32_t *l_406 = &l_336;
                    int32_t *l_407 = &l_388;
                    int32_t *l_408 = &l_237;
                    int32_t *l_409 = (void*)0;
                    int32_t *l_410 = &l_322;
                    int32_t *l_411 = &l_340;
                    int32_t *l_412 = &l_388;
                    int32_t *l_413 = &l_293;
                    int32_t *l_414 = (void*)0;
                    int32_t *l_415 = &l_336;
                    int32_t *l_416 = &l_398;
                    int32_t *l_417 = &l_269;
                    int32_t *l_418 = &l_157;
                    int32_t l_419 = 0xEA45FBA7L;
                    int32_t *l_420 = (void*)0;
                    int32_t *l_421 = (void*)0;
                    int32_t *l_422 = &l_398;
                    int32_t *l_423 = &l_336;
                    int32_t *l_424 = &l_324;
                    int32_t *l_425 = &l_388;
                    int32_t *l_426 = &l_293;
                    int32_t *l_429 = &l_398;
                    int32_t *l_431 = &l_403;
                    int32_t *l_432 = &l_427;
                    int32_t *l_433 = &l_379;
                    int32_t *l_434 = &l_430;
                    int32_t *l_435 = (void*)0;
                    int32_t *l_436 = &l_388;
                    int32_t *l_437 = (void*)0;
                    int32_t *l_438 = &g_62;
                    int32_t *l_439 = &l_269;
                    int32_t *l_440 = &l_427;
                    int32_t *l_442 = &l_388;
                    int32_t *l_443 = (void*)0;
                    int32_t *l_444 = &l_430;
                    int32_t *l_445 = &l_336;
                    int32_t *l_446 = (void*)0;
                    int32_t *l_447 = (void*)0;
                    int32_t *l_451 = &l_157;
                    int32_t l_452 = 0x2BF08DCBL;
                    int32_t *l_454 = (void*)0;
                    int32_t *l_455 = &l_427;
                    int32_t *l_456 = &l_450;
                    int32_t *l_457 = (void*)0;
                    int32_t *l_458 = (void*)0;
                    int32_t *l_459 = &l_340;
                    int32_t *l_460 = &l_450;
                    int32_t *l_461 = (void*)0;
                    int32_t *l_462 = &l_404;
                    int32_t *l_463 = &l_399;
                    int32_t *l_464 = &l_388;
                    int32_t *l_465 = &l_261;
                    int32_t *l_466 = (void*)0;
                    int32_t *l_467 = &l_419;
                    int32_t *l_468 = &l_427;
                    int32_t *l_469 = &l_449;
                    int32_t *l_470 = &l_261;
                    int32_t *l_471 = &l_419;
                    int32_t *l_472 = &l_324;
                    int32_t *l_473 = &l_293;
                    int32_t *l_474 = &l_450;
                    int32_t *l_476 = &l_419;
                    int32_t *l_478 = (void*)0;
                    int32_t *l_479 = &l_403;
                    int32_t *l_480 = (void*)0;
                    int32_t *l_481 = (void*)0;
                    int32_t *l_482 = &l_269;
                    int32_t *l_483 = (void*)0;
                    int32_t *l_485 = (void*)0;
                    int32_t *l_486 = &l_441;
                    int32_t *l_487 = &l_322;
                    int32_t *l_489 = &l_293;
                    int32_t *l_490 = &l_324;
                    int32_t *l_491 = (void*)0;
                    int32_t *l_492 = (void*)0;
                    int32_t *l_493 = &l_324;
                    int32_t *l_494 = &l_237;
                    int32_t *l_495 = &l_488;
                    int32_t *l_496 = &l_399;
                    int32_t *l_497 = (void*)0;
                    int32_t *l_498 = &g_62;
                    int32_t *l_499 = &l_453;
                    int32_t *l_500 = &l_237;
                    int32_t *l_502 = &l_428;
                    int32_t *l_503 = &l_340;
                    int32_t *l_505 = &l_237;
                    int32_t *l_506 = &l_261;
                    int32_t *l_507 = &l_488;
                    int32_t *l_508 = (void*)0;
                    int32_t *l_509 = (void*)0;
                    int32_t *l_510 = &l_404;
                    int32_t *l_511 = &l_293;
                    int32_t *l_512 = (void*)0;
                    int32_t *l_513 = &l_430;
                    int32_t *l_515 = (void*)0;
                    int32_t *l_516 = &l_261;
                    int32_t *l_517 = (void*)0;
                    int32_t *l_518 = (void*)0;
                    int32_t *l_519 = &g_62;
                    int32_t *l_521 = (void*)0;
                    int32_t *l_522 = &l_452;
                    int32_t *l_523 = &l_450;
                    int32_t *l_524 = &l_322;
                    int32_t *l_525 = (void*)0;
                    int32_t *l_526 = (void*)0;
                    int32_t *l_527 = &l_504;
                    int32_t *l_528 = &l_520;
                    int32_t *l_529 = (void*)0;
                    int32_t *l_530 = (void*)0;
                    int32_t *l_531 = &l_477;
                    int32_t *l_532 = &l_501;
                    int32_t *l_533 = &l_403;
                    int32_t *l_534 = (void*)0;
                    int32_t *l_535 = &l_514;
                    int32_t l_536 = (-6L);
                    int32_t *l_537 = &l_269;
                    int32_t *l_538 = &l_514;
                    int32_t *l_539 = &l_379;
                    int32_t *l_540 = &l_428;
                    int32_t l_541 = 0xEF0DABAFL;
                    int32_t l_542 = 0x05D170DAL;
                    int32_t *l_543 = &l_336;
                    int32_t l_544 = 0x72003204L;
                    int32_t *l_545 = &l_293;
                    int32_t *l_546 = &l_449;
                    int32_t *l_547 = &l_293;
                    int32_t *l_548 = &g_62;
                    int32_t *l_549 = (void*)0;
                    int32_t *l_550 = &l_441;
                    int32_t *l_551 = &l_322;
                    int32_t *l_552 = &l_450;
                    int32_t *l_554 = &l_541;
                    int32_t *l_555 = &l_404;
                    int32_t *l_556 = &l_237;
                    int32_t *l_557 = (void*)0;
                    int32_t *l_558 = &l_430;
                    int32_t *l_559 = &l_501;
                    int32_t *l_560 = &l_427;
                    int32_t *l_561 = (void*)0;
                    int32_t *l_563 = (void*)0;
                    int32_t *l_564 = &l_541;
                    int32_t *l_565 = &l_404;
                    int32_t *l_567 = &l_475;
                    int32_t *l_568 = &l_450;
                    int32_t *l_569 = &l_542;
                    --l_298;
                    (*l_317) |= ((safe_mod_func_uint16_t_u_u((((((((safe_sub_func_int16_t_s_s((safe_mod_func_uint64_t_u_u((4UL && (g_126.f3 && ((g_125.f2 == (safe_mul_func_uint8_t_u_u((***l_294), (safe_rshift_func_uint16_t_u_u(g_125.f1, 14))))) || (safe_rshift_func_int16_t_s_s((((((g_266 , g_313) , ((((safe_add_func_int8_t_s_s(g_80.f3, ((*g_116) & g_16))) > l_316) != l_316) || 0UL)) ^ 65531UL) , (*p_48)) >= (-4L)), g_125.f0))))), g_125.f0)), l_277)) && l_316) , p_48) != (void*)0) && (***l_294)) , 0xCACCE184C6D96F22LL) > (***l_294)), l_316)) && l_261);
                    g_570++;
                }
                (**l_294) = (**g_131);
            }
            (*g_132) = func_49((~(safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s((((((safe_add_func_uint64_t_u_u(((g_59 , (safe_mul_func_uint8_t_u_u((((safe_mul_func_int8_t_s_s(l_520, l_501)) & ((1UL & (((l_441 != l_504) ^ (&l_404 == p_48)) > ((&p_48 != (*g_107)) >= l_428))) | l_269)) || 0x6BEF7124L), l_404))) <= 65528UL), g_62)) > l_139) , (-1L)) , (void*)0) == (*g_132)), 0x5768L)), 6))), &l_441, l_139, l_584);

            ((p_48 == &l_441 || p_48 == &l_151) ? (void) (0) : __assert_fail ("p_48 == &l_441 || p_48 == &l_151", "t.c", 2512, __PRETTY_FUNCTION__));
            g_687++;
            --g_692;
        }


    }
    else
    {
        uint32_t l_695 = 0x2763AF55L;
        const int32_t ** const l_700 = (void*)0;
        l_695++;
        (*g_116) = ((safe_sub_func_uint8_t_u_u((l_700 != l_701), 0x43L)) != 0xE5974A446EADA6B6LL);
    }


    ((g_132 == &g_116 || g_132 == &p_48) ? (void) (0) : __assert_fail ("g_132 == &g_116 || g_132 == &p_48", "t.c", 2528, __PRETTY_FUNCTION__));
    return g_313.f0;


}







static int32_t * func_49(uint8_t p_50, int32_t * p_51, int8_t p_52, int32_t * p_53)
{
    int32_t *l_61 = &g_62;
    int32_t *l_63 = &g_62;
    int32_t *l_64 = &g_62;
    uint32_t l_65 = 8UL;
    int32_t *l_81 = &g_25;
    uint64_t l_87 = 0x9E0FDA63E176CBFBLL;
    int32_t **l_99 = (void*)0;
    int32_t ** const *l_98 = &l_99;
    l_65++;
    if (((((((safe_sub_func_uint64_t_u_u(((((safe_mul_func_int16_t_s_s((((((p_51 != (void*)0) | (safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s((safe_mul_func_int8_t_s_s((g_59.f4 , (((safe_sub_func_uint64_t_u_u(3UL, (((*l_61) , ((((((((((((g_80 , l_81) == (void*)0) , ((safe_mod_func_uint32_t_u_u(((!(safe_mod_func_int8_t_s_s(((((0xF147090205405EA3LL ^ 9L) != g_80.f3) < 0x763FF6366113C509LL) <= 0x45L), g_25))) , 4294967295UL), p_52)) ^ g_25)) <= 0x72B4D3A6L) , 0x42E901CC30F106BFLL) , p_53) != &g_25) < 1UL) | p_52) >= g_62) , g_62) , 0x8398D9B3EEAC61C7LL)) && g_80.f1))) <= 1UL) > (*l_63))), g_16)), 5)), l_87))) && (*l_81)) | g_62) ^ g_62), g_59.f4)) ^ g_25) , (-1L)) == p_50), 0x8C93045D781F8E38LL)) || p_50) > p_50) , (*l_81)) , &g_62) == p_53))
    {
        const int32_t *l_90 = (void*)0;
        const int32_t * const *l_89 = &l_90;
        const int32_t * const **l_88 = &l_89;
        (*l_88) = (void*)0;

        ((l_89 == 0) ? (void) (0) : __assert_fail ("l_89 == 0", "t.c", 2558, __PRETTY_FUNCTION__));
        return p_53;


    }
    else
    {
        uint8_t l_109 = 1UL;
        uint16_t l_121 = 0UL;
        for (p_52 = 6; (p_52 != (-7)); p_52--)
        {
            uint32_t l_97 = 1UL;
            int32_t ***l_100 = &l_99;
            g_80.f0 ^= ((safe_mul_func_int8_t_s_s(p_52, g_62)) && ((safe_lshift_func_int16_t_s_s(((((l_97 , (-8L)) , l_98) == l_100) ^ (p_50 != (safe_sub_func_int64_t_s_s(((safe_mod_func_int64_t_s_s((safe_lshift_func_uint8_t_u_u((p_52 | (((g_107 == &g_108) < (*p_53)) , 0xFAA48CC3AA3D5FEELL)), 0)), p_50)) & 1UL), g_25)))), p_52)) || 1L));
            l_109--;
            g_116 = ((safe_rshift_func_uint16_t_u_s((((safe_lshift_func_int8_t_s_s(0xEAL, 4)) & g_59.f5) >= g_25), 2)) , p_53);


        }


        for (p_50 = (-19); (p_50 == 43); p_50++)
        {
            int64_t l_119 = 0xD52EBB0BE5235086LL;
            int32_t **l_120 = &l_63;
            if ((*p_53))
                break;
            (*l_61) &= l_119;
            (*l_120) = p_53;
            if ((*g_116))
            {
                --l_121;
            }
            else
            {
                int32_t *l_124 = &g_62;
                (*l_120) = l_124;

                ((l_63 == &g_62) ? (void) (0) : __assert_fail ("l_63 == &g_62", "t.c", 2596, __PRETTY_FUNCTION__));
                g_80 = g_125;
                p_51 = p_51;
            }
        }


    }



    g_116 = l_61;

    ((g_116 == &g_62) ? (void) (0) : __assert_fail ("g_116 == &g_62", "t.c", 2609, __PRETTY_FUNCTION__));
    return p_51;


}





int main (void)
{
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
    transparent_crc(g_16, "g_16", print_hash_value);
    transparent_crc(g_25, "g_25", print_hash_value);
    transparent_crc(g_59.f0, "g_59.f0", print_hash_value);
    transparent_crc(g_59.f1, "g_59.f1", print_hash_value);
    transparent_crc(g_59.f2, "g_59.f2", print_hash_value);
    transparent_crc(g_59.f3, "g_59.f3", print_hash_value);
    transparent_crc(g_59.f4, "g_59.f4", print_hash_value);
    transparent_crc(g_59.f5, "g_59.f5", print_hash_value);
    transparent_crc(g_60, "g_60", print_hash_value);
    transparent_crc(g_62, "g_62", print_hash_value);
    transparent_crc(g_80.f0, "g_80.f0", print_hash_value);
    transparent_crc(g_80.f1, "g_80.f1", print_hash_value);
    transparent_crc(g_80.f2, "g_80.f2", print_hash_value);
    transparent_crc(g_80.f3, "g_80.f3", print_hash_value);
    transparent_crc(g_125.f0, "g_125.f0", print_hash_value);
    transparent_crc(g_125.f1, "g_125.f1", print_hash_value);
    transparent_crc(g_125.f2, "g_125.f2", print_hash_value);
    transparent_crc(g_125.f3, "g_125.f3", print_hash_value);
    transparent_crc(g_126.f0, "g_126.f0", print_hash_value);
    transparent_crc(g_126.f1, "g_126.f1", print_hash_value);
    transparent_crc(g_126.f2, "g_126.f2", print_hash_value);
    transparent_crc(g_126.f3, "g_126.f3", print_hash_value);
    transparent_crc(g_126.f4, "g_126.f4", print_hash_value);
    transparent_crc(g_126.f5, "g_126.f5", print_hash_value);
    transparent_crc(g_266, "g_266", print_hash_value);
    transparent_crc(g_313.f0, "g_313.f0", print_hash_value);
    transparent_crc(g_313.f1, "g_313.f1", print_hash_value);
    transparent_crc(g_313.f2, "g_313.f2", print_hash_value);
    transparent_crc(g_313.f3, "g_313.f3", print_hash_value);
    transparent_crc(g_566, "g_566", print_hash_value);
    transparent_crc(g_570, "g_570", print_hash_value);
    transparent_crc(g_687, "g_687", print_hash_value);
    transparent_crc(g_692, "g_692", print_hash_value);
    transparent_crc(g_753.f0, "g_753.f0", print_hash_value);
    transparent_crc(g_753.f1, "g_753.f1", print_hash_value);
    transparent_crc(g_753.f2, "g_753.f2", print_hash_value);
    transparent_crc(g_753.f3, "g_753.f3", print_hash_value);
    transparent_crc(g_753.f4, "g_753.f4", print_hash_value);
    transparent_crc(g_753.f5, "g_753.f5", print_hash_value);
    transparent_crc(g_763.f0, "g_763.f0", print_hash_value);
    transparent_crc(g_763.f1, "g_763.f1", print_hash_value);
    transparent_crc(g_763.f2, "g_763.f2", print_hash_value);
    transparent_crc(g_763.f3, "g_763.f3", print_hash_value);
    transparent_crc(g_763.f4, "g_763.f4", print_hash_value);
    transparent_crc(g_763.f5, "g_763.f5", print_hash_value);
    transparent_crc(g_792.f0, "g_792.f0", print_hash_value);
    transparent_crc(g_792.f1, "g_792.f1", print_hash_value);
    transparent_crc(g_792.f2, "g_792.f2", print_hash_value);
    transparent_crc(g_792.f3, "g_792.f3", print_hash_value);
    transparent_crc(g_792.f4, "g_792.f4", print_hash_value);
    transparent_crc(g_792.f5, "g_792.f5", print_hash_value);
    transparent_crc(g_793.f0, "g_793.f0", print_hash_value);
    transparent_crc(g_793.f1, "g_793.f1", print_hash_value);
    transparent_crc(g_793.f2, "g_793.f2", print_hash_value);
    transparent_crc(g_793.f3, "g_793.f3", print_hash_value);
    transparent_crc(g_794.f0, "g_794.f0", print_hash_value);
    transparent_crc(g_794.f1, "g_794.f1", print_hash_value);
    transparent_crc(g_794.f2, "g_794.f2", print_hash_value);
    transparent_crc(g_794.f3, "g_794.f3", print_hash_value);
    transparent_crc(g_803.f0, "g_803.f0", print_hash_value);
    transparent_crc(g_803.f1, "g_803.f1", print_hash_value);
    transparent_crc(g_803.f2, "g_803.f2", print_hash_value);
    transparent_crc(g_803.f3, "g_803.f3", print_hash_value);
    transparent_crc(g_803.f4, "g_803.f4", print_hash_value);
                      if (( g_60 < -2270085556831825985) )
{

(***(&g_132)) |= (*(&g_62));

}

transparent_crc(g_803.f5, "g_803.f5", print_hash_value);
    transparent_crc(g_804.f0, "g_804.f0", print_hash_value);
    transparent_crc(g_804.f1, "g_804.f1", print_hash_value);
    transparent_crc(g_804.f2, "g_804.f2", print_hash_value);
    transparent_crc(g_804.f3, "g_804.f3", print_hash_value);
    transparent_crc(g_804.f4, "g_804.f4", print_hash_value);
    transparent_crc(g_804.f5, "g_804.f5", print_hash_value);
    transparent_crc(g_818.f0, "g_818.f0", print_hash_value);
    transparent_crc(g_818.f1, "g_818.f1", print_hash_value);
    transparent_crc(g_818.f2, "g_818.f2", print_hash_value);
    transparent_crc(g_818.f3, "g_818.f3", print_hash_value);
    transparent_crc(g_847.f0, "g_847.f0", print_hash_value);
    transparent_crc(g_847.f1, "g_847.f1", print_hash_value);
    transparent_crc(g_847.f2, "g_847.f2", print_hash_value);
    transparent_crc(g_847.f3, "g_847.f3", print_hash_value);
    transparent_crc(g_1163.f0, "g_1163.f0", print_hash_value);
    transparent_crc(g_1163.f1, "g_1163.f1", print_hash_value);
    transparent_crc(g_1163.f2, "g_1163.f2", print_hash_value);
                      if ((g_108 != 0) && (*g_108 != 0) && (**g_108 != 0) && ( **g_108 < 0) )
{

print_hash_value ^= ((***(&g_132)) , 0xAB871195L);

}

transparent_crc(g_1163.f3, "g_1163.f3", print_hash_value);
    transparent_crc(g_1202.f0, "g_1202.f0", print_hash_value);
    transparent_crc(g_1202.f1, "g_1202.f1", print_hash_value);
    transparent_crc(g_1202.f2, "g_1202.f2", print_hash_value);
    transparent_crc(g_1202.f3, "g_1202.f3", print_hash_value);
    transparent_crc(g_1416, "g_1416", print_hash_value);
    transparent_crc(g_1441.f0, "g_1441.f0", print_hash_value);
    transparent_crc(g_1441.f1, "g_1441.f1", print_hash_value);
    transparent_crc(g_1441.f2, "g_1441.f2", print_hash_value);
    transparent_crc(g_1441.f3, "g_1441.f3", print_hash_value);
    transparent_crc(g_1441.f4, "g_1441.f4", print_hash_value);
    transparent_crc(g_1441.f5, "g_1441.f5", print_hash_value);
                      if ((g_3383 != 0) && (*g_3383 != 0) && (**g_3383 != 0) && ( **g_3383 < 0) )
{

(*(&g_2243)) &= (0xD866L || g_753.f5);

}

transparent_crc(g_1478, "g_1478", print_hash_value);
    transparent_crc(g_1530.f0, "g_1530.f0", print_hash_value);
    transparent_crc(g_1530.f1, "g_1530.f1", print_hash_value);
    transparent_crc(g_1530.f2, "g_1530.f2", print_hash_value);
    transparent_crc(g_1530.f3, "g_1530.f3", print_hash_value);
    transparent_crc(g_1530.f4, "g_1530.f4", print_hash_value);
                      if (( g_1648 < -509606375) )
{

for (g_62 = 13; (g_62 == (-30)); --g_62)
            {
                const int32_t **l_1206 = (void*)0;
                const int32_t ***l_1205 = &l_1206;
                int32_t *l_1236 = &(*g_116);
                struct S1 *l_1239 = (void*)0;
                int32_t l_1271 = 0x45209252L;
                int32_t l_1342 = 0x0EF6F63AL;
                int32_t l_1353 = 1L;
                int32_t l_1364 = 1L;
                int32_t l_1403 = 1L;
            };


}

transparent_crc(g_1530.f5, "g_1530.f5", print_hash_value);
    transparent_crc(g_1594.f0, "g_1594.f0", print_hash_value);
    transparent_crc(g_1594.f1, "g_1594.f1", print_hash_value);
    transparent_crc(g_1594.f2, "g_1594.f2", print_hash_value);
    transparent_crc(g_1594.f3, "g_1594.f3", print_hash_value);
    transparent_crc(g_1639.f0, "g_1639.f0", print_hash_value);
    transparent_crc(g_1639.f1, "g_1639.f1", print_hash_value);
    transparent_crc(g_1639.f2, "g_1639.f2", print_hash_value);
    transparent_crc(g_1639.f3, "g_1639.f3", print_hash_value);
    transparent_crc(g_1639.f4, "g_1639.f4", print_hash_value);
    transparent_crc(g_1639.f5, "g_1639.f5", print_hash_value);
    transparent_crc(g_1648, "g_1648", print_hash_value);
    transparent_crc(g_2015, "g_2015", print_hash_value);
    transparent_crc(g_2191.f0, "g_2191.f0", print_hash_value);
    transparent_crc(g_2191.f1, "g_2191.f1", print_hash_value);
    transparent_crc(g_2191.f2, "g_2191.f2", print_hash_value);
    transparent_crc(g_2191.f3, "g_2191.f3", print_hash_value);
    transparent_crc(g_2213.f0, "g_2213.f0", print_hash_value);
    transparent_crc(g_2213.f1, "g_2213.f1", print_hash_value);
    transparent_crc(g_2213.f2, "g_2213.f2", print_hash_value);
    transparent_crc(g_2213.f3, "g_2213.f3", print_hash_value);
    transparent_crc(g_2243, "g_2243", print_hash_value);
                      if ((g_2976 != 0) && (*g_2976 != 0) && (**g_2976 != 0) && ( **g_2976 < 0) )
{

(*(*g_132)) &= (0xD866L || g_126.f5);

}

transparent_crc(g_2309, "g_2309", print_hash_value);
    transparent_crc(g_2321.f0, "g_2321.f0", print_hash_value);
    transparent_crc(g_2321.f1, "g_2321.f1", print_hash_value);
    transparent_crc(g_2321.f2, "g_2321.f2", print_hash_value);
                      if (( g_1478 < 1685984286) )
{

{
                        int32_t l_817 = 0xE6CD8062L;
                        (***(&g_132)) = l_817;
                        (**(&g_116)) = (((g_116 == g_116) < g_763.f4) > (g_4141.f4 || (**(&g_116))));
                    }

}

transparent_crc(g_2321.f3, "g_2321.f3", print_hash_value);
    transparent_crc(g_2321.f4, "g_2321.f4", print_hash_value);
    transparent_crc(g_2321.f5, "g_2321.f5", print_hash_value);
    transparent_crc(g_2325.f0, "g_2325.f0", print_hash_value);
    transparent_crc(g_2325.f1, "g_2325.f1", print_hash_value);
    transparent_crc(g_2325.f2, "g_2325.f2", print_hash_value);
    transparent_crc(g_2325.f3, "g_2325.f3", print_hash_value);
    transparent_crc(g_2326.f0, "g_2326.f0", print_hash_value);
    transparent_crc(g_2326.f1, "g_2326.f1", print_hash_value);
    transparent_crc(g_2326.f2, "g_2326.f2", print_hash_value);
    transparent_crc(g_2326.f3, "g_2326.f3", print_hash_value);
    transparent_crc(g_2347.f0, "g_2347.f0", print_hash_value);
    transparent_crc(g_2347.f1, "g_2347.f1", print_hash_value);
    transparent_crc(g_2347.f2, "g_2347.f2", print_hash_value);
    transparent_crc(g_2347.f3, "g_2347.f3", print_hash_value);
    transparent_crc(g_2347.f4, "g_2347.f4", print_hash_value);
    transparent_crc(g_2347.f5, "g_2347.f5", print_hash_value);
    transparent_crc(g_2792.f0, "g_2792.f0", print_hash_value);
    transparent_crc(g_2792.f1, "g_2792.f1", print_hash_value);
    transparent_crc(g_2792.f2, "g_2792.f2", print_hash_value);
    transparent_crc(g_2792.f3, "g_2792.f3", print_hash_value);
    transparent_crc(g_2951, "g_2951", print_hash_value);
                      if ((g_2280 != 0) && (*g_2280 != 0) && ( *g_2280 < 0) )
{

{
                int32_t *l_124 = &g_62;
                (*(&g_116)) = l_124;

                ((g_116 == &g_62) ? (void) (0) : __assert_fail ("g_116 == &g_62", "t.c", 2838, __PRETTY_FUNCTION__));
                g_313 = g_1594;
                g_116 = g_116;
            }

}

transparent_crc(g_2952.f0, "g_2952.f0", print_hash_value);
    transparent_crc(g_2952.f1, "g_2952.f1", print_hash_value);
    transparent_crc(g_2952.f2, "g_2952.f2", print_hash_value);
    transparent_crc(g_2952.f3, "g_2952.f3", print_hash_value);
    transparent_crc(g_3732, "g_3732", print_hash_value);
    transparent_crc(g_3771.f0, "g_3771.f0", print_hash_value);
    transparent_crc(g_3771.f1, "g_3771.f1", print_hash_value);
    transparent_crc(g_3771.f2, "g_3771.f2", print_hash_value);
    transparent_crc(g_3771.f3, "g_3771.f3", print_hash_value);
    transparent_crc(g_3771.f4, "g_3771.f4", print_hash_value);
    transparent_crc(g_3771.f5, "g_3771.f5", print_hash_value);
    transparent_crc(g_4114, "g_4114", print_hash_value);
    transparent_crc(g_4141.f0, "g_4141.f0", print_hash_value);
    transparent_crc(g_4141.f1, "g_4141.f1", print_hash_value);
    transparent_crc(g_4141.f2, "g_4141.f2", print_hash_value);
    transparent_crc(g_4141.f3, "g_4141.f3", print_hash_value);
                      if ((g_129 != 0) && (*g_129 != 0) && (**g_129 != 0) && (***g_129 != 0) && ( ***g_129 < 0) )
{

{
        struct S0 **l_4142 = (void*)0;
        struct S0 **l_4143 = (void*)0;
        struct S0 **l_4144 = &g_1529;
        (*l_4144) = (g_803 , &g_803);

        ((g_1529 == &g_803) ? (void) (0) : __assert_fail ("g_1529 == &g_803", "t.c", 2870, __PRETTY_FUNCTION__));
    }

}

transparent_crc(g_4141.f4, "g_4141.f4", print_hash_value);
    transparent_crc(g_4141.f5, "g_4141.f5", print_hash_value);
    transparent_crc(g_4181.f0, "g_4181.f0", print_hash_value);
    transparent_crc(g_4181.f1, "g_4181.f1", print_hash_value);
    transparent_crc(g_4181.f2, "g_4181.f2", print_hash_value);
    transparent_crc(g_4181.f3, "g_4181.f3", print_hash_value);
    transparent_crc(g_4582, "g_4582", print_hash_value);
    transparent_crc(g_4585.f0, "g_4585.f0", print_hash_value);
    transparent_crc(g_4585.f1, "g_4585.f1", print_hash_value);
    transparent_crc(g_4585.f2, "g_4585.f2", print_hash_value);
    transparent_crc(g_4585.f3, "g_4585.f3", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

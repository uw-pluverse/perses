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


void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);static long __undefined;


struct S0 {
   uint16_t f0;
};

struct S1 {
   unsigned f0 : 29;
   unsigned f1 : 26;
   signed f2 : 10;
   unsigned f3 : 27;
   signed f4 : 18;
   signed f5 : 1;
   unsigned f6 : 26;
};


static int8_t g_12 = 0xBCL;
static int32_t g_13 = 0x5FEC46BCL;
static struct S0 g_21 = {0xC0B8L};
static int32_t g_30 = (-1L);
static int64_t g_32 = (-1L);
static uint8_t g_33 = 9UL;
static int64_t g_36 = 0xE281B1D0B827BE62LL;
static int32_t g_37 = 0x2EF61160L;
static int32_t g_38 = 6L;
static uint64_t g_39 = 0UL;
static int32_t g_65 = 1L;
static int8_t g_66 = (-5L);
static int8_t g_67 = (-4L);
static uint8_t g_69 = 0x3DL;
static uint32_t g_80 = 7UL;
static uint32_t g_182 = 18446744073709551609UL;
static int32_t g_183 = 0L;
static int16_t g_184 = 0L;
static uint8_t g_188 = 252UL;
static uint8_t g_191 = 1UL;
static struct S0 g_199 = {0x133DL};
static struct S1 g_238 = {8110,1413,13,11418,196,-0,504};
static int8_t g_240 = 0L;
static uint32_t g_241 = 18446744073709551615UL;
static uint32_t g_301 = 0x7F6F722BL;
static uint16_t g_315 = 0x89BEL;
static uint8_t g_322 = 0x36L;
static int32_t g_377 = 0x76F0FC06L;
static uint32_t g_378 = 0x122AFA7AL;
static int8_t g_524 = 0x0FL;
static int64_t g_527 = (-7L);
static uint32_t g_528 = 18446744073709551615UL;
static int32_t g_571 = 0x7B01DCB5L;
static int8_t g_586 = 0xB5L;
static uint16_t g_620 = 0xCC35L;
static int32_t g_756 = 0x66BD1D4CL;
static int32_t g_791 = (-9L);
static int32_t g_792 = 0x3C3CEAB1L;
static uint16_t g_793 = 0UL;
static int32_t g_800 = 0xF1E12B68L;
static uint8_t g_801 = 251UL;
static uint32_t g_873 = 18446744073709551615UL;
static uint16_t g_928 = 1UL;
static int32_t g_967 = 0x80995892L;
static uint32_t g_968 = 0xFF7B2476L;
static int16_t g_993 = 0x54F0L;
static uint32_t g_1249 = 4294967295UL;
static uint8_t g_1276 = 0UL;
static uint16_t g_1285 = 65535UL;



static int64_t func_1(void);
static uint8_t func_5(uint8_t p_6);
static int8_t func_14(int8_t p_15, struct S1 p_16, struct S0 p_17, struct S0 p_18, int32_t p_19);
static int16_t func_44(uint32_t p_45);
static int64_t func_56(struct S1 p_57, struct S0 p_58);
static uint8_t func_61(uint8_t p_62, uint32_t p_63, int64_t p_64);
static int8_t func_74(struct S0 p_75);
static uint8_t func_85(int16_t p_86, int8_t p_87, uint8_t p_88);
static uint8_t func_94(int16_t p_95, struct S0 p_96, int16_t p_97);
static int64_t func_101(int32_t p_102, uint16_t p_103);
static int64_t func_1(void)
{
    struct S1 l_2 = {5257,2494,15,7269,192,0,6867};
    struct S1 l_20 = {8399,1580,12,4707,209,0,910};
    struct S1 l_1295 = {8978,2774,11,1659,145,0,2412};
                                        if ((g_1285 > 65535) )
{


g_38 |= 0x342AL;


                    g_1285 |= ((safe_sub_func_uint64_t_u_u(0x6750A3B4BAC7944CLL, g_37)) > (func_85((g_756 &= (safe_lshift_func_uint16_t_u_s((g_67 >= g_183), ((safe_div_func_uint8_t_u_u(func_94((safe_div_func_uint16_t_u_u(g_32, 1L)), g_21, g_21.f0), 0xCDL)) | g_21.f0)))), __undefined, g_184) < g_183));


}
                    l_2.f2 = ((l_2 , (((((((-8L) && (safe_rshift_func_uint8_t_u_u(func_5(((l_1295 = (l_20 = ((safe_div_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(((!(g_12 || (l_2.f4 = (-1L)))) ^ g_12), 10)) <= (g_13 = g_12)), func_14(g_12, l_20, g_21, g_21, g_21.f0))) , g_238))) , g_571)), g_792))) != g_12) , 0UL) > l_2.f6) | 0xC987502CL) && g_528)) != g_524);
    return l_20.f1;
}







static uint8_t func_5(uint8_t p_6)
{
    struct S0 l_1296 = {0xA01FL};
    g_21 = l_1296;
    return g_571;
}







static int8_t func_14(int8_t p_15, struct S1 p_16, struct S0 p_17, struct S0 p_18, int32_t p_19)
{
    uint32_t l_24 = 18446744073709551612UL;
    int32_t l_29 = 0x78472532L;
    int32_t l_31 = 0x54F90BF5L;
    int16_t l_1014 = 0xEBF2L;
    struct S0 l_1015 = {0xD8E3L};
    int32_t l_1027 = 0xDEBF6134L;
    uint16_t l_1031 = 65533UL;
    struct S1 l_1050 = {3817,1817,-23,852,267,-0,5079};
    int32_t l_1288 = 0x9A5E3A71L;
    int32_t l_1290 = 0x9960D519L;
    uint8_t l_1292 = 0x55L;
                                                                           if ((l_1290 > g_993) )
{


l_1050.f5 ^= (safe_mod_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(0xAEL, (0x4461L | (g_37 != (g_756 = (__undefined == (l_1050.f0 = g_67))))))), l_1288));


for (g_301 = 0; (g_301 == 39); g_301 = safe_add_func_uint16_t_u_u(g_301, 1))
                    {
                        uint64_t l_657 = 1UL;
                        l_1050.f5 = 0xC207066FL;
                        g_377 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (g_38 = ((((safe_div_func_uint8_t_u_u(g_968, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(g_967 = (safe_mod_func_uint64_t_u_u(g_39, (g_36 &= ((safe_add_func_int8_t_s_s((g_928 = g_524), (safe_mod_func_int8_t_s_s(p_16.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((p_16.f5 &= g_801), (safe_mod_func_uint8_t_u_u(((~l_1014) , p_16.f1), 255UL)))) , g_38) & p_16.f2))))))) != 0xA14CL)))))) <= g_184), l_657))))) && 6UL))) == g_38) <= g_21.f0) <= 1L))) , l_1031), g_21.f0)) == l_1050.f4) || p_16.f0) | g_524), l_1031)) , 0x672551F9L) , 0xA150D49BL);
                    };


                    g_377 &= 0x62L;


}
                                                        while (!((g_32 >= -1)) )
{

p_16.f5 ^= (0x70BD7A420812CA0FLL > (safe_rshift_func_int16_t_s_u((((l_1050 = l_1050) , p_16.f0) , (safe_rshift_func_uint8_t_u_s(l_1050.f5, (0xF1AA9032L >= l_1050.f6)))), 1)));


}
                    if ((g_571 <= 2063719605))
                    { if ((l_1050.f6 <= 5079))
                    if ((safe_lshift_func_int16_t_s_s(((((g_21.f0 , l_24) == (0xFCD58F28D9227919LL || ((1UL || (safe_add_func_uint32_t_u_u((safe_mod_func_uint64_t_u_u(g_12, (g_21.f0 , l_24))), l_24))) <= l_24))) , g_21) , 3L), p_18.f0)))
    {
        uint64_t l_50 = 1UL;
        int32_t l_999 = 0x88B3C715L;
        g_33--;
                                            while ((g_21.f0 < 49336) )
{

g_968 |= ((safe_add_func_uint16_t_u_u(((safe_div_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_s((g_69 |= p_16.f1), 0)) <= g_184), (((safe_lshift_func_uint16_t_u_u((g_620 |= (((g_37 = g_968) | ((p_16.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((g_184 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((g_37 |= (((safe_add_func_uint64_t_u_u((g_36 < (l_1288 = ((p_16.f4 = p_16.f2) < g_65))), 0xB4C6519C0C658331LL)) | p_16.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), l_31)) , g_620)) > p_16.f4) || p_16.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > p_16.f1)) && l_1015.f0) && p_15) & g_791)) ^ g_620) & g_620)) >= 0UL) , l_31)) != g_322)) || 0x2FL)), p_15)) < p_16.f1) || 4294967294UL))) & g_199.f0), 65535UL)) >= p_16.f4);

}
                    p_18 = g_21;
                                       int64_t backup_0_8440_19945_g_32 = (~((((((~(g_993)) | ((l_1050.f5 % (-(l_1292))) ^ ((l_29 / (~(g_315))) - g_38))) || g_69) || (g_39 ^ g_800)) + (~((-(g_32)))))));
int16_t backup_1_8440_93496_g_993 = (-(((~((g_32 + ((-(g_39)) && (~((g_993 || g_315))))))) || (l_1292 && (((-(l_1050.f5)) & (g_800 && g_69)) * (-((~(((-(g_38)) + backup_0_8440_19945_g_32))))))))));
uint16_t backup_2_8440_59177_g_315 = (~(((~(((~((((~(g_800)) * l_1050.f5) % (g_38 && l_29)))) & ((~(g_315)) | ((-(((~((~((~(l_1292)))))) & backup_1_8440_93496_g_993))) ^ g_39))))) ^ (~((-((backup_0_8440_19945_g_32 * g_32))))))));
int8_t backup_3_8440_62316_l_1050_f5 = (~(((((~(l_1292)) & ((g_800 / backup_2_8440_59177_g_315) % l_29)) || (g_39 & g_993)) + ((~((-((-(g_32)))))) << (backup_0_8440_19945_g_32 || (g_69 | g_315))))));
                                    if ((!g_21.f0) )
{

g_873 |= ((safe_add_func_uint16_t_u_u(((safe_div_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_s((g_322 |= l_1050.f1), 0)) <= backup_1_8440_93496_g_993), (((safe_lshift_func_uint16_t_u_u((l_1031 |= (((g_792 = g_182) | ((l_1050.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((backup_1_8440_93496_g_993 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((g_38 |= (((safe_add_func_uint64_t_u_u((backup_0_8440_19945_g_32 < (l_31 = ((l_1050.f4 = l_1050.f2) < l_31))), 0xB4C6519C0C658331LL)) | l_1050.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), g_183)) , l_1031)) > l_1050.f4) || l_1050.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > l_1050.f1)) && l_1015.f0) && g_524) & g_37)) ^ l_1031) & l_1031)) >= 0UL) , g_183)) != g_1276)) || 0x2FL)), g_524)) < l_1050.f1) || 4294967294UL))) & l_1015.f0), 65535UL)) >= l_1050.f4);

}
                    if((l_1050.f5 < l_1292)){
backup_0_8440_19945_g_32 = g_32;
backup_1_8440_93496_g_993 = g_993;
backup_2_8440_59177_g_315 = g_315;
backup_3_8440_62316_l_1050_f5 = l_1050.f5;
                                    while ((((g_968 < l_29) || (g_32 > g_756)) || (g_32 < l_1290)) )
{

{

g_527 ^= ((((l_50 = ((l_1014 != 0x4CL) == (+(((-9L) == g_36) > 0UL)))) <= ((((safe_mod_func_uint8_t_u_u((g_33 = p_16.f0), l_1027)) <= 0xA1BF90C52FB11BB9LL) <= 1UL) & g_528)) , p_16) , g_967);


                    l_1050.f2 = (-4L);
            for (g_800 = (-19); (g_800 > 10); g_800 = safe_add_func_uint16_t_u_u(g_800, 6))
            {
                l_1050 = l_1050;
            }
        }

}
                    g_32 = (~((((-(g_69)) / (~(l_29))) - ((~(g_39)) - ((g_315 && g_993) * ((-(backup_3_8440_62316_l_1050_f5)) - ((~((g_800 || (l_1292 / g_32)))) ^ backup_1_8440_93496_g_993)))))));
                                    if ((!g_188) )
{

{
                        g_38 &= g_182;
                    }

}
                    g_993 = (-(((((g_39 - l_29) / g_993) << ((~(((~(l_1050.f5)) || (-(backup_0_8440_19945_g_32))))) || (~(((~((~(g_315)))) + backup_3_8440_62316_l_1050_f5))))) & (((~(backup_1_8440_93496_g_993)) % (~(g_38))) ^ g_69))));
g_315 = (~(((((-(l_29)) * (~(backup_3_8440_62316_l_1050_f5))) * ((g_32 * (l_1292 - (g_993 % ((backup_2_8440_59177_g_315 || g_69) << g_39)))) - (~((~(l_1050.f5)))))) * g_38)));
l_1050.f5 = (-(((~((l_1050.f5 + (((l_1292 + l_29) % (backup_1_8440_93496_g_993 && (~(g_800)))) / backup_2_8440_59177_g_315)))) && (-((backup_3_8440_62316_l_1050_f5 << ((g_69 ^ backup_0_8440_19945_g_32) && g_993)))))));
if((((g_800 < -236901528) || (!backup_2_8440_59177_g_315)) || ((g_800 > l_29) || (!g_69)))){
printf("g_32=%lld\n", (int64_t)g_32);
}
                                    while ((((g_571 < g_1276) && (l_1050.f4 > g_33)) || ((l_1050.f4 < l_1050.f0) && (g_792 < g_791))) )
{

l_1027 |= (((g_967 ^ (safe_rshift_func_int16_t_s_s(0x7DA3L, 14))) , (safe_lshift_func_int8_t_s_u(backup_2_8440_59177_g_315, 1))) != (safe_unary_minus_func_int16_t_s((l_31 = 0xBB70L))));


}
                    if((((!l_1292) || (backup_3_8440_62316_l_1050_f5 > 0)) || !(l_1292))){
printf("g_993=%lld\n", (int64_t)g_993);
}
if((!((g_993 > g_32)) || (!g_69))){
printf("g_315=%llu\n", (uint64_t)g_315);
}
if((!(g_993) || ((g_993 < -18304) && (!g_993)))){
printf("l_1050.f5=%lld\n", (int64_t)l_1050.f5);
}
}
                                    if (!(((g_38 < g_69) || (g_36 > g_524))) )
{

p_15 |= ((safe_add_func_uint64_t_u_u(((l_24 < ((safe_mod_func_uint64_t_u_u(g_238.f0, (((safe_sub_func_int8_t_s_s(((((backup_1_8440_93496_g_993 = g_241) > (safe_unary_minus_func_uint64_t_u(0xD039656BC93DCDE7LL))) && ((0x1154443CL ^ ((safe_rshift_func_int16_t_s_s((+(safe_sub_func_int32_t_s_s(g_238.f0, 0xA33F1971L))), 6)) , 0xA1E7029EL)) ^ p_17.f0)) == 0L), 0UL)) || 0xA51DB1AF86CBBD6FLL) , g_67))) , g_199.f0)) == g_238.f0), (-10L))) , g_571);


}
                    g_32 = backup_0_8440_19945_g_32;
g_993 = backup_1_8440_93496_g_993;
                                                                        if ((!((g_928 < g_792)) || ((g_792 < 1010625201) || (!g_792))) )
{


g_967 ^= (safe_lshift_func_uint8_t_u_s((g_322 < (5UL | func_56(g_238, p_17))), 7));

                    g_183 |= (((safe_add_func_int8_t_s_s((((((g_756 ^= ((g_38 = g_967) , l_1292)) >= (p_16.f4 = ((safe_add_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u((safe_mod_func_uint64_t_u_u(0x5357627B9C38BE8CLL, (safe_rshift_func_int8_t_s_u((((p_16.f2 < (l_999 = l_1050.f4)) ^ (g_315 & (g_873 <= (g_993 = p_15)))) < (l_31 = ((((l_1050.f5 = (safe_mod_func_int8_t_s_s((safe_div_func_int32_t_s_s(((l_1050.f2 ^= (-8L)) || 0xF7D7L), g_873)), 0x7AL))) ^ backup_1_8440_93496_g_993) < g_968) <= l_31))), 6)))), g_968)) | g_238.f3) , 0x4DL), g_873)) && 4294967292UL))) != 4294967293UL) || 0x61L) == 1UL), 0x74L)) , (-5L)) , g_968);

}
                    if ((!l_31) )
{

{
            int8_t l_295 = (-5L);
            --g_301;
            l_1050.f4 &= ((((g_183 &= 0x62L) <= ((g_756 = ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^ (l_999 = g_571)) & (safe_rshift_func_uint16_t_u_s(0x2310L, 10))) , ((p_19 ^ ((g_37 &= (l_295 != ((((l_1014 = ((g_791 & ((~((((l_1015 , (backup_3_8440_62316_l_1050_f5 ^ l_1050.f3)) > backup_3_8440_62316_l_1050_f5) != 0x2A7A2EF32379F2B3LL) != l_1288)) && l_295)) && l_295)) >= 0L) , 0x1AL) | 0x83L))) >= l_1050.f2)) != backup_3_8440_62316_l_1050_f5)) <= l_29) && (-1L)) || l_1050.f1) , backup_3_8440_62316_l_1050_f5)) | 1UL)) > 5L) ^ 0xDF8CL);
        }

}
                    g_315 = backup_2_8440_59177_g_315;
                                    if ((!g_80) )
{

if (g_993)
        {
            struct S0 l_200 = {0x8CAFL};
            int32_t l_205 = (-1L);
            int32_t l_208 = 0x15D7F043L;
            uint16_t l_215 = 0xEBE3L;
            struct S1 l_237 = {4888,4404,-28,3688,-181,0,4061};
            int32_t l_239 = 0x45497A7BL;
            for (l_50 = 14; (l_50 == 54); l_50++)
            {
                uint16_t l_196 = 1UL;
                l_196--;
                l_200 = p_18;
            }
            p_19 = (((safe_sub_func_uint8_t_u_u(g_182, (g_524 , l_1015.f0))) < ((l_215 = (g_238.f4 &= (+((((-1L) & ((0xAFL < (((g_188 == ((((g_238.f2 = (l_205 = (l_1015 , 8L))) <= ((((((g_39++) ^ g_993) >= l_200.f0) , g_21) , g_21.f0) ^ (-7L))) > g_184) ^ g_993)) , 18446744073709551613UL) > g_13)) ^ l_200.f0)) && g_793) != 0x8890B9DDL)))) <= l_1015.f0)) , g_238.f1);
            l_1050 = ((((((safe_mod_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s(((g_188 = (safe_lshift_func_int16_t_s_s((((((((safe_sub_func_int32_t_s_s(((((((safe_rshift_func_int16_t_s_s((+(g_993 && (g_524 = (-1L)))), (g_184 = g_183))) && (((safe_mod_func_uint16_t_u_u(l_215, (safe_lshift_func_uint8_t_u_s(((l_1015.f0 , 1L) , (0x34L != (safe_lshift_func_int8_t_s_s((safe_mod_func_uint64_t_u_u((g_993 >= (safe_add_func_uint64_t_u_u((backup_0_8440_19945_g_32 == 4294967290UL), g_993))), l_1015.f0)), g_238.f5)))), 5)))) | l_205) & 0x8900E08CL)) || g_39) || g_993) <= 0x3DL) < g_524), g_524)) | 0xBFBDL) < p_18.f0) > g_967) != l_1015.f0) | g_21.f0) <= 0xDC97BAAAL), 4))) || g_13), g_524)) | g_191) == g_377), g_13)) ^ l_215) ^ g_993) || 1L) , g_182) , l_237);

{
                        l_999 &= g_182;
                    }

                    g_873++;
        }
        else
        {
            uint32_t l_265 = 0x211A307CL;
            l_1050.f2 |= ((safe_lshift_func_uint8_t_u_s(255UL, (safe_rshift_func_uint8_t_u_s(g_39, 2)))) & (safe_sub_func_int16_t_s_s(g_238.f2, 1L)));

g_238.f4 ^= 0x1529816DL;

                    g_183 &= (l_1015 , g_238.f0);
            g_13 ^= (g_238.f5 = (l_1050.f2 = (safe_div_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(l_1015.f0, (((0x5DL > g_183) != (safe_unary_minus_func_int16_t_s(1L))) == ((((((g_182 > (safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_u(0xCBFBL, 6)) < (safe_add_func_uint32_t_u_u((((safe_sub_func_uint64_t_u_u(((((l_1015 = l_1015) , 0xA2463E9B3E846025LL) , (safe_div_func_int32_t_s_s(g_13, 0x810FC398L))) | l_265), g_184)) ^ l_265) || g_586), g_21.f0))), g_188))) ^ l_265) >= l_265) , p_16) , 249UL) , g_993)))) >= 5L) >= 255UL) , g_238.f6), g_993))));
        };


}
                    l_1050.f5 = backup_3_8440_62316_l_1050_f5;

                    ++g_39;
        l_999 &= ((l_29 | (safe_mod_func_int16_t_s_s(((func_44(((safe_rshift_func_int16_t_s_s((l_31 |= p_16.f3), (g_37 <= 6L))) , (safe_sub_func_uint64_t_u_u(p_19, l_50)))) , p_16.f2) | ((safe_sub_func_int8_t_s_s(0xA4L, p_16.f3)) <= g_571)), g_571))) || (-1L));
    }
    else
    {
        int32_t l_1002 = (-1L);
        int32_t l_1013 = 1L;
        uint32_t l_1051 = 0x65594852L;
        uint32_t l_1052 = 18446744073709551608UL;
        int8_t l_1053 = (-1L);
        int32_t l_1098 = 0L;
        struct S1 l_1133 = {18360,2680,-9,5913,-40,0,4915};
        struct S0 l_1185 = {0UL};
        int32_t l_1231 = (-1L);
        int32_t l_1279 = 1L;
        int32_t l_1289 = (-2L);
        int32_t l_1291 = (-1L);
        if (((safe_div_func_uint8_t_u_u(((l_1002 , (((p_16.f3 && (((g_801 < p_16.f5) , (((((!((((l_1002 && (safe_lshift_func_int8_t_s_u((safe_div_func_int64_t_s_s((p_16.f4 < (((l_1002 >= ((safe_rshift_func_int8_t_s_s((!((((((((safe_lshift_func_uint8_t_u_u(p_17.f0, (l_29 & 65530UL))) , p_15) >= g_32) >= 0x84791F80L) || 0x36FD788FL) >= g_37) != g_66) | g_184)), p_16.f2)) , 18446744073709551609UL)) > g_65) == l_29)), p_16.f6)), 4))) == g_528) & l_1013) == 0xA5L)) && p_16.f1) && p_16.f3) || g_12) == p_15)) , (-1L))) || 18446744073709551608UL) & g_527)) ^ p_16.f4), l_1014)) , p_19))
        {
            int64_t l_1024 = (-5L);
            int8_t l_1078 = (-6L);
            int32_t l_1097 = 1L;
            uint32_t l_1101 = 0xD7F1C410L;
            struct S1 l_1130 = {8673,6450,23,10711,151,0,6403};
            if (((l_1015 , ((safe_sub_func_int16_t_s_s((safe_add_func_int32_t_s_s(((safe_sub_func_int32_t_s_s((g_21 , ((safe_div_func_uint8_t_u_u(((l_31 = ((p_15 ^ (l_29 = l_1013)) > l_1024)) , (safe_rshift_func_int8_t_s_s(p_16.f3, 5))), ((g_38 <= (l_1027 = g_322)) && (g_967 = (+(safe_div_func_uint32_t_u_u((p_19 == g_586), p_16.f1))))))) | l_24)), p_15)) <= g_182), g_527)), p_17.f0)) <= l_1031)) ^ p_17.f0))
            {
                int32_t l_1071 = 0x4CD963E3L;
                int32_t l_1112 = 0x19243E41L;
                int64_t l_1157 = (-1L);
                if ((safe_mod_func_int64_t_s_s(g_69, (safe_mod_func_uint64_t_u_u(g_12, (safe_add_func_int64_t_s_s(((safe_add_func_uint32_t_u_u(l_1024, ((g_993 |= (safe_add_func_int32_t_s_s((p_16.f5 = ((((g_801 != (((((0x05L == ((0x25L ^ (safe_lshift_func_uint16_t_u_u((((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s((g_21 , p_16.f5), (((g_238 , p_16.f3) , l_1050) , 0L))) || l_1013), l_1051)) >= g_238.f4) >= 7UL), 13))) < g_69)) , 0x67L) & g_188) , 0xC3L) | l_1052)) || p_16.f6) , 0L) , l_1002)), g_33))) >= 0x08DCL))) == g_30), l_1053)))))))
                {
                    uint64_t l_1054 = 0UL;
                    g_30 &= (((p_15 != 0x8446L) , l_1015) , (((l_1054 ^ p_17.f0) , ((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u((safe_add_func_int64_t_s_s(((1UL & (safe_rshift_func_int8_t_s_u((safe_add_func_int64_t_s_s((l_1051 <= (g_238 , (safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(((((safe_mod_func_uint16_t_u_u(g_238.f3, g_191)) || p_16.f6) ^ l_1054) , l_1071), 8)) | l_1050.f3), 5L)))), g_377)), p_16.f4))) | l_1013), 0xCBB7D04007C17F65LL)), g_791)), p_16.f5)) > (-1L))) >= g_199.f0));
                }
                else
                {
                    int8_t l_1100 = (-7L);
                    int32_t l_1104 = 0L;
                    int32_t l_1111 = 0x36BD596BL;
                    uint16_t l_1129 = 65535UL;
                    p_16.f2 ^= (((((g_301 >= 0L) <= g_377) || ((safe_add_func_uint64_t_u_u((safe_div_func_int32_t_s_s((g_586 , ((((0L <= (0xAF2AFC70L || ((g_238.f1 |= ((((safe_sub_func_uint16_t_u_u(l_1078, (safe_lshift_func_uint16_t_u_u(1UL, g_315)))) , 0x08EAL) > 0x7146L) == 0x51A9FA1A770123F4LL)) && g_571))) != l_24) || g_967) >= p_16.f3)), 4294967295UL)), 0x8134BAAB9636E740LL)) | 0x429EL)) || l_1051) && g_527);

{
        uint64_t l_50 = 1UL;
        int32_t l_999 = 0x88B3C715L;

l_999 &= (l_1002 = (safe_lshift_func_uint8_t_u_s((+(g_873 < (-1L))), 6)));

                    g_191--;
        p_17 = p_17;

l_1130.f2 ^= (l_1133.f2 |= l_1130.f0);


                    ++g_39;

g_37 |= 0x342AL;


                    l_999 &= ((l_1231 | (safe_mod_func_int16_t_s_s(((func_44(((safe_rshift_func_int16_t_s_s((g_183 |= l_1133.f3), (l_1071 <= 6L))) , (safe_sub_func_uint64_t_u_u(l_1112, l_50)))) , l_1133.f2) | ((safe_sub_func_int8_t_s_s(0xA4L, l_1133.f3)) <= g_571)), g_571))) || (-1L));
    }

                    for (g_32 = 16; (g_32 != 15); g_32 = safe_sub_func_int32_t_s_s(g_32, 1))
                    {
                        int32_t l_1099 = 0x29D6DC62L;
                        l_1101 |= ((safe_add_func_uint16_t_u_u(((safe_div_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_s((g_188 |= g_238.f1), 0)) <= g_184), (((safe_lshift_func_uint16_t_u_u((g_793 |= (((l_1013 = g_80) | ((g_238.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((g_993 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((l_1098 |= (((safe_add_func_uint64_t_u_u((l_1024 < (l_1097 = ((g_238.f4 = p_16.f2) < l_1071))), 0xB4C6519C0C658331LL)) | p_16.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), l_1099)) , g_315)) > p_16.f4) || p_16.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > p_16.f1)) && g_21.f0) && l_1100) & l_1002)) ^ g_315) & g_928)) >= 0UL) , l_1099)) != g_33)) || 0x2FL)), l_1100)) < p_16.f1) || 4294967294UL))) & p_17.f0), 65535UL)) >= p_16.f4);
                        if (p_16.f1)
                            continue;
                    }
                    g_238.f5 = (safe_add_func_int8_t_s_s(((0L > (((l_1104 |= 0x342AL) && (l_1053 & (safe_div_func_uint8_t_u_u(0xA3L, (safe_rshift_func_uint16_t_u_u(0x820EL, 10)))))) , 1L)) , (safe_rshift_func_uint8_t_u_s((g_322++), 5))), (safe_add_func_int8_t_s_s(((0x5EA5295EB42C2F9DLL && (safe_rshift_func_int16_t_s_u(((safe_div_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((l_1097 &= l_1100), ((((safe_add_func_uint16_t_u_u((g_21.f0 = ((g_801 < p_19) <= 0x6B6EL)), l_1129)) , l_1101) , p_16) , 0xCCL))), l_1071)), g_240)), g_69)) && p_16.f2), p_16.f5))) || g_188), g_39))));

for (g_301 = 0; (g_301 == 39); g_301 = safe_add_func_uint16_t_u_u(g_301, 1))
                    {
                        uint64_t l_657 = 1UL;
                        l_1050.f5 = 0xC207066FL;
                        l_1104 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (l_1027 = ((((safe_div_func_uint8_t_u_u(g_301, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(l_1291 = (safe_mod_func_uint64_t_u_u(g_39, (l_1024 &= ((safe_add_func_int8_t_s_s((g_793 = g_66), (safe_mod_func_int8_t_s_s(l_1130.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((l_1130.f5 &= g_33), (safe_mod_func_uint8_t_u_u(((~l_1014) , l_1130.f1), 255UL)))) , l_1027) & l_1130.f2))))))) != 0xA14CL)))))) <= g_184), l_657))))) && 6UL))) == p_19) <= p_17.f0) <= 1L))) , g_928), p_17.f0)) == l_1050.f4) || l_1130.f0) | l_1078), g_928)) , 0x672551F9L) , 0xA150D49BL);
                    };


                    l_1130 = (l_1050 = g_238);
                }
                g_967 = ((1L >= ((safe_mod_func_uint8_t_u_u((l_1071 >= ((l_1133 = l_1133) , ((0L ^ 0xC90582774B564BEDLL) != ((g_184 || g_527) >= (+p_16.f2))))), (safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((l_1130.f0 ^ 0x3DD1A058L), l_1130.f3)), p_19)))) , 0x1AD8CD47L)) & 18446744073709551615UL);
                g_967 = (safe_div_func_uint32_t_u_u((safe_mod_func_int64_t_s_s(((safe_mod_func_uint64_t_u_u((safe_add_func_uint16_t_u_u(((safe_div_func_uint8_t_u_u(p_16.f4, (l_1112 && (g_191++)))) && (((safe_rshift_func_int8_t_s_u(g_571, ((safe_add_func_uint16_t_u_u((p_16.f3 ^ g_571), p_18.f0)) | g_527))) ^ (l_1157 || (((g_240 != p_16.f3) == (-4L)) & (-2L)))) == p_17.f0)), g_238.f0)), g_69)) , 1L), l_1133.f4)), p_16.f2));
                l_1130.f4 |= (safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_s(((l_1050.f5 = ((((4UL != ((safe_unary_minus_func_uint8_t_u((safe_rshift_func_uint8_t_u_s((safe_lshift_func_int16_t_s_s(((((safe_sub_func_int16_t_s_s(((safe_sub_func_int8_t_s_s(g_199.f0, (l_24 & (p_16.f5 &= (safe_div_func_int8_t_s_s(p_16.f3, 0x82L)))))) && (((safe_rshift_func_int8_t_s_s(((((0xE4L ^ ((safe_sub_func_uint64_t_u_u((((((g_238.f0 &= (safe_mod_func_int64_t_s_s((((((8UL && ((safe_mod_func_uint32_t_u_u((((safe_rshift_func_int8_t_s_u((safe_div_func_int32_t_s_s((p_16.f1 | l_1050.f6), l_1133.f2)), 7)) <= g_378) | p_16.f3), 0xF4092F41L)) || p_17.f0)) ^ l_1157) < g_238.f1) , l_1130.f6) , g_378), l_1130.f6))) , l_1112) & p_16.f4) ^ 0xCCBC0462L) == l_1051), g_571)) & 65535UL)) || l_29) | p_16.f2) > l_1097), l_1130.f3)) >= g_80) , 18446744073709551613UL)), 0x1DC2L)) , l_1185) , 0UL) || g_993), 13)), 3)))) || g_527)) | p_16.f4) , g_993) && g_238.f2)) <= 18446744073709551615UL), p_16.f6)), 7));
            }
            else
            {
                int16_t l_1198 = 1L;
                if ((((g_67 |= ((safe_lshift_func_int16_t_s_s((18446744073709551607UL != ((((((((safe_lshift_func_int16_t_s_s(((l_1015.f0 < (g_65 = ((safe_sub_func_int64_t_s_s((safe_add_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s((safe_mod_func_int32_t_s_s(l_1198, (safe_mod_func_int64_t_s_s((safe_mod_func_uint8_t_u_u(((p_15 |= ((safe_add_func_uint64_t_u_u(((g_528 < ((safe_mod_func_uint64_t_u_u(p_16.f0, (((safe_sub_func_int8_t_s_s(((((g_993 = g_182) > (safe_unary_minus_func_uint64_t_u(0xD039656BC93DCDE7LL))) && ((0x1154443CL ^ ((safe_rshift_func_int16_t_s_s((+(safe_sub_func_int32_t_s_s(l_1130.f0, 0xA33F1971L))), 6)) , 0xA1E7029EL)) ^ p_17.f0)) == 0L), 0UL)) || 0xA51DB1AF86CBBD6FLL) , l_1078))) , p_18.f0)) == l_1130.f0), (-10L))) , g_967)) > g_38), l_1198)), p_19)))), 14)) > p_16.f2) && g_33), (-1L))), g_69)) == 0L))) && 1L), g_873)) != g_33) != p_16.f3) > p_18.f0) == l_31) <= 0x48L) > 2UL) != 0x87C43CC6L)), 0)) , p_16.f5)) & g_968) , (-9L)))
                {
                    g_65 |= p_15;
                }
                else
                {

l_1024 ^= ((((g_39 = ((g_184 != 0x4CL) == (+(((-9L) == g_32) > 0UL)))) <= ((((safe_mod_func_uint8_t_u_u((g_33 = p_16.f0), g_756)) <= 0xA1BF90C52FB11BB9LL) <= 1UL) & g_301)) , l_1130) , g_800);


                    g_65 = (l_1133.f2 = (p_16.f2 ^= (l_1130.f2 |= p_16.f0)));
                    g_238 = g_238;
                }
            }
        }
        else
        {
            int64_t l_1216 = 0x5E4A5199B7ADA9F3LL;
            int32_t l_1217 = 0x973A592CL;
            int8_t l_1229 = 0xA6L;
            int32_t l_1247 = 0x75C172F7L;
            int64_t l_1284 = 0xD8A6352B8836645ELL;

{
                    g_21 = p_17;
                    l_1050 = l_1050;
                }

                    g_37 |= ((g_238.f5 | (g_39 = (l_29 < ((0x237022BDB339B958LL | ((~((l_1216 = p_17.f0) <= l_1217)) >= (g_756 >= p_16.f0))) ^ ((safe_rshift_func_int8_t_s_u((safe_add_func_int64_t_s_s(l_1185.f0, (safe_sub_func_int32_t_s_s((-1L), g_238.f6)))), 1)) ^ 0x09L))))) || g_756);

{
            l_1133.f2 = (-4L);

l_1050.f4 |= (safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_s(((l_1050.f5 = ((((4UL != ((safe_unary_minus_func_uint8_t_u((safe_rshift_func_uint8_t_u_s((safe_lshift_func_int16_t_s_s(((((safe_sub_func_int16_t_s_s(((safe_sub_func_int8_t_s_s(p_18.f0, (l_1051 & (p_16.f5 &= (safe_div_func_int8_t_s_s(p_16.f3, 0x82L)))))) && (((safe_rshift_func_int8_t_s_s(((((0xE4L ^ ((safe_sub_func_uint64_t_u_u((((((l_1050.f0 &= (safe_mod_func_int64_t_s_s((((((8UL && ((safe_mod_func_uint32_t_u_u((((safe_rshift_func_int8_t_s_u((safe_div_func_int32_t_s_s((p_16.f1 | l_1050.f6), l_1050.f2)), 7)) <= g_182) | p_16.f3), 0xF4092F41L)) || p_18.f0)) ^ g_36) < l_1050.f1) , l_1050.f6) , g_182), l_1050.f6))) , l_1217) & p_16.f4) ^ 0xCCBC0462L) == g_968), g_967)) & 65535UL)) || g_967) | p_16.f2) > g_38), l_1050.f3)) >= g_968) , 18446744073709551613UL)), 0x1DC2L)) , g_21) , 0UL) || g_993), 13)), 3)))) || l_1216)) | p_16.f4) , g_993) && l_1050.f2)) <= 18446744073709551615UL), p_16.f6)), 7));

                    for (g_30 = (-19); (g_30 > 10); g_30 = safe_add_func_uint16_t_u_u(g_30, 6))
            {
                l_1133 = g_238;
            }
        }

                    for (p_18.f0 = 2; (p_18.f0 >= 18); p_18.f0 = safe_add_func_int64_t_s_s(p_18.f0, 4))
            {
                uint32_t l_1230 = 0xC2612157L;
                int32_t l_1241 = 0x1C3A57D2L;
                int32_t l_1244 = 0x0E65AD9AL;
                int32_t l_1246 = 1L;
                l_1050 = g_238;
                l_1217 &= (g_65 = (safe_lshift_func_uint8_t_u_s((+(g_80 < (-1L))), 6)));

g_238.f5 &= (safe_div_func_int8_t_s_s(g_238.f3, 0x82L));


                    if (g_571)
                {
                    uint32_t l_1238 = 0xACAF4E8DL;
                    int32_t l_1240 = 0L;
                    g_65 = l_1229;
                    g_21 = (p_16.f6 , p_17);
                    p_16.f4 &= l_1230;

l_1053 |= ((safe_add_func_uint64_t_u_u(((g_241 < ((safe_mod_func_uint64_t_u_u(g_238.f0, (((safe_sub_func_int8_t_s_s(((((g_993 = g_80) > (safe_unary_minus_func_uint64_t_u(0xD039656BC93DCDE7LL))) && ((0x1154443CL ^ ((safe_rshift_func_int16_t_s_s((+(safe_sub_func_int32_t_s_s(l_1133.f0, 0xA33F1971L))), 6)) , 0xA1E7029EL)) ^ l_1015.f0)) == 0L), 0UL)) || 0xA51DB1AF86CBBD6FLL) , g_524))) , g_21.f0)) == l_1133.f0), (-10L))) , l_1288);


                    if (l_1231)
                    {
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;
                        g_238.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, l_1230)), (l_1239 = (l_1238 = g_30)))), (g_238.f6 , l_1240)));
                        g_1249++;
                    }
                    else
                    {

p_19 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((g_39 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((g_39 ^ (((5UL && ((((l_1185 = l_1015) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & l_1133.f0)) >= 4UL) ^ g_756)) , l_1185.f0), g_33)), l_1133.f0)) <= g_801)) , l_1133.f6), g_33)), l_24)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL);


                    l_1240 &= g_528;
                    }
                }
                else
                {
                    uint64_t l_1260 = 0xF5DC1668590A4472LL;
                    int32_t l_1273 = (-1L);
                    int32_t l_1274 = 0xEA32A638L;
                    int32_t l_1275 = 0x813DFFBBL;
                    p_16.f5 = (safe_mod_func_uint8_t_u_u((1UL == (safe_sub_func_uint8_t_u_u(((p_15 && l_1050.f4) > ((safe_div_func_uint64_t_u_u(g_69, g_322)) <= (((l_1260 , (safe_rshift_func_uint8_t_u_u(p_16.f4, 5))) != (--g_1249)) && (((g_240 & (p_16.f2 = (l_1217 ^= (safe_mod_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(0x17F9FA19L, g_36)), 1)) && p_16.f5), 0xD66C9ADCL))))) | p_18.f0) & g_184)))), l_1050.f5))), p_15));

g_800 &= (safe_div_func_uint8_t_u_u(((g_80 ^= l_1290) & (((l_1229 = (l_1291 = (0xDA1D0942DF00AC9ELL >= 0x9644A59A1FF38044LL))) ^ 0xCA3631A0D171E9D6LL) <= (g_315 |= ((safe_sub_func_uint64_t_u_u(0x6750A3B4BAC7944CLL, l_29)) > (func_85((g_967 &= (safe_lshift_func_uint16_t_u_s((l_1229 >= l_1275), ((safe_div_func_uint8_t_u_u(func_94((safe_div_func_uint16_t_u_u(l_1216, 1L)), g_21, g_21.f0), 0xCDL)) | g_21.f0)))), __undefined, g_993) < l_1002))))), (-4L)));


                    for (l_1031 = 3; (l_1031 != 32); l_1031 = safe_add_func_uint32_t_u_u(l_1031, 4))
                    {

g_756 ^= (safe_lshift_func_uint8_t_u_s((g_191 < (5UL | func_56(p_16, l_1015))), 7));

                    ++g_1276;

l_1260 |= ((safe_add_func_int8_t_s_s((((g_793 == 0x1D75A18AL) >= (safe_rshift_func_int8_t_s_u(1L, 1))) && (((l_31 , (0x3926L > ((safe_mod_func_int16_t_s_s((l_1014 = l_1050.f3), p_16.f2)) | g_240))) >= p_16.f6) , (-1L))), g_620)) <= 0L);


                    if (l_1133.f1)
                            break;
                        if (l_1279)
                            {
g_38 |= (((l_1273 ^ (safe_rshift_func_int16_t_s_s(0x7DA3L, 14))) , (safe_lshift_func_int8_t_s_u(g_928, 1))) != (safe_unary_minus_func_int16_t_s((g_792 = 0xBB70L))));


                    continue;}
                        p_16.f5 ^= (safe_mod_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(0xAEL, (0x4461L | (g_183 != (l_1217 = (l_1284 == (p_16.f0 = g_66))))))), l_1273));
                    }
                }
            }
        }

{
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;
                        g_238.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, g_378)), (l_1239 = (g_968 = l_29)))), (g_238.f6 , l_31)));
                        g_182++;
                    }

                    g_1285--;
        l_1050 = (g_238 = p_16);
        l_1292--;
    }}
    return g_993;
}







static int16_t func_44(uint32_t p_45)
{
    uint8_t l_55 = 0UL;
    struct S1 l_59 = {1957,70,26,2769,-287,0,5702};
                                       if (g_66)
                    for (p_45 = (-25); (p_45 == 43); p_45 = safe_add_func_uint64_t_u_u(p_45, 6))
    {

g_571 |= ((g_238.f5 | (g_39 = (g_792 < ((0x237022BDB339B958LL | ((~((g_527 = g_21.f0) <= g_791)) >= (g_38 >= g_238.f0))) ^ ((safe_rshift_func_int8_t_s_u((safe_add_func_int64_t_s_s(g_199.f0, (safe_sub_func_int32_t_s_s((-1L), g_238.f6)))), 1)) ^ 0x09L))))) || g_38);

                    g_967 ^= (safe_lshift_func_uint8_t_u_s((l_55 < (5UL | func_56(l_59, g_21))), 7));
    }
                                       if (((g_183 <= 0) || (!g_571)))
                    l_59.f4 = l_59.f2;
                                        if (((g_378 > 304806522) && (!g_30)) )
{

g_13 |= (((g_967 ^ (safe_rshift_func_int16_t_s_s(0x7DA3L, 14))) , (safe_lshift_func_int8_t_s_u(g_1285, 1))) != (safe_unary_minus_func_int16_t_s((g_30 = 0xBB70L))));


}
                    l_59.f5 = (safe_rshift_func_uint8_t_u_s(g_968, 5));
                                   int32_t backup_0_8492_35125_g_756 = (~(((~((-(g_66)))) || ((((g_968 && g_756) + g_184) ^ ((~((((~(g_967)) | g_792) ^ (g_800 + l_59.f4)))) || (-(g_620)))) || (~((~(g_21.f0))))))));
int32_t backup_1_8492_56405_g_792 = (~(((((~(g_967)) || (g_756 + g_968)) || ((-(g_620)) ^ (~((~(l_59.f4)))))) | (~((((backup_0_8492_35125_g_756 & g_800) - (g_792 >> g_184)) && g_21.f0))))));
int32_t backup_2_8492_82163_g_800 = (~((((~(g_967)) - ((~(g_792)) ^ (((~(backup_0_8492_35125_g_756)) * (g_620 | g_756)) % g_968))) && (~((~((backup_1_8492_56405_g_792 & (g_21.f0 - (g_800 ^ l_59.f4))))))))));
uint32_t backup_3_8492_59236_g_968 = (~(((((-((~(g_21.f0)))) ^ (g_620 | backup_0_8492_35125_g_756)) || ((l_59.f4 | g_66) && (~((-(g_792)))))) - ((~((backup_1_8492_56405_g_792 & (backup_2_8492_82163_g_800 ^ g_756)))) + (-(g_968))))));
if((g_21.f0 < g_756)){
backup_0_8492_35125_g_756 = g_756;
backup_1_8492_56405_g_792 = g_792;
backup_2_8492_82163_g_800 = g_800;
backup_3_8492_59236_g_968 = g_968;
g_756 = (~((((~((-(g_21.f0)))) & ((-((~((g_756 / (~(backup_0_8492_35125_g_756))))))) & ((((~((backup_3_8492_59236_g_968 / backup_1_8492_56405_g_792))) && g_792) + (~(g_800))) & (backup_2_8492_82163_g_800 + l_59.f4)))) | g_184)));
g_792 = (-(((-(g_620)) & (-((((g_184 ^ g_21.f0) && backup_2_8492_82163_g_800) * ((~(backup_1_8492_56405_g_792)) | (g_968 | ((-(g_756)) | (~(((g_792 && g_800) * backup_0_8492_35125_g_756))))))))))));
g_800 = (-((((-(l_59.f4)) & ((backup_1_8492_56405_g_792 + g_968) / (g_756 - g_800))) | (-((g_792 || ((-((~((g_66 + g_620))))) / (g_21.f0 | backup_0_8492_35125_g_756))))))));
g_968 = (~(((-((g_21.f0 / (~((-(g_620))))))) - (-((g_800 - ((~(((((~(g_184)) | (-(l_59.f4))) || (~(backup_3_8492_59236_g_968))) | (~((backup_1_8492_56405_g_792 && g_792)))))) - (-((backup_2_8492_82163_g_800 + g_756))))))))));
if((((g_620 > g_968) || (g_792 > -262145)) || (g_620 > backup_0_8492_35125_g_756))){
printf("g_756=%lld\n", (int64_t)g_756);
}
if(((!g_21.f0) || ((backup_2_8492_82163_g_800 > backup_1_8492_56405_g_792) || (!l_59.f4)))){
printf("g_792=%lld\n", (int64_t)g_792);
}
                               int8_t backup_0_8502_91289_l_59_f5 = (~(((~(((l_59.f5 && (((~(l_59.f0)) / g_37) || g_32)) / g_66))) - ((-(g_38)) * (~((((~(g_183)) % (~(g_377))) || (~((~((g_80 && l_59.f2))))))))))));
int32_t backup_1_8502_78635_g_37 = (-(((-(((~((-(backup_0_8502_91289_l_59_f5)))) ^ (-(l_59.f0))))) ^ (((-(((-(g_38)) + (~((~(g_377))))))) % (~(((-(((l_59.f2 + g_80) ^ l_59.f5))) - g_37)))) + ((~(g_183)) & (~((~(g_66)))))))));
int32_t backup_2_8502_22363_g_183 = (-((((((g_377 && backup_1_8502_78635_g_37) * g_37) | l_59.f5) & (g_80 ^ g_32)) - (~(((~((l_59.f2 * l_59.f0))) / (g_66 & g_38)))))));
uint32_t backup_3_8502_6189_l_59_f0 = (~(((~((((-(g_183)) | (g_38 / g_37)) && (~(backup_0_8502_91289_l_59_f5))))) % ((~(((g_32 ^ g_80) + (~((g_66 || (~(g_377)))))))) >> (-((l_59.f0 % (-(l_59.f5)))))))));
if((((!l_59.f5) || (g_183 < backup_2_8502_22363_g_183)) && ((backup_0_8502_91289_l_59_f5 <= 12) && (l_59.f2 >= 26)))){
backup_0_8502_91289_l_59_f5 = l_59.f5;
backup_1_8502_78635_g_37 = g_37;
backup_2_8502_22363_g_183 = g_183;
backup_3_8502_6189_l_59_f0 = l_59.f0;
l_59.f5 = (-(((~((~((~((~(l_59.f2)))))))) / (~(((-(((g_183 + backup_2_8502_22363_g_183) + ((~(l_59.f0)) | (-(((backup_0_8502_91289_l_59_f5 + g_80) / backup_1_8502_78635_g_37))))))) & (g_377 | (-((g_37 % g_66))))))))));
g_37 = (-((((((~(l_59.f2)) + backup_2_8502_22363_g_183) % (l_59.f5 + ((~(g_80)) & ((~(g_66)) / backup_0_8502_91289_l_59_f5)))) - (-(g_377))) % ((g_38 || l_59.f0) | g_183))));
g_183 = (-(((~((((~(l_59.f5)) ^ g_377) * (-((backup_1_8502_78635_g_37 * g_183)))))) / (((g_37 || l_59.f0) % (backup_2_8502_22363_g_183 - backup_3_8502_6189_l_59_f0)) & (~((g_66 + backup_0_8502_91289_l_59_f5)))))));
l_59.f0 = (~((((-((((~((g_377 * l_59.f5))) ^ (g_80 && backup_0_8502_91289_l_59_f5)) + g_38))) - (backup_1_8502_78635_g_37 - ((g_32 * (~((~(g_66))))) | (~(backup_3_8502_6189_l_59_f0))))) - (-(l_59.f2)))));
if((!((l_59.f2 < l_59.f0)) || ((!l_59.f0) || (backup_3_8502_6189_l_59_f0 > 1957)))){
printf("l_59.f5=%lld\n", (int64_t)l_59.f5);
}
if((!((g_377 > 1995504646)) && ((!g_80) || (backup_0_8502_91289_l_59_f5 < -1)))){
printf("g_37=%lld\n", (int64_t)g_37);
}
if(!(((!l_59.f2) || (g_80 > g_183)))){
printf("g_183=%lld\n", (int64_t)g_183);
}
if((g_183 < 1)){
printf("l_59.f0=%llu\n", (uint64_t)l_59.f0);
}
}
l_59.f5 = backup_0_8502_91289_l_59_f5;
g_37 = backup_1_8502_78635_g_37;
g_183 = backup_2_8502_22363_g_183;
l_59.f0 = backup_3_8502_6189_l_59_f0;

                    if((!((g_21.f0 < 49336)) && (!g_967))){
printf("g_800=%lld\n", (int64_t)g_800);
}
if((!g_756)){
printf("g_968=%llu\n", (uint64_t)g_968);
}
}
g_756 = backup_0_8492_35125_g_756;
g_792 = backup_1_8492_56405_g_792;
g_800 = backup_2_8492_82163_g_800;
g_968 = backup_3_8492_59236_g_968;

                                                       if ((g_183 <= 0))
                    return l_59.f3;
}







static int64_t func_56(struct S1 p_57, struct S0 p_58)
{
    uint16_t l_60 = 0UL;
    int32_t l_68 = 9L;
    int32_t l_373 = 0x8875C18FL;
    int32_t l_375 = 1L;
    uint64_t l_399 = 0x7C64D58AAD345F6ELL;
    int16_t l_400 = (-1L);
    int64_t l_493 = 9L;
    uint64_t l_579 = 0x4A4D34B35DC61D2DLL;
    uint64_t l_596 = 18446744073709551614UL;
    uint32_t l_674 = 0x131A0242L;
    uint8_t l_757 = 0xD8L;
    uint64_t l_760 = 0xF17CF80899438E3ELL;
    int32_t l_859 = (-3L);
    uint8_t l_910 = 3UL;
    uint32_t l_920 = 4294967292UL;
    uint32_t l_942 = 18446744073709551615UL;
    struct S0 l_950 = {65531UL};
    int32_t l_958 = (-1L);
    uint64_t l_994 = 0x66AA51C4DFD92F84LL;
    p_57.f2 &= l_60;


{
                    uint64_t l_641 = 0UL;
                    int32_t l_659 = (-1L);
                    for (g_968 = 0; (g_968 == 39); g_968 = safe_add_func_uint16_t_u_u(g_968, 1))
                    {
                        uint64_t l_657 = 1UL;

if (l_674)
                    {
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        p_57.f5 &= (!(g_967 = ((+(safe_mod_func_int32_t_s_s(p_57.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(p_57.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(g_238.f3, (((++g_21.f0) | (g_184 > ((g_33 , (g_792 ^= g_184)) , 0x3CC1CF37L))) != (l_942 == 249UL))))) , l_706), g_199.f0))))) ^ g_241)));
                        g_238 = p_57;
                    }
                    else
                    {
                        uint16_t l_731 = 0UL;
                        uint64_t l_732 = 0xFD49211BAC9527ABLL;
                        uint16_t l_745 = 0x07DBL;
                        p_57.f5 = (((!((((p_57.f0 == (safe_lshift_func_int8_t_s_s(g_928, ((safe_rshift_func_int8_t_s_s((p_57.f2 ^ ((((safe_sub_func_uint64_t_u_u((g_238.f4 &= g_322), (safe_mod_func_int16_t_s_s(((p_57.f4 > 1L) > ((g_800 & ((safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((((l_731 = (0xB1L > (safe_mod_func_uint32_t_u_u((safe_div_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((0xBAL <= g_39), 1UL)) == (-1L)), g_301)) & p_57.f1) == (-1L)) < g_301) && p_57.f0))), __undefined)), 0xE6E002D4L)))) || l_732) >= l_732) == g_188), g_238.f3)) == 1UL) & l_859), l_641)) == 0x4FL)) >= p_57.f2)), p_57.f6)))) < g_21.f0) ^ g_238.f6) , g_238.f4)), g_182)) || 0xA8L)))) > 251UL) , g_301) , g_238.f4)) || p_57.f3) && 0L);
                        g_65 ^= (((safe_lshift_func_int8_t_s_s((l_910 || ((safe_unary_minus_func_int16_t_s((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((g_527 ^= g_67), (g_38 |= ((!(safe_mod_func_uint32_t_u_u((g_238.f0 , ((l_745 && (0x58956D07L && (~((g_756 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_732 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((g_39 ^ (((5UL && ((((g_21 = g_199) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & p_57.f0)) >= 4UL) ^ g_792)) , g_21.f0), g_322)), p_57.f0)) <= g_188)) , p_57.f6), g_33)), g_182)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL)) <= g_238.f0)))) | p_57.f3)), g_322))) >= 0xC1BC967721442813LL)))) ^ l_942), p_57.f6)))) , 0x2FA0L)), 2)) , g_184) >= 1UL);
                        p_57.f4 = (p_57.f2 = 0xA79062E5L);
                        l_596--;
                    };


                    g_238.f5 = 0xC207066FL;
                        l_659 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (l_958 = ((((safe_div_func_uint8_t_u_u(g_378, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(g_756 = (safe_mod_func_uint64_t_u_u(l_641, (__undefined &= ((safe_add_func_int8_t_s_s((g_928 = g_66), (safe_mod_func_int8_t_s_s(g_238.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((g_238.f5 &= g_191), (safe_mod_func_uint8_t_u_u(((~l_400) , g_238.f1), 255UL)))) , l_958) & g_238.f2))))))) != 0xA14CL)))))) <= g_184), l_657))))) && 6UL))) == g_756) <= l_950.f0) <= 1L))) , g_928), l_950.f0)) == g_238.f4) || g_238.f0) | g_240), g_928)) , 0x672551F9L) , 0xA150D49BL);
                    }
                    if (((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u(((g_238.f6 & (safe_sub_func_uint8_t_u_u(g_238.f2, g_968))) < (l_994 |= ((safe_add_func_int8_t_s_s((((g_928 == 0x1D75A18AL) >= (safe_rshift_func_int8_t_s_u(1L, 1))) && (((l_859 , (0x3926L > ((safe_mod_func_int16_t_s_s((g_184 = g_238.f3), g_238.f2)) | g_240))) >= g_238.f6) , (-1L))), g_928)) <= 0L))), 4)), 6)) , 0L))
                    {
                        return g_756;
                    }
                    else
                    {
                        g_238.f5 = g_238.f3;
                        return g_37;
                    }
                }


for (g_191 = (-27); (g_191 < 39); g_191 = safe_add_func_uint8_t_u_u(g_191, 8))
    {
        int32_t l_284 = 0xEE263D41L;
        uint64_t l_288 = 18446744073709551615UL;
        int32_t l_290 = 9L;
        int32_t l_296 = 0xC6978A9AL;
        int32_t l_297 = 0x9ADCCFBDL;
        int32_t l_299 = 8L;
        int32_t l_300 = 0x80C45391L;
        struct S0 l_311 = {1UL};
        struct S1 l_314 = {15034,7901,-16,6783,-510,-0,5803};
        if ((((safe_lshift_func_uint8_t_u_s((g_69 = (safe_rshift_func_uint8_t_u_s(l_674, 2))), g_12)) && (((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_int8_t_s_s(((((p_57 = p_57) , ((g_37 = (safe_add_func_int64_t_s_s(((((__undefined != g_993) == (((safe_rshift_func_int16_t_s_u((3UL == (((l_284 <= 0xB1A0L) != (((((safe_rshift_func_uint8_t_u_u(((!g_993) , g_67), 5)) > l_288) & (-10L)) , 0xE1L) > g_1249)) , g_191)), g_12)) & 5L) || 0xA2B9BF124FD362E7LL)) == g_12) , (-1L)), l_288))) && g_37)) & l_284) >= 0x62L), l_288)) , g_12))) >= g_191) | 1L)) , g_993))
        {
            int8_t l_295 = (-5L);
            --g_968;
            p_57.f4 &= ((((g_571 &= 0x62L) <= ((g_800 = ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^ (g_13 = g_377)) & (safe_rshift_func_uint16_t_u_s(0x2310L, 10))) , ((g_37 ^ ((g_37 &= (l_295 != ((((l_400 = ((g_65 & ((~((((l_311 , (g_67 ^ p_57.f3)) > g_67) != 0x2A7A2EF32379F2B3LL) != l_284)) && l_295)) && l_295)) >= 0L) , 0x1AL) | 0x83L))) >= p_57.f2)) != g_67)) <= l_296) && (-1L)) || p_57.f1) , g_67)) | 1UL)) > 5L) ^ 0xDF8CL);
        }
        else
        {
            p_57.f2 = (-4L);
            for (l_300 = (-19); (l_300 > 10); l_300 = safe_add_func_uint16_t_u_u(l_300, 6))
            {
                p_57 = l_314;
            }
        }
    };


                    if (g_33)
    {
        int8_t l_126 = 0x41L;
        struct S0 l_158 = {65535UL};
        int32_t l_162 = (-1L);
        int8_t l_181 = 0x56L;
        int32_t l_206 = 0x501F8A61L;
        int32_t l_207 = 1L;
        int32_t l_209 = 0L;
        int32_t l_210 = 0x9105A86EL;
        int32_t l_211 = 0L;
        uint16_t l_214 = 0xEB0AL;
        struct S1 l_266 = {8020,8046,-6,1087,99,-0,4038};

l_210 |= ((safe_sub_func_int32_t_s_s(((safe_sub_func_int16_t_s_s(l_266.f2, (g_32 = (safe_sub_func_uint8_t_u_u(g_1285, (((l_266 , l_266.f1) , l_266) , (safe_add_func_uint8_t_u_u((safe_sub_func_uint64_t_u_u(((((l_674++) && (l_674 != 0xAEL)) ^ 0x9714L) <= 0xD7EAL), 0x1FBFD773E599F898LL)), g_801)))))))) < l_266.f5), g_184)) < g_1285);


                    g_30 = ((func_101(g_184, (((safe_lshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s(((((safe_add_func_int16_t_s_s(((9UL == 18446744073709551614UL) & (safe_lshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u((-1L), (65532UL != l_674))), 1))), l_674)) <= ((safe_div_func_int64_t_s_s(((safe_mod_func_uint64_t_u_u((((((!2L) & (--g_39)) > ((safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(((((safe_add_func_int32_t_s_s(l_674, 1UL)) | g_791) , 1L) || l_126), g_993)), l_950.f0)) >= l_950.f0)) >= l_950.f0) & g_33), g_571)) && g_67), 0xCC1C6A88B8388ADFLL)) >= l_674)) , g_67) < l_596), 13)), 3)) && l_126), 4)), g_36)), 6)) <= l_126) != 1UL)) >= g_240) <= l_375);
        g_791 = ((((g_238 , 0xCFL) <= (g_21.f0 == (0xFF4B716CAE9C981CLL < l_126))) <= (0x1CL < ((g_240 , l_126) , ((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(0xAF64L, g_21.f0)) != g_993), g_184)), 0x92ADL)) < g_184)))) | 0xFAL);
        for (g_21.f0 = 0; (g_21.f0 != 25); g_21.f0 = safe_add_func_int64_t_s_s(g_21.f0, 8))
        {
            uint32_t l_163 = 0UL;
            int32_t l_168 = 0x35FECE65L;
            int32_t l_185 = 1L;
            int32_t l_186 = 0xCCA4C161L;
            int32_t l_187 = 5L;
            g_1249 ^= (g_12 == ((safe_mod_func_int16_t_s_s(((safe_div_func_uint64_t_u_u(((0x23B04249L >= (safe_mod_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s(((((l_950 = l_158) , l_950) , (safe_lshift_func_uint16_t_u_s((++l_163), (safe_mod_func_uint32_t_u_u(l_168, (safe_div_func_int32_t_s_s((g_240 > ((l_950.f0 |= (safe_sub_func_uint64_t_u_u((safe_add_func_int32_t_s_s((65530UL | (safe_div_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(0x88AFL, (safe_add_func_int16_t_s_s((((l_158 = g_21) , (-10L)) & 0xC4A096ABL), 0xBEFCL)))), l_596))), l_181)), g_30))) ^ 0x3F1CL)), 0xBE4CFF9CL))))))) < l_162), 7)) | g_238.f2) || g_191), g_184))) != 0x1A2308598B864A24LL), g_238.f5)) < 1L), 0x8ABAL)) < g_184));
            --g_322;

__undefined ^= ((((l_994 = ((l_400 != 0x4CL) == (+(((-9L) == g_527) > 0UL)))) <= ((((safe_mod_func_uint8_t_u_u((l_910 = p_57.f0), l_859)) <= 0xA1BF90C52FB11BB9LL) <= 1UL) & g_301)) , p_57) , g_38);


                    g_801++;
        }

g_80 |= ((safe_add_func_uint16_t_u_u(((safe_div_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_s((g_191 |= p_57.f1), 0)) <= g_184), (((safe_lshift_func_uint16_t_u_u((l_214 |= (((l_859 = g_528) | ((p_57.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((g_184 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((l_859 |= (((safe_add_func_uint64_t_u_u((g_36 < (l_206 = ((p_57.f4 = p_57.f2) < g_37))), 0xB4C6519C0C658331LL)) | p_57.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), g_38)) , g_793)) > p_57.f4) || p_57.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > p_57.f1)) && g_21.f0) && g_524) & g_967)) ^ g_793) & g_793)) >= 0UL) , g_38)) != l_757)) || 0x2FL)), g_524)) < p_57.f1) || 4294967294UL))) & g_199.f0), 65535UL)) >= p_57.f4);

                    if (g_993)
        {
            struct S0 l_200 = {0x8CAFL};
            int32_t l_205 = (-1L);
            int32_t l_208 = 0x15D7F043L;
            uint16_t l_215 = 0xEBE3L;
            struct S1 l_237 = {4888,4404,-28,3688,-181,0,4061};
            int32_t l_239 = 0x45497A7BL;
            for (g_39 = 14; (g_39 == 54); g_39++)
            {
                uint16_t l_196 = 1UL;
                l_196--;
                l_200 = g_199;
            }
            g_791 = (((safe_sub_func_uint8_t_u_u(l_920, (g_67 , l_950.f0))) < ((l_215 = (g_238.f4 &= (+((((-1L) & ((0xAFL < (((g_322 == ((((g_238.f2 = (l_205 = (l_950 , 8L))) <= ((((((l_596++) ^ g_993) >= l_200.f0) , g_21) , g_21.f0) ^ (-7L))) > g_184) ^ g_993)) , 18446744073709551613UL) > g_571)) ^ l_200.f0)) && l_214) != 0x8890B9DDL)))) <= l_158.f0)) , g_238.f1);
            g_238 = ((((((safe_mod_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s(((g_801 = (safe_lshift_func_int16_t_s_s((((((((safe_sub_func_int32_t_s_s(((((((safe_rshift_func_int16_t_s_s((+(g_993 && (g_240 = (-1L)))), (g_184 = g_30))) && (((safe_mod_func_uint16_t_u_u(l_215, (safe_lshift_func_uint8_t_u_s(((l_950.f0 , 1L) , (0x34L != (safe_lshift_func_int8_t_s_s((safe_mod_func_uint64_t_u_u((g_993 >= (safe_add_func_uint64_t_u_u((g_36 == 4294967290UL), g_993))), l_950.f0)), g_238.f5)))), 5)))) | l_205) & 0x8900E08CL)) || l_596) || g_993) <= 0x3DL) < g_67), g_67)) | 0xBFBDL) < g_199.f0) > l_210) != l_950.f0) | g_21.f0) <= 0xDC97BAAAL), 4))) || g_571), g_67)) | g_33) == l_211), g_183)) ^ l_215) ^ g_993) || 1L) , l_920) , l_237);
            g_301++;
        }
        else
        {
            uint32_t l_265 = 0x211A307CL;

l_266.f1 |= ((((safe_sub_func_uint16_t_u_u(l_181, (safe_lshift_func_uint16_t_u_u(1UL, g_315)))) , 0x08EAL) > 0x7146L) == 0x51A9FA1A770123F4LL);


                    g_238.f2 |= ((safe_lshift_func_uint8_t_u_s(255UL, (safe_rshift_func_uint8_t_u_s(l_596, 2)))) & (safe_sub_func_int16_t_s_s(g_238.f2, 1L)));
            g_30 &= (l_950 , g_238.f0);
            l_207 ^= (g_238.f5 = (g_238.f2 = (safe_div_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(l_158.f0, (((0x5DL > g_30) != (safe_unary_minus_func_int16_t_s(1L))) == ((((((l_920 > (safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_u(0xCBFBL, 6)) < (safe_add_func_uint32_t_u_u((((safe_sub_func_uint64_t_u_u(((((l_950 = l_950) , 0xA2463E9B3E846025LL) , (safe_div_func_int32_t_s_s(g_571, 0x810FC398L))) | l_265), g_184)) ^ l_265) || g_12), g_21.f0))), g_322))) ^ l_265) >= l_265) , l_266) , 249UL) , g_993)))) >= 5L) >= 255UL) , g_238.f6), g_993))));
        }
    }
    else
    {
        struct S0 l_267 = {0xB8F5L};
        l_267 = (g_21.f0 , l_950);
        l_950 = l_950;
    };


                    if ((l_68 = ((func_61(g_30, ((g_69++) && ((l_68 >= l_68) , (((safe_sub_func_int32_t_s_s(g_12, 1UL)) || func_74(p_58)) || (g_36 != (safe_sub_func_uint32_t_u_u(0UL, p_58.f0)))))), p_57.f1) ^ p_57.f6) || (-6L))))
    {
        int32_t l_338 = 1L;
        uint8_t l_367 = 0x7FL;
        int32_t l_370 = 0L;
        int32_t l_371 = 0x384BA09CL;
        int32_t l_372 = 0x83DB8F6AL;
        int32_t l_374 = (-4L);
        int32_t l_376 = 6L;

g_801 ^= (g_184 = 0xCEC1L);


                    for (g_184 = 10; (g_184 == (-17)); --g_184)
        {
            int32_t l_347 = 1L;
            int32_t l_368 = 5L;
            if (((safe_sub_func_int32_t_s_s((~g_33), ((((+l_338) || (1L && (safe_div_func_uint8_t_u_u(((p_57.f1 == ((safe_add_func_int32_t_s_s(0L, ((((((!(safe_add_func_int8_t_s_s(g_240, 0xF5L))) , (safe_unary_minus_func_int16_t_s(3L))) > p_57.f0) > l_338) ^ 0x6B9E5876L) || 1UL))) < l_347)) & 1L), g_241)))) && 65535UL) == 0UL))) & 7UL))
            {

l_367 ^= (((((+(safe_rshift_func_int16_t_s_u(((g_69 ^= (((l_374 = (0xEB54L < g_238.f1)) <= g_238.f2) > g_12)) | g_793), l_950.f0))) ^ (safe_mul_func_int16_t_s_s((l_400 = 9L), (18446744073709551606UL >= g_993)))) != 2UL) <= 0x1EL) < l_942);



{
                int32_t l_519 = (-1L);
                int32_t l_521 = 0xC5583EF5L;
                g_967 &= ((0L < (((((safe_add_func_int64_t_s_s(((safe_lshift_func_int16_t_s_s(((-10L) | g_571), ((safe_sub_func_int16_t_s_s((g_38 = (((l_958 |= ((safe_sub_func_int32_t_s_s(((safe_sub_func_int16_t_s_s(g_238.f2, (__undefined = (safe_sub_func_uint8_t_u_u(g_620, (((g_238 , g_238.f1) , g_238) , (safe_add_func_uint8_t_u_u((safe_sub_func_uint64_t_u_u(((((g_241++) && (g_241 != 0xAEL)) ^ 0x9714L) <= 0xD7EAL), 0x1FBFD773E599F898LL)), g_322)))))))) < g_238.f5), l_400)) < g_620)) && 0x22L) ^ g_39)), g_184)) != g_238.f5))) , g_240), l_920)) != g_1249) > g_188) || l_338) <= p_58.f0)) || g_238.f2);
                l_942++;
                g_238.f4 &= (safe_sub_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(l_760, 0x32B0L)), 0x8C89L));
            }

                    if ((p_57.f5 = (0xCDL ^ p_57.f1)))
                {

g_967 |= g_240;

                    return l_338;
                }
                else
                {
                    return g_184;
                }
            }
            else
            {
                uint8_t l_348 = 255UL;
                struct S0 l_369 = {65529UL};
                if (l_348)
                {
                    p_57.f2 ^= g_69;
                    if (p_57.f1)
                        break;

l_60 |= (((l_958 = g_528) | ((g_238.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((l_400 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((g_791 |= (((safe_add_func_uint64_t_u_u((g_527 < (l_859 = ((g_238.f4 = p_57.f2) < l_338))), 0xB4C6519C0C658331LL)) | p_57.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), l_368)) , g_315)) > p_57.f4) || p_57.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > p_57.f1)) && l_369.f0) && g_240) & g_791)) ^ g_315) & g_620)) >= 0UL) , l_368)) != g_1276)) || 0x2FL);





p_57.f2 ^= (((((g_241 >= 0L) <= l_374) || ((safe_add_func_uint64_t_u_u((safe_div_func_int32_t_s_s((g_240 , ((((0L <= (0xAF2AFC70L || ((g_238.f1 |= ((((safe_sub_func_uint16_t_u_u(g_586, (safe_lshift_func_uint16_t_u_u(1UL, g_928)))) , 0x08EAL) > 0x7146L) == 0x51A9FA1A770123F4LL)) && g_377))) != g_873) || l_347) >= p_57.f3)), 4294967295UL)), 0x8134BAAB9636E740LL)) | 0x429EL)) || g_80) && g_527);

                    g_238.f4 &= g_33;


                    l_338 |= g_586;


g_238.f2 &= g_928;


{
                        l_376 &= g_80;
                    }

                    if (p_57.f2)
                        {
{
                    p_57.f2 ^= g_191;
                    if (p_57.f1)
                        break;

if (((safe_mod_func_int32_t_s_s((g_30 , (((safe_lshift_func_int8_t_s_s((safe_div_func_int64_t_s_s((safe_mod_func_int64_t_s_s(((g_792 , (((g_238.f5 < ((safe_sub_func_int32_t_s_s((g_188 <= ((safe_div_func_int64_t_s_s(((g_38 = ((safe_lshift_func_uint16_t_u_u(p_57.f1, 9)) <= ((((g_238.f1 ^ (g_873 = ((((!(((+(-5L)) >= 0x2077L) | (((safe_lshift_func_uint16_t_u_s((safe_unary_minus_func_int32_t_s((safe_lshift_func_uint16_t_u_u(0x3FE3L, 15)))), 9)) < 0x3ED2BC827CFBFAACLL) == 0UL))) <= 0xEE3FL) && 0xCB01CDCFF5673DEALL) , l_994))) | 0x05B4L) , l_369.f0) > 0xF83382B7L))) == 1UL), g_240)) <= 0xF8L)), g_993)) , g_182)) , g_80) >= g_13)) , 0x1B3F29B522290BD6LL), p_57.f3)), p_57.f5)), g_792)) == l_958) <= 0x80L)), g_993)) == g_30))
                {
                    uint16_t l_451 = 0x721EL;
                    int32_t l_453 = (-1L);
                    p_57.f2 = ((g_38 |= (((g_38 ^ (safe_rshift_func_int16_t_s_s(0x7DA3L, 14))) , (safe_lshift_func_int8_t_s_u(l_451, 1))) != (safe_unary_minus_func_int16_t_s((l_453 = 0xBB70L))))) & ((safe_mod_func_uint8_t_u_u((safe_div_func_uint32_t_u_u((!((((p_57.f4 , g_80) < p_57.f0) , (safe_div_func_int64_t_s_s((__undefined = ((safe_add_func_uint64_t_u_u(p_57.f6, (l_493 = 0L))) >= (-1L))), g_13))) , 0x779BL)), g_80)), p_57.f6)) > p_57.f3));
                }
                else
                {

{
                        ++g_801;
                        if (p_57.f1)
                            break;
                        if (g_37)
                            continue;
                        g_238.f5 ^= (safe_mod_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(0xAEL, (0x4461L | (g_800 != (g_38 = (__undefined == (g_238.f0 = g_67))))))), g_756));
                    }

                    g_21 = l_369;
                    g_238 = p_57;
                };



{
                        return l_338;
                    }

                    if (p_57.f2)
                        {

l_372 &= (g_524 != ((((g_993 = ((g_13 & ((~((((l_369 , (g_66 ^ g_238.f3)) > g_66) != 0x2A7A2EF32379F2B3LL) != l_958)) && g_524)) && g_524)) >= 0L) , 0x1AL) | 0x83L));


                    g_238.f1 &= (7L & ((g_32 ^= ((((l_596 = ((l_400 != 0x4CL) == (+(((-9L) == g_36) > 0UL)))) <= ((((safe_mod_func_uint8_t_u_u((g_322 = g_238.f0), l_68)) <= 0xA1BF90C52FB11BB9LL) <= 1UL) & g_873)) , g_238) , l_338)) <= g_238.f2));



{
                    g_21 = g_199;
                    p_57 = g_238;
                }

                    continue;}
                }


{
                int32_t l_519 = (-1L);
                int32_t l_521 = 0xC5583EF5L;

for (l_579 = 0; (l_579 > 1); l_579++)
        {
            int32_t l_870 = (-1L);
            l_521 = (g_238.f3 , (safe_rshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(g_191, 13)), g_322)), 10)));
            return l_870;
        };



g_301 |= ((safe_add_func_uint16_t_u_u(((safe_div_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_s((l_757 |= g_238.f1), 0)) <= g_184), (((safe_lshift_func_uint16_t_u_u((g_315 |= (((l_376 = l_942) | ((g_238.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((g_184 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((l_375 |= (((safe_add_func_uint64_t_u_u((g_32 < (l_373 = ((g_238.f4 = p_57.f2) < l_376))), 0xB4C6519C0C658331LL)) | p_57.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), l_368)) , g_315)) > p_57.f4) || p_57.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > p_57.f1)) && l_369.f0) && g_524) & l_374)) ^ g_315) & g_928)) >= 0UL) , l_368)) != g_33)) || 0x2FL)), g_524)) < p_57.f1) || 4294967294UL))) & l_369.f0), 65535UL)) >= p_57.f4);

                    g_800 &= ((0L < (((((safe_add_func_int64_t_s_s(((safe_lshift_func_int16_t_s_s(((-10L) | l_374), ((safe_sub_func_int16_t_s_s((g_37 = (((l_376 |= ((safe_sub_func_int32_t_s_s(((safe_sub_func_int16_t_s_s(g_238.f2, (g_32 = (safe_sub_func_uint8_t_u_u(l_60, (((g_238 , g_238.f1) , g_238) , (safe_add_func_uint8_t_u_u((safe_sub_func_uint64_t_u_u(((((g_873++) && (g_873 != 0xAEL)) ^ 0x9714L) <= 0xD7EAL), 0x1FBFD773E599F898LL)), g_1276)))))))) < g_238.f5), l_400)) < l_60)) && 0x22L) ^ l_399)), g_184)) != g_238.f5))) , g_67), g_241)) != g_241) > g_801) || l_371) <= l_369.f0)) || g_238.f2);
                l_920++;
                g_238.f4 &= (safe_sub_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(l_760, 0x32B0L)), 0x8C89L));
            }

                    continue;}
                }
                else
                {

g_238.f4 &= l_367;


                    if ((safe_lshift_func_int8_t_s_s(((4294967295UL ^ ((((safe_sub_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u((safe_div_func_int32_t_s_s(0x8676E750L, (((safe_rshift_func_uint8_t_u_s((safe_div_func_int64_t_s_s((((l_347 = 1L) >= l_60) < (p_57.f4 , (g_184 != 1UL))), (safe_sub_func_uint8_t_u_u((safe_add_func_int8_t_s_s((g_66 ^= ((p_57.f0 || 255UL) < 0xD6E0L)), 6L)), p_57.f2)))), 1)) , 4294967295UL) , l_347))), l_338)) == g_238.f4) || l_338), 65533UL)) || 0x93L), g_183)) || g_67) >= l_338) , l_367)) == l_368), 3)))
                    {

{
            int16_t l_561 = (-8L);
            struct S0 l_562 = {0x698AL};
            uint32_t l_576 = 0x50148CBAL;
            for (g_184 = 0; (g_184 != (-23)); g_184 = safe_sub_func_uint64_t_u_u(g_184, 6))
            {
                uint32_t l_559 = 4294967295UL;
                int32_t l_560 = 9L;
                l_370 = ((18446744073709551615UL && (((safe_unary_minus_func_int64_t_s((safe_add_func_uint16_t_u_u((g_21.f0 == (safe_div_func_int8_t_s_s((safe_mod_func_int64_t_s_s((+((((p_57.f0 || (((p_57.f5 , ((safe_mod_func_int8_t_s_s((((((safe_sub_func_int64_t_s_s(0xF9CED6740F5759D8LL, g_801)) | 0x5CB0L) && (-1L)) < ((g_182 = (safe_mod_func_uint16_t_u_u((+((safe_div_func_int32_t_s_s(((l_559 = (safe_sub_func_uint64_t_u_u(((safe_mod_func_int64_t_s_s(((p_57 , g_968) >= 0x34E3L), 0x02128AB49729E21BLL)) && g_37), (-1L)))) != p_57.f1), (-5L))) > p_57.f1)), g_21.f0))) <= 4L)) | 0xB4A67218FBF74A89LL), l_560)) , l_373)) != 0xF6L) || l_561)) >= g_12) ^ 0x08A696AFL) > g_12)), 1UL)), 0x24L))), g_184)))) & g_967) > l_370)) & g_21.f0);
            }
            l_562 = l_562;
            for (g_38 = 0; (g_38 == 14); g_38 = safe_add_func_uint16_t_u_u(g_38, 7))
            {
                int64_t l_568 = 0x5C343ED73A8738E9LL;
                p_57.f2 = (((p_57.f1 &= (7L & ((__undefined ^= ((((l_399 = ((l_561 != 0x4CL) == (+(((-9L) == l_568) > 0UL)))) <= ((((safe_mod_func_uint8_t_u_u((l_348 = p_57.f0), g_800)) <= 0xA1BF90C52FB11BB9LL) <= 1UL) & g_873)) , p_57) , g_183)) <= p_57.f2))) <= p_57.f5) <= p_57.f2);
                l_370 = (~0x67D3L);
                if (p_57.f4)
                    break;
                p_57.f4 &= (p_57.f5 ^= ((!((((((safe_add_func_uint16_t_u_u((((p_57.f6 & (((((l_576 < (safe_lshift_func_uint16_t_u_u(l_579, (g_12 > g_12)))) < (safe_mod_func_int32_t_s_s((safe_div_func_uint64_t_u_u((safe_lshift_func_uint8_t_u_u((1L & (__undefined < (0x7F8CL | (g_967 = p_57.f3)))), g_12)), g_184)), g_182))) < 4UL) , g_182) <= __undefined)) ^ g_315) <= (-4L)), p_57.f0)) , p_57.f1) != 1L) <= l_568) & p_57.f1) && l_910)) || 0UL));
            }
            p_57 = p_57;
        }

                    if (g_36)
                            break;
                    }
                    else
                    {

{
        uint64_t l_50 = 1UL;
        int32_t l_999 = 0x88B3C715L;

{
            uint8_t l_687 = 2UL;
            uint32_t l_692 = 4294967291UL;
            int32_t l_758 = (-6L);
            int64_t l_759 = 0x10201B5C969F6449LL;
            int32_t l_796 = (-1L);
            int32_t l_797 = 0x66E5B6A1L;
            int32_t l_799 = (-9L);
            for (l_674 = (-14); (l_674 != 49); l_674 = safe_add_func_uint8_t_u_u(l_674, 3))
            {
                int16_t l_690 = (-1L);
                int32_t l_705 = 3L;

if ((g_12 & (((((p_57 , (l_579 && l_994)) | (safe_mod_func_uint16_t_u_u(((l_371 , ((safe_sub_func_uint16_t_u_u(((((2UL & (safe_add_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(g_1276, p_57.f3)), ((safe_sub_func_uint8_t_u_u((safe_div_func_int64_t_s_s(0xEC0DF3DED07D7D71LL, 0xFE38C1710C6551B0LL)), p_57.f3)) , 65532UL)))) , 0x598DL) > g_528) || g_528), g_528)) == p_57.f0)) || g_241), g_184))) <= p_57.f5) > 0xB0L) || l_687)))
        {
            uint16_t l_644 = 7UL;
            int32_t l_655 = 0x4245560AL;
            int32_t l_658 = 1L;
            for (g_527 = 16; (g_527 >= (-4)); g_527 = safe_sub_func_int64_t_s_s(g_527, 9))
            {
                uint16_t l_614 = 0x585DL;

l_799 ^= (p_57.f5 = (g_238.f2 = (safe_div_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(l_369.f0, (((0x5DL > l_372) != (safe_unary_minus_func_int16_t_s(1L))) == ((((((l_920 > (safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_u(0xCBFBL, 6)) < (safe_add_func_uint32_t_u_u((((safe_sub_func_uint64_t_u_u(((((g_199 = g_199) , 0xA2463E9B3E846025LL) , (safe_div_func_int32_t_s_s(l_758, 0x810FC398L))) | l_674), l_690)) ^ l_674) || g_586), l_369.f0))), g_801))) ^ l_674) >= l_674) , p_57) , 249UL) , l_690)))) >= 5L) >= 255UL) , p_57.f6), l_690))));

                    ++l_614;

{
                        int8_t l_818 = 2L;
                        int32_t l_828 = (-7L);
                        int32_t l_829 = 1L;
                        int32_t l_830 = (-1L);
                        int32_t l_832 = (-4L);
                        if (g_30)
                            break;
                        g_238.f2 = (safe_rshift_func_uint16_t_u_s((l_999 | (((g_238.f5 <= ((((((((!(safe_sub_func_uint8_t_u_u((g_801--), (l_614 > (((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((p_58.f0 = l_818), (~0x15F3096FL))), (g_32 != g_66))) == (safe_add_func_uint8_t_u_u(253UL, (safe_div_func_int32_t_s_s((safe_unary_minus_func_int32_t_s(((safe_rshift_func_uint8_t_u_u(((++g_301) != ((l_368 = (g_238.f2 == 1UL)) < 0xD0L)), l_579)) ^ g_528))), 8L))))) , 0xE5B274CA6F72970ELL) && 0x791A8EF8E600BD62LL) >= 0x6BL))))) && l_347) && g_238.f2) && 0xDAL) , l_999) <= g_238.f3) >= g_240) >= g_238.f1)) != g_238.f1) > g_322)), l_999));
                        l_999 = (g_238.f0 <= (safe_div_func_uint8_t_u_u((g_238.f5 && (l_369.f0 = 0x40CEL)), (safe_sub_func_int64_t_s_s((((--g_301) >= ((safe_rshift_func_uint8_t_u_s(255UL, 4)) == (((safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((((1L ^ (safe_div_func_uint32_t_u_u(l_999, (safe_mod_func_int16_t_s_s((l_690 >= (safe_mod_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u(l_690, ((g_238.f5 &= ((safe_mod_func_uint8_t_u_u(l_999, g_238.f3)) , l_655)) , 18446744073709551613UL))) && (-8L)) & g_238.f0), (-1L)))), g_238.f2))))) != g_993) , l_958), 5)), 18446744073709551615UL)) & g_238.f4) > l_757))) | (-1L)), l_690)))));
                    }

                    return p_57.f2;
            }
            for (g_184 = 0; (g_184 >= 5); ++g_184)
            {
                int16_t l_619 = 6L;
                int16_t l_656 = 0xF40CL;
                ++g_928;
                for (g_586 = (-17); (g_586 > (-21)); --g_586)
                {
                    uint64_t l_641 = 0UL;
                    int32_t l_659 = (-1L);
                    for (g_528 = 0; (g_528 == 39); g_528 = safe_add_func_uint16_t_u_u(g_528, 1))
                    {
                        uint64_t l_657 = 1UL;
                        g_238.f5 = 0xC207066FL;
                        l_659 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (g_37 = ((((safe_div_func_uint8_t_u_u(g_80, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(l_655 = (safe_mod_func_uint64_t_u_u(l_641, (g_36 &= ((safe_add_func_int8_t_s_s((l_644 = g_12), (safe_mod_func_int8_t_s_s(p_57.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((p_57.f5 &= l_687), (safe_mod_func_uint8_t_u_u(((~l_619) , p_57.f1), 255UL)))) , g_37) & p_57.f2))))))) != 0xA14CL)))))) <= l_656), l_657))))) && 6UL))) == l_658) <= l_950.f0) <= 1L))) , g_928), l_950.f0)) == g_238.f4) || p_57.f0) | g_586), g_928)) , 0x672551F9L) , 0xA150D49BL);
                    }
                    if (((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u(((p_57.f6 & (safe_sub_func_uint8_t_u_u(p_57.f2, g_528))) < (l_994 |= ((safe_add_func_int8_t_s_s((((g_928 == 0x1D75A18AL) >= (safe_rshift_func_int8_t_s_u(1L, 1))) && (((l_796 , (0x3926L > ((safe_mod_func_int16_t_s_s((l_400 = p_57.f3), g_238.f2)) | g_586))) >= g_238.f6) , (-1L))), l_644)) <= 0L))), 4)), 6)) , 0L))
                    {

{
            struct S0 l_200 = {0x8CAFL};
            int32_t l_205 = (-1L);
            int32_t l_208 = 0x15D7F043L;
            uint16_t l_215 = 0xEBE3L;
            struct S1 l_237 = {4888,4404,-28,3688,-181,0,4061};
            int32_t l_239 = 0x45497A7BL;
            for (l_760 = 14; (l_760 == 54); l_760++)
            {
                uint16_t l_196 = 1UL;
                l_196--;
                l_200 = g_199;
            }
            l_659 = (((safe_sub_func_uint8_t_u_u(g_241, (g_240 , l_950.f0))) < ((l_215 = (g_238.f4 &= (+((((-1L) & ((0xAFL < (((l_367 == ((((g_238.f2 = (l_205 = (l_950 , 8L))) <= ((((((l_641++) ^ g_184) >= l_200.f0) , l_369) , l_369.f0) ^ (-7L))) > l_690) ^ g_184)) , 18446744073709551613UL) > l_68)) ^ l_200.f0)) && l_60) != 0x8890B9DDL)))) <= p_58.f0)) , g_238.f1);
            p_57 = ((((((safe_mod_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s(((g_801 = (safe_lshift_func_int16_t_s_s((((((((safe_sub_func_int32_t_s_s(((((((safe_rshift_func_int16_t_s_s((+(g_184 && (g_12 = (-1L)))), (l_690 = g_800))) && (((safe_mod_func_uint16_t_u_u(l_215, (safe_lshift_func_uint8_t_u_s(((l_950.f0 , 1L) , (0x34L != (safe_lshift_func_int8_t_s_s((safe_mod_func_uint64_t_u_u((g_184 >= (safe_add_func_uint64_t_u_u((__undefined == 4294967290UL), g_184))), l_950.f0)), g_238.f5)))), 5)))) | l_205) & 0x8900E08CL)) || l_641) || g_184) <= 0x3DL) < g_240), g_240)) | 0xBFBDL) < g_199.f0) > g_800) != l_950.f0) | l_369.f0) <= 0xDC97BAAAL), 4))) || l_68), g_240)) | l_757) == l_999), l_373)) ^ l_215) ^ g_184) || 1L) , g_241) , l_237);
            l_692++;
        }

                    return l_655;
                    }
                    else
                    {

for (g_80 = 0; (g_80 == 39); g_80 = safe_add_func_uint16_t_u_u(g_80, 1))
                    {
                        uint64_t l_657 = 1UL;
                        g_238.f5 = 0xC207066FL;
                        g_30 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (l_958 = ((((safe_div_func_uint8_t_u_u(l_674, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(l_796 = (safe_mod_func_uint64_t_u_u(l_399, (g_32 &= ((safe_add_func_int8_t_s_s((l_60 = g_12), (safe_mod_func_int8_t_s_s(p_57.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((p_57.f5 &= g_1276), (safe_mod_func_uint8_t_u_u(((~l_400) , p_57.f1), 255UL)))) , l_958) & p_57.f2))))))) != 0xA14CL)))))) <= g_993), l_657))))) && 6UL))) == g_30) <= g_199.f0) <= 1L))) , g_928), g_199.f0)) == g_238.f4) || p_57.f0) | g_66), g_928)) , 0x672551F9L) , 0xA150D49BL);
                    };


                    p_57.f5 = p_57.f3;
                        return l_347;
                    }
                }
            }
            g_241++;
            ++l_674;
        }
        else
        {
            uint8_t l_687 = 2UL;
            uint32_t l_692 = 4294967291UL;
            int32_t l_758 = (-6L);
            int64_t l_759 = 0x10201B5C969F6449LL;
            int32_t l_796 = (-1L);
            int32_t l_797 = 0x66E5B6A1L;
            int32_t l_799 = (-9L);
            for (g_301 = (-14); (g_301 != 49); g_301 = safe_add_func_uint8_t_u_u(g_301, 3))
            {
                int16_t l_690 = (-1L);
                int32_t l_705 = 3L;
                if (((((safe_div_func_uint64_t_u_u((p_57.f0 || ((g_1276 ^= (((((+(safe_rshift_func_int16_t_s_u(((l_687 ^= (((l_373 = (0xEB54L < p_57.f1)) <= g_238.f2) > g_12)) | g_928), g_199.f0))) ^ (safe_mul_func_int16_t_s_s((l_400 = 9L), (18446744073709551606UL >= l_690)))) != 2UL) <= 0x1EL) < g_528)) || p_57.f3)), 18446744073709551614UL)) != 0xAC861C3EL) < g_37) ^ 0L))
                {
                    g_238 = g_238;
                }
                else
                {
                    uint8_t l_715 = 0x80L;
                    int64_t l_741 = 1L;
                    int64_t l_785 = 0x89D08C2D27B3D546LL;
                    int32_t l_798 = (-4L);
                    int32_t l_809 = 0x4B1AA5B2L;
                    int16_t l_831 = 8L;
                    int32_t l_833 = 0x655BBAA5L;
                    int32_t l_834 = 0x1FA30236L;
                    if (l_692)
                    {
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        p_57.f5 &= (!(l_373 = ((+(safe_mod_func_int32_t_s_s(p_57.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(p_57.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(g_238.f3, (((++l_950.f0) | (l_690 > ((g_1276 , (l_705 ^= l_690)) , 0x3CC1CF37L))) != (l_674 == 249UL))))) , l_706), l_950.f0))))) ^ l_674)));
                        g_238 = p_57;
                    }
                    else
                    {
                        uint16_t l_731 = 0UL;
                        uint64_t l_732 = 0xFD49211BAC9527ABLL;
                        uint16_t l_745 = 0x07DBL;
                        p_57.f5 = (((!((((p_57.f0 == (safe_lshift_func_int8_t_s_s(g_928, ((safe_rshift_func_int8_t_s_s((p_57.f2 ^ ((((safe_sub_func_uint64_t_u_u((g_238.f4 &= l_715), (safe_mod_func_int16_t_s_s(((p_57.f4 > 1L) > ((g_37 & ((safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((((l_731 = (0xB1L > (safe_mod_func_uint32_t_u_u((safe_div_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((0xBAL <= l_994), 1UL)) == (-1L)), g_528)) & p_57.f1) == (-1L)) < g_301) && p_57.f0))), l_759)), 0xE6E002D4L)))) || l_732) >= l_732) == l_687), g_238.f3)) == 1UL) & l_370), l_579)) == 0x4FL)) >= p_57.f2)), p_57.f6)))) < l_950.f0) ^ g_238.f6) , g_238.f4)), g_182)) || 0xA8L)))) > 251UL) , g_301) , g_238.f4)) || p_57.f3) && 0L);
                        l_368 ^= (((safe_lshift_func_int8_t_s_s((l_367 || ((safe_unary_minus_func_int16_t_s((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((l_741 ^= g_12), (l_371 |= ((!(safe_mod_func_uint32_t_u_u((g_238.f0 , ((l_745 && (0x58956D07L && (~((l_758 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_732 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((g_39 ^ (((5UL && ((((l_950 = l_950) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & p_57.f0)) >= 4UL) ^ l_958)) , l_950.f0), l_715)), p_57.f0)) <= l_687)) , p_57.f6), g_1276)), g_182)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL)) <= g_238.f0)))) | p_57.f3)), l_687))) >= 0xC1BC967721442813LL)))) ^ g_241), p_57.f6)))) , 0x2FA0L)), 2)) , l_690) >= 1UL);
                        p_57.f4 = (p_57.f2 = 0xA79062E5L);
                        l_579--;
                    }
                    l_705 = (-1L);
                    if ((safe_add_func_uint16_t_u_u((g_238.f2 = (((((((g_238.f2 , l_338) ^ ((+(safe_lshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(p_57.f3, (g_80 == p_57.f1))), 6))) <= (((8L & (l_692 < (((+(safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u((l_705 = p_57.f2))), (safe_add_func_uint64_t_u_u(g_12, 0xC2CA4FFE53744833LL))))) <= (-5L)) | p_57.f3))) & 1UL) < 0x529AL))) || p_57.f0) , p_57.f1) | g_12) , g_12) > p_57.f6)), g_1285)))
                    {
                        uint32_t l_786 = 0xBE94B622L;
                        int8_t l_787 = 0L;
                        int32_t l_788 = 0x65367992L;
                        int32_t l_789 = 0x26FEF397L;
                        int32_t l_790 = 0L;
                        l_786 ^= ((l_950.f0 >= 0UL) <= (safe_div_func_uint8_t_u_u((p_57.f4 && (p_57.f0 = ((((safe_add_func_uint64_t_u_u((p_57.f2 & (+(l_950.f0 |= ((((safe_div_func_int16_t_s_s(((l_785 , 0UL) & l_687), 0x0D89L)) , 0x9F8EAEBA3A833647LL) != l_715) >= l_692)))), l_373)) != 0x9F1F1DE72F8155A5LL) , 65535UL) , p_57.f2))), 0x27L)));

{
        int64_t l_953 = 0x86445DF67443E0CELL;
        struct S0 l_954 = {0xD225L};
        int32_t l_955 = (-1L);
        int32_t l_956 = 6L;
        int32_t l_957 = 1L;
        int32_t l_959 = (-5L);
        int32_t l_960 = 0xFA289949L;
        int32_t l_961 = 0x9CE9722AL;
        int32_t l_962 = 0x4270AC42L;
        int32_t l_963 = 0xE0FAB585L;
        int32_t l_964 = (-1L);
        int32_t l_965 = 9L;
        int32_t l_966 = (-1L);
        l_954 = (((l_799 = (g_13 = l_953)) | (g_38 &= (g_301 | g_238.f0))) , g_199);
        l_954 = g_199;
        --g_301;

{
                        uint32_t l_786 = 0xBE94B622L;
                        int8_t l_787 = 0L;
                        int32_t l_788 = 0x65367992L;
                        int32_t l_789 = 0x26FEF397L;
                        int32_t l_790 = 0L;
                        l_786 ^= ((l_369.f0 >= 0UL) <= (safe_div_func_uint8_t_u_u((p_57.f4 && (p_57.f0 = ((((safe_add_func_uint64_t_u_u((p_57.f2 & (+(l_954.f0 |= ((((safe_div_func_int16_t_s_s(((l_493 , 0UL) & l_367), 0x0D89L)) , 0x9F8EAEBA3A833647LL) != g_69) >= g_241)))), g_377)) != 0x9F1F1DE72F8155A5LL) , 65535UL) , p_57.f2))), 0x27L)));
                        --l_60;
                        g_322--;
                    }

                    l_370 |= ((safe_div_func_uint8_t_u_u(((safe_div_func_uint8_t_u_u((safe_div_func_uint16_t_u_u((--g_928), g_238.f0)), (0x5A0BAD988B54577ELL || (l_962 != (l_369 , (safe_lshift_func_int16_t_s_u((-3L), (g_238.f1 | (safe_add_func_int8_t_s_s(g_238.f3, (safe_sub_func_int32_t_s_s((safe_div_func_int8_t_s_s(((l_760 = ((((safe_div_func_int16_t_s_s((0x7BF8L > ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((l_955 = (g_199 , l_796)), 14)), 6)) >= l_400)), l_799)) && 0xD5682F7CL) <= g_241) == g_69)) >= 65527UL), 251UL)), 0xFC6382EAL)))))))))))) > l_400), l_963)) < 1L);
    }

                    --g_928;
                        g_191--;
                    }
                    else
                    {
                        int8_t l_818 = 2L;
                        int32_t l_828 = (-7L);
                        int32_t l_829 = 1L;
                        int32_t l_830 = (-1L);
                        int32_t l_832 = (-4L);
                        if (l_338)
                            break;

{
                uint16_t l_196 = 1UL;
                l_196--;
                g_21 = g_21;
            }

                    p_57.f2 = (safe_rshift_func_uint16_t_u_s((l_799 | (((p_57.f5 <= ((((((((!(safe_sub_func_uint8_t_u_u((g_191--), (g_928 > (((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((l_950.f0 = l_818), (~0x15F3096FL))), (l_759 != g_12))) == (safe_add_func_uint8_t_u_u(253UL, (safe_div_func_int32_t_s_s((safe_unary_minus_func_int32_t_s(((safe_rshift_func_uint8_t_u_u(((++g_80) != ((l_834 = (p_57.f2 == 1UL)) < 0xD0L)), g_39)) ^ g_182))), 8L))))) , 0xE5B274CA6F72970ELL) && 0x791A8EF8E600BD62LL) >= 0x6BL))))) && l_368) && p_57.f2) && 0xDAL) , g_800) <= p_57.f3) >= g_586) >= p_57.f1)) != p_57.f1) > l_687)), l_68));

{
                    uint32_t l_1238 = 0xACAF4E8DL;
                    int32_t l_1240 = 0L;
                    l_829 = g_67;
                    p_58 = (g_238.f6 , l_369);
                    g_238.f4 &= g_182;
                    if (l_372)
                    {
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;

{
                    uint8_t l_483 = 0xD2L;
                    g_32 = ((((safe_sub_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((g_873--), l_687)), (((safe_div_func_uint32_t_u_u(g_182, 0xF5DC8482L)) > (safe_rshift_func_int16_t_s_u((safe_lshift_func_int16_t_s_s(8L, 6)), 7))) , (((((l_483 < (((l_829 || (safe_add_func_uint64_t_u_u((~((l_829 ^= (((safe_rshift_func_uint16_t_u_u(0xEED5L, g_199.f0)) >= (((safe_lshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u(8UL, g_182)), 0)) & g_238.f4) & 0x20L)) | g_182)) ^ 5L)), g_968))) < 0x0DL) <= l_1248)) | g_182) ^ 1UL) , g_69) == 0xD239F8EEL)))) & 249UL) >= g_238.f6) , g_586);
                }

                    p_57.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, g_182)), (l_1239 = (l_1238 = l_829)))), (p_57.f6 , l_1240)));
                        l_692++;
                    }
                    else
                    {
                        l_1240 &= g_378;
                    }
                }

                    l_705 = (p_57.f0 <= (safe_div_func_uint8_t_u_u((p_57.f5 && (l_950.f0 = 0x40CEL)), (safe_sub_func_int64_t_s_s((((--g_80) >= ((safe_rshift_func_uint8_t_u_s(255UL, 4)) == (((safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((((1L ^ (safe_div_func_uint32_t_u_u(l_338, (safe_mod_func_int16_t_s_s((l_690 >= (safe_mod_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u(l_690, ((g_238.f5 &= ((safe_mod_func_uint8_t_u_u(l_758, p_57.f3)) , l_797)) , 18446744073709551613UL))) && (-8L)) & p_57.f0), (-1L)))), p_57.f2))))) != l_400) , g_37), 5)), 18446744073709551615UL)) & g_238.f4) > g_33))) | (-1L)), l_690)))));
                    }
                }
                l_338 = g_238.f3;
            }
        };


                    if (((((safe_div_func_uint64_t_u_u((g_238.f0 || ((l_367 ^= (((((+(safe_rshift_func_int16_t_s_u(((l_687 ^= (((g_800 = (0xEB54L < g_238.f1)) <= g_238.f2) > g_524)) | g_1285), l_369.f0))) ^ (safe_mul_func_int16_t_s_s((g_993 = 9L), (18446744073709551606UL >= l_690)))) != 2UL) <= 0x1EL) < g_80)) || g_238.f3)), 18446744073709551614UL)) != 0xAC861C3EL) < l_347) ^ 0L))
                {
                    g_238 = g_238;
                }
                else
                {
                    uint8_t l_715 = 0x80L;
                    int64_t l_741 = 1L;
                    int64_t l_785 = 0x89D08C2D27B3D546LL;
                    int32_t l_798 = (-4L);
                    int32_t l_809 = 0x4B1AA5B2L;
                    int16_t l_831 = 8L;
                    int32_t l_833 = 0x655BBAA5L;
                    int32_t l_834 = 0x1FA30236L;
                    if (l_692)
                    {
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        g_238.f5 &= (!(g_800 = ((+(safe_mod_func_int32_t_s_s(g_238.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(g_238.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(g_238.f3, (((++l_950.f0) | (l_690 > ((l_367 , (l_705 ^= l_690)) , 0x3CC1CF37L))) != (l_674 == 249UL))))) , l_706), g_199.f0))))) ^ l_920)));
                        g_238 = g_238;
                    }
                    else
                    {
                        uint16_t l_731 = 0UL;
                        uint64_t l_732 = 0xFD49211BAC9527ABLL;
                        uint16_t l_745 = 0x07DBL;

l_999 ^= (p_57.f5 = (p_57.f2 = (safe_div_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(g_199.f0, (((0x5DL > g_377) != (safe_unary_minus_func_int16_t_s(1L))) == ((((((l_920 > (safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_u(0xCBFBL, 6)) < (safe_add_func_uint32_t_u_u((((safe_sub_func_uint64_t_u_u(((((g_21 = g_21) , 0xA2463E9B3E846025LL) , (safe_div_func_int32_t_s_s(l_796, 0x810FC398L))) | g_80), l_831)) ^ g_80) || g_586), g_199.f0))), g_33))) ^ g_80) >= g_80) , p_57) , 249UL) , l_831)))) >= 5L) >= 255UL) , p_57.f6), l_831))));

                    g_238.f5 = (((!((((g_238.f0 == (safe_lshift_func_int8_t_s_s(g_1285, ((safe_rshift_func_int8_t_s_s((g_238.f2 ^ ((((safe_sub_func_uint64_t_u_u((g_238.f4 &= l_715), (safe_mod_func_int16_t_s_s(((g_238.f4 > 1L) > ((l_347 & ((safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((((l_731 = (0xB1L > (safe_mod_func_uint32_t_u_u((safe_div_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((0xBAL <= l_994), 1UL)) == (-1L)), g_80)) & g_238.f1) == (-1L)) < l_674) && g_238.f0))), g_36)), 0xE6E002D4L)))) || l_732) >= l_732) == l_687), g_238.f3)) == 1UL) & l_373), g_39)) == 0x4FL)) >= g_238.f2)), g_238.f6)))) < l_950.f0) ^ g_238.f6) , g_238.f4)), g_182)) || 0xA8L)))) > 251UL) , l_674) , g_238.f4)) || g_238.f3) && 0L);
                        l_999 ^= (((safe_lshift_func_int8_t_s_s((l_367 || ((safe_unary_minus_func_int16_t_s((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((l_741 ^= g_66), (l_999 |= ((!(safe_mod_func_uint32_t_u_u((g_238.f0 , ((l_745 && (0x58956D07L && (~((l_758 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_732 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((l_399 ^ (((5UL && ((((l_950 = g_199) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & g_238.f0)) >= 4UL) ^ g_571)) , l_950.f0), l_715)), g_238.f0)) <= l_687)) , g_238.f6), g_33)), g_182)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL)) <= g_238.f0)))) | g_238.f3)), g_322))) >= 0xC1BC967721442813LL)))) ^ l_920), g_238.f6)))) , 0x2FA0L)), 2)) , l_690) >= 1UL);
                        g_238.f4 = (g_238.f2 = 0xA79062E5L);

if ((((g_67 |= ((safe_lshift_func_int16_t_s_s((18446744073709551607UL != ((((((((safe_lshift_func_int16_t_s_s(((g_199.f0 < (g_37 = ((safe_sub_func_int64_t_s_s((safe_add_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s((safe_mod_func_int32_t_s_s(l_831, (safe_mod_func_int64_t_s_s((safe_mod_func_uint8_t_u_u(((g_66 |= ((safe_add_func_uint64_t_u_u(((g_80 < ((safe_mod_func_uint64_t_u_u(p_57.f0, (((safe_sub_func_int8_t_s_s(((((g_184 = g_301) > (safe_unary_minus_func_uint64_t_u(0xD039656BC93DCDE7LL))) && ((0x1154443CL ^ ((safe_rshift_func_int16_t_s_s((+(safe_sub_func_int32_t_s_s(g_238.f0, 0xA33F1971L))), 6)) , 0xA1E7029EL)) ^ l_369.f0)) == 0L), 0UL)) || 0xA51DB1AF86CBBD6FLL) , g_586))) , p_58.f0)) == g_238.f0), (-10L))) , l_999)) > l_373), l_831)), g_800)))), 14)) > p_57.f2) && g_188), (-1L))), g_188)) == 0L))) && 1L), g_378)) != g_188) != p_57.f3) > p_58.f0) == l_338) <= 0x48L) > 2UL) != 0x87C43CC6L)), 0)) , p_57.f5)) & g_182) , (-9L)))
                {
                    g_37 |= g_66;
                }
                else
                {
                    g_37 = (g_238.f2 = (p_57.f2 ^= (g_238.f2 |= p_57.f0)));
                    g_238 = g_238;
                }
if ((safe_add_func_uint16_t_u_u((p_57.f2 = (((((((p_57.f2 , l_375) ^ ((+(safe_lshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(p_57.f3, (g_528 == p_57.f1))), 6))) <= (((8L & (l_674 < (((+(safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u((l_705 = p_57.f2))), (safe_add_func_uint64_t_u_u(g_240, 0xC2CA4FFE53744833LL))))) <= (-5L)) | p_57.f3))) & 1UL) < 0x529AL))) || p_57.f0) , p_57.f1) | g_524) , g_524) > p_57.f6)), l_731)))
                    {
                        uint32_t l_786 = 0xBE94B622L;
                        int8_t l_787 = 0L;
                        int32_t l_788 = 0x65367992L;
                        int32_t l_789 = 0x26FEF397L;
                        int32_t l_790 = 0L;
                        l_786 ^= ((g_199.f0 >= 0UL) <= (safe_div_func_uint8_t_u_u((p_57.f4 && (p_57.f0 = ((((safe_add_func_uint64_t_u_u((p_57.f2 & (+(g_21.f0 |= ((((safe_div_func_int16_t_s_s(((l_785 , 0UL) & l_367), 0x0D89L)) , 0x9F8EAEBA3A833647LL) != g_69) >= l_674)))), l_370)) != 0x9F1F1DE72F8155A5LL) , 65535UL) , p_57.f2))), 0x27L)));
                        --l_731;
                        g_69--;
                    }
                    else
                    {
                        int8_t l_818 = 2L;
                        int32_t l_828 = (-7L);
                        int32_t l_829 = 1L;
                        int32_t l_830 = (-1L);
                        int32_t l_832 = (-4L);
                        if (l_375)
                            break;
                        p_57.f2 = (safe_rshift_func_uint16_t_u_s((l_370 | (((p_57.f5 <= ((((((((!(safe_sub_func_uint8_t_u_u((g_69--), (l_731 > (((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((g_21.f0 = l_818), (~0x15F3096FL))), (l_785 != g_240))) == (safe_add_func_uint8_t_u_u(253UL, (safe_div_func_int32_t_s_s((safe_unary_minus_func_int32_t_s(((safe_rshift_func_uint8_t_u_u(((++l_920) != ((g_37 = (p_57.f2 == 1UL)) < 0xD0L)), l_732)) ^ g_968))), 8L))))) , 0xE5B274CA6F72970ELL) && 0x791A8EF8E600BD62LL) >= 0x6BL))))) && l_375) && p_57.f2) && 0xDAL) , g_756) <= p_57.f3) >= g_524) >= p_57.f1)) != p_57.f1) > l_367)), l_798));
                        l_705 = (p_57.f0 <= (safe_div_func_uint8_t_u_u((p_57.f5 && (g_199.f0 = 0x40CEL)), (safe_sub_func_int64_t_s_s((((--l_920) >= ((safe_rshift_func_uint8_t_u_s(255UL, 4)) == (((safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((((1L ^ (safe_div_func_uint32_t_u_u(l_371, (safe_mod_func_int16_t_s_s((g_993 >= (safe_mod_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u(g_993, ((p_57.f5 &= ((safe_mod_func_uint8_t_u_u(l_371, p_57.f3)) , l_796)) , 18446744073709551613UL))) && (-8L)) & p_57.f0), (-1L)))), p_57.f2))))) != g_993) , l_370), 5)), 18446744073709551615UL)) & p_57.f4) > l_715))) | (-1L)), g_993)))));
                    };


                    ;


                    l_994--;
                    }
                    l_705 = (-1L);


for (g_36 = 16; (g_36 != 15); g_36 = safe_sub_func_int32_t_s_s(g_36, 1))
                    {
                        int32_t l_1099 = 0x29D6DC62L;
                        g_378 |= ((safe_add_func_uint16_t_u_u(((safe_div_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_s((l_715 |= p_57.f1), 0)) <= l_400), (((safe_lshift_func_uint16_t_u_u((g_620 |= (((g_571 = g_378) | ((p_57.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((g_993 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((l_371 |= (((safe_add_func_uint64_t_u_u((g_36 < (l_368 = ((p_57.f4 = p_57.f2) < l_374))), 0xB4C6519C0C658331LL)) | p_57.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), l_1099)) , g_620)) > p_57.f4) || p_57.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > p_57.f1)) && g_21.f0) && g_12) & g_800)) ^ g_620) & g_620)) >= 0UL) , l_1099)) != l_367)) || 0x2FL)), g_12)) < p_57.f1) || 4294967294UL))) & l_369.f0), 65535UL)) >= p_57.f4);
                        if (p_57.f1)
                            continue;
                    };


                    p_57.f1 |= ((((safe_sub_func_uint16_t_u_u(g_12, (safe_lshift_func_uint16_t_u_u(1UL, g_315)))) , 0x08EAL) > 0x7146L) == 0x51A9FA1A770123F4LL);


                    if ((safe_add_func_uint16_t_u_u((g_238.f2 = (((((((g_238.f2 , l_373) ^ ((+(safe_lshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(g_238.f3, (l_942 == g_238.f1))), 6))) <= (((8L & (l_692 < (((+(safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u((l_705 = g_238.f2))), (safe_add_func_uint64_t_u_u(g_524, 0xC2CA4FFE53744833LL))))) <= (-5L)) | g_238.f3))) & 1UL) < 0x529AL))) || g_238.f0) , g_238.f1) | g_67) , g_67) > g_238.f6)), g_793)))
                    {
                        uint32_t l_786 = 0xBE94B622L;
                        int8_t l_787 = 0L;
                        int32_t l_788 = 0x65367992L;
                        int32_t l_789 = 0x26FEF397L;
                        int32_t l_790 = 0L;

l_789 &= (((g_240 != 0x8446L) , g_199) , (((l_596 ^ l_369.f0) , ((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u((safe_add_func_int64_t_s_s(((1UL & (safe_rshift_func_int8_t_s_u((safe_add_func_int64_t_s_s((g_968 <= (g_238 , (safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(((((safe_mod_func_uint16_t_u_u(g_238.f3, l_715)) || p_57.f6) ^ l_596) , l_347), 8)) | p_57.f3), 5L)))), l_376)), p_57.f4))) | l_834), 0xCBB7D04007C17F65LL)), l_999)), p_57.f5)) > (-1L))) >= p_58.f0));

                    l_786 ^= ((g_199.f0 >= 0UL) <= (safe_div_func_uint8_t_u_u((g_238.f4 && (g_238.f0 = ((((safe_add_func_uint64_t_u_u((g_238.f2 & (+(l_950.f0 |= ((((safe_div_func_int16_t_s_s(((l_785 , 0UL) & g_322), 0x0D89L)) , 0x9F8EAEBA3A833647LL) != l_715) >= l_692)))), g_800)) != 0x9F1F1DE72F8155A5LL) , 65535UL) , g_238.f2))), 0x27L)));
                        --g_1285;
                        l_910--;
                    }
                    else
                    {
                        int8_t l_818 = 2L;
                        int32_t l_828 = (-7L);
                        int32_t l_829 = 1L;
                        int32_t l_830 = (-1L);
                        int32_t l_832 = (-4L);


if (g_238.f2)
                        {
if (p_57.f2)
                        continue;

                    continue;}

                    g_756 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_994 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((l_760 ^ (((5UL && ((((g_21 = g_21) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & g_238.f0)) >= 4UL) ^ g_30)) , g_21.f0), g_69)), g_238.f0)) <= l_367)) , g_238.f6), g_1276)), g_182)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL);


                    if (l_373)
                            break;

if (l_347)
                            break;

                    g_238.f2 = (safe_rshift_func_uint16_t_u_s((l_799 | (((g_238.f5 <= ((((((((!(safe_sub_func_uint8_t_u_u((l_910--), (g_928 > (((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((l_950.f0 = l_818), (~0x15F3096FL))), (g_32 != g_524))) == (safe_add_func_uint8_t_u_u(253UL, (safe_div_func_int32_t_s_s((safe_unary_minus_func_int32_t_s(((safe_rshift_func_uint8_t_u_u(((++l_674) != ((l_834 = (g_238.f2 == 1UL)) < 0xD0L)), l_399)) ^ g_182))), 8L))))) , 0xE5B274CA6F72970ELL) && 0x791A8EF8E600BD62LL) >= 0x6BL))))) && l_999) && g_238.f2) && 0xDAL) , g_13) <= g_238.f3) >= g_524) >= g_238.f1)) != g_238.f1) > l_367)), g_183));
                        l_705 = (g_238.f0 <= (safe_div_func_uint8_t_u_u((g_238.f5 && (g_199.f0 = 0x40CEL)), (safe_sub_func_int64_t_s_s((((--l_674) >= ((safe_rshift_func_uint8_t_u_s(255UL, 4)) == (((safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((((1L ^ (safe_div_func_uint32_t_u_u(g_65, (safe_mod_func_int16_t_s_s((l_690 >= (safe_mod_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u(l_690, ((g_238.f5 &= ((safe_mod_func_uint8_t_u_u(l_758, g_238.f3)) , l_797)) , 18446744073709551613UL))) && (-8L)) & g_238.f0), (-1L)))), g_238.f2))))) != g_993) , l_373), 5)), 18446744073709551615UL)) & g_238.f4) > g_188))) | (-1L)), l_690)))));
                    }
                }
                l_373 = g_238.f3;
            }
        }

                    l_367--;

for (g_21.f0 = 0; (g_21.f0 != 25); g_21.f0 = safe_add_func_int64_t_s_s(g_21.f0, 8))
        {
            uint32_t l_163 = 0UL;
            int32_t l_168 = 0x35FECE65L;
            int32_t l_185 = 1L;
            int32_t l_186 = 0xCCA4C161L;
            int32_t l_187 = 5L;
            g_1249 ^= (g_67 == ((safe_mod_func_int16_t_s_s(((safe_div_func_uint64_t_u_u(((0x23B04249L >= (safe_mod_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s(((((g_199 = l_950) , g_199) , (safe_lshift_func_uint16_t_u_s((++l_163), (safe_mod_func_uint32_t_u_u(l_168, (safe_div_func_int32_t_s_s((g_524 > ((g_199.f0 |= (safe_sub_func_uint64_t_u_u((safe_add_func_int32_t_s_s((65530UL | (safe_div_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(0x88AFL, (safe_add_func_int16_t_s_s((((l_950 = g_21) , (-10L)) & 0xC4A096ABL), 0xBEFCL)))), g_39))), g_12)), l_958))) ^ 0x3F1CL)), 0xBE4CFF9CL))))))) < l_373), 7)) | p_57.f2) || g_322), g_184))) != 0x1A2308598B864A24LL), p_57.f5)) < 1L), 0x8ABAL)) < g_184));
            --g_801;
            g_188++;
        }
{
                if ((g_238.f5 = (0xCDL ^ g_238.f1)))
                {
                    return g_967;
                }
                else
                {
                    return g_993;
                }
            }

                    ;


                    g_21 = g_21;
        ++g_39;

{
                uint16_t l_614 = 0x585DL;
                ++l_614;
                return g_238.f2;
            }

                    l_999 &= ((g_183 | (safe_mod_func_int16_t_s_s(((func_44(((safe_rshift_func_int16_t_s_s((g_967 |= p_57.f3), (g_38 <= 6L))) , (safe_sub_func_uint64_t_u_u(l_373, l_50)))) , p_57.f2) | ((safe_sub_func_int8_t_s_s(0xA4L, p_57.f3)) <= l_373)), l_373))) || (-1L));
    }

                    l_369 = p_58;
                    }
                    return l_338;
                }
            }
        }
        g_378--;
    }
    else
    {
        int32_t l_385 = 0x98C9DF27L;
        int32_t l_394 = 0x473E9E37L;
        uint8_t l_418 = 3UL;
        int16_t l_445 = 1L;
        struct S1 l_508 = {3178,1820,-21,10076,-140,-0,3313};
        int64_t l_515 = 0x5848DA2AB3D2CF8FLL;
        uint64_t l_516 = 0x8E7615848DB85ECELL;
        int32_t l_518 = 0x2938310BL;
        int32_t l_525 = 0x94A3069EL;
        int32_t l_526 = 3L;
        uint64_t l_535 = 0UL;

g_377 |= (((g_377 ^ (safe_rshift_func_int16_t_s_s(0x7DA3L, 14))) , (safe_lshift_func_int8_t_s_u(g_1285, 1))) != (safe_unary_minus_func_int16_t_s((g_65 = 0xBB70L))));



l_375 |= (((g_65 ^ (safe_rshift_func_int16_t_s_s(0x7DA3L, 14))) , (safe_lshift_func_int8_t_s_u(g_1285, 1))) != (safe_unary_minus_func_int16_t_s((l_525 = 0xBB70L))));


                    if ((l_60 , ((l_68 & ((((safe_mod_func_int32_t_s_s(l_385, ((safe_sub_func_int8_t_s_s(g_182, ((((((g_238 = g_238) , g_21) , (p_58.f0 |= (safe_lshift_func_int8_t_s_u((safe_mod_func_uint8_t_u_u((safe_sub_func_uint64_t_u_u((((g_199.f0--) & (((0xF021F418L ^ (safe_rshift_func_int8_t_s_u(((7UL > ((p_57.f4 ^ (-5L)) , g_39)) <= l_385), g_184))) > p_57.f1) ^ l_399)) ^ g_378), g_12)), l_394)), l_68)))) > 0xFF94L) ^ g_188) <= l_400))) , g_199.f0))) , p_57.f4) >= g_240) >= g_315)) , l_394)))
        {
            uint32_t l_417 = 0xCC00055AL;
            int32_t l_517 = 0x91FB3B16L;
            int32_t l_520 = 0x36D4D769L;
            int32_t l_522 = 5L;
            int32_t l_523 = 0x43AADE25L;
lbl_464:
            g_238.f4 ^= 0x1529816DL;
lbl_465:
            if ((g_39 >= (safe_mod_func_uint16_t_u_u((0x6EL <= (((safe_sub_func_uint8_t_u_u((g_188 = (g_238.f5 & ((((p_57.f2 != ((((safe_sub_func_uint16_t_u_u((safe_mod_func_uint64_t_u_u((safe_lshift_func_uint8_t_u_u(((((+(safe_sub_func_uint8_t_u_u(g_65, (((!(safe_rshift_func_int16_t_s_u(l_417, 8))) && 0x6568L) <= l_417)))) > (0x25CBE153FDD8CB67LL | p_57.f3)) >= l_418) || l_385), l_417)), g_182)), 0x7032L)) & 4294967295UL) | 0xD45DFDD5CE231998LL) != l_60)) , l_418) <= 0x13L) == p_57.f6))), p_57.f0)) >= l_418) , l_385)), l_418))))
            {
                uint16_t l_419 = 4UL;
                return l_419;
            }
            else
            {
                uint32_t l_443 = 0xC9CAAB59L;
                int32_t l_444 = (-8L);
                int32_t l_446 = 5L;
                struct S1 l_463 = {21369,3168,-17,1223,267,0,5323};
                if (((safe_mod_func_int32_t_s_s((g_37 , (((safe_lshift_func_int8_t_s_s((safe_div_func_int64_t_s_s((safe_mod_func_int64_t_s_s(((l_373 , (((g_238.f5 < ((safe_sub_func_int32_t_s_s((g_69 <= ((safe_div_func_int64_t_s_s(((l_444 = ((safe_lshift_func_uint16_t_u_u(p_57.f1, 9)) <= ((((g_238.f1 ^ (l_443 = ((((!(((+(-5L)) >= 0x2077L) | (((safe_lshift_func_uint16_t_u_s((safe_unary_minus_func_int32_t_s((safe_lshift_func_uint16_t_u_u(0x3FE3L, 15)))), 9)) < 0x3ED2BC827CFBFAACLL) == 0UL))) <= 0xEE3FL) && 0xCB01CDCFF5673DEALL) , l_399))) | 0x05B4L) , g_21.f0) > 0xF83382B7L))) == 1UL), g_240)) <= 0xF8L)), l_445)) , g_301)) , l_417) >= l_394)) , 0x1B3F29B522290BD6LL), p_57.f3)), p_57.f5)), l_446)) == g_65) <= 0x80L)), l_445)) == g_37))
                {
                    uint16_t l_451 = 0x721EL;
                    int32_t l_453 = (-1L);
                    p_57.f2 = ((l_444 |= (((g_38 ^ (safe_rshift_func_int16_t_s_s(0x7DA3L, 14))) , (safe_lshift_func_int8_t_s_u(l_451, 1))) != (safe_unary_minus_func_int16_t_s((l_453 = 0xBB70L))))) & ((safe_mod_func_uint8_t_u_u((safe_div_func_uint32_t_u_u((!((((p_57.f4 , l_417) < p_57.f0) , (safe_div_func_int64_t_s_s((g_36 = ((safe_add_func_uint64_t_u_u(p_57.f6, (g_32 = 0L))) >= (-1L))), l_394))) , 0x779BL)), l_417)), p_57.f6)) > p_57.f3));
                }
                else
                {
                    p_58 = g_21;
                    g_238 = l_463;
                }
                if (g_183)
                    goto lbl_464;
            }
            if (p_57.f3)
            {
                int8_t l_468 = 1L;
                if (g_21.f0)
                    goto lbl_465;
                l_468 ^= ((++p_58.f0) <= p_57.f3);
                for (g_301 = 18; (g_301 > 20); g_301 = safe_add_func_int32_t_s_s(g_301, 2))
                {
                    uint8_t l_483 = 0xD2L;
                    l_493 = ((((safe_sub_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((g_378--), g_191)), (((safe_div_func_uint32_t_u_u(l_417, 0xF5DC8482L)) > (safe_rshift_func_int16_t_s_u((safe_lshift_func_int16_t_s_s(8L, 6)), 7))) , (((((l_483 < (((l_385 || (safe_add_func_uint64_t_u_u((~((l_68 ^= (((safe_rshift_func_uint16_t_u_u(0xEED5L, g_199.f0)) >= (((safe_lshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u(8UL, l_417)), 0)) & p_57.f4) & 0x20L)) | g_80)) ^ 5L)), g_301))) < 0x0DL) <= g_65)) | l_417) ^ 1UL) , g_188) == 0xD239F8EEL)))) & 249UL) >= p_57.f6) , g_66);
                }
            }
            else
            {
                int32_t l_519 = (-1L);
                int32_t l_521 = 0xC5583EF5L;
                l_518 &= ((0L < (((((safe_add_func_int64_t_s_s(((safe_lshift_func_int16_t_s_s(((-10L) | l_385), ((safe_sub_func_int16_t_s_s((l_517 = (((l_394 |= ((safe_sub_func_int32_t_s_s(((safe_sub_func_int16_t_s_s(p_57.f2, (l_515 = (safe_sub_func_uint8_t_u_u(g_315, (((p_57 , p_57.f1) , l_508) , (safe_add_func_uint8_t_u_u((safe_sub_func_uint64_t_u_u(((((g_301++) && (g_301 != 0xAEL)) ^ 0x9714L) <= 0xD7EAL), 0x1FBFD773E599F898LL)), g_33)))))))) < p_57.f5), l_400)) < g_315)) && 0x22L) ^ l_516)), g_184)) != p_57.f5))) , g_240), g_80)) != l_417) > g_188) || g_183) <= p_58.f0)) || p_57.f2);
                g_528++;

{
        int32_t l_284 = 0xEE263D41L;
        uint64_t l_288 = 18446744073709551615UL;
        int32_t l_290 = 9L;
        int32_t l_296 = 0xC6978A9AL;
        int32_t l_297 = 0x9ADCCFBDL;
        int32_t l_299 = 8L;
        int32_t l_300 = 0x80C45391L;
        struct S0 l_311 = {1UL};
        struct S1 l_314 = {15034,7901,-16,6783,-510,-0,5803};
        if ((((safe_lshift_func_uint8_t_u_s((g_188 = (safe_rshift_func_uint8_t_u_s(g_968, 2))), g_240)) && (((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_int8_t_s_s(((((p_57 = p_57) , ((g_571 = (safe_add_func_int64_t_s_s(((((g_32 != g_993) == (((safe_rshift_func_int16_t_s_u((3UL == (((l_284 <= 0xB1A0L) != (((((safe_rshift_func_uint8_t_u_u(((!g_993) , g_524), 5)) > l_288) & (-10L)) , 0xE1L) > g_80)) , g_322)), g_240)) & 5L) || 0xA2B9BF124FD362E7LL)) == g_240) , (-1L)), l_288))) && g_571)) & l_284) >= 0x62L), l_288)) , g_240))) >= g_322) | 1L)) , g_993))
        {
            int8_t l_295 = (-5L);

{
                    return l_373;
                }

                    --g_80;
            p_57.f4 &= ((((l_394 &= 0x62L) <= ((g_30 = ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^ (l_523 = l_521)) & (safe_rshift_func_uint16_t_u_s(0x2310L, 10))) , ((l_523 ^ ((g_571 &= (l_295 != ((((g_993 = ((l_68 & ((~((((l_311 , (g_524 ^ p_57.f3)) > g_524) != 0x2A7A2EF32379F2B3LL) != l_284)) && l_295)) && l_295)) >= 0L) , 0x1AL) | 0x83L))) >= p_57.f2)) != g_524)) <= l_296) && (-1L)) || p_57.f1) , g_67)) | 1UL)) > 5L) ^ 0xDF8CL);
        }
        else
        {
            p_57.f2 = (-4L);
            for (l_300 = (-19); (l_300 > 10); l_300 = safe_add_func_uint16_t_u_u(l_300, 6))
            {
                p_57 = l_314;
            }
        }
    }

                    p_57.f4 &= (safe_sub_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(l_535, 0x32B0L)), 0x8C89L));
            }
        }
        else
        {
            int16_t l_561 = (-8L);
            struct S0 l_562 = {0x698AL};
            uint32_t l_576 = 0x50148CBAL;
            for (l_400 = 0; (l_400 != (-23)); l_400 = safe_sub_func_uint64_t_u_u(l_400, 6))
            {
                uint32_t l_559 = 4294967295UL;
                int32_t l_560 = 9L;
                g_65 = ((18446744073709551615UL && (((safe_unary_minus_func_int64_t_s((safe_add_func_uint16_t_u_u((p_58.f0 == (safe_div_func_int8_t_s_s((safe_mod_func_int64_t_s_s((+((((p_57.f0 || (((g_238.f5 , ((safe_mod_func_int8_t_s_s((((((safe_sub_func_int64_t_s_s(0xF9CED6740F5759D8LL, g_33)) | 0x5CB0L) && (-1L)) < ((g_301 = (safe_mod_func_uint16_t_u_u((+((safe_div_func_int32_t_s_s(((l_559 = (safe_sub_func_uint64_t_u_u(((safe_mod_func_int64_t_s_s(((p_57 , g_241) >= 0x34E3L), 0x02128AB49729E21BLL)) && l_68), (-1L)))) != p_57.f1), (-5L))) > p_57.f1)), p_58.f0))) <= 4L)) | 0xB4A67218FBF74A89LL), l_560)) , g_37)) != 0xF6L) || l_561)) >= g_12) ^ 0x08A696AFL) > g_67)), 1UL)), 0x24L))), l_400)))) & l_375) > g_65)) & p_58.f0);
            }

for (g_301 = 0; (g_301 >= 10); ++g_301)
        {
            g_199 = (l_859 , g_199);
        };


                    l_562 = l_562;


for (l_400 = 0; (l_400 != (-23)); l_400 = safe_sub_func_uint64_t_u_u(l_400, 6))
            {
                uint32_t l_559 = 4294967295UL;
                int32_t l_560 = 9L;
                l_385 = ((18446744073709551615UL && (((safe_unary_minus_func_int64_t_s((safe_add_func_uint16_t_u_u((g_21.f0 == (safe_div_func_int8_t_s_s((safe_mod_func_int64_t_s_s((+((((g_238.f0 || (((g_238.f5 , ((safe_mod_func_int8_t_s_s((((((safe_sub_func_int64_t_s_s(0xF9CED6740F5759D8LL, g_322)) | 0x5CB0L) && (-1L)) < ((l_920 = (safe_mod_func_uint16_t_u_u((+((safe_div_func_int32_t_s_s(((l_559 = (safe_sub_func_uint64_t_u_u(((safe_mod_func_int64_t_s_s(((g_238 , l_942) >= 0x34E3L), 0x02128AB49729E21BLL)) && l_958), (-1L)))) != g_238.f1), (-5L))) > g_238.f1)), g_21.f0))) <= 4L)) | 0xB4A67218FBF74A89LL), l_560)) , g_756)) != 0xF6L) || l_400)) >= g_586) ^ 0x08A696AFL) > g_66)), 1UL)), 0x24L))), l_400)))) & l_525) > l_385)) & g_21.f0);
            };



for (l_562.f0 = 0; (l_562.f0 != 25); l_562.f0 = safe_add_func_int64_t_s_s(l_562.f0, 8))
        {
            uint32_t l_163 = 0UL;
            int32_t l_168 = 0x35FECE65L;
            int32_t l_185 = 1L;
            int32_t l_186 = 0xCCA4C161L;
            int32_t l_187 = 5L;
            g_301 ^= (g_12 == ((safe_mod_func_int16_t_s_s(((safe_div_func_uint64_t_u_u(((0x23B04249L >= (safe_mod_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s(((((g_21 = g_21) , g_21) , (safe_lshift_func_uint16_t_u_s((++l_163), (safe_mod_func_uint32_t_u_u(l_168, (safe_div_func_int32_t_s_s((g_67 > ((l_950.f0 |= (safe_sub_func_uint64_t_u_u((safe_add_func_int32_t_s_s((65530UL | (safe_div_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(0x88AFL, (safe_add_func_int16_t_s_s((((g_21 = l_562) , (-10L)) & 0xC4A096ABL), 0xBEFCL)))), l_760))), g_240)), l_373))) ^ 0x3F1CL)), 0xBE4CFF9CL))))))) < g_38), 7)) | l_508.f2) || g_322), g_993))) != 0x1A2308598B864A24LL), l_508.f5)) < 1L), 0x8ABAL)) < g_993));
            --g_322;
            l_910++;
        };


                    g_238.f4 &= ((((g_792 &= 0x62L) <= ((g_30 = ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^ (l_375 = g_967)) & (safe_rshift_func_uint16_t_u_s(0x2310L, 10))) , ((g_13 ^ ((g_967 &= (g_524 != ((((l_400 = ((g_377 & ((~((((l_562 , (g_67 ^ g_238.f3)) > g_67) != 0x2A7A2EF32379F2B3LL) != l_373)) && g_524)) && g_524)) >= 0L) , 0x1AL) | 0x83L))) >= g_238.f2)) != g_67)) <= g_30) && (-1L)) || g_238.f1) , g_240)) | 1UL)) > 5L) ^ 0xDF8CL);


l_508.f4 &= (safe_sub_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(l_399, 0x32B0L)), 0x8C89L));

                    for (g_38 = 0; (g_38 == 14); g_38 = safe_add_func_uint16_t_u_u(g_38, 7))
            {
                int64_t l_568 = 0x5C343ED73A8738E9LL;

if (l_373)
                    {
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;
                        l_508.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, g_182)), (l_1239 = (g_301 = l_375)))), (l_508.f6 , g_756)));
                        g_301++;
                    }
                    else
                    {

for (g_241 = 0; (g_241 == 39); g_241 = safe_add_func_uint16_t_u_u(g_241, 1))
                    {
                        uint64_t l_657 = 1UL;
                        g_238.f5 = 0xC207066FL;
                        l_526 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (g_756 = ((((safe_div_func_uint8_t_u_u(g_378, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(l_958 = (safe_mod_func_uint64_t_u_u(l_535, (g_527 &= ((safe_add_func_int8_t_s_s((g_315 = g_66), (safe_mod_func_int8_t_s_s(g_238.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((g_238.f5 &= g_188), (safe_mod_func_uint8_t_u_u(((~l_445) , g_238.f1), 255UL)))) , g_756) & g_238.f2))))))) != 0xA14CL)))))) <= l_445), l_657))))) && 6UL))) == l_373) <= p_58.f0) <= 1L))) , g_315), p_58.f0)) == g_238.f4) || g_238.f0) | g_66), g_315)) , 0x672551F9L) , 0xA150D49BL);
                    };


                    g_756 &= l_920;
                    };


                    g_238.f2 = (((p_57.f1 &= (7L & ((g_527 ^= ((((g_39 = ((l_561 != 0x4CL) == (+(((-9L) == l_568) > 0UL)))) <= ((((safe_mod_func_uint8_t_u_u((g_69 = p_57.f0), g_183)) <= 0xA1BF90C52FB11BB9LL) <= 1UL) & g_378)) , g_238) , g_571)) <= g_238.f2))) <= p_57.f5) <= p_57.f2);
                g_65 = (~0x67D3L);
                if (p_57.f4)
                    {
{
                    uint8_t l_715 = 0x80L;
                    int64_t l_741 = 1L;
                    int64_t l_785 = 0x89D08C2D27B3D546LL;
                    int32_t l_798 = (-4L);
                    int32_t l_809 = 0x4B1AA5B2L;
                    int16_t l_831 = 8L;
                    int32_t l_833 = 0x655BBAA5L;
                    int32_t l_834 = 0x1FA30236L;
                    if (g_1249)
                    {
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        l_508.f5 &= (!(l_373 = ((+(safe_mod_func_int32_t_s_s(l_508.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(l_508.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(l_508.f3, (((++l_950.f0) | (g_993 > ((g_322 , (g_967 ^= g_993)) , 0x3CC1CF37L))) != (l_576 == 249UL))))) , l_706), l_950.f0))))) ^ g_80)));
                        l_508 = l_508;
                    }
                    else
                    {
                        uint16_t l_731 = 0UL;
                        uint64_t l_732 = 0xFD49211BAC9527ABLL;
                        uint16_t l_745 = 0x07DBL;
                        l_508.f5 = (((!((((l_508.f0 == (safe_lshift_func_int8_t_s_s(g_315, ((safe_rshift_func_int8_t_s_s((l_508.f2 ^ ((((safe_sub_func_uint64_t_u_u((l_508.f4 &= l_715), (safe_mod_func_int16_t_s_s(((l_508.f4 > 1L) > ((l_373 & ((safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((((l_731 = (0xB1L > (safe_mod_func_uint32_t_u_u((safe_div_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((0xBAL <= l_399), 1UL)) == (-1L)), g_873)) & l_508.f1) == (-1L)) < g_241) && l_508.f0))), g_36)), 0xE6E002D4L)))) || l_732) >= l_732) == l_418), l_508.f3)) == 1UL) & g_791), g_39)) == 0x4FL)) >= l_508.f2)), l_508.f6)))) < l_950.f0) ^ l_508.f6) , l_508.f4)), l_920)) || 0xA8L)))) > 251UL) , g_241) , l_508.f4)) || l_508.f3) && 0L);
                        l_373 ^= (((safe_lshift_func_int8_t_s_s((l_418 || ((safe_unary_minus_func_int16_t_s((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((l_741 ^= g_586), (l_373 |= ((!(safe_mod_func_uint32_t_u_u((l_508.f0 , ((l_745 && (0x58956D07L && (~((g_13 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_732 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((l_399 ^ (((5UL && ((((l_950 = l_950) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & l_508.f0)) >= 4UL) ^ g_13)) , l_950.f0), l_715)), l_508.f0)) <= l_418)) , l_508.f6), g_69)), l_920)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL)) <= l_508.f0)))) | l_508.f3)), g_191))) >= 0xC1BC967721442813LL)))) ^ g_80), l_508.f6)))) , 0x2FA0L)), 2)) , g_993) >= 1UL);
                        l_508.f4 = (l_508.f2 = 0xA79062E5L);

{
            int64_t l_1216 = 0x5E4A5199B7ADA9F3LL;
            int32_t l_1217 = 0x973A592CL;
            int8_t l_1229 = 0xA6L;
            int32_t l_1247 = 0x75C172F7L;
            int64_t l_1284 = 0xD8A6352B8836645ELL;
            g_37 |= ((l_508.f5 | (l_596 = (g_791 < ((0x237022BDB339B958LL | ((~((l_1216 = l_562.f0) <= l_1217)) >= (g_571 >= l_508.f0))) ^ ((safe_rshift_func_int8_t_s_u((safe_add_func_int64_t_s_s(l_562.f0, (safe_sub_func_int32_t_s_s((-1L), l_508.f6)))), 1)) ^ 0x09L))))) || g_571);
            for (p_58.f0 = 2; (p_58.f0 >= 18); p_58.f0 = safe_add_func_int64_t_s_s(p_58.f0, 4))
            {
                uint32_t l_1230 = 0xC2612157L;
                int32_t l_1241 = 0x1C3A57D2L;
                int32_t l_1244 = 0x0E65AD9AL;
                int32_t l_1246 = 1L;
                g_238 = l_508;
                l_1217 &= (g_791 = (safe_lshift_func_uint8_t_u_s((+(l_942 < (-1L))), 6)));
                if (l_375)
                {
                    uint32_t l_1238 = 0xACAF4E8DL;
                    int32_t l_1240 = 0L;
                    g_791 = l_1229;
                    p_58 = (l_508.f6 , l_562);
                    l_508.f4 &= l_1230;
                    if (g_571)
                    {
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;
                        l_508.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, l_1230)), (l_1239 = (l_1238 = g_37)))), (l_508.f6 , l_1240)));
                        g_241++;
                    }
                    else
                    {
                        l_1240 &= g_528;
                    }
                }
                else
                {
                    uint64_t l_1260 = 0xF5DC1668590A4472LL;
                    int32_t l_1273 = (-1L);
                    int32_t l_1274 = 0xEA32A638L;
                    int32_t l_1275 = 0x813DFFBBL;
                    l_508.f5 = (safe_mod_func_uint8_t_u_u((1UL == (safe_sub_func_uint8_t_u_u(((g_240 && g_238.f4) > ((safe_div_func_uint64_t_u_u(l_715, l_715)) <= (((l_1260 , (safe_rshift_func_uint8_t_u_u(l_508.f4, 5))) != (--g_241)) && (((g_524 & (l_508.f2 = (l_1217 ^= (safe_mod_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(0x17F9FA19L, g_32)), 1)) && l_508.f5), 0xD66C9ADCL))))) | p_58.f0) & l_561)))), g_238.f5))), g_240));
                    for (g_793 = 3; (g_793 != 32); g_793 = safe_add_func_uint32_t_u_u(g_793, 4))
                    {
                        ++g_191;
                        if (l_508.f1)
                            break;
                        if (g_13)
                            continue;
                        l_508.f5 ^= (safe_mod_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(0xAEL, (0x4461L | (l_834 != (l_1217 = (l_1284 == (l_508.f0 = g_240))))))), l_1273));
                    }
                }
            }
        }

                    l_596--;
                    }
                    g_967 = (-1L);
                    if ((safe_add_func_uint16_t_u_u((l_508.f2 = (((((((l_508.f2 , l_394) ^ ((+(safe_lshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(l_508.f3, (l_920 == l_508.f1))), 6))) <= (((8L & (g_1249 < (((+(safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u((g_967 = l_508.f2))), (safe_add_func_uint64_t_u_u(g_586, 0xC2CA4FFE53744833LL))))) <= (-5L)) | l_508.f3))) & 1UL) < 0x529AL))) || l_508.f0) , l_508.f1) | g_12) , g_12) > l_508.f6)), g_315)))
                    {
                        uint32_t l_786 = 0xBE94B622L;
                        int8_t l_787 = 0L;
                        int32_t l_788 = 0x65367992L;
                        int32_t l_789 = 0x26FEF397L;
                        int32_t l_790 = 0L;
                        l_786 ^= ((l_950.f0 >= 0UL) <= (safe_div_func_uint8_t_u_u((l_508.f4 && (l_508.f0 = ((((safe_add_func_uint64_t_u_u((l_508.f2 & (+(l_950.f0 |= ((((safe_div_func_int16_t_s_s(((l_785 , 0UL) & g_191), 0x0D89L)) , 0x9F8EAEBA3A833647LL) != l_715) >= g_1249)))), l_373)) != 0x9F1F1DE72F8155A5LL) , 65535UL) , l_508.f2))), 0x27L)));
                        --g_928;
                        g_322--;
                    }
                    else
                    {
                        int8_t l_818 = 2L;
                        int32_t l_828 = (-7L);
                        int32_t l_829 = 1L;
                        int32_t l_830 = (-1L);
                        int32_t l_832 = (-4L);
                        if (l_394)
                            break;
                        l_508.f2 = (safe_rshift_func_uint16_t_u_s((g_37 | (((l_508.f5 <= ((((((((!(safe_sub_func_uint8_t_u_u((g_322--), (g_620 > (((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((l_950.f0 = l_818), (~0x15F3096FL))), (l_568 != g_586))) == (safe_add_func_uint8_t_u_u(253UL, (safe_div_func_int32_t_s_s((safe_unary_minus_func_int32_t_s(((safe_rshift_func_uint8_t_u_u(((++l_920) != ((l_834 = (l_508.f2 == 1UL)) < 0xD0L)), l_399)) ^ l_920))), 8L))))) , 0xE5B274CA6F72970ELL) && 0x791A8EF8E600BD62LL) >= 0x6BL))))) && l_373) && l_508.f2) && 0xDAL) , g_791) <= l_508.f3) >= g_12) >= l_508.f1)) != l_508.f1) > g_191)), l_526));
                        g_967 = (l_508.f0 <= (safe_div_func_uint8_t_u_u((l_508.f5 && (l_950.f0 = 0x40CEL)), (safe_sub_func_int64_t_s_s((((--l_920) >= ((safe_rshift_func_uint8_t_u_s(255UL, 4)) == (((safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((((1L ^ (safe_div_func_uint32_t_u_u(l_373, (safe_mod_func_int16_t_s_s((g_993 >= (safe_mod_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u(g_993, ((l_508.f5 &= ((safe_mod_func_uint8_t_u_u(g_13, l_508.f3)) , g_38)) , 18446744073709551613UL))) && (-8L)) & l_508.f0), (-1L)))), l_508.f2))))) != g_993) , l_373), 5)), 18446744073709551615UL)) & l_508.f4) > g_33))) | (-1L)), g_993)))));
                    }
                }


{
            int32_t l_870 = (-1L);
            l_859 = (g_238.f3 , (safe_rshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(g_801, 13)), l_757)), 10)));
            return l_870;
        }

                    break;}

if (g_1249)
                    {
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        g_238.f5 &= (!(l_859 = ((+(safe_mod_func_int32_t_s_s(g_238.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(g_238.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(g_238.f3, (((++l_950.f0) | (g_184 > ((g_1276 , (g_37 ^= g_184)) , 0x3CC1CF37L))) != (g_1249 == 249UL))))) , l_706), l_950.f0))))) ^ g_1249)));
                        g_238 = g_238;
                    }
                    else
                    {
                        uint16_t l_731 = 0UL;
                        uint64_t l_732 = 0xFD49211BAC9527ABLL;
                        uint16_t l_745 = 0x07DBL;
                        g_238.f5 = (((!((((g_238.f0 == (safe_lshift_func_int8_t_s_s(l_60, ((safe_rshift_func_int8_t_s_s((g_238.f2 ^ ((((safe_sub_func_uint64_t_u_u((g_238.f4 &= g_1276), (safe_mod_func_int16_t_s_s(((g_238.f4 > 1L) > ((g_792 & ((safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((((l_731 = (0xB1L > (safe_mod_func_uint32_t_u_u((safe_div_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((0xBAL <= l_596), 1UL)) == (-1L)), g_968)) & g_238.f1) == (-1L)) < g_968) && g_238.f0))), l_493)), 0xE6E002D4L)))) || l_732) >= l_732) == g_322), g_238.f3)) == 1UL) & g_800), l_596)) == 0x4FL)) >= g_238.f2)), g_238.f6)))) < l_950.f0) ^ g_238.f6) , g_238.f4)), g_80)) || 0xA8L)))) > 251UL) , g_968) , g_238.f4)) || g_238.f3) && 0L);
                        l_859 ^= (((safe_lshift_func_int8_t_s_s((g_801 || ((safe_unary_minus_func_int16_t_s((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((l_493 ^= g_524), (l_394 |= ((!(safe_mod_func_uint32_t_u_u((g_238.f0 , ((l_745 && (0x58956D07L && (~((l_373 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_732 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((l_535 ^ (((5UL && ((((l_950 = l_950) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & g_238.f0)) >= 4UL) ^ g_183)) , l_950.f0), g_1276)), g_238.f0)) <= g_322)) , g_238.f6), g_1276)), g_80)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL)) <= g_238.f0)))) | g_238.f3)), g_801))) >= 0xC1BC967721442813LL)))) ^ l_942), g_238.f6)))) , 0x2FA0L)), 2)) , g_184) >= 1UL);
                        g_238.f4 = (g_238.f2 = 0xA79062E5L);
                        l_535--;
                    };


                    p_57.f4 &= (g_238.f5 ^= ((!((((((safe_add_func_uint16_t_u_u((((g_238.f6 & (((((l_576 < (safe_lshift_func_uint16_t_u_u(l_579, (g_524 > g_67)))) < (safe_mod_func_int32_t_s_s((safe_div_func_uint64_t_u_u((safe_lshift_func_uint8_t_u_u((1L & (g_36 < (0x7F8CL | (l_375 = g_238.f3)))), g_586)), l_400)), g_182))) < 4UL) , g_301) <= g_32)) ^ g_315) <= (-4L)), p_57.f0)) , p_57.f1) != 1L) <= l_568) & p_57.f1) && l_418)) || 0UL));
            }

for (l_400 = 0; (l_400 != (-23)); l_400 = safe_sub_func_uint64_t_u_u(l_400, 6))
            {
                uint32_t l_559 = 4294967295UL;
                int32_t l_560 = 9L;

l_518 ^= (safe_mod_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(0x17F9FA19L, g_527)), 1)) && l_508.f5), 0xD66C9ADCL));


                    g_967 = ((18446744073709551615UL && (((safe_unary_minus_func_int64_t_s((safe_add_func_uint16_t_u_u((l_950.f0 == (safe_div_func_int8_t_s_s((safe_mod_func_int64_t_s_s((+((((p_57.f0 || (((l_508.f5 , ((safe_mod_func_int8_t_s_s((((((safe_sub_func_int64_t_s_s(0xF9CED6740F5759D8LL, l_757)) | 0x5CB0L) && (-1L)) < ((l_942 = (safe_mod_func_uint16_t_u_u((+((safe_div_func_int32_t_s_s(((l_559 = (safe_sub_func_uint64_t_u_u(((safe_mod_func_int64_t_s_s(((p_57 , g_873) >= 0x34E3L), 0x02128AB49729E21BLL)) && g_37), (-1L)))) != p_57.f1), (-5L))) > p_57.f1)), l_950.f0))) <= 4L)) | 0xB4A67218FBF74A89LL), l_560)) , g_756)) != 0xF6L) || g_993)) >= g_240) ^ 0x08A696AFL) > g_240)), 1UL)), 0x24L))), l_400)))) & g_377) > g_967)) & l_950.f0);
            };


                    p_57 = g_238;
        }
    }



{
                    uint32_t l_1238 = 0xACAF4E8DL;
                    int32_t l_1240 = 0L;
                    g_13 = g_66;
                    l_950 = (p_57.f6 , p_58);
                    p_57.f4 &= g_968;
                    if (g_967)
                    {
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;

p_57.f1 &= (7L & ((g_32 ^= ((((l_760 = ((l_400 != 0x4CL) == (+(((-9L) == __undefined) > 0UL)))) <= ((((safe_mod_func_uint8_t_u_u((l_910 = p_57.f0), l_373)) <= 0xA1BF90C52FB11BB9LL) <= 1UL) & g_1249)) , g_238) , l_1240)) <= g_238.f2));


                    g_238.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, g_968)), (l_1239 = (l_1238 = g_791)))), (g_238.f6 , l_1240)));
                        g_241++;
                    }
                    else
                    {

for (g_37 = (-27); (g_37 < 10); ++g_37)
        {
            int8_t l_937 = 5L;
            g_238 = (g_238 = ((l_373 = ((((g_238.f0 > (safe_lshift_func_int8_t_s_u((safe_div_func_uint8_t_u_u((g_620 != (g_756 , ((l_937 = 0xDABBL) || (safe_add_func_int64_t_s_s((safe_mod_func_int8_t_s_s(g_301, 1UL)), (safe_rshift_func_uint16_t_u_s((g_301 < (safe_add_func_int8_t_s_s((l_937 >= g_238.f6), g_301))), 7))))))), 1UL)), 0))) && 4294967295UL) > g_238.f5) , l_950.f0)) , g_238));
        };


                    l_1240 &= g_241;
                    }
                }

                    for (l_942 = 18; (l_942 > 20); l_942 = safe_add_func_int32_t_s_s(l_942, 2))
                {
                    uint8_t l_483 = 0xD2L;
                    __undefined = ((((safe_sub_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((l_942--), g_33)), (((safe_div_func_uint32_t_u_u(g_1249, 0xF5DC8482L)) > (safe_rshift_func_int16_t_s_u((safe_lshift_func_int16_t_s_s(8L, 6)), 7))) , (((((l_483 < (((g_756 || (safe_add_func_uint64_t_u_u((~((g_967 ^= (((safe_rshift_func_uint16_t_u_u(0xEED5L, l_950.f0)) >= (((safe_lshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u(8UL, g_1249)), 0)) & p_57.f4) & 0x20L)) | g_378)) ^ 5L)), l_942))) < 0x0DL) <= g_30)) | g_1249) ^ 1UL) , g_33) == 0xD239F8EEL)))) & 249UL) >= p_57.f6) , g_12);
                };



{
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        g_238.f5 &= (!(l_958 = ((+(safe_mod_func_int32_t_s_s(g_238.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(g_238.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(g_238.f3, (((++l_950.f0) | (g_184 > ((l_757 , (g_30 ^= g_184)) , 0x3CC1CF37L))) != (l_674 == 249UL))))) , l_706), g_21.f0))))) ^ l_920)));
                        g_238 = g_238;
                    }


g_38 |= g_524;

                    if ((((safe_lshift_func_uint8_t_u_s((g_801 = (safe_rshift_func_uint8_t_u_s(l_942, 2))), g_66)) && (((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_int8_t_s_s(((((g_238 = g_238) , ((g_38 = (safe_add_func_int64_t_s_s(((((g_36 != l_400) == (((safe_rshift_func_int16_t_s_u((3UL == (((g_183 <= 0xB1A0L) != (((((safe_rshift_func_uint8_t_u_u(((!l_400) , g_524), 5)) > g_39) & (-10L)) , 0xE1L) > l_942)) , l_910)), g_66)) & 5L) || 0xA2B9BF124FD362E7LL)) == g_66) , (-1L)), g_39))) && g_38)) & g_183) >= 0x62L), g_39)) , g_66))) >= l_910) | 1L)) , l_400))
        {
            int8_t l_295 = (-5L);
            --g_241;
            g_238.f4 &= ((((l_375 &= 0x62L) <= ((g_30 = ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^ (g_792 = g_37)) & (safe_rshift_func_uint16_t_u_s(0x2310L, 10))) , ((g_571 ^ ((g_38 &= (l_295 != ((((l_400 = ((g_571 & ((~((((g_21 , (g_524 ^ g_238.f3)) > g_524) != 0x2A7A2EF32379F2B3LL) != g_183)) && l_295)) && l_295)) >= 0L) , 0x1AL) | 0x83L))) >= g_238.f2)) != g_524)) <= l_373) && (-1L)) || g_238.f1) , g_240)) | 1UL)) > 5L) ^ 0xDF8CL);
        }
        else
        {
            g_238.f2 = (-4L);
            for (g_377 = (-19); (g_377 > 10); g_377 = safe_add_func_uint16_t_u_u(g_377, 6))
            {
                g_238 = g_238;
            }
        };


                    if ((safe_sub_func_int16_t_s_s(((((((safe_lshift_func_int8_t_s_s((0x6EL & (safe_rshift_func_uint16_t_u_s(l_373, (l_68 = p_57.f4)))), l_493)) <= ((0xD471L < (safe_lshift_func_uint8_t_u_s(g_66, 7))) || l_373)) != (((p_57.f0 & (((g_240 = (((safe_unary_minus_func_int64_t_s(((l_375 , l_400) | p_57.f2))) | 7UL) <= 0x3B9260F6L)) ^ l_373) , g_241)) , p_57.f1) | p_57.f6)) >= p_57.f4) > l_493) || l_399), l_596)))
    {
        uint32_t l_609 = 0UL;
        uint32_t l_610 = 18446744073709551615UL;
        int16_t l_611 = 1L;
        int32_t l_672 = (-1L);
        int32_t l_673 = 0x5BAB80C9L;
        uint32_t l_677 = 4294967288UL;
        struct S1 l_691 = {14501,5528,-0,7773,227,0,2285};
        uint32_t l_707 = 0xF605241DL;
        uint64_t l_733 = 18446744073709551611UL;
        int64_t l_820 = 0x28812E388A6D2202LL;
        uint8_t l_860 = 0xD6L;
        uint8_t l_869 = 0x70L;
        uint32_t l_885 = 0x7EBE34DAL;
        struct S0 l_907 = {65533UL};
        int32_t l_919 = (-5L);
        if ((g_524 & (((((p_57 , (l_596 && l_399)) | (safe_mod_func_uint16_t_u_u(((g_65 , ((safe_sub_func_uint16_t_u_u(((((2UL & (safe_add_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(g_69, p_57.f3)), ((safe_sub_func_uint8_t_u_u((safe_div_func_int64_t_s_s(0xEC0DF3DED07D7D71LL, 0xFE38C1710C6551B0LL)), p_57.f3)) , 65532UL)))) , 0x598DL) > l_609) || l_609), l_609)) == p_57.f0)) || l_610), l_611))) <= p_57.f5) > 0xB0L) || g_322)))
        {
            uint16_t l_644 = 7UL;
            int32_t l_655 = 0x4245560AL;
            int32_t l_658 = 1L;
            for (l_493 = 16; (l_493 >= (-4)); l_493 = safe_sub_func_int64_t_s_s(l_493, 9))
            {
                uint16_t l_614 = 0x585DL;

p_57.f5 &= ((safe_mod_func_uint8_t_u_u(l_375, p_57.f3)) , g_183);


                    ++l_614;
                return p_57.f2;
            }
            for (l_611 = 0; (l_611 >= 5); ++l_611)
            {
                int16_t l_619 = 6L;
                int16_t l_656 = 0xF40CL;
                ++g_620;
                for (g_586 = (-17); (g_586 > (-21)); --g_586)
                {
                    uint64_t l_641 = 0UL;
                    int32_t l_659 = (-1L);
                    for (l_609 = 0; (l_609 == 39); l_609 = safe_add_func_uint16_t_u_u(l_609, 1))
                    {
                        uint64_t l_657 = 1UL;

{
            struct S0 l_200 = {0x8CAFL};
            int32_t l_205 = (-1L);
            int32_t l_208 = 0x15D7F043L;
            uint16_t l_215 = 0xEBE3L;
            struct S1 l_237 = {4888,4404,-28,3688,-181,0,4061};
            int32_t l_239 = 0x45497A7BL;

{
                    return g_30;
                }

                    for (l_760 = 14; (l_760 == 54); l_760++)
            {
                uint16_t l_196 = 1UL;
                l_196--;
                l_200 = p_58;
            }

g_238.f2 |= l_237.f0;


                    l_658 = (((safe_sub_func_uint8_t_u_u(l_610, (g_524 , g_199.f0))) < ((l_215 = (l_691.f4 &= (+((((-1L) & ((0xAFL < (((g_1276 == ((((l_691.f2 = (l_205 = (g_199 , 8L))) <= ((((((l_596++) ^ l_656) >= l_200.f0) , l_950) , l_950.f0) ^ (-7L))) > l_656) ^ l_656)) , 18446744073709551613UL) > l_373)) ^ l_200.f0)) && g_620) != 0x8890B9DDL)))) <= g_21.f0)) , l_691.f1);
            g_238 = ((((((safe_mod_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s(((g_69 = (safe_lshift_func_int16_t_s_s((((((((safe_sub_func_int32_t_s_s(((((((safe_rshift_func_int16_t_s_s((+(l_656 && (g_66 = (-1L)))), (l_656 = l_673))) && (((safe_mod_func_uint16_t_u_u(l_215, (safe_lshift_func_uint8_t_u_s(((g_199.f0 , 1L) , (0x34L != (safe_lshift_func_int8_t_s_s((safe_mod_func_uint64_t_u_u((l_656 >= (safe_add_func_uint64_t_u_u((__undefined == 4294967290UL), l_656))), g_199.f0)), l_691.f5)))), 5)))) | l_205) & 0x8900E08CL)) || l_596) || l_656) <= 0x3DL) < g_524), g_524)) | 0xBFBDL) < p_58.f0) > g_30) != g_199.f0) | l_950.f0) <= 0xDC97BAAAL), 4))) || l_373), g_524)) | l_910) == g_13), l_373)) ^ l_215) ^ l_656) || 1L) , l_610) , l_237);
            g_378++;
        }


if (l_493)
                            break;

                    g_238.f5 = 0xC207066FL;
                        l_659 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (l_373 = ((((safe_div_func_uint8_t_u_u(g_80, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(l_655 = (safe_mod_func_uint64_t_u_u(l_641, (g_36 &= ((safe_add_func_int8_t_s_s((l_644 = g_524), (safe_mod_func_int8_t_s_s(p_57.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((p_57.f5 &= g_188), (safe_mod_func_uint8_t_u_u(((~l_619) , p_57.f1), 255UL)))) , l_373) & p_57.f2))))))) != 0xA14CL)))))) <= l_656), l_657))))) && 6UL))) == l_658) <= p_58.f0) <= 1L))) , g_315), p_58.f0)) == g_238.f4) || p_57.f0) | g_586), g_315)) , 0x672551F9L) , 0xA150D49BL);
                    }


g_967 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_399 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((l_994 ^ (((5UL && ((((g_199 = l_907) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & l_691.f0)) >= 4UL) ^ g_65)) , g_199.f0), g_33)), l_691.f0)) <= g_69)) , l_691.f6), g_69)), g_301)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL);



{
                    uint64_t l_641 = 0UL;
                    int32_t l_659 = (-1L);
                    for (g_968 = 0; (g_968 == 39); g_968 = safe_add_func_uint16_t_u_u(g_968, 1))
                    {
                        uint64_t l_657 = 1UL;
                        p_57.f5 = 0xC207066FL;
                        l_659 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (g_791 = ((((safe_div_func_uint8_t_u_u(l_707, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(l_919 = (safe_mod_func_uint64_t_u_u(l_641, (g_36 &= ((safe_add_func_int8_t_s_s((g_928 = g_524), (safe_mod_func_int8_t_s_s(p_57.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((p_57.f5 &= l_910), (safe_mod_func_uint8_t_u_u(((~l_611) , p_57.f1), 255UL)))) , g_791) & p_57.f2))))))) != 0xA14CL)))))) <= l_619), l_657))))) && 6UL))) == l_958) <= p_58.f0) <= 1L))) , g_928), p_58.f0)) == p_57.f4) || p_57.f0) | g_12), g_928)) , 0x672551F9L) , 0xA150D49BL);
                    }
                    if (((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u(((p_57.f6 & (safe_sub_func_uint8_t_u_u(p_57.f2, g_968))) < (l_760 |= ((safe_add_func_int8_t_s_s((((g_928 == 0x1D75A18AL) >= (safe_rshift_func_int8_t_s_u(1L, 1))) && (((g_571 , (0x3926L > ((safe_mod_func_int16_t_s_s((l_400 = p_57.f3), p_57.f2)) | g_12))) >= p_57.f6) , (-1L))), g_928)) <= 0L))), 4)), 6)) , 0L))
                    {
                        return l_919;
                    }
                    else
                    {
                        p_57.f5 = p_57.f3;
                        return g_756;
                    }
                }

                    g_32 ^= g_67;



{
            int8_t l_295 = (-5L);
            --g_182;
            p_57.f4 &= ((((g_65 &= 0x62L) <= ((g_571 = ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^ (l_658 = l_655)) & (safe_rshift_func_uint16_t_u_s(0x2310L, 10))) , ((g_967 ^ ((g_37 &= (l_295 != ((((l_656 = ((l_658 & ((~((((l_907 , (g_67 ^ p_57.f3)) > g_67) != 0x2A7A2EF32379F2B3LL) != l_659)) && l_295)) && l_295)) >= 0L) , 0x1AL) | 0x83L))) >= p_57.f2)) != g_67)) <= l_859) && (-1L)) || p_57.f1) , g_67)) | 1UL)) > 5L) ^ 0xDF8CL);
        }

                    if (((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u(((p_57.f6 & (safe_sub_func_uint8_t_u_u(p_57.f2, l_609))) < (g_39 |= ((safe_add_func_int8_t_s_s((((g_620 == 0x1D75A18AL) >= (safe_rshift_func_int8_t_s_u(1L, 1))) && (((g_38 , (0x3926L > ((safe_mod_func_int16_t_s_s((g_184 = p_57.f3), g_238.f2)) | g_586))) >= g_238.f6) , (-1L))), l_644)) <= 0L))), 4)), 6)) , 0L))
                    {
                        return l_655;
                    }
                    else
                    {
                        p_57.f5 = p_57.f3;

g_66 ^= ((l_691.f0 || 255UL) < 0xD6E0L);


                    return g_37;
                    }
                }
            }


l_958 &= (l_950 , p_57.f0);

                    l_860 |= l_691.f1;


                    l_674++;
            ++l_677;
        }
        else
        {
            uint8_t l_687 = 2UL;
            uint32_t l_692 = 4294967291UL;
            int32_t l_758 = (-6L);
            int64_t l_759 = 0x10201B5C969F6449LL;
            int32_t l_796 = (-1L);
            int32_t l_797 = 0x66E5B6A1L;
            int32_t l_799 = (-9L);
            for (g_301 = (-14); (g_301 != 49); g_301 = safe_add_func_uint8_t_u_u(g_301, 3))
            {
                int16_t l_690 = (-1L);
                int32_t l_705 = 3L;
                if (((((safe_div_func_uint64_t_u_u((p_57.f0 || ((g_69 ^= (((((+(safe_rshift_func_int16_t_s_u(((l_687 ^= (((l_673 = (0xEB54L < p_57.f1)) <= g_238.f2) > g_12)) | g_315), g_21.f0))) ^ (safe_mul_func_int16_t_s_s((g_184 = 9L), (18446744073709551606UL >= l_690)))) != 2UL) <= 0x1EL) < l_609)) || p_57.f3)), 18446744073709551614UL)) != 0xAC861C3EL) < g_571) ^ 0L))
                {

{

for (l_373 = 0; (l_373 == 14); l_373 = safe_add_func_uint16_t_u_u(l_373, 7))
            {
                int64_t l_568 = 0x5C343ED73A8738E9LL;

g_793 |= (((l_799 = l_610) | ((p_57.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((l_611 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((l_919 |= (((safe_add_func_uint64_t_u_u((l_759 < (l_799 = ((p_57.f4 = g_238.f2) < g_571))), 0xB4C6519C0C658331LL)) | g_238.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), l_673)) , g_620)) > g_238.f4) || g_238.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > g_238.f1)) && g_199.f0) && g_66) & l_672)) ^ g_620) & g_620)) >= 0UL) , l_673)) != g_191)) || 0x2FL);


                    l_691.f2 = (((l_691.f1 &= (7L & ((l_759 ^= ((((l_760 = ((g_993 != 0x4CL) == (+(((-9L) == l_568) > 0UL)))) <= ((((safe_mod_func_uint8_t_u_u((l_860 = l_691.f0), g_967)) <= 0xA1BF90C52FB11BB9LL) <= 1UL) & g_378)) , l_691) , g_377)) <= l_691.f2))) <= l_691.f5) <= l_691.f2);
                g_792 = (~0x67D3L);

l_68 &= l_677;

                    if (l_691.f4)
                    break;
                l_691.f4 &= (l_691.f5 ^= ((!((((((safe_add_func_uint16_t_u_u((((l_691.f6 & (((((l_942 < (safe_lshift_func_uint16_t_u_u(l_579, (g_12 > g_240)))) < (safe_mod_func_int32_t_s_s((safe_div_func_uint64_t_u_u((safe_lshift_func_uint8_t_u_u((1L & (l_759 < (0x7F8CL | (l_919 = l_691.f3)))), g_524)), g_184)), l_885))) < 4UL) , g_1249) <= g_32)) ^ g_928) <= (-4L)), l_691.f0)) , l_691.f1) != 1L) <= l_568) & l_691.f1) && g_322)) || 0UL));
            }
{
        int64_t l_953 = 0x86445DF67443E0CELL;
        struct S0 l_954 = {0xD225L};
        int32_t l_955 = (-1L);
        int32_t l_956 = 6L;
        int32_t l_957 = 1L;
        int32_t l_959 = (-5L);
        int32_t l_960 = 0xFA289949L;
        int32_t l_961 = 0x9CE9722AL;
        int32_t l_962 = 0x4270AC42L;
        int32_t l_963 = 0xE0FAB585L;
        int32_t l_964 = (-1L);
        int32_t l_965 = 9L;
        int32_t l_966 = (-1L);
        l_954 = (((g_756 = (l_859 = l_953)) | (g_37 &= (g_301 | p_57.f0))) , g_21);
        l_954 = g_21;
        --g_241;
        g_800 |= ((safe_div_func_uint8_t_u_u(((safe_div_func_uint8_t_u_u((safe_div_func_uint16_t_u_u((--g_793), p_57.f0)), (0x5A0BAD988B54577ELL || (l_962 != (g_21 , (safe_lshift_func_int16_t_s_u((-3L), (p_57.f1 | (safe_add_func_int8_t_s_s(p_57.f3, (safe_sub_func_int32_t_s_s((safe_div_func_int8_t_s_s(((l_399 = ((((safe_div_func_int16_t_s_s((0x7BF8L > ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((l_955 = (g_21 , g_37)), 14)), 6)) >= l_690)), g_571)) && 0xD5682F7CL) <= l_674) == g_191)) >= 65527UL), 251UL)), 0xFC6382EAL)))))))))))) > l_690), l_963)) < 1L);
    }

                    ;


                    if ((safe_lshift_func_int8_t_s_s(((4294967295UL ^ ((((safe_sub_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u((safe_div_func_int32_t_s_s(0x8676E750L, (((safe_rshift_func_uint8_t_u_s((safe_div_func_int64_t_s_s((((l_758 = 1L) >= g_793) < (g_238.f4 , (g_993 != 1UL))), (safe_sub_func_uint8_t_u_u((safe_add_func_int8_t_s_s((g_66 ^= ((g_238.f0 || 255UL) < 0xD6E0L)), 6L)), g_238.f2)))), 1)) , 4294967295UL) , l_758))), l_799)) == g_238.f4) || l_799), 65533UL)) || 0x93L), g_65)) || g_240) >= l_799) , l_860)) == l_672), 3)))
                    {

if (g_183)
                    {
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;
                        l_691.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, g_301)), (l_1239 = (l_942 = g_792)))), (l_691.f6 , l_673)));
                        g_1249++;
                    }
                    else
                    {
                        l_673 &= g_1249;
                    };


                    if (g_36)
                            break;
                    }
                    else
                    {
                        l_950 = p_58;
                    }

if (g_188)
                {
                    p_57.f2 ^= g_801;
                    if (p_57.f1)
                        break;
                    if (p_57.f2)
                        continue;
                }
                else
                {
                    if ((safe_lshift_func_int8_t_s_s(((4294967295UL ^ ((((safe_sub_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u((safe_div_func_int32_t_s_s(0x8676E750L, (((safe_rshift_func_uint8_t_u_s((safe_div_func_int64_t_s_s((((g_37 = 1L) >= g_793) < (p_57.f4 , (g_993 != 1UL))), (safe_sub_func_uint8_t_u_u((safe_add_func_int8_t_s_s((g_240 ^= ((p_57.f0 || 255UL) < 0xD6E0L)), 6L)), p_57.f2)))), 1)) , 4294967295UL) , g_37))), g_183)) == g_238.f4) || g_183), 65533UL)) || 0x93L), g_183)) || g_586) >= g_183) , l_687)) == l_758), 3)))
                    {
                        if (l_820)
                            break;
                    }
                    else
                    {
                        g_199 = g_199;
                    }
                    return g_183;
                };


                    return l_799;
                }



{
            int64_t l_1024 = (-5L);
            int8_t l_1078 = (-6L);
            int32_t l_1097 = 1L;
            uint32_t l_1101 = 0xD7F1C410L;
            struct S1 l_1130 = {8673,6450,23,10711,151,0,6403};
            if (((g_199 , ((safe_sub_func_int16_t_s_s((safe_add_func_int32_t_s_s(((safe_sub_func_int32_t_s_s((g_21 , ((safe_div_func_uint8_t_u_u(((g_183 = ((g_240 ^ (l_796 = g_967)) > l_1024)) , (safe_rshift_func_int8_t_s_s(p_57.f3, 5))), ((l_958 <= (g_800 = l_860)) && (l_68 = (+(safe_div_func_uint32_t_u_u((g_756 == g_524), p_57.f1))))))) | g_241)), g_240)) <= l_707), g_32)), l_907.f0)) <= g_1285)) ^ l_907.f0))
            {
                int32_t l_1071 = 0x4CD963E3L;
                int32_t l_1112 = 0x19243E41L;
                int64_t l_1157 = (-1L);
                if ((safe_mod_func_int64_t_s_s(l_757, (safe_mod_func_uint64_t_u_u(g_524, (safe_add_func_int64_t_s_s(((safe_add_func_uint32_t_u_u(l_1024, ((l_400 |= (safe_add_func_int32_t_s_s((p_57.f5 = ((((l_869 != (((((0x05L == ((0x25L ^ (safe_lshift_func_uint16_t_u_u((((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s((g_21 , p_57.f5), (((l_691 , p_57.f3) , p_57) , 0L))) || g_967), g_378)) >= l_691.f4) >= 7UL), 13))) < l_757)) , 0x67L) & l_860) , 0xC3L) | l_610)) || p_57.f6) , 0L) , l_796)), l_910))) >= 0x08DCL))) == g_756), g_524)))))))
                {
                    uint64_t l_1054 = 0UL;

for (l_733 = 0; (l_733 > 1); l_733++)
        {
            int32_t l_870 = (-1L);
            g_13 = (p_57.f3 , (safe_rshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(l_860, 13)), g_33)), 10)));
            return l_870;
        };


                    g_756 &= (((g_240 != 0x8446L) , g_199) , (((l_1054 ^ l_907.f0) , ((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u((safe_add_func_int64_t_s_s(((1UL & (safe_rshift_func_int8_t_s_u((safe_add_func_int64_t_s_s((g_378 <= (l_691 , (safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(((((safe_mod_func_uint16_t_u_u(l_691.f3, l_860)) || p_57.f6) ^ l_1054) , l_1071), 8)) | p_57.f3), 5L)))), g_37)), p_57.f4))) | g_967), 0xCBB7D04007C17F65LL)), g_571)), p_57.f5)) > (-1L))) >= l_907.f0));
                }
                else
                {
                    int8_t l_1100 = (-7L);
                    int32_t l_1104 = 0L;
                    int32_t l_1111 = 0x36BD596BL;
                    uint16_t l_1129 = 65535UL;
                    p_57.f2 ^= (((((l_707 >= 0L) <= g_37) || ((safe_add_func_uint64_t_u_u((safe_div_func_int32_t_s_s((g_524 , ((((0L <= (0xAF2AFC70L || ((l_691.f1 |= ((((safe_sub_func_uint16_t_u_u(l_1078, (safe_lshift_func_uint16_t_u_u(1UL, g_1285)))) , 0x08EAL) > 0x7146L) == 0x51A9FA1A770123F4LL)) && g_571))) != g_241) || l_68) >= p_57.f3)), 4294967295UL)), 0x8134BAAB9636E740LL)) | 0x429EL)) || g_378) && g_32);
                    for (__undefined = 16; (__undefined != 15); __undefined = safe_sub_func_int32_t_s_s(__undefined, 1))
                    {
                        int32_t l_1099 = 0x29D6DC62L;
                        l_1101 |= ((safe_add_func_uint16_t_u_u(((safe_div_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_s((l_860 |= l_691.f1), 0)) <= l_400), (((safe_lshift_func_uint16_t_u_u((g_793 |= (((g_967 = l_942) | ((l_691.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((l_400 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((l_705 |= (((safe_add_func_uint64_t_u_u((l_1024 < (l_1097 = ((l_691.f4 = p_57.f2) < l_1071))), 0xB4C6519C0C658331LL)) | p_57.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), l_1099)) , g_1285)) > p_57.f4) || p_57.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > p_57.f1)) && g_21.f0) && l_1100) & l_796)) ^ g_1285) & l_60)) >= 0UL) , l_1099)) != l_910)) || 0x2FL)), l_1100)) < p_57.f1) || 4294967294UL))) & l_907.f0), 65535UL)) >= p_57.f4);
                        if (p_57.f1)
                            continue;
                    }
                    l_691.f5 = (safe_add_func_int8_t_s_s(((0L > (((l_1104 |= 0x342AL) && (g_524 & (safe_div_func_uint8_t_u_u(0xA3L, (safe_rshift_func_uint16_t_u_u(0x820EL, 10)))))) , 1L)) , (safe_rshift_func_uint8_t_u_s((l_860++), 5))), (safe_add_func_int8_t_s_s(((0x5EA5295EB42C2F9DLL && (safe_rshift_func_int16_t_s_u(((safe_div_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((l_1097 &= l_1100), ((((safe_add_func_uint16_t_u_u((g_21.f0 = ((l_869 < g_756) <= 0x6B6EL)), l_1129)) , l_1101) , p_57) , 0xCCL))), l_1071)), g_524)), l_757)) && p_57.f2), p_57.f5))) || l_860), l_994))));

g_12 ^= ((p_57.f0 || 255UL) < 0xD6E0L);


                    l_1130 = (p_57 = l_691);
                }

g_13 &= (safe_lshift_func_uint16_t_u_s((g_66 >= l_919), ((safe_div_func_uint8_t_u_u(func_94((safe_div_func_uint16_t_u_u(g_36, 1L)), p_58, g_199.f0), 0xCDL)) | g_199.f0)));



{
                    uint8_t l_483 = 0xD2L;
                    l_1024 = ((((safe_sub_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((l_610--), g_188)), (((safe_div_func_uint32_t_u_u(g_968, 0xF5DC8482L)) > (safe_rshift_func_int16_t_s_u((safe_lshift_func_int16_t_s_s(8L, 6)), 7))) , (((((l_483 < (((l_373 || (safe_add_func_uint64_t_u_u((~((l_758 ^= (((safe_rshift_func_uint16_t_u_u(0xEED5L, g_199.f0)) >= (((safe_lshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u(8UL, g_968)), 0)) & p_57.f4) & 0x20L)) | g_301)) ^ 5L)), l_1101))) < 0x0DL) <= g_38)) | g_968) ^ 1UL) , l_687) == 0xD239F8EEL)))) & 249UL) >= p_57.f6) , l_1078);
                }

                    l_68 = ((1L >= ((safe_mod_func_uint8_t_u_u((l_1071 >= ((g_238 = g_238) , ((0L ^ 0xC90582774B564BEDLL) != ((l_400 || g_32) >= (+p_57.f2))))), (safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((l_1130.f0 ^ 0x3DD1A058L), l_1130.f3)), g_756)))) , 0x1AD8CD47L)) & 18446744073709551615UL);
                l_68 = (safe_div_func_uint32_t_u_u((safe_mod_func_int64_t_s_s(((safe_mod_func_uint64_t_u_u((safe_add_func_uint16_t_u_u(((safe_div_func_uint8_t_u_u(p_57.f4, (l_1112 && (l_860++)))) && (((safe_rshift_func_int8_t_s_u(g_571, ((safe_add_func_uint16_t_u_u((p_57.f3 ^ g_571), l_950.f0)) | g_32))) ^ (l_1157 || (((g_524 != p_57.f3) == (-4L)) & (-2L)))) == l_907.f0)), l_691.f0)), l_757)) , 1L), g_238.f4)), p_57.f2));

g_238.f2 |= ((safe_lshift_func_uint8_t_u_s(255UL, (safe_rshift_func_uint8_t_u_s(l_596, 2)))) & (safe_sub_func_int16_t_s_s(g_238.f2, 1L)));

                    l_1130.f4 |= (safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_s(((p_57.f5 = ((((4UL != ((safe_unary_minus_func_uint8_t_u((safe_rshift_func_uint8_t_u_s((safe_lshift_func_int16_t_s_s(((((safe_sub_func_int16_t_s_s(((safe_sub_func_int8_t_s_s(l_907.f0, (g_241 & (p_57.f5 &= (safe_div_func_int8_t_s_s(p_57.f3, 0x82L)))))) && (((safe_rshift_func_int8_t_s_s(((((0xE4L ^ ((safe_sub_func_uint64_t_u_u((((((l_691.f0 &= (safe_mod_func_int64_t_s_s((((((8UL && ((safe_mod_func_uint32_t_u_u((((safe_rshift_func_int8_t_s_u((safe_div_func_int32_t_s_s((p_57.f1 | p_57.f6), g_238.f2)), 7)) <= g_80) | p_57.f3), 0xF4092F41L)) || l_907.f0)) ^ l_1157) < l_691.f1) , l_1130.f6) , g_80), l_1130.f6))) , l_1112) & p_57.f4) ^ 0xCCBC0462L) == g_378), g_571)) & 65535UL)) || l_796) | p_57.f2) > l_1097), l_1130.f3)) >= l_942) , 18446744073709551613UL)), 0x1DC2L)) , l_950) , 0UL) || l_400), 13)), 3)))) || g_32)) | p_57.f4) , l_400) && l_691.f2)) <= 18446744073709551615UL), p_57.f6)), 7));
            }
            else
            {
                int16_t l_1198 = 1L;
                if ((((g_12 |= ((safe_lshift_func_int16_t_s_s((18446744073709551607UL != ((((((((safe_lshift_func_int16_t_s_s(((g_199.f0 < (l_958 = ((safe_sub_func_int64_t_s_s((safe_add_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s((safe_mod_func_int32_t_s_s(l_1198, (safe_mod_func_int64_t_s_s((safe_mod_func_uint8_t_u_u(((g_240 |= ((safe_add_func_uint64_t_u_u(((g_301 < ((safe_mod_func_uint64_t_u_u(p_57.f0, (((safe_sub_func_int8_t_s_s(((((l_400 = l_707) > (safe_unary_minus_func_uint64_t_u(0xD039656BC93DCDE7LL))) && ((0x1154443CL ^ ((safe_rshift_func_int16_t_s_s((+(safe_sub_func_int32_t_s_s(l_1130.f0, 0xA33F1971L))), 6)) , 0xA1E7029EL)) ^ l_907.f0)) == 0L), 0UL)) || 0xA51DB1AF86CBBD6FLL) , l_1078))) , l_950.f0)) == l_1130.f0), (-10L))) , l_68)) > l_958), l_1198)), g_756)))), 14)) > p_57.f2) && l_910), (-1L))), l_757)) == 0L))) && 1L), l_707)) != l_910) != p_57.f3) > l_950.f0) == g_183) <= 0x48L) > 2UL) != 0x87C43CC6L)), 0)) , p_57.f5)) & g_80) , (-9L)))
                {
                    l_958 |= g_240;
                }
                else
                {
                    l_958 = (g_238.f2 = (p_57.f2 ^= (l_1130.f2 |= p_57.f0)));
                    l_691 = l_691;
                }
            }
        }

                    p_57.f2 |= ((safe_lshift_func_uint8_t_u_s(255UL, (safe_rshift_func_uint8_t_u_s(l_733, 2)))) & (safe_sub_func_int16_t_s_s(g_238.f2, 1L)));

                    g_238 = l_691;
                }
                else
                {
                    uint8_t l_715 = 0x80L;
                    int64_t l_741 = 1L;
                    int64_t l_785 = 0x89D08C2D27B3D546LL;
                    int32_t l_798 = (-4L);
                    int32_t l_809 = 0x4B1AA5B2L;
                    int16_t l_831 = 8L;
                    int32_t l_833 = 0x655BBAA5L;
                    int32_t l_834 = 0x1FA30236L;


{

if (g_238.f1)
                            {
{
                int64_t l_568 = 0x5C343ED73A8738E9LL;
                g_238.f2 = (((g_238.f1 &= (7L & ((l_820 ^= ((((l_596 = ((l_400 != 0x4CL) == (+(((-9L) == l_568) > 0UL)))) <= ((((safe_mod_func_uint8_t_u_u((l_687 = g_238.f0), g_377)) <= 0xA1BF90C52FB11BB9LL) <= 1UL) & g_301)) , g_238) , l_834)) <= g_238.f2))) <= g_238.f5) <= g_238.f2);
                l_919 = (~0x67D3L);
                if (g_238.f4)
                    break;
                g_238.f4 &= (g_238.f5 ^= ((!((((((safe_add_func_uint16_t_u_u((((g_238.f6 & (((((g_873 < (safe_lshift_func_uint16_t_u_u(l_760, (g_524 > g_12)))) < (safe_mod_func_int32_t_s_s((safe_div_func_uint64_t_u_u((safe_lshift_func_uint8_t_u_u((1L & (l_785 < (0x7F8CL | (l_672 = g_238.f3)))), g_240)), g_184)), l_610))) < 4UL) , l_677) <= l_785)) ^ l_60) <= (-4L)), g_238.f0)) , g_238.f1) != 1L) <= l_568) & g_238.f1) && l_869)) || 0UL));
            }

                    break;}

                    g_238.f5 = g_238.f3;
                        return l_373;
                    }

                    if (((((safe_div_func_uint64_t_u_u((g_238.f0 || ((g_1276 ^= (((((+(safe_rshift_func_int16_t_s_u(((g_33 ^= (((g_800 = (0xEB54L < g_238.f1)) <= g_238.f2) > g_524)) | g_315), l_907.f0))) ^ (safe_mul_func_int16_t_s_s((g_184 = 9L), (18446744073709551606UL >= g_184)))) != 2UL) <= 0x1EL) < g_241)) || g_238.f3)), 18446744073709551614UL)) != 0xAC861C3EL) < g_13) ^ 0L))
                {

__undefined ^= g_524;



{
    struct S1 l_2 = {5257,2494,15,7269,192,0,6867};
    struct S1 l_20 = {8399,1580,12,4707,209,0,910};
    struct S1 l_1295 = {8978,2774,11,1659,145,0,2412};
    l_2.f2 = ((l_2 , (((((((-8L) && (safe_rshift_func_uint8_t_u_u(func_5(((l_1295 = (l_20 = ((safe_div_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(((!(g_12 || (l_2.f4 = (-1L)))) ^ g_12), 10)) <= (l_799 = g_12)), func_14(g_12, l_20, g_21, g_21, g_21.f0))) , p_57))) , g_571)), l_919))) != g_12) , 0UL) > l_2.f6) | 0xC987502CL) && g_528)) != g_524);
    return l_20.f1;
}

                    g_238 = g_238;
                }
                else
                {
                    uint8_t l_715 = 0x80L;
                    int64_t l_741 = 1L;
                    int64_t l_785 = 0x89D08C2D27B3D546LL;
                    int32_t l_798 = (-4L);
                    int32_t l_809 = 0x4B1AA5B2L;
                    int16_t l_831 = 8L;
                    int32_t l_833 = 0x655BBAA5L;
                    int32_t l_834 = 0x1FA30236L;
                    if (l_610)
                    {
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        g_238.f5 &= (!(g_800 = ((+(safe_mod_func_int32_t_s_s(g_238.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(g_238.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(g_238.f3, (((++l_950.f0) | (g_184 > ((g_1276 , (l_705 ^= g_184)) , 0x3CC1CF37L))) != (l_610 == 249UL))))) , l_706), l_907.f0))))) ^ g_80)));
                        g_238 = g_238;
                    }
                    else
                    {
                        uint16_t l_731 = 0UL;
                        uint64_t l_732 = 0xFD49211BAC9527ABLL;
                        uint16_t l_745 = 0x07DBL;
                        g_238.f5 = (((!((((g_238.f0 == (safe_lshift_func_int8_t_s_s(g_315, ((safe_rshift_func_int8_t_s_s((g_238.f2 ^ ((((safe_sub_func_uint64_t_u_u((g_238.f4 &= l_715), (safe_mod_func_int16_t_s_s(((g_238.f4 > 1L) > ((g_13 & ((safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((((l_731 = (0xB1L > (safe_mod_func_uint32_t_u_u((safe_div_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((0xBAL <= l_760), 1UL)) == (-1L)), g_241)) & g_238.f1) == (-1L)) < g_1249) && g_238.f0))), l_759)), 0xE6E002D4L)))) || l_732) >= l_732) == g_33), g_238.f3)) == 1UL) & l_958), l_579)) == 0x4FL)) >= g_238.f2)), g_238.f6)))) < l_950.f0) ^ g_238.f6) , g_238.f4)), g_1249)) || 0xA8L)))) > 251UL) , g_1249) , g_238.f4)) || g_238.f3) && 0L);


{
                int16_t l_619 = 6L;
                int16_t l_656 = 0xF40CL;
                ++l_60;
                for (g_586 = (-17); (g_586 > (-21)); --g_586)
                {
                    uint64_t l_641 = 0UL;
                    int32_t l_659 = (-1L);
                    for (g_873 = 0; (g_873 == 39); g_873 = safe_add_func_uint16_t_u_u(g_873, 1))
                    {
                        uint64_t l_657 = 1UL;
                        g_238.f5 = 0xC207066FL;
                        l_659 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (l_833 = ((((safe_div_func_uint8_t_u_u(l_885, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(g_30 = (safe_mod_func_uint64_t_u_u(l_641, (l_741 &= ((safe_add_func_int8_t_s_s((g_793 = g_12), (safe_mod_func_int8_t_s_s(p_57.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((p_57.f5 &= g_33), (safe_mod_func_uint8_t_u_u(((~l_619) , p_57.f1), 255UL)))) , l_833) & p_57.f2))))))) != 0xA14CL)))))) <= l_656), l_657))))) && 6UL))) == g_377) <= l_950.f0) <= 1L))) , g_1285), l_950.f0)) == g_238.f4) || p_57.f0) | g_586), g_1285)) , 0x672551F9L) , 0xA150D49BL);
                    }
                    if (((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u(((p_57.f6 & (safe_sub_func_uint8_t_u_u(p_57.f2, g_873))) < (l_760 |= ((safe_add_func_int8_t_s_s((((l_60 == 0x1D75A18AL) >= (safe_rshift_func_int8_t_s_u(1L, 1))) && (((l_68 , (0x3926L > ((safe_mod_func_int16_t_s_s((l_690 = p_57.f3), g_238.f2)) | g_586))) >= g_238.f6) , (-1L))), g_793)) <= 0L))), 4)), 6)) , 0L))
                    {
                        return g_30;
                    }
                    else
                    {
                        p_57.f5 = p_57.f3;
                        return l_672;
                    }
                }
            }

                    if (l_691.f1)
                        {

{
                uint32_t l_1230 = 0xC2612157L;
                int32_t l_1241 = 0x1C3A57D2L;
                int32_t l_1244 = 0x0E65AD9AL;
                int32_t l_1246 = 1L;

{
        struct S0 l_267 = {0xB8F5L};
        l_267 = (g_21.f0 , g_21);
        l_950 = l_950;
    }

                    g_238 = l_691;
                g_792 &= (l_705 = (safe_lshift_func_uint8_t_u_s((+(g_182 < (-1L))), 6)));
                if (l_373)
                {
                    uint32_t l_1238 = 0xACAF4E8DL;
                    int32_t l_1240 = 0L;
                    l_705 = g_524;
                    l_907 = (l_691.f6 , l_907);

if (l_907.f0)
                    goto lbl_465;

                    l_691.f4 &= l_1230;
                    if (l_705)
                    {
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;
                        l_691.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, l_1230)), (l_1239 = (l_1238 = g_30)))), (l_691.f6 , l_1240)));
                        l_920++;
                    }
                    else
                    {
                        l_1240 &= g_1249;
                    }
                }
                else
                {
                    uint64_t l_1260 = 0xF5DC1668590A4472LL;
                    int32_t l_1273 = (-1L);
                    int32_t l_1274 = 0xEA32A638L;
                    int32_t l_1275 = 0x813DFFBBL;
                    l_691.f5 = (safe_mod_func_uint8_t_u_u((1UL == (safe_sub_func_uint8_t_u_u(((g_586 && g_238.f4) > ((safe_div_func_uint64_t_u_u(l_687, l_757)) <= (((l_1260 , (safe_rshift_func_uint8_t_u_u(l_691.f4, 5))) != (--l_920)) && (((g_240 & (l_691.f2 = (g_792 ^= (safe_mod_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(0x17F9FA19L, l_785)), 1)) && l_691.f5), 0xD66C9ADCL))))) | g_199.f0) & l_831)))), g_238.f5))), g_586));
                    for (l_731 = 3; (l_731 != 32); l_731 = safe_add_func_uint32_t_u_u(l_731, 4))
                    {
                        ++g_1276;

l_705 &= (g_67 != ((((l_690 = ((l_809 & ((~((((g_21 , (g_67 ^ g_238.f3)) > g_67) != 0x2A7A2EF32379F2B3LL) != l_796)) && g_67)) && g_67)) >= 0L) , 0x1AL) | 0x83L));


                    if (g_238.f1)
                            {
{
            uint8_t l_687 = 2UL;
            uint32_t l_692 = 4294967291UL;
            int32_t l_758 = (-6L);
            int64_t l_759 = 0x10201B5C969F6449LL;
            int32_t l_796 = (-1L);
            int32_t l_797 = 0x66E5B6A1L;
            int32_t l_799 = (-9L);
            for (g_241 = (-14); (g_241 != 49); g_241 = safe_add_func_uint8_t_u_u(g_241, 3))
            {
                int16_t l_690 = (-1L);
                int32_t l_705 = 3L;
                if (((((safe_div_func_uint64_t_u_u((l_691.f0 || ((g_188 ^= (((((+(safe_rshift_func_int16_t_s_u(((l_687 ^= (((g_791 = (0xEB54L < l_691.f1)) <= l_691.f2) > g_67)) | l_745), l_907.f0))) ^ (safe_mul_func_int16_t_s_s((l_690 = 9L), (18446744073709551606UL >= l_690)))) != 2UL) <= 0x1EL) < l_1230)) || l_691.f3)), 18446744073709551614UL)) != 0xAC861C3EL) < g_377) ^ 0L))
                {
                    l_691 = g_238;
                }
                else
                {
                    uint8_t l_715 = 0x80L;
                    int64_t l_741 = 1L;
                    int64_t l_785 = 0x89D08C2D27B3D546LL;
                    int32_t l_798 = (-4L);
                    int32_t l_809 = 0x4B1AA5B2L;
                    int16_t l_831 = 8L;
                    int32_t l_833 = 0x655BBAA5L;
                    int32_t l_834 = 0x1FA30236L;
                    if (l_692)
                    {
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        l_691.f5 &= (!(g_791 = ((+(safe_mod_func_int32_t_s_s(l_691.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(l_691.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(l_691.f3, (((++l_907.f0) | (l_690 > ((g_188 , (l_705 ^= l_690)) , 0x3CC1CF37L))) != (g_301 == 249UL))))) , l_706), l_907.f0))))) ^ l_609)));
                        l_691 = l_691;
                    }
                    else
                    {
                        uint16_t l_731 = 0UL;
                        uint64_t l_732 = 0xFD49211BAC9527ABLL;
                        uint16_t l_745 = 0x07DBL;
                        l_691.f5 = (((!((((l_691.f0 == (safe_lshift_func_int8_t_s_s(l_745, ((safe_rshift_func_int8_t_s_s((l_691.f2 ^ ((((safe_sub_func_uint64_t_u_u((g_238.f4 &= l_715), (safe_mod_func_int16_t_s_s(((l_691.f4 > 1L) > ((g_377 & ((safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((((l_731 = (0xB1L > (safe_mod_func_uint32_t_u_u((safe_div_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((0xBAL <= l_399), 1UL)) == (-1L)), l_1230)) & l_691.f1) == (-1L)) < g_241) && l_691.f0))), __undefined)), 0xE6E002D4L)))) || l_732) >= l_732) == l_687), g_238.f3)) == 1UL) & g_13), g_39)) == 0x4FL)) >= l_691.f2)), l_691.f6)))) < l_907.f0) ^ l_691.f6) , l_691.f4)), l_692)) || 0xA8L)))) > 251UL) , g_241) , g_238.f4)) || l_691.f3) && 0L);
                        l_798 ^= (((safe_lshift_func_int8_t_s_s((l_869 || ((safe_unary_minus_func_int16_t_s((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((l_741 ^= g_67), (l_834 |= ((!(safe_mod_func_uint32_t_u_u((l_691.f0 , ((l_745 && (0x58956D07L && (~((l_758 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_732 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((l_994 ^ (((5UL && ((((l_907 = l_907) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & l_691.f0)) >= 4UL) ^ l_758)) , l_907.f0), l_715)), l_691.f0)) <= l_687)) , l_691.f6), l_757)), l_692)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL)) <= l_691.f0)))) | l_691.f3)), g_322))) >= 0xC1BC967721442813LL)))) ^ g_301), l_691.f6)))) , 0x2FA0L)), 2)) , l_690) >= 1UL);
                        l_691.f4 = (l_691.f2 = 0xA79062E5L);
                        l_733--;
                    }
                    l_705 = (-1L);
                    if ((safe_add_func_uint16_t_u_u((g_238.f2 = (((((((g_238.f2 , l_834) ^ ((+(safe_lshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(l_691.f3, (l_692 == l_691.f1))), 6))) <= (((8L & (l_692 < (((+(safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u((l_705 = l_691.f2))), (safe_add_func_uint64_t_u_u(g_524, 0xC2CA4FFE53744833LL))))) <= (-5L)) | l_691.f3))) & 1UL) < 0x529AL))) || l_691.f0) , l_691.f1) | g_67) , g_67) > l_691.f6)), g_793)))
                    {
                        uint32_t l_786 = 0xBE94B622L;
                        int8_t l_787 = 0L;
                        int32_t l_788 = 0x65367992L;
                        int32_t l_789 = 0x26FEF397L;
                        int32_t l_790 = 0L;
                        l_786 ^= ((l_907.f0 >= 0UL) <= (safe_div_func_uint8_t_u_u((l_691.f4 && (l_691.f0 = ((((safe_add_func_uint64_t_u_u((l_691.f2 & (+(l_907.f0 |= ((((safe_div_func_int16_t_s_s(((l_785 , 0UL) & g_322), 0x0D89L)) , 0x9F8EAEBA3A833647LL) != l_715) >= l_692)))), g_791)) != 0x9F1F1DE72F8155A5LL) , 65535UL) , l_691.f2))), 0x27L)));
                        --g_928;
                        g_1276--;
                    }
                    else
                    {
                        int8_t l_818 = 2L;
                        int32_t l_828 = (-7L);
                        int32_t l_829 = 1L;
                        int32_t l_830 = (-1L);
                        int32_t l_832 = (-4L);
                        if (l_834)
                            break;
                        l_691.f2 = (safe_rshift_func_uint16_t_u_s((l_799 | (((l_691.f5 <= ((((((((!(safe_sub_func_uint8_t_u_u((g_1276--), (l_745 > (((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((l_907.f0 = l_818), (~0x15F3096FL))), (l_785 != g_524))) == (safe_add_func_uint8_t_u_u(253UL, (safe_div_func_int32_t_s_s((safe_unary_minus_func_int32_t_s(((safe_rshift_func_uint8_t_u_u(((++l_1230) != ((l_834 = (l_691.f2 == 1UL)) < 0xD0L)), l_994)) ^ l_692))), 8L))))) , 0xE5B274CA6F72970ELL) && 0x791A8EF8E600BD62LL) >= 0x6BL))))) && l_798) && l_691.f2) && 0xDAL) , l_1244) <= l_691.f3) >= g_67) >= l_691.f1)) != l_691.f1) > g_33)), g_791));
                        l_705 = (l_691.f0 <= (safe_div_func_uint8_t_u_u((l_691.f5 && (l_907.f0 = 0x40CEL)), (safe_sub_func_int64_t_s_s((((--l_1230) >= ((safe_rshift_func_uint8_t_u_s(255UL, 4)) == (((safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((((1L ^ (safe_div_func_uint32_t_u_u(g_30, (safe_mod_func_int16_t_s_s((l_690 >= (safe_mod_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u(l_690, ((g_238.f5 &= ((safe_mod_func_uint8_t_u_u(l_758, l_691.f3)) , l_797)) , 18446744073709551613UL))) && (-8L)) & l_691.f0), (-1L)))), l_691.f2))))) != l_690) , l_796), 5)), 18446744073709551615UL)) & g_238.f4) > g_191))) | (-1L)), l_690)))));
                    }
                }
                l_834 = g_238.f3;
            }
        }

                    break;}
                        if (l_758)
                            continue;
                        l_691.f5 ^= (safe_mod_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(0xAEL, (0x4461L | (l_373 != (g_792 = (l_741 == (l_691.f0 = g_66))))))), l_1273));
                    }
                }
            }

                    g_238.f4 &= ((((l_796 &= 0x62L) <= ((g_377 = ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^ (l_958 = g_13)) & (safe_rshift_func_uint16_t_u_s(0x2310L, 10))) , ((l_833 ^ ((g_791 &= (g_66 != ((((g_993 = ((g_183 & ((~((((l_950 , (g_66 ^ g_238.f3)) > g_66) != 0x2A7A2EF32379F2B3LL) != g_13)) && g_66)) && g_66)) >= 0L) , 0x1AL) | 0x83L))) >= g_238.f2)) != g_66)) <= g_38) && (-1L)) || g_238.f1) , g_66)) | 1UL)) > 5L) ^ 0xDF8CL);

                    break;}


{
        int32_t l_338 = 1L;
        uint8_t l_367 = 0x7FL;
        int32_t l_370 = 0L;
        int32_t l_371 = 0x384BA09CL;
        int32_t l_372 = 0x83DB8F6AL;
        int32_t l_374 = (-4L);
        int32_t l_376 = 6L;
        for (g_184 = 10; (g_184 == (-17)); --g_184)
        {
            int32_t l_347 = 1L;
            int32_t l_368 = 5L;
            if (((safe_sub_func_int32_t_s_s((~l_910), ((((+l_338) || (1L && (safe_div_func_uint8_t_u_u(((g_238.f1 == ((safe_add_func_int32_t_s_s(0L, ((((((!(safe_add_func_int8_t_s_s(g_524, 0xF5L))) , (safe_unary_minus_func_int16_t_s(3L))) > g_238.f0) > l_338) ^ 0x6B9E5876L) || 1UL))) < l_347)) & 1L), g_182)))) && 65535UL) == 0UL))) & 7UL))
            {
                if ((g_238.f5 = (0xCDL ^ g_238.f1)))
                {
                    return l_338;
                }
                else
                {
                    return g_184;
                }
            }
            else
            {
                uint8_t l_348 = 255UL;
                struct S0 l_369 = {65529UL};
                if (l_348)
                {
                    g_238.f2 ^= l_910;
                    if (g_238.f1)
                        break;
                    if (g_238.f2)
                        continue;
                }
                else
                {
                    if ((safe_lshift_func_int8_t_s_s(((4294967295UL ^ ((((safe_sub_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u((safe_div_func_int32_t_s_s(0x8676E750L, (((safe_rshift_func_uint8_t_u_s((safe_div_func_int64_t_s_s((((l_347 = 1L) >= l_60) < (g_238.f4 , (g_184 != 1UL))), (safe_sub_func_uint8_t_u_u((safe_add_func_int8_t_s_s((g_524 ^= ((g_238.f0 || 255UL) < 0xD6E0L)), 6L)), g_238.f2)))), 1)) , 4294967295UL) , l_347))), l_338)) == l_691.f4) || l_338), 65533UL)) || 0x93L), l_798)) || g_12) >= l_338) , l_367)) == l_368), 3)))
                    {
                        if (l_493)
                            break;
                    }
                    else
                    {

{
                    l_369 = l_369;

if (((((safe_div_func_uint64_t_u_u((l_691.f0 || ((g_191 ^= (((((+(safe_rshift_func_int16_t_s_u(((l_348 ^= (((l_370 = (0xEB54L < l_691.f1)) <= l_691.f2) > g_12)) | g_928), l_950.f0))) ^ (safe_mul_func_int16_t_s_s((l_611 = 9L), (18446744073709551606UL >= l_831)))) != 2UL) <= 0x1EL) < g_873)) || l_691.f3)), 18446744073709551614UL)) != 0xAC861C3EL) < g_791) ^ 0L))
                {
                    l_691 = l_691;
                }
                else
                {
                    uint8_t l_715 = 0x80L;
                    int64_t l_741 = 1L;
                    int64_t l_785 = 0x89D08C2D27B3D546LL;
                    int32_t l_798 = (-4L);
                    int32_t l_809 = 0x4B1AA5B2L;
                    int16_t l_831 = 8L;
                    int32_t l_833 = 0x655BBAA5L;
                    int32_t l_834 = 0x1FA30236L;
                    if (l_609)
                    {
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        l_691.f5 &= (!(l_370 = ((+(safe_mod_func_int32_t_s_s(l_691.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(l_691.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(l_691.f3, (((++l_369.f0) | (l_831 > ((g_191 , (l_958 ^= l_831)) , 0x3CC1CF37L))) != (g_80 == 249UL))))) , l_706), l_950.f0))))) ^ g_241)));
                        l_691 = l_691;
                    }
                    else
                    {
                        uint16_t l_731 = 0UL;
                        uint64_t l_732 = 0xFD49211BAC9527ABLL;
                        uint16_t l_745 = 0x07DBL;
                        l_691.f5 = (((!((((l_691.f0 == (safe_lshift_func_int8_t_s_s(g_928, ((safe_rshift_func_int8_t_s_s((l_691.f2 ^ ((((safe_sub_func_uint64_t_u_u((l_691.f4 &= l_715), (safe_mod_func_int16_t_s_s(((l_691.f4 > 1L) > ((g_791 & ((safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((((l_731 = (0xB1L > (safe_mod_func_uint32_t_u_u((safe_div_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((0xBAL <= l_732), 1UL)) == (-1L)), g_873)) & l_691.f1) == (-1L)) < l_920) && l_691.f0))), __undefined)), 0xE6E002D4L)))) || l_732) >= l_732) == l_348), l_691.f3)) == 1UL) & g_791), l_733)) == 0x4FL)) >= l_691.f2)), l_691.f6)))) < l_369.f0) ^ l_691.f6) , l_691.f4)), g_873)) || 0xA8L)))) > 251UL) , l_920) , l_691.f4)) || l_691.f3) && 0L);
                        l_796 ^= (((safe_lshift_func_int8_t_s_s((l_348 || ((safe_unary_minus_func_int16_t_s((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((l_741 ^= g_12), (g_37 |= ((!(safe_mod_func_uint32_t_u_u((l_691.f0 , ((l_745 && (0x58956D07L && (~((l_374 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_732 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((l_732 ^ (((5UL && ((((l_369 = l_950) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & l_691.f0)) >= 4UL) ^ g_38)) , l_369.f0), l_715)), l_691.f0)) <= l_348)) , l_691.f6), g_33)), g_873)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL)) <= l_691.f0)))) | l_691.f3)), g_1276))) >= 0xC1BC967721442813LL)))) ^ g_378), l_691.f6)))) , 0x2FA0L)), 2)) , l_831) >= 1UL);
                        l_691.f4 = (l_691.f2 = 0xA79062E5L);
                        l_399--;
                    }
                    l_958 = (-1L);
                    if ((safe_add_func_uint16_t_u_u((l_691.f2 = (((((((l_691.f2 , g_37) ^ ((+(safe_lshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(l_691.f3, (l_609 == l_691.f1))), 6))) <= (((8L & (l_609 < (((+(safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u((l_958 = l_691.f2))), (safe_add_func_uint64_t_u_u(g_12, 0xC2CA4FFE53744833LL))))) <= (-5L)) | l_691.f3))) & 1UL) < 0x529AL))) || l_691.f0) , l_691.f1) | g_240) , g_240) > l_691.f6)), g_315)))
                    {
                        uint32_t l_786 = 0xBE94B622L;
                        int8_t l_787 = 0L;
                        int32_t l_788 = 0x65367992L;
                        int32_t l_789 = 0x26FEF397L;
                        int32_t l_790 = 0L;
                        l_786 ^= ((l_950.f0 >= 0UL) <= (safe_div_func_uint8_t_u_u((l_691.f4 && (l_691.f0 = ((((safe_add_func_uint64_t_u_u((l_691.f2 & (+(l_369.f0 |= ((((safe_div_func_int16_t_s_s(((l_785 , 0UL) & g_1276), 0x0D89L)) , 0x9F8EAEBA3A833647LL) != l_715) >= l_609)))), l_370)) != 0x9F1F1DE72F8155A5LL) , 65535UL) , l_691.f2))), 0x27L)));
                        --l_745;
                        g_33--;
                    }
                    else
                    {
                        int8_t l_818 = 2L;
                        int32_t l_828 = (-7L);
                        int32_t l_829 = 1L;
                        int32_t l_830 = (-1L);
                        int32_t l_832 = (-4L);
                        if (g_37)
                            break;
                        l_691.f2 = (safe_rshift_func_uint16_t_u_s((l_368 | (((l_691.f5 <= ((((((((!(safe_sub_func_uint8_t_u_u((g_33--), (g_928 > (((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((l_369.f0 = l_818), (~0x15F3096FL))), (l_820 != g_12))) == (safe_add_func_uint8_t_u_u(253UL, (safe_div_func_int32_t_s_s((safe_unary_minus_func_int32_t_s(((safe_rshift_func_uint8_t_u_u(((++l_942) != ((l_834 = (l_691.f2 == 1UL)) < 0xD0L)), l_732)) ^ g_873))), 8L))))) , 0xE5B274CA6F72970ELL) && 0x791A8EF8E600BD62LL) >= 0x6BL))))) && l_796) && l_691.f2) && 0xDAL) , l_796) <= l_691.f3) >= g_586) >= l_691.f1)) != l_691.f1) > g_33)), l_958));
                        l_958 = (l_691.f0 <= (safe_div_func_uint8_t_u_u((l_691.f5 && (l_950.f0 = 0x40CEL)), (safe_sub_func_int64_t_s_s((((--l_942) >= ((safe_rshift_func_uint8_t_u_s(255UL, 4)) == (((safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((((1L ^ (safe_div_func_uint32_t_u_u(l_370, (safe_mod_func_int16_t_s_s((l_831 >= (safe_mod_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u(l_831, ((l_691.f5 &= ((safe_mod_func_uint8_t_u_u(l_374, l_691.f3)) , l_798)) , 18446744073709551613UL))) && (-8L)) & l_691.f0), (-1L)))), l_691.f2))))) != l_611) , l_833), 5)), 18446744073709551615UL)) & l_691.f4) > l_348))) | (-1L)), l_831)))));
                    }
                };


                    g_238 = g_238;
                }

                    l_369 = l_950;
                    }

for (g_21.f0 = 2; (g_21.f0 >= 18); g_21.f0 = safe_add_func_int64_t_s_s(g_21.f0, 4))
            {
                uint32_t l_1230 = 0xC2612157L;
                int32_t l_1241 = 0x1C3A57D2L;
                int32_t l_1244 = 0x0E65AD9AL;
                int32_t l_1246 = 1L;
                g_238 = g_238;
                l_958 &= (l_859 = (safe_lshift_func_uint8_t_u_s((+(g_80 < (-1L))), 6)));
                if (l_371)
                {
                    uint32_t l_1238 = 0xACAF4E8DL;
                    int32_t l_1240 = 0L;
                    l_859 = g_240;

{
    return g_67;
}

                    g_21 = (g_238.f6 , l_907);
                    g_238.f4 &= l_1230;
                    if (g_65)
                    {
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;

p_57.f2 &= g_793;

                    g_238.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, l_1230)), (l_1239 = (l_1238 = l_673)))), (g_238.f6 , l_1240)));
                        l_610++;
                    }
                    else
                    {
                        l_1240 &= l_885;
                    }
                }
                else
                {
                    uint64_t l_1260 = 0xF5DC1668590A4472LL;
                    int32_t l_1273 = (-1L);
                    int32_t l_1274 = 0xEA32A638L;
                    int32_t l_1275 = 0x813DFFBBL;
                    g_238.f5 = (safe_mod_func_uint8_t_u_u((1UL == (safe_sub_func_uint8_t_u_u(((g_66 && g_238.f4) > ((safe_div_func_uint64_t_u_u(g_33, l_910)) <= (((l_1260 , (safe_rshift_func_uint8_t_u_u(g_238.f4, 5))) != (--l_610)) && (((g_524 & (g_238.f2 = (l_958 ^= (safe_mod_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(0x17F9FA19L, g_527)), 1)) && g_238.f5), 0xD66C9ADCL))))) | g_21.f0) & l_831)))), g_238.f5))), g_66));
                    for (l_60 = 3; (l_60 != 32); l_60 = safe_add_func_uint32_t_u_u(l_60, 4))
                    {
                        ++l_757;
                        if (l_691.f1)
                            {
for (g_524 = (-17); (g_524 > (-21)); --g_524)
                {
                    uint64_t l_641 = 0UL;
                    int32_t l_659 = (-1L);
                    for (l_920 = 0; (l_920 == 39); l_920 = safe_add_func_uint16_t_u_u(l_920, 1))
                    {
                        uint64_t l_657 = 1UL;

g_238.f5 ^= (safe_mod_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(0xAEL, (0x4461L | (l_919 != (l_705 = (g_36 == (g_238.f0 = g_240))))))), g_30));

                    l_691.f5 = 0xC207066FL;
                        l_659 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (l_347 = ((((safe_div_func_uint8_t_u_u(l_920, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(l_370 = (safe_mod_func_uint64_t_u_u(l_641, (l_759 &= ((safe_add_func_int8_t_s_s((g_315 = g_12), (safe_mod_func_int8_t_s_s(p_57.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((p_57.f5 &= g_801), (safe_mod_func_uint8_t_u_u(((~l_400) , p_57.f1), 255UL)))) , l_347) & p_57.f2))))))) != 0xA14CL)))))) <= l_831), l_657))))) && 6UL))) == l_834) <= p_58.f0) <= 1L))) , g_1285), p_58.f0)) == l_691.f4) || p_57.f0) | g_524), g_1285)) , 0x672551F9L) , 0xA150D49BL);
                    }
                    if (((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u(((p_57.f6 & (safe_sub_func_uint8_t_u_u(p_57.f2, l_920))) < (l_1260 |= ((safe_add_func_int8_t_s_s((((l_60 == 0x1D75A18AL) >= (safe_rshift_func_int8_t_s_u(1L, 1))) && (((l_705 , (0x3926L > ((safe_mod_func_int16_t_s_s((g_993 = p_57.f3), l_691.f2)) | g_524))) >= l_691.f6) , (-1L))), g_315)) <= 0L))), 4)), 6)) , 0L))
                    {
                        return l_370;
                    }
                    else
                    {
                        p_57.f5 = p_57.f3;
                        return g_377;
                    }
                };



l_691.f2 &= g_928;

                    break;}
                        if (l_705)
                            continue;
                        g_238.f5 ^= (safe_mod_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(0xAEL, (0x4461L | (l_374 != (l_958 = (g_36 == (g_238.f0 = g_66))))))), l_1273));
                    }
                }
            };



g_12 |= ((safe_add_func_uint64_t_u_u(((g_528 < ((safe_mod_func_uint64_t_u_u(p_57.f0, (((safe_sub_func_int8_t_s_s(((((g_993 = g_182) > (safe_unary_minus_func_uint64_t_u(0xD039656BC93DCDE7LL))) && ((0x1154443CL ^ ((safe_rshift_func_int16_t_s_s((+(safe_sub_func_int32_t_s_s(p_57.f0, 0xA33F1971L))), 6)) , 0xA1E7029EL)) ^ p_58.f0)) == 0L), 0UL)) || 0xA51DB1AF86CBBD6FLL) , g_67))) , g_21.f0)) == p_57.f0), (-10L))) , l_371);


                    return l_338;
                }
            }
        }
        g_968--;
    }

                    l_705 ^= (((safe_lshift_func_int8_t_s_s((g_1276 || ((safe_unary_minus_func_int16_t_s((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((l_741 ^= g_66), (l_834 |= ((!(safe_mod_func_uint32_t_u_u((g_238.f0 , ((l_745 && (0x58956D07L && (~((l_705 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_732 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((l_399 ^ (((5UL && ((((l_950 = l_907) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & g_238.f0)) >= 4UL) ^ g_791)) , l_950.f0), l_715)), g_238.f0)) <= g_33)) , g_238.f6), g_801)), g_1249)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL)) <= g_238.f0)))) | g_238.f3)), l_715))) >= 0xC1BC967721442813LL)))) ^ g_241), g_238.f6)))) , 0x2FA0L)), 2)) , g_184) >= 1UL);
                        g_238.f4 = (g_238.f2 = 0xA79062E5L);
                        l_760--;
                    }
                    l_705 = (-1L);

l_799 |= ((safe_div_func_uint8_t_u_u(((safe_div_func_uint8_t_u_u((safe_div_func_uint16_t_u_u((--l_60), p_57.f0)), (0x5A0BAD988B54577ELL || (l_672 != (l_950 , (safe_lshift_func_int16_t_s_u((-3L), (p_57.f1 | (safe_add_func_int8_t_s_s(p_57.f3, (safe_sub_func_int32_t_s_s((safe_div_func_int8_t_s_s(((l_994 = ((((safe_div_func_int16_t_s_s((0x7BF8L > ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((g_967 = (l_950 , l_833)), 14)), 6)) >= g_993)), g_38)) && 0xD5682F7CL) <= g_182) == l_910)) >= 65527UL), 251UL)), 0xFC6382EAL)))))))))))) > g_993), l_758)) < 1L);

                    if ((safe_add_func_uint16_t_u_u((g_238.f2 = (((((((g_238.f2 , g_65) ^ ((+(safe_lshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(g_238.f3, (g_241 == g_238.f1))), 6))) <= (((8L & (l_610 < (((+(safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u((l_705 = g_238.f2))), (safe_add_func_uint64_t_u_u(g_66, 0xC2CA4FFE53744833LL))))) <= (-5L)) | g_238.f3))) & 1UL) < 0x529AL))) || g_238.f0) , g_238.f1) | g_67) , g_67) > g_238.f6)), g_620)))
                    {
                        uint32_t l_786 = 0xBE94B622L;
                        int8_t l_787 = 0L;
                        int32_t l_788 = 0x65367992L;
                        int32_t l_789 = 0x26FEF397L;
                        int32_t l_790 = 0L;

if ((l_691.f5 = (0xCDL ^ l_691.f1)))
                {
                    return l_797;
                }
                else
                {

p_57.f4 &= l_715;


                    return l_690;
                };


                    l_786 ^= ((l_907.f0 >= 0UL) <= (safe_div_func_uint8_t_u_u((g_238.f4 && (g_238.f0 = ((((safe_add_func_uint64_t_u_u((g_238.f2 & (+(l_950.f0 |= ((((safe_div_func_int16_t_s_s(((l_785 , 0UL) & l_715), 0x0D89L)) , 0x9F8EAEBA3A833647LL) != l_715) >= l_610)))), g_800)) != 0x9F1F1DE72F8155A5LL) , 65535UL) , g_238.f2))), 0x27L)));

{
            int8_t l_937 = 5L;
            l_691 = (l_691 = ((l_797 = ((((l_691.f0 > (safe_lshift_func_int8_t_s_u((safe_div_func_uint8_t_u_u((l_60 != (l_375 , ((l_937 = 0xDABBL) || (safe_add_func_int64_t_s_s((safe_mod_func_int8_t_s_s(g_528, 1UL)), (safe_rshift_func_uint16_t_u_s((g_1249 < (safe_add_func_int8_t_s_s((l_937 >= l_691.f6), g_528))), 7))))))), 1UL)), 0))) && 4294967295UL) > l_691.f5) , l_950.f0)) , l_691));
        }


if (((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u(((l_691.f6 & (safe_sub_func_uint8_t_u_u(l_691.f2, l_610))) < (l_596 |= ((safe_add_func_int8_t_s_s((((l_60 == 0x1D75A18AL) >= (safe_rshift_func_int8_t_s_u(1L, 1))) && (((l_809 , (0x3926L > ((safe_mod_func_int16_t_s_s((g_184 = l_691.f3), g_238.f2)) | g_67))) >= g_238.f6) , (-1L))), g_315)) <= 0L))), 4)), 6)) , 0L))
                    {
                        return l_799;
                    }
                    else
                    {
                        l_691.f5 = l_691.f3;
                        return g_65;
                    };


                    --g_793;
                        g_191--;
                    }
                    else
                    {
                        int8_t l_818 = 2L;
                        int32_t l_828 = (-7L);
                        int32_t l_829 = 1L;
                        int32_t l_830 = (-1L);
                        int32_t l_832 = (-4L);
                        if (g_65)
                            break;
                        g_238.f2 = (safe_rshift_func_uint16_t_u_s((l_834 | (((g_238.f5 <= ((((((((!(safe_sub_func_uint8_t_u_u((g_191--), (g_620 > (((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((l_950.f0 = l_818), (~0x15F3096FL))), (g_36 != g_66))) == (safe_add_func_uint8_t_u_u(253UL, (safe_div_func_int32_t_s_s((safe_unary_minus_func_int32_t_s(((safe_rshift_func_uint8_t_u_u(((++l_942) != ((l_834 = (g_238.f2 == 1UL)) < 0xD0L)), l_399)) ^ g_1249))), 8L))))) , 0xE5B274CA6F72970ELL) && 0x791A8EF8E600BD62LL) >= 0x6BL))))) && l_705) && g_238.f2) && 0xDAL) , g_13) <= g_238.f3) >= g_524) >= g_238.f1)) != g_238.f1) > g_801)), g_800));
                        l_705 = (g_238.f0 <= (safe_div_func_uint8_t_u_u((g_238.f5 && (l_907.f0 = 0x40CEL)), (safe_sub_func_int64_t_s_s((((--l_942) >= ((safe_rshift_func_uint8_t_u_s(255UL, 4)) == (((safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((((1L ^ (safe_div_func_uint32_t_u_u(l_834, (safe_mod_func_int16_t_s_s((g_184 >= (safe_mod_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u(g_184, ((g_238.f5 &= ((safe_mod_func_uint8_t_u_u(l_705, g_238.f3)) , g_800)) , 18446744073709551613UL))) && (-8L)) & g_238.f0), (-1L)))), g_238.f2))))) != g_184) , g_65), 5)), 18446744073709551615UL)) & g_238.f4) > g_1276))) | (-1L)), g_184)))));
                    }
                };



{
                        g_199 = g_21;
                    }


l_674 ^= l_796;


                    if (l_692)
                    {
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        p_57.f5 &= (!(l_673 = ((+(safe_mod_func_int32_t_s_s(p_57.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(p_57.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(g_238.f3, (((++p_58.f0) | (l_690 > ((g_69 , (l_705 ^= l_690)) , 0x3CC1CF37L))) != (l_677 == 249UL))))) , l_706), g_199.f0))))) ^ l_707)));
                        g_238 = p_57;
                    }
                    else
                    {
                        uint16_t l_731 = 0UL;
                        uint64_t l_732 = 0xFD49211BAC9527ABLL;
                        uint16_t l_745 = 0x07DBL;

for (g_240 = (-17); (g_240 > (-21)); --g_240)
                {
                    uint64_t l_641 = 0UL;
                    int32_t l_659 = (-1L);

{
                    return g_184;
                }

                    for (l_692 = 0; (l_692 == 39); l_692 = safe_add_func_uint16_t_u_u(l_692, 1))
                    {
                        uint64_t l_657 = 1UL;
                        g_238.f5 = 0xC207066FL;
                        l_659 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (l_859 = ((((safe_div_func_uint8_t_u_u(g_378, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(l_799 = (safe_mod_func_uint64_t_u_u(l_641, (l_820 &= ((safe_add_func_int8_t_s_s((g_620 = g_67), (safe_mod_func_int8_t_s_s(g_238.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((g_238.f5 &= l_757), (safe_mod_func_uint8_t_u_u(((~g_993) , g_238.f1), 255UL)))) , l_859) & g_238.f2))))))) != 0xA14CL)))))) <= l_611), l_657))))) && 6UL))) == l_798) <= l_907.f0) <= 1L))) , g_1285), l_907.f0)) == g_238.f4) || g_238.f0) | g_240), g_1285)) , 0x672551F9L) , 0xA150D49BL);
                    }
                    if (((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u(((g_238.f6 & (safe_sub_func_uint8_t_u_u(g_238.f2, l_692))) < (l_733 |= ((safe_add_func_int8_t_s_s((((g_1285 == 0x1D75A18AL) >= (safe_rshift_func_int8_t_s_u(1L, 1))) && (((l_799 , (0x3926L > ((safe_mod_func_int16_t_s_s((l_831 = g_238.f3), g_238.f2)) | g_240))) >= g_238.f6) , (-1L))), g_620)) <= 0L))), 4)), 6)) , 0L))
                    {
                        return l_799;
                    }
                    else
                    {
                        g_238.f5 = g_238.f3;
                        return l_798;
                    }
                }
{
                if ((l_691.f5 = (0xCDL ^ l_691.f1)))
                {
                    return g_791;
                }
                else
                {
                    return g_184;
                }
            }


l_68 |= (((safe_add_func_uint64_t_u_u((l_785 < (l_705 = ((l_691.f4 = l_691.f2) < l_834))), 0xB4C6519C0C658331LL)) | l_691.f1) , 0x869ACDBBBB3DB403LL);


                    ;


                    p_57.f5 = (((!((((p_57.f0 == (safe_lshift_func_int8_t_s_s(g_315, ((safe_rshift_func_int8_t_s_s((p_57.f2 ^ ((((safe_sub_func_uint64_t_u_u((l_691.f4 &= l_715), (safe_mod_func_int16_t_s_s(((p_57.f4 > 1L) > ((g_571 & ((safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((((l_731 = (0xB1L > (safe_mod_func_uint32_t_u_u((safe_div_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((0xBAL <= l_399), 1UL)) == (-1L)), l_609)) & p_57.f1) == (-1L)) < g_301) && p_57.f0))), g_32)), 0xE6E002D4L)))) || l_732) >= l_732) == l_687), l_691.f3)) == 1UL) & g_377), l_733)) == 0x4FL)) >= p_57.f2)), p_57.f6)))) < p_58.f0) ^ g_238.f6) , g_238.f4)), g_182)) || 0xA8L)))) > 251UL) , g_301) , l_691.f4)) || p_57.f3) && 0L);

{
    return g_12;
}

                    l_375 ^= (((safe_lshift_func_int8_t_s_s((g_191 || ((safe_unary_minus_func_int16_t_s((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((l_741 ^= g_66), (g_65 |= ((!(safe_mod_func_uint32_t_u_u((g_238.f0 , ((l_745 && (0x58956D07L && (~((l_758 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_732 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((l_579 ^ (((5UL && ((((p_58 = g_199) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & p_57.f0)) >= 4UL) ^ g_756)) , p_58.f0), l_715)), p_57.f0)) <= l_687)) , p_57.f6), l_757)), g_182)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL)) <= g_238.f0)))) | p_57.f3)), g_322))) >= 0xC1BC967721442813LL)))) ^ l_610), p_57.f6)))) , 0x2FA0L)), 2)) , l_690) >= 1UL);

if (l_611)
        {
            struct S0 l_200 = {0x8CAFL};
            int32_t l_205 = (-1L);
            int32_t l_208 = 0x15D7F043L;
            uint16_t l_215 = 0xEBE3L;
            struct S1 l_237 = {4888,4404,-28,3688,-181,0,4061};
            int32_t l_239 = 0x45497A7BL;
            for (l_760 = 14; (l_760 == 54); l_760++)
            {
                uint16_t l_196 = 1UL;
                l_196--;
                l_200 = g_21;
            }
            g_791 = (((safe_sub_func_uint8_t_u_u(l_707, (g_12 , g_21.f0))) < ((l_215 = (l_691.f4 &= (+((((-1L) & ((0xAFL < (((l_860 == ((((l_691.f2 = (l_205 = (g_21 , 8L))) <= ((((((l_399++) ^ l_611) >= l_200.f0) , g_21) , g_21.f0) ^ (-7L))) > l_831) ^ l_611)) , 18446744073709551613UL) > l_373)) ^ l_200.f0)) && g_315) != 0x8890B9DDL)))) <= p_58.f0)) , l_691.f1);
            l_691 = ((((((safe_mod_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s(((l_910 = (safe_lshift_func_int16_t_s_s((((((((safe_sub_func_int32_t_s_s(((((((safe_rshift_func_int16_t_s_s((+(l_611 && (g_586 = (-1L)))), (l_831 = l_796))) && (((safe_mod_func_uint16_t_u_u(l_215, (safe_lshift_func_uint8_t_u_s(((g_21.f0 , 1L) , (0x34L != (safe_lshift_func_int8_t_s_s((safe_mod_func_uint64_t_u_u((l_611 >= (safe_add_func_uint64_t_u_u((g_527 == 4294967290UL), l_611))), g_21.f0)), l_691.f5)))), 5)))) | l_205) & 0x8900E08CL)) || l_399) || l_611) <= 0x3DL) < g_12), g_12)) | 0xBFBDL) < g_21.f0) > l_809) != g_21.f0) | g_21.f0) <= 0xDC97BAAAL), 4))) || l_373), g_12)) | g_33) == g_800), l_373)) ^ l_215) ^ l_611) || 1L) , l_707) , l_237);
            l_707++;
        }
        else
        {
            uint32_t l_265 = 0x211A307CL;
            l_691.f2 |= ((safe_lshift_func_uint8_t_u_s(255UL, (safe_rshift_func_uint8_t_u_s(l_399, 2)))) & (safe_sub_func_int16_t_s_s(l_691.f2, 1L)));
            l_796 &= (g_21 , l_691.f0);
            l_797 ^= (l_691.f5 = (l_691.f2 = (safe_div_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(p_58.f0, (((0x5DL > l_796) != (safe_unary_minus_func_int16_t_s(1L))) == ((((((l_707 > (safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_u(0xCBFBL, 6)) < (safe_add_func_uint32_t_u_u((((safe_sub_func_uint64_t_u_u(((((g_21 = g_21) , 0xA2463E9B3E846025LL) , (safe_div_func_int32_t_s_s(l_373, 0x810FC398L))) | l_265), l_831)) ^ l_265) || g_12), g_21.f0))), l_860))) ^ l_265) >= l_265) , p_57) , 249UL) , l_611)))) >= 5L) >= 255UL) , l_691.f6), l_611))));
        };


                    p_57.f4 = (p_57.f2 = 0xA79062E5L);
                        l_760--;
                    }

{
                        g_21 = g_21;
                    }


{
            uint32_t l_163 = 0UL;
            int32_t l_168 = 0x35FECE65L;
            int32_t l_185 = 1L;
            int32_t l_186 = 0xCCA4C161L;
            int32_t l_187 = 5L;
            g_968 ^= (g_586 == ((safe_mod_func_int16_t_s_s(((safe_div_func_uint64_t_u_u(((0x23B04249L >= (safe_mod_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s(((((g_21 = g_21) , g_21) , (safe_lshift_func_uint16_t_u_s((++l_163), (safe_mod_func_uint32_t_u_u(l_168, (safe_div_func_int32_t_s_s((g_12 > ((l_907.f0 |= (safe_sub_func_uint64_t_u_u((safe_add_func_int32_t_s_s((65530UL | (safe_div_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(0x88AFL, (safe_add_func_int16_t_s_s((((g_21 = p_58) , (-10L)) & 0xC4A096ABL), 0xBEFCL)))), l_596))), g_586)), l_833))) ^ 0x3F1CL)), 0xBE4CFF9CL))))))) < g_791), 7)) | l_691.f2) || l_757), l_690))) != 0x1A2308598B864A24LL), l_691.f5)) < 1L), 0x8ABAL)) < l_690));
            --l_869;

{
                    if ((safe_lshift_func_int8_t_s_s(((4294967295UL ^ ((((safe_sub_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u((safe_div_func_int32_t_s_s(0x8676E750L, (((safe_rshift_func_uint8_t_u_s((safe_div_func_int64_t_s_s((((l_375 = 1L) >= g_1285) < (l_691.f4 , (l_400 != 1UL))), (safe_sub_func_uint8_t_u_u((safe_add_func_int8_t_s_s((g_524 ^= ((l_691.f0 || 255UL) < 0xD6E0L)), 6L)), l_691.f2)))), 1)) , 4294967295UL) , l_375))), l_797)) == l_691.f4) || l_797), 65533UL)) || 0x93L), l_809)) || g_586) >= l_797) , g_1276)) == g_37), 3)))
                    {
                        if (g_36)
                            break;
                    }
                    else
                    {
                        l_907 = g_21;
                    }
                    return l_797;
                }

                    g_801++;
        }

                    l_705 = (-1L);
                    if ((safe_add_func_uint16_t_u_u((l_691.f2 = (((((((l_691.f2 , g_30) ^ ((+(safe_lshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(p_57.f3, (g_80 == p_57.f1))), 6))) <= (((8L & (l_692 < (((+(safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u((l_705 = p_57.f2))), (safe_add_func_uint64_t_u_u(g_524, 0xC2CA4FFE53744833LL))))) <= (-5L)) | p_57.f3))) & 1UL) < 0x529AL))) || p_57.f0) , p_57.f1) | g_240) , g_240) > p_57.f6)), l_60)))
                    {
                        uint32_t l_786 = 0xBE94B622L;
                        int8_t l_787 = 0L;
                        int32_t l_788 = 0x65367992L;
                        int32_t l_789 = 0x26FEF397L;
                        int32_t l_790 = 0L;
                        l_786 ^= ((g_199.f0 >= 0UL) <= (safe_div_func_uint8_t_u_u((p_57.f4 && (p_57.f0 = ((((safe_add_func_uint64_t_u_u((p_57.f2 & (+(p_58.f0 |= ((((safe_div_func_int16_t_s_s(((l_785 , 0UL) & g_322), 0x0D89L)) , 0x9F8EAEBA3A833647LL) != l_715) >= l_692)))), l_673)) != 0x9F1F1DE72F8155A5LL) , 65535UL) , p_57.f2))), 0x27L)));
                        --g_793;

{
        int8_t l_126 = 0x41L;
        struct S0 l_158 = {65535UL};
        int32_t l_162 = (-1L);
        int8_t l_181 = 0x56L;
        int32_t l_206 = 0x501F8A61L;
        int32_t l_207 = 1L;
        int32_t l_209 = 0L;
        int32_t l_210 = 0x9105A86EL;
        int32_t l_211 = 0L;
        uint16_t l_214 = 0xEB0AL;
        struct S1 l_266 = {8020,8046,-6,1087,99,-0,4038};
        g_756 = ((func_101(l_690, (((safe_lshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s(((((safe_add_func_int16_t_s_s(((9UL == 18446744073709551614UL) & (safe_lshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u((-1L), (65532UL != g_528))), 1))), g_528)) <= ((safe_div_func_int64_t_s_s(((safe_mod_func_uint64_t_u_u((((((!2L) & (--l_399)) > ((safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(((((safe_add_func_int32_t_s_s(g_528, 1UL)) | l_789) , 1L) || l_126), l_400)), g_21.f0)) >= g_21.f0)) >= g_21.f0) & g_33), l_958)) && g_12), 0xCC1C6A88B8388ADFLL)) >= g_528)) , g_12) < l_994), 13)), 3)) && l_126), 4)), l_493)), 6)) <= l_126) != 1UL)) >= g_240) <= l_859);
        l_789 = ((((p_57 , 0xCFL) <= (g_199.f0 == (0xFF4B716CAE9C981CLL < l_126))) <= (0x1CL < ((g_240 , l_126) , ((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(0xAF64L, g_199.f0)) != l_400), l_690)), 0x92ADL)) < l_690)))) | 0xFAL);
        for (g_199.f0 = 0; (g_199.f0 != 25); g_199.f0 = safe_add_func_int64_t_s_s(g_199.f0, 8))
        {
            uint32_t l_163 = 0UL;
            int32_t l_168 = 0x35FECE65L;
            int32_t l_185 = 1L;
            int32_t l_186 = 0xCCA4C161L;
            int32_t l_187 = 5L;
            g_80 ^= (g_12 == ((safe_mod_func_int16_t_s_s(((safe_div_func_uint64_t_u_u(((0x23B04249L >= (safe_mod_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s(((((g_199 = l_158) , g_199) , (safe_lshift_func_uint16_t_u_s((++l_163), (safe_mod_func_uint32_t_u_u(l_168, (safe_div_func_int32_t_s_s((g_240 > ((g_21.f0 |= (safe_sub_func_uint64_t_u_u((safe_add_func_int32_t_s_s((65530UL | (safe_div_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(0x88AFL, (safe_add_func_int16_t_s_s((((l_158 = g_199) , (-10L)) & 0xC4A096ABL), 0xBEFCL)))), l_994))), l_181)), g_756))) ^ 0x3F1CL)), 0xBE4CFF9CL))))))) < l_162), 7)) | p_57.f2) || l_757), l_690))) != 0x1A2308598B864A24LL), p_57.f5)) < 1L), 0x8ABAL)) < l_690));
            --l_687;

if (l_266.f1)
                            continue;

                    g_188++;
        }
        if (l_400)
        {
            struct S0 l_200 = {0x8CAFL};
            int32_t l_205 = (-1L);
            int32_t l_208 = 0x15D7F043L;
            uint16_t l_215 = 0xEBE3L;
            struct S1 l_237 = {4888,4404,-28,3688,-181,0,4061};
            int32_t l_239 = 0x45497A7BL;
            for (l_399 = 14; (l_399 == 54); l_399++)
            {
                uint16_t l_196 = 1UL;
                l_196--;
                l_200 = l_907;
            }
            l_789 = (((safe_sub_func_uint8_t_u_u(l_674, (g_12 , g_21.f0))) < ((l_215 = (p_57.f4 &= (+((((-1L) & ((0xAFL < (((l_687 == ((((p_57.f2 = (l_205 = (g_21 , 8L))) <= ((((((l_994++) ^ l_400) >= l_200.f0) , g_199) , g_199.f0) ^ (-7L))) > l_690) ^ l_400)) , 18446744073709551613UL) > l_958)) ^ l_200.f0)) && l_214) != 0x8890B9DDL)))) <= l_158.f0)) , p_57.f1);
            g_238 = ((((((safe_mod_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s(((g_188 = (safe_lshift_func_int16_t_s_s((((((((safe_sub_func_int32_t_s_s(((((((safe_rshift_func_int16_t_s_s((+(l_400 && (g_240 = (-1L)))), (l_690 = g_756))) && (((safe_mod_func_uint16_t_u_u(l_215, (safe_lshift_func_uint8_t_u_s(((g_21.f0 , 1L) , (0x34L != (safe_lshift_func_int8_t_s_s((safe_mod_func_uint64_t_u_u((l_400 >= (safe_add_func_uint64_t_u_u((l_493 == 4294967290UL), l_400))), g_21.f0)), p_57.f5)))), 5)))) | l_205) & 0x8900E08CL)) || l_994) || l_400) <= 0x3DL) < g_12), g_12)) | 0xBFBDL) < l_907.f0) > l_210) != g_21.f0) | g_199.f0) <= 0xDC97BAAAL), 4))) || l_958), g_12)) | g_33) == l_211), l_798)) ^ l_215) ^ l_400) || 1L) , l_674) , l_237);
            l_692++;
        }
        else
        {
            uint32_t l_265 = 0x211A307CL;
            g_238.f2 |= ((safe_lshift_func_uint8_t_u_s(255UL, (safe_rshift_func_uint8_t_u_s(l_994, 2)))) & (safe_sub_func_int16_t_s_s(p_57.f2, 1L)));

{
                uint8_t l_348 = 255UL;
                struct S0 l_369 = {65529UL};
                if (l_348)
                {
                    l_266.f2 ^= g_322;
                    if (l_266.f1)
                        break;
                    if (l_266.f2)
                        continue;
                }
                else
                {
                    if ((safe_lshift_func_int8_t_s_s(((4294967295UL ^ ((((safe_sub_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u((safe_div_func_int32_t_s_s(0x8676E750L, (((safe_rshift_func_uint8_t_u_s((safe_div_func_int64_t_s_s((((l_375 = 1L) >= g_315) < (l_266.f4 , (g_184 != 1UL))), (safe_sub_func_uint8_t_u_u((safe_add_func_int8_t_s_s((l_181 ^= ((l_266.f0 || 255UL) < 0xD6E0L)), 6L)), l_266.f2)))), 1)) , 4294967295UL) , l_375))), g_967)) == l_266.f4) || g_967), 65533UL)) || 0x93L), l_859)) || g_67) >= g_967) , g_188)) == g_791), 3)))
                    {
                        if (g_36)
                            break;
                    }
                    else
                    {
                        l_369 = l_950;
                    }
                    return g_967;
                }
            }

                    g_756 &= (g_21 , p_57.f0);
            l_207 ^= (p_57.f5 = (g_238.f2 = (safe_div_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(l_158.f0, (((0x5DL > g_756) != (safe_unary_minus_func_int16_t_s(1L))) == ((((((l_674 > (safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_u(0xCBFBL, 6)) < (safe_add_func_uint32_t_u_u((((safe_sub_func_uint64_t_u_u(((((g_21 = g_21) , 0xA2463E9B3E846025LL) , (safe_div_func_int32_t_s_s(l_958, 0x810FC398L))) | l_265), l_690)) ^ l_265) || g_12), g_199.f0))), l_687))) ^ l_265) >= l_265) , l_266) , 249UL) , l_400)))) >= 5L) >= 255UL) , p_57.f6), l_400))));
        }
    }

                    g_801--;
                    }
                    else
                    {
                        int8_t l_818 = 2L;
                        int32_t l_828 = (-7L);
                        int32_t l_829 = 1L;
                        int32_t l_830 = (-1L);
                        int32_t l_832 = (-4L);

{
                        uint64_t l_657 = 1UL;
                        g_238.f5 = 0xC207066FL;
                        l_375 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (l_958 = ((((safe_div_func_uint8_t_u_u(g_80, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(g_183 = (safe_mod_func_uint64_t_u_u(l_994, (g_527 &= ((safe_add_func_int8_t_s_s((g_928 = g_240), (safe_mod_func_int8_t_s_s(g_238.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((g_238.f5 &= g_33), (safe_mod_func_uint8_t_u_u(((~g_993) , g_238.f1), 255UL)))) , l_958) & g_238.f2))))))) != 0xA14CL)))))) <= l_690), l_657))))) && 6UL))) == g_792) <= g_21.f0) <= 1L))) , g_793), g_21.f0)) == g_238.f4) || g_238.f0) | g_524), g_793)) , 0x672551F9L) , 0xA150D49BL);
                    }

                    if (g_30)
                            {
{
                    uint64_t l_641 = 0UL;
                    int32_t l_659 = (-1L);
                    for (l_677 = 0; (l_677 == 39); l_677 = safe_add_func_uint16_t_u_u(l_677, 1))
                    {
                        uint64_t l_657 = 1UL;
                        l_691.f5 = 0xC207066FL;
                        l_659 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (g_791 = ((((safe_div_func_uint8_t_u_u(g_301, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(g_791 = (safe_mod_func_uint64_t_u_u(l_641, (g_527 &= ((safe_add_func_int8_t_s_s((g_620 = g_240), (safe_mod_func_int8_t_s_s(l_691.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((l_691.f5 &= g_33), (safe_mod_func_uint8_t_u_u(((~g_184) , l_691.f1), 255UL)))) , g_791) & l_691.f2))))))) != 0xA14CL)))))) <= l_400), l_657))))) && 6UL))) == l_375) <= g_199.f0) <= 1L))) , g_928), g_199.f0)) == l_691.f4) || l_691.f0) | l_818), g_928)) , 0x672551F9L) , 0xA150D49BL);
                    }
                    if (((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u(((l_691.f6 & (safe_sub_func_uint8_t_u_u(l_691.f2, l_677))) < (l_596 |= ((safe_add_func_int8_t_s_s((((g_315 == 0x1D75A18AL) >= (safe_rshift_func_int8_t_s_u(1L, 1))) && (((l_758 , (0x3926L > ((safe_mod_func_int16_t_s_s((l_831 = l_691.f3), l_691.f2)) | l_818))) >= l_691.f6) , (-1L))), g_620)) <= 0L))), 4)), 6)) , 0L))
                    {
                        return g_791;
                    }
                    else
                    {

l_690 |= (safe_add_func_int32_t_s_s((l_691.f5 = ((((g_33 != (((((0x05L == ((0x25L ^ (safe_lshift_func_uint16_t_u_u((((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s((l_907 , l_691.f5), (((g_238 , l_691.f3) , g_238) , 0L))) || l_796), g_528)) >= g_238.f4) >= 7UL), 13))) < g_33)) , 0x67L) & l_860) , 0xC3L) | g_378)) || l_691.f6) , 0L) , l_830)), g_1276));


                    l_691.f5 = l_691.f3;
                        return l_758;
                    }
                }

                    break;}

for (l_785 = 16; (l_785 != 15); l_785 = safe_sub_func_int32_t_s_s(l_785, 1))
                    {
                        int32_t l_1099 = 0x29D6DC62L;
                        l_920 |= ((safe_add_func_uint16_t_u_u(((safe_div_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_s((l_687 |= g_238.f1), 0)) <= l_690), (((safe_lshift_func_uint16_t_u_u((g_315 |= (((l_809 = l_610) | ((g_238.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((l_690 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((g_800 |= (((safe_add_func_uint64_t_u_u((l_785 < (g_800 = ((g_238.f4 = p_57.f2) < l_830))), 0xB4C6519C0C658331LL)) | p_57.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), l_1099)) , g_620)) > p_57.f4) || p_57.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > p_57.f1)) && g_199.f0) && g_586) & l_797)) ^ g_620) & l_60)) >= 0UL) , l_1099)) != l_910)) || 0x2FL)), g_586)) < p_57.f1) || 4294967294UL))) & g_199.f0), 65535UL)) >= p_57.f4);
                        if (p_57.f1)
                            continue;
                    };


                    p_57.f2 = (safe_rshift_func_uint16_t_u_s((l_799 | (((p_57.f5 <= ((((((((!(safe_sub_func_uint8_t_u_u((g_801--), (g_620 > (((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((p_58.f0 = l_818), (~0x15F3096FL))), (l_820 != g_524))) == (safe_add_func_uint8_t_u_u(253UL, (safe_div_func_int32_t_s_s((safe_unary_minus_func_int32_t_s(((safe_rshift_func_uint8_t_u_u(((++g_378) != ((l_834 = (p_57.f2 == 1UL)) < 0xD0L)), l_579)) ^ g_182))), 8L))))) , 0xE5B274CA6F72970ELL) && 0x791A8EF8E600BD62LL) >= 0x6BL))))) && l_375) && p_57.f2) && 0xDAL) , g_800) <= p_57.f3) >= g_586) >= p_57.f1)) != p_57.f1) > g_33)), l_672));

{
                int32_t l_519 = (-1L);
                int32_t l_521 = 0xC5583EF5L;

{
        int8_t l_126 = 0x41L;
        struct S0 l_158 = {65535UL};
        int32_t l_162 = (-1L);
        int8_t l_181 = 0x56L;
        int32_t l_206 = 0x501F8A61L;
        int32_t l_207 = 1L;
        int32_t l_209 = 0L;
        int32_t l_210 = 0x9105A86EL;
        int32_t l_211 = 0L;
        uint16_t l_214 = 0xEB0AL;
        struct S1 l_266 = {8020,8046,-6,1087,99,-0,4038};
        g_37 = ((func_101(l_611, (((safe_lshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s(((((safe_add_func_int16_t_s_s(((9UL == 18446744073709551614UL) & (safe_lshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u((-1L), (65532UL != g_1249))), 1))), g_1249)) <= ((safe_div_func_int64_t_s_s(((safe_mod_func_uint64_t_u_u((((((!2L) & (--l_733)) > ((safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(((((safe_add_func_int32_t_s_s(g_1249, 1UL)) | l_68) , 1L) || l_126), l_690)), g_199.f0)) >= g_199.f0)) >= g_199.f0) & g_801), l_373)) && g_524), 0xCC1C6A88B8388ADFLL)) >= g_1249)) , g_524) < l_579), 13)), 3)) && l_126), 4)), g_527)), 6)) <= l_126) != 1UL)) >= g_524) <= l_830);

l_942 ^= l_830;


                    l_68 = ((((g_238 , 0xCFL) <= (p_58.f0 == (0xFF4B716CAE9C981CLL < l_126))) <= (0x1CL < ((g_524 , l_126) , ((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(0xAF64L, p_58.f0)) != l_690), l_611)), 0x92ADL)) < l_611)))) | 0xFAL);
        for (p_58.f0 = 0; (p_58.f0 != 25); p_58.f0 = safe_add_func_int64_t_s_s(p_58.f0, 8))
        {
            uint32_t l_163 = 0UL;
            int32_t l_168 = 0x35FECE65L;
            int32_t l_185 = 1L;
            int32_t l_186 = 0xCCA4C161L;
            int32_t l_187 = 5L;
            l_609 ^= (l_818 == ((safe_mod_func_int16_t_s_s(((safe_div_func_uint64_t_u_u(((0x23B04249L >= (safe_mod_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s(((((g_199 = l_158) , g_199) , (safe_lshift_func_uint16_t_u_s((++l_163), (safe_mod_func_uint32_t_u_u(l_168, (safe_div_func_int32_t_s_s((g_524 > ((g_199.f0 |= (safe_sub_func_uint64_t_u_u((safe_add_func_int32_t_s_s((65530UL | (safe_div_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(0x88AFL, (safe_add_func_int16_t_s_s((((l_158 = p_58) , (-10L)) & 0xC4A096ABL), 0xBEFCL)))), l_579))), l_181)), g_37))) ^ 0x3F1CL)), 0xBE4CFF9CL))))))) < l_162), 7)) | g_238.f2) || g_69), l_611))) != 0x1A2308598B864A24LL), g_238.f5)) < 1L), 0x8ABAL)) < l_611));
            --g_801;
            l_687++;
        }


g_377 &= ((g_65 | (safe_mod_func_int16_t_s_s(((func_44(((safe_rshift_func_int16_t_s_s((l_705 |= p_57.f3), (l_919 <= 6L))) , (safe_sub_func_uint64_t_u_u(l_797, l_994)))) , p_57.f2) | ((safe_sub_func_int8_t_s_s(0xA4L, p_57.f3)) <= g_800)), g_800))) || (-1L));

                    if (l_206)
                    goto lbl_464;



{
                        l_691.f5 = l_691.f3;
                        return g_791;
                    }

                    if ((safe_mod_func_int64_t_s_s(l_757, (safe_mod_func_uint64_t_u_u(g_12, (safe_add_func_int64_t_s_s(((safe_add_func_uint32_t_u_u(g_36, ((l_690 |= (safe_add_func_int32_t_s_s((g_238.f5 = ((((g_188 != (((((0x05L == ((0x25L ^ (safe_lshift_func_uint16_t_u_u((((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s((g_21 , g_238.f5), (((l_691 , g_238.f3) , l_266) , 0L))) || g_37), g_80)) >= l_691.f4) >= 7UL), 13))) < l_757)) , 0x67L) & l_757) , 0xC3L) | g_182)) || g_238.f6) , 0L) , g_13)), l_910))) >= 0x08DCL))) == g_13), l_181)))))))
                {
                    uint64_t l_1054 = 0UL;
                    g_13 &= (((g_240 != 0x8446L) , p_58) , (((l_1054 ^ g_21.f0) , ((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u((safe_add_func_int64_t_s_s(((1UL & (safe_rshift_func_int8_t_s_u((safe_add_func_int64_t_s_s((g_80 <= (l_691 , (safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(((((safe_mod_func_uint16_t_u_u(l_691.f3, l_860)) || g_238.f6) ^ l_1054) , g_571), 8)) | l_266.f3), 5L)))), l_211)), g_238.f4))) | g_37), 0xCBB7D04007C17F65LL)), g_756)), g_238.f5)) > (-1L))) >= p_58.f0));
                }
                else
                {
                    int8_t l_1100 = (-7L);
                    int32_t l_1104 = 0L;
                    int32_t l_1111 = 0x36BD596BL;
                    uint16_t l_1129 = 65535UL;
                    g_238.f2 ^= (((((g_873 >= 0L) <= l_211) || ((safe_add_func_uint64_t_u_u((safe_div_func_int32_t_s_s((g_524 , ((((0L <= (0xAF2AFC70L || ((l_691.f1 |= ((((safe_sub_func_uint16_t_u_u(g_67, (safe_lshift_func_uint16_t_u_u(1UL, l_214)))) , 0x08EAL) > 0x7146L) == 0x51A9FA1A770123F4LL)) && l_799))) != l_677) || l_828) >= g_238.f3)), 4294967295UL)), 0x8134BAAB9636E740LL)) | 0x429EL)) || g_80) && l_759);
                    for (g_36 = 16; (g_36 != 15); g_36 = safe_sub_func_int32_t_s_s(g_36, 1))
                    {
                        int32_t l_1099 = 0x29D6DC62L;
                        g_182 |= ((safe_add_func_uint16_t_u_u(((safe_div_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_s((l_757 |= l_691.f1), 0)) <= l_611), (((safe_lshift_func_uint16_t_u_u((g_620 |= (((g_37 = g_80) | ((l_691.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((l_690 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((l_210 |= (((safe_add_func_uint64_t_u_u((g_36 < (l_519 = ((l_691.f4 = g_238.f2) < g_571))), 0xB4C6519C0C658331LL)) | g_238.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), l_1099)) , l_214)) > g_238.f4) || g_238.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > g_238.f1)) && g_21.f0) && l_1100) & g_13)) ^ l_214) & l_214)) >= 0UL) , l_1099)) != l_910)) || 0x2FL)), l_1100)) < g_238.f1) || 4294967294UL))) & g_21.f0), 65535UL)) >= g_238.f4);
                        if (g_238.f1)
                            continue;
                    }
                    l_691.f5 = (safe_add_func_int8_t_s_s(((0L > (((l_1104 |= 0x342AL) && (l_181 & (safe_div_func_uint8_t_u_u(0xA3L, (safe_rshift_func_uint16_t_u_u(0x820EL, 10)))))) , 1L)) , (safe_rshift_func_uint8_t_u_s((l_860++), 5))), (safe_add_func_int8_t_s_s(((0x5EA5295EB42C2F9DLL && (safe_rshift_func_int16_t_s_u(((safe_div_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((l_519 &= l_1100), ((((safe_add_func_uint16_t_u_u((g_21.f0 = ((g_188 < l_797) <= 0x6B6EL)), l_1129)) , g_182) , g_238) , 0xCCL))), g_571)), g_66)), l_757)) && g_238.f2), g_238.f5))) || l_757), l_596))));
                    g_238 = (l_266 = l_691);
                };



{
                        return l_162;
                    }

                    if (l_690)
        {
            struct S0 l_200 = {0x8CAFL};
            int32_t l_205 = (-1L);
            int32_t l_208 = 0x15D7F043L;
            uint16_t l_215 = 0xEBE3L;
            struct S1 l_237 = {4888,4404,-28,3688,-181,0,4061};
            int32_t l_239 = 0x45497A7BL;
            for (l_733 = 14; (l_733 == 54); l_733++)
            {
                uint16_t l_196 = 1UL;
                l_196--;


l_237.f2 ^= (-8L);


                    if (p_57.f1)
                            break;


l_239 &= l_610;

                    l_200 = p_58;
            }
            l_68 = (((safe_sub_func_uint8_t_u_u(l_942, (g_524 , g_199.f0))) < ((l_215 = (g_238.f4 &= (+((((-1L) & ((0xAFL < (((g_801 == ((((g_238.f2 = (l_205 = (g_199 , 8L))) <= ((((((l_579++) ^ l_690) >= l_200.f0) , p_58) , p_58.f0) ^ (-7L))) > l_611) ^ l_690)) , 18446744073709551613UL) > l_373)) ^ l_200.f0)) && l_214) != 0x8890B9DDL)))) <= l_158.f0)) , g_238.f1);
            p_57 = ((((((safe_mod_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s(((l_687 = (safe_lshift_func_int16_t_s_s((((((((safe_sub_func_int32_t_s_s(((((((safe_rshift_func_int16_t_s_s((+(l_690 && (g_524 = (-1L)))), (l_611 = g_37))) && (((safe_mod_func_uint16_t_u_u(l_215, (safe_lshift_func_uint8_t_u_s(((g_199.f0 , 1L) , (0x34L != (safe_lshift_func_int8_t_s_s((safe_mod_func_uint64_t_u_u((l_690 >= (safe_add_func_uint64_t_u_u((g_527 == 4294967290UL), l_690))), g_199.f0)), g_238.f5)))), 5)))) | l_205) & 0x8900E08CL)) || l_579) || l_690) <= 0x3DL) < g_524), g_524)) | 0xBFBDL) < p_58.f0) > l_210) != g_199.f0) | p_58.f0) <= 0xDC97BAAAL), 4))) || l_373), g_524)) | g_801) == l_211), l_829)) ^ l_215) ^ l_690) || 1L) , l_942) , l_237);
            l_609++;
        }
        else
        {
            uint32_t l_265 = 0x211A307CL;

{
    return g_586;
}


l_691.f4 ^= 0x1529816DL;

                    p_57.f2 |= ((safe_lshift_func_uint8_t_u_s(255UL, (safe_rshift_func_uint8_t_u_s(l_579, 2)))) & (safe_sub_func_int16_t_s_s(g_238.f2, 1L)));
            g_37 &= (g_199 , g_238.f0);

{
                uint16_t l_196 = 1UL;
                l_196--;
                g_199 = l_907;
            }

                    l_207 ^= (g_238.f5 = (p_57.f2 = (safe_div_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(l_158.f0, (((0x5DL > g_37) != (safe_unary_minus_func_int16_t_s(1L))) == ((((((l_942 > (safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_u(0xCBFBL, 6)) < (safe_add_func_uint32_t_u_u((((safe_sub_func_uint64_t_u_u(((((g_199 = g_199) , 0xA2463E9B3E846025LL) , (safe_div_func_int32_t_s_s(l_373, 0x810FC398L))) | l_265), l_611)) ^ l_265) || l_818), p_58.f0))), g_801))) ^ l_265) >= l_265) , l_266) , 249UL) , l_690)))) >= 5L) >= 255UL) , g_238.f6), l_690))));
        }
    }

                    l_830 &= ((0L < (((((safe_add_func_int64_t_s_s(((safe_lshift_func_int16_t_s_s(((-10L) | g_30), ((safe_sub_func_int16_t_s_s((g_791 = (((g_38 |= ((safe_sub_func_int32_t_s_s(((safe_sub_func_int16_t_s_s(l_691.f2, (l_785 = (safe_sub_func_uint8_t_u_u(l_60, (((l_691 , l_691.f1) , l_691) , (safe_add_func_uint8_t_u_u((safe_sub_func_uint64_t_u_u(((((l_707++) && (l_707 != 0xAEL)) ^ 0x9714L) <= 0xD7EAL), 0x1FBFD773E599F898LL)), g_69)))))))) < l_691.f5), l_831)) < l_60)) && 0x22L) ^ l_733)), l_831)) != l_691.f5))) , g_524), g_378)) != g_80) > l_687) || g_791) <= g_21.f0)) || l_691.f2);

if (((safe_mod_func_int32_t_s_s((g_30 , (((safe_lshift_func_int8_t_s_s((safe_div_func_int64_t_s_s((safe_mod_func_int64_t_s_s(((l_375 , (((g_238.f5 < ((safe_sub_func_int32_t_s_s((g_1276 <= ((safe_div_func_int64_t_s_s(((g_571 = ((safe_lshift_func_uint16_t_u_u(p_57.f1, 9)) <= ((((g_238.f1 ^ (g_301 = ((((!(((+(-5L)) >= 0x2077L) | (((safe_lshift_func_uint16_t_u_s((safe_unary_minus_func_int32_t_s((safe_lshift_func_uint16_t_u_u(0x3FE3L, 15)))), 9)) < 0x3ED2BC827CFBFAACLL) == 0UL))) <= 0xEE3FL) && 0xCB01CDCFF5673DEALL) , l_399))) | 0x05B4L) , g_199.f0) > 0xF83382B7L))) == 1UL), l_818)) <= 0xF8L)), l_611)) , g_968)) , g_241) >= l_373)) , 0x1B3F29B522290BD6LL), p_57.f3)), p_57.f5)), l_375)) == l_798) <= 0x80L)), l_611)) == g_30))
                {
                    uint16_t l_451 = 0x721EL;
                    int32_t l_453 = (-1L);

p_57.f4 &= ((((g_30 &= 0x62L) <= ((l_958 = ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^ (g_792 = l_832)) & (safe_rshift_func_uint16_t_u_s(0x2310L, 10))) , ((l_798 ^ ((l_705 &= (l_818 != ((((l_400 = ((g_967 & ((~((((g_21 , (g_12 ^ p_57.f3)) > g_12) != 0x2A7A2EF32379F2B3LL) != g_183)) && l_818)) && l_818)) >= 0L) , 0x1AL) | 0x83L))) >= p_57.f2)) != g_12)) <= g_967) && (-1L)) || p_57.f1) , g_12)) | 1UL)) > 5L) ^ 0xDF8CL);

                    p_57.f2 = ((g_571 |= (((l_833 ^ (safe_rshift_func_int16_t_s_s(0x7DA3L, 14))) , (safe_lshift_func_int8_t_s_u(l_451, 1))) != (safe_unary_minus_func_int16_t_s((l_453 = 0xBB70L))))) & ((safe_mod_func_uint8_t_u_u((safe_div_func_uint32_t_u_u((!((((p_57.f4 , g_241) < p_57.f0) , (safe_div_func_int64_t_s_s((g_527 = ((safe_add_func_uint64_t_u_u(p_57.f6, (g_527 = 0L))) >= (-1L))), l_373))) , 0x779BL)), g_241)), p_57.f6)) > p_57.f3));
                }
                else
                {
                    g_199 = g_199;
                    g_238 = g_238;
                }
{
                uint8_t l_348 = 255UL;
                struct S0 l_369 = {65529UL};

if ((safe_sub_func_int16_t_s_s(((((((safe_lshift_func_int8_t_s_s((0x6EL & (safe_rshift_func_uint16_t_u_s(g_65, (l_919 = l_691.f4)))), g_527)) <= ((0xD471L < (safe_lshift_func_uint8_t_u_s(l_818, 7))) || g_65)) != (((l_691.f0 & (((g_12 = (((safe_unary_minus_func_int64_t_s(((g_377 , g_993) | l_691.f2))) | 7UL) <= 0x3B9260F6L)) ^ g_65) , g_1249)) , l_691.f1) | l_691.f6)) >= l_691.f4) > g_527) || l_399), l_399)))
    {
        uint32_t l_609 = 0UL;
        uint32_t l_610 = 18446744073709551615UL;
        int16_t l_611 = 1L;
        int32_t l_672 = (-1L);
        int32_t l_673 = 0x5BAB80C9L;
        uint32_t l_677 = 4294967288UL;
        struct S1 l_691 = {14501,5528,-0,7773,227,0,2285};
        uint32_t l_707 = 0xF605241DL;
        uint64_t l_733 = 18446744073709551611UL;
        int64_t l_820 = 0x28812E388A6D2202LL;
        uint8_t l_860 = 0xD6L;
        uint8_t l_869 = 0x70L;
        uint32_t l_885 = 0x7EBE34DAL;
        struct S0 l_907 = {65533UL};
        int32_t l_919 = (-5L);
        if ((l_818 & (((((l_691 , (l_399 && l_399)) | (safe_mod_func_uint16_t_u_u(((l_958 , ((safe_sub_func_uint16_t_u_u(((((2UL & (safe_add_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(l_860, l_691.f3)), ((safe_sub_func_uint8_t_u_u((safe_div_func_int64_t_s_s(0xEC0DF3DED07D7D71LL, 0xFE38C1710C6551B0LL)), l_691.f3)) , 65532UL)))) , 0x598DL) > l_609) || l_609), l_609)) == l_691.f0)) || l_610), l_611))) <= l_691.f5) > 0xB0L) || l_869)))
        {
            uint16_t l_644 = 7UL;
            int32_t l_655 = 0x4245560AL;
            int32_t l_658 = 1L;
            for (g_527 = 16; (g_527 >= (-4)); g_527 = safe_sub_func_int64_t_s_s(g_527, 9))
            {
                uint16_t l_614 = 0x585DL;
                ++l_614;
                return l_691.f2;
            }
            for (l_611 = 0; (l_611 >= 5); ++l_611)
            {
                int16_t l_619 = 6L;
                int16_t l_656 = 0xF40CL;
                ++g_1285;
                for (g_12 = (-17); (g_12 > (-21)); --g_12)
                {
                    uint64_t l_641 = 0UL;
                    int32_t l_659 = (-1L);
                    for (l_609 = 0; (l_609 == 39); l_609 = safe_add_func_uint16_t_u_u(l_609, 1))
                    {
                        uint64_t l_657 = 1UL;
                        l_691.f5 = 0xC207066FL;
                        l_659 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (g_65 = ((((safe_div_func_uint8_t_u_u(l_610, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(l_655 = (safe_mod_func_uint64_t_u_u(l_641, (l_759 &= ((safe_add_func_int8_t_s_s((l_644 = l_818), (safe_mod_func_int8_t_s_s(l_691.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((l_691.f5 &= l_869), (safe_mod_func_uint8_t_u_u(((~l_619) , l_691.f1), 255UL)))) , g_65) & l_691.f2))))))) != 0xA14CL)))))) <= l_656), l_657))))) && 6UL))) == l_658) <= l_950.f0) <= 1L))) , g_315), l_950.f0)) == l_691.f4) || l_691.f0) | g_12), g_315)) , 0x672551F9L) , 0xA150D49BL);
                    }
                    if (((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u(((l_691.f6 & (safe_sub_func_uint8_t_u_u(l_691.f2, l_609))) < (l_994 |= ((safe_add_func_int8_t_s_s((((g_1285 == 0x1D75A18AL) >= (safe_rshift_func_int8_t_s_u(1L, 1))) && (((g_37 , (0x3926L > ((safe_mod_func_int16_t_s_s((g_993 = l_691.f3), l_691.f2)) | g_12))) >= l_691.f6) , (-1L))), l_644)) <= 0L))), 4)), 6)) , 0L))
                    {

l_831 |= (safe_add_func_int32_t_s_s((p_57.f5 = ((((l_715 != (((((0x05L == ((0x25L ^ (safe_lshift_func_uint16_t_u_u((((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s((l_369 , p_57.f5), (((p_57 , p_57.f3) , g_238) , 0L))) || l_797), l_942)) >= p_57.f4) >= 7UL), 13))) < l_715)) , 0x67L) & l_715) , 0xC3L) | l_677)) || p_57.f6) , 0L) , l_655)), l_348));


                    return l_655;
                    }
                    else
                    {
                        l_691.f5 = l_691.f3;
                        return l_958;
                    }
                }
            }
            g_1249++;

{
        struct S0 l_267 = {0xB8F5L};
        l_267 = (l_369.f0 , p_58);
        l_369 = l_369;
    }

                    ++l_677;
        }
        else
        {
            uint8_t l_687 = 2UL;
            uint32_t l_692 = 4294967291UL;
            int32_t l_758 = (-6L);
            int64_t l_759 = 0x10201B5C969F6449LL;
            int32_t l_796 = (-1L);
            int32_t l_797 = 0x66E5B6A1L;
            int32_t l_799 = (-9L);
            for (l_610 = (-14); (l_610 != 49); l_610 = safe_add_func_uint8_t_u_u(l_610, 3))
            {
                int16_t l_690 = (-1L);
                int32_t l_705 = 3L;
                if (((((safe_div_func_uint64_t_u_u((l_691.f0 || ((l_860 ^= (((((+(safe_rshift_func_int16_t_s_u(((l_687 ^= (((l_673 = (0xEB54L < l_691.f1)) <= l_691.f2) > g_12)) | g_315), l_950.f0))) ^ (safe_mul_func_int16_t_s_s((g_993 = 9L), (18446744073709551606UL >= l_690)))) != 2UL) <= 0x1EL) < l_609)) || l_691.f3)), 18446744073709551614UL)) != 0xAC861C3EL) < l_830) ^ 0L))
                {

l_869 |= g_238.f1;


                    l_691 = l_691;
                }
                else
                {
                    uint8_t l_715 = 0x80L;
                    int64_t l_741 = 1L;
                    int64_t l_785 = 0x89D08C2D27B3D546LL;
                    int32_t l_798 = (-4L);
                    int32_t l_809 = 0x4B1AA5B2L;
                    int16_t l_831 = 8L;
                    int32_t l_833 = 0x655BBAA5L;
                    int32_t l_834 = 0x1FA30236L;
                    if (l_692)
                    {
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        l_691.f5 &= (!(l_673 = ((+(safe_mod_func_int32_t_s_s(l_691.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(l_691.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(l_691.f3, (((++l_950.f0) | (l_690 > ((l_860 , (l_705 ^= l_690)) , 0x3CC1CF37L))) != (l_677 == 249UL))))) , l_706), l_950.f0))))) ^ l_707)));
                        l_691 = l_691;
                    }
                    else
                    {
                        uint16_t l_731 = 0UL;
                        uint64_t l_732 = 0xFD49211BAC9527ABLL;
                        uint16_t l_745 = 0x07DBL;
                        l_691.f5 = (((!((((l_691.f0 == (safe_lshift_func_int8_t_s_s(g_315, ((safe_rshift_func_int8_t_s_s((l_691.f2 ^ ((((safe_sub_func_uint64_t_u_u((l_691.f4 &= l_715), (safe_mod_func_int16_t_s_s(((l_691.f4 > 1L) > ((l_830 & ((safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((((l_731 = (0xB1L > (safe_mod_func_uint32_t_u_u((safe_div_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((0xBAL <= l_399), 1UL)) == (-1L)), l_609)) & l_691.f1) == (-1L)) < l_610) && l_691.f0))), __undefined)), 0xE6E002D4L)))) || l_732) >= l_732) == l_687), l_691.f3)) == 1UL) & g_967), l_733)) == 0x4FL)) >= l_691.f2)), l_691.f6)))) < l_950.f0) ^ l_691.f6) , l_691.f4)), g_1249)) || 0xA8L)))) > 251UL) , l_610) , l_691.f4)) || l_691.f3) && 0L);
                        g_377 ^= (((safe_lshift_func_int8_t_s_s((l_348 || ((safe_unary_minus_func_int16_t_s((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((l_741 ^= l_818), (l_958 |= ((!(safe_mod_func_uint32_t_u_u((l_691.f0 , ((l_745 && (0x58956D07L && (~((l_758 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_732 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((l_399 ^ (((5UL && ((((l_950 = l_950) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & l_691.f0)) >= 4UL) ^ g_756)) , l_950.f0), l_715)), l_691.f0)) <= l_687)) , l_691.f6), g_69)), g_1249)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL)) <= l_691.f0)))) | l_691.f3)), l_869))) >= 0xC1BC967721442813LL)))) ^ l_610), l_691.f6)))) , 0x2FA0L)), 2)) , l_690) >= 1UL);
                        l_691.f4 = (l_691.f2 = 0xA79062E5L);
                        l_760--;
                    }
                    l_705 = (-1L);
                    if ((safe_add_func_uint16_t_u_u((l_691.f2 = (((((((l_691.f2 , l_830) ^ ((+(safe_lshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(l_691.f3, (l_610 == l_691.f1))), 6))) <= (((8L & (l_692 < (((+(safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u((l_705 = l_691.f2))), (safe_add_func_uint64_t_u_u(l_818, 0xC2CA4FFE53744833LL))))) <= (-5L)) | l_691.f3))) & 1UL) < 0x529AL))) || l_691.f0) , l_691.f1) | g_12) , g_12) > l_691.f6)), g_1285)))
                    {
                        uint32_t l_786 = 0xBE94B622L;
                        int8_t l_787 = 0L;
                        int32_t l_788 = 0x65367992L;
                        int32_t l_789 = 0x26FEF397L;
                        int32_t l_790 = 0L;
                        l_786 ^= ((l_950.f0 >= 0UL) <= (safe_div_func_uint8_t_u_u((l_691.f4 && (l_691.f0 = ((((safe_add_func_uint64_t_u_u((l_691.f2 & (+(l_950.f0 |= ((((safe_div_func_int16_t_s_s(((l_785 , 0UL) & l_869), 0x0D89L)) , 0x9F8EAEBA3A833647LL) != l_715) >= l_692)))), l_673)) != 0x9F1F1DE72F8155A5LL) , 65535UL) , l_691.f2))), 0x27L)));
                        --g_1285;
                        l_860--;
                    }
                    else
                    {
                        int8_t l_818 = 2L;
                        int32_t l_828 = (-7L);
                        int32_t l_829 = 1L;
                        int32_t l_830 = (-1L);
                        int32_t l_832 = (-4L);
                        if (l_830)
                            break;
                        l_691.f2 = (safe_rshift_func_uint16_t_u_s((l_799 | (((l_691.f5 <= ((((((((!(safe_sub_func_uint8_t_u_u((l_860--), (g_1285 > (((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((l_950.f0 = l_818), (~0x15F3096FL))), (l_820 != l_818))) == (safe_add_func_uint8_t_u_u(253UL, (safe_div_func_int32_t_s_s((safe_unary_minus_func_int32_t_s(((safe_rshift_func_uint8_t_u_u(((++l_677) != ((l_834 = (l_691.f2 == 1UL)) < 0xD0L)), l_399)) ^ g_1249))), 8L))))) , 0xE5B274CA6F72970ELL) && 0x791A8EF8E600BD62LL) >= 0x6BL))))) && g_377) && l_691.f2) && 0xDAL) , l_830) <= l_691.f3) >= g_12) >= l_691.f1)) != l_691.f1) > l_715)), l_672));
                        l_705 = (l_691.f0 <= (safe_div_func_uint8_t_u_u((l_691.f5 && (l_950.f0 = 0x40CEL)), (safe_sub_func_int64_t_s_s((((--l_677) >= ((safe_rshift_func_uint8_t_u_s(255UL, 4)) == (((safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((((1L ^ (safe_div_func_uint32_t_u_u(l_797, (safe_mod_func_int16_t_s_s((l_690 >= (safe_mod_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u(l_690, ((l_691.f5 &= ((safe_mod_func_uint8_t_u_u(l_758, l_691.f3)) , l_797)) , 18446744073709551613UL))) && (-8L)) & l_691.f0), (-1L)))), l_691.f2))))) != g_993) , g_792), 5)), 18446744073709551615UL)) & l_691.f4) > l_860))) | (-1L)), l_690)))));
                    }
                }
                l_830 = l_691.f3;
            }
        }
        for (l_399 = 0; (l_399 > 1); l_399++)
        {
            int32_t l_870 = (-1L);
            l_958 = (l_691.f3 , (safe_rshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(l_860, 13)), l_869)), 10)));
            return l_870;
        }
        for (g_1285 = 0; (g_1285 < 19); g_1285 = safe_add_func_int64_t_s_s(g_1285, 7))
        {
            int32_t l_878 = 0xFC2DEAD7L;
            int32_t l_897 = 0xF61E11E5L;
            l_691.f2 = ((l_950.f0 == ((((l_885 = (((((l_885++) <= (l_672 = (((0x792DL || (safe_rshift_func_uint16_t_u_s(l_878, 13))) || (((l_950.f0--) != (l_691.f5 ^= (0x70BD7A420812CA0FLL > (safe_rshift_func_int16_t_s_u((((l_691 = l_691) , l_691.f0) , (safe_rshift_func_uint8_t_u_s(l_691.f5, (0xF1AA9032L >= l_691.f6)))), 1))))) , 0xE25AB159L)) < l_348))) != 255UL) != g_967) ^ (-1L))) <= l_820) , 0x7AF6L) >= 1UL)) >= l_860);
            l_950 = (l_907 = (((((safe_add_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(((safe_div_func_uint8_t_u_u((l_691.f5 = (safe_unary_minus_func_uint8_t_u(0UL))), ((g_792 ^ ((safe_add_func_int32_t_s_s((safe_add_func_uint8_t_u_u((++l_869), (safe_sub_func_uint32_t_u_u(l_830, (safe_rshift_func_uint16_t_u_s(l_897, ((((-1L) || (-6L)) != ((~0x65L) < (((((l_691.f4 = (((safe_lshift_func_uint16_t_u_u(((l_878 >= l_897) | l_878), g_993)) >= 0xA9570CA5L) & l_691.f5)) , l_691.f6) > l_818) & l_691.f2) ^ 0x1299A5A1L))) | 0xB6L))))))), 2UL)) , l_715)) && (-1L)))) == 0xD6L), l_691.f6)), g_12)) >= l_691.f5) <= 0xFEBE5530D01B6D3DLL) > l_691.f4) , l_950));
            g_65 = l_878;
        }

l_950.f0 |= ((((safe_div_func_int16_t_s_s(((g_527 , 0UL) & g_801), 0x0D89L)) , 0x9F8EAEBA3A833647LL) != l_860) >= g_80);


                    l_830 |= (((safe_add_func_int8_t_s_s((((((g_65 ^= ((l_673 = l_672) , g_191)) >= (l_691.f4 = ((safe_add_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u((safe_mod_func_uint64_t_u_u(0x5357627B9C38BE8CLL, (safe_rshift_func_int8_t_s_u((((l_691.f2 < (l_919 = l_691.f4)) ^ (g_315 & (l_609 <= (g_993 = l_818)))) < (g_792 = ((((l_691.f5 = (safe_mod_func_int8_t_s_s((safe_div_func_int32_t_s_s(((l_691.f2 ^= (-8L)) || 0xF7D7L), l_677)), 0x7AL))) ^ g_993) < l_707) <= g_756))), 6)))), l_610)) | l_691.f3) , 0x4DL), l_609)) && 4294967292UL))) != 4294967293UL) || 0x61L) == 1UL), 0x74L)) , (-5L)) , l_610);
    }
    else
    {
        int64_t l_925 = 0xA73062E26A32E214LL;
        int32_t l_926 = 0x25CEF752L;
        int32_t l_927 = 0xAB24C309L;
        struct S1 l_947 = {21304,6517,-24,3525,164,0,2283};
        g_620++;
        for (l_958 = (-27); (l_958 < 10); ++l_958)
        {
            int8_t l_937 = 5L;
            l_947 = (l_691 = ((l_919 = ((((l_691.f0 > (safe_lshift_func_int8_t_s_u((safe_div_func_uint8_t_u_u((g_1285 != (l_927 , ((l_937 = 0xDABBL) || (safe_add_func_int64_t_s_s((safe_mod_func_int8_t_s_s(l_692, 1UL)), (safe_rshift_func_uint16_t_u_s((l_609 < (safe_add_func_int8_t_s_s((l_937 >= l_691.f6), l_692))), 7))))))), 1UL)), 0))) && 4294967295UL) > l_691.f5) , l_950.f0)) , l_691));
        }
        l_947.f2 = 0L;
        for (l_677 = 0; (l_677 >= 10); ++l_677)
        {
            l_907 = (g_792 , l_907);
        }
    };


                    if (l_348)
                {
                    l_691.f2 ^= l_869;
                    if (l_691.f1)
                        break;
                    if (l_691.f2)
                        continue;
                }
                else
                {
                    if ((safe_lshift_func_int8_t_s_s(((4294967295UL ^ ((((safe_sub_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u((safe_div_func_int32_t_s_s(0x8676E750L, (((safe_rshift_func_uint8_t_u_s((safe_div_func_int64_t_s_s((((l_758 = 1L) >= l_60) < (l_691.f4 , (l_690 != 1UL))), (safe_sub_func_uint8_t_u_u((safe_add_func_int8_t_s_s((g_586 ^= ((l_691.f0 || 255UL) < 0xD6E0L)), 6L)), l_691.f2)))), 1)) , 4294967295UL) , l_758))), l_798)) == g_238.f4) || l_798), 65533UL)) || 0x93L), g_30)) || g_524) >= l_798) , l_869)) == l_373), 3)))
                    {
                        if (g_36)
                            break;
                    }
                    else
                    {
                        l_369 = g_21;
                    }
                    return l_798;
                }
            }

                    ;


                    g_1249++;
                l_691.f4 &= (safe_sub_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(l_596, 0x32B0L)), 0x8C89L));
            }

                    l_705 = (p_57.f0 <= (safe_div_func_uint8_t_u_u((p_57.f5 && (g_199.f0 = 0x40CEL)), (safe_sub_func_int64_t_s_s((((--g_378) >= ((safe_rshift_func_uint8_t_u_s(255UL, 4)) == (((safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((((1L ^ (safe_div_func_uint32_t_u_u(g_792, (safe_mod_func_int16_t_s_s((l_690 >= (safe_mod_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u(l_690, ((l_691.f5 &= ((safe_mod_func_uint8_t_u_u(l_758, p_57.f3)) , l_797)) , 18446744073709551613UL))) && (-8L)) & p_57.f0), (-1L)))), p_57.f2))))) != g_184) , l_859), 5)), 18446744073709551615UL)) & l_691.f4) > l_860))) | (-1L)), l_690)))));
                    }
                }
                g_30 = l_691.f3;
            }
        }
        for (l_399 = 0; (l_399 > 1); l_399++)
        {
            int32_t l_870 = (-1L);

if (g_571)
                    {
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;
                        l_691.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, g_182)), (l_1239 = (g_80 = l_373)))), (l_691.f6 , l_859)));
                        l_942++;
                    }
                    else
                    {
                        l_859 &= g_182;
                    };


                    g_37 = (p_57.f3 , (safe_rshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(g_69, 13)), l_869)), 10)));

{
                    int8_t l_1100 = (-7L);
                    int32_t l_1104 = 0L;
                    int32_t l_1111 = 0x36BD596BL;
                    uint16_t l_1129 = 65535UL;
                    g_238.f2 ^= (((((g_873 >= 0L) <= g_13) || ((safe_add_func_uint64_t_u_u((safe_div_func_int32_t_s_s((g_67 , ((((0L <= (0xAF2AFC70L || ((p_57.f1 |= ((((safe_sub_func_uint16_t_u_u(g_586, (safe_lshift_func_uint16_t_u_u(1UL, g_1285)))) , 0x08EAL) > 0x7146L) == 0x51A9FA1A770123F4LL)) && l_870))) != g_241) || l_870) >= g_238.f3)), 4294967295UL)), 0x8134BAAB9636E740LL)) | 0x429EL)) || g_1249) && g_36);
                    for (l_820 = 16; (l_820 != 15); l_820 = safe_sub_func_int32_t_s_s(l_820, 1))
                    {
                        int32_t l_1099 = 0x29D6DC62L;
                        g_1249 |= ((safe_add_func_uint16_t_u_u(((safe_div_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_s((g_188 |= p_57.f1), 0)) <= g_184), (((safe_lshift_func_uint16_t_u_u((g_793 |= (((g_30 = g_873) | ((p_57.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((l_611 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((g_791 |= (((safe_add_func_uint64_t_u_u((l_493 < (l_68 = ((p_57.f4 = g_238.f2) < l_859))), 0xB4C6519C0C658331LL)) | g_238.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), l_1099)) , g_1285)) > g_238.f4) || g_238.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > g_238.f1)) && g_21.f0) && l_1100) & g_13)) ^ g_1285) & g_315)) >= 0UL) , l_1099)) != g_33)) || 0x2FL)), l_1100)) < g_238.f1) || 4294967294UL))) & l_907.f0), 65535UL)) >= g_238.f4);

for (g_315 = 0; (g_315 < 19); g_315 = safe_add_func_int64_t_s_s(g_315, 7))
        {
            int32_t l_878 = 0xFC2DEAD7L;
            int32_t l_897 = 0xF61E11E5L;
            g_238.f2 = ((g_199.f0 == ((((g_301 = (((((g_241++) <= (g_30 = (((0x792DL || (safe_rshift_func_uint16_t_u_s(l_878, 13))) || (((l_950.f0--) != (g_238.f5 ^= (0x70BD7A420812CA0FLL > (safe_rshift_func_int16_t_s_u((((p_57 = p_57) , g_238.f0) , (safe_rshift_func_uint8_t_u_s(p_57.f5, (0xF1AA9032L >= p_57.f6)))), 1))))) , 0xE25AB159L)) < g_188))) != 255UL) != g_756) ^ (-1L))) <= l_820) , 0x7AF6L) >= 1UL)) >= l_869);
            g_199 = (g_199 = (((((safe_add_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(((safe_div_func_uint8_t_u_u((g_238.f5 = (safe_unary_minus_func_uint8_t_u(0UL))), ((l_673 ^ ((safe_add_func_int32_t_s_s((safe_add_func_uint8_t_u_u((++l_910), (safe_sub_func_uint32_t_u_u(l_1111, (safe_rshift_func_uint16_t_u_s(l_897, ((((-1L) || (-6L)) != ((~0x65L) < (((((p_57.f4 = (((safe_lshift_func_uint16_t_u_u(((l_878 >= l_897) | l_878), g_184)) >= 0xA9570CA5L) & p_57.f5)) , p_57.f6) > g_240) & p_57.f2) ^ 0x1299A5A1L))) | 0xB6L))))))), 2UL)) , l_910)) && (-1L)))) == 0xD6L), g_238.f6)), g_12)) >= p_57.f5) <= 0xFEBE5530D01B6D3DLL) > g_238.f4) , l_950));
            l_673 = l_878;
        };



{
                int16_t l_690 = (-1L);
                int32_t l_705 = 3L;
                if (((((safe_div_func_uint64_t_u_u((p_57.f0 || ((g_188 ^= (((((+(safe_rshift_func_int16_t_s_u(((g_801 ^= (((g_571 = (0xEB54L < p_57.f1)) <= l_691.f2) > l_1100)) | g_1285), g_199.f0))) ^ (safe_mul_func_int16_t_s_s((g_993 = 9L), (18446744073709551606UL >= l_690)))) != 2UL) <= 0x1EL) < l_885)) || p_57.f3)), 18446744073709551614UL)) != 0xAC861C3EL) < g_967) ^ 0L))
                {
                    l_691 = l_691;
                }
                else
                {
                    uint8_t l_715 = 0x80L;
                    int64_t l_741 = 1L;
                    int64_t l_785 = 0x89D08C2D27B3D546LL;
                    int32_t l_798 = (-4L);
                    int32_t l_809 = 0x4B1AA5B2L;
                    int16_t l_831 = 8L;
                    int32_t l_833 = 0x655BBAA5L;
                    int32_t l_834 = 0x1FA30236L;
                    if (l_610)
                    {
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        p_57.f5 &= (!(g_571 = ((+(safe_mod_func_int32_t_s_s(p_57.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(p_57.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(l_691.f3, (((++l_950.f0) | (l_690 > ((g_188 , (l_705 ^= l_690)) , 0x3CC1CF37L))) != (g_1249 == 249UL))))) , l_706), g_199.f0))))) ^ g_80)));
                        l_691 = p_57;
                    }
                    else
                    {
                        uint16_t l_731 = 0UL;
                        uint64_t l_732 = 0xFD49211BAC9527ABLL;
                        uint16_t l_745 = 0x07DBL;
                        p_57.f5 = (((!((((p_57.f0 == (safe_lshift_func_int8_t_s_s(g_1285, ((safe_rshift_func_int8_t_s_s((p_57.f2 ^ ((((safe_sub_func_uint64_t_u_u((l_691.f4 &= l_715), (safe_mod_func_int16_t_s_s(((p_57.f4 > 1L) > ((g_967 & ((safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((((l_731 = (0xB1L > (safe_mod_func_uint32_t_u_u((safe_div_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((((((safe_rshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((0xBAL <= l_596), 1UL)) == (-1L)), l_885)) & p_57.f1) == (-1L)) < g_241) && p_57.f0))), l_493)), 0xE6E002D4L)))) || l_732) >= l_732) == g_801), l_691.f3)) == 1UL) & g_791), l_994)) == 0x4FL)) >= p_57.f2)), p_57.f6)))) < l_950.f0) ^ l_691.f6) , l_691.f4)), g_182)) || 0xA8L)))) > 251UL) , g_241) , l_691.f4)) || p_57.f3) && 0L);
                        l_919 ^= (((safe_lshift_func_int8_t_s_s((g_188 || ((safe_unary_minus_func_int16_t_s((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((l_741 ^= g_67), (l_68 |= ((!(safe_mod_func_uint32_t_u_u((l_691.f0 , ((l_745 && (0x58956D07L && (~((g_800 &= ((safe_unary_minus_func_int32_t_s(((((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((l_732 == ((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((l_579 ^ (((5UL && ((((l_950 = g_199) , 0x96A9F1C011E70F5ALL) == 0x500E37B86AC15818LL) & p_57.f0)) >= 4UL) ^ l_958)) , l_950.f0), l_715)), p_57.f0)) <= g_801)) , p_57.f6), l_869)), g_182)) == 0xF049L) && (-1L)) , 1L))) <= 0x965BL)) <= l_691.f0)))) | p_57.f3)), l_910))) >= 0xC1BC967721442813LL)))) ^ l_609), p_57.f6)))) , 0x2FA0L)), 2)) , l_690) >= 1UL);
                        p_57.f4 = (p_57.f2 = 0xA79062E5L);
                        l_994--;
                    }
                    l_705 = (-1L);
                    if ((safe_add_func_uint16_t_u_u((l_691.f2 = (((((((l_691.f2 , g_30) ^ ((+(safe_lshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(p_57.f3, (g_378 == p_57.f1))), 6))) <= (((8L & (l_610 < (((+(safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u((l_705 = p_57.f2))), (safe_add_func_uint64_t_u_u(l_1100, 0xC2CA4FFE53744833LL))))) <= (-5L)) | p_57.f3))) & 1UL) < 0x529AL))) || p_57.f0) , p_57.f1) | g_240) , g_240) > p_57.f6)), g_928)))
                    {
                        uint32_t l_786 = 0xBE94B622L;
                        int8_t l_787 = 0L;
                        int32_t l_788 = 0x65367992L;
                        int32_t l_789 = 0x26FEF397L;
                        int32_t l_790 = 0L;
                        l_786 ^= ((g_199.f0 >= 0UL) <= (safe_div_func_uint8_t_u_u((p_57.f4 && (p_57.f0 = ((((safe_add_func_uint64_t_u_u((p_57.f2 & (+(l_950.f0 |= ((((safe_div_func_int16_t_s_s(((l_785 , 0UL) & l_910), 0x0D89L)) , 0x9F8EAEBA3A833647LL) != l_715) >= l_610)))), g_571)) != 0x9F1F1DE72F8155A5LL) , 65535UL) , p_57.f2))), 0x27L)));
                        --g_793;
                        g_322--;
                    }
                    else
                    {
                        int8_t l_818 = 2L;
                        int32_t l_828 = (-7L);
                        int32_t l_829 = 1L;
                        int32_t l_830 = (-1L);
                        int32_t l_832 = (-4L);
                        if (g_30)
                            break;
                        p_57.f2 = (safe_rshift_func_uint16_t_u_s((l_375 | (((p_57.f5 <= ((((((((!(safe_sub_func_uint8_t_u_u((g_322--), (g_1285 > (((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s((l_950.f0 = l_818), (~0x15F3096FL))), (g_527 != l_1100))) == (safe_add_func_uint8_t_u_u(253UL, (safe_div_func_int32_t_s_s((safe_unary_minus_func_int32_t_s(((safe_rshift_func_uint8_t_u_u(((++g_80) != ((l_834 = (p_57.f2 == 1UL)) < 0xD0L)), l_579)) ^ g_182))), 8L))))) , 0xE5B274CA6F72970ELL) && 0x791A8EF8E600BD62LL) >= 0x6BL))))) && l_919) && p_57.f2) && 0xDAL) , g_13) <= p_57.f3) >= l_1100) >= p_57.f1)) != p_57.f1) > l_910)), l_375));
                        l_705 = (p_57.f0 <= (safe_div_func_uint8_t_u_u((p_57.f5 && (g_199.f0 = 0x40CEL)), (safe_sub_func_int64_t_s_s((((--g_80) >= ((safe_rshift_func_uint8_t_u_s(255UL, 4)) == (((safe_div_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((((1L ^ (safe_div_func_uint32_t_u_u(l_870, (safe_mod_func_int16_t_s_s((l_690 >= (safe_mod_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u(l_690, ((l_691.f5 &= ((safe_mod_func_uint8_t_u_u(g_800, p_57.f3)) , g_967)) , 18446744073709551613UL))) && (-8L)) & p_57.f0), (-1L)))), p_57.f2))))) != g_993) , g_791), 5)), 18446744073709551615UL)) & l_691.f4) > l_910))) | (-1L)), l_690)))));
                    }
                }
                g_30 = l_691.f3;
            }

                    if (g_238.f1)
                            continue;
                    }
                    p_57.f5 = (safe_add_func_int8_t_s_s(((0L > (((l_1104 |= 0x342AL) && (g_240 & (safe_div_func_uint8_t_u_u(0xA3L, (safe_rshift_func_uint16_t_u_u(0x820EL, 10)))))) , 1L)) , (safe_rshift_func_uint8_t_u_s((g_33++), 5))), (safe_add_func_int8_t_s_s(((0x5EA5295EB42C2F9DLL && (safe_rshift_func_int16_t_s_u(((safe_div_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((l_68 &= l_1100), ((((safe_add_func_uint16_t_u_u((g_21.f0 = ((g_33 < g_792) <= 0x6B6EL)), l_1129)) , g_1249) , g_238) , 0xCCL))), l_859)), g_67)), g_188)) && g_238.f2), g_238.f5))) || g_188), l_994))));

{
                    uint64_t l_641 = 0UL;
                    int32_t l_659 = (-1L);
                    for (l_707 = 0; (l_707 == 39); l_707 = safe_add_func_uint16_t_u_u(l_707, 1))
                    {
                        uint64_t l_657 = 1UL;
                        l_691.f5 = 0xC207066FL;
                        l_659 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (l_672 = ((((safe_div_func_uint8_t_u_u(g_182, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(g_967 = (safe_mod_func_uint64_t_u_u(l_641, (g_527 &= ((safe_add_func_int8_t_s_s((l_60 = g_524), (safe_mod_func_int8_t_s_s(p_57.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((p_57.f5 &= l_869), (safe_mod_func_uint8_t_u_u(((~g_993) , p_57.f1), 255UL)))) , l_672) & p_57.f2))))))) != 0xA14CL)))))) <= g_184), l_657))))) && 6UL))) == l_673) <= p_58.f0) <= 1L))) , g_793), p_58.f0)) == l_691.f4) || p_57.f0) | l_1100), g_793)) , 0x672551F9L) , 0xA150D49BL);
                    }
                    if (((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u(((p_57.f6 & (safe_sub_func_uint8_t_u_u(p_57.f2, l_707))) < (l_733 |= ((safe_add_func_int8_t_s_s((((g_928 == 0x1D75A18AL) >= (safe_rshift_func_int8_t_s_u(1L, 1))) && (((l_672 , (0x3926L > ((safe_mod_func_int16_t_s_s((g_184 = p_57.f3), l_691.f2)) | l_1100))) >= l_691.f6) , (-1L))), l_60)) <= 0L))), 4)), 6)) , 0L))
                    {
                        return g_967;
                    }
                    else
                    {
                        p_57.f5 = p_57.f3;
                        return l_958;
                    }
                }

                    p_57 = (g_238 = p_57);
                }


if (l_373)
                    goto lbl_464;

                    return l_870;
        }

l_907.f0 |= (safe_lshift_func_int8_t_s_u((safe_mod_func_uint8_t_u_u((safe_sub_func_uint64_t_u_u((((g_199.f0--) & (((0xF021F418L ^ (safe_rshift_func_int8_t_s_u(((7UL > ((g_238.f4 ^ (-5L)) , l_733)) <= g_792), l_611))) > g_238.f1) ^ l_596)) ^ g_301), g_240)), g_30)), l_68));


                    for (l_60 = 0; (l_60 < 19); l_60 = safe_add_func_int64_t_s_s(l_60, 7))
        {
            int32_t l_878 = 0xFC2DEAD7L;
            int32_t l_897 = 0xF61E11E5L;
            l_691.f2 = ((g_199.f0 == ((((l_885 = (((((g_873++) <= (l_672 = (((0x792DL || (safe_rshift_func_uint16_t_u_s(l_878, 13))) || (((p_58.f0--) != (l_691.f5 ^= (0x70BD7A420812CA0FLL > (safe_rshift_func_int16_t_s_u((((p_57 = p_57) , l_691.f0) , (safe_rshift_func_uint8_t_u_s(p_57.f5, (0xF1AA9032L >= p_57.f6)))), 1))))) , 0xE25AB159L)) < g_191))) != 255UL) != g_377) ^ (-1L))) <= l_820) , 0x7AF6L) >= 1UL)) >= g_69);

g_33 ^= (((l_878 = (0xEB54L < l_691.f1)) <= l_691.f2) > g_586);


                    g_21 = (l_907 = (((((safe_add_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(((safe_div_func_uint8_t_u_u((l_691.f5 = (safe_unary_minus_func_uint8_t_u(0UL))), ((l_859 ^ ((safe_add_func_int32_t_s_s((safe_add_func_uint8_t_u_u((++g_322), (safe_sub_func_uint32_t_u_u(g_30, (safe_rshift_func_uint16_t_u_s(l_897, ((((-1L) || (-6L)) != ((~0x65L) < (((((p_57.f4 = (((safe_lshift_func_uint16_t_u_u(((l_878 >= l_897) | l_878), g_184)) >= 0xA9570CA5L) & p_57.f5)) , p_57.f6) > g_67) & p_57.f2) ^ 0x1299A5A1L))) | 0xB6L))))))), 2UL)) , g_33)) && (-1L)))) == 0xD6L), l_691.f6)), g_586)) >= p_57.f5) <= 0xFEBE5530D01B6D3DLL) > l_691.f4) , p_58));

if (g_38)
                    goto lbl_464;

                    l_373 = l_878;
        }

l_919 |= ((safe_div_func_uint8_t_u_u(((safe_div_func_uint8_t_u_u((safe_div_func_uint16_t_u_u((--g_1285), p_57.f0)), (0x5A0BAD988B54577ELL || (l_919 != (g_21 , (safe_lshift_func_int16_t_s_u((-3L), (p_57.f1 | (safe_add_func_int8_t_s_s(p_57.f3, (safe_sub_func_int32_t_s_s((safe_div_func_int8_t_s_s(((l_579 = ((((safe_div_func_int16_t_s_s((0x7BF8L > ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((l_673 = (g_21 , g_792)), 14)), 6)) >= g_184)), g_38)) && 0xD5682F7CL) <= g_528) == g_1276)) >= 65527UL), 251UL)), 0xFC6382EAL)))))))))))) > g_184), g_38)) < 1L);


l_691.f1 |= ((((safe_sub_func_uint16_t_u_u(g_524, (safe_lshift_func_uint16_t_u_u(1UL, g_928)))) , 0x08EAL) > 0x7146L) == 0x51A9FA1A770123F4LL);


                    g_30 |= (((safe_add_func_int8_t_s_s((((((l_373 ^= ((l_673 = l_672) , l_910)) >= (p_57.f4 = ((safe_add_func_uint8_t_u_u((((safe_div_func_uint64_t_u_u((safe_mod_func_uint64_t_u_u(0x5357627B9C38BE8CLL, (safe_rshift_func_int8_t_s_u((((p_57.f2 < (l_919 = l_691.f4)) ^ (g_315 & (l_920 <= (g_184 = g_67)))) < (l_859 = ((((l_691.f5 = (safe_mod_func_int8_t_s_s((safe_div_func_int32_t_s_s(((l_691.f2 ^= (-8L)) || 0xF7D7L), l_677)), 0x7AL))) ^ l_400) < l_707) <= g_756))), 6)))), g_80)) | g_238.f3) , 0x4DL), l_920)) && 4294967292UL))) != 4294967293UL) || 0x61L) == 1UL), 0x74L)) , (-5L)) , l_610);
    }
    else
    {
        int64_t l_925 = 0xA73062E26A32E214LL;
        int32_t l_926 = 0x25CEF752L;
        int32_t l_927 = 0xAB24C309L;
        struct S1 l_947 = {21304,6517,-24,3525,164,0,2283};

p_57.f5 &= l_910;


                    g_928++;

g_793 |= (((g_800 = l_942) | ((g_238.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((l_400 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((l_373 |= (((safe_add_func_uint64_t_u_u((g_527 < (g_800 = ((g_238.f4 = p_57.f2) < l_958))), 0xB4C6519C0C658331LL)) | p_57.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), g_38)) , g_315)) > p_57.f4) || p_57.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > p_57.f1)) && p_58.f0) && g_240) & l_859)) ^ g_315) & g_620)) >= 0UL) , g_38)) != g_801)) || 0x2FL);



{
    struct S1 l_2 = {5257,2494,15,7269,192,0,6867};
    struct S1 l_20 = {8399,1580,12,4707,209,0,910};
    struct S1 l_1295 = {8978,2774,11,1659,145,0,2412};
    l_2.f2 = ((l_2 , (((((((-8L) && (safe_rshift_func_uint8_t_u_u(func_5(((l_1295 = (l_20 = ((safe_div_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(((!(g_586 || (l_2.f4 = (-1L)))) ^ g_586), 10)) <= (g_183 = g_586)), func_14(g_586, l_20, g_199, g_199, g_199.f0))) , g_238))) , g_967)), g_13))) != g_586) , 0UL) > l_2.f6) | 0xC987502CL) && g_80)) != g_12);
    return l_20.f1;
}

                    for (g_37 = (-27); (g_37 < 10); ++g_37)
        {
            int8_t l_937 = 5L;

g_967 |= ((safe_div_func_uint8_t_u_u(((safe_div_func_uint8_t_u_u((safe_div_func_uint16_t_u_u((--g_928), g_238.f0)), (0x5A0BAD988B54577ELL || (g_30 != (g_21 , (safe_lshift_func_int16_t_s_u((-3L), (g_238.f1 | (safe_add_func_int8_t_s_s(g_238.f3, (safe_sub_func_int32_t_s_s((safe_div_func_int8_t_s_s(((l_579 = ((((safe_div_func_int16_t_s_s((0x7BF8L > ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((g_967 = (p_58 , g_183)), 14)), 6)) >= g_184)), g_37)) && 0xD5682F7CL) <= l_942) == g_188)) >= 65527UL), 251UL)), 0xFC6382EAL)))))))))))) > g_184), l_958)) < 1L);


if (((safe_mod_func_int32_t_s_s((l_68 , (((safe_lshift_func_int8_t_s_s((safe_div_func_int64_t_s_s((safe_mod_func_int64_t_s_s(((g_38 , (((g_238.f5 < ((safe_sub_func_int32_t_s_s((l_757 <= ((safe_div_func_int64_t_s_s(((l_926 = ((safe_lshift_func_uint16_t_u_u(p_57.f1, 9)) <= ((((g_238.f1 ^ (l_942 = ((((!(((+(-5L)) >= 0x2077L) | (((safe_lshift_func_uint16_t_u_s((safe_unary_minus_func_int32_t_s((safe_lshift_func_uint16_t_u_u(0x3FE3L, 15)))), 9)) < 0x3ED2BC827CFBFAACLL) == 0UL))) <= 0xEE3FL) && 0xCB01CDCFF5673DEALL) , l_994))) | 0x05B4L) , l_950.f0) > 0xF83382B7L))) == 1UL), g_12)) <= 0xF8L)), g_993)) , g_873)) , l_920) >= l_373)) , 0x1B3F29B522290BD6LL), p_57.f3)), p_57.f5)), l_859)) == g_183) <= 0x80L)), g_993)) == l_68))
                {
                    uint16_t l_451 = 0x721EL;
                    int32_t l_453 = (-1L);
                    p_57.f2 = ((l_926 |= (((g_38 ^ (safe_rshift_func_int16_t_s_s(0x7DA3L, 14))) , (safe_lshift_func_int8_t_s_u(l_451, 1))) != (safe_unary_minus_func_int16_t_s((l_453 = 0xBB70L))))) & ((safe_mod_func_uint8_t_u_u((safe_div_func_uint32_t_u_u((!((((p_57.f4 , l_920) < p_57.f0) , (safe_div_func_int64_t_s_s((l_925 = ((safe_add_func_uint64_t_u_u(p_57.f6, (l_493 = 0L))) >= (-1L))), l_373))) , 0x779BL)), l_920)), p_57.f6)) > p_57.f3));
                }
                else
                {

l_926 |= ((p_57.f5 | (l_596 = (g_37 < ((0x237022BDB339B958LL | ((~((g_36 = g_199.f0) <= g_756)) >= (g_13 >= l_947.f0))) ^ ((safe_rshift_func_int8_t_s_u((safe_add_func_int64_t_s_s(g_199.f0, (safe_sub_func_int32_t_s_s((-1L), p_57.f6)))), 1)) ^ 0x09L))))) || g_13);

                    g_199 = l_950;

g_238.f5 ^= (safe_mod_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(0xAEL, (0x4461L | (l_68 != (l_859 = (__undefined == (g_238.f0 = g_524))))))), l_373));


for (g_38 = (-19); (g_38 > 10); g_38 = safe_add_func_uint16_t_u_u(g_38, 6))
            {
                g_238 = l_947;
            };


                    g_238 = p_57;
                }
g_315 |= ((safe_sub_func_uint64_t_u_u(0x6750A3B4BAC7944CLL, g_377)) > (func_85((g_791 &= (safe_lshift_func_uint16_t_u_s((g_66 >= g_967), ((safe_div_func_uint8_t_u_u(func_94((safe_div_func_uint16_t_u_u(l_925, 1L)), p_58, g_199.f0), 0xCDL)) | g_199.f0)))), l_925, g_993) < g_571));


                    ;



if (((safe_sub_func_int32_t_s_s((~g_191), ((((+g_800) || (1L && (safe_div_func_uint8_t_u_u(((g_238.f1 == ((safe_add_func_int32_t_s_s(0L, ((((((!(safe_add_func_int8_t_s_s(g_12, 0xF5L))) , (safe_unary_minus_func_int16_t_s(3L))) > g_238.f0) > g_800) ^ 0x6B9E5876L) || 1UL))) < g_30)) & 1L), g_378)))) && 65535UL) == 0UL))) & 7UL))
            {
                if ((g_238.f5 = (0xCDL ^ g_238.f1)))
                {
                    return g_800;
                }
                else
                {
                    return g_184;
                }
            }
            else
            {
                uint8_t l_348 = 255UL;
                struct S0 l_369 = {65529UL};
                if (l_348)
                {
                    g_238.f2 ^= g_191;


if (g_967)
                            continue;

                    for (g_182 = 0; (g_182 == 39); g_182 = safe_add_func_uint16_t_u_u(g_182, 1))
                    {
                        uint64_t l_657 = 1UL;
                        l_947.f5 = 0xC207066FL;
                        g_756 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (l_373 = ((((safe_div_func_uint8_t_u_u(g_528, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(l_859 = (safe_mod_func_uint64_t_u_u(l_579, (l_493 &= ((safe_add_func_int8_t_s_s((g_928 = g_240), (safe_mod_func_int8_t_s_s(p_57.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((p_57.f5 &= g_191), (safe_mod_func_uint8_t_u_u(((~g_184) , p_57.f1), 255UL)))) , l_373) & p_57.f2))))))) != 0xA14CL)))))) <= g_993), l_657))))) && 6UL))) == g_571) <= l_369.f0) <= 1L))) , g_1285), l_369.f0)) == l_947.f4) || p_57.f0) | g_524), g_1285)) , 0x672551F9L) , 0xA150D49BL);
                    };


                    if (g_238.f1)
                        break;
                    if (g_238.f2)
                        continue;
                }
                else
                {
                    if ((safe_lshift_func_int8_t_s_s(((4294967295UL ^ ((((safe_sub_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u((safe_div_func_int32_t_s_s(0x8676E750L, (((safe_rshift_func_uint8_t_u_s((safe_div_func_int64_t_s_s((((g_30 = 1L) >= g_928) < (g_238.f4 , (g_184 != 1UL))), (safe_sub_func_uint8_t_u_u((safe_add_func_int8_t_s_s((g_240 ^= ((g_238.f0 || 255UL) < 0xD6E0L)), 6L)), g_238.f2)))), 1)) , 4294967295UL) , g_30))), g_800)) == l_947.f4) || g_800), 65533UL)) || 0x93L), l_68)) || g_586) >= g_800) , l_910)) == g_65), 3)))
                    {
                        if (l_925)
                            break;
                    }
                    else
                    {
                        l_369 = g_21;
                    }
                    return g_800;
                }
            };


                    l_947 = (g_238 = ((l_68 = ((((p_57.f0 > (safe_lshift_func_int8_t_s_u((safe_div_func_uint8_t_u_u((g_793 != (l_927 , ((l_937 = 0xDABBL) || (safe_add_func_int64_t_s_s((safe_mod_func_int8_t_s_s(l_942, 1UL)), (safe_rshift_func_uint16_t_u_s((l_920 < (safe_add_func_int8_t_s_s((l_937 >= p_57.f6), l_942))), 7))))))), 1UL)), 0))) && 4294967295UL) > p_57.f5) , g_199.f0)) , p_57));
        }
        l_947.f2 = 0L;
        for (g_378 = 0; (g_378 >= 10); ++g_378)
        {
            l_950 = (l_859 , l_950);
        }
    }
    for (p_58.f0 = 0; (p_58.f0 == 17); ++p_58.f0)
    {
        int64_t l_953 = 0x86445DF67443E0CELL;
        struct S0 l_954 = {0xD225L};
        int32_t l_955 = (-1L);
        int32_t l_956 = 6L;
        int32_t l_957 = 1L;
        int32_t l_959 = (-5L);
        int32_t l_960 = 0xFA289949L;
        int32_t l_961 = 0x9CE9722AL;
        int32_t l_962 = 0x4270AC42L;
        int32_t l_963 = 0xE0FAB585L;
        int32_t l_964 = (-1L);
        int32_t l_965 = 9L;
        int32_t l_966 = (-1L);
        l_954 = (((l_375 = (g_377 = l_953)) | (g_37 &= (g_241 | p_57.f0))) , l_950);

l_910 |= p_57.f1;


                    l_954 = p_58;

{
    return g_524;
}

                    --g_968;

g_13 ^= g_184;


                    g_30 |= ((safe_div_func_uint8_t_u_u(((safe_div_func_uint8_t_u_u((safe_div_func_uint16_t_u_u((--g_315), p_57.f0)), (0x5A0BAD988B54577ELL || (l_962 != (g_21 , (safe_lshift_func_int16_t_s_u((-3L), (p_57.f1 | (safe_add_func_int8_t_s_s(p_57.f3, (safe_sub_func_int32_t_s_s((safe_div_func_int8_t_s_s(((l_994 = ((((safe_div_func_int16_t_s_s((0x7BF8L > ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((l_955 = (l_950 , l_958)), 14)), 6)) >= g_993)), g_65)) && 0xD5682F7CL) <= g_873) == g_801)) >= 65527UL), 251UL)), 0xFC6382EAL)))))))))))) > g_993), l_963)) < 1L);
    }
    return l_910;
}







static uint8_t func_61(uint8_t p_62, uint32_t p_63, int64_t p_64)
{
    uint8_t l_323 = 255UL;
    uint8_t l_328 = 0UL;
    struct S1 l_329 = {20957,5903,30,8718,270,-0,5165};
    l_329 = ((((safe_sub_func_uint32_t_u_u(((g_322 ^= (g_184 = 0xCEC1L)) , (l_323 = 1UL)), ((safe_div_func_int32_t_s_s(p_62, g_238.f1)) == (safe_rshift_func_uint8_t_u_u(((7L <= (((l_328 , (((l_328 < (l_328 == (p_62 > g_182))) , l_328) && l_328)) , 0x4EC86742A66AFE18LL) , g_65)) != p_64), p_63))))) >= (-1L)) >= 1UL) , l_329);

g_13 |= ((safe_div_func_uint8_t_u_u(((safe_div_func_uint8_t_u_u((safe_div_func_uint16_t_u_u((--g_793), g_238.f0)), (0x5A0BAD988B54577ELL || (g_800 != (g_21 , (safe_lshift_func_int16_t_s_u((-3L), (g_238.f1 | (safe_add_func_int8_t_s_s(g_238.f3, (safe_sub_func_int32_t_s_s((safe_div_func_int8_t_s_s(((g_39 = ((((safe_div_func_int16_t_s_s((0x7BF8L > ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((g_65 = (g_199 , g_571)), 14)), 6)) >= g_184)), g_756)) && 0xD5682F7CL) <= g_873) == g_1276)) >= 65527UL), 251UL)), 0xFC6382EAL)))))))))))) > g_184), g_571)) < 1L);

                    l_329 = g_238;

g_800 &= (g_586 != ((((g_993 = ((g_377 & ((~((((g_199 , (g_240 ^ g_238.f3)) > g_240) != 0x2A7A2EF32379F2B3LL) != g_13)) && g_586)) && g_586)) >= 0L) , 0x1AL) | 0x83L));


                    return p_64;
}







static int8_t func_74(struct S0 p_75)
{
    int32_t l_81 = 6L;
    int8_t l_82 = 0x18L;
    int32_t l_91 = (-5L);
    struct S0 l_100 = {0x200CL};
    int32_t l_268 = 0x62F120E7L;
    int64_t l_269 = 0x10A1EBC7C7492526LL;
    int32_t l_316 = (-6L);
    uint32_t l_317 = 18446744073709551615UL;

g_183 &= (((g_586 != 0x8446L) , l_100) , (((g_39 ^ l_100.f0) , ((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u((safe_add_func_int64_t_s_s(((1UL & (safe_rshift_func_int8_t_s_u((safe_add_func_int64_t_s_s((g_1249 <= (g_238 , (safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(((((safe_mod_func_uint16_t_u_u(g_238.f3, g_188)) || g_238.f6) ^ g_39) , g_38), 8)) | g_238.f3), 5L)))), g_65)), g_238.f4))) | g_30), 0xCBB7D04007C17F65LL)), g_65)), g_238.f5)) > (-1L))) >= g_21.f0));



{
        int64_t l_925 = 0xA73062E26A32E214LL;
        int32_t l_926 = 0x25CEF752L;
        int32_t l_927 = 0xAB24C309L;
        struct S1 l_947 = {21304,6517,-24,3525,164,0,2283};
        g_1285++;
        for (l_91 = (-27); (l_91 < 10); ++l_91)
        {
            int8_t l_937 = 5L;
            l_947 = (g_238 = ((g_30 = ((((g_238.f0 > (safe_lshift_func_int8_t_s_u((safe_div_func_uint8_t_u_u((g_1285 != (l_927 , ((l_937 = 0xDABBL) || (safe_add_func_int64_t_s_s((safe_mod_func_int8_t_s_s(g_378, 1UL)), (safe_rshift_func_uint16_t_u_s((g_182 < (safe_add_func_int8_t_s_s((l_937 >= g_238.f6), g_378))), 7))))))), 1UL)), 0))) && 4294967295UL) > g_238.f5) , l_100.f0)) , g_238));
        }
        l_947.f2 = 0L;
        for (g_378 = 0; (g_378 >= 10); ++g_378)
        {
            g_21 = (g_377 , g_21);
        }
    }

                    g_756 |= (((g_756 ^ (safe_rshift_func_int16_t_s_s(0x7DA3L, 14))) , (safe_lshift_func_int8_t_s_u(g_315, 1))) != (safe_unary_minus_func_int16_t_s((g_967 = 0xBB70L))));


                    l_317 = (((l_316 &= (safe_div_func_uint8_t_u_u(((g_80 ^= g_30) & (((l_82 = (l_81 = (0xDA1D0942DF00AC9ELL >= 0x9644A59A1FF38044LL))) ^ 0xCA3631A0D171E9D6LL) <= (g_315 |= ((safe_sub_func_uint64_t_u_u(0x6750A3B4BAC7944CLL, g_37)) > (func_85((l_268 &= (safe_lshift_func_uint16_t_u_s((g_12 >= l_91), ((safe_div_func_uint8_t_u_u(func_94((safe_div_func_uint16_t_u_u(g_36, 1L)), l_100, p_75.f0), 0xCDL)) | p_75.f0)))), l_269, g_184) < g_38))))), (-4L)))) , p_75.f0) | 0xEDL);
    return g_238.f5;
}







static uint8_t func_85(int16_t p_86, int8_t p_87, uint8_t p_88)
{
    int8_t l_276 = 0xBFL;
    int32_t l_289 = 6L;
    int32_t l_291 = (-1L);
    int32_t l_292 = 1L;
    int32_t l_293 = 0x81DF53A7L;
    int32_t l_294 = 0L;
    int32_t l_298 = 0x4EC99466L;

g_967 &= g_586;


                    for (g_191 = (-27); (g_191 < 39); g_191 = safe_add_func_uint8_t_u_u(g_191, 8))
    {
        int32_t l_284 = 0xEE263D41L;
        uint64_t l_288 = 18446744073709551615UL;
        int32_t l_290 = 9L;
        int32_t l_296 = 0xC6978A9AL;
        int32_t l_297 = 0x9ADCCFBDL;
        int32_t l_299 = 8L;
        int32_t l_300 = 0x80C45391L;
        struct S0 l_311 = {1UL};
        struct S1 l_314 = {15034,7901,-16,6783,-510,-0,5803};
        if ((((safe_lshift_func_uint8_t_u_s((p_88 = (safe_rshift_func_uint8_t_u_s(g_241, 2))), l_276)) && (((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_int8_t_s_s(((((g_238 = g_238) , ((l_289 = (safe_add_func_int64_t_s_s(((((g_32 != p_86) == (((safe_rshift_func_int16_t_s_u((3UL == (((l_284 <= 0xB1A0L) != (((((safe_rshift_func_uint8_t_u_u(((!p_86) , p_87), 5)) > l_288) & (-10L)) , 0xE1L) > g_182)) , g_191)), l_276)) & 5L) || 0xA2B9BF124FD362E7LL)) == l_276) , (-1L)), l_288))) && l_289)) & l_284) >= 0x62L), l_288)) , l_276))) >= g_191) | 1L)) , p_86))
        {
            int8_t l_295 = (-5L);

{
        int64_t l_953 = 0x86445DF67443E0CELL;
        struct S0 l_954 = {0xD225L};
        int32_t l_955 = (-1L);
        int32_t l_956 = 6L;
        int32_t l_957 = 1L;
        int32_t l_959 = (-5L);
        int32_t l_960 = 0xFA289949L;
        int32_t l_961 = 0x9CE9722AL;
        int32_t l_962 = 0x4270AC42L;
        int32_t l_963 = 0xE0FAB585L;
        int32_t l_964 = (-1L);
        int32_t l_965 = 9L;
        int32_t l_966 = (-1L);
        l_954 = (((g_13 = (l_296 = l_953)) | (l_300 &= (g_378 | l_314.f0))) , l_311);
        l_954 = g_21;
        --g_378;
        l_291 |= ((safe_div_func_uint8_t_u_u(((safe_div_func_uint8_t_u_u((safe_div_func_uint16_t_u_u((--g_1285), l_314.f0)), (0x5A0BAD988B54577ELL || (l_962 != (g_199 , (safe_lshift_func_int16_t_s_u((-3L), (l_314.f1 | (safe_add_func_int8_t_s_s(l_314.f3, (safe_sub_func_int32_t_s_s((safe_div_func_int8_t_s_s(((g_39 = ((((safe_div_func_int16_t_s_s((0x7BF8L > ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((l_955 = (l_311 , g_967)), 14)), 6)) >= g_184)), l_300)) && 0xD5682F7CL) <= g_1249) == g_69)) >= 65527UL), 251UL)), 0xFC6382EAL)))))))))))) > g_184), l_963)) < 1L);
    }


if (g_238.f2)
                        continue;

                    --g_301;

l_291 |= ((safe_div_func_uint8_t_u_u(((safe_div_func_uint8_t_u_u((safe_div_func_uint16_t_u_u((--g_1285), l_314.f0)), (0x5A0BAD988B54577ELL || (g_37 != (l_311 , (safe_lshift_func_int16_t_s_u((-3L), (l_314.f1 | (safe_add_func_int8_t_s_s(l_314.f3, (safe_sub_func_int32_t_s_s((safe_div_func_int8_t_s_s(((l_288 = ((((safe_div_func_int16_t_s_s((0x7BF8L > ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((g_967 = (g_21 , l_292)), 14)), 6)) >= g_184)), g_30)) && 0xD5682F7CL) <= g_968) == g_322)) >= 65527UL), 251UL)), 0xFC6382EAL)))))))))))) > g_184), l_296)) < 1L);

                    g_238.f4 &= ((((l_291 &= 0x62L) <= ((l_298 = ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^ (l_293 = l_294)) & (safe_rshift_func_uint16_t_u_s(0x2310L, 10))) , ((g_30 ^ ((l_289 &= (l_295 != ((((g_184 = ((g_183 & ((~((((l_311 , (p_87 ^ g_238.f3)) > p_87) != 0x2A7A2EF32379F2B3LL) != l_284)) && l_295)) && l_295)) >= 0L) , 0x1AL) | 0x83L))) >= g_238.f2)) != p_87)) <= l_296) && (-1L)) || g_238.f1) , g_66)) | 1UL)) > 5L) ^ 0xDF8CL);
        }
        else
        {

g_33 |= g_238.f1;



l_314.f5 &= (!(g_38 = ((+(safe_mod_func_int32_t_s_s(l_314.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(l_314.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(l_314.f3, (((++g_199.f0) | (p_86 > ((g_191 , (g_377 ^= p_86)) , 0x3CC1CF37L))) != (g_378 == 249UL))))) , g_527), g_21.f0))))) ^ g_968)));

                    g_238.f2 = (-4L);
            for (l_300 = (-19); (l_300 > 10); l_300 = safe_add_func_uint16_t_u_u(l_300, 6))
            {
                g_238 = l_314;
            }
        }
    }
    return p_87;
}







static uint8_t func_94(int16_t p_95, struct S0 p_96, int16_t p_97)
{
    uint32_t l_120 = 0xA7EABDE2L;
    int32_t l_127 = 1L;
    uint64_t l_128 = 0x8893BA86ABA2F2E6LL;
    struct S1 l_139 = {7366,6762,-28,1126,-234,-0,4325};
    struct S0 l_159 = {65529UL};
    uint32_t l_203 = 0UL;
    if (g_33)
    {
        int8_t l_126 = 0x41L;
        struct S0 l_158 = {65535UL};
        int32_t l_162 = (-1L);
        int8_t l_181 = 0x56L;
        int32_t l_206 = 0x501F8A61L;
        int32_t l_207 = 1L;
        int32_t l_209 = 0L;
        int32_t l_210 = 0x9105A86EL;
        int32_t l_211 = 0L;
        uint16_t l_214 = 0xEB0AL;
        struct S1 l_266 = {8020,8046,-6,1087,99,-0,4038};
        g_65 = ((func_101(p_97, (((safe_lshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s(((((safe_add_func_int16_t_s_s(((9UL == 18446744073709551614UL) & (safe_lshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u((-1L), (65532UL != l_120))), 1))), l_120)) <= ((safe_div_func_int64_t_s_s(((safe_mod_func_uint64_t_u_u((((((!2L) & (--l_128)) > ((safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(((((safe_add_func_int32_t_s_s(l_120, 1UL)) | l_127) , 1L) || l_126), p_95)), p_96.f0)) >= p_96.f0)) >= p_96.f0) & g_33), g_37)) && g_67), 0xCC1C6A88B8388ADFLL)) >= l_120)) , g_67) < g_39), 13)), 3)) && l_126), 4)), g_32)), 6)) <= l_126) != 1UL)) >= g_66) <= g_30);
        l_127 = ((((l_139 , 0xCFL) <= (g_21.f0 == (0xFF4B716CAE9C981CLL < l_126))) <= (0x1CL < ((g_66 , l_126) , ((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(0xAF64L, g_21.f0)) != p_95), p_97)), 0x92ADL)) < p_97)))) | 0xFAL);
        for (g_21.f0 = 0; (g_21.f0 != 25); g_21.f0 = safe_add_func_int64_t_s_s(g_21.f0, 8))
        {
            uint32_t l_163 = 0UL;
            int32_t l_168 = 0x35FECE65L;
            int32_t l_185 = 1L;
            int32_t l_186 = 0xCCA4C161L;
            int32_t l_187 = 5L;
            g_182 ^= (g_12 == ((safe_mod_func_int16_t_s_s(((safe_div_func_uint64_t_u_u(((0x23B04249L >= (safe_mod_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s(((((l_159 = l_158) , l_159) , (safe_lshift_func_uint16_t_u_s((++l_163), (safe_mod_func_uint32_t_u_u(l_168, (safe_div_func_int32_t_s_s((g_66 > ((p_96.f0 |= (safe_sub_func_uint64_t_u_u((safe_add_func_int32_t_s_s((65530UL | (safe_div_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(0x88AFL, (safe_add_func_int16_t_s_s((((l_158 = g_21) , (-10L)) & 0xC4A096ABL), 0xBEFCL)))), g_39))), l_181)), g_65))) ^ 0x3F1CL)), 0xBE4CFF9CL))))))) < l_162), 7)) | l_139.f2) || g_69), p_97))) != 0x1A2308598B864A24LL), l_139.f5)) < 1L), 0x8ABAL)) < p_97));
            --g_188;

{
        int8_t l_126 = 0x41L;
        struct S0 l_158 = {65535UL};
        int32_t l_162 = (-1L);
        int8_t l_181 = 0x56L;
        int32_t l_206 = 0x501F8A61L;
        int32_t l_207 = 1L;
        int32_t l_209 = 0L;
        int32_t l_210 = 0x9105A86EL;
        int32_t l_211 = 0L;
        uint16_t l_214 = 0xEB0AL;
        struct S1 l_266 = {8020,8046,-6,1087,99,-0,4038};
        l_206 = ((func_101(g_184, (((safe_lshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s(((((safe_add_func_int16_t_s_s(((9UL == 18446744073709551614UL) & (safe_lshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u((-1L), (65532UL != g_182))), 1))), g_182)) <= ((safe_div_func_int64_t_s_s(((safe_mod_func_uint64_t_u_u((((((!2L) & (--l_128)) > ((safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(((((safe_add_func_int32_t_s_s(g_182, 1UL)) | g_30) , 1L) || l_126), g_184)), g_21.f0)) >= g_21.f0)) >= g_21.f0) & g_188), l_185)) && l_126), 0xCC1C6A88B8388ADFLL)) >= g_182)) , l_126) < g_39), 13)), 3)) && l_126), 4)), g_32)), 6)) <= l_126) != 1UL)) >= g_524) <= l_206);
        g_30 = ((((g_238 , 0xCFL) <= (g_21.f0 == (0xFF4B716CAE9C981CLL < l_126))) <= (0x1CL < ((g_524 , l_126) , ((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(0xAF64L, g_21.f0)) != g_184), g_184)), 0x92ADL)) < g_184)))) | 0xFAL);
        for (g_21.f0 = 0; (g_21.f0 != 25); g_21.f0 = safe_add_func_int64_t_s_s(g_21.f0, 8))
        {
            uint32_t l_163 = 0UL;
            int32_t l_168 = 0x35FECE65L;
            int32_t l_185 = 1L;
            int32_t l_186 = 0xCCA4C161L;
            int32_t l_187 = 5L;
            g_968 ^= (l_181 == ((safe_mod_func_int16_t_s_s(((safe_div_func_uint64_t_u_u(((0x23B04249L >= (safe_mod_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s(((((l_158 = l_158) , l_158) , (safe_lshift_func_uint16_t_u_s((++l_163), (safe_mod_func_uint32_t_u_u(l_168, (safe_div_func_int32_t_s_s((g_524 > ((g_21.f0 |= (safe_sub_func_uint64_t_u_u((safe_add_func_int32_t_s_s((65530UL | (safe_div_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(0x88AFL, (safe_add_func_int16_t_s_s((((l_158 = g_21) , (-10L)) & 0xC4A096ABL), 0xBEFCL)))), g_39))), l_181)), l_206))) ^ 0x3F1CL)), 0xBE4CFF9CL))))))) < l_162), 7)) | g_238.f2) || g_801), g_184))) != 0x1A2308598B864A24LL), g_238.f5)) < 1L), 0x8ABAL)) < g_184));
            --g_801;

g_240 |= ((safe_add_func_uint64_t_u_u(((g_1249 < ((safe_mod_func_uint64_t_u_u(l_266.f0, (((safe_sub_func_int8_t_s_s(((((g_993 = l_163) > (safe_unary_minus_func_uint64_t_u(0xD039656BC93DCDE7LL))) && ((0x1154443CL ^ ((safe_rshift_func_int16_t_s_s((+(safe_sub_func_int32_t_s_s(g_238.f0, 0xA33F1971L))), 6)) , 0xA1E7029EL)) ^ l_158.f0)) == 0L), 0UL)) || 0xA51DB1AF86CBBD6FLL) , l_126))) , g_199.f0)) == g_238.f0), (-10L))) , l_207);


                    g_188++;
        }

if (g_183)
                {
                    uint32_t l_1238 = 0xACAF4E8DL;
                    int32_t l_1240 = 0L;

{
                        int64_t l_706 = 0x06ACFC086CD2EA72LL;
                        g_238.f5 &= (!(g_756 = ((+(safe_mod_func_int32_t_s_s(g_238.f3, (safe_lshift_func_uint16_t_u_s((((safe_add_func_int32_t_s_s(g_238.f1, 0x9391FA2DL)) && (safe_lshift_func_int16_t_s_u(l_139.f3, (((++l_159.f0) | (g_184 > ((g_188 , (g_756 ^= g_184)) , 0x3CC1CF37L))) != (g_301 == 249UL))))) , l_706), l_159.f0))))) ^ l_203)));
                        l_139 = g_238;
                    }


l_127 ^= (safe_lshift_func_uint8_t_u_s((g_191 < (5UL | func_56(l_139, l_158))), 7));

                    g_756 = l_126;
                    g_199 = (g_238.f6 , g_199);
                    g_238.f4 &= g_301;
                    if (l_210)
                    {
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;
                        l_139.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, g_301)), (l_1239 = (l_1238 = g_377)))), (l_139.f6 , l_1240)));
                        l_203++;
                    }
                    else
                    {
                        l_1240 &= g_1249;
                    }
                }
                else
                {
                    uint64_t l_1260 = 0xF5DC1668590A4472LL;
                    int32_t l_1273 = (-1L);
                    int32_t l_1274 = 0xEA32A638L;
                    int32_t l_1275 = 0x813DFFBBL;
                    g_238.f5 = (safe_mod_func_uint8_t_u_u((1UL == (safe_sub_func_uint8_t_u_u(((g_524 && l_266.f4) > ((safe_div_func_uint64_t_u_u(g_69, g_69)) <= (((l_1260 , (safe_rshift_func_uint8_t_u_u(g_238.f4, 5))) != (--l_203)) && (((l_181 & (g_238.f2 = (g_791 ^= (safe_mod_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(0x17F9FA19L, g_32)), 1)) && g_238.f5), 0xD66C9ADCL))))) | l_158.f0) & p_97)))), l_266.f5))), g_524));
                    for (g_315 = 3; (g_315 != 32); g_315 = safe_add_func_uint32_t_u_u(g_315, 4))
                    {
                        ++g_188;
                        if (l_139.f1)
                            {

g_524 ^= ((l_266.f0 || 255UL) < 0xD6E0L);


                    for (p_96.f0 = 0; (p_96.f0 != 25); p_96.f0 = safe_add_func_int64_t_s_s(p_96.f0, 8))
        {
            uint32_t l_163 = 0UL;
            int32_t l_168 = 0x35FECE65L;
            int32_t l_185 = 1L;
            int32_t l_186 = 0xCCA4C161L;
            int32_t l_187 = 5L;
            g_968 ^= (g_12 == ((safe_mod_func_int16_t_s_s(((safe_div_func_uint64_t_u_u(((0x23B04249L >= (safe_mod_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s(((((p_96 = g_21) , p_96) , (safe_lshift_func_uint16_t_u_s((++l_163), (safe_mod_func_uint32_t_u_u(l_168, (safe_div_func_int32_t_s_s((g_67 > ((p_96.f0 |= (safe_sub_func_uint64_t_u_u((safe_add_func_int32_t_s_s((65530UL | (safe_div_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(0x88AFL, (safe_add_func_int16_t_s_s((((g_21 = p_96) , (-10L)) & 0xC4A096ABL), 0xBEFCL)))), l_128))), l_126)), l_1275))) ^ 0x3F1CL)), 0xBE4CFF9CL))))))) < g_791), 7)) | g_238.f2) || g_69), g_993))) != 0x1A2308598B864A24LL), g_238.f5)) < 1L), 0x8ABAL)) < g_993));
            --g_1276;
            g_191++;
        };


                    break;}
                        if (g_571)
                            {
g_238.f4 &= ((((l_207 &= 0x62L) <= ((g_183 = ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^ (l_168 = l_187)) & (safe_rshift_func_uint16_t_u_s(0x2310L, 10))) , ((l_207 ^ ((l_206 &= (l_181 != ((((g_993 = ((g_377 & ((~((((l_159 , (l_181 ^ g_238.f3)) > l_181) != 0x2A7A2EF32379F2B3LL) != g_756)) && l_181)) && l_181)) >= 0L) , 0x1AL) | 0x83L))) >= g_238.f2)) != l_181)) <= l_168) && (-1L)) || g_238.f1) , g_67)) | 1UL)) > 5L) ^ 0xDF8CL);

                    continue;}
                        g_238.f5 ^= (safe_mod_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(0xAEL, (0x4461L | (g_377 != (g_791 = (__undefined == (g_238.f0 = l_181))))))), l_1273));
                    }
                }
{
                    int8_t l_1100 = (-7L);
                    int32_t l_1104 = 0L;
                    int32_t l_1111 = 0x36BD596BL;
                    uint16_t l_1129 = 65535UL;
                    g_238.f2 ^= (((((g_1249 >= 0L) <= g_38) || ((safe_add_func_uint64_t_u_u((safe_div_func_int32_t_s_s((g_66 , ((((0L <= (0xAF2AFC70L || ((l_266.f1 |= ((((safe_sub_func_uint16_t_u_u(g_67, (safe_lshift_func_uint16_t_u_u(1UL, g_1285)))) , 0x08EAL) > 0x7146L) == 0x51A9FA1A770123F4LL)) && g_792))) != g_378) || l_162) >= g_238.f3)), 4294967295UL)), 0x8134BAAB9636E740LL)) | 0x429EL)) || g_378) && g_36);
                    for (g_36 = 16; (g_36 != 15); g_36 = safe_sub_func_int32_t_s_s(g_36, 1))
                    {
                        int32_t l_1099 = 0x29D6DC62L;
                        g_873 |= ((safe_add_func_uint16_t_u_u(((safe_div_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_s((g_1276 |= l_266.f1), 0)) <= g_184), (((safe_lshift_func_uint16_t_u_u((g_1285 |= (((l_162 = l_163) | ((l_266.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((g_184 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((l_185 |= (((safe_add_func_uint64_t_u_u((__undefined < (l_210 = ((l_266.f4 = g_238.f2) < g_37))), 0xB4C6519C0C658331LL)) | g_238.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), l_1099)) , g_1285)) > g_238.f4) || g_238.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > g_238.f1)) && p_96.f0) && l_1100) & g_37)) ^ g_1285) & l_214)) >= 0UL) , l_1099)) != g_1276)) || 0x2FL)), l_1100)) < g_238.f1) || 4294967294UL))) & p_96.f0), 65535UL)) >= g_238.f4);
                        if (g_238.f1)
                            continue;
                    }
                    l_266.f5 = (safe_add_func_int8_t_s_s(((0L > (((l_1104 |= 0x342AL) && (l_126 & (safe_div_func_uint8_t_u_u(0xA3L, (safe_rshift_func_uint16_t_u_u(0x820EL, 10)))))) , 1L)) , (safe_rshift_func_uint8_t_u_s((g_1276++), 5))), (safe_add_func_int8_t_s_s(((0x5EA5295EB42C2F9DLL && (safe_rshift_func_int16_t_s_u(((safe_div_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((l_210 &= l_1100), ((((safe_add_func_uint16_t_u_u((p_96.f0 = ((g_1276 < l_185) <= 0x6B6EL)), l_1129)) , g_873) , g_238) , 0xCCL))), g_37)), g_67)), g_1276)) && g_238.f2), g_238.f5))) || g_1276), g_39))));
                    g_238 = (l_266 = l_266);
                }

                    ;


                    if (g_184)
        {
            struct S0 l_200 = {0x8CAFL};
            int32_t l_205 = (-1L);
            int32_t l_208 = 0x15D7F043L;
            uint16_t l_215 = 0xEBE3L;
            struct S1 l_237 = {4888,4404,-28,3688,-181,0,4061};
            int32_t l_239 = 0x45497A7BL;

l_237.f0 &= (safe_mod_func_int64_t_s_s((((((8UL && ((safe_mod_func_uint32_t_u_u((((safe_rshift_func_int8_t_s_u((safe_div_func_int32_t_s_s((l_266.f1 | l_139.f6), l_237.f2)), 7)) <= g_80) | l_266.f3), 0xF4092F41L)) || l_158.f0)) ^ __undefined) < l_237.f1) , l_266.f6) , g_80), l_266.f6));


                    for (l_128 = 14; (l_128 == 54); l_128++)
            {
                uint16_t l_196 = 1UL;

l_208 &= (g_524 != ((((p_97 = ((g_183 & ((~((((p_96 , (g_240 ^ l_266.f3)) > g_240) != 0x2A7A2EF32379F2B3LL) != g_13)) && g_524)) && g_524)) >= 0L) , 0x1AL) | 0x83L));


                    l_196--;
                l_200 = l_158;
            }
            g_30 = (((safe_sub_func_uint8_t_u_u(g_873, (l_126 , g_21.f0))) < ((l_215 = (g_238.f4 &= (+((((-1L) & ((0xAFL < (((g_801 == ((((g_238.f2 = (l_205 = (g_21 , 8L))) <= ((((((g_39++) ^ g_184) >= l_200.f0) , g_21) , g_21.f0) ^ (-7L))) > g_184) ^ g_184)) , 18446744073709551613UL) > l_185)) ^ l_200.f0)) && l_214) != 0x8890B9DDL)))) <= l_158.f0)) , g_238.f1);


{
                        g_791 &= l_163;
                    }

                    g_238.f5 ^= (0x70BD7A420812CA0FLL > (safe_rshift_func_int16_t_s_u((((l_266 = l_266) , g_238.f0) , (safe_rshift_func_uint8_t_u_s(l_266.f5, (0xF1AA9032L >= l_266.f6)))), 1)));


                    g_238 = ((((((safe_mod_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s(((g_188 = (safe_lshift_func_int16_t_s_s((((((((safe_sub_func_int32_t_s_s(((((((safe_rshift_func_int16_t_s_s((+(g_184 && (g_524 = (-1L)))), (g_184 = l_206))) && (((safe_mod_func_uint16_t_u_u(l_215, (safe_lshift_func_uint8_t_u_s(((g_21.f0 , 1L) , (0x34L != (safe_lshift_func_int8_t_s_s((safe_mod_func_uint64_t_u_u((g_184 >= (safe_add_func_uint64_t_u_u((g_32 == 4294967290UL), g_184))), g_21.f0)), g_238.f5)))), 5)))) | l_205) & 0x8900E08CL)) || g_39) || g_184) <= 0x3DL) < l_126), l_126)) | 0xBFBDL) < l_158.f0) > l_210) != g_21.f0) | g_21.f0) <= 0xDC97BAAAL), 4))) || l_185), l_126)) | g_188) == l_211), l_185)) ^ l_215) ^ g_184) || 1L) , g_873) , l_237);
            g_873++;
        }
        else
        {
            uint32_t l_265 = 0x211A307CL;
            g_238.f2 |= ((safe_lshift_func_uint8_t_u_s(255UL, (safe_rshift_func_uint8_t_u_s(g_39, 2)))) & (safe_sub_func_int16_t_s_s(g_238.f2, 1L)));
            l_206 &= (g_21 , g_238.f0);

l_139.f5 ^= (0x70BD7A420812CA0FLL > (safe_rshift_func_int16_t_s_u((((l_139 = l_139) , l_139.f0) , (safe_rshift_func_uint8_t_u_s(l_139.f5, (0xF1AA9032L >= l_139.f6)))), 1)));



l_210 &= ((0L < (((((safe_add_func_int64_t_s_s(((safe_lshift_func_int16_t_s_s(((-10L) | g_377), ((safe_sub_func_int16_t_s_s((l_127 = (((l_127 |= ((safe_sub_func_int32_t_s_s(((safe_sub_func_int16_t_s_s(g_238.f2, (g_32 = (safe_sub_func_uint8_t_u_u(g_620, (((g_238 , g_238.f1) , l_266) , (safe_add_func_uint8_t_u_u((safe_sub_func_uint64_t_u_u(((((g_873++) && (g_873 != 0xAEL)) ^ 0x9714L) <= 0xD7EAL), 0x1FBFD773E599F898LL)), g_69)))))))) < g_238.f5), g_184)) < g_620)) && 0x22L) ^ l_128)), g_184)) != g_238.f5))) , g_12), g_528)) != g_378) > g_1276) || l_211) <= g_21.f0)) || g_238.f2);

                    l_207 ^= (g_238.f5 = (g_238.f2 = (safe_div_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(l_158.f0, (((0x5DL > l_206) != (safe_unary_minus_func_int16_t_s(1L))) == ((((((g_873 > (safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_u(0xCBFBL, 6)) < (safe_add_func_uint32_t_u_u((((safe_sub_func_uint64_t_u_u(((((g_21 = g_21) , 0xA2463E9B3E846025LL) , (safe_div_func_int32_t_s_s(l_185, 0x810FC398L))) | l_265), g_184)) ^ l_265) || l_181), g_21.f0))), g_801))) ^ l_265) >= l_265) , l_266) , 249UL) , g_184)))) >= 5L) >= 255UL) , g_238.f6), g_184))));
        }
    }

                    g_191++;
        }
        if (p_95)
        {
            struct S0 l_200 = {0x8CAFL};
            int32_t l_205 = (-1L);
            int32_t l_208 = 0x15D7F043L;
            uint16_t l_215 = 0xEBE3L;
            struct S1 l_237 = {4888,4404,-28,3688,-181,0,4061};
            int32_t l_239 = 0x45497A7BL;

{
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;

for (g_182 = 0; (g_182 >= 10); ++g_182)
        {
            g_199 = (l_239 , g_199);
        };


                    g_238.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, g_968)), (l_1239 = (g_873 = g_13)))), (g_238.f6 , l_206)));

{
                uint32_t l_559 = 4294967295UL;
                int32_t l_560 = 9L;
                l_211 = ((18446744073709551615UL && (((safe_unary_minus_func_int64_t_s((safe_add_func_uint16_t_u_u((l_159.f0 == (safe_div_func_int8_t_s_s((safe_mod_func_int64_t_s_s((+((((l_237.f0 || (((g_238.f5 , ((safe_mod_func_int8_t_s_s((((((safe_sub_func_int64_t_s_s(0xF9CED6740F5759D8LL, g_69)) | 0x5CB0L) && (-1L)) < ((g_528 = (safe_mod_func_uint16_t_u_u((+((safe_div_func_int32_t_s_s(((l_559 = (safe_sub_func_uint64_t_u_u(((safe_mod_func_int64_t_s_s(((l_237 , g_378) >= 0x34E3L), 0x02128AB49729E21BLL)) && l_1245), (-1L)))) != l_237.f1), (-5L))) > l_237.f1)), l_159.f0))) <= 4L)) | 0xB4A67218FBF74A89LL), l_560)) , l_208)) != 0xF6L) || g_184)) >= g_524) ^ 0x08A696AFL) > l_126)), 1UL)), 0x24L))), p_95)))) & l_207) > l_211)) & l_159.f0);
            }

                    g_80++;
                    }

                    for (l_128 = 14; (l_128 == 54); l_128++)
            {
                uint16_t l_196 = 1UL;

{
                        int32_t l_1239 = 0xB567C114L;
                        int32_t l_1242 = (-1L);
                        int32_t l_1243 = (-8L);
                        int32_t l_1245 = 0L;
                        int32_t l_1248 = 0xE075FBDDL;
                        l_266.f2 = (safe_div_func_int32_t_s_s((safe_div_func_int64_t_s_s((safe_lshift_func_int8_t_s_s(1L, g_80)), (l_1239 = (g_241 = g_791)))), (l_266.f6 , l_208)));

g_13 |= g_238.f3;


                    g_1249++;
                    }



{
            int8_t l_937 = 5L;
            l_139 = (l_266 = ((g_571 = ((((g_238.f0 > (safe_lshift_func_int8_t_s_u((safe_div_func_uint8_t_u_u((g_315 != (g_756 , ((l_937 = 0xDABBL) || (safe_add_func_int64_t_s_s((safe_mod_func_int8_t_s_s(g_241, 1UL)), (safe_rshift_func_uint16_t_u_s((g_528 < (safe_add_func_int8_t_s_s((l_937 >= g_238.f6), g_241))), 7))))))), 1UL)), 0))) && 4294967295UL) > g_238.f5) , l_200.f0)) , g_238));
        }

                    g_12 |= ((safe_add_func_uint64_t_u_u(((g_528 < ((safe_mod_func_uint64_t_u_u(l_237.f0, (((safe_sub_func_int8_t_s_s(((((p_97 = g_378) > (safe_unary_minus_func_uint64_t_u(0xD039656BC93DCDE7LL))) && ((0x1154443CL ^ ((safe_rshift_func_int16_t_s_s((+(safe_sub_func_int32_t_s_s(g_238.f0, 0xA33F1971L))), 6)) , 0xA1E7029EL)) ^ g_199.f0)) == 0L), 0UL)) || 0xA51DB1AF86CBBD6FLL) , g_524))) , g_199.f0)) == g_238.f0), (-10L))) , l_127);


                    l_196--;
                l_200 = g_199;
            }
            l_127 = (((safe_sub_func_uint8_t_u_u(l_203, (g_67 , p_96.f0))) < ((l_215 = (l_139.f4 &= (+((((-1L) & ((0xAFL < (((g_188 == ((((l_139.f2 = (l_205 = (p_96 , 8L))) <= ((((((g_39++) ^ p_95) >= l_200.f0) , g_21) , g_21.f0) ^ (-7L))) > p_97) ^ p_95)) , 18446744073709551613UL) > g_37)) ^ l_200.f0)) && l_214) != 0x8890B9DDL)))) <= l_158.f0)) , l_139.f1);
            g_238 = ((((((safe_mod_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s(((g_191 = (safe_lshift_func_int16_t_s_s((((((((safe_sub_func_int32_t_s_s(((((((safe_rshift_func_int16_t_s_s((+(p_95 && (g_66 = (-1L)))), (p_97 = g_65))) && (((safe_mod_func_uint16_t_u_u(l_215, (safe_lshift_func_uint8_t_u_s(((p_96.f0 , 1L) , (0x34L != (safe_lshift_func_int8_t_s_s((safe_mod_func_uint64_t_u_u((p_95 >= (safe_add_func_uint64_t_u_u((g_32 == 4294967290UL), p_95))), p_96.f0)), l_139.f5)))), 5)))) | l_205) & 0x8900E08CL)) || g_39) || p_95) <= 0x3DL) < g_67), g_67)) | 0xBFBDL) < g_199.f0) > l_210) != p_96.f0) | g_21.f0) <= 0xDC97BAAAL), 4))) || g_37), g_67)) | g_33) == l_211), g_183)) ^ l_215) ^ p_95) || 1L) , l_203) , l_237);

for (g_39 = 14; (g_39 == 54); g_39++)
            {
                uint16_t l_196 = 1UL;
                l_196--;
                l_159 = g_21;
            };


                    g_241++;
        }
        else
        {
            uint32_t l_265 = 0x211A307CL;
            g_238.f2 |= ((safe_lshift_func_uint8_t_u_s(255UL, (safe_rshift_func_uint8_t_u_s(g_39, 2)))) & (safe_sub_func_int16_t_s_s(l_139.f2, 1L)));

{
    uint32_t l_120 = 0xA7EABDE2L;
    int32_t l_127 = 1L;
    uint64_t l_128 = 0x8893BA86ABA2F2E6LL;
    struct S1 l_139 = {7366,6762,-28,1126,-234,-0,4325};
    struct S0 l_159 = {65529UL};
    uint32_t l_203 = 0UL;

l_158.f0 |= (safe_sub_func_uint64_t_u_u((safe_add_func_int32_t_s_s((65530UL | (safe_div_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(0x88AFL, (safe_add_func_int16_t_s_s((((l_158 = l_158) , (-10L)) & 0xC4A096ABL), 0xBEFCL)))), g_39))), l_181)), g_791));



l_214 |= ((safe_sub_func_uint64_t_u_u(0x6750A3B4BAC7944CLL, l_209)) > (func_85((g_377 &= (safe_lshift_func_uint16_t_u_s((g_66 >= g_377), ((safe_div_func_uint8_t_u_u(func_94((safe_div_func_uint16_t_u_u(__undefined, 1L)), g_21, g_21.f0), 0xCDL)) | g_21.f0)))), __undefined, g_993) < l_162));


                    if (g_1276)
    {
        int8_t l_126 = 0x41L;
        struct S0 l_158 = {65535UL};
        int32_t l_162 = (-1L);
        int8_t l_181 = 0x56L;
        int32_t l_206 = 0x501F8A61L;
        int32_t l_207 = 1L;
        int32_t l_209 = 0L;
        int32_t l_210 = 0x9105A86EL;
        int32_t l_211 = 0L;
        uint16_t l_214 = 0xEB0AL;
        struct S1 l_266 = {8020,8046,-6,1087,99,-0,4038};
        l_207 = ((func_101(p_95, (((safe_lshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s(((((safe_add_func_int16_t_s_s(((9UL == 18446744073709551614UL) & (safe_lshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u((-1L), (65532UL != l_120))), 1))), l_120)) <= ((safe_div_func_int64_t_s_s(((safe_mod_func_uint64_t_u_u((((((!2L) & (--l_128)) > ((safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u(((((safe_add_func_int32_t_s_s(l_120, 1UL)) | l_127) , 1L) || l_126), p_95)), p_96.f0)) >= p_96.f0)) >= p_96.f0) & g_1276), l_127)) && g_240), 0xCC1C6A88B8388ADFLL)) >= l_120)) , g_240) < g_39), 13)), 3)) && l_126), 4)), __undefined)), 6)) <= l_126) != 1UL)) >= g_240) <= l_127);
        l_127 = ((((l_139 , 0xCFL) <= (l_159.f0 == (0xFF4B716CAE9C981CLL < l_126))) <= (0x1CL < ((g_240 , l_126) , ((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(0xAF64L, l_159.f0)) != p_95), p_95)), 0x92ADL)) < p_95)))) | 0xFAL);
        for (l_159.f0 = 0; (l_159.f0 != 25); l_159.f0 = safe_add_func_int64_t_s_s(l_159.f0, 8))
        {
            uint32_t l_163 = 0UL;
            int32_t l_168 = 0x35FECE65L;
            int32_t l_185 = 1L;
            int32_t l_186 = 0xCCA4C161L;
            int32_t l_187 = 5L;

g_377 &= (safe_lshift_func_uint16_t_u_s((g_66 >= l_207), ((safe_div_func_uint8_t_u_u(func_94((safe_div_func_uint16_t_u_u(g_32, 1L)), l_159, p_96.f0), 0xCDL)) | p_96.f0)));



if ((((safe_lshift_func_uint8_t_u_s((g_33 = (safe_rshift_func_uint8_t_u_s(l_163, 2))), g_240)) && (((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_int8_t_s_s(((((l_266 = l_266) , ((l_211 = (safe_add_func_int64_t_s_s(((((g_527 != p_95) == (((safe_rshift_func_int16_t_s_u((3UL == (((g_13 <= 0xB1A0L) != (((((safe_rshift_func_uint8_t_u_u(((!p_95) , l_126), 5)) > l_128) & (-10L)) , 0xE1L) > g_528)) , g_801)), g_240)) & 5L) || 0xA2B9BF124FD362E7LL)) == g_240) , (-1L)), l_128))) && l_211)) & g_13) >= 0x62L), l_128)) , g_240))) >= g_801) | 1L)) , p_95))
        {
            int8_t l_295 = (-5L);
            --g_528;
            l_266.f4 &= ((((g_65 &= 0x62L) <= ((l_207 = ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^ (g_791 = g_30)) & (safe_rshift_func_uint16_t_u_s(0x2310L, 10))) , ((l_186 ^ ((l_211 &= (l_295 != ((((p_95 = ((l_168 & ((~((((p_96 , (l_126 ^ l_266.f3)) > l_126) != 0x2A7A2EF32379F2B3LL) != g_13)) && l_295)) && l_295)) >= 0L) , 0x1AL) | 0x83L))) >= l_266.f2)) != l_126)) <= l_168) && (-1L)) || l_266.f1) , g_240)) | 1UL)) > 5L) ^ 0xDF8CL);
        }
        else
        {
            l_266.f2 = (-4L);
            for (l_162 = (-19); (l_162 > 10); l_162 = safe_add_func_uint16_t_u_u(l_162, 6))
            {
                l_266 = g_238;
            }
        };


                    g_241 ^= (g_240 == ((safe_mod_func_int16_t_s_s(((safe_div_func_uint64_t_u_u(((0x23B04249L >= (safe_mod_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s(((((l_159 = l_158) , l_159) , (safe_lshift_func_uint16_t_u_s((++l_163), (safe_mod_func_uint32_t_u_u(l_168, (safe_div_func_int32_t_s_s((g_240 > ((p_96.f0 |= (safe_sub_func_uint64_t_u_u((safe_add_func_int32_t_s_s((65530UL | (safe_div_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(0x88AFL, (safe_add_func_int16_t_s_s((((l_158 = l_159) , (-10L)) & 0xC4A096ABL), 0xBEFCL)))), g_39))), l_181)), l_207))) ^ 0x3F1CL)), 0xBE4CFF9CL))))))) < l_162), 7)) | l_139.f2) || g_69), p_95))) != 0x1A2308598B864A24LL), l_139.f5)) < 1L), 0x8ABAL)) < p_95));
            --g_801;

{
                int32_t l_519 = (-1L);
                int32_t l_521 = 0xC5583EF5L;
                g_65 &= ((0L < (((((safe_add_func_int64_t_s_s(((safe_lshift_func_int16_t_s_s(((-10L) | g_800), ((safe_sub_func_int16_t_s_s((g_800 = (((l_206 |= ((safe_sub_func_int32_t_s_s(((safe_sub_func_int16_t_s_s(g_238.f2, (__undefined = (safe_sub_func_uint8_t_u_u(g_315, (((g_238 , g_238.f1) , l_139) , (safe_add_func_uint8_t_u_u((safe_sub_func_uint64_t_u_u(((((g_301++) && (g_301 != 0xAEL)) ^ 0x9714L) <= 0xD7EAL), 0x1FBFD773E599F898LL)), g_801)))))))) < g_238.f5), p_95)) < g_315)) && 0x22L) ^ l_128)), g_184)) != g_238.f5))) , g_66), l_120)) != l_163) > g_188) || l_206) <= p_96.f0)) || g_238.f2);
                l_120++;
                g_238.f4 &= (safe_sub_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(g_39, 0x32B0L)), 0x8C89L));
            }

                    g_801++;
        }

{
                        uint64_t l_657 = 1UL;
                        l_266.f5 = 0xC207066FL;

g_967 &= (safe_div_func_uint8_t_u_u(((g_1249 ^= g_791) & (((g_12 = (g_65 = (0xDA1D0942DF00AC9ELL >= 0x9644A59A1FF38044LL))) ^ 0xCA3631A0D171E9D6LL) <= (g_928 |= ((safe_sub_func_uint64_t_u_u(0x6750A3B4BAC7944CLL, g_65)) > (func_85((l_206 &= (safe_lshift_func_uint16_t_u_s((l_126 >= g_38), ((safe_div_func_uint8_t_u_u(func_94((safe_div_func_uint16_t_u_u(__undefined, 1L)), p_96, g_21.f0), 0xCDL)) | g_21.f0)))), g_527, p_97) < g_65))))), (-4L)));


                    g_377 = (((safe_add_func_uint64_t_u_u(((((safe_sub_func_int8_t_s_s(((0xD8941FD6L ^ (g_792 = ((((safe_div_func_uint8_t_u_u(g_873, ((~(safe_sub_func_int8_t_s_s(0L, (safe_rshift_func_int16_t_s_s(((+(l_210 = (safe_mod_func_uint64_t_u_u(l_128, (g_527 &= ((safe_add_func_int8_t_s_s((g_793 = g_524), (safe_mod_func_int8_t_s_s(l_139.f3, (safe_sub_func_int16_t_s_s((~0xD6L), (((safe_div_func_int32_t_s_s((l_139.f5 &= g_188), (safe_mod_func_uint8_t_u_u(((~p_97) , l_139.f1), 255UL)))) , g_792) & l_139.f2))))))) != 0xA14CL)))))) <= p_97), l_657))))) && 6UL))) == g_791) <= g_199.f0) <= 1L))) , g_793), g_199.f0)) == l_266.f4) || l_139.f0) | g_524), g_793)) , 0x672551F9L) , 0xA150D49BL);
                    }

                    if (p_95)
        {
            struct S0 l_200 = {0x8CAFL};
            int32_t l_205 = (-1L);
            int32_t l_208 = 0x15D7F043L;
            uint16_t l_215 = 0xEBE3L;
            struct S1 l_237 = {4888,4404,-28,3688,-181,0,4061};
            int32_t l_239 = 0x45497A7BL;
            for (l_128 = 14; (l_128 == 54); l_128++)
            {
                uint16_t l_196 = 1UL;
                l_196--;


g_38 |= g_524;

                    for (g_33 = (-27); (g_33 < 39); g_33 = safe_add_func_uint8_t_u_u(g_33, 8))
    {
        int32_t l_284 = 0xEE263D41L;
        uint64_t l_288 = 18446744073709551615UL;
        int32_t l_290 = 9L;
        int32_t l_296 = 0xC6978A9AL;
        int32_t l_297 = 0x9ADCCFBDL;
        int32_t l_299 = 8L;
        int32_t l_300 = 0x80C45391L;
        struct S0 l_311 = {1UL};
        struct S1 l_314 = {15034,7901,-16,6783,-510,-0,5803};
        if ((((safe_lshift_func_uint8_t_u_s((g_322 = (safe_rshift_func_uint8_t_u_s(l_120, 2))), g_66)) && (((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_int8_t_s_s(((((g_238 = g_238) , ((l_209 = (safe_add_func_int64_t_s_s(((((g_32 != p_95) == (((safe_rshift_func_int16_t_s_u((3UL == (((l_284 <= 0xB1A0L) != (((((safe_rshift_func_uint8_t_u_u(((!p_95) , g_240), 5)) > l_288) & (-10L)) , 0xE1L) > g_1249)) , g_33)), g_66)) & 5L) || 0xA2B9BF124FD362E7LL)) == g_66) , (-1L)), l_288))) && l_209)) & l_284) >= 0x62L), l_288)) , g_66))) >= g_33) | 1L)) , p_95))
        {
            int8_t l_295 = (-5L);
            --l_203;
            g_238.f4 &= ((((l_211 &= 0x62L) <= ((g_800 = ((((((((safe_lshift_func_int16_t_s_s(0x6090L, 11)) ^ (g_571 = l_210)) & (safe_rshift_func_uint16_t_u_s(0x2310L, 10))) , ((g_37 ^ ((l_209 &= (l_295 != ((((g_993 = ((l_208 & ((~((((l_311 , (g_240 ^ g_238.f3)) > g_240) != 0x2A7A2EF32379F2B3LL) != l_284)) && l_295)) && l_295)) >= 0L) , 0x1AL) | 0x83L))) >= g_238.f2)) != g_240)) <= l_296) && (-1L)) || g_238.f1) , g_524)) | 1UL)) > 5L) ^ 0xDF8CL);
        }
        else
        {

if (__undefined)
                            break;

                    g_238.f2 = (-4L);
            for (l_300 = (-19); (l_300 > 10); l_300 = safe_add_func_uint16_t_u_u(l_300, 6))
            {
                g_238 = l_314;
            }
        }
    };



{
                        int32_t l_1099 = 0x29D6DC62L;
                        g_182 |= ((safe_add_func_uint16_t_u_u(((safe_div_func_int64_t_s_s(((safe_rshift_func_uint8_t_u_s((g_69 |= l_139.f1), 0)) <= p_95), (((safe_lshift_func_uint16_t_u_u((g_793 |= (((g_377 = l_203) | ((l_139.f6 < (((0xE175236DL != (((0x686D572EL ^ ((((g_993 = ((((((1L >= ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((((g_967 |= (((safe_add_func_uint64_t_u_u((__undefined < (l_209 = ((l_139.f4 = l_139.f2) < g_38))), 0xB4C6519C0C658331LL)) | l_139.f1) , 0x869ACDBBBB3DB403LL)) & 0x55232CB130B1BF30LL) != 1UL), 3)) == 0xDDL), l_1099)) , l_214)) > l_139.f4) || l_139.f2) , 0x7F6B51B9FD79C856LL) != (-1L)) > l_139.f1)) && p_96.f0) && g_524) & g_13)) ^ l_214) & g_1285)) >= 0UL) , l_1099)) != g_69)) || 0x2FL)), g_524)) < l_139.f1) || 4294967294UL))) & l_159.f0), 65535UL)) >= l_139.f4);
                        if (l_139.f1)
                            continue;
                    }

                    l_200 = l_159;
            }
            l_127 = (((safe_sub_func_uint8_t_u_u(l_203, (g_240 , p_96.f0))) < ((l_215 = (l_139.f4 &= (+((((-1L) & ((0xAFL < (((g_801 == ((((l_139.f2 = (l_205 = (p_96 , 8L))) <= ((((((g_39++) ^ p_95) >= l_200.f0) , l_159) , l_159.f0) ^ (-7L))) > p_95) ^ p_95)) , 18446744073709551613UL) > l_127)) ^ l_200.f0)) && l_214) != 0x8890B9DDL)))) <= l_158.f0)) , l_139.f1);
            g_238 = ((((((safe_mod_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_s(((g_801 = (safe_lshift_func_int16_t_s_s((((((((safe_sub_func_int32_t_s_s(((((((safe_rshift_func_int16_t_s_s((+(p_95 && (g_240 = (-1L)))), (p_95 = l_207))) && (((safe_mod_func_uint16_t_u_u(l_215, (safe_lshift_func_uint8_t_u_s(((p_96.f0 , 1L) , (0x34L != (safe_lshift_func_int8_t_s_s((safe_mod_func_uint64_t_u_u((p_95 >= (safe_add_func_uint64_t_u_u((__undefined == 4294967290UL), p_95))), p_96.f0)), l_139.f5)))), 5)))) | l_205) & 0x8900E08CL)) || g_39) || p_95) <= 0x3DL) < g_240), g_240)) | 0xBFBDL) < l_159.f0) > l_210) != p_96.f0) | l_159.f0) <= 0xDC97BAAAL), 4))) || l_127), g_240)) | g_1276) == l_211), l_162)) ^ l_215) ^ p_95) || 1L) , l_203) , l_237);
            g_241++;
        }
        else
        {
            uint32_t l_265 = 0x211A307CL;
            g_238.f2 |= ((safe_lshift_func_uint8_t_u_s(255UL, (safe_rshift_func_uint8_t_u_s(g_39, 2)))) & (safe_sub_func_int16_t_s_s(l_139.f2, 1L)));
            l_207 &= (p_96 , l_139.f0);
            l_207 ^= (l_139.f5 = (g_238.f2 = (safe_div_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(l_158.f0, (((0x5DL > l_207) != (safe_unary_minus_func_int16_t_s(1L))) == ((((((l_203 > (safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_u(0xCBFBL, 6)) < (safe_add_func_uint32_t_u_u((((safe_sub_func_uint64_t_u_u(((((p_96 = p_96) , 0xA2463E9B3E846025LL) , (safe_div_func_int32_t_s_s(l_127, 0x810FC398L))) | l_265), p_95)) ^ l_265) || g_240), l_159.f0))), g_801))) ^ l_265) >= l_265) , l_266) , 249UL) , p_95)))) >= 5L) >= 255UL) , l_139.f6), p_95))));
        }
    }
    else
    {
        struct S0 l_267 = {0xB8F5L};

for (g_571 = (-19); (g_571 > 10); g_571 = safe_add_func_uint16_t_u_u(g_571, 6))
            {

{
                int32_t l_519 = (-1L);
                int32_t l_521 = 0xC5583EF5L;
                g_65 &= ((0L < (((((safe_add_func_int64_t_s_s(((safe_lshift_func_int16_t_s_s(((-10L) | l_209), ((safe_sub_func_int16_t_s_s((g_571 = (((g_37 |= ((safe_sub_func_int32_t_s_s(((safe_sub_func_int16_t_s_s(l_139.f2, (g_527 = (safe_sub_func_uint8_t_u_u(g_315, (((l_139 , l_139.f1) , l_139) , (safe_add_func_uint8_t_u_u((safe_sub_func_uint64_t_u_u(((((l_265++) && (l_265 != 0xAEL)) ^ 0x9714L) <= 0xD7EAL), 0x1FBFD773E599F898LL)), g_69)))))))) < l_139.f5), p_97)) < g_315)) && 0x22L) ^ l_128)), g_993)) != l_139.f5))) , g_67), g_378)) != g_241) > g_191) || l_211) <= p_96.f0)) || l_139.f2);
                g_182++;
                l_139.f4 &= (safe_sub_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(g_39, 0x32B0L)), 0x8C89L));
            }

                    g_238 = l_139;
            };


                    l_267 = (l_159.f0 , l_159);
        p_96 = p_96;
    }
    return g_241;
}

                    g_65 &= (p_96 , l_139.f0);
            l_207 ^= (l_139.f5 = (g_238.f2 = (safe_div_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(l_158.f0, (((0x5DL > g_65) != (safe_unary_minus_func_int16_t_s(1L))) == ((((((l_203 > (safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_u(0xCBFBL, 6)) < (safe_add_func_uint32_t_u_u((((safe_sub_func_uint64_t_u_u(((((p_96 = p_96) , 0xA2463E9B3E846025LL) , (safe_div_func_int32_t_s_s(g_37, 0x810FC398L))) | l_265), p_97)) ^ l_265) || g_12), g_21.f0))), g_188))) ^ l_265) >= l_265) , l_266) , 249UL) , p_95)))) >= 5L) >= 255UL) , l_139.f6), p_95))));
        }
    }
    else
    {
        struct S0 l_267 = {0xB8F5L};

{
                int32_t l_519 = (-1L);
                int32_t l_521 = 0xC5583EF5L;

l_139.f1 &= (7L & ((g_36 ^= ((((l_128 = ((p_95 != 0x4CL) == (+(((-9L) == g_36) > 0UL)))) <= ((((safe_mod_func_uint8_t_u_u((g_33 = l_139.f0), g_800)) <= 0xA1BF90C52FB11BB9LL) <= 1UL) & g_301)) , g_238) , g_800)) <= g_238.f2));


                    g_37 &= ((0L < (((((safe_add_func_int64_t_s_s(((safe_lshift_func_int16_t_s_s(((-10L) | l_127), ((safe_sub_func_int16_t_s_s((g_792 = (((g_38 |= ((safe_sub_func_int32_t_s_s(((safe_sub_func_int16_t_s_s(g_238.f2, (g_527 = (safe_sub_func_uint8_t_u_u(g_928, (((g_238 , g_238.f1) , l_139) , (safe_add_func_uint8_t_u_u((safe_sub_func_uint64_t_u_u(((((g_378++) && (g_378 != 0xAEL)) ^ 0x9714L) <= 0xD7EAL), 0x1FBFD773E599F898LL)), g_1276)))))))) < g_238.f5), p_95)) < g_928)) && 0x22L) ^ g_39)), g_993)) != g_238.f5))) , g_586), g_968)) != l_203) > g_69) || g_38) <= g_199.f0)) || g_238.f2);
                g_968++;
                g_238.f4 &= (safe_sub_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(l_128, 0x32B0L)), 0x8C89L));
            }

                    l_267 = (g_21.f0 , l_159);


g_756 &= 0x62L;



g_791 |= ((safe_div_func_uint8_t_u_u(((safe_div_func_uint8_t_u_u((safe_div_func_uint16_t_u_u((--g_928), l_139.f0)), (0x5A0BAD988B54577ELL || (g_791 != (g_199 , (safe_lshift_func_int16_t_s_u((-3L), (l_139.f1 | (safe_add_func_int8_t_s_s(l_139.f3, (safe_sub_func_int32_t_s_s((safe_div_func_int8_t_s_s(((g_39 = ((((safe_div_func_int16_t_s_s((0x7BF8L > ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((g_377 = (p_96 , g_13)), 14)), 6)) >= p_97)), g_967)) && 0xD5682F7CL) <= g_241) == g_188)) >= 65527UL), 251UL)), 0xFC6382EAL)))))))))))) > p_97), g_792)) < 1L);

                    g_184 |= (safe_add_func_int32_t_s_s((g_238.f5 = ((((g_69 != (((((0x05L == ((0x25L ^ (safe_lshift_func_uint16_t_u_u((((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s((l_159 , g_238.f5), (((l_139 , g_238.f3) , l_139) , 0L))) || l_127), g_1249)) >= l_139.f4) >= 7UL), 13))) < g_322)) , 0x67L) & g_191) , 0xC3L) | g_873)) || g_238.f6) , 0L) , g_791)), g_188));



for (g_39 = 14; (g_39 == 54); g_39++)
            {
                uint16_t l_196 = 1UL;
                l_196--;
                p_96 = l_267;
            }
g_792 |= g_240;

                    ;



g_238.f5 ^= (0x70BD7A420812CA0FLL > (safe_rshift_func_int16_t_s_u((((l_139 = l_139) , g_238.f0) , (safe_rshift_func_uint8_t_u_s(l_139.f5, (0xF1AA9032L >= l_139.f6)))), 1)));


                    p_96 = p_96;
    }
    return g_241;
}







static int64_t func_101(int32_t p_102, uint16_t p_103)
{
    return g_66;
}





int main (int argc, char* argv[])
{
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
    transparent_crc(g_12, "g_12", print_hash_value);
    transparent_crc(g_13, "g_13", print_hash_value);
    transparent_crc(g_21.f0, "g_21.f0", print_hash_value);
    transparent_crc(g_30, "g_30", print_hash_value);
    transparent_crc(g_32, "g_32", print_hash_value);
    transparent_crc(g_33, "g_33", print_hash_value);
    transparent_crc(g_36, "g_36", print_hash_value);
    transparent_crc(g_37, "g_37", print_hash_value);
    transparent_crc(g_38, "g_38", print_hash_value);
    transparent_crc(g_39, "g_39", print_hash_value);
    transparent_crc(g_65, "g_65", print_hash_value);
    transparent_crc(g_66, "g_66", print_hash_value);
    transparent_crc(g_67, "g_67", print_hash_value);
    transparent_crc(g_69, "g_69", print_hash_value);
    transparent_crc(g_80, "g_80", print_hash_value);
    transparent_crc(g_182, "g_182", print_hash_value);
    transparent_crc(g_183, "g_183", print_hash_value);
    transparent_crc(g_184, "g_184", print_hash_value);
    transparent_crc(g_188, "g_188", print_hash_value);
    transparent_crc(g_191, "g_191", print_hash_value);
    transparent_crc(g_199.f0, "g_199.f0", print_hash_value);
    transparent_crc(g_238.f0, "g_238.f0", print_hash_value);
    transparent_crc(g_238.f1, "g_238.f1", print_hash_value);
    transparent_crc(g_238.f2, "g_238.f2", print_hash_value);
    transparent_crc(g_238.f3, "g_238.f3", print_hash_value);
    transparent_crc(g_238.f4, "g_238.f4", print_hash_value);
    transparent_crc(g_238.f5, "g_238.f5", print_hash_value);
    transparent_crc(g_238.f6, "g_238.f6", print_hash_value);
    transparent_crc(g_240, "g_240", print_hash_value);
    transparent_crc(g_241, "g_241", print_hash_value);
    transparent_crc(g_301, "g_301", print_hash_value);
    transparent_crc(g_315, "g_315", print_hash_value);
    transparent_crc(g_322, "g_322", print_hash_value);
    transparent_crc(g_377, "g_377", print_hash_value);
    transparent_crc(g_378, "g_378", print_hash_value);
    transparent_crc(g_524, "g_524", print_hash_value);
    transparent_crc(g_527, "g_527", print_hash_value);
    transparent_crc(g_528, "g_528", print_hash_value);
    transparent_crc(g_571, "g_571", print_hash_value);
    transparent_crc(g_586, "g_586", print_hash_value);
    transparent_crc(g_620, "g_620", print_hash_value);
    transparent_crc(g_756, "g_756", print_hash_value);
    transparent_crc(g_791, "g_791", print_hash_value);
    transparent_crc(g_792, "g_792", print_hash_value);
    transparent_crc(g_793, "g_793", print_hash_value);
    transparent_crc(g_800, "g_800", print_hash_value);
    transparent_crc(g_801, "g_801", print_hash_value);
    transparent_crc(g_873, "g_873", print_hash_value);
    transparent_crc(g_928, "g_928", print_hash_value);
    transparent_crc(g_967, "g_967", print_hash_value);
    transparent_crc(g_968, "g_968", print_hash_value);
    transparent_crc(g_993, "g_993", print_hash_value);
    transparent_crc(g_1249, "g_1249", print_hash_value);
    transparent_crc(g_1276, "g_1276", print_hash_value);
    transparent_crc(g_1285, "g_1285", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

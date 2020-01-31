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
void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);static long __undefined;



static const uint8_t g_18 = 0x96L;
static uint32_t g_22 = 18446744073709551615UL;
static uint8_t g_59 = 0x26L;
static int8_t g_89 = 0xE8L;
static int8_t g_97[7] = {0x9AL, 0x9AL, 0x9AL, 0x9AL, 0x9AL, 0x9AL, 0x9AL};
static int8_t g_100 = 0x2FL;
static int16_t g_101 = 0x8DB7L;
static int32_t g_120[5] = {0x9873F28DL, 0x9873F28DL, 0x9873F28DL, 0x9873F28DL, 0x9873F28DL};
static uint32_t g_143 = 4294967295UL;
static int16_t g_540 = 0xE6F4L;
static int16_t g_694 = 0L;
static int8_t g_717 = 0x46L;
static uint32_t g_777 = 0xDDF76E03L;
static uint32_t g_849[1] = {0xBCE5A530L};
static int16_t g_935 = (-1L);
static uint32_t g_1168 = 0x7D4DB357L;
static uint8_t g_1171 = 7UL;
static uint16_t g_1217 = 0xB6F3L;
static int32_t g_1368[3] = {(-2L), (-2L), (-2L)};
static int16_t g_1482[4][3][4] = {{{0L, 1L, (-1L), 0x7568L}, {0L, 1L, (-1L), 0x7568L}, {0L, 1L, (-1L), 0x7568L}}, {{0L, 1L, (-1L), 0x7568L}, {0L, 1L, (-1L), 0x7568L}, {0L, 1L, (-1L), 0x7568L}}, {{0L, 1L, (-1L), 0x7568L}, {0L, 1L, (-1L), 0x7568L}, {0L, 1L, (-1L), 0x7568L}}, {{0L, 1L, (-1L), 0x7568L}, {0L, 1L, (-1L), 0x7568L}, {0L, 1L, (-1L), 0x7568L}}};
static int32_t g_1540[6][2] = {{3L, (-8L)}, {3L, (-8L)}, {3L, (-8L)}, {3L, (-8L)}, {3L, (-8L)}, {3L, (-8L)}};
static int32_t g_1548[10][8][3] = {{{6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}}, {{6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}}, {{6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}}, {{6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}}, {{6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}}, {{6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}}, {{6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}}, {{6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}}, {{6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}}, {{6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}, {6L, 1L, 0x1E78C61EL}}};
static int8_t g_2003[6] = {8L, 0x85L, 8L, 0x85L, 8L, 0x85L};
static int32_t g_2100 = (-1L);
static int16_t g_2184[3][3] = {{0xC198L, 0x0844L, 0xC198L}, {0xC198L, 0x0844L, 0xC198L}, {0xC198L, 0x0844L, 0xC198L}};
static int16_t g_2254 = (-10L);
static uint16_t g_2414 = 2UL;
static uint8_t g_2431 = 1UL;
static uint32_t g_2467 = 0x7A51E780L;
static const int32_t g_2468 = 0x6A00EF02L;
static int32_t g_2469 = 1L;
static int32_t g_2470[3][1][10] = {{{0xD1D11586L, (-1L), (-6L), (-6L), (-1L), 0xD1D11586L, (-1L), (-6L), (-6L), (-1L)}}, {{0xD1D11586L, (-1L), (-6L), (-6L), (-1L), 0xD1D11586L, (-1L), (-6L), (-6L), (-1L)}}, {{0xD1D11586L, (-1L), (-6L), (-6L), (-1L), 0xD1D11586L, (-1L), (-6L), (-6L), (-1L)}}};



static uint16_t func_1(void);
static int32_t func_3(int32_t p_4, uint16_t p_5, int32_t p_6, uint8_t p_7, uint32_t p_8);
static int16_t func_10(uint32_t p_11, uint8_t p_12, int32_t p_13);
static int32_t func_19(int16_t p_20);
static int16_t func_25(uint16_t p_26);
static int16_t func_28(int32_t p_29, int32_t p_30);
static int16_t func_33(uint32_t p_34, int16_t p_35);
static int16_t func_38(int32_t p_39, int8_t p_40, uint16_t p_41, int16_t p_42, uint16_t p_43);
static int32_t func_46(uint8_t p_47, uint16_t p_48, int16_t p_49, uint8_t p_50, uint16_t p_51);
static int16_t func_54(int32_t p_55, const uint32_t p_56, int8_t p_57, uint8_t p_58);
static uint16_t func_1(void)
{
    uint32_t l_2[1];
    int16_t l_9 = 0x4210L;
    int i;
                                        if (!((g_777 > g_1168)) )
{

{
            for (i = 0; i < 4; i++)
            {
                transparent_crc(g_1482[i][g_2100][i], "g_1482[i][g_2100][i]", g_2469);
                if (g_2469) printf("index = [%d][%d][%d]\n", i, g_2100, i);

            }
        }

}
                    for (i = 0; i < 1; i++)
        l_2[i] = 0xB50BF34FL;
                                        if ((g_2469>1) )
{

g_1217 ^= i;

}
                    l_2[0] = 0xA8EAC8B1L;
                                   uint32_t BOoOog_22 = (~(((-((g_101 - ((-(g_1217)) | g_694)))) & (~(((g_22 * g_59) ^ (((~(((-(g_143)) || (~(g_1168))))) - ((-(g_89)) | g_2469)) * g_1171)))))));
uint32_t BOoOobg_1168 = (~(((~((~(((g_143 - (~(((-(g_1217)) - ((g_22 & g_2469) - g_1168))))) & ((g_89 || g_101) ^ (~(((~((g_694 & (~(g_1171))))) * g_59))))))))) || (-((~(BOoOog_22)))))));
uint8_t BOoOocg_1171 = (~(((~(((~(g_89)) - (-(g_1168))))) | ((~((g_694 ^ g_143))) | ((-(BOoOog_22)) - ((((~((~((~(BOoOobg_1168)))))) || (-(((~(g_22)) || (g_1217 >> g_2469))))) - (g_59 - g_1171)) & (~((~(g_101))))))))));
int16_t BOoOodg_101 = (~(((((~(((g_694 ^ (~(g_22))) * g_1168))) - (g_89 * ((((-(g_101)) - ((g_1171 | BOoOog_22) >> (BOoOocg_1171 & g_59))) >> (~((~(g_2469))))) | (-(g_1217))))) * (~(g_143))) - BOoOobg_1168)));
int32_t BOoOoeg_2469 = (~((((~((~(((~((~(g_694)))) & BOoOocg_1171))))) * (-(((((BOoOodg_101 & BOoOobg_1168) * (g_59 & g_101)) | (-((-(((~(g_1168)) - (BOoOog_22 * (~(g_1171))))))))) * (-(g_143)))))) | (~((~(((-(g_22)) * ((~((~(g_1217)))) & ((~(g_2469)) ^ (~(g_89))))))))))));
uint32_t BOoOofg_143 = (~(((~(((-(g_2469)) | (-((~(g_1217))))))) | ((((-((g_22 * ((BOoOoeg_2469 | g_101) | BOoOocg_1171)))) | ((~(g_1168)) << (g_89 || g_694))) & (BOoOog_22 | (~(BOoOobg_1168)))) || (~(((g_143 - (g_1171 || BOoOodg_101)) & g_59)))))));
if(!((!g_101))){
BOoOog_22 = g_22;
BOoOobg_1168 = g_1168;
BOoOocg_1171 = g_1171;
BOoOodg_101 = g_101;
BOoOoeg_2469 = g_2469;
BOoOofg_143 = g_143;
g_22 = (~((((((-(g_1171)) ^ BOoOoeg_2469) * (-((BOoOocg_1171 || BOoOog_22)))) | ((g_1168 >> (g_694 * (~(g_89)))) * ((BOoOofg_143 - (-(BOoOobg_1168))) & (~((-(g_101))))))) - (~(((~(((-(((~(g_22)) | (g_1217 | (g_2469 & BOoOodg_101))))) | g_143))) - g_59))))));
g_1168 = (-(((((~((-(((~(g_1171)) - g_1168))))) * ((g_1217 || (~(g_89))) ^ g_143)) & (~((((g_101 || BOoOobg_1168) ^ (~((BOoOodg_101 | g_694)))) & (~(g_2469)))))) * (~((((~(((-(g_22)) * (~(BOoOog_22))))) - (BOoOofg_143 | (~((~(BOoOoeg_2469)))))) & (g_59 & BOoOocg_1171)))))));
g_1171 = (~(((((~((~(g_22)))) * (((-(BOoOog_22)) || (-(g_89))) & (~(((~((g_694 ^ BOoOoeg_2469))) ^ g_2469))))) & (((BOoOocg_1171 & g_59) * (~(BOoOobg_1168))) || ((-((g_143 || g_101))) ^ (g_1171 & g_1168)))) * (((-(g_1217)) - BOoOofg_143) | BOoOodg_101))));
g_101 = (~(((((g_101 - (~(g_694))) * (((~(BOoOocg_1171)) * (-((BOoOog_22 * (~(g_89)))))) ^ g_1168)) - (((~(((g_143 || g_2469) ^ BOoOoeg_2469))) || (g_1217 || g_22)) ^ ((BOoOobg_1168 & BOoOodg_101) | (~(BOoOofg_143))))) ^ ((~(g_1171)) || (~((-(g_59))))))));
g_2469 = (~(((~((~((~((BOoOoeg_2469 ^ ((BOoOocg_1171 ^ g_1171) - (-(g_143)))))))))) << (~((~(((~(((-(((g_694 || (g_59 * BOoOodg_101)) - ((~((-(g_89)))) | (BOoOog_22 ^ g_1217))))) >> ((g_1168 || (g_2469 | BOoOofg_143)) & (-((~(((~(BOoOobg_1168)) * g_101))))))))) & (~(g_22))))))))));
g_143 = (~(((~(((g_59 | BOoOobg_1168) - (~(((BOoOoeg_2469 ^ g_1171) ^ BOoOofg_143)))))) - ((~((((((BOoOodg_101 * g_1217) || (-(g_101))) | g_2469) - (BOoOog_22 ^ BOoOocg_1171)) * (-((g_694 & (g_143 * (g_1168 - g_22)))))))) << (~(g_89))))));
if((g_89>-24)){
printf("g_22=%llu\n", (unsigned long long)g_22);
BOoOog_22 = (~(((((g_22 & (g_59 || (BOoOocg_1171 - g_89))) | (g_1217 | (g_143 >> BOoOoeg_2469))) ^ ((((-(BOoOofg_143)) ^ (~(BOoOobg_1168))) - (g_694 * BOoOog_22)) ^ (((g_1171 ^ BOoOodg_101) - g_2469) ^ g_101))) ^ g_1168)));
g_143 = (~(((((-(((g_694 >> BOoOofg_143) & (g_1217 * g_101)))) >> ((~((-((g_22 * (BOoOog_22 | BOoOodg_101)))))) - (-(g_1171)))) ^ (~((-((((~(g_89)) << (-(BOoOobg_1168))) | (~(g_2469)))))))) & (((~(((~(g_143)) << (~((~(BOoOoeg_2469))))))) & (-((g_1168 - g_59)))) || BOoOocg_1171))));
}
if((BOoOog_22<4294967295U)){
printf("g_1168=%llu\n", (unsigned long long)g_1168);
BOoOog_22 = (~((((((-(g_1217)) ^ ((~(BOoOoeg_2469)) >> BOoOog_22)) - ((g_101 - BOoOocg_1171) | BOoOobg_1168)) * ((~((BOoOodg_101 || (g_89 >> g_22)))) || (-((g_143 - (g_2469 | g_59)))))) >> (-((g_694 >> ((-((-(BOoOofg_143)))) ^ (~((g_1168 & g_1171))))))))));
g_1168 = (~((((-(g_22)) | (~(BOoOog_22))) | (~(((~((BOoOofg_143 >> BOoOoeg_2469))) << ((~((((~(BOoOodg_101)) - BOoOocg_1171) & ((~(g_694)) ^ (BOoOobg_1168 << g_1171))))) & (((g_143 ^ ((-(g_2469)) | g_101)) >> g_1217) & (~(((~((g_59 - g_89))) | (-(g_1168)))))))))))));
}
if((!(g_1168) && ((BOoOodg_101>-29257) || (g_1171<255)))){

i &= g_717;

                    printf("g_1171=%llu\n", (unsigned long long)g_1171);
BOoOoeg_2469 = (-(((~((-((((~(BOoOobg_1168)) * (g_59 ^ (~(g_1171)))) ^ (~((((-(BOoOodg_101)) << (g_694 * (g_22 >> (g_2469 - BOoOoeg_2469)))) | (~((~(BOoOofg_143)))))))))))) << (~((~(((~(g_1217)) | (-((~(((~(((BOoOog_22 & (g_143 * g_101)) | g_89))) << ((~(BOoOocg_1171)) * g_1168))))))))))))));
g_101 = (~((((-(g_143)) >> ((((BOoOodg_101 & g_694) * g_1217) * (g_89 * ((-((g_22 ^ BOoOocg_1171))) ^ (~((~((~((-(g_59))))))))))) * (-((~(BOoOoeg_2469)))))) & (~((((~((g_1171 * BOoOobg_1168))) & ((~((-((g_1168 || BOoOofg_143))))) & (g_101 << (~(g_2469))))) >> (~(BOoOog_22))))))));
BOoOodg_101 = (-(((~(BOoOog_22)) - (~(((BOoOofg_143 || (~((((~(g_22)) | (~((-(g_101))))) * (~(((g_89 >> (g_694 * (~(g_143)))) | ((~((((g_1217 ^ BOoOobg_1168) | BOoOocg_1171) ^ g_2469))) >> (g_59 ^ (BOoOodg_101 ^ BOoOoeg_2469)))))))))) & ((-(g_1171)) << (~(g_1168)))))))));
}
if((g_59>38)){
printf("g_101=%lld\n", (long long)g_101);
BOoOobg_1168 = (~(((((~(BOoOocg_1171)) | g_89) & (((g_22 | g_59) | (g_101 * ((g_694 << (BOoOodg_101 << g_1168)) ^ BOoOoeg_2469))) & (BOoOobg_1168 * ((-(g_143)) * g_1217)))) || (-((~(((~((g_2469 ^ (BOoOog_22 & BOoOofg_143)))) * (-((~(g_1171))))))))))));
g_143 = (-((((BOoOodg_101 || g_22) ^ ((g_59 >> BOoOofg_143) << (BOoOog_22 | g_2469))) * ((~(((g_101 - (g_1217 - g_1171)) & ((g_143 << (g_89 ^ g_1168)) << ((~((-(BOoOocg_1171)))) - ((~(g_694)) >> BOoOoeg_2469)))))) << (~(BOoOobg_1168))))));
}
if((!g_1168)){
printf("g_2469=%lld\n", (long long)g_2469);
BOoOofg_143 = (~((((g_1168 >> g_89) ^ BOoOoeg_2469) >> ((-((~(BOoOog_22)))) ^ ((~((((-((~((-(g_101)))))) | ((~(g_59)) || (((BOoOodg_101 | (BOoOocg_1171 * g_143)) || g_1217) * BOoOofg_143))) * (-((~(g_694))))))) | ((-(BOoOobg_1168)) - ((g_2469 || g_1171) << g_22)))))));
BOoOocg_1171 = (~((((~(BOoOobg_1168)) - (g_101 >> ((BOoOofg_143 & g_694) || (-(g_1171))))) | ((-(((g_59 ^ g_22) * g_1168))) ^ ((-(((~((g_143 || (~(BOoOog_22))))) ^ ((((~(g_1217)) || (BOoOodg_101 || BOoOocg_1171)) & g_89) << (~(BOoOoeg_2469)))))) - g_2469)))));
}
if(((BOoOog_22 < BOoOocg_1171) || (BOoOodg_101>-29257))){
printf("g_143=%llu\n", (unsigned long long)g_143);
g_2469 = (-(((-((~((~((~(((BOoOocg_1171 - BOoOog_22) << (g_1168 || g_2469)))))))))) || (((~(((g_694 >> g_1171) | (-(g_59))))) ^ ((~(BOoOodg_101)) >> (-(BOoOobg_1168)))) << (g_22 >> (((~((~((~((g_143 & g_89))))))) || (BOoOoeg_2469 - g_101)) * ((-((~(BOoOofg_143)))) >> (-(g_1217)))))))));
g_101 = (-(((~((~(g_143)))) ^ ((((~((-((BOoOoeg_2469 - BOoOofg_143))))) | (BOoOodg_101 >> BOoOocg_1171)) << (g_101 & (-((~(g_1171)))))) & ((~((~((g_1168 & g_59))))) - ((g_89 || (-((g_22 || BOoOog_22)))) & (g_694 & (((-(BOoOobg_1168)) * g_1217) >> g_2469))))))));
}
}
g_22 = BOoOog_22;
g_1168 = BOoOobg_1168;
                                   if (g_1217)
                    g_1171 = BOoOocg_1171;
g_101 = BOoOodg_101;
g_2469 = BOoOoeg_2469;
g_143 = BOoOofg_143;

                                                       if ((g_100<=47))
                    g_120[1] = func_3(l_9, (func_10(l_2[0], ((safe_lshift_func_uint16_t_u_u((safe_add_func_uint16_t_u_u(g_18, l_2[0])), (func_19(l_2[0]) , (((g_1171 < g_120[1]) != g_89) & l_2[0])))) , l_9), g_1368[1]) != g_1168), l_2[0], g_1168, g_1540[1][0]);
                                       if (g_2431)
                    return g_1548[4][3][1];
}







static int32_t func_3(int32_t p_4, uint16_t p_5, int32_t p_6, uint8_t p_7, uint32_t p_8)
{
    const uint8_t l_2352 = 0UL;
    int16_t l_2357 = 0xCDFDL;
    int8_t l_2397 = (-6L);
    int32_t l_2415 = 5L;
    int32_t l_2421 = 0x1502036FL;
    int32_t l_2429[1];
    uint16_t l_2465 = 0UL;
    uint8_t l_2515 = 0x8DL;
    int i;
    for (i = 0; i < 1; i++)
        l_2429[i] = 0xDAD1BFA1L;
                                                                           while ((!(g_2100) || !((l_2397 < g_100))) )
{

if (p_4) printf("index = [%d][%d][%d]\n", i, g_2100, l_2421);

}
                    if (((g_143<=4294967295U) && (g_2469>=1)))
                    for (g_717 = (-20); (g_717 <= 1); ++g_717)
    {
        int8_t l_2362 = 0xDCL;
        uint16_t l_2371 = 0UL;
        int32_t l_2376 = 1L;
        uint32_t l_2398[6][5];
        int32_t l_2418 = 8L;
        int32_t l_2419 = (-1L);
        int32_t l_2420 = 0xB04F07EDL;
        uint32_t l_2422 = 0x9AA580D4L;
        int32_t l_2511 = 1L;
        int32_t l_2512[4][8][3] = {{{0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}}, {{0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}}, {{0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}}, {{0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}, {0x23D4EB6DL, 0x23D4EB6DL, 0L}}};
        int16_t l_2514[7][2] = {{(-2L), 0xE089L}, {(-2L), 0xE089L}, {(-2L), 0xE089L}, {(-2L), 0xE089L}, {(-2L), 0xE089L}, {(-2L), 0xE089L}, {(-2L), 0xE089L}};
        int i, j, k;
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 5; j++)
                l_2398[i][j] = 1UL;
        }
        p_4 = ((l_2352 <= g_1548[9][4][0]) & (safe_add_func_int16_t_s_s(g_89, (safe_mul_func_uint32_t_u_u(4294967295UL, ((l_2357 && (((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(l_2362, ((((((safe_rshift_func_uint16_t_u_s(((safe_add_func_uint32_t_u_u((safe_sub_func_int8_t_s_s(((((safe_rshift_func_int16_t_s_u(((l_2357 <= g_849[0]) != l_2357), p_8)) ^ l_2362) == g_1368[1]) ^ 0x92AB813CL), 0x59L)), p_7)) & l_2362), 8)) >= g_59) , l_2357) ^ (-8L)) && 0L) != g_143))), p_4)) == 0x1DE1FACEL) == l_2371)) != 1L))))));
        l_2376 = ((safe_mod_func_int32_t_s_s(g_101, (safe_add_func_uint32_t_u_u((p_5 <= 0xDBA3D591L), g_1168)))) < l_2357);
        for (g_1168 = 0; (g_1168 >= 36); g_1168++)
        {
            uint32_t l_2389 = 0UL;
            int32_t l_2417[8] = {1L, 1L, 0x595B0FA1L, 1L, 1L, 0x595B0FA1L, 1L, 1L};
            int16_t l_2504 = 5L;
            int32_t l_2505[8][2][3] = {{{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}}, {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}}, {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}}, {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}}, {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}}, {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}}, {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}}, {{0x9C66CDCDL, 0x3F98A697L, 4L}, {0x9C66CDCDL, 0x3F98A697L, 4L}}};
            int16_t l_2513 = 1L;
            int i, j, k;
            for (g_1171 = 0; (g_1171 <= 44); g_1171 = safe_add_func_int8_t_s_s(g_1171, 2))
            {
                uint32_t l_2381 = 1UL;
                int32_t l_2416[6];
                uint32_t l_2436 = 0x4366B639L;
                uint32_t l_2466 = 0x760CFC11L;
                int32_t l_2502 = 0x2781DDD3L;
                int i;
                for (i = 0; i < 6; i++)
                    l_2416[i] = 5L;
                if (((l_2381 > p_4) || (safe_add_func_uint16_t_u_u(((((((((~p_6) != ((safe_add_func_int32_t_s_s((safe_sub_func_uint32_t_u_u(g_2184[2][0], (l_2389 == (p_5 < l_2362)))), (p_7 > (safe_sub_func_int8_t_s_s((safe_mod_func_int32_t_s_s((+((((safe_rshift_func_int16_t_s_u((l_2381 && (-1L)), g_694)) == 0UL) < l_2362) , g_97[2])), 0xE2D14996L)), l_2381))))) ^ l_2397)) && p_5) && 0x6F70B1C1L) != l_2389) , 0UL) == l_2357) == l_2389), l_2398[3][4]))))
                {
                    int32_t l_2413 = 0L;
                    int32_t l_2425 = 0x8DE3555FL;
                    int32_t l_2427 = 1L;
                    int32_t l_2428 = (-2L);
                    if ((safe_sub_func_int32_t_s_s((l_2362 , ((~g_2003[4]) != p_4)), (safe_lshift_func_uint16_t_u_s((safe_unary_minus_func_int32_t_s(g_2003[0])), 6)))))
                    {
                        p_4 = p_5;
                        l_2376 = (((safe_sub_func_uint32_t_u_u(2UL, (((safe_add_func_uint8_t_u_u((safe_sub_func_int16_t_s_s((((p_5 , (0x2E78BE00L <= (((safe_mod_func_int32_t_s_s((g_2184[1][1] > ((l_2413 ^ (1L > ((((0x544EL ^ p_4) , (g_1168 == p_4)) , l_2398[1][1]) < g_97[5]))) == l_2413)), 4294967295UL)) & p_7) || g_89))) & l_2352) && p_4), 65526UL)), g_2254)) , (-1L)) | g_2414))) == p_8) <= p_5);
                        if (p_5)
                            break;
                    }
                    else
                    {
                        if (l_2413)
                            break;
                        if (g_1482[2][1][1])
                            continue;
                    }
                    l_2422--;
                    for (l_2420 = 6; (l_2420 >= 1); l_2420 -= 1)
                    {
                        int32_t l_2426 = (-1L);
                        int32_t l_2430 = (-1L);
                        int i;
                        l_2417[(l_2420 + 1)] = g_97[l_2420];
                        g_2431--;
                    }
                }
                else
                {
                    if (l_2416[5])
                        break;
                    for (p_6 = 0; (p_6 == 24); p_6 = safe_add_func_int32_t_s_s(p_6, 5))
                    {
                        return p_5;
                    }
                }
                g_2470[0][0][5] &= (0x39A6L >= (l_2436 , (safe_add_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(p_4, (safe_sub_func_int32_t_s_s(l_2418, (safe_sub_func_uint32_t_u_u(((g_101 , (((safe_mod_func_uint32_t_u_u((((safe_add_func_int16_t_s_s(((((safe_add_func_uint16_t_u_u((((0UL | ((((((safe_mod_func_uint8_t_u_u(((safe_mod_func_uint8_t_u_u((((((safe_lshift_func_int8_t_s_s((p_4 , ((safe_mod_func_int16_t_s_s(((p_7 > ((safe_rshift_func_int16_t_s_s(((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(g_777, l_2465)), l_2371)) || 6UL), 7)) < 0x2256L)) < 0x4FL), g_1482[2][2][1])) > 0x8C0EL)), 5)) && 255UL) , l_2417[0]) || g_777) != p_5), g_120[1])) <= p_4), l_2466)) ^ p_8) , g_100) != p_7) != g_2467) & l_2417[0])) , l_2416[3]) && l_2418), p_6)) > 0x8D34L) , p_4) <= l_2436), l_2389)) , g_2468) < 6UL), 0xBA6FA250L)) , g_2469) , p_8)) , l_2398[2][1]), p_8)))))), p_5))));
                for (l_2420 = (-4); (l_2420 < (-28)); l_2420 = safe_sub_func_int32_t_s_s(l_2420, 2))
                {
                    uint16_t l_2499 = 0x99C0L;
                    int32_t l_2501 = 0xEDED4BBBL;
                    int32_t l_2503 = (-1L);
                    int32_t l_2506 = 0L;
                    int32_t l_2507 = (-1L);
                    uint16_t l_2508 = 0xF71CL;
                    if (((((safe_rshift_func_int8_t_s_u((+p_5), (safe_add_func_int32_t_s_s((l_2417[7] == ((l_2417[6] || p_5) | ((safe_lshift_func_uint8_t_u_s(l_2420, (((safe_lshift_func_uint16_t_u_s(0x21DFL, p_6)) > g_2431) == (safe_mod_func_int32_t_s_s(((safe_add_func_uint8_t_u_u(l_2417[6], 0L)) & p_8), p_8))))) & p_4))), 2L)))) == g_935) , g_1540[1][0]) ^ l_2417[6]))
                    {
                        int16_t l_2498 = 0x1DD5L;
                        int32_t l_2500[5][8] = {{(-7L), 0x47EEDBA2L, 8L, 1L, 3L, 2L, 3L, 1L}, {(-7L), 0x47EEDBA2L, 8L, 1L, 3L, 2L, 3L, 1L}, {(-7L), 0x47EEDBA2L, 8L, 1L, 3L, 2L, 3L, 1L}, {(-7L), 0x47EEDBA2L, 8L, 1L, 3L, 2L, 3L, 1L}, {(-7L), 0x47EEDBA2L, 8L, 1L, 3L, 2L, 3L, 1L}};
                        int i, j;
                        l_2500[1][4] &= (~(l_2417[6] != (1UL < ((p_5 < (((p_6 <= ((safe_add_func_int8_t_s_s((-4L), ((((((((~((1UL ^ ((safe_lshift_func_uint16_t_u_s((safe_sub_func_int16_t_s_s(l_2397, ((safe_sub_func_int32_t_s_s((safe_mod_func_uint16_t_u_u(l_2498, l_2466)), (-10L))) != 0UL))), p_8)) & l_2418)) == g_2003[3])) ^ g_1168) >= l_2418) > 1L) , p_8) , p_8) , 0x1FL) & p_4))) == 0x1FFFL)) , (-1L)) ^ 65535UL)) && l_2499))));
                        ++l_2508;
                        l_2418 &= g_59;
                        return l_2429[0];
                    }
                    else
                    {
                        return l_2371;
                    }
                }
            }
            l_2515++;
            if (p_5)
            {
                uint32_t l_2518 = 0x2412710BL;
                --l_2518;
            }
            else
            {
                uint16_t l_2528[2][10] = {{6UL, 6UL, 0UL, 0UL, 65535UL, 0UL, 0UL, 6UL, 6UL, 0UL}, {6UL, 6UL, 0UL, 0UL, 65535UL, 0UL, 0UL, 6UL, 6UL, 0UL}};
                uint32_t l_2534[6][5] = {{0x089DB86DL, 2UL, 0x089DB86DL, 2UL, 0x089DB86DL}, {0x089DB86DL, 2UL, 0x089DB86DL, 2UL, 0x089DB86DL}, {0x089DB86DL, 2UL, 0x089DB86DL, 2UL, 0x089DB86DL}, {0x089DB86DL, 2UL, 0x089DB86DL, 2UL, 0x089DB86DL}, {0x089DB86DL, 2UL, 0x089DB86DL, 2UL, 0x089DB86DL}, {0x089DB86DL, 2UL, 0x089DB86DL, 2UL, 0x089DB86DL}};
                int i, j;
                p_4 = (1UL == ((((((safe_lshift_func_int16_t_s_s(((((((((((safe_rshift_func_uint16_t_u_s((g_2254 & (safe_unary_minus_func_uint8_t_u((p_5 || ((safe_add_func_uint32_t_u_u((((l_2528[0][8] == (((+l_2429[0]) < (((safe_lshift_func_int8_t_s_s(0x1BL, 3)) < ((((safe_mod_func_uint32_t_u_u((((l_2419 == (l_2534[5][3] >= g_2470[0][0][5])) <= l_2534[1][2]) == l_2534[3][0]), 4294967290UL)) != l_2429[0]) > 1UL) <= p_6)) || 4294967286UL)) ^ 0x64L)) == 0xE152L) && g_1548[4][6][2]), l_2534[0][2])) , (-1L)))))), p_4)) & g_849[0]) || 4294967294UL) > 0x45B2L) , p_6) < 0x77B3L) && g_1368[1]) & 1L) & g_1171) & 0x24A1L), l_2534[2][4])) && l_2398[3][4]) , l_2528[1][4]) == g_2100) , l_2515) , 7L));
                for (g_100 = 0; (g_100 < 17); ++g_100)
                {
                    for (g_777 = 0; (g_777 <= 4); g_777 += 1)
                    {
                        if (l_2417[6])
                            break;
                        g_120[0] = ((safe_unary_minus_func_int32_t_s((-3L))) >= 0x8490L);
                    }
                    if (g_2470[0][0][5])
                        {
if (g_1217)
                            break;

                    continue;}
                }
            }
        }
        l_2429[0] = ((safe_add_func_uint32_t_u_u((p_4 < 0xCEDAL), (safe_add_func_int16_t_s_s((safe_unary_minus_func_uint32_t_u(0x5F6C668FL)), (+(safe_sub_func_uint32_t_u_u((l_2515 <= ((+(((safe_unary_minus_func_int32_t_s((safe_add_func_uint8_t_u_u(p_8, (safe_mod_func_int32_t_s_s((0x9434C9EBL ^ (safe_add_func_uint16_t_u_u((((g_2100 && (g_1168 < (safe_lshift_func_uint16_t_u_s((((l_2397 < 0x8FL) && p_6) < p_8), l_2429[0])))) ^ 0xE70B22DFL) == g_849[0]), 0xF98EL))), 0xFC9ABC26L)))))) && g_1540[1][0]) , 4294967292UL)) | p_4)), l_2357))))))) < 65535UL);
    }
    return l_2465;
}







static int16_t func_10(uint32_t p_11, uint8_t p_12, int32_t p_13)
{
    const int32_t l_1494 = 1L;
    int32_t l_1549 = 3L;
    int32_t l_1648 = (-7L);
    int32_t l_1651 = 0x03FC532BL;
    uint32_t l_1671 = 0x5D19C228L;
    int32_t l_1693 = 6L;
    int32_t l_1694 = 0x93E56D52L;
    int32_t l_1695 = (-8L);
    int32_t l_1696[1];
    int32_t l_1698 = 0x373FD168L;
    int16_t l_1726 = 0x18DBL;
    int8_t l_1888[4] = {(-1L), 0xDAL, (-1L), 0xDAL};
    const int32_t l_2028 = 0L;
    uint32_t l_2050 = 0xE1AEC0EFL;
    int32_t l_2055 = 0x3AFF1B97L;
    int32_t l_2141[2][9][9] = {{{(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}}, {{(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}}};
    int32_t l_2178[3];
    int16_t l_2182 = 0L;
    int32_t l_2325 = 0xDDB3E8D8L;
    uint32_t l_2326 = 4UL;
    int i, j, k;
    for (i = 0; i < 1; i++)
        { if ((!g_18) )
{

if (g_97[2])
                            break;

}
                    l_1696[i] = (-1L);}
    for (i = 0; i < 3; i++)
        l_2178[i] = 0xA248903FL;
    for (g_717 = (-17); (g_717 != (-29)); g_717--)
    {
        int32_t l_1489[4][8][8] = {{{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}, {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}, {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}, {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}};
        uint32_t l_1504 = 0x5BA9BBE8L;
        uint8_t l_1505 = 0xECL;
        int32_t l_1537 = 0L;
        int32_t l_1639 = (-1L);
        int32_t l_1644[7][7][5] = {{{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}};
        int32_t l_1705 = 0x5B922F92L;
        const int32_t l_1724 = (-1L);
        int8_t l_1725 = (-7L);
        uint16_t l_1799[5][6];
        int32_t l_1842 = 1L;
        int8_t l_1854 = 1L;
        uint32_t l_1887 = 0x40D66011L;
        uint32_t l_1905 = 5UL;
        int8_t l_1931[6] = {(-1L), (-1L), 1L, (-1L), (-1L), 1L};
        uint8_t l_2006 = 255UL;
        int i, j, k;
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 6; j++)
                { if ((((g_59 > l_1726) && (l_1549 > g_1217)) || !((l_1905 > g_1217))))
                    l_1799[i][j] = 65535UL;}
        }
        l_1489[2][4][7] |= (safe_rshift_func_uint16_t_u_s(g_694, (safe_add_func_int8_t_s_s(0x34L, 0x31L))));
                                            if (((g_101 < g_89) || (l_1698>926929256)) )
{

{
        uint8_t l_722 = 0xE0L;
        int32_t l_770 = 0x6E81370EL;
        uint32_t l_779 = 1UL;
        int32_t l_792 = 0x2E89F638L;
        if ((safe_lshift_func_int16_t_s_u((g_694 <= l_722), (safe_sub_func_int8_t_s_s(((l_1888[2] <= ((((safe_sub_func_int32_t_s_s(l_2050, (safe_mod_func_uint32_t_u_u((0x7ABE5FAFL >= ((safe_sub_func_uint8_t_u_u(g_120[1], l_722)) , ((safe_lshift_func_int8_t_s_u(l_722, (((((((safe_lshift_func_int8_t_s_s(l_2050, 3)) | l_1888[2]) || g_100) >= g_694) <= g_97[5]) , l_722) >= 4294967295UL))) == l_2182))), l_1888[2])))) >= g_694) ^ 0UL) != 8L)) ^ 0x0968FE10L), p_11)))))
        {
            uint32_t l_749 = 4294967288UL;
            if ((~(safe_add_func_uint32_t_u_u(((0L != (((l_1888[2] || (safe_sub_func_int8_t_s_s(0x65L, (safe_mod_func_uint32_t_u_u(p_11, l_722))))) ^ ((safe_add_func_uint16_t_u_u((l_1725 , (safe_lshift_func_int8_t_s_u((0xA7L & 6L), 0))), (((g_694 == l_1504) >= g_18) < l_2182))) < (-1L))) < g_694)) , 0x11329388L), 4294967295UL))))
            {
                int32_t l_769[1];
                int i;
                for (i = 0; i < 1; i++)
                    l_769[i] = 0x804970A5L;
                g_120[1] = 1L;
                if (g_694)
                    continue;
                l_749 = (safe_rshift_func_uint16_t_u_u(g_97[2], 13));
                l_770 = (safe_lshift_func_int8_t_s_s((5UL >= (0UL < (safe_add_func_int8_t_s_s((((safe_rshift_func_int16_t_s_s((g_18 != (safe_sub_func_int32_t_s_s((safe_unary_minus_func_int32_t_s((safe_mod_func_int8_t_s_s((safe_mod_func_int32_t_s_s(0x5B48709BL, ((safe_rshift_func_int16_t_s_s(g_18, g_694)) || 3L))), (safe_sub_func_int32_t_s_s(l_2182, ((((safe_rshift_func_int16_t_s_u(g_694, 7)) || g_18) || l_769[0]) <= p_11))))))), l_2050))), 6)) != g_694) != l_1725), l_722)))), p_11));
            }
            else
            {
                int16_t l_775 = (-4L);
                int32_t l_776 = (-3L);
                l_2050 = ((((l_1504 ^ (l_1888[2] , (0xB43536D7L > 0x43474B68L))) >= (((g_18 < ((safe_add_func_int8_t_s_s(l_722, 0xFAL)) & (safe_mod_func_int8_t_s_s(((((((l_775 | l_776) || l_2182) || g_100) , p_11) <= 6L) <= 0x62L), 0x36L)))) && l_1504) > 0x8EL)) != p_11) == p_11);
            }
            --l_779;
        }
        else
        {
            int16_t l_786 = 8L;
            int32_t l_789 = 2L;
            int32_t l_791 = 0xB2B08DC3L;
            uint32_t l_794 = 0x67A078F5L;
            l_1842 = (safe_rshift_func_int16_t_s_u(l_1725, 9));
            if (p_11)
                break;
            for (l_1842 = 0; (l_1842 <= (-8)); l_1842--)
            {
                return l_786;
            }
            for (l_2182 = 2; (l_2182 < 14); l_2182 = safe_add_func_uint16_t_u_u(l_2182, 3))
            {
                l_794--;
            }
        }
    }

}
                    g_120[2] = (((((((safe_add_func_int16_t_s_s((((p_12 , 0xE95DL) != ((((safe_rshift_func_uint8_t_u_s((l_1489[3][4][7] > 0x91L), 3)) & ((l_1494 >= (((safe_lshift_func_uint8_t_u_s(g_18, 5)) & (((safe_sub_func_uint16_t_u_u((l_1494 | (((safe_sub_func_uint8_t_u_u((((safe_sub_func_int8_t_s_s((((l_1489[2][4][7] == (+(((g_59 || p_12) ^ p_13) < l_1504))) > 8UL) != 4294967286UL), 0xBAL)) != p_11) , 246UL), g_1482[2][0][1])) ^ l_1504) > p_13)), g_1368[0])) ^ l_1504) <= 4294967295UL)) && 0x59L)) < l_1489[0][5][2])) , (-10L)) & 0xF980F758L)) ^ g_777), g_1171)) == 1UL) >= g_97[3]) > l_1504) > p_13) > l_1505) >= p_12);
        if (l_1494)
            { while ((!g_18) )
{

g_2100 += 1;


}
                    break;}
        for (g_1217 = (-15); (g_1217 != 6); g_1217++)
        {
            const uint32_t l_1522[6][9] = {{0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}};
            uint16_t l_1591 = 7UL;
            int32_t l_1599 = 0x10CC3626L;
            int16_t l_1633 = 0x164AL;
            int32_t l_1634 = 0x157EBADBL;
            int32_t l_1643[6][4][8] = {{{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}};
            uint32_t l_1659 = 0x83EA5D3CL;
            uint32_t l_1699 = 0x2C42C799L;
            uint16_t l_1706 = 0x0899L;
            int32_t l_1806 = 0x9CB7724BL;
            uint32_t l_1837 = 3UL;
            uint32_t l_1846 = 0xD008E7A8L;
            int i, j, k;
            if (((!(safe_add_func_int32_t_s_s((p_11 || p_11), ((((safe_lshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s((0x15L <= (g_1171 <= ((safe_add_func_uint16_t_u_u((!g_849[0]), ((((safe_sub_func_int32_t_s_s(((((p_12 , ((p_12 | ((((((safe_sub_func_uint8_t_u_u((g_1368[1] <= l_1489[2][7][0]), (-1L))) ^ g_101) | g_143) , 255UL) , p_11) < g_120[0])) < p_12)) ^ l_1494) , l_1522[4][1]) < g_540), 4294967295UL)) != 0x6AL) || g_18) >= p_11))) < l_1505))), g_100)) , 0x5997L), p_11)) <= g_100) , l_1522[0][5]) <= p_13)))) == l_1522[4][1]))
            {
                uint32_t l_1543 = 7UL;
                int32_t l_1547 = (-6L);
                int32_t l_1640 = 0x4E27C546L;
                int32_t l_1641 = 1L;
                int32_t l_1646 = 0xFBA92B18L;
                int32_t l_1647 = 0xBA2A75F3L;
                int32_t l_1649 = 0L;
                int32_t l_1650 = (-1L);
                int32_t l_1652 = (-1L);
                int32_t l_1654 = (-5L);
                int32_t l_1655 = 0L;
                int32_t l_1697 = 0L;
                for (p_11 = 5; (p_11 != 57); ++p_11)
                {
                    int32_t l_1533[2][4] = {{0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}, {0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}};
                    int32_t l_1542[8][7][3] = {{{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}};
                    int i, j, k;
                    if (((0UL <= (safe_rshift_func_int8_t_s_u(p_12, 5))) & (((((((p_13 , ((safe_add_func_int32_t_s_s(0L, (safe_mod_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((((p_13 == l_1533[1][2]) && (((p_11 && ((l_1489[3][7][5] & 0x189D8138L) & g_540)) ^ g_97[2]) | l_1505)) <= (-6L)), 12)), 0x4AL)))) & l_1505)) <= p_12) == 1L) || l_1494) | l_1494) > 0xA7L) & 1L)))
                    {
                        l_1537 &= ((safe_rshift_func_uint8_t_u_s((((p_13 ^ (~((g_97[2] == p_13) , g_1217))) | (l_1522[2][7] | (((g_89 || l_1505) , (((0x07L == (-1L)) < 0xBECEL) || l_1533[1][2])) ^ g_97[1]))) , 255UL), 1)) && (-1L));


if (g_935)
                            continue;

                    l_1547 &= p_12;

                    g_120[2] = (safe_add_func_int32_t_s_s(g_89, g_1368[1]));


p_11 += 1;


                    if (l_1806)
                            break;

                    g_120[1] = g_1540[1][0];
                    }
                    else
                    {
                        int8_t l_1541 = (-1L);
                        int32_t l_1546 = 0x3C02C0E7L;
                        uint32_t l_1550 = 1UL;

{
        for (l_1634 = 0; l_1634 < 8; l_1634++)
        {
            for (l_1697 = 0; l_1697 < 3; l_1697++)
            {
                transparent_crc(g_1548[i][l_1634][l_1697], "g_1548[i][l_1634][l_1697]", l_1641);
                if (l_1641) printf("index = [%d][%d][%d]\n", i, l_1634, l_1697);

            }
        }
    }

                    l_1543++;
                        if (l_1489[0][4][1])
                            continue;
                        --l_1550;
                    }
                    for (l_1537 = 10; (l_1537 >= 5); l_1537 = safe_sub_func_uint32_t_u_u(l_1537, 6))
                    {
                        int16_t l_1581 = 0x4CE7L;

for (l_1854 = 0; (l_1854 == 7); l_1854 = safe_add_func_uint8_t_u_u(l_1854, 6))
    {
        int16_t l_2039 = 0x0ABAL;
        const uint16_t l_2040 = 65532UL;
        int32_t l_2061 = 0x90A8BF10L;
        int32_t l_2101 = 0x02F00675L;
        int32_t l_2137 = 0L;
        int32_t l_2143[3];
        uint32_t l_2152 = 0xDB2A778AL;
        uint16_t l_2158 = 0xFEEFL;
        uint16_t l_2301 = 0xE812L;
        int i;
        for (i = 0; i < 3; i++)
            l_2143[i] = 0x4EA06463L;
        if ((safe_add_func_uint8_t_u_u(1UL, ((((1UL | ((l_2326 , ((g_849[0] , l_2039) != ((((l_2040 , (-9L)) <= 0x9EA7L) > p_12) , l_2050))) <= g_100)) == l_1888[2]) || l_1806) ^ g_935))))
        {
            uint32_t l_2062 = 4UL;
            int32_t l_2136 = 0x587994DEL;
            int32_t l_2138 = 0x39236B84L;
            int32_t l_2139 = 0x2CD995FBL;
            int32_t l_2140 = (-1L);
            int32_t l_2142 = 0x807412D1L;
            int32_t l_2146 = (-8L);
            int32_t l_2147 = (-7L);
            int32_t l_2149 = 0x0E72D148L;
            int32_t l_2151 = 0x4ECFBDFFL;
            uint8_t l_2155 = 0x86L;
            int32_t l_2176[3];
            int16_t l_2177 = 0x3603L;
            int32_t l_2179 = 1L;
            int32_t l_2180 = 1L;
            int32_t l_2181 = 0xDF8F0F9CL;
            int32_t l_2183[5] = {0x3D5D9951L, 0L, 0x3D5D9951L, 0L, 0x3D5D9951L};
            uint16_t l_2185 = 0x30E9L;
            int8_t l_2259[8] = {0xA3L, 0x43L, 0xA3L, 0x43L, 0xA3L, 0x43L, 0xA3L, 0x43L};
            int i;
            for (i = 0; i < 3; i++)
                {
if (g_777)
                        break;

                    l_2176[i] = (-1L);}
            l_2061 = (safe_rshift_func_uint8_t_u_u(((((l_2039 , (safe_mod_func_int16_t_s_s((+((safe_sub_func_uint32_t_u_u((((safe_add_func_int8_t_s_s((0x9FB88B87L <= (l_2326 && l_2028)), ((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(g_120[4], (l_1549 | p_12))), ((safe_unary_minus_func_uint32_t_u((safe_mod_func_uint8_t_u_u((((((((safe_rshift_func_uint8_t_u_u(g_120[1], 3)) ^ 0L) < l_2039) && 0L) < l_1659) & 0xF6503CF8L) > l_2050), l_2050)))) , l_1696[0]))) , l_1888[2]))) == 1UL) , l_2050), l_1537)) < 0x0C40299FL)), p_12))) || 0x6671L) && g_540) < g_540), 3));
            if ((l_2062 == 0xF331L))
            {
                uint32_t l_2075 = 0x3F7E974AL;
                int32_t l_2076 = 0xDD959D4BL;
                uint32_t l_2121 = 0xDB46FF94L;
                int32_t l_2135 = 0x8FD202FEL;
                int32_t l_2144 = 7L;
                int32_t l_2145 = 0x543A4A56L;
                int32_t l_2148 = (-7L);
                int32_t l_2150 = (-4L);
                for (g_2431 = 11; (g_2431 > 6); g_2431 = safe_sub_func_uint16_t_u_u(g_2431, 8))
                {
                    uint16_t l_2105 = 65535UL;
                    for (l_2326 = 0; (l_2326 != 38); ++l_2326)
                    {
                        k = ((p_12 < (safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((l_2050 < 0L), (l_2050 >= 0L))), (-1L)))) >= ((safe_lshift_func_uint8_t_u_u(((l_1806 || 252UL) , ((((safe_lshift_func_int8_t_s_s(l_1654, 7)) != 0L) == g_935) , g_849[0])), l_2075)) >= l_2076));
                    }
                    for (l_1549 = (-27); (l_1549 <= (-28)); l_1549--)
                    {
                        uint32_t l_2102 = 0x75F47E93L;
                        g_120[2] = (safe_sub_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((g_935 > l_2050), (safe_sub_func_uint8_t_u_u(((l_1806 & (p_12 & ((((~((((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(l_1504, (((((safe_lshift_func_int8_t_s_s(((safe_mod_func_uint8_t_u_u((((0xDFF1L > ((safe_sub_func_int8_t_s_s((((+((!(((safe_lshift_func_int16_t_s_s(0xF854L, 8)) ^ g_1482[2][1][1]) ^ g_540)) , g_120[4])) == 0UL) ^ l_1854), p_12)) , 1L)) , l_1854) | l_1931[3]), g_849[0])) || 0x4AL), p_12)) > p_12) & g_97[3]) == l_2178[1]) , 0x821DL))), l_2050)) & 0xDCA8CE5FL) <= l_2040) > l_1806)) | l_1806) , p_12) || l_1806))) , l_2076), 0x74L)))), l_1549));
                        l_2101 |= 9L;
                        l_2102 &= p_12;
                    }
                    for (l_2076 = 7; (l_2076 >= (-7)); --l_2076)
                    {
                        uint32_t l_2108 = 0xCCCFDF72L;
                        l_2105 ^= l_1806;
                        g_120[2] = (((safe_rshift_func_uint8_t_u_u((((g_1482[2][1][3] , (((l_2108 | g_120[3]) == l_2050) , ((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint8_t_u_u(((0UL && l_1931[1]) || 1UL), ((safe_sub_func_uint8_t_u_u(((((safe_sub_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((p_12 && (safe_lshift_func_uint8_t_u_s((0x24L >= 0UL), 0))), l_2050)), l_2121)) <= l_2040) & g_100) , l_2050), 1UL)) >= l_2108))) >= l_1806), 12)) >= (-1L)))) | g_97[2]) != p_12), 2)) ^ 0xB68DD604L) == 0UL);
                    }
                    l_1549 = (l_1854 != (safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s((((-1L) || 0x95L) & l_2178[1]), ((safe_lshift_func_uint8_t_u_u(255UL, 7)) >= (((((safe_unary_minus_func_uint16_t_u(1UL)) , ((((l_2050 == ((l_2105 , (safe_sub_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(g_540, g_120[1])) , l_2039), l_2062))) == p_12)) , 0x8847L) == g_935) , 0x73EDD688L)) == l_1806) , l_2062) < g_935)))), 8)));
                }
                l_2152++;
                l_2145 = ((((l_2151 , (l_2155 != p_12)) || (0xADL && 0x61L)) < l_2050) < ((safe_lshift_func_uint16_t_u_s(0xD3B9L, (2UL < ((((0x7EC0L & g_120[1]) & 4294967295UL) || 1UL) & 0x5C680109L)))) == 0xC0DAL));
            }
            else
            {
                uint32_t l_2161 = 0x817ED328L;
                l_2101 |= (7L ^ (p_12 > (((l_2158 < (p_12 & ((safe_lshift_func_uint8_t_u_u(0x2CL, 3)) || (255UL >= p_12)))) , g_1548[2][0][1]) == l_2161)));
                l_2151 = (safe_sub_func_uint32_t_u_u((l_1931[0] >= ((p_12 >= (safe_add_func_int32_t_s_s(((((((safe_add_func_int8_t_s_s(((((safe_sub_func_int8_t_s_s(l_1549, (safe_sub_func_uint16_t_u_u(0xB24EL, ((((safe_mod_func_uint32_t_u_u(l_1905, ((((safe_sub_func_int32_t_s_s((0L == l_2176[0]), (0x17L && (l_1854 , 0x38L)))) > l_1905) , 255UL) && l_1504))) || 0x8F222FB3L) || 0xC79840FEL) ^ p_12))))) < p_12) , g_2431) > g_97[5]), 7UL)) < g_120[2]) , g_120[1]) & l_2146) <= g_1217) && g_18), p_12))) && p_12)), g_100));
            }

for (g_143 = 0; (g_143 <= 8); g_143 = safe_add_func_uint8_t_u_u(g_143, 6))
            {
                const int8_t l_2199 = (-1L);
                int32_t l_2255[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_2255[i] = 0L;
                for (l_2155 = 0; (l_2155 == 34); l_2155 = safe_add_func_uint8_t_u_u(l_2155, 3))
                {
                    int16_t l_2216 = 0x83C6L;
                    int32_t l_2249 = 0xEA87154FL;
                    int32_t l_2260 = 0xF84A0E45L;
                    int32_t l_2261 = 0xC424E530L;
                    uint16_t l_2263 = 65530UL;
                    for (l_2147 = 0; (l_2147 <= (-15)); l_2147 = safe_sub_func_uint32_t_u_u(l_2147, 1))
                    {
                        const uint8_t l_2200 = 0xE4L;
                        uint16_t l_2217 = 3UL;
                        l_2178[0] = (0UL >= ((g_1368[0] != (((safe_add_func_int16_t_s_s(((+(l_2178[0] && ((((0xEEL >= l_2183[1]) && (+l_1854)) || l_1671) > (((((~(l_2142 <= (l_2199 , 0L))) >= (-1L)) <= l_2142) , l_2155) , l_2062)))) > l_1671), l_2200)) | l_2200) , l_1633)) != g_97[5]));
                        l_2183[1] = (safe_lshift_func_int8_t_s_u(((safe_mod_func_uint16_t_u_u(g_59, (((l_2040 || (safe_unary_minus_func_int8_t_s(((safe_mod_func_int16_t_s_s((0L != ((safe_sub_func_uint32_t_u_u(0xF9EC49D5L, (safe_lshift_func_uint8_t_u_s(((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(((((-8L) && (0x53L || 1L)) < (l_1633 == (((0xAC9BL > l_1671) <= l_2062) >= l_2142))) , l_2216), 2)) && 0xE90C1C13L), 2L)) , l_1633) , 0UL) , l_2325), 7)))) , g_59)), g_59)) < l_2182)))) != 0L) || l_2217))) > l_2142), 6));
                        l_2183[1] &= l_2200;
                        if (l_1854)
                            break;
                    }
                    if ((g_1482[2][1][1] & 0xDB81CA17L))
                    {
                        l_2138 = l_2178[0];
                        return l_2142;
                    }
                    else
                    {
                        if (g_59)
                            break;
                    }
                    for (l_1647 = 2; (l_1647 >= 0); l_1647 -= 1)
                    {
                        int i;
                        l_2249 &= (((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((l_2183[l_1647] > (0L || (safe_rshift_func_uint8_t_u_u(l_2178[l_1647], (((g_849[0] | (((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(l_2142, 4)), 13)) , ((safe_unary_minus_func_int8_t_s(((safe_rshift_func_int16_t_s_u(l_2183[l_1647], ((safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(g_59, 2)) , (safe_rshift_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((65535UL & ((((((((safe_mod_func_int8_t_s_s(l_2138, g_101)) , 0x3DL) == g_59) > 0xB5BB9598L) != l_1633) ^ 0L) || g_1217) <= 4294967291UL)), l_2155)) <= g_97[0]), 14))), l_2180)) != g_59) != l_2062) & 0UL), g_59)) != l_2142) || g_1217), 0x7D1913C8L)) <= g_143))) ^ 0x99L))) | g_59)) | 0x6BL)) || l_1671) & g_97[2]))))) ^ l_2178[l_1647]), l_1696[0])), 0xFB5B7956L)), 14)) < g_849[0]) , l_2199) <= l_1671), l_2061)) && l_1671) , 0x3F8D8182L);
                        l_1581 ^= (l_2178[l_1647] && ((l_1543 , (safe_sub_func_int8_t_s_s((((0x01B30B9BL ^ (1UL | (safe_sub_func_int32_t_s_s(l_2199, (((l_2183[4] , g_849[0]) ^ g_777) != l_1654))))) < 1UL) | 0x7EE96D31L), l_2155))) == l_2147));
                        l_2255[1] = (l_1671 != l_2155);
                    }
                    for (g_143 = 0; (g_143 <= 2); g_143 += 1)
                    {
                        int32_t l_2256 = 0x52D2483BL;
                        int32_t l_2257 = 1L;
                        int32_t l_2258[2][3];
                        int16_t l_2262 = 1L;
                        int i, j;
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 3; j++)
                                l_2258[i][j] = 1L;
                        }
                        l_2325 = g_1368[g_143];
                        l_2263--;
                        l_2260 &= (l_1671 == l_2142);
                        l_1647 = (safe_sub_func_int16_t_s_s(((g_1482[2][1][1] | ((5L || (g_1548[3][7][1] != (safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((0x76L & ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((g_935 & (safe_lshift_func_uint16_t_u_u(((l_1671 & (0x5EL <= ((safe_add_func_int8_t_s_s(1L, (g_1368[0] >= 0x02L))) <= l_2256))) != l_1581), 15))), l_2216)), g_1540[1][0])) < 0x866FL)) >= 0x9DEFCED1L), 0x570AL)), g_97[5])), l_2061)), l_1671)))) , l_2178[2])) ^ 0xAB2DL), 0UL));
                    }
                }
            };


                    l_2185++;
            for (l_2326 = 0; (l_2326 <= 8); l_2326 = safe_add_func_uint8_t_u_u(l_2326, 6))
            {
                const int8_t l_2199 = (-1L);
                int32_t l_2255[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_2255[i] = 0L;

{
                        l_2325 = ((0L & l_2136) != (!((safe_mod_func_uint8_t_u_u(g_59, 0x7AL)) > (((l_1905 | l_2136) , 0x1F0EL) < (l_1671 && ((((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u(g_100, l_1671)), 0x3929L)) != 0L) == 0x2F747C30L) , 0x96347F98L))))));
                    }

                    for (g_2431 = 0; (g_2431 == 34); g_2431 = safe_add_func_uint8_t_u_u(g_2431, 3))
                {
                    int16_t l_2216 = 0x83C6L;
                    int32_t l_2249 = 0xEA87154FL;
                    int32_t l_2260 = 0xF84A0E45L;
                    int32_t l_2261 = 0xC424E530L;
                    uint16_t l_2263 = 65530UL;
                    for (l_1549 = 0; (l_1549 <= (-15)); l_1549 = safe_sub_func_uint32_t_u_u(l_1549, 1))
                    {
                        const uint8_t l_2200 = 0xE4L;
                        uint16_t l_2217 = 3UL;
                        l_2143[0] = (0UL >= ((l_2178[0] != (((safe_add_func_int16_t_s_s(((+(l_2176[0] && ((((0xEEL >= g_120[1]) && (+g_100)) || l_2050) > (((((~(l_1806 <= (l_2199 , 0L))) >= (-1L)) <= l_1806) , g_2431) , l_1659)))) > l_2050), l_2200)) | l_2200) , g_935)) != g_97[5]));
                        g_120[1] = (safe_lshift_func_int8_t_s_u(((safe_mod_func_uint16_t_u_u(p_12, (((l_2040 || (safe_unary_minus_func_int8_t_s(((safe_mod_func_int16_t_s_s((0L != ((safe_sub_func_uint32_t_u_u(0xF9EC49D5L, (safe_lshift_func_uint8_t_u_s(((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(((((-8L) && (0x53L || 1L)) < (g_935 == (((0xAC9BL > l_2050) <= l_1659) >= l_1806))) , l_2216), 2)) && 0xE90C1C13L), 2L)) , g_935) , 0UL) , l_2101), 7)))) , p_12)), p_12)) < g_935)))) != 0L) || l_2217))) > l_1806), 6));
                        g_120[1] &= l_2200;
                        if (g_100)
                            break;
                    }
                    if ((g_1482[2][1][1] & 0xDB81CA17L))
                    {
                        l_2181 = l_2176[0];
                        return l_1806;
                    }
                    else
                    {
                        if (p_12)
                            break;
                    }
                    for (l_2137 = 2; (l_2137 >= 0); l_2137 -= 1)
                    {
                        int i;
                        l_2249 &= (((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((l_2183[l_2137] > (0L || (safe_rshift_func_uint8_t_u_u(l_2143[l_2137], (((g_849[0] | (((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(l_1806, 4)), 13)) , ((safe_unary_minus_func_int8_t_s(((safe_rshift_func_int16_t_s_u(l_2183[l_2137], ((safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(p_12, 2)) , (safe_rshift_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((65535UL & ((((((((safe_mod_func_int8_t_s_s(l_2181, g_540)) , 0x3DL) == p_12) > 0xB5BB9598L) != g_935) ^ 0L) || l_2158) <= 4294967291UL)), g_2431)) <= g_97[0]), 14))), l_2179)) != p_12) != l_1659) & 0UL), p_12)) != l_1806) || l_2158), 0x7D1913C8L)) <= l_2152))) ^ 0x99L))) | p_12)) | 0x6BL)) || l_2050) & g_97[2]))))) ^ l_2143[l_2137]), l_1696[0])), 0xFB5B7956L)), 14)) < g_849[0]) , l_2199) <= l_2050), l_1549)) && l_2050) , 0x3F8D8182L);
                        g_935 ^= (l_2143[l_2137] && ((l_1504 , (safe_sub_func_int8_t_s_s((((0x01B30B9BL ^ (1UL | (safe_sub_func_int32_t_s_s(l_2199, (((g_120[4] , g_849[0]) ^ l_2326) != l_2151))))) < 1UL) | 0x7EE96D31L), g_2431))) == l_1549));
                        l_2255[1] = (l_2050 != g_2431);
                    }
                    for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1)
                    {
                        int32_t l_2256 = 0x52D2483BL;
                        int32_t l_2257 = 1L;
                        int32_t l_2258[2][3];
                        int16_t l_2262 = 1L;
                        int i, j;
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 3; j++)
                                {
l_2183[1] |= (((g_849[0] <= (safe_add_func_int32_t_s_s(l_1543, l_1543))) <= ((((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u((i && ((l_1543 == l_2260) > ((safe_rshift_func_int16_t_s_u(((((((g_97[2] | g_59) && ((!((safe_rshift_func_int16_t_s_s(((0L | l_2149) , i), g_22)) ^ l_2147)) ^ 0L)) == g_59) , 1L) || 0xE5L) <= l_1505), 15)) || l_2260))), 3)) > l_1633) ^ l_1543), g_777)) ^ l_2178[1]) || 1L) != (-5L)) , 4294967290UL) <= l_1543)) ^ 0x02D0829CL);

                    l_2258[i][j] = 1L;}
                        }
                        l_2101 = l_2178[l_2152];
                        l_2263--;
                        l_2260 &= (l_2050 == l_1806);
                        l_1549 = (safe_sub_func_int16_t_s_s(((g_1482[2][1][1] | ((5L || (g_1548[3][7][1] != (safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((0x76L & ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((l_2039 & (safe_lshift_func_uint16_t_u_u(((l_2050 & (0x5EL <= ((safe_add_func_int8_t_s_s(1L, (l_2178[0] >= 0x02L))) <= l_2256))) != g_935), 15))), l_2216)), g_1540[1][0])) < 0x866FL)) >= 0x9DEFCED1L), 0x570AL)), g_97[5])), l_1549)), l_2050)))) , l_2143[2])) ^ 0xAB2DL), 0UL));
                    }
                }
            }
        }
        else
        {
            int32_t l_2300[5][8] = {{0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}};
            int32_t l_2321 = (-1L);
            uint32_t l_2322 = 0x99FED06DL;
            int i, j;
            for (l_2158 = 0; (l_2158 <= 2); l_2158 += 1)
            {
                g_120[1] = (safe_sub_func_int32_t_s_s(l_1549, 0x8EEC641FL));
                for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1)
                {
                    const int16_t l_2298 = 0x7AB4L;
                    if (l_1806)
                    {
                        int8_t l_2299 = 0xA2L;
                        g_120[4] = (safe_sub_func_uint32_t_u_u(g_2184[2][0], g_935));
                        g_120[1] = ((safe_rshift_func_int8_t_s_u(l_1806, ((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((0x9CD8L && ((l_2050 != (1UL & (p_12 , (safe_lshift_func_uint16_t_u_u((((l_1806 == (0x32DBL >= (0x73E61AD3L < l_2298))) || l_1854) >= l_2299), 4))))) >= 65535UL)), l_1659)), l_1806)) && 0x6D137FB0L))) && 7L);
                        l_2301--;
                        l_1537 = ((((safe_add_func_uint8_t_u_u(0x92L, l_2152)) & (((((((safe_lshift_func_int16_t_s_u((((l_2300[3][1] & ((safe_rshift_func_uint8_t_u_u(247UL, (safe_mod_func_uint8_t_u_u(1UL, (safe_mul_func_int16_t_s_s((+l_1659), (g_1548[7][6][1] >= (safe_lshift_func_int8_t_s_u(g_540, 0))))))))) || ((safe_sub_func_int32_t_s_s((((safe_lshift_func_int16_t_s_u((-1L), 11)) == 0x5DL) | l_2299), 4294967295UL)) , l_2300[4][1]))) <= g_2184[2][0]) | l_2300[3][6]), 14)) , (-7L)) , l_1806) != 0x6C7C71DBL) , g_18) , g_1548[4][6][2]) | g_2184[2][1])) == l_2141[1][6][5]) > p_12);
                    }
                    else
                    {
                        return l_2050;
                    }
                }
                ++l_2322;
            }
        }
    }
g_89 -= 1;


                    ;


                    if (p_11)
                            {
g_2003[0] |= (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u(g_1482[0][1][0], ((~((((-6L) < l_2326) >= g_120[1]) | (l_2326 , l_2326))) != (((safe_lshift_func_uint16_t_u_s(((g_1548[4][6][2] || ((((safe_rshift_func_int8_t_s_s(1L, 4)) <= 0xC812E52FL) || g_1368[1]) <= 0UL)) , l_1888[1]), 3)) != l_1652) < 65535UL)))) | g_1482[2][1][1]) <= 4294967292UL) && k) > l_1854), g_849[0])), l_1505));

                    break;}

for (g_89 = 6; (g_89 >= 1); g_89 -= 1)
                    {
                        int i;
                        l_1806 = (safe_mod_func_int32_t_s_s(g_97[g_89], p_12));
                        g_100 = g_18;

l_1505 += 1;


                    l_1581 &= 0xEC293C97L;
                    };


                    g_120[1] = (l_1549 || (0xA427L == (safe_mod_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((g_1368[1] == 1UL), (-1L))), 0x2E3AL))));

for (g_717 = 0; (g_717 >= 7); g_717 = safe_add_func_uint8_t_u_u(g_717, 3))
                    {
                        return g_2254;
                    };


                    g_120[1] = ((+(p_12 < ((((((safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((~g_101), ((safe_lshift_func_int8_t_s_s(l_1547, (safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((+((safe_add_func_int8_t_s_s((0UL != (((safe_rshift_func_int8_t_s_u((g_89 > g_1368[2]), 1)) == (safe_unary_minus_func_int8_t_s((p_11 , (safe_rshift_func_uint8_t_u_s((((safe_mod_func_int8_t_s_s((0x71L >= l_1581), 0xB6L)) , p_11) <= p_13), 3)))))) && g_777)), 0UL)) ^ l_1522[0][5])) & 1UL), p_11)), 13)))) , 0x89L))), p_12)) != l_1537) , g_1217) || 65531UL) > p_13) < 0x33D41A9EL))) , g_59);
                    }
                    for (g_540 = 0; (g_540 <= 4); g_540 += 1)
                    {
                        int16_t l_1588[5][10][5] = {{{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}};
                        const int16_t l_1592 = (-1L);
                        int i, j, k;
                        g_120[g_540] = ((safe_sub_func_int32_t_s_s(g_101, 0xC58F4B07L)) ^ ((((((-1L) > (((((safe_add_func_int8_t_s_s(((((safe_sub_func_uint32_t_u_u(((l_1588[4][3][4] | (0xBBL | g_97[2])) ^ l_1542[2][5][1]), (p_12 , (safe_lshift_func_uint16_t_u_u(((0x8B2D6D5DL < (-6L)) < 0x8664AFBBL), 8))))) & p_11) > 7L) >= l_1591), l_1588[1][8][4])) && p_11) == 1UL) , l_1592) && g_97[2])) || g_717) <= p_11) || g_1217) >= l_1533[1][2]));
                        return l_1549;
                    }
                }
                if ((((safe_rshift_func_uint8_t_u_s(l_1549, 4)) >= (safe_lshift_func_uint8_t_u_s(l_1591, (safe_lshift_func_int8_t_s_s(l_1599, 1))))) != ((safe_lshift_func_int16_t_s_u((!(((p_12 >= l_1547) , ((!g_849[0]) >= ((g_89 <= (!(((safe_rshift_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_u((((g_540 > 0L) ^ p_13) < l_1504), p_12)) || 0x729EL) > 0xD46FL), 2)) < g_97[2]) , 6UL))) || p_12))) | l_1489[2][4][7])), 12)) == p_12)))
                {
                    uint16_t l_1611 = 0xD966L;
                    int32_t l_1636 = 1L;
                    int32_t l_1638[4][6][7] = {{{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}};
                    uint8_t l_1656[3][8][6] = {{{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}};
                    int i, j, k;
                    g_120[1] = ((((p_11 & ((safe_mul_func_uint8_t_u_u(l_1611, ((((l_1494 | (safe_mod_func_int8_t_s_s(p_13, (safe_lshift_func_uint16_t_u_u((((((((+(l_1494 , ((l_1504 & (safe_lshift_func_uint16_t_u_s((((+(((((((g_694 <= (((((p_13 & ((0x4BA9L | 0xAB14L) == 0xB0E53EB1L)) == 0x49L) >= g_1168) && p_13) < l_1611)) > 0x891AL) ^ 0xC4L) >= g_22) > l_1599) ^ g_849[0]) < l_1591)) & 0x2C1DL) >= 0L), 14))) , g_1168))) & g_101) != 0x3AL) , p_12) && g_717) ^ p_13) >= p_12), 1))))) && p_11) >= l_1522[4][1]) <= 0x012802EEL))) ^ 0x6FL)) | p_12) != 4294967290UL) | g_120[4]);

if ((safe_lshift_func_int8_t_s_s(0xBCL, 7)))
            {
                int8_t l_1831 = (-6L);
                int32_t l_1849[6] = {(-1L), 6L, (-1L), 6L, (-1L), 6L};
                const uint8_t l_1889 = 252UL;
                int i;

for (p_13 = 0; p_13 < 3; p_13++)
        g_1368[p_13] = 0xA248903FL;

                    for (l_1611 = 0; (l_1611 >= 36); l_1611 = safe_add_func_uint32_t_u_u(l_1611, 3))
                {
                    int32_t l_1836[9][5] = {{(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}};
                    int32_t l_1841 = (-3L);
                    int32_t l_1844 = 8L;
                    int32_t l_1845 = 0xBE0388A2L;
                    int16_t l_1853 = 0xBF53L;
                    uint16_t l_1856 = 0x14A1L;
                    int i, j;
                    g_120[4] ^= (((safe_add_func_uint32_t_u_u((0x22L == (((((k , (((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((~((((((g_1368[2] >= ((0xEF5AL != (safe_sub_func_int8_t_s_s(((g_1482[2][1][1] && ((safe_add_func_int8_t_s_s((((safe_sub_func_uint16_t_u_u(((((l_1831 | (((l_1505 > g_1540[1][0]) >= (((safe_rshift_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((g_1368[2] > 0x5C49CB64L), 5)) | l_1831) , l_1836[4][3]) == g_1368[1]) && g_59), g_101)) >= 0x624C7317L) == l_1647)) <= l_1505)) , l_1505) , 1UL) , g_849[0]), 0xF010L)) ^ 0UL) <= g_849[0]), g_101)) > 1L)) & l_1654), l_1647))) == 0xE4B6B42FL)) | l_1799[2][5]) , 0L) >= l_1611) & g_22) , l_1489[0][3][5])), 10)), l_1659)) == g_97[2]) >= l_1659)) || l_1726) , l_1831) == l_1647) ^ g_849[0])), l_1505)) | g_2467) , l_1724);
                    for (l_1505 = 13; (l_1505 >= 1); l_1505 = safe_sub_func_int32_t_s_s(l_1505, 9))
                    {
                        uint8_t l_1840 = 0x4FL;
                        int32_t l_1843 = 1L;
                        int32_t l_1850 = (-10L);
                        int32_t l_1851 = 0x86429966L;
                        int32_t l_1852 = 0xCA3D88B8L;
                        int32_t l_1855 = 1L;
                        l_1840 = l_1611;

for (k = 10; (k >= 5); k = safe_sub_func_uint32_t_u_u(k, 6))
                    {
                        int16_t l_1581 = 0x4CE7L;
                        if (p_11)
                            break;
                        g_120[1] = (g_2469 || (0xA427L == (safe_mod_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((l_2178[1] == 1UL), (-1L))), 0x2E3AL))));
                        g_120[1] = ((+(p_12 < ((((((safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((~l_1633), ((safe_lshift_func_int8_t_s_s(l_1652, (safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((+((safe_add_func_int8_t_s_s((0UL != (((safe_rshift_func_int8_t_s_u((g_717 > l_2178[2]), 1)) == (safe_unary_minus_func_int8_t_s((p_11 , (safe_rshift_func_uint8_t_u_s((((safe_mod_func_int8_t_s_s((0x71L >= l_1581), 0xB6L)) , p_11) <= j), 3)))))) && l_1659)), 0UL)) ^ l_1522[0][5])) & 1UL), p_11)), 13)))) , 0x89L))), p_12)) != k) , l_1611) || 65531UL) > j) < 0x33D41A9EL))) , l_1840);
                    };


                    --l_1846;
                        --l_1856;
                    }

{
                        l_1648 = l_1651;
                    }


{
        transparent_crc(g_97[l_1806], "g_97[l_1806]", i);
        if (i) printf("index = [%d]\n", l_1806);

    }

                    for (l_1841 = (-19); (l_1841 != (-8)); l_1841++)
                    {
                        uint16_t l_1886[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_1886[i] = 7UL;
                        g_120[1] &= l_1696[0];
                        g_120[0] = (((((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u(65535UL, 13)) , 0x9426L), (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_u(l_1647, (((((0xEF2D849BL || l_1591) & (l_1841 , (safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u((((((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s(g_1168, (safe_rshift_func_uint16_t_u_s((((l_1799[1][5] > (safe_add_func_uint16_t_u_u(0x2E1AL, 0xBDC1L))) >= l_1836[0][4]) == l_1886[0]), 13)))) | (-2L)), g_2467)) & l_1505) < 0xBEL) < g_2467) & l_1888[2]), 0x66L)), l_1659)), 4)), 7)), 0UL)))) , 1UL) ^ l_1889) == 0xEAL))))))) > 0x483D69BBL) , l_1844) , 247UL) ^ l_1611);
                        l_1644[0][3][4] = ((((-2L) == (safe_add_func_uint16_t_u_u((((((((((safe_add_func_int32_t_s_s(((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s((safe_mod_func_int8_t_s_s((251UL != ((!g_2467) == (((g_97[1] | (safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s(0xF54AL, 2)) && ((((l_1659 > ((((l_1853 & (safe_add_func_uint16_t_u_u(0x3ED4L, 1L))) ^ l_1647) | 1L) ^ l_1849[1])) > (-1L)) && l_1726) != 0UL)), 0xEB10B25CL)), 10))) < g_1482[2][1][1]) || 0x405D3F2AL))), l_2055)), 1)), 2)) && l_1611), 5)) && 4294967295UL), 4294967293UL)) , l_1647), 4294967288UL)) | l_1505) || l_1505) && l_1695) && l_1647) && 0x068C0922L) , l_1505) , (-1L)) < l_1659), 1UL))) ^ l_1846) || g_22);
                        j = (safe_lshift_func_uint8_t_u_s(l_1505, ((safe_rshift_func_int8_t_s_s(9L, g_101)) != l_1846)));
                    }
                }

{
        transparent_crc(g_1368[l_1649], "g_1368[l_1649]", g_2100);
        if (g_2100) printf("index = [%d]\n", l_1649);

    }

                    g_120[1] ^= ((l_1505 & (0x8889L >= (l_1647 == ((safe_unary_minus_func_uint8_t_u(0UL)) <= (safe_mod_func_int16_t_s_s(g_1482[3][0][1], ((l_1647 > (((~l_1659) && ((~(!((((safe_sub_func_uint16_t_u_u((((((((l_1505 < ((((l_1647 , l_1647) >= 0x93L) , 1UL) ^ g_89)) ^ l_1659) == l_1889) & 0UL) , g_717) < l_1799[4][4]) < 4294967295UL), l_1849[0])) <= 1L) , l_1505) , 0x3CL))) , l_1659)) >= 7L)) & k))))))) | l_1831);
                l_1643[0][3][1] = (l_1505 > 0x5B7FL);
            }
            else
            {
                uint32_t l_1932 = 1UL;
                int32_t l_1945 = 0L;
                int32_t l_1946[1];
                uint32_t l_1971 = 0x9EF11B35L;
                uint8_t l_1990 = 0xB6L;
                int i;

l_1693 += 1;


                    for (i = 0; i < 1; i++)
                    {

{
                        int i;
                        return g_120[l_2006];
                    }

                    l_1699 |= 0x10DDF4F3L;

                    l_1946[i] = 3L;}
                for (l_1726 = (-11); (l_1726 < (-24)); --l_1726)
                {
                    int32_t l_1929 = 0L;
                    int32_t l_1930 = 0x01C56913L;
                    uint8_t l_1949 = 0xBEL;
                    int32_t l_2005 = 0L;

for (g_89 = 6; (g_89 >= 1); g_89 -= 1)
                    {
                        int i;
                        j = (safe_mod_func_int32_t_s_s(g_97[g_89], l_1949));
                        l_1854 = g_18;
                        l_2182 &= 0xEC293C97L;
                    };


                    if (l_1505)
                    {
                        int32_t l_1928[10] = {0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L};
                        int i;
                        l_1932--;
                    }
                    else
                    {

g_120[1] ^= ((0L & 0x37L) >= (safe_sub_func_uint16_t_u_u(1UL, ((((safe_lshift_func_int8_t_s_u((g_97[3] >= (safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s(((((((safe_lshift_func_uint16_t_u_s(((((0xC0653759L ^ l_2005) , l_1591) == (l_1648 != l_2055)) , 1UL), l_2055)) , 4L) , g_2467) || 0x464EEE5AL) | 8UL) & g_540), 5)) , 0x83F7DA68L) && g_18), 1UL))), 5)) <= l_1949) < 65531UL) || l_2050))));

                    j = l_1647;
                    }
                    if ((l_1505 , l_1694))
                    {
                        int8_t l_1947 = 0x1BL;
                        int32_t l_1948 = 0x27F08C10L;
                        l_1945 = (((0x03L == (0xA11DL < (g_59 | ((((0x6F1BL != l_1633) < (((((((((safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(g_97[2], l_1505)), 2)) > (safe_add_func_uint16_t_u_u(g_1548[4][6][2], 0x34DEL))) & l_1659), l_1611)) , 0x3208L) , g_1540[1][0]) , l_1930) == l_1726) , g_1548[0][0][1]) <= l_1932) > l_1659) >= 0UL)) < l_1659) >= l_1647)))) ^ g_97[2]) , g_849[0]);
                        ++l_1949;
                        g_120[4] = (safe_mod_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(6L, (safe_sub_func_uint8_t_u_u(0x94L, (((l_1949 | (safe_rshift_func_int8_t_s_u(((((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((((+(safe_add_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(((0xB3EFL || (l_1947 | (((g_120[1] ^ ((((-2L) & (((l_1659 ^ (l_1945 , 0x78L)) , l_1971) < l_1647)) < 0xA9FBL) == l_1647)) < l_1694) < 0xE1L))) && l_1948), 0x64L)) , l_1647), 9UL))) >= 0x60B3L) != l_1647) ^ l_1647), l_1505)), 0x0DAEL)), g_2467)) >= l_1947) > l_1647) == l_1659), l_1948))) , 5L) | 0xB082A17BL))))) , 0x11L), 0x03L));
                    }
                    else
                    {
                        l_1930 = ((0L & l_1647) != (!((safe_mod_func_uint8_t_u_u(l_1505, 0x7AL)) > (((l_1932 | l_1647) , 0x1F0EL) < (l_1659 && ((((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u(l_1725, l_1659)), 0x3929L)) != 0L) == 0x2F747C30L) , 0x96347F98L))))));
                    }
                    if (((safe_lshift_func_uint16_t_u_s((g_1540[1][0] , l_1930), l_1659)) & (((l_1633 < (((((safe_lshift_func_int16_t_s_u(((l_1647 , ((l_1659 && (((safe_unary_minus_func_int16_t_s(((safe_add_func_uint16_t_u_u(j, ((((safe_add_func_uint16_t_u_u((l_1591 ^ l_1647), l_1990)) < l_1659) < 0x1D1DL) | g_101))) | g_120[1]))) , l_1647) && l_1643[1][1][6])) ^ g_717)) , l_1647), l_2055)) | l_1659) <= 0UL) != (-8L)) , l_1647)) < l_1654) || 0x837FL)))
                    {
                        int8_t l_2002 = 0x5BL;
                        int32_t l_2004[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            {
for (l_1945 = 0; l_1945 < 3; l_1945++)
        {
            for (l_2325 = 0; l_2325 < 4; l_2325++)
            {
                transparent_crc(g_1482[l_1648][l_1945][l_2325], "g_1482[l_1648][l_1945][l_2325]", l_1599);
                if (l_1599) printf("index = [%d][%d][%d]\n", l_1648, l_1945, l_2325);

            }
        };



{
                        int32_t l_2256 = 0x52D2483BL;
                        int32_t l_2257 = 1L;
                        int32_t l_2258[2][3];
                        int16_t l_2262 = 1L;
                        int i, j;
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 3; j++)
                                l_2258[i][j] = 1L;
                        }
                        l_1705 = l_2178[l_1699];
                        l_1611--;
                        g_2469 &= (l_1671 == l_1698);
                        l_1549 = (safe_sub_func_int16_t_s_s(((g_1482[2][1][1] | ((5L || (g_1548[3][7][1] != (safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((0x76L & ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((g_694 & (safe_lshift_func_uint16_t_u_u(((l_1671 & (0x5EL <= ((safe_add_func_int8_t_s_s(1L, (l_2178[0] >= 0x02L))) <= l_2256))) != g_694), 15))), g_694)), g_1540[1][0])) < 0x866FL)) >= 0x9DEFCED1L), 0x570AL)), g_97[5])), l_1693)), l_1671)))) , g_1368[2])) ^ 0xAB2DL), 0UL));
                    }

                    l_2004[i] = 7L;}
                        g_2003[0] |= (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u(g_1482[0][1][0], ((~((((-6L) < l_1659) >= g_120[1]) | (l_1659 , l_1659))) != (((safe_lshift_func_uint16_t_u_s(((g_1548[4][6][2] || ((((safe_rshift_func_int8_t_s_s(1L, 4)) <= 0xC812E52FL) || g_1368[1]) <= 0UL)) , l_1888[1]), 3)) != l_1647) < 65535UL)))) | g_1482[2][1][1]) <= 4294967292UL) && l_1929) > l_2002), g_849[0])), l_1505));
                        g_2431--;
                        if (l_1888[1])
                            {
l_1726 &= 0xEC293C97L;

                    break;}
                    }
                    else
                    {
                        uint8_t l_2013[2][2] = {{1UL, 0x0EL}, {1UL, 0x0EL}};
                        int i, j;
                        g_120[1] = (safe_rshift_func_int16_t_s_u((((safe_sub_func_uint8_t_u_u((0xBC96E130L > l_2013[1][0]), ((safe_add_func_uint8_t_u_u(((l_2005 >= (((safe_add_func_uint8_t_u_u((((g_89 & l_2013[0][1]) , ((safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(g_1548[4][6][2], l_1932)) , ((safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((l_1659 ^ ((safe_mod_func_uint16_t_u_u((65534UL <= l_1650), l_1659)) , g_120[3])) || l_1591), g_97[1])) > g_22), (-4L))) > 7L)), l_1949)) == l_1888[2])) < l_1505), 9UL)) | g_1368[1]) & l_1695)) <= l_1930), 0x27L)) & 9UL))) && l_1505) , 0x1E18L), g_18));
                    }
                    g_120[1] = ((((0UL == (0x99L == g_1482[2][1][1])) , l_2028) , g_97[2]) > ((g_120[3] > ((((((safe_lshift_func_uint16_t_u_s(((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s(((0x83922D4EL != ((-8L) > 0x08L)) || l_1547), 5)), g_1168)) >= l_1547), 15)) < l_1647) , 0xAC9FE61AL) , l_1647) > l_1659) | g_1540[1][0])) ^ (-1L)));
                }
            };



if (g_2470[0][0][5])
                        continue;

                    if ((l_1489[2][4][7] <= (g_97[0] <= l_1494)))
                    {
                        int32_t l_1635 = 0L;
                        int32_t l_1637 = 1L;
                        int32_t l_1642 = (-3L);
                        int32_t l_1645[4][10][3] = {{{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}};
                        int8_t l_1653 = 0xE0L;
                        int i, j, k;

g_120[1] &= l_1696[0];

                    l_1634 = (((((safe_mod_func_uint16_t_u_u((safe_unary_minus_func_uint8_t_u((safe_sub_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((p_13 ^ (((((safe_mod_func_uint8_t_u_u(((((safe_add_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(((p_11 && (((p_12 , l_1494) > (p_13 & g_1168)) >= (-2L))) == ((-1L) & ((0x2C2C4A06L || 0L) != g_100))), 0x84D0E611L)) < 247UL), l_1537)) == g_1540[0][1]) != 65535UL) != (-5L)), l_1599)) , g_777) , l_1611) == p_12) && 9L)) >= 0x3E95L), p_13)), p_11)))), 65530UL)) >= l_1549) | 0xA236F820L) , l_1611) < l_1633);

{
            const uint32_t l_1522[6][9] = {{0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}};
            uint16_t l_1591 = 7UL;
            int32_t l_1599 = 0x10CC3626L;
            int16_t l_1633 = 0x164AL;
            int32_t l_1634 = 0x157EBADBL;
            int32_t l_1643[6][4][8] = {{{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}};
            uint32_t l_1659 = 0x83EA5D3CL;
            uint32_t l_1699 = 0x2C42C799L;
            uint16_t l_1706 = 0x0899L;
            int32_t l_1806 = 0x9CB7724BL;
            uint32_t l_1837 = 3UL;
            uint32_t l_1846 = 0xD008E7A8L;
            int i, j, k;
            if (((!(safe_add_func_int32_t_s_s((l_1699 || l_1699), ((((safe_lshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s((0x15L <= (g_1171 <= ((safe_add_func_uint16_t_u_u((!g_849[0]), ((((safe_sub_func_int32_t_s_s(((((g_1171 , ((g_1171 | ((((((safe_sub_func_uint8_t_u_u((l_2178[1] <= l_1489[2][7][0]), (-1L))) ^ g_2254) | l_2050) , 255UL) , l_1699) < g_120[0])) < g_1171)) ^ g_2468) , l_1522[4][1]) < g_101), 4294967295UL)) != 0x6AL) || g_18) >= l_1699))) < g_1171))), g_100)) , 0x5997L), l_1699)) <= g_100) , l_1522[0][5]) <= l_2325)))) == l_1522[4][1]))
            {
                uint32_t l_1543 = 7UL;
                int32_t l_1547 = (-6L);
                int32_t l_1640 = 0x4E27C546L;
                int32_t l_1641 = 1L;
                int32_t l_1646 = 0xFBA92B18L;
                int32_t l_1647 = 0xBA2A75F3L;
                int32_t l_1649 = 0L;
                int32_t l_1650 = (-1L);
                int32_t l_1652 = (-1L);
                int32_t l_1654 = (-5L);
                int32_t l_1655 = 0L;
                int32_t l_1697 = 0L;
                for (l_1699 = 5; (l_1699 != 57); ++l_1699)
                {
                    int32_t l_1533[2][4] = {{0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}, {0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}};
                    int32_t l_1542[8][7][3] = {{{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}};
                    int i, j, k;
                    if (((0UL <= (safe_rshift_func_int8_t_s_u(g_1171, 5))) & (((((((l_2325 , ((safe_add_func_int32_t_s_s(0L, (safe_mod_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((((l_2325 == l_1533[1][2]) && (((l_1699 && ((l_1489[3][7][5] & 0x189D8138L) & g_101)) ^ g_97[2]) | g_1171)) <= (-6L)), 12)), 0x4AL)))) & g_1171)) <= g_1171) == 1L) || g_2468) | g_2468) > 0xA7L) & 1L)))
                    {
                        l_1806 &= ((safe_rshift_func_uint8_t_u_s((((l_2325 ^ (~((g_97[2] == l_2325) , l_1611))) | (l_1522[2][7] | (((g_717 || g_1171) , (((0x07L == (-1L)) < 0xBECEL) || l_1533[1][2])) ^ g_97[1]))) , 255UL), 1)) && (-1L));
                        g_120[2] = (safe_add_func_int32_t_s_s(g_717, l_2178[1]));
                        g_120[1] = g_1540[1][0];
                    }
                    else
                    {
                        int8_t l_1541 = (-1L);
                        int32_t l_1546 = 0x3C02C0E7L;
                        uint32_t l_1550 = 1UL;
                        l_1543++;
                        if (l_1489[0][4][1])
                            continue;
                        --l_1550;
                    }
                    for (l_1806 = 10; (l_1806 >= 5); l_1806 = safe_sub_func_uint32_t_u_u(l_1806, 6))
                    {
                        int16_t l_1581 = 0x4CE7L;
                        if (l_1699)
                            break;
                        g_120[1] = (g_2100 || (0xA427L == (safe_mod_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((l_2178[1] == 1UL), (-1L))), 0x2E3AL))));
                        g_120[1] = ((+(g_1171 < ((((((safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((~g_2254), ((safe_lshift_func_int8_t_s_s(l_1547, (safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((+((safe_add_func_int8_t_s_s((0UL != (((safe_rshift_func_int8_t_s_u((g_717 > l_2178[2]), 1)) == (safe_unary_minus_func_int8_t_s((l_1699 , (safe_rshift_func_uint8_t_u_s((((safe_mod_func_int8_t_s_s((0x71L >= l_1581), 0xB6L)) , l_1699) <= l_2325), 3)))))) && l_2050)), 0UL)) ^ l_1522[0][5])) & 1UL), l_1699)), 13)))) , 0x89L))), g_1171)) != l_1806) , l_1611) || 65531UL) > l_2325) < 0x33D41A9EL))) , g_2431);
                    }
                    for (g_101 = 0; (g_101 <= 4); g_101 += 1)
                    {
                        int16_t l_1588[5][10][5] = {{{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}};
                        const int16_t l_1592 = (-1L);
                        int i, j, k;
                        g_120[g_101] = ((safe_sub_func_int32_t_s_s(g_2254, 0xC58F4B07L)) ^ ((((((-1L) > (((((safe_add_func_int8_t_s_s(((((safe_sub_func_uint32_t_u_u(((l_1588[4][3][4] | (0xBBL | g_97[2])) ^ l_1542[2][5][1]), (g_1171 , (safe_lshift_func_uint16_t_u_u(((0x8B2D6D5DL < (-6L)) < 0x8664AFBBL), 8))))) & l_1699) > 7L) >= l_1591), l_1588[1][8][4])) && l_1699) == 1UL) , l_1592) && g_97[2])) || g_717) <= l_1699) || l_1611) >= l_1533[1][2]));
                        return g_2100;
                    }
                }
                if ((((safe_rshift_func_uint8_t_u_s(g_2100, 4)) >= (safe_lshift_func_uint8_t_u_s(l_1591, (safe_lshift_func_int8_t_s_s(l_1599, 1))))) != ((safe_lshift_func_int16_t_s_u((!(((g_1171 >= l_1547) , ((!g_849[0]) >= ((g_717 <= (!(((safe_rshift_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_u((((g_101 > 0L) ^ l_2325) < l_2050), g_1171)) || 0x729EL) > 0xD46FL), 2)) < g_97[2]) , 6UL))) || g_1171))) | l_1489[2][4][7])), 12)) == g_1171)))
                {
                    uint16_t l_1611 = 0xD966L;
                    int32_t l_1636 = 1L;
                    int32_t l_1638[4][6][7] = {{{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}};
                    uint8_t l_1656[3][8][6] = {{{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}};
                    int i, j, k;
                    g_120[1] = ((((l_1699 & ((safe_mul_func_uint8_t_u_u(l_1611, ((((g_2468 | (safe_mod_func_int8_t_s_s(l_2325, (safe_lshift_func_uint16_t_u_u((((((((+(g_2468 , ((l_2050 & (safe_lshift_func_uint16_t_u_s((((+(((((((l_1633 <= (((((l_2325 & ((0x4BA9L | 0xAB14L) == 0xB0E53EB1L)) == 0x49L) >= l_2050) && l_2325) < l_1611)) > 0x891AL) ^ 0xC4L) >= l_1699) > l_1599) ^ g_849[0]) < l_1591)) & 0x2C1DL) >= 0L), 14))) , l_2050))) & g_2254) != 0x3AL) , g_1171) && g_717) ^ l_2325) >= g_1171), 1))))) && l_1699) >= l_1522[4][1]) <= 0x012802EEL))) ^ 0x6FL)) | g_1171) != 4294967290UL) | g_120[4]);
                    if ((l_1489[2][4][7] <= (g_97[0] <= g_2468)))
                    {
                        int32_t l_1635 = 0L;
                        int32_t l_1637 = 1L;
                        int32_t l_1642 = (-3L);
                        int32_t l_1645[4][10][3] = {{{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}};
                        int8_t l_1653 = 0xE0L;
                        int i, j, k;
                        l_1634 = (((((safe_mod_func_uint16_t_u_u((safe_unary_minus_func_uint8_t_u((safe_sub_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((l_2325 ^ (((((safe_mod_func_uint8_t_u_u(((((safe_add_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(((l_1699 && (((g_1171 , g_2468) > (l_2325 & l_2050)) >= (-2L))) == ((-1L) & ((0x2C2C4A06L || 0L) != g_100))), 0x84D0E611L)) < 247UL), l_1806)) == g_1540[0][1]) != 65535UL) != (-5L)), l_1599)) , l_2050) , l_1611) == g_1171) && 9L)) >= 0x3E95L), l_2325)), l_1699)))), 65530UL)) >= g_2100) | 0xA236F820L) , l_1611) < l_1633);
                        l_1656[1][6][4]++;
                        ++l_1659;
                    }
                    else
                    {
                        int32_t l_1692 = 1L;
                        l_1504 = (((safe_mod_func_uint16_t_u_u((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u((((l_1640 , ((((l_1633 != l_1611) >= (safe_sub_func_uint8_t_u_u(0xEEL, g_849[0]))) <= l_2050) != (1UL & g_1171))) && (!(l_1640 >= l_1644[2][1][0]))) || l_1641), (-2L))), 1UL)), g_120[1])) > 0x1BL) | 0xC3L);
                        g_120[1] = (+1UL);
                        l_1643[3][1][5] = (safe_add_func_uint32_t_u_u(0UL, (((safe_rshift_func_uint16_t_u_u(((safe_mod_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((~l_2325), ((0x60L ^ ((l_1640 == ((((((-1L) == ((0x4B8FL == (g_1171 | (((6L | (safe_rshift_func_uint16_t_u_u(((((((((safe_lshift_func_int8_t_s_u(((~(((((safe_mod_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(((!(1UL != g_717)) > l_1522[2][7]), g_120[1])), l_1638[0][0][2])) < 4294967295UL) , l_1699) , 0xE3L) , 0x49L)) && 0x109AL), 6)) , g_101) || 4294967288UL) < 0x758ECAE5L) , l_1699) > l_1692) != g_120[4]) == 0x90143625L), g_120[0]))) != g_1171) | g_18))) | (-1L))) > l_1699) > l_1633) , l_1699) != l_1699)) < l_1692)) < g_18))), g_1171)) | 0x4510FC82L), l_1699)) > 2UL) != l_1643[0][3][1])));
                    }
                }
                else
                {
                    g_120[4] = l_1699;
                    if (l_1504)
                        break;
                }
                ++l_1699;
            }
            else
            {
                int8_t l_1702[4] = {0x92L, 1L, 0x92L, 1L};
                int32_t l_1703 = (-7L);
                int32_t l_1704[7][6][6] = {{{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}};
                uint8_t l_1730[3][2];
                uint32_t l_1764 = 0x54F33472L;
                int i, j, k;
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 2; j++)
                        l_1730[i][j] = 0x7BL;
                }
                g_120[2] = g_1548[4][6][2];
                --l_1706;
                if ((((g_100 < ((safe_sub_func_int8_t_s_s(g_1540[1][0], (((((((1L | (l_1643[4][0][3] != ((safe_sub_func_int16_t_s_s(((safe_sub_func_int32_t_s_s(g_1548[9][3][2], (((((safe_add_func_uint16_t_u_u((!l_1699), g_120[0])) != ((safe_sub_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u((0UL != ((g_1171 > g_2100) , l_1504)), 6)), l_1703)), l_1724)) < 255UL)) , l_1806) == l_1653) < l_1489[2][4][7]))) > g_101), (-10L))) == l_2325))) , 0x853A9528L) != 1UL) , l_1706) >= 0x1C39L) == 0xF5678FABL) , 0xD3L))) < 0x7EB415D5L)) != l_2050) || 4294967289UL))
                {
                    int32_t l_1727 = 0L;
                    int32_t l_1728 = 4L;
                    int32_t l_1729[4][6][7] = {{{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}};
                    int i, j, k;
                    --l_1730[2][0];
                }
                else
                {
                    uint16_t l_1751 = 0UL;
                    for (g_717 = 0; (g_717 <= 3); g_717 += 1)
                    {
                        int i, j, k;
                        l_1644[g_717][g_717][g_717] ^= (safe_lshift_func_uint8_t_u_u((l_1489[g_717][(g_717 + 2)][g_717] >= (safe_add_func_int32_t_s_s(0x76753DFBL, ((safe_rshift_func_uint8_t_u_s((safe_mod_func_int16_t_s_s(5L, (safe_lshift_func_int16_t_s_u((((safe_lshift_func_uint16_t_u_u(g_1482[2][1][1], 6)) < ((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(0xAAD7L, (((safe_add_func_int32_t_s_s((l_1751 && (((safe_add_func_uint8_t_u_u((((((~(l_1547 , (((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s((l_2178[1] || (((((+(safe_lshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u(g_2100, 9UL)), g_101))) , l_2325) , g_100) != 0xB3L) > l_2325)), 6L)), 0x65A1L)) != 65533UL) >= l_1751))) >= l_1764) | l_1730[2][0]) , l_1751) , l_1751), 0UL)) <= g_1548[5][0][1]) && 255UL)), l_1699)) ^ g_717) >= g_97[2]))), g_1171)) , l_1699)) | l_1751), g_2100)))), l_1751)) & l_1699)))), l_1699));
                    }
                    l_1640 = (l_1489[3][7][7] > ((g_1548[4][6][2] ^ (!((((((safe_rshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s(0x2D2C9E59L, (l_1764 | (safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(((((((l_1751 == ((l_2325 == (safe_sub_func_uint16_t_u_u(((((l_2050 & (safe_add_func_uint16_t_u_u((0L > ((((g_2431 && l_1702[3]) >= g_1171) & 0x3E3BL) , l_1730[2][0])), g_120[1]))) , 8L) , 0L) & l_1659), l_1699))) || l_1764)) >= l_1699) == l_1643[2][2][1]) == 0x34FBL) | 0x6190L) | g_1171), g_1171)) >= l_2325), g_1171)) < 0x90L), l_2050)) & 0x68AFL), g_100)) , l_1633), g_717))))), l_1724)), g_1171)) || 4294967286UL), 13)) <= g_1171) ^ 1L) , g_717) <= l_1751) & 0xABL))) | l_1706));
                    l_1643[0][3][1] ^= l_1751;
                }
                return g_1171;
            }
            for (l_1634 = 0; (l_1634 >= 17); l_1634 = safe_add_func_int16_t_s_s(l_1634, 4))
            {
                const uint32_t l_1798[7][8] = {{0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}};
                int i, j;
                l_1799[1][5] = ((6L ^ (safe_rshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s(((((((l_1611 ^ (((0L >= (((safe_lshift_func_uint8_t_u_u(0x33L, l_1699)) ^ l_1699) , (safe_lshift_func_int8_t_s_s(l_1633, 1)))) == ((((l_1489[2][4][7] , (l_1798[3][0] && k)) & 1UL) & g_1540[0][1]) & g_849[0])) >= l_2178[2])) || 2L) , g_120[1]) | 9UL) , g_1548[1][1][0]) && 1UL), l_1699)), 0))) >= 0x9FEE1EABL);
            }
            g_120[1] |= (((g_849[0] <= (safe_add_func_int32_t_s_s(l_1699, l_1699))) <= ((((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u((l_2325 && ((l_1699 == l_1806) > ((safe_rshift_func_int16_t_s_u(((((((g_97[2] | g_1171) && ((!((safe_rshift_func_int16_t_s_s(((0L | g_2100) , l_2325), l_1699)) ^ g_2100)) ^ 0L)) == g_1171) , 1L) || 0xE5L) <= g_2431), 15)) || l_1806))), 3)) > g_2254) ^ l_1699), l_2050)) ^ l_2178[1]) || 1L) != (-5L)) , 4294967290UL) <= l_1699)) ^ 0x02D0829CL);
            if ((safe_lshift_func_int8_t_s_s(0xBCL, 7)))
            {
                int8_t l_1831 = (-6L);
                int32_t l_1849[6] = {(-1L), 6L, (-1L), 6L, (-1L), 6L};
                const uint8_t l_1889 = 252UL;
                int i;
                for (l_1706 = 0; (l_1706 >= 36); l_1706 = safe_add_func_uint32_t_u_u(l_1706, 3))
                {
                    int32_t l_1836[9][5] = {{(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}};
                    int32_t l_1841 = (-3L);
                    int32_t l_1844 = 8L;
                    int32_t l_1845 = 0xBE0388A2L;
                    int16_t l_1853 = 0xBF53L;
                    uint16_t l_1856 = 0x14A1L;
                    int i, j;
                    g_120[4] ^= (((safe_add_func_uint32_t_u_u((0x22L == (((((l_1636 , (((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((~((((((l_2178[2] >= ((0xEF5AL != (safe_sub_func_int8_t_s_s(((g_1482[2][1][1] && ((safe_add_func_int8_t_s_s((((safe_sub_func_uint16_t_u_u(((((l_1831 | (((g_1171 > g_1540[1][0]) >= (((safe_rshift_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((l_2178[2] > 0x5C49CB64L), 5)) | l_1831) , l_1836[4][3]) == l_2178[1]) && g_2431), l_1633)) >= 0x624C7317L) == l_2325)) <= g_1171)) , g_1171) , 1UL) , g_849[0]), 0xF010L)) ^ 0UL) <= g_849[0]), l_1633)) > 1L)) & g_2100), l_2325))) == 0xE4B6B42FL)) | l_1799[2][5]) , 0L) >= l_1611) & l_1699) , l_1489[0][3][5])), 10)), l_1699)) == g_97[2]) >= l_1699)) || g_2254) , l_1831) == l_2325) ^ g_849[0])), g_1171)) | l_1837) , l_1724);
                    for (g_1171 = 13; (g_1171 >= 1); g_1171 = safe_sub_func_int32_t_s_s(g_1171, 9))
                    {
                        uint8_t l_1840 = 0x4FL;
                        int32_t l_1843 = 1L;
                        int32_t l_1850 = (-10L);
                        int32_t l_1851 = 0x86429966L;
                        int32_t l_1852 = 0xCA3D88B8L;
                        int32_t l_1855 = 1L;
                        l_1840 = l_1611;
                        --l_1846;
                        --l_1856;
                    }
                    for (l_1841 = (-19); (l_1841 != (-8)); l_1841++)
                    {
                        uint16_t l_1886[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_1886[i] = 7UL;
                        g_120[1] &= l_1696[0];
                        g_120[0] = (((((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u(65535UL, 13)) , 0x9426L), (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_u(l_2325, (((((0xEF2D849BL || l_1591) & (l_1841 , (safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u((((((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s(l_1699, (safe_rshift_func_uint16_t_u_s((((l_1799[1][5] > (safe_add_func_uint16_t_u_u(0x2E1AL, 0xBDC1L))) >= l_1836[0][4]) == l_1886[0]), 13)))) | (-2L)), g_143)) & g_1171) < 0xBEL) < l_2050) & l_1888[2]), 0x66L)), l_1699)), 4)), 7)), 0UL)))) , 1UL) ^ l_1889) == 0xEAL))))))) > 0x483D69BBL) , l_1844) , 247UL) ^ l_1706);
                        l_1644[0][3][4] = ((((-2L) == (safe_add_func_uint16_t_u_u((((((((((safe_add_func_int32_t_s_s(((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s((safe_mod_func_int8_t_s_s((251UL != ((!l_1671) == (((g_97[1] | (safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s(0xF54AL, 2)) && ((((l_1699 > ((((l_1853 & (safe_add_func_uint16_t_u_u(0x3ED4L, 1L))) ^ l_2325) | 1L) ^ l_1849[1])) > (-1L)) && g_2254) != 0UL)), 0xEB10B25CL)), 10))) < g_1482[2][1][1]) || 0x405D3F2AL))), l_1599)), 1)), 2)) && l_1611), 5)) && 4294967295UL), 4294967293UL)) , l_2325), 4294967288UL)) | g_1171) || g_1171) && l_1655) && l_2325) && 0x068C0922L) , g_1171) , (-1L)) < l_1699), 1UL))) ^ l_1846) || l_1699);
                        j = (safe_lshift_func_uint8_t_u_s(g_1171, ((safe_rshift_func_int8_t_s_s(9L, l_1633)) != l_1846)));
                    }
                }
                g_120[1] ^= ((g_1171 & (0x8889L >= (l_2325 == ((safe_unary_minus_func_uint8_t_u(0UL)) <= (safe_mod_func_int16_t_s_s(g_1482[3][0][1], ((l_2325 > (((~l_1699) && ((~(!((((safe_sub_func_uint16_t_u_u((((((((g_1171 < ((((l_2325 , l_2325) >= 0x93L) , 1UL) ^ g_100)) ^ l_1699) == l_1889) & 0UL) , g_717) < l_1799[4][4]) < 4294967295UL), l_1849[0])) <= 1L) , g_1171) , 0x3CL))) , l_1699)) >= 7L)) & l_1636))))))) | l_1831);
                l_1643[0][3][1] = (g_1171 > 0x5B7FL);
            }
            else
            {
                uint32_t l_1932 = 1UL;
                int32_t l_1945 = 0L;
                int32_t l_1946[1];
                uint32_t l_1971 = 0x9EF11B35L;
                uint8_t l_1990 = 0xB6L;
                int i;
                for (i = 0; i < 1; i++)
                    l_1946[i] = 3L;
                for (g_2254 = (-11); (g_2254 < (-24)); --g_2254)
                {
                    int32_t l_1929 = 0L;
                    int32_t l_1930 = 0x01C56913L;
                    uint8_t l_1949 = 0xBEL;
                    int32_t l_2005 = 0L;
                    if (g_1171)
                    {
                        int32_t l_1928[10] = {0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L};
                        int i;
                        l_1932--;
                    }
                    else
                    {
                        j = l_2325;
                    }
                    if ((g_1171 , l_2055))
                    {
                        int8_t l_1947 = 0x1BL;
                        int32_t l_1948 = 0x27F08C10L;
                        l_1945 = (((0x03L == (0xA11DL < (g_2431 | ((((0x6F1BL != l_1633) < (((((((((safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(g_97[2], g_1171)), 2)) > (safe_add_func_uint16_t_u_u(g_1548[4][6][2], 0x34DEL))) & l_1699), l_1706)) , 0x3208L) , g_1540[1][0]) , l_1930) == g_2254) , g_1548[0][0][1]) <= l_1932) > l_1699) >= 0UL)) < l_1699) >= l_2325)))) ^ g_97[2]) , g_849[0]);
                        ++l_1949;
                        g_120[4] = (safe_mod_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(6L, (safe_sub_func_uint8_t_u_u(0x94L, (((l_1949 | (safe_rshift_func_int8_t_s_u(((((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((((+(safe_add_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(((0xB3EFL || (l_1947 | (((g_120[1] ^ ((((-2L) & (((l_1699 ^ (l_1945 , 0x78L)) , l_1971) < l_2325)) < 0xA9FBL) == l_2325)) < l_1806) < 0xE1L))) && l_1948), 0x64L)) , l_2325), 9UL))) >= 0x60B3L) != l_2325) ^ l_2325), g_1171)), 0x0DAEL)), g_143)) >= l_1947) > l_2325) == l_1699), l_1948))) , 5L) | 0xB082A17BL))))) , 0x11L), 0x03L));
                    }
                    else
                    {
                        l_1930 = ((0L & l_2325) != (!((safe_mod_func_uint8_t_u_u(g_1171, 0x7AL)) > (((l_1932 | l_2325) , 0x1F0EL) < (l_1699 && ((((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u(l_1725, l_1699)), 0x3929L)) != 0L) == 0x2F747C30L) , 0x96347F98L))))));
                    }
                    if (((safe_lshift_func_uint16_t_u_s((g_1540[1][0] , l_1930), l_1699)) & (((l_1633 < (((((safe_lshift_func_int16_t_s_u(((l_2325 , ((l_1699 && (((safe_unary_minus_func_int16_t_s(((safe_add_func_uint16_t_u_u(j, ((((safe_add_func_uint16_t_u_u((l_1591 ^ l_2325), l_1990)) < l_1699) < 0x1D1DL) | l_1633))) | g_120[1]))) , l_2325) && l_1643[1][1][6])) ^ g_717)) , l_2325), l_1599)) | l_1699) <= 0UL) != (-8L)) , l_2325)) < g_2100) || 0x837FL)))
                    {
                        int8_t l_2002 = 0x5BL;
                        int32_t l_2004[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_2004[i] = 7L;
                        g_2003[0] |= (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u(g_1482[0][1][0], ((~((((-6L) < l_1699) >= g_120[1]) | (l_1699 , l_1699))) != (((safe_lshift_func_uint16_t_u_s(((g_1548[4][6][2] || ((((safe_rshift_func_int8_t_s_s(1L, 4)) <= 0xC812E52FL) || l_2178[1]) <= 0UL)) , l_1888[1]), 3)) != l_2325) < 65535UL)))) | g_1482[2][1][1]) <= 4294967292UL) && l_1929) > l_2002), g_849[0])), g_1171));
                        g_1171--;
                        if (l_1888[1])
                            break;
                    }
                    else
                    {
                        uint8_t l_2013[2][2] = {{1UL, 0x0EL}, {1UL, 0x0EL}};
                        int i, j;
                        g_120[1] = (safe_rshift_func_int16_t_s_u((((safe_sub_func_uint8_t_u_u((0xBC96E130L > l_2013[1][0]), ((safe_add_func_uint8_t_u_u(((l_2005 >= (((safe_add_func_uint8_t_u_u((((l_1653 & l_2013[0][1]) , ((safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(g_1548[4][6][2], l_1932)) , ((safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((l_1699 ^ ((safe_mod_func_uint16_t_u_u((65534UL <= g_2100), l_1699)) , g_120[3])) || l_1591), g_97[1])) > l_2050), (-4L))) > 7L)), l_1949)) == l_1888[2])) < g_1171), 9UL)) | l_2178[1]) & l_1655)) <= l_1930), 0x27L)) & 9UL))) && g_1171) , 0x1E18L), g_18));
                    }
                    g_120[1] = ((((0UL == (0x99L == g_1482[2][1][1])) , g_2468) , g_97[2]) > ((g_120[3] > ((((((safe_lshift_func_uint16_t_u_s(((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s(((0x83922D4EL != ((-8L) > 0x08L)) || l_1634), 5)), l_1504)) >= l_1634), 15)) < l_2325) , 0xAC9FE61AL) , l_2325) > l_1699) | g_1540[1][0])) ^ (-1L)));
                }
            }
        }

                    l_1656[1][6][4]++;
                        ++l_1659;
                    }
                    else
                    {
                        int32_t l_1692 = 1L;
                        l_1671 = (((safe_mod_func_uint16_t_u_u((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u((((l_1651 , ((((g_935 != l_1611) >= (safe_sub_func_uint8_t_u_u(0xEEL, g_849[0]))) <= g_1168) != (1UL & p_12))) && (!(l_1651 >= l_1644[2][1][0]))) || l_1641), (-2L))), 1UL)), g_120[1])) > 0x1BL) | 0xC3L);
                        g_120[1] = (+1UL);

{
        transparent_crc(g_120[g_2100], "g_120[g_2100]", l_1639);
        if (l_1639) printf("index = [%d]\n", g_2100);

    }

                    l_1643[3][1][5] = (safe_add_func_uint32_t_u_u(0UL, (((safe_rshift_func_uint16_t_u_u(((safe_mod_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((~p_13), ((0x60L ^ ((l_1651 == ((((((-1L) == ((0x4B8FL == (p_12 | (((6L | (safe_rshift_func_uint16_t_u_u(((((((((safe_lshift_func_int8_t_s_u(((~(((((safe_mod_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(((!(1UL != g_89)) > l_1522[2][7]), g_120[1])), l_1638[0][0][2])) < 4294967295UL) , p_11) , 0xE3L) , 0x49L)) && 0x109AL), 6)) , g_540) || 4294967288UL) < 0x758ECAE5L) , p_11) > l_1692) != g_120[4]) == 0x90143625L), g_120[0]))) != p_12) | g_18))) | (-1L))) > p_11) > g_694) , p_11) != p_11)) < l_1692)) < g_18))), p_12)) | 0x4510FC82L), g_22)) > 2UL) != l_1643[0][3][1])));
                    }
                }
                else
                {
                    g_120[4] = p_11;
                    if (l_1671)
                        break;
                }
                ++l_1699;
            }
            else
            {
                int8_t l_1702[4] = {0x92L, 1L, 0x92L, 1L};
                int32_t l_1703 = (-7L);
                int32_t l_1704[7][6][6] = {{{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}};
                uint8_t l_1730[3][2];
                uint32_t l_1764 = 0x54F33472L;
                int i, j, k;
                for (i = 0; i < 3; i++)
                {

g_100 -= 1;


                    for (j = 0; j < 2; j++)
                        l_1730[i][j] = 0x7BL;
                }
                g_120[2] = g_1548[4][6][2];
                --l_1706;
                if ((((g_100 < ((safe_sub_func_int8_t_s_s(g_1540[1][0], (((((((1L | (l_1643[4][0][3] != ((safe_sub_func_int16_t_s_s(((safe_sub_func_int32_t_s_s(g_1548[9][3][2], (((((safe_add_func_uint16_t_u_u((!l_1699), g_120[0])) != ((safe_sub_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u((0UL != ((p_12 > l_1698) , l_1671)), 6)), l_1703)), l_1724)) < 255UL)) , l_1537) == l_1725) < l_1489[2][4][7]))) > l_1726), (-10L))) == p_13))) , 0x853A9528L) != 1UL) , l_1706) >= 0x1C39L) == 0xF5678FABL) , 0xD3L))) < 0x7EB415D5L)) != g_143) || 4294967289UL))
                {
                    int32_t l_1727 = 0L;
                    int32_t l_1728 = 4L;
                    int32_t l_1729[4][6][7] = {{{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}};
                    int i, j, k;

{

if ((~(safe_add_func_uint32_t_u_u(((0L != (((l_1888[2] || (safe_sub_func_int8_t_s_s(0x65L, (safe_mod_func_uint32_t_u_u(g_1168, g_59))))) ^ ((safe_add_func_uint16_t_u_u((l_1854 , (safe_lshift_func_int8_t_s_u((0xA7L & 6L), 0))), (((g_935 == l_1764) >= g_18) < g_540))) < (-1L))) < g_935)) , 0x11329388L), 4294967295UL))))
            {
                int32_t l_769[1];
                int i;
                for (i = 0; i < 1; i++)
                    l_769[i] = 0x804970A5L;
                g_120[1] = 1L;
                if (g_935)
                    continue;
                l_2326 = (safe_rshift_func_uint16_t_u_u(g_97[2], 13));
                l_1639 = (safe_lshift_func_int8_t_s_s((5UL >= (0UL < (safe_add_func_int8_t_s_s((((safe_rshift_func_int16_t_s_s((g_18 != (safe_sub_func_int32_t_s_s((safe_unary_minus_func_int32_t_s((safe_mod_func_int8_t_s_s((safe_mod_func_int32_t_s_s(0x5B48709BL, ((safe_rshift_func_int16_t_s_s(g_18, g_935)) || 3L))), (safe_sub_func_int32_t_s_s(l_1726, ((((safe_rshift_func_int16_t_s_u(g_935, 7)) || g_18) || l_769[0]) <= g_1168))))))), g_2467))), 6)) != g_935) != l_1854), g_59)))), g_1168));
            }
            else
            {
                int16_t l_775 = (-4L);
                int32_t l_776 = (-3L);
                l_1659 = ((((l_1764 ^ (l_1888[2] , (0xB43536D7L > 0x43474B68L))) >= (((g_18 < ((safe_add_func_int8_t_s_s(g_59, 0xFAL)) & (safe_mod_func_int8_t_s_s(((((((l_775 | l_776) || g_540) || l_1854) , g_1168) <= 6L) <= 0x62L), 0x36L)))) && l_1764) > 0x8EL)) != g_1168) == g_1168);
            };


                    return g_2431;
                    }

                    --l_1730[2][0];
                }
                else
                {
                    uint16_t l_1751 = 0UL;
                    for (g_89 = 0; (g_89 <= 3); g_89 += 1)
                    {
                        int i, j, k;

{
            transparent_crc(g_1540[l_1549][l_2055], "g_1540[l_1549][l_2055]", l_1634);
            if (l_1634) printf("index = [%d][%d]\n", l_1549, l_2055);

        }

                    l_1644[g_89][g_89][g_89] ^= (safe_lshift_func_uint8_t_u_u((l_1489[g_89][(g_89 + 2)][g_89] >= (safe_add_func_int32_t_s_s(0x76753DFBL, ((safe_rshift_func_uint8_t_u_s((safe_mod_func_int16_t_s_s(5L, (safe_lshift_func_int16_t_s_u((((safe_lshift_func_uint16_t_u_u(g_1482[2][1][1], 6)) < ((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(0xAAD7L, (((safe_add_func_int32_t_s_s((l_1751 && (((safe_add_func_uint8_t_u_u((((((~(l_1695 , (((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s((g_1368[1] || (((((+(safe_lshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u(l_1549, 9UL)), g_540))) , p_13) , g_100) != 0xB3L) > p_13)), 6L)), 0x65A1L)) != 65533UL) >= l_1751))) >= l_1764) | l_1730[2][0]) , l_1751) , l_1751), 0UL)) <= g_1548[5][0][1]) && 255UL)), g_22)) ^ g_717) >= g_97[2]))), p_12)) , p_11)) | l_1751), l_1698)))), l_1751)) & p_11)))), g_22));
                    }
                    l_1651 = (l_1489[3][7][7] > ((g_1548[4][6][2] ^ (!((((((safe_rshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s(0x2D2C9E59L, (l_1764 | (safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(((((((l_1751 == ((p_13 == (safe_sub_func_uint16_t_u_u(((((g_143 & (safe_add_func_uint16_t_u_u((0L > ((((g_59 && l_1702[3]) >= p_12) & 0x3E3BL) , l_1730[2][0])), g_120[1]))) , 8L) , 0L) & l_1659), p_11))) || l_1764)) >= g_22) == l_1643[2][2][1]) == 0x34FBL) | 0x6190L) | p_12), p_12)) >= p_13), p_12)) < 0x90L), g_777)) & 0x68AFL), g_100)) , g_694), g_717))))), l_1724)), p_12)) || 4294967286UL), 13)) <= p_12) ^ 1L) , g_717) <= l_1751) & 0xABL))) | l_1706));
                    l_1643[0][3][1] ^= l_1751;
                }
                return p_12;
            }
            for (l_1634 = 0; (l_1634 >= 17); l_1634 = safe_add_func_int16_t_s_s(l_1634, 4))
            {
                const uint32_t l_1798[7][8] = {{0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}};
                int i, j;

for (l_1537 = 0; l_1537 < 1; l_1537++)
                    l_1696[l_1537] = 3L;

                    l_1799[1][5] = ((6L ^ (safe_rshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s(((((((g_1217 ^ (((0L >= (((safe_lshift_func_uint8_t_u_u(0x33L, p_11)) ^ l_1699) , (safe_lshift_func_int8_t_s_s(g_694, 1)))) == ((((l_1489[2][4][7] , (l_1798[3][0] && l_1705)) & 1UL) & g_1540[0][1]) & g_849[0])) >= g_1368[2])) || 2L) , g_120[1]) | 9UL) , g_1548[1][1][0]) && 1UL), l_1699)), 0))) >= 0x9FEE1EABL);
            }
            g_120[1] |= (((g_849[0] <= (safe_add_func_int32_t_s_s(p_11, p_11))) <= ((((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u((p_13 && ((p_11 == l_1806) > ((safe_rshift_func_int16_t_s_u(((((((g_97[2] | p_12) && ((!((safe_rshift_func_int16_t_s_s(((0L | l_1549) , p_13), g_22)) ^ l_1698)) ^ 0L)) == p_12) , 1L) || 0xE5L) <= g_59), 15)) || l_1806))), 3)) > g_101) ^ p_11), g_1168)) ^ g_1368[1]) || 1L) != (-5L)) , 4294967290UL) <= p_11)) ^ 0x02D0829CL);
            if ((safe_lshift_func_int8_t_s_s(0xBCL, 7)))
            {
                int8_t l_1831 = (-6L);
                int32_t l_1849[6] = {(-1L), 6L, (-1L), 6L, (-1L), 6L};
                const uint8_t l_1889 = 252UL;
                int i;

{
        transparent_crc(g_1368[g_2100], "g_1368[g_2100]", i);

if ((safe_lshift_func_int8_t_s_s(0xBCL, 7)))
            {
                int8_t l_1831 = (-6L);
                int32_t l_1849[6] = {(-1L), 6L, (-1L), 6L, (-1L), 6L};
                const uint8_t l_1889 = 252UL;
                int i;
                for (l_1706 = 0; (l_1706 >= 36); l_1706 = safe_add_func_uint32_t_u_u(l_1706, 3))
                {
                    int32_t l_1836[9][5] = {{(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}};
                    int32_t l_1841 = (-3L);
                    int32_t l_1844 = 8L;
                    int32_t l_1845 = 0xBE0388A2L;
                    int16_t l_1853 = 0xBF53L;
                    uint16_t l_1856 = 0x14A1L;
                    int i, j;
                    g_120[4] ^= (((safe_add_func_uint32_t_u_u((0x22L == (((((l_1639 , (((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((~((((((g_1368[2] >= ((0xEF5AL != (safe_sub_func_int8_t_s_s(((g_1482[2][1][1] && ((safe_add_func_int8_t_s_s((((safe_sub_func_uint16_t_u_u(((((l_1831 | (((g_59 > g_1540[1][0]) >= (((safe_rshift_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((g_1368[2] > 0x5C49CB64L), 5)) | l_1831) , l_1836[4][3]) == g_1368[1]) && g_59), l_1726)) >= 0x624C7317L) == g_2469)) <= g_59)) , g_59) , 1UL) , g_849[0]), 0xF010L)) ^ 0UL) <= g_849[0]), l_1726)) > 1L)) & l_1694), g_2469))) == 0xE4B6B42FL)) | l_1799[2][5]) , 0L) >= g_2414) & g_777) , l_1489[0][3][5])), 10)), l_2050)) == g_97[2]) >= l_2050)) || l_1726) , l_1831) == g_2469) ^ g_849[0])), g_59)) | g_2467) , g_2468);
                    for (g_1171 = 13; (g_1171 >= 1); g_1171 = safe_sub_func_int32_t_s_s(g_1171, 9))
                    {
                        uint8_t l_1840 = 0x4FL;
                        int32_t l_1843 = 1L;
                        int32_t l_1850 = (-10L);
                        int32_t l_1851 = 0x86429966L;
                        int32_t l_1852 = 0xCA3D88B8L;
                        int32_t l_1855 = 1L;
                        l_1840 = g_2414;
                        --l_1671;
                        --l_1856;
                    }
                    for (l_1841 = (-19); (l_1841 != (-8)); l_1841++)
                    {
                        uint16_t l_1886[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_1886[i] = 7UL;
                        g_120[1] &= l_1696[0];
                        g_120[0] = (((((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u(65535UL, 13)) , 0x9426L), (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_u(g_2469, (((((0xEF2D849BL || l_1591) & (l_1841 , (safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u((((((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s(g_143, (safe_rshift_func_uint16_t_u_s((((l_1799[1][5] > (safe_add_func_uint16_t_u_u(0x2E1AL, 0xBDC1L))) >= l_1836[0][4]) == l_1886[0]), 13)))) | (-2L)), g_777)) & g_59) < 0xBEL) < g_143) & l_1888[2]), 0x66L)), l_2050)), 4)), 7)), 0UL)))) , 1UL) ^ l_1889) == 0xEAL))))))) > 0x483D69BBL) , l_1844) , 247UL) ^ l_1706);
                        l_1644[0][3][4] = ((((-2L) == (safe_add_func_uint16_t_u_u((((((((((safe_add_func_int32_t_s_s(((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s((safe_mod_func_int8_t_s_s((251UL != ((!l_1837) == (((g_97[1] | (safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s(0xF54AL, 2)) && ((((l_2050 > ((((l_1853 & (safe_add_func_uint16_t_u_u(0x3ED4L, 1L))) ^ g_2469) | 1L) ^ l_1849[1])) > (-1L)) && l_1726) != 0UL)), 0xEB10B25CL)), 10))) < g_1482[2][1][1]) || 0x405D3F2AL))), l_1549)), 1)), 2)) && g_2414), 5)) && 4294967295UL), 4294967293UL)) , g_2469), 4294967288UL)) | g_59) || g_59) && l_1549) && g_2469) && 0x068C0922L) , g_1171) , (-1L)) < l_2050), 1UL))) ^ l_1671) || g_777);
                        l_2055 = (safe_lshift_func_uint8_t_u_s(g_59, ((safe_rshift_func_int8_t_s_s(9L, l_1726)) != l_1671)));
                    }
                }
                g_120[1] ^= ((g_59 & (0x8889L >= (g_2469 == ((safe_unary_minus_func_uint8_t_u(0UL)) <= (safe_mod_func_int16_t_s_s(g_1482[3][0][1], ((g_2469 > (((~l_2050) && ((~(!((((safe_sub_func_uint16_t_u_u((((((((g_59 < ((((g_2469 , g_2469) >= 0x93L) , 1UL) ^ l_1831)) ^ l_2050) == l_1889) & 0UL) , g_100) < l_1799[4][4]) < 4294967295UL), l_1849[0])) <= 1L) , g_59) , 0x3CL))) , l_2050)) >= 7L)) & l_1639))))))) | l_1831);
                l_1643[0][3][1] = (g_1171 > 0x5B7FL);
            }
            else
            {
                uint32_t l_1932 = 1UL;
                int32_t l_1945 = 0L;
                int32_t l_1946[1];
                uint32_t l_1971 = 0x9EF11B35L;
                uint8_t l_1990 = 0xB6L;
                int i;
                for (i = 0; i < 1; i++)
                    l_1946[i] = 3L;
                for (l_1726 = (-11); (l_1726 < (-24)); --l_1726)
                {
                    int32_t l_1929 = 0L;
                    int32_t l_1930 = 0x01C56913L;
                    uint8_t l_1949 = 0xBEL;
                    int32_t l_2005 = 0L;
                    if (g_59)
                    {
                        int32_t l_1928[10] = {0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L};
                        int i;
                        l_1932--;
                    }
                    else
                    {
                        l_2055 = g_2469;
                    }
                    if ((g_59 , l_1842))
                    {
                        int8_t l_1947 = 0x1BL;
                        int32_t l_1948 = 0x27F08C10L;
                        l_1945 = (((0x03L == (0xA11DL < (g_59 | ((((0x6F1BL != l_1633) < (((((((((safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(g_97[2], g_1171)), 2)) > (safe_add_func_uint16_t_u_u(g_1548[4][6][2], 0x34DEL))) & l_2050), l_1706)) , 0x3208L) , g_1540[1][0]) , l_1930) == l_1726) , g_1548[0][0][1]) <= l_1932) > l_2050) >= 0UL)) < l_2050) >= g_2469)))) ^ g_97[2]) , g_849[0]);
                        ++l_1949;

l_1949 += 1;


                    g_120[4] = (safe_mod_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(6L, (safe_sub_func_uint8_t_u_u(0x94L, (((l_1949 | (safe_rshift_func_int8_t_s_u(((((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((((+(safe_add_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(((0xB3EFL || (l_1947 | (((g_120[1] ^ ((((-2L) & (((l_2050 ^ (l_1945 , 0x78L)) , l_1971) < g_2469)) < 0xA9FBL) == g_2469)) < l_2055) < 0xE1L))) && l_1948), 0x64L)) , g_2469), 9UL))) >= 0x60B3L) != g_2469) ^ g_2469), g_59)), 0x0DAEL)), g_777)) >= l_1947) > g_2469) == l_2050), l_1948))) , 5L) | 0xB082A17BL))))) , 0x11L), 0x03L));
                    }
                    else
                    {
                        l_1930 = ((0L & g_2469) != (!((safe_mod_func_uint8_t_u_u(g_59, 0x7AL)) > (((l_1932 | g_2469) , 0x1F0EL) < (l_2050 && ((((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u(l_1831, l_2050)), 0x3929L)) != 0L) == 0x2F747C30L) , 0x96347F98L))))));
                    }
                    if (((safe_lshift_func_uint16_t_u_s((g_1540[1][0] , l_1930), l_2050)) & (((l_1633 < (((((safe_lshift_func_int16_t_s_u(((g_2469 , ((l_2050 && (((safe_unary_minus_func_int16_t_s(((safe_add_func_uint16_t_u_u(l_2055, ((((safe_add_func_uint16_t_u_u((l_1591 ^ g_2469), l_1990)) < l_2050) < 0x1D1DL) | l_1726))) | g_120[1]))) , g_2469) && l_1643[1][1][6])) ^ g_89)) , g_2469), l_1549)) | l_2050) <= 0UL) != (-8L)) , g_2469)) < l_1694) || 0x837FL)))
                    {
                        int8_t l_2002 = 0x5BL;
                        int32_t l_2004[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_2004[i] = 7L;

for (l_1599 = 0; l_1599 < 6; l_1599++)
        l_1849[l_1599] = 9L;

                    g_2003[0] |= (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u(g_1482[0][1][0], ((~((((-6L) < l_2050) >= g_120[1]) | (l_2050 , l_2050))) != (((safe_lshift_func_uint16_t_u_s(((g_1548[4][6][2] || ((((safe_rshift_func_int8_t_s_s(1L, 4)) <= 0xC812E52FL) || g_1368[1]) <= 0UL)) , l_1888[1]), 3)) != g_2469) < 65535UL)))) | g_1482[2][1][1]) <= 4294967292UL) && l_1929) > l_2002), g_849[0])), g_59));
                        l_1505--;
                        if (l_1888[1])
                            break;
                    }
                    else
                    {
                        uint8_t l_2013[2][2] = {{1UL, 0x0EL}, {1UL, 0x0EL}};
                        int i, j;
                        g_120[1] = (safe_rshift_func_int16_t_s_u((((safe_sub_func_uint8_t_u_u((0xBC96E130L > l_2013[1][0]), ((safe_add_func_uint8_t_u_u(((l_2005 >= (((safe_add_func_uint8_t_u_u((((g_717 & l_2013[0][1]) , ((safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(g_1548[4][6][2], l_1932)) , ((safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((l_2050 ^ ((safe_mod_func_uint16_t_u_u((65534UL <= l_2055), l_2050)) , g_120[3])) || l_1591), g_97[1])) > g_2467), (-4L))) > 7L)), l_1949)) == l_1888[2])) < g_59), 9UL)) | g_1368[1]) & l_1549)) <= l_1930), 0x27L)) & 9UL))) && g_59) , 0x1E18L), g_18));
                    }
                    g_120[1] = ((((0UL == (0x99L == g_1482[2][1][1])) , g_2468) , g_97[2]) > ((g_120[3] > ((((((safe_lshift_func_uint16_t_u_s(((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s(((0x83922D4EL != ((-8L) > 0x08L)) || l_2055), 5)), l_2326)) >= l_2055), 15)) < g_2469) , 0xAC9FE61AL) , g_2469) > l_2050) | g_1540[1][0])) ^ (-1L)));
                }
            };


                    if (i) printf("index = [%d]\n", g_2100);

    }

                    for (l_1706 = 0; (l_1706 >= 36); l_1706 = safe_add_func_uint32_t_u_u(l_1706, 3))
                {
                    int32_t l_1836[9][5] = {{(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}};
                    int32_t l_1841 = (-3L);
                    int32_t l_1844 = 8L;
                    int32_t l_1845 = 0xBE0388A2L;
                    int16_t l_1853 = 0xBF53L;
                    uint16_t l_1856 = 0x14A1L;
                    int i, j;
                    g_120[4] ^= (((safe_add_func_uint32_t_u_u((0x22L == (((((l_1648 , (((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((~((((((g_1368[2] >= ((0xEF5AL != (safe_sub_func_int8_t_s_s(((g_1482[2][1][1] && ((safe_add_func_int8_t_s_s((((safe_sub_func_uint16_t_u_u(((((l_1831 | (((p_12 > g_1540[1][0]) >= (((safe_rshift_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((g_1368[2] > 0x5C49CB64L), 5)) | l_1831) , l_1836[4][3]) == g_1368[1]) && g_59), g_694)) >= 0x624C7317L) == p_13)) <= p_12)) , p_12) , 1UL) , g_849[0]), 0xF010L)) ^ 0UL) <= g_849[0]), g_694)) > 1L)) & l_1698), p_13))) == 0xE4B6B42FL)) | l_1799[2][5]) , 0L) >= g_1217) & l_1699) , l_1489[0][3][5])), 10)), p_11)) == g_97[2]) >= p_11)) || g_101) , l_1831) == p_13) ^ g_849[0])), p_12)) | l_1837) , l_1724);
                    for (g_1171 = 13; (g_1171 >= 1); g_1171 = safe_sub_func_int32_t_s_s(g_1171, 9))
                    {
                        uint8_t l_1840 = 0x4FL;
                        int32_t l_1843 = 1L;
                        int32_t l_1850 = (-10L);
                        int32_t l_1851 = 0x86429966L;
                        int32_t l_1852 = 0xCA3D88B8L;
                        int32_t l_1855 = 1L;
                        l_1840 = g_1217;

for (l_1851 = 0; (l_1851 >= 0); l_1851 -= 1)
        {
            int8_t l_1432 = (-1L);
            int32_t l_1440 = 0x9D9C4759L;

{
                transparent_crc(g_1548[l_2055][l_1855][l_1842], "g_1548[l_2055][l_1855][l_1842]", l_1843);
                if (l_1843) printf("index = [%d][%d][%d]\n", l_2055, l_1855, l_1842);

            }

                    l_1440 &= (((l_1726 < (safe_add_func_uint8_t_u_u(l_1846, (((safe_unary_minus_func_int32_t_s(3L)) , 250UL) , (safe_sub_func_uint8_t_u_u((((g_101 == l_1432) , ((l_1846 > ((safe_lshift_func_int8_t_s_u(((safe_mod_func_uint32_t_u_u(((~((l_1699 ^ g_849[0]) >= g_2414)) || g_22), (-6L))) ^ g_849[0]), l_1846)) >= l_1851)) | 0xA9A8L)) & (-8L)), l_1849[5])))))) , 6UL) && g_120[1]);
        };


                    --l_1846;
                        --l_1856;
                    }
                    for (l_1841 = (-19); (l_1841 != (-8)); l_1841++)
                    {
                        uint16_t l_1886[5];
                        int i;

if (l_1505)
                    break;

                    for (i = 0; i < 5; i++)
                            l_1886[i] = 7UL;
                        g_120[1] &= l_1696[0];

l_1806 &= (l_1846 == l_1698);

                    g_120[0] = (((((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u(65535UL, 13)) , 0x9426L), (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_u(p_13, (((((0xEF2D849BL || l_1591) & (l_1841 , (safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u((((((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s(g_22, (safe_rshift_func_uint16_t_u_s((((l_1799[1][5] > (safe_add_func_uint16_t_u_u(0x2E1AL, 0xBDC1L))) >= l_1836[0][4]) == l_1886[0]), 13)))) | (-2L)), l_1887)) & p_12) < 0xBEL) < g_777) & l_1888[2]), 0x66L)), p_11)), 4)), 7)), 0UL)))) , 1UL) ^ l_1889) == 0xEAL))))))) > 0x483D69BBL) , l_1844) , 247UL) ^ l_1706);

if (l_1888[l_1854])
                            break;


for (l_2325 = 0; l_2325 < 1; l_2325++)
                    l_1696[l_2325] = 3L;

                    l_1644[0][3][4] = ((((-2L) == (safe_add_func_uint16_t_u_u((((((((((safe_add_func_int32_t_s_s(((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s((safe_mod_func_int8_t_s_s((251UL != ((!l_1905) == (((g_97[1] | (safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s(0xF54AL, 2)) && ((((p_11 > ((((l_1853 & (safe_add_func_uint16_t_u_u(0x3ED4L, 1L))) ^ p_13) | 1L) ^ l_1849[1])) > (-1L)) && g_101) != 0UL)), 0xEB10B25CL)), 10))) < g_1482[2][1][1]) || 0x405D3F2AL))), l_1599)), 1)), 2)) && g_1217), 5)) && 4294967295UL), 4294967293UL)) , p_13), 4294967288UL)) | p_12) || p_12) && l_1639) && p_13) && 0x068C0922L) , g_1171) , (-1L)) < p_11), 1UL))) ^ l_1846) || l_1699);
                        l_1693 = (safe_lshift_func_uint8_t_u_s(p_12, ((safe_rshift_func_int8_t_s_s(9L, g_694)) != l_1846)));
                    }
                }
                g_120[1] ^= ((p_12 & (0x8889L >= (p_13 == ((safe_unary_minus_func_uint8_t_u(0UL)) <= (safe_mod_func_int16_t_s_s(g_1482[3][0][1], ((p_13 > (((~p_11) && ((~(!((((safe_sub_func_uint16_t_u_u((((((((p_12 < ((((p_13 , p_13) >= 0x93L) , 1UL) ^ g_100)) ^ p_11) == l_1889) & 0UL) , g_717) < l_1799[4][4]) < 4294967295UL), l_1849[0])) <= 1L) , p_12) , 0x3CL))) , p_11)) >= 7L)) & l_1648))))))) | l_1831);
                l_1643[0][3][1] = (g_1171 > 0x5B7FL);
            }
            else
            {
                uint32_t l_1932 = 1UL;
                int32_t l_1945 = 0L;
                int32_t l_1946[1];
                uint32_t l_1971 = 0x9EF11B35L;
                uint8_t l_1990 = 0xB6L;
                int i;
                for (i = 0; i < 1; i++)
                    l_1946[i] = 3L;

if (g_694)
                    break;

                    for (g_101 = (-11); (g_101 < (-24)); --g_101)
                {
                    int32_t l_1929 = 0L;
                    int32_t l_1930 = 0x01C56913L;
                    uint8_t l_1949 = 0xBEL;
                    int32_t l_2005 = 0L;
                    if (p_12)
                    {
                        int32_t l_1928[10] = {0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L};
                        int i;
                        l_1932--;
                    }
                    else
                    {
                        l_1693 = p_13;
                    }
                    if ((p_12 , l_1694))
                    {
                        int8_t l_1947 = 0x1BL;
                        int32_t l_1948 = 0x27F08C10L;
                        l_1945 = (((0x03L == (0xA11DL < (g_59 | ((((0x6F1BL != g_935) < (((((((((safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(g_97[2], g_1171)), 2)) > (safe_add_func_uint16_t_u_u(g_1548[4][6][2], 0x34DEL))) & p_11), l_1706)) , 0x3208L) , g_1540[1][0]) , l_1930) == g_101) , g_1548[0][0][1]) <= l_1932) > p_11) >= 0UL)) < p_11) >= p_13)))) ^ g_97[2]) , g_849[0]);
                        ++l_1949;
                        g_120[4] = (safe_mod_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(6L, (safe_sub_func_uint8_t_u_u(0x94L, (((l_1949 | (safe_rshift_func_int8_t_s_u(((((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((((+(safe_add_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(((0xB3EFL || (l_1947 | (((g_120[1] ^ ((((-2L) & (((p_11 ^ (l_1945 , 0x78L)) , l_1971) < p_13)) < 0xA9FBL) == p_13)) < l_1806) < 0xE1L))) && l_1948), 0x64L)) , p_13), 9UL))) >= 0x60B3L) != p_13) ^ p_13), p_12)), 0x0DAEL)), l_1887)) >= l_1947) > p_13) == p_11), l_1948))) , 5L) | 0xB082A17BL))))) , 0x11L), 0x03L));
                    }
                    else
                    {
                        l_1930 = ((0L & p_13) != (!((safe_mod_func_uint8_t_u_u(p_12, 0x7AL)) > (((l_1932 | p_13) , 0x1F0EL) < (p_11 && ((((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u(l_1854, p_11)), 0x3929L)) != 0L) == 0x2F747C30L) , 0x96347F98L))))));
                    }
                    if (((safe_lshift_func_uint16_t_u_s((g_1540[1][0] , l_1930), p_11)) & (((g_935 < (((((safe_lshift_func_int16_t_s_u(((p_13 , ((p_11 && (((safe_unary_minus_func_int16_t_s(((safe_add_func_uint16_t_u_u(l_1693, ((((safe_add_func_uint16_t_u_u((l_1591 ^ p_13), l_1990)) < p_11) < 0x1D1DL) | g_694))) | g_120[1]))) , p_13) && l_1643[1][1][6])) ^ g_89)) , p_13), l_1599)) | p_11) <= 0UL) != (-8L)) , p_13)) < l_1698) || 0x837FL)))
                    {
                        int8_t l_2002 = 0x5BL;
                        int32_t l_2004[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_2004[i] = 7L;
                        g_2003[0] |= (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u(g_1482[0][1][0], ((~((((-6L) < p_11) >= g_120[1]) | (p_11 , p_11))) != (((safe_lshift_func_uint16_t_u_s(((g_1548[4][6][2] || ((((safe_rshift_func_int8_t_s_s(1L, 4)) <= 0xC812E52FL) || g_1368[1]) <= 0UL)) , l_1888[1]), 3)) != p_13) < 65535UL)))) | g_1482[2][1][1]) <= 4294967292UL) && l_1929) > l_2002), g_849[0])), p_12));
                        l_2006--;
                        if (l_1888[1])
                            break;
                    }
                    else
                    {
                        uint8_t l_2013[2][2] = {{1UL, 0x0EL}, {1UL, 0x0EL}};
                        int i, j;

for (g_2469 = 0; (g_2469 >= 17); g_2469 = safe_add_func_int16_t_s_s(g_2469, 4))
            {
                const uint32_t l_1798[7][8] = {{0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}};
                int i, j;

for (l_2325 = 0; l_2325 < 6; l_2325++)
                l_1799[l_1945][l_2325] = 65535UL;

                    l_1799[1][5] = ((6L ^ (safe_rshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s(((((((l_1706 ^ (((0L >= (((safe_lshift_func_uint8_t_u_u(0x33L, g_2467)) ^ l_1659) , (safe_lshift_func_int8_t_s_s(l_2182, 1)))) == ((((l_1489[2][4][7] , (l_1798[3][0] && l_1930)) & 1UL) & g_1540[0][1]) & g_849[0])) >= l_2178[2])) || 2L) , g_120[1]) | 9UL) , g_1548[1][1][0]) && 1UL), l_1659)), 0))) >= 0x9FEE1EABL);
            }
if ((safe_lshift_func_uint16_t_u_s((+(safe_sub_func_uint8_t_u_u(g_849[j], g_540))), 8)))
                    {
                        g_120[1] = 0xB8ED6298L;
                        if (g_540)
                            continue;
                        l_2005 &= (safe_mod_func_uint32_t_u_u(g_540, 0xE4729DD1L));
                    }
                    else
                    {
                        uint16_t l_861 = 0x987DL;
                        g_120[1] = ((safe_add_func_int16_t_s_s(0x6D2DL, l_861)) > 9L);
                        return g_849[j];
                    };


                    ;



{
                return g_849[0];
            }

                    g_120[1] = (safe_rshift_func_int16_t_s_u((((safe_sub_func_uint8_t_u_u((0xBC96E130L > l_2013[1][0]), ((safe_add_func_uint8_t_u_u(((l_2005 >= (((safe_add_func_uint8_t_u_u((((l_1725 & l_2013[0][1]) , ((safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(g_1548[4][6][2], l_1932)) , ((safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((p_11 ^ ((safe_mod_func_uint16_t_u_u((65534UL <= l_1549), p_11)) , g_120[3])) || l_1591), g_97[1])) > g_143), (-4L))) > 7L)), l_1949)) == l_1888[2])) < p_12), 9UL)) | g_1368[1]) & l_1639)) <= l_1930), 0x27L)) & 9UL))) && p_12) , 0x1E18L), g_18));
                    }
                    g_120[1] = ((((0UL == (0x99L == g_1482[2][1][1])) , l_2028) , g_97[2]) > ((g_120[3] > ((((((safe_lshift_func_uint16_t_u_s(((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s(((0x83922D4EL != ((-8L) > 0x08L)) || l_1634), 5)), l_1671)) >= l_1634), 15)) < p_13) , 0xAC9FE61AL) , p_13) > p_11) | g_1540[1][0])) ^ (-1L)));
                }
            }
        }
    }
    for (g_100 = 0; (g_100 == 7); g_100 = safe_add_func_uint8_t_u_u(g_100, 6))
    {
        int16_t l_2039 = 0x0ABAL;
        const uint16_t l_2040 = 65532UL;
        int32_t l_2061 = 0x90A8BF10L;
        int32_t l_2101 = 0x02F00675L;
        int32_t l_2137 = 0L;
        int32_t l_2143[3];
        uint32_t l_2152 = 0xDB2A778AL;
        uint16_t l_2158 = 0xFEEFL;
        uint16_t l_2301 = 0xE812L;
        int i;
        for (i = 0; i < 3; i++)
            l_2143[i] = 0x4EA06463L;

{
        uint32_t l_83 = 0xB3DEF23EL;
        l_2325 = l_2325;
        g_717 = ((g_935 > ((((safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(g_1171, (safe_rshift_func_uint16_t_u_s(0xA4A7L, (((l_83 ^ ((((l_2301 == ((safe_lshift_func_int16_t_s_u(((((g_59 || ((((g_89 <= (safe_sub_func_uint8_t_u_u(g_59, (g_18 ^ l_83)))) | 0x39L) <= l_2158) & 0x3186L)) <= g_2467) , l_2158) & 1L), l_83)) ^ 65532UL)) & l_83) || 0x439AL) && 255UL)) == l_2301) != g_18))))), 5L)) >= g_1171) == g_18) != g_935)) <= l_2158);
        return g_89;
    }

                    if ((safe_add_func_uint8_t_u_u(1UL, ((((1UL | ((l_1671 , ((g_849[0] , l_2039) != ((((l_2040 , (-9L)) <= 0x9EA7L) > p_12) , p_11))) <= g_717)) == l_1888[2]) || p_13) ^ g_935))))
        {
            uint32_t l_2062 = 4UL;
            int32_t l_2136 = 0x587994DEL;
            int32_t l_2138 = 0x39236B84L;
            int32_t l_2139 = 0x2CD995FBL;
            int32_t l_2140 = (-1L);
            int32_t l_2142 = 0x807412D1L;
            int32_t l_2146 = (-8L);
            int32_t l_2147 = (-7L);
            int32_t l_2149 = 0x0E72D148L;
            int32_t l_2151 = 0x4ECFBDFFL;
            uint8_t l_2155 = 0x86L;
            int32_t l_2176[3];
            int16_t l_2177 = 0x3603L;
            int32_t l_2179 = 1L;
            int32_t l_2180 = 1L;
            int32_t l_2181 = 0xDF8F0F9CL;
            int32_t l_2183[5] = {0x3D5D9951L, 0L, 0x3D5D9951L, 0L, 0x3D5D9951L};
            uint16_t l_2185 = 0x30E9L;
            int8_t l_2259[8] = {0xA3L, 0x43L, 0xA3L, 0x43L, 0xA3L, 0x43L, 0xA3L, 0x43L};
            int i;

if (l_1888[1])
                            break;


for (l_2055 = 0; l_2055 < 1; l_2055++)
                    {
l_1671 += 1;


                    l_1696[l_2055] = 0x804970A5L;}


for (l_2181 = 0; l_2181 < 4; l_2181++)
    {
        for (l_2180 = 0; l_2180 < 3; l_2180++)
        {
            for (l_2138 = 0; l_2138 < 4; l_2138++)
            {
                transparent_crc(g_1482[l_2181][l_2180][l_2138], "g_1482[l_2181][l_2180][l_2138]", k);
                if (k) printf("index = [%d][%d][%d]\n", l_2181, l_2180, l_2138);

            }
        }
    };


                    for (i = 0; i < 3; i++)
                l_2176[i] = (-1L);

{
                        uint8_t l_1840 = 0x4FL;
                        int32_t l_1843 = 1L;
                        int32_t l_1850 = (-10L);
                        int32_t l_1851 = 0x86429966L;
                        int32_t l_1852 = 0xCA3D88B8L;
                        int32_t l_1855 = 1L;
                        l_1840 = l_2301;
                        --g_1168;
                        --l_2301;
                    }

                    l_2061 = (safe_rshift_func_uint8_t_u_u(((((l_2039 , (safe_mod_func_int16_t_s_s((+((safe_sub_func_uint32_t_u_u((((safe_add_func_int8_t_s_s((0x9FB88B87L <= (l_2050 && l_2028)), ((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(g_120[4], (l_2055 | p_12))), ((safe_unary_minus_func_uint32_t_u((safe_mod_func_uint8_t_u_u((((((((safe_rshift_func_uint8_t_u_u(g_120[1], 3)) ^ 0L) < l_2039) && 0L) < g_143) & 0xF6503CF8L) > p_11), p_11)))) , l_1696[0]))) , l_1888[2]))) == 1UL) , p_11), l_1648)) < 0x0C40299FL)), p_12))) || 0x6671L) && g_540) < g_540), 3));

for (l_2139 = 0; l_2139 < 1; l_2139++)
        {
            for (l_2137 = 0; l_2137 < 10; l_2137++)
            {
                transparent_crc(g_2470[l_2179][l_2139][l_2137], "g_2470[l_2179][l_2139][l_2137]", l_1698);
                if (l_1698) printf("index = [%d][%d][%d]\n", l_2179, l_2139, l_2137);

            }
        };


                    if ((l_2062 == 0xF331L))
            {
                uint32_t l_2075 = 0x3F7E974AL;
                int32_t l_2076 = 0xDD959D4BL;
                uint32_t l_2121 = 0xDB46FF94L;
                int32_t l_2135 = 0x8FD202FEL;
                int32_t l_2144 = 7L;
                int32_t l_2145 = 0x543A4A56L;
                int32_t l_2148 = (-7L);
                int32_t l_2150 = (-4L);

{
                        int32_t l_1928[10] = {0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L};
                        int i;

{
                return l_2182;
            }

                    p_11--;
                    }

                    for (g_59 = 11; (g_59 > 6); g_59 = safe_sub_func_uint16_t_u_u(g_59, 8))
                {
                    uint16_t l_2105 = 65535UL;
                    for (l_2050 = 0; (l_2050 != 38); ++l_2050)
                    {
                        l_1695 = ((p_12 < (safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((p_11 < 0L), (p_11 >= 0L))), (-1L)))) >= ((safe_lshift_func_uint8_t_u_u(((p_13 || 252UL) , ((((safe_lshift_func_int8_t_s_s(l_1549, 7)) != 0L) == g_101) , g_849[0])), l_2075)) >= l_2076));
                    }
                    for (l_2055 = (-27); (l_2055 <= (-28)); l_2055--)
                    {
                        uint32_t l_2102 = 0x75F47E93L;
                        g_120[2] = (safe_sub_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((g_101 > p_11), (safe_sub_func_uint8_t_u_u(((p_13 & (p_12 & ((((~((((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(g_1168, (((((safe_lshift_func_int8_t_s_s(((safe_mod_func_uint8_t_u_u((((0xDFF1L > ((safe_sub_func_int8_t_s_s((((+((!(((safe_lshift_func_int16_t_s_s(0xF854L, 8)) ^ g_1482[2][1][1]) ^ g_540)) , g_120[4])) == 0UL) ^ g_100), p_12)) , 1L)) , g_89) | g_2003[3]), g_849[0])) || 0x4AL), p_12)) > p_12) & g_97[3]) == g_1368[1]) , 0x821DL))), p_11)) & 0xDCA8CE5FL) <= l_2040) > p_13)) | p_13) , p_12) || p_13))) , l_2076), 0x74L)))), g_2100));

for (l_2149 = (-29); (l_2149 != (-3)); l_2149++)
        {
            g_2431--;
            if (g_101)
                continue;
            for (g_101 = 0; (g_101 == (-12)); g_101 = safe_sub_func_int8_t_s_s(g_101, 2))
            {
                return g_849[0];
            }
        };


                    l_2101 |= 9L;
                        l_2102 &= p_12;
                    }
                    for (l_2076 = 7; (l_2076 >= (-7)); --l_2076)
                    {
                        uint32_t l_2108 = 0xCCCFDF72L;
                        l_2105 ^= p_13;
                        g_120[2] = (((safe_rshift_func_uint8_t_u_u((((g_1482[2][1][3] , (((l_2108 | g_120[3]) == p_11) , ((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint8_t_u_u(((0UL && g_2003[1]) || 1UL), ((safe_sub_func_uint8_t_u_u(((((safe_sub_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((p_12 && (safe_lshift_func_uint8_t_u_s((0x24L >= 0UL), 0))), p_11)), l_2121)) <= l_2040) & g_717) , p_11), 1UL)) >= l_2108))) >= p_13), 12)) >= (-1L)))) | g_97[2]) != p_12), 2)) ^ 0xB68DD604L) == 0UL);
                    }

for (p_12 = (-26); (p_12 <= 16); p_12++)
                    {
                        int8_t l_524 = (-8L);
                        l_524 = g_100;
                        l_2142 &= l_524;
                    }

{
            for (k = 0; k < 10; k++)
            {
                transparent_crc(g_2470[l_2149][l_1648][k], "g_2470[l_2149][l_1648][k]", l_2151);
                if (l_2151) printf("index = [%d][%d][%d]\n", l_2149, l_1648, k);

            }
        }

                    if ((g_143 == 0xF331L))
            {
                uint32_t l_2075 = 0x3F7E974AL;
                int32_t l_2076 = 0xDD959D4BL;
                uint32_t l_2121 = 0xDB46FF94L;
                int32_t l_2135 = 0x8FD202FEL;
                int32_t l_2144 = 7L;
                int32_t l_2145 = 0x543A4A56L;
                int32_t l_2148 = (-7L);
                int32_t l_2150 = (-4L);
                for (g_59 = 11; (g_59 > 6); g_59 = safe_sub_func_uint16_t_u_u(g_59, 8))
                {
                    uint16_t l_2105 = 65535UL;
                    for (l_2326 = 0; (l_2326 != 38); ++l_2326)
                    {

for (l_2179 = 0; l_2179 < 1; l_2179++)
        {
            for (l_2179 = 0; l_2179 < 10; l_2179++)
            {
                transparent_crc(g_2470[l_2139][l_2179][l_2179], "g_2470[l_2139][l_2179][l_2179]", l_2140);
                if (l_2140) printf("index = [%d][%d][%d]\n", l_2139, l_2179, l_2179);

            }
        };


                    l_2076 = ((g_2431 < (safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((g_1168 < 0L), (g_1168 >= 0L))), (-1L)))) >= ((safe_lshift_func_uint8_t_u_u(((l_2139 || 252UL) , ((((safe_lshift_func_int8_t_s_s(k, 7)) != 0L) == l_2182) , g_849[0])), l_2075)) >= l_2076));
                    }
                    for (l_2180 = (-27); (l_2180 <= (-28)); l_2180--)
                    {
                        uint32_t l_2102 = 0x75F47E93L;
                        l_2183[2] = (safe_sub_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((l_2182 > g_1168), (safe_sub_func_uint8_t_u_u(((l_2139 & (g_2431 & ((((~((((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(g_2467, (((((safe_lshift_func_int8_t_s_s(((safe_mod_func_uint8_t_u_u((((0xDFF1L > ((safe_sub_func_int8_t_s_s((((+((!(((safe_lshift_func_int16_t_s_s(0xF854L, 8)) ^ g_1482[2][1][1]) ^ l_2182)) , l_2183[4])) == 0UL) ^ g_89), g_2431)) , 1L)) , g_89) | g_2003[3]), g_849[0])) || 0x4AL), g_2431)) > g_2431) & g_97[3]) == l_2178[1]) , 0x821DL))), g_1168)) & 0xDCA8CE5FL) <= l_2040) > l_2139)) | l_2139) , g_2431) || l_2139))) , l_2076), 0x74L)))), l_2180));
                        l_2180 |= 9L;
                        l_2102 &= g_2431;
                    }
                    for (l_2076 = 7; (l_2076 >= (-7)); --l_2076)
                    {
                        uint32_t l_2108 = 0xCCCFDF72L;
                        l_2105 ^= l_2139;
                        l_2183[2] = (((safe_rshift_func_uint8_t_u_u((((g_1482[2][1][3] , (((l_2108 | l_2183[3]) == g_1168) , ((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint8_t_u_u(((0UL && g_2003[1]) || 1UL), ((safe_sub_func_uint8_t_u_u(((((safe_sub_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((g_2431 && (safe_lshift_func_uint8_t_u_s((0x24L >= 0UL), 0))), g_1168)), l_2121)) <= l_2040) & g_89) , g_1168), 1UL)) >= l_2108))) >= l_2139), 12)) >= (-1L)))) | g_97[2]) != g_2431), 2)) ^ 0xB68DD604L) == 0UL);
                    }
                    l_2135 = (g_89 != (safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s((((-1L) || 0x95L) & l_2178[1]), ((safe_lshift_func_uint8_t_u_u(255UL, 7)) >= (((((safe_unary_minus_func_uint16_t_u(1UL)) , ((((g_1168 == ((l_2105 , (safe_sub_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(l_2182, l_2183[1])) , l_2177), g_143))) == g_2431)) , 0x8847L) == l_2182) , 0x73EDD688L)) == l_2139) , g_143) < l_2182)))), 8)));
                }
                g_2467++;
                l_2145 = ((((l_2140 , (g_59 != g_2431)) || (0xADL && 0x61L)) < g_1168) < ((safe_lshift_func_uint16_t_u_s(0xD3B9L, (2UL < ((((0x7EC0L & l_2183[1]) & 4294967295UL) || 1UL) & 0x5C680109L)))) == 0xC0DAL));
            }
            else
            {
                uint32_t l_2161 = 0x817ED328L;
                l_2180 |= (7L ^ (g_2431 > (((l_2301 < (g_2431 & ((safe_lshift_func_uint8_t_u_u(0x2CL, 3)) || (255UL >= g_2431)))) , g_1548[2][0][1]) == l_2161)));
                l_2140 = (safe_sub_func_uint32_t_u_u((g_2003[0] >= ((g_2431 >= (safe_add_func_int32_t_s_s(((((((safe_add_func_int8_t_s_s(((((safe_sub_func_int8_t_s_s(l_2180, (safe_sub_func_uint16_t_u_u(0xB24EL, ((((safe_mod_func_uint32_t_u_u(g_22, ((((safe_sub_func_int32_t_s_s((0L == l_2178[0]), (0x17L && (g_89 , 0x38L)))) > g_22) , 255UL) && g_2467))) || 0x8F222FB3L) || 0xC79840FEL) ^ g_2431))))) < g_2431) , g_59) > g_97[5]), 7UL)) < l_2183[2]) , l_2183[1]) & l_2144) <= l_2301) && g_18), g_2431))) && g_2431)), g_89));
            };


                    ;


                    l_1693 = (g_100 != (safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s((((-1L) || 0x95L) & g_1368[1]), ((safe_lshift_func_uint8_t_u_u(255UL, 7)) >= (((((safe_unary_minus_func_uint16_t_u(1UL)) , ((((p_11 == ((l_2105 , (safe_sub_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(g_540, g_120[1])) , l_2039), l_2062))) == p_12)) , 0x8847L) == g_101) , 0x73EDD688L)) == p_13) , l_2062) < g_101)))), 8)));
                }
                l_2152++;

g_100 += 1;


                    l_2145 = ((((l_2151 , (l_2155 != p_12)) || (0xADL && 0x61L)) < p_11) < ((safe_lshift_func_uint16_t_u_s(0xD3B9L, (2UL < ((((0x7EC0L & g_120[1]) & 4294967295UL) || 1UL) & 0x5C680109L)))) == 0xC0DAL));
            }
            else
            {
                uint32_t l_2161 = 0x817ED328L;

{
                        if (p_12)
                            break;
                    }

                    l_2101 |= (7L ^ (p_12 > (((l_2158 < (p_12 & ((safe_lshift_func_uint8_t_u_u(0x2CL, 3)) || (255UL >= p_12)))) , g_1548[2][0][1]) == l_2161)));

g_717 += 1;


                    l_2151 = (safe_sub_func_uint32_t_u_u((g_2003[0] >= ((p_12 >= (safe_add_func_int32_t_s_s(((((((safe_add_func_int8_t_s_s(((((safe_sub_func_int8_t_s_s(g_2100, (safe_sub_func_uint16_t_u_u(0xB24EL, ((((safe_mod_func_uint32_t_u_u(g_22, ((((safe_sub_func_int32_t_s_s((0L == l_2176[0]), (0x17L && (g_89 , 0x38L)))) > g_22) , 255UL) && g_1168))) || 0x8F222FB3L) || 0xC79840FEL) ^ p_12))))) < p_12) , g_59) > g_97[5]), 7UL)) < g_120[2]) , g_120[1]) & l_2146) <= g_1217) && g_18), p_12))) && p_12)), g_717));
            }
            l_2185++;

{
            g_59--;
            if (g_935)
                continue;
            for (l_2182 = 0; (l_2182 == (-12)); l_2182 = safe_sub_func_int8_t_s_s(l_2182, 2))
            {
                return g_849[0];
            }
        }

                    for (l_1671 = 0; (l_1671 <= 8); l_1671 = safe_add_func_uint8_t_u_u(l_1671, 6))
            {
                const int8_t l_2199 = (-1L);
                int32_t l_2255[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_2255[i] = 0L;
                for (g_59 = 0; (g_59 == 34); g_59 = safe_add_func_uint8_t_u_u(g_59, 3))
                {
                    int16_t l_2216 = 0x83C6L;
                    int32_t l_2249 = 0xEA87154FL;
                    int32_t l_2260 = 0xF84A0E45L;
                    int32_t l_2261 = 0xC424E530L;
                    uint16_t l_2263 = 65530UL;

for (j = 2; (j >= 0); j -= 1)
                    {
                        int i;
                        l_2149 &= (((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((l_2183[j] > (0L || (safe_rshift_func_uint8_t_u_u(g_1368[j], (((g_849[0] | (((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(l_2261, 4)), 13)) , ((safe_unary_minus_func_int8_t_s(((safe_rshift_func_int16_t_s_u(l_2183[j], ((safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(p_12, 2)) , (safe_rshift_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((65535UL & ((((((((safe_mod_func_int8_t_s_s(l_2151, l_1726)) , 0x3DL) == p_12) > 0xB5BB9598L) != l_2177) ^ 0L) || g_2414) <= 4294967291UL)), g_2431)) <= g_97[0]), 14))), l_2261)) != p_12) != g_1168) & 0UL), p_12)) != l_2261) || g_2414), 0x7D1913C8L)) <= g_22))) ^ 0x99L))) | p_12)) | 0x6BL)) || g_2467) & g_97[2]))))) ^ g_1368[j]), l_1696[0])), 0xFB5B7956L)), 14)) < g_849[0]) , l_2199) <= g_2467), l_1549)) && g_2467) , 0x3F8D8182L);
                        l_1726 ^= (g_1368[j] && ((g_1168 , (safe_sub_func_int8_t_s_s((((0x01B30B9BL ^ (1UL | (safe_sub_func_int32_t_s_s(l_2199, (((g_120[4] , g_849[0]) ^ g_2467) != j))))) < 1UL) | 0x7EE96D31L), g_2431))) == g_2100));
                        l_2255[1] = (g_2467 != g_2431);
                    };


                    for (g_2100 = 0; (g_2100 <= (-15)); g_2100 = safe_sub_func_uint32_t_u_u(g_2100, 1))
                    {
                        const uint8_t l_2200 = 0xE4L;
                        uint16_t l_2217 = 3UL;

{
                    int16_t l_2216 = 0x83C6L;
                    int32_t l_2249 = 0xEA87154FL;
                    int32_t l_2260 = 0xF84A0E45L;
                    int32_t l_2261 = 0xC424E530L;
                    uint16_t l_2263 = 65530UL;
                    for (l_1651 = 0; (l_1651 <= (-15)); l_1651 = safe_sub_func_uint32_t_u_u(l_1651, 1))
                    {
                        const uint8_t l_2200 = 0xE4L;
                        uint16_t l_2217 = 3UL;
                        l_2178[0] = (0UL >= ((g_1368[0] != (((safe_add_func_int16_t_s_s(((+(l_2176[0] && ((((0xEEL >= g_120[1]) && (+g_717)) || g_143) > (((((~(l_2146 <= (l_2199 , 0L))) >= (-1L)) <= l_2146) , g_1171) , l_2062)))) > g_143), l_2200)) | l_2200) , l_2177)) != g_97[5]));
                        g_120[1] = (safe_lshift_func_int8_t_s_u(((safe_mod_func_uint16_t_u_u(g_59, (((l_2040 || (safe_unary_minus_func_int8_t_s(((safe_mod_func_int16_t_s_s((0L != ((safe_sub_func_uint32_t_u_u(0xF9EC49D5L, (safe_lshift_func_uint8_t_u_s(((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(((((-8L) && (0x53L || 1L)) < (l_2177 == (((0xAC9BL > g_143) <= l_2062) >= l_2146))) , l_2216), 2)) && 0xE90C1C13L), 2L)) , l_2177) , 0UL) , l_2142), 7)))) , g_59)), g_59)) < l_2177)))) != 0L) || l_2217))) > l_2146), 6));
                        g_120[1] &= l_2200;

for (l_2260 = 0; l_2260 < 4; l_2260++)
    {
        for (l_2136 = 0; l_2136 < 3; l_2136++)
        {
            for (l_2139 = 0; l_2139 < 4; l_2139++)
            {
                transparent_crc(g_1482[l_2260][l_2136][l_2139], "g_1482[l_2260][l_2136][l_2139]", l_2325);
                if (l_2325) printf("index = [%d][%d][%d]\n", l_2260, l_2136, l_2139);

            }
        }
    };


                    if (g_717)
                            break;
                    }
                    if ((g_1482[2][1][1] & 0xDB81CA17L))
                    {
                        i = l_2176[0];
                        return l_2146;
                    }
                    else
                    {
                        if (g_59)
                            break;
                    }
                    for (l_2180 = 2; (l_2180 >= 0); l_2180 -= 1)
                    {
                        int i;
                        l_2249 &= (((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((g_120[l_2180] > (0L || (safe_rshift_func_uint8_t_u_u(l_2178[l_2180], (((g_849[0] | (((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(l_2146, 4)), 13)) , ((safe_unary_minus_func_int8_t_s(((safe_rshift_func_int16_t_s_u(g_120[l_2180], ((safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(g_59, 2)) , (safe_rshift_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((65535UL & ((((((((safe_mod_func_int8_t_s_s(i, l_2216)) , 0x3DL) == g_59) > 0xB5BB9598L) != l_2177) ^ 0L) || l_2301) <= 4294967291UL)), g_1171)) <= g_97[0]), 14))), l_2146)) != g_59) != l_2062) & 0UL), g_59)) != l_2146) || l_2301), 0x7D1913C8L)) <= l_2062))) ^ 0x99L))) | g_59)) | 0x6BL)) || g_143) & g_97[2]))))) ^ l_2178[l_2180]), l_1696[0])), 0xFB5B7956L)), 14)) < g_849[0]) , l_2199) <= g_143), g_2100)) && g_143) , 0x3F8D8182L);
                        l_2177 ^= (l_2178[l_2180] && ((l_2050 , (safe_sub_func_int8_t_s_s((((0x01B30B9BL ^ (1UL | (safe_sub_func_int32_t_s_s(l_2199, (((g_120[4] , g_849[0]) ^ l_1671) != i))))) < 1UL) | 0x7EE96D31L), g_1171))) == l_1651));
                        l_2255[1] = (g_143 != g_1171);
                    }
                    for (l_2062 = 0; (l_2062 <= 2); l_2062 += 1)
                    {
                        int32_t l_2256 = 0x52D2483BL;
                        int32_t l_2257 = 1L;
                        int32_t l_2258[2][3];
                        int16_t l_2262 = 1L;
                        int i, j;
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 3; j++)
                                l_2258[i][j] = 1L;
                        }
                        l_2142 = g_1368[l_2062];
                        l_2263--;
                        l_2260 &= (g_143 == l_2146);
                        l_2140 = (safe_sub_func_int16_t_s_s(((g_1482[2][1][1] | ((5L || (g_1548[3][7][1] != (safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((0x76L & ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((g_101 & (safe_lshift_func_uint16_t_u_u(((g_143 & (0x5EL <= ((safe_add_func_int8_t_s_s(1L, (g_1368[0] >= 0x02L))) <= l_2256))) != l_1726), 15))), l_2216)), g_1540[1][0])) < 0x866FL)) >= 0x9DEFCED1L), 0x570AL)), g_97[5])), g_2100)), g_143)))) , l_2178[2])) ^ 0xAB2DL), 0UL));
                    }
                }


l_2182 &= 0xEC293C97L;

                    l_2143[0] = (0UL >= ((g_1368[0] != (((safe_add_func_int16_t_s_s(((+(l_2176[0] && ((((0xEEL >= g_120[1]) && (+g_717)) || p_11) > (((((~(p_13 <= (l_2199 , 0L))) >= (-1L)) <= p_13) , g_59) , g_143)))) > p_11), l_2200)) | l_2200) , g_101)) != g_97[5]));

l_1694 &= (p_11 == l_2179);

                    g_120[1] = (safe_lshift_func_int8_t_s_u(((safe_mod_func_uint16_t_u_u(p_12, (((l_2040 || (safe_unary_minus_func_int8_t_s(((safe_mod_func_int16_t_s_s((0L != ((safe_sub_func_uint32_t_u_u(0xF9EC49D5L, (safe_lshift_func_uint8_t_u_s(((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(((((-8L) && (0x53L || 1L)) < (g_101 == (((0xAC9BL > p_11) <= g_143) >= p_13))) , l_2216), 2)) && 0xE90C1C13L), 2L)) , g_101) , 0UL) , l_2101), 7)))) , p_12)), p_12)) < g_935)))) != 0L) || l_2217))) > p_13), 6));
                        g_120[1] &= l_2200;
                        if (g_717)
                            {
{
                transparent_crc(g_2470[l_1549][l_2179][l_2146], "g_2470[l_1549][l_2179][l_2146]", l_2137);
                if (l_2137) printf("index = [%d][%d][%d]\n", l_1549, l_2179, l_2146);

            }

                    break;}
                    }
                    if ((g_1482[2][1][1] & 0xDB81CA17L))
                    {

{

{
        transparent_crc(g_97[k], "g_97[k]", k);
        if (k) printf("index = [%d]\n", k);

    }

                    l_2146 = ((l_2155 < (safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((l_1671 < 0L), (l_1671 >= 0L))), (-1L)))) >= ((safe_lshift_func_uint8_t_u_u(((l_2179 || 252UL) , ((((safe_lshift_func_int8_t_s_s(l_1698, 7)) != 0L) == l_2177) , g_849[0])), g_22)) >= l_2149));
                    }

                    l_2181 = l_2176[0];
                        return p_13;
                    }
                    else
                    {
                        if (p_12)
                            break;
                    }

{
            p_12--;
            if (l_2182)
                continue;
            for (g_935 = 0; (g_935 == (-12)); g_935 = safe_sub_func_int8_t_s_s(g_935, 2))
            {
                return g_849[0];
            }
        }

                    for (l_2137 = 2; (l_2137 >= 0); l_2137 -= 1)
                    {
                        int i;
                        l_2249 &= (((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((l_2183[l_2137] > (0L || (safe_rshift_func_uint8_t_u_u(l_2143[l_2137], (((g_849[0] | (((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(p_13, 4)), 13)) , ((safe_unary_minus_func_int8_t_s(((safe_rshift_func_int16_t_s_u(l_2183[l_2137], ((safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(p_12, 2)) , (safe_rshift_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((65535UL & ((((((((safe_mod_func_int8_t_s_s(l_2181, g_540)) , 0x3DL) == p_12) > 0xB5BB9598L) != g_101) ^ 0L) || l_2158) <= 4294967291UL)), g_59)) <= g_97[0]), 14))), l_2179)) != p_12) != g_143) & 0UL), p_12)) != p_13) || l_2158), 0x7D1913C8L)) <= l_2152))) ^ 0x99L))) | p_12)) | 0x6BL)) || p_11) & g_97[2]))))) ^ l_2143[l_2137]), l_1696[0])), 0xFB5B7956L)), 14)) < g_849[0]) , l_2199) <= p_11), l_1694)) && p_11) , 0x3F8D8182L);
                        g_2254 ^= (l_2143[l_2137] && ((g_1168 , (safe_sub_func_int8_t_s_s((((0x01B30B9BL ^ (1UL | (safe_sub_func_int32_t_s_s(l_2199, (((g_120[4] , g_849[0]) ^ g_777) != l_2151))))) < 1UL) | 0x7EE96D31L), g_59))) == g_2100));
                        l_2255[1] = (p_11 != g_59);
                    }
                    for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1)
                    {
                        int32_t l_2256 = 0x52D2483BL;
                        int32_t l_2257 = 1L;
                        int32_t l_2258[2][3];
                        int16_t l_2262 = 1L;
                        int i, j;

{
                        uint8_t l_2013[2][2] = {{1UL, 0x0EL}, {1UL, 0x0EL}};
                        int i, j;
                        g_120[1] = (safe_rshift_func_int16_t_s_u((((safe_sub_func_uint8_t_u_u((0xBC96E130L > l_2013[1][0]), ((safe_add_func_uint8_t_u_u(((l_1549 >= (((safe_add_func_uint8_t_u_u((((g_89 & l_2013[0][1]) , ((safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(g_1548[4][6][2], g_22)) , ((safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((g_22 ^ ((safe_mod_func_uint16_t_u_u((65534UL <= l_2138), g_22)) , g_120[3])) || l_2185), g_97[1])) > l_1671), (-4L))) > 7L)), g_1171)) == l_1888[2])) < g_59), 9UL)) | l_2143[1]) & l_2249)) <= l_2257), 0x27L)) & 9UL))) && g_59) , 0x1E18L), g_18));
                    }

                    for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 3; j++)
                                l_2258[i][j] = 1L;
                        }


{
                        uint32_t l_2108 = 0xCCCFDF72L;
                        g_1217 ^= l_2180;
                        l_2183[2] = (((safe_rshift_func_uint8_t_u_u((((g_1482[2][1][3] , (((l_2108 | l_2183[3]) == l_2062) , ((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint8_t_u_u(((0UL && g_2003[1]) || 1UL), ((safe_sub_func_uint8_t_u_u(((((safe_sub_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((l_2155 && (safe_lshift_func_uint8_t_u_s((0x24L >= 0UL), 0))), l_2062)), g_777)) <= l_2040) & g_717) , l_2062), 1UL)) >= l_2108))) >= l_2180), 12)) >= (-1L)))) | g_97[2]) != l_2155), 2)) ^ 0xB68DD604L) == 0UL);
                    }

                    if (l_2261) {
{
        transparent_crc(g_97[l_2260], "g_97[l_2260]", l_2261);
        if (l_2261) printf("index = [%d]\n", l_2260);

    }

                    printf("index = [%d][%d][%d]\n", l_1695, l_1698, l_1651);}

                    l_2101 = g_1368[l_2152];

{
                        return g_2431;
                    }

                    l_2263--;
                        l_2260 &= (p_11 == p_13);


{
                transparent_crc(g_2470[l_1695][l_2256][l_1651], "g_2470[l_1695][l_2256][l_1651]", l_1651);
                if (l_1651) printf("index = [%d][%d][%d]\n", l_1695, l_2256, l_1651);

            }

                    if (g_101)
                            {
l_2137 -= 1;


                    break;}

                    l_1693 = (safe_sub_func_int16_t_s_s(((g_1482[2][1][1] | ((5L || (g_1548[3][7][1] != (safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((0x76L & ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((l_2039 & (safe_lshift_func_uint16_t_u_u(((p_11 & (0x5EL <= ((safe_add_func_int8_t_s_s(1L, (g_1368[0] >= 0x02L))) <= l_2256))) != g_694), 15))), l_2216)), g_1540[1][0])) < 0x866FL)) >= 0x9DEFCED1L), 0x570AL)), g_97[5])), l_1694)), p_11)))) , l_2143[2])) ^ 0xAB2DL), 0UL));
                    }
                }
            }
        }
        else
        {
            int32_t l_2300[5][8] = {{0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}};
            int32_t l_2321 = (-1L);
            uint32_t l_2322 = 0x99FED06DL;
            int i, j;

{
        int16_t l_2039 = 0x0ABAL;
        const uint16_t l_2040 = 65532UL;
        int32_t l_2061 = 0x90A8BF10L;
        int32_t l_2101 = 0x02F00675L;
        int32_t l_2137 = 0L;
        int32_t l_2143[3];
        uint32_t l_2152 = 0xDB2A778AL;
        uint16_t l_2158 = 0xFEEFL;
        uint16_t l_2301 = 0xE812L;
        int i;
        for (i = 0; i < 3; i++)
            l_2143[i] = 0x4EA06463L;
        if ((safe_add_func_uint8_t_u_u(1UL, ((((1UL | ((g_143 , ((g_849[0] , l_2039) != ((((l_2040 , (-9L)) <= 0x9EA7L) > g_1171) , l_1671))) <= g_100)) == l_1888[2]) || l_1698) ^ g_101))))
        {
            uint32_t l_2062 = 4UL;
            int32_t l_2136 = 0x587994DEL;
            int32_t l_2138 = 0x39236B84L;
            int32_t l_2139 = 0x2CD995FBL;
            int32_t l_2140 = (-1L);
            int32_t l_2142 = 0x807412D1L;
            int32_t l_2146 = (-8L);
            int32_t l_2147 = (-7L);
            int32_t l_2149 = 0x0E72D148L;
            int32_t l_2151 = 0x4ECFBDFFL;
            uint8_t l_2155 = 0x86L;
            int32_t l_2176[3];
            int16_t l_2177 = 0x3603L;
            int32_t l_2179 = 1L;
            int32_t l_2180 = 1L;
            int32_t l_2181 = 0xDF8F0F9CL;
            int32_t l_2183[5] = {0x3D5D9951L, 0L, 0x3D5D9951L, 0L, 0x3D5D9951L};
            uint16_t l_2185 = 0x30E9L;
            int8_t l_2259[8] = {0xA3L, 0x43L, 0xA3L, 0x43L, 0xA3L, 0x43L, 0xA3L, 0x43L};
            int i;
            for (i = 0; i < 3; i++)
                l_2176[i] = (-1L);
            l_2061 = (safe_rshift_func_uint8_t_u_u(((((l_2039 , (safe_mod_func_int16_t_s_s((+((safe_sub_func_uint32_t_u_u((((safe_add_func_int8_t_s_s((0x9FB88B87L <= (g_777 && g_2468)), ((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(g_120[4], (l_2101 | g_1171))), ((safe_unary_minus_func_uint32_t_u((safe_mod_func_uint8_t_u_u((((((((safe_rshift_func_uint8_t_u_u(g_120[1], 3)) ^ 0L) < l_2039) && 0L) < g_2467) & 0xF6503CF8L) > l_1671), l_1671)))) , l_1696[0]))) , l_1888[2]))) == 1UL) , l_1671), g_2469)) < 0x0C40299FL)), g_1171))) || 0x6671L) && l_2182) < l_2182), 3));
            if ((l_2062 == 0xF331L))
            {
                uint32_t l_2075 = 0x3F7E974AL;
                int32_t l_2076 = 0xDD959D4BL;
                uint32_t l_2121 = 0xDB46FF94L;
                int32_t l_2135 = 0x8FD202FEL;
                int32_t l_2144 = 7L;
                int32_t l_2145 = 0x543A4A56L;
                int32_t l_2148 = (-7L);
                int32_t l_2150 = (-4L);
                for (g_1171 = 11; (g_1171 > 6); g_1171 = safe_sub_func_uint16_t_u_u(g_1171, 8))
                {
                    uint16_t l_2105 = 65535UL;

g_2431 += 1;


                    for (g_777 = 0; (g_777 != 38); ++g_777)
                    {
                        l_2061 = ((g_1171 < (safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((l_1671 < 0L), (l_1671 >= 0L))), (-1L)))) >= ((safe_lshift_func_uint8_t_u_u(((l_1698 || 252UL) , ((((safe_lshift_func_int8_t_s_s(l_2101, 7)) != 0L) == l_2182) , g_849[0])), l_2075)) >= l_2076));
                    }
                    for (l_2101 = (-27); (l_2101 <= (-28)); l_2101--)
                    {
                        uint32_t l_2102 = 0x75F47E93L;
                        g_120[2] = (safe_sub_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((l_2182 > l_1671), (safe_sub_func_uint8_t_u_u(((l_1698 & (g_1171 & ((((~((((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(l_2152, (((((safe_lshift_func_int8_t_s_s(((safe_mod_func_uint8_t_u_u((((0xDFF1L > ((safe_sub_func_int8_t_s_s((((+((!(((safe_lshift_func_int16_t_s_s(0xF854L, 8)) ^ g_1482[2][1][1]) ^ l_2182)) , g_120[4])) == 0UL) ^ g_100), g_1171)) , 1L)) , g_100) | g_2003[3]), g_849[0])) || 0x4AL), g_1171)) > g_1171) & g_97[3]) == l_2178[1]) , 0x821DL))), l_1671)) & 0xDCA8CE5FL) <= l_2040) > l_1698)) | l_1698) , g_1171) || l_1698))) , l_2076), 0x74L)))), g_2469));
                        l_2101 |= 9L;
                        l_2102 &= g_1171;
                    }
                    for (l_2076 = 7; (l_2076 >= (-7)); --l_2076)
                    {
                        uint32_t l_2108 = 0xCCCFDF72L;
                        l_2105 ^= l_1698;
                        g_120[2] = (((safe_rshift_func_uint8_t_u_u((((g_1482[2][1][3] , (((l_2108 | g_120[3]) == l_1671) , ((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint8_t_u_u(((0UL && g_2003[1]) || 1UL), ((safe_sub_func_uint8_t_u_u(((((safe_sub_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((g_1171 && (safe_lshift_func_uint8_t_u_s((0x24L >= 0UL), 0))), l_1671)), l_2121)) <= l_2040) & g_100) , l_1671), 1UL)) >= l_2108))) >= l_1698), 12)) >= (-1L)))) | g_97[2]) != g_1171), 2)) ^ 0xB68DD604L) == 0UL);
                    }

if ((g_2467 == 0xF331L))
            {
                uint32_t l_2075 = 0x3F7E974AL;
                int32_t l_2076 = 0xDD959D4BL;
                uint32_t l_2121 = 0xDB46FF94L;
                int32_t l_2135 = 0x8FD202FEL;
                int32_t l_2144 = 7L;
                int32_t l_2145 = 0x543A4A56L;
                int32_t l_2148 = (-7L);
                int32_t l_2150 = (-4L);
                for (g_2431 = 11; (g_2431 > 6); g_2431 = safe_sub_func_uint16_t_u_u(g_2431, 8))
                {
                    uint16_t l_2105 = 65535UL;
                    for (l_2075 = 0; (l_2075 != 38); ++l_2075)
                    {
                        l_1698 = ((g_1171 < (safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((l_2075 < 0L), (l_2075 >= 0L))), (-1L)))) >= ((safe_lshift_func_uint8_t_u_u(((l_2144 || 252UL) , ((((safe_lshift_func_int8_t_s_s(l_2137, 7)) != 0L) == g_101) , g_849[0])), l_2075)) >= l_2076));
                    }
                    for (l_1698 = (-27); (l_1698 <= (-28)); l_1698--)
                    {
                        uint32_t l_2102 = 0x75F47E93L;
                        g_120[2] = (safe_sub_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((g_101 > l_2075), (safe_sub_func_uint8_t_u_u(((l_2144 & (g_1171 & ((((~((((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(g_777, (((((safe_lshift_func_int8_t_s_s(((safe_mod_func_uint8_t_u_u((((0xDFF1L > ((safe_sub_func_int8_t_s_s((((+((!(((safe_lshift_func_int16_t_s_s(0xF854L, 8)) ^ g_1482[2][1][1]) ^ g_101)) , g_120[4])) == 0UL) ^ g_717), g_1171)) , 1L)) , g_717) | g_2003[3]), g_849[0])) || 0x4AL), g_1171)) > g_1171) & g_97[3]) == l_2178[1]) , 0x821DL))), l_2075)) & 0xDCA8CE5FL) <= l_2040) > l_2144)) | l_2144) , g_1171) || l_2144))) , l_2076), 0x74L)))), l_1694));
                        j |= 9L;
                        l_2102 &= g_1171;
                    }
                    for (l_2076 = 7; (l_2076 >= (-7)); --l_2076)
                    {
                        uint32_t l_2108 = 0xCCCFDF72L;
                        l_2105 ^= l_2144;
                        g_120[2] = (((safe_rshift_func_uint8_t_u_u((((g_1482[2][1][3] , (((l_2108 | g_120[3]) == l_2075) , ((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint8_t_u_u(((0UL && g_2003[1]) || 1UL), ((safe_sub_func_uint8_t_u_u(((((safe_sub_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((g_1171 && (safe_lshift_func_uint8_t_u_s((0x24L >= 0UL), 0))), l_2075)), l_2121)) <= l_2040) & g_100) , l_2075), 1UL)) >= l_2108))) >= l_2144), 12)) >= (-1L)))) | g_97[2]) != g_1171), 2)) ^ 0xB68DD604L) == 0UL);
                    }
                    l_2136 = (g_717 != (safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s((((-1L) || 0x95L) & l_2178[1]), ((safe_lshift_func_uint8_t_u_u(255UL, 7)) >= (((((safe_unary_minus_func_uint16_t_u(1UL)) , ((((l_2075 == ((l_2105 , (safe_sub_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(g_101, g_120[1])) , l_2177), g_2467))) == g_1171)) , 0x8847L) == g_101) , 0x73EDD688L)) == l_2144) , g_2467) < g_101)))), 8)));
                }
                l_2326++;
                l_2145 = ((((i , (g_1171 != g_1171)) || (0xADL && 0x61L)) < l_2075) < ((safe_lshift_func_uint16_t_u_s(0xD3B9L, (2UL < ((((0x7EC0L & g_120[1]) & 4294967295UL) || 1UL) & 0x5C680109L)))) == 0xC0DAL));
            }
            else
            {
                uint32_t l_2161 = 0x817ED328L;
                j |= (7L ^ (g_1171 > (((l_2105 < (g_1171 & ((safe_lshift_func_uint8_t_u_u(0x2CL, 3)) || (255UL >= g_1171)))) , g_1548[2][0][1]) == l_2161)));
                i = (safe_sub_func_uint32_t_u_u((g_2003[0] >= ((g_1171 >= (safe_add_func_int32_t_s_s(((((((safe_add_func_int8_t_s_s(((((safe_sub_func_int8_t_s_s(l_1694, (safe_sub_func_uint16_t_u_u(0xB24EL, ((((safe_mod_func_uint32_t_u_u(l_2322, ((((safe_sub_func_int32_t_s_s((0L == g_1368[0]), (0x17L && (g_717 , 0x38L)))) > l_2322) , 255UL) && g_777))) || 0x8F222FB3L) || 0xC79840FEL) ^ g_1171))))) < g_1171) , g_2431) > g_97[5]), 7UL)) < g_120[2]) , g_120[1]) & l_2055) <= l_2301) && g_18), g_1171))) && g_1171)), g_100));
            };


                    l_1693 = (g_100 != (safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s((((-1L) || 0x95L) & l_2178[1]), ((safe_lshift_func_uint8_t_u_u(255UL, 7)) >= (((((safe_unary_minus_func_uint16_t_u(1UL)) , ((((l_1671 == ((l_2105 , (safe_sub_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(l_2182, g_120[1])) , l_2039), l_2062))) == g_1171)) , 0x8847L) == l_2182) , 0x73EDD688L)) == l_1698) , l_2062) < l_2182)))), 8)));
                }
                l_2152++;
                l_2145 = ((((l_2151 , (l_2155 != g_1171)) || (0xADL && 0x61L)) < l_1671) < ((safe_lshift_func_uint16_t_u_s(0xD3B9L, (2UL < ((((0x7EC0L & g_120[1]) & 4294967295UL) || 1UL) & 0x5C680109L)))) == 0xC0DAL));
            }
            else
            {
                uint32_t l_2161 = 0x817ED328L;
                l_2101 |= (7L ^ (g_1171 > (((l_2158 < (g_1171 & ((safe_lshift_func_uint8_t_u_u(0x2CL, 3)) || (255UL >= g_1171)))) , g_1548[2][0][1]) == l_2161)));
                l_2151 = (safe_sub_func_uint32_t_u_u((g_2003[0] >= ((g_1171 >= (safe_add_func_int32_t_s_s(((((((safe_add_func_int8_t_s_s(((((safe_sub_func_int8_t_s_s(g_2469, (safe_sub_func_uint16_t_u_u(0xB24EL, ((((safe_mod_func_uint32_t_u_u(l_1671, ((((safe_sub_func_int32_t_s_s((0L == l_2176[0]), (0x17L && (g_100 , 0x38L)))) > l_1671) , 255UL) && l_2152))) || 0x8F222FB3L) || 0xC79840FEL) ^ g_1171))))) < g_1171) , g_1171) > g_97[5]), 7UL)) < g_120[2]) , g_120[1]) & l_2146) <= l_2301) && g_18), g_1171))) && g_1171)), g_100));
            }
            l_2185++;
            for (g_143 = 0; (g_143 <= 8); g_143 = safe_add_func_uint8_t_u_u(g_143, 6))
            {
                const int8_t l_2199 = (-1L);
                int32_t l_2255[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_2255[i] = 0L;
                for (g_1171 = 0; (g_1171 == 34); g_1171 = safe_add_func_uint8_t_u_u(g_1171, 3))
                {
                    int16_t l_2216 = 0x83C6L;
                    int32_t l_2249 = 0xEA87154FL;
                    int32_t l_2260 = 0xF84A0E45L;
                    int32_t l_2261 = 0xC424E530L;
                    uint16_t l_2263 = 65530UL;
                    for (g_2469 = 0; (g_2469 <= (-15)); g_2469 = safe_sub_func_uint32_t_u_u(g_2469, 1))
                    {
                        const uint8_t l_2200 = 0xE4L;
                        uint16_t l_2217 = 3UL;
                        l_2143[0] = (0UL >= ((l_2178[0] != (((safe_add_func_int16_t_s_s(((+(l_2176[0] && ((((0xEEL >= g_120[1]) && (+g_100)) || l_1671) > (((((~(l_1698 <= (l_2199 , 0L))) >= (-1L)) <= l_1698) , g_1171) , g_2467)))) > l_1671), l_2200)) | l_2200) , l_2182)) != g_97[5]));
                        g_120[1] = (safe_lshift_func_int8_t_s_u(((safe_mod_func_uint16_t_u_u(g_1171, (((l_2040 || (safe_unary_minus_func_int8_t_s(((safe_mod_func_int16_t_s_s((0L != ((safe_sub_func_uint32_t_u_u(0xF9EC49D5L, (safe_lshift_func_uint8_t_u_s(((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(((((-8L) && (0x53L || 1L)) < (l_2182 == (((0xAC9BL > l_1671) <= g_2467) >= l_1698))) , l_2216), 2)) && 0xE90C1C13L), 2L)) , l_2182) , 0UL) , l_2101), 7)))) , g_1171)), g_1171)) < g_101)))) != 0L) || l_2217))) > l_1698), 6));
                        g_120[1] &= l_2200;
                        if (g_100)
                            break;
                    }
                    if ((g_1482[2][1][1] & 0xDB81CA17L))
                    {
                        l_2181 = l_2176[0];
                        return l_1698;
                    }
                    else
                    {
                        if (g_1171)
                            break;
                    }
                    for (l_2137 = 2; (l_2137 >= 0); l_2137 -= 1)
                    {
                        int i;
                        l_2249 &= (((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((l_2183[l_2137] > (0L || (safe_rshift_func_uint8_t_u_u(l_2143[l_2137], (((g_849[0] | (((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(l_1698, 4)), 13)) , ((safe_unary_minus_func_int8_t_s(((safe_rshift_func_int16_t_s_u(l_2183[l_2137], ((safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(g_1171, 2)) , (safe_rshift_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((65535UL & ((((((((safe_mod_func_int8_t_s_s(l_2181, l_2182)) , 0x3DL) == g_1171) > 0xB5BB9598L) != l_2182) ^ 0L) || l_2158) <= 4294967291UL)), g_1171)) <= g_97[0]), 14))), l_2179)) != g_1171) != g_2467) & 0UL), g_1171)) != l_1698) || l_2158), 0x7D1913C8L)) <= l_2152))) ^ 0x99L))) | g_1171)) | 0x6BL)) || l_1671) & g_97[2]))))) ^ l_2143[l_2137]), l_1696[0])), 0xFB5B7956L)), 14)) < g_849[0]) , l_2199) <= l_1671), l_2325)) && l_1671) , 0x3F8D8182L);
                        g_101 ^= (l_2143[l_2137] && ((l_2152 , (safe_sub_func_int8_t_s_s((((0x01B30B9BL ^ (1UL | (safe_sub_func_int32_t_s_s(l_2199, (((g_120[4] , g_849[0]) ^ g_22) != l_2151))))) < 1UL) | 0x7EE96D31L), g_1171))) == g_2469));
                        l_2255[1] = (l_1671 != g_1171);
                    }
                    for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1)
                    {
                        int32_t l_2256 = 0x52D2483BL;
                        int32_t l_2257 = 1L;
                        int32_t l_2258[2][3];
                        int16_t l_2262 = 1L;
                        int i, j;
                        for (i = 0; i < 2; i++)
                        {

{
                        return l_1698;
                    }

                    for (j = 0; j < 3; j++)
                                l_2258[i][j] = 1L;
                        }
                        l_2101 = l_2178[l_2152];
                        l_2263--;
                        l_2260 &= (l_1671 == l_1698);
                        l_1693 = (safe_sub_func_int16_t_s_s(((g_1482[2][1][1] | ((5L || (g_1548[3][7][1] != (safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((0x76L & ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((l_2039 & (safe_lshift_func_uint16_t_u_u(((l_1671 & (0x5EL <= ((safe_add_func_int8_t_s_s(1L, (l_2178[0] >= 0x02L))) <= l_2256))) != g_694), 15))), l_2216)), g_1540[1][0])) < 0x866FL)) >= 0x9DEFCED1L), 0x570AL)), g_97[5])), l_2325)), l_1671)))) , l_2143[2])) ^ 0xAB2DL), 0UL));
                    }
                }
            }
        }
        else
        {
            int32_t l_2300[5][8] = {{0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}};
            int32_t l_2321 = (-1L);
            uint32_t l_2322 = 0x99FED06DL;
            int i, j;
            for (l_2158 = 0; (l_2158 <= 2); l_2158 += 1)
            {

if (g_694)
                    break;

                    g_120[1] = (safe_sub_func_int32_t_s_s(g_2469, 0x8EEC641FL));
                for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1)
                {
                    const int16_t l_2298 = 0x7AB4L;
                    if (l_1698)
                    {
                        int8_t l_2299 = 0xA2L;
                        g_120[4] = (safe_sub_func_uint32_t_u_u(g_2184[2][0], g_694));

p_11 += 1;


                    g_120[1] = ((safe_rshift_func_int8_t_s_u(l_1698, ((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((0x9CD8L && ((l_1671 != (1UL & (g_1171 , (safe_lshift_func_uint16_t_u_u((((l_1698 == (0x32DBL >= (0x73E61AD3L < l_2298))) || g_100) >= l_2299), 4))))) >= 65535UL)), g_2467)), l_1698)) && 0x6D137FB0L))) && 7L);
                        l_2301--;
                        g_2469 = ((((safe_add_func_uint8_t_u_u(0x92L, l_2152)) & (((((((safe_lshift_func_int16_t_s_u((((l_2300[3][1] & ((safe_rshift_func_uint8_t_u_u(247UL, (safe_mod_func_uint8_t_u_u(1UL, (safe_mul_func_int16_t_s_s((+g_2467), (g_1548[7][6][1] >= (safe_lshift_func_int8_t_s_u(l_2182, 0))))))))) || ((safe_sub_func_int32_t_s_s((((safe_lshift_func_int16_t_s_u((-1L), 11)) == 0x5DL) | l_2299), 4294967295UL)) , l_2300[4][1]))) <= g_2184[2][0]) | l_2300[3][6]), 14)) , (-7L)) , l_1698) != 0x6C7C71DBL) , g_18) , g_1548[4][6][2]) | g_2184[2][1])) == l_2141[1][6][5]) > g_1171);
                    }
                    else
                    {
                        return l_1671;
                    }
                }
                ++l_2322;
            }
        }
    }

                    for (l_2158 = 0; (l_2158 <= 2); l_2158 += 1)
            {
                g_120[1] = (safe_sub_func_int32_t_s_s(g_2100, 0x8EEC641FL));
                for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1)
                {
                    const int16_t l_2298 = 0x7AB4L;

{
                const int8_t l_2199 = (-1L);
                int32_t l_2255[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_2255[i] = 0L;
                for (g_59 = 0; (g_59 == 34); g_59 = safe_add_func_uint8_t_u_u(g_59, 3))
                {
                    int16_t l_2216 = 0x83C6L;
                    int32_t l_2249 = 0xEA87154FL;
                    int32_t l_2260 = 0xF84A0E45L;
                    int32_t l_2261 = 0xC424E530L;
                    uint16_t l_2263 = 65530UL;
                    for (g_2100 = 0; (g_2100 <= (-15)); g_2100 = safe_sub_func_uint32_t_u_u(g_2100, 1))
                    {
                        const uint8_t l_2200 = 0xE4L;
                        uint16_t l_2217 = 3UL;
                        g_1368[0] = (0UL >= ((g_1368[0] != (((safe_add_func_int16_t_s_s(((+(g_1368[0] && ((((0xEEL >= g_120[1]) && (+g_717)) || l_2322) > (((((~(k <= (l_2199 , 0L))) >= (-1L)) <= k) , g_59) , l_1671)))) > l_2322), l_2200)) | l_2200) , g_540)) != g_97[5]));

for (l_1549 = 0; l_1549 < 3; l_1549++)
                l_2178[l_1549] = (-1L);

                    g_120[1] = (safe_lshift_func_int8_t_s_u(((safe_mod_func_uint16_t_u_u(g_59, (((l_2040 || (safe_unary_minus_func_int8_t_s(((safe_mod_func_int16_t_s_s((0L != ((safe_sub_func_uint32_t_u_u(0xF9EC49D5L, (safe_lshift_func_uint8_t_u_s(((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(((((-8L) && (0x53L || 1L)) < (g_540 == (((0xAC9BL > l_2322) <= l_1671) >= k))) , l_2216), 2)) && 0xE90C1C13L), 2L)) , g_540) , 0UL) , g_2100), 7)))) , g_59)), g_59)) < g_540)))) != 0L) || l_2217))) > k), 6));

{

{
                g_143--;
            }

                    l_2322--;
            }

                    g_120[1] &= l_2200;
                        if (g_717)
                            break;
                    }
                    if ((g_1482[2][1][1] & 0xDB81CA17L))
                    {
                        l_1549 = g_1368[0];

if (l_2325) printf("index = [%d][%d]\n", g_2469, l_2260);

                    return k;
                    }
                    else
                    {

{
                        int i;
                        return g_120[g_59];
                    }

                    if (g_59)
                            break;
                    }

g_717 -= 1;


                    for (l_1648 = 2; (l_1648 >= 0); l_1648 -= 1)
                    {
                        int i;

for (g_100 = 0; (g_100 == 7); g_100 = safe_add_func_uint8_t_u_u(g_100, 6))
    {
        int16_t l_2039 = 0x0ABAL;
        const uint16_t l_2040 = 65532UL;
        int32_t l_2061 = 0x90A8BF10L;
        int32_t l_2101 = 0x02F00675L;
        int32_t l_2137 = 0L;
        int32_t l_2143[3];
        uint32_t l_2152 = 0xDB2A778AL;
        uint16_t l_2158 = 0xFEEFL;
        uint16_t l_2301 = 0xE812L;
        int i;
        for (i = 0; i < 3; i++)
            l_2143[i] = 0x4EA06463L;
        if ((safe_add_func_uint8_t_u_u(1UL, ((((1UL | ((g_2467 , ((g_849[0] , l_2039) != ((((l_2040 , (-9L)) <= 0x9EA7L) > p_12) , p_11))) <= g_100)) == l_1888[2]) || l_1698) ^ l_2039))))
        {
            uint32_t l_2062 = 4UL;
            int32_t l_2136 = 0x587994DEL;
            int32_t l_2138 = 0x39236B84L;
            int32_t l_2139 = 0x2CD995FBL;
            int32_t l_2140 = (-1L);
            int32_t l_2142 = 0x807412D1L;
            int32_t l_2146 = (-8L);
            int32_t l_2147 = (-7L);
            int32_t l_2149 = 0x0E72D148L;
            int32_t l_2151 = 0x4ECFBDFFL;
            uint8_t l_2155 = 0x86L;
            int32_t l_2176[3];
            int16_t l_2177 = 0x3603L;
            int32_t l_2179 = 1L;
            int32_t l_2180 = 1L;
            int32_t l_2181 = 0xDF8F0F9CL;
            int32_t l_2183[5] = {0x3D5D9951L, 0L, 0x3D5D9951L, 0L, 0x3D5D9951L};
            uint16_t l_2185 = 0x30E9L;
            int8_t l_2259[8] = {0xA3L, 0x43L, 0xA3L, 0x43L, 0xA3L, 0x43L, 0xA3L, 0x43L};
            int i;
            for (i = 0; i < 3; i++)
                l_2176[i] = (-1L);
            l_2061 = (safe_rshift_func_uint8_t_u_u(((((l_2039 , (safe_mod_func_int16_t_s_s((+((safe_sub_func_uint32_t_u_u((((safe_add_func_int8_t_s_s((0x9FB88B87L <= (g_1168 && l_2028)), ((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(g_120[4], (l_2325 | p_12))), ((safe_unary_minus_func_uint32_t_u((safe_mod_func_uint8_t_u_u((((((((safe_rshift_func_uint8_t_u_u(g_120[1], 3)) ^ 0L) < l_2039) && 0L) < g_1168) & 0xF6503CF8L) > p_11), p_11)))) , l_1696[0]))) , l_1888[2]))) == 1UL) , p_11), g_2100)) < 0x0C40299FL)), p_12))) || 0x6671L) && g_2254) < g_2254), 3));
            if ((l_2062 == 0xF331L))
            {
                uint32_t l_2075 = 0x3F7E974AL;
                int32_t l_2076 = 0xDD959D4BL;
                uint32_t l_2121 = 0xDB46FF94L;
                int32_t l_2135 = 0x8FD202FEL;
                int32_t l_2144 = 7L;
                int32_t l_2145 = 0x543A4A56L;
                int32_t l_2148 = (-7L);
                int32_t l_2150 = (-4L);
                for (g_59 = 11; (g_59 > 6); g_59 = safe_sub_func_uint16_t_u_u(g_59, 8))
                {
                    uint16_t l_2105 = 65535UL;
                    for (g_1168 = 0; (g_1168 != 38); ++g_1168)
                    {
                        l_2249 = ((p_12 < (safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((p_11 < 0L), (p_11 >= 0L))), (-1L)))) >= ((safe_lshift_func_uint8_t_u_u(((l_1698 || 252UL) , ((((safe_lshift_func_int8_t_s_s(l_2101, 7)) != 0L) == l_1726) , g_849[0])), l_2075)) >= l_2076));
                    }
                    for (l_2325 = (-27); (l_2325 <= (-28)); l_2325--)
                    {
                        uint32_t l_2102 = 0x75F47E93L;
                        g_120[2] = (safe_sub_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((l_1726 > p_11), (safe_sub_func_uint8_t_u_u(((l_1698 & (p_12 & ((((~((((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(g_1168, (((((safe_lshift_func_int8_t_s_s(((safe_mod_func_uint8_t_u_u((((0xDFF1L > ((safe_sub_func_int8_t_s_s((((+((!(((safe_lshift_func_int16_t_s_s(0xF854L, 8)) ^ g_1482[2][1][1]) ^ g_2254)) , g_120[4])) == 0UL) ^ g_100), p_12)) , 1L)) , g_89) | g_2003[3]), g_849[0])) || 0x4AL), p_12)) > p_12) & g_97[3]) == l_2178[1]) , 0x821DL))), p_11)) & 0xDCA8CE5FL) <= l_2040) > l_1698)) | l_1698) , p_12) || l_1698))) , l_2076), 0x74L)))), l_2249));
                        l_2101 |= 9L;
                        l_2102 &= p_12;
                    }
                    for (l_2076 = 7; (l_2076 >= (-7)); --l_2076)
                    {
                        uint32_t l_2108 = 0xCCCFDF72L;
                        l_2105 ^= l_1698;
                        g_120[2] = (((safe_rshift_func_uint8_t_u_u((((g_1482[2][1][3] , (((l_2108 | g_120[3]) == p_11) , ((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint8_t_u_u(((0UL && g_2003[1]) || 1UL), ((safe_sub_func_uint8_t_u_u(((((safe_sub_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((p_12 && (safe_lshift_func_uint8_t_u_s((0x24L >= 0UL), 0))), p_11)), l_2121)) <= l_2040) & g_100) , p_11), 1UL)) >= l_2108))) >= l_1698), 12)) >= (-1L)))) | g_97[2]) != p_12), 2)) ^ 0xB68DD604L) == 0UL);
                    }
                    l_1651 = (g_100 != (safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s((((-1L) || 0x95L) & l_2178[1]), ((safe_lshift_func_uint8_t_u_u(255UL, 7)) >= (((((safe_unary_minus_func_uint16_t_u(1UL)) , ((((p_11 == ((l_2105 , (safe_sub_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(g_2254, g_120[1])) , l_2039), l_2062))) == p_12)) , 0x8847L) == l_1726) , 0x73EDD688L)) == l_1698) , l_2062) < l_1726)))), 8)));
                }
                l_2152++;
                l_2145 = ((((l_2151 , (l_2155 != p_12)) || (0xADL && 0x61L)) < p_11) < ((safe_lshift_func_uint16_t_u_s(0xD3B9L, (2UL < ((((0x7EC0L & g_120[1]) & 4294967295UL) || 1UL) & 0x5C680109L)))) == 0xC0DAL));
            }
            else
            {
                uint32_t l_2161 = 0x817ED328L;
                l_2101 |= (7L ^ (p_12 > (((l_2158 < (p_12 & ((safe_lshift_func_uint8_t_u_u(0x2CL, 3)) || (255UL >= p_12)))) , g_1548[2][0][1]) == l_2161)));
                l_2151 = (safe_sub_func_uint32_t_u_u((g_2003[0] >= ((p_12 >= (safe_add_func_int32_t_s_s(((((((safe_add_func_int8_t_s_s(((((safe_sub_func_int8_t_s_s(l_2249, (safe_sub_func_uint16_t_u_u(0xB24EL, ((((safe_mod_func_uint32_t_u_u(g_1168, ((((safe_sub_func_int32_t_s_s((0L == l_2176[0]), (0x17L && (g_89 , 0x38L)))) > g_1168) , 255UL) && g_1168))) || 0x8F222FB3L) || 0xC79840FEL) ^ p_12))))) < p_12) , g_59) > g_97[5]), 7UL)) < g_120[2]) , g_120[1]) & l_2146) <= g_1217) && g_18), p_12))) && p_12)), g_100));
            }
            l_2185++;
            for (g_2467 = 0; (g_2467 <= 8); g_2467 = safe_add_func_uint8_t_u_u(g_2467, 6))
            {
                const int8_t l_2199 = (-1L);
                int32_t l_2255[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_2255[i] = 0L;
                for (g_59 = 0; (g_59 == 34); g_59 = safe_add_func_uint8_t_u_u(g_59, 3))
                {
                    int16_t l_2216 = 0x83C6L;
                    int32_t l_2249 = 0xEA87154FL;
                    int32_t l_2260 = 0xF84A0E45L;
                    int32_t l_2261 = 0xC424E530L;
                    uint16_t l_2263 = 65530UL;
                    for (l_2249 = 0; (l_2249 <= (-15)); l_2249 = safe_sub_func_uint32_t_u_u(l_2249, 1))
                    {
                        const uint8_t l_2200 = 0xE4L;
                        uint16_t l_2217 = 3UL;
                        l_2143[0] = (0UL >= ((l_2178[0] != (((safe_add_func_int16_t_s_s(((+(l_2176[0] && ((((0xEEL >= g_120[1]) && (+g_100)) || p_11) > (((((~(l_1698 <= (l_2199 , 0L))) >= (-1L)) <= l_1698) , g_59) , g_1168)))) > p_11), l_2200)) | l_2200) , l_1726)) != g_97[5]));
                        g_120[1] = (safe_lshift_func_int8_t_s_u(((safe_mod_func_uint16_t_u_u(p_12, (((l_2040 || (safe_unary_minus_func_int8_t_s(((safe_mod_func_int16_t_s_s((0L != ((safe_sub_func_uint32_t_u_u(0xF9EC49D5L, (safe_lshift_func_uint8_t_u_s(((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(((((-8L) && (0x53L || 1L)) < (l_1726 == (((0xAC9BL > p_11) <= g_1168) >= l_1698))) , l_2216), 2)) && 0xE90C1C13L), 2L)) , l_1726) , 0UL) , l_2101), 7)))) , p_12)), p_12)) < l_2039)))) != 0L) || l_2217))) > l_1698), 6));
                        g_120[1] &= l_2200;
                        if (g_100)
                            break;
                    }
                    if ((g_1482[2][1][1] & 0xDB81CA17L))
                    {
                        l_2181 = l_2176[0];
                        return l_1698;
                    }
                    else
                    {
                        if (p_12)
                            break;
                    }
                    for (l_2137 = 2; (l_2137 >= 0); l_2137 -= 1)
                    {
                        int i;
                        l_2249 &= (((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((l_2183[l_2137] > (0L || (safe_rshift_func_uint8_t_u_u(l_2143[l_2137], (((g_849[0] | (((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(l_1698, 4)), 13)) , ((safe_unary_minus_func_int8_t_s(((safe_rshift_func_int16_t_s_u(l_2183[l_2137], ((safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(p_12, 2)) , (safe_rshift_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((65535UL & ((((((((safe_mod_func_int8_t_s_s(l_2181, g_2254)) , 0x3DL) == p_12) > 0xB5BB9598L) != l_1726) ^ 0L) || l_2158) <= 4294967291UL)), g_59)) <= g_97[0]), 14))), l_2179)) != p_12) != g_1168) & 0UL), p_12)) != l_1698) || l_2158), 0x7D1913C8L)) <= l_2152))) ^ 0x99L))) | p_12)) | 0x6BL)) || p_11) & g_97[2]))))) ^ l_2143[l_2137]), l_1696[0])), 0xFB5B7956L)), 14)) < g_849[0]) , l_2199) <= p_11), l_2249)) && p_11) , 0x3F8D8182L);
                        l_2182 ^= (l_2143[l_2137] && ((g_1168 , (safe_sub_func_int8_t_s_s((((0x01B30B9BL ^ (1UL | (safe_sub_func_int32_t_s_s(l_2199, (((g_120[4] , g_849[0]) ^ l_2326) != l_2151))))) < 1UL) | 0x7EE96D31L), g_59))) == l_2249));
                        l_2255[1] = (p_11 != g_59);
                    }
                    for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1)
                    {
                        int32_t l_2256 = 0x52D2483BL;
                        int32_t l_2257 = 1L;
                        int32_t l_2258[2][3];
                        int16_t l_2262 = 1L;
                        int i, j;
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 3; j++)
                                l_2258[i][j] = 1L;
                        }
                        l_2101 = l_2178[l_2152];
                        l_2263--;
                        l_2260 &= (p_11 == l_1698);
                        l_1651 = (safe_sub_func_int16_t_s_s(((g_1482[2][1][1] | ((5L || (g_1548[3][7][1] != (safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((0x76L & ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((l_2039 & (safe_lshift_func_uint16_t_u_u(((p_11 & (0x5EL <= ((safe_add_func_int8_t_s_s(1L, (l_2178[0] >= 0x02L))) <= l_2256))) != g_694), 15))), l_2216)), g_1540[1][0])) < 0x866FL)) >= 0x9DEFCED1L), 0x570AL)), g_97[5])), l_2249)), p_11)))) , l_2143[2])) ^ 0xAB2DL), 0UL));
                    }
                }
            }
        }
        else
        {
            int32_t l_2300[5][8] = {{0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}};
            int32_t l_2321 = (-1L);
            uint32_t l_2322 = 0x99FED06DL;
            int i, j;
            for (l_2158 = 0; (l_2158 <= 2); l_2158 += 1)
            {
                g_120[1] = (safe_sub_func_int32_t_s_s(l_2249, 0x8EEC641FL));
                for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1)
                {
                    const int16_t l_2298 = 0x7AB4L;
                    if (l_1698)
                    {
                        int8_t l_2299 = 0xA2L;
                        g_120[4] = (safe_sub_func_uint32_t_u_u(g_2184[2][0], g_694));
                        g_120[1] = ((safe_rshift_func_int8_t_s_u(l_1698, ((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((0x9CD8L && ((p_11 != (1UL & (p_12 , (safe_lshift_func_uint16_t_u_u((((l_1698 == (0x32DBL >= (0x73E61AD3L < l_2298))) || g_100) >= l_2299), 4))))) >= 65535UL)), g_1168)), l_1698)) && 0x6D137FB0L))) && 7L);
                        l_2301--;
                        g_2100 = ((((safe_add_func_uint8_t_u_u(0x92L, l_2152)) & (((((((safe_lshift_func_int16_t_s_u((((l_2300[3][1] & ((safe_rshift_func_uint8_t_u_u(247UL, (safe_mod_func_uint8_t_u_u(1UL, (safe_mul_func_int16_t_s_s((+g_1168), (g_1548[7][6][1] >= (safe_lshift_func_int8_t_s_u(g_2254, 0))))))))) || ((safe_sub_func_int32_t_s_s((((safe_lshift_func_int16_t_s_u((-1L), 11)) == 0x5DL) | l_2299), 4294967295UL)) , l_2300[4][1]))) <= g_2184[2][0]) | l_2300[3][6]), 14)) , (-7L)) , l_1698) != 0x6C7C71DBL) , g_18) , g_1548[4][6][2]) | g_2184[2][1])) == l_2141[1][6][5]) > p_12);
                    }
                    else
                    {
                        return p_11;
                    }
                }
                ++l_2322;
            }
        }
    };


                    l_2249 &= (((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((g_120[l_1648] > (0L || (safe_rshift_func_uint8_t_u_u(g_1368[l_1648], (((g_849[0] | (((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(k, 4)), 13)) , ((safe_unary_minus_func_int8_t_s(((safe_rshift_func_int16_t_s_u(g_120[l_1648], ((safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(g_59, 2)) , (safe_rshift_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((65535UL & ((((((((safe_mod_func_int8_t_s_s(l_1549, g_2254)) , 0x3DL) == g_59) > 0xB5BB9598L) != g_540) ^ 0L) || l_2301) <= 4294967291UL)), g_59)) <= g_97[0]), 14))), g_2100)) != g_59) != l_1671) & 0UL), g_59)) != k) || l_2301), 0x7D1913C8L)) <= g_2467))) ^ 0x99L))) | g_59)) | 0x6BL)) || l_2322) & g_97[2]))))) ^ g_1368[l_1648]), l_1696[0])), 0xFB5B7956L)), 14)) < g_849[0]) , l_2199) <= l_2322), k)) && l_2322) , 0x3F8D8182L);
                        l_1726 ^= (g_1368[l_1648] && ((l_1671 , (safe_sub_func_int8_t_s_s((((0x01B30B9BL ^ (1UL | (safe_sub_func_int32_t_s_s(l_2199, (((g_120[4] , g_849[0]) ^ g_143) != l_2061))))) < 1UL) | 0x7EE96D31L), g_59))) == g_2100));

if (l_1693)
                    {
                        int8_t l_2299 = 0xA2L;
                        g_120[4] = (safe_sub_func_uint32_t_u_u(g_2184[2][0], l_2216));
                        g_120[1] = ((safe_rshift_func_int8_t_s_u(l_1693, ((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((0x9CD8L && ((g_2467 != (1UL & (g_1171 , (safe_lshift_func_uint16_t_u_u((((l_1693 == (0x32DBL >= (0x73E61AD3L < l_2298))) || g_717) >= l_2299), 4))))) >= 65535UL)), g_2467)), l_1693)) && 0x6D137FB0L))) && 7L);
                        g_2414--;
                        i = ((((safe_add_func_uint8_t_u_u(0x92L, g_2467)) & (((((((safe_lshift_func_int16_t_s_u((((l_2300[3][1] & ((safe_rshift_func_uint8_t_u_u(247UL, (safe_mod_func_uint8_t_u_u(1UL, (safe_mul_func_int16_t_s_s((+g_2467), (g_1548[7][6][1] >= (safe_lshift_func_int8_t_s_u(g_935, 0))))))))) || ((safe_sub_func_int32_t_s_s((((safe_lshift_func_int16_t_s_u((-1L), 11)) == 0x5DL) | l_2299), 4294967295UL)) , l_2300[4][1]))) <= g_2184[2][0]) | l_2300[3][6]), 14)) , (-7L)) , l_1693) != 0x6C7C71DBL) , g_18) , g_1548[4][6][2]) | g_2184[2][1])) == l_2141[1][6][5]) > g_1171);
                    }
                    else
                    {
                        return g_2467;
                    };



if (j)
                        break;

                    l_2255[1] = (l_2322 != g_59);
                    }

for (l_2249 = 0; l_2249 < 3; l_2249++)
    {
        transparent_crc(l_2178[l_2249], "l_2178[l_2249]", l_1698);
        if (l_1698) {
{
            for (l_2260 = 0; l_2260 < 3; l_2260++)
            {
                transparent_crc(g_1548[l_2061][l_2101][l_2260], "g_1548[l_2061][l_2101][l_2260]", l_2137);

l_2101 &= (g_1168 == l_1651);

                    if (l_2137) printf("index = [%d][%d][%d]\n", l_2061, l_2101, l_2260);

            }
        }


g_120[1] ^= ((0L & 0x37L) >= (safe_sub_func_uint16_t_u_u(1UL, ((((safe_lshift_func_int8_t_s_u((g_97[3] >= (safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s(((((((safe_lshift_func_uint16_t_u_s(((((0xC0653759L ^ l_1651) , l_2263) == (j != l_1698)) , 1UL), l_1698)) , 4L) , g_1168) || 0x464EEE5AL) | 8UL) & g_694), 5)) , 0x83F7DA68L) && g_18), 1UL))), 5)) <= g_59) < 65531UL) || p_11))));

                    printf("index = [%d]\n", l_2249);}

    };


                    for (g_2467 = 0; (g_2467 <= 2); g_2467 += 1)
                    {
                        int32_t l_2256 = 0x52D2483BL;
                        int32_t l_2257 = 1L;
                        int32_t l_2258[2][3];
                        int16_t l_2262 = 1L;
                        int i, j;
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 3; j++)
                                l_2258[i][j] = 1L;
                        }
                        g_2100 = g_1368[g_2467];
                        l_2263--;
                        l_2260 &= (l_2322 == k);

for (g_100 = 3; (g_100 >= 1); g_100 -= 1)
                    {
                        int i;
                        if (g_120[g_100])
                            break;
                        if (l_1888[g_100])
                            {
if (p_13)
                    {
                        int8_t l_2299 = 0xA2L;
                        g_120[4] = (safe_sub_func_uint32_t_u_u(g_2184[2][0], l_1726));
                        g_120[1] = ((safe_rshift_func_int8_t_s_u(p_13, ((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((0x9CD8L && ((g_2467 != (1UL & (g_59 , (safe_lshift_func_uint16_t_u_u((((p_13 == (0x32DBL >= (0x73E61AD3L < l_2298))) || g_717) >= l_2299), 4))))) >= 65535UL)), l_1671)), p_13)) && 0x6D137FB0L))) && 7L);
                        l_2158--;
                        l_1698 = ((((safe_add_func_uint8_t_u_u(0x92L, g_22)) & (((((((safe_lshift_func_int16_t_s_u((((l_2300[3][1] & ((safe_rshift_func_uint8_t_u_u(247UL, (safe_mod_func_uint8_t_u_u(1UL, (safe_mul_func_int16_t_s_s((+l_1671), (g_1548[7][6][1] >= (safe_lshift_func_int8_t_s_u(l_2182, 0))))))))) || ((safe_sub_func_int32_t_s_s((((safe_lshift_func_int16_t_s_u((-1L), 11)) == 0x5DL) | l_2299), 4294967295UL)) , l_2300[4][1]))) <= g_2184[2][0]) | l_2300[3][6]), 14)) , (-7L)) , p_13) != 0x6C7C71DBL) , g_18) , g_1548[4][6][2]) | g_2184[2][1])) == l_2141[1][6][5]) > g_59);
                    }
                    else
                    {
                        return g_2467;
                    };


                    break;}
                        return l_2182;
                    };


                    l_2055 = (safe_sub_func_int16_t_s_s(((g_1482[2][1][1] | ((5L || (g_1548[3][7][1] != (safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((0x76L & ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((g_540 & (safe_lshift_func_uint16_t_u_u(((l_2322 & (0x5EL <= ((safe_add_func_int8_t_s_s(1L, (g_1368[0] >= 0x02L))) <= l_2256))) != l_1726), 15))), l_2216)), g_1540[1][0])) < 0x866FL)) >= 0x9DEFCED1L), 0x570AL)), g_97[5])), k)), l_2322)))) , g_1368[2])) ^ 0xAB2DL), 0UL));
                    }
                }
            }

                    if (p_13)
                    {
                        int8_t l_2299 = 0xA2L;
                        g_120[4] = (safe_sub_func_uint32_t_u_u(g_2184[2][0], g_694));
                        g_120[1] = ((safe_rshift_func_int8_t_s_u(p_13, ((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((0x9CD8L && ((p_11 != (1UL & (p_12 , (safe_lshift_func_uint16_t_u_u((((p_13 == (0x32DBL >= (0x73E61AD3L < l_2298))) || g_100) >= l_2299), 4))))) >= 65535UL)), g_143)), p_13)) && 0x6D137FB0L))) && 7L);

if (g_2254)
                            break;

                    l_2301--;
                        l_1648 = ((((safe_add_func_uint8_t_u_u(0x92L, l_2152)) & (((((((safe_lshift_func_int16_t_s_u((((l_2300[3][1] & ((safe_rshift_func_uint8_t_u_u(247UL, (safe_mod_func_uint8_t_u_u(1UL, (safe_mul_func_int16_t_s_s((+g_143), (g_1548[7][6][1] >= (safe_lshift_func_int8_t_s_u(g_540, 0))))))))) || ((safe_sub_func_int32_t_s_s((((safe_lshift_func_int16_t_s_u((-1L), 11)) == 0x5DL) | l_2299), 4294967295UL)) , l_2300[4][1]))) <= g_2184[2][0]) | l_2300[3][6]), 14)) , (-7L)) , p_13) != 0x6C7C71DBL) , g_18) , g_1548[4][6][2]) | g_2184[2][1])) == l_2141[1][6][5]) > p_12);
                    }
                    else
                    {

{
        transparent_crc(g_2003[l_2061], "g_2003[l_2061]", k);
        if (k) printf("index = [%d]\n", l_2061);

    }

                    return p_11;
                    }
                }

for (l_2061 = 0; l_2061 < 8; l_2061++)
        {
            for (i = 0; i < 3; i++)
            {
                transparent_crc(g_1548[l_2055][l_2061][i], "g_1548[l_2055][l_2061][i]", l_2061);
                if (l_2061) printf("index = [%d][%d][%d]\n", l_2055, l_2061, i);

            }
        };


                    ++l_2322;
            }
        }
    }
    l_2326--;
    l_1651 = (safe_mod_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s((((safe_lshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s(l_1651, ((p_13 != 0xD257L) == (safe_sub_func_uint8_t_u_u((((safe_lshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s(((g_694 | ((safe_add_func_uint8_t_u_u(l_1651, ((((p_13 == (!(((!(~0xA2B5L)) || (g_694 != p_11)) , 0xBE0E0ABDL))) , l_2028) == 0x154C94FDL) <= 0xDCE7L))) & l_1695)) == g_1368[0]), p_11)), p_13)) > 0x8806C5F6L) > p_12), p_12))))), g_717)) | p_13) & l_1651), 0xD3L)) , g_97[2]), p_12));
                                        while ((l_1726>6363) )
{

g_1171 += 1;


}
                    return l_1671;
}







static int32_t func_19(int16_t p_20)
{
    uint32_t l_21 = 8UL;
    g_22 = l_21;
    g_1482[2][1][1] |= (safe_rshift_func_uint16_t_u_s(p_20, func_25(l_21)));
    return p_20;
}







static int16_t func_25(uint16_t p_26)
{
    uint32_t l_27 = 4294967294UL;
    l_27 = 0x31AA08ECL;
    g_120[1] = (0x0415L > ((func_28((l_27 , (safe_mod_func_int16_t_s_s(func_33((safe_mod_func_int32_t_s_s(((func_38((l_27 < g_22), ((safe_lshift_func_int16_t_s_u(1L, 3)) , (((((p_26 && func_46(((((safe_lshift_func_uint8_t_u_u(0UL, (func_54((0x373CL && (0x7530L < 2UL)), p_26, p_26, l_27) >= g_18))) == g_22) >= 0xD45AA775L) > l_27), p_26, p_26, g_18, l_27)) != p_26) < p_26) != 0xE6DB759FL) != g_22)), l_27, g_22, l_27) ^ p_26) != p_26), 0xDA6413EFL)), p_26), g_18))), p_26) ^ 5UL) == g_1168));
    for (g_59 = 26; (g_59 == 51); g_59++)
    {
        uint8_t l_1466 = 254UL;
        int32_t l_1481 = 7L;
        g_120[1] = l_1466;
        l_1481 = (((g_97[2] > p_26) | (safe_add_func_uint8_t_u_u(0x65L, ((!((safe_rshift_func_int8_t_s_s(((0x0584L < (l_1466 && (safe_lshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s((((!(p_26 , ((safe_mod_func_uint8_t_u_u(l_1466, g_22)) , (safe_sub_func_int8_t_s_s((0xCDL > g_694), 0xCFL))))) < 255UL) < 0xB6L), l_1466)), p_26)))) , 0x19L), l_1466)) > 0xBFD8L)) == 0UL)))) >= l_27);
    }
    return p_26;
}







static int16_t func_28(int32_t p_29, int32_t p_30)
{
    int32_t l_1461 = 1L;
    int16_t l_1462[7][1];
    int i, j;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 1; j++)
            { int16_t BCoCog_101 = (~((((-(l_1461)) | g_22) / (~(((~((g_777 / g_540))) || g_101))))));
int32_t BCoCobl_1461 = (~((((~((~(g_101)))) ^ (-(((g_540 & (~(BCoCog_101))) || (~(g_777)))))) % (~((l_1461 << g_22))))));
int16_t BCoCocg_540 = (~(((((BCoCog_101 & (~(BCoCobl_1461))) || g_540) - (~(l_1461))) || (-((-(((~(g_777)) | (g_101 - g_22)))))))));
uint32_t BCoCodg_22 = (~((g_101 + (((g_540 - BCoCog_101) & g_22) % ((g_777 | BCoCobl_1461) && (BCoCocg_540 || l_1461))))));
uint32_t BCoCoeg_777 = (-((((~(((-(BCoCocg_540)) || (~((g_540 | g_777)))))) + (-(BCoCog_101))) - ((-(((~((BCoCobl_1461 && l_1461))) || (g_101 ^ (-(BCoCodg_22)))))) - (-(g_22))))));
                                   if (g_540)
          if((g_22>=8U)){
BCoCog_101 = g_101;
BCoCobl_1461 = l_1461;
BCoCocg_540 = g_540;
BCoCodg_22 = g_22;
BCoCoeg_777 = g_777;
g_101 = (~(((~(((-(BCoCocg_540)) | ((~(((l_1461 & (g_22 && BCoCodg_22)) - (~(BCoCog_101))))) || g_777)))) + ((-((~((~((BCoCobl_1461 / (g_101 | BCoCoeg_777)))))))) % (-((~((~((~(g_540))))))))))));
l_1461 = (~((((((-(l_1461)) | (g_777 ^ BCoCoeg_777)) ^ (BCoCog_101 | BCoCobl_1461)) / (~(g_540))) % ((~((g_101 && (~(BCoCocg_540))))) & (~((g_22 || (~(BCoCodg_22)))))))));
g_540 = (~(((~((~(((g_101 - BCoCog_101) | BCoCodg_22))))) >> (((~((g_22 & g_777))) && (~((l_1461 ^ (~(g_540)))))) + (~((~(((BCoCocg_540 | (-((~((~(BCoCobl_1461))))))) && BCoCoeg_777)))))))));
                                    while (((l_1461<=-5) && (g_22>8U)) )
{

{
        for (j = 0; j < 3; j++)
        {
            for (p_29 = 0; p_29 < 4; p_29++)
            {
                transparent_crc(g_1482[BCoCobl_1461][j][p_29], "g_1482[BCoCobl_1461][j][p_29]", i);
                if (i) printf("index = [%d][%d][%d]\n", BCoCobl_1461, j, p_29);

            }
        }
    }

}
          g_22 = (-((((-(g_22)) + ((((BCoCog_101 / g_540) + l_1461) || BCoCodg_22) + BCoCocg_540)) || (~((((BCoCobl_1461 || g_101) || g_777) | (-(BCoCoeg_777))))))));
g_777 = (~(((((BCoCog_101 / (~(BCoCobl_1461))) && g_777) - (BCoCodg_22 & BCoCocg_540)) || (~(((g_540 && (~(BCoCoeg_777))) | ((g_101 + l_1461) && g_22)))))));
                               uint32_t BHoHog_22 = (~((l_1461 | ((g_777 || (~((~((g_22 ^ g_540)))))) || g_101))));
int32_t BHoHobl_1461 = (~(((~((~((g_22 ^ (~(g_101))))))) && (~((((g_540 || g_777) || l_1461) >> (~((~(BHoHog_22))))))))));
int16_t BHoHocg_101 = (~(((~((g_101 / (~(g_777))))) << ((~(((l_1461 ^ BHoHobl_1461) | BHoHog_22))) && (g_22 | g_540)))));
int16_t BHoHodg_540 = (~(((~(((~((g_101 & g_22))) - ((~((~(g_540)))) || ((BHoHog_22 && (~((BHoHocg_101 || BHoHobl_1461)))) ^ l_1461))))) | (~((~(g_777)))))));
uint32_t BHoHoeg_777 = (~((((~((BHoHobl_1461 && BHoHocg_101))) / (l_1461 ^ g_777)) || (((BHoHodg_540 & g_101) / g_540) & (~((g_22 | BHoHog_22)))))));
if(g_540){
BHoHog_22 = g_22;
                                   if ((g_22 > g_777))
          LABEL_HoHof: BHoHobl_1461 = l_1461;
BHoHocg_101 = g_101;
BHoHodg_540 = g_540;
                               int32_t BPoPogl_1461 = (~((((g_540 - g_101) ^ g_22) << (l_1461 || (-((-(g_777))))))));
uint32_t BPoPohg_777 = (~(((g_101 | (g_540 || (~(BPoPogl_1461)))) || ((l_1461 * g_22) | g_777))));
int16_t BPoPoig_540 = (~(((((l_1461 ^ g_101) & BPoPohg_777) - (~((g_540 - (BPoPogl_1461 | g_777))))) - g_22)));
uint32_t BPoPojg_22 = (~(((~((((BPoPogl_1461 | BPoPoig_540) - g_101) & ((g_22 | g_540) || (-((~(l_1461)))))))) * ((~((-(BPoPohg_777)))) * (~(g_777))))));
int16_t BPoPokg_101 = (~(((~((~((~(((-(BPoPojg_22)) & (((BPoPoig_540 | g_22) - g_101) | (~((-(BPoPogl_1461)))))))))))) | (~((~(((~((-((l_1461 | BPoPohg_777))))) & ((~(g_777)) ^ g_540)))))))));
if(((BPoPojg_22<=4294967292U) && (g_540 < BPoPokg_101))){
BPoPogl_1461 = l_1461;
LABEL_PoPol: BPoPohg_777 = g_777;
BPoPoig_540 = g_540;
BPoPojg_22 = g_22;
BPoPokg_101 = g_101;
l_1461 = (~(((-(((~(BPoPogl_1461)) * BPoPohg_777))) | (((~(g_777)) || ((-((BPoPojg_22 ^ g_22))) | BPoPoig_540)) ^ (((l_1461 & BPoPokg_101) ^ (~(g_540))) ^ g_101)))));
g_777 = (~(((BPoPohg_777 - BPoPoig_540) - (((g_540 || BPoPojg_22) & (l_1461 & g_101)) & (BPoPogl_1461 ^ (-((~(((BPoPokg_101 >> (~(g_22))) * g_777))))))))));
g_540 = (~(((BPoPoig_540 & ((-(((~((g_777 ^ ((g_101 || BPoPokg_101) ^ g_22)))) * l_1461))) ^ (g_540 || (-((BPoPohg_777 - BPoPojg_22)))))) - (~(BPoPogl_1461)))));
g_22 = (-(((((~(BPoPojg_22)) * g_22) - (~((~(((BPoPokg_101 * BPoPohg_777) | (g_101 ^ (l_1461 & (BPoPogl_1461 | g_540))))))))) || (BPoPoig_540 || g_777))));
g_101 = (-(((-((~((BPoPokg_101 - g_777))))) | (((~((~(((BPoPohg_777 || g_101) ^ (~((~(BPoPogl_1461))))))))) ^ (BPoPoig_540 * (~(l_1461)))) | (g_22 | (BPoPojg_22 & (~(g_540))))))));
if(!(BPoPoig_540)){
printf("g_540=%lld\n", (long long)g_540);
g_777 = (~(((-((g_777 | BPoPojg_22))) || ((((-((BPoPokg_101 & (~((BPoPohg_777 || (~(BPoPoig_540)))))))) & g_540) & (BPoPogl_1461 & (g_101 * g_22))) || (~(l_1461))))));
}
if(((g_101 && (l_1461 < BPoPokg_101)) && (!g_101))){
printf("g_22=%llu\n", (unsigned long long)g_22);
g_540 = (~((((g_101 - ((~(((-(BPoPohg_777)) << BPoPokg_101))) & (g_777 & (BPoPoig_540 >> (BPoPogl_1461 | (~(g_540))))))) ^ (BPoPojg_22 << l_1461)) ^ (-(g_22)))));
g_777 = (~((((BPoPohg_777 || g_777) || (-((~(l_1461))))) * (((-(g_101)) * ((-(BPoPokg_101)) << BPoPoig_540)) - ((g_540 * (~(g_22))) >> (BPoPogl_1461 - BPoPojg_22))))));
continue;
}
if((g_101 && (!g_22))){
printf("g_101=%lld\n", (long long)g_101);
goto LABEL_HoHof;
}
}
l_1461 = BPoPogl_1461;
g_777 = BPoPohg_777;
g_540 = BPoPoig_540;
g_22 = BPoPojg_22;
g_101 = BPoPokg_101;

          BHoHoeg_777 = g_777;
g_22 = (~(((~((l_1461 | g_22))) & (~(((((~((~((~(g_540)))))) - ((~((BHoHobl_1461 / BHoHog_22))) || g_777)) - g_101) && (((~(BHoHocg_101)) / (~(BHoHodg_540))) | BHoHoeg_777)))))));
l_1461 = (~((((BHoHodg_540 / g_22) && l_1461) / ((BHoHoeg_777 & (g_101 - (g_777 & g_540))) || ((~((~(((~(BHoHocg_101)) ^ BHoHobl_1461))))) - BHoHog_22)))));
                                    if (!((g_22 > g_777)) )
{

for (BHoHobl_1461 = 0; BHoHobl_1461 < 7; BHoHobl_1461++)
    {
        for (g_2469 = 0; g_2469 < 1; g_2469++)
            l_1462[BHoHobl_1461][g_2469] = 0L;
    };


}
          g_101 = (~((((~((~(((g_101 / (g_540 & g_777)) ^ BHoHobl_1461))))) - (BHoHog_22 / (~((~(((~(l_1461)) - BHoHodg_540))))))) - (~((~((((~(BHoHoeg_777)) || g_22) ^ (~((~(BHoHocg_101))))))))))));
g_540 = (~(((((~(l_1461)) ^ (~((BHoHobl_1461 && (BHoHodg_540 & g_101))))) ^ (~((BHoHocg_101 || (~(g_22)))))) & ((g_540 / (g_777 - BHoHog_22)) - (~(BHoHoeg_777))))));
g_777 = (~((((~((BHoHocg_101 || ((~(BHoHodg_540)) - l_1461)))) / ((((~(g_777)) | BHoHoeg_777) - (~(BHoHog_22))) || g_22)) && (g_540 && ((~(BHoHobl_1461)) || g_101)))));
if(((!g_777) || (!BHoHodg_540))){
printf("g_22=%llu\n", (unsigned long long)g_22);
goto LABEL_HoHof;
}
if((BHoHoeg_777 > BHoHog_22)){
printf("l_1461=%lld\n", (long long)l_1461);
break;
}
if(((BHoHobl_1461 > BHoHocg_101) || (g_777>4294967294U))){
printf("g_101=%lld\n", (long long)g_101);
break;
}
if(!(!((!BHoHobl_1461)))){
printf("g_540=%lld\n", (long long)g_540);
continue;
}
if((g_540 && (BHoHog_22 < g_777))){

g_101 += 1;


          printf("g_777=%llu\n", (unsigned long long)g_777);
g_777 = (~(((~(BHoHocg_101)) - ((~((~(g_101)))) ^ ((~((~(((~(BHoHoeg_777)) & (g_540 << ((~(BHoHog_22)) >> g_777))))))) & ((l_1461 / BHoHobl_1461) ^ (~((BHoHodg_540 >> g_22)))))))));
continue;
}
}
g_22 = BHoHog_22;
l_1461 = BHoHobl_1461;
g_101 = BHoHocg_101;
                                    while ((g_22>4294967295U) )
{

g_2431 += 1;


}
          g_540 = BHoHodg_540;
                                   if ((g_22<=4294967295U))
          g_777 = BHoHoeg_777;

          if((((g_101<=6413) && (!BCoCobl_1461)) && !((g_22<4294967295U)))){
printf("l_1461=%lld\n", (long long)l_1461);
g_777 = (~((((-(((BCoCocg_540 || ((g_101 || (BCoCobl_1461 << BCoCog_101)) >> g_777)) && BCoCodg_22))) | (-(g_540))) - ((l_1461 && (~(BCoCoeg_777))) && (-(g_22))))));
l_1461 = (-((((-((~(((~((-(BCoCocg_540)))) / g_22))))) && (~((((~(g_777)) << (-(((g_540 << BCoCobl_1461) % BCoCoeg_777)))) & (~(g_101)))))) + (l_1461 / (~(((~(BCoCodg_22)) / BCoCog_101)))))));
}
if((BCoCodg_22>8U)){

for (i = 0; i < 4; i++)
            {

for (p_29 = 0; p_29 < 3; p_29++)
            g_1368[p_29] = 0x4EA06463L;

          transparent_crc(g_1482[l_1461][i][i], "g_1482[l_1461][i][i]", i);
                if (i) printf("index = [%d][%d][%d]\n", l_1461, i, i);

            };


          printf("g_777=%llu\n", (unsigned long long)g_777);
BCoCodg_22 = (~((((~((-(l_1461)))) | ((~((~((BCoCog_101 >> ((~(BCoCobl_1461)) || g_540)))))) | (-(((g_22 - (g_101 | BCoCodg_22)) & ((-(BCoCoeg_777)) || g_777)))))) - (~(BCoCocg_540)))));
break;
}
}
g_101 = BCoCog_101;
l_1461 = BCoCobl_1461;
g_540 = BCoCocg_540;
g_22 = BCoCodg_22;
                                    if ((!g_777) )
{

{
                    for (g_100 = 0; (g_100 <= 5); g_100 += 1)
                    {
                        return p_30;
                    }
                    return g_120[1];
                }

}
          g_777 = BCoCoeg_777;

          l_1462[i][j] = 0L;}
    }
    for (g_101 = 10; (g_101 == (-12)); g_101 = safe_sub_func_uint8_t_u_u(g_101, 9))
    {
        uint32_t l_1447 = 0xDBB284DBL;
        int32_t l_1463 = 0xE4B3772FL;
        l_1463 |= ((safe_mod_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s(((l_1447 != (safe_add_func_int8_t_s_s(((((safe_mod_func_uint16_t_u_u(((l_1447 >= (safe_add_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s((g_540 > (safe_add_func_uint8_t_u_u(g_22, (0x5103L >= (safe_mul_func_uint32_t_u_u((((+l_1447) && g_777) , l_1461), (0L == 0xFFC0EF70L))))))), 4)) > g_97[2]), p_29))) & p_30), p_30)) < p_29) && 255UL) < 8L), g_540))) , 0x1C47L), l_1461)), l_1462[4][0])) != l_1462[0][0]);
    }
                                                                           while ((!g_540) )
{

p_30 &= (safe_mod_func_uint32_t_u_u(g_694, 0xE4729DD1L));

}
          if (g_540)
          return p_29;
}







static int16_t func_33(uint32_t p_34, int16_t p_35)
{
    int8_t l_725[4] = {0x6CL, (-1L), 0x6CL, (-1L)};
    int32_t l_778 = 0L;
    int8_t l_790 = 0xCFL;
    int32_t l_793 = (-10L);
    uint32_t l_877[3][1];
    int8_t l_880 = 0x4CL;
    int32_t l_919 = 0x24F96B7BL;
    int32_t l_922 = 1L;
    uint32_t l_940[8] = {0x70725F80L, 0x971E3B31L, 0x70725F80L, 0x971E3B31L, 0x70725F80L, 0x971E3B31L, 0x70725F80L, 0x971E3B31L};
    uint32_t l_980 = 0xC75D6C4FL;
    uint8_t l_1007 = 0x6CL;
    uint32_t l_1052 = 0xC1E7B1A1L;
    int8_t l_1191[5] = {(-3L), 2L, (-3L), 2L, (-3L)};
    uint32_t l_1281 = 0x7B51DD50L;
    int32_t l_1327 = 0xC40777EBL;
    int32_t l_1329 = 0x90371E5EL;
    uint32_t l_1423 = 0UL;
    uint32_t l_1433 = 18446744073709551615UL;
    int32_t l_1439[6];
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 1; j++)
            l_877[i][j] = 0x46984ABCL;
    }
                                        while ((!g_777) )
{

{
            transparent_crc(g_2184[l_1327][l_778], "g_2184[l_1327][l_778]", l_1329);
            if (l_1329) printf("index = [%d][%d]\n", l_1327, l_778);

        }

}
                    for (i = 0; i < 6; i++)
        l_1439[i] = 9L;
    for (g_59 = 0; (g_59 != 4); ++g_59)
    {
        uint8_t l_722 = 0xE0L;
        int32_t l_770 = 0x6E81370EL;
        uint32_t l_779 = 1UL;
        int32_t l_792 = 0x2E89F638L;
        if ((safe_lshift_func_int16_t_s_u((p_35 <= l_722), (safe_sub_func_int8_t_s_s(((l_725[2] <= ((((safe_sub_func_int32_t_s_s(g_22, (safe_mod_func_uint32_t_u_u((0x7ABE5FAFL >= ((safe_sub_func_uint8_t_u_u(g_120[1], l_722)) , ((safe_lshift_func_int8_t_s_u(l_722, (((((((safe_lshift_func_int8_t_s_s(g_22, 3)) | l_725[2]) || g_89) >= p_35) <= g_97[5]) , l_722) >= 4294967295UL))) == g_694))), l_725[2])))) >= p_35) ^ 0UL) != 8L)) ^ 0x0968FE10L), p_34)))))
        {
            uint32_t l_749 = 4294967288UL;
            if ((~(safe_add_func_uint32_t_u_u(((0L != (((l_725[2] || (safe_sub_func_int8_t_s_s(0x65L, (safe_mod_func_uint32_t_u_u(p_34, l_722))))) ^ ((safe_add_func_uint16_t_u_u((g_717 , (safe_lshift_func_int8_t_s_u((0xA7L & 6L), 0))), (((p_35 == g_143) >= g_18) < g_101))) < (-1L))) < p_35)) , 0x11329388L), 4294967295UL))))
            {
                int32_t l_769[1];
                int i;
                for (i = 0; i < 1; i++)
                    l_769[i] = 0x804970A5L;
                g_120[1] = 1L;
                if (p_35)
                    continue;
                l_749 = (safe_rshift_func_uint16_t_u_u(g_97[2], 13));
                l_770 = (safe_lshift_func_int8_t_s_s((5UL >= (0UL < (safe_add_func_int8_t_s_s((((safe_rshift_func_int16_t_s_s((g_18 != (safe_sub_func_int32_t_s_s((safe_unary_minus_func_int32_t_s((safe_mod_func_int8_t_s_s((safe_mod_func_int32_t_s_s(0x5B48709BL, ((safe_rshift_func_int16_t_s_s(g_18, p_35)) || 3L))), (safe_sub_func_int32_t_s_s(g_694, ((((safe_rshift_func_int16_t_s_u(p_35, 7)) || g_18) || l_769[0]) <= p_34))))))), g_22))), 6)) != p_35) != g_100), l_722)))), p_34));
            }
            else
            {
                int16_t l_775 = (-4L);
                int32_t l_776 = (-3L);

for (l_793 = 0; l_793 < 10; l_793++)
            {
                transparent_crc(g_2470[l_922][l_922][l_793], "g_2470[l_922][l_922][l_793]", g_2100);
                if (g_2100) {
{
                        int32_t l_1358 = 0x27225A3DL;
                        --g_1171;
                        if (l_1052)
                            break;
                    }

                    printf("index = [%d][%d][%d]\n", l_922, l_922, l_793);}

            }
if (l_749)
                        break;

                    ;


                    g_777 = ((((g_143 ^ (l_725[2] , (0xB43536D7L > 0x43474B68L))) >= (((g_18 < ((safe_add_func_int8_t_s_s(l_722, 0xFAL)) & (safe_mod_func_int8_t_s_s(((((((l_775 | l_776) || g_101) || g_89) , p_34) <= 6L) <= 0x62L), 0x36L)))) && g_143) > 0x8EL)) != p_34) == p_34);
            }
            --l_779;
        }
        else
        {
            int16_t l_786 = 8L;
            int32_t l_789 = 2L;
            int32_t l_791 = 0xB2B08DC3L;
            uint32_t l_794 = 0x67A078F5L;

for (g_1171 = 0; (g_1171 <= 4); g_1171 += 1)
                    {
                        int i;
                        return g_120[g_1171];
                    };


                    l_778 = (safe_rshift_func_int16_t_s_u(g_717, 9));


for (g_2431 = 26; (g_2431 == 51); g_2431++)
    {
        uint8_t l_1466 = 254UL;
        int32_t l_1481 = 7L;
        g_120[1] = l_1466;
        l_1481 = (((g_97[2] > g_1217) | (safe_add_func_uint8_t_u_u(0x65L, ((!((safe_rshift_func_int8_t_s_s(((0x0584L < (l_1466 && (safe_lshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s((((!(g_1217 , ((safe_mod_func_uint8_t_u_u(l_1466, l_1281)) , (safe_sub_func_int8_t_s_s((0xCDL > g_540), 0xCFL))))) < 255UL) < 0xB6L), l_1466)), g_1217)))) , 0x19L), l_1466)) > 0xBFD8L)) == 0UL)))) >= l_794);
    };


                    if (p_34)
                    {
if ((l_1281 == g_540))
    {
        int16_t l_801[8][10] = {{0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}};
        int32_t l_821[9][7] = {{0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}};
        uint32_t l_843 = 4294967290UL;
        int32_t l_1046 = 0x07FD8AA4L;
        int i, j;
        for (g_2467 = 0; (g_2467 > 15); ++g_2467)
        {

g_120[1] ^= (safe_add_func_uint32_t_u_u(i, l_1046));

                    g_120[1] = 0x19D1A3FEL;
            if (l_786)
                continue;
        }
        for (l_793 = 0; (l_793 <= 24); l_793 = safe_add_func_uint16_t_u_u(l_793, 2))
        {
            int32_t l_820 = (-1L);
            const int32_t l_844 = 1L;
            int32_t l_846 = 0xEFBA0CA9L;
            int32_t l_848 = 0x52FBE6A1L;
            uint32_t l_885 = 2UL;
            int32_t l_936[2][6] = {{0L, 0L, (-3L), 0L, 0L, (-3L)}, {0L, 0L, (-3L), 0L, 0L, (-3L)}};
            int i, j;
            l_801[7][5] = l_786;
            for (l_779 = 0; (l_779 <= 7); l_779 += 1)
            {
                int i, j;
                g_120[3] = l_801[l_779][l_779];
                l_821[6][1] = (safe_rshift_func_uint8_t_u_s((safe_lshift_func_uint8_t_u_u((g_97[2] , (safe_lshift_func_int16_t_s_u((((safe_rshift_func_int16_t_s_u((safe_add_func_uint8_t_u_u((4294967286UL != 0x9CDCB11EL), ((l_801[l_779][l_779] ^ (g_100 == (safe_mod_func_int16_t_s_s(((((2UL | (safe_mod_func_int8_t_s_s((l_1281 || ((safe_add_func_int16_t_s_s((g_97[2] , (0x978C1B61L > 4294967291UL)), l_820)) < 0xB988L)), l_1281))) || l_790) >= l_786) == 0x1F887AC6L), l_1281)))) > 6UL))), 6)) != l_786) <= l_801[7][5]), l_786))), 3)), l_801[7][5]));
            }
            if ((0x4DF543CEL && l_790))
            {
                uint32_t l_847 = 0xB97BAC9CL;
                for (g_100 = 0; (g_100 >= (-10)); g_100--)
                {
                    const uint32_t l_845 = 0xB19552AFL;
                    l_846 = (((safe_sub_func_int8_t_s_s(0x65L, (safe_unary_minus_func_int8_t_s((+(g_97[2] < (safe_add_func_uint32_t_u_u(((safe_rshift_func_int8_t_s_u(((l_1281 >= g_100) || l_790), (((safe_sub_func_uint16_t_u_u(((((safe_rshift_func_uint8_t_u_s(((((safe_sub_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(l_1281, (safe_add_func_uint32_t_u_u(l_801[7][1], (~((l_790 <= (0xCC872D8FL == 4UL)) && g_120[1])))))), l_786)) & l_843) & l_786) ^ g_2467), g_97[2])) < (-1L)) >= 0x60360610L) ^ 0x1EL), 0xBA9AL)) , l_844) , l_1281))) == 3L), 4294967295UL)))))))) <= l_845) != l_786);
                    if (l_847)
                        break;
                    if (l_786)
                        continue;
                }
                g_120[1] = 0x53887F5CL;
            }
            else
            {
                uint16_t l_875 = 6UL;
                int32_t l_881 = 0L;
                int32_t l_884[2][7] = {{0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L}, {0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L}};
                uint16_t l_953 = 0x2EE0L;
                int i, j;
                g_849[0]--;
                for (l_848 = 0; (l_848 >= 0); l_848 -= 1)
                {
                    int32_t l_876 = 1L;
                    int i;
                    if ((safe_lshift_func_uint16_t_u_s((+(safe_sub_func_uint8_t_u_u(g_849[l_848], l_786))), 8)))
                    {
                        g_120[1] = 0xB8ED6298L;
                        if (l_786)
                            continue;

{
            transparent_crc(g_2184[l_922][l_881], "g_2184[l_922][l_881]", i);
            if (i) printf("index = [%d][%d]\n", l_922, l_881);

        }

                    l_846 &= (safe_mod_func_uint32_t_u_u(l_786, 0xE4729DD1L));
                    }
                    else
                    {
                        uint16_t l_861 = 0x987DL;
                        g_120[1] = ((safe_add_func_int16_t_s_s(0x6D2DL, l_861)) > 9L);
                        return g_849[l_848];
                    }
                    for (l_779 = 0; (l_779 <= 3); l_779 += 1)
                    {
                        uint8_t l_870 = 0x7BL;
                        int32_t l_882 = (-8L);
                        int32_t l_883 = (-1L);
                        l_875 &= ((g_120[3] , (safe_add_func_int32_t_s_s((((((g_849[0] & ((safe_sub_func_uint16_t_u_u(g_120[4], ((safe_sub_func_int32_t_s_s(((safe_sub_func_uint16_t_u_u(l_790, (l_870 & (safe_mod_func_uint32_t_u_u(((l_844 != (g_97[0] || g_97[3])) , (safe_lshift_func_int8_t_s_u((g_120[1] , l_820), l_794))), l_1281))))) , g_18), 4294967295UL)) , l_1281))) || l_794)) ^ l_1281) & g_2467) != l_779) & l_786), l_870))) > 8UL);
                        l_877[2][0]--;
                        --l_885;
                    }
                    g_120[1] = (((safe_lshift_func_int8_t_s_u((-7L), 4)) , 1UL) <= (safe_lshift_func_uint16_t_u_u(((g_97[5] >= l_786) < (safe_sub_func_uint8_t_u_u(l_786, (+((+(safe_mod_func_int16_t_s_s(((((l_790 == (safe_lshift_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s((((((safe_rshift_func_uint8_t_u_u(0xA3L, 3)) <= (((safe_sub_func_uint8_t_u_u((l_786 ^ (((g_97[2] <= 7UL) >= 0x5416L) < l_779)), l_846)) < (-3L)) , l_1281)) & 0x514BL) == 0x4A10A230L) > 1UL), l_790)) & 0x80BDL), 1)) <= 0xB0L), g_849[0]))) == l_1281) ^ l_786) == l_1281), 0xC7B8L))) < l_877[0][0]))))), 5)));
                }
                l_778 = ((g_97[2] > ((safe_mod_func_uint16_t_u_u((l_1281 < l_1281), (safe_mod_func_int16_t_s_s(((safe_add_func_uint8_t_u_u((l_885 , (safe_mod_func_uint8_t_u_u(((((~((l_778 & 0x0E4E5FD7L) ^ ((((l_844 == ((((l_794 | ((((((safe_rshift_func_uint8_t_u_s(l_794, l_1281)) & 0xC189E11AL) > 0x02171C1CL) , l_1281) < g_97[2]) , 0xABAFL)) && 0x0FL) , 0x444BL) >= 9L)) , 0xCAB1L) || l_786) && 0x2CF198DBL))) ^ 7UL) , 0x5D7CL) ^ l_919), g_18))), l_1281)) , g_2467), l_786)))) ^ (-1L))) <= 0x08L);
                for (l_919 = 0; (l_919 != (-11)); --l_919)
                {
                    uint8_t l_923 = 0UL;
                    int32_t l_937 = 0xB482D4E8L;
                    int32_t l_938 = 0x297BE1A5L;
                    int32_t l_939 = 0xFF539210L;
                    int32_t l_1001 = 0x1C89D44EL;

l_923 += 1;


                    ++l_923;
                    if ((((-1L) != ((safe_sub_func_uint8_t_u_u(l_820, (~((l_1281 || ((safe_lshift_func_int8_t_s_s(l_844, ((~0xB7L) & (((~(safe_rshift_func_uint8_t_u_u(0xD5L, ((g_100 , g_849[0]) == g_100)))) || l_1281) & l_820)))) , l_786)) == 0xDBB7L)))) <= g_100)) != l_936[0][5]))
                    {
                        g_120[1] = l_725[2];
                        --l_940[0];
                    }
                    else
                    {
                        int32_t l_956 = 0xA1C5A82EL;
                        g_120[1] = ((((((g_849[0] ^ l_801[6][9]) & 0x3A09L) == ((g_97[3] == (safe_lshift_func_uint8_t_u_s((((l_1281 , (l_786 < ((l_786 || (((((safe_mod_func_int16_t_s_s((((safe_mod_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((((safe_mod_func_uint16_t_u_u(g_120[0], l_786)) & l_786) != l_938), 2)), g_849[0])) <= l_953) || l_953), l_786)) <= l_801[7][5]) || 0xFCA679B8L) == g_120[1]) > l_801[0][3])) || l_923))) != l_953) , l_821[6][1]), l_1281))) < 0xABL)) == 65535UL) , 0x310916CAL) , g_120[0]);
                        l_884[0][0] = ((safe_sub_func_int8_t_s_s(l_956, ((safe_sub_func_uint32_t_u_u((safe_add_func_int8_t_s_s((((((safe_add_func_int8_t_s_s((((safe_mod_func_int8_t_s_s(g_100, (l_1281 ^ 0x4C3BL))) & ((+l_1281) == (1L < g_100))) || (((safe_add_func_int8_t_s_s((((l_725[0] & ((+(-5L)) >= 0xEFL)) < l_820) , (-9L)), 0x84L)) >= l_936[0][5]) > 0x4C33D59BL)), g_2467)) ^ g_849[0]) ^ 1L) ^ l_843) > g_540), g_540)), g_97[2])) | 0x0AD02AAFL))) , (-1L));
                        l_821[3][2] = (((safe_rshift_func_uint8_t_u_s((((l_786 <= 0xDED1L) == (l_786 ^ ((safe_add_func_uint16_t_u_u(((safe_unary_minus_func_uint16_t_u((safe_lshift_func_uint8_t_u_u((((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s(((l_1052 == (safe_rshift_func_uint16_t_u_u(0x5CC1L, ((safe_lshift_func_uint16_t_u_u((safe_add_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_lshift_func_uint8_t_u_u((((g_97[2] == ((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u(g_97[2], (((l_1281 || (((safe_rshift_func_int16_t_s_s(((((safe_add_func_uint32_t_u_u(0x04849C4EL, l_1281)) <= l_1281) <= l_937) ^ g_120[1]), g_540)) > l_956) , l_939)) <= 7L) == g_18))) != l_794), g_100)) >= l_786)) < 255UL) != g_100), 1)), l_786)) != g_2467) , l_923) > 8L), l_1281)), 9)) , 0xB22CL)))) > 0xD0D7BB55L), 7)), 3UL)) == l_1281) | l_1281), l_884[0][5])))) ^ g_717), l_956)) <= l_1281))) >= l_1281), 1)) , 0xE75EL) == 0x5EECL);
                    }
                    g_120[1] ^= (safe_add_func_uint32_t_u_u(l_939, l_938));
                    return l_1001;
                }
            }
            for (g_2467 = 17; (g_2467 <= 34); g_2467 = safe_add_func_int32_t_s_s(g_2467, 2))
            {
                uint32_t l_1004 = 0x3C1B13C2L;

l_1329 += 1;


                    if (l_786)
                    break;
                if (l_1004)
                    break;
            }
        }
        for (j = (-29); (j != (-3)); j++)
        {
            g_2431--;
            if (g_540)
                continue;
            for (l_786 = 0; (l_786 == (-12)); l_786 = safe_sub_func_int8_t_s_s(l_786, 2))
            {
                return g_849[0];
            }
        }
        l_793 = ((l_1281 || (l_801[6][3] & g_849[0])) > (safe_lshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u(l_786, (safe_mod_func_int8_t_s_s(((((safe_lshift_func_int16_t_s_u((safe_rshift_func_uint8_t_u_s(l_786, (+((safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((((+((safe_mod_func_int16_t_s_s(((((safe_add_func_int8_t_s_s((g_18 ^ (safe_add_func_int8_t_s_s((((safe_rshift_func_uint8_t_u_s((((((safe_rshift_func_uint8_t_u_s(((l_821[6][1] ^ ((((((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u((0x5FBED003L || ((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_s((-5L), 0)), 5)) != l_790)), l_1281)), l_1046)) < 0x3EL) , 0xE788D646L) == l_801[3][2]) , l_725[2]) || l_801[5][3])) || 0x23L), l_801[7][5])) , 0x32L) & 255UL) || l_1281) && l_1281), l_877[2][0])) , l_1046) , g_100), 0x67L))), 0UL)) >= 0x78D41AC2L) , l_786) ^ 255UL), l_725[2])) , 0x1712L)) , l_919) , l_786), l_1281)), l_1046)) && g_2467)))), l_1281)) ^ l_779) , l_786) , g_849[0]), l_793)))), l_786)));
    }
    else
    {
        int32_t l_1051[4] = {0x0A2DD9A0L, 0L, 0x0A2DD9A0L, 0L};
        int32_t l_1081 = 1L;
        int32_t l_1226[1][2][5] = {{{0L, (-1L), 0L, (-1L), 0L}, {0L, (-1L), 0L, (-1L), 0L}}};
        int32_t l_1273 = 0x20573342L;
        int32_t l_1359 = 0x441BD344L;
        uint8_t l_1361 = 0x58L;
        int32_t l_1369 = (-7L);
        int i, j, k;
        l_1051[0] = (safe_lshift_func_uint16_t_u_s((safe_lshift_func_int8_t_s_s(l_786, 1)), 14));
        g_2467 |= l_940[3];
        for (l_779 = 0; (l_779 > 1); ++l_779)
        {
            uint8_t l_1069 = 1UL;
            int8_t l_1216 = 0xBDL;
            int32_t l_1219 = 0x1BE859F7L;
            int32_t l_1224 = 7L;
            int32_t l_1227 = (-6L);
            int32_t l_1228 = 0x1EE42556L;
            int32_t l_1229 = 0xD31B29F5L;
            int32_t l_1231[6];
            uint32_t l_1233 = 1UL;
            int i;
            for (i = 0; i < 6; i++)
                l_1231[i] = 7L;
            if ((l_1281 , (((safe_add_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((safe_sub_func_int32_t_s_s(((-3L) == ((safe_add_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(0x6B9EL, l_1281)), ((safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s((((l_1069 , ((((~(l_1051[0] , ((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u((((l_786 >= (~((0x941CB444L | g_849[0]) || g_18))) < l_1281) == l_1051[0]), 1UL)) <= l_1281), l_786)) > l_786))) == 6L) <= 0L) , l_786)) & 5L) , l_1281), 1UL)), 4294967288UL)) >= l_793))) != l_1281)), 0xFF1D970AL)), 1L)), l_1281)) , l_790) & l_786)))
            {
                uint8_t l_1080 = 1UL;
                l_919 = (safe_sub_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u(1UL, l_1051[3])), ((g_849[0] < l_1069) != (1L > g_100))));
                g_120[1] = ((g_849[0] || 0xD3L) <= l_919);
                if (l_1080)
                    break;
                if (l_1069)
                    break;
            }
            else
            {
                int16_t l_1094 = 0xECC4L;
                int32_t l_1149[2];
                int16_t l_1163[7][10];
                int i, j;
                for (i = 0; i < 2; i++)
                    {
{
                        uint8_t l_1840 = 0x4FL;
                        int32_t l_1843 = 1L;
                        int32_t l_1850 = (-10L);
                        int32_t l_1851 = 0x86429966L;
                        int32_t l_1852 = 0xCA3D88B8L;
                        int32_t l_1855 = 1L;
                        l_1840 = g_2414;
                        --l_980;
                        --g_1217;
                    }

                    l_1149[i] = 0xBA560EB5L;}
                for (i = 0; i < 7; i++)
                {
                    for (j = 0; j < 10; j++)
                        l_1163[i][j] = 6L;
                }
                l_1081 = (l_786 == l_786);
                for (l_786 = 16; (l_786 != (-28)); l_786 = safe_sub_func_int16_t_s_s(l_786, 5))
                {
                    int32_t l_1095 = (-6L);
                    for (g_2467 = 0; (g_2467 <= 0); g_2467 += 1)
                    {
                        int i, j;
                        return l_877[g_2467][g_2467];
                    }
                    l_1095 = ((((g_120[1] || (-5L)) && ((((safe_lshift_func_int16_t_s_u((((safe_rshift_func_int16_t_s_u((l_786 || (((0xBBL ^ (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(g_120[1], (((((-1L) > (l_779 , 1L)) , ((safe_add_func_int16_t_s_s(l_1281, l_1281)) & 4294967289UL)) <= l_1281) != l_1069))), g_120[1]))) | l_786) == l_786)), l_1281)) >= 0x20L) , 0x45CAL), l_786)) > (-2L)) <= 0x8BB0L) < l_1094)) , l_1069) ^ l_786);
                    for (l_919 = 0; (l_919 <= 0); l_919 += 1)
                    {
                        int i, j;
                        g_120[2] = l_877[l_919][l_919];
                    }
                }
                if ((l_1281 , l_1281))
                {
                    uint16_t l_1101[10] = {0xEA04L, 0xEA04L, 0UL, 0xEA04L, 0xEA04L, 0UL, 0xEA04L, 0xEA04L, 0UL, 0xEA04L};
                    int i;
                    if (l_790)
                        break;
                    if ((safe_add_func_int8_t_s_s((safe_add_func_int8_t_s_s((((l_786 == ((((((((!((l_1281 ^ (l_1069 || ((l_1101[9] & ((-7L) | ((((safe_sub_func_uint8_t_u_u(l_786, (safe_add_func_uint32_t_u_u(g_2467, 0x1CB4D9C6L)))) && l_790) >= l_877[2][0]) >= l_1281))) <= l_794))) <= 4L)) , l_1281) || l_1281) != l_1281) , l_786) , 0xDF52L) , g_100) ^ l_1069)) || g_100) , 0L), 255UL)), l_1281)))
                    {
                        uint16_t l_1114[5][1][4] = {{{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}};
                        int i, j, k;
                        j = ((safe_sub_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(l_786, (8L & (-1L)))), 5UL)) ^ (safe_sub_func_uint32_t_u_u((0x9B71DE32L ^ (l_1281 < l_1281)), (+(((l_1101[9] != g_120[0]) <= 0x33L) , l_1051[0])))));
                        g_120[1] ^= (((((!((l_1114[4][0][3] == (safe_mod_func_uint32_t_u_u(((((safe_lshift_func_int8_t_s_s((safe_add_func_int16_t_s_s((+((!(g_849[0] > g_100)) ^ 0x0043E281L)), (g_97[2] >= g_2467))), ((safe_sub_func_int8_t_s_s((~((((safe_mod_func_uint16_t_u_u((0xC6L || 0x36L), l_1281)) & 0x68L) || g_540) , l_1051[0])), l_1094)) != 0x2E20L))) || l_1281) | l_1094) & l_786), l_1281))) > 1UL)) < 1UL) > l_786) > 0x5E87ADE6L) == 0x38C86F29L);
                    }
                    else
                    {
                        int8_t l_1148 = 0x89L;
                        l_1149[1] = ((0x88L > ((((l_786 || (safe_mod_func_uint32_t_u_u(l_1281, (safe_add_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(((l_1281 , (0L ^ (((safe_add_func_int8_t_s_s(((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(l_786, ((g_97[2] | 0x826CL) < ((((safe_rshift_func_uint8_t_u_s(l_794, l_786)) <= 253UL) | l_1094) >= l_1148)))), l_1281)) < l_794), l_1148)) || g_97[2]) | 0x9933L))) || g_2467), 0L)), l_1281)) >= 0x23DDBF23L), g_100)), 1)) && l_1069), 0x57543A32L))))) != 1L) , l_1281) | 4294967295UL)) ^ 0xB771L);
                        if (l_786)
                            break;
                        g_120[1] = (safe_mod_func_int16_t_s_s((((((safe_lshift_func_int8_t_s_s((((safe_sub_func_uint32_t_u_u((((((safe_mod_func_int16_t_s_s(0L, (((((+65533UL) > ((safe_mod_func_uint32_t_u_u((safe_add_func_int16_t_s_s(((l_1149[1] , ((g_2431 >= l_786) >= (l_1163[1][2] || (((safe_sub_func_int16_t_s_s((l_786 != (l_1101[9] >= (l_1051[2] == 4294967295UL))), l_1281)) ^ g_2467) & l_786)))) && l_786), l_786)), l_1051[1])) > 2L)) || l_786) < l_794) , l_1081))) < l_1281) && g_540) ^ 0x5443L) < l_779), l_786)) , l_1149[0]) , l_786), 2)) != l_1101[6]) <= l_786) , l_1281) >= l_1094), g_18));
                    }
                    l_919 = (safe_rshift_func_int8_t_s_s((l_1081 ^ 4294967295UL), 0));
                }
                else
                {
                    for (g_100 = 3; (g_100 >= 1); g_100 -= 1)
                    {
                        int i;
                        if (g_120[g_100])
                            break;
                        if (l_725[g_100])
                            break;
                        return l_786;
                    }
                }
            }
            if (l_722)
            {
                uint16_t l_1172 = 0x80D0L;
                j &= ((((l_1281 >= l_1172) && (g_849[0] , (((((0x4E57L != (safe_unary_minus_func_uint8_t_u((((((safe_sub_func_uint16_t_u_u(((safe_sub_func_int16_t_s_s((!((safe_unary_minus_func_uint16_t_u(l_786)) | l_1281)), (safe_rshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u(0UL, ((l_1069 , (safe_sub_func_int32_t_s_s((((((safe_add_func_int8_t_s_s((((!l_722) , l_786) <= l_725[0]), l_786)) != l_1172) > l_1191[1]) < l_1172) & 0UL), 0x349E8373L))) | l_786))), l_794)), l_786)))) & g_2431), (-5L))) < l_1069) , g_849[0]) | l_1172) >= l_1069)))) && l_786) != 0UL) | l_779) | 0x7351L))) & l_725[3]) , l_794);

j -= 1;


                    g_1217 |= ((safe_mod_func_int16_t_s_s((-4L), (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((((safe_add_func_int16_t_s_s((safe_lshift_func_int16_t_s_u((safe_mod_func_int32_t_s_s((((((safe_lshift_func_int8_t_s_u(g_849[0], (!0xE43BDF21L))) || ((((((safe_lshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((~(safe_lshift_func_int16_t_s_s(l_1281, 11))), 6)), 6)) , 0x9037L) || l_794) ^ ((l_786 & (l_1281 && (safe_rshift_func_uint8_t_u_s(l_1281, g_2467)))) != l_1081)) >= l_794) && g_849[0])) > g_120[1]) , 0xB8L) ^ l_1281), 4294967295UL)), g_100)), (-1L))) <= g_100) ^ l_1069), l_1172)), 0xFBL)))) > l_1216);
            }
            else
            {
                int32_t l_1218 = 0L;
                int32_t l_1220 = 0xD6A84518L;
                int32_t l_1221 = 0x3E2F8B07L;
                int32_t l_1222 = 0xBC228DECL;
                int32_t l_1223 = 0L;
                int32_t l_1225 = 0x92788A2FL;
                int32_t l_1230 = 0x8A193837L;
                int32_t l_1232[1][1];
                int i, j;
                for (i = 0; i < 1; i++)
                {
                    for (j = 0; j < 1; j++)
                        l_1232[i][j] = 0xBE2CE0ADL;
                }
                l_1233++;
            }
            if (l_779)
            {
                uint32_t l_1241[4][8] = {{0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}, {0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}, {0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}, {0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}};
                uint16_t l_1252 = 0x759AL;
                int i, j;
                g_120[4] |= ((safe_lshift_func_uint16_t_u_s(6UL, 8)) , ((safe_unary_minus_func_int32_t_s((safe_sub_func_int16_t_s_s((((((l_1241[2][6] | 0L) & ((((safe_rshift_func_uint16_t_u_u(((safe_unary_minus_func_int16_t_s(l_1191[0])) & (l_1281 , (((((safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u((l_1281 , (safe_add_func_int16_t_s_s((((~l_1252) , (safe_add_func_uint16_t_u_u((((((g_18 | (safe_lshift_func_uint16_t_u_s((safe_add_func_uint8_t_u_u(((((0x1CA4L < l_1281) && g_100) | g_97[2]) ^ l_786), l_786)), l_1281))) != l_1281) || l_790) > l_1051[2]) , 0x6DB4L), l_778))) || l_1281), 0x5D57L))), g_97[2])), l_1219)) || 1UL) || l_786) | l_1281) != g_849[0]))), l_790)) && 1L) > 0x1DC0L) , l_786)) != 0x35A6L) || 0xE981L) | l_779), 1L)))) , l_779));
            }
            else
            {
                uint16_t l_1263[6][10] = {{0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}};
                int32_t l_1277[9];
                int16_t l_1321 = 0x3AFEL;
                int i, j;
                for (i = 0; i < 9; i++)
                    {
if (l_794)
                        break;

                    l_1277[i] = (-1L);}
                for (j = 0; (j <= (-8)); --j)
                {
                    uint8_t l_1265 = 0xA0L;
                    int32_t l_1272 = 0xA92A5564L;
                    uint8_t l_1274 = 1UL;
                    int32_t l_1325 = 0x05F0F06DL;
                    int32_t l_1326 = 0xA526867EL;
                    int8_t l_1360 = 0xE8L;
                    if (((safe_rshift_func_int16_t_s_s(1L, (l_790 < ((l_1263[4][9] && (!(l_1265 || l_786))) , ((((l_786 , (safe_sub_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_u(((((safe_lshift_func_uint8_t_u_u(g_97[2], 2)) >= g_100) | 8L) , g_2467), g_849[0])) ^ g_120[1]), l_1281))) == g_18) >= l_786) < l_1263[0][9]))))) >= l_1081))
                    {
                        uint32_t l_1278 = 0x7A1781B4L;
                        l_1274--;
                        l_1278--;
                    }
                    else
                    {
                        uint8_t l_1292 = 255UL;
                        int32_t l_1301 = 0L;
                        g_143 ^= 0x10E3B930L;
                        l_1277[4] &= (safe_rshift_func_int16_t_s_u((safe_mod_func_uint16_t_u_u((9UL || ((g_849[0] < ((g_1217 >= g_849[0]) || l_786)) , (((safe_sub_func_int16_t_s_s((safe_sub_func_int8_t_s_s(0xDDL, (0UL ^ (safe_lshift_func_uint16_t_u_u(((l_1292 <= (safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u((l_779 & (-1L)), g_2431)), l_1219)), 7)), l_786))) , g_2467), 1))))), 0UL)) & l_786) || l_1281))), l_940[0])), l_786));
                        l_1301 = 0x9FC577ABL;
                    }
                    for (l_790 = 0; (l_790 >= 7); l_790 = safe_add_func_uint8_t_u_u(l_790, 3))
                    {
                        return l_786;
                    }
                    if ((l_786 , (((safe_add_func_int8_t_s_s((safe_lshift_func_int8_t_s_u(l_786, 3)), ((l_1277[4] , (safe_rshift_func_uint8_t_u_u(g_540, (safe_lshift_func_int8_t_s_s((g_2467 > (safe_add_func_uint16_t_u_u(l_1281, (((~(safe_add_func_uint8_t_u_u((((l_786 >= (safe_mod_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(g_97[0], (g_849[0] , l_1321))) || l_1281), g_2467))) && l_1229) ^ l_786), l_1081))) && l_1226[0][1][2]) , l_1281)))), 5))))) >= l_1281))) >= 65527UL) == l_1277[4])))
                    {
                        uint32_t l_1322 = 1UL;
                        int32_t l_1328[3];
                        uint16_t l_1330[7][2] = {{1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}};
                        int i, j;
                        for (i = 0; i < 3; i++)
                            l_1328[i] = 5L;

for (p_35 = 0; (p_35 < (-17)); --p_35)
        {
            uint8_t l_198 = 1UL;
            int16_t l_261 = (-10L);
            uint16_t l_350 = 5UL;
            int32_t l_367 = 1L;
            int32_t l_391[3][6] = {{0xD2D39850L, 1L, 1L, 0L, 0L, 1L}, {0xD2D39850L, 1L, 1L, 0L, 0L, 1L}, {0xD2D39850L, 1L, 1L, 0L, 0L, 1L}};
            uint32_t l_431 = 0x13F79E03L;
            int i, j;
            if (l_1007)
                break;
            l_1369 ^= l_1007;
            for (l_778 = 0; (l_778 == 26); ++l_778)
            {
                uint32_t l_210 = 0UL;
                int8_t l_281[8][7] = {{0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}};
                uint32_t l_326 = 0x0A0DE782L;
                int32_t l_363 = 0L;
                int32_t l_392 = (-1L);
                int32_t l_395 = 0L;
                const uint32_t l_420 = 0xA82EA14BL;
                const int16_t l_427 = 0L;
                int i, j;
                if ((l_1369 || (safe_mod_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_u(0x73L, 5)) | ((safe_mod_func_int32_t_s_s(g_59, (safe_rshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s((((0x7CB8L < 0xB2B8L) , ((l_198 ^ 0xDBL) != l_198)) && 0xD1L), g_1171)), 11)))) != l_1369)), 0xA615L))))
                {
                    uint32_t l_207 = 0x44D27D01L;
                    g_120[3] = p_35;
                    for (g_143 = (-26); (g_143 >= 44); g_143++)
                    {
                        return l_198;
                    }
                    g_120[1] = (((((((g_120[1] && l_1321) || ((safe_rshift_func_uint16_t_u_u(((g_2414 , ((safe_mod_func_uint32_t_u_u(((safe_mod_func_uint16_t_u_u(((((0x47C1L >= (l_1360 ^ l_207)) <= (safe_sub_func_uint16_t_u_u(((g_18 && g_2414) , l_1007), l_1007))) ^ g_120[1]) < g_120[0]), g_120[1])) & g_97[2]), 0x3A8961DAL)) & 0L)) , p_35), 4)) & g_120[1])) ^ l_1369) == l_207) | l_210) & 0xD933A2BCL) & l_1007);
                }
                else
                {
                    uint8_t l_258 = 0x75L;
                    int32_t l_262 = 0x18EC19C0L;
                    for (g_143 = (-24); (g_143 < 42); ++g_143)
                    {
                        l_1231[2] |= g_2414;
                        return l_198;
                    }
                    l_1369 = ((0x5EL || (safe_lshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((0x746C22C4L && (safe_add_func_int16_t_s_s(((g_2414 , (safe_rshift_func_uint8_t_u_u(l_1360, 6))) && (safe_add_func_uint8_t_u_u(p_35, (safe_lshift_func_int16_t_s_u((((safe_rshift_func_int8_t_s_s((safe_add_func_int8_t_s_s(((l_1360 == (((safe_sub_func_uint32_t_u_u(((l_198 || 0x50L) | ((safe_sub_func_uint32_t_u_u((((l_1231[2] == g_89) , l_1007) >= l_1321), p_35)) == 0xFF3A24CFL)), 0x3913078BL)) >= g_89) , 1L)) != p_35), l_1369)), l_1369)) > l_1321) | (-6L)), 1))))), g_120[2]))), 0L)), 15))) != l_1369);
                    for (g_1171 = 0; (g_1171 > 43); g_1171 = safe_add_func_uint8_t_u_u(g_1171, 2))
                    {
                        uint16_t l_236 = 1UL;
                        g_120[1] = 0x724D0293L;
                        l_236 = g_89;
                        l_262 = (safe_sub_func_int8_t_s_s((((((((l_1360 || ((((1UL < ((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((((safe_mod_func_uint8_t_u_u(255UL, (safe_rshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s(((safe_sub_func_int8_t_s_s((safe_mod_func_int16_t_s_s(l_1359, 65535UL)), l_198)) > ((safe_rshift_func_uint16_t_u_u(p_35, ((((safe_rshift_func_int16_t_s_u(((l_258 , (((safe_add_func_uint32_t_u_u(g_143, g_120[1])) == l_198) , l_236)) & l_258), p_35)) || g_97[2]) , l_1360) , 0x2CA6L))) > 0x62L)), p_35)) | l_261), 0)))) | l_210) && l_1369), 255UL)) | g_18), 11)) , g_2414)) || l_236) , 0x43L) | 1UL)) ^ p_35) , l_1281) < 0L) < l_1359) != l_1360) >= l_1007), l_1360));
                        l_1360 = ((((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_u(((((((safe_add_func_uint16_t_u_u(l_1007, l_1321)) == ((safe_mod_func_int32_t_s_s((((((safe_add_func_int16_t_s_s((safe_sub_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u(((((safe_sub_func_uint32_t_u_u(l_281[4][6], l_258)) ^ (((safe_add_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u((0x25D96900L <= (safe_sub_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s(l_236, l_1281)) < ((safe_lshift_func_int16_t_s_s(((0UL < (safe_mod_func_int8_t_s_s(g_2414, g_97[4]))) == g_120[2]), g_89)) < 7UL)), 2UL))), p_35)), 0x96E64D66L)) >= l_1360), 0xFC6B1E59L)) < (-5L)) | 4294967292UL)) != l_1369) ^ 8L), (-7L))) & g_2414), l_1369)) > l_236) <= (-1L)), p_35)), p_35)) >= g_143) ^ 0xF7BFL) , g_89) == l_198), l_1321)) && g_59)) | 1UL) != 0x6CL) <= l_281[0][2]) , 0x35L), l_1007)) && p_35), 4)) & g_143) < 0x73054497L) != l_1321);
                    }
                    for (g_1171 = 0; (g_1171 <= 4); g_1171 += 1)
                    {
                        int i;
                        g_120[g_1171] = ((safe_sub_func_int32_t_s_s(g_97[(g_1171 + 2)], (safe_unary_minus_func_uint8_t_u(((((safe_sub_func_int16_t_s_s(((g_97[g_1171] , 0xC6C2L) ^ 0xFEB2L), ((safe_rshift_func_uint16_t_u_u(g_97[(g_1171 + 1)], ((safe_rshift_func_uint16_t_u_u(g_120[g_1171], 5)) != (safe_mod_func_int8_t_s_s(((((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(g_120[g_1171], ((0x60L < g_120[g_1171]) , l_281[3][1]))), 0x2C0B2767L)) >= l_778) != g_89) != 255UL), 0xE6L))))) >= l_1360))) != (-6L)) || g_120[0]) && g_97[(g_1171 + 2)]))))) & l_1321);
                        g_120[2] = ((-8L) == 0UL);
                        l_326 = ((((((((65535UL > (safe_mod_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((((l_262 || (l_198 || (safe_mod_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u((safe_rshift_func_int8_t_s_u(g_89, (((l_1359 > (l_281[4][6] , p_35)) != ((safe_rshift_func_uint16_t_u_u(0xB25DL, 8)) || 1UL)) <= l_1360))), l_1321)) | g_97[2]), 1)), l_1321)))) & p_35) || g_89), l_1231[0])) & l_258), p_35))) <= g_89) < g_120[g_1171]) == 0x8B28L) < l_1360) || l_1231[2]) != l_1360) <= 246UL);
                        l_262 |= (~g_120[1]);
                    }
                }
                for (l_1007 = 20; (l_1007 < 40); l_1007 = safe_add_func_uint32_t_u_u(l_1007, 1))
                {
                    int8_t l_362 = 0x43L;
                    int32_t l_366 = (-2L);
                    uint8_t l_369 = 0x5AL;
                    int32_t l_393 = 0L;
                    if ((safe_add_func_int16_t_s_s(((((l_1231[1] || ((g_2414 >= (+(-1L))) >= (safe_lshift_func_int8_t_s_s(((safe_sub_func_int8_t_s_s((((safe_mod_func_int16_t_s_s(((safe_lshift_func_int16_t_s_s(l_1007, 2)) == (((safe_lshift_func_uint16_t_u_s((g_59 || ((safe_rshift_func_uint16_t_u_s((((safe_add_func_int16_t_s_s(((((((safe_mod_func_int16_t_s_s(g_2414, g_1171)) <= 0x56719CF5L) < ((+(((((1UL && 0xD84E0731L) > l_281[6][4]) < g_143) > 0x15L) & 0xF7L)) | g_143)) , g_2414) == l_350) , l_1369), 0xA7B5L)) , 2L) , g_935), 11)) >= l_1321)), l_210)) , 0x25L) < 7UL)), g_59)) <= 1UL) , l_210), g_59)) ^ 246UL), g_18)))) <= 0x83L) >= 6UL) & g_97[2]), l_1369)))
                    {
                        uint32_t l_364 = 0UL;
                        int32_t l_365 = 1L;
                        l_364 = ((safe_add_func_int8_t_s_s((((safe_lshift_func_uint16_t_u_u(((((p_35 != l_1360) > ((safe_lshift_func_uint16_t_u_u((0xA1L != (((-6L) && (((safe_rshift_func_int8_t_s_u(0x08L, ((g_2414 < ((g_97[2] | (((safe_sub_func_uint16_t_u_u((((l_362 != 0xFEFA8AE2L) , l_1321) != g_97[2]), l_1360)) && 0x6386802AL) >= g_97[1])) >= l_1360)) , l_1369))) < 2UL) && l_281[4][6])) != l_198)), 0)) ^ l_1369)) != g_97[2]) || 0xF9L), l_363)) || 0xD2L) , g_2414), (-7L))) && g_2414);
                        ++l_369;
                        if (l_281[4][3])
                            break;
                        l_366 = l_1369;
                    }
                    else
                    {
                        uint32_t l_384 = 0UL;
                        l_367 = (safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((p_35 , (safe_mod_func_int32_t_s_s((((((((((((g_89 , ((safe_mod_func_uint8_t_u_u((g_97[2] ^ (~(+l_1360))), ((((g_97[3] & ((safe_sub_func_uint16_t_u_u((l_384 >= g_935), (((((((safe_lshift_func_int16_t_s_u((g_2414 || (((((safe_rshift_func_int16_t_s_u((1UL != g_2414), 4)) , 0x8DL) >= l_1360) , g_2414) , 0x343F8062L)), g_2414)) > 4L) > g_2414) , g_120[1]) != g_89) , l_1369) == 0xCB3F649DL))) | g_2414)) || l_1360) | g_120[3]) && 0xE5L))) < 0UL)) >= g_97[1]) || 0x3F5AL) ^ l_261) || g_2414) | l_366) , 0L) || (-1L)) ^ 0x8506B361L) >= p_35) ^ (-6L)), 0x3F0D7356L))), l_1360)), l_1281));
                        l_980--;
                    }
                    l_1369 = (((((g_18 ^ (0UL & (((g_59 == (safe_mod_func_uint8_t_u_u(((((safe_sub_func_int16_t_s_s(((l_1369 & ((safe_add_func_int8_t_s_s((((safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((((safe_mod_func_uint32_t_u_u((safe_sub_func_int16_t_s_s((((l_1321 <= g_143) > (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(l_1360, ((((((((safe_rshift_func_uint8_t_u_s(l_1321, 1)) & (((l_281[4][6] || g_2414) && g_2414) | 0UL)) == g_120[1]) || l_1007) < l_326) < l_1321) || 0x3CL) < g_18))), 4))) >= (-1L)), g_935)), l_1052)) || g_2414) >= l_420), l_1360)), l_1360)) & (-1L)) | l_281[4][6]), 0x42L)) < g_97[3])) <= g_120[1]), g_120[3])) | l_980) != 0L) == l_391[1][4]), l_395))) > 0x32L) || l_1327))) ^ g_2414) | l_1369) < g_89) < 1UL);
                    for (g_1171 = 0; (g_1171 <= 4); g_1171 += 1)
                    {
                        int i;
                        return g_120[g_1171];
                    }
                    if (g_143)
                        break;
                }
                for (l_363 = 0; (l_363 == (-23)); --l_363)
                {
                    uint32_t l_461[2][4][5] = {{{0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}}, {{0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}}};
                    int i, j, k;
                    g_120[1] = ((0x7DDEF103L >= ((((safe_rshift_func_int16_t_s_u(((0x2CD8L == ((((((0x0CE5L > p_35) , (-9L)) || ((((safe_mod_func_uint32_t_u_u((g_120[1] > (0xD6FEED26L | ((l_427 >= (((((((safe_unary_minus_func_uint8_t_u(((safe_rshift_func_int8_t_s_s(g_97[1], 2)) != 0xEF0CL))) > 0x88D4L) && l_1360) ^ g_120[1]) >= l_281[3][0]) | (-6L)) == 1L)) ^ 7UL))), 1UL)) < g_143) | l_1360) , 0UL)) ^ (-1L)) | l_281[0][3]) == l_980)) >= 0xBDE2D00BL), 7)) , 7L) > p_35) || l_420)) , l_1052);
                    l_431--;
                    l_1369 = (((safe_unary_minus_func_int16_t_s(((((safe_unary_minus_func_uint16_t_u((l_326 , (((((~(safe_add_func_uint8_t_u_u((l_427 == (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_s(((safe_sub_func_int16_t_s_s(g_120[2], (((safe_add_func_uint8_t_u_u(((g_2414 || ((safe_mod_func_int16_t_s_s(((((l_395 & ((0xAD109901L < ((((safe_rshift_func_uint8_t_u_s(g_89, 7)) != (g_2414 <= (safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u((safe_sub_func_uint8_t_u_u(((((((((g_89 , 4UL) > 0UL) == 0xC8C73883L) <= l_427) ^ g_18) && l_1007) || g_120[1]) & l_1327), p_35)), l_461[1][1][2])), l_1360)), g_89)))) <= l_461[1][1][2]) < 0x237EL)) <= 0x28L)) < 65535UL) | l_363) >= g_2414), l_1231[4])) < 5UL)) ^ l_1359), g_59)) >= 0UL) | g_97[2]))) <= g_59), g_120[1])) ^ l_1360), 7))), g_2414))) < 1L) || l_1360) ^ l_1281) , 6UL)))) | g_143) != l_1281) , l_919))) , 1UL) != 255UL);
                }
                g_120[1] ^= ((0L & 0x37L) >= (safe_sub_func_uint16_t_u_u(1UL, ((((safe_lshift_func_int8_t_s_u((g_97[3] >= (safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s(((((((safe_lshift_func_uint16_t_u_s(((((0xC0653759L ^ l_363) , g_2414) == (l_392 != l_1369)) , 1UL), l_1369)) , 4L) , l_1281) || 0x464EEE5AL) | 8UL) & g_694), 5)) , 0x83F7DA68L) && g_18), 1UL))), 5)) <= g_1171) < 65531UL) || l_980))));
            }
        };


                    --l_1322;
                        l_1330[3][0]++;
                        if (l_1326)
                            continue;
                    }
                    else
                    {
                        int32_t l_1333[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_1333[i] = 8L;
                        l_1333[2] = l_1281;
                        g_120[3] = (safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(0x461CL, 7)), (l_1051[0] < (l_779 < (safe_add_func_uint16_t_u_u(((0x1114L | g_100) != (safe_mod_func_uint32_t_u_u((safe_mod_func_int16_t_s_s(g_1217, (safe_add_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u(((((-1L) ^ (safe_add_func_int8_t_s_s(((0x17D87BE6L != (safe_rshift_func_int8_t_s_s(((safe_unary_minus_func_uint32_t_u((!g_2467))) ^ 0x50L), g_540))) ^ l_786), l_786))) < 8UL) , l_722), 14)) , l_1329), j)))), 0x45D6E44FL))), l_794))))));
                    }
                    if ((l_790 >= ((l_1051[0] != (((l_786 == (g_849[0] ^ (l_1265 > l_1281))) < l_786) == g_849[0])) <= (safe_lshift_func_uint8_t_u_s(((safe_lshift_func_int8_t_s_u(l_1281, g_100)) , 0xF4L), 2)))))
                    {
                        l_1277[4] = l_786;
                    }
                    else
                    {
                        int32_t l_1358 = 0x27225A3DL;
                        --l_1361;
                        if (l_794)
                            break;
                    }
                }
            }

if (g_1217)
                            break;

                    for (g_143 = (-1); (g_143 == 31); ++g_143)
            {
                l_1081 ^= ((safe_add_func_int8_t_s_s(l_1359, 1L)) < (l_1281 != (((((-2L) > g_18) , (((g_100 != 0xAEL) & ((((g_1368[1] > (l_794 <= l_786)) & l_1359) == g_97[5]) > l_1369)) == 4294967286UL)) , (-1L)) ^ 255UL)));
            }
        }
        g_120[1] = (safe_sub_func_uint16_t_u_u(((0x68DCACFFL | (safe_sub_func_int8_t_s_s((((((safe_mod_func_uint32_t_u_u(((((((g_97[2] , (safe_lshift_func_int16_t_s_u((g_1368[2] && 0L), 0))) | ((l_1361 && (safe_mod_func_int8_t_s_s((l_786 && (safe_rshift_func_int16_t_s_s((((((((~(((safe_add_func_uint16_t_u_u(((((safe_lshift_func_uint8_t_u_u((((safe_add_func_uint8_t_u_u(l_1369, l_1281)) && ((((1L != 0x1161L) != l_1281) ^ l_1052) ^ g_2431)) < l_1361), g_120[1])) >= g_849[0]) , (-1L)) | 0x3F27L), g_1368[0])) , 0x8D90L) ^ l_794)) ^ l_725[2]) | 0xC3L) && g_1368[1]) <= l_1281) , l_1226[0][1][2]) , l_1226[0][0][2]), 2))), l_1281))) <= l_1273)) >= 0x27L) >= g_97[6]) != 2L) != 0x1C966BF2L), l_794)) | (-3L)) < g_2467) > l_786) == l_1281), l_1191[1]))) <= l_790), 8L));
    };


                    break;}

                    if (p_34)
                break;
            for (l_778 = 0; (l_778 <= (-8)); l_778--)
            {
                return l_786;
            }
            for (g_694 = 2; (g_694 < 14); g_694 = safe_add_func_uint16_t_u_u(g_694, 3))
            {

for (g_777 = 0; (g_777 <= 3); g_777 += 1)
                    {
                        uint8_t l_870 = 0x7BL;
                        int32_t l_882 = (-8L);
                        int32_t l_883 = (-1L);
                        g_1217 &= ((g_120[3] , (safe_add_func_int32_t_s_s((((((g_849[0] & ((safe_sub_func_uint16_t_u_u(g_120[4], ((safe_sub_func_int32_t_s_s(((safe_sub_func_uint16_t_u_u(l_880, (l_870 & (safe_mod_func_uint32_t_u_u(((g_2468 != (g_97[0] || g_97[3])) , (safe_lshift_func_int8_t_s_u((g_120[1] , j), l_1052))), l_779))))) , g_18), 4294967295UL)) , l_779))) || l_1052)) ^ l_779) & l_1423) != g_777) & g_101), l_870))) > 8UL);
                        l_877[2][0]--;
                        --l_794;
                    };


                    l_794--;
            }
        }
    }
    if ((p_34 == g_540))
    {
        int16_t l_801[8][10] = {{0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}};
        int32_t l_821[9][7] = {{0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}};
        uint32_t l_843 = 4294967290UL;
        int32_t l_1046 = 0x07FD8AA4L;
        int i, j;
        for (g_143 = 0; (g_143 > 15); ++g_143)
        {
            g_120[1] = 0x19D1A3FEL;
            if (p_35)
                continue;
        }


g_2467 |= 0x10DDF4F3L;

                    for (l_1423 = (-24); (l_1423 < 42); ++l_1423)
                    {

{
                        int i;
                        if (g_120[l_790])
                            break;
                        if (l_725[l_790])
                            break;
                        return g_540;
                    }

                    l_1439[2] |= g_1217;

{
        transparent_crc(g_2003[g_2100], "g_2003[g_2100]", i);
        if (i) printf("index = [%d]\n", g_2100);

    }

                    return l_1007;
                    };


                    for (l_793 = 0; (l_793 <= 24); l_793 = safe_add_func_uint16_t_u_u(l_793, 2))
        {
            int32_t l_820 = (-1L);
            const int32_t l_844 = 1L;
            int32_t l_846 = 0xEFBA0CA9L;
            int32_t l_848 = 0x52FBE6A1L;
            uint32_t l_885 = 2UL;
            int32_t l_936[2][6] = {{0L, 0L, (-3L), 0L, 0L, (-3L)}, {0L, 0L, (-3L), 0L, 0L, (-3L)}};
            int i, j;
            l_801[7][5] = p_35;

{
                        uint32_t l_384 = 0UL;
                        i = (safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((g_101 , (safe_mod_func_int32_t_s_s((((((((((((l_790 , ((safe_mod_func_uint8_t_u_u((g_97[2] ^ (~(+g_89))), ((((g_97[3] & ((safe_sub_func_uint16_t_u_u((l_384 >= g_2254), (((((((safe_lshift_func_int16_t_s_u((g_1217 || (((((safe_rshift_func_int16_t_s_u((1UL != g_2414), 4)) , 0x8DL) >= l_790) , g_2414) , 0x343F8062L)), g_2414)) > 4L) > g_1217) , g_120[1]) != l_790) , j) == 0xCB3F649DL))) | g_1217)) || l_790) | g_120[3]) && 0xE5L))) < 0UL)) >= g_97[1]) || 0x3F5AL) ^ g_540) || g_2414) | l_846) , 0L) || (-1L)) ^ 0x8506B361L) >= g_101) ^ (-6L)), 0x3F0D7356L))), g_717)), g_1168));
                        l_843--;
                    }

                    for (g_777 = 0; (g_777 <= 7); g_777 += 1)
            {
                int i, j;
                g_120[3] = l_801[g_777][g_777];
                l_821[6][1] = (safe_rshift_func_uint8_t_u_s((safe_lshift_func_uint8_t_u_u((g_97[2] , (safe_lshift_func_int16_t_s_u((((safe_rshift_func_int16_t_s_u((safe_add_func_uint8_t_u_u((4294967286UL != 0x9CDCB11EL), ((l_801[g_777][g_777] ^ (g_89 == (safe_mod_func_int16_t_s_s(((((2UL | (safe_mod_func_int8_t_s_s((p_34 || ((safe_add_func_int16_t_s_s((g_97[2] , (0x978C1B61L > 4294967291UL)), l_820)) < 0xB988L)), p_34))) || l_790) >= p_35) == 0x1F887AC6L), p_34)))) > 6UL))), 6)) != g_694) <= l_801[7][5]), p_35))), 3)), l_801[7][5]));
            }

if (g_935)
                        {
if (i) printf("index = [%d][%d]\n", g_2469, l_919);

                    continue;}

                    if ((0x4DF543CEL && l_790))
            {
                uint32_t l_847 = 0xB97BAC9CL;
                for (g_89 = 0; (g_89 >= (-10)); g_89--)
                {
                    const uint32_t l_845 = 0xB19552AFL;
                    l_846 = (((safe_sub_func_int8_t_s_s(0x65L, (safe_unary_minus_func_int8_t_s((+(g_97[2] < (safe_add_func_uint32_t_u_u(((safe_rshift_func_int8_t_s_u(((p_34 >= g_100) || l_790), (((safe_sub_func_uint16_t_u_u(((((safe_rshift_func_uint8_t_u_s(((((safe_sub_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(p_34, (safe_add_func_uint32_t_u_u(l_801[7][1], (~((l_790 <= (0xCC872D8FL == 4UL)) && g_120[1])))))), p_35)) & l_843) & p_35) ^ g_143), g_97[2])) < (-1L)) >= 0x60360610L) ^ 0x1EL), 0xBA9AL)) , l_844) , p_34))) == 3L), 4294967295UL)))))))) <= l_845) != p_35);
                    if (l_847)
                        break;
                    if (p_35)
                        continue;
                }
                g_120[1] = 0x53887F5CL;
            }
            else
            {
                uint16_t l_875 = 6UL;
                int32_t l_881 = 0L;
                int32_t l_884[2][7] = {{0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L}, {0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L}};
                uint16_t l_953 = 0x2EE0L;
                int i, j;
                g_849[0]--;
                for (l_848 = 0; (l_848 >= 0); l_848 -= 1)
                {
                    int32_t l_876 = 1L;
                    int i;
                    if ((safe_lshift_func_uint16_t_u_s((+(safe_sub_func_uint8_t_u_u(g_849[l_848], p_35))), 8)))
                    {
                        g_120[1] = 0xB8ED6298L;

{
                return g_849[0];
            }

                    if (p_35)
                            continue;
                        l_846 &= (safe_mod_func_uint32_t_u_u(p_35, 0xE4729DD1L));
                    }
                    else
                    {
                        uint16_t l_861 = 0x987DL;
                        g_120[1] = ((safe_add_func_int16_t_s_s(0x6D2DL, l_861)) > 9L);

if (l_846) printf("index = [%d][%d][%d]\n", l_876, l_1329, l_846);

                    return g_849[l_848];
                    }
                    for (g_777 = 0; (g_777 <= 3); g_777 += 1)
                    {
                        uint8_t l_870 = 0x7BL;
                        int32_t l_882 = (-8L);
                        int32_t l_883 = (-1L);

for (l_882 = 0; l_882 < 3; l_882++)
        {
            transparent_crc(g_2184[l_881][l_882], "g_2184[l_881][l_882]", l_881);
            if (l_881) printf("index = [%d][%d]\n", l_881, l_882);

        };


                    l_875 &= ((g_120[3] , (safe_add_func_int32_t_s_s((((((g_849[0] & ((safe_sub_func_uint16_t_u_u(g_120[4], ((safe_sub_func_int32_t_s_s(((safe_sub_func_uint16_t_u_u(l_790, (l_870 & (safe_mod_func_uint32_t_u_u(((l_844 != (g_97[0] || g_97[3])) , (safe_lshift_func_int8_t_s_u((g_120[1] , l_820), g_22))), p_34))))) , g_18), 4294967295UL)) , p_34))) || g_22)) ^ p_34) & g_143) != g_777) & p_35), l_870))) > 8UL);

for (l_1007 = 0; (l_1007 != 4); ++l_1007)
    {
        uint8_t l_722 = 0xE0L;
        int32_t l_770 = 0x6E81370EL;
        uint32_t l_779 = 1UL;
        int32_t l_792 = 0x2E89F638L;
        if ((safe_lshift_func_int16_t_s_u((g_694 <= l_722), (safe_sub_func_int8_t_s_s(((l_725[2] <= ((((safe_sub_func_int32_t_s_s(g_143, (safe_mod_func_uint32_t_u_u((0x7ABE5FAFL >= ((safe_sub_func_uint8_t_u_u(g_120[1], l_722)) , ((safe_lshift_func_int8_t_s_u(l_722, (((((((safe_lshift_func_int8_t_s_s(g_143, 3)) | l_725[2]) || g_717) >= g_694) <= g_97[5]) , l_722) >= 4294967295UL))) == g_694))), l_725[2])))) >= g_694) ^ 0UL) != 8L)) ^ 0x0968FE10L), l_1281)))))
        {
            uint32_t l_749 = 4294967288UL;
            if ((~(safe_add_func_uint32_t_u_u(((0L != (((l_725[2] || (safe_sub_func_int8_t_s_s(0x65L, (safe_mod_func_uint32_t_u_u(l_1281, l_722))))) ^ ((safe_add_func_uint16_t_u_u((l_790 , (safe_lshift_func_int8_t_s_u((0xA7L & 6L), 0))), (((g_694 == l_1052) >= g_18) < g_101))) < (-1L))) < g_694)) , 0x11329388L), 4294967295UL))))
            {
                int32_t l_769[1];
                int i;
                for (i = 0; i < 1; i++)
                    l_769[i] = 0x804970A5L;
                g_120[1] = 1L;
                if (g_694)
                    continue;
                l_749 = (safe_rshift_func_uint16_t_u_u(g_97[2], 13));
                l_770 = (safe_lshift_func_int8_t_s_s((5UL >= (0UL < (safe_add_func_int8_t_s_s((((safe_rshift_func_int16_t_s_s((g_18 != (safe_sub_func_int32_t_s_s((safe_unary_minus_func_int32_t_s((safe_mod_func_int8_t_s_s((safe_mod_func_int32_t_s_s(0x5B48709BL, ((safe_rshift_func_int16_t_s_s(g_18, g_694)) || 3L))), (safe_sub_func_int32_t_s_s(g_694, ((((safe_rshift_func_int16_t_s_u(g_694, 7)) || g_18) || l_769[0]) <= l_1281))))))), g_143))), 6)) != g_694) != l_880), l_722)))), l_1281));
            }
            else
            {
                int16_t l_775 = (-4L);
                int32_t l_776 = (-3L);
                g_777 = ((((l_1052 ^ (l_725[2] , (0xB43536D7L > 0x43474B68L))) >= (((g_18 < ((safe_add_func_int8_t_s_s(l_722, 0xFAL)) & (safe_mod_func_int8_t_s_s(((((((l_775 | l_776) || g_101) || g_717) , l_1281) <= 6L) <= 0x62L), 0x36L)))) && l_1052) > 0x8EL)) != l_1281) == l_1281);
            }
            --l_779;
        }
        else
        {
            int16_t l_786 = 8L;
            int32_t l_789 = 2L;
            int32_t l_791 = 0xB2B08DC3L;
            uint32_t l_794 = 0x67A078F5L;
            i = (safe_rshift_func_int16_t_s_u(l_790, 9));
            if (l_1281)
                break;
            for (i = 0; (i <= (-8)); i--)
            {
                return l_786;
            }
            for (g_694 = 2; (g_694 < 14); g_694 = safe_add_func_uint16_t_u_u(g_694, 3))
            {
                l_794--;
            }
        }
    };


                    l_877[2][0]--;
                        --l_885;
                    }
                    g_120[1] = (((safe_lshift_func_int8_t_s_u((-7L), 4)) , 1UL) <= (safe_lshift_func_uint16_t_u_u(((g_97[5] >= p_35) < (safe_sub_func_uint8_t_u_u(p_35, (+((+(safe_mod_func_int16_t_s_s(((((g_717 == (safe_lshift_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s((((((safe_rshift_func_uint8_t_u_u(0xA3L, 3)) <= (((safe_sub_func_uint8_t_u_u((g_101 ^ (((g_97[2] <= 7UL) >= 0x5416L) < g_777)), l_846)) < (-3L)) , p_34)) & 0x514BL) == 0x4A10A230L) > 1UL), g_717)) & 0x80BDL), 1)) <= 0xB0L), g_849[0]))) == p_34) ^ p_35) == p_34), 0xC7B8L))) < l_877[0][0]))))), 5)));
                }

{
                        int8_t l_524 = (-8L);
                        l_524 = g_100;
                        l_1329 &= l_524;
                    }

                    l_778 = ((g_97[2] > ((safe_mod_func_uint16_t_u_u((p_34 < p_34), (safe_mod_func_int16_t_s_s(((safe_add_func_uint8_t_u_u((l_885 , (safe_mod_func_uint8_t_u_u(((((~((l_778 & 0x0E4E5FD7L) ^ ((((l_844 == ((((g_22 | ((((((safe_rshift_func_uint8_t_u_s(g_22, p_34)) & 0xC189E11AL) > 0x02171C1CL) , p_34) < g_97[2]) , 0xABAFL)) && 0x0FL) , 0x444BL) >= 9L)) , 0xCAB1L) || g_101) && 0x2CF198DBL))) ^ 7UL) , 0x5D7CL) ^ l_919), g_18))), p_34)) , g_143), p_35)))) ^ (-1L))) <= 0x08L);
                for (l_919 = 0; (l_919 != (-11)); --l_919)
                {
                    uint8_t l_923 = 0UL;
                    int32_t l_937 = 0xB482D4E8L;
                    int32_t l_938 = 0x297BE1A5L;
                    int32_t l_939 = 0xFF539210L;
                    int32_t l_1001 = 0x1C89D44EL;

l_923 += 1;


                    ++l_923;


if (l_848)
                            break;

                    l_875 ^= l_1329;

                    if ((((-1L) != ((safe_sub_func_uint8_t_u_u(l_820, (~((p_34 || ((safe_lshift_func_int8_t_s_s(l_844, ((~0xB7L) & (((~(safe_rshift_func_uint8_t_u_u(0xD5L, ((g_100 , g_849[0]) == g_100)))) || p_34) & l_820)))) , g_935)) == 0xDBB7L)))) <= g_100)) != l_936[0][5]))
                    {
                        g_120[1] = l_725[2];
                        --l_940[0];
                    }
                    else
                    {
                        int32_t l_956 = 0xA1C5A82EL;

for (l_1007 = 13; (l_1007 >= 1); l_1007 = safe_sub_func_int32_t_s_s(l_1007, 9))
                    {
                        uint8_t l_1840 = 0x4FL;
                        int32_t l_1843 = 1L;
                        int32_t l_1850 = (-10L);
                        int32_t l_1851 = 0x86429966L;
                        int32_t l_1852 = 0xCA3D88B8L;
                        int32_t l_1855 = 1L;
                        l_1840 = l_875;
                        --g_777;
                        --g_1217;
                    };


                    g_120[1] = ((((((g_849[0] ^ l_801[6][9]) & 0x3A09L) == ((g_97[3] == (safe_lshift_func_uint8_t_u_s((((p_34 , (p_35 < ((g_935 || (((((safe_mod_func_int16_t_s_s((((safe_mod_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((((safe_mod_func_uint16_t_u_u(g_120[0], g_935)) & p_35) != l_938), 2)), g_849[0])) <= l_953) || l_953), p_35)) <= l_801[7][5]) || 0xFCA679B8L) == g_120[1]) > l_801[0][3])) || l_923))) != l_953) , l_821[6][1]), p_34))) < 0xABL)) == 65535UL) , 0x310916CAL) , g_120[0]);
                        l_884[0][0] = ((safe_sub_func_int8_t_s_s(l_956, ((safe_sub_func_uint32_t_u_u((safe_add_func_int8_t_s_s((((((safe_add_func_int8_t_s_s((((safe_mod_func_int8_t_s_s(g_89, (p_34 ^ 0x4C3BL))) & ((+p_34) == (1L < g_100))) || (((safe_add_func_int8_t_s_s((((l_725[0] & ((+(-5L)) >= 0xEFL)) < l_820) , (-9L)), 0x84L)) >= l_936[0][5]) > 0x4C33D59BL)), g_143)) ^ g_849[0]) ^ 1L) ^ l_843) > g_540), g_540)), g_97[2])) | 0x0AD02AAFL))) , (-1L));
                        l_821[3][2] = (((safe_rshift_func_uint8_t_u_s((((p_35 <= 0xDED1L) == (g_935 ^ ((safe_add_func_uint16_t_u_u(((safe_unary_minus_func_uint16_t_u((safe_lshift_func_uint8_t_u_u((((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s(((l_980 == (safe_rshift_func_uint16_t_u_u(0x5CC1L, ((safe_lshift_func_uint16_t_u_u((safe_add_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_lshift_func_uint8_t_u_u((((g_97[2] == ((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u(g_97[2], (((p_34 || (((safe_rshift_func_int16_t_s_s(((((safe_add_func_uint32_t_u_u(0x04849C4EL, p_34)) <= p_34) <= l_937) ^ g_120[1]), g_540)) > l_956) , l_939)) <= 7L) == g_18))) != g_22), g_89)) >= g_694)) < 255UL) != g_89), 1)), g_694)) != g_143) , l_923) > 8L), p_34)), 9)) , 0xB22CL)))) > 0xD0D7BB55L), 7)), 3UL)) == p_34) | p_34), l_884[0][5])))) ^ l_880), l_956)) <= p_34))) >= p_34), 1)) , 0xE75EL) == 0x5EECL);
                    }

{
            int32_t l_1415 = (-1L);
            int i;

for (l_922 = 0; l_922 < 6; l_922++)
    {
        for (g_2469 = 0; g_2469 < 2; g_2469++)
        {
            transparent_crc(g_1540[l_922][g_2469], "g_1540[l_922][g_2469]", l_1415);
            if (l_1415) printf("index = [%d][%d]\n", l_922, g_2469);

        }
    };


                    l_846 &= (g_120[g_100] ^ (((((((-1L) == ((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((g_120[g_100] >= ((((((safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(((safe_mod_func_int16_t_s_s((((0xC0L >= ((g_849[g_2431] > ((((safe_add_func_int16_t_s_s(g_935, (safe_rshift_func_int16_t_s_s(((safe_add_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u(g_540, l_880)) == (safe_unary_minus_func_uint32_t_u((((safe_sub_func_int16_t_s_s(0x780FL, 0xB48CL)) <= g_120[1]) ^ g_540)))), g_2467)) , g_935), g_935)))) , g_120[g_100]) && p_34) ^ g_540)) > 0xFD94L)) | g_18) == g_1217), g_120[4])) >= 0x6DB3L), 13)), 255UL)) , g_935) ^ g_935) || g_935) ^ g_935) != g_120[1])), 4)), g_935)), 0x0CL)), 0x61L)) , l_1415)) <= 0x17E2L) >= l_846) | g_100) && l_1191[1]) || g_18));
            return g_120[g_100];
        }

                    g_120[1] ^= (safe_add_func_uint32_t_u_u(l_939, l_938));
                    return l_1001;
                }
            }
            for (g_143 = 17; (g_143 <= 34); g_143 = safe_add_func_int32_t_s_s(g_143, 2))
            {
                uint32_t l_1004 = 0x3C1B13C2L;
                if (p_35)
                    break;
                if (l_1004)
                    break;
            }
        }
        for (l_922 = (-29); (l_922 != (-3)); l_922++)
        {

if (l_1439[5])
                        break;

                    l_1007--;

{
    int8_t l_725[4] = {0x6CL, (-1L), 0x6CL, (-1L)};
    int32_t l_778 = 0L;
    int8_t l_790 = 0xCFL;
    int32_t l_793 = (-10L);
    uint32_t l_877[3][1];
    int8_t l_880 = 0x4CL;
    int32_t l_919 = 0x24F96B7BL;
    int32_t l_922 = 1L;
    uint32_t l_940[8] = {0x70725F80L, 0x971E3B31L, 0x70725F80L, 0x971E3B31L, 0x70725F80L, 0x971E3B31L, 0x70725F80L, 0x971E3B31L};
    uint32_t l_980 = 0xC75D6C4FL;
    uint8_t l_1007 = 0x6CL;
    uint32_t l_1052 = 0xC1E7B1A1L;
    int8_t l_1191[5] = {(-3L), 2L, (-3L), 2L, (-3L)};
    uint32_t l_1281 = 0x7B51DD50L;
    int32_t l_1327 = 0xC40777EBL;
    int32_t l_1329 = 0x90371E5EL;
    uint32_t l_1423 = 0UL;
    uint32_t l_1433 = 18446744073709551615UL;
    int32_t l_1439[6];
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 1; j++)
            l_877[i][j] = 0x46984ABCL;
    }
    for (i = 0; i < 6; i++)
        l_1439[i] = 9L;
    for (g_2431 = 0; (g_2431 != 4); ++g_2431)
    {
        uint8_t l_722 = 0xE0L;
        int32_t l_770 = 0x6E81370EL;
        uint32_t l_779 = 1UL;
        int32_t l_792 = 0x2E89F638L;
        if ((safe_lshift_func_int16_t_s_u((g_694 <= l_722), (safe_sub_func_int8_t_s_s(((l_725[2] <= ((((safe_sub_func_int32_t_s_s(l_980, (safe_mod_func_uint32_t_u_u((0x7ABE5FAFL >= ((safe_sub_func_uint8_t_u_u(g_120[1], l_722)) , ((safe_lshift_func_int8_t_s_u(l_722, (((((((safe_lshift_func_int8_t_s_s(l_980, 3)) | l_725[2]) || l_880) >= g_694) <= g_97[5]) , l_722) >= 4294967295UL))) == g_694))), l_725[2])))) >= g_694) ^ 0UL) != 8L)) ^ 0x0968FE10L), l_1052)))))
        {
            uint32_t l_749 = 4294967288UL;
            if ((~(safe_add_func_uint32_t_u_u(((0L != (((l_725[2] || (safe_sub_func_int8_t_s_s(0x65L, (safe_mod_func_uint32_t_u_u(l_1052, l_722))))) ^ ((safe_add_func_uint16_t_u_u((l_790 , (safe_lshift_func_int8_t_s_u((0xA7L & 6L), 0))), (((g_694 == l_1281) >= g_18) < g_694))) < (-1L))) < g_694)) , 0x11329388L), 4294967295UL))))
            {
                int32_t l_769[1];
                int i;
                for (i = 0; i < 1; i++)
                    l_769[i] = 0x804970A5L;
                g_120[1] = 1L;
                if (g_694)
                    continue;
                l_749 = (safe_rshift_func_uint16_t_u_u(g_97[2], 13));
                l_770 = (safe_lshift_func_int8_t_s_s((5UL >= (0UL < (safe_add_func_int8_t_s_s((((safe_rshift_func_int16_t_s_s((g_18 != (safe_sub_func_int32_t_s_s((safe_unary_minus_func_int32_t_s((safe_mod_func_int8_t_s_s((safe_mod_func_int32_t_s_s(0x5B48709BL, ((safe_rshift_func_int16_t_s_s(g_18, g_694)) || 3L))), (safe_sub_func_int32_t_s_s(g_694, ((((safe_rshift_func_int16_t_s_u(g_694, 7)) || g_18) || l_769[0]) <= l_1052))))))), l_980))), 6)) != g_694) != g_100), l_722)))), l_1052));
            }
            else
            {
                int16_t l_775 = (-4L);
                int32_t l_776 = (-3L);
                g_777 = ((((l_1281 ^ (l_725[2] , (0xB43536D7L > 0x43474B68L))) >= (((g_18 < ((safe_add_func_int8_t_s_s(l_722, 0xFAL)) & (safe_mod_func_int8_t_s_s(((((((l_775 | l_776) || g_694) || l_880) , l_1052) <= 6L) <= 0x62L), 0x36L)))) && l_1281) > 0x8EL)) != l_1052) == l_1052);
            }
            --l_779;
        }
        else
        {
            int16_t l_786 = 8L;
            int32_t l_789 = 2L;
            int32_t l_791 = 0xB2B08DC3L;
            uint32_t l_794 = 0x67A078F5L;
            l_778 = (safe_rshift_func_int16_t_s_u(l_790, 9));
            if (l_1052)
                break;
            for (l_778 = 0; (l_778 <= (-8)); l_778--)
            {
                return l_786;
            }
            for (g_694 = 2; (g_694 < 14); g_694 = safe_add_func_uint16_t_u_u(g_694, 3))
            {
                l_794--;
            }
        }
    }
    if ((l_1052 == g_694))
    {
        int16_t l_801[8][10] = {{0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}, {0xBFACL, 0L, (-1L), (-1L), 0L, 0xBFACL, 0L, (-1L), (-1L), 0L}};
        int32_t l_821[9][7] = {{0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}, {0x9B3BBBB0L, 0x33ED253BL, 2L, 4L, 2L, 0x33ED253BL, 0x9B3BBBB0L}};
        uint32_t l_843 = 4294967290UL;
        int32_t l_1046 = 0x07FD8AA4L;
        int i, j;
        for (l_1281 = 0; (l_1281 > 15); ++l_1281)
        {
            g_120[1] = 0x19D1A3FEL;
            if (g_694)
                continue;
        }
        for (l_793 = 0; (l_793 <= 24); l_793 = safe_add_func_uint16_t_u_u(l_793, 2))
        {
            int32_t l_820 = (-1L);
            const int32_t l_844 = 1L;
            int32_t l_846 = 0xEFBA0CA9L;
            int32_t l_848 = 0x52FBE6A1L;
            uint32_t l_885 = 2UL;
            int32_t l_936[2][6] = {{0L, 0L, (-3L), 0L, 0L, (-3L)}, {0L, 0L, (-3L), 0L, 0L, (-3L)}};
            int i, j;
            l_801[7][5] = g_694;
            for (g_777 = 0; (g_777 <= 7); g_777 += 1)
            {
                int i, j;
                g_120[3] = l_801[g_777][g_777];
                l_821[6][1] = (safe_rshift_func_uint8_t_u_s((safe_lshift_func_uint8_t_u_u((g_97[2] , (safe_lshift_func_int16_t_s_u((((safe_rshift_func_int16_t_s_u((safe_add_func_uint8_t_u_u((4294967286UL != 0x9CDCB11EL), ((l_801[g_777][g_777] ^ (l_880 == (safe_mod_func_int16_t_s_s(((((2UL | (safe_mod_func_int8_t_s_s((l_1052 || ((safe_add_func_int16_t_s_s((g_97[2] , (0x978C1B61L > 4294967291UL)), l_820)) < 0xB988L)), l_1052))) || l_790) >= g_694) == 0x1F887AC6L), l_1052)))) > 6UL))), 6)) != g_694) <= l_801[7][5]), g_694))), 3)), l_801[7][5]));
            }
            if ((0x4DF543CEL && l_790))
            {
                uint32_t l_847 = 0xB97BAC9CL;
                for (l_880 = 0; (l_880 >= (-10)); l_880--)
                {
                    const uint32_t l_845 = 0xB19552AFL;
                    l_846 = (((safe_sub_func_int8_t_s_s(0x65L, (safe_unary_minus_func_int8_t_s((+(g_97[2] < (safe_add_func_uint32_t_u_u(((safe_rshift_func_int8_t_s_u(((l_1052 >= g_100) || l_790), (((safe_sub_func_uint16_t_u_u(((((safe_rshift_func_uint8_t_u_s(((((safe_sub_func_int32_t_s_s((safe_mod_func_uint8_t_u_u(l_1052, (safe_add_func_uint32_t_u_u(l_801[7][1], (~((l_790 <= (0xCC872D8FL == 4UL)) && g_120[1])))))), g_694)) & l_843) & g_694) ^ l_1281), g_97[2])) < (-1L)) >= 0x60360610L) ^ 0x1EL), 0xBA9AL)) , l_844) , l_1052))) == 3L), 4294967295UL)))))))) <= l_845) != g_694);
                    if (l_847)
                        break;
                    if (g_694)
                        continue;
                }
                g_120[1] = 0x53887F5CL;
            }
            else
            {
                uint16_t l_875 = 6UL;
                int32_t l_881 = 0L;
                int32_t l_884[2][7] = {{0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L}, {0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L, 0xB1F54B37L, (-9L), 0xB1F54B37L}};
                uint16_t l_953 = 0x2EE0L;
                int i, j;
                g_849[0]--;
                for (l_848 = 0; (l_848 >= 0); l_848 -= 1)
                {
                    int32_t l_876 = 1L;
                    int i;
                    if ((safe_lshift_func_uint16_t_u_s((+(safe_sub_func_uint8_t_u_u(g_849[l_848], g_694))), 8)))
                    {
                        g_120[1] = 0xB8ED6298L;
                        if (g_694)
                            continue;
                        l_846 &= (safe_mod_func_uint32_t_u_u(g_694, 0xE4729DD1L));
                    }
                    else
                    {
                        uint16_t l_861 = 0x987DL;
                        g_120[1] = ((safe_add_func_int16_t_s_s(0x6D2DL, l_861)) > 9L);
                        return g_849[l_848];
                    }
                    for (g_777 = 0; (g_777 <= 3); g_777 += 1)
                    {
                        uint8_t l_870 = 0x7BL;
                        int32_t l_882 = (-8L);
                        int32_t l_883 = (-1L);
                        l_875 &= ((g_120[3] , (safe_add_func_int32_t_s_s((((((g_849[0] & ((safe_sub_func_uint16_t_u_u(g_120[4], ((safe_sub_func_int32_t_s_s(((safe_sub_func_uint16_t_u_u(l_790, (l_870 & (safe_mod_func_uint32_t_u_u(((l_844 != (g_97[0] || g_97[3])) , (safe_lshift_func_int8_t_s_u((g_120[1] , l_820), l_980))), l_1052))))) , g_18), 4294967295UL)) , l_1052))) || l_980)) ^ l_1052) & l_1281) != g_777) & g_694), l_870))) > 8UL);
                        l_877[2][0]--;
                        --l_885;
                    }
                    g_120[1] = (((safe_lshift_func_int8_t_s_u((-7L), 4)) , 1UL) <= (safe_lshift_func_uint16_t_u_u(((g_97[5] >= g_694) < (safe_sub_func_uint8_t_u_u(g_694, (+((+(safe_mod_func_int16_t_s_s(((((l_790 == (safe_lshift_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s((((((safe_rshift_func_uint8_t_u_u(0xA3L, 3)) <= (((safe_sub_func_uint8_t_u_u((g_694 ^ (((g_97[2] <= 7UL) >= 0x5416L) < g_777)), l_846)) < (-3L)) , l_1052)) & 0x514BL) == 0x4A10A230L) > 1UL), l_790)) & 0x80BDL), 1)) <= 0xB0L), g_849[0]))) == l_1052) ^ g_694) == l_1052), 0xC7B8L))) < l_877[0][0]))))), 5)));
                }
                l_778 = ((g_97[2] > ((safe_mod_func_uint16_t_u_u((l_1052 < l_1052), (safe_mod_func_int16_t_s_s(((safe_add_func_uint8_t_u_u((l_885 , (safe_mod_func_uint8_t_u_u(((((~((l_778 & 0x0E4E5FD7L) ^ ((((l_844 == ((((l_980 | ((((((safe_rshift_func_uint8_t_u_s(l_980, l_1052)) & 0xC189E11AL) > 0x02171C1CL) , l_1052) < g_97[2]) , 0xABAFL)) && 0x0FL) , 0x444BL) >= 9L)) , 0xCAB1L) || g_694) && 0x2CF198DBL))) ^ 7UL) , 0x5D7CL) ^ l_919), g_18))), l_1052)) , l_1281), g_694)))) ^ (-1L))) <= 0x08L);
                for (l_919 = 0; (l_919 != (-11)); --l_919)
                {
                    uint8_t l_923 = 0UL;
                    int32_t l_937 = 0xB482D4E8L;
                    int32_t l_938 = 0x297BE1A5L;
                    int32_t l_939 = 0xFF539210L;
                    int32_t l_1001 = 0x1C89D44EL;
                    ++l_923;
                    if ((((-1L) != ((safe_sub_func_uint8_t_u_u(l_820, (~((l_1052 || ((safe_lshift_func_int8_t_s_s(l_844, ((~0xB7L) & (((~(safe_rshift_func_uint8_t_u_u(0xD5L, ((g_100 , g_849[0]) == g_100)))) || l_1052) & l_820)))) , g_694)) == 0xDBB7L)))) <= g_100)) != l_936[0][5]))
                    {
                        g_120[1] = l_725[2];
                        --l_940[0];
                    }
                    else
                    {
                        int32_t l_956 = 0xA1C5A82EL;
                        g_120[1] = ((((((g_849[0] ^ l_801[6][9]) & 0x3A09L) == ((g_97[3] == (safe_lshift_func_uint8_t_u_s((((l_1052 , (g_694 < ((g_694 || (((((safe_mod_func_int16_t_s_s((((safe_mod_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((((safe_mod_func_uint16_t_u_u(g_120[0], g_694)) & g_694) != l_938), 2)), g_849[0])) <= l_953) || l_953), g_694)) <= l_801[7][5]) || 0xFCA679B8L) == g_120[1]) > l_801[0][3])) || l_923))) != l_953) , l_821[6][1]), l_1052))) < 0xABL)) == 65535UL) , 0x310916CAL) , g_120[0]);
                        l_884[0][0] = ((safe_sub_func_int8_t_s_s(l_956, ((safe_sub_func_uint32_t_u_u((safe_add_func_int8_t_s_s((((((safe_add_func_int8_t_s_s((((safe_mod_func_int8_t_s_s(l_880, (l_1052 ^ 0x4C3BL))) & ((+l_1052) == (1L < g_100))) || (((safe_add_func_int8_t_s_s((((l_725[0] & ((+(-5L)) >= 0xEFL)) < l_820) , (-9L)), 0x84L)) >= l_936[0][5]) > 0x4C33D59BL)), l_1281)) ^ g_849[0]) ^ 1L) ^ l_843) > g_694), g_694)), g_97[2])) | 0x0AD02AAFL))) , (-1L));
                        l_821[3][2] = (((safe_rshift_func_uint8_t_u_s((((g_694 <= 0xDED1L) == (g_694 ^ ((safe_add_func_uint16_t_u_u(((safe_unary_minus_func_uint16_t_u((safe_lshift_func_uint8_t_u_u((((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s(((l_980 == (safe_rshift_func_uint16_t_u_u(0x5CC1L, ((safe_lshift_func_uint16_t_u_u((safe_add_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_lshift_func_uint8_t_u_u((((g_97[2] == ((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u(g_97[2], (((l_1052 || (((safe_rshift_func_int16_t_s_s(((((safe_add_func_uint32_t_u_u(0x04849C4EL, l_1052)) <= l_1052) <= l_937) ^ g_120[1]), g_694)) > l_956) , l_939)) <= 7L) == g_18))) != l_980), l_880)) >= g_694)) < 255UL) != l_880), 1)), g_694)) != l_1281) , l_923) > 8L), l_1052)), 9)) , 0xB22CL)))) > 0xD0D7BB55L), 7)), 3UL)) == l_1052) | l_1052), l_884[0][5])))) ^ l_880), l_956)) <= l_1052))) >= l_1052), 1)) , 0xE75EL) == 0x5EECL);
                    }
                    g_120[1] ^= (safe_add_func_uint32_t_u_u(l_939, l_938));
                    return l_1001;
                }
            }
            for (l_1281 = 17; (l_1281 <= 34); l_1281 = safe_add_func_int32_t_s_s(l_1281, 2))
            {
                uint32_t l_1004 = 0x3C1B13C2L;
                if (g_694)
                    break;
                if (l_1004)
                    break;
            }
        }
        for (l_922 = (-29); (l_922 != (-3)); l_922++)
        {
            l_1007--;
            if (g_694)
                continue;
            for (g_694 = 0; (g_694 == (-12)); g_694 = safe_sub_func_int8_t_s_s(g_694, 2))
            {
                return g_849[0];
            }
        }
        l_793 = ((l_1052 || (l_801[6][3] & g_849[0])) > (safe_lshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u(g_694, (safe_mod_func_int8_t_s_s(((((safe_lshift_func_int16_t_s_u((safe_rshift_func_uint8_t_u_s(g_694, (+((safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((((+((safe_mod_func_int16_t_s_s(((((safe_add_func_int8_t_s_s((g_18 ^ (safe_add_func_int8_t_s_s((((safe_rshift_func_uint8_t_u_s((((((safe_rshift_func_uint8_t_u_s(((l_821[6][1] ^ ((((((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u((0x5FBED003L || ((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_s((-5L), 0)), 5)) != l_790)), l_1052)), l_1046)) < 0x3EL) , 0xE788D646L) == l_801[3][2]) , l_725[2]) || l_801[5][3])) || 0x23L), l_801[7][5])) , 0x32L) & 255UL) || l_1052) && l_1052), l_877[2][0])) , l_1046) , l_880), 0x67L))), 0UL)) >= 0x78D41AC2L) , g_694) ^ 255UL), l_725[2])) , 0x1712L)) , l_919) , g_694), l_1052)), l_1046)) && l_1281)))), l_1052)) ^ g_777) , g_694) , g_849[0]), l_793)))), g_694)));
    }
    else
    {
        int32_t l_1051[4] = {0x0A2DD9A0L, 0L, 0x0A2DD9A0L, 0L};
        int32_t l_1081 = 1L;
        int32_t l_1226[1][2][5] = {{{0L, (-1L), 0L, (-1L), 0L}, {0L, (-1L), 0L, (-1L), 0L}}};
        int32_t l_1273 = 0x20573342L;
        int32_t l_1359 = 0x441BD344L;
        uint8_t l_1361 = 0x58L;
        int32_t l_1369 = (-7L);
        int i, j, k;
        l_1051[0] = (safe_lshift_func_uint16_t_u_s((safe_lshift_func_int8_t_s_s(g_694, 1)), 14));
        l_1052 |= l_940[3];
        for (g_777 = 0; (g_777 > 1); ++g_777)
        {
            uint8_t l_1069 = 1UL;
            int8_t l_1216 = 0xBDL;
            int32_t l_1219 = 0x1BE859F7L;
            int32_t l_1224 = 7L;
            int32_t l_1227 = (-6L);
            int32_t l_1228 = 0x1EE42556L;
            int32_t l_1229 = 0xD31B29F5L;
            int32_t l_1231[6];
            uint32_t l_1233 = 1UL;
            int i;
            for (i = 0; i < 6; i++)
                l_1231[i] = 7L;
            if ((l_1052 , (((safe_add_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((safe_sub_func_int32_t_s_s(((-3L) == ((safe_add_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(0x6B9EL, l_1052)), ((safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s((((l_1069 , ((((~(l_1051[0] , ((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u((((g_694 >= (~((0x941CB444L | g_849[0]) || g_18))) < l_1052) == l_1051[0]), 1UL)) <= l_1052), g_694)) > g_694))) == 6L) <= 0L) , g_694)) & 5L) , l_1052), 1UL)), 4294967288UL)) >= l_793))) != l_1052)), 0xFF1D970AL)), 1L)), l_1052)) , l_790) & g_694)))
            {
                uint8_t l_1080 = 1UL;
                l_919 = (safe_sub_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u(1UL, l_1051[3])), ((g_849[0] < l_1069) != (1L > l_880))));
                g_120[1] = ((g_849[0] || 0xD3L) <= l_919);
                if (l_1080)
                    break;
                if (l_1069)
                    break;
            }
            else
            {
                int16_t l_1094 = 0xECC4L;
                int32_t l_1149[2];
                int16_t l_1163[7][10];
                int i, j;
                for (i = 0; i < 2; i++)
                    l_1149[i] = 0xBA560EB5L;
                for (i = 0; i < 7; i++)
                {
                    for (j = 0; j < 10; j++)
                        l_1163[i][j] = 6L;
                }
                l_1081 = (g_694 == g_694);
                for (g_694 = 16; (g_694 != (-28)); g_694 = safe_sub_func_int16_t_s_s(g_694, 5))
                {
                    int32_t l_1095 = (-6L);
                    for (l_1281 = 0; (l_1281 <= 0); l_1281 += 1)
                    {
                        int i, j;
                        return l_877[l_1281][l_1281];
                    }
                    l_1095 = ((((g_120[1] || (-5L)) && ((((safe_lshift_func_int16_t_s_u((((safe_rshift_func_int16_t_s_u((g_694 || (((0xBBL ^ (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(g_120[1], (((((-1L) > (g_777 , 1L)) , ((safe_add_func_int16_t_s_s(l_1052, l_1052)) & 4294967289UL)) <= l_1052) != l_1069))), g_120[1]))) | g_694) == g_694)), l_1052)) >= 0x20L) , 0x45CAL), g_694)) > (-2L)) <= 0x8BB0L) < l_1094)) , l_1069) ^ g_694);
                    for (l_919 = 0; (l_919 <= 0); l_919 += 1)
                    {
                        int i, j;
                        g_120[2] = l_877[l_919][l_919];
                    }
                }
                if ((l_1052 , l_1052))
                {
                    uint16_t l_1101[10] = {0xEA04L, 0xEA04L, 0UL, 0xEA04L, 0xEA04L, 0UL, 0xEA04L, 0xEA04L, 0UL, 0xEA04L};
                    int i;
                    if (l_790)
                        break;
                    if ((safe_add_func_int8_t_s_s((safe_add_func_int8_t_s_s((((g_694 == ((((((((!((l_1052 ^ (l_1069 || ((l_1101[9] & ((-7L) | ((((safe_sub_func_uint8_t_u_u(g_694, (safe_add_func_uint32_t_u_u(l_1281, 0x1CB4D9C6L)))) && l_790) >= l_877[2][0]) >= l_1052))) <= l_980))) <= 4L)) , l_1052) || l_1052) != l_1052) , g_694) , 0xDF52L) , g_100) ^ l_1069)) || l_880) , 0L), 255UL)), l_1052)))
                    {
                        uint16_t l_1114[5][1][4] = {{{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}};
                        int i, j, k;
                        l_922 = ((safe_sub_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(g_694, (8L & (-1L)))), 5UL)) ^ (safe_sub_func_uint32_t_u_u((0x9B71DE32L ^ (l_1052 < l_1052)), (+(((l_1101[9] != g_120[0]) <= 0x33L) , l_1051[0])))));
                        g_120[1] ^= (((((!((l_1114[4][0][3] == (safe_mod_func_uint32_t_u_u(((((safe_lshift_func_int8_t_s_s((safe_add_func_int16_t_s_s((+((!(g_849[0] > l_880)) ^ 0x0043E281L)), (g_97[2] >= l_1281))), ((safe_sub_func_int8_t_s_s((~((((safe_mod_func_uint16_t_u_u((0xC6L || 0x36L), l_1052)) & 0x68L) || g_694) , l_1051[0])), l_1094)) != 0x2E20L))) || l_1052) | l_1094) & g_694), l_1052))) > 1UL)) < 1UL) > g_694) > 0x5E87ADE6L) == 0x38C86F29L);
                    }
                    else
                    {
                        int8_t l_1148 = 0x89L;
                        l_1149[1] = ((0x88L > ((((g_694 || (safe_mod_func_uint32_t_u_u(l_1052, (safe_add_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(((l_1052 , (0L ^ (((safe_add_func_int8_t_s_s(((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(g_694, ((g_97[2] | 0x826CL) < ((((safe_rshift_func_uint8_t_u_s(l_980, g_694)) <= 253UL) | l_1094) >= l_1148)))), l_1052)) < l_980), l_1148)) || g_97[2]) | 0x9933L))) || l_1281), 0L)), l_1052)) >= 0x23DDBF23L), g_100)), 1)) && l_1069), 0x57543A32L))))) != 1L) , l_1052) | 4294967295UL)) ^ 0xB771L);
                        if (g_694)
                            break;
                        g_120[1] = (safe_mod_func_int16_t_s_s((((((safe_lshift_func_int8_t_s_s((((safe_sub_func_uint32_t_u_u((((((safe_mod_func_int16_t_s_s(0L, (((((+65533UL) > ((safe_mod_func_uint32_t_u_u((safe_add_func_int16_t_s_s(((l_1149[1] , ((g_2431 >= g_694) >= (l_1163[1][2] || (((safe_sub_func_int16_t_s_s((g_694 != (l_1101[9] >= (l_1051[2] == 4294967295UL))), l_1052)) ^ l_1281) & g_694)))) && g_694), g_694)), l_1051[1])) > 2L)) || g_694) < g_777) , l_1081))) < l_1052) && g_694) ^ 0x5443L) < g_777), g_694)) , l_1149[0]) , g_694), 2)) != l_1101[6]) <= g_694) , l_1052) >= l_1094), g_18));
                    }
                    l_919 = (safe_rshift_func_int8_t_s_s((l_1081 ^ 4294967295UL), 0));
                }
                else
                {
                    for (g_100 = 3; (g_100 >= 1); g_100 -= 1)
                    {
                        int i;
                        if (g_120[g_100])
                            break;
                        if (l_725[g_100])
                            break;
                        return g_694;
                    }
                }
            }
            if (g_2431)
            {
                uint16_t l_1172 = 0x80D0L;
                l_922 &= ((((l_1052 >= l_1172) && (g_849[0] , (((((0x4E57L != (safe_unary_minus_func_uint8_t_u((((((safe_sub_func_uint16_t_u_u(((safe_sub_func_int16_t_s_s((!((safe_unary_minus_func_uint16_t_u(g_694)) | l_1052)), (safe_rshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u(0UL, ((l_1069 , (safe_sub_func_int32_t_s_s((((((safe_add_func_int8_t_s_s((((!g_2431) , g_694) <= l_725[0]), g_694)) != l_1172) > l_1191[1]) < l_1172) & 0UL), 0x349E8373L))) | g_694))), l_980)), g_694)))) & g_2431), (-5L))) < l_1069) , g_849[0]) | l_1172) >= l_1069)))) && g_694) != 0UL) | g_777) | 0x7351L))) & l_725[3]) , l_980);
                g_1217 |= ((safe_mod_func_int16_t_s_s((-4L), (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((((safe_add_func_int16_t_s_s((safe_lshift_func_int16_t_s_u((safe_mod_func_int32_t_s_s((((((safe_lshift_func_int8_t_s_u(g_849[0], (!0xE43BDF21L))) || ((((((safe_lshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((~(safe_lshift_func_int16_t_s_s(l_1052, 11))), 6)), 6)) , 0x9037L) || g_777) ^ ((g_694 & (l_1052 && (safe_rshift_func_uint8_t_u_s(l_1052, l_1281)))) != l_1081)) >= g_777) && g_849[0])) > g_120[1]) , 0xB8L) ^ l_1052), 4294967295UL)), l_880)), (-1L))) <= l_880) ^ l_1069), l_1172)), 0xFBL)))) > l_1216);
            }
            else
            {
                int32_t l_1218 = 0L;
                int32_t l_1220 = 0xD6A84518L;
                int32_t l_1221 = 0x3E2F8B07L;
                int32_t l_1222 = 0xBC228DECL;
                int32_t l_1223 = 0L;
                int32_t l_1225 = 0x92788A2FL;
                int32_t l_1230 = 0x8A193837L;
                int32_t l_1232[1][1];
                int i, j;
                for (i = 0; i < 1; i++)
                {
                    for (j = 0; j < 1; j++)
                        l_1232[i][j] = 0xBE2CE0ADL;
                }
                l_1233++;
            }
            if (g_777)
            {
                uint32_t l_1241[4][8] = {{0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}, {0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}, {0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}, {0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}};
                uint16_t l_1252 = 0x759AL;
                int i, j;
                g_120[4] |= ((safe_lshift_func_uint16_t_u_s(6UL, 8)) , ((safe_unary_minus_func_int32_t_s((safe_sub_func_int16_t_s_s((((((l_1241[2][6] | 0L) & ((((safe_rshift_func_uint16_t_u_u(((safe_unary_minus_func_int16_t_s(l_1191[0])) & (l_1052 , (((((safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u((l_1052 , (safe_add_func_int16_t_s_s((((~l_1252) , (safe_add_func_uint16_t_u_u((((((g_18 | (safe_lshift_func_uint16_t_u_s((safe_add_func_uint8_t_u_u(((((0x1CA4L < l_1052) && l_880) | g_97[2]) ^ g_694), g_694)), l_1052))) != l_1052) || l_790) > l_1051[2]) , 0x6DB4L), l_778))) || l_1052), 0x5D57L))), g_97[2])), l_1219)) || 1UL) || g_694) | l_1052) != g_849[0]))), l_790)) && 1L) > 0x1DC0L) , g_694)) != 0x35A6L) || 0xE981L) | g_777), 1L)))) , g_777));
            }
            else
            {
                uint16_t l_1263[6][10] = {{0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}};
                int32_t l_1277[9];
                int16_t l_1321 = 0x3AFEL;
                int i, j;
                for (i = 0; i < 9; i++)
                    l_1277[i] = (-1L);
                for (l_922 = 0; (l_922 <= (-8)); --l_922)
                {
                    uint8_t l_1265 = 0xA0L;
                    int32_t l_1272 = 0xA92A5564L;
                    uint8_t l_1274 = 1UL;
                    int32_t l_1325 = 0x05F0F06DL;
                    int32_t l_1326 = 0xA526867EL;
                    int8_t l_1360 = 0xE8L;
                    if (((safe_rshift_func_int16_t_s_s(1L, (l_790 < ((l_1263[4][9] && (!(l_1265 || g_694))) , ((((g_694 , (safe_sub_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_u(((((safe_lshift_func_uint8_t_u_u(g_97[2], 2)) >= g_100) | 8L) , l_1281), g_849[0])) ^ g_120[1]), l_1052))) == g_18) >= g_694) < l_1263[0][9]))))) >= l_1081))
                    {
                        uint32_t l_1278 = 0x7A1781B4L;
                        l_1274--;
                        l_1278--;
                    }
                    else
                    {
                        uint8_t l_1292 = 255UL;
                        int32_t l_1301 = 0L;
                        l_1281 ^= 0x10E3B930L;
                        l_1277[4] &= (safe_rshift_func_int16_t_s_u((safe_mod_func_uint16_t_u_u((9UL || ((g_849[0] < ((g_1217 >= g_849[0]) || g_694)) , (((safe_sub_func_int16_t_s_s((safe_sub_func_int8_t_s_s(0xDDL, (0UL ^ (safe_lshift_func_uint16_t_u_u(((l_1292 <= (safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u((g_777 & (-1L)), g_2431)), l_1219)), 7)), g_694))) , l_1281), 1))))), 0UL)) & g_694) || l_1052))), l_940[0])), g_694));
                        l_1301 = 0x9FC577ABL;
                    }
                    for (l_790 = 0; (l_790 >= 7); l_790 = safe_add_func_uint8_t_u_u(l_790, 3))
                    {
                        return g_694;
                    }
                    if ((g_694 , (((safe_add_func_int8_t_s_s((safe_lshift_func_int8_t_s_u(g_694, 3)), ((l_1277[4] , (safe_rshift_func_uint8_t_u_u(g_694, (safe_lshift_func_int8_t_s_s((l_1052 > (safe_add_func_uint16_t_u_u(l_1052, (((~(safe_add_func_uint8_t_u_u((((g_694 >= (safe_mod_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(g_97[0], (g_849[0] , l_1321))) || l_1052), l_1281))) && l_1229) ^ g_694), l_1081))) && l_1226[0][1][2]) , l_1052)))), 5))))) >= l_1052))) >= 65527UL) == l_1277[4])))
                    {
                        uint32_t l_1322 = 1UL;
                        int32_t l_1328[3];
                        uint16_t l_1330[7][2] = {{1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}};
                        int i, j;
                        for (i = 0; i < 3; i++)
                            l_1328[i] = 5L;
                        --l_1322;
                        l_1330[3][0]++;
                        if (l_1326)
                            continue;
                    }
                    else
                    {
                        int32_t l_1333[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_1333[i] = 8L;
                        l_1333[2] = l_1052;
                        g_120[3] = (safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(0x461CL, 7)), (l_1051[0] < (g_777 < (safe_add_func_uint16_t_u_u(((0x1114L | g_100) != (safe_mod_func_uint32_t_u_u((safe_mod_func_int16_t_s_s(g_1217, (safe_add_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u(((((-1L) ^ (safe_add_func_int8_t_s_s(((0x17D87BE6L != (safe_rshift_func_int8_t_s_s(((safe_unary_minus_func_uint32_t_u((!l_1281))) ^ 0x50L), g_694))) ^ g_694), g_694))) < 8UL) , g_2431), 14)) , l_1329), l_922)))), 0x45D6E44FL))), l_980))))));
                    }
                    if ((l_790 >= ((l_1051[0] != (((g_694 == (g_849[0] ^ (l_1265 > l_1052))) < g_694) == g_849[0])) <= (safe_lshift_func_uint8_t_u_s(((safe_lshift_func_int8_t_s_u(l_1052, l_880)) , 0xF4L), 2)))))
                    {
                        l_1277[4] = g_694;
                    }
                    else
                    {
                        int32_t l_1358 = 0x27225A3DL;
                        --l_1361;
                        if (l_980)
                            break;
                    }
                }
            }
            for (l_1281 = (-1); (l_1281 == 31); ++l_1281)
            {
                l_1081 ^= ((safe_add_func_int8_t_s_s(l_1359, 1L)) < (l_1052 != (((((-2L) > g_18) , (((l_880 != 0xAEL) & ((((g_1368[1] > (g_777 <= g_694)) & l_1359) == g_97[5]) > l_1369)) == 4294967286UL)) , (-1L)) ^ 255UL)));
            }
        }
        g_120[1] = (safe_sub_func_uint16_t_u_u(((0x68DCACFFL | (safe_sub_func_int8_t_s_s((((((safe_mod_func_uint32_t_u_u(((((((g_97[2] , (safe_lshift_func_int16_t_s_u((g_1368[2] && 0L), 0))) | ((l_1361 && (safe_mod_func_int8_t_s_s((g_694 && (safe_rshift_func_int16_t_s_s((((((((~(((safe_add_func_uint16_t_u_u(((((safe_lshift_func_uint8_t_u_u((((safe_add_func_uint8_t_u_u(l_1369, l_1052)) && ((((1L != 0x1161L) != l_1052) ^ l_980) ^ g_2431)) < l_1361), g_120[1])) >= g_849[0]) , (-1L)) | 0x3F27L), g_1368[0])) , 0x8D90L) ^ g_777)) ^ l_725[2]) | 0xC3L) && g_1368[1]) <= l_1052) , l_1226[0][1][2]) , l_1226[0][0][2]), 2))), l_1052))) <= l_1273)) >= 0x27L) >= g_97[6]) != 2L) != 0x1C966BF2L), g_777)) | (-3L)) < l_1281) > g_694) == l_1052), l_1191[1]))) <= l_790), 8L));
    }
    for (g_100 = 4; (g_100 >= 0); g_100 -= 1)
    {
        int16_t l_1414 = 0x1AE5L;
        int32_t l_1416 = (-7L);
        for (g_2431 = 0; (g_2431 <= 0); g_2431 += 1)
        {
            int32_t l_1415 = (-1L);
            int i;
            l_1416 &= (g_120[g_100] ^ (((((((-1L) == ((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((g_120[g_100] >= ((((((safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(((safe_mod_func_int16_t_s_s((((0xC0L >= ((g_849[g_2431] > ((((safe_add_func_int16_t_s_s(g_694, (safe_rshift_func_int16_t_s_s(((safe_add_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u(g_694, l_790)) == (safe_unary_minus_func_uint32_t_u((((safe_sub_func_int16_t_s_s(0x780FL, 0xB48CL)) <= g_120[1]) ^ g_694)))), l_1281)) , g_694), g_694)))) , g_120[g_100]) && l_980) ^ l_1414)) > 0xFD94L)) | g_18) == g_1217), g_120[4])) >= 0x6DB3L), 13)), 255UL)) , g_694) ^ g_694) || g_694) ^ g_694) != g_120[1])), 4)), g_694)), 0x0CL)), 0x61L)) , l_1415)) <= 0x17E2L) >= l_922) | g_100) && l_1191[1]) || g_18));
            return g_120[g_100];
        }
        l_1329 = g_694;
        l_1416 = (safe_add_func_int8_t_s_s(8L, ((safe_add_func_uint8_t_u_u(((safe_add_func_uint32_t_u_u(l_1423, g_1217)) & ((0xA6F0F4F8L != (l_1414 == l_1052)) & (+(safe_add_func_uint16_t_u_u(l_1416, g_18))))), (l_980 , l_790))) > g_1368[0])));
        for (l_1416 = 0; (l_1416 >= 0); l_1416 -= 1)
        {
            int8_t l_1432 = (-1L);
            int32_t l_1440 = 0x9D9C4759L;
            l_1440 &= (((g_694 < (safe_add_func_uint8_t_u_u(l_1052, (((safe_unary_minus_func_int32_t_s(3L)) , 250UL) , (safe_sub_func_uint8_t_u_u((((g_694 == l_1432) , ((l_1433 > ((safe_lshift_func_int8_t_s_u(((safe_mod_func_uint32_t_u_u(((~((l_1423 ^ g_849[0]) >= g_1217)) || l_980), (-6L))) ^ g_849[0]), l_1052)) >= l_1416)) | 0xA9A8L)) & (-8L)), l_1439[5])))))) , 6UL) && g_120[1]);
        }
    }
    return g_97[6];
}

                    if (g_540)
                continue;

if (l_1329) printf("index = [%d][%d]\n", l_922, l_793);

                    for (g_101 = 0; (g_101 == (-12)); g_101 = safe_sub_func_int8_t_s_s(g_101, 2))
            {


for (l_1281 = 0; (l_1281 <= 7); l_1281 += 1)
            {
                int i, j;
                g_120[3] = l_801[l_1281][l_1281];
                l_821[6][1] = (safe_rshift_func_uint8_t_u_s((safe_lshift_func_uint8_t_u_u((g_97[2] , (safe_lshift_func_int16_t_s_u((((safe_rshift_func_int16_t_s_u((safe_add_func_uint8_t_u_u((4294967286UL != 0x9CDCB11EL), ((l_801[l_1281][l_1281] ^ (g_89 == (safe_mod_func_int16_t_s_s(((((2UL | (safe_mod_func_int8_t_s_s((l_843 || ((safe_add_func_int16_t_s_s((g_97[2] , (0x978C1B61L > 4294967291UL)), l_1327)) < 0xB988L)), l_843))) || l_880) >= g_2254) == 0x1F887AC6L), l_843)))) > 6UL))), 6)) != g_935) <= l_801[7][5]), g_2254))), 3)), l_801[7][5]));
            };


                    if (l_1423)
                    break;

                    return g_849[0];
            }
        }
        l_793 = ((p_34 || (l_801[6][3] & g_849[0])) > (safe_lshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u(p_35, (safe_mod_func_int8_t_s_s(((((safe_lshift_func_int16_t_s_u((safe_rshift_func_uint8_t_u_s(p_35, (+((safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((((+((safe_mod_func_int16_t_s_s(((((safe_add_func_int8_t_s_s((g_18 ^ (safe_add_func_int8_t_s_s((((safe_rshift_func_uint8_t_u_s((((((safe_rshift_func_uint8_t_u_s(((l_821[6][1] ^ ((((((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u((0x5FBED003L || ((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_s((-5L), 0)), 5)) != l_790)), p_34)), l_1046)) < 0x3EL) , 0xE788D646L) == l_801[3][2]) , l_725[2]) || l_801[5][3])) || 0x23L), l_801[7][5])) , 0x32L) & 255UL) || p_34) && p_34), l_877[2][0])) , l_1046) , g_89), 0x67L))), 0UL)) >= 0x78D41AC2L) , p_35) ^ 255UL), l_725[2])) , 0x1712L)) , l_919) , p_35), p_34)), l_1046)) && g_143)))), p_34)) ^ g_777) , p_35) , g_849[0]), l_793)))), p_35)));
    }
    else
    {
        int32_t l_1051[4] = {0x0A2DD9A0L, 0L, 0x0A2DD9A0L, 0L};
        int32_t l_1081 = 1L;
        int32_t l_1226[1][2][5] = {{{0L, (-1L), 0L, (-1L), 0L}, {0L, (-1L), 0L, (-1L), 0L}}};
        int32_t l_1273 = 0x20573342L;
        int32_t l_1359 = 0x441BD344L;
        uint8_t l_1361 = 0x58L;
        int32_t l_1369 = (-7L);
        int i, j, k;
                                            if ((g_101 > l_778) )
{


g_2003[0] |= (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u(g_1482[0][1][0], ((~((((-6L) < l_1433) >= g_120[1]) | (l_1433 , l_1433))) != (((safe_lshift_func_uint16_t_u_s(((g_1548[4][6][2] || ((((safe_rshift_func_int8_t_s_s(1L, 4)) <= 0xC812E52FL) || g_1368[1]) <= 0UL)) , l_725[1]), 3)) != i) < 65535UL)))) | g_1482[2][1][1]) <= 4294967292UL) && l_1329) > g_89), g_849[0])), g_1171));

                    g_2414 ^= g_2100;

}
                    l_1051[0] = (safe_lshift_func_uint16_t_u_s((safe_lshift_func_int8_t_s_s(g_935, 1)), 14));
                                            while ((!g_18) )
{

for (g_101 = 16; (g_101 != (-28)); g_101 = safe_sub_func_int16_t_s_s(g_101, 5))
                {
                    int32_t l_1095 = (-6L);
                    for (l_1281 = 0; (l_1281 <= 0); l_1281 += 1)
                    {
                        int i, j;
                        return l_877[l_1281][l_1281];
                    }
                    l_1095 = ((((g_120[1] || (-5L)) && ((((safe_lshift_func_int16_t_s_u((((safe_rshift_func_int16_t_s_u((g_935 || (((0xBBL ^ (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(g_120[1], (((((-1L) > (g_2467 , 1L)) , ((safe_add_func_int16_t_s_s(p_34, p_34)) & 4294967289UL)) <= p_34) != g_59))), g_120[1]))) | g_935) == g_935)), p_34)) >= 0x20L) , 0x45CAL), g_935)) > (-2L)) <= 0x8BB0L) < g_540)) , g_59) ^ g_540);

for (l_1052 = 0; (l_1052 != 38); ++l_1052)
                    {
                        k = ((l_1007 < (safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((g_777 < 0L), (g_777 >= 0L))), (-1L)))) >= ((safe_lshift_func_uint8_t_u_u(((k || 252UL) , ((((safe_lshift_func_int8_t_s_s(l_1359, 7)) != 0L) == g_694) , g_849[0])), g_22)) >= l_922));
                    };


                    for (g_2100 = 0; (g_2100 <= 0); g_2100 += 1)
                    {
                        int i, j;
                        g_120[2] = l_877[g_2100][g_2100];
                    }
                };


}
                    l_1052 |= l_940[3];
                                       int16_t BHoHogg_101 = (~((((l_778 ^ l_919) & ((~((~(g_101)))) - (((~(g_143)) / l_1052) >> (l_1329 || (g_1171 ^ l_1423))))) & (~((~(((~(g_777)) - l_1361))))))));
uint8_t BHoHohl_1361 = (~(((~((~((BHoHogg_101 && (~(((~(l_1052)) & g_1171)))))))) ^ (~(((~(g_143)) ^ (((~((~((~((~(l_1423)))))))) && ((l_778 | (~(g_101))) << (l_1329 && l_1361))) && (l_919 / g_777))))))));
uint32_t BHoHoil_1423 = (~(((~((~(((~((l_1052 & l_919))) - (((~((~(l_1329)))) || (~((~((g_777 ^ (~(((~(g_143)) && (BHoHogg_101 & l_1423)))))))))) || (~((~(((~(BHoHohl_1361)) || (g_101 | (l_1361 || g_1171))))))))))))) | l_778)));
int32_t BHoHojl_919 = (~((((BHoHohl_1361 | l_1329) & (~((((~((~(l_1423)))) | (~(((BHoHogg_101 || (~(g_143))) | ((~(l_1052)) ^ g_1171))))) || (~((~(((~(g_101)) ^ (~(BHoHoil_1423))))))))))) & (~((~((l_778 | (~(((~((l_1361 - g_777))) & l_919)))))))))));
uint8_t BHoHokg_1171 = (~((((~((~((~(BHoHohl_1361)))))) - (~((~((~((~((~((l_1423 / (l_1052 - BHoHoil_1423))))))))))))) | (~(((((~((~(BHoHojl_919)))) | (~(g_101))) | l_1329) && ((l_919 - (~(l_1361))) >> ((g_1171 && g_777) / ((BHoHogg_101 || g_143) || (~(l_778)))))))))));
uint32_t BHoHoll_1052 = (~(((~((((((~(l_1361)) || (l_778 ^ l_1423)) - l_1329) - (~((~((~((~(g_101))))))))) ^ g_143))) | (((~((~(g_777)))) & (~(((BHoHokg_1171 >> g_1171) & ((l_919 ^ l_1052) - BHoHogg_101))))) ^ ((~(BHoHoil_1423)) - (BHoHohl_1361 && BHoHojl_919))))));
if((!((g_777<=3723980291U)) || !((!l_1361)))){
BHoHogg_101 = g_101;
BHoHohl_1361 = l_1361;
                               uint32_t B4o4ol_1052 = (~(((~((g_100 & l_1081))) * (((((~(l_1369)) | (l_1007 << g_694)) && ((l_919 ^ l_1327) * l_1433)) * l_790) & (-(l_1052))))));
int32_t B4o4obl_919 = (-((((~((~(l_919)))) && l_1007) * (~(((~(((~((l_1081 - l_1327))) - (~(l_790))))) ^ (((-((l_1369 ^ l_1433))) >> (~(((~(g_694)) | g_100)))) && (~((l_1052 & (~(B4o4ol_1052))))))))))));
int8_t B4o4ocg_100 = (~(((((~(l_1081)) | (g_100 && (l_1007 && l_1052))) & (((~(l_919)) * g_694) | l_1433)) - ((~((-(((~((-((B4o4ol_1052 ^ B4o4obl_919))))) ^ (~(l_790))))))) - ((~(l_1369)) ^ l_1327)))));
int32_t B4o4odl_1369 = (~(((-(((~((~(l_919)))) & l_790))) ^ ((~((-((B4o4ocg_100 * l_1369))))) ^ ((((-((l_1433 >> g_694))) * ((-(l_1327)) | l_1007)) - B4o4ol_1052) & ((g_100 && (l_1052 & B4o4obl_919)) ^ l_1081))))));
int8_t B4o4oel_790 = (-(((~((-(((-((~(l_919)))) & (-((-(l_1327))))))))) & (~(((~((((~(((~(l_790)) & g_694))) && l_1433) | ((l_1081 & B4o4obl_919) && g_100)))) | ((B4o4odl_1369 ^ l_1369) && ((-(((B4o4ocg_100 && l_1052) * l_1007))) && B4o4ol_1052))))))));
uint32_t B4o4ofl_1433 = (~(((~((-((l_1052 >> ((-(g_694)) && l_1327)))))) ^ (-(((~(((~((((~(l_1007)) * B4o4oel_790) - (B4o4odl_1369 && B4o4ocg_100)))) && ((l_1369 | (~(l_919))) - (-(l_1081)))))) * ((l_790 ^ ((-((~(B4o4obl_919)))) & (~(((~(l_1433)) && (~(B4o4ol_1052))))))) & (~((~(g_100)))))))))));
if((B4o4ocg_100 < g_100)){
B4o4ol_1052 = l_1052;
B4o4obl_919 = l_919;
B4o4ocg_100 = g_100;
B4o4odl_1369 = l_1369;
LABEL_4o4og: B4o4oel_790 = l_790;
B4o4ofl_1433 = l_1433;
l_1052 = (~((((-(((l_1052 >> l_1081) | (~((~(B4o4ocg_100))))))) ^ (((g_100 * (B4o4oel_790 & (-((~(l_1007)))))) - (((g_694 - B4o4obl_919) ^ l_919) | (~(l_790)))) && (B4o4odl_1369 && (~((l_1433 ^ l_1327)))))) & (~((B4o4ofl_1433 * (B4o4ol_1052 - l_1369)))))));
l_919 = (~((((l_1433 && (~(l_1081))) * l_790) * ((~(((-((-(B4o4odl_1369)))) & ((~(((-(B4o4oel_790)) ^ (~(l_1369))))) && ((l_1007 && (B4o4obl_919 && l_1327)) | (~((-(g_100))))))))) * (~(((~((~(((l_1052 ^ g_694) - B4o4ofl_1433))))) | (~(((B4o4ocg_100 & B4o4ol_1052) | l_919))))))))));
g_100 = (~(((~((~((((~(l_1369)) ^ (-(l_1081))) * (~(((~(B4o4odl_1369)) - B4o4ol_1052)))))))) | ((-((~((l_1007 - B4o4oel_790))))) | ((~((~((~(l_1327)))))) ^ (l_1433 | (-((((-((-(B4o4ofl_1433)))) << (((-(l_1052)) | l_919) * g_694)) * (B4o4obl_919 & (~(((~(B4o4ocg_100)) - (l_790 ^ (~(g_100))))))))))))))));
l_1369 = (~((((-((~((l_1433 - B4o4obl_919))))) & ((-(((l_1052 >> g_100) && (-(B4o4oel_790))))) - ((-((l_1007 && (g_694 | B4o4ofl_1433)))) | (~((-(B4o4odl_1369))))))) && (~((~(((((~(l_1327)) && (l_1369 - (-(B4o4ol_1052)))) && (~((~(l_790))))) * (-(((~(l_1081)) | (B4o4ocg_100 & l_919))))))))))));
l_790 = (~(((~((~((-((-((B4o4ofl_1433 | ((-(l_1327)) - l_1369)))))))))) * (((-((-(((g_100 * B4o4odl_1369) & (-((B4o4oel_790 & B4o4ol_1052)))))))) * ((g_694 * ((l_1007 ^ (-(B4o4ocg_100))) * (~((-(l_1052)))))) * (-((~(l_1433)))))) && (-((~(((~(l_790)) - ((B4o4obl_919 | (~(l_1081))) - (~(l_919))))))))))));
l_1433 = (-((((((l_1081 - l_790) | l_1327) | (B4o4ofl_1433 && g_694)) - (((~(((-(B4o4odl_1369)) * (B4o4oel_790 * g_100)))) ^ ((-(B4o4obl_919)) && B4o4ocg_100)) ^ (l_1052 & ((~(B4o4ol_1052)) ^ l_919)))) | (-((((-(l_1369)) && l_1433) & l_1007))))));
if((l_790 < B4o4oel_790)){
printf("l_1052=%llu\n", (unsigned long long)l_1052);
l_1052 = (~(((~((((-(l_1007)) - (~((l_1327 << l_919)))) && (-(((((B4o4oel_790 << ((~(l_1369)) << (~((B4o4odl_1369 | g_100))))) & (-((l_1052 & B4o4ofl_1433)))) | B4o4ocg_100) << (-((~((((g_694 << l_1433) * l_790) | B4o4ol_1052))))))))))) << ((~(B4o4obl_919)) | (~(l_1081))))));
goto LABEL_4o4og;
}
if(((!l_1327) && (l_919>2012425961))){
printf("l_919=%lld\n", (long long)l_919);
goto LABEL_4o4og;
}
if((!l_1081)){
printf("g_100=%lld\n", (long long)g_100);
l_790 = (-((((~((-((g_100 >> l_790))))) - ((l_1052 * l_1327) && (-((~(((~(l_1369)) && ((~(B4o4ocg_100)) | B4o4odl_1369)))))))) * (~((~(((-((l_1007 | B4o4oel_790))) & (l_1433 - (((~(l_919)) | l_1081) << (((~(B4o4obl_919)) >> B4o4ol_1052) >> ((~(g_694)) & (-(B4o4ofl_1433))))))))))))));
goto LABEL_4o4og;
}
if(!((B4o4oel_790 < B4o4ocg_100))){
printf("l_1369=%lld\n", (long long)l_1369);
l_1052 = (~(((-(l_1052)) * (-(((((((g_694 << B4o4ocg_100) | ((~(g_100)) >> l_1007)) * ((~(l_1433)) << (~(((B4o4oel_790 >> B4o4ol_1052) ^ l_1369))))) * (~((-(((l_1081 >> B4o4ofl_1433) & l_919)))))) * (-(((~(B4o4odl_1369)) && B4o4obl_919)))) | (~((~(((~(l_790)) << l_1327)))))))))));
goto LABEL_4o4og;
}
if((l_1052<1811930623U)){
printf("l_790=%lld\n", (long long)l_790);
l_790 = (-(((~((-((~((((~(l_1433)) && l_790) - (((B4o4ocg_100 << l_1007) ^ (~(B4o4obl_919))) - (~(g_694)))))))))) | (B4o4odl_1369 & (-(((((l_1327 - l_1369) ^ (-((B4o4ol_1052 - l_1052)))) & (-(((l_919 - l_1081) ^ (~(B4o4oel_790)))))) * (-((~((B4o4ofl_1433 && g_100))))))))))));
}
if(!((g_694 < B4o4ol_1052))){
printf("l_1433=%llu\n", (unsigned long long)l_1433);
l_790 = (-(((~((~((~((((-(l_1327)) & l_1007) | ((l_919 << ((B4o4odl_1369 >> l_1081) * l_1433)) >> (B4o4ol_1052 * B4o4ocg_100))))))))) | (-((((~((l_1369 && (~(((~(B4o4obl_919)) >> l_1052)))))) && (g_694 & (~(B4o4ofl_1433)))) << (~(((~((-((~(l_790)))))) >> (~((B4o4oel_790 << g_100))))))))))));
l_919 = (-((((~((((l_1369 << g_100) & ((-((l_1327 * B4o4ofl_1433))) << (l_1007 >> B4o4obl_919))) >> ((B4o4ocg_100 ^ (~(B4o4odl_1369))) >> (~(l_790)))))) << (~((l_1052 - ((l_919 << B4o4ol_1052) >> (~(B4o4oel_790))))))) ^ ((-((~((~(l_1433)))))) * (l_1081 << g_694)))));
goto LABEL_4o4og;
}
}
l_1052 = B4o4ol_1052;
l_919 = B4o4obl_919;
g_100 = B4o4ocg_100;
l_1369 = B4o4odl_1369;
l_790 = B4o4oel_790;
l_1433 = B4o4ofl_1433;

                    BHoHoil_1423 = l_1423;
                                   if ((g_18>=150))
                    BHoHojl_919 = l_919;
BHoHokg_1171 = g_1171;
BHoHoll_1052 = l_1052;
                                    while ((l_980 < l_1281) )
{

for (l_1007 = (-26); (l_1007 <= 16); l_1007++)
                    {
                        int8_t l_524 = (-8L);
                        l_524 = l_880;
                        l_1081 &= l_524;
                    };


}
                    g_101 = (~((((~(((~((~(BHoHojl_919)))) & (((~(((~(g_1171)) | BHoHogg_101))) - (g_143 - BHoHokg_1171)) ^ BHoHoll_1052)))) & (~((((~(l_1361)) & BHoHohl_1361) ^ (~((BHoHoil_1423 - g_101))))))) ^ (~(((~(l_919)) ^ (~((l_1423 || (~(((g_777 & l_1052) | ((~(l_778)) && l_1329)))))))))))));
l_1361 = (~(((~((~(g_1171)))) | (((l_919 | ((((~(BHoHogg_101)) && (g_777 | BHoHohl_1361)) >> (~(g_143))) >> (((g_101 ^ (~(l_778))) || ((~(l_1423)) || BHoHoll_1052)) && l_1052))) ^ ((~(((~(BHoHojl_919)) || (l_1329 / l_1361)))) ^ BHoHoil_1423)) | BHoHokg_1171))));
l_1423 = (~((((~((~((~((BHoHogg_101 / (~(g_101))))))))) & (~(((~((~(BHoHokg_1171)))) / ((~((BHoHoll_1052 && l_919))) ^ (((g_777 - ((~(BHoHohl_1361)) && (l_1423 && ((g_143 & g_1171) / l_1329)))) || (~(BHoHoil_1423))) ^ l_1361)))))) ^ ((~((l_778 && BHoHojl_919))) - l_1052))));
l_919 = (~(((~(((~(l_1423)) || (~(((~((BHoHohl_1361 & (~(l_1329))))) || ((BHoHogg_101 & (BHoHoll_1052 ^ (~(l_919)))) || (~((g_1171 / (~(BHoHojl_919)))))))))))) / ((~((~((~(((~(BHoHokg_1171)) - g_777))))))) & (l_1052 ^ ((~((l_1361 << ((g_101 ^ l_778) && BHoHoil_1423)))) & g_143))))));
g_1171 = (~(((~((~((~(((~((~(BHoHoil_1423)))) && BHoHoll_1052))))))) || ((~(((((~((~(((~(g_1171)) ^ l_1423))))) / (~((~(((~(g_101)) && (~((BHoHokg_1171 || BHoHogg_101))))))))) & (~((g_143 >> (((~(l_1361)) ^ l_919) && (l_778 ^ g_777)))))) || (l_1329 | BHoHojl_919)))) & (~((l_1052 - BHoHohl_1361)))))));
l_1052 = (~(((l_1361 ^ ((~((~(l_778)))) << (((~(((~(BHoHogg_101)) || (~(((~(l_1423)) | ((~(((BHoHokg_1171 || (g_101 || g_777)) || BHoHojl_919))) - (~(g_1171))))))))) | (~((~((l_919 & g_143)))))) || (~(((l_1329 || l_1052) || (BHoHoil_1423 && (~(BHoHoll_1052))))))))) || (~((~((~(BHoHohl_1361)))))))));
if((BHoHokg_1171 > l_1423)){
printf("g_101=%lld\n", (long long)g_101);
BHoHoil_1423 = (~(((~((~((~(((((l_1329 >> g_143) & BHoHogg_101) >> g_777) / ((~(g_101)) - l_1052)))))))) && ((~(((l_1361 >> g_1171) ^ BHoHokg_1171))) || ((((~((~((~(l_1423)))))) && (~((~((l_778 && BHoHoll_1052)))))) / (~((~(BHoHohl_1361))))) << (~(((~((BHoHojl_919 >> (~(BHoHoil_1423))))) && l_919))))))));


for (j = 0; j < 3; j++)
                            g_1368[j] = 5L;

                    for (g_89 = 4; (g_89 >= 0); g_89 -= 1)
    {
        int16_t l_1414 = 0x1AE5L;
        int32_t l_1416 = (-7L);
        for (BHoHohl_1361 = 0; (BHoHohl_1361 <= 0); BHoHohl_1361 += 1)
        {
            int32_t l_1415 = (-1L);
            int i;
            l_1416 &= (g_120[g_89] ^ (((((((-1L) == ((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((g_120[g_89] >= ((((((safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(((safe_mod_func_int16_t_s_s((((0xC0L >= ((g_849[BHoHohl_1361] > ((((safe_add_func_int16_t_s_s(g_101, (safe_rshift_func_int16_t_s_s(((safe_add_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u(g_694, g_100)) == (safe_unary_minus_func_uint32_t_u((((safe_sub_func_int16_t_s_s(0x780FL, 0xB48CL)) <= g_120[1]) ^ g_694)))), BHoHoll_1052)) , g_101), g_101)))) , g_120[g_89]) && l_980) ^ l_1414)) > 0xFD94L)) | g_18) == g_1217), g_120[4])) >= 0x6DB3L), 13)), 255UL)) , g_101) ^ g_101) || g_101) ^ g_101) != g_120[1])), 4)), g_101)), 0x0CL)), 0x61L)) , l_1415)) <= 0x17E2L) >= BHoHojl_919) | g_89) && l_1191[1]) || g_18));

{
                        return BHoHokg_1171;
                    }

                    return g_120[g_89];
        }
        l_1359 = g_101;
        l_1416 = (safe_add_func_int8_t_s_s(8L, ((safe_add_func_uint8_t_u_u(((safe_add_func_uint32_t_u_u(g_777, g_1217)) & ((0xA6F0F4F8L != (l_1414 == l_980)) & (+(safe_add_func_uint16_t_u_u(l_1416, g_18))))), (l_980 , g_100))) > g_1368[0])));
        for (l_1416 = 0; (l_1416 >= 0); l_1416 -= 1)
        {
            int8_t l_1432 = (-1L);
            int32_t l_1440 = 0x9D9C4759L;

if ((safe_lshift_func_uint16_t_u_s((+(safe_sub_func_uint8_t_u_u(g_849[l_1369], g_101))), 8)))
                    {
                        g_120[1] = 0xB8ED6298L;
                        if (g_101)
                            continue;
                        BHoHojl_919 &= (safe_mod_func_uint32_t_u_u(g_101, 0xE4729DD1L));
                    }
                    else
                    {
                        uint16_t l_861 = 0x987DL;
                        g_120[1] = ((safe_add_func_int16_t_s_s(0x6D2DL, l_861)) > 9L);
                        return g_849[l_1369];
                    };


                    l_1440 &= (((g_540 < (safe_add_func_uint8_t_u_u(l_980, (((safe_unary_minus_func_int32_t_s(3L)) , 250UL) , (safe_sub_func_uint8_t_u_u((((g_101 == l_1432) , ((l_1433 > ((safe_lshift_func_int8_t_s_u(((safe_mod_func_uint32_t_u_u(((~((g_777 ^ g_849[0]) >= g_1217)) || l_980), (-6L))) ^ g_849[0]), l_980)) >= l_1416)) | 0xA9A8L)) & (-8L)), l_1439[5])))))) , 6UL) && g_120[1]);
        }
    }
{
        for (g_2469 = 0; g_2469 < 3; g_2469++)
        {
            transparent_crc(g_2184[k][g_2469], "g_2184[k][g_2469]", BHoHojl_919);
            if (BHoHojl_919) printf("index = [%d][%d]\n", k, g_2469);

        }
    }

                    ;


                    l_1052 = (~((((((~(l_778)) | (BHoHojl_919 << BHoHokg_1171)) / l_1361) & (((~(l_1329)) - (BHoHoil_1423 & l_1423)) ^ BHoHoll_1052)) - (((~(BHoHohl_1361)) && ((g_1171 & g_101) ^ (g_777 ^ l_919))) && (((~(BHoHogg_101)) | l_1052) >> (~(g_143)))))));
}
                                   if (((g_143<=4294967295U) && (g_143 > l_1007)))
                    if(!((g_101 > BHoHoil_1423))){
printf("l_1361=%llu\n", (unsigned long long)l_1361);
BHoHohl_1361 = (~((((g_777 & l_919) - (BHoHohl_1361 << (~((l_778 || BHoHojl_919))))) ^ ((l_1329 / (~((BHoHoil_1423 & (~((~(l_1423)))))))) - ((~((~((~((l_1361 && l_1052))))))) ^ (((BHoHogg_101 - g_1171) && (g_143 - (~(BHoHoll_1052)))) || (~((~((g_101 << BHoHokg_1171)))))))))));
BHoHojl_919 = (~(((~((~(((~((~((l_1423 >> l_1329))))) - ((l_778 - (BHoHoll_1052 - l_919)) << (~((BHoHohl_1361 / g_1171))))))))) - (((BHoHojl_919 << l_1052) / (~(l_1361))) << ((~((~(((g_101 - (~(BHoHoil_1423))) << (~((BHoHogg_101 >> BHoHokg_1171)))))))) & (g_777 | g_143))))));
l_1361 = (~(((~((((~((g_777 & (~((l_1329 << BHoHogg_101)))))) << ((((~((~(l_919)))) - g_143) & g_101) || (~(((g_1171 & (~(BHoHokg_1171))) || l_1423))))) && (~((l_1052 && ((~((~((BHoHojl_919 ^ l_1361))))) - (BHoHohl_1361 | BHoHoil_1423)))))))) - (~((~((~((BHoHoll_1052 << (~(l_778))))))))))));
}
if((g_777<3723980291U)){
printf("l_1423=%llu\n", (unsigned long long)l_1423);
BHoHoll_1052 = (~(((~((((~((((BHoHoil_1423 || l_1361) || (~(g_1171))) << (~(l_1052))))) - (~((((BHoHojl_919 ^ BHoHoll_1052) & (~(((g_101 ^ l_1423) & (~(((~(l_1329)) >> g_777))))))) - (l_778 || BHoHohl_1361))))) & (BHoHogg_101 / BHoHokg_1171)))) && (l_919 ^ g_143))));
BHoHoil_1423 = (~((((~(((~((l_1361 | (~(((~(((~(BHoHohl_1361)) | g_777))) & (~(BHoHokg_1171)))))))) && g_143))) && (~(((~(((~((BHoHojl_919 || l_919))) && g_1171))) ^ (~((~(((BHoHogg_101 >> (BHoHoll_1052 / (l_1423 >> g_101))) ^ (~(((~(l_1329)) ^ l_1052)))))))))))) / (~((~((l_778 && (~((~(BHoHoil_1423))))))))))));
l_1361 = (~((((~((~((~(((~((~(g_777)))) / (BHoHoll_1052 >> (~((l_919 && BHoHogg_101))))))))))) - ((BHoHojl_919 ^ g_1171) << g_143)) / ((l_1361 & ((l_778 - (l_1423 / g_101)) && (l_1052 || BHoHokg_1171))) >> ((~(BHoHoil_1423)) && (l_1329 || BHoHohl_1361))))));
}
if((BHoHokg_1171 > BHoHojl_919)){

{
                        uint32_t l_384 = 0UL;
                        l_922 = (safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((g_935 , (safe_mod_func_int32_t_s_s((((((((((((l_790 , ((safe_mod_func_uint8_t_u_u((g_97[2] ^ (~(+g_717))), ((((g_97[3] & ((safe_sub_func_uint16_t_u_u((l_384 >= g_694), (((((((safe_lshift_func_int16_t_s_u((g_2414 || (((((safe_rshift_func_int16_t_s_u((1UL != g_1217), 4)) , 0x8DL) >= g_100) , g_1217) , 0x343F8062L)), g_1217)) > 4L) > g_2414) , g_120[1]) != l_790) , g_2100) == 0xCB3F649DL))) | g_2414)) || g_100) | g_120[3]) && 0xE5L))) < 0UL)) >= g_97[1]) || 0x3F5AL) ^ BHoHogg_101) || g_1217) | l_1327) , 0L) || (-1L)) ^ 0x8506B361L) >= g_935) ^ (-6L)), 0x3F0D7356L))), g_100)), g_22));
                        l_1423--;
                    }

                    printf("l_919=%lld\n", (long long)l_919);
l_1423 = (~((((~((~(l_1329)))) ^ ((~((BHoHohl_1361 >> BHoHoil_1423))) << l_1052)) & (~((~(((~((((~((~(g_777)))) / ((~(g_1171)) | (~((~(l_778)))))) | ((l_919 / BHoHogg_101) >> (~(l_1361)))))) - ((BHoHokg_1171 ^ BHoHojl_919) - ((~(g_101)) & (g_143 & (~((l_1423 ^ BHoHoll_1052))))))))))))));
BHoHokg_1171 = (~(((((((~(((~(l_778)) >> l_1052))) << (~(g_777))) || BHoHojl_919) & ((l_1329 ^ (~(BHoHohl_1361))) << (~((~((l_919 | (~(g_1171))))))))) / (~(((~((g_143 / l_1423))) | g_101)))) / (((~(BHoHogg_101)) >> ((~((BHoHokg_1171 | BHoHoil_1423))) & BHoHoll_1052)) | l_1361))));
}
if(((!BHoHokg_1171) && (l_919 > l_1329))){
printf("g_1171=%llu\n", (unsigned long long)g_1171);
l_1423 = (~((((~(((l_1361 / (~((~(BHoHoil_1423))))) ^ ((~((BHoHogg_101 || (g_101 ^ l_1423)))) ^ (~(BHoHojl_919)))))) | (~(((~(l_1329)) ^ BHoHoll_1052)))) && (~((((~((~(g_777)))) << (g_1171 & (~(((l_1052 ^ l_778) << (~((~(g_143))))))))) - (~((~((~((~((l_919 || (BHoHohl_1361 || BHoHokg_1171))))))))))))))));
g_1171 = (~(((~((BHoHoll_1052 >> (~((((l_1329 >> (((BHoHokg_1171 | l_1052) && (~(g_777))) / (~((~(l_919)))))) >> ((BHoHogg_101 ^ (~((~((~(l_778))))))) - (~(BHoHoil_1423)))) >> (~((g_1171 ^ ((BHoHojl_919 << (~(l_1361))) && (BHoHohl_1361 - g_143))))))))))) || (g_101 ^ l_1423))));
}
if((!l_1361)){
printf("l_1052=%llu\n", (unsigned long long)l_1052);
BHoHohl_1361 = (~((((~(((g_777 || (~((g_101 & l_919)))) || g_143))) / (l_1329 >> (~((BHoHoil_1423 | (BHoHogg_101 & (~(l_1361)))))))) || (~((~(((((BHoHoll_1052 << (BHoHokg_1171 / l_1423)) - (~(l_778))) || (l_1052 / (BHoHojl_919 || g_1171))) / BHoHohl_1361))))))));
g_1171 = (~(((~(((~((~(l_1423)))) << (l_1052 | (~((~((~(((~(l_1361)) / ((~(BHoHojl_919)) | (~(BHoHoil_1423)))))))))))))) / (~((((~((~(g_1171)))) ^ (((~((~(g_101)))) / ((~(BHoHokg_1171)) & (l_778 - l_1329))) ^ l_919)) << (((g_777 & BHoHogg_101) / g_143) | (BHoHoll_1052 / BHoHohl_1361))))))));
BHoHojl_919 = (~(((~(((~(((~(l_1052)) && (~(g_777))))) && ((g_143 & l_919) && ((~((g_101 >> (l_1329 - g_1171)))) | (~((~((~(BHoHogg_101))))))))))) || (~(((~(((l_778 & BHoHojl_919) ^ (l_1361 / BHoHoll_1052)))) | (~((BHoHoil_1423 & ((~(BHoHokg_1171)) / (BHoHohl_1361 / (~(l_1423)))))))))))));
}
}
g_101 = BHoHogg_101;
l_1361 = BHoHohl_1361;
l_1423 = BHoHoil_1423;
l_919 = BHoHojl_919;
g_1171 = BHoHokg_1171;
l_1052 = BHoHoll_1052;

                    for (g_777 = 0; (g_777 > 1); ++g_777)
        {
            uint8_t l_1069 = 1UL;
            int8_t l_1216 = 0xBDL;
            int32_t l_1219 = 0x1BE859F7L;
            int32_t l_1224 = 7L;
            int32_t l_1227 = (-6L);
            int32_t l_1228 = 0x1EE42556L;
            int32_t l_1229 = 0xD31B29F5L;
            int32_t l_1231[6];
            uint32_t l_1233 = 1UL;
            int i;

l_1219 &= (g_120[g_89] ^ (((((((-1L) == ((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((g_120[g_89] >= ((((((safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(((safe_mod_func_int16_t_s_s((((0xC0L >= ((g_849[g_2431] > ((((safe_add_func_int16_t_s_s(g_935, (safe_rshift_func_int16_t_s_s(((safe_add_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u(g_935, g_89)) == (safe_unary_minus_func_uint32_t_u((((safe_sub_func_int16_t_s_s(0x780FL, 0xB48CL)) <= g_120[1]) ^ g_935)))), g_143)) , g_935), g_935)))) , g_120[g_89]) && g_143) ^ g_935)) > 0xFD94L)) | g_18) == g_1217), g_120[4])) >= 0x6DB3L), 13)), 255UL)) , g_935) ^ g_935) || g_935) ^ g_935) != g_120[1])), 4)), g_935)), 0x0CL)), 0x61L)) , l_919)) <= 0x17E2L) >= g_2100) | g_89) && l_1191[1]) || g_18));

                    for (i = 0; i < 6; i++)
                l_1231[i] = 7L;
            if ((p_34 , (((safe_add_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((safe_sub_func_int32_t_s_s(((-3L) == ((safe_add_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(0x6B9EL, p_34)), ((safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s((((l_1069 , ((((~(l_1051[0] , ((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u((((p_35 >= (~((0x941CB444L | g_849[0]) || g_18))) < p_34) == l_1051[0]), 1UL)) <= p_34), p_35)) > g_935))) == 6L) <= 0L) , g_935)) & 5L) , p_34), 1UL)), 4294967288UL)) >= l_793))) != p_34)), 0xFF1D970AL)), 1L)), p_34)) , g_717) & g_935)))
            {
                uint8_t l_1080 = 1UL;
                l_919 = (safe_sub_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u(1UL, l_1051[3])), ((g_849[0] < l_1069) != (1L > g_89))));
                g_120[1] = ((g_849[0] || 0xD3L) <= l_919);
                if (l_1080)
                    break;
                if (l_1069)
                    break;
            }
            else
            {
                int16_t l_1094 = 0xECC4L;
                int32_t l_1149[2];
                int16_t l_1163[7][10];
                int i, j;
                for (i = 0; i < 2; i++)
                    l_1149[i] = 0xBA560EB5L;
                for (i = 0; i < 7; i++)
                {

if (l_1423)
                    {
for (g_59 = 26; (g_59 == 51); g_59++)
    {
        uint8_t l_1466 = 254UL;
        int32_t l_1481 = 7L;
        g_120[1] = l_1466;
        l_1481 = (((g_97[2] > g_1217) | (safe_add_func_uint8_t_u_u(0x65L, ((!((safe_rshift_func_int8_t_s_s(((0x0584L < (l_1466 && (safe_lshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s((((!(g_1217 , ((safe_mod_func_uint8_t_u_u(l_1466, g_143)) , (safe_sub_func_int8_t_s_s((0xCDL > BHoHogg_101), 0xCFL))))) < 255UL) < 0xB6L), l_1466)), g_1217)))) , 0x19L), l_1466)) > 0xBFD8L)) == 0UL)))) >= g_143);
    };


                    break;}

                    for (j = 0; j < 10; j++)
                        l_1163[i][j] = 6L;
                }
                l_1081 = (p_35 == p_35);
                for (g_935 = 16; (g_935 != (-28)); g_935 = safe_sub_func_int16_t_s_s(g_935, 5))
                {
                    int32_t l_1095 = (-6L);
                    for (g_143 = 0; (g_143 <= 0); g_143 += 1)
                    {
                        int i, j;
                        return l_877[g_143][g_143];
                    }


for (i = 0; (i <= 0); i += 1)
                    {
                        int i, j;
                        g_120[2] = l_877[i][i];
                    }
if (g_143)
                break;

                    ;


                    g_120[1] |= (((g_849[0] <= (safe_add_func_int32_t_s_s(g_777, g_777))) <= ((((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u((k && ((g_777 == g_2100) > ((safe_rshift_func_int16_t_s_u(((((((g_97[2] | l_1007) && ((!((safe_rshift_func_int16_t_s_s(((0L | l_1224) , k), l_1423)) ^ g_2100)) ^ 0L)) == l_1007) , 1L) || 0xE5L) <= l_1069), 15)) || g_2100))), 3)) > g_101) ^ g_777), l_1423)) ^ g_1368[1]) || 1L) != (-5L)) , 4294967290UL) <= g_777)) ^ 0x02D0829CL);

                    l_1095 = ((((g_120[1] || (-5L)) && ((((safe_lshift_func_int16_t_s_u((((safe_rshift_func_int16_t_s_u((p_35 || (((0xBBL ^ (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(g_120[1], (((((-1L) > (g_777 , 1L)) , ((safe_add_func_int16_t_s_s(p_34, p_34)) & 4294967289UL)) <= p_34) != l_1069))), g_120[1]))) | p_35) == p_35)), p_34)) >= 0x20L) , 0x45CAL), p_35)) > (-2L)) <= 0x8BB0L) < l_1094)) , l_1069) ^ g_101);
                    for (l_919 = 0; (l_919 <= 0); l_919 += 1)
                    {
                        int i, j;
                        g_120[2] = l_877[l_919][l_919];
                    }
                }

{
                int16_t l_775 = (-4L);
                int32_t l_776 = (-3L);
                l_1433 = ((((l_1052 ^ (l_725[2] , (0xB43536D7L > 0x43474B68L))) >= (((g_18 < ((safe_add_func_int8_t_s_s(l_1069, 0xFAL)) & (safe_mod_func_int8_t_s_s(((((((l_775 | l_776) || l_1094) || g_717) , g_143) <= 6L) <= 0x62L), 0x36L)))) && l_1052) > 0x8EL)) != g_143) == g_143);
            }

                    if ((p_34 , p_34))
                {
                    uint16_t l_1101[10] = {0xEA04L, 0xEA04L, 0UL, 0xEA04L, 0xEA04L, 0UL, 0xEA04L, 0xEA04L, 0UL, 0xEA04L};
                    int i;

for (l_1081 = 0; l_1081 < 6; l_1081++)
                l_1231[l_1081] = 7L;

                    if (g_717)
                        break;

{
            int16_t l_786 = 8L;
            int32_t l_789 = 2L;
            int32_t l_791 = 0xB2B08DC3L;
            uint32_t l_794 = 0x67A078F5L;

{
        for (l_778 = 0; l_778 < 3; l_778++)
        {
            for (l_919 = 0; l_919 < 4; l_919++)
            {
                transparent_crc(g_1482[l_1359][l_778][l_919], "g_1482[l_1359][l_778][l_919]", l_789);
                if (l_789) printf("index = [%d][%d][%d]\n", l_1359, l_778, l_919);

            }
        }
    }

                    l_922 = (safe_rshift_func_int16_t_s_u(l_1216, 9));
            if (l_1433)
                {
{
        for (l_791 = 0; l_791 < 2; l_791++)
        {
            transparent_crc(g_1540[l_1228][l_791], "g_1540[l_1228][l_791]", j);
            if (j) printf("index = [%d][%d]\n", l_1228, l_791);

        }
    }

                    break;}
            for (l_922 = 0; (l_922 <= (-8)); l_922--)
            {
                return l_786;
            }
            for (g_694 = 2; (g_694 < 14); g_694 = safe_add_func_uint16_t_u_u(g_694, 3))
            {

{
                        uint32_t l_1322 = 1UL;
                        int32_t l_1328[3];
                        uint16_t l_1330[7][2] = {{1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}};
                        int i, j;
                        for (i = 0; i < 3; i++)
                            {
if (p_35)
                            continue;

                    l_1328[i] = 5L;}

{
                        if (l_1069)
                            break;
                    }

                    --l_1322;
                        l_1330[3][0]++;

{
                        g_120[1] = 0xB8ED6298L;
                        if (l_786)
                            continue;
                        BHoHojl_919 &= (safe_mod_func_uint32_t_u_u(l_786, 0xE4729DD1L));
                    }

                    if (l_1273)
                            continue;
                    }

                    l_794--;
            }
        }


g_1482[2][1][1] |= (safe_rshift_func_uint16_t_u_s(g_540, func_25(BHoHoil_1423)));

                    if ((safe_add_func_int8_t_s_s((safe_add_func_int8_t_s_s((((p_35 == ((((((((!((p_34 ^ (l_1069 || ((l_1101[9] & ((-7L) | ((((safe_sub_func_uint8_t_u_u(p_35, (safe_add_func_uint32_t_u_u(g_143, 0x1CB4D9C6L)))) && g_717) >= l_877[2][0]) >= p_34))) <= g_22))) <= 4L)) , p_34) || p_34) != p_34) , p_35) , 0xDF52L) , g_100) ^ l_1069)) || g_89) , 0L), 255UL)), p_34)))
                    {
                        uint16_t l_1114[5][1][4] = {{{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}};
                        int i, j, k;

for (g_89 = 4; (g_89 >= 0); g_89 -= 1)
    {
        int16_t l_1414 = 0x1AE5L;
        int32_t l_1416 = (-7L);
        for (g_59 = 0; (g_59 <= 0); g_59 += 1)
        {
            int32_t l_1415 = (-1L);
            int i;
            l_1416 &= (g_120[g_89] ^ (((((((-1L) == ((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((g_120[g_89] >= ((((((safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(((safe_mod_func_int16_t_s_s((((0xC0L >= ((g_849[g_59] > ((((safe_add_func_int16_t_s_s(g_694, (safe_rshift_func_int16_t_s_s(((safe_add_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u(g_540, g_717)) == (safe_unary_minus_func_uint32_t_u((((safe_sub_func_int16_t_s_s(0x780FL, 0xB48CL)) <= g_120[1]) ^ g_540)))), l_1052)) , g_694), g_694)))) , g_120[g_89]) && BHoHoil_1423) ^ l_1414)) > 0xFD94L)) | g_18) == g_1217), g_120[4])) >= 0x6DB3L), 13)), 255UL)) , g_694) ^ g_694) || g_694) ^ g_694) != g_120[1])), 4)), g_694)), 0x0CL)), 0x61L)) , l_1415)) <= 0x17E2L) >= l_1224) | g_89) && l_1191[1]) || g_18));
            return g_120[g_89];
        }
        l_1327 = g_694;
        l_1416 = (safe_add_func_int8_t_s_s(8L, ((safe_add_func_uint8_t_u_u(((safe_add_func_uint32_t_u_u(l_1423, g_1217)) & ((0xA6F0F4F8L != (l_1414 == g_143)) & (+(safe_add_func_uint16_t_u_u(l_1416, g_18))))), (BHoHoil_1423 , g_100))) > g_1368[0])));
        for (l_1416 = 0; (l_1416 >= 0); l_1416 -= 1)
        {
            int8_t l_1432 = (-1L);
            int32_t l_1440 = 0x9D9C4759L;
            l_1440 &= (((BHoHogg_101 < (safe_add_func_uint8_t_u_u(g_143, (((safe_unary_minus_func_int32_t_s(3L)) , 250UL) , (safe_sub_func_uint8_t_u_u((((g_694 == l_1432) , ((g_1168 > ((safe_lshift_func_int8_t_s_u(((safe_mod_func_uint32_t_u_u(((~((l_1423 ^ g_849[0]) >= g_1217)) || BHoHoil_1423), (-6L))) ^ g_849[0]), g_143)) >= l_1416)) | 0xA9A8L)) & (-8L)), l_1439[5])))))) , 6UL) && g_120[1]);
        }
    };


                    l_922 = ((safe_sub_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(p_35, (8L & (-1L)))), 5UL)) ^ (safe_sub_func_uint32_t_u_u((0x9B71DE32L ^ (p_34 < p_34)), (+(((l_1101[9] != g_120[0]) <= 0x33L) , l_1051[0])))));
                        g_120[1] ^= (((((!((l_1114[4][0][3] == (safe_mod_func_uint32_t_u_u(((((safe_lshift_func_int8_t_s_s((safe_add_func_int16_t_s_s((+((!(g_849[0] > g_89)) ^ 0x0043E281L)), (g_97[2] >= g_143))), ((safe_sub_func_int8_t_s_s((~((((safe_mod_func_uint16_t_u_u((0xC6L || 0x36L), p_34)) & 0x68L) || g_540) , l_1051[0])), l_1094)) != 0x2E20L))) || p_34) | l_1094) & p_35), p_34))) > 1UL)) < 1UL) > p_35) > 0x5E87ADE6L) == 0x38C86F29L);
                    }
                    else
                    {
                        int8_t l_1148 = 0x89L;
                        l_1149[1] = ((0x88L > ((((g_935 || (safe_mod_func_uint32_t_u_u(p_34, (safe_add_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(((p_34 , (0L ^ (((safe_add_func_int8_t_s_s(((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(p_35, ((g_97[2] | 0x826CL) < ((((safe_rshift_func_uint8_t_u_s(g_22, p_35)) <= 253UL) | l_1094) >= l_1148)))), p_34)) < g_22), l_1148)) || g_97[2]) | 0x9933L))) || g_143), 0L)), p_34)) >= 0x23DDBF23L), g_100)), 1)) && l_1069), 0x57543A32L))))) != 1L) , p_34) | 4294967295UL)) ^ 0xB771L);

l_1228 &= (((g_935 < (safe_add_func_uint8_t_u_u(l_1233, (((safe_unary_minus_func_int32_t_s(3L)) , 250UL) , (safe_sub_func_uint8_t_u_u((((l_1094 == l_1148) , ((l_1233 > ((safe_lshift_func_int8_t_s_u(((safe_mod_func_uint32_t_u_u(((~((l_980 ^ g_849[0]) >= g_2414)) || l_1052), (-6L))) ^ g_849[0]), l_1233)) >= l_1224)) | 0xA9A8L)) & (-8L)), l_1439[5])))))) , 6UL) && g_120[1]);


{
                        int i;
                        return g_120[BHoHokg_1171];
                    }

                    if (g_101)
                            break;
                        g_120[1] = (safe_mod_func_int16_t_s_s((((((safe_lshift_func_int8_t_s_s((((safe_sub_func_uint32_t_u_u((((((safe_mod_func_int16_t_s_s(0L, (((((+65533UL) > ((safe_mod_func_uint32_t_u_u((safe_add_func_int16_t_s_s(((l_1149[1] , ((g_59 >= p_35) >= (l_1163[1][2] || (((safe_sub_func_int16_t_s_s((g_935 != (l_1101[9] >= (l_1051[2] == 4294967295UL))), p_34)) ^ g_143) & p_35)))) && p_35), g_935)), l_1051[1])) > 2L)) || g_101) < g_1168) , l_1081))) < p_34) && g_540) ^ 0x5443L) < g_777), p_35)) , l_1149[0]) , p_35), 2)) != l_1101[6]) <= p_35) , p_34) >= l_1094), g_18));
                    }
                    l_919 = (safe_rshift_func_int8_t_s_s((l_1081 ^ 4294967295UL), 0));
                }
                else
                {
                    for (g_100 = 3; (g_100 >= 1); g_100 -= 1)
                    {
                        int i;

g_59 += 1;


                    if (g_120[g_100])
                            break;
                        if (l_725[g_100])
                            break;
                        return p_35;
                    }
                }
            }
            if (g_1171)
            {
                uint16_t l_1172 = 0x80D0L;

{
                    for (g_100 = 3; (g_100 >= 1); g_100 -= 1)
                    {
                        int i;
                        if (g_120[g_100])
                            break;

for (g_717 = 3; (g_717 >= 1); g_717 -= 1)
                    {
                        int i;
                        if (g_120[g_717])
                            break;
                        if (l_725[g_717])
                            break;
                        return BHoHogg_101;
                    };


                    if (l_725[g_100])
                            break;
                        return g_935;
                    }
                }

                    l_922 &= ((((p_34 >= l_1172) && (g_849[0] , (((((0x4E57L != (safe_unary_minus_func_uint8_t_u((((((safe_sub_func_uint16_t_u_u(((safe_sub_func_int16_t_s_s((!((safe_unary_minus_func_uint16_t_u(p_35)) | p_34)), (safe_rshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u(0UL, ((l_1069 , (safe_sub_func_int32_t_s_s((((((safe_add_func_int8_t_s_s((((!g_1171) , g_935) <= l_725[0]), g_101)) != l_1172) > l_1191[1]) < l_1172) & 0UL), 0x349E8373L))) | g_935))), g_22)), p_35)))) & g_59), (-5L))) < l_1069) , g_849[0]) | l_1172) >= l_1069)))) && g_694) != 0UL) | g_777) | 0x7351L))) & l_725[3]) , g_22);

l_790 += 1;


                    g_1217 |= ((safe_mod_func_int16_t_s_s((-4L), (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((((safe_add_func_int16_t_s_s((safe_lshift_func_int16_t_s_u((safe_mod_func_int32_t_s_s((((((safe_lshift_func_int8_t_s_u(g_849[0], (!0xE43BDF21L))) || ((((((safe_lshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((~(safe_lshift_func_int16_t_s_s(p_34, 11))), 6)), 6)) , 0x9037L) || g_1168) ^ ((p_35 & (p_34 && (safe_rshift_func_uint8_t_u_s(p_34, g_143)))) != l_1081)) >= g_1168) && g_849[0])) > g_120[1]) , 0xB8L) ^ p_34), 4294967295UL)), g_89)), (-1L))) <= g_89) ^ l_1069), l_1172)), 0xFBL)))) > l_1216);
            }
            else
            {
                int32_t l_1218 = 0L;
                int32_t l_1220 = 0xD6A84518L;
                int32_t l_1221 = 0x3E2F8B07L;
                int32_t l_1222 = 0xBC228DECL;
                int32_t l_1223 = 0L;
                int32_t l_1225 = 0x92788A2FL;
                int32_t l_1230 = 0x8A193837L;
                int32_t l_1232[1][1];
                int i, j;
                for (i = 0; i < 1; i++)
                {
                    for (j = 0; j < 1; j++)
                        {
{
            for (i = 0; i < 4; i++)
            {
                transparent_crc(g_1482[l_1229][l_1223][i], "g_1482[l_1229][l_1223][i]", l_793);
                if (l_793) printf("index = [%d][%d][%d]\n", l_1229, l_1223, i);

            }
        }

                    l_1232[i][j] = 0xBE2CE0ADL;}
                }


for (g_694 = 0; (g_694 != 13); g_694++)
    {
        uint32_t l_83 = 0xB3DEF23EL;
        l_778 = l_778;
        l_1216 = ((g_694 > ((((safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(l_1361, (safe_rshift_func_uint16_t_u_s(0xA4A7L, (((l_83 ^ ((((g_1217 == ((safe_lshift_func_int16_t_s_u(((((g_59 || ((((g_89 <= (safe_sub_func_uint8_t_u_u(g_59, (g_18 ^ l_83)))) | 0x39L) <= g_2414) & 0x3186L)) <= l_1281) , g_2414) & 1L), l_83)) ^ 65532UL)) & l_83) || 0x439AL) && 255UL)) == g_1217) != g_18))))), 5L)) >= l_1361) == g_18) != g_694)) <= g_2414);
        return g_89;
    };


                    if (l_1281)
                        break;

                    l_1233++;
            }

{
            for (l_778 = 0; l_778 < 3; l_778++)
            {
                transparent_crc(g_1548[l_1227][g_2100][l_778], "g_1548[l_1227][g_2100][l_778]", l_1329);
                if (l_1329) printf("index = [%d][%d][%d]\n", l_1227, g_2100, l_778);

            }
        }

                    if (g_777)
            {
                uint32_t l_1241[4][8] = {{0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}, {0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}, {0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}, {0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}};
                uint16_t l_1252 = 0x759AL;
                int i, j;

g_2003[0] |= (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u(g_1482[0][1][0], ((~((((-6L) < BHoHoil_1423) >= g_120[1]) | (BHoHoil_1423 , BHoHoil_1423))) != (((safe_lshift_func_uint16_t_u_s(((g_1548[4][6][2] || ((((safe_rshift_func_int8_t_s_s(1L, 4)) <= 0xC812E52FL) || g_1368[1]) <= 0UL)) , l_725[1]), 3)) != k) < 65535UL)))) | g_1482[2][1][1]) <= 4294967292UL) && l_1327) > l_880), g_849[0])), g_1171));

                    g_120[4] |= ((safe_lshift_func_uint16_t_u_s(6UL, 8)) , ((safe_unary_minus_func_int32_t_s((safe_sub_func_int16_t_s_s((((((l_1241[2][6] | 0L) & ((((safe_rshift_func_uint16_t_u_u(((safe_unary_minus_func_int16_t_s(l_1191[0])) & (p_34 , (((((safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u((p_34 , (safe_add_func_int16_t_s_s((((~l_1252) , (safe_add_func_uint16_t_u_u((((((g_18 | (safe_lshift_func_uint16_t_u_s((safe_add_func_uint8_t_u_u(((((0x1CA4L < p_34) && g_89) | g_97[2]) ^ p_35), p_35)), p_34))) != p_34) || g_717) > l_1051[2]) , 0x6DB4L), l_778))) || p_34), 0x5D57L))), g_97[2])), l_1219)) || 1UL) || p_35) | p_34) != g_849[0]))), l_790)) && 1L) > 0x1DC0L) , p_35)) != 0x35A6L) || 0xE981L) | g_777), 1L)))) , g_777));
            }
            else
            {
                uint16_t l_1263[6][10] = {{0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}, {0xE2A8L, 0x6DABL, 0UL, 0xB1CCL, 0xB1CCL, 0UL, 0x6DABL, 0xE2A8L, 0UL, 0xE2A8L}};
                int32_t l_1277[9];
                int16_t l_1321 = 0x3AFEL;
                int i, j;

{
            uint32_t l_749 = 4294967288UL;
            if ((~(safe_add_func_uint32_t_u_u(((0L != (((l_725[2] || (safe_sub_func_int8_t_s_s(0x65L, (safe_mod_func_uint32_t_u_u(g_2467, l_1069))))) ^ ((safe_add_func_uint16_t_u_u((g_717 , (safe_lshift_func_int8_t_s_u((0xA7L & 6L), 0))), (((p_35 == l_1433) >= g_18) < g_540))) < (-1L))) < p_35)) , 0x11329388L), 4294967295UL))))
            {
                int32_t l_769[1];
                int i;
                for (i = 0; i < 1; i++)
                    {
for (g_1171 = (-26); (g_1171 <= 16); g_1171++)
                    {
                        int8_t l_524 = (-8L);

g_1171 += 1;


                    l_524 = g_89;

{
                int16_t l_1094 = 0xECC4L;
                int32_t l_1149[2];
                int16_t l_1163[7][10];
                int i, j;

for (g_59 = 0; (g_59 <= 0); g_59 += 1)
        {
            int32_t l_1415 = (-1L);
            int i;
            l_1224 &= (g_120[l_524] ^ (((((((-1L) == ((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((g_120[l_524] >= ((((((safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(((safe_mod_func_int16_t_s_s((((0xC0L >= ((g_849[g_59] > ((((safe_add_func_int16_t_s_s(g_2254, (safe_rshift_func_int16_t_s_s(((safe_add_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u(g_694, l_880)) == (safe_unary_minus_func_uint32_t_u((((safe_sub_func_int16_t_s_s(0x780FL, 0xB48CL)) <= g_120[1]) ^ g_694)))), BHoHoll_1052)) , g_2254), g_2254)))) , g_120[l_524]) && BHoHoll_1052) ^ l_1321)) > 0xFD94L)) | g_18) == g_2414), g_120[4])) >= 0x6DB3L), 13)), 255UL)) , g_2254) ^ g_2254) || g_2254) ^ g_2254) != g_120[1])), 4)), g_2254)), 0x0CL)), 0x61L)) , l_1415)) <= 0x17E2L) >= l_919) | l_524) && l_1191[1]) || g_18));
            return g_120[l_524];
        };


                    for (i = 0; i < 2; i++)
                    l_1149[i] = 0xBA560EB5L;
                for (i = 0; i < 7; i++)
                {
                    for (j = 0; j < 10; j++)
                        l_1163[i][j] = 6L;
                }
                i = (g_694 == g_694);
                for (g_935 = 16; (g_935 != (-28)); g_935 = safe_sub_func_int16_t_s_s(g_935, 5))
                {
                    int32_t l_1095 = (-6L);
                    for (BHoHoil_1423 = 0; (BHoHoil_1423 <= 0); BHoHoil_1423 += 1)
                    {
                        int i, j;
                        return l_877[BHoHoil_1423][BHoHoil_1423];
                    }

for (l_1095 = 0; l_1095 < 9; l_1095++)
                    l_1277[l_1095] = (-1L);

                    l_1095 = ((((g_120[1] || (-5L)) && ((((safe_lshift_func_int16_t_s_u((((safe_rshift_func_int16_t_s_u((g_694 || (((0xBBL ^ (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(g_120[1], (((((-1L) > (g_143 , 1L)) , ((safe_add_func_int16_t_s_s(g_22, g_22)) & 4294967289UL)) <= g_22) != l_1361))), g_120[1]))) | g_694) == g_694)), g_22)) >= 0x20L) , 0x45CAL), g_694)) > (-2L)) <= 0x8BB0L) < l_1094)) , l_1361) ^ g_2254);
                    for (l_1329 = 0; (l_1329 <= 0); l_1329 += 1)
                    {
                        int i, j;
                        g_120[2] = l_877[l_1329][l_1329];
                    }
                }
                if ((g_22 , g_22))
                {
                    uint16_t l_1101[10] = {0xEA04L, 0xEA04L, 0UL, 0xEA04L, 0xEA04L, 0UL, 0xEA04L, 0xEA04L, 0UL, 0xEA04L};
                    int i;
                    if (l_524)
                        break;
                    if ((safe_add_func_int8_t_s_s((safe_add_func_int8_t_s_s((((g_694 == ((((((((!((g_22 ^ (l_1361 || ((l_1101[9] & ((-7L) | ((((safe_sub_func_uint8_t_u_u(g_694, (safe_add_func_uint32_t_u_u(BHoHoil_1423, 0x1CB4D9C6L)))) && l_524) >= l_877[2][0]) >= g_22))) <= g_22))) <= 4L)) , g_22) || g_22) != g_22) , g_694) , 0xDF52L) , l_1216) ^ l_1361)) || g_717) , 0L), 255UL)), g_22)))
                    {
                        uint16_t l_1114[5][1][4] = {{{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}, {{0x8B41L, 0x38EFL, 1UL, 0x38EFL}}};
                        int i, j, k;
                        l_778 = ((safe_sub_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(g_694, (8L & (-1L)))), 5UL)) ^ (safe_sub_func_uint32_t_u_u((0x9B71DE32L ^ (g_22 < g_22)), (+(((l_1101[9] != g_120[0]) <= 0x33L) , l_1051[0])))));
                        g_120[1] ^= (((((!((l_1114[4][0][3] == (safe_mod_func_uint32_t_u_u(((((safe_lshift_func_int8_t_s_s((safe_add_func_int16_t_s_s((+((!(g_849[0] > g_717)) ^ 0x0043E281L)), (g_97[2] >= BHoHoil_1423))), ((safe_sub_func_int8_t_s_s((~((((safe_mod_func_uint16_t_u_u((0xC6L || 0x36L), g_22)) & 0x68L) || g_2254) , l_1051[0])), l_1094)) != 0x2E20L))) || g_22) | l_1094) & g_694), g_22))) > 1UL)) < 1UL) > g_694) > 0x5E87ADE6L) == 0x38C86F29L);
                    }
                    else
                    {
                        int8_t l_1148 = 0x89L;
                        l_1149[1] = ((0x88L > ((((g_935 || (safe_mod_func_uint32_t_u_u(g_22, (safe_add_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(((g_22 , (0L ^ (((safe_add_func_int8_t_s_s(((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(g_694, ((g_97[2] | 0x826CL) < ((((safe_rshift_func_uint8_t_u_s(g_22, g_694)) <= 253UL) | l_1094) >= l_1148)))), g_22)) < g_22), l_1148)) || g_97[2]) | 0x9933L))) || BHoHoil_1423), 0L)), g_22)) >= 0x23DDBF23L), l_1216)), 1)) && l_1361), 0x57543A32L))))) != 1L) , g_22) | 4294967295UL)) ^ 0xB771L);
                        if (g_2254)
                            break;
                        g_120[1] = (safe_mod_func_int16_t_s_s((((((safe_lshift_func_int8_t_s_s((((safe_sub_func_uint32_t_u_u((((((safe_mod_func_int16_t_s_s(0L, (((((+65533UL) > ((safe_mod_func_uint32_t_u_u((safe_add_func_int16_t_s_s(((l_1149[1] , ((g_59 >= g_694) >= (l_1163[1][2] || (((safe_sub_func_int16_t_s_s((g_935 != (l_1101[9] >= (l_1051[2] == 4294967295UL))), g_22)) ^ BHoHoil_1423) & g_694)))) && g_694), g_935)), l_1051[1])) > 2L)) || g_2254) < BHoHoll_1052) , i))) < g_22) && g_2254) ^ 0x5443L) < g_143), g_694)) , l_1149[0]) , g_694), 2)) != l_1101[6]) <= g_694) , g_22) >= l_1094), g_18));
                    }
                    l_1329 = (safe_rshift_func_int8_t_s_s((i ^ 4294967295UL), 0));
                }
                else
                {
                    for (l_1216 = 3; (l_1216 >= 1); l_1216 -= 1)
                    {
                        int i;
                        if (g_120[l_1216])
                            break;
                        if (l_725[l_1216])
                            break;
                        return g_694;
                    }
                }
            }

                    l_922 &= l_524;
                    }
{
                uint32_t l_1241[4][8] = {{0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}, {0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}, {0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}, {0x92359C80L, 18446744073709551615UL, 1UL, 5UL, 0xE2F39250L, 1UL, 0xE2F39250L, 5UL}};
                uint16_t l_1252 = 0x759AL;
                int i, j;
                g_120[4] |= ((safe_lshift_func_uint16_t_u_s(6UL, 8)) , ((safe_unary_minus_func_int32_t_s((safe_sub_func_int16_t_s_s((((((l_1241[2][6] | 0L) & ((((safe_rshift_func_uint16_t_u_u(((safe_unary_minus_func_int16_t_s(l_1191[0])) & (l_1433 , (((((safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u((l_1433 , (safe_add_func_int16_t_s_s((((~l_1252) , (safe_add_func_uint16_t_u_u((((((g_18 | (safe_lshift_func_uint16_t_u_s((safe_add_func_uint8_t_u_u(((((0x1CA4L < l_1433) && l_880) | g_97[2]) ^ g_2254), g_2254)), l_1433))) != l_1433) || l_880) > l_1051[2]) , 0x6DB4L), l_1219))) || l_1433), 0x5D57L))), g_97[2])), j)) || 1UL) || g_2254) | l_1433) != g_849[0]))), l_880)) && 1L) > 0x1DC0L) , g_2254)) != 0x35A6L) || 0xE981L) | l_1433), 1L)))) , l_1433));
            }


g_935 += 1;


                    ;


                    l_769[i] = 0x804970A5L;}
                g_120[1] = 1L;
                if (p_35)
                    continue;
                l_749 = (safe_rshift_func_uint16_t_u_u(g_97[2], 13));
                l_1224 = (safe_lshift_func_int8_t_s_s((5UL >= (0UL < (safe_add_func_int8_t_s_s((((safe_rshift_func_int16_t_s_s((g_18 != (safe_sub_func_int32_t_s_s((safe_unary_minus_func_int32_t_s((safe_mod_func_int8_t_s_s((safe_mod_func_int32_t_s_s(0x5B48709BL, ((safe_rshift_func_int16_t_s_s(g_18, p_35)) || 3L))), (safe_sub_func_int32_t_s_s(g_935, ((((safe_rshift_func_int16_t_s_u(p_35, 7)) || g_18) || l_769[0]) <= g_2467))))))), g_22))), 6)) != p_35) != g_100), l_1069)))), g_2467));
            }
            else
            {
                int16_t l_775 = (-4L);
                int32_t l_776 = (-3L);
                g_1168 = ((((l_1433 ^ (l_725[2] , (0xB43536D7L > 0x43474B68L))) >= (((g_18 < ((safe_add_func_int8_t_s_s(l_1069, 0xFAL)) & (safe_mod_func_int8_t_s_s(((((((l_775 | l_776) || g_540) || g_717) , g_2467) <= 6L) <= 0x62L), 0x36L)))) && l_1433) > 0x8EL)) != g_2467) == g_2467);
            }


for (BHoHojl_919 = 0; BHoHojl_919 < 2; BHoHojl_919++)
        {
            transparent_crc(g_1540[l_1228][BHoHojl_919], "g_1540[l_1228][BHoHojl_919]", l_1359);
            if (l_1359) printf("index = [%d][%d]\n", l_1228, BHoHojl_919);

        };


                    for (g_2100 = 0; g_2100 < 4; g_2100++)
            {
                transparent_crc(g_1482[l_1229][l_1229][g_2100], "g_1482[l_1229][l_1229][g_2100]", l_1228);
                if (l_1228) printf("index = [%d][%d][%d]\n", l_1229, l_1229, g_2100);

            };


                    --l_1233;
        }


{

{
            int8_t l_94[2];
            uint32_t l_134 = 18446744073709551615UL;
            uint16_t l_142 = 0x7BCBL;
            int i;
            for (i = 0; i < 2; i++)
                l_94[i] = 1L;
            for (l_1081 = 0; (l_1081 <= 1); l_1081 += 1)
            {
                int i;
                for (BHoHohl_1361 = 0; (BHoHohl_1361 <= 1); BHoHohl_1361 += 1)
                {
                    int i;
                    return l_94[l_1081];
                }
                if (l_94[l_1081])
                    continue;
                if (l_94[0])
                    continue;
            }
            for (g_100 = 0; (g_100 > (-19)); g_100 = safe_sub_func_uint16_t_u_u(g_100, 7))
            {
                uint8_t l_103[4] = {1UL, 0xABL, 1UL, 0xABL};
                int i;
                g_97[2] ^= g_1217;
                for (g_1168 = 1; (g_1168 <= 6); g_1168 += 1)
                {
                    int16_t l_110[7] = {0xD96CL, (-2L), 0xD96CL, (-2L), 0xD96CL, (-2L), 0xD96CL};
                    int8_t l_168 = 0xE9L;
                    int8_t l_181 = 0xCFL;
                    int i;
                    for (g_89 = 6; (g_89 >= 1); g_89 -= 1)
                    {
                        int i;
                        l_1081 = (safe_mod_func_int32_t_s_s(g_97[g_89], g_1171));
                        l_790 = g_18;
                        g_2254 &= 0xEC293C97L;
                    }
                    l_103[3]++;
                    if (((safe_rshift_func_int8_t_s_u((((((g_18 ^ ((safe_add_func_uint32_t_u_u((l_110[0] == (g_2254 == (safe_mod_func_uint16_t_u_u(0UL, (((safe_unary_minus_func_uint16_t_u(g_100)) | (l_94[1] , ((safe_add_func_uint16_t_u_u(((((((safe_mod_func_int8_t_s_s(g_2414, (safe_sub_func_uint8_t_u_u((g_120[1] > (l_1219 | g_2414)), g_2414)))) ^ BHoHohl_1361) || 0x17461B67L) && g_97[2]) == 1L) , g_18), g_120[4])) , g_120[3]))) & g_100))))), g_2254)) > 0x3AD0L)) & g_2254) || g_89) != l_94[1]) == l_1361), g_18)) <= (-9L)))
                    {
                        int8_t l_141 = (-10L);
                        g_143 ^= (g_97[6] < (safe_mod_func_int16_t_s_s((((g_120[1] ^ ((safe_add_func_uint32_t_u_u(((g_2254 <= ((safe_sub_func_uint8_t_u_u(l_103[1], (((((((safe_sub_func_uint16_t_u_u(((l_134 >= g_1168) > 0UL), ((((((safe_sub_func_int32_t_s_s((((safe_add_func_uint8_t_u_u((((((((l_790 & (safe_lshift_func_uint8_t_u_u((l_94[0] <= l_110[0]), g_2254))) || g_2414) | 0xF7L) & l_141) , 0x6CL) | l_790) < l_94[1]), l_103[3])) >= g_1171) > g_89), 1L)) || g_101) >= g_1168) , g_1171) > l_142) < g_1168))) == l_1219) , g_89) && 0x68L) && l_1361) >= l_110[0]) ^ g_2414))) != g_120[1])) != (-5L)), 0xB89AE2E4L)) > l_1361)) > g_100) || 0x3285CC41L), g_97[2])));
                    }
                    else
                    {
                        int32_t l_167 = 0xBD733D80L;
                        if (g_101)
                            break;
                        g_120[4] = (safe_rshift_func_int16_t_s_u((safe_lshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_s((safe_mod_func_uint8_t_u_u(((g_97[4] ^ (BHoHohl_1361 | (safe_lshift_func_int16_t_s_u((((safe_mod_func_int16_t_s_s(((safe_rshift_func_int8_t_s_u(2L, ((+(((g_89 , ((safe_rshift_func_uint8_t_u_s(((l_103[3] > ((((g_2414 & 0x8D56L) > (safe_lshift_func_uint8_t_u_s((safe_add_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((65535UL ^ (4L >= (-10L))), g_120[0])), g_89)), l_1081))) == 0xB673D79CL) ^ 1L)) | l_790), l_103[3])) <= l_1219)) != (-8L)) < l_167)) | BHoHohl_1361))) , g_1168), l_103[3])) ^ 0xBAC23114L) | l_110[0]), l_168)))) | g_89), (-2L))), 12)), 10)), l_790));
                        g_120[4] = ((((safe_add_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((safe_lshift_func_uint8_t_u_s(((255UL >= 254UL) < ((safe_mod_func_uint16_t_u_u(g_2254, 65531UL)) || 0x8F5F89A5L)), (((((+(((((~g_101) & ((g_1217 , l_168) < ((((((l_790 && g_89) && l_167) == g_89) , 6L) ^ g_143) , 0x9D48L))) < 0x5183DF78L) , l_142) & 1L)) != l_167) || l_181) || l_790) <= 4294967286UL))) || 0x76D7L), 1)), l_1081)) || 0xFB851665L), 0x69F6L)) >= g_2414) , 0xDEBA2DDDL) <= l_1361);
                    }
                }
                for (BHoHohl_1361 = 0; (BHoHohl_1361 != 33); BHoHohl_1361++)
                {
                    return g_2414;
                }
                if (l_103[3])
                    break;
            }
        }

                    for (g_2469 = 0; g_2469 < 8; g_2469++)
        {
            for (l_1329 = 0; l_1329 < 3; l_1329++)
            {
                transparent_crc(g_1548[l_1359][g_2469][l_1329], "g_1548[l_1359][g_2469][l_1329]", l_1327);
                if (l_1327) printf("index = [%d][%d][%d]\n", l_1359, g_2469, l_1329);

            }
        }
    }

                    for (i = 0; i < 9; i++)
                    l_1277[i] = (-1L);

{
                uint16_t l_1172 = 0x80D0L;
                l_1224 &= ((((l_1052 >= l_1172) && (g_849[0] , (((((0x4E57L != (safe_unary_minus_func_uint8_t_u((((((safe_sub_func_uint16_t_u_u(((safe_sub_func_int16_t_s_s((!((safe_unary_minus_func_uint16_t_u(g_2254)) | l_1052)), (safe_rshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u(0UL, ((g_1171 , (safe_sub_func_int32_t_s_s((((((safe_add_func_int8_t_s_s((((!BHoHokg_1171) , l_1321) <= l_725[0]), g_101)) != l_1172) > l_1191[1]) < l_1172) & 0UL), 0x349E8373L))) | l_1321))), l_1433)), g_2254)))) & g_59), (-5L))) < g_1171) , g_849[0]) | l_1172) >= g_1171)))) && BHoHogg_101) != 0UL) | l_1052) | 0x7351L))) & l_725[3]) , l_1433);
                g_2414 |= ((safe_mod_func_int16_t_s_s((-4L), (safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((((safe_add_func_int16_t_s_s((safe_lshift_func_int16_t_s_u((safe_mod_func_int32_t_s_s((((((safe_lshift_func_int8_t_s_u(g_849[0], (!0xE43BDF21L))) || ((((((safe_lshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((~(safe_lshift_func_int16_t_s_s(l_1052, 11))), 6)), 6)) , 0x9037L) || l_980) ^ ((g_2254 & (l_1052 && (safe_rshift_func_uint8_t_u_s(l_1052, l_1052)))) != l_1327)) >= l_980) && g_849[0])) > g_120[1]) , 0xB8L) ^ l_1052), 4294967295UL)), g_100)), (-1L))) <= g_100) ^ g_1171), l_1172)), 0xFBL)))) > g_717);
            }

                    for (l_922 = 0; (l_922 <= (-8)); --l_922)
                {
                    uint8_t l_1265 = 0xA0L;
                    int32_t l_1272 = 0xA92A5564L;
                    uint8_t l_1274 = 1UL;
                    int32_t l_1325 = 0x05F0F06DL;
                    int32_t l_1326 = 0xA526867EL;
                    int8_t l_1360 = 0xE8L;
                    if (((safe_rshift_func_int16_t_s_s(1L, (g_717 < ((l_1263[4][9] && (!(l_1265 || p_35))) , ((((p_35 , (safe_sub_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_u(((((safe_lshift_func_uint8_t_u_u(g_97[2], 2)) >= g_100) | 8L) , g_143), g_849[0])) ^ g_120[1]), p_34))) == g_18) >= g_101) < l_1263[0][9]))))) >= l_1081))
                    {
                        uint32_t l_1278 = 0x7A1781B4L;
                        l_1274--;
                        l_1278--;
                    }
                    else
                    {
                        uint8_t l_1292 = 255UL;
                        int32_t l_1301 = 0L;
                        l_1281 ^= 0x10E3B930L;
                        l_1277[4] &= (safe_rshift_func_int16_t_s_u((safe_mod_func_uint16_t_u_u((9UL || ((g_849[0] < ((g_1217 >= g_849[0]) || g_935)) , (((safe_sub_func_int16_t_s_s((safe_sub_func_int8_t_s_s(0xDDL, (0UL ^ (safe_lshift_func_uint16_t_u_u(((l_1292 <= (safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u((g_777 & (-1L)), g_59)), l_1219)), 7)), p_35))) , g_143), 1))))), 0UL)) & p_35) || p_34))), l_940[0])), p_35));

l_1233 += 1;


                    l_1301 = 0x9FC577ABL;
                    }
                    for (l_790 = 0; (l_790 >= 7); l_790 = safe_add_func_uint8_t_u_u(l_790, 3))
                    {


if (g_2254)
                            continue;

                    for (g_100 = 0; (g_100 <= 5); g_100 += 1)
                    {
                        return l_1325;
                    };


                    return p_35;
                    }

if (l_1052)
                        break;

                    if ((p_35 , (((safe_add_func_int8_t_s_s((safe_lshift_func_int8_t_s_u(p_35, 3)), ((l_1277[4] , (safe_rshift_func_uint8_t_u_u(g_540, (safe_lshift_func_int8_t_s_s((l_1052 > (safe_add_func_uint16_t_u_u(p_34, (((~(safe_add_func_uint8_t_u_u((((p_35 >= (safe_mod_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(g_97[0], (g_849[0] , l_1321))) || p_34), g_143))) && l_1229) ^ p_35), l_1081))) && l_1226[0][1][2]) , p_34)))), 5))))) >= p_34))) >= 65527UL) == l_1277[4])))
                    {
                        uint32_t l_1322 = 1UL;
                        int32_t l_1328[3];
                        uint16_t l_1330[7][2] = {{1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}, {1UL, 0UL}};
                        int i, j;
                        for (i = 0; i < 3; i++)
                            l_1328[i] = 5L;
                        --l_1322;

{
        transparent_crc(g_2003[i], "g_2003[i]", l_1219);
        if (l_1219) printf("index = [%d]\n", i);

    }

                    l_1330[3][0]++;

for (l_778 = 0; l_778 < 3; l_778++)
            {
{
                BHoHoil_1423--;
            }

                    l_1328[l_778] = 0x4EA06463L;}

                    if (l_1326)
                            continue;
                    }
                    else
                    {
                        int32_t l_1333[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_1333[i] = 8L;
                        l_1333[2] = p_34;
                        g_120[3] = (safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(0x461CL, 7)), (l_1051[0] < (g_777 < (safe_add_func_uint16_t_u_u(((0x1114L | g_100) != (safe_mod_func_uint32_t_u_u((safe_mod_func_int16_t_s_s(g_1217, (safe_add_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u(((((-1L) ^ (safe_add_func_int8_t_s_s(((0x17D87BE6L != (safe_rshift_func_int8_t_s_s(((safe_unary_minus_func_uint32_t_u((!g_143))) ^ 0x50L), g_540))) ^ p_35), p_35))) < 8UL) , g_1171), 14)) , l_1329), l_922)))), 0x45D6E44FL))), g_22))))));
                    }
                    if ((g_717 >= ((l_1051[0] != (((p_35 == (g_849[0] ^ (l_1265 > p_34))) < p_35) == g_849[0])) <= (safe_lshift_func_uint8_t_u_s(((safe_lshift_func_int8_t_s_u(p_34, g_89)) , 0xF4L), 2)))))
                    {
                        l_1277[4] = p_35;
                    }
                    else
                    {
                        int32_t l_1358 = 0x27225A3DL;
                        --l_1361;

if (l_1274)
                    break;

                    if (g_22)
                            break;
                    }
                }
            }
            for (l_1281 = (-1); (l_1281 == 31); ++l_1281)
            {

{
                        l_1439[2] |= g_1217;
                        return l_1069;
                    }

                    l_1081 ^= ((safe_add_func_int8_t_s_s(l_1359, 1L)) < (p_34 != (((((-2L) > g_18) , (((g_89 != 0xAEL) & ((((g_1368[1] > (g_1168 <= p_35)) & l_1359) == g_97[5]) > l_1369)) == 4294967286UL)) , (-1L)) ^ 255UL)));
            }
        }
        g_120[1] = (safe_sub_func_uint16_t_u_u(((0x68DCACFFL | (safe_sub_func_int8_t_s_s((((((safe_mod_func_uint32_t_u_u(((((((g_97[2] , (safe_lshift_func_int16_t_s_u((g_1368[2] && 0L), 0))) | ((l_1361 && (safe_mod_func_int8_t_s_s((p_35 && (safe_rshift_func_int16_t_s_s((((((((~(((safe_add_func_uint16_t_u_u(((((safe_lshift_func_uint8_t_u_u((((safe_add_func_uint8_t_u_u(l_1369, p_34)) && ((((1L != 0x1161L) != p_34) ^ l_980) ^ g_59)) < l_1361), g_120[1])) >= g_849[0]) , (-1L)) | 0x3F27L), g_1368[0])) , 0x8D90L) ^ g_1168)) ^ l_725[2]) | 0xC3L) && g_1368[1]) <= p_34) , l_1226[0][1][2]) , l_1226[0][0][2]), 2))), p_34))) <= l_1273)) >= 0x27L) >= g_97[6]) != 2L) != 0x1C966BF2L), g_1168)) | (-3L)) < g_143) > p_35) == p_34), l_1191[1]))) <= g_717), 8L));
    }
    for (g_100 = 4; (g_100 >= 0); g_100 -= 1)
    {
        int16_t l_1414 = 0x1AE5L;
        int32_t l_1416 = (-7L);
                                            while ((!l_1414) )
{

l_1423 += 1;


}
                    for (g_1171 = 0; (g_1171 <= 0); g_1171 += 1)
        {
            int32_t l_1415 = (-1L);
            int i;
                                                                                  if ((l_922<=1))
                    if ((l_778<=0))
                    l_1416 &= (g_120[g_100] ^ (((((((-1L) == ((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((g_120[g_100] >= ((((((safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(((safe_mod_func_int16_t_s_s((((0xC0L >= ((g_849[g_1171] > ((((safe_add_func_int16_t_s_s(p_35, (safe_rshift_func_int16_t_s_s(((safe_add_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u(g_540, g_717)) == (safe_unary_minus_func_uint32_t_u((((safe_sub_func_int16_t_s_s(0x780FL, 0xB48CL)) <= g_120[1]) ^ g_540)))), g_143)) , p_35), p_35)))) , g_120[g_100]) && g_22) ^ l_1414)) > 0xFD94L)) | g_18) == g_1217), g_120[4])) >= 0x6DB3L), 13)), 255UL)) , p_35) ^ p_35) || p_35) ^ p_35) != g_120[1])), 4)), p_35)), 0x0CL)), 0x61L)) , l_1415)) <= 0x17E2L) >= l_922) | g_100) && l_1191[1]) || g_18));
            return g_120[g_100];
        }
        l_1329 = p_35;
        l_1416 = (safe_add_func_int8_t_s_s(8L, ((safe_add_func_uint8_t_u_u(((safe_add_func_uint32_t_u_u(l_1423, g_1217)) & ((0xA6F0F4F8L != (l_1414 == p_34)) & (+(safe_add_func_uint16_t_u_u(l_1416, g_18))))), (g_22 , l_790))) > g_1368[0])));

for (l_919 = 0; l_919 < 3; l_919++)
                g_1368[l_919] = (-1L);

                    for (l_1416 = 0; (l_1416 >= 0); l_1416 -= 1)
        {
            int8_t l_1432 = (-1L);
            int32_t l_1440 = 0x9D9C4759L;
            l_1440 &= (((g_935 < (safe_add_func_uint8_t_u_u(p_34, (((safe_unary_minus_func_int32_t_s(3L)) , 250UL) , (safe_sub_func_uint8_t_u_u((((p_35 == l_1432) , ((l_1433 > ((safe_lshift_func_int8_t_s_u(((safe_mod_func_uint32_t_u_u(((~((l_1423 ^ g_849[0]) >= g_1217)) || g_22), (-6L))) ^ g_849[0]), p_34)) >= l_1416)) | 0xA9A8L)) & (-8L)), l_1439[5])))))) , 6UL) && g_120[1]);
        }
    }
    return g_97[6];
}







static int16_t func_38(int32_t p_39, int8_t p_40, uint16_t p_41, int16_t p_42, uint16_t p_43)
{
    uint8_t l_86 = 1UL;
    int32_t l_102 = 0xD37901A9L;
    int32_t l_213[6] = {0x32FFC17BL, 0x32FFC17BL, 1L, 0x32FFC17BL, 0x32FFC17BL, 1L};
    int32_t l_253 = 0x1789042DL;
    int16_t l_351 = (-8L);
    uint32_t l_396 = 18446744073709551609UL;
    uint32_t l_419 = 0UL;
    int16_t l_598[4];
    uint8_t l_613 = 0x0FL;
    uint8_t l_616 = 255UL;
    int8_t l_699 = 0x1AL;
    int i;
    for (i = 0; i < 4; i++)
        { if (((l_351 < g_694) && l_86))
                    l_598[i] = 0xF69FL;}
    for (p_42 = 0; (p_42 != 13); p_42++)
    {
        uint32_t l_83 = 0xB3DEF23EL;
        p_39 = p_39;
        g_89 = ((p_42 > ((((safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(g_59, (safe_rshift_func_uint16_t_u_s(0xA4A7L, (((l_83 ^ ((((p_41 == ((safe_lshift_func_int16_t_s_u(((((l_86 || ((((p_40 <= (safe_sub_func_uint8_t_u_u(l_86, (g_18 ^ l_83)))) | 0x39L) <= p_43) & 0x3186L)) <= g_22) , p_43) & 1L), l_83)) ^ 65532UL)) & l_83) || 0x439AL) && 255UL)) == p_41) != g_18))))), 5L)) >= g_59) == g_18) != p_42)) <= p_43);
        return p_40;
    }
    for (p_43 = (-30); (p_43 <= 7); p_43++)
    {
        uint8_t l_121 = 0x0CL;
        int8_t l_296 = 0x7BL;
        int32_t l_368 = 0x73C1A89DL;
        uint16_t l_389 = 9UL;
        int32_t l_390 = 4L;
        int32_t l_394 = 0x0A309251L;
        int16_t l_472 = 1L;
        int32_t l_656 = 4L;
        for (l_86 = (-11); (l_86 >= 14); ++l_86)
        {
            int8_t l_94[2];
            uint32_t l_134 = 18446744073709551615UL;
            uint16_t l_142 = 0x7BCBL;
            int i;
            for (i = 0; i < 2; i++)
                {
for (l_394 = 0; l_394 < 4; l_394++)
            {
                transparent_crc(g_1482[l_368][l_390][l_394], "g_1482[l_368][l_390][l_394]", g_2469);
                if (g_2469) {
{
                uint32_t l_2518 = 0x2412710BL;
                --l_2518;
            }

                    printf("index = [%d][%d][%d]\n", l_368, l_390, l_394);}

            };


                    l_94[i] = 1L;}

{
            l_86--;
            if (g_101)
                continue;
            for (g_694 = 0; (g_694 == (-12)); g_694 = safe_sub_func_int8_t_s_s(g_694, 2))
            {
                return g_849[0];
            }
        }

                    for (p_39 = 0; (p_39 <= 1); p_39 += 1)
            {
                int i;
                for (g_59 = 0; (g_59 <= 1); g_59 += 1)
                {
                    int i;
                    return l_94[p_39];
                }

p_40 -= 1;


                    if (l_94[p_39])
                    continue;
                if (l_94[0])
                    {
{
                        p_39 = g_2469;
                    }


for (p_42 = 0; (p_42 < (-17)); --p_42)
        {
            uint8_t l_198 = 1UL;
            int16_t l_261 = (-10L);
            uint16_t l_350 = 5UL;
            int32_t l_367 = 1L;
            int32_t l_391[3][6] = {{0xD2D39850L, 1L, 1L, 0L, 0L, 1L}, {0xD2D39850L, 1L, 1L, 0L, 0L, 1L}, {0xD2D39850L, 1L, 1L, 0L, 0L, 1L}};
            uint32_t l_431 = 0x13F79E03L;
            int i, j;
            if (l_616)
                break;
            l_656 ^= l_616;
            for (l_656 = 0; (l_656 == 26); ++l_656)
            {
                uint32_t l_210 = 0UL;
                int8_t l_281[8][7] = {{0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}};
                uint32_t l_326 = 0x0A0DE782L;
                int32_t l_363 = 0L;
                int32_t l_392 = (-1L);
                int32_t l_395 = 0L;
                const uint32_t l_420 = 0xA82EA14BL;
                const int16_t l_427 = 0L;
                int i, j;
                if ((l_656 || (safe_mod_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_u(0x73L, 5)) | ((safe_mod_func_int32_t_s_s(g_2431, (safe_rshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s((((0x7CB8L < 0xB2B8L) , ((l_198 ^ 0xDBL) != l_198)) && 0xD1L), g_1171)), 11)))) != l_656)), 0xA615L))))
                {
                    uint32_t l_207 = 0x44D27D01L;
                    g_120[3] = p_42;
                    for (l_134 = (-26); (l_134 >= 44); l_134++)
                    {
                        return l_198;
                    }
                    g_120[1] = (((((((g_120[1] && g_2254) || ((safe_rshift_func_uint16_t_u_u(((g_1217 , ((safe_mod_func_uint32_t_u_u(((safe_mod_func_uint16_t_u_u(((((0x47C1L >= (g_89 ^ l_207)) <= (safe_sub_func_uint16_t_u_u(((g_18 && p_43) , l_616), l_616))) ^ g_120[1]) < g_120[0]), g_120[1])) & g_97[2]), 0x3A8961DAL)) & 0L)) , p_42), 4)) & g_120[1])) ^ l_656) == l_207) | l_210) & 0xD933A2BCL) & l_616);
                }
                else
                {
                    uint8_t l_258 = 0x75L;
                    int32_t l_262 = 0x18EC19C0L;
                    for (l_134 = (-24); (l_134 < 42); ++l_134)
                    {
                        l_213[2] |= p_43;
                        return l_198;
                    }
                    l_656 = ((0x5EL || (safe_lshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((0x746C22C4L && (safe_add_func_int16_t_s_s(((g_1217 , (safe_rshift_func_uint8_t_u_u(p_40, 6))) && (safe_add_func_uint8_t_u_u(p_42, (safe_lshift_func_int16_t_s_u((((safe_rshift_func_int8_t_s_s((safe_add_func_int8_t_s_s(((g_89 == (((safe_sub_func_uint32_t_u_u(((l_198 || 0x50L) | ((safe_sub_func_uint32_t_u_u((((l_213[2] == p_40) , l_616) >= g_2254), p_42)) == 0xFF3A24CFL)), 0x3913078BL)) >= p_40) , 1L)) != p_42), l_656)), l_656)) > g_2254) | (-6L)), 1))))), g_120[2]))), 0L)), 15))) != l_656);
                    for (g_1171 = 0; (g_1171 > 43); g_1171 = safe_add_func_uint8_t_u_u(g_1171, 2))
                    {
                        uint16_t l_236 = 1UL;
                        g_120[1] = 0x724D0293L;
                        l_236 = p_40;
                        l_262 = (safe_sub_func_int8_t_s_s((((((((p_40 || ((((1UL < ((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((((safe_mod_func_uint8_t_u_u(255UL, (safe_rshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s(((safe_sub_func_int8_t_s_s((safe_mod_func_int16_t_s_s(l_656, 65535UL)), l_198)) > ((safe_rshift_func_uint16_t_u_u(p_42, ((((safe_rshift_func_int16_t_s_u(((l_258 , (((safe_add_func_uint32_t_u_u(l_134, g_120[1])) == l_198) , l_236)) & l_258), p_42)) || g_97[2]) , g_89) , 0x2CA6L))) > 0x62L)), p_42)) | l_261), 0)))) | l_210) && l_656), 255UL)) | g_18), 11)) , g_1217)) || l_236) , 0x43L) | 1UL)) ^ p_42) , g_1168) < 0L) < l_656) != g_89) >= l_616), g_89));
                        g_100 = ((((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_u(((((((safe_add_func_uint16_t_u_u(l_616, g_2254)) == ((safe_mod_func_int32_t_s_s((((((safe_add_func_int16_t_s_s((safe_sub_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u(((((safe_sub_func_uint32_t_u_u(l_281[4][6], l_258)) ^ (((safe_add_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u((0x25D96900L <= (safe_sub_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s(l_236, g_1168)) < ((safe_lshift_func_int16_t_s_s(((0UL < (safe_mod_func_int8_t_s_s(g_1217, g_97[4]))) == g_120[2]), p_40)) < 7UL)), 2UL))), p_42)), 0x96E64D66L)) >= g_89), 0xFC6B1E59L)) < (-5L)) | 4294967292UL)) != l_656) ^ 8L), (-7L))) & p_43), l_656)) > l_236) <= (-1L)), p_42)), p_42)) >= l_134) ^ 0xF7BFL) , p_40) == l_198), g_2254)) && g_2431)) | 1UL) != 0x6CL) <= l_281[0][2]) , 0x35L), l_616)) && p_42), 4)) & l_134) < 0x73054497L) != g_2254);
                    }
                    for (g_1171 = 0; (g_1171 <= 4); g_1171 += 1)
                    {
                        int i;
                        g_120[g_1171] = ((safe_sub_func_int32_t_s_s(g_97[(g_1171 + 2)], (safe_unary_minus_func_uint8_t_u(((((safe_sub_func_int16_t_s_s(((g_97[g_1171] , 0xC6C2L) ^ 0xFEB2L), ((safe_rshift_func_uint16_t_u_u(g_97[(g_1171 + 1)], ((safe_rshift_func_uint16_t_u_u(g_120[g_1171], 5)) != (safe_mod_func_int8_t_s_s(((((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(g_120[g_1171], ((0x60L < g_120[g_1171]) , l_281[3][1]))), 0x2C0B2767L)) >= l_656) != p_40) != 255UL), 0xE6L))))) >= g_89))) != (-6L)) || g_120[0]) && g_97[(g_1171 + 2)]))))) & g_2254);
                        g_120[2] = ((-8L) == 0UL);
                        l_326 = ((((((((65535UL > (safe_mod_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((((l_262 || (l_198 || (safe_mod_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u((safe_rshift_func_int8_t_s_u(p_40, (((l_656 > (l_281[4][6] , p_42)) != ((safe_rshift_func_uint16_t_u_u(0xB25DL, 8)) || 1UL)) <= g_89))), g_2254)) | g_97[2]), 1)), g_2254)))) & p_42) || p_40), l_213[0])) & l_258), p_42))) <= p_40) < g_120[g_1171]) == 0x8B28L) < g_89) || l_213[2]) != p_40) <= 246UL);
                        l_262 |= (~g_120[1]);
                    }
                }
                for (l_616 = 20; (l_616 < 40); l_616 = safe_add_func_uint32_t_u_u(l_616, 1))
                {
                    int8_t l_362 = 0x43L;
                    int32_t l_366 = (-2L);
                    uint8_t l_369 = 0x5AL;
                    int32_t l_393 = 0L;
                    if ((safe_add_func_int16_t_s_s(((((l_213[1] || ((g_1217 >= (+(-1L))) >= (safe_lshift_func_int8_t_s_s(((safe_sub_func_int8_t_s_s((((safe_mod_func_int16_t_s_s(((safe_lshift_func_int16_t_s_s(l_616, 2)) == (((safe_lshift_func_uint16_t_u_s((g_2431 || ((safe_rshift_func_uint16_t_u_s((((safe_add_func_int16_t_s_s(((((((safe_mod_func_int16_t_s_s(p_43, g_1171)) <= 0x56719CF5L) < ((+(((((1UL && 0xD84E0731L) > l_281[6][4]) < l_134) > 0x15L) & 0xF7L)) | l_134)) , g_1217) == l_350) , l_656), 0xA7B5L)) , 2L) , g_935), 11)) >= g_2254)), l_210)) , 0x25L) < 7UL)), g_2431)) <= 1UL) , l_210), g_2431)) ^ 246UL), g_18)))) <= 0x83L) >= 6UL) & g_97[2]), l_656)))
                    {
                        uint32_t l_364 = 0UL;
                        int32_t l_365 = 1L;
                        l_364 = ((safe_add_func_int8_t_s_s((((safe_lshift_func_uint16_t_u_u(((((p_42 != g_100) > ((safe_lshift_func_uint16_t_u_u((0xA1L != (((-6L) && (((safe_rshift_func_int8_t_s_u(0x08L, ((p_43 < ((g_97[2] | (((safe_sub_func_uint16_t_u_u((((l_362 != 0xFEFA8AE2L) , g_2254) != g_97[2]), p_40)) && 0x6386802AL) >= g_97[1])) >= g_89)) , l_656))) < 2UL) && l_281[4][6])) != l_198)), 0)) ^ l_656)) != g_97[2]) || 0xF9L), l_363)) || 0xD2L) , g_1217), (-7L))) && g_1217);
                        ++l_369;
                        if (l_281[4][3])
                            break;
                        l_366 = l_656;
                    }
                    else
                    {
                        uint32_t l_384 = 0UL;
                        l_367 = (safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((p_42 , (safe_mod_func_int32_t_s_s((((((((((((p_40 , ((safe_mod_func_uint8_t_u_u((g_97[2] ^ (~(+g_100))), ((((g_97[3] & ((safe_sub_func_uint16_t_u_u((l_384 >= g_935), (((((((safe_lshift_func_int16_t_s_u((g_1217 || (((((safe_rshift_func_int16_t_s_u((1UL != p_43), 4)) , 0x8DL) >= g_89) , g_1217) , 0x343F8062L)), p_43)) > 4L) > g_1217) , g_120[1]) != p_40) , l_656) == 0xCB3F649DL))) | g_1217)) || g_89) | g_120[3]) && 0xE5L))) < 0UL)) >= g_97[1]) || 0x3F5AL) ^ l_261) || p_43) | l_366) , 0L) || (-1L)) ^ 0x8506B361L) >= p_42) ^ (-6L)), 0x3F0D7356L))), p_40)), g_1168));
                        g_1168--;
                    }
                    l_656 = (((((g_18 ^ (0UL & (((g_2431 == (safe_mod_func_uint8_t_u_u(((((safe_sub_func_int16_t_s_s(((l_656 & ((safe_add_func_int8_t_s_s((((safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((((safe_mod_func_uint32_t_u_u((safe_sub_func_int16_t_s_s((((g_2254 <= l_134) > (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(g_100, ((((((((safe_rshift_func_uint8_t_u_s(g_2254, 1)) & (((l_281[4][6] || g_1217) && g_1217) | 0UL)) == g_120[1]) || l_616) < l_326) < g_2254) || 0x3CL) < g_18))), 4))) >= (-1L)), g_935)), g_777)) || p_43) >= l_420), p_40)), g_89)) & (-1L)) | l_281[4][6]), 0x42L)) < g_97[3])) <= g_120[1]), g_120[3])) | g_1168) != 0L) == l_391[1][4]), l_395))) > 0x32L) || l_656))) ^ p_43) | l_656) < p_40) < 1UL);
                    for (g_1171 = 0; (g_1171 <= 4); g_1171 += 1)
                    {
                        int i;
                        return g_120[g_1171];
                    }
                    if (l_134)
                        break;
                }
                for (l_363 = 0; (l_363 == (-23)); --l_363)
                {
                    uint32_t l_461[2][4][5] = {{{0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}}, {{0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}}};
                    int i, j, k;
                    g_120[1] = ((0x7DDEF103L >= ((((safe_rshift_func_int16_t_s_u(((0x2CD8L == ((((((0x0CE5L > p_42) , (-9L)) || ((((safe_mod_func_uint32_t_u_u((g_120[1] > (0xD6FEED26L | ((l_427 >= (((((((safe_unary_minus_func_uint8_t_u(((safe_rshift_func_int8_t_s_s(g_97[1], 2)) != 0xEF0CL))) > 0x88D4L) && p_40) ^ g_120[1]) >= l_281[3][0]) | (-6L)) == 1L)) ^ 7UL))), 1UL)) < l_134) | p_40) , 0UL)) ^ (-1L)) | l_281[0][3]) == g_1168)) >= 0xBDE2D00BL), 7)) , 7L) > p_42) || l_420)) , g_777);
                    l_431--;
                    l_656 = (((safe_unary_minus_func_int16_t_s(((((safe_unary_minus_func_uint16_t_u((l_326 , (((((~(safe_add_func_uint8_t_u_u((l_427 == (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_s(((safe_sub_func_int16_t_s_s(g_120[2], (((safe_add_func_uint8_t_u_u(((p_43 || ((safe_mod_func_int16_t_s_s(((((l_395 & ((0xAD109901L < ((((safe_rshift_func_uint8_t_u_s(p_40, 7)) != (g_1217 <= (safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u((safe_sub_func_uint8_t_u_u(((((((((p_40 , 4UL) > 0UL) == 0xC8C73883L) <= l_427) ^ g_18) && l_616) || g_120[1]) & l_656), p_42)), l_461[1][1][2])), g_100)), p_40)))) <= l_461[1][1][2]) < 0x237EL)) <= 0x28L)) < 65535UL) | l_363) >= g_1217), l_213[4])) < 5UL)) ^ l_656), g_2431)) >= 0UL) | g_97[2]))) <= g_2431), g_120[1])) ^ p_40), 7))), g_1217))) < 1L) || g_89) ^ g_1168) , 6UL)))) | l_134) != g_1168) , l_656))) , 1UL) != 255UL);
                }
                g_120[1] ^= ((0L & 0x37L) >= (safe_sub_func_uint16_t_u_u(1UL, ((((safe_lshift_func_int8_t_s_u((g_97[3] >= (safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s(((((((safe_lshift_func_uint16_t_u_s(((((0xC0653759L ^ l_363) , g_1217) == (l_392 != l_656)) , 1UL), l_656)) , 4L) , g_1168) || 0x464EEE5AL) | 8UL) & g_2254), 5)) , 0x83F7DA68L) && g_18), 1UL))), 5)) <= g_1171) < 65531UL) || g_1168))));
            }
        };


                    continue;}
            }


if (g_2467)
                        break;

                    for (l_394 = 0; l_394 < 4; l_394++)
    {

{
                        if (g_2100)
                            break;
                        if (g_1482[2][1][1])
                            continue;
                    }

                    for (p_39 = 0; p_39 < 3; p_39++)
        {
            for (l_390 = 0; l_390 < 4; l_390++)
            {
                transparent_crc(g_1482[l_394][p_39][l_390], "g_1482[l_394][p_39][l_390]", g_2469);

{
                        int i;
                        l_102 = (safe_mod_func_int32_t_s_s(g_97[l_296], l_616));
                        l_296 = g_18;
                        g_935 &= 0xEC293C97L;
                    }

                    if (g_2469) printf("index = [%d][%d][%d]\n", l_394, p_39, l_390);

            }
        }
    };


                    for (g_89 = 0; (g_89 > (-19)); g_89 = safe_sub_func_uint16_t_u_u(g_89, 7))
            {
                uint8_t l_103[4] = {1UL, 0xABL, 1UL, 0xABL};
                int i;
                g_97[2] ^= p_43;
                for (g_22 = 1; (g_22 <= 6); g_22 += 1)
                {
                    int16_t l_110[7] = {0xD96CL, (-2L), 0xD96CL, (-2L), 0xD96CL, (-2L), 0xD96CL};
                    int8_t l_168 = 0xE9L;
                    int8_t l_181 = 0xCFL;
                    int i;

g_120[1] &= g_18;

                    for (p_40 = 6; (p_40 >= 1); p_40 -= 1)
                    {
                        int i;
                        p_39 = (safe_mod_func_int32_t_s_s(g_97[p_40], l_86));
                        g_100 = g_18;
                        g_101 &= 0xEC293C97L;
                    }

if (l_656) printf("index = [%d]\n", l_102);

                    l_103[3]++;

for (p_39 = 0; p_39 < 3; p_39++)
    {
        transparent_crc(g_1368[p_39], "g_1368[p_39]", l_390);
        if (l_390) printf("index = [%d]\n", p_39);

    };


                    if (((safe_rshift_func_int8_t_s_u((((((g_18 ^ ((safe_add_func_uint32_t_u_u((l_110[0] == (g_101 == (safe_mod_func_uint16_t_u_u(0UL, (((safe_unary_minus_func_uint16_t_u(g_89)) | (l_94[1] , ((safe_add_func_uint16_t_u_u(((((((safe_mod_func_int8_t_s_s(p_41, (safe_sub_func_uint8_t_u_u((g_120[1] > (l_102 | p_41)), p_41)))) ^ g_59) || 0x17461B67L) && g_97[2]) == 1L) , g_18), g_120[4])) , g_120[3]))) & g_89))))), g_101)) > 0x3AD0L)) & g_101) || p_40) != l_94[1]) == l_121), g_18)) <= (-9L)))
                    {
                        int8_t l_141 = (-10L);

if (l_472)
                            break;


for (p_39 = 0; p_39 < 3; p_39++)
                            g_1368[p_39] = 5L;

                    g_143 ^= (g_97[6] < (safe_mod_func_int16_t_s_s((((g_120[1] ^ ((safe_add_func_uint32_t_u_u(((g_101 <= ((safe_sub_func_uint8_t_u_u(l_103[1], (((((((safe_sub_func_uint16_t_u_u(((l_134 >= g_22) > 0UL), ((((((safe_sub_func_int32_t_s_s((((safe_add_func_uint8_t_u_u((((((((g_100 & (safe_lshift_func_uint8_t_u_u((l_94[0] <= l_110[0]), g_101))) || p_41) | 0xF7L) & l_141) , 0x6CL) | g_100) < l_94[1]), l_103[3])) >= l_86) > p_40), 1L)) || p_42) >= g_22) , l_86) > l_142) < g_22))) == l_102) , p_40) && 0x68L) && l_121) >= l_110[0]) ^ p_41))) != g_120[1])) != (-5L)), 0xB89AE2E4L)) > l_121)) > g_89) || 0x3285CC41L), g_97[2])));
                    }
                    else
                    {
                        int32_t l_167 = 0xBD733D80L;

if (l_121)
                    {
                        int32_t l_1928[10] = {0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L};
                        int i;
                        l_419--;
                    }
                    else
                    {
                        i = i;
                    };



l_419 += 1;


                    if (p_42)
                            break;
                        g_120[4] = (safe_rshift_func_int16_t_s_u((safe_lshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_s((safe_mod_func_uint8_t_u_u(((g_97[4] ^ (g_59 | (safe_lshift_func_int16_t_s_u((((safe_mod_func_int16_t_s_s(((safe_rshift_func_int8_t_s_u(2L, ((+(((p_40 , ((safe_rshift_func_uint8_t_u_s(((l_103[3] > ((((p_41 & 0x8D56L) > (safe_lshift_func_uint8_t_u_s((safe_add_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((65535UL ^ (4L >= (-10L))), g_120[0])), p_40)), p_39))) == 0xB673D79CL) ^ 1L)) | g_100), l_103[3])) <= l_102)) != (-8L)) < l_167)) | g_59))) , g_22), l_103[3])) ^ 0xBAC23114L) | l_110[0]), l_168)))) | p_40), (-2L))), 12)), 10)), g_100));
                        g_120[4] = ((((safe_add_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((safe_lshift_func_uint8_t_u_s(((255UL >= 254UL) < ((safe_mod_func_uint16_t_u_u(g_101, 65531UL)) || 0x8F5F89A5L)), (((((+(((((~p_42) & ((p_43 , l_168) < ((((((g_100 && p_40) && l_167) == p_40) , 6L) ^ g_143) , 0x9D48L))) < 0x5183DF78L) , l_142) & 1L)) != l_167) || l_181) || g_100) <= 4294967286UL))) || 0x76D7L), 1)), p_39)) || 0xFB851665L), 0x69F6L)) >= p_41) , 0xDEBA2DDDL) <= l_121);
                    }
                }

{
                        uint32_t l_1278 = 0x7A1781B4L;
                        l_121--;
                        l_1278--;
                    }

                    for (g_59 = 0; (g_59 != 33); g_59++)
                {
                    return p_41;
                }
                if (l_103[3])
                    break;
            }
        }
        for (p_42 = 0; (p_42 < (-17)); --p_42)
        {
            uint8_t l_198 = 1UL;
            int16_t l_261 = (-10L);
            uint16_t l_350 = 5UL;
            int32_t l_367 = 1L;
            int32_t l_391[3][6] = {{0xD2D39850L, 1L, 1L, 0L, 0L, 1L}, {0xD2D39850L, 1L, 1L, 0L, 0L, 1L}, {0xD2D39850L, 1L, 1L, 0L, 0L, 1L}};
            uint32_t l_431 = 0x13F79E03L;
            int i, j;
            if (l_121)
                break;
            p_39 ^= l_121;
            for (l_102 = 0; (l_102 == 26); ++l_102)
            {
                uint32_t l_210 = 0UL;
                int8_t l_281[8][7] = {{0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}};
                uint32_t l_326 = 0x0A0DE782L;
                int32_t l_363 = 0L;
                int32_t l_392 = (-1L);
                int32_t l_395 = 0L;
                const uint32_t l_420 = 0xA82EA14BL;
                const int16_t l_427 = 0L;
                int i, j;

l_102 &= (((l_261 < (safe_add_func_uint8_t_u_u(l_419, (((safe_unary_minus_func_int32_t_s(3L)) , 250UL) , (safe_sub_func_uint8_t_u_u((((p_42 == g_717) , ((l_326 > ((safe_lshift_func_int8_t_s_u(((safe_mod_func_uint32_t_u_u(((~((l_326 ^ g_849[0]) >= g_2414)) || l_326), (-6L))) ^ g_849[0]), l_419)) >= l_253)) | 0xA9A8L)) & (-8L)), l_213[5])))))) , 6UL) && g_120[1]);


for (l_86 = (-26); (l_86 <= 16); l_86++)
                    {
                        int8_t l_524 = (-8L);

for (l_395 = 0; l_395 < 6; l_395++)
    {
        for (l_656 = 0; l_656 < 2; l_656++)
        {
            transparent_crc(g_1540[l_395][l_656], "g_1540[l_395][l_656]", l_395);
            if (l_395) printf("index = [%d][%d]\n", l_395, l_656);

        }
    };


                    l_524 = g_100;
                        l_253 &= l_524;
                    };


                    if ((p_39 || (safe_mod_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_u(0x73L, 5)) | ((safe_mod_func_int32_t_s_s(g_59, (safe_rshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s((((0x7CB8L < 0xB2B8L) , ((l_198 ^ 0xDBL) != l_198)) && 0xD1L), l_86)), 11)))) != p_39)), 0xA615L))))
                {
                    uint32_t l_207 = 0x44D27D01L;
                    g_120[3] = p_42;


{
                        int i;
                        return g_120[l_121];
                    }

                    l_213[2] |= g_2414;

                    for (g_143 = (-26); (g_143 >= 44); g_143++)
                    {

{
        uint32_t l_83 = 0xB3DEF23EL;

for (l_616 = 20; (l_616 < 40); l_616 = safe_add_func_uint32_t_u_u(l_616, 1))
                {
                    int8_t l_362 = 0x43L;
                    int32_t l_366 = (-2L);
                    uint8_t l_369 = 0x5AL;
                    int32_t l_393 = 0L;
                    if ((safe_add_func_int16_t_s_s(((((l_213[1] || ((l_350 >= (+(-1L))) >= (safe_lshift_func_int8_t_s_s(((safe_sub_func_int8_t_s_s((((safe_mod_func_int16_t_s_s(((safe_lshift_func_int16_t_s_s(l_616, 2)) == (((safe_lshift_func_uint16_t_u_s((l_616 || ((safe_rshift_func_uint16_t_u_s((((safe_add_func_int16_t_s_s(((((((safe_mod_func_int16_t_s_s(p_43, l_616)) <= 0x56719CF5L) < ((+(((((1UL && 0xD84E0731L) > l_281[6][4]) < g_2467) > 0x15L) & 0xF7L)) | g_2467)) , l_350) == g_1217) , l_395), 0xA7B5L)) , 2L) , g_101), 11)) >= g_694)), g_143)) , 0x25L) < 7UL)), l_616)) <= 1UL) , g_143), l_616)) ^ 246UL), g_18)))) <= 0x83L) >= 6UL) & g_97[2]), l_395)))
                    {
                        uint32_t l_364 = 0UL;
                        int32_t l_365 = 1L;
                        l_364 = ((safe_add_func_int8_t_s_s((((safe_lshift_func_uint16_t_u_u(((((g_2254 != l_296) > ((safe_lshift_func_uint16_t_u_u((0xA1L != (((-6L) && (((safe_rshift_func_int8_t_s_u(0x08L, ((p_43 < ((g_97[2] | (((safe_sub_func_uint16_t_u_u((((l_362 != 0xFEFA8AE2L) , g_694) != g_97[2]), g_100)) && 0x6386802AL) >= g_97[1])) >= g_717)) , l_395))) < 2UL) && l_281[4][6])) != g_1171)), 0)) ^ l_395)) != g_97[2]) || 0xF9L), l_363)) || 0xD2L) , l_350), (-7L))) && l_350);
                        ++l_369;
                        if (l_281[4][3])
                            break;
                        l_366 = l_395;
                    }
                    else
                    {
                        uint32_t l_384 = 0UL;
                        l_394 = (safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((g_2254 , (safe_mod_func_int32_t_s_s((((((((((((g_89 , ((safe_mod_func_uint8_t_u_u((g_97[2] ^ (~(+l_296))), ((((g_97[3] & ((safe_sub_func_uint16_t_u_u((l_384 >= g_101), (((((((safe_lshift_func_int16_t_s_u((l_350 || (((((safe_rshift_func_int16_t_s_u((1UL != p_43), 4)) , 0x8DL) >= g_717) , g_1217) , 0x343F8062L)), p_43)) > 4L) > l_350) , g_120[1]) != g_89) , l_395) == 0xCB3F649DL))) | l_350)) || g_717) | g_120[3]) && 0xE5L))) < 0UL)) >= g_97[1]) || 0x3F5AL) ^ g_101) || p_43) | l_366) , 0L) || (-1L)) ^ 0x8506B361L) >= g_2254) ^ (-6L)), 0x3F0D7356L))), g_100)), l_431));
                        g_2467--;
                    }
                    l_395 = (((((g_18 ^ (0UL & (((l_616 == (safe_mod_func_uint8_t_u_u(((((safe_sub_func_int16_t_s_s(((l_395 & ((safe_add_func_int8_t_s_s((((safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((((safe_mod_func_uint32_t_u_u((safe_sub_func_int16_t_s_s((((g_694 <= g_2467) > (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(l_296, ((((((((safe_rshift_func_uint8_t_u_s(g_694, 1)) & (((l_281[4][6] || l_350) && l_350) | 0UL)) == g_120[1]) || l_616) < g_2467) < g_694) || 0x3CL) < g_18))), 4))) >= (-1L)), g_101)), l_419)) || p_43) >= l_420), g_100)), g_717)) & (-1L)) | l_281[4][6]), 0x42L)) < g_97[3])) <= g_120[1]), g_120[3])) | g_2467) != 0L) == l_391[1][4]), l_394))) > 0x32L) || i))) ^ p_43) | l_395) < g_89) < 1UL);
                    for (l_616 = 0; (l_616 <= 4); l_616 += 1)
                    {
                        int i;
                        return g_120[l_616];
                    }
                    if (g_2467)
                        break;
                };


                    j = j;
        g_717 = ((l_472 > ((((safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(l_616, (safe_rshift_func_uint16_t_u_s(0xA4A7L, (((l_83 ^ ((((g_2414 == ((safe_lshift_func_int16_t_s_u(((((g_59 || ((((g_717 <= (safe_sub_func_uint8_t_u_u(g_59, (g_18 ^ l_83)))) | 0x39L) <= g_2414) & 0x3186L)) <= g_22) , g_2414) & 1L), l_83)) ^ 65532UL)) & l_83) || 0x439AL) && 255UL)) == g_2414) != g_18))))), 5L)) >= l_616) == g_18) != l_472)) <= g_2414);

l_367 -= 1;


                    return g_717;
    }

                    return l_198;
                    }
                    g_120[1] = (((((((g_120[1] && g_101) || ((safe_rshift_func_uint16_t_u_u(((p_41 , ((safe_mod_func_uint32_t_u_u(((safe_mod_func_uint16_t_u_u(((((0x47C1L >= (g_89 ^ l_207)) <= (safe_sub_func_uint16_t_u_u(((g_18 && p_43) , l_121), l_121))) ^ g_120[1]) < g_120[0]), g_120[1])) & g_97[2]), 0x3A8961DAL)) & 0L)) , p_42), 4)) & g_120[1])) ^ p_39) == l_207) | l_210) & 0xD933A2BCL) & l_121);
                }
                else
                {
                    uint8_t l_258 = 0x75L;
                    int32_t l_262 = 0x18EC19C0L;
                    for (g_143 = (-24); (g_143 < 42); ++g_143)
                    {

{
                        int i;
                        g_120[l_616] = ((safe_sub_func_int32_t_s_s(g_97[(l_616 + 2)], (safe_unary_minus_func_uint8_t_u(((((safe_sub_func_int16_t_s_s(((g_97[l_616] , 0xC6C2L) ^ 0xFEB2L), ((safe_rshift_func_uint16_t_u_u(g_97[(l_616 + 1)], ((safe_rshift_func_uint16_t_u_u(g_120[l_616], 5)) != (safe_mod_func_int8_t_s_s(((((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(g_120[l_616], ((0x60L < g_120[l_616]) , l_281[3][1]))), 0x2C0B2767L)) >= l_395) != p_40) != 255UL), 0xE6L))))) >= p_40))) != (-6L)) || g_120[0]) && g_97[(l_616 + 2)]))))) & l_261);
                        g_120[2] = ((-8L) == 0UL);
                        g_1168 = ((((((((65535UL > (safe_mod_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((((l_363 || (l_616 || (safe_mod_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u((safe_rshift_func_int8_t_s_u(p_40, (((l_363 > (l_281[4][6] , l_261)) != ((safe_rshift_func_uint16_t_u_u(0xB25DL, 8)) || 1UL)) <= p_40))), l_261)) | g_97[2]), 1)), l_261)))) & l_261) || p_40), l_213[0])) & g_1171), l_261))) <= p_40) < g_120[l_616]) == 0x8B28L) < p_40) || l_213[2]) != p_40) <= 246UL);
                        l_363 |= (~g_120[1]);
                    }

                    l_213[2] |= p_43;
                        return l_198;
                    }
                    p_39 = ((0x5EL || (safe_lshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((0x746C22C4L && (safe_add_func_int16_t_s_s(((p_41 , (safe_rshift_func_uint8_t_u_u(g_100, 6))) && (safe_add_func_uint8_t_u_u(p_42, (safe_lshift_func_int16_t_s_u((((safe_rshift_func_int8_t_s_s((safe_add_func_int8_t_s_s(((g_89 == (((safe_sub_func_uint32_t_u_u(((l_198 || 0x50L) | ((safe_sub_func_uint32_t_u_u((((l_213[2] == p_40) , l_121) >= g_101), p_42)) == 0xFF3A24CFL)), 0x3913078BL)) >= p_40) , 1L)) != p_42), p_39)), p_39)) > g_101) | (-6L)), 1))))), g_120[2]))), 0L)), 15))) != p_39);
                    for (l_86 = 0; (l_86 > 43); l_86 = safe_add_func_uint8_t_u_u(l_86, 2))
                    {
                        uint16_t l_236 = 1UL;

{
    const int32_t l_1494 = 1L;
    int32_t l_1549 = 3L;
    int32_t l_1648 = (-7L);
    int32_t l_1651 = 0x03FC532BL;
    uint32_t l_1671 = 0x5D19C228L;
    int32_t l_1693 = 6L;
    int32_t l_1694 = 0x93E56D52L;
    int32_t l_1695 = (-8L);
    int32_t l_1696[1];
    int32_t l_1698 = 0x373FD168L;
    int16_t l_1726 = 0x18DBL;
    int8_t l_1888[4] = {(-1L), 0xDAL, (-1L), 0xDAL};
    const int32_t l_2028 = 0L;
    uint32_t l_2050 = 0xE1AEC0EFL;
    int32_t l_2055 = 0x3AFF1B97L;
    int32_t l_2141[2][9][9] = {{{(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}}, {{(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}}};
    int32_t l_2178[3];
    int16_t l_2182 = 0L;
    int32_t l_2325 = 0xDDB3E8D8L;
    uint32_t l_2326 = 4UL;
    int i, j, k;
    for (i = 0; i < 1; i++)
        l_1696[i] = (-1L);
    for (i = 0; i < 3; i++)
        {
{
                        int i;
                        if (g_120[g_717])
                            break;

if (l_1671)
                break;

                    if (l_1888[g_717])
                            break;
                        return l_261;
                    }

                    l_2178[i] = 0xA248903FL;}
    for (p_40 = (-17); (p_40 != (-29)); p_40--)
    {
        int32_t l_1489[4][8][8] = {{{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}, {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}, {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}, {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}};
        uint32_t l_1504 = 0x5BA9BBE8L;
        uint8_t l_1505 = 0xECL;
        int32_t l_1537 = 0L;
        int32_t l_1639 = (-1L);
        int32_t l_1644[7][7][5] = {{{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}};
        int32_t l_1705 = 0x5B922F92L;
        const int32_t l_1724 = (-1L);
        int8_t l_1725 = (-7L);
        uint16_t l_1799[5][6];
        int32_t l_1842 = 1L;
        int8_t l_1854 = 1L;
        uint32_t l_1887 = 0x40D66011L;
        uint32_t l_1905 = 5UL;
        int8_t l_1931[6] = {(-1L), (-1L), 1L, (-1L), (-1L), 1L};
        uint8_t l_2006 = 255UL;
        int i, j, k;
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 6; j++)
                l_1799[i][j] = 65535UL;
        }
        l_1489[2][4][7] |= (safe_rshift_func_uint16_t_u_s(l_351, (safe_add_func_int8_t_s_s(0x34L, 0x31L))));
        g_120[2] = (((((((safe_add_func_int16_t_s_s((((l_258 , 0xE95DL) != ((((safe_rshift_func_uint8_t_u_s((l_1489[3][4][7] > 0x91L), 3)) & ((l_1494 >= (((safe_lshift_func_uint8_t_u_s(g_18, 5)) & (((safe_sub_func_uint16_t_u_u((l_1494 | (((safe_sub_func_uint8_t_u_u((((safe_sub_func_int8_t_s_s((((l_1489[2][4][7] == (+(((g_59 || l_258) ^ p_39) < l_1504))) > 8UL) != 4294967286UL), 0xBAL)) != l_419) , 246UL), g_1482[2][0][1])) ^ l_1504) > p_39)), g_1368[0])) ^ l_1504) <= 4294967295UL)) && 0x59L)) < l_1489[0][5][2])) , (-10L)) & 0xF980F758L)) ^ g_2467), l_198)) == 1UL) >= g_97[3]) > l_1504) > p_39) > l_1505) >= l_258);
        if (l_1494)
            break;
        for (l_389 = (-15); (l_389 != 6); l_389++)
        {
            const uint32_t l_1522[6][9] = {{0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}};
            uint16_t l_1591 = 7UL;
            int32_t l_1599 = 0x10CC3626L;
            int16_t l_1633 = 0x164AL;
            int32_t l_1634 = 0x157EBADBL;
            int32_t l_1643[6][4][8] = {{{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}};
            uint32_t l_1659 = 0x83EA5D3CL;
            uint32_t l_1699 = 0x2C42C799L;
            uint16_t l_1706 = 0x0899L;
            int32_t l_1806 = 0x9CB7724BL;
            uint32_t l_1837 = 3UL;
            uint32_t l_1846 = 0xD008E7A8L;
            int i, j, k;
            if (((!(safe_add_func_int32_t_s_s((l_419 || l_419), ((((safe_lshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s((0x15L <= (l_198 <= ((safe_add_func_uint16_t_u_u((!g_849[0]), ((((safe_sub_func_int32_t_s_s(((((l_258 , ((l_258 | ((((((safe_sub_func_uint8_t_u_u((g_1368[1] <= l_1489[2][7][0]), (-1L))) ^ l_261) | g_143) , 255UL) , l_419) < g_120[0])) < l_258)) ^ l_1494) , l_1522[4][1]) < g_935), 4294967295UL)) != 0x6AL) || g_18) >= l_419))) < l_1505))), p_40)) , 0x5997L), l_419)) <= p_40) , l_1522[0][5]) <= p_39)))) == l_1522[4][1]))
            {
                uint32_t l_1543 = 7UL;
                int32_t l_1547 = (-6L);
                int32_t l_1640 = 0x4E27C546L;
                int32_t l_1641 = 1L;
                int32_t l_1646 = 0xFBA92B18L;
                int32_t l_1647 = 0xBA2A75F3L;
                int32_t l_1649 = 0L;
                int32_t l_1650 = (-1L);
                int32_t l_1652 = (-1L);
                int32_t l_1654 = (-5L);
                int32_t l_1655 = 0L;
                int32_t l_1697 = 0L;

{
            const uint32_t l_1522[6][9] = {{0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}};
            uint16_t l_1591 = 7UL;
            int32_t l_1599 = 0x10CC3626L;
            int16_t l_1633 = 0x164AL;
            int32_t l_1634 = 0x157EBADBL;
            int32_t l_1643[6][4][8] = {{{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}};
            uint32_t l_1659 = 0x83EA5D3CL;
            uint32_t l_1699 = 0x2C42C799L;
            uint16_t l_1706 = 0x0899L;
            int32_t l_1806 = 0x9CB7724BL;
            uint32_t l_1837 = 3UL;
            uint32_t l_1846 = 0xD008E7A8L;
            int i, j, k;
            if (((!(safe_add_func_int32_t_s_s((g_143 || g_143), ((((safe_lshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s((0x15L <= (l_86 <= ((safe_add_func_uint16_t_u_u((!g_849[0]), ((((safe_sub_func_int32_t_s_s(((((l_2006 , ((l_2006 | ((((((safe_sub_func_uint8_t_u_u((g_1368[1] <= l_1489[2][7][0]), (-1L))) ^ l_261) | l_1837) , 255UL) , g_143) < g_120[0])) < l_2006)) ^ l_2028) , l_1522[4][1]) < p_42), 4294967295UL)) != 0x6AL) || g_18) >= g_143))) < l_613))), l_296)) , 0x5997L), g_143)) <= l_296) , l_1522[0][5]) <= p_39)))) == l_1522[4][1]))
            {
                uint32_t l_1543 = 7UL;
                int32_t l_1547 = (-6L);
                int32_t l_1640 = 0x4E27C546L;
                int32_t l_1641 = 1L;
                int32_t l_1646 = 0xFBA92B18L;
                int32_t l_1647 = 0xBA2A75F3L;
                int32_t l_1649 = 0L;
                int32_t l_1650 = (-1L);
                int32_t l_1652 = (-1L);
                int32_t l_1654 = (-5L);
                int32_t l_1655 = 0L;
                int32_t l_1697 = 0L;
                for (g_143 = 5; (g_143 != 57); ++g_143)
                {
                    int32_t l_1533[2][4] = {{0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}, {0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}};
                    int32_t l_1542[8][7][3] = {{{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}};
                    int i, j, k;
                    if (((0UL <= (safe_rshift_func_int8_t_s_u(l_2006, 5))) & (((((((p_39 , ((safe_add_func_int32_t_s_s(0L, (safe_mod_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((((p_39 == l_1533[1][2]) && (((g_143 && ((l_1489[3][7][5] & 0x189D8138L) & p_42)) ^ g_97[2]) | l_613)) <= (-6L)), 12)), 0x4AL)))) & l_613)) <= l_2006) == 1L) || l_2028) | l_2028) > 0xA7L) & 1L)))
                    {
                        l_1537 &= ((safe_rshift_func_uint8_t_u_s((((p_39 ^ (~((g_97[2] == p_39) , l_389))) | (l_1522[2][7] | (((l_699 || l_613) , (((0x07L == (-1L)) < 0xBECEL) || l_1533[1][2])) ^ g_97[1]))) , 255UL), 1)) && (-1L));
                        g_120[2] = (safe_add_func_int32_t_s_s(l_699, g_1368[1]));
                        g_120[1] = g_1540[1][0];
                    }
                    else
                    {
                        int8_t l_1541 = (-1L);
                        int32_t l_1546 = 0x3C02C0E7L;
                        uint32_t l_1550 = 1UL;
                        l_1543++;
                        if (l_1489[0][4][1])
                            continue;
                        --l_1550;
                    }
                    for (l_1537 = 10; (l_1537 >= 5); l_1537 = safe_sub_func_uint32_t_u_u(l_1537, 6))
                    {
                        int16_t l_1581 = 0x4CE7L;
                        if (g_143)
                            break;
                        g_120[1] = (l_253 || (0xA427L == (safe_mod_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((g_1368[1] == 1UL), (-1L))), 0x2E3AL))));
                        g_120[1] = ((+(l_2006 < ((((((safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((~l_261), ((safe_lshift_func_int8_t_s_s(l_1547, (safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((+((safe_add_func_int8_t_s_s((0UL != (((safe_rshift_func_int8_t_s_u((l_699 > g_1368[2]), 1)) == (safe_unary_minus_func_int8_t_s((g_143 , (safe_rshift_func_uint8_t_u_s((((safe_mod_func_int8_t_s_s((0x71L >= l_1581), 0xB6L)) , g_143) <= p_39), 3)))))) && l_1837)), 0UL)) ^ l_1522[0][5])) & 1UL), g_143)), 13)))) , 0x89L))), l_2006)) != l_1537) , l_389) || 65531UL) > p_39) < 0x33D41A9EL))) , g_59);
                    }
                    for (p_42 = 0; (p_42 <= 4); p_42 += 1)
                    {
                        int16_t l_1588[5][10][5] = {{{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}};
                        const int16_t l_1592 = (-1L);
                        int i, j, k;
                        g_120[p_42] = ((safe_sub_func_int32_t_s_s(l_261, 0xC58F4B07L)) ^ ((((((-1L) > (((((safe_add_func_int8_t_s_s(((((safe_sub_func_uint32_t_u_u(((l_1588[4][3][4] | (0xBBL | g_97[2])) ^ l_1542[2][5][1]), (l_2006 , (safe_lshift_func_uint16_t_u_u(((0x8B2D6D5DL < (-6L)) < 0x8664AFBBL), 8))))) & g_143) > 7L) >= l_1591), l_1588[1][8][4])) && g_143) == 1UL) , l_1592) && g_97[2])) || l_296) <= g_143) || l_389) >= l_1533[1][2]));
                        return l_253;
                    }
                }
                if ((((safe_rshift_func_uint8_t_u_s(l_253, 4)) >= (safe_lshift_func_uint8_t_u_s(l_1591, (safe_lshift_func_int8_t_s_s(l_1599, 1))))) != ((safe_lshift_func_int16_t_s_u((!(((l_2006 >= l_1547) , ((!g_849[0]) >= ((l_699 <= (!(((safe_rshift_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_u((((p_42 > 0L) ^ p_39) < l_1504), l_2006)) || 0x729EL) > 0xD46FL), 2)) < g_97[2]) , 6UL))) || l_2006))) | l_1489[2][4][7])), 12)) == l_2006)))
                {
                    uint16_t l_1611 = 0xD966L;
                    int32_t l_1636 = 1L;
                    int32_t l_1638[4][6][7] = {{{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}};
                    uint8_t l_1656[3][8][6] = {{{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}};
                    int i, j, k;
                    g_120[1] = ((((g_143 & ((safe_mul_func_uint8_t_u_u(l_1611, ((((l_2028 | (safe_mod_func_int8_t_s_s(p_39, (safe_lshift_func_uint16_t_u_u((((((((+(l_2028 , ((l_1504 & (safe_lshift_func_uint16_t_u_s((((+(((((((g_694 <= (((((p_39 & ((0x4BA9L | 0xAB14L) == 0xB0E53EB1L)) == 0x49L) >= l_396) && p_39) < l_1611)) > 0x891AL) ^ 0xC4L) >= l_2326) > l_1599) ^ g_849[0]) < l_1591)) & 0x2C1DL) >= 0L), 14))) , l_396))) & l_261) != 0x3AL) , l_2006) && l_296) ^ p_39) >= l_2006), 1))))) && g_143) >= l_1522[4][1]) <= 0x012802EEL))) ^ 0x6FL)) | l_2006) != 4294967290UL) | g_120[4]);
                    if ((l_1489[2][4][7] <= (g_97[0] <= l_2028)))
                    {
                        int32_t l_1635 = 0L;
                        int32_t l_1637 = 1L;
                        int32_t l_1642 = (-3L);
                        int32_t l_1645[4][10][3] = {{{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}};
                        int8_t l_1653 = 0xE0L;
                        int i, j, k;
                        l_1634 = (((((safe_mod_func_uint16_t_u_u((safe_unary_minus_func_uint8_t_u((safe_sub_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((p_39 ^ (((((safe_mod_func_uint8_t_u_u(((((safe_add_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(((g_143 && (((l_2006 , l_2028) > (p_39 & l_396)) >= (-2L))) == ((-1L) & ((0x2C2C4A06L || 0L) != l_296))), 0x84D0E611L)) < 247UL), l_1537)) == g_1540[0][1]) != 65535UL) != (-5L)), l_1599)) , l_1837) , l_1611) == l_2006) && 9L)) >= 0x3E95L), p_39)), g_143)))), 65530UL)) >= l_253) | 0xA236F820L) , l_1611) < l_1633);
                        l_1656[1][6][4]++;
                        ++l_1659;
                    }
                    else
                    {
                        int32_t l_1692 = 1L;
                        l_1837 = (((safe_mod_func_uint16_t_u_u((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u((((l_253 , ((((l_2182 != l_1611) >= (safe_sub_func_uint8_t_u_u(0xEEL, g_849[0]))) <= l_396) != (1UL & l_2006))) && (!(l_253 >= l_1644[2][1][0]))) || l_1641), (-2L))), 1UL)), g_120[1])) > 0x1BL) | 0xC3L);
                        g_120[1] = (+1UL);
                        l_1643[3][1][5] = (safe_add_func_uint32_t_u_u(0UL, (((safe_rshift_func_uint16_t_u_u(((safe_mod_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((~p_39), ((0x60L ^ ((l_253 == ((((((-1L) == ((0x4B8FL == (l_2006 | (((6L | (safe_rshift_func_uint16_t_u_u(((((((((safe_lshift_func_int8_t_s_u(((~(((((safe_mod_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(((!(1UL != l_699)) > l_1522[2][7]), g_120[1])), l_1638[0][0][2])) < 4294967295UL) , g_143) , 0xE3L) , 0x49L)) && 0x109AL), 6)) , p_42) || 4294967288UL) < 0x758ECAE5L) , g_143) > l_1692) != g_120[4]) == 0x90143625L), g_120[0]))) != l_2006) | g_18))) | (-1L))) > g_143) > g_694) , g_143) != g_143)) < l_1692)) < g_18))), l_2006)) | 0x4510FC82L), l_2326)) > 2UL) != l_1643[0][3][1])));
                    }
                }
                else
                {
                    g_120[4] = g_143;
                    if (l_1837)
                        break;
                }
                ++l_1699;
            }
            else
            {
                int8_t l_1702[4] = {0x92L, 1L, 0x92L, 1L};
                int32_t l_1703 = (-7L);
                int32_t l_1704[7][6][6] = {{{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}};
                uint8_t l_1730[3][2];
                uint32_t l_1764 = 0x54F33472L;
                int i, j, k;
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 2; j++)
                        l_1730[i][j] = 0x7BL;
                }
                g_120[2] = g_1548[4][6][2];
                --l_1706;
                if ((((l_296 < ((safe_sub_func_int8_t_s_s(g_1540[1][0], (((((((1L | (l_1643[4][0][3] != ((safe_sub_func_int16_t_s_s(((safe_sub_func_int32_t_s_s(g_1548[9][3][2], (((((safe_add_func_uint16_t_u_u((!l_1699), g_120[0])) != ((safe_sub_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u((0UL != ((l_2006 > l_1547) , l_1837)), 6)), l_1703)), l_2028)) < 255UL)) , l_1537) == g_717) < l_1489[2][4][7]))) > l_1726), (-10L))) == p_39))) , 0x853A9528L) != 1UL) , l_1706) >= 0x1C39L) == 0xF5678FABL) , 0xD3L))) < 0x7EB415D5L)) != l_1837) || 4294967289UL))
                {
                    int32_t l_1727 = 0L;
                    int32_t l_1728 = 4L;
                    int32_t l_1729[4][6][7] = {{{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}};
                    int i, j, k;
                    --l_1730[2][0];
                }
                else
                {
                    uint16_t l_1751 = 0UL;
                    for (l_699 = 0; (l_699 <= 3); l_699 += 1)
                    {
                        int i, j, k;
                        l_1644[l_699][l_699][l_699] ^= (safe_lshift_func_uint8_t_u_u((l_1489[l_699][(l_699 + 2)][l_699] >= (safe_add_func_int32_t_s_s(0x76753DFBL, ((safe_rshift_func_uint8_t_u_s((safe_mod_func_int16_t_s_s(5L, (safe_lshift_func_int16_t_s_u((((safe_lshift_func_uint16_t_u_u(g_1482[2][1][1], 6)) < ((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(0xAAD7L, (((safe_add_func_int32_t_s_s((l_1751 && (((safe_add_func_uint8_t_u_u((((((~(l_1693 , (((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s((g_1368[1] || (((((+(safe_lshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u(l_253, 9UL)), p_42))) , p_39) , l_296) != 0xB3L) > p_39)), 6L)), 0x65A1L)) != 65533UL) >= l_1751))) >= l_1764) | l_1730[2][0]) , l_1751) , l_1751), 0UL)) <= g_1548[5][0][1]) && 255UL)), l_2326)) ^ l_296) >= g_97[2]))), l_2006)) , g_143)) | l_1751), l_1547)))), l_1751)) & g_143)))), l_2326));
                    }
                    l_253 = (l_1489[3][7][7] > ((g_1548[4][6][2] ^ (!((((((safe_rshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s(0x2D2C9E59L, (l_1764 | (safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(((((((l_1751 == ((p_39 == (safe_sub_func_uint16_t_u_u(((((l_1837 & (safe_add_func_uint16_t_u_u((0L > ((((g_59 && l_1702[3]) >= l_2006) & 0x3E3BL) , l_1730[2][0])), g_120[1]))) , 8L) , 0L) & l_1659), g_143))) || l_1764)) >= l_2326) == l_1643[2][2][1]) == 0x34FBL) | 0x6190L) | l_2006), l_2006)) >= p_39), l_2006)) < 0x90L), l_1837)) & 0x68AFL), l_296)) , g_694), l_296))))), l_2028)), l_2006)) || 4294967286UL), 13)) <= l_2006) ^ 1L) , l_296) <= l_1751) & 0xABL))) | l_1706));
                    l_1643[0][3][1] ^= l_1751;
                }
                return l_2006;
            }
            for (l_1634 = 0; (l_1634 >= 17); l_1634 = safe_add_func_int16_t_s_s(l_1634, 4))
            {
                const uint32_t l_1798[7][8] = {{0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}};
                int i, j;
                l_1799[1][5] = ((6L ^ (safe_rshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s(((((((l_389 ^ (((0L >= (((safe_lshift_func_uint8_t_u_u(0x33L, g_143)) ^ l_1699) , (safe_lshift_func_int8_t_s_s(g_694, 1)))) == ((((l_1489[2][4][7] , (l_1798[3][0] && l_392)) & 1UL) & g_1540[0][1]) & g_849[0])) >= g_1368[2])) || 2L) , g_120[1]) | 9UL) , g_1548[1][1][0]) && 1UL), l_1699)), 0))) >= 0x9FEE1EABL);
            }
            g_120[1] |= (((g_849[0] <= (safe_add_func_int32_t_s_s(g_143, g_143))) <= ((((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u((p_39 && ((g_143 == l_1806) > ((safe_rshift_func_int16_t_s_u(((((((g_97[2] | l_2006) && ((!((safe_rshift_func_int16_t_s_s(((0L | l_253) , p_39), l_2326)) ^ l_1547)) ^ 0L)) == l_2006) , 1L) || 0xE5L) <= g_59), 15)) || l_1806))), 3)) > l_261) ^ g_143), l_396)) ^ g_1368[1]) || 1L) != (-5L)) , 4294967290UL) <= g_143)) ^ 0x02D0829CL);
            if ((safe_lshift_func_int8_t_s_s(0xBCL, 7)))
            {
                int8_t l_1831 = (-6L);
                int32_t l_1849[6] = {(-1L), 6L, (-1L), 6L, (-1L), 6L};
                const uint8_t l_1889 = 252UL;
                int i;
                for (l_1706 = 0; (l_1706 >= 36); l_1706 = safe_add_func_uint32_t_u_u(l_1706, 3))
                {
                    int32_t l_1836[9][5] = {{(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}};
                    int32_t l_1841 = (-3L);
                    int32_t l_1844 = 8L;
                    int32_t l_1845 = 0xBE0388A2L;
                    int16_t l_1853 = 0xBF53L;
                    uint16_t l_1856 = 0x14A1L;
                    int i, j;
                    g_120[4] ^= (((safe_add_func_uint32_t_u_u((0x22L == (((((l_1537 , (((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((~((((((g_1368[2] >= ((0xEF5AL != (safe_sub_func_int8_t_s_s(((g_1482[2][1][1] && ((safe_add_func_int8_t_s_s((((safe_sub_func_uint16_t_u_u(((((l_1831 | (((l_2006 > g_1540[1][0]) >= (((safe_rshift_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((g_1368[2] > 0x5C49CB64L), 5)) | l_1831) , l_1836[4][3]) == g_1368[1]) && g_59), g_694)) >= 0x624C7317L) == p_39)) <= l_2006)) , l_2006) , 1UL) , g_849[0]), 0xF010L)) ^ 0UL) <= g_849[0]), g_694)) > 1L)) & l_1547), p_39))) == 0xE4B6B42FL)) | l_1799[2][5]) , 0L) >= l_389) & l_1699) , l_1489[0][3][5])), 10)), g_143)) == g_97[2]) >= g_143)) || l_261) , l_1831) == p_39) ^ g_849[0])), l_2006)) | l_1837) , l_2028);
                    for (l_86 = 13; (l_86 >= 1); l_86 = safe_sub_func_int32_t_s_s(l_86, 9))
                    {
                        uint8_t l_1840 = 0x4FL;
                        int32_t l_1843 = 1L;
                        int32_t l_1850 = (-10L);
                        int32_t l_1851 = 0x86429966L;
                        int32_t l_1852 = 0xCA3D88B8L;
                        int32_t l_1855 = 1L;
                        l_1840 = l_389;
                        --l_1846;
                        --l_1856;
                    }
                    for (l_1841 = (-19); (l_1841 != (-8)); l_1841++)
                    {
                        uint16_t l_1886[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_1886[i] = 7UL;
                        g_120[1] &= l_1696[0];
                        g_120[0] = (((((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u(65535UL, 13)) , 0x9426L), (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_u(p_39, (((((0xEF2D849BL || l_1591) & (l_1841 , (safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u((((((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s(l_2326, (safe_rshift_func_uint16_t_u_s((((l_1799[1][5] > (safe_add_func_uint16_t_u_u(0x2E1AL, 0xBDC1L))) >= l_1836[0][4]) == l_1886[0]), 13)))) | (-2L)), l_326)) & l_2006) < 0xBEL) < l_1837) & l_1888[2]), 0x66L)), g_143)), 4)), 7)), 0UL)))) , 1UL) ^ l_1889) == 0xEAL))))))) > 0x483D69BBL) , l_1844) , 247UL) ^ l_1706);
                        l_1644[0][3][4] = ((((-2L) == (safe_add_func_uint16_t_u_u((((((((((safe_add_func_int32_t_s_s(((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s((safe_mod_func_int8_t_s_s((251UL != ((!l_419) == (((g_97[1] | (safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s(0xF54AL, 2)) && ((((g_143 > ((((l_1853 & (safe_add_func_uint16_t_u_u(0x3ED4L, 1L))) ^ p_39) | 1L) ^ l_1849[1])) > (-1L)) && l_261) != 0UL)), 0xEB10B25CL)), 10))) < g_1482[2][1][1]) || 0x405D3F2AL))), l_1599)), 1)), 2)) && l_389), 5)) && 4294967295UL), 4294967293UL)) , p_39), 4294967288UL)) | l_2006) || l_2006) && l_1640) && p_39) && 0x068C0922L) , l_86) , (-1L)) < g_143), 1UL))) ^ l_1846) || l_1699);
                        l_392 = (safe_lshift_func_uint8_t_u_s(l_2006, ((safe_rshift_func_int8_t_s_s(9L, g_694)) != l_1846)));
                    }
                }
                g_120[1] ^= ((l_2006 & (0x8889L >= (p_39 == ((safe_unary_minus_func_uint8_t_u(0UL)) <= (safe_mod_func_int16_t_s_s(g_1482[3][0][1], ((p_39 > (((~g_143) && ((~(!((((safe_sub_func_uint16_t_u_u((((((((l_2006 < ((((p_39 , p_39) >= 0x93L) , 1UL) ^ l_296)) ^ g_143) == l_1889) & 0UL) , l_296) < l_1799[4][4]) < 4294967295UL), l_1849[0])) <= 1L) , l_2006) , 0x3CL))) , g_143)) >= 7L)) & l_1537))))))) | l_1831);
                l_1643[0][3][1] = (l_86 > 0x5B7FL);
            }
            else
            {
                uint32_t l_1932 = 1UL;
                int32_t l_1945 = 0L;
                int32_t l_1946[1];
                uint32_t l_1971 = 0x9EF11B35L;
                uint8_t l_1990 = 0xB6L;
                int i;
                for (i = 0; i < 1; i++)
                    l_1946[i] = 3L;
                for (l_261 = (-11); (l_261 < (-24)); --l_261)
                {
                    int32_t l_1929 = 0L;
                    int32_t l_1930 = 0x01C56913L;
                    uint8_t l_1949 = 0xBEL;
                    int32_t l_2005 = 0L;
                    if (l_2006)
                    {
                        int32_t l_1928[10] = {0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L};
                        int i;
                        l_1932--;
                    }
                    else
                    {
                        l_392 = p_39;
                    }
                    if ((l_2006 , l_1697))
                    {
                        int8_t l_1947 = 0x1BL;
                        int32_t l_1948 = 0x27F08C10L;
                        l_1945 = (((0x03L == (0xA11DL < (g_59 | ((((0x6F1BL != l_2182) < (((((((((safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(g_97[2], l_86)), 2)) > (safe_add_func_uint16_t_u_u(g_1548[4][6][2], 0x34DEL))) & g_143), l_1706)) , 0x3208L) , g_1540[1][0]) , l_1930) == l_261) , g_1548[0][0][1]) <= l_1932) > g_143) >= 0UL)) < g_143) >= p_39)))) ^ g_97[2]) , g_849[0]);
                        ++l_1949;
                        g_120[4] = (safe_mod_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(6L, (safe_sub_func_uint8_t_u_u(0x94L, (((l_1949 | (safe_rshift_func_int8_t_s_u(((((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((((+(safe_add_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(((0xB3EFL || (l_1947 | (((g_120[1] ^ ((((-2L) & (((g_143 ^ (l_1945 , 0x78L)) , l_1971) < p_39)) < 0xA9FBL) == p_39)) < l_1806) < 0xE1L))) && l_1948), 0x64L)) , p_39), 9UL))) >= 0x60B3L) != p_39) ^ p_39), l_2006)), 0x0DAEL)), l_326)) >= l_1947) > p_39) == g_143), l_1948))) , 5L) | 0xB082A17BL))))) , 0x11L), 0x03L));
                    }
                    else
                    {
                        l_1930 = ((0L & p_39) != (!((safe_mod_func_uint8_t_u_u(l_2006, 0x7AL)) > (((l_1932 | p_39) , 0x1F0EL) < (g_143 && ((((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u(g_100, g_143)), 0x3929L)) != 0L) == 0x2F747C30L) , 0x96347F98L))))));
                    }
                    if (((safe_lshift_func_uint16_t_u_s((g_1540[1][0] , l_1930), g_143)) & (((l_2182 < (((((safe_lshift_func_int16_t_s_u(((p_39 , ((g_143 && (((safe_unary_minus_func_int16_t_s(((safe_add_func_uint16_t_u_u(l_392, ((((safe_add_func_uint16_t_u_u((l_1591 ^ p_39), l_1990)) < g_143) < 0x1D1DL) | g_694))) | g_120[1]))) , p_39) && l_1643[1][1][6])) ^ l_699)) , p_39), l_1599)) | g_143) <= 0UL) != (-8L)) , p_39)) < l_1547) || 0x837FL)))
                    {
                        int8_t l_2002 = 0x5BL;
                        int32_t l_2004[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_2004[i] = 7L;
                        l_1931[0] |= (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u(g_1482[0][1][0], ((~((((-6L) < g_143) >= g_120[1]) | (g_143 , g_143))) != (((safe_lshift_func_uint16_t_u_s(((g_1548[4][6][2] || ((((safe_rshift_func_int8_t_s_s(1L, 4)) <= 0xC812E52FL) || g_1368[1]) <= 0UL)) , l_1888[1]), 3)) != p_39) < 65535UL)))) | g_1482[2][1][1]) <= 4294967292UL) && l_1929) > l_2002), g_849[0])), l_2006));
                        l_616--;
                        if (l_1888[1])
                            break;
                    }
                    else
                    {
                        uint8_t l_2013[2][2] = {{1UL, 0x0EL}, {1UL, 0x0EL}};
                        int i, j;
                        g_120[1] = (safe_rshift_func_int16_t_s_u((((safe_sub_func_uint8_t_u_u((0xBC96E130L > l_2013[1][0]), ((safe_add_func_uint8_t_u_u(((l_2005 >= (((safe_add_func_uint8_t_u_u((((g_717 & l_2013[0][1]) , ((safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(g_1548[4][6][2], l_1932)) , ((safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((g_143 ^ ((safe_mod_func_uint16_t_u_u((65534UL <= l_253), g_143)) , g_120[3])) || l_1591), g_97[1])) > l_1837), (-4L))) > 7L)), l_1949)) == l_1888[2])) < l_2006), 9UL)) | g_1368[1]) & l_1640)) <= l_1930), 0x27L)) & 9UL))) && l_2006) , 0x1E18L), g_18));
                    }
                    g_120[1] = ((((0UL == (0x99L == g_1482[2][1][1])) , l_2028) , g_97[2]) > ((g_120[3] > ((((((safe_lshift_func_uint16_t_u_s(((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s(((0x83922D4EL != ((-8L) > 0x08L)) || l_1634), 5)), l_1837)) >= l_1634), 15)) < p_39) , 0xAC9FE61AL) , p_39) > g_143) | g_1540[1][0])) ^ (-1L)));
                }
            }
        }

                    for (l_419 = 5; (l_419 != 57); ++l_419)
                {
                    int32_t l_1533[2][4] = {{0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}, {0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}};
                    int32_t l_1542[8][7][3] = {{{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}};
                    int i, j, k;
                    if (((0UL <= (safe_rshift_func_int8_t_s_u(l_258, 5))) & (((((((p_39 , ((safe_add_func_int32_t_s_s(0L, (safe_mod_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((((p_39 == l_1533[1][2]) && (((l_419 && ((l_1489[3][7][5] & 0x189D8138L) & g_935)) ^ g_97[2]) | l_1505)) <= (-6L)), 12)), 0x4AL)))) & l_1505)) <= l_258) == 1L) || l_1494) | l_1494) > 0xA7L) & 1L)))
                    {

l_198 += 1;


                    l_1537 &= ((safe_rshift_func_uint8_t_u_s((((p_39 ^ (~((g_97[2] == p_39) , l_389))) | (l_1522[2][7] | (((l_699 || l_1505) , (((0x07L == (-1L)) < 0xBECEL) || l_1533[1][2])) ^ g_97[1]))) , 255UL), 1)) && (-1L));
                        g_120[2] = (safe_add_func_int32_t_s_s(l_699, g_1368[1]));

for (l_394 = 0; l_394 < 3; l_394++)
            g_1368[l_394] = 0x4EA06463L;

                    g_120[1] = g_1540[1][0];
                    }
                    else
                    {
                        int8_t l_1541 = (-1L);
                        int32_t l_1546 = 0x3C02C0E7L;
                        uint32_t l_1550 = 1UL;
                        l_1543++;
                        if (l_1489[0][4][1])
                            continue;
                        --l_1550;
                    }
                    for (l_1537 = 10; (l_1537 >= 5); l_1537 = safe_sub_func_uint32_t_u_u(l_1537, 6))
                    {
                        int16_t l_1581 = 0x4CE7L;
                        if (l_419)
                            {
if ((safe_lshift_func_int16_t_s_u((l_1726 <= l_2006), (safe_sub_func_int8_t_s_s(((l_1888[2] <= ((((safe_sub_func_int32_t_s_s(g_143, (safe_mod_func_uint32_t_u_u((0x7ABE5FAFL >= ((safe_sub_func_uint8_t_u_u(g_120[1], l_2006)) , ((safe_lshift_func_int8_t_s_u(l_2006, (((((((safe_lshift_func_int8_t_s_s(g_143, 3)) | l_1888[2]) || l_699) >= l_1726) <= g_97[5]) , l_2006) >= 4294967295UL))) == g_540))), l_1888[2])))) >= l_1726) ^ 0UL) != 8L)) ^ 0x0968FE10L), l_1837)))))
        {
            uint32_t l_749 = 4294967288UL;
            if ((~(safe_add_func_uint32_t_u_u(((0L != (((l_1888[2] || (safe_sub_func_int8_t_s_s(0x65L, (safe_mod_func_uint32_t_u_u(l_1837, l_2006))))) ^ ((safe_add_func_uint16_t_u_u((l_699 , (safe_lshift_func_int8_t_s_u((0xA7L & 6L), 0))), (((l_1726 == l_326) >= g_18) < l_2182))) < (-1L))) < l_1726)) , 0x11329388L), 4294967295UL))))
            {
                int32_t l_769[1];
                int i;

{
        uint8_t l_121 = 0x0CL;
        int8_t l_296 = 0x7BL;
        int32_t l_368 = 0x73C1A89DL;
        uint16_t l_389 = 9UL;
        int32_t l_390 = 4L;
        int32_t l_394 = 0x0A309251L;
        int16_t l_472 = 1L;
        int32_t l_656 = 4L;
        for (l_1505 = (-11); (l_1505 >= 14); ++l_1505)
        {
            int8_t l_94[2];
            uint32_t l_134 = 18446744073709551615UL;
            uint16_t l_142 = 0x7BCBL;
            int i;
            for (i = 0; i < 2; i++)
                l_94[i] = 1L;
            for (l_1639 = 0; (l_1639 <= 1); l_1639 += 1)
            {
                int i;
                for (l_198 = 0; (l_198 <= 1); l_198 += 1)
                {
                    int i;
                    return l_94[l_1639];
                }
                if (l_94[l_1639])
                    continue;
                if (l_94[0])
                    continue;
            }
            for (l_1725 = 0; (l_1725 > (-19)); l_1725 = safe_sub_func_uint16_t_u_u(l_1725, 7))
            {
                uint8_t l_103[4] = {1UL, 0xABL, 1UL, 0xABL};
                int i;
                g_97[2] ^= p_43;
                for (g_1168 = 1; (g_1168 <= 6); g_1168 += 1)
                {
                    int16_t l_110[7] = {0xD96CL, (-2L), 0xD96CL, (-2L), 0xD96CL, (-2L), 0xD96CL};
                    int8_t l_168 = 0xE9L;
                    int8_t l_181 = 0xCFL;
                    int i;
                    for (p_40 = 6; (p_40 >= 1); p_40 -= 1)
                    {
                        int i;
                        l_1639 = (safe_mod_func_int32_t_s_s(g_97[p_40], l_1505));
                        g_100 = g_18;
                        g_2254 &= 0xEC293C97L;
                    }
                    l_103[3]++;
                    if (((safe_rshift_func_int8_t_s_u((((((g_18 ^ ((safe_add_func_uint32_t_u_u((l_110[0] == (g_2254 == (safe_mod_func_uint16_t_u_u(0UL, (((safe_unary_minus_func_uint16_t_u(l_1725)) | (l_94[1] , ((safe_add_func_uint16_t_u_u(((((((safe_mod_func_int8_t_s_s(p_41, (safe_sub_func_uint8_t_u_u((g_120[1] > (l_1640 | p_41)), p_41)))) ^ l_198) || 0x17461B67L) && g_97[2]) == 1L) , g_18), g_120[4])) , g_120[3]))) & l_1725))))), g_2254)) > 0x3AD0L)) & g_2254) || p_40) != l_94[1]) == l_121), g_18)) <= (-9L)))
                    {
                        int8_t l_141 = (-10L);
                        l_2050 ^= (g_97[6] < (safe_mod_func_int16_t_s_s((((g_120[1] ^ ((safe_add_func_uint32_t_u_u(((g_2254 <= ((safe_sub_func_uint8_t_u_u(l_103[1], (((((((safe_sub_func_uint16_t_u_u(((l_134 >= g_1168) > 0UL), ((((((safe_sub_func_int32_t_s_s((((safe_add_func_uint8_t_u_u((((((((g_100 & (safe_lshift_func_uint8_t_u_u((l_94[0] <= l_110[0]), g_2254))) || p_41) | 0xF7L) & l_141) , 0x6CL) | g_100) < l_94[1]), l_103[3])) >= l_1505) > p_40), 1L)) || l_1726) >= g_1168) , l_1505) > l_142) < g_1168))) == l_1640) , p_40) && 0x68L) && l_121) >= l_110[0]) ^ p_41))) != g_120[1])) != (-5L)), 0xB89AE2E4L)) > l_121)) > l_1725) || 0x3285CC41L), g_97[2])));
                    }
                    else
                    {
                        int32_t l_167 = 0xBD733D80L;
                        if (l_1726)
                            break;
                        g_120[4] = (safe_rshift_func_int16_t_s_u((safe_lshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_s((safe_mod_func_uint8_t_u_u(((g_97[4] ^ (l_198 | (safe_lshift_func_int16_t_s_u((((safe_mod_func_int16_t_s_s(((safe_rshift_func_int8_t_s_u(2L, ((+(((p_40 , ((safe_rshift_func_uint8_t_u_s(((l_103[3] > ((((p_41 & 0x8D56L) > (safe_lshift_func_uint8_t_u_s((safe_add_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((65535UL ^ (4L >= (-10L))), g_120[0])), p_40)), l_1639))) == 0xB673D79CL) ^ 1L)) | g_100), l_103[3])) <= l_1640)) != (-8L)) < l_167)) | l_198))) , g_1168), l_103[3])) ^ 0xBAC23114L) | l_110[0]), l_168)))) | p_40), (-2L))), 12)), 10)), g_100));
                        g_120[4] = ((((safe_add_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((safe_lshift_func_uint8_t_u_s(((255UL >= 254UL) < ((safe_mod_func_uint16_t_u_u(g_2254, 65531UL)) || 0x8F5F89A5L)), (((((+(((((~l_1726) & ((p_43 , l_168) < ((((((g_100 && p_40) && l_167) == p_40) , 6L) ^ l_2050) , 0x9D48L))) < 0x5183DF78L) , l_142) & 1L)) != l_167) || l_181) || g_100) <= 4294967286UL))) || 0x76D7L), 1)), l_1639)) || 0xFB851665L), 0x69F6L)) >= p_41) , 0xDEBA2DDDL) <= l_121);
                    }
                }
                for (l_198 = 0; (l_198 != 33); l_198++)
                {
                    return p_41;
                }
                if (l_103[3])
                    break;
            }
        }
        for (l_1726 = 0; (l_1726 < (-17)); --l_1726)
        {
            uint8_t l_198 = 1UL;
            int16_t l_261 = (-10L);
            uint16_t l_350 = 5UL;
            int32_t l_367 = 1L;
            int32_t l_391[3][6] = {{0xD2D39850L, 1L, 1L, 0L, 0L, 1L}, {0xD2D39850L, 1L, 1L, 0L, 0L, 1L}, {0xD2D39850L, 1L, 1L, 0L, 0L, 1L}};
            uint32_t l_431 = 0x13F79E03L;
            int i, j;
            if (l_121)
                break;
            l_1639 ^= l_121;
            for (l_1640 = 0; (l_1640 == 26); ++l_1640)
            {
                uint32_t l_210 = 0UL;
                int8_t l_281[8][7] = {{0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}};
                uint32_t l_326 = 0x0A0DE782L;
                int32_t l_363 = 0L;
                int32_t l_392 = (-1L);
                int32_t l_395 = 0L;
                const uint32_t l_420 = 0xA82EA14BL;
                const int16_t l_427 = 0L;
                int i, j;
                if ((l_1639 || (safe_mod_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_u(0x73L, 5)) | ((safe_mod_func_int32_t_s_s(l_198, (safe_rshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s((((0x7CB8L < 0xB2B8L) , ((l_198 ^ 0xDBL) != l_198)) && 0xD1L), l_1505)), 11)))) != l_1639)), 0xA615L))))
                {
                    uint32_t l_207 = 0x44D27D01L;
                    g_120[3] = l_1726;
                    for (l_2050 = (-26); (l_2050 >= 44); l_2050++)
                    {
                        return l_198;
                    }
                    g_120[1] = (((((((g_120[1] && g_2254) || ((safe_rshift_func_uint16_t_u_u(((p_41 , ((safe_mod_func_uint32_t_u_u(((safe_mod_func_uint16_t_u_u(((((0x47C1L >= (l_1725 ^ l_207)) <= (safe_sub_func_uint16_t_u_u(((g_18 && p_43) , l_121), l_121))) ^ g_120[1]) < g_120[0]), g_120[1])) & g_97[2]), 0x3A8961DAL)) & 0L)) , l_1726), 4)) & g_120[1])) ^ l_1639) == l_207) | l_210) & 0xD933A2BCL) & l_121);
                }
                else
                {
                    uint8_t l_258 = 0x75L;
                    int32_t l_262 = 0x18EC19C0L;
                    for (l_2050 = (-24); (l_2050 < 42); ++l_2050)
                    {
                        l_213[2] |= p_43;
                        return l_198;
                    }
                    l_1639 = ((0x5EL || (safe_lshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((0x746C22C4L && (safe_add_func_int16_t_s_s(((p_41 , (safe_rshift_func_uint8_t_u_u(g_100, 6))) && (safe_add_func_uint8_t_u_u(l_1726, (safe_lshift_func_int16_t_s_u((((safe_rshift_func_int8_t_s_s((safe_add_func_int8_t_s_s(((l_1725 == (((safe_sub_func_uint32_t_u_u(((l_198 || 0x50L) | ((safe_sub_func_uint32_t_u_u((((l_213[2] == p_40) , l_121) >= g_2254), l_1726)) == 0xFF3A24CFL)), 0x3913078BL)) >= p_40) , 1L)) != l_1726), l_1639)), l_1639)) > g_2254) | (-6L)), 1))))), g_120[2]))), 0L)), 15))) != l_1639);
                    for (l_1505 = 0; (l_1505 > 43); l_1505 = safe_add_func_uint8_t_u_u(l_1505, 2))
                    {
                        uint16_t l_236 = 1UL;
                        g_120[1] = 0x724D0293L;
                        l_236 = p_40;
                        l_262 = (safe_sub_func_int8_t_s_s((((((((g_100 || ((((1UL < ((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((((safe_mod_func_uint8_t_u_u(255UL, (safe_rshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s(((safe_sub_func_int8_t_s_s((safe_mod_func_int16_t_s_s(l_1693, 65535UL)), l_198)) > ((safe_rshift_func_uint16_t_u_u(l_1726, ((((safe_rshift_func_int16_t_s_u(((l_258 , (((safe_add_func_uint32_t_u_u(l_2050, g_120[1])) == l_198) , l_236)) & l_258), l_1726)) || g_97[2]) , l_1725) , 0x2CA6L))) > 0x62L)), l_1726)) | l_261), 0)))) | l_210) && l_1639), 255UL)) | g_18), 11)) , p_41)) || l_236) , 0x43L) | 1UL)) ^ l_1726) , g_1168) < 0L) < l_1693) != l_1725) >= l_121), l_1725));
                        l_296 = ((((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_u(((((((safe_add_func_uint16_t_u_u(l_121, g_2254)) == ((safe_mod_func_int32_t_s_s((((((safe_add_func_int16_t_s_s((safe_sub_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u(((((safe_sub_func_uint32_t_u_u(l_281[4][6], l_258)) ^ (((safe_add_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u((0x25D96900L <= (safe_sub_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s(l_236, g_1168)) < ((safe_lshift_func_int16_t_s_s(((0UL < (safe_mod_func_int8_t_s_s(p_41, g_97[4]))) == g_120[2]), p_40)) < 7UL)), 2UL))), l_1726)), 0x96E64D66L)) >= l_1725), 0xFC6B1E59L)) < (-5L)) | 4294967292UL)) != l_1639) ^ 8L), (-7L))) & p_43), l_1639)) > l_236) <= (-1L)), l_1726)), l_1726)) >= l_2050) ^ 0xF7BFL) , p_40) == l_198), g_2254)) && l_198)) | 1UL) != 0x6CL) <= l_281[0][2]) , 0x35L), l_121)) && l_1726), 4)) & l_2050) < 0x73054497L) != g_2254);
                    }
                    for (l_1505 = 0; (l_1505 <= 4); l_1505 += 1)
                    {
                        int i;
                        g_120[l_1505] = ((safe_sub_func_int32_t_s_s(g_97[(l_1505 + 2)], (safe_unary_minus_func_uint8_t_u(((((safe_sub_func_int16_t_s_s(((g_97[l_1505] , 0xC6C2L) ^ 0xFEB2L), ((safe_rshift_func_uint16_t_u_u(g_97[(l_1505 + 1)], ((safe_rshift_func_uint16_t_u_u(g_120[l_1505], 5)) != (safe_mod_func_int8_t_s_s(((((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(g_120[l_1505], ((0x60L < g_120[l_1505]) , l_281[3][1]))), 0x2C0B2767L)) >= l_1640) != p_40) != 255UL), 0xE6L))))) >= l_1725))) != (-6L)) || g_120[0]) && g_97[(l_1505 + 2)]))))) & g_2254);
                        g_120[2] = ((-8L) == 0UL);
                        l_326 = ((((((((65535UL > (safe_mod_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((((l_262 || (l_198 || (safe_mod_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u((safe_rshift_func_int8_t_s_u(p_40, (((l_1693 > (l_281[4][6] , l_1726)) != ((safe_rshift_func_uint16_t_u_u(0xB25DL, 8)) || 1UL)) <= l_1725))), g_2254)) | g_97[2]), 1)), g_2254)))) & l_1726) || p_40), l_213[0])) & l_258), l_1726))) <= p_40) < g_120[l_1505]) == 0x8B28L) < l_1725) || l_213[2]) != g_100) <= 246UL);
                        l_262 |= (~g_120[1]);
                    }
                }
                for (l_121 = 20; (l_121 < 40); l_121 = safe_add_func_uint32_t_u_u(l_121, 1))
                {
                    int8_t l_362 = 0x43L;
                    int32_t l_366 = (-2L);
                    uint8_t l_369 = 0x5AL;
                    int32_t l_393 = 0L;
                    if ((safe_add_func_int16_t_s_s(((((l_213[1] || ((p_41 >= (+(-1L))) >= (safe_lshift_func_int8_t_s_s(((safe_sub_func_int8_t_s_s((((safe_mod_func_int16_t_s_s(((safe_lshift_func_int16_t_s_s(l_121, 2)) == (((safe_lshift_func_uint16_t_u_s((l_198 || ((safe_rshift_func_uint16_t_u_s((((safe_add_func_int16_t_s_s(((((((safe_mod_func_int16_t_s_s(p_43, l_1505)) <= 0x56719CF5L) < ((+(((((1UL && 0xD84E0731L) > l_281[6][4]) < l_2050) > 0x15L) & 0xF7L)) | l_2050)) , p_41) == l_350) , l_1639), 0xA7B5L)) , 2L) , l_1633), 11)) >= g_2254)), l_210)) , 0x25L) < 7UL)), l_198)) <= 1UL) , l_210), l_198)) ^ 246UL), g_18)))) <= 0x83L) >= 6UL) & g_97[2]), l_1639)))
                    {
                        uint32_t l_364 = 0UL;
                        int32_t l_365 = 1L;
                        l_364 = ((safe_add_func_int8_t_s_s((((safe_lshift_func_uint16_t_u_u(((((l_1726 != l_296) > ((safe_lshift_func_uint16_t_u_u((0xA1L != (((-6L) && (((safe_rshift_func_int8_t_s_u(0x08L, ((p_43 < ((g_97[2] | (((safe_sub_func_uint16_t_u_u((((l_362 != 0xFEFA8AE2L) , g_2254) != g_97[2]), g_100)) && 0x6386802AL) >= g_97[1])) >= l_1725)) , l_1639))) < 2UL) && l_281[4][6])) != l_198)), 0)) ^ l_1639)) != g_97[2]) || 0xF9L), l_363)) || 0xD2L) , p_41), (-7L))) && p_41);
                        ++l_369;
                        if (l_281[4][3])
                            break;
                        l_366 = l_1639;
                    }
                    else
                    {
                        uint32_t l_384 = 0UL;
                        l_367 = (safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((l_1726 , (safe_mod_func_int32_t_s_s((((((((((((p_40 , ((safe_mod_func_uint8_t_u_u((g_97[2] ^ (~(+l_296))), ((((g_97[3] & ((safe_sub_func_uint16_t_u_u((l_384 >= l_1633), (((((((safe_lshift_func_int16_t_s_u((p_41 || (((((safe_rshift_func_int16_t_s_u((1UL != p_43), 4)) , 0x8DL) >= l_1725) , l_389) , 0x343F8062L)), p_43)) > 4L) > p_41) , g_120[1]) != p_40) , l_1639) == 0xCB3F649DL))) | p_41)) || l_1725) | g_120[3]) && 0xE5L))) < 0UL)) >= g_97[1]) || 0x3F5AL) ^ l_261) || p_43) | l_366) , 0L) || (-1L)) ^ 0x8506B361L) >= l_1726) ^ (-6L)), 0x3F0D7356L))), g_100)), g_1168));
                        g_22--;
                    }
                    l_1639 = (((((g_18 ^ (0UL & (((l_198 == (safe_mod_func_uint8_t_u_u(((((safe_sub_func_int16_t_s_s(((l_1639 & ((safe_add_func_int8_t_s_s((((safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((((safe_mod_func_uint32_t_u_u((safe_sub_func_int16_t_s_s((((g_2254 <= l_2050) > (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(l_296, ((((((((safe_rshift_func_uint8_t_u_s(g_2254, 1)) & (((l_281[4][6] || p_41) && p_41) | 0UL)) == g_120[1]) || l_121) < l_326) < g_2254) || 0x3CL) < g_18))), 4))) >= (-1L)), l_1633)), l_1504)) || p_43) >= l_420), g_100)), l_1725)) & (-1L)) | l_281[4][6]), 0x42L)) < g_97[3])) <= g_120[1]), g_120[3])) | g_22) != 0L) == l_391[1][4]), l_395))) > 0x32L) || l_390))) ^ p_43) | l_1639) < p_40) < 1UL);
                    for (l_1505 = 0; (l_1505 <= 4); l_1505 += 1)
                    {
                        int i;
                        return g_120[l_1505];
                    }
                    if (l_2050)
                        break;
                }
                for (l_363 = 0; (l_363 == (-23)); --l_363)
                {
                    uint32_t l_461[2][4][5] = {{{0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}}, {{0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}}};
                    int i, j, k;
                    g_120[1] = ((0x7DDEF103L >= ((((safe_rshift_func_int16_t_s_u(((0x2CD8L == ((((((0x0CE5L > l_1726) , (-9L)) || ((((safe_mod_func_uint32_t_u_u((g_120[1] > (0xD6FEED26L | ((l_427 >= (((((((safe_unary_minus_func_uint8_t_u(((safe_rshift_func_int8_t_s_s(g_97[1], 2)) != 0xEF0CL))) > 0x88D4L) && g_100) ^ g_120[1]) >= l_281[3][0]) | (-6L)) == 1L)) ^ 7UL))), 1UL)) < l_2050) | g_100) , 0UL)) ^ (-1L)) | l_281[0][3]) == g_22)) >= 0xBDE2D00BL), 7)) , 7L) > l_1726) || l_420)) , l_1504);
                    l_431--;
                    l_1639 = (((safe_unary_minus_func_int16_t_s(((((safe_unary_minus_func_uint16_t_u((l_326 , (((((~(safe_add_func_uint8_t_u_u((l_427 == (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_s(((safe_sub_func_int16_t_s_s(g_120[2], (((safe_add_func_uint8_t_u_u(((p_43 || ((safe_mod_func_int16_t_s_s(((((l_395 & ((0xAD109901L < ((((safe_rshift_func_uint8_t_u_s(p_40, 7)) != (p_41 <= (safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u((safe_sub_func_uint8_t_u_u(((((((((p_40 , 4UL) > 0UL) == 0xC8C73883L) <= l_427) ^ g_18) && l_121) || g_120[1]) & l_390), l_1726)), l_461[1][1][2])), l_296)), p_40)))) <= l_461[1][1][2]) < 0x237EL)) <= 0x28L)) < 65535UL) | l_363) >= p_41), l_213[4])) < 5UL)) ^ l_1693), l_198)) >= 0UL) | g_97[2]))) <= l_198), g_120[1])) ^ g_100), 7))), p_41))) < 1L) || l_1725) ^ g_1168) , 6UL)))) | l_2050) != g_1168) , l_368))) , 1UL) != 255UL);
                }
                g_120[1] ^= ((0L & 0x37L) >= (safe_sub_func_uint16_t_u_u(1UL, ((((safe_lshift_func_int8_t_s_u((g_97[3] >= (safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s(((((((safe_lshift_func_uint16_t_u_s(((((0xC0653759L ^ l_363) , p_41) == (l_392 != l_1639)) , 1UL), l_1639)) , 4L) , g_1168) || 0x464EEE5AL) | 8UL) & l_472), 5)) , 0x83F7DA68L) && g_18), 1UL))), 5)) <= l_1505) < 65531UL) || g_22))));
            }
        }
        for (l_1640 = 29; (l_1640 != (-14)); l_1640--)
        {
            uint16_t l_507 = 65527UL;
            int32_t l_520[5][4] = {{0x55AC6CE3L, 1L, (-1L), (-1L)}, {0x55AC6CE3L, 1L, (-1L), (-1L)}, {0x55AC6CE3L, 1L, (-1L), (-1L)}, {0x55AC6CE3L, 1L, (-1L), (-1L)}, {0x55AC6CE3L, 1L, (-1L), (-1L)}};
            int32_t l_567 = (-1L);
            int32_t l_655 = (-2L);
            uint8_t l_696 = 0xEEL;
            uint16_t l_711[6] = {0x6659L, 0x6659L, 65527UL, 0x6659L, 0x6659L, 65527UL};
            int i, j;
            if (g_18)
            {
                uint8_t l_508 = 1UL;
                g_120[1] = (safe_rshift_func_int16_t_s_s(((!(1UL >= (((0xE1L != ((((safe_rshift_func_int16_t_s_s(((safe_lshift_func_int8_t_s_u((((safe_sub_func_int8_t_s_s(l_1725, ((safe_rshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((65526UL & (safe_rshift_func_int16_t_s_s((((((g_100 != l_198) >= ((((safe_rshift_func_int8_t_s_s((safe_add_func_uint16_t_u_u(1UL, (((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u((!(safe_add_func_int8_t_s_s(((((safe_lshift_func_uint8_t_u_s((g_120[1] && ((safe_mod_func_uint8_t_u_u(0x86L, g_120[3])) <= g_1168)), l_507)) <= (-10L)) && 1L) & l_508), 0x6CL))), 3)), 2)) ^ l_390) && p_40))), 7)) > l_1693) && p_43) == 0x785C2DE3L)) & l_508) ^ l_1504) , p_43), g_120[0]))), l_1633)), 0)) <= g_97[2]))) , p_41) , l_507), l_198)) == g_2254), l_1633)) && l_1505) & g_18) , l_2050)) ^ 0x3CL) , 1UL))) ^ l_507), l_1725));
            }
            else
            {
                int8_t l_513[10][2] = {{0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}};
                int32_t l_569[8][6][5] = {{{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}};
                uint32_t l_642 = 18446744073709551615UL;
                int i, j, k;
                for (g_1168 = 0; (g_1168 >= 55); g_1168 = safe_add_func_int32_t_s_s(g_1168, 5))
                {
                    int8_t l_523 = 0xDBL;
                    l_520[1][3] = ((((p_40 || 0UL) != p_43) <= (safe_rshift_func_int16_t_s_u(0x4F5AL, (l_1505 ^ (0x7DL <= l_513[9][0]))))) , (l_1725 ^ (safe_mod_func_uint16_t_u_u((((safe_rshift_func_int16_t_s_s((safe_mod_func_int32_t_s_s(l_121, g_97[2])), 12)) < p_40) | l_513[9][0]), p_41))));
                    for (l_1505 = (-26); (l_1505 <= 16); l_1505++)
                    {
                        int8_t l_524 = (-8L);
                        l_524 = l_523;
                        l_1639 &= l_524;
                    }
                }
                if (((safe_mod_func_int16_t_s_s(l_1725, (safe_rshift_func_int8_t_s_s(l_198, 1)))) > (0xAD5285A3L <= l_513[9][0])))
                {
                    uint16_t l_533 = 0xB016L;
                    g_540 &= (safe_add_func_int32_t_s_s((1UL != g_120[1]), (safe_add_func_int8_t_s_s((g_120[1] || (p_41 > (((((((l_533 >= l_1726) & p_43) || ((safe_unary_minus_func_uint8_t_u(l_472)) & (((safe_lshift_func_int8_t_s_s((+(safe_rshift_func_int16_t_s_u((l_507 , 0xDD7CL), g_120[3]))), l_368)) ^ 8L) , l_1726))) > p_43) != l_507) > 0xEEL) , l_1640))), p_43))));
                    for (l_121 = 10; (l_121 != 4); l_121--)
                    {
                        const uint16_t l_568[6][9][4] = {{{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}};
                        const uint8_t l_576 = 249UL;
                        int i, j, k;
                        l_569[7][2][2] = (((safe_rshift_func_uint8_t_u_u(l_2050, 6)) , (safe_rshift_func_uint16_t_u_u((((l_213[2] <= (((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((((((((l_513[9][1] | g_97[2]) || l_198) ^ 0x77L) , ((safe_rshift_func_uint16_t_u_s(p_43, (((safe_rshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((((((safe_lshift_func_uint16_t_u_u((((((safe_lshift_func_uint8_t_u_u(l_296, 5)) == ((((((safe_rshift_func_uint8_t_u_s(((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(9UL, 4)) < l_520[1][3]), l_198)) && g_100), g_18)) < p_40) , p_40) < 0xA5D176F9L) || l_1725) != p_41)) || g_540) >= l_567) != g_18), 5)) != 0xFB0274BAL) > l_389) && l_567) != l_1726), l_513[5][0])), 4)) == g_1168) != g_540))) > l_1640)) ^ l_198) | l_507) | l_568[1][1][0]) && l_520[1][3]), l_533)), 0UL)) , l_513[8][1]) && p_41)) <= 0x1E8AL) || l_1639), 13))) , p_41);
                        l_368 = (safe_rshift_func_int16_t_s_s((safe_rshift_func_uint16_t_u_s((safe_add_func_int16_t_s_s(l_576, ((safe_sub_func_uint32_t_u_u(4294967295UL, ((safe_lshift_func_int8_t_s_u(p_43, (safe_add_func_uint32_t_u_u((((safe_add_func_int16_t_s_s((safe_add_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u(g_100, g_120[1])) , 0xD285L), (p_41 , (0UL != (safe_lshift_func_int16_t_s_u((((safe_sub_func_int16_t_s_s((!((((safe_add_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((-1L), 13)) | g_1168), l_569[7][2][2])) <= l_513[9][0]) || l_598[1]) <= g_18)), l_213[2])) ^ p_40) , 0xDB70L), l_1725)))))), p_41)) > g_120[1]) >= l_1639), g_97[5])))) ^ 0x9F178DF0L))) && l_598[1]))), 7)), p_41));
                        l_1639 = ((+0x203AL) && (safe_rshift_func_uint8_t_u_s((0xF62F64AEL < (((safe_sub_func_int32_t_s_s((((safe_lshift_func_uint8_t_u_s(0x12L, 1)) & ((safe_rshift_func_int16_t_s_u(((safe_sub_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_u(l_1639, p_41)), (((!((g_97[1] | (l_389 || ((l_613 < l_507) == l_520[1][3]))) , p_43)) >= (-1L)) && p_41))) , 0xD86FL), 2)) & 255UL)) > l_1726), 0x9FADD9B3L)) , 0L) | p_43)), l_533)));
                        if (p_41)
                            continue;
                    }
                    for (l_1505 = (-15); (l_1505 < 46); l_1505 = safe_add_func_uint32_t_u_u(l_1505, 1))
                    {
                        --l_1505;
                        l_520[1][3] = (l_1640 != ((~(safe_lshift_func_int16_t_s_u(l_2050, l_1726))) <= (safe_add_func_int8_t_s_s(l_1725, 1L))));
                        if (g_97[2])
                            break;
                        return g_2254;
                    }
                }
                else
                {
                    g_120[1] = 1L;
                }
                l_1639 = (((((safe_add_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s((((0xA08E28CFL <= (l_2050 == (((safe_rshift_func_int16_t_s_u(l_1639, 8)) && (safe_rshift_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_mod_func_uint8_t_u_u(g_120[1], l_1505)), (0L > g_100))), (g_100 || (safe_sub_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u(l_2050, l_642)) | l_569[7][2][1]), 0UL)))))) | l_507))) | l_1726) , p_43), 15)) != p_43), g_540)) && g_1168) | l_520[0][2]) >= l_394) >= l_1639);
                if ((safe_lshift_func_int16_t_s_s(l_1726, (((((l_1726 && (((safe_sub_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((((0x23L && l_569[4][5][3]) != (safe_sub_func_uint32_t_u_u(l_296, g_97[1]))) , (safe_add_func_int8_t_s_s(l_1639, l_121))), g_2254)), l_613)) < 4294967295UL) | p_41)) ^ 0x77L) , l_394) , 0x3B0A0897L) >= g_97[4]))))
                {
                    l_1639 &= (safe_rshift_func_uint16_t_u_u(l_655, 8));
                }
                else
                {
                    for (g_100 = 0; (g_100 <= 5); g_100 += 1)
                    {
                        return l_656;
                    }
                    return g_120[1];
                }
            }
            if (((((((safe_add_func_int16_t_s_s(((p_41 == (safe_sub_func_int8_t_s_s(g_18, (65529UL | 0L)))) , (safe_sub_func_int8_t_s_s(((p_40 ^ ((g_97[3] >= ((((safe_lshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u(l_368, 1)) , (safe_mod_func_uint32_t_u_u(l_507, (~(g_2254 && 0xFDA677A5L))))), l_2050)) ^ g_1168) & l_1726) & 1L)) == g_120[1])) && l_1639), l_1639))), l_2050)) == p_43) && 255UL) < g_97[1]) >= l_296) ^ p_41))
            {
                int32_t l_691 = 0x098722ADL;
                int32_t l_693 = (-10L);
                for (g_100 = 5; (g_100 >= 0); g_100 -= 1)
                {
                    uint16_t l_692 = 0xCE33L;
                    uint32_t l_695 = 18446744073709551615UL;
                    int i;
                    l_472 &= ((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_s(l_213[g_100], 3)) , (((safe_add_func_int8_t_s_s((g_2254 != (+(0xFEB6F005L != (safe_lshift_func_int16_t_s_u(((0x63L == ((safe_rshift_func_uint8_t_u_u(l_520[1][3], 0)) > (safe_mod_func_int32_t_s_s((g_22 > 3UL), (((((((0L >= (((safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_s(((safe_lshift_func_int16_t_s_u((safe_add_func_uint16_t_u_u(((0x37L == l_691) | l_390), p_43)), l_213[g_100])) != l_692), l_691)), p_43)) >= (-2L)) >= p_40)) , 0xF9DAL) || p_41) || 6L) || g_18) >= l_692) & 248UL))))) & l_198), 9))))), g_120[1])) , 0UL) <= l_693)), l_1726)) , 0x2B6242CAL);
                    g_120[3] = (((l_695 , g_18) >= (l_696 && ((p_40 <= ((((safe_add_func_uint32_t_u_u((((l_1639 ^ ((l_389 > l_520[1][3]) , (g_120[1] | 0x8AL))) > l_2050) == l_1725), p_43)) && l_507) , 65535UL) <= l_598[1])) && 65535UL))) , l_1726);
                    if (l_1639)
                        break;
                }
            }
            else
            {
                l_213[4] = l_472;
                if (l_507)
                    continue;
            }
            l_1725 &= ((((((((safe_mod_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_u(((-3L) < (((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((!(((((l_472 == (0x1D5D50F0L == l_711[2])) >= (((safe_unary_minus_func_uint32_t_u(0xFC24DB18L)) | 0xA3L) || ((((~((((((((0UL < l_696) || ((((safe_sub_func_int32_t_s_s(((((((+((l_567 == l_711[2]) && 65535UL)) < l_389) || l_198) != l_1693) == 0L) ^ g_97[2]), 0x3C3D0A9BL)) != l_1639) , l_1639) > l_389)) != l_507) >= 7L) && l_1726) && l_1639) < 1L) , p_41)) > 0x60B3L) && 6UL) != l_567))) || p_41) && 0x58L) | 0xEFC1L)) && l_655), l_389)), g_2254)) ^ 9L) | 0x68L)), l_598[3])) >= g_120[4]), (-7L))) <= 0L) != l_213[2]) == l_1505) && p_41) <= l_1726) < 0x057B1D42L) | l_213[1]);
        }
    }

                    for (i = 0; i < 1; i++)
                    l_769[i] = 0x804970A5L;
                g_120[1] = 1L;

{
        transparent_crc(g_1368[l_390], "g_1368[l_390]", l_368);
        if (l_368) printf("index = [%d]\n", l_390);

    }

                    if (l_1726)
                    {
{
                uint32_t l_2161 = 0x817ED328L;
                l_1547 |= (7L ^ (g_1171 > (((g_2414 < (g_1171 & ((safe_lshift_func_uint8_t_u_u(0x2CL, 3)) || (255UL >= g_1171)))) , g_1548[2][0][1]) == l_2161)));
                l_1646 = (safe_sub_func_uint32_t_u_u((l_1931[0] >= ((g_1171 >= (safe_add_func_int32_t_s_s(((((((safe_add_func_int8_t_s_s(((((safe_sub_func_int8_t_s_s(l_1549, (safe_sub_func_uint16_t_u_u(0xB24EL, ((((safe_mod_func_uint32_t_u_u(l_1671, ((((safe_sub_func_int32_t_s_s((0L == l_2178[0]), (0x17L && (l_1854 , 0x38L)))) > l_1671) , 255UL) && l_1671))) || 0x8F222FB3L) || 0xC79840FEL) ^ g_1171))))) < g_1171) , l_86) > g_97[5]), 7UL)) < g_120[2]) , g_120[1]) & l_1648) <= g_2414) && g_18), g_1171))) && g_1171)), g_100));
            }

                    continue;}
                l_749 = (safe_rshift_func_uint16_t_u_u(g_97[2], 13));
                l_1698 = (safe_lshift_func_int8_t_s_s((5UL >= (0UL < (safe_add_func_int8_t_s_s((((safe_rshift_func_int16_t_s_s((g_18 != (safe_sub_func_int32_t_s_s((safe_unary_minus_func_int32_t_s((safe_mod_func_int8_t_s_s((safe_mod_func_int32_t_s_s(0x5B48709BL, ((safe_rshift_func_int16_t_s_s(g_18, l_1726)) || 3L))), (safe_sub_func_int32_t_s_s(g_540, ((((safe_rshift_func_int16_t_s_u(l_1726, 7)) || g_18) || l_769[0]) <= l_1837))))))), g_143))), 6)) != l_1726) != l_296), l_2006)))), l_1837));
            }
            else
            {
                int16_t l_775 = (-4L);
                int32_t l_776 = (-3L);
                l_1887 = ((((l_326 ^ (l_1888[2] , (0xB43536D7L > 0x43474B68L))) >= (((g_18 < ((safe_add_func_int8_t_s_s(l_2006, 0xFAL)) & (safe_mod_func_int8_t_s_s(((((((l_775 | l_776) || l_2182) || l_699) , l_1837) <= 6L) <= 0x62L), 0x36L)))) && l_326) > 0x8EL)) != l_1837) == l_1837);
            }

l_1671 += 1;


                    --l_1887;
        }
        else
        {
            int16_t l_786 = 8L;
            int32_t l_789 = 2L;
            int32_t l_791 = 0xB2B08DC3L;
            uint32_t l_794 = 0x67A078F5L;
            l_368 = (safe_rshift_func_int16_t_s_u(l_699, 9));
            if (l_1837)
                break;
            for (l_368 = 0; (l_368 <= (-8)); l_368--)
            {
                return l_786;
            }
            for (g_540 = 2; (g_540 < 14); g_540 = safe_add_func_uint16_t_u_u(g_540, 3))
            {
                l_794--;
            }
        };


                    break;}

for (l_1806 = 0; l_1806 < 1; l_1806++)
        l_1696[l_1806] = 0xDAD1BFA1L;

                    g_120[1] = (l_1549 || (0xA427L == (safe_mod_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((g_1368[1] == 1UL), (-1L))), 0x2E3AL))));

for (l_2182 = (-11); (l_2182 < (-24)); --l_2182)
                {
                    int32_t l_1929 = 0L;
                    int32_t l_1930 = 0x01C56913L;
                    uint8_t l_1949 = 0xBEL;
                    int32_t l_2005 = 0L;
                    if (l_613)
                    {
                        int32_t l_1928[10] = {0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L};
                        int i;
                        l_419--;
                    }
                    else
                    {

for (g_2467 = 0; (g_2467 > 15); ++g_2467)
        {
            g_120[1] = 0x19D1A3FEL;
            if (g_694)
                continue;
        };


                    l_1641 = l_2325;
                    }
                    if ((l_613 , l_1641))
                    {
                        int8_t l_1947 = 0x1BL;
                        int32_t l_1948 = 0x27F08C10L;
                        l_1547 = (((0x03L == (0xA11DL < (g_59 | ((((0x6F1BL != l_1581) < (((((((((safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(g_97[2], l_121)), 2)) > (safe_add_func_uint16_t_u_u(g_1548[4][6][2], 0x34DEL))) & l_1905), l_1706)) , 0x3208L) , g_1540[1][0]) , l_1930) == l_2182) , g_1548[0][0][1]) <= l_419) > l_1905) >= 0UL)) < l_1905) >= l_2325)))) ^ g_97[2]) , g_849[0]);
                        ++l_1949;

if (l_1888[1])
                            break;

                    g_120[4] = (safe_mod_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(6L, (safe_sub_func_uint8_t_u_u(0x94L, (((l_1949 | (safe_rshift_func_int8_t_s_u(((((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((((+(safe_add_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(((0xB3EFL || (l_1947 | (((g_120[1] ^ ((((-2L) & (((l_1905 ^ (l_1547 , 0x78L)) , g_22) < l_2325)) < 0xA9FBL) == l_2325)) < l_1648) < 0xE1L))) && l_1948), 0x64L)) , l_2325), 9UL))) >= 0x60B3L) != l_2325) ^ l_2325), l_613)), 0x0DAEL)), l_1543)) >= l_1947) > l_2325) == l_1905), l_1948))) , 5L) | 0xB082A17BL))))) , 0x11L), 0x03L));
                    }
                    else
                    {
                        l_1930 = ((0L & l_2325) != (!((safe_mod_func_uint8_t_u_u(l_613, 0x7AL)) > (((l_419 | l_2325) , 0x1F0EL) < (l_1905 && ((((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u(l_296, l_1905)), 0x3929L)) != 0L) == 0x2F747C30L) , 0x96347F98L))))));
                    }
                    if (((safe_lshift_func_uint16_t_u_s((g_1540[1][0] , l_1930), l_1905)) & (((l_1581 < (((((safe_lshift_func_int16_t_s_u(((l_2325 , ((l_1905 && (((safe_unary_minus_func_int16_t_s(((safe_add_func_uint16_t_u_u(l_1641, ((((safe_add_func_uint16_t_u_u((l_236 ^ l_2325), l_616)) < l_1905) < 0x1D1DL) | l_2182))) | g_120[1]))) , l_2325) && l_1643[1][1][6])) ^ l_699)) , l_2325), l_1649)) | l_1905) <= 0UL) != (-8L)) , l_2325)) < l_2055) || 0x837FL)))
                    {
                        int8_t l_2002 = 0x5BL;
                        int32_t l_2004[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_2004[i] = 7L;
                        l_1931[0] |= (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u(g_1482[0][1][0], ((~((((-6L) < l_1905) >= g_120[1]) | (l_1905 , l_1905))) != (((safe_lshift_func_uint16_t_u_s(((g_1548[4][6][2] || ((((safe_rshift_func_int8_t_s_s(1L, 4)) <= 0xC812E52FL) || l_2178[1]) <= 0UL)) , l_1888[1]), 3)) != l_2325) < 65535UL)))) | g_1482[2][1][1]) <= 4294967292UL) && l_1929) > l_2002), g_849[0])), l_613));
                        l_613--;
                        if (l_1888[1])
                            break;
                    }
                    else
                    {
                        uint8_t l_2013[2][2] = {{1UL, 0x0EL}, {1UL, 0x0EL}};
                        int i, j;
                        g_120[1] = (safe_rshift_func_int16_t_s_u((((safe_sub_func_uint8_t_u_u((0xBC96E130L > l_2013[1][0]), ((safe_add_func_uint8_t_u_u(((l_2005 >= (((safe_add_func_uint8_t_u_u((((p_40 & l_2013[0][1]) , ((safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(g_1548[4][6][2], l_419)) , ((safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((l_1905 ^ ((safe_mod_func_uint16_t_u_u((65534UL <= j), l_1905)) , g_120[3])) || l_236), g_97[1])) > l_2050), (-4L))) > 7L)), l_1949)) == l_1888[2])) < l_613), 9UL)) | l_2178[1]) & j)) <= l_1930), 0x27L)) & 9UL))) && l_613) , 0x1E18L), g_18));
                    }
                    g_120[1] = ((((0UL == (0x99L == g_1482[2][1][1])) , g_2468) , g_97[2]) > ((g_120[3] > ((((((safe_lshift_func_uint16_t_u_s(((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s(((0x83922D4EL != ((-8L) > 0x08L)) || l_1649), 5)), l_2050)) >= l_1649), 15)) < l_2325) , 0xAC9FE61AL) , l_2325) > l_1905) | g_1540[1][0])) ^ (-1L)));
                };


                    g_120[1] = ((+(l_258 < ((((((safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((~l_261), ((safe_lshift_func_int8_t_s_s(l_1547, (safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((+((safe_add_func_int8_t_s_s((0UL != (((safe_rshift_func_int8_t_s_u((l_699 > g_1368[2]), 1)) == (safe_unary_minus_func_int8_t_s((l_419 , (safe_rshift_func_uint8_t_u_s((((safe_mod_func_int8_t_s_s((0x71L >= l_1581), 0xB6L)) , l_419) <= p_39), 3)))))) && g_2467)), 0UL)) ^ l_1522[0][5])) & 1UL), l_419)), 13)))) , 0x89L))), l_258)) != l_1537) , l_389) || 65531UL) > p_39) < 0x33D41A9EL))) , g_59);
                    }
                    for (g_935 = 0; (g_935 <= 4); g_935 += 1)
                    {
                        int16_t l_1588[5][10][5] = {{{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}};
                        const int16_t l_1592 = (-1L);
                        int i, j, k;
                        g_120[g_935] = ((safe_sub_func_int32_t_s_s(l_261, 0xC58F4B07L)) ^ ((((((-1L) > (((((safe_add_func_int8_t_s_s(((((safe_sub_func_uint32_t_u_u(((l_1588[4][3][4] | (0xBBL | g_97[2])) ^ l_1542[2][5][1]), (l_258 , (safe_lshift_func_uint16_t_u_u(((0x8B2D6D5DL < (-6L)) < 0x8664AFBBL), 8))))) & l_419) > 7L) >= l_1591), l_1588[1][8][4])) && l_419) == 1UL) , l_1592) && g_97[2])) || p_40) <= l_419) || l_389) >= l_1533[1][2]));
                        return l_1549;
                    }
                }
                if ((((safe_rshift_func_uint8_t_u_s(l_1549, 4)) >= (safe_lshift_func_uint8_t_u_s(l_1591, (safe_lshift_func_int8_t_s_s(l_1599, 1))))) != ((safe_lshift_func_int16_t_s_u((!(((l_258 >= l_1547) , ((!g_849[0]) >= ((l_699 <= (!(((safe_rshift_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_u((((g_935 > 0L) ^ p_39) < l_1504), l_258)) || 0x729EL) > 0xD46FL), 2)) < g_97[2]) , 6UL))) || l_258))) | l_1489[2][4][7])), 12)) == l_258)))
                {
                    uint16_t l_1611 = 0xD966L;
                    int32_t l_1636 = 1L;
                    int32_t l_1638[4][6][7] = {{{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}};
                    uint8_t l_1656[3][8][6] = {{{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}};
                    int i, j, k;

for (l_1699 = 0; (l_1699 > 15); ++l_1699)
        {
            g_120[1] = 0x19D1A3FEL;
            if (l_1726)
                continue;
        };


                    g_120[1] = ((((l_419 & ((safe_mul_func_uint8_t_u_u(l_1611, ((((l_1494 | (safe_mod_func_int8_t_s_s(p_39, (safe_lshift_func_uint16_t_u_u((((((((+(l_1494 , ((l_1504 & (safe_lshift_func_uint16_t_u_s((((+(((((((l_351 <= (((((p_39 & ((0x4BA9L | 0xAB14L) == 0xB0E53EB1L)) == 0x49L) >= g_143) && p_39) < l_1611)) > 0x891AL) ^ 0xC4L) >= l_431) > l_1599) ^ g_849[0]) < l_1591)) & 0x2C1DL) >= 0L), 14))) , g_143))) & l_261) != 0x3AL) , l_258) && p_40) ^ p_39) >= l_258), 1))))) && l_419) >= l_1522[4][1]) <= 0x012802EEL))) ^ 0x6FL)) | l_258) != 4294967290UL) | g_120[4]);
                    if ((l_1489[2][4][7] <= (g_97[0] <= l_1494)))
                    {
                        int32_t l_1635 = 0L;
                        int32_t l_1637 = 1L;
                        int32_t l_1642 = (-3L);
                        int32_t l_1645[4][10][3] = {{{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}};
                        int8_t l_1653 = 0xE0L;
                        int i, j, k;
                        l_1634 = (((((safe_mod_func_uint16_t_u_u((safe_unary_minus_func_uint8_t_u((safe_sub_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((p_39 ^ (((((safe_mod_func_uint8_t_u_u(((((safe_add_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(((l_419 && (((l_258 , l_1494) > (p_39 & g_143)) >= (-2L))) == ((-1L) & ((0x2C2C4A06L || 0L) != p_40))), 0x84D0E611L)) < 247UL), l_1537)) == g_1540[0][1]) != 65535UL) != (-5L)), l_1599)) , g_2467) , l_1611) == l_258) && 9L)) >= 0x3E95L), p_39)), l_419)))), 65530UL)) >= l_1549) | 0xA236F820L) , l_1611) < l_1633);
                        l_1656[1][6][4]++;
                        ++l_1659;
                    }
                    else
                    {
                        int32_t l_1692 = 1L;
                        l_1671 = (((safe_mod_func_uint16_t_u_u((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u((((l_1651 , ((((g_935 != l_1611) >= (safe_sub_func_uint8_t_u_u(0xEEL, g_849[0]))) <= g_143) != (1UL & l_258))) && (!(l_1651 >= l_1644[2][1][0]))) || l_1641), (-2L))), 1UL)), g_120[1])) > 0x1BL) | 0xC3L);
                        g_120[1] = (+1UL);
                        l_1643[3][1][5] = (safe_add_func_uint32_t_u_u(0UL, (((safe_rshift_func_uint16_t_u_u(((safe_mod_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((~p_39), ((0x60L ^ ((l_1651 == ((((((-1L) == ((0x4B8FL == (l_258 | (((6L | (safe_rshift_func_uint16_t_u_u(((((((((safe_lshift_func_int8_t_s_u(((~(((((safe_mod_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(((!(1UL != l_699)) > l_1522[2][7]), g_120[1])), l_1638[0][0][2])) < 4294967295UL) , l_419) , 0xE3L) , 0x49L)) && 0x109AL), 6)) , g_935) || 4294967288UL) < 0x758ECAE5L) , l_419) > l_1692) != g_120[4]) == 0x90143625L), g_120[0]))) != l_258) | g_18))) | (-1L))) > l_419) > l_351) , l_419) != l_419)) < l_1692)) < g_18))), l_258)) | 0x4510FC82L), l_431)) > 2UL) != l_1643[0][3][1])));
                    }
                }
                else
                {
                    g_120[4] = l_419;
                    if (l_1671)
                        break;
                }

{
                int16_t l_775 = (-4L);
                int32_t l_776 = (-3L);
                l_1887 = ((((l_210 ^ (l_1888[2] , (0xB43536D7L > 0x43474B68L))) >= (((g_18 < ((safe_add_func_int8_t_s_s(l_616, 0xFAL)) & (safe_mod_func_int8_t_s_s(((((((l_775 | l_776) || l_261) || l_1854) , l_1905) <= 6L) <= 0x62L), 0x36L)))) && l_210) > 0x8EL)) != l_1905) == l_1905);
            }

                    ++l_1699;
            }
            else
            {
                int8_t l_1702[4] = {0x92L, 1L, 0x92L, 1L};
                int32_t l_1703 = (-7L);
                int32_t l_1704[7][6][6] = {{{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}};
                uint8_t l_1730[3][2];
                uint32_t l_1764 = 0x54F33472L;
                int i, j, k;

{
                    for (g_89 = 3; (g_89 >= 1); g_89 -= 1)
                    {
                        int i;
                        if (g_120[g_89])
                            break;
                        if (l_1888[g_89])
                            break;
                        return l_472;
                    }
                }

                    for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 2; j++)
                        l_1730[i][j] = 0x7BL;
                }
                g_120[2] = g_1548[4][6][2];
                --l_1706;
                if ((((p_40 < ((safe_sub_func_int8_t_s_s(g_1540[1][0], (((((((1L | (l_1643[4][0][3] != ((safe_sub_func_int16_t_s_s(((safe_sub_func_int32_t_s_s(g_1548[9][3][2], (((((safe_add_func_uint16_t_u_u((!l_1699), g_120[0])) != ((safe_sub_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u((0UL != ((l_258 > l_1698) , l_1671)), 6)), l_1703)), l_1724)) < 255UL)) , l_1537) == l_1725) < l_1489[2][4][7]))) > l_1726), (-10L))) == p_39))) , 0x853A9528L) != 1UL) , l_1706) >= 0x1C39L) == 0xF5678FABL) , 0xD3L))) < 0x7EB415D5L)) != g_143) || 4294967289UL))
                {
                    int32_t l_1727 = 0L;
                    int32_t l_1728 = 4L;
                    int32_t l_1729[4][6][7] = {{{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}};
                    int i, j, k;
                    --l_1730[2][0];
                }
                else
                {
                    uint16_t l_1751 = 0UL;

{
            const uint32_t l_1522[6][9] = {{0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}};
            uint16_t l_1591 = 7UL;
            int32_t l_1599 = 0x10CC3626L;
            int16_t l_1633 = 0x164AL;
            int32_t l_1634 = 0x157EBADBL;
            int32_t l_1643[6][4][8] = {{{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}};
            uint32_t l_1659 = 0x83EA5D3CL;
            uint32_t l_1699 = 0x2C42C799L;
            uint16_t l_1706 = 0x0899L;
            int32_t l_1806 = 0x9CB7724BL;
            uint32_t l_1837 = 3UL;
            uint32_t l_1846 = 0xD008E7A8L;
            int i, j, k;
            if (((!(safe_add_func_int32_t_s_s((l_210 || l_210), ((((safe_lshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s((0x15L <= (l_258 <= ((safe_add_func_uint16_t_u_u((!g_849[0]), ((((safe_sub_func_int32_t_s_s(((((l_198 , ((l_198 | ((((((safe_sub_func_uint8_t_u_u((l_2178[1] <= l_1489[2][7][0]), (-1L))) ^ l_351) | l_1659) , 255UL) , l_210) < g_120[0])) < l_198)) ^ g_2468) , l_1522[4][1]) < l_351), 4294967295UL)) != 0x6AL) || g_18) >= l_210))) < g_59))), l_699)) , 0x5997L), l_210)) <= l_699) , l_1522[0][5]) <= l_253)))) == l_1522[4][1]))
            {
                uint32_t l_1543 = 7UL;
                int32_t l_1547 = (-6L);
                int32_t l_1640 = 0x4E27C546L;
                int32_t l_1641 = 1L;
                int32_t l_1646 = 0xFBA92B18L;
                int32_t l_1647 = 0xBA2A75F3L;
                int32_t l_1649 = 0L;
                int32_t l_1650 = (-1L);
                int32_t l_1652 = (-1L);
                int32_t l_1654 = (-5L);
                int32_t l_1655 = 0L;
                int32_t l_1697 = 0L;
                for (l_210 = 5; (l_210 != 57); ++l_210)
                {
                    int32_t l_1533[2][4] = {{0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}, {0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}};
                    int32_t l_1542[8][7][3] = {{{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}};
                    int i, j, k;
                    if (((0UL <= (safe_rshift_func_int8_t_s_u(l_198, 5))) & (((((((l_253 , ((safe_add_func_int32_t_s_s(0L, (safe_mod_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((((l_253 == l_1533[1][2]) && (((l_210 && ((l_1489[3][7][5] & 0x189D8138L) & l_351)) ^ g_97[2]) | g_59)) <= (-6L)), 12)), 0x4AL)))) & g_59)) <= l_198) == 1L) || g_2468) | g_2468) > 0xA7L) & 1L)))
                    {
                        l_262 &= ((safe_rshift_func_uint8_t_u_s((((l_253 ^ (~((g_97[2] == l_253) , l_1751))) | (l_1522[2][7] | (((g_89 || g_59) , (((0x07L == (-1L)) < 0xBECEL) || l_1533[1][2])) ^ g_97[1]))) , 255UL), 1)) && (-1L));
                        g_120[2] = (safe_add_func_int32_t_s_s(g_89, l_2178[1]));
                        g_120[1] = g_1540[1][0];
                    }
                    else
                    {
                        int8_t l_1541 = (-1L);
                        int32_t l_1546 = 0x3C02C0E7L;
                        uint32_t l_1550 = 1UL;
                        l_1543++;
                        if (l_1489[0][4][1])
                            continue;
                        --l_1550;
                    }
                    for (l_262 = 10; (l_262 >= 5); l_262 = safe_sub_func_uint32_t_u_u(l_262, 6))
                    {
                        int16_t l_1581 = 0x4CE7L;
                        if (l_210)
                            break;
                        g_120[1] = (l_1634 || (0xA427L == (safe_mod_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((l_2178[1] == 1UL), (-1L))), 0x2E3AL))));
                        g_120[1] = ((+(l_198 < ((((((safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((~l_351), ((safe_lshift_func_int8_t_s_s(l_1547, (safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((+((safe_add_func_int8_t_s_s((0UL != (((safe_rshift_func_int8_t_s_u((g_89 > l_2178[2]), 1)) == (safe_unary_minus_func_int8_t_s((l_210 , (safe_rshift_func_uint8_t_u_s((((safe_mod_func_int8_t_s_s((0x71L >= l_1581), 0xB6L)) , l_210) <= l_253), 3)))))) && g_143)), 0UL)) ^ l_1522[0][5])) & 1UL), l_210)), 13)))) , 0x89L))), l_198)) != l_262) , l_1751) || 65531UL) > l_253) < 0x33D41A9EL))) , l_86);
                    }

{
    uint32_t l_27 = 4294967294UL;
    l_27 = 0x31AA08ECL;
    g_120[1] = (0x0415L > ((func_28((l_27 , (safe_mod_func_int16_t_s_s(func_33((safe_mod_func_int32_t_s_s(((func_38((l_27 < l_1504), ((safe_lshift_func_int16_t_s_u(1L, 3)) , (((((l_1751 && func_46(((((safe_lshift_func_uint8_t_u_u(0UL, (func_54((0x373CL && (0x7530L < 2UL)), l_1751, l_1751, l_27) >= g_18))) == l_1504) >= 0xD45AA775L) > l_27), l_1751, l_1751, g_18, l_27)) != l_1751) < l_1751) != 0xE6DB759FL) != l_1504)), l_27, l_1504, l_27) ^ l_1751) != l_1751), 0xDA6413EFL)), l_1751), g_18))), l_1751) ^ 5UL) == l_1699));
    for (g_59 = 26; (g_59 == 51); g_59++)
    {
        uint8_t l_1466 = 254UL;
        int32_t l_1481 = 7L;
        g_120[1] = l_1466;
        l_1481 = (((g_97[2] > l_1751) | (safe_add_func_uint8_t_u_u(0x65L, ((!((safe_rshift_func_int8_t_s_s(((0x0584L < (l_1466 && (safe_lshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s((((!(l_1751 , ((safe_mod_func_uint8_t_u_u(l_1466, l_1504)) , (safe_sub_func_int8_t_s_s((0xCDL > l_1726), 0xCFL))))) < 255UL) < 0xB6L), l_1466)), l_1751)))) , 0x19L), l_1466)) > 0xBFD8L)) == 0UL)))) >= l_27);
    }
    return l_1751;
}

                    for (l_351 = 0; (l_351 <= 4); l_351 += 1)
                    {
                        int16_t l_1588[5][10][5] = {{{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}};
                        const int16_t l_1592 = (-1L);
                        int i, j, k;
                        g_120[l_351] = ((safe_sub_func_int32_t_s_s(l_351, 0xC58F4B07L)) ^ ((((((-1L) > (((((safe_add_func_int8_t_s_s(((((safe_sub_func_uint32_t_u_u(((l_1588[4][3][4] | (0xBBL | g_97[2])) ^ l_1542[2][5][1]), (l_198 , (safe_lshift_func_uint16_t_u_u(((0x8B2D6D5DL < (-6L)) < 0x8664AFBBL), 8))))) & l_210) > 7L) >= l_1591), l_1588[1][8][4])) && l_210) == 1UL) , l_1592) && g_97[2])) || g_89) <= l_210) || l_1751) >= l_1533[1][2]));
                        return l_1634;
                    }
                }
                if ((((safe_rshift_func_uint8_t_u_s(l_1634, 4)) >= (safe_lshift_func_uint8_t_u_s(l_1591, (safe_lshift_func_int8_t_s_s(l_1599, 1))))) != ((safe_lshift_func_int16_t_s_u((!(((l_198 >= l_1547) , ((!g_849[0]) >= ((g_89 <= (!(((safe_rshift_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_u((((l_351 > 0L) ^ l_253) < l_1504), l_198)) || 0x729EL) > 0xD46FL), 2)) < g_97[2]) , 6UL))) || l_198))) | l_1489[2][4][7])), 12)) == l_198)))
                {
                    uint16_t l_1611 = 0xD966L;
                    int32_t l_1636 = 1L;
                    int32_t l_1638[4][6][7] = {{{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}};
                    uint8_t l_1656[3][8][6] = {{{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}};
                    int i, j, k;
                    g_120[1] = ((((l_210 & ((safe_mul_func_uint8_t_u_u(l_1611, ((((g_2468 | (safe_mod_func_int8_t_s_s(l_253, (safe_lshift_func_uint16_t_u_u((((((((+(g_2468 , ((l_1504 & (safe_lshift_func_uint16_t_u_s((((+(((((((l_351 <= (((((l_253 & ((0x4BA9L | 0xAB14L) == 0xB0E53EB1L)) == 0x49L) >= l_1659) && l_253) < l_1611)) > 0x891AL) ^ 0xC4L) >= l_419) > l_1599) ^ g_849[0]) < l_1591)) & 0x2C1DL) >= 0L), 14))) , l_1659))) & l_351) != 0x3AL) , l_198) && g_89) ^ l_253) >= l_198), 1))))) && l_210) >= l_1522[4][1]) <= 0x012802EEL))) ^ 0x6FL)) | l_198) != 4294967290UL) | g_120[4]);
                    if ((l_1489[2][4][7] <= (g_97[0] <= g_2468)))
                    {
                        int32_t l_1635 = 0L;
                        int32_t l_1637 = 1L;
                        int32_t l_1642 = (-3L);
                        int32_t l_1645[4][10][3] = {{{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}};
                        int8_t l_1653 = 0xE0L;
                        int i, j, k;
                        l_1634 = (((((safe_mod_func_uint16_t_u_u((safe_unary_minus_func_uint8_t_u((safe_sub_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((l_253 ^ (((((safe_mod_func_uint8_t_u_u(((((safe_add_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(((l_210 && (((l_198 , g_2468) > (l_253 & l_1659)) >= (-2L))) == ((-1L) & ((0x2C2C4A06L || 0L) != l_699))), 0x84D0E611L)) < 247UL), l_262)) == g_1540[0][1]) != 65535UL) != (-5L)), l_1599)) , g_143) , l_1611) == l_198) && 9L)) >= 0x3E95L), l_253)), l_210)))), 65530UL)) >= l_1634) | 0xA236F820L) , l_1611) < l_1633);
                        l_1656[1][6][4]++;
                        ++l_1659;
                    }
                    else
                    {
                        int32_t l_1692 = 1L;
                        g_22 = (((safe_mod_func_uint16_t_u_u((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u((((l_368 , ((((g_101 != l_1611) >= (safe_sub_func_uint8_t_u_u(0xEEL, g_849[0]))) <= l_1659) != (1UL & l_198))) && (!(l_368 >= l_1644[2][1][0]))) || l_1641), (-2L))), 1UL)), g_120[1])) > 0x1BL) | 0xC3L);
                        g_120[1] = (+1UL);
                        l_1643[3][1][5] = (safe_add_func_uint32_t_u_u(0UL, (((safe_rshift_func_uint16_t_u_u(((safe_mod_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((~l_253), ((0x60L ^ ((l_368 == ((((((-1L) == ((0x4B8FL == (l_198 | (((6L | (safe_rshift_func_uint16_t_u_u(((((((((safe_lshift_func_int8_t_s_u(((~(((((safe_mod_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(((!(1UL != g_89)) > l_1522[2][7]), g_120[1])), l_1638[0][0][2])) < 4294967295UL) , l_210) , 0xE3L) , 0x49L)) && 0x109AL), 6)) , l_351) || 4294967288UL) < 0x758ECAE5L) , l_210) > l_1692) != g_120[4]) == 0x90143625L), g_120[0]))) != l_198) | g_18))) | (-1L))) > l_210) > l_351) , l_210) != l_210)) < l_1692)) < g_18))), l_198)) | 0x4510FC82L), l_419)) > 2UL) != l_1643[0][3][1])));
                    }
                }
                else
                {
                    g_120[4] = l_210;
                    if (g_22)
                        break;
                }
                ++l_1699;
            }
            else
            {
                int8_t l_1702[4] = {0x92L, 1L, 0x92L, 1L};
                int32_t l_1703 = (-7L);
                int32_t l_1704[7][6][6] = {{{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}};
                uint8_t l_1730[3][2];
                uint32_t l_1764 = 0x54F33472L;
                int i, j, k;
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 2; j++)
                        {
if (l_210)
                    break;

                    l_1730[i][j] = 0x7BL;}
                }
                g_120[2] = g_1548[4][6][2];
                --l_1706;
                if ((((l_699 < ((safe_sub_func_int8_t_s_s(g_1540[1][0], (((((((1L | (l_1643[4][0][3] != ((safe_sub_func_int16_t_s_s(((safe_sub_func_int32_t_s_s(g_1548[9][3][2], (((((safe_add_func_uint16_t_u_u((!l_1699), g_120[0])) != ((safe_sub_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u((0UL != ((l_198 > g_2100) , g_22)), 6)), l_1703)), g_2468)) < 255UL)) , l_262) == g_100) < l_1489[2][4][7]))) > p_42), (-10L))) == l_253))) , 0x853A9528L) != 1UL) , l_1706) >= 0x1C39L) == 0xF5678FABL) , 0xD3L))) < 0x7EB415D5L)) != l_1659) || 4294967289UL))
                {
                    int32_t l_1727 = 0L;
                    int32_t l_1728 = 4L;
                    int32_t l_1729[4][6][7] = {{{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}};
                    int i, j, k;
                    --l_1730[2][0];
                }
                else
                {
                    uint16_t l_1751 = 0UL;
                    for (g_89 = 0; (g_89 <= 3); g_89 += 1)
                    {
                        int i, j, k;
                        l_1644[g_89][g_89][g_89] ^= (safe_lshift_func_uint8_t_u_u((l_1489[g_89][(g_89 + 2)][g_89] >= (safe_add_func_int32_t_s_s(0x76753DFBL, ((safe_rshift_func_uint8_t_u_s((safe_mod_func_int16_t_s_s(5L, (safe_lshift_func_int16_t_s_u((((safe_lshift_func_uint16_t_u_u(g_1482[2][1][1], 6)) < ((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(0xAAD7L, (((safe_add_func_int32_t_s_s((l_1751 && (((safe_add_func_uint8_t_u_u((((((~(l_1842 , (((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s((l_2178[1] || (((((+(safe_lshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u(l_1634, 9UL)), l_351))) , l_253) , l_699) != 0xB3L) > l_253)), 6L)), 0x65A1L)) != 65533UL) >= l_1751))) >= l_1764) | l_1730[2][0]) , l_1751) , l_1751), 0UL)) <= g_1548[5][0][1]) && 255UL)), l_419)) ^ g_89) >= g_97[2]))), l_198)) , l_210)) | l_1751), g_2100)))), l_1751)) & l_210)))), l_419));
                    }
                    l_368 = (l_1489[3][7][7] > ((g_1548[4][6][2] ^ (!((((((safe_rshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s(0x2D2C9E59L, (l_1764 | (safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(((((((l_1751 == ((l_253 == (safe_sub_func_uint16_t_u_u(((((l_1659 & (safe_add_func_uint16_t_u_u((0L > ((((l_86 && l_1702[3]) >= l_198) & 0x3E3BL) , l_1730[2][0])), g_120[1]))) , 8L) , 0L) & l_1659), l_210))) || l_1764)) >= l_419) == l_1643[2][2][1]) == 0x34FBL) | 0x6190L) | l_198), l_198)) >= l_253), l_198)) < 0x90L), g_143)) & 0x68AFL), l_699)) , l_351), g_89))))), g_2468)), l_198)) || 4294967286UL), 13)) <= l_198) ^ 1L) , g_89) <= l_1751) & 0xABL))) | l_1706));
                    l_1643[0][3][1] ^= l_1751;
                }
                return l_198;
            }
            for (l_1634 = 0; (l_1634 >= 17); l_1634 = safe_add_func_int16_t_s_s(l_1634, 4))
            {
                const uint32_t l_1798[7][8] = {{0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}};
                int i, j;
                l_1799[1][5] = ((6L ^ (safe_rshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s(((((((l_1751 ^ (((0L >= (((safe_lshift_func_uint8_t_u_u(0x33L, l_210)) ^ l_1699) , (safe_lshift_func_int8_t_s_s(l_351, 1)))) == ((((l_1489[2][4][7] , (l_1798[3][0] && l_262)) & 1UL) & g_1540[0][1]) & g_849[0])) >= l_2178[2])) || 2L) , g_120[1]) | 9UL) , g_1548[1][1][0]) && 1UL), l_1699)), 0))) >= 0x9FEE1EABL);
            }
            g_120[1] |= (((g_849[0] <= (safe_add_func_int32_t_s_s(l_210, l_210))) <= ((((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u((l_253 && ((l_210 == l_1806) > ((safe_rshift_func_int16_t_s_u(((((((g_97[2] | l_198) && ((!((safe_rshift_func_int16_t_s_s(((0L | l_1634) , l_253), l_419)) ^ g_2100)) ^ 0L)) == l_198) , 1L) || 0xE5L) <= l_86), 15)) || l_1806))), 3)) > l_351) ^ l_210), l_1659)) ^ l_2178[1]) || 1L) != (-5L)) , 4294967290UL) <= l_210)) ^ 0x02D0829CL);
            if ((safe_lshift_func_int8_t_s_s(0xBCL, 7)))
            {
                int8_t l_1831 = (-6L);
                int32_t l_1849[6] = {(-1L), 6L, (-1L), 6L, (-1L), 6L};
                const uint8_t l_1889 = 252UL;
                int i;
                for (l_1706 = 0; (l_1706 >= 36); l_1706 = safe_add_func_uint32_t_u_u(l_1706, 3))
                {
                    int32_t l_1836[9][5] = {{(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}};
                    int32_t l_1841 = (-3L);
                    int32_t l_1844 = 8L;
                    int32_t l_1845 = 0xBE0388A2L;
                    int16_t l_1853 = 0xBF53L;
                    uint16_t l_1856 = 0x14A1L;
                    int i, j;
                    g_120[4] ^= (((safe_add_func_uint32_t_u_u((0x22L == (((((l_656 , (((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((~((((((l_2178[2] >= ((0xEF5AL != (safe_sub_func_int8_t_s_s(((g_1482[2][1][1] && ((safe_add_func_int8_t_s_s((((safe_sub_func_uint16_t_u_u(((((l_1831 | (((l_198 > g_1540[1][0]) >= (((safe_rshift_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((l_2178[2] > 0x5C49CB64L), 5)) | l_1831) , l_1836[4][3]) == l_2178[1]) && l_86), l_351)) >= 0x624C7317L) == l_253)) <= l_198)) , l_198) , 1UL) , g_849[0]), 0xF010L)) ^ 0UL) <= g_849[0]), l_351)) > 1L)) & g_2100), l_253))) == 0xE4B6B42FL)) | l_1799[2][5]) , 0L) >= l_1751) & l_1699) , l_1489[0][3][5])), 10)), l_210)) == g_97[2]) >= l_210)) || l_351) , l_1831) == l_253) ^ g_849[0])), l_198)) | l_1837) , g_2468);
                    for (l_258 = 13; (l_258 >= 1); l_258 = safe_sub_func_int32_t_s_s(l_258, 9))
                    {
                        uint8_t l_1840 = 0x4FL;
                        int32_t l_1843 = 1L;
                        int32_t l_1850 = (-10L);
                        int32_t l_1851 = 0x86429966L;
                        int32_t l_1852 = 0xCA3D88B8L;
                        int32_t l_1855 = 1L;
                        l_1840 = l_1751;
                        --l_1846;
                        --l_1856;
                    }
                    for (l_1841 = (-19); (l_1841 != (-8)); l_1841++)
                    {
                        uint16_t l_1886[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_1886[i] = 7UL;
                        g_120[1] &= l_1696[0];

l_1643[0][3][1] ^= p_43;

                    g_120[0] = (((((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u(65535UL, 13)) , 0x9426L), (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_u(l_253, (((((0xEF2D849BL || l_1591) & (l_1841 , (safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u((((((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s(l_419, (safe_rshift_func_uint16_t_u_s((((l_1799[1][5] > (safe_add_func_uint16_t_u_u(0x2E1AL, 0xBDC1L))) >= l_1836[0][4]) == l_1886[0]), 13)))) | (-2L)), l_431)) & l_198) < 0xBEL) < g_143) & l_1888[2]), 0x66L)), l_210)), 4)), 7)), 0UL)))) , 1UL) ^ l_1889) == 0xEAL))))))) > 0x483D69BBL) , l_1844) , 247UL) ^ l_1706);
                        l_1644[0][3][4] = ((((-2L) == (safe_add_func_uint16_t_u_u((((((((((safe_add_func_int32_t_s_s(((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s((safe_mod_func_int8_t_s_s((251UL != ((!g_143) == (((g_97[1] | (safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s(0xF54AL, 2)) && ((((l_210 > ((((l_1853 & (safe_add_func_uint16_t_u_u(0x3ED4L, 1L))) ^ l_253) | 1L) ^ l_1849[1])) > (-1L)) && l_351) != 0UL)), 0xEB10B25CL)), 10))) < g_1482[2][1][1]) || 0x405D3F2AL))), l_1599)), 1)), 2)) && l_1751), 5)) && 4294967295UL), 4294967293UL)) , l_253), 4294967288UL)) | l_198) || l_198) && l_368) && l_253) && 0x068C0922L) , l_258) , (-1L)) < l_210), 1UL))) ^ l_1846) || l_1699);
                        l_2055 = (safe_lshift_func_uint8_t_u_s(l_198, ((safe_rshift_func_int8_t_s_s(9L, l_351)) != l_1846)));
                    }
                }
                g_120[1] ^= ((l_198 & (0x8889L >= (l_253 == ((safe_unary_minus_func_uint8_t_u(0UL)) <= (safe_mod_func_int16_t_s_s(g_1482[3][0][1], ((l_253 > (((~l_210) && ((~(!((((safe_sub_func_uint16_t_u_u((((((((l_198 < ((((l_253 , l_253) >= 0x93L) , 1UL) ^ l_699)) ^ l_210) == l_1889) & 0UL) , g_89) < l_1799[4][4]) < 4294967295UL), l_1849[0])) <= 1L) , l_198) , 0x3CL))) , l_210)) >= 7L)) & l_656))))))) | l_1831);

{
                    uint16_t l_1611 = 0xD966L;
                    int32_t l_1636 = 1L;
                    int32_t l_1638[4][6][7] = {{{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}};
                    uint8_t l_1656[3][8][6] = {{{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}};
                    int i, j, k;
                    g_120[1] = ((((l_1905 & ((safe_mul_func_uint8_t_u_u(l_1611, ((((l_1724 | (safe_mod_func_int8_t_s_s(p_39, (safe_lshift_func_uint16_t_u_u((((((((+(l_1724 , ((g_22 & (safe_lshift_func_uint16_t_u_s((((+(((((((l_351 <= (((((p_39 & ((0x4BA9L | 0xAB14L) == 0xB0E53EB1L)) == 0x49L) >= g_1168) && p_39) < l_1611)) > 0x891AL) ^ 0xC4L) >= l_1887) > l_1842) ^ g_849[0]) < g_2414)) & 0x2C1DL) >= 0L), 14))) , g_1168))) & g_2254) != 0x3AL) , l_86) && l_1831) ^ p_39) >= l_86), 1))))) && l_1905) >= l_1522[4][1]) <= 0x012802EEL))) ^ 0x6FL)) | l_86) != 4294967290UL) | g_120[4]);
                    if ((l_1489[2][4][7] <= (g_97[0] <= l_1724)))
                    {
                        int32_t l_1635 = 0L;
                        int32_t l_1637 = 1L;
                        int32_t l_1642 = (-3L);
                        int32_t l_1645[4][10][3] = {{{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}};
                        int8_t l_1653 = 0xE0L;
                        int i, j, k;
                        l_1549 = (((((safe_mod_func_uint16_t_u_u((safe_unary_minus_func_uint8_t_u((safe_sub_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((p_39 ^ (((((safe_mod_func_uint8_t_u_u(((((safe_add_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(((l_1905 && (((l_86 , l_1724) > (p_39 & g_1168)) >= (-2L))) == ((-1L) & ((0x2C2C4A06L || 0L) != l_1854))), 0x84D0E611L)) < 247UL), l_1695)) == g_1540[0][1]) != 65535UL) != (-5L)), l_1842)) , l_326) , l_1611) == l_86) && 9L)) >= 0x3E95L), p_39)), l_1905)))), 65530UL)) >= l_2055) | 0xA236F820L) , l_1611) < l_2182);
                        l_1656[1][6][4]++;
                        ++g_1168;
                    }
                    else
                    {
                        int32_t l_1692 = 1L;
                        g_143 = (((safe_mod_func_uint16_t_u_u((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u((((l_1639 , ((((l_472 != l_1611) >= (safe_sub_func_uint8_t_u_u(0xEEL, g_849[0]))) <= g_1168) != (1UL & l_86))) && (!(l_1639 >= l_1644[2][1][0]))) || l_1695), (-2L))), 1UL)), g_120[1])) > 0x1BL) | 0xC3L);
                        g_120[1] = (+1UL);
                        l_1643[3][1][5] = (safe_add_func_uint32_t_u_u(0UL, (((safe_rshift_func_uint16_t_u_u(((safe_mod_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((~p_39), ((0x60L ^ ((l_1639 == ((((((-1L) == ((0x4B8FL == (l_86 | (((6L | (safe_rshift_func_uint16_t_u_u(((((((((safe_lshift_func_int8_t_s_u(((~(((((safe_mod_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(((!(1UL != l_296)) > l_1522[2][7]), g_120[1])), l_1638[0][0][2])) < 4294967295UL) , l_1905) , 0xE3L) , 0x49L)) && 0x109AL), 6)) , g_2254) || 4294967288UL) < 0x758ECAE5L) , l_1905) > l_1692) != g_120[4]) == 0x90143625L), g_120[0]))) != l_86) | l_1889))) | (-1L))) > l_1905) > l_351) , l_1905) != l_1905)) < l_1692)) < l_1889))), l_86)) | 0x4510FC82L), l_1887)) > 2UL) != l_1643[0][3][1])));
                    }
                }

                    l_1643[0][3][1] = (l_258 > 0x5B7FL);
            }
            else
            {
                uint32_t l_1932 = 1UL;
                int32_t l_1945 = 0L;
                int32_t l_1946[1];
                uint32_t l_1971 = 0x9EF11B35L;
                uint8_t l_1990 = 0xB6L;
                int i;
                for (i = 0; i < 1; i++)
                    l_1946[i] = 3L;
                for (l_351 = (-11); (l_351 < (-24)); --l_351)
                {
                    int32_t l_1929 = 0L;
                    int32_t l_1930 = 0x01C56913L;
                    uint8_t l_1949 = 0xBEL;
                    int32_t l_2005 = 0L;
                    if (l_198)
                    {
                        int32_t l_1928[10] = {0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L};
                        int i;
                        l_1932--;
                    }
                    else
                    {
                        l_2055 = l_253;
                    }

{
                transparent_crc(g_2470[l_392][l_2055][j], "g_2470[l_392][l_2055][j]", l_367);
                if (l_367) printf("index = [%d][%d][%d]\n", l_392, l_2055, j);

            }

                    if ((l_198 , l_1842))
                    {
                        int8_t l_1947 = 0x1BL;
                        int32_t l_1948 = 0x27F08C10L;
                        l_1945 = (((0x03L == (0xA11DL < (l_86 | ((((0x6F1BL != g_101) < (((((((((safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(g_97[2], l_258)), 2)) > (safe_add_func_uint16_t_u_u(g_1548[4][6][2], 0x34DEL))) & l_210), l_1706)) , 0x3208L) , g_1540[1][0]) , l_1930) == l_351) , g_1548[0][0][1]) <= l_1932) > l_210) >= 0UL)) < l_210) >= l_253)))) ^ g_97[2]) , g_849[0]);

if (l_1726)
                continue;

                    ++l_1949;
                        g_120[4] = (safe_mod_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(6L, (safe_sub_func_uint8_t_u_u(0x94L, (((l_1949 | (safe_rshift_func_int8_t_s_u(((((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((((+(safe_add_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(((0xB3EFL || (l_1947 | (((g_120[1] ^ ((((-2L) & (((l_210 ^ (l_1945 , 0x78L)) , l_1971) < l_253)) < 0xA9FBL) == l_253)) < l_1806) < 0xE1L))) && l_1948), 0x64L)) , l_253), 9UL))) >= 0x60B3L) != l_253) ^ l_253), l_198)), 0x0DAEL)), l_431)) >= l_1947) > l_253) == l_210), l_1948))) , 5L) | 0xB082A17BL))))) , 0x11L), 0x03L));
                    }
                    else
                    {
                        l_1930 = ((0L & l_253) != (!((safe_mod_func_uint8_t_u_u(l_198, 0x7AL)) > (((l_1932 | l_253) , 0x1F0EL) < (l_210 && ((((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u(l_296, l_210)), 0x3929L)) != 0L) == 0x2F747C30L) , 0x96347F98L))))));
                    }
                    if (((safe_lshift_func_uint16_t_u_s((g_1540[1][0] , l_1930), l_210)) & (((g_101 < (((((safe_lshift_func_int16_t_s_u(((l_253 , ((l_210 && (((safe_unary_minus_func_int16_t_s(((safe_add_func_uint16_t_u_u(l_2055, ((((safe_add_func_uint16_t_u_u((l_1591 ^ l_253), l_1990)) < l_210) < 0x1D1DL) | l_351))) | g_120[1]))) , l_253) && l_1643[1][1][6])) ^ g_89)) , l_253), l_1599)) | l_210) <= 0UL) != (-8L)) , l_253)) < g_2100) || 0x837FL)))
                    {
                        int8_t l_2002 = 0x5BL;
                        int32_t l_2004[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_2004[i] = 7L;
                        g_2003[0] |= (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u(g_1482[0][1][0], ((~((((-6L) < l_210) >= g_120[1]) | (l_210 , l_210))) != (((safe_lshift_func_uint16_t_u_s(((g_1548[4][6][2] || ((((safe_rshift_func_int8_t_s_s(1L, 4)) <= 0xC812E52FL) || l_2178[1]) <= 0UL)) , l_1888[1]), 3)) != l_253) < 65535UL)))) | g_1482[2][1][1]) <= 4294967292UL) && l_1929) > l_2002), g_849[0])), l_198));

{
                        int i, j, k;
                        l_1644[l_296][l_296][l_296] ^= (safe_lshift_func_uint8_t_u_u((l_1489[l_296][(l_296 + 2)][l_296] >= (safe_add_func_int32_t_s_s(0x76753DFBL, ((safe_rshift_func_uint8_t_u_s((safe_mod_func_int16_t_s_s(5L, (safe_lshift_func_int16_t_s_u((((safe_lshift_func_uint16_t_u_u(g_1482[2][1][1], 6)) < ((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(0xAAD7L, (((safe_add_func_int32_t_s_s((l_389 && (((safe_add_func_uint8_t_u_u((((((~(j , (((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s((g_1368[1] || (((((+(safe_lshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u(l_1634, 9UL)), p_42))) , l_1703) , l_1725) != 0xB3L) > l_1703)), 6L)), 0x65A1L)) != 65533UL) >= l_389))) >= l_1905) | l_1730[2][0]) , l_389) , l_389), 0UL)) <= g_1548[5][0][1]) && 255UL)), l_1887)) ^ l_296) >= g_97[2]))), l_198)) , l_1887)) | l_389), g_2469)))), l_389)) & l_1887)))), l_1887));
                    }

                    g_59--;
                        if (l_1888[1])
                            break;
                    }
                    else
                    {
                        uint8_t l_2013[2][2] = {{1UL, 0x0EL}, {1UL, 0x0EL}};
                        int i, j;
                        g_120[1] = (safe_rshift_func_int16_t_s_u((((safe_sub_func_uint8_t_u_u((0xBC96E130L > l_2013[1][0]), ((safe_add_func_uint8_t_u_u(((l_2005 >= (((safe_add_func_uint8_t_u_u((((g_100 & l_2013[0][1]) , ((safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(g_1548[4][6][2], l_1932)) , ((safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((l_210 ^ ((safe_mod_func_uint16_t_u_u((65534UL <= l_1634), l_210)) , g_120[3])) || l_1591), g_97[1])) > l_1659), (-4L))) > 7L)), l_1949)) == l_1888[2])) < l_198), 9UL)) | l_2178[1]) & l_368)) <= l_1930), 0x27L)) & 9UL))) && l_198) , 0x1E18L), g_18));
                    }
                    g_120[1] = ((((0UL == (0x99L == g_1482[2][1][1])) , l_2028) , g_97[2]) > ((g_120[3] > ((((((safe_lshift_func_uint16_t_u_s(((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s(((0x83922D4EL != ((-8L) > 0x08L)) || l_1634), 5)), g_22)) >= l_1634), 15)) < l_253) , 0xAC9FE61AL) , l_253) > l_210) | g_1540[1][0])) ^ (-1L)));
                }
            }
        }

                    for (l_699 = 0; (l_699 <= 3); l_699 += 1)
                    {
                        int i, j, k;
                        l_1644[l_699][l_699][l_699] ^= (safe_lshift_func_uint8_t_u_u((l_1489[l_699][(l_699 + 2)][l_699] >= (safe_add_func_int32_t_s_s(0x76753DFBL, ((safe_rshift_func_uint8_t_u_s((safe_mod_func_int16_t_s_s(5L, (safe_lshift_func_int16_t_s_u((((safe_lshift_func_uint16_t_u_u(g_1482[2][1][1], 6)) < ((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(0xAAD7L, (((safe_add_func_int32_t_s_s((l_1751 && (((safe_add_func_uint8_t_u_u((((((~(l_1695 , (((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s((g_1368[1] || (((((+(safe_lshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u(l_1549, 9UL)), g_935))) , p_39) , p_40) != 0xB3L) > p_39)), 6L)), 0x65A1L)) != 65533UL) >= l_1751))) >= l_1764) | l_1730[2][0]) , l_1751) , l_1751), 0UL)) <= g_1548[5][0][1]) && 255UL)), l_431)) ^ p_40) >= g_97[2]))), l_258)) , l_419)) | l_1751), l_1698)))), l_1751)) & l_419)))), l_431));
                    }
                    l_1651 = (l_1489[3][7][7] > ((g_1548[4][6][2] ^ (!((((((safe_rshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s(0x2D2C9E59L, (l_1764 | (safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(((((((l_1751 == ((p_39 == (safe_sub_func_uint16_t_u_u(((((g_143 & (safe_add_func_uint16_t_u_u((0L > ((((g_59 && l_1702[3]) >= l_258) & 0x3E3BL) , l_1730[2][0])), g_120[1]))) , 8L) , 0L) & l_1659), l_419))) || l_1764)) >= l_431) == l_1643[2][2][1]) == 0x34FBL) | 0x6190L) | l_258), l_258)) >= p_39), l_258)) < 0x90L), g_2467)) & 0x68AFL), p_40)) , l_351), p_40))))), l_1724)), l_258)) || 4294967286UL), 13)) <= l_258) ^ 1L) , p_40) <= l_1751) & 0xABL))) | l_1706));

{
                    int8_t l_362 = 0x43L;
                    int32_t l_366 = (-2L);
                    uint8_t l_369 = 0x5AL;
                    int32_t l_393 = 0L;
                    if ((safe_add_func_int16_t_s_s(((((l_213[1] || ((l_389 >= (+(-1L))) >= (safe_lshift_func_int8_t_s_s(((safe_sub_func_int8_t_s_s((((safe_mod_func_int16_t_s_s(((safe_lshift_func_int16_t_s_s(g_2431, 2)) == (((safe_lshift_func_uint16_t_u_s((l_86 || ((safe_rshift_func_uint16_t_u_s((((safe_add_func_int16_t_s_s(((((((safe_mod_func_int16_t_s_s(p_43, l_86)) <= 0x56719CF5L) < ((+(((((1UL && 0xD84E0731L) > l_281[6][4]) < l_1846) > 0x15L) & 0xF7L)) | l_1846)) , l_389) == g_2414) , l_1634), 0xA7B5L)) , 2L) , g_540), 11)) >= g_101)), l_431)) , 0x25L) < 7UL)), l_86)) <= 1UL) , l_431), l_86)) ^ 246UL), g_18)))) <= 0x83L) >= 6UL) & g_97[2]), l_1634)))
                    {
                        uint32_t l_364 = 0UL;
                        int32_t l_365 = 1L;
                        l_364 = ((safe_add_func_int8_t_s_s((((safe_lshift_func_uint16_t_u_u(((((l_2182 != g_89) > ((safe_lshift_func_uint16_t_u_u((0xA1L != (((-6L) && (((safe_rshift_func_int8_t_s_u(0x08L, ((p_43 < ((g_97[2] | (((safe_sub_func_uint16_t_u_u((((l_362 != 0xFEFA8AE2L) , g_101) != g_97[2]), l_1854)) && 0x6386802AL) >= g_97[1])) >= l_1854)) , l_1634))) < 2UL) && l_281[4][6])) != g_2431)), 0)) ^ l_1634)) != g_97[2]) || 0xF9L), l_262)) || 0xD2L) , l_389), (-7L))) && l_389);
                        ++l_369;
                        if (l_281[4][3])
                            break;
                        l_366 = l_1634;
                    }
                    else
                    {
                        uint32_t l_384 = 0UL;
                        l_367 = (safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((l_2182 , (safe_mod_func_int32_t_s_s((((((((((((p_40 , ((safe_mod_func_uint8_t_u_u((g_97[2] ^ (~(+g_89))), ((((g_97[3] & ((safe_sub_func_uint16_t_u_u((l_384 >= g_540), (((((((safe_lshift_func_int16_t_s_u((l_389 || (((((safe_rshift_func_int16_t_s_u((1UL != p_43), 4)) , 0x8DL) >= l_1854) , p_43) , 0x343F8062L)), p_43)) > 4L) > l_389) , g_120[1]) != p_40) , l_1634) == 0xCB3F649DL))) | l_389)) || l_1854) | g_120[3]) && 0xE5L))) < 0UL)) >= g_97[1]) || 0x3F5AL) ^ l_472) || p_43) | l_366) , 0L) || (-1L)) ^ 0x8506B361L) >= l_2182) ^ (-6L)), 0x3F0D7356L))), l_1854)), l_1699));
                        l_1671--;
                    }
                    l_1634 = (((((g_18 ^ (0UL & (((l_86 == (safe_mod_func_uint8_t_u_u(((((safe_sub_func_int16_t_s_s(((l_1634 & ((safe_add_func_int8_t_s_s((((safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((((safe_mod_func_uint32_t_u_u((safe_sub_func_int16_t_s_s((((g_101 <= l_1846) > (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(g_89, ((((((((safe_rshift_func_uint8_t_u_s(g_101, 1)) & (((l_281[4][6] || l_389) && l_389) | 0UL)) == g_120[1]) || g_2431) < l_1699) < g_101) || 0x3CL) < g_18))), 4))) >= (-1L)), g_540)), l_2050)) || p_43) >= l_420), l_1854)), l_1854)) & (-1L)) | l_281[4][6]), 0x42L)) < g_97[3])) <= g_120[1]), g_120[3])) | l_1671) != 0L) == l_391[1][4]), l_1537))) > 0x32L) || l_1693))) ^ p_43) | l_1634) < p_40) < 1UL);
                    for (l_86 = 0; (l_86 <= 4); l_86 += 1)
                    {
                        int i;
                        return g_120[l_86];
                    }
                    if (l_1846)
                        break;
                }

                    l_1643[0][3][1] ^= l_1751;
                }
                return l_258;
            }
            for (l_1634 = 0; (l_1634 >= 17); l_1634 = safe_add_func_int16_t_s_s(l_1634, 4))
            {
                const uint32_t l_1798[7][8] = {{0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}};
                int i, j;
                l_1799[1][5] = ((6L ^ (safe_rshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s(((((((l_389 ^ (((0L >= (((safe_lshift_func_uint8_t_u_u(0x33L, l_419)) ^ l_1699) , (safe_lshift_func_int8_t_s_s(l_351, 1)))) == ((((l_1489[2][4][7] , (l_1798[3][0] && l_1705)) & 1UL) & g_1540[0][1]) & g_849[0])) >= g_1368[2])) || 2L) , g_120[1]) | 9UL) , g_1548[1][1][0]) && 1UL), l_1699)), 0))) >= 0x9FEE1EABL);
            }

{
            g_120[1] = 0x19D1A3FEL;

if (p_39) printf("index = [%d]\n", p_39);

                    if (g_540)
                continue;
        }

                    g_120[1] |= (((g_849[0] <= (safe_add_func_int32_t_s_s(l_419, l_419))) <= ((((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u((p_39 && ((l_419 == l_1806) > ((safe_rshift_func_int16_t_s_u(((((((g_97[2] | l_258) && ((!((safe_rshift_func_int16_t_s_s(((0L | l_1549) , p_39), l_431)) ^ l_1698)) ^ 0L)) == l_258) , 1L) || 0xE5L) <= g_59), 15)) || l_1806))), 3)) > l_261) ^ l_419), g_143)) ^ g_1368[1]) || 1L) != (-5L)) , 4294967290UL) <= l_419)) ^ 0x02D0829CL);
            if ((safe_lshift_func_int8_t_s_s(0xBCL, 7)))
            {
                int8_t l_1831 = (-6L);
                int32_t l_1849[6] = {(-1L), 6L, (-1L), 6L, (-1L), 6L};
                const uint8_t l_1889 = 252UL;
                int i;
                for (l_1706 = 0; (l_1706 >= 36); l_1706 = safe_add_func_uint32_t_u_u(l_1706, 3))
                {
                    int32_t l_1836[9][5] = {{(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}};
                    int32_t l_1841 = (-3L);
                    int32_t l_1844 = 8L;
                    int32_t l_1845 = 0xBE0388A2L;
                    int16_t l_1853 = 0xBF53L;
                    uint16_t l_1856 = 0x14A1L;
                    int i, j;
                    g_120[4] ^= (((safe_add_func_uint32_t_u_u((0x22L == (((((l_1648 , (((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((~((((((g_1368[2] >= ((0xEF5AL != (safe_sub_func_int8_t_s_s(((g_1482[2][1][1] && ((safe_add_func_int8_t_s_s((((safe_sub_func_uint16_t_u_u(((((l_1831 | (((l_258 > g_1540[1][0]) >= (((safe_rshift_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((g_1368[2] > 0x5C49CB64L), 5)) | l_1831) , l_1836[4][3]) == g_1368[1]) && g_59), l_351)) >= 0x624C7317L) == p_39)) <= l_258)) , l_258) , 1UL) , g_849[0]), 0xF010L)) ^ 0UL) <= g_849[0]), l_351)) > 1L)) & l_1698), p_39))) == 0xE4B6B42FL)) | l_1799[2][5]) , 0L) >= l_389) & l_1699) , l_1489[0][3][5])), 10)), l_419)) == g_97[2]) >= l_419)) || l_261) , l_1831) == p_39) ^ g_849[0])), l_258)) | l_1837) , l_1724);
                    for (l_198 = 13; (l_198 >= 1); l_198 = safe_sub_func_int32_t_s_s(l_198, 9))
                    {
                        uint8_t l_1840 = 0x4FL;
                        int32_t l_1843 = 1L;
                        int32_t l_1850 = (-10L);
                        int32_t l_1851 = 0x86429966L;
                        int32_t l_1852 = 0xCA3D88B8L;
                        int32_t l_1855 = 1L;
                        l_1840 = l_389;
                        --l_1846;
                        --l_1856;
                    }
                    for (l_1841 = (-19); (l_1841 != (-8)); l_1841++)
                    {
                        uint16_t l_1886[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            {
l_394 &= (safe_rshift_func_uint16_t_u_u(l_656, 8));

                    l_1886[i] = 7UL;}
                        g_120[1] &= l_1696[0];
                        g_120[0] = (((((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u(65535UL, 13)) , 0x9426L), (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_u(p_39, (((((0xEF2D849BL || l_1591) & (l_1841 , (safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u((((((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s(l_431, (safe_rshift_func_uint16_t_u_s((((l_1799[1][5] > (safe_add_func_uint16_t_u_u(0x2E1AL, 0xBDC1L))) >= l_1836[0][4]) == l_1886[0]), 13)))) | (-2L)), l_1887)) & l_258) < 0xBEL) < g_2467) & l_1888[2]), 0x66L)), l_419)), 4)), 7)), 0UL)))) , 1UL) ^ l_1889) == 0xEAL))))))) > 0x483D69BBL) , l_1844) , 247UL) ^ l_1706);
                        l_1644[0][3][4] = ((((-2L) == (safe_add_func_uint16_t_u_u((((((((((safe_add_func_int32_t_s_s(((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s((safe_mod_func_int8_t_s_s((251UL != ((!l_1905) == (((g_97[1] | (safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s(0xF54AL, 2)) && ((((l_419 > ((((l_1853 & (safe_add_func_uint16_t_u_u(0x3ED4L, 1L))) ^ p_39) | 1L) ^ l_1849[1])) > (-1L)) && l_261) != 0UL)), 0xEB10B25CL)), 10))) < g_1482[2][1][1]) || 0x405D3F2AL))), l_1599)), 1)), 2)) && l_389), 5)) && 4294967295UL), 4294967293UL)) , p_39), 4294967288UL)) | l_258) || l_258) && l_1639) && p_39) && 0x068C0922L) , l_198) , (-1L)) < l_419), 1UL))) ^ l_1846) || l_1699);
                        l_1693 = (safe_lshift_func_uint8_t_u_s(l_258, ((safe_rshift_func_int8_t_s_s(9L, l_351)) != l_1846)));
                    }
                }
                g_120[1] ^= ((l_258 & (0x8889L >= (p_39 == ((safe_unary_minus_func_uint8_t_u(0UL)) <= (safe_mod_func_int16_t_s_s(g_1482[3][0][1], ((p_39 > (((~l_419) && ((~(!((((safe_sub_func_uint16_t_u_u((((((((l_258 < ((((p_39 , p_39) >= 0x93L) , 1UL) ^ p_40)) ^ l_419) == l_1889) & 0UL) , p_40) < l_1799[4][4]) < 4294967295UL), l_1849[0])) <= 1L) , l_258) , 0x3CL))) , l_419)) >= 7L)) & l_1648))))))) | l_1831);
                l_1643[0][3][1] = (l_198 > 0x5B7FL);
            }
            else
            {
                uint32_t l_1932 = 1UL;
                int32_t l_1945 = 0L;
                int32_t l_1946[1];
                uint32_t l_1971 = 0x9EF11B35L;
                uint8_t l_1990 = 0xB6L;
                int i;
                for (i = 0; i < 1; i++)
                    l_1946[i] = 3L;
                for (l_261 = (-11); (l_261 < (-24)); --l_261)
                {
                    int32_t l_1929 = 0L;
                    int32_t l_1930 = 0x01C56913L;
                    uint8_t l_1949 = 0xBEL;
                    int32_t l_2005 = 0L;

{
                    l_1842 &= (safe_rshift_func_uint16_t_u_u(l_253, 8));
                }

                    if (l_258)
                    {
                        int32_t l_1928[10] = {0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L};
                        int i;
                        l_1932--;
                    }
                    else
                    {
                        l_1693 = p_39;
                    }
                    if ((l_258 , l_1694))
                    {
                        int8_t l_1947 = 0x1BL;
                        int32_t l_1948 = 0x27F08C10L;

{
                        l_1948 = l_2178[0];
                        return l_1806;
                    }

                    l_1945 = (((0x03L == (0xA11DL < (g_59 | ((((0x6F1BL != g_935) < (((((((((safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(g_97[2], l_198)), 2)) > (safe_add_func_uint16_t_u_u(g_1548[4][6][2], 0x34DEL))) & l_419), l_1706)) , 0x3208L) , g_1540[1][0]) , l_1930) == l_261) , g_1548[0][0][1]) <= l_1932) > l_419) >= 0UL)) < l_419) >= p_39)))) ^ g_97[2]) , g_849[0]);
                        ++l_1949;
                        g_120[4] = (safe_mod_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(6L, (safe_sub_func_uint8_t_u_u(0x94L, (((l_1949 | (safe_rshift_func_int8_t_s_u(((((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((((+(safe_add_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(((0xB3EFL || (l_1947 | (((g_120[1] ^ ((((-2L) & (((l_419 ^ (l_1945 , 0x78L)) , l_1971) < p_39)) < 0xA9FBL) == p_39)) < l_1806) < 0xE1L))) && l_1948), 0x64L)) , p_39), 9UL))) >= 0x60B3L) != p_39) ^ p_39), l_258)), 0x0DAEL)), l_1887)) >= l_1947) > p_39) == l_419), l_1948))) , 5L) | 0xB082A17BL))))) , 0x11L), 0x03L));
                    }
                    else
                    {
                        l_1930 = ((0L & p_39) != (!((safe_mod_func_uint8_t_u_u(l_258, 0x7AL)) > (((l_1932 | p_39) , 0x1F0EL) < (l_419 && ((((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u(l_1854, l_419)), 0x3929L)) != 0L) == 0x2F747C30L) , 0x96347F98L))))));
                    }
                    if (((safe_lshift_func_uint16_t_u_s((g_1540[1][0] , l_1930), l_419)) & (((g_935 < (((((safe_lshift_func_int16_t_s_u(((p_39 , ((l_419 && (((safe_unary_minus_func_int16_t_s(((safe_add_func_uint16_t_u_u(l_1693, ((((safe_add_func_uint16_t_u_u((l_1591 ^ p_39), l_1990)) < l_419) < 0x1D1DL) | l_351))) | g_120[1]))) , p_39) && l_1643[1][1][6])) ^ l_699)) , p_39), l_1599)) | l_419) <= 0UL) != (-8L)) , p_39)) < l_1698) || 0x837FL)))
                    {
                        int8_t l_2002 = 0x5BL;
                        int32_t l_2004[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_2004[i] = 7L;
                        g_2003[0] |= (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u(g_1482[0][1][0], ((~((((-6L) < l_419) >= g_120[1]) | (l_419 , l_419))) != (((safe_lshift_func_uint16_t_u_s(((g_1548[4][6][2] || ((((safe_rshift_func_int8_t_s_s(1L, 4)) <= 0xC812E52FL) || g_1368[1]) <= 0UL)) , l_1888[1]), 3)) != p_39) < 65535UL)))) | g_1482[2][1][1]) <= 4294967292UL) && l_1929) > l_2002), g_849[0])), l_258));
                        l_2006--;
                        if (l_1888[1])
                            {
for (l_1549 = 0; l_1549 < 6; l_1549++)
    {
        for (l_367 = 0; l_367 < 2; l_367++)
        {
            transparent_crc(g_1540[l_1549][l_367], "g_1540[l_1549][l_367]", l_363);
            if (l_363) printf("index = [%d][%d]\n", l_1549, l_367);

        }
    };


                    break;}
                    }
                    else
                    {
                        uint8_t l_2013[2][2] = {{1UL, 0x0EL}, {1UL, 0x0EL}};
                        int i, j;
                        g_120[1] = (safe_rshift_func_int16_t_s_u((((safe_sub_func_uint8_t_u_u((0xBC96E130L > l_2013[1][0]), ((safe_add_func_uint8_t_u_u(((l_2005 >= (((safe_add_func_uint8_t_u_u((((l_1725 & l_2013[0][1]) , ((safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(g_1548[4][6][2], l_1932)) , ((safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((l_419 ^ ((safe_mod_func_uint16_t_u_u((65534UL <= l_1549), l_419)) , g_120[3])) || l_1591), g_97[1])) > g_143), (-4L))) > 7L)), l_1949)) == l_1888[2])) < l_258), 9UL)) | g_1368[1]) & l_1639)) <= l_1930), 0x27L)) & 9UL))) && l_258) , 0x1E18L), g_18));
                    }
                    g_120[1] = ((((0UL == (0x99L == g_1482[2][1][1])) , l_2028) , g_97[2]) > ((g_120[3] > ((((((safe_lshift_func_uint16_t_u_s(((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s(((0x83922D4EL != ((-8L) > 0x08L)) || l_1634), 5)), l_1671)) >= l_1634), 15)) < p_39) , 0xAC9FE61AL) , p_39) > l_419) | g_1540[1][0])) ^ (-1L)));
                }
            }
        }
    }
    for (p_40 = 0; (p_40 == 7); p_40 = safe_add_func_uint8_t_u_u(p_40, 6))
    {
        int16_t l_2039 = 0x0ABAL;
        const uint16_t l_2040 = 65532UL;
        int32_t l_2061 = 0x90A8BF10L;
        int32_t l_2101 = 0x02F00675L;
        int32_t l_2137 = 0L;
        int32_t l_2143[3];
        uint32_t l_2152 = 0xDB2A778AL;
        uint16_t l_2158 = 0xFEEFL;
        uint16_t l_2301 = 0xE812L;
        int i;
        for (i = 0; i < 3; i++)
            l_2143[i] = 0x4EA06463L;
        if ((safe_add_func_uint8_t_u_u(1UL, ((((1UL | ((l_1671 , ((g_849[0] , l_2039) != ((((l_2040 , (-9L)) <= 0x9EA7L) > l_258) , l_419))) <= p_40)) == l_1888[2]) || p_39) ^ g_935))))
        {
            uint32_t l_2062 = 4UL;
            int32_t l_2136 = 0x587994DEL;
            int32_t l_2138 = 0x39236B84L;
            int32_t l_2139 = 0x2CD995FBL;
            int32_t l_2140 = (-1L);
            int32_t l_2142 = 0x807412D1L;
            int32_t l_2146 = (-8L);
            int32_t l_2147 = (-7L);
            int32_t l_2149 = 0x0E72D148L;
            int32_t l_2151 = 0x4ECFBDFFL;
            uint8_t l_2155 = 0x86L;
            int32_t l_2176[3];
            int16_t l_2177 = 0x3603L;
            int32_t l_2179 = 1L;
            int32_t l_2180 = 1L;
            int32_t l_2181 = 0xDF8F0F9CL;
            int32_t l_2183[5] = {0x3D5D9951L, 0L, 0x3D5D9951L, 0L, 0x3D5D9951L};
            uint16_t l_2185 = 0x30E9L;
            int8_t l_2259[8] = {0xA3L, 0x43L, 0xA3L, 0x43L, 0xA3L, 0x43L, 0xA3L, 0x43L};
            int i;
            for (i = 0; i < 3; i++)
                l_2176[i] = (-1L);
            l_2061 = (safe_rshift_func_uint8_t_u_u(((((l_2039 , (safe_mod_func_int16_t_s_s((+((safe_sub_func_uint32_t_u_u((((safe_add_func_int8_t_s_s((0x9FB88B87L <= (l_2050 && l_2028)), ((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(g_120[4], (l_2055 | l_258))), ((safe_unary_minus_func_uint32_t_u((safe_mod_func_uint8_t_u_u((((((((safe_rshift_func_uint8_t_u_u(g_120[1], 3)) ^ 0L) < l_2039) && 0L) < g_143) & 0xF6503CF8L) > l_419), l_419)))) , l_1696[0]))) , l_1888[2]))) == 1UL) , l_419), l_1648)) < 0x0C40299FL)), l_258))) || 0x6671L) && g_935) < g_935), 3));
            if ((l_2062 == 0xF331L))
            {
                uint32_t l_2075 = 0x3F7E974AL;
                int32_t l_2076 = 0xDD959D4BL;
                uint32_t l_2121 = 0xDB46FF94L;
                int32_t l_2135 = 0x8FD202FEL;
                int32_t l_2144 = 7L;
                int32_t l_2145 = 0x543A4A56L;
                int32_t l_2148 = (-7L);
                int32_t l_2150 = (-4L);
                for (g_59 = 11; (g_59 > 6); g_59 = safe_sub_func_uint16_t_u_u(g_59, 8))
                {
                    uint16_t l_2105 = 65535UL;
                    for (l_2050 = 0; (l_2050 != 38); ++l_2050)
                    {
                        l_1695 = ((l_258 < (safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((l_419 < 0L), (l_419 >= 0L))), (-1L)))) >= ((safe_lshift_func_uint8_t_u_u(((p_39 || 252UL) , ((((safe_lshift_func_int8_t_s_s(l_1549, 7)) != 0L) == l_261) , g_849[0])), l_2075)) >= l_2076));
                    }
                    for (l_2055 = (-27); (l_2055 <= (-28)); l_2055--)
                    {
                        uint32_t l_2102 = 0x75F47E93L;

{
        transparent_crc(g_2003[l_656], "g_2003[l_656]", l_394);
        if (l_394) printf("index = [%d]\n", l_656);

    }

                    g_120[2] = (safe_sub_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((l_261 > l_419), (safe_sub_func_uint8_t_u_u(((p_39 & (l_258 & ((((~((((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(g_143, (((((safe_lshift_func_int8_t_s_s(((safe_mod_func_uint8_t_u_u((((0xDFF1L > ((safe_sub_func_int8_t_s_s((((+((!(((safe_lshift_func_int16_t_s_s(0xF854L, 8)) ^ g_1482[2][1][1]) ^ g_935)) , g_120[4])) == 0UL) ^ p_40), l_258)) , 1L)) , l_699) | g_2003[3]), g_849[0])) || 0x4AL), l_258)) > l_258) & g_97[3]) == g_1368[1]) , 0x821DL))), l_419)) & 0xDCA8CE5FL) <= l_2040) > p_39)) | p_39) , l_258) || p_39))) , l_2076), 0x74L)))), l_390));
                        l_2101 |= 9L;

for (l_262 = 0; l_262 < 1; l_262++)
        l_1696[l_262] = (-1L);

                    l_2102 &= l_258;
                    }
                    for (l_2076 = 7; (l_2076 >= (-7)); --l_2076)
                    {
                        uint32_t l_2108 = 0xCCCFDF72L;
                        l_2105 ^= p_39;
                        g_120[2] = (((safe_rshift_func_uint8_t_u_u((((g_1482[2][1][3] , (((l_2108 | g_120[3]) == l_419) , ((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint8_t_u_u(((0UL && g_2003[1]) || 1UL), ((safe_sub_func_uint8_t_u_u(((((safe_sub_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((l_258 && (safe_lshift_func_uint8_t_u_s((0x24L >= 0UL), 0))), l_419)), l_2121)) <= l_2040) & p_40) , l_419), 1UL)) >= l_2108))) >= p_39), 12)) >= (-1L)))) | g_97[2]) != l_258), 2)) ^ 0xB68DD604L) == 0UL);
                    }
                    l_1693 = (p_40 != (safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s((((-1L) || 0x95L) & g_1368[1]), ((safe_lshift_func_uint8_t_u_u(255UL, 7)) >= (((((safe_unary_minus_func_uint16_t_u(1UL)) , ((((l_419 == ((l_2105 , (safe_sub_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(g_935, g_120[1])) , l_2039), l_2062))) == l_258)) , 0x8847L) == l_261) , 0x73EDD688L)) == p_39) , l_2062) < l_261)))), 8)));
                }
                l_2152++;
                l_2145 = ((((l_2151 , (l_2155 != l_258)) || (0xADL && 0x61L)) < l_419) < ((safe_lshift_func_uint16_t_u_s(0xD3B9L, (2UL < ((((0x7EC0L & g_120[1]) & 4294967295UL) || 1UL) & 0x5C680109L)))) == 0xC0DAL));
            }
            else
            {
                uint32_t l_2161 = 0x817ED328L;
                l_2101 |= (7L ^ (l_258 > (((l_2158 < (l_258 & ((safe_lshift_func_uint8_t_u_u(0x2CL, 3)) || (255UL >= l_258)))) , g_1548[2][0][1]) == l_2161)));
                l_2151 = (safe_sub_func_uint32_t_u_u((g_2003[0] >= ((l_258 >= (safe_add_func_int32_t_s_s(((((((safe_add_func_int8_t_s_s(((((safe_sub_func_int8_t_s_s(l_390, (safe_sub_func_uint16_t_u_u(0xB24EL, ((((safe_mod_func_uint32_t_u_u(l_431, ((((safe_sub_func_int32_t_s_s((0L == l_2176[0]), (0x17L && (l_699 , 0x38L)))) > l_431) , 255UL) && g_143))) || 0x8F222FB3L) || 0xC79840FEL) ^ l_258))))) < l_258) , g_59) > g_97[5]), 7UL)) < g_120[2]) , g_120[1]) & l_2146) <= l_389) && g_18), l_258))) && l_258)), p_40));
            }
            l_2185++;
            for (l_1671 = 0; (l_1671 <= 8); l_1671 = safe_add_func_uint8_t_u_u(l_1671, 6))
            {
                const int8_t l_2199 = (-1L);
                int32_t l_2255[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_2255[i] = 0L;
                for (g_59 = 0; (g_59 == 34); g_59 = safe_add_func_uint8_t_u_u(g_59, 3))
                {
                    int16_t l_2216 = 0x83C6L;
                    int32_t l_2249 = 0xEA87154FL;
                    int32_t l_2260 = 0xF84A0E45L;
                    int32_t l_2261 = 0xC424E530L;
                    uint16_t l_2263 = 65530UL;
                    for (l_390 = 0; (l_390 <= (-15)); l_390 = safe_sub_func_uint32_t_u_u(l_390, 1))
                    {
                        const uint8_t l_2200 = 0xE4L;
                        uint16_t l_2217 = 3UL;
                        l_2143[0] = (0UL >= ((g_1368[0] != (((safe_add_func_int16_t_s_s(((+(l_2176[0] && ((((0xEEL >= g_120[1]) && (+p_40)) || l_419) > (((((~(p_39 <= (l_2199 , 0L))) >= (-1L)) <= p_39) , g_59) , g_143)))) > l_419), l_2200)) | l_2200) , l_261)) != g_97[5]));
                        g_120[1] = (safe_lshift_func_int8_t_s_u(((safe_mod_func_uint16_t_u_u(l_258, (((l_2040 || (safe_unary_minus_func_int8_t_s(((safe_mod_func_int16_t_s_s((0L != ((safe_sub_func_uint32_t_u_u(0xF9EC49D5L, (safe_lshift_func_uint8_t_u_s(((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(((((-8L) && (0x53L || 1L)) < (l_261 == (((0xAC9BL > l_419) <= g_143) >= p_39))) , l_2216), 2)) && 0xE90C1C13L), 2L)) , l_261) , 0UL) , l_2101), 7)))) , l_258)), l_258)) < g_935)))) != 0L) || l_2217))) > p_39), 6));
                        g_120[1] &= l_2200;
                        if (p_40)
                            {
if (l_2061)
                            break;

                    break;}
                    }
                    if ((g_1482[2][1][1] & 0xDB81CA17L))
                    {
                        l_2181 = l_2176[0];
                        return p_39;
                    }
                    else
                    {
                        if (l_258)
                            break;
                    }


{
            int8_t l_94[2];
            uint32_t l_134 = 18446744073709551615UL;
            uint16_t l_142 = 0x7BCBL;
            int i;
            for (i = 0; i < 2; i++)
                l_94[i] = 1L;
            for (l_2179 = 0; (l_2179 <= 1); l_2179 += 1)
            {
                int i;
                for (g_59 = 0; (g_59 <= 1); g_59 += 1)
                {
                    int i;
                    return l_94[l_2179];
                }
                if (l_94[l_2179])
                    continue;
                if (l_94[0])
                    continue;
            }
            for (g_89 = 0; (g_89 > (-19)); g_89 = safe_sub_func_uint16_t_u_u(g_89, 7))
            {
                uint8_t l_103[4] = {1UL, 0xABL, 1UL, 0xABL};
                int i;
                g_97[2] ^= g_1217;
                for (g_777 = 1; (g_777 <= 6); g_777 += 1)
                {
                    int16_t l_110[7] = {0xD96CL, (-2L), 0xD96CL, (-2L), 0xD96CL, (-2L), 0xD96CL};
                    int8_t l_168 = 0xE9L;
                    int8_t l_181 = 0xCFL;
                    int i;
                    for (l_296 = 6; (l_296 >= 1); l_296 -= 1)
                    {
                        int i;
                        l_2179 = (safe_mod_func_int32_t_s_s(g_97[l_296], g_59));
                        g_89 = g_18;
                        l_2216 &= 0xEC293C97L;
                    }
                    l_103[3]++;
                    if (((safe_rshift_func_int8_t_s_u((((((g_18 ^ ((safe_add_func_uint32_t_u_u((l_110[0] == (l_2216 == (safe_mod_func_uint16_t_u_u(0UL, (((safe_unary_minus_func_uint16_t_u(g_89)) | (l_94[1] , ((safe_add_func_uint16_t_u_u(((((((safe_mod_func_int8_t_s_s(g_1217, (safe_sub_func_uint8_t_u_u((g_120[1] > (l_102 | g_1217)), g_1217)))) ^ g_59) || 0x17461B67L) && g_97[2]) == 1L) , g_18), g_120[4])) , g_120[3]))) & g_89))))), l_2216)) > 0x3AD0L)) & l_2216) || l_296) != l_94[1]) == g_2431), g_18)) <= (-9L)))
                    {
                        int8_t l_141 = (-10L);
                        l_419 ^= (g_97[6] < (safe_mod_func_int16_t_s_s((((g_120[1] ^ ((safe_add_func_uint32_t_u_u(((l_2216 <= ((safe_sub_func_uint8_t_u_u(l_103[1], (((((((safe_sub_func_uint16_t_u_u(((l_134 >= g_777) > 0UL), ((((((safe_sub_func_int32_t_s_s((((safe_add_func_uint8_t_u_u((((((((g_89 & (safe_lshift_func_uint8_t_u_u((l_94[0] <= l_110[0]), l_2216))) || g_1217) | 0xF7L) & l_141) , 0x6CL) | g_89) < l_94[1]), l_103[3])) >= g_59) > l_296), 1L)) || l_2039) >= g_777) , g_59) > l_142) < g_777))) == l_102) , l_296) && 0x68L) && g_2431) >= l_110[0]) ^ g_1217))) != g_120[1])) != (-5L)), 0xB89AE2E4L)) > g_2431)) > g_89) || 0x3285CC41L), g_97[2])));
                    }
                    else
                    {
                        int32_t l_167 = 0xBD733D80L;
                        if (l_2039)
                            break;
                        g_120[4] = (safe_rshift_func_int16_t_s_u((safe_lshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_s((safe_mod_func_uint8_t_u_u(((g_97[4] ^ (g_59 | (safe_lshift_func_int16_t_s_u((((safe_mod_func_int16_t_s_s(((safe_rshift_func_int8_t_s_u(2L, ((+(((l_296 , ((safe_rshift_func_uint8_t_u_s(((l_103[3] > ((((g_1217 & 0x8D56L) > (safe_lshift_func_uint8_t_u_s((safe_add_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((65535UL ^ (4L >= (-10L))), g_120[0])), l_296)), l_2179))) == 0xB673D79CL) ^ 1L)) | g_89), l_103[3])) <= l_102)) != (-8L)) < l_167)) | g_59))) , g_777), l_103[3])) ^ 0xBAC23114L) | l_110[0]), l_168)))) | l_296), (-2L))), 12)), 10)), g_89));
                        g_120[4] = ((((safe_add_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((safe_lshift_func_uint8_t_u_s(((255UL >= 254UL) < ((safe_mod_func_uint16_t_u_u(l_2216, 65531UL)) || 0x8F5F89A5L)), (((((+(((((~l_2039) & ((g_1217 , l_168) < ((((((g_89 && l_296) && l_167) == l_296) , 6L) ^ l_419) , 0x9D48L))) < 0x5183DF78L) , l_142) & 1L)) != l_167) || l_181) || g_89) <= 4294967286UL))) || 0x76D7L), 1)), l_2179)) || 0xFB851665L), 0x69F6L)) >= g_1217) , 0xDEBA2DDDL) <= g_2431);
                    }
                }
                for (g_59 = 0; (g_59 != 33); g_59++)
                {
                    return g_1217;
                }
                if (l_103[3])
                    break;
            }
        }

                    for (l_2180 = 0; l_2180 < 1; l_2180++)
    {
        transparent_crc(g_849[l_2180], "g_849[l_2180]", l_2139);
        if (l_2139) printf("index = [%d]\n", l_2180);

    }
for (l_392 = 0; (l_392 == 26); ++l_392)
            {
                uint32_t l_210 = 0UL;
                int8_t l_281[8][7] = {{0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}, {0xE1L, 5L, (-1L), 5L, 0xE1L, 0x96L, (-1L)}};
                uint32_t l_326 = 0x0A0DE782L;
                int32_t l_363 = 0L;
                int32_t l_392 = (-1L);
                int32_t l_395 = 0L;
                const uint32_t l_420 = 0xA82EA14BL;
                const int16_t l_427 = 0L;
                int i, j;
                if ((l_2151 || (safe_mod_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_u(0x73L, 5)) | ((safe_mod_func_int32_t_s_s(g_1171, (safe_rshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s((((0x7CB8L < 0xB2B8L) , ((g_1171 ^ 0xDBL) != g_1171)) && 0xD1L), g_1171)), 11)))) != l_2151)), 0xA615L))))
                {
                    uint32_t l_207 = 0x44D27D01L;
                    g_120[3] = l_2177;
                    for (g_143 = (-26); (g_143 >= 44); g_143++)
                    {
                        return g_1171;
                    }
                    g_120[1] = (((((((g_120[1] && g_540) || ((safe_rshift_func_uint16_t_u_u(((l_350 , ((safe_mod_func_uint32_t_u_u(((safe_mod_func_uint16_t_u_u(((((0x47C1L >= (l_296 ^ l_207)) <= (safe_sub_func_uint16_t_u_u(((g_18 && l_2185) , l_121), l_121))) ^ g_120[1]) < g_120[0]), g_120[1])) & g_97[2]), 0x3A8961DAL)) & 0L)) , l_2177), 4)) & g_120[1])) ^ l_2151) == l_207) | l_210) & 0xD933A2BCL) & l_121);
                }
                else
                {
                    uint8_t l_258 = 0x75L;
                    int32_t l_262 = 0x18EC19C0L;
                    for (g_143 = (-24); (g_143 < 42); ++g_143)
                    {
                        l_213[2] |= l_2185;
                        return g_1171;
                    }
                    l_2151 = ((0x5EL || (safe_lshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((0x746C22C4L && (safe_add_func_int16_t_s_s(((l_350 , (safe_rshift_func_uint8_t_u_u(l_296, 6))) && (safe_add_func_uint8_t_u_u(l_2177, (safe_lshift_func_int16_t_s_u((((safe_rshift_func_int8_t_s_s((safe_add_func_int8_t_s_s(((l_296 == (((safe_sub_func_uint32_t_u_u(((g_1171 || 0x50L) | ((safe_sub_func_uint32_t_u_u((((l_213[2] == l_296) , l_121) >= g_540), l_2177)) == 0xFF3A24CFL)), 0x3913078BL)) >= l_296) , 1L)) != l_2177), l_2151)), l_2151)) > g_540) | (-6L)), 1))))), g_120[2]))), 0L)), 15))) != l_2151);
                    for (g_1171 = 0; (g_1171 > 43); g_1171 = safe_add_func_uint8_t_u_u(g_1171, 2))
                    {
                        uint16_t l_236 = 1UL;
                        g_120[1] = 0x724D0293L;
                        l_236 = l_296;
                        l_262 = (safe_sub_func_int8_t_s_s((((((((l_296 || ((((1UL < ((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((((safe_mod_func_uint8_t_u_u(255UL, (safe_rshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s(((safe_sub_func_int8_t_s_s((safe_mod_func_int16_t_s_s(l_395, 65535UL)), g_1171)) > ((safe_rshift_func_uint16_t_u_u(l_2177, ((((safe_rshift_func_int16_t_s_u(((l_258 , (((safe_add_func_uint32_t_u_u(g_143, g_120[1])) == g_1171) , l_236)) & l_258), l_2177)) || g_97[2]) , l_296) , 0x2CA6L))) > 0x62L)), l_2177)) | l_1726), 0)))) | l_210) && l_2151), 255UL)) | g_18), 11)) , l_350)) || l_236) , 0x43L) | 1UL)) ^ l_2177) , l_210) < 0L) < l_395) != l_296) >= l_121), l_296));
                        g_100 = ((((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_u(((((((safe_add_func_uint16_t_u_u(l_121, g_540)) == ((safe_mod_func_int32_t_s_s((((((safe_add_func_int16_t_s_s((safe_sub_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u(((((safe_sub_func_uint32_t_u_u(l_281[4][6], l_258)) ^ (((safe_add_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u((0x25D96900L <= (safe_sub_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s(l_236, l_210)) < ((safe_lshift_func_int16_t_s_s(((0UL < (safe_mod_func_int8_t_s_s(l_350, g_97[4]))) == g_120[2]), l_296)) < 7UL)), 2UL))), l_2177)), 0x96E64D66L)) >= l_296), 0xFC6B1E59L)) < (-5L)) | 4294967292UL)) != l_2151) ^ 8L), (-7L))) & l_2185), l_2151)) > l_236) <= (-1L)), l_2177)), l_2177)) >= g_143) ^ 0xF7BFL) , l_296) == g_1171), g_540)) && g_1171)) | 1UL) != 0x6CL) <= l_281[0][2]) , 0x35L), l_121)) && l_2177), 4)) & g_143) < 0x73054497L) != g_540);
                    }
                    for (g_1171 = 0; (g_1171 <= 4); g_1171 += 1)
                    {
                        int i;
                        g_120[g_1171] = ((safe_sub_func_int32_t_s_s(g_97[(g_1171 + 2)], (safe_unary_minus_func_uint8_t_u(((((safe_sub_func_int16_t_s_s(((g_97[g_1171] , 0xC6C2L) ^ 0xFEB2L), ((safe_rshift_func_uint16_t_u_u(g_97[(g_1171 + 1)], ((safe_rshift_func_uint16_t_u_u(g_120[g_1171], 5)) != (safe_mod_func_int8_t_s_s(((((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(g_120[g_1171], ((0x60L < g_120[g_1171]) , l_281[3][1]))), 0x2C0B2767L)) >= l_392) != l_296) != 255UL), 0xE6L))))) >= l_296))) != (-6L)) || g_120[0]) && g_97[(g_1171 + 2)]))))) & g_540);
                        g_120[2] = ((-8L) == 0UL);
                        l_326 = ((((((((65535UL > (safe_mod_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((((l_262 || (g_1171 || (safe_mod_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u((safe_rshift_func_int8_t_s_u(l_296, (((l_395 > (l_281[4][6] , l_2177)) != ((safe_rshift_func_uint16_t_u_u(0xB25DL, 8)) || 1UL)) <= l_296))), g_540)) | g_97[2]), 1)), g_540)))) & l_2177) || l_296), l_213[0])) & l_258), l_2177))) <= l_296) < g_120[g_1171]) == 0x8B28L) < l_296) || l_213[2]) != l_296) <= 246UL);
                        l_262 |= (~g_120[1]);
                    }
                }
                for (l_121 = 20; (l_121 < 40); l_121 = safe_add_func_uint32_t_u_u(l_121, 1))
                {
                    int8_t l_362 = 0x43L;
                    int32_t l_366 = (-2L);
                    uint8_t l_369 = 0x5AL;
                    int32_t l_393 = 0L;
                    if ((safe_add_func_int16_t_s_s(((((l_213[1] || ((l_350 >= (+(-1L))) >= (safe_lshift_func_int8_t_s_s(((safe_sub_func_int8_t_s_s((((safe_mod_func_int16_t_s_s(((safe_lshift_func_int16_t_s_s(l_121, 2)) == (((safe_lshift_func_uint16_t_u_s((g_1171 || ((safe_rshift_func_uint16_t_u_s((((safe_add_func_int16_t_s_s(((((((safe_mod_func_int16_t_s_s(l_2185, g_1171)) <= 0x56719CF5L) < ((+(((((1UL && 0xD84E0731L) > l_281[6][4]) < g_143) > 0x15L) & 0xF7L)) | g_143)) , l_350) == l_2185) , l_2151), 0xA7B5L)) , 2L) , l_351), 11)) >= g_540)), l_210)) , 0x25L) < 7UL)), g_1171)) <= 1UL) , l_210), g_1171)) ^ 246UL), g_18)))) <= 0x83L) >= 6UL) & g_97[2]), l_2151)))
                    {
                        uint32_t l_364 = 0UL;
                        int32_t l_365 = 1L;
                        l_364 = ((safe_add_func_int8_t_s_s((((safe_lshift_func_uint16_t_u_u(((((l_2177 != g_100) > ((safe_lshift_func_uint16_t_u_u((0xA1L != (((-6L) && (((safe_rshift_func_int8_t_s_u(0x08L, ((l_2185 < ((g_97[2] | (((safe_sub_func_uint16_t_u_u((((l_362 != 0xFEFA8AE2L) , g_540) != g_97[2]), l_296)) && 0x6386802AL) >= g_97[1])) >= l_296)) , l_2151))) < 2UL) && l_281[4][6])) != g_1171)), 0)) ^ l_2151)) != g_97[2]) || 0xF9L), l_363)) || 0xD2L) , l_350), (-7L))) && l_350);
                        ++l_369;
                        if (l_281[4][3])
                            break;
                        l_366 = l_2151;
                    }
                    else
                    {
                        uint32_t l_384 = 0UL;
                        l_1693 = (safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((l_2177 , (safe_mod_func_int32_t_s_s((((((((((((l_296 , ((safe_mod_func_uint8_t_u_u((g_97[2] ^ (~(+g_100))), ((((g_97[3] & ((safe_sub_func_uint16_t_u_u((l_384 >= l_351), (((((((safe_lshift_func_int16_t_s_u((l_350 || (((((safe_rshift_func_int16_t_s_u((1UL != l_2185), 4)) , 0x8DL) >= l_296) , l_350) , 0x343F8062L)), l_2185)) > 4L) > l_350) , g_120[1]) != l_296) , l_2151) == 0xCB3F649DL))) | l_350)) || l_296) | g_120[3]) && 0xE5L))) < 0UL)) >= g_97[1]) || 0x3F5AL) ^ l_1726) || l_2185) | l_366) , 0L) || (-1L)) ^ 0x8506B361L) >= l_2177) ^ (-6L)), 0x3F0D7356L))), l_296)), l_210));
                        l_2050--;
                    }
                    l_2151 = (((((g_18 ^ (0UL & (((g_1171 == (safe_mod_func_uint8_t_u_u(((((safe_sub_func_int16_t_s_s(((l_2151 & ((safe_add_func_int8_t_s_s((((safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((((safe_mod_func_uint32_t_u_u((safe_sub_func_int16_t_s_s((((g_540 <= g_143) > (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(g_100, ((((((((safe_rshift_func_uint8_t_u_s(g_540, 1)) & (((l_281[4][6] || l_350) && l_350) | 0UL)) == g_120[1]) || l_121) < l_326) < g_540) || 0x3CL) < g_18))), 4))) >= (-1L)), l_351)), l_210)) || l_2185) >= l_420), l_296)), l_296)) & (-1L)) | l_281[4][6]), 0x42L)) < g_97[3])) <= g_120[1]), g_120[3])) | l_2050) != 0L) == l_391[1][4]), l_395))) > 0x32L) || l_367))) ^ l_2185) | l_2151) < l_296) < 1UL);
                    for (g_1171 = 0; (g_1171 <= 4); g_1171 += 1)
                    {
                        int i;
                        return g_120[g_1171];
                    }
                    if (g_143)
                        break;
                }
                for (l_363 = 0; (l_363 == (-23)); --l_363)
                {
                    uint32_t l_461[2][4][5] = {{{0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}}, {{0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}}};
                    int i, j, k;
                    g_120[1] = ((0x7DDEF103L >= ((((safe_rshift_func_int16_t_s_u(((0x2CD8L == ((((((0x0CE5L > l_2177) , (-9L)) || ((((safe_mod_func_uint32_t_u_u((g_120[1] > (0xD6FEED26L | ((l_427 >= (((((((safe_unary_minus_func_uint8_t_u(((safe_rshift_func_int8_t_s_s(g_97[1], 2)) != 0xEF0CL))) > 0x88D4L) && l_296) ^ g_120[1]) >= l_281[3][0]) | (-6L)) == 1L)) ^ 7UL))), 1UL)) < g_143) | l_296) , 0UL)) ^ (-1L)) | l_281[0][3]) == l_2050)) >= 0xBDE2D00BL), 7)) , 7L) > l_2177) || l_420)) , l_210);
                    g_2467--;
                    l_2151 = (((safe_unary_minus_func_int16_t_s(((((safe_unary_minus_func_uint16_t_u((l_326 , (((((~(safe_add_func_uint8_t_u_u((l_427 == (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_s(((safe_sub_func_int16_t_s_s(g_120[2], (((safe_add_func_uint8_t_u_u(((l_2185 || ((safe_mod_func_int16_t_s_s(((((l_395 & ((0xAD109901L < ((((safe_rshift_func_uint8_t_u_s(l_296, 7)) != (l_350 <= (safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u((safe_sub_func_uint8_t_u_u(((((((((l_296 , 4UL) > 0UL) == 0xC8C73883L) <= l_427) ^ g_18) && l_121) || g_120[1]) & l_367), l_2177)), l_461[1][1][2])), g_100)), l_296)))) <= l_461[1][1][2]) < 0x237EL)) <= 0x28L)) < 65535UL) | l_363) >= l_350), l_213[4])) < 5UL)) ^ l_395), g_1171)) >= 0UL) | g_97[2]))) <= g_1171), g_120[1])) ^ l_296), 7))), l_350))) < 1L) || l_296) ^ l_210) , 6UL)))) | g_143) != l_210) , l_1693))) , 1UL) != 255UL);
                }
                g_120[1] ^= ((0L & 0x37L) >= (safe_sub_func_uint16_t_u_u(1UL, ((((safe_lshift_func_int8_t_s_u((g_97[3] >= (safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s(((((((safe_lshift_func_uint16_t_u_s(((((0xC0653759L ^ l_363) , l_350) == (l_392 != l_2151)) , 1UL), l_2151)) , 4L) , l_210) || 0x464EEE5AL) | 8UL) & l_2216), 5)) , 0x83F7DA68L) && g_18), 1UL))), 5)) <= g_1171) < 65531UL) || l_2050))));
            };


                    ;


                    for (l_2137 = 2; (l_2137 >= 0); l_2137 -= 1)
                    {
                        int i;
                        l_2249 &= (((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((l_2183[l_2137] > (0L || (safe_rshift_func_uint8_t_u_u(l_2143[l_2137], (((g_849[0] | (((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(p_39, 4)), 13)) , ((safe_unary_minus_func_int8_t_s(((safe_rshift_func_int16_t_s_u(l_2183[l_2137], ((safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(l_258, 2)) , (safe_rshift_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((65535UL & ((((((((safe_mod_func_int8_t_s_s(l_2181, g_935)) , 0x3DL) == l_258) > 0xB5BB9598L) != l_261) ^ 0L) || l_2158) <= 4294967291UL)), g_59)) <= g_97[0]), 14))), l_2179)) != l_258) != g_143) & 0UL), l_258)) != p_39) || l_2158), 0x7D1913C8L)) <= l_2152))) ^ 0x99L))) | l_258)) | 0x6BL)) || l_419) & g_97[2]))))) ^ l_2143[l_2137]), l_1696[0])), 0xFB5B7956L)), 14)) < g_849[0]) , l_2199) <= l_419), l_1694)) && l_419) , 0x3F8D8182L);

for (l_363 = 0; l_363 < 1; l_363++)
        {
            for (l_392 = 0; l_392 < 10; l_392++)
            {
                transparent_crc(g_2470[l_656][l_363][l_392], "g_2470[l_656][l_363][l_392]", l_2180);

for (l_121 = 0; (l_121 > 43); l_121 = safe_add_func_uint8_t_u_u(l_121, 2))
                    {
                        uint16_t l_236 = 1UL;
                        g_120[1] = 0x724D0293L;
                        l_236 = l_296;
                        l_2261 = (safe_sub_func_int8_t_s_s((((((((l_296 || ((((1UL < ((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((((safe_mod_func_uint8_t_u_u(255UL, (safe_rshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s(((safe_sub_func_int8_t_s_s((safe_mod_func_int16_t_s_s(l_390, 65535UL)), l_198)) > ((safe_rshift_func_uint16_t_u_u(g_694, ((((safe_rshift_func_int16_t_s_u(((l_2155 , (((safe_add_func_uint32_t_u_u(g_143, g_120[1])) == l_198) , l_236)) & l_2155), g_694)) || g_97[2]) , l_296) , 0x2CA6L))) > 0x62L)), g_694)) | g_935), 0)))) | g_1168) && l_2181), 255UL)) | g_18), 11)) , l_2158)) || l_236) , 0x43L) | 1UL)) ^ g_694) , g_2467) < 0L) < l_390) != l_296) >= l_121), l_296));
                        l_296 = ((((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_u(((((((safe_add_func_uint16_t_u_u(l_121, g_101)) == ((safe_mod_func_int32_t_s_s((((((safe_add_func_int16_t_s_s((safe_sub_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u(((((safe_sub_func_uint32_t_u_u(l_281[4][6], l_2155)) ^ (((safe_add_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u((0x25D96900L <= (safe_sub_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s(l_236, g_2467)) < ((safe_lshift_func_int16_t_s_s(((0UL < (safe_mod_func_int8_t_s_s(l_2158, g_97[4]))) == g_120[2]), l_296)) < 7UL)), 2UL))), g_694)), 0x96E64D66L)) >= l_296), 0xFC6B1E59L)) < (-5L)) | 4294967292UL)) != l_2181) ^ 8L), (-7L))) & l_2158), l_2181)) > l_236) <= (-1L)), g_694)), g_694)) >= g_143) ^ 0xF7BFL) , l_296) == l_198), g_101)) && l_613)) | 1UL) != 0x6CL) <= l_281[0][2]) , 0x35L), l_121)) && g_694), 4)) & g_143) < 0x73054497L) != g_101);
                    };


                    if (l_2180) printf("index = [%d][%d][%d]\n", l_656, l_363, l_392);

            }
        };


                    l_261 ^= (l_2143[l_2137] && ((g_143 , (safe_sub_func_int8_t_s_s((((0x01B30B9BL ^ (1UL | (safe_sub_func_int32_t_s_s(l_2199, (((g_120[4] , g_849[0]) ^ g_2467) != l_2151))))) < 1UL) | 0x7EE96D31L), g_59))) == l_390));

l_472 ^= (l_2176[g_2469] && ((g_22 , (safe_sub_func_int8_t_s_s((((0x01B30B9BL ^ (1UL | (safe_sub_func_int32_t_s_s(l_2199, (((g_120[4] , g_849[0]) ^ l_2050) != l_2151))))) < 1UL) | 0x7EE96D31L), g_2431))) == l_2138));

                    l_2255[1] = (l_419 != g_59);
                    }
                    for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1)
                    {
                        int32_t l_2256 = 0x52D2483BL;
                        int32_t l_2257 = 1L;
                        int32_t l_2258[2][3];
                        int16_t l_2262 = 1L;
                        int i, j;

{
                        int32_t l_2256 = 0x52D2483BL;
                        int32_t l_2257 = 1L;
                        int32_t l_2258[2][3];
                        int16_t l_2262 = 1L;
                        int i, j;
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 3; j++)
                                l_2258[i][j] = 1L;
                        }
                        g_2469 = g_1368[g_2467];
                        l_2263--;
                        l_2055 &= (l_419 == l_2149);
                        g_2469 = (safe_sub_func_int16_t_s_s(((g_1482[2][1][1] | ((5L || (g_1548[3][7][1] != (safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((0x76L & ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((g_101 & (safe_lshift_func_uint16_t_u_u(((l_419 & (0x5EL <= ((safe_add_func_int8_t_s_s(1L, (g_1368[0] >= 0x02L))) <= l_2256))) != l_2177), 15))), l_2177)), g_1540[1][0])) < 0x866FL)) >= 0x9DEFCED1L), 0x570AL)), g_97[5])), l_2325)), l_419)))) , l_2143[2])) ^ 0xAB2DL), 0UL));
                    }

                    for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 3; j++)
                                l_2258[i][j] = 1L;
                        }
                        l_2101 = g_1368[l_2152];
                        l_2263--;
                        l_2260 &= (l_419 == p_39);

for (g_2100 = 0; g_2100 < 3; g_2100++)
    {
        for (p_39 = 0; p_39 < 3; p_39++)
        {
            transparent_crc(g_2184[g_2100][p_39], "g_2184[g_2100][p_39]", l_392);
            if (l_392) printf("index = [%d][%d]\n", g_2100, p_39);

        }
    };


                    l_1693 = (safe_sub_func_int16_t_s_s(((g_1482[2][1][1] | ((5L || (g_1548[3][7][1] != (safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((0x76L & ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((l_2039 & (safe_lshift_func_uint16_t_u_u(((l_419 & (0x5EL <= ((safe_add_func_int8_t_s_s(1L, (g_1368[0] >= 0x02L))) <= l_2256))) != l_351), 15))), l_2216)), g_1540[1][0])) < 0x866FL)) >= 0x9DEFCED1L), 0x570AL)), g_97[5])), l_1694)), l_419)))) , l_2143[2])) ^ 0xAB2DL), 0UL));
                    }
                }
            }
        }
        else
        {
            int32_t l_2300[5][8] = {{0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}};
            int32_t l_2321 = (-1L);
            uint32_t l_2322 = 0x99FED06DL;
            int i, j;
            for (l_2158 = 0; (l_2158 <= 2); l_2158 += 1)
            {
                g_120[1] = (safe_sub_func_int32_t_s_s(l_390, 0x8EEC641FL));
                for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1)
                {
                    const int16_t l_2298 = 0x7AB4L;
                    if (p_39)
                    {
                        int8_t l_2299 = 0xA2L;
                        g_120[4] = (safe_sub_func_uint32_t_u_u(g_2184[2][0], l_351));
                        g_120[1] = ((safe_rshift_func_int8_t_s_u(p_39, ((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((0x9CD8L && ((l_419 != (1UL & (l_258 , (safe_lshift_func_uint16_t_u_u((((p_39 == (0x32DBL >= (0x73E61AD3L < l_2298))) || p_40) >= l_2299), 4))))) >= 65535UL)), g_143)), p_39)) && 0x6D137FB0L))) && 7L);
                        l_2301--;

{
            transparent_crc(g_2184[l_395][l_2137], "g_2184[l_395][l_2137]", l_394);
            if (l_394) printf("index = [%d][%d]\n", l_395, l_2137);

        }

                    l_1648 = ((((safe_add_func_uint8_t_u_u(0x92L, l_2152)) & (((((((safe_lshift_func_int16_t_s_u((((l_2300[3][1] & ((safe_rshift_func_uint8_t_u_u(247UL, (safe_mod_func_uint8_t_u_u(1UL, (safe_mul_func_int16_t_s_s((+g_143), (g_1548[7][6][1] >= (safe_lshift_func_int8_t_s_u(g_935, 0))))))))) || ((safe_sub_func_int32_t_s_s((((safe_lshift_func_int16_t_s_u((-1L), 11)) == 0x5DL) | l_2299), 4294967295UL)) , l_2300[4][1]))) <= g_2184[2][0]) | l_2300[3][6]), 14)) , (-7L)) , p_39) != 0x6C7C71DBL) , g_18) , g_1548[4][6][2]) | g_2184[2][1])) == l_2141[1][6][5]) > l_258);
                    }
                    else
                    {
                        return l_419;
                    }
                }
                ++l_2322;
            }
        }
    }

{
                uint32_t l_2518 = 0x2412710BL;
                --l_2518;
            }

                    l_2326--;
    l_1651 = (safe_mod_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s((((safe_lshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s(l_1651, ((p_39 != 0xD257L) == (safe_sub_func_uint8_t_u_u((((safe_lshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s(((l_351 | ((safe_add_func_uint8_t_u_u(l_1651, ((((p_39 == (!(((!(~0xA2B5L)) || (l_351 != l_419)) , 0xBE0E0ABDL))) , l_2028) == 0x154C94FDL) <= 0xDCE7L))) & l_1695)) == g_1368[0]), l_419)), p_39)) > 0x8806C5F6L) > l_258), l_258))))), p_40)) | p_39) & l_1651), 0xD3L)) , g_97[2]), l_258));
    return l_1671;
}

                    g_120[1] = 0x724D0293L;
                        l_236 = p_40;
                        l_262 = (safe_sub_func_int8_t_s_s((((((((g_100 || ((((1UL < ((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((((safe_mod_func_uint8_t_u_u(255UL, (safe_rshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s(((safe_sub_func_int8_t_s_s((safe_mod_func_int16_t_s_s(l_253, 65535UL)), l_198)) > ((safe_rshift_func_uint16_t_u_u(p_42, ((((safe_rshift_func_int16_t_s_u(((l_258 , (((safe_add_func_uint32_t_u_u(g_143, g_120[1])) == l_198) , l_236)) & l_258), p_42)) || g_97[2]) , g_89) , 0x2CA6L))) > 0x62L)), p_42)) | l_261), 0)))) | l_210) && p_39), 255UL)) | g_18), 11)) , p_41)) || l_236) , 0x43L) | 1UL)) ^ p_42) , g_22) < 0L) < l_253) != g_89) >= l_121), g_89));

{
                        g_120[1] = 0xB8ED6298L;

for (l_368 = 0; l_368 < 7; l_368++)
    {
        transparent_crc(g_97[l_368], "g_97[l_368]", l_102);
        if (l_102) printf("index = [%d]\n", l_368);

    };


                    if (l_261)
                            continue;
                        l_253 &= (safe_mod_func_uint32_t_u_u(l_261, 0xE4729DD1L));
                    }


for (l_656 = 0; l_656 < 3; l_656++)
                            g_1368[l_656] = 5L;

                    l_296 = ((((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_u(((((((safe_add_func_uint16_t_u_u(l_121, g_101)) == ((safe_mod_func_int32_t_s_s((((((safe_add_func_int16_t_s_s((safe_sub_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u(((((safe_sub_func_uint32_t_u_u(l_281[4][6], l_258)) ^ (((safe_add_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u((0x25D96900L <= (safe_sub_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s(l_236, g_22)) < ((safe_lshift_func_int16_t_s_s(((0UL < (safe_mod_func_int8_t_s_s(p_41, g_97[4]))) == g_120[2]), p_40)) < 7UL)), 2UL))), p_42)), 0x96E64D66L)) >= g_89), 0xFC6B1E59L)) < (-5L)) | 4294967292UL)) != p_39) ^ 8L), (-7L))) & p_43), p_39)) > l_236) <= (-1L)), p_42)), p_42)) >= g_143) ^ 0xF7BFL) , p_40) == l_198), g_101)) && g_59)) | 1UL) != 0x6CL) <= l_281[0][2]) , 0x35L), l_121)) && p_42), 4)) & g_143) < 0x73054497L) != g_101);
                    }
                    for (l_86 = 0; (l_86 <= 4); l_86 += 1)
                    {
                        int i;
                        g_120[l_86] = ((safe_sub_func_int32_t_s_s(g_97[(l_86 + 2)], (safe_unary_minus_func_uint8_t_u(((((safe_sub_func_int16_t_s_s(((g_97[l_86] , 0xC6C2L) ^ 0xFEB2L), ((safe_rshift_func_uint16_t_u_u(g_97[(l_86 + 1)], ((safe_rshift_func_uint16_t_u_u(g_120[l_86], 5)) != (safe_mod_func_int8_t_s_s(((((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(g_120[l_86], ((0x60L < g_120[l_86]) , l_281[3][1]))), 0x2C0B2767L)) >= l_102) != p_40) != 255UL), 0xE6L))))) >= g_89))) != (-6L)) || g_120[0]) && g_97[(l_86 + 2)]))))) & g_101);
                        g_120[2] = ((-8L) == 0UL);

g_717 -= 1;



{
        for (l_656 = 0; l_656 < 3; l_656++)
        {
            transparent_crc(g_2184[l_253][l_656], "g_2184[l_253][l_656]", l_363);

g_2431 += 1;


                    if (l_363) printf("index = [%d][%d]\n", l_253, l_656);

        }
    }


{
        transparent_crc(g_849[g_2469], "g_849[g_2469]", l_363);
        if (l_363) printf("index = [%d]\n", g_2469);

    }

                    l_326 = ((((((((65535UL > (safe_mod_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((((l_262 || (l_198 || (safe_mod_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u((safe_rshift_func_int8_t_s_u(p_40, (((l_253 > (l_281[4][6] , p_42)) != ((safe_rshift_func_uint16_t_u_u(0xB25DL, 8)) || 1UL)) <= g_89))), g_101)) | g_97[2]), 1)), g_101)))) & p_42) || p_40), l_213[0])) & l_258), p_42))) <= p_40) < g_120[l_86]) == 0x8B28L) < g_89) || l_213[2]) != g_100) <= 246UL);
                        l_262 |= (~g_120[1]);
                    }
                }
                for (l_121 = 20; (l_121 < 40); l_121 = safe_add_func_uint32_t_u_u(l_121, 1))
                {
                    int8_t l_362 = 0x43L;
                    int32_t l_366 = (-2L);
                    uint8_t l_369 = 0x5AL;
                    int32_t l_393 = 0L;
                    if ((safe_add_func_int16_t_s_s(((((l_213[1] || ((p_41 >= (+(-1L))) >= (safe_lshift_func_int8_t_s_s(((safe_sub_func_int8_t_s_s((((safe_mod_func_int16_t_s_s(((safe_lshift_func_int16_t_s_s(l_121, 2)) == (((safe_lshift_func_uint16_t_u_s((g_59 || ((safe_rshift_func_uint16_t_u_s((((safe_add_func_int16_t_s_s(((((((safe_mod_func_int16_t_s_s(p_43, l_86)) <= 0x56719CF5L) < ((+(((((1UL && 0xD84E0731L) > l_281[6][4]) < g_143) > 0x15L) & 0xF7L)) | g_143)) , p_41) == l_350) , p_39), 0xA7B5L)) , 2L) , l_351), 11)) >= g_101)), l_210)) , 0x25L) < 7UL)), g_59)) <= 1UL) , l_210), g_59)) ^ 246UL), g_18)))) <= 0x83L) >= 6UL) & g_97[2]), p_39)))
                    {
                        uint32_t l_364 = 0UL;
                        int32_t l_365 = 1L;
                        l_364 = ((safe_add_func_int8_t_s_s((((safe_lshift_func_uint16_t_u_u(((((p_42 != l_296) > ((safe_lshift_func_uint16_t_u_u((0xA1L != (((-6L) && (((safe_rshift_func_int8_t_s_u(0x08L, ((p_43 < ((g_97[2] | (((safe_sub_func_uint16_t_u_u((((l_362 != 0xFEFA8AE2L) , g_101) != g_97[2]), g_100)) && 0x6386802AL) >= g_97[1])) >= g_89)) , p_39))) < 2UL) && l_281[4][6])) != l_198)), 0)) ^ p_39)) != g_97[2]) || 0xF9L), l_363)) || 0xD2L) , p_41), (-7L))) && p_41);


l_121 += 1;


                    if (g_97[2])
                            break;

                    ++l_369;

if (g_1168)
                            break;

                    if (l_281[4][3])
                            break;

{
        for (l_656 = 0; l_656 < 3; l_656++)
        {
            for (l_366 = 0; l_366 < 4; l_366++)
            {
                transparent_crc(g_1482[l_656][l_656][l_366], "g_1482[l_656][l_656][l_366]", g_2469);

for (l_656 = 0; l_656 < 8; l_656++)
        {
            for (i = 0; i < 3; i++)
            {
                transparent_crc(g_1548[l_368][l_656][i], "g_1548[l_368][l_656][i]", j);
                if (j) {
for (l_392 = 0; l_392 < 7; l_392++)
    {
        transparent_crc(g_97[l_392], "g_97[l_392]", j);
        if (j) printf("index = [%d]\n", l_392);

    };


                    printf("index = [%d][%d][%d]\n", l_368, l_656, i);}

            }
        };


                    if (g_2469) printf("index = [%d][%d][%d]\n", l_656, l_656, l_366);

            }
        }
    }

                    l_366 = p_39;
                    }
                    else
                    {
                        uint32_t l_384 = 0UL;
                        l_367 = (safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((p_42 , (safe_mod_func_int32_t_s_s((((((((((((p_40 , ((safe_mod_func_uint8_t_u_u((g_97[2] ^ (~(+l_296))), ((((g_97[3] & ((safe_sub_func_uint16_t_u_u((l_384 >= l_351), (((((((safe_lshift_func_int16_t_s_u((p_41 || (((((safe_rshift_func_int16_t_s_u((1UL != p_43), 4)) , 0x8DL) >= g_89) , l_389) , 0x343F8062L)), p_43)) > 4L) > p_41) , g_120[1]) != p_40) , p_39) == 0xCB3F649DL))) | p_41)) || g_89) | g_120[3]) && 0xE5L))) < 0UL)) >= g_97[1]) || 0x3F5AL) ^ l_261) || p_43) | l_366) , 0L) || (-1L)) ^ 0x8506B361L) >= p_42) ^ (-6L)), 0x3F0D7356L))), g_100)), g_22));
                        l_396--;
                    }
                    p_39 = (((((g_18 ^ (0UL & (((g_59 == (safe_mod_func_uint8_t_u_u(((((safe_sub_func_int16_t_s_s(((p_39 & ((safe_add_func_int8_t_s_s((((safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((((safe_mod_func_uint32_t_u_u((safe_sub_func_int16_t_s_s((((g_101 <= g_143) > (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(l_296, ((((((((safe_rshift_func_uint8_t_u_s(g_101, 1)) & (((l_281[4][6] || p_41) && p_41) | 0UL)) == g_120[1]) || l_121) < l_326) < g_101) || 0x3CL) < g_18))), 4))) >= (-1L)), l_351)), l_419)) || p_43) >= l_420), g_100)), g_89)) & (-1L)) | l_281[4][6]), 0x42L)) < g_97[3])) <= g_120[1]), g_120[3])) | l_396) != 0L) == l_391[1][4]), l_395))) > 0x32L) || l_390))) ^ p_43) | p_39) < p_40) < 1UL);
                    for (l_86 = 0; (l_86 <= 4); l_86 += 1)
                    {
                        int i;
                        return g_120[l_86];
                    }
                    if (g_143)
                        break;
                }
                for (l_363 = 0; (l_363 == (-23)); --l_363)
                {
                    uint32_t l_461[2][4][5] = {{{0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}}, {{0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}, {0xEE2EC9CFL, 0x5DDD064BL, 4294967288UL, 0x62B936CDL, 4294967288UL}}};
                    int i, j, k;
                    g_120[1] = ((0x7DDEF103L >= ((((safe_rshift_func_int16_t_s_u(((0x2CD8L == ((((((0x0CE5L > p_42) , (-9L)) || ((((safe_mod_func_uint32_t_u_u((g_120[1] > (0xD6FEED26L | ((l_427 >= (((((((safe_unary_minus_func_uint8_t_u(((safe_rshift_func_int8_t_s_s(g_97[1], 2)) != 0xEF0CL))) > 0x88D4L) && g_100) ^ g_120[1]) >= l_281[3][0]) | (-6L)) == 1L)) ^ 7UL))), 1UL)) < g_143) | g_100) , 0UL)) ^ (-1L)) | l_281[0][3]) == l_396)) >= 0xBDE2D00BL), 7)) , 7L) > p_42) || l_420)) , l_419);
                    l_431--;
                    p_39 = (((safe_unary_minus_func_int16_t_s(((((safe_unary_minus_func_uint16_t_u((l_326 , (((((~(safe_add_func_uint8_t_u_u((l_427 == (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_s(((safe_sub_func_int16_t_s_s(g_120[2], (((safe_add_func_uint8_t_u_u(((p_43 || ((safe_mod_func_int16_t_s_s(((((l_395 & ((0xAD109901L < ((((safe_rshift_func_uint8_t_u_s(p_40, 7)) != (p_41 <= (safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u((safe_sub_func_uint8_t_u_u(((((((((p_40 , 4UL) > 0UL) == 0xC8C73883L) <= l_427) ^ g_18) && l_121) || g_120[1]) & l_390), p_42)), l_461[1][1][2])), l_296)), p_40)))) <= l_461[1][1][2]) < 0x237EL)) <= 0x28L)) < 65535UL) | l_363) >= p_41), l_213[4])) < 5UL)) ^ l_253), g_59)) >= 0UL) | g_97[2]))) <= g_59), g_120[1])) ^ g_100), 7))), p_41))) < 1L) || g_89) ^ g_22) , 6UL)))) | g_143) != g_22) , l_368))) , 1UL) != 255UL);
                }
                g_120[1] ^= ((0L & 0x37L) >= (safe_sub_func_uint16_t_u_u(1UL, ((((safe_lshift_func_int8_t_s_u((g_97[3] >= (safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s(((((((safe_lshift_func_uint16_t_u_s(((((0xC0653759L ^ l_363) , p_41) == (l_392 != p_39)) , 1UL), p_39)) , 4L) , g_22) || 0x464EEE5AL) | 8UL) & l_472), 5)) , 0x83F7DA68L) && g_18), 1UL))), 5)) <= l_86) < 65531UL) || l_396))));
            }
        }

g_2469 |= (~g_120[1]);

                    for (l_102 = 29; (l_102 != (-14)); l_102--)
        {
            uint16_t l_507 = 65527UL;
            int32_t l_520[5][4] = {{0x55AC6CE3L, 1L, (-1L), (-1L)}, {0x55AC6CE3L, 1L, (-1L), (-1L)}, {0x55AC6CE3L, 1L, (-1L), (-1L)}, {0x55AC6CE3L, 1L, (-1L), (-1L)}, {0x55AC6CE3L, 1L, (-1L), (-1L)}};
            int32_t l_567 = (-1L);
            int32_t l_655 = (-2L);
            uint8_t l_696 = 0xEEL;
            uint16_t l_711[6] = {0x6659L, 0x6659L, 65527UL, 0x6659L, 0x6659L, 65527UL};
            int i, j;

for (l_616 = 0; (l_616 <= 4); l_616 += 1)
                    {
                        int i;
                        return g_120[l_616];
                    };


                    if (g_18)
            {
                uint8_t l_508 = 1UL;

{
        transparent_crc(g_120[p_39], "g_120[p_39]", l_368);
        if (l_368) printf("index = [%d]\n", p_39);

    }

                    g_120[1] = (safe_rshift_func_int16_t_s_s(((!(1UL >= (((0xE1L != ((((safe_rshift_func_int16_t_s_s(((safe_lshift_func_int8_t_s_u((((safe_sub_func_int8_t_s_s(g_89, ((safe_rshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((65526UL & (safe_rshift_func_int16_t_s_s((((((g_100 != g_59) >= ((((safe_rshift_func_int8_t_s_s((safe_add_func_uint16_t_u_u(1UL, (((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u((!(safe_add_func_int8_t_s_s(((((safe_lshift_func_uint8_t_u_s((g_120[1] && ((safe_mod_func_uint8_t_u_u(0x86L, g_120[3])) <= g_22)), l_507)) <= (-10L)) && 1L) & l_508), 0x6CL))), 3)), 2)) ^ l_390) && p_40))), 7)) > l_253) && p_43) == 0x785C2DE3L)) & l_508) ^ l_419) , p_43), g_120[0]))), l_351)), 0)) <= g_97[2]))) , p_41) , l_507), g_59)) == g_101), l_351)) && l_86) & g_18) , g_143)) ^ 0x3CL) , 1UL))) ^ l_507), g_89));
            }
            else
            {
                int8_t l_513[10][2] = {{0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}};
                int32_t l_569[8][6][5] = {{{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}};
                uint32_t l_642 = 18446744073709551615UL;
                int i, j, k;
                for (g_22 = 0; (g_22 >= 55); g_22 = safe_add_func_int32_t_s_s(g_22, 5))
                {
                    int8_t l_523 = 0xDBL;
                    l_520[1][3] = ((((p_40 || 0UL) != p_43) <= (safe_rshift_func_int16_t_s_u(0x4F5AL, (l_86 ^ (0x7DL <= l_513[9][0]))))) , (g_89 ^ (safe_mod_func_uint16_t_u_u((((safe_rshift_func_int16_t_s_s((safe_mod_func_int32_t_s_s(l_121, g_97[2])), 12)) < p_40) | l_513[9][0]), p_41))));
                    for (l_86 = (-26); (l_86 <= 16); l_86++)
                    {
                        int8_t l_524 = (-8L);
                        l_524 = l_523;

g_100 -= 1;



{
                        uint16_t l_861 = 0x987DL;
                        g_120[1] = ((safe_add_func_int16_t_s_s(0x6D2DL, l_861)) > 9L);
                        return g_849[p_39];
                    }

                    p_39 &= l_524;
                    }
                }
                if (((safe_mod_func_int16_t_s_s(g_89, (safe_rshift_func_int8_t_s_s(g_59, 1)))) > (0xAD5285A3L <= l_513[9][0])))
                {
                    uint16_t l_533 = 0xB016L;
                    g_540 &= (safe_add_func_int32_t_s_s((1UL != g_120[1]), (safe_add_func_int8_t_s_s((g_120[1] || (p_41 > (((((((l_533 >= p_42) & p_43) || ((safe_unary_minus_func_uint8_t_u(l_472)) & (((safe_lshift_func_int8_t_s_s((+(safe_rshift_func_int16_t_s_u((l_507 , 0xDD7CL), g_120[3]))), l_368)) ^ 8L) , p_42))) > p_43) != l_507) > 0xEEL) , l_102))), p_43))));
                    for (l_121 = 10; (l_121 != 4); l_121--)
                    {
                        const uint16_t l_568[6][9][4] = {{{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}};
                        const uint8_t l_576 = 249UL;
                        int i, j, k;
                        l_569[7][2][2] = (((safe_rshift_func_uint8_t_u_u(g_143, 6)) , (safe_rshift_func_uint16_t_u_u((((l_213[2] <= (((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((((((((l_513[9][1] | g_97[2]) || g_59) ^ 0x77L) , ((safe_rshift_func_uint16_t_u_s(p_43, (((safe_rshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((((((safe_lshift_func_uint16_t_u_u((((((safe_lshift_func_uint8_t_u_u(l_296, 5)) == ((((((safe_rshift_func_uint8_t_u_s(((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(9UL, 4)) < l_520[1][3]), g_59)) && g_100), g_18)) < p_40) , p_40) < 0xA5D176F9L) || g_89) != p_41)) || g_540) >= l_567) != g_18), 5)) != 0xFB0274BAL) > l_389) && l_567) != p_42), l_513[5][0])), 4)) == g_22) != g_540))) > l_102)) ^ g_59) | l_507) | l_568[1][1][0]) && l_520[1][3]), l_533)), 0UL)) , l_513[8][1]) && p_41)) <= 0x1E8AL) || p_39), 13))) , p_41);

l_213[2] |= l_533;

                    l_368 = (safe_rshift_func_int16_t_s_s((safe_rshift_func_uint16_t_u_s((safe_add_func_int16_t_s_s(l_576, ((safe_sub_func_uint32_t_u_u(4294967295UL, ((safe_lshift_func_int8_t_s_u(p_43, (safe_add_func_uint32_t_u_u((((safe_add_func_int16_t_s_s((safe_add_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u(g_100, g_120[1])) , 0xD285L), (p_41 , (0UL != (safe_lshift_func_int16_t_s_u((((safe_sub_func_int16_t_s_s((!((((safe_add_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((-1L), 13)) | g_22), l_569[7][2][2])) <= l_513[9][0]) || l_598[1]) <= g_18)), l_213[2])) ^ p_40) , 0xDB70L), g_89)))))), p_41)) > g_120[1]) >= p_39), g_97[5])))) ^ 0x9F178DF0L))) && l_598[1]))), 7)), p_41));
                        p_39 = ((+0x203AL) && (safe_rshift_func_uint8_t_u_s((0xF62F64AEL < (((safe_sub_func_int32_t_s_s((((safe_lshift_func_uint8_t_u_s(0x12L, 1)) & ((safe_rshift_func_int16_t_s_u(((safe_sub_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_u(p_39, p_41)), (((!((g_97[1] | (l_389 || ((l_613 < l_507) == l_520[1][3]))) , p_43)) >= (-1L)) && p_41))) , 0xD86FL), 2)) & 255UL)) > p_42), 0x9FADD9B3L)) , 0L) | p_43)), l_533)));
                        if (p_41)
                            continue;
                    }

{
                        int i;

{
        for (l_368 = 0; l_368 < 1; l_368++)
        {
            for (l_368 = 0; l_368 < 10; l_368++)
            {
                transparent_crc(g_2470[l_253][l_368][l_368], "g_2470[l_253][l_368][l_368]", l_567);
                if (l_567) printf("index = [%d][%d][%d]\n", l_253, l_368, l_368);

            }
        }
    }

                    i = (safe_mod_func_int32_t_s_s(g_97[g_100], l_696));
                        g_100 = g_18;
                        g_2254 &= 0xEC293C97L;
                    }


if (p_41)
                    continue;

                    for (l_86 = (-15); (l_86 < 46); l_86 = safe_add_func_uint32_t_u_u(l_86, 1))
                    {

{
                        k = l_394;
                    }

                    --l_616;
                        l_520[1][3] = (l_102 != ((~(safe_lshift_func_int16_t_s_u(g_143, p_42))) <= (safe_add_func_int8_t_s_s(g_89, 1L))));

{
        transparent_crc(g_97[l_102], "g_97[l_102]", l_394);

for (j = 0; j < 3; j++)
    {
        for (j = 0; j < 1; j++)
        {
            for (j = 0; j < 10; j++)
            {
                transparent_crc(g_2470[j][j][j], "g_2470[j][j][j]", k);
                if (k) printf("index = [%d][%d][%d]\n", j, j, j);

            }
        }
    };


                    if (l_394) printf("index = [%d]\n", l_102);

    }

                    if (g_97[2])
                            break;

j &= (safe_rshift_func_uint16_t_u_u(i, 8));

                    return g_101;
                    }
                }
                else
                {

if ((safe_lshift_func_int16_t_s_s(g_2254, (((((g_2254 && (((safe_sub_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((((0x23L && l_569[4][5][3]) != (safe_sub_func_uint32_t_u_u(g_89, g_97[1]))) , (safe_add_func_int8_t_s_s(l_368, l_696))), g_935)), l_616)) < 4294967295UL) | g_2414)) ^ 0x77L) , l_368) , 0x3B0A0897L) >= g_97[4]))))
                {
                    l_368 &= (safe_rshift_func_uint16_t_u_u(g_2469, 8));
                }
                else
                {
                    for (g_717 = 0; (g_717 <= 5); g_717 += 1)
                    {

l_699 -= 1;


                    return l_567;
                    }
                    return g_120[1];
                };


                    g_120[1] = 1L;
                }

if (((safe_mod_func_int16_t_s_s(l_296, (safe_rshift_func_int8_t_s_s(g_1171, 1)))) > (0xAD5285A3L <= l_513[9][0])))
                {
                    uint16_t l_533 = 0xB016L;
                    g_694 &= (safe_add_func_int32_t_s_s((1UL != g_120[1]), (safe_add_func_int8_t_s_s((g_120[1] || (p_43 > (((((((l_533 >= g_101) & p_43) || ((safe_unary_minus_func_uint8_t_u(g_694)) & (((safe_lshift_func_int8_t_s_s((+(safe_rshift_func_int16_t_s_u((l_507 , 0xDD7CL), g_120[3]))), l_656)) ^ 8L) , g_101))) > p_43) != l_507) > 0xEEL) , g_2469))), p_43))));
                    for (l_696 = 10; (l_696 != 4); l_696--)
                    {
                        const uint16_t l_568[6][9][4] = {{{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}};
                        const uint8_t l_576 = 249UL;
                        int i, j, k;
                        l_569[7][2][2] = (((safe_rshift_func_uint8_t_u_u(g_1168, 6)) , (safe_rshift_func_uint16_t_u_u((((l_213[2] <= (((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((((((((l_513[9][1] | g_97[2]) || g_1171) ^ 0x77L) , ((safe_rshift_func_uint16_t_u_s(p_43, (((safe_rshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((((((safe_lshift_func_uint16_t_u_u((((((safe_lshift_func_uint8_t_u_u(l_296, 5)) == ((((((safe_rshift_func_uint8_t_u_s(((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(9UL, 4)) < l_520[1][3]), g_1171)) && l_699), g_18)) < l_296) , l_296) < 0xA5D176F9L) || l_296) != p_43)) || g_694) >= k) != g_18), 5)) != 0xFB0274BAL) > l_507) && k) != g_101), l_513[5][0])), 4)) == l_642) != g_694))) > g_2469)) ^ g_1171) | l_507) | l_568[1][1][0]) && l_520[1][3]), l_533)), 0UL)) , l_513[8][1]) && p_43)) <= 0x1E8AL) || k), 13))) , p_43);
                        l_656 = (safe_rshift_func_int16_t_s_s((safe_rshift_func_uint16_t_u_s((safe_add_func_int16_t_s_s(l_576, ((safe_sub_func_uint32_t_u_u(4294967295UL, ((safe_lshift_func_int8_t_s_u(p_43, (safe_add_func_uint32_t_u_u((((safe_add_func_int16_t_s_s((safe_add_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u(l_699, g_120[1])) , 0xD285L), (p_43 , (0UL != (safe_lshift_func_int16_t_s_u((((safe_sub_func_int16_t_s_s((!((((safe_add_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((-1L), 13)) | l_642), l_569[7][2][2])) <= l_513[9][0]) || l_598[1]) <= g_18)), l_213[2])) ^ l_296) , 0xDB70L), l_296)))))), p_43)) > g_120[1]) >= k), g_97[5])))) ^ 0x9F178DF0L))) && l_598[1]))), 7)), p_43));
                        k = ((+0x203AL) && (safe_rshift_func_uint8_t_u_s((0xF62F64AEL < (((safe_sub_func_int32_t_s_s((((safe_lshift_func_uint8_t_u_s(0x12L, 1)) & ((safe_rshift_func_int16_t_s_u(((safe_sub_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_u(k, p_43)), (((!((g_97[1] | (l_507 || ((l_613 < l_507) == l_520[1][3]))) , p_43)) >= (-1L)) && p_43))) , 0xD86FL), 2)) & 255UL)) > g_101), 0x9FADD9B3L)) , 0L) | p_43)), l_533)));
                        if (p_43)
                            continue;
                    }
                    for (l_613 = (-15); (l_613 < 46); l_613 = safe_add_func_uint32_t_u_u(l_613, 1))
                    {
                        --g_1171;
                        l_520[1][3] = (g_2469 != ((~(safe_lshift_func_int16_t_s_u(g_1168, g_101))) <= (safe_add_func_int8_t_s_s(l_296, 1L))));
                        if (g_97[2])
                            break;
                        return g_101;
                    }
                }
                else
                {
                    g_120[1] = 1L;
                };


                    p_39 = (((((safe_add_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s((((0xA08E28CFL <= (g_143 == (((safe_rshift_func_int16_t_s_u(p_39, 8)) && (safe_rshift_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_mod_func_uint8_t_u_u(g_120[1], l_616)), (0L > g_100))), (g_100 || (safe_sub_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u(g_143, l_642)) | l_569[7][2][1]), 0UL)))))) | l_507))) | p_42) , p_43), 15)) != p_43), g_540)) && g_22) | l_520[0][2]) >= l_394) >= p_39);
                if ((safe_lshift_func_int16_t_s_s(p_42, (((((p_42 && (((safe_sub_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((((0x23L && l_569[4][5][3]) != (safe_sub_func_uint32_t_u_u(l_296, g_97[1]))) , (safe_add_func_int8_t_s_s(p_39, l_121))), g_101)), l_613)) < 4294967295UL) | p_41)) ^ 0x77L) , l_394) , 0x3B0A0897L) >= g_97[4]))))
                {
                    p_39 &= (safe_rshift_func_uint16_t_u_u(l_655, 8));
                }
                else
                {
                    for (g_100 = 0; (g_100 <= 5); g_100 += 1)
                    {
                        return l_656;
                    }
                    return g_120[1];
                }
            }
            if (((((((safe_add_func_int16_t_s_s(((p_41 == (safe_sub_func_int8_t_s_s(g_18, (65529UL | 0L)))) , (safe_sub_func_int8_t_s_s(((p_40 ^ ((g_97[3] >= ((((safe_lshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u(l_368, 1)) , (safe_mod_func_uint32_t_u_u(l_507, (~(g_101 && 0xFDA677A5L))))), g_143)) ^ g_22) & p_42) & 1L)) == g_120[1])) && p_39), p_39))), g_143)) == p_43) && 255UL) < g_97[1]) >= l_296) ^ p_41))
            {
                int32_t l_691 = 0x098722ADL;
                int32_t l_693 = (-10L);


for (l_368 = 0; l_368 < 6; l_368++)
    {
        transparent_crc(g_2003[l_368], "g_2003[l_368]", l_253);
        if (l_253) printf("index = [%d]\n", l_368);

    };


                    for (l_253 = 0; l_253 < 10; l_253++)
            {
                transparent_crc(g_2470[l_102][l_693][l_253], "g_2470[l_102][l_693][l_253]", l_567);
                if (l_567) {
{
                g_777--;
            }

                    printf("index = [%d][%d][%d]\n", l_102, l_693, l_253);}

            }

{
            int16_t l_786 = 8L;
            int32_t l_789 = 2L;
            int32_t l_791 = 0xB2B08DC3L;
            uint32_t l_794 = 0x67A078F5L;
            l_567 = (safe_rshift_func_int16_t_s_u(g_717, 9));
            if (l_396)
                break;
            for (l_567 = 0; (l_567 <= (-8)); l_567--)
            {
                return l_786;
            }
            for (g_935 = 2; (g_935 < 14); g_935 = safe_add_func_uint16_t_u_u(g_935, 3))
            {
                l_794--;
            }
        }

                    for (l_102 = 29; (l_102 != (-14)); l_102--)
        {
            uint16_t l_507 = 65527UL;
            int32_t l_520[5][4] = {{0x55AC6CE3L, 1L, (-1L), (-1L)}, {0x55AC6CE3L, 1L, (-1L), (-1L)}, {0x55AC6CE3L, 1L, (-1L), (-1L)}, {0x55AC6CE3L, 1L, (-1L), (-1L)}, {0x55AC6CE3L, 1L, (-1L), (-1L)}};
            int32_t l_567 = (-1L);
            int32_t l_655 = (-2L);
            uint8_t l_696 = 0xEEL;
            uint16_t l_711[6] = {0x6659L, 0x6659L, 65527UL, 0x6659L, 0x6659L, 65527UL};
            int i, j;
            if (g_18)
            {
                uint8_t l_508 = 1UL;
                g_120[1] = (safe_rshift_func_int16_t_s_s(((!(1UL >= (((0xE1L != ((((safe_rshift_func_int16_t_s_s(((safe_lshift_func_int8_t_s_u((((safe_sub_func_int8_t_s_s(g_717, ((safe_rshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((65526UL & (safe_rshift_func_int16_t_s_s((((((g_100 != g_2431) >= ((((safe_rshift_func_int8_t_s_s((safe_add_func_uint16_t_u_u(1UL, (((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u((!(safe_add_func_int8_t_s_s(((((safe_lshift_func_uint8_t_u_s((g_120[1] && ((safe_mod_func_uint8_t_u_u(0x86L, g_120[3])) <= g_2467)), l_507)) <= (-10L)) && 1L) & l_508), 0x6CL))), 3)), 2)) ^ l_691) && g_100))), 7)) > l_655) && p_43) == 0x785C2DE3L)) & l_508) ^ l_419) , p_43), g_120[0]))), g_101)), 0)) <= g_97[2]))) , p_41) , l_507), g_2431)) == g_101), g_101)) && l_616) & g_18) , g_777)) ^ 0x3CL) , 1UL))) ^ l_507), g_717));
            }
            else
            {
                int8_t l_513[10][2] = {{0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}};
                int32_t l_569[8][6][5] = {{{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}};
                uint32_t l_642 = 18446744073709551615UL;
                int i, j, k;

{
                        i = ((l_121 < (safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((g_2467 < 0L), (g_2467 >= 0L))), (-1L)))) >= ((safe_lshift_func_uint8_t_u_u(((g_2469 || 252UL) , ((((safe_lshift_func_int8_t_s_s(k, 7)) != 0L) == p_42) , g_849[0])), l_419)) >= g_2100));
                    }

                    for (g_2467 = 0; (g_2467 >= 55); g_2467 = safe_add_func_int32_t_s_s(g_2467, 5))
                {
                    int8_t l_523 = 0xDBL;

{
            int16_t l_786 = 8L;
            int32_t l_789 = 2L;
            int32_t l_791 = 0xB2B08DC3L;
            uint32_t l_794 = 0x67A078F5L;
            g_2469 = (safe_rshift_func_int16_t_s_u(l_296, 9));
            if (l_642)
                break;
            for (g_2469 = 0; (g_2469 <= (-8)); g_2469--)
            {
                return l_786;
            }
            for (g_694 = 2; (g_694 < 14); g_694 = safe_add_func_uint16_t_u_u(g_694, 3))
            {
                l_794--;
            }
        }

                    l_520[1][3] = ((((g_100 || 0UL) != p_43) <= (safe_rshift_func_int16_t_s_u(0x4F5AL, (l_616 ^ (0x7DL <= l_513[9][0]))))) , (g_717 ^ (safe_mod_func_uint16_t_u_u((((safe_rshift_func_int16_t_s_s((safe_mod_func_int32_t_s_s(g_2431, g_97[2])), 12)) < g_100) | l_513[9][0]), p_41))));
                    for (l_616 = (-26); (l_616 <= 16); l_616++)
                    {
                        int8_t l_524 = (-8L);
                        l_524 = l_523;
                        l_368 &= l_524;
                    }
                }
                if (((safe_mod_func_int16_t_s_s(g_717, (safe_rshift_func_int8_t_s_s(g_2431, 1)))) > (0xAD5285A3L <= l_513[9][0])))
                {
                    uint16_t l_533 = 0xB016L;
                    g_101 &= (safe_add_func_int32_t_s_s((1UL != g_120[1]), (safe_add_func_int8_t_s_s((g_120[1] || (p_41 > (((((((l_533 >= g_2254) & p_43) || ((safe_unary_minus_func_uint8_t_u(g_935)) & (((safe_lshift_func_int8_t_s_s((+(safe_rshift_func_int16_t_s_u((l_507 , 0xDD7CL), g_120[3]))), l_691)) ^ 8L) , g_2254))) > p_43) != l_507) > 0xEEL) , l_102))), p_43))));
                    for (g_2431 = 10; (g_2431 != 4); g_2431--)
                    {
                        const uint16_t l_568[6][9][4] = {{{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}};
                        const uint8_t l_576 = 249UL;
                        int i, j, k;
                        l_569[7][2][2] = (((safe_rshift_func_uint8_t_u_u(g_777, 6)) , (safe_rshift_func_uint16_t_u_u((((l_213[2] <= (((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((((((((l_513[9][1] | g_97[2]) || g_2431) ^ 0x77L) , ((safe_rshift_func_uint16_t_u_s(p_43, (((safe_rshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((((((safe_lshift_func_uint16_t_u_u((((((safe_lshift_func_uint8_t_u_u(g_100, 5)) == ((((((safe_rshift_func_uint8_t_u_s(((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(9UL, 4)) < l_520[1][3]), g_2431)) && g_100), g_18)) < g_100) , g_100) < 0xA5D176F9L) || g_717) != p_41)) || g_101) >= l_567) != g_18), 5)) != 0xFB0274BAL) > g_1217) && l_567) != g_2254), l_513[5][0])), 4)) == g_2467) != g_101))) > l_102)) ^ g_2431) | l_507) | l_568[1][1][0]) && l_520[1][3]), l_533)), 0UL)) , l_513[8][1]) && p_41)) <= 0x1E8AL) || l_368), 13))) , p_41);
                        l_691 = (safe_rshift_func_int16_t_s_s((safe_rshift_func_uint16_t_u_s((safe_add_func_int16_t_s_s(l_576, ((safe_sub_func_uint32_t_u_u(4294967295UL, ((safe_lshift_func_int8_t_s_u(p_43, (safe_add_func_uint32_t_u_u((((safe_add_func_int16_t_s_s((safe_add_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u(g_100, g_120[1])) , 0xD285L), (p_41 , (0UL != (safe_lshift_func_int16_t_s_u((((safe_sub_func_int16_t_s_s((!((((safe_add_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((-1L), 13)) | g_2467), l_569[7][2][2])) <= l_513[9][0]) || l_598[1]) <= g_18)), l_213[2])) ^ g_100) , 0xDB70L), g_717)))))), p_41)) > g_120[1]) >= l_368), g_97[5])))) ^ 0x9F178DF0L))) && l_598[1]))), 7)), p_41));
                        l_368 = ((+0x203AL) && (safe_rshift_func_uint8_t_u_s((0xF62F64AEL < (((safe_sub_func_int32_t_s_s((((safe_lshift_func_uint8_t_u_s(0x12L, 1)) & ((safe_rshift_func_int16_t_s_u(((safe_sub_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_u(l_368, p_41)), (((!((g_97[1] | (g_1217 || ((g_1171 < l_507) == l_520[1][3]))) , p_43)) >= (-1L)) && p_41))) , 0xD86FL), 2)) & 255UL)) > g_2254), 0x9FADD9B3L)) , 0L) | p_43)), l_533)));
                        if (p_41)
                            continue;
                    }
                    for (l_616 = (-15); (l_616 < 46); l_616 = safe_add_func_uint32_t_u_u(l_616, 1))
                    {
                        --l_613;
                        l_520[1][3] = (l_102 != ((~(safe_lshift_func_int16_t_s_u(g_777, g_2254))) <= (safe_add_func_int8_t_s_s(g_717, 1L))));
                        if (g_97[2])
                            break;

if (g_2254)
                            break;

                    return g_101;
                    }
                }
                else
                {
                    g_120[1] = 1L;
                }
                l_368 = (((((safe_add_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s((((0xA08E28CFL <= (g_777 == (((safe_rshift_func_int16_t_s_u(l_368, 8)) && (safe_rshift_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_mod_func_uint8_t_u_u(g_120[1], l_613)), (0L > g_100))), (g_100 || (safe_sub_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u(g_777, l_642)) | l_569[7][2][1]), 0UL)))))) | l_507))) | g_2254) , p_43), 15)) != p_43), g_101)) && g_2467) | l_520[0][2]) >= l_691) >= l_368);
                if ((safe_lshift_func_int16_t_s_s(g_2254, (((((g_2254 && (((safe_sub_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((((0x23L && l_569[4][5][3]) != (safe_sub_func_uint32_t_u_u(g_100, g_97[1]))) , (safe_add_func_int8_t_s_s(l_368, g_2431))), g_101)), g_1171)) < 4294967295UL) | p_41)) ^ 0x77L) , l_691) , 0x3B0A0897L) >= g_97[4]))))
                {
                    l_368 &= (safe_rshift_func_uint16_t_u_u(l_655, 8));
                }
                else
                {
                    for (g_100 = 0; (g_100 <= 5); g_100 += 1)
                    {

{
    const int32_t l_1494 = 1L;
    int32_t l_1549 = 3L;
    int32_t l_1648 = (-7L);
    int32_t l_1651 = 0x03FC532BL;
    uint32_t l_1671 = 0x5D19C228L;
    int32_t l_1693 = 6L;
    int32_t l_1694 = 0x93E56D52L;
    int32_t l_1695 = (-8L);
    int32_t l_1696[1];
    int32_t l_1698 = 0x373FD168L;
    int16_t l_1726 = 0x18DBL;
    int8_t l_1888[4] = {(-1L), 0xDAL, (-1L), 0xDAL};
    const int32_t l_2028 = 0L;
    uint32_t l_2050 = 0xE1AEC0EFL;
    int32_t l_2055 = 0x3AFF1B97L;
    int32_t l_2141[2][9][9] = {{{(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}}, {{(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}, {(-1L), 0xA2DF3799L, 0L, 0L, 0xE05CC0F0L, 0xBF96A785L, 0xE05CC0F0L, 0L, 0L}}};
    int32_t l_2178[3];
    int16_t l_2182 = 0L;
    int32_t l_2325 = 0xDDB3E8D8L;
    uint32_t l_2326 = 4UL;
    int i, j, k;
    for (i = 0; i < 1; i++)
        l_1696[i] = (-1L);
    for (i = 0; i < 3; i++)
        l_2178[i] = 0xA248903FL;
    for (l_699 = (-17); (l_699 != (-29)); l_699--)
    {
        int32_t l_1489[4][8][8] = {{{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}, {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}, {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}, {{(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}, {(-9L), 0L, 0L, 0xCE3C3B5DL, 0x461AD9A7L, (-8L), 1L, 0x4803C05CL}}};
        uint32_t l_1504 = 0x5BA9BBE8L;
        uint8_t l_1505 = 0xECL;
        int32_t l_1537 = 0L;
        int32_t l_1639 = (-1L);
        int32_t l_1644[7][7][5] = {{{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}, {{0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}, {0x43661B5DL, 0x0C1C4156L, 0L, (-8L), 0x6DC3101FL}}};
        int32_t l_1705 = 0x5B922F92L;
        const int32_t l_1724 = (-1L);
        int8_t l_1725 = (-7L);
        uint16_t l_1799[5][6];
        int32_t l_1842 = 1L;
        int8_t l_1854 = 1L;
        uint32_t l_1887 = 0x40D66011L;
        uint32_t l_1905 = 5UL;
        int8_t l_1931[6] = {(-1L), (-1L), 1L, (-1L), (-1L), 1L};
        uint8_t l_2006 = 255UL;
        int i, j, k;
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 6; j++)
                l_1799[i][j] = 65535UL;
        }
        l_1489[2][4][7] |= (safe_rshift_func_uint16_t_u_s(g_540, (safe_add_func_int8_t_s_s(0x34L, 0x31L))));
        g_120[2] = (((((((safe_add_func_int16_t_s_s((((g_59 , 0xE95DL) != ((((safe_rshift_func_uint8_t_u_s((l_1489[3][4][7] > 0x91L), 3)) & ((l_1494 >= (((safe_lshift_func_uint8_t_u_s(g_18, 5)) & (((safe_sub_func_uint16_t_u_u((l_1494 | (((safe_sub_func_uint8_t_u_u((((safe_sub_func_int8_t_s_s((((l_1489[2][4][7] == (+(((l_121 || g_59) ^ l_656) < l_1504))) > 8UL) != 4294967286UL), 0xBAL)) != l_419) , 246UL), g_1482[2][0][1])) ^ l_1504) > l_656)), g_1368[0])) ^ l_1504) <= 4294967295UL)) && 0x59L)) < l_1489[0][5][2])) , (-10L)) & 0xF980F758L)) ^ g_777), l_696)) == 1UL) >= g_97[3]) > l_1504) > l_656) > l_1505) >= g_59);
        if (l_1494)
            break;
        for (g_1217 = (-15); (g_1217 != 6); g_1217++)
        {
            const uint32_t l_1522[6][9] = {{0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}, {0x7C2D2C19L, 0x7C2D2C19L, 3UL, 0x91735878L, 1UL, 0x39DCD8D2L, 0x38E53B65L, 0x7C2D2C19L, 2UL}};
            uint16_t l_1591 = 7UL;
            int32_t l_1599 = 0x10CC3626L;
            int16_t l_1633 = 0x164AL;
            int32_t l_1634 = 0x157EBADBL;
            int32_t l_1643[6][4][8] = {{{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}, {{3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}, {3L, 0x37F5EF1AL, 0x786B0D09L, (-6L), 0x42958925L, 0xE7C5776DL, 0xBFED9D93L, 0x29968C4FL}}};
            uint32_t l_1659 = 0x83EA5D3CL;
            uint32_t l_1699 = 0x2C42C799L;
            uint16_t l_1706 = 0x0899L;
            int32_t l_1806 = 0x9CB7724BL;
            uint32_t l_1837 = 3UL;
            uint32_t l_1846 = 0xD008E7A8L;
            int i, j, k;
            if (((!(safe_add_func_int32_t_s_s((l_419 || l_419), ((((safe_lshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s((0x15L <= (l_696 <= ((safe_add_func_uint16_t_u_u((!g_849[0]), ((((safe_sub_func_int32_t_s_s(((((g_59 , ((g_59 | ((((((safe_sub_func_uint8_t_u_u((g_1368[1] <= l_1489[2][7][0]), (-1L))) ^ l_472) | l_396) , 255UL) , l_419) < g_120[0])) < g_59)) ^ l_1494) , l_1522[4][1]) < g_101), 4294967295UL)) != 0x6AL) || g_18) >= l_419))) < l_1505))), g_717)) , 0x5997L), l_419)) <= g_717) , l_1522[0][5]) <= l_656)))) == l_1522[4][1]))
            {
                uint32_t l_1543 = 7UL;
                int32_t l_1547 = (-6L);
                int32_t l_1640 = 0x4E27C546L;
                int32_t l_1641 = 1L;
                int32_t l_1646 = 0xFBA92B18L;
                int32_t l_1647 = 0xBA2A75F3L;
                int32_t l_1649 = 0L;
                int32_t l_1650 = (-1L);
                int32_t l_1652 = (-1L);
                int32_t l_1654 = (-5L);
                int32_t l_1655 = 0L;
                int32_t l_1697 = 0L;
                for (l_419 = 5; (l_419 != 57); ++l_419)
                {
                    int32_t l_1533[2][4] = {{0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}, {0x902650EEL, 0x19200A77L, 0x902650EEL, 0x19200A77L}};
                    int32_t l_1542[8][7][3] = {{{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}, {{0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}, {0x668B73B2L, 0xF9691E2AL, 0xE2B07B07L}}};
                    int i, j, k;
                    if (((0UL <= (safe_rshift_func_int8_t_s_u(g_59, 5))) & (((((((l_656 , ((safe_add_func_int32_t_s_s(0L, (safe_mod_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((((l_656 == l_1533[1][2]) && (((l_419 && ((l_1489[3][7][5] & 0x189D8138L) & g_101)) ^ g_97[2]) | l_1505)) <= (-6L)), 12)), 0x4AL)))) & l_1505)) <= g_59) == 1L) || l_1494) | l_1494) > 0xA7L) & 1L)))
                    {
                        l_1537 &= ((safe_rshift_func_uint8_t_u_s((((l_656 ^ (~((g_97[2] == l_656) , g_1217))) | (l_1522[2][7] | (((g_717 || l_1505) , (((0x07L == (-1L)) < 0xBECEL) || l_1533[1][2])) ^ g_97[1]))) , 255UL), 1)) && (-1L));
                        g_120[2] = (safe_add_func_int32_t_s_s(g_717, g_1368[1]));
                        g_120[1] = g_1540[1][0];
                    }
                    else
                    {
                        int8_t l_1541 = (-1L);
                        int32_t l_1546 = 0x3C02C0E7L;
                        uint32_t l_1550 = 1UL;
                        l_1543++;
                        if (l_1489[0][4][1])
                            continue;
                        --l_1550;
                    }
                    for (l_1537 = 10; (l_1537 >= 5); l_1537 = safe_sub_func_uint32_t_u_u(l_1537, 6))
                    {
                        int16_t l_1581 = 0x4CE7L;
                        if (l_419)
                            break;
                        g_120[1] = (l_1549 || (0xA427L == (safe_mod_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((g_1368[1] == 1UL), (-1L))), 0x2E3AL))));
                        g_120[1] = ((+(g_59 < ((((((safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((~l_472), ((safe_lshift_func_int8_t_s_s(l_1547, (safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((+((safe_add_func_int8_t_s_s((0UL != (((safe_rshift_func_int8_t_s_u((g_717 > g_1368[2]), 1)) == (safe_unary_minus_func_int8_t_s((l_419 , (safe_rshift_func_uint8_t_u_s((((safe_mod_func_int8_t_s_s((0x71L >= l_1581), 0xB6L)) , l_419) <= l_656), 3)))))) && g_777)), 0UL)) ^ l_1522[0][5])) & 1UL), l_419)), 13)))) , 0x89L))), g_59)) != l_1537) , g_1217) || 65531UL) > l_656) < 0x33D41A9EL))) , l_121);
                    }
                    for (g_101 = 0; (g_101 <= 4); g_101 += 1)
                    {
                        int16_t l_1588[5][10][5] = {{{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}, {{(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}, {(-2L), 0xDF7FL, 0x9E4EL, (-7L), (-7L)}}};
                        const int16_t l_1592 = (-1L);
                        int i, j, k;
                        g_120[g_101] = ((safe_sub_func_int32_t_s_s(l_472, 0xC58F4B07L)) ^ ((((((-1L) > (((((safe_add_func_int8_t_s_s(((((safe_sub_func_uint32_t_u_u(((l_1588[4][3][4] | (0xBBL | g_97[2])) ^ l_1542[2][5][1]), (g_59 , (safe_lshift_func_uint16_t_u_u(((0x8B2D6D5DL < (-6L)) < 0x8664AFBBL), 8))))) & l_419) > 7L) >= l_1591), l_1588[1][8][4])) && l_419) == 1UL) , l_1592) && g_97[2])) || l_699) <= l_419) || g_1217) >= l_1533[1][2]));
                        return l_1549;
                    }
                }
                if ((((safe_rshift_func_uint8_t_u_s(l_1549, 4)) >= (safe_lshift_func_uint8_t_u_s(l_1591, (safe_lshift_func_int8_t_s_s(l_1599, 1))))) != ((safe_lshift_func_int16_t_s_u((!(((g_59 >= l_1547) , ((!g_849[0]) >= ((g_717 <= (!(((safe_rshift_func_uint8_t_u_u((((safe_rshift_func_uint16_t_u_u((((g_101 > 0L) ^ l_656) < l_1504), g_59)) || 0x729EL) > 0xD46FL), 2)) < g_97[2]) , 6UL))) || g_59))) | l_1489[2][4][7])), 12)) == g_59)))
                {
                    uint16_t l_1611 = 0xD966L;
                    int32_t l_1636 = 1L;
                    int32_t l_1638[4][6][7] = {{{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}, {{0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}, {0x6566DF0BL, 5L, (-7L), 0L, 1L, 0x097A03BDL, 0x2E53E7D0L}}};
                    uint8_t l_1656[3][8][6] = {{{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}, {{7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}, {7UL, 0x45L, 251UL, 0x07L, 0UL, 0x86L}}};
                    int i, j, k;
                    g_120[1] = ((((l_419 & ((safe_mul_func_uint8_t_u_u(l_1611, ((((l_1494 | (safe_mod_func_int8_t_s_s(l_656, (safe_lshift_func_uint16_t_u_u((((((((+(l_1494 , ((l_1504 & (safe_lshift_func_uint16_t_u_s((((+(((((((g_540 <= (((((l_656 & ((0x4BA9L | 0xAB14L) == 0xB0E53EB1L)) == 0x49L) >= l_642) && l_656) < l_1611)) > 0x891AL) ^ 0xC4L) >= g_777) > l_1599) ^ g_849[0]) < l_1591)) & 0x2C1DL) >= 0L), 14))) , l_642))) & l_472) != 0x3AL) , g_59) && l_699) ^ l_656) >= g_59), 1))))) && l_419) >= l_1522[4][1]) <= 0x012802EEL))) ^ 0x6FL)) | g_59) != 4294967290UL) | g_120[4]);
                    if ((l_1489[2][4][7] <= (g_97[0] <= l_1494)))
                    {
                        int32_t l_1635 = 0L;
                        int32_t l_1637 = 1L;
                        int32_t l_1642 = (-3L);
                        int32_t l_1645[4][10][3] = {{{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}, {{0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}, {0L, 0L, 0L}}};
                        int8_t l_1653 = 0xE0L;
                        int i, j, k;
                        l_1634 = (((((safe_mod_func_uint16_t_u_u((safe_unary_minus_func_uint8_t_u((safe_sub_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((l_656 ^ (((((safe_mod_func_uint8_t_u_u(((((safe_add_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(((l_419 && (((g_59 , l_1494) > (l_656 & l_642)) >= (-2L))) == ((-1L) & ((0x2C2C4A06L || 0L) != g_717))), 0x84D0E611L)) < 247UL), l_1537)) == g_1540[0][1]) != 65535UL) != (-5L)), l_1599)) , g_777) , l_1611) == g_59) && 9L)) >= 0x3E95L), l_656)), l_419)))), 65530UL)) >= l_1549) | 0xA236F820L) , l_1611) < l_1633);
                        l_1656[1][6][4]++;
                        ++l_1659;
                    }
                    else
                    {
                        int32_t l_1692 = 1L;
                        l_1671 = (((safe_mod_func_uint16_t_u_u((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u((((l_1651 , ((((l_351 != l_1611) >= (safe_sub_func_uint8_t_u_u(0xEEL, g_849[0]))) <= l_642) != (1UL & g_59))) && (!(l_1651 >= l_1644[2][1][0]))) || l_1641), (-2L))), 1UL)), g_120[1])) > 0x1BL) | 0xC3L);
                        g_120[1] = (+1UL);
                        l_1643[3][1][5] = (safe_add_func_uint32_t_u_u(0UL, (((safe_rshift_func_uint16_t_u_u(((safe_mod_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((~l_656), ((0x60L ^ ((l_1651 == ((((((-1L) == ((0x4B8FL == (g_59 | (((6L | (safe_rshift_func_uint16_t_u_u(((((((((safe_lshift_func_int8_t_s_u(((~(((((safe_mod_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(((!(1UL != g_717)) > l_1522[2][7]), g_120[1])), l_1638[0][0][2])) < 4294967295UL) , l_419) , 0xE3L) , 0x49L)) && 0x109AL), 6)) , g_101) || 4294967288UL) < 0x758ECAE5L) , l_419) > l_1692) != g_120[4]) == 0x90143625L), g_120[0]))) != g_59) | g_18))) | (-1L))) > l_419) > g_540) , l_419) != l_419)) < l_1692)) < g_18))), g_59)) | 0x4510FC82L), g_777)) > 2UL) != l_1643[0][3][1])));
                    }
                }
                else
                {
                    g_120[4] = l_419;
                    if (l_1671)
                        break;
                }
                ++l_1699;
            }
            else
            {
                int8_t l_1702[4] = {0x92L, 1L, 0x92L, 1L};
                int32_t l_1703 = (-7L);
                int32_t l_1704[7][6][6] = {{{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}, {{(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}, {(-9L), (-1L), 0xBDC814B4L, 0x2CB8391FL, 0xBB96DC80L, 0x841B2AA2L}}};
                uint8_t l_1730[3][2];
                uint32_t l_1764 = 0x54F33472L;
                int i, j, k;
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 2; j++)
                        l_1730[i][j] = 0x7BL;
                }
                g_120[2] = g_1548[4][6][2];
                --l_1706;
                if ((((g_717 < ((safe_sub_func_int8_t_s_s(g_1540[1][0], (((((((1L | (l_1643[4][0][3] != ((safe_sub_func_int16_t_s_s(((safe_sub_func_int32_t_s_s(g_1548[9][3][2], (((((safe_add_func_uint16_t_u_u((!l_1699), g_120[0])) != ((safe_sub_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u((0UL != ((g_59 > l_1698) , l_1671)), 6)), l_1703)), l_1724)) < 255UL)) , l_1537) == l_1725) < l_1489[2][4][7]))) > l_1726), (-10L))) == l_656))) , 0x853A9528L) != 1UL) , l_1706) >= 0x1C39L) == 0xF5678FABL) , 0xD3L))) < 0x7EB415D5L)) != l_396) || 4294967289UL))
                {
                    int32_t l_1727 = 0L;
                    int32_t l_1728 = 4L;
                    int32_t l_1729[4][6][7] = {{{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}, {{(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}, {(-1L), (-6L), 0x86BB00ECL, (-5L), 0L, 0xF2E762D9L, 0x11543290L}}};
                    int i, j, k;
                    --l_1730[2][0];
                }
                else
                {
                    uint16_t l_1751 = 0UL;
                    for (g_717 = 0; (g_717 <= 3); g_717 += 1)
                    {
                        int i, j, k;
                        l_1644[g_717][g_717][g_717] ^= (safe_lshift_func_uint8_t_u_u((l_1489[g_717][(g_717 + 2)][g_717] >= (safe_add_func_int32_t_s_s(0x76753DFBL, ((safe_rshift_func_uint8_t_u_s((safe_mod_func_int16_t_s_s(5L, (safe_lshift_func_int16_t_s_u((((safe_lshift_func_uint16_t_u_u(g_1482[2][1][1], 6)) < ((safe_mod_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(0xAAD7L, (((safe_add_func_int32_t_s_s((l_1751 && (((safe_add_func_uint8_t_u_u((((((~(l_1695 , (((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s((g_1368[1] || (((((+(safe_lshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u(l_1549, 9UL)), g_101))) , l_656) , g_717) != 0xB3L) > l_656)), 6L)), 0x65A1L)) != 65533UL) >= l_1751))) >= l_1764) | l_1730[2][0]) , l_1751) , l_1751), 0UL)) <= g_1548[5][0][1]) && 255UL)), g_777)) ^ l_699) >= g_97[2]))), g_59)) , l_419)) | l_1751), l_1698)))), l_1751)) & l_419)))), g_777));
                    }
                    l_1651 = (l_1489[3][7][7] > ((g_1548[4][6][2] ^ (!((((((safe_rshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s(0x2D2C9E59L, (l_1764 | (safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(((((((l_1751 == ((l_656 == (safe_sub_func_uint16_t_u_u(((((l_396 & (safe_add_func_uint16_t_u_u((0L > ((((l_121 && l_1702[3]) >= g_59) & 0x3E3BL) , l_1730[2][0])), g_120[1]))) , 8L) , 0L) & l_1659), l_419))) || l_1764)) >= g_777) == l_1643[2][2][1]) == 0x34FBL) | 0x6190L) | g_59), g_59)) >= l_656), g_59)) < 0x90L), g_777)) & 0x68AFL), g_717)) , g_540), l_699))))), l_1724)), g_59)) || 4294967286UL), 13)) <= g_59) ^ 1L) , l_699) <= l_1751) & 0xABL))) | l_1706));
                    l_1643[0][3][1] ^= l_1751;
                }
                return g_59;
            }
            for (l_1634 = 0; (l_1634 >= 17); l_1634 = safe_add_func_int16_t_s_s(l_1634, 4))
            {
                const uint32_t l_1798[7][8] = {{0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}, {0x659DA0B9L, 0x659DA0B9L, 0xCFD1424FL, 0x9AE21F5DL, 0UL, 2UL, 0x14481399L, 0x659DA0B9L}};
                int i, j;
                l_1799[1][5] = ((6L ^ (safe_rshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s(((((((g_1217 ^ (((0L >= (((safe_lshift_func_uint8_t_u_u(0x33L, l_419)) ^ l_1699) , (safe_lshift_func_int8_t_s_s(g_540, 1)))) == ((((l_1489[2][4][7] , (l_1798[3][0] && l_1705)) & 1UL) & g_1540[0][1]) & g_849[0])) >= g_1368[2])) || 2L) , g_120[1]) | 9UL) , g_1548[1][1][0]) && 1UL), l_1699)), 0))) >= 0x9FEE1EABL);
            }
            g_120[1] |= (((g_849[0] <= (safe_add_func_int32_t_s_s(l_419, l_419))) <= ((((((safe_mod_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u((l_656 && ((l_419 == l_1806) > ((safe_rshift_func_int16_t_s_u(((((((g_97[2] | g_59) && ((!((safe_rshift_func_int16_t_s_s(((0L | l_1549) , l_656), g_777)) ^ l_1698)) ^ 0L)) == g_59) , 1L) || 0xE5L) <= l_121), 15)) || l_1806))), 3)) > l_472) ^ l_419), l_642)) ^ g_1368[1]) || 1L) != (-5L)) , 4294967290UL) <= l_419)) ^ 0x02D0829CL);
            if ((safe_lshift_func_int8_t_s_s(0xBCL, 7)))
            {
                int8_t l_1831 = (-6L);
                int32_t l_1849[6] = {(-1L), 6L, (-1L), 6L, (-1L), 6L};
                const uint8_t l_1889 = 252UL;
                int i;
                for (l_1706 = 0; (l_1706 >= 36); l_1706 = safe_add_func_uint32_t_u_u(l_1706, 3))
                {
                    int32_t l_1836[9][5] = {{(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}, {(-1L), (-3L), (-1L), (-4L), (-6L)}};
                    int32_t l_1841 = (-3L);
                    int32_t l_1844 = 8L;
                    int32_t l_1845 = 0xBE0388A2L;
                    int16_t l_1853 = 0xBF53L;
                    uint16_t l_1856 = 0x14A1L;
                    int i, j;
                    g_120[4] ^= (((safe_add_func_uint32_t_u_u((0x22L == (((((l_1648 , (((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((~((((((g_1368[2] >= ((0xEF5AL != (safe_sub_func_int8_t_s_s(((g_1482[2][1][1] && ((safe_add_func_int8_t_s_s((((safe_sub_func_uint16_t_u_u(((((l_1831 | (((g_59 > g_1540[1][0]) >= (((safe_rshift_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((g_1368[2] > 0x5C49CB64L), 5)) | l_1831) , l_1836[4][3]) == g_1368[1]) && l_121), g_540)) >= 0x624C7317L) == l_656)) <= g_59)) , g_59) , 1UL) , g_849[0]), 0xF010L)) ^ 0UL) <= g_849[0]), g_540)) > 1L)) & l_1698), l_656))) == 0xE4B6B42FL)) | l_1799[2][5]) , 0L) >= g_1217) & l_1699) , l_1489[0][3][5])), 10)), l_419)) == g_97[2]) >= l_419)) || l_472) , l_1831) == l_656) ^ g_849[0])), g_59)) | l_1837) , l_1724);
                    for (l_696 = 13; (l_696 >= 1); l_696 = safe_sub_func_int32_t_s_s(l_696, 9))
                    {
                        uint8_t l_1840 = 0x4FL;
                        int32_t l_1843 = 1L;
                        int32_t l_1850 = (-10L);
                        int32_t l_1851 = 0x86429966L;
                        int32_t l_1852 = 0xCA3D88B8L;
                        int32_t l_1855 = 1L;
                        l_1840 = g_1217;
                        --l_1846;
                        --l_1856;
                    }
                    for (l_1841 = (-19); (l_1841 != (-8)); l_1841++)
                    {
                        uint16_t l_1886[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_1886[i] = 7UL;
                        g_120[1] &= l_1696[0];
                        g_120[0] = (((((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u(65535UL, 13)) , 0x9426L), (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_u(l_656, (((((0xEF2D849BL || l_1591) & (l_1841 , (safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u((((((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s(g_777, (safe_rshift_func_uint16_t_u_s((((l_1799[1][5] > (safe_add_func_uint16_t_u_u(0x2E1AL, 0xBDC1L))) >= l_1836[0][4]) == l_1886[0]), 13)))) | (-2L)), l_1887)) & g_59) < 0xBEL) < g_777) & l_1888[2]), 0x66L)), l_419)), 4)), 7)), 0UL)))) , 1UL) ^ l_1889) == 0xEAL))))))) > 0x483D69BBL) , l_1844) , 247UL) ^ l_1706);
                        l_1644[0][3][4] = ((((-2L) == (safe_add_func_uint16_t_u_u((((((((((safe_add_func_int32_t_s_s(((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s((safe_mod_func_int8_t_s_s((251UL != ((!l_1905) == (((g_97[1] | (safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s(0xF54AL, 2)) && ((((l_419 > ((((l_1853 & (safe_add_func_uint16_t_u_u(0x3ED4L, 1L))) ^ l_656) | 1L) ^ l_1849[1])) > (-1L)) && l_472) != 0UL)), 0xEB10B25CL)), 10))) < g_1482[2][1][1]) || 0x405D3F2AL))), l_1599)), 1)), 2)) && g_1217), 5)) && 4294967295UL), 4294967293UL)) , l_656), 4294967288UL)) | g_59) || g_59) && l_1639) && l_656) && 0x068C0922L) , l_696) , (-1L)) < l_419), 1UL))) ^ l_1846) || l_1699);
                        l_1693 = (safe_lshift_func_uint8_t_u_s(g_59, ((safe_rshift_func_int8_t_s_s(9L, g_540)) != l_1846)));
                    }
                }
                g_120[1] ^= ((g_59 & (0x8889L >= (l_656 == ((safe_unary_minus_func_uint8_t_u(0UL)) <= (safe_mod_func_int16_t_s_s(g_1482[3][0][1], ((l_656 > (((~l_419) && ((~(!((((safe_sub_func_uint16_t_u_u((((((((g_59 < ((((l_656 , l_656) >= 0x93L) , 1UL) ^ g_717)) ^ l_419) == l_1889) & 0UL) , l_699) < l_1799[4][4]) < 4294967295UL), l_1849[0])) <= 1L) , g_59) , 0x3CL))) , l_419)) >= 7L)) & l_1648))))))) | l_1831);
                l_1643[0][3][1] = (l_696 > 0x5B7FL);
            }
            else
            {
                uint32_t l_1932 = 1UL;
                int32_t l_1945 = 0L;
                int32_t l_1946[1];
                uint32_t l_1971 = 0x9EF11B35L;
                uint8_t l_1990 = 0xB6L;
                int i;
                for (i = 0; i < 1; i++)
                    l_1946[i] = 3L;
                for (l_472 = (-11); (l_472 < (-24)); --l_472)
                {
                    int32_t l_1929 = 0L;
                    int32_t l_1930 = 0x01C56913L;
                    uint8_t l_1949 = 0xBEL;
                    int32_t l_2005 = 0L;
                    if (g_59)
                    {
                        int32_t l_1928[10] = {0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L, 0x6399E99BL, 0x3C11E539L};
                        int i;
                        l_1932--;
                    }
                    else
                    {
                        l_1693 = l_656;
                    }
                    if ((g_59 , l_1694))
                    {
                        int8_t l_1947 = 0x1BL;
                        int32_t l_1948 = 0x27F08C10L;
                        l_1945 = (((0x03L == (0xA11DL < (l_121 | ((((0x6F1BL != l_351) < (((((((((safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(g_97[2], l_696)), 2)) > (safe_add_func_uint16_t_u_u(g_1548[4][6][2], 0x34DEL))) & l_419), l_1706)) , 0x3208L) , g_1540[1][0]) , l_1930) == l_472) , g_1548[0][0][1]) <= l_1932) > l_419) >= 0UL)) < l_419) >= l_656)))) ^ g_97[2]) , g_849[0]);
                        ++l_1949;
                        g_120[4] = (safe_mod_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s(6L, (safe_sub_func_uint8_t_u_u(0x94L, (((l_1949 | (safe_rshift_func_int8_t_s_u(((((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((((+(safe_add_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(((0xB3EFL || (l_1947 | (((g_120[1] ^ ((((-2L) & (((l_419 ^ (l_1945 , 0x78L)) , l_1971) < l_656)) < 0xA9FBL) == l_656)) < l_1806) < 0xE1L))) && l_1948), 0x64L)) , l_656), 9UL))) >= 0x60B3L) != l_656) ^ l_656), g_59)), 0x0DAEL)), l_1887)) >= l_1947) > l_656) == l_419), l_1948))) , 5L) | 0xB082A17BL))))) , 0x11L), 0x03L));
                    }
                    else
                    {
                        l_1930 = ((0L & l_656) != (!((safe_mod_func_uint8_t_u_u(g_59, 0x7AL)) > (((l_1932 | l_656) , 0x1F0EL) < (l_419 && ((((safe_mod_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u(l_1854, l_419)), 0x3929L)) != 0L) == 0x2F747C30L) , 0x96347F98L))))));
                    }
                    if (((safe_lshift_func_uint16_t_u_s((g_1540[1][0] , l_1930), l_419)) & (((l_351 < (((((safe_lshift_func_int16_t_s_u(((l_656 , ((l_419 && (((safe_unary_minus_func_int16_t_s(((safe_add_func_uint16_t_u_u(l_1693, ((((safe_add_func_uint16_t_u_u((l_1591 ^ l_656), l_1990)) < l_419) < 0x1D1DL) | g_540))) | g_120[1]))) , l_656) && l_1643[1][1][6])) ^ g_717)) , l_656), l_1599)) | l_419) <= 0UL) != (-8L)) , l_656)) < l_1698) || 0x837FL)))
                    {
                        int8_t l_2002 = 0x5BL;
                        int32_t l_2004[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_2004[i] = 7L;
                        g_2003[0] |= (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((((((safe_rshift_func_uint16_t_u_u(g_1482[0][1][0], ((~((((-6L) < l_419) >= g_120[1]) | (l_419 , l_419))) != (((safe_lshift_func_uint16_t_u_s(((g_1548[4][6][2] || ((((safe_rshift_func_int8_t_s_s(1L, 4)) <= 0xC812E52FL) || g_1368[1]) <= 0UL)) , l_1888[1]), 3)) != l_656) < 65535UL)))) | g_1482[2][1][1]) <= 4294967292UL) && l_1929) > l_2002), g_849[0])), g_59));
                        l_2006--;
                        if (l_1888[1])
                            break;
                    }
                    else
                    {
                        uint8_t l_2013[2][2] = {{1UL, 0x0EL}, {1UL, 0x0EL}};
                        int i, j;
                        g_120[1] = (safe_rshift_func_int16_t_s_u((((safe_sub_func_uint8_t_u_u((0xBC96E130L > l_2013[1][0]), ((safe_add_func_uint8_t_u_u(((l_2005 >= (((safe_add_func_uint8_t_u_u((((l_1725 & l_2013[0][1]) , ((safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(g_1548[4][6][2], l_1932)) , ((safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((l_419 ^ ((safe_mod_func_uint16_t_u_u((65534UL <= l_1549), l_419)) , g_120[3])) || l_1591), g_97[1])) > l_396), (-4L))) > 7L)), l_1949)) == l_1888[2])) < g_59), 9UL)) | g_1368[1]) & l_1639)) <= l_1930), 0x27L)) & 9UL))) && g_59) , 0x1E18L), g_18));
                    }
                    g_120[1] = ((((0UL == (0x99L == g_1482[2][1][1])) , l_2028) , g_97[2]) > ((g_120[3] > ((((((safe_lshift_func_uint16_t_u_s(((safe_rshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s(((0x83922D4EL != ((-8L) > 0x08L)) || l_1634), 5)), l_1671)) >= l_1634), 15)) < l_656) , 0xAC9FE61AL) , l_656) > l_419) | g_1540[1][0])) ^ (-1L)));
                }
            }
        }
    }
    for (g_717 = 0; (g_717 == 7); g_717 = safe_add_func_uint8_t_u_u(g_717, 6))
    {
        int16_t l_2039 = 0x0ABAL;
        const uint16_t l_2040 = 65532UL;
        int32_t l_2061 = 0x90A8BF10L;
        int32_t l_2101 = 0x02F00675L;
        int32_t l_2137 = 0L;
        int32_t l_2143[3];
        uint32_t l_2152 = 0xDB2A778AL;
        uint16_t l_2158 = 0xFEEFL;
        uint16_t l_2301 = 0xE812L;
        int i;
        for (i = 0; i < 3; i++)
            l_2143[i] = 0x4EA06463L;
        if ((safe_add_func_uint8_t_u_u(1UL, ((((1UL | ((l_1671 , ((g_849[0] , l_2039) != ((((l_2040 , (-9L)) <= 0x9EA7L) > g_59) , l_419))) <= l_699)) == l_1888[2]) || l_656) ^ l_351))))
        {
            uint32_t l_2062 = 4UL;
            int32_t l_2136 = 0x587994DEL;
            int32_t l_2138 = 0x39236B84L;
            int32_t l_2139 = 0x2CD995FBL;
            int32_t l_2140 = (-1L);
            int32_t l_2142 = 0x807412D1L;
            int32_t l_2146 = (-8L);
            int32_t l_2147 = (-7L);
            int32_t l_2149 = 0x0E72D148L;
            int32_t l_2151 = 0x4ECFBDFFL;
            uint8_t l_2155 = 0x86L;
            int32_t l_2176[3];
            int16_t l_2177 = 0x3603L;
            int32_t l_2179 = 1L;
            int32_t l_2180 = 1L;
            int32_t l_2181 = 0xDF8F0F9CL;
            int32_t l_2183[5] = {0x3D5D9951L, 0L, 0x3D5D9951L, 0L, 0x3D5D9951L};
            uint16_t l_2185 = 0x30E9L;
            int8_t l_2259[8] = {0xA3L, 0x43L, 0xA3L, 0x43L, 0xA3L, 0x43L, 0xA3L, 0x43L};
            int i;
            for (i = 0; i < 3; i++)
                l_2176[i] = (-1L);
            l_2061 = (safe_rshift_func_uint8_t_u_u(((((l_2039 , (safe_mod_func_int16_t_s_s((+((safe_sub_func_uint32_t_u_u((((safe_add_func_int8_t_s_s((0x9FB88B87L <= (l_2050 && l_2028)), ((safe_add_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(g_120[4], (l_2055 | g_59))), ((safe_unary_minus_func_uint32_t_u((safe_mod_func_uint8_t_u_u((((((((safe_rshift_func_uint8_t_u_u(g_120[1], 3)) ^ 0L) < l_2039) && 0L) < l_396) & 0xF6503CF8L) > l_419), l_419)))) , l_1696[0]))) , l_1888[2]))) == 1UL) , l_419), l_1648)) < 0x0C40299FL)), g_59))) || 0x6671L) && g_101) < g_101), 3));
            if ((l_2062 == 0xF331L))
            {
                uint32_t l_2075 = 0x3F7E974AL;
                int32_t l_2076 = 0xDD959D4BL;
                uint32_t l_2121 = 0xDB46FF94L;
                int32_t l_2135 = 0x8FD202FEL;
                int32_t l_2144 = 7L;
                int32_t l_2145 = 0x543A4A56L;
                int32_t l_2148 = (-7L);
                int32_t l_2150 = (-4L);
                for (l_121 = 11; (l_121 > 6); l_121 = safe_sub_func_uint16_t_u_u(l_121, 8))
                {
                    uint16_t l_2105 = 65535UL;
                    for (l_2050 = 0; (l_2050 != 38); ++l_2050)
                    {
                        l_1695 = ((g_59 < (safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((l_419 < 0L), (l_419 >= 0L))), (-1L)))) >= ((safe_lshift_func_uint8_t_u_u(((l_656 || 252UL) , ((((safe_lshift_func_int8_t_s_s(l_1549, 7)) != 0L) == l_472) , g_849[0])), l_2075)) >= l_2076));
                    }
                    for (l_2055 = (-27); (l_2055 <= (-28)); l_2055--)
                    {
                        uint32_t l_2102 = 0x75F47E93L;
                        g_120[2] = (safe_sub_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((l_472 > l_419), (safe_sub_func_uint8_t_u_u(((l_656 & (g_59 & ((((~((((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(l_642, (((((safe_lshift_func_int8_t_s_s(((safe_mod_func_uint8_t_u_u((((0xDFF1L > ((safe_sub_func_int8_t_s_s((((+((!(((safe_lshift_func_int16_t_s_s(0xF854L, 8)) ^ g_1482[2][1][1]) ^ g_101)) , g_120[4])) == 0UL) ^ g_717), g_59)) , 1L)) , g_717) | g_2003[3]), g_849[0])) || 0x4AL), g_59)) > g_59) & g_97[3]) == g_1368[1]) , 0x821DL))), l_419)) & 0xDCA8CE5FL) <= l_2040) > l_656)) | l_656) , g_59) || l_656))) , l_2076), 0x74L)))), k));
                        l_2101 |= 9L;
                        l_2102 &= g_59;
                    }
                    for (l_2076 = 7; (l_2076 >= (-7)); --l_2076)
                    {
                        uint32_t l_2108 = 0xCCCFDF72L;
                        l_2105 ^= l_656;
                        g_120[2] = (((safe_rshift_func_uint8_t_u_u((((g_1482[2][1][3] , (((l_2108 | g_120[3]) == l_419) , ((safe_lshift_func_uint16_t_u_s(((safe_sub_func_uint8_t_u_u(((0UL && g_2003[1]) || 1UL), ((safe_sub_func_uint8_t_u_u(((((safe_sub_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((g_59 && (safe_lshift_func_uint8_t_u_s((0x24L >= 0UL), 0))), l_419)), l_2121)) <= l_2040) & l_699) , l_419), 1UL)) >= l_2108))) >= l_656), 12)) >= (-1L)))) | g_97[2]) != g_59), 2)) ^ 0xB68DD604L) == 0UL);
                    }
                    l_1693 = (g_717 != (safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s((((-1L) || 0x95L) & g_1368[1]), ((safe_lshift_func_uint8_t_u_u(255UL, 7)) >= (((((safe_unary_minus_func_uint16_t_u(1UL)) , ((((l_419 == ((l_2105 , (safe_sub_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(g_101, g_120[1])) , l_2039), l_2062))) == g_59)) , 0x8847L) == l_472) , 0x73EDD688L)) == l_656) , l_2062) < l_472)))), 8)));
                }
                l_2152++;
                l_2145 = ((((l_2151 , (l_2155 != g_59)) || (0xADL && 0x61L)) < l_419) < ((safe_lshift_func_uint16_t_u_s(0xD3B9L, (2UL < ((((0x7EC0L & g_120[1]) & 4294967295UL) || 1UL) & 0x5C680109L)))) == 0xC0DAL));
            }
            else
            {
                uint32_t l_2161 = 0x817ED328L;
                l_2101 |= (7L ^ (g_59 > (((l_2158 < (g_59 & ((safe_lshift_func_uint8_t_u_u(0x2CL, 3)) || (255UL >= g_59)))) , g_1548[2][0][1]) == l_2161)));
                l_2151 = (safe_sub_func_uint32_t_u_u((g_2003[0] >= ((g_59 >= (safe_add_func_int32_t_s_s(((((((safe_add_func_int8_t_s_s(((((safe_sub_func_int8_t_s_s(k, (safe_sub_func_uint16_t_u_u(0xB24EL, ((((safe_mod_func_uint32_t_u_u(g_777, ((((safe_sub_func_int32_t_s_s((0L == l_2176[0]), (0x17L && (g_717 , 0x38L)))) > g_777) , 255UL) && l_642))) || 0x8F222FB3L) || 0xC79840FEL) ^ g_59))))) < g_59) , l_121) > g_97[5]), 7UL)) < g_120[2]) , g_120[1]) & l_2146) <= g_1217) && g_18), g_59))) && g_59)), l_699));
            }
            l_2185++;
            for (l_1671 = 0; (l_1671 <= 8); l_1671 = safe_add_func_uint8_t_u_u(l_1671, 6))
            {
                const int8_t l_2199 = (-1L);
                int32_t l_2255[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_2255[i] = 0L;
                for (l_121 = 0; (l_121 == 34); l_121 = safe_add_func_uint8_t_u_u(l_121, 3))
                {
                    int16_t l_2216 = 0x83C6L;
                    int32_t l_2249 = 0xEA87154FL;
                    int32_t l_2260 = 0xF84A0E45L;
                    int32_t l_2261 = 0xC424E530L;
                    uint16_t l_2263 = 65530UL;
                    for (k = 0; (k <= (-15)); k = safe_sub_func_uint32_t_u_u(k, 1))
                    {
                        const uint8_t l_2200 = 0xE4L;
                        uint16_t l_2217 = 3UL;
                        l_2143[0] = (0UL >= ((g_1368[0] != (((safe_add_func_int16_t_s_s(((+(l_2176[0] && ((((0xEEL >= g_120[1]) && (+l_699)) || l_419) > (((((~(l_656 <= (l_2199 , 0L))) >= (-1L)) <= l_656) , l_121) , l_396)))) > l_419), l_2200)) | l_2200) , l_472)) != g_97[5]));
                        g_120[1] = (safe_lshift_func_int8_t_s_u(((safe_mod_func_uint16_t_u_u(g_59, (((l_2040 || (safe_unary_minus_func_int8_t_s(((safe_mod_func_int16_t_s_s((0L != ((safe_sub_func_uint32_t_u_u(0xF9EC49D5L, (safe_lshift_func_uint8_t_u_s(((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(((((-8L) && (0x53L || 1L)) < (l_472 == (((0xAC9BL > l_419) <= l_396) >= l_656))) , l_2216), 2)) && 0xE90C1C13L), 2L)) , l_472) , 0UL) , l_2101), 7)))) , g_59)), g_59)) < l_351)))) != 0L) || l_2217))) > l_656), 6));
                        g_120[1] &= l_2200;
                        if (l_699)
                            break;
                    }
                    if ((g_1482[2][1][1] & 0xDB81CA17L))
                    {
                        l_2181 = l_2176[0];
                        return l_656;
                    }
                    else
                    {
                        if (g_59)
                            break;
                    }
                    for (l_2137 = 2; (l_2137 >= 0); l_2137 -= 1)
                    {
                        int i;
                        l_2249 &= (((safe_mod_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((l_2183[l_2137] > (0L || (safe_rshift_func_uint8_t_u_u(l_2143[l_2137], (((g_849[0] | (((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(l_656, 4)), 13)) , ((safe_unary_minus_func_int8_t_s(((safe_rshift_func_int16_t_s_u(l_2183[l_2137], ((safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(g_59, 2)) , (safe_rshift_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((65535UL & ((((((((safe_mod_func_int8_t_s_s(l_2181, g_101)) , 0x3DL) == g_59) > 0xB5BB9598L) != l_472) ^ 0L) || l_2158) <= 4294967291UL)), l_121)) <= g_97[0]), 14))), l_2179)) != g_59) != l_396) & 0UL), g_59)) != l_656) || l_2158), 0x7D1913C8L)) <= l_2152))) ^ 0x99L))) | g_59)) | 0x6BL)) || l_419) & g_97[2]))))) ^ l_2143[l_2137]), l_1696[0])), 0xFB5B7956L)), 14)) < g_849[0]) , l_2199) <= l_419), l_1694)) && l_419) , 0x3F8D8182L);
                        l_351 ^= (l_2143[l_2137] && ((l_642 , (safe_sub_func_int8_t_s_s((((0x01B30B9BL ^ (1UL | (safe_sub_func_int32_t_s_s(l_2199, (((g_120[4] , g_849[0]) ^ g_777) != l_2151))))) < 1UL) | 0x7EE96D31L), l_121))) == k));
                        l_2255[1] = (l_419 != l_121);
                    }
                    for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1)
                    {
                        int32_t l_2256 = 0x52D2483BL;
                        int32_t l_2257 = 1L;
                        int32_t l_2258[2][3];
                        int16_t l_2262 = 1L;
                        int i, j;
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 3; j++)
                                l_2258[i][j] = 1L;
                        }
                        l_2101 = g_1368[l_2152];
                        l_2263--;
                        l_2260 &= (l_419 == l_656);
                        l_1693 = (safe_sub_func_int16_t_s_s(((g_1482[2][1][1] | ((5L || (g_1548[3][7][1] != (safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((0x76L & ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((l_2039 & (safe_lshift_func_uint16_t_u_u(((l_419 & (0x5EL <= ((safe_add_func_int8_t_s_s(1L, (g_1368[0] >= 0x02L))) <= l_2256))) != g_540), 15))), l_2216)), g_1540[1][0])) < 0x866FL)) >= 0x9DEFCED1L), 0x570AL)), g_97[5])), l_1694)), l_419)))) , l_2143[2])) ^ 0xAB2DL), 0UL));
                    }
                }
            }
        }
        else
        {
            int32_t l_2300[5][8] = {{0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}, {0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L, 0x279269D4L, 0xC988FBC0L, 1L, 0xC988FBC0L}};
            int32_t l_2321 = (-1L);
            uint32_t l_2322 = 0x99FED06DL;
            int i, j;
            for (l_2158 = 0; (l_2158 <= 2); l_2158 += 1)
            {
                g_120[1] = (safe_sub_func_int32_t_s_s(k, 0x8EEC641FL));
                for (l_2152 = 0; (l_2152 <= 2); l_2152 += 1)
                {
                    const int16_t l_2298 = 0x7AB4L;
                    if (l_656)
                    {
                        int8_t l_2299 = 0xA2L;
                        g_120[4] = (safe_sub_func_uint32_t_u_u(g_2184[2][0], g_540));
                        g_120[1] = ((safe_rshift_func_int8_t_s_u(l_656, ((safe_mod_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s((0x9CD8L && ((l_419 != (1UL & (g_59 , (safe_lshift_func_uint16_t_u_u((((l_656 == (0x32DBL >= (0x73E61AD3L < l_2298))) || g_717) >= l_2299), 4))))) >= 65535UL)), l_396)), l_656)) && 0x6D137FB0L))) && 7L);
                        l_2301--;
                        l_1648 = ((((safe_add_func_uint8_t_u_u(0x92L, l_2152)) & (((((((safe_lshift_func_int16_t_s_u((((l_2300[3][1] & ((safe_rshift_func_uint8_t_u_u(247UL, (safe_mod_func_uint8_t_u_u(1UL, (safe_mul_func_int16_t_s_s((+l_396), (g_1548[7][6][1] >= (safe_lshift_func_int8_t_s_u(g_101, 0))))))))) || ((safe_sub_func_int32_t_s_s((((safe_lshift_func_int16_t_s_u((-1L), 11)) == 0x5DL) | l_2299), 4294967295UL)) , l_2300[4][1]))) <= g_2184[2][0]) | l_2300[3][6]), 14)) , (-7L)) , l_656) != 0x6C7C71DBL) , g_18) , g_1548[4][6][2]) | g_2184[2][1])) == l_2141[1][6][5]) > g_59);
                    }
                    else
                    {
                        return l_419;
                    }
                }
                ++l_2322;
            }
        }
    }
    l_2326--;
    l_1651 = (safe_mod_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s((((safe_lshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s(l_1651, ((l_656 != 0xD257L) == (safe_sub_func_uint8_t_u_u((((safe_lshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s(((g_540 | ((safe_add_func_uint8_t_u_u(l_1651, ((((l_656 == (!(((!(~0xA2B5L)) || (g_540 != l_419)) , 0xBE0E0ABDL))) , l_2028) == 0x154C94FDL) <= 0xDCE7L))) & l_1695)) == g_1368[0]), l_419)), l_656)) > 0x8806C5F6L) > g_59), g_59))))), l_699)) | l_656) & l_1651), 0xD3L)) , g_97[2]), g_59));
    return l_1671;
}

                    return l_368;
                    }
                    return g_120[1];
                }
            }
            if (((((((safe_add_func_int16_t_s_s(((p_41 == (safe_sub_func_int8_t_s_s(g_18, (65529UL | 0L)))) , (safe_sub_func_int8_t_s_s(((g_100 ^ ((g_97[3] >= ((((safe_lshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u(l_691, 1)) , (safe_mod_func_uint32_t_u_u(l_507, (~(g_101 && 0xFDA677A5L))))), g_777)) ^ g_2467) & g_2254) & 1L)) == g_120[1])) && l_368), l_368))), g_777)) == p_43) && 255UL) < g_97[1]) >= g_100) ^ p_41))
            {
                int32_t l_691 = 0x098722ADL;
                int32_t l_693 = (-10L);
                for (g_100 = 5; (g_100 >= 0); g_100 -= 1)
                {
                    uint16_t l_692 = 0xCE33L;
                    uint32_t l_695 = 18446744073709551615UL;
                    int i;
                    g_101 &= ((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_s(l_213[g_100], 3)) , (((safe_add_func_int8_t_s_s((g_101 != (+(0xFEB6F005L != (safe_lshift_func_int16_t_s_u(((0x63L == ((safe_rshift_func_uint8_t_u_u(l_520[1][3], 0)) > (safe_mod_func_int32_t_s_s((l_419 > 3UL), (((((((0L >= (((safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_s(((safe_lshift_func_int16_t_s_u((safe_add_func_uint16_t_u_u(((0x37L == l_691) | l_691), p_43)), l_213[g_100])) != l_692), l_691)), p_43)) >= (-2L)) >= g_100)) , 0xF9DAL) || p_41) || 6L) || g_18) >= l_692) & 248UL))))) & g_2431), 9))))), g_120[1])) , 0UL) <= l_693)), g_2254)) , 0x2B6242CAL);
                    g_120[3] = (((l_695 , g_18) >= (l_696 && ((g_100 <= ((((safe_add_func_uint32_t_u_u((((l_368 ^ ((g_1217 > l_520[1][3]) , (g_120[1] | 0x8AL))) > g_777) == g_100), p_43)) && l_507) , 65535UL) <= l_598[1])) && 65535UL))) , g_2254);

if (i) printf("index = [%d][%d][%d]\n", l_253, l_656, l_655);

                    if (l_368)
                        break;
                }
            }
            else
            {
                l_213[4] = g_101;
                if (l_507)
                    continue;
            }
            g_100 &= ((((((((safe_mod_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_u(((-3L) < (((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((!(((((g_935 == (0x1D5D50F0L == l_711[2])) >= (((safe_unary_minus_func_uint32_t_u(0xFC24DB18L)) | 0xA3L) || ((((~((((((((0UL < l_696) || ((((safe_sub_func_int32_t_s_s(((((((+((l_567 == l_711[2]) && 65535UL)) < g_1217) || g_2431) != l_655) == 0L) ^ g_97[2]), 0x3C3D0A9BL)) != l_368) , l_368) > g_1217)) != l_507) >= 7L) && g_2254) && l_368) < 1L) , p_41)) > 0x60B3L) && 6UL) != l_567))) || p_41) && 0x58L) | 0xEFC1L)) && l_655), g_1217)), g_101)) ^ 9L) | 0x68L)), l_598[3])) >= g_120[4]), (-7L))) <= 0L) != l_213[2]) == l_613) && p_41) <= g_2254) < 0x057B1D42L) | l_213[1]);
        };


                    ;


                    for (g_100 = 5; (g_100 >= 0); g_100 -= 1)
                {
                    uint16_t l_692 = 0xCE33L;
                    uint32_t l_695 = 18446744073709551615UL;
                    int i;
                    g_694 &= ((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_s(l_213[g_100], 3)) , (((safe_add_func_int8_t_s_s((g_101 != (+(0xFEB6F005L != (safe_lshift_func_int16_t_s_u(((0x63L == ((safe_rshift_func_uint8_t_u_u(l_520[1][3], 0)) > (safe_mod_func_int32_t_s_s((l_396 > 3UL), (((((((0L >= (((safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_s(((safe_lshift_func_int16_t_s_u((safe_add_func_uint16_t_u_u(((0x37L == l_691) | l_390), p_43)), l_213[g_100])) != l_692), l_691)), p_43)) >= (-2L)) >= p_40)) , 0xF9DAL) || p_41) || 6L) || g_18) >= l_692) & 248UL))))) & g_59), 9))))), g_120[1])) , 0UL) <= l_693)), p_42)) , 0x2B6242CAL);


g_1482[2][1][1] |= (safe_rshift_func_uint16_t_u_s(g_2254, func_25(g_777)));

                    if (p_42)
                            break;

                    g_120[3] = (((l_695 , g_18) >= (l_696 && ((p_40 <= ((((safe_add_func_uint32_t_u_u((((p_39 ^ ((l_389 > l_520[1][3]) , (g_120[1] | 0x8AL))) > g_143) == l_699), p_43)) && l_507) , 65535UL) <= l_598[1])) && 65535UL))) , p_42);
                    if (p_39)
                        {
if (p_42)
                            {
{
                int8_t l_513[10][2] = {{0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}, {0L, 0x21L}};
                int32_t l_569[8][6][5] = {{{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}, {{0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}, {0x119536F7L, 0xBC264333L, (-1L), 6L, 9L}}};
                uint32_t l_642 = 18446744073709551615UL;
                int i, j, k;
                for (l_419 = 0; (l_419 >= 55); l_419 = safe_add_func_int32_t_s_s(l_419, 5))
                {
                    int8_t l_523 = 0xDBL;
                    l_520[1][3] = ((((l_699 || 0UL) != l_389) <= (safe_rshift_func_int16_t_s_u(0x4F5AL, (g_1171 ^ (0x7DL <= l_513[9][0]))))) , (g_89 ^ (safe_mod_func_uint16_t_u_u((((safe_rshift_func_int16_t_s_s((safe_mod_func_int32_t_s_s(l_696, g_97[2])), 12)) < l_699) | l_513[9][0]), p_41))));
                    for (g_1171 = (-26); (g_1171 <= 16); g_1171++)
                    {
                        int8_t l_524 = (-8L);
                        l_524 = l_523;
                        l_693 &= l_524;
                    }
                }
                if (((safe_mod_func_int16_t_s_s(g_89, (safe_rshift_func_int8_t_s_s(g_1171, 1)))) > (0xAD5285A3L <= l_513[9][0])))
                {
                    uint16_t l_533 = 0xB016L;
                    p_42 &= (safe_add_func_int32_t_s_s((1UL != g_120[1]), (safe_add_func_int8_t_s_s((g_120[1] || (p_41 > (((((((l_533 >= p_42) & l_389) || ((safe_unary_minus_func_uint8_t_u(p_42)) & (((safe_lshift_func_int8_t_s_s((+(safe_rshift_func_int16_t_s_u((g_2414 , 0xDD7CL), g_120[3]))), j)) ^ 8L) , p_42))) > l_389) != g_2414) > 0xEEL) , l_693))), l_389))));
                    for (l_696 = 10; (l_696 != 4); l_696--)
                    {
                        const uint16_t l_568[6][9][4] = {{{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}, {{0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}, {0x5921L, 0x6BC9L, 65527UL, 65526UL}}};
                        const uint8_t l_576 = 249UL;
                        int i, j, k;
                        l_569[7][2][2] = (((safe_rshift_func_uint8_t_u_u(g_143, 6)) , (safe_rshift_func_uint16_t_u_u((((l_213[2] <= (((safe_sub_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((((((((l_513[9][1] | g_97[2]) || g_1171) ^ 0x77L) , ((safe_rshift_func_uint16_t_u_s(l_389, (((safe_rshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((((((safe_lshift_func_uint16_t_u_u((((((safe_lshift_func_uint8_t_u_u(l_296, 5)) == ((((((safe_rshift_func_uint8_t_u_s(((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(9UL, 4)) < l_520[1][3]), g_1171)) && l_699), g_18)) < l_699) , l_699) < 0xA5D176F9L) || g_89) != p_41)) || p_42) >= i) != g_18), 5)) != 0xFB0274BAL) > l_692) && i) != p_42), l_513[5][0])), 4)) == l_419) != p_42))) > l_693)) ^ g_1171) | g_2414) | l_568[1][1][0]) && l_520[1][3]), l_533)), 0UL)) , l_513[8][1]) && p_41)) <= 0x1E8AL) || l_693), 13))) , p_41);
                        j = (safe_rshift_func_int16_t_s_s((safe_rshift_func_uint16_t_u_s((safe_add_func_int16_t_s_s(l_576, ((safe_sub_func_uint32_t_u_u(4294967295UL, ((safe_lshift_func_int8_t_s_u(l_389, (safe_add_func_uint32_t_u_u((((safe_add_func_int16_t_s_s((safe_add_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u(l_699, g_120[1])) , 0xD285L), (p_41 , (0UL != (safe_lshift_func_int16_t_s_u((((safe_sub_func_int16_t_s_s((!((((safe_add_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((-1L), 13)) | l_419), l_569[7][2][2])) <= l_513[9][0]) || l_598[1]) <= g_18)), l_213[2])) ^ l_699) , 0xDB70L), g_89)))))), p_41)) > g_120[1]) >= l_693), g_97[5])))) ^ 0x9F178DF0L))) && l_598[1]))), 7)), p_41));
                        l_693 = ((+0x203AL) && (safe_rshift_func_uint8_t_u_s((0xF62F64AEL < (((safe_sub_func_int32_t_s_s((((safe_lshift_func_uint8_t_u_s(0x12L, 1)) & ((safe_rshift_func_int16_t_s_u(((safe_sub_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_u(l_693, p_41)), (((!((g_97[1] | (l_692 || ((g_1171 < g_2414) == l_520[1][3]))) , l_389)) >= (-1L)) && p_41))) , 0xD86FL), 2)) & 255UL)) > p_42), 0x9FADD9B3L)) , 0L) | l_389)), l_533)));
                        if (p_41)
                            continue;
                    }
                    for (g_1171 = (-15); (g_1171 < 46); g_1171 = safe_add_func_uint32_t_u_u(g_1171, 1))
                    {
                        --g_1171;
                        l_520[1][3] = (l_693 != ((~(safe_lshift_func_int16_t_s_u(g_143, p_42))) <= (safe_add_func_int8_t_s_s(g_89, 1L))));
                        if (g_97[2])
                            break;
                        return p_42;
                    }
                }
                else
                {
                    g_120[1] = 1L;
                }
                l_693 = (((((safe_add_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_s((((0xA08E28CFL <= (g_143 == (((safe_rshift_func_int16_t_s_u(l_693, 8)) && (safe_rshift_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_mod_func_uint8_t_u_u(g_120[1], g_1171)), (0L > l_699))), (l_699 || (safe_sub_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u(g_143, l_642)) | l_569[7][2][1]), 0UL)))))) | g_2414))) | p_42) , l_389), 15)) != l_389), p_42)) && l_419) | l_520[0][2]) >= j) >= l_693);

if (g_2254)
                        continue;

                    if ((safe_lshift_func_int16_t_s_s(p_42, (((((p_42 && (((safe_sub_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((((0x23L && l_569[4][5][3]) != (safe_sub_func_uint32_t_u_u(l_296, g_97[1]))) , (safe_add_func_int8_t_s_s(l_693, l_696))), p_42)), g_1171)) < 4294967295UL) | p_41)) ^ 0x77L) , j) , 0x3B0A0897L) >= g_97[4]))))
                {
                    l_693 &= (safe_rshift_func_uint16_t_u_u(l_253, 8));
                }
                else
                {
                    for (l_699 = 0; (l_699 <= 5); l_699 += 1)
                    {
                        return j;
                    }
                    return g_120[1];
                }
            }

                    break;}

                    break;}
                }
            }
            else
            {
                l_213[4] = g_694;


if (l_368) printf("index = [%d][%d]\n", l_655, l_655);

                    for (g_2467 = 0; (g_2467 > 15); ++g_2467)
        {
            g_120[1] = 0x19D1A3FEL;
            if (g_540)
                {
if (p_40)
                            break;

                    continue;}
        };


                    if (l_507)
                    continue;
            }

{

p_39 &= (((l_351 < (safe_add_func_uint8_t_u_u(g_22, (((safe_unary_minus_func_int32_t_s(3L)) , 250UL) , (safe_sub_func_uint8_t_u_u((((l_351 == g_717) , ((g_1168 > ((safe_lshift_func_int8_t_s_u(((safe_mod_func_uint32_t_u_u(((~((l_396 ^ g_849[0]) >= g_2414)) || l_419), (-6L))) ^ g_849[0]), g_22)) >= l_655)) | 0xA9A8L)) & (-8L)), l_213[5])))))) , 6UL) && g_120[1]);

                    for (l_656 = 0; l_656 < 3; l_656++)
        {
            transparent_crc(g_2184[l_253][l_656], "g_2184[l_253][l_656]", l_567);
            if (l_567) printf("index = [%d][%d]\n", l_253, l_656);

        }
    }


{
        transparent_crc(g_1368[g_2469], "g_1368[g_2469]", l_394);
        if (l_394) printf("index = [%d]\n", g_2469);

    }

                    g_717 &= ((((((((safe_mod_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_u(((-3L) < (((safe_add_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((!(((((l_472 == (0x1D5D50F0L == l_711[2])) >= (((safe_unary_minus_func_uint32_t_u(0xFC24DB18L)) | 0xA3L) || ((((~((((((((0UL < l_696) || ((((safe_sub_func_int32_t_s_s(((((((+((l_567 == l_711[2]) && 65535UL)) < l_389) || g_59) != l_253) == 0L) ^ g_97[2]), 0x3C3D0A9BL)) != p_39) , p_39) > l_389)) != l_507) >= 7L) && p_42) && p_39) < 1L) , p_41)) > 0x60B3L) && 6UL) != l_567))) || p_41) && 0x58L) | 0xEFC1L)) && l_655), l_389)), g_101)) ^ 9L) | 0x68L)), l_598[3])) >= g_120[4]), (-7L))) <= 0L) != l_213[2]) == l_616) && p_41) <= p_42) < 0x057B1D42L) | l_213[1]);
        }
    }
    return l_253;
}







static int32_t func_46(uint8_t p_47, uint16_t p_48, int16_t p_49, uint8_t p_50, uint16_t p_51)
{
    uint32_t l_74 = 0xF6860338L;
    l_74 |= 0x10DDF4F3L;
    return p_51;
}







static int16_t func_54(int32_t p_55, const uint32_t p_56, int8_t p_57, uint8_t p_58)
{
    int16_t l_68 = 0xEEB3L;
    uint16_t l_73 = 0xAD67L;
    g_59 = g_22;
    p_55 = ((((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(g_18, (safe_mod_func_int32_t_s_s(((((safe_lshift_func_int8_t_s_s(((((l_68 == l_68) <= p_56) ^ ((l_68 , (g_18 >= (!(((safe_lshift_func_uint8_t_u_s((((p_57 > ((l_68 == (~((((l_73 < g_22) & 1L) , l_68) > 1L))) <= 0x8971L)) > p_56) , g_22), 1)) & 6UL) || g_18)))) <= 0x164DL)) == p_56), 7)) == l_68) < p_56) , (-1L)), l_68)))) > p_56), (-10L))) , g_59) && g_18) , p_56);
    return l_73;
}





int main (void)
{
    int i, j, k;
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
    transparent_crc(g_18, "g_18", print_hash_value);
    transparent_crc(g_22, "g_22", print_hash_value);
    transparent_crc(g_59, "g_59", print_hash_value);
    transparent_crc(g_89, "g_89", print_hash_value);
    for (i = 0; i < 7; i++)
    {
        transparent_crc(g_97[i], "g_97[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_100, "g_100", print_hash_value);
    transparent_crc(g_101, "g_101", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        transparent_crc(g_120[i], "g_120[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_143, "g_143", print_hash_value);
    transparent_crc(g_540, "g_540", print_hash_value);
    transparent_crc(g_694, "g_694", print_hash_value);
    transparent_crc(g_717, "g_717", print_hash_value);
    transparent_crc(g_777, "g_777", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_849[i], "g_849[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_935, "g_935", print_hash_value);
    transparent_crc(g_1168, "g_1168", print_hash_value);
    transparent_crc(g_1171, "g_1171", print_hash_value);
    transparent_crc(g_1217, "g_1217", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_1368[i], "g_1368[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                transparent_crc(g_1482[i][j][k], "g_1482[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 2; j++)
        {
            transparent_crc(g_1540[i][j], "g_1540[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 8; j++)
        {
            for (k = 0; k < 3; k++)
            {
                transparent_crc(g_1548[i][j][k], "g_1548[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    for (i = 0; i < 6; i++)
    {
        transparent_crc(g_2003[i], "g_2003[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_2100, "g_2100", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transparent_crc(g_2184[i][j], "g_2184[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_2254, "g_2254", print_hash_value);
    transparent_crc(g_2414, "g_2414", print_hash_value);
    transparent_crc(g_2431, "g_2431", print_hash_value);
    transparent_crc(g_2467, "g_2467", print_hash_value);
    transparent_crc(g_2468, "g_2468", print_hash_value);
    transparent_crc(g_2469, "g_2469", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 1; j++)
        {
            for (k = 0; k < 10; k++)
            {
                transparent_crc(g_2470[i][j][k], "g_2470[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

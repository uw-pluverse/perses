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



static uint32_t g_15 = 0x1DFD9475L;
static uint16_t g_28[7][9] = {{65527UL, 65531UL, 0xE6C8L, 0xAC31L, 65535UL, 0xAC31L, 0xE6C8L, 65531UL, 65527UL}, {65527UL, 65531UL, 0xE6C8L, 0xAC31L, 65535UL, 0xAC31L, 0xE6C8L, 65531UL, 65527UL}, {65527UL, 65531UL, 0xE6C8L, 0xAC31L, 65535UL, 0xAC31L, 0xE6C8L, 65531UL, 65527UL}, {65527UL, 65531UL, 0xE6C8L, 0xAC31L, 65535UL, 0xAC31L, 0xE6C8L, 65531UL, 65527UL}, {65527UL, 65531UL, 0xE6C8L, 0xAC31L, 65535UL, 0xAC31L, 0xE6C8L, 65531UL, 65527UL}, {65527UL, 65531UL, 0xE6C8L, 0xAC31L, 65535UL, 0xAC31L, 0xE6C8L, 65531UL, 65527UL}, {65527UL, 65531UL, 0xE6C8L, 0xAC31L, 65535UL, 0xAC31L, 0xE6C8L, 65531UL, 65527UL}};
static volatile int32_t g_76 = 0x79815C87L;
static uint8_t g_81[1] = {0xFAL};
static uint32_t g_90 = 0UL;
static uint32_t g_91 = 0x487E88E1L;
static int32_t g_93 = (-2L);
static int32_t g_105[1][9][10] = {{{9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L}, {9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L}, {9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L}, {9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L}, {9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L}, {9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L}, {9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L}, {9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L}, {9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L, 9L}}};
static uint64_t g_124 = 1UL;
static int16_t g_148 = (-10L);
static int8_t g_151 = 0x15L;
static uint64_t g_152[5][1][6] = {{{0xA2021D835F2621DCLL, 0x5673C17101716674LL, 0xB8FCCBCFC55BB8F8LL, 0x5673C17101716674LL, 0xA2021D835F2621DCLL, 0x5673C17101716674LL}}, {{0xA2021D835F2621DCLL, 0x5673C17101716674LL, 0xB8FCCBCFC55BB8F8LL, 0x5673C17101716674LL, 0xA2021D835F2621DCLL, 0x5673C17101716674LL}}, {{0xA2021D835F2621DCLL, 0x5673C17101716674LL, 0xB8FCCBCFC55BB8F8LL, 0x5673C17101716674LL, 0xA2021D835F2621DCLL, 0x5673C17101716674LL}}, {{0xA2021D835F2621DCLL, 0x5673C17101716674LL, 0xB8FCCBCFC55BB8F8LL, 0x5673C17101716674LL, 0xA2021D835F2621DCLL, 0x5673C17101716674LL}}, {{0xA2021D835F2621DCLL, 0x5673C17101716674LL, 0xB8FCCBCFC55BB8F8LL, 0x5673C17101716674LL, 0xA2021D835F2621DCLL, 0x5673C17101716674LL}}};
static uint64_t g_163 = 9UL;
static int32_t g_167 = 6L;
static uint8_t g_188[1] = {0x5AL};
static int32_t g_202 = 5L;
static uint8_t g_203 = 0UL;
static int32_t g_208 = 0L;
static uint32_t g_269 = 0x2B0E516BL;
static int8_t g_276 = 0x3AL;
static int16_t g_324 = 0xD1C0L;
static int64_t g_381 = 0x53076E19BB2B780CLL;
static int64_t g_423 = 0x498ADFB72610C518LL;
static int8_t g_465 = 0xC4L;
static int32_t g_482[7][3][4] = {{{0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}}, {{0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}}, {{0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}}, {{0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}}, {{0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}}, {{0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}}, {{0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}, {0x8FD500D0L, 1L, 0x926A1E5FL, 0x2A50666EL}}};
static uint32_t g_483[3] = {0xF5A22B49L, 0xF5A22B49L, 0xF5A22B49L};
static volatile uint64_t g_511 = 1UL;
static int8_t g_519 = 0xC0L;
static int8_t g_520 = 0xDCL;
static uint16_t g_521 = 0x9926L;
static uint64_t g_551 = 0x0C3E9FAD57ED5205LL;
static int16_t g_559 = 0x34D1L;
static uint64_t g_576 = 0xB7E0F2C445097D32LL;
static int32_t g_579 = 0x73505EB7L;
static int32_t g_694 = (-2L);
static int32_t g_695 = 0xE00B5322L;
static uint16_t g_747 = 0x033AL;
static volatile uint64_t g_758[10][6] = {{18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL}, {18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL}, {18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL}, {18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL}, {18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL}, {18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL}, {18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL}, {18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL}, {18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL}, {18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL, 18446744073709551611UL, 1UL}};
static int64_t g_875 = (-1L);
static uint8_t g_952[8][5] = {{255UL, 1UL, 255UL, 1UL, 255UL}, {255UL, 1UL, 255UL, 1UL, 255UL}, {255UL, 1UL, 255UL, 1UL, 255UL}, {255UL, 1UL, 255UL, 1UL, 255UL}, {255UL, 1UL, 255UL, 1UL, 255UL}, {255UL, 1UL, 255UL, 1UL, 255UL}, {255UL, 1UL, 255UL, 1UL, 255UL}, {255UL, 1UL, 255UL, 1UL, 255UL}};
static uint16_t g_1016 = 0x7CE0L;
static uint32_t g_1023[3][5][10] = {{{0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}, {0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}, {0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}, {0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}, {0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}}, {{0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}, {0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}, {0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}, {0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}, {0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}}, {{0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}, {0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}, {0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}, {0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}, {0UL, 0x3F96B48DL, 18446744073709551608UL, 0x4FC4911DL, 18446744073709551613UL, 0x12B9AE81L, 0x6C89C667L, 0xCEA9D2EAL, 18446744073709551615UL, 0xE6DB3CA3L}}};
static int32_t g_1121 = 6L;
static int16_t g_1388[3] = {0x411BL, 0x411BL, 0x411BL};
static volatile int16_t g_1405[10][9][2] = {{{0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}}, {{0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}}, {{0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}}, {{0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}}, {{0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}}, {{0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}}, {{0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}}, {{0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}}, {{0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}}, {{0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}, {0xEE96L, 0xAFADL}}};
static int16_t g_1507 = (-7L);
static int16_t g_1593 = 0x71AEL;
static int8_t g_1613 = 0xA3L;
static volatile uint64_t g_1703 = 0xCC154F334727056FLL;
static volatile int8_t g_1704 = 1L;
static uint64_t g_1729[1][4] = {{18446744073709551614UL, 18446744073709551614UL, 18446744073709551614UL, 18446744073709551614UL}};
static uint64_t g_1730 = 0x22CF64ED8F928E06LL;
static int32_t g_1775 = (-3L);
static volatile uint32_t g_1783[7][1] = {{4294967295UL}, {4294967295UL}, {4294967295UL}, {4294967295UL}, {4294967295UL}, {4294967295UL}, {4294967295UL}};
static int64_t g_1820 = (-1L);
static int8_t g_1854 = (-1L);
static volatile int64_t g_1884 = 0x11E85E49C1803EEALL;
static int8_t g_1970 = 0L;
static uint32_t g_2151 = 0UL;
static volatile int64_t g_2201 = 0xB8B5AF854C92A8E3LL;
static uint8_t g_2718 = 0x18L;
static uint32_t g_2720[3] = {0x86FC3314L, 0x86FC3314L, 0x86FC3314L};
static uint16_t g_2939 = 0x0468L;
static uint16_t g_3020 = 0x2F95L;
static uint32_t g_3022 = 3UL;
static uint8_t g_3106 = 0x2DL;
static uint32_t g_3551 = 0x752DD6CAL;



static int16_t func_1(void);
static int16_t func_7(int64_t p_8, int16_t p_9, uint8_t p_10, uint32_t p_11);
static uint8_t func_12(int8_t p_13, int32_t p_14);
static int32_t func_17(uint32_t p_18, int32_t p_19, int32_t p_20);
static uint64_t func_22(uint32_t p_23, uint32_t p_24, int32_t p_25, uint64_t p_26, int32_t p_27);
static int32_t func_32(int32_t p_33, uint8_t p_34, uint32_t p_35, int32_t p_36);
static uint8_t func_37(uint8_t p_38, uint32_t p_39, uint32_t p_40, int32_t p_41, int8_t p_42);
static uint8_t func_46(uint8_t p_47, uint8_t p_48, int64_t p_49, uint8_t p_50);
static int32_t func_53(uint16_t p_54);
static uint16_t func_55(int32_t p_56);
static int16_t func_1(void)
{
    uint8_t l_2 = 0x13L;
    int8_t l_16 = 0xFBL;
    int32_t l_3555 = 0L;
    l_2 = 2L;
    l_3555 = ((safe_add_func_uint32_t_u_u((safe_sub_func_int16_t_s_s(func_7((((func_12(g_15, l_16) < 255UL) || (((safe_mod_func_int64_t_s_s((safe_lshift_func_uint8_t_u_s((g_90 > g_1703), 6)), l_16)) == l_2) > (safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s((safe_sub_func_int16_t_s_s((safe_mod_func_int8_t_s_s(g_423, g_167)), 0x620AL)), 15)), 0UL)))) < l_16), l_16, l_16, g_3551), g_3551)), 0x6A2B20D8L)) | 1UL);
    l_3555 = 0xE1182985L;
    for (g_167 = 20; (g_167 < (-29)); g_167 = safe_sub_func_int8_t_s_s(g_167, 5))
    {
        uint32_t l_3560 = 0xF29B50C7L;
        int32_t l_3568 = 8L;
        int32_t l_3578[1];
        int i;
        for (i = 0; i < 1; i++)
            l_3578[i] = (-1L);
        l_3578[0] = (g_579 = (0xE9L & (safe_rshift_func_int8_t_s_s((l_3560 ^ ((((safe_lshift_func_uint8_t_u_u((safe_add_func_int16_t_s_s(g_1613, (l_2 & 0x7963DC6EL))), ((~((g_875 = (safe_add_func_uint64_t_u_u((l_3568 = l_3560), 0UL))) & ((((safe_sub_func_uint16_t_u_u((+g_1703), (g_1593 = (safe_sub_func_int8_t_s_s((safe_unary_minus_func_uint64_t_u((((safe_mod_func_uint64_t_u_u((g_152[3][0][0] = (safe_unary_minus_func_int8_t_s(g_695))), l_3555)) <= g_93) , 18446744073709551607UL))), g_1023[1][4][5]))))) != l_3560) <= g_3020) ^ 0xBD755CF8L))) == 0xB13AL))) | l_3560) > l_3555) <= g_694)), l_16))));
    }
    return l_3555;
}







static int16_t func_7(int64_t p_8, int16_t p_9, uint8_t p_10, uint32_t p_11)
{
    int32_t l_3554 = 4L;
    l_3554 = (safe_lshift_func_uint16_t_u_u(p_10, 4));
    return p_11;
}







static uint8_t func_12(int8_t p_13, int32_t p_14)
{
    int32_t l_3205 = 0L;
    uint32_t l_3206 = 0xCE610382L;
    int32_t l_3247 = 6L;
    uint16_t l_3252[10] = {0UL, 65535UL, 0x0B33L, 0x0B33L, 65535UL, 0UL, 65535UL, 0x0B33L, 0x0B33L, 65535UL};
    int64_t l_3253 = 0L;
    int32_t l_3287 = 0xC03CAE91L;
    int32_t l_3289[5][7][7] = {{{0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}}, {{0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}}, {{0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}}, {{0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}}, {{0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}, {0xC7F885C5L, 0L, 0x23A4E5AFL, 0x849A6F42L, 0x23A4E5AFL, 0L, 0xC7F885C5L}}};
    uint32_t l_3294 = 0xD4C11313L;
    uint16_t l_3365 = 65529UL;
    int8_t l_3406 = 0x55L;
    int32_t l_3538 = 0x06351BBEL;
    int i, j, k;
    l_3247 = func_17(g_15, ((+((func_22(p_14, p_14, g_15, (g_28[6][1] = 18446744073709551613UL), g_15) >= 0L) == (l_3205 = ((p_14 <= 18446744073709551615UL) , p_13)))) <= l_3206), l_3206);
    for (p_14 = 0; (p_14 != (-13)); p_14--)
    {
        int16_t l_3286 = 0x7C2DL;
        uint8_t l_3288 = 0UL;
        int32_t l_3290 = 0xA8BB0D9AL;
        int32_t l_3307 = (-1L);
        int16_t l_3473 = 7L;
        uint16_t l_3489 = 0x473BL;
        int64_t l_3523 = 0L;
        l_3247 = (0x770E85511FB9DF1ELL > (safe_lshift_func_int8_t_s_s((p_13 = l_3252[9]), 6)));
        g_579 = (l_3253 , (g_482[5][1][0] = p_14));
        if ((l_3290 = ((safe_mod_func_int16_t_s_s(((safe_mod_func_int32_t_s_s(((((safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((p_14 || (safe_add_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((((safe_rshift_func_int8_t_s_u(((safe_sub_func_uint16_t_u_u((g_324 || (p_13 > ((safe_add_func_uint32_t_u_u(((l_3252[0] > ((l_3253 != (safe_mod_func_int32_t_s_s((safe_mod_func_int16_t_s_s(l_3205, (safe_sub_func_int16_t_s_s((((g_1775 = g_520) <= ((safe_sub_func_int16_t_s_s((l_3287 = ((l_3286 = (((l_3247 = p_14) && (safe_add_func_uint32_t_u_u(((safe_add_func_uint64_t_u_u(g_3106, 0xCB0CD7BF47F1B7FDLL)) || p_14), 0x7B9AA23FL))) && l_3252[8])) ^ p_14)), l_3206)) , 0L)) <= l_3252[9]), 0UL)))), g_105[0][3][1]))) | p_14)) == g_1405[9][3][0]), 0xA21B3913L)) > p_14))), 65535UL)) < 0L), p_13)) < l_3288) == l_3289[0][5][5]), g_124)), 4294967295UL))), g_15)), 0L)) >= g_163) ^ l_3288) , l_3288), p_14)) || g_1775), p_13)) == 0x1FE179EFL)))
        {
            int32_t l_3306 = 0x6B748418L;
            int64_t l_3320 = 0x8C137D7A3125EEDELL;
            uint32_t l_3391[4][7][8] = {{{0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}}, {{0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}}, {{0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}}, {{0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}, {0x488D7BB2L, 4UL, 4294967295UL, 4294967294UL, 0xBD2301C0L, 0x540E1DD6L, 0x121FD2AFL, 0xE59AD53BL}}};
            int32_t l_3392 = 0L;
            int32_t l_3401 = 0L;
            int8_t l_3474[1][3];
            uint32_t l_3522 = 4294967286UL;
            int i, j, k;
            for (i = 0; i < 1; i++)
            {
                for (j = 0; j < 3; j++)
                    l_3474[i][j] = (-1L);
            }
            l_3307 = (((~(g_2151 && ((l_3306 = ((g_1593 = l_3294) >= (p_13 & (((!((safe_add_func_uint8_t_u_u(p_14, (((safe_lshift_func_uint16_t_u_u((l_3290 = p_13), 0)) , (((safe_add_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((((((p_13 , (-5L)) >= (l_3290 = 0xA5L)) < ((safe_sub_func_int64_t_s_s(((65535UL != 0x3ABBL) == 0x3EL), 0x1E688197EBCE1CE6LL)) ^ 0UL)) < 3L) & p_13), 10)), l_3306)) >= 0xE374C47196F94115LL) || 0xF9CFA298L)) , p_14))) && g_90)) || g_2718) == 0xCE7FC3D92F16705ELL)))) == 0x18982411A5E7960DLL))) > (-4L)) & 0x08F3CAAF556D8798LL);
            for (g_1854 = 0; (g_1854 <= 1); g_1854 += 1)
            {
                int32_t l_3336 = 0xD973F3C8L;
                int32_t l_3366 = 0x79375C1BL;
                int32_t l_3367 = 4L;
                uint32_t l_3368[6][10] = {{0x10DC4C36L, 0xAF642237L, 0xF6BC337CL, 0xAF642237L, 0x10DC4C36L, 0x0009B13DL, 0x10DC4C36L, 0xAF642237L, 0xF6BC337CL, 0xAF642237L}, {0x10DC4C36L, 0xAF642237L, 0xF6BC337CL, 0xAF642237L, 0x10DC4C36L, 0x0009B13DL, 0x10DC4C36L, 0xAF642237L, 0xF6BC337CL, 0xAF642237L}, {0x10DC4C36L, 0xAF642237L, 0xF6BC337CL, 0xAF642237L, 0x10DC4C36L, 0x0009B13DL, 0x10DC4C36L, 0xAF642237L, 0xF6BC337CL, 0xAF642237L}, {0x10DC4C36L, 0xAF642237L, 0xF6BC337CL, 0xAF642237L, 0x10DC4C36L, 0x0009B13DL, 0x10DC4C36L, 0xAF642237L, 0xF6BC337CL, 0xAF642237L}, {0x10DC4C36L, 0xAF642237L, 0xF6BC337CL, 0xAF642237L, 0x10DC4C36L, 0x0009B13DL, 0x10DC4C36L, 0xAF642237L, 0xF6BC337CL, 0xAF642237L}, {0x10DC4C36L, 0xAF642237L, 0xF6BC337CL, 0xAF642237L, 0x10DC4C36L, 0x0009B13DL, 0x10DC4C36L, 0xAF642237L, 0xF6BC337CL, 0xAF642237L}};
                uint16_t l_3373 = 2UL;
                uint16_t l_3459 = 6UL;
                uint64_t l_3491[8][9] = {{0UL, 0xB51916D98F99F11CLL, 18446744073709551615UL, 18446744073709551611UL, 0xB51916D98F99F11CLL, 0x1FC6249BE8207DACLL, 0xB51916D98F99F11CLL, 18446744073709551611UL, 18446744073709551615UL}, {0UL, 0xB51916D98F99F11CLL, 18446744073709551615UL, 18446744073709551611UL, 0xB51916D98F99F11CLL, 0x1FC6249BE8207DACLL, 0xB51916D98F99F11CLL, 18446744073709551611UL, 18446744073709551615UL}, {0UL, 0xB51916D98F99F11CLL, 18446744073709551615UL, 18446744073709551611UL, 0xB51916D98F99F11CLL, 0x1FC6249BE8207DACLL, 0xB51916D98F99F11CLL, 18446744073709551611UL, 18446744073709551615UL}, {0UL, 0xB51916D98F99F11CLL, 18446744073709551615UL, 18446744073709551611UL, 0xB51916D98F99F11CLL, 0x1FC6249BE8207DACLL, 0xB51916D98F99F11CLL, 18446744073709551611UL, 18446744073709551615UL}, {0UL, 0xB51916D98F99F11CLL, 18446744073709551615UL, 18446744073709551611UL, 0xB51916D98F99F11CLL, 0x1FC6249BE8207DACLL, 0xB51916D98F99F11CLL, 18446744073709551611UL, 18446744073709551615UL}, {0UL, 0xB51916D98F99F11CLL, 18446744073709551615UL, 18446744073709551611UL, 0xB51916D98F99F11CLL, 0x1FC6249BE8207DACLL, 0xB51916D98F99F11CLL, 18446744073709551611UL, 18446744073709551615UL}, {0UL, 0xB51916D98F99F11CLL, 18446744073709551615UL, 18446744073709551611UL, 0xB51916D98F99F11CLL, 0x1FC6249BE8207DACLL, 0xB51916D98F99F11CLL, 18446744073709551611UL, 18446744073709551615UL}, {0UL, 0xB51916D98F99F11CLL, 18446744073709551615UL, 18446744073709551611UL, 0xB51916D98F99F11CLL, 0x1FC6249BE8207DACLL, 0xB51916D98F99F11CLL, 18446744073709551611UL, 18446744073709551615UL}};
                uint32_t l_3492 = 4294967289UL;
                int i, j;
                if ((l_3290 = (l_3320 = (((g_152[0][0][4] = (g_1775 & (safe_add_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s(l_3306, 5)), (-1L))))) ^ 0x84C40B52E1FA4B00LL) != (safe_mod_func_int16_t_s_s(((((l_3306 >= g_124) , (safe_sub_func_int8_t_s_s(((safe_sub_func_int64_t_s_s(((l_3287 = p_13) >= (safe_rshift_func_uint16_t_u_u((0xA8L && (l_3307 = p_14)), 7))), l_3289[0][5][5])) , p_13), g_1704))) , p_13) ^ l_3306), 0x6D11L))))))
                {
                    uint32_t l_3325 = 0xD2AE5B18L;
                    l_3325 = (0x17FBL < (safe_sub_func_int64_t_s_s(p_14, (safe_lshift_func_uint8_t_u_s(g_28[2][5], g_875)))));
                    for (g_520 = 0; (g_520 <= 0); g_520 += 1)
                    {
                        int32_t l_3343 = 0x2CA5397CL;
                        int i, j, k;
                        l_3343 = (((!(safe_add_func_uint32_t_u_u(g_1023[g_1854][(g_1854 + 3)][(g_1854 + 7)], (safe_add_func_int8_t_s_s(((safe_rshift_func_uint8_t_u_s((g_188[g_520] & (safe_unary_minus_func_int64_t_s(((((safe_rshift_func_int16_t_s_s(((g_28[(g_1854 + 4)][(g_1854 + 5)] = ((((g_2151 = g_28[(g_1854 + 1)][(g_520 + 5)]) >= (((l_3336 >= (((!(safe_rshift_func_int8_t_s_s(l_3336, 6))) , ((((g_28[6][1] == (safe_rshift_func_int16_t_s_u((g_1507 = g_1388[2]), 3))) , (+(p_13 , (l_3289[1][6][4] , g_1783[5][0])))) != p_13) < 1UL)) < g_188[g_520])) , 0x33B9L) <= g_81[0])) < 0x0EEBL) >= p_14)) & l_3336), l_3306)) , 0xE105EADDL) != l_3289[0][5][3]) != l_3325)))), g_559)) ^ l_3325), 1UL))))) != 0xC2L) == 0UL);
                    }
                    l_3306 = (l_3287 = (!((safe_sub_func_int8_t_s_s((p_13 = (p_14 && 5UL)), (safe_sub_func_int64_t_s_s((((((safe_lshift_func_int16_t_s_u((l_3366 = (((safe_rshift_func_int16_t_s_u((p_14 >= ((g_276 = g_124) , (l_3336 = (safe_sub_func_uint32_t_u_u(((g_152[3][0][0] ^ (safe_lshift_func_int8_t_s_u(((g_1730 != ((((safe_sub_func_int64_t_s_s((((safe_lshift_func_uint8_t_u_s((p_14 != p_14), (safe_lshift_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u((p_14 , p_14), g_483[1])), 1)))) > g_276) || 0x0FC3BDAF81BB4A44LL), l_3365)) ^ g_1507) < 6UL) & (-5L))) & g_163), 1))) && g_1729[0][3]), l_3290))))), l_3325)) > 0xF5L) != 0UL)), 10)) & l_3367) , l_3288) & p_14) != l_3325), 0xAAC0AFE8DA44009DLL)))) || l_3366)));
                    l_3336 = l_3368[2][2];
                }
                else
                {
                    int32_t l_3377 = 6L;
                    if (l_3294)
                        break;
                    l_3307 = (((g_1507 > ((safe_mod_func_uint32_t_u_u(((((((safe_mod_func_int64_t_s_s(l_3373, (((safe_unary_minus_func_uint64_t_u(p_13)) == ((g_576 >= ((p_13 >= (((0x977A8B54L || ((l_3368[2][2] & p_14) != (!(((~0UL) , p_13) >= l_3307)))) || p_14) <= 0x2D1DL)) , p_14)) , 4294967294UL)) ^ p_13))) ^ 0L) <= g_1730) || 0x223DL) == 18446744073709551615UL) == p_14), p_14)) < p_13)) && l_3368[2][2]) > p_13);
                    g_105[0][4][2] = l_3377;
                    l_3392 = (safe_rshift_func_int16_t_s_u((g_1388[2] = 0L), (g_28[5][6] < ((safe_lshift_func_int16_t_s_u(((l_3306 = (((safe_lshift_func_int16_t_s_s(((((l_3307 = g_423) > ((((p_14 && (((safe_unary_minus_func_int64_t_s(0x677104AA6C096DE2LL)) && (l_3247 = (((0x13L > (safe_lshift_func_uint8_t_u_u((safe_mul_func_int64_t_s_s(0x670B584F6CC9EB55LL, (p_13 <= ((p_14 ^ g_202) >= 0x41FBED7EL)))), l_3391[1][5][3]))) == g_2720[1]) < p_13))) == p_13)) <= 18446744073709551614UL) != 0x61F3D445557F4475LL) , (-4L))) , 3L) <= 0x0AA1D685L), 0)) , p_14) & l_3391[1][5][3])) || g_2718), 2)) == p_13))));
                }
                if ((p_14 & ((safe_add_func_int8_t_s_s(((safe_add_func_uint32_t_u_u(l_3307, ((g_81[0] = ((((-7L) | (safe_lshift_func_int8_t_s_u(p_13, (4L && (g_559 != (p_13 <= ((l_3290 = (g_1730 = p_13)) & ((l_3306 = ((safe_rshift_func_int16_t_s_u(l_3401, g_81[0])) ^ l_3288)) , g_1884)))))))) <= l_3253) && 0x6FFBL)) | 0UL))) > p_13), l_3367)) <= (-2L))))
                {
                    uint32_t l_3417 = 0xACD6D7B6L;
                    int32_t l_3418 = (-1L);
                    int32_t l_3419 = 0L;
                    for (g_93 = 0; (g_93 <= 2); g_93 += 1)
                    {
                        int i, j, k;
                        return g_1023[(g_1854 + 1)][(g_93 + 2)][(g_1854 + 8)];
                    }
                    l_3336 = (p_14 || (safe_sub_func_int64_t_s_s(((safe_sub_func_uint64_t_u_u(((((l_3406 < ((0x3427CB21L & (safe_lshift_func_uint8_t_u_s(g_76, 3))) >= (g_124 = ((((safe_sub_func_uint32_t_u_u((g_2151 = (safe_lshift_func_uint8_t_u_u(l_3366, 5))), (l_3418 = (safe_add_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s(l_3368[0][1], 2)) != l_3417), ((g_81[0] && l_3417) == g_276)))))) & p_13) != l_3289[1][2][5]) || g_952[4][2])))) , p_14) == g_3106) < 0xBC053A1CL), l_3417)) > l_3419), 0x5DD34A5A23DADAB4LL)));
                    return g_694;
                }
                else
                {
                    for (g_124 = 0; (g_124 <= 2); g_124 += 1)
                    {
                        g_1775 = g_482[0][0][3];
                    }
                }
                for (l_3206 = 0; (l_3206 <= 0); l_3206 += 1)
                {
                    int8_t l_3422 = (-2L);
                    uint8_t l_3436 = 0UL;
                    for (g_521 = 0; (g_521 <= 0); g_521 += 1)
                    {
                        int i;
                        if (g_188[l_3206])
                            {

{
                        int i;
                        g_76 = g_81[l_3373];
                    }


break;}

                        if (g_1388[0])
                            continue;
                        if (p_14)
                            continue;
                        l_3422 = (safe_rshift_func_uint8_t_u_s(0x4CL, 0));
                    }
                    for (g_3020 = 0; (g_3020 <= 2); g_3020 += 1)
                    {
                        g_579 = (((safe_sub_func_int16_t_s_s((+(g_3022 || (+g_465))), g_1783[5][0])) ^ 0L) | (g_1507 && ((safe_add_func_int16_t_s_s(l_3367, (l_3307 = (safe_add_func_uint32_t_u_u((safe_unary_minus_func_int64_t_s(l_3392)), (g_2151 = 0xD9DF8FDDL)))))) == (((safe_mod_func_int64_t_s_s((safe_mod_func_uint16_t_u_u((g_1613 | p_14), l_3206)), (-1L))) > l_3436) ^ 0x94C1C43EL))));
                    }
                }
                for (g_381 = 1; (g_381 >= 0); g_381 -= 1)
                {
                    int16_t l_3440 = 0L;
                    uint16_t l_3460 = 0x4806L;
                    g_1775 = ((safe_lshift_func_uint8_t_u_u(((((l_3287 < p_13) , (safe_unary_minus_func_uint8_t_u(p_13))) || (l_3440 = p_14)) <= (((~(!g_1405[9][3][0])) , (g_1016 || (((safe_rshift_func_int16_t_s_s(l_3336, 15)) | ((l_3253 > (((safe_rshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((safe_add_func_uint64_t_u_u((safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s((safe_add_func_uint64_t_u_u(((l_3391[1][5][3] < g_482[0][1][3]) < l_3459), 0x0EEFACC3AEB0C67ELL)), 12)), 0xBE80CC94L)), l_3290)), l_3460)), 6)) | p_14) > g_151)) && l_3286)) <= l_3306))) >= l_3288)), p_14)) , p_13);
                    if (((0x03L & (l_3247 = (p_13 & (g_2718 , (l_3206 == (((((((((safe_lshift_func_uint16_t_u_u((l_3460 & 0L), (((((g_15 = p_14) & (18446744073709551615UL >= ((((safe_lshift_func_uint8_t_u_s((((safe_rshift_func_int16_t_s_u((safe_lshift_func_uint16_t_u_s((l_3307 = ((safe_mod_func_uint64_t_u_u(((l_3290 = p_13) || 0xBB7E86EB1EB83B71LL), l_3307)) & p_13)), 3)), p_13)) , 9UL) ^ p_14), p_13)) == l_3286) , g_1507) && p_14))) , l_3473) && g_1854) != l_3474[0][0]))) | g_188[0]) , g_276) ^ l_3252[9]) && l_3440) >= 0x8F3CB98A3DC7D2BCLL) < 0x5B8CF264539FA5D8LL) && p_13) != 0xCDL)))))) | p_14))
                    {
                        int32_t l_3490 = (-2L);
                        int i, j, k;
                        g_579 = (((safe_mod_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_s((((((g_2151 = (safe_mod_func_int8_t_s_s(0xABL, (safe_lshift_func_uint16_t_u_u(p_13, ((l_3473 & (safe_sub_func_uint64_t_u_u(((g_1023[g_381][g_1854][(g_381 + 3)] = (safe_mod_func_int32_t_s_s(1L, p_13))) , ((((safe_add_func_uint64_t_u_u(((p_14 != g_269) > 0x761763E6L), (l_3489 = p_13))) != 0x3842L) < l_3392) || 1UL)), l_3490))) , l_3368[2][2])))))) || 0UL) >= l_3401) <= l_3491[3][8]) >= l_3290), 8)) != g_519), p_14)) , l_3288) && 1UL);
                        l_3492 = ((-2L) <= g_1970);
                        if (l_3367)
                            continue;
                    }
                    else
                    {
                        g_482[5][1][0] = (safe_lshift_func_uint8_t_u_u(g_152[1][0][5], 2));
                    }
                    if (p_14)
                        continue;
                }
            }
            l_3307 = (safe_lshift_func_uint16_t_u_s(0x328FL, 6));
            l_3247 = (safe_mod_func_uint32_t_u_u(((g_875 = (safe_add_func_int32_t_s_s((0xDB01C904F463EAD8LL | (0xB205L == ((safe_rshift_func_uint8_t_u_u(0x11L, 2)) && ((+((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((l_3287 = ((((l_3290 = (safe_sub_func_int32_t_s_s(((((p_13 & 0x1A16B325L) , ((safe_rshift_func_int16_t_s_u((safe_sub_func_uint64_t_u_u((g_758[8][4] , (safe_lshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u((0xBFEDFF84FCF67CCELL | (g_482[5][1][0] , (((((safe_sub_func_uint32_t_u_u(p_13, 0x06D091B2L)) , l_3401) != 3L) , p_13) >= p_13))), l_3522)), l_3522))), 0xC84F6C87B3197D56LL)), 4)) | 8UL)) , g_519) & p_14), l_3522))) || g_482[5][1][0]) && g_381) >= g_381)), p_14)), 2)) , 0x19CDCB27L)) != g_81[0])))), (-4L)))) ^ l_3523), l_3294));
        }
        else
        {
            int32_t l_3524 = 0x21461512L;
            g_482[5][1][0] = 0x82369650L;
            g_482[5][0][3] = (l_3524 = 0xE65A234EL);
        }
        if (p_14)
            continue;
    }
    l_3287 = ((safe_mod_func_uint16_t_u_u((g_2939 = ((safe_lshift_func_int16_t_s_s((g_1854 && (l_3287 & (((l_3538 = (safe_mod_func_uint8_t_u_u((((((l_3247 = (((safe_sub_func_int64_t_s_s(((((g_3020 = (+4294967288UL)) ^ (((safe_sub_func_int32_t_s_s((-1L), (l_3252[9] == g_511))) < (g_203 = ((g_93 || (4UL != p_14)) < g_152[1][0][5]))) , p_13)) == g_276) & 0xB309L), g_1820)) & 0x41E2L) | p_14)) > g_1729[0][3]) || 0xEAE920BA4370B50ELL) , 0x7B620FE5L) | l_3289[2][0][4]), 0x10L))) | 0x1DFB285C861F465BLL) , g_81[0]))), 3)) ^ l_3289[0][5][6])), (-1L))) ^ l_3252[5]);
                      if (( g_202 < 5) )
{

{
    uint8_t l_2073[4] = {4UL, 0xDFL, 4UL, 0xDFL};
    int8_t l_2074 = 1L;
    uint32_t l_2092 = 1UL;
    uint32_t l_2093 = 0UL;
    int32_t l_2094[3];
    int32_t l_2095 = (-1L);
    int i;
    for (i = 0; i < 3; i++)
        l_2094[i] = (-8L);
    l_2074 = ((safe_lshift_func_uint8_t_u_u((l_2073[1] = (g_551 ^ g_167)), 6)) , (g_151 <= g_81[0]));
    l_2095 = ((g_1820 = (((!((g_2720[1] | (((safe_rshift_func_uint8_t_u_u(l_2073[1], 3)) <= (g_520 = (((((+(((l_2094[2] = (~((g_3022 <= (g_151 = (((safe_lshift_func_int8_t_s_u((((l_3406 = l_2073[0]) & ((7L | (0xEBB5B307BA6D4CF6LL & (safe_mod_func_uint32_t_u_u(((((safe_rshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u((safe_rshift_func_int8_t_s_u((((safe_add_func_int16_t_s_s((g_1507 = ((((((g_203 = l_2092) , (l_2074 || (4UL == g_3020))) || (-1L)) ^ p_13) <= l_2073[0]) <= g_76)), j)) , l_2092) <= 1L), 1)), l_2074)), 3)) || 0L) == g_105[0][3][1]) , l_2093), 0x68BF614DL)))) , l_2093)) | 1L), l_2074)) ^ l_2074) != g_81[0]))) < l_2092))) == 4UL) , g_124)) && 0xDE7F2A58D417EC0ELL) == 0x99L) && l_2092) , (-1L)))) < g_551)) != 7L)) && l_2074) & p_13)) && g_3020);
    for (g_203 = 0; (g_203 != 43); ++g_203)
    {
        int16_t l_2098 = 0xD407L;
        int32_t l_2112 = 3L;
        if (g_269)
        {
            uint32_t l_2101[3];
            int i;
            for (i = 0; i < 3; i++)
                l_2101[i] = 4294967288UL;
            l_2101[0] = (l_2098 && (safe_rshift_func_uint16_t_u_s(0UL, 12)));
        }
        else
        {
            uint32_t l_2106 = 4294967291UL;
            int32_t l_2113[5][9] = {{0L, 0x74499E55L, 0x51C0958EL, 0x74499E55L, 0L, 0x2DB6A292L, 0L, 0x74499E55L, 0x51C0958EL}, {0L, 0x74499E55L, 0x51C0958EL, 0x74499E55L, 0L, 0x2DB6A292L, 0L, 0x74499E55L, 0x51C0958EL}, {0L, 0x74499E55L, 0x51C0958EL, 0x74499E55L, 0L, 0x2DB6A292L, 0L, 0x74499E55L, 0x51C0958EL}, {0L, 0x74499E55L, 0x51C0958EL, 0x74499E55L, 0L, 0x2DB6A292L, 0L, 0x74499E55L, 0x51C0958EL}, {0L, 0x74499E55L, 0x51C0958EL, 0x74499E55L, 0L, 0x2DB6A292L, 0L, 0x74499E55L, 0x51C0958EL}};
            int32_t l_2114 = 0x92A4DB93L;
            int i, j;
            g_76 = g_381;
            for (g_1703 = 0; g_1703 < 8; g_1703 += 1)
            {
                for (l_2074 = 0; l_2074 < 5; l_2074 += 1)
                {
                    g_952[g_1703][l_2074] = 1UL;
                }
            }
            l_2114 = (!((((18446744073709551606UL != (l_2094[0] = (safe_sub_func_int32_t_s_s((l_2113[3][7] = ((0xC534L != (((g_203 = (safe_unary_minus_func_int32_t_s(((g_151 = l_2106) , ((safe_mod_func_int16_t_s_s((g_269 > ((safe_unary_minus_func_uint8_t_u((g_203 & (safe_sub_func_uint32_t_u_u((g_3022 = (((l_2098 ^ g_81[0]) == ((g_482[5][1][0] , (g_1775 && 0x59CBA05F959F00DDLL)) && g_3022)) < g_1820)), p_13))))) > l_2112)), l_2095)) < g_1775))))) != g_1775) != l_2106)) != 249UL)), g_76)))) , g_163) , g_269) ^ g_952[4][2]));
            l_2113[3][7] = (-1L);
        }
        return g_1775;
    }
    return g_2720[0];
}

}

return p_13;
}







static int32_t func_17(uint32_t p_18, int32_t p_19, int32_t p_20)
{
    int64_t l_3211 = (-1L);
    int32_t l_3224[10];
    int8_t l_3225 = 0x8AL;
    int32_t l_3226 = 0x6DC7ABB0L;
    int32_t l_3227[9] = {(-5L), (-5L), 0L, (-5L), (-5L), 0L, (-5L), (-5L), 0L};
    int32_t l_3228[9] = {0x946F9E5EL, (-4L), 0x946F9E5EL, (-4L), 0x946F9E5EL, (-4L), 0x946F9E5EL, (-4L), 0x946F9E5EL};
    int16_t l_3231 = 4L;
    int32_t l_3238 = (-8L);
    uint32_t l_3239 = 0xE6E3A790L;
    uint8_t l_3246 = 1UL;
    int i;
    for (i = 0; i < 10; i++)
        l_3224[i] = (-9L);
    l_3228[3] = (safe_rshift_func_int16_t_s_u((safe_add_func_int32_t_s_s(((((((((g_203 = ((g_1970 = ((l_3211 != ((safe_mod_func_uint64_t_u_u((l_3227[8] = ((l_3226 = (g_952[6][3] | ((65529UL == (safe_lshift_func_int8_t_s_s(g_324, 3))) > (safe_rshift_func_uint16_t_u_s((((((g_747 = p_18) | ((safe_rshift_func_uint16_t_u_s((g_511 , (p_20 & p_19)), 3)) & ((safe_rshift_func_int16_t_s_u(((safe_sub_func_uint32_t_u_u((l_3224[6] = 0xC79D8663L), l_3225)) && l_3224[6]), p_19)) >= g_2718))) , p_18) < p_19) & 4294967295UL), 3))))) || l_3224[6])), 18446744073709551615UL)) , l_3227[7])) , l_3224[0])) , 1UL)) ^ p_20) ^ l_3211) != l_3225) || l_3225) , g_1016) < p_18) > 0x2171L), 4294967295UL)), 2));
    g_482[5][1][0] = 0xF1C31E2BL;
    l_3227[4] = (((l_3227[8] | (safe_lshift_func_int8_t_s_s((((g_579 = l_3231) | (l_3238 = (safe_mod_func_int16_t_s_s(0xE5B9L, (l_3224[2] = ((safe_add_func_uint8_t_u_u(0x8DL, 1UL)) & (l_3226 = (l_3228[3] = ((safe_sub_func_int16_t_s_s(0xFE7AL, (g_3020 = 0x49D4L))) > (((0x0FL <= 1L) | 0xFF1753A31093D144LL) > 2L)))))))))) ^ l_3231), 2))) | l_3239) != 255UL);
    for (g_93 = 0; (g_93 != (-24)); --g_93)
    {
        int32_t l_3242 = (-1L);
        p_20 = 0L;
        if (g_1704)
            continue;
        g_482[6][1][1] = l_3242;
        for (g_381 = 4; (g_381 != (-28)); --g_381)
        {
            uint32_t l_3245 = 0x97FA978AL;
            return l_3245;
        }
    }
    return l_3246;
}







static uint64_t func_22(uint32_t p_23, uint32_t p_24, int32_t p_25, uint64_t p_26, int32_t p_27)
{
    int16_t l_29[1];
    int32_t l_2180 = 0x3758556BL;
    int32_t l_2200 = (-5L);
    int32_t l_2202 = 4L;
    uint8_t l_2465 = 255UL;
    int16_t l_2466 = 0x34A5L;
    uint64_t l_2531[2][2] = {{1UL, 0x70602D019D4FD810LL}, {1UL, 0x70602D019D4FD810LL}};
    uint64_t l_2545 = 0x27492F07F239913FLL;
    int32_t l_2692 = 0x3EB17080L;
    int32_t l_2767 = 6L;
    uint64_t l_2849[2][3][2];
    int32_t l_2850[7] = {(-9L), 0x49979F67L, (-9L), 0x49979F67L, (-9L), 0x49979F67L, (-9L)};
    int32_t l_2990[6] = {9L, 0x79949B4FL, 9L, 0x79949B4FL, 9L, 0x79949B4FL};
    uint16_t l_3029 = 0x0006L;
    int i, j, k;
                      if (( l_2200 < -5) )
{

{
                        p_27 = ((safe_rshift_func_int16_t_s_s(((0x96C9DF21E312C42CLL >= (0xFA354F1FC35AFA75LL <= ((safe_mod_func_int16_t_s_s(g_482[5][1][0], (safe_lshift_func_uint16_t_u_u(g_15, (safe_rshift_func_int8_t_s_s((safe_sub_func_uint16_t_u_u(l_2465, ((safe_sub_func_int16_t_s_s(((g_695 != (safe_add_func_uint8_t_u_u((g_81[0] = (+(g_163 & (g_1388[1] > (l_2767 = ((g_694 > g_3106) , g_482[1][1][3])))))), (-1L)))) || g_1023[1][4][5]), g_202)) != 8UL))), 1)))))) == g_3106))) != l_2465), 4)) , 0x34CFAD37L);
                    }

}

for (i = 0; i < 1; i++)
        l_29[i] = 0x9209L;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 2; k++)
                l_2849[i][j][k] = 0x5CE67DD89BB4E8AFLL;
        }
    }
    l_29[0] = 1L;
    for (p_27 = 15; (p_27 >= 6); --p_27)
    {
        uint8_t l_43 = 255UL;
        uint16_t l_1351 = 7UL;
        int16_t l_1352 = 0xCED9L;
        int32_t l_2069 = 0xCC7CAC4CL;
        int32_t l_2070 = 0x6663D855L;
        p_25 = func_32(g_28[6][1], func_37(l_43, ((l_2069 = (((func_46((safe_lshift_func_int8_t_s_s(((func_53(func_55((safe_unary_minus_func_uint32_t_u(l_43)))) , g_695) , ((g_91 == (p_24 , (safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((safe_sub_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s(((((18446744073709551614UL >= 0xC7CC7D8C010F4ABALL) ^ l_43) < p_26) && l_29[0]), g_511)) <= l_1351), 0x83EEL)) ^ g_952[4][2]), p_27)), 0)))) & l_29[0])), 4)), l_1352, g_28[2][5], p_24) != g_1729[0][3]) && l_1351) > 0UL)) > (-2L)), l_2070, l_29[0], g_28[2][8]), g_1023[1][1][0], p_23);
    }
    for (p_26 = 0; (p_26 != 18); p_26++)
    {
        int8_t l_2179[7][1];
        int32_t l_2197[1][1][1];
        int8_t l_2244 = (-1L);
        uint32_t l_2430 = 18446744073709551615UL;
        uint8_t l_2431 = 252UL;
        uint32_t l_2454 = 1UL;
        int32_t l_2468 = 7L;
        uint16_t l_2490[10] = {0x6DBFL, 0xF908L, 0x6DBFL, 0xF908L, 0x6DBFL, 0xF908L, 0x6DBFL, 0xF908L, 0x6DBFL, 0xF908L};
        uint64_t l_2504 = 0UL;
        int32_t l_2591[3][7][6] = {{{1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}}, {{1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}}, {{1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}, {1L, 0x4C5BD215L, 0x731C91BFL, 3L, 0x845B1EC4L, 0L}}};
        int32_t l_2829 = 0xA764965EL;
        uint32_t l_2840 = 18446744073709551606UL;
        int i, j, k;
        for (i = 0; i < 7; i++)
        {
            for (j = 0; j < 1; j++)
                l_2179[i][j] = 0x2FL;
        }
                          if (( g_167 < 6) )
{

for (l_2180 = 0; l_2180 < 10; l_2180++)
    {
        for (l_2202 = 0; l_2202 < 6; l_2202++)
        {
            transparent_crc(g_758[l_2180][l_2202], "g_758[l_2180][l_2202]", g_93);
            if (g_93) printf("index = [%d][%d]\n", l_2180, l_2202);

        }
    };


}

for (i = 0; i < 1; i++)
        {
                              if (( g_695 < 0) )
{

__undefined -= 1;


}

for (j = 0; j < 1; j++)
            {
                for (k = 0; k < 1; k++)
                    l_2197[i][j][k] = 0x096C7C1FL;
            }
        }
        for (g_324 = 1; (g_324 <= 4); g_324 += 1)
        {
            uint32_t l_2199[7][3] = {{0xBB204A30L, 0xBB204A30L, 3UL}, {0xBB204A30L, 0xBB204A30L, 3UL}, {0xBB204A30L, 0xBB204A30L, 3UL}, {0xBB204A30L, 0xBB204A30L, 3UL}, {0xBB204A30L, 0xBB204A30L, 3UL}, {0xBB204A30L, 0xBB204A30L, 3UL}, {0xBB204A30L, 0xBB204A30L, 3UL}};
            int i, j;
            g_76 = (safe_add_func_uint16_t_u_u((((g_952[(g_324 + 1)][g_324] < p_25) | ((g_28[(g_324 + 2)][(g_324 + 1)] = 0x90C1L) <= ((g_520 = (l_2180 = (safe_unary_minus_func_int32_t_s(((0x53AFD7A7L == (safe_lshift_func_int16_t_s_u(((((safe_rshift_func_int16_t_s_u((safe_lshift_func_uint16_t_u_u((((safe_rshift_func_uint16_t_u_u(g_482[5][1][0], (0xECBDDB81CA17BB01LL <= g_952[4][2]))) != (safe_sub_func_uint8_t_u_u(((4294967295UL || (!(safe_rshift_func_int16_t_s_u(9L, g_579)))) != g_1783[6][0]), g_1729[0][0]))) , g_188[0]), p_26)), 12)) || l_2179[4][0]) , p_25) , 0xF606L), 15))) != 0x6CB5L))))) || l_29[0]))) , 0UL), 0xA2AEL));
            if (p_23)
                break;
            l_2202 = (((((safe_add_func_int16_t_s_s((((0x72D2L | ((((safe_mod_func_uint16_t_u_u(g_151, ((g_952[6][2] = (safe_add_func_int8_t_s_s((65526UL < (l_2200 = ((((((safe_lshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u(((safe_rshift_func_uint8_t_u_u((((l_2179[4][0] || ((l_2180 = ((0x40FC27C9L | ((((safe_lshift_func_int8_t_s_u(((l_2197[0][0][0] <= l_2180) >= (safe_unary_minus_func_int32_t_s((g_579 = 1L)))), 5)) == g_482[0][2][2]) & 0x7AL) != l_29[0])) > 0xD6E640B49B40DADBLL)) , 0x91L)) >= p_23) , 0x99L), 7)) == p_25), 3)), g_952[(g_324 + 1)][g_324])) & g_482[5][2][3]) != g_423) == l_2199[5][2]) , 0UL) < 0x4FL))), g_2201))) , g_167))) < 0x9C6A0B10L) <= g_81[0]) , 0x1701L)) , l_2179[4][0]) <= 0xAAL), p_25)) > p_23) , p_24) , g_1970) >= 0x424AL);
        }
        l_2200 = (p_25 = (((g_167 | (safe_rshift_func_int16_t_s_s(p_25, 10))) | l_2180) | (((safe_rshift_func_int8_t_s_s(g_1613, l_2197[0][0][0])) <= 18446744073709551607UL) | p_26)));
        if ((safe_lshift_func_int16_t_s_s(((((1L > (9UL != (l_2202 = (safe_add_func_int32_t_s_s(p_26, (safe_mod_func_uint64_t_u_u((safe_unary_minus_func_uint64_t_u(18446744073709551612UL)), (g_1820 && (0x5F824377D2A3173ELL && g_758[0][2]))))))))) | (safe_rshift_func_uint8_t_u_u(((l_2200 = ((p_24 ^ (safe_add_func_uint64_t_u_u(0UL, l_2197[0][0][0]))) , 0x98FE05F47D1147DFLL)) & p_24), g_875))) & 0x4E530206L) | g_202), 0)))
        {
            uint16_t l_2226 = 0xDCBDL;
            int64_t l_2243[6] = {5L, 0xB2D8883A982846D0LL, 5L, 0xB2D8883A982846D0LL, 5L, 0xB2D8883A982846D0LL};
            int32_t l_2245[1][2];
            uint8_t l_2262 = 7UL;
            uint32_t l_2277 = 4294967295UL;
            uint16_t l_2387 = 0x18E8L;
            int32_t l_2467 = (-2L);
            int i, j;
            for (i = 0; i < 1; i++)
            {
                for (j = 0; j < 2; j++)
                    l_2245[i][j] = 0L;
            }
            if (((l_2197[0][0][0] = (l_2245[0][1] = ((9L ^ ((~(safe_mod_func_int64_t_s_s((l_2200 = (4L != g_1613)), (safe_unary_minus_func_uint64_t_u((((((((((((((g_559 > (safe_sub_func_uint16_t_u_u(l_2226, g_1016))) ^ 0xDFL) , (l_2197[0][0][0] & (safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_u((l_2202 = (((safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((safe_mod_func_uint32_t_u_u((p_24 = (safe_rshift_func_int8_t_s_u((((((safe_lshift_func_int8_t_s_u((safe_mod_func_int32_t_s_s(1L, g_559)), l_2179[1][0])) , l_2226) , 1L) == p_27) > g_1507), 0))), g_208)), l_2197[0][0][0])), 0L)) < l_2243[5]) , l_2197[0][0][0])), g_519)), 0xF8EEC641L)))) , 4294967294UL) | l_2244) == 0x7D80576F5A2AA679LL) & 0xC0L) <= p_25) >= p_25) < 249UL) != g_1507) & g_76) || p_26)))))) > g_28[6][1])) <= p_27))) > l_2226))
            {
                int32_t l_2250[6][4][4] = {{{0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}}, {{0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}}, {{0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}}, {{0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}}, {{0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}}, {{0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}, {0xD137FB06L, (-1L), 0x2A23451FL, (-2L)}}};
                int64_t l_2307 = 0xC8EB9C2FB78442A6LL;
                int16_t l_2308 = (-5L);
                int i, j, k;

{
        for (p_25 = 0; p_25 < 9; p_25++)
        {
            transparent_crc(g_28[l_2767][p_25], "g_28[l_2767][p_25]", g_167);
            if (g_167) printf("index = [%d][%d]\n", l_2767, p_25);

        }
    }


l_2197[0][0][0] = ((safe_add_func_int64_t_s_s((safe_lshift_func_uint16_t_u_u(l_2250[0][1][1], ((p_25 = (((safe_unary_minus_func_int8_t_s((((safe_mod_func_int32_t_s_s((safe_mod_func_int64_t_s_s((((safe_lshift_func_int16_t_s_s(g_758[6][5], l_2250[3][0][3])) > (safe_unary_minus_func_int64_t_s(((0x97A29866E7AF8D4BLL & (0xF2133AFCL > ((0x21L >= (safe_sub_func_int64_t_s_s((((((~((p_27 , g_521) ^ g_875)) <= 0x34L) || p_27) | p_25) , 0x12F00221D3EA775ELL), 0xF3454C2B60C85511LL))) && l_2245[0][1]))) && 0xDF21L)))) != g_202), 0xF1B11B653B335DE6LL)), p_26)) || p_26) & 0UL))) == l_2226) & 249UL)) || 0x936C7C71L))), p_24)) && 0L);
                l_2250[0][1][1] = ((l_2250[0][1][1] != ((l_2262 >= ((l_2245[0][1] = (safe_sub_func_uint32_t_u_u(g_15, l_2202))) >= (((safe_lshift_func_uint16_t_u_s(((((l_2250[0][1][1] , ((safe_mod_func_int16_t_s_s((g_15 || (safe_lshift_func_int16_t_s_u((safe_mod_func_int32_t_s_s((safe_sub_func_uint8_t_u_u(((l_2180 = p_24) , (p_24 >= (safe_rshift_func_uint8_t_u_u((((l_29[0] ^ 4294967292UL) <= g_148) > 0x8740B0CDL), 4)))), p_23)), g_1729[0][2])), l_2202))), 0x3BAFL)) < g_148)) , 0L) ^ l_2262) == 0L), l_2179[6][0])) , p_27) >= 0x329FL))) | l_2277)) , l_29[0]);
                for (g_151 = 0; (g_151 != 21); g_151 = safe_add_func_int16_t_s_s(g_151, 4))
                {
                    g_76 = (p_26 >= p_23);
                    if (p_23)
                        break;
                }
                if (((((((safe_mod_func_uint16_t_u_u((((((safe_add_func_uint64_t_u_u((g_1730 = ((safe_mod_func_int64_t_s_s(((safe_sub_func_int32_t_s_s(g_1388[2], p_23)) ^ 0L), (safe_add_func_int16_t_s_s((((g_148 = l_29[0]) | (g_521 = (l_2179[4][0] , p_25))) | l_29[0]), g_81[0])))) > (((l_2245[0][1] = (safe_unary_minus_func_int8_t_s(((p_25 | g_1405[6][3][1]) , l_2197[0][0][0])))) != 0UL) < 0x7D8B615FL))), l_2179[4][0])) || g_521) , 255UL) || p_27) >= g_28[6][1]), 0xA250L)) && 0xA29BL) == 0xE0ABL) < l_2197[0][0][0]) >= g_15) && p_24))
                {
                    uint8_t l_2349 = 252UL;
                    if ((g_105[0][1][9] && (+(((((p_23 , g_381) || (((0x1261L <= (1UL == ((!0x80L) == (l_2250[0][1][1] = ((((g_952[5][4] > (safe_rshift_func_int16_t_s_s(((l_2197[0][0][0] | (safe_rshift_func_uint16_t_u_s(l_2244, p_23))) <= g_152[1][0][5]), g_1730))) && p_25) < g_1703) , l_2197[0][0][0]))))) ^ l_2197[0][0][0]) & p_27)) ^ 0xA90FL) && (-6L)) ^ g_520))))
                    {
                        int32_t l_2322[5] = {0xE6985877L, 0xDF323E0AL, 0xE6985877L, 0xDF323E0AL, 0xE6985877L};
                        int i;
                        p_25 = (safe_rshift_func_uint8_t_u_u(249UL, (safe_rshift_func_uint8_t_u_s((65530UL & (p_24 != p_26)), 2))));
                        g_76 = ((((((~(safe_sub_func_uint64_t_u_u((l_2250[0][1][1] = ((safe_unary_minus_func_int8_t_s(g_1023[1][4][5])) > (safe_add_func_int16_t_s_s(((l_2307 | 0x657974C6L) && (g_202 >= ((((g_747 = ((l_2308 , (safe_rshift_func_int16_t_s_u((safe_rshift_func_int8_t_s_u(l_2244, 2)), 6))) | ((safe_sub_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((+(((l_2200 == g_483[2]) , (((safe_sub_func_int64_t_s_s((((((((l_2226 >= l_2322[4]) > p_25) , p_27) & p_23) | 0xDD299C761F8E3105LL) >= l_2250[0][1][1]) >= p_27), p_23)) , p_23) < l_2180)) && l_2250[0][1][1])), 4294967295UL)), 3)), (-1L))) != g_203))) , l_2322[0]) | p_23) ^ 0x19L))), g_1703)))), g_483[2]))) == g_1820) , g_519) || p_24) ^ p_26) >= 0UL);
                        g_482[3][2][1] = (-9L);
                        p_25 = (safe_lshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s((safe_mod_func_uint32_t_u_u((p_25 > ((safe_rshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_s((safe_sub_func_uint64_t_u_u(((p_25 == (l_2180 = (0xBD8FE360L <= ((((((safe_unary_minus_func_int16_t_s(((p_23 != (safe_mod_func_int8_t_s_s(((+((safe_rshift_func_int8_t_s_s((p_27 >= (safe_add_func_int64_t_s_s((((((l_29[0] && ((safe_mod_func_int32_t_s_s(((l_2262 < (((l_2202 = (((l_2322[3] = ((safe_lshift_func_uint8_t_u_s(l_2322[4], ((249UL < l_29[0]) ^ g_152[2][0][3]))) || p_24)) >= 0x9FDAE2E57A37FF36LL) , (-1L))) && l_2349) && p_25)) != l_2349), g_188[0])) != p_27)) ^ g_188[0]) == p_26) && l_2322[4]) > l_2349), 0xAD501DF9083C6E8ALL))), 2)) | g_1703)) & 0xDB40L), l_2226))) > 6UL))) , 1UL) >= 0L) ^ p_25) , l_2322[4]) || 0xFCL)))) ^ 3UL), l_2307)), g_747)), 8)) && g_124)), g_151)), l_2349)), p_27)), l_2349));
                    }
                    else
                    {
                        return l_2243[0];
                    }
                    for (g_695 = 0; (g_695 >= 0); g_695 -= 1)
                    {
                        int32_t l_2350 = 1L;
                        int i;
                        p_25 = g_188[g_695];
                        if (p_26)
                            continue;
                        if (l_2308)
                            break;
                        l_2350 = g_105[0][3][1];
                    }
                }
                else
                {
                    int8_t l_2363[2];
                    int i;
                    for (i = 0; i < 2; i++)
                        l_2363[i] = 0x82L;
                    g_579 = (safe_mod_func_int8_t_s_s((l_2245[0][1] = (g_151 = (l_2262 > 0x1B30L))), (((safe_rshift_func_int8_t_s_u(g_152[1][0][4], 7)) , ((safe_sub_func_int16_t_s_s(l_2250[0][1][1], l_2250[0][1][1])) < (safe_sub_func_int64_t_s_s(((((safe_mod_func_int16_t_s_s(g_2201, (p_26 && (p_23 && ((safe_rshift_func_uint16_t_u_u(l_2226, 2)) == 0x005A61D1FE15AA38LL))))) ^ p_27) > l_2363[1]) | p_24), 0x38E321867D3B39A6LL)))) && 1L)));
                }
            }
            else
            {
                int8_t l_2375 = (-1L);
                uint64_t l_2388 = 18446744073709551610UL;
                for (g_1854 = 2; (g_1854 == 9); g_1854++)
                {
                    for (l_2202 = (-29); (l_2202 > (-4)); l_2202 = safe_add_func_int16_t_s_s(l_2202, 3))
                    {
                        if (p_23)
                            break;
                    }
                    for (g_521 = 0; (g_521 <= 0); g_521 += 1)
                    {
                        int i;
                        g_76 = g_81[g_521];
                    }
                }
                for (g_203 = (-24); (g_203 > 7); g_203++)
                {
                    uint8_t l_2405 = 246UL;
                    int32_t l_2406 = (-1L);
                    p_25 = (safe_add_func_uint16_t_u_u((+p_24), (255UL == (-1L))));
                    if (p_26)
                    {
                        if (p_27)
                            break;
                        p_25 = (((((safe_rshift_func_int8_t_s_u(((p_23 && (l_2375 = (g_551 = g_559))) , (255UL ^ (((safe_sub_func_uint8_t_u_u(p_23, 0UL)) == (safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint8_t_u_u(((((g_324 , ((safe_add_func_int8_t_s_s((((((p_25 , (safe_add_func_int16_t_s_s((p_23 < (+0x42256224FF56A661LL)), g_694))) <= p_27) >= (-1L)) <= p_25) != p_26), p_27)) >= g_202)) || l_2375) < l_2375) == 0xA1L), 2)), g_1023[1][4][5]))) && l_2387))), g_148)) < 255UL) || p_25) < g_952[5][3]) , 1L);
                    }
                    else
                    {
                        p_25 = (g_105[0][6][9] = ((l_2388 != (p_23 != (((g_952[0][0] = g_1884) || ((((safe_add_func_int16_t_s_s((g_1593 & (safe_lshift_func_int16_t_s_s(g_81[0], 12))), (((safe_sub_func_uint16_t_u_u(l_2388, (safe_mod_func_int16_t_s_s((l_29[0] <= (((safe_mod_func_uint64_t_u_u(((((g_1775 = g_81[0]) & g_152[1][0][0]) != p_24) != g_28[0][8]), 18446744073709551611UL)) > 0x69C295B25130E0D6LL) , g_269)), 0x0C93L)))) == g_1613) , l_2244))) >= g_93) , 0x22B6L) | p_25)) & p_26))) < p_26));
                        l_2197[0][0][0] = p_23;
                        g_105[0][3][0] = ((safe_mod_func_uint64_t_u_u((+((g_324 , (((~(65527UL == 1L)) , ((safe_lshift_func_uint16_t_u_s(g_758[0][2], (((l_2406 = (l_2405 < l_2405)) || ((g_695 , (((p_24 ^ ((p_23 & l_2388) , 0UL)) , p_27) & 8L)) & 0x0A9C8F6262EF761CLL)) , 0x9193L))) == g_151)) || p_25)) >= p_27)), l_2388)) < 1UL);
                        return g_511;
                    }
                    if (g_1593)
                        continue;
                }
            }
            l_2202 = (p_26 , (p_25 = ((safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((((g_1730 = p_27) | ((safe_mod_func_uint64_t_u_u((~(((safe_mod_func_int32_t_s_s((safe_sub_func_uint64_t_u_u(((safe_lshift_func_int8_t_s_u(((safe_lshift_func_int16_t_s_u((l_2387 & (((l_2245[0][0] = (0x2951L > l_2197[0][0][0])) | l_2244) <= g_1775)), (l_2200 = g_1388[2]))) != ((safe_rshift_func_uint16_t_u_u((((safe_rshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s(((safe_add_func_int32_t_s_s(((3L || g_1507) ^ 1L), 0x85BFDC9FL)) > l_2430), g_482[6][2][2])), l_2179[4][0])) <= l_29[0]) && l_2179[0][0]), g_423)) < g_483[1])), p_26)) >= 0L), 0x32C5C46F32FAB364LL)), l_2387)) && l_2430) | g_28[0][1])), l_2431)) & l_2202)) >= 0xD2624FD5A033F98ALL), 9)), l_2226)) & p_25)));
            l_2468 = (safe_lshift_func_uint16_t_u_s((safe_sub_func_uint16_t_u_u((safe_mod_func_int8_t_s_s((((l_2245[0][0] != (l_2387 > ((p_27 != (g_381 = ((l_2467 = ((safe_lshift_func_uint16_t_u_u(((1L && (safe_mod_func_int64_t_s_s((safe_rshift_func_uint16_t_u_s((((((((safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((safe_unary_minus_func_uint32_t_u((l_2197[0][0][0] = (((((safe_rshift_func_uint16_t_u_u(((((+(l_2454 > (safe_rshift_func_int16_t_s_s((((safe_lshift_func_uint16_t_u_u((((safe_rshift_func_int16_t_s_s((~l_29[0]), (safe_sub_func_int16_t_s_s(l_2243[5], ((~(0xDB79L < ((((9UL | l_2202) | 1UL) | 18446744073709551608UL) || g_576))) ^ p_23))))) != 8L) <= 0x19B0L), 2)) < 1UL) < l_2179[4][0]), 3)))) , l_2197[0][0][0]) , 1L) > l_2243[5]), g_1884)) || 1L) != 0UL) || p_26) != (-1L))))), g_202)), 0xDCF5L)) , g_1016) == l_2465) && l_2245[0][1]) ^ l_2202) > 255UL) & l_2466), 15)), p_25))) == g_148), p_25)) | g_1730)) != p_23))) < 0UL))) || l_2243[5]) && 0xBCD2L), p_26)), g_188[0])), 7));
            return l_2245[0][0];
        }
        else
        {
            int32_t l_2483 = (-3L);
            int16_t l_2491[10][2][1] = {{{0x93C5L}, {0x93C5L}}, {{0x93C5L}, {0x93C5L}}, {{0x93C5L}, {0x93C5L}}, {{0x93C5L}, {0x93C5L}}, {{0x93C5L}, {0x93C5L}}, {{0x93C5L}, {0x93C5L}}, {{0x93C5L}, {0x93C5L}}, {{0x93C5L}, {0x93C5L}}, {{0x93C5L}, {0x93C5L}}, {{0x93C5L}, {0x93C5L}}};
            int32_t l_2503 = (-1L);
            int64_t l_2690 = 0x01B674E72A06BFD2LL;
            uint16_t l_2691 = 0UL;
            int32_t l_2740 = 0xF1E5EB90L;
            int i, j, k;
            if ((safe_mod_func_int8_t_s_s((((safe_rshift_func_uint8_t_u_s((p_23 > (safe_rshift_func_int16_t_s_u((l_2179[4][0] & (safe_rshift_func_int16_t_s_s((l_2468 != (((safe_lshift_func_int8_t_s_s((safe_add_func_int64_t_s_s((safe_add_func_uint32_t_u_u(l_2483, ((safe_sub_func_int64_t_s_s(g_188[0], (safe_add_func_uint32_t_u_u((((((safe_mod_func_uint32_t_u_u(p_24, g_202)) < (l_2490[2] && (p_26 , 0x52A3L))) <= 0x2AL) <= 4294967295UL) < p_25), 4294967295UL)))) != p_27))), g_1820)), 7)) <= g_1854) & 0x3889L)), 13))), 2))), p_26)) < l_2491[4][0][0]) || 0x45L), l_2483)))
            {
                int16_t l_2502[4][9] = {{8L, 6L, (-2L), 6L, 8L, (-1L), (-2L), (-1L), 8L}, {8L, 6L, (-2L), 6L, 8L, (-1L), (-2L), (-1L), 8L}, {8L, 6L, (-2L), 6L, 8L, (-1L), (-2L), (-1L), 8L}, {8L, 6L, (-2L), 6L, 8L, (-1L), (-2L), (-1L), 8L}};
                int i, j;
                l_2180 = (safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((((0L >= 18446744073709551615UL) == (safe_lshift_func_int16_t_s_s((0x58L >= (l_2483 = (g_1507 < (l_2197[0][0][0] = p_25)))), 11))) ^ ((l_2503 = (safe_rshift_func_uint16_t_u_u(((p_25 , g_1704) != ((safe_rshift_func_int8_t_s_u((g_276 = ((l_2454 , (2L < l_2465)) || g_465)), l_2502[1][0])) <= g_559)), 14))) , g_1388[0])), l_2466)), l_2504));
                if (p_27)
                    break;
                g_1775 = 0x00B86130L;
                g_482[0][1][3] = (p_25 = p_24);
            }
            else
            {
                uint8_t l_2513 = 2UL;
                int32_t l_2546 = 0x6CE34449L;
                uint32_t l_2594[2][4][8];
                uint64_t l_2595 = 8UL;
                int i, j, k;

{
                        if (l_2454)
                            break;
                    }


for (i = 0; i < 2; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        for (k = 0; k < 8; k++)
                            l_2594[i][j][k] = 0x3730E86CL;
                    }
                }
                for (g_1507 = (-11); (g_1507 >= (-22)); g_1507--)
                {
                    uint16_t l_2518 = 0x640BL;
                    int32_t l_2583[8][2][3] = {{{0x401C324AL, (-9L), (-1L)}, {0x401C324AL, (-9L), (-1L)}}, {{0x401C324AL, (-9L), (-1L)}, {0x401C324AL, (-9L), (-1L)}}, {{0x401C324AL, (-9L), (-1L)}, {0x401C324AL, (-9L), (-1L)}}, {{0x401C324AL, (-9L), (-1L)}, {0x401C324AL, (-9L), (-1L)}}, {{0x401C324AL, (-9L), (-1L)}, {0x401C324AL, (-9L), (-1L)}}, {{0x401C324AL, (-9L), (-1L)}, {0x401C324AL, (-9L), (-1L)}}, {{0x401C324AL, (-9L), (-1L)}, {0x401C324AL, (-9L), (-1L)}}, {{0x401C324AL, (-9L), (-1L)}, {0x401C324AL, (-9L), (-1L)}}};
                    int16_t l_2598 = 0L;
                    int i, j, k;
                    if ((g_105[0][2][5] , (((l_2468 = ((g_1729[0][3] >= 0x3BL) || ((safe_mod_func_int16_t_s_s(((((0xC7L < (safe_add_func_int64_t_s_s((l_2483 = ((safe_add_func_uint32_t_u_u((g_2151 = ((((-1L) > ((1L ^ ((l_2513 | (safe_lshift_func_int8_t_s_u((((g_465 = (safe_sub_func_int32_t_s_s((((1L < 4L) && p_25) > (-1L)), l_2503))) , p_24) != 7L), 6))) , l_2518)) & p_25)) == 8L) & l_29[0])), p_26)) ^ l_2244)), l_2200))) < p_23) & 0x6D05D24469E59CC0LL) , 0x77F4L), 0x9867L)) <= 0x2901L))) & l_2518) < p_27)))
                    {
                        uint64_t l_2528 = 9UL;
                        int32_t l_2544 = 0x3EA38060L;
                        l_2483 = ((((((g_482[6][2][1] = (-6L)) <= ((safe_add_func_int64_t_s_s((safe_add_func_int8_t_s_s(l_2491[1][0][0], ((((((((~(0xA3L && (safe_lshift_func_uint8_t_u_s((safe_add_func_int64_t_s_s((g_1820 = l_2528), ((0UL < 4L) ^ (safe_lshift_func_uint8_t_u_s((g_695 ^ (((g_520 & p_23) != (-4L)) <= g_1016)), 2))))), 1)))) & p_27) != g_208) , p_24) >= 18446744073709551612UL) != l_2466) && g_695) | g_269))), 0x946BC4B4833C51A9LL)) >= l_2531[1][0])) || p_24) || 5UL) , 0xB0D1L) ^ 1UL);
                        l_2483 = (g_482[4][2][0] = g_1775);
                        p_25 = (p_27 >= (safe_rshift_func_int8_t_s_u((0L ^ (((247UL & (((1L | l_2528) && ((((l_2546 = (safe_lshift_func_uint8_t_u_u((l_2504 >= ((safe_rshift_func_uint8_t_u_s(((l_2545 = ((safe_mod_func_uint32_t_u_u(((g_105[0][0][4] = 3L) >= (l_2544 = ((safe_lshift_func_int16_t_s_u(((((safe_lshift_func_int16_t_s_u((((p_26 >= (l_2531[1][0] > l_2454)) < 7L) | (-3L)), p_25)) == g_952[0][0]) < p_26) <= 0L), 7)) & 65535UL))), l_2513)) < p_26)) , 0x36L), p_26)) <= l_2513)), 0))) || p_26) > 0L) <= 1L)) ^ g_694)) > l_2491[4][0][0]) < 0x9106BF15L)), l_2518)));
                        p_25 = ((((safe_unary_minus_func_uint16_t_u((g_747 = l_2244))) || ((g_521 <= p_25) == 0x23D2F281FE4DF34CLL)) <= ((l_2503 & (safe_add_func_int32_t_s_s(((((((safe_lshift_func_int8_t_s_u(0xCAL, 4)) < ((safe_lshift_func_int8_t_s_s(g_1593, ((~g_203) , (l_2546 = (7L != l_2430))))) && g_151)) < g_105[0][3][1]) & (-2L)) || g_188[0]) == l_2528), p_23))) <= p_23)) != 0L);
                    }
                    else
                    {
                        uint32_t l_2555 = 18446744073709551615UL;
                        int8_t l_2560 = 0x45L;
                        uint32_t l_2582 = 0xC8E1D23EL;
                        int32_t l_2584 = 0x420D0B9AL;
                        p_25 = l_2555;
                        p_25 = (((safe_rshift_func_int8_t_s_u(0x95L, 0)) > (safe_sub_func_int16_t_s_s((l_2560 = l_2513), (l_2200 = ((safe_add_func_int16_t_s_s((((safe_mod_func_uint16_t_u_u(((safe_mod_func_int64_t_s_s((l_2584 = ((((safe_sub_func_uint16_t_u_u(((l_2465 >= (!((safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((p_27 & ((safe_rshift_func_uint8_t_u_s((p_27 && 0xC8344F90L), (((((safe_lshift_func_uint8_t_u_s(p_24, 0)) ^ (l_2583[0][1][0] = ((safe_sub_func_uint8_t_u_u(252UL, (g_151 = (((safe_lshift_func_int8_t_s_s((l_2197[0][0][0] , l_2582), 5)) != p_23) , (-7L))))) != 0L))) <= g_81[0]) > 0x588F3B4CL) && 0L))) == g_81[0])), l_2546)), l_2244)) , p_27))) && l_2179[3][0]), p_27)) && p_26) , 0xA519L) & 0x1429L)), g_1783[2][0])) , 0x69EFL), p_25)) >= g_520) & 3UL), l_2491[4][0][0])) < 0x72123D20B98395B3LL))))) , 0L);
                    }
                    if ((~((l_2202 = (((p_23 ^ ((+((0x94L | (p_26 && (safe_lshift_func_uint8_t_u_u(((safe_lshift_func_int8_t_s_u((g_151 = (l_2531[0][0] > ((((l_2591[1][4][0] || (p_23 , (l_2503 , (p_25 == ((((((safe_sub_func_int64_t_s_s((0UL <= p_24), 0L)) || g_1854) < 0xFBFCF9863BBFDDD1LL) | g_148) , 0x83E3AF1DL) >= g_482[0][0][2]))))) && l_2583[4][0][2]) ^ g_1783[5][0]) & p_25))), l_2518)) ^ l_2594[0][1][2]), 5)))) | 0xEDL)) && l_2531[1][0])) && 4294967295UL) ^ p_24)) < g_105[0][5][9])))
                    {
                        int16_t l_2599 = 0xD2DAL;
                        l_2197[0][0][0] = p_24;
                        l_2503 = (((((((l_2595 = ((-1L) <= p_25)) < (((((g_28[6][1] = p_23) , ((((p_23 == 0L) & (((((l_2594[1][1][7] || (((p_26 || (safe_add_func_int32_t_s_s((l_2598 | g_91), g_152[0][0][4]))) < l_2583[5][0][1]) | 0xDEA8606B15FA6FC4LL)) , l_2546) >= 0xBC36L) , p_27) != g_1884)) >= 0xFF93EFC75541F40CLL) ^ l_2430)) <= l_2599) | p_27) || l_2491[7][1][0])) , g_694) < l_2599) > 6UL) | p_26) == l_2599);
                        g_105[0][6][1] = (((((-5L) | (l_2546 = p_27)) | ((safe_mod_func_int32_t_s_s(9L, g_1884)) && l_2513)) < (g_482[5][1][0] = (+((0L && ((safe_lshift_func_uint16_t_u_u(65535UL, p_27)) , ((g_2151 = 4294967291UL) != p_23))) != p_27)))) && l_2513);
                    }
                    else
                    {
                        uint64_t l_2613 = 0x8E8A0B4290D126F6LL;
                        p_25 = (((safe_lshift_func_int16_t_s_u(((safe_sub_func_int8_t_s_s((safe_add_func_int8_t_s_s((l_2546 = (safe_rshift_func_int16_t_s_u((((p_27 >= ((g_465 = (l_2613 , ((l_2613 | ((((safe_add_func_int8_t_s_s(l_2583[0][1][0], (safe_rshift_func_int16_t_s_s(1L, 12)))) & (!g_1613)) , ((l_2197[0][0][0] , (((safe_lshift_func_int8_t_s_u((safe_rshift_func_int8_t_s_s(((((l_2583[4][1][1] = (l_2200 = ((((((safe_unary_minus_func_int16_t_s(0xE145L)) > (((safe_sub_func_int64_t_s_s(p_27, (-10L))) | (-10L)) , g_167)) <= 0x1466FDFBBCBE1C07LL) != p_27) && 0xA573L) , l_2503))) , 0x4FBDB27830B92C88LL) == g_1704) || 0xF3F2L), 0)), g_188[0])) && p_26) || g_105[0][3][1])) | l_2598)) < p_25)) , 1L))) ^ p_26)) ^ 4294967295UL) ^ l_2483), 7))), 0x21L)), p_27)) > 1UL), g_2151)) < g_1507) > p_27);

for (g_93 = 0; g_93 < 1; g_93++)
                            g_188[g_93] = 2UL;


l_2583[1][1][2] = ((((g_483[1] || ((safe_lshift_func_int8_t_s_u(((safe_lshift_func_uint8_t_u_s(((((safe_lshift_func_uint8_t_u_s(252UL, (((g_2151 = (((safe_sub_func_int64_t_s_s(((safe_add_func_uint16_t_u_u((((safe_sub_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u((p_26 != ((safe_sub_func_int32_t_s_s((safe_sub_func_int64_t_s_s(0xD43097BD0D1DBF83LL, (safe_mod_func_uint16_t_u_u((l_2468 = l_2491[4][0][0]), (+l_2594[0][1][2]))))), ((p_26 ^ (((((g_203 , ((((safe_rshift_func_uint8_t_u_s(p_24, p_26)) , 0x598EL) ^ (-8L)) || 0L)) != 0xB588A448E0971639LL) , 0x1CB2997BL) > 0x4377E664L) == p_25)) || l_2518))) > 0x0EA9660DL)), p_27)), g_1023[0][4][0])) < 0xE1E21288L) , l_2613), g_1970)) , l_2483), p_26)) , g_81[0]) ^ l_2490[4])) && g_1704) , p_24))) > 0L) && g_151) & 0xB4F8L), 2)) != l_2490[2]), g_694)) > 0x980EB088175350E4LL)) < l_2613) , 9L) < p_26);
                    }
                    for (g_521 = 13; (g_521 < 28); ++g_521)
                    {
                        p_25 = ((g_269 ^ (-8L)) ^ g_465);
                        return p_24;
                    }
                }
                l_2483 = ((l_2546 = (safe_add_func_uint8_t_u_u(g_579, (0xA469F79A7A764C8DLL < g_105[0][5][5])))) | ((((safe_sub_func_int16_t_s_s(g_1729[0][3], (l_2202 = p_23))) ^ ((safe_rshift_func_int8_t_s_s((~(((((l_2180 = (safe_rshift_func_int16_t_s_u((((safe_mod_func_uint8_t_u_u(((g_324 = (l_2594[0][1][2] && (safe_lshift_func_int16_t_s_u((((safe_mod_func_uint64_t_u_u(((0x73414183L || 0x2DF0FD9FL) || ((((~(g_269 >= (-1L))) ^ g_483[1]) || g_423) | g_758[0][2])), 0x4549BA388BC69A37LL)) < p_26) , l_2513), 15)))) || 0x54A5L), g_1121)) <= g_559) < 0x4D1CL), l_2591[1][4][0]))) == l_2197[0][0][0]) > g_559) || p_24) | 0x4CL)), 7)) & p_23)) <= g_208) , p_23));
                g_76 = (safe_rshift_func_int16_t_s_u(0xA4F2L, 13));
            }
            for (g_875 = (-19); (g_875 <= (-25)); g_875--)
            {
                int64_t l_2679[6] = {(-10L), 0x1BC37BA8C4C98BEELL, (-10L), 0x1BC37BA8C4C98BEELL, (-10L), 0x1BC37BA8C4C98BEELL};
                int32_t l_2699 = 0x6834504CL;
                uint64_t l_2745[1];
                int8_t l_2766 = (-1L);
                int64_t l_2772[8][8] = {{1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L}, {1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L}, {1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L}, {1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L}, {1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L}, {1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L}, {1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L}, {1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L, 0x3DB6A5591EAE96DCLL, 1L, 1L}};
                int i, j;
                for (i = 0; i < 1; i++)
                    l_2745[i] = 18446744073709551615UL;
                if (l_2491[1][0][0])
                    break;
                for (g_2151 = 29; (g_2151 > 53); g_2151 = safe_add_func_int16_t_s_s(g_2151, 7))
                {
                    uint32_t l_2719 = 4294967295UL;
                    int32_t l_2742 = 0x18E14F04L;
                    if (((((safe_rshift_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u(0x48L, (g_152[1][0][5] ^ l_2679[2]))) <= (l_2679[2] , 18446744073709551615UL)), (safe_rshift_func_uint8_t_u_s((p_27 != (safe_sub_func_uint8_t_u_u((0x99A0BAF2EB22F11BLL && 18446744073709551607UL), ((safe_sub_func_uint32_t_u_u((safe_add_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_u((g_423 >= g_758[1][1]), g_91)) ^ l_2690), (-1L))), l_2691)) | p_23)))), p_27)))) , l_2692) , p_26) , 0x1D5C8F78L))
                    {
                        uint16_t l_2693 = 0x897BL;
                        g_482[5][1][0] = l_2693;
                        g_482[0][2][3] = (safe_rshift_func_uint16_t_u_u((safe_add_func_uint64_t_u_u((((!((((((((l_2699 = 0xDDB3L) && (((!(l_2179[4][0] < (g_2720[2] = ((((((((((8UL <= (((safe_mod_func_int32_t_s_s(g_269, (((safe_sub_func_int32_t_s_s((safe_unary_minus_func_int8_t_s(((p_24 = p_26) , (0xE3E7L > (((g_2718 = (((((safe_add_func_uint32_t_u_u((safe_add_func_uint32_t_u_u((safe_add_func_uint8_t_u_u((safe_add_func_int32_t_s_s(((((4294967295UL | (l_2699 = (safe_lshift_func_uint8_t_u_s(0x30L, 2)))) != (safe_sub_func_uint16_t_u_u(0x063DL, l_2545))) == g_520) <= g_423), p_27)), 1UL)), p_23)), 0L)) | 0xA67F6A19L) & p_27) <= 1L) | l_29[0])) > p_26) , l_2719))))), 0xE71CC545L)) <= 0x13L) , p_27))) , g_1884) >= l_2531[0][0])) == g_148) ^ 1L) && g_1729[0][3]) && g_105[0][0][9]) & 0x8B3DL) || l_2490[0]) && 0xE9L) , p_24) , l_2690)))) >= 0UL) == 0x8D029B4CL)) , p_26) == 1UL) == l_2679[0]) > p_25) && g_163) | p_25)) <= 0x0A25L) , g_15), g_93)), 11));
                        p_25 = (-1L);

g_551 += 1;



if (p_24)
                            {

if (p_25)
            continue;


break;}

                    }
                    else
                    {
                        int64_t l_2741 = 0x8A3ABE652606BDE5LL;
                        int32_t l_2743 = 0xC46B6AB5L;
                        int32_t l_2744 = 0x0B2AC45FL;
                        if (p_23)
                            break;

for (g_579 = 0; g_579 < 1; g_579++)
    {
        transparent_crc(g_81[g_579], "g_81[g_579]", g_694);
        if (g_694) printf("index = [%d]\n", g_579);

    };



l_2699 = ((p_25 = (((((((l_2490[4] != 0xEFL) > (((safe_add_func_int32_t_s_s(l_2679[3], (((((0x55901A7003B9FE29LL >= (l_2743 = (safe_add_func_uint64_t_u_u(1UL, (l_2200 = ((l_2742 = ((l_2468 = (+(safe_rshift_func_int16_t_s_s(((((l_2741 = ((safe_lshift_func_uint16_t_u_s((((((((safe_lshift_func_int16_t_s_u((safe_lshift_func_uint16_t_u_u((((((l_2591[0][5][0] = (safe_unary_minus_func_int32_t_s(p_26))) , (l_2202 = 1UL)) != 1L) == (safe_rshift_func_uint8_t_u_u((((((((((safe_rshift_func_uint8_t_u_s((!g_188[0]), l_29[0])) , l_2719) && p_23) > 0x9E2BF2DCL) ^ g_381) && p_23) & g_483[1]) || p_27) | p_24), 2))) , g_1388[2]), g_1783[3][0])), l_2740)) && 0x14A4D940L) <= g_2151) != p_26) < l_2179[4][0]) >= 4294967287UL) | p_27), 9)) | g_952[7][2])) | 0x3AB1ADF13F3F2C75LL) <= g_81[0]) & p_23), l_2699)))) <= 1L)) | 0x03F7513D964400D4LL)))))) > l_2744) , g_276) | l_2745[0]) | g_167))) || 1UL) , p_27)) > 0x1162L) < l_2745[0]) | 0x799FL) > 18446744073709551610UL) < 0L)) , l_2679[2]);
                        l_2202 = (safe_lshift_func_uint8_t_u_s((g_1405[9][3][0] ^ ((g_1613 = (+0x14BD4865626A28E2LL)) <= (g_559 , ((safe_rshift_func_int8_t_s_u((g_519 = ((((1L == (((p_26 | 0L) , ((((safe_mod_func_uint8_t_u_u(p_26, l_2679[2])) && p_24) || 1UL) , p_26)) || l_2202)) && 0x67D4ADD7L) >= 0xC6L) & 4294967295UL)), g_1121)) ^ 0x51C119C8BA4A5683LL)))), 2));
                        g_76 = (safe_mod_func_uint32_t_u_u((0x643AL != (((g_520 = (g_105[0][3][9] == (safe_mod_func_uint32_t_u_u((~(safe_lshift_func_int16_t_s_s(((((safe_sub_func_int32_t_s_s(p_26, ((~((g_269 || ((((safe_lshift_func_uint16_t_u_s((l_2200 = (g_482[3][0][1] , (1UL | p_23))), ((((safe_unary_minus_func_uint64_t_u(((g_576 && (l_2679[3] < g_1854)) > l_2719))) , g_511) , l_2742) ^ g_1121))) != 0xDBL) <= l_2531[1][0]) != l_2766)) <= l_2740)) | 7UL))) && 0x0370D8BEEF898209LL) || l_2719) != l_2719), 9))), p_25)))) > g_875) > 0L)), l_2491[5][0][0]));
                    }
                    l_2767 = (0x61L != l_2742);
                }
                if (((0x2FD58920L <= 4294967295UL) > (g_1023[1][3][3] > ((l_2483 = l_2430) < (((safe_mod_func_uint8_t_u_u(((g_1884 < l_2430) ^ (0x7CEEFDE0L & (p_26 && ((((safe_sub_func_uint16_t_u_u((l_2468 = l_2200), 0xFECAL)) < l_29[0]) >= l_2772[4][5]) & l_2197[0][0][0])))), l_2503)) | g_875) < 0xA04092CEL)))))
                {
                    uint32_t l_2773 = 0UL;
                    int32_t l_2819[3][5][2];
                    int32_t l_2848 = 0x7CFFAC30L;
                    int i, j, k;

if (g_81[g_15])
                            break;


for (i = 0; i < 3; i++)
                    {
                        for (j = 0; j < 5; j++)
                        {
                            for (k = 0; k < 2; k++)
                                l_2819[i][j][k] = 0xB1A08559L;
                        }
                    }
                    if (p_23)
                    {
                        if (l_2773)
                            break;
                        l_2202 = g_1703;
                    }
                    else
                    {
                        uint8_t l_2789 = 0x4BL;
                        uint16_t l_2800 = 9UL;
                        p_25 = (safe_rshift_func_uint16_t_u_s(((p_25 ^ (((safe_lshift_func_uint8_t_u_u(((((safe_add_func_int8_t_s_s(l_2773, (((((safe_lshift_func_uint8_t_u_s(((safe_lshift_func_int16_t_s_s(g_758[6][0], ((((safe_add_func_int64_t_s_s(p_24, (safe_mod_func_uint8_t_u_u((l_2800 = (+(0xDB56C073L < (l_2789 <= ((safe_lshift_func_uint8_t_u_u(((l_2468 = g_202) == (((safe_sub_func_uint8_t_u_u(((((((((l_2789 > (safe_lshift_func_uint16_t_u_s(((g_203 = ((safe_rshift_func_uint16_t_u_s((safe_sub_func_int16_t_s_s((1L >= p_27), p_27)), l_2773)) > p_25)) <= 0x50L), 14))) , 0x4DL) < 6UL) , l_2179[4][0]) , g_519) > l_2430) > l_2789) || p_23), g_208)) == (-10L)) , l_2772[4][5])), 3)) && 0x283C3F38L))))), 1UL)))) >= 0x17B2L) > g_1388[0]) >= g_1388[2]))) | 0x0C388A0FL), 0)) != l_2483) || p_26) & g_551) & (-8L)))) , p_23) , p_24) ^ l_2773), 6)) | 0x4FL) > l_2465)) || l_2766), p_23));
                    }
                    if (g_28[6][1])
                    {
                        uint16_t l_2815 = 1UL;
                        int32_t l_2828[7][3][9] = {{{0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}}, {{0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}}, {{0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}}, {{0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}}, {{0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}}, {{0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}}, {{0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}, {0xB660CD2BL, 0xA03C2B81L, (-4L), (-1L), 0xB660CD2BL, 4L, 0x28EBAD2AL, 4L, 0xB660CD2BL}}};
                        int i, j, k;
                        g_76 = (p_23 != (((p_27 , ((g_2151 = (safe_sub_func_int8_t_s_s(((safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s((safe_add_func_int16_t_s_s(g_483[1], 5UL)), 10)), (safe_sub_func_int16_t_s_s(0x26DAL, ((~((g_1388[2] | g_482[5][1][0]) == (safe_sub_func_int8_t_s_s(((g_483[2] , (g_28[6][1] = ((l_2745[0] == p_27) ^ 9L))) != p_25), g_1121)))) <= g_90))))) , l_2490[2]), l_2197[0][0][0]))) <= p_27)) <= 0xBBA2A9BAL) > g_1783[1][0]));
                        l_2699 = (g_579 = (+l_2815));
                        l_2483 = ((p_23 , ((safe_rshift_func_uint16_t_u_s((+((g_1729[0][2] , (((l_2819[2][0][1] = l_2180) != 0xEBC9326246BDDA40LL) == ((p_27 && p_27) , (safe_mod_func_uint64_t_u_u(((((safe_sub_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s(((((((g_1016 = l_2828[3][2][7]) ^ g_482[5][1][0]) & l_2503) & l_2679[2]) != g_28[3][5]) == 2L), l_2503)), 3)) | 65529UL), 0xDAL)) | l_2745[0]) , 4UL) , g_1405[9][3][0]), l_2829))))) || p_24)), g_559)) , p_24)) | g_2720[2]);
                    }
                    else
                    {
                        int32_t l_2830 = 0x7346D446L;
                        int32_t l_2839 = 1L;
                        l_2830 = l_2740;
                        g_105[0][4][6] = (~((p_24 , ((0L <= (((l_2197[0][0][0] , ((safe_sub_func_uint16_t_u_u(((g_269 != g_694) , (65535UL || (0x14E8DBFCL >= ((l_2180 = (safe_rshift_func_int16_t_s_s((+((((safe_add_func_uint8_t_u_u(p_24, l_2839)) || g_758[0][2]) & l_2200) > 2UL)), 14))) > g_324)))), g_482[1][0][0])) >= p_27)) , 18446744073709551615UL) , g_1388[2])) | 0x4DCE59F5L)) < l_2840));
                    }
                    p_25 = (((l_2819[2][0][1] != ((safe_lshift_func_int16_t_s_u(((((l_29[0] <= p_26) , ((safe_lshift_func_uint8_t_u_u(g_381, ((safe_sub_func_uint16_t_u_u(((g_105[0][3][4] || 0x3CD1322CL) && (((l_2848 = ((g_381 & (l_2197[0][0][0] , (((safe_unary_minus_func_int32_t_s(0xA29CC715L)) > g_324) >= 0L))) | g_1703)) && p_25) <= l_2200)), p_27)) > p_24))) <= 0xD8L)) , 0xF1922A5CAD6F74C4LL) && 0x40DEF69FDC4488E0LL), l_29[0])) <= 0xED8AL)) , l_2849[0][2][0]) | l_2850[1]);
                }
                else
                {
                    for (g_1016 = (-7); (g_1016 > 5); g_1016 = safe_add_func_int32_t_s_s(g_1016, 5))
                    {

{
                        uint64_t l_2528 = 9UL;
                        int32_t l_2544 = 0x3EA38060L;
                        l_2767 = ((((((g_482[6][2][1] = (-6L)) <= ((safe_add_func_int64_t_s_s((safe_add_func_int8_t_s_s(l_2491[1][0][0], ((((((((~(0xA3L && (safe_lshift_func_uint8_t_u_s((safe_add_func_int64_t_s_s((g_875 = l_2528), ((0UL < 4L) ^ (safe_lshift_func_uint8_t_u_s((l_2699 ^ (((g_276 & g_3551) != (-4L)) <= g_3020)), 2))))), 1)))) & l_2767) != l_2767) , g_269) >= 18446744073709551612UL) != g_324) && l_2699) | g_90))), 0x946BC4B4833C51A9LL)) >= l_2531[1][0])) || g_269) || 5UL) , 0xB0D1L) ^ 1UL);
                        l_2767 = (g_482[4][2][0] = g_579);
                        l_2200 = (l_2767 >= (safe_rshift_func_int8_t_s_u((0L ^ (((247UL & (((1L | l_2528) && ((((l_2483 = (safe_lshift_func_uint8_t_u_u((g_1730 >= ((safe_rshift_func_uint8_t_u_s(((l_2545 = ((safe_mod_func_uint32_t_u_u(((g_105[0][0][4] = 3L) >= (l_2544 = ((safe_lshift_func_int16_t_s_u(((((safe_lshift_func_int16_t_s_u((((g_1730 >= (l_2531[1][0] > g_269)) < 7L) | (-3L)), l_2200)) == g_952[0][0]) < g_1730) <= 0L), 7)) & 65535UL))), g_3106)) < g_1730)) , 0x36L), g_1730)) <= g_3106)), 0))) || g_1730) > 0L) <= 1L)) ^ l_2202)) > l_2491[4][0][0]) < 0x9106BF15L)), l_2691)));
                        l_2200 = ((((safe_unary_minus_func_uint16_t_u((g_1016 = g_276))) || ((l_3029 <= l_2200) == 0x23D2F281FE4DF34CLL)) <= ((g_208 & (safe_add_func_int32_t_s_s(((((((safe_lshift_func_int8_t_s_u(0xCAL, 4)) < ((safe_lshift_func_int8_t_s_s(g_1593, ((~g_3106) , (l_2483 = (7L != g_269))))) && g_276)) < g_105[0][3][1]) & (-2L)) || g_81[0]) == l_2528), g_3551))) <= g_3551)) != 0L);
                    }


return p_27;
                    }
                    g_579 = 0xD4E207E3L;
                }
                g_482[0][1][2] = (l_2483 = p_24);
            }
        }
    }
    if ((~65535UL))
    {
        uint64_t l_2855 = 7UL;
        int32_t l_2868 = (-4L);
        uint16_t l_2889 = 65529UL;
        int32_t l_2890 = 1L;
        p_25 = ((4294967287UL || l_2466) < ((l_2868 = (((safe_unary_minus_func_uint16_t_u(l_2855)) , ((safe_lshift_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_u(l_2855, 7)) ^ (((l_2202 = (p_26 = 0xE4EAF2CDD3E714B4LL)) < (safe_mod_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(p_23, 13)), l_2855))) , (g_1729[0][3] < (safe_mod_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u((((p_27 >= 0UL) & g_1405[9][3][0]) & l_29[0]), 1)), l_2531[1][0]))))) , 0L) ^ g_208), p_23)) <= 0xC1A8F937L)) || 0x9FL)) && g_188[0]));
        for (g_1854 = 16; (g_1854 > (-2)); g_1854 = safe_sub_func_int8_t_s_s(g_1854, 1))
        {
            uint32_t l_2886 = 0x8CEC9082L;

for (g_520 = 0; g_520 < 5; g_520 += 1)
                {
                    g_952[g_511][g_520] = 1UL;
                };



l_2890 = (safe_add_func_uint8_t_u_u(((((safe_add_func_int16_t_s_s((((l_2868 = (safe_add_func_int64_t_s_s(0xCD0C9890C0586A29LL, (!l_2868)))) || ((safe_mod_func_int16_t_s_s(((safe_mod_func_int64_t_s_s((safe_mod_func_uint8_t_u_u((((((safe_mod_func_uint32_t_u_u(((l_2886 = p_23) , ((safe_mod_func_uint16_t_u_u(((p_25 != (p_27 > (g_2720[1] , (p_27 & l_2889)))) ^ (g_2720[2] , l_2849[0][2][0])), g_152[1][0][5])) == p_25)), p_24)) < g_2718) , 0xBAF1258DL) == g_81[0]) < p_27), p_26)), l_2767)) && l_2200), p_23)) == 0xDDL)) <= l_2849[0][2][0]), 0xCF7FL)) ^ g_188[0]) || g_1388[2]) | 3UL), 0x9EL));
        }
    }
    else
    {
        int64_t l_2899 = 0L;
        int32_t l_2911 = 0x34F043A5L;
        int32_t l_2923 = 0x54CDD866L;
        int32_t l_2940 = 0xE393A55AL;
        uint32_t l_2965 = 0x186B27C4L;
        int32_t l_3011[10][1][3] = {{{(-6L), 0x73076FECL, 0xD86BD461L}}, {{(-6L), 0x73076FECL, 0xD86BD461L}}, {{(-6L), 0x73076FECL, 0xD86BD461L}}, {{(-6L), 0x73076FECL, 0xD86BD461L}}, {{(-6L), 0x73076FECL, 0xD86BD461L}}, {{(-6L), 0x73076FECL, 0xD86BD461L}}, {{(-6L), 0x73076FECL, 0xD86BD461L}}, {{(-6L), 0x73076FECL, 0xD86BD461L}}, {{(-6L), 0x73076FECL, 0xD86BD461L}}, {{(-6L), 0x73076FECL, 0xD86BD461L}}};
        uint64_t l_3066[6];
        int32_t l_3154 = 0L;
        uint16_t l_3155 = 0xE0BAL;
        uint32_t l_3177 = 0xF4D522BCL;
        int16_t l_3198[1];
        int i, j, k;
        for (i = 0; i < 6; i++)
            l_3066[i] = 1UL;
        for (i = 0; i < 1; i++)
            l_3198[i] = 0x3F8FL;
        p_25 = ((((((g_1783[5][0] == (safe_sub_func_uint32_t_u_u((l_2466 > 0L), l_2180))) < (((((((safe_rshift_func_uint8_t_u_u((((((safe_lshift_func_uint16_t_u_u((((safe_sub_func_int8_t_s_s(l_2849[0][2][0], p_24)) | (((((-3L) <= 0x70L) | ((0xC9F9L < p_27) || 0UL)) , g_1729[0][3]) != 0x98DC747174CAEB8ALL)) >= p_24), g_483[1])) == 1L) >= 0x820CEA30L) && p_26) > g_2720[1]), p_23)) || 0x3069D1405192C4A5LL) | p_25) && g_276) , 1UL) && l_2899) | g_188[0])) <= p_23) < l_2899) >= 0L) >= g_1388[2]);
        if ((g_1729[0][0] != ((((safe_mod_func_int32_t_s_s((((safe_lshift_func_int16_t_s_u(l_2899, p_27)) == (safe_rshift_func_uint8_t_u_s((safe_unary_minus_func_int16_t_s((((safe_rshift_func_int8_t_s_u((safe_mod_func_uint32_t_u_u((l_2911 = p_24), (safe_sub_func_int32_t_s_s(0x1A0A5BA7L, (l_2202 = g_381))))), (l_2923 = (+(l_29[0] != ((safe_add_func_int16_t_s_s(g_152[2][0][0], (safe_rshift_func_uint8_t_u_u(((safe_rshift_func_uint8_t_u_u((safe_sub_func_int8_t_s_s(p_23, l_2531[1][0])), 0)) , 0xA7L), g_188[0])))) < l_2850[1])))))) < p_25) | p_24))), l_2899))) >= l_29[0]), 0x014C4CC2L)) | g_694) || p_24) , g_1405[9][3][0])))
        {
            int8_t l_2946[7];
            int32_t l_2989[7][8][4] = {{{0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}}, {{0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}}, {{0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}}, {{0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}}, {{0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}}, {{0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}}, {{0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}, {0xF650D527L, 6L, (-4L), 0x1FE78B6BL}}};
            uint64_t l_3021 = 0x2A5CB463609E747BLL;
            int32_t l_3087[4];
            uint32_t l_3113 = 0xC1ED8786L;
            uint32_t l_3121[1];
            int i, j, k;
            for (i = 0; i < 7; i++)
                l_2946[i] = 0xC3L;
            for (i = 0; i < 4; i++)
                l_3087[i] = 0L;

{
        for (l_2767 = 0; l_2767 < 9; l_2767++)
        {
            transparent_crc(g_28[l_2180][l_2767], "g_28[l_2180][l_2767]", g_1121);
            if (g_1121) printf("index = [%d][%d]\n", l_2180, l_2767);

        }
    }


for (i = 0; i < 1; i++)
                l_3121[i] = 0xD66C1488L;
            if (g_28[6][1])
            {
                int32_t l_2924 = 0xAA8DCA40L;
                if (l_2924)
                {
                    uint16_t l_2931 = 0UL;
                    uint8_t l_2947 = 0x9BL;
                    g_76 = (0xD468399CL & (safe_lshift_func_int8_t_s_u((l_2692 = (g_151 = (safe_mod_func_int16_t_s_s((safe_lshift_func_int16_t_s_u((((((l_2931 & ((safe_mod_func_int8_t_s_s(0x89L, ((g_1016 = ((l_2924 && (safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u(0xC57CL, p_23)), l_29[0]))) != g_208)) && (!((g_81[0] = ((g_2939 = 4294967289UL) < g_758[0][2])) > g_695))))) , p_23)) > p_27) != 9UL) , 0x280188A7L) , p_24), l_2940)), l_2200)))), 5)));
                    l_2947 = (g_1388[2] , (((g_151 = 0xB3L) | ((safe_unary_minus_func_uint64_t_u((safe_mod_func_uint32_t_u_u((safe_add_func_uint64_t_u_u((l_2911 && ((((0x123D7D083F39965DLL == ((l_2911 <= 0x8D7BL) < (p_24 = l_2946[2]))) >= (((g_758[9][4] && l_2924) && p_27) < p_26)) , l_2911) != l_2899)), p_27)), 0xBD36B61EL)))) <= l_2924)) != 0x09L));
                }
                else
                {
                    int16_t l_2966 = 0x7037L;
                    uint8_t l_2988[8];
                    int i;
                    for (i = 0; i < 8; i++)
                        l_2988[i] = 0xD7L;

if (g_695) printf("index = [%d]\n", l_2180);


l_2200 = ((safe_lshift_func_uint8_t_u_u(g_1405[9][3][0], (((((safe_sub_func_int32_t_s_s((l_2940 = (safe_add_func_int16_t_s_s((safe_sub_func_int32_t_s_s(((safe_add_func_uint32_t_u_u((0L < (l_2989[0][1][2] = (~(safe_mod_func_uint32_t_u_u((p_24 = ((safe_add_func_uint32_t_u_u((p_26 > (g_1854 >= ((((l_2966 = (safe_lshift_func_int8_t_s_u(9L, l_2965))) > (((safe_rshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((p_25 = ((safe_mod_func_int16_t_s_s(((safe_add_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_s((g_81[0] = (safe_lshift_func_int16_t_s_s((safe_sub_func_int64_t_s_s((((safe_rshift_func_int16_t_s_s((safe_mod_func_int16_t_s_s(0x2EB4L, (((0x34L & ((!((((((safe_rshift_func_uint16_t_u_u(65529UL, l_2531[1][0])) <= 0UL) <= p_27) < p_27) , l_2545) == p_23)) != p_25)) == g_559) , 0xDB5DL))), l_2988[0])) >= 0UL) , p_27), g_2939)), g_28[0][8]))), 7)), 1UL)) > 0x8764L), 9UL)) | l_2988[4])), 0x77FB0852L)), 12)) >= g_167) | 0xC7F1L)) & g_1730) < 1UL))), 0xBCF825A5L)) >= l_2200)), p_27))))), g_694)) == p_23), g_163)), (-5L)))), l_2988[0])) & l_2990[2]) , g_124) == g_167) <= 0xD4135D0B07067DF3LL))) == 18446744073709551607UL);
                    g_76 = (-1L);
                    for (l_2899 = 0; (l_2899 == (-14)); --l_2899)
                    {
                        int64_t l_2993 = 0xD2613B3005CFBDE1LL;
                        g_1775 = (l_2993 = (g_482[5][2][0] = 0x5815CEF5L));
                        p_25 = (safe_add_func_uint16_t_u_u((l_2899 <= ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s((l_2924 = ((safe_sub_func_int16_t_s_s(g_152[1][0][5], (safe_sub_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(((g_167 = (((~(safe_rshift_func_uint16_t_u_s(((safe_lshift_func_uint8_t_u_u(((((l_3011[8][0][2] >= (+(safe_rshift_func_int8_t_s_u((l_2200 = (g_758[0][2] , p_23)), 7)))) , (safe_rshift_func_uint16_t_u_u(7UL, 8))) ^ (~g_81[0])) ^ 0x91L), (safe_mod_func_int32_t_s_s(g_3020, l_2989[0][1][2])))) == l_3021), l_2988[4]))) , p_26) >= p_27)) , l_2924), g_483[2])), g_3022)))) > l_2993)), 7)), l_2850[1])) ^ 0L)), 9L));
                        if (l_2989[0][1][2])
                            break;
                        p_25 = g_167;
                    }
                    g_1775 = p_24;
                }
            }
            else
            {
                g_579 = 1L;
            }
            g_105[0][3][1] = (safe_lshift_func_int8_t_s_u((safe_lshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s((l_3029 | g_91), l_2923)), 1)), 0));
            if ((g_579 = (((safe_mod_func_int16_t_s_s((~255UL), (l_2989[0][1][2] = 0xBE3BL))) < ((0xE096BAAEF25888DALL != (((safe_lshift_func_int8_t_s_u((+((safe_rshift_func_int8_t_s_u(0xCAL, 0)) && (-1L))), ((+((((safe_lshift_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s(((safe_add_func_uint16_t_u_u(((l_2965 , (((((((-2L) && ((((safe_mod_func_int32_t_s_s(g_465, ((((g_559 = (safe_mod_func_int64_t_s_s((g_2151 > g_576), g_1613))) && p_26) , 0x6E3EFCD1L) && (-9L)))) & g_324) , l_2946[4]) & 0xEFL)) || 1L) , l_3011[2][0][2]) && 0UL) , l_2946[2]) <= g_3020)) && p_23), p_26)) , 0x9E26L), g_875)), 6)) || p_24) & 4294967288UL) , 18446744073709551611UL)) && g_1507))) > p_23) <= g_423)) , 1UL)) , l_2531[1][0])))
            {
                uint64_t l_3051 = 0xCE807D02AF47F2ABLL;
                int32_t l_3070 = 0xC50531CEL;
                if ((safe_lshift_func_uint16_t_u_s(p_25, g_324)))
                {
                    uint32_t l_3069 = 0x7527C55EL;
                    if ((0L == p_25))
                    {
                        l_3051 = l_3021;
                    }
                    else
                    {
                        l_2923 = (((l_2989[3][7][1] = (safe_lshift_func_int16_t_s_s(((l_3070 = ((l_3051 | (safe_sub_func_uint64_t_u_u((safe_add_func_int16_t_s_s((~(safe_sub_func_uint32_t_u_u((safe_lshift_func_int8_t_s_u(((p_23 | (l_2767 && ((l_3011[8][0][2] && g_81[0]) >= ((g_579 = g_76) >= ((!4UL) , (p_24 = (l_2202 = (safe_mod_func_int8_t_s_s(l_3066[1], (+(!l_3069))))))))))) & 0x8059DF9F40F00F43LL), l_2899)), l_2692))), l_3069)), g_952[4][2]))) , 4294967287UL)) > 0x04C3FD46L), 4))) , g_324) , 0x029D06EEL);
                    }
                    for (g_1820 = (-20); (g_1820 <= (-13)); g_1820 = safe_add_func_uint16_t_u_u(g_1820, 8))
                    {
                        p_25 = p_26;
                        g_76 = ((((safe_lshift_func_int8_t_s_u((g_269 != (g_1854 = (safe_sub_func_uint64_t_u_u(p_24, (safe_sub_func_int8_t_s_s(((safe_rshift_func_uint8_t_u_s((((l_2989[0][1][2] = ((p_27 , p_24) && (safe_mod_func_uint8_t_u_u(g_269, (g_1507 , l_3011[8][0][2]))))) == ((safe_sub_func_uint32_t_u_u(((safe_sub_func_uint8_t_u_u((l_3087[0] = (g_81[0] = l_3011[8][0][2])), (safe_add_func_int8_t_s_s(g_151, 0xE3L)))) && p_24), g_203)) || p_23)) > g_93), l_3069)) & p_27), p_27)))))), 1)) ^ g_276) , l_3069) , 0xADE44BFCL);
                    }
                    return g_1729[0][3];
                }
                else
                {
                    uint32_t l_3104 = 4294967288UL;
                    for (g_208 = 0; (g_208 != 25); ++g_208)
                    {
                        int8_t l_3105 = 0x20L;
                        g_76 = p_24;
                        if (p_25)
                            continue;
                        p_25 = (((safe_lshift_func_int16_t_s_s(((g_3106 = (1UL || (safe_sub_func_int32_t_s_s((safe_sub_func_int64_t_s_s(1L, ((((l_3066[4] <= 0xA7452DE7L) && ((((safe_rshift_func_int8_t_s_u(((g_2151 = ((safe_lshift_func_int16_t_s_u(((g_1593 = (safe_rshift_func_uint16_t_u_u(65528UL, ((p_25 || p_27) , l_3104)))) != 0x7E6BL), g_519)) | 1UL)) <= g_276), l_2989[0][1][2])) < 2L) & 0x69L) < g_2720[2])) != p_24) == g_695))), l_3105)))) & l_3070), g_105[0][8][2])) == g_3020) < l_2692);
                        g_482[1][2][1] = l_2899;
                    }
                }
            }
            else
            {
                int32_t l_3123[6][9] = {{2L, 8L, 1L, 1L, 8L, 2L, 8L, 1L, 1L}, {2L, 8L, 1L, 1L, 8L, 2L, 8L, 1L, 1L}, {2L, 8L, 1L, 1L, 8L, 2L, 8L, 1L, 1L}, {2L, 8L, 1L, 1L, 8L, 2L, 8L, 1L, 1L}, {2L, 8L, 1L, 1L, 8L, 2L, 8L, 1L, 1L}, {2L, 8L, 1L, 1L, 8L, 2L, 8L, 1L, 1L}};
                int i, j;
                for (g_269 = 0; (g_269 >= 41); ++g_269)
                {
                    g_76 = (p_25 , 1L);
                    g_482[5][1][0] = p_27;
                }
                for (g_167 = 0; (g_167 <= 3); g_167 += 1)
                {
                    int i;

l_3029 += 1;



l_3087[g_167] = p_27;
                    for (g_1730 = 1; (g_1730 <= 4); g_1730 += 1)
                    {
                        int64_t l_3122 = 0L;
                        int i;
                        p_25 = (l_3087[g_167] = g_3106);
                        g_105[0][6][5] = (!((safe_mod_func_int8_t_s_s((((!(g_559 , ((((l_2989[0][1][2] >= 0x6EAA696DL) && (((l_3113 <= (((safe_rshift_func_int16_t_s_u((safe_rshift_func_int8_t_s_s((l_2200 && (g_203 | g_188[0])), ((safe_lshift_func_uint8_t_u_s((((!(((p_24 != ((l_3121[0] <= l_3122) | l_2946[1])) , 0x4FL) > g_1613)) && p_27) != 18446744073709551615UL), 5)) >= 0xD709L))), l_3087[g_167])) | l_3123[2][4]) >= g_694)) > l_3122) ^ p_24)) >= l_3021) & 0x31F5AF7DCC59E95FLL))) | l_3122) <= p_25), 7L)) <= 0xBB0E0BC994D0B758LL));
                    }
                }
            }
        }
        else
        {
            for (p_27 = 0; (p_27 <= (-14)); p_27 = safe_sub_func_uint8_t_u_u(p_27, 7))
            {
                return g_381;
            }
            l_2940 = (safe_lshift_func_uint16_t_u_u(g_694, 14));
        }
        p_25 = (g_1775 = (((((safe_rshift_func_uint8_t_u_s((p_24 == (((safe_mod_func_uint16_t_u_u(((safe_add_func_uint64_t_u_u((safe_sub_func_int8_t_s_s((((((+(safe_unary_minus_func_uint32_t_u(g_3020))) , (((((safe_lshift_func_uint8_t_u_u(0xFDL, (p_25 , 246UL))) >= l_2531[1][0]) <= (((safe_lshift_func_uint8_t_u_s((safe_add_func_int32_t_s_s((((((safe_add_func_uint64_t_u_u((l_2180 = (safe_rshift_func_uint16_t_u_u(p_24, ((safe_add_func_int64_t_s_s((0xE20DL && (((safe_unary_minus_func_int32_t_s((((!((((safe_sub_func_int32_t_s_s(((((g_576 = (p_26 = l_29[0])) >= g_579) > l_2531[1][0]) == l_2990[1]), 0x1FEA2120L)) <= p_27) , l_2965) > 0x323101D57BBE8912LL)) , p_25) | (-1L)))) , l_2180) <= 1L)), 0xBF52172798D1CFFCLL)) == g_521)))), p_27)) != l_2965) != 1L) == g_105[0][3][1]) != l_2531[0][1]), l_3154)), 2)) | l_3155) , l_2899)) != g_163) && 0x1D291BDBE3467350LL)) || p_23) , l_3066[1]) , 0L), p_27)), g_151)) && p_26), p_27)) && 4294967292UL) < 65529UL)), 7)) <= p_25) <= 255UL) , p_25) , g_152[0][0][4]));
        for (l_2940 = 0; (l_2940 >= 18); l_2940 = safe_add_func_int16_t_s_s(l_2940, 8))
        {
            uint32_t l_3158 = 0xE6078B7CL;
            int32_t l_3178 = 0L;
            int64_t l_3204 = (-7L);
            g_482[5][1][0] = ((l_3158 | (((l_3178 = (safe_sub_func_int64_t_s_s((safe_rshift_func_uint8_t_u_u(((((((safe_sub_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u(0x93L, l_3154)), (p_24 && p_23))) || (safe_lshift_func_int16_t_s_u((((safe_mod_func_uint16_t_u_u((safe_add_func_int16_t_s_s(g_694, (safe_mod_func_uint32_t_u_u(l_3154, l_2200)))), (safe_mod_func_int32_t_s_s((p_27 ^ 1UL), p_27)))) < (-1L)) | 0UL), 12))) , p_27) != p_24) || p_27) ^ l_2202), g_324)), l_3177))) && l_3178) , g_694)) != 0xD26581A0L);
            p_25 = ((safe_rshift_func_uint8_t_u_s(((g_579 = ((safe_sub_func_uint32_t_u_u((g_3022 = g_276), (safe_rshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_s(((((((safe_sub_func_int64_t_s_s((g_576 > (safe_add_func_int8_t_s_s(((0UL != ((g_559 = (safe_lshift_func_uint8_t_u_s((l_2180 , 0x46L), (safe_mod_func_uint8_t_u_u(((l_3198[0] = (~g_1775)) == (g_1507 ^ ((safe_mod_func_uint32_t_u_u(p_24, ((l_3178 = ((safe_add_func_int64_t_s_s((safe_unary_minus_func_uint8_t_u((p_25 <= 251UL))), p_24)) , g_2151)) ^ p_25))) || p_27))), (-3L)))))) || l_3204)) != p_27), g_105[0][3][1]))), p_24)) || 0x4751B99CL) || p_23) < 0xB4L) || l_2940) , g_520), 5)) & l_3011[2][0][2]), 4)), 2)))) ^ 0L)) && 0xA5C3DF04L), 3)) != p_26);
        }
    }
    return p_24;
}







static int32_t func_32(int32_t p_33, uint8_t p_34, uint32_t p_35, int32_t p_36)
{
    uint16_t l_2123[7][4] = {{2UL, 0xC7BEL, 0x4742L, 0xF2F2L}, {2UL, 0xC7BEL, 0x4742L, 0xF2F2L}, {2UL, 0xC7BEL, 0x4742L, 0xF2F2L}, {2UL, 0xC7BEL, 0x4742L, 0xF2F2L}, {2UL, 0xC7BEL, 0x4742L, 0xF2F2L}, {2UL, 0xC7BEL, 0x4742L, 0xF2F2L}, {2UL, 0xC7BEL, 0x4742L, 0xF2F2L}};
    int32_t l_2124 = (-2L);
    int32_t l_2160 = (-7L);
    int i, j;
                      if (( g_579 < -8) )
{

{
            transparent_crc(g_28[g_1775][g_93], "g_28[g_1775][g_93]", g_694);
            if (g_694) printf("index = [%d][%d]\n", g_1775, g_93);

        }

}

p_36 = p_36;
    for (g_151 = 0; (g_151 != (-8)); g_151 = safe_sub_func_uint16_t_u_u(g_151, 2))
    {
        int8_t l_2125 = 0xBEL;
        p_36 = ((safe_sub_func_int16_t_s_s((g_1016 | (safe_add_func_int8_t_s_s(((g_1730 = (p_33 < g_521)) != (l_2124 = (((((g_758[0][2] > 0x9CDD1424802716C9LL) , (safe_lshift_func_int16_t_s_s(0xF35AL, p_34))) , (l_2123[3][2] | 0x9C84125F2A8981A3LL)) > 6UL) != g_202))), l_2125))), l_2123[3][2])) , l_2123[3][2]);
        for (g_163 = 0; (g_163 < 51); ++g_163)
        {
            uint32_t l_2137 = 18446744073709551615UL;
            uint64_t l_2150[9];
            int i;
            for (i = 0; i < 9; i++)
                l_2150[i] = 0x9EE7F9D1C772505BLL;
            g_1775 = ((safe_rshift_func_uint16_t_u_s(((g_324 >= (safe_mod_func_int32_t_s_s((safe_mod_func_uint64_t_u_u(0x819D62416B30E980LL, (safe_sub_func_int8_t_s_s((safe_unary_minus_func_int64_t_s(p_34)), (l_2137 ^ p_34))))), ((((g_152[1][0][5] = (l_2124 = (safe_add_func_uint64_t_u_u((safe_rshift_func_int8_t_s_s((safe_mod_func_uint64_t_u_u((g_1729[0][3] = (safe_add_func_int16_t_s_s(((safe_rshift_func_int16_t_s_u(((l_2124 != (((safe_mod_func_int32_t_s_s((l_2150[0] && (g_1783[5][0] > (-10L))), p_34)) > g_483[1]) < 0UL)) | p_36), p_36)) && 4L), l_2124))), g_2151)), l_2123[3][3])), l_2150[0])))) , p_36) | l_2137) , 0xD1403C4BL)))) , l_2137), 1)) != g_520);
        }
    }
    l_2160 = (safe_add_func_int64_t_s_s((p_36 < (l_2124 = (p_33 && (safe_lshift_func_uint8_t_u_u(0x28L, 3))))), (((safe_sub_func_uint16_t_u_u(p_33, (safe_add_func_int64_t_s_s(l_2123[3][2], g_1783[5][0])))) > ((((((g_188[0] , g_1613) , g_423) , p_33) && p_36) | p_36) & l_2123[2][0])) && g_1783[5][0])));
    return l_2123[3][2];
}







static uint8_t func_37(uint8_t p_38, uint32_t p_39, uint32_t p_40, int32_t p_41, int8_t p_42)
{
    uint8_t l_2073[4] = {4UL, 0xDFL, 4UL, 0xDFL};
    int8_t l_2074 = 1L;
    uint32_t l_2092 = 1UL;
    uint32_t l_2093 = 0UL;
    int32_t l_2094[3];
    int32_t l_2095 = (-1L);
    int i;
    for (i = 0; i < 3; i++)
        l_2094[i] = (-8L);
    l_2074 = ((safe_lshift_func_uint8_t_u_u((l_2073[1] = (g_551 ^ g_93)), 6)) , (g_276 <= g_81[0]));
    l_2095 = ((g_381 = (((!((g_483[1] | (((safe_rshift_func_uint8_t_u_u(l_2073[1], 3)) <= (g_1970 = (((((+(((l_2094[2] = (~((p_40 <= (g_276 = (((safe_lshift_func_int8_t_s_u((((g_1613 = l_2073[0]) & ((7L | (0xEBB5B307BA6D4CF6LL & (safe_mod_func_uint32_t_u_u(((((safe_rshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u((safe_rshift_func_int8_t_s_u((((safe_add_func_int16_t_s_s((g_1593 = ((((((p_38 = l_2092) , (l_2074 || (4UL == g_521))) || (-1L)) ^ p_42) <= l_2073[0]) <= g_76)), g_167)) , l_2092) <= 1L), 1)), l_2074)), 3)) || 0L) == g_105[0][3][1]) , l_2093), 0x68BF614DL)))) , l_2093)) | 1L), l_2074)) ^ l_2074) != g_81[0]))) < l_2092))) == 4UL) , g_124)) && 0xDE7F2A58D417EC0ELL) == 0x99L) && l_2092) , (-1L)))) < g_551)) != 7L)) && l_2074) & p_42)) && g_521);
    for (g_203 = 0; (g_203 != 43); ++g_203)
    {
        int16_t l_2098 = 0xD407L;
        int32_t l_2112 = 3L;
        if (p_39)
        {
            uint32_t l_2101[3];
            int i;
            for (i = 0; i < 3; i++)
                l_2101[i] = 4294967288UL;
            l_2101[0] = (l_2098 && (safe_rshift_func_uint16_t_u_s(0UL, 12)));
        }
        else
        {
            uint32_t l_2106 = 4294967291UL;
            int32_t l_2113[5][9] = {{0L, 0x74499E55L, 0x51C0958EL, 0x74499E55L, 0L, 0x2DB6A292L, 0L, 0x74499E55L, 0x51C0958EL}, {0L, 0x74499E55L, 0x51C0958EL, 0x74499E55L, 0L, 0x2DB6A292L, 0L, 0x74499E55L, 0x51C0958EL}, {0L, 0x74499E55L, 0x51C0958EL, 0x74499E55L, 0L, 0x2DB6A292L, 0L, 0x74499E55L, 0x51C0958EL}, {0L, 0x74499E55L, 0x51C0958EL, 0x74499E55L, 0L, 0x2DB6A292L, 0L, 0x74499E55L, 0x51C0958EL}, {0L, 0x74499E55L, 0x51C0958EL, 0x74499E55L, 0L, 0x2DB6A292L, 0L, 0x74499E55L, 0x51C0958EL}};
            int32_t l_2114 = 0x92A4DB93L;
            int i, j;

for (l_2114 = 0; l_2114 < 7; l_2114++)
    {
        for (l_2114 = 0; l_2114 < 1; l_2114++)
        {
            transparent_crc(g_1783[l_2114][l_2114], "g_1783[l_2114][l_2114]", g_202);
            if (g_202) printf("index = [%d][%d]\n", l_2114, l_2114);

        }
    };



g_76 = g_423;
            for (g_511 = 0; g_511 < 8; g_511 += 1)
            {
                for (l_2074 = 0; l_2074 < 5; l_2074 += 1)
                {
                    g_952[g_511][l_2074] = 1UL;
                }
            }
            l_2114 = (!((((18446744073709551606UL != (l_2094[0] = (safe_sub_func_int32_t_s_s((l_2113[3][7] = ((0xC534L != (((p_38 = (safe_unary_minus_func_int32_t_s(((g_465 = l_2106) , ((safe_mod_func_int16_t_s_s((p_39 > ((safe_unary_minus_func_uint8_t_u((g_203 & (safe_sub_func_uint32_t_u_u((p_40 = (((l_2098 ^ g_188[0]) == ((g_482[5][1][0] , (p_41 && 0x59CBA05F959F00DDLL)) && p_40)) < g_1820)), p_42))))) > l_2112)), l_2095)) < p_41))))) != p_41) != l_2106)) != 249UL)), g_76)))) , g_163) , p_39) ^ g_952[4][2]));
            l_2113[3][7] = (-1L);
        }
        return p_41;
    }
    return g_483[0];
}







static uint8_t func_46(uint8_t p_47, uint8_t p_48, int64_t p_49, uint8_t p_50)
{
    uint64_t l_1361[4][8] = {{0UL, 0x05536A6F0B75E808LL, 1UL, 18446744073709551611UL, 18446744073709551609UL, 18446744073709551611UL, 1UL, 0x05536A6F0B75E808LL}, {0UL, 0x05536A6F0B75E808LL, 1UL, 18446744073709551611UL, 18446744073709551609UL, 18446744073709551611UL, 1UL, 0x05536A6F0B75E808LL}, {0UL, 0x05536A6F0B75E808LL, 1UL, 18446744073709551611UL, 18446744073709551609UL, 18446744073709551611UL, 1UL, 0x05536A6F0B75E808LL}, {0UL, 0x05536A6F0B75E808LL, 1UL, 18446744073709551611UL, 18446744073709551609UL, 18446744073709551611UL, 1UL, 0x05536A6F0B75E808LL}};
    int32_t l_1364 = 0xA9810F33L;
    uint64_t l_1367 = 0x540E42D561897AF8LL;
    int32_t l_1385 = 1L;
    int64_t l_1387 = 0x0A77078943322C5DLL;
    int32_t l_1420 = (-1L);
    int8_t l_1515 = 0x61L;
    uint32_t l_1534 = 18446744073709551608UL;
    int8_t l_1731[10][8][3] = {{{0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}}, {{0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}}, {{0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}}, {{0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}}, {{0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}}, {{0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}}, {{0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}}, {{0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}}, {{0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}}, {{0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}, {0x57L, 7L, 4L}}};
    uint32_t l_1800 = 0x75962E1AL;
    int i, j, k;
    if ((safe_sub_func_int32_t_s_s(((safe_lshift_func_int8_t_s_s((-1L), (safe_add_func_int32_t_s_s((g_90 < (0L > 6L)), (safe_lshift_func_int8_t_s_u((((0x3C27L <= 1UL) > (l_1364 = ((p_47 ^ l_1361[0][3]) || (safe_mod_func_uint32_t_u_u(g_747, 0x02EB61D9L))))) <= p_49), g_1121)))))) | 0L), p_50)))
    {
        uint16_t l_1384 = 0x3197L;
        int32_t l_1386 = (-3L);
        g_482[5][1][0] = (((((safe_rshift_func_uint16_t_u_s(((((l_1367 = 1L) != (g_1023[1][4][5] , (safe_mod_func_int16_t_s_s(((g_1388[2] = ((safe_lshift_func_int16_t_s_u(((safe_add_func_uint16_t_u_u(((safe_mod_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(255UL, p_47)) , ((((l_1385 = (4294967295UL || ((((safe_rshift_func_uint8_t_u_s((+(safe_lshift_func_int16_t_s_u(((p_47 == (g_202 && p_47)) , (l_1364 = (l_1384 = (((~((g_423 = (g_423 && 3L)) && p_50)) > 0L) < p_49)))), 2))), g_152[1][0][5])) || g_482[4][0][3]) >= l_1361[3][4]) < 18446744073709551615UL))) < g_76) | g_93) | l_1386)), l_1361[0][3])) != 65528UL), p_50)) & l_1387), 13)) && l_1386)) < g_91), l_1361[1][1])))) || g_952[4][2]) ^ g_483[1]), g_151)) , l_1385) & l_1386) ^ g_1121) | p_50);
    }
    else
    {
        uint32_t l_1398 = 0x46414C80L;
        int32_t l_1406[8];
        int32_t l_1407 = 0x155818F1L;
        int32_t l_1481 = 0x20B23D41L;
        uint32_t l_1615[6][1] = {{4294967295UL}, {4294967295UL}, {4294967295UL}, {4294967295UL}, {4294967295UL}, {4294967295UL}};
        int32_t l_1751[10][5][3] = {{{0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}}, {{0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}}, {{0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}}, {{0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}}, {{0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}}, {{0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}}, {{0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}}, {{0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}}, {{0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}}, {{0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}, {0x30A49A7DL, (-1L), 1L}}};
        uint8_t l_1957[3][3][4] = {{{0xD6L, 0x2DL, 0xC5L, 0xC5L}, {0xD6L, 0x2DL, 0xC5L, 0xC5L}, {0xD6L, 0x2DL, 0xC5L, 0xC5L}}, {{0xD6L, 0x2DL, 0xC5L, 0xC5L}, {0xD6L, 0x2DL, 0xC5L, 0xC5L}, {0xD6L, 0x2DL, 0xC5L, 0xC5L}}, {{0xD6L, 0x2DL, 0xC5L, 0xC5L}, {0xD6L, 0x2DL, 0xC5L, 0xC5L}, {0xD6L, 0x2DL, 0xC5L, 0xC5L}}};
        uint64_t l_2035[9] = {0xE821D301D0F535BALL, 0x4DBAFD754AEF4869LL, 0xE821D301D0F535BALL, 0x4DBAFD754AEF4869LL, 0xE821D301D0F535BALL, 0x4DBAFD754AEF4869LL, 0xE821D301D0F535BALL, 0x4DBAFD754AEF4869LL, 0xE821D301D0F535BALL};
        int i, j, k;
        for (i = 0; i < 8; i++)
            l_1406[i] = 0xD0E98A00L;
        g_579 = (0xEBCEE90A93CDF156LL ^ ((l_1364 = (((safe_lshift_func_int16_t_s_s(((+((((1L > p_49) , ((p_50 = p_50) >= ((1UL > (safe_lshift_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_s(((0x2036AFB2L | p_47) == (p_49 && (7L >= l_1385))), p_48)) , 0xA76DL), 8))) , p_47))) , l_1361[0][3]) <= 0x2F0261D1L)) > p_47), 2)) > g_188[0]) > (-1L))) != p_48));
        l_1407 = (safe_sub_func_int32_t_s_s((l_1398 == (safe_rshift_func_uint8_t_u_s((safe_sub_func_int64_t_s_s((safe_lshift_func_int16_t_s_s((((g_482[5][1][0] = ((((p_47 <= (g_381 = g_559)) , p_48) & g_952[4][2]) <= (9UL < (l_1367 ^ ((l_1398 == ((g_875 = p_50) ^ g_1388[2])) >= g_1405[9][3][0]))))) ^ (-1L)) < 0UL), 5)), l_1406[3])), 4))), 4L));
        if ((safe_mod_func_uint32_t_u_u((l_1361[0][3] <= (g_483[1] ^ (g_152[1][0][5] & (safe_add_func_int8_t_s_s(((((safe_rshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u(((l_1364 = (((((safe_rshift_func_uint8_t_u_u(252UL, g_551)) | (l_1407 = 1UL)) , (safe_add_func_uint8_t_u_u(((l_1398 && l_1420) && ((l_1407 = (((safe_lshift_func_uint8_t_u_u(((8L && 6UL) , 0x03L), p_48)) && 0xFDL) | l_1364)) || p_48)), l_1364))) && g_269) != p_47)) , 0xE7L), 3)), p_49)) >= g_952[4][3]) ^ p_49) > p_50), g_151))))), g_124)))
        {
            uint32_t l_1431 = 0UL;
            uint8_t l_1432[10] = {253UL, 0xDEL, 253UL, 0xDEL, 253UL, 0xDEL, 253UL, 0xDEL, 253UL, 0xDEL};
            int8_t l_1616 = 0x17L;
            int32_t l_1662 = 1L;
            int16_t l_1673 = 0x11D6L;
            int64_t l_1682 = 0xEF9EFA40340F37D1LL;
            int32_t l_1750 = 0x2D157FB0L;
            int64_t l_1815 = 1L;
            uint32_t l_1855[9];
            uint8_t l_1876 = 0UL;
            uint64_t l_1910 = 1UL;
            int32_t l_1925 = 0x01E3B566L;
            int i;
            for (i = 0; i < 9; i++)
                l_1855[i] = 6UL;
            for (g_90 = 0; (g_90 != 53); g_90 = safe_add_func_int64_t_s_s(g_90, 4))
            {
                int16_t l_1435 = (-5L);
                int32_t l_1442 = 0x33EC51ABL;
                int32_t l_1450 = 0x33FA4F60L;
                uint64_t l_1520 = 0x3833010C1D61304CLL;
                uint8_t l_1554 = 0xE0L;
                int16_t l_1565[5][7][2] = {{{5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}}, {{5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}}, {{5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}}, {{5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}}, {{5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}, {5L, 0x7EE0L}}};
                int16_t l_1574[7] = {0x82F8L, 1L, 0x82F8L, 1L, 0x82F8L, 1L, 0x82F8L};
                int16_t l_1635 = 1L;
                int i, j, k;
                l_1364 = l_1398;
                if ((safe_mod_func_int32_t_s_s(((((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_s((((l_1431 = p_47) , (l_1432[4] , ((g_519 = (safe_mod_func_int64_t_s_s((p_47 && l_1435), (safe_lshift_func_uint8_t_u_u(5UL, 2))))) ^ (0x88BD42E1L | (l_1406[1] | ((((safe_add_func_uint32_t_u_u((((safe_add_func_uint16_t_u_u(0xB6A0L, (g_521 = (l_1442 = p_50)))) && 0x81A2L) && g_1121), 0xC41F4966L)) != g_152[2][0][5]) && g_465) <= 0x5F31C714L)))))) , l_1432[4]), 9)), p_49)) >= 0x24L) || l_1361[0][3]) < g_952[4][4]), 0x9FE4289FL)))
                {
                    int64_t l_1449 = 1L;
                    int32_t l_1455[6] = {0xECDF7FFBL, 0x710EAE92L, 0xECDF7FFBL, 0x710EAE92L, 0xECDF7FFBL, 0x710EAE92L};
                    uint64_t l_1469 = 0xAFF3A9F38B28C283LL;
                    int32_t l_1490[4][7] = {{0L, 0x8DB94951L, 0L, 0x8DB94951L, 0L, 0x8DB94951L, 0L}, {0L, 0x8DB94951L, 0L, 0x8DB94951L, 0L, 0x8DB94951L, 0L}, {0L, 0x8DB94951L, 0L, 0x8DB94951L, 0L, 0x8DB94951L, 0L}, {0L, 0x8DB94951L, 0L, 0x8DB94951L, 0L, 0x8DB94951L, 0L}};
                    int16_t l_1506 = 0xCDFDL;
                    uint16_t l_1512 = 65535UL;
                    uint32_t l_1575 = 0xB622C4ACL;
                    int i, j;
                    if ((safe_add_func_int8_t_s_s(((((g_747 = (g_758[0][2] >= 0x30L)) , (18446744073709551606UL && ((l_1432[1] ^ (safe_sub_func_int32_t_s_s((safe_rshift_func_uint8_t_u_u(((l_1361[0][1] > (l_1450 = (l_1442 = l_1449))) & (g_483[1] <= (l_1449 < p_47))), 4)), 0UL))) == p_50))) != l_1449) > g_695), 8L)))
                    {
                        int8_t l_1468 = (-8L);
                        l_1468 = (((safe_add_func_int8_t_s_s((l_1455[1] = (g_152[2][0][1] , (p_48 >= g_1121))), ((safe_rshift_func_int16_t_s_s((((p_49 , (((safe_rshift_func_uint8_t_u_s((l_1407 = ((safe_add_func_int8_t_s_s((safe_add_func_uint8_t_u_u((p_47 = (l_1432[3] , (g_203 = (safe_mod_func_int64_t_s_s(l_1431, p_47))))), (8L != (safe_add_func_uint8_t_u_u(0xEDL, 3UL))))), 0x4BL)) == p_50)), 3)) != 0xD674L) && 0xA3L)) || 0xD9334DA9L) ^ g_1405[9][3][0]), g_483[1])) == p_49))) >= 0x8E7FF10CL) != 0UL);
                        g_76 = ((((l_1469 = p_48) >= p_50) ^ ((+(l_1431 ^ (safe_rshift_func_uint8_t_u_u(0x20L, 2)))) & (safe_mod_func_int16_t_s_s(((l_1407 >= l_1431) || 249UL), (safe_mod_func_uint64_t_u_u((safe_add_func_int32_t_s_s((((p_49 <= (l_1481 = ((l_1455[5] = l_1361[0][3]) >= 0xFAL))) && p_50) || 0L), g_952[4][2])), l_1420)))))) == p_48);
                        l_1490[1][2] = (~(p_50 | (safe_rshift_func_uint8_t_u_s(((2L & ((((safe_rshift_func_int8_t_s_s(p_48, (g_483[2] ^ (((g_151 = ((((safe_unary_minus_func_uint8_t_u((((p_49 < ((safe_mod_func_uint32_t_u_u(4294967294UL, (l_1450 = (l_1455[0] = (0x1D359CCC69F8E8B1LL ^ 0UL))))) , ((p_49 >= p_49) ^ g_208))) , p_48) == 0x1A5FDFC5C6DBA0CELL))) | l_1432[4]) == 5L) == 0x7641L)) == l_1442) && 0x8DDCL)))) , p_49) ^ 4294967289UL) | 0UL)) ^ l_1420), 4))));
                        l_1490[1][2] = l_1449;
                    }
                    else
                    {
                        l_1407 = l_1432[9];
                    }
                    l_1442 = (l_1490[1][2] = (g_1507 = (safe_sub_func_uint32_t_u_u(g_188[0], (l_1407 = ((((((safe_lshift_func_int16_t_s_u(((safe_lshift_func_uint16_t_u_u(l_1490[0][2], 13)) | p_47), g_579)) <= (safe_add_func_uint16_t_u_u(65528UL, (safe_rshift_func_int8_t_s_s((((l_1385 = (g_105[0][3][1] <= (((safe_lshift_func_int16_t_s_u((safe_add_func_int64_t_s_s(((l_1490[1][2] != ((~(g_81[0] = (p_48 > ((((((p_49 > 5L) < 0xD2L) <= l_1506) & 0xF015C02D207CCD70LL) || g_551) | 0x878495E2L)))) , p_47)) <= 0xB0751AC3L), 0xD648ABEC5B20F5F7LL)), l_1431)) & l_1367) || 1L))) >= g_105[0][8][4]) ^ 0x63BF9E257F1316D3LL), p_47))))) != 0xC0L) || l_1367) == 4294967295UL) ^ 0xAC650318L))))));
                    if ((l_1420 | ((g_152[1][0][5] = 0UL) , ((safe_rshift_func_int16_t_s_s(((0x20E1544DL <= (safe_mod_func_uint8_t_u_u(l_1512, ((safe_sub_func_uint64_t_u_u(l_1515, p_50)) ^ (safe_add_func_int16_t_s_s((l_1385 = (0x9919L == (((((((g_747 = g_163) >= ((((((safe_sub_func_int16_t_s_s(l_1432[4], 0x0E05L)) > p_48) < g_483[1]) || 1L) , 0x65L) , p_48)) | l_1520) , 0x61L) | 255UL) , 0xB24DAA5B60EC872ELL) <= g_163))), 65534UL)))))) & 0x23L), p_49)) != g_483[1]))))
                    {
                        uint32_t l_1553 = 1UL;
                        g_76 = ((g_520 = ((!(g_381 = (safe_add_func_int8_t_s_s(0xD2L, ((g_875 = ((g_276 = 0xA2L) , g_381)) || (p_49 && ((((((safe_mod_func_int8_t_s_s((safe_rshift_func_int8_t_s_s(((l_1385 = (((((((p_49 == 1L) >= 0x68L) <= ((safe_add_func_int32_t_s_s(1L, (safe_add_func_uint64_t_u_u((safe_mod_func_int8_t_s_s(0xD1L, g_482[2][2][3])), l_1534)))) < 0x2D5DFA9BEA341718LL)) < 9L) , 4294967291UL) , g_579) ^ p_49)) < 6L), 3)), g_188[0])) & 0xD080L) , l_1442) , 0x4A30L) & g_952[4][2]) >= 1L))))))) < 0x441E9E50L)) , p_50);
                        l_1455[1] = (~(4UL | (safe_lshift_func_int16_t_s_u((p_47 != (safe_mod_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_s(((safe_lshift_func_int16_t_s_s(g_203, g_483[1])) != (p_50 || ((safe_add_func_int16_t_s_s((p_47 <= (g_324 = 0xF916L)), (safe_add_func_uint64_t_u_u(((l_1481 = ((((safe_lshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u(255UL, ((((g_81[0] = ((+((((0x9C11L >= l_1490[3][3]) || (-8L)) ^ g_381) , l_1420)) > g_758[2][4])) , 8L) && l_1553) && 0x73L))) && l_1490[0][4]), p_48)) & p_50) >= g_152[1][0][5]) && l_1554)) , p_47), g_1016)))) > 0x572EE0BBC9886FBALL))), g_91)), g_124))), 8))));
                    }
                    else
                    {
                        int8_t l_1560[2][9] = {{0x2BL, 0x2BL, 8L, 0x08L, 0x48L, 0x08L, 8L, 0x2BL, 0x2BL}, {0x2BL, 0x2BL, 8L, 0x08L, 0x48L, 0x08L, 8L, 0x2BL, 0x2BL}};
                        int i, j;
                        g_105[0][6][0] = ((((l_1385 = 0xA2A75F3FB5C58BF9LL) ^ (~(safe_rshift_func_uint16_t_u_s(((l_1560[0][6] = ((l_1554 > g_483[2]) <= (safe_lshift_func_int8_t_s_u(p_47, 1)))) && (safe_lshift_func_int8_t_s_u((safe_rshift_func_uint16_t_u_s((l_1565[2][2][0] <= ((((((safe_add_func_uint8_t_u_u(250UL, (safe_rshift_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(g_188[0], ((safe_sub_func_int64_t_s_s((g_423 = ((g_747 = ((((6UL ^ (0xE6L <= 0xECL)) < p_48) == g_269) , 0xE7C3L)) == p_47)), p_50)) != l_1565[2][2][0]))) , l_1469), g_695)))) <= 5L) , l_1574[2]) ^ p_48) == l_1406[3]) <= l_1398)), 0)), g_148))), p_48)))) , g_1023[1][4][5]) <= p_47);
                        l_1575 = 9L;
                        l_1455[1] = ((p_50 >= ((safe_add_func_uint8_t_u_u((((p_47 <= 0xBDE8L) ^ (safe_lshift_func_uint16_t_u_u((g_511 <= ((p_50 != (((safe_unary_minus_func_uint8_t_u((0x83A4L >= (((safe_mod_func_uint32_t_u_u(((safe_add_func_int32_t_s_s((((g_875 > ((((((safe_mod_func_uint32_t_u_u((((g_1593 = ((safe_add_func_int16_t_s_s(9L, (safe_lshift_func_uint8_t_u_u((((safe_mod_func_uint16_t_u_u(65528UL, g_483[0])) & g_559) || g_90), g_576)))) <= 0L)) >= p_48) , 4294967294UL), 0xF13E5F57L)) || p_47) && 0x23732B732382E34BLL) & p_47) & 0xF5C17530L) & (-1L))) || l_1565[2][2][0]) , 0x52E3D582L), 0x1F7CEBABL)) | g_188[0]), l_1560[0][6])) < g_875) & 0x8BB57D75L)))) != g_551) & p_47)) >= p_49)), 1))) >= 18446744073709551615UL), 0x7DL)) == l_1574[2])) < 2UL);
                        return g_758[4][0];
                    }
                    g_482[4][2][3] = ((safe_sub_func_uint32_t_u_u(0xE5930B54L, (g_105[0][3][1] = g_90))) != 0x5EC8L);
                }
                else
                {
                    uint8_t l_1597 = 3UL;
                    int64_t l_1612 = 0x4DDB825B8A6CD5BELL;
                    uint64_t l_1614 = 0UL;
                    int32_t l_1632 = 0x046478E8L;
                    int32_t l_1655[2][6] = {{0x790873C3L, (-7L), 0x5610BFE8L, 0x5610BFE8L, (-7L), 0x790873C3L}, {0x790873C3L, (-7L), 0x5610BFE8L, 0x5610BFE8L, (-7L), 0x790873C3L}};
                    int i, j;
                    if ((!((l_1597 , (((safe_lshift_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((((((l_1616 = (((l_1615[1][0] = (((safe_sub_func_uint8_t_u_u((((safe_add_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_s(0x4DL, l_1398)), (l_1515 < (g_465 <= ((g_1613 = (((p_50 , g_952[4][1]) != ((safe_add_func_int64_t_s_s((safe_rshift_func_uint8_t_u_u(248UL, ((-1L) || g_551))), 0xC6CC315713BBB757LL)) <= (-9L))) ^ l_1612)) <= 3L))))) <= l_1534) < l_1431), l_1614)) , g_579) && g_747)) | 0x2FE4E4699329FD0CLL) || l_1432[1])) ^ g_148) && l_1387) < p_48) , 0x3AL), l_1574[2])), p_49)) != g_93) && p_49)) <= p_49)))
                    {
                        return p_49;
                    }
                    else
                    {
                        l_1632 = ((safe_rshift_func_int16_t_s_s(((0x96C9DF21E312C42CLL >= (0xFA354F1FC35AFA75LL <= ((safe_mod_func_int16_t_s_s(g_482[5][1][0], (safe_lshift_func_uint16_t_u_u(l_1398, (safe_rshift_func_int8_t_s_s((safe_sub_func_uint16_t_u_u(p_47, ((safe_sub_func_int16_t_s_s(((l_1481 != (safe_add_func_uint8_t_u_u((g_81[0] = (+(l_1614 & (g_1388[1] > (l_1364 = ((l_1420 > p_48) , g_482[1][1][3])))))), (-1L)))) || g_1023[1][4][5]), l_1407)) != 8UL))), 1)))))) == p_48))) != p_47), 4)) , 0x34CFAD37L);
                    }
                    if ((safe_add_func_uint16_t_u_u(p_49, (l_1450 = g_1507))))
                    {
                        return p_47;
                    }
                    else
                    {
                        if (l_1635)
                            break;
                        l_1407 = (g_482[6][2][0] = (((-8L) || 0x67AEL) == ((safe_rshift_func_int16_t_s_u(((((l_1481 = ((l_1481 , (((g_188[0] | (18446744073709551610UL < 0xB863BCC068F8EC20LL)) || g_559) >= 0x1CL)) || g_208)) , p_47) < p_50) < l_1361[0][3]), 5)) & 1UL)));
                        l_1481 = p_50;

for (g_1613 = 0; (g_1613 < (-6)); g_1613--)
                    {
                        uint16_t l_800 = 0x10E9L;
                        l_1442 = ((safe_add_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_s(l_1515, ((g_579 , (g_1121 == (((0x9151FB835E603606LL != l_1925) == g_579) & ((((safe_add_func_uint64_t_u_u((l_1420 = (3UL ^ (((-1L) > (((safe_rshift_func_uint8_t_u_u(0x91L, g_579)) && l_1635) != g_579)) && l_1398))), 18446744073709551615UL)) , g_105[0][3][1]) > p_50) != l_1398)))) , 2L))) ^ 4294967295UL) ^ l_1398), l_1398)) , l_800);
                    };



if (g_511)
                            continue;
                    }
                    for (l_1367 = 0; (l_1367 <= 6); l_1367 += 1)
                    {
                        int i;
                        l_1442 = (l_1655[1][3] = ((((safe_sub_func_uint32_t_u_u(((((((((safe_lshift_func_uint16_t_u_s(l_1574[l_1367], 2)) & l_1574[l_1367]) < (safe_rshift_func_uint8_t_u_s((((g_576 = (l_1364 = (safe_mod_func_uint16_t_u_u((0UL <= (l_1385 = p_48)), (0UL ^ ((g_381 = (((safe_lshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_s(65535UL, (0x7DL == (((safe_mod_func_int32_t_s_s(((0x08EAL > ((((safe_unary_minus_func_int32_t_s((((l_1632 = g_694) || l_1431) & g_1121))) , g_875) > g_152[1][0][5]) >= l_1361[0][3])) <= p_48), l_1574[2])) <= l_1534) != p_50)))) && l_1450), g_276)) < (-1L)) == p_47)) , 0UL)))))) , 0x1CL) >= p_49), p_47))) ^ l_1515) > l_1635) | l_1574[l_1367]) , g_551) == g_1405[5][0][1]), 0xB784DF07L)) | 1L) , 0x54L) != p_49));
                        if (g_188[0])
                            continue;
                        return l_1361[0][3];
                    }
                }
            }
            if ((l_1420 ^ 0xD16DE3BCFFB0E960LL))
            {
                int32_t l_1656 = (-10L);
                int32_t l_1663 = 0L;
                uint64_t l_1711 = 0xC89DE85AD790C3BCLL;
                uint8_t l_1763[2];
                uint32_t l_1827 = 0UL;
                int i;
                for (i = 0; i < 2; i++)
                    l_1763[i] = 9UL;
                if ((l_1656 < (safe_sub_func_uint16_t_u_u((((safe_mod_func_int64_t_s_s(((g_152[1][0][5] = 18446744073709551615UL) != (((l_1481 = (g_163 = (l_1656 , (p_49 != l_1406[3])))) | ((((l_1515 , (p_47 || g_203)) == ((l_1663 = (l_1662 = ((safe_unary_minus_func_uint64_t_u((l_1385 && g_1405[2][1][1]))) | g_576))) || p_49)) & p_48) || 0xD8L)) != l_1407)), 18446744073709551612UL)) , g_208) || 0xB46CL), p_47))))
                {
                    uint16_t l_1670[9][10][2] = {{{65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}}, {{65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}}, {{65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}}, {{65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}}, {{65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}}, {{65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}}, {{65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}}, {{65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}}, {{65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}, {65534UL, 0x94E5L}}};
                    int32_t l_1701 = 1L;
                    int32_t l_1705 = 0xC2B94873L;
                    int i, j, k;
                    l_1682 = ((safe_add_func_uint16_t_u_u((safe_mod_func_int64_t_s_s((safe_sub_func_uint8_t_u_u((((((7L < (l_1670[3][7][1] >= g_188[0])) == (((((safe_add_func_int64_t_s_s((g_952[4][2] == p_49), (l_1673 , (safe_rshift_func_int8_t_s_s(((safe_rshift_func_int8_t_s_u(((safe_mod_func_uint32_t_u_u((p_48 ^ l_1670[3][7][1]), (safe_lshift_func_int16_t_s_s(p_49, p_48)))) == 0UL), 3)) | g_151), g_576))))) ^ l_1662) , p_49) < 65527UL) || l_1515)) || 65535UL) && 18446744073709551615UL) ^ g_148), 0x48L)), p_50)), p_50)) , 3L);
                    for (g_521 = 0; (g_521 == 51); g_521++)
                    {
                        uint32_t l_1702 = 1UL;
                        int32_t l_1706[5][4][8] = {{{(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}}, {{(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}}, {{(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}}, {{(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}}, {{(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}, {(-5L), 0xEF86A80CL, (-1L), 6L, 0L, 2L, 0L, 0L}}};
                        int i, j, k;
                        l_1385 = ((safe_add_func_uint32_t_u_u((safe_add_func_uint32_t_u_u((l_1705 = ((safe_add_func_uint64_t_u_u(((0x78C8L & ((safe_sub_func_uint64_t_u_u((+(!(safe_rshift_func_int8_t_s_u((((((((l_1702 = (l_1701 = (((l_1662 = 1L) , p_49) || (safe_sub_func_uint8_t_u_u(p_49, (safe_add_func_int16_t_s_s(0x4E4DL, (p_47 | ((l_1663 || (((l_1407 < p_47) < 5L) != p_48)) != g_124))))))))) , g_202) < 0xBD2EL) <= g_576) > p_49) | g_1703) || g_1704), 2)))), g_381)) , p_49)) , 0x68C1B70003B87C5ELL), 5L)) ^ l_1406[1])), p_49)), l_1706[2][1][6])) | 0xB68AFE1786EA430FLL);
                        if (p_47)
                            break;

g_747 += 1;



if (p_47)
                            break;
                        l_1385 = ((l_1662 = (l_1481 = 18446744073709551613UL)) > (l_1663 = (safe_rshift_func_uint8_t_u_s(p_50, p_49))));
                    }
                    return g_1405[9][3][0];
                }
                else
                {
                    int32_t l_1720 = (-1L);
                    for (l_1398 = 0; (l_1398 != 25); l_1398 = safe_add_func_uint16_t_u_u(l_1398, 5))
                    {
                        l_1662 = (l_1711 = p_50);
                        return p_50;
                    }
                    l_1731[2][7][2] = ((l_1534 | (g_28[6][1] > (g_1730 = (((safe_sub_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_u((~(((+(safe_lshift_func_uint8_t_u_s((g_148 <= (l_1720 , (~p_47))), 2))) || (0x749AL && ((safe_sub_func_int8_t_s_s(((~l_1656) & (safe_lshift_func_uint8_t_u_u(((-1L) <= ((((safe_lshift_func_uint16_t_u_u(0xF8C5L, 2)) | 0xC109L) == l_1406[3]) , p_47)), g_482[5][1][0]))), g_381)) ^ 0x1DF96F497B6ECC77LL))) && g_28[6][1])), 6)) | g_1729[0][3]) >= 0xCCA00D2D3EA11F80LL), p_47)) > g_482[4][2][3]) <= g_1023[2][3][6])))) == l_1534);
                }
                l_1750 = (l_1751[1][3][2] = ((safe_mod_func_int8_t_s_s((((l_1711 != (l_1407 = p_49)) , 1UL) >= (((safe_add_func_uint64_t_u_u(l_1662, (((safe_mod_func_uint8_t_u_u(((g_875 = ((safe_add_func_uint64_t_u_u((g_1388[2] | (safe_lshift_func_int8_t_s_s(((l_1481 = (safe_mod_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u((safe_add_func_uint32_t_u_u((l_1711 >= (0x8C2208D85D637A20LL | ((g_188[0] <= (0x6FL >= 0xC9L)) != l_1656))), 0UL)), 3)), 1)), g_747))) == p_49), 2))), 0xD1A495A55A6D51FCLL)) != l_1406[3])) != 0x0829C8C59F558FAFLL), l_1711)) | l_1682) >= p_47))) >= 0x592CL) , 7L)), l_1750)) , p_50));
                if ((((safe_lshift_func_int8_t_s_s((((p_49 <= ((0L || p_50) || (p_48 && (((!((safe_add_func_uint16_t_u_u(((safe_sub_func_int64_t_s_s((safe_mod_func_int32_t_s_s(((safe_add_func_uint8_t_u_u(((g_521 = p_48) , ((l_1750 = l_1763[1]) | ((safe_rshift_func_uint16_t_u_u(p_50, ((p_48 < (g_1016 = (((l_1763[1] < g_188[0]) || l_1763[0]) && g_152[1][0][2]))) ^ p_50))) | g_483[1]))), 0L)) < p_48), l_1731[8][1][0])), g_1507)) || g_559), g_694)) ^ 1L)) || 0x1FL) == l_1406[1])))) | l_1534) | p_47), g_511)) != l_1663) || 0L))
                {
                    uint32_t l_1774 = 0UL;
                    int32_t l_1776 = 0x53E9575DL;
                    int32_t l_1799 = 0x07ED9F63L;
                    l_1776 = (safe_lshift_func_uint8_t_u_s(((0x3F4A42E4L != (safe_sub_func_uint64_t_u_u(8UL, ((p_48 <= (((((p_47 = 252UL) || p_49) < 65535UL) || ((g_1775 = (p_48 && ((g_1593 = (g_1388[2] = (((safe_sub_func_int16_t_s_s(((safe_add_func_uint8_t_u_u(((l_1774 = g_167) && (l_1656 = g_1388[2])), l_1367)) != l_1407), l_1616)) , g_483[2]) <= (-1L)))) == g_483[1]))) == l_1763[1])) > 1UL)) <= l_1776)))) , g_28[1][5]), 0));
                    l_1364 = (safe_lshift_func_uint8_t_u_s(((safe_lshift_func_uint16_t_u_s((g_747 = ((((l_1407 = (g_1593 = ((safe_lshift_func_int16_t_s_u((l_1774 > g_1783[5][0]), (l_1751[1][3][2] = (safe_rshift_func_int16_t_s_u((safe_add_func_uint64_t_u_u((l_1776 = 18446744073709551614UL), (safe_mod_func_int32_t_s_s(((((safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u(4L, ((g_1507 > ((g_28[6][1] != (safe_lshift_func_int8_t_s_s((((l_1481 = p_50) <= (l_1799 = ((((safe_mod_func_uint8_t_u_u((l_1361[0][3] , (!(g_482[6][2][0] = g_1775))), 9L)) < l_1432[8]) ^ 0L) , p_50))) < 0x380CL), p_47))) , l_1800)) && l_1751[4][2][2]))), l_1662)) >= p_49) == 1UL) | l_1774), p_50)))), 8))))) >= 0UL))) | 2UL) & 0x69L) != 0UL)), 11)) || p_50), g_203));
                    if ((safe_rshift_func_int8_t_s_u(p_48, 1)))
                    {
                        int8_t l_1814 = (-3L);
                        int32_t l_1816 = (-4L);
                        g_1775 = (0x5062L > (g_559 = ((((safe_mod_func_int8_t_s_s((~(safe_rshift_func_uint16_t_u_u(g_482[0][1][3], (((((l_1799 = (((safe_add_func_uint64_t_u_u(g_482[0][1][2], ((safe_lshift_func_int8_t_s_u((((((((0x15L > ((l_1814 = ((g_105[0][0][0] = (safe_rshift_func_uint16_t_u_s(l_1481, 15))) >= p_49)) ^ ((l_1432[4] >= g_1730) == (l_1815 < (-1L))))) & l_1682) < 4UL) == l_1751[9][3][0]) & g_269) ^ g_208) <= l_1367), p_50)) != p_48))) == p_49) ^ l_1816)) && g_28[6][1]) || g_93) & g_269) ^ 0L)))), (-1L))) , 0x4C54L) != p_50) <= l_1774)));
                        l_1776 = (g_1388[2] >= ((-1L) | ((safe_sub_func_uint32_t_u_u((g_1820 = (+p_49)), ((((safe_lshift_func_int16_t_s_u(p_49, g_520)) || ((((((l_1763[0] ^ ((safe_mod_func_int64_t_s_s((safe_sub_func_uint32_t_u_u(0UL, l_1827)), (safe_sub_func_int16_t_s_s(((l_1751[1][0][1] = l_1750) == 0xD291169CL), g_758[6][3])))) || l_1615[1][0])) , (-1L)) < l_1774) >= p_50) < l_1816) >= g_324)) && p_47) < 1L))) , l_1799)));
                        l_1481 = ((0x9E189CE3L | g_152[1][0][5]) <= p_47);
                        l_1776 = (0x578BL || (l_1481 = (0x0666A715E3FB427ELL < ((safe_add_func_int16_t_s_s((safe_add_func_uint64_t_u_u(((((((g_1613 = ((g_105[0][5][4] && ((safe_rshift_func_uint8_t_u_u(((safe_mod_func_uint32_t_u_u(((((p_48 , (safe_add_func_int64_t_s_s((safe_add_func_int64_t_s_s(((((((safe_sub_func_int16_t_s_s(0xC11EL, g_152[1][0][2])) != (safe_rshift_func_uint8_t_u_s(0x2AL, 6))) >= (safe_sub_func_uint32_t_u_u((p_49 | (((g_1854 = ((g_483[0] = (safe_add_func_uint64_t_u_u(((((((safe_add_func_int32_t_s_s(1L, 0xF7CBBF8EL)) || 0L) , l_1763[1]) , (-5L)) | g_208) , 18446744073709551615UL), g_152[1][0][5]))) , g_1775)) ^ p_49) <= l_1827)), 0x1DF6A43DL))) ^ l_1663) , l_1663) , (-2L)), l_1656)), 0xF1B88EE7E5072D7FLL))) != g_694) & l_1731[3][5][1]) == p_49), p_47)) & 0x9EEDL), g_167)) | g_163)) == l_1534)) <= p_48) , p_49) >= l_1855[1]) || l_1774) & p_48), l_1816)), l_1774)) , p_48))));
                    }
                    else
                    {
                        uint32_t l_1867 = 0x82841526L;
                        int16_t l_1877 = 1L;
                        g_105[0][3][8] = ((safe_mod_func_int8_t_s_s(0x29L, ((!(safe_sub_func_uint64_t_u_u(p_50, ((((g_152[3][0][3] < g_1704) , (safe_rshift_func_uint16_t_u_u((((((safe_rshift_func_int8_t_s_u((((((g_1023[1][3][3] == (safe_mod_func_uint16_t_u_u((l_1867 = 0xB1CCL), g_324))) ^ (l_1481 = ((1UL & (safe_mod_func_int64_t_s_s(((((((safe_add_func_int8_t_s_s((((l_1776 = (l_1750 = (safe_rshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((l_1774 , p_48), g_105[0][3][1])), l_1855[1])))) , l_1876) < l_1877), 0x50L)) , p_50) , g_1783[3][0]) < p_47) == p_50) == 5UL), l_1711))) == p_49))) & 0x2AL) | (-1L)) ^ l_1799), 1)) & p_49) <= 0xBF179788L) > 1UL) > 18446744073709551607UL), l_1877))) , p_48) & p_48)))) , l_1799))) != g_520);
                        g_105[0][5][5] = (((safe_lshift_func_uint8_t_u_s((p_47 = p_47), 0)) > ((safe_lshift_func_uint16_t_u_s(0x606EL, ((((~((!2UL) >= (g_1884 & ((((safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u((((((safe_add_func_uint32_t_u_u((((l_1364 = ((g_151 = l_1877) , (((!0xEBFBL) >= ((p_49 , (((safe_add_func_uint64_t_u_u(((safe_rshift_func_int8_t_s_s(l_1615[1][0], 3)) || (safe_mod_func_uint64_t_u_u((l_1420 == l_1615[1][0]), l_1515))), l_1799)) | 0xBD71736DL) , p_49)) & p_48)) | 0xDF5C5152L))) == l_1406[1]) != 8L), 0x51FBF5FDL)) == 0UL) , g_747) , 0x0038E27BL) ^ 5UL), 15)), g_521)) != 0x5DD4L) , p_49) & p_49)))) != p_48) , g_465) != l_1867))) || 0xA0L)) != p_50);
                    }
                }
                else
                {
                    int8_t l_1902[10] = {0x18L, 0x18L, 0x38L, 0x18L, 0x18L, 0x38L, 0x18L, 0x18L, 0x38L, 0x18L};
                    int i;
                    g_76 = (safe_lshift_func_int16_t_s_s(((((safe_add_func_uint8_t_u_u(3UL, l_1902[4])) ^ (l_1751[3][0][2] = (g_105[0][5][7] = (l_1364 = ((l_1750 = l_1800) , ((((((safe_mod_func_int32_t_s_s((8UL <= (+l_1432[6])), (safe_lshift_func_int8_t_s_u(l_1751[9][1][1], 2)))) == 0x52L) >= (safe_rshift_func_int16_t_s_s(l_1910, (safe_sub_func_uint64_t_u_u((((safe_add_func_int32_t_s_s((((safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s((((safe_rshift_func_uint8_t_u_s(p_47, p_49)) , 0x543E5627D914D432LL) == (-3L)), l_1815)), 0xF1263573L)) != 5UL) > 0x1DC4L), 0UL)) == 6UL) , 0xF92863AD42449A8CLL), p_47))))) , p_49) && p_50) <= 4294967290UL)))))) < l_1398) < l_1481), p_50));
                    for (g_202 = 0; (g_202 <= 2); g_202 += 1)
                    {
                        int8_t l_1939 = 0x94L;
                        int32_t l_1956 = 6L;
                        if (l_1432[4])
                            break;
                        g_105[0][6][6] = (safe_add_func_int64_t_s_s(((0x3852L | (((safe_lshift_func_uint16_t_u_u(((0x70B8D5F3A5E82501LL || l_1750) , l_1925), 7)) != l_1731[4][7][0]) , (safe_sub_func_int8_t_s_s((((((safe_lshift_func_int8_t_s_s((safe_add_func_uint8_t_u_u((!(p_47 <= ((((safe_rshift_func_uint16_t_u_s((g_188[0] != (g_1016 = p_47)), (safe_rshift_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_u(p_48, 3)) | g_1820) > l_1902[4]), 3)))) || 6L) , 0x4CDDBFCAL) <= 1L))), p_49)), l_1939)) <= 0xC9L) >= l_1902[4]) <= l_1939) != l_1902[4]), g_1388[0])))) <= l_1815), l_1902[4]));
                        g_105[0][3][1] = (safe_mod_func_uint64_t_u_u(((((((safe_lshift_func_int8_t_s_u((((l_1662 = (l_1364 = (((safe_lshift_func_int8_t_s_u(((0xD232A29AECDE45E1LL >= (((safe_add_func_uint16_t_u_u((g_167 & (((g_208 , (safe_sub_func_int64_t_s_s((g_148 || ((g_1613 <= (l_1385 = (safe_add_func_uint16_t_u_u(((((l_1956 = (safe_lshift_func_uint8_t_u_s((g_559 , g_521), p_50))) < (l_1957[2][1][2] > g_1703)) && g_324) , p_48), l_1957[2][1][2])))) ^ 0xBFL)), 0x25A73AAA92F7F0DDLL))) & p_47) > l_1663)), p_48)) ^ 0UL) <= p_48)) < g_151), p_50)) != g_1729[0][3]) && l_1711))) & p_47) == g_579), g_28[6][1])) >= g_1507) < g_203) != 1UL) || p_49) <= p_50), l_1398));
                        g_105[0][3][1] = ((((safe_unary_minus_func_uint16_t_u((safe_mod_func_uint32_t_u_u((l_1925 = (g_1970 = (((safe_mod_func_int16_t_s_s(((l_1663 = (g_579 < ((safe_sub_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((safe_sub_func_int32_t_s_s((g_81[0] , (+(g_1507 == l_1663))), p_49)), ((l_1656 <= (g_1783[5][0] > 0x39L)) & l_1902[4]))), g_1023[0][3][0])) > p_49))) != p_48), 0xBC9BL)) , l_1763[0]) | 0UL))), p_49)))) >= 0xCD5BFDAEL) , g_1730) >= p_48);
                    }
                }
                l_1364 = (safe_rshift_func_int16_t_s_s(((g_465 = p_50) < (((((safe_add_func_int64_t_s_s(g_1023[1][4][5], (safe_rshift_func_uint16_t_u_s((safe_add_func_int8_t_s_s(l_1656, l_1406[3])), (p_49 & p_49))))) , ((l_1385 = 0x3B802FE3L) >= ((safe_mod_func_int64_t_s_s(((-1L) & (safe_mod_func_uint16_t_u_u((safe_mod_func_int64_t_s_s((-1L), l_1763[1])), 0x2DD6L))), 1UL)) , p_49))) , l_1957[2][0][2]) > l_1682) | p_50)), l_1731[2][7][2]));
            }
            else
            {
                int8_t l_1985[4] = {0x24L, 0x43L, 0x24L, 0x43L};
                uint32_t l_2015[8][1] = {{0xC7B68C41L}, {0xC7B68C41L}, {0xC7B68C41L}, {0xC7B68C41L}, {0xC7B68C41L}, {0xC7B68C41L}, {0xC7B68C41L}, {0xC7B68C41L}};
                int i, j;
                g_76 = (g_579 = l_1985[0]);
                l_1751[1][3][2] = (((safe_sub_func_int8_t_s_s(0xB7L, (g_1388[2] > (safe_add_func_uint64_t_u_u((safe_lshift_func_int16_t_s_s(g_15, 15)), (safe_add_func_uint16_t_u_u(((0x2B40C402L || ((((safe_rshift_func_uint16_t_u_s(((0x0B99L != (safe_sub_func_uint8_t_u_u((safe_mod_func_uint64_t_u_u((l_1985[0] == (safe_sub_func_uint16_t_u_u((((l_1481 = ((safe_sub_func_int16_t_s_s((safe_unary_minus_func_uint32_t_u((l_1407 = (l_1431 , (safe_lshift_func_uint16_t_u_s(((l_1615[1][0] , (safe_rshift_func_int8_t_s_s((safe_sub_func_uint32_t_u_u((safe_add_func_uint16_t_u_u((safe_add_func_int32_t_s_s(p_50, p_48)), 1L)), l_1615[1][0])), l_1407))) , g_1704), p_48)))))), 65527UL)) , (-8L))) < l_1957[2][2][1]) && g_1121), g_152[0][0][1]))), p_47)), g_1775))) < 9UL), 9)) && 4294967287UL) ^ 0x2240F4F8DEF3BB6ELL) && 6L)) > l_1432[5]), l_2015[2][0]))))))) || g_90) , 0xD37BB40AL);
                g_1775 = (safe_lshift_func_int8_t_s_u(0x92L, (safe_mod_func_uint16_t_u_u(((p_49 | (((l_1750 = ((l_1364 = (safe_sub_func_uint8_t_u_u(0x6CL, (safe_lshift_func_uint16_t_u_u((safe_mod_func_int8_t_s_s(p_47, 2UL)), 12))))) > (l_1385 = (((0x56EDFF1EE5423717LL || (safe_rshift_func_int16_t_s_s((((safe_add_func_int8_t_s_s((safe_rshift_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(((l_2015[4][0] || (!(0x55F4L != (l_1385 , l_2035[4])))) > g_167), p_50)), 5)), p_50)) || 0xA1L) & l_1751[1][3][2]), 6))) && l_1985[0]) , 0x473BL)))) != g_1783[5][0]) & g_1023[2][4][5])) | l_1662), p_50))));
            }
            g_1775 = ((+(g_1507 == 0x27L)) < l_1800);
        }
        else
        {
            uint64_t l_2037[10][3] = {{0UL, 1UL, 18446744073709551607UL}, {0UL, 1UL, 18446744073709551607UL}, {0UL, 1UL, 18446744073709551607UL}, {0UL, 1UL, 18446744073709551607UL}, {0UL, 1UL, 18446744073709551607UL}, {0UL, 1UL, 18446744073709551607UL}, {0UL, 1UL, 18446744073709551607UL}, {0UL, 1UL, 18446744073709551607UL}, {0UL, 1UL, 18446744073709551607UL}, {0UL, 1UL, 18446744073709551607UL}};
            int32_t l_2046 = (-1L);
            int i, j;
            l_2037[0][0] = p_49;

{
        for (g_694 = 0; g_694 < 9; g_694++)
        {
            for (k = 0; k < 2; k++)
            {
                transparent_crc(g_1405[g_579][g_694][k], "g_1405[g_579][g_694][k]", g_93);
                if (g_93) printf("index = [%d][%d][%d]\n", g_579, g_694, k);

            }
        }
    }


l_1751[3][3][1] = (safe_lshift_func_int8_t_s_s((!((((g_105[0][0][3] >= ((safe_lshift_func_uint16_t_u_s((l_2046 = ((g_1016 || g_579) , (+p_47))), 9)) >= ((safe_mod_func_int64_t_s_s((p_47 | (safe_mod_func_int64_t_s_s((safe_mod_func_int32_t_s_s(((g_483[1] = ((p_50 != ((g_152[1][0][5] = ((((safe_rshift_func_int16_t_s_u(p_50, (l_1481 = (g_747 = ((+((safe_lshift_func_int8_t_s_u((safe_add_func_uint16_t_u_u((0xF52A5113478697F6LL < ((+(l_1407 = (safe_sub_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(((((g_1775 = ((safe_add_func_uint64_t_u_u(7UL, 0x165EF791BF22EA1BLL)) , l_1615[5][0])) ^ 9L) < l_1420) > g_483[1]), 4L)), 246UL)), p_49)))) , p_48)), g_1121)), 0)) >= l_1957[2][1][2])) & p_48))))) & 2L) ^ g_952[7][2]) , l_1731[2][7][2])) && p_47)) , 18446744073709551610UL)) , p_47), 0x87E81690L)), l_2037[0][0]))), l_1731[8][7][2])) || 0UL))) ^ 0xD2FFD587L) >= g_188[0]) <= (-1L))), p_50));
        }
    }
    return l_1515;
}







static int32_t func_53(uint16_t p_54)
{
    uint32_t l_1339 = 2UL;
    int32_t l_1340 = 0L;
    int32_t l_1341 = 4L;
    int32_t l_1342 = 0x5FA3AAFEL;
    l_1342 = (l_1341 = (safe_lshift_func_int8_t_s_s((18446744073709551615UL > ((((g_81[0] != ((safe_sub_func_int64_t_s_s(1L, (((((p_54 || ((l_1339 == l_1339) > g_520)) && 0x41L) ^ (l_1340 = p_54)) > g_465) < g_81[0]))) & p_54)) <= g_202) == 0x3BL) <= l_1339)), 5)));
    return p_54;
}







static uint16_t func_55(int32_t p_56)
{
    uint64_t l_60 = 1UL;
    int32_t l_83 = (-4L);
    int32_t l_204[4] = {5L, (-2L), 5L, (-2L)};
    int16_t l_424 = 0x9D79L;
    int32_t l_505 = 0L;
    int8_t l_697 = 2L;
    int8_t l_702 = 0xC8L;
    int32_t l_709 = 0L;
    uint32_t l_710[9] = {7UL, 0xB8ADD8FEL, 7UL, 0xB8ADD8FEL, 7UL, 0xB8ADD8FEL, 7UL, 0xB8ADD8FEL, 7UL};
    uint64_t l_742 = 0xCE6CAAD49A671E8DLL;
    int16_t l_743[1];
    uint64_t l_745 = 18446744073709551611UL;
    uint8_t l_799 = 1UL;
    int8_t l_874 = 0xFBL;
    uint32_t l_1051 = 0x765C9EEEL;
    uint8_t l_1145 = 2UL;
    uint64_t l_1173 = 4UL;
    int32_t l_1187[7][2] = {{1L, 0x62BE95A5L}, {1L, 0x62BE95A5L}, {1L, 0x62BE95A5L}, {1L, 0x62BE95A5L}, {1L, 0x62BE95A5L}, {1L, 0x62BE95A5L}, {1L, 0x62BE95A5L}};
    uint32_t l_1200[1][3][10] = {{{0x55F78B80L, 0xD2645AB9L, 0x55F78B80L, 0xD2645AB9L, 0x55F78B80L, 0xD2645AB9L, 0x55F78B80L, 0xD2645AB9L, 0x55F78B80L, 0xD2645AB9L}, {0x55F78B80L, 0xD2645AB9L, 0x55F78B80L, 0xD2645AB9L, 0x55F78B80L, 0xD2645AB9L, 0x55F78B80L, 0xD2645AB9L, 0x55F78B80L, 0xD2645AB9L}, {0x55F78B80L, 0xD2645AB9L, 0x55F78B80L, 0xD2645AB9L, 0x55F78B80L, 0xD2645AB9L, 0x55F78B80L, 0xD2645AB9L, 0x55F78B80L, 0xD2645AB9L}}};
    uint64_t l_1206 = 0xCBB8C99E76B701ECLL;
    int32_t l_1232 = 0x610B1950L;
    uint64_t l_1236 = 6UL;
    int i, j, k;
    for (i = 0; i < 1; i++)
        l_743[i] = 0x4292L;
                      if (( g_423 < 5299293889265452312) )
{

{
        for (g_695 = 0; g_695 < 5; g_695++)
        {
            for (l_709 = 0; l_709 < 10; l_709++)
            {
                transparent_crc(g_1023[l_709][g_695][l_709], "g_1023[l_709][g_695][l_709]", g_1775);
                if (g_1775) printf("index = [%d][%d][%d]\n", l_709, g_695, l_709);

            }
        }
    }

}

if ((g_28[6][1] == (safe_sub_func_uint16_t_u_u(0x7530L, ((l_60 = g_28[6][1]) | p_56)))))
    {
        int32_t l_77[6];
        int32_t l_80 = (-5L);
        int32_t l_82 = 0L;
        int32_t l_187 = (-3L);
        uint32_t l_201 = 0x5AC32FFCL;
        int i;

{
            transparent_crc(g_1729[l_82][l_505], "g_1729[l_82][l_505]", l_1232);
            if (l_1232) printf("index = [%d][%d]\n", l_82, l_505);

        }


for (i = 0; i < 6; i++)
            l_77[i] = 0x949389D0L;
        g_76 = ((g_28[2][6] || (safe_add_func_int16_t_s_s((l_83 = (((l_60 ^ (g_81[0] = (safe_mod_func_int64_t_s_s((g_28[6][1] ^ ((safe_sub_func_int16_t_s_s((l_77[5] = (safe_mod_func_uint64_t_u_u(((safe_lshift_func_int8_t_s_s(0x5CL, 3)) != ((safe_rshift_func_uint8_t_u_s((!g_76), g_28[6][1])) | 0x6CF3L)), l_60))), ((l_80 = (safe_rshift_func_uint8_t_u_u(252UL, l_60))) < 0xD35EB13E27C2130BLL))) != p_56)), 3L)))) == p_56) == l_82)), 0xF6D6L))) || l_83);
        for (p_56 = 5; (p_56 >= 0); p_56 -= 1)
        {
            int32_t l_92 = 0x51589059L;
            int i;
            g_76 = ((((safe_lshift_func_int16_t_s_s((l_77[5] = (l_77[p_56] && ((0xAA798D66L >= (((safe_add_func_uint64_t_u_u((((l_77[p_56] > (((l_82 = (l_77[p_56] == g_81[0])) , (0x86L < (-4L))) >= (l_60 , ((g_91 = (l_80 = (g_90 = (safe_rshift_func_int16_t_s_u(((g_28[4][0] >= 5L) & l_80), g_28[6][1]))))) & l_83)))) & (-6L)) <= g_28[5][1]), g_28[6][1])) == 0UL) | g_76)) && g_28[1][2]))), p_56)) < l_92) ^ 0x508B3DEF23EAFAF4LL) & p_56);
        }
        for (g_91 = 0; (g_91 <= 0); g_91 += 1)
        {
            int32_t l_104[6][2] = {{0L, 0L}, {0L, 0L}, {0L, 0L}, {0L, 0L}, {0L, 0L}, {0L, 0L}};
            int32_t l_107 = 0x40DCEDD9L;
            int32_t l_108 = 0x657C725CL;
            int8_t l_146 = 4L;
            int i, j;
            g_76 = (g_93 = g_81[g_91]);
            for (l_82 = 0; (l_82 <= 0); l_82 += 1)
            {
                int32_t l_106[10][3] = {{0x06A2966CL, 1L, 1L}, {0x06A2966CL, 1L, 1L}, {0x06A2966CL, 1L, 1L}, {0x06A2966CL, 1L, 1L}, {0x06A2966CL, 1L, 1L}, {0x06A2966CL, 1L, 1L}, {0x06A2966CL, 1L, 1L}, {0x06A2966CL, 1L, 1L}, {0x06A2966CL, 1L, 1L}, {0x06A2966CL, 1L, 1L}};
                int i, j;
                l_108 = ((((((safe_lshift_func_int16_t_s_u((safe_add_func_int64_t_s_s((((safe_rshift_func_int16_t_s_s((g_81[l_82] , (l_107 = (l_106[4][0] = (((((g_81[l_82] || (((0xB163B6BA6FA0F5A0LL & ((safe_lshift_func_uint8_t_u_s((((-1L) | ((((g_105[0][3][1] = (safe_rshift_func_int16_t_s_s((((l_104[1][1] = (g_81[g_91] ^ (g_81[g_91] | (l_83 , p_56)))) ^ p_56) & g_81[0]), 5))) >= p_56) < l_80) > g_93)) , g_28[1][5]), p_56)) == g_91)) < g_93) && g_105[0][3][1])) || 0x064EL) ^ 0x3C97L) || 0xB7D616EC0BA0D379LL) || 7L)))), 12)) , p_56) > 1UL), 0xF44D61F694DF9DF5LL)), 4)) , 0xB69DL) & p_56) | 0x931259C1L) < 1L) > l_80);
            }
            for (l_80 = 0; (l_80 <= 0); l_80 += 1)
            {
                int64_t l_123 = 1L;
                uint32_t l_166 = 0x86D6A567L;
                l_104[1][1] = (0xFB9873F2L > p_56);

for (l_1232 = 0; (l_1232 > 3); ++l_1232)
                    {
                        int16_t l_666 = 3L;
                        g_482[6][0][2] = (((safe_add_func_int8_t_s_s((((g_167 = (((g_381 , (safe_rshift_func_uint16_t_u_s((safe_add_func_int8_t_s_s((g_519 = 7L), 1L)), 1))) , l_424) | (k == k))) & (g_3022 != ((i = k) ^ (safe_lshift_func_int16_t_s_u((~l_146), l_666))))) , 0xA1L), k)) > g_148) ^ 0x48L);
                        l_82 = g_579;
                        return k;
                    };



for (l_107 = 0; (l_107 >= 0); l_107 -= 1)
                {
                    int32_t l_147 = 0x4C687DC4L;
                    int32_t l_149 = (-8L);
                    int32_t l_168 = 0L;
                    int i;
                    for (l_82 = 0; (l_82 >= 0); l_82 -= 1)
                    {
                        int16_t l_125 = (-9L);
                        int i;
                        l_77[l_80] = (safe_lshift_func_uint8_t_u_u((safe_add_func_int8_t_s_s(((l_77[l_80] ^ (((l_77[l_80] || ((safe_rshift_func_int16_t_s_s((0x3FD25F9EFA0E0CC2LL & ((safe_sub_func_uint16_t_u_u((g_124 = (safe_mod_func_uint8_t_u_u(0x01L, (g_15 ^ (g_76 && (g_81[0] >= ((l_83 = ((g_76 <= (((((((((safe_rshift_func_uint8_t_u_s((p_56 != 0xF9266F03L), 6)) & p_56) != p_56) && 1L) >= l_123) < g_91) <= 0x8F82L) , 18446744073709551615UL) < 18446744073709551615UL)) , l_77[5])) && l_123))))))), g_105[0][3][1])) >= g_28[6][1])), 14)) != 8UL)) < g_15) || l_125)) == l_104[1][1]), 0x89L)), l_104[1][1]));
                    }
                    for (g_90 = 0; (g_90 <= 0); g_90 += 1)
                    {
                        uint32_t l_134 = 0UL;
                        int32_t l_150 = 8L;
                        g_105[0][3][2] = (l_83 = (safe_add_func_int16_t_s_s(((safe_mod_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_u(l_80, 4)), 0x60L)) || (safe_lshift_func_uint8_t_u_s((l_134 <= (g_152[1][0][5] = ((!(g_151 = ((((safe_add_func_int8_t_s_s(l_104[1][1], ((l_77[5] = (l_77[4] > (g_76 > (l_150 = (l_149 = ((g_148 = (safe_sub_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(p_56, ((safe_lshift_func_uint8_t_u_s(((g_124 >= (safe_rshift_func_int16_t_s_u((((l_123 || g_91) && g_81[0]) > l_146), l_77[5]))) , 255UL), p_56)) && 0xFF05L))), l_147))) < p_56)))))) < 0x2FC082C0L))) || g_81[0]) | l_147) & p_56))) & g_81[0]))), g_91))), l_147)));
                    }
                    l_77[5] = ((~(safe_mod_func_uint32_t_u_u((l_80 > ((((0x02L == (~(l_83 = ((l_168 = (p_56 < ((safe_mod_func_uint32_t_u_u((g_167 = ((g_81[l_80] = (l_83 && (((((+((l_149 = 0xF569B843L) >= ((g_163 = (safe_unary_minus_func_int64_t_s((safe_rshift_func_uint8_t_u_s(0x5EL, 2))))) ^ (l_147 , l_123)))) <= (((safe_add_func_int64_t_s_s(l_166, l_147)) < l_147) , g_28[5][7])) , 7UL) , 0x5045441F61FBC89FLL) == (-4L)))) == g_124)), p_56)) & l_60))) | 0x5EL)))) | l_60) ^ p_56) >= g_105[0][7][5])), g_152[4][0][4]))) , 0x76EB5C15L);
                    for (l_149 = 0; (l_149 < 20); ++l_149)
                    {
                        uint16_t l_171 = 0x8F4EL;
                        g_105[0][3][1] = l_171;
                        return g_163;
                    }
                }
            }
            for (g_90 = 0; (g_90 <= 10); g_90 = safe_add_func_int8_t_s_s(g_90, 2))
            {
                return g_91;
            }
        }
        if (((g_91 || 0x01BA2FB8516656B1LL) & ((safe_mod_func_uint16_t_u_u((g_188[0] = (safe_sub_func_uint16_t_u_u(l_77[5], ((g_93 != g_93) <= ((((+(safe_lshift_func_int8_t_s_s(p_56, ((safe_sub_func_uint8_t_u_u((((g_152[0][0][3] ^ (-8L)) || (safe_mod_func_int16_t_s_s(((safe_lshift_func_int8_t_s_s((((p_56 != 0x60L) >= 7UL) > l_82), 1)) != g_167), p_56))) != l_187), g_15)) , 0x7AL)))) , 0xD5F3CC42DB4DAEADLL) ^ p_56) != 0x95L))))), p_56)) > l_83)))
        {
            uint8_t l_189 = 1UL;
            l_189 = l_60;
        }
        else
        {
            int64_t l_197 = 0xA891246E79F7EB36LL;
            uint32_t l_200 = 0x4CFC64E1L;
            l_204[2] = (((g_151 = 7L) & (((safe_rshift_func_int8_t_s_u((g_93 != (g_203 = ((+(g_202 = (l_80 = ((((safe_rshift_func_int8_t_s_s((l_197 = (safe_rshift_func_int16_t_s_u(l_60, 3))), 1)) || ((0UL ^ (safe_add_func_int8_t_s_s((g_90 >= ((l_83 = l_60) <= (((((((0xC0F5L >= (((l_200 = p_56) >= (6L == 0UL)) < g_188[0])) & l_201) , g_81[0]) != p_56) | l_60) < 5L) <= l_60))), p_56))) < g_163)) , p_56) == g_152[1][0][5])))) != p_56))), p_56)) >= 0x7124CF96642D96FBLL) > 0x299ECA85L)) & 1L);
            return g_93;
        }
    }
    else
    {
        int32_t l_205[2];
        int32_t l_248 = 0xE6961723L;
        uint8_t l_312 = 0xB4L;
        int32_t l_480 = (-6L);
        int16_t l_560[9] = {9L, 8L, 9L, 8L, 9L, 8L, 9L, 8L, 9L};
        int i;
        for (i = 0; i < 2; i++)
            l_205[i] = 0xAFC14AF0L;
        l_205[0] = p_56;
        if (l_205[0])
        {
            uint32_t l_219 = 0UL;
            g_105[0][3][1] = (safe_sub_func_uint16_t_u_u(((l_60 == ((g_208 = l_205[1]) | (((safe_sub_func_uint64_t_u_u((l_204[2] = (safe_lshift_func_uint8_t_u_s(p_56, 2))), (safe_add_func_int16_t_s_s(p_56, (p_56 , (safe_add_func_int64_t_s_s((((((g_28[6][1] & (l_205[0] , (((l_83 = (((safe_lshift_func_int16_t_s_s((g_148 = (-1L)), 6)) | (p_56 != 1UL)) , 1UL)) != p_56) > g_76))) && l_219) , p_56) , 0x23CB69B9L) == l_219), 0xE78B22332C2AF841LL))))))) == l_219) , 4294967288UL))) == g_124), g_15));
        }
        else
        {
            int8_t l_249 = 0x09L;
            int32_t l_268 = (-1L);
            uint16_t l_311[5] = {65535UL, 0xB51FL, 65535UL, 0xB51FL, 65535UL};
            uint64_t l_321 = 0xBC31D82569CB5C4FLL;
            uint64_t l_327 = 0x8220034B15233EBALL;
            int64_t l_404 = 0xA8398D24BC1E70CELL;
            int32_t l_512 = 0x06786BF2L;
            uint8_t l_611 = 255UL;
            int32_t l_654 = 0x142E51CAL;
            int i;
            for (g_167 = (-3); (g_167 != (-1)); g_167++)
            {
                for (g_208 = 28; (g_208 <= 20); --g_208)
                {
                    return g_28[6][1];
                }
                if (g_91)
                    continue;
            }
            for (g_167 = 0; (g_167 < (-15)); g_167 = safe_sub_func_uint64_t_u_u(g_167, 2))
            {
                int32_t l_252 = 0xC3F1FFCAL;
                uint32_t l_261[2];
                int16_t l_280 = 1L;
                int i;
                for (i = 0; i < 2; i++)
                    l_261[i] = 5UL;
                for (l_60 = 0; (l_60 <= 0); l_60 += 1)
                {
                    uint8_t l_243 = 0xC2L;
                    int32_t l_245 = 0xB17AC642L;
                    int32_t l_281 = 2L;
                    int i;
                    if ((g_188[l_60] ^ 0x9EBEL))
                    {
                        return p_56;
                    }
                    else
                    {
                        int16_t l_244 = 0x7364L;
                        int32_t l_253[8][6] = {{0x400D427AL, (-6L), (-5L), (-6L), 0x400D427AL, 0x8D2C7568L}, {0x400D427AL, (-6L), (-5L), (-6L), 0x400D427AL, 0x8D2C7568L}, {0x400D427AL, (-6L), (-5L), (-6L), 0x400D427AL, 0x8D2C7568L}, {0x400D427AL, (-6L), (-5L), (-6L), 0x400D427AL, 0x8D2C7568L}, {0x400D427AL, (-6L), (-5L), (-6L), 0x400D427AL, 0x8D2C7568L}, {0x400D427AL, (-6L), (-5L), (-6L), 0x400D427AL, 0x8D2C7568L}, {0x400D427AL, (-6L), (-5L), (-6L), 0x400D427AL, 0x8D2C7568L}, {0x400D427AL, (-6L), (-5L), (-6L), 0x400D427AL, 0x8D2C7568L}};
                        int i, j;
                        l_245 = (safe_lshift_func_int16_t_s_u((~((((((((p_56 , (((((g_151 , 0UL) < (safe_rshift_func_uint8_t_u_u(g_152[1][0][5], (!((safe_sub_func_int64_t_s_s(((safe_lshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u((safe_add_func_int32_t_s_s(((safe_lshift_func_int16_t_s_u(g_91, 6)) ^ (((+(p_56 ^ 0xF8F8L)) ^ l_243) , (-5L))), l_204[1])), l_244)), p_56)) && p_56), 0xF3817B0A88631824LL)) , l_205[0]))))) & g_105[0][3][1]) > 0x7DC6L) , g_105[0][3][1])) & 0x64L) >= 0x30L) & g_28[6][1]) && l_83) , 255UL) < 0UL) <= 0x3AL)), 2));
                        l_253[1][2] = (safe_rshift_func_int8_t_s_u((((l_249 = (l_248 = (g_188[l_60] <= g_148))) && p_56) , ((1L | ((((safe_lshift_func_int8_t_s_s((g_124 , g_167), 1)) || ((l_245 = ((((((g_90 , ((0x9CL > (g_152[0][0][5] == 9UL)) | 0x7F8293ABL)) <= (-1L)) >= 4294967295UL) , 1UL) < p_56) , l_252)) || l_204[1])) , p_56) <= l_249)) , g_151)), 0));
                        g_76 = ((l_204[1] = ((g_124 && ((p_56 <= p_56) , (safe_add_func_int64_t_s_s((safe_add_func_uint64_t_u_u((6L & p_56), (safe_sub_func_uint32_t_u_u((((g_91 < (safe_unary_minus_func_uint32_t_u(0xF7BF0A0AL))) , g_81[0]) || l_252), g_163)))), 0xA1E6C3D03F822C63LL)))) , 0xFC9DC177L)) && l_261[0]);
                    }
                    for (g_90 = 0; (g_90 <= 0); g_90 += 1)
                    {
                        uint8_t l_279[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_279[i] = 2UL;
                        g_105[0][3][1] = (((((safe_add_func_uint64_t_u_u(((safe_rshift_func_int8_t_s_u(0x22L, g_28[6][7])) ^ ((g_151 = p_56) && ((safe_lshift_func_int16_t_s_u((((l_268 = g_188[0]) & 0x339D3A4715469824LL) ^ p_56), 9)) , 0x9AL))), 0xDB5662893A887020LL)) < 7L) <= p_56) , p_56) >= p_56);
                        l_281 = ((p_56 , ((l_280 = (((g_269 = 4294967295UL) < ((g_151 = (safe_sub_func_uint64_t_u_u(g_105[0][3][8], ((((g_276 = ((safe_lshift_func_int16_t_s_u((l_245 = (safe_add_func_int16_t_s_s(l_204[1], l_83))), 8)) == l_268)) >= 18446744073709551615UL) == g_188[l_60]) && ((safe_rshift_func_int8_t_s_u((255UL <= g_148), 4)) || 0xD1ECE837L))))) == p_56)) || l_279[0])) ^ 255UL)) >= p_56);
                        if (g_276)
                            break;
                    }
                }
            }
            for (g_93 = 0; (g_93 < 8); g_93 = safe_add_func_int32_t_s_s(g_93, 2))
            {
                int16_t l_309 = 0xC262L;
                int32_t l_313 = 1L;
                int32_t l_328 = (-1L);
                int32_t l_425 = 0xB1920E52L;
                int64_t l_464 = 0xEB0DDA2389F4B7CELL;
                uint32_t l_561 = 0x4DE871DBL;
                int32_t l_631 = 1L;
                if ((safe_lshift_func_uint8_t_u_s((0x16L < (g_81[0] & 0xAAL)), 1)))
                {
                    int32_t l_310 = 0x6BFDA8D5L;
                    int8_t l_340 = 0x2EL;
                    for (g_151 = 0; (g_151 >= 0); g_151 -= 1)
                    {
                        int i;
                        g_105[0][1][4] = ((safe_rshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_u((g_188[g_151] , g_188[g_151]), 5)), (l_204[2] = p_56))) , ((safe_sub_func_int32_t_s_s((((safe_unary_minus_func_uint16_t_u((l_310 = ((safe_mod_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s(248UL, 6)) & (((safe_add_func_int16_t_s_s((g_208 > (((!((g_91 = (safe_lshift_func_int16_t_s_u((l_248 = ((p_56 != (~(7UL && (safe_mod_func_uint64_t_u_u((safe_rshift_func_uint8_t_u_s(((safe_sub_func_uint32_t_u_u(l_249, 0x79BA9FE9L)) & p_56), p_56)), g_188[g_151]))))) , 0L)), l_309))) , g_105[0][3][1])) == g_203) != (-7L))), 0x1CF7L)) <= p_56) != p_56)) >= l_310), 0x74B0L)) == l_204[3])))) , l_205[1]) ^ l_311[2]), 0L)) != p_56));
                        g_105[0][0][7] = (((g_15 ^ (l_310 = (l_313 = (l_311[1] & l_312)))) != (g_167 & (safe_sub_func_int8_t_s_s(p_56, 0UL)))) > (~(safe_mod_func_int8_t_s_s(l_204[2], l_249))));
                        l_268 = ((((l_328 = (safe_rshift_func_int16_t_s_s((((((((l_321 == (safe_rshift_func_int8_t_s_u(((0x22L <= (((g_188[g_151] && (g_324 = l_309)) , (p_56 == (safe_lshift_func_uint8_t_u_s(l_327, ((((p_56 > ((p_56 < p_56) == l_60)) <= g_124) | 0L) & p_56))))) != p_56)) && l_310), g_188[g_151]))) != l_310) == p_56) && 0x212ADDC4B2344DFELL) , g_188[0]) ^ 1L) == p_56), g_269))) ^ g_188[g_151]) && 0xC0084AF5CDD96B38LL) , 0xF9E2EB27L);
                    }
                    for (l_313 = 0; (l_313 <= 0); l_313 += 1)
                    {
                        int64_t l_351 = (-2L);
                        int i;
                        l_268 = (g_105[0][3][1] = (safe_lshift_func_int16_t_s_s(0x6852L, 11)));
                        if (g_188[l_313])
                            continue;

{
                    return g_28[6][1];
                }


g_76 = (((safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((((safe_add_func_int32_t_s_s((safe_sub_func_uint32_t_u_u((((l_328 = g_105[0][3][1]) > (safe_unary_minus_func_uint8_t_u(g_188[0]))) >= 0xE9L), (l_340 , (safe_unary_minus_func_int64_t_s(((p_56 < 0x324BC6540DECC855LL) < ((l_268 = (safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((((safe_rshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_u((((l_313 < ((g_152[0][0][2] < ((+7UL) == 0x54L)) || l_351)) == p_56) > 255UL), 11)), 6)) & p_56) > 0x99AFD36CL), l_309)), p_56))) & 1UL))))))), g_81[0])) | g_105[0][2][5]) ^ 0xEE80A6DD8FC0ECA9LL), 4)), 2)) , l_60) , g_93);

l_709 += 1;



l_310 = (0x3BL && (safe_sub_func_int64_t_s_s(p_56, (((safe_rshift_func_int16_t_s_u(l_205[0], (((safe_add_func_uint16_t_u_u(1UL, ((safe_add_func_uint16_t_u_u((g_381 = (g_81[0] , (((safe_rshift_func_int8_t_s_u((l_248 = (safe_rshift_func_int8_t_s_s((safe_sub_func_uint64_t_u_u((!((safe_rshift_func_uint8_t_u_u((((((safe_lshift_func_uint8_t_u_s((safe_sub_func_uint32_t_u_u(g_188[l_313], (((safe_add_func_uint16_t_u_u(l_83, (((((safe_lshift_func_uint16_t_u_s(((safe_add_func_int8_t_s_s(l_60, (g_276 = ((safe_rshift_func_int16_t_s_u(l_204[2], 12)) && 0L)))) | p_56), 4)) || g_203) , 65534UL) <= l_205[1]) == 0x13C4L))) >= l_309) , 0x6919A173L))), 2)) || (-5L)) & l_249) > 0x087DL) , p_56), 6)) > p_56)), 0x8F459F38E30C4F04LL)), 3))), 3)) <= 1UL) <= 6UL))), 1L)) | l_321))) , g_105[0][3][6]) , g_163))) & l_311[2]) >= l_310))));
                    }
                }
                else
                {
                    uint64_t l_422[4][10] = {{0xE9DBCF1DEF639776LL, 0xE9DBCF1DEF639776LL, 6UL, 0x797F1FA50CE07EB1LL, 0UL, 0x797F1FA50CE07EB1LL, 6UL, 0xE9DBCF1DEF639776LL, 0xE9DBCF1DEF639776LL, 6UL}, {0xE9DBCF1DEF639776LL, 0xE9DBCF1DEF639776LL, 6UL, 0x797F1FA50CE07EB1LL, 0UL, 0x797F1FA50CE07EB1LL, 6UL, 0xE9DBCF1DEF639776LL, 0xE9DBCF1DEF639776LL, 6UL}, {0xE9DBCF1DEF639776LL, 0xE9DBCF1DEF639776LL, 6UL, 0x797F1FA50CE07EB1LL, 0UL, 0x797F1FA50CE07EB1LL, 6UL, 0xE9DBCF1DEF639776LL, 0xE9DBCF1DEF639776LL, 6UL}, {0xE9DBCF1DEF639776LL, 0xE9DBCF1DEF639776LL, 6UL, 0x797F1FA50CE07EB1LL, 0UL, 0x797F1FA50CE07EB1LL, 6UL, 0xE9DBCF1DEF639776LL, 0xE9DBCF1DEF639776LL, 6UL}};
                    int i, j;
                    l_268 = p_56;
                    for (g_124 = (-3); (g_124 < 25); ++g_124)
                    {
                        int16_t l_398[4] = {0L, 0xC81DL, 0L, 0xC81DL};
                        uint64_t l_399 = 0xE6059952D4A45373LL;
                        int i;
                        g_76 = ((~(65533UL && (g_148 = p_56))) <= (((safe_mod_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(l_312, 1)) && ((p_56 , 247UL) != ((1L != (safe_rshift_func_uint16_t_u_s(((safe_lshift_func_uint16_t_u_s(((safe_unary_minus_func_int16_t_s(((l_83 || ((-2L) >= (safe_lshift_func_int8_t_s_s(((safe_sub_func_uint64_t_u_u((l_313 = 0UL), g_163)) , (-1L)), g_81[0])))) >= p_56))) < 0x24ADL), p_56)) == g_152[3][0][4]), l_204[2]))) >= 0xFEL))), g_81[0])) , l_398[0]) & l_399));
                        return g_28[3][6];
                    }
                    l_425 = (l_204[2] = ((safe_lshift_func_uint8_t_u_s(((g_81[0] != (((g_163 = (safe_lshift_func_uint16_t_u_u(l_404, (p_56 >= ((g_188[0] < (safe_mod_func_int8_t_s_s((l_424 = (safe_mod_func_uint64_t_u_u((safe_sub_func_uint64_t_u_u((((safe_lshift_func_uint16_t_u_s(((safe_rshift_func_uint8_t_u_s((safe_sub_func_int64_t_s_s((l_404 < 0x72E9L), (l_328 = ((l_312 != (p_56 <= (safe_sub_func_uint8_t_u_u((safe_unary_minus_func_int64_t_s((l_313 = (safe_lshift_func_uint16_t_u_s(((((g_188[0] >= l_309) , 0xEDL) || 0x19L) | (-7L)), l_422[1][7]))))), g_202)))) ^ 4294967295UL)))), 7)) , g_423), 1)) == 0xFB0D7E68L) > g_15), g_28[6][4])), l_204[1]))), g_151))) , l_422[1][7]))))) && 0x75871132302CAEB7LL) || g_105[0][3][1])) > 0xBDE2L), 0)) , p_56));
                }
                for (g_167 = 0; (g_167 >= 0); g_167 -= 1)
                {
                    int64_t l_441 = 0x3FFE5A35B0BF8C4FLL;
                    uint32_t l_481 = 0xE4CF94CDL;
                    int32_t l_484 = 7L;
                    int i;
                    if ((g_188[g_167] >= (safe_lshift_func_uint8_t_u_s((4294967289UL & 0x84C35385L), 1))))
                    {
                        int32_t l_442 = 0x7F010E22L;
                        int i;
                        l_204[g_167] = (g_188[g_167] , (((((safe_sub_func_int16_t_s_s(((safe_rshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(((+g_91) , (0xDA609329L && (g_203 && ((((safe_add_func_int8_t_s_s(0L, (safe_add_func_int64_t_s_s(((safe_unary_minus_func_uint8_t_u((g_124 == ((l_442 = (l_268 = ((((safe_unary_minus_func_int32_t_s(l_328)) >= p_56) == (((g_163 = 0xAD1099014910825BLL) >= g_28[6][1]) | g_188[g_167])) && l_441))) <= 0L)))) & g_188[g_167]), p_56)))) | l_60) && 0x07AAL) & g_148)))), 2)), g_381)) | p_56), g_28[4][7])) , 1UL) | 18446744073709551612UL) | g_202) != 0xE1C8C73883698E11LL));
                        g_105[0][3][1] = (safe_add_func_uint64_t_u_u((((0x2FL && g_167) != 2L) > (safe_mod_func_int32_t_s_s((safe_unary_minus_func_int8_t_s((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s(((p_56 > (safe_rshift_func_int8_t_s_u(0x2AL, 6))) == (safe_add_func_uint32_t_u_u((safe_rshift_func_int8_t_s_s(((0x2AL ^ ((safe_lshift_func_uint16_t_u_u(((l_204[g_167] = 0x37E8A922L) >= (((((g_208 < ((((l_425 = (safe_add_func_uint16_t_u_u((g_465 = (((((((((safe_rshift_func_uint8_t_u_s((0xF89B4838L < p_56), g_163)) , (-9L)) , g_152[1][0][5]) ^ 0x8D77F4ABL) , 255UL) <= p_56) , 0x93DBL) >= l_464) && 1L)), l_83))) >= 65529UL) > 0xBCL) == 0x541AL)) , 0UL) , (-1L)) >= l_404) <= g_188[g_167])), 8)) >= 0x6F1ECEA6L)) , p_56), p_56)), 0xA47657B2L))), 0x7DL)), 6)))), g_269))), g_151));
                    }
                    else
                    {
                        uint32_t l_478[2][10][7] = {{{0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}}, {{0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}, {0x226C8784L, 4294967295UL, 1UL, 1UL, 4294967295UL, 0x226C8784L, 4294967295UL}}};
                        int32_t l_479[7][1];
                        int i, j, k;

if (l_1051)
                    continue;


for (i = 0; i < 7; i++)
                        {
                            for (j = 0; j < 1; j++)
                                l_479[i][j] = (-5L);
                        }
                        l_204[0] = (safe_sub_func_uint8_t_u_u(((g_483[1] = (g_482[5][1][0] = (((((g_148 = p_56) , (safe_lshift_func_int8_t_s_u((-6L), 6))) , (((p_56 > ((g_91 , (((g_163 , (g_81[0] = (((safe_rshift_func_int16_t_s_u((0x21DA734FL ^ g_152[1][0][5]), 0)) ^ p_56) && ((safe_add_func_int8_t_s_s((l_480 = (((safe_mod_func_int8_t_s_s(((((safe_lshift_func_int16_t_s_s((l_478[1][3][5] = (g_148 = (l_248 = ((((0x5FF69825B7D2326DLL || g_93) == g_381) , (-1L)) < g_188[g_167])))), l_479[2][0])) == p_56) == p_56) <= g_93), p_56)) , 0x986FB326C4E58694LL) <= 0x54C03015EFFD0515LL)), 0xFDL)) , l_309)))) < p_56) , l_481)) < g_163)) > (-1L)) & l_205[1])) & g_91) , 0x5D87785CL))) > 4294967295UL), 0xDEL));
                        l_484 = (l_204[1] = (g_483[1] , p_56));
                    }
                    if ((l_484 = (((safe_mod_func_int8_t_s_s((((-6L) != ((~((safe_mod_func_int8_t_s_s(((((g_202 <= g_188[0]) < (((safe_sub_func_int8_t_s_s((l_480 <= ((((g_148 ^ (((safe_unary_minus_func_int32_t_s((1UL < (p_56 , (safe_lshift_func_int16_t_s_s(p_56, g_28[6][1])))))) && l_204[2]) | g_188[g_167])) ^ p_56) ^ p_56) & l_268)), l_481)) < p_56) <= p_56)) , 0x0640675FL) == g_276), p_56)) , l_404)) <= g_28[3][3])) != g_81[0]), g_105[0][7][5])) >= g_151) | 0xFA625486L)))
                    {
                        uint32_t l_497 = 0UL;
                        l_497 = g_203;
                        g_76 = (g_482[5][1][0] = (((l_425 = (((safe_rshift_func_int16_t_s_u((g_324 = (!((((1UL >= (l_204[3] = 246UL)) || (g_124 < (safe_sub_func_uint8_t_u_u((p_56 < (safe_mod_func_int8_t_s_s(((l_505 , (((((((((safe_lshift_func_uint8_t_u_s((safe_rshift_func_uint8_t_u_u((((((l_313 = p_56) != l_464) <= p_56) <= (!0L)) , p_56), 1)), l_481)) , g_203) != 0x57L) , 0x4C470BCAL) && g_28[6][1]) < g_511) <= (-3L)) , l_205[0]) && l_464)) != p_56), g_91))), 0x48L)))) && 65535UL) , l_481))), g_151)) & p_56) == l_512)) , g_203) , 0x3EAAD61CL));
                        g_76 = ((g_521 = ((safe_add_func_uint16_t_u_u((l_505 = (safe_rshift_func_int16_t_s_s(p_56, (p_56 < ((safe_add_func_uint64_t_u_u(0x7852BE3175C0B0B8LL, g_163)) != (l_204[2] > (g_519 = ((g_324 | l_481) == l_249)))))))), (g_520 = p_56))) && l_484)) == g_91);
                        if (p_56)
                            continue;
                    }
                    else
                    {
                        g_105[0][3][1] = ((0x9BL > (safe_sub_func_int32_t_s_s(0L, g_81[0]))) || g_152[4][0][5]);
                    }
                }
                for (g_167 = 9; (g_167 > 10); g_167++)
                {
                    int8_t l_544[3];
                    int8_t l_577 = 0x7DL;
                    int32_t l_616 = 0xC1C79E02L;
                    uint32_t l_625 = 0x1452E025L;
                    uint8_t l_667[6] = {0xAEL, 0xAEL, 251UL, 0xAEL, 0xAEL, 251UL};
                    int i;
                    for (i = 0; i < 3; i++)
                        l_544[i] = (-1L);
                    if ((safe_add_func_uint64_t_u_u(p_56, (l_313 = (safe_mod_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(p_56, 15)), ((p_56 == ((safe_sub_func_int64_t_s_s(1L, g_276)) | ((g_188[0] = 0xF1L) , (safe_sub_func_uint8_t_u_u(((p_56 , (safe_add_func_uint64_t_u_u(((safe_lshift_func_int8_t_s_s(((g_148 = (l_268 = (safe_rshift_func_int8_t_s_u((((((safe_lshift_func_int16_t_s_u((l_204[2] | p_56), p_56)) < 5L) == l_464) < l_544[2]) || 248UL), l_544[2])))) ^ 0x4BA0L), l_544[0])) < l_327), l_327))) , g_511), l_327))))) , l_512)))))))
                    {
                        uint64_t l_578 = 6UL;
                        int32_t l_580 = 8L;
                        l_561 = (safe_lshift_func_uint8_t_u_u((g_152[1][0][5] == (((safe_add_func_int16_t_s_s(l_328, (g_148 = (-8L)))) < ((l_560[3] = (l_313 = ((safe_sub_func_int32_t_s_s(l_205[0], (g_551 = g_163))) , (safe_add_func_int64_t_s_s((safe_lshift_func_uint16_t_u_u((~((!g_124) || (+((g_559 = (0xD5204E2C4A6525F3LL & (p_56 > ((18446744073709551609UL | g_276) ^ 0xA4DEL)))) , g_202)))), 2)), 0xEA2A0ABE1F7FABC3LL))))) && 1L)) != g_81[0])), 6));
                        l_480 = (p_56 != ((((safe_rshift_func_uint16_t_u_s((((((0x1E18A1B861DB024CLL <= ((safe_mod_func_int32_t_s_s(1L, ((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(0x1F24L, (l_268 = ((g_482[5][1][0] = ((l_578 = ((safe_mod_func_uint8_t_u_u(g_105[0][3][5], (safe_add_func_int64_t_s_s(p_56, (((g_482[5][1][3] && (((safe_sub_func_uint16_t_u_u((l_560[4] , ((l_83 = 0x8D4EE9B7L) < p_56)), g_559)) > l_311[2]) & g_576)) >= l_560[3]) == l_249))))) < l_577)) , l_505)) | l_404)))), l_327)) , g_208))) , 1L)) >= p_56) >= g_579) && 0x7E58L) < l_313), l_580)) , l_404) & g_579) ^ 0UL));
                        return l_249;
                    }
                    else
                    {
                        uint16_t l_602 = 0x8B8BL;
                        int32_t l_643 = 0x88E13076L;
                        int32_t l_644 = (-1L);

l_512 += 1;



l_268 = l_544[2];
                        g_482[6][1][1] = (((((safe_add_func_uint32_t_u_u((0x2D08F28484C2F172LL || ((p_56 != p_56) ^ ((+(safe_sub_func_int32_t_s_s(((safe_rshift_func_uint8_t_u_u(g_576, p_56)) <= (((safe_rshift_func_uint16_t_u_u((g_521 = (l_204[0] <= ((safe_lshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u(0x274EL, (safe_rshift_func_uint16_t_u_s((g_559 == p_56), 6)))), g_483[1])), p_56)), 5)) || g_163))), p_56)) || 65529UL) >= l_602)), g_91))) > g_483[0]))), p_56)) & l_424) , p_56) != l_425) == p_56);
                        g_76 = ((((safe_add_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((g_76 <= p_56), ((((((safe_add_func_int8_t_s_s(((safe_mod_func_uint64_t_u_u(18446744073709551615UL, l_611)) | (safe_add_func_uint64_t_u_u((safe_mod_func_uint32_t_u_u((l_616 = p_56), (safe_sub_func_int16_t_s_s((((g_81[0] != (safe_mod_func_int32_t_s_s(0L, (((((((((safe_mod_func_int32_t_s_s(((((((safe_sub_func_int16_t_s_s((l_83 = p_56), ((g_163 >= 0x8A92DB5FAC56BDEBLL) ^ 1L))) || p_56) <= l_602) | l_561) ^ g_551) & 18446744073709551614UL), l_424)) && 0xB9L) != l_625) >= l_312) || l_249) || 0xB052L) != p_56) , g_81[0]) || l_602)))) != 0L) ^ p_56), (-3L))))), l_313))), g_276)) ^ 0x5AL) , 18446744073709551610UL) == l_313) <= g_482[5][1][0]) <= 18446744073709551612UL))) > p_56), p_56)) , g_521) >= l_544[2]) >= p_56);
                        l_644 = ((safe_sub_func_uint32_t_u_u((((safe_lshift_func_int16_t_s_s((0x2060L || (!l_631)), (((safe_add_func_int64_t_s_s(g_520, ((0x5FCBL & ((l_643 = ((((((((safe_unary_minus_func_int64_t_s(p_56)) <= (l_480 = (((safe_mod_func_int16_t_s_s((l_425 = 0xC42EL), (safe_add_func_uint64_t_u_u((safe_add_func_int64_t_s_s((safe_rshift_func_int8_t_s_s((0x5340A894L && 0xA3C26A6CL), (((0UL > 1L) <= l_327) , 0x3AL))), (-5L))), g_105[0][3][1])))) , g_76) ^ p_56))) , 0x2996L) ^ 0x5023L) == 0UL) && l_60) != 1UL) , 0xE102D2CBL)) || g_148)) || l_544[0]))) , p_56) ^ 0x2735DC10L))) , l_544[2]) || g_482[5][1][0]), p_56)) | l_544[2]);
                    }
                    for (l_268 = 1; (l_268 > (-26)); l_268 = safe_sub_func_int32_t_s_s(l_268, 3))
                    {
                        l_654 = ((g_423 ^ 0x32DC191BL) != ((l_560[8] <= 0xD6FCL) && ((g_324 && ((!((safe_add_func_uint8_t_u_u(0x63L, (g_276 = (safe_mod_func_uint16_t_u_u((((((((safe_sub_func_uint64_t_u_u((g_483[2] != 0x6772530C57E0C540LL), g_576)) ^ p_56) < p_56) | g_576) != 0xB0BA164ECA27DCEELL) <= l_544[2]) == 0x0BFBL), 0x4AF3L))))) , g_28[6][1])) < l_328)) , g_163)));
                        l_654 = l_631;
                        l_425 = (l_248 & 0x13EE3A2FL);
                    }
                    for (l_268 = 0; (l_268 > 3); ++l_268)
                    {
                        int16_t l_666 = 3L;
                        g_482[6][0][2] = (((safe_add_func_int8_t_s_s((((l_328 = (((l_464 , (safe_rshift_func_uint16_t_u_s((safe_add_func_int8_t_s_s((g_465 = 7L), 1L)), 1))) , g_148) | (p_56 == p_56))) & (l_625 != ((l_313 = p_56) ^ (safe_lshift_func_int16_t_s_u((~l_577), l_666))))) , 0xA1L), p_56)) > g_324) ^ 0x48L);
                        l_505 = l_616;
                        return p_56;
                    }

if (g_188[l_625])
                            break;


l_667[5] = 0x04D6BC1CL;
                }
            }
        }
    }
    for (g_148 = 17; (g_148 > 6); g_148--)
    {
        int16_t l_673 = (-1L);
        int32_t l_674 = (-1L);
        int32_t l_679 = 0x78152AACL;
        int16_t l_691 = 0x053BL;
        int32_t l_692[4][9][3] = {{{0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}}, {{0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}}, {{0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}}, {{0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}, {0x41CC77B8L, 0x1C1CD64FL, 1L}}};
        int32_t l_693 = 1L;
        int8_t l_696 = 0L;
        int i, j, k;
        l_696 = (safe_sub_func_uint32_t_u_u((l_83 = ((+g_76) == (g_695 = (((((l_674 = (l_673 = g_188[0])) ^ (safe_mod_func_uint64_t_u_u((((((safe_mod_func_uint8_t_u_u((l_679 = (l_505 = (l_204[2] = p_56))), (((((safe_unary_minus_func_int64_t_s((p_56 & (g_579 = g_151)))) < p_56) <= ((safe_mod_func_uint32_t_u_u((safe_mod_func_int64_t_s_s((g_381 = (-4L)), (g_152[1][0][3] = (((l_693 = ((safe_lshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_u((l_692[3][2][2] = (l_691 & p_56)), 13)), 6)) <= 0UL)) == p_56) ^ l_691)))), g_208)) == g_694)) , 18446744073709551610UL) && l_692[3][2][2]))) & p_56) , 0x8A5D5AAC2DC8A8A7LL) != l_60) ^ l_691), p_56))) > g_148) == l_691) & 0xD98BL)))), 0x3FE65436L));
        return l_697;
    }
    g_105[0][6][5] = (g_482[0][2][0] = ((((((((l_505 = ((((((safe_sub_func_int32_t_s_s((safe_sub_func_int64_t_s_s((l_702 < ((l_424 >= (((safe_unary_minus_func_uint8_t_u(g_76)) , (safe_mod_func_uint64_t_u_u(18446744073709551615UL, l_505))) <= (g_694 == (((((((+((((g_188[0] = (((l_709 = (safe_sub_func_uint16_t_u_u(p_56, ((l_204[2] = ((l_83 = l_697) | ((((l_204[3] , p_56) && g_167) , p_56) , l_424))) , p_56)))) || g_559) & 0x917D6821A35EB76FLL)) != 0x00L) || g_208) , 0UL)) , g_91) , g_694) == p_56) > 0xB966C6247691C875LL) <= l_710[0]) <= 0x835EABDDL)))) <= 1UL)), p_56)), g_276)) >= l_60) , (-1L)) , l_505) <= p_56) <= p_56)) > 0xB4419068L) && p_56) , l_204[2]) != 0UL) || 0UL) | g_521) , p_56));
    if (((l_83 = 0xBF14L) && p_56))
    {
        int64_t l_716[9] = {0x55A2B29BF6B81BDCLL, 0x1BBAC604CC1C4531LL, 0x55A2B29BF6B81BDCLL, 0x1BBAC604CC1C4531LL, 0x55A2B29BF6B81BDCLL, 0x1BBAC604CC1C4531LL, 0x55A2B29BF6B81BDCLL, 0x1BBAC604CC1C4531LL, 0x55A2B29BF6B81BDCLL};
        int32_t l_717 = 1L;
        int32_t l_760[2];
        int8_t l_1082 = 0x5CL;
        int16_t l_1103 = 0x1C6BL;
        int32_t l_1104[8] = {2L, 0xF47D156AL, 2L, 0xF47D156AL, 2L, 0xF47D156AL, 2L, 0xF47D156AL};
        int i;
        for (i = 0; i < 2; i++)
            l_760[i] = 0xFACABC79L;
        for (g_203 = 0; (g_203 != 55); g_203 = safe_add_func_uint16_t_u_u(g_203, 2))
        {
            uint32_t l_727 = 0xAADA066DL;
            int32_t l_746 = 0x87C13F3AL;
            int32_t l_759 = 0L;
            int32_t l_761 = 0x34C308F3L;
            int16_t l_805 = 0x0EEAL;
            int8_t l_811 = 0xDEL;
            uint64_t l_818 = 0x21B74946A3D1B1F5LL;
            for (g_694 = 0; (g_694 > 24); g_694 = safe_add_func_uint16_t_u_u(g_694, 4))
            {
                int64_t l_718 = (-1L);
                l_718 = (((!g_152[1][0][5]) < l_204[3]) >= (l_717 = l_716[3]));
            }
            for (l_709 = 0; (l_709 <= 0); l_709 += 1)
            {
                int i;
                if (g_188[l_709])
                    break;
                if (g_188[l_709])
                    break;
                return g_81[l_709];
            }
            for (g_519 = 0; (g_519 == (-7)); --g_519)
            {
                uint32_t l_726 = 0xF59617DAL;
                int32_t l_744 = 8L;
                for (l_424 = (-8); (l_424 <= (-17)); l_424--)
                {
                    int16_t l_723 = (-7L);
                    int32_t l_732 = 0L;
                    int16_t l_740 = 8L;
                    uint32_t l_741 = 1UL;
                    l_723 = l_716[3];
                    for (g_324 = 0; (g_324 >= (-18)); g_324--)
                    {
                        l_717 = l_726;
                        l_717 = 9L;
                    }
                    l_746 = ((l_727 < (((l_744 = (safe_sub_func_int16_t_s_s(((safe_mod_func_int16_t_s_s((l_732 = g_483[1]), 0x72EDL)) | (l_743[0] = (g_148 <= (((safe_mod_func_uint32_t_u_u(((((safe_unary_minus_func_int16_t_s(((l_717 , (g_188[0] = 0xD2L)) || 255UL))) && ((((((l_740 = ((l_505 = (g_519 && ((((safe_mod_func_uint32_t_u_u((safe_add_func_uint16_t_u_u(65532UL, g_269)), g_482[5][1][0])) < p_56) >= l_717) | g_152[1][0][5]))) ^ 0x668B4341L)) | l_741) , p_56) <= 0xFC607107L) | l_742) || 0xEC93AEE8L)) <= p_56) ^ l_723), 0x41A3FE99L)) , l_726) & l_424)))), l_727))) != g_152[0][0][3]) > l_709)) , l_745);

l_742 += 1;



l_717 = g_747;
                }
                l_746 = l_716[3];
                g_579 = (((safe_mod_func_uint16_t_u_u((l_761 = (((g_576 | ((g_124 = l_744) & ((l_727 ^ (!0L)) == g_202))) ^ (safe_rshift_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s((p_56 & ((g_152[2][0][4] = (safe_add_func_int8_t_s_s((l_760[1] = (l_717 = ((l_746 = ((~(((g_758[0][2] ^ 5L) < ((((l_716[0] , p_56) > 0x0BL) == l_759) < l_742)) , p_56)) ^ l_759)) != 1L))), p_56))) > g_551)), p_56)), l_726))) > 0x6204L)), p_56)) > g_695) <= 0x3431L);
            }
            if ((0xBA6F9EA546B370B4LL <= g_483[1]))
            {
                uint32_t l_762 = 0x7B344F51L;
                int8_t l_763 = 0xB3L;
                int32_t l_788 = 0x65194C85L;
                int32_t l_873 = 0x428C1F9FL;
                if (g_576)
                {
                    int64_t l_781[7];
                    int32_t l_783 = 0L;
                    int32_t l_784 = 7L;
                    int32_t l_785 = (-10L);
                    uint32_t l_787[1];
                    int i;
                    for (i = 0; i < 7; i++)
                        l_781[i] = 0xCFD14D2385EB63F6LL;
                    for (i = 0; i < 1; i++)
                        l_787[i] = 0x0D13245AL;
                    if (p_56)
                    {
                        l_762 = p_56;
                    }
                    else
                    {
                        uint64_t l_780[6][8] = {{0xFCED28356902AA37LL, 0UL, 0UL, 3UL, 3UL, 0UL, 0UL, 0xFCED28356902AA37LL}, {0xFCED28356902AA37LL, 0UL, 0UL, 3UL, 3UL, 0UL, 0UL, 0xFCED28356902AA37LL}, {0xFCED28356902AA37LL, 0UL, 0UL, 3UL, 3UL, 0UL, 0UL, 0xFCED28356902AA37LL}, {0xFCED28356902AA37LL, 0UL, 0UL, 3UL, 3UL, 0UL, 0UL, 0xFCED28356902AA37LL}, {0xFCED28356902AA37LL, 0UL, 0UL, 3UL, 3UL, 0UL, 0UL, 0xFCED28356902AA37LL}, {0xFCED28356902AA37LL, 0UL, 0UL, 3UL, 3UL, 0UL, 0UL, 0xFCED28356902AA37LL}};
                        int32_t l_782 = 0x3CE08D65L;
                        int32_t l_786 = 0xEA4C4FE8L;
                        int i, j;
                        l_785 = ((((g_81[0] , ((l_784 = (((l_746 | ((l_204[2] = (l_763 = (g_482[5][1][0] , 8L))) , (safe_rshift_func_uint16_t_u_s((safe_mod_func_uint8_t_u_u((((((safe_sub_func_uint64_t_u_u((((safe_mod_func_uint64_t_u_u((safe_sub_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s((l_783 = (safe_lshift_func_uint8_t_u_u((l_782 = (safe_rshift_func_uint16_t_u_u((l_780[1][1] >= (g_105[0][3][1] = p_56)), (l_781[0] = (l_204[3] = g_151))))), l_702))), g_483[1])), l_780[2][0])), l_762)) & p_56) > 65535UL), g_203)) , g_105[0][5][1]) , g_124) < 1L) == g_15), l_709)), g_465)))) != g_269) <= 1L)) >= (-3L))) , l_780[5][2]) || l_782) ^ 255UL);
                        if (l_786)
                            break;
                        l_788 = (l_782 = (p_56 || l_787[0]));
                    }
                }
                else
                {
                    int16_t l_816 = 0x6A0DL;
                    int32_t l_817 = 0xCD7E4E01L;
                    int64_t l_895[1];
                    int i;
                    for (i = 0; i < 1; i++)
                        l_895[i] = 0x780FD5F574519E2ELL;
                    for (g_465 = 0; (g_465 < (-6)); g_465--)
                    {
                        uint16_t l_800 = 0x10E9L;
                        g_579 = ((safe_add_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_s(g_519, ((p_56 , (l_83 == (((0x9151FB835E603606LL != l_717) == p_56) & ((((safe_add_func_uint64_t_u_u((l_788 = (3UL ^ (((-1L) > (((safe_rshift_func_uint8_t_u_u(0x91L, p_56)) && g_324) != p_56)) && l_762))), 18446744073709551615UL)) , g_105[0][3][1]) > l_799) != g_15)))) , 2L))) ^ 4294967295UL) ^ l_762), l_762)) , l_800);
                    }
                    g_579 = (l_817 = (safe_lshift_func_int16_t_s_s((((((l_204[1] = (safe_mod_func_uint32_t_u_u((l_805 != (g_482[6][0][3] = (g_105[0][7][9] = g_148))), (safe_lshift_func_uint8_t_u_u((g_163 >= (safe_add_func_uint32_t_u_u(((((p_56 != (0x10661155156C69FELL || (l_760[1] = (((((0UL || (((!(((l_811 == ((safe_mod_func_uint8_t_u_u((l_799 > (g_423 = (((safe_mod_func_int8_t_s_s((g_465 = 0x72L), g_93)) != l_811) >= l_760[0]))), g_148)) > l_742)) == g_758[0][2]) < g_559)) , l_760[0]) < g_188[0])) , 0L) != p_56) < l_816) || g_148)))) , g_81[0]) == 0L) < p_56), 1L))), 6))))) < g_148) < 0xB0D4L) <= l_816) == 0x8AEF07D41DBF749CLL), 6)));

{
                uint32_t l_726 = 0xF59617DAL;
                int32_t l_744 = 8L;
                for (g_559 = (-8); (g_559 <= (-17)); g_559--)
                {
                    int16_t l_723 = (-7L);
                    int32_t l_732 = 0L;
                    int16_t l_740 = 8L;
                    uint32_t l_741 = 1UL;
                    l_723 = l_716[3];
                    for (l_816 = 0; (l_816 >= (-18)); l_816--)
                    {
                        g_1775 = l_726;
                        g_1775 = 9L;
                    }
                    i = ((g_3551 < (((l_744 = (safe_sub_func_int16_t_s_s(((safe_mod_func_int16_t_s_s((l_732 = g_2720[1]), 0x72EDL)) | (l_743[0] = (l_805 <= (((safe_mod_func_uint32_t_u_u(((((safe_unary_minus_func_int16_t_s(((g_1775 , (g_81[0] = 0xD2L)) || 255UL))) && ((((((l_740 = ((j = (g_1613 && ((((safe_mod_func_uint32_t_u_u((safe_add_func_uint16_t_u_u(65532UL, g_2151)), g_482[5][1][0])) < j) >= g_1775) | g_152[1][0][5]))) ^ 0x668B4341L)) | l_741) , j) <= 0xFC607107L) | l_742) || 0xEC93AEE8L)) <= j) ^ l_723), 0x41A3FE99L)) , l_726) & g_559)))), g_3551))) != g_152[0][0][3]) > l_83)) , l_742);
                    g_1775 = g_1016;
                }
                i = l_716[3];
                l_83 = (((safe_mod_func_uint16_t_u_u((g_167 = (((l_742 | ((g_1730 = l_744) & ((g_3551 ^ (!0L)) == g_93))) ^ (safe_rshift_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s((j & ((g_152[2][0][4] = (safe_add_func_int8_t_s_s((l_760[1] = (g_1775 = ((i = ((~(((g_758[0][2] ^ 5L) < ((((l_716[0] , j) > 0x0BL) == g_167) < l_742)) , j)) ^ g_167)) != 1L))), j))) > l_742)), j)), l_726))) > 0x6204L)), j)) > j) <= 0x3431L);
            }


l_818 = 0x079621B1L;
                    if (((!(safe_mod_func_uint32_t_u_u(g_76, (safe_add_func_int8_t_s_s((((l_727 , p_56) || g_188[0]) ^ ((1UL <= ((((0xE983L ^ (g_747 = l_717)) >= ((((l_746 = 8UL) <= p_56) > g_203) & g_91)) , l_716[1]) > p_56)) <= 0x43939D47L)), l_745))))) <= p_56))
                    {
                        int16_t l_826 = 0L;
                        l_204[1] = ((safe_rshift_func_int8_t_s_u(((0xBCL > (l_826 = l_743[0])) , l_818), 1)) ^ (safe_mod_func_uint32_t_u_u(g_269, ((safe_sub_func_int64_t_s_s((((safe_add_func_int16_t_s_s((((0xE65F8825L <= g_90) , p_56) | (((safe_sub_func_uint32_t_u_u(((g_81[0] = (safe_rshift_func_int8_t_s_s(((safe_sub_func_uint32_t_u_u((((safe_sub_func_uint8_t_u_u(251UL, (safe_lshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_s((((g_167 == l_697) >= 0xD8A3D08F8BA47D60LL) > g_482[5][1][0]), 10)), 1)))) < p_56) || p_56), 0xED089FA5L)) < l_805), p_56))) , l_760[1]), g_188[0])) != l_817) && l_763)), 65535UL)) >= p_56) != 0xBA98L), p_56)) , p_56))));
                        if (l_788)
                            continue;
                        g_76 = (l_760[0] = ((((safe_sub_func_uint32_t_u_u((safe_unary_minus_func_int32_t_s(((safe_add_func_int16_t_s_s((safe_unary_minus_func_uint64_t_u(p_56)), p_56)) != (safe_rshift_func_int16_t_s_u((l_817 = (((g_276 = (safe_rshift_func_int8_t_s_s((((p_56 ^ ((g_520 = ((safe_mod_func_int8_t_s_s((7UL >= ((g_90 <= (((safe_sub_func_int64_t_s_s(p_56, p_56)) && ((g_188[0] > (safe_rshift_func_int16_t_s_u(((safe_unary_minus_func_int16_t_s(((((~(((safe_add_func_int8_t_s_s((safe_lshift_func_int8_t_s_u(((safe_rshift_func_int8_t_s_s((((safe_lshift_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s(((g_875 = ((((l_873 = l_817) <= 1UL) | l_874) > g_324)) && g_747), 0x6F1DD5CBL)) != 65535UL), 11)) , p_56) != p_56), p_56)) < 0xFB8E971A54B7409DLL), 2)), (-7L))) ^ 0xA3L) , 1UL)) ^ l_763) >= g_482[6][2][2]) != p_56))) , p_56), l_760[1]))) ^ g_28[6][1])) > 0L)) == p_56)), g_148)) != p_56)) == l_760[1])) ^ p_56) || p_56), l_826))) != p_56) | 250UL)), g_152[1][0][5]))))), p_56)) , p_56) , g_559) && l_727));
                    }
                    else
                    {
                        uint64_t l_886[5];
                        int32_t l_896[8][4][7] = {{{1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}}, {{1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}}, {{1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}}, {{1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}}, {{1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}}, {{1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}}, {{1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}}, {{1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}, {1L, (-4L), 0xC27296FCL, 0xB3069B94L, 0xBEBEB32FL, 0x473C66A1L, 0xB3069B94L}}};
                        int32_t l_897 = 1L;
                        uint16_t l_914 = 0xB055L;
                        int i, j, k;
                        for (i = 0; i < 5; i++)
                            l_886[i] = 0UL;
                        if (g_188[0])
                            break;
                        g_482[4][0][0] = ((((safe_lshift_func_uint16_t_u_s(l_760[1], (safe_add_func_int64_t_s_s(((safe_lshift_func_int8_t_s_s((safe_sub_func_uint64_t_u_u(((l_897 = (safe_rshift_func_uint8_t_u_u((l_505 = (((p_56 = 1L) , (((l_896[6][2][3] = ((l_886[3] | ((g_188[0] = (safe_lshift_func_uint16_t_u_s(p_56, 13))) != (l_761 = (((safe_rshift_func_int8_t_s_u((-1L), (safe_mod_func_uint32_t_u_u(((p_56 != (((l_817 = ((safe_sub_func_uint32_t_u_u(((p_56 , 0x2A767632L) , (g_151 >= l_818)), l_895[0])) & l_873)) ^ g_276) <= p_56)) || p_56), g_152[1][0][2])))) > 0x2A08B5E7L) && 18446744073709551607UL)))) < l_745)) < p_56) | 0xCC15B6E2L)) >= l_760[0])), 1))) <= l_717), g_520)), 1)) ^ l_742), g_76)))) <= 1UL) || 0x51L) > 0x63FA1C54A34BEE36LL);
                        l_760[0] = ((l_505 = (safe_lshift_func_uint8_t_u_s(g_28[6][1], (((safe_add_func_uint64_t_u_u(7UL, (((p_56 < ((((safe_unary_minus_func_int16_t_s((l_816 != (g_694 & ((((safe_lshift_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s((g_28[1][0] | ((safe_unary_minus_func_uint32_t_u(1UL)) >= p_56)), (l_83 = ((safe_sub_func_int64_t_s_s((safe_lshift_func_int8_t_s_s((safe_sub_func_uint64_t_u_u((g_576 = (((((g_482[1][0][3] = 2L) , p_56) , 0x3D7BL) > l_83) != 2L)), 0x41EDE75E8785EEC6LL)), 7)), 0xBF0F0E22BC4BE7EALL)) >= g_188[0])))) != g_188[0]), 0)) != p_56) != g_519) | 4294967294UL))))) != l_811) | l_204[2]) , g_482[6][1][0])) == 1L) ^ g_483[1]))) < l_818) <= l_914)))) > p_56);
                        return p_56;
                    }
                }
            }
            else
            {
                uint32_t l_915 = 0x6F6D503EL;
                int32_t l_962 = (-8L);
                for (g_519 = 2; (g_519 >= 0); g_519 -= 1)
                {
                    uint32_t l_924 = 1UL;
                    int32_t l_928 = 0x1FC16E6EL;
                    int32_t l_941 = 0xA09E3757L;
                    for (g_381 = 2; (g_381 >= 0); g_381 -= 1)
                    {
                        int i;
                        g_482[3][1][2] = (g_483[g_519] == l_915);
                        g_105[0][3][1] = ((l_928 = (safe_lshift_func_int16_t_s_u(((safe_rshift_func_uint8_t_u_s(p_56, (p_56 , (safe_add_func_uint32_t_u_u(p_56, p_56))))) > (safe_add_func_int64_t_s_s((0x8BL != ((l_924 < (safe_rshift_func_uint16_t_u_s((+p_56), 11))) > g_152[0][0][3])), (l_760[1] = (l_743[0] , l_745))))), g_151))) && g_28[6][1]);
                        return g_91;
                    }
                    for (l_60 = 0; (l_60 <= 2); l_60 += 1)
                    {
                        g_76 = p_56;
                        if (g_202)
                            break;
                    }
                    if (p_56)
                        continue;

for (l_761 = 0; l_761 < 8; l_761++)
    {
        for (l_941 = 0; l_941 < 5; l_941++)
        {
            transparent_crc(g_952[l_761][l_941], "g_952[l_761][l_941]", l_941);
            if (l_941) printf("index = [%d][%d]\n", l_761, l_941);

        }
    };



for (l_805 = 0; (l_805 <= 2); l_805 += 1)
                    {
                        uint16_t l_939 = 0x6F6AL;
                        int64_t l_940 = 5L;
                        g_105[0][0][9] = (((l_941 = (g_124 = ((safe_add_func_int16_t_s_s((((safe_unary_minus_func_uint32_t_u((safe_add_func_uint64_t_u_u((g_758[8][1] , (l_818 , l_759)), (g_482[5][1][0] > ((l_928 = ((safe_sub_func_uint32_t_u_u((safe_unary_minus_func_int32_t_s((l_204[2] = ((((safe_mod_func_uint32_t_u_u(p_56, p_56)) < (((l_710[0] | g_579) , p_56) & p_56)) ^ l_939) || l_727)))), l_940)) || 0x2F82L)) , 0x5B35E8B7L)))))) < 0x337C9CAB4D216A8FLL) || 0xFFL), 0xFDCDL)) | 0xEFF80438L))) , l_746) != g_28[6][1]);
                        l_928 = (((safe_add_func_uint32_t_u_u(((((safe_add_func_uint8_t_u_u(((((safe_sub_func_uint8_t_u_u((l_915 , (((18446744073709551615UL & ((((l_83 = (0x02AD98B8CD3AB207LL < (p_56 != (l_915 , (((l_702 <= (65531UL >= (l_924 < 0xBCL))) || p_56) , 1L))))) != p_56) > p_56) == g_324)) >= p_56) != g_483[2])), p_56)) >= 0xAD5A7995L) == l_716[1]) != 1L), p_56)) && 0x3CAEF687L) == 0xC505F204545F499BLL) | 1L), g_152[1][0][5])) > p_56) != p_56);
                        g_76 = ((l_962 = (safe_lshift_func_int16_t_s_u((0x70AFL | ((l_928 = (((((p_56 < (g_482[0][1][1] = g_167)) != (l_746 = p_56)) <= 0x7322L) >= (-3L)) | (g_952[4][2] > (g_465 = ((safe_sub_func_uint64_t_u_u((safe_lshift_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_s(((+(safe_sub_func_uint32_t_u_u(5UL, (p_56 | g_521)))) || l_761), 11)) | p_56), g_269)), g_188[0])) == p_56))))) <= g_952[0][1])), 4))) & g_521);
                        return g_152[3][0][1];
                    }
                }
                return p_56;
            }
        }
        for (g_579 = (-28); (g_579 < 8); g_579++)
        {
            int32_t l_978 = (-1L);
            int32_t l_979 = (-7L);
            int32_t l_1052 = (-1L);
            for (g_93 = 0; (g_93 < (-8)); g_93 = safe_sub_func_int8_t_s_s(g_93, 1))
            {
                int8_t l_977 = 0x4DL;
                int32_t l_980[5][3] = {{0x226B4520L, 0x226B4520L, 0L}, {0x226B4520L, 0x226B4520L, 0L}, {0x226B4520L, 0x226B4520L, 0L}, {0x226B4520L, 0x226B4520L, 0L}, {0x226B4520L, 0x226B4520L, 0L}};
                int32_t l_1011 = 0L;
                int32_t l_1025[8] = {0x78E03790L, 0x530A5FC8L, 0x78E03790L, 0x530A5FC8L, 0x78E03790L, 0x530A5FC8L, 0x78E03790L, 0x530A5FC8L};
                int64_t l_1026 = (-3L);
                int i, j;
                for (l_83 = (-24); (l_83 == (-22)); l_83 = safe_add_func_uint16_t_u_u(l_83, 2))
                {
                    int32_t l_989[4] = {0x6DBBF7C7L, 0L, 0x6DBBF7C7L, 0L};
                    uint32_t l_990 = 0x19505724L;
                    int32_t l_999 = 0x97B219EFL;
                    int i;
                    l_980[0][1] = ((safe_add_func_uint16_t_u_u(((((safe_sub_func_int32_t_s_s(p_56, (0UL | (safe_mod_func_uint64_t_u_u(0xD8571B6259CE1B06LL, (safe_mod_func_int8_t_s_s(((g_276 < (((p_56 != (l_977 > ((l_979 = (g_28[6][1] & l_978)) > (l_717 ^ l_745)))) & 1UL) != 0x3431L)) <= l_717), 0x46L))))))) & l_977) & 248UL) && l_716[3]), 0x2F0DL)) , g_952[4][3]);
                    for (g_521 = 12; (g_521 == 19); ++g_521)
                    {
                        int16_t l_1004 = 0x2FCDL;
                        int32_t l_1017[7];
                        int32_t l_1024 = 0x1C9A42C6L;
                        int i;
                        for (i = 0; i < 7; i++)
                            l_1017[i] = (-1L);
                        g_482[5][1][0] = (((4294967293UL == (safe_lshift_func_int8_t_s_s((l_760[1] = (safe_lshift_func_int8_t_s_u((l_999 = ((safe_add_func_int64_t_s_s((((((((l_989[1] , l_990) > (0xE3L == ((+((((0x9F81L == l_743[0]) > (g_105[0][3][1] = g_381)) & (l_989[1] != ((~(((((((safe_sub_func_int64_t_s_s((((g_188[0] | 0xFC1562FEL) > 0L) , g_423), l_989[0])) != g_151) >= 0xC339BD7A3AFA68A0LL) > g_520) | p_56) != g_483[0]) , l_743[0])) , 0UL))) | 0xDDL)) <= p_56))) | 1L) , g_758[3][3]) == 0xCD9B57338EF1AADCLL) && 0x9D22F8DA05BE2A12LL) ^ 0x835AB7C1F7D1E15ALL), l_980[4][0])) < p_56)), 6))), p_56))) , l_978) ^ p_56);
                        g_105[0][7][1] = ((g_579 & ((safe_add_func_uint64_t_u_u(0xE577EB664C4E12CDLL, (((0x9B69L || 0x0686L) >= (((((safe_lshift_func_int16_t_s_u(l_1004, 10)) != (l_999 = ((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((((safe_lshift_func_int16_t_s_u((l_1011 = g_324), ((p_56 & (l_979 < g_163)) == l_977))) == 0L) , 1UL), 7)), l_978)) > g_90))) & g_202) < g_90) & 0x76AB82568F8C0618LL)) & (-6L)))) == p_56)) ^ 0xEADB1892F10404A2LL);
                        g_76 = ((l_980[0][2] <= (safe_sub_func_uint64_t_u_u(g_423, ((l_1017[4] = (g_1016 = (safe_lshift_func_int16_t_s_u((((0x608B29F4FD807FF4LL < p_56) || p_56) , l_979), 9)))) > ((safe_add_func_uint8_t_u_u(g_483[1], ((+(safe_lshift_func_uint8_t_u_u((l_1024 = (g_324 >= g_1023[1][4][5])), 1))) , l_999))) ^ l_1025[6]))))) , 1L);
                    }
                }
                if (g_105[0][5][2])
                    break;
                g_105[0][3][1] = l_1026;
            }
            l_1052 = ((safe_lshift_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u(((g_152[2][0][1] , ((safe_rshift_func_uint16_t_u_u((((l_979 = ((safe_mod_func_int16_t_s_s(((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u((safe_add_func_uint16_t_u_u(65534UL, g_28[6][1])), (((safe_sub_func_int32_t_s_s((safe_lshift_func_int8_t_s_s((-10L), 5)), (safe_sub_func_int16_t_s_s((((((safe_rshift_func_int16_t_s_s((safe_mod_func_int8_t_s_s((g_465 = (((((l_60 , g_202) , p_56) ^ (g_324 = ((0xA1F58BA7L > l_979) || 0x313A4F115575B18CLL))) && l_204[2]) == g_15)), g_483[1])), l_709)) < 0x07B8E2E3L) , g_203) , 2UL) , l_978), 0x39B2L)))) >= l_979) || l_716[5]))), 14)) , l_743[0]), p_56)) ^ g_148)) < l_978) < l_710[3]), 13)) != l_1051)) , 0x0DL), 2)), p_56)) , l_978);
            if (l_743[0])
                continue;
        }
        if (p_56)
        {
            int32_t l_1053 = 0xD6CA0CCBL;
            g_105[0][2][3] = (0x214E3661L & (l_1053 = 0x4088C32DL));
        }
        else
        {
            uint32_t l_1071 = 3UL;
            int32_t l_1080[8] = {9L, 0xFC4A7E6DL, 9L, 0xFC4A7E6DL, 9L, 0xFC4A7E6DL, 9L, 0xFC4A7E6DL};
            int32_t l_1081 = (-1L);
            int32_t l_1083 = 0L;
            int32_t l_1084 = 0L;
            int i;
            l_1084 = (0x3734L ^ (((safe_sub_func_uint32_t_u_u(((safe_rshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_u((l_1083 = (((l_717 = (safe_add_func_uint64_t_u_u(g_423, (safe_mod_func_uint64_t_u_u(((g_952[4][2] || (safe_rshift_func_uint8_t_u_u(((!((7L <= (((safe_mod_func_int64_t_s_s((l_1081 = (l_1082 = ((((l_1071 = (safe_lshift_func_uint16_t_u_s(g_148, 0))) == (0x6585E20CL >= (l_760[0] = (0x4CL & (safe_rshift_func_uint8_t_u_s((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_u(((l_1080[1] = ((safe_lshift_func_int8_t_s_s(l_1080[2], 4)) <= ((0L && l_1080[1]) != l_709))) >= 65526UL), g_747)), l_1081)), 2)))))) != (-1L)) != g_875))), 18446744073709551615UL)) , p_56) ^ 7L)) ^ 2UL)) , g_188[0]), p_56))) ^ g_952[0][4]), 0x6B1102F9BDC1C0FBLL))))) == g_148) ^ 0xA0DA3876E6941BE8LL)), p_56)), p_56)) , 8UL), g_124)) > 0x7743L) , l_760[1]));
        }
        g_579 = (l_1104[7] = (l_717 = (g_381 < (((safe_mod_func_int16_t_s_s(0x88A2L, 0xF134L)) & ((safe_rshift_func_uint8_t_u_u((l_760[1] = ((safe_lshift_func_uint8_t_u_u((g_124 <= (safe_rshift_func_int16_t_s_u(((safe_sub_func_int16_t_s_s((safe_rshift_func_int8_t_s_s((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_u(((safe_sub_func_int64_t_s_s(l_799, ((l_505 = (l_204[2] = (0x9719L ^ 0x0664L))) > 1UL))) < (l_1103 > 1UL)), g_758[0][2])), 0xDABF31EAL)), 2)), l_760[1])) | g_381), 10))), p_56)) <= 4294967295UL)), g_28[6][1])) && l_760[1])) <= g_952[5][1]))));
    }
    else
    {
        int16_t l_1105 = (-2L);
        uint32_t l_1125 = 0x142F56D6L;
        int16_t l_1172[9];
        int32_t l_1174[9];
        uint32_t l_1241 = 18446744073709551615UL;
        int32_t l_1307 = 0xEF5721ABL;
        int32_t l_1308 = 0x462A3636L;
        int32_t l_1309 = 0x70FE1D24L;
        int8_t l_1310 = 0xD9L;
        int32_t l_1321 = 0xA651263FL;
        uint64_t l_1324 = 0x03ECD761DAC5A2BALL;
        int i;
        for (i = 0; i < 9; i++)
            l_1172[i] = 0x87C5L;
        for (i = 0; i < 9; i++)
            l_1174[i] = (-4L);
        if (((l_1105 = p_56) > (~((l_505 = 0x53E2D692359C8067LL) && 0xDAC381D76D5AB3F1LL))))
        {
            uint16_t l_1123 = 65535UL;
            int32_t l_1136 = (-1L);
            uint32_t l_1170 = 0xE226A18BL;
            int32_t l_1209 = 1L;
            for (g_695 = 0; (g_695 != 4); ++g_695)
            {
                uint8_t l_1122[6][7] = {{0xABL, 0xABL, 0x2BL, 0UL, 253UL, 0xE7L, 246UL}, {0xABL, 0xABL, 0x2BL, 0UL, 253UL, 0xE7L, 246UL}, {0xABL, 0xABL, 0x2BL, 0UL, 253UL, 0xE7L, 246UL}, {0xABL, 0xABL, 0x2BL, 0UL, 253UL, 0xE7L, 246UL}, {0xABL, 0xABL, 0x2BL, 0UL, 253UL, 0xE7L, 246UL}, {0xABL, 0xABL, 0x2BL, 0UL, 253UL, 0xE7L, 246UL}};
                int32_t l_1124[8][9] = {{0xA2B1CC77L, 1L, 0x7BB23200L, 0x7BB23200L, 1L, 0xA2B1CC77L, 0x93D3279FL, 1L, 0xDC0FDE25L}, {0xA2B1CC77L, 1L, 0x7BB23200L, 0x7BB23200L, 1L, 0xA2B1CC77L, 0x93D3279FL, 1L, 0xDC0FDE25L}, {0xA2B1CC77L, 1L, 0x7BB23200L, 0x7BB23200L, 1L, 0xA2B1CC77L, 0x93D3279FL, 1L, 0xDC0FDE25L}, {0xA2B1CC77L, 1L, 0x7BB23200L, 0x7BB23200L, 1L, 0xA2B1CC77L, 0x93D3279FL, 1L, 0xDC0FDE25L}, {0xA2B1CC77L, 1L, 0x7BB23200L, 0x7BB23200L, 1L, 0xA2B1CC77L, 0x93D3279FL, 1L, 0xDC0FDE25L}, {0xA2B1CC77L, 1L, 0x7BB23200L, 0x7BB23200L, 1L, 0xA2B1CC77L, 0x93D3279FL, 1L, 0xDC0FDE25L}, {0xA2B1CC77L, 1L, 0x7BB23200L, 0x7BB23200L, 1L, 0xA2B1CC77L, 0x93D3279FL, 1L, 0xDC0FDE25L}, {0xA2B1CC77L, 1L, 0x7BB23200L, 0x7BB23200L, 1L, 0xA2B1CC77L, 0x93D3279FL, 1L, 0xDC0FDE25L}};
                int i, j;
                g_482[5][1][0] = ((l_1125 = (((safe_unary_minus_func_int8_t_s((safe_rshift_func_uint16_t_u_s(((((g_1023[2][3][2] || p_56) == p_56) | g_105[0][3][1]) | (l_1124[2][8] = (+((safe_lshift_func_uint8_t_u_s((g_952[4][2] = (safe_lshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s((l_1123 = ((1UL || p_56) ^ ((safe_mod_func_uint32_t_u_u(g_1016, ((g_519 = ((g_1121 = ((6UL <= l_1105) > g_483[1])) | p_56)) || g_167))) > l_1122[0][3]))), l_1122[0][3])), p_56))), 2)) == 8UL)))), g_483[2])))) | p_56) > p_56)) & (-1L));
                g_579 = (g_482[6][2][3] = (0L && (safe_rshift_func_int8_t_s_s(((((safe_sub_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s(p_56, l_1136)), ((safe_sub_func_uint16_t_u_u(((safe_add_func_int64_t_s_s(l_799, (safe_sub_func_uint16_t_u_u(l_1123, (((safe_add_func_uint32_t_u_u(g_105[0][3][1], 0L)) >= (((l_1145 = 0x20573342L) , (safe_mod_func_uint8_t_u_u((p_56 & p_56), g_152[1][0][5]))) != 0x7D2BL)) >= 0xA37A1781B40E6268LL))))) , l_1125), g_423)) , p_56))), p_56)) || p_56), p_56)) , p_56) == 0x40L) ^ p_56), g_188[0]))));
            }
            for (l_505 = 2; (l_505 >= 0); l_505 -= 1)
            {
                uint32_t l_1171 = 0x0807037DL;
                int32_t l_1182 = 0L;
                int i;
                l_1174[2] = (((safe_mod_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(((l_1136 = (((0x8424A6F0L >= g_483[l_505]) <= (+((g_482[2][1][0] = (((safe_lshift_func_int16_t_s_s(0x3AC9L, (((((safe_lshift_func_uint16_t_u_u(((0x03BBL > (((safe_mod_func_int16_t_s_s((~(safe_mod_func_int64_t_s_s((((((safe_add_func_int32_t_s_s((((((l_1051 > (safe_lshift_func_uint8_t_u_u(g_952[6][3], (safe_add_func_uint8_t_u_u(255UL, g_483[l_505]))))) , (p_56 >= (-1L))) >= p_56) || g_1023[1][4][5]) == g_152[1][0][5]), p_56)) ^ p_56) && l_1170) , l_1105) & l_1171), g_483[l_505]))), l_745)) ^ g_694) > p_56)) || l_1105), 9)) <= g_105[0][3][6]) | g_167) ^ 0x8E6D9C0DL) || l_1172[0]))) != p_56) | l_1173)) & p_56))) , 0UL)) , p_56), l_204[1])), p_56)) != g_167), 0xF06DL)) < g_747) | 0x5BL);
                for (g_875 = 0; (g_875 >= 0); g_875 -= 1)
                {
                    int8_t l_1201 = 7L;
                    int32_t l_1207 = 9L;
                    int32_t l_1208 = 1L;
                    uint32_t l_1210 = 0x26FAB7A0L;
                    int32_t l_1211 = 0x923F3631L;
                    uint32_t l_1216[4] = {9UL, 0x29B5EB43L, 9UL, 0x29B5EB43L};
                    int i;
                    if ((((+(safe_rshift_func_uint8_t_u_s(((((safe_add_func_int16_t_s_s((p_56 != (safe_add_func_uint32_t_u_u((l_1182 = 0xE890371EL), p_56))), l_1171)) && g_28[6][1]) || ((safe_mod_func_int8_t_s_s(p_56, (0UL | (l_1136 = g_188[0])))) != (safe_mod_func_uint8_t_u_u(g_90, g_203)))) , p_56), 6))) , g_324) && g_203))
                    {
                        return p_56;
                    }
                    else
                    {
                        uint32_t l_1193[6][8] = {{0x7F110394L, 7UL, 0x7F110394L, 7UL, 0x7F110394L, 7UL, 0x7F110394L, 7UL}, {0x7F110394L, 7UL, 0x7F110394L, 7UL, 0x7F110394L, 7UL, 0x7F110394L, 7UL}, {0x7F110394L, 7UL, 0x7F110394L, 7UL, 0x7F110394L, 7UL, 0x7F110394L, 7UL}, {0x7F110394L, 7UL, 0x7F110394L, 7UL, 0x7F110394L, 7UL, 0x7F110394L, 7UL}, {0x7F110394L, 7UL, 0x7F110394L, 7UL, 0x7F110394L, 7UL, 0x7F110394L, 7UL}, {0x7F110394L, 7UL, 0x7F110394L, 7UL, 0x7F110394L, 7UL, 0x7F110394L, 7UL}};
                        int32_t l_1202 = 0xBAB7F0D6L;
                        int i, j;
                        l_1187[6][0] = p_56;
                        g_105[0][4][0] = p_56;
                        l_1202 = (~(safe_mod_func_int16_t_s_s((((g_324 , p_56) , (((l_1174[2] = (((((safe_add_func_int16_t_s_s(((l_1193[4][4] > (((safe_add_func_uint16_t_u_u(0x93D9L, (g_482[5][1][0] , ((safe_sub_func_uint64_t_u_u(((safe_lshift_func_int8_t_s_s((((g_1121 ^ (l_1136 , ((((0x4BDAA3FBL ^ 0L) ^ l_1200[0][0][2]) >= g_93) == 0UL))) > g_152[1][0][5]) ^ g_28[4][3]), 4)) , g_188[0]), p_56)) , l_1201)))) > 250UL) >= p_56)) , l_1145), p_56)) , l_1105) , p_56) && 0xE1E7B4D0E9F73634LL) && p_56)) & p_56) , 0x8F52L)) != p_56), g_559)));
                    }
                    if (g_483[1])
                        continue;
                    if ((g_483[1] < (((-4L) >= 0x3308L) ^ ((l_1211 = (0xB1441BD3444F1E8DLL && (g_152[4][0][3] = ((((l_709 = (((g_579 , ((safe_mod_func_int64_t_s_s(((l_1209 = ((!(l_1174[8] = ((((l_1208 = ((l_1207 = (((((l_1136 = (0x59DA5CE29605EA60LL & 0xE78F8AEC27711922LL)) | ((((l_1206 = (g_152[1][0][5] | l_1201)) || g_576) ^ 0x4BDFF392L) && 0xEBL)) < p_56) && g_208) > g_521)) ^ l_1201)) , 0L) , 0x3AL) | p_56))) >= p_56)) , g_105[0][8][5]), l_1201)) , g_269)) || l_1210) == g_124)) , l_1172[0]) ^ p_56) && 0x856574B1L)))) , (-10L)))))
                    {
                        l_1209 = 1L;
                        g_579 = ((safe_add_func_int16_t_s_s((((((safe_lshift_func_uint8_t_u_u(0x2BL, 7)) , 1UL) >= (g_483[1] , ((l_1174[2] = (1L && p_56)) || g_93))) > (g_423 < l_1216[2])) < ((g_747 = (~(+(0x360FL < g_324)))) , l_1171)), g_76)) || 7L);
                        l_1182 = l_83;
                    }
                    else
                    {
                        l_1182 = (g_579 = p_56);
                    }
                    for (g_747 = 0; (g_747 <= 0); g_747 += 1)
                    {
                        uint32_t l_1219 = 4294967288UL;
                        int i, j, k;
                        l_1219 = (0x69FE8BBAL < 0x0DD4834AL);
                        return g_152[l_505][g_875][l_505];
                    }
                }
            }
            if (g_482[5][1][0])
            {
                int8_t l_1231[2];
                int32_t l_1233 = 0x7E5C9CF8L;
                int32_t l_1260 = 0x49F5DF84L;
                int32_t l_1261[5][2][10] = {{{0L, 0x14325CF0L, (-2L), 0L, 1L, 0L, (-2L), 0x14325CF0L, 0L, (-3L)}, {0L, 0x14325CF0L, (-2L), 0L, 1L, 0L, (-2L), 0x14325CF0L, 0L, (-3L)}}, {{0L, 0x14325CF0L, (-2L), 0L, 1L, 0L, (-2L), 0x14325CF0L, 0L, (-3L)}, {0L, 0x14325CF0L, (-2L), 0L, 1L, 0L, (-2L), 0x14325CF0L, 0L, (-3L)}}, {{0L, 0x14325CF0L, (-2L), 0L, 1L, 0L, (-2L), 0x14325CF0L, 0L, (-3L)}, {0L, 0x14325CF0L, (-2L), 0L, 1L, 0L, (-2L), 0x14325CF0L, 0L, (-3L)}}, {{0L, 0x14325CF0L, (-2L), 0L, 1L, 0L, (-2L), 0x14325CF0L, 0L, (-3L)}, {0L, 0x14325CF0L, (-2L), 0L, 1L, 0L, (-2L), 0x14325CF0L, 0L, (-3L)}}, {{0L, 0x14325CF0L, (-2L), 0L, 1L, 0L, (-2L), 0x14325CF0L, 0L, (-3L)}, {0L, 0x14325CF0L, (-2L), 0L, 1L, 0L, (-2L), 0x14325CF0L, 0L, (-3L)}}};
                int32_t l_1262 = 0xACF9F31BL;
                int i, j, k;
                for (i = 0; i < 2; i++)
                    l_1231[i] = 0xB8L;
                l_1233 = (((l_1231[0] = (g_81[0] != ((safe_rshift_func_uint16_t_u_u((l_204[3] = g_163), (0xB9C75BB78334736ALL & (((((safe_rshift_func_int16_t_s_s((~(safe_rshift_func_int16_t_s_u((((g_519 != (safe_sub_func_int16_t_s_s(1L, (((g_576 = (g_423 , 0x05D905D1614561FELL)) != (((g_482[0][1][3] = (safe_add_func_int16_t_s_s((4L ^ 0x53L), g_93))) <= 7L) | p_56)) ^ l_1209)))) || 9UL) && l_1105), g_188[0]))), g_952[6][2])) == 0xBB22684DL) , l_1051) < 0x82BD050476F7B5F9LL) || p_56)))) | l_1174[2]))) >= l_1232) || p_56);
                g_105[0][3][1] = ((safe_sub_func_uint8_t_u_u(p_56, (((((g_482[5][1][0] = (l_1236 = g_381)) & 0xFE5D168EL) & (safe_sub_func_int16_t_s_s((0xABL > ((g_81[0] > 1UL) || (5L == (p_56 && (safe_sub_func_int64_t_s_s(g_91, 0xD33159AB5EAB222ELL)))))), l_1241))) , l_1105) && 0x1EL))) , p_56);
                l_1262 = (safe_lshift_func_int16_t_s_u((l_1261[2][0][1] = (safe_rshift_func_uint8_t_u_s((g_203 = ((l_1174[2] = (p_56 | (0xF0CCL == (safe_lshift_func_uint8_t_u_s((((g_124 = ((l_1260 = ((p_56 >= (safe_sub_func_uint32_t_u_u((l_1233 = (safe_mod_func_uint32_t_u_u(g_1023[0][3][7], (safe_sub_func_uint64_t_u_u(p_56, (((safe_lshift_func_int16_t_s_u((((safe_mod_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s(g_105[0][3][0], g_758[0][3])) == p_56), g_91)) | g_952[4][2]) & g_28[6][1]), p_56)) ^ 0x80E90788L) & 0xC994E7D4L)))))), l_1174[2]))) >= l_1174[2])) | g_81[0])) | g_28[2][8]) != l_1231[0]), g_163))))) | 65535UL)), 3))), 2));
            }
            else
            {
                l_1136 = 0x07268604L;
            }
        }
        else
        {
            uint16_t l_1272 = 65535UL;
            int32_t l_1289[1][4] = {{0xD1AA792EL, 1L, 0xD1AA792EL, 1L}};
            int32_t l_1290 = 0xD0DE670EL;
            int32_t l_1291 = 0x743F6940L;
            int i, j;
            for (g_1121 = 13; (g_1121 != 21); ++g_1121)
            {
                int32_t l_1287[8][3] = {{0xD0DEA817L, 1L, 0x10F07832L}, {0xD0DEA817L, 1L, 0x10F07832L}, {0xD0DEA817L, 1L, 0x10F07832L}, {0xD0DEA817L, 1L, 0x10F07832L}, {0xD0DEA817L, 1L, 0x10F07832L}, {0xD0DEA817L, 1L, 0x10F07832L}, {0xD0DEA817L, 1L, 0x10F07832L}, {0xD0DEA817L, 1L, 0x10F07832L}};
                int i, j;
                l_1174[2] = (safe_add_func_int16_t_s_s((((!((safe_add_func_uint32_t_u_u((246UL >= p_56), (safe_lshift_func_int8_t_s_u((l_1272 = p_56), (l_204[2] = (+(safe_rshift_func_uint16_t_u_s((((safe_add_func_int64_t_s_s((l_1290 = (((((safe_lshift_func_uint8_t_u_u(((((safe_unary_minus_func_int8_t_s((((l_709 = (safe_sub_func_uint32_t_u_u(0xDCFF4939L, ((safe_rshift_func_uint8_t_u_u(250UL, (l_1289[0][1] = (safe_lshift_func_uint8_t_u_u(((l_1172[1] & l_1287[3][2]) , p_56), (g_81[0] = ((+(g_952[0][2] != 255UL)) < g_695))))))) >= p_56)))) > l_1290) , g_81[0]))) ^ p_56) | 0x3EL) | p_56), p_56)) <= g_579) && p_56) , 254UL) || 0x11L)), g_551)) , 0x4353L) || g_423), p_56)))))))) > 9UL)) , 0UL) > l_1291), p_56));
            }
            l_204[2] = (safe_sub_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u(g_28[2][4], 8)), 13)), (18446744073709551610UL ^ ((g_482[5][1][0] && (((l_1289[0][1] = ((l_1272 == p_56) > ((0UL ^ g_276) , ((safe_rshift_func_uint16_t_u_u(((((l_204[2] & (l_1310 = ((((l_1309 = (safe_add_func_uint32_t_u_u((l_1308 = (!((((((l_1307 = (l_1174[8] = (safe_mod_func_uint64_t_u_u((safe_mod_func_uint64_t_u_u(0x278E5175941960F7LL, g_519)), p_56)))) != g_76) >= l_1272) < (-8L)) || g_423) ^ p_56))), p_56))) , l_1174[7]) != l_1241) >= g_188[0]))) , 0x40BC073DL) >= g_81[0]) , 0xB522L), 10)) != g_105[0][7][7])))) , 0x65L) == 8L)) <= p_56))));
            for (g_695 = 1; (g_695 <= 8); g_695 += 1)
            {
                int i;
                g_482[5][1][0] = (safe_add_func_int64_t_s_s((safe_add_func_uint32_t_u_u(4294967288UL, ((0x43761EBC0140EA69LL ^ 1UL) > ((l_710[g_695] , ((safe_rshift_func_uint8_t_u_u((safe_mod_func_int16_t_s_s(((0xDAL > (safe_rshift_func_int16_t_s_s(((((l_1290 = (l_710[g_695] < ((((l_1321 != (safe_sub_func_int64_t_s_s(p_56, ((l_1324 >= p_56) <= 0xF1356B65L)))) , l_1125) == p_56) , g_747))) , g_81[0]) , g_28[5][5]) > 0x5A0B2650L), 11))) && p_56), 65532UL)), 1)) == p_56)) | 0xC9L)))), 0x03D27E7128917FEFLL));
            }
        }
        g_579 = ((((g_208 != (safe_add_func_uint64_t_u_u(((safe_rshift_func_int8_t_s_u((l_709 = (safe_sub_func_uint8_t_u_u((l_204[2] = g_188[0]), (l_1307 == l_1324)))), 6)) && ((((safe_mod_func_int8_t_s_s(((((l_1307 = (g_1016 = (((5L <= (safe_sub_func_int64_t_s_s((1UL | g_576), ((g_423 != (l_1309 = ((l_1105 < p_56) < 0x6677A1833A4AEC9BLL))) & 0xE6EA7B67E45D921ALL)))) & l_1241) != p_56))) < p_56) != g_188[0]) , l_1187[6][0]), g_579)) != 0xA2ACC0FBL) >= 5UL) < 1UL)), l_745))) , p_56) & g_152[2][0][1]) , g_483[1]);
    }
    return l_1173;
}





int main (void)
{
    int i, j, k;
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
                      if (( g_579 < -12) )
{

{
                        print_hash_value = ((safe_rshift_func_int16_t_s_s(((0x96C9DF21E312C42CLL >= (0xFA354F1FC35AFA75LL <= ((safe_mod_func_int16_t_s_s(g_482[5][1][0], (safe_lshift_func_uint16_t_u_u(g_3022, (safe_rshift_func_int8_t_s_s((safe_sub_func_uint16_t_u_u(g_2718, ((safe_sub_func_int16_t_s_s(((g_694 != (safe_add_func_uint8_t_u_u((g_188[0] = (+(g_163 & (g_1388[1] > (i = ((g_1775 > g_3106) , g_482[1][1][3])))))), (-1L)))) || g_1023[1][4][5]), g_93)) != 8UL))), 1)))))) == g_3106))) != g_2718), 4)) , 0x34CFAD37L);
                    }

}

transparent_crc(g_15, "g_15", print_hash_value);
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 9; j++)
        {
            transparent_crc(g_28[i][j], "g_28[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_76, "g_76", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_81[i], "g_81[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
                      if (( g_1820 < -1) )
{

g_276 += 1;


}

transparent_crc(g_90, "g_90", print_hash_value);
    transparent_crc(g_91, "g_91", print_hash_value);
    transparent_crc(g_93, "g_93", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 9; j++)
        {
            for (k = 0; k < 10; k++)
            {
                                  if (( g_1704 < 1) )
{

{
                        g_695 = (g_202 = g_202);
                    }

}

transparent_crc(g_105[i][j][k], "g_105[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_124, "g_124", print_hash_value);
    transparent_crc(g_148, "g_148", print_hash_value);
    transparent_crc(g_151, "g_151", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 1; j++)
        {
            for (k = 0; k < 6; k++)
            {
                                  if (( g_694 < -2) )
{

{
                transparent_crc(g_152[g_202][g_167][g_93], "g_152[g_202][g_167][g_93]", g_93);
                if (g_93) printf("index = [%d][%d][%d]\n", g_202, g_167, g_93);

            }

}

transparent_crc(g_152[i][j][k], "g_152[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_163, "g_163", print_hash_value);
    transparent_crc(g_167, "g_167", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_188[i], "g_188[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_202, "g_202", print_hash_value);
    transparent_crc(g_203, "g_203", print_hash_value);
    transparent_crc(g_208, "g_208", print_hash_value);
    transparent_crc(g_269, "g_269", print_hash_value);
    transparent_crc(g_276, "g_276", print_hash_value);
    transparent_crc(g_324, "g_324", print_hash_value);
    transparent_crc(g_381, "g_381", print_hash_value);
    transparent_crc(g_423, "g_423", print_hash_value);
    transparent_crc(g_465, "g_465", print_hash_value);
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                transparent_crc(g_482[i][j][k], "g_482[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_483[i], "g_483[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_511, "g_511", print_hash_value);
                      if (( g_324 < 1) )
{

{
        for (g_1121 = 0; g_1121 < 1; g_1121++)
        {
            for (g_579 = 0; g_579 < 6; g_579++)
            {
                transparent_crc(g_152[g_1775][g_1121][g_579], "g_152[g_1775][g_1121][g_579]", k);
                if (k) printf("index = [%d][%d][%d]\n", g_1775, g_1121, g_579);

            }
        }
    }

}

transparent_crc(g_519, "g_519", print_hash_value);
    transparent_crc(g_520, "g_520", print_hash_value);
    transparent_crc(g_521, "g_521", print_hash_value);
    transparent_crc(g_551, "g_551", print_hash_value);
    transparent_crc(g_559, "g_559", print_hash_value);
    transparent_crc(g_576, "g_576", print_hash_value);
    transparent_crc(g_579, "g_579", print_hash_value);
    transparent_crc(g_694, "g_694", print_hash_value);
    transparent_crc(g_695, "g_695", print_hash_value);
    transparent_crc(g_747, "g_747", print_hash_value);
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 6; j++)
        {
            transparent_crc(g_758[i][j], "g_758[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_875, "g_875", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 5; j++)
        {
            transparent_crc(g_952[i][j], "g_952[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_1016, "g_1016", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            for (k = 0; k < 10; k++)
            {
                transparent_crc(g_1023[i][j][k], "g_1023[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_1121, "g_1121", print_hash_value);
                      if (( g_208 < -1346286864) )
{

{
                        print_hash_value = (g_167 = g_694);
                    }

}

for (i = 0; i < 3; i++)
    {
        transparent_crc(g_1388[i], "g_1388[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9; j++)
        {
            for (k = 0; k < 2; k++)
            {
                transparent_crc(g_1405[i][j][k], "g_1405[i][j][k]", print_hash_value);
                if (print_hash_value) {

{
                        int i;
                        if (g_81[g_90])
                            break;
                        if (g_1388[0])
                            continue;
                        if (g_579)
                            continue;
                        g_1613 = (safe_rshift_func_uint8_t_u_s(0x4CL, 0));
                    }


printf("index = [%d][%d][%d]\n", i, j, k);}


            }
        }
    }
    transparent_crc(g_1507, "g_1507", print_hash_value);
    transparent_crc(g_1593, "g_1593", print_hash_value);
    transparent_crc(g_1613, "g_1613", print_hash_value);
    transparent_crc(g_1703, "g_1703", print_hash_value);
    transparent_crc(g_1704, "g_1704", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 4; j++)
        {
            transparent_crc(g_1729[i][j], "g_1729[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_1730, "g_1730", print_hash_value);
    transparent_crc(g_1775, "g_1775", print_hash_value);
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 1; j++)
        {
            transparent_crc(g_1783[i][j], "g_1783[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_1820, "g_1820", print_hash_value);
    transparent_crc(g_1854, "g_1854", print_hash_value);
    transparent_crc(g_1884, "g_1884", print_hash_value);
    transparent_crc(g_1970, "g_1970", print_hash_value);
    transparent_crc(g_2151, "g_2151", print_hash_value);
                      if (( g_1884 < 1290384964113678058) )
{

{
                transparent_crc(g_482[g_93][g_93][j], "g_482[g_93][g_93][j]", g_1775);
                if (g_1775) printf("index = [%d][%d][%d]\n", g_93, g_93, j);

            }

}

transparent_crc(g_2201, "g_2201", print_hash_value);
    transparent_crc(g_2718, "g_2718", print_hash_value);
    for (i = 0; i < 3; i++)
    {
                          if (( g_1704 < 1) )
{

{
                        g_91 = g_695;
                    }

}

transparent_crc(g_2720[i], "g_2720[i]", print_hash_value);
                          if (( g_1704 < 1) )
{

g_124 += 1;


}

if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_2939, "g_2939", print_hash_value);
    transparent_crc(g_3020, "g_3020", print_hash_value);
    transparent_crc(g_3022, "g_3022", print_hash_value);
    transparent_crc(g_3106, "g_3106", print_hash_value);
    transparent_crc(g_3551, "g_3551", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

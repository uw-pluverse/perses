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
void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);static long __undefined;


struct S0 {
   int32_t f0;
   signed f1 : 22;
};

struct S1 {
   unsigned f0 : 16;
   signed f1 : 9;
   signed f2 : 28;
   signed f3 : 13;
   unsigned f4 : 15;
   unsigned f5 : 17;
};


static struct S1 g_2 = {34,-5,2681,8,80,143};
static int32_t g_40[3] = {0xD571E957L, 0xD571E957L, 0xD571E957L};
static uint32_t g_63 = 18446744073709551615UL;
static uint32_t g_69 = 0UL;
static int32_t g_75 = 9L;
static uint16_t g_112 = 0x21B9L;
static struct S0 g_130 = {-1L,-557};
static uint16_t g_163 = 1UL;
static uint32_t g_174 = 18446744073709551610UL;
static int32_t g_211 = 0L;
static struct S0 g_217[1] = {{0x4CA2719FL,-474}};
static int32_t g_224 = (-10L);
static int32_t g_237 = 0xA85C4E4FL;
static uint8_t g_264 = 0x9EL;
static struct S1 g_274 = {208,13,-3263,-71,45,346};
static int32_t g_310 = 6L;
static uint16_t g_415 = 0xC333L;
static uint8_t g_613 = 253UL;
static int32_t g_647 = (-1L);
static struct S1 g_656 = {57,14,-15572,48,3,68};
static struct S1 g_658 = {251,19,4643,-9,101,27};
static int32_t g_688 = 1L;
static uint8_t g_714 = 0UL;
static uint32_t g_740 = 0UL;
static int32_t g_759 = 0x96B2935EL;
static int32_t g_875 = 0xC04C2CACL;
static uint32_t g_900 = 0xBE201F5BL;
static int16_t g_959 = 0xA11EL;
static int16_t g_969 = 0xB7E4L;
static uint32_t g_971 = 0x40F4A1F2L;
static uint32_t g_1039 = 0x32AF807FL;
static uint16_t g_1056 = 65535UL;
static int32_t g_1058 = (-7L);
static uint16_t g_1106 = 0xEC2AL;
static uint8_t g_1135 = 250UL;
static int32_t g_1177[4][5][2] = {{{0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}}, {{0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}}, {{0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}}, {{0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}, {0x697C2A1DL, 9L}}};
static uint8_t g_1178 = 0x76L;
static int8_t g_1184 = 0x39L;
static int16_t g_1204 = 0x8491L;
static int32_t g_1568 = 0x092DBBDEL;
static struct S0 g_1895 = {3L,-1076};
static struct S0 g_1896 = {0x1C87E74FL,-816};
static uint8_t g_1897 = 3UL;
static int16_t g_2098 = 0x4C2BL;
static uint32_t g_2214 = 0UL;
static int32_t g_2317 = 0xC2407E48L;
static int32_t g_2569 = 1L;
static int8_t g_2667 = 0xB3L;
static uint32_t g_3242[5] = {0xBD33D456L, 0xBD33D456L, 0xBD33D456L, 0xBD33D456L, 0xBD33D456L};
static int32_t g_3324 = 0x90578E4BL;
static uint8_t g_3484 = 0xFEL;
static uint8_t g_3662 = 249UL;
static uint32_t g_3735[5][4] = {{0x463FF5CBL, 0xAE64BA3BL, 0x463FF5CBL, 0xAE64BA3BL}, {0x463FF5CBL, 0xAE64BA3BL, 0x463FF5CBL, 0xAE64BA3BL}, {0x463FF5CBL, 0xAE64BA3BL, 0x463FF5CBL, 0xAE64BA3BL}, {0x463FF5CBL, 0xAE64BA3BL, 0x463FF5CBL, 0xAE64BA3BL}, {0x463FF5CBL, 0xAE64BA3BL, 0x463FF5CBL, 0xAE64BA3BL}};



static int8_t func_1(void);
static int32_t func_3(uint16_t p_4, int32_t p_5, uint32_t p_6, uint32_t p_7);
static uint16_t func_8(int32_t p_9, uint32_t p_10);
static uint8_t func_14(uint16_t p_15, int8_t p_16, uint8_t p_17, uint32_t p_18, uint32_t p_19);
static int16_t func_25(int32_t p_26);
static uint8_t func_29(uint16_t p_30, int32_t p_31);
static uint16_t func_33(uint32_t p_34, uint32_t p_35, int8_t p_36, uint16_t p_37);
static int8_t func_45(int32_t p_46, int32_t p_47, uint8_t p_48, int8_t p_49, uint8_t p_50);
static uint8_t func_52(int16_t p_53, uint32_t p_54, int16_t p_55, int8_t p_56, int8_t p_57);
static uint16_t func_64(uint8_t p_65, uint16_t p_66, int32_t p_67);
static int8_t func_1(void)
{
    int32_t l_22[10][10][2] = {{{0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}}, {{0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}}, {{0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}}, {{0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}}, {{0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}}, {{0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}}, {{0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}}, {{0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}}, {{0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}}, {{0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}, {0x5D64F689L, (-1L)}}};
    int32_t l_957 = 0L;
    int32_t l_958 = 7L;
    uint16_t l_2367 = 0xCA60L;
    int32_t l_2368 = (-1L);
    int32_t l_3000 = 0x9F95F825L;
    int32_t l_3110 = 0xE827D082L;
    int32_t l_3111 = (-1L);
    int32_t l_3850 = 0xEEDF68D4L;
    int i, j, k;
    g_2 = g_2;
    l_3850 = (0x3D783989L | func_3((l_3110 = func_8((l_3000 = (safe_add_func_uint16_t_u_u(((safe_unary_minus_func_int16_t_s(((func_14((g_2.f0 & ((safe_lshift_func_uint8_t_u_s(g_2.f4, l_22[8][1][0])) < (((l_2368 = (safe_mod_func_int16_t_s_s((func_25((safe_rshift_func_int8_t_s_u(g_2.f5, func_29(l_22[4][2][0], (g_959 = (g_2.f1 < (safe_unary_minus_func_uint8_t_u((l_958 = (l_957 = (func_33(l_22[8][8][0], (((g_40[1] = (safe_lshift_func_uint8_t_u_s(l_22[5][1][1], l_22[7][7][1]))) <= g_2.f3) >= 65531UL), g_2.f2, g_2.f2) & l_22[5][7][0]))))))))))) ^ l_2367), l_22[9][4][0]))) <= (-1L)) & l_2367))), g_1177[3][2][1], l_22[2][3][0], g_2.f4, l_22[9][5][1]) || 0xA1L) != g_2569))) || g_2667), g_1177[2][3][1]))), g_2569)), l_22[8][1][0], l_2367, l_3111));
    return g_740;
}







static int32_t func_3(uint16_t p_4, int32_t p_5, uint32_t p_6, uint32_t p_7)
{
    int8_t l_3150 = (-1L);
    int32_t l_3192 = (-1L);
    int16_t l_3215[1];
    int32_t l_3303 = 0x667F0CE7L;
    int16_t l_3361 = 9L;
    struct S1 l_3395 = {116,5,5933,-53,166,159};
    int32_t l_3465[8][7] = {{(-1L), (-1L), 0x107AA667L, (-1L), (-1L), (-1L), 0x107AA667L}, {(-1L), (-1L), 0x107AA667L, (-1L), (-1L), (-1L), 0x107AA667L}, {(-1L), (-1L), 0x107AA667L, (-1L), (-1L), (-1L), 0x107AA667L}, {(-1L), (-1L), 0x107AA667L, (-1L), (-1L), (-1L), 0x107AA667L}, {(-1L), (-1L), 0x107AA667L, (-1L), (-1L), (-1L), 0x107AA667L}, {(-1L), (-1L), 0x107AA667L, (-1L), (-1L), (-1L), 0x107AA667L}, {(-1L), (-1L), 0x107AA667L, (-1L), (-1L), (-1L), 0x107AA667L}, {(-1L), (-1L), 0x107AA667L, (-1L), (-1L), (-1L), 0x107AA667L}};
    int16_t l_3466[4];
    uint32_t l_3483 = 0UL;
    int8_t l_3485 = (-1L);
    uint32_t l_3518 = 0x4DF749D3L;
    struct S0 l_3519 = {-7L,-1037};
    uint32_t l_3617 = 18446744073709551615UL;
    int16_t l_3663 = 0x7CDEL;
    struct S1 l_3664 = {196,-14,-11505,36,27,45};
    uint8_t l_3714 = 0x78L;
    int16_t l_3763 = 0L;
    int16_t l_3773 = 0xAA10L;
    int i, j;
    for (i = 0; i < 1; i++)
        l_3215[i] = 0x8B40L;
    for (i = 0; i < 4; i++)
        l_3466[i] = 0x0E18L;
    for (p_4 = 0; (p_4 < 42); p_4 = safe_add_func_uint32_t_u_u(p_4, 3))
    {
        uint8_t l_3121[10] = {4UL, 0x3EL, 255UL, 255UL, 0x3EL, 4UL, 0x3EL, 255UL, 255UL, 0x3EL};
        int32_t l_3128[3];
        uint32_t l_3149 = 1UL;
        int32_t l_3156[9][10][2] = {{{(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}}, {{(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}}, {{(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}}, {{(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}}, {{(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}}, {{(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}}, {{(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}}, {{(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}}, {{(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}, {(-4L), 0x2EF9F7F2L}}};
        int32_t l_3158 = 2L;
        int32_t l_3159 = 0L;
        int i, j, k;
        for (i = 0; i < 3; i++)
            l_3128[i] = 0x935085E4L;
        p_5 = (((g_310 | (safe_lshift_func_int16_t_s_u(g_2.f1, (safe_sub_func_uint16_t_u_u((((~0x06DB24A1L) || (safe_lshift_func_uint8_t_u_u(g_274.f5, 4))) > ((l_3121[3] > ((g_1039 > ((((safe_rshift_func_uint8_t_u_s((((safe_mod_func_uint8_t_u_u((((l_3128[0] = ((safe_lshift_func_int16_t_s_s((0UL <= 4294967295UL), (((g_274.f3 && 0x84L) ^ 0x4EL) <= 0xD6L))) >= 0x35L)) || 9UL) & l_3121[3]), 0xA7L)) <= g_2667) > 65526UL), p_5)) || p_5) > p_4) == l_3121[5])) & g_656.f2)) >= g_1178)), 0xCE5EL))))) < 0xBDL) ^ 4294967295UL);
        if (((safe_rshift_func_uint16_t_u_u(p_7, 1)) || l_3128[0]))
        {
            int8_t l_3138 = 0xD4L;
            for (g_1184 = (-28); (g_1184 < 22); g_1184 = safe_add_func_int32_t_s_s(g_1184, 8))
            {
                for (g_2667 = 0; (g_2667 < 17); ++g_2667)
                {
                    return g_658.f3;
                }
            }
            g_1058 = ((((p_5 != (safe_unary_minus_func_int8_t_s((0L >= (+(~(l_3138 & (safe_add_func_int8_t_s_s(((safe_sub_func_int8_t_s_s(1L, g_647)) <= p_7), (g_224 < (safe_sub_func_int32_t_s_s((l_3149 = ((safe_sub_func_int32_t_s_s(g_1056, (safe_lshift_func_int8_t_s_s(p_7, g_174)))) | p_6)), g_2569)))))))))))) && l_3150) >= l_3138) < p_6);
            if (g_69)
                continue;
        }
        else
        {
            uint32_t l_3153 = 0UL;
            int32_t l_3160 = 0x89DB6284L;
            struct S0 l_3163 = {0x81074C56L,652};
            for (g_1056 = 0; (g_1056 > 18); ++g_1056)
            {
                struct S1 l_3155 = {48,-18,11019,53,146,113};
                int8_t l_3205 = 0x0DL;
                int16_t l_3256 = (-7L);

for (l_3663 = 6; (l_3663 >= 1); l_3663 -= 1)
                {
                    struct S0 l_3535 = {0x11C838F9L,694};
                    l_3535 = (l_3163 = l_3163);
                };


                    if (l_3153)
                {
                    struct S1 l_3154 = {145,14,-8932,-31,30,59};
                    g_688 = g_1895.f0;

for (g_759 = 0; g_759 < 5; g_759++)
    {
        for (g_1058 = 0; g_1058 < 4; g_1058++)
        {
            transparent_crc(g_3735[g_759][g_1058], "g_3735[g_759][g_1058]", g_2569);
            if (g_2569) printf("index = [%d][%d]\n", g_759, g_1058);

        }
    };


                    g_658 = (l_3155 = l_3154);
                }
                else
                {
                    l_3160 = (((g_130.f1 = ((g_875 > (((l_3156[1][2][0] ^ p_5) <= (l_3158 = (safe_unary_minus_func_uint8_t_u(l_3158)))) ^ l_3153)) < (l_3159 < ((g_714 < (p_6 & g_415)) < 0xCC38L)))) != 0xC79800D9L) == p_5);

if (l_3395.f1)
                {
for (l_3763 = 0; (l_3763 <= 0); l_3763 += 1)
                    {
                        struct S0 l_2619 = {1L,826};
                        int i;
                        g_130 = (l_2619 = (g_1896 = (g_217[g_1184] = g_130)));
                        g_274 = l_3395;
                    };


                    continue;}

                    return l_3150;
                }
                for (g_2317 = (-4); (g_2317 < 4); ++g_2317)
                {
                    l_3163 = (g_217[0] = g_217[0]);
                }
                for (p_5 = (-30); (p_5 < (-19)); ++p_5)
                {
                    int16_t l_3173 = 0xE426L;
                    int32_t l_3178[1];
                    uint8_t l_3241 = 246UL;
                    int32_t l_3285 = 0xEB33C094L;
                    int i;
                    for (i = 0; i < 1; i++)
                        {
{
                struct S0 l_3534 = {0xA0FCC4C2L,-196};
                struct S1 l_3595 = {118,17,-5381,27,140,190};
                g_217[0] = (g_1895 = (l_3534 = g_1895));
                for (l_3173 = 6; (l_3173 >= 1); l_3173 -= 1)
                {
                    struct S0 l_3535 = {0x11C838F9L,694};
                    l_3535 = (l_3534 = g_1896);
                }
                l_3534.f1 = ((l_3285 = (0x32F683B6L <= (safe_rshift_func_int8_t_s_s((safe_mod_func_int8_t_s_s((g_1184 = g_211), l_3534.f1)), 3)))) != (l_3303 = (g_1895.f1 = (((safe_sub_func_int8_t_s_s((safe_mod_func_int32_t_s_s((safe_sub_func_uint8_t_u_u(247UL, (g_688 = ((safe_mod_func_int32_t_s_s(((+l_3714) == (l_3714 & ((0x2EL != (safe_rshift_func_int8_t_s_s((g_274.f3 = l_3160), ((safe_lshift_func_uint8_t_u_u(l_3361, 1)) & l_3160)))) < 9L))), g_163)) & g_40[2])))), p_5)), l_3160)) < (-6L)) == l_3153))));
                if ((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_uint16_t_u_u(((((g_211 > (safe_lshift_func_int16_t_s_s(0xE7B3L, (6UL ^ (safe_add_func_int16_t_s_s(1L, g_163)))))) && g_1896.f0) > ((safe_sub_func_int16_t_s_s((-1L), (safe_rshift_func_uint16_t_u_s((g_163 = 0UL), 10)))) != (l_3153 <= l_3150))) < g_1568), 3)) >= 0xF2C9L))))
                {
                    int32_t l_3574 = (-7L);
                    int i;
                    g_656 = g_656;
                    g_658.f2 = (g_3242[1] <= (safe_lshift_func_uint16_t_u_s(((safe_mod_func_int16_t_s_s(0xA72DL, (safe_mod_func_int8_t_s_s(((g_1568 = g_1056) || (0UL && ((((l_3466[g_130.f0] = g_3242[4]) & (g_1056 = (safe_sub_func_int16_t_s_s(((l_3574 <= (safe_lshift_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_s((safe_unary_minus_func_int32_t_s(((l_3574 & (g_658.f3 == g_163)) && g_163))), 3)) | g_1896.f1), g_613))) ^ g_174), g_1896.f0)))) | 0xB9035DCAL) == 0x0965BC03L))), l_3534.f1)))) >= g_1896.f0), g_1897)));
                }
                else
                {
                    uint32_t l_3594 = 0x3BE16989L;
                    struct S1 l_3618 = {98,-18,15578,-20,29,137};
                    if ((safe_rshift_func_uint16_t_u_u((g_130.f1 = g_1896.f0), ((((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u(l_3285, (safe_rshift_func_int16_t_s_s((4294967286UL | (safe_add_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_s((((safe_lshift_func_uint8_t_u_s(1UL, 7)) || g_1056) | 0x5FL), (l_3594 = (((0xA259L && (248UL <= (g_163 | g_163))) || g_688) != (-3L))))) || g_900), 0x21D9L))), 13)))), p_5)) != l_3153) && l_3534.f0) && 0x76C663A7L))))
                    {
                        struct S1 l_3596 = {21,1,11767,18,12,308};
                        g_656 = g_274;
                        g_274 = (g_656 = (l_3596 = l_3595));
                    }
                    else
                    {
                        p_5 = (p_5 || l_3153);
                    }
                    if ((((((safe_mod_func_uint8_t_u_u(((l_3594 > (safe_unary_minus_func_uint32_t_u((l_3153 = ((safe_mod_func_uint8_t_u_u((l_3159 & (safe_lshift_func_uint8_t_u_s((g_1896.f1 || (((g_163 = g_211) ^ (((((-2L) || p_5) & ((safe_rshift_func_int8_t_s_u(((l_3153 < (safe_lshift_func_int8_t_s_u((safe_rshift_func_int16_t_s_s(g_688, 5)), (safe_add_func_uint8_t_u_u((g_1897 = (l_3595.f1 != 0x79L)), 250UL))))) >= 0x56L), 4)) & l_3153)) == 0xA155L) | l_3153)) <= 65535UL)), g_656.f1))), 0x3DL)) <= 0xD308927CL))))) >= g_69), g_1895.f0)) || l_3466[0]) || l_3594) | g_130.f1) >= l_3285))
                    {
                        g_1568 = (p_5 = (safe_mod_func_uint16_t_u_u((+(safe_rshift_func_uint8_t_u_s(252UL, 4))), g_40[1])));
                        g_740 = ((g_658.f1 = 0x24747140L) ^ 0x139177C6L);
                        l_3155 = l_3618;
                        if (g_656.f1)
                            break;
                    }
                    else
                    {
                        g_130.f1 = (g_658.f3 ^ (safe_lshift_func_int8_t_s_u(l_3155.f2, (safe_add_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((l_3618.f0 <= l_3155.f0), g_163)), (l_3714 = (safe_mod_func_uint32_t_u_u((((((safe_mod_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s(p_5, l_3618.f0)), g_274.f5)) | l_3595.f0) <= g_658.f5) & l_3595.f4) != l_3285), g_69))))), 0L)))));
                    }
                    if (g_217[0].f0)
                        continue;
                }
                for (g_1897 = 0; (g_1897 <= 6); g_1897 += 1)
                {
                    int16_t l_3638 = 4L;
                    int32_t l_3660 = 3L;
                    for (l_3153 = 2; (l_3153 <= 6); l_3153 += 1)
                    {
                        uint32_t l_3661 = 0xD4525F18L;
                        int i, j;
                        l_3465[(g_1897 + 1)][g_1897] = (safe_rshift_func_uint8_t_u_u(((~(safe_unary_minus_func_int32_t_s(((l_3150 = (g_69 < 4UL)) <= l_3638)))) != ((((l_3153 <= (safe_sub_func_int16_t_s_s((safe_sub_func_uint8_t_u_u((g_1135 = (+((safe_sub_func_int32_t_s_s((g_163 || (((safe_rshift_func_uint16_t_u_s((g_163 >= (safe_mod_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(((((((g_1184 = ((safe_rshift_func_int16_t_s_s(l_3173, 7)) <= (((g_1204 = ((safe_sub_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s((1L == (l_3660 = (safe_add_func_int32_t_s_s(g_69, g_163)))), l_3153)) >= l_3661), g_656.f4)) && g_211)) && 0x0E40L) ^ 0xF9L))) ^ g_1897) == p_5) < g_217[0].f1) ^ g_656.f0) > g_69), l_3155.f0)), 251UL))), g_69)) && l_3155.f4) && l_3159)), l_3160)) && g_1056))), l_3149)), l_3361))) && g_656.f3) && l_3153) != l_3361)), 7));
                        p_5 = (-1L);
                    }
                }
            }

                    l_3178[i] = 0x34784428L;}
                    if ((0xE8L <= (safe_rshift_func_int8_t_s_s((((l_3178[0] = ((safe_add_func_uint8_t_u_u((((safe_sub_func_uint16_t_u_u((((!((((p_7 <= l_3173) | 0xC0L) && (((safe_rshift_func_int8_t_s_s(((safe_mod_func_int8_t_s_s((l_3155.f1 = (-9L)), (g_1895.f1 & (l_3173 == (-1L))))) ^ (((((((p_5 & g_264) > p_4) && (-1L)) && 255UL) && l_3155.f3) < 0L) ^ 0UL)), 1)) >= l_3160) <= 0xB8D9AD0FL)) && p_5)) | g_1135) & 2L), l_3158)) == l_3155.f2) < l_3155.f3), p_4)) >= l_3150)) == g_658.f0) | 0UL), 4))))
                    {
                        int32_t l_3179 = 9L;
                        uint16_t l_3180 = 0x8C96L;
                        g_310 = ((p_6 <= (g_959 = (l_3156[8][5][0] = (l_3163.f1 == (g_1897 = p_4))))) <= (g_2.f1 = (g_2569 = (0x2E69865AL ^ g_2.f3))));
                        l_3179 = p_6;

g_759 -= 1;


                    l_3192 = ((((l_3180 & g_1058) != 0L) && (safe_rshift_func_uint8_t_u_s(p_5, ((~((l_3163.f0 <= (((((g_1106 && (g_2.f0 >= ((0x4BL >= (safe_sub_func_int16_t_s_s((safe_mod_func_int8_t_s_s((safe_lshift_func_int8_t_s_u(((p_7 = g_2667) >= l_3153), p_6)), 5UL)), g_971))) | 0x69F6955EL))) > (-3L)) == 249UL) != 0xFBL) != g_1177[2][3][1])) && g_63)) == g_656.f0)))) <= p_6);
                        if (g_274.f5)
                            continue;
                    }
                    else
                    {
                        uint16_t l_3206 = 0x01FDL;

l_3163.f0 += 1;


                    l_3206 = ((safe_rshift_func_uint16_t_u_u(g_2.f3, (g_274.f2 >= g_274.f3))) != (safe_lshift_func_int16_t_s_s(g_759, (((safe_mod_func_int32_t_s_s((l_3155.f1 = (safe_sub_func_uint32_t_u_u((p_7 = 0x164FC45FL), l_3149))), (safe_unary_minus_func_uint16_t_u((((((+g_658.f2) | (((safe_rshift_func_uint8_t_u_u(0UL, (p_5 < 65531UL))) != (-1L)) & l_3205)) && l_3192) | p_6) > 4L))))) || l_3155.f5) >= l_3192))));
                        if (p_6)
                            break;
                    }
                    if (((((safe_rshift_func_uint16_t_u_u((g_1106 = (((l_3163.f1 < ((p_4 || ((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(((l_3215[0] = (l_3155.f3 = l_3163.f0)) >= p_7), l_3163.f0)), 2)), (((safe_sub_func_uint8_t_u_u((0x0ED1L == p_5), 255UL)) || 0x13D5D53DL) != g_658.f3))) > g_40[0])) || p_7)) > 0xD607L) <= p_7)), 0)) | g_2667) & l_3153) | 7L))
                    {
                        uint32_t l_3240 = 4294967295UL;
                        int32_t l_3243 = 0x2036FA62L;
                        l_3243 = ((g_217[0].f0 & (safe_unary_minus_func_uint32_t_u((safe_lshift_func_uint16_t_u_u(p_6, 12))))) != ((g_40[1] && (safe_add_func_uint16_t_u_u(((p_4 & (safe_mod_func_int16_t_s_s(((g_274.f4 = ((l_3155.f3 = ((((((safe_mod_func_uint8_t_u_u((((safe_mod_func_int16_t_s_s(0xC8E0L, (safe_sub_func_int32_t_s_s((((((((+(safe_sub_func_uint16_t_u_u((((l_3155.f2 = (safe_lshift_func_uint16_t_u_u(((safe_sub_func_int16_t_s_s(1L, (((0xAE9E1DFEL >= ((((safe_lshift_func_uint16_t_u_s(l_3178[0], 7)) < (g_658.f1 != 0xDCL)) | l_3178[0]) > l_3121[2])) || 1L) && p_5))) <= g_2667), 15))) ^ 65535UL) != p_5), 0x3336L))) || l_3240) | g_415) ^ 0xECB9L) ^ 0xEAL) > l_3240) > 0x980DC22EL), p_5)))) & l_3156[0][8][0]) == 0x2CL), l_3241)) || l_3153) > l_3150) ^ p_6) && 0x00A1L) | 0x6007259EL)) != g_3242[3])) != p_5), g_112))) < 1L), (-3L)))) < g_237));
                        l_3192 = (p_6 & p_7);
                    }
                    else
                    {
                        return p_5;
                    }
                    l_3178[0] = (safe_sub_func_uint8_t_u_u((l_3159 = ((g_274.f2 && (safe_lshift_func_uint16_t_u_s(((l_3121[3] <= (((((0xF90FL ^ l_3156[1][8][0]) | ((g_310 = ((((safe_sub_func_int32_t_s_s((safe_sub_func_int32_t_s_s(1L, (safe_sub_func_int8_t_s_s((0x98F7L != (-1L)), ((0xE9L < (0x9130L != (-1L))) | p_7))))), 0x2DED9735L)) != 0x45L) & p_5) != 0x44B3L)) >= g_69)) | p_5) < 9UL) && g_1895.f1)) | p_6), 1))) & p_6)), 0UL));

for (g_2317 = 0; g_2317 < 5; g_2317++)
        {
            for (g_688 = 0; g_688 < 2; g_688++)
            {
                transparent_crc(g_1177[p_5][g_2317][g_688], "g_1177[p_5][g_2317][g_688]", g_211);
                if (g_211) {
{
                        if (l_3763)
                            break;
                    }

                    printf("index = [%d][%d][%d]\n", p_5, g_2317, g_688);}

            }
        };


                    for (g_971 = 0; (g_971 >= 7); g_971 = safe_add_func_int32_t_s_s(g_971, 6))
                    {
                        uint16_t l_3284 = 1UL;
                        if (l_3256)
                            break;
                        l_3285 = ((safe_unary_minus_func_uint16_t_u(((((l_3163.f1 = (safe_sub_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(0x0CE5L, ((l_3128[0] = (g_1897 & (((safe_add_func_int8_t_s_s((l_3160 = (l_3156[1][2][0] = 0x39L)), (safe_mod_func_uint32_t_u_u(0x57E20B7BL, (l_3178[0] || (safe_sub_func_uint32_t_u_u((g_2.f4 = (l_3158 = (safe_rshift_func_uint16_t_u_s((safe_lshift_func_uint16_t_u_u(((p_7 > (g_1106 = (safe_add_func_int16_t_s_s((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s((l_3192 = g_656.f4), 4)), (g_1184 = ((safe_lshift_func_uint16_t_u_u(l_3163.f0, (safe_sub_func_uint16_t_u_u((l_3178[0] = ((safe_lshift_func_int16_t_s_s(((((((g_415 = (65527UL <= p_7)) & g_2317) >= 1UL) > g_658.f2) && l_3284) <= 0x6CL), g_1895.f0)) ^ p_5)), p_5)))) < l_3241)))), 0xF518L)))) >= g_75), p_5)), 13)))), 1UL))))))) >= g_2.f3) <= l_3215[0]))) ^ 0UL))), 0x7746L))) | 0xE224L) == g_237) < p_6))) <= 1L);
                    }
                }
            }

g_63 += 1;


                    p_5 = (safe_rshift_func_int8_t_s_s((((safe_add_func_uint16_t_u_u(((safe_mod_func_uint8_t_u_u(((l_3160 = (-5L)) <= ((0xE7L <= ((+p_5) > ((((p_6 & (safe_unary_minus_func_uint32_t_u(0xE961FAADL))) >= 0x65100CFAL) > g_658.f2) || p_4))) || g_130.f0)), l_3163.f1)) != l_3163.f0), p_4)) < p_5) >= 0x56L), g_1895.f1));

g_264 += 1;


                    p_5 = (!p_6);
        }
    }
    for (g_2214 = 0; (g_2214 <= 1); g_2214 += 1)
    {
        uint16_t l_3297 = 7UL;
        int32_t l_3298[3];
        uint16_t l_3304[2];
        struct S1 l_3308 = {92,-17,2491,4,172,312};
        uint16_t l_3325 = 65526UL;
        uint32_t l_3330 = 18446744073709551609UL;
        uint32_t l_3434[5] = {0xFA961CEAL, 18446744073709551615UL, 0xFA961CEAL, 18446744073709551615UL, 0xFA961CEAL};
        int i;
        for (i = 0; i < 3; i++)
            l_3298[i] = 0x3A7C282BL;

if (g_310)
                    continue;

                    for (i = 0; i < 2; i++)
            {
if (g_217[0].f0)
                        continue;

                    l_3304[i] = 65532UL;}
        g_1896.f1 = (safe_mul_func_int8_t_s_s((g_1184 = ((l_3192 = (((l_3297 && ((l_3298[1] = ((g_714 = l_3215[0]) ^ 4L)) < p_4)) == (0xDAE2L ^ (safe_lshift_func_uint16_t_u_s(g_217[0].f0, 12)))) && (~0xAD5E69F1L))) || 0x3239L)), (1UL >= l_3150)));
        for (l_3192 = 1; (l_3192 >= 0); l_3192 -= 1)
        {
            int16_t l_3302[7][6][6] = {{{0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}}, {{0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}}, {{0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}}, {{0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}}, {{0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}}, {{0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}}, {{0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}, {0x281BL, 0x88D3L, 5L, 0xF72BL, 0x8704L, 0x9F0EL}}};
            int32_t l_3307[9][2][5] = {{{(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}, {(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}}, {{(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}, {(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}}, {{(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}, {(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}}, {{(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}, {(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}}, {{(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}, {(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}}, {{(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}, {(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}}, {{(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}, {(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}}, {{(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}, {(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}}, {{(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}, {(-1L), 0x119DF868L, 0x119DF868L, (-1L), 0L}}};
            int i, j, k;

for (g_3324 = 0; (g_3324 <= 1); g_3324 += 1)
                    {
                        g_658 = g_2;
                    };


                    for (g_75 = 1; (g_75 >= 0); g_75 -= 1)
            {
                int i, j, k;
                return g_1177[(g_2214 + 1)][g_2214][l_3192];
            }
            for (g_1897 = 0; (g_1897 <= 1); g_1897 += 1)
            {
                int i;
                l_3298[g_2214] = l_3298[g_2214];
                for (g_2098 = 0; (g_2098 <= 1); g_2098 += 1)
                {
                    int i, j, k;

{
                    g_647 = 0L;
                    if (g_647)
                        continue;
                    g_658 = g_274;
                }

                    if (g_1177[(g_2214 + 2)][(g_2214 + 3)][g_2098])
                        {
g_1178 += 1;


                    break;}
                    l_3303 = l_3302[1][1][5];
                    g_217[0].f1 = (((g_1135 = ((0x597FA753L != (g_658.f5 = (p_7 = 0UL))) >= (l_3302[1][1][5] <= 8L))) > (0x14L != (((p_4 ^ (l_3304[1] & (l_3307[7][1][1] = ((safe_lshift_func_int16_t_s_s(g_1177[(g_2214 + 2)][(g_2214 + 3)][g_2098], g_900)) >= p_5)))) <= 0x97817216L) || g_613))) > g_1056);
                    g_658 = l_3308;
                }
            }

g_647 -= 1;


                    return l_3297;
        }
        for (g_1896.f0 = 1; (g_1896.f0 >= 0); g_1896.f0 -= 1)
        {
            struct S1 l_3309 = {245,-1,-15661,10,41,220};
            if (g_3242[4])
                break;

{
                        g_1896.f1 = (g_658.f3 ^ (safe_lshift_func_int8_t_s_u(g_2.f2, (safe_add_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((l_3664.f0 <= g_2.f0), l_3297)), (g_1897 = (safe_mod_func_uint32_t_u_u((((((safe_mod_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s(g_3324, l_3664.f0)), l_3308.f5)) | l_3308.f0) <= g_658.f5) & l_3308.f4) != i), g_740))))), 0L)))));
                    }

                    if (g_656.f5)
            {
                int16_t l_3338 = 0xA3E7L;
                int32_t l_3339 = 1L;
                uint8_t l_3390 = 0x46L;
                l_3309 = g_2;


g_1568 -= 1;


                    if (l_3297)
                            continue;

                    g_656.f3 = l_3303;
                for (p_6 = 0; (p_6 <= 1); p_6 += 1)
                {
                    int16_t l_3321[7][2] = {{(-4L), 4L}, {(-4L), 4L}, {(-4L), 4L}, {(-4L), 4L}, {(-4L), 4L}, {(-4L), 4L}, {(-4L), 4L}};
                    int32_t l_3326 = 0x0F8CB4E5L;
                    uint32_t l_3327 = 0UL;
                    int i, j;
                    g_40[1] = ((safe_mod_func_uint32_t_u_u(((0UL > (g_656.f3 = (g_1177[0][2][0] & ((!(g_3242[3] & l_3309.f4)) ^ (((l_3298[1] < (safe_add_func_int32_t_s_s(((safe_lshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((l_3308.f5 > (g_1184 = (p_5 != (safe_sub_func_uint32_t_u_u(l_3321[5][1], (l_3326 = ((safe_rshift_func_int8_t_s_u(g_3324, l_3325)) || 4UL))))))), 1)), 5)) >= 5L), g_656.f2))) < l_3309.f5) && 4294967286UL))))) == l_3327), p_7)) != 0x78F790AFL);
                    if (p_5)
                    {
                        if (g_2098)
                            {
for (l_3485 = 27; (l_3485 > (-25)); l_3485--)
                    {
                        uint32_t l_665 = 0xE8B9A2A8L;
                        int32_t l_668[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_668[i] = 0x75128752L;
                        g_2317 = (g_875 = l_665);
                        l_3308.f1 = (l_668[1] = (g_656.f1 = l_665));
                        g_875 = g_63;
                        l_3339 = l_3485;
                    };


                    break;}
                    }
                    else
                    {
                        int32_t l_3360[8];
                        int i;
                        for (i = 0; i < 8; i++)
                            l_3360[i] = (-1L);

{
            g_3324 = g_900;
        }

                    l_3308.f3 = (g_658.f5 & (safe_rshift_func_uint16_t_u_s(0x505AL, 13)));

if (g_112)
                            continue;

                    p_5 = (((p_5 <= l_3330) > ((safe_lshift_func_int8_t_s_u(g_1895.f0, 7)) >= ((safe_mod_func_uint16_t_u_u((safe_add_func_uint32_t_u_u((safe_unary_minus_func_uint16_t_u(((g_714 = (l_3338 = g_1106)) <= l_3339))), (((p_7 = ((safe_rshift_func_int8_t_s_s(((l_3303 = (l_3360[7] = ((p_6 || ((safe_mod_func_int16_t_s_s(((safe_add_func_uint16_t_u_u(((safe_mod_func_uint8_t_u_u(((l_3326 = (((((0x29L == (l_3298[2] == (safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u(((safe_lshift_func_uint8_t_u_s((safe_sub_func_int32_t_s_s(((safe_rshift_func_int8_t_s_s(p_7, l_3360[2])) && l_3309.f5), l_3360[7])), g_224)) == 1L), g_1895.f1)), p_7)), g_658.f3)))) > g_2.f2) == g_2.f2) || l_3326) & l_3339)) ^ p_4), l_3339)) > l_3360[7]), l_3361)) >= g_237), 0x365BL)) & 4UL)) != p_5))) == 0xE998L), p_6)) == l_3308.f5)) | 0UL) >= l_3192))), 65535UL)) < l_3215[0]))) & g_959);
                        g_211 = (safe_rshift_func_int16_t_s_u(l_3309.f4, 5));
                    }
                    for (l_3192 = 0; (l_3192 <= 1); l_3192 += 1)
                    {
                        int32_t l_3384 = 0x7079A3C1L;
                        int i, j;
                        g_2317 = ((((l_3298[1] = (g_2098 = (safe_sub_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((((((p_7 = (!(l_3321[(g_2214 + 4)][l_3192] >= (safe_sub_func_uint16_t_u_u(p_5, ((g_1204 = ((l_3309.f1 = (-1L)) > ((safe_add_func_int32_t_s_s((safe_add_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_u((l_3309.f3 = (((safe_unary_minus_func_uint16_t_u(0x0734L)) == ((g_1897 = (0xDDBFA053L <= g_274.f2)) <= (((((p_6 | (l_3384 = (((safe_rshift_func_uint16_t_u_s(((safe_lshift_func_int16_t_s_s(l_3308.f0, 0)) > (((safe_add_func_uint8_t_u_u(((g_1056 >= p_6) & l_3215[0]), l_3321[5][1])) == g_2.f3) <= l_3215[0])), 3)) & g_130.f0) != 0xDA11F161L))) != p_4) == p_5) > 65535UL) < p_6))) && 0x3383L)), g_3324)) < 1UL), 0xDDA0E53CL)), 0x0A57D91CL)) >= p_5))) | l_3321[(l_3192 + 5)][p_6])))))) != p_4) & 0x96L) ^ l_3321[(g_2214 + 4)][l_3192]) <= 0xC0C1898EL), 1)), 0x55C7L)))) > (-1L)) != l_3304[0]) || g_714);
                        p_5 = g_714;
                    }
                    l_3339 = (l_3192 = (p_5 = (safe_mod_func_uint32_t_u_u(0xC9EE7B75L, (0x29L & (g_1184 = (0x841AL || (~(g_415 = (0xB7F9CC39L && p_7))))))))));
                }

{
                    uint32_t l_2898 = 4294967295UL;
                    l_3192 = (safe_add_func_uint16_t_u_u((1UL & p_6), ((g_63 | (safe_rshift_func_uint8_t_u_u((g_3484 = ((l_3339 = ((0UL <= 4L) | (safe_rshift_func_uint8_t_u_s((g_613 = ((l_3395.f1 = (safe_sub_func_uint8_t_u_u(p_6, (safe_sub_func_int8_t_s_s((safe_lshift_func_int8_t_s_u((g_1184 = (safe_lshift_func_uint8_t_u_s(6UL, (l_3395.f4 | ((+(g_1896.f0 >= g_656.f0)) == 0x5A62595BL))))), 0)), l_3395.f1))))) != 0x59L)), 1)))) || l_3395.f3)), 3))) || g_656.f4)));
                    g_1895 = l_3519;
                    if ((safe_lshift_func_int8_t_s_u(((+(safe_sub_func_uint32_t_u_u((0L || (g_714 = (safe_rshift_func_uint16_t_u_s(g_1896.f0, 4)))), g_3324))) == ((-1L) | g_2.f2)), g_63)))
                    {
                        g_1895.f1 = l_3483;
                    }
                    else
                    {
                        uint8_t l_2913 = 0x9DL;
                        g_656.f2 = (safe_mod_func_uint32_t_u_u((g_1896.f1 = ((((safe_sub_func_int8_t_s_s(g_714, g_112)) && (((safe_add_func_uint32_t_u_u((safe_mod_func_int16_t_s_s((g_656.f3 = ((safe_mod_func_uint8_t_u_u(g_656.f1, (g_1184 = (l_3150 && (safe_lshift_func_uint8_t_u_u((((((safe_add_func_int32_t_s_s((safe_add_func_uint32_t_u_u(l_3150, (l_3339 = l_3330))), (safe_rshift_func_int16_t_s_u(((safe_add_func_int8_t_s_s((g_2667 = g_714), (g_1895.f1 = g_656.f4))) ^ g_1184), 15)))) & g_1039) & l_3330) != 0x1B3FL) == l_2898), g_1178)))))) > p_6)), 1UL)), g_224)) & 1L) | 0xFAF6L)) | g_2.f3) && g_1896.f0)), 0xF5299BB1L));
                        g_658.f1 = ((safe_rshift_func_uint8_t_u_u((((((g_1896.f1 = (g_211 <= (safe_add_func_uint16_t_u_u((8UL < (0xBB9ADCDDL != (g_656.f3 = (safe_add_func_uint32_t_u_u((g_656.f1 = (((safe_sub_func_int8_t_s_s((p_6 & (g_658.f2 = ((safe_sub_func_int8_t_s_s((((g_1184 && (safe_add_func_int8_t_s_s((l_3150 = (((g_1896.f1 = (safe_lshift_func_int16_t_s_u(l_2913, 0))) <= (g_656.f1 > g_2317)) ^ ((g_224 != 1UL) < l_3325))), 0x66L))) | l_2898) > 0xB95B8FDAL), g_1896.f1)) > l_2913))), g_217[0].f1)) & l_2913) && l_3395.f2)), 0x0D2C52FFL))))), g_2.f1)))) ^ g_63) <= l_3192) > p_6) || l_2898), 4)) && l_3395.f5);
                    }
                }

                    if ((1L | (safe_lshift_func_uint16_t_u_s((l_3390 <= (safe_lshift_func_uint8_t_u_s((safe_add_func_uint8_t_u_u(p_7, 1UL)), 3))), l_3309.f3))))
                {
                    p_5 = 0L;
                    if (p_5)
                        {
{
                    struct S1 l_3154 = {145,14,-8932,-31,30,59};

if (g_1177[(g_2214 + 2)][(g_2214 + 3)][l_3361])
                        break;

                    g_211 = g_1895.f0;

{
                    for (g_1058 = 24; (g_1058 <= 23); g_1058 = safe_sub_func_int32_t_s_s(g_1058, 5))
                    {
                        int8_t l_1498[9][6][4] = {{{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}};
                        int32_t l_1503 = 0x172577FDL;
                        int i, j, k;
                        g_971 = 0L;
                        l_3303 = ((safe_lshift_func_uint16_t_u_u((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u((l_3361 = (6UL ^ (g_3662 && 6UL))), 0)) < ((-1L) | l_1498[5][2][2])), l_1498[3][2][2])) ^ ((safe_mod_func_int32_t_s_s(((safe_sub_func_uint32_t_u_u(l_3303, (l_1503 = (((g_759 > 1UL) <= l_3663) & 255UL)))) != 1UL), 2L)) | g_1106)) | l_3395.f0), 12)) ^ g_2667);
                    }
                }

                    g_656 = (l_3308 = l_3154);
                }

                    continue;}
                    l_3395 = g_658;
                }
                else
                {

g_1897 += 1;



{
                        uint32_t l_3661 = 0xD4525F18L;
                        int i, j;
                        l_3465[(g_1897 + 1)][g_1897] = (safe_rshift_func_uint8_t_u_u(((~(safe_unary_minus_func_int32_t_s(((g_1184 = (l_3330 < 4UL)) <= l_3338)))) != ((((l_3518 <= (safe_sub_func_int16_t_s_s((safe_sub_func_uint8_t_u_u((g_3662 = (+((safe_sub_func_int32_t_s_s((g_163 || (((safe_rshift_func_uint16_t_u_s((g_163 >= (safe_mod_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(((((((l_3150 = ((safe_rshift_func_int16_t_s_s(g_959, 7)) <= (((g_959 = ((safe_sub_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s((1L == (g_237 = (safe_add_func_int32_t_s_s(l_3330, g_163)))), l_3518)) >= l_3661), l_3664.f4)) && g_875)) && 0x0E40L) ^ 0xF9L))) ^ g_3662) == g_310) < g_217[0].f1) ^ l_3664.f0) > l_3330), l_3664.f0)), 251UL))), l_3330)) && l_3664.f4) && l_3192)), l_3192)) && l_3325))), g_900)), g_959))) && l_3664.f3) && l_3518) != l_3338)), 7));
                        g_310 = (-1L);
                    }

                    l_3309.f2 = 0x4B857C2BL;
                }
            }
            else
            {
                l_3395.f3 = 0L;
                p_5 = l_3308.f5;
                p_5 = (+l_3309.f4);
            }
            for (g_130.f0 = 0; (g_130.f0 <= 1); g_130.f0 += 1)
            {
                struct S1 l_3398 = {35,16,7720,-29,103,324};
                for (g_310 = 0; (g_310 <= 0); g_310 += 1)
                {
                    int32_t l_3406[5][6][5] = {{{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}, {{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}, {{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}, {{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}, {{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}};
                    int i, j, k;
                    for (g_1895.f0 = 0; (g_1895.f0 <= 1); g_1895.f0 += 1)
                    {
                        uint32_t l_3397 = 18446744073709551612UL;
                        g_688 = l_3397;
                    }

{
                    int8_t l_265 = 1L;
                    l_3298[1] = ((((l_265 = (safe_lshift_func_uint16_t_u_s(3UL, (l_3150 > (safe_rshift_func_uint8_t_u_s((((g_740 >= (safe_sub_func_uint8_t_u_u(g_1896.f1, (g_714 = ((safe_lshift_func_uint16_t_u_s(g_740, 8)) <= g_647))))) == g_63) <= 7UL), 3)))))) || (safe_mod_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(g_656.f2, g_112)), g_656.f1))) && l_3150) >= l_3150);
                    for (l_3485 = 0; (l_3485 <= 4); l_3485 += 1)
                    {
                        g_647 = l_3298[1];
                    }
                }

                    g_658 = l_3398;
                    g_211 = (safe_rshift_func_uint8_t_u_s((p_6 | ((safe_mod_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((g_1204 = (p_7 >= (~249UL))) == ((0xF820L > (p_4 || l_3308.f5)) && (0x6EL != g_2.f0))), ((((((0xD75D51DDL ^ g_647) <= (-1L)) | l_3406[0][2][0]) || l_3309.f0) >= g_130.f0) >= g_2667))) | g_2.f3) | 65529UL), l_3309.f2)) <= l_3406[4][3][3])), 1));
                }
            }
        }
        for (g_63 = 0; (g_63 <= 1); g_63 += 1)
        {
            struct S0 l_3407[8] = {{-6L,-1441}, {1L,1034}, {-6L,-1441}, {1L,1034}, {-6L,-1441}, {1L,1034}, {-6L,-1441}, {1L,1034}};
            int i;
            g_759 = 0x5B787D82L;
            for (g_1135 = 0; (g_1135 <= 0); g_1135 += 1)
            {
                int i;
                l_3407[3] = (g_1896 = g_217[g_1135]);
                p_5 = g_217[g_1135].f1;
            }

for (j = 0; (j == (-3)); --j)
            {
                uint32_t l_138 = 0UL;
                uint8_t l_145 = 2UL;
                if (((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s((l_3297 & (g_875 = (safe_mod_func_int16_t_s_s(l_3483, l_3773)))), 0)) > (l_3483 & ((g_163 = g_658.f0) < (3L & (((safe_add_func_int8_t_s_s(((7L <= g_688) | l_3297), g_658.f0)) | 0UL) || 0xE596L))))), 2)) == g_688))
                {

g_112 += 1;



if (l_3303)
                        break;

                    j = l_3483;
                }
                else
                {
                    struct S1 l_129 = {74,15,-5951,-51,147,32};
                    struct S0 l_147 = {-6L,1480};
                    for (g_1056 = 0; (g_1056 <= 11); ++g_1056)
                    {
                        int16_t l_146 = 0xA7B7L;
                        l_129 = g_658;

if (g_688)
                        break;

                    g_130 = g_130;
                        l_146 = ((safe_rshift_func_int16_t_s_u(((((g_875 = 0xE8AE3155L) & (g_1056 != (-1L))) >= (safe_lshift_func_int8_t_s_u((l_145 = (!((safe_sub_func_int16_t_s_s((l_138 <= ((g_40[1] <= ((safe_rshift_func_uint8_t_u_s((((l_129.f1 = (((safe_mod_func_uint32_t_u_u((l_3297 == (l_3483 ^ ((safe_mod_func_uint16_t_u_u(g_130.f0, 1L)) && g_971))), l_3485)) <= g_658.f4) == 0x0C3003DDL)) & g_163) | g_163), 7)) >= l_129.f3)) && 1UL)), g_658.f5)) == 0xE0L))), 0))) | l_3483), g_658.f2)) == g_658.f4);
                    }
                    l_147 = g_130;
                    if (g_658.f2)
                        break;
                }
            };


                    p_5 = (((p_4 & 0xC581L) | g_1896.f1) ^ 0L);
            for (l_3297 = 0; (l_3297 <= 1); l_3297 += 1)
            {
                int32_t l_3414 = 1L;
                int32_t l_3442[6];
                int i;
                for (i = 0; i < 6; i++)
                    l_3442[i] = 0xC36A85D4L;

if (g_63)
                            continue;

                    for (g_959 = 1; (g_959 >= 0); g_959 -= 1)
                {
                    int32_t l_3419 = 0xB76BEF39L;
                    int32_t l_3427[7][9] = {{0L, 0x830EA8C7L, 1L, 0x88B06F0FL, 1L, 0xB32CFCB1L, 1L, 0x88B06F0FL, 1L}, {0L, 0x830EA8C7L, 1L, 0x88B06F0FL, 1L, 0xB32CFCB1L, 1L, 0x88B06F0FL, 1L}, {0L, 0x830EA8C7L, 1L, 0x88B06F0FL, 1L, 0xB32CFCB1L, 1L, 0x88B06F0FL, 1L}, {0L, 0x830EA8C7L, 1L, 0x88B06F0FL, 1L, 0xB32CFCB1L, 1L, 0x88B06F0FL, 1L}, {0L, 0x830EA8C7L, 1L, 0x88B06F0FL, 1L, 0xB32CFCB1L, 1L, 0x88B06F0FL, 1L}, {0L, 0x830EA8C7L, 1L, 0x88B06F0FL, 1L, 0xB32CFCB1L, 1L, 0x88B06F0FL, 1L}, {0L, 0x830EA8C7L, 1L, 0x88B06F0FL, 1L, 0xB32CFCB1L, 1L, 0x88B06F0FL, 1L}};
                    int32_t l_3441 = 0x11CB144BL;
                    uint32_t l_3443 = 0xEF1EAEF4L;
                    int32_t l_3444 = 0x1C555F7DL;
                    int i, j;
                    p_5 = (5UL > (p_5 != ((((l_3419 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_s(((((((safe_lshift_func_int8_t_s_s(((l_3304[1] >= ((l_3414 > l_3308.f0) ^ ((g_658.f3 && g_63) < ((((l_3308.f2 = (safe_lshift_func_uint16_t_u_s((p_4 = g_3242[3]), 10))) == (safe_sub_func_uint32_t_u_u((l_3407[3].f0 != 0xF2D15877L), g_656.f2))) >= l_3361) || 255UL)))) | 0x9A96L), 5)) <= p_6) == l_3414) > g_1184) <= 0x80L) | p_7), 6)), p_7))) <= p_5) && l_3419) <= l_3414)));
                    p_5 = (safe_unary_minus_func_int32_t_s((((-9L) >= (safe_mod_func_int32_t_s_s((safe_add_func_uint16_t_u_u((safe_sub_func_int16_t_s_s(((0x88L & g_3324) & (g_75 == g_658.f1)), (l_3395.f2 = (l_3427[4][8] = 5L)))), (safe_mod_func_uint16_t_u_u(((((((g_969 = (g_1204 = l_3298[1])) && ((l_3308.f2 = ((safe_lshift_func_int16_t_s_u((((0x92FCE6FDL ^ (((((safe_sub_func_int16_t_s_s((((((((0x60L > g_969) <= 0xD2L) || p_4) == 4294967295UL) & (-1L)) >= p_7) && l_3414), p_4)) >= 0xAFB92EB2L) < 1UL) >= p_4) >= g_656.f4)) && g_759) >= l_3434[1]), 15)) & g_656.f0)) != p_4)) ^ p_4) | 0x8405E4EBL) >= 1L) && 0x02L), 0x4E95L)))), 3UL))) >= p_5)));
                    for (l_3325 = 0; (l_3325 <= 0); l_3325 += 1)
                    {
                        int i;

for (g_1896.f0 = 0; (g_1896.f0 <= 1); g_1896.f0 += 1)
            {
                struct S1 l_3398 = {35,16,7720,-29,103,324};

l_3297 += 1;


                    for (g_1568 = 0; (g_1568 <= 0); g_1568 += 1)
                {
                    int32_t l_3406[5][6][5] = {{{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}, {{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}, {{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}, {{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}, {{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}};
                    int i, j, k;
                    for (g_1896.f0 = 0; (g_1896.f0 <= 1); g_1896.f0 += 1)
                    {
                        uint32_t l_3397 = 18446744073709551612UL;
                        g_75 = l_3397;
                    }
                    l_3664 = l_3398;
                    g_1568 = (safe_rshift_func_uint8_t_u_s((g_63 | ((safe_mod_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((l_3763 = (l_3443 >= (~249UL))) == ((0xF820L > (g_415 || g_2.f5)) && (0x6EL != l_3395.f0))), ((((((0xD75D51DDL ^ l_3441) <= (-1L)) | l_3406[0][2][0]) || l_3664.f0) >= g_1896.f0) >= l_3150))) | l_3395.f3) | 65529UL), l_3664.f2)) <= l_3406[4][3][3])), 1));
                }
            };


                    g_1896 = (g_217[0] = g_217[l_3325]);
                        l_3444 = (0x46L | ((((((safe_add_func_uint8_t_u_u((4L && (251UL || 0xC2L)), ((g_1135 = (l_3442[4] = ((((safe_add_func_uint16_t_u_u(((((l_3298[2] = (l_3434[g_2214] || 0xBAL)) > ((g_163 = ((safe_mod_func_uint16_t_u_u((g_415 = (p_4 = (g_237 < (l_3441 = ((0xFA7BL == (l_3427[4][8] = g_2.f0)) > p_6))))), 0xDB07L)) && p_6)) && g_959)) & l_3414) <= p_6), g_217[l_3325].f1)) <= p_6) != l_3414) & g_217[l_3325].f1))) <= l_3443))) ^ l_3297) || l_3308.f1) > g_613) == l_3414) == l_3192));
                        l_3192 = 0x6E3A984FL;
                        p_5 = l_3325;
                    }

g_740 += 1;


                    p_5 = (4294967294UL > l_3407[3].f0);
                }
                if (p_5)
                    break;
            }
        }
    }

g_759 += 1;


                    l_3395.f2 = ((((safe_sub_func_int32_t_s_s((~(g_1058 || ((((!(((p_6 <= (safe_rshift_func_uint16_t_u_u((p_4 = (safe_lshift_func_int8_t_s_s((g_1184 = (safe_rshift_func_int8_t_s_s(p_6, 3))), (((safe_sub_func_int16_t_s_s(((safe_mod_func_uint8_t_u_u((1L <= (((1L > 0L) || (safe_sub_func_uint8_t_u_u(p_7, (l_3192 = ((l_3395.f1 = (safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s((p_4 < (((l_3395.f3 = 0xA3L) <= g_1178) && g_656.f3)), g_1177[2][3][1])) || 0x80L), g_1895.f1))) == l_3150))))) <= g_1895.f1)), l_3395.f4)) ^ 0x6FL), g_656.f1)) && p_6) & l_3465[6][1])))), g_274.f5))) >= g_658.f0) ^ l_3215[0])) > 5UL) == l_3466[2]) & g_969))), g_174)) != 0x51F8L) == 4UL) & 255UL);
    if (((((((safe_rshift_func_int16_t_s_u((((((safe_sub_func_int16_t_s_s(((l_3395.f2 = 0x29L) == (l_3485 = (safe_add_func_int16_t_s_s(g_163, ((p_5 | (safe_add_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(g_274.f4, (l_3465[6][5] = ((((p_4 | p_4) | (g_1204 = (safe_sub_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(((0xC091L ^ (((safe_mod_func_uint32_t_u_u(l_3466[0], l_3395.f4)) ^ l_3483) || p_4)) && p_4), g_2317)), p_6)))) | g_3242[3]) && g_875)))), 0xC5A3L))) || g_3484))))), 0xA4BDL)) != p_6) <= l_3150) != 0x5ABEL) >= l_3215[0]), l_3361)) && 0L) && g_63) != p_5) <= (-9L)) == 2L))
    {
        int8_t l_3486 = 0xBAL;
        int32_t l_3487 = 0x50391338L;
        struct S0 l_3521 = {2L,60};
        struct S1 l_3619 = {134,-3,7843,-7,4,65};
        p_5 = ((l_3395.f1 = ((l_3486 = l_3395.f3) <= 0xFCL)) < (((l_3395.f0 & l_3487) == (safe_sub_func_int16_t_s_s(p_6, l_3487))) == p_7));
        if (((~((((l_3487 = g_274.f1) ^ (1UL != ((4294967295UL || l_3486) > g_1056))) && (l_3465[6][1] = (safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(((safe_add_func_uint16_t_u_u(((0x590057A5L >= 3L) != ((((g_1895.f0 < ((g_875 = (g_217[0].f1 = p_4)) < p_7)) && 1L) == (-10L)) | g_1896.f1)), g_2569)) ^ l_3395.f0), p_4)), l_3215[0])))) || p_7)) == p_6))
        {
            p_5 = p_7;
        }
        else
        {
            uint8_t l_3501 = 0xE8L;
            int32_t l_3517 = 1L;
            struct S0 l_3533 = {-7L,737};
            int32_t l_3553 = (-6L);
            int32_t l_3554 = 0xF75A6613L;
            struct S1 l_3665 = {102,-8,-13702,-7,137,244};
            if ((safe_mod_func_int16_t_s_s(((l_3501 <= ((safe_sub_func_uint8_t_u_u(0x9BL, ((l_3303 = (safe_rshift_func_int8_t_s_u(g_1056, g_217[0].f1))) != (l_3465[7][4] = (g_613 = ((safe_lshift_func_uint16_t_u_u(p_4, 13)) ^ g_415)))))) <= ((g_112 && (safe_mod_func_int16_t_s_s(((g_310 = (g_2.f1 = ((((g_1184 = (((!0x76271C1FL) ^ (safe_sub_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(((safe_add_func_int16_t_s_s(((g_264 = (g_3484 = ((((l_3517 = ((p_7 = 0x19E28945L) ^ l_3395.f0)) <= l_3485) && p_4) & p_4))) <= (-9L)), 65535UL)) != l_3486), 3L)), l_3501))) | 0x20L)) ^ l_3501) | g_2.f2) ^ p_5))) & 0L), l_3518))) > l_3501))) && l_3501), p_6)))
            {
                struct S0 l_3520[3] = {{-4L,-2011}, {-4L,-2011}, {-4L,-2011}};
                struct S1 l_3522 = {0,8,818,-84,160,233};
                int i;
                l_3521 = (l_3520[1] = l_3519);

if ((safe_rshift_func_uint16_t_u_u((g_130.f1 = g_130.f0), ((((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u(g_875, (safe_rshift_func_int16_t_s_s((4294967286UL | (safe_add_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_s((((safe_lshift_func_uint8_t_u_s(1UL, 7)) || g_163) | 0x5FL), (g_2214 = (((0xA259L && (248UL <= (g_415 | g_415))) || i) != (-3L))))) || g_900), 0x21D9L))), 13)))), l_3303)) != g_2214) && g_1895.f0) && 0x76C663A7L))))
                    {
                        struct S1 l_3596 = {21,1,11767,18,12,308};
                        l_3665 = g_274;
                        g_274 = (g_274 = (l_3596 = l_3395));
                    }
                    else
                    {
                        l_3303 = (l_3303 || g_2214);
                    };


                    l_3522 = g_2;
            }
            else
            {
                int32_t l_3528 = (-10L);
                p_5 = (p_6 <= (safe_lshift_func_int8_t_s_u((((g_1896.f1 > 1UL) > (safe_lshift_func_uint8_t_u_u(0x0AL, (((!((g_1897 = l_3528) ^ (-4L))) < (p_7 = (((((p_4 || l_3395.f5) == 0xD141EB83L) & l_3395.f4) >= 1UL) & l_3501))) | 0xA348L)))) || (-1L)), 0)));

for (g_1058 = 0; g_1058 < 3; g_1058++)
            g_40[g_1058] = 0x935085E4L;

                    g_656.f3 = ((((((0x23L < (((l_3528 == ((p_7 > (l_3483 & l_3517)) || ((((safe_sub_func_int32_t_s_s((l_3487 = g_658.f3), (((0xCEL == (safe_add_func_int32_t_s_s(g_714, (((((((((0xF731AC28L < g_3242[3]) | l_3521.f0) | l_3395.f1) == g_971) <= 0x620DL) & g_274.f3) >= (-7L)) > 0xD885ADEAL) | l_3517)))) == l_3486) || 4294967295UL))) || 0x35FAL) <= l_3528) <= 0x8EDAE74BL))) != 65532UL) <= g_274.f4)) & g_2667) | p_4) & l_3501) | l_3303) & l_3521.f0);
            }

{
        for (g_875 = 0; g_875 < 5; g_875++)
        {

{
                        l_3553 = g_40[1];
                    }

                    for (g_759 = 0; g_759 < 2; g_759++)
            {
                transparent_crc(g_1177[g_211][g_875][g_759], "g_1177[g_211][g_875][g_759]", i);
                if (i) printf("index = [%d][%d][%d]\n", g_211, g_875, g_759);

            }
        }
    }

                    for (l_3519.f0 = 0; (l_3519.f0 <= 3); l_3519.f0 += 1)
            {
                struct S0 l_3534 = {0xA0FCC4C2L,-196};
                struct S1 l_3595 = {118,17,-5381,27,140,190};

if (g_1184)
                        break;

                    g_217[0] = (l_3533 = (l_3534 = l_3533));
                for (g_1204 = 6; (g_1204 >= 1); g_1204 -= 1)
                {
                    struct S0 l_3535 = {0x11C838F9L,694};

g_2098 -= 1;


                    l_3535 = (l_3534 = l_3521);
                }
                l_3534.f1 = ((l_3517 = (0x32F683B6L <= (safe_rshift_func_int8_t_s_s((safe_mod_func_int8_t_s_s((g_1184 = g_1058), l_3534.f1)), 3)))) != (l_3554 = (l_3533.f1 = (((safe_sub_func_int8_t_s_s((safe_mod_func_int32_t_s_s((safe_sub_func_uint8_t_u_u(247UL, (l_3553 = ((safe_mod_func_int32_t_s_s(((+g_1178) == (g_1178 & ((0x2EL != (safe_rshift_func_int8_t_s_s((l_3395.f3 = g_310), ((safe_lshift_func_uint8_t_u_u(l_3361, 1)) & l_3192)))) < 9L))), p_4)) & g_40[2])))), p_5)), g_3324)) < (-6L)) == p_7))));

{
                        uint16_t l_3206 = 0x01FDL;
                        l_3206 = ((safe_rshift_func_uint16_t_u_u(g_274.f3, (l_3595.f2 >= l_3595.f3))) != (safe_lshift_func_int16_t_s_s(g_3324, (((safe_mod_func_int32_t_s_s((g_656.f1 = (safe_sub_func_uint32_t_u_u((l_3483 = 0x164FC45FL), g_971))), (safe_unary_minus_func_uint16_t_u((((((+g_274.f2) | (((safe_rshift_func_uint8_t_u_u(0UL, (g_688 < 65531UL))) != (-1L)) & g_2667)) && g_75) | g_740) > 4L))))) || g_656.f5) >= g_75))));
                        if (g_740)
                            break;
                    }

                    if ((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_uint16_t_u_u(((((g_2569 > (safe_lshift_func_int16_t_s_s(0xE7B3L, (6UL ^ (safe_add_func_int16_t_s_s(1L, p_4)))))) && l_3521.f0) > ((safe_sub_func_int16_t_s_s((-1L), (safe_rshift_func_uint16_t_u_s((g_415 = 0UL), 10)))) != (p_7 <= g_2667))) < l_3487), 3)) >= 0xF2C9L))))
                {
                    int32_t l_3574 = (-7L);
                    int i;

for (g_2569 = 0; (g_2569 < (-14)); g_2569--)
            {
                uint16_t l_275 = 0x38A2L;
                int8_t l_276[8];
                int i;
                for (i = 0; i < 8; i++)
                    l_276[i] = 0L;
                if ((l_3485 == (l_3150 > l_3150)))
                {
                    int8_t l_265 = 1L;
                    g_40[1] = ((((l_265 = (safe_lshift_func_uint16_t_u_s(3UL, (l_3150 > (safe_rshift_func_uint8_t_u_s((((l_3483 >= (safe_sub_func_uint8_t_u_u(g_130.f1, (g_1178 = ((safe_lshift_func_uint16_t_u_s(l_3483, 8)) <= g_75))))) == l_3518) <= 7UL), 3)))))) || (safe_mod_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(l_3665.f2, g_415)), l_3665.f1))) && l_3150) >= l_3150);
                    for (l_3485 = 0; (l_3485 <= 4); l_3485 += 1)
                    {
                        g_75 = g_40[1];
                    }
                }
                else
                {
                    struct S1 l_273 = {66,-4,-10986,-87,170,225};
                    if (l_3485)
                        {
for (g_310 = 0; (g_310 == (-3)); --g_310)
            {
                uint32_t l_138 = 0UL;
                uint8_t l_145 = 2UL;
                if (((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s((g_163 & (l_3487 = (safe_mod_func_int16_t_s_s(g_174, l_3763)))), 0)) > (g_174 & ((l_275 = l_3665.f0) < (3L & (((safe_add_func_int8_t_s_s(((7L <= g_3324) | g_163), l_3665.f0)) | 0UL) || 0xE596L))))), 2)) == g_3324))
                {
                    g_688 = g_174;
                }
                else
                {
                    struct S1 l_129 = {74,15,-5951,-51,147,32};
                    struct S0 l_147 = {-6L,1480};
                    for (g_415 = 0; (g_415 <= 11); ++g_415)
                    {
                        int16_t l_146 = 0xA7B7L;
                        l_129 = l_3665;
                        g_1896 = g_1896;
                        l_146 = ((safe_rshift_func_int16_t_s_u(((((l_3487 = 0xE8AE3155L) & (g_415 != (-1L))) >= (safe_lshift_func_int8_t_s_u((l_145 = (!((safe_sub_func_int16_t_s_s((l_138 <= ((g_40[1] <= ((safe_rshift_func_uint8_t_u_s((((l_129.f1 = (((safe_mod_func_uint32_t_u_u((g_163 == (g_174 ^ ((safe_mod_func_uint16_t_u_u(g_1896.f0, 1L)) && g_2214))), l_3150)) <= l_3665.f4) == 0x0C3003DDL)) & l_275) | l_275), 7)) >= l_129.f3)) && 1UL)), l_3665.f5)) == 0xE0L))), 0))) | g_174), l_3665.f2)) == l_3665.f4);
                    }
                    l_147 = g_1896;
                    if (l_3665.f2)
                        break;
                }
            };


                    break;}
                    for (l_3485 = 0; (l_3485 <= 13); l_3485 = safe_add_func_int16_t_s_s(l_3485, 1))
                    {
                        l_3619 = l_273;
                        l_275 = (l_273.f4 < g_40[1]);
                        l_276[0] = g_75;
                    }
                }
            };


                    g_656 = g_2;
                    g_274.f2 = (g_3242[1] <= (safe_lshift_func_uint16_t_u_s(((safe_mod_func_int16_t_s_s(0xA72DL, (safe_mod_func_int8_t_s_s(((l_3487 = g_112) || (0UL && ((((l_3466[l_3519.f0] = g_3242[4]) & (g_1106 = (safe_sub_func_int16_t_s_s(((l_3574 <= (safe_lshift_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_s((safe_unary_minus_func_int32_t_s(((l_3574 & (g_274.f3 == p_4)) && p_4))), 3)) | l_3521.f1), l_3501))) ^ g_174), l_3521.f0)))) | 0xB9035DCAL) == 0x0965BC03L))), l_3534.f1)))) >= g_1896.f0), g_1135)));
                }
                else
                {
                    uint32_t l_3594 = 0x3BE16989L;
                    struct S1 l_3618 = {98,-18,15578,-20,29,137};
                    if ((safe_rshift_func_uint16_t_u_u((l_3519.f1 = l_3521.f0), ((((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u(g_2317, (safe_rshift_func_int16_t_s_s((4294967286UL | (safe_add_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_s((((safe_lshift_func_uint8_t_u_s(1UL, 7)) || g_112) | 0x5FL), (l_3594 = (((0xA259L && (248UL <= (p_4 | p_4))) || l_3553) != (-3L))))) || l_3518), 0x21D9L))), 13)))), p_5)) != p_7) && l_3534.f0) && 0x76C663A7L))))
                    {
                        struct S1 l_3596 = {21,1,11767,18,12,308};
                        g_2 = l_3395;

if (i)
                        break;


if (((~((((g_211 = g_656.f1) ^ (1UL != ((4294967295UL || l_3486) > g_1106))) && (l_3465[6][1] = (safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(((safe_add_func_uint16_t_u_u(((0x590057A5L >= 3L) != ((((l_3533.f0 < ((g_688 = (g_217[0].f1 = g_415)) < g_69)) && 1L) == (-10L)) | l_3521.f1)), g_224)) ^ g_656.f0), g_415)), l_3215[0])))) || g_69)) == l_3617))
        {
            i = g_69;
        }
        else
        {
            uint8_t l_3501 = 0xE8L;
            int32_t l_3517 = 1L;
            struct S0 l_3533 = {-7L,737};
            int32_t l_3553 = (-6L);
            int32_t l_3554 = 0xF75A6613L;
            struct S1 l_3665 = {102,-8,-13702,-7,137,244};
            if ((safe_mod_func_int16_t_s_s(((l_3501 <= ((safe_sub_func_uint8_t_u_u(0x9BL, ((g_759 = (safe_rshift_func_int8_t_s_u(g_1106, g_217[0].f1))) != (l_3465[7][4] = (g_1135 = ((safe_lshift_func_uint16_t_u_u(g_415, 13)) ^ g_415)))))) <= ((g_1106 && (safe_mod_func_int16_t_s_s(((g_224 = (l_3395.f1 = ((((l_3150 = (((!0x76271C1FL) ^ (safe_sub_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(((safe_add_func_int16_t_s_s(((g_264 = (l_3501 = ((((l_3517 = ((g_69 = 0x19E28945L) ^ g_656.f0)) <= l_3485) && g_415) & g_415))) <= (-9L)), 65535UL)) != l_3486), 3L)), l_3501))) | 0x20L)) ^ l_3501) | l_3395.f2) ^ i))) & 0L), g_69))) > l_3501))) && l_3501), l_3617)))
            {
                struct S0 l_3520[3] = {{-4L,-2011}, {-4L,-2011}, {-4L,-2011}};
                struct S1 l_3522 = {0,8,818,-84,160,233};
                int i;
                l_3521 = (l_3520[1] = g_1895);
                l_3522 = l_3395;
            }
            else
            {
                int32_t l_3528 = (-10L);
                i = (l_3617 <= (safe_lshift_func_int8_t_s_u((((l_3521.f1 > 1UL) > (safe_lshift_func_uint8_t_u_u(0x0AL, (((!((g_1135 = l_3528) ^ (-4L))) < (g_69 = (((((g_415 || g_656.f5) == 0xD141EB83L) & g_656.f4) >= 1UL) & l_3501))) | 0xA348L)))) || (-1L)), 0)));
                g_656.f3 = ((((((0x23L < (((l_3528 == ((g_69 > (g_1039 & l_3517)) || ((((safe_sub_func_int32_t_s_s((g_211 = l_3595.f3), (((0xCEL == (safe_add_func_int32_t_s_s(g_3662, (((((((((0xF731AC28L < g_3242[3]) | l_3521.f0) | g_656.f1) == g_740) <= 0x620DL) & g_656.f3) >= (-7L)) > 0xD885ADEAL) | l_3517)))) == l_3486) || 4294967295UL))) || 0x35FAL) <= l_3528) <= 0x8EDAE74BL))) != 65532UL) <= g_656.f4)) & g_2667) | g_415) & l_3501) | g_759) & l_3521.f0);
            }
            for (g_1895.f0 = 0; (g_1895.f0 <= 3); g_1895.f0 += 1)
            {
                struct S0 l_3534 = {0xA0FCC4C2L,-196};
                struct S1 l_3595 = {118,17,-5381,27,140,190};
                g_217[0] = (l_3533 = (l_3534 = l_3533));
                for (g_1204 = 6; (g_1204 >= 1); g_1204 -= 1)
                {
                    struct S0 l_3535 = {0x11C838F9L,694};
                    l_3535 = (l_3534 = l_3521);
                }
                l_3534.f1 = ((l_3517 = (0x32F683B6L <= (safe_rshift_func_int8_t_s_s((safe_mod_func_int8_t_s_s((l_3150 = g_211), l_3534.f1)), 3)))) != (l_3554 = (l_3533.f1 = (((safe_sub_func_int8_t_s_s((safe_mod_func_int32_t_s_s((safe_sub_func_uint8_t_u_u(247UL, (l_3553 = ((safe_mod_func_int32_t_s_s(((+l_3501) == (l_3501 & ((0x2EL != (safe_rshift_func_int8_t_s_s((g_656.f3 = g_224), ((safe_lshift_func_uint8_t_u_u(g_969, 1)) & j)))) < 9L))), g_415)) & g_40[2])))), i)), g_237)) < (-6L)) == g_69))));
                if ((safe_unary_minus_func_uint16_t_u(((safe_lshift_func_uint16_t_u_u(((((g_224 > (safe_lshift_func_int16_t_s_s(0xE7B3L, (6UL ^ (safe_add_func_int16_t_s_s(1L, g_415)))))) && l_3521.f0) > ((safe_sub_func_int16_t_s_s((-1L), (safe_rshift_func_uint16_t_u_s((g_415 = 0UL), 10)))) != (g_69 <= g_2667))) < g_211), 3)) >= 0xF2C9L))))
                {
                    int32_t l_3574 = (-7L);
                    int i;
                    g_656 = l_3395;
                    g_656.f2 = (g_3242[1] <= (safe_lshift_func_uint16_t_u_s(((safe_mod_func_int16_t_s_s(0xA72DL, (safe_mod_func_int8_t_s_s(((g_211 = g_1106) || (0UL && ((((l_3466[g_1895.f0] = g_3242[4]) & (g_163 = (safe_sub_func_int16_t_s_s(((l_3574 <= (safe_lshift_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_s((safe_unary_minus_func_int32_t_s(((l_3574 & (g_656.f3 == g_415)) && g_415))), 3)) | l_3521.f1), l_3501))) ^ l_3617), l_3521.f0)))) | 0xB9035DCAL) == 0x0965BC03L))), l_3534.f1)))) >= l_3521.f0), g_1135)));
                }
                else
                {
                    uint32_t l_3594 = 0x3BE16989L;
                    struct S1 l_3618 = {98,-18,15578,-20,29,137};
                    if ((safe_rshift_func_uint16_t_u_u((g_1895.f1 = l_3521.f0), ((((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u(g_224, (safe_rshift_func_int16_t_s_s((4294967286UL | (safe_add_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_s((((safe_lshift_func_uint8_t_u_s(1UL, 7)) || g_1106) | 0x5FL), (l_3594 = (((0xA259L && (248UL <= (g_415 | g_415))) || l_3553) != (-3L))))) || g_69), 0x21D9L))), 13)))), i)) != g_69) && l_3534.f0) && 0x76C663A7L))))
                    {
                        struct S1 l_3596 = {21,1,11767,18,12,308};
                        l_3395 = g_656;
                        g_656 = (g_656 = (l_3596 = l_3595));
                    }
                    else
                    {
                        i = (i || g_69);
                    }
                    if ((((((safe_mod_func_uint8_t_u_u(((l_3594 > (safe_unary_minus_func_uint32_t_u((g_69 = ((safe_mod_func_uint8_t_u_u((g_237 & (safe_lshift_func_uint8_t_u_s((l_3521.f1 || (((g_415 = j) ^ (((((-2L) || i) & ((safe_rshift_func_int8_t_s_u(((g_69 < (safe_lshift_func_int8_t_s_u((safe_rshift_func_int16_t_s_s(l_3553, 5)), (safe_add_func_uint8_t_u_u((g_1135 = (l_3595.f1 != 0x79L)), 250UL))))) >= 0x56L), 4)) & g_69)) == 0xA155L) | g_69)) <= 65535UL)), l_3395.f1))), 0x3DL)) <= 0xD308927CL))))) >= l_3617), l_3533.f0)) || l_3466[0]) || l_3594) | l_3533.f1) >= l_3517))
                    {
                        g_211 = (i = (safe_mod_func_uint16_t_u_u((+(safe_rshift_func_uint8_t_u_s(252UL, 4))), g_40[1])));
                        l_3518 = ((l_3595.f1 = 0x24747140L) ^ 0x139177C6L);
                        l_3395 = l_3618;
                        if (l_3395.f1)
                            break;
                    }
                    else
                    {
                        l_3521.f1 = (g_656.f3 ^ (safe_lshift_func_int8_t_s_u(l_3395.f2, (safe_add_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((l_3618.f0 <= l_3395.f0), g_415)), (l_3501 = (safe_mod_func_uint32_t_u_u((((((safe_mod_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s(i, l_3618.f0)), g_656.f5)) | l_3595.f0) <= g_656.f5) & l_3595.f4) != g_224), l_3617))))), 0L)))));
                    }
                    if (g_217[0].f0)
                        continue;
                }
                for (g_1135 = 0; (g_1135 <= 6); g_1135 += 1)
                {
                    int16_t l_3638 = 4L;
                    int32_t l_3660 = 3L;
                    for (g_69 = 2; (g_69 <= 6); g_69 += 1)
                    {
                        uint32_t l_3661 = 0xD4525F18L;
                        int i, j;
                        l_3465[(g_1135 + 1)][g_1135] = (safe_rshift_func_uint8_t_u_u(((~(safe_unary_minus_func_int32_t_s(((g_2667 = (l_3617 < 4UL)) <= l_3638)))) != ((((g_69 <= (safe_sub_func_int16_t_s_s((safe_sub_func_uint8_t_u_u((l_3501 = (+((safe_sub_func_int32_t_s_s((g_415 || (((safe_rshift_func_uint16_t_u_s((g_415 >= (safe_mod_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(((((((l_3150 = ((safe_rshift_func_int16_t_s_s(g_1204, 7)) <= (((g_1204 = ((safe_sub_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s((1L == (l_3660 = (safe_add_func_int32_t_s_s(l_3617, g_415)))), g_69)) >= l_3661), g_656.f4)) && g_224)) && 0x0E40L) ^ 0xF9L))) ^ g_1135) == i) < g_217[0].f1) ^ g_656.f0) > l_3617), l_3395.f0)), 251UL))), l_3617)) && l_3395.f4) && j)), g_237)) && g_1106))), g_900)), g_1204))) && g_656.f3) && g_69) != g_2098)), 7));
                        i = (-1L);
                    }
                }
            }
            l_3665 = l_3395;
        };


                    l_3395 = (g_656 = (l_3596 = l_3595));
                    }
                    else
                    {

{
                    struct S1 l_129 = {74,15,-5951,-51,147,32};
                    struct S0 l_147 = {-6L,1480};
                    for (g_1106 = 0; (g_1106 <= 11); ++g_1106)
                    {
                        int16_t l_146 = 0xA7B7L;
                        l_129 = l_3619;
                        l_3534 = l_3534;
                        l_146 = ((safe_rshift_func_int16_t_s_u(((((l_3303 = 0xE8AE3155L) & (g_1106 != (-1L))) >= (safe_lshift_func_int8_t_s_u((l_3501 = (!((safe_sub_func_int16_t_s_s((g_971 <= ((g_40[1] <= ((safe_rshift_func_uint8_t_u_s((((l_129.f1 = (((safe_mod_func_uint32_t_u_u((g_1106 == (g_2214 ^ ((safe_mod_func_uint16_t_u_u(l_3534.f0, 1L)) && g_1039))), l_3485)) <= l_3619.f4) == 0x0C3003DDL)) & g_415) | g_415), 7)) >= l_129.f3)) && 1UL)), l_3619.f5)) == 0xE0L))), 0))) | g_2214), l_3619.f2)) == l_3619.f4);
                    }
                    l_147 = l_3534;
                    if (l_3619.f2)
                        break;
                }

                    p_5 = (p_5 || p_7);
                    }

{
                    int32_t l_2157 = 6L;
                    struct S0 l_2166 = {0x1EE1138AL,-1097};
                    l_3664.f3 = ((0x95FDL || l_3361) <= (((((((((g_2098 = l_2157) >= ((((g_1568 = ((l_3595.f2 = g_2317) <= (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_s((l_3501 >= (safe_add_func_int16_t_s_s(g_3324, (0xA0L < (safe_add_func_uint16_t_u_u(((g_2317 | 0xA63F201AL) ^ 0xCFF3DD30L), l_2157)))))), g_1135)) == l_3521.f0), l_3487)))) | 65535UL) & l_2157) | l_3487)) < g_3662) >= g_1135) > g_1135) > (-1L)) < l_3487) == l_3665.f3) > 1L));
                    g_1896 = (g_1895 = l_2166);
                }

                    if ((((((safe_mod_func_uint8_t_u_u(((l_3594 > (safe_unary_minus_func_uint32_t_u((p_7 = ((safe_mod_func_uint8_t_u_u((g_75 & (safe_lshift_func_uint8_t_u_s((l_3521.f1 || (((p_4 = g_237) ^ (((((-2L) || p_5) & ((safe_rshift_func_int8_t_s_u(((p_7 < (safe_lshift_func_int8_t_s_u((safe_rshift_func_int16_t_s_s(l_3553, 5)), (safe_add_func_uint8_t_u_u((g_613 = (l_3595.f1 != 0x79L)), 250UL))))) >= 0x56L), 4)) & p_7)) == 0xA155L) | p_7)) <= 65535UL)), g_2.f1))), 0x3DL)) <= 0xD308927CL))))) >= p_6), l_3533.f0)) || l_3466[0]) || l_3594) | g_1895.f1) >= l_3517))
                    {
                        l_3487 = (p_5 = (safe_mod_func_uint16_t_u_u((+(safe_rshift_func_uint8_t_u_s(252UL, 4))), g_40[1])));
                        l_3617 = ((g_658.f1 = 0x24747140L) ^ 0x139177C6L);
                        l_3619 = l_3618;
                        if (g_2.f1)
                            break;
                    }
                    else
                    {
                        g_130.f1 = (g_274.f3 ^ (safe_lshift_func_int8_t_s_u(l_3619.f2, (safe_add_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((l_3618.f0 <= l_3619.f0), p_4)), (g_1178 = (safe_mod_func_uint32_t_u_u((((((safe_mod_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s(p_5, l_3618.f0)), l_3395.f5)) | l_3595.f0) <= g_274.f5) & l_3595.f4) != g_2317), p_6))))), 0L)))));
                    }
                    if (g_217[0].f0)
                        {
g_759 -= 1;


                    continue;}
                }
                for (g_1135 = 0; (g_1135 <= 6); g_1135 += 1)
                {
                    int16_t l_3638 = 4L;
                    int32_t l_3660 = 3L;

g_1058 -= 1;


                    for (p_7 = 2; (p_7 <= 6); p_7 += 1)
                    {
                        uint32_t l_3661 = 0xD4525F18L;
                        int i, j;
                        l_3465[(g_1135 + 1)][g_1135] = (safe_rshift_func_uint8_t_u_u(((~(safe_unary_minus_func_int32_t_s(((g_2667 = (p_6 < 4UL)) <= l_3638)))) != ((((p_7 <= (safe_sub_func_int16_t_s_s((safe_sub_func_uint8_t_u_u((g_3662 = (+((safe_sub_func_int32_t_s_s((p_4 || (((safe_rshift_func_uint16_t_u_s((p_4 >= (safe_mod_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(((((((g_1184 = ((safe_rshift_func_int16_t_s_s(g_1204, 7)) <= (((g_2098 = ((safe_sub_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s((1L == (l_3660 = (safe_add_func_int32_t_s_s(p_6, p_4)))), p_7)) >= l_3661), g_656.f4)) && g_2569)) && 0x0E40L) ^ 0xF9L))) ^ g_613) == p_5) < g_217[0].f1) ^ g_656.f0) > p_6), l_3619.f0)), 251UL))), p_6)) && l_3619.f4) && g_1568)), g_3324)) && g_1056))), g_900)), g_969))) && g_656.f3) && p_7) != l_3663)), 7));
                        p_5 = (-1L);
                    }
                }
            }

g_2317 += 1;


                    l_3665 = l_3664;
        }
    }
    else
    {
        uint32_t l_3675 = 0UL;
        struct S1 l_3690[4][6] = {{{114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}, {114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}}, {{114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}, {114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}}, {{114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}, {114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}}, {{114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}, {114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}}};
        int32_t l_3711 = 0x89004967L;
        uint32_t l_3797[3][1];
        int i, j;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 1; j++)
                l_3797[i][j] = 0xEEBFC6BFL;
        }
        for (g_2214 = 0; (g_2214 <= 21); g_2214 = safe_add_func_int32_t_s_s(g_2214, 8))
        {
            int16_t l_3672 = 0x56DAL;
            struct S1 l_3687 = {189,20,-16362,38,121,6};
            struct S1 l_3688 = {105,-17,-2409,60,130,138};
            uint32_t l_3698[10];
            int8_t l_3712 = 0L;
            int i;
            for (i = 0; i < 10; i++)
                l_3698[i] = 0xD52D981BL;

{
                        int32_t l_3842[7][5][7] = {{{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}};
                        int i, j, k;
                        g_75 = (((!l_3688.f5) <= ((((((safe_rshift_func_uint8_t_u_u((g_274.f2 = (safe_mod_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s(l_3518, (safe_mod_func_int32_t_s_s((((safe_add_func_uint16_t_u_u(p_6, ((((g_264 = ((safe_add_func_int8_t_s_s((l_3842[6][4][6] = 0x7AL), (~((safe_sub_func_int8_t_s_s(((((safe_rshift_func_int16_t_s_u(l_3672, 4)) ^ 0xDB1D7EE1L) == g_1106) != l_3690[3][4].f4), ((g_1106 >= l_3617) <= 3UL))) < 1UL)))) > 0x0DFFBBBEL)) >= 0L) && g_174) | l_3672))) & g_174) != l_3664.f1), g_75)))) && g_75), g_875))), 2)) | 4294967292UL) & 0x8D92B91EL) == 251UL) >= l_3672) && g_75)) | 0x46L);
                        if (l_3842[6][4][6])
                            break;

if (g_274.f3)
                            continue;

                    g_759 = (safe_lshift_func_int8_t_s_u(0L, 4));
                    }

                    for (g_688 = 16; (g_688 < 15); g_688 = safe_sub_func_int8_t_s_s(g_688, 1))
            {
                uint32_t l_3684 = 0x5C0F1FBCL;
                struct S1 l_3691 = {242,-9,7696,49,79,208};

{
                    struct S1 l_3154 = {145,14,-8932,-31,30,59};
                    g_75 = g_1895.f0;
                    l_3687 = (l_3691 = l_3154);
                }

                    g_40[0] = ((g_112 = 0x6681L) > (safe_rshift_func_int16_t_s_u((l_3672 = l_3192), 1)));

g_688 += 1;


                    if (g_130.f1)
                {
                    struct S1 l_3689 = {208,-13,-2383,42,8,302};
                    p_5 = ((safe_rshift_func_int16_t_s_u(p_5, 14)) || (g_112 = (p_5 > ((((-2L) || (g_2569 & l_3675)) == (safe_lshift_func_int16_t_s_s((((0x95L > (-9L)) && ((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_s(l_3684, 0)), (((safe_sub_func_int8_t_s_s(((p_7 & 0x8A79L) == g_224), p_4)) || 0xDBL) < l_3684))) >= 0xA356877BL)) > 0L), 0))) | p_7))));


for (g_688 = 0; g_688 < 1; g_688++)
        l_3215[g_688] = 0x8B40L;

                    for (g_1896.f0 = 5; (g_1896.f0 > 20); g_1896.f0++)
                    {
                        uint8_t l_1925 = 0x3EL;

{
                    int32_t l_2157 = 6L;
                    struct S0 l_2166 = {0x1EE1138AL,-1097};
                    l_3688.f3 = ((0x95FDL || g_969) <= (((((((((l_3672 = l_2157) >= ((((g_875 = ((g_2.f2 = g_2569) <= (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_s((g_3484 >= (safe_add_func_int16_t_s_s(g_1058, (0xA0L < (safe_add_func_uint16_t_u_u(((g_2569 | 0xA63F201AL) ^ 0xCFF3DD30L), l_2157)))))), g_3662)) == g_130.f0), g_2317)))) | 65535UL) & l_2157) | g_2317)) < g_714) >= g_1897) > g_1135) > (-1L)) < g_2317) == l_3395.f3) > 1L));
                    g_130 = (g_130 = l_2166);
                }

                    l_3664.f2 = (0UL && ((((g_63 >= (g_658.f2 = (p_5 & (safe_mod_func_int32_t_s_s((g_310 = 0x050CE2D4L), (safe_add_func_int16_t_s_s((((safe_lshift_func_uint16_t_u_s(((g_1106 = ((safe_lshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u((l_3684 ^ 0xFFL), (l_3664.f1 = (safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(p_5, (g_688 = 1L))) == (g_658.f2 = (safe_rshift_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(g_647, l_1925)), g_174)))) <= (-3L)), l_3664.f3))))), 6)), l_3664.f0)), 0)) == 0xCC4DL)) & l_3688.f2), 11)) >= g_1135) <= (-1L)), 0x90D6L))))))) < l_3518) || g_1897) ^ 0x23L));
                        g_217[0] = (l_3519 = g_130);
                        l_3664 = l_3688;
                        if (p_5)
                            break;
                    };


                    l_3689 = (l_3688 = (l_3687 = l_3664));
                    for (g_1135 = 0; (g_1135 <= 0); g_1135 += 1)
                    {
                        if (p_5)
                            break;
                    }
                    l_3690[3][4] = g_274;
                }
                else
                {
                    if (g_3484)
                    {

if (g_1178)
                            break;

                    g_658 = (l_3691 = l_3691);
                        p_5 = (g_969 && p_6);
                    }
                    else
                    {


for (l_3712 = (-28); (l_3712 < 22); l_3712 = safe_add_func_int32_t_s_s(l_3712, 8))
            {
                for (g_2667 = 0; (g_2667 < 17); ++g_2667)
                {
                    return g_658.f3;
                }
            };


                    if (g_3484)
                            break;

                    g_211 = 1L;
                    }
                }
            }
            if (((safe_lshift_func_int8_t_s_s(g_274.f0, (g_1184 = (safe_mod_func_int16_t_s_s((l_3711 = (((((safe_mod_func_uint32_t_u_u((l_3698[0] = 0xB768A2D0L), p_6)) > (((safe_mod_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_u((l_3690[3][4].f1 = p_7), 2)), (((0x7197L | ((p_7 || (safe_sub_func_int8_t_s_s((safe_rshift_func_int8_t_s_u(((safe_mod_func_uint32_t_u_u((0xEEF7L >= (l_3688.f1 = (safe_lshift_func_int8_t_s_u(0xA0L, (l_3711 && g_1895.f0))))), l_3712)) > g_63), l_3518)), 0UL))) && p_5)) & 0xF1L) | 4294967292UL))) != p_6) | 4294967294UL)) | g_1106) < p_5) | l_3690[3][4].f2)), 0x4938L))))) & p_4))
            {
                l_3688 = l_3687;

{
        for (g_75 = 0; g_75 < 4; g_75++)
        {
            transparent_crc(g_3735[g_2569][g_75], "g_3735[g_2569][g_75]", l_3711);
            if (l_3711) {
for (l_3712 = 27; (l_3712 > (-25)); l_3712--)
                    {
                        uint32_t l_665 = 0xE8B9A2A8L;
                        int32_t l_668[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_668[i] = 0x75128752L;
                        g_1568 = (g_224 = l_665);
                        g_2.f1 = (l_668[1] = (g_658.f1 = l_665));
                        g_211 = g_1039;
                        j = l_3712;
                    };


                    printf("index = [%d][%d]\n", g_2569, g_75);}

        }
    }

                    g_647 = (+0xFAL);
            }
            else
            {


{
        uint32_t l_3675 = 0UL;
        struct S1 l_3690[4][6] = {{{114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}, {114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}}, {{114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}, {114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}}, {{114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}, {114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}}, {{114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}, {114,4,3877,54,161,357}, {114,4,3877,54,161,357}, {33,12,7133,-78,10,203}}};
        int32_t l_3711 = 0x89004967L;
        uint32_t l_3797[3][1];
        int i, j;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 1; j++)
                l_3797[i][j] = 0xEEBFC6BFL;
        }
        for (g_1039 = 0; (g_1039 <= 21); g_1039 = safe_add_func_int32_t_s_s(g_1039, 8))
        {
            int16_t l_3672 = 0x56DAL;
            struct S1 l_3687 = {189,20,-16362,38,121,6};
            struct S1 l_3688 = {105,-17,-2409,60,130,138};
            uint32_t l_3698[10];
            int8_t l_3712 = 0L;
            int i;
            for (i = 0; i < 10; i++)
                l_3698[i] = 0xD52D981BL;
            for (j = 16; (j < 15); j = safe_sub_func_int8_t_s_s(j, 1))
            {
                uint32_t l_3684 = 0x5C0F1FBCL;
                struct S1 l_3691 = {242,-9,7696,49,79,208};
                g_40[0] = ((g_112 = 0x6681L) > (safe_rshift_func_int16_t_s_u((l_3672 = g_759), 1)));
                if (g_130.f1)
                {
                    struct S1 l_3689 = {208,-13,-2383,42,8,302};
                    j = ((safe_rshift_func_int16_t_s_u(j, 14)) || (g_112 = (j > ((((-2L) || (j & l_3675)) == (safe_lshift_func_int16_t_s_s((((0x95L > (-9L)) && ((safe_lshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_s(l_3684, 0)), (((safe_sub_func_int8_t_s_s(((p_7 & 0x8A79L) == i), p_4)) || 0xDBL) < l_3684))) >= 0xA356877BL)) > 0L), 0))) | p_7))));
                    l_3689 = (l_3688 = (l_3687 = l_3687));
                    for (g_3484 = 0; (g_3484 <= 0); g_3484 += 1)
                    {
                        if (j)
                            break;
                    }
                    l_3690[3][4] = g_274;
                }
                else
                {
                    if (g_3484)
                    {
                        l_3687 = (l_3691 = l_3691);
                        j = (g_959 && l_3617);
                    }
                    else
                    {
                        g_1058 = 1L;
                    }
                }
            }
            if (((safe_lshift_func_int8_t_s_s(g_274.f0, (l_3712 = (safe_mod_func_int16_t_s_s((l_3711 = (((((safe_mod_func_uint32_t_u_u((l_3698[0] = 0xB768A2D0L), l_3617)) > (((safe_mod_func_uint32_t_u_u((safe_rshift_func_uint8_t_u_u((l_3690[3][4].f1 = p_7), 2)), (((0x7197L | ((p_7 || (safe_sub_func_int8_t_s_s((safe_rshift_func_int8_t_s_u(((safe_mod_func_uint32_t_u_u((0xEEF7L >= (l_3688.f1 = (safe_lshift_func_int8_t_s_u(0xA0L, (l_3711 && g_1895.f0))))), l_3712)) > l_3617), l_3617)), 0UL))) && j)) & 0xF1L) | 4294967292UL))) != l_3617) | 4294967294UL)) | g_1106) < j) | l_3690[3][4].f2)), 0x4938L))))) & p_4))
            {
                l_3688 = l_3687;
                j = (+0xFAL);
            }
            else
            {
                if (l_3688.f1)
                {
                    return g_714;
                }
                else
                {
                    return g_969;
                }
            }
        }
        if ((((safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u((!(l_3690[3][4].f1 = (!0xB0L))), l_3617)), l_3687.f3)) || (l_3690[3][4].f3 & ((p_7 || ((g_1178 = (l_3617 != l_3675)) && g_656.f5)) != (l_3465[6][1] = (safe_rshift_func_int8_t_s_s(l_3690[3][4].f5, l_3690[3][4].f1)))))) | j), l_3690[3][4].f3)) & l_3690[3][4].f5) != g_130.f1))
        {
            int16_t l_3733[6] = {0xA952L, 0L, 0xA952L, 0L, 0xA952L, 0L};
            int32_t l_3750 = 1L;
            int i;
            for (g_163 = 0; (g_163 <= 7); g_163 = safe_add_func_int8_t_s_s(g_163, 8))
            {
                int32_t l_3748 = 2L;
                int32_t l_3749 = 1L;
                int8_t l_3772 = 0x94L;
                for (g_959 = 0; (g_959 >= 0); g_959 -= 1)
                {
                    int32_t l_3751 = 0xD10EFF40L;
                    int i, j;
                    l_3465[g_959][(g_959 + 1)] = (((safe_add_func_int8_t_s_s(0x9DL, (safe_mod_func_int32_t_s_s((((249UL == p_4) | (j <= (g_656.f0 <= ((safe_add_func_uint32_t_u_u(((l_3733[0] < (~(g_3735[4][3] = l_3617))) >= (((((((((((((((l_3750 = (safe_unary_minus_func_int16_t_s(((safe_mod_func_int16_t_s_s(((safe_rshift_func_int8_t_s_s((safe_unary_minus_func_int16_t_s(((safe_mod_func_int32_t_s_s((safe_add_func_int8_t_s_s(((((safe_add_func_int32_t_s_s(((l_3748 = p_4) <= (g_1204 >= l_3749)), 0UL)) || 1UL) >= l_3687.f3) && 0L), p_4)), g_1895.f1)) ^ j))), g_274.f0)) && 0xE4L), l_3690[3][4].f0)) < g_274.f2)))) == p_4) ^ 0xB65E33D5L) ^ l_3751) > g_130.f1) ^ 0xB9E3L) & (-1L)) || 253UL) ^ 0x072AF1C0L) < (-1L)) ^ g_130.f0) <= p_4) < p_7) != 0xD9L) >= j)), l_3711)) == l_3617)))) > 0x9914651DL), g_688)))) & g_3484) == g_1039);
                    j = (safe_rshift_func_uint16_t_u_u((g_2.f1 = (safe_lshift_func_uint8_t_u_u((+(safe_sub_func_uint8_t_u_u(((((g_1895.f0 || l_3751) >= g_1056) <= (g_224 ^ ((safe_sub_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((l_3712 = g_1204), (safe_add_func_uint8_t_u_u(0x1FL, (safe_mod_func_uint16_t_u_u((((((((l_3690[3][4].f2 | (safe_lshift_func_int8_t_s_s((0x79L && ((safe_sub_func_int32_t_s_s((((g_2667 = 0x4DL) && (-1L)) <= j), 0xB04C4358L)) >= p_7)), 3))) >= l_3617) || p_7) >= l_3772) ^ g_759) | g_217[0].f1) >= g_1039), g_969)))))), p_7)) || j))) || j), 9UL))), 7))), 12));
                    g_3324 = l_3751;
                    if (l_3687.f1)
                        continue;
                }
                l_3687 = l_3687;
            }
            g_40[1] = (g_3484 && 0xCC87E0E5L);
        }
        else
        {
            uint32_t l_3774 = 0xFCBED209L;
            int16_t l_3793[9];
            int8_t l_3825 = 0xECL;
            int i;
            for (i = 0; i < 9; i++)
                l_3793[i] = (-1L);
            if (l_3774)
            {
                uint8_t l_3796 = 0x0AL;
                j = 0x7A362A30L;
                g_1895.f1 = ((safe_add_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s((((~(safe_mod_func_int16_t_s_s(0L, (safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u((g_3484 > 4294967288UL), 0)), (safe_rshift_func_int8_t_s_u(8L, (l_3797[0][0] = (p_4 || ((safe_rshift_func_uint16_t_u_s((safe_add_func_int8_t_s_s((!((l_3796 = ((l_3793[5] = 0xC669EB36L) != ((safe_sub_func_int32_t_s_s((g_40[0] = (j = j)), (l_3711 = j))) != (p_4 ^ g_274.f5)))) != p_7)), 0x63L)), g_1895.f0)) != g_224)))))))))) > g_274.f1) != j), 2)), l_3687.f5)) & p_4);
                for (g_3324 = 0; (g_3324 == (-28)); g_3324 = safe_sub_func_int32_t_s_s(g_3324, 3))
                {
                    int16_t l_3822 = 0x2756L;
                    l_3711 = ((((p_4 = p_4) < ((p_7 = 7UL) <= ((safe_lshift_func_int8_t_s_s((l_3712 = ((((safe_lshift_func_int8_t_s_u((g_40[0] >= (((l_3617 >= (g_2667 = (0UL < (safe_mod_func_uint8_t_u_u((((safe_rshift_func_int16_t_s_u(j, (((((safe_rshift_func_uint8_t_u_s(((((g_3484 = ((l_3690[3][4].f2 = (safe_sub_func_uint8_t_u_u(((g_759 = (safe_lshift_func_uint16_t_u_u(1UL, ((g_1039 | ((safe_mod_func_int8_t_s_s((((safe_lshift_func_int8_t_s_s((g_2.f1 >= g_1039), g_224)) || g_112) >= l_3617), 0xABL)) ^ l_3822)) ^ l_3617)))) & l_3617), g_656.f3))) | 0x1A997046L)) ^ 0UL) == l_3793[4]) != g_2.f3), 0)) || l_3822) > l_3711) >= l_3796) > (-1L)))) == l_3617) & 0L), 0x17L))))) >= j) == l_3617)), 3)) && g_3484) || 65528UL) ^ j)), 3)) == j))) && 0UL) < 0xB2L);
                }
                for (g_759 = 0; (g_759 < 26); g_759 = safe_add_func_int16_t_s_s(g_759, 3))
                {
                    uint32_t l_3835 = 0x0CE33761L;
                    if (l_3825)
                        break;
                    for (g_3484 = (-23); (g_3484 == 25); g_3484++)
                    {
                        int32_t l_3842[7][5][7] = {{{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}};
                        int i, j, k;
                        j = (((!g_274.f5) <= ((((((safe_rshift_func_uint8_t_u_u((g_2.f2 = (safe_mod_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s(l_3835, (safe_mod_func_int32_t_s_s((((safe_add_func_uint16_t_u_u(l_3617, ((((g_1135 = ((safe_add_func_int8_t_s_s((l_3842[6][4][6] = 0x7AL), (~((safe_sub_func_int8_t_s_s(((((safe_rshift_func_int16_t_s_u(g_969, 4)) ^ 0xDB1D7EE1L) == p_4) != l_3690[3][4].f4), ((p_4 >= l_3774) <= 3UL))) < 1UL)))) > 0x0DFFBBBEL)) >= 0L) && p_7) | g_959))) & p_7) != l_3687.f1), j)))) && j), j))), 2)) | 4294967292UL) & 0x8D92B91EL) == 251UL) >= g_1204) && j)) | 0x46L);
                        if (l_3842[6][4][6])
                            break;
                        l_3711 = (safe_lshift_func_int8_t_s_u(0L, 4));
                    }
                }
            }
            else
            {
                return g_274.f0;
            }
            return l_3617;
        }
        g_3324 = l_3690[3][4].f2;
    }

                    if (l_3712)
                        break;


{
            for (g_310 = 0; g_310 < 1; g_310++)
                l_3797[g_237][g_310] = 0xEEBFC6BFL;
        }

                    if (l_3688.f1)
                {
                    return l_3714;
                }
                else
                {
                    return g_959;
                }
            }
        }

if ((safe_mod_func_int16_t_s_s(((g_3484 <= ((safe_sub_func_uint8_t_u_u(0x9BL, ((g_237 = (safe_rshift_func_int8_t_s_u(g_1106, g_217[0].f1))) != (l_3465[7][4] = (g_1897 = ((safe_lshift_func_uint16_t_u_u(g_1056, 13)) ^ g_112)))))) <= ((g_112 && (safe_mod_func_int16_t_s_s(((g_1568 = (g_2.f1 = ((((l_3485 = (((!0x76271C1FL) ^ (safe_sub_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(((safe_add_func_int16_t_s_s(((g_1897 = (g_1897 = ((((j = ((l_3518 = 0x19E28945L) ^ g_2.f0)) <= l_3485) && g_1056) & g_1056))) <= (-9L)), 65535UL)) != l_3485), 3L)), g_3484))) | 0x20L)) ^ g_3484) | g_2.f2) ^ g_1568))) & 0L), l_3675))) > g_3484))) && g_3484), g_740)))
            {
                struct S0 l_3520[3] = {{-4L,-2011}, {-4L,-2011}, {-4L,-2011}};
                struct S1 l_3522 = {0,8,818,-84,160,233};
                int i;
                g_130 = (l_3520[1] = g_1895);
                l_3522 = g_2;
            }
            else
            {
                int32_t l_3528 = (-10L);
                g_1568 = (g_740 <= (safe_lshift_func_int8_t_s_u((((g_1895.f1 > 1UL) > (safe_lshift_func_uint8_t_u_u(0x0AL, (((!((g_1897 = l_3528) ^ (-4L))) < (l_3518 = (((((g_1056 || g_2.f5) == 0xD141EB83L) & g_2.f4) >= 1UL) & g_3484))) | 0xA348L)))) || (-1L)), 0)));
                g_2.f3 = ((((((0x23L < (((l_3528 == ((l_3518 > (g_971 & j)) || ((((safe_sub_func_int32_t_s_s((g_759 = g_2.f3), (((0xCEL == (safe_add_func_int32_t_s_s(g_1897, (((((((((0xF731AC28L < g_3242[3]) | g_130.f0) | g_2.f1) == g_69) <= 0x620DL) & g_2.f3) >= (-7L)) > 0xD885ADEAL) | j)))) == l_3485) || 4294967295UL))) || 0x35FAL) <= l_3528) <= 0x8EDAE74BL))) != 65532UL) <= g_2.f4)) & g_2667) | g_1056) & g_3484) | g_237) & g_130.f0);
            }
for (g_688 = 0; g_688 < 1; g_688++)
                l_3797[g_224][g_688] = 0xEEBFC6BFL;

                    ;


                    if ((((safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u((!(l_3690[3][4].f1 = (!0xB0L))), g_971)), g_658.f3)) || (l_3690[3][4].f3 & ((p_7 || ((g_714 = (g_1039 != l_3675)) && g_656.f5)) != (l_3465[6][1] = (safe_rshift_func_int8_t_s_s(l_3690[3][4].f5, l_3690[3][4].f1)))))) | p_5), l_3690[3][4].f3)) & l_3690[3][4].f5) != g_130.f1))
        {
            int16_t l_3733[6] = {0xA952L, 0L, 0xA952L, 0L, 0xA952L, 0L};
            int32_t l_3750 = 1L;
            int i;
            for (g_163 = 0; (g_163 <= 7); g_163 = safe_add_func_int8_t_s_s(g_163, 8))
            {
                int32_t l_3748 = 2L;
                int32_t l_3749 = 1L;
                int8_t l_3772 = 0x94L;
                for (g_969 = 0; (g_969 >= 0); g_969 -= 1)
                {
                    int32_t l_3751 = 0xD10EFF40L;
                    int i, j;
                    l_3465[g_969][(g_969 + 1)] = (((safe_add_func_int8_t_s_s(0x9DL, (safe_mod_func_int32_t_s_s((((249UL == p_4) | (p_5 <= (g_656.f0 <= ((safe_add_func_uint32_t_u_u(((l_3733[0] < (~(g_3735[4][3] = g_63))) >= (((((((((((((((l_3750 = (safe_unary_minus_func_int16_t_s(((safe_mod_func_int16_t_s_s(((safe_rshift_func_int8_t_s_s((safe_unary_minus_func_int16_t_s(((safe_mod_func_int32_t_s_s((safe_add_func_int8_t_s_s(((((safe_add_func_int32_t_s_s(((l_3748 = p_4) <= (g_1204 >= l_3749)), 0UL)) || 1UL) >= g_658.f3) && 0L), p_4)), g_1895.f1)) ^ p_5))), g_274.f0)) && 0xE4L), l_3690[3][4].f0)) < g_2.f2)))) == p_4) ^ 0xB65E33D5L) ^ l_3751) > g_130.f1) ^ 0xB9E3L) & (-1L)) || 253UL) ^ 0x072AF1C0L) < (-1L)) ^ g_130.f0) <= p_4) < p_7) != 0xD9L) >= p_5)), l_3711)) == p_6)))) > 0x9914651DL), g_75)))) & g_1135) == g_174);
                    p_5 = (safe_rshift_func_uint16_t_u_u((l_3395.f1 = (safe_lshift_func_uint8_t_u_u((+(safe_sub_func_uint8_t_u_u(((((g_1896.f0 || l_3751) >= g_415) <= (g_875 ^ ((safe_sub_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((g_1184 = l_3763), (safe_add_func_uint8_t_u_u(0x1FL, (safe_mod_func_uint16_t_u_u((((((((l_3690[3][4].f2 | (safe_lshift_func_int8_t_s_s((0x79L && ((safe_sub_func_int32_t_s_s((((g_2667 = 0x4DL) && (-1L)) <= p_5), 0xB04C4358L)) >= p_7)), 3))) >= g_740) || p_7) >= l_3772) ^ g_237) | g_217[0].f1) >= g_69), l_3773)))))), p_7)) || g_688))) || g_1568), 9UL))), 7))), 12));
                    g_759 = l_3751;
                    if (g_658.f1)
                        continue;
                }
                g_658 = l_3664;
            }

{
                int32_t l_3528 = (-10L);
                l_3711 = (g_2214 <= (safe_lshift_func_int8_t_s_u((((g_1895.f1 > 1UL) > (safe_lshift_func_uint8_t_u_u(0x0AL, (((!((g_1897 = l_3528) ^ (-4L))) < (g_174 = (((((g_1056 || g_658.f5) == 0xD141EB83L) & g_658.f4) >= 1UL) & l_3714))) | 0xA348L)))) || (-1L)), 0)));
                g_658.f3 = ((((((0x23L < (((l_3528 == ((g_174 > (g_740 & j)) || ((((safe_sub_func_int32_t_s_s((l_3750 = g_656.f3), (((0xCEL == (safe_add_func_int32_t_s_s(l_3714, (((((((((0xF731AC28L < g_3242[3]) | g_130.f0) | g_658.f1) == g_740) <= 0x620DL) & g_656.f3) >= (-7L)) > 0xD885ADEAL) | j)))) == l_3485) || 4294967295UL))) || 0x35FAL) <= l_3528) <= 0x8EDAE74BL))) != 65532UL) <= g_656.f4)) & l_3150) | g_1056) & l_3714) | l_3750) & g_130.f0);
            }

                    g_40[1] = (g_264 && 0xCC87E0E5L);
        }
        else
        {
            uint32_t l_3774 = 0xFCBED209L;
            int16_t l_3793[9];
            int8_t l_3825 = 0xECL;
            int i;
            for (i = 0; i < 9; i++)
                l_3793[i] = (-1L);

for (g_415 = 0; (g_415 <= 11); ++g_415)
                    {
                        int16_t l_146 = 0xA7B7L;
                        l_3395 = g_274;

for (g_900 = 0; (g_900 <= 1); g_900 += 1)
                {
                    int i;
                    g_217[0] = g_217[p_4];
                };


                    g_1896 = g_1896;

{
                        g_1896.f1 = (g_2.f3 ^ (safe_lshift_func_int8_t_s_u(g_658.f2, (safe_add_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((g_658.f0 <= g_658.f0), g_1056)), (g_1135 = (safe_mod_func_uint32_t_u_u((((((safe_mod_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s(g_3324, g_658.f0)), g_274.f5)) | l_3664.f0) <= g_2.f5) & l_3664.f4) != g_2569), g_174))))), 0L)))));
                    }

                    l_146 = ((safe_rshift_func_int16_t_s_u(((((g_211 = 0xE8AE3155L) & (g_415 != (-1L))) >= (safe_lshift_func_int8_t_s_u((g_3662 = (!((safe_sub_func_int16_t_s_s((p_7 <= ((g_40[1] <= ((safe_rshift_func_uint8_t_u_s((((l_3395.f1 = (((safe_mod_func_uint32_t_u_u((g_112 == (g_1039 ^ ((safe_mod_func_uint16_t_u_u(g_1896.f0, 1L)) && l_3483))), g_1184)) <= g_274.f4) == 0x0C3003DDL)) & g_415) | g_415), 7)) >= l_3395.f3)) && 1UL)), g_274.f5)) == 0xE0L))), 0))) | g_1039), g_274.f2)) == g_274.f4);
                    }
for (g_959 = 6; (g_959 >= 1); g_959 -= 1)
                {
                    struct S0 l_3535 = {0x11C838F9L,694};
                    l_3535 = (g_1896 = l_3519);
                };


                    ;


                    if (l_3774)
            {
                uint8_t l_3796 = 0x0AL;
                p_5 = 0x7A362A30L;
                l_3519.f1 = ((safe_add_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s((((~(safe_mod_func_int16_t_s_s(0L, (safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u((g_3484 > 4294967288UL), 0)), (safe_rshift_func_int8_t_s_u(8L, (l_3797[0][0] = (p_4 || ((safe_rshift_func_uint16_t_u_s((safe_add_func_int8_t_s_s((!((l_3796 = ((l_3793[5] = 0xC669EB36L) != ((safe_sub_func_int32_t_s_s((g_40[0] = (g_1568 = p_5)), (g_310 = g_688))) != (p_4 ^ g_274.f5)))) != p_7)), 0x63L)), l_3519.f0)) != g_875)))))))))) > g_274.f1) != p_5), 2)), g_658.f5)) & p_4);
                for (g_759 = 0; (g_759 == (-28)); g_759 = safe_sub_func_int32_t_s_s(g_759, 3))
                {
                    int16_t l_3822 = 0x2756L;

for (g_237 = 0; g_237 < 2; g_237++)
            {
                transparent_crc(g_1177[g_211][g_75][g_237], "g_1177[g_211][g_75][g_237]", g_310);
                if (g_310) printf("index = [%d][%d][%d]\n", g_211, g_75, g_237);

            };


                    l_3711 = ((((p_4 = p_4) < ((p_7 = 7UL) <= ((safe_lshift_func_int8_t_s_s((g_1184 = ((((safe_lshift_func_int8_t_s_u((g_40[0] >= (((p_6 >= (g_2667 = (0UL < (safe_mod_func_uint8_t_u_u((((safe_rshift_func_int16_t_s_u(g_2569, (((((safe_rshift_func_uint8_t_u_s(((((g_1135 = ((l_3690[3][4].f2 = (safe_sub_func_uint8_t_u_u(((l_3192 = (safe_lshift_func_uint16_t_u_u(1UL, ((g_2214 | ((safe_mod_func_int8_t_s_s((((safe_lshift_func_int8_t_s_s((l_3395.f1 >= g_2214), g_875)) || g_112) >= p_6), 0xABL)) ^ l_3822)) ^ p_6)))) & p_6), g_656.f3))) | 0x1A997046L)) ^ 0UL) == l_3793[4]) != l_3395.f3), 0)) || l_3822) > l_3711) >= l_3796) > (-1L)))) == p_6) & 0L), 0x17L))))) >= p_5) == p_6)), 3)) && g_1135) || 65528UL) ^ p_5)), 3)) == g_2569))) && 0UL) < 0xB2L);
                }
                for (g_237 = 0; (g_237 < 26); g_237 = safe_add_func_int16_t_s_s(g_237, 3))
                {
                    uint32_t l_3835 = 0x0CE33761L;
                    if (l_3825)
                        break;
                    for (g_3484 = (-23); (g_3484 == 25); g_3484++)
                    {
                        int32_t l_3842[7][5][7] = {{{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}, {{0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}, {0xF492A5FEL, 0x82DE5A1DL, 0x6B44038FL, (-1L), 8L, 0L, 8L}}};
                        int i, j, k;

g_1896.f0 += 1;


                    p_5 = (((!g_274.f5) <= ((((((safe_rshift_func_uint8_t_u_u((l_3395.f2 = (safe_mod_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_s(l_3835, (safe_mod_func_int32_t_s_s((((safe_add_func_uint16_t_u_u(p_6, ((((g_1897 = ((safe_add_func_int8_t_s_s((l_3842[6][4][6] = 0x7AL), (~((safe_sub_func_int8_t_s_s(((((safe_rshift_func_int16_t_s_u(g_959, 4)) ^ 0xDB1D7EE1L) == p_4) != l_3690[3][4].f4), ((p_4 >= l_3774) <= 3UL))) < 1UL)))) > 0x0DFFBBBEL)) >= 0L) && p_7) | g_969))) & p_7) != l_3664.f1), p_5)))) && p_5), g_688))), 2)) | 4294967292UL) & 0x8D92B91EL) == 251UL) >= g_1204) && p_5)) | 0x46L);
                        if (l_3842[6][4][6])
                            break;
                        g_310 = (safe_lshift_func_int8_t_s_u(0L, 4));
                    }
                }
            }
            else
            {
                return g_2.f0;
            }
            return p_6;
        }
        g_759 = l_3690[3][4].f2;
    }
    return g_130.f0;
}







static uint16_t func_8(int32_t p_9, uint32_t p_10)
{
    int32_t l_3021 = (-3L);
    int32_t l_3076 = 0L;
    struct S1 l_3077 = {194,-7,7616,49,73,331};
    struct S0 l_3079[3] = {{0xDA2CB06EL,1272}, {0xDA2CB06EL,1272}, {0xDA2CB06EL,1272}};
    struct S1 l_3109 = {119,-4,-10417,-36,96,221};
    int i;
    for (g_1056 = 5; (g_1056 == 2); --g_1056)
    {
        int32_t l_3005 = 7L;
        int32_t l_3011 = 0L;
        uint32_t l_3101 = 0xFDC593CDL;
        g_274.f3 = (safe_lshift_func_uint8_t_u_s(g_2667, 5));
        if (l_3005)
            break;
        if (((p_9 = (((safe_sub_func_int16_t_s_s(p_10, (!(safe_mod_func_int8_t_s_s((l_3011 = l_3005), p_10))))) >= (safe_mod_func_int16_t_s_s((+((safe_lshift_func_int8_t_s_u((safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s(l_3021, 0)) != g_658.f2), (safe_rshift_func_int8_t_s_s((g_2667 = (safe_sub_func_uint8_t_u_u(((g_2569 > (safe_add_func_uint8_t_u_u(((g_130.f1 || (safe_rshift_func_uint16_t_u_s(((((0x78L <= (safe_mod_func_uint32_t_u_u(((safe_lshift_func_uint16_t_u_u(((l_3021 == 0L) && p_9), g_40[0])) || g_2.f5), l_3005))) | p_10) == 0x869AB182L) ^ p_10), l_3005))) ^ 1L), g_217[0].f0))) && p_10), l_3005))), 1)))), l_3005)) ^ (-3L))), 0x4E89L))) == l_3005)) | g_613))
        {
            int16_t l_3049[1];
            int32_t l_3060 = (-1L);
            int32_t l_3067 = 0L;
            int32_t l_3074 = 0xA37F3276L;
            struct S1 l_3078 = {127,-0,-15401,63,36,141};
            struct S0 l_3082[3] = {{0x4AF132A0L,1413}, {0x4AF132A0L,1413}, {0x4AF132A0L,1413}};
            int i;
            for (i = 0; i < 1; i++)
                l_3049[i] = (-3L);

l_3005 -= 1;


                    for (g_2569 = 0; (g_2569 >= 0); g_2569 -= 1)
            {
                int32_t l_3063 = 0x16C57B5CL;
                g_40[0] = ((((-1L) | ((p_10 && (((safe_mod_func_uint8_t_u_u((g_2.f1 == (l_3011 = (safe_lshift_func_int8_t_s_u(((+0xD0A1L) ^ (safe_add_func_int32_t_s_s((p_9 = (g_211 = (~(((g_1184 = 1L) || (p_10 || ((safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u((!((((g_1184 = (((g_211 ^ (safe_sub_func_uint32_t_u_u(p_9, l_3049[0]))) ^ 0UL) ^ g_274.f3)) ^ 248UL) > g_224) > 5L)), 1)), l_3011)) | g_1895.f1))) >= g_959)))), 1UL))), g_1177[2][3][1])))), l_3005)) != g_2.f4) | l_3021)) || l_3049[0])) && (-1L)) <= g_274.f2);

{
            uint32_t l_2366 = 0UL;
            g_1568 = l_2366;
            g_224 = (-1L);
        }

                    if ((safe_sub_func_uint8_t_u_u((((((0xFAL > ((safe_lshift_func_int8_t_s_s((safe_unary_minus_func_int16_t_s(l_3049[0])), 1)) || (g_969 = (((!((((0xCBL < (4294967295UL < ((p_9 = (0x7C74476EL & ((g_1106 = 1UL) != ((safe_add_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((l_3060 = p_10), (safe_mod_func_int32_t_s_s(l_3063, ((((safe_rshift_func_int16_t_s_s(l_3049[0], l_3021)) != 0x991EL) || 6L) || l_3021))))), l_3049[0])) | l_3011)))) != g_224))) ^ l_3005) > 1L) | g_274.f5)) | p_10) | l_3063)))) || l_3060) > p_10) < g_1895.f1) != p_10), l_3021)))
                {
                    int16_t l_3066 = 7L;
                    struct S0 l_3083 = {7L,-1036};
                    struct S0 l_3084[3][4] = {{{0xD323E343L,-637}, {-1L,-1009}, {-2L,-9}, {-1L,-1009}}, {{0xD323E343L,-637}, {-1L,-1009}, {-2L,-9}, {-1L,-1009}}, {{0xD323E343L,-637}, {-1L,-1009}, {-2L,-9}, {-1L,-1009}}};
                    int i, j;
                    if ((l_3049[0] | g_658.f2))
                    {
                        int8_t l_3075 = 0L;

for (g_415 = 0; (g_415 <= 0); g_415 += 1)
        {
            g_1896.f1 = ((g_211 && ((g_2.f2 = 0xDDE33A30L) != ((g_211 <= (g_40[1] == (safe_add_func_uint16_t_u_u((g_415 = 3UL), g_69)))) != 8UL))) && g_211);
            g_224 = g_2.f4;
            for (g_1896.f0 = 1; (g_1896.f0 >= 0); g_1896.f0 -= 1)
            {
                g_656.f3 = (safe_sub_func_int16_t_s_s(0L, 0L));
                for (p_10 = 0; (p_10 <= 1); p_10 += 1)
                {
                    int i;
                    g_217[0] = g_217[g_415];
                }
            }
        };


                    g_310 = ((p_9 ^ ((l_3067 = (((g_1184 == (l_3060 = (-1L))) == 0x60L) || (g_2667 = l_3066))) ^ 4L)) < ((p_10 > (safe_add_func_int8_t_s_s(((+(l_3076 = (safe_unary_minus_func_int16_t_s(((p_10 ^ (safe_rshift_func_int16_t_s_u((g_1204 = ((0L & l_3074) >= l_3075)), 1))) < l_3075))))) & l_3049[0]), 0x13L))) < p_9));
                    }
                    else
                    {
                        return p_10;
                    }

{
                        g_1568 = 1L;
                    }

                    for (g_69 = 0; (g_69 <= 0); g_69 += 1)
                    {
                        int i;
                        l_3078 = l_3077;

{
                        return g_658.f2;
                    }

                    l_3079[2] = g_217[g_69];
                    }
                    p_9 = (safe_lshift_func_int16_t_s_u(1L, 4));
                    l_3084[1][3] = (l_3082[2] = (l_3083 = l_3082[2]));
                }
                else
                {
                    if (l_3063)
                        break;
                    return p_10;
                }
            }
            p_9 = ((safe_sub_func_uint32_t_u_u((safe_lshift_func_int16_t_s_u((g_658.f0 && (safe_mod_func_uint16_t_u_u((0x6DL || (g_1184 = (l_3011 = (safe_rshift_func_int16_t_s_u((safe_lshift_func_uint8_t_u_s((l_3078.f4 < ((l_3078.f1 = (((safe_mod_func_uint16_t_u_u(p_10, (254UL ^ (l_3077.f2 = l_3011)))) & (((((l_3076 && ((safe_add_func_uint16_t_u_u((0x706DL != ((safe_lshift_func_int16_t_s_u(l_3082[2].f0, g_1177[2][3][1])) >= 0xFEL)), l_3101)) ^ 0xE8L)) | g_217[0].f1) && 0xC0L) <= l_3101) ^ g_688)) | g_1895.f0)) ^ 0x578AL)), p_9)), 10))))), g_2214))), 1)), 0x8D7FFE03L)) || g_656.f1);
            return g_274.f0;
        }
        else
        {
            for (g_415 = 0; (g_415 < 31); g_415 = safe_add_func_int16_t_s_s(g_415, 5))
            {

{
                struct S1 l_655 = {224,20,14000,-67,46,41};
                g_658 = (g_2 = (l_3077 = (l_3109 = l_655)));
            }

                    for (g_969 = 26; (g_969 >= 28); g_969 = safe_add_func_uint32_t_u_u(g_969, 4))
                {
                    for (g_174 = 0; (g_174 != 48); g_174++)
                    {
                        struct S1 l_3108 = {238,8,4487,-23,133,252};
                        g_2569 = p_9;
                        g_274 = l_3108;
                        if (g_224)
                            continue;
                    }
                }
            }
        }
        if (g_2098)
            continue;
    }
                                   int32_t BHJHJg_310 = (~(((((l_3109.f4 & l_3109.f2) + g_2.f5) % l_3077.f0) % (((~((~((g_1106 * l_3077.f2))))) | (g_2.f4 + (~(l_3077.f3)))) & (g_274.f2 % (~(g_310)))))));
int32_t BHJHJbg_274_f2 = (~(((~((~((BHJHJg_310 + ((~(l_3077.f0)) + l_3077.f2)))))) % ((g_2.f4 + ((~((~(l_3109.f2)))) % (~((l_3077.f3 % (g_310 % l_3109.f4)))))) % (g_2.f5 % (g_1106 % g_274.f2))))));
int16_t BHJHJcl_3077_f3 = (~(((~(((~(g_2.f5)) % g_310))) + (~((((((g_2.f4 >> ((l_3077.f0 * ((~(BHJHJg_310)) % BHJHJbg_274_f2)) || g_1106)) * l_3109.f4) || l_3109.f2) ^ (~((~(((~(l_3077.f2)) ^ g_274.f2)))))) % l_3077.f3))))));
uint32_t BHJHJdg_2_f5 = (~((((~((~((BHJHJg_310 ^ (l_3077.f3 * l_3109.f4)))))) ^ (~((((g_310 + (~(g_1106))) || (~((~(g_274.f2))))) << (g_2.f4 || (((~((~(BHJHJcl_3077_f3)))) * (~(BHJHJbg_274_f2))) || (~(l_3109.f2)))))))) | (~(((~((g_2.f5 ^ l_3077.f2))) || l_3077.f0))))));
uint16_t BHJHJeg_2_f4 = (~(((~(((~((g_2.f4 + (~(((l_3077.f3 || (~(g_2.f5))) << BHJHJdg_2_f5)))))) | l_3077.f0))) % (~((((~(((~(BHJHJcl_3077_f3)) + l_3109.f4))) || (BHJHJg_310 % BHJHJbg_274_f2)) >> ((g_274.f2 * (~(g_1106))) || ((l_3077.f2 ^ l_3109.f2) ^ g_310))))))));
uint16_t BHJHJfl_3077_f0 = (~(((((~((~(BHJHJbg_274_f2)))) * (~(l_3109.f4))) + ((~(((l_3077.f2 * (g_1106 || BHJHJeg_2_f4)) & (~((~(BHJHJg_310))))))) | (~(g_310)))) | (~((~(((l_3077.f0 ^ (((l_3109.f2 + (l_3077.f3 || BHJHJdg_2_f5)) & g_2.f5) + (g_274.f2 ^ g_2.f4))) || (~((~(BHJHJcl_3077_f3))))))))))));
if(l_3077.f3){
BHJHJg_310 = g_310;
BHJHJbg_274_f2 = g_274.f2;
BHJHJcl_3077_f3 = l_3077.f3;
BHJHJdg_2_f5 = g_2.f5;
BHJHJeg_2_f4 = g_2.f4;
BHJHJfl_3077_f0 = l_3077.f0;
g_310 = (~(((((~((~(l_3077.f0)))) + l_3109.f2) * (~(((~((~(g_2.f4)))) << ((((g_2.f5 % BHJHJdg_2_f5) % l_3077.f3) & (~(BHJHJfl_3077_f0))) * (~(((g_1106 | (~(l_3077.f2))) & ((BHJHJcl_3077_f3 ^ (~(g_274.f2))) * BHJHJbg_274_f2))))))))) + (~((~((~(((BHJHJeg_2_f4 & g_310) % (BHJHJg_310 % (~(l_3109.f4)))))))))))));
g_274.f2 = (~((((((~((~(l_3077.f2)))) * ((l_3109.f2 | (((g_2.f5 % g_1106) & g_274.f2) | (BHJHJdg_2_f5 % BHJHJg_310))) * BHJHJfl_3077_f0)) || ((~((BHJHJeg_2_f4 || g_2.f4))) % (~((~(l_3109.f4)))))) * (~((~(l_3077.f0))))) ^ (((~(((~(BHJHJcl_3077_f3)) || g_310))) | (~((~(l_3077.f3))))) + (~((~(BHJHJbg_274_f2))))))));
l_3077.f3 = (~(((((((((~(g_1106)) + ((BHJHJcl_3077_f3 & BHJHJdg_2_f5) ^ g_310)) + (~(BHJHJbg_274_f2))) * g_2.f4) % g_2.f5) * (~((l_3077.f2 % (((~(l_3109.f2)) * (~(BHJHJfl_3077_f0))) ^ (~(g_274.f2))))))) % (~(((l_3109.f4 | BHJHJg_310) * (BHJHJeg_2_f4 || (~(l_3077.f3))))))) ^ (~((~(l_3077.f0)))))));
                                   if ((l_3077.f0 > g_613))
                    g_2.f5 = (~(((~((~(((~((BHJHJg_310 % (g_274.f2 ^ BHJHJfl_3077_f0)))) | (BHJHJcl_3077_f3 + ((l_3077.f0 & g_310) << (l_3077.f2 % ((~(l_3109.f4)) || (BHJHJdg_2_f5 * (~(g_2.f5)))))))))))) || (~(((~((g_1106 + (BHJHJbg_274_f2 || (~(g_2.f4)))))) & ((~((BHJHJeg_2_f4 ^ l_3077.f3))) * (~(l_3109.f2)))))))));
g_2.f4 = (~((l_3109.f4 || ((~((~(BHJHJcl_3077_f3)))) * (~((((~(l_3077.f0)) || (((~((l_3077.f2 % g_2.f5))) ^ (~((l_3077.f3 || ((g_274.f2 & g_310) ^ BHJHJeg_2_f4))))) | (l_3109.f2 * (~(((BHJHJdg_2_f5 ^ (~(g_2.f4))) || (~((~(BHJHJg_310)))))))))) | (g_1106 ^ (BHJHJfl_3077_f0 * BHJHJbg_274_f2)))))))));
l_3077.f0 = (~(((~(((~((~(l_3077.f2)))) % (~((((~(g_2.f4)) | (l_3109.f4 | (~((~(l_3077.f3)))))) & (~((BHJHJbg_274_f2 || l_3109.f2))))))))) & (~((l_3077.f0 | ((~((((~(BHJHJdg_2_f5)) % ((g_2.f5 % g_274.f2) ^ g_310)) ^ BHJHJcl_3077_f3))) % (BHJHJeg_2_f4 * (~(((BHJHJfl_3077_f0 * g_1106) + BHJHJg_310)))))))))));
if((((BHJHJcl_3077_f3 < l_3077.f2) && l_3077.f0) && ((l_3077.f2<7616) || (BHJHJg_310 > g_274.f2)))){
printf("g_310=%lld\n", (long long)g_310);

for (BHJHJfl_3077_f0 = 0; (BHJHJfl_3077_f0 <= 0); BHJHJfl_3077_f0 += 1)
        {
            g_1895.f1 = ((g_688 && ((g_656.f2 = 0xDDE33A30L) != ((g_688 <= (g_40[1] == (safe_add_func_uint16_t_u_u((BHJHJfl_3077_f0 = 3UL), g_740)))) != 8UL))) && g_688);
            BHJHJg_310 = g_656.f4;
            for (g_1895.f0 = 1; (g_1895.f0 >= 0); g_1895.f0 -= 1)
            {
                g_656.f3 = (safe_sub_func_int16_t_s_s(0L, 0L));
                for (g_740 = 0; (g_740 <= 1); g_740 += 1)
                {
                    int i;
                    g_217[0] = g_217[BHJHJfl_3077_f0];
                }
            }
        };


                    BHJHJfl_3077_f0 = (~((((((~((~(((~((BHJHJg_310 | g_2.f5))) % (BHJHJfl_3077_f0 % l_3109.f2)))))) >> (~((~(g_310))))) % (~((~(BHJHJdg_2_f5))))) || (l_3077.f0 << (~(g_274.f2)))) % ((((~(l_3077.f2)) % l_3077.f3) * ((~(BHJHJeg_2_f4)) | (g_2.f4 ^ BHJHJbg_274_f2))) + ((~(g_1106)) | (l_3109.f4 * BHJHJcl_3077_f3))))));
BHJHJeg_2_f4 = (~(((~((~(((~((~((~((~(BHJHJfl_3077_f0)))))))) << (~((((~((~((l_3077.f2 + g_1106))))) * (~((~(l_3109.f4))))) | (~((BHJHJdg_2_f5 << (g_2.f4 << BHJHJcl_3077_f3)))))))))))) % (((((BHJHJg_310 & g_310) | l_3109.f2) || (~(l_3077.f0))) % (~((((~((~(g_274.f2)))) || BHJHJeg_2_f4) >> (l_3077.f3 << BHJHJbg_274_f2))))) ^ (~((~(g_2.f5))))))));
BHJHJg_310 = (~(((((~((l_3077.f3 || BHJHJg_310))) ^ ((BHJHJcl_3077_f3 % g_2.f5) ^ l_3077.f2)) | ((~(((~((~(g_2.f4)))) | BHJHJbg_274_f2))) * (~(BHJHJdg_2_f5)))) << ((~((((~(BHJHJeg_2_f4)) >> (~((l_3109.f2 >> l_3077.f0)))) << (~(l_3109.f4))))) << (BHJHJfl_3077_f0 & ((g_274.f2 + g_310) % g_1106))))));
}
if((g_274.f2 < BHJHJg_310)){
printf("g_274.f2=%lld\n", (long long)g_274.f2);
g_274.f2 = (~(((((~((g_274.f2 ^ l_3077.f3))) || ((~(BHJHJcl_3077_f3)) >> (~((~(BHJHJfl_3077_f0)))))) | (~((g_2.f5 * BHJHJeg_2_f4)))) | ((BHJHJg_310 | (g_1106 * g_310)) << (((BHJHJbg_274_f2 % l_3077.f2) & (l_3109.f4 >> BHJHJdg_2_f5)) & (((~(l_3109.f2)) % (~(g_2.f4))) & (~(l_3077.f0))))))));
BHJHJfl_3077_f0 = (~((BHJHJbg_274_f2 >> (~((~((((g_1106 ^ ((((~(g_2.f5)) & BHJHJcl_3077_f3) || (l_3077.f0 << BHJHJeg_2_f4)) + l_3077.f2)) & (~((BHJHJdg_2_f5 & l_3077.f3)))) << ((~(((~((~(l_3109.f4)))) << ((l_3109.f2 + (~((~(g_274.f2))))) << ((~(g_2.f4)) >> BHJHJg_310))))) % (~((g_310 << BHJHJfl_3077_f0))))))))))));
BHJHJeg_2_f4 = (~((((~(((~(BHJHJdg_2_f5)) | (~((~((~(g_2.f5))))))))) + ((~((~(BHJHJg_310)))) >> (~(((~(l_3077.f0)) + BHJHJbg_274_f2))))) ^ (~((~(((~(((~(((g_1106 | l_3109.f2) * (~((g_310 % l_3077.f3)))))) * l_3077.f2))) >> ((~(BHJHJcl_3077_f3)) << (((BHJHJfl_3077_f0 % (g_274.f2 >> BHJHJeg_2_f4)) | g_2.f4) * l_3109.f4))))))))));
}
if(((!BHJHJdg_2_f5) && g_1106)){
printf("l_3077.f3=%lld\n", (long long)l_3077.f3);
BHJHJbg_274_f2 = (~((((g_274.f2 + ((l_3109.f4 || (~(BHJHJbg_274_f2))) << (~(BHJHJeg_2_f4)))) | (((BHJHJfl_3077_f0 + (~(g_2.f5))) | (g_2.f4 % g_310)) ^ (~((((l_3077.f2 * g_1106) << (~(l_3077.f0))) & (~(BHJHJcl_3077_f3))))))) | (~((~((~((~((~((BHJHJdg_2_f5 + ((~(l_3077.f3)) ^ (l_3109.f2 % BHJHJg_310))))))))))))))));
BHJHJfl_3077_f0 = (~(((~((((g_2.f4 ^ (~(g_274.f2))) ^ (~(l_3109.f2))) | ((g_1106 | (~(l_3077.f0))) | (~(l_3077.f2)))))) || (~((~(((~(((~(l_3077.f3)) << (~((g_2.f5 + BHJHJfl_3077_f0)))))) + ((BHJHJbg_274_f2 % l_3109.f4) >> (BHJHJcl_3077_f3 + ((BHJHJg_310 + g_310) % (BHJHJeg_2_f4 << BHJHJdg_2_f5))))))))))));
g_274.f2 = (~((((~((~((~(g_2.f5)))))) || (~(BHJHJbg_274_f2))) >> ((~(((~(((l_3077.f3 * ((~((~(g_1106)))) + l_3077.f2)) & l_3109.f2))) || ((~((l_3109.f4 >> BHJHJg_310))) & (((~(g_310)) ^ (~(((~((BHJHJfl_3077_f0 || l_3077.f0))) % BHJHJeg_2_f4)))) || (~(g_2.f4))))))) >> (~((~(((BHJHJdg_2_f5 & BHJHJcl_3077_f3) & g_274.f2)))))))));
}
if((l_3077.f3 > BHJHJg_310)){

for (p_10 = 0; (p_10 <= 1); p_10 += 1)
                    {
                        g_130.f1 = (safe_lshift_func_uint16_t_u_s(((-1L) != (~(g_1056 ^ g_1135))), 4));
                    };


                    printf("g_2.f5=%llu\n", (unsigned long long)g_2.f5);
l_3077.f0 = (~(((((l_3109.f2 | (BHJHJcl_3077_f3 * g_310)) & (~((~((~(g_2.f4))))))) & ((((l_3077.f0 % (~(l_3109.f4))) || g_1106) * (BHJHJfl_3077_f0 * BHJHJdg_2_f5)) | l_3077.f2)) ^ ((~((~(((g_274.f2 % BHJHJg_310) % (~(g_2.f5))))))) | ((l_3077.f3 << BHJHJbg_274_f2) % (~(BHJHJeg_2_f4)))))));
BHJHJg_310 = (~(((~(((((~(g_2.f4)) & (~(((l_3077.f0 || (l_3077.f2 << BHJHJbg_274_f2)) * (((BHJHJcl_3077_f3 & l_3109.f2) + (~(l_3077.f3))) >> (~((BHJHJg_310 & g_1106)))))))) >> g_2.f5) * ((~((~(g_310)))) ^ (l_3109.f4 | ((~(g_274.f2)) || BHJHJfl_3077_f0)))))) % (~((BHJHJeg_2_f4 + BHJHJdg_2_f5))))));
g_310 = (~(((~((((BHJHJfl_3077_f0 & l_3077.f2) + (~((l_3077.f0 + BHJHJeg_2_f4)))) * ((~((~(((g_2.f4 || BHJHJbg_274_f2) | l_3109.f2))))) * (g_1106 | (~(l_3077.f3))))))) || (~(((~((~(((g_274.f2 << (BHJHJg_310 ^ (g_2.f5 * BHJHJcl_3077_f3))) >> (~(g_310))))))) ^ (~((BHJHJdg_2_f5 ^ l_3109.f4)))))))));
}
if((l_3109.f2<-10417)){
printf("g_2.f4=%llu\n", (unsigned long long)g_2.f4);
g_310 = (~(((~((((~(((~(l_3077.f2)) >> l_3109.f4))) >> (BHJHJdg_2_f5 ^ (~(g_2.f4)))) + ((~((~((~((~(l_3109.f2)))))))) >> (~(((~((g_274.f2 | BHJHJfl_3077_f0))) & ((g_310 | BHJHJcl_3077_f3) * (((~(g_2.f5)) | BHJHJeg_2_f4) * (((l_3077.f0 << BHJHJbg_274_f2) >> (~(g_1106))) * l_3077.f3)))))))))) >> (~((~((~(BHJHJg_310)))))))));
BHJHJdg_2_f5 = (~(((~(((~(BHJHJfl_3077_f0)) & (BHJHJg_310 % BHJHJcl_3077_f3)))) ^ ((g_274.f2 + ((~(BHJHJbg_274_f2)) >> (((~(g_2.f4)) || (BHJHJdg_2_f5 << (l_3077.f2 >> g_310))) << l_3109.f4))) ^ ((g_2.f5 & (~((~(g_1106))))) >> ((BHJHJeg_2_f4 || l_3077.f0) || ((~(l_3109.f2)) | l_3077.f3)))))));
BHJHJcl_3077_f3 = (~(((((~(((~(g_274.f2)) ^ (~(BHJHJcl_3077_f3))))) * (~(((l_3109.f4 ^ (g_2.f5 || l_3077.f0)) ^ g_2.f4)))) & (~((~(((g_310 % (((BHJHJeg_2_f4 >> g_1106) & (~((~(BHJHJg_310))))) + (~((((~(l_3077.f3)) % BHJHJbg_274_f2) + BHJHJfl_3077_f0))))) || (~(l_3077.f2)))))))) >> (~((BHJHJdg_2_f5 % (~(l_3109.f2))))))));
}
if((l_3077.f0>48383)){
printf("l_3077.f0=%llu\n", (unsigned long long)l_3077.f0);

for (g_2667 = 0; (g_2667 > 5); g_2667++)
                {
                    g_658 = (g_656 = g_656);
                };


                    l_3077.f3 = (~((((~((~(BHJHJg_310)))) + ((~((l_3077.f3 || l_3077.f2))) % ((BHJHJbg_274_f2 & BHJHJfl_3077_f0) % (~((g_2.f4 | (g_2.f5 & BHJHJeg_2_f4))))))) >> ((l_3077.f0 || l_3109.f4) & ((~(((~((~((~((l_3109.f2 >> (~(g_274.f2))))))))) || BHJHJcl_3077_f3))) & (g_1106 >> ((~(g_310)) || BHJHJdg_2_f5)))))));
g_274.f2 = (~((((~((~(BHJHJeg_2_f4)))) * (((~((~(g_310)))) | (g_2.f4 || ((~(BHJHJcl_3077_f3)) & l_3109.f2))) * (~(((~((BHJHJfl_3077_f0 * (~(((~(BHJHJg_310)) & (l_3077.f3 ^ l_3077.f2))))))) | ((~(g_274.f2)) % (BHJHJbg_274_f2 & g_1106))))))) | (~((l_3077.f0 << ((l_3109.f4 | g_2.f5) + (~(BHJHJdg_2_f5)))))))));
BHJHJdg_2_f5 = (~((((~((((((~(((~(g_1106)) || l_3109.f4))) & BHJHJfl_3077_f0) | (BHJHJcl_3077_f3 + BHJHJeg_2_f4)) >> ((~((~(g_274.f2)))) >> (g_2.f4 & l_3109.f2))) << (g_2.f5 << (~(l_3077.f2)))))) << (~((~((~(g_310))))))) || ((~((((~(l_3077.f0)) + (~((BHJHJg_310 ^ l_3077.f3)))) >> (~((~(BHJHJbg_274_f2))))))) * (~(BHJHJdg_2_f5))))));
}
}
g_310 = BHJHJg_310;
g_274.f2 = BHJHJbg_274_f2;
l_3077.f3 = BHJHJcl_3077_f3;
g_2.f5 = BHJHJdg_2_f5;
g_2.f4 = BHJHJeg_2_f4;
l_3077.f0 = BHJHJfl_3077_f0;

                    l_3109 = l_3077;
                                       if (!((g_69>0U)))
                    return g_264;
}







static uint8_t func_14(uint16_t p_15, int8_t p_16, uint8_t p_17, uint32_t p_18, uint32_t p_19)
{
    uint32_t l_2369 = 7UL;
    int32_t l_2370 = 0x7E58DDD0L;
    struct S0 l_2373 = {0xE06C78CEL,-371};
    int8_t l_2395 = (-2L);
    uint32_t l_2429[8];
    uint32_t l_2432[1];
    uint32_t l_2497[6];
    struct S1 l_2501 = {57,-8,-368,45,126,148};
    int32_t l_2566 = 0xC7039E54L;
    uint8_t l_2749 = 0x4BL;
    uint32_t l_2760 = 0xA126D742L;
    uint16_t l_2765 = 65535UL;
    uint32_t l_2793 = 0UL;
    int16_t l_2832 = (-2L);
    int16_t l_2946[4][8] = {{(-1L), 1L, 0x97B0L, (-8L), 0x97B0L, 1L, (-1L), 0L}, {(-1L), 1L, 0x97B0L, (-8L), 0x97B0L, 1L, (-1L), 0L}, {(-1L), 1L, 0x97B0L, (-8L), 0x97B0L, 1L, (-1L), 0L}, {(-1L), 1L, 0x97B0L, (-8L), 0x97B0L, 1L, (-1L), 0L}};
    uint32_t l_2958 = 0x2317CB77L;
    uint32_t l_2999[5][3][6] = {{{0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}, {0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}, {0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}}, {{0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}, {0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}, {0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}}, {{0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}, {0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}, {0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}}, {{0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}, {0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}, {0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}}, {{0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}, {0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}, {0x149B77D7L, 0xAFDF0422L, 0x42E75D6BL, 0xAF9D1F0EL, 18446744073709551615UL, 0xF3C17A56L}}};
    int i, j, k;
    for (i = 0; i < 8; i++)
        { while (((g_656.f1>14) || (!g_1895.f0)) )
{

{
        struct S0 l_2374 = {5L,1341};
        int32_t l_2443 = (-1L);
        l_2374 = g_1895;
        for (g_971 = 0; (g_971 == 32); ++g_971)
        {
            uint32_t l_2381 = 0x65E011A9L;
            int8_t l_2400 = (-5L);
            int32_t l_2401[3][1];
            int i, j;
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 1; j++)
                    l_2401[i][j] = 0x96776460L;
            }
            g_274.f3 = ((g_112 = (((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_u(((l_2374.f0 != ((l_2381 < (l_2749 = g_274.f5)) == (safe_lshift_func_int8_t_s_s((safe_lshift_func_int8_t_s_u((((g_112 & (safe_rshift_func_uint8_t_u_u((safe_unary_minus_func_int8_t_s((0x69796EA6L <= ((safe_mod_func_int32_t_s_s(((safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u((l_2374.f0 | g_971), 12)) ^ (0x40F3FEA6L | g_1184)), g_274.f0)) < 0x3BL), p_16)) >= 1L)))), 3))) && g_274.f3) != g_163), j)), 2)))) ^ 1UL), g_1177[1][2][0])), l_2381)) <= g_1895.f0) == (-1L))) | g_1895.f1);
            g_2569 = ((safe_add_func_int8_t_s_s((safe_add_func_uint8_t_u_u(l_2400, ((g_1039 < l_2374.f1) & (l_2401[0][0] = 1L)))), ((l_2374.f1 > (safe_sub_func_int16_t_s_s((safe_sub_func_int32_t_s_s((+(safe_rshift_func_uint16_t_u_u(0x1327L, (g_163 = g_112)))), (((((g_1135 < (g_959 = 0x46F0L)) != 65535UL) | g_274.f2) != 0xA1A1L) <= 4294967288UL))), 0x7D85L))) && g_274.f5))) == p_16);
            for (g_971 = (-23); (g_971 >= 60); ++g_971)
            {
                int16_t l_2428 = 0L;
                int32_t l_2448 = 0x88594FAAL;
                for (g_1184 = 0; (g_1184 > 5); g_1184++)
                {
                    g_274 = (g_274 = g_274);
                }
                for (g_1039 = 0; (g_1039 >= 15); ++g_1039)
                {
                    uint8_t l_2417[8][2];
                    int i, j;
                    for (i = 0; i < 8; i++)
                    {
                        for (j = 0; j < 2; j++)
                            l_2417[i][j] = 0UL;
                    }
                    l_2374.f1 = (safe_sub_func_int8_t_s_s(l_2417[5][1], ((safe_mod_func_int32_t_s_s((-1L), (safe_lshift_func_uint8_t_u_u(((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u(((l_2381 == 0x29L) && ((l_2566 = (safe_mod_func_int32_t_s_s(((l_2381 < ((g_2317 == ((((l_2749 < (3UL || (g_971 >= (-1L)))) <= l_2374.f1) || 1L) || l_2428)) == g_274.f1)) >= g_1039), p_16))) != g_40[1])), 3)), 3L)) < l_2429[5]), l_2374.f1)))) && g_1177[0][2][0])));
                }
                l_2448 = (safe_mod_func_uint16_t_u_u(l_2429[5], (((g_112 = ((l_2374.f0 && (((l_2432[0] | (safe_mod_func_uint32_t_u_u((((0x3F9B71A3L && (((((((((safe_add_func_int32_t_s_s((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(9L, 0)), 2)), (((l_2443 = (safe_rshift_func_uint16_t_u_u(0x40DFL, 7))) >= (((l_2374.f1 == l_2432[0]) <= (((((safe_mod_func_int8_t_s_s((g_1039 ^ 8L), l_2381)) != g_2317) ^ 0L) == g_274.f5) >= g_1039)) <= g_274.f4)) | 0xA6L))) == g_1895.f1) != l_2428) <= 4L) > 0xBDL) <= g_163) > 2L) & l_2374.f0) == g_971)) && l_2400) <= l_2374.f0), l_2428))) | 0x51EAL) <= g_274.f4)) < g_1177[2][3][1])) && l_2374.f0) | 0x09838561L)));
            }
        }
    }

}
                    if ((g_1568>153992158) )
{

{
                        g_658.f3 = (g_1568 = 8L);
                        g_658.f2 = g_1184;
                        g_1568 = 0x264ADA42L;
                        l_2501 = g_658;
                    }

}
                    l_2429[i] = 4294967295UL;}
    for (i = 0; i < 1; i++)
        l_2432[i] = 4294967287UL;
                                       if (l_2373.f1)
                    for (i = 0; i < 6; i++)
        { if (l_2501.f0)
                    l_2497[i] = 1UL;}
    l_2370 = (l_2369 = 0xE8A9B9C2L);
                                       if (((g_658.f0<251) || g_1895.f0))
                    for (g_310 = 25; (g_310 > (-26)); --g_310)
    {
        struct S0 l_2374 = {5L,1341};
        int32_t l_2443 = (-1L);
        l_2374 = l_2373;
        for (p_19 = 0; (p_19 == 32); ++p_19)
        {
            uint32_t l_2381 = 0x65E011A9L;
            int8_t l_2400 = (-5L);
            int32_t l_2401[3][1];
            int i, j;
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 1; j++)
                    l_2401[i][j] = 0x96776460L;
            }
            g_274.f3 = ((g_1056 = (((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_u(((l_2374.f0 != ((l_2381 < (g_1897 = g_656.f5)) == (safe_lshift_func_int8_t_s_s((safe_lshift_func_int8_t_s_u((((g_1106 & (safe_rshift_func_uint8_t_u_u((safe_unary_minus_func_int8_t_s((0x69796EA6L <= ((safe_mod_func_int32_t_s_s(((safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u((l_2374.f0 | p_19), 12)) ^ (0x40F3FEA6L | l_2395)), g_658.f0)) < 0x3BL), p_16)) >= 1L)))), 3))) && g_658.f3) != p_15), g_688)), 2)))) ^ 1UL), g_1177[1][2][0])), l_2381)) <= l_2373.f0) == (-1L))) | g_1895.f1);

{
                        struct S1 l_3596 = {21,1,11767,18,12,308};
                        l_2501 = g_658;
                        g_658 = (g_274 = (l_3596 = g_658));
                    }

                    l_2370 = ((safe_add_func_int8_t_s_s((safe_add_func_uint8_t_u_u(l_2400, ((p_18 < l_2374.f1) & (l_2401[0][0] = 1L)))), ((l_2374.f1 > (safe_sub_func_int16_t_s_s((safe_sub_func_int32_t_s_s((+(safe_rshift_func_uint16_t_u_u(0x1327L, (p_15 = g_1106)))), (((((p_17 < (g_1204 = 0x46F0L)) != 65535UL) | g_2.f2) != 0xA1A1L) <= 4294967288UL))), 0x7D85L))) && g_2.f5))) == p_16);
            for (g_971 = (-23); (g_971 >= 60); ++g_971)
            {
                int16_t l_2428 = 0L;
                int32_t l_2448 = 0x88594FAAL;
                for (g_1184 = 0; (g_1184 > 5); g_1184++)
                {
                    g_274 = (g_2 = g_2);
                }
                for (g_174 = 0; (g_174 >= 15); ++g_174)
                {
                    uint8_t l_2417[8][2];
                    int i, j;
                    for (i = 0; i < 8; i++)
                    {
                        for (j = 0; j < 2; j++)
                            l_2417[i][j] = 0UL;
                    }
                    l_2374.f1 = (safe_sub_func_int8_t_s_s(l_2417[5][1], ((safe_mod_func_int32_t_s_s((-1L), (safe_lshift_func_uint8_t_u_u(((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u(((l_2381 == 0x29L) && ((g_759 = (safe_mod_func_int32_t_s_s(((l_2381 < ((g_647 == ((((g_1135 < (3UL || (g_971 >= (-1L)))) <= l_2374.f1) || 1L) || l_2428)) == g_2.f1)) >= p_18), p_16))) != g_40[1])), 3)), 3L)) < l_2429[5]), l_2374.f1)))) && g_1177[0][2][0])));
                }
                l_2448 = (safe_mod_func_uint16_t_u_u(l_2429[5], (((g_112 = ((l_2374.f0 && (((l_2432[0] | (safe_mod_func_uint32_t_u_u((((0x3F9B71A3L && (((((((((safe_add_func_int32_t_s_s((safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(9L, 0)), 2)), (((l_2443 = (safe_rshift_func_uint16_t_u_u(0x40DFL, 7))) >= (((l_2374.f1 == l_2432[0]) <= (((((safe_mod_func_int8_t_s_s((p_18 ^ 8L), l_2381)) != g_75) ^ 0L) == g_274.f5) >= p_18)) <= g_658.f4)) | 0xA6L))) == g_1896.f1) != l_2428) <= 4L) > 0xBDL) <= p_15) > 2L) & l_2374.f0) == p_19)) && l_2400) <= l_2374.f0), l_2428))) | 0x51EAL) <= g_658.f4)) < g_1177[2][3][1])) && l_2374.f0) | 0x09838561L)));
            }
        }
    }
    for (g_900 = 0; (g_900 < 45); ++g_900)
    {
        int32_t l_2463 = 0x5133D18EL;
        struct S1 l_2476 = {214,10,10833,-7,32,40};
        uint32_t l_2494 = 4294967295UL;
        int8_t l_2498 = 0xCDL;
        uint16_t l_2499 = 65533UL;
        int8_t l_2568 = 1L;
        struct S0 l_2601 = {0xA95DA4A4L,-1799};
        struct S0 l_2620 = {-8L,666};
        uint32_t l_2794 = 0x9E89757CL;
        int32_t l_2795 = 0xFC78A87CL;
        int32_t l_2833 = 3L;
        struct S0 l_2834 = {-4L,420};
        int8_t l_2930 = (-3L);
        int32_t l_2931 = (-10L);
                                           if ((l_2794 > g_2098))
                    for (p_16 = 0; (p_16 >= 0); p_16 -= 1)
        {
            int8_t l_2474 = 0x67L;
            int32_t l_2475 = 0x81E3C5D9L;
            struct S1 l_2570 = {6,8,3950,-70,80,219};
            uint8_t l_2595 = 0x51L;
            struct S0 l_2618 = {0x368FB9A0L,1042};
            uint8_t l_2664 = 0x30L;
            g_1896.f1 = (safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((l_2475 = ((g_1896.f1 | (((((safe_mod_func_int32_t_s_s(((0xA021C9D2L > (((safe_rshift_func_int16_t_s_s((l_2463 >= ((!l_2463) >= (((safe_mod_func_int32_t_s_s(((((+((safe_mod_func_int32_t_s_s(0x2F888F84L, (safe_sub_func_int32_t_s_s(g_1895.f0, g_656.f1)))) && ((safe_add_func_int8_t_s_s(l_2463, p_17)) && (-1L)))) && g_1204) || g_2.f0) ^ p_19), l_2474)) && g_40[0]) < p_15))), g_658.f2)) & l_2463) <= l_2474)) ^ l_2369), g_310)) == g_274.f4) != 0x599E7536L) > g_656.f1) >= g_658.f3)) < l_2474)), 4)), g_264));
            g_2 = l_2476;
                                                if ((g_2.f5>40) )
{

g_740 += 1;


}
                    if ((((l_2474 != (p_15 <= ((g_1135 <= ((p_17 <= g_163) & ((g_1039 & ((5UL | (-1L)) >= 0L)) && p_15))) | p_15))) <= 0xC1L) >= p_16))
            {
                int32_t l_2478[5][4] = {{0L, 0xF0FEAB4AL, 0xB7E3E6CCL, 0xF0FEAB4AL}, {0L, 0xF0FEAB4AL, 0xB7E3E6CCL, 0xF0FEAB4AL}, {0L, 0xF0FEAB4AL, 0xB7E3E6CCL, 0xF0FEAB4AL}, {0L, 0xF0FEAB4AL, 0xB7E3E6CCL, 0xF0FEAB4AL}, {0L, 0xF0FEAB4AL, 0xB7E3E6CCL, 0xF0FEAB4AL}};
                int32_t l_2527 = 8L;
                int16_t l_2567 = 0L;
                int i, j;
                for (g_688 = 0; (g_688 >= 0); g_688 -= 1)
                {
                    uint8_t l_2481 = 255UL;
                    l_2478[2][3] = (safe_unary_minus_func_uint16_t_u(l_2370));
                    g_274.f1 = (safe_lshift_func_uint16_t_u_s(((-8L) <= (0x0C44L > l_2481)), (safe_mod_func_uint16_t_u_u((0x2CBEL <= ((p_15 = 0x1294L) ^ (safe_sub_func_int16_t_s_s(0xEFF0L, 0xB819L)))), (p_19 || (safe_rshift_func_uint16_t_u_s((p_16 >= 1L), l_2481)))))));
                }
                if ((safe_add_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s((0UL < l_2478[2][3]), (0x01AEC1B2L <= (-3L)))) < (l_2476.f0 | (((safe_mod_func_uint8_t_u_u((p_19 <= l_2494), ((5L >= (p_15 = (((safe_rshift_func_uint16_t_u_u(l_2497[1], 1)) | 0xEA06L) || l_2498))) || p_19))) == g_174) || l_2369))) <= g_130.f0), p_17)))
                {
                    struct S1 l_2500 = {173,2,15151,-16,8,18};
                    if (l_2499)
                    {
                        struct S1 l_2502 = {37,-16,-5418,53,71,209};
                        l_2502 = (l_2501 = (l_2500 = g_656));
                        g_274.f3 = (safe_add_func_uint32_t_u_u((safe_unary_minus_func_uint8_t_u(((l_2500.f1 = ((g_2317 = ((g_1897 = (safe_mod_func_int16_t_s_s((l_2501.f1 = (l_2500.f2 = (safe_add_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s(l_2501.f4, (safe_mod_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u(((safe_mod_func_uint32_t_u_u((p_18 = (((p_16 >= ((g_2.f1 = (safe_lshift_func_int8_t_s_s((-2L), 4))) > (l_2527 = (safe_rshift_func_int8_t_s_s((1L ^ (safe_rshift_func_int8_t_s_s((!0xE379L), 5))), l_2475))))) == (safe_sub_func_uint16_t_u_u((((((((safe_add_func_uint16_t_u_u(l_2395, 0L)) ^ (g_415 = 0x9D79L)) | p_17) < l_2369) && g_647) & 0x48L) ^ p_16), l_2478[4][3]))) ^ l_2476.f1)), l_2474)) | g_740), 0x07L)), l_2500.f4)))), 6L)) & g_40[1]), 0xB6L)))), g_163))) & g_274.f1)) & p_16)) ^ l_2474))), 4294967295UL));
                    }
                    else
                    {
                        l_2566 = (g_656.f3 || (safe_lshift_func_uint8_t_u_s((((((((safe_add_func_int32_t_s_s((safe_sub_func_int32_t_s_s(((safe_rshift_func_uint16_t_u_s(((safe_add_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_s((safe_add_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((0xF8L >= (((l_2476.f2 = ((((((g_274.f5 = (((safe_rshift_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_s((((((safe_add_func_int16_t_s_s((1L && p_16), 0x8A54L)) ^ (g_656.f1 = (((((((l_2567 = ((safe_add_func_int8_t_s_s((g_613 & ((safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(0xD4D7L, 13)), 5)) < 8L)), (safe_mod_func_uint16_t_u_u(((g_2098 = (safe_lshift_func_int16_t_s_s(l_2566, 6))) <= 65533UL), l_2432[0])))) < l_2474)) >= p_18) < 8UL) && g_2.f5) != g_1896.f1) >= l_2476.f3) < 1UL))) & p_18) && p_16) & l_2568), 3)), l_2395)) & g_415), 5)) || (-5L)) && l_2370)) <= p_19) && p_16) < l_2474) | 1UL) <= l_2501.f2)) == p_15) >= p_17)), l_2478[3][1])), 1UL)), 1)) < (-1L)), l_2527)) >= p_19), 15)) & p_16), (-1L))), g_217[0].f1)) >= p_17) || g_2569) == p_18) >= (-6L)) & p_18) > 6L), 5)));
                    }
                    for (g_613 = 0; (g_613 <= 0); g_613 += 1)
                    {
                        g_2 = l_2570;
                    }
                }
                else
                {
                    return g_688;
                }
            }
            else
            {
                int32_t l_2596 = (-8L);
                struct S0 l_2602 = {-7L,-646};
                uint8_t l_2607 = 0xC3L;
                for (g_688 = 0; (g_688 >= 0); g_688 -= 1)
                {
                    int8_t l_2597 = 0x67L;
                    int32_t l_2598[7] = {0x82654177L, 0L, 0x82654177L, 0L, 0x82654177L, 0L, 0x82654177L};
                    int32_t l_2609 = 2L;
                    struct S1 l_2610 = {55,-18,-13671,12,179,347};
                    int i;
                    l_2598[5] = (safe_mod_func_uint8_t_u_u((((safe_add_func_uint16_t_u_u((safe_rshift_func_int8_t_s_u(p_17, ((g_658.f2 == ((((65535UL > (p_16 | 255UL)) && (g_1897 != ((safe_sub_func_uint32_t_u_u((safe_add_func_uint16_t_u_u((safe_add_func_uint8_t_u_u((l_2476.f1 = (g_264 = ((safe_rshift_func_int16_t_s_u((g_1039 && g_112), 3)) < (l_2597 = ((((safe_add_func_uint32_t_u_u((((safe_mod_func_uint16_t_u_u((((safe_rshift_func_uint8_t_u_s((safe_add_func_uint8_t_u_u((safe_add_func_int8_t_s_s(0x26L, g_1177[0][4][1])), l_2568)), l_2595)) | p_18) ^ p_16), l_2596)) || g_1568) || g_1135), g_217[0].f1)) && g_1177[0][2][1]) > g_875) != 0x0AL))))), g_658.f4)), 0x99A6L)), l_2395)) > l_2476.f3))) && l_2501.f4) >= (-1L))) > 8UL))), g_2.f5)) & 0x5B430BB3L) != 0L), p_16));
                    if ((l_2597 || (safe_rshift_func_uint8_t_u_u(p_17, (l_2373.f0 >= p_18)))))
                    {
                        int i;
                        g_217[g_688] = g_217[0];

l_2930 += 1;


                    l_2602 = (l_2601 = (g_217[g_688] = g_130));
                    }
                    else
                    {
                        int8_t l_2608[6][9] = {{0x15L, 0xCBL, 9L, 0xBFL, 9L, 0xCBL, 0x15L, (-1L), 0xFCL}, {0x15L, 0xCBL, 9L, 0xBFL, 9L, 0xCBL, 0x15L, (-1L), 0xFCL}, {0x15L, 0xCBL, 9L, 0xBFL, 9L, 0xCBL, 0x15L, (-1L), 0xFCL}, {0x15L, 0xCBL, 9L, 0xBFL, 9L, 0xCBL, 0x15L, (-1L), 0xFCL}, {0x15L, 0xCBL, 9L, 0xBFL, 9L, 0xCBL, 0x15L, (-1L), 0xFCL}, {0x15L, 0xCBL, 9L, 0xBFL, 9L, 0xCBL, 0x15L, (-1L), 0xFCL}};
                        int i, j;
                        if (p_17)
                            break;

for (l_2793 = 0; (l_2793 <= 1); l_2793 += 1)
                {
                    int i;
                    g_217[0] = g_217[g_1106];
                };


                    l_2609 = ((safe_rshift_func_uint16_t_u_u((((p_18 == (l_2598[2] = (l_2598[5] >= (p_17 & ((l_2476.f5 && p_16) > ((l_2607 != (0x0D3FB68CL < (((p_18 <= 0x64L) ^ 4294967287UL) > p_16))) && p_17)))))) <= p_17) != p_15), l_2501.f5)) & l_2608[2][7]);
                        l_2610 = g_656;
                    }
                    g_875 = p_17;
                    for (l_2602.f0 = 5; (l_2602.f0 >= 0); l_2602.f0 -= 1)
                    {
                        return p_17;
                    }
                }
            }
            for (g_174 = 0; (g_174 <= 1); g_174 += 1)
            {
                int i;
                                               uint32_t BqJqJl_2501_f5 = (-((((~((g_2.f2 & l_2370))) ^ ((g_658.f0 | l_2595) | (~(((~((~(l_2501.f0)))) && (-(l_2501.f5))))))) ^ (~(((-(g_714)) && (~((l_2476.f4 && (g_740 | g_1568))))))))));
uint8_t BqJqJbg_714 = (~(((~((~((((g_714 & l_2595) && l_2476.f4) ^ (l_2501.f0 & ((g_740 && l_2501.f5) | g_1568))))))) && (-((((g_2.f2 && g_658.f0) && (-((~(BqJqJl_2501_f5))))) | l_2370))))));
uint16_t BqJqJcg_658_f0 = (~(((~((-((((((BqJqJbg_714 & g_740) ^ (-(g_1568))) | (l_2501.f5 | (g_2.f2 ^ BqJqJl_2501_f5))) && (~(g_714))) ^ (l_2476.f4 ^ (l_2501.f0 & (-(((-(l_2370)) && g_658.f0)))))))))) & (-(l_2595)))));
uint8_t BqJqJdl_2595 = (~(((((((~(l_2476.f4)) && l_2501.f0) ^ (~(l_2595))) && ((g_714 & BqJqJcg_658_f0) ^ (~((~(BqJqJbg_714)))))) && (~(l_2370))) ^ (~(((~(((((~(g_2.f2)) & (g_740 | BqJqJl_2501_f5)) | g_1568) && (~((-(l_2501.f5))))))) & (~(g_658.f0))))))));
int32_t BqJqJeg_1568 = (~(((-(((-(l_2595)) && (~(((~(l_2501.f0)) | (BqJqJbg_714 & (~((-(BqJqJdl_2595))))))))))) && (((~((BqJqJl_2501_f5 ^ (l_2501.f5 & g_2.f2)))) & l_2370) ^ (((g_740 && l_2476.f4) ^ (~((BqJqJcg_658_f0 ^ (~(g_714)))))) && (g_658.f0 ^ g_1568))))));
int32_t BqJqJfl_2370 = (~((((g_658.f0 & ((~((-(BqJqJl_2501_f5)))) | g_1568)) >> ((g_2.f2 | (l_2501.f5 & BqJqJbg_714)) & (~(((~(l_2476.f4)) | (-(l_2595))))))) & ((~((((-(BqJqJeg_1568)) ^ ((~(l_2370)) & (l_2501.f0 ^ (-(g_740))))) ^ (g_714 | BqJqJcg_658_f0)))) & (~(BqJqJdl_2595))))));
if((BqJqJdl_2595<=5)){
BqJqJl_2501_f5 = l_2501.f5;
BqJqJbg_714 = g_714;
BqJqJcg_658_f0 = g_658.f0;
LABEL_qJqJg: BqJqJdl_2595 = l_2595;
BqJqJeg_1568 = g_1568;
BqJqJfl_2370 = l_2370;
l_2501.f5 = (~(((((~((-((~((BqJqJfl_2370 ^ (-(g_740))))))))) | BqJqJdl_2595) >> ((((-((~((BqJqJeg_1568 && BqJqJcg_658_f0))))) ^ l_2595) && g_714) | (((l_2501.f5 & g_658.f0) & (~(l_2370))) >> (BqJqJl_2501_f5 && g_2.f2)))) ^ (~((~((~(((~((l_2476.f4 | l_2501.f0))) & (~((BqJqJbg_714 | g_1568)))))))))))));
g_714 = (~(((~((-((((~((~(g_714)))) & ((BqJqJbg_714 ^ BqJqJeg_1568) ^ (~((g_658.f0 ^ (BqJqJfl_2370 ^ BqJqJcg_658_f0)))))) && (~((-(((~((-((~(((~(l_2501.f5)) ^ BqJqJl_2501_f5))))))) ^ (~((-(l_2370)))))))))))))) | (~((((~((-(l_2595)))) ^ (~(BqJqJdl_2595))) && ((~((l_2476.f4 | (-(g_740))))) | ((g_1568 ^ g_2.f2) & (~(l_2501.f0))))))))));
g_658.f0 = (~(((-(((~((~(g_2.f2)))) & (l_2370 ^ (l_2501.f5 & (g_658.f0 && (~(BqJqJdl_2595)))))))) & ((((~(BqJqJbg_714)) | g_740) | ((g_1568 >> (g_714 & BqJqJcg_658_f0)) | ((l_2476.f4 | BqJqJl_2501_f5) | ((~(l_2595)) ^ (~(l_2501.f0)))))) ^ (~((-((BqJqJfl_2370 ^ (~((~((~((-(BqJqJeg_1568)))))))))))))))));
l_2595 = (-(((((~((l_2501.f0 && l_2595))) & g_2.f2) ^ (-((BqJqJeg_1568 & (~(BqJqJcg_658_f0)))))) ^ ((((~(BqJqJdl_2595)) | (-((g_740 && (l_2370 && (g_1568 ^ (l_2501.f5 ^ (~(BqJqJfl_2370))))))))) & ((~((BqJqJl_2501_f5 | g_658.f0))) & (-((-(BqJqJbg_714)))))) | (~((-((-((g_714 ^ l_2476.f4)))))))))));
g_1568 = (~((((-(((g_658.f0 >> (g_2.f2 && (-(l_2501.f5)))) | (BqJqJcg_658_f0 | BqJqJfl_2370)))) & BqJqJdl_2595) << (((-((~(((~((BqJqJbg_714 >> BqJqJl_2501_f5))) | (-(l_2370))))))) & (l_2501.f0 && (~((l_2595 ^ BqJqJeg_1568))))) && (~((((l_2476.f4 | g_1568) | (~(g_740))) && (~(g_714)))))))));
l_2370 = (-(((g_740 & (((~(((~(g_714)) & l_2595))) ^ (l_2501.f0 ^ (-((BqJqJdl_2595 && g_1568))))) && (g_2.f2 & ((~(BqJqJcg_658_f0)) | (l_2370 & l_2501.f5))))) ^ (~((-((-((((-((~((BqJqJbg_714 & BqJqJl_2501_f5))))) | ((-((~(l_2476.f4)))) && (g_658.f0 | BqJqJfl_2370))) && BqJqJeg_1568))))))))));
if((BqJqJcg_658_f0 < l_2501.f0)){
printf("l_2501.f5=%llu\n", (unsigned long long)l_2501.f5);
BqJqJl_2501_f5 = (~((((-((~(l_2370)))) >> (~(g_1568))) && ((~((-(BqJqJcg_658_f0)))) & (((BqJqJbg_714 ^ g_714) && (~(((~(g_740)) >> ((l_2595 && (l_2501.f0 >> BqJqJl_2501_f5)) << g_658.f0))))) >> ((-(l_2501.f5)) << (BqJqJdl_2595 << ((BqJqJeg_1568 && l_2476.f4) & ((~(g_2.f2)) << BqJqJfl_2370)))))))));
l_2595 = (~(((((~(g_740)) & l_2595) >> (~(((-(((~((-((~(l_2476.f4)))))) << (-(BqJqJbg_714))))) ^ (~(((l_2501.f5 | (((~(g_2.f2)) | (g_714 >> g_658.f0)) && ((BqJqJcg_658_f0 << ((~((~(BqJqJl_2501_f5)))) ^ BqJqJfl_2370)) && g_1568))) && (l_2501.f0 | (~((l_2370 << BqJqJdl_2595))))))))))) ^ (-(BqJqJeg_1568)))));
goto LABEL_qJqJg;
}
if(((g_714>=0) && (l_2370<2))){
printf("g_714=%llu\n", (unsigned long long)g_714);
g_658.f0 = (~(((-((~((~(((~(l_2476.f4)) | (((-(((BqJqJl_2501_f5 | BqJqJdl_2595) && l_2370))) << (-(((~(g_658.f0)) | (l_2595 | (BqJqJcg_658_f0 & (~(g_2.f2)))))))) << (BqJqJbg_714 >> l_2501.f0))))))))) | ((~((g_714 << (l_2501.f5 ^ g_740)))) & ((BqJqJfl_2370 | (~((~(g_1568))))) >> BqJqJeg_1568)))));
continue;
}
if((l_2370>2)){
printf("g_658.f0=%llu\n", (unsigned long long)g_658.f0);
l_2370 = (~(((~((~(((g_1568 << g_658.f0) << (g_714 | l_2595)))))) >> (((BqJqJdl_2595 & g_2.f2) | ((l_2501.f5 ^ g_740) & BqJqJl_2501_f5)) >> (BqJqJfl_2370 | (((~((-(l_2476.f4)))) && l_2370) & ((BqJqJbg_714 >> BqJqJcg_658_f0) & (-((l_2501.f0 | (~(BqJqJeg_1568))))))))))));
continue;
}
if(((l_2501.f5 < BqJqJdl_2595) || (!l_2476.f4))){
printf("l_2595=%llu\n", (unsigned long long)l_2595);
break;
}
if((g_2.f2 < BqJqJfl_2370)){
printf("g_1568=%lld\n", (long long)g_1568);
BqJqJfl_2370 = (~((((~((-((~(l_2476.f4)))))) & (-((~((g_740 << (-((g_714 && (~((~(BqJqJbg_714))))))))))))) >> (((((BqJqJcg_658_f0 ^ g_1568) >> (~(l_2595))) | l_2501.f0) ^ ((l_2501.f5 && BqJqJl_2501_f5) ^ (~(((BqJqJfl_2370 | (g_2.f2 << l_2370)) & ((~(g_658.f0)) << BqJqJeg_1568)))))) << BqJqJdl_2595))));
BqJqJbg_714 = (~(((((~(((g_658.f0 << g_1568) ^ g_740))) && (BqJqJdl_2595 ^ BqJqJcg_658_f0)) | ((g_2.f2 << l_2370) >> (~(((~(l_2501.f5)) << ((~(BqJqJl_2501_f5)) && (l_2476.f4 | g_714))))))) << ((l_2595 ^ BqJqJbg_714) << (((~((-(l_2501.f0)))) >> (-(BqJqJeg_1568))) ^ BqJqJfl_2370)))));
g_658.f0 = (~(((((-((((~((BqJqJdl_2595 >> (BqJqJl_2501_f5 >> l_2501.f5)))) & BqJqJeg_1568) ^ g_2.f2))) << ((BqJqJcg_658_f0 | (l_2595 & BqJqJbg_714)) ^ (~(((l_2476.f4 && BqJqJfl_2370) << (~(g_740))))))) && (g_658.f0 >> (~(l_2501.f0)))) << (-(((-(g_1568)) | (l_2370 | g_714)))))));
}
if(((g_2.f2>3950) || (l_2501.f5 < g_714))){
printf("l_2370=%lld\n", (long long)l_2370);
l_2595 = (-((((~(((BqJqJbg_714 << g_714) && (-(l_2370))))) & (~(((((((~((~(l_2501.f5)))) && ((l_2501.f0 << BqJqJeg_1568) << (-(l_2476.f4)))) >> l_2595) << (~((-((BqJqJfl_2370 << g_2.f2)))))) && g_740) & (((~(g_658.f0)) & BqJqJcg_658_f0) | BqJqJdl_2595))))) & (~((-((BqJqJl_2501_f5 >> g_1568))))))));
continue;
}
}
l_2501.f5 = BqJqJl_2501_f5;
g_714 = BqJqJbg_714;
g_658.f0 = BqJqJcg_658_f0;
l_2595 = BqJqJdl_2595;
g_1568 = BqJqJeg_1568;
l_2370 = BqJqJfl_2370;

                    g_2317 = ((safe_add_func_uint8_t_u_u(((l_2501.f3 = (safe_mod_func_uint8_t_u_u(((!g_40[g_174]) ^ 0x7CL), l_2497[(g_174 + 2)]))) < l_2497[(g_174 + 4)]), (1UL < (+p_16)))) || (l_2370 > (+4294967289UL)));
                for (p_17 = 0; (p_17 <= 5); p_17 += 1)
                {
                    int32_t l_2642 = 0xAC553B10L;
                    struct S0 l_2643 = {0xC5B0517CL,25};
                    for (g_1204 = 0; (g_1204 <= 0); g_1204 += 1)
                    {
                        struct S0 l_2619 = {1L,826};
                        int i;
                        l_2620 = (l_2619 = (l_2618 = (g_217[p_16] = g_1896)));
                        l_2570 = l_2476;
                    }
                    for (l_2499 = 0; (l_2499 <= 1); l_2499 += 1)
                    {
                        int32_t l_2627 = 0xA02FAE0FL;
                        int i;
                        g_40[g_174] = ((safe_add_func_int8_t_s_s((safe_sub_func_int16_t_s_s(((l_2475 = (((safe_lshift_func_int16_t_s_u(((l_2627 = l_2432[p_16]) > (safe_rshift_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((((((0x52L || 0xC5L) <= (safe_lshift_func_uint16_t_u_u((((l_2497[(l_2499 + 2)] >= (g_1184 = 0x58L)) || ((safe_mod_func_int8_t_s_s((l_2432[p_16] && ((((((p_17 | (l_2570.f1 = ((safe_mod_func_uint32_t_u_u((safe_add_func_uint32_t_u_u(((g_714 = (l_2370 = (safe_lshift_func_int8_t_s_u((l_2618.f1 == 0x95E8L), 7)))) | p_19), g_40[g_174])), 0x5655E761L)) >= 0x26L))) || g_658.f0) > l_2642) | 0UL) && g_415) >= l_2432[p_16])), 0xB3L)) && l_2463)) < 0L), p_19))) != g_2.f2) && p_18) >= (-7L)), p_15)), l_2476.f2))), 1)) & p_16) && l_2620.f1)) ^ 0UL), g_1177[2][3][1])), 0xB1L)) || 0x33D5B1B9L);
                        if (g_40[2])
                            continue;
                        g_217[p_16] = l_2643;
                        return p_18;
                    }
                    for (g_112 = 0; (g_112 <= 0); g_112 += 1)
                    {
                        int32_t l_2644 = 2L;
                        int32_t l_2656 = 0xA6B659ACL;
                        int i, j, k;
                        g_40[g_174] = ((((((l_2644 = l_2432[p_16]) >= g_40[(g_174 + 1)]) == (g_1896.f1 = (-8L))) >= (g_647 = (+((safe_rshift_func_uint16_t_u_s((safe_add_func_int16_t_s_s((0L | ((g_1177[(g_112 + 3)][(g_112 + 2)][g_112] >= l_2497[(g_174 + 4)]) == g_40[g_174])), (g_969 = (safe_add_func_int8_t_s_s(((((safe_lshift_func_int8_t_s_u(((l_2656 = (p_18 = (((safe_add_func_uint8_t_u_u(p_16, (p_16 > l_2476.f5))) & 4294967294UL) <= 0xC6L))) & p_17), 0)) || 65535UL) < p_16) | 0x28D3L), 255UL))))), 0)) >= p_15)))) == p_17) ^ 3UL);
                        l_2643 = (g_217[p_16] = l_2620);
                        if (g_274.f5)
                            continue;
                    }
                }
                if ((((safe_add_func_int32_t_s_s(((g_130.f1 ^ ((safe_add_func_uint32_t_u_u((((g_112 = (safe_lshift_func_uint16_t_u_u(8UL, ((!p_18) || (l_2664 = (g_969 = g_1177[1][2][0])))))) && (g_40[0] != (safe_add_func_uint16_t_u_u((((g_656.f1 = (l_2570.f1 = ((g_2667 = g_1135) | (((g_274.f2 >= (safe_mod_func_uint16_t_u_u(g_1896.f0, 65535UL))) && 1UL) || 0x975446F8L)))) & g_658.f2) > g_112), p_19)))) < l_2497[3]), p_17)) && 0L)) != 9UL), 0x56F4143EL)) != p_16) >= l_2618.f1))
                {
                    uint16_t l_2688[4][4] = {{4UL, 0x29E5L, 0x9A8EL, 0x9A8EL}, {4UL, 0x29E5L, 0x9A8EL, 0x9A8EL}, {4UL, 0x29E5L, 0x9A8EL, 0x9A8EL}, {4UL, 0x29E5L, 0x9A8EL, 0x9A8EL}};
                    int i, j;
                                                        while ((g_415 && (g_2569>1)) )
{

for (g_3324 = 0; g_3324 < 2; g_3324++)
            {
                transparent_crc(g_1177[l_2833][g_647][g_3324], "g_1177[l_2833][g_647][g_3324]", g_211);
                if (g_211) printf("index = [%d][%d][%d]\n", l_2833, g_647, g_3324);

            };


}
                    l_2570.f2 = (safe_add_func_int8_t_s_s(((p_15 = g_1039) > (((safe_add_func_int8_t_s_s(4L, (safe_add_func_int32_t_s_s(0x64601414L, ((safe_add_func_int32_t_s_s((((l_2476.f2 = (safe_unary_minus_func_uint8_t_u(255UL))) || (safe_sub_func_int8_t_s_s(((l_2570.f1 == (((safe_unary_minus_func_int32_t_s(0xA23FA5C3L)) == (p_19 >= l_2432[0])) == (l_2476.f2 = ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_u((g_264 = g_415), p_18)) | p_18), 0xE9FCL)) < g_2.f2)))) && g_2317), 0x9EL))) != l_2595), p_19)) >= l_2620.f1))))) & 0xFADCEDE5L) != 4294967295UL)), 0x70L));
                    l_2688[2][0] = g_112;
                }
                else
                {
                    return g_656.f3;
                }
            }
            for (p_17 = 0; (p_17 <= 1); p_17 += 1)
            {
                int32_t l_2691 = (-1L);
                for (g_1895.f0 = 0; (g_1895.f0 >= 0); g_1895.f0 -= 1)
                {
                    int32_t l_2689 = 0xC6940A15L;
                    struct S1 l_2690 = {139,4,-11389,19,59,277};
                    int i;
                    l_2501.f1 = (l_2432[g_1895.f0] <= (l_2689 = l_2432[g_1895.f0]));
                    l_2501 = l_2690;
                    return l_2691;
                }
            }
        }

g_1058 += 1;



for (l_2794 = 0; (l_2794 <= 1); l_2794 += 1)
                    {
                        g_130.f1 = (safe_lshift_func_uint16_t_u_s(((-1L) != (~(g_112 ^ p_17))), 4));
                    };


                    for (l_2566 = (-6); (l_2566 == (-25)); l_2566 = safe_sub_func_int32_t_s_s(l_2566, 2))
        {
            int16_t l_2712 = 0L;
            int32_t l_2713 = (-1L);
            int32_t l_2725[4][5][6] = {{{0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}}, {{0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}}, {{0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}}, {{0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}, {0x3FDF7F3CL, 0x351869DAL, 0L, 0x8DE4153AL, 0x3FDF7F3CL, (-6L)}}};
            int i, j, k;
            for (g_959 = 0; (g_959 == (-22)); g_959 = safe_sub_func_int8_t_s_s(g_959, 7))
            {
                int32_t l_2705 = 0xF53AEC0FL;
                int16_t l_2724 = 0xDD23L;
                struct S0 l_2761 = {0x0C5196BBL,-1949};

for (g_1895.f0 = 5; (g_1895.f0 > 20); g_1895.f0++)
                    {
                        uint8_t l_1925 = 0x3EL;
                        l_2476.f2 = (0UL && ((((l_2794 >= (g_274.f2 = (k & (safe_mod_func_int32_t_s_s((g_759 = 0x050CE2D4L), (safe_add_func_int16_t_s_s((((safe_lshift_func_uint16_t_u_s(((g_112 = ((safe_lshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u((g_69 ^ 0xFFL), (l_2476.f1 = (safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(k, (g_647 = 1L))) == (g_2.f2 = (safe_rshift_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(l_2370, l_1925)), l_2793)))) <= (-3L)), l_2476.f3))))), 6)), l_2476.f0)), 0)) == 0xCC4DL)) & g_274.f2), 11)) >= l_2749) <= (-1L)), 0x90D6L))))))) < g_740) || p_17) ^ 0x23L));
                        g_217[0] = (l_2834 = l_2373);
                        l_2476 = l_2501;
                        if (k)
                            break;
                    };


                    g_875 = (+(((((safe_sub_func_int16_t_s_s((((safe_add_func_int16_t_s_s((l_2713 = (safe_mod_func_int16_t_s_s(((safe_add_func_uint8_t_u_u((((l_2705 <= (safe_rshift_func_int16_t_s_u(l_2601.f0, ((safe_lshift_func_uint8_t_u_u(p_15, g_658.f0)) > (p_16 | g_1177[2][3][1]))))) >= (safe_add_func_int32_t_s_s(l_2712, l_2705))) == 0xC5L), g_658.f4)) | p_19), l_2712))), p_17)) || 0x9447L) != 0UL), p_15)) < 1L) | 0UL) | l_2601.f1) <= l_2705));

{
                    int32_t l_2157 = 6L;
                    struct S0 l_2166 = {0x1EE1138AL,-1097};
                    g_656.f3 = ((0x95FDL || l_2712) <= (((((((((g_969 = l_2157) >= ((((g_75 = ((g_2.f2 = g_1058) <= (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_s((l_2749 >= (safe_add_func_int16_t_s_s(l_2713, (0xA0L < (safe_add_func_uint16_t_u_u(((g_1058 | 0xA63F201AL) ^ 0xCFF3DD30L), l_2157)))))), g_714)) == l_2761.f0), l_2705)))) | 65535UL) & l_2157) | l_2705)) < g_1135) >= p_17) > g_714) > (-1L)) < l_2705) == l_2476.f3) > 1L));
                    l_2834 = (l_2601 = l_2166);
                }

                    l_2725[3][0][5] = (l_2713 = (safe_mod_func_uint8_t_u_u((safe_add_func_uint32_t_u_u((safe_mod_func_int8_t_s_s(p_19, (((0x2050L && 65532UL) != ((((l_2705 ^ (g_163 = (safe_rshift_func_int8_t_s_s(l_2476.f0, ((safe_add_func_uint16_t_u_u(0x33F5L, l_2705)) >= l_2601.f0))))) <= (l_2601.f1 || g_1204)) ^ p_18) || p_19)) | l_2724))), l_2373.f1)), 255UL)));
                for (l_2724 = 12; (l_2724 <= (-9)); l_2724 = safe_sub_func_uint32_t_u_u(l_2724, 4))
                {
                    int32_t l_2734 = 0x59501DC8L;
                    if ((safe_lshift_func_int16_t_s_s((((((safe_lshift_func_uint8_t_u_u(((p_16 != (((safe_sub_func_uint8_t_u_u(g_714, 0x5AL)) < l_2734) >= (safe_rshift_func_uint16_t_u_u(0xF189L, (((safe_rshift_func_int8_t_s_u((safe_add_func_int32_t_s_s(((safe_rshift_func_uint8_t_u_u((p_19 > (l_2724 >= ((((l_2494 > ((g_1184 = l_2734) > g_130.f1)) == 0x04FFL) > g_1178) >= l_2734))), 3)) > 5L), 0xEF9375E6L)), g_1896.f1)) & p_17) | g_656.f2))))) <= p_19), 2)) != p_18) < g_274.f2) & p_17) != 0xB1C6L), 12)))
                    {
                        int32_t l_2754 = (-6L);
                        l_2734 = (safe_sub_func_uint16_t_u_u((l_2501.f2 = (l_2601.f1 = ((safe_add_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_u((g_1106 = l_2749), 0)) >= ((safe_add_func_int32_t_s_s((safe_sub_func_uint32_t_u_u((p_18 = ((0x06L != (l_2754 >= ((((g_1184 < l_2501.f1) && (safe_sub_func_uint8_t_u_u(((g_274.f2 = g_658.f2) && (((g_264 = ((g_1204 = (safe_rshift_func_uint16_t_u_s(((safe_unary_minus_func_int16_t_s((g_274.f2 || p_19))) != l_2476.f1), 0))) || g_217[0].f0)) < 7L) < g_656.f4)), l_2760))) != 0L) < 0xD63662ABL))) || 0xA836L)), g_658.f0)), (-1L))) >= p_17)), g_130.f1)) >= l_2725[0][0][2]))), 0L));
                    }
                    else
                    {
                        l_2761 = g_1895;
                    }
                }
            }
            for (l_2395 = 5; (l_2395 >= 1); l_2395 -= 1)
            {
                struct S0 l_2764 = {0x7CACC2F3L,-350};
                int i;
                l_2725[3][0][5] = (safe_lshift_func_int16_t_s_s(l_2497[l_2395], 12));

for (l_2395 = 27; (l_2395 > (-25)); l_2395--)
                    {
                        uint32_t l_665 = 0xE8B9A2A8L;
                        int32_t l_668[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_668[i] = 0x75128752L;
                        l_2833 = (g_224 = l_665);
                        l_2476.f1 = (l_668[1] = (g_658.f1 = l_665));
                        l_2463 = g_971;
                        g_211 = l_2395;
                    };


                    l_2764 = (l_2373 = l_2620);
                g_40[1] = l_2765;
                l_2713 = g_613;
            }
        }

g_3484 += 1;


                    if ((safe_add_func_int32_t_s_s((l_2795 = ((safe_add_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(g_75, (((((((safe_lshift_func_uint16_t_u_u((safe_add_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u((+((safe_rshift_func_uint16_t_u_s(g_2667, ((safe_sub_func_uint16_t_u_u(g_112, ((safe_add_func_int16_t_s_s(p_18, p_15)) <= (l_2373.f1 = (l_2476.f3 = (0xDE05L | (3L < (safe_rshift_func_int16_t_s_u(l_2501.f3, (safe_rshift_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u((((g_613 | l_2370) < l_2793) >= 0xF4L), g_1039)), 1))))))))))) | l_2794))) ^ 4294967289UL)), 5)), l_2501.f0)), l_2765)) | g_274.f5) > l_2601.f1) < 1UL) <= 0L) >= g_875) < 2UL))), l_2794)), l_2749)) || (-7L))), g_656.f3)))
        {
            for (g_2214 = 0; (g_2214 <= 41); ++g_2214)
            {
                int32_t l_2811 = (-6L);

{
                    if (g_1568)
                        break;
                }

                    l_2476.f3 = (safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u(((((safe_lshift_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((safe_add_func_int16_t_s_s(l_2432[0], (!((safe_rshift_func_int8_t_s_u(0L, (((0L != p_15) == (l_2811 | ((safe_mod_func_uint8_t_u_u(p_16, (safe_add_func_int8_t_s_s((g_2.f3 < (g_647 = ((p_18 <= ((l_2498 < l_2497[1]) != g_656.f3)) & l_2811))), g_2667)))) > l_2811))) != g_310))) < 65535UL)))), 3)), g_1204)) && g_1039) || p_18) & g_2.f2), l_2373.f1)), 4294967295UL));

for (g_2569 = 0; g_2569 < 5; g_2569++)
        {
            for (g_224 = 0; g_224 < 2; g_224++)
            {
                transparent_crc(g_1177[g_75][g_2569][g_224], "g_1177[g_75][g_2569][g_224]", g_759);
                if (g_759) printf("index = [%d][%d][%d]\n", g_75, g_2569, g_224);

            }
        };



p_17 += 1;


                    l_2501.f3 = (((0xDC2A82A1L != (((((safe_sub_func_int32_t_s_s((safe_lshift_func_int16_t_s_s((l_2370 = (l_2476.f1 = g_1896.f1)), ((0x421E0BECL >= ((((-1L) == (((safe_add_func_uint8_t_u_u(((g_1178 || ((safe_lshift_func_int16_t_s_u((safe_rshift_func_uint16_t_u_s((((((safe_sub_func_uint32_t_u_u((p_18 == ((safe_add_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(g_2317, ((g_2.f0 || (g_658.f2 > l_2832)) == 7L))), g_69)) & 0xB91300D3L)), l_2794)) ^ 0x1D3EFE35L) | p_17) <= l_2833) != 0x8DL), 0)), 4)) != 0xF7L)) != 0xE568L), p_15)) | 0x60FCL) | 0x2FL)) < p_18) == (-1L))) == 255UL))), l_2811)) > l_2498) >= g_647) != g_75) || 0x25A46E49L)) ^ 3L) == p_16);
            }
            l_2834 = (l_2373 = l_2601);
        }
        else
        {
            struct S0 l_2838 = {-1L,1255};
            int32_t l_2844 = 0xEA4CC78BL;
            uint32_t l_2857 = 7UL;
            int16_t l_2932 = 1L;
            if ((safe_lshift_func_int16_t_s_u(g_959, 6)))
            {
                for (g_875 = 0; g_875 < 6; g_875 += 1)
                {
                    l_2497[g_875] = 18446744073709551613UL;
                }
            }
            else
            {
                struct S0 l_2837[8] = {{0x6813F8C5L,-660}, {0x6B31915EL,-1011}, {0x6813F8C5L,-660}, {0x6B31915EL,-1011}, {0x6813F8C5L,-660}, {0x6B31915EL,-1011}, {0x6813F8C5L,-660}, {0x6B31915EL,-1011}};
                int i;
                for (l_2494 = 0; (l_2494 <= 1); l_2494 += 1)
                {
                    struct S1 l_2840 = {127,-3,5344,-0,132,316};
                    for (g_237 = 0; (g_237 >= 0); g_237 -= 1)
                    {
                        struct S0 l_2839 = {0x6DE45221L,-1195};
                        int i, j, k;
                        l_2839 = (l_2838 = l_2837[7]);
                        if (g_40[(l_2494 + 1)])
                            continue;
                        return g_1177[l_2494][(g_237 + 2)][l_2494];
                    }
                    l_2373 = l_2601;
                    for (g_1568 = 0; (g_1568 <= 1); g_1568 += 1)
                    {
                        l_2840 = g_274;
                    }
                }
                for (p_19 = (-13); (p_19 > 34); p_19 = safe_add_func_uint16_t_u_u(p_19, 4))
                {
                    uint32_t l_2843[9][1][2] = {{{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}};
                    uint32_t l_2849 = 0UL;
                    int i, j, k;
                    for (l_2373.f0 = 0; (l_2373.f0 <= 0); l_2373.f0 += 1)
                    {
                        g_656.f1 = l_2837[7].f1;
                        l_2844 = l_2843[7][0][0];
                    }
                    l_2837[7].f1 = (((g_1896.f0 || ((1UL >= (1UL || p_18)) ^ (l_2501.f2 = (l_2370 = (((((((1UL > p_18) ^ (safe_lshift_func_int16_t_s_u(((((g_656.f3 && 0x226129DCL) == ((((((safe_sub_func_uint16_t_u_u(g_656.f2, g_40[1])) ^ 0x10B0F3EFL) > l_2497[1]) || 0x2AL) < l_2849) || 4L)) ^ g_900) & g_40[1]), 13))) == g_1106) >= g_900) || p_16) & 0xDCL) & 1UL))))) ^ l_2765) <= p_15);
                }
            }

{
                    struct S1 l_3154 = {145,14,-8932,-31,30,59};
                    k = l_2620.f0;
                    l_2501 = (l_2501 = l_3154);
                }

                    for (g_415 = (-3); (g_415 >= 18); g_415 = safe_add_func_uint32_t_u_u(g_415, 7))
            {
                struct S1 l_2852 = {190,6,-5246,84,117,243};
                uint16_t l_2914 = 0xFEDCL;

g_647 += 1;



{
                int32_t l_2478[5][4] = {{0L, 0xF0FEAB4AL, 0xB7E3E6CCL, 0xF0FEAB4AL}, {0L, 0xF0FEAB4AL, 0xB7E3E6CCL, 0xF0FEAB4AL}, {0L, 0xF0FEAB4AL, 0xB7E3E6CCL, 0xF0FEAB4AL}, {0L, 0xF0FEAB4AL, 0xB7E3E6CCL, 0xF0FEAB4AL}, {0L, 0xF0FEAB4AL, 0xB7E3E6CCL, 0xF0FEAB4AL}};
                int32_t l_2527 = 8L;
                int16_t l_2567 = 0L;
                int i, j;
                for (l_2370 = 0; (l_2370 >= 0); l_2370 -= 1)
                {
                    uint8_t l_2481 = 255UL;
                    l_2478[2][3] = (safe_unary_minus_func_uint16_t_u(j));
                    g_658.f1 = (safe_lshift_func_uint16_t_u_s(((-8L) <= (0x0C44L > l_2481)), (safe_mod_func_uint16_t_u_u((0x2CBEL <= ((l_2499 = 0x1294L) ^ (safe_sub_func_int16_t_s_s(0xEFF0L, 0xB819L)))), (l_2369 || (safe_rshift_func_uint16_t_u_s((l_2930 >= 1L), l_2481)))))));
                }
                if ((safe_add_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s((0UL < l_2478[2][3]), (0x01AEC1B2L <= (-3L)))) < (g_2.f0 | (((safe_mod_func_uint8_t_u_u((l_2369 <= g_2214), ((5L >= (l_2499 = (((safe_rshift_func_uint16_t_u_u(l_2497[1], 1)) | 0xEA06L) || l_2930))) || l_2369))) == l_2793) || l_2369))) <= l_2838.f0), g_613)))
                {
                    struct S1 l_2500 = {173,2,15151,-16,8,18};
                    if (g_112)
                    {
                        struct S1 l_2502 = {37,-16,-5418,53,71,209};
                        l_2502 = (g_656 = (l_2500 = g_2));
                        g_658.f3 = (safe_add_func_uint32_t_u_u((safe_unary_minus_func_uint8_t_u(((l_2500.f1 = ((l_2931 = ((g_714 = (safe_mod_func_int16_t_s_s((g_656.f1 = (l_2500.f2 = (safe_add_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s((safe_sub_func_int8_t_s_s(g_656.f4, (safe_mod_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u(((safe_mod_func_uint32_t_u_u((g_69 = (((l_2930 >= ((g_656.f1 = (safe_lshift_func_int8_t_s_s((-2L), 4))) > (l_2527 = (safe_rshift_func_int8_t_s_s((1L ^ (safe_rshift_func_int8_t_s_s((!0xE379L), 5))), l_2370))))) == (safe_sub_func_uint16_t_u_u((((((((safe_add_func_uint16_t_u_u(l_2395, 0L)) ^ (g_1106 = 0x9D79L)) | g_613) < l_2369) && g_2317) & 0x48L) ^ l_2930), l_2478[4][3]))) ^ g_2.f1)), g_1184)) | g_63), 0x07L)), l_2500.f4)))), 6L)) & g_40[1]), 0xB6L)))), g_112))) & g_658.f1)) & l_2930)) ^ g_1184))), 4294967295UL));
                    }
                    else
                    {
                        l_2370 = (g_2.f3 || (safe_lshift_func_uint8_t_u_s((((((((safe_add_func_int32_t_s_s((safe_sub_func_int32_t_s_s(((safe_rshift_func_uint16_t_u_s(((safe_add_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_s((safe_add_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((0xF8L >= (((g_2.f2 = ((((((g_658.f5 = (((safe_rshift_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_s((((((safe_add_func_int16_t_s_s((1L && l_2930), 0x8A54L)) ^ (g_2.f1 = (((((((l_2567 = ((safe_add_func_int8_t_s_s((g_1135 & ((safe_lshift_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(0xD4D7L, 13)), 5)) < 8L)), (safe_mod_func_uint16_t_u_u(((g_1204 = (safe_lshift_func_int16_t_s_s(l_2370, 6))) <= 65533UL), l_2432[0])))) < g_1184)) >= g_69) < 8UL) && g_656.f5) != l_2834.f1) >= g_2.f3) < 1UL))) & g_69) && l_2930) & l_2930), 3)), l_2395)) & g_1106), 5)) || (-5L)) && j)) <= l_2369) && l_2930) < g_1184) | 1UL) <= g_656.f2)) == l_2499) >= g_613)), l_2478[3][1])), 1UL)), 1)) < (-1L)), l_2527)) >= l_2369), 15)) & l_2930), (-1L))), g_217[0].f1)) >= g_613) || g_875) == g_69) >= (-6L)) & g_69) > 6L), 5)));
                    }
                    for (g_1135 = 0; (g_1135 <= 0); g_1135 += 1)
                    {
                        g_656 = g_2;
                    }
                }
                else
                {
                    return l_2370;
                }
            }

                    g_1568 = (l_2501.f2 = 6L);
                l_2852 = g_656;

g_1178 += 1;


                    for (g_740 = 15; (g_740 > 27); g_740 = safe_add_func_int8_t_s_s(g_740, 2))
                {
                    uint32_t l_2898 = 4294967295UL;

for (g_1056 = 0; (g_1056 <= 1); g_1056 += 1)
                    {
                        int32_t l_2627 = 0xA02FAE0FL;
                        int i;
                        g_40[g_69] = ((safe_add_func_int8_t_s_s((safe_sub_func_int16_t_s_s(((j = (((safe_lshift_func_int16_t_s_u(((l_2627 = l_2432[l_2395]) > (safe_rshift_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((((((0x52L || 0xC5L) <= (safe_lshift_func_uint16_t_u_u((((l_2497[(g_1056 + 2)] >= (l_2568 = 0x58L)) || ((safe_mod_func_int8_t_s_s((l_2432[l_2395] && ((((((g_264 | (g_274.f1 = ((safe_mod_func_uint32_t_u_u((safe_add_func_uint32_t_u_u(((g_1135 = (l_2833 = (safe_lshift_func_int8_t_s_u((g_1896.f1 == 0x95E8L), 7)))) | p_18), g_40[g_69])), 0x5655E761L)) >= 0x26L))) || l_2852.f0) > g_1568) | 0UL) && g_1106) >= l_2432[l_2395])), 0xB3L)) && l_2833)) < 0L), p_18))) != l_2501.f2) && g_900) >= (-7L)), g_112)), g_658.f2))), 1)) & l_2395) && l_2373.f1)) ^ 0UL), g_1177[2][3][1])), 0xB1L)) || 0x33D5B1B9L);
                        if (g_40[2])
                            continue;
                        g_217[l_2395] = l_2620;
                        return g_900;
                    };


                    l_2795 = (safe_add_func_uint16_t_u_u((1UL & p_18), ((l_2857 | (safe_rshift_func_uint8_t_u_u((g_714 = ((l_2566 = ((0UL <= 4L) | (safe_rshift_func_uint8_t_u_s((g_1178 = ((l_2501.f1 = (safe_sub_func_uint8_t_u_u(p_18, (safe_sub_func_int8_t_s_s((safe_lshift_func_int8_t_s_u((g_1184 = (safe_lshift_func_uint8_t_u_s(6UL, (g_2.f4 | ((+(g_130.f0 >= l_2852.f0)) == 0x5A62595BL))))), 0)), g_2.f1))))) != 0x59L)), 1)))) || g_2.f3)), 3))) || l_2852.f4)));
                    g_1895 = l_2601;
                    if ((safe_lshift_func_int8_t_s_u(((+(safe_sub_func_uint32_t_u_u((0L || (p_17 = (safe_rshift_func_uint16_t_u_s(l_2838.f0, 4)))), g_75))) == ((-1L) | g_274.f2)), l_2857)))
                    {

{
                    int i;
                    g_217[0] = g_217[g_112];
                }

                    g_1895.f1 = l_2793;
                    }
                    else
                    {
                        uint8_t l_2913 = 0x9DL;
                        l_2852.f2 = (safe_mod_func_uint32_t_u_u((l_2838.f1 = ((((safe_sub_func_int8_t_s_s(p_17, g_415)) && (((safe_add_func_uint32_t_u_u((safe_mod_func_int16_t_s_s((l_2852.f3 = ((safe_mod_func_uint8_t_u_u(l_2852.f1, (g_1184 = (p_16 && (safe_lshift_func_uint8_t_u_u((((((safe_add_func_int32_t_s_s((safe_add_func_uint32_t_u_u(p_16, (l_2566 = p_19))), (safe_rshift_func_int16_t_s_u(((safe_add_func_int8_t_s_s((g_2667 = p_17), (l_2373.f1 = l_2852.f4))) ^ g_1184), 15)))) & g_2214) & p_19) != 0x1B3FL) == l_2898), g_1897)))))) > p_18)), 1UL)), l_2370)) & 1L) | 0xFAF6L)) | g_274.f3) && l_2838.f0)), 0xF5299BB1L));
                        g_656.f1 = ((safe_rshift_func_uint8_t_u_u((((((l_2838.f1 = (g_2317 <= (safe_add_func_uint16_t_u_u((8UL < (0xBB9ADCDDL != (l_2852.f3 = (safe_add_func_uint32_t_u_u((l_2852.f1 = (((safe_sub_func_int8_t_s_s((p_18 & (l_2476.f2 = ((safe_sub_func_int8_t_s_s((((g_1184 && (safe_add_func_int8_t_s_s((p_16 = (((g_130.f1 = (safe_lshift_func_int16_t_s_u(l_2913, 0))) <= (l_2852.f1 > g_237)) ^ ((l_2370 != 1UL) < l_2914))), 0x66L))) | l_2898) > 0xB95B8FDAL), l_2838.f1)) > l_2913))), g_217[0].f1)) & l_2913) && g_2.f2)), 0x0D2C52FFL))))), g_274.f1)))) ^ l_2857) <= g_875) > p_18) || l_2898), 4)) && l_2501.f5);
                    }
                }
                l_2932 = (l_2931 = (0x0BL == (((safe_lshift_func_uint16_t_u_s((((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint8_t_u_s((l_2432[0] < 0x2E7CA327L), p_19)), 0)) > ((safe_mod_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(((((safe_lshift_func_uint8_t_u_u(p_19, ((safe_mod_func_uint32_t_u_u((l_2852.f3 = ((+(g_2667 = (-1L))) != g_2.f5)), (l_2566 = ((((0x4AB74D0FL && (l_2795 = (g_658.f0 > 8L))) <= p_18) < g_740) || 0x1EL)))) >= l_2930))) & 0x4A0ED782L) == p_18) >= p_19), p_16)), 65535UL)) >= 0L)) & g_2.f4), 0)) >= g_1177[2][3][1]) & l_2852.f4)));
            }
            l_2373.f1 = (l_2838.f1 || (safe_sub_func_uint32_t_u_u((+(g_1204 = (safe_rshift_func_uint16_t_u_u((((safe_rshift_func_int16_t_s_s(((safe_rshift_func_int16_t_s_s(l_2429[5], l_2932)) ^ (((((safe_lshift_func_int8_t_s_s((g_2667 = (4294967295UL && 4UL)), (p_16 & p_19))) != (safe_mod_func_int16_t_s_s((65535UL & p_16), p_18))) > 0L) != 4294967295UL) || g_1178)), 12)) <= 0x9961D603L) != g_274.f0), 0)))), 1L)));
            if (p_17)
                {
if ((safe_lshift_func_int16_t_s_u(g_969, 6)))
            {
                for (g_1058 = 0; g_1058 < 6; g_1058 += 1)
                {
                    l_2497[g_1058] = 18446744073709551613UL;
                }
            }
            else
            {
                struct S0 l_2837[8] = {{0x6813F8C5L,-660}, {0x6B31915EL,-1011}, {0x6813F8C5L,-660}, {0x6B31915EL,-1011}, {0x6813F8C5L,-660}, {0x6B31915EL,-1011}, {0x6813F8C5L,-660}, {0x6B31915EL,-1011}};
                int i;
                for (g_900 = 0; (g_900 <= 1); g_900 += 1)
                {
                    struct S1 l_2840 = {127,-3,5344,-0,132,316};
                    for (g_237 = 0; (g_237 >= 0); g_237 -= 1)
                    {
                        struct S0 l_2839 = {0x6DE45221L,-1195};
                        int i, j, k;
                        l_2839 = (g_130 = l_2837[7]);
                        if (g_40[(g_900 + 1)])
                            continue;
                        return g_1177[g_900][(g_237 + 2)][g_900];
                    }
                    g_1895 = g_130;

if (g_163)
                break;

                    for (g_875 = 0; (g_875 <= 1); g_875 += 1)
                    {
                        l_2840 = g_2;
                    }
                }
                for (l_2857 = (-13); (l_2857 > 34); l_2857 = safe_add_func_uint16_t_u_u(l_2857, 4))
                {
                    uint32_t l_2843[9][1][2] = {{{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}, {{0xEBEB99C0L, 0x850227CDL}}};
                    uint32_t l_2849 = 0UL;
                    int i, j, k;

if (g_274.f5)
                            continue;

                    for (g_1895.f0 = 0; (g_1895.f0 <= 0); g_1895.f0 += 1)
                    {
                        g_658.f1 = l_2837[7].f1;
                        g_875 = l_2843[7][0][0];
                    }
                    l_2837[7].f1 = (((l_2834.f0 || ((1UL >= (1UL || l_2494)) ^ (g_656.f2 = (g_75 = (((((((1UL > l_2494) ^ (safe_lshift_func_int16_t_s_u(((((g_658.f3 && 0x226129DCL) == ((((((safe_sub_func_uint16_t_u_u(g_658.f2, g_40[1])) ^ 0x10B0F3EFL) > l_2497[1]) || 0x2AL) < l_2849) || 4L)) ^ g_63) & g_40[1]), 13))) == g_112) >= g_63) || l_2930) & 0xDCL) & 1UL))))) ^ l_2499) <= l_2765);
                }
            };


                    continue;}
        }
        if (((l_2946[3][7] & ((0xF3L <= (safe_rshift_func_int8_t_s_u((p_18 == (((((safe_mod_func_int16_t_s_s((l_2501.f2 = 0x6DDCL), (safe_sub_func_int32_t_s_s(((safe_lshift_func_int8_t_s_s(((0x26L & (g_40[1] & 0L)) == (((((~0x18629155L) <= (safe_mod_func_uint16_t_u_u(((0x5BD7L >= l_2370) | p_18), 9UL))) >= 0xDFD4C6E6L) >= 0UL) < p_19)), p_16)) >= p_16), g_656.f3)))) | 1UL) != 1L) ^ g_2569) & g_1896.f1)), 1))) | l_2958)) & g_40[1]))
        {
            int16_t l_2971 = (-2L);
            int32_t l_2980[9][8] = {{0xA1D12C22L, 1L, 1L, 0xA1D12C22L, (-1L), 0x36CE900BL, (-5L), 9L}, {0xA1D12C22L, 1L, 1L, 0xA1D12C22L, (-1L), 0x36CE900BL, (-5L), 9L}, {0xA1D12C22L, 1L, 1L, 0xA1D12C22L, (-1L), 0x36CE900BL, (-5L), 9L}, {0xA1D12C22L, 1L, 1L, 0xA1D12C22L, (-1L), 0x36CE900BL, (-5L), 9L}, {0xA1D12C22L, 1L, 1L, 0xA1D12C22L, (-1L), 0x36CE900BL, (-5L), 9L}, {0xA1D12C22L, 1L, 1L, 0xA1D12C22L, (-1L), 0x36CE900BL, (-5L), 9L}, {0xA1D12C22L, 1L, 1L, 0xA1D12C22L, (-1L), 0x36CE900BL, (-5L), 9L}, {0xA1D12C22L, 1L, 1L, 0xA1D12C22L, (-1L), 0x36CE900BL, (-5L), 9L}, {0xA1D12C22L, 1L, 1L, 0xA1D12C22L, (-1L), 0x36CE900BL, (-5L), 9L}};
            int32_t l_2998 = (-10L);
            int i, j;
            l_2373 = l_2373;

l_2373.f0 += 1;


                    for (g_740 = 0; (g_740 > 50); g_740 = safe_add_func_uint32_t_u_u(g_740, 8))
            {
                int32_t l_2978[1];
                int32_t l_2979 = 0L;
                int i;
                for (i = 0; i < 1; i++)
                    l_2978[i] = 0x5AC4A759L;
                for (l_2601.f0 = 12; (l_2601.f0 != (-8)); l_2601.f0 = safe_sub_func_int16_t_s_s(l_2601.f0, 5))
                {
                    uint8_t l_2981 = 1UL;
                    l_2980[4][5] = ((safe_rshift_func_uint16_t_u_u((l_2978[0] = ((safe_lshift_func_uint8_t_u_s((p_17 = ((l_2601.f1 > g_658.f1) | (safe_lshift_func_int8_t_s_u(((safe_mod_func_uint16_t_u_u((0xC87D36B8L < ((((l_2971 = p_16) < (((safe_add_func_uint32_t_u_u((((g_237 >= (0x9BL ^ (safe_add_func_uint8_t_u_u((l_2463 = l_2501.f5), ((p_15 = (safe_lshift_func_int16_t_s_u((((((p_15 > g_2.f1) & g_217[0].f1) == p_18) < g_1039) <= 0x0FL), g_69))) && 0xAFB6L))))) ^ p_18) & p_18), g_656.f4)) > g_40[1]) & (-1L))) != 0x152AL) < (-1L))), l_2566)) == p_17), 1)))), p_18)) == 0xF90C5357L)), l_2979)) | l_2979);
                    return l_2981;
                }
                if (g_2.f3)
                    {
for (g_211 = 0; (g_211 == (-3)); --g_211)
            {
                uint32_t l_138 = 0UL;
                uint8_t l_145 = 2UL;
                if (((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s((p_15 & (l_2370 = (safe_mod_func_int16_t_s_s(g_174, l_2971)))), 0)) > (g_174 & ((l_2765 = g_2.f0) < (3L & (((safe_add_func_int8_t_s_s(((7L <= g_647) | p_15), g_2.f0)) | 0UL) || 0xE596L))))), 2)) == g_647))
                {
                    l_2463 = g_174;
                }
                else
                {
                    struct S1 l_129 = {74,15,-5951,-51,147,32};
                    struct S0 l_147 = {-6L,1480};
                    for (l_2499 = 0; (l_2499 <= 11); ++l_2499)
                    {
                        int16_t l_146 = 0xA7B7L;
                        l_129 = g_2;
                        g_1895 = g_1895;
                        l_146 = ((safe_rshift_func_int16_t_s_u(((((l_2370 = 0xE8AE3155L) & (l_2499 != (-1L))) >= (safe_lshift_func_int8_t_s_u((l_145 = (!((safe_sub_func_int16_t_s_s((l_138 <= ((g_40[1] <= ((safe_rshift_func_uint8_t_u_s((((l_129.f1 = (((safe_mod_func_uint32_t_u_u((p_15 == (g_174 ^ ((safe_mod_func_uint16_t_u_u(g_1895.f0, 1L)) && l_2794))), l_2395)) <= g_2.f4) == 0x0C3003DDL)) & l_2765) | l_2765), 7)) >= l_129.f3)) && 1UL)), g_2.f5)) == 0xE0L))), 0))) | g_174), g_2.f2)) == g_2.f4);
                    }
                    l_147 = g_1895;
                    if (g_2.f2)
                        break;
                }
            };


                    continue;}
                for (p_17 = 0; (p_17 != 46); p_17++)
                {
                    int32_t l_2984 = 8L;

l_2765 += 1;


                    g_211 = p_17;
                    g_40[1] = ((p_16 ^ p_17) && l_2984);
                    return g_1106;
                }
                g_1896.f1 = (65532UL < (l_2979 = (p_19 > (0UL <= (~(((safe_rshift_func_int8_t_s_s(0x32L, (safe_mod_func_uint32_t_u_u(l_2980[4][5], ((safe_lshift_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_s(p_15, (l_2979 && ((safe_mod_func_int16_t_s_s((safe_sub_func_int32_t_s_s((-1L), g_217[0].f1)), l_2476.f1)) ^ 0UL)))) || 0x17L), 1)) && 246UL))))) < l_2998) && g_656.f4))))));
            }
        }
        else
        {

l_2369 += 1;



{
                struct S1 l_1943[8][9] = {{{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}};
                int i, j;
                l_1943[7][0] = (l_2476 = l_2476);
            }

                    return g_1135;
        }
    }
    return l_2999[4][0][0];
}







static int16_t func_25(int32_t p_26)
{
    uint32_t l_1786 = 18446744073709551610UL;
    int32_t l_1806 = (-5L);
    uint8_t l_1814 = 1UL;
    int32_t l_1815[2];
    int32_t l_1816 = (-3L);
    int32_t l_1817 = 0xED54E622L;
    struct S0 l_1894 = {1L,-315};
    struct S1 l_1927 = {136,-3,-16072,12,178,302};
    int8_t l_1930 = 0x14L;
    struct S1 l_1966[9][9][3] = {{{{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}}, {{{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}}, {{{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}}, {{{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}}, {{{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}}, {{{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}}, {{{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}}, {{{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}}, {{{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}, {{63,-1,-13035,-53,90,249}, {50,9,4230,-69,46,245}, {117,-13,8894,56,94,90}}}};
    int8_t l_2016[6][9] = {{0xC6L, (-6L), 0x4FL, (-6L), 0xC6L, (-1L), 0xC6L, (-6L), 0x4FL}, {0xC6L, (-6L), 0x4FL, (-6L), 0xC6L, (-1L), 0xC6L, (-6L), 0x4FL}, {0xC6L, (-6L), 0x4FL, (-6L), 0xC6L, (-1L), 0xC6L, (-6L), 0x4FL}, {0xC6L, (-6L), 0x4FL, (-6L), 0xC6L, (-1L), 0xC6L, (-6L), 0x4FL}, {0xC6L, (-6L), 0x4FL, (-6L), 0xC6L, (-1L), 0xC6L, (-6L), 0x4FL}, {0xC6L, (-6L), 0x4FL, (-6L), 0xC6L, (-1L), 0xC6L, (-6L), 0x4FL}};
    uint32_t l_2081 = 18446744073709551614UL;
    int16_t l_2091 = (-1L);
    int32_t l_2199 = 0x18C64565L;
    uint32_t l_2212 = 4294967295UL;
    uint32_t l_2219 = 0x8A81A5DEL;
    uint16_t l_2262[8][5][2] = {{{0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}}, {{0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}}, {{0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}}, {{0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}}, {{0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}}, {{0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}}, {{0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}}, {{0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}, {0x9CBCL, 0x93C9L}}};
    uint32_t l_2338 = 4294967295UL;
    int i, j, k;
                                        while (!((g_959 > g_647)) )
{

g_211 += 1;


}
                    for (i = 0; i < 2; i++)
        { if ((g_1135 < g_274.f1) )
{

k -= 1;


}
                    l_1815[i] = 0xD7FE9604L;}
    l_1817 = (0x7BL >= ((l_1786 < (safe_rshift_func_uint16_t_u_s(((safe_lshift_func_int8_t_s_u(((l_1816 = ((safe_add_func_int8_t_s_s((l_1815[1] = (((safe_add_func_uint32_t_u_u(l_1786, ((safe_lshift_func_int16_t_s_s((safe_mod_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s(((+(l_1806 = (safe_lshift_func_int16_t_s_u(p_26, 14)))) || (((safe_mod_func_int16_t_s_s(g_69, ((1L & (!((safe_mod_func_uint8_t_u_u(((safe_lshift_func_int8_t_s_u((g_688 & (p_26 ^ (p_26 || l_1806))), g_69)) ^ (-1L)), 0x53L)) <= 65529UL))) && l_1814))) | p_26) || g_264)), g_224)), l_1786)), l_1786)), g_1039)) & p_26))) >= p_26) < p_26)), 0xFBL)) >= 0UL)) & g_1106), 0)) > l_1814), g_1177[2][3][1]))) <= p_26));
    if ((safe_rshift_func_int8_t_s_u((safe_rshift_func_uint8_t_u_s((safe_rshift_func_int8_t_s_u(((((safe_mod_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u((((safe_add_func_uint16_t_u_u((safe_add_func_uint16_t_u_u(0x9BBBL, l_1816)), 0x1EF6L)) < (safe_rshift_func_uint8_t_u_u((((safe_mod_func_int32_t_s_s(((l_1815[0] | (safe_sub_func_int16_t_s_s(p_26, l_1806))) != ((0xAA45L != ((safe_rshift_func_uint8_t_u_s(l_1814, (safe_mul_func_int16_t_s_s(l_1814, 0L)))) <= l_1817)) & 0xF8L)), l_1815[1])) | 0x7547L) & l_1817), 4))) == l_1815[0]), 8)) < p_26), g_688)) & l_1816) == 0x64L) == l_1786), 5)), 7)), 6)))
    {
        int8_t l_1854 = 0x85L;
        struct S1 l_1865 = {176,-10,11387,53,160,8};
        for (g_969 = 1; (g_969 >= 0); g_969 -= 1)
        {
            int8_t l_1859 = 0xADL;
            int32_t l_1860 = (-9L);
            struct S0 l_1867 = {1L,305};
            int8_t l_1990 = 0x55L;
            int32_t l_1992 = (-1L);
            int i;
            if (l_1815[g_969])
            {
                uint16_t l_1861 = 0x6A41L;
                struct S1 l_1864 = {41,-16,151,64,74,251};
                struct S0 l_1926 = {0x2E512C52L,3};
                if (((~(safe_rshift_func_uint8_t_u_s((safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u((((g_40[1] == (safe_lshift_func_uint8_t_u_s((((l_1815[g_969] == (g_969 ^ (!(0xC5D27E3CL < (l_1854 > (safe_rshift_func_uint8_t_u_s((((l_1861 = ((g_959 | ((l_1860 = ((((safe_sub_func_int32_t_s_s(p_26, (0x4B77L | 0xBDD2L))) || 0xADBB7538L) && (-1L)) && l_1859)) | g_69)) & 65535UL)) != 65535UL) || p_26), 7))))))) > 255UL) != 0xFD47A197L), 2))) >= 1L) | g_224), 13)), 12)), l_1854))) != g_40[0]))
                {
                    uint16_t l_1882 = 0x3F61L;
                    for (g_310 = (-15); (g_310 <= 17); g_310 = safe_add_func_uint8_t_u_u(g_310, 1))
                    {
                        struct S1 l_1866 = {0,-12,4423,59,44,361};

for (l_1992 = 0; (l_1992 <= 1); l_1992 += 1)
                    {
                        g_2 = l_1927;
                    };


                    l_1866 = (l_1865 = l_1864);

if (g_2098)
                            break;


for (g_875 = 0; (g_875 == (-3)); --g_875)
            {
                uint32_t l_138 = 0UL;
                uint8_t l_145 = 2UL;
                if (((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s((g_1056 & (k = (safe_mod_func_int16_t_s_s(g_900, g_1204)))), 0)) > (g_900 & ((g_163 = g_2.f0) < (3L & (((safe_add_func_int8_t_s_s(((7L <= i) | g_1056), g_2.f0)) | 0UL) || 0xE596L))))), 2)) == i))
                {
                    g_1058 = g_900;
                }
                else
                {
                    struct S1 l_129 = {74,15,-5951,-51,147,32};
                    struct S0 l_147 = {-6L,1480};
                    for (g_1106 = 0; (g_1106 <= 11); ++g_1106)
                    {
                        int16_t l_146 = 0xA7B7L;
                        l_129 = g_2;
                        g_1896 = g_1896;
                        l_146 = ((safe_rshift_func_int16_t_s_u(((((k = 0xE8AE3155L) & (g_1106 != (-1L))) >= (safe_lshift_func_int8_t_s_u((l_145 = (!((safe_sub_func_int16_t_s_s((l_138 <= ((g_40[1] <= ((safe_rshift_func_uint8_t_u_s((((l_129.f1 = (((safe_mod_func_uint32_t_u_u((g_1056 == (g_900 ^ ((safe_mod_func_uint16_t_u_u(g_1896.f0, 1L)) && g_69))), l_1859)) <= g_2.f4) == 0x0C3003DDL)) & g_163) | g_163), 7)) >= l_129.f3)) && 1UL)), g_2.f5)) == 0xE0L))), 0))) | g_900), g_2.f2)) == g_2.f4);
                    }

{
                        uint32_t l_3397 = 18446744073709551612UL;
                        g_237 = l_3397;
                    }

                    l_147 = g_1896;

g_415 += 1;


                    if (g_2.f2)
                        break;
                }
            };


                    g_217[0] = l_1867;
                    }
                    for (l_1817 = 0; (l_1817 <= 2); l_1817 += 1)
                    {
                        int i;
                        l_1864.f2 = (((((((l_1864.f3 = g_40[l_1817]) ^ (0x6CBDL == ((((l_1859 | l_1864.f2) & 2L) ^ ((!l_1815[1]) > (g_69 > (((safe_unary_minus_func_uint16_t_u((safe_rshift_func_int16_t_s_s((((g_69 | (safe_rshift_func_uint8_t_u_u((((safe_sub_func_int32_t_s_s(((l_1867.f1 = (((safe_rshift_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s(l_1865.f1, 4)), g_714)), g_658.f5)) & g_1106) > 0xEF62L)) > 1UL), g_274.f4)) != 0x7FBCL) != 9L), 3))) > 1L) <= p_26), 0)))) >= l_1882) != g_40[1])))) > g_1056))) & g_40[0]) <= l_1882) | 0x18C9B83AL) && g_613) <= p_26);
                        l_1864.f1 = (((safe_sub_func_int32_t_s_s(g_40[l_1817], (((safe_unary_minus_func_uint16_t_u((p_26 > ((safe_lshift_func_uint8_t_u_u((((((7UL ^ l_1786) != (((safe_sub_func_uint8_t_u_u(((g_217[0].f1 ^ 0UL) != (g_211 >= g_40[l_1817])), (((safe_sub_func_int32_t_s_s((g_211 ^ l_1864.f2), l_1816)) >= g_174) == g_40[l_1817]))) == g_2.f4) & l_1867.f0)) > p_26) <= 0xCA73L) <= g_112), 3)) < p_26)))) >= 0x50L) < p_26))) && g_656.f1) > 0xEEL);

if (g_40[2])
                            {
{
                        g_237 = (g_237 || l_1786);
                    }

                    continue;}

                    g_1896 = (g_1895 = (g_217[0] = (g_130 = l_1894)));

for (l_1817 = 0; (l_1817 != 19); ++l_1817)
                {
                    if (k)
                        break;
                };



g_2569 -= 1;


                    return g_759;
                    }
                }
                else
                {



{
                    int8_t l_265 = 1L;
                    g_40[1] = ((((l_265 = (safe_lshift_func_uint16_t_u_s(3UL, (g_1184 > (safe_rshift_func_uint8_t_u_s((((g_971 >= (safe_sub_func_uint8_t_u_u(l_1926.f1, (g_1135 = ((safe_lshift_func_uint16_t_u_s(g_971, 8)) <= l_1817))))) == g_900) <= 7UL), 3)))))) || (safe_mod_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(g_2.f2, g_415)), g_2.f1))) && g_1184) >= g_1184);
                    for (l_1854 = 0; (l_1854 <= 4); l_1854 += 1)
                    {
                        l_1817 = g_40[1];
                    }
                }

                    g_163 += 1;


                    for (g_759 = 0; (g_759 <= 0); g_759 += 1)
                {
                    int32_t l_3406[5][6][5] = {{{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}, {{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}, {{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}, {{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}, {{(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}, {(-6L), 0xC186B30EL, 0xF2AFD43EL, 1L, 0xC186B30EL}}};
                    int i, j, k;

l_2219 += 1;



for (l_1816 = 0; l_1816 < 2; l_1816++)
            {
                transparent_crc(g_1177[g_688][l_1992][l_1816], "g_1177[g_688][l_1992][l_1816]", g_1058);
                if (g_1058) printf("index = [%d][%d][%d]\n", g_688, l_1992, l_1816);

            };


                    for (l_1867.f0 = 0; (l_1867.f0 <= 1); l_1867.f0 += 1)
                    {
                        uint32_t l_3397 = 18446744073709551612UL;
                        g_2317 = l_3397;
                    }
                    g_274 = l_1865;
                    i = (safe_rshift_func_uint8_t_u_s((l_1786 | ((safe_mod_func_int16_t_s_s((((safe_add_func_uint8_t_u_u(((l_2091 = (g_69 >= (~249UL))) == ((0xF820L > (g_1056 || l_1927.f5)) && (0x6EL != g_656.f0))), ((((((0xD75D51DDL ^ g_2569) <= (-1L)) | l_3406[0][2][0]) || g_2.f0) >= l_1926.f0) >= l_1854))) | g_656.f3) | 65529UL), g_2.f2)) <= l_3406[4][3][3])), 1));
                }
if (g_163)
                    continue;

                    ;


                    l_1867.f1 = (g_1897 ^ l_1786);
                }

l_1926.f0 += 1;


                    for (g_1039 = 0; (g_1039 > 51); g_1039 = safe_add_func_int16_t_s_s(g_1039, 5))
                {
                    uint32_t l_1916 = 4UL;
                    for (g_1895.f0 = 5; (g_1895.f0 > 20); g_1895.f0++)
                    {
                        uint8_t l_1925 = 0x3EL;
                        l_1864.f2 = (0UL && ((((g_740 >= (g_274.f2 = (p_26 & (safe_mod_func_int32_t_s_s((l_1816 = 0x050CE2D4L), (safe_add_func_int16_t_s_s((((safe_lshift_func_uint16_t_u_s(((g_163 = ((safe_lshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u((l_1916 ^ 0xFFL), (l_1864.f1 = (safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(p_26, (g_759 = 1L))) == (g_656.f2 = (safe_rshift_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(g_75, l_1925)), g_900)))) <= (-3L)), l_1864.f3))))), 6)), l_1864.f0)), 0)) == 0xCC4DL)) & g_2.f2), 11)) >= g_264) <= (-1L)), 0x90D6L))))))) < l_1786) || g_1897) ^ 0x23L));

l_2081 += 1;


                    g_217[0] = (l_1926 = l_1867);
                        l_1864 = l_1927;
                        if (p_26)
                            break;
                    }
                    return l_1859;
                }
                l_1865.f1 = ((l_1865.f2 = ((safe_sub_func_uint32_t_u_u(l_1930, (safe_rshift_func_uint16_t_u_s(((l_1930 | ((safe_lshift_func_uint8_t_u_s(((((1UL <= (~0L)) && (safe_add_func_int8_t_s_s(p_26, ((-1L) != (8L > ((-1L) != g_310)))))) < g_1568) == l_1865.f2), 7)) == p_26)) <= 2L), g_656.f4)))) == l_1867.f1)) > p_26);
                l_1806 = (p_26 && ((safe_sub_func_int16_t_s_s(l_1865.f2, 8L)) && l_1867.f0));
            }
            else
            {
                uint16_t l_1940 = 5UL;
                return l_1940;
            }
            for (g_69 = 20; (g_69 == 56); g_69 = safe_add_func_int8_t_s_s(g_69, 5))
            {
                struct S1 l_1943[8][9] = {{{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}};
                int i, j;

if (g_613)
                            break;

                    l_1943[7][0] = (l_1927 = l_1927);
            }
            for (g_130.f0 = 5; (g_130.f0 != (-9)); g_130.f0 = safe_sub_func_uint32_t_u_u(g_130.f0, 9))
            {
                uint8_t l_1958[5] = {1UL, 0UL, 1UL, 0UL, 1UL};
                int32_t l_1962[6][4];
                int i, j;
                for (i = 0; i < 6; i++)
                {
                    for (j = 0; j < 4; j++)
                        l_1962[i][j] = 0L;
                }

{
                        l_1894.f1 = g_63;
                    }

                    if ((l_1927.f3 != (!((g_1568 >= ((-1L) < l_1865.f1)) == (safe_sub_func_int16_t_s_s(((((p_26 || (safe_add_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_u(g_658.f5, 1)) >= (((((l_1865.f2 = (safe_rshift_func_uint16_t_u_u(((g_959 = (safe_sub_func_uint16_t_u_u((g_415 = ((l_1865.f2 <= (65534UL || (+0x489BL))) <= 1UL)), 3UL))) < g_237), p_26))) >= g_658.f4) <= 7UL) | 0x1ADBL) || 1UL)), g_658.f2))) && l_1814) == l_1958[0]) || p_26), g_2.f4))))))
                {
                    int32_t l_1961[5][3] = {{0L, 0L, 0x59E520ADL}, {0L, 0L, 0x59E520ADL}, {0L, 0L, 0x59E520ADL}, {0L, 0L, 0x59E520ADL}, {0L, 0L, 0x59E520ADL}};
                    int i, j;

for (g_969 = 6; (g_969 >= 1); g_969 -= 1)
                {
                    struct S0 l_3535 = {0x11C838F9L,694};
                    l_3535 = (l_1867 = g_1896);
                };


                    g_217[0].f1 = (g_658.f1 = (safe_mod_func_uint32_t_u_u((((l_1958[0] >= (((l_1962[1][0] = (l_1961[3][2] = (0xB9L < g_1058))) > ((0UL >= p_26) == l_1867.f1)) | 8UL)) ^ ((safe_rshift_func_int8_t_s_s((g_237 && ((((!(g_1106 != g_1178)) | 0xC140E0E0L) > p_26) >= l_1894.f0)), 2)) <= 0x0A711732L)) & 65527UL), p_26)));

l_1894.f0 -= 1;


                    return g_274.f4;
                }
                else
                {
                    return g_264;
                }
            }
            if ((((0xBBL == (l_1865.f1 = 0UL)) > (l_1867.f1 & p_26)) != (4UL <= ((l_1817 = p_26) ^ g_1056))))
            {
                l_1966[2][2][0] = l_1927;
                if (l_1815[g_969])
                    break;
                l_1815[g_969] = (g_274.f3 = (safe_mod_func_uint8_t_u_u((g_900 & (g_959 | (safe_sub_func_uint16_t_u_u((g_740 && ((safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint16_t_u((l_1966[2][2][0].f4 == (safe_add_func_int16_t_s_s(p_26, (0xA5L != l_1966[2][2][0].f2)))))), 2)) || ((((((safe_lshift_func_uint8_t_u_u((((g_2.f1 >= l_1930) != 1L) == l_1865.f4), l_1930)) != 0x07L) > 0x3BL) < 0xBD918B8AL) | l_1865.f3) || p_26))), g_274.f1)))), p_26)));
            }
            else
            {
                uint16_t l_1984 = 0xD467L;
                int32_t l_1991 = 1L;
                for (g_224 = 0; (g_224 >= 8); ++g_224)
                {
                    for (g_613 = 0; (g_613 <= 0); g_613 += 1)
                    {
                        int i;
                        g_217[g_613] = g_217[g_613];
                        g_217[0] = g_217[g_613];
                        g_40[g_969] = ((safe_mod_func_int8_t_s_s((safe_add_func_uint8_t_u_u(g_40[(g_613 + 2)], ((g_40[(g_613 + 1)] != (l_1815[g_969] = ((l_1991 = (((((((l_1984 = (g_959 = 0xEB1AL)) & (g_1204 = (l_1865.f2 = (safe_add_func_uint16_t_u_u(g_217[g_613].f1, ((((safe_sub_func_uint32_t_u_u(g_1204, ((l_1865.f3 = (safe_unary_minus_func_uint8_t_u(l_1990))) == ((p_26 < p_26) <= g_274.f5)))) ^ (-6L)) < g_1895.f0) || 0x98D1L)))))) && p_26) && l_1867.f1) > g_759) || g_2.f5) > 9UL)) & (-10L)))) > g_211))), l_1992)) <= g_969);
                    }
                }
            }
        }

g_2317 += 1;


                    g_688 = l_1865.f5;

l_2091 += 1;


                    for (g_1056 = 0; (g_1056 <= 0); g_1056 += 1)
        {
            g_130.f1 = ((p_26 && ((l_1865.f2 = 0xDDE33A30L) != ((p_26 <= (g_40[1] == (safe_add_func_uint16_t_u_u((g_163 = 3UL), g_900)))) != 8UL))) && p_26);
            g_310 = l_1865.f4;

{
                    uint32_t l_1916 = 4UL;
                    for (g_1896.f0 = 5; (g_1896.f0 > 20); g_1896.f0++)
                    {
                        uint8_t l_1925 = 0x3EL;
                        l_1927.f2 = (0UL && ((((l_2338 >= (g_274.f2 = (g_224 & (safe_mod_func_int32_t_s_s((l_1806 = 0x050CE2D4L), (safe_add_func_int16_t_s_s((((safe_lshift_func_uint16_t_u_s(((g_1106 = ((safe_lshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u((l_1916 ^ 0xFFL), (l_1927.f1 = (safe_add_func_uint32_t_u_u((((safe_sub_func_int32_t_s_s(g_224, (g_3324 = 1L))) == (l_1865.f2 = (safe_rshift_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(g_237, l_1925)), g_740)))) <= (-3L)), l_1927.f3))))), 6)), l_1927.f0)), 0)) == 0xCC4DL)) & l_1927.f2), 11)) >= g_714) <= (-1L)), 0x90D6L))))))) < g_63) || g_3484) ^ 0x23L));
                        g_217[0] = (g_130 = g_1895);
                        l_1927 = l_1927;
                        if (g_224)
                            {
{
                        g_224 = (g_224 || g_63);
                    }

                    break;}
                    }

{
                        struct S0 l_1266 = {0x0AD0680CL,-1162};
                        g_237 = (safe_lshift_func_uint8_t_u_u(g_130.f1, 2));
                        l_1927.f1 = ((safe_sub_func_uint16_t_u_u((safe_unary_minus_func_uint32_t_u(((safe_sub_func_int32_t_s_s(g_63, ((safe_mod_func_uint8_t_u_u((g_1135 = g_237), g_274.f3)) || ((safe_mod_func_int32_t_s_s(0L, g_237)) & g_658.f3)))) == ((g_163 != ((g_237 || (safe_add_func_uint32_t_u_u((g_163 || 0x3C37L), g_237))) == 1UL)) >= g_274.f2)))), (-5L))) == g_163);
                        l_1266 = g_1896;
                    }


{
                        l_1865 = g_658;
                    }

                    return l_1854;
                }

                    for (g_130.f0 = 1; (g_130.f0 >= 0); g_130.f0 -= 1)
            {
                g_658.f3 = (safe_sub_func_int16_t_s_s(0L, 0L));
                for (g_1039 = 0; (g_1039 <= 1); g_1039 += 1)
                {
                    int i;
                    g_217[0] = g_217[g_1056];
                }
            }
        }
    }
    else
    {
        int8_t l_2008[4];
        int8_t l_2041[2][7] = {{(-10L), (-10L), 0xB3L, (-10L), (-10L), 0xB3L, (-10L)}, {(-10L), (-10L), 0xB3L, (-10L), (-10L), 0xB3L, (-10L)}};
        int32_t l_2043 = 0x95BE3990L;
        int32_t l_2143 = 0xD0E5BDAFL;
        struct S0 l_2181[4] = {{-2L,-1738}, {-2L,-1738}, {-2L,-1738}, {-2L,-1738}};
        int32_t l_2252 = 0x018285E7L;
        int32_t l_2297 = (-1L);
        int16_t l_2300 = 0x3230L;
        uint32_t l_2314 = 0xF5DB9CA0L;
        uint32_t l_2365 = 0xEF3406B2L;
        int i, j;
                                                                               if (!((g_613<253)))
                    while ((l_1894.f1>-315) )
{

if (g_613)
                    {
                        g_274 = (g_656 = g_656);
                        l_2297 = (g_969 && g_2214);
                    }
                    else
                    {
                        g_1568 = 1L;
                    };


}
                    for (i = 0; i < 4; i++)
            l_2008[i] = (-10L);
        if (g_174)
        {
            int32_t l_2003 = 0x6FDBD163L;
            int32_t l_2011 = 0xDDDF1ED5L;
            int16_t l_2021 = (-5L);
            int16_t l_2179[3][9] = {{(-1L), 1L, (-1L), 1L, (-1L), 1L, (-1L), 1L, (-1L)}, {(-1L), 1L, (-1L), 1L, (-1L), 1L, (-1L), 1L, (-1L)}, {(-1L), 1L, (-1L), 1L, (-1L), 1L, (-1L), 1L, (-1L)}};
            int i, j;
                                                if (((l_1894.f1 > g_224) && (!l_1894.f0)) )
{

{
                    for (g_2317 = 24; (g_2317 <= 23); g_2317 = safe_sub_func_int32_t_s_s(g_2317, 5))
                    {
                        int8_t l_1498[9][6][4] = {{{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}};
                        int32_t l_1503 = 0x172577FDL;
                        int i, j, k;
                        g_900 = 0L;

if (((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s((g_1106 & (l_2199 = (safe_mod_func_int16_t_s_s(l_2365, l_2021)))), 0)) > (l_2365 & ((g_415 = l_1927.f0) < (3L & (((safe_add_func_int8_t_s_s(((7L <= g_224) | g_1106), l_1927.f0)) | 0UL) || 0xE596L))))), 2)) == g_224))
                {
                    g_310 = l_2365;
                }
                else
                {
                    struct S1 l_129 = {74,15,-5951,-51,147,32};
                    struct S0 l_147 = {-6L,1480};
                    for (g_1056 = 0; (g_1056 <= 11); ++g_1056)
                    {
                        int16_t l_146 = 0xA7B7L;
                        l_129 = l_1927;
                        l_1894 = l_1894;
                        l_146 = ((safe_rshift_func_int16_t_s_u(((((l_2199 = 0xE8AE3155L) & (g_1056 != (-1L))) >= (safe_lshift_func_int8_t_s_u((g_1178 = (!((safe_sub_func_int16_t_s_s((g_1039 <= ((g_40[1] <= ((safe_rshift_func_uint8_t_u_s((((l_129.f1 = (((safe_mod_func_uint32_t_u_u((g_1106 == (l_2365 ^ ((safe_mod_func_uint16_t_u_u(l_1894.f0, 1L)) && l_2212))), l_1930)) <= l_1927.f4) == 0x0C3003DDL)) & g_415) | g_415), 7)) >= l_129.f3)) && 1UL)), l_1927.f5)) == 0xE0L))), 0))) | l_2365), l_1927.f2)) == l_1927.f4);
                    }
                    l_147 = l_1894;
                    if (l_1927.f2)
                        break;
                };


                    g_310 = ((safe_lshift_func_uint16_t_u_u((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u((l_2091 = (6UL ^ (g_1897 && 6UL))), 0)) < ((-1L) | l_1498[5][2][2])), l_1498[3][2][2])) ^ ((safe_mod_func_int32_t_s_s(((safe_sub_func_uint32_t_u_u(g_310, (l_1503 = (((g_2317 > 1UL) <= g_2098) & 255UL)))) != 1UL), 2L)) | g_163)) | g_656.f0), 12)) ^ g_2667);
                    }
                }

}
                    l_2011 = (((((((l_1927.f3 = (safe_add_func_uint32_t_u_u((0x72D8A7C8L <= (safe_add_func_uint32_t_u_u(p_26, ((safe_lshift_func_int16_t_s_s(l_2003, (safe_mod_func_uint32_t_u_u((0x23L <= ((((0xCA53L ^ (p_26 ^ (safe_sub_func_int16_t_s_s(g_274.f1, l_2008[2])))) != (((((safe_mod_func_int8_t_s_s((p_26 == p_26), 0x3CL)) > 0x2966L) < 0x74L) & p_26) & 0xFDL)) == g_69) > p_26)), g_647)))) <= l_2003)))), 0x13FE7FA6L))) & 6UL) > 0L) && g_1204) ^ p_26) > l_1894.f0) <= p_26);
            if ((safe_add_func_int32_t_s_s(((248UL & (!(l_2011 = p_26))) <= g_217[0].f0), ((!(((0x840FB4D7L > l_2016[2][1]) >= (((((p_26 >= (((safe_sub_func_int32_t_s_s((safe_sub_func_int8_t_s_s(l_2021, (safe_sub_func_int32_t_s_s((safe_add_func_uint8_t_u_u(l_1966[2][2][0].f1, (l_1815[0] = (g_1135 | p_26)))), p_26)))), p_26)) != 1UL) > g_759)) | g_658.f2) == 8L) >= p_26) == p_26)) ^ p_26)) < g_211))))
            {
                int32_t l_2054 = 9L;
                int32_t l_2055 = (-1L);
                struct S0 l_2057 = {0xA871BB6AL,369};
                int32_t l_2090[10][10][2] = {{{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}};
                uint16_t l_2144 = 65532UL;
                int i, j, k;
                if (((g_656.f3 == ((safe_mod_func_uint16_t_u_u(0x1652L, (safe_lshift_func_uint8_t_u_s(((safe_mod_func_int32_t_s_s((4294967289UL < (((((g_656.f5 = ((safe_lshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u(((l_1815[1] = g_656.f2) ^ ((safe_rshift_func_int16_t_s_u(0x4C94L, (safe_sub_func_uint8_t_u_u((safe_unary_minus_func_int32_t_s(0L)), l_2041[0][1])))) & (l_2043 = (!0x760D3DE3L)))), (l_1927.f3 = (safe_rshift_func_uint8_t_u_u(((l_1817 = (((safe_rshift_func_int16_t_s_u(((safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((g_1178 = (l_2054 = (safe_mod_func_uint32_t_u_u(g_969, p_26)))), p_26)), l_2008[2])) == g_2.f1), l_2011)) < p_26) != g_875)) > p_26), l_2055))))), 5)) && p_26)) ^ g_688) & p_26) & l_2041[0][1]) < l_2021)), l_2055)) < 2L), 2)))) || p_26)) >= 255UL))
                {
                    struct S0 l_2056 = {-1L,1122};
                    int32_t l_2072 = 0x4AFDEC30L;

g_310 += 1;


                    l_2057 = l_2056;

g_1184 -= 1;



{
                        l_2252 = 1L;
                    }

                    if ((l_2057.f1 && (l_1966[2][2][0].f3 = (g_1056 = (safe_lshift_func_int8_t_s_u(((safe_sub_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((g_174 || (g_647 < l_2008[2])), ((0x971619E2L | (((((safe_mod_func_int32_t_s_s(((safe_rshift_func_int16_t_s_u(3L, 14)) >= (1L >= (((l_1927.f1 = (g_1184 = (((0xD1F5ED2CL >= (l_2072 = ((((l_2056.f1 = (safe_lshift_func_int16_t_s_s(((safe_mod_func_int32_t_s_s(p_26, 0x0B3B51A7L)) >= p_26), 12))) == l_2056.f0) <= l_2056.f0) <= 0UL))) ^ p_26) & 7UL))) | 0xEDL) | 0UL))), g_1895.f0)) != 0xCD742DA1L) == p_26) | p_26) >= l_2003)) <= p_26))), g_1896.f0)) & 0xF7L), 5))))))
                    {
                        int8_t l_2076[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_2076[i] = (-1L);
                        g_274.f1 = g_69;
                        l_1806 = 1L;
                        l_2043 = ((safe_sub_func_uint8_t_u_u(g_40[1], (+l_2076[1]))) || ((((((((g_2.f0 > (safe_lshift_func_uint8_t_u_u((safe_add_func_uint16_t_u_u((l_2081 >= (safe_sub_func_uint32_t_u_u((((((-1L) && (safe_mod_func_uint32_t_u_u(((safe_mod_func_uint32_t_u_u((safe_add_func_uint32_t_u_u((p_26 >= 0x42L), g_163)), g_658.f1)) > l_2011), p_26))) ^ 1L) >= l_2043) ^ l_2090[9][8][1]), 0UL))), 3UL)), 3))) && l_2055) == 0x53L) < l_2072) >= l_2008[2]) ^ g_656.f5) >= p_26) < l_2091));
                        g_274.f1 = ((l_2056.f0 <= (safe_mod_func_uint8_t_u_u(((((safe_add_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u(g_2098, g_2.f4)), ((((safe_lshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u(p_26, ((safe_sub_func_int16_t_s_s((safe_rshift_func_int8_t_s_s(1L, ((safe_lshift_func_int16_t_s_u(0x9F7EL, (((safe_mod_func_uint8_t_u_u(((safe_mod_func_uint16_t_u_u((l_1816 != ((p_26 || (0x14L | p_26)) ^ 0x02L)), 0xB743L)) >= (-2L)), g_264)) & p_26) & p_26))) ^ g_656.f5))), 65530UL)) | l_2056.f0))), g_969)) > l_2076[1]) == l_2076[1]) | l_2041[0][1]))) & p_26) > p_26) != l_2072), (-10L)))) | 0xD636L);
                    }
                    else
                    {
                        l_2011 = (0x1696D010L | ((p_26 | 0xC4L) ^ g_2.f5));
                    }

for (l_1817 = 0; l_1817 < 4; l_1817++)
        {
            transparent_crc(g_3735[g_3324][l_1817], "g_3735[g_3324][l_1817]", j);
            if (j) printf("index = [%d][%d]\n", g_3324, l_1817);

        };


                    l_2057.f1 = (safe_sub_func_uint32_t_u_u((safe_rshift_func_int16_t_s_s(((l_2055 = (((safe_mod_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_u(p_26, (l_2043 = (+((g_647 = l_1930) | 0xF178BAB5L))))), (safe_mod_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u(((safe_sub_func_uint32_t_u_u(5UL, p_26)) < (l_2143 = (((((((l_1816 = (((safe_rshift_func_int8_t_s_s(0x40L, p_26)) != (safe_lshift_func_int8_t_s_u((safe_add_func_int16_t_s_s((safe_sub_func_int8_t_s_s(((((~(((safe_lshift_func_int16_t_s_s((((((((safe_lshift_func_uint8_t_u_s(0x3BL, (l_2041[0][1] | p_26))) <= 0x1288868AL) || l_2057.f1) >= p_26) || g_658.f0) | g_2.f0) || l_2056.f0), 3)) <= g_1106) || 0xDC80L)) ^ p_26) != l_2056.f1) != p_26), p_26)), p_26)), 1))) ^ g_130.f1)) <= 0x75L) ^ p_26) & g_415) != g_2.f0) ^ l_2090[9][8][1]) > l_2090[9][8][1]))), 1UL)) != g_1897), g_274.f1)), p_26)))) || p_26) | l_2144)) < 0xEFFAL), 4)), 4294967286UL));
                    for (g_959 = 0; (g_959 <= 1); g_959 += 1)
                    {
                        int8_t l_2156 = 0x9EL;
                        g_1896.f1 = (g_1058 = (safe_mod_func_int32_t_s_s((l_2056.f1 = (0x854D7E61L > (0x9E0EL != (((safe_rshift_func_int16_t_s_u(1L, 4)) == 1L) || g_217[0].f1)))), ((-7L) ^ (+(l_2008[2] & (g_2.f0 || (((((safe_mod_func_uint16_t_u_u((((l_2156 = ((safe_add_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((g_415 = 0x61B0L), g_274.f5)) > g_274.f4), l_2072)) && 1UL)) || l_1927.f2) | 1L), 0x671BL)) == 0x9BL) != p_26) ^ g_1896.f0) >= 4294967295UL))))))));

{
                        int8_t l_1498[9][6][4] = {{{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}};
                        int32_t l_1503 = 0x172577FDL;
                        int i, j, k;
                        l_2365 = 0L;
                        g_1568 = ((safe_lshift_func_uint16_t_u_u((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u((g_2098 = (6UL ^ (g_1135 && 6UL))), 0)) < ((-1L) | l_1498[5][2][2])), l_1498[3][2][2])) ^ ((safe_mod_func_int32_t_s_s(((safe_sub_func_uint32_t_u_u(g_1568, (l_1503 = (((k > 1UL) <= l_2091) & 255UL)))) != 1UL), 2L)) | l_2144)) | g_274.f0), 12)) ^ g_1184);
                    }

                    l_2011 = 0x1E595EA1L;
                    }
                }
                else
                {
                    int32_t l_2157 = 6L;
                    struct S0 l_2166 = {0x1EE1138AL,-1097};
                    g_656.f3 = ((0x95FDL || l_2021) <= (((((((((g_2098 = l_2157) >= ((((l_2143 = ((g_2.f2 = l_2003) <= (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_s((g_613 >= (safe_add_func_int16_t_s_s(l_1817, (0xA0L < (safe_add_func_uint16_t_u_u(((l_2003 | 0xA63F201AL) ^ 0xCFF3DD30L), l_2157)))))), g_1135)) == g_130.f0), p_26)))) | 65535UL) & l_2157) | p_26)) < l_1814) >= g_264) > g_714) > (-1L)) < p_26) == g_274.f3) > 1L));
                    g_1896 = (l_1894 = l_2166);
                }
                for (g_211 = 0; (g_211 != 19); ++g_211)
                {
                    if (p_26)
                        { int16_t BHJHJgg_969 = (~((((~(g_310)) | (g_1058 % g_1897)) | ((~((~(((~(((~((l_2054 % (~(g_69))))) % l_1927.f1))) | (g_969 + ((~(g_658.f4)) | l_2252))))))) * (~(l_1806))))));
uint32_t BHJHJhg_69 = (~(((~(((~((~((~((g_1058 % l_1927.f1))))))) * ((~((l_2252 >> ((~(l_1806)) * g_310)))) ^ (BHJHJgg_969 & l_2054))))) % (~((~(((~(((~((~(g_969)))) & (~(g_69))))) & (g_1897 || g_658.f4)))))))));
uint8_t BHJHJig_1897 = (~((((~(((l_1806 + (~(l_2252))) ^ (~((~((g_1897 & g_658.f4)))))))) ^ (~(((g_69 + (BHJHJhg_69 & g_969)) || (~(l_2054)))))) ^ ((g_1058 ^ (~(l_1927.f1))) | (BHJHJgg_969 ^ g_310)))));
uint16_t BHJHJjg_658_f4 = (~(((((~(g_1897)) || g_69) & l_2252) & (((~(BHJHJhg_69)) + g_658.f4) * (((~(l_1927.f1)) * (~((l_2054 & g_310)))) ^ ((g_1058 || (~((~(l_1806))))) & (g_969 || (BHJHJig_1897 + BHJHJgg_969))))))));
int32_t BHJHJkl_2054 = (~(((((BHJHJjg_658_f4 ^ (~((l_1927.f1 ^ (g_1897 || BHJHJhg_69))))) & (~(g_69))) % ((((BHJHJgg_969 || (~((~(l_2054))))) & ((g_658.f4 ^ g_969) ^ l_1806)) | (~((~((~(l_2252))))))) * ((~(g_310)) | BHJHJig_1897))) ^ (~((~((~(g_1058)))))))));
int32_t BHJHJll_1806 = (~((((~(l_1927.f1)) ^ (~(((~(BHJHJig_1897)) % (~((~((((BHJHJjg_658_f4 + ((g_310 << g_69) ^ g_658.f4)) | (~((~(BHJHJgg_969))))) || ((~((~(l_2252)))) & l_2054)))))))))) * (~((~((~(((~(((~(((g_1058 & g_1897) ^ l_1806))) + (~(g_969))))) | (BHJHJkl_2054 * BHJHJhg_69)))))))))));
if((g_310 > l_1806)){
BHJHJgg_969 = g_969;
                                   if (g_613)
                    BHJHJhg_69 = g_69;
BHJHJig_1897 = g_1897;
BHJHJjg_658_f4 = g_658.f4;
BHJHJkl_2054 = l_2054;
BHJHJll_1806 = l_1806;
g_969 = (~((((BHJHJkl_2054 || (~((g_658.f4 ^ (~(g_969)))))) & (((~((g_310 >> ((~(l_2252)) || l_1927.f1)))) || (~((~(BHJHJll_1806))))) || (BHJHJhg_69 | (BHJHJgg_969 ^ g_1897)))) * (~((~(((BHJHJjg_658_f4 & (l_1806 % (l_2054 ^ g_1058))) * (g_69 + BHJHJig_1897)))))))));
g_69 = (~(((((((~((~((l_2252 >> BHJHJhg_69))))) + BHJHJll_1806) % ((~(g_1897)) + (((~((~(BHJHJig_1897)))) * ((~(g_658.f4)) * (~((l_1927.f1 % BHJHJkl_2054))))) & (~(BHJHJjg_658_f4))))) ^ (~((~(g_969))))) ^ ((~((g_310 % (l_1806 | g_69)))) * (g_1058 + BHJHJgg_969))) & (~((~(l_2054)))))));
g_1897 = (~(((((~((~(BHJHJjg_658_f4)))) ^ l_2054) | (~(((~(g_69)) >> (~((~(((~((l_1806 * g_310))) || (g_969 || (~(BHJHJll_1806)))))))))))) ^ ((~((~(((~((g_1058 | ((g_658.f4 ^ l_2252) | BHJHJkl_2054)))) * (~(((~((~((~(l_1927.f1)))))) & ((BHJHJhg_69 + (~(BHJHJig_1897))) & (~(BHJHJgg_969))))))))))) << g_1897))));
g_658.f4 = (~((l_2252 ^ (~((~(((~((~((((((~(BHJHJig_1897)) & (g_1058 || l_2054)) % (~((~((BHJHJjg_658_f4 | BHJHJll_1806)))))) ^ (~((BHJHJkl_2054 % l_1927.f1)))) + (((~((~(BHJHJgg_969)))) % (~((~(g_69))))) | ((~(((~(g_969)) + g_658.f4))) % ((~(g_310)) ^ (l_1806 | BHJHJhg_69))))))))) % (~(g_1897))))))))));
l_2054 = (~((((~(g_1897)) * (((~((~((((~(BHJHJgg_969)) + (g_69 * (~(g_310)))) << (~((~(BHJHJhg_69))))))))) & (~((l_2054 | g_1058)))) % ((BHJHJjg_658_f4 * BHJHJll_1806) & (BHJHJig_1897 % ((~((l_2252 | BHJHJkl_2054))) * (~(g_969))))))) + ((l_1927.f1 | l_1806) | (~(g_658.f4))))));
l_1806 = (~(((~((BHJHJig_1897 | (~((BHJHJll_1806 | (~((~(BHJHJkl_2054)))))))))) | (~((((~((~(((g_658.f4 + (~(g_69))) * (g_969 * g_1058)))))) | ((~(BHJHJgg_969)) | l_1806)) % (~((l_1927.f1 * ((((~((~((g_310 ^ l_2054))))) >> BHJHJhg_69) | (g_1897 + BHJHJjg_658_f4)) + l_2252))))))))));
if(!((g_658.f4 && (g_310<=0)))){

if (l_2300)
                            break;

                    printf("g_969=%lld\n", (long long)g_969);
BHJHJkl_2054 = (~(((g_310 | ((~(((~((~((g_969 * ((~((BHJHJjg_658_f4 + BHJHJhg_69))) + (~((~(l_2054)))))))))) << ((~((l_1806 ^ g_1897))) ^ (g_1058 & (~(BHJHJig_1897))))))) * (~(((~(((~(BHJHJgg_969)) & g_69))) | BHJHJkl_2054))))) || (~((~((~((~(((BHJHJll_1806 >> l_2252) >> (g_658.f4 + l_1927.f1)))))))))))));
break;
}
if(((BHJHJgg_969<-18460) || ((BHJHJig_1897>3) || (!g_1058)))){
printf("g_69=%llu\n", (unsigned long long)g_69);
BHJHJll_1806 = (~((((~((l_2252 | ((g_1897 * l_1806) * ((l_1927.f1 + l_2054) ^ (g_310 >> (~(BHJHJig_1897)))))))) % (~(BHJHJjg_658_f4))) * (~(((((~(g_69)) % (BHJHJll_1806 || (g_969 << BHJHJkl_2054))) % ((g_658.f4 % BHJHJhg_69) + (~(BHJHJgg_969)))) & (~((~((~(g_1058))))))))))));
g_969 = (~(((~(((~(((g_69 % (~(g_1897))) % (~(l_2054))))) || (~((~((BHJHJkl_2054 << g_310)))))))) << ((~(((((~(((l_1806 >> l_2252) * BHJHJig_1897))) + (~(((~(l_1927.f1)) & g_969)))) ^ g_1058) * (g_658.f4 & BHJHJjg_658_f4)))) ^ (BHJHJhg_69 * ((~(BHJHJgg_969)) + (~((~((~(BHJHJll_1806))))))))))));
break;
}
if((g_1058 > l_2054)){

if (g_40[(g_900 + 1)])
                            continue;

                    printf("g_1897=%llu\n", (unsigned long long)g_1897);
continue;
}
if((l_1806>3)){

{
        transparent_crc(g_40[g_759], "g_40[g_759]", k);
        if (k) printf("index = [%d]\n", g_759);

    }

                    printf("g_658.f4=%llu\n", (unsigned long long)g_658.f4);
l_2054 = (~(((((((~(BHJHJjg_658_f4)) + (~(l_2054))) ^ (~((BHJHJgg_969 >> BHJHJll_1806)))) << (~((l_2252 & g_310)))) ^ ((~((~(g_969)))) % (~(((BHJHJhg_69 || (~(g_658.f4))) * (g_1897 & BHJHJig_1897)))))) | (~((~((((l_1806 & g_1058) + BHJHJkl_2054) * ((~(g_69)) % (~(l_1927.f1)))))))))));
l_1806 = (~(((~((BHJHJkl_2054 << l_1806))) >> (((~((~(((BHJHJgg_969 << g_1058) + (~((g_969 + g_310)))))))) * (~((~((((BHJHJll_1806 >> (BHJHJig_1897 + BHJHJhg_69)) >> (~((g_658.f4 << g_69)))) | ((~((l_2252 + g_1897))) | (~(BHJHJjg_658_f4))))))))) << ((~(l_2054)) & (~((~((~(l_1927.f1)))))))))));
}
if((g_1897 > g_658.f4)){

{
        int8_t l_2008[4];
        int8_t l_2041[2][7] = {{(-10L), (-10L), 0xB3L, (-10L), (-10L), 0xB3L, (-10L)}, {(-10L), (-10L), 0xB3L, (-10L), (-10L), 0xB3L, (-10L)}};
        int32_t l_2043 = 0x95BE3990L;
        int32_t l_2143 = 0xD0E5BDAFL;
        struct S0 l_2181[4] = {{-2L,-1738}, {-2L,-1738}, {-2L,-1738}, {-2L,-1738}};
        int32_t l_2252 = 0x018285E7L;
        int32_t l_2297 = (-1L);
        int16_t l_2300 = 0x3230L;
        uint32_t l_2314 = 0xF5DB9CA0L;
        uint32_t l_2365 = 0xEF3406B2L;
        int i, j;
        for (i = 0; i < 4; i++)
            l_2008[i] = (-10L);
        if (g_971)
        {
            int32_t l_2003 = 0x6FDBD163L;
            int32_t l_2011 = 0xDDDF1ED5L;
            int16_t l_2021 = (-5L);
            int16_t l_2179[3][9] = {{(-1L), 1L, (-1L), 1L, (-1L), 1L, (-1L), 1L, (-1L)}, {(-1L), 1L, (-1L), 1L, (-1L), 1L, (-1L), 1L, (-1L)}, {(-1L), 1L, (-1L), 1L, (-1L), 1L, (-1L), 1L, (-1L)}};
            int i, j;
            l_2011 = (((((((g_658.f3 = (safe_add_func_uint32_t_u_u((0x72D8A7C8L <= (safe_add_func_uint32_t_u_u(l_2055, ((safe_lshift_func_int16_t_s_s(l_2003, (safe_mod_func_uint32_t_u_u((0x23L <= ((((0xCA53L ^ (l_2055 ^ (safe_sub_func_int16_t_s_s(g_274.f1, l_2008[2])))) != (((((safe_mod_func_int8_t_s_s((l_2055 == l_2055), 0x3CL)) > 0x2966L) < 0x74L) & l_2055) & 0xFDL)) == l_2219) > l_2055)), l_2297)))) <= l_2003)))), 0x13FE7FA6L))) & 6UL) > 0L) && g_1204) ^ l_2055) > g_1895.f0) <= l_2055);
            if ((safe_add_func_int32_t_s_s(((248UL & (!(l_2011 = l_2055))) <= g_217[0].f0), ((!(((0x840FB4D7L > l_2016[2][1]) >= (((((l_2055 >= (((safe_sub_func_int32_t_s_s((safe_sub_func_int8_t_s_s(l_2021, (safe_sub_func_int32_t_s_s((safe_add_func_uint8_t_u_u(l_1966[2][2][0].f1, (l_1815[0] = (g_3662 | l_2055)))), l_2055)))), l_2055)) != 1UL) > l_2054)) | g_274.f2) == 8L) >= l_2055) == l_2055)) ^ l_2055)) < l_2143))))
            {
                int32_t l_2054 = 9L;
                int32_t l_2055 = (-1L);
                struct S0 l_2057 = {0xA871BB6AL,369};
                int32_t l_2090[10][10][2] = {{{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}};
                uint16_t l_2144 = 65532UL;
                int i, j, k;
                if (((g_656.f3 == ((safe_mod_func_uint16_t_u_u(0x1652L, (safe_lshift_func_uint8_t_u_s(((safe_mod_func_int32_t_s_s((4294967289UL < (((((g_656.f5 = ((safe_lshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u(((l_1815[1] = g_656.f2) ^ ((safe_rshift_func_int16_t_s_u(0x4C94L, (safe_sub_func_uint8_t_u_u((safe_unary_minus_func_int32_t_s(0L)), l_2041[0][1])))) & (l_2043 = (!0x760D3DE3L)))), (g_658.f3 = (safe_rshift_func_uint8_t_u_u(((l_2297 = (((safe_rshift_func_int16_t_s_u(((safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((g_3662 = (l_2054 = (safe_mod_func_uint32_t_u_u(l_2300, l_2055)))), l_2055)), l_2008[2])) == g_274.f1), l_2011)) < l_2055) != k)) > l_2055), l_2055))))), 5)) && l_2055)) ^ g_647) & l_2055) & l_2041[0][1]) < l_2021)), l_2055)) < 2L), 2)))) || l_2055)) >= 255UL))
                {
                    struct S0 l_2056 = {-1L,1122};
                    int32_t l_2072 = 0x4AFDEC30L;
                    l_2057 = l_2056;
                    if ((l_2057.f1 && (l_1966[2][2][0].f3 = (g_1056 = (safe_lshift_func_int8_t_s_u(((safe_sub_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((g_971 || (l_2297 < l_2008[2])), ((0x971619E2L | (((((safe_mod_func_int32_t_s_s(((safe_rshift_func_int16_t_s_u(3L, 14)) >= (1L >= (((g_658.f1 = (g_2667 = (((0xD1F5ED2CL >= (l_2072 = ((((l_2056.f1 = (safe_lshift_func_int16_t_s_s(((safe_mod_func_int32_t_s_s(l_2055, 0x0B3B51A7L)) >= l_2055), 12))) == l_2056.f0) <= l_2056.f0) <= 0UL))) ^ l_2055) & 7UL))) | 0xEDL) | 0UL))), l_2057.f0)) != 0xCD742DA1L) == l_2055) | l_2055) >= l_2003)) <= l_2055))), l_2057.f0)) & 0xF7L), 5))))))
                    {
                        int8_t l_2076[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_2076[i] = (-1L);
                        g_274.f1 = l_2219;
                        g_211 = 1L;
                        l_2043 = ((safe_sub_func_uint8_t_u_u(g_40[1], (+l_2076[1]))) || ((((((((g_274.f0 > (safe_lshift_func_uint8_t_u_u((safe_add_func_uint16_t_u_u((g_971 >= (safe_sub_func_uint32_t_u_u((((((-1L) && (safe_mod_func_uint32_t_u_u(((safe_mod_func_uint32_t_u_u((safe_add_func_uint32_t_u_u((l_2055 >= 0x42L), l_2144)), g_274.f1)) > l_2011), l_2055))) ^ 1L) >= l_2043) ^ l_2090[9][8][1]), 0UL))), 3UL)), 3))) && l_2055) == 0x53L) < l_2072) >= l_2008[2]) ^ g_656.f5) >= l_2055) < g_959));
                        g_274.f1 = ((l_2056.f0 <= (safe_mod_func_uint8_t_u_u(((((safe_add_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u(g_2098, g_274.f4)), ((((safe_lshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u(l_2055, ((safe_sub_func_int16_t_s_s((safe_rshift_func_int8_t_s_s(1L, ((safe_lshift_func_int16_t_s_u(0x9F7EL, (((safe_mod_func_uint8_t_u_u(((safe_mod_func_uint16_t_u_u((g_647 != ((l_2055 || (0x14L | l_2055)) ^ 0x02L)), 0xB743L)) >= (-2L)), g_3662)) & l_2055) & l_2055))) ^ g_656.f5))), 65530UL)) | l_2056.f0))), l_2300)) > l_2076[1]) == l_2076[1]) | l_2041[0][1]))) & l_2055) > l_2055) != l_2072), (-10L)))) | 0xD636L);
                    }
                    else
                    {
                        l_2011 = (0x1696D010L | ((l_2055 | 0xC4L) ^ g_274.f5));
                    }
                    l_2057.f1 = (safe_sub_func_uint32_t_u_u((safe_rshift_func_int16_t_s_s(((l_2055 = (((safe_mod_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_u(l_2055, (l_2043 = (+((l_2297 = g_2667) | 0xF178BAB5L))))), (safe_mod_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u(((safe_sub_func_uint32_t_u_u(5UL, l_2055)) < (l_2143 = (((((((g_647 = (((safe_rshift_func_int8_t_s_s(0x40L, l_2055)) != (safe_lshift_func_int8_t_s_u((safe_add_func_int16_t_s_s((safe_sub_func_int8_t_s_s(((((~(((safe_lshift_func_int16_t_s_s((((((((safe_lshift_func_uint8_t_u_s(0x3BL, (l_2041[0][1] | l_2055))) <= 0x1288868AL) || l_2057.f1) >= l_2055) || g_274.f0) | g_274.f0) || l_2056.f0), 3)) <= g_112) || 0xDC80L)) ^ l_2055) != l_2056.f1) != l_2055), l_2055)), l_2055)), 1))) ^ g_130.f1)) <= 0x75L) ^ l_2055) & g_112) != g_274.f0) ^ l_2090[9][8][1]) > l_2090[9][8][1]))), 1UL)) != g_3662), g_274.f1)), l_2055)))) || l_2055) | l_2144)) < 0xEFFAL), 4)), 4294967286UL));
                    for (g_2098 = 0; (g_2098 <= 1); g_2098 += 1)
                    {
                        int8_t l_2156 = 0x9EL;
                        l_2057.f1 = (j = (safe_mod_func_int32_t_s_s((l_2056.f1 = (0x854D7E61L > (0x9E0EL != (((safe_rshift_func_int16_t_s_u(1L, 4)) == 1L) || g_217[0].f1)))), ((-7L) ^ (+(l_2008[2] & (g_274.f0 || (((((safe_mod_func_uint16_t_u_u((((l_2156 = ((safe_add_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((g_112 = 0x61B0L), g_274.f5)) > g_274.f4), l_2072)) && 1UL)) || g_658.f2) | 1L), 0x671BL)) == 0x9BL) != l_2055) ^ l_2057.f0) >= 4294967295UL))))))));
                        l_2011 = 0x1E595EA1L;
                    }
                }
                else
                {
                    int32_t l_2157 = 6L;
                    struct S0 l_2166 = {0x1EE1138AL,-1097};
                    g_656.f3 = ((0x95FDL || l_2021) <= (((((((((g_2098 = l_2157) >= ((((l_2143 = ((g_274.f2 = l_2003) <= (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_s((g_1897 >= (safe_add_func_int16_t_s_s(l_2297, (0xA0L < (safe_add_func_uint16_t_u_u(((l_2003 | 0xA63F201AL) ^ 0xCFF3DD30L), l_2157)))))), g_3662)) == g_130.f0), l_2055)))) | 65535UL) & l_2157) | l_2055)) < l_1814) >= g_3662) > g_3662) > (-1L)) < l_2055) == g_274.f3) > 1L));
                    l_2057 = (g_1895 = l_2166);
                }
                for (l_2143 = 0; (l_2143 != 19); ++l_2143)
                {
                    if (l_2055)
                        break;
                }
            }
            else
            {
                int16_t l_2180 = (-2L);
                l_2180 = ((safe_lshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s((l_2055 <= ((g_217[0].f1 = g_3662) >= (safe_rshift_func_uint8_t_u_u((l_2055 != (safe_mod_func_uint8_t_u_u(((l_1815[1] = g_1897) != l_2055), ((safe_add_func_uint16_t_u_u((0x34D303D7L >= (4294967295UL | l_2179[0][1])), (g_211 = g_658.f5))) & l_1814)))), l_2055)))), 0x266FAC67L)), l_2055)) > g_1177[2][2][1]);
            }
            l_2057 = l_2181[0];
        }
        else
        {
            uint16_t l_2204[3];
            int32_t l_2205 = 0L;
            int32_t l_2206 = 0x0290BCA3L;
            uint32_t l_2230 = 0xBADDBEEAL;
            int16_t l_2251 = 0xD81BL;
            uint32_t l_2255 = 18446744073709551615UL;
            int16_t l_2273[10][10][2] = {{{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}};
            int i, j, k;
            for (i = 0; i < 3; i++)
                l_2204[i] = 0xAC95L;
            l_2206 = ((l_2205 = (safe_mod_func_uint32_t_u_u(((safe_sub_func_uint16_t_u_u((((((safe_add_func_int16_t_s_s(((safe_add_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(((safe_unary_minus_func_uint16_t_u(((g_3662 & (l_2055 || ((+l_2055) > ((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u((((g_112 = ((~((l_2143 = g_1568) == (safe_sub_func_uint8_t_u_u((g_3662 = (4294967290UL | 0xE4536538L)), ((((((g_274.f0 <= ((safe_rshift_func_int8_t_s_u(l_2143, 5)) ^ (l_2055 >= l_2041[1][2]))) | l_2055) < 0x329D2F20L) != g_274.f2) || 0xCB80L) < 0xB85FL))))) >= l_2011)) ^ 0x462CL) >= l_2041[0][5]), 15)) & 0x0A6EL), l_2055)) || 0x65L) ^ (-9L)) & g_274.f1)))) >= l_2055))) > 0x9AL), (-1L))), 1UL)) >= l_2204[1]), 0x93F9L)) > g_1177[1][3][1]) || 6UL) && l_2011) && 0x02L), 0x3375L)) & l_1966[2][2][0].f1), 0x5EE7F6D3L))) == (-6L));
            if (((l_2008[2] != ((l_2055 && (l_2055 >= 247UL)) != (safe_add_func_uint8_t_u_u(l_2055, ((safe_mod_func_uint32_t_u_u(2UL, g_658.f5)) < ((safe_unary_minus_func_uint16_t_u(((g_656.f4 < 3L) > g_740))) & g_656.f0)))))) || l_2206))
            {
                int8_t l_2213[1];
                struct S1 l_2254 = {35,6,-15233,-13,54,117};
                int i;
                for (i = 0; i < 1; i++)
                    l_2213[i] = 0xBCL;
                if ((l_2213[0] = 0x35AFDBFDL))
                {
                    return g_740;
                }
                else
                {
                    int8_t l_2217 = 0x52L;
                    int32_t l_2231 = 0L;
                    l_2231 = (((((safe_lshift_func_uint16_t_u_u((l_2217 >= g_274.f4), 2)) > ((safe_unary_minus_func_uint16_t_u(((g_971 >= (safe_lshift_func_int16_t_s_s(0xF5A6L, g_647))) && ((g_1039 = ((g_274.f3 = ((((l_2181[0].f1 = (safe_add_func_uint32_t_u_u((((l_2213[0] >= 8UL) | (safe_mod_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_sub_func_uint8_t_u_u(l_2055, l_2230)), l_2011)), l_2055))) >= l_2057.f0), l_2204[2]))) >= 6UL) != g_2667) && 1UL)) <= g_274.f0)) && g_2667)))) <= l_2055)) ^ 0x9652L) | l_2055) != l_2055);
                    if (((safe_mod_func_uint16_t_u_u(65535UL, g_647)) == (((((safe_mod_func_int16_t_s_s((l_2054 || (((l_2055 != (!l_2055)) && (safe_sub_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((g_112 = (0xFF59BC60L || l_2008[0])), ((((((l_2205 = (((safe_mod_func_uint8_t_u_u(((((safe_lshift_func_int8_t_s_u(((((safe_rshift_func_int16_t_s_u((l_2206 = (l_2213[0] != g_40[1])), l_2143)) < (-6L)) <= l_2251) | 0xDCL), l_2213[0])) ^ 0UL) || 6UL) ^ g_274.f2), g_274.f0)) & l_2055) != l_2055)) || l_2055) >= 0UL) > l_2252) | l_2204[2]) && 8UL))), g_656.f2))) <= l_2213[0])), l_2252)) == 1L) >= l_2055) && 0xE366L) < l_2055)))
                    {
                        l_2143 = 1L;
                    }
                    else
                    {
                        struct S1 l_2253[1][2] = {{{17,-17,4609,-5,113,280}, {17,-17,4609,-5,113,280}}};
                        int i, j;
                        g_658 = l_2253[0][1];
                        l_2253[0][1] = g_274;
                        l_2254 = l_2254;
                    }
                    l_2254.f2 = l_2057.f0;
                    return g_274.f4;
                }
            }
            else
            {
                struct S0 l_2276[7][6] = {{{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}, {{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}, {{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}, {{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}, {{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}, {{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}, {{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}};
                int i, j;
                l_2255 = (l_2143 = (g_112 && l_2206));
                for (g_1056 = 0; (g_1056 == 43); g_1056++)
                {
                    int32_t l_2274 = (-1L);
                    struct S0 l_2275 = {1L,-2015};
                    g_130.f1 = (0x7C67B9F8L && (safe_rshift_func_uint16_t_u_u((l_2206 = ((0L && (safe_lshift_func_uint8_t_u_u(l_2262[5][0][0], (g_1895.f1 = (g_1897 = 0x01L))))) < (safe_lshift_func_int8_t_s_s((safe_add_func_int32_t_s_s((((safe_rshift_func_uint16_t_u_s((l_2274 = ((safe_sub_func_uint32_t_u_u((((l_2055 & ((l_2016[1][5] || ((safe_rshift_func_int16_t_s_s(l_2055, 0)) <= 2UL)) == l_2273[9][1][0])) < l_2055) || (-10L)), g_274.f2)) & g_656.f1)), 6)) > 0xF8L) || 0xEF7F05C2L), 4294967286UL)), l_2055)))), g_217[0].f0)));
                    l_2276[6][3] = l_2275;
                    if (l_2143)
                        break;
                }
                l_2297 = (safe_lshift_func_int16_t_s_s(((((g_2667 = 0xAFL) != l_2055) & ((safe_unary_minus_func_uint32_t_u((((safe_lshift_func_uint16_t_u_s(l_2055, (((safe_lshift_func_int16_t_s_u(0xF8EAL, (safe_add_func_uint8_t_u_u(((~l_2057.f1) != ((g_274.f4 < ((((safe_mod_func_int8_t_s_s((!((g_274.f4 = (g_656.f5 = ((~(safe_add_func_uint8_t_u_u(((l_1966[2][2][0].f3 & (safe_add_func_uint16_t_u_u(((g_1895.f1 = (l_2055 > (safe_mod_func_uint32_t_u_u(((((l_2276[6][3].f1 = 0xC8L) >= l_2276[6][3].f0) && 0x688FL) || (-6L)), l_2057.f1)))) > 0x7CL), l_2055))) < l_2055), 0L))) == l_1786))) ^ l_2204[1])), l_2041[0][5])) <= l_2055) > l_2276[6][3].f0) <= l_2055)) == 0xD580L)), l_2055)))) ^ l_2008[2]) != l_2055))) == l_2276[6][3].f0) || l_2181[0].f1))) >= 0x60L)) != l_2055), 1));
                k = (l_2055 | (safe_rshift_func_int8_t_s_u((((l_2276[6][3].f1 = ((l_2008[0] & (g_3662 & (l_2300 || (safe_lshift_func_uint16_t_u_u(l_2041[0][1], 6))))) != (l_2055 & ((l_2206 = l_2011) >= l_2262[5][0][0])))) & (safe_unary_minus_func_uint32_t_u(7UL))) <= l_2055), 7)));
            }
            g_656 = l_1966[2][2][0];
            l_2143 = l_2055;
        }
        if ((safe_lshift_func_int8_t_s_s((safe_sub_func_int32_t_s_s(l_2055, l_2054)), ((l_2181[0].f1 = (safe_lshift_func_uint16_t_u_s(k, 5))) | ((safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_u(1UL, 3)), l_2314)) == l_2055)))))
        {
            uint32_t l_2328 = 18446744073709551608UL;
            int32_t l_2337[8] = {0x4753007EL, (-8L), 0x4753007EL, (-8L), 0x4753007EL, (-8L), 0x4753007EL, (-8L)};
            int32_t l_2339 = 1L;
            int32_t l_2340 = 9L;
            int i;
            l_2043 = (l_1815[0] < (g_1056 = (safe_lshift_func_uint16_t_u_u(l_2143, 1))));
            l_2340 = ((safe_mod_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_u(1UL, ((safe_add_func_uint8_t_u_u(l_2055, (l_2339 = ((safe_rshift_func_uint16_t_u_u(1UL, 2)) && ((safe_add_func_uint16_t_u_u(l_2055, (l_2328 = l_2219))) >= (safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u(g_40[1], (l_2219 = ((safe_add_func_int32_t_s_s(((l_2008[2] <= ((((safe_sub_func_uint8_t_u_u((l_2337[5] = (l_2314 < ((l_2300 && g_211) < l_2055))), 0x45L)) && 0UL) > l_2055) && g_1177[2][3][1])) < 65535UL), g_274.f5)) | l_1966[2][2][0].f5)))), g_3662))))))) || 0xF64DL))), 0xD969L)) & l_2055);
            for (l_2219 = 0; (l_2219 <= 1); l_2219 += 1)
            {
                struct S0 l_2361[5][1] = {{{-2L,8}}, {{-2L,8}}, {{-2L,8}}, {{-2L,8}}, {{-2L,8}}};
                struct S0 l_2362 = {0L,-781};
                int i, j;
                l_1815[l_2219] = l_1815[l_2219];
                for (g_647 = 0; (g_647 == (-14)); g_647 = safe_sub_func_uint16_t_u_u(g_647, 9))
                {
                    int8_t l_2345 = 0x8DL;
                    uint32_t l_2358 = 0x43698C13L;
                    l_2297 = (safe_rshift_func_uint8_t_u_s((l_2143 = l_2345), ((safe_add_func_int16_t_s_s(0x050DL, (0x9EL & ((0xC4L >= (safe_lshift_func_uint16_t_u_u(l_2055, l_2057.f1))) < (safe_rshift_func_int8_t_s_u((safe_rshift_func_int8_t_s_s(0xEEL, (safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_u(l_2358, 5)) < (safe_sub_func_uint32_t_u_u(l_2057.f0, l_2055))) > g_274.f5), l_2055)))), l_2297)))))) | l_2055)));
                    l_2340 = l_2337[5];
                }
                l_2362 = (l_2361[0][0] = (l_2057 = l_2057));
            }
            l_1815[0] = ((safe_unary_minus_func_uint16_t_u(g_130.f0)) > ((+l_2297) || l_2365));
        }
        else
        {
            uint32_t l_2366 = 0UL;
            l_2143 = l_2366;
            g_211 = (-1L);
        }
    }

                    printf("l_2054=%lld\n", (long long)l_2054);

{
                    return g_264;
                }

                    g_658.f4 = (~((BHJHJjg_658_f4 + ((((~((~((~(BHJHJhg_69)))))) & ((~((~(l_1806)))) & g_1897)) * (g_1058 & (BHJHJig_1897 >> g_310))) & ((((g_658.f4 >> g_69) ^ l_1927.f1) % (~((~((~(((BHJHJll_1806 << (~(BHJHJkl_2054))) << l_2054)))))))) << (~((~((BHJHJgg_969 || (g_969 << l_2252)))))))))));
BHJHJgg_969 = (~(((~((l_2252 << ((BHJHJjg_658_f4 >> g_658.f4) + BHJHJig_1897)))) * (~(((~(((~((~(((~((~(g_1897)))) >> (~(g_310))))))) | (~((g_969 || BHJHJhg_69)))))) * ((~((g_69 % BHJHJkl_2054))) << ((~((~(g_1058)))) * (((~(BHJHJgg_969)) * l_1927.f1) >> (~(((l_1806 + (~(BHJHJll_1806))) % l_2054))))))))))));
break;
}
if(((l_2054<0) || (!g_1897))){
printf("l_1806=%lld\n", (long long)l_1806);
continue;
}
}
g_969 = BHJHJgg_969;
g_69 = BHJHJhg_69;
g_1897 = BHJHJig_1897;
                                   if ((l_2300 > g_2.f1))
                    g_658.f4 = BHJHJjg_658_f4;
l_2054 = BHJHJkl_2054;
l_1806 = BHJHJll_1806;

                    break;}
                }
            }
            else
            {
                int16_t l_2180 = (-2L);

for (g_211 = 0; g_211 < 3; g_211++)
            g_40[g_211] = 0x935085E4L;

                    l_2180 = ((safe_lshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s((p_26 <= ((g_217[0].f1 = g_1178) >= (safe_rshift_func_uint8_t_u_u((p_26 != (safe_mod_func_uint8_t_u_u(((l_1815[1] = g_613) != p_26), ((safe_add_func_uint16_t_u_u((0x34D303D7L >= (4294967295UL | l_2179[0][1])), (l_1806 = l_1927.f5))) & l_1814)))), p_26)))), 0x266FAC67L)), p_26)) > g_1177[2][2][1]);
            }
            g_1895 = l_2181[0];
        }
        else
        {
            uint16_t l_2204[3];
            int32_t l_2205 = 0L;
            int32_t l_2206 = 0x0290BCA3L;
            uint32_t l_2230 = 0xBADDBEEAL;
            int16_t l_2251 = 0xD81BL;
            uint32_t l_2255 = 18446744073709551615UL;
            int16_t l_2273[10][10][2] = {{{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}, {{0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}, {0x27E5L, 0x2140L}}};
            int i, j, k;
            for (i = 0; i < 3; i++)
                l_2204[i] = 0xAC95L;

g_130.f0 += 1;


                    l_2206 = ((l_2205 = (safe_mod_func_uint32_t_u_u(((safe_sub_func_uint16_t_u_u((((((safe_add_func_int16_t_s_s(((safe_add_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(((safe_unary_minus_func_uint16_t_u(((g_264 & (p_26 || ((+p_26) > ((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u((((g_1106 = ((~((l_2143 = l_2199) == (safe_sub_func_uint8_t_u_u((g_1178 = (4294967290UL | 0xE4536538L)), ((((((g_658.f0 <= ((safe_rshift_func_int8_t_s_u(g_211, 5)) ^ (p_26 >= l_2041[1][2]))) | p_26) < 0x329D2F20L) != g_658.f2) || 0xCB80L) < 0xB85FL))))) >= g_310)) ^ 0x462CL) >= l_2041[0][5]), 15)) & 0x0A6EL), p_26)) || 0x65L) ^ (-9L)) & g_274.f1)))) >= p_26))) > 0x9AL), (-1L))), 1UL)) >= l_2204[1]), 0x93F9L)) > g_1177[1][3][1]) || 6UL) && g_310) && 0x02L), 0x3375L)) & l_1966[2][2][0].f1), 0x5EE7F6D3L))) == (-6L));

g_714 += 1;


                    if (((l_2008[2] != ((p_26 && (p_26 >= 247UL)) != (safe_add_func_uint8_t_u_u(p_26, ((safe_mod_func_uint32_t_u_u(2UL, l_1927.f5)) < ((safe_unary_minus_func_uint16_t_u(((g_656.f4 < 3L) > l_2212))) & g_656.f0)))))) || l_2206))
            {
                int8_t l_2213[1];
                struct S1 l_2254 = {35,6,-15233,-13,54,117};
                int i;
                for (i = 0; i < 1; i++)
                    l_2213[i] = 0xBCL;
                if ((l_2213[0] = 0x35AFDBFDL))
                {

{
                    int8_t l_2217 = 0x52L;
                    int32_t l_2231 = 0L;
                    l_2231 = (((((safe_lshift_func_uint16_t_u_u((l_2217 >= g_274.f4), 2)) > ((safe_unary_minus_func_uint16_t_u(((g_69 >= (safe_lshift_func_int16_t_s_s(0xF5A6L, g_647))) && ((l_2314 = ((g_274.f3 = ((((l_2181[0].f1 = (safe_add_func_uint32_t_u_u((((l_2213[0] >= 8UL) | (safe_mod_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_sub_func_uint8_t_u_u(l_2043, l_2314)), i)), l_2043))) >= g_1895.f0), l_2204[2]))) >= 6UL) != g_2667) && 1UL)) <= g_274.f0)) && g_2667)))) <= l_2043)) ^ 0x9652L) | l_2043) != l_2043);
                    if (((safe_mod_func_uint16_t_u_u(65535UL, i)) == (((((safe_mod_func_int16_t_s_s((g_211 || (((l_2043 != (!l_2043)) && (safe_sub_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((g_163 = (0xFF59BC60L || l_2008[0])), ((((((l_1816 = (((safe_mod_func_uint8_t_u_u(((((safe_lshift_func_int8_t_s_u(((((safe_rshift_func_int16_t_s_u((l_2206 = (l_2213[0] != g_40[1])), g_2569)) < (-6L)) <= l_2091) | 0xDCL), l_2213[0])) ^ 0UL) || 6UL) ^ g_658.f2), g_274.f0)) & l_2043) != l_2043)) || l_2043) >= 0UL) > l_2199) | l_2204[2]) && 8UL))), g_274.f2))) <= l_2213[0])), l_2199)) == 1L) >= l_2043) && 0xE366L) < l_2043)))
                    {
                        g_310 = 1L;
                    }
                    else
                    {
                        struct S1 l_2253[1][2] = {{{17,-17,4609,-5,113,280}, {17,-17,4609,-5,113,280}}};
                        int i, j;
                        g_274 = l_2253[0][1];
                        l_2253[0][1] = g_274;
                        g_658 = g_658;
                    }
                    g_658.f2 = g_130.f0;
                    return g_658.f4;
                }

                    return g_2214;
                }
                else
                {
                    int8_t l_2217 = 0x52L;
                    int32_t l_2231 = 0L;
                    l_2231 = (((((safe_lshift_func_uint16_t_u_u((l_2217 >= g_274.f4), 2)) > ((safe_unary_minus_func_uint16_t_u(((l_2219 >= (safe_lshift_func_int16_t_s_s(0xF5A6L, g_688))) && ((g_900 = ((g_2.f3 = ((((l_2181[0].f1 = (safe_add_func_uint32_t_u_u((((l_2213[0] >= 8UL) | (safe_mod_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_sub_func_uint8_t_u_u(p_26, l_2230)), g_310)), p_26))) >= g_1896.f0), l_2204[2]))) >= 6UL) != g_1184) && 1UL)) <= g_2.f0)) && g_1184)))) <= p_26)) ^ 0x9652L) | p_26) != p_26);
                    if (((safe_mod_func_uint16_t_u_u(65535UL, l_1816)) == (((((safe_mod_func_int16_t_s_s((g_759 || (((p_26 != (!p_26)) && (safe_sub_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((g_415 = (0xFF59BC60L || l_2008[0])), ((((((l_2205 = (((safe_mod_func_uint8_t_u_u(((((safe_lshift_func_int8_t_s_u(((((safe_rshift_func_int16_t_s_u((l_2206 = (l_2213[0] != g_40[1])), g_211)) < (-6L)) <= l_2251) | 0xDCL), l_2213[0])) ^ 0UL) || 6UL) ^ g_658.f2), g_2.f0)) & p_26) != p_26)) || p_26) >= 0UL) > l_2252) | l_2204[2]) && 8UL))), g_656.f2))) <= l_2213[0])), l_2252)) == 1L) >= p_26) && 0xE366L) < p_26)))
                    {

{
                l_1927.f3 = 0L;

for (l_2297 = 0; l_2297 < 4; l_2297++)
    {
        for (g_1058 = 0; g_1058 < 5; g_1058++)
        {
            for (l_2297 = 0; l_2297 < 2; l_2297++)
            {
                transparent_crc(g_1177[l_2297][g_1058][l_2297], "g_1177[l_2297][g_1058][l_2297]", l_2043);
                if (l_2043) printf("index = [%d][%d][%d]\n", l_2297, g_1058, l_2297);

            }
        }
    };


                    k = g_2.f5;
                k = (+g_656.f4);
            }

                    l_2143 = 1L;
                    }
                    else
                    {
                        struct S1 l_2253[1][2] = {{{17,-17,4609,-5,113,280}, {17,-17,4609,-5,113,280}}};
                        int i, j;
                        l_1927 = l_2253[0][1];
                        l_2253[0][1] = g_274;
                        l_2254 = l_2254;
                    }
                    l_2254.f2 = g_1895.f0;
                    return g_658.f4;
                }
            }
            else
            {
                struct S0 l_2276[7][6] = {{{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}, {{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}, {{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}, {{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}, {{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}, {{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}, {{0L,1782}, {0xBD74BE5BL,-624}, {-4L,-967}, {0x71CD3BAAL,-895}, {0xB526EB9EL,1977}, {-3L,1019}}};
                int i, j;
                l_2255 = (l_2143 = (g_1106 && l_2206));
                for (g_1056 = 0; (g_1056 == 43); g_1056++)
                {
                    int32_t l_2274 = (-1L);
                    struct S0 l_2275 = {1L,-2015};

{
                        l_2206 = 1L;
                    }

                    g_130.f1 = (0x7C67B9F8L && (safe_rshift_func_uint16_t_u_u((l_2206 = ((0L && (safe_lshift_func_uint8_t_u_u(l_2262[5][0][0], (l_1894.f1 = (g_613 = 0x01L))))) < (safe_lshift_func_int8_t_s_s((safe_add_func_int32_t_s_s((((safe_rshift_func_uint16_t_u_s((l_2274 = ((safe_sub_func_uint32_t_u_u((((p_26 & ((l_2016[1][5] || ((safe_rshift_func_int16_t_s_s(p_26, 0)) <= 2UL)) == l_2273[9][1][0])) < p_26) || (-10L)), g_658.f2)) & g_656.f1)), 6)) > 0xF8L) || 0xEF7F05C2L), 4294967286UL)), p_26)))), g_217[0].f0)));

{
                int32_t l_2054 = 9L;
                int32_t l_2055 = (-1L);
                struct S0 l_2057 = {0xA871BB6AL,369};
                int32_t l_2090[10][10][2] = {{{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}, {{(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}, {(-1L), 0xED845926L}}};
                uint16_t l_2144 = 65532UL;
                int i, j, k;
                if (((g_2.f3 == ((safe_mod_func_uint16_t_u_u(0x1652L, (safe_lshift_func_uint8_t_u_s(((safe_mod_func_int32_t_s_s((4294967289UL < (((((g_2.f5 = ((safe_lshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u(((l_1815[1] = g_2.f2) ^ ((safe_rshift_func_int16_t_s_u(0x4C94L, (safe_sub_func_uint8_t_u_u((safe_unary_minus_func_int32_t_s(0L)), l_2041[0][1])))) & (g_211 = (!0x760D3DE3L)))), (g_656.f3 = (safe_rshift_func_uint8_t_u_u(((g_2569 = (((safe_rshift_func_int16_t_s_u(((safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((g_1135 = (l_2054 = (safe_mod_func_uint32_t_u_u(g_959, g_875)))), g_875)), l_2008[2])) == g_2.f1), l_1816)) < g_875) != g_224)) > g_875), l_2055))))), 5)) && g_875)) ^ k) & g_875) & l_2041[0][1]) < g_2098)), l_2055)) < 2L), 2)))) || g_875)) >= 255UL))
                {
                    struct S0 l_2056 = {-1L,1122};
                    int32_t l_2072 = 0x4AFDEC30L;
                    l_2057 = l_2056;
                    if ((l_2057.f1 && (l_1966[2][2][0].f3 = (g_415 = (safe_lshift_func_int8_t_s_u(((safe_sub_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((l_1786 || (l_2206 < l_2008[2])), ((0x971619E2L | (((((safe_mod_func_int32_t_s_s(((safe_rshift_func_int16_t_s_u(3L, 14)) >= (1L >= (((g_656.f1 = (g_2667 = (((0xD1F5ED2CL >= (l_2072 = ((((l_2056.f1 = (safe_lshift_func_int16_t_s_s(((safe_mod_func_int32_t_s_s(g_875, 0x0B3B51A7L)) >= g_875), 12))) == l_2056.f0) <= l_2056.f0) <= 0UL))) ^ g_875) & 7UL))) | 0xEDL) | 0UL))), l_1894.f0)) != 0xCD742DA1L) == g_875) | g_875) >= l_2199)) <= g_875))), l_1894.f0)) & 0xF7L), 5))))))
                    {
                        int8_t l_2076[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_2076[i] = (-1L);

{
                    g_1896 = (g_217[0] = g_217[0]);
                }

                    g_2.f1 = l_2365;
                        l_2274 = 1L;

g_2667 += 1;


                    g_211 = ((safe_sub_func_uint8_t_u_u(g_40[1], (+l_2076[1]))) || ((((((((g_2.f0 > (safe_lshift_func_uint8_t_u_u((safe_add_func_uint16_t_u_u((l_2365 >= (safe_sub_func_uint32_t_u_u((((((-1L) && (safe_mod_func_uint32_t_u_u(((safe_mod_func_uint32_t_u_u((safe_add_func_uint32_t_u_u((g_875 >= 0x42L), g_415)), g_2.f1)) > l_1816), g_875))) ^ 1L) >= g_211) ^ l_2090[9][8][1]), 0UL))), 3UL)), 3))) && l_2055) == 0x53L) < l_2072) >= l_2008[2]) ^ g_2.f5) >= g_875) < l_2091));
                        g_2.f1 = ((l_2056.f0 <= (safe_mod_func_uint8_t_u_u(((((safe_add_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u(g_2098, g_2.f4)), ((((safe_lshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u(g_875, ((safe_sub_func_int16_t_s_s((safe_rshift_func_int8_t_s_s(1L, ((safe_lshift_func_int16_t_s_u(0x9F7EL, (((safe_mod_func_uint8_t_u_u(((safe_mod_func_uint16_t_u_u((k != ((g_875 || (0x14L | g_875)) ^ 0x02L)), 0xB743L)) >= (-2L)), g_1178)) & g_875) & g_875))) ^ g_2.f5))), 65530UL)) | l_2056.f0))), g_959)) > l_2076[1]) == l_2076[1]) | l_2041[0][1]))) & g_875) > g_875) != l_2072), (-10L)))) | 0xD636L);
                    }
                    else
                    {

p_26 += 1;


                    l_1816 = (0x1696D010L | ((g_875 | 0xC4L) ^ g_2.f5));
                    }
                    l_2057.f1 = (safe_sub_func_uint32_t_u_u((safe_rshift_func_int16_t_s_s(((l_2055 = (((safe_mod_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_u(g_875, (g_211 = (+((l_2206 = g_2667) | 0xF178BAB5L))))), (safe_mod_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u(((safe_sub_func_uint32_t_u_u(5UL, g_875)) < (l_2043 = (((((((k = (((safe_rshift_func_int8_t_s_s(0x40L, g_875)) != (safe_lshift_func_int8_t_s_u((safe_add_func_int16_t_s_s((safe_sub_func_int8_t_s_s(((((~(((safe_lshift_func_int16_t_s_s((((((((safe_lshift_func_uint8_t_u_s(0x3BL, (l_2041[0][1] | g_875))) <= 0x1288868AL) || l_2057.f1) >= g_875) || g_2.f0) | g_2.f0) || l_2056.f0), 3)) <= g_415) || 0xDC80L)) ^ g_875) != l_2056.f1) != g_875), g_875)), g_875)), 1))) ^ l_2275.f1)) <= 0x75L) ^ g_875) & g_415) != g_2.f0) ^ l_2090[9][8][1]) > l_2090[9][8][1]))), 1UL)) != g_1178), g_2.f1)), g_875)))) || g_875) | l_2144)) < 0xEFFAL), 4)), 4294967286UL));
                    for (l_2300 = 0; (l_2300 <= 1); l_2300 += 1)
                    {
                        int8_t l_2156 = 0x9EL;

{
                    j = l_2219;
                }

                    l_1894.f1 = (g_237 = (safe_mod_func_int32_t_s_s((l_2056.f1 = (0x854D7E61L > (0x9E0EL != (((safe_rshift_func_int16_t_s_u(1L, 4)) == 1L) || g_217[0].f1)))), ((-7L) ^ (+(l_2008[2] & (g_2.f0 || (((((safe_mod_func_uint16_t_u_u((((l_2156 = ((safe_add_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((g_415 = 0x61B0L), g_2.f5)) > g_2.f4), l_2072)) && 1UL)) || g_656.f2) | 1L), 0x671BL)) == 0x9BL) != g_875) ^ l_1894.f0) >= 4294967295UL))))))));
                        l_1816 = 0x1E595EA1L;
                    }
                }
                else
                {
                    int32_t l_2157 = 6L;
                    struct S0 l_2166 = {0x1EE1138AL,-1097};
                    g_2.f3 = ((0x95FDL || g_2098) <= (((((((((g_2098 = l_2157) >= ((((l_2043 = ((g_2.f2 = l_2199) <= (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_s((g_1178 >= (safe_add_func_int16_t_s_s(g_2569, (0xA0L < (safe_add_func_uint16_t_u_u(((l_2199 | 0xA63F201AL) ^ 0xCFF3DD30L), l_2157)))))), g_1178)) == l_2275.f0), g_875)))) | 65535UL) & l_2157) | g_875)) < g_3662) >= g_1178) > g_264) > (-1L)) < g_875) == g_2.f3) > 1L));
                    l_1894 = (l_1894 = l_2166);
                }
                for (g_759 = 0; (g_759 != 19); ++g_759)
                {
                    if (g_875)
                        break;
                }
            }


{
                g_2 = l_1927;
                i = (+0xFAL);
            }

                    l_2276[6][3] = l_2275;
                    if (g_211)
                        break;
                }
                l_2297 = (safe_lshift_func_int16_t_s_s(((((g_1184 = 0xAFL) != p_26) & ((safe_unary_minus_func_uint32_t_u((((safe_lshift_func_uint16_t_u_s(p_26, (((safe_lshift_func_int16_t_s_u(0xF8EAL, (safe_add_func_uint8_t_u_u(((~g_1895.f1) != ((g_658.f4 < ((((safe_mod_func_int8_t_s_s((!((g_274.f4 = (g_656.f5 = ((~(safe_add_func_uint8_t_u_u(((l_1966[2][2][0].f3 & (safe_add_func_uint16_t_u_u(((l_1894.f1 = (p_26 > (safe_mod_func_uint32_t_u_u(((((l_2276[6][3].f1 = 0xC8L) >= l_2276[6][3].f0) && 0x688FL) || (-6L)), g_1896.f1)))) > 0x7CL), p_26))) < p_26), 0L))) == g_740))) ^ l_2204[1])), l_2041[0][5])) <= p_26) > l_2276[6][3].f0) <= p_26)) == 0xD580L)), p_26)))) ^ l_2008[2]) != p_26))) == l_2276[6][3].f0) || l_2181[0].f1))) >= 0x60L)) != p_26), 1));
                g_875 = (p_26 | (safe_rshift_func_int8_t_s_u((((l_2276[6][3].f1 = ((l_2008[0] & (g_264 & (l_2300 || (safe_lshift_func_uint16_t_u_u(l_2041[0][1], 6))))) != (p_26 & ((l_2206 = g_75) >= l_2262[5][0][0])))) & (safe_unary_minus_func_uint32_t_u(7UL))) <= p_26), 7)));
            }

{
                        uint8_t l_2913 = 0x9DL;
                        l_1927.f2 = (safe_mod_func_uint32_t_u_u((g_130.f1 = ((((safe_sub_func_int8_t_s_s(g_714, g_112)) && (((safe_add_func_uint32_t_u_u((safe_mod_func_int16_t_s_s((l_1927.f3 = ((safe_mod_func_uint8_t_u_u(l_1927.f1, (g_2667 = (g_1184 && (safe_lshift_func_uint8_t_u_u((((((safe_add_func_int32_t_s_s((safe_add_func_uint32_t_u_u(g_1184, (g_75 = l_2314))), (safe_rshift_func_int16_t_s_u(((safe_add_func_int8_t_s_s((g_2667 = g_714), (l_1894.f1 = l_1927.f4))) ^ g_2667), 15)))) & g_971) & l_2314) != 0x1B3FL) == l_2230), g_1135)))))) > l_2219)), 1UL)), l_2206)) & 1L) | 0xFAF6L)) | g_658.f3) && g_130.f0)), 0xF5299BB1L));
                        g_658.f1 = ((safe_rshift_func_uint8_t_u_u((((((g_130.f1 = (g_1568 <= (safe_add_func_uint16_t_u_u((8UL < (0xBB9ADCDDL != (l_1927.f3 = (safe_add_func_uint32_t_u_u((l_1927.f1 = (((safe_sub_func_int8_t_s_s((l_2219 & (g_658.f2 = ((safe_sub_func_int8_t_s_s((((g_2667 && (safe_add_func_int8_t_s_s((g_1184 = (((g_130.f1 = (safe_lshift_func_int16_t_s_u(l_2913, 0))) <= (l_1927.f1 > k)) ^ ((l_2206 != 1UL) < g_1106))), 0x66L))) | l_2230) > 0xB95B8FDAL), g_130.f1)) > l_2913))), g_217[0].f1)) & l_2913) && g_658.f2)), 0x0D2C52FFL))))), g_658.f1)))) ^ l_2212) <= j) > l_2219) || l_2230), 4)) && g_656.f5);
                    }

                    g_656 = l_1966[2][2][0];
            l_2143 = p_26;
        }
        if ((safe_lshift_func_int8_t_s_s((safe_sub_func_int32_t_s_s(p_26, g_759)), ((l_2181[0].f1 = (safe_lshift_func_uint16_t_u_s(g_875, 5))) | ((safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_u(1UL, 3)), l_2314)) == p_26)))))
        {
            uint32_t l_2328 = 18446744073709551608UL;
            int32_t l_2337[8] = {0x4753007EL, (-8L), 0x4753007EL, (-8L), 0x4753007EL, (-8L), 0x4753007EL, (-8L)};
            int32_t l_2339 = 1L;
            int32_t l_2340 = 9L;
            int i;
            l_2043 = (l_1815[0] < (g_112 = (safe_lshift_func_uint16_t_u_u(g_2317, 1))));
            l_2340 = ((safe_mod_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_u(1UL, ((safe_add_func_uint8_t_u_u(p_26, (l_2339 = ((safe_rshift_func_uint16_t_u_u(1UL, 2)) && ((safe_add_func_uint16_t_u_u(p_26, (l_2328 = g_69))) >= (safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u(g_40[1], (l_2338 = ((safe_add_func_int32_t_s_s(((l_2008[2] <= ((((safe_sub_func_uint8_t_u_u((l_2337[5] = (l_2314 < ((l_2300 && l_1806) < p_26))), 0x45L)) && 0UL) > p_26) && g_1177[2][3][1])) < 65535UL), g_2.f5)) | l_1966[2][2][0].f5)))), g_1897))))))) || 0xF64DL))), 0xD969L)) & p_26);
                                                if (((l_1927.f3 > g_2098) || (l_1927.f3>1)) )
{

{
                        int8_t l_2156 = 0x9EL;
                        g_130.f1 = (l_2340 = (safe_mod_func_int32_t_s_s((g_1895.f1 = (0x854D7E61L > (0x9E0EL != (((safe_rshift_func_int16_t_s_u(1L, 4)) == 1L) || g_217[0].f1)))), ((-7L) ^ (+(l_2008[2] & (g_2.f0 || (((((safe_mod_func_uint16_t_u_u((((l_2156 = ((safe_add_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((g_1056 = 0x61B0L), g_658.f5)) > g_658.f4), p_26)) && 1UL)) || g_656.f2) | 1L), 0x671BL)) == 0x9BL) != p_26) ^ g_130.f0) >= 4294967295UL))))))));
                        g_3324 = 0x1E595EA1L;
                    }

}
                    for (l_2338 = 0; (l_2338 <= 1); l_2338 += 1)
            {
                struct S0 l_2361[5][1] = {{{-2L,8}}, {{-2L,8}}, {{-2L,8}}, {{-2L,8}}, {{-2L,8}}};
                struct S0 l_2362 = {0L,-781};
                int i, j;
                l_1815[l_2338] = l_1815[l_2338];
                for (l_1816 = 0; (l_1816 == (-14)); l_1816 = safe_sub_func_uint16_t_u_u(l_1816, 9))
                {
                    int8_t l_2345 = 0x8DL;
                    uint32_t l_2358 = 0x43698C13L;

l_2314 += 1;


                    l_2297 = (safe_rshift_func_uint8_t_u_s((l_2143 = l_2345), ((safe_add_func_int16_t_s_s(0x050DL, (0x9EL & ((0xC4L >= (safe_lshift_func_uint16_t_u_u(p_26, g_1896.f1))) < (safe_rshift_func_int8_t_s_u((safe_rshift_func_int8_t_s_s(0xEEL, (safe_rshift_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_u(l_2358, 5)) < (safe_sub_func_uint32_t_u_u(g_1895.f0, p_26))) > g_2.f5), p_26)))), g_647)))))) | p_26)));
                    l_2340 = l_2337[5];
                }
                l_2362 = (l_2361[0][0] = (g_1896 = g_1895));
            }
                                                if (((g_1135 < g_688) || (g_688 < g_274.f3)) )
{

{
            l_1894.f1 = ((g_224 && ((l_1927.f2 = 0xDDE33A30L) != ((g_224 <= (g_40[1] == (safe_add_func_uint16_t_u_u((g_415 = 3UL), g_63)))) != 8UL))) && g_224);
            l_2297 = l_1927.f4;
            for (l_1894.f0 = 1; (l_1894.f0 >= 0); l_1894.f0 -= 1)
            {
                g_656.f3 = (safe_sub_func_int16_t_s_s(0L, 0L));
                for (g_740 = 0; (g_740 <= 1); g_740 += 1)
                {
                    int i;
                    g_217[0] = g_217[g_1056];
                }
            }
        }

}
                    l_1815[0] = ((safe_unary_minus_func_uint16_t_u(g_130.f0)) > ((+l_2297) || l_2365));
        }
        else
        {
            uint32_t l_2366 = 0UL;

for (p_26 = 0; p_26 < 2; p_26++)
                            l_1815[p_26] = 0x75128752L;


{
                    l_2199 = g_971;
                }

                    l_2143 = l_2366;
            g_1568 = (-1L);
        }
    }
                                       if (((g_264 && g_959) && ((g_959<=1) && (g_658.f1 > g_2.f2))))
                    return l_1815[1];
}







static uint8_t func_29(uint16_t p_30, int32_t p_31)
{
    int8_t l_962 = 0xABL;
    int16_t l_970 = 0x8F91L;
    int32_t l_980 = 0x8720B0BDL;
    int32_t l_981 = (-1L);
    int32_t l_1008 = 1L;
    int32_t l_1009 = 0x93F14F40L;
    int16_t l_1038 = 3L;
    struct S0 l_1236[7] = {{-1L,-1417}, {-1L,-1417}, {1L,-744}, {-1L,-1417}, {-1L,-1417}, {1L,-744}, {-1L,-1417}};
    struct S0 l_1241 = {0x0D5FE7CFL,-1859};
    struct S1 l_1267 = {13,-16,-8596,67,96,108};
    struct S1 l_1288 = {203,14,12624,-59,172,180};
    int32_t l_1388 = (-7L);
    int16_t l_1497 = 0x25E7L;
    uint32_t l_1551 = 1UL;
    uint8_t l_1632[3][1];
    int32_t l_1648[9] = {1L, 1L, 0xB1D08922L, 1L, 1L, 0xB1D08922L, 1L, 1L, 0xB1D08922L};
    uint32_t l_1670 = 1UL;
    int i, j;
    for (i = 0; i < 3; i++)
    {
                                            while ((!g_1204) )
{

for (g_900 = 0; (g_900 < 15); g_900 = safe_add_func_int32_t_s_s(g_900, 9))
                {
                    if (g_274.f0)
                        break;
                };


}
                    for (j = 0; j < 1; j++)
            l_1632[i][j] = 0x40L;
    }
    g_310 = (safe_rshift_func_int16_t_s_u((l_962 & 255UL), 11));
                                       if (!((g_130.f1<0)))
                    for (l_962 = 0; (l_962 == 8); l_962 = safe_add_func_int8_t_s_s(l_962, 5))
    {
        struct S0 l_967[7][1] = {{{0xC345C254L,1172}}, {{0xC345C254L,1172}}, {{0xC345C254L,1172}}, {{0xC345C254L,1172}}, {{0xC345C254L,1172}}, {{0xC345C254L,1172}}, {{0xC345C254L,1172}}};
        uint32_t l_1022[8] = {0x66227D22L, 0x9C91C761L, 0x66227D22L, 0x9C91C761L, 0x66227D22L, 0x9C91C761L, 0x66227D22L, 0x9C91C761L};
        struct S1 l_1040[10] = {{215,-2,-6866,-87,50,45}, {37,-18,-15287,-51,173,161}, {215,-2,-6866,-87,50,45}, {37,-18,-15287,-51,173,161}, {215,-2,-6866,-87,50,45}, {37,-18,-15287,-51,173,161}, {215,-2,-6866,-87,50,45}, {37,-18,-15287,-51,173,161}, {215,-2,-6866,-87,50,45}, {37,-18,-15287,-51,173,161}};
        int8_t l_1155 = 0L;
        uint8_t l_1224 = 4UL;
        int32_t l_1389 = 0xB245BFFEL;
        int16_t l_1441 = (-9L);
        uint32_t l_1628 = 1UL;
        uint32_t l_1657 = 1UL;
        int i, j;
        for (g_237 = 0; (g_237 != (-26)); g_237 = safe_sub_func_int8_t_s_s(g_237, 5))
        {
            int32_t l_979 = 0x81F04563L;
            int32_t l_982 = 1L;
            g_130 = l_967[5][0];
            for (g_647 = 0; (g_647 <= 0); g_647 += 1)
            {
                uint32_t l_968[5];
                int i;
                for (i = 0; i < 5; i++)
                    l_968[i] = 0xC2F1D77AL;
                p_31 = (((g_969 = (l_968[1] = g_75)) <= ((l_962 | (((0xC17EL & 0x7FB4L) >= (g_264 = ((-4L) ^ l_970))) && ((((9UL ^ g_971) == 0UL) | 1UL) && 0x4B32EC67L))) != (-3L))) || 0xC0DA3BA4L);
                l_982 = ((p_30 & (((g_274.f2 < (p_31 = g_130.f0)) & (-4L)) < (((safe_add_func_int16_t_s_s(((l_967[5][0].f0 == ((l_967[5][0].f0 & g_112) < ((safe_add_func_uint32_t_u_u(((((g_969 = (l_967[5][0].f1 = (((((l_981 = (l_980 = ((((safe_unary_minus_func_uint32_t_u((((!0UL) && (+l_968[1])) <= p_30))) && 0xEE3AL) < l_968[1]) | l_979))) && 0x0FL) == g_959) < p_30) <= (-9L)))) < p_30) & l_968[1]) <= g_274.f4), g_274.f5)) <= 0UL))) | 0x32CAL), g_274.f2)) && 0x5F82F534L) ^ p_30))) == 0x8453L);
            }
            l_980 = g_2.f2;
        }
        if (l_962)
        {
            uint8_t l_986 = 0x60L;
            int32_t l_993 = 0x5E9B0965L;
            struct S0 l_997[1][9][9] = {{{{0x746E6793L,-541}, {-6L,1378}, {8L,551}, {1L,79}, {0xD373DBE7L,-1954}, {0x6B515B7AL,733}, {0L,483}, {0x8D88F804L,661}, {0L,483}}, {{0x746E6793L,-541}, {-6L,1378}, {8L,551}, {1L,79}, {0xD373DBE7L,-1954}, {0x6B515B7AL,733}, {0L,483}, {0x8D88F804L,661}, {0L,483}}, {{0x746E6793L,-541}, {-6L,1378}, {8L,551}, {1L,79}, {0xD373DBE7L,-1954}, {0x6B515B7AL,733}, {0L,483}, {0x8D88F804L,661}, {0L,483}}, {{0x746E6793L,-541}, {-6L,1378}, {8L,551}, {1L,79}, {0xD373DBE7L,-1954}, {0x6B515B7AL,733}, {0L,483}, {0x8D88F804L,661}, {0L,483}}, {{0x746E6793L,-541}, {-6L,1378}, {8L,551}, {1L,79}, {0xD373DBE7L,-1954}, {0x6B515B7AL,733}, {0L,483}, {0x8D88F804L,661}, {0L,483}}, {{0x746E6793L,-541}, {-6L,1378}, {8L,551}, {1L,79}, {0xD373DBE7L,-1954}, {0x6B515B7AL,733}, {0L,483}, {0x8D88F804L,661}, {0L,483}}, {{0x746E6793L,-541}, {-6L,1378}, {8L,551}, {1L,79}, {0xD373DBE7L,-1954}, {0x6B515B7AL,733}, {0L,483}, {0x8D88F804L,661}, {0L,483}}, {{0x746E6793L,-541}, {-6L,1378}, {8L,551}, {1L,79}, {0xD373DBE7L,-1954}, {0x6B515B7AL,733}, {0L,483}, {0x8D88F804L,661}, {0L,483}}, {{0x746E6793L,-541}, {-6L,1378}, {8L,551}, {1L,79}, {0xD373DBE7L,-1954}, {0x6B515B7AL,733}, {0L,483}, {0x8D88F804L,661}, {0L,483}}}};
            int32_t l_1015 = (-4L);
            uint8_t l_1071 = 0x81L;
            int32_t l_1222 = 1L;
            int i, j, k;
            if (((((+((g_658.f5 = g_658.f3) > g_656.f4)) | (l_986 = (safe_add_func_int8_t_s_s((0xE6079331L || (p_30 == (-6L))), 0x93L)))) >= ((safe_lshift_func_int16_t_s_s((safe_add_func_int8_t_s_s(l_980, (l_967[5][0].f0 > ((l_993 = (((((p_31 = ((safe_lshift_func_uint8_t_u_u(l_993, 6)) ^ 0x9B94L)) >= l_981) && 65535UL) == 9UL) == 0x6E9FD4C2L)) < l_967[5][0].f1)))), p_30)) >= 4UL)) && 65535UL))
            {
                struct S0 l_994 = {0xA29DD86AL,1920};
                struct S1 l_1118 = {228,18,-5328,-18,33,316};
                uint8_t l_1179[6][8][5] = {{{255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}}, {{255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}}, {{255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}}, {{255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}}, {{255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}}, {{255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}, {255UL, 1UL, 0x6BL, 0UL, 1UL}}};
                int i, j, k;
                l_994 = g_217[0];
                for (l_981 = 0; (l_981 >= (-20)); l_981 = safe_sub_func_int32_t_s_s(l_981, 5))
                {
                    int16_t l_1004 = 8L;
                    uint32_t l_1007 = 0x498B67A2L;
                    g_217[0] = (l_997[0][2][3] = g_217[0]);
                    for (g_130.f0 = (-15); (g_130.f0 > (-30)); g_130.f0 = safe_sub_func_int16_t_s_s(g_130.f0, 2))
                    {
                        l_993 = (((((safe_sub_func_uint8_t_u_u((safe_sub_func_int16_t_s_s((l_967[5][0].f1 = (l_1004 = g_613)), (l_980 = (g_2.f2 & 0x88L)))), (g_714 = (safe_mod_func_uint32_t_u_u((l_994.f1 = g_658.f3), (l_1007 = g_714)))))) & (l_1009 = (g_740 = ((l_1008 = 254UL) != (p_30 && 0x29L))))) ^ ((8UL >= 0xB263L) != 0x8FL)) != 2UL) || p_30);
                    }
                }
                for (l_981 = 0; (l_981 <= 16); l_981 = safe_add_func_uint32_t_u_u(l_981, 6))
                {
                    int32_t l_1029 = 0x50C32397L;
                    int32_t l_1055[6][10][4] = {{{2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}}, {{2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}}, {{2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}}, {{2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}}, {{2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}}, {{2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}, {2L, 1L, 0L, 0xCDB40901L}}};
                    int8_t l_1061[4][1][2] = {{{0L, 0L}}, {{0L, 0L}}, {{0L, 0L}}, {{0L, 0L}}};
                    uint32_t l_1117 = 0x4945F685L;
                    int i, j, k;
                    if (((((safe_sub_func_int16_t_s_s((safe_unary_minus_func_int16_t_s(((l_997[0][2][3].f0 || (l_1015 ^ (!((((((((safe_rshift_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_u((safe_unary_minus_func_int16_t_s((l_1022[7] != (safe_add_func_uint32_t_u_u((((((l_967[5][0].f1 = (((safe_sub_func_uint16_t_u_u(p_31, (safe_lshift_func_uint16_t_u_s(l_1029, 8)))) >= ((((g_163 = g_274.f1) > g_658.f0) >= (((((safe_rshift_func_int16_t_s_u((0xA606L ^ ((safe_sub_func_int32_t_s_s((safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((l_994.f0 == g_740), g_40[1])), p_30)), g_2.f3)) ^ p_30)), g_656.f1)) < g_658.f3) > l_994.f1) == 0x93L) || l_1029)) & 1L)) == l_1038)) || g_40[1]) | 1UL) == p_30) && 1L), 0xEC7C47AFL))))), 0)) & g_217[0].f1), g_130.f1)) >= p_30) < g_613) > g_656.f4) != p_31) <= p_31) != p_31) != g_174)))) ^ 4UL))), 0xD9CFL)) & 0x2AF8L) == 0x9AF7A210L) > 251UL))
                    {
                        p_31 = (g_1039 & g_63);
                        l_1040[3] = l_1040[2];
                        g_211 = ((safe_rshift_func_int8_t_s_s((p_31 >= ((((safe_sub_func_uint32_t_u_u((l_994.f0 != (((safe_add_func_uint16_t_u_u((((((l_986 < p_30) || g_274.f4) ^ (g_959 < (safe_mod_func_int8_t_s_s(((-7L) < (((g_1056 = (safe_lshift_func_uint16_t_u_s((((safe_lshift_func_int16_t_s_u((0x31L <= (g_264 = (safe_rshift_func_int16_t_s_u((g_969 = p_30), g_658.f1)))), 1)) && l_994.f0) < l_1055[3][4][3]), p_30))) > p_30) || g_211)), l_970)))) > p_30) > l_997[0][2][3].f0), l_986)) || g_2.f0) > g_40[2])), p_30)) ^ 252UL) <= 0xB240L) & 0x46AA526CL)), g_274.f5)) && 1UL);
                    }
                    else
                    {
                        uint32_t l_1076 = 0x54B8845CL;
                        l_1040[2].f3 = (((~(g_1058 || (((p_31 == l_1015) >= (safe_rshift_func_int8_t_s_u(l_1061[0][0][0], 4))) == ((((safe_add_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_s(((g_415 <= 0xA709L) > (safe_rshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u(((safe_unary_minus_func_uint8_t_u(g_875)) >= (l_1009 = (l_1071 > ((safe_lshift_func_int8_t_s_u((safe_mod_func_uint8_t_u_u(0x12L, l_994.f0)), l_981)) >= g_656.f4)))), p_30)) != 0xC16DL), 13))), l_994.f1)) >= 0xA88EL), l_1076)) && g_971) == p_30) & 0x6002896DL)))) == 0L) | 0xF2L);
                    }
                    if (p_31)
                    {
                        uint16_t l_1107[1];
                        int32_t l_1116 = 3L;
                        int i;
                        for (i = 0; i < 1; i++)
                            l_1107[i] = 1UL;
                        if (g_613)
                            break;
                        p_31 = ((((safe_sub_func_uint32_t_u_u((g_656.f3 == (g_971 | l_1040[2].f1)), g_688)) == (~((safe_sub_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_s((l_994.f1 = (l_997[0][2][3].f1 = ((((((safe_mod_func_int8_t_s_s((l_1029 = (((!(0xBBB1L <= 5UL)) > (safe_add_func_uint8_t_u_u((l_1015 = ((safe_rshift_func_int16_t_s_u((safe_mod_func_int16_t_s_s(((+0xEAF0BAEDL) != (safe_sub_func_uint16_t_u_u((safe_add_func_int8_t_s_s((g_1106 = (safe_rshift_func_uint16_t_u_s(((l_1055[3][4][1] = ((safe_add_func_uint16_t_u_u((((l_1008 = (safe_add_func_uint32_t_u_u((((g_2.f1 >= ((safe_sub_func_uint8_t_u_u(g_274.f5, 0xC6L)) <= (-3L))) == 0x29042436L) | (-10L)), l_1061[3][0][1]))) | p_30) < g_40[1]), l_994.f1)) ^ l_981)) | g_415), 7))), l_1061[0][0][0])), p_30))), g_217[0].f1)), 3)) > 255UL)), g_714))) ^ g_217[0].f1)), l_970)) ^ l_1107[0]) & g_163) | p_30) < g_211) >= g_658.f0))), 2)) || p_31), 255UL)) != 0xA4F1L))) | g_274.f5) ^ l_1022[7]);
                        p_31 = ((0x5E0CL | (safe_add_func_int16_t_s_s((((safe_add_func_int8_t_s_s((((l_1107[0] < l_1038) || (g_274.f3 < (l_994.f1 = (l_1107[0] & g_224)))) | (0x4117L == (safe_rshift_func_uint16_t_u_s((safe_sub_func_uint32_t_u_u(((p_31 >= (l_1116 = 1L)) >= p_30), l_1055[4][3][0])), 13)))), 0x12L)) <= g_740) < g_274.f5), p_31))) != p_30);
                    }
                    else
                    {
                        g_875 = l_1117;
                        g_656 = (l_1118 = (g_274 = g_2));
                        if (p_31)
                            {
{
                        return g_3484;
                    }

                    break;}
                        g_40[1] = (l_1055[1][3][1] | p_31);
                    }
                }
                for (l_1071 = 0; (l_1071 <= 2); l_1071 += 1)
                {
                    int i;
                    if (((254UL >= ((!((safe_sub_func_int32_t_s_s(((((+(safe_rshift_func_uint16_t_u_s((safe_sub_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u((g_40[l_1071] | ((g_1135 = (0x31ADFB97L && (safe_rshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((safe_lshift_func_uint8_t_u_s((g_971 | (((((g_237 != (p_30 == (l_994.f1 != 0xCBE74D71L))) >= (((0xA7L ^ p_31) < 8UL) != g_40[l_1071])) | (-10L)) ^ g_130.f1) == p_31)), 0)), 5)), 12)))) || 0L)), l_1040[2].f5)), g_217[0].f1)), 9))) ^ l_967[5][0].f0) | 2L) < 0xFD4EDBECL), g_900)) && 6L)) == 0x2BL)) >= p_30))
                    {
                        int32_t l_1158 = 0xE6F159A0L;
                        int i;
                        if (l_970)
                            break;
                        g_40[l_1071] = l_1015;
                        g_40[l_1071] = ((safe_rshift_func_uint8_t_u_u(g_40[l_1071], (safe_lshift_func_uint16_t_u_u((((safe_mul_func_int8_t_s_s(0x6FL, (((safe_add_func_uint32_t_u_u((l_997[0][2][3].f1 = ((safe_mod_func_uint16_t_u_u((~((safe_add_func_int16_t_s_s(((safe_add_func_int16_t_s_s(((l_1158 = (g_40[l_1071] < ((safe_lshift_func_int16_t_s_s((g_40[l_1071] | ((-1L) || (safe_sub_func_uint8_t_u_u(l_1155, ((safe_mod_func_int16_t_s_s(((l_967[5][0].f1 = p_31) | g_900), ((g_40[l_1071] > g_658.f2) && 0x86L))) > 7L))))), p_31)) > g_656.f4))) == 0x84F7L), 65535UL)) != (-9L)), g_264)) != p_31)), p_31)) != 0xBEL)), 0x3C0B77CDL)) | (-1L)) > 1L))) || p_31) < g_2.f2), 3)))) <= 0x3C8D9DC3L);
                        if (g_2.f3)
                            break;
                    }
                    else
                    {
                        int16_t l_1163 = 4L;

{
                    uint32_t l_670 = 1UL;
                    g_237 = (l_670 = g_112);
                    g_658.f3 = (safe_lshift_func_int8_t_s_u(g_1039, g_658.f4));
                }

                    g_656 = l_1040[2];
                        if (g_613)
                            break;
                        l_1015 = ((safe_mod_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s(l_1163, ((+(0x00A5L > (g_959 || ((g_1178 = (safe_lshift_func_uint16_t_u_s(l_1008, (g_40[l_1071] = ((safe_add_func_uint8_t_u_u((safe_add_func_uint32_t_u_u(((((((safe_rshift_func_int16_t_s_u(((safe_add_func_int32_t_s_s((safe_mod_func_uint8_t_u_u((l_1118.f1 = 0xFFL), (0xE1E8B9A3L & 0xEDE23F60L))), l_1040[2].f5)) ^ (0xE324F024L && g_274.f1)), 13)) & 1UL) || g_2.f3) <= 0L) <= g_1177[2][3][1]) | l_1040[2].f2), p_31)), g_875)) & 0xE3E2L))))) ^ 0x1CL)))) <= l_1163))), p_31)) < p_31);
                        return l_1179[2][5][1];
                    }
                    return p_31;
                }
            }
            else
            {
                int8_t l_1205[1];
                int32_t l_1223[10] = {4L, 0L, 4L, 0L, 4L, 0L, 4L, 0L, 4L, 0L};
                int i;
                for (i = 0; i < 1; i++)
                    l_1205[i] = 0x4EL;
                for (g_63 = 0; (g_63 <= 0); g_63 += 1)
                {
                    int32_t l_1207 = 0x288D8ED9L;
                    struct S0 l_1208 = {-2L,-1489};
                    g_130 = l_967[0][0];
                    if (l_980)
                    {
                        l_997[0][2][3].f1 = g_112;
                        p_31 = p_30;
                    }
                    else
                    {
                        uint16_t l_1206 = 65535UL;
                        int32_t l_1221[9] = {2L, 2L, 0x73A09F77L, 2L, 2L, 0x73A09F77L, 2L, 2L, 0x73A09F77L};
                        int i;
                        g_130 = g_217[0];
                        g_2.f3 = ((((safe_mod_func_int8_t_s_s((((((((0xE4A5L ^ (g_163 = (((l_1008 = (((l_967[5][0].f1 = (0x75L < g_971)) ^ ((g_1184 <= (((safe_add_func_int8_t_s_s((~(safe_add_func_int8_t_s_s((safe_mod_func_uint16_t_u_u((safe_add_func_int32_t_s_s((safe_sub_func_int8_t_s_s((((safe_add_func_int32_t_s_s(((g_1204 = (safe_add_func_uint32_t_u_u(((g_40[1] <= ((1UL | (safe_sub_func_uint32_t_u_u(0x2961B254L, (9UL > (safe_add_func_int8_t_s_s((p_31 <= 1UL), g_2.f0)))))) || p_30)) >= l_1071), p_30))) < g_40[1]), l_1205[0])) <= 0xC3F7L) || p_31), p_31)), p_30)), 0xEA1AL)), g_1178))), g_959)) == l_1206) != p_31)) >= l_1207)) > l_1009)) && p_31) & g_2.f5))) | 0x204AL) <= p_31) & 0x60L) | g_658.f2) < l_1009) || p_31), l_1071)) > l_980) <= 3L) <= l_1205[0]);
                        g_217[0] = l_1208;
                        l_1224 = ((safe_rshift_func_uint16_t_u_s((5L <= (((g_1106 = (g_2.f5 && (0xC266L == (l_1223[9] = (safe_lshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s(((safe_add_func_int32_t_s_s((((l_993 = l_981) <= (((safe_lshift_func_int16_t_s_s(l_997[0][2][3].f0, ((((l_1205[0] == ((safe_sub_func_int32_t_s_s(p_30, ((l_1221[5] = (l_1205[0] != (l_1040[2].f5 ^ l_1208.f1))) | 0L))) & 0xE6C5L)) >= g_1184) ^ g_658.f4) < p_31))) == 5UL) != l_1222)) == g_274.f2), g_2.f4)) ^ l_1207), p_31)), g_658.f2)))))) <= 5L) < g_656.f3)), p_31)) || g_2.f3);
                    }
                    for (g_1135 = 0; (g_1135 <= 0); g_1135 += 1)
                    {
                        int i, j, k;
                        l_967[5][0] = (l_997[g_1135][g_1135][(g_63 + 3)] = l_997[g_63][(g_1135 + 4)][(g_63 + 3)]);
                        l_967[5][0].f1 = (p_31 || (safe_lshift_func_uint16_t_u_u((l_1208.f1 = (safe_sub_func_int32_t_s_s((safe_add_func_int16_t_s_s(6L, ((((((0x1AE0A76DL & (250UL == ((safe_add_func_int32_t_s_s(g_274.f5, g_740)) != ((safe_sub_func_uint8_t_u_u(p_31, (~(0xF8C9AD46L | p_31)))) ^ p_30)))) < 1L) ^ g_2.f4) | l_993) < p_31) > g_688))), 0x9B172797L))), p_31)));
                        g_130 = l_1236[5];
                        if (p_30)
                            continue;
                    }
                }
            }
            for (l_1224 = 0; (l_1224 <= 6); l_1224++)
            {
                uint32_t l_1251 = 0UL;
                struct S0 l_1265 = {0x75B7B6B7L,-975};
                for (g_1184 = 0; (g_1184 >= (-12)); g_1184--)
                {
                    int32_t l_1246[9][1] = {{0x8F658985L}, {0x8F658985L}, {0x8F658985L}, {0x8F658985L}, {0x8F658985L}, {0x8F658985L}, {0x8F658985L}, {0x8F658985L}, {0x8F658985L}};
                    int32_t l_1249 = 0xE23D0DEFL;
                    int16_t l_1250 = 0x3575L;
                    int i, j;
                    l_1241 = (g_217[0] = l_967[5][0]);

{
                    g_274.f2 = 0x4B857C2BL;
                }

                    if (((safe_mod_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((((p_31 = (((p_31 | (l_1251 = ((-1L) < (((g_658.f3 ^ (-9L)) | l_997[0][2][3].f0) < ((l_1250 = ((g_969 = g_658.f2) > (((l_1246[5][0] > (safe_add_func_int8_t_s_s(0x5EL, ((l_1249 = g_415) & g_40[2])))) ^ g_130.f1) <= 0xCCF2L))) != g_658.f4))))) >= p_31) >= 1L)) >= 4294967294UL) && l_1241.f1), l_1241.f1)), g_1058)) == 0xC6L))
                    {
                        struct S0 l_1266 = {0x0AD0680CL,-1162};
                        p_31 = (safe_lshift_func_uint8_t_u_u(g_130.f1, 2));
                        g_656.f1 = ((safe_sub_func_uint16_t_u_u((safe_unary_minus_func_uint32_t_u(((safe_sub_func_int32_t_s_s(g_900, ((safe_mod_func_uint8_t_u_u((g_1178 = p_31), g_274.f3)) || ((safe_mod_func_int32_t_s_s(0L, p_31)) & g_658.f3)))) == ((p_30 != ((p_31 || (safe_add_func_uint32_t_u_u((p_30 || 0x3C37L), p_31))) == 1UL)) >= g_274.f2)))), (-5L))) == p_30);
                        l_1266 = l_1265;
                    }
                    else
                    {
                        if (l_1022[7])
                            {
for (l_1265.f0 = 1; (l_1265.f0 >= 0); l_1265.f0 -= 1)
            {
                l_1288.f3 = (safe_sub_func_int16_t_s_s(0L, 0L));
                for (g_1039 = 0; (g_1039 <= 1); g_1039 += 1)
                {
                    int i;
                    g_217[0] = g_217[g_112];
                }
            };


                    break;}
                        l_1267 = g_2;
                        return p_31;
                    }
                }
                for (g_1056 = 11; (g_1056 <= 6); g_1056--)
                {
                    int8_t l_1286 = 0xF7L;
                    int32_t l_1287 = 0x356F42BEL;
                    l_1009 = ((l_1265.f1 = (((safe_rshift_func_int16_t_s_s(g_658.f4, p_30)) > ((((g_310 != (3UL | ((safe_mod_func_uint8_t_u_u((l_997[0][2][3].f0 != ((g_688 = (((safe_sub_func_int32_t_s_s((((safe_rshift_func_uint16_t_u_u(0x7011L, 14)) == 0xB1F66F9FL) < ((safe_rshift_func_int16_t_s_s(((((((l_1286 = (((safe_unary_minus_func_uint32_t_u(g_75)) & (!(safe_add_func_uint16_t_u_u(((l_1040[2].f2 = (safe_mod_func_int32_t_s_s(0L, g_658.f3))) >= p_30), (-7L))))) && g_1106)) != g_759) || p_31) == 0x0973L) ^ 0UL) <= g_1135), 5)) && g_217[0].f0)), 0x894B29E4L)) >= l_1267.f1) || l_997[0][2][3].f0)) >= 0xBAB8CFF4L)), p_30)) < p_31))) >= 0x7E998754L) < g_112) || l_997[0][2][3].f0)) >= l_1287)) | (-1L));
                }
            }
            if (p_30)
                break;
            g_217[0] = g_130;
        }
        else
        {
            uint8_t l_1296[1];
            uint32_t l_1314 = 7UL;
            int32_t l_1342 = 0x839C20CEL;
            struct S1 l_1390 = {71,7,-7173,-18,36,332};
            int8_t l_1482 = (-9L);
            uint32_t l_1490 = 4UL;
            uint32_t l_1520 = 1UL;
            int i;
            for (i = 0; i < 1; i++)
                l_1296[i] = 4UL;
            for (l_1008 = 1; (l_1008 >= 0); l_1008 -= 1)
            {
                int32_t l_1321 = (-1L);
                struct S1 l_1393 = {199,19,-9742,62,113,165};
                struct S0 l_1414 = {0x083C0FACL,1679};
                struct S0 l_1415 = {1L,-1194};
                int i;
                g_656 = (l_1288 = (g_658 = (l_1040[8] = l_1267)));
                if ((0L & ((l_1022[(l_1008 + 2)] & 0x1B06L) <= ((g_264 != ((safe_rshift_func_int16_t_s_s((safe_mod_func_int32_t_s_s(l_1022[(l_1008 + 2)], (g_656.f5 = p_30))), 12)) >= l_1022[(l_1008 + 2)])) & 0UL))))
                {
                    int8_t l_1305 = 0x30L;
                    int32_t l_1308 = 0xFEE2516AL;
                    int32_t l_1309 = 0L;
                    l_1309 = (((g_959 = (~(l_980 = (((g_264 = 0xA9L) <= (l_981 & (l_1308 = ((p_30 = 0x8466L) && (g_969 = (((p_31 & (safe_lshift_func_int8_t_s_s(l_1296[0], ((safe_rshift_func_uint8_t_u_s(((safe_add_func_int32_t_s_s(((safe_rshift_func_uint16_t_u_s((p_30 | ((safe_sub_func_uint16_t_u_u((((l_1305 != (safe_sub_func_int32_t_s_s(l_1305, ((l_1267.f1 = 6L) && p_30)))) || p_30) != p_31), 0x7415L)) | p_31)), l_1305)) || g_759), p_30)) && p_30), l_1305)) < g_274.f5)))) || p_30) == l_1305)))))) ^ l_1296[0])))) == l_1288.f4) <= 0xC9B1L);
                    if (g_647)
                        break;
                    if (((safe_sub_func_int16_t_s_s(((l_1314 == p_30) ^ (0x35381D8FL > l_1309)), (g_658.f3 <= 4294967295UL))) >= (g_656.f3 = (safe_mod_func_int8_t_s_s((g_1184 = ((((p_30 | ((safe_mod_func_uint32_t_u_u((g_1039 = (l_1321 = (((p_30 & (safe_sub_func_uint32_t_u_u((g_658.f5 = (l_1288.f3 = 4294967291UL)), p_30))) < g_310) <= p_31))), p_30)) > g_2.f1)) == g_174) <= g_969) == l_1267.f2)), g_40[2])))))
                    {
                        l_1321 = g_2.f4;
                    }
                    else
                    {
                        if (p_31)
                            break;
                        g_130.f1 = ((g_1184 = (p_30 && (l_1296[0] <= (safe_sub_func_int32_t_s_s(((l_1342 = (safe_add_func_uint32_t_u_u(((l_967[5][0].f1 = (l_1224 || p_30)) >= ((((l_1040[2].f2 = ((safe_rshift_func_uint8_t_u_s(l_1305, (safe_rshift_func_int16_t_s_u(l_1296[0], 4)))) <= (safe_lshift_func_uint16_t_u_s((g_163 = ((safe_mod_func_int16_t_s_s((safe_add_func_int16_t_s_s(l_1296[0], (safe_sub_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(((safe_rshift_func_uint8_t_u_s(1UL, 6)) ^ g_656.f1), g_658.f1)), 0UL)))), g_1178)) >= 0xB8D619E5L)), l_1155)))) || l_1022[(l_1008 + 2)]) <= (-6L)) <= p_30)), p_31))) > (-5L)), g_174))))) ^ l_1040[2].f1);
                    }
                }
                else
                {
                    int32_t l_1361 = 0x0BCD998FL;
                    uint32_t l_1374[9][2][4] = {{{3UL, 0UL, 9UL, 0x4C8A649CL}, {3UL, 0UL, 9UL, 0x4C8A649CL}}, {{3UL, 0UL, 9UL, 0x4C8A649CL}, {3UL, 0UL, 9UL, 0x4C8A649CL}}, {{3UL, 0UL, 9UL, 0x4C8A649CL}, {3UL, 0UL, 9UL, 0x4C8A649CL}}, {{3UL, 0UL, 9UL, 0x4C8A649CL}, {3UL, 0UL, 9UL, 0x4C8A649CL}}, {{3UL, 0UL, 9UL, 0x4C8A649CL}, {3UL, 0UL, 9UL, 0x4C8A649CL}}, {{3UL, 0UL, 9UL, 0x4C8A649CL}, {3UL, 0UL, 9UL, 0x4C8A649CL}}, {{3UL, 0UL, 9UL, 0x4C8A649CL}, {3UL, 0UL, 9UL, 0x4C8A649CL}}, {{3UL, 0UL, 9UL, 0x4C8A649CL}, {3UL, 0UL, 9UL, 0x4C8A649CL}}, {{3UL, 0UL, 9UL, 0x4C8A649CL}, {3UL, 0UL, 9UL, 0x4C8A649CL}}};
                    int32_t l_1375 = 0x26D13B7EL;
                    int8_t l_1392 = 0xE8L;
                    int i, j, k;
                    for (g_971 = 0; (g_971 <= 1); g_971 += 1)
                    {
                        g_130.f1 = (safe_lshift_func_uint16_t_u_s(((-1L) != (~(p_30 ^ g_1178))), 4));
                    }
                    for (g_759 = 0; (g_759 <= 2); g_759 += 1)
                    {
                        int i;
                        g_40[g_759] = ((((safe_sub_func_int32_t_s_s(0xE6936FA6L, ((g_40[g_759] || (~(safe_sub_func_int32_t_s_s(((safe_sub_func_uint16_t_u_u((safe_sub_func_int32_t_s_s(((g_656.f4 < l_1342) >= ((safe_mod_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((((((safe_mod_func_int8_t_s_s((-5L), 252UL)) || l_962) > (0x7141L == ((((l_1361 = (g_714 != p_30)) <= 1L) <= l_1241.f1) < 0UL))) < l_1009) | 0xD768FEE2L), g_2.f5)), l_1022[(l_1008 + 2)])) == p_30)), g_40[g_759])), 0x6B53L)) == g_1177[2][3][1]), 0x37911921L)))) | 0xE4606A53L))) && 0L) < p_31) != p_30);
                        l_1321 = 1L;
                        p_31 = (safe_mod_func_uint8_t_u_u((((g_40[g_759] <= l_1040[2].f3) > (g_1184 = (!(l_1040[2].f1 & (((safe_sub_func_int8_t_s_s((safe_unary_minus_func_uint16_t_u(6UL)), 1L)) & (((((g_2.f3 > ((safe_add_func_int8_t_s_s(((l_1361 = (((((p_30 == p_30) ^ (safe_sub_func_uint8_t_u_u((((((l_1374[5][1][0] = (safe_sub_func_uint8_t_u_u(4UL, p_31))) == p_30) & 249UL) >= p_31) < l_1296[0]), 0x64L))) && g_2.f3) & g_274.f2) <= 0UL)) == g_40[g_759]), 247UL)) ^ p_30)) | l_1296[0]) && (-1L)) <= 0xC9E02FD5L) > p_31)) == l_1321))))) < l_1375), l_1009));
                        g_211 = ((safe_add_func_int16_t_s_s(((l_1321 = (g_40[g_759] = l_1288.f5)) < ((safe_sub_func_uint8_t_u_u((l_981 = (safe_add_func_int16_t_s_s((((safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u(l_1224, 5)), ((safe_add_func_uint8_t_u_u((l_1342 = g_237), 0L)) | (((((l_1361 = l_1388) | 9L) < l_1374[5][1][0]) | (p_31 ^ ((p_31 <= g_69) == g_740))) || 0x0DL)))) ^ l_1296[0]) && 0L), l_1236[5].f1))), 0xFDL)) && l_1389)), p_31)) < 0x83A9F797L);
                    }
                    l_1288 = (l_1390 = l_1040[8]);
                    if ((!(l_1321 = p_31)))
                    {
                        l_1267.f3 = (p_31 = 8L);
                        g_274.f2 = l_1392;
                        p_31 = 0x264ADA42L;
                        l_1393 = g_274;
                    }
                    else
                    {

{
        for (g_310 = 0; g_310 < 4; g_310++)
        {
            transparent_crc(g_3735[g_237][g_310], "g_3735[g_237][g_310]", k);
            if (k) printf("index = [%d][%d]\n", g_237, g_310);

        }
    }

                    g_1058 = ((0UL <= (((safe_sub_func_uint32_t_u_u((l_1390.f2 != ((safe_add_func_int32_t_s_s((+((((safe_sub_func_uint8_t_u_u(g_211, (safe_sub_func_int16_t_s_s(g_264, ((~((l_1393.f3 = g_658.f3) || (safe_rshift_func_int8_t_s_s((safe_add_func_int32_t_s_s(0L, ((((((safe_add_func_uint16_t_u_u((g_875 || (((safe_mod_func_uint32_t_u_u(0xA5882367L, p_31)) >= g_658.f2) || 1L)), l_1393.f1)) > l_1155) || (-6L)) ^ 0x2BFA1B9EL) < l_1288.f2) >= p_30))), l_967[5][0].f0)))) || g_2.f1))))) & 3UL) || 0xD75EL) ^ l_967[5][0].f0)), p_31)) || 1UL)), g_875)) != 0xECL) == 0x4FL)) >= 65530UL);
                        l_1267.f1 = (+(l_1393.f3 < (l_1390.f1 = ((l_1040[2].f2 = p_31) != (+g_714)))));

for (g_1184 = 0; (g_1184 <= 4); g_1184 += 1)
                    {
                        l_1009 = g_40[1];
                    };


                    p_31 = p_31;
                        l_1415 = (l_1414 = l_967[3][0]);
                    }
                }
                for (l_981 = 1; (l_981 >= 0); l_981 -= 1)
                {
                    struct S0 l_1416 = {-4L,1625};
                    if (g_656.f2)
                    {
                        return g_63;
                    }
                    else
                    {

{
            transparent_crc(g_3735[l_1008][g_1568], "g_3735[l_1008][g_1568]", p_31);
            if (p_31) printf("index = [%d][%d]\n", l_1008, g_1568);

        }

                    l_1416 = g_217[0];
                        if (p_30)
                            continue;
                    }
                }
                for (g_971 = 0; (g_971 <= 1); g_971 += 1)
                {
                    int16_t l_1440 = 0x3A3EL;
                    int32_t l_1442 = 1L;
                    uint32_t l_1463 = 7UL;
                    for (l_1388 = 1; (l_1388 >= 0); l_1388 -= 1)
                    {
                        int8_t l_1439 = 0xEDL;
                        l_1442 = ((safe_unary_minus_func_uint32_t_u((g_658.f4 = g_274.f1))) || (l_980 = ((safe_lshift_func_int8_t_s_u(p_30, 7)) && (0x95L || ((safe_add_func_int16_t_s_s((safe_add_func_int32_t_s_s(p_30, 0xA1395645L)), ((((g_1135 = (((safe_add_func_uint32_t_u_u((l_1241.f1 = (safe_sub_func_int32_t_s_s(0xF2B132C5L, ((((safe_add_func_int32_t_s_s(((((safe_mod_func_uint8_t_u_u(((l_1393.f1 = (l_1040[2].f3 = l_1040[2].f3)) ^ (((((((safe_add_func_uint8_t_u_u(((((safe_lshift_func_uint16_t_u_s((p_30 <= (safe_unary_minus_func_uint32_t_u(((((l_1288.f3 = (safe_mod_func_int16_t_s_s(((p_30 < p_30) ^ 4294967294UL), l_1439))) && l_1439) & g_237) > p_31)))), l_1390.f3)) | 0x97L) < l_1440) ^ p_30), l_1440)) != g_658.f5) & p_30) & 0x8A53L) <= 4294967295UL) != g_1178) & 4294967288UL)), 1L)) != g_688) < 5UL) < l_1236[5].f0), p_31)) ^ l_1441) == p_31) & g_969)))), l_1393.f2)) > g_759) ^ 0x6F85B003L)) < l_1440) & p_31) >= 1UL))) == g_274.f1)))));

{
                        struct S1 l_3108 = {238,8,4487,-23,133,252};
                        g_310 = g_2569;
                        g_274 = l_3108;
                        if (g_310)
                            continue;
                    }

                    p_31 = (safe_sub_func_int32_t_s_s(p_31, (((safe_add_func_uint16_t_u_u(((((l_1321 >= (((safe_lshift_func_int8_t_s_s((((l_967[5][0].f1 != ((l_1288.f5 ^ (p_30 > ((safe_unary_minus_func_int32_t_s(g_274.f3)) <= ((safe_lshift_func_int8_t_s_s((safe_mod_func_int32_t_s_s((safe_rshift_func_uint8_t_u_u(253UL, 6)), (+g_211))), 2)) <= (safe_lshift_func_int16_t_s_u((((safe_add_func_uint32_t_u_u((safe_add_func_int32_t_s_s(l_1393.f0, 4294967295UL)), g_1177[0][1][0])) >= l_1440) && g_274.f1), l_1439)))))) & l_1463)) > g_656.f0) || 2UL), g_2.f5)) < 4294967295UL) || g_217[0].f1)) | g_656.f1) != p_30) & l_1414.f0), p_30)) & g_1177[1][2][0]) || g_274.f1)));
                    }
                    l_1393.f1 = (((safe_rshift_func_uint8_t_u_u(0x23L, (0xAFL == (g_1135 = (l_1463 == l_1390.f0))))) >= l_1440) ^ ((~(safe_sub_func_int32_t_s_s((-10L), (l_1390.f1 = (3UL == (safe_lshift_func_int16_t_s_s((((+((p_31 < p_30) >= g_971)) > p_30) | 0L), 0))))))) == l_1224));
                    g_274.f2 = ((safe_rshift_func_uint16_t_u_s(5UL, ((safe_mod_func_int32_t_s_s(((((((((l_1482 = (g_656.f5 >= (p_31 > ((((safe_lshift_func_uint16_t_u_s(g_2.f3, l_1390.f4)) || (g_1204 = (g_759 != (0x96FE2CA9L & (safe_mod_func_int16_t_s_s((((((p_31 >= (p_31 != 1UL)) > p_30) ^ p_31) < p_30) == l_1442), g_875)))))) < 0xEB00F17EL) || l_1022[5])))) != l_1390.f5) ^ 0x02AB5DC0L) == l_1440) ^ 0x65BA3974L) > (-1L)) | 65531UL) == p_30), 0xD3F38E3FL)) == g_656.f1))) <= p_30);
                }
            }
            for (g_310 = 0; (g_310 > 21); ++g_310)
            {
                int8_t l_1504 = 1L;
                for (l_1224 = 0; (l_1224 <= 1); l_1224 += 1)
                {
                    int32_t l_1485 = 0L;
                    int i, j, k;
                    l_1485 = g_1177[(l_1224 + 1)][(l_1224 + 1)][l_1224];
                }
                for (l_970 = 0; (l_970 >= 13); l_970++)
                {
                    for (g_75 = 24; (g_75 <= 23); g_75 = safe_sub_func_int32_t_s_s(g_75, 5))
                    {
                        int8_t l_1498[9][6][4] = {{{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}};
                        int32_t l_1503 = 0x172577FDL;
                        int i, j, k;
                        l_1490 = 0L;
                        p_31 = ((safe_lshift_func_uint16_t_u_u((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u((l_1497 = (6UL ^ (g_613 && 6UL))), 0)) < ((-1L) | l_1498[5][2][2])), l_1498[3][2][2])) ^ ((safe_mod_func_int32_t_s_s(((safe_sub_func_uint32_t_u_u(p_31, (l_1503 = (((g_224 > 1UL) <= g_1204) & 255UL)))) != 1UL), 2L)) | g_415)) | g_658.f0), 12)) ^ l_1504);
                    }
                }
            }
            for (g_1039 = 0; (g_1039 < 52); g_1039 = safe_add_func_int16_t_s_s(g_1039, 3))
            {
                uint16_t l_1510 = 0xD21AL;
                int32_t l_1511 = 0L;
                g_759 = (((safe_mod_func_uint16_t_u_u((p_30 & (!(l_1511 = l_1510))), (g_130.f0 & (p_30 <= (safe_sub_func_int16_t_s_s(0x59A7L, (safe_sub_func_int32_t_s_s((((safe_add_func_int8_t_s_s(l_1288.f2, l_1040[2].f3)) ^ ((safe_sub_func_int32_t_s_s((p_30 ^ g_2.f0), 4294967295UL)) > 0x4431L)) == p_30), g_714)))))))) == 254UL) & p_31);
                p_31 = g_1039;
                if (p_31)
                    continue;
            }
            p_31 = (l_1520 = g_130.f1);
        }
        for (g_237 = (-5); (g_237 == 20); g_237++)
        {
            struct S1 l_1523 = {211,14,2313,14,18,4};
            l_1523 = l_1523;
            return g_224;
        }

{
            l_1241.f1 = ((g_211 && ((l_1288.f2 = 0xDDE33A30L) != ((g_211 <= (g_40[1] == (safe_add_func_uint16_t_u_u((p_30 = 3UL), l_1657)))) != 8UL))) && g_211);
            l_1388 = l_1288.f4;
            for (l_1241.f0 = 1; (l_1241.f0 >= 0); l_1241.f0 -= 1)
            {
                g_658.f3 = (safe_sub_func_int16_t_s_s(0L, 0L));
                for (g_69 = 0; (g_69 <= 1); g_69 += 1)
                {
                    int i;
                    g_217[0] = g_217[g_1056];
                }
            }
        }

                    for (g_1178 = 0; (g_1178 <= 13); ++g_1178)
        {
            int16_t l_1541 = 0L;
            int8_t l_1542 = (-6L);
            int32_t l_1625[7] = {8L, 8L, 0x33A538B1L, 8L, 8L, 0x33A538B1L, 8L};
            int32_t l_1627 = 0xDECF5C9FL;
            struct S0 l_1629 = {0xC1CEB23FL,-1828};
            struct S0 l_1630 = {0L,1784};
            struct S1 l_1652 = {97,13,-11501,78,84,178};
            uint32_t l_1688[6] = {0x6CDF6027L, 18446744073709551614UL, 0x6CDF6027L, 18446744073709551614UL, 0x6CDF6027L, 18446744073709551614UL};
            int i;
            p_31 = (3L || (safe_add_func_uint32_t_u_u((l_1008 = (safe_mod_func_int8_t_s_s(((safe_mod_func_uint8_t_u_u(l_1267.f3, 252UL)) > (((~0xBA5BF7E7L) > (g_1106 || (((((((((((safe_rshift_func_uint16_t_u_s((0x58L == (p_30 ^ (safe_add_func_uint32_t_u_u(p_30, (safe_mod_func_int8_t_s_s((0x53EFCD35L <= l_967[5][0].f1), 0xAAL)))))), p_30)) & l_1541) | p_31) == g_1177[3][4][1]) >= p_30) >= l_1542) | g_1178) <= 1L) <= l_1040[2].f3) | g_274.f5) ^ 1L))) < l_1542)), p_30))), p_31)));
            if (l_1542)
            {
                uint32_t l_1544 = 0xCCE97922L;
                int32_t l_1550 = 2L;
                struct S0 l_1631 = {0xC3612360L,-719};
                for (l_1241.f0 = 9; (l_1241.f0 >= 0); l_1241.f0 -= 1)
                {
                    uint16_t l_1558 = 65535UL;
                    int8_t l_1567 = (-1L);
                    int32_t l_1626 = 0xE0872107L;
                    p_31 = (g_274.f2 = ((+(((l_1544 && p_30) < ((-1L) || l_1040[2].f1)) > (safe_mod_func_int32_t_s_s((safe_lshift_func_int16_t_s_s((l_1550 = (safe_unary_minus_func_int32_t_s(l_1544))), l_1551)), ((safe_sub_func_int8_t_s_s((safe_mod_func_int8_t_s_s((0x21L < (safe_add_func_int8_t_s_s((65530UL != (g_112 == 0x09L)), l_1558))), p_30)), g_714)) & 0xB7EFL))))) != g_658.f4));
                    if (p_30)
                    {
                        uint32_t l_1594 = 0xD3100A1AL;
                        p_31 = (safe_lshift_func_int16_t_s_s((((((((0x1F94L || (safe_unary_minus_func_int8_t_s((+((((65526UL ^ (0x1666L != g_415)) > p_31) > (safe_sub_func_int8_t_s_s((((l_1040[2].f3 = (safe_mod_func_uint32_t_u_u((l_1567 = (g_274.f0 = g_656.f4)), ((l_1241.f0 > (l_1388 <= (p_30 != p_30))) & g_2.f1)))) <= 6UL) >= p_30), p_31))) >= p_31))))) && l_1542) ^ g_656.f1) | g_1568) == 0UL) || g_656.f2) & g_415), p_30));
                        l_1267.f3 = (safe_mod_func_int16_t_s_s((g_1204 = (safe_add_func_int8_t_s_s((!((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u(((((0x07568ADEL > p_30) >= (safe_add_func_int32_t_s_s((((((safe_mod_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s(g_658.f0, 1)), (safe_lshift_func_uint8_t_u_s(((((((safe_lshift_func_uint8_t_u_s((safe_mod_func_int32_t_s_s((2L ^ p_30), ((safe_sub_func_uint32_t_u_u(((safe_lshift_func_uint16_t_u_u(65528UL, l_1594)) || g_274.f0), (safe_rshift_func_int16_t_s_s(0L, 13)))) || (-1L)))), p_30)) != g_658.f2) && p_30) >= p_31) | p_30) && 1UL), 0)))) | p_30) < p_31) == g_274.f5) <= (-8L)), p_30))) ^ 0L) >= g_658.f3), l_1542)), 6)) >= p_31)), l_1594))), p_31));
                        l_1627 = (!((p_30 ^ (safe_add_func_uint16_t_u_u(65535UL, (safe_add_func_int16_t_s_s((l_1626 = (safe_mod_func_int8_t_s_s((safe_mod_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s(1UL, 1)), (safe_sub_func_uint8_t_u_u(((l_1625[6] = ((safe_mod_func_int8_t_s_s(g_1177[1][3][0], (((g_1106 >= (((g_969 == (safe_add_func_uint32_t_u_u((l_1241.f1 = ((safe_lshift_func_int8_t_s_s((g_1184 = ((((safe_add_func_int32_t_s_s((-6L), (safe_sub_func_uint32_t_u_u((l_967[5][0].f1 = ((safe_sub_func_uint8_t_u_u(0xCDL, (safe_lshift_func_int16_t_s_u(((~g_714) || 1L), 2)))) > l_1542)), l_1558)))) & 0L) < 0UL) | 0UL)), g_658.f4)) == 5UL)), l_1040[2].f4))) ^ 0x7026CC4CL) <= g_274.f0)) & p_31) && p_31))) <= l_1558)) >= 0x4EL), p_31)))), l_1551))), g_274.f1))))) >= p_31));
                    }
                    else
                    {
                        int i;
                        l_1040[l_1241.f0] = l_1040[l_1241.f0];
                        l_1628 = l_1224;
                        if (l_1040[l_1241.f0].f3)
                            break;
                        l_1631 = (g_217[0] = (l_1630 = (l_967[4][0] = (l_1629 = g_217[0]))));
                    }
                    for (l_1628 = 0; (l_1628 <= 1); l_1628 += 1)
                    {
                        int i, j, k;
                        l_1632[2][0] = (-1L);
                        return g_1177[l_1628][(l_1628 + 3)][l_1628];
                    }
                }
                p_31 = ((g_714 = ((safe_mod_func_int16_t_s_s(g_2.f1, 0xFFE6L)) != (safe_add_func_uint16_t_u_u((l_1648[8] = (((safe_rshift_func_int16_t_s_u((((((((l_967[5][0].f1 = (((((g_224 && (l_1627 = (p_31 || g_2.f2))) & ((((0x41L ^ ((safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u(g_217[0].f0, (safe_sub_func_int32_t_s_s(((safe_add_func_uint16_t_u_u(((+((p_30 ^ (-7L)) == p_31)) ^ 0x02L), g_1056)) | l_1541), 6L)))), 3)) && g_274.f0)) || 9L) <= g_656.f2) || p_30)) >= p_30) < g_658.f2) != p_30)) >= 0L) <= g_2.f2) > p_30) | p_30) <= l_1628) && g_656.f3), 10)) || p_30) != l_1241.f1)), p_31)))) ^ 0x80L);
            }
            else
            {
                struct S1 l_1651[10] = {{188,-8,-7050,-86,43,183}, {188,-8,-7050,-86,43,183}, {174,15,-9180,24,43,149}, {188,-8,-7050,-86,43,183}, {188,-8,-7050,-86,43,183}, {174,15,-9180,24,43,149}, {188,-8,-7050,-86,43,183}, {188,-8,-7050,-86,43,183}, {174,15,-9180,24,43,149}, {188,-8,-7050,-86,43,183}};
                int i;
                for (g_971 = 0; (g_971 < 15); g_971 = safe_add_func_int32_t_s_s(g_971, 9))
                {
                    if (g_658.f0)
                        break;
                }
                l_1652 = l_1651[1];

if (g_656.f3)
                            break;

                    g_217[0] = g_130;
            }
            if ((safe_sub_func_int32_t_s_s(((l_1040[2].f1 = ((safe_add_func_int32_t_s_s(l_1657, 0xB1D6B296L)) != (safe_mod_func_uint32_t_u_u(l_1627, (((l_967[5][0].f1 = (g_969 = (safe_add_func_int16_t_s_s((safe_sub_func_int16_t_s_s((l_1541 || (p_31 | (safe_sub_func_uint8_t_u_u((g_264 = (safe_mod_func_uint8_t_u_u((safe_sub_func_int16_t_s_s(0xAB35L, ((l_1040[2].f5 > l_1224) & (p_30 != l_1267.f4)))), 248UL))), (-1L))))), p_30)), l_1670)))) < (-8L)) ^ l_962))))) | l_1630.f1), 0xB5994657L)))
            {
                int16_t l_1681 = (-5L);
                struct S1 l_1689[6] = {{81,-9,2061,89,89,104}, {81,-9,2061,89,89,104}, {55,-12,-10511,-5,54,61}, {81,-9,2061,89,89,104}, {81,-9,2061,89,89,104}, {55,-12,-10511,-5,54,61}};
                int i;
                l_1629.f1 = (((((g_1177[2][3][1] | g_112) | (g_112 <= (p_31 = (p_30 | (l_981 & g_2.f2))))) != ((safe_lshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((safe_add_func_int32_t_s_s(l_1040[2].f4, (safe_sub_func_int16_t_s_s(l_1681, ((safe_mod_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_u((safe_sub_func_int32_t_s_s(p_30, p_30)), 0)) ^ 6L), p_30)) != l_1541))))), 6)), p_30)), g_2.f0)) | l_1688[3])) <= l_1681) < p_30);
                g_658 = (l_1288 = l_1689[0]);
            }
            else
            {
                int8_t l_1698[10][5][5] = {{{3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}}, {{3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}}, {{3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}}, {{3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}}, {{3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}}, {{3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}}, {{3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}}, {{3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}}, {{3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}}, {{3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}, {3L, 0x0FL, (-1L), 0L, 0L}}};
                int8_t l_1711 = 0L;
                int32_t l_1712 = 0x9464F9B3L;
                int i, j, k;
                if (p_30)
                {

g_959 += 1;


                    l_1652 = l_1040[4];
                    g_40[1] = (safe_rshift_func_int8_t_s_s(0xDAL, 7));
                }
                else
                {
                    g_656.f2 = p_31;
                    for (g_688 = 0; (g_688 == (-15)); --g_688)
                    {
                        int16_t l_1699 = (-1L);
                        g_647 = (((!g_1568) & l_1038) & ((safe_rshift_func_int8_t_s_u(((!((g_1184 > (((-9L) > ((p_30 = (g_658.f2 && (g_163 = 1UL))) <= l_1698[5][3][3])) || ((g_656.f5 || (0x6482L > 0x776EL)) <= (-8L)))) || 0x8DL)) == l_1699), p_31)) > p_31));
                    }
                }
                l_1712 = ((safe_mod_func_int32_t_s_s(p_31, (safe_rshift_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(((0L || 9L) || ((safe_unary_minus_func_uint16_t_u((g_274.f0 & l_1040[2].f1))) == ((safe_rshift_func_uint8_t_u_u(((p_30 = (((((((+(((((l_1698[6][3][2] && 0UL) != ((~g_658.f5) | g_900)) & l_1711) > g_900) == l_1648[3])) & l_1628) ^ p_31) || g_1177[2][3][1]) && l_1155) == 0x4C1BL) || 0xFA98L)) != (-1L)), 6)) & 0x05C9L))), g_658.f4)), 6)))) != l_1698[5][3][3]);
                g_130 = g_217[0];
                l_980 = (p_31 = ((((g_264 != (((((safe_unary_minus_func_int8_t_s(((safe_rshift_func_uint8_t_u_u((l_1712 = ((255UL <= (((p_31 ^ (l_1441 < (0x0EL <= ((safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((l_1698[5][2][3] && ((l_1711 && (l_1008 = ((p_30 = l_1632[2][0]) || (safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_s((((0UL < 255UL) <= p_30) == g_1106), 11)), g_224))))) ^ g_130.f1)), l_1629.f0)), g_130.f1)) != g_130.f1)))) | 2UL) > (-1L))) > p_31)), p_31)) > p_31))) <= 1L) > l_1040[2].f0) != l_1630.f0) ^ 0UL)) ^ p_31) <= l_1040[2].f4) > g_1039));
            }
        }
    }
    for (l_1551 = 20; (l_1551 >= 24); l_1551 = safe_add_func_int8_t_s_s(l_1551, 2))
    {
        int8_t l_1730 = 4L;
        int32_t l_1763 = 0x5453623BL;
        int32_t l_1765 = 0xFAA487A7L;
        int32_t l_1766 = (-8L);
        uint8_t l_1767 = 247UL;
        struct S0 l_1784[8][10] = {{{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}};
        int i, j;
        if ((l_1730 | 0L))
        {
            struct S0 l_1731 = {0x8B54C699L,-1628};
            int32_t l_1764 = 1L;
            p_31 = g_1177[2][3][1];
            g_217[0] = l_1731;
            g_1058 = (safe_rshift_func_uint8_t_u_s((safe_unary_minus_func_int32_t_s((safe_lshift_func_int8_t_s_s((-4L), (safe_rshift_func_uint16_t_u_s(((l_1288.f1 = ((safe_rshift_func_int16_t_s_s((safe_lshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(((0x96L && ((0xA7C3L < (safe_rshift_func_int16_t_s_u(((l_981 == (l_1766 = (safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s(0L, ((safe_sub_func_int16_t_s_s(p_31, (safe_sub_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_s((safe_sub_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(g_163, (l_1765 = ((l_1764 = ((l_1763 = ((l_1731.f1 = p_31) <= ((safe_add_func_uint16_t_u_u(l_1730, g_274.f3)) <= 0x3FE4L))) < l_980)) || l_1267.f0)))), l_1730)), 1)) ^ 5UL), 0x5CL)))) || l_1763))) || p_31), 0xB94CF378L)))) <= l_1267.f0), 3))) & 0L)) || g_1568), l_1670)), 3)), 4)) >= l_1288.f4)) <= g_112), l_1767)))))), l_1767));
        }
        else
        {
            uint32_t l_1783 = 0x80786831L;
            struct S0 l_1785 = {9L,-1659};
            g_40[1] = (((((safe_sub_func_uint8_t_u_u((l_1730 > (g_714 == (safe_mod_func_uint8_t_u_u(0x2DL, g_656.f0)))), p_30)) >= ((safe_add_func_int32_t_s_s(p_31, (safe_mod_func_int16_t_s_s(g_613, (safe_sub_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u(((((((l_1288.f1 = (-9L)) | ((((safe_add_func_uint16_t_u_u((((safe_unary_minus_func_int32_t_s(((p_31 <= p_30) & p_31))) >= 0x041CC1BDL) == p_30), p_31)) <= l_1783) > p_30) < 65535UL)) >= 0xA4DBL) != (-1L)) == 9UL) && g_658.f4), l_1767)) != g_310), p_30)))))) < l_1783)) > l_1765) >= p_30) >= g_130.f0);
            if (g_274.f1)
                continue;
            l_1785 = l_1784[1][9];
            g_130 = g_217[0];
        }
    }
    return g_656.f1;
}







static uint16_t func_33(uint32_t p_34, uint32_t p_35, int8_t p_36, uint16_t p_37)
{
    uint32_t l_58[6];
    int32_t l_62 = 0x59BBC08FL;
    int16_t l_122 = 0xCE6BL;
    struct S0 l_216[7][5][5] = {{{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}, {{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}, {{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}, {{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}, {{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}, {{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}, {{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}};
    struct S1 l_251 = {108,-3,10049,-17,167,287};
    int16_t l_320[7][1][7] = {{{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}, {{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}, {{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}, {{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}, {{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}, {{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}, {{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}};
    uint16_t l_321 = 0x7542L;
    uint32_t l_441 = 0x2AFAB89DL;
    int8_t l_450 = 0x00L;
    int32_t l_652 = 0x816C5560L;
    struct S1 l_674 = {101,-10,7274,-22,12,219};
    uint8_t l_784 = 0x23L;
    int8_t l_824 = 0L;
    uint16_t l_863 = 65535UL;
    int16_t l_884[5] = {0L, 8L, 0L, 8L, 0L};
    int i, j, k;
    for (i = 0; i < 6; i++)
        { while ((g_658.f4 < g_69) )
{


if ((safe_unary_minus_func_uint16_t_u(g_237)))
                {
                    uint32_t l_346 = 0x90B89719L;
                    int32_t l_348[9];
                    int i;
                    for (i = 0; i < 9; i++)
                        l_348[i] = 1L;
                    l_348[0] = (g_63 == (g_40[1] = ((safe_rshift_func_int8_t_s_s(((safe_sub_func_int32_t_s_s(g_959, g_759)) | ((g_63 && ((safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_s(g_112, 1)), (safe_rshift_func_int16_t_s_u(g_112, g_2.f5)))) | (g_1039 = 0UL))) != ((safe_lshift_func_uint8_t_u_u((+(g_237 = (safe_rshift_func_int16_t_s_s(((l_346 <= g_217[0].f0) ^ g_2.f2), 1)))), g_2.f3)) ^ p_34))), 0)) == p_34)));
                    for (g_211 = 0; (g_211 < 13); g_211 = safe_add_func_int16_t_s_s(g_211, 2))
                    {
                        int8_t l_371 = (-2L);
                        g_274 = g_2;
                        l_216[5][2][4].f1 = (safe_sub_func_uint8_t_u_u(((((p_34 < (safe_mod_func_uint8_t_u_u((p_34 < (safe_sub_func_int32_t_s_s(((((safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((((((g_274.f1 = (p_36 = (safe_mod_func_int8_t_s_s(((l_674.f3 && (safe_sub_func_uint32_t_u_u((((g_75 = (safe_sub_func_int32_t_s_s((+g_211), g_63))) <= (l_674.f2 = (safe_unary_minus_func_uint32_t_u(4294967287UL)))) < (l_320[4][0][2] > g_2.f0)), (g_3324 | g_264)))) >= g_959), l_371)))) < l_652) < g_112) || l_371) && g_2.f4), 0x1DCE6AB1L)), l_863)) <= 4294967287UL) & 0UL) & 2UL), g_40[2]))), g_875))) && 0x3786L) >= 0x41L) & 1L), g_112));
                    }
                    for (l_863 = 2; (l_863 == 45); l_863++)
                    {
                        if (p_34)
                            break;
                    }
                    if (g_112)
                        continue;
                }
                else
                {
                    uint16_t l_385 = 0x4A82L;
                    uint32_t l_416 = 0xF4081C80L;
                    int32_t l_476 = 0xAC569D01L;
                    int32_t l_479 = 0x0FFF34F5L;
                    g_211 = ((+(((~(safe_add_func_uint32_t_u_u((safe_add_func_int32_t_s_s(((safe_lshift_func_int16_t_s_u(((((g_1039 >= (((((((safe_add_func_int8_t_s_s(0xB2L, l_385)) <= (l_674.f1 = ((g_2.f4 == (safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(((((l_216[5][2][4].f0 >= (safe_lshift_func_uint16_t_u_s(0x8D89L, 13))) > (safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(((safe_add_func_uint8_t_u_u((safe_unary_minus_func_uint8_t_u((safe_lshift_func_int16_t_s_s((safe_sub_func_int16_t_s_s(g_75, (safe_rshift_func_int8_t_s_u(l_863, ((l_385 < 0x54L) >= 0x2881L))))), l_58[4])))), l_58[3])) == 0xC3B5L), g_1106)), 0))) <= p_36) > g_75), p_36)) == g_274.f3), g_1039))) == g_1896.f1))) == 65533UL) == 9UL) > g_2.f0) >= p_34) || p_34)) | 0xE150EA9AL) || 7UL) > p_34), 4)) ^ g_959), g_1896.f0)), l_320[4][0][2]))) && g_2.f5) & g_112)) || 0xC4L);
                    if ((g_2.f1 >= (safe_mod_func_uint32_t_u_u(((safe_sub_func_uint32_t_u_u((0x2BL & (g_1896.f0 || (((safe_add_func_int16_t_s_s((g_2.f3 = ((safe_add_func_int16_t_s_s(g_112, (p_36 && (safe_mod_func_uint16_t_u_u(0xE618L, (g_163 = (246UL & ((g_211 ^ (p_36 = (-3L))) >= 0x59301DB9L)))))))) < p_34)), p_34)) | 0x48L) == l_416))), 0x94C6A02EL)) && g_2.f2), g_1106))))
                    {
                        uint32_t l_440[4];
                        int i;
                        for (i = 0; i < 4; i++)
                            l_440[i] = 6UL;
                        g_211 = (safe_rshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u((((((g_264 = g_2.f5) || (~(0xF79201D8L <= (safe_mod_func_uint16_t_u_u((safe_sub_func_int32_t_s_s(l_863, (+((p_34 = 1UL) && (safe_mod_func_int8_t_s_s(((!g_2.f4) <= (g_1039 = (safe_mod_func_uint32_t_u_u(((safe_mod_func_int16_t_s_s(((safe_lshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(g_1896.f0, (((1L >= l_440[0]) && (((((p_36 & g_1039) < g_112) <= l_440[2]) || l_674.f3) != 0xF1L)) != g_2.f2))), 5)) != p_34), g_237)) == (-7L)), g_2.f5)))), g_1039)))))), p_34))))) ^ 0x25L) >= g_2.f4) > g_2.f3), 5)), 0UL)), 4));
                        return g_40[1];
                    }
                    else
                    {
                        int32_t l_478 = 0xCB2505EBL;
                        g_2.f3 = p_36;
                        g_237 = (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s(((0x6C3B8124L >= (!g_2317)) || (((0xB1F7L == (g_1184 = g_1039)) <= (safe_sub_func_int32_t_s_s(p_34, (p_34 ^ ((l_450 | p_34) ^ (safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(0xE6L, 0)), p_34))))))) == g_211)), 0xEBL)), 12))));
                        l_674.f1 = ((safe_rshift_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(0x41L, (safe_lshift_func_int16_t_s_u((p_34 == ((((((safe_sub_func_int32_t_s_s((((safe_sub_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((((l_479 = ((safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s(((g_237 = (safe_lshift_func_int16_t_s_u(((g_2.f4 || (1L & (l_476 = p_34))) < g_2.f4), (((g_163 = (p_36 >= (~(0xE59C2AA1L != 0xF9BF29F1L)))) || 1UL) > l_478)))) & g_2.f1), g_2.f1)), 0xF1F6L)) <= 0x6524L)) != g_112) < (-9L)), g_112)), l_478)) > 0x43L) | l_416), p_34)) <= g_274.f5) >= p_34) | g_63) || p_34) & l_450)), l_674.f3)))), g_1039)) == p_36);
                        l_479 = (g_274.f3 = (safe_rshift_func_int8_t_s_u(((safe_lshift_func_int16_t_s_s(g_112, (safe_lshift_func_int16_t_s_u((((!(-9L)) == g_217[0].f0) >= (l_476 = p_36)), 11)))) == 65535UL), 4)));
                    }
                };


                    for (i = 0; i < 1; i++)
    {

if (g_163)
                break;

                    transparent_crc(g_217[i].f0, "g_217[i].f0", g_211);

for (l_824 = 22; (l_824 != (-10)); l_824 = safe_sub_func_int8_t_s_s(l_824, 7))
            {
                uint32_t l_175 = 4294967295UL;
                int32_t l_178 = (-3L);
                uint16_t l_212[10] = {65535UL, 65535UL, 0xC7ADL, 65535UL, 65535UL, 0xC7ADL, 65535UL, 65535UL, 0xC7ADL, 65535UL};
                int i;
                if (g_1896.f0)
                    break;
                if (g_656.f2)
                    break;
                if (g_112)
                    continue;
                if (g_2098)
                {
                    uint32_t l_156[9] = {0x0D3AC039L, 0x0D3AC039L, 6UL, 0x0D3AC039L, 0x0D3AC039L, 6UL, 0x0D3AC039L, 0x0D3AC039L, 6UL};
                    int i;
                    for (g_415 = (-12); (g_415 != 28); g_415++)
                    {
                        int16_t l_161 = (-3L);
                        int32_t l_162[7][4] = {{0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}};
                        int i, j;
                        l_162[2][2] = (safe_sub_func_int32_t_s_s((g_1896.f0 <= (g_1896.f1 = ((g_759 = ((g_900 >= ((safe_sub_func_int16_t_s_s(((l_156[3] < (0xD5L == (((g_900 < (safe_sub_func_uint8_t_u_u((l_161 = ((g_1058 = ((g_647 == 1UL) != j)) && (((safe_sub_func_uint16_t_u_u(0xF7D0L, g_656.f3)) ^ l_58[4]) == g_63))), l_162[2][2]))) == 0UL) == l_162[2][2]))) > 0x97L), 4UL)) <= l_321)) < g_112)) >= j))), g_900));
                        g_656.f3 = ((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u((g_656.f0 == (safe_sub_func_int8_t_s_s(((l_321 = g_40[2]) != 0x2DD9L), (safe_sub_func_uint16_t_u_u((l_156[3] ^ (safe_lshift_func_int16_t_s_u((g_900 = (8UL > (2UL == (0x66ACL ^ (((-1L) < l_156[3]) < g_647))))), l_175))), 1L))))), 7)), l_156[5])) == 0x0657D6C4L);
                    }
                }
                else
                {
                    struct S0 l_180[1][5][8] = {{{{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}}};
                    int16_t l_213 = (-1L);
                    int i, j, k;
                    for (g_2098 = (-18); (g_2098 != (-3)); g_2098++)
                    {
                        int32_t l_179 = (-1L);
                        l_179 = (l_178 = g_900);
                        if (l_179)
                            continue;
                        g_1896 = (l_180[0][2][4] = g_1896);
                    }
                    g_656.f2 = (safe_add_func_uint32_t_u_u(((((g_900 = j) <= ((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u(g_1896.f0, g_656.f2)), g_656.f2)) ^ (safe_add_func_int16_t_s_s((((safe_add_func_int32_t_s_s(((safe_mod_func_uint16_t_u_u((safe_mod_func_int8_t_s_s((safe_unary_minus_func_int8_t_s((((((safe_add_func_uint8_t_u_u(g_900, g_656.f3)) || (safe_sub_func_int16_t_s_s((l_212[4] = (safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s((((((g_310 = (j = ((safe_lshift_func_uint16_t_u_s(((0x96262B8EL == g_112) > ((safe_mod_func_int32_t_s_s((g_647 < g_1058), g_112)) ^ g_112)), 1)) >= g_647))) | g_415) & l_824) && l_321) >= 0x7B1EL), g_112)), g_2098)), g_63))), g_900))) | l_213) & 255UL) <= g_656.f3))), 253UL)), g_647)) & 4L), 4UL)) && g_647) || 0x7BL), l_180[0][2][4].f1)))) >= l_824) || g_112), (-6L)));
                    g_40[1] = l_441;
                }
            };


                    transparent_crc(g_217[i].f1, "g_217[i].f1", g_211);
        if (g_211) {
if (g_1039)
    {
        int32_t l_51 = 0x879C9350L;
        int32_t l_60 = 3L;
        uint8_t l_61 = 0x17L;
        int32_t l_210 = 0L;
        uint32_t l_238 = 0xB82698C1L;
        if (((safe_add_func_int16_t_s_s((safe_sub_func_int32_t_s_s((func_45(l_51, g_40[0], func_52((l_58[4] = (0xE4L >= l_51)), g_40[2], g_2.f4, (+((6UL && (l_60 = l_51)) | ((g_2.f2 = (l_61 <= l_61)) || g_2.f5))), k), g_1039, l_863) <= g_2.f1), l_61)), g_63)) <= k))
        {
            uint16_t l_123 = 65535UL;
            int32_t l_126 = 0x51F8F6A0L;
            for (l_60 = 0; (l_60 == (-3)); --l_60)
            {
                uint32_t l_138 = 0UL;
                uint8_t l_145 = 2UL;
                if (((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s((l_863 & (k = (safe_mod_func_int16_t_s_s(g_63, l_122)))), 0)) > (g_63 & ((l_123 = g_2.f0) < (3L & (((safe_add_func_int8_t_s_s(((7L <= l_51) | l_863), g_2.f0)) | 0UL) || 0xE596L))))), 2)) == l_51))
                {
                    l_126 = g_63;
                }
                else
                {
                    struct S1 l_129 = {74,15,-5951,-51,147,32};
                    struct S0 l_147 = {-6L,1480};
                    for (l_321 = 0; (l_321 <= 11); ++l_321)
                    {
                        int16_t l_146 = 0xA7B7L;
                        l_129 = g_2;
                        g_130 = g_130;
                        l_146 = ((safe_rshift_func_int16_t_s_u(((((k = 0xE8AE3155L) & (l_321 != (-1L))) >= (safe_lshift_func_int8_t_s_u((l_145 = (!((safe_sub_func_int16_t_s_s((l_138 <= ((g_40[1] <= ((safe_rshift_func_uint8_t_u_s((((l_129.f1 = (((safe_mod_func_uint32_t_u_u((l_863 == (g_63 ^ ((safe_mod_func_uint16_t_u_u(g_130.f0, 1L)) && g_1039))), p_36)) <= g_2.f4) == 0x0C3003DDL)) & l_123) | l_123), 7)) >= l_129.f3)) && 1UL)), g_2.f5)) == 0xE0L))), 0))) | g_63), g_2.f2)) == g_2.f4);
                    }
                    l_147 = g_130;
                    if (g_2.f2)
                        break;
                }
            }
            for (p_36 = 22; (p_36 != (-10)); p_36 = safe_sub_func_int8_t_s_s(p_36, 7))
            {
                uint32_t l_175 = 4294967295UL;
                int32_t l_178 = (-3L);
                uint16_t l_212[10] = {65535UL, 65535UL, 0xC7ADL, 65535UL, 65535UL, 0xC7ADL, 65535UL, 65535UL, 0xC7ADL, 65535UL};
                int i;
                if (g_130.f0)
                    break;
                if (g_2.f2)
                    break;
                if (l_123)
                    continue;
                if (l_122)
                {
                    uint32_t l_156[9] = {0x0D3AC039L, 0x0D3AC039L, 6UL, 0x0D3AC039L, 0x0D3AC039L, 6UL, 0x0D3AC039L, 0x0D3AC039L, 6UL};
                    int i;
                    for (l_321 = (-12); (l_321 != 28); l_321++)
                    {
                        int16_t l_161 = (-3L);
                        int32_t l_162[7][4] = {{0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}};
                        int i, j;
                        l_162[2][2] = (safe_sub_func_int32_t_s_s((g_130.f0 <= (g_130.f1 = ((l_126 = ((g_63 >= ((safe_sub_func_int16_t_s_s(((l_156[3] < (0xD5L == (((g_63 < (safe_sub_func_uint8_t_u_u((l_161 = ((k = ((g_237 == 1UL) != l_60)) && (((safe_sub_func_uint16_t_u_u(0xF7D0L, g_2.f3)) ^ l_58[4]) == g_1039))), l_162[2][2]))) == 0UL) == l_162[2][2]))) > 0x97L), 4UL)) <= g_1106)) < l_123)) >= l_60))), g_63));
                        g_2.f3 = ((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u((g_2.f0 == (safe_sub_func_int8_t_s_s(((g_1106 = g_40[2]) != 0x2DD9L), (safe_sub_func_uint16_t_u_u((l_156[3] ^ (safe_lshift_func_int16_t_s_u((g_1039 = (8UL > (2UL == (0x66ACL ^ (((-1L) < l_156[3]) < g_237))))), l_175))), 1L))))), 7)), l_156[5])) == 0x0657D6C4L);
                    }
                }
                else
                {
                    struct S0 l_180[1][5][8] = {{{{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}}};
                    int16_t l_213 = (-1L);
                    int i, j, k;
                    for (l_122 = (-18); (l_122 != (-3)); l_122++)
                    {
                        int32_t l_179 = (-1L);
                        l_179 = (l_178 = g_63);
                        if (l_179)
                            continue;
                        g_130 = (l_180[0][2][4] = g_130);
                    }
                    g_2.f2 = (safe_add_func_uint32_t_u_u(((((g_63 = l_60) <= ((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u(g_130.f0, g_2.f2)), g_2.f2)) ^ (safe_add_func_int16_t_s_s((((safe_add_func_int32_t_s_s(((safe_mod_func_uint16_t_u_u((safe_mod_func_int8_t_s_s((safe_unary_minus_func_int8_t_s((((((safe_add_func_uint8_t_u_u(g_1039, g_2.f3)) || (safe_sub_func_int16_t_s_s((l_212[4] = (safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s((((((g_3324 = (l_210 = ((safe_lshift_func_uint16_t_u_s(((0x96262B8EL == l_863) > ((safe_mod_func_int32_t_s_s((g_237 < k), l_863)) ^ l_863)), 1)) >= g_237))) | l_321) & p_36) && g_1106) >= 0x7B1EL), l_863)), l_122)), g_1039))), g_1039))) | l_213) & 255UL) <= g_2.f3))), 253UL)), g_237)) & 4L), 4UL)) && g_237) || 0x7BL), l_180[0][2][4].f1)))) >= p_36) || l_863), (-6L)));
                    g_40[1] = g_1039;
                }
            }
        }
        else
        {
            int32_t l_232 = 0L;
            for (g_1039 = 0; (g_1039 >= 11); g_1039++)
            {
                int32_t l_218 = 0xD9B91490L;
                uint8_t l_227 = 254UL;
                g_217[0] = (g_130 = l_216[5][2][4]);
                for (l_61 = 0; (l_61 <= 5); l_61 += 1)
                {
                    uint16_t l_219 = 0x791FL;
                    struct S0 l_220[4] = {{0x34A1C847L,71}, {-1L,1107}, {0x34A1C847L,71}, {-1L,1107}};
                    int32_t l_234 = 1L;
                    int i;
                    for (p_36 = 4; (p_36 >= 1); p_36 -= 1)
                    {
                        int i;
                        if (l_58[p_36])
                            break;
                        l_218 = ((-1L) <= g_63);
                        l_210 = l_219;
                    }
                    g_217[0] = l_220[1];
                    for (l_122 = 0; (l_122 <= 5); l_122 += 1)
                    {
                        uint8_t l_233 = 0UL;
                        l_234 = (g_1039 <= (safe_mod_func_uint8_t_u_u(((-9L) && (((!((g_63 = (i = 4294967288UL)) != ((l_220[1].f1 = (safe_mod_func_int16_t_s_s(((l_227 ^ (((0xCDL || ((0xA2A9L < ((safe_lshift_func_int8_t_s_u(((l_863 ^ l_210) > ((l_232 = (0x87C8L || g_1039)) & g_130.f1)), l_58[3])) != g_1039)) < 0x96L)) != k) && g_1039)) < g_2.f5), 0x45C8L))) > 1UL))) | 9UL) < 1UL)), l_233)));
                    }
                }
            }
        }
        for (g_237 = 23; (g_237 != (-30)); --g_237)
        {
            return l_216[5][2][4].f0;
        }
        k = ((g_237 = g_2.f2) | (5L == l_238));
    }
    else
    {
        int8_t l_243 = 7L;
        uint16_t l_270 = 1UL;
        int32_t l_293 = 0x4223055EL;
        uint32_t l_300 = 0x6A80E99DL;
        uint16_t l_302 = 3UL;
        g_130.f1 = (g_2.f4 <= ((safe_mod_func_int8_t_s_s(((0x0902586CL != (0x0F0FC9D2L && l_216[5][2][4].f1)) <= 1L), (65535UL & ((safe_sub_func_uint32_t_u_u((g_63 = l_243), (0x78L || (!(k = (safe_sub_func_int16_t_s_s((safe_add_func_int32_t_s_s((safe_lshift_func_int16_t_s_u((0x4FL < 0x57L), l_863)), l_863)), p_36))))))) == 0x74A4447EL)))) || g_217[0].f0));
        l_251 = l_251;
        for (l_321 = 25; (l_321 < 3); --l_321)
        {
            int32_t l_301[1][6];
            int i, j;
            for (i = 0; i < 1; i++)
            {
                for (j = 0; j < 6; j++)
                    l_301[i][j] = 0x73B3B5CCL;
            }
            for (k = 0; (k < (-14)); k--)
            {
                uint16_t l_275 = 0x38A2L;
                int8_t l_276[8];
                int i;
                for (i = 0; i < 8; i++)
                    l_276[i] = 0L;
                if ((l_243 == (p_36 > p_36)))
                {
                    int8_t l_265 = 1L;
                    g_40[1] = ((((l_265 = (safe_lshift_func_uint16_t_u_s(3UL, (p_36 > (safe_rshift_func_uint8_t_u_s((((g_63 >= (safe_sub_func_uint8_t_u_u(g_130.f1, (g_714 = ((safe_lshift_func_uint16_t_u_s(g_63, 8)) <= g_237))))) == g_1039) <= 7UL), 3)))))) || (safe_mod_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(g_2.f2, l_270)), g_2.f1))) && p_36) >= p_36);
                    for (l_243 = 0; (l_243 <= 4); l_243 += 1)
                    {
                        g_237 = g_40[1];
                    }
                }
                else
                {
                    struct S1 l_273 = {66,-4,-10986,-87,170,225};
                    if (l_243)
                        break;
                    for (l_243 = 0; (l_243 <= 13); l_243 = safe_add_func_int16_t_s_s(l_243, 1))
                    {
                        l_251 = l_273;
                        l_275 = (l_273.f4 < g_40[1]);
                        l_276[0] = g_237;
                    }
                }
            }
            g_3324 = (safe_sub_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(g_1039, ((((safe_mod_func_uint32_t_u_u((((l_243 != k) < 0xCBEFL) && (safe_mod_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_u((l_301[0][5] = (safe_sub_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s((l_293 = l_251.f0), 2)) > ((safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(((safe_mod_func_int32_t_s_s(((g_1106 = (0x66L ^ (p_36 = g_40[0]))) != (((1UL >= 0x2C471631L) < l_300) || g_1039)), i)) > 0x303FCA0DL), 3)), l_270)) != 255UL)), l_321))), 3)), 0)), 0x4F0B7164L))), g_40[0])) <= l_251.f1) <= l_243) ^ (-1L)))), g_2.f1));
        }
        k = (l_302 > (p_36 >= (g_2.f4 >= (+(0x4FL != (l_216[5][2][4].f1 = g_2.f5))))));
    };


                    printf("index = [%d]\n", i);}

    };


}
                    l_58[i] = 1UL;}
    if (p_35)
    {
        int32_t l_51 = 0x879C9350L;
        int32_t l_60 = 3L;
        uint8_t l_61 = 0x17L;
        int32_t l_210 = 0L;
        uint32_t l_238 = 0xB82698C1L;
        if (((safe_add_func_int16_t_s_s((safe_sub_func_int32_t_s_s((func_45(l_51, g_40[0], func_52((l_58[4] = (0xE4L >= l_51)), g_40[2], g_2.f4, (+((6UL && (l_60 = l_51)) | ((g_2.f2 = (l_61 <= l_61)) || g_2.f5))), l_62), g_63, p_37) <= g_2.f1), l_61)), p_34)) <= l_62))
        {
            uint16_t l_123 = 65535UL;
            int32_t l_126 = 0x51F8F6A0L;
            for (l_60 = 0; (l_60 == (-3)); --l_60)
            {
                uint32_t l_138 = 0UL;
                uint8_t l_145 = 2UL;

if (g_415)
                            continue;

                    if (((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s((p_37 & (l_62 = (safe_mod_func_int16_t_s_s(p_34, l_122)))), 0)) > (p_34 & ((l_123 = g_2.f0) < (3L & (((safe_add_func_int8_t_s_s(((7L <= l_51) | p_37), g_2.f0)) | 0UL) || 0xE596L))))), 2)) == l_51))
                {

{
                uint16_t l_275 = 0x38A2L;
                int8_t l_276[8];
                int i;
                for (i = 0; i < 8; i++)
                    l_276[i] = 0L;
                if ((g_2667 == (l_824 > l_824)))
                {
                    int8_t l_265 = 1L;
                    g_40[1] = ((((l_265 = (safe_lshift_func_uint16_t_u_s(3UL, (l_824 > (safe_rshift_func_uint8_t_u_s((((p_35 >= (safe_sub_func_uint8_t_u_u(g_1895.f1, (l_61 = ((safe_lshift_func_uint16_t_u_s(p_35, 8)) <= g_211))))) == l_238) <= 7UL), 3)))))) || (safe_mod_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(g_274.f2, g_1106)), g_274.f1))) && l_824) >= l_824);
                    for (g_2667 = 0; (g_2667 <= 4); g_2667 += 1)
                    {
                        g_211 = g_40[1];
                    }
                }
                else
                {
                    struct S1 l_273 = {66,-4,-10986,-87,170,225};
                    if (g_2667)
                        break;
                    for (g_2667 = 0; (g_2667 <= 13); g_2667 = safe_add_func_int16_t_s_s(g_2667, 1))
                    {
                        g_274 = l_273;
                        l_275 = (l_273.f4 < g_40[1]);
                        l_276[0] = g_211;
                    }
                }
            }

                    l_126 = p_34;
                }
                else
                {
                    struct S1 l_129 = {74,15,-5951,-51,147,32};
                    struct S0 l_147 = {-6L,1480};
                    for (g_112 = 0; (g_112 <= 11); ++g_112)
                    {
                        int16_t l_146 = 0xA7B7L;
                        l_129 = g_2;
                        g_130 = g_130;

if (j)
                        continue;

                    l_146 = ((safe_rshift_func_int16_t_s_u(((((l_62 = 0xE8AE3155L) & (g_112 != (-1L))) >= (safe_lshift_func_int8_t_s_u((l_145 = (!((safe_sub_func_int16_t_s_s((l_138 <= ((g_40[1] <= ((safe_rshift_func_uint8_t_u_s((((l_129.f1 = (((safe_mod_func_uint32_t_u_u((p_37 == (p_34 ^ ((safe_mod_func_uint16_t_u_u(g_130.f0, 1L)) && p_35))), p_36)) <= g_2.f4) == 0x0C3003DDL)) & l_123) | l_123), 7)) >= l_129.f3)) && 1UL)), g_2.f5)) == 0xE0L))), 0))) | p_34), g_2.f2)) == g_2.f4);
                    }
                    l_147 = g_130;
                    if (g_2.f2)
                        break;
                }
            }

{
                    int32_t l_1485 = 0L;
                    int i, j, k;
                    l_1485 = g_1177[(l_61 + 1)][(l_61 + 1)][l_61];
                }

                    for (p_36 = 22; (p_36 != (-10)); p_36 = safe_sub_func_int8_t_s_s(p_36, 7))
            {
                uint32_t l_175 = 4294967295UL;
                int32_t l_178 = (-3L);
                uint16_t l_212[10] = {65535UL, 65535UL, 0xC7ADL, 65535UL, 65535UL, 0xC7ADL, 65535UL, 65535UL, 0xC7ADL, 65535UL};
                int i;
                if (g_130.f0)
                    {
for (l_441 = 20; (l_441 == 56); l_441 = safe_add_func_int8_t_s_s(l_441, 5))
            {
                struct S1 l_1943[8][9] = {{{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}};
                int i, j;
                l_1943[7][0] = (g_2 = g_2);
            };


                    break;}
                if (g_2.f2)
                    break;
                if (l_123)
                    {
if (l_321)
                        continue;

                    continue;}

l_175 += 1;


                    if (l_122)
                {
                    uint32_t l_156[9] = {0x0D3AC039L, 0x0D3AC039L, 6UL, 0x0D3AC039L, 0x0D3AC039L, 6UL, 0x0D3AC039L, 0x0D3AC039L, 6UL};
                    int i;

{
        int16_t l_319 = 7L;
        struct S1 l_322 = {218,-14,-13328,35,77,28};
        int32_t l_368 = (-1L);
        for (j = 0; (j == (-16)); j = safe_sub_func_uint16_t_u_u(j, 9))
        {
            int8_t l_318 = 0xA7L;
            struct S1 l_323 = {75,18,-1671,80,156,344};
            int16_t l_332 = 0x8338L;
            int32_t l_333 = 0x25710E5DL;
            uint32_t l_347 = 6UL;
            uint16_t l_560 = 0UL;
            g_112 = (((safe_add_func_int8_t_s_s((j = 0xB0L), (l_674.f0 && 8UL))) > g_40[1]) ^ ((((safe_rshift_func_int16_t_s_u((g_163 || ((safe_unary_minus_func_int32_t_s((((safe_sub_func_int32_t_s_s(g_1896.f0, (g_658.f1 = (((safe_lshift_func_int8_t_s_u(g_163, 3)) & (((((l_318 = l_674.f1) != g_40[2]) || 65535UL) || l_318) | l_319)) | 0x1FL)))) ^ g_63) == l_320[4][0][2]))) && 1L)), g_1184)) | 0xC9F1L) || l_318) >= 1UL));
            l_323 = (l_674 = l_322);
            for (g_112 = 0; (g_112 <= 49); g_112++)
            {
                int32_t l_327 = 0x989AA41EL;
                uint32_t l_340 = 0x828E4155L;
                int16_t l_370 = 0x7B07L;
                int32_t l_372 = (-1L);
                int8_t l_453 = 0x96L;
                uint16_t l_511 = 0x0BC0L;
                uint32_t l_542[7] = {7UL, 7UL, 18446744073709551606UL, 7UL, 7UL, 18446744073709551606UL, 7UL};
                int16_t l_585 = 0L;
                int8_t l_596 = 0xBEL;
                int8_t l_612 = 0x26L;
                int i;
                if ((safe_unary_minus_func_uint16_t_u(l_327)))
                {
                    uint32_t l_346 = 0x90B89719L;
                    int32_t l_348[9];
                    int i;
                    for (i = 0; i < 9; i++)
                        l_348[i] = 1L;
                    l_348[0] = (g_2214 == (g_40[1] = ((safe_rshift_func_int8_t_s_s(((safe_sub_func_int32_t_s_s(l_332, l_333)) | ((g_2214 && ((safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_s(g_163, 1)), (safe_rshift_func_int16_t_s_u(g_163, l_674.f5)))) | (l_340 = 0UL))) != ((safe_lshift_func_uint8_t_u_u((+(l_327 = (safe_rshift_func_int16_t_s_s(((l_346 <= g_217[0].f0) ^ l_674.f2), 1)))), l_674.f3)) ^ g_63))), 0)) == l_347)));
                    for (g_875 = 0; (g_875 < 13); g_875 = safe_add_func_int16_t_s_s(g_875, 2))
                    {
                        int8_t l_371 = (-2L);

g_174 += 1;


                    l_322 = g_658;
                        l_216[5][2][4].f1 = (safe_sub_func_uint8_t_u_u(((((g_63 < (safe_mod_func_uint8_t_u_u((g_63 < (safe_sub_func_int32_t_s_s(((((safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((((((l_322.f1 = (g_1184 = (safe_mod_func_int8_t_s_s(((l_323.f3 && (safe_sub_func_uint32_t_u_u((((l_368 = (safe_sub_func_int32_t_s_s((+g_875), g_2214))) <= (l_323.f2 = (safe_unary_minus_func_uint32_t_u(4294967287UL)))) < (l_320[4][0][2] > l_674.f0)), (j | l_784)))) >= l_370), l_371)))) < j) < g_163) || l_371) && l_674.f4), 0x1DCE6AB1L)), g_1106)) <= 4294967287UL) & 0UL) & 2UL), g_40[2]))), l_372))) && 0x3786L) >= 0x41L) & 1L), g_163));
                    }
                    for (g_1106 = 2; (g_1106 == 45); g_1106++)
                    {

for (l_327 = 0; (l_327 == (-3)); --l_327)
            {
                uint32_t l_138 = 0UL;
                uint8_t l_145 = 2UL;
                if (((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s((l_123 & (l_210 = (safe_mod_func_int16_t_s_s(g_971, g_969)))), 0)) > (g_971 & ((l_321 = l_674.f0) < (3L & (((safe_add_func_int8_t_s_s(((7L <= g_647) | l_123), l_674.f0)) | 0UL) || 0xE596L))))), 2)) == g_647))
                {
                    l_333 = g_971;
                }
                else
                {
                    struct S1 l_129 = {74,15,-5951,-51,147,32};
                    struct S0 l_147 = {-6L,1480};
                    for (l_863 = 0; (l_863 <= 11); ++l_863)
                    {
                        int16_t l_146 = 0xA7B7L;
                        l_129 = l_674;
                        g_1896 = g_1896;
                        l_146 = ((safe_rshift_func_int16_t_s_u(((((l_210 = 0xE8AE3155L) & (l_863 != (-1L))) >= (safe_lshift_func_int8_t_s_u((l_145 = (!((safe_sub_func_int16_t_s_s((l_138 <= ((g_40[1] <= ((safe_rshift_func_uint8_t_u_s((((l_129.f1 = (((safe_mod_func_uint32_t_u_u((l_123 == (g_971 ^ ((safe_mod_func_uint16_t_u_u(g_1896.f0, 1L)) && l_175))), l_612)) <= l_674.f4) == 0x0C3003DDL)) & l_321) | l_321), 7)) >= l_129.f3)) && 1UL)), l_674.f5)) == 0xE0L))), 0))) | g_971), l_674.f2)) == l_674.f4);
                    }
                    l_147 = g_1896;
                    if (l_674.f2)
                        break;
                }
            };


                    if (g_63)
                            break;
                    }
                    if (g_163)
                        continue;
                }
                else
                {
                    uint16_t l_385 = 0x4A82L;
                    uint32_t l_416 = 0xF4081C80L;
                    int32_t l_476 = 0xAC569D01L;
                    int32_t l_479 = 0x0FFF34F5L;
                    l_210 = ((+(((~(safe_add_func_uint32_t_u_u((safe_add_func_int32_t_s_s(((safe_lshift_func_int16_t_s_u(((((g_740 >= (((((((safe_add_func_int8_t_s_s(0xB2L, l_385)) <= (l_323.f1 = ((l_674.f4 == (safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(((((l_216[5][2][4].f0 >= (safe_lshift_func_uint16_t_u_s(0x8D89L, 13))) > (safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(((safe_add_func_uint8_t_u_u((safe_unary_minus_func_uint8_t_u((safe_lshift_func_int16_t_s_s((safe_sub_func_int16_t_s_s(l_368, (safe_rshift_func_int8_t_s_u(g_1106, ((l_385 < 0x54L) >= 0x2881L))))), l_58[4])))), l_58[3])) == 0xC3B5L), g_112)), 0))) <= g_1184) > l_368), g_1184)) == l_322.f3), g_740))) == g_1896.f1))) == 65533UL) == 9UL) > l_674.f0) >= g_63) || g_63)) | 0xE150EA9AL) || 7UL) > l_347), 4)) ^ g_959), g_1896.f0)), l_320[4][0][2]))) && l_674.f5) & g_163)) || 0xC4L);
                    if ((l_674.f1 >= (safe_mod_func_uint32_t_u_u(((safe_sub_func_uint32_t_u_u((0x2BL & (g_1896.f0 || (((safe_add_func_int16_t_s_s((g_658.f3 = ((safe_add_func_int16_t_s_s(g_163, (g_1184 && (safe_mod_func_uint16_t_u_u(0xE618L, (g_112 = (246UL & ((l_51 ^ (g_1184 = (-3L))) >= 0x59301DB9L)))))))) < g_63)), g_63)) | 0x48L) == l_416))), 0x94C6A02EL)) && l_674.f2), g_112))))
                    {
                        uint32_t l_440[4];
                        int i;
                        for (i = 0; i < 4; i++)
                            {
{
                g_274.f3 = 0L;
                i = l_251.f5;
                i = (+l_674.f4);
            }

                    l_440[i] = 6UL;}
                        l_210 = (safe_rshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u((((((l_784 = l_674.f5) || (~(0xF79201D8L <= (safe_mod_func_uint16_t_u_u((safe_sub_func_int32_t_s_s(g_1106, (+((g_63 = 1UL) && (safe_mod_func_int8_t_s_s(((!l_674.f4) <= (l_238 = (safe_mod_func_uint32_t_u_u(((safe_mod_func_int16_t_s_s(((safe_lshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(g_1896.f0, (((1L >= l_440[0]) && (((((g_1184 & l_340) < g_163) <= l_440[2]) || l_323.f3) != 0xF1L)) != l_674.f2))), 5)) != g_63), l_327)) == (-7L)), l_674.f5)))), g_740)))))), g_63))))) ^ 0x25L) >= l_674.f4) > l_674.f3), 5)), 0UL)), 4));
                        return g_40[1];
                    }
                    else
                    {
                        int32_t l_478 = 0xCB2505EBL;
                        l_674.f3 = g_1184;

{
                uint16_t l_661 = 0x6EA5L;
                int32_t l_671 = (-9L);
                if ((g_900 = (safe_rshift_func_uint8_t_u_u(g_971, l_661))))
                {
                    int32_t l_669 = 0x7D1AE5F8L;

{
                        if (k)
                            break;
                    }

                    for (l_318 = 27; (l_318 > (-25)); l_318--)
                    {
                        uint32_t l_665 = 0xE8B9A2A8L;
                        int32_t l_668[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_668[i] = 0x75128752L;
                        g_759 = (l_51 = l_665);
                        g_2.f1 = (l_668[1] = (g_658.f1 = l_665));
                        l_669 = g_971;
                        g_759 = l_318;
                    }
                    if (l_511)
                    {
                        return l_511;
                    }
                    else
                    {
                        return g_1039;
                    }
                }
                else
                {
                    uint32_t l_670 = 1UL;
                    l_671 = (l_670 = l_661);
                    g_2.f3 = (safe_lshift_func_int8_t_s_u(g_900, g_658.f4));
                }
            }

                    l_327 = (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s(((0x6C3B8124L >= (!j)) || (((0xB1F7L == (g_2667 = l_238)) <= (safe_sub_func_int32_t_s_s(g_63, (g_63 ^ ((l_453 | g_63) ^ (safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(0xE6L, 0)), g_63))))))) == l_51)), 0xEBL)), 12))));

if (g_237)
                            break;

                    l_323.f1 = ((safe_rshift_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(0x41L, (safe_lshift_func_int16_t_s_u((g_63 == ((((((safe_sub_func_int32_t_s_s((((safe_sub_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((((l_479 = ((safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s(((l_327 = (safe_lshift_func_int16_t_s_u(((l_674.f4 || (1L & (l_476 = g_63))) < g_658.f4), (((g_112 = (g_1184 >= (~(0xE59C2AA1L != 0xF9BF29F1L)))) || 1UL) > l_478)))) & l_674.f1), l_674.f1)), 0xF1F6L)) <= 0x6524L)) != g_163) < (-9L)), g_163)), l_478)) > 0x43L) | l_416), g_63)) <= l_322.f5) >= g_63) | g_2214) || l_347) & l_453)), l_323.f3)))), l_340)) == g_1184);
                        l_479 = (l_322.f3 = (safe_rshift_func_int8_t_s_u(((safe_lshift_func_int16_t_s_s(g_163, (safe_lshift_func_int16_t_s_u((((!(-9L)) == g_217[0].f0) >= (l_476 = g_1184)), 11)))) == 65535UL), 4)));
                    }
                }
                if (((0xCA025045L ^ (((safe_sub_func_uint32_t_u_u(((~(l_340 > ((((safe_rshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s((g_1184 = g_163), 1)) > ((+(safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(g_740, (((l_323.f1 = (g_112 = (safe_sub_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((g_1896.f1 || l_323.f2) <= (4294967295UL <= (((0L >= (safe_mod_func_int32_t_s_s((safe_sub_func_int16_t_s_s(((g_2214 || (-6L)) & 0xD3L), 0x79D5L)), l_674.f2))) & 0xCCCEL) == l_674.f2))), (-2L))), (-8L))))) ^ g_217[0].f0) || l_238))), g_63))) <= l_453)), j)) ^ g_63) ^ g_112) | 0xD9L))) | l_323.f5), l_238)) != 0UL) <= g_163)) <= g_63))
                {
                    uint32_t l_541 = 4294967289UL;
                    int32_t l_543[10] = {0x3EF99F8AL, 0x3EF99F8AL, 1L, 0x3EF99F8AL, 0x3EF99F8AL, 1L, 0x3EF99F8AL, 0x3EF99F8AL, 1L, 0x3EF99F8AL};
                    struct S0 l_597 = {-2L,901};
                    int i;
                    for (l_784 = 0; (l_784 != 59); ++l_784)
                    {
                        uint32_t l_514[2][8][5] = {{{0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}}, {{0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}}};
                        int i, j, k;
                        l_511 = 0xD56F6D0BL;
                        g_40[1] = 1L;
                        l_372 = (safe_add_func_int16_t_s_s(((((g_658.f3 = l_514[1][3][4]) && ((0x6E41L ^ ((((((((safe_mul_func_uint16_t_u_u(65526UL, (0x4B51FDB1L < 3UL))) != 4UL) > (safe_lshift_func_int16_t_s_s((l_327 = 1L), g_1896.f1))) | 5L) | 0xC785L) & l_514[1][3][3]) >= g_1184) & g_163)) <= g_2667)) >= 0L) || g_63), g_658.f4));

{
                    l_368 = 0L;
                    if (l_368)
                        continue;
                    g_656 = g_2;
                }

                    g_658.f3 = (safe_rshift_func_uint16_t_u_u(l_320[0][0][2], 10));
                    }
                    if ((((l_322.f1 = (((g_63 | ((safe_add_func_int32_t_s_s(((l_368 & (safe_mod_func_int8_t_s_s(((safe_unary_minus_func_int16_t_s(((l_543[9] = (safe_rshift_func_int8_t_s_u((g_1184 = (g_1106 > (safe_rshift_func_int16_t_s_s((((safe_unary_minus_func_uint16_t_u((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s(l_674.f2, (safe_rshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(((g_163 != (safe_sub_func_int32_t_s_s(l_541, g_1184))) <= (((0xE7L || g_163) & l_319) <= l_58[4])), l_541)), 6)))) != l_542[4]), g_63)))) && 0x87L) & l_323.f3), 6)))), g_217[0].f1))) >= 0x1377L))) || g_63), l_323.f2))) & g_2214), l_372)) ^ l_51)) || l_674.f1) | 0x47B1ED3EL)) & 0xBBL) == g_112))
                    {
                        uint32_t l_586 = 6UL;
                        g_40[0] = (safe_mod_func_int32_t_s_s((((safe_rshift_func_int8_t_s_s(0x1AL, 6)) != 0x9A7E1DFBL) != 0UL), (((safe_rshift_func_int16_t_s_u(l_543[1], (safe_sub_func_uint32_t_u_u((safe_sub_func_int8_t_s_s((((safe_mod_func_uint16_t_u_u(l_541, l_216[5][2][4].f1)) ^ (((safe_sub_func_int8_t_s_s(((((g_63 = g_1184) & g_1184) >= (safe_add_func_uint8_t_u_u((l_543[1] == j), l_674.f3))) != g_1184), 0xC4L)) <= l_322.f4) | l_560)) || l_347), 0xB3L)), g_2214)))) & l_453) & l_674.f3)));

if (g_40[(g_900 + 1)])
                            continue;

                    g_40[1] = (g_163 || (safe_mod_func_int8_t_s_s((((((safe_lshift_func_uint8_t_u_u(l_674.f2, (((safe_mod_func_uint16_t_u_u(g_1184, (((l_674.f4 = (((safe_add_func_uint8_t_u_u((safe_add_func_uint16_t_u_u(((((-9L) && ((safe_add_func_int16_t_s_s((0L != (safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_u((l_674.f5 == (((safe_rshift_func_uint8_t_u_u((l_784 = g_63), 5)) || (safe_lshift_func_uint8_t_u_s((((((safe_add_func_int32_t_s_s((0xC539F0A9L < (((safe_sub_func_uint8_t_u_u(g_63, g_63)) ^ 251UL) <= g_163)), 1L)) <= 0x34L) > 6L) <= l_674.f4) ^ g_63), g_63))) & 0L)), 8)), 0x94468146L))), g_63)) ^ g_63)) ^ l_585) > 0x3969L), 0UL)), g_63)) | l_674.f0) || g_163)) | l_541) && (-6L)))) && l_372) != 0xAAD2AD68L))) ^ g_63) ^ g_1184) > g_163) < 1UL), 255UL)));
                        if (l_674.f3)
                            {
p_34 += 1;



if (g_40[2])
                            continue;

                    continue;}

l_585 += 1;


                    l_586 = g_658.f1;
                    }
                    else
                    {

{
                        g_658 = l_322;
                    }

                    l_674.f2 = j;

if (((0xCA025045L ^ (((safe_sub_func_uint32_t_u_u(((~(g_2214 > ((((safe_rshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s((l_596 = l_863), 1)) > ((+(safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(g_69, (((g_2.f1 = (g_1106 = (safe_sub_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((g_1896.f1 || g_2.f2) <= (4294967295UL <= (((0L >= (safe_mod_func_int32_t_s_s((safe_sub_func_int16_t_s_s(((l_347 || (-6L)) & 0xD3L), 0x79D5L)), g_2.f2))) & 0xCCCEL) == g_274.f2))), (-2L))), (-8L))))) ^ g_217[0].f0) || g_2214))), l_347))) <= l_596)), k)) ^ l_347) ^ l_863) | 0xD9L))) | g_2.f5), g_2214)) != 0UL) <= l_863)) <= l_347))
                {
                    uint32_t l_541 = 4294967289UL;
                    int32_t l_543[10] = {0x3EF99F8AL, 0x3EF99F8AL, 1L, 0x3EF99F8AL, 0x3EF99F8AL, 1L, 0x3EF99F8AL, 0x3EF99F8AL, 1L, 0x3EF99F8AL};
                    struct S0 l_597 = {-2L,901};
                    int i;
                    for (l_784 = 0; (l_784 != 59); ++l_784)
                    {
                        uint32_t l_514[2][8][5] = {{{0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}}, {{0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}}};
                        int i, j, k;
                        l_123 = 0xD56F6D0BL;
                        g_40[1] = 1L;
                        l_60 = (safe_add_func_int16_t_s_s(((((g_656.f3 = l_514[1][3][4]) && ((0x6E41L ^ ((((((((safe_mul_func_uint16_t_u_u(65526UL, (0x4B51FDB1L < 3UL))) != 4UL) > (safe_lshift_func_int16_t_s_s((l_126 = 1L), g_1896.f1))) | 5L) | 0xC785L) & l_514[1][3][3]) >= l_596) & l_863)) <= l_596)) >= 0L) || g_63), g_656.f4));
                        g_656.f3 = (safe_rshift_func_uint16_t_u_u(l_320[0][0][2], 10));
                    }
                    if ((((l_322.f1 = (((g_63 | ((safe_add_func_int32_t_s_s(((g_875 & (safe_mod_func_int8_t_s_s(((safe_unary_minus_func_int16_t_s(((l_543[9] = (safe_rshift_func_int8_t_s_u((l_596 = (g_1106 > (safe_rshift_func_int16_t_s_s((((safe_unary_minus_func_uint16_t_u((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s(g_274.f2, (safe_rshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(((l_863 != (safe_sub_func_int32_t_s_s(l_541, l_596))) <= (((0xE7L || l_863) & l_319) <= l_58[4])), l_541)), 6)))) != l_542[4]), g_63)))) && 0x87L) & g_2.f3), 6)))), g_217[0].f1))) >= 0x1377L))) || g_63), g_2.f2))) & l_347), l_60)) ^ i)) || g_2.f1) | 0x47B1ED3EL)) & 0xBBL) == l_863))
                    {
                        uint32_t l_586 = 6UL;
                        g_40[0] = (safe_mod_func_int32_t_s_s((((safe_rshift_func_int8_t_s_s(0x1AL, 6)) != 0x9A7E1DFBL) != 0UL), (((safe_rshift_func_int16_t_s_u(l_543[1], (safe_sub_func_uint32_t_u_u((safe_sub_func_int8_t_s_s((((safe_mod_func_uint16_t_u_u(l_541, l_216[5][2][4].f1)) ^ (((safe_sub_func_int8_t_s_s(((((g_63 = l_596) & l_596) >= (safe_add_func_uint8_t_u_u((l_543[1] == l_126), g_2.f3))) != l_596), 0xC4L)) <= l_322.f4) | g_415)) || l_175), 0xB3L)), l_347)))) & l_596) & g_2.f3)));
                        g_40[1] = (l_863 || (safe_mod_func_int8_t_s_s((((((safe_lshift_func_uint8_t_u_u(g_274.f2, (((safe_mod_func_uint16_t_u_u(l_596, (((g_274.f4 = (((safe_add_func_uint8_t_u_u((safe_add_func_uint16_t_u_u(((((-9L) && ((safe_add_func_int16_t_s_s((0L != (safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_u((g_2.f5 == (((safe_rshift_func_uint8_t_u_u((l_784 = l_347), 5)) || (safe_lshift_func_uint8_t_u_s((((((safe_add_func_int32_t_s_s((0xC539F0A9L < (((safe_sub_func_uint8_t_u_u(l_347, g_63)) ^ 251UL) <= l_863)), 1L)) <= 0x34L) > 6L) <= g_274.f4) ^ g_63), l_347))) & 0L)), 8)), 0x94468146L))), g_63)) ^ g_63)) ^ l_370) > 0x3969L), 0UL)), l_347)) | g_274.f0) || l_863)) | l_541) && (-6L)))) && l_60) != 0xAAD2AD68L))) ^ l_347) ^ l_596) > l_863) < 1UL), 255UL)));
                        if (g_274.f3)
                            continue;
                        l_586 = g_656.f1;
                    }
                    else
                    {
                        g_274.f2 = k;
                        g_274.f2 = g_274.f5;
                    }
                    if ((safe_rshift_func_int16_t_s_s((l_543[1] <= (+2UL)), (safe_mod_func_int8_t_s_s((g_875 && (0x7D100E82L < (l_542[4] <= ((((safe_rshift_func_int16_t_s_u(((0x4E4BL && l_58[2]) ^ ((0x2E7EE68AL <= (((safe_add_func_uint32_t_u_u((g_274.f0 = (((l_543[9] >= l_216[5][2][4].f1) | g_63) && l_863)), l_596)) == (-1L)) && g_63)) >= g_1106)), 6)) || l_596) | 0x05L) == l_347)))), l_60)))))
                    {
                        int8_t l_598 = 0xBFL;
                        g_217[0] = l_597;
                        g_274.f3 = l_596;
                        if (g_69)
                            continue;
                        l_598 = 0L;
                    }
                    else
                    {
                        if (l_863)
                            break;
                        return l_543[7];
                    }
                }
                else
                {
                    return l_347;
                };


                    l_674.f2 = l_674.f5;
                    }
                    if ((safe_rshift_func_int16_t_s_s((l_543[1] <= (+2UL)), (safe_mod_func_int8_t_s_s((l_368 && (0x7D100E82L < (l_542[4] <= ((((safe_rshift_func_int16_t_s_u(((0x4E4BL && l_58[2]) ^ ((0x2E7EE68AL <= (((safe_add_func_uint32_t_u_u((l_674.f0 = (((l_543[9] >= l_216[5][2][4].f1) | g_63) && g_163)), g_1184)) == (-1L)) && g_63)) >= g_1106)), 6)) || l_596) | 0x05L) == g_63)))), j)))))
                    {
                        int8_t l_598 = 0xBFL;
                        g_217[0] = l_597;
                        l_674.f3 = g_1184;
                        if (g_740)
                            continue;
                        l_598 = 0L;
                    }
                    else
                    {
                        if (g_163)
                            break;
                        return l_543[7];
                    }
                }
                else
                {

{
        int8_t l_1730 = 4L;
        int32_t l_1763 = 0x5453623BL;
        int32_t l_1765 = 0xFAA487A7L;
        int32_t l_1766 = (-8L);
        uint8_t l_1767 = 247UL;
        struct S0 l_1784[8][10] = {{{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}, {{1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}, {1L,1157}, {0L,-1749}, {0x85AAD430L,264}, {0x85AAD430L,264}, {0L,-1749}}};
        int i, j;
        if ((l_1730 | 0L))
        {
            struct S0 l_1731 = {0x8B54C699L,-1628};
            int32_t l_1764 = 1L;
            g_1058 = g_1177[2][3][1];
            g_217[0] = l_1731;
            l_178 = (safe_rshift_func_uint8_t_u_s((safe_unary_minus_func_int32_t_s((safe_lshift_func_int8_t_s_s((-4L), (safe_rshift_func_uint16_t_u_s(((l_323.f1 = ((safe_rshift_func_int16_t_s_s((safe_lshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(((0x96L && ((0xA7C3L < (safe_rshift_func_int16_t_s_u(((l_62 == (l_1766 = (safe_add_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s(0L, ((safe_sub_func_int16_t_s_s(g_1058, (safe_sub_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_s((safe_sub_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(l_560, (l_1765 = ((l_1764 = ((l_1763 = ((l_1731.f1 = g_1058) <= ((safe_add_func_uint16_t_u_u(l_1730, l_322.f3)) <= 0x3FE4L))) < g_875)) || g_656.f0)))), l_1730)), 1)) ^ 5UL), 0x5CL)))) || l_1763))) || g_1058), 0xB94CF378L)))) <= g_656.f0), 3))) & 0L)) || g_211), g_69)), 3)), 4)) >= l_323.f4)) <= g_1056), l_1767)))))), l_1767));
        }
        else
        {
            uint32_t l_1783 = 0x80786831L;
            struct S0 l_1785 = {9L,-1659};
            g_40[1] = (((((safe_sub_func_uint8_t_u_u((l_1730 > (g_3662 == (safe_mod_func_uint8_t_u_u(0x2DL, l_674.f0)))), p_37)) >= ((safe_add_func_int32_t_s_s(g_1058, (safe_mod_func_int16_t_s_s(l_784, (safe_sub_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u(((((((l_323.f1 = (-9L)) | ((((safe_add_func_uint16_t_u_u((((safe_unary_minus_func_int32_t_s(((g_1058 <= p_37) & g_1058))) >= 0x041CC1BDL) == p_37), g_1058)) <= l_1783) > p_37) < 65535UL)) >= 0xA4DBL) != (-1L)) == 9UL) && l_323.f4), l_1767)) != i), p_37)))))) < l_1783)) > l_1765) >= p_37) >= g_1896.f0);
            if (l_322.f1)
                continue;
            l_1785 = l_1784[1][9];
            g_1896 = g_217[0];
        }
    }


{
    uint32_t l_58[6];
    int32_t l_62 = 0x59BBC08FL;
    int16_t l_122 = 0xCE6BL;
    struct S0 l_216[7][5][5] = {{{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}, {{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}, {{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}, {{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}, {{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}, {{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}, {{{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}, {{0x15D6DEBDL,1941}, {0x291ADAEAL,-1915}, {1L,-1943}, {0x291ADAEAL,-1915}, {0x15D6DEBDL,1941}}}};
    struct S1 l_251 = {108,-3,10049,-17,167,287};
    int16_t l_320[7][1][7] = {{{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}, {{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}, {{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}, {{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}, {{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}, {{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}, {{0x4E1CL, 0xA331L, 5L, 0xA331L, 0x4E1CL, 0xA331L, 5L}}};
    uint16_t l_321 = 0x7542L;
    uint32_t l_441 = 0x2AFAB89DL;
    int8_t l_450 = 0x00L;
    int32_t l_652 = 0x816C5560L;
    struct S1 l_674 = {101,-10,7274,-22,12,219};
    uint8_t l_784 = 0x23L;
    int8_t l_824 = 0L;
    uint16_t l_863 = 65535UL;
    int16_t l_884[5] = {0L, 8L, 0L, 8L, 0L};
    int i, j, k;
    for (i = 0; i < 6; i++)
        l_58[i] = 1UL;
    if (l_441)
    {
        int32_t l_51 = 0x879C9350L;
        int32_t l_60 = 3L;
        uint8_t l_61 = 0x17L;
        int32_t l_210 = 0L;
        uint32_t l_238 = 0xB82698C1L;
        if (((safe_add_func_int16_t_s_s((safe_sub_func_int32_t_s_s((func_45(l_51, g_40[0], func_52((l_58[4] = (0xE4L >= l_51)), g_40[2], l_322.f4, (+((6UL && (l_60 = l_51)) | ((l_322.f2 = (l_61 <= l_61)) || l_322.f5))), l_62), g_174, l_321) <= l_322.f1), l_61)), g_740)) <= l_62))
        {
            uint16_t l_123 = 65535UL;
            int32_t l_126 = 0x51F8F6A0L;
            for (l_60 = 0; (l_60 == (-3)); --l_60)
            {
                uint32_t l_138 = 0UL;
                uint8_t l_145 = 2UL;
                if (((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_s((l_321 & (l_62 = (safe_mod_func_int16_t_s_s(g_740, l_122)))), 0)) > (g_740 & ((l_123 = l_322.f0) < (3L & (((safe_add_func_int8_t_s_s(((7L <= l_51) | l_321), l_322.f0)) | 0UL) || 0xE596L))))), 2)) == l_51))
                {
                    l_126 = g_740;
                }
                else
                {
                    struct S1 l_129 = {74,15,-5951,-51,147,32};
                    struct S0 l_147 = {-6L,1480};
                    for (l_560 = 0; (l_560 <= 11); ++l_560)
                    {
                        int16_t l_146 = 0xA7B7L;
                        l_129 = l_322;
                        g_1896 = g_1896;
                        l_146 = ((safe_rshift_func_int16_t_s_u(((((l_62 = 0xE8AE3155L) & (l_560 != (-1L))) >= (safe_lshift_func_int8_t_s_u((l_145 = (!((safe_sub_func_int16_t_s_s((l_138 <= ((g_40[1] <= ((safe_rshift_func_uint8_t_u_s((((l_129.f1 = (((safe_mod_func_uint32_t_u_u((l_321 == (g_740 ^ ((safe_mod_func_uint16_t_u_u(g_1896.f0, 1L)) && l_441))), g_1184)) <= l_322.f4) == 0x0C3003DDL)) & l_123) | l_123), 7)) >= l_129.f3)) && 1UL)), l_322.f5)) == 0xE0L))), 0))) | g_740), l_322.f2)) == l_322.f4);
                    }
                    l_147 = g_1896;
                    if (l_322.f2)
                        break;
                }
            }
            for (g_1184 = 22; (g_1184 != (-10)); g_1184 = safe_sub_func_int8_t_s_s(g_1184, 7))
            {
                uint32_t l_175 = 4294967295UL;
                int32_t l_178 = (-3L);
                uint16_t l_212[10] = {65535UL, 65535UL, 0xC7ADL, 65535UL, 65535UL, 0xC7ADL, 65535UL, 65535UL, 0xC7ADL, 65535UL};
                int i;
                if (g_1896.f0)
                    break;
                if (l_322.f2)
                    break;
                if (l_123)
                    continue;
                if (l_122)
                {
                    uint32_t l_156[9] = {0x0D3AC039L, 0x0D3AC039L, 6UL, 0x0D3AC039L, 0x0D3AC039L, 6UL, 0x0D3AC039L, 0x0D3AC039L, 6UL};
                    int i;
                    for (l_560 = (-12); (l_560 != 28); l_560++)
                    {
                        int16_t l_161 = (-3L);
                        int32_t l_162[7][4] = {{0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}};
                        int i, j;
                        l_162[2][2] = (safe_sub_func_int32_t_s_s((g_1896.f0 <= (g_1896.f1 = ((l_126 = ((g_740 >= ((safe_sub_func_int16_t_s_s(((l_156[3] < (0xD5L == (((g_740 < (safe_sub_func_uint8_t_u_u((l_161 = ((l_62 = ((g_237 == 1UL) != l_60)) && (((safe_sub_func_uint16_t_u_u(0xF7D0L, l_322.f3)) ^ l_58[4]) == l_441))), l_162[2][2]))) == 0UL) == l_162[2][2]))) > 0x97L), 4UL)) <= l_321)) < l_123)) >= l_60))), g_740));
                        l_322.f3 = ((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u((l_322.f0 == (safe_sub_func_int8_t_s_s(((l_321 = g_40[2]) != 0x2DD9L), (safe_sub_func_uint16_t_u_u((l_156[3] ^ (safe_lshift_func_int16_t_s_u((g_740 = (8UL > (2UL == (0x66ACL ^ (((-1L) < l_156[3]) < g_237))))), l_175))), 1L))))), 7)), l_156[5])) == 0x0657D6C4L);
                    }
                }
                else
                {
                    struct S0 l_180[1][5][8] = {{{{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}}};
                    int16_t l_213 = (-1L);
                    int i, j, k;
                    for (l_122 = (-18); (l_122 != (-3)); l_122++)
                    {
                        int32_t l_179 = (-1L);
                        l_179 = (l_178 = g_740);
                        if (l_179)
                            continue;
                        g_1896 = (l_180[0][2][4] = g_1896);
                    }
                    l_322.f2 = (safe_add_func_uint32_t_u_u(((((g_740 = l_60) <= ((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u(g_1896.f0, l_322.f2)), l_322.f2)) ^ (safe_add_func_int16_t_s_s((((safe_add_func_int32_t_s_s(((safe_mod_func_uint16_t_u_u((safe_mod_func_int8_t_s_s((safe_unary_minus_func_int8_t_s((((((safe_add_func_uint8_t_u_u(g_740, l_322.f3)) || (safe_sub_func_int16_t_s_s((l_212[4] = (safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s((((((l_62 = (l_210 = ((safe_lshift_func_uint16_t_u_s(((0x96262B8EL == l_321) > ((safe_mod_func_int32_t_s_s((g_237 < l_62), l_321)) ^ l_321)), 1)) >= g_237))) | l_560) & g_1184) && l_321) >= 0x7B1EL), l_321)), l_122)), l_441))), g_174))) | l_213) & 255UL) <= l_322.f3))), 253UL)), g_237)) & 4L), 4UL)) && g_237) || 0x7BL), l_180[0][2][4].f1)))) >= g_1184) || l_321), (-6L)));
                    g_40[1] = g_174;
                }
            }
        }
        else
        {
            int32_t l_232 = 0L;
            for (g_174 = 0; (g_174 >= 11); g_174++)
            {
                int32_t l_218 = 0xD9B91490L;
                uint8_t l_227 = 254UL;
                g_217[0] = (g_1896 = l_216[5][2][4]);
                for (l_61 = 0; (l_61 <= 5); l_61 += 1)
                {
                    uint16_t l_219 = 0x791FL;
                    struct S0 l_220[4] = {{0x34A1C847L,71}, {-1L,1107}, {0x34A1C847L,71}, {-1L,1107}};
                    int32_t l_234 = 1L;
                    int i;
                    for (g_1184 = 4; (g_1184 >= 1); g_1184 -= 1)
                    {
                        int i;
                        if (l_58[g_1184])
                            break;
                        l_218 = ((-1L) <= g_740);
                        l_210 = l_219;
                    }
                    g_217[0] = l_220[1];
                    for (l_122 = 0; (l_122 <= 5); l_122 += 1)
                    {
                        uint8_t l_233 = 0UL;
                        l_234 = (g_174 <= (safe_mod_func_uint8_t_u_u(((-9L) && (((!((g_740 = (i = 4294967288UL)) != ((l_220[1].f1 = (safe_mod_func_int16_t_s_s(((l_227 ^ (((0xCDL || ((0xA2A9L < ((safe_lshift_func_int8_t_s_u(((l_321 ^ l_210) > ((l_232 = (0x87C8L || l_441)) & g_1896.f1)), l_58[3])) != l_441)) < 0x96L)) != l_62) && g_174)) < l_322.f5), 0x45C8L))) > 1UL))) | 9UL) < 1UL)), l_233)));
                    }
                }
            }
        }
        for (g_237 = 23; (g_237 != (-30)); --g_237)
        {
            return l_216[5][2][4].f0;
        }
        l_62 = ((j = l_322.f2) | (5L == l_238));
    }
    else
    {
        int8_t l_243 = 7L;
        uint16_t l_270 = 1UL;
        int32_t l_293 = 0x4223055EL;
        uint32_t l_300 = 0x6A80E99DL;
        uint16_t l_302 = 3UL;
        g_1896.f1 = (l_322.f4 <= ((safe_mod_func_int8_t_s_s(((0x0902586CL != (0x0F0FC9D2L && l_216[5][2][4].f1)) <= 1L), (65535UL & ((safe_sub_func_uint32_t_u_u((g_740 = l_243), (0x78L || (!(l_62 = (safe_sub_func_int16_t_s_s((safe_add_func_int32_t_s_s((safe_lshift_func_int16_t_s_u((0x4FL < 0x57L), l_321)), l_321)), g_1184))))))) == 0x74A4447EL)))) || g_217[0].f0));
        l_251 = l_251;
        for (l_560 = 25; (l_560 < 3); --l_560)
        {
            int32_t l_301[1][6];
            int i, j;
            for (i = 0; i < 1; i++)
            {
                for (j = 0; j < 6; j++)
                    l_301[i][j] = 0x73B3B5CCL;
            }
            for (l_62 = 0; (l_62 < (-14)); l_62--)
            {
                uint16_t l_275 = 0x38A2L;
                int8_t l_276[8];
                int i;
                for (i = 0; i < 8; i++)
                    l_276[i] = 0L;
                if ((l_243 == (g_1184 > g_1184)))
                {
                    int8_t l_265 = 1L;
                    g_40[1] = ((((l_265 = (safe_lshift_func_uint16_t_u_s(3UL, (g_1184 > (safe_rshift_func_uint8_t_u_s((((g_740 >= (safe_sub_func_uint8_t_u_u(g_1896.f1, (l_784 = ((safe_lshift_func_uint16_t_u_s(g_740, 8)) <= j))))) == g_740) <= 7UL), 3)))))) || (safe_mod_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(l_322.f2, l_270)), l_322.f1))) && g_1184) >= g_1184);
                    for (l_243 = 0; (l_243 <= 4); l_243 += 1)
                    {
                        j = g_40[1];
                    }
                }
                else
                {
                    struct S1 l_273 = {66,-4,-10986,-87,170,225};
                    if (l_243)
                        break;
                    for (l_243 = 0; (l_243 <= 13); l_243 = safe_add_func_int16_t_s_s(l_243, 1))
                    {
                        l_322 = l_273;
                        l_275 = (l_273.f4 < g_40[1]);
                        l_276[0] = j;
                    }
                }
            }
            l_62 = (safe_sub_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(g_174, ((((safe_mod_func_uint32_t_u_u((((l_243 != l_62) < 0xCBEFL) && (safe_mod_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_u((l_301[0][5] = (safe_sub_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s((l_293 = l_251.f0), 2)) > ((safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(((safe_mod_func_int32_t_s_s(((l_321 = (0x66L ^ (g_1184 = g_40[0]))) != (((1UL >= 0x2C471631L) < l_300) || l_441)), i)) > 0x303FCA0DL), 3)), l_270)) != 255UL)), l_560))), 3)), 0)), 0x4F0B7164L))), g_40[0])) <= l_322.f1) <= l_243) ^ (-1L)))), l_322.f1));
        }
        l_62 = (l_302 > (g_1184 >= (l_322.f4 >= (+(0x4FL != (l_216[5][2][4].f1 = l_322.f5))))));
    }
    for (l_122 = (-12); (l_122 <= (-7)); l_122 = safe_add_func_uint32_t_u_u(l_122, 5))
    {
        int16_t l_319 = 7L;
        struct S1 l_322 = {218,-14,-13328,35,77,28};
        int32_t l_368 = (-1L);
        for (i = 0; (i == (-16)); i = safe_sub_func_uint16_t_u_u(i, 9))
        {
            int8_t l_318 = 0xA7L;
            struct S1 l_323 = {75,18,-1671,80,156,344};
            int16_t l_332 = 0x8338L;
            int32_t l_333 = 0x25710E5DL;
            uint32_t l_347 = 6UL;
            uint16_t l_560 = 0UL;
            l_321 = (((safe_add_func_int8_t_s_s((g_2317 = 0xB0L), (l_322.f0 && 8UL))) > g_40[1]) ^ ((((safe_rshift_func_int16_t_s_u((l_321 || ((safe_unary_minus_func_int32_t_s((((safe_sub_func_int32_t_s_s(g_1896.f0, (l_251.f1 = (((safe_lshift_func_int8_t_s_u(l_321, 3)) & (((((l_318 = l_322.f1) != g_40[2]) || 65535UL) || l_318) | l_319)) | 0x1FL)))) ^ l_441) == l_320[4][0][2]))) && 1L)), g_1184)) | 0xC9F1L) || l_318) >= 1UL));
            l_323 = (l_322 = l_322);
            for (l_321 = 0; (l_321 <= 49); l_321++)
            {
                int32_t l_327 = 0x989AA41EL;
                uint32_t l_340 = 0x828E4155L;
                int16_t l_370 = 0x7B07L;
                int32_t l_372 = (-1L);
                int8_t l_453 = 0x96L;
                uint16_t l_511 = 0x0BC0L;
                uint32_t l_542[7] = {7UL, 7UL, 18446744073709551606UL, 7UL, 7UL, 18446744073709551606UL, 7UL};
                int16_t l_585 = 0L;
                int8_t l_596 = 0xBEL;
                int8_t l_612 = 0x26L;
                int i;
                if ((safe_unary_minus_func_uint16_t_u(l_327)))
                {
                    uint32_t l_346 = 0x90B89719L;
                    int32_t l_348[9];
                    int i;
                    for (i = 0; i < 9; i++)
                        l_348[i] = 1L;
                    l_348[0] = (g_740 == (g_40[1] = ((safe_rshift_func_int8_t_s_s(((safe_sub_func_int32_t_s_s(l_332, l_333)) | ((g_740 && ((safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_s(l_321, 1)), (safe_rshift_func_int16_t_s_u(l_321, l_322.f5)))) | (l_340 = 0UL))) != ((safe_lshift_func_uint8_t_u_u((+(l_327 = (safe_rshift_func_int16_t_s_s(((l_346 <= g_217[0].f0) ^ l_322.f2), 1)))), l_322.f3)) ^ g_740))), 0)) == l_347)));
                    for (g_237 = 0; (g_237 < 13); g_237 = safe_add_func_int16_t_s_s(g_237, 2))
                    {
                        int8_t l_371 = (-2L);
                        l_322 = l_251;
                        l_216[5][2][4].f1 = (safe_sub_func_uint8_t_u_u(((((g_740 < (safe_mod_func_uint8_t_u_u((l_441 < (safe_sub_func_int32_t_s_s(((((safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((((((l_322.f1 = (g_1184 = (safe_mod_func_int8_t_s_s(((l_323.f3 && (safe_sub_func_uint32_t_u_u((((l_368 = (safe_sub_func_int32_t_s_s((+g_237), g_740))) <= (l_323.f2 = (safe_unary_minus_func_uint32_t_u(4294967287UL)))) < (l_320[4][0][2] > l_322.f0)), (g_2317 | l_784)))) >= l_370), l_371)))) < l_62) < l_321) || l_371) && l_322.f4), 0x1DCE6AB1L)), l_560)) <= 4294967287UL) & 0UL) & 2UL), g_40[2]))), l_372))) && 0x3786L) >= 0x41L) & 1L), l_321));
                    }
                    for (l_560 = 2; (l_560 == 45); l_560++)
                    {
                        if (g_740)
                            break;
                    }
                    if (l_321)
                        continue;
                }
                else
                {
                    uint16_t l_385 = 0x4A82L;
                    uint32_t l_416 = 0xF4081C80L;
                    int32_t l_476 = 0xAC569D01L;
                    int32_t l_479 = 0x0FFF34F5L;
                    l_62 = ((+(((~(safe_add_func_uint32_t_u_u((safe_add_func_int32_t_s_s(((safe_lshift_func_int16_t_s_u(((((g_174 >= (((((((safe_add_func_int8_t_s_s(0xB2L, l_385)) <= (l_323.f1 = ((l_322.f4 == (safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(((((l_216[5][2][4].f0 >= (safe_lshift_func_uint16_t_u_s(0x8D89L, 13))) > (safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(((safe_add_func_uint8_t_u_u((safe_unary_minus_func_uint8_t_u((safe_lshift_func_int16_t_s_s((safe_sub_func_int16_t_s_s(l_368, (safe_rshift_func_int8_t_s_u(l_560, ((l_385 < 0x54L) >= 0x2881L))))), l_58[4])))), l_58[3])) == 0xC3B5L), l_321)), 0))) <= g_1184) > l_368), g_1184)) == l_322.f3), g_174))) == g_1896.f1))) == 65533UL) == 9UL) > l_322.f0) >= g_740) || g_740)) | 0xE150EA9AL) || 7UL) > l_347), 4)) ^ l_122), g_1896.f0)), l_320[4][0][2]))) && l_322.f5) & l_321)) || 0xC4L);
                    if ((l_322.f1 >= (safe_mod_func_uint32_t_u_u(((safe_sub_func_uint32_t_u_u((0x2BL & (g_1896.f0 || (((safe_add_func_int16_t_s_s((l_251.f3 = ((safe_add_func_int16_t_s_s(l_321, (g_1184 && (safe_mod_func_uint16_t_u_u(0xE618L, (l_321 = (246UL & ((j ^ (g_1184 = (-3L))) >= 0x59301DB9L)))))))) < l_441)), g_740)) | 0x48L) == l_416))), 0x94C6A02EL)) && l_322.f2), l_321))))
                    {
                        uint32_t l_440[4];
                        int i;
                        for (i = 0; i < 4; i++)
                            l_440[i] = 6UL;
                        l_62 = (safe_rshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u((((((l_784 = l_322.f5) || (~(0xF79201D8L <= (safe_mod_func_uint16_t_u_u((safe_sub_func_int32_t_s_s(l_560, (+((g_740 = 1UL) && (safe_mod_func_int8_t_s_s(((!l_322.f4) <= (l_441 = (safe_mod_func_uint32_t_u_u(((safe_mod_func_int16_t_s_s(((safe_lshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(g_1896.f0, (((1L >= l_440[0]) && (((((g_1184 & l_340) < l_321) <= l_440[2]) || l_323.f3) != 0xF1L)) != l_322.f2))), 5)) != l_441), l_327)) == (-7L)), l_322.f5)))), g_174)))))), l_441))))) ^ 0x25L) >= l_322.f4) > l_322.f3), 5)), 0UL)), 4));
                        return g_40[1];
                    }
                    else
                    {
                        int32_t l_478 = 0xCB2505EBL;
                        l_322.f3 = g_1184;
                        l_327 = (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s(((0x6C3B8124L >= (!i)) || (((0xB1F7L == (l_450 = l_441)) <= (safe_sub_func_int32_t_s_s(l_441, (g_740 ^ ((l_453 | l_441) ^ (safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(0xE6L, 0)), l_441))))))) == j)), 0xEBL)), 12))));
                        l_323.f1 = ((safe_rshift_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(0x41L, (safe_lshift_func_int16_t_s_u((l_441 == ((((((safe_sub_func_int32_t_s_s((((safe_sub_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((((l_479 = ((safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s(((l_327 = (safe_lshift_func_int16_t_s_u(((l_322.f4 || (1L & (l_476 = g_740))) < l_251.f4), (((l_321 = (g_1184 >= (~(0xE59C2AA1L != 0xF9BF29F1L)))) || 1UL) > l_478)))) & l_322.f1), l_322.f1)), 0xF1F6L)) <= 0x6524L)) != l_321) < (-9L)), l_321)), l_478)) > 0x43L) | l_416), l_441)) <= l_322.f5) >= l_441) | g_740) || l_347) & l_453)), l_323.f3)))), l_340)) == g_1184);
                        l_479 = (l_322.f3 = (safe_rshift_func_int8_t_s_u(((safe_lshift_func_int16_t_s_s(l_321, (safe_lshift_func_int16_t_s_u((((!(-9L)) == g_217[0].f0) >= (l_476 = g_1184)), 11)))) == 65535UL), 4)));
                    }
                }
                if (((0xCA025045L ^ (((safe_sub_func_uint32_t_u_u(((~(l_340 > ((((safe_rshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s((g_1184 = l_321), 1)) > ((+(safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(g_174, (((l_323.f1 = (l_321 = (safe_sub_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((g_1896.f1 || l_323.f2) <= (4294967295UL <= (((0L >= (safe_mod_func_int32_t_s_s((safe_sub_func_int16_t_s_s(((g_740 || (-6L)) & 0xD3L), 0x79D5L)), l_322.f2))) & 0xCCCEL) == l_322.f2))), (-2L))), (-8L))))) ^ g_217[0].f0) || l_441))), l_441))) <= l_453)), i)) ^ l_441) ^ l_321) | 0xD9L))) | l_323.f5), l_441)) != 0UL) <= l_321)) <= l_441))
                {
                    uint32_t l_541 = 4294967289UL;
                    int32_t l_543[10] = {0x3EF99F8AL, 0x3EF99F8AL, 1L, 0x3EF99F8AL, 0x3EF99F8AL, 1L, 0x3EF99F8AL, 0x3EF99F8AL, 1L, 0x3EF99F8AL};
                    struct S0 l_597 = {-2L,901};
                    int i;
                    for (l_784 = 0; (l_784 != 59); ++l_784)
                    {
                        uint32_t l_514[2][8][5] = {{{0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}}, {{0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}}};
                        int i, j, k;
                        l_511 = 0xD56F6D0BL;
                        g_40[1] = 1L;
                        l_372 = (safe_add_func_int16_t_s_s(((((l_251.f3 = l_514[1][3][4]) && ((0x6E41L ^ ((((((((safe_mul_func_uint16_t_u_u(65526UL, (0x4B51FDB1L < 3UL))) != 4UL) > (safe_lshift_func_int16_t_s_s((l_327 = 1L), g_1896.f1))) | 5L) | 0xC785L) & l_514[1][3][3]) >= g_1184) & l_321)) <= l_450)) >= 0L) || g_740), l_251.f4));
                        l_251.f3 = (safe_rshift_func_uint16_t_u_u(l_320[0][0][2], 10));
                    }
                    if ((((l_322.f1 = (((g_740 | ((safe_add_func_int32_t_s_s(((l_368 & (safe_mod_func_int8_t_s_s(((safe_unary_minus_func_int16_t_s(((l_543[9] = (safe_rshift_func_int8_t_s_u((g_1184 = (l_560 > (safe_rshift_func_int16_t_s_s((((safe_unary_minus_func_uint16_t_u((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s(l_322.f2, (safe_rshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(((l_321 != (safe_sub_func_int32_t_s_s(l_541, g_1184))) <= (((0xE7L || l_321) & l_319) <= l_58[4])), l_541)), 6)))) != l_542[4]), g_740)))) && 0x87L) & l_323.f3), 6)))), g_217[0].f1))) >= 0x1377L))) || g_740), l_323.f2))) & g_740), l_372)) ^ j)) || l_322.f1) | 0x47B1ED3EL)) & 0xBBL) == l_321))
                    {
                        uint32_t l_586 = 6UL;
                        g_40[0] = (safe_mod_func_int32_t_s_s((((safe_rshift_func_int8_t_s_s(0x1AL, 6)) != 0x9A7E1DFBL) != 0UL), (((safe_rshift_func_int16_t_s_u(l_543[1], (safe_sub_func_uint32_t_u_u((safe_sub_func_int8_t_s_s((((safe_mod_func_uint16_t_u_u(l_541, l_216[5][2][4].f1)) ^ (((safe_sub_func_int8_t_s_s(((((g_740 = g_1184) & g_1184) >= (safe_add_func_uint8_t_u_u((l_543[1] == g_2317), l_322.f3))) != g_1184), 0xC4L)) <= l_322.f4) | l_560)) || l_347), 0xB3L)), g_740)))) & l_453) & l_322.f3)));
                        g_40[1] = (l_321 || (safe_mod_func_int8_t_s_s((((((safe_lshift_func_uint8_t_u_u(l_322.f2, (((safe_mod_func_uint16_t_u_u(g_1184, (((l_322.f4 = (((safe_add_func_uint8_t_u_u((safe_add_func_uint16_t_u_u(((((-9L) && ((safe_add_func_int16_t_s_s((0L != (safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_u((l_322.f5 == (((safe_rshift_func_uint8_t_u_u((l_784 = l_441), 5)) || (safe_lshift_func_uint8_t_u_s((((((safe_add_func_int32_t_s_s((0xC539F0A9L < (((safe_sub_func_uint8_t_u_u(l_441, g_740)) ^ 251UL) <= l_321)), 1L)) <= 0x34L) > 6L) <= l_322.f4) ^ g_740), l_441))) & 0L)), 8)), 0x94468146L))), g_740)) ^ g_740)) ^ l_585) > 0x3969L), 0UL)), l_441)) | l_322.f0) || l_321)) | l_541) && (-6L)))) && l_372) != 0xAAD2AD68L))) ^ l_441) ^ g_1184) > l_321) < 1UL), 255UL)));
                        if (l_322.f3)
                            continue;
                        l_586 = l_251.f1;
                    }
                    else
                    {
                        l_322.f2 = i;
                        l_322.f2 = l_322.f5;
                    }
                    if ((safe_rshift_func_int16_t_s_s((l_543[1] <= (+2UL)), (safe_mod_func_int8_t_s_s((l_368 && (0x7D100E82L < (l_542[4] <= ((((safe_rshift_func_int16_t_s_u(((0x4E4BL && l_58[2]) ^ ((0x2E7EE68AL <= (((safe_add_func_uint32_t_u_u((l_322.f0 = (((l_543[9] >= l_216[5][2][4].f1) | g_740) && l_321)), g_1184)) == (-1L)) && g_740)) >= l_560)), 6)) || l_596) | 0x05L) == l_441)))), l_62)))))
                    {
                        int8_t l_598 = 0xBFL;
                        g_217[0] = l_597;
                        l_322.f3 = g_1184;
                        if (g_174)
                            continue;
                        l_598 = 0L;
                    }
                    else
                    {
                        if (l_321)
                            break;
                        return l_543[7];
                    }
                }
                else
                {
                    return g_740;
                }
                l_323.f1 = (l_322.f5 < ((g_1184 = ((((((safe_rshift_func_int8_t_s_s(((((safe_add_func_uint32_t_u_u(((safe_add_func_int32_t_s_s(((l_340 != (safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u(((g_1184 >= (0x10F51F9BL != ((0x3DL ^ (((g_1135 = (l_322.f3 = (l_784 = (safe_add_func_int16_t_s_s((l_372 = l_368), (((l_62 = l_784) || (-8L)) >= (safe_rshift_func_uint16_t_u_u(l_612, 7)))))))) != l_322.f4) > 0xC9L)) || l_332))) ^ 0x3B09CD00L))), 9))) ^ g_740), 7L)) != 0x1291L), 0x2F13D676L)) || l_323.f0) > 0x17L) > 0xEAL), 0)) & 0xCA0E249EL) | g_40[1]) && g_1184) | g_1184) == i)) | g_740));
                l_323.f3 = (((safe_lshift_func_uint16_t_u_u((((safe_lshift_func_uint16_t_u_u((safe_sub_func_int8_t_s_s(l_321, (safe_rshift_func_int16_t_s_u((0x862CB02EL && l_321), (l_322.f3 = (safe_mod_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u(l_333, (safe_rshift_func_int8_t_s_u(0x17L, ((g_740 != (g_1184 = (safe_add_func_uint16_t_u_u(l_321, l_323.f3)))) & l_784))))), 0x2B79L))))))), l_321)) ^ l_321) >= (-7L)), l_542[1])) ^ l_322.f1) >= i);
            }
        }
    }
    if ((g_217[0].f1 = (l_441 > ((l_216[5][2][4].f1 = ((g_740 = (l_251.f3 = (((safe_rshift_func_int16_t_s_u(l_251.f2, (safe_mod_func_int16_t_s_s(l_321, ((l_321 = (((safe_add_func_uint8_t_u_u(((safe_sub_func_uint16_t_u_u(l_251.f1, (g_740 <= (l_560 = ((safe_lshift_func_int16_t_s_u(((g_40[1] = (safe_sub_func_uint8_t_u_u((safe_add_func_int16_t_s_s((g_40[1] & ((((0UL && (g_1058 = (safe_unary_minus_func_uint32_t_u((safe_mod_func_int32_t_s_s((g_1184 & 0x79L), 2L)))))) & l_322.f2) < 0x92L) | g_1184)), l_322.f3)), 0xDAL))) < l_441), g_1184)) <= l_441))))) || 255UL), 6L)) || 0x03L) | l_321)) | g_1184))))) >= 0x1950L) > i))) && l_450)) && l_441))))
    {
        uint8_t l_648 = 1UL;
        return l_648;
    }
    else
    {
        uint32_t l_662 = 1UL;
        int32_t l_666 = 0x898FEB7AL;
        int32_t l_667 = 0x738C6A61L;
        uint8_t l_842 = 0xBBL;
        struct S0 l_956 = {0x978E043CL,-1705};
        if (l_441)
        {
            uint8_t l_651 = 1UL;
            struct S1 l_657 = {101,-0,14313,-45,32,110};
            if (((l_784 = (((safe_sub_func_uint16_t_u_u((g_1184 ^ ((((((l_651 & l_652) <= (l_216[5][2][4].f1 = (safe_lshift_func_int16_t_s_u(l_320[3][0][4], ((l_441 ^ (g_1135 = 0UL)) ^ 4L))))) == 0xC3D04E26L) != j) <= g_237) != g_217[0].f1)), g_1184)) < l_441) || 0x677223E7L)) | 0x17L))
            {
                struct S1 l_655 = {224,20,14000,-67,46,41};
                l_322 = (l_657 = (l_322 = (l_322 = l_655)));
            }
            else
            {
                uint16_t l_661 = 0x6EA5L;
                int32_t l_671 = (-9L);
                if ((l_662 = (safe_rshift_func_uint8_t_u_u(g_740, l_661))))
                {
                    int32_t l_669 = 0x7D1AE5F8L;
                    for (g_1184 = 27; (g_1184 > (-25)); g_1184--)
                    {
                        uint32_t l_665 = 0xE8B9A2A8L;
                        int32_t l_668[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_668[i] = 0x75128752L;
                        l_667 = (l_666 = l_665);
                        l_322.f1 = (l_668[1] = (l_251.f1 = l_665));
                        l_669 = g_740;
                        l_62 = g_1184;
                    }
                    if (l_321)
                    {
                        return l_321;
                    }
                    else
                    {
                        return l_441;
                    }
                }
                else
                {
                    uint32_t l_670 = 1UL;
                    l_671 = (l_670 = l_661);
                    l_657.f3 = (safe_lshift_func_int8_t_s_u(l_662, l_251.f4));
                }
            }
        }
        else
        {
            uint16_t l_685 = 0UL;
            int32_t l_737[5][10] = {{1L, 0x31256A9DL, 7L, 7L, 0x31256A9DL, 1L, 2L, 0xD88782CBL, 0L, 2L}, {1L, 0x31256A9DL, 7L, 7L, 0x31256A9DL, 1L, 2L, 0xD88782CBL, 0L, 2L}, {1L, 0x31256A9DL, 7L, 7L, 0x31256A9DL, 1L, 2L, 0xD88782CBL, 0L, 2L}, {1L, 0x31256A9DL, 7L, 7L, 0x31256A9DL, 1L, 2L, 0xD88782CBL, 0L, 2L}, {1L, 0x31256A9DL, 7L, 7L, 0x31256A9DL, 1L, 2L, 0xD88782CBL, 0L, 2L}};
            int32_t l_772 = 5L;
            int i, j;
            for (l_667 = 0; (l_667 <= 2); l_667 += 1)
            {
                struct S1 l_789 = {205,17,-3036,5,156,142};
                int i;
                l_674 = l_322;
                g_40[l_667] = l_441;
                if ((safe_sub_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_s((((safe_sub_func_int16_t_s_s(((g_40[l_667] = (l_321 || (safe_rshift_func_uint8_t_u_s((safe_lshift_func_int16_t_s_u(((((((g_40[l_667] || (248UL || l_666)) || l_685) != (l_321 != ((safe_unary_minus_func_uint8_t_u((l_784 = ((((+0x0FL) != 0x73L) & (g_1058 = (l_441 ^ l_322.f5))) ^ 4UL)))) && l_322.f1))) & l_322.f0) == 1UL) && l_321), l_666)), 3)))) >= l_685), 0UL)) != l_321) || l_322.f4), 5)) >= l_322.f5), g_217[0].f0)))
                {
                    int32_t l_713[1];
                    int32_t l_715[1];
                    struct S1 l_788 = {162,11,-9528,76,126,34};
                    struct S0 l_790 = {0xEACA67FEL,-2018};
                    int i;
                    for (i = 0; i < 1; i++)
                        l_713[i] = (-1L);
                    for (i = 0; i < 1; i++)
                        l_715[i] = 7L;
                    l_666 = g_40[l_667];
                    l_216[5][2][4] = g_1896;
                    if ((safe_sub_func_int8_t_s_s((safe_mod_func_uint8_t_u_u(0x86L, l_685)), ((safe_add_func_int32_t_s_s((((l_713[0] = (l_322.f0 && ((((safe_rshift_func_uint16_t_u_s((l_666 = (l_251.f3 = (!(safe_add_func_uint16_t_u_u((g_1184 <= ((g_1178 = (safe_unary_minus_func_uint32_t_u((g_1135 & (safe_sub_func_int16_t_s_s(l_322.f5, (safe_rshift_func_int16_t_s_u(((safe_add_func_int16_t_s_s(((safe_sub_func_int32_t_s_s(l_685, 1UL)) ^ (safe_lshift_func_int16_t_s_u((safe_sub_func_int8_t_s_s((((((((g_740 > 0L) != g_1184) || l_713[0]) || l_58[4]) & l_321) > l_441) ^ g_174), l_322.f3)), g_40[l_667]))), l_685)) | g_174), 7)))))))) & g_40[l_667])), 65526UL))))), l_322.f1)) || l_322.f4) == l_662) && 0x040FL))) >= l_667) == l_715[0]), g_740)) != l_662))))
                    {
                        uint8_t l_758 = 0UL;
                        int32_t l_773 = 9L;
                        l_322.f2 = (((+((safe_lshift_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(((((g_40[l_667] = (safe_sub_func_uint32_t_u_u((g_740 = ((safe_add_func_uint8_t_u_u(((1UL == ((((g_1178 && 0x80L) == (safe_mod_func_int16_t_s_s((+(l_322.f3 = (((l_322.f4 = ((l_321 == ((safe_sub_func_uint32_t_u_u(((safe_mod_func_int32_t_s_s(((!(((l_321 != (+((~((safe_sub_func_int8_t_s_s(l_321, (l_737[3][3] != ((safe_sub_func_int32_t_s_s(l_685, g_217[0].f1)) < 0L)))) <= 0L)) < l_441))) || i) | g_174)) < 0xFC57L), l_321)) >= l_441), g_740)) || l_441)) == g_1178)) <= l_713[0]) > l_441))), l_322.f3))) <= g_174) != 254UL)) ^ 0xA28A1E5FL), 0x79L)) && 0x4DL)), l_441))) || 0xF26FL) && 0xDB531D12L) && l_737[1][2]), l_322.f4)), 12)) & g_1184)) || j) == 0x93CBL);
                        l_666 = ((((((0x01DBL >= (safe_add_func_int16_t_s_s(((safe_sub_func_int8_t_s_s((l_62 = ((g_1184 = 0xB0L) <= ((g_40[l_667] = ((safe_sub_func_int16_t_s_s((l_321 | ((safe_rshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_u((safe_unary_minus_func_int16_t_s((l_322.f2 && ((safe_add_func_int8_t_s_s((l_251.f0 ^ (((((l_737[3][3] = (3L < (safe_rshift_func_int8_t_s_s(0xE8L, 6)))) >= 0xE6CEL) | l_58[4]) <= l_758) >= l_321)), 0x13L)) >= l_441)))), l_685)), 1)) == (-1L))), (-1L))) >= l_62)) || l_441))), l_441)) <= l_321), 0x125FL))) <= 0L) > l_321) && 0x88C7L) < g_740) >= l_441);
                        l_772 = ((0xB5CFBE9DL > (l_666 = (((g_40[l_667] = g_740) != (safe_add_func_uint8_t_u_u(l_758, ((((0xA9L ^ ((safe_rshift_func_uint16_t_u_s((safe_mod_func_int16_t_s_s(g_1184, (safe_rshift_func_uint8_t_u_s(l_322.f5, g_217[0].f0)))), 5)) < ((l_737[3][3] = ((safe_sub_func_uint8_t_u_u((safe_add_func_int16_t_s_s(1L, ((g_740 | 0x26EF1429L) | l_715[0]))), 255UL)) | l_441)) < l_321))) || l_758) <= l_322.f5) == l_758)))) | g_1178))) == 1L);
                        l_773 = 0xDC06628CL;
                    }
                    else
                    {
                        uint16_t l_787 = 0x9C7CL;
                        l_772 = ((safe_lshift_func_int16_t_s_u(0xDC95L, 0)) || (((((!(!(l_772 > ((safe_sub_func_int32_t_s_s((l_715[0] = (0xFB8B5851L && (safe_mod_func_uint32_t_u_u((l_666 = l_321), (safe_add_func_int16_t_s_s((-7L), (0x1189L <= l_784))))))), l_713[0])) > ((safe_rshift_func_uint8_t_u_s(g_174, 2)) <= l_713[0]))))) || g_174) & 0x0506L) != 0xD8L) >= l_787));
                        l_789 = l_788;
                        g_217[0] = l_790;
                    }
                }
                else
                {
                    for (l_62 = (-2); (l_62 > (-22)); l_62 = safe_sub_func_uint8_t_u_u(l_62, 5))
                    {
                        return l_251.f2;
                    }
                    return l_322.f2;
                }
            }
            l_737[1][1] = (((((safe_add_func_int16_t_s_s((((safe_lshift_func_int8_t_s_u(g_1184, 6)) < l_322.f5) ^ (l_321 || ((g_740 & (l_322.f5 & l_441)) && ((safe_mod_func_uint32_t_u_u((safe_mod_func_uint16_t_u_u(((+((g_1058 == (l_322.f5 > (!l_441))) != 0UL)) && g_1058), 0x16EEL)), l_251.f2)) | (-1L))))), l_666)) & g_40[1]) <= l_322.f3) | 0x4332143FL) || (-7L));
        }
        if ((((l_251.f3 = (safe_lshift_func_int16_t_s_s(g_1184, (safe_sub_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((((0x19L & l_322.f1) & (safe_unary_minus_func_uint16_t_u((((safe_mod_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s((((safe_lshift_func_int16_t_s_u((safe_add_func_uint16_t_u_u((l_441 ^ g_40[1]), (0L ^ l_322.f3))), (safe_mod_func_uint32_t_u_u((safe_mod_func_uint16_t_u_u(((((safe_rshift_func_int16_t_s_u(j, l_321)) & l_321) == g_740) < g_740), (-6L))), 0x4BE9801AL)))) || l_322.f1) | 0xF5L), l_322.f1)) > 0x83681970L), l_62)) < l_824) ^ 0x6EL)))) || 8UL) || l_320[4][0][2]), l_652)), l_62))))) & 0x755A4503L) > 7L))
        {
            l_216[5][2][4].f1 = l_784;
            return l_320[5][0][1];
        }
        else
        {
            uint8_t l_837 = 0xE3L;
            int32_t l_845[10] = {0x30602858L, 0x857EE561L, 0x30602858L, 0x857EE561L, 0x30602858L, 0x857EE561L, 0x30602858L, 0x857EE561L, 0x30602858L, 0x857EE561L};
            int32_t l_865 = 0x40867A90L;
            uint32_t l_868[6] = {1UL, 0x76233594L, 1UL, 0x76233594L, 1UL, 0x76233594L};
            struct S1 l_869 = {65,6,-13417,-17,32,59};
            int32_t l_885 = 5L;
            struct S0 l_937 = {0x5BEEEA9BL,-429};
            int i;
            for (g_740 = 0; (g_740 <= 37); ++g_740)
            {
                uint16_t l_831 = 65527UL;
                int32_t l_834 = 0x4BD17104L;
                int32_t l_843 = 0xD9FA71C5L;
                if ((!(safe_sub_func_uint16_t_u_u((~(l_831 = 0x2A44E312L)), (+(((+(((g_740 ^ (((l_662 && l_322.f0) >= (l_834 = g_217[0].f1)) > (safe_mod_func_uint8_t_u_u((l_667 == ((l_216[5][2][4].f1 = ((l_837 != 0xEDL) ^ ((safe_rshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s((0xAEEAL <= l_322.f3), l_321)), l_842)) == 0x1FL))) > l_322.f4)), (-4L))))) > l_843) ^ 0x40L)) < l_843) < 0x7E2EL))))))
                {
                    int8_t l_844 = 0x78L;
                    l_216[3][1][2] = g_217[0];
                    l_845[2] = l_844;
                }
                else
                {
                    int16_t l_864 = (-1L);
                    int32_t l_886 = (-1L);
                    l_865 = (g_1184 || (safe_rshift_func_int16_t_s_s((((safe_unary_minus_func_int8_t_s((((safe_mod_func_uint32_t_u_u((((safe_mod_func_int8_t_s_s((safe_lshift_func_int8_t_s_u((l_674.f1 < g_237), l_666)), (l_784 & l_322.f5))) == (safe_mod_func_int16_t_s_s((((safe_add_func_int16_t_s_s(((l_845[2] = (j == l_845[5])) != ((safe_lshift_func_int16_t_s_s((l_863 = ((safe_sub_func_int32_t_s_s(1L, 3L)) >= l_824)), 3)) | 0x6F77L)), g_1184)) < l_837) ^ 1UL), g_217[0].f1))) != 0x8767L), 4294967295UL)) & l_837) | l_322.f4))) <= l_864) == l_824), l_322.f2)));
                    for (l_843 = 6; (l_843 == 21); l_843 = safe_add_func_int8_t_s_s(l_843, 4))
                    {
                        uint16_t l_872 = 0xC883L;
                        l_868[3] = l_843;
                        l_322 = l_869;
                        l_834 = ((((g_1058 <= ((((safe_rshift_func_int8_t_s_u(l_872, (((l_322.f2 | (safe_rshift_func_uint8_t_u_u(((l_886 = ((((0x59EBL != g_1058) < ((safe_add_func_int32_t_s_s((((g_740 > (safe_mod_func_int8_t_s_s(((g_1184 = (safe_rshift_func_int16_t_s_s(l_322.f1, ((g_740 || (safe_rshift_func_uint16_t_u_u((g_1058 >= l_884[4]), 10))) < 0x03L)))) != l_885), 255UL))) == 0L) <= 255UL), l_441)) > g_740)) < l_831) & l_441)) != l_864), l_321))) & l_831) != l_321))) == l_560) != l_441) != 1UL)) < l_864) || g_1058) ^ 0xAF596846L);
                    }
                    l_251.f1 = (l_62 = 0x2802AEF7L);
                    if (((((safe_sub_func_int16_t_s_s((-1L), (l_886 = (6UL | l_322.f2)))) ^ 0x2E139A74L) | (l_864 | (safe_rshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s((safe_lshift_func_int8_t_s_s((((+(l_322.f3 = (((!(l_62 = (safe_add_func_uint32_t_u_u((((~(l_321 = l_842)) & (g_174 = 0L)) | (l_322.f2 <= ((safe_add_func_int16_t_s_s(4L, l_322.f5)) | 0x6DL))), l_322.f2)))) && l_321) == l_251.f4))) || g_1058) > l_441), l_834)), g_740)), 7)))) && 0L))
                    {
                        uint32_t l_903 = 0UL;
                        l_903 = (-1L);
                        l_674 = l_322;
                        l_322.f1 = ((safe_rshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_s((l_320[1][0][3] ^ (((l_251.f3 = 0x1401L) ^ (l_322.f1 & (safe_mod_func_uint8_t_u_u((safe_add_func_int8_t_s_s(((g_1184 < (safe_rshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_s((l_321 = (safe_lshift_func_uint16_t_u_u((l_321 = ((safe_add_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u(g_1184, (!((((0x6F3E371DL < (l_251.f1 = (safe_mod_func_uint16_t_u_u(1UL, l_652)))) & (safe_mod_func_int32_t_s_s((l_886 = ((((+((((safe_add_func_int16_t_s_s((l_666 = (safe_mod_func_int16_t_s_s((l_666 && l_441), l_843))), l_321)) || 65530UL) && 1UL) >= 0xFBA8L)) > g_174) <= 0x54L) & 0xD6L)), g_1058))) > l_864) && l_58[4])))), g_217[0].f0)), 4294967295UL)) != 0UL)), g_740))), g_1184)), l_322.f1))) ^ 0UL), g_174)), 0x56L)))) && l_441)), 6)), 13)) < l_322.f3);
                    }
                    else
                    {
                        l_674.f1 = ((safe_rshift_func_uint16_t_u_s((+l_831), 8)) == (l_322.f1 | (l_322.f5 = g_1184)));
                        if (l_834)
                            break;
                    }
                }
                g_1896 = l_937;
                l_834 = (safe_mod_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s(((!l_834) != (g_740 ^ (l_62 = ((((safe_unary_minus_func_int16_t_s(g_217[0].f0)) == (l_322.f2 & ((safe_rshift_func_uint8_t_u_s(((safe_lshift_func_uint8_t_u_u(((((g_1135 = 0x36L) || g_1178) < (!((((((l_674.f1 = (safe_mod_func_uint32_t_u_u((g_1184 | ((l_843 = (l_845[0] = ((safe_unary_minus_func_int8_t_s(8L)) && (0x85L > l_869.f4)))) < 0x85L)), l_441))) || l_322.f4) || g_40[1]) ^ j) < g_217[0].f0) ^ 0x1EL))) || (-1L)), 4)) < l_322.f4), l_441)) == l_322.f1))) ^ l_216[5][2][4].f1) && l_322.f1)))), g_740)), l_869.f2));
            }
            g_1058 = (safe_add_func_int16_t_s_s(g_1184, (-1L)));
            l_937 = l_956;
        }
    }
    g_1058 = g_1058;
    return l_322.f1;
}

                    return g_2214;
                }
                l_323.f1 = (l_674.f5 < ((g_1184 = ((((((safe_rshift_func_int8_t_s_s(((((safe_add_func_uint32_t_u_u(((safe_add_func_int32_t_s_s(((l_340 != (safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u(((g_1184 >= (0x10F51F9BL != ((0x3DL ^ (((g_3662 = (l_322.f3 = (l_784 = (safe_add_func_int16_t_s_s((l_372 = l_368), (((j = l_784) || (-8L)) >= (safe_rshift_func_uint16_t_u_u(l_612, 7)))))))) != l_674.f4) > 0xC9L)) || l_332))) ^ 0x3B09CD00L))), 9))) ^ g_63), 7L)) != 0x1291L), 0x2F13D676L)) || l_323.f0) > 0x17L) > 0xEAL), 0)) & 0xCA0E249EL) | g_40[1]) && g_1184) | g_1184) == j)) | g_63));
                l_323.f3 = (((safe_lshift_func_uint16_t_u_u((((safe_lshift_func_uint16_t_u_u((safe_sub_func_int8_t_s_s(g_163, (safe_rshift_func_int16_t_s_u((0x862CB02EL && g_163), (l_322.f3 = (safe_mod_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u(l_333, (safe_rshift_func_int8_t_s_u(0x17L, ((g_2214 != (g_1184 = (safe_add_func_uint16_t_u_u(g_163, l_323.f3)))) & l_784))))), 0x2B79L))))))), g_163)) ^ g_163) >= (-7L)), l_542[1])) ^ l_322.f1) >= j);
            }
        }
    }

                    for (g_112 = (-12); (g_112 != 28); g_112++)
                    {
                        int16_t l_161 = (-3L);
                        int32_t l_162[7][4] = {{0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}, {0x4C5083F6L, 1L, (-1L), (-1L)}};
                        int i, j;
                        l_162[2][2] = (safe_sub_func_int32_t_s_s((g_130.f0 <= (g_130.f1 = ((l_126 = ((p_34 >= ((safe_sub_func_int16_t_s_s(((l_156[3] < (0xD5L == (((p_34 < (safe_sub_func_uint8_t_u_u((l_161 = ((l_62 = ((g_75 == 1UL) != l_60)) && (((safe_sub_func_uint16_t_u_u(0xF7D0L, g_2.f3)) ^ l_58[4]) == p_35))), l_162[2][2]))) == 0UL) == l_162[2][2]))) > 0x97L), 4UL)) <= g_163)) < l_123)) >= l_60))), p_34));
                        g_2.f3 = ((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u((g_2.f0 == (safe_sub_func_int8_t_s_s(((g_163 = g_40[2]) != 0x2DD9L), (safe_sub_func_uint16_t_u_u((l_156[3] ^ (safe_lshift_func_int16_t_s_u((g_174 = (8UL > (2UL == (0x66ACL ^ (((-1L) < l_156[3]) < g_75))))), l_175))), 1L))))), 7)), l_156[5])) == 0x0657D6C4L);
                    }
                }
                else
                {
                    struct S0 l_180[1][5][8] = {{{{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}, {{0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}, {0L,-838}, {0L,1893}, {5L,1681}, {0L,1893}}}};
                    int16_t l_213 = (-1L);
                    int i, j, k;
                    for (l_122 = (-18); (l_122 != (-3)); l_122++)
                    {
                        int32_t l_179 = (-1L);
                        l_179 = (l_178 = p_34);
                        if (l_179)
                            {
{
                        int8_t l_1498[9][6][4] = {{{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}, {{0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}, {0x76L, 0x0DL, (-6L), 0x92L}}};
                        int32_t l_1503 = 0x172577FDL;
                        int i, j, k;
                        p_34 = 0L;
                        g_759 = ((safe_lshift_func_uint16_t_u_u((((safe_sub_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_u((l_213 = (6UL ^ (l_61 && 6UL))), 0)) < ((-1L) | l_1498[5][2][2])), l_1498[3][2][2])) ^ ((safe_mod_func_int32_t_s_s(((safe_sub_func_uint32_t_u_u(g_759, (l_1503 = (((i > 1UL) <= l_213) & 255UL)))) != 1UL), 2L)) | g_163)) | g_274.f0), 12)) ^ l_824);
                    }

                    continue;}

for (g_75 = 0; g_75 < 6; g_75++)
        {
if (g_1895.f0)
                    break;

                    l_58[g_75] = 1UL;}

                    g_130 = (l_180[0][2][4] = g_130);
                    }
                    g_2.f2 = (safe_add_func_uint32_t_u_u(((((p_34 = l_60) <= ((safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u(g_130.f0, g_2.f2)), g_2.f2)) ^ (safe_add_func_int16_t_s_s((((safe_add_func_int32_t_s_s(((safe_mod_func_uint16_t_u_u((safe_mod_func_int8_t_s_s((safe_unary_minus_func_int8_t_s((((((safe_add_func_uint8_t_u_u(g_174, g_2.f3)) || (safe_sub_func_int16_t_s_s((l_212[4] = (safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s((((((g_211 = (l_210 = ((safe_lshift_func_uint16_t_u_s(((0x96262B8EL == p_37) > ((safe_mod_func_int32_t_s_s((g_75 < l_62), p_37)) ^ p_37)), 1)) >= g_75))) | g_112) & p_36) && g_163) >= 0x7B1EL), p_37)), l_122)), p_35))), g_69))) | l_213) & 255UL) <= g_2.f3))), 253UL)), g_75)) & 4L), 4UL)) && g_75) || 0x7BL), l_180[0][2][4].f1)))) >= p_36) || p_37), (-6L)));
                    g_40[1] = g_63;
                }
            }
        }
        else
        {
            int32_t l_232 = 0L;
            for (g_63 = 0; (g_63 >= 11); g_63++)
            {
                int32_t l_218 = 0xD9B91490L;
                uint8_t l_227 = 254UL;
                g_217[0] = (g_130 = l_216[5][2][4]);
                for (l_61 = 0; (l_61 <= 5); l_61 += 1)
                {
                    uint16_t l_219 = 0x791FL;
                    struct S0 l_220[4] = {{0x34A1C847L,71}, {-1L,1107}, {0x34A1C847L,71}, {-1L,1107}};
                    int32_t l_234 = 1L;
                    int i;
                    for (p_36 = 4; (p_36 >= 1); p_36 -= 1)
                    {
                        int i;
                        if (l_58[p_36])
                            break;
                        l_218 = ((-1L) <= p_34);
                        l_210 = l_219;
                    }
                    g_217[0] = l_220[1];
                    for (l_122 = 0; (l_122 <= 5); l_122 += 1)
                    {
                        uint8_t l_233 = 0UL;
                        l_234 = (g_63 <= (safe_mod_func_uint8_t_u_u(((-9L) && (((!((p_34 = (g_224 = 4294967288UL)) != ((l_220[1].f1 = (safe_mod_func_int16_t_s_s(((l_227 ^ (((0xCDL || ((0xA2A9L < ((safe_lshift_func_int8_t_s_u(((p_37 ^ l_210) > ((l_232 = (0x87C8L || p_35)) & g_130.f1)), l_58[3])) != p_35)) < 0x96L)) != l_62) && g_69)) < g_2.f5), 0x45C8L))) > 1UL))) | 9UL) < 1UL)), l_233)));
                    }
                }
            }
        }
        for (g_75 = 23; (g_75 != (-30)); --g_75)
        {
            return l_216[5][2][4].f0;
        }
        l_62 = ((g_237 = g_2.f2) | (5L == l_238));
    }
    else
    {
        int8_t l_243 = 7L;
        uint16_t l_270 = 1UL;
        int32_t l_293 = 0x4223055EL;
        uint32_t l_300 = 0x6A80E99DL;
        uint16_t l_302 = 3UL;
        g_130.f1 = (g_2.f4 <= ((safe_mod_func_int8_t_s_s(((0x0902586CL != (0x0F0FC9D2L && l_216[5][2][4].f1)) <= 1L), (65535UL & ((safe_sub_func_uint32_t_u_u((p_34 = l_243), (0x78L || (!(l_62 = (safe_sub_func_int16_t_s_s((safe_add_func_int32_t_s_s((safe_lshift_func_int16_t_s_u((0x4FL < 0x57L), p_37)), p_37)), p_36))))))) == 0x74A4447EL)))) || g_217[0].f0));
                                       int16_t BIJIJml_251_f1 = (~(((((~(l_122)) % (~(l_251.f5))) || (l_251.f1 | g_112)) << (((g_274.f1 | (~(l_62))) * (g_274.f2 || (~((~(g_759)))))) || (~((g_658.f3 ^ l_251.f4)))))));
int32_t BIJIJng_274_f2 = (~(((~((l_122 | (~((l_251.f1 ^ l_62)))))) * (~((((l_251.f4 | (~((g_658.f3 * l_251.f5)))) + ((~(g_759)) & g_274.f1)) % ((g_274.f2 | BIJIJml_251_f1) & (~((~(g_112)))))))))));
uint16_t BIJIJog_112 = (~(((~((l_122 | (~(g_759))))) | (((~((BIJIJml_251_f1 + BIJIJng_274_f2))) * (l_251.f1 || g_274.f2)) || (~((((l_251.f4 * (g_658.f3 + (~(l_251.f5)))) | g_274.f1) | (g_112 | l_62))))))));
int32_t BIJIJpl_62 = (~(((((~(((((~(g_274.f2)) % (l_62 ^ (g_274.f1 ^ (BIJIJng_274_f2 & g_112)))) || BIJIJml_251_f1) | l_251.f5))) ^ (~((~(BIJIJog_112))))) ^ (~((~(l_122))))) % (~((g_658.f3 ^ (~((~((g_759 | (l_251.f4 | (~(l_251.f1))))))))))))));
uint16_t BIJIJql_251_f4 = (~(((((BIJIJpl_62 * g_658.f3) | ((BIJIJog_112 | g_759) & (~((l_62 & l_251.f1))))) * ((~(((~((~(g_274.f2)))) & (~((~(g_274.f1))))))) | (~((~(BIJIJng_274_f2)))))) | (~((~(((BIJIJml_251_f1 + g_112) * ((l_251.f5 * l_251.f4) % (~((~(l_122)))))))))))));
int32_t BIJIJrg_759 = (~((((~(BIJIJml_251_f1)) | g_274.f2) ^ ((((~(g_759)) ^ (l_251.f4 * g_112)) & ((BIJIJpl_62 ^ (l_251.f1 | (l_122 | BIJIJql_251_f4))) * ((~((~((l_251.f5 & BIJIJng_274_f2))))) % (BIJIJog_112 % (~(((~((~(g_274.f1)))) & l_62))))))) ^ g_658.f3))));
                               int32_t B5J5Jg_759 = (~(((((g_759 | l_302) | (~((~(l_674.f4))))) | g_174) | ((~(((l_300 | (~((~(l_62))))) + (l_251.f3 % (~((g_658.f3 + g_274.f0))))))) & g_2.f5))));
uint16_t B5J5Jbg_274_f0 = (~((((~((g_658.f3 - (~(g_274.f0))))) % l_251.f3) & (((g_2.f5 >> l_674.f4) | (~((~((g_174 + (~((~(l_62)))))))))) | ((~(g_759)) + ((B5J5Jg_759 / l_302) ^ l_300))))));
uint32_t B5J5Jcg_174 = (~(((~(((g_274.f0 - ((l_62 | ((g_759 & l_302) & l_251.f3)) & (~((l_300 & g_174))))) - (~((~((((B5J5Jbg_274_f0 - g_2.f5) / l_674.f4) / (~(B5J5Jg_759)))))))))) / g_658.f3)));
uint32_t B5J5Jdl_300 = (~(((((~(((~(l_674.f4)) ^ (~(l_302))))) | (~(B5J5Jcg_174))) % ((~(((~((~(l_62)))) & ((B5J5Jbg_274_f0 % g_274.f0) % l_300)))) << (B5J5Jg_759 / g_2.f5))) | (~((~((~((~((((~(g_658.f3)) >> (g_174 / l_251.f3)) & g_759))))))))))));
int16_t B5J5Jeg_658_f3 = (~(((((~((l_62 ^ (~((g_2.f5 - g_759)))))) % (~(B5J5Jdl_300))) ^ (l_251.f3 ^ (((l_302 ^ (~(B5J5Jcg_174))) / g_658.f3) % (~(B5J5Jg_759))))) | (((~(l_300)) + g_174) | (~(((~(g_274.f0)) & (l_674.f4 ^ B5J5Jbg_274_f0))))))));
uint32_t B5J5Jfg_2_f5 = (~(((((~((((B5J5Jeg_658_f3 % (~(g_759))) / (g_2.f5 % ((~(B5J5Jbg_274_f0)) - g_174))) | (~(g_658.f3))))) | ((~(g_274.f0)) | B5J5Jcg_174)) / (~((l_251.f3 ^ l_302)))) % ((l_674.f4 % (~(l_300))) ^ ((~(B5J5Jg_759)) + (~((l_62 ^ B5J5Jdl_300))))))));
if(((l_251.f3 < g_759) || (B5J5Jg_759<=0))){
B5J5Jg_759 = g_759;
B5J5Jbg_274_f0 = g_274.f0;
B5J5Jcg_174 = g_174;
B5J5Jdl_300 = l_300;
B5J5Jeg_658_f3 = g_658.f3;
B5J5Jfg_2_f5 = g_2.f5;
g_759 = (~((((~((~((g_2.f5 >> l_674.f4))))) + ((B5J5Jeg_658_f3 ^ g_658.f3) ^ (~(g_274.f0)))) / (~((((~((((~(B5J5Jbg_274_f0)) | (l_62 / (~(g_174)))) + (((l_251.f3 % g_759) & (B5J5Jcg_174 + l_300)) | ((~(B5J5Jdl_300)) % B5J5Jg_759))))) - (~(B5J5Jfg_2_f5))) | (~((~((~(l_302))))))))))));
g_274.f0 = (~((((~(l_62)) & (((((~(l_300)) + (B5J5Jeg_658_f3 | (~(l_302)))) % ((B5J5Jbg_274_f0 % l_251.f3) - (~((~(g_2.f5)))))) ^ ((g_174 & B5J5Jfg_2_f5) + B5J5Jg_759)) + (B5J5Jcg_174 | ((~((g_658.f3 % l_674.f4))) + g_759)))) / (~((B5J5Jdl_300 | g_274.f0))))));
g_174 = (~((((((~(((~(g_658.f3)) + (~(B5J5Jfg_2_f5))))) ^ (~((B5J5Jcg_174 % g_2.f5)))) | ((~((B5J5Jbg_274_f0 + ((~(g_759)) | B5J5Jeg_658_f3)))) % (~(((l_300 | l_674.f4) % (~(l_62))))))) - (((~(g_174)) ^ ((~((~(g_274.f0)))) + B5J5Jdl_300)) % (l_302 + l_251.f3))) % (~(B5J5Jg_759)))));
l_300 = (~(((~(((~((g_174 % (B5J5Jg_759 & B5J5Jeg_658_f3)))) / (~((((~(g_759)) | ((~((g_658.f3 ^ g_274.f0))) + ((~((l_62 % g_2.f5))) - (B5J5Jfg_2_f5 ^ B5J5Jdl_300)))) + (~((((l_302 ^ (~((~(B5J5Jbg_274_f0))))) | (l_300 - l_674.f4)) & B5J5Jcg_174))))))))) - (~((~(l_251.f3)))))));
LABEL_5J5Jg: g_658.f3 = (~(((~(((((~((~(g_274.f0)))) ^ (B5J5Jcg_174 - g_174)) | (~((~(((~(B5J5Jfg_2_f5)) + B5J5Jg_759)))))) / (~(((~(l_251.f3)) ^ (~(g_759)))))))) - (~(((~((~(B5J5Jeg_658_f3)))) + (~((((((~(g_2.f5)) % l_62) | (~(l_674.f4))) + (B5J5Jdl_300 | ((~((l_302 ^ B5J5Jbg_274_f0))) / l_300))) + g_658.f3)))))))));
g_2.f5 = (~(((~((((B5J5Jfg_2_f5 - B5J5Jcg_174) << (~(l_251.f3))) - ((g_174 % B5J5Jg_759) | (((l_674.f4 & l_300) % (~((l_62 & g_759)))) + (((~(l_302)) & ((~(B5J5Jbg_274_f0)) / (~(B5J5Jeg_658_f3)))) - (~(g_274.f0)))))))) | (~(((~(((~(B5J5Jdl_300)) / g_2.f5))) ^ (~((~(g_658.f3))))))))));
if((((!B5J5Jdl_300) || (g_759 > g_658.f3)) || !((g_2.f5>=8)))){
printf("g_759=%lld\n", (long long)g_759);
goto LABEL_rJrJo;
}
if(((!B5J5Jfg_2_f5) && (B5J5Jdl_300 < g_174))){
printf("g_274.f0=%llu\n", (unsigned long long)g_274.f0);
goto LABEL_5J5Jg;
}
if(!(l_62)){
printf("g_174=%llu\n", (unsigned long long)g_174);
g_658.f3 = (~(((~((((~((g_274.f0 >> B5J5Jg_759))) / l_300) + (((((~(B5J5Jeg_658_f3)) - g_2.f5) << l_674.f4) - ((~((((~((~(B5J5Jcg_174)))) - B5J5Jbg_274_f0) ^ g_174))) - g_658.f3)) ^ (((l_302 ^ l_62) ^ B5J5Jdl_300) | l_251.f3))))) ^ (B5J5Jfg_2_f5 - g_759))));
goto LABEL_rJrJn;
}
if((l_251.f3 > B5J5Jeg_658_f3)){
printf("l_300=%llu\n", (unsigned long long)l_300);
goto LABEL_5J5Jg;
}
if(!((l_302<=3))){
printf("g_658.f3=%lld\n", (long long)g_658.f3);
goto LABEL_5J5Jg;
}
if(!(l_62)){
printf("g_2.f5=%llu\n", (unsigned long long)g_2.f5);
B5J5Jdl_300 = (~(((~((~((l_251.f3 << (~(l_302))))))) / ((g_759 % (((~(B5J5Jfg_2_f5)) - B5J5Jbg_274_f0) % (~(((g_2.f5 & l_62) & l_674.f4))))) & ((~((g_658.f3 - (~((((~(B5J5Jcg_174)) + (l_300 << B5J5Jg_759)) / (B5J5Jdl_300 - (~(g_274.f0))))))))) | (g_174 >> (~(B5J5Jeg_658_f3))))))));
g_2.f5 = (~(((~((((~(g_759)) << (~((~((B5J5Jfg_2_f5 + (l_251.f3 | l_300))))))) ^ ((B5J5Jcg_174 & B5J5Jdl_300) | ((B5J5Jg_759 - l_302) & (g_174 ^ (B5J5Jbg_274_f0 << l_674.f4))))))) ^ ((g_658.f3 | g_2.f5) / (~((g_274.f0 & (l_62 << B5J5Jeg_658_f3))))))));
}
}
g_759 = B5J5Jg_759;
g_274.f0 = B5J5Jbg_274_f0;
g_174 = B5J5Jcg_174;
l_300 = B5J5Jdl_300;
g_658.f3 = B5J5Jeg_658_f3;
g_2.f5 = B5J5Jfg_2_f5;

                    if((l_122 < BIJIJng_274_f2)){
BIJIJml_251_f1 = l_251.f1;
BIJIJng_274_f2 = g_274.f2;
BIJIJog_112 = g_112;
LABEL_IJIJs: BIJIJpl_62 = l_62;
BIJIJql_251_f4 = l_251.f4;
BIJIJrg_759 = g_759;
l_251.f1 = (~(((~(((~(((g_274.f1 + l_251.f4) ^ g_759))) + (~((((~((~(BIJIJql_251_f4)))) & (((~((~(l_251.f1)))) + (l_251.f5 | g_112)) & (~(l_62)))) % g_274.f2)))))) | (~((~((BIJIJrg_759 * ((((~((BIJIJpl_62 + BIJIJml_251_f1))) || (BIJIJog_112 & l_122)) & g_658.f3) || (~(BIJIJng_274_f2)))))))))));
g_274.f2 = (~((((~((g_759 ^ g_274.f2))) & ((((g_112 << (BIJIJng_274_f2 || g_658.f3)) & ((l_251.f4 % (BIJIJog_112 ^ l_62)) ^ BIJIJml_251_f1)) + (~(((~((~(BIJIJpl_62)))) + BIJIJql_251_f4)))) | (~(l_251.f1)))) + (((g_274.f1 || l_251.f5) || BIJIJrg_759) + (~((~(l_122))))))));
g_112 = (~(((~(((~((~(g_274.f1)))) ^ (((l_251.f1 | ((~((~((l_251.f5 ^ (~(BIJIJml_251_f1))))))) & ((~(BIJIJng_274_f2)) ^ (~((l_251.f4 ^ BIJIJpl_62)))))) | g_759) ^ (~(((~(((g_658.f3 + BIJIJrg_759) ^ l_62))) & g_112))))))) + (~(((~((BIJIJog_112 & (~(l_122))))) ^ (~((g_274.f2 % BIJIJql_251_f4)))))))));
l_62 = (~(((((~((BIJIJrg_759 || (BIJIJog_112 % g_274.f1)))) * (~(g_112))) % ((~((~((g_759 & l_251.f1))))) ^ (~((~(l_62)))))) << (~((~(((BIJIJpl_62 + (((g_658.f3 + l_251.f4) + (~((g_274.f2 + BIJIJng_274_f2)))) + (BIJIJml_251_f1 * l_251.f5))) || (~((~((BIJIJql_251_f4 % l_122)))))))))))));
l_251.f4 = (~(((((~((((~(BIJIJql_251_f4)) + (~((BIJIJpl_62 || g_759)))) + (((~(l_251.f4)) || BIJIJml_251_f1) & (~(l_62)))))) * (BIJIJng_274_f2 % g_274.f2)) ^ ((~((~(g_112)))) >> ((l_251.f5 + g_274.f1) || (~(BIJIJog_112))))) | (~((BIJIJrg_759 ^ (g_658.f3 + (l_122 * (~(l_251.f1))))))))));
g_759 = (~(((((l_251.f5 + g_658.f3) + (~((~((BIJIJrg_759 || g_112)))))) || ((~((g_274.f1 * (~((((BIJIJql_251_f4 | BIJIJog_112) ^ g_759) || (~(BIJIJpl_62)))))))) || (~((l_62 * (~(BIJIJng_274_f2))))))) & (~((~(((~(((~((~(l_122)))) * l_251.f1))) << ((l_251.f4 + BIJIJml_251_f1) || (~(g_274.f2)))))))))));
if(!((BIJIJml_251_f1>=-3))){
printf("l_251.f1=%lld\n", (long long)l_251.f1);
goto LABEL_IJIJs;
}
if((l_251.f1 < BIJIJml_251_f1)){
printf("g_274.f2=%lld\n", (long long)g_274.f2);

g_2569 -= 1;


                    goto LABEL_rJrJn;
}
if((g_274.f2>-112356781)){
printf("g_112=%llu\n", (unsigned long long)g_112);

{
                        l_62 = g_40[1];
                    }

                    goto LABEL_rJrJo;
}
                               uint32_t B5J5Jhg_740 = (~((((g_2.f2 | (~((g_714 + l_863)))) / (~(g_740))) & (((g_759 - (~((l_652 - (~(g_112)))))) & (~((~(l_293))))) & (l_251.f3 ^ g_264)))));
int32_t B5J5Jig_759 = (~(((~((~((((B5J5Jhg_740 % g_2.f2) / l_652) / l_863))))) & ((((~((~(g_264)))) << (~(((~(g_740)) | (l_293 + g_714))))) ^ l_251.f3) ^ (g_759 - (~(g_112)))))));
int32_t B5J5Jjl_293 = (~(((~((((~((g_2.f2 / g_759))) - (~(l_293))) % ((~(l_863)) % ((l_652 ^ g_740) | g_714))))) ^ (((((~(l_251.f3)) - g_264) / g_112) ^ (~((~((~(B5J5Jhg_740))))))) ^ (~(B5J5Jig_759))))));
int32_t B5J5Jkg_2_f2 = (~((((l_251.f3 - (((g_112 + (B5J5Jhg_740 / (B5J5Jjl_293 + (g_759 + (~(l_293)))))) | (g_714 / (~(g_740)))) % (B5J5Jig_759 | g_2.f2))) - (~((~((l_652 / g_264)))))) & (~(l_863)))));
int32_t B5J5Jll_652 = (~(((~((((~((g_2.f2 & l_251.f3))) | ((~((g_740 - g_112))) - g_714)) | ((~(l_863)) & l_293)))) ^ (~(((~((~(g_759)))) - (~(((B5J5Jig_759 & (~(B5J5Jhg_740))) & (B5J5Jkg_2_f2 / (B5J5Jjl_293 ^ (l_652 + g_264))))))))))));
int16_t B5J5Jml_251_f3 = (~(((~(((~(l_293)) + ((~(l_652)) % g_2.f2)))) / (~((((((B5J5Jkg_2_f2 | (g_714 / ((~((l_863 + g_740))) + B5J5Jig_759))) | B5J5Jjl_293) + (~((((B5J5Jhg_740 + B5J5Jll_652) % l_251.f3) >> (~(g_759)))))) + g_264) ^ (~(g_112))))))));
if(!(((g_264<158) || (g_2.f2>2681)))){
B5J5Jhg_740 = g_740;
B5J5Jig_759 = g_759;
B5J5Jjl_293 = l_293;
B5J5Jkg_2_f2 = g_2.f2;
B5J5Jll_652 = l_652;
LABEL_5J5Jn: B5J5Jml_251_f3 = l_251.f3;
g_740 = (~((((((B5J5Jig_759 ^ l_652) / (B5J5Jjl_293 << g_714)) % l_863) & g_759) % (~(((~((~(g_112)))) ^ ((~((((l_293 | (B5J5Jkg_2_f2 & g_2.f2)) % ((~(B5J5Jml_251_f3)) ^ (~(g_264)))) << (B5J5Jhg_740 % B5J5Jll_652)))) - ((~(g_740)) - (~(l_251.f3))))))))));
g_759 = (~((((((B5J5Jig_759 ^ B5J5Jhg_740) | (g_112 / (~((g_264 ^ (~((~(B5J5Jll_652))))))))) | g_759) | (~((((~((l_652 - g_740))) % (~((B5J5Jkg_2_f2 ^ (B5J5Jjl_293 / l_863))))) - (~(((~(g_714)) | g_2.f2))))))) - (~(((~(((~(l_293)) - (~(B5J5Jml_251_f3))))) % (~(l_251.f3))))))));
l_293 = (~(((((g_264 | g_759) + (~(l_863))) / (~(l_293))) >> (g_714 % ((((B5J5Jig_759 % (~(B5J5Jjl_293))) & g_740) % (~(((((l_652 ^ g_2.f2) - (g_112 | l_251.f3)) & B5J5Jml_251_f3) - B5J5Jhg_740)))) ^ (B5J5Jll_652 | B5J5Jkg_2_f2))))));
g_2.f2 = (~((((~((~((~((B5J5Jjl_293 + (l_251.f3 ^ B5J5Jhg_740)))))))) + ((~((((g_112 >> g_714) / B5J5Jml_251_f3) % B5J5Jll_652))) | ((~((~(g_2.f2)))) | l_652))) / (~((~(((((~(B5J5Jig_759)) % (l_863 ^ l_293)) + (~(((~(B5J5Jkg_2_f2)) | (~(g_759)))))) / (g_740 & g_264)))))))));
l_652 = (~(((g_2.f2 / (((~(l_863)) + (B5J5Jml_251_f3 + (~((~(g_714)))))) ^ ((~(((((~((g_740 ^ g_759))) | (~(l_652))) >> ((~(B5J5Jig_759)) - (~(B5J5Jhg_740)))) - ((~((l_251.f3 + g_112))) / (~((B5J5Jll_652 % (~(B5J5Jjl_293))))))))) & (l_293 / g_264)))) | (~(B5J5Jkg_2_f2)))));
l_251.f3 = (~(((~((~(((~((~(((~(((~((B5J5Jml_251_f3 % B5J5Jkg_2_f2))) & (~((~(g_112))))))) % (g_264 & g_740)))))) | (~((~(((~(B5J5Jig_759)) - (((l_251.f3 | l_293) | g_714) + (~(l_863))))))))))))) - ((~((B5J5Jll_652 - g_759))) & ((l_652 << B5J5Jhg_740) + (B5J5Jjl_293 + g_2.f2))))));
if(!(g_2.f2)){
printf("g_740=%llu\n", (unsigned long long)g_740);
goto LABEL_rJrJo;
}
if((((g_2.f2<-66360740) && (!B5J5Jml_251_f3)) && ((g_264>=158) && g_264))){
printf("g_759=%lld\n", (long long)g_759);
goto LABEL_rJrJn;
}
if((B5J5Jhg_740 > g_112)){
printf("l_293=%lld\n", (long long)l_293);
goto LABEL_IJIJt;
}
if((B5J5Jhg_740<0U)){
printf("g_2.f2=%lld\n", (long long)g_2.f2);
B5J5Jml_251_f3 = (~(((~(((~(((B5J5Jml_251_f3 / ((B5J5Jjl_293 ^ g_759) / (~(B5J5Jkg_2_f2)))) + (~(l_652))))) ^ ((~(B5J5Jig_759)) & ((~(B5J5Jll_652)) - (~((g_714 ^ l_293)))))))) % (~(((~(((g_264 + (~((g_740 & g_2.f2)))) + ((B5J5Jhg_740 | g_112) + l_251.f3)))) | l_863))))));
goto LABEL_rJrJn;
}
if((g_714>0)){
printf("l_652=%lld\n", (long long)l_652);
goto LABEL_rJrJo;
}
if((l_293<-1)){
printf("l_251.f3=%lld\n", (long long)l_251.f3);
B5J5Jll_652 = (~(((~((((~(l_293)) - ((~((~(g_714)))) - (l_652 | (~(g_112))))) & ((~((((~((g_264 | B5J5Jhg_740))) ^ (g_759 | (B5J5Jll_652 >> (~(g_2.f2))))) - B5J5Jkg_2_f2))) << l_251.f3)))) & (~((~((~(((l_863 ^ B5J5Jjl_293) - (~((((~(B5J5Jig_759)) >> g_740) & (~((~(B5J5Jml_251_f3)))))))))))))))));
g_759 = (~(((((~((~(((g_759 - B5J5Jhg_740) << g_740))))) & ((~(g_714)) + (((B5J5Jml_251_f3 / (~((l_863 + (B5J5Jig_759 | (l_293 ^ B5J5Jjl_293)))))) + (~((~((B5J5Jkg_2_f2 | g_112)))))) ^ ((l_652 | g_2.f2) / B5J5Jll_652)))) >> (~(g_264))) << (~((~((~(l_251.f3)))))))));
goto LABEL_IJIJs;
}
}
g_740 = B5J5Jhg_740;
g_759 = B5J5Jig_759;
l_293 = B5J5Jjl_293;
g_2.f2 = B5J5Jkg_2_f2;
l_652 = B5J5Jll_652;
l_251.f3 = B5J5Jml_251_f3;

                    LABEL_IJIJt: if((l_122<-12693)){
printf("l_62=%lld\n", (long long)l_62);
goto LABEL_rJrJn;
}
                                    if ((!l_674.f1) )
{

{
                        int8_t l_371 = (-2L);
                        g_658 = l_251;
                        l_216[5][2][4].f1 = (safe_sub_func_uint8_t_u_u(((((g_740 < (safe_mod_func_uint8_t_u_u((p_34 < (safe_sub_func_int32_t_s_s(((((safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((((((g_658.f1 = (l_243 = (safe_mod_func_int8_t_s_s(((g_274.f3 && (safe_sub_func_uint32_t_u_u((((g_75 = (safe_sub_func_int32_t_s_s((+g_211), g_740))) <= (g_274.f2 = (safe_unary_minus_func_uint32_t_u(4294967287UL)))) < (l_320[4][0][2] > l_674.f0)), (g_1568 | g_1897)))) >= l_122), l_371)))) < k) < BIJIJog_112) || l_371) && l_674.f4), 0x1DCE6AB1L)), l_270)) <= 4294967287UL) & 0UL) & 2UL), g_40[2]))), g_224))) && 0x3786L) >= 0x41L) & 1L), BIJIJog_112));
                    }

}
                    if(!((l_251.f4>=15696))){
printf("l_251.f4=%llu\n", (unsigned long long)l_251.f4);
goto LABEL_rJrJn;
}
                                    if ((g_2.f3 > g_415) )
{

{
                    int i;
                    g_217[0] = g_217[l_321];
                }

}
                    if((((l_62 < g_274.f2) && g_658.f3) && (g_658.f3 > l_122))){
printf("g_759=%lld\n", (long long)g_759);
goto LABEL_IJIJs;
}
}
l_251.f1 = BIJIJml_251_f1;
g_274.f2 = BIJIJng_274_f2;
g_112 = BIJIJog_112;
                                   if (!(!((l_251.f1 < g_658.f2))))
                    l_62 = BIJIJpl_62;
l_251.f4 = BIJIJql_251_f4;
g_759 = BIJIJrg_759;

                    l_251 = l_251;
                                           if (l_674.f5)
                    for (g_112 = 25; (g_112 < 3); --g_112)
        {
            int32_t l_301[1][6];
            int i, j;
            for (i = 0; i < 1; i++)
            {
                for (j = 0; j < 6; j++)
                    l_301[i][j] = 0x73B3B5CCL;
            }
            for (l_62 = 0; (l_62 < (-14)); l_62--)
            {
                uint16_t l_275 = 0x38A2L;
                int8_t l_276[8];
                int i;
                for (i = 0; i < 8; i++)
                    l_276[i] = 0L;

{
                    l_251.f2 = 0x4B857C2BL;
                }

                    if ((l_243 == (p_36 > p_36)))
                {
                    int8_t l_265 = 1L;
                    g_40[1] = ((((l_265 = (safe_lshift_func_uint16_t_u_s(3UL, (p_36 > (safe_rshift_func_uint8_t_u_s((((p_34 >= (safe_sub_func_uint8_t_u_u(g_130.f1, (g_264 = ((safe_lshift_func_uint16_t_u_s(p_34, 8)) <= g_237))))) == g_174) <= 7UL), 3)))))) || (safe_mod_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(g_2.f2, l_270)), g_2.f1))) && p_36) >= p_36);

for (p_34 = 20; (p_34 == 56); p_34 = safe_add_func_int8_t_s_s(p_34, 5))
            {
                struct S1 l_1943[8][9] = {{{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}, {{180,-8,13660,-80,130,197}, {161,-6,-95,15,51,54}, {75,-9,-3262,50,158,157}, {11,-21,2572,70,171,89}, {11,-21,2572,70,171,89}, {75,-9,-3262,50,158,157}, {161,-6,-95,15,51,54}, {180,-8,13660,-80,130,197}, {75,-9,-3262,50,158,157}}};
                int i, j;
                l_1943[7][0] = (g_656 = g_656);
            };


                    for (l_243 = 0; (l_243 <= 4); l_243 += 1)
                    {
                        g_237 = g_40[1];
                    }
                }
                else
                {
                    struct S1 l_273 = {66,-4,-10986,-87,170,225};
                    if (l_243)
                        break;
                    for (l_243 = 0; (l_243 <= 13); l_243 = safe_add_func_int16_t_s_s(l_243, 1))
                    {
                        g_274 = l_273;
                        l_275 = (l_273.f4 < g_40[1]);
                        l_276[0] = g_237;
                    }
                }
            }
            g_211 = (safe_sub_func_uint32_t_u_u((safe_rshift_func_int16_t_s_u(g_69, ((((safe_mod_func_uint32_t_u_u((((l_243 != l_62) < 0xCBEFL) && (safe_mod_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_u((l_301[0][5] = (safe_sub_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s((l_293 = l_251.f0), 2)) > ((safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(((safe_mod_func_int32_t_s_s(((g_163 = (0x66L ^ (p_36 = g_40[0]))) != (((1UL >= 0x2C471631L) < l_300) || p_35)), g_224)) > 0x303FCA0DL), 3)), l_270)) != 255UL)), g_112))), 3)), 0)), 0x4F0B7164L))), g_40[0])) <= g_274.f1) <= l_243) ^ (-1L)))), g_2.f1));
        }
                                            if (((g_264 < g_2.f4) || (g_264<158)) )
{

{
                        int32_t l_478 = 0xCB2505EBL;

if ((safe_lshift_func_int8_t_s_u(((+(safe_sub_func_uint32_t_u_u((0L || (g_3484 = (safe_rshift_func_uint16_t_u_s(g_1895.f0, 4)))), g_3324))) == ((-1L) | g_2.f2)), g_740)))
                    {
                        g_1896.f1 = g_971;
                    }
                    else
                    {
                        uint8_t l_2913 = 0x9DL;
                        l_251.f2 = (safe_mod_func_uint32_t_u_u((g_1895.f1 = ((((safe_sub_func_int8_t_s_s(g_3484, l_302)) && (((safe_add_func_uint32_t_u_u((safe_mod_func_int16_t_s_s((l_251.f3 = ((safe_mod_func_uint8_t_u_u(l_251.f1, (l_243 = (l_243 && (safe_lshift_func_uint8_t_u_u((((((safe_add_func_int32_t_s_s((safe_add_func_uint32_t_u_u(l_243, (BIJIJpl_62 = g_69))), (safe_rshift_func_int16_t_s_u(((safe_add_func_int8_t_s_s((l_243 = g_3484), (g_1896.f1 = l_251.f4))) ^ l_243), 15)))) & g_69) & g_69) != 0x1B3FL) == l_300), l_784)))))) > p_34)), 1UL)), g_224)) & 1L) | 0xFAF6L)) | g_2.f3) && g_1895.f0)), 0xF5299BB1L));
                        g_658.f1 = ((safe_rshift_func_uint8_t_u_u((((((g_1895.f1 = (g_224 <= (safe_add_func_uint16_t_u_u((8UL < (0xBB9ADCDDL != (l_251.f3 = (safe_add_func_uint32_t_u_u((l_251.f1 = (((safe_sub_func_int8_t_s_s((p_34 & (l_251.f2 = ((safe_sub_func_int8_t_s_s((((l_243 && (safe_add_func_int8_t_s_s((l_243 = (((g_1896.f1 = (safe_lshift_func_int16_t_s_u(l_2913, 0))) <= (l_251.f1 > g_2569)) ^ ((g_224 != 1UL) < l_270))), 0x66L))) | l_300) > 0xB95B8FDAL), g_1895.f1)) > l_2913))), g_217[0].f1)) & l_2913) && l_251.f2)), 0x0D2C52FFL))))), g_2.f1)))) ^ g_740) <= g_1058) > p_34) || l_300), 4)) && l_251.f5);
                    };


                    g_2.f3 = g_2667;
                        g_647 = (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s(((0x6C3B8124L >= (!j)) || (((0xB1F7L == (g_2667 = g_63)) <= (safe_sub_func_int32_t_s_s(g_971, (g_1039 ^ ((l_824 | g_971) ^ (safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(0xE6L, 0)), g_971))))))) == g_1058)), 0xEBL)), 12))));
                        g_2.f1 = ((safe_rshift_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(0x41L, (safe_lshift_func_int16_t_s_u((g_971 == ((((((safe_sub_func_int32_t_s_s((((safe_sub_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((((j = ((safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s(((g_647 = (safe_lshift_func_int16_t_s_u(((g_656.f4 || (1L & (g_2317 = g_1039))) < g_656.f4), (((l_270 = (g_2667 >= (~(0xE59C2AA1L != 0xF9BF29F1L)))) || 1UL) > l_478)))) & g_2.f1), g_2.f1)), 0xF1F6L)) <= 0x6524L)) != l_302) < (-9L)), l_302)), l_478)) > 0x43L) | g_971), g_971)) <= g_656.f5) >= g_971) | g_1039) || g_900) & l_824)), g_2.f3)))), g_63)) == g_2667);
                        j = (g_656.f3 = (safe_rshift_func_int8_t_s_u(((safe_lshift_func_int16_t_s_s(l_302, (safe_lshift_func_int16_t_s_u((((!(-9L)) == g_217[0].f0) >= (g_2317 = g_2667)), 11)))) == 65535UL), 4)));
                    }

}
                    l_62 = (l_302 > (p_36 >= (g_2.f4 >= (+(0x4FL != (l_216[5][2][4].f1 = g_2.f5))))));
    }
    for (l_122 = (-12); (l_122 <= (-7)); l_122 = safe_add_func_uint32_t_u_u(l_122, 5))
    {
        int16_t l_319 = 7L;
        struct S1 l_322 = {218,-14,-13328,35,77,28};
        int32_t l_368 = (-1L);
        for (g_224 = 0; (g_224 == (-16)); g_224 = safe_sub_func_uint16_t_u_u(g_224, 9))
        {
            int8_t l_318 = 0xA7L;
            struct S1 l_323 = {75,18,-1671,80,156,344};
            int16_t l_332 = 0x8338L;
            int32_t l_333 = 0x25710E5DL;
            uint32_t l_347 = 6UL;
            uint16_t l_560 = 0UL;
            l_321 = (((safe_add_func_int8_t_s_s((g_310 = 0xB0L), (g_2.f0 && 8UL))) > g_40[1]) ^ ((((safe_rshift_func_int16_t_s_u((p_37 || ((safe_unary_minus_func_int32_t_s((((safe_sub_func_int32_t_s_s(g_130.f0, (l_251.f1 = (((safe_lshift_func_int8_t_s_u(p_37, 3)) & (((((l_318 = g_2.f1) != g_40[2]) || 65535UL) || l_318) | l_319)) | 0x1FL)))) ^ p_35) == l_320[4][0][2]))) && 1L)), p_36)) | 0xC9F1L) || l_318) >= 1UL));

{
                    l_368 = 0L;
                    if (l_368)
                        continue;

{

{
                    g_2 = (g_656 = g_656);
                }

                    transparent_crc(g_40[k], "g_40[k]", l_652);
        if (l_652) printf("index = [%d]\n", k);

    }

                    l_322 = g_658;
                }

                    l_323 = (g_274 = l_322);
            for (l_321 = 0; (l_321 <= 49); l_321++)
            {
                int32_t l_327 = 0x989AA41EL;
                uint32_t l_340 = 0x828E4155L;
                int16_t l_370 = 0x7B07L;
                int32_t l_372 = (-1L);
                int8_t l_453 = 0x96L;
                uint16_t l_511 = 0x0BC0L;
                uint32_t l_542[7] = {7UL, 7UL, 18446744073709551606UL, 7UL, 7UL, 18446744073709551606UL, 7UL};
                int16_t l_585 = 0L;
                int8_t l_596 = 0xBEL;
                int8_t l_612 = 0x26L;
                int i;
                if ((safe_unary_minus_func_uint16_t_u(l_327)))
                {
                    uint32_t l_346 = 0x90B89719L;
                    int32_t l_348[9];
                    int i;
                    for (i = 0; i < 9; i++)
                        l_348[i] = 1L;

for (g_688 = 0; g_688 < 6; g_688++)
        l_58[g_688] = 1UL;


{
                        struct S1 l_3596 = {21,1,11767,18,12,308};
                        g_2 = g_658;
                        g_658 = (g_2 = (l_3596 = g_658));
                    }

                    l_348[0] = (g_174 == (g_40[1] = ((safe_rshift_func_int8_t_s_s(((safe_sub_func_int32_t_s_s(l_332, l_333)) | ((g_174 && ((safe_mod_func_int32_t_s_s((safe_rshift_func_int8_t_s_s(p_37, 1)), (safe_rshift_func_int16_t_s_u(p_37, g_2.f5)))) | (l_340 = 0UL))) != ((safe_lshift_func_uint8_t_u_u((+(l_327 = (safe_rshift_func_int16_t_s_s(((l_346 <= g_217[0].f0) ^ g_2.f2), 1)))), g_274.f3)) ^ p_34))), 0)) == l_347)));
                    for (g_75 = 0; (g_75 < 13); g_75 = safe_add_func_int16_t_s_s(g_75, 2))
                    {
                        int8_t l_371 = (-2L);
                        l_322 = l_251;
                        l_216[5][2][4].f1 = (safe_sub_func_uint8_t_u_u(((((p_34 < (safe_mod_func_uint8_t_u_u((p_35 < (safe_sub_func_int32_t_s_s(((((safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((((((l_322.f1 = (p_36 = (safe_mod_func_int8_t_s_s(((l_323.f3 && (safe_sub_func_uint32_t_u_u((((l_368 = (safe_sub_func_int32_t_s_s((+g_75), g_174))) <= (l_323.f2 = (safe_unary_minus_func_uint32_t_u(4294967287UL)))) < (l_320[4][0][2] > g_2.f0)), (g_310 | g_264)))) >= l_370), l_371)))) < l_62) < p_37) || l_371) && g_274.f4), 0x1DCE6AB1L)), g_112)) <= 4294967287UL) & 0UL) & 2UL), g_40[2]))), l_372))) && 0x3786L) >= 0x41L) & 1L), p_37));
                    }
                    for (g_112 = 2; (g_112 == 45); g_112++)
                    {
                        if (p_34)
                            break;
                    }
                    if (p_37)
                        continue;
                }
                else
                {
                    uint16_t l_385 = 0x4A82L;
                    uint32_t l_416 = 0xF4081C80L;
                    int32_t l_476 = 0xAC569D01L;
                    int32_t l_479 = 0x0FFF34F5L;
                    g_211 = ((+(((~(safe_add_func_uint32_t_u_u((safe_add_func_int32_t_s_s(((safe_lshift_func_int16_t_s_u(((((g_69 >= (((((((safe_add_func_int8_t_s_s(0xB2L, l_385)) <= (l_323.f1 = ((g_274.f4 == (safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(((((l_216[5][2][4].f0 >= (safe_lshift_func_uint16_t_u_s(0x8D89L, 13))) > (safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(((safe_add_func_uint8_t_u_u((safe_unary_minus_func_uint8_t_u((safe_lshift_func_int16_t_s_s((safe_sub_func_int16_t_s_s(l_368, (safe_rshift_func_int8_t_s_u(g_112, ((l_385 < 0x54L) >= 0x2881L))))), l_58[4])))), l_58[3])) == 0xC3B5L), g_163)), 0))) <= p_36) > l_368), p_36)) == l_322.f3), g_69))) == g_130.f1))) == 65533UL) == 9UL) > g_2.f0) >= p_34) || p_34)) | 0xE150EA9AL) || 7UL) > l_347), 4)) ^ l_122), g_130.f0)), l_320[4][0][2]))) && g_2.f5) & p_37)) || 0xC4L);

g_1897 += 1;


                    if ((g_2.f1 >= (safe_mod_func_uint32_t_u_u(((safe_sub_func_uint32_t_u_u((0x2BL & (g_130.f0 || (((safe_add_func_int16_t_s_s((l_251.f3 = ((safe_add_func_int16_t_s_s(p_37, (p_36 && (safe_mod_func_uint16_t_u_u(0xE618L, (g_415 = (246UL & ((g_237 ^ (p_36 = (-3L))) >= 0x59301DB9L)))))))) < p_35)), p_34)) | 0x48L) == l_416))), 0x94C6A02EL)) && g_2.f2), g_163))))
                    {
                        uint32_t l_440[4];
                        int i;
                        for (i = 0; i < 4; i++)
                            l_440[i] = 6UL;

{
                        g_2.f1 = ((safe_rshift_func_uint16_t_u_s((+l_863), 8)) == (g_2.f1 | (g_2.f5 = g_1184)));
                        if (g_1568)
                            break;
                    }

                    g_211 = (safe_rshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u((((((g_264 = g_2.f5) || (~(0xF79201D8L <= (safe_mod_func_uint16_t_u_u((safe_sub_func_int32_t_s_s(g_112, (+((p_34 = 1UL) && (safe_mod_func_int8_t_s_s(((!g_2.f4) <= (l_441 = (safe_mod_func_uint32_t_u_u(((safe_mod_func_int16_t_s_s(((safe_lshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(g_130.f0, (((1L >= l_440[0]) && (((((p_36 & l_340) < p_37) <= l_440[2]) || l_323.f3) != 0xF1L)) != g_2.f2))), 5)) != p_35), l_327)) == (-7L)), g_274.f5)))), g_69)))))), p_35))))) ^ 0x25L) >= g_2.f4) > g_274.f3), 5)), 0UL)), 4));
                        return g_40[1];
                    }
                    else
                    {
                        int32_t l_478 = 0xCB2505EBL;
                        g_274.f3 = p_36;

{
                        g_274.f2 = l_368;

{
        for (l_478 = 0; l_478 < 5; l_478++)
        {
            for (l_476 = 0; l_476 < 2; l_476++)
            {
                transparent_crc(g_1177[l_479][l_478][l_476], "g_1177[l_479][l_478][l_476]", g_2317);
                if (g_2317) printf("index = [%d][%d][%d]\n", l_479, l_478, l_476);

            }
        }
    }

                    g_274.f2 = g_274.f5;
                    }

                    l_327 = (safe_unary_minus_func_uint32_t_u((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s(((0x6C3B8124L >= (!g_224)) || (((0xB1F7L == (l_450 = l_441)) <= (safe_sub_func_int32_t_s_s(p_35, (p_34 ^ ((l_453 | p_35) ^ (safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u(0xE6L, 0)), p_35))))))) == g_237)), 0xEBL)), 12))));
                        l_323.f1 = ((safe_rshift_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(0x41L, (safe_lshift_func_int16_t_s_u((p_35 == ((((((safe_sub_func_int32_t_s_s((((safe_sub_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((((l_479 = ((safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s(((l_327 = (safe_lshift_func_int16_t_s_u(((g_2.f4 || (1L & (l_476 = p_34))) < l_251.f4), (((g_415 = (p_36 >= (~(0xE59C2AA1L != 0xF9BF29F1L)))) || 1UL) > l_478)))) & g_274.f1), g_274.f1)), 0xF1F6L)) <= 0x6524L)) != p_37) < (-9L)), p_37)), l_478)) > 0x43L) | l_416), p_35)) <= l_322.f5) >= p_35) | g_174) || l_347) & l_453)), l_323.f3)))), l_340)) == p_36);
                        l_479 = (l_322.f3 = (safe_rshift_func_int8_t_s_u(((safe_lshift_func_int16_t_s_s(p_37, (safe_lshift_func_int16_t_s_u((((!(-9L)) == g_217[0].f0) >= (l_476 = p_36)), 11)))) == 65535UL), 4)));
                    }
                }
                if (((0xCA025045L ^ (((safe_sub_func_uint32_t_u_u(((~(l_340 > ((((safe_rshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s((p_36 = p_37), 1)) > ((+(safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(g_69, (((l_323.f1 = (g_163 = (safe_sub_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((g_130.f1 || l_323.f2) <= (4294967295UL <= (((0L >= (safe_mod_func_int32_t_s_s((safe_sub_func_int16_t_s_s(((g_174 || (-6L)) & 0xD3L), 0x79D5L)), g_2.f2))) & 0xCCCEL) == g_274.f2))), (-2L))), (-8L))))) ^ g_217[0].f0) || l_441))), p_35))) <= l_453)), g_224)) ^ p_35) ^ g_415) | 0xD9L))) | l_323.f5), l_441)) != 0UL) <= p_37)) <= p_35))
                {
                    uint32_t l_541 = 4294967289UL;
                    int32_t l_543[10] = {0x3EF99F8AL, 0x3EF99F8AL, 1L, 0x3EF99F8AL, 0x3EF99F8AL, 1L, 0x3EF99F8AL, 0x3EF99F8AL, 1L, 0x3EF99F8AL};
                    struct S0 l_597 = {-2L,901};
                    int i;

{
                        struct S1 l_3108 = {238,8,4487,-23,133,252};
                        g_224 = l_333;
                        l_323 = l_3108;
                        if (l_327)
                            continue;
                    }

                    for (g_264 = 0; (g_264 != 59); ++g_264)
                    {
                        uint32_t l_514[2][8][5] = {{{0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}}, {{0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}, {0xE107908DL, 9UL, 5UL, 0UL, 0xB33DAA00L}}};
                        int i, j, k;
                        l_511 = 0xD56F6D0BL;


{
                        g_875 = (0x1696D010L | ((g_1058 | 0xC4L) ^ g_2.f5));
                    }

                    if (k)
                        break;

                    g_40[1] = 1L;
                        l_372 = (safe_add_func_int16_t_s_s(((((l_251.f3 = l_514[1][3][4]) && ((0x6E41L ^ ((((((((safe_mul_func_uint16_t_u_u(65526UL, (0x4B51FDB1L < 3UL))) != 4UL) > (safe_lshift_func_int16_t_s_s((l_327 = 1L), g_130.f1))) | 5L) | 0xC785L) & l_514[1][3][3]) >= p_36) & p_37)) <= l_450)) >= 0L) || p_34), l_251.f4));
                        l_251.f3 = (safe_rshift_func_uint16_t_u_u(l_320[0][0][2], 10));
                    }
                    if ((((l_322.f1 = (((p_34 | ((safe_add_func_int32_t_s_s(((l_368 & (safe_mod_func_int8_t_s_s(((safe_unary_minus_func_int16_t_s(((l_543[9] = (safe_rshift_func_int8_t_s_u((p_36 = (g_112 > (safe_rshift_func_int16_t_s_s((((safe_unary_minus_func_uint16_t_u((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s(g_274.f2, (safe_rshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(((p_37 != (safe_sub_func_int32_t_s_s(l_541, p_36))) <= (((0xE7L || p_37) & l_319) <= l_58[4])), l_541)), 6)))) != l_542[4]), p_34)))) && 0x87L) & l_323.f3), 6)))), g_217[0].f1))) >= 0x1377L))) || p_34), l_323.f2))) & g_174), l_372)) ^ g_237)) || g_2.f1) | 0x47B1ED3EL)) & 0xBBL) == g_415))
                    {
                        uint32_t l_586 = 6UL;
                        g_40[0] = (safe_mod_func_int32_t_s_s((((safe_rshift_func_int8_t_s_s(0x1AL, 6)) != 0x9A7E1DFBL) != 0UL), (((safe_rshift_func_int16_t_s_u(l_543[1], (safe_sub_func_uint32_t_u_u((safe_sub_func_int8_t_s_s((((safe_mod_func_uint16_t_u_u(l_541, l_216[5][2][4].f1)) ^ (((safe_sub_func_int8_t_s_s(((((p_34 = p_36) & p_36) >= (safe_add_func_uint8_t_u_u((l_543[1] == g_310), g_2.f3))) != p_36), 0xC4L)) <= l_322.f4) | l_560)) || l_347), 0xB3L)), g_174)))) & l_453) & g_2.f3)));
                        g_40[1] = (p_37 || (safe_mod_func_int8_t_s_s((((((safe_lshift_func_uint8_t_u_u(g_274.f2, (((safe_mod_func_uint16_t_u_u(p_36, (((g_274.f4 = (((safe_add_func_uint8_t_u_u((safe_add_func_uint16_t_u_u(((((-9L) && ((safe_add_func_int16_t_s_s((0L != (safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_u((g_2.f5 == (((safe_rshift_func_uint8_t_u_u((g_264 = p_35), 5)) || (safe_lshift_func_uint8_t_u_s((((((safe_add_func_int32_t_s_s((0xC539F0A9L < (((safe_sub_func_uint8_t_u_u(p_35, p_34)) ^ 251UL) <= p_37)), 1L)) <= 0x34L) > 6L) <= g_274.f4) ^ p_34), p_35))) & 0L)), 8)), 0x94468146L))), p_34)) ^ p_34)) ^ l_585) > 0x3969L), 0UL)), p_35)) | g_274.f0) || p_37)) | l_541) && (-6L)))) && l_372) != 0xAAD2AD68L))) ^ p_35) ^ p_36) > p_37) < 1UL), 255UL)));
                        if (g_274.f3)
                            continue;
                        l_586 = l_251.f1;
                    }
                    else
                    {

if (g_415)
                            {
l_652 += 1;


                    break;}

                    g_274.f2 = g_224;

if (l_372)
                            {
g_264 += 1;


                    break;}

                    g_274.f2 = g_274.f5;
                    }
                    if ((safe_rshift_func_int16_t_s_s((l_543[1] <= (+2UL)), (safe_mod_func_int8_t_s_s((l_368 && (0x7D100E82L < (l_542[4] <= ((((safe_rshift_func_int16_t_s_u(((0x4E4BL && l_58[2]) ^ ((0x2E7EE68AL <= (((safe_add_func_uint32_t_u_u((g_274.f0 = (((l_543[9] >= l_216[5][2][4].f1) | p_34) && p_37)), p_36)) == (-1L)) && p_34)) >= g_112)), 6)) || l_596) | 0x05L) == p_35)))), l_62)))))
                    {
                        int8_t l_598 = 0xBFL;
                        g_217[0] = l_597;
                        g_274.f3 = p_36;
                        if (g_69)
                            {
{
                    uint32_t l_670 = 1UL;
                    g_2569 = (l_670 = p_37);
                    l_674.f3 = (safe_lshift_func_int8_t_s_u(g_900, g_2.f4));
                }


g_130.f0 += 1;


                    continue;}
                        l_598 = 0L;
                    }
                    else
                    {
                        if (p_37)
                            {
if (g_40[(l_441 + 1)])
                            continue;

                    break;}
                        return l_543[7];
                    }
                }
                else
                {

for (g_112 = 0; (g_112 <= 0); g_112 += 1)
        {
            g_1895.f1 = ((g_647 && ((l_674.f2 = 0xDDE33A30L) != ((g_647 <= (g_40[1] == (safe_add_func_uint16_t_u_u((g_163 = 3UL), l_347)))) != 8UL))) && g_647);
            g_75 = l_674.f4;
            for (g_1895.f0 = 1; (g_1895.f0 >= 0); g_1895.f0 -= 1)
            {
                g_658.f3 = (safe_sub_func_int16_t_s_s(0L, 0L));

{
                struct S1 l_655 = {224,20,14000,-67,46,41};
                g_658 = (l_322 = (l_251 = (l_674 = l_655)));
            }

                    for (l_441 = 0; (l_441 <= 1); l_441 += 1)
                {
                    int i;
                    g_217[0] = g_217[g_112];
                }
            }
        };


                    return g_174;
                }
                l_323.f1 = (g_274.f5 < ((p_36 = ((((((safe_rshift_func_int8_t_s_s(((((safe_add_func_uint32_t_u_u(((safe_add_func_int32_t_s_s(((l_340 != (safe_rshift_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u(((p_36 >= (0x10F51F9BL != ((0x3DL ^ (((g_613 = (l_322.f3 = (g_264 = (safe_add_func_int16_t_s_s((l_372 = l_368), (((l_62 = g_264) || (-8L)) >= (safe_rshift_func_uint16_t_u_u(l_612, 7)))))))) != g_274.f4) > 0xC9L)) || l_332))) ^ 0x3B09CD00L))), 9))) ^ p_34), 7L)) != 0x1291L), 0x2F13D676L)) || l_323.f0) > 0x17L) > 0xEAL), 0)) & 0xCA0E249EL) | g_40[1]) && p_36) | p_36) == g_224)) | p_34));
                l_323.f3 = (((safe_lshift_func_uint16_t_u_u((((safe_lshift_func_uint16_t_u_u((safe_sub_func_int8_t_s_s(p_37, (safe_rshift_func_int16_t_s_u((0x862CB02EL && p_37), (l_322.f3 = (safe_mod_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u(l_333, (safe_rshift_func_int8_t_s_u(0x17L, ((g_174 != (p_36 = (safe_add_func_uint16_t_u_u(p_37, l_323.f3)))) & g_264))))), 0x2B79L))))))), p_37)) ^ p_37) >= (-7L)), l_542[1])) ^ l_322.f1) >= g_224);
            }
        }
    }
    if ((g_217[0].f1 = (p_35 > ((l_216[5][2][4].f1 = ((p_34 = (l_251.f3 = (((safe_rshift_func_int16_t_s_u(l_251.f2, (safe_mod_func_int16_t_s_s(p_37, ((g_415 = (((safe_add_func_uint8_t_u_u(((safe_sub_func_uint16_t_u_u(l_251.f1, (g_174 <= (g_112 = ((safe_lshift_func_int16_t_s_u(((g_40[1] = (safe_sub_func_uint8_t_u_u((safe_add_func_int16_t_s_s((g_40[1] & ((((0UL && (g_647 = (safe_unary_minus_func_uint32_t_u((safe_mod_func_int32_t_s_s((p_36 & 0x79L), 2L)))))) & g_274.f2) < 0x92L) | p_36)), g_274.f3)), 0xDAL))) < p_35), p_36)) <= p_35))))) || 255UL), 6L)) || 0x03L) | l_321)) | p_36))))) >= 0x1950L) > g_224))) && l_450)) && p_35))))
    {
        uint8_t l_648 = 1UL;
        return l_648;
    }
    else
    {
        uint32_t l_662 = 1UL;
        int32_t l_666 = 0x898FEB7AL;
        int32_t l_667 = 0x738C6A61L;
        uint8_t l_842 = 0xBBL;
        struct S0 l_956 = {0x978E043CL,-1705};
        if (p_35)
        {
            uint8_t l_651 = 1UL;
            struct S1 l_657 = {101,-0,14313,-45,32,110};
            if (((g_264 = (((safe_sub_func_uint16_t_u_u((p_36 ^ ((((((l_651 & l_652) <= (l_216[5][2][4].f1 = (safe_lshift_func_int16_t_s_u(l_320[3][0][4], ((p_35 ^ (g_613 = 0UL)) ^ 4L))))) == 0xC3D04E26L) != g_237) <= g_75) != g_217[0].f1)), p_36)) < p_35) || 0x677223E7L)) | 0x17L))
            {
                struct S1 l_655 = {224,20,14000,-67,46,41};
                g_658 = (l_657 = (g_656 = (g_274 = l_655)));
            }
            else
            {
                uint16_t l_661 = 0x6EA5L;
                int32_t l_671 = (-9L);

for (g_759 = 0; g_759 < 5; g_759++)
        {
            for (j = 0; j < 2; j++)
            {
                transparent_crc(g_1177[l_666][g_759][j], "g_1177[l_666][g_759][j]", g_75);
                if (g_75) printf("index = [%d][%d][%d]\n", l_666, g_759, j);

            }
        };


                    if ((l_662 = (safe_rshift_func_uint8_t_u_u(p_34, l_661))))
                {
                    int32_t l_669 = 0x7D1AE5F8L;
                    for (p_36 = 27; (p_36 > (-25)); p_36--)
                    {
                        uint32_t l_665 = 0xE8B9A2A8L;
                        int32_t l_668[2];
                        int i;

{
                int32_t l_218 = 0xD9B91490L;
                uint8_t l_227 = 254UL;
                g_217[0] = (g_1895 = l_216[5][2][4]);
                for (g_3662 = 0; (g_3662 <= 5); g_3662 += 1)
                {
                    uint16_t l_219 = 0x791FL;
                    struct S0 l_220[4] = {{0x34A1C847L,71}, {-1L,1107}, {0x34A1C847L,71}, {-1L,1107}};
                    int32_t l_234 = 1L;
                    int i;
                    for (g_2667 = 4; (g_2667 >= 1); g_2667 -= 1)
                    {
                        int i;
                        if (l_58[g_2667])
                            break;
                        l_218 = ((-1L) <= g_63);
                        g_310 = l_219;
                    }
                    g_217[0] = l_220[1];
                    for (g_959 = 0; (g_959 <= 5); g_959 += 1)
                    {
                        uint8_t l_233 = 0UL;
                        l_234 = (g_174 <= (safe_mod_func_uint8_t_u_u(((-9L) && (((!((g_63 = (j = 4294967288UL)) != ((l_220[1].f1 = (safe_mod_func_int16_t_s_s(((l_227 ^ (((0xCDL || ((0xA2A9L < ((safe_lshift_func_int8_t_s_u(((g_415 ^ g_310) > ((g_759 = (0x87C8L || g_174)) & g_1895.f1)), l_58[3])) != g_174)) < 0x96L)) != l_667) && g_1039)) < l_251.f5), 0x45C8L))) > 1UL))) | 9UL) < 1UL)), l_233)));
                    }
                }
            }

                    for (i = 0; i < 2; i++)
                            l_668[i] = 0x75128752L;
                        l_667 = (l_666 = l_665);
                        g_274.f1 = (l_668[1] = (l_251.f1 = l_665));

for (g_237 = 0; g_237 < 4; g_237++)
        {
            transparent_crc(g_3735[l_671][g_237], "g_3735[l_671][g_237]", l_666);
            if (l_666) {
if (g_959)
                            break;

                    printf("index = [%d][%d]\n", l_671, g_237);}

        };


                    l_669 = p_34;
                        l_62 = p_36;
                    }

{
        transparent_crc(g_217[g_688].f0, "g_217[g_688].f0", l_666);
        transparent_crc(g_217[g_688].f1, "g_217[g_688].f1", l_666);

if ((safe_rshift_func_uint16_t_u_u((g_1896.f1 = l_956.f0), ((((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u(l_62, (safe_rshift_func_int16_t_s_s((4294967286UL | (safe_add_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_s((((safe_lshift_func_uint8_t_u_s(1UL, 7)) || l_321) | 0x5FL), (p_34 = (((0xA259L && (248UL <= (g_112 | g_112))) || g_75) != (-3L))))) || g_971), 0x21D9L))), 13)))), g_2569)) != g_1039) && g_1896.f0) && 0x76C663A7L))))
                    {
                        struct S1 l_3596 = {21,1,11767,18,12,308};
                        g_2 = g_658;
                        g_658 = (g_274 = (l_3596 = l_251));
                    }
                    else
                    {
                        g_2569 = (g_2569 || g_1039);
                    };


                    if (l_666) printf("index = [%d]\n", g_688);

    }

                    if (p_37)
                    {

for (g_69 = 0; (g_69 <= 1); g_69 += 1)
                    {
                        l_956.f1 = (safe_lshift_func_uint16_t_u_s(((-1L) != (~(g_1106 ^ g_613))), 4));
                    };


                    return p_37;
                    }
                    else
                    {
                        return p_35;
                    }
                }
                else
                {
                    uint32_t l_670 = 1UL;

g_971 += 1;


                    l_671 = (l_670 = l_661);
                    l_657.f3 = (safe_lshift_func_int8_t_s_u(l_662, l_251.f4));
                }
            }
        }
        else
        {
            uint16_t l_685 = 0UL;
            int32_t l_737[5][10] = {{1L, 0x31256A9DL, 7L, 7L, 0x31256A9DL, 1L, 2L, 0xD88782CBL, 0L, 2L}, {1L, 0x31256A9DL, 7L, 7L, 0x31256A9DL, 1L, 2L, 0xD88782CBL, 0L, 2L}, {1L, 0x31256A9DL, 7L, 7L, 0x31256A9DL, 1L, 2L, 0xD88782CBL, 0L, 2L}, {1L, 0x31256A9DL, 7L, 7L, 0x31256A9DL, 1L, 2L, 0xD88782CBL, 0L, 2L}, {1L, 0x31256A9DL, 7L, 7L, 0x31256A9DL, 1L, 2L, 0xD88782CBL, 0L, 2L}};
            int32_t l_772 = 5L;
            int i, j;
                                               if (l_784)
                    for (l_667 = 0; (l_667 <= 2); l_667 += 1)
            {
                struct S1 l_789 = {205,17,-3036,5,156,142};
                int i;
                l_674 = g_656;
                g_40[l_667] = p_35;
                                               uint32_t BrJrJhg_900 = (-(((~((~((l_662 ^ (-(l_956.f1))))))) && (((l_674.f2 ^ (g_900 | l_674.f1)) && g_613) ^ ((~(g_688)) | (g_274.f5 | (l_789.f2 ^ (-(g_237)))))))));
int32_t BrJrJil_674_f2 = (~(((-((~(((-(g_688)) && (-(l_674.f2))))))) && ((~(l_789.f2)) << (l_662 | ((((l_956.f1 & g_274.f5) << (l_674.f1 & BrJrJhg_900)) && (~(g_613))) ^ (g_237 && g_900)))))));
int32_t BrJrJjg_688 = (~((((l_662 && l_674.f2) ^ (g_688 & (~(((~(BrJrJil_674_f2)) ^ (~(g_274.f5))))))) | (((l_956.f1 | (~(g_613))) ^ (~((g_237 ^ ((BrJrJhg_900 << l_674.f1) & g_900))))) | (-((~(l_789.f2))))))));
int32_t BrJrJkg_237 = (~(((~(((~((~(g_237)))) & ((((~(BrJrJjg_688)) & BrJrJil_674_f2) ^ g_688) ^ (~((-(l_674.f2)))))))) && ((-((~(g_274.f5)))) | ((~(((-((g_900 & l_789.f2))) && (~((~(l_956.f1))))))) && (((~(BrJrJhg_900)) | (~(l_674.f1))) ^ (g_613 << l_662)))))));
uint32_t BrJrJlg_274_f5 = (~(((~(((~((~(BrJrJhg_900)))) | g_688))) & ((~((((-((g_237 | l_674.f1))) | BrJrJkg_237) ^ (~(((-(g_274.f5)) && ((l_789.f2 ^ (~(BrJrJjg_688))) && (-((~(g_900))))))))))) && ((BrJrJil_674_f2 ^ ((l_956.f1 && (-(g_613))) && (~(l_674.f2)))) && l_662)))));
uint32_t BrJrJml_662 = (-((((((-((~((BrJrJlg_274_f5 & (-(BrJrJkg_237))))))) | (l_662 ^ (-(BrJrJil_674_f2)))) ^ (~(((g_237 && (~((g_688 && g_900)))) & (l_674.f1 & ((l_956.f1 ^ g_274.f5) ^ l_789.f2)))))) | (-(((~((~(BrJrJjg_688)))) & (~(g_613)))))) && (~((l_674.f2 | BrJrJhg_900))))));
if(g_688){
BrJrJhg_900 = g_900;
BrJrJil_674_f2 = l_674.f2;
BrJrJjg_688 = g_688;
BrJrJkg_237 = g_237;
BrJrJlg_274_f5 = g_274.f5;
BrJrJml_662 = l_662;
g_900 = (~((((~((((-(l_674.f2)) | BrJrJlg_274_f5) | ((((-(l_674.f1)) & (BrJrJjg_688 | (g_688 && g_900))) | (~(g_274.f5))) & (BrJrJml_662 ^ BrJrJhg_900))))) | ((-(((~(l_789.f2)) | g_237))) & l_956.f1)) ^ (-((-((((~((~((l_662 | BrJrJil_674_f2))))) & (-(g_613))) & (-((~(BrJrJkg_237))))))))))));
l_674.f2 = (-((((l_662 && BrJrJil_674_f2) | (~((l_674.f1 ^ BrJrJkg_237)))) ^ (((BrJrJml_662 && (~((g_613 & BrJrJjg_688)))) ^ (l_956.f1 | ((~(l_789.f2)) && ((g_237 && (BrJrJhg_900 ^ l_674.f2)) & BrJrJlg_274_f5)))) && (g_900 & (g_274.f5 & g_688))))));
                                    while (!(l_956.f1) )
{

g_714 += 1;


}
                    g_688 = (-(((-(((-((g_274.f5 | (l_956.f1 ^ BrJrJhg_900)))) && (-((g_900 | (BrJrJml_662 ^ BrJrJjg_688))))))) && (-((((((~((-(((g_237 ^ l_674.f1) & BrJrJil_674_f2))))) && l_789.f2) << ((-(l_674.f2)) & g_688)) & ((~((l_662 ^ BrJrJlg_274_f5))) & g_613)) && BrJrJkg_237))))));
g_237 = (-(((-((~((((-((~(((~(l_674.f2)) >> g_688))))) | (~(((~(((~(g_900)) & g_274.f5))) | (~(((~(g_237)) & l_789.f2))))))) ^ ((((~((g_613 ^ ((BrJrJkg_237 && BrJrJhg_900) && l_674.f1)))) ^ (~(BrJrJlg_274_f5))) ^ BrJrJil_674_f2) && (~((-((l_662 << BrJrJml_662))))))))))) ^ (~(((~((-((~((-(l_956.f1)))))))) | BrJrJjg_688))))));
LABEL_rJrJn: g_274.f5 = (~((((~((-((-((-(g_613)))))))) & (((-(l_789.f2)) && (l_662 & BrJrJml_662)) && ((~((BrJrJjg_688 | (g_274.f5 | g_237)))) ^ (l_674.f2 ^ (g_900 & g_688))))) << (((~(l_674.f1)) && ((BrJrJhg_900 ^ BrJrJil_674_f2) | BrJrJkg_237)) && ((-((~(BrJrJlg_274_f5)))) | (~((-(l_956.f1)))))))));
l_662 = (~(((~((~((((g_274.f5 & l_674.f1) & ((~(BrJrJil_674_f2)) ^ (l_789.f2 & BrJrJlg_274_f5))) && (BrJrJjg_688 | g_613)))))) | (((g_688 ^ BrJrJkg_237) && ((~((~(BrJrJhg_900)))) >> l_662)) << ((-(l_674.f2)) && (-((((~(g_237)) | l_956.f1) | ((~(BrJrJml_662)) | g_900)))))))));
                                   if ((g_274.f1>=13))
                    if(!(((l_956.f1 < l_674.f1) || l_789.f2))){
printf("g_900=%llu\n", (unsigned long long)g_900);
g_274.f5 = (~(((~((~(((g_900 | (~(BrJrJhg_900))) | (~((~((-(l_674.f1))))))))))) ^ ((BrJrJkg_237 && (((-(l_789.f2)) >> (BrJrJlg_274_f5 | l_662)) & l_674.f2)) >> (((-((~(g_688)))) << (BrJrJjg_688 << (BrJrJil_674_f2 & g_237))) && (~((l_956.f1 && (g_274.f5 && ((-(BrJrJml_662)) | g_613))))))))));
break;
}
if((g_688 < l_956.f1)){
printf("l_674.f2=%lld\n", (long long)l_674.f2);
continue;
}
                                    if (!((l_789.f5<=142)) )
{

{
        transparent_crc(g_217[g_759].f0, "g_217[g_759].f0", l_667);
        transparent_crc(g_217[g_759].f1, "g_217[g_759].f1", l_667);
        if (l_667) printf("index = [%d]\n", g_759);

    }

}
                    if((!BrJrJml_662)){
printf("g_688=%lld\n", (long long)g_688);
l_674.f2 = (-((((BrJrJkg_237 ^ ((((g_613 ^ BrJrJjg_688) && l_674.f1) | l_789.f2) >> (BrJrJlg_274_f5 >> l_674.f2))) & (~(((g_274.f5 >> (~(l_956.f1))) ^ (~(g_900)))))) | (~((~((((~((BrJrJil_674_f2 ^ (~((-(l_662))))))) ^ (~((BrJrJml_662 & (-((~(g_237)))))))) << (g_688 && BrJrJhg_900)))))))));
}
LABEL_rJrJo: if((!BrJrJjg_688)){
printf("g_237=%lld\n", (long long)g_237);
l_662 = (~(((~((BrJrJml_662 && BrJrJil_674_f2))) && ((~((~(g_237)))) && (BrJrJlg_274_f5 && ((((l_789.f2 | (~((g_613 & BrJrJkg_237)))) ^ ((((l_662 | BrJrJhg_900) && l_674.f2) << g_900) ^ BrJrJjg_688)) | (~((g_688 >> (l_956.f1 | g_274.f5))))) ^ (-((~(l_674.f1))))))))));
BrJrJkg_237 = (-((((((g_274.f5 | (~(l_674.f1))) & (~(BrJrJhg_900))) ^ ((((l_956.f1 << (~((BrJrJkg_237 | l_662)))) & g_237) << (BrJrJlg_274_f5 ^ BrJrJml_662)) && ((~((~(BrJrJjg_688)))) & (l_674.f2 & g_613)))) | (-((-(BrJrJil_674_f2))))) >> ((~((-((~(l_789.f2)))))) | (~((g_900 << (-(g_688)))))))));
}
if(!((g_237 < g_688))){
printf("g_274.f5=%llu\n", (unsigned long long)g_274.f5);
l_662 = (~((((~((~(g_900)))) ^ ((-(((~((l_674.f1 << (BrJrJkg_237 >> (-(l_956.f1)))))) | (((~((~((-(l_662)))))) ^ ((~(BrJrJjg_688)) && (-((~((g_274.f5 & BrJrJml_662))))))) && (~(BrJrJil_674_f2)))))) & (-(l_674.f2)))) & ((g_237 && ((~(BrJrJhg_900)) ^ g_688)) >> ((BrJrJlg_274_f5 >> l_789.f2) && (-(g_613)))))));
break;
}
if((g_613>253)){
printf("l_662=%llu\n", (unsigned long long)l_662);
g_274.f5 = (~(((-((~(((l_662 && (~(l_674.f1))) & BrJrJil_674_f2))))) && (~((((~((-(g_613)))) << (-((~((-(BrJrJml_662))))))) | (~((~(((~(((((BrJrJjg_688 & g_237) & ((BrJrJkg_237 ^ g_900) | BrJrJhg_900)) | (~(l_674.f2))) << (g_274.f5 & ((-(BrJrJlg_274_f5)) ^ (g_688 | l_956.f1)))))) & (~(l_789.f2)))))))))))));
BrJrJjg_688 = (~(((((~((((g_613 << g_274.f5) & BrJrJlg_274_f5) ^ (~(BrJrJhg_900))))) ^ ((g_237 >> (~((g_900 ^ g_688)))) && l_662)) << (((BrJrJml_662 >> (~(l_956.f1))) >> (~((-(BrJrJkg_237))))) >> (-(((BrJrJjg_688 && l_674.f2) << l_789.f2))))) | (~((~((l_674.f1 && BrJrJil_674_f2))))))));
}
}
g_900 = BrJrJhg_900;
l_674.f2 = BrJrJil_674_f2;
g_688 = BrJrJjg_688;
g_237 = BrJrJkg_237;
g_274.f5 = BrJrJlg_274_f5;
l_662 = BrJrJml_662;

                    if ((safe_sub_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_s((((safe_sub_func_int16_t_s_s(((g_40[l_667] = (p_37 || (safe_rshift_func_uint8_t_u_s((safe_lshift_func_int16_t_s_u(((((((g_40[l_667] || (248UL || l_666)) || l_685) != (l_321 != ((safe_unary_minus_func_uint8_t_u((g_264 = ((((+0x0FL) != 0x73L) & (g_688 = (p_35 ^ g_658.f5))) ^ 4UL)))) && g_658.f1))) & g_2.f0) == 1UL) && p_37), l_666)), 3)))) >= l_685), 0UL)) != g_163) || g_2.f4), 5)) >= g_2.f5), g_217[0].f0)))
                {
                    int32_t l_713[1];
                    int32_t l_715[1];
                    struct S1 l_788 = {162,11,-9528,76,126,34};
                    struct S0 l_790 = {0xEACA67FEL,-2018};
                    int i;
                                                        while (((l_667>2) || (g_63<4294967295U)) )
{

l_956.f0 -= 1;


}
                    for (i = 0; i < 1; i++)
                        l_713[i] = (-1L);
                    for (i = 0; i < 1; i++)
                        l_715[i] = 7L;
                    l_666 = g_40[l_667];
                    l_216[5][2][4] = g_130;
                    if ((safe_sub_func_int8_t_s_s((safe_mod_func_uint8_t_u_u(0x86L, l_685)), ((safe_add_func_int32_t_s_s((((l_713[0] = (g_2.f0 && ((((safe_rshift_func_uint16_t_u_s((l_666 = (l_251.f3 = (!(safe_add_func_uint16_t_u_u((p_36 <= ((g_714 = (safe_unary_minus_func_uint32_t_u((g_613 & (safe_sub_func_int16_t_s_s(g_658.f5, (safe_rshift_func_int16_t_s_u(((safe_add_func_int16_t_s_s(((safe_sub_func_int32_t_s_s(l_685, 1UL)) ^ (safe_lshift_func_int16_t_s_u((safe_sub_func_int8_t_s_s((((((((p_34 > 0L) != p_36) || l_713[0]) || l_58[4]) & p_37) > p_35) ^ g_69), g_656.f3)), g_40[l_667]))), l_685)) | g_63), 7)))))))) & g_40[l_667])), 65526UL))))), g_274.f1)) || g_658.f4) == l_662) && 0x040FL))) >= l_667) == l_715[0]), p_34)) != l_662))))
                    {
                        uint8_t l_758 = 0UL;
                        int32_t l_773 = 9L;
                        g_656.f2 = (((+((safe_lshift_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(((((g_40[l_667] = (safe_sub_func_uint32_t_u_u((p_34 = ((safe_add_func_uint8_t_u_u(((1UL == ((((g_714 && 0x80L) == (safe_mod_func_int16_t_s_s((+(g_658.f3 = (((g_656.f4 = ((p_37 == ((safe_sub_func_uint32_t_u_u(((safe_mod_func_int32_t_s_s(((!(((p_37 != (+((~((safe_sub_func_int8_t_s_s(p_37, (l_737[3][3] != ((safe_sub_func_int32_t_s_s(l_685, g_217[0].f1)) < 0L)))) <= 0L)) < p_35))) || g_224) | g_63)) < 0xFC57L), p_37)) >= p_35), p_34)) || p_35)) == g_714)) <= l_713[0]) > p_35))), g_2.f3))) <= g_740) != 254UL)) ^ 0xA28A1E5FL), 0x79L)) && 0x4DL)), p_35))) || 0xF26FL) && 0xDB531D12L) && l_737[1][2]), g_658.f4)), 12)) & p_36)) || g_237) == 0x93CBL);
                        l_666 = ((((((0x01DBL >= (safe_add_func_int16_t_s_s(((safe_sub_func_int8_t_s_s((g_759 = ((p_36 = 0xB0L) <= ((g_40[l_667] = ((safe_sub_func_int16_t_s_s((p_37 | ((safe_rshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_u((safe_unary_minus_func_int16_t_s((g_658.f2 && ((safe_add_func_int8_t_s_s((l_251.f0 ^ (((((l_737[3][3] = (3L < (safe_rshift_func_int8_t_s_s(0xE8L, 6)))) >= 0xE6CEL) | l_58[4]) <= l_758) >= p_37)), 0x13L)) >= p_35)))), l_685)), 1)) == (-1L))), (-1L))) >= g_211)) || p_35))), p_35)) <= p_37), 0x125FL))) <= 0L) > p_37) && 0x88C7L) < p_34) >= p_35);
                        l_772 = ((0xB5CFBE9DL > (l_666 = (((g_40[l_667] = p_34) != (safe_add_func_uint8_t_u_u(l_758, ((((0xA9L ^ ((safe_rshift_func_uint16_t_u_s((safe_mod_func_int16_t_s_s(p_36, (safe_rshift_func_uint8_t_u_s(g_274.f5, g_217[0].f0)))), 5)) < ((l_737[3][3] = ((safe_sub_func_uint8_t_u_u((safe_add_func_int16_t_s_s(1L, ((g_174 | 0x26EF1429L) | l_715[0]))), 255UL)) | p_35)) < p_37))) || l_758) <= g_658.f5) == l_758)))) | g_714))) == 1L);
                        l_773 = 0xDC06628CL;
                    }
                    else
                    {
                        uint16_t l_787 = 0x9C7CL;

{
                int32_t l_3528 = (-10L);
                g_224 = (g_2214 <= (safe_lshift_func_int8_t_s_u((((l_956.f1 > 1UL) > (safe_lshift_func_uint8_t_u_u(0x0AL, (((!((l_842 = l_3528) ^ (-4L))) < (p_34 = (((((l_321 || g_656.f5) == 0xD141EB83L) & g_656.f4) >= 1UL) & g_264))) | 0xA348L)))) || (-1L)), 0)));
                l_789.f3 = ((((((0x23L < (((l_3528 == ((p_34 > (l_662 & k)) || ((((safe_sub_func_int32_t_s_s((g_237 = l_674.f3), (((0xCEL == (safe_add_func_int32_t_s_s(l_842, (((((((((0xF731AC28L < g_3242[3]) | g_130.f0) | g_656.f1) == g_971) <= 0x620DL) & l_674.f3) >= (-7L)) > 0xD885ADEAL) | k)))) == l_824) || 4294967295UL))) || 0x35FAL) <= l_3528) <= 0x8EDAE74BL))) != 65532UL) <= l_674.f4)) & l_450) | l_321) & g_264) | g_1058) & g_130.f0);
            }

                    l_772 = ((safe_lshift_func_int16_t_s_u(0xDC95L, 0)) || (((((!(!(l_772 > ((safe_sub_func_int32_t_s_s((l_715[0] = (0xFB8B5851L && (safe_mod_func_uint32_t_u_u((l_666 = p_37), (safe_add_func_int16_t_s_s((-7L), (0x1189L <= l_784))))))), l_713[0])) > ((safe_rshift_func_uint8_t_u_s(g_740, 2)) <= l_713[0]))))) || g_69) & 0x0506L) != 0xD8L) >= l_787));
                        l_789 = l_788;
                        g_217[0] = l_790;
                    }
                }
                else
                {
                    for (g_211 = (-2); (g_211 > (-22)); g_211 = safe_sub_func_uint8_t_u_u(g_211, 5))
                    {
                        return l_251.f2;
                    }

{
        transparent_crc(g_3242[g_3324], "g_3242[g_3324]", g_224);
        if (g_224) printf("index = [%d]\n", g_3324);

    }

                    return g_2.f2;
                }
            }
            l_737[1][1] = (((((safe_add_func_int16_t_s_s((((safe_lshift_func_int8_t_s_u(p_36, 6)) < g_658.f5) ^ (p_37 || ((p_34 & (g_2.f5 & p_35)) && ((safe_mod_func_uint32_t_u_u((safe_mod_func_uint16_t_u_u(((+((g_688 == (g_2.f5 > (!p_35))) != 0UL)) && g_688), 0x16EEL)), l_251.f2)) | (-1L))))), l_666)) & g_40[1]) <= g_274.f3) | 0x4332143FL) || (-7L));
        }
        if ((((l_251.f3 = (safe_lshift_func_int16_t_s_s(p_36, (safe_sub_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((((0x19L & g_2.f1) & (safe_unary_minus_func_uint16_t_u((((safe_mod_func_uint8_t_u_u(((safe_sub_func_int8_t_s_s((((safe_lshift_func_int16_t_s_u((safe_add_func_uint16_t_u_u((p_35 ^ g_40[1]), (0L ^ g_658.f3))), (safe_mod_func_uint32_t_u_u((safe_mod_func_uint16_t_u_u(((((safe_rshift_func_int16_t_s_u(g_237, g_163)) & p_37) == p_34) < p_34), (-6L))), 0x4BE9801AL)))) || g_274.f1) | 0xF5L), g_658.f1)) > 0x83681970L), g_759)) < l_824) ^ 0x6EL)))) || 8UL) || l_320[4][0][2]), l_652)), g_211))))) & 0x755A4503L) > 7L))
        {
            l_216[5][2][4].f1 = g_264;
            return l_320[5][0][1];
        }
        else
        {
            uint8_t l_837 = 0xE3L;
            int32_t l_845[10] = {0x30602858L, 0x857EE561L, 0x30602858L, 0x857EE561L, 0x30602858L, 0x857EE561L, 0x30602858L, 0x857EE561L, 0x30602858L, 0x857EE561L};
            int32_t l_865 = 0x40867A90L;
            uint32_t l_868[6] = {1UL, 0x76233594L, 1UL, 0x76233594L, 1UL, 0x76233594L};
            struct S1 l_869 = {65,6,-13417,-17,32,59};
            int32_t l_885 = 5L;
            struct S0 l_937 = {0x5BEEEA9BL,-429};
            int i;
            for (p_34 = 0; (p_34 <= 37); ++p_34)
            {
                uint16_t l_831 = 65527UL;
                int32_t l_834 = 0x4BD17104L;
                int32_t l_843 = 0xD9FA71C5L;
                if ((!(safe_sub_func_uint16_t_u_u((~(l_831 = 0x2A44E312L)), (+(((+(((p_34 ^ (((l_662 && g_2.f0) >= (l_834 = g_217[0].f1)) > (safe_mod_func_uint8_t_u_u((l_667 == ((l_216[5][2][4].f1 = ((l_837 != 0xEDL) ^ ((safe_rshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s((0xAEEAL <= g_658.f3), p_37)), l_842)) == 0x1FL))) > g_658.f4)), (-4L))))) > l_843) ^ 0x40L)) < l_843) < 0x7E2EL))))))
                {
                    int8_t l_844 = 0x78L;

l_122 -= 1;


                    l_216[3][1][2] = g_217[0];

g_969 -= 1;


                    l_845[2] = l_844;
                }
                else
                {
                    int16_t l_864 = (-1L);
                    int32_t l_886 = (-1L);
                    l_865 = (p_36 || (safe_rshift_func_int16_t_s_s((((safe_unary_minus_func_int8_t_s((((safe_mod_func_uint32_t_u_u((((safe_mod_func_int8_t_s_s((safe_lshift_func_int8_t_s_u((l_674.f1 < g_75), l_666)), (g_264 & g_2.f5))) == (safe_mod_func_int16_t_s_s((((safe_add_func_int16_t_s_s(((l_845[2] = (g_237 == l_845[5])) != ((safe_lshift_func_int16_t_s_s((l_863 = ((safe_sub_func_int32_t_s_s(1L, 3L)) >= l_824)), 3)) | 0x6F77L)), p_36)) < l_837) ^ 1UL), g_217[0].f1))) != 0x8767L), 4294967295UL)) & l_837) | g_658.f4))) <= l_864) == l_824), g_2.f2)));
                    for (l_843 = 6; (l_843 == 21); l_843 = safe_add_func_int8_t_s_s(l_843, 4))
                    {
                        uint16_t l_872 = 0xC883L;
                        l_868[3] = l_843;
                        g_656 = l_869;
                        l_834 = ((((g_688 <= ((((safe_rshift_func_int8_t_s_u(l_872, (((g_658.f2 | (safe_rshift_func_uint8_t_u_u(((l_886 = ((((0x59EBL != g_875) < ((safe_add_func_int32_t_s_s((((p_34 > (safe_mod_func_int8_t_s_s(((p_36 = (safe_rshift_func_int16_t_s_s(g_2.f1, ((p_34 || (safe_rshift_func_uint16_t_u_u((g_875 >= l_884[4]), 10))) < 0x03L)))) != l_885), 255UL))) == 0L) <= 255UL), p_35)) > p_34)) < l_831) & p_35)) != l_864), p_37))) & l_831) != p_37))) == g_112) != p_35) != 1UL)) < l_864) || g_688) ^ 0xAF596846L);
                    }
                    l_251.f1 = (l_62 = 0x2802AEF7L);
                    if (((((safe_sub_func_int16_t_s_s((-1L), (l_886 = (6UL | g_274.f2)))) ^ 0x2E139A74L) | (l_864 | (safe_rshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s((safe_lshift_func_int8_t_s_s((((+(g_2.f3 = (((!(l_62 = (safe_add_func_uint32_t_u_u((((~(p_37 = l_842)) & (g_900 = 0L)) | (g_656.f2 <= ((safe_add_func_int16_t_s_s(4L, g_658.f5)) | 0x6DL))), g_656.f2)))) && p_37) == l_251.f4))) || g_688) > p_35), l_834)), p_34)), 7)))) && 0L))
                    {
                        uint32_t l_903 = 0UL;

if (((((safe_sub_func_int16_t_s_s((-1L), (l_652 = (6UL | l_869.f2)))) ^ 0x2E139A74L) | (g_1204 | (safe_rshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s((safe_lshift_func_int8_t_s_s((((+(g_2.f3 = (((!(g_1568 = (safe_add_func_uint32_t_u_u((((~(g_415 = g_1135)) & (g_2214 = 0L)) | (l_869.f2 <= ((safe_add_func_int16_t_s_s(4L, g_2.f5)) | 0x6DL))), l_869.f2)))) && g_415) == g_2.f4))) || l_652) > p_35), i)), g_69)), 7)))) && 0L))
                    {
                        uint32_t l_903 = 0UL;
                        l_903 = (-1L);
                        g_656 = l_869;
                        l_869.f1 = ((safe_rshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_s((l_320[1][0][3] ^ (((g_2.f3 = 0x1401L) ^ (g_2.f1 & (safe_mod_func_uint8_t_u_u((safe_add_func_int8_t_s_s(((p_36 < (safe_rshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_s((g_1056 = (safe_lshift_func_uint16_t_u_u((g_415 = ((safe_add_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u(p_36, (!((((0x6F3E371DL < (g_2.f1 = (safe_mod_func_uint16_t_u_u(1UL, k)))) & (safe_mod_func_int32_t_s_s((l_652 = ((((+((((safe_add_func_int16_t_s_s((i = (safe_mod_func_int16_t_s_s((i && p_35), l_652))), g_415)) || 65530UL) && 1UL) >= 0xFBA8L)) > g_971) <= 0x54L) & 0xD6L)), l_652))) > g_1204) && l_868[4])))), g_217[0].f0)), 4294967295UL)) != 0UL)), g_69))), p_36)), l_869.f1))) ^ 0UL), g_971)), 0x56L)))) && p_35)), 6)), 13)) < g_2.f3);
                    }
                    else
                    {
                        g_656.f1 = ((safe_rshift_func_uint16_t_u_s((+g_1056), 8)) == (l_869.f1 | (l_869.f5 = p_36)));
                        if (i)
                            break;
                    };


                    l_903 = (-1L);
                        l_674 = g_656;
                        g_656.f1 = ((safe_rshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_s((l_320[1][0][3] ^ (((l_251.f3 = 0x1401L) ^ (g_658.f1 & (safe_mod_func_uint8_t_u_u((safe_add_func_int8_t_s_s(((p_36 < (safe_rshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_s((g_415 = (safe_lshift_func_uint16_t_u_u((p_37 = ((safe_add_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u(p_36, (!((((0x6F3E371DL < (l_251.f1 = (safe_mod_func_uint16_t_u_u(1UL, l_652)))) & (safe_mod_func_int32_t_s_s((l_886 = ((((+((((safe_add_func_int16_t_s_s((l_666 = (safe_mod_func_int16_t_s_s((l_666 && p_35), l_843))), p_37)) || 65530UL) && 1UL) >= 0xFBA8L)) > g_740) <= 0x54L) & 0xD6L)), g_688))) > l_864) && l_58[4])))), g_217[0].f0)), 4294967295UL)) != 0UL)), p_34))), p_36)), g_656.f1))) ^ 0UL), g_63)), 0x56L)))) && p_35)), 6)), 13)) < g_658.f3);
                    }
                    else
                    {
                        l_674.f1 = ((safe_rshift_func_uint16_t_u_s((+l_831), 8)) == (g_274.f1 | (g_656.f5 = p_36)));

g_69 += 1;



if (g_2098)
                            break;

                    if (l_834)
                            break;
                    }
                }
                g_130 = l_937;

{
                        int i;
                        g_217[l_865] = g_217[0];
                        l_937 = (g_1896 = (g_217[l_865] = l_937));
                    }

                    l_834 = (safe_mod_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s(((!l_834) != (g_174 ^ (l_62 = ((((safe_unary_minus_func_int16_t_s(g_217[0].f0)) == (g_658.f2 & ((safe_rshift_func_uint8_t_u_s(((safe_lshift_func_uint8_t_u_u(((((g_613 = 0x36L) || g_714) < (!((((((l_674.f1 = (safe_mod_func_uint32_t_u_u((p_36 | ((l_843 = (l_845[0] = ((safe_unary_minus_func_int8_t_s(8L)) && (0x85L > l_869.f4)))) < 0x85L)), p_35))) || g_274.f4) || g_40[1]) ^ g_237) < g_217[0].f0) ^ 0x1EL))) || (-1L)), 4)) < g_658.f4), p_35)) == g_658.f1))) ^ l_216[5][2][4].f1) && g_658.f1)))), p_34)), l_869.f2));
            }
            g_875 = (safe_add_func_int16_t_s_s(p_36, (-1L)));
            l_937 = l_956;
        }
    }
    g_647 = g_688;
    return g_274.f1;
}







static int8_t func_45(int32_t p_46, int32_t p_47, uint8_t p_48, int8_t p_49, uint8_t p_50)
{
    uint32_t l_68 = 0x43CAE23FL;
    int32_t l_85 = 0x03EC6B4EL;
    int32_t l_86 = (-8L);
    uint32_t l_87 = 0UL;
    int32_t l_88 = 0x5644FE3DL;
    int32_t l_89 = 0xFE20FE05L;
    uint8_t l_110 = 0xE6L;
    int32_t l_111 = 0xD894E178L;
    int32_t l_113 = 0x59AB7399L;

{
                    l_113 = g_174;
                }

                    g_40[1] = func_52((g_40[2] != func_64(((((p_46 >= ((g_69 = l_68) <= ((l_89 = ((safe_rshift_func_int16_t_s_u(((l_88 = (0x9AL == ((~((safe_rshift_func_uint16_t_u_s((l_87 = (0xAB19L | ((g_75 = 0x249DL) ^ ((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint8_t_u_u((l_86 = (+((l_85 = (safe_sub_func_int8_t_s_s((l_68 & (1L <= g_40[1])), g_2.f4))) && g_2.f1))), l_68)), p_50)) == 0x6341L)))), l_68)) | l_68)) ^ l_68))) != l_68), g_2.f5)) > g_2.f1)) || p_48))) && l_86) || l_87) >= 0xEEL), l_68, g_2.f4)), l_68, p_50, g_40[1], g_2.f1);
    l_89 = (p_49 & (g_40[1] = (g_75 ^ (safe_lshift_func_int8_t_s_u((safe_mod_func_uint8_t_u_u(p_50, (p_48 = p_46))), 2)))));
    l_113 = ((safe_lshift_func_uint16_t_u_u((l_85 = l_85), g_2.f4)) ^ (p_48 >= (g_112 = ((safe_lshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((safe_unary_minus_func_int8_t_s(((l_111 = (4294967287UL & (((l_86 = (safe_mod_func_int32_t_s_s(p_47, (safe_sub_func_int32_t_s_s(g_2.f3, g_2.f5))))) || (l_89 = ((safe_add_func_uint8_t_u_u(((l_88 = g_2.f2) & (g_75 <= g_40[1])), p_48)) > p_49))) & l_110))) < p_50))), 0)), p_48)) && g_2.f5))));
    return p_47;
}







static uint8_t func_52(int16_t p_53, uint32_t p_54, int16_t p_55, int8_t p_56, int8_t p_57)
{
    return p_56;
}







static uint16_t func_64(uint8_t p_65, uint16_t p_66, int32_t p_67)
{
    uint32_t l_92 = 4294967291UL;

g_1204 += 1;


        g_2.f2 = (p_67 = g_69);

{
                    g_3324 = g_900;
                }


for (g_75 = 0; g_75 < 3; g_75++)
            g_40[g_75] = 0x3A7C282BL;

        for (g_63 = (-8); (g_63 < 2); g_63 = safe_add_func_uint16_t_u_u(g_63, 5))
    {

if (g_688)
                            break;

        return g_69;
    }
    return l_92;
}





int main (int argc, char* argv[])
{
    int i, j, k;
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
    transparent_crc(g_2.f0, "g_2.f0", print_hash_value);
    transparent_crc(g_2.f1, "g_2.f1", print_hash_value);
    transparent_crc(g_2.f2, "g_2.f2", print_hash_value);
    transparent_crc(g_2.f3, "g_2.f3", print_hash_value);
    transparent_crc(g_2.f4, "g_2.f4", print_hash_value);
    transparent_crc(g_2.f5, "g_2.f5", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_40[i], "g_40[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_63, "g_63", print_hash_value);
    transparent_crc(g_69, "g_69", print_hash_value);
    transparent_crc(g_75, "g_75", print_hash_value);
    transparent_crc(g_112, "g_112", print_hash_value);
    transparent_crc(g_130.f0, "g_130.f0", print_hash_value);
    transparent_crc(g_130.f1, "g_130.f1", print_hash_value);
    transparent_crc(g_163, "g_163", print_hash_value);
    transparent_crc(g_174, "g_174", print_hash_value);
    transparent_crc(g_211, "g_211", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_217[i].f0, "g_217[i].f0", print_hash_value);
        transparent_crc(g_217[i].f1, "g_217[i].f1", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_224, "g_224", print_hash_value);
    transparent_crc(g_237, "g_237", print_hash_value);
    transparent_crc(g_264, "g_264", print_hash_value);
    transparent_crc(g_274.f0, "g_274.f0", print_hash_value);
    transparent_crc(g_274.f1, "g_274.f1", print_hash_value);
    transparent_crc(g_274.f2, "g_274.f2", print_hash_value);
    transparent_crc(g_274.f3, "g_274.f3", print_hash_value);
    transparent_crc(g_274.f4, "g_274.f4", print_hash_value);
    transparent_crc(g_274.f5, "g_274.f5", print_hash_value);
    transparent_crc(g_310, "g_310", print_hash_value);
    transparent_crc(g_415, "g_415", print_hash_value);
    transparent_crc(g_613, "g_613", print_hash_value);
    transparent_crc(g_647, "g_647", print_hash_value);
    transparent_crc(g_656.f0, "g_656.f0", print_hash_value);
    transparent_crc(g_656.f1, "g_656.f1", print_hash_value);
    transparent_crc(g_656.f2, "g_656.f2", print_hash_value);
    transparent_crc(g_656.f3, "g_656.f3", print_hash_value);
    transparent_crc(g_656.f4, "g_656.f4", print_hash_value);
    transparent_crc(g_656.f5, "g_656.f5", print_hash_value);
    transparent_crc(g_658.f0, "g_658.f0", print_hash_value);
    transparent_crc(g_658.f1, "g_658.f1", print_hash_value);
    transparent_crc(g_658.f2, "g_658.f2", print_hash_value);
    transparent_crc(g_658.f3, "g_658.f3", print_hash_value);
    transparent_crc(g_658.f4, "g_658.f4", print_hash_value);
    transparent_crc(g_658.f5, "g_658.f5", print_hash_value);
    transparent_crc(g_688, "g_688", print_hash_value);
    transparent_crc(g_714, "g_714", print_hash_value);
    transparent_crc(g_740, "g_740", print_hash_value);
    transparent_crc(g_759, "g_759", print_hash_value);
    transparent_crc(g_875, "g_875", print_hash_value);
    transparent_crc(g_900, "g_900", print_hash_value);
    transparent_crc(g_959, "g_959", print_hash_value);
    transparent_crc(g_969, "g_969", print_hash_value);
    transparent_crc(g_971, "g_971", print_hash_value);
    transparent_crc(g_1039, "g_1039", print_hash_value);
    transparent_crc(g_1056, "g_1056", print_hash_value);
    transparent_crc(g_1058, "g_1058", print_hash_value);
    transparent_crc(g_1106, "g_1106", print_hash_value);
    transparent_crc(g_1135, "g_1135", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            for (k = 0; k < 2; k++)
            {
                transparent_crc(g_1177[i][j][k], "g_1177[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_1178, "g_1178", print_hash_value);
    transparent_crc(g_1184, "g_1184", print_hash_value);
    transparent_crc(g_1204, "g_1204", print_hash_value);
    transparent_crc(g_1568, "g_1568", print_hash_value);
    transparent_crc(g_1895.f0, "g_1895.f0", print_hash_value);
    transparent_crc(g_1895.f1, "g_1895.f1", print_hash_value);
    transparent_crc(g_1896.f0, "g_1896.f0", print_hash_value);
    transparent_crc(g_1896.f1, "g_1896.f1", print_hash_value);
    transparent_crc(g_1897, "g_1897", print_hash_value);
    transparent_crc(g_2098, "g_2098", print_hash_value);
    transparent_crc(g_2214, "g_2214", print_hash_value);
    transparent_crc(g_2317, "g_2317", print_hash_value);
    transparent_crc(g_2569, "g_2569", print_hash_value);
    transparent_crc(g_2667, "g_2667", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        transparent_crc(g_3242[i], "g_3242[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_3324, "g_3324", print_hash_value);
    transparent_crc(g_3484, "g_3484", print_hash_value);
    transparent_crc(g_3662, "g_3662", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            transparent_crc(g_3735[i][j], "g_3735[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

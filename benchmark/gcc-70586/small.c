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
void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);static long __undefined;



static int8_t g_4 = (-1L);
static uint8_t g_12 = 0UL;
static int32_t g_22 = 0x5EE56E31L;
static uint16_t g_63 = 65532UL;
static int8_t g_83 = (-1L);
static uint32_t g_103 = 1UL;
static int32_t g_115 = 0xDA9491B2L;
static uint32_t g_161 = 8UL;
static uint16_t g_172[9] = {65535UL,65535UL,65535UL,65535UL,65535UL,65535UL,65535UL,65535UL,65535UL};
static uint8_t g_173 = 1UL;
static int16_t g_188 = 0x3C2DL;
static uint8_t g_217 = 0x25L;
static int32_t g_247 = 7L;
static uint16_t g_315 = 0x66F1L;
static uint32_t g_359[10][7] = {{0x3FA7BD63L,0x3FA7BD63L,4294967295UL,1UL,2UL,4294967286UL,0x86D169E2L},{4294967286UL,4294967295UL,2UL,0xEBBF1EA3L,4294967295UL,0UL,0xD3F18FECL},{4294967295UL,0xB191E2DDL,0x894467B8L,4294967295UL,2UL,0xD3F18FECL,0x3FA7BD63L},{1UL,0xC4126F55L,0xC6494F46L,0x70286BD2L,0xEF9FE435L,0xEF9FE435L,0x70286BD2L},{4294967291UL,0xC4126F55L,4294967291UL,0x3FA7BD63L,0xD3F18FECL,2UL,4294967295UL},{0UL,0xB191E2DDL,0xB191E2DDL,4294967291UL,0xD4A24541L,0xB2788A97L,0UL},{1UL,0xC6494F46L,0xD3F18FECL,1UL,2UL,1UL,4294967295UL},{0x86D169E2L,4294967295UL,2UL,0xD4A24541L,1UL,0xD3F18FECL,1UL},{0xB191E2DDL,2UL,2UL,0xB191E2DDL,4294967286UL,4294967291UL,0xD3F18FECL},{1UL,4294967295UL,0xD3F18FECL,2UL,0xC4126F55L,0xD4A24541L,0xAF15F833L}};
static int8_t g_361 = 0xE8L;
static uint16_t g_538 = 0x2A52L;
static uint32_t g_540 = 0x03F238A4L;
static int32_t g_541 = 2L;
static int16_t g_543[3] = {0xA684L,0xA684L,0xA684L};
static uint16_t g_813[7][1] = {{1UL},{1UL},{1UL},{1UL},{1UL},{1UL},{1UL}};
static int16_t g_866[8][10] = {{0xE09DL,0L,0x2212L,0x2212L,0L,0xE09DL,(-1L),0x4458L,0L,0x4458L},{0xF029L,0x2212L,0L,0x98E1L,0L,0x2212L,0xF029L,(-1L),0x1ED0L,0x1ED0L},{0xF029L,0x1ED0L,0xE09DL,0L,0L,0xE09DL,0x1ED0L,0xF029L,0L,(-1L)},{0xE09DL,0x1ED0L,0xF029L,0L,(-1L),0L,0xF029L,0x1ED0L,0xE09DL,0L},{0L,0x2212L,0xF029L,(-1L),0x1ED0L,0x1ED0L,(-1L),0xF029L,0x2212L,0L},{0x2212L,0L,0xE09DL,(-1L),0x4458L,0L,0x4458L,(-1L),0xE09DL,0L},{0L,0xF029L,0L,0L,0x4458L,0x98E1L,0x98E1L,0x4458L,0L,0L},{0x4458L,0x4458L,0x2212L,0L,0x1ED0L,0x98E1L,0xE09DL,0x98E1L,0x1ED0L,0L}};
static int32_t g_949[3][9][9] = {{{0x19FE0FA4L,0x004CDDF9L,0xA2352584L,1L,4L,(-1L),(-1L),(-4L),0xB51D2F47L},{0x02FF677CL,0xFB20F18DL,0x3FD00C3BL,4L,4L,0x3FD00C3BL,0xFB20F18DL,0x02FF677CL,0xA2352584L},{0L,0L,0x3C1CCF04L,0L,4L,0L,4L,0x80CBB97EL,1L},{0x94A69707L,(-4L),0x2773E334L,0x80CBB97EL,0x004CDDF9L,0x5E55A83DL,(-1L),(-7L),0xA2352584L},{(-1L),0xB7AAB78DL,2L,(-1L),0x7E126A91L,(-5L),1L,0L,0xB51D2F47L},{0x19FE0FA4L,0x94A69707L,0xC2B10BA8L,(-1L),(-1L),0L,0x19FE0FA4L,(-4L),(-1L)},{0xA537F120L,3L,0x0F8F2D30L,0x80CBB97EL,0L,0x3FD00C3BL,6L,0xA537F120L,0x1374F73BL},{0x04754667L,(-1L),0xA2352584L,0L,1L,0L,0xDE5814CDL,5L,0xF3A357CCL},{4L,5L,1L,1L,8L,4L,5L,0x765C689EL,0xA537F120L}},{{0L,0x62F880C4L,1L,0x514180D2L,0x62F880C4L,0x04754667L,0x004628F1L,1L,6L},{0x622710D1L,0x0710E789L,0xA537F120L,1L,0x1FC49A14L,1L,4L,0L,4L},{5L,(-5L),0L,0xA5559F9FL,0x3772736DL,1L,0x004628F1L,5L,3L},{0x9C3268C6L,0L,3L,0L,(-5L),0L,5L,5L,0L},{0x87EFAE68L,0L,0xB7AAB78DL,0L,0x87EFAE68L,4L,0xDE5814CDL,0x0B2B9C01L,0x04754667L},{5L,(-5L),4L,0x514180D2L,0x004628F1L,0x02FF677CL,1L,0L,0x7E126A91L},{4L,0x0710E789L,0x62D64424L,(-3L),1L,4L,0x0710E789L,0x1FC49A14L,4L},{0x11A29F7FL,0x62F880C4L,(-2L),0xDE5814CDL,0xA5559F9FL,0L,0x004628F1L,0x11A29F7FL,0L},{0x11A29F7FL,5L,0xA537F120L,0x11A29F7FL,(-5L),1L,0x1FC49A14L,0L,(-1L)}},{{4L,0x1FC49A14L,0xB7AAB78DL,0xA5559F9FL,0x52EAD88AL,1L,1L,0x765C689EL,3L},{5L,0xB2702615L,0x7E126A91L,0x0B2B9C01L,(-5L),0x04754667L,0x61EF5EBCL,0L,0xFB20F18DL},{0x87EFAE68L,0x622710D1L,0x02FF677CL,1L,0xA5559F9FL,4L,6L,0xA5559F9FL,0xFB20F18DL},{0x9C3268C6L,(-5L),(-1L),0xDE5814CDL,1L,0L,1L,0x9C3268C6L,3L},{5L,5L,0x62D64424L,(-3L),0x004628F1L,(-2L),5L,0x1FC49A14L,(-1L)},{0x622710D1L,0xA5559F9FL,1L,0xDE5814CDL,0x87EFAE68L,(-4L),1L,1L,0L},{0L,0x61EF5EBCL,4L,1L,(-5L),0L,(-5L),1L,4L},{4L,4L,0x02FF677CL,0x0B2B9C01L,0x3772736DL,1L,8L,0x1FC49A14L,0x7E126A91L},{0x9C3268C6L,0xB2702615L,0xF3A357CCL,0xA5559F9FL,0x1FC49A14L,0L,0x61EF5EBCL,0x9C3268C6L,0x04754667L}}};
static int16_t g_974 = (-1L);
static uint8_t g_1129 = 252UL;
static int32_t g_1215[6] = {0x2F236E6CL,0x2F236E6CL,1L,0x2F236E6CL,0x2F236E6CL,1L};
static uint8_t g_1460 = 0x4FL;
static int16_t g_1524 = (-9L);
static uint8_t g_2177[6][4][10] = {{{0xFBL,247UL,0xB9L,255UL,255UL,0xFBL,251UL,0xB9L,255UL,0xFBL},{4UL,255UL,0xDBL,0xFBL,0xFBL,0xDBL,255UL,4UL,0xFBL,0xB9L},{4UL,0xB4L,0xDBL,0xB9L,0xFBL,4UL,255UL,0xDBL,0xFBL,0xFBL},{4UL,255UL,0xDBL,0xFBL,0xFBL,0xDBL,255UL,4UL,0xFBL,0xB9L}},{{4UL,0xB4L,0xDBL,0xB9L,0xFBL,4UL,255UL,0xDBL,0xFBL,0xFBL},{4UL,255UL,0xDBL,0xFBL,0xFBL,0xDBL,255UL,4UL,0xFBL,0xB9L},{4UL,0xB4L,0xDBL,0xB9L,0xFBL,4UL,255UL,0xDBL,0xFBL,0xFBL},{4UL,255UL,0xDBL,0xFBL,0xFBL,0xDBL,255UL,4UL,0xFBL,0xB9L}},{{4UL,0xB4L,0xDBL,0xB9L,0xFBL,4UL,255UL,0xDBL,0xFBL,0xFBL},{4UL,255UL,0xDBL,0xFBL,0xFBL,0xDBL,255UL,4UL,0xFBL,0xB9L},{4UL,0xB4L,0xDBL,0xB9L,0xFBL,4UL,255UL,0xDBL,0xFBL,0xFBL},{4UL,255UL,0xDBL,0xFBL,0xFBL,0xDBL,255UL,4UL,0xFBL,0xB9L}},{{4UL,0xB4L,0xDBL,0xB9L,0xFBL,4UL,255UL,0xDBL,0xFBL,0xFBL},{4UL,255UL,0xDBL,0xFBL,0xFBL,0xDBL,255UL,4UL,0xFBL,0xB9L},{4UL,0xB4L,0xDBL,0xB9L,0xFBL,4UL,255UL,0xDBL,0xFBL,0xFBL},{4UL,255UL,0xDBL,0xFBL,0xFBL,0xDBL,255UL,4UL,0xFBL,0xB9L}},{{4UL,0xB4L,0xDBL,0xB9L,0xFBL,4UL,255UL,0xDBL,0xFBL,0xFBL},{4UL,255UL,0xDBL,0xFBL,0xFBL,0xDBL,255UL,4UL,0xFBL,0xB9L},{4UL,0xB4L,0xDBL,0xB9L,0xFBL,4UL,255UL,0xDBL,0xFBL,0xFBL},{4UL,255UL,0xDBL,0xFBL,0xFBL,0xDBL,255UL,4UL,0xFBL,0xB9L}},{{247UL,255UL,251UL,0xDBL,4UL,247UL,255UL,251UL,4UL,4UL},{247UL,255UL,251UL,4UL,4UL,251UL,255UL,247UL,4UL,0xDBL},{247UL,255UL,251UL,0xDBL,4UL,247UL,255UL,251UL,4UL,4UL},{247UL,255UL,251UL,4UL,4UL,251UL,255UL,247UL,4UL,0xDBL}}};
static int32_t g_2352[9] = {(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L)};
static int8_t g_2420 = (-2L);
static int32_t g_2476 = 0x7B48C0CFL;
static int32_t g_2576 = 6L;
static uint32_t g_2598 = 0xF45B1DEAL;
static uint8_t g_2710 = 0x47L;
static int32_t g_3152 = (-1L);
static int32_t g_3258 = 5L;
static uint16_t g_3261 = 0x2ECEL;
static int8_t g_3409 = 8L;
static uint8_t g_3421 = 0UL;
static int32_t g_3484 = 1L;
static int8_t g_3781 = 1L;
static int32_t g_3956[5] = {(-1L),(-1L),(-1L),(-1L),(-1L)};
static uint32_t g_3957 = 0UL;



static int32_t func_1(void);
static uint8_t func_6(uint32_t p_7);
static uint16_t func_8(int16_t p_9);
static int32_t func_15(uint32_t p_16, int8_t p_17, uint32_t p_18, uint32_t p_19, uint32_t p_20);
static int32_t func_29(uint8_t p_30, uint8_t p_31, uint16_t p_32, uint32_t p_33, int32_t p_34);
static int8_t func_35(int8_t p_36, int16_t p_37, int32_t p_38, int32_t p_39);
static int32_t func_42(int16_t p_43, int32_t p_44, uint32_t p_45);
static int32_t func_46(int8_t p_47);
static int32_t func_48(uint32_t p_49, int16_t p_50);
static int8_t func_57(int16_t p_58, uint32_t p_59, uint32_t p_60, int32_t p_61);
static int32_t func_1(void)
{
    uint32_t l_5[6][7] = {{0x327439CBL,0xB03629AAL,0UL,0UL,0xB03629AAL,0x327439CBL,2UL},{1UL,0UL,0x91F782A1L,2UL,1UL,1UL,2UL},{0xFE4B2830L,0x1D2250DBL,0xFE4B2830L,7UL,2UL,1UL,0x327439CBL},{0x91F782A1L,0UL,1UL,7UL,1UL,0UL,0x91F782A1L},{0UL,0xB03629AAL,0x327439CBL,2UL,0UL,1UL,0UL},{0UL,0UL,0UL,0UL,0xFE4B2830L,1UL,7UL}};
    int32_t l_2266[5];
    int32_t l_2290 = (-5L);
    uint8_t l_2292 = 0xB3L;
    int32_t l_2294 = (-3L);
    int32_t l_2296 = 1L;
    int32_t l_2408[5][6] = {{0L,0L,0xC284D198L,1L,0L,1L},{0L,0L,0L,1L,0L,0xC284D198L},{0L,0L,1L,1L,0L,0L},{0L,0L,0xC284D198L,1L,0L,1L},{0L,0L,0L,1L,0L,0xC284D198L}};
    int8_t l_2418[6][5] = {{0L,0L,0L,0L,0xCAL},{0xD8L,0xA7L,0L,6L,0xCAL},{0L,0xD8L,(-1L),(-8L),(-1L)},{(-8L),(-8L),0xCAL,6L,0L},{0x38L,1L,0xCAL,0L,0L},{(-9L),0xCAL,(-1L),0xCAL,(-9L)}};
    int8_t l_2465 = 0x95L;
    int8_t l_2526 = 1L;
    int16_t l_2601 = 0L;
    uint8_t l_2674 = 0x97L;
    uint32_t l_2692 = 1UL;
    uint32_t l_2790[6][3] = {{0xCD6BF178L,0xCD6BF178L,0xCD6BF178L},{18446744073709551609UL,18446744073709551609UL,18446744073709551609UL},{0xCD6BF178L,0xCD6BF178L,0xCD6BF178L},{18446744073709551609UL,18446744073709551609UL,18446744073709551609UL},{0xCD6BF178L,0xCD6BF178L,0xCD6BF178L},{18446744073709551609UL,18446744073709551609UL,18446744073709551609UL}};
    uint32_t l_2841 = 18446744073709551607UL;
    uint32_t l_2899 = 2UL;
    int32_t l_3017 = 0x0B37558CL;
    int32_t l_3116 = 0L;
    uint8_t l_3151 = 0x0AL;
    uint16_t l_3171 = 65535UL;
    uint32_t l_3257 = 1UL;
    int32_t l_3262 = (-1L);
    uint32_t l_3399 = 7UL;
    uint8_t l_3408 = 0x12L;
    uint8_t l_3424[2][3][5] = {{{0x72L,0x5BL,0xBDL,2UL,0xBDL},{1UL,1UL,0x5BL,255UL,0xEBL},{0x72L,0xEBL,0x76L,255UL,255UL}},{{255UL,0x16L,255UL,0x72L,0xEBL},{255UL,0xBDL,0x16L,0x5BL,0xEBL},{1UL,2UL,2UL,1UL,255UL}}};
    int32_t l_3471 = 0x35FC95CDL;
    int32_t l_3492 = 0x5429EDD7L;
    uint16_t l_3534 = 3UL;
    uint32_t l_3573[10] = {6UL,6UL,6UL,6UL,6UL,6UL,6UL,6UL,6UL,6UL};
    uint8_t l_3655 = 1UL;
    int8_t l_3667 = (-1L);
    int8_t l_3683 = (-1L);
    uint16_t l_3702 = 0x4BDBL;
    int32_t l_3707 = 1L;
    int32_t l_3721 = 0x7BC1F5CCL;
    int8_t l_3741 = 0x63L;
    uint8_t l_3752 = 255UL;
    int32_t l_3755[2][2][7] = {{{0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L},{0L,0L,0L,0L,0L,0L,0L}},{{0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L},{0L,0L,0L,0L,0L,0L,0L}}};
    uint16_t l_3775 = 0x252EL;
    int32_t l_3872 = 0L;
    int32_t l_3873 = 0xE2017063L;
    int32_t l_3874[9] = {0L,0L,0L,0L,0L,0L,0L,0L,0L};
    int32_t l_3891 = 0x323AE330L;
    int32_t l_3908 = (-7L);
    int8_t l_4035 = 1L;
    int i, j, k;
    for (i = 0; i < 5; i++)
        l_2266[i] = 0x3DF77380L;
    if ((((safe_lshift_func_uint16_t_u_s(g_4, 8)) | l_5[1][6]) != func_6((l_2266[3] = ((g_813[3][0] = func_8(l_5[1][6])) || (!(l_5[1][6] <= 1UL)))))))
    {
        uint32_t l_2279 = 0x93AE2901L;
        int32_t l_2291[2];
        int32_t l_2293[10][5][5] = {{{0x45777B37L,4L,(-5L),(-10L),(-5L)},{0xA9C5A221L,0xA9C5A221L,0x9C7A75D8L,0xD4EDE40DL,0x8ED2113AL},{0xFE015731L,2L,6L,0xA4130E32L,(-3L)},{0x4F8FF695L,9L,0xD4EDE40DL,0x6B855A03L,(-2L)},{0L,2L,0x45777B37L,0xEF9A929BL,1L}},{{(-1L),0xA9C5A221L,0x3F2DF9F6L,0x9C7A75D8L,0x4F8FF695L},{0x05E1541BL,4L,0xFE015731L,1L,(-4L)},{0x2F4D056CL,0x2206AE63L,0xD4EDE40DL,0xE58FA5B4L,0x2F4D056CL},{0x4E1AA23AL,0xEF9A929BL,0L,1L,(-7L)},{(-1L),(-8L),0x9C7A75D8L,0x9C7A75D8L,(-8L)}},{{(-3L),(-4L),0x05E1541BL,0xEF9A929BL,0xD31BC39FL},{0xE58FA5B4L,0x9C7A75D8L,0xEBCBB2E6L,0x6B855A03L,0x2F4D056CL},{(-7L),1L,0x4E1AA23AL,0xA4130E32L,0x141ABB78L},{0xE58FA5B4L,0x8ED2113AL,0xF2DC1619L,0xD4EDE40DL,0x4F8FF695L},{(-3L),(-9L),(-3L),(-10L),(-5L)}},{{(-1L),(-7L),0x2206AE63L,(-8L),(-2L)},{0x4E1AA23AL,1L,(-7L),4L,(-7L)},{0x2F4D056CL,(-1L),0x2206AE63L,(-1L),0x8ED2113AL},{0x05E1541BL,(-4L),(-3L),(-4L),0x05E1541BL},{(-1L),(-9L),0xF2DC1619L,(-2L),0xA9C5A221L}},{{0L,0xEF9A929BL,0x4E1AA23AL,4L,5L},{0x4F8FF695L,0xE58FA5B4L,0xEBCBB2E6L,(-9L),0xA9C5A221L},{0xFE015731L,4L,0x05E1541BL,(-10L),0x05E1541BL},{0xA9C5A221L,0x3F2DF9F6L,0x9C7A75D8L,0x4F8FF695L,0x8ED2113AL},{0x45777B37L,2L,0L,0xA4130E32L,(-7L)}},{{0x4F8FF695L,(-1L),0xD4EDE40DL,0xC4371B6FL,(-2L)},{6L,6L,0x80113FBEL,4L,(-4L)},{0xA9C5A221L,0xC4371B6FL,0xC4371B6FL,0xA9C5A221L,(-8L)},{0L,1L,4L,2L,(-5L)},{(-1L),(-1L),(-9L),9L,(-1L)}},{{0xD31BC39FL,4L,(-3L),2L,1L},{0x4F8FF695L,0x9C7A75D8L,0x3F2DF9F6L,0xA9C5A221L,(-1L)},{5L,(-9L),0L,4L,0x9616CC94L},{(-1L),0xA9C5A221L,0xF2DC1619L,0x2206AE63L,(-1L)},{1L,(-10L),0xD31BC39FL,0xEF9A929BL,0x05E1541BL}},{{(-1L),0xEBCBB2E6L,0xD4EDE40DL,(-8L),(-8L)},{5L,1L,5L,(-4L),0x141ABB78L},{0x4F8FF695L,0x2F4D056CL,9L,0x9C7A75D8L,0x8ED2113AL},{0xD31BC39FL,(-10L),1L,1L,(-1L)},{(-1L),0x3F2DF9F6L,9L,0x8ED2113AL,0x2F4D056CL}},{{0L,(-9L),5L,(-9L),0L},{0xA9C5A221L,(-1L),0xD4EDE40DL,(-7L),0x6B855A03L},{(-3L),4L,0xD31BC39FL,1L,0xC0723F86L},{(-8L),9L,0xF2DC1619L,(-1L),0x6B855A03L},{4L,1L,0L,(-4L),0L}},{{0x6B855A03L,0x6B855A03L,0x3F2DF9F6L,(-9L),0x2F4D056CL},{0x80113FBEL,6L,(-3L),0xEF9A929BL,(-1L)},{(-8L),(-1L),(-9L),0xE58FA5B4L,0x8ED2113AL},{(-7L),6L,4L,4L,0x141ABB78L},{0xA9C5A221L,0x6B855A03L,0xC4371B6FL,0x3F2DF9F6L,(-8L)}}};
        int32_t l_2295 = 0xA7522FCFL;
        uint16_t l_2386[5] = {0xA842L,0xA842L,0xA842L,0xA842L,0xA842L};
        uint8_t l_2387 = 0xC5L;
        uint8_t l_2566[3][1];
        int16_t l_2600 = 0x9347L;
        uint16_t l_2619[2];
        int i, j, k;
        for (i = 0; i < 2; i++)
            l_2291[i] = 0x4E538020L;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 1; j++)
                l_2566[i][j] = 1UL;
        }
        for (i = 0; i < 2; i++)
            l_2619[i] = 65535UL;
        l_2296 = (l_2266[2] = (l_2295 = (((safe_sub_func_uint32_t_u_u((!(safe_sub_func_int16_t_s_s((g_543[1] = (safe_add_func_int32_t_s_s((safe_rshift_func_uint8_t_u_u(0x89L, 6)), ((safe_mod_func_int16_t_s_s((g_172[8] >= 0x22C8L), (g_63 = l_5[5][1]))) || (l_2279 | (((safe_mod_func_uint32_t_u_u((~(l_2293[5][4][4] = (safe_sub_func_int32_t_s_s(((g_63 = (safe_lshift_func_uint16_t_u_s(((~l_2266[4]) < (((l_2291[0] = (0x405BL < (((l_2290 = (safe_add_func_uint16_t_u_u((g_315 = (l_5[1][6] == 0x41L)), g_540))) | l_2266[3]) >= g_2177[1][3][4]))) ^ 0x136C721FL) | g_540)), 2))) > l_2292), g_1129)))), l_2266[1])) ^ 0xBD41L) | 0xAFB6L)))))), l_2294))), l_5[4][0])) >= 1L) <= l_2279)));
        for (g_4 = 2; (g_4 >= 0); g_4 -= 1)
        {
            uint32_t l_2314 = 0xBB7DC9F1L;
            int32_t l_2326 = 0x3AB3E32BL;
            int8_t l_2328[1];
            int i;
            for (i = 0; i < 1; i++)
                { int16_t Bmgmgg_1524 = (~(((~(((~((~((g_3409 + l_2841))))) ^ (~((~((g_540 | ((g_361 & g_1524) ^ l_3017))))))))) - (~((((l_3151 + l_2692) | g_3781) ^ (~(l_3752))))))));
uint8_t Bmgmgbl_3752 = (~(((~((~(((~(g_3409)) & g_540))))) | ((~((~(((~((~(g_3781)))) & (((l_3752 ^ l_3017) | (~(((~((l_3151 % l_2841))) % g_1524)))) % (~(Bmgmgg_1524)))))))) << (l_2692 + g_361)))));
uint32_t Bmgmgcl_2841 = (~((((~((~(((~((~(((~(l_3017)) & Bmgmgg_1524))))) % (Bmgmgbl_3752 | (~(g_1524)))))))) % (~((g_540 - l_2692)))) & (~((~(((~((g_3409 - l_3151))) << (((l_3752 << g_361) % l_2841) % g_3781)))))))));
int32_t Bmgmgdl_3017 = (~(((~(((~(((~(Bmgmgbl_3752)) & l_3151))) ^ (g_1524 ^ (((~(Bmgmgcl_2841)) % g_3409) ^ ((((g_3781 & g_540) % l_3017) - Bmgmgg_1524) + (~(l_2841)))))))) % (~(((~(l_2692)) ^ ((~((~(l_3752)))) >> g_361)))))));
uint32_t Bmgmgel_2692 = (~((Bmgmgg_1524 | (((((~(l_3752)) & (((l_2692 | Bmgmgcl_2841) - (l_2841 ^ (~(g_1524)))) + l_3017)) ^ (~(l_3151))) | ((~(g_361)) - (Bmgmgdl_3017 & (Bmgmgbl_3752 & (~(g_3409)))))) - (~((~((g_540 + g_3781)))))))));
uint8_t Bmgmgfl_3151 = (~(((~((~((~(((~((~(Bmgmgel_2692)))) & ((~((g_3409 & l_3752))) | l_3017)))))))) % ((~((Bmgmgbl_3752 & (~((~(g_361))))))) + ((~(((~((Bmgmgcl_2841 << l_2692))) ^ ((~((Bmgmgg_1524 ^ Bmgmgdl_3017))) - l_2841)))) % ((~(g_1524)) - ((~((l_3151 - g_540))) % (~(g_3781)))))))));
                                   if (l_2294)
                    if((g_3781 > g_1524)){
Bmgmgg_1524 = g_1524;
Bmgmgbl_3752 = l_3752;
                                   if (l_2600)
                    Bmgmgcl_2841 = l_2841;
Bmgmgdl_3017 = l_3017;
                                    if ((l_3534 && (!l_3151)) )
{

{
                        return g_361;
                    }

}
                    Bmgmgel_2692 = l_2692;
Bmgmgfl_3151 = l_3151;
g_1524 = (~((((l_2841 - (~((((~(g_540)) ^ (~(Bmgmgdl_3017))) - (((~(l_3752)) - g_3781) ^ (l_2692 ^ g_1524)))))) & ((~((g_3409 & Bmgmgcl_2841))) | (~(((~(Bmgmgfl_3151)) ^ Bmgmgbl_3752))))) | ((~(((Bmgmgel_2692 & (~(l_3151))) ^ Bmgmgg_1524))) + (l_3017 + (~(g_361)))))));
l_3752 = (~(((~(((~((~(l_3151)))) + (~((((~(Bmgmgcl_2841)) >> g_3781) | ((Bmgmgg_1524 ^ (g_361 % (Bmgmgdl_3017 + l_2692))) + Bmgmgfl_3151))))))) % ((~(((~(g_3409)) - (~((l_3017 | Bmgmgel_2692)))))) ^ ((~(((~(((~((~((~(l_2841)))))) ^ (~(Bmgmgbl_3752))))) ^ (~(g_540))))) + (~((~((~((l_3752 % g_1524))))))))))));
l_2841 = (~((Bmgmgel_2692 % ((~((~((Bmgmgbl_3752 | (~((~((~(g_1524))))))))))) ^ ((g_3781 ^ (~((g_361 << (g_540 & l_3151))))) | (~(((~((((~((~(g_3409)))) + (~(Bmgmgdl_3017))) ^ Bmgmgfl_3151))) & (~((Bmgmgcl_2841 - (((l_2841 << l_2692) & Bmgmgg_1524) + (l_3017 | l_3752)))))))))))));
l_3017 = (~((((~(((~((l_3151 | Bmgmgcl_2841))) | g_540))) | ((~(g_3409)) + (Bmgmgg_1524 ^ Bmgmgel_2692))) % (~((~(((~((~(Bmgmgdl_3017)))) | (~((~(((~((l_3017 ^ (g_3781 << g_361)))) % (((~(Bmgmgbl_3752)) % (~((l_2841 - (Bmgmgfl_3151 ^ l_3752))))) | (g_1524 - l_2692)))))))))))))));
                                    if ((g_540<66205860U) )
{

{
                        uint32_t l_720 = 0UL;
                        int32_t l_721 = 7L;
                        l_3874[0] = (safe_sub_func_int16_t_s_s(((g_2598 = (safe_add_func_uint8_t_u_u(0x83L, (((safe_add_func_int8_t_s_s(g_172[4], (Bmgmgdl_3017 = g_188))) ^ (~(j = (safe_rshift_func_int16_t_s_u((((safe_rshift_func_int8_t_s_s((l_721 = (4UL || ((-1L) == (((safe_lshift_func_uint8_t_u_s((safe_sub_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u(65535UL, 2)), (safe_rshift_func_int16_t_s_s((g_115 && ((l_3262 = ((safe_mod_func_uint8_t_u_u(((l_2314 < Bmgmgel_2692) && g_172[4]), 0x9AL)) <= g_2598)) != Bmgmgel_2692)), l_720)))), g_103)) && 0x78L) ^ g_103)))), 6)) || g_188) ^ 0xF1F3L), 3))))) || 6UL)))) & 0UL), 5UL));
                    }

}
                    l_2692 = (~((((~((((Bmgmgfl_3151 | l_2692) | ((g_3781 + g_540) ^ l_3151)) | Bmgmgbl_3752))) + Bmgmgel_2692) ^ ((l_3017 - ((Bmgmgcl_2841 % g_1524) & (l_2841 % (Bmgmgg_1524 + l_3752)))) | (g_3409 ^ (~((Bmgmgdl_3017 | g_361))))))));
l_3151 = (~(((~((((~(g_540)) + (~(Bmgmgfl_3151))) + (~(((((l_2692 | (~((~(l_3752))))) + g_1524) % (~(((l_3017 & ((l_2841 << Bmgmgel_2692) - g_361)) & l_3151)))) ^ (g_3409 % (~(((~(Bmgmgbl_3752)) ^ (~(Bmgmgdl_3017)))))))))))) ^ (~(((~(Bmgmgcl_2841)) % (g_3781 + (~(Bmgmgg_1524)))))))));
                                   if (l_3721)
                    if((!l_2841)){
printf("g_1524=%lld\n", (long long)g_1524);
continue;
}
                                    if ((l_2465<-107) )
{

for (g_22 = (-29); (g_22 < 29); g_22++)
                {
                    int32_t l_3319 = 4L;
                    for (l_2292 = 1; (l_2292 <= 7); l_2292 += 1)
                    {
                        int i, j;
                        return g_866[l_2292][(l_2292 + 1)];
                    }
                    for (g_3484 = (-5); (g_3484 > 23); g_3484++)
                    {
                        l_3319 = 0x34207361L;
                    }
                };


}
                    if(((Bmgmgdl_3017 < l_3151) || (g_361 > l_3752))){
printf("l_3752=%llu\n", (unsigned long long)l_3752);
Bmgmgbl_3752 = (~((((~(((~(((~(Bmgmgbl_3752)) + (~(Bmgmgfl_3151))))) ^ Bmgmgel_2692))) & (~((((~(l_3017)) << ((g_3409 >> l_2692) >> l_3151)) ^ (((Bmgmgdl_3017 >> g_3781) ^ (g_361 ^ l_2841)) | (l_3752 + (~((~(g_1524)))))))))) ^ (~(((~((g_540 ^ Bmgmgcl_2841))) & (~(Bmgmgg_1524))))))));
Bmgmgcl_2841 = (~(((((~((((~(Bmgmgbl_3752)) ^ (g_1524 - l_3752)) % ((~(Bmgmgdl_3017)) ^ (~(l_3151)))))) & (~(((Bmgmgfl_3151 % (~(Bmgmgel_2692))) >> ((~(((~(g_3781)) % l_2692))) % (~(((~((g_540 - Bmgmgcl_2841))) << (~((~(l_3017)))))))))))) ^ (~((~(g_361))))) | (~(((~(l_2841)) & (g_3409 ^ Bmgmgg_1524)))))));
Bmgmgel_2692 = (~(((~(Bmgmgbl_3752)) << (((~((((~((Bmgmgfl_3151 >> (~((Bmgmgel_2692 & (g_3409 << l_2692))))))) - g_3781) << (((~(Bmgmgg_1524)) % (~(((l_3752 | (~(g_361))) + (l_3151 & Bmgmgcl_2841))))) % (~(g_1524)))))) % (~(g_540))) << (l_2841 - (l_3017 | Bmgmgdl_3017))))));
}
if((Bmgmgel_2692 && (g_3409>8))){
printf("l_2841=%llu\n", (unsigned long long)l_2841);
break;
}
if(((Bmgmgdl_3017 < Bmgmgbl_3752) || ((g_3781<1) && (Bmgmgcl_2841 < Bmgmgbl_3752)))){
printf("l_3017=%lld\n", (long long)l_3017);
l_2841 = (~(((((~((~((~(Bmgmgel_2692)))))) % (l_2841 ^ ((~(g_3781)) + ((~((Bmgmgg_1524 << (l_3752 ^ (Bmgmgdl_3017 + g_1524))))) - (((l_2692 - g_540) & Bmgmgfl_3151) - (~(Bmgmgbl_3752))))))) + (((~(l_3151)) | (~((~(Bmgmgcl_2841))))) + l_3017)) + (~(((~(g_361)) >> (~((~((~((~(g_3409))))))))))))));
break;
}
if(!((Bmgmgg_1524<=-9))){
printf("l_2692=%llu\n", (unsigned long long)l_2692);
Bmgmgcl_2841 = (~(((((~(((Bmgmgcl_2841 + Bmgmgbl_3752) % (~(Bmgmgfl_3151))))) | (~(((~(Bmgmgg_1524)) >> (~((g_361 ^ ((~((l_3151 & l_2841))) & (l_3017 ^ g_3781))))))))) | (((g_540 % g_3409) >> (~(((l_2692 | l_3752) ^ (~((~(Bmgmgel_2692)))))))) - (~((~(Bmgmgdl_3017)))))) + (~(g_1524)))));
}
if((Bmgmgel_2692 < g_361)){
printf("l_3151=%llu\n", (unsigned long long)l_3151);
l_3151 = (~(((~((~(((~((~((((~((l_3017 << g_540))) - Bmgmgel_2692) + (((((~(l_3752)) - (~(g_3781))) % (g_1524 & l_2841)) % (~((Bmgmgfl_3151 | Bmgmgbl_3752)))) << (((l_2692 | l_3151) << Bmgmgdl_3017) + g_361))))))) | (~((~(Bmgmgg_1524))))))))) << (~((g_3409 + Bmgmgcl_2841))))));
break;
}
}
g_1524 = Bmgmgg_1524;
l_3752 = Bmgmgbl_3752;
l_2841 = Bmgmgcl_2841;
l_3017 = Bmgmgdl_3017;
l_2692 = Bmgmgel_2692;
l_3151 = Bmgmgfl_3151;

                    l_2328[i] = 0L;}
            for (g_974 = 0; (g_974 <= 2); g_974 += 1)
            {
                int16_t l_2315 = 0xC65AL;
                uint16_t l_2327 = 65533UL;
                uint8_t l_2343[5] = {3UL,3UL,3UL,3UL,3UL};
                int i;
                for (l_2295 = 0; (l_2295 <= 2); l_2295 += 1)
                {
                    int i, j, k;
                    g_247 = (((safe_lshift_func_uint16_t_u_s((g_315 = (~(g_217 = (safe_add_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u(((safe_add_func_uint32_t_u_u(((((safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((safe_add_func_uint16_t_u_u(((((((safe_sub_func_int16_t_s_s((g_949[l_2295][(l_2295 + 3)][(g_4 + 5)] & g_949[l_2295][(g_4 + 4)][(g_4 + 2)]), l_2314)) == ((((g_172[4] = (g_949[l_2295][(l_2295 + 3)][(g_4 + 5)] ^ (l_2315 == (safe_lshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(0L, 9)), 13))))) | ((safe_sub_func_uint32_t_u_u(((((safe_rshift_func_uint16_t_u_s(g_949[l_2295][(g_4 + 4)][(g_4 + 2)], ((safe_rshift_func_uint16_t_u_s((0x65F9L > 0x8304L), 8)) & 6L))) & 0UL) && 0L) != l_5[1][6]), g_115)) <= 0UL)) & (-2L)) != g_949[l_2295][(g_4 + 4)][(g_4 + 2)])) & g_103) & l_2291[0]) ^ 1UL) > 0x97A6L), g_315)), l_2326)), g_949[l_2295][(g_4 + 4)][(g_4 + 2)])) == l_2327) || g_2177[2][1][9]) && g_63), (-4L))) >= 0x5E9A852FL), l_2328[0])) == g_4), l_2314))))), g_1215[4])) >= 4294967286UL) && 0x397E8B8CL);
                    for (g_1129 = 20; (g_1129 != 28); g_1129++)
                    {
                        int16_t l_2333 = 0x031BL;
                        l_2291[1] = 1L;
                        if (l_2291[0])
                            break;
                        g_247 = (safe_mod_func_uint32_t_u_u((5L || (l_2326 = (((l_2333 < ((((g_1460 = ((((-6L) == ((g_83 = (safe_add_func_int32_t_s_s((0L <= (g_83 && (safe_unary_minus_func_int8_t_s((((((((safe_add_func_uint16_t_u_u((1UL >= (safe_add_func_int8_t_s_s(0x1DL, (safe_add_func_uint32_t_u_u(((g_949[l_2295][(g_4 + 4)][(g_4 + 2)] > 0xC1A8C29BL) >= l_2295), l_2328[0]))))), 8UL)) == g_247) < g_540) == g_12) & l_2343[4]) && l_2315) <= l_2292))))), g_866[7][5]))) & 1UL)) | l_2327) & g_315)) & g_315) != l_2333) || l_2333)) & l_2294) && g_949[0][6][3]))), 6L));
                    }
                    g_247 = g_974;
                }
                if (g_813[1][0])
                    continue;
                g_247 = (safe_rshift_func_int16_t_s_u(((l_2315 & (safe_lshift_func_uint16_t_u_u((((l_2326 = (g_188 ^ (g_83 = (safe_add_func_uint8_t_u_u((((((0xE5L >= (((((g_161 = (safe_mod_func_int8_t_s_s((g_361 = (g_2352[2] || 4UL)), g_866[4][0]))) && 0xB2182F1EL) && (l_5[1][6] ^ (safe_lshift_func_uint8_t_u_s(((safe_add_func_uint16_t_u_u(((+g_173) != l_2292), g_543[1])) && (-1L)), 7)))) < 0xB49FL) > 0x7963L)) >= l_2314) >= 2L) >= l_2291[1]) && (-1L)), g_12))))) | l_2327) < g_813[5][0]), g_173))) < l_2314), 12));
            }
            return g_1460;
        }
        if (((((safe_lshift_func_int16_t_s_u(((((safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s((g_541 & (((safe_sub_func_uint8_t_u_u(((g_540 < (((safe_add_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(0xB2C7L, (((safe_sub_func_uint8_t_u_u(((safe_unary_minus_func_uint16_t_u((l_2293[8][3][1] = 0x0192L))) || (g_247 = (((-1L) < g_543[1]) || (l_2266[3] = (safe_add_func_int16_t_s_s((safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(l_2293[5][1][3], (+(((g_63 = (safe_rshift_func_uint16_t_u_s(((g_2177[1][3][2] >= (safe_mod_func_int8_t_s_s(g_2352[4], g_173))) != 5L), 0))) < l_2296) != g_1215[2])))), 8L)), g_2177[3][1][9])))))), l_5[1][6])) || l_2295) == l_2291[0]))), l_2291[0])), g_359[9][0])) & l_2386[4]) < 1UL)) | l_2295), 0x6BL)) != 0UL) >= l_5[1][6])), g_949[0][6][1])), 0x5BL)) || g_866[4][0]) < g_866[6][2]) || l_2266[3]), l_2387)) > 0xCA700566L) >= g_813[1][0]) || g_63))
        {
            uint8_t l_2432 = 0x5EL;
            int8_t l_2575 = 0L;
            int32_t l_2584 = 0x0CC4751DL;
            int32_t l_2585[3];
            int8_t l_2620 = 0x0FL;
            int i;
            for (i = 0; i < 3; i++)
                l_2585[i] = 0xAFFA580CL;
            for (l_2279 = 0; (l_2279 == 40); ++l_2279)
            {
                uint16_t l_2390 = 0x77A9L;
                uint32_t l_2419 = 1UL;
                int32_t l_2421 = 0x4F3857AAL;
                uint32_t l_2422 = 0x8A7A8A37L;
                int32_t l_2431 = (-10L);
                int8_t l_2475 = 0x84L;
                l_2390 = (g_247 = g_540);

if (l_3151)
                            break;


l_2465 -= 1;


                    l_2422 = (((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u(((0x64L > ((~(safe_sub_func_uint32_t_u_u((safe_add_func_int32_t_s_s(g_12, ((safe_sub_func_int16_t_s_s((l_2296 = (safe_lshift_func_uint8_t_u_s((g_540 < 0xD1A6L), 3))), (g_543[1] = l_2293[5][4][4]))) == (l_2421 = (((((((safe_lshift_func_uint8_t_u_u(l_2408[3][0], (safe_rshift_func_uint16_t_u_u((0x71C3L & (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_uint16_t_u((l_2419 = (safe_lshift_func_int8_t_s_s(((g_173 = (safe_rshift_func_int8_t_s_s((g_1215[0] && l_2418[5][4]), 5))) == l_2390), 2))))), g_2420))), 2)))) <= 0L) || l_2279) | l_2292) && 4L) != g_949[0][6][1]) ^ l_2390))))), (-3L)))) == 0x9FC9L)) && 0x36A7L), l_2386[4])), 8)) != g_361) <= 0x9B065C80L);
                l_2293[5][4][4] = (((((((safe_lshift_func_int8_t_s_u((((((((((g_1460 == l_2293[5][4][4]) ^ (((g_63 = 0xDFFFL) | (g_538 = 0x34B8L)) && (safe_lshift_func_int16_t_s_s((((safe_sub_func_int32_t_s_s((g_247 = ((l_2421 = 0UL) | ((((l_2291[0] > (safe_sub_func_uint8_t_u_u(l_2431, (l_2295 = l_2432)))) < 0x06L) != g_949[0][6][1]) && l_2431))), 0x134D74CCL)) <= (-10L)) < g_63), 7)))) > 0x9248DD31L) == g_974) == 0UL) < g_1460) == l_2408[3][0]) <= 0x7CL) | l_2431), l_5[1][6])) && 0x07L) | g_866[4][0]) & 0xE8L) <= g_866[7][7]) < g_813[1][0]) != l_2432);
                for (l_2432 = 0; (l_2432 <= 3); l_2432 += 1)
                {
                    uint32_t l_2437 = 8UL;
                    int32_t l_2466 = 0x1A5DEB5BL;
                    uint32_t l_2474[3][4][7] = {{{18446744073709551611UL,18446744073709551609UL,0xDE198DD4L,0UL,0UL,0UL,0xDE198DD4L},{0x582432FAL,0x582432FAL,18446744073709551615UL,0x20D3A748L,1UL,0x5B92F6A6L,1UL},{0x3B7A71C4L,0xBB8986F1L,0xFCA41817L,0xC54627FCL,0xC54627FCL,0xFCA41817L,0xBB8986F1L},{1UL,18446744073709551615UL,0x582432FAL,1UL,1UL,0x688D7EE0L,0x20D3A748L}},{{0xFCA41817L,18446744073709551611UL,0UL,0xBB8986F1L,0UL,18446744073709551611UL,0xFCA41817L},{0x20D3A748L,0x688D7EE0L,1UL,1UL,0x582432FAL,18446744073709551615UL,1UL},{0xBB8986F1L,0xFCA41817L,0xC54627FCL,0xC54627FCL,0xFCA41817L,0xBB8986F1L,0x3B7A71C4L},{1UL,0x5B92F6A6L,1UL,0x20D3A748L,18446744073709551615UL,0x582432FAL,0x582432FAL}},{{0xDE198DD4L,0UL,0UL,0UL,0xDE198DD4L,18446744073709551615UL,0x3B7A71C4L},{1UL,1UL,18446744073709551615UL,18446744073709551615UL,0x5B92F6A6L,0x20D3A748L,0x5B92F6A6L},{0xBB8986F1L,1UL,1UL,0xBB8986F1L,18446744073709551611UL,18446744073709551609UL,0xDE198DD4L},{1UL,18446744073709551615UL,1UL,0x582432FAL,18446744073709551608UL,18446744073709551608UL,0x582432FAL}}};
                    int i, j, k;
                    g_22 = (safe_mod_func_int8_t_s_s(((((g_866[(l_2432 + 4)][(l_2432 + 1)] && g_2352[(l_2432 + 5)]) > (g_4 < 0L)) && ((safe_sub_func_int32_t_s_s((0xE897L >= l_2437), (0UL ^ 0x39L))) <= (safe_add_func_uint16_t_u_u((g_540 < g_540), 0x403CL)))) & 0x0DF0L), l_2386[4]));

for (g_188 = 17; (g_188 <= (-24)); g_188 = safe_sub_func_uint32_t_u_u(g_188, 6))
            {
                if (g_813[1][0])
                    break;
                return g_974;
            };


                    g_22 = ((g_813[5][0] = ((safe_lshift_func_uint16_t_u_s(g_1129, 5)) && 0x9FL)) <= (((safe_add_func_int32_t_s_s((safe_sub_func_uint8_t_u_u(g_172[5], (safe_rshift_func_uint16_t_u_u((((g_173 = (g_161 && (safe_rshift_func_int8_t_s_s((((safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(((safe_sub_func_int32_t_s_s(g_1460, ((((safe_sub_func_uint32_t_u_u((~g_538), (g_247 = (l_2432 < g_2352[(l_2432 + 5)])))) && g_161) || g_22) || g_866[(l_2432 + 4)][(l_2432 + 1)]))) == l_2465), g_543[1])), l_2432)), 3)), 5)) != g_949[0][6][4]), l_2292)) > l_2421) < g_217), g_115)))) > l_2296) >= 0xC1L), 9)))), l_2293[5][4][4])) > l_2437) || 0x1B16L));
                    if (g_359[9][0])
                        break;
                    for (g_63 = 0; (g_63 <= 3); g_63 += 1)
                    {
                        int32_t l_2473 = (-1L);
                        int i, j, k;
                        l_2466 = 0x839C60E3L;

{
                if (l_2390)
                    break;
            }

                    g_2476 = (((g_2177[(g_63 + 2)][l_2432][(g_63 + 5)] && (((safe_rshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u(g_2177[(l_2432 + 1)][g_63][(l_2432 + 5)], 14)), (safe_mod_func_uint16_t_u_u(g_4, g_103)))) <= ((l_2473 = (g_247 = l_2390)) != (g_22 = (0x43DA57DBL | g_541)))) < (g_217 < l_2474[0][1][4]))) || g_543[2]) || l_2475);
                    }
                }
            }
            for (g_115 = (-19); (g_115 < (-22)); g_115 = safe_sub_func_uint16_t_u_u(g_115, 7))
            {
                uint8_t l_2479 = 1UL;
                int8_t l_2495 = 0xB0L;
                int32_t l_2513 = 0xA6921076L;
                int32_t l_2547 = 0x6B1B6203L;
                uint8_t l_2563[7] = {0xB3L,0xB3L,0x5EL,0xB3L,0xB3L,0x5EL,0xB3L};
                int i;
                if (l_2479)
                {
                    int16_t l_2490 = 0L;
                    int32_t l_2504 = (-8L);
                    for (g_315 = (-1); (g_315 == 46); g_315 = safe_add_func_int32_t_s_s(g_315, 5))
                    {
                        int16_t l_2482 = 0xC29FL;
                        l_2295 = (l_2482 >= (safe_add_func_uint16_t_u_u((g_247 == g_173), 0x0D89L)));
                        l_2293[5][4][4] = g_974;
                    }
                    l_2295 = ((l_2296 = ((((g_83 = ((+g_12) & ((safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u(g_173, (((g_63 = l_5[0][0]) | ((g_4 <= 0x4CL) || ((l_2490 || (safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(l_2495, g_83)), 3))) >= g_359[6][6]))) ^ 2UL))), l_2495)) ^ 0L))) < 0x23L) & l_2495) && 0x9BA8983EL)) >= 65527UL);
                    l_2408[3][0] = (((g_161 = (g_173 >= g_949[0][5][6])) == ((safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s((g_2177[4][1][4] = ((g_172[7] == ((l_2266[0] = (safe_add_func_int32_t_s_s(((l_2504 = l_2495) >= ((safe_mod_func_uint8_t_u_u((l_2490 | ((l_2296 = ((0L || (l_2513 = ((l_2490 ^ (safe_add_func_int32_t_s_s((safe_add_func_int8_t_s_s(1L, g_315)), l_2490))) | l_2432))) >= g_4)) < 65535UL)), g_2476)) && 252UL)), g_315))) <= g_538)) | (-10L))), 6)), l_2479)) && (-1L))) ^ (-8L));
                    l_2291[0] = g_4;
                }
                else
                {
                    uint32_t l_2525 = 0xDBD6AC3EL;
                    int32_t l_2528 = 0xF6619A70L;
                    for (g_541 = 0; (g_541 <= 5); g_541 += 1)
                    {
                        int32_t l_2527 = 0L;
                        int i, j;
                        g_247 = ((safe_rshift_func_uint8_t_u_u((l_2528 = ((l_5[g_541][g_541] = (safe_unary_minus_func_uint16_t_u(0x2292L))) ^ (l_2293[5][4][4] = (((-7L) < ((safe_lshift_func_uint8_t_u_u((0xE68EF4FBL < ((safe_add_func_int8_t_s_s((l_2291[0] = ((safe_add_func_uint32_t_u_u((g_2420 != (safe_add_func_int16_t_s_s((((65531UL > ((l_2525 || g_361) & g_949[1][7][7])) || (((l_2526 = ((l_2525 > g_172[4]) & 0x1B0088F1L)) ^ l_2479) & l_2479)) && 0x82L), 0x2333L))), g_1129)) || g_217)), g_173)) ^ 4294967295UL)), 1)) == 5L)) == l_2527)))), 0)) >= 255UL);

l_3408 += 1;


                    g_247 = (safe_lshift_func_uint16_t_u_u(1UL, (safe_lshift_func_uint16_t_u_s(((((((safe_rshift_func_uint8_t_u_s(((((g_83 = l_2432) <= (0UL ^ (safe_mod_func_int8_t_s_s(((safe_sub_func_int32_t_s_s(l_2295, g_543[2])) ^ ((l_2418[0][3] <= l_2292) != (safe_sub_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(((g_2177[3][1][9] = l_2386[4]) <= (safe_mod_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(g_543[1], g_361)), l_2513))), l_2528)), l_2432)))), l_2387)))) <= 0x476CB2BEL) <= l_5[g_541][(g_541 + 1)]), 5)) == l_2547) ^ 0x6F1AL) & g_103) | 0x2AL) | g_172[2]), g_2476))));
                        g_247 = (g_22 = ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u(((0xFFL <= 0x8EL) && (g_813[0][0] <= (-1L))), 0)), 0x2FL)) | (0x30L & (((safe_add_func_int16_t_s_s((0x0450E2D6L <= l_2432), (g_1129 < g_949[0][6][1]))) || 0x6291L) > 0x03C1L))));
                        l_2527 = (l_2290 = 0x5A0AF0AFL);
                    }
                    g_2476 = 1L;
                    if ((safe_lshift_func_int8_t_s_s((+((safe_rshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s((l_2266[3] < l_2563[0]), (safe_mod_func_uint16_t_u_u(l_2566[2][0], ((safe_mod_func_uint32_t_u_u(0xB86569AAL, (safe_sub_func_int8_t_s_s((l_2525 & (safe_sub_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(l_2575, g_2576)), ((g_22 = l_5[1][6]) && ((((l_2547 = (safe_rshift_func_uint8_t_u_s((((g_63 = g_1129) == l_2547) || (-1L)), 5))) && 0x8CF5425BL) > g_361) ^ g_540))))), 0x41L)))) & 0xFF38L))))) != l_2563[0]), 1UL)), l_2575)) && 9UL)), 1)))
                    {
                        l_2585[1] = (+(0x39E1L | (safe_lshift_func_int16_t_s_s((g_866[7][8] = ((65535UL & 0x0AC2L) <= 0xB3EAL)), ((g_974 = g_974) >= (l_2295 = (g_543[2] = (((l_2575 < (((safe_sub_func_uint16_t_u_u(l_2525, (g_2177[3][1][9] != (l_2584 = (l_2292 && g_12))))) & 0xD04E619AL) <= g_538)) == g_543[1]) >= l_2575))))))));
                        g_22 = g_1129;
                    }
                    else
                    {
                        uint32_t l_2599 = 0x7CDA3D77L;
                        int32_t l_2616 = (-4L);
                        g_2576 = ((1L == l_2525) != (safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(((-3L) != ((safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((((((((l_2386[4] >= (g_813[1][0] < (g_2476 = (((0xFFL | g_949[0][6][1]) == (((safe_add_func_uint32_t_u_u((l_2563[0] || l_2292), g_2598)) >= l_2585[2]) || l_2525)) < 0x66L)))) ^ l_2599) || g_541) >= l_2600) >= l_2528) != 6L) <= g_538) >= l_2599), l_2528)), 0x61L)) ^ g_949[2][8][6])), g_543[1])), (-4L))));

l_2525 += 1;



for (l_3707 = 0; l_3707 < 6; l_3707++)
    {
        transparent_crc(g_1215[l_3707], "g_1215[l_3707]", g_2576);
        if (g_2576) printf("index = [%d]\n", l_3707);

    };


                    l_2585[2] = ((l_2601 < (safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((l_2616 = ((safe_lshift_func_uint16_t_u_s(l_2266[0], 6)) ^ ((+(l_2547 = g_949[0][6][1])) && (l_2584 != (safe_sub_func_uint16_t_u_u(((l_2408[2][4] = 6L) ^ (safe_mod_func_int32_t_s_s(g_173, g_172[4]))), (+((-1L) && (safe_lshift_func_uint8_t_u_u(g_2476, g_541)))))))))), 0)), 11))) <= l_2387);
                        g_247 = g_1129;
                    }

if ((safe_lshift_func_uint16_t_u_s(0xCDD4L, l_5[5][4])))
            {
                int8_t l_2662[2];
                int32_t l_2672 = 0x458B65B5L;
                int32_t l_2691[7][4] = {{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)},{0xA7CC0C33L,(-1L),0xA7CC0C33L,0xA7CC0C33L},{(-1L),(-1L),0xB115895CL,(-1L)},{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)},{0xA7CC0C33L,(-1L),0xA7CC0C33L,0xA7CC0C33L},{(-1L),(-1L),0xB115895CL,(-1L)},{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)}};
                uint8_t l_2701 = 0x03L;
                int i, j;

for (l_2290 = 0; l_2290 < 1; l_2290++)
                l_2566[l_3492][l_2290] = 1UL;

                    for (i = 0; i < 2; i++)
                    l_2662[i] = (-6L);
                l_2547 = (((l_2547 = (j = (l_4035 = ((l_2547 < ((safe_add_func_int32_t_s_s(g_949[0][6][1], ((+((safe_lshift_func_uint16_t_u_u((((l_2575 = ((g_3258 = ((l_2662[0] < (((((safe_lshift_func_int16_t_s_u(((safe_add_func_int16_t_s_s((((safe_lshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u(65535UL, (~(((l_2662[1] >= l_2513) >= 9L) && g_2177[5][0][0])))), 5)) >= g_359[6][0]) >= l_2619[1]), l_2662[0])) ^ 0x2BBDAAFAL), g_813[5][0])) ^ l_2672) | 250UL) & (-8L)) != l_2495)) == g_949[2][0][1])) ^ 0x0227889AL)) <= (-9L)) >= g_1524), g_2177[4][1][5])) && l_2547)) < 0x41L))) & g_813[1][0])) == 0x5FL)))) != g_543[2]) > l_3257);
                for (l_3655 = 0; (l_3655 <= 6); l_3655 += 1)
                {
                    l_3655 = 0L;
                    for (l_2575 = 0; (l_2575 <= 6); l_2575 += 1)
                    {
                        int32_t l_2677[7][8][4] = {{{1L,0x41A054B2L,0L,0x2D0DBF52L},{0x0CF1A441L,0L,(-5L),(-1L)},{(-4L),0L,0x731C9F43L,0x01A3D290L},{0L,(-10L),0x0D46BF51L,0x0D46BF51L},{3L,3L,0x4CB0245BL,0x60E2D043L},{0x0D46BF51L,0L,0xCE5C71E8L,0xD450BA5CL},{1L,0xBBB0E83CL,(-1L),0xCE5C71E8L},{0xBC9F03A0L,0xBBB0E83CL,(-10L),0xD450BA5CL}},{{0xBBB0E83CL,0L,(-1L),0x60E2D043L},{1L,3L,0xBC9F03A0L,0x0D46BF51L},{0x731C9F43L,(-10L),(-9L),0x01A3D290L},{0x4CB0245BL,0L,0x7AE1F11BL,(-1L)},{0xB8ACCB37L,0L,1L,0x2D0DBF52L},{0x60E2D043L,0x41A054B2L,0x830FB6EAL,(-4L)},{0L,(-1L),0L,2L},{(-9L),0L,3L,(-10L)}},{{0L,0x2D0DBF52L,0L,0L},{0x41A054B2L,0x8FB9928BL,0L,0x0CF1A441L},{0L,0x731C9F43L,3L,0x7AE1F11BL},{(-9L),0L,0L,(-3L)},{0L,(-3L),0x830FB6EAL,0L},{0x60E2D043L,(-9L),1L,0L},{0xB8ACCB37L,(-1L),0x7AE1F11BL,0xA2CE5981L},{0x4CB0245BL,0xB8ACCB37L,(-9L),(-1L)}},{{0x731C9F43L,0xBC9F03A0L,0xBC9F03A0L,0x731C9F43L},{1L,0xD450BA5CL,(-1L),(-9L)},{0xBBB0E83CL,0x0CF1A441L,(-10L),1L},{0xBC9F03A0L,0L,(-1L),1L},{1L,0x0CF1A441L,0xCE5C71E8L,(-9L)},{0x0D46BF51L,0xD450BA5CL,0x4CB0245BL,0x731C9F43L},{3L,0xBC9F03A0L,0x0D46BF51L,(-1L)},{0L,0xB8ACCB37L,0x731C9F43L,0xA2CE5981L}},{{(-4L),(-1L),(-5L),0L},{0x0CF1A441L,2L,0L,(-1L)},{0x7AE1F11BL,0x2D0DBF52L,0xCE5C71E8L,0x2D0DBF52L},{0x8FB9928BL,0xA2CE5981L,0x2D0DBF52L,1L},{1L,1L,(-9L),0x41A054B2L},{0x0D46BF51L,(-3L),0L,(-4L)},{0x0D46BF51L,(-5L),(-9L),0L},{1L,(-4L),0x2D0DBF52L,0xB8ACCB37L}},{{0x8FB9928BL,(-9L),0xCE5C71E8L,0x0CF1A441L},{0x7AE1F11BL,(-1L),0L,(-5L)},{0x41A054B2L,0L,0x01A3D290L,0x8FB9928BL},{0x0CF1A441L,0L,1L,0xBC9F03A0L},{0xA2CE5981L,0L,(-10L),(-10L)},{0x4CB0245BL,0x4CB0245BL,9L,1L},{(-10L),0L,1L,0L},{0L,0L,0x0D46BF51L,1L}},{{0x731C9F43L,0L,0L,0L},{0L,0L,1L,1L},{0xD450BA5CL,0x4CB0245BL,0x731C9F43L,(-10L)},{1L,0L,2L,0xBC9F03A0L},{9L,0L,1L,0x8FB9928BL},{0x830FB6EAL,0L,0xD450BA5CL,(-5L)},{1L,(-1L),3L,0x0CF1A441L},{0xBBB0E83CL,(-9L),0xBBB0E83CL,0xB8ACCB37L}}};
                        int i, j, k;
                        l_2677[4][2][3] = (safe_unary_minus_func_int16_t_s((safe_unary_minus_func_int8_t_s((g_359[(l_3655 + 1)][l_2575] > g_1524)))));
                    }
                }
                if (((j = (((l_2291[1] = g_172[1]) && (safe_sub_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_u((((l_2292 = (g_2177[0][0][9] = ((l_2575 > g_115) & (((safe_mod_func_int32_t_s_s((((((((((safe_lshift_func_int8_t_s_u((g_3409 = (((safe_add_func_uint8_t_u_u(l_2662[1], ((-1L) <= g_1524))) != ((((safe_sub_func_int32_t_s_s((!g_1524), ((l_2691[0][0] = (l_2408[3][0] = ((0xB248A39EL & ((g_188 = (-2L)) < g_3258)) >= l_2662[1]))) && g_1524))) && g_866[4][0]) && l_2691[0][2]) > g_1524)) & 0L)), l_2479)) <= g_866[4][0]) == g_1524) | l_3655) && g_2177[3][3][8]) <= l_2841) ^ g_1524) != l_2479) ^ 0xECF0AEBAL), 0xCF415C16L)) > g_543[1]) == g_1524)))) < l_2291[0]) & l_2266[3]), l_2575)) && (-4L)), g_359[1][6]))) == 0xBF9AL)) > 0xEE49L))
                {
                    int32_t l_2700 = (-6L);
                    g_115 = 1L;

if (l_2296) printf("index = [%d]\n", g_3484);

                    g_115 = (((0xB2637E3CL != (~((safe_add_func_int8_t_s_s((l_2691[0][0] = g_115), (l_3873 = (l_2292 = (((-3L) ^ (l_2701 = (l_2700 = (safe_mod_func_uint8_t_u_u(0xD2L, 5UL))))) ^ (g_172[1] == ((safe_sub_func_int16_t_s_s(((g_543[1] = (l_3873 & ((!(safe_mod_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(g_974, 0x8C7F0823L)) == l_3775), l_2672))) >= 0UL))) > 0xA047L), l_2672)) >= l_3752))))))) && l_3873))) <= g_1524) > 0L);
                    l_3873 = (249UL & ((safe_lshift_func_int16_t_s_u(g_1129, 6)) && 1UL));
                }
                else
                {
                    int32_t l_2715 = 0x20D70AE1L;
                    int32_t l_2723 = 0x493688ADL;
                    for (l_3171 = 0; (l_3171 > 25); l_3171++)
                    {
                        uint16_t l_2724 = 65535UL;
                        l_3873 = ((((((g_974 = l_2715) & ((4UL == l_2408[3][2]) <= (safe_unary_minus_func_uint32_t_u(((safe_add_func_int8_t_s_s((safe_add_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(l_3655, 14)), ((l_2723 = 0xEEF6D83EL) > l_2513))), 0x16L)) && l_2279))))) >= ((l_2691[3][1] = 65535UL) > l_2724)) && g_359[9][6]) || l_2662[0]) > l_3171);
                        return g_115;
                    }
                    j = (l_2691[0][0] = ((l_2293[5][4][4] = (l_5[4][2] | ((g_115 ^ (((0x3248F897L < ((safe_unary_minus_func_int16_t_s(0xA585L)) ^ (l_2495 > l_2513))) < ((0L && (((-10L) < (0x522993A5L < 0x6C6B07C7L)) == l_2408[3][0])) || g_103)) > g_115)) > 0x637DBBF8L))) && l_3257));
                    l_3017 = (safe_unary_minus_func_int8_t_s((l_2495 = ((safe_rshift_func_uint16_t_u_u(1UL, 7)) < (l_4035 || l_3257)))));
                    for (l_2575 = 0; (l_2575 <= (-25)); l_2575--)
                    {
                        g_115 = l_3171;

{
                if (l_3534)
                    break;
            }

                    return g_949[0][6][1];
                    }
                }
            }
            else
            {
                l_2408[0][5] = l_2619[1];
                g_115 = (((((((safe_rshift_func_uint8_t_u_s((g_2177[3][1][9] = ((safe_add_func_uint8_t_u_u((safe_add_func_int32_t_s_s(g_188, (l_2408[0][0] = (safe_add_func_uint8_t_u_u((l_2479 = (g_3258 < (g_172[4] != 0xD4L))), 1L))))), ((g_1524 == g_115) < (l_3655 < l_2619[1])))) < g_1215[1])), 7)) <= l_2525) ^ 0xC9C7L) && 1UL) || l_3655) | l_3655) != g_1524);
            };


                    g_247 = (safe_mod_func_uint32_t_u_u(l_2619[1], ((((g_2576 < g_161) || l_2620) == ((((safe_sub_func_int16_t_s_s(((g_2177[3][1][9] = l_2547) | (l_2418[2][1] < (+(0xC4FEL ^ (safe_rshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s((((l_2528 > (-1L)) | (-1L)) > g_173), g_359[4][0])), 2UL)), 7)))))), g_115)) > l_2266[4]) <= 2UL) < l_2525)) ^ (-6L))));
                }
            }

{
            transparent_crc(g_813[g_541][g_541], "g_813[g_541][g_541]", l_2290);
            if (l_2290) printf("index = [%d][%d]\n", g_541, g_541);

        }

                    l_2290 = (safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u(((safe_mod_func_uint32_t_u_u((((l_2408[3][0] = g_2476) <= ((g_359[9][0] & (safe_rshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((g_359[6][6] && (safe_mod_func_uint8_t_u_u(((((safe_rshift_func_uint8_t_u_s(((safe_sub_func_int8_t_s_s((g_974 & (g_217 = (safe_sub_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((((~0x448CL) ^ (safe_lshift_func_int8_t_s_s(((g_172[4] = g_2352[7]) | ((safe_lshift_func_uint16_t_u_s(0xEFAAL, 7)) < 6UL)), 7))) < (1L > g_813[1][0])), g_63)), l_2293[5][4][4])))), 255UL)) ^ g_2177[3][1][9]), l_2294)) || 1UL) != g_188) < l_2600), (-1L)))), g_247)), 6))) | g_541)) < 4294967295UL), g_361)) || l_2620), 1)), 7));
            for (g_63 = 0; g_63 < 3; g_63 += 1)
            {

for (g_3484 = 0; g_3484 < 10; g_3484++)
    {
        for (l_2295 = 0; l_2295 < 7; l_2295++)
        {
            transparent_crc(g_359[g_3484][l_2295], "g_359[g_3484][l_2295]", l_3017);
            if (l_3017) printf("index = [%d][%d]\n", g_3484, l_2295);

        }
    };


                    for (g_22 = 0; g_22 < 9; g_22 += 1)
                {

{
                        int16_t l_2482 = 0xC29FL;
                        l_3471 = (l_2482 >= (safe_add_func_uint16_t_u_u((l_3707 == l_2292), 0x0D89L)));
                        l_2293[5][4][4] = l_2601;
                    }

                    for (g_83 = 0; g_83 < 9; g_83 += 1)
                    {

if (l_2899)
                            break;

                    g_949[g_63][g_22][g_83] = 0L;
                    }
                }
            }
        }
        else
        {
            int16_t l_2673 = (-1L);
            int32_t l_2704 = (-1L);
            if ((safe_lshift_func_uint16_t_u_s(0xCDD4L, l_5[5][4])))
            {
                int8_t l_2662[2];
                int32_t l_2672 = 0x458B65B5L;
                int32_t l_2691[7][4] = {{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)},{0xA7CC0C33L,(-1L),0xA7CC0C33L,0xA7CC0C33L},{(-1L),(-1L),0xB115895CL,(-1L)},{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)},{0xA7CC0C33L,(-1L),0xA7CC0C33L,0xA7CC0C33L},{(-1L),(-1L),0xB115895CL,(-1L)},{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)}};
                uint8_t l_2701 = 0x03L;
                int i, j;
                for (i = 0; i < 2; i++)
                    {
for (l_3891 = 0; (l_3891 > 18); l_3891 = safe_add_func_uint32_t_u_u(l_3891, 3))
        {
            uint16_t l_3255[4][5];
            int32_t l_3256[2][8] = {{0L,0L,0x73962BB8L,0x73962BB8L,0L,0L,0x73962BB8L,0x73962BB8L},{0L,0L,0x73962BB8L,0x73962BB8L,0L,0L,0x73962BB8L,0x73962BB8L}};
            int i, j;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 5; j++)
                    l_3255[i][j] = 0x74B9L;
            }
            if ((safe_sub_func_uint16_t_u_u((l_3683 || (safe_add_func_uint32_t_u_u(((((((l_2790[4][0] || ((((g_538 != ((l_3256[1][3] = (l_3721 >= (g_541 = (l_2672 = (g_3258 = (((safe_sub_func_int32_t_s_s(((((safe_mod_func_uint8_t_u_u(((((g_1215[2] & ((l_3872 = (l_3721 = (safe_add_func_uint16_t_u_u(l_3683, (65529UL != ((g_974 & ((safe_add_func_int8_t_s_s(3L, g_1215[1])) <= l_3255[1][3])) != 0x21FD1DCEL)))))) < (-8L))) >= 0xBAL) != g_1129) > l_5[3][0]), l_3721)) < 0L) & l_3752) ^ 0xA4EBL), 0xA9004A2AL)) > g_813[3][0]) != l_3255[1][3])))))) > l_3255[1][3])) & g_543[0]) >= g_1129) ^ 1L)) != 0L) & l_3775) ^ l_3741) & g_3957) | l_3255[0][4]), 1UL))), l_3721)))
            {
                uint32_t l_3263 = 4294967295UL;
                int32_t l_3303 = 0L;
                for (g_3421 = 0; (g_3421 != 43); g_3421++)
                {
                    uint32_t l_3304 = 0xA0CD230EL;
                    int32_t l_3305[2][8][1] = {{{0xC3B07C44L},{0xC3B07C44L},{0x80AED170L},{0xAF71240FL},{0x9433F045L},{0xAF71240FL},{0x80AED170L},{0xC3B07C44L}},{{0xC3B07C44L},{0x80AED170L},{0xAF71240FL},{0x9433F045L},{0xAF71240FL},{0x80AED170L},{0xC3B07C44L},{0xC3B07C44L}}};
                    int i, j, k;
                    g_3484 = (g_538 <= l_3151);
                    l_3263 = 0x3D7DBF13L;
                    if (g_2177[1][0][6])
                    {
                        return l_3667;
                    }
                    else
                    {
                        uint8_t l_3287 = 5UL;
                        l_3305[0][3][0] = (((safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((g_2420 = ((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s((safe_unary_minus_func_int16_t_s((((safe_add_func_int16_t_s_s((g_1215[3] = l_3255[2][2]), ((safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(((safe_add_func_int32_t_s_s(((safe_mod_func_uint16_t_u_u((l_3256[1][3] = ((safe_sub_func_int32_t_s_s((l_2672 = 1L), (safe_lshift_func_int16_t_s_s(((0x83DAL <= (g_2177[3][1][9] > (l_3287 | 1UL))) <= (((safe_sub_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u((((safe_rshift_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(((l_3303 = (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_uint32_t_u((((safe_add_func_uint16_t_u_u(((l_3256[1][3] < l_3287) < ((safe_sub_func_int32_t_s_s(l_3287, 7UL)) && g_538)), l_3721)) >= 0x318768DEL) && l_3263))), 9))) != l_3683), l_3256[1][6])), 4)) >= l_3304) | l_3655), l_3287)) ^ l_3721), 0L)) ^ 0x51L) != g_103)), 15)))) >= l_3287)), (-1L))) && g_2177[5][1][8]), g_813[6][0])) ^ 0xAFL), g_103)), g_22)) >= 0x34L))) == g_359[9][2]) | g_1215[4]))), l_3667)), l_3151)) == l_3255[0][1])), 4)), 6)) || 4UL) | l_3287);
                    }
                }
                for (l_3683 = 0; (l_3683 <= (-20)); l_3683 = safe_sub_func_uint8_t_u_u(l_3683, 5))
                {
                    l_3872 = (g_359[9][0] ^ (l_3655 != (((safe_rshift_func_uint16_t_u_u(9UL, (safe_sub_func_int16_t_s_s((g_543[1] = 0x560CL), (safe_lshift_func_int16_t_s_s((!l_3303), 7)))))) > ((l_3721 && ((g_3956[3] = 65535UL) != (l_3741 & (g_3258 = ((-10L) > 0xD9890121L))))) > l_3683)) | l_3256[1][3])));
                    l_3303 = 0x9ED79E98L;
                    l_2672 = (l_3256[1][2] = (l_3872 = (0x6A45L != (g_188 = (-1L)))));
                    l_3721 = 0xA5D6E7B4L;
                }
                for (l_3872 = (-29); (l_3872 < 29); l_3872++)
                {
                    int32_t l_3319 = 4L;
                    for (g_1129 = 1; (g_1129 <= 7); g_1129 += 1)
                    {
                        int i, j;
                        return g_866[g_1129][(g_1129 + 1)];
                    }
                    for (l_2294 = (-5); (l_2294 > 23); l_2294++)
                    {
                        l_3319 = 0x34207361L;
                    }
                }
            }
            else
            {
                l_3721 = l_3721;
            }
            l_3872 = (safe_lshift_func_uint8_t_u_s((safe_sub_func_int16_t_s_s((((((((safe_add_func_int8_t_s_s(0x88L, (g_541 ^ (safe_unary_minus_func_uint32_t_u(g_3421))))) >= 0xE6B5L) <= (g_359[9][0] || g_813[1][0])) < (0xD1BFL && (((0x8B84L != (safe_sub_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((l_3891 >= l_3256[1][3]), l_2294)), l_2790[4][0])) > 0x93L), l_3255[1][3]))) | g_2177[4][3][5]) ^ l_3721))) < g_2352[1]) == g_3957) & 65530UL), l_3721)), l_5[1][6]));
        };


                    l_2662[i] = (-6L);}
                g_22 = (((l_2290 = (l_2295 = (g_2420 = ((g_22 < ((safe_add_func_int32_t_s_s(g_949[0][6][1], ((+((safe_lshift_func_uint16_t_u_u((((g_4 = ((g_247 = ((l_2662[0] < (((((safe_lshift_func_int16_t_s_u(((safe_add_func_int16_t_s_s((((safe_lshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u(65535UL, (~(((l_2662[1] >= g_541) >= 9L) && g_2177[5][0][0])))), 5)) >= g_359[6][0]) >= l_2619[1]), l_2662[0])) ^ 0x2BBDAAFAL), g_813[5][0])) ^ l_2672) | 250UL) & (-8L)) != g_83)) == g_949[2][0][1])) ^ 0x0227889AL)) <= (-9L)) >= l_2673), g_2177[4][1][5])) && g_22)) < 0x41L))) & g_813[1][0])) == 0x5FL)))) != g_543[2]) > g_540);
                for (g_1460 = 0; (g_1460 <= 6); g_1460 += 1)
                {
                    l_2674 = 0L;

{
                    i = 0x647B4652L;
                }

                    for (l_2465 = 0; (l_2465 <= 6); l_2465 += 1)
                    {
                        int32_t l_2677[7][8][4] = {{{1L,0x41A054B2L,0L,0x2D0DBF52L},{0x0CF1A441L,0L,(-5L),(-1L)},{(-4L),0L,0x731C9F43L,0x01A3D290L},{0L,(-10L),0x0D46BF51L,0x0D46BF51L},{3L,3L,0x4CB0245BL,0x60E2D043L},{0x0D46BF51L,0L,0xCE5C71E8L,0xD450BA5CL},{1L,0xBBB0E83CL,(-1L),0xCE5C71E8L},{0xBC9F03A0L,0xBBB0E83CL,(-10L),0xD450BA5CL}},{{0xBBB0E83CL,0L,(-1L),0x60E2D043L},{1L,3L,0xBC9F03A0L,0x0D46BF51L},{0x731C9F43L,(-10L),(-9L),0x01A3D290L},{0x4CB0245BL,0L,0x7AE1F11BL,(-1L)},{0xB8ACCB37L,0L,1L,0x2D0DBF52L},{0x60E2D043L,0x41A054B2L,0x830FB6EAL,(-4L)},{0L,(-1L),0L,2L},{(-9L),0L,3L,(-10L)}},{{0L,0x2D0DBF52L,0L,0L},{0x41A054B2L,0x8FB9928BL,0L,0x0CF1A441L},{0L,0x731C9F43L,3L,0x7AE1F11BL},{(-9L),0L,0L,(-3L)},{0L,(-3L),0x830FB6EAL,0L},{0x60E2D043L,(-9L),1L,0L},{0xB8ACCB37L,(-1L),0x7AE1F11BL,0xA2CE5981L},{0x4CB0245BL,0xB8ACCB37L,(-9L),(-1L)}},{{0x731C9F43L,0xBC9F03A0L,0xBC9F03A0L,0x731C9F43L},{1L,0xD450BA5CL,(-1L),(-9L)},{0xBBB0E83CL,0x0CF1A441L,(-10L),1L},{0xBC9F03A0L,0L,(-1L),1L},{1L,0x0CF1A441L,0xCE5C71E8L,(-9L)},{0x0D46BF51L,0xD450BA5CL,0x4CB0245BL,0x731C9F43L},{3L,0xBC9F03A0L,0x0D46BF51L,(-1L)},{0L,0xB8ACCB37L,0x731C9F43L,0xA2CE5981L}},{{(-4L),(-1L),(-5L),0L},{0x0CF1A441L,2L,0L,(-1L)},{0x7AE1F11BL,0x2D0DBF52L,0xCE5C71E8L,0x2D0DBF52L},{0x8FB9928BL,0xA2CE5981L,0x2D0DBF52L,1L},{1L,1L,(-9L),0x41A054B2L},{0x0D46BF51L,(-3L),0L,(-4L)},{0x0D46BF51L,(-5L),(-9L),0L},{1L,(-4L),0x2D0DBF52L,0xB8ACCB37L}},{{0x8FB9928BL,(-9L),0xCE5C71E8L,0x0CF1A441L},{0x7AE1F11BL,(-1L),0L,(-5L)},{0x41A054B2L,0L,0x01A3D290L,0x8FB9928BL},{0x0CF1A441L,0L,1L,0xBC9F03A0L},{0xA2CE5981L,0L,(-10L),(-10L)},{0x4CB0245BL,0x4CB0245BL,9L,1L},{(-10L),0L,1L,0L},{0L,0L,0x0D46BF51L,1L}},{{0x731C9F43L,0L,0L,0L},{0L,0L,1L,1L},{0xD450BA5CL,0x4CB0245BL,0x731C9F43L,(-10L)},{1L,0L,2L,0xBC9F03A0L},{9L,0L,1L,0x8FB9928BL},{0x830FB6EAL,0L,0xD450BA5CL,(-5L)},{1L,(-1L),3L,0x0CF1A441L},{0xBBB0E83CL,(-9L),0xBBB0E83CL,0xB8ACCB37L}}};
                        int i, j, k;
                        l_2677[4][2][3] = (safe_unary_minus_func_int16_t_s((safe_unary_minus_func_int8_t_s((g_359[(g_1460 + 1)][l_2465] > l_2673)))));
                    }
                }
                if (((l_2295 = (((l_2291[1] = g_172[1]) && (safe_sub_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_u((((g_217 = (g_2177[0][0][9] = ((g_4 > g_2576) & (((safe_mod_func_int32_t_s_s((((((((((safe_lshift_func_int8_t_s_u((g_361 = (((safe_add_func_uint8_t_u_u(l_2662[1], ((-1L) <= l_2673))) != ((((safe_sub_func_int32_t_s_s((!g_188), ((l_2691[0][0] = (l_2408[3][0] = ((0xB248A39EL & ((g_974 = (-2L)) < g_247)) >= l_2662[1]))) && l_2673))) && g_866[4][0]) && l_2691[0][2]) > l_2673)) & 0L)), g_173)) <= g_866[4][0]) == l_2673) | g_1460) && g_2177[3][3][8]) <= l_2692) ^ l_2673) != g_173) ^ 0xECF0AEBAL), 0xCF415C16L)) > g_543[1]) == l_2673)))) < l_2291[0]) & l_2266[3]), l_2465)) && (-4L)), g_359[1][6]))) == 0xBF9AL)) > 0xEE49L))
                {
                    int32_t l_2700 = (-6L);
                    g_2576 = 1L;

if (((k = (((l_2291[1] = g_172[1]) && (safe_sub_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_u((((l_2292 = (g_2177[0][0][9] = ((g_361 > l_3891) & (((safe_mod_func_int32_t_s_s((((((((((safe_lshift_func_int8_t_s_u((l_3741 = (((safe_add_func_uint8_t_u_u(l_2662[1], ((-1L) <= g_188))) != ((((safe_sub_func_int32_t_s_s((!g_188), ((l_2691[0][0] = (l_2408[3][0] = ((0xB248A39EL & ((g_188 = (-2L)) < g_22)) >= l_2662[1]))) && g_188))) && g_866[4][0]) && l_2691[0][2]) > g_188)) & 0L)), l_2674)) <= g_866[4][0]) == g_188) | l_2292) && g_2177[3][3][8]) <= l_3399) ^ g_188) != l_2674) ^ 0xECF0AEBAL), 0xCF415C16L)) > g_543[1]) == g_188)))) < l_2291[0]) & g_3956[3]), g_361)) && (-4L)), g_359[1][6]))) == 0xBF9AL)) > 0xEE49L))
                {
                    int32_t l_2700 = (-6L);
                    l_3891 = 1L;
                    l_3891 = (((0xB2637E3CL != (~((safe_add_func_int8_t_s_s((l_2691[0][0] = l_3891), (g_115 = (l_2292 = (((-3L) ^ (g_1460 = (l_2700 = (safe_mod_func_uint8_t_u_u(0xD2L, 5UL))))) ^ (g_172[1] == ((safe_sub_func_int16_t_s_s(((g_543[1] = (g_115 & ((!(safe_mod_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(l_2601, 0x8C7F0823L)) == g_63), l_3872))) >= 0UL))) > 0xA047L), l_3872)) >= g_2710))))))) && g_115))) <= g_188) > 0L);
                    g_115 = (249UL & ((safe_lshift_func_int16_t_s_u(l_3655, 6)) && 1UL));
                }
                else
                {
                    int32_t l_2715 = 0x20D70AE1L;
                    int32_t l_2723 = 0x493688ADL;
                    for (l_3775 = 0; (l_3775 > 25); l_3775++)
                    {
                        uint16_t l_2724 = 65535UL;
                        g_115 = ((((((g_188 = l_2715) & ((4UL == l_2408[3][2]) <= (safe_unary_minus_func_uint32_t_u(((safe_add_func_int8_t_s_s((safe_add_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(g_1129, 14)), ((l_2723 = 0xEEF6D83EL) > g_541))), 0x16L)) && l_2899))))) >= ((l_2691[3][1] = 65535UL) > l_2724)) && g_359[9][6]) || l_2662[0]) > l_3775);
                        return g_115;
                    }
                    k = (l_2691[0][0] = ((l_2293[5][4][4] = (l_5[4][2] | ((l_3891 ^ (((0x3248F897L < ((safe_unary_minus_func_int16_t_s(0xA585L)) ^ (l_3741 > g_541))) < ((0L && (((-10L) < (0x522993A5L < 0x6C6B07C7L)) == l_2408[3][0])) || l_3257)) > l_3891)) > 0x637DBBF8L))) && l_3257));
                    l_2294 = (safe_unary_minus_func_int8_t_s((l_3741 = ((safe_rshift_func_uint16_t_u_u(1UL, 7)) < (l_3741 || l_3257)))));
                    for (g_361 = 0; (g_361 <= (-25)); g_361--)
                    {
                        l_3891 = l_3775;
                        return g_949[0][6][1];
                    }
                };


                    g_2576 = (((0xB2637E3CL != (~((safe_add_func_int8_t_s_s((l_2691[0][0] = l_2296), (l_2704 = (g_217 = (((-3L) ^ (l_2701 = (l_2700 = (safe_mod_func_uint8_t_u_u(0xD2L, 5UL))))) ^ (g_172[1] == ((safe_sub_func_int16_t_s_s(((g_543[1] = (l_2704 & ((!(safe_mod_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(l_2601, 0x8C7F0823L)) == g_63), l_2672))) >= 0UL))) > 0xA047L), l_2672)) >= g_2710))))))) && l_2704))) <= l_2673) > 0L);
                    l_2704 = (249UL & ((safe_lshift_func_int16_t_s_u(g_1129, 6)) && 1UL));
                }
                else
                {
                    int32_t l_2715 = 0x20D70AE1L;
                    int32_t l_2723 = 0x493688ADL;
                    for (g_538 = 0; (g_538 > 25); g_538++)
                    {
                        uint16_t l_2724 = 65535UL;
                        l_2704 = ((((((g_1524 = l_2715) & ((4UL == l_2408[3][2]) <= (safe_unary_minus_func_uint32_t_u(((safe_add_func_int8_t_s_s((safe_add_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(g_12, 14)), ((l_2723 = 0xEEF6D83EL) > g_541))), 0x16L)) && g_161))))) >= ((l_2691[3][1] = 65535UL) > l_2724)) && g_359[9][6]) || l_2662[0]) > g_538);
                        return g_115;
                    }
                    l_2295 = (l_2691[0][0] = ((l_2293[5][4][4] = (l_5[4][2] | ((g_2576 ^ (((0x3248F897L < ((safe_unary_minus_func_int16_t_s(0xA585L)) ^ (g_83 > g_541))) < ((0L && (((-10L) < (0x522993A5L < 0x6C6B07C7L)) == l_2408[3][0])) || g_103)) > l_2296)) > 0x637DBBF8L))) && g_540));
                    g_2476 = (safe_unary_minus_func_int8_t_s((g_83 = ((safe_rshift_func_uint16_t_u_u(1UL, 7)) < (g_2420 || g_540)))));
                    for (g_4 = 0; (g_4 <= (-25)); g_4--)
                    {
                        g_2576 = g_538;
                        return g_949[0][6][1];
                    }
                }
            }
            else
            {
                l_2408[0][5] = l_2619[1];


g_1129 += 1;


                    g_538 += 1;


                    g_2576 = (((((((safe_rshift_func_uint8_t_u_s((g_2177[3][1][9] = ((safe_add_func_uint8_t_u_u((safe_add_func_int32_t_s_s(l_2600, (l_2408[0][0] = (safe_add_func_uint8_t_u_u((g_173 = (g_247 < (g_172[4] != 0xD4L))), 1L))))), ((l_2673 == g_115) < (g_12 < l_2619[1])))) < g_1215[1])), 7)) <= g_2598) ^ 0xC9C7L) && 1UL) || g_1460) | g_12) != l_2673);
            }
        }
        return g_538;
    }
    else
    {
        uint32_t l_2750 = 0UL;
        int16_t l_2774 = 0x1B44L;
        uint32_t l_2816 = 8UL;
        uint16_t l_2838 = 0x80C3L;
        uint32_t l_2839[4][5][4] = {{{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL}},{{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL}},{{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL}},{{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL}}};
        int32_t l_2840 = (-1L);
        uint32_t l_2842 = 4294967293UL;
        uint32_t l_2858 = 6UL;
        int32_t l_2886[5] = {0x58E56A96L,0x58E56A96L,0x58E56A96L,0x58E56A96L,0x58E56A96L};
        uint8_t l_2918 = 251UL;
        uint32_t l_3026 = 0xD83BFFE3L;
        uint16_t l_3036[9][4][6] = {{{0x87ECL,6UL,0x87ECL,7UL,0UL,0x77DEL},{0x87ECL,0xE62AL,65535UL,0x2B5DL,65528UL,1UL},{0x707AL,65535UL,0x663BL,0x95CBL,0x87ECL,0x3B74L},{1UL,0xF5FBL,0xAEF8L,0x3B74L,65535UL,65534UL}},{{1UL,0x7B76L,0x0A26L,0x95CBL,65535UL,65528UL},{0xAEF8L,2UL,1UL,0x95CBL,0xFE06L,0UL},{1UL,0x7098L,0x6C25L,0x3B74L,0x663BL,0x69E2L},{1UL,7UL,0x2A82L,0x95CBL,0xD05AL,0x7629L}},{{0xAEF8L,1UL,0xB2E4L,0x95CBL,0x707AL,0x95CBL},{1UL,0x77DEL,1UL,0x3B74L,0xB77FL,65527UL},{1UL,0x2B5DL,0xBEA0L,0x95CBL,0x8C94L,0xCCFEL},{0xAEF8L,9UL,0xBCF5L,0x95CBL,0x87ECL,0x3B74L}},{{1UL,0xF5FBL,0xAEF8L,0x3B74L,65535UL,65534UL},{1UL,0x7B76L,0x0A26L,0x95CBL,65535UL,65528UL},{0xAEF8L,2UL,1UL,0x95CBL,0xFE06L,0UL},{1UL,0x7098L,0x6C25L,0x3B74L,0x663BL,0x69E2L}},{{1UL,7UL,0x2A82L,0x95CBL,0xD05AL,0x7629L},{0xAEF8L,1UL,0xB2E4L,0x95CBL,0x707AL,0x95CBL},{1UL,0x77DEL,1UL,0x3B74L,0xB77FL,65527UL},{1UL,0x2B5DL,0xBEA0L,0x95CBL,0x8C94L,0xCCFEL}},{{0xAEF8L,9UL,0xBCF5L,0x95CBL,0x87ECL,0x3B74L},{1UL,0xF5FBL,0xAEF8L,0x3B74L,65535UL,65534UL},{1UL,0x7B76L,0x0A26L,0x95CBL,65535UL,65528UL},{0xAEF8L,2UL,1UL,0x95CBL,0xFE06L,0UL}},{{1UL,0x7098L,0x6C25L,0x3B74L,0x663BL,0x69E2L},{1UL,7UL,0x2A82L,0x95CBL,0xD05AL,0x7629L},{0xAEF8L,1UL,0xB2E4L,0x95CBL,0x707AL,0x95CBL},{1UL,0x77DEL,1UL,0x3B74L,0xB77FL,65527UL}},{{1UL,0x2B5DL,0xBEA0L,0x95CBL,0x8C94L,0xCCFEL},{0xAEF8L,9UL,0xBCF5L,0x95CBL,0x87ECL,0x3B74L},{1UL,0xF5FBL,0xAEF8L,0x3B74L,65535UL,65534UL},{1UL,0x7B76L,0x0A26L,0x95CBL,65535UL,65528UL}},{{0xAEF8L,2UL,1UL,0x95CBL,0xFE06L,0UL},{1UL,0x7098L,0x6C25L,0x3B74L,0x663BL,0x69E2L},{1UL,0x3B74L,0UL,6UL,0x2A82L,0x0DFFL},{0x2848L,0xCCFEL,1UL,6UL,0xAEF8L,6UL}}};
        uint32_t l_3109 = 0x4E3D05E3L;
        uint8_t l_3153 = 0xD3L;
        int i, j, k;
        for (g_1524 = 0; (g_1524 <= 5); g_1524 += 1)
        {
            int16_t l_2741[4] = {(-1L),(-1L),(-1L),(-1L)};
            int8_t l_2767 = 0L;
            int32_t l_2786 = (-1L);
            uint8_t l_2805 = 0x6BL;
            int i;

{
            uint32_t l_2849 = 0x6555F265L;
            int32_t l_2882 = 0x437FFEACL;
            for (g_115 = 0; (g_115 < 14); g_115 = safe_add_func_int8_t_s_s(g_115, 9))
            {
                uint8_t l_2857[10] = {0x47L,0x47L,5UL,0x47L,0x47L,5UL,0x47L,0x47L,5UL,0x47L};
                int i;
                l_3908 = (safe_sub_func_uint32_t_u_u(((((safe_mod_func_int16_t_s_s(l_2849, l_2692)) >= ((safe_mod_func_int16_t_s_s(((((safe_add_func_uint8_t_u_u((((safe_rshift_func_int8_t_s_s(0xEBL, (g_217 & (~((g_2352[2] ^ l_2857[0]) | g_2352[8]))))) > l_3408) ^ 0xB3A2L), 1L)) > l_2692) >= 4UL) <= g_2177[3][1][9]), l_2849)) > (-1L))) & g_1215[4]) & 0x305117E2L), l_2849));
                if (l_2842)
                {
                    uint16_t l_2859[9][10][2] = {{{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L},{0x351AL,0x0962L},{0x63E3L,0x6C7BL}},{{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L},{0x2BD3L,0x351AL},{0x0962L,0x63E3L}},{{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L},{0x351AL,0x0962L}},{{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L},{0x2BD3L,0x351AL}},{{0x0962L,0x63E3L},{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L}},{{0x351AL,0x0962L},{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L}},{{0x2BD3L,0x351AL},{0x0962L,0x63E3L},{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL}},{{0x2BD3L,0x2BD3L},{0x351AL,0x0962L},{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L}},{{0x351AL,0x2BD3L},{0x2BD3L,0x351AL},{0x0962L,0x63E3L},{0UL,0xBB6AL},{1UL,0x1D2FL},{0xBB6AL,0x351AL},{0x1AC1L,0x351AL},{0xBB6AL,0x1D2FL},{1UL,0xBB6AL},{0UL,0xE5BAL}}};
                    int i, j, k;
                    l_3707 = (((l_2859[6][7][1] = 0xADBFA8FFL) >= 0x48712C93L) <= (safe_mod_func_uint16_t_u_u(g_217, 0xF825L)));
                }
                else
                {
                    uint32_t l_2870 = 7UL;
                    int16_t l_2876 = 0x4E7FL;
                    for (l_2692 = (-5); (l_2692 > 9); l_2692 = safe_add_func_uint16_t_u_u(l_2692, 3))
                    {
                        int32_t l_2875 = 0x445A8CCEL;
                        g_3258 = ((safe_lshift_func_int8_t_s_s(l_2839[3][2][0], 7)) == (safe_sub_func_uint8_t_u_u(4UL, 0x27L)));
                        l_3908 = ((l_2857[8] ^ (safe_add_func_uint16_t_u_u(g_949[0][2][8], l_2692))) >= (((((l_3408 = l_2870) > g_2352[0]) < ((safe_sub_func_int8_t_s_s((((((l_2857[6] && (((l_2870 == ((-4L) == (g_359[1][0] = (safe_add_func_uint16_t_u_u((9L & l_2875), g_315))))) < g_3152) != l_2857[0])) <= l_2408[3][0]) <= (-7L)) < g_543[1]) & 0x6FL), g_361)) <= 0xF0L)) >= l_3707) < g_217));
                    }
                    if (l_2876)
                        continue;
                    if (l_2870)
                        continue;
                }
                l_3908 = (g_361 >= (((((((l_2882 = (safe_lshift_func_int8_t_s_u(((~(safe_mod_func_uint8_t_u_u((l_2899 & l_2692), 255UL))) & l_2601), g_173))) && 255UL) || (l_3408 & (g_2420 = (!((safe_mod_func_int8_t_s_s((g_866[4][0] & (-1L)), g_3956[3])) ^ 1UL))))) && (-10L)) | 0x2BL) == 0xDDL) & l_2857[6]));
            }
        }

                    l_2266[3] = (l_2741[1] <= (-1L));

for (l_2601 = 0; (l_2601 <= 1); l_2601 += 1)
                    {
                        int i, j, k;
                        j = ((safe_rshift_func_int16_t_s_s(((((-1L) == ((((safe_sub_func_int32_t_s_s(0x814AF06EL, ((safe_mod_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(((l_3755[l_3752][l_3752][(l_3752 + 4)] != i) <= (safe_unary_minus_func_uint16_t_u(l_3026))), l_3667)), j)) < (l_3171 = (((safe_mod_func_uint32_t_u_u(((l_3872 & (safe_lshift_func_uint8_t_u_s((safe_add_func_uint32_t_u_u(0xFCA458E4L, 0xFAFCB658L)), l_3471))) && 4294967290UL), g_172[3])) | (-1L)) == g_2352[(l_3752 + 4)]))))) | 0x96617425L) && l_2840) & g_359[9][0])) & 0UL) <= 1UL), 5)) || 0x45L);
                        return j;
                    };


                    if (g_2710)
                break;
            if ((((g_538 = ((safe_lshift_func_uint16_t_u_u(((((safe_add_func_int16_t_s_s(g_359[9][0], l_2741[3])) > ((((((safe_mod_func_uint16_t_u_u(((g_866[7][9] = ((((0x6E85L <= (0x42L | l_2741[3])) <= 0x5A05L) || g_172[4]) >= ((safe_add_func_uint16_t_u_u(0UL, (((((((((g_359[9][0] == l_2526) & 1L) | g_813[1][0]) || g_538) >= g_161) == l_2465) ^ g_2420) | 0x22D5438DL) != g_813[1][0]))) > l_2294))) == 0xDB79L), l_2750)) || g_949[2][3][0]) || 0x4AL) && g_949[0][6][1]) | g_2177[3][1][9]) >= 1L)) >= g_2177[1][2][5]) < 0L), 0)) != 0x4DL)) <= 0xF9F6L) && 0x03L))
            {
                int16_t l_2751 = 0x67D2L;
                return l_2751;
            }
            else
            {
                int8_t l_2775 = 0xEAL;

if (l_3873)
                    break;

                    if (g_103)
                    break;
                for (g_1460 = 0; (g_1460 <= 7); g_1460 += 1)
                {
                    int i, j;
                    g_2476 = ((safe_lshift_func_int16_t_s_s(((safe_add_func_int32_t_s_s((g_2576 = ((l_2408[2][1] = ((((((safe_lshift_func_uint8_t_u_s((((safe_sub_func_uint32_t_u_u(g_866[g_1460][g_1524], (((((g_22 = ((safe_mod_func_uint32_t_u_u((safe_unary_minus_func_uint16_t_u(l_5[g_1524][g_1524])), (safe_lshift_func_int16_t_s_u((((safe_mod_func_int32_t_s_s(g_1215[4], ((l_2767 ^ g_247) ^ 4L))) ^ ((+((safe_mod_func_uint32_t_u_u((safe_add_func_int8_t_s_s((0L == (+(g_359[5][0] = g_866[g_1460][g_1524]))), ((((l_2774 >= l_5[g_1524][g_1524]) != l_2741[1]) >= g_1460) || g_949[0][6][1]))), 0x60FE58BBL)) | l_2741[1])) & g_2352[2])) & g_63), 5)))) || g_2710)) ^ g_2352[1]) && g_1524) > g_2710) ^ g_217))) != l_2292) | l_2526), g_1215[4])) >= g_974) < l_2775) > 0x93B1L) && l_2408[3][0]) >= g_949[0][6][1])) && l_2774)), g_172[8])) && 0L), g_188)) == g_540);
                    for (l_2294 = 0; (l_2294 <= 2); l_2294 += 1)
                    {
                        return l_2775;
                    }
                    for (l_2774 = 2; (l_2774 >= 0); l_2774 -= 1)
                    {
                        if (g_115)
                            break;
                    }
                }
            }
            for (g_315 = 0; (g_315 <= 5); g_315 += 1)
            {
                uint32_t l_2789 = 0UL;
                int i, j;

{
                uint8_t l_2857[10] = {0x47L,0x47L,5UL,0x47L,0x47L,5UL,0x47L,0x47L,5UL,0x47L};
                int i;
                j = (safe_sub_func_uint32_t_u_u(((((safe_mod_func_int16_t_s_s(g_3957, l_3257)) >= ((safe_mod_func_int16_t_s_s(((((safe_add_func_uint8_t_u_u((((safe_rshift_func_int8_t_s_s(0xEBL, (l_3752 & (~((l_3874[2] ^ l_2857[0]) | l_3874[8]))))) > l_3752) ^ 0xB3A2L), 1L)) > l_2750) >= 4UL) <= g_2177[3][1][9]), g_3957)) > (-1L))) & g_1215[4]) & 0x305117E2L), g_3957));
                if (l_2842)
                {
                    uint16_t l_2859[9][10][2] = {{{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L},{0x351AL,0x0962L},{0x63E3L,0x6C7BL}},{{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L},{0x2BD3L,0x351AL},{0x0962L,0x63E3L}},{{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L},{0x351AL,0x0962L}},{{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L},{0x2BD3L,0x351AL}},{{0x0962L,0x63E3L},{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L}},{{0x351AL,0x0962L},{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L}},{{0x2BD3L,0x351AL},{0x0962L,0x63E3L},{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL}},{{0x2BD3L,0x2BD3L},{0x351AL,0x0962L},{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L}},{{0x351AL,0x2BD3L},{0x2BD3L,0x351AL},{0x0962L,0x63E3L},{0UL,0xBB6AL},{1UL,0x1D2FL},{0xBB6AL,0x351AL},{0x1AC1L,0x351AL},{0xBB6AL,0x1D2FL},{1UL,0xBB6AL},{0UL,0xE5BAL}}};
                    int i, j, k;
                    g_541 = (((l_2859[6][7][1] = 0xADBFA8FFL) >= 0x48712C93L) <= (safe_mod_func_uint16_t_u_u(l_3752, 0xF825L)));
                }
                else
                {
                    uint32_t l_2870 = 7UL;
                    int16_t l_2876 = 0x4E7FL;
                    for (g_3957 = (-5); (g_3957 > 9); g_3957 = safe_add_func_uint16_t_u_u(g_3957, 3))
                    {
                        int32_t l_2875 = 0x445A8CCEL;
                        l_2294 = ((safe_lshift_func_int8_t_s_s(l_2839[3][2][0], 7)) == (safe_sub_func_uint8_t_u_u(4UL, 0x27L)));
                        j = ((l_2857[8] ^ (safe_add_func_uint16_t_u_u(g_949[0][2][8], l_3257))) >= (((((l_3752 = l_2870) > l_3874[0]) < ((safe_sub_func_int8_t_s_s((((((l_2857[6] && (((l_2870 == ((-4L) == (g_359[1][0] = (safe_add_func_uint16_t_u_u((9L & l_2875), l_3702))))) < g_541) != l_2857[0])) <= l_2408[3][0]) <= (-7L)) < g_543[1]) & 0x6FL), g_4)) <= 0xF0L)) >= g_541) < l_3752));
                    }
                    if (l_2876)
                        {
{
                        l_3873 = l_3471;
                        if (l_2774)
                            break;
                    }

                    continue;}
                    if (l_2870)
                        continue;
                }
                j = (g_4 >= (((((((g_22 = (safe_lshift_func_int8_t_s_u(((~(safe_mod_func_uint8_t_u_u((l_2842 & l_3399), 255UL))) & g_1524), l_2674))) && 255UL) || (l_3752 & (g_83 = (!((safe_mod_func_int8_t_s_s((g_866[4][0] & (-1L)), l_2886[3])) ^ 1UL))))) && (-10L)) | 0x2BL) == 0xDDL) & l_2857[6]));
            }

                    if ((safe_rshift_func_uint16_t_u_u(((((safe_sub_func_uint32_t_u_u(0x0CA3AF23L, ((safe_lshift_func_int16_t_s_s((((0xE3A54803L | (g_866[g_1524][(g_315 + 1)] || (0x65L < (safe_add_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_u((((l_2408[3][0] = (l_2786 = 0xAB10L)) < l_5[g_315][(g_315 + 1)]) | l_2741[1]), 8)) | 0xFAL), (((safe_sub_func_uint8_t_u_u(g_2177[3][1][0], g_1460)) <= 3UL) && l_2789)))))) == l_2774) == 4294967294UL), g_1215[4])) ^ l_5[g_315][(g_315 + 1)]))) >= l_2290) || l_5[g_315][(g_315 + 1)]) == l_2790[4][0]), l_2767)))
                {
                    int32_t l_2804 = 0xA0FDC450L;
                    int i, j;
                    g_2576 = (safe_lshift_func_uint8_t_u_u(((0x9DL || 0L) >= g_172[4]), ((safe_add_func_int8_t_s_s((((safe_lshift_func_int8_t_s_u(0xF2L, ((g_173 ^ 65535UL) > (!(l_2408[3][0] = (((g_866[g_1524][(g_1524 + 4)] = g_2710) == (safe_rshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_u(((l_2741[0] < (safe_sub_func_uint32_t_u_u((g_2352[2] | 0xC0D2L), l_2789))) & g_172[4]), l_2741[1])), l_2804))) != l_5[g_315][(g_315 + 1)])))))) == l_2774) & g_949[0][0][4]), g_188)) & g_543[1])));

if (i)
                        continue;

                    if (g_103)
                        break;
                    return l_2805;
                }
                else
                {

{
    uint32_t l_899[7][3] = {{0x87F01EA7L,0x87F01EA7L,0x87F01EA7L},{1UL,6UL,1UL},{0x87F01EA7L,0x87F01EA7L,0x87F01EA7L},{1UL,6UL,1UL},{0x87F01EA7L,0x87F01EA7L,0x87F01EA7L},{1UL,6UL,1UL},{0x87F01EA7L,0x87F01EA7L,0x87F01EA7L}};
    int32_t l_951[9][1] = {{0x65F0C153L},{(-1L)},{0x65F0C153L},{(-1L)},{0x65F0C153L},{(-1L)},{0x65F0C153L},{(-1L)},{0x65F0C153L}};
    uint32_t l_973 = 0xD1EA04B1L;
    int i, j;
    l_951[4][0] = ((func_29((0x29L >= (func_35(g_161, l_3017, l_2841, l_2465) <= ((+((0xFFE5L <= (((safe_mod_func_int16_t_s_s((safe_sub_func_uint8_t_u_u(((g_161 && l_2465) == l_3741), g_103)), l_899[6][1])) >= 8L) <= l_899[6][1])) | 8L)) | l_3741))), l_3741, l_3741, l_3741, l_899[0][2]) ^ l_3741) || 3UL);
    g_2576 = l_951[2][0];
    for (l_2292 = 0; (l_2292 == 26); ++l_2292)
    {
        uint16_t l_963[10][10] = {{0UL,2UL,65535UL,2UL,0UL,1UL,0UL,0xE16FL,0xB861L,0UL},{2UL,0xB861L,0x5B7AL,0UL,65535UL,0x705DL,1UL,0UL,0UL,0UL},{0UL,0UL,2UL,0UL,0UL,2UL,0UL,0UL,2UL,0UL},{0UL,0x705DL,0x2CCFL,2UL,0UL,0UL,0UL,65531UL,65535UL,0UL},{5UL,0UL,0x2CCFL,0UL,0xB861L,65531UL,0xB861L,0UL,0x2CCFL,0UL},{0xE16FL,0UL,2UL,0UL,0xAEDAL,0UL,0x705DL,0UL,0xF795L,5UL},{0x2CCFL,1UL,0x5B7AL,5UL,0UL,0UL,0xE16FL,0xE16FL,0UL,0UL},{0xE16FL,65535UL,65535UL,0xE16FL,2UL,65531UL,0xF795L,65535UL,0UL,0UL},{5UL,0x5B7AL,1UL,0x2CCFL,65531UL,0UL,65535UL,0xF795L,0UL,0xF795L},{0UL,2UL,0UL,0xE16FL,0UL,2UL,0UL,0xAEDAL,0UL,0x705DL}};
        int32_t l_970 = 0x9509D908L;
        int32_t l_971 = 1L;
        int32_t l_972 = (-1L);
        int i, j;
        l_972 = ((((safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u(0x6FL, 7)), (l_971 = (l_3752 = ((l_951[0][0] = (l_970 = ((safe_add_func_int8_t_s_s(l_899[6][1], l_899[6][0])) && ((~(safe_sub_func_int8_t_s_s((0x1A95L && (g_161 >= l_963[7][4])), ((l_963[9][0] != (safe_sub_func_uint8_t_u_u((((safe_sub_func_int16_t_s_s(0xB05DL, (((safe_rshift_func_int8_t_s_u(((((g_866[4][0] < 65526UL) || l_963[6][0]) >= g_543[1]) == l_899[6][1]), g_543[1])) > l_2841) < 4294967295UL))) & 0x7830B31CL) != g_103), l_963[7][4]))) > 9UL)))) > l_963[7][4])))) | g_161))))) > l_963[2][1]) < l_963[1][0]) == l_963[8][8]);
    }
    l_951[2][0] = 0xE9313C12L;
    return l_973;
}

                    return l_2741[1];
                }
            }
        }
        if ((g_2476 = (safe_rshift_func_uint16_t_u_s((l_2408[1][1] = ((4294967295UL && ((safe_mod_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_s(((safe_add_func_int32_t_s_s((safe_add_func_int8_t_s_s((l_2816 != l_2816), (g_4 = (safe_rshift_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_s(g_1460, 11)) > ((safe_add_func_uint16_t_u_u((+(l_2840 = ((safe_add_func_int16_t_s_s((l_2292 > (safe_lshift_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((g_540 = (g_4 | (l_2266[3] = ((safe_mod_func_int32_t_s_s((safe_mod_func_int16_t_s_s(l_2266[3], g_1215[4])), (safe_lshift_func_int16_t_s_u((safe_add_func_int8_t_s_s(((((l_2838 < l_2774) != 0xD9L) || 0UL) != g_543[1]), 0x0DL)), g_540)))) <= g_949[0][6][1])))) ^ l_2816), l_5[2][3])), g_63))), l_2839[3][2][0])) && g_2352[3]))), l_2816)) <= 65535UL)) > 6L), l_2816))))), g_541)) != g_949[0][6][1]), l_2841)) < g_12), l_2842)) == 0xC5L)) >= 0xB92611BCL)), 4))))
        {
            uint32_t l_2849 = 0x6555F265L;
            int32_t l_2882 = 0x437FFEACL;
            for (l_2290 = 0; (l_2290 < 14); l_2290 = safe_add_func_int8_t_s_s(l_2290, 9))
            {
                uint8_t l_2857[10] = {0x47L,0x47L,5UL,0x47L,0x47L,5UL,0x47L,0x47L,5UL,0x47L};
                int i;
                g_247 = (safe_sub_func_uint32_t_u_u(((((safe_mod_func_int16_t_s_s(l_2849, g_161)) >= ((safe_mod_func_int16_t_s_s(((((safe_add_func_uint8_t_u_u((((safe_rshift_func_int8_t_s_s(0xEBL, (g_217 & (~((g_2352[2] ^ l_2857[0]) | g_2352[8]))))) > g_173) ^ 0xB3A2L), 1L)) > l_2816) >= 4UL) <= g_2177[3][1][9]), l_2849)) > (-1L))) & g_1215[4]) & 0x305117E2L), l_2849));

for (g_2476 = 0; g_2476 < 5; g_2476++)
                        l_2266[g_2476] = 0x26DA5657L;

                    if (l_2858)
                {
                    uint16_t l_2859[9][10][2] = {{{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L},{0x351AL,0x0962L},{0x63E3L,0x6C7BL}},{{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L},{0x2BD3L,0x351AL},{0x0962L,0x63E3L}},{{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L},{0x351AL,0x0962L}},{{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L},{0x2BD3L,0x351AL}},{{0x0962L,0x63E3L},{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L}},{{0x351AL,0x0962L},{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L}},{{0x2BD3L,0x351AL},{0x0962L,0x63E3L},{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL}},{{0x2BD3L,0x2BD3L},{0x351AL,0x0962L},{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L}},{{0x351AL,0x2BD3L},{0x2BD3L,0x351AL},{0x0962L,0x63E3L},{0UL,0xBB6AL},{1UL,0x1D2FL},{0xBB6AL,0x351AL},{0x1AC1L,0x351AL},{0xBB6AL,0x1D2FL},{1UL,0xBB6AL},{0UL,0xE5BAL}}};
                    int i, j, k;
                    g_2476 = (((l_2859[6][7][1] = 0xADBFA8FFL) >= 0x48712C93L) <= (safe_mod_func_uint16_t_u_u(g_217, 0xF825L)));
                }
                else
                {
                    uint32_t l_2870 = 7UL;
                    int16_t l_2876 = 0x4E7FL;
                    for (g_103 = (-5); (g_103 > 9); g_103 = safe_add_func_uint16_t_u_u(g_103, 3))
                    {
                        int32_t l_2875 = 0x445A8CCEL;

for (g_541 = 0; g_541 < 5; g_541++)
                        g_3956[g_541] = 0x26DA5657L;

                    l_2840 = ((safe_lshift_func_int8_t_s_s(l_2839[3][2][0], 7)) == (safe_sub_func_uint8_t_u_u(4UL, 0x27L)));

if (g_115) printf("index = [%d][%d]\n", l_2294, g_2576);

                    g_247 = ((l_2857[8] ^ (safe_add_func_uint16_t_u_u(g_949[0][2][8], g_161))) >= (((((g_12 = l_2870) > g_2352[0]) < ((safe_sub_func_int8_t_s_s((((((l_2857[6] && (((l_2870 == ((-4L) == (g_359[1][0] = (safe_add_func_uint16_t_u_u((9L & l_2875), l_2838))))) < g_22) != l_2857[0])) <= l_2408[3][0]) <= (-7L)) < g_543[1]) & 0x6FL), l_2526)) <= 0xF0L)) >= g_2476) < g_217));
                    }
                    if (l_2876)
                        continue;
                    if (l_2870)
                        continue;
                }
                g_247 = (l_2526 >= (((((((l_2882 = (safe_lshift_func_int8_t_s_u(((~(safe_mod_func_uint8_t_u_u((l_2750 & l_2842), 255UL))) & g_1524), l_2674))) && 255UL) || (g_12 & (g_2420 = (!((safe_mod_func_int8_t_s_s((g_866[4][0] & (-1L)), l_2886[3])) ^ 1UL))))) && (-10L)) | 0x2BL) == 0xDDL) & l_2857[6]));
            }
        }
        else
        {
            uint8_t l_2896 = 0x25L;
            int32_t l_2900[1][7][10] = {{{1L,0x51D4F00DL,(-2L),0x72793645L,(-2L),0x51D4F00DL,1L,0x51D4F00DL,(-2L),0x72793645L},{0xD57951F1L,0x72793645L,0xD57951F1L,0x51D4F00DL,9L,0x51D4F00DL,0xD57951F1L,0x72793645L,0xD57951F1L,0x51D4F00DL},{1L,0x72793645L,0L,0x72793645L,1L,0x4FD08915L,1L,0x72793645L,0L,0x72793645L},{9L,0x51D4F00DL,0xD57951F1L,0x72793645L,0xD57951F1L,0x51D4F00DL,9L,0x51D4F00DL,0xD57951F1L,0x72793645L},{(-2L),0x72793645L,(-2L),0x51D4F00DL,1L,0x51D4F00DL,(-2L),0x72793645L,(-2L),0x51D4F00DL},{9L,0x72793645L,2L,0x72793645L,9L,0x4FD08915L,9L,0x72793645L,2L,0x72793645L},{1L,0x51D4F00DL,(-2L),0x72793645L,(-2L),0x51D4F00DL,1L,0x51D4F00DL,(-2L),0x72793645L}}};
            uint8_t l_2943 = 0x66L;
            uint32_t l_2954 = 4294967292UL;
            int16_t l_2978 = 0L;
            int32_t l_3072 = 1L;
            int i, j, k;
            for (l_2838 = (-17); (l_2838 < 7); ++l_2838)
            {
                int16_t l_2889 = 0x56E2L;
                int32_t l_2901 = 3L;
                if ((l_2889 ^ (safe_lshift_func_int16_t_s_u((g_543[0] = 0xB38AL), (safe_mod_func_int16_t_s_s((((safe_mod_func_int32_t_s_s(((0L < (l_2408[3][0] = (l_2896 != g_2352[2]))) <= 0xF7L), (((((g_188 > ((((((safe_add_func_uint16_t_u_u(((l_2266[0] = (l_2901 = (l_2899 != l_2900[0][1][8]))) != l_2900[0][1][8]), 0x6951L)) >= g_188) && 1L) ^ g_866[0][4]) && g_813[1][0]) | (-8L))) && (-1L)) > 0x6DEFL) != l_2841) | g_359[9][0]))) < l_2896) && l_2465), l_2889))))))
                {
                    return l_2816;
                }
                else
                {
                    uint32_t l_2908 = 4294967295UL;
                    int16_t l_2945 = (-1L);
                    l_2840 = (safe_rshift_func_uint8_t_u_u((0xFDF2L == ((((safe_rshift_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_u((1UL >= ((g_866[4][0] > 0x7AL) == 9UL)), g_12)) || (l_2908 == ((3UL & (g_359[9][0] != 0L)) && l_2900[0][1][8]))), g_173)) == l_2418[3][4]) != 4294967295UL) || l_2899)), g_543[1]));
                    if ((((-5L) > (4294967295UL >= ((((safe_add_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s(0xA94EL, ((g_541 && g_949[0][6][1]) < ((((((safe_rshift_func_uint16_t_u_u((((((0x4CD1L == (((safe_add_func_int32_t_s_s(g_2476, (l_2908 > (~(g_2177[3][1][9] ^ l_2908))))) >= l_2889) > 0x64F7L)) > g_540) == g_866[6][0]) != 0L) == l_2839[3][2][0]), 4)) <= l_2900[0][1][8]) <= 0xBEL) ^ g_543[1]) == g_2420) == l_2918)))), g_4)) ^ 0xDC73L) && g_173) || l_2908))) <= g_161))
                    {
                        uint32_t l_2944 = 0x023CA64AL;
                        if (g_2352[2])
                            break;
                        g_22 = ((safe_lshift_func_int16_t_s_u((safe_mod_func_int16_t_s_s((safe_sub_func_int32_t_s_s((l_2886[3] = ((((safe_sub_func_uint16_t_u_u(((g_813[6][0] = ((g_359[9][0] & (-1L)) ^ l_2601)) < (safe_mod_func_uint16_t_u_u(g_540, g_540))), (safe_add_func_uint32_t_u_u(((safe_rshift_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((((((((0x7C9D89B7L && (safe_add_func_uint16_t_u_u(g_161, (l_2889 != (g_103 = ((((safe_add_func_int8_t_s_s((safe_add_func_uint32_t_u_u(g_315, g_1129)), l_2943)) || l_5[1][6]) && l_2944) != l_2889)))))) & g_2476) != l_2266[3]) > g_974) <= g_866[5][7]) > l_2896) || 1L), (-8L))), g_2177[0][2][6])) | 0x50DFL), l_2858)))) <= l_2896) && l_2944) || 0x623CL)), 0x8170AE80L)), g_247)), l_2945)) <= 0x93L);
                    }
                    else
                    {
                        return g_188;
                    }
                    return g_247;
                }
            }

{
        int8_t l_3204 = 0xA2L;
        uint32_t l_3210 = 0xF4784D76L;
        int32_t l_3239 = 6L;
        int32_t l_3240[6];
        int i;
        for (i = 0; i < 6; i++)
            l_3240[i] = 0xADBA3217L;

{
                transparent_crc(g_949[l_2296][g_3152][l_3891], "g_949[l_2296][g_3152][l_3891]", g_3152);
                if (g_3152) printf("index = [%d][%d][%d]\n", l_2296, g_3152, l_3891);

            }

                    l_3492 = (((((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((((l_3655 & (safe_add_func_int32_t_s_s((((((l_3204 = g_543[1]) | (9L != (safe_add_func_uint32_t_u_u(l_3683, (8L | (-1L)))))) || ((safe_sub_func_int16_t_s_s((safe_unary_minus_func_uint32_t_u(l_3210)), l_3204)) <= (g_2177[3][1][9] | g_2476))) ^ l_2266[3]) != l_3210), l_3655))) <= l_3655) || 5UL), g_2177[3][1][9])), 0)) < g_2576) >= 1UL) || g_2476) > l_3072);
        l_3492 = (l_3204 <= (safe_sub_func_uint16_t_u_u(((g_974 >= (1UL || (safe_sub_func_uint8_t_u_u((g_2177[2][3][7] = (safe_sub_func_uint8_t_u_u((safe_mod_func_int16_t_s_s(((l_2978 = (safe_lshift_func_uint8_t_u_u((l_2266[1] = ((((l_3534 || (l_3072 = l_3399)) || (safe_sub_func_int8_t_s_s((safe_sub_func_int32_t_s_s(((l_3721 = (safe_mod_func_uint16_t_u_u(g_543[2], l_2465))) <= (g_543[1] || (l_3399 == 0UL))), l_3667)), 2L))) >= g_2177[5][3][1]) == l_3210)), l_3667))) != l_2418[5][4]), l_3204)), l_5[1][6]))), 0x74L)))) | g_949[2][4][8]), l_3721)));
        g_2576 = (safe_add_func_uint16_t_u_u((((l_2774 >= (safe_lshift_func_int8_t_s_s(0L, ((0L | l_2408[3][0]) < ((safe_add_func_uint32_t_u_u(l_2408[3][0], (((safe_mod_func_uint8_t_u_u(((l_3210 > ((safe_rshift_func_int16_t_s_u(((((g_359[9][0] = (l_3240[3] = (((safe_mod_func_uint16_t_u_u((g_813[1][0] = (4294967295UL == ((-5L) >= l_3210))), l_3702)) >= l_5[2][1]) | l_3239))) & 4UL) & l_3655) && l_3721), 8)) > l_2465)) == l_3239), l_3534)) > 0xBF1DC840L) != l_3026))) ^ g_2177[1][1][7]))))) < g_949[0][6][1]) > 7UL), l_3655));
        for (l_3492 = 0; (l_3492 > 18); l_3492 = safe_add_func_uint32_t_u_u(l_3492, 3))
        {
            uint16_t l_3255[4][5];
            int32_t l_3256[2][8] = {{0L,0L,0x73962BB8L,0x73962BB8L,0L,0L,0x73962BB8L,0x73962BB8L},{0L,0L,0x73962BB8L,0x73962BB8L,0L,0L,0x73962BB8L,0x73962BB8L}};
            int i, j;
            for (i = 0; i < 4; i++)
            {

{
    uint32_t l_5[6][7] = {{0x327439CBL,0xB03629AAL,0UL,0UL,0xB03629AAL,0x327439CBL,2UL},{1UL,0UL,0x91F782A1L,2UL,1UL,1UL,2UL},{0xFE4B2830L,0x1D2250DBL,0xFE4B2830L,7UL,2UL,1UL,0x327439CBL},{0x91F782A1L,0UL,1UL,7UL,1UL,0UL,0x91F782A1L},{0UL,0xB03629AAL,0x327439CBL,2UL,0UL,1UL,0UL},{0UL,0UL,0UL,0UL,0xFE4B2830L,1UL,7UL}};
    int32_t l_2266[5];
    int32_t l_2290 = (-5L);
    uint8_t l_2292 = 0xB3L;
    int32_t l_2294 = (-3L);
    int32_t l_2296 = 1L;
    int32_t l_2408[5][6] = {{0L,0L,0xC284D198L,1L,0L,1L},{0L,0L,0L,1L,0L,0xC284D198L},{0L,0L,1L,1L,0L,0L},{0L,0L,0xC284D198L,1L,0L,1L},{0L,0L,0L,1L,0L,0xC284D198L}};
    int8_t l_2418[6][5] = {{0L,0L,0L,0L,0xCAL},{0xD8L,0xA7L,0L,6L,0xCAL},{0L,0xD8L,(-1L),(-8L),(-1L)},{(-8L),(-8L),0xCAL,6L,0L},{0x38L,1L,0xCAL,0L,0L},{(-9L),0xCAL,(-1L),0xCAL,(-9L)}};
    int8_t l_2465 = 0x95L;
    int8_t l_2526 = 1L;
    int16_t l_2601 = 0L;
    uint8_t l_2674 = 0x97L;
    uint32_t l_2692 = 1UL;
    uint32_t l_2790[6][3] = {{0xCD6BF178L,0xCD6BF178L,0xCD6BF178L},{18446744073709551609UL,18446744073709551609UL,18446744073709551609UL},{0xCD6BF178L,0xCD6BF178L,0xCD6BF178L},{18446744073709551609UL,18446744073709551609UL,18446744073709551609UL},{0xCD6BF178L,0xCD6BF178L,0xCD6BF178L},{18446744073709551609UL,18446744073709551609UL,18446744073709551609UL}};
    uint32_t l_2841 = 18446744073709551607UL;
    uint32_t l_2899 = 2UL;
    int32_t l_3017 = 0x0B37558CL;
    int32_t l_3116 = 0L;
    uint8_t l_3151 = 0x0AL;
    uint16_t l_3171 = 65535UL;
    uint32_t l_3257 = 1UL;
    int32_t l_3262 = (-1L);
    uint32_t l_3399 = 7UL;
    uint8_t l_3408 = 0x12L;
    uint8_t l_3424[2][3][5] = {{{0x72L,0x5BL,0xBDL,2UL,0xBDL},{1UL,1UL,0x5BL,255UL,0xEBL},{0x72L,0xEBL,0x76L,255UL,255UL}},{{255UL,0x16L,255UL,0x72L,0xEBL},{255UL,0xBDL,0x16L,0x5BL,0xEBL},{1UL,2UL,2UL,1UL,255UL}}};
    int32_t l_3471 = 0x35FC95CDL;
    int32_t l_3492 = 0x5429EDD7L;
    uint16_t l_3534 = 3UL;
    uint32_t l_3573[10] = {6UL,6UL,6UL,6UL,6UL,6UL,6UL,6UL,6UL,6UL};
    uint8_t l_3655 = 1UL;
    int8_t l_3667 = (-1L);
    int8_t l_3683 = (-1L);
    uint16_t l_3702 = 0x4BDBL;
    int32_t l_3707 = 1L;
    int32_t l_3721 = 0x7BC1F5CCL;
    int8_t l_3741 = 0x63L;
    uint8_t l_3752 = 255UL;
    int32_t l_3755[2][2][7] = {{{0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L},{0L,0L,0L,0L,0L,0L,0L}},{{0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L},{0L,0L,0L,0L,0L,0L,0L}}};
    uint16_t l_3775 = 0x252EL;
    int32_t l_3872 = 0L;
    int32_t l_3873 = 0xE2017063L;
    int32_t l_3874[9] = {0L,0L,0L,0L,0L,0L,0L,0L,0L};
    int32_t l_3891 = 0x323AE330L;
    int32_t l_3908 = (-7L);
    int8_t l_4035 = 1L;
    int i, j, k;
    for (i = 0; i < 5; i++)
        l_2266[i] = 0x3DF77380L;
    if ((((safe_lshift_func_uint16_t_u_s(l_3667, 8)) | l_5[1][6]) != func_6((l_2266[3] = ((g_813[3][0] = func_8(l_5[1][6])) || (!(l_5[1][6] <= 1UL)))))))
    {
        uint32_t l_2279 = 0x93AE2901L;
        int32_t l_2291[2];
        int32_t l_2293[10][5][5] = {{{0x45777B37L,4L,(-5L),(-10L),(-5L)},{0xA9C5A221L,0xA9C5A221L,0x9C7A75D8L,0xD4EDE40DL,0x8ED2113AL},{0xFE015731L,2L,6L,0xA4130E32L,(-3L)},{0x4F8FF695L,9L,0xD4EDE40DL,0x6B855A03L,(-2L)},{0L,2L,0x45777B37L,0xEF9A929BL,1L}},{{(-1L),0xA9C5A221L,0x3F2DF9F6L,0x9C7A75D8L,0x4F8FF695L},{0x05E1541BL,4L,0xFE015731L,1L,(-4L)},{0x2F4D056CL,0x2206AE63L,0xD4EDE40DL,0xE58FA5B4L,0x2F4D056CL},{0x4E1AA23AL,0xEF9A929BL,0L,1L,(-7L)},{(-1L),(-8L),0x9C7A75D8L,0x9C7A75D8L,(-8L)}},{{(-3L),(-4L),0x05E1541BL,0xEF9A929BL,0xD31BC39FL},{0xE58FA5B4L,0x9C7A75D8L,0xEBCBB2E6L,0x6B855A03L,0x2F4D056CL},{(-7L),1L,0x4E1AA23AL,0xA4130E32L,0x141ABB78L},{0xE58FA5B4L,0x8ED2113AL,0xF2DC1619L,0xD4EDE40DL,0x4F8FF695L},{(-3L),(-9L),(-3L),(-10L),(-5L)}},{{(-1L),(-7L),0x2206AE63L,(-8L),(-2L)},{0x4E1AA23AL,1L,(-7L),4L,(-7L)},{0x2F4D056CL,(-1L),0x2206AE63L,(-1L),0x8ED2113AL},{0x05E1541BL,(-4L),(-3L),(-4L),0x05E1541BL},{(-1L),(-9L),0xF2DC1619L,(-2L),0xA9C5A221L}},{{0L,0xEF9A929BL,0x4E1AA23AL,4L,5L},{0x4F8FF695L,0xE58FA5B4L,0xEBCBB2E6L,(-9L),0xA9C5A221L},{0xFE015731L,4L,0x05E1541BL,(-10L),0x05E1541BL},{0xA9C5A221L,0x3F2DF9F6L,0x9C7A75D8L,0x4F8FF695L,0x8ED2113AL},{0x45777B37L,2L,0L,0xA4130E32L,(-7L)}},{{0x4F8FF695L,(-1L),0xD4EDE40DL,0xC4371B6FL,(-2L)},{6L,6L,0x80113FBEL,4L,(-4L)},{0xA9C5A221L,0xC4371B6FL,0xC4371B6FL,0xA9C5A221L,(-8L)},{0L,1L,4L,2L,(-5L)},{(-1L),(-1L),(-9L),9L,(-1L)}},{{0xD31BC39FL,4L,(-3L),2L,1L},{0x4F8FF695L,0x9C7A75D8L,0x3F2DF9F6L,0xA9C5A221L,(-1L)},{5L,(-9L),0L,4L,0x9616CC94L},{(-1L),0xA9C5A221L,0xF2DC1619L,0x2206AE63L,(-1L)},{1L,(-10L),0xD31BC39FL,0xEF9A929BL,0x05E1541BL}},{{(-1L),0xEBCBB2E6L,0xD4EDE40DL,(-8L),(-8L)},{5L,1L,5L,(-4L),0x141ABB78L},{0x4F8FF695L,0x2F4D056CL,9L,0x9C7A75D8L,0x8ED2113AL},{0xD31BC39FL,(-10L),1L,1L,(-1L)},{(-1L),0x3F2DF9F6L,9L,0x8ED2113AL,0x2F4D056CL}},{{0L,(-9L),5L,(-9L),0L},{0xA9C5A221L,(-1L),0xD4EDE40DL,(-7L),0x6B855A03L},{(-3L),4L,0xD31BC39FL,1L,0xC0723F86L},{(-8L),9L,0xF2DC1619L,(-1L),0x6B855A03L},{4L,1L,0L,(-4L),0L}},{{0x6B855A03L,0x6B855A03L,0x3F2DF9F6L,(-9L),0x2F4D056CL},{0x80113FBEL,6L,(-3L),0xEF9A929BL,(-1L)},{(-8L),(-1L),(-9L),0xE58FA5B4L,0x8ED2113AL},{(-7L),6L,4L,4L,0x141ABB78L},{0xA9C5A221L,0x6B855A03L,0xC4371B6FL,0x3F2DF9F6L,(-8L)}}};
        int32_t l_2295 = 0xA7522FCFL;
        uint16_t l_2386[5] = {0xA842L,0xA842L,0xA842L,0xA842L,0xA842L};
        uint8_t l_2387 = 0xC5L;
        uint8_t l_2566[3][1];
        int16_t l_2600 = 0x9347L;
        uint16_t l_2619[2];
        int i, j, k;
        for (i = 0; i < 2; i++)
            l_2291[i] = 0x4E538020L;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 1; j++)
                l_2566[i][j] = 1UL;
        }
        for (i = 0; i < 2; i++)
            l_2619[i] = 65535UL;
        l_2296 = (l_2266[2] = (l_2295 = (((safe_sub_func_uint32_t_u_u((!(safe_sub_func_int16_t_s_s((g_543[1] = (safe_add_func_int32_t_s_s((safe_rshift_func_uint8_t_u_u(0x89L, 6)), ((safe_mod_func_int16_t_s_s((g_172[8] >= 0x22C8L), (g_3261 = l_5[5][1]))) || (l_2279 | (((safe_mod_func_uint32_t_u_u((~(l_2293[5][4][4] = (safe_sub_func_int32_t_s_s(((g_3261 = (safe_lshift_func_uint16_t_u_s(((~l_2266[4]) < (((l_2291[0] = (0x405BL < (((l_2290 = (safe_add_func_uint16_t_u_u((l_3702 = (l_5[1][6] == 0x41L)), l_2841))) | l_2266[3]) >= g_2177[1][3][4]))) ^ 0x136C721FL) | l_2841)), 2))) > l_2292), g_2710)))), l_2266[1])) ^ 0xBD41L) | 0xAFB6L)))))), l_2294))), l_5[4][0])) >= 1L) <= l_2279)));
        for (l_3667 = 2; (l_3667 >= 0); l_3667 -= 1)
        {
            uint32_t l_2314 = 0xBB7DC9F1L;
            int32_t l_2326 = 0x3AB3E32BL;
            int8_t l_2328[1];
            int i;
            for (i = 0; i < 1; i++)
                l_2328[i] = 0L;
            for (g_1524 = 0; (g_1524 <= 2); g_1524 += 1)
            {
                int16_t l_2315 = 0xC65AL;
                uint16_t l_2327 = 65533UL;
                uint8_t l_2343[5] = {3UL,3UL,3UL,3UL,3UL};
                int i;
                for (l_2295 = 0; (l_2295 <= 2); l_2295 += 1)
                {
                    int i, j, k;
                    l_2294 = (((safe_lshift_func_uint16_t_u_s((l_3702 = (~(g_1460 = (safe_add_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u(((safe_add_func_uint32_t_u_u(((((safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((safe_add_func_uint16_t_u_u(((((((safe_sub_func_int16_t_s_s((g_949[l_2295][(l_2295 + 3)][(l_3667 + 5)] & g_949[l_2295][(l_3667 + 4)][(l_3667 + 2)]), l_2314)) == ((((g_172[4] = (g_949[l_2295][(l_2295 + 3)][(l_3667 + 5)] ^ (l_2315 == (safe_lshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(0L, 9)), 13))))) | ((safe_sub_func_uint32_t_u_u(((((safe_rshift_func_uint16_t_u_s(g_949[l_2295][(l_3667 + 4)][(l_3667 + 2)], ((safe_rshift_func_uint16_t_u_s((0x65F9L > 0x8304L), 8)) & 6L))) & 0UL) && 0L) != l_5[1][6]), l_3873)) <= 0UL)) & (-2L)) != g_949[l_2295][(l_3667 + 4)][(l_3667 + 2)])) & l_3210) & l_2291[0]) ^ 1UL) > 0x97A6L), l_3702)), l_2326)), g_949[l_2295][(l_3667 + 4)][(l_3667 + 2)])) == l_2327) || g_2177[2][1][9]) && g_3261), (-4L))) >= 0x5E9A852FL), l_2328[0])) == l_3667), l_2314))))), l_3240[4])) >= 4294967286UL) && 0x397E8B8CL);
                    for (g_2710 = 20; (g_2710 != 28); g_2710++)
                    {
                        int16_t l_2333 = 0x031BL;
                        l_2291[1] = 1L;
                        if (l_2291[0])
                            break;
                        l_2294 = (safe_mod_func_uint32_t_u_u((5L || (l_2326 = (((l_2333 < ((((l_2292 = ((((-6L) == ((l_3683 = (safe_add_func_int32_t_s_s((0L <= (l_3683 && (safe_unary_minus_func_int8_t_s((((((((safe_add_func_uint16_t_u_u((1UL >= (safe_add_func_int8_t_s_s(0x1DL, (safe_add_func_uint32_t_u_u(((g_949[l_2295][(l_3667 + 4)][(l_3667 + 2)] > 0xC1A8C29BL) >= l_2295), l_2328[0]))))), 8UL)) == l_2294) < l_2841) == g_1129) & l_2343[4]) && l_2315) <= l_2292))))), g_866[7][5]))) & 1UL)) | l_2327) & l_3702)) & l_3702) != l_2333) || l_2333)) & l_2294) && g_949[0][6][3]))), 6L));
                    }
                    l_2294 = g_1524;
                }
                if (g_813[1][0])
                    continue;
                l_2294 = (safe_rshift_func_int16_t_s_u(((l_2315 & (safe_lshift_func_uint16_t_u_u((((l_2326 = (g_1524 ^ (l_3683 = (safe_add_func_uint8_t_u_u((((((0xE5L >= (((((l_3026 = (safe_mod_func_int8_t_s_s((l_2465 = (l_3874[2] || 4UL)), g_866[4][0]))) && 0xB2182F1EL) && (l_5[1][6] ^ (safe_lshift_func_uint8_t_u_s(((safe_add_func_uint16_t_u_u(((+l_2292) != l_2292), g_543[1])) && (-1L)), 7)))) < 0xB49FL) > 0x7963L)) >= l_2314) >= 2L) >= l_2291[1]) && (-1L)), g_1129))))) | l_2327) < g_813[5][0]), l_2292))) < l_2314), 12));
            }
            return l_2292;
        }
        if (((((safe_lshift_func_int16_t_s_u(((((safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s((l_3017 & (((safe_sub_func_uint8_t_u_u(((l_2841 < (((safe_add_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(0xB2C7L, (((safe_sub_func_uint8_t_u_u(((safe_unary_minus_func_uint16_t_u((l_2293[8][3][1] = 0x0192L))) || (l_2294 = (((-1L) < g_543[1]) || (l_2266[3] = (safe_add_func_int16_t_s_s((safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(l_2293[5][1][3], (+(((g_3261 = (safe_rshift_func_uint16_t_u_s(((g_2177[1][3][2] >= (safe_mod_func_int8_t_s_s(l_3874[4], l_2292))) != 5L), 0))) < l_2296) != l_3240[2])))), 8L)), g_2177[3][1][9])))))), l_5[1][6])) || l_2295) == l_2291[0]))), l_2291[0])), g_359[9][0])) & l_2386[4]) < 1UL)) | l_2295), 0x6BL)) != 0UL) >= l_5[1][6])), g_949[0][6][1])), 0x5BL)) || g_866[4][0]) < g_866[6][2]) || l_2266[3]), l_2387)) > 0xCA700566L) >= g_813[1][0]) || g_3261))
        {
            uint8_t l_2432 = 0x5EL;
            int8_t l_2575 = 0L;
            int32_t l_2584 = 0x0CC4751DL;
            int32_t l_2585[3];
            int8_t l_2620 = 0x0FL;
            int i;
            for (i = 0; i < 3; i++)
                l_2585[i] = 0xAFFA580CL;
            for (l_2279 = 0; (l_2279 == 40); ++l_2279)
            {
                uint16_t l_2390 = 0x77A9L;
                uint32_t l_2419 = 1UL;
                int32_t l_2421 = 0x4F3857AAL;
                uint32_t l_2422 = 0x8A7A8A37L;
                int32_t l_2431 = (-10L);
                int8_t l_2475 = 0x84L;
                l_2390 = (l_2294 = l_2841);
                l_2422 = (((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u(((0x64L > ((~(safe_sub_func_uint32_t_u_u((safe_add_func_int32_t_s_s(g_1129, ((safe_sub_func_int16_t_s_s((l_2296 = (safe_lshift_func_uint8_t_u_s((l_2841 < 0xD1A6L), 3))), (g_543[1] = l_2293[5][4][4]))) == (l_2421 = (((((((safe_lshift_func_uint8_t_u_u(l_2408[3][0], (safe_rshift_func_uint16_t_u_u((0x71C3L & (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_uint16_t_u((l_2419 = (safe_lshift_func_int8_t_s_s(((l_2292 = (safe_rshift_func_int8_t_s_s((l_3240[0] && l_2418[5][4]), 5))) == l_2390), 2))))), l_3667))), 2)))) <= 0L) || l_2279) | l_2292) && 4L) != g_949[0][6][1]) ^ l_2390))))), (-3L)))) == 0x9FC9L)) && 0x36A7L), l_2386[4])), 8)) != l_2465) <= 0x9B065C80L);
                l_2293[5][4][4] = (((((((safe_lshift_func_int8_t_s_u((((((((((l_2292 == l_2293[5][4][4]) ^ (((g_3261 = 0xDFFFL) | (l_3534 = 0x34B8L)) && (safe_lshift_func_int16_t_s_s((((safe_sub_func_int32_t_s_s((l_2294 = ((l_2421 = 0UL) | ((((l_2291[0] > (safe_sub_func_uint8_t_u_u(l_2431, (l_2295 = l_2432)))) < 0x06L) != g_949[0][6][1]) && l_2431))), 0x134D74CCL)) <= (-10L)) < g_3261), 7)))) > 0x9248DD31L) == g_1524) == 0UL) < l_2292) == l_2408[3][0]) <= 0x7CL) | l_2431), l_5[1][6])) && 0x07L) | g_866[4][0]) & 0xE8L) <= g_866[7][7]) < g_813[1][0]) != l_2432);
                for (l_2432 = 0; (l_2432 <= 3); l_2432 += 1)
                {
                    uint32_t l_2437 = 8UL;
                    int32_t l_2466 = 0x1A5DEB5BL;
                    uint32_t l_2474[3][4][7] = {{{18446744073709551611UL,18446744073709551609UL,0xDE198DD4L,0UL,0UL,0UL,0xDE198DD4L},{0x582432FAL,0x582432FAL,18446744073709551615UL,0x20D3A748L,1UL,0x5B92F6A6L,1UL},{0x3B7A71C4L,0xBB8986F1L,0xFCA41817L,0xC54627FCL,0xC54627FCL,0xFCA41817L,0xBB8986F1L},{1UL,18446744073709551615UL,0x582432FAL,1UL,1UL,0x688D7EE0L,0x20D3A748L}},{{0xFCA41817L,18446744073709551611UL,0UL,0xBB8986F1L,0UL,18446744073709551611UL,0xFCA41817L},{0x20D3A748L,0x688D7EE0L,1UL,1UL,0x582432FAL,18446744073709551615UL,1UL},{0xBB8986F1L,0xFCA41817L,0xC54627FCL,0xC54627FCL,0xFCA41817L,0xBB8986F1L,0x3B7A71C4L},{1UL,0x5B92F6A6L,1UL,0x20D3A748L,18446744073709551615UL,0x582432FAL,0x582432FAL}},{{0xDE198DD4L,0UL,0UL,0UL,0xDE198DD4L,18446744073709551615UL,0x3B7A71C4L},{1UL,1UL,18446744073709551615UL,18446744073709551615UL,0x5B92F6A6L,0x20D3A748L,0x5B92F6A6L},{0xBB8986F1L,1UL,1UL,0xBB8986F1L,18446744073709551611UL,18446744073709551609UL,0xDE198DD4L},{1UL,18446744073709551615UL,1UL,0x582432FAL,18446744073709551608UL,18446744073709551608UL,0x582432FAL}}};
                    int i, j, k;
                    l_2296 = (safe_mod_func_int8_t_s_s(((((g_866[(l_2432 + 4)][(l_2432 + 1)] && l_3874[(l_2432 + 5)]) > (l_3667 < 0L)) && ((safe_sub_func_int32_t_s_s((0xE897L >= l_2437), (0UL ^ 0x39L))) <= (safe_add_func_uint16_t_u_u((l_2841 < l_2841), 0x403CL)))) & 0x0DF0L), l_2386[4]));
                    l_2296 = ((g_813[5][0] = ((safe_lshift_func_uint16_t_u_s(g_2710, 5)) && 0x9FL)) <= (((safe_add_func_int32_t_s_s((safe_sub_func_uint8_t_u_u(g_172[5], (safe_rshift_func_uint16_t_u_u((((l_2292 = (l_3026 && (safe_rshift_func_int8_t_s_s((((safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(((safe_sub_func_int32_t_s_s(l_2292, ((((safe_sub_func_uint32_t_u_u((~l_3534), (l_2294 = (l_2432 < l_3874[(l_2432 + 5)])))) && l_3026) || l_2296) || g_866[(l_2432 + 4)][(l_2432 + 1)]))) == l_2465), g_543[1])), l_2432)), 3)), 5)) != g_949[0][6][4]), l_2292)) > l_2421) < g_1460), l_3873)))) > l_2296) >= 0xC1L), 9)))), l_2293[5][4][4])) > l_2437) || 0x1B16L));
                    if (g_359[9][0])
                        break;
                    for (g_3261 = 0; (g_3261 <= 3); g_3261 += 1)
                    {
                        int32_t l_2473 = (-1L);
                        int i, j, k;
                        l_2466 = 0x839C60E3L;
                        l_3262 = (((g_2177[(g_3261 + 2)][l_2432][(g_3261 + 5)] && (((safe_rshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u(g_2177[(l_2432 + 1)][g_3261][(l_2432 + 5)], 14)), (safe_mod_func_uint16_t_u_u(l_3667, l_3210)))) <= ((l_2473 = (l_2294 = l_2390)) != (l_2296 = (0x43DA57DBL | l_3017)))) < (g_1460 < l_2474[0][1][4]))) || g_543[2]) || l_2475);
                    }
                }
            }
            for (l_3873 = (-19); (l_3873 < (-22)); l_3873 = safe_sub_func_uint16_t_u_u(l_3873, 7))
            {
                uint8_t l_2479 = 1UL;
                int8_t l_2495 = 0xB0L;
                int32_t l_2513 = 0xA6921076L;
                int32_t l_2547 = 0x6B1B6203L;
                uint8_t l_2563[7] = {0xB3L,0xB3L,0x5EL,0xB3L,0xB3L,0x5EL,0xB3L};
                int i;
                if (l_2479)
                {
                    int16_t l_2490 = 0L;
                    int32_t l_2504 = (-8L);
                    for (l_3702 = (-1); (l_3702 == 46); l_3702 = safe_add_func_int32_t_s_s(l_3702, 5))
                    {
                        int16_t l_2482 = 0xC29FL;
                        l_2295 = (l_2482 >= (safe_add_func_uint16_t_u_u((l_2294 == l_2292), 0x0D89L)));
                        l_2293[5][4][4] = g_1524;
                    }
                    l_2295 = ((l_2296 = ((((l_3683 = ((+g_1129) & ((safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u(l_2292, (((g_3261 = l_5[0][0]) | ((l_3667 <= 0x4CL) || ((l_2490 || (safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(l_2495, l_3683)), 3))) >= g_359[6][6]))) ^ 2UL))), l_2495)) ^ 0L))) < 0x23L) & l_2495) && 0x9BA8983EL)) >= 65527UL);
                    l_2408[3][0] = (((l_3026 = (l_2292 >= g_949[0][5][6])) == ((safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s((g_2177[4][1][4] = ((g_172[7] == ((l_2266[0] = (safe_add_func_int32_t_s_s(((l_2504 = l_2495) >= ((safe_mod_func_uint8_t_u_u((l_2490 | ((l_2296 = ((0L || (l_2513 = ((l_2490 ^ (safe_add_func_int32_t_s_s((safe_add_func_int8_t_s_s(1L, l_3702)), l_2490))) | l_2432))) >= l_3667)) < 65535UL)), l_3262)) && 252UL)), l_3702))) <= l_3534)) | (-10L))), 6)), l_2479)) && (-1L))) ^ (-8L));
                    l_2291[0] = l_3667;
                }
                else
                {
                    uint32_t l_2525 = 0xDBD6AC3EL;
                    int32_t l_2528 = 0xF6619A70L;
                    for (l_3017 = 0; (l_3017 <= 5); l_3017 += 1)
                    {
                        int32_t l_2527 = 0L;
                        int i, j;
                        l_2294 = ((safe_rshift_func_uint8_t_u_u((l_2528 = ((l_5[l_3017][l_3017] = (safe_unary_minus_func_uint16_t_u(0x2292L))) ^ (l_2293[5][4][4] = (((-7L) < ((safe_lshift_func_uint8_t_u_u((0xE68EF4FBL < ((safe_add_func_int8_t_s_s((l_2291[0] = ((safe_add_func_uint32_t_u_u((l_3667 != (safe_add_func_int16_t_s_s((((65531UL > ((l_2525 || l_2465) & g_949[1][7][7])) || (((l_2526 = ((l_2525 > g_172[4]) & 0x1B0088F1L)) ^ l_2479) & l_2479)) && 0x82L), 0x2333L))), g_2710)) || g_1460)), l_2292)) ^ 4294967295UL)), 1)) == 5L)) == l_2527)))), 0)) >= 255UL);
                        l_2294 = (safe_lshift_func_uint16_t_u_u(1UL, (safe_lshift_func_uint16_t_u_s(((((((safe_rshift_func_uint8_t_u_s(((((l_3683 = l_2432) <= (0UL ^ (safe_mod_func_int8_t_s_s(((safe_sub_func_int32_t_s_s(l_2295, g_543[2])) ^ ((l_2418[0][3] <= l_2292) != (safe_sub_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(((g_2177[3][1][9] = l_2386[4]) <= (safe_mod_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(g_543[1], l_2465)), l_2513))), l_2528)), l_2432)))), l_2387)))) <= 0x476CB2BEL) <= l_5[l_3017][(l_3017 + 1)]), 5)) == l_2547) ^ 0x6F1AL) & l_3210) | 0x2AL) | g_172[2]), l_3262))));
                        l_2294 = (l_2296 = ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u(((0xFFL <= 0x8EL) && (g_813[0][0] <= (-1L))), 0)), 0x2FL)) | (0x30L & (((safe_add_func_int16_t_s_s((0x0450E2D6L <= l_2432), (g_2710 < g_949[0][6][1]))) || 0x6291L) > 0x03C1L))));
                        l_2527 = (l_2290 = 0x5A0AF0AFL);
                    }
                    l_3262 = 1L;
                    if ((safe_lshift_func_int8_t_s_s((+((safe_rshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s((l_2266[3] < l_2563[0]), (safe_mod_func_uint16_t_u_u(l_2566[2][0], ((safe_mod_func_uint32_t_u_u(0xB86569AAL, (safe_sub_func_int8_t_s_s((l_2525 & (safe_sub_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(l_2575, l_3262)), ((l_2296 = l_5[1][6]) && ((((l_2547 = (safe_rshift_func_uint8_t_u_s((((g_3261 = g_2710) == l_2547) || (-1L)), 5))) && 0x8CF5425BL) > l_2465) ^ l_2841))))), 0x41L)))) & 0xFF38L))))) != l_2563[0]), 1UL)), l_2575)) && 9UL)), 1)))
                    {
                        l_2585[1] = (+(0x39E1L | (safe_lshift_func_int16_t_s_s((g_866[7][8] = ((65535UL & 0x0AC2L) <= 0xB3EAL)), ((g_1524 = g_1524) >= (l_2295 = (g_543[2] = (((l_2575 < (((safe_sub_func_uint16_t_u_u(l_2525, (g_2177[3][1][9] != (l_2584 = (l_2292 && g_1129))))) & 0xD04E619AL) <= l_3534)) == g_543[1]) >= l_2575))))))));
                        l_2296 = g_2710;
                    }
                    else
                    {
                        uint32_t l_2599 = 0x7CDA3D77L;
                        int32_t l_2616 = (-4L);
                        l_3262 = ((1L == l_2525) != (safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(((-3L) != ((safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((((((((l_2386[4] >= (g_813[1][0] < (l_3262 = (((0xFFL | g_949[0][6][1]) == (((safe_add_func_uint32_t_u_u((l_2563[0] || l_2292), l_2692)) >= l_2585[2]) || l_2525)) < 0x66L)))) ^ l_2599) || l_3017) >= l_2600) >= l_2528) != 6L) <= l_3534) >= l_2599), l_2528)), 0x61L)) ^ g_949[2][8][6])), g_543[1])), (-4L))));
                        l_2585[2] = ((l_2601 < (safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((l_2616 = ((safe_lshift_func_uint16_t_u_s(l_2266[0], 6)) ^ ((+(l_2547 = g_949[0][6][1])) && (l_2584 != (safe_sub_func_uint16_t_u_u(((l_2408[2][4] = 6L) ^ (safe_mod_func_int32_t_s_s(l_2292, g_172[4]))), (+((-1L) && (safe_lshift_func_uint8_t_u_u(l_3262, l_3017)))))))))), 0)), 11))) <= l_2387);
                        l_2294 = g_2710;
                    }
                    l_2294 = (safe_mod_func_uint32_t_u_u(l_2619[1], ((((l_3262 < l_3026) || l_2620) == ((((safe_sub_func_int16_t_s_s(((g_2177[3][1][9] = l_2547) | (l_2418[2][1] < (+(0xC4FEL ^ (safe_rshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s((((l_2528 > (-1L)) | (-1L)) > l_2292), g_359[4][0])), 2UL)), 7)))))), l_3873)) > l_2266[4]) <= 2UL) < l_2525)) ^ (-6L))));
                }
            }
            l_2290 = (safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u(((safe_mod_func_uint32_t_u_u((((l_2408[3][0] = l_3262) <= ((g_359[9][0] & (safe_rshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((g_359[6][6] && (safe_mod_func_uint8_t_u_u(((((safe_rshift_func_uint8_t_u_s(((safe_sub_func_int8_t_s_s((g_1524 & (g_1460 = (safe_sub_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((((~0x448CL) ^ (safe_lshift_func_int8_t_s_s(((g_172[4] = l_3874[7]) | ((safe_lshift_func_uint16_t_u_s(0xEFAAL, 7)) < 6UL)), 7))) < (1L > g_813[1][0])), g_3261)), l_2293[5][4][4])))), 255UL)) ^ g_2177[3][1][9]), l_2294)) || 1UL) != g_1524) < l_2600), (-1L)))), l_2294)), 6))) | l_3017)) < 4294967295UL), l_2465)) || l_2620), 1)), 7));
            for (g_3261 = 0; g_3261 < 3; g_3261 += 1)
            {
                for (l_2296 = 0; l_2296 < 9; l_2296 += 1)
                {
                    for (l_3683 = 0; l_3683 < 9; l_3683 += 1)
                    {
                        g_949[g_3261][l_2296][l_3683] = 0L;
                    }
                }
            }
        }
        else
        {
            int16_t l_2673 = (-1L);
            int32_t l_2704 = (-1L);
            if ((safe_lshift_func_uint16_t_u_s(0xCDD4L, l_5[5][4])))
            {
                int8_t l_2662[2];
                int32_t l_2672 = 0x458B65B5L;
                int32_t l_2691[7][4] = {{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)},{0xA7CC0C33L,(-1L),0xA7CC0C33L,0xA7CC0C33L},{(-1L),(-1L),0xB115895CL,(-1L)},{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)},{0xA7CC0C33L,(-1L),0xA7CC0C33L,0xA7CC0C33L},{(-1L),(-1L),0xB115895CL,(-1L)},{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)}};
                uint8_t l_2701 = 0x03L;
                int i, j;
                for (i = 0; i < 2; i++)
                    l_2662[i] = (-6L);
                l_2296 = (((l_2290 = (l_2295 = (l_3667 = ((l_2296 < ((safe_add_func_int32_t_s_s(g_949[0][6][1], ((+((safe_lshift_func_uint16_t_u_u((((l_3667 = ((l_2294 = ((l_2662[0] < (((((safe_lshift_func_int16_t_s_u(((safe_add_func_int16_t_s_s((((safe_lshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u(65535UL, (~(((l_2662[1] >= l_3017) >= 9L) && g_2177[5][0][0])))), 5)) >= g_359[6][0]) >= l_2619[1]), l_2662[0])) ^ 0x2BBDAAFAL), g_813[5][0])) ^ l_2672) | 250UL) & (-8L)) != l_3683)) == g_949[2][0][1])) ^ 0x0227889AL)) <= (-9L)) >= l_2673), g_2177[4][1][5])) && l_2296)) < 0x41L))) & g_813[1][0])) == 0x5FL)))) != g_543[2]) > l_2841);
                for (l_2292 = 0; (l_2292 <= 6); l_2292 += 1)
                {
                    l_2674 = 0L;
                    for (l_2465 = 0; (l_2465 <= 6); l_2465 += 1)
                    {
                        int32_t l_2677[7][8][4] = {{{1L,0x41A054B2L,0L,0x2D0DBF52L},{0x0CF1A441L,0L,(-5L),(-1L)},{(-4L),0L,0x731C9F43L,0x01A3D290L},{0L,(-10L),0x0D46BF51L,0x0D46BF51L},{3L,3L,0x4CB0245BL,0x60E2D043L},{0x0D46BF51L,0L,0xCE5C71E8L,0xD450BA5CL},{1L,0xBBB0E83CL,(-1L),0xCE5C71E8L},{0xBC9F03A0L,0xBBB0E83CL,(-10L),0xD450BA5CL}},{{0xBBB0E83CL,0L,(-1L),0x60E2D043L},{1L,3L,0xBC9F03A0L,0x0D46BF51L},{0x731C9F43L,(-10L),(-9L),0x01A3D290L},{0x4CB0245BL,0L,0x7AE1F11BL,(-1L)},{0xB8ACCB37L,0L,1L,0x2D0DBF52L},{0x60E2D043L,0x41A054B2L,0x830FB6EAL,(-4L)},{0L,(-1L),0L,2L},{(-9L),0L,3L,(-10L)}},{{0L,0x2D0DBF52L,0L,0L},{0x41A054B2L,0x8FB9928BL,0L,0x0CF1A441L},{0L,0x731C9F43L,3L,0x7AE1F11BL},{(-9L),0L,0L,(-3L)},{0L,(-3L),0x830FB6EAL,0L},{0x60E2D043L,(-9L),1L,0L},{0xB8ACCB37L,(-1L),0x7AE1F11BL,0xA2CE5981L},{0x4CB0245BL,0xB8ACCB37L,(-9L),(-1L)}},{{0x731C9F43L,0xBC9F03A0L,0xBC9F03A0L,0x731C9F43L},{1L,0xD450BA5CL,(-1L),(-9L)},{0xBBB0E83CL,0x0CF1A441L,(-10L),1L},{0xBC9F03A0L,0L,(-1L),1L},{1L,0x0CF1A441L,0xCE5C71E8L,(-9L)},{0x0D46BF51L,0xD450BA5CL,0x4CB0245BL,0x731C9F43L},{3L,0xBC9F03A0L,0x0D46BF51L,(-1L)},{0L,0xB8ACCB37L,0x731C9F43L,0xA2CE5981L}},{{(-4L),(-1L),(-5L),0L},{0x0CF1A441L,2L,0L,(-1L)},{0x7AE1F11BL,0x2D0DBF52L,0xCE5C71E8L,0x2D0DBF52L},{0x8FB9928BL,0xA2CE5981L,0x2D0DBF52L,1L},{1L,1L,(-9L),0x41A054B2L},{0x0D46BF51L,(-3L),0L,(-4L)},{0x0D46BF51L,(-5L),(-9L),0L},{1L,(-4L),0x2D0DBF52L,0xB8ACCB37L}},{{0x8FB9928BL,(-9L),0xCE5C71E8L,0x0CF1A441L},{0x7AE1F11BL,(-1L),0L,(-5L)},{0x41A054B2L,0L,0x01A3D290L,0x8FB9928BL},{0x0CF1A441L,0L,1L,0xBC9F03A0L},{0xA2CE5981L,0L,(-10L),(-10L)},{0x4CB0245BL,0x4CB0245BL,9L,1L},{(-10L),0L,1L,0L},{0L,0L,0x0D46BF51L,1L}},{{0x731C9F43L,0L,0L,0L},{0L,0L,1L,1L},{0xD450BA5CL,0x4CB0245BL,0x731C9F43L,(-10L)},{1L,0L,2L,0xBC9F03A0L},{9L,0L,1L,0x8FB9928BL},{0x830FB6EAL,0L,0xD450BA5CL,(-5L)},{1L,(-1L),3L,0x0CF1A441L},{0xBBB0E83CL,(-9L),0xBBB0E83CL,0xB8ACCB37L}}};
                        int i, j, k;
                        l_2677[4][2][3] = (safe_unary_minus_func_int16_t_s((safe_unary_minus_func_int8_t_s((g_359[(l_2292 + 1)][l_2465] > l_2673)))));
                    }
                }
                if (((l_2295 = (((l_2291[1] = g_172[1]) && (safe_sub_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_u((((g_1460 = (g_2177[0][0][9] = ((l_3667 > l_3262) & (((safe_mod_func_int32_t_s_s((((((((((safe_lshift_func_int8_t_s_u((l_2465 = (((safe_add_func_uint8_t_u_u(l_2662[1], ((-1L) <= l_2673))) != ((((safe_sub_func_int32_t_s_s((!g_1524), ((l_2691[0][0] = (l_2408[3][0] = ((0xB248A39EL & ((g_1524 = (-2L)) < l_2294)) >= l_2662[1]))) && l_2673))) && g_866[4][0]) && l_2691[0][2]) > l_2673)) & 0L)), l_2292)) <= g_866[4][0]) == l_2673) | l_2292) && g_2177[3][3][8]) <= l_2692) ^ l_2673) != l_2292) ^ 0xECF0AEBAL), 0xCF415C16L)) > g_543[1]) == l_2673)))) < l_2291[0]) & l_2266[3]), l_2465)) && (-4L)), g_359[1][6]))) == 0xBF9AL)) > 0xEE49L))
                {
                    int32_t l_2700 = (-6L);
                    l_3262 = 1L;
                    l_3262 = (((0xB2637E3CL != (~((safe_add_func_int8_t_s_s((l_2691[0][0] = l_2296), (l_2704 = (g_1460 = (((-3L) ^ (l_2701 = (l_2700 = (safe_mod_func_uint8_t_u_u(0xD2L, 5UL))))) ^ (g_172[1] == ((safe_sub_func_int16_t_s_s(((g_543[1] = (l_2704 & ((!(safe_mod_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(l_2601, 0x8C7F0823L)) == g_3261), l_2672))) >= 0UL))) > 0xA047L), l_2672)) >= g_2710))))))) && l_2704))) <= l_2673) > 0L);
                    l_2704 = (249UL & ((safe_lshift_func_int16_t_s_u(g_2710, 6)) && 1UL));
                }
                else
                {
                    int32_t l_2715 = 0x20D70AE1L;
                    int32_t l_2723 = 0x493688ADL;
                    for (l_3534 = 0; (l_3534 > 25); l_3534++)
                    {
                        uint16_t l_2724 = 65535UL;
                        l_2704 = ((((((l_2601 = l_2715) & ((4UL == l_2408[3][2]) <= (safe_unary_minus_func_uint32_t_u(((safe_add_func_int8_t_s_s((safe_add_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(g_1129, 14)), ((l_2723 = 0xEEF6D83EL) > l_3017))), 0x16L)) && l_3026))))) >= ((l_2691[3][1] = 65535UL) > l_2724)) && g_359[9][6]) || l_2662[0]) > l_3534);
                        return l_3873;
                    }
                    l_2295 = (l_2691[0][0] = ((l_2293[5][4][4] = (l_5[4][2] | ((l_3262 ^ (((0x3248F897L < ((safe_unary_minus_func_int16_t_s(0xA585L)) ^ (l_3683 > l_3017))) < ((0L && (((-10L) < (0x522993A5L < 0x6C6B07C7L)) == l_2408[3][0])) || l_3210)) > l_2296)) > 0x637DBBF8L))) && l_2841));
                    l_3262 = (safe_unary_minus_func_int8_t_s((l_3683 = ((safe_rshift_func_uint16_t_u_u(1UL, 7)) < (l_3667 || l_2841)))));
                    for (l_3667 = 0; (l_3667 <= (-25)); l_3667--)
                    {
                        l_3262 = l_3534;
                        return g_949[0][6][1];
                    }
                }
            }
            else
            {
                l_2408[0][5] = l_2619[1];
                l_3262 = (((((((safe_rshift_func_uint8_t_u_s((g_2177[3][1][9] = ((safe_add_func_uint8_t_u_u((safe_add_func_int32_t_s_s(l_2600, (l_2408[0][0] = (safe_add_func_uint8_t_u_u((l_2292 = (l_2294 < (g_172[4] != 0xD4L))), 1L))))), ((l_2673 == l_3873) < (g_1129 < l_2619[1])))) < l_3240[1])), 7)) <= l_2692) ^ 0xC9C7L) && 1UL) || l_2292) | g_1129) != l_2673);
            }
        }
        return l_3534;
    }
    else
    {
        uint32_t l_2750 = 0UL;
        int16_t l_2774 = 0x1B44L;
        uint32_t l_2816 = 8UL;
        uint16_t l_2838 = 0x80C3L;
        uint32_t l_2839[4][5][4] = {{{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL}},{{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL}},{{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL}},{{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL}}};
        int32_t l_2840 = (-1L);
        uint32_t l_2842 = 4294967293UL;
        uint32_t l_2858 = 6UL;
        int32_t l_2886[5] = {0x58E56A96L,0x58E56A96L,0x58E56A96L,0x58E56A96L,0x58E56A96L};
        uint8_t l_2918 = 251UL;
        uint32_t l_3026 = 0xD83BFFE3L;
        uint16_t l_3036[9][4][6] = {{{0x87ECL,6UL,0x87ECL,7UL,0UL,0x77DEL},{0x87ECL,0xE62AL,65535UL,0x2B5DL,65528UL,1UL},{0x707AL,65535UL,0x663BL,0x95CBL,0x87ECL,0x3B74L},{1UL,0xF5FBL,0xAEF8L,0x3B74L,65535UL,65534UL}},{{1UL,0x7B76L,0x0A26L,0x95CBL,65535UL,65528UL},{0xAEF8L,2UL,1UL,0x95CBL,0xFE06L,0UL},{1UL,0x7098L,0x6C25L,0x3B74L,0x663BL,0x69E2L},{1UL,7UL,0x2A82L,0x95CBL,0xD05AL,0x7629L}},{{0xAEF8L,1UL,0xB2E4L,0x95CBL,0x707AL,0x95CBL},{1UL,0x77DEL,1UL,0x3B74L,0xB77FL,65527UL},{1UL,0x2B5DL,0xBEA0L,0x95CBL,0x8C94L,0xCCFEL},{0xAEF8L,9UL,0xBCF5L,0x95CBL,0x87ECL,0x3B74L}},{{1UL,0xF5FBL,0xAEF8L,0x3B74L,65535UL,65534UL},{1UL,0x7B76L,0x0A26L,0x95CBL,65535UL,65528UL},{0xAEF8L,2UL,1UL,0x95CBL,0xFE06L,0UL},{1UL,0x7098L,0x6C25L,0x3B74L,0x663BL,0x69E2L}},{{1UL,7UL,0x2A82L,0x95CBL,0xD05AL,0x7629L},{0xAEF8L,1UL,0xB2E4L,0x95CBL,0x707AL,0x95CBL},{1UL,0x77DEL,1UL,0x3B74L,0xB77FL,65527UL},{1UL,0x2B5DL,0xBEA0L,0x95CBL,0x8C94L,0xCCFEL}},{{0xAEF8L,9UL,0xBCF5L,0x95CBL,0x87ECL,0x3B74L},{1UL,0xF5FBL,0xAEF8L,0x3B74L,65535UL,65534UL},{1UL,0x7B76L,0x0A26L,0x95CBL,65535UL,65528UL},{0xAEF8L,2UL,1UL,0x95CBL,0xFE06L,0UL}},{{1UL,0x7098L,0x6C25L,0x3B74L,0x663BL,0x69E2L},{1UL,7UL,0x2A82L,0x95CBL,0xD05AL,0x7629L},{0xAEF8L,1UL,0xB2E4L,0x95CBL,0x707AL,0x95CBL},{1UL,0x77DEL,1UL,0x3B74L,0xB77FL,65527UL}},{{1UL,0x2B5DL,0xBEA0L,0x95CBL,0x8C94L,0xCCFEL},{0xAEF8L,9UL,0xBCF5L,0x95CBL,0x87ECL,0x3B74L},{1UL,0xF5FBL,0xAEF8L,0x3B74L,65535UL,65534UL},{1UL,0x7B76L,0x0A26L,0x95CBL,65535UL,65528UL}},{{0xAEF8L,2UL,1UL,0x95CBL,0xFE06L,0UL},{1UL,0x7098L,0x6C25L,0x3B74L,0x663BL,0x69E2L},{1UL,0x3B74L,0UL,6UL,0x2A82L,0x0DFFL},{0x2848L,0xCCFEL,1UL,6UL,0xAEF8L,6UL}}};
        uint32_t l_3109 = 0x4E3D05E3L;
        uint8_t l_3153 = 0xD3L;
        int i, j, k;
        for (l_2601 = 0; (l_2601 <= 5); l_2601 += 1)
        {
            int16_t l_2741[4] = {(-1L),(-1L),(-1L),(-1L)};
            int8_t l_2767 = 0L;
            int32_t l_2786 = (-1L);
            uint8_t l_2805 = 0x6BL;
            int i;
            l_2266[3] = (l_2741[1] <= (-1L));
            if (g_2710)
                break;
            if ((((l_3534 = ((safe_lshift_func_uint16_t_u_u(((((safe_add_func_int16_t_s_s(g_359[9][0], l_2741[3])) > ((((((safe_mod_func_uint16_t_u_u(((g_866[7][9] = ((((0x6E85L <= (0x42L | l_2741[3])) <= 0x5A05L) || g_172[4]) >= ((safe_add_func_uint16_t_u_u(0UL, (((((((((g_359[9][0] == l_2526) & 1L) | g_813[1][0]) || l_3534) >= l_3026) == l_2465) ^ l_3667) | 0x22D5438DL) != g_813[1][0]))) > l_2294))) == 0xDB79L), l_2750)) || g_949[2][3][0]) || 0x4AL) && g_949[0][6][1]) | g_2177[3][1][9]) >= 1L)) >= g_2177[1][2][5]) < 0L), 0)) != 0x4DL)) <= 0xF9F6L) && 0x03L))
            {
                int16_t l_2751 = 0x67D2L;
                return l_2751;
            }
            else
            {
                int8_t l_2775 = 0xEAL;
                if (l_3210)
                    break;
                for (l_2292 = 0; (l_2292 <= 7); l_2292 += 1)
                {
                    int i, j;
                    l_3262 = ((safe_lshift_func_int16_t_s_s(((safe_add_func_int32_t_s_s((l_3262 = ((l_2408[2][1] = ((((((safe_lshift_func_uint8_t_u_s((((safe_sub_func_uint32_t_u_u(g_866[l_2292][l_2601], (((((l_2296 = ((safe_mod_func_uint32_t_u_u((safe_unary_minus_func_uint16_t_u(l_5[l_2601][l_2601])), (safe_lshift_func_int16_t_s_u((((safe_mod_func_int32_t_s_s(l_3240[4], ((l_2767 ^ l_2294) ^ 4L))) ^ ((+((safe_mod_func_uint32_t_u_u((safe_add_func_int8_t_s_s((0L == (+(g_359[5][0] = g_866[l_2292][l_2601]))), ((((l_2774 >= l_5[l_2601][l_2601]) != l_2741[1]) >= l_2292) || g_949[0][6][1]))), 0x60FE58BBL)) | l_2741[1])) & l_3874[2])) & g_3261), 5)))) || g_2710)) ^ l_3874[1]) && l_2601) > g_2710) ^ g_1460))) != l_2292) | l_2526), l_3240[4])) >= g_1524) < l_2775) > 0x93B1L) && l_2408[3][0]) >= g_949[0][6][1])) && l_2774)), g_172[8])) && 0L), g_1524)) == l_2841);
                    for (l_2294 = 0; (l_2294 <= 2); l_2294 += 1)
                    {
                        return l_2775;
                    }
                    for (l_2774 = 2; (l_2774 >= 0); l_2774 -= 1)
                    {
                        if (l_3873)
                            break;
                    }
                }
            }
            for (l_3702 = 0; (l_3702 <= 5); l_3702 += 1)
            {
                uint32_t l_2789 = 0UL;
                int i, j;
                if ((safe_rshift_func_uint16_t_u_u(((((safe_sub_func_uint32_t_u_u(0x0CA3AF23L, ((safe_lshift_func_int16_t_s_s((((0xE3A54803L | (g_866[l_2601][(l_3702 + 1)] || (0x65L < (safe_add_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_u((((l_2408[3][0] = (l_2786 = 0xAB10L)) < l_5[l_3702][(l_3702 + 1)]) | l_2741[1]), 8)) | 0xFAL), (((safe_sub_func_uint8_t_u_u(g_2177[3][1][0], l_2292)) <= 3UL) && l_2789)))))) == l_2774) == 4294967294UL), l_3240[4])) ^ l_5[l_3702][(l_3702 + 1)]))) >= l_2290) || l_5[l_3702][(l_3702 + 1)]) == l_2790[4][0]), l_2767)))
                {
                    int32_t l_2804 = 0xA0FDC450L;
                    int i, j;
                    l_3262 = (safe_lshift_func_uint8_t_u_u(((0x9DL || 0L) >= g_172[4]), ((safe_add_func_int8_t_s_s((((safe_lshift_func_int8_t_s_u(0xF2L, ((l_2292 ^ 65535UL) > (!(l_2408[3][0] = (((g_866[l_2601][(l_2601 + 4)] = g_2710) == (safe_rshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_u(((l_2741[0] < (safe_sub_func_uint32_t_u_u((l_3874[2] | 0xC0D2L), l_2789))) & g_172[4]), l_2741[1])), l_2804))) != l_5[l_3702][(l_3702 + 1)])))))) == l_2774) & g_949[0][0][4]), g_1524)) & g_543[1])));
                    if (l_3210)
                        break;
                    return l_2805;
                }
                else
                {
                    return l_2741[1];
                }
            }
        }
        if ((l_3262 = (safe_rshift_func_uint16_t_u_s((l_2408[1][1] = ((4294967295UL && ((safe_mod_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_s(((safe_add_func_int32_t_s_s((safe_add_func_int8_t_s_s((l_2816 != l_2816), (l_3667 = (safe_rshift_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_s(l_2292, 11)) > ((safe_add_func_uint16_t_u_u((+(l_2840 = ((safe_add_func_int16_t_s_s((l_2292 > (safe_lshift_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((l_2841 = (l_3667 | (l_2266[3] = ((safe_mod_func_int32_t_s_s((safe_mod_func_int16_t_s_s(l_2266[3], l_3240[4])), (safe_lshift_func_int16_t_s_u((safe_add_func_int8_t_s_s(((((l_2838 < l_2774) != 0xD9L) || 0UL) != g_543[1]), 0x0DL)), l_2841)))) <= g_949[0][6][1])))) ^ l_2816), l_5[2][3])), g_3261))), l_2839[3][2][0])) && l_3874[3]))), l_2816)) <= 65535UL)) > 6L), l_2816))))), l_3017)) != g_949[0][6][1]), l_2841)) < g_1129), l_2842)) == 0xC5L)) >= 0xB92611BCL)), 4))))
        {
            uint32_t l_2849 = 0x6555F265L;
            int32_t l_2882 = 0x437FFEACL;
            for (l_2290 = 0; (l_2290 < 14); l_2290 = safe_add_func_int8_t_s_s(l_2290, 9))
            {
                uint8_t l_2857[10] = {0x47L,0x47L,5UL,0x47L,0x47L,5UL,0x47L,0x47L,5UL,0x47L};
                int i;
                l_2294 = (safe_sub_func_uint32_t_u_u(((((safe_mod_func_int16_t_s_s(l_2849, l_3026)) >= ((safe_mod_func_int16_t_s_s(((((safe_add_func_uint8_t_u_u((((safe_rshift_func_int8_t_s_s(0xEBL, (g_1460 & (~((l_3874[2] ^ l_2857[0]) | l_3874[8]))))) > l_2292) ^ 0xB3A2L), 1L)) > l_2816) >= 4UL) <= g_2177[3][1][9]), l_2849)) > (-1L))) & l_3240[4]) & 0x305117E2L), l_2849));
                if (l_2858)
                {
                    uint16_t l_2859[9][10][2] = {{{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L},{0x351AL,0x0962L},{0x63E3L,0x6C7BL}},{{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L},{0x2BD3L,0x351AL},{0x0962L,0x63E3L}},{{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L},{0x351AL,0x0962L}},{{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L},{0x2BD3L,0x351AL}},{{0x0962L,0x63E3L},{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L}},{{0x351AL,0x0962L},{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L}},{{0x2BD3L,0x351AL},{0x0962L,0x63E3L},{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL}},{{0x2BD3L,0x2BD3L},{0x351AL,0x0962L},{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L}},{{0x351AL,0x2BD3L},{0x2BD3L,0x351AL},{0x0962L,0x63E3L},{0UL,0xBB6AL},{1UL,0x1D2FL},{0xBB6AL,0x351AL},{0x1AC1L,0x351AL},{0xBB6AL,0x1D2FL},{1UL,0xBB6AL},{0UL,0xE5BAL}}};
                    int i, j, k;
                    l_3262 = (((l_2859[6][7][1] = 0xADBFA8FFL) >= 0x48712C93L) <= (safe_mod_func_uint16_t_u_u(g_1460, 0xF825L)));
                }
                else
                {
                    uint32_t l_2870 = 7UL;
                    int16_t l_2876 = 0x4E7FL;
                    for (l_3210 = (-5); (l_3210 > 9); l_3210 = safe_add_func_uint16_t_u_u(l_3210, 3))
                    {
                        int32_t l_2875 = 0x445A8CCEL;
                        l_2840 = ((safe_lshift_func_int8_t_s_s(l_2839[3][2][0], 7)) == (safe_sub_func_uint8_t_u_u(4UL, 0x27L)));
                        l_2294 = ((l_2857[8] ^ (safe_add_func_uint16_t_u_u(g_949[0][2][8], l_3026))) >= (((((g_1129 = l_2870) > l_3874[0]) < ((safe_sub_func_int8_t_s_s((((((l_2857[6] && (((l_2870 == ((-4L) == (g_359[1][0] = (safe_add_func_uint16_t_u_u((9L & l_2875), l_2838))))) < l_2296) != l_2857[0])) <= l_2408[3][0]) <= (-7L)) < g_543[1]) & 0x6FL), l_2526)) <= 0xF0L)) >= l_3262) < g_1460));
                    }
                    if (l_2876)
                        continue;
                    if (l_2870)
                        continue;
                }
                l_2294 = (l_2526 >= (((((((l_2882 = (safe_lshift_func_int8_t_s_u(((~(safe_mod_func_uint8_t_u_u((l_2750 & l_2842), 255UL))) & l_2601), l_2674))) && 255UL) || (g_1129 & (l_3667 = (!((safe_mod_func_int8_t_s_s((g_866[4][0] & (-1L)), l_2886[3])) ^ 1UL))))) && (-10L)) | 0x2BL) == 0xDDL) & l_2857[6]));
            }
        }
        else
        {
            uint8_t l_2896 = 0x25L;
            int32_t l_2900[1][7][10] = {{{1L,0x51D4F00DL,(-2L),0x72793645L,(-2L),0x51D4F00DL,1L,0x51D4F00DL,(-2L),0x72793645L},{0xD57951F1L,0x72793645L,0xD57951F1L,0x51D4F00DL,9L,0x51D4F00DL,0xD57951F1L,0x72793645L,0xD57951F1L,0x51D4F00DL},{1L,0x72793645L,0L,0x72793645L,1L,0x4FD08915L,1L,0x72793645L,0L,0x72793645L},{9L,0x51D4F00DL,0xD57951F1L,0x72793645L,0xD57951F1L,0x51D4F00DL,9L,0x51D4F00DL,0xD57951F1L,0x72793645L},{(-2L),0x72793645L,(-2L),0x51D4F00DL,1L,0x51D4F00DL,(-2L),0x72793645L,(-2L),0x51D4F00DL},{9L,0x72793645L,2L,0x72793645L,9L,0x4FD08915L,9L,0x72793645L,2L,0x72793645L},{1L,0x51D4F00DL,(-2L),0x72793645L,(-2L),0x51D4F00DL,1L,0x51D4F00DL,(-2L),0x72793645L}}};
            uint8_t l_2943 = 0x66L;
            uint32_t l_2954 = 4294967292UL;
            int16_t l_2978 = 0L;
            int32_t l_3072 = 1L;
            int i, j, k;
            for (l_2838 = (-17); (l_2838 < 7); ++l_2838)
            {
                int16_t l_2889 = 0x56E2L;
                int32_t l_2901 = 3L;
                if ((l_2889 ^ (safe_lshift_func_int16_t_s_u((g_543[0] = 0xB38AL), (safe_mod_func_int16_t_s_s((((safe_mod_func_int32_t_s_s(((0L < (l_2408[3][0] = (l_2896 != l_3874[2]))) <= 0xF7L), (((((g_1524 > ((((((safe_add_func_uint16_t_u_u(((l_2266[0] = (l_2901 = (l_2899 != l_2900[0][1][8]))) != l_2900[0][1][8]), 0x6951L)) >= g_1524) && 1L) ^ g_866[0][4]) && g_813[1][0]) | (-8L))) && (-1L)) > 0x6DEFL) != l_2841) | g_359[9][0]))) < l_2896) && l_2465), l_2889))))))
                {
                    return l_2816;
                }
                else
                {
                    uint32_t l_2908 = 4294967295UL;
                    int16_t l_2945 = (-1L);
                    l_2840 = (safe_rshift_func_uint8_t_u_u((0xFDF2L == ((((safe_rshift_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_u((1UL >= ((g_866[4][0] > 0x7AL) == 9UL)), g_1129)) || (l_2908 == ((3UL & (g_359[9][0] != 0L)) && l_2900[0][1][8]))), l_2292)) == l_2418[3][4]) != 4294967295UL) || l_2899)), g_543[1]));
                    if ((((-5L) > (4294967295UL >= ((((safe_add_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s(0xA94EL, ((l_3017 && g_949[0][6][1]) < ((((((safe_rshift_func_uint16_t_u_u((((((0x4CD1L == (((safe_add_func_int32_t_s_s(l_3262, (l_2908 > (~(g_2177[3][1][9] ^ l_2908))))) >= l_2889) > 0x64F7L)) > l_2841) == g_866[6][0]) != 0L) == l_2839[3][2][0]), 4)) <= l_2900[0][1][8]) <= 0xBEL) ^ g_543[1]) == l_3667) == l_2918)))), l_3667)) ^ 0xDC73L) && l_2292) || l_2908))) <= l_3026))
                    {
                        uint32_t l_2944 = 0x023CA64AL;
                        if (l_3874[2])
                            break;
                        l_2296 = ((safe_lshift_func_int16_t_s_u((safe_mod_func_int16_t_s_s((safe_sub_func_int32_t_s_s((l_2886[3] = ((((safe_sub_func_uint16_t_u_u(((g_813[6][0] = ((g_359[9][0] & (-1L)) ^ l_2601)) < (safe_mod_func_uint16_t_u_u(l_2841, l_2841))), (safe_add_func_uint32_t_u_u(((safe_rshift_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((((((((0x7C9D89B7L && (safe_add_func_uint16_t_u_u(l_3026, (l_2889 != (l_3210 = ((((safe_add_func_int8_t_s_s((safe_add_func_uint32_t_u_u(l_3702, g_2710)), l_2943)) || l_5[1][6]) && l_2944) != l_2889)))))) & l_3262) != l_2266[3]) > g_1524) <= g_866[5][7]) > l_2896) || 1L), (-8L))), g_2177[0][2][6])) | 0x50DFL), l_2858)))) <= l_2896) && l_2944) || 0x623CL)), 0x8170AE80L)), l_2294)), l_2945)) <= 0x93L);
                    }
                    else
                    {
                        return g_1524;
                    }
                    return l_2294;
                }
            }
            if ((safe_add_func_uint32_t_u_u((g_359[9][0] = (safe_rshift_func_int8_t_s_s(g_866[7][3], 6))), (l_2266[3] & ((safe_add_func_uint8_t_u_u((l_2290 = (safe_sub_func_uint16_t_u_u(l_3667, (l_2954 = g_2177[0][3][9])))), ((safe_sub_func_uint16_t_u_u((8UL || (l_2465 = ((g_1524 = (l_2886[2] = ((safe_mod_func_uint16_t_u_u((l_2900[0][2][7] = 0UL), (safe_lshift_func_uint16_t_u_u(l_2774, (l_2943 < (safe_lshift_func_uint16_t_u_u(((+(l_2896 & g_172[2])) >= l_2292), 6))))))) & l_2896))) ^ l_2943))), l_2943)) && 1UL))) == 2UL)))))
            {
                l_2900[0][1][8] = (l_3017 | (safe_unary_minus_func_uint32_t_u(l_2954)));
            }
            else
            {
                uint16_t l_2979 = 0UL;
                int32_t l_3106 = 0x8C9DC0F5L;
                if ((safe_rshift_func_uint16_t_u_u(l_2900[0][1][8], (safe_add_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_u((0x8092L < ((~(((((safe_lshift_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((l_2841 != (0x4FA4222FL < l_2900[0][1][8])), 5)), (l_2839[1][2][3] != l_3667))) > (l_3683 = g_172[4])) <= (((g_2710 != l_3874[2]) < l_2978) <= l_2292)) ^ 0x244BBC70L) != g_543[1])) && l_2979)), 1)), g_172[4])), 0L)))))
                {
                    int16_t l_3004[7][4][5] = {{{(-4L),0x7651L,(-1L),(-5L),1L},{0L,0x99FBL,0xBC8AL,0x2258L,0L},{0x907EL,1L,0xD21DL,(-4L),0L},{(-1L),0L,0x33D1L,0x1D12L,1L}},{{6L,0x1D12L,1L,(-1L),(-4L)},{0xF8F4L,0xAC40L,0x96A6L,1L,1L},{(-1L),0x1CB0L,(-1L),0x46ADL,3L},{0xBC8AL,6L,(-6L),0xC8C6L,0x7C8AL}},{{(-5L),(-1L),0x7C8AL,(-4L),9L},{(-4L),1L,(-6L),0x7C8AL,0x530DL},{(-1L),0x7484L,(-1L),3L,6L},{0xBAC0L,0x32A9L,0x96A6L,0x1CB0L,0x444BL}},{{0x444BL,0x34E6L,1L,(-1L),1L},{0x7484L,0x907EL,0x33D1L,8L,1L},{0x31EAL,(-6L),0xD21DL,(-4L),(-1L)},{0x31EAL,(-1L),0xBC8AL,0x530DL,1L}},{{0x7484L,1L,(-1L),0x51ECL,0xB22CL},{0x444BL,0x2258L,(-4L),0xBA36L,0x907EL},{0xBAC0L,0L,0L,0xBAC0L,0x7651L},{(-1L),(-4L),0x444BL,0xAC40L,1L}},{{(-4L),0x96A6L,0xF8F4L,(-6L),0x99FBL},{(-5L),0xB22CL,(-1L),1L,0L},{0x3620L,0x46ADL,3L,1L,3L},{0L,0L,(-4L),(-4L),1L}},{{0xBC8AL,0x7C8AL,0L,(-1L),0x3620L},{(-4L),0x2258L,0L,0L,0x7C8AL},{1L,0x34E6L,0x1D12L,(-1L),0xC8C6L},{0x31EAL,0x34E6L,0xF8F4L,1L,(-4L)}}};
                    int32_t l_3027 = 0x4F76AF9EL;
                    int i, j, k;
                    for (l_2692 = 0; (l_2692 != 55); ++l_2692)
                    {
                        int16_t l_2984[4] = {0L,0L,0L,0L};
                        int i;
                        l_2294 = l_2858;
                        l_2290 = (safe_lshift_func_uint16_t_u_u(0x652AL, 2));
                        if (l_2984[3])
                            continue;
                        l_2296 = ((l_2292 != ((l_2984[3] == ((-10L) <= 0x4657L)) & g_543[0])) != 0x598F6BB9L);
                    }
                    for (g_3261 = 0; (g_3261 <= 4); g_3261 += 1)
                    {
                        int i;
                        l_2296 = (l_2886[g_3261] = (safe_lshift_func_uint8_t_u_s(l_3683, (safe_rshift_func_int16_t_s_u((safe_mod_func_uint32_t_u_u((g_949[0][2][2] != l_2292), (safe_rshift_func_int16_t_s_u((safe_unary_minus_func_int32_t_s(g_172[4])), ((safe_mod_func_uint32_t_u_u(l_2979, l_2840)) != l_2886[1]))))), (safe_lshift_func_uint8_t_u_u(g_1460, 5)))))));
                        l_2900[0][1][8] = (safe_rshift_func_int16_t_s_u((((l_2774 > (safe_sub_func_uint8_t_u_u(l_2979, (safe_rshift_func_uint8_t_u_s(l_3004[4][2][0], 0))))) > (safe_mod_func_uint16_t_u_u((safe_sub_func_int32_t_s_s((safe_mod_func_uint8_t_u_u((((0xD7L || (l_3027 = ((safe_add_func_int16_t_s_s((l_2290 = ((l_2978 & (safe_lshift_func_int8_t_s_u(((safe_lshift_func_int8_t_s_u((l_3017 || ((((1L == (((!g_2177[3][1][5]) | ((((((safe_mod_func_int32_t_s_s(((((!((safe_rshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s(((0x32L | g_1460) < l_3004[4][2][0]), 2)) ^ l_3667), 12)) || 0x97B2L)) | l_2979) | 0xB9843563L) < 0xB46BL), l_3667)) > l_3017) < l_2290) || l_3026) == l_2790[4][0]) != l_2886[g_3261])) | 0x616CL)) < l_2900[0][5][5]) ^ l_2886[g_3261]) <= 1L)), 4)) ^ l_2979), 4))) <= l_2979)), 0x7F87L)) == l_2292))) > g_949[2][2][1]) & l_2841), l_3667)), l_2886[g_3261])), l_2266[3]))) | 0x49L), g_813[1][0]));
                        if (l_2886[g_3261])
                            continue;
                    }
                    l_2296 = g_1129;
                }
                else
                {
                    int32_t l_3037 = 0xE3233A39L;
                    int32_t l_3060[10] = {6L,6L,6L,6L,6L,6L,6L,6L,6L,6L};
                    int i;
                    l_2296 = (((safe_lshift_func_uint16_t_u_s((((((l_2266[3] = ((l_2886[2] = g_813[0][0]) == (g_543[1] ^ (g_2710 & l_3210)))) <= (safe_sub_func_uint8_t_u_u(((0x13L | (l_2840 = ((l_2292 >= (safe_sub_func_int32_t_s_s(l_2979, g_2710))) >= ((safe_sub_func_int8_t_s_s((1UL >= 0x6AL), 0x75L)) <= 0xFD0877F9L)))) && l_3036[6][2][5]), l_2979))) >= 0UL) && g_359[9][0]) || l_3037), l_2943)) > l_2294) | g_3261);
                    for (l_2674 = 0; (l_2674 > 24); l_2674 = safe_add_func_uint8_t_u_u(l_2674, 9))
                    {
                        int16_t l_3042 = 0xDD5AL;
                        l_3262 = (safe_add_func_int16_t_s_s((l_3042 < l_2465), ((safe_sub_func_int32_t_s_s(0x826DAE46L, ((g_1524 < 0xCDF2L) != ((safe_rshift_func_uint16_t_u_u(l_3037, (l_3702 = l_2692))) && (65535UL < ((safe_rshift_func_int8_t_s_u(0xB0L, 0)) | l_2896)))))) != 0x08L)));
                    }
                    for (l_3037 = 5; (l_3037 >= 2); l_3037 -= 1)
                    {
                        uint8_t l_3061 = 0UL;
                        int i;
                        l_3061 = (~(((l_3060[5] = (((safe_mod_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_s((safe_unary_minus_func_int32_t_s((safe_add_func_uint32_t_u_u(((-1L) == g_172[(l_3037 + 2)]), l_3874[l_3037])))), l_3874[l_3037])) > ((!l_3240[l_3037]) > l_2292)), (safe_mod_func_int32_t_s_s(l_3037, (l_3210 = 4294967295UL))))) || (0x5AFB853AL <= l_3240[l_3037])) | 0xA7L)) ^ l_3037) >= g_359[5][0]));
                    }
                }
                l_2900[0][2][4] = (((g_949[0][6][1] && (g_359[9][0] | (((g_2177[3][1][9] >= (1UL && (safe_mod_func_uint32_t_u_u(l_2858, (safe_lshift_func_uint8_t_u_u((((l_2296 = l_3702) ^ ((safe_mod_func_int8_t_s_s(((safe_lshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s(2L, l_3072)), 6)) != (l_3874[2] != 253UL)), g_1460)) & l_3240[4])) & l_2858), l_2841)))))) >= l_2418[5][1]) ^ 0xD174L))) == 7UL) <= 0x9A48L);
                if ((l_3874[5] && g_1524))
                {
                    l_2408[4][4] = l_3026;
                }
                else
                {
                    uint32_t l_3090 = 0UL;
                    int32_t l_3091 = 0L;
                    int16_t l_3092 = (-8L);
                    l_2900[0][1][8] = (l_3262 = (((safe_add_func_uint8_t_u_u((0x8017L & 0xC852L), (((safe_add_func_uint16_t_u_u((!((safe_rshift_func_uint8_t_u_s(((safe_add_func_int8_t_s_s(4L, (safe_mod_func_int16_t_s_s((l_3667 > l_2979), (~(l_2296 = ((+l_3026) && (safe_add_func_uint8_t_u_u((((+(((!l_2841) && ((l_3090 = l_2408[1][3]) & (((l_3091 && 0x435BL) ^ l_2601) > 1L))) >= l_3092)) | l_3026) > 0x889AL), g_866[6][9]))))))))) <= g_1524), l_2979)) < l_2292)), l_2292)) & g_2710) >= 0xAEL))) & l_2978) > 0x659EL));
                    l_3017 = l_2790[4][0];
                    if (g_1460)
                    {
                        uint16_t l_3099[7][1][9] = {{{0x51BFL,0xF916L,0xE95AL,0xF916L,0x51BFL,0xFFE8L,0xF916L,0x12F6L,0x49F3L}},{{0xFB2EL,0x5E99L,0x2DFEL,3UL,0x5E99L,0x6495L,0x5E99L,3UL,0x2DFEL}},{{0x51BFL,0x51BFL,0x49F3L,0x12F6L,0xF916L,0xFFE8L,0x51BFL,0xF916L,0xE95AL}},{{0x1128L,0x5E99L,0x525EL,0xFB2EL,0xFB2EL,0x525EL,0x5E99L,0x1128L,0x6495L}},{{0xB939L,0xF916L,0x49F3L,0xB939L,0xA389L,65526UL,0xF916L,0xF916L,65526UL}},{{0UL,0xFB2EL,0x2DFEL,0xFB2EL,0UL,0x9D28L,0xFB2EL,3UL,0x6495L}},{{0xF916L,0xA389L,0xE95AL,0x12F6L,0xA389L,0x49F3L,0xA389L,0x12F6L,0xE95AL}}};
                        int i, j, k;
                        l_2294 = (safe_sub_func_uint8_t_u_u(((safe_add_func_uint16_t_u_u(g_543[1], (0x01E7BACFL || (l_3262 = 0L)))) == (((l_2900[0][0][5] = ((safe_sub_func_int16_t_s_s((g_949[0][6][1] < ((l_2465 = ((0xE5L || (l_3099[2][0][1] < (g_1524 | (safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((g_813[6][0] >= (l_3026 = (safe_lshift_func_uint8_t_u_s((1L & l_2900[0][1][6]), g_359[2][6])))), 4)), 4))))) & l_3099[3][0][2])) || 1L)), l_2918)) && l_3106)) <= g_359[2][3]) & 0x0EL)), (-2L)));
                    }
                    else
                    {
                        l_2900[0][1][7] = l_3091;
                        return g_543[1];
                    }
                }
                l_2294 = ((safe_unary_minus_func_int32_t_s((((l_2900[0][4][1] = ((((g_1460 & ((4L >= (g_1524 = ((7L | ((0x9B13L < g_1460) > (l_2979 < ((!l_5[1][1]) <= (g_3261 = ((g_1129 != (((0xA14DL > 0xAC7AL) == l_2886[2]) > 0L)) <= g_866[4][0])))))) | g_1129))) <= l_3026)) < l_3874[0]) == l_2526) <= 0x0C7DL)) || 254UL) != l_3109))) != l_2841);
            }
        }
        if ((((safe_rshift_func_int16_t_s_s((safe_mod_func_uint8_t_u_u((((safe_rshift_func_int16_t_s_u((9L ^ ((g_2177[2][1][7] == g_949[0][2][4]) || ((l_2886[3] = (l_3116 != (safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_s((l_2292 > (0x05L | l_3036[5][1][4])), 7)), g_1129)), (safe_unary_minus_func_int8_t_s(((g_866[1][3] & g_1460) & g_543[1]))))))) || g_866[4][0]))), 2)) == l_2838) <= 0UL), 0x82L)), g_2710)) && g_2710) < l_2838))
        {
            int16_t l_3131 = 0xDA0DL;
            l_2294 = ((-7L) | (safe_lshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((0xACL >= (!(safe_mod_func_uint16_t_u_u(l_3131, l_3116)))), 5)), 10)));
            for (l_2601 = 17; (l_2601 <= (-24)); l_2601 = safe_sub_func_uint32_t_u_u(l_2601, 6))
            {
                if (g_813[1][0])
                    break;
                return l_3131;
            }
            return l_3210;
        }
        else
        {
            int8_t l_3134 = 1L;
            l_2294 = l_3134;
            l_2266[3] = (safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u(((((safe_sub_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u(((l_3036[8][1][4] && (((l_2292 = (safe_sub_func_int8_t_s_s((safe_mod_func_int8_t_s_s((safe_mod_func_int8_t_s_s(l_2858, (safe_sub_func_uint32_t_u_u(l_3151, ((l_3210 = l_3134) == (0x54EAL == (g_866[2][3] & (l_3262 = g_813[1][0])))))))), i)), (((l_2465 & g_866[4][0]) != l_3667) < l_3134)))) >= 0x97L) || g_172[3])) <= 3L), g_359[9][0])) <= l_3134), 0UL)) ^ 2UL) == l_3240[4]) == 0x81F5611FL), l_2674)), 7));
        }
        l_2840 = ((0x10L && (((l_2886[0] = (l_3153 = l_3026)) != l_2840) == (safe_mod_func_uint16_t_u_u((g_3261 = (((safe_mod_func_int16_t_s_s((l_3017 = ((g_813[5][0] & ((((g_2177[3][1][9] = (safe_lshift_func_int16_t_s_u((safe_add_func_uint32_t_u_u((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((((safe_unary_minus_func_int8_t_s(((safe_sub_func_uint32_t_u_u(0UL, (0x891FL & (safe_mod_func_int16_t_s_s((l_2292 ^ (((((l_2816 == g_866[4][0]) <= l_2418[5][4]) | l_2840) > l_3683) != l_3171)), l_2266[3]))))) || l_2692))) > l_2465) | 0xD3666B9CL), l_2296)), l_2601)), l_3262)), 13))) > 0UL) != l_2465) > l_2918)) != l_3151)), l_2841)) > l_2838) != l_2842)), 1L)))) <= 0L);
    }
    l_3262 = (l_2296 = (((!(((l_2266[3] = (safe_rshift_func_uint16_t_u_u(((l_2294 = (((safe_rshift_func_int8_t_s_s(l_2266[0], 1)) == (~((0UL <= (((l_2408[2][5] || (safe_sub_func_uint16_t_u_u((0x07C4L | ((safe_lshift_func_uint8_t_u_u((((safe_mod_func_int8_t_s_s(9L, 0x8EL)) & (safe_mod_func_int16_t_s_s((safe_mod_func_uint16_t_u_u((((safe_add_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(0x49BFL, (l_2290 = ((safe_lshift_func_uint8_t_u_s((safe_add_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_s(g_813[6][0], 7)) ^ (((l_2408[0][0] = l_3874[0]) > 0x99F79172L) > 0xE78350BCL)), l_2266[3])), l_3210)) < l_3667)))), l_2674)) & l_2292) >= g_949[2][4][8]), g_866[6][3])), (-3L)))) >= 0x7F3CD12AL), 6)) == 0x5622E054L)), 0x1450L))) || l_3683) != 0L)) != l_3026))) <= g_1460)) | g_543[1]), 14))) > l_3210) & l_2899)) & (-10L)) <= l_2692));
    if (l_2790[4][0])
    {
        int8_t l_3204 = 0xA2L;
        uint32_t l_3210 = 0xF4784D76L;
        int32_t l_3239 = 6L;
        int32_t l_3240[6];
        int i;
        for (i = 0; i < 6; i++)
            l_3240[i] = 0xADBA3217L;
        l_2296 = (((((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((((l_2292 & (safe_add_func_int32_t_s_s((((((l_3204 = g_543[1]) | (9L != (safe_add_func_uint32_t_u_u(l_3667, (8L | (-1L)))))) || ((safe_sub_func_int16_t_s_s((safe_unary_minus_func_uint32_t_u(l_3210)), l_3204)) <= (g_2177[3][1][9] | l_3262))) ^ l_2266[3]) != l_3210), g_1129))) <= g_2710) || 5UL), g_2177[3][1][9])), 0)) < l_2294) >= 1UL) || l_3262) > l_3262);
        l_2296 = (l_3204 <= (safe_sub_func_uint16_t_u_u(((l_2601 >= (1UL || (safe_sub_func_uint8_t_u_u((g_2177[2][3][7] = (safe_sub_func_uint8_t_u_u((safe_mod_func_int16_t_s_s(((g_1524 = (safe_lshift_func_uint8_t_u_u((l_2266[1] = ((((l_3171 || (l_2290 = l_2692)) || (safe_sub_func_int8_t_s_s((safe_sub_func_int32_t_s_s(((l_2296 = (safe_mod_func_uint16_t_u_u(g_543[2], l_3667))) <= (g_543[1] || (l_2692 == 0UL))), l_2526)), 2L))) >= g_2177[5][3][1]) == l_3210)), l_2526))) != l_2418[5][4]), l_3204)), l_5[1][6]))), 0x74L)))) | g_949[2][4][8]), i)));
        l_3017 = (safe_add_func_uint16_t_u_u((((l_2601 >= (safe_lshift_func_int8_t_s_s(0L, ((0L | l_2408[3][0]) < ((safe_add_func_uint32_t_u_u(l_2408[3][0], (((safe_mod_func_uint8_t_u_u(((l_3210 > ((safe_rshift_func_int16_t_s_u(((((g_359[9][0] = (l_3240[3] = (((safe_mod_func_uint16_t_u_u((g_813[1][0] = (4294967295UL == ((-5L) >= l_3210))), g_3261)) >= l_5[2][1]) | l_3239))) & 4UL) & l_2292) && l_3017), 8)) > l_3667)) == l_3239), l_3702)) > 0xBF1DC840L) != l_3210))) ^ g_2177[1][1][7]))))) < g_949[0][6][1]) > 7UL), l_2292));
        for (l_2296 = 0; (l_2296 > 18); l_2296 = safe_add_func_uint32_t_u_u(l_2296, 3))
        {
            uint16_t l_3255[4][5];
            int32_t l_3256[2][8] = {{0L,0L,0x73962BB8L,0x73962BB8L,0L,0L,0x73962BB8L,0x73962BB8L},{0L,0L,0x73962BB8L,0x73962BB8L,0L,0L,0x73962BB8L,0x73962BB8L}};
            int i, j;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 5; j++)
                    l_3255[i][j] = 0x74B9L;
            }
            if ((safe_sub_func_uint16_t_u_u((l_3204 || (safe_add_func_uint32_t_u_u(((((((l_2790[4][0] || ((((l_3702 != ((l_3256[1][3] = (l_3873 >= (l_2290 = (l_3262 = (l_2296 = (((safe_sub_func_int32_t_s_s(((((safe_mod_func_uint8_t_u_u(((((l_3240[2] & ((l_3262 = (l_2294 = (safe_add_func_uint16_t_u_u(l_3204, (65529UL != ((g_1524 & ((safe_add_func_int8_t_s_s(3L, l_3240[1])) <= l_3255[1][3])) != 0x21FD1DCEL)))))) < (-8L))) >= 0xBAL) != l_2674) > l_5[3][0]), l_3116)) < 0L) & l_2292) ^ 0xA4EBL), 0xA9004A2AL)) > g_813[3][0]) != l_3255[1][3])))))) > l_3255[1][3])) & g_543[0]) >= l_2674) ^ 1L)) != 0L) & l_3171) ^ l_3667) & l_3257) | l_3255[0][4]), 1UL))), l_3707)))
            {
                uint32_t l_3263 = 4294967295UL;
                int32_t l_3303 = 0L;
                for (g_2710 = 0; (g_2710 != 43); g_2710++)
                {
                    uint32_t l_3304 = 0xA0CD230EL;
                    int32_t l_3305[2][8][1] = {{{0xC3B07C44L},{0xC3B07C44L},{0x80AED170L},{0xAF71240FL},{0x9433F045L},{0xAF71240FL},{0x80AED170L},{0xC3B07C44L}},{{0xC3B07C44L},{0x80AED170L},{0xAF71240FL},{0x9433F045L},{0xAF71240FL},{0x80AED170L},{0xC3B07C44L},{0xC3B07C44L}}};
                    int i, j, k;
                    l_3262 = (g_3261 <= g_2710);
                    l_3263 = 0x3D7DBF13L;
                    if (g_2177[1][0][6])
                    {
                        return l_3683;
                    }
                    else
                    {
                        uint8_t l_3287 = 5UL;
                        l_3305[0][3][0] = (((safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((l_3667 = ((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s((safe_unary_minus_func_int16_t_s((((safe_add_func_int16_t_s_s((l_3240[3] = l_3255[2][2]), ((safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(((safe_add_func_int32_t_s_s(((safe_mod_func_uint16_t_u_u((l_3256[1][3] = ((safe_sub_func_int32_t_s_s((l_3262 = 1L), (safe_lshift_func_int16_t_s_s(((0x83DAL <= (g_2177[3][1][9] > (l_3287 | 1UL))) <= (((safe_sub_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u((((safe_rshift_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(((l_3303 = (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_uint32_t_u((((safe_add_func_uint16_t_u_u(((l_3256[1][3] < l_3287) < ((safe_sub_func_int32_t_s_s(l_3287, 7UL)) && g_3261)), l_3873)) >= 0x318768DEL) && l_3263))), 9))) != l_3204), l_3256[1][6])), 4)) >= l_3304) | g_1460), l_3287)) ^ l_3707), 0L)) ^ 0x51L) != l_3210)), 15)))) >= l_3287)), (-1L))) && g_2177[5][1][8]), g_813[6][0])) ^ 0xAFL), l_3210)), l_3017)) >= 0x34L))) == g_359[9][2]) | l_3240[4]))), l_2465)), g_2710)) == l_3255[0][1])), 4)), 6)) || 4UL) | l_3287);
                    }
                }
                for (l_3204 = 0; (l_3204 <= (-20)); l_3204 = safe_sub_func_uint8_t_u_u(l_3204, 5))
                {
                    l_3262 = (g_359[9][0] ^ (g_1460 != (((safe_rshift_func_uint16_t_u_u(9UL, (safe_sub_func_int16_t_s_s((g_543[1] = 0x560CL), (safe_lshift_func_int16_t_s_s((!l_3303), 7)))))) > ((l_3873 && ((l_2266[3] = 65535UL) != (l_3667 & (l_2296 = ((-10L) > 0xD9890121L))))) > l_3204)) | l_3256[1][3])));
                    l_3303 = 0x9ED79E98L;
                    l_3262 = (l_3256[1][2] = (l_3262 = (0x6A45L != (l_2601 = (-1L)))));
                    l_3707 = 0xA5D6E7B4L;
                }
                for (l_3262 = (-29); (l_3262 < 29); l_3262++)
                {
                    int32_t l_3319 = 4L;
                    for (l_2292 = 1; (l_2292 <= 7); l_2292 += 1)
                    {
                        int i, j;
                        return g_866[l_2292][(l_2292 + 1)];
                    }
                    for (l_2294 = (-5); (l_2294 > 23); l_2294++)
                    {
                        l_3319 = 0x34207361L;
                    }
                }
            }
            else
            {
                l_3707 = l_3239;
            }
            l_3262 = (safe_lshift_func_uint8_t_u_s((safe_sub_func_int16_t_s_s((((((((safe_add_func_int8_t_s_s(0x88L, (l_3017 ^ (safe_unary_minus_func_uint32_t_u(g_2710))))) >= 0xE6B5L) <= (g_359[9][0] || g_813[1][0])) < (0xD1BFL && (((0x8B84L != (safe_sub_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((l_2296 >= l_3256[1][3]), l_2294)), l_2790[4][0])) > 0x93L), l_3255[1][3]))) | g_2177[4][3][5]) ^ l_3873))) < l_3874[1]) == l_3257) & 65530UL), l_3873)), l_5[1][6]));
        }
    }
    else
    {
        int8_t l_3339 = 0xC8L;
        int32_t l_3340 = 0x644F2DE5L;
        uint8_t l_3351[6];
        int32_t l_3352[3];
        uint16_t l_3398 = 65532UL;
        uint32_t l_3467 = 0UL;
        int i;
        for (i = 0; i < 6; i++)
            l_3351[i] = 0x35L;
        for (i = 0; i < 3; i++)
            l_3352[i] = 0xE9F35B3EL;
        if ((0L ^ (((l_2292 ^ ((safe_mul_func_uint8_t_u_u((l_3340 = (safe_add_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s(l_3667, l_3339)), (g_2710 == g_2710)))), ((l_3707 = (~(safe_lshift_func_int16_t_s_s((((safe_unary_minus_func_uint32_t_u(((safe_lshift_func_uint8_t_u_s(((safe_sub_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_s(l_2408[3][0], 13)), (l_3017 = (((l_2841 ^ ((((g_866[4][0] ^ l_3351[3]) < 0xE8L) | g_2710) || l_2266[3])) ^ l_3351[3]) || l_2692)))) & l_3351[0]), l_3351[2])) != l_3240[4]))) ^ l_2465) & l_3352[0]), g_359[9][0])))) != 0x3D20D3F6L))) <= l_3339)) == l_2841) == l_2408[3][0])))
        {
            l_2296 = (l_3262 = (safe_add_func_int8_t_s_s(g_2177[3][1][9], l_3351[4])));
        }
        else
        {
            int32_t l_3355[8][1] = {{0L},{(-1L)},{0L},{(-1L)},{0L},{(-1L)},{0L},{(-1L)}};
            uint32_t l_3372[4] = {0x99672B6EL,0x99672B6EL,0x99672B6EL,0x99672B6EL};
            int32_t l_3443 = 4L;
            uint32_t l_3505 = 18446744073709551615UL;
            int32_t l_3506[10];
            int i, j;
            for (i = 0; i < 10; i++)
                l_3506[i] = (-1L);
            l_2294 = ((g_1129 = (l_3874[2] ^ l_3340)) | l_3355[5][0]);
            for (l_3262 = 2; (l_3262 >= 0); l_3262 -= 1)
            {
                int32_t l_3359 = 0x3456D091L;
                uint16_t l_3373 = 1UL;
                uint32_t l_3513 = 4294967295UL;
                int i;
                l_3340 = (g_543[l_3262] != ((safe_rshift_func_uint8_t_u_s(g_543[l_3262], (l_3667 = (l_3359 = (safe_unary_minus_func_int8_t_s(1L)))))) ^ (safe_add_func_int32_t_s_s(g_866[6][0], (((0xF346L ^ l_3262) && (((l_3240[4] | (!l_3340)) & l_3339) != l_2292)) | 4294967288UL)))));
                if ((((((l_2899 > (g_813[4][0] | 0x4A1BL)) | l_3355[5][0]) == (((l_3702 ^ ((i || l_3240[4]) < (safe_add_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((((g_1129 || (safe_unary_minus_func_int16_t_s(l_3874[2]))) == l_3262) <= 0x88L), 14)), (-1L))))) != l_3026) == g_3261)) < 65535UL) <= 1UL))
                {
                    uint16_t l_3397 = 0xE9F5L;
                    for (l_3683 = 0; l_3683 < 3; l_3683 += 1)
                    {
                        l_3352[l_3683] = 0x6604D0B6L;
                    }
                    for (l_3257 = 0; (l_3257 <= 2); l_3257 += 1)
                    {
                        int32_t l_3396[2][10] = {{0xFD928D26L,0x128AF7B3L,0xFD928D26L,0x70EF2261L,0x70EF2261L,0xFD928D26L,0x128AF7B3L,0xFD928D26L,0x70EF2261L,0x70EF2261L},{0xFD928D26L,0x128AF7B3L,0xFD928D26L,0x70EF2261L,0x70EF2261L,0xFD928D26L,0x128AF7B3L,0xFD928D26L,0x70EF2261L,0x70EF2261L}};
                        int i, j;
                        l_3262 = ((((safe_sub_func_uint32_t_u_u(((safe_lshift_func_uint16_t_u_u((((((((l_5[5][1] ^ g_2710) & (g_359[5][3] = ((l_3210 = l_3372[0]) & l_3373))) & ((safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u((l_2465 != (l_3683 = ((251UL <= ((l_3026 = (((l_3534 = (safe_add_func_uint32_t_u_u(((((safe_mod_func_int16_t_s_s((safe_sub_func_int32_t_s_s((safe_sub_func_int8_t_s_s((0xCCA5L != (safe_unary_minus_func_int16_t_s((g_543[l_3262] = ((l_3373 < (safe_add_func_uint16_t_u_u(((l_2296 = (safe_rshift_func_int8_t_s_s((~(safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((l_3702 ^ l_3240[5]), l_3667)), l_3355[4][0]))), 1))) > 0xE3C5E1EAL), l_3873))) <= g_1524))))), l_3240[4])), l_3683)), l_3396[0][2])) && l_3397) && l_2296) > (-1L)), l_3359))) >= l_3373) | 0x3BE0L)) ^ (-9L))) || 0x52L))), 3)) | l_3398), 0xC478L)) <= 0x81F1L)) <= l_2292) & g_1524) <= l_2294) >= 0x47L), g_1524)) != l_3399), l_3151)) != l_3397) ^ 1UL) > 0x7F4ED5EFL);
                        l_3340 = (((((l_2292 <= (safe_lshift_func_int8_t_s_u(((l_3397 && (l_3396[0][2] = ((((l_3351[3] > (((safe_sub_func_uint8_t_u_u(((g_3261 || (l_3359 = (((l_3210 = (g_359[9][1] = (((g_813[1][0] = ((((safe_sub_func_int16_t_s_s((-1L), ((g_1129 = ((0x82A8L ^ 0xEFCAL) > ((l_2408[3][0] != (safe_sub_func_int16_t_s_s((((0x3DD5L < g_543[l_3262]) <= 1L) ^ l_3408), g_2177[1][2][4]))) || 4294967295UL))) != 0x58L))) && l_2418[5][4]) || 4L) & g_2710)) == 0x5062L) >= 0x611BL))) != g_2710) && l_3240[4]))) != 3L), l_3351[3])) | l_3396[0][2]) <= l_4035)) & g_3261) != 1L) || 1L))) >= 255UL), g_2177[3][1][9]))) | 0xEFL) <= g_543[l_3262]) >= g_1524) == l_3373);
                        l_2296 = l_3352[0];
                    }
                    l_2408[1][0] = (((((l_3372[3] > (safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u((safe_rshift_func_uint16_t_u_u(((g_172[3] != (safe_add_func_int8_t_s_s(l_3397, (((safe_unary_minus_func_int8_t_s(((((safe_sub_func_int32_t_s_s(l_3151, l_2790[4][0])) | ((safe_lshift_func_uint16_t_u_s((l_3424[1][0][0] && ((0xFDCCD15CL < (safe_lshift_func_uint16_t_u_s((safe_lshift_func_uint16_t_u_s((safe_add_func_int8_t_s_s((l_3683 = ((l_3351[4] & g_543[l_3262]) <= l_3707)), 0UL)), l_2841)), 9))) ^ 8UL)), 11)) ^ g_3261)) & (-5L)) ^ l_3017))) < l_2292) != 0x29BCB211L)))) == l_3397), g_866[4][0])), 15)), l_2526))) <= (-3L)) == 0x1AE2L) && l_3398) == l_3372[0]);
                }
                else
                {
                    uint16_t l_3442[9][9] = {{0xD162L,0UL,0xD162L,0x5941L,0x5941L,0xD162L,0UL,0xD162L,0x5941L},{0xD162L,0x5941L,0x5941L,0xD162L,0UL,0xD162L,0x5941L,0xD162L,65532UL},{0x5941L,0xD162L,0UL,0xD162L,0x5941L,0x5941L,0xD162L,0UL,0xD162L},{0xD162L,0UL,0UL,0UL,0UL,0xD162L,0UL,0UL,0UL},{0x5941L,0x5941L,0xD162L,0UL,0xD162L,0x5941L,0x5941L,0xD162L,0UL},{65532UL,0UL,65532UL,0xD162L,0xD162L,65532UL,0UL,65532UL,0xD162L},{65532UL,0xD162L,0xD162L,65532UL,0UL,65532UL,0xD162L,0xD162L,65532UL},{0x5941L,0xD162L,0UL,0xD162L,0x5941L,0x5941L,0xD162L,0UL,0xD162L},{0xD162L,0UL,0UL,0UL,0UL,0xD162L,0UL,0UL,0UL}};
                    int i, j;
                    l_3707 = ((safe_mod_func_int8_t_s_s((l_3683 = ((safe_rshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((g_2710 = (((((0xEAL && (((l_3443 = (safe_sub_func_int32_t_s_s((!(safe_rshift_func_int16_t_s_s(l_2841, l_3442[6][8]))), (g_1460 == g_866[6][5])))) || (((l_3340 = (safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_u(((safe_lshift_func_uint16_t_u_s(((+0x53L) >= (~((l_2292 = (safe_sub_func_uint32_t_u_u(0x00580031L, (((safe_sub_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_u((safe_lshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_u(0xF9L, 7)), 15)), 10)) == (l_3443 = g_359[9][0])), l_3151)) == 0x2266L) & l_2899)))) ^ l_3355[5][0]))), 1)) <= l_3707), 1)) != l_3355[5][0]), 7)), 2))) == l_2601) > g_359[9][0])) & 0xD676L)) == l_3442[0][6]) != l_3442[6][8]) ^ 0x3B79L) >= 0x22L)), 0UL)), l_3667)) ^ g_866[4][0])), 0x3CL)) >= l_2692);
                }
                for (l_2692 = 0; (l_2692 <= 57); l_2692 = safe_add_func_int16_t_s_s(l_2692, 7))
                {
                    int32_t l_3476 = 0x5E8CBEC4L;
                    if (l_3667)
                    {
                        uint16_t l_3468 = 0x5320L;
                        l_3707 = ((l_3359 | g_543[l_3262]) == (((g_2177[3][1][9] = (l_3026 < 0xC0L)) > (l_3372[0] != (g_2710 = ((safe_unary_minus_func_int8_t_s(((l_3467 != g_543[l_3262]) < l_3468))) >= ((((g_3261 = 65535UL) | 0L) | 0L) || 8UL))))) != 0x21L));
                    }
                    else
                    {
                        uint8_t l_3474 = 0x79L;
                        int32_t l_3475 = 0xEE4C41D5L;
                        l_2294 = (safe_add_func_int32_t_s_s((((l_3471 ^ (((l_3373 < ((safe_mod_func_uint16_t_u_u((l_2292 ^ (l_3352[1] ^ (l_2692 && (((((l_2465 | 4294967292UL) | g_1460) | (l_3474 = 6L)) > 1UL) > l_2841)))), g_1524)) == 0xEC67L)) || l_3683) >= 0x2A2BL)) && l_3683) != l_3475), g_949[0][6][1]));
                        if (l_3476)
                            break;
                        l_2408[1][1] = ((0xACA1L ^ ((safe_add_func_int16_t_s_s((((((l_3471 = ((((l_3474 >= (safe_lshift_func_uint8_t_u_s(0x3BL, 0))) >= (safe_lshift_func_uint8_t_u_s((safe_unary_minus_func_int16_t_s(l_3017)), ((l_3443 | (l_3534 > 0x81F1L)) ^ (safe_lshift_func_uint16_t_u_u((((safe_sub_func_uint16_t_u_u((((((l_2290 = (safe_rshift_func_int16_t_s_s(((~l_3475) > (l_2266[3] = 0x4EE0L)), g_2710))) && g_543[1]) & g_813[1][0]) ^ l_3492) > l_3240[1]), 0L)) >= l_3398) < (-5L)), 10)))))) ^ g_543[l_3262]) <= 1UL)) >= 0x86DCL) | l_3351[5]) == 0UL) & g_543[l_3262]), l_3874[1])) >= 0xC6L)) <= l_3240[3]);
                    }
                    for (l_3471 = (-22); (l_3471 < 11); ++l_3471)
                    {
                        uint32_t l_3502 = 0x9ED2561EL;
                        l_2294 = (0x16F39D5EL != ((((safe_add_func_int16_t_s_s(((l_3476 <= ((safe_add_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u((l_2290 = ((l_2296 & (!((l_3443 = (g_359[9][0] = l_3339)) >= (l_2294 <= 2L)))) == 3UL)), l_3502)), ((safe_add_func_int8_t_s_s((l_3707 != 0x76L), g_3261)) >= g_866[0][5]))) ^ 0UL)) || g_949[1][1][4]), l_3359)) || l_3502) < g_3261) ^ l_3355[0][0]));
                    }
                    if ((((l_4035 == 0x87L) != (g_1129 = 0UL)) ^ l_4035))
                    {
                        l_3506[3] = ((0x63D96127L || l_3359) > (0xE625L || l_3505));
                    }
                    else
                    {
                        int8_t l_3520 = 0x2EL;
                        l_3359 = 0x132D1CFBL;
                        l_2296 = (((l_3340 = (((((l_2292 >= (g_2710 = ((0xA6C9L | (safe_mod_func_int8_t_s_s((safe_sub_func_int32_t_s_s(l_3667, l_3351[3])), l_3372[0]))) & (safe_mod_func_uint16_t_u_u(((l_3513 < (safe_sub_func_uint32_t_u_u(((safe_rshift_func_int8_t_s_s(g_866[0][1], (((safe_sub_func_int8_t_s_s((g_813[6][0] && l_2294), 255UL)) > 1L) || 0xA69DCD2EL))) | l_3520), l_3026))) ^ l_3372[3]), g_2710))))) == 0xA3DB543AL) && l_3520) != 0x5621L) & g_1524)) >= g_1524) | l_3667);
                    }
                    l_3707 = g_2710;
                }
            }
        }
        l_3262 = ((((l_2294 = (g_543[1] | (safe_add_func_int16_t_s_s(l_3874[0], (((1UL ^ l_3210) < l_3340) < (l_3151 = (safe_sub_func_uint32_t_u_u(((safe_add_func_uint32_t_u_u((l_2408[0][2] == ((~(((((safe_add_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(l_3534, (safe_mod_func_uint8_t_u_u(g_866[7][7], (safe_sub_func_uint32_t_u_u((((((((l_3352[0] < l_2292) >= 0x780BL) != l_3398) ^ 0L) < (-1L)) | g_3261) ^ l_3683), l_2408[3][0])))))) <= 0UL), l_3351[3])) & 4294967295UL) || (-1L)) != (-1L)) < l_2408[0][5])) > l_3707)), l_2601)) & l_3398), (-6L))))))))) >= g_172[7]) == l_3873) == l_2292);
        return l_3398;
    }
    if ((+(safe_add_func_int32_t_s_s((l_2408[3][4] = (((g_3261 || (safe_sub_func_uint16_t_u_u(((l_2266[3] = (l_2841 ^ (safe_add_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((~((safe_lshift_func_int8_t_s_s((((l_2290 = l_3534) <= (((safe_add_func_uint8_t_u_u((((0xADFAL <= g_3261) & (l_2601 && l_3210)) < (-2L)), ((l_3116 < l_3702) ^ l_3017))) < 7UL) ^ l_2266[3])) | l_3017), g_1129)) || l_5[1][6])), g_1524)), 0x16L)))) || l_3116), 0x5C64L))) >= l_3240[3]) & l_2296)), l_3408))))
    {
        int32_t l_3561 = 0xC7A6A094L;
        int32_t l_3562[7];
        int32_t l_3639 = 0x57E1FCD6L;
        int i;
        for (i = 0; i < 7; i++)
            l_3562[i] = 0xF6374F20L;
        if ((safe_rshift_func_uint16_t_u_s((l_4035 < (safe_sub_func_uint8_t_u_u((g_2710 = (safe_sub_func_uint16_t_u_u(((l_3561 = 0xFE00L) > l_3562[1]), g_866[5][2]))), ((safe_rshift_func_int8_t_s_s((safe_sub_func_int16_t_s_s(g_813[1][0], ((l_3262 >= (safe_add_func_uint32_t_u_u(((safe_mul_func_int32_t_s_s((l_3262 = (((0UL > ((g_3261 > ((safe_add_func_int8_t_s_s((l_3262 <= 0xAE4AL), 0x0CL)) >= 255UL)) ^ 0xBAED8CF2L)) == g_1129) && 0L)), 0L)) || l_3562[1]), 0xFBC96193L))) == (-9L)))), 6)) == l_2294)))), l_3573[1])))
        {
            l_3562[1] = 1L;
        }
        else
        {
            int16_t l_3588 = 9L;
            int32_t l_3622[9][5] = {{3L,0x6BA56314L,1L,0x10275A46L,0L},{0x10275A46L,(-7L),4L,4L,(-7L)},{0L,1L,5L,4L,0x99AB53BFL},{1L,0x99AB53BFL,0x528214A4L,0x10275A46L,0x6BA56314L},{1L,(-10L),0L,0x6BA56314L,0x888D88CAL},{1L,1L,0x888D88CAL,1L,1L},{0L,0x366C108CL,0x888D88CAL,0L,1L},{0x10275A46L,8L,0L,5L,3L},{3L,1L,0x528214A4L,0x366C108CL,1L}};
            uint16_t l_3664 = 8UL;
            int i, j;
            for (l_2692 = 2; (l_2692 >= 7); ++l_2692)
            {
                uint8_t l_3587[6];
                int32_t l_3614 = 0x78771F22L;
                int32_t l_3615[3];
                int i;
                for (i = 0; i < 6; i++)
                    l_3587[i] = 248UL;
                for (i = 0; i < 3; i++)
                    l_3615[i] = 0x1058D4E6L;
                l_3262 = (0x2024L >= (safe_rshift_func_int16_t_s_u((0xA3L && 0x6BL), l_3561)));
                l_3262 = (g_2710 <= ((((l_2408[3][0] = (safe_rshift_func_uint8_t_u_u(((safe_add_func_int32_t_s_s((0x3CA5L >= ((safe_mod_func_uint8_t_u_u(0x91L, l_3562[5])) >= l_3562[1])), (1L | 0x184E7879L))) != l_3257), ((safe_rshift_func_uint16_t_u_u((~(g_813[4][0] = 2UL)), l_3561)) | l_3587[3])))) && 0x2CB018B9L) & l_3151) == l_3588));
                l_3707 = l_3116;
                l_3615[2] = ((((l_2465 = (((safe_sub_func_int8_t_s_s((-2L), (safe_rshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u(7UL, ((255UL != (safe_sub_func_int32_t_s_s((safe_mod_func_uint32_t_u_u(((l_3874[2] ^ (0xC0D53A6EL | (l_3614 = (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_int32_t_s((((g_3261 & (safe_sub_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s(((((safe_lshift_func_uint16_t_u_u((safe_add_func_int8_t_s_s((l_3667 ^ l_2465), (l_2266[3] = ((safe_lshift_func_int16_t_s_u((g_2177[3][0][1] | 0L), g_1524)) == 7L)))), l_2292)) > 0x266CL) >= g_1524) <= l_3534), 2)) == 0L), 0UL)), 1UL))) >= l_4035) != (-1L)))), 11))))) ^ l_2290), l_3562[6])), l_3424[1][0][0]))) >= 0x63A0L))), l_3587[4])))) & l_3587[5]) | g_3261)) ^ 254UL) <= l_3424[1][2][3]) || l_3614);
            }
            l_3471 = g_2177[3][1][9];
            l_3262 = (safe_unary_minus_func_uint8_t_u(1UL));
            if (g_172[7])
            {
                uint16_t l_3621 = 8UL;
                uint16_t l_3638[10][1][6] = {{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}}};
                int32_t l_3656 = 0x6C16DA66L;
                uint16_t l_3666 = 65535UL;
                int32_t l_3681 = 0L;
                int i, j, k;
                l_2294 = l_3707;
                l_3622[1][1] = ((1UL | (safe_mod_func_int16_t_s_s((l_2296 & l_3588), l_3562[1]))) == (g_2177[3][1][9] = (safe_lshift_func_int8_t_s_u(l_3621, 5))));
                if ((safe_add_func_int8_t_s_s((l_4035 = (l_3667 = (safe_lshift_func_uint8_t_u_u(((~0xACL) || (((g_1524 && (safe_mod_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(((-1L) ^ (l_3707 = ((g_813[3][0] == (l_3621 & l_3017)) <= g_3261))), (safe_rshift_func_int8_t_s_u(((((safe_unary_minus_func_int8_t_s(((l_3561 ^ (l_3638[4][0][5] = (!(l_3667 = (251UL | 1UL))))) & l_2296))) | 0x6828710FL) || g_359[4][4]) > l_2296), l_3683)))) < l_3534), l_3588))) & 0xA5L) != l_2899)), l_3639)))), 0L)))
                {
                    int16_t l_3668 = 4L;
                    if ((0x58A82B72L | (safe_sub_func_int16_t_s_s(g_2177[3][1][9], (1L < g_2177[4][3][0])))))
                    {
                        uint32_t l_3663 = 0xB87B213BL;
                        int32_t l_3665 = 0x38F15173L;
                        l_3668 = (l_3667 = (0x9C031653L > ((((safe_sub_func_uint32_t_u_u((~(g_3261 ^ ((((safe_mod_func_uint8_t_u_u((g_2177[3][1][9] > (safe_sub_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u(l_3621, (l_3262 && (l_3655 == (g_866[0][1] = (l_3656 = 0L)))))) || (safe_lshift_func_int16_t_s_s((safe_add_func_int16_t_s_s(l_2692, (((l_3663 = (4294967295UL ^ 0xC8C7ECD9L)) == 0x67EB8C8CL) <= 0L))), 14))) >= l_3664), 11)) == l_3683), 3)) == l_3665), l_3622[1][1]))), 0x4AL)) == l_3874[2]) && 0x4BL) & g_359[4][4]))), l_3622[3][4])) == (-1L)) && l_2294) < l_3666)));
                        l_2296 = 1L;
                    }
                    else
                    {
                        int32_t l_3686 = 0x5209DBEDL;
                        int32_t l_3687 = 0L;
                        l_2296 = ((safe_rshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((((-10L) < (safe_lshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((((safe_rshift_func_uint16_t_u_u((l_3702 = (((l_3681 != (0xD32132F5L <= (g_172[1] < (!l_2841)))) || 0UL) <= l_3683)), (0xA83222B9L || ((safe_sub_func_int16_t_s_s((l_3622[8][3] <= g_543[1]), l_3686)) & (-5L))))) < l_2601) & l_2601), l_3707)) <= (-1L)), 6))) >= l_3687), l_3262)), 8UL)), 2)) | g_172[0]);
                    }
                    for (l_3151 = 0; (l_3151 == 4); l_3151 = safe_add_func_uint32_t_u_u(l_3151, 4))
                    {
                        return l_3656;
                    }
                    for (g_3261 = 0; (g_3261 <= 4); g_3261 += 1)
                    {
                        int i;
                        l_3262 = (safe_add_func_uint8_t_u_u(l_2266[g_3261], (safe_lshift_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((8L == (l_3656 = ((l_2266[g_3261] && g_172[4]) < g_2177[5][2][8]))), (g_3261 = (l_3702 = (l_2692 || 0x4FL))))), 4))));
                        if (l_2841)
                            break;
                    }
                    l_3702 = (6UL && (l_3667 & (l_3639 = ((((safe_sub_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_s((((l_3562[1] && 9L) > (0xE5F008A1L <= ((l_3707 = (-10L)) <= (safe_mod_func_int8_t_s_s(g_359[6][3], (g_2710 = l_2790[0][0])))))) >= l_3240[4]), l_2899)) ^ 0xD6L), 0x64C4L)) & l_3668) == l_3656) & l_3668))));
                }
                else
                {
                    for (l_2692 = 0; (l_2692 != 42); l_2692++)
                    {
                        l_2266[2] = l_3534;
                    }
                    return g_3261;
                }
            }
            else
            {
                return g_1524;
            }
        }
        l_3707 = ((safe_lshift_func_int8_t_s_u(((l_3562[0] >= g_866[4][0]) != (g_2710 = (l_2601 > l_2692))), l_3707)) > 0x3DD2L);
        l_3262 = ((((safe_sub_func_uint16_t_u_u((((safe_rshift_func_uint16_t_u_u(l_3562[0], (safe_mod_func_uint8_t_u_u((safe_add_func_uint32_t_u_u(((l_2294 = (safe_rshift_func_int16_t_s_u((-2L), ((g_172[1] = 65528UL) < l_3562[1])))) > (safe_lshift_func_int16_t_s_u(((((~g_2177[1][2][6]) | ((l_3721 || l_2294) >= (0x0FL ^ l_3262))) | l_3639) >= g_866[4][0]), l_3874[2]))), l_2526)), l_3702)))) < g_1129) & l_3534), l_3562[1])) != 1UL) && l_2418[5][4]) ^ l_3873);
    }
    else
    {
        int32_t l_3732 = 5L;
        int32_t l_3772[9][5][4] = {{{(-5L),0x53797119L,(-1L),0xEC1AA655L},{(-3L),0x0BED20CAL,0x620E126EL,0x64D60197L},{0x620E126EL,0x64D60197L,(-1L),(-1L)},{0x9C8EED80L,0x08C26BBCL,(-1L),(-7L)},{(-1L),(-1L),0x5187487DL,(-1L)}},{{(-1L),0x5187487DL,0x5187487DL,0x08C26BBCL},{0L,0x3A0636EDL,0x227DF413L,0L},{(-1L),(-1L),0x53797119L,0x5A84B327L},{(-1L),0x08C26BBCL,0x3C72134DL,0x5A84B327L},{0L,(-1L),0x5B09E585L,0L}},{{0x64D60197L,0x3A0636EDL,0xEC1AA655L,0x08C26BBCL},{0x6CA574B2L,0x5187487DL,(-1L),0xC7C31EEAL},{0x620E126EL,(-1L),(-1L),(-5L)},{(-1L),0xEC1AA655L,0x9C8EED80L,0x0BED20CAL},{0x3A0636EDL,(-1L),0x620E126EL,(-1L)}},{{1L,(-1L),(-3L),0L},{0x5A84B327L,0L,(-5L),0x9C8EED80L},{0x9C8EED80L,4L,0L,8L},{0x9C8EED80L,(-7L),(-5L),0x2F85340DL},{0x5A84B327L,8L,(-3L),0L}},{{1L,0L,0x620E126EL,0x53797119L},{0x3A0636EDL,0xB8D39A8AL,0x9C8EED80L,(-1L)},{(-1L),0x64D60197L,(-1L),0x3FDD2651L},{0x620E126EL,0x5B09E585L,(-1L),(-1L)},{0x6CA574B2L,0x6CA574B2L,0xEC1AA655L,4L}},{{0x64D60197L,0x2F85340DL,0x5B09E585L,0x3A0636EDL},{0L,(-1L),0x3C72134DL,0x5B09E585L},{(-1L),(-1L),0x53797119L,0x3A0636EDL},{(-1L),0x2F85340DL,0x227DF413L,4L},{0L,0x6CA574B2L,0x5187487DL,(-1L)}},{{0x08C26BBCL,0x5B09E585L,0x6CA574B2L,0x3FDD2651L},{(-7L),0x64D60197L,0x0BED20CAL,(-1L)},{(-3L),0xB8D39A8AL,(-1L),0x53797119L},{8L,0L,8L,0L},{(-1L),8L,0xC7C31EEAL,0x2F85340DL}},{{0x53797119L,(-7L),0x3A0636EDL,8L},{(-1L),4L,0x3A0636EDL,0x9C8EED80L},{0x53797119L,0L,0xC7C31EEAL,0L},{(-1L),(-1L),8L,(-1L)},{8L,(-1L),(-1L),0x0BED20CAL}},{{(-3L),0xEC1AA655L,0x0BED20CAL,(-5L)},{(-7L),(-1L),0x6CA574B2L,0xC7C31EEAL},{0x08C26BBCL,0x5187487DL,0x5187487DL,0x08C26BBCL},{0L,0x3A0636EDL,0x227DF413L,0L},{(-1L),(-1L),0x53797119L,0x5A84B327L}}};
        int32_t l_3780 = 1L;
        uint32_t l_3807[8] = {0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL};
        int16_t l_3822 = 0xB624L;
        uint32_t l_3909[7][2] = {{4294967295UL,0xDBB9B69CL},{0xDA67836AL,0xDBB9B69CL},{4294967295UL,0xA3043AE8L},{0xA3043AE8L,4294967295UL},{0xDBB9B69CL,0xDA67836AL},{0xDBB9B69CL,4294967295UL},{0xA3043AE8L,0xA3043AE8L}};
        uint32_t l_3937 = 9UL;
        int32_t l_3987 = 0x7570AEB1L;
        int i, j, k;
        l_3732 = (safe_add_func_int32_t_s_s(l_2408[3][0], (safe_rshift_func_uint8_t_u_u(((((safe_rshift_func_uint8_t_u_s(((((-10L) != (safe_mod_func_uint32_t_u_u(((-9L) > ((1L < (safe_lshift_func_int16_t_s_u(l_3732, (safe_rshift_func_uint16_t_u_u(l_2408[2][1], 2))))) != (safe_rshift_func_int16_t_s_u(((safe_rshift_func_uint16_t_u_s(l_3240[5], 5)) | (l_3732 || ((safe_add_func_int16_t_s_s(l_2296, 0x51BCL)) <= 0x9FL))), l_3471)))), 0x6935AA16L))) || l_3874[2]) != l_3741), 5)) && l_3732) && l_3732) > l_3017), l_3732))));
        if ((((l_3874[2] < (((safe_rshift_func_int16_t_s_s((((((safe_sub_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(0x91L)), (g_2710 = 255UL))) && (g_949[0][6][1] & (safe_add_func_int32_t_s_s(((safe_unary_minus_func_int16_t_s((-1L))) && (safe_rshift_func_int16_t_s_s(((((l_3262 = l_2408[3][0]) > ((l_3755[0][0][5] = ((g_1460 = (g_2710 = 255UL)) ^ ((l_3752 != (((+((safe_unary_minus_func_uint16_t_u(((l_2674 && l_3873) < 9UL))) <= l_3667)) > l_3732) & l_3210)) == l_2266[3]))) || l_3732)) == l_3732) || 7L), l_3667))), l_3707)))) == 0x1476L) & l_3752) & 4294967295UL), l_3732)) || 1UL) && 0x51L)) & l_3874[8]) | l_2292))
        {
            int32_t l_3782 = (-1L);
            int32_t l_3783 = (-1L);
            uint32_t l_3784[6] = {1UL,0x277AD475L,1UL,1UL,0x277AD475L,1UL};
            int i;
            l_2296 = (((l_3732 = (g_2177[0][1][6] > 65535UL)) ^ (safe_mod_func_uint8_t_u_u(((l_2465 = (safe_rshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_u((l_3702 = (safe_lshift_func_uint8_t_u_u(255UL, (0UL > (l_3784[4] = (safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(l_3262, 3)), (((l_3783 = (safe_lshift_func_uint8_t_u_s((l_3772[0][4][0] <= ((l_3262 = ((((safe_lshift_func_int8_t_s_u((l_3667 = l_3775), 2)) != ((((safe_lshift_func_int16_t_s_u((g_543[1] = (((((((65534UL || (l_3667 = (safe_add_func_int16_t_s_s((l_3752 ^ l_3780), l_3683)))) || (-1L)) ^ l_2292) == l_3782) || l_3782) ^ l_3755[0][1][1]) == g_543[1])), 2)) ^ g_3261) == l_3782) <= g_2177[4][1][2])) && g_3261) <= 0xCEL)) != 0UL)), 4))) || l_3873) && g_813[0][0])))))))), l_2418[3][4])), 1)), g_1129))) | l_2266[4]), 0xE6L))) ^ l_3874[6]);
            l_2294 = 0x9DF8728DL;
        }
        else
        {
            uint32_t l_3796 = 18446744073709551615UL;
            int32_t l_3808 = (-1L);
            int32_t l_3812 = 0x5C3FB331L;
            for (l_4035 = 0; (l_4035 <= (-26)); l_4035 = safe_sub_func_uint32_t_u_u(l_4035, 4))
            {
                int32_t l_3789 = 0L;
                int32_t l_3793 = 0L;
                for (l_3667 = 0; (l_3667 != 4); l_3667 = safe_add_func_int32_t_s_s(l_3667, 2))
                {
                    int32_t l_3792[2][4];
                    int i, j;
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 4; j++)
                            l_3792[i][j] = 1L;
                    }
                    if ((((l_3789 <= (safe_sub_func_int16_t_s_s((0x931ABD91L > (l_3793 = l_3792[1][0])), (l_3796 | (l_2674 == (l_3026 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(l_2465, 1)), 5)), l_3262)))))))) > (~(((g_172[5] ^ (safe_mod_func_uint8_t_u_u((~l_3775), l_3807[1]))) > l_3808) && l_2692))) <= 0x50BC1107L))
                    {
                        l_3262 = (l_2294 = (0x9D645515L | (l_3792[1][3] && (l_3792[1][2] = ((+l_3667) <= g_1129)))));
                    }
                    else
                    {
                        l_3812 = (l_3262 = (0L & ((g_3261 | ((((g_1129 || ((g_2177[1][1][3] = (l_3808 == (g_1524 = (65535UL != (((l_3534 = l_3796) < ((((safe_unary_minus_func_uint8_t_u(((g_2710 ^ ((+l_3573[1]) != l_3210)) > l_2292))) <= 8L) & l_3262) && 0x17F2086DL)) >= g_359[9][0]))))) != l_3792[0][1])) >= l_3017) >= 0xB60DL) == 0x653A7DA3L)) != l_3262)));
                    }
                }
            }
            for (l_3151 = 0; (l_3151 <= 1); l_3151 += 1)
            {
                int16_t l_3827 = 0xA98EL;
                int32_t l_3837 = 0xC79C192DL;
                uint8_t l_3870 = 251UL;
                int32_t l_3892 = 0x9B48DECCL;
                uint32_t l_3910 = 1UL;
                int8_t l_3927 = 0x16L;
                for (l_3534 = 0; (l_3534 <= 5); l_3534 += 1)
                {
                    int32_t l_3828 = 0x3079516EL;
                    int i;
                    l_3828 = (l_3827 = (l_3874[(l_3151 + 4)] ^ (safe_mod_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((safe_add_func_int16_t_s_s((!l_3240[(l_3151 + 4)]), ((l_4035 = 3L) >= (((l_3822 = 1L) >= ((safe_sub_func_int8_t_s_s(0L, (safe_lshift_func_int8_t_s_u(0x39L, 4)))) != l_3573[1])) ^ ((0x2E9DL != l_3807[0]) || g_1129))))), g_543[1])), 0x755FL)) <= g_172[4]), g_2177[1][3][3]))));
                    for (g_1524 = 0; (g_1524 <= 1); g_1524 += 1)
                    {
                        int i, j, k;
                        l_3732 = ((safe_rshift_func_int16_t_s_s(((((-1L) == ((((safe_sub_func_int32_t_s_s(0x814AF06EL, ((safe_mod_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(((l_3755[l_3151][l_3151][(l_3151 + 4)] != l_3837) <= (safe_unary_minus_func_uint16_t_u(l_3399))), l_4035)), l_3732)) < (l_3534 = (((safe_mod_func_uint32_t_u_u(((l_3017 & (safe_lshift_func_uint8_t_u_s((safe_add_func_uint32_t_u_u(0xFCA458E4L, 0xFAFCB658L)), l_3828))) && 4294967290UL), g_172[3])) | (-1L)) == l_3874[(l_3151 + 4)]))))) | 0x96617425L) && i) & g_359[9][0])) & 0UL) <= 1UL), 5)) || 0x45L);
                        return l_3262;
                    }
                }
                for (l_2692 = 10; (l_2692 != 50); ++l_2692)
                {
                    uint32_t l_3851 = 18446744073709551615UL;
                    int8_t l_3871 = 3L;
                    uint32_t l_3897[8][4][7] = {{{18446744073709551612UL,0xE1836138L,0x850D52E1L,4UL,18446744073709551612UL,18446744073709551615UL,18446744073709551615UL},{0x66203650L,18446744073709551612UL,6UL,18446744073709551612UL,0x66203650L,0x325F3AE1L,4UL},{18446744073709551606UL,0x19A3FC88L,18446744073709551615UL,0x43272F40L,0x3D0A099DL,1UL,0x66203650L},{18446744073709551614UL,18446744073709551606UL,0UL,18446744073709551614UL,18446744073709551612UL,0UL,0UL}},{{18446744073709551606UL,0x43272F40L,6UL,1UL,18446744073709551606UL,18446744073709551615UL,1UL},{0x66203650L,1UL,0x3D0A099DL,0x43272F40L,18446744073709551615UL,0x19A3FC88L,18446744073709551606UL},{1UL,0x850D52E1L,0x3D0A099DL,18446744073709551615UL,0x2C9ACB3CL,18446744073709551615UL,0x3D0A099DL},{18446744073709551612UL,18446744073709551612UL,6UL,0xA92A9589L,0xFD09A0FAL,18446744073709551606UL,4UL}},{{0xA92A9589L,18446744073709551615UL,0UL,0UL,0x19A3FC88L,0UL,18446744073709551612UL},{0UL,0x850D52E1L,18446744073709551615UL,0x3D0A099DL,0xFD09A0FAL,0UL,0xB93E9277L},{18446744073709551606UL,4UL,6UL,18446744073709551612UL,0x2C9ACB3CL,0x333F6AB0L,18446744073709551606UL},{0xA92A9589L,0UL,0x1077E5E4L,0x66203650L,18446744073709551615UL,18446744073709551606UL,18446744073709551606UL}},{{18446744073709551615UL,18446744073709551606UL,0x19A3FC88L,0x19A3FC88L,18446744073709551606UL,18446744073709551615UL,0xB93E9277L},{4UL,0UL,0x7FF5CEFEL,0xA92A9589L,18446744073709551612UL,0x4DEDE24EL,18446744073709551612UL},{0x66203650L,18446744073709551615UL,0x37F1B27FL,18446744073709551612UL,0x3D0A099DL,18446744073709551606UL,4UL},{0UL,0UL,18446744073709551615UL,0UL,0x66203650L,1UL,0x3D0A099DL}},{{1UL,18446744073709551606UL,18446744073709551615UL,1UL,18446744073709551612UL,0x87551765L,18446744073709551606UL},{18446744073709551606UL,0UL,18446744073709551615UL,1UL,0UL,0UL,1UL},{0x3D0A099DL,4UL,0x3D0A099DL,0UL,18446744073709551612UL,0x19A3FC88L,0UL},{4UL,0x850D52E1L,0xE1836138L,18446744073709551612UL,0x2C9ACB3CL,6UL,0x66203650L}},{{18446744073709551612UL,18446744073709551615UL,18446744073709551615UL,0xA92A9589L,0x1077E5E4L,0x19A3FC88L,4UL},{0xB93E9277L,18446744073709551612UL,0UL,0x19A3FC88L,0UL,0UL,18446744073709551615UL},{18446744073709551606UL,0x850D52E1L,0x4DEDE24EL,0x66203650L,0xFD09A0FAL,0x87551765L,0xA92A9589L},{18446744073709551606UL,1UL,0x37F1B27FL,18446744073709551612UL,0x37F1B27FL,1UL,18446744073709551606UL}},{{0xB93E9277L,0x43272F40L,0x1077E5E4L,0x3D0A099DL,18446744073709551612UL,18446744073709551606UL,0UL},{18446744073709551612UL,18446744073709551606UL,18446744073709551606UL,0UL,18446744073709551606UL,0x4DEDE24EL,0xA92A9589L},{4UL,0x19A3FC88L,0x1077E5E4L,0xA92A9589L,18446744073709551615UL,18446744073709551615UL,18446744073709551612UL},{0x3D0A099DL,18446744073709551612UL,0x37F1B27FL,18446744073709551615UL,0x66203650L,18446744073709551606UL,0UL}},{{0x3D0A099DL,0UL,18446744073709551612UL,18446744073709551606UL,0x19A3FC88L,0xA92A9589L,0x19A3FC88L},{18446744073709551615UL,0x32647471L,0x32647471L,18446744073709551615UL,0x333F6AB0L,0x325F3AE1L,0x3D0A099DL},{0xE1836138L,18446744073709551606UL,0x333F6AB0L,0x4DEDE24EL,18446744073709551614UL,0x32647471L,0x4DEDE24EL},{0x19A3FC88L,0xB93E9277L,0UL,18446744073709551606UL,18446744073709551615UL,18446744073709551606UL,0x3D0A099DL}}};
                    int32_t l_3916 = (-1L);
                    int i, j, k;
                    if ((((((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((l_3851 != (((l_3667 = (l_3812 = (l_3667 = (-7L)))) & ((0x1404L == 0xBA1BL) <= ((-8L) ^ (((l_3872 = (safe_rshift_func_int16_t_s_u((l_3262 && (safe_mod_func_uint16_t_u_u((((((safe_sub_func_int32_t_s_s((safe_add_func_int32_t_s_s(((safe_mod_func_int16_t_s_s((l_2601 = (((((l_3851 ^ (safe_mod_func_int32_t_s_s((safe_add_func_uint32_t_u_u(g_543[1], (safe_mod_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((0x6EL >= g_172[4]), l_3870)), g_866[4][9])))), g_1524))) < 0xBD537FA9L) > 0UL) | l_3851) < 65532UL)), 8L)) | l_2294), l_2408[1][0])), l_3262)) > g_1460) > l_3822) | l_3424[1][1][4]) && l_3871), 1L))), l_3808))) == (-5L)) | l_3873)))) & l_3808)), 2)), 0x0BL)) == l_3874[8]) <= l_3874[0]) <= l_3667) >= l_3807[6]))
                    {
                        l_3892 = (safe_sub_func_uint32_t_u_u(((l_2841 != (l_2601 = (((safe_mod_func_uint8_t_u_u((g_1460 & (l_3891 = (safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_s(65534UL, 15)) == (g_813[5][0] = ((safe_add_func_uint8_t_u_u(((((g_359[9][0] && (safe_lshift_func_uint8_t_u_s(l_3780, 2))) <= l_3851) <= l_3874[2]) != 1UL), ((safe_add_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u((l_2465 = l_3796), g_1524)) == l_3755[0][0][5]), g_1460)) & l_3262))) || 0xD0F0L))), l_3871)))), 1L)) & l_2266[3]) < l_3874[4]))) & l_3871), l_3808));
                    }
                    else
                    {
                        return l_3240[3];
                    }
                    for (l_2294 = 0; (l_2294 <= 27); l_2294++)
                    {
                        uint32_t l_3907 = 4294967295UL;
                        l_3808 = g_1460;
                        l_3262 = ((safe_sub_func_uint32_t_u_u(0xBE8ABD83L, (((g_2177[3][1][9] = (l_3897[2][0][0] = g_1524)) ^ (((l_3910 = (((safe_mod_func_int16_t_s_s((safe_add_func_uint16_t_u_u((((((~65535UL) > l_3262) == l_3892) != l_2294) < (((safe_rshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s(l_3907, 1L)), 4)) == (l_3908 = (-6L))) < l_3210)), l_3851)), l_3909[0][0])) && l_3262) <= 0x9386A289L)) > l_3874[2]) >= l_2296)) | 0x77F0A1CDL))) < l_3017);
                    }
                    l_3262 = (safe_add_func_uint32_t_u_u((l_3210 = ((+((((l_3916 = (safe_rshift_func_int8_t_s_u((-10L), 7))) && ((safe_unary_minus_func_int16_t_s((1L && (safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u((g_3261 < ((g_172[4] >= (0xBEL && (l_2790[4][0] >= ((3L < (safe_sub_func_int8_t_s_s((((safe_sub_func_int16_t_s_s((((((~l_3796) >= l_3927) < l_3732) && g_3261) | l_3240[4]), 0x3FC3L)) && 0x9294L) & l_3026), l_2601))) == l_3534)))) == l_3891)), l_3262)), l_3667))))) == g_1460)) & l_3017) > g_3261)) && l_3910)), g_2710));
                    return l_3780;
                }
                if (g_2177[4][0][3])
                    continue;
            }
        }
        l_3780 = g_949[0][8][6];
        if ((l_3707 = (safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(3L, 11)), (safe_lshift_func_uint8_t_u_u(l_2692, (safe_add_func_int32_t_s_s((l_3937 = (l_2294 = (safe_unary_minus_func_int32_t_s((l_3908 = ((4294967288UL > ((l_3534 = 0x2816L) | l_3732)) & (l_2692 && g_359[9][0]))))))), ((6UL == ((0x973FL <= l_2465) && l_2418[5][4])) > g_359[9][0])))))))))
        {
            l_3772[2][2][0] = l_3873;
            l_2294 = (0L & 0x34L);
        }
        else
        {
            int32_t l_3960 = (-4L);
            int8_t l_3991[1][5] = {{(-9L),(-9L),(-9L),(-9L),(-9L)}};
            int32_t l_4020 = 0x4B3E2823L;
            int i, j;
            for (l_3655 = (-28); (l_3655 < 46); ++l_3655)
            {
                int16_t l_3951 = 0x1704L;
                int32_t l_3955[7][7] = {{0x94E9D490L,(-3L),0xF4171F52L,(-3L),0x94E9D490L,0x94E9D490L,(-3L)},{(-1L),0xB5D7E716L,(-1L),0x3C2EED67L,0x3C2EED67L,(-1L),0xB5D7E716L},{(-3L),(-8L),0xF4171F52L,0xF4171F52L,(-8L),(-3L),(-8L)},{(-1L),0x3C2EED67L,0x3C2EED67L,(-1L),0xB5D7E716L,(-1L),0x3C2EED67L},{0x94E9D490L,0x94E9D490L,(-3L),0xF4171F52L,(-3L),0x94E9D490L,0x94E9D490L},{0xCBAC2FE8L,0x3C2EED67L,1L,0x3C2EED67L,0xCBAC2FE8L,0xCBAC2FE8L,0x3C2EED67L},{(-1L),(-8L),(-1L),(-3L),(-3L),(-1L),(-8L)}};
                int8_t l_4032 = 8L;
                int i, j;
                for (l_2674 = 0; (l_2674 >= 29); l_2674++)
                {
                    uint8_t l_3954 = 0xF9L;
                    l_2692 = (g_813[2][0] != (safe_add_func_uint32_t_u_u(((l_3807[4] & 1UL) > (safe_lshift_func_uint8_t_u_s((!i), 6))), ((0L | (((l_3955[3][0] = (((safe_lshift_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(l_3951, 12)) & (safe_sub_func_int16_t_s_s(g_3261, (g_3261 = (1L <= l_3707))))), l_3954)) | 0xC3L) && 0L)) || 1UL) & l_2886[2])) != l_2465))));
                }
                for (g_3261 = 0; (g_3261 > 34); ++g_3261)
                {
                    uint32_t l_3973 = 0x4C44CE71L;
                    int8_t l_3988[10] = {(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L)};
                    int32_t l_4033 = (-1L);
                    int32_t l_4034 = 0x9751D3BDL;
                    int i;
                    l_3262 = ((((l_2290 ^ (g_1460 = ((l_3960 | (safe_add_func_int8_t_s_s(0x29L, ((safe_add_func_int8_t_s_s(((safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s(l_4035, l_3874[2])), g_949[0][6][1])) == l_3534), ((safe_sub_func_int32_t_s_s(g_1524, ((safe_add_func_int16_t_s_s((1L <= l_2841), l_3707)) && g_172[6]))) != l_3960))) <= 0x1406L)))) ^ 255UL))) == l_3960) <= l_3973) && l_3951);
                    for (l_3752 = 0; (l_3752 <= 8); l_3752 += 1)
                    {
                        uint8_t l_3986 = 0UL;
                        int32_t l_4009[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_4009[i] = 1L;
                        l_3732 = (l_3262 = (l_3988[7] = (safe_add_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((l_3874[l_3752] || 254UL), (safe_rshift_func_int16_t_s_s(l_3873, 11)))) == (((-9L) >= ((((safe_rshift_func_int8_t_s_u(l_2841, (l_3960 && (safe_rshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u(((g_2177[3][1][9] = (((g_1129 || ((l_3822 && ((0x690DL <= l_3909[0][0]) | l_3986)) | l_3987)) && 0x59DE2E1CL) || 0x0ECC5B70L)) < l_3986), 9)), l_3262))))) < l_3874[l_3752]) & l_3026) > l_3986)) > l_3973)), 65533UL))));
                        l_3262 = (g_543[2] == 4294967295UL);
                        l_3262 = (l_2294 = (safe_rshift_func_uint8_t_u_u(l_3991[0][2], (l_3807[0] > (safe_rshift_func_uint16_t_u_s((+(0xF87CL < l_3399)), (l_2601 = (safe_lshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u((((+(1UL <= (safe_sub_func_int8_t_s_s(((l_3937 > (((+(l_4009[1] = ((safe_add_func_uint32_t_u_u(l_3874[8], (safe_rshift_func_uint8_t_u_u((g_1524 & (l_3991[0][2] && l_4035)), l_3874[l_3752])))) ^ l_3683))) & g_359[9][0]) >= l_2674)) | l_3262), 0x23L)))) == l_2296) >= l_2465), l_3988[2])), l_3937)), 6)))))))));
                    }
                    for (l_3116 = 0; (l_3116 < 12); l_3116 = safe_add_func_int32_t_s_s(l_3116, 7))
                    {
                        return g_1524;
                    }
                    l_2886[1] = (safe_lshift_func_int16_t_s_s((l_3960 != ((l_3262 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_uint8_t_u_u((safe_mod_func_int16_t_s_s((l_4020 = (g_543[2] = 0x7667L)), (((safe_add_func_int16_t_s_s((l_3988[6] ^ (l_4034 = (l_4033 = (((safe_sub_func_uint8_t_u_u(g_1129, l_3955[3][0])) & ((safe_add_func_uint16_t_u_u(((1UL >= l_3262) || ((safe_unary_minus_func_int16_t_s(g_2177[3][1][9])) | (safe_rshift_func_uint8_t_u_u(((((safe_sub_func_uint32_t_u_u(((((-1L) < g_1129) | 248UL) || l_3991[0][3]), l_3534)) > l_3991[0][2]) & l_4032) & l_2674), l_3667)))), g_1460)) != g_1524)) || 248UL)))), l_3960)) <= 0x3193CC09L) | l_3991[0][1]))), l_3955[4][6])), 0))) || l_4034)), l_3873));
                }
            }
        }
    }
    return l_4035;
}

                    for (j = 0; j < 5; j++)
                    l_3255[i][j] = 0x74B9L;
            }
            if ((safe_sub_func_uint16_t_u_u((l_3204 || (safe_add_func_uint32_t_u_u(((((((l_2790[4][0] || ((((l_3534 != ((l_3256[1][3] = (l_3721 >= (l_3072 = (g_2476 = (l_3721 = (((safe_sub_func_int32_t_s_s(((((safe_mod_func_uint8_t_u_u(((((l_3240[2] & ((l_3072 = (l_2840 = (safe_add_func_uint16_t_u_u(l_3204, (65529UL != ((l_2978 & ((safe_add_func_int8_t_s_s(3L, g_1215[1])) <= l_3255[1][3])) != 0x21FD1DCEL)))))) < (-8L))) >= 0xBAL) != l_2918) > l_5[3][0]), g_3152)) < 0L) & l_3655) ^ 0xA4EBL), 0xA9004A2AL)) > g_813[3][0]) != l_3255[1][3])))))) > l_3255[1][3])) & g_543[0]) >= l_2918) ^ 1L)) != 0L) & l_3534) ^ l_3683) & g_540) | l_3255[0][4]), 1UL))), g_2476)))
            {
                uint32_t l_3263 = 4294967295UL;
                int32_t l_3303 = 0L;
                for (l_3655 = 0; (l_3655 != 43); l_3655++)
                {
                    uint32_t l_3304 = 0xA0CD230EL;
                    int32_t l_3305[2][8][1] = {{{0xC3B07C44L},{0xC3B07C44L},{0x80AED170L},{0xAF71240FL},{0x9433F045L},{0xAF71240FL},{0x80AED170L},{0xC3B07C44L}},{{0xC3B07C44L},{0x80AED170L},{0xAF71240FL},{0x9433F045L},{0xAF71240FL},{0x80AED170L},{0xC3B07C44L},{0xC3B07C44L}}};
                    int i, j, k;
                    g_247 = (g_3261 <= l_3408);
                    l_3263 = 0x3D7DBF13L;
                    if (g_2177[1][0][6])
                    {
                        return g_361;
                    }
                    else
                    {
                        uint8_t l_3287 = 5UL;
                        l_3305[0][3][0] = (((safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((l_2465 = ((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s((safe_unary_minus_func_int16_t_s((((safe_add_func_int16_t_s_s((l_3240[3] = l_3255[2][2]), ((safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(((safe_add_func_int32_t_s_s(((safe_mod_func_uint16_t_u_u((l_3256[1][3] = ((safe_sub_func_int32_t_s_s((g_2476 = 1L), (safe_lshift_func_int16_t_s_s(((0x83DAL <= (g_2177[3][1][9] > (l_3287 | 1UL))) <= (((safe_sub_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u((((safe_rshift_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(((l_3303 = (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_uint32_t_u((((safe_add_func_uint16_t_u_u(((l_3256[1][3] < l_3287) < ((safe_sub_func_int32_t_s_s(l_3287, 7UL)) && g_3261)), l_3721)) >= 0x318768DEL) && l_3263))), 9))) != l_3204), l_3256[1][6])), 4)) >= l_3304) | l_3153), l_3287)) ^ g_2476), 0L)) ^ 0x51L) != l_3026)), 15)))) >= l_3287)), (-1L))) && g_2177[5][1][8]), g_813[6][0])) ^ 0xAFL), l_3026)), l_3721)) >= 0x34L))) == g_359[9][2]) | g_1215[4]))), l_3741)), l_3408)) == l_3255[0][1])), 4)), 6)) || 4UL) | l_3287);
                    }
                }
                for (l_3204 = 0; (l_3204 <= (-20)); l_3204 = safe_sub_func_uint8_t_u_u(l_3204, 5))
                {
                    l_3072 = (g_359[9][0] ^ (l_3153 != (((safe_rshift_func_uint16_t_u_u(9UL, (safe_sub_func_int16_t_s_s((g_543[1] = 0x560CL), (safe_lshift_func_int16_t_s_s((!l_3303), 7)))))) > ((l_3721 && ((l_2266[3] = 65535UL) != (l_3683 & (l_3721 = ((-10L) > 0xD9890121L))))) > l_3204)) | l_3256[1][3])));
                    l_3303 = 0x9ED79E98L;

l_3257 += 1;


                    g_2476 = (l_3256[1][2] = (l_3072 = (0x6A45L != (l_2774 = (-1L)))));
                    g_2476 = 0xA5D6E7B4L;
                }
                for (l_3072 = (-29); (l_3072 < 29); l_3072++)
                {
                    int32_t l_3319 = 4L;
                    for (l_2918 = 1; (l_2918 <= 7); l_2918 += 1)
                    {
                        int i, j;
                        return g_866[l_2918][(l_2918 + 1)];
                    }

if ((+(safe_add_func_int32_t_s_s((l_2408[3][4] = (((g_538 || (safe_sub_func_uint16_t_u_u(((l_2266[3] = (g_540 ^ (safe_add_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((~((safe_lshift_func_int8_t_s_s((((l_3072 = g_538) <= (((safe_add_func_uint8_t_u_u((((0xADFAL <= g_315) & (l_2978 && l_3109)) < (-2L)), ((g_3258 < g_315) ^ g_115))) < 7UL) ^ l_2266[3])) | g_115), g_12)) || l_5[1][6])), l_2978)), 0x16L)))) || g_3258), 0x5C64L))) >= g_1215[3]) & l_2290)), l_2943))))
    {
        int32_t l_3561 = 0xC7A6A094L;
        int32_t l_3562[7];
        int32_t l_3639 = 0x57E1FCD6L;
        int i;
        for (i = 0; i < 7; i++)
            l_3562[i] = 0xF6374F20L;
        if ((safe_rshift_func_uint16_t_u_s((l_3204 < (safe_sub_func_uint8_t_u_u((l_2896 = (safe_sub_func_uint16_t_u_u(((l_3561 = 0xFE00L) > l_3562[1]), g_866[5][2]))), ((safe_rshift_func_int8_t_s_s((safe_sub_func_int16_t_s_s(g_813[1][0], ((j >= (safe_add_func_uint32_t_u_u(((safe_mul_func_int32_t_s_s((l_2290 = (((0UL > ((g_315 > ((safe_add_func_int8_t_s_s((j <= 0xAE4AL), 0x0CL)) >= 255UL)) ^ 0xBAED8CF2L)) == g_12) && 0L)), 0L)) || l_3562[1]), 0xFBC96193L))) == (-9L)))), 6)) == g_22)))), l_3573[1])))
        {
            l_3562[1] = 1L;
        }
        else
        {
            int16_t l_3588 = 9L;
            int32_t l_3622[9][5] = {{3L,0x6BA56314L,1L,0x10275A46L,0L},{0x10275A46L,(-7L),4L,4L,(-7L)},{0L,1L,5L,4L,0x99AB53BFL},{1L,0x99AB53BFL,0x528214A4L,0x10275A46L,0x6BA56314L},{1L,(-10L),0L,0x6BA56314L,0x888D88CAL},{1L,1L,0x888D88CAL,1L,1L},{0L,0x366C108CL,0x888D88CAL,0L,1L},{0x10275A46L,8L,0L,5L,3L},{3L,1L,0x528214A4L,0x366C108CL,1L}};
            uint16_t l_3664 = 8UL;
            int i, j;
            for (l_2954 = 2; (l_2954 >= 7); ++l_2954)
            {
                uint8_t l_3587[6];
                int32_t l_3614 = 0x78771F22L;
                int32_t l_3615[3];
                int i;
                for (i = 0; i < 6; i++)
                    l_3587[i] = 248UL;
                for (i = 0; i < 3; i++)
                    l_3615[i] = 0x1058D4E6L;
                j = (0x2024L >= (safe_rshift_func_int16_t_s_u((0xA3L && 0x6BL), l_3561)));
                l_2290 = (l_2896 <= ((((l_2408[3][0] = (safe_rshift_func_uint8_t_u_u(((safe_add_func_int32_t_s_s((0x3CA5L >= ((safe_mod_func_uint8_t_u_u(0x91L, l_3562[5])) >= l_3562[1])), (1L | 0x184E7879L))) != l_2816), ((safe_rshift_func_uint16_t_u_u((~(g_813[4][0] = 2UL)), l_3561)) | l_3587[3])))) && 0x2CB018B9L) & l_3153) == l_3588));
                g_247 = g_3258;
                l_3615[2] = ((((g_361 = (((safe_sub_func_int8_t_s_s((-2L), (safe_rshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u(7UL, ((255UL != (safe_sub_func_int32_t_s_s((safe_mod_func_uint32_t_u_u(((g_2352[2] ^ (0xC0D53A6EL | (l_3614 = (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_int32_t_s((((g_538 & (safe_sub_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s(((((safe_lshift_func_uint16_t_u_u((safe_add_func_int8_t_s_s((l_3204 ^ g_3781), (l_2266[3] = ((safe_lshift_func_int16_t_s_u((g_2177[3][0][1] | 0L), g_1524)) == 7L)))), l_3408)) > 0x266CL) >= g_1524) <= g_3261), 2)) == 0L), 0UL)), 1UL))) >= l_3204) != (-1L)))), 11))))) ^ l_3072), l_3562[6])), l_3424[1][0][0]))) >= 0x63A0L))), l_3587[4])))) & l_3587[5]) | g_538)) ^ 254UL) <= l_3424[1][2][3]) || l_3614);
            }
            g_3484 = g_2177[3][1][9];
            j = (safe_unary_minus_func_uint8_t_u(1UL));
            if (g_172[7])
            {
                uint16_t l_3621 = 8UL;
                uint16_t l_3638[10][1][6] = {{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}}};
                int32_t l_3656 = 0x6C16DA66L;
                uint16_t l_3666 = 65535UL;
                int32_t l_3681 = 0L;
                int i, j, k;
                g_22 = g_247;
                l_3622[1][1] = ((1UL | (safe_mod_func_int16_t_s_s((l_2290 & l_3588), l_3562[1]))) == (g_2177[3][1][9] = (safe_lshift_func_int8_t_s_u(l_3621, 5))));
                if ((safe_add_func_int8_t_s_s((l_3204 = (l_4035 = (safe_lshift_func_uint8_t_u_u(((~0xACL) || (((g_1524 && (safe_mod_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(((-1L) ^ (g_247 = ((g_813[3][0] == (l_3621 & g_3152)) <= g_315))), (safe_rshift_func_int8_t_s_u(((((safe_unary_minus_func_int8_t_s(((l_3561 ^ (l_3638[4][0][5] = (!(l_3204 = (251UL | 1UL))))) & l_2290))) | 0x6828710FL) || g_359[4][4]) > g_247), l_3204)))) < g_3261), l_3588))) & 0xA5L) != g_540)), l_3639)))), 0L)))
                {
                    int16_t l_3668 = 4L;
                    if ((0x58A82B72L | (safe_sub_func_int16_t_s_s(g_2177[3][1][9], (1L < g_2177[4][3][0])))))
                    {
                        uint32_t l_3663 = 0xB87B213BL;
                        int32_t l_3665 = 0x38F15173L;
                        l_3668 = (g_3781 = (0x9C031653L > ((((safe_sub_func_uint32_t_u_u((~(g_538 ^ ((((safe_mod_func_uint8_t_u_u((g_2177[3][1][9] > (safe_sub_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u(l_3621, (l_2290 && (l_3408 == (g_866[0][1] = (l_3656 = 0L)))))) || (safe_lshift_func_int16_t_s_s((safe_add_func_int16_t_s_s(l_2954, (((l_3663 = (4294967295UL ^ 0xC8C7ECD9L)) == 0x67EB8C8CL) <= 0L))), 14))) >= l_3664), 11)) == l_3204), 3)) == l_3665), l_3622[1][1]))), 0x4AL)) == g_2352[2]) && 0x4BL) & g_359[4][4]))), l_3622[3][4])) == (-1L)) && g_22) < l_3666)));
                        l_2290 = 1L;
                    }
                    else
                    {
                        int32_t l_3686 = 0x5209DBEDL;
                        int32_t l_3687 = 0L;
                        l_2290 = ((safe_rshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((((-10L) < (safe_lshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((((safe_rshift_func_uint16_t_u_u((g_315 = (((l_3681 != (0xD32132F5L <= (g_172[1] < (!l_2858)))) || 0UL) <= g_4)), (0xA83222B9L || ((safe_sub_func_int16_t_s_s((l_3622[8][3] <= g_543[1]), l_3686)) & (-5L))))) < g_1524) & g_1524), g_247)) <= (-1L)), 6))) >= l_3687), l_2290)), 8UL)), 2)) | g_172[0]);
                    }
                    for (l_3153 = 0; (l_3153 == 4); l_3153 = safe_add_func_uint32_t_u_u(l_3153, 4))
                    {
                        return l_3656;
                    }
                    for (g_538 = 0; (g_538 <= 4); g_538 += 1)
                    {
                        int i;
                        l_2290 = (safe_add_func_uint8_t_u_u(l_2266[g_538], (safe_lshift_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((8L == (l_3656 = ((l_2266[g_538] && g_172[4]) < g_2177[5][2][8]))), (g_315 = (g_315 = (l_2954 || 0x4FL))))), 4))));
                        if (l_2858)
                            break;
                    }
                    g_538 = (6UL && (l_3204 & (l_3639 = ((((safe_sub_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_s((((l_3562[1] && 9L) > (0xE5F008A1L <= ((g_247 = (-10L)) <= (safe_mod_func_int8_t_s_s(g_359[6][3], (l_2896 = l_2790[0][0])))))) >= g_1215[4]), g_540)) ^ 0xD6L), 0x64C4L)) & l_3668) == l_3656) & l_3668))));
                }
                else
                {
                    for (g_103 = 0; (g_103 != 42); g_103++)
                    {
                        l_2266[2] = g_3261;
                    }
                    return g_538;
                }
            }
            else
            {
                return l_2978;
            }
        }
        l_3873 = ((safe_lshift_func_int8_t_s_u(((l_3562[0] >= g_866[4][0]) != (l_2896 = (g_1524 > l_2954))), l_3873)) > 0x3DD2L);
        j = ((((safe_sub_func_uint16_t_u_u((((safe_rshift_func_uint16_t_u_u(l_3562[0], (safe_mod_func_uint8_t_u_u((safe_add_func_uint32_t_u_u(((g_22 = (safe_rshift_func_int16_t_s_u((-2L), ((g_172[1] = 65528UL) < l_3562[1])))) > (safe_lshift_func_int16_t_s_u(((((~g_2177[1][2][6]) | ((l_2296 || l_2296) >= (0x0FL ^ j))) | l_3639) >= g_866[4][0]), g_2352[2]))), g_4)), g_538)))) < g_12) & g_3261), l_3562[1])) != 1UL) && l_2418[5][4]) ^ l_3492);
    }
    else
    {
        int32_t l_3732 = 5L;
        int32_t l_3772[9][5][4] = {{{(-5L),0x53797119L,(-1L),0xEC1AA655L},{(-3L),0x0BED20CAL,0x620E126EL,0x64D60197L},{0x620E126EL,0x64D60197L,(-1L),(-1L)},{0x9C8EED80L,0x08C26BBCL,(-1L),(-7L)},{(-1L),(-1L),0x5187487DL,(-1L)}},{{(-1L),0x5187487DL,0x5187487DL,0x08C26BBCL},{0L,0x3A0636EDL,0x227DF413L,0L},{(-1L),(-1L),0x53797119L,0x5A84B327L},{(-1L),0x08C26BBCL,0x3C72134DL,0x5A84B327L},{0L,(-1L),0x5B09E585L,0L}},{{0x64D60197L,0x3A0636EDL,0xEC1AA655L,0x08C26BBCL},{0x6CA574B2L,0x5187487DL,(-1L),0xC7C31EEAL},{0x620E126EL,(-1L),(-1L),(-5L)},{(-1L),0xEC1AA655L,0x9C8EED80L,0x0BED20CAL},{0x3A0636EDL,(-1L),0x620E126EL,(-1L)}},{{1L,(-1L),(-3L),0L},{0x5A84B327L,0L,(-5L),0x9C8EED80L},{0x9C8EED80L,4L,0L,8L},{0x9C8EED80L,(-7L),(-5L),0x2F85340DL},{0x5A84B327L,8L,(-3L),0L}},{{1L,0L,0x620E126EL,0x53797119L},{0x3A0636EDL,0xB8D39A8AL,0x9C8EED80L,(-1L)},{(-1L),0x64D60197L,(-1L),0x3FDD2651L},{0x620E126EL,0x5B09E585L,(-1L),(-1L)},{0x6CA574B2L,0x6CA574B2L,0xEC1AA655L,4L}},{{0x64D60197L,0x2F85340DL,0x5B09E585L,0x3A0636EDL},{0L,(-1L),0x3C72134DL,0x5B09E585L},{(-1L),(-1L),0x53797119L,0x3A0636EDL},{(-1L),0x2F85340DL,0x227DF413L,4L},{0L,0x6CA574B2L,0x5187487DL,(-1L)}},{{0x08C26BBCL,0x5B09E585L,0x6CA574B2L,0x3FDD2651L},{(-7L),0x64D60197L,0x0BED20CAL,(-1L)},{(-3L),0xB8D39A8AL,(-1L),0x53797119L},{8L,0L,8L,0L},{(-1L),8L,0xC7C31EEAL,0x2F85340DL}},{{0x53797119L,(-7L),0x3A0636EDL,8L},{(-1L),4L,0x3A0636EDL,0x9C8EED80L},{0x53797119L,0L,0xC7C31EEAL,0L},{(-1L),(-1L),8L,(-1L)},{8L,(-1L),(-1L),0x0BED20CAL}},{{(-3L),0xEC1AA655L,0x0BED20CAL,(-5L)},{(-7L),(-1L),0x6CA574B2L,0xC7C31EEAL},{0x08C26BBCL,0x5187487DL,0x5187487DL,0x08C26BBCL},{0L,0x3A0636EDL,0x227DF413L,0L},{(-1L),(-1L),0x53797119L,0x5A84B327L}}};
        int32_t l_3780 = 1L;
        uint32_t l_3807[8] = {0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL};
        int16_t l_3822 = 0xB624L;
        uint32_t l_3909[7][2] = {{4294967295UL,0xDBB9B69CL},{0xDA67836AL,0xDBB9B69CL},{4294967295UL,0xA3043AE8L},{0xA3043AE8L,4294967295UL},{0xDBB9B69CL,0xDA67836AL},{0xDBB9B69CL,4294967295UL},{0xA3043AE8L,0xA3043AE8L}};
        uint32_t l_3937 = 9UL;
        int32_t l_3987 = 0x7570AEB1L;
        int i, j, k;
        l_3732 = (safe_add_func_int32_t_s_s(l_2408[3][0], (safe_rshift_func_uint8_t_u_u(((((safe_rshift_func_uint8_t_u_s(((((-10L) != (safe_mod_func_uint32_t_u_u(((-9L) > ((1L < (safe_lshift_func_int16_t_s_u(l_3732, (safe_rshift_func_uint16_t_u_u(l_2408[2][1], 2))))) != (safe_rshift_func_int16_t_s_u(((safe_rshift_func_uint16_t_u_s(g_1215[5], 5)) | (l_3732 || ((safe_add_func_int16_t_s_s(l_2290, 0x51BCL)) <= 0x9FL))), g_3484)))), 0x6935AA16L))) || g_2352[2]) != l_3683), 5)) && l_3732) && l_3732) > l_2840), l_3732))));
        if ((((g_2352[2] < (((safe_rshift_func_int16_t_s_s((((((safe_sub_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(0x91L)), (g_2710 = 255UL))) && (g_949[0][6][1] & (safe_add_func_int32_t_s_s(((safe_unary_minus_func_int16_t_s((-1L))) && (safe_rshift_func_int16_t_s_s(((((l_2290 = l_2408[3][0]) > ((l_3755[0][0][5] = ((g_12 = (l_2896 = 255UL)) ^ ((l_2943 != (((+((safe_unary_minus_func_uint16_t_u(((g_2710 && l_3492) < 9UL))) <= l_4035)) > l_3732) & l_3109)) == l_2266[3]))) || l_3732)) == l_3732) || 7L), l_4035))), l_3873)))) == 0x1476L) & l_2943) & 4294967295UL), l_3732)) || 1UL) && 0x51L)) & g_2352[8]) | l_3408))
        {
            int32_t l_3782 = (-1L);
            int32_t l_3783 = (-1L);
            uint32_t l_3784[6] = {1UL,0x277AD475L,1UL,1UL,0x277AD475L,1UL};
            int i;
            l_2290 = (((l_3732 = (g_2177[0][1][6] > 65535UL)) ^ (safe_mod_func_uint8_t_u_u(((g_361 = (safe_rshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_u((g_315 = (safe_lshift_func_uint8_t_u_u(255UL, (0UL > (l_3784[4] = (safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(l_2290, 3)), (((l_3783 = (safe_lshift_func_uint8_t_u_s((l_3772[0][4][0] <= ((l_3873 = ((((safe_lshift_func_int8_t_s_u((l_4035 = g_3261), 2)) != ((((safe_lshift_func_int16_t_s_u((g_543[1] = (((((((65534UL || (g_361 = (safe_add_func_int16_t_s_s((l_2943 ^ l_3780), l_3204)))) || (-1L)) ^ l_3408) == l_3782) || l_3782) ^ l_3755[0][1][1]) == g_543[1])), 2)) ^ g_538) == l_3782) <= g_2177[4][1][2])) && g_315) <= 0xCEL)) != 0UL)), 4))) || l_3492) && g_813[0][0])))))))), l_2418[3][4])), 1)), g_12))) | l_2266[4]), 0xE6L))) ^ g_2352[6]);
            g_22 = 0x9DF8728DL;
        }
        else
        {
            uint32_t l_3796 = 18446744073709551615UL;
            int32_t l_3808 = (-1L);
            int32_t l_3812 = 0x5C3FB331L;
            for (l_3204 = 0; (l_3204 <= (-26)); l_3204 = safe_sub_func_uint32_t_u_u(l_3204, 4))
            {
                int32_t l_3789 = 0L;
                int32_t l_3793 = 0L;
                for (l_4035 = 0; (l_4035 != 4); l_4035 = safe_add_func_int32_t_s_s(l_4035, 2))
                {
                    int32_t l_3792[2][4];
                    int i, j;
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 4; j++)
                            l_3792[i][j] = 1L;
                    }
                    if ((((l_3789 <= (safe_sub_func_int16_t_s_s((0x931ABD91L > (l_3793 = l_3792[1][0])), (l_3796 | (g_2710 == (l_2842 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(g_3781, 1)), 5)), j)))))))) > (~(((g_172[5] ^ (safe_mod_func_uint8_t_u_u((~g_3261), l_3807[1]))) > l_3808) && l_2954))) <= 0x50BC1107L))
                    {
                        l_2290 = (g_22 = (0x9D645515L | (l_3792[1][3] && (l_3792[1][2] = ((+g_361) <= g_12)))));
                    }
                    else
                    {
                        l_3812 = (j = (0L & ((g_538 | ((((g_12 || ((g_2177[1][1][3] = (l_3808 == (l_2978 = (65535UL != (((g_3261 = l_3796) < ((((safe_unary_minus_func_uint8_t_u(((l_2896 ^ ((+l_3573[1]) != l_3109)) > l_3408))) <= 8L) & j) && 0x17F2086DL)) >= g_359[9][0]))))) != l_3792[0][1])) >= g_3152) >= 0xB60DL) == 0x653A7DA3L)) != l_3873)));
                    }
                }
            }
            for (l_2674 = 0; (l_2674 <= 1); l_2674 += 1)
            {
                int16_t l_3827 = 0xA98EL;
                int32_t l_3837 = 0xC79C192DL;
                uint8_t l_3870 = 251UL;
                int32_t l_3892 = 0x9B48DECCL;
                uint32_t l_3910 = 1UL;
                int8_t l_3927 = 0x16L;
                for (g_538 = 0; (g_538 <= 5); g_538 += 1)
                {
                    int32_t l_3828 = 0x3079516EL;
                    int i;
                    l_3828 = (l_3827 = (g_2352[(l_2674 + 4)] ^ (safe_mod_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((safe_add_func_int16_t_s_s((!g_1215[(l_2674 + 4)]), ((l_3204 = 3L) >= (((l_3822 = 1L) >= ((safe_sub_func_int8_t_s_s(0L, (safe_lshift_func_int8_t_s_u(0x39L, 4)))) != l_3573[1])) ^ ((0x2E9DL != l_3807[0]) || g_12))))), g_543[1])), 0x755FL)) <= g_172[4]), g_2177[1][3][3]))));
                    for (l_2978 = 0; (l_2978 <= 1); l_2978 += 1)
                    {
                        int i, j, k;
                        l_3732 = ((safe_rshift_func_int16_t_s_s(((((-1L) == ((((safe_sub_func_int32_t_s_s(0x814AF06EL, ((safe_mod_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(((l_3755[l_2674][l_2674][(l_2674 + 4)] != l_3837) <= (safe_unary_minus_func_uint16_t_u(l_2841))), l_3204)), l_3732)) < (g_3261 = (((safe_mod_func_uint32_t_u_u(((g_3152 & (safe_lshift_func_uint8_t_u_s((safe_add_func_uint32_t_u_u(0xFCA458E4L, 0xFAFCB658L)), l_3828))) && 4294967290UL), g_172[3])) | (-1L)) == g_2352[(l_2674 + 4)]))))) | 0x96617425L) && g_22) & g_359[9][0])) & 0UL) <= 1UL), 5)) || 0x45L);
                        return l_2290;
                    }
                }
                for (l_2954 = 10; (l_2954 != 50); ++l_2954)
                {
                    uint32_t l_3851 = 18446744073709551615UL;
                    int8_t l_3871 = 3L;
                    uint32_t l_3897[8][4][7] = {{{18446744073709551612UL,0xE1836138L,0x850D52E1L,4UL,18446744073709551612UL,18446744073709551615UL,18446744073709551615UL},{0x66203650L,18446744073709551612UL,6UL,18446744073709551612UL,0x66203650L,0x325F3AE1L,4UL},{18446744073709551606UL,0x19A3FC88L,18446744073709551615UL,0x43272F40L,0x3D0A099DL,1UL,0x66203650L},{18446744073709551614UL,18446744073709551606UL,0UL,18446744073709551614UL,18446744073709551612UL,0UL,0UL}},{{18446744073709551606UL,0x43272F40L,6UL,1UL,18446744073709551606UL,18446744073709551615UL,1UL},{0x66203650L,1UL,0x3D0A099DL,0x43272F40L,18446744073709551615UL,0x19A3FC88L,18446744073709551606UL},{1UL,0x850D52E1L,0x3D0A099DL,18446744073709551615UL,0x2C9ACB3CL,18446744073709551615UL,0x3D0A099DL},{18446744073709551612UL,18446744073709551612UL,6UL,0xA92A9589L,0xFD09A0FAL,18446744073709551606UL,4UL}},{{0xA92A9589L,18446744073709551615UL,0UL,0UL,0x19A3FC88L,0UL,18446744073709551612UL},{0UL,0x850D52E1L,18446744073709551615UL,0x3D0A099DL,0xFD09A0FAL,0UL,0xB93E9277L},{18446744073709551606UL,4UL,6UL,18446744073709551612UL,0x2C9ACB3CL,0x333F6AB0L,18446744073709551606UL},{0xA92A9589L,0UL,0x1077E5E4L,0x66203650L,18446744073709551615UL,18446744073709551606UL,18446744073709551606UL}},{{18446744073709551615UL,18446744073709551606UL,0x19A3FC88L,0x19A3FC88L,18446744073709551606UL,18446744073709551615UL,0xB93E9277L},{4UL,0UL,0x7FF5CEFEL,0xA92A9589L,18446744073709551612UL,0x4DEDE24EL,18446744073709551612UL},{0x66203650L,18446744073709551615UL,0x37F1B27FL,18446744073709551612UL,0x3D0A099DL,18446744073709551606UL,4UL},{0UL,0UL,18446744073709551615UL,0UL,0x66203650L,1UL,0x3D0A099DL}},{{1UL,18446744073709551606UL,18446744073709551615UL,1UL,18446744073709551612UL,0x87551765L,18446744073709551606UL},{18446744073709551606UL,0UL,18446744073709551615UL,1UL,0UL,0UL,1UL},{0x3D0A099DL,4UL,0x3D0A099DL,0UL,18446744073709551612UL,0x19A3FC88L,0UL},{4UL,0x850D52E1L,0xE1836138L,18446744073709551612UL,0x2C9ACB3CL,6UL,0x66203650L}},{{18446744073709551612UL,18446744073709551615UL,18446744073709551615UL,0xA92A9589L,0x1077E5E4L,0x19A3FC88L,4UL},{0xB93E9277L,18446744073709551612UL,0UL,0x19A3FC88L,0UL,0UL,18446744073709551615UL},{18446744073709551606UL,0x850D52E1L,0x4DEDE24EL,0x66203650L,0xFD09A0FAL,0x87551765L,0xA92A9589L},{18446744073709551606UL,1UL,0x37F1B27FL,18446744073709551612UL,0x37F1B27FL,1UL,18446744073709551606UL}},{{0xB93E9277L,0x43272F40L,0x1077E5E4L,0x3D0A099DL,18446744073709551612UL,18446744073709551606UL,0UL},{18446744073709551612UL,18446744073709551606UL,18446744073709551606UL,0UL,18446744073709551606UL,0x4DEDE24EL,0xA92A9589L},{4UL,0x19A3FC88L,0x1077E5E4L,0xA92A9589L,18446744073709551615UL,18446744073709551615UL,18446744073709551612UL},{0x3D0A099DL,18446744073709551612UL,0x37F1B27FL,18446744073709551615UL,0x66203650L,18446744073709551606UL,0UL}},{{0x3D0A099DL,0UL,18446744073709551612UL,18446744073709551606UL,0x19A3FC88L,0xA92A9589L,0x19A3FC88L},{18446744073709551615UL,0x32647471L,0x32647471L,18446744073709551615UL,0x333F6AB0L,0x325F3AE1L,0x3D0A099DL},{0xE1836138L,18446744073709551606UL,0x333F6AB0L,0x4DEDE24EL,18446744073709551614UL,0x32647471L,0x4DEDE24EL},{0x19A3FC88L,0xB93E9277L,0UL,18446744073709551606UL,18446744073709551615UL,18446744073709551606UL,0x3D0A099DL}}};
                    int32_t l_3916 = (-1L);
                    int i, j, k;
                    if ((((((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((l_3851 != (((l_3204 = (l_3812 = (g_361 = (-7L)))) & ((0x1404L == 0xBA1BL) <= ((-8L) ^ (((l_3707 = (safe_rshift_func_int16_t_s_u((l_2290 && (safe_mod_func_uint16_t_u_u((((((safe_sub_func_int32_t_s_s((safe_add_func_int32_t_s_s(((safe_mod_func_int16_t_s_s((g_1524 = (((((l_3851 ^ (safe_mod_func_int32_t_s_s((safe_add_func_uint32_t_u_u(g_543[1], (safe_mod_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((0x6EL >= g_172[4]), l_3870)), g_866[4][9])))), g_1524))) < 0xBD537FA9L) > 0UL) | l_3851) < 65532UL)), 8L)) | g_22), l_2408[1][0])), j)) > g_12) > l_3822) | l_3424[1][1][4]) && l_3871), 1L))), l_3808))) == (-5L)) | l_3873)))) & l_3808)), 2)), 0x0BL)) == g_2352[8]) <= g_2352[0]) <= l_4035) >= l_3807[6]))
                    {
                        l_3892 = (safe_sub_func_uint32_t_u_u(((l_2858 != (g_1524 = (((safe_mod_func_uint8_t_u_u((g_12 & (l_2290 = (safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_s(65534UL, 15)) == (g_813[5][0] = ((safe_add_func_uint8_t_u_u(((((g_359[9][0] && (safe_lshift_func_uint8_t_u_s(l_3780, 2))) <= l_3851) <= g_2352[2]) != 1UL), ((safe_add_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u((g_361 = l_3796), g_1524)) == l_3755[0][0][5]), g_12)) & l_2290))) || 0xD0F0L))), l_3871)))), 1L)) & l_2266[3]) < g_2352[4]))) & l_3871), l_3808));
                    }
                    else
                    {
                        return g_1215[3];
                    }
                    for (l_2296 = 0; (l_2296 <= 27); l_2296++)
                    {
                        uint32_t l_3907 = 4294967295UL;
                        l_3808 = g_12;
                        l_2290 = ((safe_sub_func_uint32_t_u_u(0xBE8ABD83L, (((g_2177[3][1][9] = (l_3897[2][0][0] = g_1524)) ^ (((l_3910 = (((safe_mod_func_int16_t_s_s((safe_add_func_uint16_t_u_u((((((~65535UL) > j) == l_3892) != g_22) < (((safe_rshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s(l_3907, 1L)), 4)) == (l_2296 = (-6L))) < l_3109)), l_3851)), l_3909[0][0])) && l_2290) <= 0x9386A289L)) > g_2352[2]) >= l_2290)) | 0x77F0A1CDL))) < g_3152);
                    }
                    l_2290 = (safe_add_func_uint32_t_u_u((l_3109 = ((+((((l_3916 = (safe_rshift_func_int8_t_s_u((-10L), 7))) && ((safe_unary_minus_func_int16_t_s((1L && (safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u((g_315 < ((g_172[4] >= (0xBEL && (l_2790[4][0] >= ((3L < (safe_sub_func_int8_t_s_s((((safe_sub_func_int16_t_s_s((((((~l_3796) >= l_3927) < l_3732) && g_315) | g_1215[4]), 0x3FC3L)) && 0x9294L) & l_2842), g_1524))) == g_3261)))) == l_2290)), l_2290)), l_3204))))) == g_12)) & g_115) > g_315)) && l_3910)), g_2710));
                    return l_3780;
                }
                if (g_2177[4][0][3])
                    continue;
            }
        }
        l_3780 = g_949[0][8][6];
        if ((g_247 = (safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(3L, 11)), (safe_lshift_func_uint8_t_u_u(l_2954, (safe_add_func_int32_t_s_s((l_3937 = (g_22 = (safe_unary_minus_func_int32_t_s((l_2296 = ((4294967288UL > ((g_3261 = 0x2816L) | l_3732)) & (l_2954 && g_359[9][0]))))))), ((6UL == ((0x973FL <= g_361) && l_2418[5][4])) > g_359[9][0])))))))))
        {
            l_3772[2][2][0] = l_3492;
            g_22 = (0L & 0x34L);
        }
        else
        {
            int32_t l_3960 = (-4L);
            int8_t l_3991[1][5] = {{(-9L),(-9L),(-9L),(-9L),(-9L)}};
            int32_t l_4020 = 0x4B3E2823L;
            int i, j;
            for (l_3408 = (-28); (l_3408 < 46); ++l_3408)
            {
                int16_t l_3951 = 0x1704L;
                int32_t l_3955[7][7] = {{0x94E9D490L,(-3L),0xF4171F52L,(-3L),0x94E9D490L,0x94E9D490L,(-3L)},{(-1L),0xB5D7E716L,(-1L),0x3C2EED67L,0x3C2EED67L,(-1L),0xB5D7E716L},{(-3L),(-8L),0xF4171F52L,0xF4171F52L,(-8L),(-3L),(-8L)},{(-1L),0x3C2EED67L,0x3C2EED67L,(-1L),0xB5D7E716L,(-1L),0x3C2EED67L},{0x94E9D490L,0x94E9D490L,(-3L),0xF4171F52L,(-3L),0x94E9D490L,0x94E9D490L},{0xCBAC2FE8L,0x3C2EED67L,1L,0x3C2EED67L,0xCBAC2FE8L,0xCBAC2FE8L,0x3C2EED67L},{(-1L),(-8L),(-1L),(-3L),(-3L),(-1L),(-8L)}};
                int8_t l_4032 = 8L;
                int i, j;
                for (g_2710 = 0; (g_2710 >= 29); g_2710++)
                {
                    uint8_t l_3954 = 0xF9L;
                    l_2858 = (g_813[2][0] != (safe_add_func_uint32_t_u_u(((l_3807[4] & 1UL) > (safe_lshift_func_uint8_t_u_s((!g_22), 6))), ((0L | (((l_3955[3][0] = (((safe_lshift_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(l_3951, 12)) & (safe_sub_func_int16_t_s_s(g_538, (g_315 = (1L <= g_247))))), l_3954)) | 0xC3L) && 0L)) || 1UL) & l_2266[2])) != g_361))));
                }
                for (g_538 = 0; (g_538 > 34); ++g_538)
                {
                    uint32_t l_3973 = 0x4C44CE71L;
                    int8_t l_3988[10] = {(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L)};
                    int32_t l_4033 = (-1L);
                    int32_t l_4034 = 0x9751D3BDL;
                    int i;
                    j = ((((l_3072 ^ (g_12 = ((l_3960 | (safe_add_func_int8_t_s_s(0x29L, ((safe_add_func_int8_t_s_s(((safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s(l_3204, g_2352[2])), g_949[0][6][1])) == g_538), ((safe_sub_func_int32_t_s_s(g_1524, ((safe_add_func_int16_t_s_s((1L <= l_2858), l_3873)) && g_172[6]))) != l_3960))) <= 0x1406L)))) ^ 255UL))) == l_3960) <= l_3973) && l_3951);
                    for (l_2943 = 0; (l_2943 <= 8); l_2943 += 1)
                    {
                        uint8_t l_3986 = 0UL;
                        int32_t l_4009[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_4009[i] = 1L;
                        l_3732 = (j = (l_3988[7] = (safe_add_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((g_2352[l_2943] || 254UL), (safe_rshift_func_int16_t_s_s(l_3873, 11)))) == (((-9L) >= ((((safe_rshift_func_int8_t_s_u(l_2858, (l_3960 && (safe_rshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u(((g_2177[3][1][9] = (((g_12 || ((l_3822 && ((0x690DL <= l_3909[0][0]) | l_3986)) | l_3987)) && 0x59DE2E1CL) || 0x0ECC5B70L)) < l_3986), 9)), l_2290))))) < g_2352[l_2943]) & l_2842) > l_3986)) > l_3973)), 65533UL))));
                        j = (g_543[2] == 4294967295UL);
                        l_2290 = (g_22 = (safe_rshift_func_uint8_t_u_u(l_3991[0][2], (l_3807[0] > (safe_rshift_func_uint16_t_u_s((+(0xF87CL < l_2841)), (g_1524 = (safe_lshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u((((+(1UL <= (safe_sub_func_int8_t_s_s(((l_3937 > (((+(l_4009[1] = ((safe_add_func_uint32_t_u_u(g_2352[8], (safe_rshift_func_uint8_t_u_u((g_1524 & (l_3991[0][2] && l_3204)), g_2352[l_2943])))) ^ l_3204))) & g_359[9][0]) >= g_2710)) | l_2290), 0x23L)))) == l_2290) >= g_361), l_3988[2])), l_3937)), 6)))))))));
                    }
                    for (g_3258 = 0; (g_3258 < 12); g_3258 = safe_add_func_int32_t_s_s(g_3258, 7))
                    {
                        return g_1524;
                    }
                    l_2266[1] = (safe_lshift_func_int16_t_s_s((l_3960 != ((l_3873 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_uint8_t_u_u((safe_mod_func_int16_t_s_s((l_4020 = (g_543[2] = 0x7667L)), (((safe_add_func_int16_t_s_s((l_3988[6] ^ (l_4034 = (l_4033 = (((safe_sub_func_uint8_t_u_u(g_12, l_3955[3][0])) & ((safe_add_func_uint16_t_u_u(((1UL >= l_2290) || ((safe_unary_minus_func_int16_t_s(g_2177[3][1][9])) | (safe_rshift_func_uint8_t_u_u(((((safe_sub_func_uint32_t_u_u(((((-1L) < g_12) | 248UL) || l_3991[0][3]), g_3261)) > l_3991[0][2]) & l_4032) & g_2710), l_4035)))), g_12)) != l_2978)) || 248UL)))), l_3960)) <= 0x3193CC09L) | l_3991[0][1]))), l_3955[4][6])), 0))) || l_4034)), l_3492));
                }
            }
        }
    };


                    for (g_2576 = (-5); (g_2576 > 23); g_2576++)
                    {
                        l_3319 = 0x34207361L;
                    }
                }
            }
            else
            {
                g_2476 = l_3239;
            }
            l_3072 = (safe_lshift_func_uint8_t_u_s((safe_sub_func_int16_t_s_s((((((((safe_add_func_int8_t_s_s(0x88L, (g_2576 ^ (safe_unary_minus_func_uint32_t_u(l_3655))))) >= 0xE6B5L) <= (g_359[9][0] || g_813[1][0])) < (0xD1BFL && (((0x8B84L != (safe_sub_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((l_3492 >= l_3256[1][3]), g_2576)), l_2790[4][0])) > 0x93L), l_3255[1][3]))) | g_2177[4][3][5]) ^ l_3721))) < l_3874[1]) == g_540) & 65530UL), l_3721)), l_5[1][6]));
        }
    }

                    if ((safe_add_func_uint32_t_u_u((g_359[9][0] = (safe_rshift_func_int8_t_s_s(g_866[7][3], 6))), (l_2266[3] & ((safe_add_func_uint8_t_u_u((l_2290 = (safe_sub_func_uint16_t_u_u(g_2420, (l_2954 = g_2177[0][3][9])))), ((safe_sub_func_uint16_t_u_u((8UL || (g_361 = ((g_974 = (l_2886[2] = ((safe_mod_func_uint16_t_u_u((l_2900[0][2][7] = 0UL), (safe_lshift_func_uint16_t_u_u(l_2774, (l_2943 < (safe_lshift_func_uint16_t_u_u(((+(l_2896 & g_172[2])) >= g_173), 6))))))) & l_2896))) ^ l_2943))), l_2943)) && 1UL))) == 2UL)))))
            {
                l_2900[0][1][8] = (g_541 | (safe_unary_minus_func_uint32_t_u(l_2954)));
            }
            else
            {
                uint16_t l_2979 = 0UL;
                int32_t l_3106 = 0x8C9DC0F5L;
                if ((safe_rshift_func_uint16_t_u_u(l_2900[0][1][8], (safe_add_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_u((0x8092L < ((~(((((safe_lshift_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((g_540 != (0x4FA4222FL < l_2900[0][1][8])), 5)), (l_2839[1][2][3] != g_2420))) > (g_83 = g_172[4])) <= (((g_2710 != g_2352[2]) < l_2978) <= g_173)) ^ 0x244BBC70L) != g_543[1])) && l_2979)), 1)), g_172[4])), 0L)))))
                {
                    int16_t l_3004[7][4][5] = {{{(-4L),0x7651L,(-1L),(-5L),1L},{0L,0x99FBL,0xBC8AL,0x2258L,0L},{0x907EL,1L,0xD21DL,(-4L),0L},{(-1L),0L,0x33D1L,0x1D12L,1L}},{{6L,0x1D12L,1L,(-1L),(-4L)},{0xF8F4L,0xAC40L,0x96A6L,1L,1L},{(-1L),0x1CB0L,(-1L),0x46ADL,3L},{0xBC8AL,6L,(-6L),0xC8C6L,0x7C8AL}},{{(-5L),(-1L),0x7C8AL,(-4L),9L},{(-4L),1L,(-6L),0x7C8AL,0x530DL},{(-1L),0x7484L,(-1L),3L,6L},{0xBAC0L,0x32A9L,0x96A6L,0x1CB0L,0x444BL}},{{0x444BL,0x34E6L,1L,(-1L),1L},{0x7484L,0x907EL,0x33D1L,8L,1L},{0x31EAL,(-6L),0xD21DL,(-4L),(-1L)},{0x31EAL,(-1L),0xBC8AL,0x530DL,1L}},{{0x7484L,1L,(-1L),0x51ECL,0xB22CL},{0x444BL,0x2258L,(-4L),0xBA36L,0x907EL},{0xBAC0L,0L,0L,0xBAC0L,0x7651L},{(-1L),(-4L),0x444BL,0xAC40L,1L}},{{(-4L),0x96A6L,0xF8F4L,(-6L),0x99FBL},{(-5L),0xB22CL,(-1L),1L,0L},{0x3620L,0x46ADL,3L,1L,3L},{0L,0L,(-4L),(-4L),1L}},{{0xBC8AL,0x7C8AL,0L,(-1L),0x3620L},{(-4L),0x2258L,0L,0L,0x7C8AL},{1L,0x34E6L,0x1D12L,(-1L),0xC8C6L},{0x31EAL,0x34E6L,0xF8F4L,1L,(-4L)}}};
                    int32_t l_3027 = 0x4F76AF9EL;
                    int i, j, k;
                    for (l_2692 = 0; (l_2692 != 55); ++l_2692)
                    {
                        int16_t l_2984[4] = {0L,0L,0L,0L};
                        int i;
                        g_247 = l_2858;
                        l_2290 = (safe_lshift_func_uint16_t_u_u(0x652AL, 2));
                        if (l_2984[3])
                            continue;
                        g_22 = ((g_1460 != ((l_2984[3] == ((-10L) <= 0x4657L)) & g_543[0])) != 0x598F6BB9L);
                    }
                    for (g_63 = 0; (g_63 <= 4); g_63 += 1)
                    {
                        int i;
                        g_22 = (l_2886[g_63] = (safe_lshift_func_uint8_t_u_s(g_83, (safe_rshift_func_int16_t_s_u((safe_mod_func_uint32_t_u_u((g_949[0][2][2] != g_173), (safe_rshift_func_int16_t_s_u((safe_unary_minus_func_int32_t_s(g_172[4])), ((safe_mod_func_uint32_t_u_u(l_2979, l_2840)) != l_2886[1]))))), (safe_lshift_func_uint8_t_u_u(g_217, 5)))))));
                        l_2900[0][1][8] = (safe_rshift_func_int16_t_s_u((((l_2774 > (safe_sub_func_uint8_t_u_u(l_2979, (safe_rshift_func_uint8_t_u_s(l_3004[4][2][0], 0))))) > (safe_mod_func_uint16_t_u_u((safe_sub_func_int32_t_s_s((safe_mod_func_uint8_t_u_u((((0xD7L || (l_3027 = ((safe_add_func_int16_t_s_s((l_2290 = ((l_2978 & (safe_lshift_func_int8_t_s_u(((safe_lshift_func_int8_t_s_u((l_3017 || ((((1L == (((!g_2177[3][1][5]) | ((((((safe_mod_func_int32_t_s_s(((((!((safe_rshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s(((0x32L | g_217) < l_3004[4][2][0]), 2)) ^ g_2420), 12)) || 0x97B2L)) | l_2979) | 0xB9843563L) < 0xB46BL), g_2420)) > g_541) < l_2290) || l_3026) == l_2790[4][0]) != l_2886[g_63])) | 0x616CL)) < l_2900[0][5][5]) ^ l_2886[g_63]) <= 1L)), 4)) ^ l_2979), 4))) <= l_2979)), 0x7F87L)) == g_173))) > g_949[2][2][1]) & g_540), g_4)), l_2886[g_63])), l_2266[3]))) | 0x49L), g_813[1][0]));
                        if (l_2886[g_63])
                            continue;
                    }
                    g_22 = g_12;
                }
                else
                {
                    int32_t l_3037 = 0xE3233A39L;
                    int32_t l_3060[10] = {6L,6L,6L,6L,6L,6L,6L,6L,6L,6L};
                    int i;
                    g_22 = (((safe_lshift_func_uint16_t_u_s((((((l_2266[3] = ((l_2886[2] = g_813[0][0]) == (g_543[1] ^ (g_2710 & g_103)))) <= (safe_sub_func_uint8_t_u_u(((0x13L | (l_2840 = ((g_173 >= (safe_sub_func_int32_t_s_s(l_2979, g_1129))) >= ((safe_sub_func_int8_t_s_s((1UL >= 0x6AL), 0x75L)) <= 0xFD0877F9L)))) && l_3036[6][2][5]), l_2979))) >= 0UL) && g_359[9][0]) || l_3037), l_2943)) > l_2294) | g_63);
                    for (l_2674 = 0; (l_2674 > 24); l_2674 = safe_add_func_uint8_t_u_u(l_2674, 9))
                    {
                        int16_t l_3042 = 0xDD5AL;
                        g_2476 = (safe_add_func_int16_t_s_s((l_3042 < g_361), ((safe_sub_func_int32_t_s_s(0x826DAE46L, ((g_188 < 0xCDF2L) != ((safe_rshift_func_uint16_t_u_u(l_3037, (g_315 = l_2692))) && (65535UL < ((safe_rshift_func_int8_t_s_u(0xB0L, 0)) | l_2896)))))) != 0x08L)));
                    }
                    for (l_3037 = 5; (l_3037 >= 2); l_3037 -= 1)
                    {
                        uint8_t l_3061 = 0UL;
                        int i;
                        l_3061 = (~(((l_3060[5] = (((safe_mod_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_s((safe_unary_minus_func_int32_t_s((safe_add_func_uint32_t_u_u(((-1L) == g_172[(l_3037 + 2)]), g_2352[l_3037])))), g_2352[l_3037])) > ((!g_1215[l_3037]) > g_173)), (safe_mod_func_int32_t_s_s(l_3037, (g_103 = 4294967295UL))))) || (0x5AFB853AL <= g_1215[l_3037])) | 0xA7L)) ^ l_3037) >= g_359[5][0]));
                    }
                }
                l_2900[0][2][4] = (((g_949[0][6][1] && (g_359[9][0] | (((g_2177[3][1][9] >= (1UL && (safe_mod_func_uint32_t_u_u(l_2858, (safe_lshift_func_uint8_t_u_u((((g_22 = g_315) ^ ((safe_mod_func_int8_t_s_s(((safe_lshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s(2L, l_3072)), 6)) != (g_2352[2] != 253UL)), g_217)) & g_1215[4])) & l_2858), l_2841)))))) >= l_2418[5][1]) ^ 0xD174L))) == 7UL) <= 0x9A48L);
                if ((g_2352[5] && g_974))
                {
                    l_2408[4][4] = g_161;
                }
                else
                {
                    uint32_t l_3090 = 0UL;
                    int32_t l_3091 = 0L;
                    int16_t l_3092 = (-8L);
                    l_2900[0][1][8] = (g_2476 = (((safe_add_func_uint8_t_u_u((0x8017L & 0xC852L), (((safe_add_func_uint16_t_u_u((!((safe_rshift_func_uint8_t_u_s(((safe_add_func_int8_t_s_s(4L, (safe_mod_func_int16_t_s_s((g_2420 > l_2979), (~(g_22 = ((+g_161) && (safe_add_func_uint8_t_u_u((((+(((!l_2841) && ((l_3090 = l_2408[1][3]) & (((l_3091 && 0x435BL) ^ l_2601) > 1L))) >= l_3092)) | l_3026) > 0x889AL), g_866[6][9]))))))))) <= g_974), l_2979)) < g_1460)), g_173)) & g_1129) >= 0xAEL))) & l_2978) > 0x659EL));
                    l_3017 = l_2790[4][0];
                    if (g_217)
                    {
                        uint16_t l_3099[7][1][9] = {{{0x51BFL,0xF916L,0xE95AL,0xF916L,0x51BFL,0xFFE8L,0xF916L,0x12F6L,0x49F3L}},{{0xFB2EL,0x5E99L,0x2DFEL,3UL,0x5E99L,0x6495L,0x5E99L,3UL,0x2DFEL}},{{0x51BFL,0x51BFL,0x49F3L,0x12F6L,0xF916L,0xFFE8L,0x51BFL,0xF916L,0xE95AL}},{{0x1128L,0x5E99L,0x525EL,0xFB2EL,0xFB2EL,0x525EL,0x5E99L,0x1128L,0x6495L}},{{0xB939L,0xF916L,0x49F3L,0xB939L,0xA389L,65526UL,0xF916L,0xF916L,65526UL}},{{0UL,0xFB2EL,0x2DFEL,0xFB2EL,0UL,0x9D28L,0xFB2EL,3UL,0x6495L}},{{0xF916L,0xA389L,0xE95AL,0x12F6L,0xA389L,0x49F3L,0xA389L,0x12F6L,0xE95AL}}};
                        int i, j, k;
                        g_247 = (safe_sub_func_uint8_t_u_u(((safe_add_func_uint16_t_u_u(g_543[1], (0x01E7BACFL || (g_2576 = 0L)))) == (((l_2900[0][0][5] = ((safe_sub_func_int16_t_s_s((g_949[0][6][1] < ((g_361 = ((0xE5L || (l_3099[2][0][1] < (g_974 | (safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((g_813[6][0] >= (g_161 = (safe_lshift_func_uint8_t_u_s((1L & l_2900[0][1][6]), g_359[2][6])))), 4)), 4))))) & l_3099[3][0][2])) || 1L)), l_2918)) && l_3106)) <= g_359[2][3]) & 0x0EL)), (-2L)));
                    }
                    else
                    {

{
                    j = 0x97E65834L;
                }

                    l_2900[0][1][7] = l_3091;
                        return g_543[1];
                    }
                }
                g_247 = ((safe_unary_minus_func_int32_t_s((((l_2900[0][4][1] = ((((g_217 & ((4L >= (g_188 = ((7L | ((0x9B13L < g_217) > (l_2979 < ((!l_5[1][1]) <= (g_63 = ((g_12 != (((0xA14DL > 0xAC7AL) == l_2886[2]) > 0L)) <= g_866[4][0])))))) | g_12))) <= g_161)) < g_2352[0]) == l_2526) <= 0x0C7DL)) || 254UL) != l_3109))) != g_540);
            }
        }
        if ((((safe_rshift_func_int16_t_s_s((safe_mod_func_uint8_t_u_u((((safe_rshift_func_int16_t_s_u((9L ^ ((g_2177[2][1][7] == g_949[0][2][4]) || ((l_2886[3] = (l_3116 != (safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_s((l_2292 > (0x05L | l_3036[5][1][4])), 7)), g_12)), (safe_unary_minus_func_int8_t_s(((g_866[1][3] & g_217) & g_543[1]))))))) || g_866[4][0]))), 2)) == l_2838) <= 0UL), 0x82L)), g_2710)) && g_2710) < l_2838))
        {
            int16_t l_3131 = 0xDA0DL;
            g_247 = ((-7L) | (safe_lshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((0xACL >= (!(safe_mod_func_uint16_t_u_u(l_3131, l_3116)))), 5)), 10)));
            for (g_1524 = 17; (g_1524 <= (-24)); g_1524 = safe_sub_func_uint32_t_u_u(g_1524, 6))
            {
                if (g_813[1][0])
                    {
{
                int32_t l_2223 = 0xFFA1B367L;

if (g_188)
                        break;

                    g_22 = 1L;
                l_2223 = (l_2601 && (4294967293UL & ((l_2601 != 0x174AL) ^ l_2601)));
                k = (safe_lshift_func_int8_t_s_u(((safe_rshift_func_int16_t_s_s(g_949[0][6][1], 15)) ^ ((l_4035 = 0x79L) == k)), 2));
            }

                    break;}
                return l_3131;
            }
            return g_103;
        }
        else
        {
            int8_t l_3134 = 1L;
            g_247 = l_3134;
            l_2266[3] = (safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u(((((safe_sub_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u(((l_3036[8][1][4] && (((g_173 = (safe_sub_func_int8_t_s_s((safe_mod_func_int8_t_s_s((safe_mod_func_int8_t_s_s(l_2858, (safe_sub_func_uint32_t_u_u(l_3151, ((g_103 = l_3134) == (0x54EAL == (g_866[2][3] & (g_2476 = g_813[1][0])))))))), g_3152)), (((l_2465 & g_866[4][0]) != g_4) < l_3134)))) >= 0x97L) || g_172[3])) <= 3L), g_359[9][0])) <= l_3134), 0UL)) ^ 2UL) == g_1215[4]) == 0x81F5611FL), l_2674)), 7));
        }

for (l_3109 = (-10); (l_3109 <= 14); l_3109 = safe_add_func_uint8_t_u_u(l_3109, 5))
        {
            int16_t l_501 = 9L;
            int32_t l_508[9][8][3] = {{{1L,0x08A14A3AL,0L},{0xC26916B3L,0x08A14A3AL,3L},{0x08A14A3AL,(-8L),1L},{0x1E9F24E1L,0xC26916B3L,3L},{(-1L),(-7L),0L},{(-1L),0x001EC93AL,3L},{0x1E9F24E1L,7L,9L},{0x08A14A3AL,0x001EC93AL,(-2L)}},{{0xC26916B3L,(-7L),(-2L)},{1L,0xC26916B3L,9L},{(-8L),(-8L),3L},{1L,0x08A14A3AL,0L},{0xC26916B3L,0x08A14A3AL,3L},{0x08A14A3AL,(-8L),1L},{0x1E9F24E1L,0xC26916B3L,3L},{(-1L),(-7L),0L}},{{(-1L),0x001EC93AL,3L},{0x1E9F24E1L,7L,9L},{0x08A14A3AL,0x001EC93AL,(-2L)},{0xC26916B3L,(-7L),(-2L)},{1L,0xC26916B3L,9L},{(-8L),(-8L),3L},{1L,0x08A14A3AL,7L},{0L,1L,(-1L)}},{{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)},{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)},{0xCFF90880L,0x3E711866L,0x001EC93AL},{1L,(-1L),0x1E9F24E1L},{0L,0x1C26E085L,0x1E9F24E1L},{(-6L),0L,0x001EC93AL}},{{0x095E5563L,0x095E5563L,(-8L)},{(-6L),1L,7L},{0L,1L,(-1L)},{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)},{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)},{0xCFF90880L,0x3E711866L,0x001EC93AL}},{{1L,(-1L),0x1E9F24E1L},{0L,0x1C26E085L,0x1E9F24E1L},{(-6L),0L,0x001EC93AL},{0x095E5563L,0x095E5563L,(-8L)},{(-6L),1L,7L},{0L,1L,(-1L)},{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)}},{{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)},{0xCFF90880L,0x3E711866L,0x001EC93AL},{1L,(-1L),0x1E9F24E1L},{0L,0x1C26E085L,0x1E9F24E1L},{(-6L),0L,0x001EC93AL},{0x095E5563L,0x095E5563L,(-8L)},{(-6L),1L,7L}},{{0L,1L,(-1L)},{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)},{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)},{0xCFF90880L,0x3E711866L,0x001EC93AL},{1L,(-1L),0x1E9F24E1L},{0L,0x1C26E085L,0x1E9F24E1L}},{{(-6L),0L,0x001EC93AL},{0x095E5563L,0x095E5563L,(-8L)},{(-6L),1L,7L},{0L,1L,(-1L)},{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)},{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)}}};
            int32_t l_517 = 0xA0C82EBCL;
            int32_t l_518 = 0x8F0CB5B0L;
            int32_t l_520 = 1L;
            int i, j, k;
            l_520 = ((l_3741 = 1L) <= (((~(((safe_add_func_uint16_t_u_u((l_2842 < (((((safe_sub_func_uint8_t_u_u((l_518 = ((((!(l_501 < (safe_lshift_func_uint16_t_u_s((l_517 = ((safe_rshift_func_int8_t_s_s((l_508[8][4][1] = (l_3683 = l_3026)), (l_2465 <= (l_2842 && l_2842)))) >= (((-7L) ^ (safe_sub_func_int16_t_s_s(((safe_add_func_int16_t_s_s((l_3017 = ((l_3872 = (safe_sub_func_uint32_t_u_u(((safe_mod_func_int32_t_s_s((-10L), (-1L))) && 0x80L), l_3109))) & l_501)), (-1L))) || 65531UL), 6UL))) == 1UL))), l_501)))) && l_3872) < g_1524) > l_2465)), l_3109)) | l_3492) <= l_3775) ^ l_3891) < 0x72DFB7FAL)), 0x2D47L)) >= 1L) <= 1UL)) > l_3151) < l_3891));
        };


                    l_2840 = ((0x10L && (((l_2886[0] = (l_3153 = g_161)) != l_2840) == (safe_mod_func_uint16_t_u_u((g_63 = (((safe_mod_func_int16_t_s_s((l_3017 = ((g_813[5][0] & ((((g_2177[3][1][9] = (safe_lshift_func_int16_t_s_u((safe_add_func_uint32_t_u_u((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((((safe_unary_minus_func_int8_t_s(((safe_sub_func_uint32_t_u_u(0UL, (0x891FL & (safe_mod_func_int16_t_s_s((l_2292 ^ (((((l_2816 == g_866[4][0]) <= l_2418[5][4]) | l_2840) > g_83) != l_3171)), l_2266[3]))))) || g_2598))) > l_2465) | 0xD3666B9CL), l_2296)), l_2601)), g_2576)), 13))) > 0UL) != g_361) > l_2918)) != l_3151)), l_2841)) > l_2838) != l_2842)), 1L)))) <= 0L);
    }
    g_2576 = (l_2296 = (((!(((l_2266[3] = (safe_rshift_func_uint16_t_u_u(((g_247 = (((safe_rshift_func_int8_t_s_s(l_2266[0], 1)) == (~((0UL <= (((l_2408[2][5] || (safe_sub_func_uint16_t_u_u((0x07C4L | ((safe_lshift_func_uint8_t_u_u((((safe_mod_func_int8_t_s_s(9L, 0x8EL)) & (safe_mod_func_int16_t_s_s((safe_mod_func_uint16_t_u_u((((safe_add_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(0x49BFL, (l_2290 = ((safe_lshift_func_uint8_t_u_s((safe_add_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_s(g_813[6][0], 7)) ^ (((l_2408[0][0] = g_2352[0]) > 0x99F79172L) > 0xE78350BCL)), l_2266[3])), g_103)) < g_2420)))), l_2674)) & g_1460) >= g_949[2][4][8]), g_866[6][3])), (-3L)))) >= 0x7F3CD12AL), 6)) == 0x5622E054L)), 0x1450L))) || g_83) != 0L)) != g_161))) <= g_217)) | g_543[1]), 14))) > g_103) & l_2899)) & (-10L)) <= g_2598));
    if (l_2790[4][0])
    {
        int8_t l_3204 = 0xA2L;
        uint32_t l_3210 = 0xF4784D76L;
        int32_t l_3239 = 6L;
        int32_t l_3240[6];
        int i;

l_3775 += 1;


                    for (i = 0; i < 6; i++)
            l_3240[i] = 0xADBA3217L;

l_3655 += 1;


                    g_22 = (((((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((((g_1460 & (safe_add_func_int32_t_s_s((((((l_3204 = g_543[1]) | (9L != (safe_add_func_uint32_t_u_u(g_4, (8L | (-1L)))))) || ((safe_sub_func_int16_t_s_s((safe_unary_minus_func_uint32_t_u(l_3210)), l_3204)) <= (g_2177[3][1][9] | g_2576))) ^ l_2266[3]) != l_3210), g_12))) <= g_1129) || 5UL), g_2177[3][1][9])), 0)) < l_2294) >= 1UL) || g_2576) > g_2476);
        g_22 = (l_3204 <= (safe_sub_func_uint16_t_u_u(((l_2601 >= (1UL || (safe_sub_func_uint8_t_u_u((g_2177[2][3][7] = (safe_sub_func_uint8_t_u_u((safe_mod_func_int16_t_s_s(((g_974 = (safe_lshift_func_uint8_t_u_u((l_2266[1] = ((((l_3171 || (l_2290 = l_2692)) || (safe_sub_func_int8_t_s_s((safe_sub_func_int32_t_s_s(((l_2296 = (safe_mod_func_uint16_t_u_u(g_543[2], g_2420))) <= (g_543[1] || (l_2692 == 0UL))), l_2526)), 2L))) >= g_2177[5][3][1]) == l_3210)), l_2526))) != l_2418[5][4]), l_3204)), l_5[1][6]))), 0x74L)))) | g_949[2][4][8]), g_3152)));
        l_3017 = (safe_add_func_uint16_t_u_u((((g_1524 >= (safe_lshift_func_int8_t_s_s(0L, ((0L | l_2408[3][0]) < ((safe_add_func_uint32_t_u_u(l_2408[3][0], (((safe_mod_func_uint8_t_u_u(((l_3210 > ((safe_rshift_func_int16_t_s_u(((((g_359[9][0] = (l_3240[3] = (((safe_mod_func_uint16_t_u_u((g_813[1][0] = (4294967295UL == ((-5L) >= l_3210))), g_63)) >= l_5[2][1]) | l_3239))) & 4UL) & g_1460) && g_541), 8)) > g_2420)) == l_3239), g_315)) > 0xBF1DC840L) != g_103))) ^ g_2177[1][1][7]))))) < g_949[0][6][1]) > 7UL), g_1460));
        for (g_22 = 0; (g_22 > 18); g_22 = safe_add_func_uint32_t_u_u(g_22, 3))
        {
            uint16_t l_3255[4][5];
            int32_t l_3256[2][8] = {{0L,0L,0x73962BB8L,0x73962BB8L,0L,0L,0x73962BB8L,0x73962BB8L},{0L,0L,0x73962BB8L,0x73962BB8L,0L,0L,0x73962BB8L,0x73962BB8L}};
            int i, j;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 5; j++)
                    l_3255[i][j] = 0x74B9L;
            }
            if ((safe_sub_func_uint16_t_u_u((l_3204 || (safe_add_func_uint32_t_u_u(((((((l_2790[4][0] || ((((g_315 != ((l_3256[1][3] = (g_115 >= (l_2290 = (g_2576 = (l_2296 = (((safe_sub_func_int32_t_s_s(((((safe_mod_func_uint8_t_u_u(((((l_3240[2] & ((g_2476 = (g_247 = (safe_add_func_uint16_t_u_u(l_3204, (65529UL != ((g_974 & ((safe_add_func_int8_t_s_s(3L, g_1215[1])) <= l_3255[1][3])) != 0x21FD1DCEL)))))) < (-8L))) >= 0xBAL) != l_2674) > l_5[3][0]), l_3116)) < 0L) & g_1460) ^ 0xA4EBL), 0xA9004A2AL)) > g_813[3][0]) != l_3255[1][3])))))) > l_3255[1][3])) & g_543[0]) >= l_2674) ^ 1L)) != 0L) & l_3171) ^ g_4) & l_3257) | l_3255[0][4]), 1UL))), g_3258)))
            {
                uint32_t l_3263 = 4294967295UL;
                int32_t l_3303 = 0L;
                for (g_1129 = 0; (g_1129 != 43); g_1129++)
                {
                    uint32_t l_3304 = 0xA0CD230EL;
                    int32_t l_3305[2][8][1] = {{{0xC3B07C44L},{0xC3B07C44L},{0x80AED170L},{0xAF71240FL},{0x9433F045L},{0xAF71240FL},{0x80AED170L},{0xC3B07C44L}},{{0xC3B07C44L},{0x80AED170L},{0xAF71240FL},{0x9433F045L},{0xAF71240FL},{0x80AED170L},{0xC3B07C44L},{0xC3B07C44L}}};
                    int i, j, k;
                    l_3262 = (g_3261 <= g_2710);
                    l_3263 = 0x3D7DBF13L;
                    if (g_2177[1][0][6])
                    {
                        return g_83;
                    }
                    else
                    {
                        uint8_t l_3287 = 5UL;
                        l_3305[0][3][0] = (((safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((g_2420 = ((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s((safe_unary_minus_func_int16_t_s((((safe_add_func_int16_t_s_s((l_3240[3] = l_3255[2][2]), ((safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(((safe_add_func_int32_t_s_s(((safe_mod_func_uint16_t_u_u((l_3256[1][3] = ((safe_sub_func_int32_t_s_s((g_2576 = 1L), (safe_lshift_func_int16_t_s_s(((0x83DAL <= (g_2177[3][1][9] > (l_3287 | 1UL))) <= (((safe_sub_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u((((safe_rshift_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(((l_3303 = (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_uint32_t_u((((safe_add_func_uint16_t_u_u(((l_3256[1][3] < l_3287) < ((safe_sub_func_int32_t_s_s(l_3287, 7UL)) && g_3261)), g_115)) >= 0x318768DEL) && l_3263))), 9))) != l_3204), l_3256[1][6])), 4)) >= l_3304) | g_217), l_3287)) ^ g_3258), 0L)) ^ 0x51L) != g_103)), 15)))) >= l_3287)), (-1L))) && g_2177[5][1][8]), g_813[6][0])) ^ 0xAFL), g_103)), g_541)) >= 0x34L))) == g_359[9][2]) | g_1215[4]))), g_361)), g_2710)) == l_3255[0][1])), 4)), 6)) || 4UL) | l_3287);
                    }
                }

l_3171 += 1;


                    for (l_3204 = 0; (l_3204 <= (-20)); l_3204 = safe_sub_func_uint8_t_u_u(l_3204, 5))
                {

g_63 += 1;


                    g_2476 = (g_359[9][0] ^ (g_217 != (((safe_rshift_func_uint16_t_u_u(9UL, (safe_sub_func_int16_t_s_s((g_543[1] = 0x560CL), (safe_lshift_func_int16_t_s_s((!l_3303), 7)))))) > ((g_115 && ((l_2266[3] = 65535UL) != (g_4 & (l_2296 = ((-10L) > 0xD9890121L))))) > l_3204)) | l_3256[1][3])));
                    l_3303 = 0x9ED79E98L;
                    g_2576 = (l_3256[1][2] = (g_2476 = (0x6A45L != (g_1524 = (-1L)))));
                    g_3258 = 0xA5D6E7B4L;
                }
                for (g_2476 = (-29); (g_2476 < 29); g_2476++)
                {
                    int32_t l_3319 = 4L;
                    for (l_2292 = 1; (l_2292 <= 7); l_2292 += 1)
                    {
                        int i, j;

l_3399 += 1;


                    return g_866[l_2292][(l_2292 + 1)];
                    }
                    for (l_2294 = (-5); (l_2294 > 23); l_2294++)
                    {
                        l_3319 = 0x34207361L;
                    }
                }
            }
            else
            {

{
        transparent_crc(g_543[i], "g_543[i]", g_2476);
        if (g_2476) printf("index = [%d]\n", i);

    }

                    g_3258 = l_3239;
            }
            g_2476 = (safe_lshift_func_uint8_t_u_s((safe_sub_func_int16_t_s_s((((((((safe_add_func_int8_t_s_s(0x88L, (l_3017 ^ (safe_unary_minus_func_uint32_t_u(g_1129))))) >= 0xE6B5L) <= (g_359[9][0] || g_813[1][0])) < (0xD1BFL && (((0x8B84L != (safe_sub_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((g_22 >= l_3256[1][3]), l_2294)), l_2790[4][0])) > 0x93L), l_3255[1][3]))) | g_2177[4][3][5]) ^ g_115))) < g_2352[1]) == l_3257) & 65530UL), g_115)), l_5[1][6]));
        }
    }
    else
    {
        int8_t l_3339 = 0xC8L;
        int32_t l_3340 = 0x644F2DE5L;
        uint8_t l_3351[6];
        int32_t l_3352[3];
        uint16_t l_3398 = 65532UL;
        uint32_t l_3467 = 0UL;
        int i;
        for (i = 0; i < 6; i++)
            l_3351[i] = 0x35L;
        for (i = 0; i < 3; i++)
            l_3352[i] = 0xE9F35B3EL;
        if ((0L ^ (((l_2292 ^ ((safe_mul_func_uint8_t_u_u((l_3340 = (safe_add_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s(g_4, l_3339)), (g_1129 == g_2710)))), ((g_3258 = (~(safe_lshift_func_int16_t_s_s((((safe_unary_minus_func_uint32_t_u(((safe_lshift_func_uint8_t_u_s(((safe_sub_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_s(l_2408[3][0], 13)), (l_3017 = (((g_540 ^ ((((g_866[4][0] ^ l_3351[3]) < 0xE8L) | g_1129) || l_2266[3])) ^ l_3351[3]) || g_2598)))) & l_3351[0]), l_3351[2])) != g_1215[4]))) ^ g_361) & l_3352[0]), g_359[9][0])))) != 0x3D20D3F6L))) <= l_3339)) == g_540) == l_2408[3][0])))
        {
            g_22 = (g_2476 = (safe_add_func_int8_t_s_s(g_2177[3][1][9], l_3351[4])));
        }
        else
        {
            int32_t l_3355[8][1] = {{0L},{(-1L)},{0L},{(-1L)},{0L},{(-1L)},{0L},{(-1L)}};
            uint32_t l_3372[4] = {0x99672B6EL,0x99672B6EL,0x99672B6EL,0x99672B6EL};
            int32_t l_3443 = 4L;
            uint32_t l_3505 = 18446744073709551615UL;
            int32_t l_3506[10];
            int i, j;

{
                return g_974;
            }

                    for (i = 0; i < 10; i++)
                l_3506[i] = (-1L);
            g_247 = ((g_12 = (g_2352[2] ^ l_3340)) | l_3355[5][0]);
            for (g_2476 = 2; (g_2476 >= 0); g_2476 -= 1)
            {
                int32_t l_3359 = 0x3456D091L;
                uint16_t l_3373 = 1UL;
                uint32_t l_3513 = 4294967295UL;
                int i;
                l_3340 = (g_543[g_2476] != ((safe_rshift_func_uint8_t_u_s(g_543[g_2476], (g_4 = (l_3359 = (safe_unary_minus_func_int8_t_s(1L)))))) ^ (safe_add_func_int32_t_s_s(g_866[6][0], (((0xF346L ^ l_3262) && (((g_1215[4] | (!l_3340)) & l_3339) != g_173)) | 4294967288UL)))));
                if ((((((l_2899 > (g_813[4][0] | 0x4A1BL)) | l_3355[5][0]) == (((g_315 ^ ((g_3152 || g_1215[4]) < (safe_add_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((((g_12 || (safe_unary_minus_func_int16_t_s(g_2352[2]))) == g_2476) <= 0x88L), 14)), (-1L))))) != g_161) == g_63)) < 65535UL) <= 1UL))
                {
                    uint16_t l_3397 = 0xE9F5L;
                    for (g_83 = 0; g_83 < 3; g_83 += 1)
                    {

if (g_813[1][0])
                    break;

                    l_3352[g_83] = 0x6604D0B6L;
                    }
                    for (l_3257 = 0; (l_3257 <= 2); l_3257 += 1)
                    {
                        int32_t l_3396[2][10] = {{0xFD928D26L,0x128AF7B3L,0xFD928D26L,0x70EF2261L,0x70EF2261L,0xFD928D26L,0x128AF7B3L,0xFD928D26L,0x70EF2261L,0x70EF2261L},{0xFD928D26L,0x128AF7B3L,0xFD928D26L,0x70EF2261L,0x70EF2261L,0xFD928D26L,0x128AF7B3L,0xFD928D26L,0x70EF2261L,0x70EF2261L}};
                        int i, j;
                        g_2576 = ((((safe_sub_func_uint32_t_u_u(((safe_lshift_func_uint16_t_u_u((((((((l_5[5][1] ^ g_1129) & (g_359[5][3] = ((g_103 = l_3372[0]) & l_3373))) & ((safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u((g_361 != (g_83 = ((251UL <= ((g_161 = (((g_538 = (safe_add_func_uint32_t_u_u(((((safe_mod_func_int16_t_s_s((safe_sub_func_int32_t_s_s((safe_sub_func_int8_t_s_s((0xCCA5L != (safe_unary_minus_func_int16_t_s((g_543[g_2476] = ((l_3373 < (safe_add_func_uint16_t_u_u(((g_22 = (safe_rshift_func_int8_t_s_s((~(safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((g_315 ^ g_1215[5]), g_2420)), l_3355[4][0]))), 1))) > 0xE3C5E1EAL), g_115))) <= g_974))))), g_1215[4])), g_83)), l_3396[0][2])) && l_3397) && l_2296) > (-1L)), l_3359))) >= l_3373) | 0x3BE0L)) ^ (-9L))) || 0x52L))), 3)) | l_3398), 0xC478L)) <= 0x81F1L)) <= g_173) & g_188) <= g_247) >= 0x47L), g_188)) != l_3399), l_3151)) != l_3397) ^ 1UL) > 0x7F4ED5EFL);
                        l_3340 = (((((g_173 <= (safe_lshift_func_int8_t_s_u(((l_3397 && (l_3396[0][2] = ((((l_3351[3] > (((safe_sub_func_uint8_t_u_u(((g_3261 || (l_3359 = (((g_103 = (g_359[9][1] = (((g_813[1][0] = ((((safe_sub_func_int16_t_s_s((-1L), ((g_12 = ((0x82A8L ^ 0xEFCAL) > ((l_2408[3][0] != (safe_sub_func_int16_t_s_s((((0x3DD5L < g_543[g_2476]) <= 1L) ^ l_3408), g_2177[1][2][4]))) || 4294967295UL))) != 0x58L))) && l_2418[5][4]) || 4L) & g_1129)) == 0x5062L) >= 0x611BL))) != g_1129) && g_1215[4]))) != 3L), l_3351[3])) | l_3396[0][2]) <= g_3409)) & g_63) != 1L) || 1L))) >= 255UL), g_2177[3][1][9]))) | 0xEFL) <= g_543[g_2476]) >= g_188) == l_3373);
                        g_22 = l_3352[0];
                    }
                    l_2408[1][0] = (((((l_3372[3] > (safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u((safe_rshift_func_uint16_t_u_u(((g_172[3] != (safe_add_func_int8_t_s_s(l_3397, (((safe_unary_minus_func_int8_t_s(((((safe_sub_func_int32_t_s_s(g_3421, l_2790[4][0])) | ((safe_lshift_func_uint16_t_u_s((l_3424[1][0][0] && ((0xFDCCD15CL < (safe_lshift_func_uint16_t_u_s((safe_lshift_func_uint16_t_u_s((safe_add_func_int8_t_s_s((g_83 = ((l_3351[4] & g_543[g_2476]) <= g_3258)), 0UL)), g_540)), 9))) ^ 8UL)), 11)) ^ g_63)) & (-5L)) ^ g_541))) < g_173) != 0x29BCB211L)))) == l_3397), g_866[4][0])), 15)), l_2526))) <= (-3L)) == 0x1AE2L) && l_3398) == l_3372[0]);
                }
                else
                {
                    uint16_t l_3442[9][9] = {{0xD162L,0UL,0xD162L,0x5941L,0x5941L,0xD162L,0UL,0xD162L,0x5941L},{0xD162L,0x5941L,0x5941L,0xD162L,0UL,0xD162L,0x5941L,0xD162L,65532UL},{0x5941L,0xD162L,0UL,0xD162L,0x5941L,0x5941L,0xD162L,0UL,0xD162L},{0xD162L,0UL,0UL,0UL,0UL,0xD162L,0UL,0UL,0UL},{0x5941L,0x5941L,0xD162L,0UL,0xD162L,0x5941L,0x5941L,0xD162L,0UL},{65532UL,0UL,65532UL,0xD162L,0xD162L,65532UL,0UL,65532UL,0xD162L},{65532UL,0xD162L,0xD162L,65532UL,0UL,65532UL,0xD162L,0xD162L,65532UL},{0x5941L,0xD162L,0UL,0xD162L,0x5941L,0x5941L,0xD162L,0UL,0xD162L},{0xD162L,0UL,0UL,0UL,0UL,0xD162L,0UL,0UL,0UL}};
                    int i, j;
                    g_3258 = ((safe_mod_func_int8_t_s_s((g_83 = ((safe_rshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((g_2710 = (((((0xEAL && (((l_3443 = (safe_sub_func_int32_t_s_s((!(safe_rshift_func_int16_t_s_s(g_540, l_3442[6][8]))), (g_217 == g_866[6][5])))) || (((l_3340 = (safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_u(((safe_lshift_func_uint16_t_u_s(((+0x53L) >= (~((g_173 = (safe_sub_func_uint32_t_u_u(0x00580031L, (((safe_sub_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_u((safe_lshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_u(0xF9L, 7)), 15)), 10)) == (l_3443 = g_359[9][0])), g_3421)) == 0x2266L) & l_2899)))) ^ l_3355[5][0]))), 1)) <= g_3258), 1)) != l_3355[5][0]), 7)), 2))) == g_1524) > g_359[9][0])) & 0xD676L)) == l_3442[0][6]) != l_3442[6][8]) ^ 0x3B79L) >= 0x22L)), 0UL)), g_4)) ^ g_866[4][0])), 0x3CL)) >= l_2692);
                }

g_2476 -= 1;


                    for (l_2692 = 0; (l_2692 <= 57); l_2692 = safe_add_func_int16_t_s_s(l_2692, 7))
                {
                    int32_t l_3476 = 0x5E8CBEC4L;
                    if (g_4)
                    {
                        uint16_t l_3468 = 0x5320L;

g_541 -= 1;


                    g_3258 = ((l_3359 | g_543[g_2476]) == (((g_2177[3][1][9] = (g_161 < 0xC0L)) > (l_3372[0] != (g_1129 = ((safe_unary_minus_func_int8_t_s(((l_3467 != g_543[g_2476]) < l_3468))) >= ((((g_63 = 65535UL) | 0L) | 0L) || 8UL))))) != 0x21L));
                    }
                    else
                    {
                        uint8_t l_3474 = 0x79L;
                        int32_t l_3475 = 0xEE4C41D5L;
                        g_247 = (safe_add_func_int32_t_s_s((((l_3471 ^ (((l_3373 < ((safe_mod_func_uint16_t_u_u((g_173 ^ (l_3352[1] ^ (g_2598 && (((((g_361 | 4294967292UL) | g_217) | (l_3474 = 6L)) > 1UL) > g_540)))), g_974)) == 0xEC67L)) || g_83) >= 0x2A2BL)) && g_83) != l_3475), g_949[0][6][1]));
                        if (l_3476)
                            break;
                        l_2408[1][1] = ((0xACA1L ^ ((safe_add_func_int16_t_s_s((((((l_3471 = ((((l_3474 >= (safe_lshift_func_uint8_t_u_s(0x3BL, 0))) >= (safe_lshift_func_uint8_t_u_s((safe_unary_minus_func_int16_t_s(g_3484)), ((l_3443 | (g_538 > 0x81F1L)) ^ (safe_lshift_func_uint16_t_u_u((((safe_sub_func_uint16_t_u_u((((((l_2290 = (safe_rshift_func_int16_t_s_s(((~l_3475) > (l_2266[3] = 0x4EE0L)), g_2710))) && g_543[1]) & g_813[1][0]) ^ l_3492) > g_1215[1]), 0L)) >= l_3398) < (-5L)), 10)))))) ^ g_543[g_2476]) <= 1UL)) >= 0x86DCL) | l_3351[5]) == 0UL) & g_543[g_2476]), g_2352[1])) >= 0xC6L)) <= g_1215[3]);
                    }
                    for (l_3471 = (-22); (l_3471 < 11); ++l_3471)
                    {
                        uint32_t l_3502 = 0x9ED2561EL;
                        g_247 = (0x16F39D5EL != ((((safe_add_func_int16_t_s_s(((l_3476 <= ((safe_add_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u((l_2290 = ((g_22 & (!((l_3443 = (g_359[9][0] = l_3339)) >= (g_247 <= 2L)))) == 3UL)), l_3502)), ((safe_add_func_int8_t_s_s((g_3258 != 0x76L), g_3261)) >= g_866[0][5]))) ^ 0UL)) || g_949[1][1][4]), l_3359)) || l_3502) < g_63) ^ l_3355[0][0]));
                    }

{
        int32_t l_3732 = 5L;
        int32_t l_3772[9][5][4] = {{{(-5L),0x53797119L,(-1L),0xEC1AA655L},{(-3L),0x0BED20CAL,0x620E126EL,0x64D60197L},{0x620E126EL,0x64D60197L,(-1L),(-1L)},{0x9C8EED80L,0x08C26BBCL,(-1L),(-7L)},{(-1L),(-1L),0x5187487DL,(-1L)}},{{(-1L),0x5187487DL,0x5187487DL,0x08C26BBCL},{0L,0x3A0636EDL,0x227DF413L,0L},{(-1L),(-1L),0x53797119L,0x5A84B327L},{(-1L),0x08C26BBCL,0x3C72134DL,0x5A84B327L},{0L,(-1L),0x5B09E585L,0L}},{{0x64D60197L,0x3A0636EDL,0xEC1AA655L,0x08C26BBCL},{0x6CA574B2L,0x5187487DL,(-1L),0xC7C31EEAL},{0x620E126EL,(-1L),(-1L),(-5L)},{(-1L),0xEC1AA655L,0x9C8EED80L,0x0BED20CAL},{0x3A0636EDL,(-1L),0x620E126EL,(-1L)}},{{1L,(-1L),(-3L),0L},{0x5A84B327L,0L,(-5L),0x9C8EED80L},{0x9C8EED80L,4L,0L,8L},{0x9C8EED80L,(-7L),(-5L),0x2F85340DL},{0x5A84B327L,8L,(-3L),0L}},{{1L,0L,0x620E126EL,0x53797119L},{0x3A0636EDL,0xB8D39A8AL,0x9C8EED80L,(-1L)},{(-1L),0x64D60197L,(-1L),0x3FDD2651L},{0x620E126EL,0x5B09E585L,(-1L),(-1L)},{0x6CA574B2L,0x6CA574B2L,0xEC1AA655L,4L}},{{0x64D60197L,0x2F85340DL,0x5B09E585L,0x3A0636EDL},{0L,(-1L),0x3C72134DL,0x5B09E585L},{(-1L),(-1L),0x53797119L,0x3A0636EDL},{(-1L),0x2F85340DL,0x227DF413L,4L},{0L,0x6CA574B2L,0x5187487DL,(-1L)}},{{0x08C26BBCL,0x5B09E585L,0x6CA574B2L,0x3FDD2651L},{(-7L),0x64D60197L,0x0BED20CAL,(-1L)},{(-3L),0xB8D39A8AL,(-1L),0x53797119L},{8L,0L,8L,0L},{(-1L),8L,0xC7C31EEAL,0x2F85340DL}},{{0x53797119L,(-7L),0x3A0636EDL,8L},{(-1L),4L,0x3A0636EDL,0x9C8EED80L},{0x53797119L,0L,0xC7C31EEAL,0L},{(-1L),(-1L),8L,(-1L)},{8L,(-1L),(-1L),0x0BED20CAL}},{{(-3L),0xEC1AA655L,0x0BED20CAL,(-5L)},{(-7L),(-1L),0x6CA574B2L,0xC7C31EEAL},{0x08C26BBCL,0x5187487DL,0x5187487DL,0x08C26BBCL},{0L,0x3A0636EDL,0x227DF413L,0L},{(-1L),(-1L),0x53797119L,0x5A84B327L}}};
        int32_t l_3780 = 1L;
        uint32_t l_3807[8] = {0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL};
        int16_t l_3822 = 0xB624L;
        uint32_t l_3909[7][2] = {{4294967295UL,0xDBB9B69CL},{0xDA67836AL,0xDBB9B69CL},{4294967295UL,0xA3043AE8L},{0xA3043AE8L,4294967295UL},{0xDBB9B69CL,0xDA67836AL},{0xDBB9B69CL,4294967295UL},{0xA3043AE8L,0xA3043AE8L}};
        uint32_t l_3937 = 9UL;
        int32_t l_3987 = 0x7570AEB1L;
        int i, j, k;
        l_3732 = (safe_add_func_int32_t_s_s(l_2408[3][0], (safe_rshift_func_uint8_t_u_u(((((safe_rshift_func_uint8_t_u_s(((((-10L) != (safe_mod_func_uint32_t_u_u(((-9L) > ((1L < (safe_lshift_func_int16_t_s_u(l_3732, (safe_rshift_func_uint16_t_u_u(l_2408[2][1], 2))))) != (safe_rshift_func_int16_t_s_u(((safe_rshift_func_uint16_t_u_s(g_1215[5], 5)) | (l_3732 || ((safe_add_func_int16_t_s_s(l_3492, 0x51BCL)) <= 0x9FL))), l_3492)))), 0x6935AA16L))) || g_2352[2]) != g_4), 5)) && l_3732) && l_3732) > l_3476), l_3732))));

{
                        uint32_t l_720 = 0UL;
                        int32_t l_721 = 7L;
                        l_3874[0] = (safe_sub_func_int16_t_s_s(((g_3957 = (safe_add_func_uint8_t_u_u(0x83L, (((safe_add_func_int8_t_s_s(g_172[4], (j = g_974))) ^ (~(l_2290 = (safe_rshift_func_int16_t_s_u((((safe_rshift_func_int8_t_s_s((l_721 = (4UL || ((-1L) == (((safe_lshift_func_uint8_t_u_s((safe_sub_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u(65535UL, 2)), (safe_rshift_func_int16_t_s_s((l_3872 && ((g_115 = ((safe_mod_func_uint8_t_u_u(((l_3937 < g_3957) && g_172[4]), 0x9AL)) <= g_3957)) != g_3957)), l_720)))), l_3513)) && 0x78L) ^ l_3513)))), 6)) || g_974) ^ 0xF1F3L), 3))))) || 6UL)))) & 0UL), 5UL));
                    }

                    if ((((g_2352[2] < (((safe_rshift_func_int16_t_s_s((((((safe_sub_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(0x91L)), (g_173 = 255UL))) && (g_949[0][6][1] & (safe_add_func_int32_t_s_s(((safe_unary_minus_func_int16_t_s((-1L))) && (safe_rshift_func_int16_t_s_s(((((i = l_2408[3][0]) > ((l_3755[0][0][5] = ((g_3421 = (g_2710 = 255UL)) ^ ((l_3752 != (((+((safe_unary_minus_func_uint16_t_u(((l_2674 && l_3492) < 9UL))) <= l_4035)) > l_3732) & l_3505)) == l_2266[3]))) || l_3732)) == l_3732) || 7L), l_4035))), i)))) == 0x1476L) & l_3752) & 4294967295UL), l_3732)) || 1UL) && 0x51L)) & g_2352[8]) | g_173))
        {
            int32_t l_3782 = (-1L);
            int32_t l_3783 = (-1L);
            uint32_t l_3784[6] = {1UL,0x277AD475L,1UL,1UL,0x277AD475L,1UL};
            int i;
            l_3492 = (((l_3732 = (g_2177[0][1][6] > 65535UL)) ^ (safe_mod_func_uint8_t_u_u(((l_3667 = (safe_rshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_u((l_3534 = (safe_lshift_func_uint8_t_u_u(255UL, (0UL > (l_3784[4] = (safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(i, 3)), (((l_3783 = (safe_lshift_func_uint8_t_u_s((l_3772[0][4][0] <= ((l_3359 = ((((safe_lshift_func_int8_t_s_u((l_4035 = g_315), 2)) != ((((safe_lshift_func_int16_t_s_u((g_543[1] = (((((((65534UL || (l_2526 = (safe_add_func_int16_t_s_s((l_3752 ^ l_3780), l_3667)))) || (-1L)) ^ g_173) == l_3782) || l_3782) ^ l_3755[0][1][1]) == g_543[1])), 2)) ^ g_315) == l_3782) <= g_2177[4][1][2])) && g_315) <= 0xCEL)) != 0UL)), 4))) || l_3492) && g_813[0][0])))))))), l_2418[3][4])), 1)), g_173))) | l_2266[4]), 0xE6L))) ^ g_2352[6]);
            l_3443 = 0x9DF8728DL;
        }
        else
        {
            uint32_t l_3796 = 18446744073709551615UL;
            int32_t l_3808 = (-1L);
            int32_t l_3812 = 0x5C3FB331L;
            for (l_4035 = 0; (l_4035 <= (-26)); l_4035 = safe_sub_func_uint32_t_u_u(l_4035, 4))
            {
                int32_t l_3789 = 0L;
                int32_t l_3793 = 0L;
                for (l_4035 = 0; (l_4035 != 4); l_4035 = safe_add_func_int32_t_s_s(l_4035, 2))
                {
                    int32_t l_3792[2][4];
                    int i, j;
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 4; j++)
                            l_3792[i][j] = 1L;
                    }
                    if ((((l_3789 <= (safe_sub_func_int16_t_s_s((0x931ABD91L > (l_3793 = l_3792[1][0])), (l_3796 | (l_2674 == (g_103 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(g_3781, 1)), 5)), l_3492)))))))) > (~(((g_172[5] ^ (safe_mod_func_uint8_t_u_u((~g_315), l_3807[1]))) > l_3808) && l_3257))) <= 0x50BC1107L))
                    {
                        i = (l_3443 = (0x9D645515L | (l_3792[1][3] && (l_3792[1][2] = ((+l_2526) <= g_173)))));
                    }
                    else
                    {
                        l_3812 = (l_3492 = (0L & ((g_315 | ((((g_173 || ((g_2177[1][1][3] = (l_3808 == (l_2601 = (65535UL != (((l_3171 = l_3796) < ((((safe_unary_minus_func_uint8_t_u(((g_2710 ^ ((+l_3573[1]) != l_3505)) > l_2292))) <= 8L) & l_3492) && 0x17F2086DL)) >= g_359[9][0]))))) != l_3792[0][1])) >= g_22) >= 0xB60DL) == 0x653A7DA3L)) != l_3359)));
                    }
                }
            }
            for (l_2674 = 0; (l_2674 <= 1); l_2674 += 1)
            {
                int16_t l_3827 = 0xA98EL;
                int32_t l_3837 = 0xC79C192DL;
                uint8_t l_3870 = 251UL;
                int32_t l_3892 = 0x9B48DECCL;
                uint32_t l_3910 = 1UL;
                int8_t l_3927 = 0x16L;
                for (l_3534 = 0; (l_3534 <= 5); l_3534 += 1)
                {
                    int32_t l_3828 = 0x3079516EL;
                    int i;
                    l_3828 = (l_3827 = (g_2352[(l_2674 + 4)] ^ (safe_mod_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((safe_add_func_int16_t_s_s((!g_1215[(l_2674 + 4)]), ((l_4035 = 3L) >= (((l_3822 = 1L) >= ((safe_sub_func_int8_t_s_s(0L, (safe_lshift_func_int8_t_s_u(0x39L, 4)))) != l_3573[1])) ^ ((0x2E9DL != l_3807[0]) || g_173))))), g_543[1])), 0x755FL)) <= g_172[4]), g_2177[1][3][3]))));
                    for (l_2601 = 0; (l_2601 <= 1); l_2601 += 1)
                    {
                        int i, j, k;
                        l_3732 = ((safe_rshift_func_int16_t_s_s(((((-1L) == ((((safe_sub_func_int32_t_s_s(0x814AF06EL, ((safe_mod_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(((l_3755[l_2674][l_2674][(l_2674 + 4)] != l_3837) <= (safe_unary_minus_func_uint16_t_u(l_3257))), l_4035)), l_3732)) < (l_3171 = (((safe_mod_func_uint32_t_u_u(((g_22 & (safe_lshift_func_uint8_t_u_s((safe_add_func_uint32_t_u_u(0xFCA458E4L, 0xFAFCB658L)), l_3828))) && 4294967290UL), g_172[3])) | (-1L)) == g_2352[(l_2674 + 4)]))))) | 0x96617425L) && l_3721) & g_359[9][0])) & 0UL) <= 1UL), 5)) || 0x45L);
                        return i;
                    }
                }
                for (l_3257 = 10; (l_3257 != 50); ++l_3257)
                {
                    uint32_t l_3851 = 18446744073709551615UL;
                    int8_t l_3871 = 3L;
                    uint32_t l_3897[8][4][7] = {{{18446744073709551612UL,0xE1836138L,0x850D52E1L,4UL,18446744073709551612UL,18446744073709551615UL,18446744073709551615UL},{0x66203650L,18446744073709551612UL,6UL,18446744073709551612UL,0x66203650L,0x325F3AE1L,4UL},{18446744073709551606UL,0x19A3FC88L,18446744073709551615UL,0x43272F40L,0x3D0A099DL,1UL,0x66203650L},{18446744073709551614UL,18446744073709551606UL,0UL,18446744073709551614UL,18446744073709551612UL,0UL,0UL}},{{18446744073709551606UL,0x43272F40L,6UL,1UL,18446744073709551606UL,18446744073709551615UL,1UL},{0x66203650L,1UL,0x3D0A099DL,0x43272F40L,18446744073709551615UL,0x19A3FC88L,18446744073709551606UL},{1UL,0x850D52E1L,0x3D0A099DL,18446744073709551615UL,0x2C9ACB3CL,18446744073709551615UL,0x3D0A099DL},{18446744073709551612UL,18446744073709551612UL,6UL,0xA92A9589L,0xFD09A0FAL,18446744073709551606UL,4UL}},{{0xA92A9589L,18446744073709551615UL,0UL,0UL,0x19A3FC88L,0UL,18446744073709551612UL},{0UL,0x850D52E1L,18446744073709551615UL,0x3D0A099DL,0xFD09A0FAL,0UL,0xB93E9277L},{18446744073709551606UL,4UL,6UL,18446744073709551612UL,0x2C9ACB3CL,0x333F6AB0L,18446744073709551606UL},{0xA92A9589L,0UL,0x1077E5E4L,0x66203650L,18446744073709551615UL,18446744073709551606UL,18446744073709551606UL}},{{18446744073709551615UL,18446744073709551606UL,0x19A3FC88L,0x19A3FC88L,18446744073709551606UL,18446744073709551615UL,0xB93E9277L},{4UL,0UL,0x7FF5CEFEL,0xA92A9589L,18446744073709551612UL,0x4DEDE24EL,18446744073709551612UL},{0x66203650L,18446744073709551615UL,0x37F1B27FL,18446744073709551612UL,0x3D0A099DL,18446744073709551606UL,4UL},{0UL,0UL,18446744073709551615UL,0UL,0x66203650L,1UL,0x3D0A099DL}},{{1UL,18446744073709551606UL,18446744073709551615UL,1UL,18446744073709551612UL,0x87551765L,18446744073709551606UL},{18446744073709551606UL,0UL,18446744073709551615UL,1UL,0UL,0UL,1UL},{0x3D0A099DL,4UL,0x3D0A099DL,0UL,18446744073709551612UL,0x19A3FC88L,0UL},{4UL,0x850D52E1L,0xE1836138L,18446744073709551612UL,0x2C9ACB3CL,6UL,0x66203650L}},{{18446744073709551612UL,18446744073709551615UL,18446744073709551615UL,0xA92A9589L,0x1077E5E4L,0x19A3FC88L,4UL},{0xB93E9277L,18446744073709551612UL,0UL,0x19A3FC88L,0UL,0UL,18446744073709551615UL},{18446744073709551606UL,0x850D52E1L,0x4DEDE24EL,0x66203650L,0xFD09A0FAL,0x87551765L,0xA92A9589L},{18446744073709551606UL,1UL,0x37F1B27FL,18446744073709551612UL,0x37F1B27FL,1UL,18446744073709551606UL}},{{0xB93E9277L,0x43272F40L,0x1077E5E4L,0x3D0A099DL,18446744073709551612UL,18446744073709551606UL,0UL},{18446744073709551612UL,18446744073709551606UL,18446744073709551606UL,0UL,18446744073709551606UL,0x4DEDE24EL,0xA92A9589L},{4UL,0x19A3FC88L,0x1077E5E4L,0xA92A9589L,18446744073709551615UL,18446744073709551615UL,18446744073709551612UL},{0x3D0A099DL,18446744073709551612UL,0x37F1B27FL,18446744073709551615UL,0x66203650L,18446744073709551606UL,0UL}},{{0x3D0A099DL,0UL,18446744073709551612UL,18446744073709551606UL,0x19A3FC88L,0xA92A9589L,0x19A3FC88L},{18446744073709551615UL,0x32647471L,0x32647471L,18446744073709551615UL,0x333F6AB0L,0x325F3AE1L,0x3D0A099DL},{0xE1836138L,18446744073709551606UL,0x333F6AB0L,0x4DEDE24EL,18446744073709551614UL,0x32647471L,0x4DEDE24EL},{0x19A3FC88L,0xB93E9277L,0UL,18446744073709551606UL,18446744073709551615UL,18446744073709551606UL,0x3D0A099DL}}};
                    int32_t l_3916 = (-1L);
                    int i, j, k;
                    if ((((((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((l_3851 != (((l_2526 = (l_3812 = (l_2526 = (-7L)))) & ((0x1404L == 0xBA1BL) <= ((-8L) ^ (((i = (safe_rshift_func_int16_t_s_u((i && (safe_mod_func_uint16_t_u_u((((((safe_sub_func_int32_t_s_s((safe_add_func_int32_t_s_s(((safe_mod_func_int16_t_s_s((g_1524 = (((((l_3851 ^ (safe_mod_func_int32_t_s_s((safe_add_func_uint32_t_u_u(g_543[1], (safe_mod_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((0x6EL >= g_172[4]), l_3870)), g_866[4][9])))), l_2601))) < 0xBD537FA9L) > 0UL) | l_3851) < 65532UL)), 8L)) | l_3443), l_2408[1][0])), l_3492)) > g_3421) > l_3822) | l_3424[1][1][4]) && l_3871), 1L))), l_3808))) == (-5L)) | j)))) & l_3808)), 2)), 0x0BL)) == g_2352[8]) <= g_2352[0]) <= l_4035) >= l_3807[6]))
                    {
                        l_3892 = (safe_sub_func_uint32_t_u_u(((g_103 != (g_1524 = (((safe_mod_func_uint8_t_u_u((g_3421 & (l_3872 = (safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_s(65534UL, 15)) == (g_813[5][0] = ((safe_add_func_uint8_t_u_u(((((g_359[9][0] && (safe_lshift_func_uint8_t_u_s(l_3780, 2))) <= l_3851) <= g_2352[2]) != 1UL), ((safe_add_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u((l_3667 = l_3796), l_2601)) == l_3755[0][0][5]), g_3421)) & i))) || 0xD0F0L))), l_3871)))), 1L)) & l_2266[3]) < g_2352[4]))) & l_3871), l_3808));
                    }
                    else
                    {

if ((((l_3874[2] < (((safe_rshift_func_int16_t_s_s((((((safe_sub_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(0x91L)), (g_217 = 255UL))) && (g_949[0][6][1] & (safe_add_func_int32_t_s_s(((safe_unary_minus_func_int16_t_s((-1L))) && (safe_rshift_func_int16_t_s_s(((((l_3873 = l_2408[3][0]) > ((l_3755[0][0][5] = ((g_3421 = (g_12 = 255UL)) ^ ((g_3421 != (((+((safe_unary_minus_func_uint16_t_u(((g_12 && l_3017) < 9UL))) <= l_3927)) > l_3017) & l_2841)) == g_3956[3]))) || l_3017)) == l_3017) || 7L), l_3927))), g_2576)))) == 0x1476L) & g_3421) & 4294967295UL), l_3017)) || 1UL) && 0x51L)) & l_3874[8]) | g_173))
        {
            int32_t l_3782 = (-1L);
            int32_t l_3783 = (-1L);
            uint32_t l_3784[6] = {1UL,0x277AD475L,1UL,1UL,0x277AD475L,1UL};
            int i;
            l_3987 = (((l_3017 = (g_2177[0][1][6] > 65535UL)) ^ (safe_mod_func_uint8_t_u_u(((l_3927 = (safe_rshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_u((l_3702 = (safe_lshift_func_uint8_t_u_u(255UL, (0UL > (l_3784[4] = (safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(l_3873, 3)), (((l_3783 = (safe_lshift_func_uint8_t_u_s((l_3772[0][4][0] <= ((l_3017 = ((((safe_lshift_func_int8_t_s_u((l_3927 = l_3398), 2)) != ((((safe_lshift_func_int16_t_s_u((g_543[1] = (((((((65534UL || (g_3409 = (safe_add_func_int16_t_s_s((g_3421 ^ l_3732), l_3339)))) || (-1L)) ^ g_173) == l_3782) || l_3782) ^ l_3755[0][1][1]) == g_543[1])), 2)) ^ l_3373) == l_3782) <= g_2177[4][1][2])) && l_3398) <= 0xCEL)) != 0UL)), 4))) || l_3017) && g_813[0][0])))))))), l_2418[3][4])), 1)), g_3421))) | g_3956[4]), 0xE6L))) ^ l_3874[6]);
            l_3732 = 0x9DF8728DL;
        }
        else
        {
            uint32_t l_3796 = 18446744073709551615UL;
            int32_t l_3808 = (-1L);
            int32_t l_3812 = 0x5C3FB331L;
            for (l_2465 = 0; (l_2465 <= (-26)); l_2465 = safe_sub_func_uint32_t_u_u(l_2465, 4))
            {
                int32_t l_3789 = 0L;
                int32_t l_3793 = 0L;
                for (l_3927 = 0; (l_3927 != 4); l_3927 = safe_add_func_int32_t_s_s(l_3927, 2))
                {
                    int32_t l_3792[2][4];
                    int i, j;
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 4; j++)
                            l_3792[i][j] = 1L;
                    }
                    if ((((l_3789 <= (safe_sub_func_int16_t_s_s((0x931ABD91L > (l_3793 = l_3792[1][0])), (l_3796 | (g_12 == (l_3851 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(l_2465, 1)), 5)), l_3017)))))))) > (~(((g_172[5] ^ (safe_mod_func_uint8_t_u_u((~l_3398), l_3807[1]))) > l_3808) && g_540))) <= 0x50BC1107L))
                    {
                        l_3873 = (l_3732 = (0x9D645515L | (l_3792[1][3] && (l_3792[1][2] = ((+g_3409) <= g_3421)))));
                    }
                    else
                    {
                        l_3812 = (l_3017 = (0L & ((l_3373 | ((((g_3421 || ((g_2177[1][1][3] = (l_3808 == (g_974 = (65535UL != (((g_3261 = l_3796) < ((((safe_unary_minus_func_uint8_t_u(((g_12 ^ ((+l_3573[1]) != l_2841)) > g_1129))) <= 8L) & l_3017) && 0x17F2086DL)) >= g_359[9][0]))))) != l_3792[0][1])) >= g_3484) >= 0xB60DL) == 0x653A7DA3L)) != l_3017)));
                    }
                }
            }
            for (g_12 = 0; (g_12 <= 1); g_12 += 1)
            {
                int16_t l_3827 = 0xA98EL;
                int32_t l_3837 = 0xC79C192DL;
                uint8_t l_3870 = 251UL;
                int32_t l_3892 = 0x9B48DECCL;
                uint32_t l_3910 = 1UL;
                int8_t l_3927 = 0x16L;
                for (l_3398 = 0; (l_3398 <= 5); l_3398 += 1)
                {
                    int32_t l_3828 = 0x3079516EL;
                    int i;
                    l_3828 = (l_3827 = (l_3874[(g_12 + 4)] ^ (safe_mod_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((safe_add_func_int16_t_s_s((!g_1215[(g_12 + 4)]), ((l_2465 = 3L) >= (((g_188 = 1L) >= ((safe_sub_func_int8_t_s_s(0L, (safe_lshift_func_int8_t_s_u(0x39L, 4)))) != l_3573[1])) ^ ((0x2E9DL != l_3807[0]) || g_3421))))), g_543[1])), 0x755FL)) <= g_172[4]), g_2177[1][3][3]))));
                    for (g_974 = 0; (g_974 <= 1); g_974 += 1)
                    {
                        int i, j, k;
                        l_3017 = ((safe_rshift_func_int16_t_s_s(((((-1L) == ((((safe_sub_func_int32_t_s_s(0x814AF06EL, ((safe_mod_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(((l_3755[g_12][g_12][(g_12 + 4)] != l_3837) <= (safe_unary_minus_func_uint16_t_u(l_3796))), l_2465)), l_3017)) < (g_3261 = (((safe_mod_func_uint32_t_u_u(((g_3484 & (safe_lshift_func_uint8_t_u_s((safe_add_func_uint32_t_u_u(0xFCA458E4L, 0xFAFCB658L)), l_3828))) && 4294967290UL), g_172[3])) | (-1L)) == l_3874[(g_12 + 4)]))))) | 0x96617425L) && l_2296) & g_359[9][0])) & 0UL) <= 1UL), 5)) || 0x45L);
                        return l_3873;
                    }
                }
                for (g_540 = 10; (g_540 != 50); ++g_540)
                {
                    uint32_t l_3851 = 18446744073709551615UL;
                    int8_t l_3871 = 3L;
                    uint32_t l_3897[8][4][7] = {{{18446744073709551612UL,0xE1836138L,0x850D52E1L,4UL,18446744073709551612UL,18446744073709551615UL,18446744073709551615UL},{0x66203650L,18446744073709551612UL,6UL,18446744073709551612UL,0x66203650L,0x325F3AE1L,4UL},{18446744073709551606UL,0x19A3FC88L,18446744073709551615UL,0x43272F40L,0x3D0A099DL,1UL,0x66203650L},{18446744073709551614UL,18446744073709551606UL,0UL,18446744073709551614UL,18446744073709551612UL,0UL,0UL}},{{18446744073709551606UL,0x43272F40L,6UL,1UL,18446744073709551606UL,18446744073709551615UL,1UL},{0x66203650L,1UL,0x3D0A099DL,0x43272F40L,18446744073709551615UL,0x19A3FC88L,18446744073709551606UL},{1UL,0x850D52E1L,0x3D0A099DL,18446744073709551615UL,0x2C9ACB3CL,18446744073709551615UL,0x3D0A099DL},{18446744073709551612UL,18446744073709551612UL,6UL,0xA92A9589L,0xFD09A0FAL,18446744073709551606UL,4UL}},{{0xA92A9589L,18446744073709551615UL,0UL,0UL,0x19A3FC88L,0UL,18446744073709551612UL},{0UL,0x850D52E1L,18446744073709551615UL,0x3D0A099DL,0xFD09A0FAL,0UL,0xB93E9277L},{18446744073709551606UL,4UL,6UL,18446744073709551612UL,0x2C9ACB3CL,0x333F6AB0L,18446744073709551606UL},{0xA92A9589L,0UL,0x1077E5E4L,0x66203650L,18446744073709551615UL,18446744073709551606UL,18446744073709551606UL}},{{18446744073709551615UL,18446744073709551606UL,0x19A3FC88L,0x19A3FC88L,18446744073709551606UL,18446744073709551615UL,0xB93E9277L},{4UL,0UL,0x7FF5CEFEL,0xA92A9589L,18446744073709551612UL,0x4DEDE24EL,18446744073709551612UL},{0x66203650L,18446744073709551615UL,0x37F1B27FL,18446744073709551612UL,0x3D0A099DL,18446744073709551606UL,4UL},{0UL,0UL,18446744073709551615UL,0UL,0x66203650L,1UL,0x3D0A099DL}},{{1UL,18446744073709551606UL,18446744073709551615UL,1UL,18446744073709551612UL,0x87551765L,18446744073709551606UL},{18446744073709551606UL,0UL,18446744073709551615UL,1UL,0UL,0UL,1UL},{0x3D0A099DL,4UL,0x3D0A099DL,0UL,18446744073709551612UL,0x19A3FC88L,0UL},{4UL,0x850D52E1L,0xE1836138L,18446744073709551612UL,0x2C9ACB3CL,6UL,0x66203650L}},{{18446744073709551612UL,18446744073709551615UL,18446744073709551615UL,0xA92A9589L,0x1077E5E4L,0x19A3FC88L,4UL},{0xB93E9277L,18446744073709551612UL,0UL,0x19A3FC88L,0UL,0UL,18446744073709551615UL},{18446744073709551606UL,0x850D52E1L,0x4DEDE24EL,0x66203650L,0xFD09A0FAL,0x87551765L,0xA92A9589L},{18446744073709551606UL,1UL,0x37F1B27FL,18446744073709551612UL,0x37F1B27FL,1UL,18446744073709551606UL}},{{0xB93E9277L,0x43272F40L,0x1077E5E4L,0x3D0A099DL,18446744073709551612UL,18446744073709551606UL,0UL},{18446744073709551612UL,18446744073709551606UL,18446744073709551606UL,0UL,18446744073709551606UL,0x4DEDE24EL,0xA92A9589L},{4UL,0x19A3FC88L,0x1077E5E4L,0xA92A9589L,18446744073709551615UL,18446744073709551615UL,18446744073709551612UL},{0x3D0A099DL,18446744073709551612UL,0x37F1B27FL,18446744073709551615UL,0x66203650L,18446744073709551606UL,0UL}},{{0x3D0A099DL,0UL,18446744073709551612UL,18446744073709551606UL,0x19A3FC88L,0xA92A9589L,0x19A3FC88L},{18446744073709551615UL,0x32647471L,0x32647471L,18446744073709551615UL,0x333F6AB0L,0x325F3AE1L,0x3D0A099DL},{0xE1836138L,18446744073709551606UL,0x333F6AB0L,0x4DEDE24EL,18446744073709551614UL,0x32647471L,0x4DEDE24EL},{0x19A3FC88L,0xB93E9277L,0UL,18446744073709551606UL,18446744073709551615UL,18446744073709551606UL,0x3D0A099DL}}};
                    int32_t l_3916 = (-1L);
                    int i, j, k;
                    if ((((((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((l_3851 != (((l_2526 = (l_3812 = (g_3409 = (-7L)))) & ((0x1404L == 0xBA1BL) <= ((-8L) ^ (((g_2476 = (safe_rshift_func_int16_t_s_u((l_3873 && (safe_mod_func_uint16_t_u_u((((((safe_sub_func_int32_t_s_s((safe_add_func_int32_t_s_s(((safe_mod_func_int16_t_s_s((l_2601 = (((((l_3851 ^ (safe_mod_func_int32_t_s_s((safe_add_func_uint32_t_u_u(g_543[1], (safe_mod_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((0x6EL >= g_172[4]), l_3870)), g_866[4][9])))), g_974))) < 0xBD537FA9L) > 0UL) | l_3851) < 65532UL)), 8L)) | l_3732), l_2408[1][0])), l_3017)) > g_3421) > g_188) | l_3424[1][1][4]) && l_3871), 1L))), l_3808))) == (-5L)) | l_3873)))) & l_3808)), 2)), 0x0BL)) == l_3874[8]) <= l_3874[0]) <= l_3927) >= l_3807[6]))
                    {
                        l_3892 = (safe_sub_func_uint32_t_u_u(((g_540 != (l_2601 = (((safe_mod_func_uint8_t_u_u((g_3421 & (g_2476 = (safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_s(65534UL, 15)) == (g_813[5][0] = ((safe_add_func_uint8_t_u_u(((((g_359[9][0] && (safe_lshift_func_uint8_t_u_s(l_3732, 2))) <= l_3851) <= l_3874[2]) != 1UL), ((safe_add_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u((l_3927 = l_3796), g_974)) == l_3755[0][0][5]), g_3421)) & l_3873))) || 0xD0F0L))), l_3871)))), 1L)) & g_3956[3]) < l_3874[4]))) & l_3871), l_3808));
                    }
                    else
                    {
                        return g_1215[3];
                    }
                    for (i = 0; (i <= 27); i++)
                    {
                        uint32_t l_3907 = 4294967295UL;
                        l_3808 = g_3421;
                        l_3873 = ((safe_sub_func_uint32_t_u_u(0xBE8ABD83L, (((g_2177[3][1][9] = (l_3897[2][0][0] = g_974)) ^ (((l_3910 = (((safe_mod_func_int16_t_s_s((safe_add_func_uint16_t_u_u((((((~65535UL) > l_3017) == l_3892) != l_3732) < (((safe_rshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s(l_3907, 1L)), 4)) == (l_3476 = (-6L))) < l_2841)), l_3851)), l_3909[0][0])) && l_3873) <= 0x9386A289L)) > l_3874[2]) >= l_3987)) | 0x77F0A1CDL))) < g_3484);
                    }
                    l_3873 = (safe_add_func_uint32_t_u_u((l_2841 = ((+((((l_3916 = (safe_rshift_func_int8_t_s_u((-10L), 7))) && ((safe_unary_minus_func_int16_t_s((1L && (safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u((l_3398 < ((g_172[4] >= (0xBEL && (l_2790[4][0] >= ((3L < (safe_sub_func_int8_t_s_s((((safe_sub_func_int16_t_s_s((((((~l_3796) >= l_3927) < l_3017) && l_3398) | g_1215[4]), 0x3FC3L)) && 0x9294L) & l_3851), l_2601))) == g_3261)))) == g_2476)), l_3873)), l_2526))))) == g_3421)) & l_3987) > l_3398)) && l_3910)), g_217));
                    return l_3732;
                }
                if (g_2177[4][0][3])
                    continue;
            }
        };


                    return g_1215[3];
                    }
                    for (l_3443 = 0; (l_3443 <= 27); l_3443++)
                    {
                        uint32_t l_3907 = 4294967295UL;
                        l_3808 = g_3421;
                        i = ((safe_sub_func_uint32_t_u_u(0xBE8ABD83L, (((g_2177[3][1][9] = (l_3897[2][0][0] = l_2601)) ^ (((l_3910 = (((safe_mod_func_int16_t_s_s((safe_add_func_uint16_t_u_u((((((~65535UL) > l_3492) == l_3892) != l_3443) < (((safe_rshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s(l_3907, 1L)), 4)) == (i = (-6L))) < l_3505)), l_3851)), l_3909[0][0])) && i) <= 0x9386A289L)) > g_2352[2]) >= l_3492)) | 0x77F0A1CDL))) < g_22);
                    }
                    i = (safe_add_func_uint32_t_u_u((l_3505 = ((+((((l_3916 = (safe_rshift_func_int8_t_s_u((-10L), 7))) && ((safe_unary_minus_func_int16_t_s((1L && (safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u((g_315 < ((g_172[4] >= (0xBEL && (l_2790[4][0] >= ((3L < (safe_sub_func_int8_t_s_s((((safe_sub_func_int16_t_s_s((((((~l_3796) >= l_3927) < l_3732) && g_315) | g_1215[4]), 0x3FC3L)) && 0x9294L) & g_103), g_1524))) == l_3171)))) == l_3872)), i)), l_2526))))) == g_3421)) & l_3492) > g_315)) && l_3910)), g_173));
                    return l_3780;
                }
                if (g_2177[4][0][3])
                    continue;
            }
        }
        l_3780 = g_949[0][8][6];
        if ((g_3152 = (safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(3L, 11)), (safe_lshift_func_uint8_t_u_u(l_3257, (safe_add_func_int32_t_s_s((l_3937 = (l_3443 = (safe_unary_minus_func_int32_t_s((i = ((4294967288UL > ((l_3171 = 0x2816L) | l_3732)) & (l_3257 && g_359[9][0]))))))), ((6UL == ((0x973FL <= l_3667) && l_2418[5][4])) > g_359[9][0])))))))))
        {
            l_3772[2][2][0] = l_3492;
            l_3443 = (0L & 0x34L);
        }
        else
        {
            int32_t l_3960 = (-4L);
            int8_t l_3991[1][5] = {{(-9L),(-9L),(-9L),(-9L),(-9L)}};
            int32_t l_4020 = 0x4B3E2823L;
            int i, j;
            for (g_2710 = (-28); (g_2710 < 46); ++g_2710)
            {
                int16_t l_3951 = 0x1704L;
                int32_t l_3955[7][7] = {{0x94E9D490L,(-3L),0xF4171F52L,(-3L),0x94E9D490L,0x94E9D490L,(-3L)},{(-1L),0xB5D7E716L,(-1L),0x3C2EED67L,0x3C2EED67L,(-1L),0xB5D7E716L},{(-3L),(-8L),0xF4171F52L,0xF4171F52L,(-8L),(-3L),(-8L)},{(-1L),0x3C2EED67L,0x3C2EED67L,(-1L),0xB5D7E716L,(-1L),0x3C2EED67L},{0x94E9D490L,0x94E9D490L,(-3L),0xF4171F52L,(-3L),0x94E9D490L,0x94E9D490L},{0xCBAC2FE8L,0x3C2EED67L,1L,0x3C2EED67L,0xCBAC2FE8L,0xCBAC2FE8L,0x3C2EED67L},{(-1L),(-8L),(-1L),(-3L),(-3L),(-1L),(-8L)}};
                int8_t l_4032 = 8L;
                int i, j;
                for (l_2674 = 0; (l_2674 >= 29); l_2674++)
                {
                    uint8_t l_3954 = 0xF9L;
                    l_3257 = (g_813[2][0] != (safe_add_func_uint32_t_u_u(((l_3807[4] & 1UL) > (safe_lshift_func_uint8_t_u_s((!l_3721), 6))), ((0L | (((l_3955[3][0] = (((safe_lshift_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(l_3951, 12)) & (safe_sub_func_int16_t_s_s(g_315, (g_315 = (1L <= g_3152))))), l_3954)) | 0xC3L) && 0L)) || 1UL) & l_2266[2])) != l_3667))));
                }
                for (g_315 = 0; (g_315 > 34); ++g_315)
                {
                    uint32_t l_3973 = 0x4C44CE71L;
                    int8_t l_3988[10] = {(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L)};
                    int32_t l_4033 = (-1L);
                    int32_t l_4034 = 0x9751D3BDL;
                    int i;
                    l_3492 = ((((l_3492 ^ (g_3421 = ((l_3960 | (safe_add_func_int8_t_s_s(0x29L, ((safe_add_func_int8_t_s_s(((safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s(l_4035, g_2352[2])), g_949[0][6][1])) == l_3534), ((safe_sub_func_int32_t_s_s(l_2601, ((safe_add_func_int16_t_s_s((1L <= g_103), i)) && g_172[6]))) != l_3960))) <= 0x1406L)))) ^ 255UL))) == l_3960) <= l_3973) && l_3951);
                    for (l_3752 = 0; (l_3752 <= 8); l_3752 += 1)
                    {
                        uint8_t l_3986 = 0UL;
                        int32_t l_4009[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_4009[i] = 1L;
                        l_3732 = (l_3492 = (l_3988[7] = (safe_add_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((g_2352[l_3752] || 254UL), (safe_rshift_func_int16_t_s_s(j, 11)))) == (((-9L) >= ((((safe_rshift_func_int8_t_s_u(g_103, (l_3960 && (safe_rshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u(((g_2177[3][1][9] = (((g_173 || ((l_3822 && ((0x690DL <= l_3909[0][0]) | l_3986)) | l_3987)) && 0x59DE2E1CL) || 0x0ECC5B70L)) < l_3986), 9)), i))))) < g_2352[l_3752]) & g_103) > l_3986)) > l_3973)), 65533UL))));
                        l_3492 = (g_543[2] == 4294967295UL);
                        i = (l_3443 = (safe_rshift_func_uint8_t_u_u(l_3991[0][2], (l_3807[0] > (safe_rshift_func_uint16_t_u_s((+(0xF87CL < l_3257)), (g_1524 = (safe_lshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u((((+(1UL <= (safe_sub_func_int8_t_s_s(((l_3937 > (((+(l_4009[1] = ((safe_add_func_uint32_t_u_u(g_2352[8], (safe_rshift_func_uint8_t_u_u((l_2601 & (l_3991[0][2] && l_4035)), g_2352[l_3752])))) ^ l_3667))) & g_359[9][0]) >= l_2674)) | i), 0x23L)))) == l_3492) >= l_3667), l_3988[2])), l_3937)), 6)))))))));
                    }
                    for (i = 0; (i < 12); i = safe_add_func_int32_t_s_s(i, 7))
                    {
                        return l_2601;
                    }
                    l_2266[1] = (safe_lshift_func_int16_t_s_s((l_3960 != ((l_3359 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_uint8_t_u_u((safe_mod_func_int16_t_s_s((l_4020 = (g_543[2] = 0x7667L)), (((safe_add_func_int16_t_s_s((l_3988[6] ^ (l_4034 = (l_4033 = (((safe_sub_func_uint8_t_u_u(g_173, l_3955[3][0])) & ((safe_add_func_uint16_t_u_u(((1UL >= i) || ((safe_unary_minus_func_int16_t_s(g_2177[3][1][9])) | (safe_rshift_func_uint8_t_u_u(((((safe_sub_func_uint32_t_u_u(((((-1L) < g_173) | 248UL) || l_3991[0][3]), l_3171)) > l_3991[0][2]) & l_4032) & l_2674), l_4035)))), g_3421)) != l_2601)) || 248UL)))), l_3960)) <= 0x3193CC09L) | l_3991[0][1]))), l_3955[4][6])), 0))) || l_4034)), l_3492));
                }
            }
        }
    }

                    if ((((g_3409 == 0x87L) != (g_12 = 0UL)) ^ g_3409))
                    {
                        l_3506[3] = ((0x63D96127L || l_3359) > (0xE625L || l_3505));
                    }
                    else
                    {
                        int8_t l_3520 = 0x2EL;
                        l_3359 = 0x132D1CFBL;
                        g_22 = (((l_3340 = (((((l_2292 >= (g_1129 = ((0xA6C9L | (safe_mod_func_int8_t_s_s((safe_sub_func_int32_t_s_s(g_4, l_3351[3])), l_3372[0]))) & (safe_mod_func_uint16_t_u_u(((l_3513 < (safe_sub_func_uint32_t_u_u(((safe_rshift_func_int8_t_s_s(g_866[0][1], (((safe_sub_func_int8_t_s_s((g_813[6][0] && g_247), 255UL)) > 1L) || 0xA69DCD2EL))) | l_3520), g_161))) ^ l_3372[3]), g_1129))))) == 0xA3DB543AL) && l_3520) != 0x5621L) & g_974)) >= g_188) | g_4);
                    }
                    g_3258 = g_1129;
                }
            }
        }
        g_2476 = ((((g_247 = (g_543[1] | (safe_add_func_int16_t_s_s(g_2352[0], (((1UL ^ g_103) < l_3340) < (g_3421 = (safe_sub_func_uint32_t_u_u(((safe_add_func_uint32_t_u_u((l_2408[0][2] == ((~(((((safe_add_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(l_3534, (safe_mod_func_uint8_t_u_u(g_866[7][7], (safe_sub_func_uint32_t_u_u((((((((l_3352[0] < l_2292) >= 0x780BL) != l_3398) ^ 0L) < (-1L)) | g_63) ^ g_83), l_2408[3][0])))))) <= 0UL), l_3351[3])) & 4294967295UL) || (-1L)) != (-1L)) < l_2408[0][5])) > g_3258)), g_1524)) & l_3398), (-6L))))))))) >= g_172[7]) == g_115) == l_2292);
        return l_3398;
    }
    if ((+(safe_add_func_int32_t_s_s((l_2408[3][4] = (((g_3261 || (safe_sub_func_uint16_t_u_u(((l_2266[3] = (l_2841 ^ (safe_add_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((~((safe_lshift_func_int8_t_s_s((((l_2290 = l_3534) <= (((safe_add_func_uint8_t_u_u((((0xADFAL <= g_63) & (l_2601 && g_103)) < (-2L)), ((l_3116 < g_315) ^ g_3484))) < 7UL) ^ l_2266[3])) | g_3484), g_12)) || l_5[1][6])), g_188)), 0x16L)))) || l_3116), 0x5C64L))) >= g_1215[3]) & g_22)), l_3408))))
    {
        int32_t l_3561 = 0xC7A6A094L;
        int32_t l_3562[7];
        int32_t l_3639 = 0x57E1FCD6L;
        int i;

for (l_3116 = 0; l_3116 < 7; l_3116++)
        {
            transparent_crc(g_359[l_3891][l_3116], "g_359[l_3891][l_3116]", l_3017);
            if (l_3017) printf("index = [%d][%d]\n", l_3891, l_3116);

        };



if (l_3908) printf("index = [%d][%d][%d]\n", l_3721, g_247, k);

                    for (i = 0; i < 7; i++)
            {
if (g_2177[4][0][3])
                    continue;

                    l_3562[i] = 0xF6374F20L;}
        if ((safe_rshift_func_uint16_t_u_s((g_3409 < (safe_sub_func_uint8_t_u_u((g_1129 = (safe_sub_func_uint16_t_u_u(((l_3561 = 0xFE00L) > l_3562[1]), g_866[5][2]))), ((safe_rshift_func_int8_t_s_s((safe_sub_func_int16_t_s_s(g_813[1][0], ((g_2576 >= (safe_add_func_uint32_t_u_u(((safe_mul_func_int32_t_s_s((g_2476 = (((0UL > ((g_63 > ((safe_add_func_int8_t_s_s((g_2576 <= 0xAE4AL), 0x0CL)) >= 255UL)) ^ 0xBAED8CF2L)) == g_12) && 0L)), 0L)) || l_3562[1]), 0xFBC96193L))) == (-9L)))), 6)) == g_247)))), l_3573[1])))
        {
            l_3562[1] = 1L;
        }
        else
        {
            int16_t l_3588 = 9L;
            int32_t l_3622[9][5] = {{3L,0x6BA56314L,1L,0x10275A46L,0L},{0x10275A46L,(-7L),4L,4L,(-7L)},{0L,1L,5L,4L,0x99AB53BFL},{1L,0x99AB53BFL,0x528214A4L,0x10275A46L,0x6BA56314L},{1L,(-10L),0L,0x6BA56314L,0x888D88CAL},{1L,1L,0x888D88CAL,1L,1L},{0L,0x366C108CL,0x888D88CAL,0L,1L},{0x10275A46L,8L,0L,5L,3L},{3L,1L,0x528214A4L,0x366C108CL,1L}};
            uint16_t l_3664 = 8UL;
            int i, j;
            for (g_2598 = 2; (g_2598 >= 7); ++g_2598)
            {
                uint8_t l_3587[6];
                int32_t l_3614 = 0x78771F22L;
                int32_t l_3615[3];
                int i;
                for (i = 0; i < 6; i++)
                    l_3587[i] = 248UL;

{
                return l_3492;
            }

                    for (i = 0; i < 3; i++)
                    l_3615[i] = 0x1058D4E6L;
                g_2576 = (0x2024L >= (safe_rshift_func_int16_t_s_u((0xA3L && 0x6BL), l_3561)));
                g_2476 = (g_1129 <= ((((l_2408[3][0] = (safe_rshift_func_uint8_t_u_u(((safe_add_func_int32_t_s_s((0x3CA5L >= ((safe_mod_func_uint8_t_u_u(0x91L, l_3562[5])) >= l_3562[1])), (1L | 0x184E7879L))) != l_3257), ((safe_rshift_func_uint16_t_u_u((~(g_813[4][0] = 2UL)), l_3561)) | l_3587[3])))) && 0x2CB018B9L) & g_3421) == l_3588));
                g_3258 = l_3116;
                l_3615[2] = ((((g_361 = (((safe_sub_func_int8_t_s_s((-2L), (safe_rshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u(7UL, ((255UL != (safe_sub_func_int32_t_s_s((safe_mod_func_uint32_t_u_u(((g_2352[2] ^ (0xC0D53A6EL | (l_3614 = (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_int32_t_s((((g_3261 & (safe_sub_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s(((((safe_lshift_func_uint16_t_u_u((safe_add_func_int8_t_s_s((g_4 ^ l_2465), (l_2266[3] = ((safe_lshift_func_int16_t_s_u((g_2177[3][0][1] | 0L), g_974)) == 7L)))), g_173)) > 0x266CL) >= g_974) <= g_538), 2)) == 0L), 0UL)), 1UL))) >= g_3409) != (-1L)))), 11))))) ^ l_2290), l_3562[6])), l_3424[1][0][0]))) >= 0x63A0L))), l_3587[4])))) & l_3587[5]) | g_3261)) ^ 254UL) <= l_3424[1][2][3]) || l_3614);
            }
            l_3471 = g_2177[3][1][9];

g_2476 -= 1;


                    g_2576 = (safe_unary_minus_func_uint8_t_u(1UL));
            if (g_172[7])
            {
                uint16_t l_3621 = 8UL;
                uint16_t l_3638[10][1][6] = {{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}}};
                int32_t l_3656 = 0x6C16DA66L;
                uint16_t l_3666 = 65535UL;
                int32_t l_3681 = 0L;
                int i, j, k;
                g_247 = g_3258;
                l_3622[1][1] = ((1UL | (safe_mod_func_int16_t_s_s((g_22 & l_3588), l_3562[1]))) == (g_2177[3][1][9] = (safe_lshift_func_int8_t_s_u(l_3621, 5))));
                if ((safe_add_func_int8_t_s_s((g_3409 = (g_2420 = (safe_lshift_func_uint8_t_u_u(((~0xACL) || (((g_974 && (safe_mod_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(((-1L) ^ (g_3258 = ((g_813[3][0] == (l_3621 & g_541)) <= g_63))), (safe_rshift_func_int8_t_s_u(((((safe_unary_minus_func_int8_t_s(((l_3561 ^ (l_3638[4][0][5] = (!(g_4 = (251UL | 1UL))))) & g_22))) | 0x6828710FL) || g_359[4][4]) > l_2296), g_83)))) < g_538), l_3588))) & 0xA5L) != l_2899)), l_3639)))), 0L)))
                {
                    int16_t l_3668 = 4L;
                    if ((0x58A82B72L | (safe_sub_func_int16_t_s_s(g_2177[3][1][9], (1L < g_2177[4][3][0])))))
                    {
                        uint32_t l_3663 = 0xB87B213BL;
                        int32_t l_3665 = 0x38F15173L;
                        l_3668 = (l_3667 = (0x9C031653L > ((((safe_sub_func_uint32_t_u_u((~(g_3261 ^ ((((safe_mod_func_uint8_t_u_u((g_2177[3][1][9] > (safe_sub_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u(l_3621, (g_2476 && (l_3655 == (g_866[0][1] = (l_3656 = 0L)))))) || (safe_lshift_func_int16_t_s_s((safe_add_func_int16_t_s_s(g_2598, (((l_3663 = (4294967295UL ^ 0xC8C7ECD9L)) == 0x67EB8C8CL) <= 0L))), 14))) >= l_3664), 11)) == g_83), 3)) == l_3665), l_3622[1][1]))), 0x4AL)) == g_2352[2]) && 0x4BL) & g_359[4][4]))), l_3622[3][4])) == (-1L)) && g_247) < l_3666)));
                        g_22 = 1L;
                    }
                    else
                    {
                        int32_t l_3686 = 0x5209DBEDL;
                        int32_t l_3687 = 0L;
                        g_22 = ((safe_rshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((((-10L) < (safe_lshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((((safe_rshift_func_uint16_t_u_u((g_315 = (((l_3681 != (0xD32132F5L <= (g_172[1] < (!g_540)))) || 0UL) <= l_3683)), (0xA83222B9L || ((safe_sub_func_int16_t_s_s((l_3622[8][3] <= g_543[1]), l_3686)) & (-5L))))) < g_1524) & g_1524), g_3258)) <= (-1L)), 6))) >= l_3687), g_2476)), 8UL)), 2)) | g_172[0]);
                    }
                    for (g_3421 = 0; (g_3421 == 4); g_3421 = safe_add_func_uint32_t_u_u(g_3421, 4))
                    {
                        return l_3656;
                    }
                    for (g_3261 = 0; (g_3261 <= 4); g_3261 += 1)
                    {
                        int i;
                        g_2476 = (safe_add_func_uint8_t_u_u(l_2266[g_3261], (safe_lshift_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((8L == (l_3656 = ((l_2266[g_3261] && g_172[4]) < g_2177[5][2][8]))), (g_63 = (g_315 = (g_2598 || 0x4FL))))), 4))));

g_2598 += 1;


                    if (g_540)
                            break;
                    }
                    l_3702 = (6UL && (g_4 & (l_3639 = ((((safe_sub_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_s((((l_3562[1] && 9L) > (0xE5F008A1L <= ((g_3258 = (-10L)) <= (safe_mod_func_int8_t_s_s(g_359[6][3], (g_1129 = l_2790[0][0])))))) >= g_1215[4]), l_2899)) ^ 0xD6L), 0x64C4L)) & l_3668) == l_3656) & l_3668))));
                }
                else
                {
                    for (l_2692 = 0; (l_2692 != 42); l_2692++)
                    {
                        l_2266[2] = g_538;
                    }
                    return g_3261;
                }
            }
            else
            {
                return g_188;
            }
        }
        l_3707 = ((safe_lshift_func_int8_t_s_u(((l_3562[0] >= g_866[4][0]) != (g_1129 = (g_1524 > g_2598))), l_3707)) > 0x3DD2L);

l_3775 += 1;


                    g_2576 = ((((safe_sub_func_uint16_t_u_u((((safe_rshift_func_uint16_t_u_u(l_3562[0], (safe_mod_func_uint8_t_u_u((safe_add_func_uint32_t_u_u(((g_247 = (safe_rshift_func_int16_t_s_u((-2L), ((g_172[1] = 65528UL) < l_3562[1])))) > (safe_lshift_func_int16_t_s_u(((((~g_2177[1][2][6]) | ((l_3721 || l_2294) >= (0x0FL ^ g_2576))) | l_3639) >= g_866[4][0]), g_2352[2]))), l_2526)), l_3702)))) < g_12) & g_538), l_3562[1])) != 1UL) && l_2418[5][4]) ^ g_115);
    }
    else
    {
        int32_t l_3732 = 5L;
        int32_t l_3772[9][5][4] = {{{(-5L),0x53797119L,(-1L),0xEC1AA655L},{(-3L),0x0BED20CAL,0x620E126EL,0x64D60197L},{0x620E126EL,0x64D60197L,(-1L),(-1L)},{0x9C8EED80L,0x08C26BBCL,(-1L),(-7L)},{(-1L),(-1L),0x5187487DL,(-1L)}},{{(-1L),0x5187487DL,0x5187487DL,0x08C26BBCL},{0L,0x3A0636EDL,0x227DF413L,0L},{(-1L),(-1L),0x53797119L,0x5A84B327L},{(-1L),0x08C26BBCL,0x3C72134DL,0x5A84B327L},{0L,(-1L),0x5B09E585L,0L}},{{0x64D60197L,0x3A0636EDL,0xEC1AA655L,0x08C26BBCL},{0x6CA574B2L,0x5187487DL,(-1L),0xC7C31EEAL},{0x620E126EL,(-1L),(-1L),(-5L)},{(-1L),0xEC1AA655L,0x9C8EED80L,0x0BED20CAL},{0x3A0636EDL,(-1L),0x620E126EL,(-1L)}},{{1L,(-1L),(-3L),0L},{0x5A84B327L,0L,(-5L),0x9C8EED80L},{0x9C8EED80L,4L,0L,8L},{0x9C8EED80L,(-7L),(-5L),0x2F85340DL},{0x5A84B327L,8L,(-3L),0L}},{{1L,0L,0x620E126EL,0x53797119L},{0x3A0636EDL,0xB8D39A8AL,0x9C8EED80L,(-1L)},{(-1L),0x64D60197L,(-1L),0x3FDD2651L},{0x620E126EL,0x5B09E585L,(-1L),(-1L)},{0x6CA574B2L,0x6CA574B2L,0xEC1AA655L,4L}},{{0x64D60197L,0x2F85340DL,0x5B09E585L,0x3A0636EDL},{0L,(-1L),0x3C72134DL,0x5B09E585L},{(-1L),(-1L),0x53797119L,0x3A0636EDL},{(-1L),0x2F85340DL,0x227DF413L,4L},{0L,0x6CA574B2L,0x5187487DL,(-1L)}},{{0x08C26BBCL,0x5B09E585L,0x6CA574B2L,0x3FDD2651L},{(-7L),0x64D60197L,0x0BED20CAL,(-1L)},{(-3L),0xB8D39A8AL,(-1L),0x53797119L},{8L,0L,8L,0L},{(-1L),8L,0xC7C31EEAL,0x2F85340DL}},{{0x53797119L,(-7L),0x3A0636EDL,8L},{(-1L),4L,0x3A0636EDL,0x9C8EED80L},{0x53797119L,0L,0xC7C31EEAL,0L},{(-1L),(-1L),8L,(-1L)},{8L,(-1L),(-1L),0x0BED20CAL}},{{(-3L),0xEC1AA655L,0x0BED20CAL,(-5L)},{(-7L),(-1L),0x6CA574B2L,0xC7C31EEAL},{0x08C26BBCL,0x5187487DL,0x5187487DL,0x08C26BBCL},{0L,0x3A0636EDL,0x227DF413L,0L},{(-1L),(-1L),0x53797119L,0x5A84B327L}}};
        int32_t l_3780 = 1L;
        uint32_t l_3807[8] = {0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL};
        int16_t l_3822 = 0xB624L;
        uint32_t l_3909[7][2] = {{4294967295UL,0xDBB9B69CL},{0xDA67836AL,0xDBB9B69CL},{4294967295UL,0xA3043AE8L},{0xA3043AE8L,4294967295UL},{0xDBB9B69CL,0xDA67836AL},{0xDBB9B69CL,4294967295UL},{0xA3043AE8L,0xA3043AE8L}};
        uint32_t l_3937 = 9UL;
        int32_t l_3987 = 0x7570AEB1L;
        int i, j, k;
        l_3732 = (safe_add_func_int32_t_s_s(l_2408[3][0], (safe_rshift_func_uint8_t_u_u(((((safe_rshift_func_uint8_t_u_s(((((-10L) != (safe_mod_func_uint32_t_u_u(((-9L) > ((1L < (safe_lshift_func_int16_t_s_u(l_3732, (safe_rshift_func_uint16_t_u_u(l_2408[2][1], 2))))) != (safe_rshift_func_int16_t_s_u(((safe_rshift_func_uint16_t_u_s(g_1215[5], 5)) | (l_3732 || ((safe_add_func_int16_t_s_s(g_22, 0x51BCL)) <= 0x9FL))), l_3471)))), 0x6935AA16L))) || g_2352[2]) != l_3741), 5)) && l_3732) && l_3732) > l_3017), l_3732))));

for (g_217 = 0; (g_217 == 4); g_217 = safe_add_func_uint32_t_u_u(g_217, 4))
                    {
                        return l_3780;
                    }
for (l_3399 = 0; (l_3399 != 42); l_3399++)
                    {
                        g_3956[2] = l_3775;
                    };


                    ;


                    if ((((g_2352[2] < (((safe_rshift_func_int16_t_s_s((((((safe_sub_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(0x91L)), (g_2710 = 255UL))) && (g_949[0][6][1] & (safe_add_func_int32_t_s_s(((safe_unary_minus_func_int16_t_s((-1L))) && (safe_rshift_func_int16_t_s_s(((((g_2476 = l_2408[3][0]) > ((l_3755[0][0][5] = ((g_217 = (g_1129 = 255UL)) ^ ((l_3752 != (((+((safe_unary_minus_func_uint16_t_u(((l_2674 && g_115) < 9UL))) <= g_2420)) > l_3732) & g_103)) == l_2266[3]))) || l_3732)) == l_3732) || 7L), g_2420))), l_3707)))) == 0x1476L) & l_3752) & 4294967295UL), l_3732)) || 1UL) && 0x51L)) & g_2352[8]) | g_173))
        {
            int32_t l_3782 = (-1L);
            int32_t l_3783 = (-1L);
            uint32_t l_3784[6] = {1UL,0x277AD475L,1UL,1UL,0x277AD475L,1UL};
            int i;

{
                    int32_t l_3828 = 0x3079516EL;
                    int i;
                    l_3828 = (g_1524 = (l_3874[(g_217 + 4)] ^ (safe_mod_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((safe_add_func_int16_t_s_s((!g_1215[(g_217 + 4)]), ((g_4 = 3L) >= (((l_2601 = 1L) >= ((safe_sub_func_int8_t_s_s(0L, (safe_lshift_func_int8_t_s_u(0x39L, 4)))) != l_3573[1])) ^ ((0x2E9DL != l_3807[0]) || g_1129))))), g_543[1])), 0x755FL)) <= g_172[4]), g_2177[1][3][3]))));

if (g_2476) printf("index = [%d][%d]\n", g_2576, k);

                    for (l_2601 = 0; (l_2601 <= 1); l_2601 += 1)
                    {
                        int i, j, k;

{
            for (g_2476 = 0; g_2476 < 9; g_2476++)
            {
                transparent_crc(g_949[g_2476][g_115][g_2476], "g_949[g_2476][g_115][g_2476]", l_3828);
                if (l_3828) printf("index = [%d][%d][%d]\n", g_2476, g_115, g_2476);

            }
        }

                    g_3484 = ((safe_rshift_func_int16_t_s_s(((((-1L) == ((((safe_sub_func_int32_t_s_s(0x814AF06EL, ((safe_mod_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(((l_3755[g_217][g_217][(g_217 + 4)] != l_3492) <= (safe_unary_minus_func_uint16_t_u(l_2841))), g_4)), g_3484)) < (g_315 = (((safe_mod_func_uint32_t_u_u(((g_2476 & (safe_lshift_func_uint8_t_u_s((safe_add_func_uint32_t_u_u(0xFCA458E4L, 0xFAFCB658L)), l_3828))) && 4294967290UL), g_172[3])) | (-1L)) == l_3874[(g_217 + 4)]))))) | 0x96617425L) && l_3262) & g_359[9][0])) & 0UL) <= 1UL), 5)) || 0x45L);
                        return g_247;
                    }
                }

                    g_22 = (((l_3732 = (g_2177[0][1][6] > 65535UL)) ^ (safe_mod_func_uint8_t_u_u(((g_361 = (safe_rshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_u((g_315 = (safe_lshift_func_uint8_t_u_u(255UL, (0UL > (l_3784[4] = (safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(g_2476, 3)), (((l_3783 = (safe_lshift_func_uint8_t_u_s((l_3772[0][4][0] <= ((l_3262 = ((((safe_lshift_func_int8_t_s_u((g_2420 = l_3775), 2)) != ((((safe_lshift_func_int16_t_s_u((g_543[1] = (((((((65534UL || (g_3781 = (safe_add_func_int16_t_s_s((l_3752 ^ l_3780), g_83)))) || (-1L)) ^ g_173) == l_3782) || l_3782) ^ l_3755[0][1][1]) == g_543[1])), 2)) ^ g_3261) == l_3782) <= g_2177[4][1][2])) && g_63) <= 0xCEL)) != 0UL)), 4))) || g_115) && g_813[0][0])))))))), l_2418[3][4])), 1)), g_12))) | l_2266[4]), 0xE6L))) ^ g_2352[6]);
            g_247 = 0x9DF8728DL;
        }
        else
        {
            uint32_t l_3796 = 18446744073709551615UL;
            int32_t l_3808 = (-1L);
            int32_t l_3812 = 0x5C3FB331L;
            for (g_3409 = 0; (g_3409 <= (-26)); g_3409 = safe_sub_func_uint32_t_u_u(g_3409, 4))
            {
                int32_t l_3789 = 0L;
                int32_t l_3793 = 0L;
                for (g_2420 = 0; (g_2420 != 4); g_2420 = safe_add_func_int32_t_s_s(g_2420, 2))
                {
                    int32_t l_3792[2][4];
                    int i, j;
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 4; j++)
                            l_3792[i][j] = 1L;
                    }
                    if ((((l_3789 <= (safe_sub_func_int16_t_s_s((0x931ABD91L > (l_3793 = l_3792[1][0])), (l_3796 | (l_2674 == (g_161 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(l_2465, 1)), 5)), g_2576)))))))) > (~(((g_172[5] ^ (safe_mod_func_uint8_t_u_u((~l_3775), l_3807[1]))) > l_3808) && g_2598))) <= 0x50BC1107L))
                    {
                        g_2476 = (g_247 = (0x9D645515L | (l_3792[1][3] && (l_3792[1][2] = ((+g_3781) <= g_12)))));
                    }
                    else
                    {
                        l_3812 = (g_2576 = (0L & ((g_3261 | ((((g_12 || ((g_2177[1][1][3] = (l_3808 == (g_188 = (65535UL != (((g_538 = l_3796) < ((((safe_unary_minus_func_uint8_t_u(((g_1129 ^ ((+l_3573[1]) != g_103)) > g_1460))) <= 8L) & g_2576) && 0x17F2086DL)) >= g_359[9][0]))))) != l_3792[0][1])) >= g_541) >= 0xB60DL) == 0x653A7DA3L)) != l_3262)));
                    }
                }
            }
            for (l_3151 = 0; (l_3151 <= 1); l_3151 += 1)
            {
                int16_t l_3827 = 0xA98EL;
                int32_t l_3837 = 0xC79C192DL;
                uint8_t l_3870 = 251UL;
                int32_t l_3892 = 0x9B48DECCL;
                uint32_t l_3910 = 1UL;
                int8_t l_3927 = 0x16L;
                for (l_3534 = 0; (l_3534 <= 5); l_3534 += 1)
                {
                    int32_t l_3828 = 0x3079516EL;
                    int i;
                    l_3828 = (l_3827 = (g_2352[(l_3151 + 4)] ^ (safe_mod_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((safe_add_func_int16_t_s_s((!g_1215[(l_3151 + 4)]), ((g_3409 = 3L) >= (((l_3822 = 1L) >= ((safe_sub_func_int8_t_s_s(0L, (safe_lshift_func_int8_t_s_u(0x39L, 4)))) != l_3573[1])) ^ ((0x2E9DL != l_3807[0]) || g_12))))), g_543[1])), 0x755FL)) <= g_172[4]), g_2177[1][3][3]))));

if (g_83)
                        break;

                    for (g_188 = 0; (g_188 <= 1); g_188 += 1)
                    {
                        int i, j, k;

l_3775 += 1;


                    l_3732 = ((safe_rshift_func_int16_t_s_s(((((-1L) == ((((safe_sub_func_int32_t_s_s(0x814AF06EL, ((safe_mod_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(((l_3755[l_3151][l_3151][(l_3151 + 4)] != l_3837) <= (safe_unary_minus_func_uint16_t_u(l_3399))), g_3409)), l_3732)) < (g_538 = (((safe_mod_func_uint32_t_u_u(((g_541 & (safe_lshift_func_uint8_t_u_s((safe_add_func_uint32_t_u_u(0xFCA458E4L, 0xFAFCB658L)), l_3828))) && 4294967290UL), g_172[3])) | (-1L)) == g_2352[(l_3151 + 4)]))))) | 0x96617425L) && g_3152) & g_359[9][0])) & 0UL) <= 1UL), 5)) || 0x45L);
                        return g_2476;
                    }
                }
                for (g_2598 = 10; (g_2598 != 50); ++g_2598)
                {
                    uint32_t l_3851 = 18446744073709551615UL;
                    int8_t l_3871 = 3L;
                    uint32_t l_3897[8][4][7] = {{{18446744073709551612UL,0xE1836138L,0x850D52E1L,4UL,18446744073709551612UL,18446744073709551615UL,18446744073709551615UL},{0x66203650L,18446744073709551612UL,6UL,18446744073709551612UL,0x66203650L,0x325F3AE1L,4UL},{18446744073709551606UL,0x19A3FC88L,18446744073709551615UL,0x43272F40L,0x3D0A099DL,1UL,0x66203650L},{18446744073709551614UL,18446744073709551606UL,0UL,18446744073709551614UL,18446744073709551612UL,0UL,0UL}},{{18446744073709551606UL,0x43272F40L,6UL,1UL,18446744073709551606UL,18446744073709551615UL,1UL},{0x66203650L,1UL,0x3D0A099DL,0x43272F40L,18446744073709551615UL,0x19A3FC88L,18446744073709551606UL},{1UL,0x850D52E1L,0x3D0A099DL,18446744073709551615UL,0x2C9ACB3CL,18446744073709551615UL,0x3D0A099DL},{18446744073709551612UL,18446744073709551612UL,6UL,0xA92A9589L,0xFD09A0FAL,18446744073709551606UL,4UL}},{{0xA92A9589L,18446744073709551615UL,0UL,0UL,0x19A3FC88L,0UL,18446744073709551612UL},{0UL,0x850D52E1L,18446744073709551615UL,0x3D0A099DL,0xFD09A0FAL,0UL,0xB93E9277L},{18446744073709551606UL,4UL,6UL,18446744073709551612UL,0x2C9ACB3CL,0x333F6AB0L,18446744073709551606UL},{0xA92A9589L,0UL,0x1077E5E4L,0x66203650L,18446744073709551615UL,18446744073709551606UL,18446744073709551606UL}},{{18446744073709551615UL,18446744073709551606UL,0x19A3FC88L,0x19A3FC88L,18446744073709551606UL,18446744073709551615UL,0xB93E9277L},{4UL,0UL,0x7FF5CEFEL,0xA92A9589L,18446744073709551612UL,0x4DEDE24EL,18446744073709551612UL},{0x66203650L,18446744073709551615UL,0x37F1B27FL,18446744073709551612UL,0x3D0A099DL,18446744073709551606UL,4UL},{0UL,0UL,18446744073709551615UL,0UL,0x66203650L,1UL,0x3D0A099DL}},{{1UL,18446744073709551606UL,18446744073709551615UL,1UL,18446744073709551612UL,0x87551765L,18446744073709551606UL},{18446744073709551606UL,0UL,18446744073709551615UL,1UL,0UL,0UL,1UL},{0x3D0A099DL,4UL,0x3D0A099DL,0UL,18446744073709551612UL,0x19A3FC88L,0UL},{4UL,0x850D52E1L,0xE1836138L,18446744073709551612UL,0x2C9ACB3CL,6UL,0x66203650L}},{{18446744073709551612UL,18446744073709551615UL,18446744073709551615UL,0xA92A9589L,0x1077E5E4L,0x19A3FC88L,4UL},{0xB93E9277L,18446744073709551612UL,0UL,0x19A3FC88L,0UL,0UL,18446744073709551615UL},{18446744073709551606UL,0x850D52E1L,0x4DEDE24EL,0x66203650L,0xFD09A0FAL,0x87551765L,0xA92A9589L},{18446744073709551606UL,1UL,0x37F1B27FL,18446744073709551612UL,0x37F1B27FL,1UL,18446744073709551606UL}},{{0xB93E9277L,0x43272F40L,0x1077E5E4L,0x3D0A099DL,18446744073709551612UL,18446744073709551606UL,0UL},{18446744073709551612UL,18446744073709551606UL,18446744073709551606UL,0UL,18446744073709551606UL,0x4DEDE24EL,0xA92A9589L},{4UL,0x19A3FC88L,0x1077E5E4L,0xA92A9589L,18446744073709551615UL,18446744073709551615UL,18446744073709551612UL},{0x3D0A099DL,18446744073709551612UL,0x37F1B27FL,18446744073709551615UL,0x66203650L,18446744073709551606UL,0UL}},{{0x3D0A099DL,0UL,18446744073709551612UL,18446744073709551606UL,0x19A3FC88L,0xA92A9589L,0x19A3FC88L},{18446744073709551615UL,0x32647471L,0x32647471L,18446744073709551615UL,0x333F6AB0L,0x325F3AE1L,0x3D0A099DL},{0xE1836138L,18446744073709551606UL,0x333F6AB0L,0x4DEDE24EL,18446744073709551614UL,0x32647471L,0x4DEDE24EL},{0x19A3FC88L,0xB93E9277L,0UL,18446744073709551606UL,18446744073709551615UL,18446744073709551606UL,0x3D0A099DL}}};
                    int32_t l_3916 = (-1L);
                    int i, j, k;

{
            for (l_3812 = 0; l_3812 < 9; l_3812++)
            {
                transparent_crc(g_949[g_247][l_3707][l_3812], "g_949[g_247][l_3707][l_3812]", l_3707);
                if (l_3707) printf("index = [%d][%d][%d]\n", g_247, l_3707, l_3812);

            }
        }

                    if ((((((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((l_3851 != (((g_4 = (l_3812 = (g_3781 = (-7L)))) & ((0x1404L == 0xBA1BL) <= ((-8L) ^ (((l_3872 = (safe_rshift_func_int16_t_s_u((g_2476 && (safe_mod_func_uint16_t_u_u((((((safe_sub_func_int32_t_s_s((safe_add_func_int32_t_s_s(((safe_mod_func_int16_t_s_s((g_1524 = (((((l_3851 ^ (safe_mod_func_int32_t_s_s((safe_add_func_uint32_t_u_u(g_543[1], (safe_mod_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((0x6EL >= g_172[4]), l_3870)), g_866[4][9])))), g_974))) < 0xBD537FA9L) > 0UL) | l_3851) < 65532UL)), 8L)) | g_247), l_2408[1][0])), g_2576)) > g_217) > l_3822) | l_3424[1][1][4]) && l_3871), 1L))), l_3808))) == (-5L)) | l_3873)))) & l_3808)), 2)), 0x0BL)) == l_3874[8]) <= g_2352[0]) <= g_2420) >= l_3807[6]))
                    {

for (l_3257 = 10; (l_3257 != 50); ++l_3257)
                {
                    uint32_t l_3851 = 18446744073709551615UL;
                    int8_t l_3871 = 3L;
                    uint32_t l_3897[8][4][7] = {{{18446744073709551612UL,0xE1836138L,0x850D52E1L,4UL,18446744073709551612UL,18446744073709551615UL,18446744073709551615UL},{0x66203650L,18446744073709551612UL,6UL,18446744073709551612UL,0x66203650L,0x325F3AE1L,4UL},{18446744073709551606UL,0x19A3FC88L,18446744073709551615UL,0x43272F40L,0x3D0A099DL,1UL,0x66203650L},{18446744073709551614UL,18446744073709551606UL,0UL,18446744073709551614UL,18446744073709551612UL,0UL,0UL}},{{18446744073709551606UL,0x43272F40L,6UL,1UL,18446744073709551606UL,18446744073709551615UL,1UL},{0x66203650L,1UL,0x3D0A099DL,0x43272F40L,18446744073709551615UL,0x19A3FC88L,18446744073709551606UL},{1UL,0x850D52E1L,0x3D0A099DL,18446744073709551615UL,0x2C9ACB3CL,18446744073709551615UL,0x3D0A099DL},{18446744073709551612UL,18446744073709551612UL,6UL,0xA92A9589L,0xFD09A0FAL,18446744073709551606UL,4UL}},{{0xA92A9589L,18446744073709551615UL,0UL,0UL,0x19A3FC88L,0UL,18446744073709551612UL},{0UL,0x850D52E1L,18446744073709551615UL,0x3D0A099DL,0xFD09A0FAL,0UL,0xB93E9277L},{18446744073709551606UL,4UL,6UL,18446744073709551612UL,0x2C9ACB3CL,0x333F6AB0L,18446744073709551606UL},{0xA92A9589L,0UL,0x1077E5E4L,0x66203650L,18446744073709551615UL,18446744073709551606UL,18446744073709551606UL}},{{18446744073709551615UL,18446744073709551606UL,0x19A3FC88L,0x19A3FC88L,18446744073709551606UL,18446744073709551615UL,0xB93E9277L},{4UL,0UL,0x7FF5CEFEL,0xA92A9589L,18446744073709551612UL,0x4DEDE24EL,18446744073709551612UL},{0x66203650L,18446744073709551615UL,0x37F1B27FL,18446744073709551612UL,0x3D0A099DL,18446744073709551606UL,4UL},{0UL,0UL,18446744073709551615UL,0UL,0x66203650L,1UL,0x3D0A099DL}},{{1UL,18446744073709551606UL,18446744073709551615UL,1UL,18446744073709551612UL,0x87551765L,18446744073709551606UL},{18446744073709551606UL,0UL,18446744073709551615UL,1UL,0UL,0UL,1UL},{0x3D0A099DL,4UL,0x3D0A099DL,0UL,18446744073709551612UL,0x19A3FC88L,0UL},{4UL,0x850D52E1L,0xE1836138L,18446744073709551612UL,0x2C9ACB3CL,6UL,0x66203650L}},{{18446744073709551612UL,18446744073709551615UL,18446744073709551615UL,0xA92A9589L,0x1077E5E4L,0x19A3FC88L,4UL},{0xB93E9277L,18446744073709551612UL,0UL,0x19A3FC88L,0UL,0UL,18446744073709551615UL},{18446744073709551606UL,0x850D52E1L,0x4DEDE24EL,0x66203650L,0xFD09A0FAL,0x87551765L,0xA92A9589L},{18446744073709551606UL,1UL,0x37F1B27FL,18446744073709551612UL,0x37F1B27FL,1UL,18446744073709551606UL}},{{0xB93E9277L,0x43272F40L,0x1077E5E4L,0x3D0A099DL,18446744073709551612UL,18446744073709551606UL,0UL},{18446744073709551612UL,18446744073709551606UL,18446744073709551606UL,0UL,18446744073709551606UL,0x4DEDE24EL,0xA92A9589L},{4UL,0x19A3FC88L,0x1077E5E4L,0xA92A9589L,18446744073709551615UL,18446744073709551615UL,18446744073709551612UL},{0x3D0A099DL,18446744073709551612UL,0x37F1B27FL,18446744073709551615UL,0x66203650L,18446744073709551606UL,0UL}},{{0x3D0A099DL,0UL,18446744073709551612UL,18446744073709551606UL,0x19A3FC88L,0xA92A9589L,0x19A3FC88L},{18446744073709551615UL,0x32647471L,0x32647471L,18446744073709551615UL,0x333F6AB0L,0x325F3AE1L,0x3D0A099DL},{0xE1836138L,18446744073709551606UL,0x333F6AB0L,0x4DEDE24EL,18446744073709551614UL,0x32647471L,0x4DEDE24EL},{0x19A3FC88L,0xB93E9277L,0UL,18446744073709551606UL,18446744073709551615UL,18446744073709551606UL,0x3D0A099DL}}};
                    int32_t l_3916 = (-1L);
                    int i, j, k;
                    if ((((((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((l_3851 != (((l_2526 = (l_3732 = (l_4035 = (-7L)))) & ((0x1404L == 0xBA1BL) <= ((-8L) ^ (((l_2290 = (safe_rshift_func_int16_t_s_u((l_3017 && (safe_mod_func_uint16_t_u_u((((((safe_sub_func_int32_t_s_s((safe_add_func_int32_t_s_s(((safe_mod_func_int16_t_s_s((g_188 = (((((l_3851 ^ (safe_mod_func_int32_t_s_s((safe_add_func_uint32_t_u_u(g_543[1], (safe_mod_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((0x6EL >= g_172[4]), g_173)), g_866[4][9])))), g_1524))) < 0xBD537FA9L) > 0UL) | l_3851) < 65532UL)), 8L)) | l_3892), l_2408[1][0])), g_3484)) > l_3655) > l_3827) | l_3424[1][1][4]) && l_3871), 1L))), l_2294))) == (-5L)) | l_3873)))) & l_2294)), 2)), 0x0BL)) == l_3874[8]) <= l_3874[0]) <= g_361) >= l_3807[6]))
                    {
                        l_3892 = (safe_sub_func_uint32_t_u_u(((l_3399 != (g_188 = (((safe_mod_func_uint8_t_u_u((l_3655 & (l_3891 = (safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_s(65534UL, 15)) == (g_813[5][0] = ((safe_add_func_uint8_t_u_u(((((g_359[9][0] && (safe_lshift_func_uint8_t_u_s(l_3732, 2))) <= l_3851) <= l_3874[2]) != 1UL), ((safe_add_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u((g_361 = l_3399), g_1524)) == l_3755[0][0][5]), l_3655)) & l_3017))) || 0xD0F0L))), l_3871)))), 1L)) & l_2266[3]) < l_3874[4]))) & l_3871), l_2294));
                    }
                    else
                    {
                        return g_1215[3];
                    }
                    for (l_3017 = 0; (l_3017 <= 27); l_3017++)
                    {
                        uint32_t l_3907 = 4294967295UL;

{
        uint32_t l_2279 = 0x93AE2901L;
        int32_t l_2291[2];
        int32_t l_2293[10][5][5] = {{{0x45777B37L,4L,(-5L),(-10L),(-5L)},{0xA9C5A221L,0xA9C5A221L,0x9C7A75D8L,0xD4EDE40DL,0x8ED2113AL},{0xFE015731L,2L,6L,0xA4130E32L,(-3L)},{0x4F8FF695L,9L,0xD4EDE40DL,0x6B855A03L,(-2L)},{0L,2L,0x45777B37L,0xEF9A929BL,1L}},{{(-1L),0xA9C5A221L,0x3F2DF9F6L,0x9C7A75D8L,0x4F8FF695L},{0x05E1541BL,4L,0xFE015731L,1L,(-4L)},{0x2F4D056CL,0x2206AE63L,0xD4EDE40DL,0xE58FA5B4L,0x2F4D056CL},{0x4E1AA23AL,0xEF9A929BL,0L,1L,(-7L)},{(-1L),(-8L),0x9C7A75D8L,0x9C7A75D8L,(-8L)}},{{(-3L),(-4L),0x05E1541BL,0xEF9A929BL,0xD31BC39FL},{0xE58FA5B4L,0x9C7A75D8L,0xEBCBB2E6L,0x6B855A03L,0x2F4D056CL},{(-7L),1L,0x4E1AA23AL,0xA4130E32L,0x141ABB78L},{0xE58FA5B4L,0x8ED2113AL,0xF2DC1619L,0xD4EDE40DL,0x4F8FF695L},{(-3L),(-9L),(-3L),(-10L),(-5L)}},{{(-1L),(-7L),0x2206AE63L,(-8L),(-2L)},{0x4E1AA23AL,1L,(-7L),4L,(-7L)},{0x2F4D056CL,(-1L),0x2206AE63L,(-1L),0x8ED2113AL},{0x05E1541BL,(-4L),(-3L),(-4L),0x05E1541BL},{(-1L),(-9L),0xF2DC1619L,(-2L),0xA9C5A221L}},{{0L,0xEF9A929BL,0x4E1AA23AL,4L,5L},{0x4F8FF695L,0xE58FA5B4L,0xEBCBB2E6L,(-9L),0xA9C5A221L},{0xFE015731L,4L,0x05E1541BL,(-10L),0x05E1541BL},{0xA9C5A221L,0x3F2DF9F6L,0x9C7A75D8L,0x4F8FF695L,0x8ED2113AL},{0x45777B37L,2L,0L,0xA4130E32L,(-7L)}},{{0x4F8FF695L,(-1L),0xD4EDE40DL,0xC4371B6FL,(-2L)},{6L,6L,0x80113FBEL,4L,(-4L)},{0xA9C5A221L,0xC4371B6FL,0xC4371B6FL,0xA9C5A221L,(-8L)},{0L,1L,4L,2L,(-5L)},{(-1L),(-1L),(-9L),9L,(-1L)}},{{0xD31BC39FL,4L,(-3L),2L,1L},{0x4F8FF695L,0x9C7A75D8L,0x3F2DF9F6L,0xA9C5A221L,(-1L)},{5L,(-9L),0L,4L,0x9616CC94L},{(-1L),0xA9C5A221L,0xF2DC1619L,0x2206AE63L,(-1L)},{1L,(-10L),0xD31BC39FL,0xEF9A929BL,0x05E1541BL}},{{(-1L),0xEBCBB2E6L,0xD4EDE40DL,(-8L),(-8L)},{5L,1L,5L,(-4L),0x141ABB78L},{0x4F8FF695L,0x2F4D056CL,9L,0x9C7A75D8L,0x8ED2113AL},{0xD31BC39FL,(-10L),1L,1L,(-1L)},{(-1L),0x3F2DF9F6L,9L,0x8ED2113AL,0x2F4D056CL}},{{0L,(-9L),5L,(-9L),0L},{0xA9C5A221L,(-1L),0xD4EDE40DL,(-7L),0x6B855A03L},{(-3L),4L,0xD31BC39FL,1L,0xC0723F86L},{(-8L),9L,0xF2DC1619L,(-1L),0x6B855A03L},{4L,1L,0L,(-4L),0L}},{{0x6B855A03L,0x6B855A03L,0x3F2DF9F6L,(-9L),0x2F4D056CL},{0x80113FBEL,6L,(-3L),0xEF9A929BL,(-1L)},{(-8L),(-1L),(-9L),0xE58FA5B4L,0x8ED2113AL},{(-7L),6L,4L,4L,0x141ABB78L},{0xA9C5A221L,0x6B855A03L,0xC4371B6FL,0x3F2DF9F6L,(-8L)}}};
        int32_t l_2295 = 0xA7522FCFL;
        uint16_t l_2386[5] = {0xA842L,0xA842L,0xA842L,0xA842L,0xA842L};
        uint8_t l_2387 = 0xC5L;
        uint8_t l_2566[3][1];
        int16_t l_2600 = 0x9347L;
        uint16_t l_2619[2];
        int i, j, k;
        for (i = 0; i < 2; i++)
            l_2291[i] = 0x4E538020L;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 1; j++)
                l_2566[i][j] = 1UL;
        }
        for (i = 0; i < 2; i++)
            l_2619[i] = 65535UL;
        i = (l_2266[2] = (l_2295 = (((safe_sub_func_uint32_t_u_u((!(safe_sub_func_int16_t_s_s((g_543[1] = (safe_add_func_int32_t_s_s((safe_rshift_func_uint8_t_u_u(0x89L, 6)), ((safe_mod_func_int16_t_s_s((g_172[8] >= 0x22C8L), (g_3261 = l_5[5][1]))) || (l_2279 | (((safe_mod_func_uint32_t_u_u((~(l_2293[5][4][4] = (safe_sub_func_int32_t_s_s(((g_3261 = (safe_lshift_func_uint16_t_u_s(((~l_2266[4]) < (((l_2291[0] = (0x405BL < (((k = (safe_add_func_uint16_t_u_u((l_3702 = (l_5[1][6] == 0x41L)), l_3796))) | l_2266[3]) >= g_2177[1][3][4]))) ^ 0x136C721FL) | l_3796)), 2))) > g_3421), g_12)))), l_2266[1])) ^ 0xBD41L) | 0xAFB6L)))))), l_2294))), l_5[4][0])) >= 1L) <= l_2279)));
        for (l_3667 = 2; (l_3667 >= 0); l_3667 -= 1)
        {
            uint32_t l_2314 = 0xBB7DC9F1L;
            int32_t l_2326 = 0x3AB3E32BL;
            int8_t l_2328[1];
            int i;
            for (i = 0; i < 1; i++)
                l_2328[i] = 0L;
            for (g_188 = 0; (g_188 <= 2); g_188 += 1)
            {
                int16_t l_2315 = 0xC65AL;
                uint16_t l_2327 = 65533UL;
                uint8_t l_2343[5] = {3UL,3UL,3UL,3UL,3UL};
                int i;
                for (l_2295 = 0; (l_2295 <= 2); l_2295 += 1)
                {
                    int i, j, k;
                    l_3891 = (((safe_lshift_func_uint16_t_u_s((l_3702 = (~(g_3421 = (safe_add_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u(((safe_add_func_uint32_t_u_u(((((safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((safe_add_func_uint16_t_u_u(((((((safe_sub_func_int16_t_s_s((g_949[l_2295][(l_2295 + 3)][(l_3667 + 5)] & g_949[l_2295][(l_3667 + 4)][(l_3667 + 2)]), l_2314)) == ((((g_172[4] = (g_949[l_2295][(l_2295 + 3)][(l_3667 + 5)] ^ (l_2315 == (safe_lshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(0L, 9)), 13))))) | ((safe_sub_func_uint32_t_u_u(((((safe_rshift_func_uint16_t_u_s(g_949[l_2295][(l_3667 + 4)][(l_3667 + 2)], ((safe_rshift_func_uint16_t_u_s((0x65F9L > 0x8304L), 8)) & 6L))) & 0UL) && 0L) != l_5[1][6]), l_3916)) <= 0UL)) & (-2L)) != g_949[l_2295][(l_3667 + 4)][(l_3667 + 2)])) & l_3399) & l_2291[0]) ^ 1UL) > 0x97A6L), l_3702)), l_2326)), g_949[l_2295][(l_3667 + 4)][(l_3667 + 2)])) == l_2327) || g_2177[2][1][9]) && g_3261), (-4L))) >= 0x5E9A852FL), l_2328[0])) == l_3667), l_2314))))), g_1215[4])) >= 4294967286UL) && 0x397E8B8CL);
                    for (g_12 = 20; (g_12 != 28); g_12++)
                    {
                        int16_t l_2333 = 0x031BL;
                        l_2291[1] = 1L;
                        if (l_2291[0])
                            break;
                        l_3891 = (safe_mod_func_uint32_t_u_u((5L || (l_2326 = (((l_2333 < ((((l_3408 = ((((-6L) == ((l_3927 = (safe_add_func_int32_t_s_s((0L <= (l_3927 && (safe_unary_minus_func_int8_t_s((((((((safe_add_func_uint16_t_u_u((1UL >= (safe_add_func_int8_t_s_s(0x1DL, (safe_add_func_uint32_t_u_u(((g_949[l_2295][(l_3667 + 4)][(l_3667 + 2)] > 0xC1A8C29BL) >= l_2295), l_2328[0]))))), 8UL)) == l_3891) < l_3796) == g_12) & l_2343[4]) && l_2315) <= g_3421))))), g_866[7][5]))) & 1UL)) | l_2327) & l_3702)) & l_3702) != l_2333) || l_2333)) & l_2294) && g_949[0][6][3]))), 6L));
                    }
                    l_3891 = g_188;
                }
                if (g_813[1][0])
                    continue;
                l_3891 = (safe_rshift_func_int16_t_s_u(((l_2315 & (safe_lshift_func_uint16_t_u_u((((l_2326 = (l_3822 ^ (l_3927 = (safe_add_func_uint8_t_u_u((((((0xE5L >= (((((g_103 = (safe_mod_func_int8_t_s_s((g_361 = (l_3874[2] || 4UL)), g_866[4][0]))) && 0xB2182F1EL) && (l_5[1][6] ^ (safe_lshift_func_uint8_t_u_s(((safe_add_func_uint16_t_u_u(((+g_3421) != g_3421), g_543[1])) && (-1L)), 7)))) < 0xB49FL) > 0x7963L)) >= l_2314) >= 2L) >= l_2291[1]) && (-1L)), g_12))))) | l_2327) < g_813[5][0]), g_3421))) < l_2314), 12));
            }
            return l_3408;
        }
        if (((((safe_lshift_func_int16_t_s_u(((((safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s((g_541 & (((safe_sub_func_uint8_t_u_u(((l_3796 < (((safe_add_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(0xB2C7L, (((safe_sub_func_uint8_t_u_u(((safe_unary_minus_func_uint16_t_u((l_2293[8][3][1] = 0x0192L))) || (l_3891 = (((-1L) < g_543[1]) || (l_2266[3] = (safe_add_func_int16_t_s_s((safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(l_2293[5][1][3], (+(((g_3261 = (safe_rshift_func_uint16_t_u_s(((g_2177[1][3][2] >= (safe_mod_func_int8_t_s_s(l_3874[4], g_3421))) != 5L), 0))) < i) != g_1215[2])))), 8L)), g_2177[3][1][9])))))), l_5[1][6])) || l_2295) == l_2291[0]))), l_2291[0])), g_359[9][0])) & l_2386[4]) < 1UL)) | l_2295), 0x6BL)) != 0UL) >= l_5[1][6])), g_949[0][6][1])), 0x5BL)) || g_866[4][0]) < g_866[6][2]) || l_2266[3]), l_2387)) > 0xCA700566L) >= g_813[1][0]) || g_3261))
        {
            uint8_t l_2432 = 0x5EL;
            int8_t l_2575 = 0L;
            int32_t l_2584 = 0x0CC4751DL;
            int32_t l_2585[3];
            int8_t l_2620 = 0x0FL;
            int i;
            for (i = 0; i < 3; i++)
                l_2585[i] = 0xAFFA580CL;
            for (l_2279 = 0; (l_2279 == 40); ++l_2279)
            {
                uint16_t l_2390 = 0x77A9L;
                uint32_t l_2419 = 1UL;
                int32_t l_2421 = 0x4F3857AAL;
                uint32_t l_2422 = 0x8A7A8A37L;
                int32_t l_2431 = (-10L);
                int8_t l_2475 = 0x84L;
                l_2390 = (l_3891 = l_3796);
                l_2422 = (((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u(((0x64L > ((~(safe_sub_func_uint32_t_u_u((safe_add_func_int32_t_s_s(g_12, ((safe_sub_func_int16_t_s_s((i = (safe_lshift_func_uint8_t_u_s((l_3796 < 0xD1A6L), 3))), (g_543[1] = l_2293[5][4][4]))) == (l_2421 = (((((((safe_lshift_func_uint8_t_u_u(l_2408[3][0], (safe_rshift_func_uint16_t_u_u((0x71C3L & (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_uint16_t_u((l_2419 = (safe_lshift_func_int8_t_s_s(((g_3421 = (safe_rshift_func_int8_t_s_s((g_1215[0] && l_2418[5][4]), 5))) == l_2390), 2))))), l_3741))), 2)))) <= 0L) || l_2279) | g_3421) && 4L) != g_949[0][6][1]) ^ l_2390))))), (-3L)))) == 0x9FC9L)) && 0x36A7L), l_2386[4])), 8)) != g_361) <= 0x9B065C80L);
                l_2293[5][4][4] = (((((((safe_lshift_func_int8_t_s_u((((((((((l_3408 == l_2293[5][4][4]) ^ (((g_3261 = 0xDFFFL) | (l_3534 = 0x34B8L)) && (safe_lshift_func_int16_t_s_s((((safe_sub_func_int32_t_s_s((l_3891 = ((l_2421 = 0UL) | ((((l_2291[0] > (safe_sub_func_uint8_t_u_u(l_2431, (l_2295 = l_2432)))) < 0x06L) != g_949[0][6][1]) && l_2431))), 0x134D74CCL)) <= (-10L)) < g_3261), 7)))) > 0x9248DD31L) == g_188) == 0UL) < l_3408) == l_2408[3][0]) <= 0x7CL) | l_2431), l_5[1][6])) && 0x07L) | g_866[4][0]) & 0xE8L) <= g_866[7][7]) < g_813[1][0]) != l_2432);
                for (l_2432 = 0; (l_2432 <= 3); l_2432 += 1)
                {
                    uint32_t l_2437 = 8UL;
                    int32_t l_2466 = 0x1A5DEB5BL;
                    uint32_t l_2474[3][4][7] = {{{18446744073709551611UL,18446744073709551609UL,0xDE198DD4L,0UL,0UL,0UL,0xDE198DD4L},{0x582432FAL,0x582432FAL,18446744073709551615UL,0x20D3A748L,1UL,0x5B92F6A6L,1UL},{0x3B7A71C4L,0xBB8986F1L,0xFCA41817L,0xC54627FCL,0xC54627FCL,0xFCA41817L,0xBB8986F1L},{1UL,18446744073709551615UL,0x582432FAL,1UL,1UL,0x688D7EE0L,0x20D3A748L}},{{0xFCA41817L,18446744073709551611UL,0UL,0xBB8986F1L,0UL,18446744073709551611UL,0xFCA41817L},{0x20D3A748L,0x688D7EE0L,1UL,1UL,0x582432FAL,18446744073709551615UL,1UL},{0xBB8986F1L,0xFCA41817L,0xC54627FCL,0xC54627FCL,0xFCA41817L,0xBB8986F1L,0x3B7A71C4L},{1UL,0x5B92F6A6L,1UL,0x20D3A748L,18446744073709551615UL,0x582432FAL,0x582432FAL}},{{0xDE198DD4L,0UL,0UL,0UL,0xDE198DD4L,18446744073709551615UL,0x3B7A71C4L},{1UL,1UL,18446744073709551615UL,18446744073709551615UL,0x5B92F6A6L,0x20D3A748L,0x5B92F6A6L},{0xBB8986F1L,1UL,1UL,0xBB8986F1L,18446744073709551611UL,18446744073709551609UL,0xDE198DD4L},{1UL,18446744073709551615UL,1UL,0x582432FAL,18446744073709551608UL,18446744073709551608UL,0x582432FAL}}};
                    int i, j, k;
                    g_115 = (safe_mod_func_int8_t_s_s(((((g_866[(l_2432 + 4)][(l_2432 + 1)] && l_3874[(l_2432 + 5)]) > (l_3667 < 0L)) && ((safe_sub_func_int32_t_s_s((0xE897L >= l_2437), (0UL ^ 0x39L))) <= (safe_add_func_uint16_t_u_u((l_3796 < l_3796), 0x403CL)))) & 0x0DF0L), l_2386[4]));
                    g_115 = ((g_813[5][0] = ((safe_lshift_func_uint16_t_u_s(g_12, 5)) && 0x9FL)) <= (((safe_add_func_int32_t_s_s((safe_sub_func_uint8_t_u_u(g_172[5], (safe_rshift_func_uint16_t_u_u((((g_3421 = (g_103 && (safe_rshift_func_int8_t_s_s((((safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(((safe_sub_func_int32_t_s_s(l_3408, ((((safe_sub_func_uint32_t_u_u((~l_3534), (l_3891 = (l_2432 < l_3874[(l_2432 + 5)])))) && g_103) || g_115) || g_866[(l_2432 + 4)][(l_2432 + 1)]))) == l_3927), g_543[1])), l_2432)), 3)), 5)) != g_949[0][6][4]), g_3421)) > l_2421) < g_3421), l_3916)))) > i) >= 0xC1L), 9)))), l_2293[5][4][4])) > l_2437) || 0x1B16L));
                    if (g_359[9][0])
                        break;
                    for (g_3261 = 0; (g_3261 <= 3); g_3261 += 1)
                    {
                        int32_t l_2473 = (-1L);
                        int i, j, k;
                        l_2466 = 0x839C60E3L;
                        g_22 = (((g_2177[(g_3261 + 2)][l_2432][(g_3261 + 5)] && (((safe_rshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u(g_2177[(l_2432 + 1)][g_3261][(l_2432 + 5)], 14)), (safe_mod_func_uint16_t_u_u(l_3667, l_3399)))) <= ((l_2473 = (l_3891 = l_2390)) != (g_115 = (0x43DA57DBL | g_541)))) < (g_3421 < l_2474[0][1][4]))) || g_543[2]) || l_2475);
                    }
                }
            }
            for (l_3916 = (-19); (l_3916 < (-22)); l_3916 = safe_sub_func_uint16_t_u_u(l_3916, 7))
            {
                uint8_t l_2479 = 1UL;
                int8_t l_2495 = 0xB0L;
                int32_t l_2513 = 0xA6921076L;
                int32_t l_2547 = 0x6B1B6203L;
                uint8_t l_2563[7] = {0xB3L,0xB3L,0x5EL,0xB3L,0xB3L,0x5EL,0xB3L};
                int i;
                if (l_2479)
                {
                    int16_t l_2490 = 0L;
                    int32_t l_2504 = (-8L);
                    for (l_3702 = (-1); (l_3702 == 46); l_3702 = safe_add_func_int32_t_s_s(l_3702, 5))
                    {
                        int16_t l_2482 = 0xC29FL;
                        l_2295 = (l_2482 >= (safe_add_func_uint16_t_u_u((l_3891 == g_3421), 0x0D89L)));
                        l_2293[5][4][4] = g_188;
                    }
                    l_2295 = ((i = ((((l_3927 = ((+g_12) & ((safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u(g_3421, (((g_3261 = l_5[0][0]) | ((l_3667 <= 0x4CL) || ((l_2490 || (safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(l_2495, l_3927)), 3))) >= g_359[6][6]))) ^ 2UL))), l_2495)) ^ 0L))) < 0x23L) & l_2495) && 0x9BA8983EL)) >= 65527UL);
                    l_2408[3][0] = (((g_103 = (g_3421 >= g_949[0][5][6])) == ((safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s((g_2177[4][1][4] = ((g_172[7] == ((l_2266[0] = (safe_add_func_int32_t_s_s(((l_2504 = l_2495) >= ((safe_mod_func_uint8_t_u_u((l_2490 | ((i = ((0L || (l_2513 = ((l_2490 ^ (safe_add_func_int32_t_s_s((safe_add_func_int8_t_s_s(1L, l_3702)), l_2490))) | l_2432))) >= l_3667)) < 65535UL)), g_22)) && 252UL)), l_3702))) <= l_3534)) | (-10L))), 6)), l_2479)) && (-1L))) ^ (-8L));
                    l_2291[0] = l_3667;
                }
                else
                {
                    uint32_t l_2525 = 0xDBD6AC3EL;
                    int32_t l_2528 = 0xF6619A70L;
                    for (g_541 = 0; (g_541 <= 5); g_541 += 1)
                    {
                        int32_t l_2527 = 0L;
                        int i, j;
                        l_3891 = ((safe_rshift_func_uint8_t_u_u((l_2528 = ((l_5[g_541][g_541] = (safe_unary_minus_func_uint16_t_u(0x2292L))) ^ (l_2293[5][4][4] = (((-7L) < ((safe_lshift_func_uint8_t_u_u((0xE68EF4FBL < ((safe_add_func_int8_t_s_s((l_2291[0] = ((safe_add_func_uint32_t_u_u((l_3741 != (safe_add_func_int16_t_s_s((((65531UL > ((l_2525 || g_361) & g_949[1][7][7])) || (((g_3409 = ((l_2525 > g_172[4]) & 0x1B0088F1L)) ^ l_2479) & l_2479)) && 0x82L), 0x2333L))), g_12)) || g_3421)), g_3421)) ^ 4294967295UL)), 1)) == 5L)) == l_2527)))), 0)) >= 255UL);
                        l_3891 = (safe_lshift_func_uint16_t_u_u(1UL, (safe_lshift_func_uint16_t_u_s(((((((safe_rshift_func_uint8_t_u_s(((((l_3927 = l_2432) <= (0UL ^ (safe_mod_func_int8_t_s_s(((safe_sub_func_int32_t_s_s(l_2295, g_543[2])) ^ ((l_2418[0][3] <= g_3421) != (safe_sub_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(((g_2177[3][1][9] = l_2386[4]) <= (safe_mod_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(g_543[1], g_361)), l_2513))), l_2528)), l_2432)))), l_2387)))) <= 0x476CB2BEL) <= l_5[g_541][(g_541 + 1)]), 5)) == l_2547) ^ 0x6F1AL) & l_3399) | 0x2AL) | g_172[2]), g_22))));
                        l_3891 = (g_115 = ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u(((0xFFL <= 0x8EL) && (g_813[0][0] <= (-1L))), 0)), 0x2FL)) | (0x30L & (((safe_add_func_int16_t_s_s((0x0450E2D6L <= l_2432), (g_12 < g_949[0][6][1]))) || 0x6291L) > 0x03C1L))));
                        l_2527 = (k = 0x5A0AF0AFL);
                    }
                    g_22 = 1L;
                    if ((safe_lshift_func_int8_t_s_s((+((safe_rshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s((l_2266[3] < l_2563[0]), (safe_mod_func_uint16_t_u_u(l_2566[2][0], ((safe_mod_func_uint32_t_u_u(0xB86569AAL, (safe_sub_func_int8_t_s_s((l_2525 & (safe_sub_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(l_2575, l_3017)), ((g_115 = l_5[1][6]) && ((((l_2547 = (safe_rshift_func_uint8_t_u_s((((g_3261 = g_12) == l_2547) || (-1L)), 5))) && 0x8CF5425BL) > g_361) ^ l_3796))))), 0x41L)))) & 0xFF38L))))) != l_2563[0]), 1UL)), l_2575)) && 9UL)), 1)))
                    {
                        l_2585[1] = (+(0x39E1L | (safe_lshift_func_int16_t_s_s((g_866[7][8] = ((65535UL & 0x0AC2L) <= 0xB3EAL)), ((g_188 = g_188) >= (l_2295 = (g_543[2] = (((l_2575 < (((safe_sub_func_uint16_t_u_u(l_2525, (g_2177[3][1][9] != (l_2584 = (g_3421 && g_12))))) & 0xD04E619AL) <= l_3534)) == g_543[1]) >= l_2575))))))));
                        g_115 = g_12;
                    }
                    else
                    {
                        uint32_t l_2599 = 0x7CDA3D77L;
                        int32_t l_2616 = (-4L);
                        l_3017 = ((1L == l_2525) != (safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(((-3L) != ((safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((((((((l_2386[4] >= (g_813[1][0] < (g_22 = (((0xFFL | g_949[0][6][1]) == (((safe_add_func_uint32_t_u_u((l_2563[0] || g_3421), g_103)) >= l_2585[2]) || l_2525)) < 0x66L)))) ^ l_2599) || g_541) >= l_2600) >= l_2528) != 6L) <= l_3534) >= l_2599), l_2528)), 0x61L)) ^ g_949[2][8][6])), g_543[1])), (-4L))));
                        l_2585[2] = ((l_3822 < (safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((l_2616 = ((safe_lshift_func_uint16_t_u_s(l_2266[0], 6)) ^ ((+(l_2547 = g_949[0][6][1])) && (l_2584 != (safe_sub_func_uint16_t_u_u(((l_2408[2][4] = 6L) ^ (safe_mod_func_int32_t_s_s(g_3421, g_172[4]))), (+((-1L) && (safe_lshift_func_uint8_t_u_u(g_22, g_541)))))))))), 0)), 11))) <= l_2387);
                        l_3891 = g_12;
                    }
                    l_3891 = (safe_mod_func_uint32_t_u_u(l_2619[1], ((((l_3017 < g_103) || l_2620) == ((((safe_sub_func_int16_t_s_s(((g_2177[3][1][9] = l_2547) | (l_2418[2][1] < (+(0xC4FEL ^ (safe_rshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s((((l_2528 > (-1L)) | (-1L)) > g_3421), g_359[4][0])), 2UL)), 7)))))), l_3916)) > l_2266[4]) <= 2UL) < l_2525)) ^ (-6L))));
                }
            }
            k = (safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u(((safe_mod_func_uint32_t_u_u((((l_2408[3][0] = g_22) <= ((g_359[9][0] & (safe_rshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((g_359[6][6] && (safe_mod_func_uint8_t_u_u(((((safe_rshift_func_uint8_t_u_s(((safe_sub_func_int8_t_s_s((g_188 & (g_3421 = (safe_sub_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((((~0x448CL) ^ (safe_lshift_func_int8_t_s_s(((g_172[4] = l_3874[7]) | ((safe_lshift_func_uint16_t_u_s(0xEFAAL, 7)) < 6UL)), 7))) < (1L > g_813[1][0])), g_3261)), l_2293[5][4][4])))), 255UL)) ^ g_2177[3][1][9]), l_2294)) || 1UL) != l_3822) < l_2600), (-1L)))), l_3891)), 6))) | g_541)) < 4294967295UL), g_361)) || l_2620), 1)), 7));
            for (g_3261 = 0; g_3261 < 3; g_3261 += 1)
            {
                for (g_115 = 0; g_115 < 9; g_115 += 1)
                {
                    for (l_3927 = 0; l_3927 < 9; l_3927 += 1)
                    {
                        g_949[g_3261][g_115][l_3927] = 0L;
                    }
                }
            }
        }
        else
        {
            int16_t l_2673 = (-1L);
            int32_t l_2704 = (-1L);
            if ((safe_lshift_func_uint16_t_u_s(0xCDD4L, l_5[5][4])))
            {
                int8_t l_2662[2];
                int32_t l_2672 = 0x458B65B5L;
                int32_t l_2691[7][4] = {{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)},{0xA7CC0C33L,(-1L),0xA7CC0C33L,0xA7CC0C33L},{(-1L),(-1L),0xB115895CL,(-1L)},{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)},{0xA7CC0C33L,(-1L),0xA7CC0C33L,0xA7CC0C33L},{(-1L),(-1L),0xB115895CL,(-1L)},{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)}};
                uint8_t l_2701 = 0x03L;
                int i, j;
                for (i = 0; i < 2; i++)
                    l_2662[i] = (-6L);
                g_115 = (((k = (l_2295 = (l_3741 = ((g_115 < ((safe_add_func_int32_t_s_s(g_949[0][6][1], ((+((safe_lshift_func_uint16_t_u_u((((l_3667 = ((l_3891 = ((l_2662[0] < (((((safe_lshift_func_int16_t_s_u(((safe_add_func_int16_t_s_s((((safe_lshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u(65535UL, (~(((l_2662[1] >= g_541) >= 9L) && g_2177[5][0][0])))), 5)) >= g_359[6][0]) >= l_2619[1]), l_2662[0])) ^ 0x2BBDAAFAL), g_813[5][0])) ^ l_2672) | 250UL) & (-8L)) != l_3927)) == g_949[2][0][1])) ^ 0x0227889AL)) <= (-9L)) >= l_2673), g_2177[4][1][5])) && g_115)) < 0x41L))) & g_813[1][0])) == 0x5FL)))) != g_543[2]) > l_3796);
                for (l_3408 = 0; (l_3408 <= 6); l_3408 += 1)
                {
                    g_173 = 0L;
                    for (l_3927 = 0; (l_3927 <= 6); l_3927 += 1)
                    {
                        int32_t l_2677[7][8][4] = {{{1L,0x41A054B2L,0L,0x2D0DBF52L},{0x0CF1A441L,0L,(-5L),(-1L)},{(-4L),0L,0x731C9F43L,0x01A3D290L},{0L,(-10L),0x0D46BF51L,0x0D46BF51L},{3L,3L,0x4CB0245BL,0x60E2D043L},{0x0D46BF51L,0L,0xCE5C71E8L,0xD450BA5CL},{1L,0xBBB0E83CL,(-1L),0xCE5C71E8L},{0xBC9F03A0L,0xBBB0E83CL,(-10L),0xD450BA5CL}},{{0xBBB0E83CL,0L,(-1L),0x60E2D043L},{1L,3L,0xBC9F03A0L,0x0D46BF51L},{0x731C9F43L,(-10L),(-9L),0x01A3D290L},{0x4CB0245BL,0L,0x7AE1F11BL,(-1L)},{0xB8ACCB37L,0L,1L,0x2D0DBF52L},{0x60E2D043L,0x41A054B2L,0x830FB6EAL,(-4L)},{0L,(-1L),0L,2L},{(-9L),0L,3L,(-10L)}},{{0L,0x2D0DBF52L,0L,0L},{0x41A054B2L,0x8FB9928BL,0L,0x0CF1A441L},{0L,0x731C9F43L,3L,0x7AE1F11BL},{(-9L),0L,0L,(-3L)},{0L,(-3L),0x830FB6EAL,0L},{0x60E2D043L,(-9L),1L,0L},{0xB8ACCB37L,(-1L),0x7AE1F11BL,0xA2CE5981L},{0x4CB0245BL,0xB8ACCB37L,(-9L),(-1L)}},{{0x731C9F43L,0xBC9F03A0L,0xBC9F03A0L,0x731C9F43L},{1L,0xD450BA5CL,(-1L),(-9L)},{0xBBB0E83CL,0x0CF1A441L,(-10L),1L},{0xBC9F03A0L,0L,(-1L),1L},{1L,0x0CF1A441L,0xCE5C71E8L,(-9L)},{0x0D46BF51L,0xD450BA5CL,0x4CB0245BL,0x731C9F43L},{3L,0xBC9F03A0L,0x0D46BF51L,(-1L)},{0L,0xB8ACCB37L,0x731C9F43L,0xA2CE5981L}},{{(-4L),(-1L),(-5L),0L},{0x0CF1A441L,2L,0L,(-1L)},{0x7AE1F11BL,0x2D0DBF52L,0xCE5C71E8L,0x2D0DBF52L},{0x8FB9928BL,0xA2CE5981L,0x2D0DBF52L,1L},{1L,1L,(-9L),0x41A054B2L},{0x0D46BF51L,(-3L),0L,(-4L)},{0x0D46BF51L,(-5L),(-9L),0L},{1L,(-4L),0x2D0DBF52L,0xB8ACCB37L}},{{0x8FB9928BL,(-9L),0xCE5C71E8L,0x0CF1A441L},{0x7AE1F11BL,(-1L),0L,(-5L)},{0x41A054B2L,0L,0x01A3D290L,0x8FB9928BL},{0x0CF1A441L,0L,1L,0xBC9F03A0L},{0xA2CE5981L,0L,(-10L),(-10L)},{0x4CB0245BL,0x4CB0245BL,9L,1L},{(-10L),0L,1L,0L},{0L,0L,0x0D46BF51L,1L}},{{0x731C9F43L,0L,0L,0L},{0L,0L,1L,1L},{0xD450BA5CL,0x4CB0245BL,0x731C9F43L,(-10L)},{1L,0L,2L,0xBC9F03A0L},{9L,0L,1L,0x8FB9928BL},{0x830FB6EAL,0L,0xD450BA5CL,(-5L)},{1L,(-1L),3L,0x0CF1A441L},{0xBBB0E83CL,(-9L),0xBBB0E83CL,0xB8ACCB37L}}};
                        int i, j, k;
                        l_2677[4][2][3] = (safe_unary_minus_func_int16_t_s((safe_unary_minus_func_int8_t_s((g_359[(l_3408 + 1)][l_3927] > l_2673)))));
                    }
                }
                if (((l_2295 = (((l_2291[1] = g_172[1]) && (safe_sub_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_u((((g_3421 = (g_2177[0][0][9] = ((l_3667 > l_3017) & (((safe_mod_func_int32_t_s_s((((((((((safe_lshift_func_int8_t_s_u((g_361 = (((safe_add_func_uint8_t_u_u(l_2662[1], ((-1L) <= l_2673))) != ((((safe_sub_func_int32_t_s_s((!l_3822), ((l_2691[0][0] = (l_2408[3][0] = ((0xB248A39EL & ((g_188 = (-2L)) < l_3891)) >= l_2662[1]))) && l_2673))) && g_866[4][0]) && l_2691[0][2]) > l_2673)) & 0L)), g_3421)) <= g_866[4][0]) == l_2673) | l_3408) && g_2177[3][3][8]) <= l_3796) ^ l_2673) != g_3421) ^ 0xECF0AEBAL), 0xCF415C16L)) > g_543[1]) == l_2673)))) < l_2291[0]) & l_2266[3]), l_3927)) && (-4L)), g_359[1][6]))) == 0xBF9AL)) > 0xEE49L))
                {
                    int32_t l_2700 = (-6L);
                    l_3017 = 1L;
                    l_3017 = (((0xB2637E3CL != (~((safe_add_func_int8_t_s_s((l_2691[0][0] = i), (l_2704 = (g_3421 = (((-3L) ^ (l_2701 = (l_2700 = (safe_mod_func_uint8_t_u_u(0xD2L, 5UL))))) ^ (g_172[1] == ((safe_sub_func_int16_t_s_s(((g_543[1] = (l_2704 & ((!(safe_mod_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(l_3822, 0x8C7F0823L)) == g_3261), l_2672))) >= 0UL))) > 0xA047L), l_2672)) >= g_173))))))) && l_2704))) <= l_2673) > 0L);
                    l_2704 = (249UL & ((safe_lshift_func_int16_t_s_u(g_12, 6)) && 1UL));
                }
                else
                {
                    int32_t l_2715 = 0x20D70AE1L;
                    int32_t l_2723 = 0x493688ADL;
                    for (l_3534 = 0; (l_3534 > 25); l_3534++)
                    {
                        uint16_t l_2724 = 65535UL;
                        l_2704 = ((((((l_3822 = l_2715) & ((4UL == l_2408[3][2]) <= (safe_unary_minus_func_uint32_t_u(((safe_add_func_int8_t_s_s((safe_add_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(g_12, 14)), ((l_2723 = 0xEEF6D83EL) > g_541))), 0x16L)) && g_103))))) >= ((l_2691[3][1] = 65535UL) > l_2724)) && g_359[9][6]) || l_2662[0]) > l_3534);
                        return l_3916;
                    }
                    l_2295 = (l_2691[0][0] = ((l_2293[5][4][4] = (l_5[4][2] | ((l_3017 ^ (((0x3248F897L < ((safe_unary_minus_func_int16_t_s(0xA585L)) ^ (l_3927 > g_541))) < ((0L && (((-10L) < (0x522993A5L < 0x6C6B07C7L)) == l_2408[3][0])) || l_3399)) > i)) > 0x637DBBF8L))) && l_3796));
                    g_22 = (safe_unary_minus_func_int8_t_s((l_3927 = ((safe_rshift_func_uint16_t_u_u(1UL, 7)) < (l_3741 || l_3796)))));
                    for (l_3667 = 0; (l_3667 <= (-25)); l_3667--)
                    {
                        l_3017 = l_3534;
                        return g_949[0][6][1];
                    }
                }
            }
            else
            {
                l_2408[0][5] = l_2619[1];
                l_3017 = (((((((safe_rshift_func_uint8_t_u_s((g_2177[3][1][9] = ((safe_add_func_uint8_t_u_u((safe_add_func_int32_t_s_s(l_2600, (l_2408[0][0] = (safe_add_func_uint8_t_u_u((g_3421 = (l_3891 < (g_172[4] != 0xD4L))), 1L))))), ((l_2673 == l_3916) < (g_12 < l_2619[1])))) < g_1215[1])), 7)) <= g_103) ^ 0xC9C7L) && 1UL) || l_3408) | g_12) != l_2673);
            }
        }
        return l_3534;
    }

                    l_2294 = l_3655;
                        l_3017 = ((safe_sub_func_uint32_t_u_u(0xBE8ABD83L, (((g_2177[3][1][9] = (l_3897[2][0][0] = g_1524)) ^ (((g_161 = (((safe_mod_func_int16_t_s_s((safe_add_func_uint16_t_u_u((((((~65535UL) > g_3484) == l_3892) != l_3892) < (((safe_rshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s(l_3907, 1L)), 4)) == (g_22 = (-6L))) < l_3851)), l_3851)), l_3909[0][0])) && l_3017) <= 0x9386A289L)) > l_3874[2]) >= l_3732)) | 0x77F0A1CDL))) < l_2290);
                    }
                    l_3017 = (safe_add_func_uint32_t_u_u((l_3851 = ((+((((l_3916 = (safe_rshift_func_int8_t_s_u((-10L), 7))) && ((safe_unary_minus_func_int16_t_s((1L && (safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u((g_315 < ((g_172[4] >= (0xBEL && (l_2790[4][0] >= ((3L < (safe_sub_func_int8_t_s_s((((safe_sub_func_int16_t_s_s((((((~l_3399) >= l_2526) < g_3484) && g_315) | g_1215[4]), 0x3FC3L)) && 0x9294L) & l_3257), g_188))) == l_3171)))) == l_3891)), l_3017)), l_2526))))) == l_3655)) & g_247) > g_315)) && g_161)), l_3655));
                    return l_3732;
                };


                    l_3892 = (safe_sub_func_uint32_t_u_u(((g_540 != (g_1524 = (((safe_mod_func_uint8_t_u_u((g_217 & (l_3891 = (safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_s(65534UL, 15)) == (g_813[5][0] = ((safe_add_func_uint8_t_u_u(((((g_359[9][0] && (safe_lshift_func_uint8_t_u_s(l_3780, 2))) <= l_3851) <= g_2352[2]) != 1UL), ((safe_add_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u((g_361 = l_3796), g_974)) == l_3755[0][0][5]), g_217)) & g_2476))) || 0xD0F0L))), l_3871)))), 1L)) & l_2266[3]) < g_2352[4]))) & l_3871), l_3808));
                    }
                    else
                    {

l_3732 += 1;


                    return g_1215[3];
                    }
                    for (l_2294 = 0; (l_2294 <= 27); l_2294++)
                    {
                        uint32_t l_3907 = 4294967295UL;
                        l_3808 = g_217;
                        g_2476 = ((safe_sub_func_uint32_t_u_u(0xBE8ABD83L, (((g_2177[3][1][9] = (l_3897[2][0][0] = g_974)) ^ (((l_3910 = (((safe_mod_func_int16_t_s_s((safe_add_func_uint16_t_u_u((((((~65535UL) > g_2576) == l_3892) != g_247) < (((safe_rshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s(l_3907, 1L)), 4)) == (l_3908 = (-6L))) < g_103)), l_3851)), l_3909[0][0])) && g_2476) <= 0x9386A289L)) > g_2352[2]) >= g_22)) | 0x77F0A1CDL))) < g_541);
                    }
                    g_2476 = (safe_add_func_uint32_t_u_u((g_103 = ((+((((l_3916 = (safe_rshift_func_int8_t_s_u((-10L), 7))) && ((safe_unary_minus_func_int16_t_s((1L && (safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u((g_63 < ((g_172[4] >= (0xBEL && (l_2790[4][0] >= ((3L < (safe_sub_func_int8_t_s_s((((safe_sub_func_int16_t_s_s((((((~l_3796) >= l_3927) < l_3732) && g_63) | g_1215[4]), 0x3FC3L)) && 0x9294L) & g_161), g_1524))) == g_538)))) == l_3891)), g_2476)), g_4))))) == g_217)) & g_3484) > g_63)) && l_3910)), g_2710));
                    return l_3780;
                }
                if (g_2177[4][0][3])
                    continue;
            }
        }
        l_3780 = g_949[0][8][6];
        if ((g_3258 = (safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(3L, 11)), (safe_lshift_func_uint8_t_u_u(g_2598, (safe_add_func_int32_t_s_s((l_3937 = (g_247 = (safe_unary_minus_func_int32_t_s((l_3908 = ((4294967288UL > ((g_538 = 0x2816L) | l_3732)) & (g_2598 && g_359[9][0]))))))), ((6UL == ((0x973FL <= g_361) && l_2418[5][4])) > g_359[9][0])))))))))
        {
            l_3772[2][2][0] = g_115;
            g_247 = (0L & 0x34L);
        }
        else
        {
            int32_t l_3960 = (-4L);
            int8_t l_3991[1][5] = {{(-9L),(-9L),(-9L),(-9L),(-9L)}};
            int32_t l_4020 = 0x4B3E2823L;
            int i, j;
            for (l_3655 = (-28); (l_3655 < 46); ++l_3655)
            {
                int16_t l_3951 = 0x1704L;
                int32_t l_3955[7][7] = {{0x94E9D490L,(-3L),0xF4171F52L,(-3L),0x94E9D490L,0x94E9D490L,(-3L)},{(-1L),0xB5D7E716L,(-1L),0x3C2EED67L,0x3C2EED67L,(-1L),0xB5D7E716L},{(-3L),(-8L),0xF4171F52L,0xF4171F52L,(-8L),(-3L),(-8L)},{(-1L),0x3C2EED67L,0x3C2EED67L,(-1L),0xB5D7E716L,(-1L),0x3C2EED67L},{0x94E9D490L,0x94E9D490L,(-3L),0xF4171F52L,(-3L),0x94E9D490L,0x94E9D490L},{0xCBAC2FE8L,0x3C2EED67L,1L,0x3C2EED67L,0xCBAC2FE8L,0xCBAC2FE8L,0x3C2EED67L},{(-1L),(-8L),(-1L),(-3L),(-3L),(-1L),(-8L)}};
                int8_t l_4032 = 8L;
                int i, j;
                for (l_2674 = 0; (l_2674 >= 29); l_2674++)
                {
                    uint8_t l_3954 = 0xF9L;
                    g_3957 = (g_813[2][0] != (safe_add_func_uint32_t_u_u(((l_3807[4] & 1UL) > (safe_lshift_func_uint8_t_u_s((!g_3152), 6))), ((0L | (((l_3955[3][0] = (((safe_lshift_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(l_3951, 12)) & (safe_sub_func_int16_t_s_s(g_3261, (g_63 = (1L <= g_3258))))), l_3954)) | 0xC3L) && 0L)) || 1UL) & g_3956[2])) != g_361))));
                }
                for (g_3261 = 0; (g_3261 > 34); ++g_3261)
                {
                    uint32_t l_3973 = 0x4C44CE71L;
                    int8_t l_3988[10] = {(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L)};
                    int32_t l_4033 = (-1L);
                    int32_t l_4034 = 0x9751D3BDL;
                    int i;
                    g_2576 = ((((l_2290 ^ (g_217 = ((l_3960 | (safe_add_func_int8_t_s_s(0x29L, ((safe_add_func_int8_t_s_s(((safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s(g_3409, g_2352[2])), g_949[0][6][1])) == l_3534), ((safe_sub_func_int32_t_s_s(g_974, ((safe_add_func_int16_t_s_s((1L <= g_540), l_3707)) && g_172[6]))) != l_3960))) <= 0x1406L)))) ^ 255UL))) == l_3960) <= l_3973) && l_3951);
                    for (l_3752 = 0; (l_3752 <= 8); l_3752 += 1)
                    {
                        uint8_t l_3986 = 0UL;
                        int32_t l_4009[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_4009[i] = 1L;
                        l_3732 = (g_2576 = (l_3988[7] = (safe_add_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((l_3874[l_3752] || 254UL), (safe_rshift_func_int16_t_s_s(l_3873, 11)))) == (((-9L) >= ((((safe_rshift_func_int8_t_s_u(g_540, (l_3960 && (safe_rshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u(((g_2177[3][1][9] = (((g_12 || ((l_3822 && ((0x690DL <= l_3909[0][0]) | l_3986)) | l_3987)) && 0x59DE2E1CL) || 0x0ECC5B70L)) < l_3986), 9)), g_2476))))) < l_3874[l_3752]) & g_161) > l_3986)) > l_3973)), 65533UL))));
                        g_2576 = (g_543[2] == 4294967295UL);
                        g_2476 = (g_247 = (safe_rshift_func_uint8_t_u_u(l_3991[0][2], (l_3807[0] > (safe_rshift_func_uint16_t_u_s((+(0xF87CL < l_3399)), (g_1524 = (safe_lshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u((((+(1UL <= (safe_sub_func_int8_t_s_s(((l_3937 > (((+(l_4009[1] = ((safe_add_func_uint32_t_u_u(l_3874[8], (safe_rshift_func_uint8_t_u_u((g_974 & (l_3991[0][2] && g_3409)), l_3874[l_3752])))) ^ g_83))) & g_359[9][0]) >= l_2674)) | g_2476), 0x23L)))) == g_22) >= g_361), l_3988[2])), l_3937)), 6)))))))));
                    }
                    for (l_3116 = 0; (l_3116 < 12); l_3116 = safe_add_func_int32_t_s_s(l_3116, 7))
                    {
                        return g_974;
                    }
                    g_3956[1] = (safe_lshift_func_int16_t_s_s((l_3960 != ((l_3262 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_uint8_t_u_u((safe_mod_func_int16_t_s_s((l_4020 = (g_543[2] = 0x7667L)), (((safe_add_func_int16_t_s_s((l_3988[6] ^ (l_4034 = (l_4033 = (((safe_sub_func_uint8_t_u_u(g_12, l_3955[3][0])) & ((safe_add_func_uint16_t_u_u(((1UL >= g_2476) || ((safe_unary_minus_func_int16_t_s(g_2177[3][1][9])) | (safe_rshift_func_uint8_t_u_u(((((safe_sub_func_uint32_t_u_u(((((-1L) < g_12) | 248UL) || l_3991[0][3]), g_538)) > l_3991[0][2]) & l_4032) & l_2674), g_2420)))), g_217)) != g_188)) || 248UL)))), l_3960)) <= 0x3193CC09L) | l_3991[0][1]))), l_3955[4][6])), 0))) || l_4034)), g_115));
                }
            }
        }
    }
    return l_4035;
}







static uint8_t func_6(uint32_t p_7)
{
    int16_t l_2267 = 0x1B23L;
    l_2267 = 0x31F7CEF5L;
                                        if (((!l_2267) || !(l_2267)) )
{

{
                transparent_crc(g_2177[g_247][g_3258][g_541], "g_2177[g_247][g_3258][g_541]", g_3258);
                if (g_3258) printf("index = [%d][%d][%d]\n", g_247, g_3258, g_541);

            }

}
  return l_2267;
}







static uint16_t func_8(int16_t p_9)
{
    uint16_t l_21 = 0xEB38L;
    int32_t l_26 = 0xD437F1BDL;
    int32_t l_27 = 1L;
    int8_t l_28 = 0x24L;
    int32_t l_975[3][1];
    uint16_t l_1001 = 0x0784L;
    uint16_t l_1077 = 0x3CE7L;
    uint16_t l_1180 = 0UL;
    int8_t l_1359[7] = {0L,0xD9L,0L,0L,0xD9L,0L,0L};
    uint16_t l_1377 = 1UL;
    int8_t l_1434 = 2L;
    int16_t l_1631 = 0xB5F5L;
    int32_t l_1633 = 0xE2E5D52BL;
    uint32_t l_1760 = 0UL;
    int32_t l_1768 = 1L;
    int32_t l_1836 = 0x207434B2L;
    uint16_t l_1956 = 8UL;
    int16_t l_2163 = 0x991BL;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 1; j++)
            l_975[i][j] = 0x717E753EL;
    }
    l_975[0][0] = (((safe_add_func_uint8_t_u_u((g_974 = ((g_12 = (-5L)) & (safe_mod_func_uint8_t_u_u((0x68L ^ (func_15(l_21, (((g_22 = g_4) >= ((l_27 = (g_4 == (l_26 = ((p_9 != (p_9 ^ (-1L))) == (safe_mod_func_int32_t_s_s(((~g_4) < p_9), g_4)))))) < g_4)) > p_9), l_21, g_4, l_28) | 4294967295UL)), l_28)))), 3L)) == g_4) <= 0L);
    if (g_540)
    {
        int32_t l_982 = (-1L);
        int32_t l_987 = 0xB0431CEDL;
        int32_t l_1000[3][7] = {{0x510B92E6L,0x510B92E6L,3L,0x510B92E6L,0x510B92E6L,3L,0x510B92E6L},{0x510B92E6L,0x285A33BBL,0x285A33BBL,0x510B92E6L,0x285A33BBL,0x285A33BBL,0x510B92E6L},{0x285A33BBL,0x510B92E6L,0x285A33BBL,0x285A33BBL,0x510B92E6L,0x285A33BBL,0x285A33BBL}};
        uint16_t l_1153 = 0x1594L;
        int32_t l_1179 = 0xF7BD02E2L;
        int16_t l_1271 = 0x809CL;
        uint32_t l_1288 = 0x20D07CB7L;
        int16_t l_1320 = (-1L);
        uint8_t l_1374[5];
        int32_t l_1450 = 0xAAB2BE5DL;
        int32_t l_1574[10][5][5] = {{{0xB88192B0L,1L,(-1L),0x9AFCA347L,(-8L)},{9L,0x68D8C52CL,0x42676019L,(-7L),0xF5F6E304L},{(-1L),0x6DD85EFFL,1L,0xDDD8D046L,(-4L)},{(-5L),0xF5F6E304L,8L,0xF5F6E304L,(-5L)},{0x805059C3L,0x2D85E9C1L,0xB8108C61L,0L,0xDDD8D046L}},{{0x3158F380L,(-1L),0xC9DC7FEEL,0x905909A4L,0x6C5667D7L},{(-1L),0xB88192B0L,0L,0x2D85E9C1L,0xDDD8D046L},{0x3E0D08DAL,0x905909A4L,(-1L),0xC9DC7FEEL,(-5L)},{0xDDD8D046L,(-7L),0x58005A23L,0L,(-4L)},{0x08914F9DL,0xA9C617C3L,0xD2F7E75DL,(-8L),0xF5F6E304L}},{{1L,0xE623C1BAL,(-7L),1L,(-8L)},{(-1L),0x3E0D08DAL,0x72DDDB91L,(-5L),0L},{0xB26A9CD1L,0xB88192B0L,0L,(-1L),0xE623C1BAL},{(-4L),(-1L),0x96202DA2L,0x96202DA2L,0x72DDDB91L},{(-1L),0xE2A9CB83L,0x65297164L,(-4L),(-3L)}},{{0xD5CB906BL,0x3E0D08DAL,0x08914F9DL,(-4L),0x6C5667D7L},{0xE2A9CB83L,0xFBDFF96BL,0x612FD6CFL,0x8EA251F8L,0x58005A23L},{0xD5CB906BL,0xFC4ADC57L,0x0FFFC8EEL,(-1L),0xDBA7D363L},{(-1L),0x6DD85EFFL,0x2D85E9C1L,1L,1L},{0x5C021EF9L,(-4L),0xB9A8A535L,8L,0xC9DC7FEEL}},{{0xB8108C61L,0L,2L,1L,(-1L)},{0x72DDDB91L,(-6L),6L,0x3E0D08DAL,0x42676019L},{(-8L),(-7L),0x612FD6CFL,1L,1L},{(-7L),0x0FFFC8EEL,8L,(-6L),8L},{(-8L),(-8L),0x2D7A9E7DL,0x805059C3L,0xB8108C61L}},{{8L,0x6C5667D7L,0x7A142AA9L,0xB9A8A535L,0xC9DC7FEEL},{(-10L),1L,(-2L),0xFBDFF96BL,0L},{9L,0x6C5667D7L,0L,9L,(-1L)},{(-3L),(-8L),0L,(-1L),0x58005A23L},{0xC5431E8FL,0x0FFFC8EEL,8L,(-7L),0xD2F7E75DL}},{{0L,(-7L),0xB88192B0L,0xB8108C61L,(-7L)},{0xA864CBE7L,(-6L),0xFC4ADC57L,0x66D49155L,0x72DDDB91L},{0xB092DCD2L,0L,1L,0xFBDFF96BL,0L},{(-6L),(-4L),(-1L),0x96202DA2L,0x96202DA2L},{9L,0x6DD85EFFL,9L,0x612FD6CFL,0L}},{{0xC9DC7FEEL,0xFC4ADC57L,0x721C1174L,(-6L),(-1L)},{0L,0xFBDFF96BL,0xB26A9CD1L,(-8L),(-1L)},{0x7A142AA9L,0x3E0D08DAL,0x721C1174L,(-1L),0xC5431E8FL},{(-7L),0xE2A9CB83L,9L,1L,1L},{9L,0x72DDDB91L,(-1L),0x42676019L,0L}},{{2L,0xB092DCD2L,1L,0xE2A9CB83L,(-8L)},{0x42676019L,8L,0xFC4ADC57L,(-1L),0x7A142AA9L},{(-8L),1L,0xB88192B0L,0x58005A23L,(-1L)},{0x721C1174L,0x34C80B3CL,8L,(-9L),0x3E0D08DAL},{(-4L),0L,0L,(-4L),0xA5ACB989L}},{{0x72DDDB91L,0x42676019L,0L,0xC5431E8FL,0x96202DA2L},{(-1L),0xB092DCD2L,(-2L),2L,1L},{0x34C80B3CL,0x642128BEL,0x7A142AA9L,0xC5431E8FL,0x642128BEL},{(-1L),1L,0x2D7A9E7DL,(-4L),(-7L)},{0x0FFFC8EEL,0x3E0D08DAL,8L,(-9L),0x6C5667D7L}}};
        int16_t l_1736 = 0xB9D6L;
        int i, j, k;
                                            while ((!l_1320) )
{

g_974 += 1;


}
                    for (i = 0; i < 5; i++)
            l_1374[i] = 251UL;
        if ((safe_sub_func_int32_t_s_s(((safe_sub_func_uint32_t_u_u((l_1001 = (safe_add_func_uint32_t_u_u(((((g_217 = (l_982 == (g_315 = (0x1527L != ((((((safe_sub_func_uint32_t_u_u((safe_mod_func_int16_t_s_s(p_9, (l_987 = 0x122DL))), 0xAF5DB42CL)) < (7L < g_949[2][8][7])) <= p_9) > ((((((safe_mod_func_int8_t_s_s(((((l_1000[1][6] = ((safe_lshift_func_uint16_t_u_u((safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u(((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_int16_t_s_s(((l_975[0][0] <= p_9) && 0x7284A069L), 6)) >= l_982), g_217)) <= p_9), p_9)), l_982)), 3)) <= l_982)) < g_188) != g_172[4]) < p_9), 0xE7L)) || g_103) <= 0x4BB63EC3L) ^ l_28) & 0x178DB0B5L) & l_982)) <= l_21) == g_949[1][4][1]))))) != 0x11L) && p_9) >= g_103), p_9))), 4294967295UL)) && l_982), (-7L))))
        {
            int32_t l_1044 = 0x5A13B012L;
            uint32_t l_1107 = 0x28F65E86L;
            int32_t l_1131 = (-4L);
            int8_t l_1145[5] = {0x88L,0x88L,0x88L,0x88L,0x88L};
            int i;
            for (p_9 = 0; (p_9 <= (-19)); --p_9)
            {
                int32_t l_1012 = (-1L);
                uint16_t l_1029 = 0x9278L;
                l_1029 = (g_22 = (safe_mod_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s((safe_mod_func_uint8_t_u_u(l_1012, g_543[1])), (((l_975[0][0] = (((!(~((safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u(l_1000[1][6], ((0x22L > (safe_rshift_func_uint8_t_u_u(250UL, 0))) <= ((safe_mod_func_int8_t_s_s((0x271358C7L <= ((safe_mod_func_int32_t_s_s((safe_add_func_int16_t_s_s(g_22, ((safe_sub_func_uint32_t_u_u(5UL, (0x75D2E236L <= g_172[4]))) < 1L))), p_9)) > g_866[4][0])), g_866[4][0])) == p_9)))), l_1012)) | 0x106106EEL))) ^ g_173) != 9L)) != (-5L)) < p_9))), 0)) ^ g_22), p_9)));
                if (l_1012)
                    break;
                l_1044 = ((-2L) > (safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_s(((safe_rshift_func_int8_t_s_s(((safe_rshift_func_int8_t_s_u(0x7DL, 1)) > (safe_add_func_int32_t_s_s(0x5DAB9F54L, g_217))), (4294967295UL > ((l_1000[1][6] == ((safe_sub_func_int32_t_s_s((l_982 = p_9), ((g_173 > ((g_361 <= p_9) <= g_103)) >= g_543[1]))) == g_538)) ^ l_1000[1][6])))) ^ 0xF9C6D80AL), g_188)) != p_9), 0)), 0x7AL)));
                g_22 = (+1UL);
            }
            if ((p_9 ^ 0xE840E5A7L))
            {
                uint32_t l_1048[4];
                int32_t l_1051 = 0x370D4B7EL;
                int16_t l_1078 = 1L;
                int i;
                                                    if ((l_1077 > l_1288) )
{

{
        transparent_crc(g_543[g_3152], "g_543[g_3152]", l_1633);
        if (l_1633) printf("index = [%d]\n", g_3152);

    }

}
                    for (i = 0; i < 4; i++)
                    l_1048[i] = 0x5311DC50L;
                g_22 = (l_1044 = p_9);
                                                    if ((l_1131 > g_247) )
{

for (l_1179 = 0; l_1179 < 3; l_1179++)
    {
        transparent_crc(g_543[l_1179], "g_543[l_1179]", g_2576);
        if (g_2576) printf("index = [%d]\n", l_1179);

    };


}
                    l_1051 = ((safe_rshift_func_uint16_t_u_u(l_1048[3], (safe_lshift_func_uint16_t_u_s(p_9, 5)))) == 1L);
                g_22 = (((safe_lshift_func_uint16_t_u_u(((((g_173 == (safe_add_func_int8_t_s_s(0x85L, (g_866[4][0] & g_813[1][0])))) < (l_1044 == (safe_mod_func_int16_t_s_s(0x3447L, ((safe_mod_func_int16_t_s_s((((!(safe_lshift_func_int16_t_s_u(((((safe_sub_func_int16_t_s_s((safe_mod_func_int32_t_s_s(((safe_lshift_func_uint8_t_u_u((safe_mod_func_int32_t_s_s((safe_lshift_func_int8_t_s_s(((safe_add_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(p_9, g_173)), p_9)) ^ l_975[0][0]), g_103)), g_543[1])), p_9)) && l_1000[1][6]), 0x2EBCD1D0L)), l_1077)) == p_9) | l_975[0][0]) || l_1078), p_9))) != g_172[2]) < 3UL), p_9)) && g_541))))) != p_9) != g_813[1][0]), 13)) != g_103) && l_28);
                g_22 = (!(0x4D452E28L | (-10L)));
            }
            else
            {
                int8_t l_1088 = 0x48L;
                int32_t l_1123 = 1L;
                int8_t l_1128 = 0x8FL;
                int32_t l_1130 = 0L;
                uint16_t l_1155 = 65535UL;
                int32_t l_1156 = (-1L);
                if ((((g_63 = (g_172[4] = (2UL ^ ((l_982 = 0xCC4D0FF6L) != ((g_974 && (0x2DL < ((safe_mod_func_int8_t_s_s((safe_add_func_uint8_t_u_u(g_543[1], g_866[4][0])), (0xAE74A061L ^ ((safe_rshift_func_int16_t_s_u((safe_add_func_int8_t_s_s(l_1088, 0x82L)), 8)) <= 7L)))) != 7L))) > l_1088))))) & p_9) > g_974))
                {
                    uint32_t l_1106 = 0xA3E081EAL;
                    int32_t l_1108 = 0xB45B4023L;
                    int32_t l_1109 = 0L;
                    int32_t l_1115 = (-1L);
                    l_1109 = ((0xA991L ^ (safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((p_9 != g_172[6]), (((safe_add_func_uint32_t_u_u((((((((l_1108 = (g_172[4] != (safe_lshift_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u(((((p_9 || (safe_add_func_uint32_t_u_u(g_12, p_9))) && (+((l_1107 = (safe_mod_func_uint8_t_u_u((((((safe_rshift_func_uint16_t_u_s(65535UL, p_9)) >= g_813[1][0]) == 0xF230L) ^ l_1106) || 0xC3E97BBAL), g_361))) && l_1044))) | p_9) || 0x739D4E79L), g_541)), 12)))) ^ 0x430FL) == 0L) | p_9) == 4L) > 251UL) && 0x54700F55L), 1UL)) | l_1044) < 4294967286UL))), l_1106))) > p_9);
                    g_247 = (0xFAL == (safe_add_func_uint8_t_u_u(1UL, (~(safe_add_func_int16_t_s_s(p_9, ((l_1115 = l_1077) >= (l_1044 = (0L >= ((l_1001 | ((l_1109 = g_974) | (safe_unary_minus_func_int16_t_s((p_9 | ((safe_add_func_uint32_t_u_u(g_361, 0x6120F022L)) >= p_9)))))) == 0UL))))))))));
                    g_247 = ((safe_add_func_int32_t_s_s(p_9, (l_1123 = (safe_lshift_func_int16_t_s_u(g_949[0][6][1], 10))))) != (l_1000[1][6] = ((1UL & (l_987 = (((p_9 || (0L <= (l_1131 = (l_1130 = (((safe_sub_func_int32_t_s_s(g_813[3][0], ((g_1129 = ((((safe_add_func_int8_t_s_s((l_1044 = ((((((0x465FL >= (g_315 ^ (((p_9 & p_9) != g_974) < p_9))) > l_987) | l_21) && l_1128) | 0xEB927AC1L) & g_22)), p_9)) > 0x9521L) ^ g_247) < g_949[0][6][1])) | l_975[1][0]))) <= g_83) | 0x0D803776L))))) <= l_1088) || 1UL))) | g_22)));
                }
                else
                {
                    int8_t l_1144 = (-6L);
                    int32_t l_1154 = 0x21380E4FL;
                    if (g_813[6][0])
                    {

g_974 += 1;


                    return g_949[1][4][6];
                    }
                    else
                    {
                        uint32_t l_1143 = 0x014BF0E5L;
                        l_1123 = (((safe_mod_func_uint8_t_u_u((safe_add_func_int8_t_s_s((l_987 >= ((l_26 = ((~(g_172[1] >= (l_1143 = ((g_22 & 0xDCL) == (((0L < g_103) | ((p_9 || p_9) ^ ((safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((g_974 | g_359[6][2]), g_813[1][0])), g_172[5])), 1UL)) == 0x6786L))) == p_9))))) ^ p_9)) != l_1144)), 0L)), l_1144)) || 0x11CFL) && p_9);
                        l_1145[2] = (-1L);
                        l_1130 = (0UL ^ ((safe_lshift_func_uint8_t_u_u((g_217 = (((safe_add_func_uint32_t_u_u(((0x27L == ((((l_1000[1][6] = p_9) > (((((g_188 > (g_949[0][6][1] || (+(g_247 = ((((p_9 <= ((l_1154 = ((((0x36L != g_63) && (safe_add_func_uint8_t_u_u(((g_173 < (-9L)) && g_359[9][0]), l_1123))) <= l_1153) > 0x0CA7DFD0L)) > 251UL)) | l_1130) && p_9) || g_541))))) == p_9) && (-1L)) || l_1153) <= 8UL)) <= g_188) | 65531UL)) != g_359[1][2]), l_1088)) >= p_9) || g_813[4][0])), 5)) == l_1155));
                        g_22 = ((((g_161 = g_217) & l_1156) || g_540) < l_1145[2]);
                    }
                }

g_173 += 1;


                    g_22 = ((safe_add_func_uint16_t_u_u(((g_543[1] = ((l_1000[1][6] = g_361) <= ((+((safe_sub_func_uint32_t_u_u(((((safe_sub_func_uint32_t_u_u((g_949[0][6][1] > ((safe_unary_minus_func_uint32_t_u(p_9)) < ((((((((safe_sub_func_uint32_t_u_u((g_115 >= (l_987 > g_4)), l_982)) < ((safe_mod_func_uint8_t_u_u(((g_172[7] || (((safe_sub_func_uint32_t_u_u((l_975[2][0] = (safe_sub_func_int8_t_s_s((l_1179 = (l_27 = ((safe_unary_minus_func_int16_t_s(((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u(((~((p_9 == 0x622C1845L) != g_315)) > g_63), p_9)), g_543[1])) & p_9))) | p_9))), g_359[2][4]))), l_1001)) != p_9) | 0x60L)) >= l_1180), l_1153)) || 0xB777L)) <= g_361) | p_9) <= p_9) | l_987) ^ 251UL) != 0UL))), 0L)) != l_1128) ^ l_987) == g_543[1]), 0L)) == p_9)) <= 1UL))) <= l_987), 0UL)) || p_9);
                for (g_315 = 0; (g_315 == 37); g_315 = safe_add_func_int8_t_s_s(g_315, 1))
                {
                    int16_t l_1184[7][10] = {{0x0584L,0xF49AL,0x0584L,0x1CAEL,0x1CAEL,(-9L),0x691FL,(-9L),0x0584L,0x0584L},{(-9L),0x691FL,(-9L),0x0584L,0x0584L,(-9L),0x691FL,(-9L),0x0584L,0x0584L},{(-9L),0x691FL,(-9L),0x0584L,0x0584L,(-9L),0x691FL,(-9L),0x0584L,0x0584L},{(-9L),0x691FL,(-9L),0x0584L,0x0584L,(-9L),0x691FL,(-9L),0x0584L,0x0584L},{(-9L),0x691FL,(-9L),0x0584L,0x0584L,(-9L),0x691FL,(-9L),0x0584L,0x0584L},{(-9L),0x691FL,(-9L),0x0584L,0x0584L,(-9L),0x691FL,(-9L),0x0584L,0x0584L},{(-9L),0x691FL,(-9L),0x0584L,0x0584L,(-9L),0x691FL,(-9L),0x0584L,0x0584L}};
                    int i, j;
                    l_1000[1][6] = (((!l_1184[5][5]) == ((g_83 = g_866[4][0]) | (~250UL))) && ((g_949[0][6][1] >= ((p_9 > ((safe_add_func_uint32_t_u_u((l_1145[3] & p_9), ((safe_unary_minus_func_int32_t_s((safe_add_func_uint8_t_u_u((g_12 = (l_1044 = l_1107)), (0x10F80FA5L || l_1131))))) == l_1130))) > p_9)) ^ p_9)) != g_172[4]));
                }
            }
        }
        else
        {
            uint32_t l_1210 = 0xFBD33136L;
            int32_t l_1257 = 0x65E6AA61L;
            int32_t l_1272 = 0L;
            int16_t l_1321[1][8] = {{(-8L),(-1L),(-1L),(-8L),(-1L),(-1L),(-8L),(-1L)}};
            int i, j;
            if ((((safe_add_func_int32_t_s_s((((((safe_add_func_int32_t_s_s(((safe_mod_func_uint16_t_u_u(((0x0040L | (0xD223L == (safe_sub_func_int16_t_s_s(((safe_rshift_func_int8_t_s_u((g_1215[4] = (safe_mod_func_uint8_t_u_u(0x22L, ((+p_9) ^ (safe_add_func_int16_t_s_s(l_1077, (((((safe_add_func_uint32_t_u_u((l_27 <= l_1210), 1UL)) || ((safe_mod_func_uint32_t_u_u(((safe_add_func_uint32_t_u_u(p_9, 0x09BF8AFEL)) & 0x4FA669B5L), 1UL)) >= 0x1FEBB9BDL)) > l_1179) && g_172[8]) & 4294967287UL))))))), 0)) > g_813[5][0]), p_9)))) == 0x5F3FL), p_9)) != p_9), g_866[4][9])) < 65535UL) == l_28) || g_949[0][6][8]) == l_1210), 0x7086C046L)) <= l_1210) >= 0x9DL))
            {
                uint16_t l_1250 = 0x9105L;
                int32_t l_1254 = 0x0F0B4864L;
                int32_t l_1255 = (-1L);
                uint32_t l_1256 = 0x971EA8C0L;
                uint16_t l_1268 = 65531UL;
                for (g_83 = 6; (g_83 >= 0); g_83 -= 1)
                {
                    uint16_t l_1253 = 0UL;
                    int32_t l_1273 = (-2L);
                    int32_t l_1289 = 0xC89C5942L;
                    int32_t l_1302 = (-10L);
                    for (g_173 = 0; (g_173 <= 6); g_173 += 1)
                    {
                        int32_t l_1269 = 1L;
                        int8_t l_1270 = 0xE8L;
                        int i, j;
                        l_1257 = ((((0xD12A6F93L ^ (safe_rshift_func_int8_t_s_s((safe_sub_func_int8_t_s_s(0xCBL, (safe_add_func_uint8_t_u_u(((safe_sub_func_int32_t_s_s(((((safe_sub_func_int32_t_s_s((((~((~(safe_lshift_func_uint8_t_u_u((g_359[(g_83 + 3)][g_173] & (((safe_mod_func_uint8_t_u_u(p_9, (safe_lshift_func_uint8_t_u_u(p_9, 0)))) != ((safe_sub_func_int32_t_s_s((((safe_lshift_func_uint16_t_u_s(l_987, (safe_rshift_func_int16_t_s_s((((g_540 = ((safe_rshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(0L, (safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s(l_1250, (l_1254 = (safe_add_func_uint32_t_u_u((p_9 == p_9), l_1253))))), 4294967295UL)))), l_1255)), 0)) == p_9)) && p_9) != 9UL), 1)))) & g_813[1][0]) | p_9), p_9)) & 0x62L)) & l_975[2][0])), p_9))) | 0xCD8BL)) >= g_173) & g_172[8]), l_1250)) & g_173) && g_359[(g_83 + 3)][g_83]) < p_9), l_1253)) == g_103), l_1256)))), l_1001))) < g_1215[5]) & p_9) >= 0xB0L);
                        l_1273 = ((((!((l_1272 = (g_1129 = (((((safe_lshift_func_int8_t_s_u(p_9, 4)) | g_161) < (l_1257 = ((((safe_sub_func_uint16_t_u_u((g_540 && (l_1269 = (safe_sub_func_uint16_t_u_u(((((+g_540) < g_1129) == ((safe_mod_func_int16_t_s_s((l_26 = g_217), ((0xA9L < ((-5L) || (g_315 > g_217))) | g_1129))) != 0x7EL)) > l_1268), p_9)))), g_866[4][3])) <= 0x15L) == 0x3FL) != l_982))) & l_1270) ^ l_1271))) < g_63)) <= g_217) != g_359[(g_83 + 3)][g_173]) && g_173);
                        g_247 = (g_161 < p_9);
                    }
                    l_1289 = (safe_add_func_int32_t_s_s(l_1153, (0x5AL < ((safe_sub_func_uint8_t_u_u((g_173 = (l_975[0][0] = (safe_add_func_int32_t_s_s((((((g_63 <= ((((0x583DL || (l_975[1][0] < (safe_mod_func_uint16_t_u_u(g_866[4][0], g_949[2][8][0])))) & (safe_rshift_func_int8_t_s_s(((l_987 = p_9) > ((((((safe_mod_func_int32_t_s_s((l_1273 = ((safe_rshift_func_uint8_t_u_s(l_1254, 3)) > g_866[6][4])), l_1253)) != l_975[0][0]) == 0xCF9AL) ^ l_1253) != g_247) > p_9)), 7))) <= p_9) != p_9)) ^ l_1257) <= g_866[7][6]) ^ 0L) | g_359[7][6]), l_1288)))), g_949[0][6][1])) | 0x1EL))));
                    for (l_1289 = 0; (l_1289 <= 0); l_1289 += 1)
                    {
                        int i, j;
                        l_1255 = ((l_975[(l_1289 + 2)][l_1289] == (-1L)) < l_1077);
                        l_1273 = (g_1129 | (!((((((safe_sub_func_uint8_t_u_u((l_1272 == (((safe_rshift_func_int8_t_s_s(((l_1257 | ((safe_sub_func_int8_t_s_s(p_9, l_1273)) | ((g_538 = (safe_sub_func_uint16_t_u_u((((+((g_543[1] | ((((l_27 = (0x796B303EL == (safe_mod_func_uint8_t_u_u((l_1302 ^ (safe_sub_func_int32_t_s_s(l_26, 0x7FEAD647L))), p_9)))) & g_361) & l_1302) | 1L)) >= p_9)) && 0L) & g_949[0][6][1]), g_83))) && l_1210))) ^ 0x36C9L), l_1255)) <= l_1289) && g_1215[4])), g_161)) > l_1254) <= (-1L)) <= p_9) == 2L) || p_9)));
                        if (l_1273)
                            {
if (g_2352[2])
                            break;


for (l_1179 = 0; l_1179 < 9; l_1179 += 1)
                {
                    for (l_1434 = 0; l_1434 < 9; l_1434 += 1)
                    {
                        g_949[g_538][l_1179][l_1434] = 0L;
                    }
                };


                    continue;}
                        g_247 = (-1L);
                    }
                }
            }
            else
            {
                uint8_t l_1330 = 247UL;
                l_27 = (safe_sub_func_uint16_t_u_u(l_982, (+(((safe_sub_func_int8_t_s_s((~(p_9 > ((safe_rshift_func_uint8_t_u_u((~9L), (g_540 | (safe_rshift_func_uint16_t_u_u(g_813[0][0], ((0x749DL < 6L) & (0x15L == (safe_mod_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u((l_26 = 1L), p_9)), p_9))))))))) == 4L))), (-1L))) > l_1320) & l_1321[0][7]))));

{
        for (l_1836 = 0; l_1836 < 9; l_1836++)
        {
            for (g_115 = 0; g_115 < 9; g_115++)
            {
                transparent_crc(g_949[l_1179][l_1836][g_115], "g_949[l_1179][l_1836][g_115]", l_1272);
                if (l_1272) printf("index = [%d][%d][%d]\n", l_1179, l_1836, g_115);

            }
        }
    }

                    l_982 = (g_83 && (safe_lshift_func_uint16_t_u_u(g_172[4], 1)));
                for (l_982 = (-30); (l_982 != (-28)); l_982++)
                {
                    int8_t l_1341 = (-1L);
                    for (p_9 = 20; (p_9 == (-1)); --p_9)
                    {
                        int8_t l_1364 = 0x68L;

l_1288 += 1;


                    g_22 = (safe_sub_func_int8_t_s_s((l_1330 > (0xC9DEA68FL <= ((l_27 = ((safe_sub_func_uint16_t_u_u((g_63 = (0L ^ 0xB73CL)), ((safe_sub_func_uint32_t_u_u((safe_lshift_func_int8_t_s_u((-10L), g_217)), ((p_9 & (safe_sub_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u(p_9, (l_1341 <= l_1180))) ^ 0L), 0xD8L))) || (-4L)))) || l_26))) && 0xDF7FDABDL)) <= l_1288))), p_9));
                        g_247 = ((((safe_unary_minus_func_uint16_t_u((safe_add_func_int16_t_s_s(((safe_sub_func_int32_t_s_s((((safe_sub_func_int32_t_s_s(((0UL && (((((safe_add_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(p_9, (safe_mod_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_s((safe_mod_func_int16_t_s_s((0L <= l_1359[3]), ((((safe_sub_func_int32_t_s_s((safe_add_func_int32_t_s_s(l_1364, p_9)), (g_161 = p_9))) | g_359[2][5]) & g_247) | g_866[7][4]))), 2)) || l_1288) > 0xDC14L), g_949[0][6][1])))), 1L)) <= 6L) != 0xC828L) < g_543[2]) & p_9)) <= p_9), 1L)) && (-4L)) & l_1364), g_541)) <= 0x36L), g_540)))) | p_9) == p_9) <= (-1L));
                    }
                }
            }
            l_1000[1][6] = (-3L);
            l_1272 = ((((safe_lshift_func_int8_t_s_u((l_987 = (((safe_add_func_uint32_t_u_u((l_982 = (((safe_add_func_int8_t_s_s((l_1377 = ((~(safe_rshift_func_uint16_t_u_s(g_12, 13))) == (((l_1374[3] = ((p_9 ^ l_987) == 0x9272L)) > (g_161 = 0xCC5192BAL)) <= (safe_lshift_func_uint8_t_u_s((0xABL || g_949[0][6][1]), 1))))), l_1271)) <= (((safe_rshift_func_int8_t_s_s(0L, p_9)) | 7UL) <= 0x36749FCCL)) < p_9)), (-3L))) == 4294967295UL) == l_1153)), 1)) | g_538) <= g_188) != p_9);
            for (g_161 = (-25); (g_161 >= 1); g_161++)
            {
                l_975[2][0] = p_9;
            }
        }
                                            while ((!l_982) )
{

{
                l_975[2][0] = g_974;
            }

}
                    g_22 = (l_982 = (l_982 < (p_9 = p_9)));
        for (l_1288 = 0; (l_1288 <= 49); l_1288 = safe_add_func_uint32_t_u_u(l_1288, 8))
        {
            int32_t l_1386[8][6][5] = {{{1L,0x13047496L,0x24F15A40L,0x76EFD044L,(-1L)},{0xC87EA5D2L,1L,6L,1L,1L},{0xEAC19E7DL,0x0785FA11L,0x3A6D85AFL,0x76EFD044L,1L},{(-1L),0xA2352078L,0xF0E7E3B8L,0L,0x01E0BE68L},{(-1L),0L,(-1L),0xA2352078L,7L},{0xEAC19E7DL,(-1L),(-2L),0x13047496L,(-9L)}},{{0xC87EA5D2L,0x76EFD044L,(-1L),0xE426A69DL,0x45517AFBL},{1L,0L,0xF0E7E3B8L,0L,0x45517AFBL},{(-1L),(-1L),0x3A6D85AFL,(-2L),(-9L)},{0x80DF98E5L,(-2L),6L,(-10L),7L},{1L,(-1L),0x24F15A40L,0x711F5BC4L,0x01E0BE68L},{(-9L),0L,0x14DE518BL,0x711F5BC4L,1L}},{{0x3AC73DA6L,0x76EFD044L,0x16D10BE2L,(-10L),1L},{(-6L),(-1L),0L,(-2L),(-1L)},{0x3AC73DA6L,0L,0x5927EACFL,0L,0x3AC73DA6L},{(-9L),0xA2352078L,0x5927EACFL,0xE426A69DL,1L},{1L,0x0785FA11L,0L,0x13047496L,0x80DF98E5L},{0x80DF98E5L,1L,0x16D10BE2L,0xA2352078L,1L}},{{(-1L),0x13047496L,0x14DE518BL,0L,0x3AC73DA6L},{1L,0x13047496L,0x24F15A40L,0x76EFD044L,(-1L)},{0xC87EA5D2L,1L,6L,1L,1L},{0xEAC19E7DL,0x0785FA11L,0x3A6D85AFL,0x76EFD044L,1L},{(-1L),0xA2352078L,0xF0E7E3B8L,0L,0x01E0BE68L},{(-1L),0L,(-1L),0x4CDAA604L,0x711F5BC4L}},{{0L,(-9L),0xA35F3599L,0x98FFAF84L,0x76EFD044L},{(-1L),(-3L),0x2666F0A9L,0x60350416L,1L},{(-9L),0L,0xBFC10485L,0L,1L},{0x0785FA11L,(-5L),0L,(-7L),0x76EFD044L},{0xD3F429C3L,(-7L),(-1L),0xB8E2DB93L,0x711F5BC4L},{0xE426A69DL,(-5L),0L,1L,(-2L)}},{{0x76EFD044L,0L,0x588ED3D3L,1L,1L},{0L,(-3L),0xA114170AL,0xB8E2DB93L,0xFB7B8D50L},{0x13047496L,(-9L),1L,(-7L),0x0785FA11L},{0L,0L,1L,0L,0L},{0x76EFD044L,0x4CDAA604L,1L,0x60350416L,(-9L)},{0xE426A69DL,0xF67F32CFL,1L,0x98FFAF84L,0xD3F429C3L}},{{0xD3F429C3L,(-4L),0xA114170AL,0x4CDAA604L,(-9L)},{0x0785FA11L,0x98FFAF84L,0x588ED3D3L,0x48E7C1F4L,0L},{(-9L),0x98FFAF84L,0L,(-3L),0x0785FA11L},{(-1L),(-4L),(-1L),(-1L),0xFB7B8D50L},{0L,0xF67F32CFL,0L,(-3L),1L},{0x115294F3L,0x4CDAA604L,0xBFC10485L,0x48E7C1F4L,(-2L)}},{{0x115294F3L,0L,0x2666F0A9L,0x4CDAA604L,0x711F5BC4L},{0L,(-9L),0xA35F3599L,0x98FFAF84L,0x76EFD044L},{(-1L),(-3L),0x2666F0A9L,0x60350416L,1L},{(-9L),0L,0xBFC10485L,0L,1L},{0x0785FA11L,(-5L),0L,(-7L),0x76EFD044L},{0xD3F429C3L,(-7L),(-1L),0xB8E2DB93L,0x711F5BC4L}}};
            uint16_t l_1401 = 2UL;
            int32_t l_1426 = (-10L);
            uint8_t l_1449 = 0xD0L;
            int32_t l_1456 = 1L;
            int16_t l_1467 = 0x2779L;
            int i, j, k;
            if (((safe_sub_func_int16_t_s_s(l_1386[7][1][4], (safe_unary_minus_func_uint32_t_u((safe_lshift_func_int8_t_s_u((safe_mod_func_int32_t_s_s((+(l_1386[7][1][4] <= (1L < (p_9 == (safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_u(g_949[2][4][6], ((((((safe_rshift_func_uint16_t_u_u((g_813[3][0] | (safe_lshift_func_uint8_t_u_u((7L != (p_9 || (p_9 != l_1000[2][6]))), l_1000[0][6]))), 14)) <= 1L) > 6UL) <= l_1401) > l_1288) <= 0L))) ^ p_9), 9L)))))), l_1077)), 6)))))) ^ p_9))
            {
                uint32_t l_1423 = 0xE576516EL;
                int32_t l_1424 = 0x76D7F62DL;
                int32_t l_1431 = 0x4C9012BCL;
                int32_t l_1432 = (-8L);
                uint8_t l_1527 = 6UL;
                if ((safe_lshift_func_int8_t_s_u((p_9 && 0xDCE4L), (safe_lshift_func_int8_t_s_u(((l_1424 = (safe_sub_func_uint16_t_u_u((g_315 = (l_27 < (((((((g_63 = (!(safe_lshift_func_int8_t_s_s((!((safe_add_func_int8_t_s_s((l_1386[6][5][0] > 0xB5EEL), p_9)) || (p_9 && (0xDC53108EL > (safe_unary_minus_func_int16_t_s((((safe_rshift_func_uint16_t_u_s((l_1179 = (safe_mod_func_int32_t_s_s(((safe_add_func_uint16_t_u_u((0x6B50CB0AL | p_9), g_4)) < 0x1DL), 0xBC2AB98CL))), 9)) == 0x0979578BL) == g_543[0]))))))), l_1359[3])))) == l_1001) == 0UL) && (-10L)) || l_1423) ^ 1UL) < 0xE469L))), g_103))) ^ 0xAFL), 2)))))
                {
                    uint16_t l_1425 = 0x3E3BL;
                    if (p_9)
                    {
                        int32_t l_1429 = 0x011288BAL;
                        int32_t l_1433 = 0x32668139L;
                        l_1425 = p_9;
                        l_1426 = ((l_1000[1][6] = g_115) <= 0x6EL);
                        l_1433 = ((safe_rshift_func_int8_t_s_u(g_217, 5)) & (((l_1424 = l_1429) == (((~0xEE002086L) & (l_1431 = ((g_63 = 2UL) > (0x60L > 0UL)))) < (0xF6L || (g_83 = g_543[2])))) == (l_1432 = ((g_866[7][4] = (-10L)) != 0x26A5L))));
                    }
                    else
                    {
                        int16_t l_1435 = 0x2B29L;
                        l_1434 = 0x50E79F57L;
                        l_1435 = g_949[2][3][1];

{
            for (l_26 = 0; l_26 < 9; l_26++)
            {
                transparent_crc(g_949[l_27][l_1450][l_26], "g_949[l_27][l_1450][l_26]", l_1431);
                if (l_1431) printf("index = [%d][%d][%d]\n", l_27, l_1450, l_26);

            }
        }

                    l_1426 = (p_9 && (safe_rshift_func_int16_t_s_s(l_1425, 10)));
                        return g_12;
                    }
                    l_975[2][0] = (g_173 ^ (safe_add_func_uint16_t_u_u((l_1423 | ((p_9 == p_9) || ((((safe_mod_func_int32_t_s_s(((l_1426 = (safe_mod_func_uint8_t_u_u(1UL, p_9))) & (g_63 = ((l_26 = p_9) ^ (~((safe_lshift_func_uint16_t_u_u((l_1450 = ((safe_sub_func_uint16_t_u_u(g_541, (g_172[4] = ((l_1449 != l_1001) || p_9)))) > g_541)), 4)) < p_9))))), l_1425)) || 0UL) | 8L) >= p_9))), 1UL)));
                }
                else
                {
                    int32_t l_1452 = 0xCF7B80C9L;
                    int32_t l_1459[1];
                    int i;
                    for (i = 0; i < 1; i++)
                        l_1459[i] = 0xA041CE44L;
                    l_1426 = (+g_173);
                    l_987 = (-3L);
                                                   int16_t Bogoggl_2163 = (~(((~((~((~(l_1452)))))) ^ ((~((~((l_1633 | (g_1460 ^ (~(l_1434)))))))) ^ (~((g_63 % ((~((((~(g_247)) ^ (~(l_2163))) + (g_1129 & g_540)))) | (~(l_1456))))))))));
uint8_t Bogoghg_1460 = (~(((~((~(g_247)))) | (~(((~((((~((~(g_63)))) & (Bogoggl_2163 & g_540)) >> (~((~((l_1434 & (l_1452 & g_1129))))))))) << (l_1633 & (g_1460 % (~((l_1456 ^ l_2163)))))))))));
int32_t Bogogig_247 = (~((((g_1129 + (~(g_247))) % ((~((~((~(l_1456)))))) - (((~(Bogoggl_2163)) & l_1633) & (~(l_1434))))) + ((~(((l_1452 | g_63) & (~(l_2163))))) - ((g_540 ^ (~(Bogoghg_1460))) % (~(g_1460)))))));
uint32_t Bogogjg_540 = (~((((~((l_2163 - (~((Bogoghg_1460 | ((~(Bogogig_247)) + (~(l_1456))))))))) | (~(((l_1633 | g_1129) - (g_63 | g_540))))) ^ (~((~((~((((~(Bogoggl_2163)) % l_1434) & ((~((l_1452 - (~(g_247))))) + g_1460)))))))))));
int32_t Bogogkl_1452 = (~((Bogoggl_2163 - (((g_63 - (~(g_247))) ^ (g_1129 + (~(l_1633)))) & ((((Bogogig_247 | l_1434) ^ l_1456) + Bogoghg_1460) - (((~((g_540 % l_1452))) ^ Bogogjg_540) - (~((l_2163 + g_1460)))))))));
uint16_t Bogoglg_63 = (~(((~((~(l_1434)))) - ((~(((~(g_247)) ^ (~(Bogogkl_1452))))) ^ (~((~((~(((((g_540 ^ l_2163) - (Bogoggl_2163 + (~((Bogoghg_1460 << l_1456))))) - ((~(((~(l_1452)) % (~((~(g_1129))))))) - ((g_63 + l_1633) ^ (~(Bogogig_247))))) ^ (~((Bogogjg_540 ^ g_1460))))))))))))));
if(Bogoggl_2163){
Bogoggl_2163 = l_2163;
Bogoghg_1460 = g_1460;
Bogogig_247 = g_247;
Bogogjg_540 = g_540;
Bogogkl_1452 = l_1452;
Bogoglg_63 = g_63;
l_2163 = (~(((((~((~(g_540)))) + Bogoghg_1460) % (~(((((((~((Bogogkl_1452 - Bogoggl_2163))) + l_1456) | g_1129) | (((g_63 % (~(g_1460))) | l_1633) ^ ((l_1452 | l_1434) & (~(g_247))))) & (~((~(Bogogig_247))))) & Bogoglg_63)))) - (~(((~((~(l_2163)))) ^ (~((~(Bogogjg_540))))))))));
g_1460 = (~(((~(((((~(Bogogjg_540)) % (~(l_1434))) | (((~(l_1456)) | g_1129) - (l_1452 + (~((Bogoglg_63 | Bogoggl_2163)))))) ^ (~(g_63))))) - (~(((~(((~((~(((g_247 + l_1633) + (~((~(Bogoghg_1460))))))))) | (l_2163 | Bogogig_247)))) - ((~((~(((~(g_540)) & Bogogkl_1452))))) ^ (~(g_1460)))))))));
                               uint32_t BGgGgl_1423 = (~(((((~((g_173 << l_1434))) && g_1129) || ((g_974 | l_26) - (l_1401 & (l_1631 ^ l_1467)))) || (~((l_1423 << l_1424))))));
int8_t BGgGgbl_1434 = (~((((((~((g_1129 && BGgGgl_1423))) + l_26) + l_1434) || (l_1423 ^ (~(g_974)))) + (~((((l_1631 || (~((l_1401 ^ l_1467)))) && g_173) + l_1424))))));
int32_t BGgGgcl_26 = (~(((~(((~(((g_974 && g_1129) << ((~(BGgGgbl_1434)) && l_26)))) | (~(l_1423))))) && ((((l_1401 + (g_173 >> l_1434)) || l_1467) + l_1424) << (BGgGgl_1423 / l_1631)))));
int16_t BGgGgdg_974 = (~(((~(((~(g_173)) % (~((g_974 % l_1467)))))) + (((l_1631 || (BGgGgbl_1434 + l_1401)) || ((~(l_1423)) ^ (~(((BGgGgcl_26 || BGgGgl_1423) || l_26))))) ^ ((l_1424 << l_1434) | g_1129)))));
uint8_t BGgGgeg_1129 = (~(((~(((~((g_173 - (~((~((g_1129 | BGgGgl_1423)))))))) - (((l_1423 & (l_1401 && BGgGgdg_974)) + (((l_1434 + BGgGgbl_1434) | (~(l_26))) + (~(BGgGgcl_26)))) + l_1424)))) + (~((~(((l_1631 - l_1467) + g_974))))))));
uint16_t BGgGgfl_1401 = (~(((((~(g_173)) && ((~((l_1631 && BGgGgl_1423))) % (~(l_26)))) + (BGgGgcl_26 % (~((l_1434 / g_1129))))) || (((g_974 & l_1423) % l_1401) && (~(((BGgGgdg_974 - (BGgGgbl_1434 && l_1424)) && ((~(BGgGgeg_1129)) + (~(l_1467))))))))));
if((!((!g_974)) && (g_974<=3))){
BGgGgl_1423 = l_1423;
BGgGgbl_1434 = l_1434;
BGgGgcl_26 = l_26;
BGgGgdg_974 = g_974;
BGgGgeg_1129 = g_1129;
BGgGgfl_1401 = l_1401;
l_1423 = (~(((~((~((~((((~(BGgGgfl_1401)) % (~(l_1434))) + l_1424))))))) / (~((((BGgGgcl_26 && l_1423) >> (~((~(g_173))))) & (((((BGgGgl_1423 && BGgGgbl_1434) + (~(l_1401))) - BGgGgeg_1129) ^ ((BGgGgdg_974 - l_26) - g_1129)) || (l_1467 % (g_974 | l_1631)))))))));
l_1434 = (~((((~(((~((l_1467 & BGgGgl_1423))) || (~(((~(((l_1401 && (BGgGgbl_1434 | l_1434)) - (~(g_173))))) & (BGgGgcl_26 | l_1424))))))) % (((~((BGgGgfl_1401 | g_1129))) + (((~(g_974)) & l_1631) - BGgGgdg_974)) + (~(((~(l_26)) - l_1423))))) - (~(BGgGgeg_1129)))));
l_26 = (~(((~((l_1631 & (((~(l_1423)) - ((l_1424 + l_26) ^ BGgGgeg_1129)) & ((BGgGgfl_1401 >> l_1401) / l_1467))))) / (~((~((((BGgGgbl_1434 % BGgGgl_1423) - (~(((l_1434 | g_173) + (~((~(g_974)))))))) >> (~((~((~(((~(BGgGgcl_26)) ^ (g_1129 % BGgGgdg_974))))))))))))))));
g_974 = (~(((~(l_1423)) ^ (((~((l_1401 & ((g_974 && (~(l_1467))) - (BGgGgl_1423 % BGgGgeg_1129))))) & ((BGgGgbl_1434 || g_1129) << (l_26 / BGgGgdg_974))) - ((l_1424 && g_173) || (l_1631 % (~((~(((BGgGgfl_1401 | BGgGgcl_26) + (~(l_1434)))))))))))));
g_1129 = (~(((~((~((~((((~((~(l_1467)))) & ((l_1401 && ((l_1423 % l_1631) | (BGgGgcl_26 % (~(BGgGgdg_974))))) - (~(l_1424)))) / (~((~((~(g_974))))))))))))) / ((((~(l_1434)) & ((~(BGgGgeg_1129)) | BGgGgfl_1401)) - (((~(BGgGgbl_1434)) && g_173) % (l_26 | (~(g_1129))))) % (~((~((~((~((~(BGgGgl_1423))))))))))))));
l_1401 = (~(((((((~(l_1631)) || g_173) || BGgGgl_1423) - (~((l_1401 || l_1434)))) ^ BGgGgeg_1129) / ((~((~((BGgGgbl_1434 & l_1423))))) - ((((g_1129 - BGgGgdg_974) & (l_1467 % (~(l_26)))) && (g_974 || l_1424)) % (~((BGgGgfl_1401 & BGgGgcl_26))))))));
if((!BGgGgbl_1434)){
printf("l_1423=%llu\n", (unsigned long long)l_1423);
continue;
}
if((g_974 < l_1434)){
printf("l_1434=%lld\n", (long long)l_1434);
BGgGgdg_974 = (~(((~(l_1401)) && (((l_1434 << (~(g_974))) | ((~((~((~((BGgGgbl_1434 ^ l_1467))))))) % ((~((~((~((~(l_1423)))))))) & ((l_1424 >> BGgGgcl_26) && (~(g_173)))))) + ((~((~((~((l_1631 + BGgGgl_1423))))))) || ((~(g_1129)) % (~(((l_26 | BGgGgdg_974) | (BGgGgfl_1401 + BGgGgeg_1129))))))))));
BGgGgl_1423 = (~(((((~((~(BGgGgfl_1401)))) | (~(g_974))) << ((~((~(((~(BGgGgbl_1434)) / ((~(l_1401)) >> (~((((~(l_1434)) + (BGgGgcl_26 % g_173)) - (~((~((~(g_1129))))))))))))))) | ((BGgGgl_1423 | (~(l_1467))) || (l_1631 ^ (~(l_1424)))))) / (~((~(((l_26 + (l_1423 & (~(BGgGgdg_974)))) / BGgGgeg_1129))))))));
}
if((BGgGgdg_974>3)){
printf("l_26=%lld\n", (long long)l_26);
l_26 = (~(((~(((BGgGgdg_974 | (~((~((BGgGgl_1423 && g_1129)))))) - ((~((~(((~((l_26 | l_1424))) | (~(g_974))))))) / ((~(g_173)) || (BGgGgcl_26 % ((l_1467 / (l_1401 + (BGgGgfl_1401 - l_1434))) % (~((l_1631 / BGgGgbl_1434)))))))))) % ((~((~(l_1423)))) | (~((~(BGgGgeg_1129))))))));
continue;
}
if((!BGgGgfl_1401)){
printf("g_974=%lld\n", (long long)g_974);
goto LABEL_ogogm;
}
if((!l_1401)){
printf("g_1129=%llu\n", (unsigned long long)g_1129);
continue;
}
}
l_1423 = BGgGgl_1423;
l_1434 = BGgGgbl_1434;
l_26 = BGgGgcl_26;
g_974 = BGgGgdg_974;
g_1129 = BGgGgeg_1129;
l_1401 = BGgGgfl_1401;

                    g_247 = (~((((~((~(g_540)))) + (~((~((~((l_1434 ^ g_247)))))))) % ((~(((((~(l_2163)) % (~((Bogoghg_1460 - ((Bogogkl_1452 ^ g_1129) ^ (l_1452 + Bogogjg_540)))))) - (Bogoggl_2163 & Bogoglg_63)) | (~(l_1633))))) - (~((~((~(((Bogogig_247 - l_1456) + ((~(g_1460)) % g_63))))))))))));
g_540 = (~(((((((~(Bogogjg_540)) & Bogoglg_63) ^ g_1460) & ((((l_1633 - (~(Bogoggl_2163))) % (~(l_2163))) | (l_1452 % g_1129)) % (~(Bogogig_247)))) >> (~((~(((l_1456 ^ (Bogogkl_1452 + (Bogoghg_1460 % g_247))) % (l_1434 | g_63))))))) | (~(g_540)))));
l_1452 = (~(((~((~((((~(((~(Bogogkl_1452)) - g_247))) | (~((Bogoghg_1460 + l_1434)))) + (g_540 + (l_1456 & Bogogjg_540))))))) % ((((~((g_63 | Bogogig_247))) - ((~((~(Bogoggl_2163)))) ^ l_2163)) ^ (~(Bogoglg_63))) | (~((((~((g_1129 | l_1452))) & l_1633) | g_1460)))))));
g_63 = (~(((((~((g_540 ^ ((~(l_2163)) ^ ((g_247 + Bogogjg_540) - ((~(g_1460)) ^ l_1456)))))) % ((~(Bogoghg_1460)) - ((~(Bogogkl_1452)) ^ (~(l_1434))))) + Bogogig_247) - (((Bogoggl_2163 | l_1452) + (~(l_1633))) & (~((~((Bogoglg_63 - (g_1129 ^ g_63))))))))));
                               uint16_t BGgGggl_1956 = (~(((~(((~((g_217 << g_103))) + (~((l_1956 ^ l_1179)))))) + ((((~(g_161)) % (g_538 & g_83)) % (~(l_1377))) || (l_1736 / l_1401)))));
int8_t BGgGghg_83 = (~(((~((~((g_217 % l_1956))))) | (((~(l_1401)) ^ ((((g_83 - (l_1377 % l_1736)) + g_161) % (~(l_1179))) + BGgGggl_1956)) | (g_538 & g_103)))));
uint32_t BGgGgig_103 = (~(((((~((~(l_1401)))) % ((BGgGghg_83 | (~((BGgGggl_1956 && (~((~(g_161)))))))) | ((l_1179 / g_83) && (~((~(g_103))))))) ^ (~(l_1377))) / (((~((l_1956 ^ l_1736))) - g_538) >> g_217))));
int32_t BGgGgjl_1179 = (~(((~((g_103 + (BGgGghg_83 / (l_1179 + l_1736))))) & ((((~((g_538 & g_217))) && BGgGggl_1956) >> ((~(BGgGgig_103)) && (~((l_1401 << (l_1377 || l_1956)))))) + (~((~((g_83 ^ (~(g_161)))))))))));
uint8_t BGgGgkg_217 = (~((((~(l_1179)) | (~(((g_217 && (~(g_538))) - (l_1956 ^ (~((~((BGgGggl_1956 ^ l_1377)))))))))) ^ ((g_83 % (~(l_1736))) % (g_103 ^ ((~(((~((~(BGgGgjl_1179)))) | BGgGghg_83))) / ((l_1401 << g_161) ^ BGgGgig_103)))))));
uint16_t BGgGgll_1377 = (~((((~(((l_1956 - (BGgGgkg_217 % l_1179)) ^ BGgGggl_1956))) << (((~((~((g_161 && (~(g_83))))))) || (~(l_1736))) && (((~(BGgGghg_83)) % (~(g_103))) && (~(BGgGgig_103))))) / ((l_1377 >> (g_217 & BGgGgjl_1179)) - (~((g_538 ^ l_1401)))))));
if((l_1956<=8)){
BGgGggl_1956 = l_1956;
BGgGghg_83 = g_83;
LABEL_GgGgm: BGgGgig_103 = g_103;
BGgGgjl_1179 = l_1179;
BGgGgkg_217 = g_217;
BGgGgll_1377 = l_1377;
l_1956 = (~((((~((~((~(g_83)))))) ^ (~((~((l_1179 & BGgGggl_1956)))))) || (((~((BGgGgig_103 && (g_538 && l_1401)))) - (((BGgGgll_1377 || g_217) / (~(((((~(BGgGgjl_1179)) && g_161) | l_1956) & (~(l_1736)))))) >> (l_1377 % (BGgGghg_83 || BGgGgkg_217)))) + (~(g_103))))));
g_83 = (~(((~((~(((~((~((g_538 || (~(((l_1377 | BGgGgkg_217) + (~(g_217)))))))))) | (((~((l_1736 | BGgGgll_1377))) >> (~(g_83))) % (((~(BGgGgig_103)) | l_1179) ^ (~((~(BGgGgjl_1179))))))))))) && ((~(((~((~(l_1956)))) & BGgGghg_83))) || (~(((~((BGgGggl_1956 & l_1401))) + (g_161 ^ g_103))))))));
g_103 = (~(((~(((((~(g_217)) || (((~(BGgGggl_1956)) + l_1736) + ((~(l_1377)) ^ l_1956))) ^ g_161) << (~((~(BGgGgig_103))))))) - (~(((~((~((l_1401 & BGgGgkg_217))))) - ((~((~((BGgGgjl_1179 | g_83))))) % ((BGgGghg_83 % BGgGgll_1377) - ((g_538 % l_1179) | g_103)))))))));
l_1179 = (~(((~((~(((~((~((g_217 % (~(l_1179))))))) & ((((~(l_1736)) ^ (g_83 - (g_103 || BGgGgkg_217))) && (~((BGgGgig_103 << BGgGgll_1377)))) / ((~((l_1401 | (~((~(((~(BGgGggl_1956)) | g_538)))))))) || BGgGgjl_1179))))))) / ((~(g_161)) ^ (BGgGghg_83 ^ (l_1377 || (~((~(l_1956))))))))));
g_217 = (~(((~((BGgGgig_103 & (g_161 | l_1736)))) & (~(((~(((BGgGgll_1377 | ((l_1401 && (g_103 / g_538)) % (~((~(g_83)))))) | (~((l_1179 + BGgGgjl_1179)))))) & ((l_1377 | g_217) ^ (((l_1956 & BGgGgkg_217) | BGgGghg_83) - BGgGggl_1956))))))));
l_1377 = (~(((~(g_103)) << ((~((~((((l_1736 || BGgGghg_83) >> l_1401) + l_1179))))) & (((~((BGgGgkg_217 % BGgGgig_103))) % (~(((l_1377 / BGgGgjl_1179) && (((~(BGgGgll_1377)) - ((g_217 && (~(g_161))) << (~(g_83)))) + (l_1956 & g_538)))))) % BGgGggl_1956)))));
if((((!BGgGgll_1377) || (BGgGghg_83 < l_1736)) || !(l_1401))){
printf("l_1956=%llu\n", (unsigned long long)l_1956);
goto LABEL_ogogm;
}
if((((g_217 < l_1377) && (BGgGghg_83>-1)) || (!BGgGgjl_1179))){
printf("g_83=%lld\n", (long long)g_83);
BGgGggl_1956 = (~(((~((~(BGgGgjl_1179)))) >> (((BGgGghg_83 + (BGgGgll_1377 || (BGgGggl_1956 + l_1377))) - (~((~((l_1736 || (BGgGgig_103 || g_103))))))) - ((~((~(g_83)))) | (~((((g_161 && (~((l_1179 || l_1956)))) && (~(BGgGgkg_217))) && (~((~(((~(l_1401)) & (g_217 % g_538))))))))))))));
break;
}
if((((l_1377>10834) || (!l_1736)) && (!l_1401))){
printf("g_103=%llu\n", (unsigned long long)g_103);
goto LABEL_GgGgm;
}
if((!g_538)){
printf("l_1179=%lld\n", (long long)l_1179);
break;
}
if(((BGgGghg_83<=-1) && (!l_1179))){
printf("g_217=%llu\n", (unsigned long long)g_217);
BGgGgkg_217 = (~(((~((((l_1401 >> BGgGgjl_1179) | (~(((~((BGgGgkg_217 ^ l_1179))) << (~(((g_83 % l_1956) + (g_161 << g_217)))))))) | ((~(g_103)) || ((~(BGgGggl_1956)) / (BGgGgll_1377 << BGgGghg_83)))))) | (~((((~(((~(l_1377)) << BGgGgig_103))) + (~(g_538))) % l_1736))))));
g_103 = (~(((~((~(((g_83 & ((~((~((BGgGghg_83 && BGgGgll_1377))))) && (g_161 || (~((BGgGggl_1956 / BGgGgig_103)))))) & ((l_1736 & g_538) - ((~(l_1956)) && BGgGgkg_217))))))) << (~(((~((g_217 >> ((~(g_103)) || BGgGgjl_1179)))) + ((l_1401 & (~(l_1377))) / l_1179)))))));
}
if(!((l_1956 > BGgGgig_103))){
printf("l_1377=%llu\n", (unsigned long long)l_1377);
goto LABEL_GgGgm;
}
}
l_1956 = BGgGggl_1956;
g_83 = BGgGghg_83;
g_103 = BGgGgig_103;
l_1179 = BGgGgjl_1179;
g_217 = BGgGgkg_217;
l_1377 = BGgGgll_1377;

                    if((!g_1129)){
printf("l_2163=%lld\n", (long long)l_2163);
Bogoghg_1460 = (~(((~((~((~((l_1434 % (~(Bogoghg_1460))))))))) & (~((((g_1460 & Bogogkl_1452) ^ (~(l_1633))) + ((((Bogogjg_540 << (Bogogig_247 - g_1129)) % l_1452) & (~((((Bogoggl_2163 | (~((g_247 & (~(l_1456)))))) >> (~(Bogoglg_63))) >> ((~((~(l_2163)))) | (~(g_540))))))) >> g_63)))))));
continue;
}
if(!((g_1460<=125))){
printf("g_1460=%llu\n", (unsigned long long)g_1460);
Bogoglg_63 = (~(((~((((~(l_1456)) - (~(g_63))) << (~(((((~(((~(l_1434)) & g_1460))) >> g_1129) << (~(Bogoghg_1460))) & ((~((~(l_1452)))) | ((Bogogkl_1452 - (~((Bogoggl_2163 + Bogoglg_63)))) >> (g_247 + Bogogig_247))))))))) << ((~((~((~(l_1633)))))) + (~(((Bogogjg_540 | g_540) - l_2163)))))));
l_2163 = (~(((~((~((((~(g_540)) % (~(l_2163))) ^ (~((~(l_1456))))))))) >> (((~((~(((((g_63 - (g_1460 << Bogoghg_1460)) + (Bogogkl_1452 ^ (Bogogig_247 + g_1129))) | l_1452) + (~((Bogoggl_2163 + (~(l_1633)))))))))) + (~((~((Bogoglg_63 % ((~(g_247)) | (~((~(Bogogjg_540))))))))))) % l_1434))));
g_540 = (~((((~((~(((~(Bogogig_247)) - (~(g_247))))))) >> (~(Bogoglg_63))) >> (~((~(((~(g_540)) - (((~((~((~((g_1460 % (Bogoggl_2163 >> l_2163)))))))) ^ ((~(l_1456)) << ((Bogogjg_540 - l_1434) ^ g_63))) | (~((~((Bogogkl_1452 + ((g_1129 % l_1452) & (l_1633 % Bogoghg_1460))))))))))))))));
}
if(!((l_2163<=9548))){
printf("g_247=%lld\n", (long long)g_247);
break;
}
if((Bogoglg_63>1)){
printf("l_1452=%lld\n", (long long)l_1452);
break;
}
LABEL_ogogm: if((Bogoglg_63>1)){
printf("g_63=%llu\n", (unsigned long long)g_63);
Bogogig_247 = (~(((~((((~((~((l_1456 << l_1633))))) % Bogogjg_540) - (Bogoglg_63 >> ((~(Bogoghg_1460)) ^ g_63))))) & ((((l_1434 ^ Bogogkl_1452) + (~(((~(g_247)) | (~((~((Bogogig_247 >> l_1452))))))))) | (~((~((~(l_2163))))))) + (g_1460 & (g_1129 + (g_540 | Bogoggl_2163)))))));
l_1452 = (~((((g_247 ^ l_1456) % (~(((~(((~((l_1434 % (Bogoglg_63 % (~(Bogoggl_2163)))))) << ((Bogogkl_1452 + (~(l_1452))) & (~((~((~((~(g_540)))))))))))) + (~((~((Bogoghg_1460 | g_63))))))))) - (~((((l_1633 % (g_1460 ^ l_2163)) >> g_1129) ^ ((~(Bogogjg_540)) | Bogogig_247)))))));
}
}
l_2163 = Bogoggl_2163;
g_1460 = Bogoghg_1460;
g_247 = Bogogig_247;
g_540 = Bogogjg_540;
                               int32_t BGgGgnl_1432 = (~(((~((~(((~((~(l_1180)))) || (l_1432 & ((g_173 && g_63) || (l_1956 | g_12)))))))) ^ (~((((l_1836 || l_1736) | g_1524) / (~(l_1426))))))));
int16_t BGgGgol_1736 = (~(((~((g_63 ^ (l_1956 << BGgGgnl_1432)))) + (~((((l_1736 || l_1426) & (~(((~((((~(g_1524)) & g_173) + l_1432))) << l_1180)))) - (~((g_12 | (~(l_1836)))))))))));
uint16_t BGgGgpl_1956 = (~((((~((~((~((~((~(l_1836)))))))))) ^ (BGgGgnl_1432 & g_173)) | (~(((~((l_1180 || ((~(l_1736)) % (~(l_1956)))))) && (((g_1524 & g_12) & (g_63 & ((~(l_1426)) / BGgGgol_1736))) & (~(l_1432)))))))));
int32_t BGgGgql_1836 = (~(((~((~(((((l_1836 ^ g_1524) + (l_1432 ^ (l_1180 || BGgGgol_1736))) & ((~(l_1956)) + (~((~(g_12)))))) >> ((((~(g_173)) && BGgGgnl_1432) | BGgGgpl_1956) % g_63)))))) - (~((l_1736 ^ l_1426))))));
uint16_t BGgGgrg_63 = (~(((~((~(l_1432)))) + ((((~((~(l_1836)))) % (((~(l_1426)) ^ ((~(g_12)) / (~(g_63)))) && BGgGgol_1736)) && (~(((~((~((~(((~(l_1180)) & (~(BGgGgpl_1956))))))))) % (~((BGgGgql_1836 | (g_173 & g_1524)))))))) % (l_1956 || (~((BGgGgnl_1432 - l_1736))))))));
int32_t BGgGgsl_1426 = (~((((~((((g_63 - BGgGgpl_1956) + (l_1956 % (((~((BGgGgnl_1432 | l_1432))) & (~(BGgGgol_1736))) << l_1180))) || l_1736))) / (~((~(((~((g_1524 ^ g_173))) ^ BGgGgrg_63)))))) & (~((((~((g_12 && BGgGgql_1836))) / l_1836) - (~(l_1426))))))));
if(((BGgGgpl_1956>=0) && (g_63 > l_1180))){
BGgGgnl_1432 = l_1432;
BGgGgol_1736 = l_1736;
BGgGgpl_1956 = l_1956;
BGgGgql_1836 = l_1836;
BGgGgrg_63 = g_63;
BGgGgsl_1426 = l_1426;
l_1432 = (~(((~(((g_63 && (~((g_1524 && (~(((BGgGgrg_63 ^ BGgGgsl_1426) & g_12))))))) | (~((~((~(l_1956))))))))) || ((~(((~((~((~(BGgGgol_1736)))))) / ((((~((BGgGgnl_1432 && l_1736))) - (l_1836 / (BGgGgql_1836 ^ g_173))) + (l_1426 / BGgGgpl_1956)) && (~(l_1432)))))) & l_1180))));
l_1736 = (~((((~(((~(BGgGgnl_1432)) % (l_1180 || ((g_173 || BGgGgol_1736) || BGgGgql_1836))))) + (~(((~((~(BGgGgrg_63)))) / ((l_1736 - l_1426) && (~(l_1956))))))) && (~(((((~(l_1432)) % ((~((~(g_63)))) % ((g_12 && l_1836) + BGgGgpl_1956))) && g_1524) && BGgGgsl_1426))))));
l_1956 = (~(((~((((BGgGgnl_1432 || ((g_12 && (~(BGgGgql_1836))) & (BGgGgrg_63 | (~(g_63))))) && ((~(BGgGgsl_1426)) + (l_1426 << (~((~((BGgGgol_1736 && (~(g_173)))))))))) % ((~(((~((BGgGgpl_1956 || g_1524))) % (~((~((l_1956 || (l_1736 & l_1432))))))))) && (~((~((~(l_1180)))))))))) || l_1836)));
l_1836 = (~((((l_1426 && ((~((~((~((~(g_1524)))))))) / l_1836)) && ((((~(((BGgGgnl_1432 - BGgGgql_1836) & (BGgGgsl_1426 / l_1736)))) ^ (BGgGgrg_63 % l_1956)) & ((BGgGgol_1736 ^ l_1180) + g_63)) | (((~(g_173)) && l_1432) || (~(BGgGgpl_1956))))) - (~(g_12)))));
LABEL_GgGgt: g_63 = (~(((BGgGgql_1836 << BGgGgsl_1426) >> (~((~((((~((~(BGgGgnl_1432)))) ^ (((~((l_1836 % (BGgGgpl_1956 || (l_1432 ^ g_173))))) || (~(BGgGgrg_63))) ^ g_1524)) & (~(((~((((~(g_12)) + l_1736) && (~(g_63))))) ^ (((l_1180 - l_1956) && BGgGgol_1736) >> l_1426))))))))))));
l_1426 = (~(((((~(BGgGgnl_1432)) + (~((~(l_1736))))) || (~((~(g_63))))) % ((((~((~((l_1836 / BGgGgql_1836))))) | ((~((((~((g_12 && (l_1956 || l_1432)))) && l_1426) & (~((~(((~(g_173)) | g_1524)))))))) + (l_1180 + BGgGgrg_63))) && BGgGgol_1736) - (BGgGgpl_1956 && BGgGgsl_1426)))));
if(((g_173<=0) && (g_63 < l_1180))){
printf("l_1432=%lld\n", (long long)l_1432);
BGgGgnl_1432 = (~(((~((~((((~(BGgGgnl_1432)) + (((BGgGgpl_1956 && l_1426) || l_1432) ^ (BGgGgol_1736 || (g_173 + (~((g_1524 / g_12))))))) - (~(((~((l_1836 % BGgGgql_1836))) / (~((g_63 / l_1180))))))))))) << ((~((~(l_1736)))) % ((~(BGgGgsl_1426)) && (~((~((~((l_1956 + BGgGgrg_63))))))))))));
break;
}
if((BGgGgql_1836>544486578)){
printf("l_1736=%lld\n", (long long)l_1736);
BGgGgsl_1426 = (~((((~(((l_1836 - g_63) && (~(l_1956))))) >> ((((~(g_1524)) % (~(l_1426))) << ((BGgGgnl_1432 ^ BGgGgsl_1426) - l_1432)) || (((g_173 & (l_1736 << BGgGgol_1736)) % BGgGgrg_63) || g_12))) & (l_1180 << (BGgGgpl_1956 << BGgGgql_1836)))));
l_1836 = (~((BGgGgpl_1956 & (~((((~(BGgGgrg_63)) % (~(g_173))) || ((~(((l_1180 % g_63) / (l_1432 + (l_1426 && BGgGgol_1736))))) >> (BGgGgql_1836 << ((((l_1956 >> g_12) | BGgGgsl_1426) % (((~(l_1836)) / l_1736) / BGgGgnl_1432)) && g_1524)))))))));
l_1426 = (~(((((~(BGgGgsl_1426)) | (~(((l_1180 ^ (g_173 >> (~(BGgGgpl_1956)))) || g_63)))) / ((((l_1736 >> (g_1524 | BGgGgnl_1432)) + l_1426) + (~((l_1836 & (~((~(l_1432)))))))) - (~(((~(g_12)) << BGgGgol_1736))))) << ((l_1956 % BGgGgrg_63) - (~((~(BGgGgql_1836))))))));
}
if((l_1736 < BGgGgol_1736)){
printf("l_1956=%llu\n", (unsigned long long)l_1956);
BGgGgql_1836 = (~((((~((l_1426 & (g_63 ^ ((~(l_1956)) && BGgGgol_1736))))) % (l_1180 >> (~(l_1432)))) ^ ((~((~(((~(((g_12 ^ BGgGgrg_63) << (BGgGgnl_1432 || l_1736)))) % (~(((~(BGgGgpl_1956)) & (~(((~(((~(BGgGgsl_1426)) - g_173))) && g_1524))))))))))) | (~((l_1836 / BGgGgql_1836)))))));
break;
}
if(((l_1736 < g_1524) || (l_1836>-253))){
printf("l_1836=%lld\n", (long long)l_1836);
BGgGgrg_63 = (~((((((~(((l_1432 | (~(l_1180))) / l_1736))) & ((~((l_1426 >> g_63))) ^ (~((BGgGgnl_1432 ^ ((~(BGgGgol_1736)) && BGgGgrg_63)))))) + ((g_12 + BGgGgsl_1426) % l_1836)) + (~(((~(g_173)) / (~(BGgGgpl_1956)))))) || (~(((BGgGgql_1836 + l_1956) / (~(g_1524))))))));
break;
}
if(!(!((g_173 > g_12)))){
printf("g_63=%llu\n", (unsigned long long)g_63);
continue;
}
if((!BGgGgpl_1956)){
printf("l_1426=%lld\n", (long long)l_1426);
goto LABEL_ogogm;
}
}
l_1432 = BGgGgnl_1432;
l_1736 = BGgGgol_1736;
l_1956 = BGgGgpl_1956;
l_1836 = BGgGgql_1836;
g_63 = BGgGgrg_63;
l_1426 = BGgGgsl_1426;

                    l_1452 = Bogogkl_1452;
g_63 = Bogoglg_63;

                    l_1452 = 8L;
                                                       if (l_1836)
                    if ((+l_27))
                    {
                        g_22 = (safe_mod_func_int32_t_s_s((g_4 ^ (((l_1426 = p_9) <= ((p_9 <= p_9) != ((l_1271 != (l_1456 = g_540)) || p_9))) & (((((l_1452 = (g_247 = p_9)) > (6UL == l_1459[0])) < l_1000[1][5]) ^ 6UL) || 0x249EL))), 0xE13E9B49L));
                        if (g_1460)
                            continue;
                    }
                    else
                    {
                        l_1432 = l_1449;
                    }
                }
                                               int32_t BGgGgul_1432 = (~((((((~(g_974)) | l_1631) - l_1377) + (~(((~((~(l_1431)))) % (~((~(g_1460)))))))) | (~((l_1426 - ((~((l_1432 ^ g_538))) - (~(((~(g_83)) ^ l_1450))))))))));
uint16_t BGgGgvg_538 = (~((((~(((~(l_1432)) | (((l_1377 && g_974) && l_1450) ^ (~(l_1431)))))) & ((~(l_1426)) - g_83)) && ((~((~((~(BGgGgul_1432)))))) ^ (~(((~((g_538 || g_1460))) ^ (~((~(l_1631)))))))))));
int32_t BGgGgwl_1450 = (~(((~((((g_538 || l_1631) << g_974) - (l_1450 + l_1431)))) && (~(((~((~((((~(l_1426)) & (~((g_83 | (~(BGgGgul_1432)))))) && (~((~((~((BGgGgvg_538 && g_1460)))))))))))) | (~((~((l_1377 & l_1432)))))))))));
uint16_t BGgGgxl_1377 = (~(((((~((BGgGgwl_1450 | g_538))) | (g_83 % ((~((~(BGgGgul_1432)))) ^ (~(((~(g_974)) | ((~((~(l_1426)))) / ((l_1431 | l_1377) + BGgGgvg_538)))))))) / ((~(l_1432)) & l_1631)) - (~((l_1450 ^ g_1460))))));
int32_t BGgGgyl_1426 = (~(((((~(l_1432)) || (~((BGgGgul_1432 && (~(g_538)))))) / (((~(((~(l_1631)) % l_1377))) | BGgGgvg_538) & g_1460)) || ((g_83 && l_1450) - ((BGgGgxl_1377 + BGgGgwl_1450) - ((l_1431 >> g_974) ^ l_1426))))));
int32_t BGgGgzl_1431 = (~(((~(((~((~((l_1431 && g_83))))) + ((~(g_1460)) / BGgGgyl_1426)))) && (~(((~((BGgGgxl_1377 + ((~(l_1432)) || g_538)))) ^ (~((~((((((l_1631 + (g_974 + l_1426)) / l_1450) + BGgGgul_1432) / (BGgGgwl_1450 + BGgGgvg_538)) + (~((~(l_1377)))))))))))))));
if((!((l_1450>-1431126435)) || ((!BGgGgvg_538) && (!BGgGgvg_538)))){
BGgGgul_1432 = l_1432;
BGgGgvg_538 = g_538;
BGgGgwl_1450 = l_1450;
BGgGgxl_1377 = l_1377;
BGgGgyl_1426 = l_1426;
BGgGgzl_1431 = l_1431;
l_1432 = (~(((~(((l_1450 & (((~((l_1431 / (BGgGgyl_1426 | BGgGgxl_1377)))) / (~(((~(BGgGgul_1432)) | (((BGgGgvg_538 - l_1377) & l_1432) / BGgGgwl_1450))))) & (~((l_1631 / BGgGgzl_1431))))) - ((~((~(g_974)))) - g_1460)))) & ((~(l_1426)) | (~((~((g_83 && g_538)))))))));
g_538 = (~((((((BGgGgul_1432 / BGgGgzl_1431) ^ l_1377) && ((~(((~((~(BGgGgxl_1377)))) || g_538))) + (BGgGgvg_538 / l_1450))) ^ ((l_1631 & g_974) | (~(((~(l_1432)) % BGgGgwl_1450))))) && ((~((l_1431 || (g_83 + (BGgGgyl_1426 || l_1426))))) / (~(g_1460))))));
l_1450 = (~((((l_1377 || (~((~((l_1450 % (~(l_1431)))))))) | ((~((g_538 + (g_974 - l_1432)))) | (~(((~((~((BGgGgzl_1431 % g_1460))))) ^ (((~(g_83)) && l_1631) + BGgGgul_1432)))))) & ((~((BGgGgwl_1450 & BGgGgyl_1426))) + ((l_1426 ^ BGgGgvg_538) || BGgGgxl_1377)))));
l_1377 = (~(((~((((~((BGgGgxl_1377 + g_1460))) % (((((BGgGgvg_538 + (~(BGgGgzl_1431))) / (~((BGgGgul_1432 >> l_1426)))) ^ (~((l_1631 & l_1432)))) - (((~(g_83)) ^ (~(BGgGgyl_1426))) - (l_1377 % (~(BGgGgwl_1450))))) && (~((~(g_974)))))) / (~(g_538))))) / (~((~((~((~(l_1431)))))))))));
l_1426 = (~(((~((~((~((~(g_1460)))))))) / (~(((~((~(BGgGgyl_1426)))) - ((~(((l_1432 + l_1426) | ((l_1431 - BGgGgzl_1431) - (~(BGgGgxl_1377)))))) | (~((((g_974 ^ ((~(BGgGgvg_538)) ^ (g_83 % g_538))) && ((BGgGgwl_1450 % l_1631) | l_1377)) && BGgGgul_1432))))))))));
l_1431 = (~(((~((BGgGgvg_538 || (l_1432 ^ l_1426)))) + (((~(((~((l_1377 + (BGgGgul_1432 & BGgGgwl_1450)))) % (((l_1631 ^ g_83) - ((~((~(g_538)))) && (~(BGgGgxl_1377)))) || BGgGgzl_1431)))) ^ (~(g_1460))) & (~(((l_1431 >> BGgGgyl_1426) ^ (~(g_974)))))))));
LABEL_GgGgA: if((((l_1432<=2644) || (!BGgGgul_1432)) && ((BGgGgxl_1377 < BGgGgvg_538) && (g_83 > BGgGgyl_1426)))){
printf("l_1432=%lld\n", (long long)l_1432);
continue;
}
LABEL_GgGgB: if((((g_974 < l_1426) || (l_1631 > BGgGgyl_1426)) && !(l_1432))){
printf("l_1450=%lld\n", (long long)l_1450);
break;
}
if(((BGgGgul_1432 < BGgGgwl_1450) || (BGgGgul_1432 > g_538))){
printf("l_1377=%llu\n", (unsigned long long)l_1377);
break;
}
if((l_1631>-18955)){
printf("l_1426=%lld\n", (long long)l_1426);
goto LABEL_GgGgB;
}
if(((BGgGgxl_1377 > BGgGgvg_538) || (BGgGgvg_538 < l_1426))){
printf("l_1431=%lld\n", (long long)l_1431);
break;
}
}
l_1432 = BGgGgul_1432;
g_538 = BGgGgvg_538;
l_1450 = BGgGgwl_1450;
l_1377 = BGgGgxl_1377;
l_1426 = BGgGgyl_1426;
l_1431 = BGgGgzl_1431;

                    if ((0xAC7B6331L < (((((safe_add_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(g_63, 5)), 0xF8L)) && ((-6L) > (((-1L) == (g_813[1][0] = 65535UL)) && (((((0xDB09L & g_83) && (((safe_mod_func_int16_t_s_s(g_1215[4], l_1467)) | 0L) <= l_1359[3])) || l_1424) < 0xEB4AB756L) != 1L)))) < 0x2DL) | g_361) >= l_1426)))
                {
                    uint16_t l_1482[10] = {0UL,7UL,0x6A59L,7UL,0UL,0UL,7UL,0x6A59L,7UL,0UL};
                    int32_t l_1484 = (-10L);
                    int i;
                    for (l_1424 = 7; (l_1424 >= 21); l_1424 = safe_add_func_int16_t_s_s(l_1424, 6))
                    {
                        uint8_t l_1472 = 0UL;
                        int32_t l_1483 = 0xF30B31E2L;
                        l_1484 = (((0x358998F2L && ((l_1483 = ((safe_rshift_func_int8_t_s_u(l_1449, 5)) >= (0x49L & ((((((((0x23DAA934L | (9L > l_1472)) || ((safe_mod_func_int8_t_s_s((safe_sub_func_uint32_t_u_u((((((~1UL) ^ g_361) & ((safe_mod_func_uint16_t_u_u(((l_975[0][0] = (((safe_sub_func_uint16_t_u_u(((l_26 = 4294967289UL) ^ p_9), l_1426)) && p_9) || p_9)) || g_359[7][2]), (-5L))) == l_1482[8])) && p_9) > l_1472), 0x6B9FD0C3L)), p_9)) <= 255UL)) == l_1472) > p_9) >= l_27) && l_1386[7][1][4]) <= l_1472) & (-1L))))) & g_172[4])) != 1UL) ^ l_1482[8]);
                    }
                }
                else
                {
                    int32_t l_1493[5];
                    int32_t l_1528 = 1L;
                    int i;
                    for (i = 0; i < 5; i++)
                        l_1493[i] = 0x26DA5657L;
                    l_1426 = (g_247 = ((((((((l_987 = ((g_247 <= ((safe_mod_func_uint32_t_u_u(((g_83 = (((((0L ^ ((safe_lshift_func_int16_t_s_s((((safe_add_func_int16_t_s_s(1L, (p_9 = (safe_sub_func_uint32_t_u_u((((l_1493[0] & (!(p_9 < ((((0x60781BCDL >= (safe_mod_func_int32_t_s_s((((safe_mod_func_int32_t_s_s((l_1271 || (((l_975[0][0] = (((safe_mod_func_int16_t_s_s(l_1493[1], (~0x8BL))) ^ l_1153) ^ l_1493[0])) < l_1423) & 0xCC6EBE87L)), p_9)) > 0xB5L) | 0UL), p_9))) != p_9) ^ 4294967287UL) <= p_9)))) > l_27) && g_540), l_1423))))) || g_172[4]) ^ l_26), l_1401)) || p_9)) && 0x6EL) != l_1493[0]) >= l_1493[4]) < 0x0103082AL)) & 1L), l_1431)) >= g_63)) != g_540)) | l_1493[3]) == l_1434) ^ 0xF2A5F255L) <= 0xB1BFL) != (-1L)) & l_1493[0]) ^ (-1L)));
                    l_1424 = (safe_sub_func_uint32_t_u_u(g_540, ((((safe_add_func_int32_t_s_s((((g_83 = p_9) && (safe_lshift_func_int16_t_s_s(((safe_lshift_func_int8_t_s_u((safe_add_func_uint16_t_u_u(((((0x4A22L & p_9) == (g_541 >= (((((((safe_sub_func_uint16_t_u_u((safe_rshift_func_int8_t_s_u(((safe_add_func_uint8_t_u_u((l_1493[4] = (((safe_sub_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u((((g_1524 < l_1493[0]) | (safe_mod_func_int16_t_s_s(0x2E74L, l_1431))) && g_1460), 6)), l_1432)) ^ 0x1872A46CL) <= l_1401)), 0x3DL)) ^ 0UL), p_9)), l_1527)) & l_987) == l_1528) < 1L) != l_1467) ^ l_1153) != p_9))) > l_1401) | l_1386[7][1][4]), g_103)), 7)) >= 65533UL), 11))) & g_161), p_9)) == 0x170AL) | l_1153) != 0x1308L)));
                                                        if ((l_1426 < l_1450) )
{

for (l_1423 = 0; (l_1423 <= 1); l_1423 += 1)
                    {
                        l_1179 = ((-5L) <= (65528UL || ((safe_lshift_func_uint8_t_u_u((g_2710 = (g_12 = ((safe_rshift_func_uint16_t_u_s(g_188, (l_982 = (g_949[0][6][1] < 1L)))) || g_188))), (g_2710 = (((safe_rshift_func_int8_t_s_s(1L, ((((g_543[1] = ((0x4A66L || ((((l_1633 || g_541) != g_2710) || l_1467) & g_188)) <= g_2710)) && g_188) ^ g_3957) & l_1320))) >= g_188) > g_188)))) & j)));
                    };


}
                    l_975[1][0] = (0x7F4604DAL >= (((p_9 = p_9) >= ((g_172[8] | ((g_173 ^ (0xACL != l_982)) == (safe_sub_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(l_1432, (safe_add_func_uint32_t_u_u(g_115, (((safe_rshift_func_uint16_t_u_s((safe_mod_func_int32_t_s_s((safe_add_func_int32_t_s_s(((l_1456 = (safe_add_func_uint32_t_u_u(4294967287UL, l_1456))) ^ 0xA1L), 0x186CA311L)), l_28)), l_28)) ^ g_217) > 65529UL))))), l_1423)))) < g_1460)) != 0x16L));
                                                       if (l_1633)
                    l_1574[8][3][0] = (safe_add_func_uint16_t_u_u(((safe_unary_minus_func_uint32_t_u(p_9)) < (!(safe_rshift_func_uint8_t_u_s(((l_1179 = l_1450) < (safe_rshift_func_int8_t_s_s((g_83 = p_9), (safe_mod_func_int8_t_s_s((safe_mod_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_u(g_866[0][6], g_543[0])) & ((((~(safe_add_func_int16_t_s_s(((g_813[1][0] | (l_975[0][0] >= ((safe_add_func_uint8_t_u_u(((p_9 | (l_26 = ((l_1456 = (safe_rshift_func_uint8_t_u_s((((((safe_mod_func_uint8_t_u_u(((safe_mod_func_int32_t_s_s((safe_lshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_u((((1L == 0x2590L) | 0UL) == 0x7D765DB6L), g_361)), 4)), g_1215[4])) != (-3L)), l_1527)) > 1UL) & l_1359[6]) | p_9) > 2L), 1))) | l_1493[0]))) >= l_1153), 0x0EL)) && 0xFBL))) ^ 1UL), l_1449))) < 1UL) == 0x4EL) && l_975[0][0])), l_975[0][0])), 0x54L))))), 1)))), g_173));
                }
                l_1426 = p_9;
            }
            else
            {
                int16_t l_1575 = 0x3956L;
                g_247 = 0xDF2B422CL;
                l_1574[2][4][0] = 1L;

{
                int32_t l_2250 = 3L;
                int i;
                l_2250 = (l_975[0][0] = (g_1215[g_315] | g_3409));
            }

                    l_1575 = (g_247 = p_9);
                g_247 = (safe_add_func_uint16_t_u_u((((safe_sub_func_int8_t_s_s(((l_27 = (safe_lshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(l_26, 15)) == (0xDD25L || (l_1401 != (((safe_mod_func_int16_t_s_s((safe_sub_func_int8_t_s_s(l_1401, (((safe_add_func_int32_t_s_s((safe_add_func_int8_t_s_s(((safe_rshift_func_uint8_t_u_s((0xDA9F34EDL < l_1000[0][6]), 2)) >= ((safe_sub_func_int16_t_s_s(((safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u((((safe_add_func_uint16_t_u_u(l_1374[4], (p_9 = (p_9 != g_12)))) || p_9) || 0x2BL), l_982)), g_1129)) ^ 1UL), l_1386[7][1][4])) != 0xAFL)), 248UL)), l_1467)) > g_172[2]) <= 0x6EFDL))), l_1001)) < l_1575) && 0x454F405FL)))), 2))) | 0x1EL), l_1575)) < g_172[6]) <= l_1575), l_1271));
            }
        }
        for (l_1434 = 0; (l_1434 <= 2); l_1434 += 1)
        {
            uint16_t l_1613 = 0xBDD3L;
            int32_t l_1647[7] = {4L,4L,4L,4L,4L,4L,4L};
            uint32_t l_1715 = 4294967291UL;
            int i;
            l_975[1][0] = (((p_9 = 0xD9E9L) != (safe_mod_func_int8_t_s_s((g_866[4][0] | ((~(safe_unary_minus_func_int8_t_s((g_813[5][0] || 0x871AL)))) | (l_26 = (1L || (safe_sub_func_int16_t_s_s((safe_mod_func_int8_t_s_s(((((+(((g_974 = (safe_sub_func_uint8_t_u_u((l_1374[3] >= 1UL), (0x15E6545DL <= 0L)))) > 2L) != 4294967295UL)) <= g_12) == l_26) < g_1460), l_1613)), l_1613)))))), g_813[0][0]))) | g_866[4][0]);
            for (l_1320 = 0; (l_1320 <= 2); l_1320 += 1)
            {
                uint32_t l_1630 = 0UL;
                int32_t l_1632 = (-3L);
                uint8_t l_1634 = 255UL;
                int32_t l_1735 = 0xE7931F0BL;
                int32_t l_1747 = 0x90D33844L;
                uint16_t l_1767 = 0xB63DL;
                int8_t l_1773 = 8L;
                if ((l_1634 = (safe_rshift_func_uint16_t_u_u((!(p_9 | (safe_add_func_int32_t_s_s((g_247 = ((safe_rshift_func_uint16_t_u_s(l_1434, (safe_add_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u((+p_9), (g_12 = (safe_sub_func_uint8_t_u_u(g_866[2][8], (l_26 = ((g_361 = (safe_rshift_func_uint16_t_u_u(((l_1632 = ((0x1151L < l_1630) & ((l_1631 <= (l_1077 != ((-1L) < 1L))) & 0x030F28C5L))) && p_9), 3))) | 255UL))))))) & g_217), l_1633)))) == 1UL)), g_540)))), 14))))
                {
                    return g_813[1][0];
                }
                else
                {
                    uint32_t l_1646 = 0x278B7B9BL;
                    uint16_t l_1656 = 0x0825L;
                    int32_t l_1678 = 0L;
                    l_975[2][0] = (safe_mod_func_uint32_t_u_u((~g_813[3][0]), (safe_lshift_func_int8_t_s_u(0x87L, ((253UL > (((g_866[4][0] = (safe_rshift_func_int16_t_s_s(((safe_sub_func_int16_t_s_s((l_1613 < (safe_sub_func_int32_t_s_s((g_247 & 0x4BC1D873L), ((l_1646 > p_9) == (l_1647[4] != 0x85B8F6D1L))))), 1L)) >= p_9), p_9))) & l_1632) >= p_9)) == p_9)))));
                                                        if ((!g_541) )
{

{
        for (g_115 = 0; g_115 < 1; g_115++)
            l_975[i][g_115] = 0x717E753EL;
    }

}
                    if (p_9)
                        break;
                    if ((((safe_lshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_s(p_9, 5)), (safe_sub_func_int32_t_s_s(l_1656, (65535UL & l_1631))))) <= ((((safe_mod_func_int16_t_s_s((l_1000[1][6] = (safe_add_func_int8_t_s_s(0L, ((((safe_lshift_func_uint8_t_u_s((g_1215[4] ^ (p_9 >= g_361)), 3)) < 65535UL) && 65531UL) >= p_9)))), 1L)) <= g_543[1]) <= g_361) < p_9)) & l_1646))
                    {
                        int32_t l_1677 = 0xF193FDE7L;
                        l_975[0][0] = ((safe_add_func_uint32_t_u_u(((g_361 | (safe_add_func_uint16_t_u_u(((((g_103 | (l_1574[8][3][0] = (l_1678 = (g_172[4] = ((((safe_add_func_uint16_t_u_u(((p_9 < (safe_unary_minus_func_int32_t_s(0x3E7B5B0BL))) || (l_1000[2][6] = ((~((safe_rshift_func_int8_t_s_s((safe_add_func_uint8_t_u_u(8UL, l_1647[5])), (safe_rshift_func_uint16_t_u_u(g_1460, p_9)))) && 3UL)) != p_9))), p_9)) < 65531UL) == 0x38L) | l_1677))))) != 0x7565L) > l_982) || g_188), p_9))) < 0L), g_538)) >= l_1374[3]);

g_3957 += 1;


                    if (g_173)
                            break;
                        g_22 = 0xD97B7BEFL;
                    }
                    else
                    {
                        int32_t l_1698 = 0xA0B63C4CL;
                        int32_t l_1709 = 0x482D571FL;
                        l_26 = (((safe_lshift_func_uint8_t_u_s((safe_rshift_func_uint16_t_u_u((g_172[6] = (((safe_add_func_int16_t_s_s((l_1698 = ((safe_rshift_func_uint16_t_u_s((3L != (safe_add_func_int16_t_s_s((safe_mod_func_int16_t_s_s((safe_mod_func_uint32_t_u_u(0x27E36F9BL, (safe_add_func_uint8_t_u_u(g_315, ((safe_sub_func_int8_t_s_s((safe_unary_minus_func_uint32_t_u((((((l_1698 != l_1698) <= (safe_lshift_func_int16_t_s_u(((safe_mod_func_int16_t_s_s((safe_add_func_uint32_t_u_u(((l_1574[8][3][0] = l_1632) ^ (g_1524 = ((g_217 != ((safe_lshift_func_uint8_t_u_s(((safe_rshift_func_int16_t_s_u(p_9, 1)) < ((p_9 != p_9) >= g_543[1])), g_359[0][1])) & g_4)) | g_103))), p_9)), (-1L))) >= g_541), p_9))) && l_1632) || 0x97BA31CCL) ^ p_9))), g_949[1][7][7])) ^ g_949[1][0][2]))))), l_21)), p_9))), g_103)) & 1UL)), g_4)) ^ p_9) <= 1L)), l_1288)), g_538)) ^ l_1709) >= 65527UL);
                    }
                    l_26 = (l_975[0][0] = l_1630);
                }
                for (l_1271 = 0; (l_1271 <= 7); l_1271 += 1)
                {
                    int8_t l_1750 = (-1L);
                    int32_t l_1754 = 0x72FDB8B5L;
                    int32_t l_1755 = 0xD68E3259L;
                    int i, j, k;
                    if ((+((safe_sub_func_uint32_t_u_u(g_949[l_1320][l_1271][(l_1320 + 6)], ((safe_lshift_func_int8_t_s_u(((l_1374[(l_1320 + 1)] != (g_83 = 5L)) & (((0x4FC7L <= (p_9 < ((((0xB7CFB51BL && l_1715) == ((g_188 | 0x5EL) > p_9)) | g_188) > 5UL))) == g_949[l_1320][l_1271][(l_1320 + 6)]) > l_1374[(l_1320 + 1)])), 6)) != 4UL))) >= p_9)))
                    {
                        int8_t l_1728 = 0x75L;
                        int32_t l_1734 = 0x88D3EA52L;
                        int i, j;
                        l_987 = (l_1574[1][1][4] = (l_1734 = (safe_lshift_func_int8_t_s_u(((l_1000[0][2] = (((safe_sub_func_int16_t_s_s((safe_mod_func_uint8_t_u_u(248UL, (safe_sub_func_uint8_t_u_u(l_1000[1][6], (0UL | (l_1735 = (safe_sub_func_int16_t_s_s(((g_866[(l_1434 + 2)][(l_1434 + 6)] = (safe_mod_func_uint8_t_u_u(l_1634, (l_1728 = 0xEFL)))) | ((safe_add_func_uint16_t_u_u(((((~((((l_1632 = (((safe_add_func_int16_t_s_s((0xE0L ^ (g_949[l_1320][l_1271][(l_1320 + 6)] >= p_9)), (((g_217 = (p_9 < l_1647[4])) < g_538) | l_1734))) ^ g_949[1][5][0]) > 0x20L)) > g_543[0]) < g_315) >= 3UL)) ^ 0x95EBL) || g_541) & l_1634), l_1374[(l_1320 + 1)])) < p_9)), 0x5FC9L)))))))), l_1736)) ^ 0x6872123FL) & g_949[0][7][7])) <= g_974), 3))));
                        l_1632 = ((safe_mod_func_int8_t_s_s(g_813[1][0], (((p_9 | 4L) ^ (l_1734 >= l_1179)) || (((safe_rshift_func_int16_t_s_u(l_1728, 1)) | ((g_813[1][0] == (l_1647[3] = ((safe_rshift_func_int16_t_s_u((0xF4L || ((safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u((((((0UL | l_1647[2]) < g_361) <= p_9) < p_9) | 0xF4D1L), p_9)), g_866[4][0])) ^ (-5L))), 10)) || 0x75L))) || l_1747)) == 0x60L)))) | p_9);
                        g_22 = p_9;
                    }
                    else
                    {
                        return g_1460;
                    }

{
                    g_12 = 0L;
                    for (g_83 = 0; (g_83 <= 6); g_83 += 1)
                    {
                        int32_t l_2677[7][8][4] = {{{1L,0x41A054B2L,0L,0x2D0DBF52L},{0x0CF1A441L,0L,(-5L),(-1L)},{(-4L),0L,0x731C9F43L,0x01A3D290L},{0L,(-10L),0x0D46BF51L,0x0D46BF51L},{3L,3L,0x4CB0245BL,0x60E2D043L},{0x0D46BF51L,0L,0xCE5C71E8L,0xD450BA5CL},{1L,0xBBB0E83CL,(-1L),0xCE5C71E8L},{0xBC9F03A0L,0xBBB0E83CL,(-10L),0xD450BA5CL}},{{0xBBB0E83CL,0L,(-1L),0x60E2D043L},{1L,3L,0xBC9F03A0L,0x0D46BF51L},{0x731C9F43L,(-10L),(-9L),0x01A3D290L},{0x4CB0245BL,0L,0x7AE1F11BL,(-1L)},{0xB8ACCB37L,0L,1L,0x2D0DBF52L},{0x60E2D043L,0x41A054B2L,0x830FB6EAL,(-4L)},{0L,(-1L),0L,2L},{(-9L),0L,3L,(-10L)}},{{0L,0x2D0DBF52L,0L,0L},{0x41A054B2L,0x8FB9928BL,0L,0x0CF1A441L},{0L,0x731C9F43L,3L,0x7AE1F11BL},{(-9L),0L,0L,(-3L)},{0L,(-3L),0x830FB6EAL,0L},{0x60E2D043L,(-9L),1L,0L},{0xB8ACCB37L,(-1L),0x7AE1F11BL,0xA2CE5981L},{0x4CB0245BL,0xB8ACCB37L,(-9L),(-1L)}},{{0x731C9F43L,0xBC9F03A0L,0xBC9F03A0L,0x731C9F43L},{1L,0xD450BA5CL,(-1L),(-9L)},{0xBBB0E83CL,0x0CF1A441L,(-10L),1L},{0xBC9F03A0L,0L,(-1L),1L},{1L,0x0CF1A441L,0xCE5C71E8L,(-9L)},{0x0D46BF51L,0xD450BA5CL,0x4CB0245BL,0x731C9F43L},{3L,0xBC9F03A0L,0x0D46BF51L,(-1L)},{0L,0xB8ACCB37L,0x731C9F43L,0xA2CE5981L}},{{(-4L),(-1L),(-5L),0L},{0x0CF1A441L,2L,0L,(-1L)},{0x7AE1F11BL,0x2D0DBF52L,0xCE5C71E8L,0x2D0DBF52L},{0x8FB9928BL,0xA2CE5981L,0x2D0DBF52L,1L},{1L,1L,(-9L),0x41A054B2L},{0x0D46BF51L,(-3L),0L,(-4L)},{0x0D46BF51L,(-5L),(-9L),0L},{1L,(-4L),0x2D0DBF52L,0xB8ACCB37L}},{{0x8FB9928BL,(-9L),0xCE5C71E8L,0x0CF1A441L},{0x7AE1F11BL,(-1L),0L,(-5L)},{0x41A054B2L,0L,0x01A3D290L,0x8FB9928BL},{0x0CF1A441L,0L,1L,0xBC9F03A0L},{0xA2CE5981L,0L,(-10L),(-10L)},{0x4CB0245BL,0x4CB0245BL,9L,1L},{(-10L),0L,1L,0L},{0L,0L,0x0D46BF51L,1L}},{{0x731C9F43L,0L,0L,0L},{0L,0L,1L,1L},{0xD450BA5CL,0x4CB0245BL,0x731C9F43L,(-10L)},{1L,0L,2L,0xBC9F03A0L},{9L,0L,1L,0x8FB9928BL},{0x830FB6EAL,0L,0xD450BA5CL,(-5L)},{1L,(-1L),3L,0x0CF1A441L},{0xBBB0E83CL,(-9L),0xBBB0E83CL,0xB8ACCB37L}}};
                        int i, j, k;
                        l_2677[4][2][3] = (safe_unary_minus_func_int16_t_s((safe_unary_minus_func_int8_t_s((g_359[(g_1129 + 1)][g_83] > g_188)))));
                    }
                }

                    l_1633 = (g_12 & (g_172[4] = ((l_1755 = ((((g_115 > (g_103 = (l_1754 = (g_359[9][0] == (safe_sub_func_int8_t_s_s((g_83 = l_1715), ((((-1L) < ((((l_1750 == l_1613) != g_315) | (safe_add_func_int32_t_s_s((safe_unary_minus_func_int16_t_s(g_543[0])), p_9))) < g_161)) | p_9) >= p_9))))))) > g_247) > p_9) | l_1715)) ^ g_974)));
                    for (l_1632 = 7; (l_1632 >= 0); l_1632 -= 1)
                    {
                        g_247 = 0L;
                        if (p_9)
                            continue;
                    }
                }
                g_247 = (safe_sub_func_int32_t_s_s((safe_sub_func_int32_t_s_s(p_9, (l_1760 | 0x6C03L))), p_9));
                for (l_1634 = 0; (l_1634 <= 2); l_1634 += 1)
                {
                    int32_t l_1788 = 0xE5B11C52L;
                    int i, j, k;

for (g_22 = 0; g_22 < 9; g_22++)
    {
        transparent_crc(g_2352[g_22], "g_2352[g_22]", l_982);
        if (l_982) printf("index = [%d]\n", g_22);

    };


                    if (((l_1735 = (((g_12 = g_949[l_1634][(l_1320 + 3)][l_1320]) == ((g_949[2][4][6] & (g_949[l_1634][(l_1320 + 3)][l_1320] || (((safe_mod_func_int16_t_s_s(((((l_1633 = l_1000[0][0]) & 0L) || p_9) != (p_9 > (l_1574[3][4][2] = ((+(safe_rshift_func_int8_t_s_s((!(((1UL <= g_172[1]) <= g_115) || 1L)), 3))) >= g_949[l_1634][(l_1320 + 3)][l_1320])))), g_115)) != p_9) || g_949[l_1634][(l_1320 + 3)][l_1320]))) || p_9)) > l_1767)) == 0xC8E730F8L))
                    {

if (g_173)
                break;

                    g_247 = l_1768;
                        if (g_1524)
                            break;
                    }
                    else
                    {
                        l_1788 = ((safe_lshift_func_int16_t_s_s((g_12 == (safe_lshift_func_int8_t_s_u(0xF6L, (l_1773 > p_9)))), g_188)) == (safe_lshift_func_int16_t_s_s((g_543[1] = ((safe_rshift_func_int16_t_s_u((((g_247 = (safe_mod_func_int16_t_s_s(((~(g_4 | ((!0x0772F407L) != (((safe_add_func_int32_t_s_s((safe_rshift_func_int16_t_s_u(0x8E70L, 14)), (safe_add_func_uint32_t_u_u(p_9, p_9)))) || 5UL) <= g_813[1][0])))) & g_866[4][0]), p_9))) == p_9) ^ (-8L)), g_359[3][1])) == g_1215[1])), 10)));
                    }
                    if (p_9)
                        {
{
            int32_t l_1044 = 0x5A13B012L;
            uint32_t l_1107 = 0x28F65E86L;
            int32_t l_1131 = (-4L);
            int8_t l_1145[5] = {0x88L,0x88L,0x88L,0x88L,0x88L};
            int i;
            for (l_1320 = 0; (l_1320 <= (-19)); --l_1320)
            {
                int32_t l_1012 = (-1L);
                uint16_t l_1029 = 0x9278L;
                l_1029 = (g_2476 = (safe_mod_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s((safe_mod_func_uint8_t_u_u(l_1012, g_543[1])), (((l_975[0][0] = (((!(~((safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u(l_1000[1][6], ((0x22L > (safe_rshift_func_uint8_t_u_u(250UL, 0))) <= ((safe_mod_func_int8_t_s_s((0x271358C7L <= ((safe_mod_func_int32_t_s_s((safe_add_func_int16_t_s_s(g_2476, ((safe_sub_func_uint32_t_u_u(5UL, (0x75D2E236L <= g_172[4]))) < 1L))), l_1320)) > g_866[4][0])), g_866[4][0])) == l_1320)))), l_1012)) | 0x106106EEL))) ^ g_1460) != 9L)) != (-5L)) < l_1320))), 0)) ^ g_2476), l_1320)));
                if (l_1012)
                    break;
                l_1044 = ((-2L) > (safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_s(((safe_rshift_func_int8_t_s_s(((safe_rshift_func_int8_t_s_u(0x7DL, 1)) > (safe_add_func_int32_t_s_s(0x5DAB9F54L, g_3421))), (4294967295UL > ((l_1000[1][6] == ((safe_sub_func_int32_t_s_s((i = l_1320), ((g_1460 > ((g_2420 <= l_1320) <= g_3957)) >= g_543[1]))) == l_1001)) ^ l_1000[1][6])))) ^ 0xF9C6D80AL), l_1631)) != l_1320), 0)), 0x7AL)));

{
                    uint16_t l_1253 = 0UL;
                    int32_t l_1273 = (-2L);
                    int32_t l_1289 = 0xC89C5942L;
                    int32_t l_1302 = (-10L);
                    for (g_12 = 0; (g_12 <= 6); g_12 += 1)
                    {
                        int32_t l_1269 = 1L;
                        int8_t l_1270 = 0xE8L;
                        int i, j;
                        l_1747 = ((((0xD12A6F93L ^ (safe_rshift_func_int8_t_s_s((safe_sub_func_int8_t_s_s(0xCBL, (safe_add_func_uint8_t_u_u(((safe_sub_func_int32_t_s_s(((((safe_sub_func_int32_t_s_s((((~((~(safe_lshift_func_uint8_t_u_u((g_359[(g_3781 + 3)][g_12] & (((safe_mod_func_uint8_t_u_u(l_1320, (safe_lshift_func_uint8_t_u_u(l_1320, 0)))) != ((safe_sub_func_int32_t_s_s((((safe_lshift_func_uint16_t_u_s(l_982, (safe_rshift_func_int16_t_s_s((((g_103 = ((safe_rshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(0L, (safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s(l_1377, (j = (safe_add_func_uint32_t_u_u((l_1320 == l_1320), l_1253))))), 4294967295UL)))), l_1633)), 0)) == l_1320)) && l_1320) != 9UL), 1)))) & g_813[1][0]) | l_1320), l_1320)) & 0x62L)) & l_975[2][0])), l_1320))) | 0xCD8BL)) >= g_12) & g_172[8]), l_1377)) & g_12) && g_359[(g_3781 + 3)][g_3781]) < l_1320), l_1253)) == g_2598), g_3957)))), l_1029))) < g_1215[5]) & l_1320) >= 0xB0L);
                        l_1273 = ((((!((j = (g_3421 = (((((safe_lshift_func_int8_t_s_u(l_1320, 4)) | g_103) < (l_1747 = ((((safe_sub_func_uint16_t_u_u((g_103 && (l_1269 = (safe_sub_func_uint16_t_u_u(((((+g_103) < g_3421) == ((safe_mod_func_int16_t_s_s((l_982 = g_2710), ((0xA9L < ((-5L) || (l_1029 > g_2710))) | g_3421))) != 0x7EL)) > l_1001), l_1320)))), g_866[4][3])) <= 0x15L) == 0x3FL) != g_247))) & l_1270) ^ g_1524))) < l_1180)) <= g_2710) != g_359[(g_3781 + 3)][g_12]) && g_12);
                        j = (g_103 < l_1320);
                    }
                    l_1289 = (safe_add_func_int32_t_s_s(l_1956, (0x5AL < ((safe_sub_func_uint8_t_u_u((g_12 = (l_975[0][0] = (safe_add_func_int32_t_s_s((((((l_1180 <= ((((0x583DL || (l_975[1][0] < (safe_mod_func_uint16_t_u_u(g_866[4][0], g_949[2][8][0])))) & (safe_rshift_func_int8_t_s_s(((l_982 = l_1320) > ((((((safe_mod_func_int32_t_s_s((l_1273 = ((safe_rshift_func_uint8_t_u_s(j, 3)) > g_866[6][4])), l_1253)) != l_975[0][0]) == 0xCF9AL) ^ l_1253) != j) > l_1320)), 7))) <= l_1320) != l_1320)) ^ l_1747) <= g_866[7][6]) ^ 0L) | g_359[7][6]), g_3957)))), g_949[0][6][1])) | 0x1EL))));
                    for (l_1289 = 0; (l_1289 <= 0); l_1289 += 1)
                    {
                        int i, j;
                        l_1633 = ((l_975[(l_1289 + 2)][l_1289] == (-1L)) < l_21);
                        l_1273 = (g_3421 | (!((((((safe_sub_func_uint8_t_u_u((j == (((safe_rshift_func_int8_t_s_s(((l_1747 | ((safe_sub_func_int8_t_s_s(l_1320, l_1273)) | ((l_1029 = (safe_sub_func_uint16_t_u_u((((+((g_543[1] | ((((g_22 = (0x796B303EL == (safe_mod_func_uint8_t_u_u((l_1302 ^ (safe_sub_func_int32_t_s_s(l_982, 0x7FEAD647L))), l_1320)))) & g_3781) & l_1302) | 1L)) >= l_1320)) && 0L) & g_949[0][6][1]), g_3781))) && g_540))) ^ 0x36C9L), l_1633)) <= l_1289) && g_1215[4])), g_103)) > j) <= (-1L)) <= l_1320) == 2L) || l_1320)));
                        if (l_1273)
                            continue;
                        j = (-1L);
                    }
                }

                    g_2476 = (+1UL);
            }
            if ((l_1320 ^ 0xE840E5A7L))
            {
                uint32_t l_1048[4];
                int32_t l_1051 = 0x370D4B7EL;
                int16_t l_1078 = 1L;
                int i;
                for (i = 0; i < 4; i++)
                    {
{
                        int16_t l_2482 = 0xC29FL;
                        l_1051 = (l_2482 >= (safe_add_func_uint16_t_u_u((g_3484 == l_1634), 0x0D89L)));
                        l_1574[5][4][4] = l_1631;
                    }

                    l_1048[i] = 0x5311DC50L;}
                g_2476 = (l_1044 = l_1320);
                l_1051 = ((safe_rshift_func_uint16_t_u_u(l_1048[3], (safe_lshift_func_uint16_t_u_s(l_1320, 5)))) == 1L);
                g_2476 = (((safe_lshift_func_uint16_t_u_u(((((g_1460 == (safe_add_func_int8_t_s_s(0x85L, (g_866[4][0] & g_813[1][0])))) < (l_1044 == (safe_mod_func_int16_t_s_s(0x3447L, ((safe_mod_func_int16_t_s_s((((!(safe_lshift_func_int16_t_s_u(((((safe_sub_func_int16_t_s_s((safe_mod_func_int32_t_s_s(((safe_lshift_func_uint8_t_u_u((safe_mod_func_int32_t_s_s((safe_lshift_func_int8_t_s_s(((safe_add_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(l_1320, g_1460)), l_1320)) ^ l_975[0][0]), g_3957)), g_543[1])), l_1320)) && l_1000[1][6]), 0x2EBCD1D0L)), l_1956)) == l_1320) | l_975[0][0]) || l_1078), l_1320))) != g_172[2]) < 3UL), l_1320)) && l_1632))))) != l_1320) != g_813[1][0]), 13)) != g_3957) && g_2420);
                g_2476 = (!(0x4D452E28L | (-10L)));
            }
            else
            {
                int8_t l_1088 = 0x48L;
                int32_t l_1123 = 1L;
                int8_t l_1128 = 0x8FL;
                int32_t l_1130 = 0L;
                uint16_t l_1155 = 65535UL;
                int32_t l_1156 = (-1L);
                if ((((l_1956 = (g_172[4] = (2UL ^ ((i = 0xCC4D0FF6L) != ((l_1271 && (0x2DL < ((safe_mod_func_int8_t_s_s((safe_add_func_uint8_t_u_u(g_543[1], g_866[4][0])), (0xAE74A061L ^ ((safe_rshift_func_int16_t_s_u((safe_add_func_int8_t_s_s(l_1088, 0x82L)), 8)) <= 7L)))) != 7L))) > l_1088))))) & l_1320) > l_1271))
                {
                    uint32_t l_1106 = 0xA3E081EAL;
                    int32_t l_1108 = 0xB45B4023L;
                    int32_t l_1109 = 0L;
                    int32_t l_1115 = (-1L);

if (k)
                            break;

                    l_1109 = ((0xA991L ^ (safe_add_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((l_1320 != g_172[6]), (((safe_add_func_uint32_t_u_u((((((((l_1108 = (g_172[4] != (safe_lshift_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u(((((l_1320 || (safe_add_func_uint32_t_u_u(g_1460, l_1320))) && (+((l_1107 = (safe_mod_func_uint8_t_u_u((((((safe_rshift_func_uint16_t_u_s(65535UL, l_1320)) >= g_813[1][0]) == 0xF230L) ^ l_1106) || 0xC3E97BBAL), g_2420))) && l_1044))) | l_1320) || 0x739D4E79L), l_1632)), 12)))) ^ 0x430FL) == 0L) | l_1320) == 4L) > 251UL) && 0x54700F55L), 1UL)) | l_1044) < 4294967286UL))), l_1106))) > l_1320);
                    l_1747 = (0xFAL == (safe_add_func_uint8_t_u_u(1UL, (~(safe_add_func_int16_t_s_s(l_1320, ((l_1115 = l_1956) >= (l_1044 = (0L >= ((l_1001 | ((l_1109 = l_1271) | (safe_unary_minus_func_int16_t_s((l_1320 | ((safe_add_func_uint32_t_u_u(g_2420, 0x6120F022L)) >= l_1320)))))) == 0UL))))))))));
                    l_1747 = ((safe_add_func_int32_t_s_s(l_1320, (l_1123 = (safe_lshift_func_int16_t_s_u(g_949[0][6][1], 10))))) != (l_1000[1][6] = ((1UL & (l_1747 = (((l_1320 || (0L <= (l_1131 = (l_1130 = (((safe_sub_func_int32_t_s_s(g_813[3][0], ((g_1460 = ((((safe_add_func_int8_t_s_s((l_1044 = ((((((0x465FL >= (g_315 ^ (((l_1320 & l_1320) != l_1271) < l_1320))) > l_1747) | l_1956) && l_1128) | 0xEB927AC1L) & g_2476)), l_1320)) > 0x9521L) ^ l_1747) < g_949[0][6][1])) | l_975[1][0]))) <= g_3781) | 0x0D803776L))))) <= l_1088) || 1UL))) | g_2476)));
                }
                else
                {
                    int8_t l_1144 = (-6L);
                    int32_t l_1154 = 0x21380E4FL;

if (g_247)
                        break;

                    if (g_813[6][0])
                    {
                        return g_949[1][4][6];
                    }
                    else
                    {
                        uint32_t l_1143 = 0x014BF0E5L;
                        l_1123 = (((safe_mod_func_uint8_t_u_u((safe_add_func_int8_t_s_s((l_1747 >= ((l_1632 = ((~(g_172[1] >= (l_1143 = ((g_2476 & 0xDCL) == (((0L < g_3957) | ((l_1320 || l_1320) ^ ((safe_sub_func_uint16_t_u_u((safe_add_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((l_1271 | g_359[6][2]), g_813[1][0])), g_172[5])), 1UL)) == 0x6786L))) == l_1320))))) ^ l_1320)) != l_1144)), 0L)), l_1144)) || 0x11CFL) && l_1320);
                        l_1145[2] = (-1L);
                        l_1130 = (0UL ^ ((safe_lshift_func_uint8_t_u_u((g_3421 = (((safe_add_func_uint32_t_u_u(((0x27L == ((((l_1000[1][6] = l_1320) > (((((l_1631 > (g_949[0][6][1] || (+(l_1747 = ((((l_1320 <= ((l_1154 = ((((0x36L != l_1956) && (safe_add_func_uint8_t_u_u(((g_1460 < (-9L)) && g_359[9][0]), l_1123))) <= l_1001) > 0x0CA7DFD0L)) > 251UL)) | l_1130) && l_1320) || l_1632))))) == l_1320) && (-1L)) || l_1001) <= 8UL)) <= l_1631) | 65531UL)) != g_359[1][2]), l_1088)) >= l_1320) || g_813[4][0])), 5)) == l_1155));
                        g_2476 = ((((g_3957 = g_3421) & l_1156) || g_3957) < l_1145[2]);
                    }
                }
                g_2476 = ((safe_add_func_uint16_t_u_u(((g_543[1] = ((l_1000[1][6] = g_2420) <= ((+((safe_sub_func_uint32_t_u_u(((((safe_sub_func_uint32_t_u_u((g_949[0][6][1] > ((safe_unary_minus_func_uint32_t_u(l_1320)) < ((((((((safe_sub_func_uint32_t_u_u((g_3258 >= (l_1747 > l_1773)), i)) < ((safe_mod_func_uint8_t_u_u(((g_172[7] || (((safe_sub_func_uint32_t_u_u((l_975[2][0] = (safe_sub_func_int8_t_s_s((g_22 = (g_3484 = ((safe_unary_minus_func_int16_t_s(((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u(((~((l_1320 == 0x622C1845L) != g_315)) > l_1956), l_1320)), g_543[1])) & l_1320))) | l_1320))), g_359[2][4]))), l_1001)) != l_1320) | 0x60L)) >= l_1613), l_1001)) || 0xB777L)) <= g_2420) | l_1320) <= l_1320) | l_1747) ^ 251UL) != 0UL))), 0L)) != l_1128) ^ l_1747) == g_543[1]), 0L)) == l_1320)) <= 1UL))) <= l_1747), 0UL)) || l_1320);
                for (g_315 = 0; (g_315 == 37); g_315 = safe_add_func_int8_t_s_s(g_315, 1))
                {
                    int16_t l_1184[7][10] = {{0x0584L,0xF49AL,0x0584L,0x1CAEL,0x1CAEL,(-9L),0x691FL,(-9L),0x0584L,0x0584L},{(-9L),0x691FL,(-9L),0x0584L,0x0584L,(-9L),0x691FL,(-9L),0x0584L,0x0584L},{(-9L),0x691FL,(-9L),0x0584L,0x0584L,(-9L),0x691FL,(-9L),0x0584L,0x0584L},{(-9L),0x691FL,(-9L),0x0584L,0x0584L,(-9L),0x691FL,(-9L),0x0584L,0x0584L},{(-9L),0x691FL,(-9L),0x0584L,0x0584L,(-9L),0x691FL,(-9L),0x0584L,0x0584L},{(-9L),0x691FL,(-9L),0x0584L,0x0584L,(-9L),0x691FL,(-9L),0x0584L,0x0584L},{(-9L),0x691FL,(-9L),0x0584L,0x0584L,(-9L),0x691FL,(-9L),0x0584L,0x0584L}};
                    int i, j;
                    l_1000[1][6] = (((!l_1184[5][5]) == ((g_3781 = g_866[4][0]) | (~250UL))) && ((g_949[0][6][1] >= ((l_1320 > ((safe_add_func_uint32_t_u_u((l_1145[3] & l_1320), ((safe_unary_minus_func_int32_t_s((safe_add_func_uint8_t_u_u((g_1460 = (l_1044 = l_1107)), (0x10F80FA5L || l_1131))))) == l_1130))) > l_1320)) ^ l_1320)) != g_172[4]));
                }
            }
        }

                    break;}
                    l_1633 = 0x0D52A060L;
                    return l_1374[1];
                }
            }
        }
    }
    else
    {
        uint16_t l_1806 = 0xCFCDL;
        int32_t l_1813 = 0xA2F6670EL;
        int8_t l_1829 = 0xF1L;
        int32_t l_1866[3][9] = {{(-1L),0x50DE20A4L,(-1L),0x684B7A88L,0xFFD23646L,0x69C74DB6L,0xC9D6D157L,1L,1L},{0x5130844BL,0x50DE20A4L,1L,0xFFD23646L,1L,0x50DE20A4L,0x5130844BL,0xC9D6D157L,0x703A697CL},{0xC9D6D157L,0x69C74DB6L,0xFFD23646L,0x684B7A88L,(-1L),0x50DE20A4L,(-1L),0x684B7A88L,0xFFD23646L}};
        int32_t l_1867 = 0x9412EF4CL;
        uint32_t l_1954[5][7][5] = {{{18446744073709551615UL,0x2D7E9CF2L,0x99BF8AD8L,0xDE233414L,18446744073709551615UL},{18446744073709551612UL,1UL,8UL,0UL,0xBB8041F1L},{0x214A9EA3L,0xDA497574L,0UL,0x2D7E9CF2L,18446744073709551615UL},{0xA197DEFCL,0UL,0UL,0xA197DEFCL,0xFDB24C69L},{18446744073709551615UL,0x70947AEBL,0xAB58004CL,0x177B7774L,0UL},{18446744073709551613UL,4UL,0xBB8041F1L,0xFDB24C69L,0x5483EC4DL},{0x99BF8AD8L,1UL,18446744073709551609UL,18446744073709551615UL,0x8EDD1C86L}},{{1UL,18446744073709551613UL,1UL,1UL,0x4BE9CFC3L},{18446744073709551615UL,0x70947AEBL,0x107B98D8L,0x5A88219EL,0xAB58004CL},{0xA197DEFCL,18446744073709551612UL,4UL,0UL,18446744073709551615UL},{0x7DF9D7B6L,18446744073709551615UL,0x107B98D8L,18446744073709551612UL,0x107B98D8L},{0xBB8041F1L,0xBB8041F1L,1UL,0UL,0xFDB24C69L},{0UL,0x0E457A2DL,18446744073709551609UL,1UL,0x6F310635L},{18446744073709551609UL,0x5483EC4DL,0xBB8041F1L,8UL,18446744073709551608UL}},{{1UL,0x0E457A2DL,0x99BF8AD8L,0x099BD9B8L,1UL},{18446744073709551615UL,0xBB8041F1L,0UL,0xA197DEFCL,0x1231ACB6L},{2UL,18446744073709551615UL,0UL,0xDE233414L,0UL},{0UL,18446744073709551612UL,18446744073709551608UL,0x5483EC4DL,1UL},{2UL,0x70947AEBL,0UL,0x70947AEBL,2UL},{18446744073709551615UL,18446744073709551613UL,1UL,18446744073709551608UL,0xBB8041F1L},{1UL,1UL,0xAB58004CL,18446744073709551607UL,0x862F632DL}},{{18446744073709551609UL,4UL,0x86D70A80L,18446744073709551613UL,0xBB8041F1L},{0UL,18446744073709551607UL,18446744073709551615UL,0x38C0BC05L,2UL},{0xBB8041F1L,0UL,0xA197DEFCL,0x1231ACB6L,1UL},{0x7DF9D7B6L,0x756BE40BL,0x214A9EA3L,0xDA497574L,0UL},{0xA197DEFCL,1UL,18446744073709551612UL,0x1231ACB6L,0x1231ACB6L},{18446744073709551615UL,0x5A88219EL,18446744073709551615UL,0x38C0BC05L,1UL},{1UL,0UL,0xFDB24C69L,18446744073709551613UL,18446744073709551608UL}},{{0x99BF8AD8L,0xE90C99D2L,2UL,18446744073709551607UL,0x6F310635L},{18446744073709551613UL,0x1231ACB6L,0xFDB24C69L,18446744073709551608UL,0xFDB24C69L},{0x214A9EA3L,0x5478B9A4L,18446744073709551615UL,0x70947AEBL,0x107B98D8L},{1UL,0x4BE9CFC3L,18446744073709551612UL,0x5483EC4DL,18446744073709551615UL},{0x862F632DL,1UL,0x214A9EA3L,0xDE233414L,0xAB58004CL},{8UL,0x4BE9CFC3L,0xA197DEFCL,0xA197DEFCL,0x4BE9CFC3L},{0x6F310635L,0x5478B9A4L,18446744073709551615UL,0x099BD9B8L,0x8EDD1C86L}}};
        uint32_t l_2001 = 0x2D326036L;
        uint8_t l_2002 = 0x26L;
        int16_t l_2117[2][6][4] = {{{(-10L),0L,0L,0L},{0x0FD9L,0x0FD9L,0x74D4L,0L},{0L,(-10L),0x74D4L,(-10L)},{0x0FD9L,0x0E78L,0L,0x74D4L},{(-10L),0x0E78L,0x0E78L,(-10L)},{0x0E78L,(-10L),0x0FD9L,0L}},{{0x0E78L,0x0FD9L,0x0E78L,0L},{(-10L),0L,0L,0L},{0x0FD9L,0x0FD9L,0x74D4L,0L},{0L,(-10L),0x74D4L,(-10L)},{(-5L),0L,0x74D4L,0x0FD9L},{0x0E78L,0L,0L,0x0E78L}}};
        int32_t l_2155 = 0xBD390F35L;
        uint16_t l_2179 = 0UL;
        uint16_t l_2239[9][7][4] = {{{8UL,0x260EL,0xC0A7L,65526UL},{0xE758L,4UL,65526UL,0UL},{65526UL,0UL,65532UL,0UL},{0x9015L,4UL,1UL,65526UL},{9UL,0x260EL,0UL,0x3A76L},{1UL,0x9015L,8UL,8UL},{1UL,1UL,0UL,8UL}},{{9UL,8UL,1UL,0x260EL},{0x9015L,0xE758L,65532UL,1UL},{65526UL,0xE758L,65526UL,0x260EL},{0xE758L,8UL,0xC0A7L,8UL},{8UL,1UL,0x9015L,8UL},{0x3A76L,0x9015L,0x9015L,0x3A76L},{8UL,0x260EL,0xC0A7L,65526UL}},{{0xE758L,4UL,65526UL,0UL},{65526UL,0UL,65532UL,0UL},{0x9015L,4UL,1UL,65526UL},{9UL,0x260EL,0UL,0x3A76L},{1UL,0x9015L,8UL,8UL},{1UL,1UL,0UL,8UL},{9UL,8UL,1UL,0x260EL}},{{0x9015L,0xE758L,65532UL,1UL},{65526UL,0xE758L,65526UL,0x260EL},{0xE758L,8UL,0xC0A7L,8UL},{8UL,1UL,0x9015L,8UL},{0x3A76L,0x9015L,0x9015L,0x3A76L},{8UL,0x260EL,0xC0A7L,65526UL},{0xE758L,4UL,65526UL,0UL}},{{65526UL,0UL,65532UL,0UL},{0x9015L,4UL,1UL,65526UL},{9UL,0x260EL,0UL,0x3A76L},{1UL,0x9015L,8UL,8UL},{1UL,1UL,0UL,8UL},{9UL,8UL,1UL,0x260EL},{0x9015L,0xE758L,65532UL,1UL}},{{65526UL,0xE758L,65526UL,0x260EL},{0xE758L,8UL,0xC0A7L,8UL},{8UL,1UL,0x9015L,8UL},{0x3A76L,0x9015L,0x9015L,0x3A76L},{8UL,0x260EL,0xC0A7L,65526UL},{0xE758L,4UL,65526UL,0UL},{65526UL,0UL,65532UL,0UL}},{{0x9015L,4UL,1UL,65526UL},{9UL,0x260EL,0UL,0x3A76L},{1UL,0x9015L,8UL,8UL},{1UL,1UL,0UL,0x260EL},{65526UL,0x9015L,0UL,4UL},{0x3A76L,8UL,9UL,0UL},{8UL,8UL,8UL,4UL}},{{8UL,0x9015L,65532UL,0x260EL},{0x260EL,0UL,0x3A76L,0x9015L},{1UL,0x3A76L,0x3A76L,1UL},{0x260EL,4UL,65532UL,8UL},{8UL,0xC0A7L,8UL,0xE758L},{8UL,0xE758L,9UL,0xE758L},{0x3A76L,0xC0A7L,0UL,8UL}},{{65526UL,4UL,0xE758L,1UL},{0UL,0x3A76L,0x9015L,0x9015L},{0UL,0UL,0xE758L,0x260EL},{65526UL,0x9015L,0UL,4UL},{0x3A76L,8UL,9UL,0UL},{8UL,8UL,8UL,4UL},{8UL,0x9015L,65532UL,0x260EL}}};
        int i, j, k;
        if (((0x5CL == ((((safe_lshift_func_int16_t_s_u((safe_add_func_int16_t_s_s(g_949[0][1][6], ((+((safe_rshift_func_int8_t_s_u(((safe_mod_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((safe_add_func_int32_t_s_s((safe_sub_func_int32_t_s_s((safe_add_func_int8_t_s_s(((((((g_543[1] > g_361) && l_1806) == (l_1813 = (p_9 || (safe_mod_func_uint32_t_u_u(4294967291UL, (((-5L) == (safe_mod_func_uint8_t_u_u(((l_27 = (safe_rshift_func_uint16_t_u_u(g_543[1], 4))) || 0xCFD8L), l_1001))) && g_1524)))))) <= l_1806) != l_1806) || l_1813), 1UL)), 4294967295UL)), g_866[7][7])), g_359[9][0])), 0xFDL)) && g_949[0][6][1]), 2)) >= 0x3C4F9398L)) <= l_1806))), 14)) <= l_1806) >= g_1215[1]) >= p_9)) != g_22))
        {
            int16_t l_1822 = 7L;
            int32_t l_1832[5] = {0x86755FF3L,0x86755FF3L,0x86755FF3L,0x86755FF3L,0x86755FF3L};
            int8_t l_1833 = 0xBDL;
            int i;
            for (g_12 = (-5); (g_12 <= 11); ++g_12)
            {
                for (g_538 = 28; (g_538 != 11); g_538 = safe_sub_func_uint32_t_u_u(g_538, 3))
                {
                    l_26 = 0x97E65834L;
                }
            }
            l_1833 = ((safe_add_func_uint16_t_u_u(p_9, (l_1813 = ((~(((+l_1822) == ((safe_sub_func_int8_t_s_s((g_83 = ((((l_975[2][0] || (safe_lshift_func_uint16_t_u_u(((safe_lshift_func_uint8_t_u_u((l_26 >= 0xFDL), 7)) >= ((((l_975[0][0] = l_1829) == 0x5AL) || (safe_add_func_int32_t_s_s((g_247 = ((((0x7CL < p_9) > g_540) >= 0x9A6EDC86L) | 1UL)), g_866[0][7]))) > g_4)), 13))) | 1UL) >= p_9) & l_1832[3])), g_540)) != 0x6D9DL)) > p_9)) > l_1180)))) && g_247);
        }
        else
        {
            int16_t l_1839 = (-8L);
            int32_t l_1848 = 1L;
            int32_t l_1849 = 0xE7F06EBBL;
            uint8_t l_1955[3];
            int32_t l_2020 = 7L;
            uint16_t l_2112 = 0xEC38L;
            uint16_t l_2240 = 0UL;
            uint32_t l_2247[3][1][10] = {{{0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L}},{{0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L}},{{0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L}}};
            int i, j, k;

for (l_2155 = 0; l_2155 < 1; l_2155++)
            l_975[l_26][l_2155] = 0x717E753EL;


for (g_2576 = 0; g_2576 < 9; g_2576++)
            {
                transparent_crc(g_949[g_3152][g_541][g_2576], "g_949[g_3152][g_541][g_2576]", l_26);
                if (l_26) printf("index = [%d][%d][%d]\n", g_3152, g_541, g_2576);

            };


                    for (i = 0; i < 3; i++)
                l_1955[i] = 0x9CL;
            if (((safe_mod_func_int16_t_s_s((((l_1836 == ((l_1849 = (safe_rshift_func_int8_t_s_u((l_1813 > ((l_1839 != (((g_22 <= ((0x097CL && ((safe_add_func_uint16_t_u_u(l_1806, (+(+((safe_rshift_func_int16_t_s_u(0L, 5)) || (((((l_1848 = (((0x72L >= (safe_mod_func_int16_t_s_s(l_1768, 0x6688L))) >= 0xAEDFL) > 0x188CL)) == g_83) | p_9) & p_9) & p_9)))))) != p_9)) >= l_1806)) < 0xA6CCL) < (-8L))) == g_1215[4])), 0))) != 0x72L)) == g_1129) && 4294967291UL), 0xBE51L)) | g_1215[4]))
            {
                int32_t l_1863 = 1L;
                int32_t l_1868[4] = {0x44B6E1A3L,0x44B6E1A3L,0x44B6E1A3L,0x44B6E1A3L};
                int i;
                g_247 = (safe_mod_func_int32_t_s_s((((safe_lshift_func_int16_t_s_s((p_9 = (!g_103)), l_1077)) > (((l_1867 = (safe_add_func_uint16_t_u_u(((0x88144887L & (((l_1848 = ((l_1863 = (l_1866[0][4] = (safe_sub_func_uint16_t_u_u(0xBA9AL, (safe_add_func_uint8_t_u_u((l_1806 | 0xC033B429L), ((safe_lshift_func_int16_t_s_u(l_1863, 9)) <= (l_26 = (l_1813 = (safe_rshift_func_uint8_t_u_s((7UL != (g_161 = (l_1849 = (l_1863 | 0L)))), 7))))))))))) != l_1839)) && l_21) ^ g_173)) | l_1434), 0xBEE9L))) < g_359[9][0]) && l_1806)) || g_217), l_1868[2]));
                for (p_9 = 0; (p_9 < 2); p_9 = safe_add_func_uint8_t_u_u(p_9, 1))
                {

if (k)
                        break;

                    return g_217;
                }
                l_1848 = ((safe_add_func_int8_t_s_s(l_1849, l_1359[2])) && (safe_rshift_func_int16_t_s_u((g_866[4][0] = (safe_sub_func_uint32_t_u_u(l_1849, 0x58CB39AAL))), 10)));
                if (((((safe_mod_func_int32_t_s_s(((0x07L | (p_9 || 0UL)) & (65528UL ^ (safe_mod_func_int32_t_s_s(((safe_add_func_int8_t_s_s((((((0x28L == ((safe_rshift_func_uint8_t_u_s((safe_rshift_func_uint16_t_u_s((safe_add_func_uint16_t_u_u((((safe_sub_func_int16_t_s_s(g_949[0][6][1], (safe_mod_func_int32_t_s_s(p_9, (0x8DB1L ^ l_1806))))) > l_1848) | 0xD61FL), g_103)), 0)), p_9)) | l_1760)) != 0x6205774BL) != (-1L)) && g_541) ^ p_9), l_27)) & 0x5FL), p_9)))), (-1L))) != p_9) ^ g_361) >= g_866[4][0]))
                {
                    int32_t l_1914 = 6L;
                    int32_t l_1935[9][9] = {{1L,(-8L),7L,0xD35C264CL,0xD35C264CL,7L,(-8L),1L,(-1L)},{0xC213583BL,0xD35C264CL,1L,1L,0x740A6CC5L,0xE38A8284L,(-8L),0x740A6CC5L,0xB1227660L},{4L,0xC213583BL,1L,0L,(-8L),1L,0x4B16B3AEL,0xE35208FFL,(-1L)},{0L,0xC213583BL,(-1L),(-8L),0xE35208FFL,(-5L),0L,0x4B16B3AEL,1L},{0x4B16B3AEL,0xD35C264CL,0xE38A8284L,0L,4L,(-5L),4L,0L,0xE38A8284L},{(-8L),(-8L),(-9L),1L,(-10L),1L,0xC213583BL,0x4B16B3AEL,(-5L)},{(-8L),0L,1L,0xD35C264CL,0L,0xE38A8284L,1L,0xE35208FFL,0xB0495FE9L},{0x4B16B3AEL,0L,(-9L),(-5L),0L,7L,(-5L),0x740A6CC5L,(-4L)},{0L,0x3D793A73L,0xE38A8284L,4L,(-10L),(-4L),1L,1L,(-4L)}};
                    int i, j;
                    if (l_1848)
                    {
                        int8_t l_1895 = 0xD3L;
                        uint8_t l_1934 = 252UL;
                        g_247 = 0x515FE230L;
                        l_1914 = (safe_add_func_int16_t_s_s(l_1895, ((safe_mod_func_uint8_t_u_u(p_9, (((p_9 <= ((safe_sub_func_int8_t_s_s((safe_mod_func_uint16_t_u_u(p_9, (safe_mod_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_s((safe_sub_func_int16_t_s_s(((g_161 < ((safe_add_func_int32_t_s_s((g_315 | ((safe_mod_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((((g_540 = p_9) >= 4294967291UL) >= (g_866[4][3] = (0x0086L >= 0xCFBCL))), (-1L))), g_12)) ^ p_9)), p_9)) || 0xA6L)) != 0x72141EEEL), l_1813)), 2)) == p_9), g_22)))), 2L)) == l_21)) >= l_21) && p_9))) >= g_1460)));

{
            int16_t l_1839 = (-8L);
            int32_t l_1848 = 1L;
            int32_t l_1849 = 0xE7F06EBBL;
            uint8_t l_1955[3];
            int32_t l_2020 = 7L;
            uint16_t l_2112 = 0xEC38L;
            uint16_t l_2240 = 0UL;
            uint32_t l_2247[3][1][10] = {{{0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L}},{{0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L}},{{0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L,0x87E54647L}}};
            int i, j, k;
            for (i = 0; i < 3; i++)
                l_1955[i] = 0x9CL;
            if (((safe_mod_func_int16_t_s_s((((g_2576 == ((l_1849 = (safe_rshift_func_int8_t_s_u((g_3484 > ((l_1839 != (((l_1914 <= ((0x097CL && ((safe_add_func_uint16_t_u_u(l_2240, (+(+((safe_rshift_func_int16_t_s_u(0L, 5)) || (((((l_1848 = (((0x72L >= (safe_mod_func_int16_t_s_s(g_2476, 0x6688L))) >= 0xAEDFL) > 0x188CL)) == g_4) | g_188) & g_188) & g_188)))))) != g_188)) >= l_2240)) < 0xA6CCL) < (-8L))) == g_1215[4])), 0))) != 0x72L)) == g_1129) && 4294967291UL), 0xBE51L)) | g_1215[4]))
            {
                int32_t l_1863 = 1L;
                int32_t l_1868[4] = {0x44B6E1A3L,0x44B6E1A3L,0x44B6E1A3L,0x44B6E1A3L};
                int i;
                j = (safe_mod_func_int32_t_s_s((((safe_lshift_func_int16_t_s_s((g_188 = (!g_3957)), l_2112)) > (((g_541 = (safe_add_func_uint16_t_u_u(((0x88144887L & (((l_1848 = ((l_1863 = (l_1866[0][4] = (safe_sub_func_uint16_t_u_u(0xBA9AL, (safe_add_func_uint8_t_u_u((l_2240 | 0xC033B429L), ((safe_lshift_func_int16_t_s_u(l_1863, 9)) <= (l_26 = (g_3484 = (safe_rshift_func_uint8_t_u_s((7UL != (g_3957 = (l_1849 = (l_1863 | 0L)))), 7))))))))))) != l_1839)) && l_1077) ^ g_173)) | g_3409), 0xBEE9L))) < g_359[9][0]) && l_2240)) || g_12), l_1868[2]));
                for (g_188 = 0; (g_188 < 2); g_188 = safe_add_func_uint8_t_u_u(g_188, 1))
                {
                    return g_12;
                }
                l_1848 = ((safe_add_func_int8_t_s_s(l_1849, l_1359[2])) && (safe_rshift_func_int16_t_s_u((g_866[4][0] = (safe_sub_func_uint32_t_u_u(l_1849, 0x58CB39AAL))), 10)));
                if (((((safe_mod_func_int32_t_s_s(((0x07L | (g_188 || 0UL)) & (65528UL ^ (safe_mod_func_int32_t_s_s(((safe_add_func_int8_t_s_s((((((0x28L == ((safe_rshift_func_uint8_t_u_s((safe_rshift_func_uint16_t_u_s((safe_add_func_uint16_t_u_u((((safe_sub_func_int16_t_s_s(g_949[0][6][1], (safe_mod_func_int32_t_s_s(g_188, (0x8DB1L ^ l_2240))))) > l_1848) | 0xD61FL), g_3957)), 0)), g_188)) | g_3957)) != 0x6205774BL) != (-1L)) && j) ^ g_188), g_247)) & 0x5FL), g_188)))), (-1L))) != g_188) ^ g_3781) >= g_866[4][0]))
                {
                    int32_t l_1914 = 6L;
                    int32_t l_1935[9][9] = {{1L,(-8L),7L,0xD35C264CL,0xD35C264CL,7L,(-8L),1L,(-1L)},{0xC213583BL,0xD35C264CL,1L,1L,0x740A6CC5L,0xE38A8284L,(-8L),0x740A6CC5L,0xB1227660L},{4L,0xC213583BL,1L,0L,(-8L),1L,0x4B16B3AEL,0xE35208FFL,(-1L)},{0L,0xC213583BL,(-1L),(-8L),0xE35208FFL,(-5L),0L,0x4B16B3AEL,1L},{0x4B16B3AEL,0xD35C264CL,0xE38A8284L,0L,4L,(-5L),4L,0L,0xE38A8284L},{(-8L),(-8L),(-9L),1L,(-10L),1L,0xC213583BL,0x4B16B3AEL,(-5L)},{(-8L),0L,1L,0xD35C264CL,0L,0xE38A8284L,1L,0xE35208FFL,0xB0495FE9L},{0x4B16B3AEL,0L,(-9L),(-5L),0L,7L,(-5L),0x740A6CC5L,(-4L)},{0L,0x3D793A73L,0xE38A8284L,4L,(-10L),(-4L),1L,1L,(-4L)}};
                    int i, j;
                    if (l_1848)
                    {
                        int8_t l_1895 = 0xD3L;
                        uint8_t l_1934 = 252UL;
                        j = 0x515FE230L;
                        l_1914 = (safe_add_func_int16_t_s_s(l_1895, ((safe_mod_func_uint8_t_u_u(g_188, (((g_188 <= ((safe_sub_func_int8_t_s_s((safe_mod_func_uint16_t_u_u(g_188, (safe_mod_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_s((safe_sub_func_int16_t_s_s(((g_3957 < ((safe_add_func_int32_t_s_s((g_3261 | ((safe_mod_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((((g_3957 = g_188) >= 4294967291UL) >= (g_866[4][3] = (0x0086L >= 0xCFBCL))), (-1L))), g_217)) ^ g_188)), g_188)) || 0xA6L)) != 0x72141EEEL), g_3484)), 2)) == g_188), l_1914)))), 2L)) == l_1077)) >= l_1077) && g_188))) >= g_1129)));
                        l_1935[4][2] = (((safe_sub_func_int8_t_s_s(((safe_rshift_func_int8_t_s_u(g_217, (safe_lshift_func_int8_t_s_s((~(g_3957 ^ ((g_813[1][0] < g_361) != ((5UL >= (safe_lshift_func_uint16_t_u_u(((safe_mod_func_int8_t_s_s((g_12 >= (l_2240 = (l_1866[0][4] = (safe_lshift_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(((((safe_rshift_func_int16_t_s_s((l_1895 | (safe_mod_func_int32_t_s_s((0x4FA3L & 0L), 0x3F21BD3AL))), 8)) != 0x5BC70887L) <= 0x27L) & 0xB13EF641L), l_1914)), l_1180))))), g_188)) ^ l_1914), l_1934))) <= g_188)))), 6)))) || g_949[0][0][2]), (-7L))) <= g_359[9][0]) ^ 1UL);
                    }
                    else
                    {
                        return l_975[0][0];
                    }
                    for (l_1914 = 5; (l_1914 >= 2); l_1914 -= 1)
                    {
                        int i;
                        j = (l_1359[(l_1914 + 1)] == ((safe_lshift_func_uint16_t_u_s(((((l_2112 = ((safe_rshift_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s(((l_1359[(l_1914 + 1)] && g_315) == g_359[3][2]), ((safe_sub_func_uint8_t_u_u((l_1849 = ((safe_sub_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s(1L, (g_1129 == 0x2B504DA9L))), 9UL)) > ((safe_lshift_func_uint8_t_u_u(g_188, g_188)) || l_1954[3][0][1]))), g_172[4])) != l_1955[1]))), g_173)), 0x4C755050L)), 0)) <= g_188)) <= g_188) || g_188) < g_188), 13)) ^ g_3261));
                        j = ((((+((safe_add_func_uint16_t_u_u((g_3261 = (safe_unary_minus_func_uint32_t_u(l_1955[1]))), (1UL || (safe_rshift_func_int16_t_s_s(((((safe_lshift_func_uint8_t_u_u((((g_543[2] || 1UL) > j) && g_866[0][9]), ((safe_sub_func_uint8_t_u_u((l_1935[4][2] = (safe_add_func_int16_t_s_s((g_1524 = l_2240), (safe_sub_func_int16_t_s_s(g_866[4][0], (((safe_lshift_func_int16_t_s_u((l_1359[(l_1914 + 1)] ^ g_949[1][7][4]), g_12)) && l_1848) == l_1849)))))), g_188)) || g_188))) ^ 0L) || 4294967295UL) < g_188), 11))))) < g_188)) & 6L) >= 3L) != l_1359[(l_1914 + 1)]);
                        j = g_188;
                        return g_359[9][0];
                    }
                }
                else
                {
                    l_1848 = 0x5D495BDFL;
                }
            }
            else
            {
                int32_t l_1989[1][10][5] = {{{0x7F4AB92CL,0xC925956FL,8L,8L,0xC925956FL},{0x24D3979AL,0xAD01E5F9L,8L,0xB96CFD52L,0xB96CFD52L},{0xAD01E5F9L,0x24D3979AL,0xAD01E5F9L,8L,0xB96CFD52L},{0xC925956FL,0x5412202AL,0xB96CFD52L,0x5412202AL,0xC925956FL},{0xAD01E5F9L,0x5412202AL,0x24D3979AL,0xC925956FL,0x24D3979AL},{0x24D3979AL,0x24D3979AL,0xB96CFD52L,0xC925956FL,0x7F4AB92CL},{0x5412202AL,0xAD01E5F9L,0xAD01E5F9L,0x5412202AL,0x24D3979AL},{0x5412202AL,0xC925956FL,8L,8L,0xC925956FL},{0x24D3979AL,0xAD01E5F9L,8L,0xB96CFD52L,0xB96CFD52L},{0xAD01E5F9L,0x24D3979AL,0xAD01E5F9L,8L,0xB96CFD52L}}};
                int8_t l_2105 = 0L;
                int i, j, k;
                l_1849 = (safe_unary_minus_func_int32_t_s((safe_rshift_func_int16_t_s_u(1L, 0))));
                if ((safe_lshift_func_int16_t_s_s(((safe_sub_func_int32_t_s_s(((l_1849 = (-9L)) || (((!(((((safe_lshift_func_int8_t_s_s(0xDAL, 3)) | (safe_sub_func_uint8_t_u_u((l_1914 >= (((safe_rshift_func_uint16_t_u_s((safe_lshift_func_int16_t_s_s(l_1849, 7)), 9)) < (l_1866[0][4] = (l_1989[0][4][1] & (safe_sub_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s(0x53L, (safe_add_func_int8_t_s_s((l_1989[0][4][1] | (((((((((((safe_unary_minus_func_int16_t_s(0x3B85L)) != ((safe_sub_func_int32_t_s_s((safe_rshift_func_uint8_t_u_s(((g_188 >= 0x0DDCL) || 0xA8L), 0)), g_188)) ^ 4294967291UL)) & 0x4108C488L) || l_1848) == 1L) < g_188) < l_1760) != (-1L)) == g_217) && g_188) < 65535UL)), g_188)))), 0UL))))) < g_315)), g_188))) && g_188) == 0xB9DFL) == g_359[2][5])) | g_188) ^ g_188)), g_172[4])) ^ g_188), g_188)))
                {
                    int16_t l_2038[7] = {(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L)};
                    int32_t l_2039 = 0xC0D7F6D0L;
                    int16_t l_2068 = 0xB7D8L;
                    int i;
                    if ((safe_rshift_func_uint8_t_u_s((((l_1989[0][7][2] = (safe_lshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((0L && (((~g_188) | (safe_mod_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s(g_1524, 7)), 1UL))) >= g_188)), ((g_188 | (((l_1866[0][4] = (((safe_add_func_int16_t_s_s(((((~1L) > ((safe_add_func_int16_t_s_s((g_543[1] = (~((((g_188 != g_543[1]) || l_2020) != 0L) != l_2020))), g_359[8][6])) <= (-9L))) && g_866[4][0]) < l_1849), 0xE863L)) == 0xE036L) & g_2576)) && g_188) >= 0x60597231L)) && 0L))), 6))) != 2UL) || l_1954[3][4][0]), 3)))
                    {
                        int16_t l_2067 = 0x91C1L;
                        int32_t l_2069 = 1L;
                        l_2039 = (l_2240 ^ (safe_mod_func_uint32_t_u_u((safe_add_func_uint32_t_u_u(g_188, (safe_lshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s((-4L), g_188)), ((((!(l_1849 = ((g_3261 = ((safe_rshift_func_int16_t_s_s((g_3957 == (~(65533UL >= (safe_mod_func_uint8_t_u_u(((safe_unary_minus_func_int32_t_s((safe_rshift_func_int16_t_s_u(((((l_1914 = (g_173 != ((g_3781 ^ 6L) > 7UL))) >= l_2020) | 0x22625FC4L) < 0xF488F9B2L), 1)))) || 0x3538B600L), g_188))))), 4)) | l_2038[0])) > l_2020))) >= g_543[1]) | j) & l_2038[0]))))), g_188)));
                        l_2069 = (safe_add_func_uint8_t_u_u(((safe_unary_minus_func_uint32_t_u((safe_unary_minus_func_uint8_t_u((safe_sub_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((safe_mod_func_int8_t_s_s(0xECL, ((safe_sub_func_int16_t_s_s(((g_543[1] = ((0x9DL && (safe_mod_func_uint32_t_u_u((0xEA79B2F8L && (g_813[1][0] >= (((safe_mul_func_int16_t_s_s(g_188, ((((((((safe_sub_func_int32_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(((+(safe_add_func_uint32_t_u_u(0UL, (g_188 ^ g_3261)))) < (l_2067 = (g_3957 = (safe_lshift_func_uint16_t_u_u((g_1524 && g_188), g_866[3][0]))))), l_2068)), g_188)), 6L)) >= g_188) & g_188) > 1UL) == 0x5343C28EL) < g_188) != 0L) >= g_188))) <= 0x4BL) >= g_188))), l_2069))) < l_1954[2][2][0])) >= l_2240), 5L)) & l_1989[0][4][1]))) != l_1866[0][4]), 0xE27096D6L)), g_188)))))) && 8L), g_1524));
                        l_1849 = (safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s((((g_188 ^ (safe_mod_func_int8_t_s_s(((safe_rshift_func_uint8_t_u_u((1L || 0xBEL), (g_188 && (safe_mod_func_uint32_t_u_u((((safe_add_func_int8_t_s_s(g_188, (g_543[0] == (safe_rshift_func_int16_t_s_s((l_2039 = l_2038[5]), 14))))) ^ (safe_mod_func_uint32_t_u_u((+((((~(safe_rshift_func_int8_t_s_u(((j <= ((0x01L == 0x87L) == 0x27878AF2L)) ^ l_1955[1]), 3))) && 0x4F75L) != g_3957) & 255UL)), g_3957))) && g_188), g_188))))) > g_188), l_2068))) >= g_173) > g_247), g_188)), g_172[4])), g_188));
                    }
                    else
                    {
                        uint16_t l_2111[5] = {0x6F74L,0x6F74L,0x6F74L,0x6F74L,0x6F74L};
                        int i;
                        l_1866[0][4] = g_188;
                        l_1914 = (j = (j & g_813[1][0]));
                        l_1914 = (safe_sub_func_int32_t_s_s(g_543[1], (((l_1866[0][6] != (l_1955[1] ^ ((g_3484 = (l_1989[0][9][2] = (g_866[4][0] && (safe_lshift_func_uint8_t_u_u((g_173 = (g_1129 = (((safe_sub_func_uint8_t_u_u((!(0xB6L || ((((safe_mod_func_uint32_t_u_u(g_188, (safe_lshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s(g_1524, l_2105)), ((g_1524 = ((!(safe_mod_func_int16_t_s_s(((g_866[3][6] = ((((g_3957 = (((safe_add_func_uint8_t_u_u(((g_188 >= g_361) >= l_1839), 0xFBL)) || l_2111[0]) | g_1215[1])) <= g_359[9][2]) || 255UL) < g_813[1][0])) >= 65535UL), g_188))) <= l_2240)) ^ 0xF7D9L))))) ^ l_2112) && g_188) && g_188))), l_2111[4])) != g_188) >= g_188))), 0))))) || 0x0BL))) != g_813[1][0]) < 0x1DCCL)));
                    }
                    for (g_4 = (-20); (g_4 < 6); g_4 = safe_add_func_uint16_t_u_u(g_4, 4))
                    {
                        l_1849 = (g_1129 || 1UL);
                    }
                }
                else
                {
                    uint8_t l_2126 = 253UL;
                    int32_t l_2133 = (-1L);
                    for (l_2112 = 26; (l_2112 <= 8); l_2112 = safe_sub_func_int32_t_s_s(l_2112, 5))
                    {
                        l_1914 = (1L != ((0xA588L | (l_2117[1][4][0] | 0x2BL)) | l_1848));
                        j = ((safe_sub_func_uint32_t_u_u(g_813[0][0], (l_1989[0][4][1] < (g_4 = g_188)))) <= (safe_mod_func_uint16_t_u_u(0xDAE1L, ((1L <= (((l_975[2][0] = (g_188 | (safe_sub_func_uint8_t_u_u(0x5DL, ((safe_rshift_func_int8_t_s_s(((g_188 & (g_188 != g_188)) | 0x7A4DL), 6)) < g_188))))) & g_188) >= 0xE26837B1L)) ^ l_2126))));
                    }
                    j = (safe_lshift_func_uint16_t_u_u(5UL, 7));
                    for (g_3957 = 0; (g_3957 <= 1); g_3957 += 1)
                    {
                        l_26 = ((-5L) <= (65528UL || ((safe_lshift_func_uint8_t_u_u((g_1129 = (g_1129 = ((safe_rshift_func_uint16_t_u_s(g_188, (l_2133 = (g_949[0][6][1] < 1L)))) || g_188))), (g_12 = (((safe_rshift_func_int8_t_s_s(1L, ((((g_543[1] = ((0x4A66L || ((((l_1848 || j) != g_12) || g_1524) & g_188)) <= g_12)) && g_188) ^ g_3957) & l_2163))) >= g_188) > g_188)))) & j)));
                    }
                }
                if ((g_866[4][0] <= g_172[4]))
                {
                    uint32_t l_2158 = 0x15129E0FL;
                    int32_t l_2159 = 8L;
                    l_1989[0][4][1] = (safe_sub_func_uint16_t_u_u((l_1839 & g_4), (safe_mod_func_int8_t_s_s((-6L), (0x9A0CL || g_866[2][1])))));
                    l_1914 = (+(safe_add_func_uint32_t_u_u(g_188, (safe_lshift_func_uint8_t_u_u(((((l_1866[2][0] = ((safe_rshift_func_int16_t_s_u((safe_lshift_func_int8_t_s_u((g_3781 = (safe_add_func_int16_t_s_s(7L, (+(~((g_359[6][0] <= (g_813[4][0] || ((safe_sub_func_int8_t_s_s(1L, (l_1989[0][0][3] = g_2576))) < (safe_mod_func_uint32_t_u_u((l_2159 = l_2158), (l_26 = (~((safe_lshift_func_uint16_t_u_u(g_188, 12)) ^ g_1129)))))))) > g_1524)))))), 5)), l_2117[1][4][0])) && g_1215[4])) || 0xF2L) > g_188) >= g_188), g_188)))));
                    l_2163 = l_1989[0][1][4];
                    l_1914 = g_188;
                }
                else
                {
                    uint32_t l_2178 = 0x079FD5DBL;
                    int32_t l_2180 = 1L;
                    l_2180 = (l_1077 = ((~((g_2177[4][3][1] = (safe_mod_func_uint8_t_u_u(((l_2163 | ((safe_mod_func_uint16_t_u_u((l_1955[1] != ((l_1989[0][5][1] ^ (safe_rshift_func_int8_t_s_u((g_3781 = ((safe_sub_func_uint8_t_u_u(g_188, (((~(~6UL)) || (l_2163 = ((0x800C94DEL <= (safe_lshift_func_uint16_t_u_u(g_949[1][0][4], (l_2020 && g_2177[3][1][9])))) & l_2178))) != g_4))) && 0x3AC1L)), 2))) == g_188)), l_2020)) == g_188)) ^ (-1L)), (-1L)))) == g_866[4][0])) < g_188));
                }
            }
            if ((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u((safe_sub_func_uint8_t_u_u((safe_add_func_uint32_t_u_u((((g_188 = ((g_359[8][3] = (l_2240 | ((((safe_mod_func_int16_t_s_s(g_949[2][0][4], (l_975[0][0] = 65530UL))) ^ ((safe_rshift_func_uint8_t_u_s((g_315 || ((((l_1866[0][4] = g_188) < (safe_rshift_func_uint8_t_u_u(((l_1848 = 6L) & ((safe_sub_func_uint32_t_u_u((((g_188 ^ 0x66L) < ((0UL == g_188) != g_188)) | (-1L)), 6L)) < g_188)), 3))) ^ g_188) <= l_1954[3][6][0])), 4)) & l_26)) != l_1955[0]) == 0UL))) && g_217)) && g_3409) ^ l_1955[1]), 0x1E98BD3CL)), 0x71L)), l_2112)), 2)))
            {
                uint8_t l_2220 = 0x46L;
                for (g_2576 = 0; (g_2576 != 5); ++g_2576)
                {
                    l_1914 = (l_2117[1][1][1] >= l_1914);
                }
                l_1914 = (safe_sub_func_int8_t_s_s((g_3957 ^ ((safe_rshift_func_uint8_t_u_s((((((((g_3484 = ((safe_sub_func_int8_t_s_s((safe_lshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u(0xF3L, g_188)) & ((safe_unary_minus_func_int8_t_s((safe_mod_func_uint32_t_u_u(((l_26 = (((safe_rshift_func_uint8_t_u_s((safe_sub_func_int8_t_s_s((g_3781 = ((safe_add_func_int8_t_s_s((-1L), (((safe_lshift_func_int8_t_s_s(l_2220, 7)) < (safe_mod_func_int16_t_s_s(((0xFCL == (-1L)) && ((0xA9DC081EL == g_188) & 0x9283L)), 65526UL))) | 0UL))) || 0x85A7L)), g_172[4])), g_1524)) && 0UL) > 0xA28D7A70L)) < j), l_2220)))) >= g_12)), 3)), l_2220)) != g_359[9][0])) == l_2240) == g_1215[4]) ^ g_12) >= j) | g_188) || g_2576), 2)) > g_3957)), (-1L)));
                g_541 = 0x6E262701L;
            }
            else
            {
                int32_t l_2223 = 0xFFA1B367L;
                l_1849 = 1L;
                l_2223 = (g_188 && (4294967293UL & ((g_188 != 0x174AL) ^ g_188)));
                l_1914 = (safe_lshift_func_int8_t_s_u(((safe_rshift_func_int16_t_s_s(g_949[0][6][1], 15)) ^ ((g_3781 = 0x79L) == j)), 2));
            }
            l_26 = (l_1848 = ((safe_mod_func_uint16_t_u_u(l_1954[3][0][1], (safe_add_func_int8_t_s_s((((g_813[2][0] = (safe_sub_func_uint8_t_u_u((safe_unary_minus_func_int8_t_s((((((safe_rshift_func_uint16_t_u_u(g_188, l_1848)) > (l_975[2][0] = (l_2239[3][2][0] < (g_359[1][6] ^ l_2240)))) & ((safe_lshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((j = ((safe_add_func_uint16_t_u_u((l_2247[1][0][8] <= (g_4 = (safe_mod_func_int32_t_s_s(l_1955[1], g_188)))), g_188)) < 1UL)), 0x9CFB623FL)), l_1077)) <= l_2163)) >= 0x2C3CBB80L) > g_188))), 0xBFL))) <= l_2239[5][4][1]) ^ 0xF637093EL), g_3261)))) < g_188));
            for (l_1077 = 0; (l_1077 <= 5); l_1077 += 1)
            {
                int32_t l_2250 = 3L;
                int i;
                l_2250 = (l_975[0][0] = (g_1215[l_1077] | g_3781));
            }
        }

                    l_1935[4][2] = (((safe_sub_func_int8_t_s_s(((safe_rshift_func_int8_t_s_u(g_12, (safe_lshift_func_int8_t_s_s((~(g_540 ^ ((g_813[1][0] < g_4) != ((5UL >= (safe_lshift_func_uint16_t_u_u(((safe_mod_func_int8_t_s_s((g_217 >= (g_538 = (l_1866[0][4] = (safe_lshift_func_uint8_t_u_u((safe_mod_func_uint16_t_u_u(((((safe_rshift_func_int16_t_s_s((l_1895 | (safe_mod_func_int32_t_s_s((0x4FA3L & 0L), 0x3F21BD3AL))), 8)) != 0x5BC70887L) <= 0x27L) & 0xB13EF641L), l_1914)), g_63))))), p_9)) ^ l_1914), l_1934))) <= p_9)))), 6)))) || g_949[0][0][2]), (-7L))) <= g_359[9][0]) ^ 1UL);
                    }
                    else
                    {
                        return l_975[0][0];
                    }

{
            transparent_crc(g_359[l_1849][g_541], "g_359[l_1849][g_541]", g_22);
            if (g_22) printf("index = [%d][%d]\n", l_1849, g_541);

        }

                    for (g_22 = 5; (g_22 >= 2); g_22 -= 1)
                    {
                        int i;
                        g_247 = (l_1359[(g_22 + 1)] == ((safe_lshift_func_uint16_t_u_s(((((l_1956 = ((safe_rshift_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s(((l_1359[(g_22 + 1)] && l_1001) == g_359[3][2]), ((safe_sub_func_uint8_t_u_u((l_1849 = ((safe_sub_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s(1L, (g_1460 == 0x2B504DA9L))), 9UL)) > ((safe_lshift_func_uint8_t_u_u(p_9, p_9)) || l_1954[3][0][1]))), g_172[4])) != l_1955[1]))), g_173)), 0x4C755050L)), 0)) <= p_9)) <= p_9) || p_9) < p_9), 13)) ^ g_315));
                        g_247 = ((((+((safe_add_func_uint16_t_u_u((g_315 = (safe_unary_minus_func_uint32_t_u(l_1955[1]))), (1UL || (safe_rshift_func_int16_t_s_s(((((safe_lshift_func_uint8_t_u_u((((g_543[2] || 1UL) > g_115) && g_866[0][9]), ((safe_sub_func_uint8_t_u_u((l_1935[4][2] = (safe_add_func_int16_t_s_s((g_188 = g_538), (safe_sub_func_int16_t_s_s(g_866[4][0], (((safe_lshift_func_int16_t_s_u((l_1359[(g_22 + 1)] ^ g_949[1][7][4]), g_217)) && l_1848) == l_1849)))))), p_9)) || p_9))) ^ 0L) || 4294967295UL) < p_9), 11))))) < p_9)) & 6L) >= 3L) != l_1359[(g_22 + 1)]);
                        g_247 = p_9;
                        return g_359[9][0];
                    }
                }
                else
                {
                    l_1848 = 0x5D495BDFL;
                }
            }
            else
            {
                int32_t l_1989[1][10][5] = {{{0x7F4AB92CL,0xC925956FL,8L,8L,0xC925956FL},{0x24D3979AL,0xAD01E5F9L,8L,0xB96CFD52L,0xB96CFD52L},{0xAD01E5F9L,0x24D3979AL,0xAD01E5F9L,8L,0xB96CFD52L},{0xC925956FL,0x5412202AL,0xB96CFD52L,0x5412202AL,0xC925956FL},{0xAD01E5F9L,0x5412202AL,0x24D3979AL,0xC925956FL,0x24D3979AL},{0x24D3979AL,0x24D3979AL,0xB96CFD52L,0xC925956FL,0x7F4AB92CL},{0x5412202AL,0xAD01E5F9L,0xAD01E5F9L,0x5412202AL,0x24D3979AL},{0x5412202AL,0xC925956FL,8L,8L,0xC925956FL},{0x24D3979AL,0xAD01E5F9L,8L,0xB96CFD52L,0xB96CFD52L},{0xAD01E5F9L,0x24D3979AL,0xAD01E5F9L,8L,0xB96CFD52L}}};
                int8_t l_2105 = 0L;
                int i, j, k;
                l_1849 = (safe_unary_minus_func_int32_t_s((safe_rshift_func_int16_t_s_u(1L, 0))));
                if ((safe_lshift_func_int16_t_s_s(((safe_sub_func_int32_t_s_s(((l_1849 = (-9L)) || (((!(((((safe_lshift_func_int8_t_s_s(0xDAL, 3)) | (safe_sub_func_uint8_t_u_u((g_22 >= (((safe_rshift_func_uint16_t_u_s((safe_lshift_func_int16_t_s_s(l_1849, 7)), 9)) < (l_1866[0][4] = (l_1989[0][4][1] & (safe_sub_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s(0x53L, (safe_add_func_int8_t_s_s((l_1989[0][4][1] | (((((((((((safe_unary_minus_func_int16_t_s(0x3B85L)) != ((safe_sub_func_int32_t_s_s((safe_rshift_func_uint8_t_u_s(((p_9 >= 0x0DDCL) || 0xA8L), 0)), p_9)) ^ 4294967291UL)) & 0x4108C488L) || l_1848) == 1L) < p_9) < l_2001) != (-1L)) == l_2002) && p_9) < 65535UL)), p_9)))), 0UL))))) < l_1001)), p_9))) && p_9) == 0xB9DFL) == g_359[2][5])) | p_9) ^ p_9)), g_172[4])) ^ p_9), p_9)))
                {
                    int16_t l_2038[7] = {(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L)};
                    int32_t l_2039 = 0xC0D7F6D0L;
                    int16_t l_2068 = 0xB7D8L;
                    int i;
                    if ((safe_rshift_func_uint8_t_u_s((((l_1989[0][7][2] = (safe_lshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((0L && (((~p_9) | (safe_mod_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s(g_188, 7)), 1UL))) >= p_9)), ((p_9 | (((l_1866[0][4] = (((safe_add_func_int16_t_s_s(((((~1L) > ((safe_add_func_int16_t_s_s((g_543[1] = (~((((p_9 != g_543[1]) || l_2020) != 0L) != l_2020))), g_359[8][6])) <= (-9L))) && g_866[4][0]) < l_1849), 0xE863L)) == 0xE036L) & l_1836)) && p_9) >= 0x60597231L)) && 0L))), 6))) != 2UL) || l_1954[3][4][0]), 3)))
                    {
                        int16_t l_2067 = 0x91C1L;
                        int32_t l_2069 = 1L;
                        l_2039 = (g_538 ^ (safe_mod_func_uint32_t_u_u((safe_add_func_uint32_t_u_u(p_9, (safe_lshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s((-4L), p_9)), ((((!(l_1849 = ((g_315 = ((safe_rshift_func_int16_t_s_s((g_161 == (~(65533UL >= (safe_mod_func_uint8_t_u_u(((safe_unary_minus_func_int32_t_s((safe_rshift_func_int16_t_s_u(((((g_22 = (g_173 != ((g_361 ^ 6L) > 7UL))) >= l_2020) | 0x22625FC4L) < 0xF488F9B2L), 1)))) || 0x3538B600L), p_9))))), 4)) | l_2038[0])) > l_2020))) >= g_543[1]) | g_115) & l_2038[0]))))), p_9)));

for (l_2039 = 0; l_2039 < 5; l_2039++)
    {
        transparent_crc(g_3956[l_2039], "g_3956[l_2039]", j);
        if (j) printf("index = [%d]\n", l_2039);

    };


                    l_2069 = (safe_add_func_uint8_t_u_u(((safe_unary_minus_func_uint32_t_u((safe_unary_minus_func_uint8_t_u((safe_sub_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((safe_mod_func_int8_t_s_s(0xECL, ((safe_sub_func_int16_t_s_s(((g_543[1] = ((0x9DL && (safe_mod_func_uint32_t_u_u((0xEA79B2F8L && (g_813[1][0] >= (((safe_mul_func_int16_t_s_s(p_9, ((((((((safe_sub_func_int32_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(((+(safe_add_func_uint32_t_u_u(0UL, (p_9 ^ g_315)))) < (l_2067 = (g_161 = (safe_lshift_func_uint16_t_u_u((g_1524 && p_9), g_866[3][0]))))), l_2068)), p_9)), 6L)) >= p_9) & p_9) > 1UL) == 0x5343C28EL) < p_9) != 0L) >= p_9))) <= 0x4BL) >= p_9))), l_2069))) < l_1954[2][2][0])) >= l_1806), 5L)) & l_1989[0][4][1]))) != l_1866[0][4]), 0xE27096D6L)), p_9)))))) && 8L), g_188));
                        l_1849 = (safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s((((p_9 ^ (safe_mod_func_int8_t_s_s(((safe_rshift_func_uint8_t_u_u((1L || 0xBEL), (p_9 && (safe_mod_func_uint32_t_u_u((((safe_add_func_int8_t_s_s(p_9, (g_543[0] == (safe_rshift_func_int16_t_s_s((l_2039 = l_2038[5]), 14))))) ^ (safe_mod_func_uint32_t_u_u((+((((~(safe_rshift_func_int8_t_s_u(((g_115 <= ((0x01L == 0x87L) == 0x27878AF2L)) ^ l_1955[1]), 3))) && 0x4F75L) != g_103) & 255UL)), g_540))) && p_9), p_9))))) > p_9), l_2068))) >= g_173) > l_27), p_9)), g_172[4])), p_9));
                    }
                    else
                    {
                        uint16_t l_2111[5] = {0x6F74L,0x6F74L,0x6F74L,0x6F74L,0x6F74L};
                        int i;
                        l_1866[0][4] = p_9;
                        g_22 = (g_247 = (g_541 & g_813[1][0]));

{
                int32_t l_1989[1][10][5] = {{{0x7F4AB92CL,0xC925956FL,8L,8L,0xC925956FL},{0x24D3979AL,0xAD01E5F9L,8L,0xB96CFD52L,0xB96CFD52L},{0xAD01E5F9L,0x24D3979AL,0xAD01E5F9L,8L,0xB96CFD52L},{0xC925956FL,0x5412202AL,0xB96CFD52L,0x5412202AL,0xC925956FL},{0xAD01E5F9L,0x5412202AL,0x24D3979AL,0xC925956FL,0x24D3979AL},{0x24D3979AL,0x24D3979AL,0xB96CFD52L,0xC925956FL,0x7F4AB92CL},{0x5412202AL,0xAD01E5F9L,0xAD01E5F9L,0x5412202AL,0x24D3979AL},{0x5412202AL,0xC925956FL,8L,8L,0xC925956FL},{0x24D3979AL,0xAD01E5F9L,8L,0xB96CFD52L,0xB96CFD52L},{0xAD01E5F9L,0x24D3979AL,0xAD01E5F9L,8L,0xB96CFD52L}}};
                int8_t l_2105 = 0L;
                int i, j, k;
                g_22 = (safe_unary_minus_func_int32_t_s((safe_rshift_func_int16_t_s_u(1L, 0))));
                if ((safe_lshift_func_int16_t_s_s(((safe_sub_func_int32_t_s_s(((g_22 = (-9L)) || (((!(((((safe_lshift_func_int8_t_s_s(0xDAL, 3)) | (safe_sub_func_uint8_t_u_u((g_2476 >= (((safe_rshift_func_uint16_t_u_s((safe_lshift_func_int16_t_s_s(g_22, 7)), 9)) < (l_1866[0][4] = (l_1989[0][4][1] & (safe_sub_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s(0x53L, (safe_add_func_int8_t_s_s((l_1989[0][4][1] | (((((((((((safe_unary_minus_func_int16_t_s(0x3B85L)) != ((safe_sub_func_int32_t_s_s((safe_rshift_func_uint8_t_u_s(((p_9 >= 0x0DDCL) || 0xA8L), 0)), p_9)) ^ 4294967291UL)) & 0x4108C488L) || l_1867) == 1L) < p_9) < g_2598) != (-1L)) == g_2710) && p_9) < 65535UL)), p_9)))), 0UL))))) < g_315)), p_9))) && p_9) == 0xB9DFL) == g_359[2][5])) | p_9) ^ p_9)), g_172[4])) ^ p_9), p_9)))
                {
                    int16_t l_2038[7] = {(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L)};
                    int32_t l_2039 = 0xC0D7F6D0L;
                    int16_t l_2068 = 0xB7D8L;
                    int i;
                    if ((safe_rshift_func_uint8_t_u_s((((l_1989[0][7][2] = (safe_lshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((0L && (((~p_9) | (safe_mod_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s(g_974, 7)), 1UL))) >= p_9)), ((p_9 | (((l_1866[0][4] = (((safe_add_func_int16_t_s_s(((((~1L) > ((safe_add_func_int16_t_s_s((g_543[1] = (~((((p_9 != g_543[1]) || l_1867) != 0L) != l_1867))), g_359[8][6])) <= (-9L))) && g_866[4][0]) < g_22), 0xE863L)) == 0xE036L) & l_2039)) && p_9) >= 0x60597231L)) && 0L))), 6))) != 2UL) || l_1954[3][4][0]), 3)))
                    {
                        int16_t l_2067 = 0x91C1L;
                        int32_t l_2069 = 1L;
                        l_2039 = (l_2240 ^ (safe_mod_func_uint32_t_u_u((safe_add_func_uint32_t_u_u(p_9, (safe_lshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s((-4L), p_9)), ((((!(g_22 = ((l_1956 = ((safe_rshift_func_int16_t_s_s((g_161 == (~(65533UL >= (safe_mod_func_uint8_t_u_u(((safe_unary_minus_func_int32_t_s((safe_rshift_func_int16_t_s_u(((((g_2476 = (g_2710 != ((g_4 ^ 6L) > 7UL))) >= l_1867) | 0x22625FC4L) < 0xF488F9B2L), 1)))) || 0x3538B600L), p_9))))), 4)) | l_2038[0])) > l_1867))) >= g_543[1]) | l_2039) & l_2038[0]))))), p_9)));
                        l_2069 = (safe_add_func_uint8_t_u_u(((safe_unary_minus_func_uint32_t_u((safe_unary_minus_func_uint8_t_u((safe_sub_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((safe_mod_func_int8_t_s_s(0xECL, ((safe_sub_func_int16_t_s_s(((g_543[1] = ((0x9DL && (safe_mod_func_uint32_t_u_u((0xEA79B2F8L && (g_813[1][0] >= (((safe_mul_func_int16_t_s_s(p_9, ((((((((safe_sub_func_int32_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(((+(safe_add_func_uint32_t_u_u(0UL, (p_9 ^ l_1956)))) < (l_2067 = (g_161 = (safe_lshift_func_uint16_t_u_u((g_974 && p_9), g_866[3][0]))))), l_2068)), p_9)), 6L)) >= p_9) & p_9) > 1UL) == 0x5343C28EL) < p_9) != 0L) >= p_9))) <= 0x4BL) >= p_9))), l_2069))) < l_1954[2][2][0])) >= l_1377), 5L)) & l_1989[0][4][1]))) != l_1866[0][4]), 0xE27096D6L)), p_9)))))) && 8L), g_974));
                        g_22 = (safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s((((p_9 ^ (safe_mod_func_int8_t_s_s(((safe_rshift_func_uint8_t_u_u((1L || 0xBEL), (p_9 && (safe_mod_func_uint32_t_u_u((((safe_add_func_int8_t_s_s(p_9, (g_543[0] == (safe_rshift_func_int16_t_s_s((l_2039 = l_2038[5]), 14))))) ^ (safe_mod_func_uint32_t_u_u((+((((~(safe_rshift_func_int8_t_s_u(((l_2039 <= ((0x01L == 0x87L) == 0x27878AF2L)) ^ l_1955[1]), 3))) && 0x4F75L) != g_161) & 255UL)), g_2598))) && p_9), p_9))))) > p_9), l_2068))) >= g_2710) > i), p_9)), g_172[4])), p_9));
                    }
                    else
                    {
                        uint16_t l_2111[5] = {0x6F74L,0x6F74L,0x6F74L,0x6F74L,0x6F74L};
                        int i;
                        l_1866[0][4] = p_9;
                        g_2476 = (g_115 = (g_2576 & g_813[1][0]));
                        g_2476 = (safe_sub_func_int32_t_s_s(g_543[1], (((l_1866[0][6] != (l_1955[1] ^ ((g_2576 = (l_1989[0][9][2] = (g_866[4][0] && (safe_lshift_func_uint8_t_u_u((g_2710 = (g_1460 = (((safe_sub_func_uint8_t_u_u((!(0xB6L || ((((safe_mod_func_uint32_t_u_u(p_9, (safe_lshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s(g_974, l_2105)), ((g_974 = ((!(safe_mod_func_int16_t_s_s(((g_866[3][6] = ((((g_2598 = (((safe_add_func_uint8_t_u_u(((p_9 >= g_361) >= g_974), 0xFBL)) || l_2111[0]) | g_1215[1])) <= g_359[9][2]) || 255UL) < g_813[1][0])) >= 65535UL), p_9))) <= l_2240)) ^ 0xF7D9L))))) ^ l_2112) && p_9) && p_9))), l_2111[4])) != p_9) >= p_9))), 0))))) || 0x0BL))) != g_813[1][0]) < 0x1DCCL)));
                    }
                    for (g_361 = (-20); (g_361 < 6); g_361 = safe_add_func_uint16_t_u_u(g_361, 4))
                    {
                        g_22 = (g_1129 || 1UL);
                    }
                }
                else
                {
                    uint8_t l_2126 = 253UL;
                    int32_t l_2133 = (-1L);
                    for (l_2112 = 26; (l_2112 <= 8); l_2112 = safe_sub_func_int32_t_s_s(l_2112, 5))
                    {
                        g_2476 = (1L != ((0xA588L | (l_2117[1][4][0] | 0x2BL)) | l_1867));
                        g_115 = ((safe_sub_func_uint32_t_u_u(g_813[0][0], (l_1989[0][4][1] < (g_4 = p_9)))) <= (safe_mod_func_uint16_t_u_u(0xDAE1L, ((1L <= (((l_975[2][0] = (p_9 | (safe_sub_func_uint8_t_u_u(0x5DL, ((safe_rshift_func_int8_t_s_s(((p_9 & (p_9 != p_9)) | 0x7A4DL), 6)) < p_9))))) & p_9) >= 0xE26837B1L)) ^ l_2126))));
                    }
                    g_115 = (safe_lshift_func_uint16_t_u_u(5UL, 7));
                    for (g_161 = 0; (g_161 <= 1); g_161 += 1)
                    {
                        g_2576 = ((-5L) <= (65528UL || ((safe_lshift_func_uint8_t_u_u((g_1460 = (g_1129 = ((safe_rshift_func_uint16_t_u_s(p_9, (l_2133 = (g_949[0][6][1] < 1L)))) || p_9))), (g_1460 = (((safe_rshift_func_int8_t_s_s(1L, ((((g_543[1] = ((0x4A66L || ((((l_1867 || g_2576) != g_1460) || g_974) & p_9)) <= g_1460)) && p_9) ^ g_161) & g_1524))) >= p_9) > p_9)))) & g_115)));
                    }
                }
                if ((g_866[4][0] <= g_172[4]))
                {
                    uint32_t l_2158 = 0x15129E0FL;
                    int32_t l_2159 = 8L;
                    l_1989[0][4][1] = (safe_sub_func_uint16_t_u_u((g_974 & g_4), (safe_mod_func_int8_t_s_s((-6L), (0x9A0CL || g_866[2][1])))));
                    g_2476 = (+(safe_add_func_uint32_t_u_u(p_9, (safe_lshift_func_uint8_t_u_u(((((l_1866[2][0] = ((safe_rshift_func_int16_t_s_u((safe_lshift_func_int8_t_s_u((g_4 = (safe_add_func_int16_t_s_s(7L, (+(~((g_359[6][0] <= (g_813[4][0] || ((safe_sub_func_int8_t_s_s(1L, (l_1989[0][0][3] = j))) < (safe_mod_func_uint32_t_u_u((l_2159 = l_2158), (g_2576 = (~((safe_lshift_func_uint16_t_u_u(p_9, 12)) ^ g_1460)))))))) > g_974)))))), 5)), l_2117[1][4][0])) && g_1215[4])) || 0xF2L) > p_9) >= p_9), p_9)))));
                    g_1524 = l_1989[0][1][4];
                    g_2476 = p_9;
                }
                else
                {
                    uint32_t l_2178 = 0x079FD5DBL;
                    int32_t l_2180 = 1L;
                    l_2180 = (l_1077 = ((~((g_2177[4][3][1] = (safe_mod_func_uint8_t_u_u(((g_974 | ((safe_mod_func_uint16_t_u_u((l_1955[1] != ((l_1989[0][5][1] ^ (safe_rshift_func_int8_t_s_u((g_4 = ((safe_sub_func_uint8_t_u_u(p_9, (((~(~6UL)) || (g_1524 = ((0x800C94DEL <= (safe_lshift_func_uint16_t_u_u(g_949[1][0][4], (l_1867 && g_2177[3][1][9])))) & l_2178))) != g_361))) && 0x3AC1L)), 2))) == p_9)), l_1867)) == p_9)) ^ (-1L)), (-1L)))) == g_866[4][0])) < p_9));
                }
            }

                    g_22 = (safe_sub_func_int32_t_s_s(g_543[1], (((l_1866[0][6] != (l_1955[1] ^ ((l_1813 = (l_1989[0][9][2] = (g_866[4][0] && (safe_lshift_func_uint8_t_u_u((g_173 = (g_1460 = (((safe_sub_func_uint8_t_u_u((!(0xB6L || ((((safe_mod_func_uint32_t_u_u(p_9, (safe_lshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s(g_188, l_2105)), ((g_1524 = ((!(safe_mod_func_int16_t_s_s(((g_866[3][6] = ((((g_540 = (((safe_add_func_uint8_t_u_u(((p_9 >= g_4) >= l_1839), 0xFBL)) || l_2111[0]) | g_1215[1])) <= g_359[9][2]) || 255UL) < g_813[1][0])) >= 65535UL), p_9))) <= g_538)) ^ 0xF7D9L))))) ^ l_2112) && p_9) && p_9))), l_2111[4])) != p_9) >= p_9))), 0))))) || 0x0BL))) != g_813[1][0]) < 0x1DCCL)));
                    }

{
                        int16_t l_2067 = 0x91C1L;
                        int32_t l_2069 = 1L;
                        g_541 = (l_21 ^ (safe_mod_func_uint32_t_u_u((safe_add_func_uint32_t_u_u(l_2068, (safe_lshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s((-4L), l_2068)), ((((!(l_1867 = ((l_2179 = ((safe_rshift_func_int16_t_s_s((g_3957 == (~(65533UL >= (safe_mod_func_uint8_t_u_u(((safe_unary_minus_func_int32_t_s((safe_rshift_func_int16_t_s_u(((((l_1836 = (g_1460 != ((g_3409 ^ 6L) > 7UL))) >= j) | 0x22625FC4L) < 0xF488F9B2L), 1)))) || 0x3538B600L), l_2068))))), 4)) | l_2038[0])) > j))) >= g_543[1]) | g_3152) & l_2038[0]))))), l_2068)));
                        l_2069 = (safe_add_func_uint8_t_u_u(((safe_unary_minus_func_uint32_t_u((safe_unary_minus_func_uint8_t_u((safe_sub_func_uint32_t_u_u((safe_mod_func_int32_t_s_s(((safe_mod_func_int8_t_s_s(0xECL, ((safe_sub_func_int16_t_s_s(((g_543[1] = ((0x9DL && (safe_mod_func_uint32_t_u_u((0xEA79B2F8L && (g_813[1][0] >= (((safe_mul_func_int16_t_s_s(l_2068, ((((((((safe_sub_func_int32_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(((+(safe_add_func_uint32_t_u_u(0UL, (l_2068 ^ l_2179)))) < (l_2067 = (g_3957 = (safe_lshift_func_uint16_t_u_u((l_2163 && l_2068), g_866[3][0]))))), l_1631)), l_2068)), 6L)) >= l_2068) & l_2068) > 1UL) == 0x5343C28EL) < l_2068) != 0L) >= l_2068))) <= 0x4BL) >= l_2068))), l_2069))) < l_1954[2][2][0])) >= g_3261), 5L)) & l_1989[0][4][1]))) != l_1866[0][4]), 0xE27096D6L)), l_2068)))))) && 8L), g_1524));
                        l_1867 = (safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((safe_sub_func_int16_t_s_s((((l_2068 ^ (safe_mod_func_int8_t_s_s(((safe_rshift_func_uint8_t_u_u((1L || 0xBEL), (l_2068 && (safe_mod_func_uint32_t_u_u((((safe_add_func_int8_t_s_s(l_2068, (g_543[0] == (safe_rshift_func_int16_t_s_s((g_541 = l_2038[5]), 14))))) ^ (safe_mod_func_uint32_t_u_u((+((((~(safe_rshift_func_int8_t_s_u(((g_3152 <= ((0x01L == 0x87L) == 0x27878AF2L)) ^ l_1955[1]), 3))) && 0x4F75L) != g_3957) & 255UL)), g_3957))) && l_2068), l_2068))))) > l_2068), l_1631))) >= g_1460) > l_1633), l_2068)), g_172[4])), l_2068));
                    }

                    for (l_28 = (-20); (l_28 < 6); l_28 = safe_add_func_uint16_t_u_u(l_28, 4))
                    {

g_3484 += 1;


                    l_1849 = (g_1129 || 1UL);
                    }
                }
                else
                {
                    uint8_t l_2126 = 253UL;
                    int32_t l_2133 = (-1L);
                    for (l_2112 = 26; (l_2112 <= 8); l_2112 = safe_sub_func_int32_t_s_s(l_2112, 5))
                    {
                        g_22 = (1L != ((0xA588L | (l_2117[1][4][0] | 0x2BL)) | l_1848));
                        g_247 = ((safe_sub_func_uint32_t_u_u(g_813[0][0], (l_1989[0][4][1] < (g_83 = p_9)))) <= (safe_mod_func_uint16_t_u_u(0xDAE1L, ((1L <= (((l_975[2][0] = (p_9 | (safe_sub_func_uint8_t_u_u(0x5DL, ((safe_rshift_func_int8_t_s_s(((p_9 & (p_9 != p_9)) | 0x7A4DL), 6)) < p_9))))) & p_9) >= 0xE26837B1L)) ^ l_2126))));
                    }
                    g_247 = (safe_lshift_func_uint16_t_u_u(5UL, 7));
                    for (l_1760 = 0; (l_1760 <= 1); l_1760 += 1)
                    {
                        l_26 = ((-5L) <= (65528UL || ((safe_lshift_func_uint8_t_u_u((g_1460 = (g_1129 = ((safe_rshift_func_uint16_t_u_s(p_9, (l_2133 = (g_949[0][6][1] < 1L)))) || p_9))), (g_217 = (((safe_rshift_func_int8_t_s_s(1L, ((((g_543[1] = ((0x4A66L || ((((l_1848 || g_541) != g_217) || g_1524) & p_9)) <= g_217)) && p_9) ^ g_103) & g_974))) >= p_9) > p_9)))) & g_247)));
                    }
                }
                if ((g_866[4][0] <= g_172[4]))
                {
                    uint32_t l_2158 = 0x15129E0FL;
                    int32_t l_2159 = 8L;
                    l_1989[0][4][1] = (safe_sub_func_uint16_t_u_u((l_1839 & g_83), (safe_mod_func_int8_t_s_s((-6L), (0x9A0CL || g_866[2][1])))));
                    g_22 = (+(safe_add_func_uint32_t_u_u(p_9, (safe_lshift_func_uint8_t_u_u(((((l_1866[2][0] = ((safe_rshift_func_int16_t_s_u((safe_lshift_func_int8_t_s_u((g_361 = (safe_add_func_int16_t_s_s(7L, (+(~((g_359[6][0] <= (g_813[4][0] || ((safe_sub_func_int8_t_s_s(1L, (l_1989[0][0][3] = l_2155))) < (safe_mod_func_uint32_t_u_u((l_2159 = l_2158), (l_26 = (~((safe_lshift_func_uint16_t_u_u(p_9, 12)) ^ g_1460)))))))) > g_1524)))))), 5)), l_2117[1][4][0])) && g_1215[4])) || 0xF2L) > p_9) >= p_9), p_9)))));
                    l_2163 = l_1989[0][1][4];
                    g_22 = p_9;
                }
                else
                {
                    uint32_t l_2178 = 0x079FD5DBL;
                    int32_t l_2180 = 1L;

for (l_1867 = 0; l_1867 < 1; l_1867++)
        {
            transparent_crc(g_813[l_1867][l_1867], "g_813[l_1867][l_1867]", g_115);
            if (g_115) printf("index = [%d][%d]\n", l_1867, l_1867);

        };


                    l_2180 = (l_2179 = ((~((g_2177[4][3][1] = (safe_mod_func_uint8_t_u_u(((l_1631 | ((safe_mod_func_uint16_t_u_u((l_1955[1] != ((l_1989[0][5][1] ^ (safe_rshift_func_int8_t_s_u((g_361 = ((safe_sub_func_uint8_t_u_u(p_9, (((~(~6UL)) || (g_974 = ((0x800C94DEL <= (safe_lshift_func_uint16_t_u_u(g_949[1][0][4], (l_2020 && g_2177[3][1][9])))) & l_2178))) != l_28))) && 0x3AC1L)), 2))) == p_9)), l_2020)) == p_9)) ^ (-1L)), (-1L)))) == g_866[4][0])) < p_9));
                }
            }
            if ((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u((safe_sub_func_uint8_t_u_u((safe_add_func_uint32_t_u_u((((p_9 = ((g_359[8][3] = (l_1806 | ((((safe_mod_func_int16_t_s_s(g_949[2][0][4], (l_975[0][0] = 65530UL))) ^ ((safe_rshift_func_uint8_t_u_s((l_1001 || ((((l_1866[0][4] = p_9) < (safe_rshift_func_uint8_t_u_u(((l_1848 = 6L) & ((safe_sub_func_uint32_t_u_u((((p_9 ^ 0x66L) < ((0UL == p_9) != p_9)) | (-1L)), 6L)) < p_9)), 3))) ^ p_9) <= l_1954[3][6][0])), 4)) & l_26)) != l_1955[0]) == 0UL))) && g_12)) && l_1434) ^ l_1955[1]), 0x1E98BD3CL)), 0x71L)), l_2112)), 2)))
            {
                uint8_t l_2220 = 0x46L;
                for (l_2155 = 0; (l_2155 != 5); ++l_2155)
                {
                    g_22 = (l_2117[1][1][1] >= g_22);
                }
                g_22 = (safe_sub_func_int8_t_s_s((g_103 ^ ((safe_rshift_func_uint8_t_u_s((((((((l_1813 = ((safe_sub_func_int8_t_s_s((safe_lshift_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u(0xF3L, p_9)) & ((safe_unary_minus_func_int8_t_s((safe_mod_func_uint32_t_u_u(((l_26 = (((safe_rshift_func_uint8_t_u_s((safe_sub_func_int8_t_s_s((g_361 = ((safe_add_func_int8_t_s_s((-1L), (((safe_lshift_func_int8_t_s_s(l_2220, 7)) < (safe_mod_func_int16_t_s_s(((0xFCL == (-1L)) && ((0xA9DC081EL == p_9) & 0x9283L)), 65526UL))) | 0UL))) || 0x85A7L)), g_172[4])), g_1524)) && 0UL) > 0xA28D7A70L)) < g_247), l_2220)))) >= g_217)), 3)), l_2220)) != g_359[9][0])) == l_1806) == g_1215[4]) ^ g_217) >= g_541) | p_9) || l_1836), 2)) > g_103)), (-1L)));
                l_1867 = 0x6E262701L;
            }
            else
            {
                int32_t l_2223 = 0xFFA1B367L;
                l_1849 = 1L;

{
                        g_3956[2] = l_1001;
                    }

                    l_2223 = (p_9 && (4294967293UL & ((p_9 != 0x174AL) ^ p_9)));
                g_22 = (safe_lshift_func_int8_t_s_u(((safe_rshift_func_int16_t_s_s(g_949[0][6][1], 15)) ^ ((g_361 = 0x79L) == g_541)), 2));
            }
            l_26 = (l_1848 = ((safe_mod_func_uint16_t_u_u(l_1954[3][0][1], (safe_add_func_int8_t_s_s((((g_813[2][0] = (safe_sub_func_uint8_t_u_u((safe_unary_minus_func_int8_t_s((((((safe_rshift_func_uint16_t_u_u(p_9, l_1848)) > (l_975[2][0] = (l_2239[3][2][0] < (g_359[1][6] ^ l_2240)))) & ((safe_lshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((g_247 = ((safe_add_func_uint16_t_u_u((l_2247[1][0][8] <= (g_83 = (safe_mod_func_int32_t_s_s(l_1955[1], p_9)))), p_9)) < 1UL)), 0x9CFB623FL)), l_2179)) <= l_1631)) >= 0x2C3CBB80L) > p_9))), 0xBFL))) <= l_2239[5][4][1]) ^ 0xF637093EL), g_315)))) < p_9));
            for (l_2179 = 0; (l_2179 <= 5); l_2179 += 1)
            {
                int32_t l_2250 = 3L;
                int i;
                l_2250 = (l_975[0][0] = (g_1215[l_2179] | g_361));
            }
        }
        g_22 = ((safe_rshift_func_int8_t_s_s(p_9, ((safe_sub_func_uint32_t_u_u(p_9, (((g_315 || (l_1866[0][0] = l_2163)) > (safe_add_func_uint32_t_u_u(((safe_add_func_uint16_t_u_u((safe_add_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_s((l_1956 >= g_115), ((!((l_2002 <= (g_63 && ((!0x075CA883L) < l_1760))) || g_359[1][4])) <= 0x10L))) & g_247), (-7L))), 65532UL)) <= 0xF5L), p_9))) <= g_974))) == 0UL))) & p_9);
    }
                                        while (!((l_1956<=8)) )
{

g_2576 += 1;


}
                    return p_9;
}







static int32_t func_15(uint32_t p_16, int8_t p_17, uint32_t p_18, uint32_t p_19, uint32_t p_20)
{
    uint32_t l_899[7][3] = {{0x87F01EA7L,0x87F01EA7L,0x87F01EA7L},{1UL,6UL,1UL},{0x87F01EA7L,0x87F01EA7L,0x87F01EA7L},{1UL,6UL,1UL},{0x87F01EA7L,0x87F01EA7L,0x87F01EA7L},{1UL,6UL,1UL},{0x87F01EA7L,0x87F01EA7L,0x87F01EA7L}};
    int32_t l_951[9][1] = {{0x65F0C153L},{(-1L)},{0x65F0C153L},{(-1L)},{0x65F0C153L},{(-1L)},{0x65F0C153L},{(-1L)},{0x65F0C153L}};
    uint32_t l_973 = 0xD1EA04B1L;
    int i, j;
    l_951[4][0] = ((func_29((0x29L >= (func_35(p_16, g_22, p_19, p_17) <= ((+((0xFFE5L <= (((safe_mod_func_int16_t_s_s((safe_sub_func_uint8_t_u_u(((p_16 && p_17) == g_4), p_20)), l_899[6][1])) >= 8L) <= l_899[6][1])) | 8L)) | g_4))), g_4, g_4, g_4, l_899[0][2]) ^ g_4) || 3UL);
    g_247 = l_951[2][0];
    for (g_217 = 0; (g_217 == 26); ++g_217)
    {
        uint16_t l_963[10][10] = {{0UL,2UL,65535UL,2UL,0UL,1UL,0UL,0xE16FL,0xB861L,0UL},{2UL,0xB861L,0x5B7AL,0UL,65535UL,0x705DL,1UL,0UL,0UL,0UL},{0UL,0UL,2UL,0UL,0UL,2UL,0UL,0UL,2UL,0UL},{0UL,0x705DL,0x2CCFL,2UL,0UL,0UL,0UL,65531UL,65535UL,0UL},{5UL,0UL,0x2CCFL,0UL,0xB861L,65531UL,0xB861L,0UL,0x2CCFL,0UL},{0xE16FL,0UL,2UL,0UL,0xAEDAL,0UL,0x705DL,0UL,0xF795L,5UL},{0x2CCFL,1UL,0x5B7AL,5UL,0UL,0UL,0xE16FL,0xE16FL,0UL,0UL},{0xE16FL,65535UL,65535UL,0xE16FL,2UL,65531UL,0xF795L,65535UL,0UL,0UL},{5UL,0x5B7AL,1UL,0x2CCFL,65531UL,0UL,65535UL,0xF795L,0UL,0xF795L},{0UL,2UL,0UL,0xE16FL,0UL,2UL,0UL,0xAEDAL,0UL,0x705DL}};
        int32_t l_970 = 0x9509D908L;
        int32_t l_971 = 1L;
        int32_t l_972 = (-1L);
        int i, j;
        l_972 = ((((safe_add_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u(0x6FL, 7)), (l_971 = (g_173 = ((l_951[0][0] = (l_970 = ((safe_add_func_int8_t_s_s(l_899[6][1], l_899[6][0])) && ((~(safe_sub_func_int8_t_s_s((0x1A95L && (p_18 >= l_963[7][4])), ((l_963[9][0] != (safe_sub_func_uint8_t_u_u((((safe_sub_func_int16_t_s_s(0xB05DL, (((safe_rshift_func_int8_t_s_u(((((g_866[4][0] < 65526UL) || l_963[6][0]) >= g_543[1]) == l_899[6][1]), g_543[1])) > p_19) < 4294967295UL))) & 0x7830B31CL) != p_20), l_963[7][4]))) > 9UL)))) > l_963[7][4])))) | p_18))))) > l_963[2][1]) < l_963[1][0]) == l_963[8][8]);
    }
    l_951[2][0] = 0xE9313C12L;
    return l_973;
}







static int32_t func_29(uint8_t p_30, uint8_t p_31, uint16_t p_32, uint32_t p_33, int32_t p_34)
{
    uint32_t l_932[6][4] = {{0x30C08275L,0x09916C09L,0x09916C09L,0x30C08275L},{0UL,0x09916C09L,4UL,0x09916C09L},{0x09916C09L,0x8539AD46L,4UL,4UL},{0UL,0UL,0x09916C09L,4UL},{0x30C08275L,0x8539AD46L,0x30C08275L,0x09916C09L},{0x30C08275L,0x09916C09L,0x09916C09L,0x30C08275L}};
    int32_t l_950 = 0x12F1490EL;
    int i, j;
    for (g_22 = (-5); (g_22 < (-7)); --g_22)
    {
        int8_t l_931 = (-8L);

{
        for (j = 0; j < 4; j++)
        {
            for (g_3484 = 0; g_3484 < 10; g_3484++)
            {
                transparent_crc(g_2177[g_3484][j][g_3484], "g_2177[g_3484][j][g_3484]", g_2576);
                if (g_2576) printf("index = [%d][%d][%d]\n", g_3484, j, g_3484);

            }
        }
    }

                    g_247 = (safe_rshift_func_uint16_t_u_u((safe_sub_func_int32_t_s_s((safe_unary_minus_func_uint8_t_u(p_33)), 0xEACFE029L)), 6));
        for (g_63 = 0; (g_63 != 54); g_63++)
        {
            uint32_t l_942 = 0xA7B52D8FL;
            p_34 = (p_34 < ((((safe_sub_func_int16_t_s_s((-2L), ((((safe_mod_func_int32_t_s_s((safe_mod_func_int32_t_s_s(8L, (safe_add_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u(0x07L, (((safe_mod_func_uint8_t_u_u(g_247, (safe_sub_func_int32_t_s_s(g_359[9][0], (safe_mod_func_uint16_t_u_u((g_813[1][0] < (safe_rshift_func_int8_t_s_s((safe_sub_func_uint8_t_u_u(((-9L) != (safe_lshift_func_int16_t_s_u(1L, 11))), g_172[1])), p_32))), 0xCC61L)))))) != l_931) < 0xE70A6146L))), 1UL)))), g_813[1][0])) == 4294967295UL) ^ p_31) || g_217))) ^ g_315) | l_931) | g_115));
            g_949[0][6][1] = ((l_932[1][1] ^ (safe_lshift_func_uint16_t_u_s(g_361, 11))) && (!(safe_add_func_uint8_t_u_u(p_31, (((safe_rshift_func_uint16_t_u_u(g_813[1][0], (safe_mod_func_uint8_t_u_u((l_942 || (p_33 > (l_932[1][1] == (safe_add_func_uint32_t_u_u((safe_unary_minus_func_int32_t_s((g_247 = (!(g_359[8][0] = (((((0xADL ^ (safe_sub_func_int16_t_s_s(p_34, (-1L)))) ^ (-1L)) ^ p_30) > 5UL) | (-5L))))))), p_32))))), g_172[4])))) != 250UL) ^ g_4)))));
            l_950 = l_932[1][1];

g_1129 += 1;


                    for (p_30 = 0; (p_30 <= 7); p_30 += 1)
            {
                int i, j;

{
                    i = 0x647B4652L;
                }

                    for (g_161 = 2; (g_161 <= 7); g_161 += 1)
                {
                    p_34 = 0x647B4652L;
                }
                g_247 = (g_866[p_30][(p_30 + 2)] & 1UL);
            }
        }
        l_950 = 0L;
    }
    return p_31;
}







static int8_t func_35(int8_t p_36, int16_t p_37, int32_t p_38, int32_t p_39)
{
    int32_t l_521 = 0xBC8555D8L;
    int32_t l_522 = 0x4F3B9912L;
    int32_t l_539 = 0x4D9E0D6BL;
    int32_t l_542 = 1L;
    g_22 = ((safe_lshift_func_uint16_t_u_u(g_4, 1)) | g_4);
    p_39 = func_42(p_36, func_46(g_4), ((l_521 == (((l_522 = 0x88L) && (safe_add_func_int16_t_s_s((safe_lshift_func_int8_t_s_u((safe_rshift_func_uint8_t_u_u(((g_543[1] = (((0xFA1EL || (l_542 = (((safe_sub_func_int8_t_s_s((g_541 = ((g_4 == (((((((safe_unary_minus_func_int8_t_s((g_540 = (safe_sub_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u((l_539 = ((safe_mod_func_int8_t_s_s((l_522 = p_37), ((((g_538 = g_4) >= l_521) == p_37) || p_38))) ^ p_39)), 4294967294UL)) ^ 1L), g_4))))) > l_521) & 0x37L) && l_522) && 65535UL) & 1UL) & p_37)) ^ p_38)), l_521)) <= (-9L)) != p_37))) & 4294967295UL) < g_4)) || 0x1DL), p_37)), 5)), g_4))) > g_4)) ^ l_521));
                                        if ((!l_539) )
{

{
    uint8_t l_71 = 0UL;
    int32_t l_75[2][3][6] = {{{(-2L),(-2L),0L,0xA11B98B5L,3L,(-1L)},{1L,0xD8A5C089L,0L,0L,0x473F1902L,0L},{0L,1L,0L,4L,(-2L),(-1L)}},{{0x2A83C5EEL,4L,0L,0xAF0CFC20L,7L,7L},{0xAF0CFC20L,7L,7L,0xAF0CFC20L,0L,4L},{0x2A83C5EEL,(-1L),(-2L),0xD8A5C089L,(-1L),0xA11B98B5L}}};
    uint16_t l_78[8] = {0x58C9L,0x2F22L,0x58C9L,0x2F22L,0x58C9L,0x2F22L,0x58C9L,0x2F22L};
    int i, j, k;
    for (g_103 = 0; (g_103 > 12); g_103 = safe_add_func_uint16_t_u_u(g_103, 7))
    {
        uint32_t l_72[6] = {18446744073709551606UL,18446744073709551606UL,0xEFD7F9B6L,18446744073709551606UL,18446744073709551606UL,0xEFD7F9B6L};
        int i;
        l_521 = ((g_63 < ((((safe_rshift_func_uint16_t_u_s(((((l_72[5] = (~l_71)) != g_63) | ((0xE2L < (safe_rshift_func_uint16_t_u_s(((0L && 0UL) ^ (7L > (((l_521 ^ l_71) == l_521) < (-1L)))), 15))) == 0x2DL)) & g_103), 8)) ^ 0x12ECL) | l_71) <= 0x319F56C0L)) >= 255UL);
    }
    for (l_521 = 1; (l_521 >= 0); l_521 -= 1)
    {
        return l_75[0][0][0];
    }
    l_78[4] = (safe_mod_func_int32_t_s_s(l_521, g_103));
    return g_103;
}

}
                    return g_359[9][0];
}







static int32_t func_42(int16_t p_43, int32_t p_44, uint32_t p_45)
{
    int8_t l_545[3];
    int32_t l_576 = (-3L);
    int32_t l_577 = (-9L);
    int32_t l_608 = 0xEF9BE18AL;
    int32_t l_609 = (-9L);
    uint16_t l_796 = 0UL;
    uint32_t l_814 = 4294967295UL;
    int8_t l_815[6] = {0L,0L,0xC7L,0L,0L,0xC7L};
    int16_t l_891 = 0x8619L;
    int32_t l_892[7];
    int i;
    for (i = 0; i < 3; i++)
        l_545[i] = 0x82L;
    for (i = 0; i < 7; i++)
        l_892[i] = 0x225A8AF4L;
    p_44 = ((g_173 = ((4UL <= (l_577 = (+(l_545[2] > (1UL | (safe_sub_func_int8_t_s_s((!(((safe_lshift_func_int16_t_s_s(p_45, 7)) & ((0xEDL || ((safe_lshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((l_576 = (safe_add_func_uint8_t_u_u((safe_add_func_int16_t_s_s((safe_rshift_func_int16_t_s_s((g_83 > (safe_unary_minus_func_uint8_t_u(((+(safe_add_func_int8_t_s_s((-7L), ((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s(((safe_lshift_func_uint16_t_u_s(0x0162L, 4)) && (safe_add_func_uint32_t_u_u((+((p_45 & 1L) ^ p_44)), g_543[0]))), 14)), 1L)) & p_43)))) > p_43)))), g_22)), l_545[2])), 2UL))), p_44)), g_217)) & 1UL)) <= (-8L))) && p_45)), g_115))))))) < 0L)) | l_545[2]);
    l_577 = ((safe_lshift_func_uint8_t_u_s(((safe_sub_func_uint16_t_u_u(((p_44 = l_577) || ((((((-2L) <= g_103) || p_45) != l_545[2]) || ((l_545[2] <= ((safe_mod_func_int8_t_s_s(1L, (l_545[2] & (l_545[2] <= g_540)))) < (-1L))) == l_545[2])) ^ l_545[2])), (-6L))) || 1L), p_45)) >= 2UL);
    p_44 = (safe_add_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u(((safe_add_func_uint16_t_u_u(l_577, ((l_609 = ((safe_sub_func_int8_t_s_s((safe_mod_func_uint16_t_u_u((l_608 = (((((((safe_lshift_func_uint8_t_u_s((safe_mod_func_int8_t_s_s((p_43 > (safe_add_func_int16_t_s_s(0xFDDDL, (safe_add_func_uint8_t_u_u(0x59L, (((safe_mod_func_int8_t_s_s((safe_add_func_int16_t_s_s((g_543[1] >= (p_45 >= 0UL)), ((safe_lshift_func_int8_t_s_s((l_576 = l_577), ((l_577 < g_543[1]) == 255UL))) != 0x98C1L))), p_45)) & 1UL) < 0xBCL)))))), g_359[7][2])), p_43)) < 9UL) < p_44) && l_576) && p_45) > 4294967295UL) | l_577)), 0xE706L)), g_541)) && g_188)) || g_538))) < 0x0A13L), 10)), 0x855A41B0L));
    for (g_361 = 13; (g_361 < 11); g_361 = safe_sub_func_uint32_t_u_u(g_361, 2))
    {
        uint32_t l_623 = 0xD90F1D9FL;
        int32_t l_624 = 2L;
        uint16_t l_637 = 0x4B68L;
        int32_t l_648[10] = {0x9713A9AEL,0xB289C69EL,0xB289C69EL,0x9713A9AEL,0x7EA5E1F5L,0x9713A9AEL,0xB289C69EL,0xB289C69EL,0x9713A9AEL,0x7EA5E1F5L};
        uint16_t l_659 = 0x21DAL;
        int16_t l_831[10] = {2L,2L,2L,2L,2L,2L,2L,2L,2L,2L};
        int i;
        p_44 = ((p_45 = (~(g_188 ^ (safe_add_func_uint16_t_u_u(p_45, ((l_545[2] | (safe_sub_func_int16_t_s_s(((g_359[9][0] = (l_577 = ((safe_add_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(((safe_add_func_int32_t_s_s(0xD02CED5BL, (0x47DF14EFL < l_623))) && (l_608 = (p_43 <= (l_624 = 0x68L)))), g_217)), p_44)) ^ p_44))) >= g_63), g_315))) | p_44)))))) && 0xF6AF04A2L);
        p_44 = (l_608 >= (safe_lshift_func_uint16_t_u_u((l_609 = ((g_543[1] < 0x92L) || ((safe_rshift_func_uint8_t_u_s(p_43, 7)) & ((((((safe_mod_func_int8_t_s_s((g_188 | ((((-5L) < (safe_lshift_func_int8_t_s_s((l_609 & l_608), (safe_mod_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s(l_623, l_608)), (-1L)))))) & g_541) < g_359[9][0])), l_637)) & l_624) == (-5L)) >= g_188) != 4UL) >= l_608)))), p_44)));
        if (((((safe_rshift_func_uint16_t_u_s(l_624, (((0x6C58L == (g_247 > l_637)) >= (l_648[7] = ((g_22 = (p_44 && p_44)) ^ ((safe_mod_func_int32_t_s_s(g_173, 4294967294UL)) == (safe_mod_func_uint16_t_u_u(((((safe_add_func_int16_t_s_s((g_188 = ((0x2415FF63L < g_63) | g_83)), g_315)) == 3L) < l_637) || (-1L)), p_45)))))) > g_538))) < 1UL) >= p_45) == g_217))
        {
            uint32_t l_660 = 18446744073709551606UL;
            int32_t l_703 = 0x45EA0260L;
            int32_t l_719 = 0xF66FE10FL;
            int16_t l_842 = 0xD120L;
            uint32_t l_850 = 0x6743DD51L;
            g_22 = ((((safe_lshift_func_int8_t_s_s(p_44, (safe_mod_func_uint32_t_u_u((p_43 | (safe_lshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_s(0x19L, 0)) ^ l_637), ((((safe_rshift_func_int16_t_s_u(((g_83 = 0xF9L) < ((l_659 < (0x1F6080AFL < p_44)) != g_103)), 0)) >= l_660) ^ l_659) || g_543[1])))), 0x58400C79L)))) & p_44) > 0xEFL) & g_103);
            g_247 = (-1L);
            for (g_103 = 0; (g_103 <= 57); ++g_103)
            {
                uint16_t l_676[2][10] = {{0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL},{0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL}};
                uint32_t l_678 = 5UL;
                int32_t l_692[9] = {0x28905217L,0x28905217L,0x28905217L,0x28905217L,0x28905217L,0x28905217L,0x28905217L,0x28905217L,0x28905217L};
                uint32_t l_743[2][4] = {{0UL,4294967295UL,4294967295UL,0UL},{4294967295UL,0UL,4294967295UL,4294967295UL}};
                int32_t l_797 = 1L;
                int i, j;

{
    uint32_t l_62 = 4294967295UL;
    int32_t l_309 = 0x5E625162L;
    int8_t l_310 = 0xDEL;
    uint16_t l_406 = 0x5A4EL;
    int32_t l_492 = 9L;
    l_309 = func_48((safe_lshift_func_int8_t_s_u((((((((g_3409 | g_3409) <= ((safe_lshift_func_int16_t_s_u((safe_sub_func_int8_t_s_s(0L, func_57(l_62, g_3409, l_62, ((g_3261 = (g_3409 & g_2420)) | (safe_rshift_func_uint8_t_u_s(g_2420, 7)))))), 2)) >= 0x40L)) >= g_3409) > (-1L)) | g_2420) && l_62) <= g_2420), g_2420)), g_3409);

{
            uint16_t l_869 = 0x0CBAL;
            int32_t l_893 = 0x3423351EL;
            l_577 = (safe_lshift_func_uint16_t_u_s((0x39L & ((l_869 & ((((((0xB4L < (safe_sub_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s((2L >= (safe_lshift_func_uint16_t_u_u(((safe_mod_func_uint16_t_u_u((((safe_rshift_func_int16_t_s_u(g_974, 5)) | (safe_rshift_func_int16_t_s_u((safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_lshift_func_int8_t_s_s((((~g_974) < (l_577 <= g_866[6][9])) < (g_161 && l_869)), l_869)), 9)), (-1L))), g_161))) ^ 0x226FL), l_637)) & g_543[1]), 4))), 0)), l_608))) | 0x38EB57AFL) || g_115) != 0UL) >= 0x7089L) <= g_161)) >= l_869)), l_703));
            if (l_892[1])
                continue;
            l_893 = (-1L);
        }

                    l_309 = l_310;
    if ((safe_rshift_func_uint8_t_u_u(((l_637 = (safe_add_func_uint8_t_u_u(g_3409, g_3409))) >= (safe_add_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s(l_309, (safe_mod_func_uint16_t_u_u((l_309 <= 0xE3L), l_309)))), (safe_add_func_uint8_t_u_u((safe_mod_func_int32_t_s_s((-1L), (safe_add_func_uint8_t_u_u((0xD127F73BL > (l_310 <= 5UL)), g_115)))), g_3409))))), l_309)))
    {
        uint16_t l_333 = 2UL;
        int32_t l_335[8][3][4] = {{{0xDD39B848L,0L,0x5E468437L,3L},{3L,(-1L),0x641FE7F3L,0L},{0x7D02BC70L,0x641FE7F3L,0x641FE7F3L,0x7D02BC70L}},{{3L,(-1L),0x5E468437L,(-1L)},{0xDD39B848L,0L,(-1L),0x0799FA52L},{(-1L),0x0799FA52L,0L,0x0799FA52L}},{{0x641FE7F3L,0L,(-1L),(-1L)},{0x22CC248DL,(-1L),0x0799FA52L,0x7D02BC70L},{(-1L),0x641FE7F3L,0L,0L}},{{(-1L),(-1L),0x0799FA52L,3L},{0x22CC248DL,0L,(-1L),(-1L)},{0x641FE7F3L,0xDD39B848L,0L,(-1L)}},{{(-1L),0xDD39B848L,(-1L),(-1L)},{0xDD39B848L,0L,0x5E468437L,3L},{3L,(-1L),0x641FE7F3L,0L}},{{0x7D02BC70L,0x641FE7F3L,0x641FE7F3L,0x7D02BC70L},{3L,(-1L),0x5E468437L,(-1L)},{0xDD39B848L,0L,(-1L),0x0799FA52L}},{{(-1L),0x0799FA52L,0L,0x0799FA52L},{0x641FE7F3L,0L,(-1L),(-1L)},{0x22CC248DL,(-1L),0x0799FA52L,0x7D02BC70L}},{{(-1L),0x641FE7F3L,0L,0L},{(-1L),(-1L),0x0799FA52L,3L},{0x22CC248DL,0L,(-1L),(-1L)}}};
        int8_t l_348 = 1L;
        int32_t l_349[2];
        int32_t l_375 = 0xA66D8ECDL;
        int32_t l_376 = 0x60344EB4L;
        uint16_t l_389 = 0x6F8FL;
        uint32_t l_465[9][6] = {{4294967295UL,4294967295UL,0x6C58D8B7L,4294967295UL,4294967295UL,0x6C58D8B7L},{4294967295UL,4294967295UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL}};
        int i, j, k;
        for (i = 0; i < 2; i++)
            l_349[i] = 2L;
        if ((((((safe_rshift_func_uint16_t_u_s((!(safe_add_func_uint8_t_u_u(l_309, (g_3261 | ((((l_660 = (((l_333 ^ (!((g_3409 & p_43) & (g_3409 & 0x5C2909C2L)))) >= (((l_335[6][1][3] = g_3261) == 0x9128L) && 0x20EB86FDL)) <= 0x8FL)) && l_310) == 0x845DL) <= 0xC565EBF9L))))), 9)) ^ g_115) && g_3409) | l_333) <= g_3409))
        {
            uint16_t l_336 = 0UL;
            int32_t l_345 = 0xF6AF8E6AL;
            l_349[1] = (l_348 = (l_336 & (safe_lshift_func_uint8_t_u_s((((safe_mod_func_uint8_t_u_u((~(+(l_335[6][1][3] = 1UL))), ((safe_mod_func_uint8_t_u_u((l_345 = 0xBDL), ((0xB66F0254L < (safe_rshift_func_int8_t_s_s((4L < g_3409), (((-1L) & (l_310 < ((l_62 & g_3409) != 0L))) ^ 249UL)))) & 3UL))) || g_3409))) <= (-1L)) != l_310), l_333))));
            for (g_3261 = 0; (g_3261 >= 27); g_3261++)
            {
                return l_345;
            }
        }
        else
        {
            uint8_t l_360 = 0x60L;

{
                    i = 0x97E65834L;
                }

                    g_115 = ((((g_3409 >= (4294967290UL >= g_540)) <= (l_797 = (g_3409 && (((safe_sub_func_int8_t_s_s((((!(g_3409 || (l_309 = (safe_rshift_func_uint16_t_u_s(g_359[9][0], (((g_2420 < 65535UL) > g_172[1]) ^ 0x17L)))))) == l_360) <= g_3409), g_3409)) != g_172[8]) | g_3409)))) != g_3261) | g_3421);

{
    uint8_t l_79[5][2][1] = {{{0xCDL},{0x09L}},{{0xCDL},{0x09L}},{{0xCDL},{0x09L}},{{0xCDL},{0x09L}},{{0xCDL},{0x09L}}};
    int32_t l_80 = 0x7FAA682DL;
    int32_t l_88 = 0x3CEB4B62L;
    int32_t l_117 = 0x9AA43C15L;
    int16_t l_201 = 9L;
    int32_t l_259 = (-1L);
    int32_t l_268 = (-9L);
    int i, j, k;
    for (l_796 = 0; (l_796 <= 0); l_796 += 1)
    {
        uint8_t l_87 = 1UL;
        int32_t l_104[6][9] = {{0xAA260870L,(-1L),(-1L),0xAA260870L,(-1L),(-1L),0xAA260870L,0x21B11E67L,0x21B11E67L},{0xB10BEF9BL,0L,0x691EA77CL,0xB10BEF9BL,0x691EA77CL,0L,0xB10BEF9BL,0L,0L},{0xAA260870L,(-1L),(-1L),0xAA260870L,(-1L),(-1L),0xAA260870L,0x21B11E67L,0x21B11E67L},{0xB10BEF9BL,0L,0x691EA77CL,0xB10BEF9BL,0x691EA77CL,(-6L),0L,(-9L),(-9L)},{0x21B11E67L,0x1F4E5A65L,8L,0x21B11E67L,8L,0x1F4E5A65L,0x21B11E67L,0x37DDF4F0L,0x37DDF4F0L},{0L,(-6L),(-1L),0L,(-1L),(-6L),0L,(-9L),(-9L)}};
        int32_t l_262 = 0xC8414168L;
        int32_t l_263[3][2];
        int16_t l_306 = 1L;
        int i, j;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 2; j++)
                l_263[i][j] = 0x2B217F77L;
        }
        l_80 = l_660;
        for (l_80 = 0; (l_80 >= 0); l_80 -= 1)
        {
            int32_t l_82 = 1L;
            int8_t l_118 = (-1L);
            int32_t l_136 = 0x05D4F871L;
            int32_t l_160[9][3] = {{(-6L),(-6L),(-6L)},{0xE17D4CA5L,0xE17D4CA5L,0xE17D4CA5L},{(-6L),(-6L),(-6L)},{0xE17D4CA5L,0xE17D4CA5L,0xE17D4CA5L},{(-6L),(-6L),(-6L)},{0xE17D4CA5L,0xE17D4CA5L,0xE17D4CA5L},{(-6L),(-6L),(-6L)},{0xE17D4CA5L,0xE17D4CA5L,0xE17D4CA5L},{(-6L),(-6L),(-6L)}};
            int i, j;
            g_83 = (g_541 = (!l_82));
            if (((l_88 = (g_83 != (((safe_lshift_func_uint8_t_u_u(g_3781, l_79[3][1][0])) < ((((~l_660) != (l_82 = 0L)) && ((((0x7DD3L > 1UL) | l_87) != ((g_83 && g_1524) == l_87)) || l_87)) <= g_1524)) >= (-7L)))) && 0UL))
            {
                if (g_1524)
                    break;
            }
            else
            {
                if (l_796)
                    break;
            }
            for (l_87 = 0; (l_87 <= 0); l_87 += 1)
            {
                int32_t l_89 = 0x625CAFD9L;
                int32_t l_114 = (-1L);
                uint16_t l_116[10][5] = {{1UL,65534UL,0x3A66L,1UL,0x3A66L},{65535UL,65535UL,0x22B0L,0x65DDL,0x46F2L},{0xAA81L,0xE6F9L,0x3A66L,0x3A66L,0xE6F9L},{0x46F2L,0x35CAL,65526UL,0x46F2L,1UL},{0xCAF6L,0xE6F9L,0xBCFCL,0xE6F9L,0xCAF6L},{65526UL,65535UL,0x35CAL,1UL,65535UL},{0xCAF6L,65534UL,65534UL,0xCAF6L,0x3A66L},{0x46F2L,0x65DDL,0x22B0L,65535UL,65535UL},{0xAA81L,0xCAF6L,0xAA81L,0x3A66L,0xCAF6L},{65535UL,0x35CAL,1UL,65535UL,1UL}};
                int32_t l_119 = 0x48BAA0A5L;
                int i, j, k;
                l_82 = l_79[(l_80 + 1)][l_796][l_796];
                g_541 = ((((((l_89 = l_79[(l_80 + 1)][(l_80 + 1)][l_80]) != (safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s(g_1524, (safe_unary_minus_func_uint16_t_u((g_1524 > (l_118 = (l_117 = (l_88 = ((l_796 || 1L) <= (safe_add_func_uint8_t_u_u(((safe_sub_func_int16_t_s_s((l_796 && (l_104[5][6] = (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u((g_2598 = l_796), 7)), 1)))), (l_577 = ((safe_lshift_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u((+g_83), (safe_add_func_int8_t_s_s((((safe_sub_func_int16_t_s_s((((((l_114 = (l_660 || l_660)) < g_541) && g_541) | l_660) || l_660), 0xA0AEL)) == l_79[1][0][0]) != 5UL), l_660)))) | g_3781), 7)) & g_1524)))) && l_116[3][1]), l_660))))))))))), l_796))) <= 0UL) == l_80) > l_82) && g_83);
                for (l_114 = 0; (l_114 <= 0); l_114 += 1)
                {
                    for (l_89 = 0; (l_89 <= 0); l_89 += 1)
                    {
                        uint16_t l_131 = 1UL;
                        l_104[5][6] = g_1524;
                        l_119 = (-1L);
                        g_541 = (safe_add_func_uint16_t_u_u((l_136 = (safe_sub_func_int8_t_s_s(((0UL == 249UL) > ((l_82 = l_660) || (safe_mod_func_uint32_t_u_u(((0x01A3L | (((4294967288UL ^ (~(((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s(((l_131 >= l_660) > l_88), (safe_sub_func_int16_t_s_s((safe_mod_func_int8_t_s_s((g_1524 >= g_2598), 0x7DL)), 65532UL)))), l_104[5][0])) | 0UL) || (-1L)))) < g_2598) != l_577)) ^ (-1L)), l_796)))), l_118))), 0x6CB3L));
                    }
                    if (l_577)
                        break;
                }
                l_119 = g_541;
            }
            for (l_118 = 0; (l_118 <= 0); l_118 += 1)
            {
                uint8_t l_158 = 0UL;
                int32_t l_193 = (-1L);
                int16_t l_218 = 0x7D3DL;
                for (l_577 = 0; (l_577 <= 0); l_577 += 1)
                {
                    int i, j, k;
                    g_541 = (safe_add_func_int16_t_s_s((l_79[(l_577 + 4)][(l_796 + 1)][l_118] || l_660), g_83));
                    if (l_660)
                        continue;
                }
                if ((l_136 = g_541))
                {
                    uint32_t l_145 = 0x463E212FL;
                    int32_t l_159 = 0x7C7E8E6BL;
                    int i, j, k;
                    l_160[1][0] = (l_660 | ((safe_mod_func_int8_t_s_s((((safe_mod_func_int8_t_s_s((((safe_add_func_int16_t_s_s(l_145, l_145)) >= (safe_mod_func_uint16_t_u_u((g_540 = (9UL >= (safe_lshift_func_int16_t_s_u(((0x9404BF6FL & (safe_unary_minus_func_uint8_t_u(((l_79[(l_118 + 3)][l_796][l_796] = (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((((l_82 = (safe_unary_minus_func_uint32_t_u((safe_rshift_func_uint8_t_u_u((0xA192L <= ((l_159 = (((((l_136 = ((l_88 = (-1L)) >= (((0UL & l_80) < g_83) <= l_660))) || 0xA3C1A26CL) <= l_158) | l_577) > 0x4CD6L)) | g_541)), l_660))))) && 1L) && (-4L)), l_796)), 7))) != 0x87L)))) | l_160[1][0]), 5)))), g_541))) ^ g_1524), l_660)) < 0xB1L) <= l_80), g_1524)) && l_104[3][0]));
                    if (((((g_1460 = ((l_104[5][6] = l_660) >= (((g_541 = 0x3B790C2EL) != (((safe_rshift_func_uint16_t_u_u(l_796, 14)) ^ (0xCE46L <= (safe_lshift_func_int8_t_s_s((((safe_mod_func_int32_t_s_s((((safe_add_func_uint32_t_u_u(((g_83 = ((l_87 ^ l_87) ^ 65526UL)) >= ((g_172[4] = ((((-1L) != (safe_add_func_uint8_t_u_u((g_1524 || 0x6976L), l_160[3][0]))) < g_2598) <= g_540)) != 0UL)), 6UL)) < l_796) < l_577), l_117)) & g_1524) || 1UL), 6)))) >= 0x8CL)) & l_796))) || g_1524) <= 0xA9L) ^ l_660))
                    {
                        g_541 = (l_118 != l_660);
                    }
                    else
                    {
                        return g_3781;
                    }
                    for (g_540 = 0; (g_540 == 42); g_540 = safe_add_func_uint32_t_u_u(g_540, 6))
                    {
                        if (l_660)
                            break;
                        l_160[1][0] = g_2598;
                        l_842 = ((l_158 && (safe_add_func_uint32_t_u_u((safe_add_func_uint32_t_u_u(g_1524, (safe_add_func_uint8_t_u_u(l_104[5][6], (l_160[2][1] = l_158))))), (((safe_sub_func_int32_t_s_s((l_159 = (g_541 = l_79[(l_118 + 3)][l_796][l_796])), (((4294967295UL < (safe_sub_func_int8_t_s_s(l_660, (7L ^ (safe_sub_func_int8_t_s_s((g_1524 < g_1460), g_1524)))))) || g_172[4]) > l_158))) & l_104[5][6]) >= 0x816EFC97L)))) ^ g_83);
                    }
                }
                else
                {
                    int8_t l_204 = (-1L);
                    int32_t l_205 = 0xA341128DL;
                    if ((0xB969A7E2L != (l_660 == (safe_mod_func_int32_t_s_s(g_1524, 0x24DCF8C1L)))))
                    {
                        l_193 = (((-1L) <= (safe_lshift_func_int8_t_s_s(l_842, l_796))) > l_160[7][2]);
                        l_193 = 0L;
                        if (l_796)
                            break;
                    }
                    else
                    {
                        int32_t l_203 = (-8L);
                        l_104[1][7] = (0x8075L != ((g_1524 = l_87) >= (l_660 && (0xAB5394E2L >= 0UL))));
                        g_541 = (((l_88 = (((l_660 | 0UL) < (g_2598 && ((l_205 = (((g_1460 && g_1524) > (safe_sub_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((g_541 > ((safe_mod_func_int16_t_s_s(((g_3781 <= (((~l_201) != (((((((+(g_1524 > g_1460)) && g_1460) <= g_1524) > 3UL) == l_660) > l_203) >= l_660)) ^ 0xE3DCAB47L)) >= l_204), 0xEE06L)) == 0x9DDDL)), 0xE14EL)) && l_203), 0UL))) <= g_172[4])) == l_660))) && (-2L))) | 0xBAB4L) || 1UL);
                        return g_1460;
                    }
                    l_193 = (safe_lshift_func_uint8_t_u_s(((-2L) == (safe_rshift_func_int8_t_s_s((((g_1524 & ((safe_add_func_int16_t_s_s((0xE4L || (safe_rshift_func_uint8_t_u_s(g_172[4], g_541))), (l_218 = (g_1460 = ((l_117 < 0xAD95808BL) ^ ((safe_rshift_func_int8_t_s_s((safe_unary_minus_func_int16_t_s(l_842)), ((0x4EEEL == 6L) && 0xC3D4A470L))) || l_660)))))) > (-1L))) <= l_577) == l_82), g_541))), 1));
                }
                g_541 = (((-1L) | l_796) > (+l_218));
                g_541 = ((((l_88 = (safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(((0x4A28L >= l_660) || ((g_540 = ((safe_sub_func_uint8_t_u_u(l_218, (safe_rshift_func_uint8_t_u_s(l_82, (+0xA994BE0AL))))) || ((safe_lshift_func_uint8_t_u_u((l_218 != (safe_lshift_func_int8_t_s_s(g_2598, 3))), 4)) < ((safe_mod_func_int8_t_s_s(g_1460, (safe_lshift_func_uint16_t_u_u(((-1L) <= 1UL), g_1524)))) < 0x90L)))) >= g_541)), 7)), l_660))) == 0L) & l_158) < 0x193FL);
            }
        }
        if (((l_842 <= 0L) ^ 0xA2L))
        {
            uint16_t l_237 = 65526UL;
            int32_t l_260[5];
            int32_t l_261 = 4L;
            uint32_t l_274[7][10] = {{0x9183A3A1L,0xD0E7BC49L,1UL,4294967295UL,0x4EE4472DL,1UL,0xFA7611F6L,0x0EC4D18DL,0x0EC4D18DL,0xFA7611F6L},{4294967295UL,0x9183A3A1L,4294967295UL,4294967295UL,0x9183A3A1L,4294967295UL,4294967295UL,1UL,0xBC1D7A0BL,0UL},{0UL,0x0EC4D18DL,0xD0E7BC49L,1UL,1UL,0UL,4294967295UL,0UL,1UL,1UL},{0UL,0UL,0UL,4294967292UL,0xFA7611F6L,4294967295UL,1UL,0x4EE4472DL,0xD0E7BC49L,1UL},{4294967295UL,1UL,0x4EE4472DL,0xD0E7BC49L,1UL,1UL,0xD0E7BC49L,0x4EE4472DL,1UL,4294967295UL},{0x9183A3A1L,0x45722FB2L,0UL,0x0EC4D18DL,0xD0E7BC49L,1UL,1UL,0UL,4294967295UL,0UL},{0xBC1D7A0BL,0UL,0xD0E7BC49L,0x45722FB2L,0xD0E7BC49L,0UL,0xBC1D7A0BL,1UL,4294967295UL,4294967295UL}};
            int16_t l_277[9][10][2] = {{{1L,8L},{0x6338L,0L},{(-1L),7L},{0x35ABL,1L},{(-6L),0L},{0x372EL,0x97CDL},{1L,0xDD2AL},{0L,0x35ABL},{(-1L),0L},{3L,0x78A7L}},{{8L,3L},{0x38AEL,0x78A7L},{0x795CL,1L},{0x0659L,0xDD2AL},{1L,1L},{0xF30DL,0x12BCL},{8L,(-7L)},{7L,0xA12CL},{(-1L),1L},{0x78A7L,(-1L)}},{{0x12BCL,(-1L)},{0x78A7L,1L},{(-1L),0xA12CL},{7L,(-7L)},{8L,0x12BCL},{0xF30DL,1L},{1L,0xDD2AL},{0x0659L,1L},{0x795CL,0x78A7L},{0x38AEL,7L}},{{0x0659L,0L},{7L,1L},{7L,0x372EL},{8L,7L},{(-7L),0xA12CL},{1L,8L},{0x78A7L,0x2EBBL},{0x372EL,(-1L)},{0x679DL,8L},{(-1L),(-4L)}},{{(-7L),(-7L)},{1L,0x372EL},{0xF30DL,1L},{7L,0xDD2AL},{0L,7L},{0x795CL,0x679DL},{0x795CL,7L},{0L,0xDD2AL},{7L,1L},{0xF30DL,0x372EL}},{{1L,(-7L)},{(-7L),(-4L)},{(-1L),8L},{0x679DL,(-1L)},{0x372EL,0x2EBBL},{0x78A7L,8L},{1L,0xA12CL},{(-7L),7L},{8L,0x372EL},{7L,1L}},{{7L,0L},{0x0659L,7L},{0x38AEL,0x78A7L},{0x795CL,1L},{0x0659L,0xDD2AL},{1L,1L},{0xF30DL,0x12BCL},{8L,(-7L)},{7L,0xA12CL},{(-1L),1L}},{{0x78A7L,(-1L)},{0x12BCL,(-1L)},{0x78A7L,1L},{(-1L),0xA12CL},{7L,(-7L)},{8L,0x12BCL},{0xF30DL,1L},{1L,0xDD2AL},{0x0659L,1L},{0x795CL,0x78A7L}},{{0x38AEL,7L},{0x0659L,0L},{7L,1L},{7L,0x372EL},{8L,7L},{(-7L),0xA12CL},{1L,8L},{0x78A7L,0x2EBBL},{0x372EL,(-1L)},{0x679DL,8L}}};
            int i, j, k;
            for (i = 0; i < 5; i++)
                l_260[i] = 0L;
            l_263[2][0] = (l_237 != (l_262 = (((0xF55769E9L != (l_80 = (safe_rshift_func_uint16_t_u_u(((l_261 = (safe_add_func_int32_t_s_s((+l_237), (l_104[5][6] = ((l_260[0] = (safe_rshift_func_uint16_t_u_s((safe_add_func_uint16_t_u_u((g_3484 || (!(safe_mod_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((l_117 ^ (safe_mod_func_uint8_t_u_u((safe_sub_func_int16_t_s_s((safe_add_func_uint16_t_u_u(0x7869L, (l_259 | 0L))), 0x508AL)), g_1524))), 1UL)), l_104[0][6])))), l_796)), l_842))) == 0x2AFEL))))) == g_540), l_259)))) <= g_1524) != 0x68L)));
            l_104[5][6] = (safe_add_func_uint32_t_u_u(((((((safe_add_func_int8_t_s_s(l_268, l_660)) >= g_1524) >= (g_83 = (safe_unary_minus_func_uint32_t_u(g_172[4])))) > (((safe_lshift_func_int8_t_s_s((0xF631L < (((0x9B79L < (safe_rshift_func_uint16_t_u_u((l_274[4][1] < (l_117 = ((safe_rshift_func_int8_t_s_u(l_277[8][8][0], l_660)) == 0xB7205401L))), g_1460))) >= g_172[4]) || g_172[6])), 1)) != g_172[1]) | l_237)) == l_263[0][1]) >= l_660), 0UL));
        }
        else
        {
            int16_t l_295 = 0x4B2EL;
            int32_t l_305 = 0L;
            g_3484 = (safe_sub_func_int8_t_s_s((((~(safe_rshift_func_uint8_t_u_s(((((g_1460 = ((safe_add_func_int8_t_s_s(g_1524, (safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s((safe_rshift_func_int8_t_s_s((0x6986D460L | ((((safe_mod_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s(l_295, 3)) > ((0x1AC507ADL >= (((safe_unary_minus_func_uint8_t_u((safe_add_func_uint8_t_u_u((l_262 = (safe_lshift_func_int16_t_s_u(((250UL && (l_104[5][6] = ((l_305 = ((safe_add_func_int32_t_s_s((safe_mod_func_int8_t_s_s(g_541, g_1524)), l_660)) & ((l_660 == g_1524) ^ l_660))) ^ l_660))) >= l_262), 3))), 0x05L)))) >= l_87) || 0x4A90L)) < l_268)) < g_3484), 65535UL)) < 0x0D65L) & 0x98E9L) >= l_201)), 3)), 2)) > 0x7EF9L), g_1460)))) >= l_660)) <= 0L) != l_306) || 0xBECC66A6L), l_259))) >= l_660) >= g_1524), l_660));
        }
        l_104[5][5] = (l_263[0][0] = ((safe_add_func_int32_t_s_s(g_1524, l_117)) == ((1UL || 0x8C5AC05FL) | g_172[5])));
    }
    return l_80;
}

                    l_309 = ((safe_lshift_func_uint8_t_u_u((l_376 = (safe_lshift_func_int8_t_s_u(g_3409, ((l_310 || (l_349[1] = g_3409)) & ((safe_lshift_func_int16_t_s_s(((safe_lshift_func_uint16_t_u_u((safe_rshift_func_int16_t_s_s((((l_335[6][1][3] = (l_62 <= (g_172[8] != 0xE7FBL))) && (safe_unary_minus_func_uint32_t_u((l_637 <= 0x63L)))) | (((((((safe_add_func_int32_t_s_s(((l_375 = (g_3409 ^ l_637)) & (-1L)), g_3409)) ^ g_3409) | 0x727FL) || 0xC8A15306L) != 5L) && g_172[4]) <= 247UL)), 6)), 15)) ^ (-1L)), 15)) & g_3409))))), 2)) == g_3261);
            return g_3409;
        }
        l_309 = g_359[9][0];
        for (g_3409 = (-4); (g_3409 > 11); g_3409 = safe_add_func_int8_t_s_s(g_3409, 4))
        {
            int32_t l_379 = (-9L);
            int32_t l_447 = 0L;
            uint32_t l_491 = 0UL;
            for (l_375 = 2; (l_375 >= 0); l_375 -= 1)
            {
                uint8_t l_421[8];
                uint32_t l_426 = 1UL;
                int32_t l_427 = 0L;
                int32_t l_446[4][2][2] = {{{5L,5L},{0x7B32B138L,5L}},{{5L,0x7B32B138L},{5L,5L}},{{0x7B32B138L,5L},{5L,0x7B32B138L}},{{5L,5L},{0x7B32B138L,5L}}};
                uint8_t l_466 = 1UL;
                int i, j, k;
                for (i = 0; i < 8; i++)
                    l_421[i] = 0x31L;
                for (l_637 = 0; (l_637 <= 2); l_637 += 1)
                {
                    int16_t l_380[5][5] = {{(-1L),0L,0x3ED2L,(-1L),0x3ED2L},{(-1L),(-1L),7L,0x22E4L,0x4688L},{0xF476L,0x4688L,0x3ED2L,0x3ED2L,0x4688L},{0x4688L,0L,0xF476L,0x4688L,0x3ED2L},{0x22E4L,0x4688L,7L,0x4688L,0x22E4L}};
                    int32_t l_390[10] = {0xBF810539L,0x88F1ED79L,0xBF810539L,0xBF810539L,0x88F1ED79L,0xBF810539L,0xBF810539L,0x88F1ED79L,0xBF810539L,0xBF810539L};
                    int i, j;
                    for (p_43 = 0; (p_43 <= 2); p_43 += 1)
                    {
                        int i, j, k;
                        l_380[1][4] = (l_335[(l_375 + 5)][p_43][p_43] = (0xB5F2L > (l_379 = 0x9A89L)));
                    }
                    if (g_3409)
                        {
for (g_3484 = 0; g_3484 < 10; g_3484++)
        {
            transparent_crc(g_866[l_309][g_3484], "g_866[l_309][g_3484]", l_608);
            if (l_608) printf("index = [%d][%d]\n", l_309, g_3484);

        };


                    break;}

l_492 -= 1;


                    g_115 = (safe_sub_func_int8_t_s_s(((safe_mod_func_int32_t_s_s(((l_390[7] = (l_62 != (safe_sub_func_uint32_t_u_u((g_359[9][0] = (0xB2L >= (6L > ((((((((safe_add_func_uint8_t_u_u(((((l_379 != l_389) && (g_3409 ^ (g_3409 & (g_172[(l_375 + 2)] = ((g_3409 != 0x7FL) != 0L))))) >= g_359[9][0]) & g_3409), g_3409)) & 1UL) && 0xDAB7L) | l_349[1]) < g_3421) >= g_3409) >= g_3261) ^ (-1L))))), (-5L))))) != g_3421), g_3409)) != g_3409), g_3409));
                }
                if ((l_310 != (safe_mod_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((((safe_lshift_func_int8_t_s_u((safe_add_func_uint16_t_u_u(((p_43 = (l_376 = ((safe_sub_func_uint16_t_u_u(((((safe_sub_func_uint8_t_u_u(((g_540 = ((((safe_unary_minus_func_uint8_t_u((l_349[1] = (l_406 = g_3409)))) || ((safe_rshift_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_u((((safe_add_func_int32_t_s_s((-3L), (safe_add_func_uint16_t_u_u(((g_3261 = (l_335[6][1][3] = (safe_rshift_func_uint8_t_u_s((((l_426 = ((safe_sub_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u(l_421[6], 1UL)), ((g_3409 = (-1L)) > ((safe_add_func_uint8_t_u_u((g_172[6] > (g_359[9][0] = l_421[2])), (((g_3409 = (safe_rshift_func_uint16_t_u_s(l_637, 8))) >= 249UL) || 0x8A7F073DL))) & 0x32L)))) != 0xCA9CL)) != l_406) == 0x14L), 1)))) >= l_797), l_349[1])))) & (-1L)) || l_379), l_349[1])) < g_3409), 2)) ^ g_3421)) != g_2420) == 2L)) != g_172[5]), l_421[6])) < g_3409) >= l_797) & 0x1F63E348L), 7L)) ^ 0x40L))) != l_427), l_637)), 7)) <= l_421[6]) >= g_3409), g_172[4])), l_660)), 0x41L))))
                {
                    int8_t l_445 = 0x02L;
                    l_309 = ((safe_sub_func_int32_t_s_s(1L, (l_797 = (0xCFL > (g_115 == (((((safe_rshift_func_uint8_t_u_s((((g_3261 = l_406) <= g_3421) || ((safe_mod_func_int8_t_s_s(((g_3409 = 0L) < (safe_mod_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u((~(safe_unary_minus_func_uint8_t_u(g_3409))), (~(l_376 = (safe_mod_func_int8_t_s_s(g_115, (safe_lshift_func_uint16_t_u_s(((0x0C28L & l_445) || 1UL), l_348)))))))) ^ 0UL), 0x7BD5L))), 0xDEL)) & g_3409)), g_3409)) < 0xD2L) || 4294967295UL) <= 0L) || l_446[3][0][0])))))) && g_3409);
                    l_447 = g_3409;
                }
                else
                {
                    uint32_t l_456[9][6][4] = {{{0x5997C0ABL,0x5CE5605DL,0x493FBAA3L,0x31A615D8L},{0x5CE5605DL,5UL,5UL,0x5CE5605DL},{1UL,0x31A615D8L,5UL,0x26A8E26AL},{0x5CE5605DL,0x5997C0ABL,0x493FBAA3L,0x5997C0ABL},{0x5997C0ABL,5UL,1UL,0x5997C0ABL},{1UL,0x5997C0ABL,0x26A8E26AL,0x26A8E26AL}},{{0x31A615D8L,0x31A615D8L,0x493FBAA3L,0x5CE5605DL},{0x31A615D8L,5UL,0x26A8E26AL,0x31A615D8L},{1UL,0x5CE5605DL,1UL,0x26A8E26AL},{0x5997C0ABL,0x5CE5605DL,0x493FBAA3L,0x31A615D8L},{0x5CE5605DL,5UL,5UL,0x5CE5605DL},{1UL,0x31A615D8L,5UL,0x26A8E26AL}},{{0x5CE5605DL,0x5997C0ABL,0x493FBAA3L,0x5997C0ABL},{0x5997C0ABL,5UL,1UL,0x5997C0ABL},{1UL,0x5997C0ABL,0x26A8E26AL,0x26A8E26AL},{0x31A615D8L,0x31A615D8L,0x493FBAA3L,0x5CE5605DL},{0x31A615D8L,5UL,0x26A8E26AL,0x31A615D8L},{1UL,0x5CE5605DL,1UL,0x26A8E26AL}},{{0x5997C0ABL,0x5CE5605DL,0x493FBAA3L,0x31A615D8L},{0x5CE5605DL,5UL,5UL,0x5CE5605DL},{1UL,0x31A615D8L,5UL,0x26A8E26AL},{0x5CE5605DL,0x5997C0ABL,0x493FBAA3L,0x5997C0ABL},{0x5997C0ABL,5UL,1UL,0x5997C0ABL},{1UL,0x26A8E26AL,1UL,1UL}},{{1UL,1UL,0x31A615D8L,5UL},{1UL,0x493FBAA3L,1UL,1UL},{0xCEFF6648L,5UL,0xCEFF6648L,1UL},{0x26A8E26AL,5UL,0x31A615D8L,1UL},{5UL,0x493FBAA3L,0x493FBAA3L,5UL},{0xCEFF6648L,1UL,0x493FBAA3L,1UL}},{{5UL,0x26A8E26AL,0x31A615D8L,0x26A8E26AL},{0x26A8E26AL,0x493FBAA3L,0xCEFF6648L,0x26A8E26AL},{0xCEFF6648L,0x26A8E26AL,1UL,1UL},{1UL,1UL,0x31A615D8L,5UL},{1UL,0x493FBAA3L,1UL,1UL},{0xCEFF6648L,5UL,0xCEFF6648L,1UL}},{{0x26A8E26AL,5UL,0x31A615D8L,1UL},{5UL,0x493FBAA3L,0x493FBAA3L,5UL},{0xCEFF6648L,1UL,0x493FBAA3L,1UL},{5UL,0x26A8E26AL,0x31A615D8L,0x26A8E26AL},{0x26A8E26AL,0x493FBAA3L,0xCEFF6648L,0x26A8E26AL},{0xCEFF6648L,0x26A8E26AL,1UL,1UL}},{{1UL,1UL,0x31A615D8L,5UL},{1UL,0x493FBAA3L,1UL,1UL},{0xCEFF6648L,5UL,0xCEFF6648L,1UL},{0x26A8E26AL,5UL,0x31A615D8L,1UL},{5UL,0x493FBAA3L,0x493FBAA3L,5UL},{0xCEFF6648L,1UL,0x493FBAA3L,1UL}},{{5UL,0x26A8E26AL,0x31A615D8L,0x26A8E26AL},{0x26A8E26AL,0x493FBAA3L,0xCEFF6648L,0x26A8E26AL},{0xCEFF6648L,0x26A8E26AL,1UL,1UL},{1UL,1UL,0x31A615D8L,5UL},{1UL,0x493FBAA3L,1UL,1UL},{0xCEFF6648L,5UL,0xCEFF6648L,1UL}}};
                    int i, j, k;
                    for (l_426 = 0; (l_426 <= 1); l_426 += 1)
                    {
                        int i;
                        l_349[l_426] = (safe_rshift_func_int16_t_s_s((safe_sub_func_int16_t_s_s(0x6C4BL, (-8L))), l_349[l_426]));
                    }

if (((((safe_rshift_func_uint16_t_u_s(l_576, (((0x6C58L == (l_703 > l_796)) >= (l_648[7] = ((g_115 = (l_609 && l_609)) ^ ((safe_mod_func_int32_t_s_s(g_173, 4294967294UL)) == (safe_mod_func_uint16_t_u_u(((((safe_add_func_int16_t_s_s((p_43 = ((0x2415FF63L < l_796) | g_2420)), l_406)) == 3L) < l_796) || (-1L)), l_814)))))) > l_796))) < 1UL) >= l_814) == l_466))
        {
            uint32_t l_660 = 18446744073709551606UL;
            int32_t l_703 = 0x45EA0260L;
            int32_t l_719 = 0xF66FE10FL;
            int16_t l_842 = 0xD120L;
            uint32_t l_850 = 0x6743DD51L;
            g_115 = ((((safe_lshift_func_int8_t_s_s(l_609, (safe_mod_func_uint32_t_u_u((p_43 | (safe_lshift_func_int16_t_s_u(((safe_rshift_func_int8_t_s_s(0x19L, 0)) ^ l_796), ((((safe_rshift_func_int16_t_s_u(((g_2420 = 0xF9L) < ((g_63 < (0x1F6080AFL < l_609)) != g_2598)), 0)) >= l_660) ^ g_63) || g_543[1])))), 0x58400C79L)))) & l_609) > 0xEFL) & g_2598);
            l_703 = (-1L);
            for (g_2598 = 0; (g_2598 <= 57); ++g_2598)
            {
                uint16_t l_676[2][10] = {{0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL},{0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL}};
                uint32_t l_678 = 5UL;
                int32_t l_692[9] = {0x28905217L,0x28905217L,0x28905217L,0x28905217L,0x28905217L,0x28905217L,0x28905217L,0x28905217L,0x28905217L};
                uint32_t l_743[2][4] = {{0UL,4294967295UL,4294967295UL,0UL},{4294967295UL,0UL,4294967295UL,4294967295UL}};
                int32_t l_797 = 1L;
                int i, j;
                for (g_3484 = 2; (g_3484 >= 0); g_3484 -= 1)
                {
                    uint16_t l_669 = 0x0983L;
                    int32_t l_677 = 0L;
                    int i;
                    l_609 = ((l_545[g_3484] > (safe_add_func_int32_t_s_s(((g_115 = (~g_543[1])) == l_660), (p_43 & (safe_sub_func_int16_t_s_s(((((l_545[2] >= (l_577 = (((((+l_669) < ((((((safe_mod_func_uint32_t_u_u((((((safe_rshift_func_uint8_t_u_s(l_814, 6)) > ((0UL | (safe_mod_func_uint32_t_u_u((6L && 1L), l_676[0][3]))) || p_43)) >= 8UL) != g_359[3][2]) < l_814), g_359[6][1])) && l_676[0][8]) ^ g_3484) < l_678) != l_375) || 0xAB7CL)) ^ g_3152) || l_545[1]) || 0x409AL))) == g_2420) ^ g_359[1][4]) && 0x8AE5680CL), p_43)))))) <= l_545[1]);
                    l_677 = (g_115 = l_678);
                    if ((p_43 != (l_609 >= ((0x0DL || (4UL ^ l_678)) <= (safe_mod_func_uint32_t_u_u(((safe_add_func_int32_t_s_s((safe_mod_func_uint32_t_u_u((((safe_mod_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u((l_677 = (safe_unary_minus_func_uint32_t_u((safe_add_func_int32_t_s_s((((p_43 || (l_692[0] = (l_796 = 0x5548L))) == (safe_sub_func_int8_t_s_s((l_576 = p_43), (safe_mod_func_int8_t_s_s(l_814, p_43))))) && l_545[2]), l_814))))), 6)) ^ 0x54L), g_3484)) == 0L) != 0xEBCD03DFL), 5UL)), 6L)) <= l_814), 4294967290UL))))))
                    {
                        uint32_t l_720 = 0UL;
                        int32_t l_721 = 7L;
                        l_692[0] = (safe_sub_func_int16_t_s_s(((l_814 = (safe_add_func_uint8_t_u_u(0x83L, (((safe_add_func_int8_t_s_s(g_172[4], (l_703 = p_43))) ^ (~(l_677 = (safe_rshift_func_int16_t_s_u((((safe_rshift_func_int8_t_s_s((l_721 = (4UL || ((-1L) == (((safe_lshift_func_uint8_t_u_s((safe_sub_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u(65535UL, 2)), (safe_rshift_func_int16_t_s_s((l_609 && ((l_719 = ((safe_mod_func_uint8_t_u_u(((l_814 < l_660) && g_172[4]), 0x9AL)) <= l_814)) != l_660)), l_720)))), l_678)) && 0x78L) ^ l_678)))), 6)) || p_43) ^ 0xF1F3L), 3))))) || 6UL)))) & 0UL), 5UL));
                    }
                    else
                    {
                        int16_t l_744 = 0x456EL;
                        l_719 = (safe_sub_func_int8_t_s_s((1L ^ l_609), ((l_375 && (safe_lshift_func_int8_t_s_u(((safe_lshift_func_uint8_t_u_s((safe_unary_minus_func_uint32_t_u((g_359[1][5] = ((safe_add_func_uint8_t_u_u((((safe_rshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s((((((safe_lshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s((7L > (safe_lshift_func_uint8_t_u_u(l_703, 7))), (l_466 && (((l_677 = ((4294967295UL >= (safe_lshift_func_int16_t_s_s((l_375 | l_406), l_703))) || g_2420)) <= l_466) | 0x11L)))), 0)) < l_743[1][3]) || l_678) == 0x50L) ^ l_744), l_348)), 2)) < l_576) >= g_543[1]), l_577)) && l_348)))), 7)) & l_743[1][3]), g_115))) == 1L)));
                        l_703 = (safe_add_func_uint32_t_u_u(g_2598, (((safe_mod_func_uint8_t_u_u(((safe_mod_func_uint8_t_u_u((((l_719 = (((p_43 <= ((l_703 == (l_703 = 65531UL)) != ((6L <= ((safe_sub_func_int32_t_s_s(((l_692[4] = (safe_add_func_int32_t_s_s((p_43 && ((l_677 = (safe_unary_minus_func_int32_t_s(((l_814 >= 0xED81L) & (safe_add_func_uint16_t_u_u((0xADA9L != p_43), l_796)))))) > 1L)), l_796))) == 0x15L), p_43)) ^ l_609)) & l_796))) ^ 0x4F420878L) == (-2L))) < 1UL) | (-1L)), g_173)) | l_796), l_609)) && l_678) > l_744)));
                        if (l_703)
                            break;
                        g_115 = ((safe_mod_func_int16_t_s_s(((g_359[9][0] == ((safe_add_func_uint16_t_u_u(((l_814 = (l_677 = l_814)) >= (0x1BL ^ (safe_add_func_int32_t_s_s((+(0x5B46L >= g_115)), l_669)))), (1L <= ((((((safe_mod_func_int16_t_s_s((safe_add_func_int16_t_s_s((l_577 <= ((((safe_rshift_func_int16_t_s_s(l_406, g_172[7])) & 6L) < g_543[1]) & l_348)), g_173)), g_2420)) || l_609) || p_43) & l_609) || p_43) || p_43)))) == l_814)) != l_814), l_744)) >= 65530UL);
                    }
                    for (l_678 = 1; (l_678 <= 6); l_678 += 1)
                    {
                        int i, j;
                        l_692[(g_3484 + 1)] = (g_115 = ((l_577 = ((((p_43 = ((g_115 = l_545[g_3484]) == (l_692[(g_3484 + 1)] | (safe_lshift_func_uint16_t_u_s((l_692[g_3484] & (((((g_359[(l_678 + 2)][(g_3484 + 3)] & (safe_sub_func_int16_t_s_s((g_103 > ((l_797 = ((!(safe_sub_func_int8_t_s_s((safe_add_func_uint16_t_u_u((+((safe_lshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s((safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u((((0x48A4D6C4L ^ (l_609 = ((0xF3L && (l_348 < ((safe_mod_func_uint8_t_u_u(((+(l_678 = p_43)) == g_3152), l_406)) && 0x3B13BD3CL))) >= l_743[0][3]))) >= l_648[7]) & l_703), l_669)) == l_796), 4)) >= l_814), 3L)), (-3L))), 12)) < g_359[(l_678 + 3)][(g_3484 + 1)])), 0L)), p_43))) <= g_173)) >= l_814)), 2L))) == 1UL) <= 0x73L) > g_543[0]) <= p_43)), 5))))) >= 5L) & p_43) || g_3152)) < l_814));
                        g_115 = (l_545[g_3484] >= (l_814 | g_543[1]));
                    }
                }
                g_115 = (((((safe_mod_func_uint8_t_u_u(g_359[1][0], (safe_rshift_func_uint8_t_u_u((safe_add_func_int32_t_s_s((((((l_648[4] = l_814) < ((0xBAAB71EFL < ((~g_115) <= (l_815[0] = (safe_add_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_u(((safe_add_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u(((g_813[1][0] > (g_3957 || (g_2420 = g_172[4]))) != (p_43 && (l_814 & l_814))), l_743[1][3])) <= l_609), g_172[4])) >= p_43), l_545[0])) > 1L) || g_813[1][0]), p_43))))) ^ l_797)) == 1L) | p_43) != g_359[9][0]), (-6L))), 6)))) > 0x22L) > l_743[1][3]) && l_676[0][3]) >= l_660);
                for (l_814 = 0; (l_814 >= 32); ++l_814)
                {
                    uint16_t l_830 = 0x915EL;
                    int32_t l_841 = 0x410F57C2L;
                    l_609 = (safe_unary_minus_func_uint8_t_u(((((l_719 = ((l_797 = (l_703 = ((safe_unary_minus_func_int16_t_s(0xA9D2L)) < ((0x78EDL != (safe_lshift_func_int8_t_s_u((g_2420 = (g_115 = (g_2420 && (((safe_mod_func_int16_t_s_s(0x3B07L, (safe_rshift_func_uint16_t_u_s((g_813[1][0] = (l_375 = l_703)), 7)))) && (((safe_rshift_func_uint16_t_u_s((safe_add_func_uint8_t_u_u((0xF815L && (g_3152 < p_43)), 0UL)), g_3484)) && l_796) == l_676[0][3])) >= g_172[4])))), 0))) && p_43)))) & l_609)) == l_814) <= l_830) <= 0x47D2L)));
                    l_703 = (l_703 || l_831[7]);
                    for (l_796 = 2; (l_796 <= 6); l_796 += 1)
                    {
                        int i;
                        l_609 = ((l_692[l_796] < ((0xFBL < (((0x48747109L == (0x97L | l_676[0][3])) & 0x46AA7A64L) >= (safe_mod_func_uint16_t_u_u(((~((((l_719 = (((0L < (safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(((p_43 = g_115) >= (l_841 = (safe_sub_func_uint16_t_u_u(l_692[l_796], 0xC2D2L)))), l_660)), 0xEBL))) ^ l_609) <= l_796)) || 0x0BL) >= 0x51L) || l_703)) != l_842), l_814)))) != 0xC8L)) >= 0xAB494884L);
                        g_115 = (0x9FADL & (l_609 > ((l_466 = (!(((0xAE45L > l_678) >= 0L) & (safe_sub_func_uint8_t_u_u(((g_543[1] = 0xE08EL) > (safe_sub_func_uint8_t_u_u(((l_609 | ((-1L) >= (((g_3957 != l_743[1][3]) != p_43) || l_678))) && l_676[0][3]), l_609))), l_850))))) || g_359[9][0])));
                        g_866[4][0] = ((safe_lshift_func_int16_t_s_u((safe_unary_minus_func_uint32_t_u((((safe_sub_func_int16_t_s_s((((l_842 && (l_842 >= (-1L))) < (0UL ^ (l_692[0] = ((safe_rshift_func_int16_t_s_s((((!(safe_unary_minus_func_uint16_t_u((l_719 = l_814)))) & ((safe_mod_func_uint8_t_u_u((l_850 == g_115), (p_43 & ((safe_lshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(l_814, 5)), 4)) || l_842)))) || l_609)) && l_678), l_692[5])) || l_796)))) ^ p_43), l_466)) | l_831[8]) || g_813[1][0]))), l_814)) && 0xD5C0L);
                    }
                    if (g_3152)
                        continue;
                }
            }
        }
        else
        {
            uint16_t l_869 = 0x0CBAL;
            int32_t l_893 = 0x3423351EL;
            g_115 = (safe_lshift_func_uint16_t_u_s((0x39L & ((l_869 & ((((((0xB4L < (safe_sub_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s((2L >= (safe_lshift_func_uint16_t_u_u(((safe_mod_func_uint16_t_u_u((((safe_rshift_func_int16_t_s_u(p_43, 5)) | (safe_rshift_func_int16_t_s_u((safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_lshift_func_int8_t_s_s((((~g_974) < (g_115 <= g_866[6][9])) < (l_814 && l_869)), l_869)), 9)), (-1L))), l_814))) ^ 0x226FL), g_63)) & g_543[1]), 4))), 0)), l_609))) | 0x38EB57AFL) || g_3152) != 0UL) >= 0x7089L) <= l_814)) >= l_869)), l_375));
            if (l_892[1])
                continue;
            l_893 = (-1L);
        };


                    l_447 = (~(((((+(((safe_add_func_int8_t_s_s((-10L), l_456[2][5][2])) < 0xED819CAFL) <= (safe_mod_func_int8_t_s_s(g_3409, (((((g_3409 == l_335[6][1][3]) < (safe_sub_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u((safe_sub_func_uint8_t_u_u((g_172[0] | g_3409), (((l_465[6][3] || l_309) || l_797) != l_609))), 4294967294UL)) <= g_3409), l_456[1][4][1]))) < 1L) || p_43) || g_2420))))) == 0x13L) & g_540) == g_3261) ^ 0x86A1AECCL));
                }
                l_446[3][0][0] = l_466;
            }
            l_447 = (g_1460 | l_375);
            l_349[1] = (((safe_sub_func_int32_t_s_s(g_359[6][4], (safe_unary_minus_func_int32_t_s(((0xEFE6L != ((safe_mod_func_uint8_t_u_u((safe_mod_func_int32_t_s_s(((1UL == (safe_lshift_func_int16_t_s_s((l_309 = (l_465[6][3] & (~(((safe_add_func_int32_t_s_s(g_359[9][0], g_3261)) && (g_3409 != g_3409)) | g_3409)))), l_379))) || 0x87FBL), 0xCCF5684AL)), 0x9BL)) >= 0x47C0L)) >= g_3409))))) || g_3409) | (-1L));
            l_492 = ((safe_sub_func_int32_t_s_s(g_359[9][0], (((safe_lshift_func_int8_t_s_u(((((l_465[2][3] & g_3409) < (g_3409 | ((0UL && l_379) == ((((0xF23DB827L == ((((safe_rshift_func_uint16_t_u_u((l_309 = ((safe_lshift_func_int8_t_s_s((safe_mod_func_int16_t_s_s((((l_491 = 0x894CL) && (-7L)) && 0xA782L), l_375)), 0)) != 0xC734L)), 12)) | g_3409) && l_447) < 0x90L)) & (-9L)) > l_348) <= g_359[9][0])))) != 0L) > l_797), 6)) ^ l_62) != 0UL))) < 0x2D04L);
        }
    }
    else
    {
        int32_t l_519 = (-2L);
        for (g_540 = (-10); (g_540 <= 14); g_540 = safe_add_func_uint8_t_u_u(g_540, 5))
        {
            int16_t l_501 = 9L;
            int32_t l_508[9][8][3] = {{{1L,0x08A14A3AL,0L},{0xC26916B3L,0x08A14A3AL,3L},{0x08A14A3AL,(-8L),1L},{0x1E9F24E1L,0xC26916B3L,3L},{(-1L),(-7L),0L},{(-1L),0x001EC93AL,3L},{0x1E9F24E1L,7L,9L},{0x08A14A3AL,0x001EC93AL,(-2L)}},{{0xC26916B3L,(-7L),(-2L)},{1L,0xC26916B3L,9L},{(-8L),(-8L),3L},{1L,0x08A14A3AL,0L},{0xC26916B3L,0x08A14A3AL,3L},{0x08A14A3AL,(-8L),1L},{0x1E9F24E1L,0xC26916B3L,3L},{(-1L),(-7L),0L}},{{(-1L),0x001EC93AL,3L},{0x1E9F24E1L,7L,9L},{0x08A14A3AL,0x001EC93AL,(-2L)},{0xC26916B3L,(-7L),(-2L)},{1L,0xC26916B3L,9L},{(-8L),(-8L),3L},{1L,0x08A14A3AL,7L},{0L,1L,(-1L)}},{{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)},{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)},{0xCFF90880L,0x3E711866L,0x001EC93AL},{1L,(-1L),0x1E9F24E1L},{0L,0x1C26E085L,0x1E9F24E1L},{(-6L),0L,0x001EC93AL}},{{0x095E5563L,0x095E5563L,(-8L)},{(-6L),1L,7L},{0L,1L,(-1L)},{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)},{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)},{0xCFF90880L,0x3E711866L,0x001EC93AL}},{{1L,(-1L),0x1E9F24E1L},{0L,0x1C26E085L,0x1E9F24E1L},{(-6L),0L,0x001EC93AL},{0x095E5563L,0x095E5563L,(-8L)},{(-6L),1L,7L},{0L,1L,(-1L)},{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)}},{{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)},{0xCFF90880L,0x3E711866L,0x001EC93AL},{1L,(-1L),0x1E9F24E1L},{0L,0x1C26E085L,0x1E9F24E1L},{(-6L),0L,0x001EC93AL},{0x095E5563L,0x095E5563L,(-8L)},{(-6L),1L,7L}},{{0L,1L,(-1L)},{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)},{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)},{0xCFF90880L,0x3E711866L,0x001EC93AL},{1L,(-1L),0x1E9F24E1L},{0L,0x1C26E085L,0x1E9F24E1L}},{{(-6L),0L,0x001EC93AL},{0x095E5563L,0x095E5563L,(-8L)},{(-6L),1L,7L},{0L,1L,(-1L)},{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)},{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)}}};
            int32_t l_517 = 0xA0C82EBCL;
            int32_t l_518 = 0x8F0CB5B0L;
            int32_t l_520 = 1L;
            int i, j, k;
            l_520 = ((g_3409 = 1L) <= (((~(((safe_add_func_uint16_t_u_u((l_660 < (((((safe_sub_func_uint8_t_u_u((l_518 = ((((!(l_501 < (safe_lshift_func_uint16_t_u_s((l_517 = ((safe_rshift_func_int8_t_s_s((l_508[8][4][1] = (g_3409 = l_62)), (g_3409 <= (l_660 && l_660)))) >= (((-7L) ^ (safe_sub_func_int16_t_s_s(((safe_add_func_int16_t_s_s((l_492 = ((l_309 = (safe_sub_func_uint32_t_u_u(((safe_mod_func_int32_t_s_s((-10L), (-1L))) && 0x80L), g_540))) & l_501)), (-1L))) || 65531UL), 6UL))) == 1UL))), l_501)))) && l_309) < p_43) > g_3409)), g_540)) | l_519) <= g_3261) ^ l_797) < 0x72DFB7FAL)), 0x2D47L)) >= 1L) <= 1UL)) > g_3421) < l_797));
        }
    }
    return p_43;
}

                    for (l_609 = 2; (l_609 >= 0); l_609 -= 1)
                {
                    uint16_t l_669 = 0x0983L;
                    int32_t l_677 = 0L;
                    int i;
                    p_44 = ((l_545[l_609] > (safe_add_func_int32_t_s_s(((l_608 = (~g_543[1])) == l_660), (p_43 & (safe_sub_func_int16_t_s_s(((((l_545[2] >= (l_577 = (((((+l_669) < ((((((safe_mod_func_uint32_t_u_u((((((safe_rshift_func_uint8_t_u_s(p_45, 6)) > ((0UL | (safe_mod_func_uint32_t_u_u((6L && 1L), l_676[0][3]))) || p_43)) >= 8UL) != g_359[3][2]) < p_45), g_359[6][1])) && l_676[0][8]) ^ l_609) < g_161) != l_576) || 0xAB7CL)) ^ g_541) || l_545[1]) || 0x409AL))) == g_83) ^ g_359[1][4]) && 0x8AE5680CL), p_43)))))) <= l_545[1]);

{
                        return g_1215[3];
                    }

                    l_677 = (g_22 = g_161);

g_361 += 1;


                    if ((p_43 != (p_44 >= ((0x0DL || (4UL ^ l_678)) <= (safe_mod_func_uint32_t_u_u(((safe_add_func_int32_t_s_s((safe_mod_func_uint32_t_u_u((((safe_mod_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u((l_677 = (safe_unary_minus_func_uint32_t_u((safe_add_func_int32_t_s_s((((p_43 || (l_692[0] = (g_538 = 0x5548L))) == (safe_sub_func_int8_t_s_s((l_624 = p_43), (safe_mod_func_int8_t_s_s(p_45, p_43))))) && l_545[2]), g_540))))), 6)) ^ 0x54L), l_609)) == 0L) != 0xEBCD03DFL), 5UL)), 6L)) <= p_45), 4294967290UL))))))
                    {
                        uint32_t l_720 = 0UL;
                        int32_t l_721 = 7L;
                        l_692[0] = (safe_sub_func_int16_t_s_s(((p_45 = (safe_add_func_uint8_t_u_u(0x83L, (((safe_add_func_int8_t_s_s(g_172[4], (l_703 = p_43))) ^ (~(l_677 = (safe_rshift_func_int16_t_s_u((((safe_rshift_func_int8_t_s_s((l_721 = (4UL || ((-1L) == (((safe_lshift_func_uint8_t_u_s((safe_sub_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u(65535UL, 2)), (safe_rshift_func_int16_t_s_s((p_44 && ((l_719 = ((safe_mod_func_uint8_t_u_u(((g_540 < l_660) && g_172[4]), 0x9AL)) <= p_45)) != l_660)), l_720)))), g_161)) && 0x78L) ^ g_161)))), 6)) || p_43) ^ 0xF1F3L), 3))))) || 6UL)))) & 0UL), 5UL));
                    }
                    else
                    {
                        int16_t l_744 = 0x456EL;
                        l_719 = (safe_sub_func_int8_t_s_s((1L ^ p_44), ((l_576 && (safe_lshift_func_int8_t_s_u(((safe_lshift_func_uint8_t_u_s((safe_unary_minus_func_uint32_t_u((g_359[1][5] = ((safe_add_func_uint8_t_u_u((((safe_rshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s((((((safe_lshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s((7L > (safe_lshift_func_uint8_t_u_u(g_115, 7))), (g_217 && (((l_677 = ((4294967295UL >= (safe_lshift_func_int16_t_s_s((l_576 | g_315), g_115))) || g_4)) <= g_217) | 0x11L)))), 0)) < l_743[1][3]) || g_161) == 0x50L) ^ l_744), g_361)), 2)) < l_624) >= g_543[1]), l_577)) && g_361)))), 7)) & l_743[1][3]), l_608))) == 1L)));
                        g_247 = (safe_add_func_uint32_t_u_u(g_103, (((safe_mod_func_uint8_t_u_u(((safe_mod_func_uint8_t_u_u((((l_719 = (((p_43 <= ((g_247 == (l_703 = 65531UL)) != ((6L <= ((safe_sub_func_int32_t_s_s(((l_692[4] = (safe_add_func_int32_t_s_s((g_188 && ((l_677 = (safe_unary_minus_func_int32_t_s(((p_45 >= 0xED81L) & (safe_add_func_uint16_t_u_u((0xADA9L != p_43), g_538)))))) > 1L)), g_63))) == 0x15L), p_43)) ^ p_44)) & g_538))) ^ 0x4F420878L) == (-2L))) < 1UL) | (-1L)), g_173)) | g_63), p_44)) && g_161) > l_744)));
                        if (g_115)
                            break;
                        g_22 = ((safe_mod_func_int16_t_s_s(((g_359[9][0] == ((safe_add_func_uint16_t_u_u(((g_540 = (l_677 = p_45)) >= (0x1BL ^ (safe_add_func_int32_t_s_s((+(0x5B46L >= g_22)), l_669)))), (1L <= ((((((safe_mod_func_int16_t_s_s((safe_add_func_int16_t_s_s((l_577 <= ((((safe_rshift_func_int16_t_s_s(g_315, g_172[7])) & 6L) < g_543[1]) & g_361)), g_173)), g_4)) || p_44) || p_43) & p_44) || p_43) || p_43)))) == p_45)) != p_45), l_744)) >= 65530UL);
                    }
                    for (l_678 = 1; (l_678 <= 6); l_678 += 1)
                    {
                        int i, j;
                        l_692[(l_609 + 1)] = (g_22 = ((l_577 = ((((p_43 = ((l_608 = l_545[l_609]) == (l_692[(l_609 + 1)] | (safe_lshift_func_uint16_t_u_s((l_692[l_609] & (((((g_359[(l_678 + 2)][(l_609 + 3)] & (safe_sub_func_int16_t_s_s((l_623 > ((l_797 = ((!(safe_sub_func_int8_t_s_s((safe_add_func_uint16_t_u_u((+((safe_lshift_func_uint16_t_u_s((safe_sub_func_int8_t_s_s((safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u((((0x48A4D6C4L ^ (p_44 = ((0xF3L && (g_361 < ((safe_mod_func_uint8_t_u_u(((+(g_161 = p_43)) == g_541), g_315)) && 0x3B13BD3CL))) >= l_743[0][3]))) >= l_648[7]) & l_703), l_669)) == l_796), 4)) >= p_45), 3L)), (-3L))), 12)) < g_359[(l_678 + 3)][(l_609 + 1)])), 0L)), p_43))) <= g_173)) >= p_45)), 2L))) == 1UL) <= 0x73L) > g_543[0]) <= p_43)), 5))))) >= 5L) & g_188) || g_541)) < p_45));
                        g_22 = (l_545[l_609] >= (p_45 | g_543[1]));
                    }
                }
                g_22 = (((((safe_mod_func_uint8_t_u_u(g_359[1][0], (safe_rshift_func_uint8_t_u_u((safe_add_func_int32_t_s_s((((((l_648[4] = g_540) < ((0xBAAB71EFL < ((~l_608) <= (l_815[0] = (safe_add_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_u(((safe_add_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u(((g_813[1][0] > (l_814 || (g_83 = g_172[4]))) != (g_188 && (p_45 & p_45))), l_743[1][3])) <= p_44), g_172[4])) >= p_43), l_545[0])) > 1L) || g_813[1][0]), p_43))))) ^ l_797)) == 1L) | p_43) != g_359[9][0]), (-6L))), 6)))) > 0x22L) > l_743[1][3]) && l_676[0][3]) >= l_660);
                for (g_540 = 0; (g_540 >= 32); ++g_540)
                {
                    uint16_t l_830 = 0x915EL;
                    int32_t l_841 = 0x410F57C2L;
                    p_44 = (safe_unary_minus_func_uint8_t_u(((((l_719 = ((l_797 = (l_703 = ((safe_unary_minus_func_int16_t_s(0xA9D2L)) < ((0x78EDL != (safe_lshift_func_int8_t_s_u((g_83 = (l_608 = (g_83 && (((safe_mod_func_int16_t_s_s(0x3B07L, (safe_rshift_func_uint16_t_u_s((g_813[1][0] = (l_576 = l_703)), 7)))) && (((safe_rshift_func_uint16_t_u_s((safe_add_func_uint8_t_u_u((0xF815L && (g_541 < g_188)), 0UL)), l_609)) && g_63) == l_676[0][3])) >= g_172[4])))), 0))) && p_43)))) & p_44)) == p_45) <= l_830) <= 0x47D2L)));
                    g_247 = (g_115 || l_831[7]);

{
                    uint16_t l_2859[9][10][2] = {{{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L},{0x351AL,0x0962L},{0x63E3L,0x6C7BL}},{{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L},{0x2BD3L,0x351AL},{0x0962L,0x63E3L}},{{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L},{0x351AL,0x0962L}},{{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L},{0x2BD3L,0x351AL}},{{0x0962L,0x63E3L},{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L}},{{0x351AL,0x0962L},{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L}},{{0x2BD3L,0x351AL},{0x0962L,0x63E3L},{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL}},{{0x2BD3L,0x2BD3L},{0x351AL,0x0962L},{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L}},{{0x351AL,0x2BD3L},{0x2BD3L,0x351AL},{0x0962L,0x63E3L},{0UL,0xBB6AL},{1UL,0x1D2FL},{0xBB6AL,0x351AL},{0x1AC1L,0x351AL},{0xBB6AL,0x1D2FL},{1UL,0xBB6AL},{0UL,0xE5BAL}}};
                    int i, j, k;
                    g_247 = (((l_2859[6][7][1] = 0xADBFA8FFL) >= 0x48712C93L) <= (safe_mod_func_uint16_t_u_u(g_1129, 0xF825L)));
                }

                    for (l_637 = 2; (l_637 <= 6); l_637 += 1)
                    {
                        int i;
                        p_44 = ((l_692[l_637] < ((0xFBL < (((0x48747109L == (0x97L | l_676[0][3])) & 0x46AA7A64L) >= (safe_mod_func_uint16_t_u_u(((~((((l_719 = (((0L < (safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(((p_43 = g_22) >= (l_841 = (safe_sub_func_uint16_t_u_u(l_692[l_637], 0xC2D2L)))), l_660)), 0xEBL))) ^ p_44) <= l_796)) || 0x0BL) >= 0x51L) || l_703)) != l_842), p_45)))) != 0xC8L)) >= 0xAB494884L);
                        g_22 = (0x9FADL & (p_44 > ((g_217 = (!(((0xAE45L > g_161) >= 0L) & (safe_sub_func_uint8_t_u_u(((g_543[1] = 0xE08EL) > (safe_sub_func_uint8_t_u_u(((p_44 | ((-1L) >= (((l_814 != l_743[1][3]) != p_43) || g_161))) && l_676[0][3]), p_44))), l_850))))) || g_359[9][0])));
                        g_866[4][0] = ((safe_lshift_func_int16_t_s_u((safe_unary_minus_func_uint32_t_u((((safe_sub_func_int16_t_s_s((((l_842 && (l_842 >= (-1L))) < (0UL ^ (l_692[0] = ((safe_rshift_func_int16_t_s_s((((!(safe_unary_minus_func_uint16_t_u((l_719 = g_540)))) & ((safe_mod_func_uint8_t_u_u((l_850 == g_22), (p_43 & ((safe_lshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(p_45, 5)), 4)) || l_842)))) || p_44)) && g_161), l_692[5])) || l_637)))) ^ p_43), g_217)) | l_831[8]) || g_813[1][0]))), p_45)) && 0xD5C0L);
                    }
                    if (g_541)
                        continue;
                }
            }
        }
        else
        {
            uint16_t l_869 = 0x0CBAL;
            int32_t l_893 = 0x3423351EL;

g_1524 += 1;


                    g_22 = (safe_lshift_func_uint16_t_u_s((0x39L & ((l_869 & ((((((0xB4L < (safe_sub_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s((2L >= (safe_lshift_func_uint16_t_u_u(((safe_mod_func_uint16_t_u_u((((safe_rshift_func_int16_t_s_u(p_43, 5)) | (safe_rshift_func_int16_t_s_u((safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_lshift_func_int8_t_s_s((((~l_891) < (g_22 <= g_866[6][9])) < (p_45 && l_869)), l_869)), 9)), (-1L))), p_45))) ^ 0x226FL), l_659)) & g_543[1]), 4))), 0)), p_44))) | 0x38EB57AFL) || g_541) != 0UL) >= 0x7089L) <= p_45)) >= l_869)), l_576));
            if (l_892[1])
                continue;
            l_893 = (-1L);
        }
    }
    return p_45;
}







static int32_t func_46(int8_t p_47)
{
    uint32_t l_62 = 4294967295UL;
    int32_t l_309 = 0x5E625162L;
    int8_t l_310 = 0xDEL;
    uint16_t l_406 = 0x5A4EL;
    int32_t l_492 = 9L;
    l_309 = func_48((safe_lshift_func_int8_t_s_u((((((((p_47 | p_47) <= ((safe_lshift_func_int16_t_s_u((safe_sub_func_int8_t_s_s(0L, func_57(l_62, p_47, l_62, ((g_63 = (p_47 & g_4)) | (safe_rshift_func_uint8_t_u_s(g_4, 7)))))), 2)) >= 0x40L)) >= p_47) > (-1L)) | g_4) && l_62) <= g_4), g_4)), p_47);
    l_309 = l_310;
    if ((safe_rshift_func_uint8_t_u_u(((g_315 = (safe_add_func_uint8_t_u_u(p_47, g_83))) >= (safe_add_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s(l_309, (safe_mod_func_uint16_t_u_u((l_309 <= 0xE3L), l_309)))), (safe_add_func_uint8_t_u_u((safe_mod_func_int32_t_s_s((-1L), (safe_add_func_uint8_t_u_u((0xD127F73BL > (l_310 <= 5UL)), g_22)))), p_47))))), l_309)))
    {
        uint16_t l_333 = 2UL;
        int32_t l_335[8][3][4] = {{{0xDD39B848L,0L,0x5E468437L,3L},{3L,(-1L),0x641FE7F3L,0L},{0x7D02BC70L,0x641FE7F3L,0x641FE7F3L,0x7D02BC70L}},{{3L,(-1L),0x5E468437L,(-1L)},{0xDD39B848L,0L,(-1L),0x0799FA52L},{(-1L),0x0799FA52L,0L,0x0799FA52L}},{{0x641FE7F3L,0L,(-1L),(-1L)},{0x22CC248DL,(-1L),0x0799FA52L,0x7D02BC70L},{(-1L),0x641FE7F3L,0L,0L}},{{(-1L),(-1L),0x0799FA52L,3L},{0x22CC248DL,0L,(-1L),(-1L)},{0x641FE7F3L,0xDD39B848L,0L,(-1L)}},{{(-1L),0xDD39B848L,(-1L),(-1L)},{0xDD39B848L,0L,0x5E468437L,3L},{3L,(-1L),0x641FE7F3L,0L}},{{0x7D02BC70L,0x641FE7F3L,0x641FE7F3L,0x7D02BC70L},{3L,(-1L),0x5E468437L,(-1L)},{0xDD39B848L,0L,(-1L),0x0799FA52L}},{{(-1L),0x0799FA52L,0L,0x0799FA52L},{0x641FE7F3L,0L,(-1L),(-1L)},{0x22CC248DL,(-1L),0x0799FA52L,0x7D02BC70L}},{{(-1L),0x641FE7F3L,0L,0L},{(-1L),(-1L),0x0799FA52L,3L},{0x22CC248DL,0L,(-1L),(-1L)}}};
        int8_t l_348 = 1L;
        int32_t l_349[2];
        int32_t l_375 = 0xA66D8ECDL;
        int32_t l_376 = 0x60344EB4L;
        uint16_t l_389 = 0x6F8FL;
        uint32_t l_465[9][6] = {{4294967295UL,4294967295UL,0x6C58D8B7L,4294967295UL,4294967295UL,0x6C58D8B7L},{4294967295UL,4294967295UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL},{0UL,0UL,4294967295UL,0UL,0UL,4294967295UL}};
        int i, j, k;
        for (i = 0; i < 2; i++)
            l_349[i] = 2L;
        if ((((((safe_rshift_func_uint16_t_u_s((!(safe_add_func_uint8_t_u_u(l_309, (g_63 | ((((g_103 = (((l_333 ^ (!((p_47 & g_188) & (p_47 & 0x5C2909C2L)))) >= (((l_335[6][1][3] = g_63) == 0x9128L) && 0x20EB86FDL)) <= 0x8FL)) && l_310) == 0x845DL) <= 0xC565EBF9L))))), 9)) ^ g_22) && p_47) | l_333) <= g_83))
        {
            uint16_t l_336 = 0UL;
            int32_t l_345 = 0xF6AF8E6AL;
            l_349[1] = (l_348 = (l_336 & (safe_lshift_func_uint8_t_u_s((((safe_mod_func_uint8_t_u_u((~(+(l_335[6][1][3] = 1UL))), ((safe_mod_func_uint8_t_u_u((l_345 = 0xBDL), ((0xB66F0254L < (safe_rshift_func_int8_t_s_s((4L < p_47), (((-1L) & (l_310 < ((l_62 & p_47) != 0L))) ^ 249UL)))) & 3UL))) || p_47))) <= (-1L)) != l_310), l_333))));
            for (g_63 = 0; (g_63 >= 27); g_63++)
            {
                return l_345;
            }
        }
        else
        {
            uint8_t l_360 = 0x60L;
            g_22 = ((((p_47 >= (4294967290UL >= g_161)) <= (g_247 = (p_47 && (((safe_sub_func_int8_t_s_s((((!(g_83 || (l_309 = (safe_rshift_func_uint16_t_u_s(g_359[9][0], (((g_4 < 65535UL) > g_172[1]) ^ 0x17L)))))) == l_360) <= g_361), p_47)) != g_172[8]) | p_47)))) != g_63) | g_217);
            l_309 = ((safe_lshift_func_uint8_t_u_u((l_376 = (safe_lshift_func_int8_t_s_u(p_47, ((l_310 || (l_349[1] = p_47)) & ((safe_lshift_func_int16_t_s_s(((safe_lshift_func_uint16_t_u_u((safe_rshift_func_int16_t_s_s((((l_335[6][1][3] = (l_62 <= (g_172[8] != 0xE7FBL))) && (safe_unary_minus_func_uint32_t_u((g_315 <= 0x63L)))) | (((((((safe_add_func_int32_t_s_s(((l_375 = (p_47 ^ g_315)) & (-1L)), g_361)) ^ g_83) | 0x727FL) || 0xC8A15306L) != 5L) && g_172[4]) <= 247UL)), 6)), 15)) ^ (-1L)), 15)) & p_47))))), 2)) == g_63);
            return g_83;
        }
        l_309 = g_359[9][0];
        for (p_47 = (-4); (p_47 > 11); p_47 = safe_add_func_int8_t_s_s(p_47, 4))
        {
            int32_t l_379 = (-9L);
            int32_t l_447 = 0L;
            uint32_t l_491 = 0UL;
            for (l_375 = 2; (l_375 >= 0); l_375 -= 1)
            {
                uint8_t l_421[8];
                uint32_t l_426 = 1UL;
                int32_t l_427 = 0L;
                int32_t l_446[4][2][2] = {{{5L,5L},{0x7B32B138L,5L}},{{5L,0x7B32B138L},{5L,5L}},{{0x7B32B138L,5L},{5L,0x7B32B138L}},{{5L,5L},{0x7B32B138L,5L}}};
                uint8_t l_466 = 1UL;
                int i, j, k;
                for (i = 0; i < 8; i++)
                    {
if (g_2710)
                break;

                    l_421[i] = 0x31L;}
                for (g_315 = 0; (g_315 <= 2); g_315 += 1)
                {
                    int16_t l_380[5][5] = {{(-1L),0L,0x3ED2L,(-1L),0x3ED2L},{(-1L),(-1L),7L,0x22E4L,0x4688L},{0xF476L,0x4688L,0x3ED2L,0x3ED2L,0x4688L},{0x4688L,0L,0xF476L,0x4688L,0x3ED2L},{0x22E4L,0x4688L,7L,0x4688L,0x22E4L}};
                    int32_t l_390[10] = {0xBF810539L,0x88F1ED79L,0xBF810539L,0xBF810539L,0x88F1ED79L,0xBF810539L,0xBF810539L,0x88F1ED79L,0xBF810539L,0xBF810539L};
                    int i, j;
                    for (g_188 = 0; (g_188 <= 2); g_188 += 1)
                    {
                        int i, j, k;

{
            int16_t l_3131 = 0xDA0DL;

l_309 += 1;


                    i = ((-7L) | (safe_lshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((0xACL >= (!(safe_mod_func_uint16_t_u_u(l_3131, k)))), 5)), 10)));

l_333 += 1;


                    for (g_188 = 17; (g_188 <= (-24)); g_188 = safe_sub_func_uint32_t_u_u(g_188, 6))
            {
                if (g_813[1][0])
                    break;
                return l_3131;
            }
            return g_161;
        }

                    l_380[1][4] = (l_335[(l_375 + 5)][g_188][g_188] = (0xB5F2L > (l_379 = 0x9A89L)));
                    }
                    if (p_47)
                        {
for (l_406 = 0; (l_406 <= 4); l_406 += 1)
                    {
                        int i;

if (g_540)
                        break;

                    g_541 = (safe_add_func_uint8_t_u_u(g_3956[l_406], (safe_lshift_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((8L == (k = ((g_3956[l_406] && g_172[4]) < g_2177[5][2][8]))), (l_406 = (l_389 = (g_2598 || 0x4FL))))), 4))));
                        if (l_62)
                            break;
                    };


                    break;}
                    g_22 = (safe_sub_func_int8_t_s_s(((safe_mod_func_int32_t_s_s(((l_390[7] = (l_62 != (safe_sub_func_uint32_t_u_u((g_359[9][0] = (0xB2L >= (6L > ((((((((safe_add_func_uint8_t_u_u(((((l_379 != l_389) && (p_47 ^ (g_83 & (g_172[(l_375 + 2)] = ((p_47 != 0x7FL) != 0L))))) >= g_359[9][0]) & p_47), p_47)) & 1UL) && 0xDAB7L) | l_349[1]) < g_217) >= g_83) >= g_63) ^ (-1L))))), (-5L))))) != g_217), g_361)) != p_47), p_47));
                }
                if ((l_310 != (safe_mod_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((((safe_lshift_func_int8_t_s_u((safe_add_func_uint16_t_u_u(((g_188 = (l_376 = ((safe_sub_func_uint16_t_u_u(((((safe_sub_func_uint8_t_u_u(((g_161 = ((((safe_unary_minus_func_uint8_t_u((l_349[1] = (l_406 = g_361)))) || ((safe_rshift_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_u((((safe_add_func_int32_t_s_s((-3L), (safe_add_func_uint16_t_u_u(((g_63 = (l_335[6][1][3] = (safe_rshift_func_uint8_t_u_s((((l_426 = ((safe_sub_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u(l_421[6], 1UL)), ((g_361 = (-1L)) > ((safe_add_func_uint8_t_u_u((g_172[6] > (g_359[9][0] = l_421[2])), (((g_83 = (safe_rshift_func_uint16_t_u_s(g_315, 8))) >= 249UL) || 0x8A7F073DL))) & 0x32L)))) != 0xCA9CL)) != l_406) == 0x14L), 1)))) >= g_247), l_349[1])))) & (-1L)) || l_379), l_349[1])) < p_47), 2)) ^ g_217)) != g_4) == 2L)) != g_172[5]), l_421[6])) < p_47) >= g_247) & 0x1F63E348L), 7L)) ^ 0x40L))) != l_427), g_315)), 7)) <= l_421[6]) >= p_47), g_172[4])), g_103)), 0x41L))))
                {
                    int8_t l_445 = 0x02L;
                    l_309 = ((safe_sub_func_int32_t_s_s(1L, (g_247 = (0xCFL > (g_22 == (((((safe_rshift_func_uint8_t_u_s((((g_63 = l_406) <= g_217) || ((safe_mod_func_int8_t_s_s(((g_361 = 0L) < (safe_mod_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_u((~(safe_unary_minus_func_uint8_t_u(p_47))), (~(l_376 = (safe_mod_func_int8_t_s_s(g_22, (safe_lshift_func_uint16_t_u_s(((0x0C28L & l_445) || 1UL), l_348)))))))) ^ 0UL), 0x7BD5L))), 0xDEL)) & p_47)), p_47)) < 0xD2L) || 4294967295UL) <= 0L) || l_446[3][0][0])))))) && p_47);
                    l_447 = p_47;
                }
                else
                {
                    uint32_t l_456[9][6][4] = {{{0x5997C0ABL,0x5CE5605DL,0x493FBAA3L,0x31A615D8L},{0x5CE5605DL,5UL,5UL,0x5CE5605DL},{1UL,0x31A615D8L,5UL,0x26A8E26AL},{0x5CE5605DL,0x5997C0ABL,0x493FBAA3L,0x5997C0ABL},{0x5997C0ABL,5UL,1UL,0x5997C0ABL},{1UL,0x5997C0ABL,0x26A8E26AL,0x26A8E26AL}},{{0x31A615D8L,0x31A615D8L,0x493FBAA3L,0x5CE5605DL},{0x31A615D8L,5UL,0x26A8E26AL,0x31A615D8L},{1UL,0x5CE5605DL,1UL,0x26A8E26AL},{0x5997C0ABL,0x5CE5605DL,0x493FBAA3L,0x31A615D8L},{0x5CE5605DL,5UL,5UL,0x5CE5605DL},{1UL,0x31A615D8L,5UL,0x26A8E26AL}},{{0x5CE5605DL,0x5997C0ABL,0x493FBAA3L,0x5997C0ABL},{0x5997C0ABL,5UL,1UL,0x5997C0ABL},{1UL,0x5997C0ABL,0x26A8E26AL,0x26A8E26AL},{0x31A615D8L,0x31A615D8L,0x493FBAA3L,0x5CE5605DL},{0x31A615D8L,5UL,0x26A8E26AL,0x31A615D8L},{1UL,0x5CE5605DL,1UL,0x26A8E26AL}},{{0x5997C0ABL,0x5CE5605DL,0x493FBAA3L,0x31A615D8L},{0x5CE5605DL,5UL,5UL,0x5CE5605DL},{1UL,0x31A615D8L,5UL,0x26A8E26AL},{0x5CE5605DL,0x5997C0ABL,0x493FBAA3L,0x5997C0ABL},{0x5997C0ABL,5UL,1UL,0x5997C0ABL},{1UL,0x26A8E26AL,1UL,1UL}},{{1UL,1UL,0x31A615D8L,5UL},{1UL,0x493FBAA3L,1UL,1UL},{0xCEFF6648L,5UL,0xCEFF6648L,1UL},{0x26A8E26AL,5UL,0x31A615D8L,1UL},{5UL,0x493FBAA3L,0x493FBAA3L,5UL},{0xCEFF6648L,1UL,0x493FBAA3L,1UL}},{{5UL,0x26A8E26AL,0x31A615D8L,0x26A8E26AL},{0x26A8E26AL,0x493FBAA3L,0xCEFF6648L,0x26A8E26AL},{0xCEFF6648L,0x26A8E26AL,1UL,1UL},{1UL,1UL,0x31A615D8L,5UL},{1UL,0x493FBAA3L,1UL,1UL},{0xCEFF6648L,5UL,0xCEFF6648L,1UL}},{{0x26A8E26AL,5UL,0x31A615D8L,1UL},{5UL,0x493FBAA3L,0x493FBAA3L,5UL},{0xCEFF6648L,1UL,0x493FBAA3L,1UL},{5UL,0x26A8E26AL,0x31A615D8L,0x26A8E26AL},{0x26A8E26AL,0x493FBAA3L,0xCEFF6648L,0x26A8E26AL},{0xCEFF6648L,0x26A8E26AL,1UL,1UL}},{{1UL,1UL,0x31A615D8L,5UL},{1UL,0x493FBAA3L,1UL,1UL},{0xCEFF6648L,5UL,0xCEFF6648L,1UL},{0x26A8E26AL,5UL,0x31A615D8L,1UL},{5UL,0x493FBAA3L,0x493FBAA3L,5UL},{0xCEFF6648L,1UL,0x493FBAA3L,1UL}},{{5UL,0x26A8E26AL,0x31A615D8L,0x26A8E26AL},{0x26A8E26AL,0x493FBAA3L,0xCEFF6648L,0x26A8E26AL},{0xCEFF6648L,0x26A8E26AL,1UL,1UL},{1UL,1UL,0x31A615D8L,5UL},{1UL,0x493FBAA3L,1UL,1UL},{0xCEFF6648L,5UL,0xCEFF6648L,1UL}}};
                    int i, j, k;
                    for (l_426 = 0; (l_426 <= 1); l_426 += 1)
                    {
                        int i;

k += 1;


                    l_349[l_426] = (safe_rshift_func_int16_t_s_s((safe_sub_func_int16_t_s_s(0x6C4BL, (-8L))), l_349[l_426]));
                    }
                    l_447 = (~(((((+(((safe_add_func_int8_t_s_s((-10L), l_456[2][5][2])) < 0xED819CAFL) <= (safe_mod_func_int8_t_s_s(p_47, (((((p_47 == l_335[6][1][3]) < (safe_sub_func_int16_t_s_s(((safe_mod_func_uint32_t_u_u((safe_sub_func_uint8_t_u_u((g_172[0] | p_47), (((l_465[6][3] || l_309) || g_247) != g_115))), 4294967294UL)) <= p_47), l_456[1][4][1]))) < 1L) || g_188) || g_4))))) == 0x13L) & g_161) == g_63) ^ 0x86A1AECCL));
                }
                l_446[3][0][0] = l_466;
            }
            l_447 = (g_173 | l_375);
            l_349[1] = (((safe_sub_func_int32_t_s_s(g_359[6][4], (safe_unary_minus_func_int32_t_s(((0xEFE6L != ((safe_mod_func_uint8_t_u_u((safe_mod_func_int32_t_s_s(((1UL == (safe_lshift_func_int16_t_s_s((l_309 = (l_465[6][3] & (~(((safe_add_func_int32_t_s_s(g_359[9][0], g_63)) && (p_47 != p_47)) | p_47)))), l_379))) || 0x87FBL), 0xCCF5684AL)), 0x9BL)) >= 0x47C0L)) >= p_47))))) || p_47) | (-1L));
            l_492 = ((safe_sub_func_int32_t_s_s(g_359[9][0], (((safe_lshift_func_int8_t_s_u(((((l_465[2][3] & p_47) < (p_47 | ((0UL && l_379) == ((((0xF23DB827L == ((((safe_rshift_func_uint16_t_u_u((l_309 = ((safe_lshift_func_int8_t_s_s((safe_mod_func_int16_t_s_s((((l_491 = 0x894CL) && (-7L)) && 0xA782L), l_375)), 0)) != 0xC734L)), 12)) | g_361) && l_447) < 0x90L)) & (-9L)) > l_348) <= g_359[9][0])))) != 0L) > g_247), 6)) ^ l_62) != 0UL))) < 0x2D04L);
        }
    }
    else
    {
        int32_t l_519 = (-2L);
        for (g_161 = (-10); (g_161 <= 14); g_161 = safe_add_func_uint8_t_u_u(g_161, 5))
        {
            int16_t l_501 = 9L;
            int32_t l_508[9][8][3] = {{{1L,0x08A14A3AL,0L},{0xC26916B3L,0x08A14A3AL,3L},{0x08A14A3AL,(-8L),1L},{0x1E9F24E1L,0xC26916B3L,3L},{(-1L),(-7L),0L},{(-1L),0x001EC93AL,3L},{0x1E9F24E1L,7L,9L},{0x08A14A3AL,0x001EC93AL,(-2L)}},{{0xC26916B3L,(-7L),(-2L)},{1L,0xC26916B3L,9L},{(-8L),(-8L),3L},{1L,0x08A14A3AL,0L},{0xC26916B3L,0x08A14A3AL,3L},{0x08A14A3AL,(-8L),1L},{0x1E9F24E1L,0xC26916B3L,3L},{(-1L),(-7L),0L}},{{(-1L),0x001EC93AL,3L},{0x1E9F24E1L,7L,9L},{0x08A14A3AL,0x001EC93AL,(-2L)},{0xC26916B3L,(-7L),(-2L)},{1L,0xC26916B3L,9L},{(-8L),(-8L),3L},{1L,0x08A14A3AL,7L},{0L,1L,(-1L)}},{{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)},{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)},{0xCFF90880L,0x3E711866L,0x001EC93AL},{1L,(-1L),0x1E9F24E1L},{0L,0x1C26E085L,0x1E9F24E1L},{(-6L),0L,0x001EC93AL}},{{0x095E5563L,0x095E5563L,(-8L)},{(-6L),1L,7L},{0L,1L,(-1L)},{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)},{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)},{0xCFF90880L,0x3E711866L,0x001EC93AL}},{{1L,(-1L),0x1E9F24E1L},{0L,0x1C26E085L,0x1E9F24E1L},{(-6L),0L,0x001EC93AL},{0x095E5563L,0x095E5563L,(-8L)},{(-6L),1L,7L},{0L,1L,(-1L)},{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)}},{{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)},{0xCFF90880L,0x3E711866L,0x001EC93AL},{1L,(-1L),0x1E9F24E1L},{0L,0x1C26E085L,0x1E9F24E1L},{(-6L),0L,0x001EC93AL},{0x095E5563L,0x095E5563L,(-8L)},{(-6L),1L,7L}},{{0L,1L,(-1L)},{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)},{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)},{0xCFF90880L,0x3E711866L,0x001EC93AL},{1L,(-1L),0x1E9F24E1L},{0L,0x1C26E085L,0x1E9F24E1L}},{{(-6L),0L,0x001EC93AL},{0x095E5563L,0x095E5563L,(-8L)},{(-6L),1L,7L},{0L,1L,(-1L)},{1L,0x095E5563L,6L},{0xCFF90880L,0L,(-1L)},{(-1L),0x1C26E085L,7L},{(-1L),(-1L),(-8L)}}};
            int32_t l_517 = 0xA0C82EBCL;
            int32_t l_518 = 0x8F0CB5B0L;
            int32_t l_520 = 1L;
            int i, j, k;
            l_520 = ((g_83 = 1L) <= (((~(((safe_add_func_uint16_t_u_u((g_103 < (((((safe_sub_func_uint8_t_u_u((l_518 = ((((!(l_501 < (safe_lshift_func_uint16_t_u_s((l_517 = ((safe_rshift_func_int8_t_s_s((l_508[8][4][1] = (g_361 = l_62)), (p_47 <= (g_103 && g_103)))) >= (((-7L) ^ (safe_sub_func_int16_t_s_s(((safe_add_func_int16_t_s_s((l_492 = ((l_309 = (safe_sub_func_uint32_t_u_u(((safe_mod_func_int32_t_s_s((-10L), (-1L))) && 0x80L), g_161))) & l_501)), (-1L))) || 65531UL), 6UL))) == 1UL))), l_501)))) && l_309) < g_188) > p_47)), g_161)) | l_519) <= g_63) ^ g_247) < 0x72DFB7FAL)), 0x2D47L)) >= 1L) <= 1UL)) > g_217) < g_247));
        }
    }
    return g_188;
}







static int32_t func_48(uint32_t p_49, int16_t p_50)
{
    uint8_t l_79[5][2][1] = {{{0xCDL},{0x09L}},{{0xCDL},{0x09L}},{{0xCDL},{0x09L}},{{0xCDL},{0x09L}},{{0xCDL},{0x09L}}};
    int32_t l_80 = 0x7FAA682DL;
    int32_t l_88 = 0x3CEB4B62L;
    int32_t l_117 = 0x9AA43C15L;
    int16_t l_201 = 9L;
    int32_t l_259 = (-1L);
    int32_t l_268 = (-9L);
    int i, j, k;
    for (g_63 = 0; (g_63 <= 0); g_63 += 1)
    {
        uint8_t l_87 = 1UL;
        int32_t l_104[6][9] = {{0xAA260870L,(-1L),(-1L),0xAA260870L,(-1L),(-1L),0xAA260870L,0x21B11E67L,0x21B11E67L},{0xB10BEF9BL,0L,0x691EA77CL,0xB10BEF9BL,0x691EA77CL,0L,0xB10BEF9BL,0L,0L},{0xAA260870L,(-1L),(-1L),0xAA260870L,(-1L),(-1L),0xAA260870L,0x21B11E67L,0x21B11E67L},{0xB10BEF9BL,0L,0x691EA77CL,0xB10BEF9BL,0x691EA77CL,(-6L),0L,(-9L),(-9L)},{0x21B11E67L,0x1F4E5A65L,8L,0x21B11E67L,8L,0x1F4E5A65L,0x21B11E67L,0x37DDF4F0L,0x37DDF4F0L},{0L,(-6L),(-1L),0L,(-1L),(-6L),0L,(-9L),(-9L)}};
        int32_t l_262 = 0xC8414168L;
        int32_t l_263[3][2];
        int16_t l_306 = 1L;
        int i, j;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 2; j++)
                l_263[i][j] = 0x2B217F77L;
        }
        l_80 = p_49;
        for (l_80 = 0; (l_80 >= 0); l_80 -= 1)
        {
            int32_t l_82 = 1L;
            int8_t l_118 = (-1L);
            int32_t l_136 = 0x05D4F871L;
            int32_t l_160[9][3] = {{(-6L),(-6L),(-6L)},{0xE17D4CA5L,0xE17D4CA5L,0xE17D4CA5L},{(-6L),(-6L),(-6L)},{0xE17D4CA5L,0xE17D4CA5L,0xE17D4CA5L},{(-6L),(-6L),(-6L)},{0xE17D4CA5L,0xE17D4CA5L,0xE17D4CA5L},{(-6L),(-6L),(-6L)},{0xE17D4CA5L,0xE17D4CA5L,0xE17D4CA5L},{(-6L),(-6L),(-6L)}};
            int i, j;
                                           int32_t BJgJgCg_22 = (~(((~((g_83 & ((~(g_63)) / (~(l_136)))))) ^ (~(((~((g_161 ^ (~((l_82 - l_87)))))) % (~(((~((~(l_117)))) / (~((~(((l_268 & g_173) || g_22))))))))))))));
uint32_t BJgJgDg_161 = (~(((~(((((~((l_268 - g_161))) >> (((~(l_82)) | (~(g_173))) && (g_22 || g_83))) ^ (~((~((~(g_63))))))) && (~(((~(l_87)) / (l_136 && l_117))))))) && (~((~((~((~(BJgJgCg_22)))))))))));
int32_t BJgJgEl_136 = (~(((~((~(((g_83 && g_173) >> (~((~(l_87))))))))) + (l_117 || (((l_268 - g_22) ^ (BJgJgDg_161 + (BJgJgCg_22 / g_161))) / (~((~((l_82 | (~((~((g_63 + l_136)))))))))))))));
uint8_t BJgJgFg_173 = (~(((~((g_83 / ((~(l_136)) & (~(l_87)))))) || (BJgJgEl_136 ^ (~(((l_117 + (~(((~((g_22 ^ g_173))) | (~(g_63)))))) & (~(((BJgJgDg_161 >> (~(l_268))) % ((~(BJgJgCg_22)) ^ (g_161 ^ (~(l_82))))))))))))));
int32_t BJgJgGl_117 = (~((((l_117 | (~(l_268))) + (~((~(((~(l_82)) ^ (~((~((g_63 ^ l_136))))))))))) && (~(((~((((~(BJgJgDg_161)) ^ g_22) & l_87))) >> ((((~(g_83)) ^ (BJgJgEl_136 | BJgJgFg_173)) && (~(g_161))) || (g_173 | BJgJgCg_22))))))));
int32_t BJgJgHl_268 = (~((((~((~(((l_87 ^ g_161) / (~(l_268))))))) && (~((l_82 | ((~(BJgJgFg_173)) ^ (~(((~(BJgJgGl_117)) | l_136)))))))) << ((~((g_83 && ((~(((BJgJgCg_22 ^ g_63) % BJgJgEl_136))) | (BJgJgDg_161 - (l_117 / g_173)))))) || (~(g_22))))));
if((g_22<=1)){
BJgJgCg_22 = g_22;
BJgJgDg_161 = g_161;
BJgJgEl_136 = l_136;
BJgJgFg_173 = g_173;
BJgJgGl_117 = l_117;
BJgJgHl_268 = l_268;
g_22 = (~((((~((~((BJgJgEl_136 & (~(g_173))))))) + (((g_63 / BJgJgGl_117) + g_83) ^ ((~(l_117)) & (~((~(g_22))))))) || (~((~(((~((~((BJgJgHl_268 / (l_82 || BJgJgCg_22)))))) ^ (((~((~(l_268)))) || (((l_136 | BJgJgDg_161) && (~(BJgJgFg_173))) % l_87)) / (~((~(g_161)))))))))))));
g_161 = (~(((((~((BJgJgDg_161 || l_117))) + (~((~(BJgJgFg_173))))) && (~(((~((~(BJgJgGl_117)))) % ((((~(BJgJgCg_22)) / ((g_161 & g_83) % g_22)) / ((BJgJgEl_136 - g_63) || (l_136 >> (~(BJgJgHl_268))))) - (l_82 / (~(l_87)))))))) - (~((~((~((~((l_268 && g_173))))))))))));
l_136 = (~(((((((l_82 | BJgJgHl_268) + BJgJgFg_173) + (~(g_63))) | g_22) + (((~((~((~(BJgJgEl_136)))))) && (~((~((((~(l_136)) && BJgJgCg_22) + ((g_173 ^ BJgJgDg_161) || (~((~(g_161))))))))))) & l_87)) / (~((((~(l_117)) - l_268) / (~((~((~((~((~((BJgJgGl_117 || (~(g_83)))))))))))))))))));
g_173 = (~(((~(((~(g_22)) & BJgJgGl_117))) + (((g_63 % (~(l_268))) + (((~(g_161)) - (~((BJgJgDg_161 + BJgJgCg_22)))) || (l_117 & (~((~((l_136 ^ BJgJgHl_268)))))))) | (~(((~((l_87 & (~(BJgJgFg_173))))) % (l_82 & (g_173 | (g_83 ^ BJgJgEl_136))))))))));
l_117 = (~(((~(((~(g_83)) ^ g_173))) && (~(((~((((~(g_22)) + ((BJgJgFg_173 ^ (~(l_87))) & l_136)) + l_117))) % ((((~(g_161)) ^ (((~((g_63 - BJgJgGl_117))) | l_82) && BJgJgDg_161)) || (~((~((~((BJgJgEl_136 || (~((l_268 / BJgJgCg_22))))))))))) + BJgJgHl_268)))))));
l_268 = (~(((~((((l_268 & l_87) << (g_173 || g_83)) - (l_117 && BJgJgCg_22)))) ^ ((~(((~(((~(BJgJgHl_268)) / l_136))) & (~(BJgJgGl_117))))) ^ (~(((g_63 & ((~(((~((~(g_22)))) && BJgJgFg_173))) - (~(((g_161 << l_82) << BJgJgDg_161))))) | (~((~(BJgJgEl_136)))))))))));
if(((!l_268) || (BJgJgCg_22>1))){
printf("g_22=%lld\n", (long long)g_22);
continue;
}
if((BJgJgEl_136 > g_161)){
printf("g_161=%llu\n", (unsigned long long)g_161);
goto LABEL_qgqgt;
}
if((((!BJgJgHl_268) || (BJgJgDg_161 < g_173)) || ((BJgJgHl_268<-9) || (!BJgJgEl_136)))){
printf("l_136=%lld\n", (long long)l_136);
goto LABEL_qgqgt;
}
if((l_82>1)){
printf("g_173=%llu\n", (unsigned long long)g_173);
g_173 = (~((((~((~((BJgJgFg_173 % (~((BJgJgGl_117 >> l_87)))))))) >> (l_117 - (BJgJgEl_136 - (l_82 / (~(g_161)))))) ^ (((~((~((~(l_136)))))) - g_173) << (((~((g_22 & BJgJgCg_22))) >> (~((~((g_83 - (~(BJgJgDg_161)))))))) << ((~(((~(BJgJgHl_268)) / (~(g_63))))) | l_268))))));
break;
}
if((!l_87)){
printf("l_117=%lld\n", (long long)l_117);
goto LABEL_qgqgu;
}
if((((g_173>=2) && (!g_22)) || ((g_83>-1) || (!l_87)))){
printf("l_268=%lld\n", (long long)l_268);
BJgJgEl_136 = (~((((~(g_161)) + ((~(l_87)) ^ (~(((~((BJgJgHl_268 + g_173))) % (~(BJgJgCg_22))))))) - (~(((~((BJgJgEl_136 || l_82))) | (((~(l_117)) + (~(((~(l_268)) || ((BJgJgGl_117 >> l_136) % g_22))))) + ((~(((~(g_63)) && BJgJgDg_161))) + (g_83 % BJgJgFg_173)))))))));
BJgJgHl_268 = (~((((~((g_83 << l_136))) | (((~((~(BJgJgFg_173)))) | (~((~((l_268 >> (~(l_117)))))))) | (~((~(BJgJgCg_22)))))) / (((g_161 && BJgJgGl_117) && ((((~(l_82)) / (~(l_87))) << (BJgJgEl_136 >> g_22)) - (g_63 << (BJgJgDg_161 % BJgJgHl_268)))) + g_173))));
}
}
g_22 = BJgJgCg_22;
g_161 = BJgJgDg_161;
l_136 = BJgJgEl_136;
g_173 = BJgJgFg_173;
l_117 = BJgJgGl_117;
l_268 = BJgJgHl_268;

                    g_83 = (g_22 = (!l_82));
            if (((l_88 = (g_83 != (((safe_lshift_func_uint8_t_u_u(g_4, l_79[3][1][0])) < ((((~p_49) != (l_82 = 0L)) && ((((0x7DD3L > 1UL) | l_87) != ((g_83 && p_50) == l_87)) || l_87)) <= p_50)) >= (-7L)))) && 0UL))
            {
                if (p_50)
                    break;
            }
            else
            {
                if (g_63)
                    break;
            }
                                                                                   if (((l_118>=-1) || l_136))
                    while ((g_217 < g_22) )
{

{
            uint16_t l_237 = 65526UL;
            int32_t l_260[5];
            int32_t l_261 = 4L;
            uint32_t l_274[7][10] = {{0x9183A3A1L,0xD0E7BC49L,1UL,4294967295UL,0x4EE4472DL,1UL,0xFA7611F6L,0x0EC4D18DL,0x0EC4D18DL,0xFA7611F6L},{4294967295UL,0x9183A3A1L,4294967295UL,4294967295UL,0x9183A3A1L,4294967295UL,4294967295UL,1UL,0xBC1D7A0BL,0UL},{0UL,0x0EC4D18DL,0xD0E7BC49L,1UL,1UL,0UL,4294967295UL,0UL,1UL,1UL},{0UL,0UL,0UL,4294967292UL,0xFA7611F6L,4294967295UL,1UL,0x4EE4472DL,0xD0E7BC49L,1UL},{4294967295UL,1UL,0x4EE4472DL,0xD0E7BC49L,1UL,1UL,0xD0E7BC49L,0x4EE4472DL,1UL,4294967295UL},{0x9183A3A1L,0x45722FB2L,0UL,0x0EC4D18DL,0xD0E7BC49L,1UL,1UL,0UL,4294967295UL,0UL},{0xBC1D7A0BL,0UL,0xD0E7BC49L,0x45722FB2L,0xD0E7BC49L,0UL,0xBC1D7A0BL,1UL,4294967295UL,4294967295UL}};
            int16_t l_277[9][10][2] = {{{1L,8L},{0x6338L,0L},{(-1L),7L},{0x35ABL,1L},{(-6L),0L},{0x372EL,0x97CDL},{1L,0xDD2AL},{0L,0x35ABL},{(-1L),0L},{3L,0x78A7L}},{{8L,3L},{0x38AEL,0x78A7L},{0x795CL,1L},{0x0659L,0xDD2AL},{1L,1L},{0xF30DL,0x12BCL},{8L,(-7L)},{7L,0xA12CL},{(-1L),1L},{0x78A7L,(-1L)}},{{0x12BCL,(-1L)},{0x78A7L,1L},{(-1L),0xA12CL},{7L,(-7L)},{8L,0x12BCL},{0xF30DL,1L},{1L,0xDD2AL},{0x0659L,1L},{0x795CL,0x78A7L},{0x38AEL,7L}},{{0x0659L,0L},{7L,1L},{7L,0x372EL},{8L,7L},{(-7L),0xA12CL},{1L,8L},{0x78A7L,0x2EBBL},{0x372EL,(-1L)},{0x679DL,8L},{(-1L),(-4L)}},{{(-7L),(-7L)},{1L,0x372EL},{0xF30DL,1L},{7L,0xDD2AL},{0L,7L},{0x795CL,0x679DL},{0x795CL,7L},{0L,0xDD2AL},{7L,1L},{0xF30DL,0x372EL}},{{1L,(-7L)},{(-7L),(-4L)},{(-1L),8L},{0x679DL,(-1L)},{0x372EL,0x2EBBL},{0x78A7L,8L},{1L,0xA12CL},{(-7L),7L},{8L,0x372EL},{7L,1L}},{{7L,0L},{0x0659L,7L},{0x38AEL,0x78A7L},{0x795CL,1L},{0x0659L,0xDD2AL},{1L,1L},{0xF30DL,0x12BCL},{8L,(-7L)},{7L,0xA12CL},{(-1L),1L}},{{0x78A7L,(-1L)},{0x12BCL,(-1L)},{0x78A7L,1L},{(-1L),0xA12CL},{7L,(-7L)},{8L,0x12BCL},{0xF30DL,1L},{1L,0xDD2AL},{0x0659L,1L},{0x795CL,0x78A7L}},{{0x38AEL,7L},{0x0659L,0L},{7L,1L},{7L,0x372EL},{8L,7L},{(-7L),0xA12CL},{1L,8L},{0x78A7L,0x2EBBL},{0x372EL,(-1L)},{0x679DL,8L}}};
            int i, j, k;
            for (i = 0; i < 5; i++)
                l_260[i] = 0L;
            l_263[2][0] = (l_237 != (j = (((0xF55769E9L != (g_3484 = (safe_rshift_func_uint16_t_u_u(((l_261 = (safe_add_func_int32_t_s_s((+l_237), (l_104[5][6] = ((l_260[0] = (safe_rshift_func_uint16_t_u_s((safe_add_func_uint16_t_u_u((l_88 || (!(safe_mod_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((g_3258 ^ (safe_mod_func_uint8_t_u_u((safe_sub_func_int16_t_s_s((safe_add_func_uint16_t_u_u(0x7869L, (l_88 | 0L))), 0x508AL)), p_50))), 1UL)), l_104[0][6])))), g_538)), g_1524))) == 0x2AFEL))))) == g_540), l_88)))) <= p_50) != 0x68L)));
            l_104[5][6] = (safe_add_func_uint32_t_u_u(((((((safe_add_func_int8_t_s_s(l_88, g_161)) >= p_50) >= (g_2420 = (safe_unary_minus_func_uint32_t_u(g_172[4])))) > (((safe_lshift_func_int8_t_s_s((0xF631L < (((0x9B79L < (safe_rshift_func_uint16_t_u_u((l_274[4][1] < (g_3258 = ((safe_rshift_func_int8_t_s_u(l_277[8][8][0], g_161)) == 0xB7205401L))), l_87))) >= g_172[4]) || g_172[6])), 1)) != g_172[1]) | l_237)) == l_263[0][1]) >= g_161), 0UL));
        }

}
                                                   int32_t BJgJgIg_115 = (~((((~((((g_103 & (l_268 || (((~(g_247)) || g_83) ^ l_87))) && (~((~(g_22))))) | (~((~(g_115))))))) ^ (~(l_88))) + (g_217 ^ l_136))));
int32_t BJgJgJl_136 = (~((((g_103 | ((~(l_136)) | g_217)) + ((BJgJgIg_115 & (l_268 / l_87)) >> ((~(l_88)) || (g_22 & g_247)))) | ((~(g_115)) | g_83))));
int32_t BJgJgKg_247 = (~((((~((l_136 ^ (g_22 << l_88)))) / ((~(g_115)) - g_217)) && (~((~(((BJgJgIg_115 / (~(BJgJgJl_136))) | (~((~(((l_268 + (~(((~(g_103)) & l_87)))) + (g_247 | g_83))))))))))))));
uint32_t BJgJgLg_103 = (~((g_22 % (((~((~(((~(g_247)) - BJgJgIg_115))))) + (~((~(l_136))))) | (((((l_87 >> l_88) || ((~(g_83)) / g_217)) | (~(l_268))) >> (~(BJgJgKg_247))) | ((~((~(g_115)))) && ((~(BJgJgJl_136)) | g_103)))))));
int32_t BJgJgMg_22 = (~((((~((~((~((BJgJgKg_247 / (~(g_83))))))))) + ((((~(g_22)) || (l_87 / g_115)) & l_136) ^ (((~(((BJgJgIg_115 % g_217) << l_88))) & (g_247 % BJgJgJl_136)) >> (~(l_268))))) / (~((BJgJgLg_103 & (~(g_103))))))));
uint8_t BJgJgNl_87 = (~(((~((~(((~(((g_103 & g_83) ^ BJgJgLg_103))) & (~(((l_87 / (~((~(l_136))))) + (((~(BJgJgMg_22)) - BJgJgIg_115) + (BJgJgKg_247 ^ (l_268 && g_115))))))))))) % ((BJgJgJl_136 && (~((~((~(((~(g_217)) && (~(g_22)))))))))) % (~(((~(g_247)) - (~((~(l_88)))))))))));
if((l_88<=1)){
BJgJgIg_115 = g_115;
BJgJgJl_136 = l_136;
LABEL_JgJgO: BJgJgKg_247 = g_247;
BJgJgLg_103 = g_103;
BJgJgMg_22 = g_22;
BJgJgNl_87 = l_87;
g_115 = (~(((((~(g_103)) / (BJgJgNl_87 || ((~(BJgJgKg_247)) & (~(g_247))))) && (~((~((~((g_22 - BJgJgJl_136)))))))) - ((((g_83 & l_88) & (l_87 && (((~(BJgJgMg_22)) & BJgJgIg_115) || (~(BJgJgLg_103))))) & (~(g_115))) + (~((~(((~(l_268)) & (g_217 || l_136))))))))));
l_136 = (~((((~((~((~((~(g_247)))))))) | ((((l_88 / g_217) / l_87) + BJgJgNl_87) + ((~((BJgJgLg_103 ^ BJgJgMg_22))) ^ g_22))) & (~((~((((BJgJgKg_247 || ((g_103 ^ (~(l_136))) ^ (l_268 - BJgJgIg_115))) / (~((~(BJgJgJl_136))))) - (~(((~(g_115)) / (~(g_83)))))))))))));
g_247 = (~(((~(((((BJgJgLg_103 || g_217) >> l_88) - ((l_268 | ((~(g_247)) % BJgJgIg_115)) - BJgJgMg_22)) | ((~(((~((BJgJgNl_87 >> l_87))) & g_103))) || (~((g_22 + l_136))))))) % (~((g_83 << (~((~(((~((g_115 & BJgJgJl_136))) && BJgJgKg_247)))))))))));
g_103 = (~(((((~(((~((l_88 + (~(g_22))))) / (g_83 | (g_247 & g_103))))) && ((BJgJgNl_87 | ((~(BJgJgLg_103)) % g_115)) + (~((l_87 ^ (l_136 ^ BJgJgIg_115)))))) + (~(((g_217 + BJgJgMg_22) ^ l_268)))) - (~((~((~(((~(BJgJgKg_247)) / BJgJgJl_136))))))))));
g_22 = (~(((~(((~((~((~((BJgJgNl_87 | (BJgJgLg_103 / l_88)))))))) - ((~(g_247)) << BJgJgKg_247)))) ^ ((((BJgJgMg_22 / l_268) & (((~(BJgJgIg_115)) ^ g_22) & (~((g_103 + (~(g_217))))))) - ((~(((~(g_115)) ^ (~(l_87))))) ^ (~(l_136)))) & (~((g_83 ^ BJgJgJl_136)))))));
l_87 = (~(((~((((~(((~((~(g_217)))) && ((BJgJgNl_87 & (~((~((~(g_103))))))) | (l_88 || (BJgJgLg_103 / l_268)))))) / (BJgJgIg_115 + (~(((l_87 - (~(g_115))) || l_136))))) >> (~((~(g_83))))))) || ((~((~((g_22 % BJgJgJl_136))))) || (g_247 || (~((BJgJgMg_22 << BJgJgKg_247))))))));
if((!BJgJgIg_115)){
printf("g_115=%lld\n", (long long)g_115);
goto LABEL_JgJgO;
}
if(!((BJgJgNl_87 > BJgJgMg_22))){
printf("g_247=%lld\n", (long long)g_247);
goto LABEL_JgJgO;
}
if((!BJgJgLg_103)){
printf("g_103=%llu\n", (unsigned long long)g_103);
break;
}
if(((g_83 > BJgJgNl_87) && (l_136 < BJgJgIg_115))){
printf("g_22=%lld\n", (long long)g_22);
goto LABEL_qgqgt;
}
if(((BJgJgNl_87 > g_83) && !(BJgJgLg_103))){
printf("l_87=%llu\n", (unsigned long long)l_87);
break;
}
}
g_115 = BJgJgIg_115;
l_136 = BJgJgJl_136;
g_247 = BJgJgKg_247;
g_103 = BJgJgLg_103;
g_22 = BJgJgMg_22;
l_87 = BJgJgNl_87;

                    for (l_87 = 0; (l_87 <= 0); l_87 += 1)
            {
                int32_t l_89 = 0x625CAFD9L;
                int32_t l_114 = (-1L);
                uint16_t l_116[10][5] = {{1UL,65534UL,0x3A66L,1UL,0x3A66L},{65535UL,65535UL,0x22B0L,0x65DDL,0x46F2L},{0xAA81L,0xE6F9L,0x3A66L,0x3A66L,0xE6F9L},{0x46F2L,0x35CAL,65526UL,0x46F2L,1UL},{0xCAF6L,0xE6F9L,0xBCFCL,0xE6F9L,0xCAF6L},{65526UL,65535UL,0x35CAL,1UL,65535UL},{0xCAF6L,65534UL,65534UL,0xCAF6L,0x3A66L},{0x46F2L,0x65DDL,0x22B0L,65535UL,65535UL},{0xAA81L,0xCAF6L,0xAA81L,0x3A66L,0xCAF6L},{65535UL,0x35CAL,1UL,65535UL,1UL}};
                int32_t l_119 = 0x48BAA0A5L;
                int i, j, k;
                l_82 = l_79[(l_80 + 1)][g_63][g_63];
                g_22 = ((((((l_89 = l_79[(l_80 + 1)][(l_80 + 1)][l_80]) != (safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s(p_50, (safe_unary_minus_func_uint16_t_u((p_50 > (l_118 = (l_117 = (l_88 = ((g_63 || 1L) <= (safe_add_func_uint8_t_u_u(((safe_sub_func_int16_t_s_s((g_63 && (l_104[5][6] = (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u((g_103 = g_63), 7)), 1)))), (g_115 = ((safe_lshift_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u((+g_83), (safe_add_func_int8_t_s_s((((safe_sub_func_int16_t_s_s((((((l_114 = (p_49 || p_49)) < g_22) && g_22) | p_49) || p_49), 0xA0AEL)) == l_79[1][0][0]) != 5UL), p_49)))) | g_4), 7)) & p_50)))) && l_116[3][1]), p_49))))))))))), g_63))) <= 0UL) == l_80) > l_82) && g_83);
                for (l_114 = 0; (l_114 <= 0); l_114 += 1)
                {
                    for (l_89 = 0; (l_89 <= 0); l_89 += 1)
                    {
                        uint16_t l_131 = 1UL;
                                                            while ((((l_80>0) && (g_161 < l_136)) && ((g_173 < l_80) || (!l_118))) )
{

g_540 += 1;


}
                    l_104[5][6] = p_50;
                        l_119 = (-1L);
                                                       int32_t Bqgqgnl_88 = (~(((((~(l_88)) | (((~(g_161)) ^ l_268) - g_4)) ^ (((g_115 ^ l_259) & l_82) | (~(l_306)))) % ((~(l_136)) | l_117))));
int32_t Bqgqgol_82 = (~(((~(l_136)) % (~(((((~(g_4)) ^ (~(l_88))) % (~(g_161))) + (((l_117 - l_82) | l_259) & ((g_115 | l_306) & (l_268 | Bqgqgnl_88)))))))));
int32_t Bqgqgpl_117 = (~(((((g_161 & (l_88 - l_136)) & ((~(l_259)) | l_82)) - ((~(((Bqgqgol_82 % g_4) << (~(Bqgqgnl_88))))) | (((~(l_117)) & (~(g_115))) | l_306))) ^ (~(l_268)))));
int32_t Bqgqgql_259 = (~(((~((~((l_259 | (((~((g_115 | (((l_306 & l_117) + Bqgqgnl_88) % (~(l_136)))))) | g_4) | (~((~(Bqgqgol_82)))))))))) + ((~((~(((~(l_88)) | (~(Bqgqgpl_117))))))) + ((l_268 - l_82) + (~(g_161)))))));
int16_t Bqgqgrl_306 = (~(((~(((((~((Bqgqgql_259 & (~(l_117))))) - l_88) % (~((((~(((~(g_161)) | Bqgqgnl_88))) & Bqgqgol_82) & l_82)))) & ((~(l_268)) - ((l_136 + g_4) & (~((l_259 % Bqgqgpl_117)))))))) - ((~((~((~(g_115)))))) ^ l_306))));
int32_t Bqgqgsg_115 = (~((((~(((~((~((g_161 ^ g_115))))) - (~((~(((Bqgqgql_259 + Bqgqgpl_117) | (((~((~(Bqgqgrl_306)))) + ((l_117 & Bqgqgol_82) | l_88)) - (~((~((l_306 + l_268)))))))))))))) >> (~(g_4))) + ((~((Bqgqgnl_88 & (~(l_136))))) + (~((l_82 + l_259)))))));
if((((g_161 < Bqgqgrl_306) && (l_88<=1)) && ((l_259<=-1) && Bqgqgnl_88))){
Bqgqgnl_88 = l_88;
Bqgqgol_82 = l_82;
LABEL_qgqgt: Bqgqgpl_117 = l_117;
                                    while (((!g_217) || ((!l_117) || (g_217 < g_63))) )
{

g_217 += 1;


}
                    Bqgqgql_259 = l_259;
Bqgqgrl_306 = l_306;
Bqgqgsg_115 = g_115;
l_88 = (~((((~((~((~((((~((~(Bqgqgpl_117)))) + ((~(l_268)) & l_117)) ^ (g_115 - ((Bqgqgol_82 | g_4) + l_82))))))))) & (((~(Bqgqgql_259)) + (l_259 ^ Bqgqgnl_88)) % (g_161 ^ ((l_136 | l_88) | (Bqgqgsg_115 & Bqgqgrl_306))))) | (~(l_306)))));
l_82 = (~(((~((~((((~((~(Bqgqgql_259)))) - (~((~(((~(Bqgqgsg_115)) ^ (l_259 - (~(g_115))))))))) & (((~((l_136 & Bqgqgnl_88))) % (~((g_161 % (~(l_306)))))) - ((Bqgqgrl_306 & ((~(l_268)) + l_117)) % (~(l_82))))))))) - ((((~(l_88)) + Bqgqgol_82) + g_4) + (~(Bqgqgpl_117))))));
LABEL_qgqgu: l_117 = (~((((~(((~((~(g_4)))) | ((~((l_268 + Bqgqgnl_88))) | Bqgqgol_82)))) ^ (~((g_161 - (~(l_82)))))) >> (~((((~(((~((~(Bqgqgql_259)))) | ((l_136 - l_88) + (~((l_117 % (~(Bqgqgrl_306))))))))) | ((~((Bqgqgsg_115 - (g_115 + l_306)))) + l_259)) + (~(Bqgqgpl_117))))))));
l_259 = (~((((~(((~(l_117)) | l_268))) & ((~((g_115 & Bqgqgpl_117))) % Bqgqgsg_115)) ^ ((~((((l_259 + (~(l_306))) | ((~((l_88 - g_4))) % (((~(g_161)) % l_82) ^ (~((~((Bqgqgol_82 - Bqgqgrl_306)))))))) + (Bqgqgnl_88 | Bqgqgql_259)))) + (~((~((~(l_136))))))))));
l_306 = (~(((((~(((~((~(((l_117 | l_82) - (Bqgqgrl_306 >> g_161)))))) ^ l_306))) % (Bqgqgql_259 + (Bqgqgnl_88 - Bqgqgsg_115))) & (~((((l_268 ^ l_136) & l_259) ^ (~(((~(Bqgqgpl_117)) | (g_4 ^ l_88)))))))) - (~((~(((~((~(Bqgqgol_82)))) + g_115))))))));
g_115 = (~(((~((~(((~((~(Bqgqgql_259)))) & (~((~(Bqgqgpl_117))))))))) & (~(((~(((((~((~(Bqgqgsg_115)))) - (~(Bqgqgnl_88))) & (((~(l_82)) + g_161) + (g_4 ^ (~((~(l_136))))))) | ((~(g_115)) & (l_268 - ((l_88 ^ l_306) + ((Bqgqgol_82 ^ l_259) ^ l_117))))))) ^ Bqgqgrl_306))))));
if((Bqgqgnl_88 < l_117)){
printf("l_88=%lld\n", (long long)l_88);
l_117 = (~(((((Bqgqgrl_306 + (~((l_136 ^ Bqgqgnl_88)))) | g_161) + (~((Bqgqgpl_117 << (~(((~(l_82)) << ((~(Bqgqgsg_115)) % ((~(l_117)) ^ (l_268 >> (~(g_4)))))))))))) + (((Bqgqgol_82 << l_259) + g_115) ^ ((~(l_88)) % (Bqgqgql_259 - l_306))))));
continue;
}
if((g_161>8U)){
printf("l_82=%lld\n", (long long)l_82);
goto LABEL_qgqgu;
}
if((!Bqgqgsg_115)){
printf("l_117=%lld\n", (long long)l_117);
Bqgqgsg_115 = (~(((~((((~((~(Bqgqgql_259)))) + ((g_115 % (~(g_4))) - (~(g_161)))) - (l_259 & ((~(l_117)) | l_82))))) & (~((((Bqgqgsg_115 % (l_88 % ((Bqgqgol_82 << Bqgqgrl_306) - l_268))) >> (~(Bqgqgpl_117))) >> (~(((~((~(l_136)))) & (l_306 << (~(Bqgqgnl_88))))))))))));
continue;
}
if((Bqgqgpl_117 > Bqgqgol_82)){

{
                        g_541 = 0x34207361L;
                    }

                    printf("l_259=%lld\n", (long long)l_259);
goto LABEL_qgqgt;
}
if((!l_306)){
printf("l_306=%lld\n", (long long)l_306);
continue;
}
if(!((l_117 < Bqgqgrl_306))){
printf("g_115=%lld\n", (long long)g_115);
continue;
}
}
l_88 = Bqgqgnl_88;
l_82 = Bqgqgol_82;
l_117 = Bqgqgpl_117;
l_259 = Bqgqgql_259;
l_306 = Bqgqgrl_306;
g_115 = Bqgqgsg_115;

                    g_22 = (safe_add_func_uint16_t_u_u((l_136 = (safe_sub_func_int8_t_s_s(((0UL == 249UL) > ((l_82 = p_49) || (safe_mod_func_uint32_t_u_u(((0x01A3L | (((4294967288UL ^ (~(((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s(((l_131 >= p_49) > l_88), (safe_sub_func_int16_t_s_s((safe_mod_func_int8_t_s_s((p_50 >= g_103), 0x7DL)), 65532UL)))), l_104[5][0])) | 0UL) || (-1L)))) < g_103) != g_115)) ^ (-1L)), g_63)))), l_118))), 0x6CB3L));
                    }
                    if (g_115)
                        break;
                }
                l_119 = g_22;
            }
            for (l_118 = 0; (l_118 <= 0); l_118 += 1)
            {
                uint8_t l_158 = 0UL;
                int32_t l_193 = (-1L);
                int16_t l_218 = 0x7D3DL;
                for (g_115 = 0; (g_115 <= 0); g_115 += 1)
                {
                    int i, j, k;
                    g_22 = (safe_add_func_int16_t_s_s((l_79[(g_115 + 4)][(g_63 + 1)][l_118] || p_49), g_83));
                    if (p_49)
                        {
p_49 += 1;


                    continue;}
                }
                                               uint32_t BJgJgPg_161 = (~((((l_88 + ((~(g_63)) - (g_247 / g_103))) | l_218) / (~(((~(((((~(g_22)) | (~((~(l_158))))) || g_173) % g_161))) % (~(l_118))))))));
uint16_t BJgJgQg_63 = (~((((~((BJgJgPg_161 / g_173))) - (~(l_118))) % ((l_218 || ((g_103 + l_88) ^ (~(g_161)))) && (~(((~((~(l_158)))) + ((g_22 % (~((~(g_247))))) & g_63))))))));
int32_t BJgJgRg_22 = (~(((~((((l_158 ^ g_103) + (g_22 & BJgJgPg_161)) / (~((~(((~(g_247)) ^ g_63)))))))) % (~(((~((((~(l_118)) - (~(BJgJgQg_63))) & (~((l_88 ^ g_161)))))) / (~((g_173 ^ l_218)))))))));
int16_t BJgJgSl_218 = (~(((~(((g_161 || (g_63 && BJgJgRg_22)) + (BJgJgPg_161 + l_88)))) + (~(((~(g_22)) && (((~(((g_173 | l_218) | l_158))) & ((l_118 + g_103) || BJgJgQg_63)) + g_247)))))));
int32_t BJgJgTl_88 = (~((((l_218 && (~((~(((g_63 || BJgJgQg_63) % BJgJgRg_22)))))) / ((~((g_247 & (~((l_118 ^ BJgJgSl_218)))))) + (g_161 | ((~(l_88)) & g_103)))) % (~((((g_22 || l_158) ^ g_173) - BJgJgPg_161))))));
uint8_t BJgJgUg_173 = (~(((~((((~((~(g_173)))) % (~(l_88))) / (~((~(((~(((~(g_22)) | BJgJgTl_88))) | g_247)))))))) + ((~((~(((g_103 && (BJgJgPg_161 % (~(((~(BJgJgQg_63)) / (~(l_218))))))) - g_63))))) ^ (~(((((l_118 | BJgJgRg_22) && g_161) | (~((~(l_158))))) + (~(BJgJgSl_218)))))))));
if(!((BJgJgUg_173>252))){
BJgJgPg_161 = g_161;
BJgJgQg_63 = g_63;
BJgJgRg_22 = g_22;
LABEL_JgJgV: BJgJgSl_218 = l_218;
BJgJgTl_88 = l_88;
BJgJgUg_173 = g_173;
g_161 = (~((((~((g_22 / (~((BJgJgTl_88 % g_161)))))) % (~(((~(g_173)) | ((~((g_247 ^ (~(BJgJgQg_63))))) ^ ((BJgJgRg_22 >> l_118) << (g_103 + (BJgJgSl_218 | (~(l_218)))))))))) / (~((~(((~(((BJgJgUg_173 + l_88) - BJgJgPg_161))) | (l_158 ^ (~((~(g_63)))))))))))));
g_63 = (~(((~((~(((BJgJgSl_218 << BJgJgPg_161) >> (g_173 + ((BJgJgUg_173 | l_88) << (l_118 % g_103)))))))) - (~((~(((((~((~(BJgJgTl_88)))) - (l_218 / g_161)) - ((~((~(g_63)))) & (g_247 && ((~((~(BJgJgQg_63)))) && (BJgJgRg_22 + g_22))))) + (~((~((~((~(l_158))))))))))))))));
g_22 = (~(((~(l_88)) + (((l_118 / (g_247 || BJgJgSl_218)) | (((l_218 ^ (g_173 % BJgJgPg_161)) / ((~(BJgJgTl_88)) ^ (l_158 >> (g_161 + g_22)))) % ((~((~(BJgJgUg_173)))) ^ (~(g_103))))) + (~((~((~((BJgJgRg_22 || (BJgJgQg_63 / g_63))))))))))));
l_218 = (~(((((~(BJgJgRg_22)) / (~(BJgJgTl_88))) << l_158) && (~(((((~((((~(l_218)) && (~((g_161 % g_63)))) + (~(((BJgJgPg_161 - g_247) & g_22)))))) & (~(((BJgJgQg_63 >> BJgJgUg_173) ^ (~(l_88)))))) && (~(((g_103 && g_173) || BJgJgSl_218)))) + (~((~((~(l_118))))))))))));
l_88 = (~(((~((((l_158 && (g_173 & BJgJgPg_161)) >> ((~(l_88)) & (g_161 && ((BJgJgUg_173 || (~(((~((g_247 - (~((~(g_22))))))) / g_63)))) % (~((g_103 ^ l_118))))))) || (~((BJgJgQg_63 | BJgJgSl_218)))))) || (~((~((~((BJgJgRg_22 % (~((BJgJgTl_88 || l_218)))))))))))));
g_173 = (~((((~((((~((~(BJgJgPg_161)))) || ((~(BJgJgTl_88)) || (~(((g_63 || (g_173 ^ l_88)) + BJgJgQg_63))))) || (BJgJgUg_173 & (l_218 || l_118))))) / (~(((~((~((~(BJgJgRg_22)))))) && ((~(((BJgJgSl_218 + (g_247 + g_103)) | (~((~((~(g_22))))))))) & (~((~(l_158))))))))) ^ g_161)));
if((!g_247)){
printf("g_161=%llu\n", (unsigned long long)g_161);
break;
}
if((BJgJgUg_173 > BJgJgPg_161)){
printf("g_63=%llu\n", (unsigned long long)g_63);
break;
}
if((!BJgJgRg_22)){
printf("g_22=%lld\n", (long long)g_22);
continue;
}
if((g_173 > BJgJgSl_218)){
printf("l_218=%lld\n", (long long)l_218);
BJgJgSl_218 = (~(((~((~((((~((~(g_173)))) >> (~((((BJgJgQg_63 + g_161) | BJgJgUg_173) >> (BJgJgSl_218 >> (((BJgJgPg_161 % l_118) / BJgJgRg_22) >> (~(l_158)))))))) / ((g_22 || (~((~((l_88 % l_218)))))) % (g_63 / (~(g_247))))))))) & (~(((~(g_103)) | (~((~(BJgJgTl_88))))))))));
goto LABEL_JgJgV;
}
if((g_63>45248)){
printf("l_88=%lld\n", (long long)l_88);
break;
}
if((g_247>7)){
printf("g_173=%llu\n", (unsigned long long)g_173);
BJgJgSl_218 = (~(((((~(((~(l_118)) / (BJgJgRg_22 && (~((~(g_247)))))))) - (~((~(BJgJgSl_218))))) % ((~(g_103)) ^ (((~((~(g_63)))) + (BJgJgUg_173 % (BJgJgQg_63 << l_158))) && ((~((~(g_22)))) & l_218)))) >> (~((~(((BJgJgTl_88 - (BJgJgPg_161 + l_88)) && (~(((~(g_173)) << g_161)))))))))));
break;
}
}
g_161 = BJgJgPg_161;
g_63 = BJgJgQg_63;
g_22 = BJgJgRg_22;
l_218 = BJgJgSl_218;
l_88 = BJgJgTl_88;
g_173 = BJgJgUg_173;

                    if ((l_136 = g_22))
                {
                    uint32_t l_145 = 0x463E212FL;
                    int32_t l_159 = 0x7C7E8E6BL;
                    int i, j, k;
                    l_160[1][0] = (p_49 | ((safe_mod_func_int8_t_s_s((((safe_mod_func_int8_t_s_s((((safe_add_func_int16_t_s_s(l_145, l_145)) >= (safe_mod_func_uint16_t_u_u((g_161 = (9UL >= (safe_lshift_func_int16_t_s_u(((0x9404BF6FL & (safe_unary_minus_func_uint8_t_u(((l_79[(l_118 + 3)][g_63][g_63] = (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((((l_82 = (safe_unary_minus_func_uint32_t_u((safe_rshift_func_uint8_t_u_u((0xA192L <= ((l_159 = (((((l_136 = ((l_88 = (-1L)) >= (((0UL & l_80) < g_83) <= p_49))) || 0xA3C1A26CL) <= l_158) | g_115) > 0x4CD6L)) | g_22)), p_49))))) && 1L) && (-4L)), g_63)), 7))) != 0x87L)))) | l_160[1][0]), 5)))), g_22))) ^ p_50), p_49)) < 0xB1L) <= l_80), p_50)) && l_104[3][0]));
                                                        while ((!g_4) )
{

{
    uint8_t l_79[5][2][1] = {{{0xCDL},{0x09L}},{{0xCDL},{0x09L}},{{0xCDL},{0x09L}},{{0xCDL},{0x09L}},{{0xCDL},{0x09L}}};
    int32_t l_80 = 0x7FAA682DL;
    int32_t l_88 = 0x3CEB4B62L;
    int32_t l_117 = 0x9AA43C15L;
    int16_t l_201 = 9L;
    int32_t l_259 = (-1L);
    int32_t l_268 = (-9L);
    int i, j, k;
    for (g_538 = 0; (g_538 <= 0); g_538 += 1)
    {
        uint8_t l_87 = 1UL;
        int32_t l_104[6][9] = {{0xAA260870L,(-1L),(-1L),0xAA260870L,(-1L),(-1L),0xAA260870L,0x21B11E67L,0x21B11E67L},{0xB10BEF9BL,0L,0x691EA77CL,0xB10BEF9BL,0x691EA77CL,0L,0xB10BEF9BL,0L,0L},{0xAA260870L,(-1L),(-1L),0xAA260870L,(-1L),(-1L),0xAA260870L,0x21B11E67L,0x21B11E67L},{0xB10BEF9BL,0L,0x691EA77CL,0xB10BEF9BL,0x691EA77CL,(-6L),0L,(-9L),(-9L)},{0x21B11E67L,0x1F4E5A65L,8L,0x21B11E67L,8L,0x1F4E5A65L,0x21B11E67L,0x37DDF4F0L,0x37DDF4F0L},{0L,(-6L),(-1L),0L,(-1L),(-6L),0L,(-9L),(-9L)}};
        int32_t l_262 = 0xC8414168L;
        int32_t l_263[3][2];
        int16_t l_306 = 1L;
        int i, j;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 2; j++)
                l_263[i][j] = 0x2B217F77L;
        }
        l_80 = l_145;
        for (l_80 = 0; (l_80 >= 0); l_80 -= 1)
        {
            int32_t l_82 = 1L;
            int8_t l_118 = (-1L);
            int32_t l_136 = 0x05D4F871L;
            int32_t l_160[9][3] = {{(-6L),(-6L),(-6L)},{0xE17D4CA5L,0xE17D4CA5L,0xE17D4CA5L},{(-6L),(-6L),(-6L)},{0xE17D4CA5L,0xE17D4CA5L,0xE17D4CA5L},{(-6L),(-6L),(-6L)},{0xE17D4CA5L,0xE17D4CA5L,0xE17D4CA5L},{(-6L),(-6L),(-6L)},{0xE17D4CA5L,0xE17D4CA5L,0xE17D4CA5L},{(-6L),(-6L),(-6L)}};
            int i, j;
            l_118 = (g_3258 = (!l_82));
            if (((l_88 = (l_118 != (((safe_lshift_func_uint8_t_u_u(l_118, l_79[3][1][0])) < ((((~l_145) != (l_82 = 0L)) && ((((0x7DD3L > 1UL) | l_87) != ((l_118 && g_188) == l_87)) || l_87)) <= g_188)) >= (-7L)))) && 0UL))
            {
                if (g_188)
                    break;
            }
            else
            {
                if (g_538)
                    break;
            }
            for (l_87 = 0; (l_87 <= 0); l_87 += 1)
            {
                int32_t l_89 = 0x625CAFD9L;
                int32_t l_114 = (-1L);
                uint16_t l_116[10][5] = {{1UL,65534UL,0x3A66L,1UL,0x3A66L},{65535UL,65535UL,0x22B0L,0x65DDL,0x46F2L},{0xAA81L,0xE6F9L,0x3A66L,0x3A66L,0xE6F9L},{0x46F2L,0x35CAL,65526UL,0x46F2L,1UL},{0xCAF6L,0xE6F9L,0xBCFCL,0xE6F9L,0xCAF6L},{65526UL,65535UL,0x35CAL,1UL,65535UL},{0xCAF6L,65534UL,65534UL,0xCAF6L,0x3A66L},{0x46F2L,0x65DDL,0x22B0L,65535UL,65535UL},{0xAA81L,0xCAF6L,0xAA81L,0x3A66L,0xCAF6L},{65535UL,0x35CAL,1UL,65535UL,1UL}};
                int32_t l_119 = 0x48BAA0A5L;
                int i, j, k;
                l_82 = l_79[(l_80 + 1)][g_538][g_538];
                g_3258 = ((((((l_89 = l_79[(l_80 + 1)][(l_80 + 1)][l_80]) != (safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s(g_188, (safe_unary_minus_func_uint16_t_u((g_188 > (l_118 = (l_117 = (l_88 = ((g_538 || 1L) <= (safe_add_func_uint8_t_u_u(((safe_sub_func_int16_t_s_s((g_538 && (l_104[5][6] = (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u((l_145 = g_538), 7)), 1)))), (l_259 = ((safe_lshift_func_int8_t_s_s(((safe_mod_func_uint16_t_u_u((+l_118), (safe_add_func_int8_t_s_s((((safe_sub_func_int16_t_s_s((((((l_114 = (l_145 || l_145)) < g_3258) && g_3258) | l_145) || l_145), 0xA0AEL)) == l_79[1][0][0]) != 5UL), l_145)))) | l_118), 7)) & g_188)))) && l_116[3][1]), l_145))))))))))), g_538))) <= 0UL) == l_80) > l_82) && l_118);
                for (l_114 = 0; (l_114 <= 0); l_114 += 1)
                {
                    for (l_89 = 0; (l_89 <= 0); l_89 += 1)
                    {
                        uint16_t l_131 = 1UL;
                        l_104[5][6] = g_188;
                        l_119 = (-1L);
                        g_3258 = (safe_add_func_uint16_t_u_u((l_136 = (safe_sub_func_int8_t_s_s(((0UL == 249UL) > ((l_82 = l_145) || (safe_mod_func_uint32_t_u_u(((0x01A3L | (((4294967288UL ^ (~(((safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s(((l_131 >= l_145) > l_88), (safe_sub_func_int16_t_s_s((safe_mod_func_int8_t_s_s((g_188 >= l_145), 0x7DL)), 65532UL)))), l_104[5][0])) | 0UL) || (-1L)))) < l_145) != l_259)) ^ (-1L)), g_538)))), l_118))), 0x6CB3L));
                    }
                    if (l_259)
                        break;
                }
                l_119 = g_3258;
            }
            for (l_118 = 0; (l_118 <= 0); l_118 += 1)
            {
                uint8_t l_158 = 0UL;
                int32_t l_193 = (-1L);
                int16_t l_218 = 0x7D3DL;
                for (l_259 = 0; (l_259 <= 0); l_259 += 1)
                {
                    int i, j, k;
                    g_3258 = (safe_add_func_int16_t_s_s((l_79[(l_259 + 4)][(g_538 + 1)][l_118] || l_145), l_118));
                    if (l_145)
                        continue;
                }
                if ((l_136 = g_3258))
                {
                    uint32_t l_145 = 0x463E212FL;
                    int32_t l_159 = 0x7C7E8E6BL;
                    int i, j, k;
                    l_160[1][0] = (l_145 | ((safe_mod_func_int8_t_s_s((((safe_mod_func_int8_t_s_s((((safe_add_func_int16_t_s_s(l_145, l_145)) >= (safe_mod_func_uint16_t_u_u((l_145 = (9UL >= (safe_lshift_func_int16_t_s_u(((0x9404BF6FL & (safe_unary_minus_func_uint8_t_u(((l_79[(l_118 + 3)][g_538][g_538] = (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((((l_82 = (safe_unary_minus_func_uint32_t_u((safe_rshift_func_uint8_t_u_u((0xA192L <= ((l_159 = (((((l_136 = ((l_88 = (-1L)) >= (((0UL & l_80) < l_118) <= l_145))) || 0xA3C1A26CL) <= l_158) | l_259) > 0x4CD6L)) | g_3258)), l_145))))) && 1L) && (-4L)), g_538)), 7))) != 0x87L)))) | l_160[1][0]), 5)))), g_3258))) ^ g_188), l_145)) < 0xB1L) <= l_80), g_188)) && l_104[3][0]));
                    if (((((g_12 = ((l_104[5][6] = l_145) >= (((g_3258 = 0x3B790C2EL) != (((safe_rshift_func_uint16_t_u_u(g_538, 14)) ^ (0xCE46L <= (safe_lshift_func_int8_t_s_s((((safe_mod_func_int32_t_s_s((((safe_add_func_uint32_t_u_u(((l_118 = ((l_87 ^ l_87) ^ 65526UL)) >= ((g_172[4] = ((((-1L) != (safe_add_func_uint8_t_u_u((g_188 || 0x6976L), l_160[3][0]))) < l_145) <= l_145)) != 0UL)), 6UL)) < g_538) < l_259), l_117)) & g_188) || 1UL), 6)))) >= 0x8CL)) & g_538))) || g_188) <= 0xA9L) ^ l_145))
                    {
                        g_3258 = (l_118 != l_145);
                    }
                    else
                    {
                        return l_118;
                    }
                    for (l_145 = 0; (l_145 == 42); l_145 = safe_add_func_uint32_t_u_u(l_145, 6))
                    {
                        if (l_145)
                            break;
                        l_160[1][0] = l_145;
                        l_201 = ((l_158 && (safe_add_func_uint32_t_u_u((safe_add_func_uint32_t_u_u(g_188, (safe_add_func_uint8_t_u_u(l_104[5][6], (l_160[2][1] = l_158))))), (((safe_sub_func_int32_t_s_s((l_159 = (g_3258 = l_79[(l_118 + 3)][g_538][g_538])), (((4294967295UL < (safe_sub_func_int8_t_s_s(l_145, (7L ^ (safe_sub_func_int8_t_s_s((g_188 < g_12), g_188)))))) || g_172[4]) > l_158))) & l_104[5][6]) >= 0x816EFC97L)))) ^ l_118);
                    }
                }
                else
                {
                    int8_t l_204 = (-1L);
                    int32_t l_205 = 0xA341128DL;
                    if ((0xB969A7E2L != (l_145 == (safe_mod_func_int32_t_s_s(g_188, 0x24DCF8C1L)))))
                    {
                        l_193 = (((-1L) <= (safe_lshift_func_int8_t_s_s(l_201, g_538))) > l_160[7][2]);
                        l_193 = 0L;
                        if (g_538)
                            break;
                    }
                    else
                    {
                        int32_t l_203 = (-8L);
                        l_104[1][7] = (0x8075L != ((g_188 = l_87) >= (l_145 && (0xAB5394E2L >= 0UL))));
                        g_3258 = (((l_88 = (((l_145 | 0UL) < (l_145 && ((l_205 = (((g_12 && g_188) > (safe_sub_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((g_3258 > ((safe_mod_func_int16_t_s_s(((l_118 <= (((~l_201) != (((((((+(g_188 > g_12)) && g_12) <= g_188) > 3UL) == l_145) > l_203) >= l_145)) ^ 0xE3DCAB47L)) >= l_204), 0xEE06L)) == 0x9DDDL)), 0xE14EL)) && l_203), 0UL))) <= g_172[4])) == l_145))) && (-2L))) | 0xBAB4L) || 1UL);
                        return g_12;
                    }
                    l_193 = (safe_lshift_func_uint8_t_u_s(((-2L) == (safe_rshift_func_int8_t_s_s((((g_188 & ((safe_add_func_int16_t_s_s((0xE4L || (safe_rshift_func_uint8_t_u_s(g_172[4], g_3258))), (l_218 = (g_12 = ((l_117 < 0xAD95808BL) ^ ((safe_rshift_func_int8_t_s_s((safe_unary_minus_func_int16_t_s(l_201)), ((0x4EEEL == 6L) && 0xC3D4A470L))) || l_145)))))) > (-1L))) <= l_259) == l_82), g_3258))), 1));
                }
                g_3258 = (((-1L) | g_538) > (+l_218));
                g_3258 = ((((l_88 = (safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(((0x4A28L >= l_145) || ((l_145 = ((safe_sub_func_uint8_t_u_u(l_218, (safe_rshift_func_uint8_t_u_s(l_82, (+0xA994BE0AL))))) || ((safe_lshift_func_uint8_t_u_u((l_218 != (safe_lshift_func_int8_t_s_s(l_145, 3))), 4)) < ((safe_mod_func_int8_t_s_s(g_12, (safe_lshift_func_uint16_t_u_u(((-1L) <= 1UL), g_188)))) < 0x90L)))) >= g_3258)), 7)), l_145))) == 0L) & l_158) < 0x193FL);
            }
        }
        if (((l_201 <= 0L) ^ 0xA2L))
        {
            uint16_t l_237 = 65526UL;
            int32_t l_260[5];
            int32_t l_261 = 4L;
            uint32_t l_274[7][10] = {{0x9183A3A1L,0xD0E7BC49L,1UL,4294967295UL,0x4EE4472DL,1UL,0xFA7611F6L,0x0EC4D18DL,0x0EC4D18DL,0xFA7611F6L},{4294967295UL,0x9183A3A1L,4294967295UL,4294967295UL,0x9183A3A1L,4294967295UL,4294967295UL,1UL,0xBC1D7A0BL,0UL},{0UL,0x0EC4D18DL,0xD0E7BC49L,1UL,1UL,0UL,4294967295UL,0UL,1UL,1UL},{0UL,0UL,0UL,4294967292UL,0xFA7611F6L,4294967295UL,1UL,0x4EE4472DL,0xD0E7BC49L,1UL},{4294967295UL,1UL,0x4EE4472DL,0xD0E7BC49L,1UL,1UL,0xD0E7BC49L,0x4EE4472DL,1UL,4294967295UL},{0x9183A3A1L,0x45722FB2L,0UL,0x0EC4D18DL,0xD0E7BC49L,1UL,1UL,0UL,4294967295UL,0UL},{0xBC1D7A0BL,0UL,0xD0E7BC49L,0x45722FB2L,0xD0E7BC49L,0UL,0xBC1D7A0BL,1UL,4294967295UL,4294967295UL}};
            int16_t l_277[9][10][2] = {{{1L,8L},{0x6338L,0L},{(-1L),7L},{0x35ABL,1L},{(-6L),0L},{0x372EL,0x97CDL},{1L,0xDD2AL},{0L,0x35ABL},{(-1L),0L},{3L,0x78A7L}},{{8L,3L},{0x38AEL,0x78A7L},{0x795CL,1L},{0x0659L,0xDD2AL},{1L,1L},{0xF30DL,0x12BCL},{8L,(-7L)},{7L,0xA12CL},{(-1L),1L},{0x78A7L,(-1L)}},{{0x12BCL,(-1L)},{0x78A7L,1L},{(-1L),0xA12CL},{7L,(-7L)},{8L,0x12BCL},{0xF30DL,1L},{1L,0xDD2AL},{0x0659L,1L},{0x795CL,0x78A7L},{0x38AEL,7L}},{{0x0659L,0L},{7L,1L},{7L,0x372EL},{8L,7L},{(-7L),0xA12CL},{1L,8L},{0x78A7L,0x2EBBL},{0x372EL,(-1L)},{0x679DL,8L},{(-1L),(-4L)}},{{(-7L),(-7L)},{1L,0x372EL},{0xF30DL,1L},{7L,0xDD2AL},{0L,7L},{0x795CL,0x679DL},{0x795CL,7L},{0L,0xDD2AL},{7L,1L},{0xF30DL,0x372EL}},{{1L,(-7L)},{(-7L),(-4L)},{(-1L),8L},{0x679DL,(-1L)},{0x372EL,0x2EBBL},{0x78A7L,8L},{1L,0xA12CL},{(-7L),7L},{8L,0x372EL},{7L,1L}},{{7L,0L},{0x0659L,7L},{0x38AEL,0x78A7L},{0x795CL,1L},{0x0659L,0xDD2AL},{1L,1L},{0xF30DL,0x12BCL},{8L,(-7L)},{7L,0xA12CL},{(-1L),1L}},{{0x78A7L,(-1L)},{0x12BCL,(-1L)},{0x78A7L,1L},{(-1L),0xA12CL},{7L,(-7L)},{8L,0x12BCL},{0xF30DL,1L},{1L,0xDD2AL},{0x0659L,1L},{0x795CL,0x78A7L}},{{0x38AEL,7L},{0x0659L,0L},{7L,1L},{7L,0x372EL},{8L,7L},{(-7L),0xA12CL},{1L,8L},{0x78A7L,0x2EBBL},{0x372EL,(-1L)},{0x679DL,8L}}};
            int i, j, k;
            for (i = 0; i < 5; i++)
                l_260[i] = 0L;
            l_263[2][0] = (l_237 != (l_262 = (((0xF55769E9L != (l_80 = (safe_rshift_func_uint16_t_u_u(((l_261 = (safe_add_func_int32_t_s_s((+l_237), (l_104[5][6] = ((l_260[0] = (safe_rshift_func_uint16_t_u_s((safe_add_func_uint16_t_u_u((l_117 || (!(safe_mod_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((l_117 ^ (safe_mod_func_uint8_t_u_u((safe_sub_func_int16_t_s_s((safe_add_func_uint16_t_u_u(0x7869L, (l_259 | 0L))), 0x508AL)), g_188))), 1UL)), l_104[0][6])))), g_538)), l_201))) == 0x2AFEL))))) == l_145), l_259)))) <= g_188) != 0x68L)));
            l_104[5][6] = (safe_add_func_uint32_t_u_u(((((((safe_add_func_int8_t_s_s(l_268, l_145)) >= g_188) >= (l_118 = (safe_unary_minus_func_uint32_t_u(g_172[4])))) > (((safe_lshift_func_int8_t_s_s((0xF631L < (((0x9B79L < (safe_rshift_func_uint16_t_u_u((l_274[4][1] < (l_117 = ((safe_rshift_func_int8_t_s_u(l_277[8][8][0], l_145)) == 0xB7205401L))), g_12))) >= g_172[4]) || g_172[6])), 1)) != g_172[1]) | l_237)) == l_263[0][1]) >= l_145), 0UL));
        }
        else
        {
            int16_t l_295 = 0x4B2EL;
            int32_t l_305 = 0L;
            l_117 = (safe_sub_func_int8_t_s_s((((~(safe_rshift_func_uint8_t_u_s(((((g_12 = ((safe_add_func_int8_t_s_s(g_188, (safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s((safe_rshift_func_int8_t_s_s((0x6986D460L | ((((safe_mod_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s(l_295, 3)) > ((0x1AC507ADL >= (((safe_unary_minus_func_uint8_t_u((safe_add_func_uint8_t_u_u((l_262 = (safe_lshift_func_int16_t_s_u(((250UL && (l_104[5][6] = ((l_305 = ((safe_add_func_int32_t_s_s((safe_mod_func_int8_t_s_s(g_3258, g_188)), l_145)) & ((l_145 == g_188) ^ l_145))) ^ l_145))) >= l_262), 3))), 0x05L)))) >= l_87) || 0x4A90L)) < l_268)) < l_117), 65535UL)) < 0x0D65L) & 0x98E9L) >= l_201)), 3)), 2)) > 0x7EF9L), g_12)))) >= l_145)) <= 0L) != l_306) || 0xBECC66A6L), l_259))) >= l_145) >= g_188), l_145));
        }
        l_104[5][5] = (l_263[0][0] = ((safe_add_func_int32_t_s_s(g_188, l_117)) == ((1UL || 0x8C5AC05FL) | g_172[5])));
    }
    return l_80;
}

}
                    if (((((g_173 = ((l_104[5][6] = p_49) >= (((g_22 = 0x3B790C2EL) != (((safe_rshift_func_uint16_t_u_u(g_63, 14)) ^ (0xCE46L <= (safe_lshift_func_int8_t_s_s((((safe_mod_func_int32_t_s_s((((safe_add_func_uint32_t_u_u(((g_83 = ((l_87 ^ l_87) ^ 65526UL)) >= ((g_172[4] = ((((-1L) != (safe_add_func_uint8_t_u_u((p_50 || 0x6976L), l_160[3][0]))) < g_103) <= g_161)) != 0UL)), 6UL)) < g_63) < g_115), l_117)) & p_50) || 1UL), 6)))) >= 0x8CL)) & g_63))) || p_50) <= 0xA9L) ^ p_49))
                    {
                                                            while ((!l_87) )
{

{
    uint32_t l_5[6][7] = {{0x327439CBL,0xB03629AAL,0UL,0UL,0xB03629AAL,0x327439CBL,2UL},{1UL,0UL,0x91F782A1L,2UL,1UL,1UL,2UL},{0xFE4B2830L,0x1D2250DBL,0xFE4B2830L,7UL,2UL,1UL,0x327439CBL},{0x91F782A1L,0UL,1UL,7UL,1UL,0UL,0x91F782A1L},{0UL,0xB03629AAL,0x327439CBL,2UL,0UL,1UL,0UL},{0UL,0UL,0UL,0UL,0xFE4B2830L,1UL,7UL}};
    int32_t l_2266[5];
    int32_t l_2290 = (-5L);
    uint8_t l_2292 = 0xB3L;
    int32_t l_2294 = (-3L);
    int32_t l_2296 = 1L;
    int32_t l_2408[5][6] = {{0L,0L,0xC284D198L,1L,0L,1L},{0L,0L,0L,1L,0L,0xC284D198L},{0L,0L,1L,1L,0L,0L},{0L,0L,0xC284D198L,1L,0L,1L},{0L,0L,0L,1L,0L,0xC284D198L}};
    int8_t l_2418[6][5] = {{0L,0L,0L,0L,0xCAL},{0xD8L,0xA7L,0L,6L,0xCAL},{0L,0xD8L,(-1L),(-8L),(-1L)},{(-8L),(-8L),0xCAL,6L,0L},{0x38L,1L,0xCAL,0L,0L},{(-9L),0xCAL,(-1L),0xCAL,(-9L)}};
    int8_t l_2465 = 0x95L;
    int8_t l_2526 = 1L;
    int16_t l_2601 = 0L;
    uint8_t l_2674 = 0x97L;
    uint32_t l_2692 = 1UL;
    uint32_t l_2790[6][3] = {{0xCD6BF178L,0xCD6BF178L,0xCD6BF178L},{18446744073709551609UL,18446744073709551609UL,18446744073709551609UL},{0xCD6BF178L,0xCD6BF178L,0xCD6BF178L},{18446744073709551609UL,18446744073709551609UL,18446744073709551609UL},{0xCD6BF178L,0xCD6BF178L,0xCD6BF178L},{18446744073709551609UL,18446744073709551609UL,18446744073709551609UL}};
    uint32_t l_2841 = 18446744073709551607UL;
    uint32_t l_2899 = 2UL;
    int32_t l_3017 = 0x0B37558CL;
    int32_t l_3116 = 0L;
    uint8_t l_3151 = 0x0AL;
    uint16_t l_3171 = 65535UL;
    uint32_t l_3257 = 1UL;
    int32_t l_3262 = (-1L);
    uint32_t l_3399 = 7UL;
    uint8_t l_3408 = 0x12L;
    uint8_t l_3424[2][3][5] = {{{0x72L,0x5BL,0xBDL,2UL,0xBDL},{1UL,1UL,0x5BL,255UL,0xEBL},{0x72L,0xEBL,0x76L,255UL,255UL}},{{255UL,0x16L,255UL,0x72L,0xEBL},{255UL,0xBDL,0x16L,0x5BL,0xEBL},{1UL,2UL,2UL,1UL,255UL}}};
    int32_t l_3471 = 0x35FC95CDL;
    int32_t l_3492 = 0x5429EDD7L;
    uint16_t l_3534 = 3UL;
    uint32_t l_3573[10] = {6UL,6UL,6UL,6UL,6UL,6UL,6UL,6UL,6UL,6UL};
    uint8_t l_3655 = 1UL;
    int8_t l_3667 = (-1L);
    int8_t l_3683 = (-1L);
    uint16_t l_3702 = 0x4BDBL;
    int32_t l_3707 = 1L;
    int32_t l_3721 = 0x7BC1F5CCL;
    int8_t l_3741 = 0x63L;
    uint8_t l_3752 = 255UL;
    int32_t l_3755[2][2][7] = {{{0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L},{0L,0L,0L,0L,0L,0L,0L}},{{0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L,0x55919521L},{0L,0L,0L,0L,0L,0L,0L}}};
    uint16_t l_3775 = 0x252EL;
    int32_t l_3872 = 0L;
    int32_t l_3873 = 0xE2017063L;
    int32_t l_3874[9] = {0L,0L,0L,0L,0L,0L,0L,0L,0L};
    int32_t l_3891 = 0x323AE330L;
    int32_t l_3908 = (-7L);
    int8_t l_4035 = 1L;
    int i, j, k;
    for (i = 0; i < 5; i++)
        l_2266[i] = 0x3DF77380L;
    if ((((safe_lshift_func_uint16_t_u_s(g_361, 8)) | l_5[1][6]) != func_6((l_2266[3] = ((g_813[3][0] = func_8(l_5[1][6])) || (!(l_5[1][6] <= 1UL)))))))
    {
        uint32_t l_2279 = 0x93AE2901L;
        int32_t l_2291[2];
        int32_t l_2293[10][5][5] = {{{0x45777B37L,4L,(-5L),(-10L),(-5L)},{0xA9C5A221L,0xA9C5A221L,0x9C7A75D8L,0xD4EDE40DL,0x8ED2113AL},{0xFE015731L,2L,6L,0xA4130E32L,(-3L)},{0x4F8FF695L,9L,0xD4EDE40DL,0x6B855A03L,(-2L)},{0L,2L,0x45777B37L,0xEF9A929BL,1L}},{{(-1L),0xA9C5A221L,0x3F2DF9F6L,0x9C7A75D8L,0x4F8FF695L},{0x05E1541BL,4L,0xFE015731L,1L,(-4L)},{0x2F4D056CL,0x2206AE63L,0xD4EDE40DL,0xE58FA5B4L,0x2F4D056CL},{0x4E1AA23AL,0xEF9A929BL,0L,1L,(-7L)},{(-1L),(-8L),0x9C7A75D8L,0x9C7A75D8L,(-8L)}},{{(-3L),(-4L),0x05E1541BL,0xEF9A929BL,0xD31BC39FL},{0xE58FA5B4L,0x9C7A75D8L,0xEBCBB2E6L,0x6B855A03L,0x2F4D056CL},{(-7L),1L,0x4E1AA23AL,0xA4130E32L,0x141ABB78L},{0xE58FA5B4L,0x8ED2113AL,0xF2DC1619L,0xD4EDE40DL,0x4F8FF695L},{(-3L),(-9L),(-3L),(-10L),(-5L)}},{{(-1L),(-7L),0x2206AE63L,(-8L),(-2L)},{0x4E1AA23AL,1L,(-7L),4L,(-7L)},{0x2F4D056CL,(-1L),0x2206AE63L,(-1L),0x8ED2113AL},{0x05E1541BL,(-4L),(-3L),(-4L),0x05E1541BL},{(-1L),(-9L),0xF2DC1619L,(-2L),0xA9C5A221L}},{{0L,0xEF9A929BL,0x4E1AA23AL,4L,5L},{0x4F8FF695L,0xE58FA5B4L,0xEBCBB2E6L,(-9L),0xA9C5A221L},{0xFE015731L,4L,0x05E1541BL,(-10L),0x05E1541BL},{0xA9C5A221L,0x3F2DF9F6L,0x9C7A75D8L,0x4F8FF695L,0x8ED2113AL},{0x45777B37L,2L,0L,0xA4130E32L,(-7L)}},{{0x4F8FF695L,(-1L),0xD4EDE40DL,0xC4371B6FL,(-2L)},{6L,6L,0x80113FBEL,4L,(-4L)},{0xA9C5A221L,0xC4371B6FL,0xC4371B6FL,0xA9C5A221L,(-8L)},{0L,1L,4L,2L,(-5L)},{(-1L),(-1L),(-9L),9L,(-1L)}},{{0xD31BC39FL,4L,(-3L),2L,1L},{0x4F8FF695L,0x9C7A75D8L,0x3F2DF9F6L,0xA9C5A221L,(-1L)},{5L,(-9L),0L,4L,0x9616CC94L},{(-1L),0xA9C5A221L,0xF2DC1619L,0x2206AE63L,(-1L)},{1L,(-10L),0xD31BC39FL,0xEF9A929BL,0x05E1541BL}},{{(-1L),0xEBCBB2E6L,0xD4EDE40DL,(-8L),(-8L)},{5L,1L,5L,(-4L),0x141ABB78L},{0x4F8FF695L,0x2F4D056CL,9L,0x9C7A75D8L,0x8ED2113AL},{0xD31BC39FL,(-10L),1L,1L,(-1L)},{(-1L),0x3F2DF9F6L,9L,0x8ED2113AL,0x2F4D056CL}},{{0L,(-9L),5L,(-9L),0L},{0xA9C5A221L,(-1L),0xD4EDE40DL,(-7L),0x6B855A03L},{(-3L),4L,0xD31BC39FL,1L,0xC0723F86L},{(-8L),9L,0xF2DC1619L,(-1L),0x6B855A03L},{4L,1L,0L,(-4L),0L}},{{0x6B855A03L,0x6B855A03L,0x3F2DF9F6L,(-9L),0x2F4D056CL},{0x80113FBEL,6L,(-3L),0xEF9A929BL,(-1L)},{(-8L),(-1L),(-9L),0xE58FA5B4L,0x8ED2113AL},{(-7L),6L,4L,4L,0x141ABB78L},{0xA9C5A221L,0x6B855A03L,0xC4371B6FL,0x3F2DF9F6L,(-8L)}}};
        int32_t l_2295 = 0xA7522FCFL;
        uint16_t l_2386[5] = {0xA842L,0xA842L,0xA842L,0xA842L,0xA842L};
        uint8_t l_2387 = 0xC5L;
        uint8_t l_2566[3][1];
        int16_t l_2600 = 0x9347L;
        uint16_t l_2619[2];
        int i, j, k;
        for (i = 0; i < 2; i++)
            l_2291[i] = 0x4E538020L;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 1; j++)
                l_2566[i][j] = 1UL;
        }
        for (i = 0; i < 2; i++)
            l_2619[i] = 65535UL;
        l_2296 = (l_2266[2] = (l_2295 = (((safe_sub_func_uint32_t_u_u((!(safe_sub_func_int16_t_s_s((g_543[1] = (safe_add_func_int32_t_s_s((safe_rshift_func_uint8_t_u_u(0x89L, 6)), ((safe_mod_func_int16_t_s_s((g_172[8] >= 0x22C8L), (g_538 = l_5[5][1]))) || (l_2279 | (((safe_mod_func_uint32_t_u_u((~(l_2293[5][4][4] = (safe_sub_func_int32_t_s_s(((g_538 = (safe_lshift_func_uint16_t_u_s(((~l_2266[4]) < (((l_2291[0] = (0x405BL < (((l_2290 = (safe_add_func_uint16_t_u_u((g_538 = (l_5[1][6] == 0x41L)), g_161))) | l_2266[3]) >= g_2177[1][3][4]))) ^ 0x136C721FL) | g_161)), 2))) > l_2292), g_1460)))), l_2266[1])) ^ 0xBD41L) | 0xAFB6L)))))), l_2294))), l_5[4][0])) >= 1L) <= l_2279)));
        for (g_361 = 2; (g_361 >= 0); g_361 -= 1)
        {
            uint32_t l_2314 = 0xBB7DC9F1L;
            int32_t l_2326 = 0x3AB3E32BL;
            int8_t l_2328[1];
            int i;
            for (i = 0; i < 1; i++)
                l_2328[i] = 0L;
            for (l_201 = 0; (l_201 <= 2); l_201 += 1)
            {
                int16_t l_2315 = 0xC65AL;
                uint16_t l_2327 = 65533UL;
                uint8_t l_2343[5] = {3UL,3UL,3UL,3UL,3UL};
                int i;
                for (l_2295 = 0; (l_2295 <= 2); l_2295 += 1)
                {
                    int i, j, k;
                    g_247 = (((safe_lshift_func_uint16_t_u_s((g_538 = (~(g_217 = (safe_add_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u(((safe_add_func_uint32_t_u_u(((((safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((safe_add_func_uint16_t_u_u(((((((safe_sub_func_int16_t_s_s((g_949[l_2295][(l_2295 + 3)][(g_361 + 5)] & g_949[l_2295][(g_361 + 4)][(g_361 + 2)]), l_2314)) == ((((g_172[4] = (g_949[l_2295][(l_2295 + 3)][(g_361 + 5)] ^ (l_2315 == (safe_lshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(0L, 9)), 13))))) | ((safe_sub_func_uint32_t_u_u(((((safe_rshift_func_uint16_t_u_s(g_949[l_2295][(g_361 + 4)][(g_361 + 2)], ((safe_rshift_func_uint16_t_u_s((0x65F9L > 0x8304L), 8)) & 6L))) & 0UL) && 0L) != l_5[1][6]), i)) <= 0UL)) & (-2L)) != g_949[l_2295][(g_361 + 4)][(g_361 + 2)])) & g_103) & l_2291[0]) ^ 1UL) > 0x97A6L), g_538)), l_2326)), g_949[l_2295][(g_361 + 4)][(g_361 + 2)])) == l_2327) || g_2177[2][1][9]) && g_538), (-4L))) >= 0x5E9A852FL), l_2328[0])) == g_361), l_2314))))), g_1215[4])) >= 4294967286UL) && 0x397E8B8CL);
                    for (g_1460 = 20; (g_1460 != 28); g_1460++)
                    {
                        int16_t l_2333 = 0x031BL;
                        l_2291[1] = 1L;
                        if (l_2291[0])
                            break;
                        g_247 = (safe_mod_func_uint32_t_u_u((5L || (l_2326 = (((l_2333 < ((((g_1460 = ((((-6L) == ((g_361 = (safe_add_func_int32_t_s_s((0L <= (g_361 && (safe_unary_minus_func_int8_t_s((((((((safe_add_func_uint16_t_u_u((1UL >= (safe_add_func_int8_t_s_s(0x1DL, (safe_add_func_uint32_t_u_u(((g_949[l_2295][(g_361 + 4)][(g_361 + 2)] > 0xC1A8C29BL) >= l_2295), l_2328[0]))))), 8UL)) == g_247) < g_161) == g_1129) & l_2343[4]) && l_2315) <= l_2292))))), g_866[7][5]))) & 1UL)) | l_2327) & g_538)) & g_538) != l_2333) || l_2333)) & l_2294) && g_949[0][6][3]))), 6L));
                    }
                    g_247 = l_201;
                }
                if (g_813[1][0])
                    continue;
                g_247 = (safe_rshift_func_int16_t_s_u(((l_2315 & (safe_lshift_func_uint16_t_u_u((((l_2326 = (g_188 ^ (g_361 = (safe_add_func_uint8_t_u_u((((((0xE5L >= (((((l_145 = (safe_mod_func_int8_t_s_s((g_2420 = (g_2352[2] || 4UL)), g_866[4][0]))) && 0xB2182F1EL) && (l_5[1][6] ^ (safe_lshift_func_uint8_t_u_s(((safe_add_func_uint16_t_u_u(((+g_1460) != l_2292), g_543[1])) && (-1L)), 7)))) < 0xB49FL) > 0x7963L)) >= l_2314) >= 2L) >= l_2291[1]) && (-1L)), g_1129))))) | l_2327) < g_813[5][0]), g_1460))) < l_2314), 12));
            }
            return g_1460;
        }
        if (((((safe_lshift_func_int16_t_s_u(((((safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s((g_3258 & (((safe_sub_func_uint8_t_u_u(((g_161 < (((safe_add_func_int16_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_u(0xB2C7L, (((safe_sub_func_uint8_t_u_u(((safe_unary_minus_func_uint16_t_u((l_2293[8][3][1] = 0x0192L))) || (g_247 = (((-1L) < g_543[1]) || (l_2266[3] = (safe_add_func_int16_t_s_s((safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(l_2293[5][1][3], (+(((g_538 = (safe_rshift_func_uint16_t_u_s(((g_2177[1][3][2] >= (safe_mod_func_int8_t_s_s(g_2352[4], g_1460))) != 5L), 0))) < l_2296) != g_1215[2])))), 8L)), g_2177[3][1][9])))))), l_5[1][6])) || l_2295) == l_2291[0]))), l_2291[0])), g_359[9][0])) & l_2386[4]) < 1UL)) | l_2295), 0x6BL)) != 0UL) >= l_5[1][6])), g_949[0][6][1])), 0x5BL)) || g_866[4][0]) < g_866[6][2]) || l_2266[3]), l_2387)) > 0xCA700566L) >= g_813[1][0]) || g_538))
        {
            uint8_t l_2432 = 0x5EL;
            int8_t l_2575 = 0L;
            int32_t l_2584 = 0x0CC4751DL;
            int32_t l_2585[3];
            int8_t l_2620 = 0x0FL;
            int i;
            for (i = 0; i < 3; i++)
                l_2585[i] = 0xAFFA580CL;
            for (l_2279 = 0; (l_2279 == 40); ++l_2279)
            {
                uint16_t l_2390 = 0x77A9L;
                uint32_t l_2419 = 1UL;
                int32_t l_2421 = 0x4F3857AAL;
                uint32_t l_2422 = 0x8A7A8A37L;
                int32_t l_2431 = (-10L);
                int8_t l_2475 = 0x84L;
                l_2390 = (g_247 = g_161);
                l_2422 = (((safe_lshift_func_uint16_t_u_s((safe_mod_func_uint32_t_u_u(((0x64L > ((~(safe_sub_func_uint32_t_u_u((safe_add_func_int32_t_s_s(g_1129, ((safe_sub_func_int16_t_s_s((l_2296 = (safe_lshift_func_uint8_t_u_s((g_161 < 0xD1A6L), 3))), (g_543[1] = l_2293[5][4][4]))) == (l_2421 = (((((((safe_lshift_func_uint8_t_u_u(l_2408[3][0], (safe_rshift_func_uint16_t_u_u((0x71C3L & (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_uint16_t_u((l_2419 = (safe_lshift_func_int8_t_s_s(((g_1460 = (safe_rshift_func_int8_t_s_s((g_1215[0] && l_2418[5][4]), 5))) == l_2390), 2))))), g_2420))), 2)))) <= 0L) || l_2279) | l_2292) && 4L) != g_949[0][6][1]) ^ l_2390))))), (-3L)))) == 0x9FC9L)) && 0x36A7L), l_2386[4])), 8)) != g_2420) <= 0x9B065C80L);
                l_2293[5][4][4] = (((((((safe_lshift_func_int8_t_s_u((((((((((g_1460 == l_2293[5][4][4]) ^ (((g_538 = 0xDFFFL) | (g_315 = 0x34B8L)) && (safe_lshift_func_int16_t_s_s((((safe_sub_func_int32_t_s_s((g_247 = ((l_2421 = 0UL) | ((((l_2291[0] > (safe_sub_func_uint8_t_u_u(l_2431, (l_2295 = l_2432)))) < 0x06L) != g_949[0][6][1]) && l_2431))), 0x134D74CCL)) <= (-10L)) < g_538), 7)))) > 0x9248DD31L) == l_201) == 0UL) < g_1460) == l_2408[3][0]) <= 0x7CL) | l_2431), l_5[1][6])) && 0x07L) | g_866[4][0]) & 0xE8L) <= g_866[7][7]) < g_813[1][0]) != l_2432);
                for (l_2432 = 0; (l_2432 <= 3); l_2432 += 1)
                {
                    uint32_t l_2437 = 8UL;
                    int32_t l_2466 = 0x1A5DEB5BL;
                    uint32_t l_2474[3][4][7] = {{{18446744073709551611UL,18446744073709551609UL,0xDE198DD4L,0UL,0UL,0UL,0xDE198DD4L},{0x582432FAL,0x582432FAL,18446744073709551615UL,0x20D3A748L,1UL,0x5B92F6A6L,1UL},{0x3B7A71C4L,0xBB8986F1L,0xFCA41817L,0xC54627FCL,0xC54627FCL,0xFCA41817L,0xBB8986F1L},{1UL,18446744073709551615UL,0x582432FAL,1UL,1UL,0x688D7EE0L,0x20D3A748L}},{{0xFCA41817L,18446744073709551611UL,0UL,0xBB8986F1L,0UL,18446744073709551611UL,0xFCA41817L},{0x20D3A748L,0x688D7EE0L,1UL,1UL,0x582432FAL,18446744073709551615UL,1UL},{0xBB8986F1L,0xFCA41817L,0xC54627FCL,0xC54627FCL,0xFCA41817L,0xBB8986F1L,0x3B7A71C4L},{1UL,0x5B92F6A6L,1UL,0x20D3A748L,18446744073709551615UL,0x582432FAL,0x582432FAL}},{{0xDE198DD4L,0UL,0UL,0UL,0xDE198DD4L,18446744073709551615UL,0x3B7A71C4L},{1UL,1UL,18446744073709551615UL,18446744073709551615UL,0x5B92F6A6L,0x20D3A748L,0x5B92F6A6L},{0xBB8986F1L,1UL,1UL,0xBB8986F1L,18446744073709551611UL,18446744073709551609UL,0xDE198DD4L},{1UL,18446744073709551615UL,1UL,0x582432FAL,18446744073709551608UL,18446744073709551608UL,0x582432FAL}}};
                    int i, j, k;
                    l_268 = (safe_mod_func_int8_t_s_s(((((g_866[(l_2432 + 4)][(l_2432 + 1)] && g_2352[(l_2432 + 5)]) > (g_361 < 0L)) && ((safe_sub_func_int32_t_s_s((0xE897L >= l_2437), (0UL ^ 0x39L))) <= (safe_add_func_uint16_t_u_u((g_161 < g_161), 0x403CL)))) & 0x0DF0L), l_2386[4]));
                    l_268 = ((g_813[5][0] = ((safe_lshift_func_uint16_t_u_s(g_1460, 5)) && 0x9FL)) <= (((safe_add_func_int32_t_s_s((safe_sub_func_uint8_t_u_u(g_172[5], (safe_rshift_func_uint16_t_u_u((((g_1460 = (l_145 && (safe_rshift_func_int8_t_s_s((((safe_sub_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(((safe_sub_func_int32_t_s_s(g_1460, ((((safe_sub_func_uint32_t_u_u((~g_315), (g_247 = (l_2432 < g_2352[(l_2432 + 5)])))) && l_145) || l_268) || g_866[(l_2432 + 4)][(l_2432 + 1)]))) == l_2465), g_543[1])), l_2432)), 3)), 5)) != g_949[0][6][4]), l_2292)) > l_2421) < g_217), i)))) > l_2296) >= 0xC1L), 9)))), l_2293[5][4][4])) > l_2437) || 0x1B16L));
                    if (g_359[9][0])
                        break;
                    for (g_538 = 0; (g_538 <= 3); g_538 += 1)
                    {
                        int32_t l_2473 = (-1L);
                        int i, j, k;
                        l_2466 = 0x839C60E3L;
                        g_115 = (((g_2177[(g_538 + 2)][l_2432][(g_538 + 5)] && (((safe_rshift_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u(g_2177[(l_2432 + 1)][g_538][(l_2432 + 5)], 14)), (safe_mod_func_uint16_t_u_u(g_361, g_103)))) <= ((l_2473 = (g_247 = l_2390)) != (l_268 = (0x43DA57DBL | g_3258)))) < (g_217 < l_2474[0][1][4]))) || g_543[2]) || l_2475);
                    }
                }
            }
            for (i = (-19); (i < (-22)); i = safe_sub_func_uint16_t_u_u(i, 7))
            {
                uint8_t l_2479 = 1UL;
                int8_t l_2495 = 0xB0L;
                int32_t l_2513 = 0xA6921076L;
                int32_t l_2547 = 0x6B1B6203L;
                uint8_t l_2563[7] = {0xB3L,0xB3L,0x5EL,0xB3L,0xB3L,0x5EL,0xB3L};
                int i;
                if (l_2479)
                {
                    int16_t l_2490 = 0L;
                    int32_t l_2504 = (-8L);
                    for (g_538 = (-1); (g_538 == 46); g_538 = safe_add_func_int32_t_s_s(g_538, 5))
                    {
                        int16_t l_2482 = 0xC29FL;
                        l_2295 = (l_2482 >= (safe_add_func_uint16_t_u_u((g_247 == g_1460), 0x0D89L)));
                        l_2293[5][4][4] = l_201;
                    }
                    l_2295 = ((l_2296 = ((((g_361 = ((+g_1129) & ((safe_sub_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u(g_1460, (((g_538 = l_5[0][0]) | ((g_361 <= 0x4CL) || ((l_2490 || (safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(l_2495, g_361)), 3))) >= g_359[6][6]))) ^ 2UL))), l_2495)) ^ 0L))) < 0x23L) & l_2495) && 0x9BA8983EL)) >= 65527UL);
                    l_2408[3][0] = (((l_145 = (g_1460 >= g_949[0][5][6])) == ((safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s((g_2177[4][1][4] = ((g_172[7] == ((l_2266[0] = (safe_add_func_int32_t_s_s(((l_2504 = l_2495) >= ((safe_mod_func_uint8_t_u_u((l_2490 | ((l_2296 = ((0L || (l_2513 = ((l_2490 ^ (safe_add_func_int32_t_s_s((safe_add_func_int8_t_s_s(1L, g_538)), l_2490))) | l_2432))) >= g_361)) < 65535UL)), g_115)) && 252UL)), g_538))) <= g_315)) | (-10L))), 6)), l_2479)) && (-1L))) ^ (-8L));
                    l_2291[0] = g_361;
                }
                else
                {
                    uint32_t l_2525 = 0xDBD6AC3EL;
                    int32_t l_2528 = 0xF6619A70L;
                    for (g_3258 = 0; (g_3258 <= 5); g_3258 += 1)
                    {
                        int32_t l_2527 = 0L;
                        int i, j;
                        g_247 = ((safe_rshift_func_uint8_t_u_u((l_2528 = ((l_5[g_3258][g_3258] = (safe_unary_minus_func_uint16_t_u(0x2292L))) ^ (l_2293[5][4][4] = (((-7L) < ((safe_lshift_func_uint8_t_u_u((0xE68EF4FBL < ((safe_add_func_int8_t_s_s((l_2291[0] = ((safe_add_func_uint32_t_u_u((g_2420 != (safe_add_func_int16_t_s_s((((65531UL > ((l_2525 || g_2420) & g_949[1][7][7])) || (((l_2526 = ((l_2525 > g_172[4]) & 0x1B0088F1L)) ^ l_2479) & l_2479)) && 0x82L), 0x2333L))), g_1460)) || g_217)), g_1460)) ^ 4294967295UL)), 1)) == 5L)) == l_2527)))), 0)) >= 255UL);
                        g_247 = (safe_lshift_func_uint16_t_u_u(1UL, (safe_lshift_func_uint16_t_u_s(((((((safe_rshift_func_uint8_t_u_s(((((g_361 = l_2432) <= (0UL ^ (safe_mod_func_int8_t_s_s(((safe_sub_func_int32_t_s_s(l_2295, g_543[2])) ^ ((l_2418[0][3] <= l_2292) != (safe_sub_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(((g_2177[3][1][9] = l_2386[4]) <= (safe_mod_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(g_543[1], g_2420)), l_2513))), l_2528)), l_2432)))), l_2387)))) <= 0x476CB2BEL) <= l_5[g_3258][(g_3258 + 1)]), 5)) == l_2547) ^ 0x6F1AL) & g_103) | 0x2AL) | g_172[2]), g_115))));
                        g_247 = (l_268 = ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_u(((0xFFL <= 0x8EL) && (g_813[0][0] <= (-1L))), 0)), 0x2FL)) | (0x30L & (((safe_add_func_int16_t_s_s((0x0450E2D6L <= l_2432), (g_1460 < g_949[0][6][1]))) || 0x6291L) > 0x03C1L))));
                        l_2527 = (l_2290 = 0x5A0AF0AFL);
                    }
                    g_115 = 1L;
                    if ((safe_lshift_func_int8_t_s_s((+((safe_rshift_func_uint8_t_u_s((safe_mod_func_uint32_t_u_u(((safe_rshift_func_uint16_t_u_s((l_2266[3] < l_2563[0]), (safe_mod_func_uint16_t_u_u(l_2566[2][0], ((safe_mod_func_uint32_t_u_u(0xB86569AAL, (safe_sub_func_int8_t_s_s((l_2525 & (safe_sub_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(l_2575, j)), ((l_268 = l_5[1][6]) && ((((l_2547 = (safe_rshift_func_uint8_t_u_s((((g_538 = g_1460) == l_2547) || (-1L)), 5))) && 0x8CF5425BL) > g_2420) ^ g_161))))), 0x41L)))) & 0xFF38L))))) != l_2563[0]), 1UL)), l_2575)) && 9UL)), 1)))
                    {
                        l_2585[1] = (+(0x39E1L | (safe_lshift_func_int16_t_s_s((g_866[7][8] = ((65535UL & 0x0AC2L) <= 0xB3EAL)), ((l_201 = l_201) >= (l_2295 = (g_543[2] = (((l_2575 < (((safe_sub_func_uint16_t_u_u(l_2525, (g_2177[3][1][9] != (l_2584 = (l_2292 && g_1129))))) & 0xD04E619AL) <= g_315)) == g_543[1]) >= l_2575))))))));
                        l_268 = g_1460;
                    }
                    else
                    {
                        uint32_t l_2599 = 0x7CDA3D77L;
                        int32_t l_2616 = (-4L);
                        j = ((1L == l_2525) != (safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(((-3L) != ((safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_s(((((((((l_2386[4] >= (g_813[1][0] < (g_115 = (((0xFFL | g_949[0][6][1]) == (((safe_add_func_uint32_t_u_u((l_2563[0] || l_2292), g_103)) >= l_2585[2]) || l_2525)) < 0x66L)))) ^ l_2599) || g_3258) >= l_2600) >= l_2528) != 6L) <= g_315) >= l_2599), l_2528)), 0x61L)) ^ g_949[2][8][6])), g_543[1])), (-4L))));
                        l_2585[2] = ((l_2601 < (safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((l_2616 = ((safe_lshift_func_uint16_t_u_s(l_2266[0], 6)) ^ ((+(l_2547 = g_949[0][6][1])) && (l_2584 != (safe_sub_func_uint16_t_u_u(((l_2408[2][4] = 6L) ^ (safe_mod_func_int32_t_s_s(g_1460, g_172[4]))), (+((-1L) && (safe_lshift_func_uint8_t_u_u(g_115, g_3258)))))))))), 0)), 11))) <= l_2387);
                        g_247 = g_1460;
                    }
                    g_247 = (safe_mod_func_uint32_t_u_u(l_2619[1], ((((j < l_145) || l_2620) == ((((safe_sub_func_int16_t_s_s(((g_2177[3][1][9] = l_2547) | (l_2418[2][1] < (+(0xC4FEL ^ (safe_rshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s((((l_2528 > (-1L)) | (-1L)) > g_1460), g_359[4][0])), 2UL)), 7)))))), i)) > l_2266[4]) <= 2UL) < l_2525)) ^ (-6L))));
                }
            }
            l_2290 = (safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u(((safe_mod_func_uint32_t_u_u((((l_2408[3][0] = g_115) <= ((g_359[9][0] & (safe_rshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((g_359[6][6] && (safe_mod_func_uint8_t_u_u(((((safe_rshift_func_uint8_t_u_s(((safe_sub_func_int8_t_s_s((l_201 & (g_217 = (safe_sub_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((((~0x448CL) ^ (safe_lshift_func_int8_t_s_s(((g_172[4] = g_2352[7]) | ((safe_lshift_func_uint16_t_u_s(0xEFAAL, 7)) < 6UL)), 7))) < (1L > g_813[1][0])), g_538)), l_2293[5][4][4])))), 255UL)) ^ g_2177[3][1][9]), l_2294)) || 1UL) != g_188) < l_2600), (-1L)))), g_247)), 6))) | g_3258)) < 4294967295UL), g_2420)) || l_2620), 1)), 7));
            for (g_538 = 0; g_538 < 3; g_538 += 1)
            {
                for (l_268 = 0; l_268 < 9; l_268 += 1)
                {
                    for (g_361 = 0; g_361 < 9; g_361 += 1)
                    {
                        g_949[g_538][l_268][g_361] = 0L;
                    }
                }
            }
        }
        else
        {
            int16_t l_2673 = (-1L);
            int32_t l_2704 = (-1L);
            if ((safe_lshift_func_uint16_t_u_s(0xCDD4L, l_5[5][4])))
            {
                int8_t l_2662[2];
                int32_t l_2672 = 0x458B65B5L;
                int32_t l_2691[7][4] = {{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)},{0xA7CC0C33L,(-1L),0xA7CC0C33L,0xA7CC0C33L},{(-1L),(-1L),0xB115895CL,(-1L)},{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)},{0xA7CC0C33L,(-1L),0xA7CC0C33L,0xA7CC0C33L},{(-1L),(-1L),0xB115895CL,(-1L)},{(-1L),0xA7CC0C33L,0xA7CC0C33L,(-1L)}};
                uint8_t l_2701 = 0x03L;
                int i, j;
                for (i = 0; i < 2; i++)
                    l_2662[i] = (-6L);
                l_268 = (((l_2290 = (l_2295 = (g_2420 = ((l_268 < ((safe_add_func_int32_t_s_s(g_949[0][6][1], ((+((safe_lshift_func_uint16_t_u_u((((g_361 = ((g_247 = ((l_2662[0] < (((((safe_lshift_func_int16_t_s_u(((safe_add_func_int16_t_s_s((((safe_lshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u(65535UL, (~(((l_2662[1] >= g_3258) >= 9L) && g_2177[5][0][0])))), 5)) >= g_359[6][0]) >= l_2619[1]), l_2662[0])) ^ 0x2BBDAAFAL), g_813[5][0])) ^ l_2672) | 250UL) & (-8L)) != g_361)) == g_949[2][0][1])) ^ 0x0227889AL)) <= (-9L)) >= l_2673), g_2177[4][1][5])) && l_268)) < 0x41L))) & g_813[1][0])) == 0x5FL)))) != g_543[2]) > g_161);
                for (g_1460 = 0; (g_1460 <= 6); g_1460 += 1)
                {
                    l_2674 = 0L;
                    for (l_2465 = 0; (l_2465 <= 6); l_2465 += 1)
                    {
                        int32_t l_2677[7][8][4] = {{{1L,0x41A054B2L,0L,0x2D0DBF52L},{0x0CF1A441L,0L,(-5L),(-1L)},{(-4L),0L,0x731C9F43L,0x01A3D290L},{0L,(-10L),0x0D46BF51L,0x0D46BF51L},{3L,3L,0x4CB0245BL,0x60E2D043L},{0x0D46BF51L,0L,0xCE5C71E8L,0xD450BA5CL},{1L,0xBBB0E83CL,(-1L),0xCE5C71E8L},{0xBC9F03A0L,0xBBB0E83CL,(-10L),0xD450BA5CL}},{{0xBBB0E83CL,0L,(-1L),0x60E2D043L},{1L,3L,0xBC9F03A0L,0x0D46BF51L},{0x731C9F43L,(-10L),(-9L),0x01A3D290L},{0x4CB0245BL,0L,0x7AE1F11BL,(-1L)},{0xB8ACCB37L,0L,1L,0x2D0DBF52L},{0x60E2D043L,0x41A054B2L,0x830FB6EAL,(-4L)},{0L,(-1L),0L,2L},{(-9L),0L,3L,(-10L)}},{{0L,0x2D0DBF52L,0L,0L},{0x41A054B2L,0x8FB9928BL,0L,0x0CF1A441L},{0L,0x731C9F43L,3L,0x7AE1F11BL},{(-9L),0L,0L,(-3L)},{0L,(-3L),0x830FB6EAL,0L},{0x60E2D043L,(-9L),1L,0L},{0xB8ACCB37L,(-1L),0x7AE1F11BL,0xA2CE5981L},{0x4CB0245BL,0xB8ACCB37L,(-9L),(-1L)}},{{0x731C9F43L,0xBC9F03A0L,0xBC9F03A0L,0x731C9F43L},{1L,0xD450BA5CL,(-1L),(-9L)},{0xBBB0E83CL,0x0CF1A441L,(-10L),1L},{0xBC9F03A0L,0L,(-1L),1L},{1L,0x0CF1A441L,0xCE5C71E8L,(-9L)},{0x0D46BF51L,0xD450BA5CL,0x4CB0245BL,0x731C9F43L},{3L,0xBC9F03A0L,0x0D46BF51L,(-1L)},{0L,0xB8ACCB37L,0x731C9F43L,0xA2CE5981L}},{{(-4L),(-1L),(-5L),0L},{0x0CF1A441L,2L,0L,(-1L)},{0x7AE1F11BL,0x2D0DBF52L,0xCE5C71E8L,0x2D0DBF52L},{0x8FB9928BL,0xA2CE5981L,0x2D0DBF52L,1L},{1L,1L,(-9L),0x41A054B2L},{0x0D46BF51L,(-3L),0L,(-4L)},{0x0D46BF51L,(-5L),(-9L),0L},{1L,(-4L),0x2D0DBF52L,0xB8ACCB37L}},{{0x8FB9928BL,(-9L),0xCE5C71E8L,0x0CF1A441L},{0x7AE1F11BL,(-1L),0L,(-5L)},{0x41A054B2L,0L,0x01A3D290L,0x8FB9928BL},{0x0CF1A441L,0L,1L,0xBC9F03A0L},{0xA2CE5981L,0L,(-10L),(-10L)},{0x4CB0245BL,0x4CB0245BL,9L,1L},{(-10L),0L,1L,0L},{0L,0L,0x0D46BF51L,1L}},{{0x731C9F43L,0L,0L,0L},{0L,0L,1L,1L},{0xD450BA5CL,0x4CB0245BL,0x731C9F43L,(-10L)},{1L,0L,2L,0xBC9F03A0L},{9L,0L,1L,0x8FB9928BL},{0x830FB6EAL,0L,0xD450BA5CL,(-5L)},{1L,(-1L),3L,0x0CF1A441L},{0xBBB0E83CL,(-9L),0xBBB0E83CL,0xB8ACCB37L}}};
                        int i, j, k;
                        l_2677[4][2][3] = (safe_unary_minus_func_int16_t_s((safe_unary_minus_func_int8_t_s((g_359[(g_1460 + 1)][l_2465] > l_2673)))));
                    }
                }
                if (((l_2295 = (((l_2291[1] = g_172[1]) && (safe_sub_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_u((((g_217 = (g_2177[0][0][9] = ((g_361 > j) & (((safe_mod_func_int32_t_s_s((((((((((safe_lshift_func_int8_t_s_u((g_2420 = (((safe_add_func_uint8_t_u_u(l_2662[1], ((-1L) <= l_2673))) != ((((safe_sub_func_int32_t_s_s((!g_188), ((l_2691[0][0] = (l_2408[3][0] = ((0xB248A39EL & ((l_201 = (-2L)) < g_247)) >= l_2662[1]))) && l_2673))) && g_866[4][0]) && l_2691[0][2]) > l_2673)) & 0L)), g_1460)) <= g_866[4][0]) == l_2673) | g_1460) && g_2177[3][3][8]) <= l_2692) ^ l_2673) != g_1460) ^ 0xECF0AEBAL), 0xCF415C16L)) > g_543[1]) == l_2673)))) < l_2291[0]) & l_2266[3]), l_2465)) && (-4L)), g_359[1][6]))) == 0xBF9AL)) > 0xEE49L))
                {
                    int32_t l_2700 = (-6L);
                    j = 1L;
                    j = (((0xB2637E3CL != (~((safe_add_func_int8_t_s_s((l_2691[0][0] = l_2296), (l_2704 = (g_217 = (((-3L) ^ (l_2701 = (l_2700 = (safe_mod_func_uint8_t_u_u(0xD2L, 5UL))))) ^ (g_172[1] == ((safe_sub_func_int16_t_s_s(((g_543[1] = (l_2704 & ((!(safe_mod_func_uint16_t_u_u(((safe_sub_func_uint32_t_u_u(l_2601, 0x8C7F0823L)) == g_538), l_2672))) >= 0UL))) > 0xA047L), l_2672)) >= g_1460))))))) && l_2704))) <= l_2673) > 0L);
                    l_2704 = (249UL & ((safe_lshift_func_int16_t_s_u(g_1460, 6)) && 1UL));
                }
                else
                {
                    int32_t l_2715 = 0x20D70AE1L;
                    int32_t l_2723 = 0x493688ADL;
                    for (g_315 = 0; (g_315 > 25); g_315++)
                    {
                        uint16_t l_2724 = 65535UL;
                        l_2704 = ((((((p_50 = l_2715) & ((4UL == l_2408[3][2]) <= (safe_unary_minus_func_uint32_t_u(((safe_add_func_int8_t_s_s((safe_add_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(g_1129, 14)), ((l_2723 = 0xEEF6D83EL) > g_3258))), 0x16L)) && l_145))))) >= ((l_2691[3][1] = 65535UL) > l_2724)) && g_359[9][6]) || l_2662[0]) > g_315);
                        return i;
                    }
                    l_2295 = (l_2691[0][0] = ((l_2293[5][4][4] = (l_5[4][2] | ((j ^ (((0x3248F897L < ((safe_unary_minus_func_int16_t_s(0xA585L)) ^ (g_361 > g_3258))) < ((0L && (((-10L) < (0x522993A5L < 0x6C6B07C7L)) == l_2408[3][0])) || g_103)) > l_2296)) > 0x637DBBF8L))) && g_161));
                    g_115 = (safe_unary_minus_func_int8_t_s((g_361 = ((safe_rshift_func_uint16_t_u_u(1UL, 7)) < (g_2420 || g_161)))));
                    for (g_361 = 0; (g_361 <= (-25)); g_361--)
                    {
                        j = g_315;
                        return g_949[0][6][1];
                    }
                }
            }
            else
            {
                l_2408[0][5] = l_2619[1];
                j = (((((((safe_rshift_func_uint8_t_u_s((g_2177[3][1][9] = ((safe_add_func_uint8_t_u_u((safe_add_func_int32_t_s_s(l_2600, (l_2408[0][0] = (safe_add_func_uint8_t_u_u((g_1460 = (g_247 < (g_172[4] != 0xD4L))), 1L))))), ((l_2673 == i) < (g_1129 < l_2619[1])))) < g_1215[1])), 7)) <= g_103) ^ 0xC9C7L) && 1UL) || g_1460) | g_1129) != l_2673);
            }
        }
        return g_315;
    }
    else
    {
        uint32_t l_2750 = 0UL;
        int16_t l_2774 = 0x1B44L;
        uint32_t l_2816 = 8UL;
        uint16_t l_2838 = 0x80C3L;
        uint32_t l_2839[4][5][4] = {{{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL}},{{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL}},{{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL}},{{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL},{0xDB032C1FL,0xDB032C1FL,0xDB032C1FL,0xDB032C1FL}}};
        int32_t l_2840 = (-1L);
        uint32_t l_2842 = 4294967293UL;
        uint32_t l_2858 = 6UL;
        int32_t l_2886[5] = {0x58E56A96L,0x58E56A96L,0x58E56A96L,0x58E56A96L,0x58E56A96L};
        uint8_t l_2918 = 251UL;
        uint32_t l_3026 = 0xD83BFFE3L;
        uint16_t l_3036[9][4][6] = {{{0x87ECL,6UL,0x87ECL,7UL,0UL,0x77DEL},{0x87ECL,0xE62AL,65535UL,0x2B5DL,65528UL,1UL},{0x707AL,65535UL,0x663BL,0x95CBL,0x87ECL,0x3B74L},{1UL,0xF5FBL,0xAEF8L,0x3B74L,65535UL,65534UL}},{{1UL,0x7B76L,0x0A26L,0x95CBL,65535UL,65528UL},{0xAEF8L,2UL,1UL,0x95CBL,0xFE06L,0UL},{1UL,0x7098L,0x6C25L,0x3B74L,0x663BL,0x69E2L},{1UL,7UL,0x2A82L,0x95CBL,0xD05AL,0x7629L}},{{0xAEF8L,1UL,0xB2E4L,0x95CBL,0x707AL,0x95CBL},{1UL,0x77DEL,1UL,0x3B74L,0xB77FL,65527UL},{1UL,0x2B5DL,0xBEA0L,0x95CBL,0x8C94L,0xCCFEL},{0xAEF8L,9UL,0xBCF5L,0x95CBL,0x87ECL,0x3B74L}},{{1UL,0xF5FBL,0xAEF8L,0x3B74L,65535UL,65534UL},{1UL,0x7B76L,0x0A26L,0x95CBL,65535UL,65528UL},{0xAEF8L,2UL,1UL,0x95CBL,0xFE06L,0UL},{1UL,0x7098L,0x6C25L,0x3B74L,0x663BL,0x69E2L}},{{1UL,7UL,0x2A82L,0x95CBL,0xD05AL,0x7629L},{0xAEF8L,1UL,0xB2E4L,0x95CBL,0x707AL,0x95CBL},{1UL,0x77DEL,1UL,0x3B74L,0xB77FL,65527UL},{1UL,0x2B5DL,0xBEA0L,0x95CBL,0x8C94L,0xCCFEL}},{{0xAEF8L,9UL,0xBCF5L,0x95CBL,0x87ECL,0x3B74L},{1UL,0xF5FBL,0xAEF8L,0x3B74L,65535UL,65534UL},{1UL,0x7B76L,0x0A26L,0x95CBL,65535UL,65528UL},{0xAEF8L,2UL,1UL,0x95CBL,0xFE06L,0UL}},{{1UL,0x7098L,0x6C25L,0x3B74L,0x663BL,0x69E2L},{1UL,7UL,0x2A82L,0x95CBL,0xD05AL,0x7629L},{0xAEF8L,1UL,0xB2E4L,0x95CBL,0x707AL,0x95CBL},{1UL,0x77DEL,1UL,0x3B74L,0xB77FL,65527UL}},{{1UL,0x2B5DL,0xBEA0L,0x95CBL,0x8C94L,0xCCFEL},{0xAEF8L,9UL,0xBCF5L,0x95CBL,0x87ECL,0x3B74L},{1UL,0xF5FBL,0xAEF8L,0x3B74L,65535UL,65534UL},{1UL,0x7B76L,0x0A26L,0x95CBL,65535UL,65528UL}},{{0xAEF8L,2UL,1UL,0x95CBL,0xFE06L,0UL},{1UL,0x7098L,0x6C25L,0x3B74L,0x663BL,0x69E2L},{1UL,0x3B74L,0UL,6UL,0x2A82L,0x0DFFL},{0x2848L,0xCCFEL,1UL,6UL,0xAEF8L,6UL}}};
        uint32_t l_3109 = 0x4E3D05E3L;
        uint8_t l_3153 = 0xD3L;
        int i, j, k;
        for (p_50 = 0; (p_50 <= 5); p_50 += 1)
        {
            int16_t l_2741[4] = {(-1L),(-1L),(-1L),(-1L)};
            int8_t l_2767 = 0L;
            int32_t l_2786 = (-1L);
            uint8_t l_2805 = 0x6BL;
            int i;
            l_2266[3] = (l_2741[1] <= (-1L));
            if (g_1460)
                break;
            if ((((g_315 = ((safe_lshift_func_uint16_t_u_u(((((safe_add_func_int16_t_s_s(g_359[9][0], l_2741[3])) > ((((((safe_mod_func_uint16_t_u_u(((g_866[7][9] = ((((0x6E85L <= (0x42L | l_2741[3])) <= 0x5A05L) || g_172[4]) >= ((safe_add_func_uint16_t_u_u(0UL, (((((((((g_359[9][0] == l_2526) & 1L) | g_813[1][0]) || g_315) >= l_145) == l_2465) ^ g_2420) | 0x22D5438DL) != g_813[1][0]))) > l_2294))) == 0xDB79L), l_2750)) || g_949[2][3][0]) || 0x4AL) && g_949[0][6][1]) | g_2177[3][1][9]) >= 1L)) >= g_2177[1][2][5]) < 0L), 0)) != 0x4DL)) <= 0xF9F6L) && 0x03L))
            {
                int16_t l_2751 = 0x67D2L;
                return l_2751;
            }
            else
            {
                int8_t l_2775 = 0xEAL;
                if (g_103)
                    break;
                for (g_1460 = 0; (g_1460 <= 7); g_1460 += 1)
                {
                    int i, j;
                    g_115 = ((safe_lshift_func_int16_t_s_s(((safe_add_func_int32_t_s_s((j = ((l_2408[2][1] = ((((((safe_lshift_func_uint8_t_u_s((((safe_sub_func_uint32_t_u_u(g_866[g_1460][p_50], (((((l_268 = ((safe_mod_func_uint32_t_u_u((safe_unary_minus_func_uint16_t_u(l_5[p_50][p_50])), (safe_lshift_func_int16_t_s_u((((safe_mod_func_int32_t_s_s(g_1215[4], ((l_2767 ^ g_247) ^ 4L))) ^ ((+((safe_mod_func_uint32_t_u_u((safe_add_func_int8_t_s_s((0L == (+(g_359[5][0] = g_866[g_1460][p_50]))), ((((l_2774 >= l_5[p_50][p_50]) != l_2741[1]) >= g_1460) || g_949[0][6][1]))), 0x60FE58BBL)) | l_2741[1])) & g_2352[2])) & g_538), 5)))) || g_1460)) ^ g_2352[1]) && p_50) > g_1460) ^ g_217))) != l_2292) | l_2526), g_1215[4])) >= l_201) < l_2775) > 0x93B1L) && l_2408[3][0]) >= g_949[0][6][1])) && l_2774)), g_172[8])) && 0L), g_188)) == g_161);
                    for (l_2294 = 0; (l_2294 <= 2); l_2294 += 1)
                    {
                        return l_2775;
                    }
                    for (l_2774 = 2; (l_2774 >= 0); l_2774 -= 1)
                    {
                        if (i)
                            break;
                    }
                }
            }
            for (g_538 = 0; (g_538 <= 5); g_538 += 1)
            {
                uint32_t l_2789 = 0UL;
                int i, j;
                if ((safe_rshift_func_uint16_t_u_u(((((safe_sub_func_uint32_t_u_u(0x0CA3AF23L, ((safe_lshift_func_int16_t_s_s((((0xE3A54803L | (g_866[p_50][(g_538 + 1)] || (0x65L < (safe_add_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_u((((l_2408[3][0] = (l_2786 = 0xAB10L)) < l_5[g_538][(g_538 + 1)]) | l_2741[1]), 8)) | 0xFAL), (((safe_sub_func_uint8_t_u_u(g_2177[3][1][0], g_1460)) <= 3UL) && l_2789)))))) == l_2774) == 4294967294UL), g_1215[4])) ^ l_5[g_538][(g_538 + 1)]))) >= l_2290) || l_5[g_538][(g_538 + 1)]) == l_2790[4][0]), l_2767)))
                {
                    int32_t l_2804 = 0xA0FDC450L;
                    int i, j;
                    j = (safe_lshift_func_uint8_t_u_u(((0x9DL || 0L) >= g_172[4]), ((safe_add_func_int8_t_s_s((((safe_lshift_func_int8_t_s_u(0xF2L, ((g_1460 ^ 65535UL) > (!(l_2408[3][0] = (((g_866[p_50][(p_50 + 4)] = g_1460) == (safe_rshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_u(((l_2741[0] < (safe_sub_func_uint32_t_u_u((g_2352[2] | 0xC0D2L), l_2789))) & g_172[4]), l_2741[1])), l_2804))) != l_5[g_538][(g_538 + 1)])))))) == l_2774) & g_949[0][0][4]), g_188)) & g_543[1])));
                    if (g_103)
                        break;
                    return l_2805;
                }
                else
                {
                    return l_2741[1];
                }
            }
        }
        if ((g_115 = (safe_rshift_func_uint16_t_u_s((l_2408[1][1] = ((4294967295UL && ((safe_mod_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_s(((safe_add_func_int32_t_s_s((safe_add_func_int8_t_s_s((l_2816 != l_2816), (g_361 = (safe_rshift_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_s(g_1460, 11)) > ((safe_add_func_uint16_t_u_u((+(l_2840 = ((safe_add_func_int16_t_s_s((l_2292 > (safe_lshift_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((g_161 = (g_361 | (l_2266[3] = ((safe_mod_func_int32_t_s_s((safe_mod_func_int16_t_s_s(l_2266[3], g_1215[4])), (safe_lshift_func_int16_t_s_u((safe_add_func_int8_t_s_s(((((l_2838 < l_2774) != 0xD9L) || 0UL) != g_543[1]), 0x0DL)), g_161)))) <= g_949[0][6][1])))) ^ l_2816), l_5[2][3])), g_538))), l_2839[3][2][0])) && g_2352[3]))), l_2816)) <= 65535UL)) > 6L), l_2816))))), g_3258)) != g_949[0][6][1]), l_2841)) < g_1129), l_2842)) == 0xC5L)) >= 0xB92611BCL)), 4))))
        {
            uint32_t l_2849 = 0x6555F265L;
            int32_t l_2882 = 0x437FFEACL;
            for (l_2290 = 0; (l_2290 < 14); l_2290 = safe_add_func_int8_t_s_s(l_2290, 9))
            {
                uint8_t l_2857[10] = {0x47L,0x47L,5UL,0x47L,0x47L,5UL,0x47L,0x47L,5UL,0x47L};
                int i;
                g_247 = (safe_sub_func_uint32_t_u_u(((((safe_mod_func_int16_t_s_s(l_2849, l_145)) >= ((safe_mod_func_int16_t_s_s(((((safe_add_func_uint8_t_u_u((((safe_rshift_func_int8_t_s_s(0xEBL, (g_217 & (~((g_2352[2] ^ l_2857[0]) | g_2352[8]))))) > g_1460) ^ 0xB3A2L), 1L)) > l_2816) >= 4UL) <= g_2177[3][1][9]), l_2849)) > (-1L))) & g_1215[4]) & 0x305117E2L), l_2849));
                if (l_2858)
                {
                    uint16_t l_2859[9][10][2] = {{{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L},{0x351AL,0x0962L},{0x63E3L,0x6C7BL}},{{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L},{0x2BD3L,0x351AL},{0x0962L,0x63E3L}},{{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L},{0x351AL,0x0962L}},{{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L},{0x2BD3L,0x351AL}},{{0x0962L,0x63E3L},{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL},{0x2BD3L,0x2BD3L}},{{0x351AL,0x0962L},{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L},{0x351AL,0x2BD3L}},{{0x2BD3L,0x351AL},{0x0962L,0x63E3L},{0x6C7BL,1UL},{0x2BD3L,65535UL},{1UL,0x0962L},{0xBB6AL,0x0962L},{1UL,65535UL},{0x2BD3L,1UL},{0x6C7BL,0x63E3L},{0x0962L,0x351AL}},{{0x2BD3L,0x2BD3L},{0x351AL,0x0962L},{0x63E3L,0x6C7BL},{1UL,0x2BD3L},{65535UL,1UL},{0x0962L,0xBB6AL},{0x0962L,1UL},{65535UL,0x2BD3L},{1UL,0x6C7BL},{0x63E3L,0x0962L}},{{0x351AL,0x2BD3L},{0x2BD3L,0x351AL},{0x0962L,0x63E3L},{0UL,0xBB6AL},{1UL,0x1D2FL},{0xBB6AL,0x351AL},{0x1AC1L,0x351AL},{0xBB6AL,0x1D2FL},{1UL,0xBB6AL},{0UL,0xE5BAL}}};
                    int i, j, k;
                    g_115 = (((l_2859[6][7][1] = 0xADBFA8FFL) >= 0x48712C93L) <= (safe_mod_func_uint16_t_u_u(g_217, 0xF825L)));
                }
                else
                {
                    uint32_t l_2870 = 7UL;
                    int16_t l_2876 = 0x4E7FL;
                    for (g_103 = (-5); (g_103 > 9); g_103 = safe_add_func_uint16_t_u_u(g_103, 3))
                    {
                        int32_t l_2875 = 0x445A8CCEL;
                        l_2840 = ((safe_lshift_func_int8_t_s_s(l_2839[3][2][0], 7)) == (safe_sub_func_uint8_t_u_u(4UL, 0x27L)));
                        g_247 = ((l_2857[8] ^ (safe_add_func_uint16_t_u_u(g_949[0][2][8], l_145))) >= (((((g_1129 = l_2870) > g_2352[0]) < ((safe_sub_func_int8_t_s_s((((((l_2857[6] && (((l_2870 == ((-4L) == (g_359[1][0] = (safe_add_func_uint16_t_u_u((9L & l_2875), l_2838))))) < l_268) != l_2857[0])) <= l_2408[3][0]) <= (-7L)) < g_543[1]) & 0x6FL), l_2526)) <= 0xF0L)) >= g_115) < g_217));
                    }
                    if (l_2876)
                        continue;
                    if (l_2870)
                        continue;
                }
                g_247 = (l_2526 >= (((((((l_2882 = (safe_lshift_func_int8_t_s_u(((~(safe_mod_func_uint8_t_u_u((l_2750 & l_2842), 255UL))) & p_50), l_2674))) && 255UL) || (g_1129 & (g_2420 = (!((safe_mod_func_int8_t_s_s((g_866[4][0] & (-1L)), l_2886[3])) ^ 1UL))))) && (-10L)) | 0x2BL) == 0xDDL) & l_2857[6]));
            }
        }
        else
        {
            uint8_t l_2896 = 0x25L;
            int32_t l_2900[1][7][10] = {{{1L,0x51D4F00DL,(-2L),0x72793645L,(-2L),0x51D4F00DL,1L,0x51D4F00DL,(-2L),0x72793645L},{0xD57951F1L,0x72793645L,0xD57951F1L,0x51D4F00DL,9L,0x51D4F00DL,0xD57951F1L,0x72793645L,0xD57951F1L,0x51D4F00DL},{1L,0x72793645L,0L,0x72793645L,1L,0x4FD08915L,1L,0x72793645L,0L,0x72793645L},{9L,0x51D4F00DL,0xD57951F1L,0x72793645L,0xD57951F1L,0x51D4F00DL,9L,0x51D4F00DL,0xD57951F1L,0x72793645L},{(-2L),0x72793645L,(-2L),0x51D4F00DL,1L,0x51D4F00DL,(-2L),0x72793645L,(-2L),0x51D4F00DL},{9L,0x72793645L,2L,0x72793645L,9L,0x4FD08915L,9L,0x72793645L,2L,0x72793645L},{1L,0x51D4F00DL,(-2L),0x72793645L,(-2L),0x51D4F00DL,1L,0x51D4F00DL,(-2L),0x72793645L}}};
            uint8_t l_2943 = 0x66L;
            uint32_t l_2954 = 4294967292UL;
            int16_t l_2978 = 0L;
            int32_t l_3072 = 1L;
            int i, j, k;
            for (l_2838 = (-17); (l_2838 < 7); ++l_2838)
            {
                int16_t l_2889 = 0x56E2L;
                int32_t l_2901 = 3L;
                if ((l_2889 ^ (safe_lshift_func_int16_t_s_u((g_543[0] = 0xB38AL), (safe_mod_func_int16_t_s_s((((safe_mod_func_int32_t_s_s(((0L < (l_2408[3][0] = (l_2896 != g_2352[2]))) <= 0xF7L), (((((g_188 > ((((((safe_add_func_uint16_t_u_u(((l_2266[0] = (l_2901 = (l_2899 != l_2900[0][1][8]))) != l_2900[0][1][8]), 0x6951L)) >= g_188) && 1L) ^ g_866[0][4]) && g_813[1][0]) | (-8L))) && (-1L)) > 0x6DEFL) != l_2841) | g_359[9][0]))) < l_2896) && l_2465), l_2889))))))
                {
                    return l_2816;
                }
                else
                {
                    uint32_t l_2908 = 4294967295UL;
                    int16_t l_2945 = (-1L);
                    l_2840 = (safe_rshift_func_uint8_t_u_u((0xFDF2L == ((((safe_rshift_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_u((1UL >= ((g_866[4][0] > 0x7AL) == 9UL)), g_1129)) || (l_2908 == ((3UL & (g_359[9][0] != 0L)) && l_2900[0][1][8]))), g_1460)) == l_2418[3][4]) != 4294967295UL) || l_2899)), g_543[1]));
                    if ((((-5L) > (4294967295UL >= ((((safe_add_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s(0xA94EL, ((g_3258 && g_949[0][6][1]) < ((((((safe_rshift_func_uint16_t_u_u((((((0x4CD1L == (((safe_add_func_int32_t_s_s(g_115, (l_2908 > (~(g_2177[3][1][9] ^ l_2908))))) >= l_2889) > 0x64F7L)) > g_161) == g_866[6][0]) != 0L) == l_2839[3][2][0]), 4)) <= l_2900[0][1][8]) <= 0xBEL) ^ g_543[1]) == g_2420) == l_2918)))), g_361)) ^ 0xDC73L) && g_1460) || l_2908))) <= l_145))
                    {
                        uint32_t l_2944 = 0x023CA64AL;
                        if (g_2352[2])
                            break;
                        l_268 = ((safe_lshift_func_int16_t_s_u((safe_mod_func_int16_t_s_s((safe_sub_func_int32_t_s_s((l_2886[3] = ((((safe_sub_func_uint16_t_u_u(((g_813[6][0] = ((g_359[9][0] & (-1L)) ^ l_2601)) < (safe_mod_func_uint16_t_u_u(g_161, g_161))), (safe_add_func_uint32_t_u_u(((safe_rshift_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((((((((0x7C9D89B7L && (safe_add_func_uint16_t_u_u(l_145, (l_2889 != (g_103 = ((((safe_add_func_int8_t_s_s((safe_add_func_uint32_t_u_u(g_538, g_1460)), l_2943)) || l_5[1][6]) && l_2944) != l_2889)))))) & g_115) != l_2266[3]) > l_201) <= g_866[5][7]) > l_2896) || 1L), (-8L))), g_2177[0][2][6])) | 0x50DFL), l_2858)))) <= l_2896) && l_2944) || 0x623CL)), 0x8170AE80L)), g_247)), l_2945)) <= 0x93L);
                    }
                    else
                    {
                        return g_188;
                    }
                    return g_247;
                }
            }
            if ((safe_add_func_uint32_t_u_u((g_359[9][0] = (safe_rshift_func_int8_t_s_s(g_866[7][3], 6))), (l_2266[3] & ((safe_add_func_uint8_t_u_u((l_2290 = (safe_sub_func_uint16_t_u_u(g_2420, (l_2954 = g_2177[0][3][9])))), ((safe_sub_func_uint16_t_u_u((8UL || (g_2420 = ((l_201 = (l_2886[2] = ((safe_mod_func_uint16_t_u_u((l_2900[0][2][7] = 0UL), (safe_lshift_func_uint16_t_u_u(l_2774, (l_2943 < (safe_lshift_func_uint16_t_u_u(((+(l_2896 & g_172[2])) >= g_1460), 6))))))) & l_2896))) ^ l_2943))), l_2943)) && 1UL))) == 2UL)))))
            {
                l_2900[0][1][8] = (g_3258 | (safe_unary_minus_func_uint32_t_u(l_2954)));
            }
            else
            {
                uint16_t l_2979 = 0UL;
                int32_t l_3106 = 0x8C9DC0F5L;
                if ((safe_rshift_func_uint16_t_u_u(l_2900[0][1][8], (safe_add_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((safe_lshift_func_int16_t_s_u((0x8092L < ((~(((((safe_lshift_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((g_161 != (0x4FA4222FL < l_2900[0][1][8])), 5)), (l_2839[1][2][3] != g_2420))) > (g_361 = g_172[4])) <= (((g_1460 != g_2352[2]) < l_2978) <= g_1460)) ^ 0x244BBC70L) != g_543[1])) && l_2979)), 1)), g_172[4])), 0L)))))
                {
                    int16_t l_3004[7][4][5] = {{{(-4L),0x7651L,(-1L),(-5L),1L},{0L,0x99FBL,0xBC8AL,0x2258L,0L},{0x907EL,1L,0xD21DL,(-4L),0L},{(-1L),0L,0x33D1L,0x1D12L,1L}},{{6L,0x1D12L,1L,(-1L),(-4L)},{0xF8F4L,0xAC40L,0x96A6L,1L,1L},{(-1L),0x1CB0L,(-1L),0x46ADL,3L},{0xBC8AL,6L,(-6L),0xC8C6L,0x7C8AL}},{{(-5L),(-1L),0x7C8AL,(-4L),9L},{(-4L),1L,(-6L),0x7C8AL,0x530DL},{(-1L),0x7484L,(-1L),3L,6L},{0xBAC0L,0x32A9L,0x96A6L,0x1CB0L,0x444BL}},{{0x444BL,0x34E6L,1L,(-1L),1L},{0x7484L,0x907EL,0x33D1L,8L,1L},{0x31EAL,(-6L),0xD21DL,(-4L),(-1L)},{0x31EAL,(-1L),0xBC8AL,0x530DL,1L}},{{0x7484L,1L,(-1L),0x51ECL,0xB22CL},{0x444BL,0x2258L,(-4L),0xBA36L,0x907EL},{0xBAC0L,0L,0L,0xBAC0L,0x7651L},{(-1L),(-4L),0x444BL,0xAC40L,1L}},{{(-4L),0x96A6L,0xF8F4L,(-6L),0x99FBL},{(-5L),0xB22CL,(-1L),1L,0L},{0x3620L,0x46ADL,3L,1L,3L},{0L,0L,(-4L),(-4L),1L}},{{0xBC8AL,0x7C8AL,0L,(-1L),0x3620L},{(-4L),0x2258L,0L,0L,0x7C8AL},{1L,0x34E6L,0x1D12L,(-1L),0xC8C6L},{0x31EAL,0x34E6L,0xF8F4L,1L,(-4L)}}};
                    int32_t l_3027 = 0x4F76AF9EL;
                    int i, j, k;
                    for (l_2692 = 0; (l_2692 != 55); ++l_2692)
                    {
                        int16_t l_2984[4] = {0L,0L,0L,0L};
                        int i;
                        g_247 = l_2858;
                        l_2290 = (safe_lshift_func_uint16_t_u_u(0x652AL, 2));
                        if (l_2984[3])
                            continue;
                        l_268 = ((g_1460 != ((l_2984[3] == ((-10L) <= 0x4657L)) & g_543[0])) != 0x598F6BB9L);
                    }
                    for (g_538 = 0; (g_538 <= 4); g_538 += 1)
                    {
                        int i;
                        l_268 = (l_2886[g_538] = (safe_lshift_func_uint8_t_u_s(g_361, (safe_rshift_func_int16_t_s_u((safe_mod_func_uint32_t_u_u((g_949[0][2][2] != g_1460), (safe_rshift_func_int16_t_s_u((safe_unary_minus_func_int32_t_s(g_172[4])), ((safe_mod_func_uint32_t_u_u(l_2979, l_2840)) != l_2886[1]))))), (safe_lshift_func_uint8_t_u_u(g_217, 5)))))));
                        l_2900[0][1][8] = (safe_rshift_func_int16_t_s_u((((l_2774 > (safe_sub_func_uint8_t_u_u(l_2979, (safe_rshift_func_uint8_t_u_s(l_3004[4][2][0], 0))))) > (safe_mod_func_uint16_t_u_u((safe_sub_func_int32_t_s_s((safe_mod_func_uint8_t_u_u((((0xD7L || (l_3027 = ((safe_add_func_int16_t_s_s((l_2290 = ((l_2978 & (safe_lshift_func_int8_t_s_u(((safe_lshift_func_int8_t_s_u((l_3017 || ((((1L == (((!g_2177[3][1][5]) | ((((((safe_mod_func_int32_t_s_s(((((!((safe_rshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_s(((0x32L | g_217) < l_3004[4][2][0]), 2)) ^ g_2420), 12)) || 0x97B2L)) | l_2979) | 0xB9843563L) < 0xB46BL), g_2420)) > g_3258) < l_2290) || l_3026) == l_2790[4][0]) != l_2886[g_538])) | 0x616CL)) < l_2900[0][5][5]) ^ l_2886[g_538]) <= 1L)), 4)) ^ l_2979), 4))) <= l_2979)), 0x7F87L)) == g_1460))) > g_949[2][2][1]) & g_161), g_361)), l_2886[g_538])), l_2266[3]))) | 0x49L), g_813[1][0]));
                        if (l_2886[g_538])
                            continue;
                    }
                    l_268 = g_1129;
                }
                else
                {
                    int32_t l_3037 = 0xE3233A39L;
                    int32_t l_3060[10] = {6L,6L,6L,6L,6L,6L,6L,6L,6L,6L};
                    int i;
                    l_268 = (((safe_lshift_func_uint16_t_u_s((((((l_2266[3] = ((l_2886[2] = g_813[0][0]) == (g_543[1] ^ (g_1460 & g_103)))) <= (safe_sub_func_uint8_t_u_u(((0x13L | (l_2840 = ((g_1460 >= (safe_sub_func_int32_t_s_s(l_2979, g_1460))) >= ((safe_sub_func_int8_t_s_s((1UL >= 0x6AL), 0x75L)) <= 0xFD0877F9L)))) && l_3036[6][2][5]), l_2979))) >= 0UL) && g_359[9][0]) || l_3037), l_2943)) > l_2294) | g_538);
                    for (l_2674 = 0; (l_2674 > 24); l_2674 = safe_add_func_uint8_t_u_u(l_2674, 9))
                    {
                        int16_t l_3042 = 0xDD5AL;
                        g_115 = (safe_add_func_int16_t_s_s((l_3042 < g_2420), ((safe_sub_func_int32_t_s_s(0x826DAE46L, ((g_188 < 0xCDF2L) != ((safe_rshift_func_uint16_t_u_u(l_3037, (g_538 = l_2692))) && (65535UL < ((safe_rshift_func_int8_t_s_u(0xB0L, 0)) | l_2896)))))) != 0x08L)));
                    }
                    for (l_3037 = 5; (l_3037 >= 2); l_3037 -= 1)
                    {
                        uint8_t l_3061 = 0UL;
                        int i;
                        l_3061 = (~(((l_3060[5] = (((safe_mod_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_s((safe_unary_minus_func_int32_t_s((safe_add_func_uint32_t_u_u(((-1L) == g_172[(l_3037 + 2)]), g_2352[l_3037])))), g_2352[l_3037])) > ((!g_1215[l_3037]) > g_1460)), (safe_mod_func_int32_t_s_s(l_3037, (g_103 = 4294967295UL))))) || (0x5AFB853AL <= g_1215[l_3037])) | 0xA7L)) ^ l_3037) >= g_359[5][0]));
                    }
                }
                l_2900[0][2][4] = (((g_949[0][6][1] && (g_359[9][0] | (((g_2177[3][1][9] >= (1UL && (safe_mod_func_uint32_t_u_u(l_2858, (safe_lshift_func_uint8_t_u_u((((l_268 = g_538) ^ ((safe_mod_func_int8_t_s_s(((safe_lshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s(2L, l_3072)), 6)) != (g_2352[2] != 253UL)), g_217)) & g_1215[4])) & l_2858), l_2841)))))) >= l_2418[5][1]) ^ 0xD174L))) == 7UL) <= 0x9A48L);
                if ((g_2352[5] && l_201))
                {
                    l_2408[4][4] = l_145;
                }
                else
                {
                    uint32_t l_3090 = 0UL;
                    int32_t l_3091 = 0L;
                    int16_t l_3092 = (-8L);
                    l_2900[0][1][8] = (g_115 = (((safe_add_func_uint8_t_u_u((0x8017L & 0xC852L), (((safe_add_func_uint16_t_u_u((!((safe_rshift_func_uint8_t_u_s(((safe_add_func_int8_t_s_s(4L, (safe_mod_func_int16_t_s_s((g_2420 > l_2979), (~(l_268 = ((+l_145) && (safe_add_func_uint8_t_u_u((((+(((!l_2841) && ((l_3090 = l_2408[1][3]) & (((l_3091 && 0x435BL) ^ l_2601) > 1L))) >= l_3092)) | l_3026) > 0x889AL), g_866[6][9]))))))))) <= l_201), l_2979)) < g_1460)), g_1460)) & g_1460) >= 0xAEL))) & l_2978) > 0x659EL));
                    l_3017 = l_2790[4][0];
                    if (g_217)
                    {
                        uint16_t l_3099[7][1][9] = {{{0x51BFL,0xF916L,0xE95AL,0xF916L,0x51BFL,0xFFE8L,0xF916L,0x12F6L,0x49F3L}},{{0xFB2EL,0x5E99L,0x2DFEL,3UL,0x5E99L,0x6495L,0x5E99L,3UL,0x2DFEL}},{{0x51BFL,0x51BFL,0x49F3L,0x12F6L,0xF916L,0xFFE8L,0x51BFL,0xF916L,0xE95AL}},{{0x1128L,0x5E99L,0x525EL,0xFB2EL,0xFB2EL,0x525EL,0x5E99L,0x1128L,0x6495L}},{{0xB939L,0xF916L,0x49F3L,0xB939L,0xA389L,65526UL,0xF916L,0xF916L,65526UL}},{{0UL,0xFB2EL,0x2DFEL,0xFB2EL,0UL,0x9D28L,0xFB2EL,3UL,0x6495L}},{{0xF916L,0xA389L,0xE95AL,0x12F6L,0xA389L,0x49F3L,0xA389L,0x12F6L,0xE95AL}}};
                        int i, j, k;
                        g_247 = (safe_sub_func_uint8_t_u_u(((safe_add_func_uint16_t_u_u(g_543[1], (0x01E7BACFL || (j = 0L)))) == (((l_2900[0][0][5] = ((safe_sub_func_int16_t_s_s((g_949[0][6][1] < ((g_2420 = ((0xE5L || (l_3099[2][0][1] < (l_201 | (safe_rshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((g_813[6][0] >= (l_145 = (safe_lshift_func_uint8_t_u_s((1L & l_2900[0][1][6]), g_359[2][6])))), 4)), 4))))) & l_3099[3][0][2])) || 1L)), l_2918)) && l_3106)) <= g_359[2][3]) & 0x0EL)), (-2L)));
                    }
                    else
                    {
                        l_2900[0][1][7] = l_3091;
                        return g_543[1];
                    }
                }
                g_247 = ((safe_unary_minus_func_int32_t_s((((l_2900[0][4][1] = ((((g_217 & ((4L >= (g_188 = ((7L | ((0x9B13L < g_217) > (l_2979 < ((!l_5[1][1]) <= (g_538 = ((g_1129 != (((0xA14DL > 0xAC7AL) == l_2886[2]) > 0L)) <= g_866[4][0])))))) | g_1129))) <= l_145)) < g_2352[0]) == l_2526) <= 0x0C7DL)) || 254UL) != l_3109))) != g_161);
            }
        }
        if ((((safe_rshift_func_int16_t_s_s((safe_mod_func_uint8_t_u_u((((safe_rshift_func_int16_t_s_u((9L ^ ((g_2177[2][1][7] == g_949[0][2][4]) || ((l_2886[3] = (l_3116 != (safe_mod_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((safe_rshift_func_int16_t_s_s((l_2292 > (0x05L | l_3036[5][1][4])), 7)), g_1129)), (safe_unary_minus_func_int8_t_s(((g_866[1][3] & g_217) & g_543[1]))))))) || g_866[4][0]))), 2)) == l_2838) <= 0UL), 0x82L)), g_1460)) && g_1460) < l_2838))
        {
            int16_t l_3131 = 0xDA0DL;
            g_247 = ((-7L) | (safe_lshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((0xACL >= (!(safe_mod_func_uint16_t_u_u(l_3131, l_3116)))), 5)), 10)));
            for (p_50 = 17; (p_50 <= (-24)); p_50 = safe_sub_func_uint32_t_u_u(p_50, 6))
            {
                if (g_813[1][0])
                    break;
                return l_3131;
            }
            return g_103;
        }
        else
        {
            int8_t l_3134 = 1L;
            g_247 = l_3134;
            l_2266[3] = (safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u(((((safe_sub_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u(((l_3036[8][1][4] && (((g_1460 = (safe_sub_func_int8_t_s_s((safe_mod_func_int8_t_s_s((safe_mod_func_int8_t_s_s(l_2858, (safe_sub_func_uint32_t_u_u(l_3151, ((g_103 = l_3134) == (0x54EAL == (g_866[2][3] & (g_115 = g_813[1][0])))))))), g_22)), (((l_2465 & g_866[4][0]) != g_361) < l_3134)))) >= 0x97L) || g_172[3])) <= 3L), g_359[9][0])) <= l_3134), 0UL)) ^ 2UL) == g_1215[4]) == 0x81F5611FL), l_2674)), 7));
        }
        l_2840 = ((0x10L && (((l_2886[0] = (l_3153 = l_145)) != l_2840) == (safe_mod_func_uint16_t_u_u((g_538 = (((safe_mod_func_int16_t_s_s((l_3017 = ((g_813[5][0] & ((((g_2177[3][1][9] = (safe_lshift_func_int16_t_s_u((safe_add_func_uint32_t_u_u((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((((safe_unary_minus_func_int8_t_s(((safe_sub_func_uint32_t_u_u(0UL, (0x891FL & (safe_mod_func_int16_t_s_s((l_2292 ^ (((((l_2816 == g_866[4][0]) <= l_2418[5][4]) | l_2840) > g_361) != l_3171)), l_2266[3]))))) || g_103))) > l_2465) | 0xD3666B9CL), l_2296)), l_2601)), j)), 13))) > 0UL) != g_2420) > l_2918)) != l_3151)), l_2841)) > l_2838) != l_2842)), 1L)))) <= 0L);
    }
    j = (l_2296 = (((!(((l_2266[3] = (safe_rshift_func_uint16_t_u_u(((g_247 = (((safe_rshift_func_int8_t_s_s(l_2266[0], 1)) == (~((0UL <= (((l_2408[2][5] || (safe_sub_func_uint16_t_u_u((0x07C4L | ((safe_lshift_func_uint8_t_u_u((((safe_mod_func_int8_t_s_s(9L, 0x8EL)) & (safe_mod_func_int16_t_s_s((safe_mod_func_uint16_t_u_u((((safe_add_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(0x49BFL, (l_2290 = ((safe_lshift_func_uint8_t_u_s((safe_add_func_uint8_t_u_u(((safe_rshift_func_int8_t_s_s(g_813[6][0], 7)) ^ (((l_2408[0][0] = g_2352[0]) > 0x99F79172L) > 0xE78350BCL)), l_2266[3])), g_103)) < g_2420)))), l_2674)) & g_1460) >= g_949[2][4][8]), g_866[6][3])), (-3L)))) >= 0x7F3CD12AL), 6)) == 0x5622E054L)), 0x1450L))) || g_361) != 0L)) != l_145))) <= g_217)) | g_543[1]), 14))) > g_103) & l_2899)) & (-10L)) <= g_103));
    if (l_2790[4][0])
    {
        int8_t l_3204 = 0xA2L;
        uint32_t l_3210 = 0xF4784D76L;
        int32_t l_3239 = 6L;
        int32_t l_3240[6];
        int i;
        for (i = 0; i < 6; i++)
            l_3240[i] = 0xADBA3217L;
        l_268 = (((((safe_rshift_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s((((g_1460 & (safe_add_func_int32_t_s_s((((((l_3204 = g_543[1]) | (9L != (safe_add_func_uint32_t_u_u(g_361, (8L | (-1L)))))) || ((safe_sub_func_int16_t_s_s((safe_unary_minus_func_uint32_t_u(l_3210)), l_3204)) <= (g_2177[3][1][9] | j))) ^ l_2266[3]) != l_3210), g_1129))) <= g_1460) || 5UL), g_2177[3][1][9])), 0)) < l_2294) >= 1UL) || j) > g_115);
        l_268 = (l_3204 <= (safe_sub_func_uint16_t_u_u(((l_2601 >= (1UL || (safe_sub_func_uint8_t_u_u((g_2177[2][3][7] = (safe_sub_func_uint8_t_u_u((safe_mod_func_int16_t_s_s(((l_201 = (safe_lshift_func_uint8_t_u_u((l_2266[1] = ((((l_3171 || (l_2290 = l_2692)) || (safe_sub_func_int8_t_s_s((safe_sub_func_int32_t_s_s(((l_2296 = (safe_mod_func_uint16_t_u_u(g_543[2], g_2420))) <= (g_543[1] || (l_2692 == 0UL))), l_2526)), 2L))) >= g_2177[5][3][1]) == l_3210)), l_2526))) != l_2418[5][4]), l_3204)), l_5[1][6]))), 0x74L)))) | g_949[2][4][8]), g_22)));
        l_3017 = (safe_add_func_uint16_t_u_u((((p_50 >= (safe_lshift_func_int8_t_s_s(0L, ((0L | l_2408[3][0]) < ((safe_add_func_uint32_t_u_u(l_2408[3][0], (((safe_mod_func_uint8_t_u_u(((l_3210 > ((safe_rshift_func_int16_t_s_u(((((g_359[9][0] = (l_3240[3] = (((safe_mod_func_uint16_t_u_u((g_813[1][0] = (4294967295UL == ((-5L) >= l_3210))), g_538)) >= l_5[2][1]) | l_3239))) & 4UL) & g_1460) && g_3258), 8)) > g_2420)) == l_3239), g_538)) > 0xBF1DC840L) != g_103))) ^ g_2177[1][1][7]))))) < g_949[0][6][1]) > 7UL), g_1460));
        for (l_268 = 0; (l_268 > 18); l_268 = safe_add_func_uint32_t_u_u(l_268, 3))
        {
            uint16_t l_3255[4][5];
            int32_t l_3256[2][8] = {{0L,0L,0x73962BB8L,0x73962BB8L,0L,0L,0x73962BB8L,0x73962BB8L},{0L,0L,0x73962BB8L,0x73962BB8L,0L,0L,0x73962BB8L,0x73962BB8L}};
            int i, j;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 5; j++)
                    l_3255[i][j] = 0x74B9L;
            }
            if ((safe_sub_func_uint16_t_u_u((l_3204 || (safe_add_func_uint32_t_u_u(((((((l_2790[4][0] || ((((g_538 != ((l_3256[1][3] = (i >= (l_2290 = (j = (l_2296 = (((safe_sub_func_int32_t_s_s(((((safe_mod_func_uint8_t_u_u(((((l_3240[2] & ((g_115 = (g_247 = (safe_add_func_uint16_t_u_u(l_3204, (65529UL != ((l_201 & ((safe_add_func_int8_t_s_s(3L, g_1215[1])) <= l_3255[1][3])) != 0x21FD1DCEL)))))) < (-8L))) >= 0xBAL) != l_2674) > l_5[3][0]), l_3116)) < 0L) & g_1460) ^ 0xA4EBL), 0xA9004A2AL)) > g_813[3][0]) != l_3255[1][3])))))) > l_3255[1][3])) & g_543[0]) >= l_2674) ^ 1L)) != 0L) & l_3171) ^ g_361) & l_3257) | l_3255[0][4]), 1UL))), l_88)))
            {
                uint32_t l_3263 = 4294967295UL;
                int32_t l_3303 = 0L;
                for (g_1460 = 0; (g_1460 != 43); g_1460++)
                {
                    uint32_t l_3304 = 0xA0CD230EL;
                    int32_t l_3305[2][8][1] = {{{0xC3B07C44L},{0xC3B07C44L},{0x80AED170L},{0xAF71240FL},{0x9433F045L},{0xAF71240FL},{0x80AED170L},{0xC3B07C44L}},{{0xC3B07C44L},{0x80AED170L},{0xAF71240FL},{0x9433F045L},{0xAF71240FL},{0x80AED170L},{0xC3B07C44L},{0xC3B07C44L}}};
                    int i, j, k;
                    l_3262 = (g_315 <= g_1460);
                    l_3263 = 0x3D7DBF13L;
                    if (g_2177[1][0][6])
                    {
                        return g_361;
                    }
                    else
                    {
                        uint8_t l_3287 = 5UL;
                        l_3305[0][3][0] = (((safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((g_2420 = ((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s((safe_unary_minus_func_int16_t_s((((safe_add_func_int16_t_s_s((l_3240[3] = l_3255[2][2]), ((safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(((safe_add_func_int32_t_s_s(((safe_mod_func_uint16_t_u_u((l_3256[1][3] = ((safe_sub_func_int32_t_s_s((j = 1L), (safe_lshift_func_int16_t_s_s(((0x83DAL <= (g_2177[3][1][9] > (l_3287 | 1UL))) <= (((safe_sub_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u((((safe_rshift_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(((l_3303 = (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_uint32_t_u((((safe_add_func_uint16_t_u_u(((l_3256[1][3] < l_3287) < ((safe_sub_func_int32_t_s_s(l_3287, 7UL)) && g_315)), i)) >= 0x318768DEL) && l_3263))), 9))) != l_3204), l_3256[1][6])), 4)) >= l_3304) | g_217), l_3287)) ^ l_88), 0L)) ^ 0x51L) != g_103)), 15)))) >= l_3287)), (-1L))) && g_2177[5][1][8]), g_813[6][0])) ^ 0xAFL), g_103)), g_3258)) >= 0x34L))) == g_359[9][2]) | g_1215[4]))), g_2420)), g_1460)) == l_3255[0][1])), 4)), 6)) || 4UL) | l_3287);
                    }
                }
                for (l_3204 = 0; (l_3204 <= (-20)); l_3204 = safe_sub_func_uint8_t_u_u(l_3204, 5))
                {
                    g_115 = (g_359[9][0] ^ (g_217 != (((safe_rshift_func_uint16_t_u_u(9UL, (safe_sub_func_int16_t_s_s((g_543[1] = 0x560CL), (safe_lshift_func_int16_t_s_s((!l_3303), 7)))))) > ((i && ((l_2266[3] = 65535UL) != (g_361 & (l_2296 = ((-10L) > 0xD9890121L))))) > l_3204)) | l_3256[1][3])));
                    l_3303 = 0x9ED79E98L;
                    j = (l_3256[1][2] = (g_115 = (0x6A45L != (p_50 = (-1L)))));
                    l_88 = 0xA5D6E7B4L;
                }
                for (g_115 = (-29); (g_115 < 29); g_115++)
                {
                    int32_t l_3319 = 4L;
                    for (l_2292 = 1; (l_2292 <= 7); l_2292 += 1)
                    {
                        int i, j;
                        return g_866[l_2292][(l_2292 + 1)];
                    }
                    for (l_2294 = (-5); (l_2294 > 23); l_2294++)
                    {
                        l_3319 = 0x34207361L;
                    }
                }
            }
            else
            {
                l_88 = l_3239;
            }
            g_115 = (safe_lshift_func_uint8_t_u_s((safe_sub_func_int16_t_s_s((((((((safe_add_func_int8_t_s_s(0x88L, (l_3017 ^ (safe_unary_minus_func_uint32_t_u(g_1460))))) >= 0xE6B5L) <= (g_359[9][0] || g_813[1][0])) < (0xD1BFL && (((0x8B84L != (safe_sub_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((safe_add_func_uint16_t_u_u((l_268 >= l_3256[1][3]), l_2294)), l_2790[4][0])) > 0x93L), l_3255[1][3]))) | g_2177[4][3][5]) ^ i))) < g_2352[1]) == l_3257) & 65530UL), i)), l_5[1][6]));
        }
    }
    else
    {
        int8_t l_3339 = 0xC8L;
        int32_t l_3340 = 0x644F2DE5L;
        uint8_t l_3351[6];
        int32_t l_3352[3];
        uint16_t l_3398 = 65532UL;
        uint32_t l_3467 = 0UL;
        int i;
        for (i = 0; i < 6; i++)
            l_3351[i] = 0x35L;
        for (i = 0; i < 3; i++)
            l_3352[i] = 0xE9F35B3EL;
        if ((0L ^ (((l_2292 ^ ((safe_mul_func_uint8_t_u_u((l_3340 = (safe_add_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s(g_361, l_3339)), (g_1460 == g_1460)))), ((l_88 = (~(safe_lshift_func_int16_t_s_s((((safe_unary_minus_func_uint32_t_u(((safe_lshift_func_uint8_t_u_s(((safe_sub_func_uint32_t_u_u((safe_rshift_func_uint16_t_u_s(l_2408[3][0], 13)), (l_3017 = (((g_161 ^ ((((g_866[4][0] ^ l_3351[3]) < 0xE8L) | g_1460) || l_2266[3])) ^ l_3351[3]) || g_103)))) & l_3351[0]), l_3351[2])) != g_1215[4]))) ^ g_2420) & l_3352[0]), g_359[9][0])))) != 0x3D20D3F6L))) <= l_3339)) == g_161) == l_2408[3][0])))
        {
            l_268 = (g_115 = (safe_add_func_int8_t_s_s(g_2177[3][1][9], l_3351[4])));
        }
        else
        {
            int32_t l_3355[8][1] = {{0L},{(-1L)},{0L},{(-1L)},{0L},{(-1L)},{0L},{(-1L)}};
            uint32_t l_3372[4] = {0x99672B6EL,0x99672B6EL,0x99672B6EL,0x99672B6EL};
            int32_t l_3443 = 4L;
            uint32_t l_3505 = 18446744073709551615UL;
            int32_t l_3506[10];
            int i, j;
            for (i = 0; i < 10; i++)
                l_3506[i] = (-1L);
            g_247 = ((g_1129 = (g_2352[2] ^ l_3340)) | l_3355[5][0]);
            for (g_115 = 2; (g_115 >= 0); g_115 -= 1)
            {
                int32_t l_3359 = 0x3456D091L;
                uint16_t l_3373 = 1UL;
                uint32_t l_3513 = 4294967295UL;
                int i;
                l_3340 = (g_543[g_115] != ((safe_rshift_func_uint8_t_u_s(g_543[g_115], (g_361 = (l_3359 = (safe_unary_minus_func_int8_t_s(1L)))))) ^ (safe_add_func_int32_t_s_s(g_866[6][0], (((0xF346L ^ l_3262) && (((g_1215[4] | (!l_3340)) & l_3339) != g_1460)) | 4294967288UL)))));
                if ((((((l_2899 > (g_813[4][0] | 0x4A1BL)) | l_3355[5][0]) == (((g_538 ^ ((g_22 || g_1215[4]) < (safe_add_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((((g_1129 || (safe_unary_minus_func_int16_t_s(g_2352[2]))) == g_115) <= 0x88L), 14)), (-1L))))) != l_145) == g_538)) < 65535UL) <= 1UL))
                {
                    uint16_t l_3397 = 0xE9F5L;
                    for (g_361 = 0; g_361 < 3; g_361 += 1)
                    {
                        l_3352[g_361] = 0x6604D0B6L;
                    }
                    for (l_3257 = 0; (l_3257 <= 2); l_3257 += 1)
                    {
                        int32_t l_3396[2][10] = {{0xFD928D26L,0x128AF7B3L,0xFD928D26L,0x70EF2261L,0x70EF2261L,0xFD928D26L,0x128AF7B3L,0xFD928D26L,0x70EF2261L,0x70EF2261L},{0xFD928D26L,0x128AF7B3L,0xFD928D26L,0x70EF2261L,0x70EF2261L,0xFD928D26L,0x128AF7B3L,0xFD928D26L,0x70EF2261L,0x70EF2261L}};
                        int i, j;
                        j = ((((safe_sub_func_uint32_t_u_u(((safe_lshift_func_uint16_t_u_u((((((((l_5[5][1] ^ g_1460) & (g_359[5][3] = ((g_103 = l_3372[0]) & l_3373))) & ((safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u((g_2420 != (g_361 = ((251UL <= ((l_145 = (((g_315 = (safe_add_func_uint32_t_u_u(((((safe_mod_func_int16_t_s_s((safe_sub_func_int32_t_s_s((safe_sub_func_int8_t_s_s((0xCCA5L != (safe_unary_minus_func_int16_t_s((g_543[g_115] = ((l_3373 < (safe_add_func_uint16_t_u_u(((l_268 = (safe_rshift_func_int8_t_s_s((~(safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((g_538 ^ g_1215[5]), g_2420)), l_3355[4][0]))), 1))) > 0xE3C5E1EAL), i))) <= l_201))))), g_1215[4])), g_361)), l_3396[0][2])) && l_3397) && l_2296) > (-1L)), l_3359))) >= l_3373) | 0x3BE0L)) ^ (-9L))) || 0x52L))), 3)) | l_3398), 0xC478L)) <= 0x81F1L)) <= g_1460) & g_188) <= g_247) >= 0x47L), g_188)) != l_3399), l_3151)) != l_3397) ^ 1UL) > 0x7F4ED5EFL);
                        l_3340 = (((((g_1460 <= (safe_lshift_func_int8_t_s_u(((l_3397 && (l_3396[0][2] = ((((l_3351[3] > (((safe_sub_func_uint8_t_u_u(((g_315 || (l_3359 = (((g_103 = (g_359[9][1] = (((g_813[1][0] = ((((safe_sub_func_int16_t_s_s((-1L), ((g_1129 = ((0x82A8L ^ 0xEFCAL) > ((l_2408[3][0] != (safe_sub_func_int16_t_s_s((((0x3DD5L < g_543[g_115]) <= 1L) ^ l_3408), g_2177[1][2][4]))) || 4294967295UL))) != 0x58L))) && l_2418[5][4]) || 4L) & g_1460)) == 0x5062L) >= 0x611BL))) != g_1460) && g_1215[4]))) != 3L), l_3351[3])) | l_3396[0][2]) <= g_361)) & g_538) != 1L) || 1L))) >= 255UL), g_2177[3][1][9]))) | 0xEFL) <= g_543[g_115]) >= g_188) == l_3373);
                        l_268 = l_3352[0];
                    }
                    l_2408[1][0] = (((((l_3372[3] > (safe_mod_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u((safe_rshift_func_uint16_t_u_u(((g_172[3] != (safe_add_func_int8_t_s_s(l_3397, (((safe_unary_minus_func_int8_t_s(((((safe_sub_func_int32_t_s_s(g_12, l_2790[4][0])) | ((safe_lshift_func_uint16_t_u_s((l_3424[1][0][0] && ((0xFDCCD15CL < (safe_lshift_func_uint16_t_u_s((safe_lshift_func_uint16_t_u_s((safe_add_func_int8_t_s_s((g_361 = ((l_3351[4] & g_543[g_115]) <= l_88)), 0UL)), g_161)), 9))) ^ 8UL)), 11)) ^ g_538)) & (-5L)) ^ g_3258))) < g_1460) != 0x29BCB211L)))) == l_3397), g_866[4][0])), 15)), l_2526))) <= (-3L)) == 0x1AE2L) && l_3398) == l_3372[0]);
                }
                else
                {
                    uint16_t l_3442[9][9] = {{0xD162L,0UL,0xD162L,0x5941L,0x5941L,0xD162L,0UL,0xD162L,0x5941L},{0xD162L,0x5941L,0x5941L,0xD162L,0UL,0xD162L,0x5941L,0xD162L,65532UL},{0x5941L,0xD162L,0UL,0xD162L,0x5941L,0x5941L,0xD162L,0UL,0xD162L},{0xD162L,0UL,0UL,0UL,0UL,0xD162L,0UL,0UL,0UL},{0x5941L,0x5941L,0xD162L,0UL,0xD162L,0x5941L,0x5941L,0xD162L,0UL},{65532UL,0UL,65532UL,0xD162L,0xD162L,65532UL,0UL,65532UL,0xD162L},{65532UL,0xD162L,0xD162L,65532UL,0UL,65532UL,0xD162L,0xD162L,65532UL},{0x5941L,0xD162L,0UL,0xD162L,0x5941L,0x5941L,0xD162L,0UL,0xD162L},{0xD162L,0UL,0UL,0UL,0UL,0xD162L,0UL,0UL,0UL}};
                    int i, j;
                    l_88 = ((safe_mod_func_int8_t_s_s((g_361 = ((safe_rshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((g_1460 = (((((0xEAL && (((l_3443 = (safe_sub_func_int32_t_s_s((!(safe_rshift_func_int16_t_s_s(g_161, l_3442[6][8]))), (g_217 == g_866[6][5])))) || (((l_3340 = (safe_lshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(((safe_lshift_func_int8_t_s_u(((safe_lshift_func_uint16_t_u_s(((+0x53L) >= (~((g_1460 = (safe_sub_func_uint32_t_u_u(0x00580031L, (((safe_sub_func_uint32_t_u_u(((safe_lshift_func_int16_t_s_u((safe_lshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_u(0xF9L, 7)), 15)), 10)) == (l_3443 = g_359[9][0])), g_12)) == 0x2266L) & l_2899)))) ^ l_3355[5][0]))), 1)) <= l_88), 1)) != l_3355[5][0]), 7)), 2))) == p_50) > g_359[9][0])) & 0xD676L)) == l_3442[0][6]) != l_3442[6][8]) ^ 0x3B79L) >= 0x22L)), 0UL)), g_361)) ^ g_866[4][0])), 0x3CL)) >= l_2692);
                }
                for (l_2692 = 0; (l_2692 <= 57); l_2692 = safe_add_func_int16_t_s_s(l_2692, 7))
                {
                    int32_t l_3476 = 0x5E8CBEC4L;
                    if (g_361)
                    {
                        uint16_t l_3468 = 0x5320L;
                        l_88 = ((l_3359 | g_543[g_115]) == (((g_2177[3][1][9] = (l_145 < 0xC0L)) > (l_3372[0] != (g_1460 = ((safe_unary_minus_func_int8_t_s(((l_3467 != g_543[g_115]) < l_3468))) >= ((((g_538 = 65535UL) | 0L) | 0L) || 8UL))))) != 0x21L));
                    }
                    else
                    {
                        uint8_t l_3474 = 0x79L;
                        int32_t l_3475 = 0xEE4C41D5L;
                        g_247 = (safe_add_func_int32_t_s_s((((l_3471 ^ (((l_3373 < ((safe_mod_func_uint16_t_u_u((g_1460 ^ (l_3352[1] ^ (g_103 && (((((g_2420 | 4294967292UL) | g_217) | (l_3474 = 6L)) > 1UL) > g_161)))), l_201)) == 0xEC67L)) || g_361) >= 0x2A2BL)) && g_361) != l_3475), g_949[0][6][1]));
                        if (l_3476)
                            break;
                        l_2408[1][1] = ((0xACA1L ^ ((safe_add_func_int16_t_s_s((((((l_3471 = ((((l_3474 >= (safe_lshift_func_uint8_t_u_s(0x3BL, 0))) >= (safe_lshift_func_uint8_t_u_s((safe_unary_minus_func_int16_t_s(l_88)), ((l_3443 | (g_315 > 0x81F1L)) ^ (safe_lshift_func_uint16_t_u_u((((safe_sub_func_uint16_t_u_u((((((l_2290 = (safe_rshift_func_int16_t_s_s(((~l_3475) > (l_2266[3] = 0x4EE0L)), g_1460))) && g_543[1]) & g_813[1][0]) ^ l_3492) > g_1215[1]), 0L)) >= l_3398) < (-5L)), 10)))))) ^ g_543[g_115]) <= 1UL)) >= 0x86DCL) | l_3351[5]) == 0UL) & g_543[g_115]), g_2352[1])) >= 0xC6L)) <= g_1215[3]);
                    }
                    for (l_3471 = (-22); (l_3471 < 11); ++l_3471)
                    {
                        uint32_t l_3502 = 0x9ED2561EL;
                        g_247 = (0x16F39D5EL != ((((safe_add_func_int16_t_s_s(((l_3476 <= ((safe_add_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u((l_2290 = ((l_268 & (!((l_3443 = (g_359[9][0] = l_3339)) >= (g_247 <= 2L)))) == 3UL)), l_3502)), ((safe_add_func_int8_t_s_s((l_88 != 0x76L), g_315)) >= g_866[0][5]))) ^ 0UL)) || g_949[1][1][4]), l_3359)) || l_3502) < g_538) ^ l_3355[0][0]));
                    }
                    if ((((g_361 == 0x87L) != (g_1129 = 0UL)) ^ g_361))
                    {
                        l_3506[3] = ((0x63D96127L || l_3359) > (0xE625L || l_3505));
                    }
                    else
                    {
                        int8_t l_3520 = 0x2EL;
                        l_3359 = 0x132D1CFBL;
                        l_268 = (((l_3340 = (((((l_2292 >= (g_1460 = ((0xA6C9L | (safe_mod_func_int8_t_s_s((safe_sub_func_int32_t_s_s(g_361, l_3351[3])), l_3372[0]))) & (safe_mod_func_uint16_t_u_u(((l_3513 < (safe_sub_func_uint32_t_u_u(((safe_rshift_func_int8_t_s_s(g_866[0][1], (((safe_sub_func_int8_t_s_s((g_813[6][0] && g_247), 255UL)) > 1L) || 0xA69DCD2EL))) | l_3520), l_145))) ^ l_3372[3]), g_1460))))) == 0xA3DB543AL) && l_3520) != 0x5621L) & l_201)) >= g_188) | g_361);
                    }
                    l_88 = g_1460;
                }
            }
        }
        g_115 = ((((g_247 = (g_543[1] | (safe_add_func_int16_t_s_s(g_2352[0], (((1UL ^ g_103) < l_3340) < (g_12 = (safe_sub_func_uint32_t_u_u(((safe_add_func_uint32_t_u_u((l_2408[0][2] == ((~(((((safe_add_func_int32_t_s_s(((safe_lshift_func_int16_t_s_s(l_3534, (safe_mod_func_uint8_t_u_u(g_866[7][7], (safe_sub_func_uint32_t_u_u((((((((l_3352[0] < l_2292) >= 0x780BL) != l_3398) ^ 0L) < (-1L)) | g_538) ^ g_361), l_2408[3][0])))))) <= 0UL), l_3351[3])) & 4294967295UL) || (-1L)) != (-1L)) < l_2408[0][5])) > l_88)), p_50)) & l_3398), (-6L))))))))) >= g_172[7]) == i) == l_2292);
        return l_3398;
    }
    if ((+(safe_add_func_int32_t_s_s((l_2408[3][4] = (((g_315 || (safe_sub_func_uint16_t_u_u(((l_2266[3] = (l_2841 ^ (safe_add_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((~((safe_lshift_func_int8_t_s_s((((l_2290 = l_3534) <= (((safe_add_func_uint8_t_u_u((((0xADFAL <= g_538) & (l_2601 && g_103)) < (-2L)), ((l_3116 < g_538) ^ l_88))) < 7UL) ^ l_2266[3])) | l_88), g_1129)) || l_5[1][6])), g_188)), 0x16L)))) || l_3116), 0x5C64L))) >= g_1215[3]) & l_268)), l_3408))))
    {
        int32_t l_3561 = 0xC7A6A094L;
        int32_t l_3562[7];
        int32_t l_3639 = 0x57E1FCD6L;
        int i;
        for (i = 0; i < 7; i++)
            l_3562[i] = 0xF6374F20L;
        if ((safe_rshift_func_uint16_t_u_s((g_361 < (safe_sub_func_uint8_t_u_u((g_1460 = (safe_sub_func_uint16_t_u_u(((l_3561 = 0xFE00L) > l_3562[1]), g_866[5][2]))), ((safe_rshift_func_int8_t_s_s((safe_sub_func_int16_t_s_s(g_813[1][0], ((j >= (safe_add_func_uint32_t_u_u(((safe_mul_func_int32_t_s_s((g_115 = (((0UL > ((g_538 > ((safe_add_func_int8_t_s_s((j <= 0xAE4AL), 0x0CL)) >= 255UL)) ^ 0xBAED8CF2L)) == g_1129) && 0L)), 0L)) || l_3562[1]), 0xFBC96193L))) == (-9L)))), 6)) == g_247)))), l_3573[1])))
        {
            l_3562[1] = 1L;
        }
        else
        {
            int16_t l_3588 = 9L;
            int32_t l_3622[9][5] = {{3L,0x6BA56314L,1L,0x10275A46L,0L},{0x10275A46L,(-7L),4L,4L,(-7L)},{0L,1L,5L,4L,0x99AB53BFL},{1L,0x99AB53BFL,0x528214A4L,0x10275A46L,0x6BA56314L},{1L,(-10L),0L,0x6BA56314L,0x888D88CAL},{1L,1L,0x888D88CAL,1L,1L},{0L,0x366C108CL,0x888D88CAL,0L,1L},{0x10275A46L,8L,0L,5L,3L},{3L,1L,0x528214A4L,0x366C108CL,1L}};
            uint16_t l_3664 = 8UL;
            int i, j;
            for (g_103 = 2; (g_103 >= 7); ++g_103)
            {
                uint8_t l_3587[6];
                int32_t l_3614 = 0x78771F22L;
                int32_t l_3615[3];
                int i;
                for (i = 0; i < 6; i++)
                    l_3587[i] = 248UL;
                for (i = 0; i < 3; i++)
                    l_3615[i] = 0x1058D4E6L;
                j = (0x2024L >= (safe_rshift_func_int16_t_s_u((0xA3L && 0x6BL), l_3561)));
                g_115 = (g_1460 <= ((((l_2408[3][0] = (safe_rshift_func_uint8_t_u_u(((safe_add_func_int32_t_s_s((0x3CA5L >= ((safe_mod_func_uint8_t_u_u(0x91L, l_3562[5])) >= l_3562[1])), (1L | 0x184E7879L))) != l_3257), ((safe_rshift_func_uint16_t_u_u((~(g_813[4][0] = 2UL)), l_3561)) | l_3587[3])))) && 0x2CB018B9L) & g_12) == l_3588));
                l_88 = l_3116;
                l_3615[2] = ((((g_2420 = (((safe_sub_func_int8_t_s_s((-2L), (safe_rshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u(7UL, ((255UL != (safe_sub_func_int32_t_s_s((safe_mod_func_uint32_t_u_u(((g_2352[2] ^ (0xC0D53A6EL | (l_3614 = (safe_lshift_func_uint16_t_u_u((safe_unary_minus_func_int32_t_s((((g_315 & (safe_sub_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u(((safe_lshift_func_uint8_t_u_s(((((safe_lshift_func_uint16_t_u_u((safe_add_func_int8_t_s_s((g_361 ^ l_2465), (l_2266[3] = ((safe_lshift_func_int16_t_s_u((g_2177[3][0][1] | 0L), l_201)) == 7L)))), g_1460)) > 0x266CL) >= l_201) <= g_315), 2)) == 0L), 0UL)), 1UL))) >= g_361) != (-1L)))), 11))))) ^ l_2290), l_3562[6])), l_3424[1][0][0]))) >= 0x63A0L))), l_3587[4])))) & l_3587[5]) | g_315)) ^ 254UL) <= l_3424[1][2][3]) || l_3614);
            }
            l_3471 = g_2177[3][1][9];
            j = (safe_unary_minus_func_uint8_t_u(1UL));
            if (g_172[7])
            {
                uint16_t l_3621 = 8UL;
                uint16_t l_3638[10][1][6] = {{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}},{{0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL,0x6793L}},{{0x05AAL,0x05AAL,0x6793L,0x6793L,0x05AAL,0x05AAL}}};
                int32_t l_3656 = 0x6C16DA66L;
                uint16_t l_3666 = 65535UL;
                int32_t l_3681 = 0L;
                int i, j, k;
                g_247 = l_88;
                l_3622[1][1] = ((1UL | (safe_mod_func_int16_t_s_s((l_268 & l_3588), l_3562[1]))) == (g_2177[3][1][9] = (safe_lshift_func_int8_t_s_u(l_3621, 5))));
                if ((safe_add_func_int8_t_s_s((g_361 = (g_2420 = (safe_lshift_func_uint8_t_u_u(((~0xACL) || (((l_201 && (safe_mod_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(((-1L) ^ (l_88 = ((g_813[3][0] == (l_3621 & g_3258)) <= g_538))), (safe_rshift_func_int8_t_s_u(((((safe_unary_minus_func_int8_t_s(((l_3561 ^ (l_3638[4][0][5] = (!(g_361 = (251UL | 1UL))))) & l_268))) | 0x6828710FL) || g_359[4][4]) > l_2296), g_361)))) < g_315), l_3588))) & 0xA5L) != l_2899)), l_3639)))), 0L)))
                {
                    int16_t l_3668 = 4L;
                    if ((0x58A82B72L | (safe_sub_func_int16_t_s_s(g_2177[3][1][9], (1L < g_2177[4][3][0])))))
                    {
                        uint32_t l_3663 = 0xB87B213BL;
                        int32_t l_3665 = 0x38F15173L;
                        l_3668 = (l_3667 = (0x9C031653L > ((((safe_sub_func_uint32_t_u_u((~(g_315 ^ ((((safe_mod_func_uint8_t_u_u((g_2177[3][1][9] > (safe_sub_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_s((((safe_rshift_func_uint16_t_u_u(l_3621, (g_115 && (l_3655 == (g_866[0][1] = (l_3656 = 0L)))))) || (safe_lshift_func_int16_t_s_s((safe_add_func_int16_t_s_s(g_103, (((l_3663 = (4294967295UL ^ 0xC8C7ECD9L)) == 0x67EB8C8CL) <= 0L))), 14))) >= l_3664), 11)) == g_361), 3)) == l_3665), l_3622[1][1]))), 0x4AL)) == g_2352[2]) && 0x4BL) & g_359[4][4]))), l_3622[3][4])) == (-1L)) && g_247) < l_3666)));
                        l_268 = 1L;
                    }
                    else
                    {
                        int32_t l_3686 = 0x5209DBEDL;
                        int32_t l_3687 = 0L;
                        l_268 = ((safe_rshift_func_int8_t_s_u((safe_mod_func_uint16_t_u_u((safe_sub_func_int8_t_s_s((((-10L) < (safe_lshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((((safe_rshift_func_uint16_t_u_u((g_538 = (((l_3681 != (0xD32132F5L <= (g_172[1] < (!g_161)))) || 0UL) <= l_3683)), (0xA83222B9L || ((safe_sub_func_int16_t_s_s((l_3622[8][3] <= g_543[1]), l_3686)) & (-5L))))) < p_50) & p_50), l_88)) <= (-1L)), 6))) >= l_3687), g_115)), 8UL)), 2)) | g_172[0]);
                    }
                    for (g_12 = 0; (g_12 == 4); g_12 = safe_add_func_uint32_t_u_u(g_12, 4))
                    {
                        return l_3656;
                    }
                    for (g_315 = 0; (g_315 <= 4); g_315 += 1)
                    {
                        int i;
                        g_115 = (safe_add_func_uint8_t_u_u(l_2266[g_315], (safe_lshift_func_int16_t_s_s((safe_sub_func_uint16_t_u_u((8L == (l_3656 = ((l_2266[g_315] && g_172[4]) < g_2177[5][2][8]))), (g_538 = (g_538 = (g_103 || 0x4FL))))), 4))));
                        if (g_161)
                            break;
                    }
                    l_3702 = (6UL && (g_361 & (l_3639 = ((((safe_sub_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_s((((l_3562[1] && 9L) > (0xE5F008A1L <= ((l_88 = (-10L)) <= (safe_mod_func_int8_t_s_s(g_359[6][3], (g_1460 = l_2790[0][0])))))) >= g_1215[4]), l_2899)) ^ 0xD6L), 0x64C4L)) & l_3668) == l_3656) & l_3668))));
                }
                else
                {
                    for (l_2692 = 0; (l_2692 != 42); l_2692++)
                    {
                        l_2266[2] = g_315;
                    }
                    return g_315;
                }
            }
            else
            {
                return g_188;
            }
        }
        l_3707 = ((safe_lshift_func_int8_t_s_u(((l_3562[0] >= g_866[4][0]) != (g_1460 = (p_50 > g_103))), l_3707)) > 0x3DD2L);
        j = ((((safe_sub_func_uint16_t_u_u((((safe_rshift_func_uint16_t_u_u(l_3562[0], (safe_mod_func_uint8_t_u_u((safe_add_func_uint32_t_u_u(((g_247 = (safe_rshift_func_int16_t_s_u((-2L), ((g_172[1] = 65528UL) < l_3562[1])))) > (safe_lshift_func_int16_t_s_u(((((~g_2177[1][2][6]) | ((l_3721 || l_2294) >= (0x0FL ^ j))) | l_3639) >= g_866[4][0]), g_2352[2]))), l_2526)), l_3702)))) < g_1129) & g_315), l_3562[1])) != 1UL) && l_2418[5][4]) ^ i);
    }
    else
    {
        int32_t l_3732 = 5L;
        int32_t l_3772[9][5][4] = {{{(-5L),0x53797119L,(-1L),0xEC1AA655L},{(-3L),0x0BED20CAL,0x620E126EL,0x64D60197L},{0x620E126EL,0x64D60197L,(-1L),(-1L)},{0x9C8EED80L,0x08C26BBCL,(-1L),(-7L)},{(-1L),(-1L),0x5187487DL,(-1L)}},{{(-1L),0x5187487DL,0x5187487DL,0x08C26BBCL},{0L,0x3A0636EDL,0x227DF413L,0L},{(-1L),(-1L),0x53797119L,0x5A84B327L},{(-1L),0x08C26BBCL,0x3C72134DL,0x5A84B327L},{0L,(-1L),0x5B09E585L,0L}},{{0x64D60197L,0x3A0636EDL,0xEC1AA655L,0x08C26BBCL},{0x6CA574B2L,0x5187487DL,(-1L),0xC7C31EEAL},{0x620E126EL,(-1L),(-1L),(-5L)},{(-1L),0xEC1AA655L,0x9C8EED80L,0x0BED20CAL},{0x3A0636EDL,(-1L),0x620E126EL,(-1L)}},{{1L,(-1L),(-3L),0L},{0x5A84B327L,0L,(-5L),0x9C8EED80L},{0x9C8EED80L,4L,0L,8L},{0x9C8EED80L,(-7L),(-5L),0x2F85340DL},{0x5A84B327L,8L,(-3L),0L}},{{1L,0L,0x620E126EL,0x53797119L},{0x3A0636EDL,0xB8D39A8AL,0x9C8EED80L,(-1L)},{(-1L),0x64D60197L,(-1L),0x3FDD2651L},{0x620E126EL,0x5B09E585L,(-1L),(-1L)},{0x6CA574B2L,0x6CA574B2L,0xEC1AA655L,4L}},{{0x64D60197L,0x2F85340DL,0x5B09E585L,0x3A0636EDL},{0L,(-1L),0x3C72134DL,0x5B09E585L},{(-1L),(-1L),0x53797119L,0x3A0636EDL},{(-1L),0x2F85340DL,0x227DF413L,4L},{0L,0x6CA574B2L,0x5187487DL,(-1L)}},{{0x08C26BBCL,0x5B09E585L,0x6CA574B2L,0x3FDD2651L},{(-7L),0x64D60197L,0x0BED20CAL,(-1L)},{(-3L),0xB8D39A8AL,(-1L),0x53797119L},{8L,0L,8L,0L},{(-1L),8L,0xC7C31EEAL,0x2F85340DL}},{{0x53797119L,(-7L),0x3A0636EDL,8L},{(-1L),4L,0x3A0636EDL,0x9C8EED80L},{0x53797119L,0L,0xC7C31EEAL,0L},{(-1L),(-1L),8L,(-1L)},{8L,(-1L),(-1L),0x0BED20CAL}},{{(-3L),0xEC1AA655L,0x0BED20CAL,(-5L)},{(-7L),(-1L),0x6CA574B2L,0xC7C31EEAL},{0x08C26BBCL,0x5187487DL,0x5187487DL,0x08C26BBCL},{0L,0x3A0636EDL,0x227DF413L,0L},{(-1L),(-1L),0x53797119L,0x5A84B327L}}};
        int32_t l_3780 = 1L;
        uint32_t l_3807[8] = {0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL};
        int16_t l_3822 = 0xB624L;
        uint32_t l_3909[7][2] = {{4294967295UL,0xDBB9B69CL},{0xDA67836AL,0xDBB9B69CL},{4294967295UL,0xA3043AE8L},{0xA3043AE8L,4294967295UL},{0xDBB9B69CL,0xDA67836AL},{0xDBB9B69CL,4294967295UL},{0xA3043AE8L,0xA3043AE8L}};
        uint32_t l_3937 = 9UL;
        int32_t l_3987 = 0x7570AEB1L;
        int i, j, k;
        l_3732 = (safe_add_func_int32_t_s_s(l_2408[3][0], (safe_rshift_func_uint8_t_u_u(((((safe_rshift_func_uint8_t_u_s(((((-10L) != (safe_mod_func_uint32_t_u_u(((-9L) > ((1L < (safe_lshift_func_int16_t_s_u(l_3732, (safe_rshift_func_uint16_t_u_u(l_2408[2][1], 2))))) != (safe_rshift_func_int16_t_s_u(((safe_rshift_func_uint16_t_u_s(g_1215[5], 5)) | (l_3732 || ((safe_add_func_int16_t_s_s(l_268, 0x51BCL)) <= 0x9FL))), l_3471)))), 0x6935AA16L))) || g_2352[2]) != l_3741), 5)) && l_3732) && l_3732) > l_3017), l_3732))));
        if ((((g_2352[2] < (((safe_rshift_func_int16_t_s_s((((((safe_sub_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(0x91L)), (g_1460 = 255UL))) && (g_949[0][6][1] & (safe_add_func_int32_t_s_s(((safe_unary_minus_func_int16_t_s((-1L))) && (safe_rshift_func_int16_t_s_s(((((g_115 = l_2408[3][0]) > ((l_3755[0][0][5] = ((g_217 = (g_1460 = 255UL)) ^ ((l_3752 != (((+((safe_unary_minus_func_uint16_t_u(((l_2674 && i) < 9UL))) <= g_2420)) > l_3732) & g_103)) == l_2266[3]))) || l_3732)) == l_3732) || 7L), g_2420))), l_3707)))) == 0x1476L) & l_3752) & 4294967295UL), l_3732)) || 1UL) && 0x51L)) & g_2352[8]) | g_1460))
        {
            int32_t l_3782 = (-1L);
            int32_t l_3783 = (-1L);
            uint32_t l_3784[6] = {1UL,0x277AD475L,1UL,1UL,0x277AD475L,1UL};
            int i;
            l_268 = (((l_3732 = (g_2177[0][1][6] > 65535UL)) ^ (safe_mod_func_uint8_t_u_u(((g_2420 = (safe_rshift_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u((safe_lshift_func_uint16_t_u_u((g_538 = (safe_lshift_func_uint8_t_u_u(255UL, (0UL > (l_3784[4] = (safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(g_115, 3)), (((l_3783 = (safe_lshift_func_uint8_t_u_s((l_3772[0][4][0] <= ((l_3262 = ((((safe_lshift_func_int8_t_s_u((g_2420 = l_3775), 2)) != ((((safe_lshift_func_int16_t_s_u((g_543[1] = (((((((65534UL || (g_361 = (safe_add_func_int16_t_s_s((l_3752 ^ l_3780), g_361)))) || (-1L)) ^ g_1460) == l_3782) || l_3782) ^ l_3755[0][1][1]) == g_543[1])), 2)) ^ g_315) == l_3782) <= g_2177[4][1][2])) && g_538) <= 0xCEL)) != 0UL)), 4))) || i) && g_813[0][0])))))))), l_2418[3][4])), 1)), g_1129))) | l_2266[4]), 0xE6L))) ^ g_2352[6]);
            g_247 = 0x9DF8728DL;
        }
        else
        {
            uint32_t l_3796 = 18446744073709551615UL;
            int32_t l_3808 = (-1L);
            int32_t l_3812 = 0x5C3FB331L;
            for (g_361 = 0; (g_361 <= (-26)); g_361 = safe_sub_func_uint32_t_u_u(g_361, 4))
            {
                int32_t l_3789 = 0L;
                int32_t l_3793 = 0L;
                for (g_2420 = 0; (g_2420 != 4); g_2420 = safe_add_func_int32_t_s_s(g_2420, 2))
                {
                    int32_t l_3792[2][4];
                    int i, j;
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 4; j++)
                            l_3792[i][j] = 1L;
                    }
                    if ((((l_3789 <= (safe_sub_func_int16_t_s_s((0x931ABD91L > (l_3793 = l_3792[1][0])), (l_3796 | (l_2674 == (l_145 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_s(l_2465, 1)), 5)), j)))))))) > (~(((g_172[5] ^ (safe_mod_func_uint8_t_u_u((~l_3775), l_3807[1]))) > l_3808) && g_103))) <= 0x50BC1107L))
                    {
                        g_115 = (g_247 = (0x9D645515L | (l_3792[1][3] && (l_3792[1][2] = ((+g_361) <= g_1129)))));
                    }
                    else
                    {
                        l_3812 = (j = (0L & ((g_315 | ((((g_1129 || ((g_2177[1][1][3] = (l_3808 == (g_188 = (65535UL != (((g_315 = l_3796) < ((((safe_unary_minus_func_uint8_t_u(((g_1460 ^ ((+l_3573[1]) != g_103)) > g_1460))) <= 8L) & j) && 0x17F2086DL)) >= g_359[9][0]))))) != l_3792[0][1])) >= g_3258) >= 0xB60DL) == 0x653A7DA3L)) != l_3262)));
                    }
                }
            }
            for (l_3151 = 0; (l_3151 <= 1); l_3151 += 1)
            {
                int16_t l_3827 = 0xA98EL;
                int32_t l_3837 = 0xC79C192DL;
                uint8_t l_3870 = 251UL;
                int32_t l_3892 = 0x9B48DECCL;
                uint32_t l_3910 = 1UL;
                int8_t l_3927 = 0x16L;
                for (l_3534 = 0; (l_3534 <= 5); l_3534 += 1)
                {
                    int32_t l_3828 = 0x3079516EL;
                    int i;
                    l_3828 = (l_3827 = (g_2352[(l_3151 + 4)] ^ (safe_mod_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u((safe_add_func_int16_t_s_s((!g_1215[(l_3151 + 4)]), ((g_361 = 3L) >= (((l_3822 = 1L) >= ((safe_sub_func_int8_t_s_s(0L, (safe_lshift_func_int8_t_s_u(0x39L, 4)))) != l_3573[1])) ^ ((0x2E9DL != l_3807[0]) || g_1129))))), g_543[1])), 0x755FL)) <= g_172[4]), g_2177[1][3][3]))));
                    for (g_188 = 0; (g_188 <= 1); g_188 += 1)
                    {
                        int i, j, k;
                        l_3732 = ((safe_rshift_func_int16_t_s_s(((((-1L) == ((((safe_sub_func_int32_t_s_s(0x814AF06EL, ((safe_mod_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(((l_3755[l_3151][l_3151][(l_3151 + 4)] != l_3837) <= (safe_unary_minus_func_uint16_t_u(l_3399))), g_361)), l_3732)) < (g_315 = (((safe_mod_func_uint32_t_u_u(((g_3258 & (safe_lshift_func_uint8_t_u_s((safe_add_func_uint32_t_u_u(0xFCA458E4L, 0xFAFCB658L)), l_3828))) && 4294967290UL), g_172[3])) | (-1L)) == g_2352[(l_3151 + 4)]))))) | 0x96617425L) && g_22) & g_359[9][0])) & 0UL) <= 1UL), 5)) || 0x45L);
                        return g_115;
                    }
                }
                for (g_103 = 10; (g_103 != 50); ++g_103)
                {
                    uint32_t l_3851 = 18446744073709551615UL;
                    int8_t l_3871 = 3L;
                    uint32_t l_3897[8][4][7] = {{{18446744073709551612UL,0xE1836138L,0x850D52E1L,4UL,18446744073709551612UL,18446744073709551615UL,18446744073709551615UL},{0x66203650L,18446744073709551612UL,6UL,18446744073709551612UL,0x66203650L,0x325F3AE1L,4UL},{18446744073709551606UL,0x19A3FC88L,18446744073709551615UL,0x43272F40L,0x3D0A099DL,1UL,0x66203650L},{18446744073709551614UL,18446744073709551606UL,0UL,18446744073709551614UL,18446744073709551612UL,0UL,0UL}},{{18446744073709551606UL,0x43272F40L,6UL,1UL,18446744073709551606UL,18446744073709551615UL,1UL},{0x66203650L,1UL,0x3D0A099DL,0x43272F40L,18446744073709551615UL,0x19A3FC88L,18446744073709551606UL},{1UL,0x850D52E1L,0x3D0A099DL,18446744073709551615UL,0x2C9ACB3CL,18446744073709551615UL,0x3D0A099DL},{18446744073709551612UL,18446744073709551612UL,6UL,0xA92A9589L,0xFD09A0FAL,18446744073709551606UL,4UL}},{{0xA92A9589L,18446744073709551615UL,0UL,0UL,0x19A3FC88L,0UL,18446744073709551612UL},{0UL,0x850D52E1L,18446744073709551615UL,0x3D0A099DL,0xFD09A0FAL,0UL,0xB93E9277L},{18446744073709551606UL,4UL,6UL,18446744073709551612UL,0x2C9ACB3CL,0x333F6AB0L,18446744073709551606UL},{0xA92A9589L,0UL,0x1077E5E4L,0x66203650L,18446744073709551615UL,18446744073709551606UL,18446744073709551606UL}},{{18446744073709551615UL,18446744073709551606UL,0x19A3FC88L,0x19A3FC88L,18446744073709551606UL,18446744073709551615UL,0xB93E9277L},{4UL,0UL,0x7FF5CEFEL,0xA92A9589L,18446744073709551612UL,0x4DEDE24EL,18446744073709551612UL},{0x66203650L,18446744073709551615UL,0x37F1B27FL,18446744073709551612UL,0x3D0A099DL,18446744073709551606UL,4UL},{0UL,0UL,18446744073709551615UL,0UL,0x66203650L,1UL,0x3D0A099DL}},{{1UL,18446744073709551606UL,18446744073709551615UL,1UL,18446744073709551612UL,0x87551765L,18446744073709551606UL},{18446744073709551606UL,0UL,18446744073709551615UL,1UL,0UL,0UL,1UL},{0x3D0A099DL,4UL,0x3D0A099DL,0UL,18446744073709551612UL,0x19A3FC88L,0UL},{4UL,0x850D52E1L,0xE1836138L,18446744073709551612UL,0x2C9ACB3CL,6UL,0x66203650L}},{{18446744073709551612UL,18446744073709551615UL,18446744073709551615UL,0xA92A9589L,0x1077E5E4L,0x19A3FC88L,4UL},{0xB93E9277L,18446744073709551612UL,0UL,0x19A3FC88L,0UL,0UL,18446744073709551615UL},{18446744073709551606UL,0x850D52E1L,0x4DEDE24EL,0x66203650L,0xFD09A0FAL,0x87551765L,0xA92A9589L},{18446744073709551606UL,1UL,0x37F1B27FL,18446744073709551612UL,0x37F1B27FL,1UL,18446744073709551606UL}},{{0xB93E9277L,0x43272F40L,0x1077E5E4L,0x3D0A099DL,18446744073709551612UL,18446744073709551606UL,0UL},{18446744073709551612UL,18446744073709551606UL,18446744073709551606UL,0UL,18446744073709551606UL,0x4DEDE24EL,0xA92A9589L},{4UL,0x19A3FC88L,0x1077E5E4L,0xA92A9589L,18446744073709551615UL,18446744073709551615UL,18446744073709551612UL},{0x3D0A099DL,18446744073709551612UL,0x37F1B27FL,18446744073709551615UL,0x66203650L,18446744073709551606UL,0UL}},{{0x3D0A099DL,0UL,18446744073709551612UL,18446744073709551606UL,0x19A3FC88L,0xA92A9589L,0x19A3FC88L},{18446744073709551615UL,0x32647471L,0x32647471L,18446744073709551615UL,0x333F6AB0L,0x325F3AE1L,0x3D0A099DL},{0xE1836138L,18446744073709551606UL,0x333F6AB0L,0x4DEDE24EL,18446744073709551614UL,0x32647471L,0x4DEDE24EL},{0x19A3FC88L,0xB93E9277L,0UL,18446744073709551606UL,18446744073709551615UL,18446744073709551606UL,0x3D0A099DL}}};
                    int32_t l_3916 = (-1L);
                    int i, j, k;
                    if ((((((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((l_3851 != (((g_361 = (l_3812 = (g_361 = (-7L)))) & ((0x1404L == 0xBA1BL) <= ((-8L) ^ (((l_3872 = (safe_rshift_func_int16_t_s_u((g_115 && (safe_mod_func_uint16_t_u_u((((((safe_sub_func_int32_t_s_s((safe_add_func_int32_t_s_s(((safe_mod_func_int16_t_s_s((p_50 = (((((l_3851 ^ (safe_mod_func_int32_t_s_s((safe_add_func_uint32_t_u_u(g_543[1], (safe_mod_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((0x6EL >= g_172[4]), l_3870)), g_866[4][9])))), l_201))) < 0xBD537FA9L) > 0UL) | l_3851) < 65532UL)), 8L)) | g_247), l_2408[1][0])), j)) > g_217) > l_3822) | l_3424[1][1][4]) && l_3871), 1L))), l_3808))) == (-5L)) | l_3873)))) & l_3808)), 2)), 0x0BL)) == l_3874[8]) <= g_2352[0]) <= g_2420) >= l_3807[6]))
                    {
                        l_3892 = (safe_sub_func_uint32_t_u_u(((g_161 != (p_50 = (((safe_mod_func_uint8_t_u_u((g_217 & (l_3891 = (safe_rshift_func_int8_t_s_u(((safe_rshift_func_uint16_t_u_s(65534UL, 15)) == (g_813[5][0] = ((safe_add_func_uint8_t_u_u(((((g_359[9][0] && (safe_lshift_func_uint8_t_u_s(l_3780, 2))) <= l_3851) <= g_2352[2]) != 1UL), ((safe_add_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u((g_2420 = l_3796), l_201)) == l_3755[0][0][5]), g_217)) & g_115))) || 0xD0F0L))), l_3871)))), 1L)) & l_2266[3]) < g_2352[4]))) & l_3871), l_3808));
                    }
                    else
                    {
                        return g_1215[3];
                    }
                    for (l_2294 = 0; (l_2294 <= 27); l_2294++)
                    {
                        uint32_t l_3907 = 4294967295UL;
                        l_3808 = g_217;
                        g_115 = ((safe_sub_func_uint32_t_u_u(0xBE8ABD83L, (((g_2177[3][1][9] = (l_3897[2][0][0] = l_201)) ^ (((l_3910 = (((safe_mod_func_int16_t_s_s((safe_add_func_uint16_t_u_u((((((~65535UL) > j) == l_3892) != g_247) < (((safe_rshift_func_int8_t_s_u((safe_sub_func_int8_t_s_s(l_3907, 1L)), 4)) == (l_3908 = (-6L))) < g_103)), l_3851)), l_3909[0][0])) && g_115) <= 0x9386A289L)) > g_2352[2]) >= l_268)) | 0x77F0A1CDL))) < g_3258);
                    }
                    g_115 = (safe_add_func_uint32_t_u_u((g_103 = ((+((((l_3916 = (safe_rshift_func_int8_t_s_u((-10L), 7))) && ((safe_unary_minus_func_int16_t_s((1L && (safe_rshift_func_int16_t_s_u((safe_sub_func_uint32_t_u_u((g_538 < ((g_172[4] >= (0xBEL && (l_2790[4][0] >= ((3L < (safe_sub_func_int8_t_s_s((((safe_sub_func_int16_t_s_s((((((~l_3796) >= l_3927) < l_3732) && g_538) | g_1215[4]), 0x3FC3L)) && 0x9294L) & l_145), p_50))) == g_315)))) == l_3891)), g_115)), g_361))))) == g_217)) & l_88) > g_538)) && l_3910)), g_1460));
                    return l_3780;
                }
                if (g_2177[4][0][3])
                    continue;
            }
        }
        l_3780 = g_949[0][8][6];
        if ((l_88 = (safe_sub_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(3L, 11)), (safe_lshift_func_uint8_t_u_u(g_103, (safe_add_func_int32_t_s_s((l_3937 = (g_247 = (safe_unary_minus_func_int32_t_s((l_3908 = ((4294967288UL > ((g_315 = 0x2816L) | l_3732)) & (g_103 && g_359[9][0]))))))), ((6UL == ((0x973FL <= g_2420) && l_2418[5][4])) > g_359[9][0])))))))))
        {
            l_3772[2][2][0] = i;
            g_247 = (0L & 0x34L);
        }
        else
        {
            int32_t l_3960 = (-4L);
            int8_t l_3991[1][5] = {{(-9L),(-9L),(-9L),(-9L),(-9L)}};
            int32_t l_4020 = 0x4B3E2823L;
            int i, j;
            for (l_3655 = (-28); (l_3655 < 46); ++l_3655)
            {
                int16_t l_3951 = 0x1704L;
                int32_t l_3955[7][7] = {{0x94E9D490L,(-3L),0xF4171F52L,(-3L),0x94E9D490L,0x94E9D490L,(-3L)},{(-1L),0xB5D7E716L,(-1L),0x3C2EED67L,0x3C2EED67L,(-1L),0xB5D7E716L},{(-3L),(-8L),0xF4171F52L,0xF4171F52L,(-8L),(-3L),(-8L)},{(-1L),0x3C2EED67L,0x3C2EED67L,(-1L),0xB5D7E716L,(-1L),0x3C2EED67L},{0x94E9D490L,0x94E9D490L,(-3L),0xF4171F52L,(-3L),0x94E9D490L,0x94E9D490L},{0xCBAC2FE8L,0x3C2EED67L,1L,0x3C2EED67L,0xCBAC2FE8L,0xCBAC2FE8L,0x3C2EED67L},{(-1L),(-8L),(-1L),(-3L),(-3L),(-1L),(-8L)}};
                int8_t l_4032 = 8L;
                int i, j;
                for (l_2674 = 0; (l_2674 >= 29); l_2674++)
                {
                    uint8_t l_3954 = 0xF9L;
                    g_161 = (g_813[2][0] != (safe_add_func_uint32_t_u_u(((l_3807[4] & 1UL) > (safe_lshift_func_uint8_t_u_s((!g_22), 6))), ((0L | (((l_3955[3][0] = (((safe_lshift_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u(l_3951, 12)) & (safe_sub_func_int16_t_s_s(g_315, (g_538 = (1L <= l_88))))), l_3954)) | 0xC3L) && 0L)) || 1UL) & g_3956[2])) != g_2420))));
                }
                for (g_315 = 0; (g_315 > 34); ++g_315)
                {
                    uint32_t l_3973 = 0x4C44CE71L;
                    int8_t l_3988[10] = {(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L),(-1L)};
                    int32_t l_4033 = (-1L);
                    int32_t l_4034 = 0x9751D3BDL;
                    int i;
                    j = ((((l_2290 ^ (g_217 = ((l_3960 | (safe_add_func_int8_t_s_s(0x29L, ((safe_add_func_int8_t_s_s(((safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s(g_361, g_2352[2])), g_949[0][6][1])) == l_3534), ((safe_sub_func_int32_t_s_s(l_201, ((safe_add_func_int16_t_s_s((1L <= g_161), l_3707)) && g_172[6]))) != l_3960))) <= 0x1406L)))) ^ 255UL))) == l_3960) <= l_3973) && l_3951);
                    for (l_3752 = 0; (l_3752 <= 8); l_3752 += 1)
                    {
                        uint8_t l_3986 = 0UL;
                        int32_t l_4009[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_4009[i] = 1L;
                        l_3732 = (j = (l_3988[7] = (safe_add_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((l_3874[l_3752] || 254UL), (safe_rshift_func_int16_t_s_s(l_3873, 11)))) == (((-9L) >= ((((safe_rshift_func_int8_t_s_u(g_161, (l_3960 && (safe_rshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u(((g_2177[3][1][9] = (((g_1129 || ((l_3822 && ((0x690DL <= l_3909[0][0]) | l_3986)) | l_3987)) && 0x59DE2E1CL) || 0x0ECC5B70L)) < l_3986), 9)), g_115))))) < l_3874[l_3752]) & l_145) > l_3986)) > l_3973)), 65533UL))));
                        j = (g_543[2] == 4294967295UL);
                        g_115 = (g_247 = (safe_rshift_func_uint8_t_u_u(l_3991[0][2], (l_3807[0] > (safe_rshift_func_uint16_t_u_s((+(0xF87CL < l_3399)), (p_50 = (safe_lshift_func_int16_t_s_u((safe_sub_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u((((+(1UL <= (safe_sub_func_int8_t_s_s(((l_3937 > (((+(l_4009[1] = ((safe_add_func_uint32_t_u_u(l_3874[8], (safe_rshift_func_uint8_t_u_u((l_201 & (l_3991[0][2] && g_361)), l_3874[l_3752])))) ^ g_361))) & g_359[9][0]) >= l_2674)) | g_115), 0x23L)))) == l_268) >= g_2420), l_3988[2])), l_3937)), 6)))))))));
                    }
                    for (l_3116 = 0; (l_3116 < 12); l_3116 = safe_add_func_int32_t_s_s(l_3116, 7))
                    {
                        return l_201;
                    }
                    g_3956[1] = (safe_lshift_func_int16_t_s_s((l_3960 != ((l_3262 = (safe_lshift_func_uint8_t_u_s((safe_rshift_func_uint8_t_u_u((safe_mod_func_int16_t_s_s((l_4020 = (g_543[2] = 0x7667L)), (((safe_add_func_int16_t_s_s((l_3988[6] ^ (l_4034 = (l_4033 = (((safe_sub_func_uint8_t_u_u(g_1129, l_3955[3][0])) & ((safe_add_func_uint16_t_u_u(((1UL >= g_115) || ((safe_unary_minus_func_int16_t_s(g_2177[3][1][9])) | (safe_rshift_func_uint8_t_u_u(((((safe_sub_func_uint32_t_u_u(((((-1L) < g_1129) | 248UL) || l_3991[0][3]), g_315)) > l_3991[0][2]) & l_4032) & l_2674), g_2420)))), g_217)) != g_188)) || 248UL)))), l_3960)) <= 0x3193CC09L) | l_3991[0][1]))), l_3955[4][6])), 0))) || l_4034)), i));
                }
            }
        }
    }
    return l_4035;
}

}
                    g_22 = (l_118 != p_49);
                    }
                    else
                    {
                        return g_4;
                    }
                                                        while ((!l_306) )
{

i += 1;


}
                    for (g_161 = 0; (g_161 == 42); g_161 = safe_add_func_uint32_t_u_u(g_161, 6))
                    {
                        if (p_49)
                            break;
                        l_160[1][0] = g_103;
                        g_188 = ((l_158 && (safe_add_func_uint32_t_u_u((safe_add_func_uint32_t_u_u(p_50, (safe_add_func_uint8_t_u_u(l_104[5][6], (l_160[2][1] = l_158))))), (((safe_sub_func_int32_t_s_s((l_159 = (g_22 = l_79[(l_118 + 3)][g_63][g_63])), (((4294967295UL < (safe_sub_func_int8_t_s_s(p_49, (7L ^ (safe_sub_func_int8_t_s_s((p_50 < g_173), p_50)))))) || g_172[4]) > l_158))) & l_104[5][6]) >= 0x816EFC97L)))) ^ g_83);
                    }
                }
                else
                {
                    int8_t l_204 = (-1L);
                    int32_t l_205 = 0xA341128DL;
                    if ((0xB969A7E2L != (p_49 == (safe_mod_func_int32_t_s_s(p_50, 0x24DCF8C1L)))))
                    {
                        l_193 = (((-1L) <= (safe_lshift_func_int8_t_s_s(g_188, g_63))) > l_160[7][2]);

{
                        g_3484 = g_1129;
                    }

                    l_193 = 0L;
                        if (g_63)
                            break;
                    }
                    else
                    {
                        int32_t l_203 = (-8L);
                        l_104[1][7] = (0x8075L != ((p_50 = l_87) >= (p_49 && (0xAB5394E2L >= 0UL))));
                        g_22 = (((l_88 = (((p_49 | 0UL) < (g_103 && ((l_205 = (((g_173 && p_50) > (safe_sub_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((g_22 > ((safe_mod_func_int16_t_s_s(((g_4 <= (((~l_201) != (((((((+(p_50 > g_173)) && g_173) <= p_50) > 3UL) == p_49) > l_203) >= p_49)) ^ 0xE3DCAB47L)) >= l_204), 0xEE06L)) == 0x9DDDL)), 0xE14EL)) && l_203), 0UL))) <= g_172[4])) == p_49))) && (-2L))) | 0xBAB4L) || 1UL);
                        return g_173;
                    }

for (g_4 = 0; (g_4 <= (-25)); g_4--)
                    {
                        l_193 = g_3261;
                        return g_949[0][6][1];
                    };


                    l_193 = (safe_lshift_func_uint8_t_u_s(((-2L) == (safe_rshift_func_int8_t_s_s((((p_50 & ((safe_add_func_int16_t_s_s((0xE4L || (safe_rshift_func_uint8_t_u_s(g_172[4], g_22))), (l_218 = (g_217 = ((l_117 < 0xAD95808BL) ^ ((safe_rshift_func_int8_t_s_s((safe_unary_minus_func_int16_t_s(g_188)), ((0x4EEEL == 6L) && 0xC3D4A470L))) || p_49)))))) > (-1L))) <= g_115) == l_82), g_22))), 1));
                }
                g_22 = (((-1L) | g_63) > (+l_218));
                g_22 = ((((l_88 = (safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(((0x4A28L >= p_49) || ((g_161 = ((safe_sub_func_uint8_t_u_u(l_218, (safe_rshift_func_uint8_t_u_s(l_82, (+0xA994BE0AL))))) || ((safe_lshift_func_uint8_t_u_u((l_218 != (safe_lshift_func_int8_t_s_s(g_103, 3))), 4)) < ((safe_mod_func_int8_t_s_s(g_173, (safe_lshift_func_uint16_t_u_u(((-1L) <= 1UL), p_50)))) < 0x90L)))) >= g_22)), 7)), p_49))) == 0L) & l_158) < 0x193FL);
            }
        }
        if (((g_188 <= 0L) ^ 0xA2L))
        {
            uint16_t l_237 = 65526UL;
            int32_t l_260[5];
            int32_t l_261 = 4L;
            uint32_t l_274[7][10] = {{0x9183A3A1L,0xD0E7BC49L,1UL,4294967295UL,0x4EE4472DL,1UL,0xFA7611F6L,0x0EC4D18DL,0x0EC4D18DL,0xFA7611F6L},{4294967295UL,0x9183A3A1L,4294967295UL,4294967295UL,0x9183A3A1L,4294967295UL,4294967295UL,1UL,0xBC1D7A0BL,0UL},{0UL,0x0EC4D18DL,0xD0E7BC49L,1UL,1UL,0UL,4294967295UL,0UL,1UL,1UL},{0UL,0UL,0UL,4294967292UL,0xFA7611F6L,4294967295UL,1UL,0x4EE4472DL,0xD0E7BC49L,1UL},{4294967295UL,1UL,0x4EE4472DL,0xD0E7BC49L,1UL,1UL,0xD0E7BC49L,0x4EE4472DL,1UL,4294967295UL},{0x9183A3A1L,0x45722FB2L,0UL,0x0EC4D18DL,0xD0E7BC49L,1UL,1UL,0UL,4294967295UL,0UL},{0xBC1D7A0BL,0UL,0xD0E7BC49L,0x45722FB2L,0xD0E7BC49L,0UL,0xBC1D7A0BL,1UL,4294967295UL,4294967295UL}};
            int16_t l_277[9][10][2] = {{{1L,8L},{0x6338L,0L},{(-1L),7L},{0x35ABL,1L},{(-6L),0L},{0x372EL,0x97CDL},{1L,0xDD2AL},{0L,0x35ABL},{(-1L),0L},{3L,0x78A7L}},{{8L,3L},{0x38AEL,0x78A7L},{0x795CL,1L},{0x0659L,0xDD2AL},{1L,1L},{0xF30DL,0x12BCL},{8L,(-7L)},{7L,0xA12CL},{(-1L),1L},{0x78A7L,(-1L)}},{{0x12BCL,(-1L)},{0x78A7L,1L},{(-1L),0xA12CL},{7L,(-7L)},{8L,0x12BCL},{0xF30DL,1L},{1L,0xDD2AL},{0x0659L,1L},{0x795CL,0x78A7L},{0x38AEL,7L}},{{0x0659L,0L},{7L,1L},{7L,0x372EL},{8L,7L},{(-7L),0xA12CL},{1L,8L},{0x78A7L,0x2EBBL},{0x372EL,(-1L)},{0x679DL,8L},{(-1L),(-4L)}},{{(-7L),(-7L)},{1L,0x372EL},{0xF30DL,1L},{7L,0xDD2AL},{0L,7L},{0x795CL,0x679DL},{0x795CL,7L},{0L,0xDD2AL},{7L,1L},{0xF30DL,0x372EL}},{{1L,(-7L)},{(-7L),(-4L)},{(-1L),8L},{0x679DL,(-1L)},{0x372EL,0x2EBBL},{0x78A7L,8L},{1L,0xA12CL},{(-7L),7L},{8L,0x372EL},{7L,1L}},{{7L,0L},{0x0659L,7L},{0x38AEL,0x78A7L},{0x795CL,1L},{0x0659L,0xDD2AL},{1L,1L},{0xF30DL,0x12BCL},{8L,(-7L)},{7L,0xA12CL},{(-1L),1L}},{{0x78A7L,(-1L)},{0x12BCL,(-1L)},{0x78A7L,1L},{(-1L),0xA12CL},{7L,(-7L)},{8L,0x12BCL},{0xF30DL,1L},{1L,0xDD2AL},{0x0659L,1L},{0x795CL,0x78A7L}},{{0x38AEL,7L},{0x0659L,0L},{7L,1L},{7L,0x372EL},{8L,7L},{(-7L),0xA12CL},{1L,8L},{0x78A7L,0x2EBBL},{0x372EL,(-1L)},{0x679DL,8L}}};
            int i, j, k;
            for (i = 0; i < 5; i++)
                l_260[i] = 0L;
            l_263[2][0] = (l_237 != (l_262 = (((0xF55769E9L != (l_80 = (safe_rshift_func_uint16_t_u_u(((l_261 = (safe_add_func_int32_t_s_s((+l_237), (l_104[5][6] = ((l_260[0] = (safe_rshift_func_uint16_t_u_s((safe_add_func_uint16_t_u_u((g_247 || (!(safe_mod_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((l_117 ^ (safe_mod_func_uint8_t_u_u((safe_sub_func_int16_t_s_s((safe_add_func_uint16_t_u_u(0x7869L, (l_259 | 0L))), 0x508AL)), p_50))), 1UL)), l_104[0][6])))), g_63)), g_188))) == 0x2AFEL))))) == g_161), l_259)))) <= p_50) != 0x68L)));
            l_104[5][6] = (safe_add_func_uint32_t_u_u(((((((safe_add_func_int8_t_s_s(l_268, p_49)) >= p_50) >= (g_83 = (safe_unary_minus_func_uint32_t_u(g_172[4])))) > (((safe_lshift_func_int8_t_s_s((0xF631L < (((0x9B79L < (safe_rshift_func_uint16_t_u_u((l_274[4][1] < (l_117 = ((safe_rshift_func_int8_t_s_u(l_277[8][8][0], p_49)) == 0xB7205401L))), g_173))) >= g_172[4]) || g_172[6])), 1)) != g_172[1]) | l_237)) == l_263[0][1]) >= p_49), 0UL));
        }
        else
        {
            int16_t l_295 = 0x4B2EL;
            int32_t l_305 = 0L;
            g_247 = (safe_sub_func_int8_t_s_s((((~(safe_rshift_func_uint8_t_u_s(((((g_173 = ((safe_add_func_int8_t_s_s(p_50, (safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s((safe_rshift_func_int8_t_s_s((0x6986D460L | ((((safe_mod_func_int16_t_s_s((((safe_rshift_func_int8_t_s_s(l_295, 3)) > ((0x1AC507ADL >= (((safe_unary_minus_func_uint8_t_u((safe_add_func_uint8_t_u_u((l_262 = (safe_lshift_func_int16_t_s_u(((250UL && (l_104[5][6] = ((l_305 = ((safe_add_func_int32_t_s_s((safe_mod_func_int8_t_s_s(g_22, p_50)), p_49)) & ((p_49 == p_50) ^ p_49))) ^ p_49))) >= l_262), 3))), 0x05L)))) >= l_87) || 0x4A90L)) < l_268)) < g_247), 65535UL)) < 0x0D65L) & 0x98E9L) >= l_201)), 3)), 2)) > 0x7EF9L), g_217)))) >= p_49)) <= 0L) != l_306) || 0xBECC66A6L), l_259))) >= p_49) >= p_50), p_49));
        }
                                       int32_t BLgLgWl_117 = (~(((~((~(((~((g_83 || ((g_161 - g_115) ^ g_188)))) / (~(g_173))))))) + (((~(l_117)) | (~(g_217))) | (g_103 & (g_63 >> g_22))))));
int16_t BLgLgXg_188 = (~(((~((g_173 | g_115))) % (~((((~((~((~(g_83)))))) + (g_103 & ((g_188 & BLgLgWl_117) & g_63))) / (((g_161 << g_22) | (~(l_117))) & g_217)))))));
uint8_t BLgLgYg_217 = (~((((((g_188 | g_63) + (~(g_173))) + (~(g_103))) << ((((g_217 || (BLgLgWl_117 ^ (g_115 >> BLgLgXg_188))) && l_117) && g_22) / (~(g_161)))) - (~(g_83)))));
int8_t BLgLgZg_83 = (~(((((g_188 & g_83) | (BLgLgXg_188 - g_22)) | (((g_173 || BLgLgYg_217) ^ (~((~(g_115))))) / (~((l_117 - g_63))))) || (~(((BLgLgWl_117 || g_217) || (g_161 - (~(g_103)))))))));
int32_t BLgLg_g_22 = (~(((l_117 << (~((~(g_63))))) | (~(((~((~(((~((~((~((g_173 & g_115))))))) / ((~((((~((g_188 & (~(BLgLgYg_217))))) - ((BLgLgZg_83 & g_22) & g_217)) && (~((BLgLgXg_188 / (~(g_103)))))))) || (~(BLgLgWl_117)))))))) + (~((~((g_161 & g_83)))))))))));
uint32_t BLgLg0g_161 = (~((((~((BLgLgWl_117 & (~(g_63))))) ^ (~(((~(g_115)) % (~((((g_161 & (BLgLg_g_22 || g_173)) | (~(g_22))) || (~(BLgLgYg_217))))))))) & (~((~(((g_103 & (~(g_83))) - ((~((l_117 | (~(((~((BLgLgXg_188 + g_188))) ^ g_217)))))) & (~(BLgLgZg_83)))))))))));
LABEL_LgLg1: if(((BLgLg_g_22 && g_115) && (l_117 < g_173))){
BLgLgWl_117 = l_117;
BLgLgXg_188 = g_188;
BLgLgYg_217 = g_217;
BLgLgZg_83 = g_83;
BLgLg_g_22 = g_22;
LABEL_LgLg2: BLgLg0g_161 = g_161;
l_117 = (~(((((~((~(((BLgLgWl_117 || BLgLgYg_217) + g_103))))) || ((~(g_83)) | (~((~((~((~(BLgLgZg_83)))))))))) ^ (~((((~(g_161)) / ((~(g_217)) - g_188)) + ((~(((~(BLgLg_g_22)) ^ l_117))) & ((g_63 | (~(BLgLgXg_188))) | ((~((g_173 || g_22))) / (~(BLgLg0g_161))))))))) % (~((~((~(g_115)))))))));
g_188 = (~(((~(((~(((~(g_217)) ^ ((~(((~(g_63)) - g_188))) || ((~(BLgLg_g_22)) | (~(((~(BLgLgWl_117)) / (~((g_173 - l_117))))))))))) & ((g_161 / BLgLgZg_83) && (BLgLgXg_188 % BLgLgYg_217))))) && ((~(((g_103 / g_83) ^ g_115))) & (g_22 | (~(BLgLg0g_161)))))));
g_217 = (~(((~(((~((((g_173 + (~(BLgLgZg_83))) | BLgLg_g_22) >> (BLgLgWl_117 || g_103)))) | (~(((g_63 + ((~(BLgLg0g_161)) ^ g_115)) & ((~(g_83)) % BLgLgYg_217))))))) << (~((~(((~((l_117 && g_217))) & ((g_188 + (~(g_22))) && (BLgLgXg_188 || g_161))))))))));
g_83 = (~(((~((~(((((~(BLgLgYg_217)) || BLgLgZg_83) - (~(g_63))) & (~((~(g_83))))))))) % ((~((~((((BLgLg0g_161 % g_188) - ((~(BLgLgXg_188)) / g_173)) / (~((~((~((l_117 - BLgLgWl_117)))))))))))) || ((~((BLgLg_g_22 / (~(g_115))))) | (~(((g_217 >> (g_22 << g_161)) | (~((~(g_103))))))))))));
g_22 = (~(((~((g_22 & BLgLgWl_117))) ^ (~((((BLgLg0g_161 | g_115) / ((((~(g_103)) << ((~(l_117)) || ((~(BLgLgZg_83)) - g_217))) & (~((~(g_161))))) | (BLgLg_g_22 || (~(BLgLgXg_188))))) & ((~((~(BLgLgYg_217)))) + ((g_63 && (g_188 || g_173)) && g_83))))))));
g_161 = (~(((~((((BLgLg_g_22 || (~(BLgLgWl_117))) >> (~((~(g_115))))) % ((~((~((g_161 - (g_103 || g_217)))))) / ((~(g_22)) - BLgLgYg_217))))) >> (~((g_83 + ((g_63 && g_188) << ((g_173 && l_117) << ((~((BLgLgZg_83 % BLgLgXg_188))) - BLgLg0g_161)))))))));
if((BLgLgYg_217 < BLgLgWl_117)){
printf("l_117=%lld\n", (long long)l_117);
l_117 = (~((((((~(g_161)) + ((~((BLgLg0g_161 % l_117))) / g_188)) && (g_63 / (g_173 ^ (BLgLg_g_22 << BLgLgYg_217)))) - (~((((~(g_83)) << g_217) | (~((~((~(BLgLgWl_117)))))))))) >> (g_103 && (((g_115 >> BLgLgZg_83) >> g_22) & BLgLgXg_188)))));
continue;
}
if((!BLgLgZg_83)){
printf("g_188=%lld\n", (long long)g_188);
break;
}
if((g_161 > g_173)){
printf("g_217=%llu\n", (unsigned long long)g_217);
break;
}
if((g_63>0)){
printf("g_83=%lld\n", (long long)g_83);
continue;
}
if(!((g_103<=1U))){
printf("g_22=%lld\n", (long long)g_22);
break;
}
if(!((g_173 || (g_173 > BLgLgWl_117)))){
printf("g_161=%llu\n", (unsigned long long)g_161);
g_188 = (~(((~(((g_188 << ((g_83 << g_173) | (g_22 >> (BLgLgXg_188 || BLgLgWl_117)))) % ((((~(l_117)) || (~((~(g_115))))) << (~(BLgLg_g_22))) - ((~((g_161 + g_217))) && BLgLg0g_161))))) + (~(((~(BLgLgZg_83)) | (~((BLgLgYg_217 | (g_103 >> g_63))))))))));
BLgLgYg_217 = (~(((~(((g_115 & g_22) / g_188))) - (((~((g_161 << g_217))) | (~((~(((~(BLgLgXg_188)) & ((BLgLg_g_22 >> BLgLgYg_217) % (~((~((BLgLgWl_117 | g_173)))))))))))) && ((l_117 | g_83) & ((g_63 % (~((BLgLgZg_83 >> BLgLg0g_161)))) - (~(g_103))))))));
}
}
l_117 = BLgLgWl_117;
g_188 = BLgLgXg_188;
g_217 = BLgLgYg_217;
g_83 = BLgLgZg_83;
g_22 = BLgLg_g_22;
g_161 = BLgLg0g_161;

                    l_104[5][5] = (l_263[0][0] = ((safe_add_func_int32_t_s_s(p_50, l_117)) == ((1UL || 0x8C5AC05FL) | g_172[5])));
    }
    return l_80;
}







static int8_t func_57(int16_t p_58, uint32_t p_59, uint32_t p_60, int32_t p_61)
{
    uint8_t l_71 = 0UL;
    int32_t l_75[2][3][6] = {{{(-2L),(-2L),0L,0xA11B98B5L,3L,(-1L)},{1L,0xD8A5C089L,0L,0L,0x473F1902L,0L},{0L,1L,0L,4L,(-2L),(-1L)}},{{0x2A83C5EEL,4L,0L,0xAF0CFC20L,7L,7L},{0xAF0CFC20L,7L,7L,0xAF0CFC20L,0L,4L},{0x2A83C5EEL,(-1L),(-2L),0xD8A5C089L,(-1L),0xA11B98B5L}}};
    uint16_t l_78[8] = {0x58C9L,0x2F22L,0x58C9L,0x2F22L,0x58C9L,0x2F22L,0x58C9L,0x2F22L};
    int i, j, k;
                                        if (((g_63>65535) && (g_63 < l_71)) )
{

g_1460 += 1;


}
      for (p_59 = 0; (p_59 > 12); p_59 = safe_add_func_uint16_t_u_u(p_59, 7))
    {
        uint32_t l_72[6] = {18446744073709551606UL,18446744073709551606UL,0xEFD7F9B6L,18446744073709551606UL,18446744073709551606UL,0xEFD7F9B6L};
        int i;
        g_22 = ((g_63 < ((((safe_rshift_func_uint16_t_u_s(((((l_72[5] = (~l_71)) != g_63) | ((0xE2L < (safe_rshift_func_uint16_t_u_s(((0L && 0UL) ^ (7L > (((g_22 ^ l_71) == g_22) < (-1L)))), 15))) == 0x2DL)) & p_60), 8)) ^ 0x12ECL) | l_71) <= 0x319F56C0L)) >= 255UL);
    }
    for (g_22 = 1; (g_22 >= 0); g_22 -= 1)
    {
        return l_75[0][0][0];
    }
    l_78[4] = (safe_mod_func_int32_t_s_s(g_22, p_59));

{
                    j = 0x5D495BDFL;
                }

      return p_60;
}





int main (int argc, char* argv[])
{
    int i, j, k;
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
    transparent_crc(g_4, "g_4", print_hash_value);
    transparent_crc(g_12, "g_12", print_hash_value);
    transparent_crc(g_22, "g_22", print_hash_value);
    transparent_crc(g_63, "g_63", print_hash_value);
    transparent_crc(g_83, "g_83", print_hash_value);
    transparent_crc(g_103, "g_103", print_hash_value);
    transparent_crc(g_115, "g_115", print_hash_value);
    transparent_crc(g_161, "g_161", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_172[i], "g_172[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_173, "g_173", print_hash_value);
    transparent_crc(g_188, "g_188", print_hash_value);
    transparent_crc(g_217, "g_217", print_hash_value);
    transparent_crc(g_247, "g_247", print_hash_value);
    transparent_crc(g_315, "g_315", print_hash_value);
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 7; j++)
        {
            transparent_crc(g_359[i][j], "g_359[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_361, "g_361", print_hash_value);
    transparent_crc(g_538, "g_538", print_hash_value);
    transparent_crc(g_540, "g_540", print_hash_value);
    transparent_crc(g_541, "g_541", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_543[i], "g_543[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 1; j++)
        {
            transparent_crc(g_813[i][j], "g_813[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 10; j++)
        {
            transparent_crc(g_866[i][j], "g_866[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 9; j++)
        {
            for (k = 0; k < 9; k++)
            {
                transparent_crc(g_949[i][j][k], "g_949[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_974, "g_974", print_hash_value);
    transparent_crc(g_1129, "g_1129", print_hash_value);
    for (i = 0; i < 6; i++)
    {
        transparent_crc(g_1215[i], "g_1215[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_1460, "g_1460", print_hash_value);
    transparent_crc(g_1524, "g_1524", print_hash_value);
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 10; k++)
            {
                transparent_crc(g_2177[i][j][k], "g_2177[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_2352[i], "g_2352[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_2420, "g_2420", print_hash_value);
    transparent_crc(g_2476, "g_2476", print_hash_value);
    transparent_crc(g_2576, "g_2576", print_hash_value);
    transparent_crc(g_2598, "g_2598", print_hash_value);
    transparent_crc(g_2710, "g_2710", print_hash_value);
    transparent_crc(g_3152, "g_3152", print_hash_value);
    transparent_crc(g_3258, "g_3258", print_hash_value);
    transparent_crc(g_3261, "g_3261", print_hash_value);
    transparent_crc(g_3409, "g_3409", print_hash_value);
    transparent_crc(g_3421, "g_3421", print_hash_value);
    transparent_crc(g_3484, "g_3484", print_hash_value);
    transparent_crc(g_3781, "g_3781", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        transparent_crc(g_3956[i], "g_3956[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_3957, "g_3957", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

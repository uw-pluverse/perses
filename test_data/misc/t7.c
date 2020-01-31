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
static float
(safe_add_func_float_f_f)(float sf1, float sf2 )
{
 
  return

    (fabsf((0.5f * sf1) + (0.5f * sf2)) > (0.5f * 3.40282346638528859811704183484516925e+38F)) ?
    (sf1) :

    (sf1 + sf2);
}

static float
(safe_sub_func_float_f_f)(float sf1, float sf2 )
{
 
  return

    (fabsf((0.5f * sf1) - (0.5f * sf2)) > (0.5f * 3.40282346638528859811704183484516925e+38F)) ?
    (sf1) :

    (sf1 - sf2);
}

static float
(safe_mul_func_float_f_f)(float sf1, float sf2 )
{
 
  return

    (fabsf((0x1.0p-100f * sf1) * (0x1.0p-28f * sf2)) > (0x1.0p-100f * (0x1.0p-28f * 3.40282346638528859811704183484516925e+38F))) ?
    (sf1) :

    (sf1 * sf2);
}

static float
(safe_div_func_float_f_f)(float sf1, float sf2 )
{
 
  return

    ((fabsf(sf2) < 1.0f) && (((sf2 == 0.0f) || (fabsf((0x1.0p-49f * sf1) / (0x1.0p100f * sf2))) > (0x1.0p-100f * (0x1.0p-49f * 3.40282346638528859811704183484516925e+38F))))) ?
    (sf1) :

    (sf1 / sf2);
}




static double
(safe_add_func_double_f_f)(double sf1, double sf2 )
{
 
  return

    (fabs((0.5 * sf1) + (0.5 * sf2)) > (0.5 * ((double)1.79769313486231570814527423731704357e+308L))) ?
    (sf1) :

    (sf1 + sf2);
}

static double
(safe_sub_func_double_f_f)(double sf1, double sf2 )
{
 
  return

    (fabs((0.5 * sf1) - (0.5 * sf2)) > (0.5 * ((double)1.79769313486231570814527423731704357e+308L))) ?
    (sf1) :

    (sf1 - sf2);
}

static double
(safe_mul_func_double_f_f)(double sf1, double sf2 )
{
 
  return

    (fabs((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) > (0x1.0p-100 * (0x1.0p-924 * ((double)1.79769313486231570814527423731704357e+308L)))) ?
    (sf1) :

    (sf1 * sf2);
}

static double
(safe_div_func_double_f_f)(double sf1, double sf2 )
{
 
  return

    ((fabs(sf2) < 1.0) && (((sf2 == 0.0) || (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) > (0x1.0p-100 * (0x1.0p-974 * ((double)1.79769313486231570814527423731704357e+308L)))))) ?
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
crc32_8bytes (uint32_t val)
{
 crc32_byte ((val>>0) & 0xff);
 crc32_byte ((val>>8) & 0xff);
 crc32_byte ((val>>16) & 0xff);
 crc32_byte ((val>>24) & 0xff);
}

static void
transparent_crc (uint32_t val, char* vname, int flag)
{
 crc32_8bytes(val);
 if (flag) {
    printf("...checksum after hashing %s : %X\n", vname, crc32_context ^ 0xFFFFFFFFU);
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







void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);static long __undefined;



static uint32_t g_8 = 0xA3A11C15L;
static uint16_t g_43 = 0x1241L;
static int16_t g_123 = 0x1D3DL;
static int32_t g_128 = 0xBF9D6D6FL;
static int16_t g_129 = 1L;
static uint16_t g_130 = 1UL;
static int16_t g_152[9][7] = {{0xCF18L, 0x5174L, 0L, 0xB2AAL, 0xB2AAL, 0L, 0x5174L}, {0xCF18L, 0x5174L, 0L, 0xB2AAL, 0xB2AAL, 0L, 0x5174L}, {0xCF18L, 0x5174L, 0L, 0xB2AAL, 0xB2AAL, 0L, 0x5174L}, {0xCF18L, 0x5174L, 0L, 0xB2AAL, 0xB2AAL, 0L, 0x5174L}, {0xCF18L, 0x5174L, 0L, 0xB2AAL, 0xB2AAL, 0L, 0x5174L}, {0xCF18L, 0x5174L, 0L, 0xB2AAL, 0xB2AAL, 0L, 0x5174L}, {0xCF18L, 0x5174L, 0L, 0xB2AAL, 0xB2AAL, 0L, 0x5174L}, {0xCF18L, 0x5174L, 0L, 0xB2AAL, 0xB2AAL, 0L, 0x5174L}, {0xCF18L, 0x5174L, 0L, 0xB2AAL, 0xB2AAL, 0L, 0x5174L}};
static int32_t g_184[10][4][3] = {{{0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}}, {{0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}}, {{0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}}, {{0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}}, {{0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}}, {{0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}}, {{0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}}, {{0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}}, {{0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}}, {{0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}, {0xD6AADDF2L, 0xE2578D85L, 0x969F2998L}}};
static int32_t g_185[8][1][8] = {{{0x0667DD3FL, 1L, 0xC580CF4DL, 0x88D9D7E8L, 0x07BE3842L, (-1L), 0L, (-9L)}}, {{0x0667DD3FL, 1L, 0xC580CF4DL, 0x88D9D7E8L, 0x07BE3842L, (-1L), 0L, (-9L)}}, {{0x0667DD3FL, 1L, 0xC580CF4DL, 0x88D9D7E8L, 0x07BE3842L, (-1L), 0L, (-9L)}}, {{0x0667DD3FL, 1L, 0xC580CF4DL, 0x88D9D7E8L, 0x07BE3842L, (-1L), 0L, (-9L)}}, {{0x0667DD3FL, 1L, 0xC580CF4DL, 0x88D9D7E8L, 0x07BE3842L, (-1L), 0L, (-9L)}}, {{0x0667DD3FL, 1L, 0xC580CF4DL, 0x88D9D7E8L, 0x07BE3842L, (-1L), 0L, (-9L)}}, {{0x0667DD3FL, 1L, 0xC580CF4DL, 0x88D9D7E8L, 0x07BE3842L, (-1L), 0L, (-9L)}}, {{0x0667DD3FL, 1L, 0xC580CF4DL, 0x88D9D7E8L, 0x07BE3842L, (-1L), 0L, (-9L)}}};
static uint8_t g_186 = 0x09L;
static uint8_t g_211[2] = {0x5DL, 0x5DL};
static int32_t g_256 = 0xD5119C74L;
static int16_t g_257 = 0x15A4L;
static uint16_t g_259 = 65532UL;
static uint32_t g_271 = 4294967292UL;
static int16_t g_298 = 0L;
static uint32_t g_300 = 1UL;
static int32_t g_331[9] = {1L, 1L, 1L, 1L, 1L, 1L, 1L, 1L, 1L};
static int8_t g_332 = 0x54L;
static uint16_t g_348[2][10][1] = {{{0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}}, {{0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}, {0x23E2L}}};
static int32_t g_392[4][10] = {{0xB09E32A8L, 0x61FED368L, (-3L), (-2L), 0x61FED368L, 0x0FD333E6L, 0x61FED368L, (-2L), (-3L), 0x61FED368L}, {0xB09E32A8L, 0x61FED368L, (-3L), (-2L), 0x61FED368L, 0x0FD333E6L, 0x61FED368L, (-2L), (-3L), 0x61FED368L}, {0xB09E32A8L, 0x61FED368L, (-3L), (-2L), 0x61FED368L, 0x0FD333E6L, 0x61FED368L, (-2L), (-3L), 0x61FED368L}, {0xB09E32A8L, 0x61FED368L, (-3L), (-2L), 0x61FED368L, 0x0FD333E6L, 0x61FED368L, (-2L), (-3L), 0x61FED368L}};
static uint8_t g_483 = 1UL;
static uint16_t g_489 = 0xD773L;
static uint32_t g_497[1][10] = {{1UL, 0xBA7ED337L, 4294967289UL, 4294967289UL, 0xBA7ED337L, 1UL, 0xBA7ED337L, 4294967289UL, 4294967289UL, 0xBA7ED337L}};
static int8_t g_498 = 0xA6L;
static uint32_t g_499 = 0UL;
static uint32_t g_570 = 0x5C3FAB13L;
static uint16_t g_670 = 65529UL;
static uint32_t g_705 = 1UL;
static int32_t g_820 = 0xA88D7592L;
static uint16_t g_1129 = 65530UL;
static int32_t g_1232 = 0x14215CECL;
static int16_t g_1302 = 0xA67AL;
static int32_t g_1303[8] = {6L, 0x7DE31289L, 6L, 0x7DE31289L, 6L, 0x7DE31289L, 6L, 0x7DE31289L};
static int32_t g_1371 = 1L;
static int8_t g_1482 = 0x47L;
static uint32_t g_1483[8] = {0x1C958B2DL, 0x8AD53843L, 0x1C958B2DL, 0x8AD53843L, 0x1C958B2DL, 0x8AD53843L, 0x1C958B2DL, 0x8AD53843L};
static int16_t g_1596 = (-5L);
static int16_t g_1676[10] = {1L, 7L, 1L, 7L, 1L, 7L, 1L, 7L, 1L, 7L};
static uint32_t g_1752 = 0xABD3DA8CL;
static int32_t g_1850 = 0x7512D236L;
static int32_t g_1925 = 5L;
static uint8_t g_2108[10][4] = {{0x73L, 1UL, 0x0CL, 255UL}, {0x73L, 1UL, 0x0CL, 255UL}, {0x73L, 1UL, 0x0CL, 255UL}, {0x73L, 1UL, 0x0CL, 255UL}, {0x73L, 1UL, 0x0CL, 255UL}, {0x73L, 1UL, 0x0CL, 255UL}, {0x73L, 1UL, 0x0CL, 255UL}, {0x73L, 1UL, 0x0CL, 255UL}, {0x73L, 1UL, 0x0CL, 255UL}, {0x73L, 1UL, 0x0CL, 255UL}};
static uint8_t g_2385 = 4UL;
static int32_t g_2560 = 1L;
static int16_t g_2792[2][10] = {{0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L}, {0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L}};
static int32_t g_2845 = 4L;
static uint16_t g_3008[9] = {0x6CC8L, 0x6CC8L, 0xB484L, 0x6CC8L, 0x6CC8L, 0xB484L, 0x6CC8L, 0x6CC8L, 0xB484L};
static uint32_t g_3059 = 2UL;
static uint8_t g_3069 = 0xD5L;
static uint32_t g_3202 = 7UL;
static int32_t g_3238[3][6] = {{0x2C87538CL, (-8L), 0x2C87538CL, (-8L), 0x2C87538CL, (-8L)}, {0x2C87538CL, (-8L), 0x2C87538CL, (-8L), 0x2C87538CL, (-8L)}, {0x2C87538CL, (-8L), 0x2C87538CL, (-8L), 0x2C87538CL, (-8L)}};
static uint16_t g_3475 = 0UL;



static int8_t func_1(void);
static uint16_t func_2(int32_t p_3, uint32_t p_4, int32_t p_5, int8_t p_6, int8_t p_7);
static uint8_t func_10(int8_t p_11, uint32_t p_12, int8_t p_13, uint32_t p_14);
static uint8_t func_15(int32_t p_16, int32_t p_17);
static int16_t func_20(uint32_t p_21, uint16_t p_22, int8_t p_23, int16_t p_24);
static int8_t func_31(int8_t p_32, int8_t p_33, uint32_t p_34, int8_t p_35);
static int32_t func_46(uint32_t p_47);
static int8_t func_63(int16_t p_64, int32_t p_65, uint16_t p_66, int16_t p_67, uint32_t p_68);
static int16_t func_69(uint8_t p_70, int32_t p_71, uint32_t p_72);
static uint8_t func_81(int16_t p_82, uint8_t p_83);
static int8_t func_1(void)
{
    uint32_t l_9[4];
    uint16_t l_1854 = 65528UL;
    int32_t l_2374 = 0x08C82191L;
    int32_t l_3594 = 0x6C0E560BL;
    int32_t l_3621 = 0xE431F0F9L;
    int i;
    for (i = 0; i < 4; i++)
        l_9[i] = 0UL;
                                        if ((g_300>1U) )
{

g_348[1][2][0] ^= g_1371;


}
                    l_3621 &= (func_2(((g_8 , l_9[3]) == g_8), (l_3594 ^= (func_10(g_8, (func_15((l_2374 = (safe_rshift_func_int8_t_s_u(0x1DL, (func_20((safe_rshift_func_int16_t_s_s((((((g_8 == ((((((0x77L ^ l_9[2]) <= ((safe_mul_func_int8_t_s_s(((safe_mul_func_int8_t_s_s(func_31(g_8, l_9[3], l_9[3], g_8), l_9[3])) != l_9[0]), g_392[2][4])) && l_1854)) ^ g_1302) , g_259) <= l_9[0]) == g_392[3][0])) , g_497[0][0]) ^ 1UL) & l_9[1]) != 0x118AL), l_1854)), g_392[2][0], l_1854, l_9[1]) != 2L)))), g_1302) | l_9[1]), l_9[1], g_1302) , g_185[1][0][2])), l_9[3], l_9[3], g_8) == l_9[3]);
    return g_1596;
}







static uint16_t func_2(int32_t p_3, uint32_t p_4, int32_t p_5, int8_t p_6, int8_t p_7)
{
    uint8_t l_3600[4][2] = {{255UL, 255UL}, {255UL, 255UL}, {255UL, 255UL}, {255UL, 255UL}};
    int32_t l_3601 = 0xBA5869DEL;
    int8_t l_3606 = 0xBBL;
    int32_t l_3620 = 0xDF15A5F7L;
    int i, j;
    p_3 = 0L;
    p_3 = ((safe_lshift_func_uint16_t_u_u((l_3600[2][0] ^= (safe_add_func_int32_t_s_s((!p_4), g_392[0][8]))), 5)) ^ ((l_3601 && (safe_mul_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(l_3606, ((((safe_lshift_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(((safe_sub_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(l_3606, ((l_3620 &= ((l_3601 = 255UL) < ((safe_rshift_func_int16_t_s_u(p_7, (((safe_rshift_func_uint16_t_u_u((~((g_1303[0] & 65535UL) != 1UL)), 3)) == p_4) > g_2792[0][0]))) == 0x06L))) , g_8))), l_3606)) , p_3), p_7)), 11)) & p_6) && l_3620) , g_1129))), 0x64L))) , p_6));
    return p_6;
}







static uint8_t func_10(int8_t p_11, uint32_t p_12, int8_t p_13, uint32_t p_14)
{
    int8_t l_2418[1];
    uint32_t l_2431[4] = {1UL, 9UL, 1UL, 9UL};
    int8_t l_2445 = 0x64L;
    int8_t l_2474 = (-1L);
    int32_t l_2507[1];
    uint16_t l_2531 = 0x942EL;
    int16_t l_2608 = 0xBD17L;
    int32_t l_2616 = 1L;
    int32_t l_2621 = 0xE7B12466L;
    uint32_t l_2757 = 4294967290UL;
    int32_t l_2812 = 0xC7498B8BL;
    uint8_t l_2923[2];
    int32_t l_3047 = (-1L);
    uint32_t l_3049 = 1UL;
    uint32_t l_3224 = 0x96CD2A54L;
    uint16_t l_3241 = 0xFD71L;
    uint32_t l_3309 = 4294967295UL;
    int8_t l_3390 = 0x88L;
    int32_t l_3473 = 0x68F75EC2L;
    int32_t l_3544[9] = {0x87C2F7F7L, 0x87C2F7F7L, (-1L), 0x87C2F7F7L, 0x87C2F7F7L, (-1L), 0x87C2F7F7L, 0x87C2F7F7L, (-1L)};
    int32_t l_3549 = 0xFD7E0959L;
    int32_t l_3552 = 0xAA76B3C5L;
    int i;
    for (i = 0; i < 1; i++)
        l_2418[i] = 0x54L;
    for (i = 0; i < 1; i++)
        l_2507[i] = 0L;
                                        while (!((g_271 > g_483)) )
{

for (i = 0; (i <= (-4)); i--)
                    {
                        uint32_t l_3250 = 1UL;
                        int32_t l_3255 = (-1L);
                        int32_t l_3271 = 5L;
                        g_1752++;
                        g_1303[0] = l_2445;
                        l_3549 = ((p_12 >= g_498) , l_2445);
                        l_3271 = (safe_unary_minus_func_int8_t_s(((safe_lshift_func_int16_t_s_s((l_3049 <= (l_3049 = l_3250)), ((safe_sub_func_int32_t_s_s(0x211E8D53L, ((safe_lshift_func_uint8_t_u_s((g_128 = (((l_3255 = 255UL) > (safe_mul_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((g_1752 , ((safe_sub_func_uint8_t_u_u(g_152[2][5], ((safe_rshift_func_uint8_t_u_s(((((safe_lshift_func_uint16_t_u_u(((l_3549 || ((((g_3475 |= ((0UL & l_2445) < l_2445)) < g_498) | 0x1763L) | l_2445)) == g_2108[6][3]), l_3473)) <= 0x09B7AB54L) , l_3049) == g_128), p_12)) , g_2385))) <= l_2445)), 0)), l_3049)), l_3250))) , l_2445)), g_3008[1])) == l_2445))) | 0L))) ^ l_3049)));
                    };


}
                    for (i = 0; i < 2; i++)
        l_2923[i] = 2UL;
    g_128 = ((l_2418[0] && ((safe_rshift_func_uint16_t_u_u(((((safe_add_func_uint8_t_u_u((safe_sub_func_int16_t_s_s(p_13, g_43)), g_186)) & (((safe_rshift_func_uint16_t_u_u(((safe_add_func_int32_t_s_s(0L, (g_129 | (safe_mul_func_uint8_t_u_u((l_2418[0] , p_12), p_11))))) , p_14), g_1483[4])) == g_483) | 0x8A641CCBL)) != g_1676[0]) , 0xCF9DL), 9)) ^ l_2431[3])) == l_2418[0]);
    g_1232 |= ((g_499 &= ((((safe_sub_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u(g_128, l_2418[0])), (~(safe_rshift_func_uint8_t_u_u(5UL, ((safe_mul_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_u(p_11, 0)) , (safe_sub_func_uint8_t_u_u((l_2445 | p_11), (~(safe_mul_func_uint16_t_u_u((((-1L) < ((((safe_add_func_int32_t_s_s(l_2418[0], ((((0x8A4D3EEAL && 4294967295UL) && 0x6794L) || 0UL) > 0x0DL))) , 0xB0L) < 0x7EL) >= p_13)) , g_2108[6][3]), g_152[4][6])))))), p_12)) != l_2418[0])))))) >= l_2431[3]) & p_11) && 65535UL)) != l_2431[2]);
lbl_3593:
    for (g_2385 = 1; (g_2385 >= 25); g_2385 = safe_add_func_uint8_t_u_u(g_2385, 5))
    {
        uint8_t l_2457 = 0UL;
        uint32_t l_2482 = 0UL;
        int32_t l_2493 = 0xBC58FC51L;
        l_2457 ^= (g_332 < l_2418[0]);
        for (g_499 = (-23); (g_499 >= 5); g_499++)
        {
            int8_t l_2475 = 0x2EL;
            int8_t l_2494 = (-1L);
            for (g_1302 = 2; (g_1302 <= 8); g_1302 += 1)
            {
                for (g_332 = 0; (g_332 <= 8); g_332 += 1)
                {
                    for (g_186 = 2; (g_186 <= 8); g_186 += 1)
                    {
                        int i;
                        return g_331[g_186];
                    }
                }
            }
            if (((-1L) < ((g_570 > (((((safe_unary_minus_func_int8_t_s(((safe_sub_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u((0x27E3L && (safe_rshift_func_int16_t_s_s((safe_mul_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s(((((((g_1483[2] > 0xD7E3A114L) <= g_1482) != (p_12 | ((safe_mod_func_uint16_t_u_u(((~9UL) && (p_13 <= g_499)), l_2418[0])) != l_2474))) , g_497[0][0]) , (-1L)) && p_13), 0)), g_820)), 10))), 0x50B0L)), g_348[1][1][0])) < p_12))) <= 0UL) > 0x67A6L) & l_2475) , p_11)) , 0x2F5DCD34L)))
            {
                uint32_t l_2492[3];
                int32_t l_2523 = 0x16A64304L;
                int i;
                for (i = 0; i < 3; i++)
                    l_2492[i] = 0xE38E26EAL;
                if ((safe_add_func_int16_t_s_s((p_11 , (((((((((safe_mul_func_uint16_t_u_u((((p_11 > ((p_13 < (g_331[8] | (((0xEAL < ((safe_lshift_func_int16_t_s_s(l_2482, (safe_lshift_func_uint8_t_u_s(((g_211[1] != ((safe_mul_func_int16_t_s_s((safe_add_func_int8_t_s_s((safe_sub_func_int8_t_s_s((p_11 != ((l_2492[1] |= (~(p_12 < 0xFEL))) , l_2475)), (-1L))), g_184[6][0][2])), p_14)) == g_130)) <= l_2493), g_348[1][1][0])))) < 0x999AF261L)) , p_14) < p_14))) > p_12)) == p_14) <= 255UL), p_14)) | 0x91FAL) || g_259) ^ 8L) <= p_12) > l_2494) != g_184[4][1][2]) <= (-1L)) != 0UL)), 0x49E1L)))
                {
                    g_1303[0] = ((safe_add_func_uint16_t_u_u((p_13 , (g_670 = (((safe_add_func_int8_t_s_s((p_13 = g_271), (safe_lshift_func_uint8_t_u_s((247UL ^ ((safe_rshift_func_uint16_t_u_u(g_257, p_12)) && (safe_lshift_func_int16_t_s_s((g_1482 <= p_11), 1)))), (safe_mul_func_uint16_t_u_u((l_2418[0] , 0xE23FL), 0L)))))) , l_2482) != 0xC1L))), p_14)) && p_11);
                }
                else
                {
                    uint8_t l_2530 = 0x43L;
                    l_2507[0] = 1L;
                    g_1925 ^= ((safe_rshift_func_int16_t_s_u(p_14, (p_12 && ((g_497[0][4] ^= (g_128 | (((safe_rshift_func_int16_t_s_s(((((safe_lshift_func_uint16_t_u_u((((safe_rshift_func_uint16_t_u_s(((((((safe_add_func_int16_t_s_s((((safe_lshift_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u(((l_2523 &= (p_13 ^ (safe_unary_minus_func_int32_t_s((p_13 , (-1L)))))) != ((safe_sub_func_uint32_t_u_u((safe_add_func_int32_t_s_s(1L, (safe_lshift_func_int16_t_s_s(0xA805L, 5)))), ((p_13 & p_13) <= p_11))) != 0L)), 3)), l_2492[1])) | p_14) == (-1L)), l_2530)) >= l_2531) || 0x7ACC8963L) >= 255UL) ^ 3UL) || 0xDCL), 15)) , g_256) <= 0UL), l_2492[2])) , l_2530) && 0xB0L) ^ g_184[3][0][1]), 3)) , l_2457) > l_2494))) > g_271)))) == g_1676[3]);
                    g_1303[0] |= (((safe_mod_func_int16_t_s_s((((~(((safe_mod_func_uint16_t_u_u(((l_2493 ^= g_489) == ((((safe_mul_func_uint16_t_u_u(((g_498 = 0x15L) == (0x245BL <= (((((safe_lshift_func_uint16_t_u_u((p_14 <= (l_2523 , ((safe_unary_minus_func_uint8_t_u((safe_mul_func_uint16_t_u_u(((8UL & (safe_sub_func_uint8_t_u_u((((0xCAC3L & (safe_add_func_int8_t_s_s((safe_sub_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(((safe_mul_func_uint16_t_u_u(0xBD9DL, (safe_add_func_int32_t_s_s((safe_add_func_int8_t_s_s((safe_mul_func_int16_t_s_s(g_1925, l_2494)), g_1676[3])), p_11)))) & 250UL), g_43)), 4L)), l_2475))) && l_2431[3]) , g_2560), 0x72L))) > 0xBC58L), p_13)))) , l_2530))), 3)) | l_2482) & g_130) , l_2523) & g_2108[6][3]))), 0x2649L)) < p_11) <= p_14) == 0UL)), g_483)) , l_2530) & g_1232)) , p_13) , g_211[1]), g_1302)) | p_11) & g_1676[3]);
                }
            }
            else
            {
                l_2493 ^= (-4L);
                return g_186;
            }
            l_2507[0] = 0x88471138L;
        }
        return g_348[1][2][0];
    }
    if ((l_2418[0] , l_2531))
    {
        uint16_t l_2577 = 1UL;
        uint8_t l_2598 = 4UL;
        uint16_t l_2609 = 0xA12EL;
        int32_t l_2622 = (-3L);
        int32_t l_2739 = 0xCACA59F1L;
        int16_t l_2740 = 5L;
        int32_t l_2759 = 7L;
        uint16_t l_2865 = 1UL;
        int32_t l_2925[6] = {(-8L), 0L, (-8L), 0L, (-8L), 0L};
        int8_t l_2970 = 0x8CL;
        int32_t l_2978 = 0x180B70E1L;
        int32_t l_2980 = 2L;
        int32_t l_2985[8] = {1L, 1L, 0x7BA6B078L, 1L, 1L, 0x7BA6B078L, 1L, 1L};
        int32_t l_2989 = (-1L);
        int16_t l_3019 = (-7L);
        int i;
        for (g_670 = 2; (g_670 <= 9); g_670 += 1)
        {
            int32_t l_2578 = 0x675F7AC3L;
            int32_t l_2579[8][7] = {{0L, 0x84012D95L, (-1L), 0x3F075CB1L, 0x3F075CB1L, (-1L), 0x84012D95L}, {0L, 0x84012D95L, (-1L), 0x3F075CB1L, 0x3F075CB1L, (-1L), 0x84012D95L}, {0L, 0x84012D95L, (-1L), 0x3F075CB1L, 0x3F075CB1L, (-1L), 0x84012D95L}, {0L, 0x84012D95L, (-1L), 0x3F075CB1L, 0x3F075CB1L, (-1L), 0x84012D95L}, {0L, 0x84012D95L, (-1L), 0x3F075CB1L, 0x3F075CB1L, (-1L), 0x84012D95L}, {0L, 0x84012D95L, (-1L), 0x3F075CB1L, 0x3F075CB1L, (-1L), 0x84012D95L}, {0L, 0x84012D95L, (-1L), 0x3F075CB1L, 0x3F075CB1L, (-1L), 0x84012D95L}, {0L, 0x84012D95L, (-1L), 0x3F075CB1L, 0x3F075CB1L, (-1L), 0x84012D95L}};
            int i, j;
            l_2507[0] = (g_1676[g_670] ^ ((((safe_rshift_func_uint16_t_u_s((p_12 > g_123), 12)) , 0L) | ((((safe_add_func_int8_t_s_s(((((+(-1L)) > (safe_mul_func_uint8_t_u_u((g_2108[6][3] |= (p_11 == ((safe_lshift_func_uint16_t_u_u((((((safe_mul_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(((((((safe_unary_minus_func_uint32_t_u((0x755C0708L >= l_2507[0]))) , (((safe_mul_func_uint8_t_u_u((l_2579[2][5] = ((l_2578 ^= ((g_331[6] , l_2577) | 0xC4B71FC1L)) != g_300)), l_2577)) & g_1676[g_670]) != 0x07L)) && (-9L)) , l_2579[2][5]) , p_14) || p_12), g_129)), (-1L))) ^ p_13) >= 0L) ^ l_2577) , 0x8EE9L), 2)) ^ 0L))), 0x4FL))) >= 0xB1L) != g_1676[8]), g_499)) != 65528UL) >= g_670) , p_11)) == l_2431[3]));
            for (g_489 = 3; (g_489 <= 9); g_489 += 1)
            {
                int32_t l_2599 = 0xE8849D68L;
                g_820 = (((safe_sub_func_int32_t_s_s((l_2579[7][0] = ((l_2507[0] = ((((((l_2577 && 0xB7L) | ((safe_add_func_int32_t_s_s((safe_sub_func_int16_t_s_s((safe_unary_minus_func_int32_t_s((safe_lshift_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u(((l_2577 , (safe_unary_minus_func_uint32_t_u(0x4A8A0441L))) == (safe_lshift_func_int16_t_s_u(((((g_185[6][0][2] , (safe_mul_func_int16_t_s_s((p_13 < (safe_mul_func_uint8_t_u_u(l_2577, (p_13 != (-8L))))), 0x101CL))) < 0L) , l_2579[2][5]) >= l_2598), 3))), 1)), g_483)))), 0x96D8L)), 3UL)) < p_13)) && 4294967286UL) & l_2579[4][1]) <= g_184[6][0][2]) , l_2599)) | p_14)), l_2531)) , l_2531) | 0L);
                g_2560 |= ((8L != (((p_12 , ((((((p_12 | 0x0849L) < (safe_add_func_int16_t_s_s(((4UL < (safe_sub_func_uint8_t_u_u(p_14, (safe_add_func_int32_t_s_s(((safe_mul_func_uint16_t_u_u((g_1483[6] , g_130), 0UL)) < (-8L)), p_11))))) == 0xFBF4L), l_2577))) == l_2577) > (-2L)) <= l_2445) , p_13)) <= p_14) >= l_2577)) | p_13);
            }
            ++l_2609;
        }
        if ((((p_11 >= (l_2507[0] , 0x3EB4L)) | ((safe_add_func_uint32_t_u_u((((safe_sub_func_int8_t_s_s(0x36L, l_2616)) == ((safe_lshift_func_int8_t_s_u((p_13 = g_185[6][0][2]), 2)) <= (safe_mod_func_uint8_t_u_u(p_11, p_12)))) == (l_2622 = ((l_2608 & l_2621) || p_14))), p_14)) | l_2474)) , (-3L)))
        {
            int16_t l_2635 = 0x2B62L;
            int32_t l_2655 = 0xEFBFE9F3L;
            int32_t l_2656 = (-9L);
            int32_t l_2657[4];
            int32_t l_2659[5] = {(-2L), 0xA61F38E2L, (-2L), 0xA61F38E2L, (-2L)};
            int8_t l_2660 = 0xEEL;
            int i;
            for (i = 0; i < 4; i++)
                l_2657[i] = 0xACE2B57CL;
lbl_2764:
            g_1303[0] = ((safe_mod_func_int16_t_s_s(((safe_rshift_func_int8_t_s_u((safe_mul_func_uint16_t_u_u(g_1302, 0UL)), 0)) <= (0x9DL & 0x63L)), g_331[8])) != ((g_348[1][2][0] & (l_2609 , p_12)) | (((safe_mod_func_int32_t_s_s((l_2635 = ((safe_sub_func_uint8_t_u_u((g_2108[6][3]--), 0x5AL)) < g_331[4])), l_2622)) && l_2635) < 0x7DL)));
            for (l_2531 = 16; (l_2531 >= 39); l_2531 = safe_add_func_uint8_t_u_u(l_2531, 1))
            {
                uint8_t l_2658 = 0x71L;
                int32_t l_2698 = 0x565019AFL;
                uint8_t l_2699 = 0UL;
                l_2659[3] = (safe_sub_func_uint32_t_u_u((g_497[0][1] = ((((safe_mul_func_int16_t_s_s(l_2609, 0xE3CFL)) , (safe_add_func_int8_t_s_s(g_271, p_14))) != (l_2622 = ((safe_rshift_func_int8_t_s_s((-10L), (l_2657[3] ^= (p_11 &= (~((0x70L && (((((!(safe_rshift_func_uint8_t_u_s(0x53L, ((l_2656 = (l_2507[0] |= ((((l_2655 &= ((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u(p_13, 7)), 8)) & (~(l_2445 > l_2598))) && g_1925) != l_2598)) | l_2609) < g_211[1]) <= 0x68CD51B6L))) <= (-1L))))) , 0x0C3BDF04L) != 0UL) != g_498) && p_13)) >= (-1L))))))) < 255UL))) || l_2658)), p_12));
                if ((l_2660 ^= (0x742EL != (l_2657[2] &= 0x7D77L))))
                {
                    l_2622 &= ((p_14 && 4294967295UL) , ((safe_lshift_func_uint16_t_u_u((+(safe_mul_func_uint16_t_u_u(65535UL, 0L))), 11)) || (1UL >= ((-7L) & l_2577))));
                }
                else
                {
                    l_2659[4] = ((g_271 | (l_2699 = (safe_mul_func_int8_t_s_s((((safe_rshift_func_int8_t_s_u((safe_add_func_int8_t_s_s((p_11 = (safe_unary_minus_func_uint16_t_u((safe_mod_func_uint8_t_u_u((~((safe_add_func_uint8_t_u_u((((safe_mod_func_int16_t_s_s((g_570 , l_2658), (l_2655 = ((safe_rshift_func_uint16_t_u_u((l_2616 |= ((l_2698 = (safe_rshift_func_uint16_t_u_s(((((safe_mul_func_uint16_t_u_u(l_2657[3], ((g_43 < (((((((safe_mul_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(((safe_mod_func_uint16_t_u_u(g_392[2][4], (++g_670))) >= (l_2507[0] |= (1L || (safe_add_func_int16_t_s_s(((p_13 = (g_705 , (((safe_add_func_int8_t_s_s(p_14, g_1752)) | l_2598) < l_2474))) == g_392[2][4]), l_2608))))), p_12)), g_1676[3])) && l_2474) || 1UL) <= 0xA761L) ^ 0xD285L) , 1L) , p_12)) != 1L))) , (-9L)) , 0x3960L) <= g_259), 9))) > g_257)), g_1676[3])) , l_2658)))) | p_11) == p_12), (-6L))) , (-1L))), l_2418[0]))))), l_2577)), 3)) && 4L) || (-7L)), 7UL)))) == p_14);
                }
                return g_300;
            }
            for (l_2445 = (-25); (l_2445 > (-11)); l_2445++)
            {
                uint16_t l_2717 = 0xFE8EL;
                int32_t l_2720 = 0xEDF85396L;
                uint32_t l_2788 = 0xF2DA1930L;
                int32_t l_2835 = 0xF5299DC4L;
                int32_t l_2894[8][8][4] = {{{(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}}, {{(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}}, {{(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}}, {{(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}}, {{(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}}, {{(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}}, {{(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}}, {{(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}, {(-1L), 0x29851032L, 0xC42C86C5L, 0x290E42D0L}}};
                int i, j, k;
                for (g_129 = 11; (g_129 >= 14); ++g_129)
                {
                    uint8_t l_2712[2];
                    int32_t l_2738 = 1L;
                    int32_t l_2741[5] = {0x39500430L, 0x72E2A8F8L, 0x39500430L, 0x72E2A8F8L, 0x39500430L};
                    uint8_t l_2760 = 0x37L;
                    uint8_t l_2761 = 1UL;
                    int i;
                    for (i = 0; i < 2; i++)
                        l_2712[i] = 255UL;
                    if ((safe_mul_func_int16_t_s_s((safe_add_func_int32_t_s_s((g_820 = (((g_1302 & (safe_sub_func_int16_t_s_s((safe_mul_func_int8_t_s_s(l_2712[1], p_11)), (((((safe_mul_func_int8_t_s_s((safe_lshift_func_int8_t_s_u(((((l_2717 = p_11) , ((((safe_add_func_uint32_t_u_u(((g_186 ^= g_130) < l_2712[1]), l_2622)) > g_128) , ((g_1752 = (0UL & g_259)) || 0x6C16CE98L)) || g_1371)) > l_2660) && l_2657[3]), 5)), p_14)) , 1L) >= p_13) | p_13) , (-6L))))) , p_14) <= 0x6C12L)), l_2720)), 0x7547L)))
                    {
                        uint8_t l_2758[9][6] = {{5UL, 0xD3L, 5UL, 0xD3L, 5UL, 0xD3L}, {5UL, 0xD3L, 5UL, 0xD3L, 5UL, 0xD3L}, {5UL, 0xD3L, 5UL, 0xD3L, 5UL, 0xD3L}, {5UL, 0xD3L, 5UL, 0xD3L, 5UL, 0xD3L}, {5UL, 0xD3L, 5UL, 0xD3L, 5UL, 0xD3L}, {5UL, 0xD3L, 5UL, 0xD3L, 5UL, 0xD3L}, {5UL, 0xD3L, 5UL, 0xD3L, 5UL, 0xD3L}, {5UL, 0xD3L, 5UL, 0xD3L, 5UL, 0xD3L}, {5UL, 0xD3L, 5UL, 0xD3L, 5UL, 0xD3L}};
                        int i, j;
                        g_1232 = (((l_2760 = (((((((safe_add_func_int8_t_s_s(g_331[2], 252UL)) <= ((safe_rshift_func_int16_t_s_s(((((!l_2622) >= (++g_497[0][0])) == ((safe_lshift_func_uint8_t_u_s(0x00L, 6)) == (safe_lshift_func_uint8_t_u_u((((g_498 = (l_2759 = ((safe_mul_func_uint16_t_u_u(((safe_mul_func_uint8_t_u_u(((l_2758[5][4] |= (safe_sub_func_uint32_t_u_u(((++g_211[1]) == (((safe_rshift_func_uint8_t_u_u((safe_sub_func_int32_t_s_s(((p_12 || ((+((g_1302 == (safe_mul_func_uint8_t_u_u(248UL, (safe_rshift_func_int16_t_s_u(((((l_2659[3] = (safe_sub_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_s((p_12 , (p_11 , l_2712[0])), l_2757)) && g_392[1][5]), p_13))) | 0x77L) && l_2507[0]) ^ 0x96FEL), 14))))) != 1L)) >= l_2738)) | p_11), 3L)), l_2577)) != g_1303[0]) > l_2431[3])), p_12))) , l_2712[0]), 0UL)) | l_2759), 65535UL)) && 0x8C02L))) , g_298) || g_130), 3)))) , p_12), 11)) , 4294967292UL)) < l_2712[0]) != 0xE26549CAL) ^ g_1371) == 0x5EL) > g_570)) ^ (-8L)) == p_12);
                        ++l_2761;
                        if (g_2560)
                            goto lbl_2764;
                        g_1925 = (safe_sub_func_uint16_t_u_u((safe_mul_func_uint8_t_u_u(((g_348[1][8][0] , (safe_add_func_uint32_t_u_u(g_123, (p_11 ^ (0x46L & (0xA8L || (g_211[1] = (safe_mul_func_uint16_t_u_u(l_2717, (safe_sub_func_uint8_t_u_u(l_2758[4][3], ((safe_add_func_int16_t_s_s(((safe_lshift_func_uint16_t_u_u(65535UL, (l_2741[0] == p_11))) && 65531UL), l_2659[1])) , p_13)))))))))))) <= g_497[0][0]), l_2740)), p_12));
                    }
                    else
                    {
                        l_2739 = p_14;
                        l_2622 = l_2720;
                        return g_498;
                    }
                    if (((g_498 = (l_2720 = (safe_lshift_func_uint8_t_u_u(((((safe_mod_func_int32_t_s_s((safe_unary_minus_func_uint32_t_u((safe_mod_func_int32_t_s_s(((safe_mod_func_uint32_t_u_u(l_2788, g_1925)) && ((-1L) >= (((((l_2507[0] = 0x3273351BL) >= p_12) & ((5UL > ((safe_sub_func_uint8_t_u_u(((+(g_2792[1][5] = p_12)) == ((safe_rshift_func_uint16_t_u_u(g_184[6][0][2], 6)) > (safe_lshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u((+0L), 0UL)), g_256)))), l_2660)) <= (-1L))) >= l_2616)) ^ p_11) || p_14))), p_12)))), g_1596)) < g_483) >= g_1752) > 0x1B92L), 5)))) == g_185[6][0][2]))
                    {
                        int16_t l_2813 = 1L;
                        l_2738 = ((0xFEL > p_13) & (0x551DL & (l_2635 || (g_152[5][2] |= ((safe_unary_minus_func_int32_t_s((((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s(0L, ((((safe_lshift_func_uint16_t_u_u((((((safe_sub_func_uint16_t_u_u((~((((safe_add_func_uint32_t_u_u(((l_2741[0] = (g_483 > ((l_2720 &= (-1L)) <= l_2656))) || (0x1CL || g_256)), l_2812)) < l_2813) > p_13) , 65535UL)), 0x1D00L)) < l_2598) && 2L) , g_128) | g_392[2][4]), l_2788)) , 65535UL) <= p_12) , 5UL))), p_11)) , p_14) >= l_2717))) & g_184[6][0][2])))));

for (l_2656 = 0; l_2656 < 8; l_2656++)
    {
        for (i = 0; i < 1; i++)
        {
            for (l_2622 = 0; l_2622 < 8; l_2622++)
            {
                transparent_crc(g_185[l_2656][i][l_2622], "g_185[l_2656][i][l_2622]", g_128);
                if (g_128) printf("index = [%d][%d][%d]\n", l_2656, i, l_2622);

            }
        }
    };


                    return p_11;
                    }
                    else
                    {
                        uint8_t l_2834[6] = {0UL, 1UL, 0UL, 1UL, 0UL, 1UL};
                        int i;
                        l_2622 = (((safe_add_func_int32_t_s_s(g_348[1][2][0], (l_2835 = (((0x46L || (safe_rshift_func_int16_t_s_u((l_2616 = (0x52DAL ^ (safe_lshift_func_int16_t_s_u(p_14, (0L && ((((p_11 = (safe_rshift_func_int8_t_s_s((((safe_add_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((l_2720 = ((((1UL != ((safe_mod_func_int8_t_s_s(p_12, (0x5672L || (safe_sub_func_uint32_t_u_u(((g_1303[0] != g_1925) | 0x43L), g_152[7][5]))))) < p_13)) >= p_13) , (-1L)) ^ p_11)), p_14)) , 255UL), 255UL)) > l_2445), g_2560)) >= l_2659[3]) , l_2531), l_2834[5]))) || l_2609) >= 0x6FC8L) == g_1303[3])))))), p_14))) > 0x9964L) , g_186)))) < 65532UL) <= 0x520EL);

{
        for (l_2656 = 0; l_2656 < 7; l_2656++)
        {
            transparent_crc(g_152[l_3047][l_2656], "g_152[l_3047][l_2656]", g_1371);
            if (g_1371) printf("index = [%d][%d]\n", l_3047, l_2656);

        }
    }

                    return g_130;
                    }
                }
                for (g_820 = (-5); (g_820 == (-25)); --g_820)
                {
                    int32_t l_2842 = (-5L);
                    int32_t l_2846 = 7L;
                    int32_t l_2870 = 0x2F0BDF7FL;
                    int32_t l_2871 = 1L;
                    int32_t l_2872 = (-3L);
                    l_2507[0] &= (0x87479D5CL >= ((safe_add_func_int8_t_s_s(((l_2846 = (g_2845 &= ((((((l_2655 &= l_2788) == ((0xC2CBA9C1L | (g_271 == (safe_sub_func_int32_t_s_s(((l_2616 ^= (g_1482 |= ((1L || ((l_2842 <= 0x17L) & (g_1371 | ((safe_rshift_func_int16_t_s_u((0x7E80E5CCL | g_123), 15)) || l_2621)))) >= 0x13L))) , g_1303[0]), l_2835)))) , l_2842)) > 0x608F7470L) <= 0L) >= p_12) < p_13))) & 9UL), g_186)) | g_211[1]));
                    l_2872 = ((l_2846 |= (safe_rshift_func_int16_t_s_s(l_2657[2], 15))) <= (((safe_sub_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u(g_1596, ((safe_add_func_int32_t_s_s(((g_1596 , (((l_2507[0] = ((((l_2871 = (!((safe_mod_func_uint32_t_u_u(l_2609, (((0L && (g_392[2][4] >= (safe_lshift_func_int16_t_s_u(((g_489--) != (safe_add_func_int8_t_s_s((~((l_2656 |= ((((l_2865 && (l_2870 = ((safe_lshift_func_int8_t_s_u(((safe_add_func_uint16_t_u_u((p_13 >= 0x7DD4L), (-1L))) >= g_186), 1)) > 0x1355C19BL))) , p_14) >= l_2609) < g_8)) & g_332)), 1L))), 5)))) || 0L) , (-1L)))) | p_14))) , l_2577) & (-10L)) | 0x8EL)) & l_2739) ^ 6L)) <= g_2792[1][5]), g_331[2])) , g_186))) , 0xBCL), g_331[2])) < g_570) | l_2659[4]));
                    if (p_12)
                        break;
                    for (g_300 = 0; (g_300 <= 0); g_300 += 1)
                    {
                        l_2835 = 0xB60EFBFCL;
                    }
                }
                l_2616 = g_184[6][0][2];
                g_1925 = (((((((safe_add_func_uint32_t_u_u(l_2598, (safe_mul_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((safe_mod_func_uint8_t_u_u((l_2739 = (1UL > (g_257 == (l_2894[2][1][1] = (l_2740 | ((l_2835 &= ((l_2720 = (safe_mul_func_uint8_t_u_u((((((g_2792[1][5] , ((safe_sub_func_int8_t_s_s((!(safe_rshift_func_uint8_t_u_s(l_2598, (safe_sub_func_uint32_t_u_u((l_2788 & (safe_lshift_func_uint8_t_u_s((l_2660 || 65535UL), l_2577))), l_2598))))), p_14)) >= l_2507[0])) & 0xE176L) > 0xF7L) , p_13) , 0x0FL), p_14))) & 0xC21CL)) != l_2635)))))), l_2759)) & p_11), p_11)), g_499)))) > 0xCBL) > l_2659[3]) > l_2788) <= g_499) , g_1850) , g_499);
            }
            g_1925 = (safe_add_func_int8_t_s_s((((g_211[1] = p_11) <= (p_13 = g_184[6][0][2])) , (safe_rshift_func_int8_t_s_s(l_2507[0], (0x6E05L && 0x785FL)))), (g_271 >= ((safe_unary_minus_func_int32_t_s(((g_152[0][3] & l_2577) > (safe_unary_minus_func_int32_t_s((!0x2366L)))))) > g_1483[6]))));
        }
        else
        {
            int32_t l_2924 = 0xB874628BL;
            int16_t l_2971[1];
            int32_t l_2972 = (-8L);
            int32_t l_2973 = 9L;
            int32_t l_2974 = 0xE2247A93L;
            int32_t l_2975 = (-4L);
            int32_t l_2976 = 0xD9B34947L;
            int32_t l_2977 = (-6L);
            int32_t l_2979 = (-1L);
            int32_t l_2981 = 0xD54E299EL;
            int32_t l_2982 = (-5L);
            int32_t l_2983 = 1L;
            int32_t l_2984 = 0x6018FD50L;
            int16_t l_2986 = 8L;
            int32_t l_2987[9][2] = {{(-1L), 1L}, {(-1L), 1L}, {(-1L), 1L}, {(-1L), 1L}, {(-1L), 1L}, {(-1L), 1L}, {(-1L), 1L}, {(-1L), 1L}, {(-1L), 1L}};
            uint32_t l_3045 = 0x882F4AB0L;
            int i, j;
            for (i = 0; i < 1; i++)
                l_2971[i] = 0x0923L;
            if ((((l_2759 = (l_2622 &= ((+(((l_2739 = (~(0x351B947BL && ((safe_mul_func_int8_t_s_s(((((((0xF49532ADL <= ((g_331[6] , (g_570 = (safe_unary_minus_func_uint32_t_u((safe_sub_func_int32_t_s_s(0L, (g_497[0][1]++))))))) <= (((((0xF5BF2E6BL & (safe_rshift_func_int8_t_s_u((safe_mod_func_int8_t_s_s((safe_mod_func_int16_t_s_s((g_1676[2] ^= 1L), l_2507[0])), (safe_lshift_func_uint8_t_u_s(((((safe_mul_func_uint16_t_u_u((g_43 = (((safe_lshift_func_uint8_t_u_u((((((l_2616 = (g_1232 , p_12)) ^ 0xC9D0L) , l_2609) , 0x862D6D18L) >= p_11), 7)) == 0xE2L) == 1UL)), g_348[1][2][0])) | 0xCA1B0C03L) | l_2759) != p_11), l_2923[0])))), g_1752))) != l_2431[3]) , 0x23B25113L) , (-1L)) & l_2924))) && g_186) <= l_2925[5]) , l_2418[0]) , 0x82L) || g_2845), 0xD1L)) <= l_2474)))) , l_2577) == (-1L))) & 4L))) == g_670) ^ g_152[7][5]))
            {
                int32_t l_2941 = 0x0C9E4E97L;
                int32_t l_2942[4][8][2] = {{{(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}}, {{(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}}, {{(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}}, {{(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}, {(-1L), 0xE780B4DDL}}};
                int32_t l_2988 = 0x156360E1L;
                uint8_t l_2990 = 0x9BL;
                int i, j, k;
                l_2942[2][3][0] = (safe_add_func_int32_t_s_s((safe_rshift_func_int16_t_s_u(((l_2507[0] = (g_1371 |= ((g_8 || g_2792[1][5]) ^ 0x36L))) ^ (g_1303[0] > (6L || (safe_mod_func_int8_t_s_s((safe_add_func_int32_t_s_s((((((l_2740 , (safe_add_func_int16_t_s_s(((l_2616 = (g_211[1] = ((safe_mul_func_uint16_t_u_u((g_2845 > (safe_unary_minus_func_uint8_t_u((safe_lshift_func_int16_t_s_s((-3L), 11))))), 0x4539L)) , g_185[0][0][3]))) && p_13), 1UL))) , 65535UL) && l_2941) && g_1482) ^ p_11), p_11)), l_2924))))), 10)), g_152[7][5]));
                for (g_1596 = 0; (g_1596 > (-2)); g_1596 = safe_sub_func_int32_t_s_s(g_1596, 8))
                {
                    int32_t l_2954 = (-5L);
                    for (l_2445 = (-28); (l_2445 != 23); l_2445 = safe_add_func_int32_t_s_s(l_2445, 5))
                    {
                        uint8_t l_2947 = 0x4EL;

if (g_130)
                            break;

                    l_2947 = 3L;

{
                l_3047 ^= (-4L);
                return l_2990;
            }

                    if (l_2947)
                            break;
                        l_2739 = (safe_lshift_func_int8_t_s_s((safe_sub_func_int16_t_s_s(((safe_mul_func_int8_t_s_s(l_2954, ((l_2759 = (l_2924 = p_12)) == (safe_rshift_func_uint16_t_u_s(g_820, 6))))) , (g_2792[0][3] , ((((safe_mod_func_int8_t_s_s(((p_11 ^= ((l_2970 = ((l_2942[2][3][0] = ((((l_2577 >= (~(p_13 || (0x6570CFE5L & (safe_lshift_func_int16_t_s_s(((safe_mul_func_int16_t_s_s((safe_mod_func_int8_t_s_s((safe_rshift_func_int16_t_s_s((safe_sub_func_int32_t_s_s((p_14 > (l_2942[0][6][1] | g_257)), l_2924)), 1)), 0x8FL)), 0xC654L)) <= 0x5762378CL), p_14)))))) > g_1129) >= 0xE3D2L) , 0UL)) && 0x75A0L)) > 4294967287UL)) && g_820), l_2507[0])) && p_13) < l_2971[0]) != g_331[2]))), p_12)), g_392[2][4]));

for (l_2988 = 0; l_2988 < 2; l_2988++)
        l_2923[l_2988] = 2UL;

                    g_2845 = g_1371;
                    }
                }
                --l_2990;
            }
            else
            {
                int32_t l_2995 = 0x90287D4DL;
                uint32_t l_3044 = 4294967287UL;
                int32_t l_3046 = 0x353FB8ADL;
                int32_t l_3055 = 1L;
                int32_t l_3058[8][2] = {{0xE2BFD281L, 1L}, {0xE2BFD281L, 1L}, {0xE2BFD281L, 1L}, {0xE2BFD281L, 1L}, {0xE2BFD281L, 1L}, {0xE2BFD281L, 1L}, {0xE2BFD281L, 1L}, {0xE2BFD281L, 1L}};
                int i, j;
                l_2507[0] ^= (safe_add_func_uint16_t_u_u((g_259--), (safe_mul_func_uint16_t_u_u(((safe_mul_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(l_2995, g_1596)), (g_332 ^= (0L || p_14)))) >= (((safe_sub_func_int32_t_s_s((((safe_mul_func_int16_t_s_s((g_3008[3] = 0xBEF0L), ((g_483 = (safe_rshift_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_u((l_2531 , (safe_mul_func_uint16_t_u_u(0xA4FEL, (g_670 = p_14)))), l_2608)), g_497[0][0])), 10)), g_1303[0]))) || p_14))) >= l_3019) , g_392[1][0]), l_2980)) && p_13) == 1L)), l_3019))));
                if (p_11)
                {
                    uint8_t l_3043 = 4UL;
                    l_2507[0] = 0x1BE37D07L;
                    for (l_2616 = (-7); (l_2616 == 6); l_2616 = safe_add_func_int32_t_s_s(l_2616, 1))
                    {
                        g_820 = (l_3046 = (((safe_sub_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((((g_2560 > (l_2925[5] == (safe_mul_func_uint16_t_u_u((0xE0EAE084L || (((safe_rshift_func_int16_t_s_u(1L, (safe_unary_minus_func_int8_t_s(((safe_lshift_func_int8_t_s_u((p_11 = (safe_add_func_uint16_t_u_u(((g_186++) , 0x6F61L), (safe_rshift_func_uint16_t_u_s((((g_256 = (((g_570 |= (((safe_mod_func_uint16_t_u_u(g_1596, (l_2985[4] = ((safe_mod_func_int16_t_s_s((0L < ((p_12 && (l_2976 = l_3043)) | l_3044)), l_2995)) & g_256)))) & 0x70FEL) != 0x4AL)) != l_2973) >= g_498)) , p_11) , l_2976), l_3043))))), 2)) == g_3008[8]))))) <= 1L) && l_2431[0])), 0x3EBEL)))) >= l_3043) >= (-4L)), l_3045)), p_12)) , 7L) == g_331[3]));
                        return l_3047;
                    }
                }
                else
                {
                    int32_t l_3048 = 7L;
                    int32_t l_3057 = (-8L);
                    for (l_2759 = 2; (l_2759 >= 0); l_2759 -= 1)
                    {
                        int8_t l_3056 = 0x27L;
                        g_820 = p_11;
                        --l_3049;
                        l_3057 = (l_3056 = (((((l_2980 = 255UL) & (((l_2974 < 0xF375L) > g_1483[7]) == ((safe_rshift_func_uint8_t_u_s(l_2995, 2)) && ((+((l_3046 < ((l_2977 && ((g_300 , (((p_14 , p_13) == l_3055) >= 0xA6FC943CL)) <= 0UL)) , p_14)) < g_489)) & 0x08L)))) ^ g_1303[4]) == g_185[6][0][1]) != 1L));
                    }
                }
                ++g_3059;
            }
        }
    }
    else
    {
        int16_t l_3064[1];
        int32_t l_3065 = 6L;
        int32_t l_3128[7][6][6] = {{{0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}}, {{0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}}, {{0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}}, {{0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}}, {{0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}}, {{0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}}, {{0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}, {0L, 0L, 0L, 0x6B52A34BL, 0x8BEE9232L, (-6L)}}};
        uint32_t l_3129 = 4294967295UL;
        uint16_t l_3140 = 0x3649L;
        int8_t l_3210 = 0x9FL;
        int32_t l_3221[5];
        uint32_t l_3268 = 0UL;
        uint32_t l_3474 = 4294967286UL;
        int8_t l_3546 = 0x0FL;
        int32_t l_3547[5] = {7L, 0x2A0C19D5L, 7L, 0x2A0C19D5L, 7L};
        int32_t l_3551 = (-7L);
        int i, j, k;
        for (i = 0; i < 1; i++)
            l_3064[i] = 0xAB41L;
        for (i = 0; i < 5; i++)
            l_3221[i] = 0x173F2037L;
        for (g_257 = 0; (g_257 >= 8); ++g_257)
        {
            int16_t l_3066[10];
            int32_t l_3067 = (-1L);
            int32_t l_3068 = 0x5AB06E69L;
            int i;
            for (i = 0; i < 10; i++)
                {
if (l_3067)
                continue;

                    l_3066[i] = 0L;}
            g_3069--;
            l_3065 ^= (+p_14);
            if ((((!0xF5F2L) < 0xA3L) <= (l_3068 = 0x7257DDC4L)))
            {
                uint8_t l_3074[8] = {1UL, 2UL, 1UL, 2UL, 1UL, 2UL, 1UL, 2UL};
                int32_t l_3096 = 0x12AC147EL;
                int32_t l_3097[3][5][6] = {{{(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}, {(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}, {(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}, {(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}, {(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}}, {{(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}, {(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}, {(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}, {(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}, {(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}}, {{(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}, {(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}, {(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}, {(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}, {(-4L), 0L, 0x68C47377L, 7L, 0x0BC99BADL, 7L}}};
                int i, j, k;
                l_3074[4] |= (l_3064[0] != p_14);
                if (p_12)
                    break;
                for (g_256 = 0; (g_256 != (-15)); g_256 = safe_sub_func_uint16_t_u_u(g_256, 9))
                {
                    int32_t l_3086 = 1L;
                    int8_t l_3095 = (-1L);
                    for (l_2621 = 0; (l_2621 < (-5)); l_2621--)
                    {
                        uint8_t l_3083 = 0xF4L;
                        l_3097[0][4][2] = (l_3096 = (((g_1232 == (safe_mul_func_uint16_t_u_u((safe_mul_func_uint16_t_u_u((((l_3065 &= ((((l_3064[0] , ((g_2108[1][0] > l_3083) , ((safe_sub_func_uint8_t_u_u(((l_3086 > (1L <= (safe_add_func_int8_t_s_s(g_1302, ((((safe_sub_func_int16_t_s_s(((((safe_mod_func_uint8_t_u_u((safe_mul_func_uint8_t_u_u(((l_3083 != 0xBAL) & (-3L)), 4UL)), 1UL)) | p_11) || l_3074[5]) <= 0x39L), g_1303[4])) < g_1483[6]) , 0xB362L) ^ p_12))))) > 0xE8C3L), 255UL)) , 248UL))) & l_3095) , g_43) >= l_3095)) ^ 1L) , p_12), g_1232)), l_3064[0]))) | l_3064[0]) <= l_3074[4]));
                        l_3097[0][4][5] = (safe_mod_func_int32_t_s_s((-1L), (safe_lshift_func_uint8_t_u_u(((safe_mul_func_int8_t_s_s((safe_lshift_func_int16_t_s_u(((safe_rshift_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(254UL, (safe_mul_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(0xA8BBL, ((safe_mul_func_uint16_t_u_u(((p_11 & ((l_3095 == (g_332 = (safe_mod_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u((safe_sub_func_int32_t_s_s((0x67L ^ (-1L)), ((safe_sub_func_uint32_t_u_u(((safe_mod_func_uint8_t_u_u(l_3097[1][1][4], (((((p_11 , l_3086) >= 0x6C7475CCL) , 1UL) ^ 0L) , p_14))) != 0x1BL), l_3083)) || l_3097[0][4][2]))), p_12)), 5)), p_12)))) , l_2923[0])) < p_11), 0x9A4FL)) < 65535UL))), p_12)))), 1)) , l_3064[0]), g_257)), p_11)) || 0UL), 2))));
                        if (p_13)
                            break;
                    }
                }
            }
            else
            {
                l_3129++;
                l_3065 |= (((g_300 ^ 0L) >= ((safe_mul_func_uint8_t_u_u((g_211[0] = g_332), (((!0x7D7CL) != 0x78L) ^ ((safe_mul_func_int8_t_s_s(g_185[7][0][4], ((g_3008[3] = ((!((((((((((~1UL) != (!4UL)) || ((-1L) || 0x4C15L)) < l_3140) && 0x162CL) && p_11) , (-1L)) & 0x52CBL) , g_1752) , p_12)) > p_12)) , 0xACL))) ^ 4294967295UL)))) , g_1752)) == g_3059);

l_2812 &= ((g_2560 = (safe_mul_func_uint8_t_u_u((((((g_2792[1][5] , ((safe_sub_func_int8_t_s_s((!(safe_rshift_func_uint8_t_u_s(g_3069, (safe_sub_func_uint32_t_u_u((g_300 & (safe_lshift_func_uint8_t_u_s((l_3210 || 65535UL), l_3241))), g_3069))))), l_3309)) >= l_2507[0])) & 0xE176L) > 0xF7L) , l_3210) , 0x0FL), l_3309))) & 0xC21CL);


                    return p_13;
            }
        }
        g_1232 = ((safe_lshift_func_uint8_t_u_u(p_14, 4)) , g_331[2]);
        for (l_3065 = 0; (l_3065 < (-24)); l_3065--)
        {
            int32_t l_3145 = 0L;
            int32_t l_3169 = 0x71C19CD8L;
            uint32_t l_3170 = 0x055833AEL;
            int32_t l_3208[1][7][1] = {{{0L}, {0L}, {0L}, {0L}, {0L}, {0L}, {0L}}};
            int16_t l_3313 = 0x77DDL;
            uint8_t l_3380 = 0xF4L;
            int16_t l_3504 = 1L;
            int16_t l_3548 = 5L;
            int8_t l_3553 = 0x11L;
            uint16_t l_3554 = 0UL;
            int i, j, k;
            if (((g_497[0][0] = ((g_498 &= p_11) || l_3145)) || (l_2507[0] ^= (g_1303[6] = p_11))))
            {
                return g_129;
            }
            else
            {
                uint8_t l_3171 = 9UL;
                int32_t l_3206 = (-3L);
                int32_t l_3209 = 0L;
                int32_t l_3222 = (-10L);
                int32_t l_3223 = (-1L);
                uint32_t l_3378 = 7UL;
                int32_t l_3519[4][1];
                int i, j;
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 1; j++)
                        l_3519[i][j] = 0L;
                }
                if ((g_1925 = (((safe_rshift_func_uint16_t_u_u((safe_add_func_int16_t_s_s(((l_3128[4][1][4] = 0x89L) ^ ((((+0x85755261L) == (safe_add_func_uint16_t_u_u(((((safe_sub_func_uint32_t_u_u(0UL, (safe_rshift_func_int8_t_s_s(((0x96L | ((safe_rshift_func_int16_t_s_s(l_3145, (l_3169 = (((safe_rshift_func_uint16_t_u_u((((((g_1596 = (safe_mul_func_int16_t_s_s(g_392[3][7], (g_2792[1][7] = 3L)))) != (-1L)) ^ (safe_lshift_func_int16_t_s_s((safe_sub_func_int32_t_s_s((safe_mul_func_int16_t_s_s((((p_11 != l_3145) > l_3064[0]) < g_3069), g_2560)), g_1129)), p_12))) || g_184[3][1][0]) || g_331[2]), 15)) == 0xF7L) ^ g_184[4][0][0])))) | 7L)) >= 0x1DL), g_123)))) | l_3145) & l_2531) <= g_259), 0xE82BL))) , p_11) && l_3170)), 65532UL)), 8)) == p_11) >= (-5L))))
                {
                    g_1925 = p_13;
                }
                else
                {
                    uint32_t l_3201 = 4294967295UL;
                    int32_t l_3205 = 0xC0730222L;
                    int32_t l_3207 = 0x543A9B16L;
                    int32_t l_3211 = 1L;
                    int32_t l_3212 = 0L;
                    int32_t l_3213[4] = {0x507BCD5AL, 1L, 0x507BCD5AL, 1L};
                    uint32_t l_3215 = 1UL;
                    int i;
                    ++l_3171;
                    for (g_1925 = 0; (g_1925 != 27); ++g_1925)
                    {
                        int32_t l_3203 = (-2L);
                        int8_t l_3204 = (-5L);
                        int32_t l_3214 = 0xFC2FE0ECL;
                        int32_t l_3218 = (-8L);
                        int32_t l_3219 = (-1L);
                        int32_t l_3220[8] = {0x4FDEA941L, 0x214255FAL, 0x4FDEA941L, 0x214255FAL, 0x4FDEA941L, 0x214255FAL, 0x4FDEA941L, 0x214255FAL};
                        int i;
                        if (g_489)
                            break;
                        l_2507[0] = (g_2560 = (safe_rshift_func_uint8_t_u_s((+(safe_lshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s((0x5FL > 0x86L), ((safe_mul_func_int8_t_s_s((((safe_mul_func_uint8_t_u_u(((((safe_sub_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s((p_11 != g_3008[1]), g_256)), (((l_3145 & ((safe_rshift_func_int8_t_s_u((safe_mul_func_int8_t_s_s((safe_add_func_int8_t_s_s((safe_sub_func_uint8_t_u_u(l_3171, (g_128 == (((safe_add_func_uint8_t_u_u(g_1303[0], p_14)) ^ g_128) & l_3171)))), l_3201)), g_3202)), 7)) > l_3203)) & l_3204) != l_3145))) != l_3205) > g_2792[1][5]) | g_256), l_3205)) & p_12) < g_331[2]), l_3203)) || g_123))), 0))), l_3203)));
                        l_3215--;
                        l_3224--;
                    }
                }
                if ((((l_2445 , l_3170) , (p_14 != (safe_rshift_func_uint16_t_u_u((+(safe_add_func_int8_t_s_s(((((((g_257 |= 0x1310L) > ((((safe_add_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(((9UL || (safe_unary_minus_func_uint8_t_u(0x42L))) > (g_489 = (+(g_3238[0][2] = l_3169)))), 3)), l_3206)) , (((l_3241 = (g_3008[6]--)) , (((p_13 && l_2431[1]) >= g_348[1][2][0]) | p_14)) , g_1303[0])) , p_14) <= g_1302)) , g_499) , g_152[1][0]) < l_3128[4][1][4]) | l_3145), l_3049))), p_13)))) >= g_152[7][5]))
                {
                    uint32_t l_3244 = 0x9EBEB9EEL;
                    int8_t l_3269 = 0xA4L;
                    int32_t l_3270 = (-1L);
                    int32_t l_3308[2];
                    int i;
                    for (i = 0; i < 2; i++)
                        l_3308[i] = 1L;
                    for (g_2560 = 0; (g_2560 <= (-4)); g_2560--)
                    {
                        uint32_t l_3250 = 1UL;
                        int32_t l_3255 = (-1L);
                        int32_t l_3271 = 5L;
                        l_3244++;
                        g_1303[0] = p_11;
                        g_1371 = ((g_3059 >= g_498) , p_13);
                        l_3271 = (safe_unary_minus_func_int8_t_s(((safe_lshift_func_int16_t_s_s((p_14 <= (g_499 = l_3250)), ((safe_sub_func_int32_t_s_s(0x211E8D53L, ((safe_lshift_func_uint8_t_u_s((l_3270 = (((l_3255 = 255UL) > (safe_mul_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((l_3244 , ((safe_sub_func_uint8_t_u_u(g_152[2][5], ((safe_rshift_func_uint8_t_u_s(((((safe_lshift_func_uint16_t_u_u(((g_1850 || ((((g_43 |= ((0UL & p_13) < l_3210)) < g_498) | 0x1763L) | p_13)) == g_2108[6][3]), l_3169)) <= 0x09B7AB54L) , l_3268) == l_3209), p_12)) , g_3069))) <= l_3269)), 0)), l_2757)), l_3250))) , l_3269)), g_3008[1])) == p_11))) | 0L))) ^ g_3202)));
                    }
                    g_2845 ^= (safe_sub_func_uint32_t_u_u(((safe_add_func_int32_t_s_s(((((l_3270 = ((((safe_sub_func_int8_t_s_s((l_3208[0][0][0] , p_12), (safe_lshift_func_uint8_t_u_s(l_2923[1], 5)))) , (((safe_sub_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s((g_130 = ((g_499 = (l_3169 = (g_497[0][4] = 0xC00B44CAL))) , (((safe_lshift_func_int16_t_s_u(((safe_add_func_uint16_t_u_u(g_128, (l_3308[1] &= ((+(p_12 , ((safe_mul_func_uint8_t_u_u(((safe_mul_func_uint16_t_u_u(((safe_sub_func_uint16_t_u_u((((safe_lshift_func_int8_t_s_u(((safe_mul_func_int8_t_s_s((~((safe_add_func_uint16_t_u_u(0xCB47L, (safe_rshift_func_int8_t_s_s(p_12, 1)))) > ((g_1129 = (l_3209 ^= (((safe_sub_func_int32_t_s_s((safe_sub_func_uint8_t_u_u((g_184[6][0][2] || l_3244), p_12)), 1UL)) != p_12) | p_13))) & p_14))), 0xEAL)) < 0L), 4)) , l_3222) && g_1371), g_43)) , p_11), 0L)) >= l_3270), l_3222)) , p_13))) && g_130)))) && g_129), g_2108[6][3])) == 0x42L) > l_2445))), g_1850)) & l_3170) , l_3047), l_2431[3])) , 0xB4L) >= g_1482)) || 0x98E65B96L) && 4294967295UL)) , p_13) ^ l_3309) != l_3049), l_3206)) > 0xA9AB640BL), g_1303[0]));

for (g_2845 = 0; g_2845 < 1; g_2845++)
        l_2418[g_2845] = 0x54L;

                    for (l_2445 = 0; (l_2445 == (-28)); l_2445 = safe_sub_func_uint16_t_u_u(l_2445, 1))
                    {
                        int16_t l_3312 = 0xAD67L;
                        l_3312 = 0xA29FBB94L;
                    }
                }
                else
                {
                    uint32_t l_3314 = 6UL;
                    int32_t l_3322[10][6] = {{0xEDFB4805L, 0xEB9B0FDDL, (-8L), (-7L), 1L, 1L}, {0xEDFB4805L, 0xEB9B0FDDL, (-8L), (-7L), 1L, 1L}, {0xEDFB4805L, 0xEB9B0FDDL, (-8L), (-7L), 1L, 1L}, {0xEDFB4805L, 0xEB9B0FDDL, (-8L), (-7L), 1L, 1L}, {0xEDFB4805L, 0xEB9B0FDDL, (-8L), (-7L), 1L, 1L}, {0xEDFB4805L, 0xEB9B0FDDL, (-8L), (-7L), 1L, 1L}, {0xEDFB4805L, 0xEB9B0FDDL, (-8L), (-7L), 1L, 1L}, {0xEDFB4805L, 0xEB9B0FDDL, (-8L), (-7L), 1L, 1L}, {0xEDFB4805L, 0xEB9B0FDDL, (-8L), (-7L), 1L, 1L}, {0xEDFB4805L, 0xEB9B0FDDL, (-8L), (-7L), 1L, 1L}};
                    int i, j;
                    l_3314++;
                    if (((g_1752++) & (safe_lshift_func_int16_t_s_s(((l_2616 = p_12) < (!(++g_211[1]))), (g_1371 > g_705)))))
                    {
                        int8_t l_3340 = (-6L);
                        int32_t l_3379[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_3379[i] = 0xC7F93EFDL;
                        g_128 = ((safe_lshift_func_int8_t_s_u((safe_mod_func_int16_t_s_s((((p_11 > ((l_3222 ^= (((l_3241 | p_14) > ((safe_mod_func_uint8_t_u_u((g_2385 != (~((safe_mod_func_int8_t_s_s((safe_mod_func_int8_t_s_s(p_14, ((g_259 < (((251UL <= 0x99L) , (++g_499)) , (l_2616 = (safe_mod_func_int8_t_s_s(6L, l_3064[0]))))) && 255UL))), (-1L))) == l_3340))), p_13)) , g_1596)) && p_14)) | g_705)) != 5L) > l_3208[0][0][0]), p_12)), p_12)) == 0x56L);
                        l_3223 = ((+(((!((((safe_mod_func_int16_t_s_s(0xF947L, (((((safe_mod_func_uint32_t_u_u(((-1L) || (((safe_mod_func_uint32_t_u_u((l_3206 = (safe_add_func_int32_t_s_s((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(6UL, 2)), (l_3322[4][2] = ((p_12 , (g_184[1][2][1] , ((safe_mul_func_int16_t_s_s((((l_3128[4][1][4] |= (p_11 ^= ((safe_add_func_uint16_t_u_u(((g_570 && (safe_add_func_int16_t_s_s(p_12, (~(safe_mul_func_int16_t_s_s((0L || ((((safe_sub_func_uint32_t_u_u((g_129 != g_3059), 0x84F36AFEL)) || l_3322[0][4]) == l_2757) != p_13)), l_3171)))))) < g_152[7][5]), 7L)) , g_1676[4]))) <= g_705) || l_3221[3]), p_13)) <= 0xAA83L))) <= g_332)))), g_271))), 0xBC476770L)) > g_43) >= 1UL)), l_3314)) & p_13) <= p_14) | g_332) , g_185[6][0][2]))) && g_1482) < 0x163CD058L) < p_14)) | 0x93CFL) & (-1L))) > 65529UL);
                        l_3379[0] = (safe_rshift_func_uint16_t_u_u(((g_3008[3] = (safe_mul_func_uint8_t_u_u(((((safe_mul_func_int16_t_s_s((safe_lshift_func_uint8_t_u_u((l_3322[0][4] = ((safe_sub_func_uint8_t_u_u(((p_11 || 0x1F0BL) || (((((0x5BB838FAL | (safe_mod_func_uint16_t_u_u(p_14, p_13))) == (-1L)) <= l_3169) <= (l_3223 & ((1UL == p_12) | p_11))) && l_3378)), p_11)) ^ 0x841E669FL)), g_123)), g_259)) == l_3314) < g_2385) ^ g_2560), p_11))) & 0xB3E4L), 1));
                    }
                    else
                    {
                        l_3380--;
                        l_3390 = ((g_499 = ((l_3128[4][1][4] &= 1L) ^ (safe_lshift_func_int8_t_s_u((g_498 ^= (p_12 & (g_670 = (safe_add_func_uint32_t_u_u((1UL | ((~(-1L)) || (p_11 , ((safe_add_func_int8_t_s_s(l_2923[0], (l_3206 | ((g_1482 = (((0x0DL == 0xF5L) == g_186) , 0L)) | l_3047)))) >= g_211[1])))), p_12))))), 5)))) > l_3065);
                        l_2507[0] = g_498;
                    }
                    if (g_1850)
                        {
if (l_3222) printf("index = [%d]\n", g_1850);

                    continue;}

{
        for (g_1232 = 0; g_1232 < 10; g_1232++)
        {
            transparent_crc(g_497[l_3169][g_1232], "g_497[l_3169][g_1232]", g_1850);
            if (g_1850) printf("index = [%d][%d]\n", l_3169, g_1232);

        }
    }

                    for (g_1129 = 0; (g_1129 <= 7); g_1129 += 1)
                    {
                        int32_t l_3393[8] = {0x929D46EDL, 0x929D46EDL, 0x04856239L, 0x929D46EDL, 0x929D46EDL, 0x04856239L, 0x929D46EDL, 0x929D46EDL};
                        int i;
                        l_3393[1] = (((g_1752++) == (g_1303[g_1129] = (g_3008[(g_1129 + 1)] >= l_3314))) == (g_1676[9] & (g_3008[(g_1129 + 1)] != ((((((g_570 = ((g_348[1][2][0] < (g_3008[(g_1129 + 1)] | ((l_3047 &= ((g_2108[2][3] > (0x65L != p_13)) , p_12)) | 1UL))) >= p_11)) >= g_256) , l_3209) < l_3145) == p_11) , 5L))));
                        g_1303[6] = (safe_mul_func_uint16_t_u_u((((g_1752 | (safe_sub_func_uint32_t_u_u((0x0CL & g_499), (+((((+(((l_3128[0][2][5] &= (safe_sub_func_int32_t_s_s(p_12, l_3129))) && (safe_lshift_func_uint8_t_u_u((((-1L) <= ((safe_sub_func_uint32_t_u_u(l_3140, (((0xFA448F8AL != ((((+(safe_add_func_uint32_t_u_u(g_257, p_12))) <= 65528UL) && g_348[1][2][0]) | g_257)) | p_12) , g_1303[g_1129]))) || 0xD03F4EF0L)) <= (-1L)), p_13))) > l_3222)) > l_3224) < p_14) == p_11))))) == g_298) | g_1371), p_13));
                    }
                }

for (i = 0; i < 3; i++)
            {
                transparent_crc(g_184[l_3169][l_3552][i], "g_184[l_3169][l_3552][i]", l_3551);
                if (l_3551) printf("index = [%d][%d][%d]\n", l_3169, l_3552, i);

            };


                    if ((((((safe_add_func_int32_t_s_s(0xAD52E694L, (l_3380 | (g_489 = (+(safe_add_func_int8_t_s_s(l_3223, ((safe_add_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((((!0xEBL) < p_14) | (safe_add_func_int16_t_s_s((safe_add_func_int32_t_s_s((safe_lshift_func_uint8_t_u_s(1UL, p_12)), (l_3208[0][0][0] ^= p_12))), ((((+(g_2792[1][5] = (l_3169 ^= ((((g_186 && 0xF8A200C9L) >= p_12) ^ g_8) , 0x5753L)))) != 0x18L) < 0xFB9CL) | 65535UL)))), g_1676[0])) , g_497[0][6]), p_13)) && l_3378)))))))) , p_13) != 65533UL) , 0x464EB96BL) | l_2812))
                {
                    uint32_t l_3446 = 0x972E8BEFL;
                    g_128 = ((safe_mul_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((-3L) & (safe_rshift_func_int16_t_s_s((g_128 >= (p_13 = (safe_mod_func_uint16_t_u_u(((l_3128[4][5][0] &= (l_3208[0][4][0] , (safe_add_func_uint32_t_u_u(((safe_sub_func_uint8_t_u_u((safe_add_func_int8_t_s_s(g_1129, (safe_lshift_func_int16_t_s_s(p_13, 10)))), (((safe_lshift_func_int8_t_s_s(((l_3208[0][2][0] = 0xE2CCL) != (((l_3209 != ((p_13 <= ((safe_lshift_func_int8_t_s_u((l_2616 <= l_3446), 4)) , g_331[2])) <= p_13)) | g_3202) || p_14)), 0)) == 251UL) || g_1483[6]))) && l_3145), 4294967295UL)))) == l_3209), g_185[6][0][7])))), 8))), 0x78L)), p_12)) || g_2845);
                    g_2560 = ((((g_3069 , (+(((((g_2792[0][6] ^= (l_3209 &= (((safe_sub_func_uint32_t_u_u((g_348[0][4][0] < ((g_3475 |= (((safe_add_func_int32_t_s_s(0L, (p_11 && ((p_11 > (safe_mod_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((1UL & (safe_lshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u((((l_2507[0] = ((~(safe_rshift_func_uint8_t_u_s((((safe_rshift_func_uint8_t_u_s((safe_rshift_func_uint8_t_u_u(((safe_sub_func_uint16_t_u_u(((p_13 & (safe_lshift_func_uint16_t_u_u(l_3049, (((((safe_add_func_uint16_t_u_u((l_3473 = (g_1232 > 8UL)), g_331[7])) > l_2431[3]) >= g_497[0][7]) == p_12) , g_185[6][0][2])))) , l_3129), p_13)) ^ p_12), l_3128[4][1][4])), g_43)) <= p_13) <= 5UL), 5))) <= g_1676[6])) & 0xCCC2C11AL) && l_3145), 7)) != 0xE78A2021L), g_152[7][5]))) >= g_3238[0][2]), l_3064[0])), 0xB511L))) , l_3474)))) , g_1676[3]) , l_3049)) , p_12)), l_3446)) >= g_257) , 0xC01CL))) , 4294967290UL) && p_11) || l_3446) && 0xADL))) | 0L) && 0x26L) ^ l_3065);
                    l_3504 = (l_3206 = ((safe_add_func_uint16_t_u_u((((l_3171 > (safe_rshift_func_uint8_t_u_s((safe_rshift_func_int8_t_s_u((safe_lshift_func_int8_t_s_s((safe_mul_func_uint8_t_u_u(((safe_mul_func_uint8_t_u_u((((g_3008[3] = ((((safe_rshift_func_uint8_t_u_u(((l_3208[0][0][0] , (safe_mul_func_int16_t_s_s((g_152[7][5] = ((safe_mod_func_int8_t_s_s(p_11, g_2108[6][3])) < (safe_lshift_func_uint16_t_u_s((safe_sub_func_int32_t_s_s((-8L), (l_3128[0][5][2] |= l_3313))), (safe_add_func_uint16_t_u_u((((safe_mul_func_uint8_t_u_u(l_3208[0][0][0], (safe_add_func_uint32_t_u_u(p_13, 0x56F8913AL)))) <= 0x51BDL) < l_3446), l_3222)))))), p_14))) | g_2845), l_3064[0])) , 0x6675L) & p_11) ^ l_2757)) < l_3446) || l_3446), g_1232)) , l_3128[2][4][3]), p_13)), 7)), 5)), 0))) , g_1925) , p_12), 0x933AL)) > 0x3DB2431BL));
                }
                else
                {
                    int32_t l_3518 = 0x613CF344L;
                    for (g_3475 = 0; (g_3475 <= 7); g_3475 += 1)
                    {
                        int i;
                        if (g_1483[g_3475])
                            {
g_1371 &= (l_3518 = (((l_3546 , g_152[4][4]) > 0x713BL) , l_3546));


                    break;}
                    }
                    l_3047 = (((g_43 != (safe_mod_func_int16_t_s_s(0x07F0L, 0xD59CL))) == ((~(g_670 = (l_3169 = (((0x53L <= ((safe_add_func_int32_t_s_s((safe_add_func_int8_t_s_s((p_11 > ((((--g_499) != g_2792[0][9]) | (safe_sub_func_uint8_t_u_u((p_12 <= l_3145), ((g_298 > l_3518) && l_3519[3][0])))) && 0x7F5B296CL)), 0UL)), 0x46B81B9BL)) < 0x6EL)) & l_3210) & 0x71L)))) || 0L)) || p_14);
                }
                g_1925 = (g_1483[5] , ((0x3AF0L < g_184[8][0][0]) == (safe_mod_func_uint16_t_u_u((safe_add_func_int8_t_s_s(((((!(+6L)) >= (safe_rshift_func_int16_t_s_u(l_2812, 13))) <= l_3380) ^ l_3064[0]), (((l_3140 , (l_3519[3][0] = ((0xFC4CL | g_348[1][2][0]) <= p_11))) , 0xA2F6E2ABL) & g_1302))), 65534UL))));
            }
            for (g_1232 = (-25); (g_1232 != (-9)); g_1232 = safe_add_func_uint16_t_u_u(g_1232, 1))
            {
                int32_t l_3541 = 0x19BD880CL;
                int32_t l_3542[9] = {0x83D566D0L, 0x83D566D0L, 1L, 0x83D566D0L, 0x83D566D0L, 1L, 0x83D566D0L, 0x83D566D0L, 1L};
                int32_t l_3543 = 0xBFAFFB6AL;
                int32_t l_3545[9] = {(-4L), 4L, (-4L), 4L, (-4L), 4L, (-4L), 4L, (-4L)};
                int8_t l_3550[8] = {0x0EL, 0x8EL, 0x0EL, 0x8EL, 0x0EL, 0x8EL, 0x0EL, 0x8EL};
                int8_t l_3587 = 0x61L;
                int i;
                g_1371 = (safe_mul_func_int8_t_s_s(g_1482, ((safe_rshift_func_uint8_t_u_s(l_3504, (safe_add_func_int16_t_s_s(((g_184[6][0][2] < ((((l_3545[8] = ((p_13 , p_13) == ((p_11 < (safe_sub_func_int16_t_s_s((-1L), (((safe_mod_func_uint16_t_u_u(((g_332 = p_13) & (+(l_3543 = ((l_3542[4] = ((l_3541 , l_3129) && p_13)) , 2L)))), l_3544[3])) > g_300) > 1L)))) , g_185[3][0][6]))) != p_14) | (-1L)) >= p_14)) <= 0x4DA2C610L), p_12)))) , (-1L))));
                if (l_3221[1])
                    break;
                --l_3554;
                g_2560 = ((safe_lshift_func_int8_t_s_s(((safe_mod_func_int8_t_s_s((safe_add_func_int32_t_s_s(0L, (safe_lshift_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_u((safe_rshift_func_uint8_t_u_s((((((safe_add_func_int32_t_s_s((((l_3169 = (l_3541 == ((l_3551 = (l_3541 <= (((safe_rshift_func_int16_t_s_u(p_13, 1)) , (safe_sub_func_int32_t_s_s(((l_3208[0][0][0] |= (((l_3543 = (g_705--)) , (((safe_sub_func_uint16_t_u_u(65535UL, (safe_lshift_func_uint8_t_u_u(g_570, ((safe_add_func_int8_t_s_s(((safe_sub_func_int16_t_s_s((l_3544[0] = ((g_332 = ((-6L) > 65535UL)) & (safe_rshift_func_int16_t_s_u(((l_3550[3] | g_271) | g_2792[0][9]), 4)))), p_12)) > g_3475), 0x59L)) & 0L))))) , 0UL) < p_12)) | 0xCDL)) , g_259), g_129))) <= (-7L)))) ^ l_3065))) && l_3210) & p_13), p_14)) >= p_12) >= 0xFEBDL) | (-2L)) < 4294967295UL), g_1596)), 8)) ^ l_3587) && l_3064[0]), 7)))), l_3554)) <= g_497[0][0]), p_14)) < 0x2D31B660L);
            }
            g_2560 = (l_3551 = ((~(safe_rshift_func_uint8_t_u_s(0x39L, (p_11 | (p_11 <= (safe_mod_func_int32_t_s_s(p_13, p_14))))))) && g_2560));
            if (g_256)
                goto lbl_3593;
        }
    }
    return p_13;
}







static uint8_t func_15(int32_t p_16, int32_t p_17)
{
    int32_t l_2381 = (-1L);
    int32_t l_2383[2];
    uint32_t l_2412 = 0xCBC5DC9AL;
    uint32_t l_2413 = 1UL;
    uint8_t l_2415 = 0x5BL;
    int i;
    for (i = 0; i < 2; i++)
        l_2383[i] = (-4L);
    for (g_499 = 17; (g_499 != 37); g_499++)
    {
        uint8_t l_2377 = 2UL;
        int32_t l_2378 = (-1L);
        int32_t l_2382 = 1L;
        int32_t l_2384 = 0x8E5D3742L;
        int32_t l_2414 = 9L;
        g_1371 = (((((l_2378 |= (l_2377 = (p_16 , (0x93253A1DL > 4294967292UL)))) , g_1483[6]) != ((safe_mul_func_uint8_t_u_u(0x48L, ((((l_2383[0] |= (0xC666A200L > (p_16 > ((((l_2381 && 0xA7L) > 1L) | l_2382) > 0xB2L)))) < p_16) && 0x15L) , g_331[2]))) != p_17)) == 252UL) & g_8);
                                       uint32_t B6j6jg_499 = (~((((l_2415 || g_2385) << g_186) | (((~(g_256)) << (l_2382 & (l_2414 & (~(l_2384))))) | (g_670 | (~((~(l_2381)))))))));
int32_t B6j6jbl_2381 = (~(((~((~(l_2384)))) || ((~(((~(g_256)) & (g_2385 | (~(l_2381)))))) ^ (~((((B6j6jg_499 ^ (g_670 ^ l_2415)) & (~((l_2414 & g_186)))) & (~(l_2382)))))))));
int32_t B6j6jcg_256 = (~(((~(B6j6jbl_2381)) ^ (~(((~(((l_2381 ^ (~(l_2382))) & ((l_2414 | g_670) & l_2415)))) ^ (~((g_186 ^ (l_2384 & g_256))))))))));
if((!((g_670<=65529)) || ((!l_2415) || (B6j6jbl_2381<=-2)))){
B6j6jg_499 = g_499;
B6j6jbl_2381 = l_2381;
B6j6jcg_256 = g_256;
g_499 = (~((((l_2414 | l_2384) || ((((l_2382 || B6j6jbl_2381) | (~((~(B6j6jcg_256))))) ^ (g_186 | g_256)) ^ g_670)) | l_2415)));
l_2381 = (~(((~(((g_670 || ((~(((~(l_2381)) >> l_2414))) | g_186)) | (~((l_2384 | (g_256 & l_2382))))))) | (~((~((~((g_499 & (~(l_2415))))))))))));
g_256 = (~(((~(l_2382)) | (~(((~(((~(l_2381)) ^ (~(B6j6jbl_2381))))) | ((((~(g_670)) || l_2384) ^ (l_2414 || l_2415)) >> (g_186 >> g_2385))))))));
if(((B6j6jbl_2381 < B6j6jcg_256) && (g_2385 < g_256))){
printf("g_499=%llu\n", (unsigned long long)g_499);
g_499 = (~(((~(((~(l_2384)) & (~((((~(g_499)) << B6j6jbl_2381) | (~((~(((g_2385 & (l_2382 | l_2414)) & (l_2415 >> g_256)))))))))))) << (~((~(B6j6jcg_256)))))));
continue;
}
if((!((l_2415 < B6j6jg_499)) && (g_670>65529))){
printf("g_256=%lld\n", (long long)g_256);
l_2381 = (~((((B6j6jcg_256 | l_2384) ^ ((g_256 | l_2415) & (l_2414 | g_186))) ^ (~((((B6j6jbl_2381 || g_670) & g_2385) & (~(g_499))))))));
g_499 = (~(((~(((l_2384 >> l_2381) << (~(((~((g_2385 >> l_2415))) ^ (~((((~((~(g_256)))) ^ g_186) ^ g_670))))))))) << (~((~((~((B6j6jcg_256 >> l_2414))))))))));
continue;
}
}
g_499 = B6j6jg_499;
l_2381 = B6j6jbl_2381;
g_256 = B6j6jcg_256;

                    if (g_392[2][2])
            { uint32_t B6j6jdg_1752 = (~(((~(l_2378)) | (((g_670 & (~((~(((~((~(l_2382)))) | l_2412)))))) ^ (l_2414 & ((~((g_1752 & g_1371))) << (~((~(g_298))))))) ^ (~(l_2413))))));
uint32_t B6j6jel_2412 = (~((((~(g_1752)) << (~((((~(l_2414)) || (g_298 & l_2378)) | (~(g_1371)))))) | (~((~(((((~(l_2382)) | B6j6jdg_1752) ^ (~(l_2413))) || l_2412))))))));
int32_t B6j6jfl_2382 = (~(((~((~((g_1752 | (B6j6jdg_1752 || g_670)))))) << ((l_2414 ^ (~(g_1371))) || (((~(l_2413)) ^ (~((~(l_2412))))) ^ (~((l_2378 & B6j6jel_2412))))))));
if(!((g_298 < l_2378))){
B6j6jdg_1752 = g_1752;
B6j6jel_2412 = l_2412;
B6j6jfl_2382 = l_2382;
g_1752 = (~(((~((~(((~((l_2412 || g_1752))) || ((g_298 & l_2414) | (~(g_670)))))))) || (((~((~(l_2378)))) | (~((g_1371 << B6j6jfl_2382)))) ^ l_2382))));
l_2412 = (~(((~((~((~((l_2378 || (B6j6jfl_2382 & B6j6jel_2412)))))))) || ((~((l_2412 << (~((~(l_2382))))))) | (((l_2413 & (~(g_1371))) ^ B6j6jdg_1752) ^ (~(l_2414)))))));
l_2382 = (~(((~((~(((((~(l_2382)) ^ g_1371) ^ (~(l_2378))) ^ B6j6jel_2412))))) || (((l_2414 | (l_2413 | B6j6jdg_1752)) | (~(g_298))) | (~(B6j6jfl_2382))))));
if((l_2378 > l_2414)){
printf("g_1752=%llu\n", (unsigned long long)g_1752);
break;
}
if((B6j6jfl_2382 > g_670)){
printf("l_2412=%llu\n", (unsigned long long)l_2412);
break;
}
if((!g_499)){
printf("l_2382=%lld\n", (long long)l_2382);
B6j6jel_2412 = (~(((~(((~((g_1752 & (g_670 << (~((l_2412 << (~((~(B6j6jdg_1752))))))))))) || (~(g_298))))) << (~(((~((l_2413 || (~(B6j6jel_2412))))) & (~((B6j6jfl_2382 >> l_2378)))))))));
g_1752 = (~((((~(g_298)) | (g_1752 | l_2382)) ^ (((~(l_2413)) ^ (g_1371 | l_2378)) | (B6j6jfl_2382 ^ (B6j6jel_2412 ^ l_2412))))));
}
}
g_1752 = B6j6jdg_1752;
l_2412 = B6j6jel_2412;
l_2382 = B6j6jfl_2382;

                    continue;}
        for (g_670 = 0; (g_670 <= 9); g_670 += 1)
        {
            int i;
            g_1232 = g_1676[g_670];
            g_2385++;
        }
        for (g_186 = (-25); (g_186 < 17); g_186 = safe_add_func_uint32_t_u_u(g_186, 1))
        {
            int16_t l_2402 = 1L;
            l_2414 &= (safe_sub_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s(((safe_mul_func_uint16_t_u_u((safe_mod_func_uint8_t_u_u(((p_17 , 0x34F1L) == ((safe_rshift_func_uint16_t_u_u(l_2384, 7)) >= ((((0x137A8676L || ((--g_211[1]) < ((safe_lshift_func_uint8_t_u_s(((((l_2382 < (65535UL | (((safe_sub_func_uint8_t_u_u((((safe_lshift_func_int16_t_s_s((p_16 & (((l_2378 = (!(g_298 != (l_2412 , p_17)))) > 0x6EL) , l_2378)), g_1752)) >= g_271) >= l_2377), l_2413)) || l_2402) & l_2402))) && g_185[6][0][5]) > g_256) ^ g_499), l_2383[0])) <= l_2381))) ^ p_17) , l_2402) , g_211[1]))), 255UL)), p_16)) != 0L), 1)), 0xE7L));
            if (g_8)
                break;
            return l_2377;
        }
    }
    --l_2415;
                                        if ((g_271 < l_2415) )
{

g_1302 += 1;


}
                    return g_259;
}







static int16_t func_20(uint32_t p_21, uint16_t p_22, int8_t p_23, int16_t p_24)
{
    uint32_t l_1861[7] = {4294967295UL, 4294967295UL, 0UL, 4294967295UL, 4294967295UL, 0UL, 4294967295UL};
    int32_t l_1862 = 0xF57B2FD2L;
    int32_t l_1873[4][6][1] = {{{0L}, {0L}, {0L}, {0L}, {0L}, {0L}}, {{0L}, {0L}, {0L}, {0L}, {0L}, {0L}}, {{0L}, {0L}, {0L}, {0L}, {0L}, {0L}}, {{0L}, {0L}, {0L}, {0L}, {0L}, {0L}}};
    int32_t l_1874[9][2] = {{0xB1BFF744L, 0x84ED0D24L}, {0xB1BFF744L, 0x84ED0D24L}, {0xB1BFF744L, 0x84ED0D24L}, {0xB1BFF744L, 0x84ED0D24L}, {0xB1BFF744L, 0x84ED0D24L}, {0xB1BFF744L, 0x84ED0D24L}, {0xB1BFF744L, 0x84ED0D24L}, {0xB1BFF744L, 0x84ED0D24L}, {0xB1BFF744L, 0x84ED0D24L}};
    int32_t l_1875 = 0x8864BE46L;
    uint32_t l_1876 = 0x901C7A3BL;
    int32_t l_1877 = 0x43B984A8L;
    uint16_t l_1878[6][6];
    int32_t l_1879 = 1L;
    uint8_t l_1882 = 0x2FL;
    uint32_t l_1893 = 4294967295UL;
    int8_t l_2060 = (-3L);
    uint8_t l_2110 = 0xBAL;
    int32_t l_2111 = 7L;
    uint16_t l_2211[3];
    int32_t l_2215 = 8L;
    int8_t l_2277 = 0xB4L;
    uint8_t l_2278 = 255UL;
    int16_t l_2362 = 1L;
    uint16_t l_2371 = 0xEA6AL;
    int i, j, k;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
            l_1878[i][j] = 2UL;
    }
    for (i = 0; i < 3; i++)
        l_2211[i] = 65532UL;
    l_1879 = ((((g_1303[0] = (l_1877 = ((safe_mul_func_uint8_t_u_u((g_184[6][0][2] > ((safe_add_func_uint16_t_u_u(0x5ED8L, (g_497[0][9] == (safe_sub_func_int16_t_s_s(((l_1861[2] || p_24) & (l_1862 = 0xECL)), (((l_1861[2] , ((safe_mul_func_int16_t_s_s((safe_mul_func_int16_t_s_s((safe_lshift_func_int16_t_s_u((0x13D21411L || ((((safe_lshift_func_int16_t_s_u((l_1875 &= (l_1874[6][1] = (l_1873[0][5][0] = (((safe_lshift_func_uint16_t_u_u(((-1L) < g_257), p_24)) | 0xB7FDL) > l_1861[3])))), 6)) || g_1850) == (-1L)) != 9L)), 1)), p_21)), 65530UL)) , 0x55L)) > p_23) < l_1876)))))) , 3L)), p_24)) < g_1676[3]))) ^ l_1878[1][0]) , (-7L)) || p_24);
                                   if (!((g_1302 > l_1862)))
                    lbl_2119:
    for (g_1371 = (-30); (g_1371 <= 4); g_1371++)
    {
        return l_1873[0][5][0];
    }
    if ((l_1882 | ((((l_1875 |= ((((p_21--) , 255UL) > (g_1482 &= ((p_23 != ((((safe_mod_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s(l_1873[0][5][0], p_23)), 65529UL)) ^ (safe_mul_func_uint8_t_u_u((g_1483[6] && (safe_lshift_func_uint8_t_u_s(p_24, 3))), p_24))) && l_1878[1][0]) ^ l_1862)) & p_23))) >= 4294967287UL)) | l_1893) , g_498) == g_1752)))
    {
        uint32_t l_1906 = 0xEA4C5961L;
        int32_t l_1913 = (-1L);
        int32_t l_1914 = 1L;
        int32_t l_1915 = 0L;
        uint32_t l_1916 = 0UL;
        int32_t l_1965 = 0x4FF67899L;
        int32_t l_1996 = 0x7992CE25L;
        int32_t l_1998 = (-1L);
        int32_t l_2009 = 0xE429D551L;
        int32_t l_2010[4][10] = {{5L, 0xD19C2C08L, 1L, 0xD19C2C08L, 5L, 0xAEDCF459L, 5L, 0xD19C2C08L, 1L, 0xD19C2C08L}, {5L, 0xD19C2C08L, 1L, 0xD19C2C08L, 5L, 0xAEDCF459L, 5L, 0xD19C2C08L, 1L, 0xD19C2C08L}, {5L, 0xD19C2C08L, 1L, 0xD19C2C08L, 5L, 0xAEDCF459L, 5L, 0xD19C2C08L, 1L, 0xD19C2C08L}, {5L, 0xD19C2C08L, 1L, 0xD19C2C08L, 5L, 0xAEDCF459L, 5L, 0xD19C2C08L, 1L, 0xD19C2C08L}};
        int32_t l_2011 = (-2L);
        uint32_t l_2146 = 0x428FE84FL;
        int32_t l_2171 = 1L;
        int32_t l_2174[7][2][10] = {{{7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}, {7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}}, {{7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}, {7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}}, {{7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}, {7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}}, {{7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}, {7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}}, {{7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}, {7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}}, {{7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}, {7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}}, {{7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}, {7L, 7L, 0x5DB299A6L, 5L, 0L, 0L, 0L, 0x0D5E0A1DL, 1L, 0x02D8AD30L}}};
        int8_t l_2206 = 4L;
        uint32_t l_2212 = 0x4F4B70A0L;
        int i, j, k;
        g_1303[0] &= (safe_lshift_func_uint8_t_u_s((((safe_mod_func_int16_t_s_s((safe_mul_func_int16_t_s_s(p_21, (safe_mul_func_int16_t_s_s((safe_mod_func_int8_t_s_s(((((l_1861[2] == ((((((safe_lshift_func_uint8_t_u_u((g_186 | ((g_497[0][6] <= l_1906) == 0x8A27L)), l_1882)) == (p_24 && ((safe_lshift_func_uint8_t_u_u(((p_22 = (safe_mod_func_uint32_t_u_u(((safe_sub_func_int32_t_s_s(9L, l_1913)) || 0xEBF8L), (-3L)))) <= g_271), 5)) < p_21))) != l_1906) > p_23) < 0x34C26843L) <= p_24)) , p_23) , g_259) != p_23), g_489)), g_348[0][2][0])))), 0x78F8L)) != 4UL) && (-8L)), 6));
lbl_2061:
        l_1916--;
        for (p_21 = 0; p_21 < 8; p_21 += 1)
        {

g_570 ^= (safe_sub_func_uint16_t_u_u(((safe_mul_func_int8_t_s_s(g_185[6][0][2], (((g_1482 = (g_331[2] = g_152[7][5])) >= (safe_mul_func_uint8_t_u_u((g_298 >= 0xF371L), ((l_2171 = (safe_lshift_func_uint8_t_u_s((safe_mul_func_uint8_t_u_u(((g_1596 > ((0UL ^ (0xB62024FCL > p_23)) && l_2110)) , g_211[1]), 252UL)), 1))) <= g_152[7][5])))) <= l_2110))) == l_1965), g_2385));


                    g_1303[p_21] = 0x902FB455L;
        }
        if ((safe_rshift_func_int8_t_s_u((safe_add_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_u((g_1925 & g_1676[3]), 5)) < 0xD9C5AFA1L), ((((g_257 , g_348[1][6][0]) <= (0x37L || (g_186 = (((safe_rshift_func_uint8_t_u_u((l_1915 = 0x00L), (g_129 ^ (safe_lshift_func_uint8_t_u_u(((safe_add_func_int16_t_s_s((l_1875 ^= (l_1873[0][5][0] , 0x8354L)), g_1232)) <= g_184[4][3][1]), l_1914))))) >= g_300) , l_1914)))) , p_22) & 0L))), l_1893)))
        {
            uint16_t l_1936 = 1UL;
            uint8_t l_1951 = 248UL;
            int32_t l_1978 = 5L;
            int32_t l_1979 = (-6L);
            int32_t l_2001 = (-1L);
            int32_t l_2002 = (-1L);
            int32_t l_2004 = 0x13CF4E77L;
            int32_t l_2006[2][2] = {{1L, 0xFB666DDAL}, {1L, 0xFB666DDAL}};
            int8_t l_2007 = 0xC8L;
            int16_t l_2109 = (-3L);
            int i, j;
            g_1303[0] = (l_1914 , l_1916);
            for (p_22 = 1; (p_22 <= 40); p_22 = safe_add_func_int16_t_s_s(p_22, 8))
            {
                int32_t l_1957[2][7][10] = {{{0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}, {0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}, {0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}, {0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}, {0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}, {0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}, {0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}}, {{0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}, {0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}, {0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}, {0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}, {0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}, {0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}, {0L, (-1L), 0xB1625B49L, 0x44B0B19FL, 0L, (-2L), (-1L), (-1L), 0x01ECEE30L, 0xF542E35FL}}};
                int16_t l_1960[2][8][8] = {{{0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}}, {{0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}, {0x5CCBL, (-1L), 7L, 0x2D07L, (-1L), 0x7E51L, (-1L), 0x2D07L}}};
                uint32_t l_1967[6] = {0x9E030B8BL, 0x9E030B8BL, 0xA17A278BL, 0x9E030B8BL, 0x9E030B8BL, 0xA17A278BL};
                int32_t l_2005 = 0x0DC349A7L;
                uint8_t l_2036[4] = {0x7BL, 5UL, 0x7BL, 5UL};
                uint16_t l_2086 = 0x8FD3L;
                int i, j, k;
                for (g_1371 = 0; (g_1371 >= 16); g_1371++)
                {
                    int32_t l_1959[1];
                    int i;
                    for (i = 0; i < 1; i++)
                        l_1959[i] = (-10L);
                    if (p_22)
                    {
                        uint32_t l_1958 = 1UL;
                        int32_t l_1961 = 9L;
                        l_1936--;
                        l_1915 = g_497[0][6];
                        l_1957[1][1][8] = ((l_1873[3][5][0] = ((safe_lshift_func_uint8_t_u_s((g_211[0] = (g_186 = p_21)), 2)) || g_499)) <= (((safe_mod_func_uint16_t_u_u(((((g_129 ^ g_570) & (((((safe_sub_func_uint8_t_u_u(((!(+(((((safe_mul_func_uint8_t_u_u((((((safe_add_func_uint32_t_u_u(l_1951, (safe_lshift_func_int8_t_s_s((l_1958 = (((((g_256 < (((g_1303[0] ^ (g_483 , (((safe_mod_func_int16_t_s_s((+(-1L)), 65532UL)) | g_130) , p_24))) ^ 4294967292UL) < l_1957[1][1][8])) < l_1936) & p_22) , 0x4D484A7EL) , 0xAAL)), 7)))) != g_1371) <= l_1959[0]) || l_1862) < g_184[0][3][0]), 0UL)) && p_23) < l_1957[0][2][0]) || l_1957[1][2][8]) > g_1850))) != g_499), 3UL)) & l_1951) & l_1960[0][1][4]) == 0x76L) , 255UL)) > l_1874[6][1]) , 0x6043L), l_1936)) <= g_152[7][5]) | 7L));
                        l_1961 = g_184[6][0][2];
                    }
                    else
                    {
                        int32_t l_1962 = 0xF4AACF3AL;
                        int32_t l_1963 = 0xF68E3FA7L;
                        int32_t l_1964 = 9L;
                        int32_t l_1966[4][7] = {{(-1L), (-1L), 0L, 0L, 9L, 0L, 0L}, {(-1L), (-1L), 0L, 0L, 9L, 0L, 0L}, {(-1L), (-1L), 0L, 0L, 9L, 0L, 0L}, {(-1L), (-1L), 0L, 0L, 9L, 0L, 0L}};
                        int i, j;
                        l_1967[4]++;
                        l_1915 = (-5L);
                        l_1966[2][6] ^= (((p_22 > (l_1915 = (p_21--))) >= l_1959[0]) | (g_211[0] & (safe_lshift_func_uint8_t_u_u((0x4E5AB01BL >= g_392[3][0]), 7))));
                        if (g_392[2][0])
                            break;
                    }
                    g_1303[0] = l_1959[0];
                }
                if ((safe_rshift_func_int16_t_s_u(((((0xEFE8L < ((safe_rshift_func_int8_t_s_s((-1L), ((p_23 = l_1873[2][1][0]) || (-1L)))) == p_21)) , (0UL <= ((--g_497[0][0]) & ((safe_mod_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u(((safe_sub_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_s((-1L), ((safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_s((l_1877 && ((0xD6E1L >= l_1916) , 0x616883DAL)), p_23)), 0x7C91DDBBL)) ^ p_23))) && (-1L)), p_21)) | g_184[6][0][2]), p_21)), 0x2E07L)) , p_22)))) ^ l_1879) | g_130), 2)))
                {
                    int16_t l_1994[7] = {0xB4BEL, 0x103BL, 0xB4BEL, 0x103BL, 0xB4BEL, 0x103BL, 0xB4BEL};
                    int32_t l_1995 = 0xE169147DL;
                    int32_t l_1997 = 0x9BFC0741L;
                    int32_t l_1999 = 0x37DDB7A1L;
                    int32_t l_2000 = 0x1DCBAE4AL;
                    int32_t l_2003 = 0xDFABE3E9L;
                    int32_t l_2008[9] = {(-4L), (-4L), 0L, (-4L), (-4L), 0L, (-4L), (-4L), 0L};
                    uint16_t l_2012 = 65528UL;
                    int i;
                    l_2012--;
                }
                else
                {
                    int16_t l_2017 = 6L;
                    int32_t l_2059 = 0xD57A4778L;
                    g_1925 |= ((((1UL | (g_185[6][0][2] >= (l_1879 = (safe_mod_func_int32_t_s_s(0L, p_22))))) , (((g_211[1]++) | (safe_lshift_func_int8_t_s_s(l_1960[0][1][4], (((safe_mod_func_uint8_t_u_u((safe_lshift_func_int16_t_s_s(((safe_sub_func_int16_t_s_s(((g_498 = (safe_sub_func_int32_t_s_s((l_2009 = ((p_24 < (safe_mod_func_uint32_t_u_u((((safe_mod_func_uint8_t_u_u(((-3L) ^ (g_489 = 0x7E92L)), (safe_mod_func_int16_t_s_s(l_1960[0][1][4], g_128)))) ^ g_1302) != g_1303[2]), g_392[2][4]))) || 3UL)), g_332))) && l_1960[0][1][4]), 0x43EBL)) , 0L), p_21)), l_2036[2])) == l_2017) < l_2036[2])))) != p_22)) ^ 0UL) ^ p_23);
                    for (g_483 = 3; (g_483 == 19); g_483 = safe_add_func_uint32_t_u_u(g_483, 7))
                    {
                        int16_t l_2058[10][6][3] = {{{4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}}, {{4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}}, {{4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}}, {{4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}}, {{4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}}, {{4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}}, {{4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}}, {{4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}}, {{4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}}, {{4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}, {4L, (-7L), 0x8F2AL}}};
                        int i, j, k;
                        l_1957[1][1][8] = (safe_sub_func_int32_t_s_s((l_2004 |= (1L & (-10L))), (safe_add_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s((~((0x13CE8E9CL <= (l_2005 &= (safe_rshift_func_int16_t_s_s(((safe_mul_func_int8_t_s_s(((((((safe_rshift_func_uint16_t_u_s(0x8AC3L, p_22)) , (safe_rshift_func_uint16_t_u_s((g_1129 , (l_2059 = (safe_add_func_int16_t_s_s((safe_mul_func_int16_t_s_s((p_24 = l_2058[1][3][1]), g_298)), g_130)))), g_152[7][5]))) ^ g_184[2][1][1]) ^ g_184[6][0][2]) && l_2060) > l_1951), g_257)) || p_22), 3)))) & 1UL)), 2)), p_22))));
                    }
                }
                if (g_332)
                    goto lbl_2061;
                for (p_23 = 0; (p_23 != (-2)); p_23 = safe_sub_func_uint16_t_u_u(p_23, 5))
                {
                    int32_t l_2112 = 6L;
                    for (p_24 = 0; (p_24 != 23); p_24 = safe_add_func_int32_t_s_s(p_24, 7))
                    {
                        int32_t l_2076 = 0xEBFEB2C6L;
                        uint32_t l_2087 = 0x05925976L;
                        int32_t l_2107 = 0xF92D8475L;

if (l_1875) printf("index = [%d]\n", l_2004);

                    l_2010[0][7] = (65535UL || (safe_add_func_int8_t_s_s(0x95L, (((((((safe_unary_minus_func_uint8_t_u((((+(((-1L) || (0xDFL <= l_1936)) < (0xD3L != ((((((((safe_rshift_func_uint16_t_u_u((((0L >= (safe_rshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_u((l_1873[0][5][0] = (0x6D352CE5L < 4294967295UL)), 2)), 13))) & 0UL) , p_24), p_22)) > p_24) , 0x9EF81521L) | l_1861[2]) != l_2004) >= g_1303[6]) >= p_22) && p_22)))) != 0x6A85L) < l_1874[2][1]))) , g_392[2][4]) || l_2006[0][1]) < p_24) > l_2076) , 0x7A9FA31DL) == g_705))));
                        l_2004 &= (safe_mod_func_uint16_t_u_u((g_1129 = (safe_sub_func_uint16_t_u_u(p_24, (safe_lshift_func_uint16_t_u_s(((((((((!(safe_mul_func_uint8_t_u_u((g_483 = (l_2086 > l_2087)), (safe_sub_func_uint32_t_u_u(((+(l_1957[1][1][8] = (((((p_22 < (safe_mod_func_uint32_t_u_u((g_185[1][0][7] , ((safe_sub_func_int8_t_s_s((((((((safe_add_func_int16_t_s_s((g_298 = ((((l_1877 = (l_1873[0][1][0] = (((((safe_unary_minus_func_uint32_t_u(l_1978)) && ((safe_mul_func_uint8_t_u_u(((g_570 = (safe_mul_func_uint16_t_u_u(g_348[1][1][0], (((0x89L | ((safe_lshift_func_uint16_t_u_u(((g_123 |= ((((l_2107 = (((safe_rshift_func_uint16_t_u_s(((g_1232 = (!p_22)) | g_1303[0]), 10)) | g_348[0][6][0]) | 0x2235E913L)) < g_1850) && g_8) || g_211[1])) == g_2108[6][3]), 15)) >= g_570)) == 0x02L) || p_23)))) == g_185[6][0][6]), l_1957[0][5][7])) < g_2108[6][3])) == p_22) <= 0UL) & p_23))) <= l_2109) | p_23) , 6L)), p_23)) ^ p_23) || p_24) == l_2110) == g_300) & l_2076) , g_184[2][1][0]), l_2111)) > p_21)), p_24))) < 6L) == 0xBA444350L) <= g_332) != 0UL))) != l_1906), l_1878[1][0]))))) ^ p_22) , l_1913) <= g_1371) > l_2112) , 6UL) | p_21) , 5UL), l_1967[3]))))), 1UL));
                    }
                }
            }
            for (l_1978 = (-12); (l_1978 < (-27)); l_1978 = safe_sub_func_uint8_t_u_u(l_1978, 9))
            {
                int16_t l_2144 = 0x1BCEL;
                int32_t l_2145 = 0xEE6A92E6L;
                int32_t l_2188 = 5L;
                for (g_43 = 0; (g_43 < 52); g_43++)
                {
                    int16_t l_2126 = 1L;
                    for (g_186 = (-4); (g_186 != 57); g_186++)
                    {
                        if (g_256)
                            goto lbl_2119;

for (g_1371 = 0; g_1371 < 9; g_1371++)
    {
        transparent_crc(g_331[g_1371], "g_331[g_1371]", l_2145);
        if (l_2145) printf("index = [%d]\n", g_1371);

    };


                    l_2006[1][0] = (safe_mul_func_int8_t_s_s(((((g_1303[0] != ((safe_sub_func_uint16_t_u_u(((((safe_rshift_func_uint16_t_u_s(l_2126, ((!((((safe_rshift_func_int16_t_s_s((l_2146 = ((g_8 & (l_2144 = ((((safe_rshift_func_int16_t_s_s((0x87L >= (safe_sub_func_int16_t_s_s(((((safe_rshift_func_uint16_t_u_s(l_2126, 2)) && (((((g_152[7][5] , (safe_rshift_func_uint8_t_u_u(((safe_lshift_func_int8_t_s_s((l_1915 && (safe_rshift_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(g_1129, 4)), 9))), (g_185[6][0][2] || g_1483[6]))) <= g_256), p_21))) <= 4UL) && 0xB59AC822L) , 0xFBL) != 4L)) || 253UL) == l_2126), g_1302))), 8)) , g_1303[0]) && (-1L)) < g_1850))) | l_2145)), l_2006[0][1])) < g_1371) > l_2111) == p_24)) == p_21))) && g_185[6][0][1]) >= g_705) ^ 0x0668D4B6L), 0xB3A6L)) , l_1862)) , g_184[9][2][0]) == l_2007) >= 0x11L), p_21));
                    }
                    l_1875 = (p_21 >= (g_2108[6][3] = (l_2144 & (((safe_mod_func_int32_t_s_s(((safe_sub_func_uint16_t_u_u(65531UL, p_24)) || ((safe_mul_func_uint16_t_u_u((safe_add_func_int32_t_s_s((safe_rshift_func_int8_t_s_s(0xB2L, 4)), (p_24 & l_2145))), (safe_mod_func_uint16_t_u_u((safe_mul_func_uint8_t_u_u(((safe_mul_func_uint8_t_u_u(((l_2002 |= ((-10L) && 0UL)) ^ g_348[1][2][0]), 0xBEL)) <= 0UL), 0x6AL)), l_2110)))) == g_211[1])), 0xA7B477D4L)) < 248UL) , g_256))));
                }
                for (g_670 = 0; (g_670 != 57); g_670 = safe_add_func_uint16_t_u_u(g_670, 1))
                {
                    l_2001 = (l_1879 = (l_2188 ^= ((safe_mul_func_int8_t_s_s((g_128 < (((safe_lshift_func_uint16_t_u_s(((safe_mul_func_int8_t_s_s((l_2171 = l_1936), (((p_21 , (safe_lshift_func_int16_t_s_u(l_2174[1][1][4], (l_2145 = (safe_mod_func_int16_t_s_s((((((safe_sub_func_int8_t_s_s(p_24, (safe_sub_func_int32_t_s_s((!((((g_256 ^ (((safe_mod_func_int32_t_s_s(((l_1965 = l_1936) , (safe_add_func_int8_t_s_s((safe_rshift_func_uint16_t_u_s(0UL, 3)), ((p_23 , 0UL) >= 65532UL)))), 0x2D032163L)) == 0x3FL) , p_24)) ^ g_332) || g_499) && 0x51L)), 0x1CE325D2L)))) && 4294967295UL) , 0xAAF4281DL) && 4294967295UL) | p_22), l_1998)))))) & g_1925) >= g_1302))) != l_2001), 9)) && p_23) > g_1302)), 0x9FL)) || p_22)));
                }
            }
        }
        else
        {
            uint32_t l_2210[2];
            int i;
            for (i = 0; i < 2; i++)
                l_2210[i] = 0x447CD6F2L;
            if (g_8)
            {
                int16_t l_2207 = 6L;
                l_2212 = (safe_mul_func_uint8_t_u_u(((g_184[5][0][1] , (-4L)) < 0x1FL), (safe_mul_func_int8_t_s_s((safe_unary_minus_func_int16_t_s(l_2171)), ((g_820 <= l_2060) ^ (!(safe_sub_func_int8_t_s_s((((p_24 = (((l_2010[1][3] ^= (safe_sub_func_int8_t_s_s((p_23 , ((+((((safe_mul_func_int8_t_s_s((p_23 ^ (safe_sub_func_uint8_t_u_u(((safe_lshift_func_int8_t_s_u((((g_489--) | l_2210[0]) == 0x0D2E98C0L), 7)) & 0x9BL), p_21))), l_2211[2])) != 0x8A3A97B3L) <= g_8) | l_2207)) , l_2210[1])), l_2211[2]))) , g_271) , p_21)) , g_128) > g_211[1]), l_2207))))))));
            }
            else
            {
                g_1232 = (safe_mul_func_int16_t_s_s(g_489, l_2215));
            }
        }
    }
    else
    {
        uint32_t l_2227 = 0x86BDF8B5L;
        for (l_2215 = (-20); (l_2215 < 13); ++l_2215)
        {
            uint16_t l_2218 = 0UL;
            if (l_1861[2])
                break;

l_2362 &= (l_2278 > ((safe_mod_func_int32_t_s_s(((safe_mod_func_uint32_t_u_u((((g_128 = ((((safe_rshift_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_s(((((p_21 ^= (safe_sub_func_uint16_t_u_u(((safe_mul_func_int8_t_s_s(g_185[6][0][2], (((l_2060 = (g_331[2] = g_152[7][5])) >= (safe_mul_func_uint8_t_u_u((l_2362 >= 0xF371L), ((l_2111 = (safe_lshift_func_uint8_t_u_s((safe_mul_func_uint8_t_u_u(((g_1302 > ((0UL ^ (0xB62024FCL > g_332)) && l_2278)) , g_211[1]), 252UL)), 1))) <= g_152[7][5])))) <= l_2278))) == l_2215), l_1882))) > g_1925) <= g_152[7][5]) ^ g_185[6][0][2]), g_184[7][1][0])) | l_1882), 0xD9L)), 0)) <= g_1925) , l_1875) && l_1882)) >= 0x7C5511DEL) <= 1L), g_3059)) > 0xEB716152L), 4L)) , l_1882));


                    l_2218 = g_129;
        }
        g_128 &= ((safe_mul_func_int16_t_s_s(l_1873[3][0][0], ((0xEDL && l_1879) & (safe_lshift_func_int8_t_s_s((0x0411ADADL >= ((g_211[0]++) > ((g_129 , p_23) && l_1874[7][0]))), (((safe_lshift_func_uint8_t_u_s((g_185[7][0][6] != (((g_348[0][7][0] < p_23) == g_257) != l_2227)), l_2211[1])) , g_271) , (-7L))))))) <= l_2227);
        for (l_1875 = 0; (l_1875 < 16); ++l_1875)
        {
            return g_129;
        }
        l_2215 = ((g_211[1] &= 0x08L) || (safe_lshift_func_uint16_t_u_s(((safe_mod_func_int8_t_s_s(g_1483[5], (safe_mul_func_uint16_t_u_u(((g_498 ^= ((safe_sub_func_int8_t_s_s((0x43E7L != g_130), (safe_rshift_func_uint8_t_u_s((((safe_mul_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((!((safe_unary_minus_func_int8_t_s((0xC219L | (safe_sub_func_uint32_t_u_u(((l_1874[6][1] &= (g_2108[6][3] = ((p_21 >= (safe_add_func_int8_t_s_s((((safe_lshift_func_int8_t_s_s((p_23 = (!(((l_2227 >= g_392[0][0]) < p_24) , 0x11B6L))), 3)) & 0xDAA8L) <= (-5L)), 0xE9L))) != l_2211[2]))) & g_298), 0UL))))) , 0L)), g_259)) , 4L), g_184[6][0][2])) , g_331[1]) && p_24), g_43)))) <= 0x4BL)) ^ g_1925), p_24)))) >= g_300), g_1596)));
    }
    if ((((((safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_u(g_331[2], (safe_lshift_func_int8_t_s_s(((l_1878[1][0] != (l_1874[6][1] = (g_497[0][0] > (safe_mul_func_uint8_t_u_u(g_184[2][3][0], (safe_rshift_func_uint16_t_u_s((g_348[1][2][0] = ((safe_rshift_func_int16_t_s_s((((safe_mul_func_int8_t_s_s((safe_add_func_uint8_t_u_u((((g_211[1] = p_24) || 0UL) , (safe_mod_func_uint8_t_u_u((safe_add_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(p_24, 5)), ((safe_add_func_uint16_t_u_u(l_1861[2], ((l_2277 | p_24) || l_1878[5][2]))) == l_1876))), l_2215))), 0x31L)), 0x97L)) | 4L) && 0L), 13)) && p_23)), g_1371))))))) & g_129), 4)))), g_184[1][0][1])) ^ l_2278) > (-1L)) != g_332) , g_331[2]))
    {
        uint8_t l_2279 = 0x0FL;
        l_2279--;
    }
    else
    {
        uint8_t l_2299 = 0x95L;
        int32_t l_2300 = 0xE98BE002L;
        int32_t l_2326 = (-1L);
        int32_t l_2364 = 7L;
        int32_t l_2365 = (-6L);
        int32_t l_2368 = 0x455FE67CL;
        int32_t l_2369 = 0L;
        if ((((safe_mod_func_uint16_t_u_u(((((6L == (((p_24 < 65526UL) , (((safe_add_func_int16_t_s_s((((+(safe_rshift_func_uint16_t_u_s((p_22 < l_2277), 14))) <= ((((safe_mod_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_u((safe_sub_func_int32_t_s_s((((l_2060 || 1UL) != ((((65530UL != ((safe_sub_func_int32_t_s_s((l_2215 &= (safe_sub_func_int16_t_s_s((l_2299 = (((0xA1L > 0xCEL) < l_2277) == p_23)), p_23))), 0xB5B2ED57L)) && g_298)) != l_2300) | p_21) | 0xA771L)) , g_392[1][9]), 0xB4DDA5EDL)), 9)) == g_271), 65535UL)) == p_23) , 0x4151D4E2L) & g_1850)) != p_23), p_21)) || p_23) || l_2060)) < 0x6A54L)) | p_24) , p_21) | 0xFA5D570BL), l_2110)) == g_211[0]) <= g_152[2][4]))
        {
            int32_t l_2306 = 0x4441BAB4L;
            int32_t l_2324 = 0L;
            int32_t l_2325 = (-1L);
            l_2326 = ((~((0x253AL || (safe_rshift_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u(0xA2C6L, (g_348[1][2][0] ^= l_2306))) || (l_2306 && (l_1874[2][1] == (safe_rshift_func_uint8_t_u_u(((g_211[1] = (safe_mod_func_int32_t_s_s(((0x3BBFL < ((+((safe_rshift_func_uint8_t_u_u((((l_2306 = (l_2324 |= (safe_lshift_func_int16_t_s_u(l_2300, (safe_rshift_func_int16_t_s_s((safe_rshift_func_int8_t_s_s((g_129 <= ((p_22 &= (safe_rshift_func_int16_t_s_s((g_257 = (safe_lshift_func_int8_t_s_s((g_123 & l_1877), 0))), g_483))) == p_21)), 3)), l_2306)))))) < l_2211[2]) < p_21), 6)) && l_2300)) , l_1882)) != g_8), g_130))) | p_24), 6))))), g_1596))) | l_2325)) , 0xB3EC48A4L);
            if (p_23)
            {
                for (g_300 = 0; g_300 < 8; g_300 += 1)
                {
                    g_1483[g_300] = 4294967287UL;
                }
                return p_24;
            }
            else
            {

{
        for (g_820 = 0; g_820 < 7; g_820++)
        {
            transparent_crc(g_152[g_820][g_820], "g_152[g_820][g_820]", l_2368);
            if (l_2368) printf("index = [%d][%d]\n", g_820, g_820);

        }
    }

                    l_1874[8][0] = g_2108[6][3];
                return g_392[1][3];
            }
        }
        else
        {
            uint32_t l_2348 = 0x05D591F2L;
            int32_t l_2349 = 0x45C625B5L;
            int32_t l_2361 = (-1L);
            int32_t l_2363 = 0x5354F2A8L;
            int32_t l_2366 = 0x62890807L;
            int32_t l_2367 = 0xDD15A4F0L;
            int32_t l_2370[1][1];
            int i, j;
            for (i = 0; i < 1; i++)
            {
                for (j = 0; j < 1; j++)
                    l_2370[i][j] = 1L;
            }
            g_1303[0] = ((l_1879 && ((((((safe_mul_func_uint16_t_u_u(((((((((safe_add_func_uint8_t_u_u((safe_mul_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((l_2277 | (3UL < l_2326)), (safe_mul_func_uint16_t_u_u((((safe_sub_func_int8_t_s_s(p_24, ((safe_add_func_int8_t_s_s((g_1129 , (!(l_2300 || (l_2349 &= (((((safe_add_func_uint16_t_u_u(l_2348, (p_22 = (p_21 == g_1303[7])))) > g_331[6]) > l_1878[4][0]) == p_21) ^ 0UL))))), g_1129)) & g_570))) && 0x35L) >= g_186), p_24)))), g_348[0][7][0])) == g_184[3][0][2]), 2)), g_123)), 0x22L)) == g_498) || p_23) >= (-4L)) <= p_23) & p_24) >= g_211[1]) < p_24), 0xC3F3L)) != l_2299) , 4294967295UL) ^ 0xA4E8E4FCL) >= p_24) < g_259)) ^ 0xAFE3C44AL);

for (g_1129 = 0; (g_1129 <= 9); g_1129 += 1)
        {
            int i;
            g_1371 = g_1676[g_1129];
            g_3069++;
        };


                    l_1874[2][0] |= ((((safe_mod_func_uint32_t_u_u((0x9AF7EE03L ^ p_22), p_23)) && ((safe_mod_func_uint32_t_u_u(((safe_sub_func_uint16_t_u_u((++g_670), (p_22 = 0x2754L))) == p_21), 0x7A2CA731L)) & (l_2299 < (((((((l_1873[0][5][0] != (+((safe_lshift_func_uint16_t_u_s(g_1850, g_348[1][2][0])) | l_2326))) > p_21) > 0xBDB3L) , 0x7EL) || g_2108[3][0]) != p_24) < g_392[2][4])))) || l_1877) , p_23);
            l_2371--;
        }
    }
    return l_2215;
}







static int8_t func_31(int8_t p_32, int8_t p_33, uint32_t p_34, int8_t p_35)
{
    int16_t l_36[3][1];
    int32_t l_38 = 0xFCC9F71DL;
    int32_t l_40 = 0xBA137262L;
    int32_t l_41 = 0xAD1532D4L;
    int32_t l_42 = (-7L);
    uint8_t l_1655 = 0x0DL;
    int32_t l_1675[10];
    int32_t l_1809 = 1L;
    uint32_t l_1813 = 0x03F346D7L;
    uint8_t l_1843[8][4] = {{5UL, 0UL, 5UL, 0UL}, {5UL, 0UL, 5UL, 0UL}, {5UL, 0UL, 5UL, 0UL}, {5UL, 0UL, 5UL, 0UL}, {5UL, 0UL, 5UL, 0UL}, {5UL, 0UL, 5UL, 0UL}, {5UL, 0UL, 5UL, 0UL}, {5UL, 0UL, 5UL, 0UL}};
    int32_t l_1849[3][10][3] = {{{0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}}, {{0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}}, {{0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}, {0xEA503FD9L, (-1L), 0xA33C00BCL}}};
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 1; j++)
            l_36[i][j] = 0L;
    }
    for (i = 0; i < 10; i++)
        l_1675[i] = 0x7CA3E359L;
    for (p_32 = 0; (p_32 >= 0); p_32 -= 1)
    {
        uint16_t l_48 = 65529UL;
        int32_t l_1610 = 0xADF19088L;
        int32_t l_1615 = 0xC6E3ABE8L;
        int32_t l_1616 = 1L;
        int32_t l_1668 = 0xC79C9E81L;
        int32_t l_1671[4][1][8] = {{{0xA6143B2BL, 4L, 0xA6143B2BL, 4L, 0xA6143B2BL, 4L, 0xA6143B2BL, 4L}}, {{0xA6143B2BL, 4L, 0xA6143B2BL, 4L, 0xA6143B2BL, 4L, 0xA6143B2BL, 4L}}, {{0xA6143B2BL, 4L, 0xA6143B2BL, 4L, 0xA6143B2BL, 4L, 0xA6143B2BL, 4L}}, {{0xA6143B2BL, 4L, 0xA6143B2BL, 4L, 0xA6143B2BL, 4L, 0xA6143B2BL, 4L}}};
        uint32_t l_1679 = 3UL;
        int16_t l_1831 = 8L;
        int i, j, k;
        for (p_35 = 0; (p_35 >= 0); p_35 -= 1)
        {
            int8_t l_37 = 0xF3L;
            int32_t l_39 = 0L;
            g_43--;
        }
                                            if ((g_670 > g_271) )
{

{
            transparent_crc(g_497[g_1232][g_820], "g_497[g_1232][g_820]", l_1809);
            if (l_1809) printf("index = [%d][%d]\n", g_1232, g_820);

        }

}
                    if ((g_1596 |= func_46(l_48)))
        {
            uint32_t l_1634 = 4294967292UL;
            int32_t l_1638 = 0x9E0196D5L;
            int32_t l_1669 = (-9L);
            int32_t l_1670 = 0x4D98D798L;
            int32_t l_1672 = 0x3DF66434L;
            int32_t l_1673 = 0xA9407AF6L;
            int32_t l_1674 = (-6L);
            int32_t l_1677 = (-8L);
            int32_t l_1678[1];
            int i;
            for (i = 0; i < 1; i++)
                { if ((g_271 && g_820))
                    l_1678[i] = 1L;}
            if (l_42)
            {
                int32_t l_1617 = 0x3F65117AL;
                int32_t l_1667[7] = {(-10L), 0x06891B3AL, (-10L), 0x06891B3AL, (-10L), 0x06891B3AL, (-10L)};
                int i;
                g_1371 = (safe_mod_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_s(((safe_mod_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((g_1482 = ((!((safe_mul_func_uint16_t_u_u(((safe_lshift_func_uint16_t_u_s(0xA501L, (((g_8 != 0xE6FFL) > (l_1610 <= (safe_rshift_func_uint8_t_u_s((g_152[3][6] > ((g_211[0] || p_32) != (safe_add_func_int16_t_s_s((l_1616 &= (l_1615 = (((p_35 , g_152[4][4]) > 0x713BL) , p_35))), p_35)))), p_34)))) && 0x64L))) ^ g_256), l_1617)) && g_184[6][0][2])) & p_32)), 0x3CL)), 0xE3L)) > p_34), l_36[0][0])) <= p_33), 251UL));
                for (p_33 = 0; (p_33 >= 0); p_33 -= 1)
                {
                    int32_t l_1635 = (-7L);
                    int i, j;
                    l_1616 = l_36[(p_33 + 1)][p_33];
                    l_1616 |= ((g_185[2][0][7] >= p_35) || ((l_1610 ^= ((((((safe_add_func_uint32_t_u_u((safe_rshift_func_int8_t_s_u((((safe_lshift_func_uint8_t_u_s((safe_sub_func_uint16_t_u_u(p_32, (safe_lshift_func_int16_t_s_s(((safe_add_func_int8_t_s_s(p_35, (0xBF7D91ACL == ((((safe_mul_func_int16_t_s_s((((safe_add_func_int32_t_s_s((g_497[0][0] <= (l_1634 <= l_40)), ((l_1635 &= ((l_41 &= 0x65875E35L) , l_41)) ^ 4294967295UL))) > p_35) <= p_32), (-6L))) , l_1617) , g_1129) < l_48)))) && 0xE2L), 1)))), g_1483[6])) > g_332) & p_32), 2)), 0xBE298D04L)) ^ 9UL) && p_35) || g_820) ^ 0xE517C86CL) ^ l_1634)) >= l_1615));
                    for (l_1610 = 0; (l_1610 <= 0); l_1610 += 1)
                    {
                        int8_t l_1656 = 0x75L;
                        int32_t l_1657 = 0xBD4BDB5EL;
                        int i, j;
                        l_1638 = ((g_498 = g_1483[(p_32 + 7)]) ^ (g_152[7][5] != (g_1482 = 0x44L)));
                        l_1657 |= (((p_35 ^ (((((safe_add_func_uint16_t_u_u((((0xAEA0L || 65528UL) , ((((safe_mul_func_int8_t_s_s((((safe_add_func_int16_t_s_s((-1L), ((((255UL ^ ((l_1638 = g_1482) <= (((g_1232 |= ((((safe_mul_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u((((l_36[(p_32 + 1)][p_33] = ((((safe_mod_func_int32_t_s_s(0L, (safe_add_func_uint16_t_u_u(65533UL, g_497[0][0])))) != g_128) < g_332) , g_211[1])) != g_331[2]) ^ p_33), g_348[0][7][0])), l_1655)) , (-1L)) || p_32) , p_32)) > g_392[2][4]) == l_48))) == l_41) , g_152[2][4]) , g_331[2]))) == p_32) != p_32), l_1617)) != l_1617) | p_34) && l_1656)) , 0x3FD6L), 1UL)) >= g_129) && p_34) , l_36[(p_33 + 1)][p_33]) > l_1617)) <= 0x584EL) >= l_48);
                        g_128 = ((safe_mul_func_uint8_t_u_u(g_1483[(p_32 + 7)], (-7L))) == (safe_mod_func_uint8_t_u_u((g_211[0] = ((g_820 = (safe_lshift_func_uint8_t_u_s((l_1657 = (g_1483[3] || ((safe_mod_func_uint32_t_u_u((g_259 & ((g_257 >= ((249UL <= (((0xA7335E7EL != (!l_1656)) <= 1L) > g_499)) <= g_123)) && g_670)), 0x1058E11FL)) , 0x5AL))), 7))) && g_331[2])), 255UL)));
                    }
                }
                if (l_1617)
                    break;
                l_1679++;
            }
            else
            {
                int32_t l_1682 = 0x47A3ECD8L;
                int32_t l_1683 = 9L;
                int32_t l_1684[8];
                int i;
                for (i = 0; i < 8; i++)
                    l_1684[i] = 2L;
                for (g_298 = 0; (g_298 <= 0); g_298 += 1)
                {
                    for (l_1669 = 0; (l_1669 <= 0); l_1669 += 1)
                    {
                        g_1303[0] = p_35;
                        if (g_271)
                            continue;
                    }
                }
                for (l_1655 = 0; (l_1655 <= 0); l_1655 += 1)
                {
                    uint32_t l_1688 = 2UL;
                    uint16_t l_1691 = 1UL;
                    for (g_128 = 0; (g_128 <= 0); g_128 += 1)
                    {
                        int8_t l_1685 = 0x8BL;
                        int32_t l_1686 = 0x98028662L;
                        int32_t l_1687 = 7L;
                        l_40 = 4L;
                        --l_1688;
                        l_1691--;
                        l_1673 &= (safe_rshift_func_int16_t_s_u(((safe_mul_func_uint8_t_u_u((g_211[0] = (l_1686 = (~((safe_add_func_int8_t_s_s((9L & (safe_lshift_func_int16_t_s_u(0L, 8))), ((safe_add_func_uint8_t_u_u((((((p_34 != (safe_mod_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u(251UL, (p_35 , 0xCBL))), (safe_mul_func_int8_t_s_s(g_1232, (((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(0x5250E116L, 0x6C4CEA90L)), g_184[1][3][0])), 7)) , p_33) && g_1483[6])))))) | p_32) | l_1675[7]) || 0UL) , p_33), g_43)) , l_1675[3]))) , l_48)))), 0UL)) == 1L), 15));
                    }
                }
            }
            for (l_1655 = 0; l_1655 < 8; l_1655 += 1)
            {
                g_1483[l_1655] = 0x540716E3L;
            }
            l_1671[1][0][7] = 0x38B17AD2L;
            g_1303[0] = (((safe_mod_func_int16_t_s_s(((safe_mul_func_int16_t_s_s(p_32, (((g_300 ^ (((safe_mod_func_int16_t_s_s(((l_38 > (safe_rshift_func_int16_t_s_s((((((safe_mul_func_int16_t_s_s((safe_sub_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u((safe_add_func_int16_t_s_s((0xCDEEL || (safe_mul_func_uint8_t_u_u(l_1675[6], (safe_add_func_int16_t_s_s(((((((~(l_1610 = ((safe_unary_minus_func_uint32_t_u(((safe_mod_func_uint8_t_u_u((safe_mul_func_uint16_t_u_u(p_32, (safe_lshift_func_uint8_t_u_u(((p_34 > ((safe_mul_func_int8_t_s_s((safe_unary_minus_func_uint16_t_u((((-10L) > g_259) < g_1752))), p_34)) == 0x87D1402DL)) , g_392[2][4]), l_1677)))), l_1615)) ^ l_1638))) >= l_1675[6]))) > g_1482) , g_392[3][0]) , g_1302) != g_499) < 1L), 0xBB79L))))), 9UL)), g_1303[0])) , g_256), p_34)), 65535UL)) == 0x7AL) && p_32) >= 1UL) <= (-1L)), 0))) | 0xEEL), g_1232)) ^ l_1615) , 0x726BL)) || l_1668) & 0x0EL))) >= p_34), l_1677)) > 65527UL) >= 0x7493L);
        }
        else
        {
            int16_t l_1777 = 0x53E5L;
            int32_t l_1778 = 0x072A3F7AL;
            for (l_48 = 0; (l_48 <= 6); l_48 += 1)
            {
                int32_t l_1759 = 0x907EC2ABL;
                int32_t l_1776 = (-1L);
                int32_t l_1779 = 0L;
                uint16_t l_1780 = 1UL;
                for (g_259 = 0; (g_259 <= 6); g_259 += 1)
                {
                    int32_t l_1785 = (-1L);
                    int32_t l_1786 = 0x923B4589L;
                    int16_t l_1812 = 0L;
                    int i, j;

g_1232 &= ((((safe_rshift_func_uint16_t_u_s((safe_rshift_func_int16_t_s_u(p_33, 7)), 8)) & (~(p_32 > g_2385))) && g_128) != g_2385);


                    l_1779 = (safe_mod_func_int32_t_s_s(((safe_mul_func_int8_t_s_s((safe_add_func_uint32_t_u_u(4294967295UL, (p_35 || l_1759))), (safe_add_func_uint16_t_u_u(g_392[2][4], ((g_152[l_48][l_48] ^= ((g_128 = (l_1778 |= ((safe_lshift_func_int8_t_s_u((g_332 = (p_33 = 0xD1L)), (((safe_lshift_func_int8_t_s_u((safe_lshift_func_int16_t_s_s((l_36[(p_32 + 1)][p_32] = (safe_sub_func_uint8_t_u_u(g_1129, ((safe_mul_func_int8_t_s_s((safe_mod_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s((l_38 != (5UL | 1L)), 5)), p_34)), 0L)) , l_1776)))), l_1776)), 1)) & l_1777) < g_298))) & 4L))) > 0x732EB598L)) , 0xBE26L))))) != p_32), l_1777));
                    if (l_1780)
                        continue;
                    if (((((((safe_rshift_func_uint16_t_u_s(((-8L) == (l_36[(p_32 + 1)][p_32] <= g_8)), (g_257 = g_8))) && (((safe_sub_func_uint16_t_u_u(0x67C0L, (0x037B56FFL >= ((l_1786 ^= (l_1785 &= 0xE3A0A816L)) || ((p_34--) , (!((g_332 >= 0x4CL) <= g_300))))))) , p_34) , 0x6746L)) && p_35) | 65530UL) || l_1671[0][0][0]) || p_33))
                    {
                        return g_498;
                    }
                    else
                    {
                        uint32_t l_1810[10][1][1] = {{{0x5C201E5AL}}, {{0x5C201E5AL}}, {{0x5C201E5AL}}, {{0x5C201E5AL}}, {{0x5C201E5AL}}, {{0x5C201E5AL}}, {{0x5C201E5AL}}, {{0x5C201E5AL}}, {{0x5C201E5AL}}, {{0x5C201E5AL}}};
                        uint32_t l_1811 = 0x297DF59BL;
                        int32_t l_1822 = 0x194B3607L;
                        int32_t l_1826 = 0x2F7BC348L;
                        int i, j, k;
                        l_1779 = (g_259 > (safe_rshift_func_int16_t_s_s(((((((l_1671[3][0][1] | g_8) >= (g_128 = (safe_rshift_func_uint16_t_u_u((((+(safe_rshift_func_int8_t_s_s(1L, 1))) , g_184[6][0][2]) , ((((safe_sub_func_int16_t_s_s(((safe_add_func_int16_t_s_s((l_1809 = ((safe_lshift_func_int16_t_s_s(((g_1676[3] = (p_33 , (((safe_add_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s((((safe_add_func_int8_t_s_s(0xF3L, ((((((p_35 & (l_1668 &= (0x67L ^ g_1232))) & g_259) < p_35) | g_670) , g_185[2][0][3]) && l_1675[0]))) < l_1809) <= l_1810[3][0][0]), l_1811)), 0xABL)) < l_1671[1][0][7]) > g_152[2][1]))) != 0x52FDL), 7)) , l_1810[9][0][0])), 5UL)) <= p_35), l_42)) && 7L) && l_1786) >= p_32)), p_35)))) || p_33) ^ g_152[l_48][l_48]) == 0x43DDL) , 0xF7BFL), p_34)));
                        l_1812 = 0x671350FBL;
                        l_1668 = (((((((g_129 & ((((l_1813 ^ 65527UL) & p_35) & (safe_rshift_func_int8_t_s_s(((safe_lshift_func_int16_t_s_u((safe_sub_func_int32_t_s_s(((((g_332 = ((g_670 ^= (safe_mod_func_uint8_t_u_u(g_499, (g_211[1] = (l_1822 = 249UL))))) >= (safe_rshift_func_int16_t_s_s(l_1778, (4294967295UL == (+(l_1785 = (((((l_1826 &= 0x501F928FL) > p_34) <= p_32) || p_34) == l_1786)))))))) & 0x03L) & g_1129) != p_35), (-1L))), 15)) & g_820), p_33))) < g_300)) >= l_42) || (-7L)) > p_35) || l_1822) > g_123) != g_705);
                    }
                }
            }
        }
        for (g_257 = 0; (g_257 >= 0); g_257 -= 1)
        {
            uint32_t l_1834 = 4294967295UL;
            int32_t l_1848[3][3] = {{0x6EAF60D8L, 0xE76AA30AL, 0x6EAF60D8L}, {0x6EAF60D8L, 0xE76AA30AL, 0x6EAF60D8L}, {0x6EAF60D8L, 0xE76AA30AL, 0x6EAF60D8L}};
            uint8_t l_1851 = 1UL;
            int i, j;
            l_1848[2][2] |= (safe_rshift_func_int16_t_s_s(((safe_sub_func_uint32_t_u_u((((((((l_1831 >= ((g_1371 = ((l_36[(g_257 + 1)][g_257] &= (((safe_mul_func_int8_t_s_s(l_1834, l_1834)) <= (((g_152[7][1] , (safe_mul_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s(((l_1610 = ((safe_mod_func_uint32_t_u_u(l_1843[1][1], ((safe_mod_func_int8_t_s_s(((l_40 = ((-3L) != 1UL)) , ((safe_rshift_func_int16_t_s_s(((p_35 > ((0xAC855737L && g_392[2][4]) & l_1668)) , g_331[2]), g_489)) | l_1834)), l_1616)) | p_35))) , 0x1455L)) < 0x951FL), g_497[0][6])), 5UL)), p_32))) , 0x8CL) , p_35)) || g_300)) && 0x1D05L)) != l_1671[1][0][7])) == g_8) & 4294967293UL) < l_1615) , l_1675[6]) , l_1834) & g_392[3][8]), 1L)) , g_670), 8));

for (g_2845 = 0; g_2845 < 10; g_2845++)
        l_1675[g_2845] = 0x7CA3E359L;

                    --l_1851;
        }
    }
    return l_41;
}







static int32_t func_46(uint32_t p_47)
{
    uint8_t l_49 = 0x50L;
    int32_t l_50[9];
    int16_t l_53 = (-1L);
    int32_t l_1191 = 0x6A0630EFL;
    int32_t l_1228 = 0xCA0B20EFL;
    int32_t l_1230 = (-3L);
    uint32_t l_1279 = 0x4A4B987BL;
    uint32_t l_1304 = 0x96A25AACL;
    int32_t l_1384 = 0xBC0F7C56L;
    int8_t l_1397[8][1];
    uint32_t l_1430 = 0x61C7D030L;
    int16_t l_1489[10] = {0xC331L, 0xB736L, 0L, 0L, 0xB736L, 0xC331L, 0xB736L, 0L, 0L, 0xB736L};
    int32_t l_1503 = (-9L);
    int16_t l_1526[2];
    uint32_t l_1566 = 4294967291UL;
    int32_t l_1588 = 0xF3E1A92EL;
    int8_t l_1593[2];
    int i, j;
    for (i = 0; i < 9; i++)
        l_50[i] = 0xE324E816L;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 1; j++)
            { if ((g_499>0U) )
{

l_1503 |= (1L & (-10L));


}
                    l_1397[i][j] = 0xF6L;}
    }
    for (i = 0; i < 2; i++)
        l_1526[i] = 0x23CFL;
    for (i = 0; i < 2; i++)
        { if ((l_1430 > g_499))
                    l_1593[i] = (-1L);}
    if (((l_50[1] &= ((l_49 , l_49) && 7UL)) != (((safe_sub_func_int32_t_s_s(l_53, l_53)) , (safe_sub_func_uint16_t_u_u((safe_mul_func_int8_t_s_s((l_1191 = ((~(safe_sub_func_int16_t_s_s((safe_mod_func_int32_t_s_s((-9L), (0x5501L && ((((func_63(func_69(p_47, g_8, p_47), p_47, l_53, p_47, p_47) <= p_47) , l_49) , p_47) && l_53)))), l_49))) > p_47)), 6L)), 65535UL))) < l_53)))
    {
        uint16_t l_1204 = 0xEA4BL;
        uint32_t l_1229 = 0x334DF0F3L;
        int32_t l_1231 = (-1L);
        uint32_t l_1290 = 0xEA366762L;
        int32_t l_1299 = 0xE8AF71B0L;
        int32_t l_1300[8][9][3] = {{{4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}}, {{4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}}, {{4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}}, {{4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}}, {{4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}}, {{4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}}, {{4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}}, {{4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}, {4L, (-2L), (-1L)}}};
        uint32_t l_1592[7] = {9UL, 0xB96823B8L, 9UL, 0xB96823B8L, 9UL, 0xB96823B8L, 9UL};
        int i, j, k;
        if ((safe_mod_func_int16_t_s_s(((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u(g_348[1][2][0], (g_348[1][2][0] & (safe_rshift_func_uint8_t_u_s((safe_mul_func_int16_t_s_s((((((((l_1204 || ((safe_rshift_func_uint16_t_u_s(p_47, 4)) <= (((safe_rshift_func_uint16_t_u_s((safe_lshift_func_uint16_t_u_s((((safe_rshift_func_uint16_t_u_u((((~(safe_sub_func_int32_t_s_s((l_1191 ^= ((safe_unary_minus_func_int8_t_s(((((g_497[0][0] = 0UL) | ((p_47 == ((l_1231 = ((((safe_add_func_uint32_t_u_u((((((safe_mod_func_uint32_t_u_u((~(safe_mul_func_int8_t_s_s((safe_add_func_uint8_t_u_u(g_185[6][0][2], (0x8E3E615DL && ((l_50[1] = ((safe_add_func_int32_t_s_s(((g_499 = 0x2D3DB2A5L) != l_1204), l_1228)) , 0xF8E9DC1FL)) != 0x8549BE39L)))), p_47))), l_1229)) == p_47) == 0xBCL) && 0x9080L) != g_331[4]), g_128)) || 0x2455L) && l_1230) & g_705)) != l_49)) != l_1229)) || g_332) < 5UL))) != 0xE66CL)), (-1L)))) && p_47) <= 3L), p_47)) && 0xF2CEL) && 0x04BCL), 4)), 13)) == 0x9BL) , g_43))) | l_53) , g_211[1]) , l_50[5]) & g_1232) , 0x81BDL) != g_256), g_271)), l_1204))))), 65529UL)) <= l_1204), 0x0E0CL)))
        {
            int32_t l_1244 = 0x15AEB998L;
            g_1232 = ((l_50[6] = (((-1L) & (safe_mul_func_int16_t_s_s((247UL | (safe_sub_func_int16_t_s_s(p_47, ((!((0xDD595583L | (g_332 == (safe_unary_minus_func_uint16_t_u((safe_mul_func_int16_t_s_s(0x3760L, ((safe_mul_func_int8_t_s_s(((0x57L <= (g_392[1][7] ^ ((!(g_392[2][4] != 0xADD4L)) <= l_1244))) != l_1229), l_1244)) != g_497[0][0]))))))) == p_47)) >= g_498)))), l_1244))) | 0x6289L)) < 0x814F4109L);
        }
        else
        {
            int16_t l_1280 = 0xA1C7L;
            int32_t l_1281 = 0L;
            int32_t l_1282 = 6L;
            int32_t l_1283 = 0L;
            uint32_t l_1505 = 0x13A97CBBL;
            int32_t l_1532 = 0L;
            int32_t l_1536 = 0x589CD189L;

l_1281 += 1;


                    l_50[1] = (((safe_add_func_uint32_t_u_u((!1UL), (safe_rshift_func_int8_t_s_s((safe_mod_func_uint8_t_u_u((((safe_lshift_func_uint16_t_u_s(p_47, 11)) ^ (safe_add_func_int8_t_s_s((((((l_1282 |= ((safe_lshift_func_uint16_t_u_u((1L >= ((safe_lshift_func_uint8_t_u_s((((safe_rshift_func_uint16_t_u_u(p_47, ((((l_1231 = (((safe_mul_func_int8_t_s_s((((safe_mod_func_uint8_t_u_u((l_1281 = (((safe_mod_func_uint32_t_u_u((safe_mod_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u(0UL, 7)), ((l_1280 = (safe_mul_func_int16_t_s_s(p_47, ((+0xF7A8L) == (p_47 < ((safe_mod_func_int16_t_s_s((l_1191 = (safe_rshift_func_uint8_t_u_s(((1UL ^ 0x0520E99AL) || g_483), 2))), p_47)) , l_1279)))))) , (-1L)))), 0xFF00E9A0L)) > 0xF0L) , g_298)), g_211[1])) ^ l_53) , p_47), p_47)) != g_152[7][5]) > 0xF50779DAL)) , 9L) > p_47) || g_392[2][4]))) , 0xAEFFL) || l_1231), p_47)) & g_257)), p_47)) && g_184[6][0][2])) <= g_1129) , 0x1BL) < g_256) && g_129), g_184[8][0][1]))) && 0L), p_47)), l_1229)))) < l_1283) | g_392[2][0]);
            if ((((safe_mul_func_int8_t_s_s((g_497[0][5] && (safe_mod_func_int32_t_s_s((safe_add_func_uint32_t_u_u(l_1290, ((g_184[4][2][0] == ((l_1281 = (l_1282 = (g_498 = (g_332 = 0x11L)))) && (((safe_rshift_func_uint8_t_u_s(((g_128 |= p_47) ^ ((0x5AL == (l_1282 |= ((safe_mod_func_uint16_t_u_u(((-9L) == ((((l_1231 = l_1204) != ((safe_add_func_int8_t_s_s(((safe_add_func_int8_t_s_s(g_1232, 0xF9L)) && 0x4446L), 1UL)) & l_1204)) >= 0xCE91L) , 0x8FL)), 0x7F1FL)) <= 0x0579L))) , l_1279)), p_47)) || p_47) || p_47))) == 0xF166294DL))), g_497[0][1]))), 0L)) < g_130) , p_47))
            {
                return p_47;
            }
            else
            {
                int32_t l_1301 = 0x3FAF73F6L;
                int32_t l_1339 = 0xC1413828L;
                int32_t l_1340 = 0L;
                int32_t l_1408[2];
                int i;

g_670 &= ((g_3475 || 0x68L) && (g_1482 |= l_49));

                    for (i = 0; i < 2; i++)
                    l_1408[i] = 3L;
                ++l_1304;
                l_1281 = (((+((safe_lshift_func_uint8_t_u_u(0UL, (((safe_lshift_func_int8_t_s_u((l_1300[0][4][1] != ((p_47 >= 4294967290UL) >= (safe_lshift_func_uint8_t_u_u((0x9638323EL && (0xFF93L != (g_348[1][3][0] && l_50[1]))), (+((((((g_184[7][2][1] ^ g_298) > 0x88E6L) & p_47) <= 0UL) | p_47) > g_185[6][0][2])))))), 1)) >= 0xA4L) , 0x22L))) >= 0x0AL)) > l_1191) , l_1283);
                for (g_483 = 22; (g_483 == 12); g_483--)
                {
                    int32_t l_1341 = 0x8735C346L;
                    int32_t l_1342 = 0L;
                    uint32_t l_1385 = 0UL;
                    l_1342 = (l_1301 & (0xEA927CD4L <= (safe_sub_func_int16_t_s_s((safe_sub_func_int32_t_s_s((-1L), ((safe_mod_func_uint16_t_u_u((((safe_mul_func_int16_t_s_s((safe_add_func_uint8_t_u_u((l_50[4] |= (p_47 , (g_186++))), (safe_mul_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s(p_47, ((p_47 >= l_1301) , (safe_sub_func_int8_t_s_s((0UL || ((((l_1339 = (safe_sub_func_int8_t_s_s((safe_mod_func_int32_t_s_s(((g_298 |= (((g_392[0][4] > 0xF48A6572L) || p_47) & (-1L))) , 0x397D93AAL), g_497[0][0])), g_348[1][2][0]))) , (-1L)) ^ p_47) , l_1191)), g_129))))), 0x61L)))), p_47)) && l_1340) <= g_348[0][0][0]), g_185[6][0][2])) , (-1L)))), l_1341))));
                    l_1191 |= (!((safe_rshift_func_int8_t_s_s(g_300, p_47)) , ((g_332 = (safe_rshift_func_int8_t_s_u(p_47, l_1339))) != ((safe_mul_func_int8_t_s_s(0xFAL, (l_50[1] = (l_1342 |= (p_47 | g_186))))) , p_47))));
                    for (l_1281 = (-24); (l_1281 < (-1)); l_1281 = safe_add_func_int16_t_s_s(l_1281, 7))
                    {
                        int16_t l_1370 = 0x07DAL;
                        int32_t l_1386 = 2L;
                        l_1386 = (safe_mul_func_int8_t_s_s((l_1283 ^= l_1300[0][4][1]), (((p_47 || ((safe_rshift_func_int16_t_s_u(((safe_rshift_func_uint8_t_u_u(((safe_add_func_int16_t_s_s((safe_sub_func_int32_t_s_s(g_498, g_186)), (g_130 = (!(((+(safe_lshift_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((((safe_mod_func_uint32_t_u_u(p_47, l_1370)) , ((g_1371 <= ((safe_lshift_func_uint8_t_u_s((safe_rshift_func_uint16_t_u_s(((safe_lshift_func_uint8_t_u_u(((l_1339 , ((safe_lshift_func_int8_t_s_u((safe_mul_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_s((g_211[1] &= (l_1299 > p_47)), 6)), p_47)), g_392[0][1])) >= p_47)) || p_47), 2)) , g_348[1][2][0]), p_47)), 7)) <= l_1340)) , p_47)) == 0L), 15)), g_1129))) ^ g_1302) < l_1384))))) < l_1385), 1)) , 1L), 8)) || p_47)) && 0xE50E7748L) > p_47)));
                        if (g_256)
                            break;
                    }
                    g_1232 |= ((((safe_sub_func_int16_t_s_s(((g_332 = (safe_mod_func_uint8_t_u_u(((g_348[0][1][0] != (g_123 &= (0xB381L != (l_1342 = (safe_mul_func_uint16_t_u_u(((l_1408[1] = (p_47 > (safe_add_func_uint32_t_u_u((l_1339 = (safe_rshift_func_int8_t_s_s(0xF6L, 6))), (((g_499--) | ((safe_sub_func_uint32_t_u_u((((((((0x8AL | (safe_lshift_func_uint8_t_u_s(0x03L, p_47))) && ((safe_add_func_int16_t_s_s((l_1281 |= 5L), (1L >= 0xC8150F9CL))) == p_47)) ^ p_47) | 0xAC95186FL) || 0x1305A61BL) >= p_47) , 0x7D03D2B0L), g_1303[0])) == l_1300[0][4][1])) || l_1341))))) & g_130), p_47)))))) < l_1290), p_47))) <= l_1301), g_1303[2])) | 0L) ^ l_1282) || 4294967288UL);
                }
                for (g_1129 = 1; (g_1129 == 54); ++g_1129)
                {
                    int32_t l_1424 = 0xA0CF2913L;
                    int16_t l_1425 = 0x68A0L;
                    int32_t l_1426 = 0xD7FE1E0FL;
                    g_128 = (((g_184[5][0][1] || p_47) & g_185[3][0][0]) < (l_1408[0] = 0x75L));
                    l_1426 |= (((g_259--) == ((safe_lshift_func_int8_t_s_u((safe_sub_func_uint8_t_u_u(p_47, 0x56L)), 3)) <= (((((g_497[0][9] = (+(((safe_sub_func_int32_t_s_s(g_331[2], (-10L))) <= ((((l_1408[1] = (((l_1408[1] != (-6L)) & ((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s(((l_1282 != (((l_1424 != p_47) ^ p_47) >= g_331[7])) == 65526UL), l_1425)), 8UL)) || g_1232)) | l_1191)) , g_489) ^ 0x04L) ^ g_1303[5])) ^ 0xC0F505C5L))) == p_47) || 0xCDF3L) != g_392[2][6]) && p_47))) == l_1424);
                }
            }
            for (g_498 = (-28); (g_498 <= 9); g_498++)
            {
                int32_t l_1429 = (-3L);
                int32_t l_1473 = 0x0902ADD8L;
                int32_t l_1504 = 0x56778F80L;
                int32_t l_1583 = 0xAA7785F5L;
                ++l_1430;
                if ((safe_mod_func_uint16_t_u_u((safe_sub_func_int16_t_s_s((((((65535UL | 0xDB15L) != (safe_lshift_func_uint8_t_u_u((((!g_332) & (p_47 == p_47)) , ((safe_add_func_uint8_t_u_u((p_47 , (g_498 <= (l_1300[3][3][0] <= ((safe_rshift_func_uint16_t_u_u((safe_sub_func_int32_t_s_s((safe_mul_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s(p_47, l_1283)) > g_298), 0x91L)), 0xC171189FL)), 0)) == g_257)))), 0UL)) || p_47)), p_47))) , l_1191) ^ 0x50L) && g_348[1][8][0]), p_47)), 0x2FA1L)))
                {
                    int32_t l_1474 = 0x0A314195L;
                    l_1299 = (((safe_rshift_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(((((l_1473 ^= ((0UL && (safe_mod_func_int32_t_s_s(p_47, (safe_mod_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_u((l_50[2] = (safe_sub_func_int32_t_s_s(((((g_392[2][4] == 0xF8L) && (safe_sub_func_int32_t_s_s((~(g_483 = (l_1280 >= (safe_mod_func_uint32_t_u_u((l_1300[0][4][1] = 4294967295UL), l_1429))))), g_186))) , (safe_lshift_func_int8_t_s_u((safe_mod_func_uint32_t_u_u((g_184[8][2][0] , 0x0BA6240AL), 0x74AF7473L)), p_47))) , l_1299), 0UL))), 2)) == 1UL), 0x60L))))) | 0x488AL)) || 1L) || g_184[6][0][2]) >= l_1474), 0x48D1B89CL)), p_47)) ^ g_298) , g_1232);
                    if (((!((g_332 = 0xDEL) > ((p_47 != (l_1282 || ((p_47 < (g_1482 = ((safe_add_func_int8_t_s_s((0x7ADFF584L == g_185[6][0][2]), (safe_add_func_int16_t_s_s(l_1474, p_47)))) >= (safe_mul_func_int8_t_s_s(g_259, g_499))))) >= g_129))) < g_1483[6]))) , l_1474))
                    {
                        uint8_t l_1484 = 3UL;
                        l_50[1] = l_1484;
                    }
                    else
                    {
                        int32_t l_1488 = (-2L);
                        int32_t l_1490 = 0xC08A8438L;

g_498 -= 1;


                    l_1300[0][0][1] = (safe_mod_func_uint32_t_u_u(((g_129 != (((g_570 |= ((+(g_152[5][1] ^ ((l_1488 = 0xF3A69F87L) && ((g_298 = p_47) & (l_1489[7] ^ (g_211[1] = l_1490)))))) , (safe_rshift_func_uint8_t_u_u((safe_add_func_uint32_t_u_u((l_1281 > ((((((((safe_rshift_func_uint8_t_u_u((((safe_rshift_func_int8_t_s_u(p_47, (safe_mul_func_uint16_t_u_u(((((l_1503 &= (safe_rshift_func_uint16_t_u_u((l_1474 < p_47), 12))) | 0UL) ^ p_47) ^ g_497[0][0]), p_47)))) , g_820) & l_1397[5][0]), p_47)) == 0xECL) , l_1504) && p_47) <= l_1473) && p_47) >= g_489) != l_1473)), 1L)), g_1302)))) <= p_47) & 1L)) , 1UL), l_1474));
                        return g_570;
                    }
                    l_1191 = ((l_1505++) || (((~(((safe_mod_func_uint32_t_u_u((g_43 >= l_1281), (g_499 || (g_257 < (safe_add_func_int32_t_s_s(l_1473, (safe_lshift_func_int16_t_s_u((g_497[0][0] >= (safe_rshift_func_uint8_t_u_s(((safe_rshift_func_int8_t_s_s(0x01L, ((safe_mod_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_u(p_47, ((l_1300[5][3][1] = (l_50[1] = l_1504)) , l_1191))) , l_1429), g_130)) , p_47))) == g_300), p_47))), 6)))))))) == g_185[5][0][4]) , g_1232)) , 3UL) > g_185[6][0][2]));
                }
                else
                {
                    int32_t l_1527 = 0L;
                    int32_t l_1529 = 9L;
                    int32_t l_1530 = (-5L);
                    int32_t l_1531 = 0L;
                    for (l_1430 = (-7); (l_1430 <= 55); ++l_1430)
                    {
                        int16_t l_1525 = 0xB3D2L;
                        int32_t l_1528 = 1L;
                        uint16_t l_1533 = 0x5EE4L;
                        int32_t l_1582 = 1L;
                        ++l_1533;
                        l_1583 = (l_1536 != (safe_mul_func_int8_t_s_s((l_1429 = l_1304), (((safe_sub_func_int8_t_s_s((((safe_add_func_uint16_t_u_u((((safe_mod_func_int32_t_s_s((safe_mul_func_int16_t_s_s((l_50[1] &= (((l_1529 > 0x85F3L) >= (safe_mul_func_int16_t_s_s((l_1281 ^= (safe_mod_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_u(((l_1528 = (l_1191 = p_47)) > ((safe_add_func_int8_t_s_s((((safe_sub_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(p_47, (safe_sub_func_uint8_t_u_u((l_1582 = ((safe_unary_minus_func_int8_t_s((safe_lshift_func_int8_t_s_u((((((((safe_mul_func_uint16_t_u_u((((l_1283 = l_1566) < 1L) || ((l_1282 &= (safe_rshift_func_uint8_t_u_s(((safe_mul_func_int16_t_s_s((((safe_mul_func_int8_t_s_s((l_1473 = ((safe_lshift_func_uint8_t_u_u(((l_1531 = ((((!(l_1503 = (safe_add_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s(((safe_mul_func_int16_t_s_s(p_47, 0xF86DL)) >= 0UL), l_1531)), p_47)))) <= g_1482) > g_670) >= p_47)) < l_53), l_1231)) , p_47)), 1L)) , g_128) < l_1533), 0x2E00L)) & g_498), 2))) , p_47)), p_47)) | 0L) , 65535UL) & g_130) , 65531UL) > l_1529) ^ l_1504), l_1204)))) == 0x8C2C5CBCL)), l_1229)))), p_47)) & g_130) <= l_1536), p_47)) , l_1530)), p_47)), 0x88FCL))), 0L))) != 0xB0E3L)), g_348[1][2][0])), 4294967295UL)) | 0x29F75717L) >= 0xC478L), p_47)) <= l_1533) , l_1529), p_47)) <= l_1529) != g_184[6][0][2]))));
                        l_50[1] = p_47;
                        l_1588 = (safe_mul_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u(1UL, 4)), 0L));
                    }
                    for (l_1204 = 0; l_1204 < 8; l_1204 += 1)
                    {

for (l_1532 = 0; l_1532 < 1; l_1532++)
            {
                transparent_crc(g_348[l_1231][l_1473][l_1532], "g_348[l_1231][l_1473][l_1532]", l_1504);
                if (l_1504) printf("index = [%d][%d][%d]\n", l_1231, l_1473, l_1532);

            };


                    g_1303[l_1204] = 0x595066F4L;
                    }
                }
            }
            g_1232 = ((safe_unary_minus_func_int8_t_s(((safe_add_func_int8_t_s_s(0x92L, 5UL)) || (g_152[7][0] & p_47)))) <= l_1592[2]);
        }
        return l_1593[1];
    }
    else
    {
        uint32_t l_1594 = 0xA469E0E8L;
        int32_t l_1595 = 0x38DAF927L;
        g_128 |= (g_1482 <= (l_1594 , (l_1489[8] < g_8)));
        l_1595 = l_1304;
    }
    return g_211[1];
}







static int8_t func_63(int16_t p_64, int32_t p_65, uint16_t p_66, int16_t p_67, uint32_t p_68)
{
    uint32_t l_80[1];
    int32_t l_960 = 1L;
    int32_t l_962 = (-1L);
    uint8_t l_963 = 0xA7L;
    int32_t l_989 = 0x9B60C87BL;
    int32_t l_1029 = 0x5AD2EFE2L;
    int32_t l_1088 = (-1L);
    int32_t l_1134 = 5L;
    int i;
    for (i = 0; i < 1; i++)
        l_80[i] = 4294967295UL;
    if ((((safe_mod_func_uint8_t_u_u(p_65, func_69(p_67, p_65, (safe_mul_func_int8_t_s_s((safe_sub_func_int32_t_s_s((l_80[0] , ((l_80[0] || p_65) , ((func_69((func_69((l_960 = func_81(g_43, (safe_mul_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_u(p_65, (((safe_mul_func_uint16_t_u_u((g_8 , 8UL), p_65)) <= p_65) & 1UL))) <= p_64), l_80[0])))), g_570, l_80[0]) <= g_392[3][5]), p_67, p_68) , l_960) ^ g_256))), p_66)), l_80[0]))))) | 251UL) != g_256))
    {
        int8_t l_961 = (-1L);
        int32_t l_966[2][9][9] = {{{0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}}, {{0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}, {0xE5CA81DDL, (-1L), (-1L), 0xE5CA81DDL, 0x37086B6CL, 0xAF64F26EL, 0xB0B1402CL, (-7L), 1L}}};
        uint16_t l_967 = 65535UL;
        int i, j, k;
                                            if (((l_1134 > g_43) || (!l_961)) )
{

for (l_1088 = 0; l_1088 < 3; l_1088++)
    {
        for (l_962 = 0; l_962 < 6; l_962++)
        {
            transparent_crc(g_3238[l_1088][l_962], "g_3238[l_1088][l_962]", g_128);
            if (g_128) printf("index = [%d][%d]\n", l_1088, l_962);

        }
    };


}
                    --l_963;
                                       uint32_t B6j6jgg_300 = (~(((~((((~((g_670 | (g_300 | l_961)))) & ((~(g_256)) || g_129)) ^ (~((~(((g_332 ^ g_259) >> l_960)))))))) ^ (g_271 | g_186))));
uint16_t B6j6jhg_670 = (~((((((~(l_960)) || B6j6jgg_300) | g_670) & ((~(g_129)) | (l_961 ^ (~(g_186))))) ^ ((~(((g_332 | g_259) || (~(g_256))))) & g_271))));
int16_t B6j6jig_129 = (~(((~(((~(((~(B6j6jgg_300)) & (g_300 << l_960)))) || ((~(B6j6jhg_670)) & (g_332 ^ g_271))))) ^ (~((g_256 | (~(((g_186 ^ l_961) & g_129)))))))));
if(((!B6j6jgg_300) || (g_259 > B6j6jig_129))){
B6j6jgg_300 = g_300;
B6j6jhg_670 = g_670;
B6j6jig_129 = g_129;
g_300 = (~(((~(((~((~(((~(B6j6jig_129)) & ((g_186 || B6j6jhg_670) >> l_960)))))) | (~((((~(B6j6jgg_300)) ^ (g_300 >> g_129)) >> (~((~((g_259 || g_256))))))))))) | g_670)));
g_670 = (~(((B6j6jhg_670 || (~((~((l_961 | g_300)))))) || ((g_271 | (~((((g_332 || B6j6jgg_300) ^ g_256) ^ B6j6jig_129)))) | (~((l_960 || g_186)))))));
g_129 = (~(((~((((~(B6j6jig_129)) & g_186) | (~((~(g_259))))))) || (~(((~(B6j6jgg_300)) | ((~((g_256 ^ g_300))) | (~(((~((~((~((~((((~(g_332)) ^ l_961) | g_129))))))))) & (~(g_670))))))))))));
if(((!B6j6jgg_300) || ((g_129>-2) && (g_256 > g_129)))){
printf("g_300=%llu\n", (unsigned long long)g_300);
B6j6jhg_670 = (~((((~(g_186)) >> (~((~((~(g_670))))))) << ((~((l_960 ^ B6j6jhg_670))) << (~((l_961 << ((~(g_259)) << (g_300 || (B6j6jgg_300 || (g_256 | B6j6jig_129)))))))))));
g_670 = (~((((~((B6j6jig_129 >> g_332))) || ((~(B6j6jhg_670)) & (g_300 & (g_186 ^ l_961)))) ^ (((~((~(g_256)))) ^ g_259) || (~(((~((~(g_670)))) << (~(B6j6jgg_300)))))))));
g_300 = (~(((~((((~((g_259 >> l_961))) & (~((~((g_186 << (g_332 ^ (g_271 | B6j6jhg_670)))))))) << (~(g_670))))) >> (~(((B6j6jgg_300 & g_256) << (~((~((~(g_300))))))))))));
}
if((g_129 > g_332)){
printf("g_670=%llu\n", (unsigned long long)g_670);
g_129 = (~((((~(((~((~(l_960)))) ^ B6j6jgg_300))) | (l_961 ^ (~(((g_186 || (B6j6jig_129 || g_256)) || (~((B6j6jhg_670 & g_271)))))))) ^ (~((~((g_332 ^ (~((~((~(g_670))))))))))))));
B6j6jig_129 = (~(((~((~((B6j6jhg_670 << (g_256 | g_259)))))) | ((~(((~(g_129)) | ((g_300 ^ g_271) >> (g_332 ^ B6j6jgg_300))))) & (g_186 ^ (~(l_961)))))));
g_670 = (~(((g_300 ^ ((g_670 << (~((g_129 | g_259)))) << (~((((~((~(g_271)))) & B6j6jhg_670) || l_960))))) ^ ((~((~(l_961)))) | ((~(g_332)) >> B6j6jig_129)))));
}
if((B6j6jhg_670>65529)){
printf("g_129=%lld\n", (long long)g_129);
B6j6jig_129 = (~(((~(((~((~(g_332)))) || (~((l_961 << B6j6jgg_300)))))) ^ ((((g_256 >> g_271) & (~(g_186))) >> (g_259 << g_129)) || (g_300 ^ g_670)))));
B6j6jgg_300 = (~((((~((g_256 >> g_186))) & (~(((~(l_960)) ^ ((~((B6j6jig_129 || ((B6j6jhg_670 & l_961) & (~(g_271)))))) >> (~((g_670 | g_259)))))))) ^ g_300)));
g_670 = (~(((~((~((~((~((l_961 << g_186))))))))) << (~(((((~((~(g_670)))) >> (~(g_271))) ^ (~(B6j6jgg_300))) || (((g_256 ^ g_259) & (~(B6j6jig_129))) ^ (g_332 | (~(g_300))))))))));
}
}
g_300 = B6j6jgg_300;
g_670 = B6j6jhg_670;
g_129 = B6j6jig_129;

                    --l_967;
    }
    else
    {
        uint32_t l_970 = 4294967293UL;
        l_970 = 1L;
    }
    g_820 = 0x6501458DL;
    for (g_128 = (-1); (g_128 != 12); g_128 = safe_add_func_int32_t_s_s(g_128, 9))
    {
        uint16_t l_987 = 65535UL;
        int32_t l_1070 = (-1L);
        int8_t l_1086 = (-1L);
        int32_t l_1104 = 0xC4FB4E3CL;
        int16_t l_1174[8] = {0x4482L, 0x9550L, 0x4482L, 0x9550L, 0x4482L, 0x9550L, 0x4482L, 0x9550L};
        int32_t l_1190[6];
        int i;
        for (i = 0; i < 6; i++)
            l_1190[i] = 8L;
        for (g_499 = 0; (g_499 <= 0); g_499 += 1)
        {
            uint32_t l_988 = 9UL;
            int32_t l_1020 = 0L;
            int32_t l_1031 = (-1L);
            uint32_t l_1032[2][7] = {{0x715764B3L, 0x715764B3L, 0x84B322A7L, 0x715764B3L, 0x715764B3L, 0x84B322A7L, 0x715764B3L}, {0x715764B3L, 0x715764B3L, 0x84B322A7L, 0x715764B3L, 0x715764B3L, 0x84B322A7L, 0x715764B3L}};
            int32_t l_1048 = 0x0DE32FACL;
            uint32_t l_1085 = 4294967290UL;
            int i, j;
            g_820 ^= ((g_497[0][0] , (safe_sub_func_uint32_t_u_u(((4294967289UL && ((((2UL & (((safe_rshift_func_int8_t_s_s((safe_mul_func_int8_t_s_s((g_489 || (g_499 >= ((~p_68) , ((safe_rshift_func_uint8_t_u_u(((0x97L != (safe_add_func_int16_t_s_s((g_271 & ((+((safe_sub_func_int16_t_s_s(1L, l_987)) > 1L)) > g_392[3][4])), 0xB67DL))) , p_64), l_988)) , l_80[0])))), l_989)), 3)) >= g_259) , p_65)) & p_68) != l_988) > l_987)) < 1UL), 0xEC4465B2L))) , g_8);
            for (l_962 = 1; (l_962 >= 0); l_962 -= 1)
            {
                uint32_t l_992[8][5][6] = {{{0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}}, {{0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}}, {{0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}}, {{0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}}, {{0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}}, {{0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}}, {{0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}}, {{0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}, {0UL, 0x77148015L, 0UL, 0x3527C7B3L, 0x317C50F3L, 0UL}}};
                int32_t l_1010 = 0x6A922945L;
                uint16_t l_1017 = 0x524AL;
                int i, j, k;
                if (((safe_add_func_int8_t_s_s((g_332 = (l_992[4][3][2] , (g_498 = ((safe_add_func_uint8_t_u_u((l_960 = (l_1017 = (((-8L) | ((safe_sub_func_uint8_t_u_u(((safe_sub_func_int16_t_s_s(p_68, (g_257 < (safe_rshift_func_uint16_t_u_u((~(safe_rshift_func_uint16_t_u_s((((safe_mul_func_int16_t_s_s((((safe_rshift_func_int16_t_s_s(((++g_211[l_962]) != (l_1010 = g_152[2][4])), 6)) > (safe_mul_func_int8_t_s_s((l_992[4][3][2] == ((safe_mod_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((g_259 && (((((g_483 = (0x3FFBL >= (g_129 = ((g_186 , l_987) <= l_987)))) > 1L) & 0UL) >= 4294967295UL) != g_489)), 0)) != p_66), 7UL)) & g_498)), g_392[2][4]))) ^ g_497[0][0]), p_65)) >= p_67) < g_152[7][5]), 2))), 15))))) ^ l_987), l_80[0])) == 0xF5F9L)) != 0xDDL))), p_68)) | 1UL)))), g_300)) != 6L))
                {
                    uint16_t l_1030 = 0xB807L;
                    int32_t l_1047[5];
                    int i;
                    for (i = 0; i < 5; i++)
                        l_1047[i] = 0x1D3002EFL;
                    l_1047[0] = ((safe_rshift_func_uint8_t_u_u((l_1020 = (0xF2156182L >= l_992[7][2][5])), 1)) >= ((l_1048 = ((safe_mod_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((safe_lshift_func_int16_t_s_s((!((((0x9B0CB7FBL || ((p_67 = ((l_1030 = (~l_1029)) > l_1031)) >= g_257)) < (l_1032[1][5] = 6L)) > (safe_mul_func_uint16_t_u_u(((safe_sub_func_int16_t_s_s(((safe_sub_func_int8_t_s_s((g_332 = (safe_mod_func_int16_t_s_s(((safe_mul_func_int16_t_s_s((g_392[2][4] != (safe_rshift_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s(p_68, l_987)), p_68))), 65528UL)) <= p_68), 0x73D5L))), (-3L))) ^ 65528UL), l_1047[0])) > p_68), 0xD2CAL))) ^ g_348[1][2][0])), 8)), 2)), 0xAD47L)) < g_211[l_962])) ^ l_1031));
                }
                else
                {
                    int32_t l_1080 = 3L;
                    int32_t l_1087 = 0x6F0598A3L;
                    int i, j, k;
                    l_1020 = (safe_sub_func_uint32_t_u_u((0x14829739L || ((safe_rshift_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((((((safe_add_func_uint32_t_u_u(((l_1010 != (safe_rshift_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(((safe_mul_func_int16_t_s_s((safe_mul_func_uint16_t_u_u((safe_unary_minus_func_int32_t_s((safe_mul_func_uint16_t_u_u(l_1070, l_989)))), 0x0CCDL)), g_128)) > (p_65 && (safe_unary_minus_func_int8_t_s(((safe_mul_func_uint16_t_u_u((safe_mul_func_int16_t_s_s((p_67 |= (safe_mul_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_u((g_348[g_499][(g_499 + 3)][g_499] = (l_1080 == (safe_rshift_func_int16_t_s_u((((safe_mod_func_uint16_t_u_u(g_186, g_128)) == l_1085) , l_988), l_1086)))), g_331[7])) , 0x1AL), g_331[6]))), l_1029)), p_66)) >= g_129))))), p_64)) , l_1087), 15))) || g_348[1][7][0]), p_66)) && p_68) & 0x0303D0C3L) , 247UL) < l_987), 3)), 0x76L)) > 0x0DB4L), 14)) || p_66)), g_185[3][0][2]));
                }
                return l_1088;
            }
        }

{
                        uint32_t l_602[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_602[i] = 1UL;
                        g_2845 = ((g_1850 = ((safe_rshift_func_uint16_t_u_s(g_2845, 5)) > (safe_mul_func_uint8_t_u_u((((safe_mod_func_int8_t_s_s((safe_sub_func_int8_t_s_s(g_331[2], 0x6BL)), g_1596)) , 1L) > (g_1371 = (((((((((g_152[1][0] >= g_1596) < (l_602[0] != g_392[1][1])) <= g_348[1][2][0]) , l_602[0]) ^ 65535UL) || (-7L)) , (-1L)) , g_1596) == g_257))), g_1596)))) , 1L);
                        g_2845 = g_1596;
                        l_960 = (safe_add_func_uint32_t_u_u((safe_mul_func_uint16_t_u_u((l_960 = p_65), (l_1104 = (((-2L) != ((g_257 , (1L != (g_211[(g_1596 + 1)]--))) , (((safe_add_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s((g_3069 | ((l_1070 != g_271) == ((((safe_mod_func_int32_t_s_s(g_3069, (l_1088 = (safe_add_func_uint32_t_u_u((safe_unary_minus_func_uint16_t_u((g_348[0][3][0] > g_498))), g_211[g_1596]))))) < g_1925) == g_211[1]) && 0xE7L))), 12)), g_186)) & g_3069) != g_1371))) < 0x887EA039L)))), g_257));
                    }

                    if ((safe_mul_func_uint8_t_u_u((((safe_mod_func_uint8_t_u_u(1UL, (l_960 = p_67))) != (((p_66 , (safe_lshift_func_uint8_t_u_u(((safe_mod_func_int16_t_s_s((safe_sub_func_int32_t_s_s(g_670, (l_1104 |= (safe_mod_func_int32_t_s_s((((((safe_lshift_func_uint8_t_u_s((safe_unary_minus_func_int8_t_s(((g_499 > (l_80[0] == l_1088)) < 0UL))), 1)) != (g_259 <= l_1086)) <= g_259) && (-1L)) >= l_1070), p_67))))), l_80[0])) != 0xB5L), 5))) , l_1070) > 0x59676AE0L)) ^ g_498), l_989)))
        {
            int16_t l_1105 = (-1L);
            int32_t l_1135 = 0xE24BC97CL;

{
        uint32_t l_1594 = 0xA469E0E8L;
        int32_t l_1595 = 0x38DAF927L;
        g_820 |= (g_498 <= (l_1594 , (g_1676[8] < g_8)));
        l_1595 = g_300;
    }

                    l_1135 &= (l_1105 ^ ((0xFF8985BAL <= (+(l_962 = (safe_rshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s(0x1ED08827L, p_68)), 4))))) && (safe_mul_func_uint8_t_u_u(0UL, ((((safe_sub_func_uint8_t_u_u(p_67, 0xD1L)) <= ((safe_sub_func_int8_t_s_s((((safe_unary_minus_func_uint32_t_u((safe_add_func_int32_t_s_s((safe_rshift_func_int8_t_s_u((safe_lshift_func_int8_t_s_s((!(safe_sub_func_int32_t_s_s(((safe_add_func_int32_t_s_s(((g_1129++) || (l_1029 || (safe_lshift_func_int16_t_s_u(((p_64 , l_1086) <= p_65), 10)))), g_300)) != 0xB3L), l_1086))), p_65)), l_1105)), 0L)))) , l_1134) , g_499), p_67)) != l_1105)) <= g_211[0]) & l_987)))));
        }
        else
        {
            int16_t l_1139 = 0xC263L;
            int32_t l_1140[3];
            int32_t l_1147 = 7L;
            int i;
            for (i = 0; i < 3; i++)
                l_1140[i] = 0L;
            if (g_332)
            {
                uint8_t l_1138 = 0x57L;
                int32_t l_1148 = 0L;
                if (g_348[1][2][0])
                    break;
                l_1148 |= (safe_rshift_func_uint16_t_u_s((l_1138 , (p_68 | ((1L & (l_1140[1] = l_1139)) >= (5L > (248UL > (safe_lshift_func_uint16_t_u_s((((l_1147 ^= ((((safe_mul_func_uint16_t_u_u(((0L && (safe_lshift_func_int16_t_s_s((g_43 < (p_66 , l_963)), 8))) || 5L), 0xF59AL)) >= g_186) , g_8) >= g_1129)) | (-1L)) > p_68), g_130))))))), l_1138));
                for (l_963 = 0; (l_963 <= 6); l_963 += 1)
                {
                    for (l_960 = 0; (l_960 <= 6); l_960 += 1)
                    {
                        uint32_t l_1149 = 7UL;
                        l_1149--;
                    }
                }
            }
            else
            {
                uint16_t l_1175 = 65528UL;
                g_820 = (0x0B01L ^ (safe_mod_func_int32_t_s_s((safe_sub_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_int8_t_s_s(0xF0L, l_1147)), ((g_499 , (safe_mul_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u((safe_lshift_func_int8_t_s_u(((((((safe_mod_func_uint16_t_u_u(0x8647L, 0x3D1CL)) || (((safe_mod_func_uint8_t_u_u(p_66, g_392[2][4])) ^ ((g_129 = ((g_497[0][1] < 1UL) & 2L)) || 0x7056L)) >= p_65)) & l_1088) > g_123) == l_1147) >= 0xFDL), p_66)), l_1174[2])), 246UL)) && p_68), l_1175))) <= g_570))), p_67)), l_1175)), 0xD7BFA746L)));
                l_1104 = 0xA2CBA8FEL;
            }
            l_1190[0] = (g_8 && (((((safe_mod_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_s((p_68 | p_67), (l_1147 |= (safe_mul_func_int16_t_s_s((safe_rshift_func_int8_t_s_s(l_962, (l_1104 = (g_332 = ((safe_add_func_int8_t_s_s((((safe_lshift_func_uint8_t_u_u(((((0x42L || ((1L && ((safe_lshift_func_uint16_t_u_s(0x3AD5L, (g_184[6][0][2] == 1UL))) <= g_392[1][1])) > p_68)) | 0x709AL) , g_130) | g_256), 2)) | g_705) <= g_184[6][0][2]), l_1140[1])) , g_570))))), l_989))))) >= l_80[0]), g_123)) < g_43) > g_348[0][8][0]) , l_960) >= p_65));
        }
    }
    return p_67;
}







static int16_t func_69(uint8_t p_70, int32_t p_71, uint32_t p_72)
{
    uint8_t l_73[5][4][2] = {{{0x01L, 0x01L}, {0x01L, 0x01L}, {0x01L, 0x01L}, {0x01L, 0x01L}}, {{0x01L, 0x01L}, {0x01L, 0x01L}, {0x01L, 0x01L}, {0x01L, 0x01L}}, {{0x01L, 0x01L}, {0x01L, 0x01L}, {0x01L, 0x01L}, {0x01L, 0x01L}}, {{0x01L, 0x01L}, {0x01L, 0x01L}, {0x01L, 0x01L}, {0x01L, 0x01L}}, {{0x01L, 0x01L}, {0x01L, 0x01L}, {0x01L, 0x01L}, {0x01L, 0x01L}}};
    int i, j, k;
    l_73[0][3][0] |= 1L;
    return g_43;
}







static uint8_t func_81(int16_t p_82, uint8_t p_83)
{
    uint32_t l_90 = 0x80C48983L;
    int32_t l_124 = (-1L);
    int32_t l_125 = 0x4BC7F4BDL;
    int32_t l_126 = 0xBCAB3842L;
    int32_t l_127 = 0x6F3B0A6BL;
    int8_t l_240[6];
    int8_t l_248 = 0x03L;
    uint16_t l_531 = 1UL;
    uint8_t l_550 = 0x90L;
    uint8_t l_617 = 0x19L;
    int32_t l_623 = 0L;
    int32_t l_650 = 1L;
    uint32_t l_769[10];
    uint32_t l_842 = 9UL;
    uint32_t l_952 = 0xE73E0F7AL;
    int i;
    for (i = 0; i < 6; i++)
        l_240[i] = 0x69L;
    for (i = 0; i < 10; i++)
        l_769[i] = 0x7986FDEFL;
    if (l_90)
    {
        int8_t l_107 = 0xF9L;
        int32_t l_122 = 0xA52A621CL;
        int32_t l_144 = (-1L);
        int32_t l_252 = (-9L);
        int32_t l_254 = 0xBB9FF989L;
        uint16_t l_433[10][2] = {{65531UL, 0x3A1EL}, {65531UL, 0x3A1EL}, {65531UL, 0x3A1EL}, {65531UL, 0x3A1EL}, {65531UL, 0x3A1EL}, {65531UL, 0x3A1EL}, {65531UL, 0x3A1EL}, {65531UL, 0x3A1EL}, {65531UL, 0x3A1EL}, {65531UL, 0x3A1EL}};
        uint32_t l_463 = 0UL;
        int i, j;
        if ((safe_add_func_uint32_t_u_u((((safe_mod_func_uint8_t_u_u((((safe_mod_func_int32_t_s_s((((g_43 = (safe_mod_func_uint16_t_u_u(((safe_add_func_uint8_t_u_u(((g_8 > g_43) , (p_83 = (safe_mod_func_uint16_t_u_u(p_82, g_43)))), (safe_mul_func_uint16_t_u_u(l_107, 65535UL)))) & ((safe_rshift_func_uint16_t_u_s(0x3AE4L, p_82)) | ((safe_sub_func_int8_t_s_s((safe_sub_func_uint32_t_u_u((safe_mul_func_int16_t_s_s(l_107, 0xB8F7L)), l_107)), g_8)) > g_8))), g_43))) && 0UL) , g_8), p_82)) != 0xDDC7CBFAL) ^ p_82), p_82)) == 0x8E64L) != 1UL), p_82)))
        {
            uint32_t l_138 = 1UL;
            int32_t l_143[8][3][4] = {{{0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}}, {{0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}}, {{0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}}, {{0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}}, {{0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}}, {{0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}}, {{0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}}, {{0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}, {0xA0F9AE2BL, 0x9C4D8F35L, 0L, (-1L)}}};
            int32_t l_145[7][9][4] = {{{0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}}, {{0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}}, {{0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}}, {{0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}}, {{0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}}, {{0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}}, {{0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}, {0x6106D1D5L, 0L, 0xCBD7FBB0L, 6L}}};
            uint32_t l_241[1];
            int i, j, k;
            for (i = 0; i < 1; i++)
                l_241[i] = 3UL;
            l_145[1][3][2] = (l_144 &= ((safe_lshift_func_int16_t_s_u((g_123 = (safe_sub_func_uint16_t_u_u(g_43, (safe_add_func_int32_t_s_s((l_107 , ((p_83 & p_82) || p_83)), ((++g_130) , (((safe_mul_func_int8_t_s_s((safe_rshift_func_int8_t_s_u((!(((((g_128 = (((l_122 = l_138) , (6UL != ((safe_mul_func_int16_t_s_s((safe_sub_func_int32_t_s_s(l_138, (l_143[5][2][0] &= l_122))), g_128)) < l_138))) , l_138)) , p_83) , l_126) >= p_82) != l_107)), l_138)), 0xF7L)) , 3L) ^ g_130))))))), 15)) < l_138));
            for (l_107 = 0; (l_107 <= 2); l_107 += 1)
            {
                uint32_t l_164[10][4][2] = {{{6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}}, {{6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}}, {{6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}}, {{6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}}, {{6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}}, {{6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}}, {{6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}}, {{6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}}, {{6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}}, {{6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}, {6UL, 4294967294UL}}};
                int32_t l_167 = 0xEC5635C9L;
                int32_t l_168[5][2] = {{0xA423BFD0L, 1L}, {0xA423BFD0L, 1L}, {0xA423BFD0L, 1L}, {0xA423BFD0L, 1L}, {0xA423BFD0L, 1L}};
                int i, j, k;
                l_143[5][2][0] = (safe_lshift_func_uint16_t_u_s(((l_144 |= ((g_128 & (safe_add_func_int16_t_s_s((-1L), 0x4106L))) , (((g_123 , 0x53L) < (0xFE344F03L & g_129)) | (((((g_43 , ((safe_mod_func_uint16_t_u_u(((g_8 || p_82) != l_122), g_123)) , 0x3C66L)) && 0xB798L) <= p_83) && l_127) <= g_152[7][5])))) ^ p_82), 0));
                l_164[5][2][0] = (((!(safe_rshift_func_uint8_t_u_s(((safe_mod_func_uint32_t_u_u(((safe_lshift_func_uint16_t_u_s(((l_144 = (safe_sub_func_int16_t_s_s((p_83 == p_83), (p_82 &= 0x7636L)))) < p_83), 12)) < ((g_8 ^ ((-1L) == (g_8 > l_126))) != ((l_143[6][2][2] || 1UL) == p_83))), g_130)) && p_82), 6))) , g_130) , 0xE5F6D2A8L);
                for (l_124 = 2; (l_124 >= 0); l_124 -= 1)
                {
                    uint32_t l_182 = 0x74A005E7L;
                    int32_t l_183 = 0x92CF6085L;
                    uint16_t l_210[8][10][3] = {{{0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}}, {{0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}}, {{0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}}, {{0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}}, {{0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}}, {{0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}}, {{0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}}, {{0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}, {0xFF6BL, 65535UL, 0xFF6BL}}};
                    int i, j, k;
                    l_168[0][0] |= (p_82 && (l_164[3][1][1] <= (1UL | (l_167 = (-1L)))));
                    g_186 &= ((p_83 , (p_83 && (safe_sub_func_int32_t_s_s(p_83, (safe_add_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((((safe_add_func_uint32_t_u_u((l_145[0][6][2] = (g_185[6][0][2] = (safe_lshift_func_int16_t_s_s((~(safe_lshift_func_uint16_t_u_s((g_129 == l_182), (p_83 != (((g_184[6][0][2] = (l_183 = 0x8D028DA7L)) , g_152[3][1]) | g_43))))), p_82)))), 4294967294UL)) ^ p_82) <= l_138), 0L)), g_128)))))) | g_152[5][1]);
                                                        while ((g_570 > l_182) )
{

if (g_489)
                            break;

}
                    for (l_138 = 0; (l_138 <= 2); l_138 += 1)
                    {
                        int i, j, k;
                        l_143[l_138][l_107][l_107] = (((((safe_mod_func_int8_t_s_s(l_143[(l_138 + 5)][l_138][(l_107 + 1)], (safe_rshift_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u(((safe_mul_func_int16_t_s_s((p_82 >= ((safe_rshift_func_uint8_t_u_u(((safe_mul_func_int16_t_s_s(0L, ((((safe_mul_func_int16_t_s_s(((((safe_add_func_int32_t_s_s(0x49581F8BL, 0xB2A35B8BL)) ^ (g_130--)) >= l_167) & (--g_43)), g_186)) & (((p_83 = ((((safe_lshift_func_uint16_t_u_s((safe_unary_minus_func_int16_t_s((l_143[(l_138 + 5)][l_138][(l_107 + 1)] , (0xAB9CL > 65535UL)))), l_183)) != l_210[5][0][1]) ^ (-1L)) || 0x88L)) , l_183) && 8UL)) >= 1UL) >= l_182))) && l_90), 1)) & 1L)), g_184[6][0][2])) >= 3UL), g_184[6][0][2])), 8)))) && 0xAFADE91FL) == p_82) || 5UL) , 0x2A66D061L);
                        g_211[1]--;
                        if (l_144)
                            { if (l_842)
                    continue;}
                    }
                }
            }
            g_128 = (((safe_lshift_func_uint8_t_u_s(((~((safe_lshift_func_uint8_t_u_u(((((((l_138 > (safe_lshift_func_int16_t_s_s((0xD4FFL < l_138), 2))) && (safe_rshift_func_int8_t_s_s((safe_mod_func_int8_t_s_s(((p_82 ^ (safe_unary_minus_func_int8_t_s(((g_130 < (l_144 = (((((safe_lshift_func_int8_t_s_u((0UL & ((++g_43) , ((g_184[6][0][2] && ((((~g_128) && ((safe_add_func_int8_t_s_s((((safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s((g_152[7][5] = ((safe_lshift_func_uint16_t_u_u(((!((l_107 || g_123) , g_128)) && 65535UL), l_144)) != 0UL)), 3)), 0L)) ^ p_82) , 0x6DL), 0x83L)) , 8L)) < 0xE2F4L) , (-10L))) || p_82))), 7)) , p_82) != 0x45L) && l_126) & 0x99D8L))) || l_126)))) >= l_143[3][2][0]), g_211[1])), l_240[4]))) || g_184[5][3][1]) && 0x02L) || l_241[0]) < 0xBC80L), 2)) & l_240[4])) , 0x92L), 7)) | p_83) && 3UL);
        }
        else
        {
            int8_t l_249 = 0x02L;
            int32_t l_251 = 0x056CAB57L;
            int32_t l_253 = 0x05BE474BL;
            int8_t l_432 = (-1L);
            uint32_t l_460 = 1UL;
            uint8_t l_461 = 0x69L;
            if ((l_240[3] > 1UL))
            {
                int32_t l_244 = 0x3608916AL;
                for (g_129 = (-25); (g_129 == (-12)); g_129++)
                {
                    uint8_t l_245[3];
                    int32_t l_250 = 0xAD904D1DL;
                    int32_t l_255 = 0xA02321D8L;
                    int32_t l_258[10];
                    int i;
                    for (i = 0; i < 3; i++)
                        l_245[i] = 0xE2L;

{
                int32_t l_1682 = 0x47A3ECD8L;
                int32_t l_1683 = 9L;
                int32_t l_1684[8];
                int i;
                for (i = 0; i < 8; i++)
                    l_1684[i] = 2L;
                for (g_123 = 0; (g_123 <= 0); g_123 += 1)
                {
                    for (l_124 = 0; (l_124 <= 0); l_124 += 1)
                    {
                        g_1303[0] = g_332;
                        if (l_460)
                            continue;
                    }
                }
                for (l_461 = 0; (l_461 <= 0); l_461 += 1)
                {
                    uint32_t l_1688 = 2UL;
                    uint16_t l_1691 = 1UL;
                    for (l_253 = 0; (l_253 <= 0); l_253 += 1)
                    {
                        int8_t l_1685 = 0x8BL;
                        int32_t l_1686 = 0x98028662L;
                        int32_t l_1687 = 7L;
                        g_2845 = 4L;
                        --l_1688;
                        l_1691--;
                        l_125 &= (safe_rshift_func_int16_t_s_u(((safe_mul_func_uint8_t_u_u((g_211[0] = (l_1686 = (~((safe_add_func_int8_t_s_s((9L & (safe_lshift_func_int16_t_s_u(0L, 8))), ((safe_add_func_uint8_t_u_u((((((g_499 != (safe_mod_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u(251UL, (g_332 , 0xCBL))), (safe_mul_func_int8_t_s_s(l_254, (((safe_lshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(0x5250E116L, 0x6C4CEA90L)), g_184[1][3][0])), 7)) , g_332) && g_1483[6])))))) | g_332) | l_258[7]) || 0UL) , g_332), g_3475)) , l_258[3]))) , g_3475)))), 0UL)) == 1L), 15));
                    }
                }
            }

                    for (i = 0; i < 10; i++)
                        l_258[i] = 0x509FD6BDL;
                    --l_245[0];
                    g_259--;
                    for (g_186 = 23; (g_186 != 6); g_186 = safe_sub_func_int32_t_s_s(g_186, 1))
                    {
                        uint8_t l_268 = 0x93L;
                        g_128 = (0x5C32L | ((((-1L) || ((l_144 = ((l_122 ^= (((safe_mul_func_int8_t_s_s((((g_152[7][5] | (((l_268 , ((0UL ^ l_258[4]) >= (l_252 , 1L))) <= (l_254 = ((safe_add_func_uint16_t_u_u((p_83 , g_152[3][6]), 0xA1DFL)) >= 255UL))) <= g_8)) | 0xCC9F1702L) & g_259), g_123)) || 0UL) ^ 0L)) || l_240[3])) || 0L)) | (-8L)) ^ 0x7559L));
                    }
                }
                g_271--;
                for (p_82 = 2; (p_82 != (-29)); p_82--)
                {
                    int16_t l_281 = 0xA7E0L;
                    l_127 = (((l_251 = ((safe_unary_minus_func_int16_t_s((safe_sub_func_int8_t_s_s(l_251, ((l_126 &= (p_82 | ((0x8BL ^ l_127) ^ (g_185[6][0][2] >= ((l_253 = ((safe_mul_func_int16_t_s_s((l_281 , ((((safe_mul_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((((((safe_lshift_func_int8_t_s_u(((safe_rshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u((p_83 & g_257), 7)), g_152[7][5])), l_281)) ^ 0x8A383003L), 2)) < l_122) & 0L) || l_281) , 0x7B51L), 0x40EEL)) || g_256), (-7L))) > 4294967287UL), l_240[4])) && 0x88DAE93EL) > g_129) >= l_281)), 0x7182L)) | p_82)) >= 4294967291UL))))) < 0x0025CD26L))))) >= 0x34L)) , p_82) < l_244);
                    g_128 = (l_127 = (p_82 < (safe_lshift_func_uint8_t_u_s(l_249, 5))));
                }
            }
            else
            {
                uint8_t l_316 = 0UL;
                int32_t l_358 = 0x1E32FE72L;
                uint32_t l_383 = 8UL;
                int16_t l_431 = 0xA4F7L;
lbl_393:
                for (g_123 = 4; (g_123 >= 0); g_123 -= 1)
                {
                    int32_t l_299 = 0L;
                    uint32_t l_339 = 1UL;
                    int8_t l_353 = 0L;
                    int i;
                    if (l_240[(g_123 + 1)])
                    {
                        --g_300;
                        if (l_299)
                            continue;
                        g_128 = (+(+0x7E84L));
                    }
                    else
                    {
                        l_125 = (((((safe_mul_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((safe_lshift_func_int8_t_s_s((p_83 >= (~(safe_mod_func_uint8_t_u_u(((safe_mul_func_int16_t_s_s((g_257 &= (l_316 > ((safe_mod_func_int32_t_s_s(((safe_mod_func_uint32_t_u_u((((g_128 = ((((safe_rshift_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_s(((((l_339 ^= (safe_sub_func_uint16_t_u_u(((safe_mul_func_int8_t_s_s(g_185[6][0][2], (((g_332 = (g_331[2] = g_152[7][5])) >= (safe_mul_func_uint8_t_u_u((p_82 >= 0xF371L), ((l_124 = (safe_lshift_func_uint8_t_u_s((safe_mul_func_uint8_t_u_u(((g_298 > ((0UL ^ (0xB62024FCL > l_107)) && l_316)) , g_211[1]), 252UL)), 1))) <= g_152[7][5])))) <= l_316))) == l_254), p_83))) > l_122) <= g_152[7][5]) ^ g_185[6][0][2]), g_184[7][1][0])) | p_83), 0xD9L)), 0)) <= l_251) , l_253) && p_83)) >= 0x7C5511DEL) <= 1L), g_271)) > 0xEB716152L), 4L)) , p_83))), 0xDB09L)) == g_259), p_83)))), 6)), 10)) >= 0x5A984FCCL), p_82)) == l_240[4]) | 0xC492L) != p_82) , p_82);
                    }
                    if ((((-6L) ^ (safe_mod_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s((safe_sub_func_uint16_t_u_u((g_130 = ((safe_mod_func_int32_t_s_s(g_259, (++g_348[1][2][0]))) , ((safe_mul_func_int8_t_s_s(l_353, (-7L))) <= 4294967293UL))), (((p_82 ^= (safe_sub_func_uint8_t_u_u(((g_128 = l_240[3]) >= (safe_add_func_int8_t_s_s(p_83, ((l_358 ^= l_249) ^ (++g_186))))), l_316))) ^ l_299) , 0x4898L))), 6)), g_184[2][3][2]))) , 0x36E18AEFL))
                    {
                        int32_t l_384 = 5L;
                        l_384 = (safe_sub_func_int16_t_s_s((g_152[4][0] = ((safe_mod_func_int16_t_s_s((safe_mul_func_int8_t_s_s(g_348[1][2][0], ((safe_unary_minus_func_uint32_t_u(p_82)) | (g_332 = (((safe_mod_func_int32_t_s_s((((!(safe_mul_func_uint16_t_u_u(0xC1D6L, ((safe_add_func_uint32_t_u_u(4294967293UL, ((safe_unary_minus_func_int8_t_s((~(((g_257 | (g_186 |= (safe_sub_func_int16_t_s_s(((safe_lshift_func_int16_t_s_s(((g_298 = (((((safe_sub_func_int8_t_s_s((1L & (p_83 , (l_251 &= ((l_299 = g_256) , p_82)))), l_383)) != 0x3861C090L) == g_8) <= 7L) & 0xAAE3C059L)) ^ 0x2F0AL), g_348[1][2][0])) >= l_339), g_184[6][0][2])))) ^ p_83) >= l_126)))) , 0x9B95104FL))) <= 0xD17F2E58L)))) != g_332) ^ 0L), 1L)) & p_82) == p_82))))), l_353)) , (-4L))), 0L));
                    }
                    else
                    {
                        return l_383;
                    }
                    l_251 = (safe_mul_func_int8_t_s_s((l_125 = ((safe_sub_func_uint8_t_u_u(((p_82 & (((l_299 = g_123) == 0x3CL) | ((l_358 = ((~(p_82 & (l_249 || (g_348[1][0][0] = ((l_253 &= ((9L >= 0x83D9F478L) <= (l_248 < (safe_mul_func_int16_t_s_s(p_83, 65527UL))))) > g_259))))) & p_82)) >= p_83))) != 5UL), g_392[2][4])) != 0xFAA0B6E3L)), g_271));
                }
                for (l_251 = 2; (l_251 >= 0); l_251 -= 1)
                {
                    uint16_t l_430 = 65527UL;

g_499 += 1;


                    if (g_298)
                        goto lbl_393;
                    g_128 = ((((safe_lshift_func_int8_t_s_u((l_316 ^ (((safe_rshift_func_uint16_t_u_s(g_259, (safe_mul_func_uint16_t_u_u((l_124 = (~((((safe_sub_func_uint8_t_u_u((0x0CL < l_248), (safe_sub_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_u((l_254 = (safe_mul_func_int8_t_s_s((safe_lshift_func_uint8_t_u_u((~65531UL), ((((g_271 , (safe_rshift_func_int8_t_s_u(g_185[6][0][2], 1))) >= (g_300 ^ (safe_mod_func_uint32_t_u_u((((l_127 ^= (safe_add_func_int8_t_s_s((safe_sub_func_int32_t_s_s(((safe_mul_func_int8_t_s_s(((safe_mul_func_uint8_t_u_u((l_431 &= (((((safe_lshift_func_uint8_t_u_u((safe_mul_func_int8_t_s_s((safe_add_func_uint32_t_u_u(l_430, l_430)), 7UL)), l_316)) , l_249) >= (-3L)) & l_383) && 0xB6700EEBL)), p_83)) , p_82), g_184[6][0][2])) != p_82), g_298)), g_257))) & 0x2B05L) , 0xFDE8E21DL), l_144)))) , l_432) & g_130))), l_358))), 6)) && 249UL), g_186)))) | l_433[9][0]) || g_300) , g_185[6][0][2]))), l_122)))) == g_331[8]) | 0xD6E36051L)), 7)) > 0L) <= g_129) & 2UL);
                    for (g_130 = 0; (g_130 <= 2); g_130 += 1)
                    {

g_129 ^= (safe_sub_func_uint8_t_u_u(((g_256 = l_240[3]) >= (safe_add_func_int8_t_s_s(l_461, ((l_251 ^= l_107) ^ (++g_483))))), g_186));


                    return l_430;
                    }
                }
            }
            if (g_271)
                goto lbl_462;
lbl_462:
            l_254 &= ((safe_add_func_uint8_t_u_u((((l_249 <= (((safe_mul_func_int8_t_s_s((-1L), p_83)) , ((safe_mul_func_uint16_t_u_u(((safe_rshift_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s(p_83, (safe_add_func_uint16_t_u_u(l_240[1], p_82)))), 7)), l_240[4])) , g_184[2][0][2]), ((safe_lshift_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_rshift_func_int8_t_s_s((safe_mul_func_int8_t_s_s(((((safe_add_func_int32_t_s_s(0x3097D770L, 0x0EBB21D4L)) < g_123) || (-1L)) < l_460), 252UL)), l_127)), p_82)), 1)) >= l_252))) != l_253)) != g_184[6][0][2])) & l_461) < 0x20BD9D44L), l_249)) < p_83);
            ++l_463;
        }
    }
    else
    {
        uint32_t l_511 = 0xA77FD89CL;
        uint8_t l_532 = 0xEAL;
        int32_t l_546 = 0x1CB7CBD9L;
        int16_t l_578 = 0x22EDL;
        int32_t l_622 = 1L;
        l_125 = (safe_rshift_func_int16_t_s_u(g_43, 15));
        for (g_128 = 19; (g_128 >= (-26)); g_128 = safe_sub_func_int32_t_s_s(g_128, 3))
        {
            int16_t l_490 = (-1L);
            int32_t l_496 = 0xD080FBE3L;
            for (g_123 = (-16); (g_123 < 28); g_123++)
            {
                int8_t l_488 = 0L;
                g_483 = ((safe_rshift_func_uint16_t_u_u(65535UL, 0)) & ((safe_mul_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((g_130 = (!(safe_rshift_func_int8_t_s_u(g_211[0], 3)))), 10)), g_129)) > l_127));
                if (g_348[0][2][0])
                    {
{
            transparent_crc(g_392[g_1371][l_124], "g_392[g_1371][l_124]", l_125);
            if (l_125) printf("index = [%d][%d]\n", g_1371, l_124);

        }

                    break;}
                for (g_332 = (-28); (g_332 > 2); g_332++)
                {
                    for (l_127 = (-25); (l_127 <= (-16)); l_127 = safe_add_func_uint8_t_u_u(l_127, 1))
                    {
                        if (g_331[2])
                            {
{
                    for (g_483 = 2; (g_483 <= 8); g_483 += 1)
                    {
                        int i;
                        return g_331[g_483];
                    }
                }

                    break;}
                        return g_211[1];
                    }
                    g_489 &= ((g_130 || 0x68L) && (l_488 |= g_186));
                    if (l_490)
                        continue;
                }
                g_498 = (g_497[0][0] = (safe_lshift_func_int16_t_s_s((!(((g_186 ^= (safe_mul_func_uint16_t_u_u(l_490, 0x927FL))) >= l_124) && (1L <= ((p_83 | (p_82 != ((5UL <= g_211[1]) & (l_496 = ((-1L) != l_488))))) , g_185[3][0][2])))), 9)));
            }
            ++g_499;
        }
        l_126 = (g_128 = (p_82 & (((!(safe_rshift_func_int8_t_s_u((-1L), 1))) , (safe_lshift_func_uint16_t_u_s(((l_127 &= (safe_rshift_func_uint16_t_u_s(((((safe_sub_func_uint8_t_u_u(l_511, ((((safe_unary_minus_func_uint16_t_u(((((l_125 = (l_240[4] , (((((safe_rshift_func_uint16_t_u_u(((safe_mod_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_s((((((safe_sub_func_int32_t_s_s((safe_sub_func_uint16_t_u_u((g_211[0] < (safe_rshift_func_uint8_t_u_u(((((safe_add_func_int8_t_s_s((((safe_lshift_func_int16_t_s_s((0L != 0x7713L), (g_152[7][5] = g_257))) < (((safe_rshift_func_uint16_t_u_s(g_184[4][0][1], 12)) < l_511) , 0xE8L)) , g_483), l_511)) != g_392[2][4]) , l_511) < l_511), 3))), 0UL)), g_256)) > g_332) == g_130) || p_83) && p_82), 6)), l_125)) || 0x234AL), g_130)) > 0xC8BAL) > g_256) != l_125) != l_531))) != g_348[0][8][0]) >= 3UL) | p_82))) ^ 0x51L) , g_211[1]) > 0UL))) , l_90) > p_83) != l_532), g_392[0][3]))) < (-6L)), 7))) & l_511)));
        for (g_129 = 0; (g_129 <= 3); g_129 += 1)
        {
            int8_t l_537[4][6] = {{1L, 0x2DL, 0x3BL, 0L, 0L, 0x3BL}, {1L, 0x2DL, 0x3BL, 0L, 0L, 0x3BL}, {1L, 0x2DL, 0x3BL, 0L, 0L, 0x3BL}, {1L, 0x2DL, 0x3BL, 0L, 0L, 0x3BL}};
            int8_t l_566 = 0L;
            uint32_t l_569 = 2UL;
            int32_t l_582 = 1L;
            int32_t l_586 = 0L;
            int32_t l_591 = 0x0D5FFFDDL;
            uint16_t l_592[2][1][3] = {{{65533UL, 0x6472L, 65533UL}}, {{65533UL, 0x6472L, 65533UL}}};
            int8_t l_649 = 0xBCL;
            int i, j, k;
            l_125 = ((safe_lshift_func_uint8_t_u_s((safe_sub_func_uint32_t_u_u((l_537[3][0] , (safe_mod_func_int32_t_s_s(0xB92F76AEL, (safe_sub_func_uint16_t_u_u((((l_90 >= (g_185[6][0][2] == ((((((((safe_add_func_int16_t_s_s((safe_lshift_func_int8_t_s_u((-1L), (l_546 |= (p_82 == ((-2L) != p_82))))), g_392[3][8])) | l_532) , l_537[3][0]) <= 253UL) | g_259) < l_532) < (-1L)) == g_392[2][4]))) >= p_83) < (-1L)), 0x0F6EL))))), l_248)), 1)) ^ 0xC85A9D1DL);
            g_128 = 0x1CC6DAC4L;
            g_128 &= ((p_83 |= (safe_rshift_func_uint8_t_u_u((~l_550), 2))) , l_537[3][0]);
            if (l_124)
                continue;
            for (g_257 = 1; (g_257 >= 0); g_257 -= 1)
            {
                int16_t l_585 = 0xF957L;
                int32_t l_624 = 0x85AABD85L;
                uint16_t l_632 = 0xA693L;
                int32_t l_651 = 0L;
                int16_t l_665 = 1L;
                int i;

g_186 |= (safe_sub_func_int16_t_s_s(((safe_lshift_func_int16_t_s_s(((l_578 = (((((safe_sub_func_int8_t_s_s((1L & (g_2385 , (g_1232 &= ((l_127 = g_2845) , g_1302)))), l_842)) != 0x3861C090L) == g_271) <= 7L) & 0xAAE3C059L)) ^ 0x2F0AL), g_348[1][2][0])) >= l_90), g_184[6][0][2]));


                    l_546 = ((g_211[g_257] < (safe_unary_minus_func_int16_t_s((safe_sub_func_uint8_t_u_u((((((safe_add_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_s((safe_lshift_func_int8_t_s_u(((p_83 | (((safe_rshift_func_int16_t_s_s(((safe_sub_func_int16_t_s_s(((safe_lshift_func_uint16_t_u_s(p_83, 5)) < l_566), (g_152[3][6] == (((((((l_537[2][1] , (g_483 < ((l_240[4] , ((((g_259 | 0UL) == 3L) | p_82) & 4294967293UL)) , 5UL))) > p_83) <= g_497[0][5]) , 0x1BAE3C5EL) & p_82) , l_537[3][1]) >= 0UL)))) > g_332), g_185[6][0][0])) ^ g_497[0][2]) >= l_569)) ^ g_152[7][5]), g_186)), 1)), l_537[1][0])) <= 0xDAL) , g_211[g_257]) & g_392[2][4]) , g_211[g_257]), g_570))))) <= p_82);
                for (p_82 = 0; (p_82 <= 0); p_82 += 1)
                {
                    int8_t l_621 = 0x13L;
                    int32_t l_669 = 1L;
                    int i, j, k;
                    if ((((((((4UL > ((safe_unary_minus_func_int32_t_s((safe_lshift_func_uint16_t_u_s(((0x828F8CECL <= (safe_sub_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u(((l_125 &= (g_348[1][2][0]--)) != ((safe_unary_minus_func_int16_t_s((l_582 ^= (l_546 = g_185[(g_257 + 3)][p_82][p_82])))) != (l_578 || ((l_586 = (safe_lshift_func_uint8_t_u_u(l_585, 7))) != ((safe_lshift_func_int8_t_s_s(0xBDL, (0xC0L | ((((safe_add_func_int16_t_s_s(((l_591 &= (p_83 <= 0xA750CE1FL)) || 0xFD4DAF73L), g_257)) ^ l_511) , p_82) != l_592[1][0][2])))) && l_532))))), 9)), g_499))) != p_83), g_392[2][4])))) || p_82)) , g_331[3]) && p_82) != l_531) , (-3L)) <= g_185[(g_257 + 3)][p_82][p_82]) | p_82))
                    {
                        int32_t l_593 = 1L;
                        if (g_497[0][0])
                            break;
                        l_593 = g_257;
                    }
                    else
                    {
                        uint32_t l_602[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_602[i] = 1UL;
                        g_128 = ((l_586 = ((safe_rshift_func_uint16_t_u_s(g_128, 5)) > (safe_mul_func_uint8_t_u_u((((safe_mod_func_int8_t_s_s((safe_sub_func_int8_t_s_s(g_331[2], 0x6BL)), p_82)) , 1L) > (l_582 = (((((((((g_152[1][0] >= p_82) < (l_602[0] != g_392[1][1])) <= g_348[1][2][0]) , l_602[0]) ^ 65535UL) || (-7L)) , (-1L)) , p_82) == l_585))), g_257)))) , 1L);
                        g_128 = p_82;
                        l_591 = (safe_add_func_uint32_t_u_u((safe_mul_func_uint16_t_u_u((l_126 = g_256), (l_624 = (((-2L) != ((g_298 , (1L != (g_211[(p_82 + 1)]--))) , (((safe_add_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s((g_483 | ((l_546 != g_300) == ((((safe_mod_func_int32_t_s_s(l_617, (l_622 = (safe_add_func_uint32_t_u_u((safe_unary_minus_func_uint16_t_u((g_348[0][3][0] > l_621))), g_211[g_257]))))) < l_125) == g_211[1]) && 0xE7L))), 12)), p_83)) & g_483) != l_623))) < 0x887EA039L)))), g_298));
                    }
                    if (p_83)
                        continue;

l_566 ^= (l_952 & (g_3475 = (safe_add_func_uint32_t_u_u((1UL | ((~(-1L)) || (l_621 , ((safe_add_func_int8_t_s_s(g_211[0], (k | ((g_1482 = (((0x0DL == 0xF5L) == l_617) , 0L)) | k)))) >= g_211[1])))), l_952))));


                    if ((safe_mul_func_uint8_t_u_u(((~(((safe_lshift_func_int16_t_s_s((safe_mul_func_uint8_t_u_u(l_632, 0L)), (((g_211[1] = ((l_546 = (safe_mod_func_uint32_t_u_u(p_83, 4294967295UL))) <= (safe_mod_func_int32_t_s_s((-1L), (safe_mod_func_int16_t_s_s((((l_126 = 0L) , (((safe_rshift_func_uint16_t_u_s(((((l_592[1][0][2] , ((((((safe_mul_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(p_82, ((safe_rshift_func_int8_t_s_u((((safe_mod_func_int32_t_s_s((g_185[6][0][7] < g_130), 0x3F64C02FL)) , p_83) | 6UL), l_125)) && (-2L)))), 5L)) && l_240[4]) | 1UL) == l_578) & l_578) > g_271)) | p_82) < p_83) || l_622), l_649)) | p_83) > l_582)) , l_650), 65531UL)))))) ^ 0x31L) , g_211[g_257]))) < l_651) > g_489)) < p_82), 0x0AL)))
                    {
                        int32_t l_668[5][3][4] = {{{0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}, {0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}, {0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}}, {{0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}, {0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}, {0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}}, {{0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}, {0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}, {0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}}, {{0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}, {0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}, {0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}}, {{0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}, {0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}, {0xEB098103L, 0x7FA4C102L, 6L, 0x7FA4C102L}}};
                        int i, j, k;
                        g_670 = (g_128 = ((((((!(safe_mul_func_uint16_t_u_u(g_348[0][3][0], p_83))) == (((0xEDL ^ (~(((g_498 = (g_498 > (l_586 = (safe_mod_func_uint16_t_u_u((safe_sub_func_int8_t_s_s(0L, (l_669 ^= (safe_lshift_func_uint8_t_u_u((safe_unary_minus_func_int16_t_s((((safe_add_func_uint8_t_u_u(p_83, l_665)) || ((((safe_mul_func_uint8_t_u_u(p_82, (((((l_582 <= g_185[6][0][2]) ^ 0L) ^ 0x4F87L) >= 0xD6L) && p_82))) | g_499) ^ p_82) == l_668[3][1][0])) , l_90))), g_129))))), p_83))))) != g_489) , p_83))) , 0x4CL) ^ g_392[2][4])) & g_152[7][5]) < 0UL) | (-8L)) ^ g_185[(g_257 + 3)][p_82][p_82]));
                        l_125 = (p_82 || ((l_669 = p_82) <= ((((safe_sub_func_uint32_t_u_u((((p_82 < ((safe_add_func_int32_t_s_s(l_586, (0xC1C2L ^ ((safe_rshift_func_uint16_t_u_u((safe_mod_func_int32_t_s_s(p_82, (p_82 && l_578))), (g_43 ^= ((p_83 && l_649) <= 0xA0C7L)))) , p_82)))) , 0xC0L)) != 0xEBC5L) ^ g_130), l_124)) , 0x94L) || 0x06L) == p_82)));
                    }
                    else
                    {
                        return g_570;
                    }
                }
            }
        }
    }
    for (g_271 = (-30); (g_271 > 8); g_271 = safe_add_func_uint16_t_u_u(g_271, 3))
    {
        int32_t l_697 = 0x851E1FC5L;
        int32_t l_722 = (-2L);
        for (g_332 = (-11); (g_332 <= 9); g_332++)
        {
            uint8_t l_698 = 1UL;
            int32_t l_703 = 0x9418BA95L;
            uint32_t l_704 = 0xDED63E84L;
            g_705 |= ((safe_mul_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((safe_add_func_uint32_t_u_u((g_128 >= (g_152[7][5] , ((l_703 = (((safe_sub_func_uint16_t_u_u((safe_sub_func_int16_t_s_s((safe_add_func_int32_t_s_s((safe_add_func_uint8_t_u_u((p_83 = ((l_698--) > g_130)), (p_82 , ((safe_add_func_int8_t_s_s((0xE6L == ((1UL >= l_697) >= l_703)), (p_82 == 0xA8BE2389L))) ^ g_271)))), p_82)), l_623)), l_704)) || p_82) == g_392[2][4])) == l_650))), l_704)), p_82)), l_550)) , g_128);
        }
        g_128 = 0xCA97DC43L;
        if ((((safe_add_func_uint8_t_u_u(0UL, p_82)) > (safe_lshift_func_uint8_t_u_u(l_697, (safe_mul_func_uint16_t_u_u(65533UL, (safe_rshift_func_uint8_t_u_u(((((safe_mod_func_uint8_t_u_u((((p_83 >= (safe_add_func_int16_t_s_s(l_623, (l_722 |= ((safe_add_func_int8_t_s_s((p_82 <= (safe_rshift_func_uint16_t_u_u(p_83, 14))), (2L ^ 0x2BL))) ^ 1L))))) > l_240[4]) >= 0x0C63L), g_298)) && p_83) , g_332) && l_124), 7))))))) < 249UL))
        {
                                           int32_t B6j6jjg_128 = (~((((~((~(l_248)))) & (~(((~((~(l_127)))) & (g_129 | g_256))))) << (g_123 & (~((g_128 ^ (((g_259 & l_697) ^ l_90) & l_722))))))));
uint32_t B6j6jkl_90 = (~((((g_128 | (~(l_722))) ^ ((~((~(g_129)))) | l_90)) || ((g_123 ^ (~(g_259))) | (~(((~((~((g_256 ^ B6j6jjg_128))))) ^ (l_248 ^ l_697))))))));
int32_t B6j6jll_697 = (~(((~(((~(((l_90 | (~((((~(l_697)) | g_128) | g_259)))) || (l_722 & B6j6jjg_128)))) & (~((~(l_248))))))) || (~(((l_127 & g_129) | B6j6jkl_90))))));
if(g_123){
B6j6jjg_128 = g_128;
B6j6jkl_90 = l_90;
B6j6jll_697 = l_697;
g_128 = (~(((~(((~((~(((~(l_90)) | (~(((g_123 << l_248) || (~((B6j6jjg_128 ^ g_129))))))))))) | g_256))) & ((~(((~((l_697 || (~(B6j6jkl_90))))) & B6j6jll_697))) & l_127))));
l_90 = (~(((((~((((g_129 || g_259) ^ g_123) | (l_722 & l_697)))) | l_90) | ((~(l_127)) | (B6j6jll_697 & (~(B6j6jjg_128))))) || (~((~(g_256)))))));
l_697 = (~(((~(((~(((g_259 & l_697) ^ B6j6jkl_90))) || (~((~(((l_127 ^ g_256) ^ (g_128 || (l_722 | g_123)))))))))) || ((~((~(l_90)))) ^ B6j6jjg_128))));
if((l_697 && (g_259<65532))){
printf("g_128=%lld\n", (long long)g_128);
continue;
}
if((g_129 > l_90)){
printf("l_90=%llu\n", (unsigned long long)l_90);
l_90 = (~(((((~(B6j6jll_697)) >> (~(((g_129 || l_722) << g_123)))) & (B6j6jjg_128 || g_128)) || ((g_256 | (~(B6j6jkl_90))) << (~((l_248 & l_127)))))));
B6j6jll_697 = (~(((((~(g_129)) || (~(((B6j6jkl_90 || B6j6jjg_128) | (l_90 & ((~(B6j6jll_697)) << g_259)))))) << (l_248 ^ l_697)) || ((~(g_123)) << (~((~(g_256))))))));
continue;
}
if((!g_259)){
printf("l_697=%lld\n", (long long)l_697);
B6j6jll_697 = (~(((~((~((~((~(((~((l_722 & B6j6jll_697))) | (~(g_128))))))))))) ^ ((~((~(g_129)))) | ((~((g_259 ^ (~(l_127))))) << (~((~((g_256 || ((l_90 >> l_248) >> B6j6jjg_128)))))))))));
continue;
}
}
g_128 = B6j6jjg_128;
l_90 = B6j6jkl_90;
l_697 = B6j6jll_697;

                    return p_82;
        }
        else
        {
            if (l_240[4])
                break;

{
                int32_t l_244 = 0x3608916AL;
                for (g_257 = (-25); (g_257 == (-12)); g_257++)
                {
                    uint8_t l_245[3];
                    int32_t l_250 = 0xAD904D1DL;
                    int32_t l_255 = 0xA02321D8L;
                    int32_t l_258[10];
                    int i;
                    for (i = 0; i < 3; i++)
                        l_245[i] = 0xE2L;
                    for (i = 0; i < 10; i++)
                        l_258[i] = 0x509FD6BDL;
                    --l_245[0];
                    g_259--;
                    for (g_186 = 23; (g_186 != 6); g_186 = safe_sub_func_int32_t_s_s(g_186, 1))
                    {
                        uint8_t l_268 = 0x93L;
                        l_722 = (0x5C32L | ((((-1L) || ((l_127 = ((g_820 ^= (((safe_mul_func_int8_t_s_s((((g_152[7][5] | (((l_268 , ((0UL ^ l_258[4]) >= (g_1371 , 1L))) <= (g_820 = ((safe_add_func_uint16_t_u_u((l_617 , g_152[3][6]), 0xA1DFL)) >= 255UL))) <= l_90)) | 0xCC9F1702L) & g_259), g_257)) || 0UL) ^ 0L)) || l_240[3])) || 0L)) | (-8L)) ^ 0x7559L));
                    }
                }
                g_705--;
                for (g_257 = 2; (g_257 != (-29)); g_257--)
                {
                    int16_t l_281 = 0xA7E0L;
                    l_650 = (((g_256 = ((safe_unary_minus_func_int16_t_s((safe_sub_func_int8_t_s_s(g_256, ((g_1371 &= (g_257 | ((0x8BL ^ l_650) ^ (g_185[6][0][2] >= ((g_128 = ((safe_mul_func_int16_t_s_s((l_281 , ((((safe_mul_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((((((safe_lshift_func_int8_t_s_u(((safe_rshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u((l_617 & g_257), 7)), g_152[7][5])), l_281)) ^ 0x8A383003L), 2)) < g_820) & 0L) || l_281) , 0x7B51L), 0x40EEL)) || g_2845), (-7L))) > 4294967287UL), l_240[4])) && 0x88DAE93EL) > g_257) >= l_281)), 0x7182L)) | g_257)) >= 4294967291UL))))) < 0x0025CD26L))))) >= 0x34L)) , g_257) < l_244);
                    l_722 = (l_650 = (g_257 < (safe_lshift_func_uint8_t_u_s(g_332, 5))));
                }
            }

                    return l_124;
        }
    }
    for (l_126 = 0; (l_126 >= 19); l_126 = safe_add_func_uint32_t_u_u(l_126, 2))
    {
        int32_t l_735 = 0xFDDD0EC5L;
        int32_t l_749 = 7L;
        int8_t l_768 = 0xB0L;
        int32_t l_803 = 0x2B9C7615L;
        uint32_t l_821 = 4294967289UL;
        uint32_t l_951 = 0UL;

for (g_257 = 2; (g_257 != (-29)); g_257--)
                {
                    int16_t l_281 = 0xA7E0L;
                    l_803 = (((l_749 = ((safe_unary_minus_func_int16_t_s((safe_sub_func_int8_t_s_s(l_749, ((l_623 &= (g_257 | ((0x8BL ^ l_803) ^ (g_185[6][0][2] >= ((l_650 = ((safe_mul_func_int16_t_s_s((l_281 , ((((safe_mul_func_int16_t_s_s(((safe_mod_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((((((safe_lshift_func_int8_t_s_u(((safe_rshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u((g_483 & g_123), 7)), g_152[7][5])), l_281)) ^ 0x8A383003L), 2)) < l_803) & 0L) || l_281) , 0x7B51L), 0x40EEL)) || i), (-7L))) > 4294967287UL), l_240[4])) && 0x88DAE93EL) > g_129) >= l_281)), 0x7182L)) | g_257)) >= 4294967291UL))))) < 0x0025CD26L))))) >= 0x34L)) , g_257) < g_1371);
                    g_1925 = (l_803 = (g_257 < (safe_lshift_func_uint8_t_u_s(g_498, 5))));
                };


                    l_735 = ((safe_add_func_uint8_t_u_u((g_211[0] , ((((((safe_lshift_func_int8_t_s_u((safe_mul_func_uint8_t_u_u(l_125, ((l_531 , (((safe_sub_func_int16_t_s_s((g_8 != ((p_83 && ((p_82 == (g_211[0] , (((((safe_add_func_int32_t_s_s(g_392[2][4], (l_124 |= (p_82 == 0UL)))) | p_82) || 7L) && g_498) >= l_240[4]))) <= g_392[0][1])) & 65535UL)), g_392[3][3])) < g_211[1]) ^ 1L)) >= l_240[4]))), 4)) & 0x6F09BCC5L) || l_240[5]) == (-6L)) > g_392[2][4]) , p_82)), 0x0AL)) <= 0L);

g_256 &= (safe_rshift_func_uint8_t_u_s(((safe_mul_func_int16_t_s_s((((safe_mul_func_int8_t_s_s((g_128 = ((safe_lshift_func_uint8_t_u_u(((g_1850 = ((((!(l_803 = (safe_add_func_uint16_t_u_u((safe_rshift_func_int8_t_s_s(((safe_mul_func_int16_t_s_s(g_300, 0xF86DL)) >= 0UL), g_1850)), g_300)))) <= g_1482) > g_130) >= g_300)) < g_129), l_126)) , g_300)), 1L)) , l_124) < l_531), 0x2E00L)) & g_1482), 2));


                    for (l_617 = 0; (l_617 < 4); l_617 = safe_add_func_uint8_t_u_u(l_617, 8))
        {
            uint32_t l_741[8][7][4] = {{{2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}}, {{2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}}, {{2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}}, {{2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}}, {{2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}}, {{2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}}, {{2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}}, {{2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}, {2UL, 1UL, 1UL, 0xD5061183L}}};
            int32_t l_746[1];
            int32_t l_950 = 0L;
            int i, j, k;
            for (i = 0; i < 1; i++)
                l_746[i] = 0x75F7F9D2L;
            g_128 = (safe_lshift_func_int16_t_s_s(((p_82 ^ (l_741[3][2][2] ^= (~0xCCL))) != ((l_749 |= (((p_82 & (l_735 = (safe_mul_func_int16_t_s_s(((4294967293UL || ((safe_add_func_int32_t_s_s((0x21727721L & l_746[0]), p_83)) >= p_83)) , (safe_mod_func_int8_t_s_s(l_735, p_82))), l_735)))) , 9UL) >= 0x8B55L)) ^ p_82)), 3));
            if (((l_127 = ((safe_add_func_uint32_t_u_u(((l_124 = (+(safe_mod_func_uint8_t_u_u(((!(-1L)) , (((safe_rshift_func_uint8_t_u_u(((safe_sub_func_int16_t_s_s((255UL >= ((l_749 < 0x07L) < ((((l_735 < (safe_unary_minus_func_uint16_t_u((l_531 && ((!(safe_add_func_int8_t_s_s((safe_mul_func_int8_t_s_s((l_768 = (p_82 < ((~(~g_152[7][5])) > ((l_746[0] <= 0x571D56DFL) , 0x34L)))), (-1L))), l_741[3][2][2]))) | 2L))))) ^ g_497[0][0]) > p_82) && 0xAE70AF2AL))), l_749)) || 0x60B7L), g_211[1])) != (-4L)) != (-3L))), 7UL)))) == l_769[1]), 5L)) , (-1L))) <= 0L))
            {
                uint16_t l_770 = 0x07FDL;
                int32_t l_778 = 0L;
                l_125 = (p_82 > (l_770 |= p_83));
                g_128 = (safe_rshift_func_uint16_t_u_u(g_497[0][0], 5));
                l_778 = (safe_mul_func_int16_t_s_s(l_735, ((!((safe_lshift_func_uint16_t_u_u(l_741[3][2][2], p_82)) , g_271)) & 0L)));
                g_128 = (-1L);
            }
            else
            {
                int16_t l_788 = (-7L);
                g_128 ^= ((safe_rshift_func_uint8_t_u_s((safe_sub_func_int16_t_s_s(((((safe_mod_func_int8_t_s_s(p_83, (safe_rshift_func_int8_t_s_s((+(g_499 ^ (((l_788 = (-5L)) == (1L < g_123)) ^ 0x0FL))), 2)))) , 0L) , (((safe_mul_func_int16_t_s_s((safe_sub_func_int16_t_s_s((l_768 && ((65535UL || g_392[3][5]) || g_331[2])), 65526UL)), g_331[6])) >= p_83) > 0L)) == l_735), 1UL)), 3)) <= 0x48L);
                if (p_82)
                    continue;
            }
            for (l_623 = 3; (l_623 >= 0); l_623 -= 1)
            {
                int i, j;
                l_127 &= (g_128 &= g_392[l_623][(l_623 + 6)]);

{
                    l_126 &= ((g_570 && 4294967295UL) , ((safe_lshift_func_uint16_t_u_u((+(safe_mul_func_uint16_t_u_u(65535UL, 0L))), 11)) || (1UL >= ((-7L) & g_1129))));
                }

                    return g_392[l_623][(l_623 + 2)];
            }
            if ((safe_add_func_int32_t_s_s((safe_sub_func_uint32_t_u_u(g_271, (safe_sub_func_int32_t_s_s((g_128 = (l_650 && ((-3L) > 0x78BBL))), (g_499 = ((((p_83 == ((safe_rshift_func_uint16_t_u_u((l_746[0] = l_803), 0)) <= ((g_331[2] , 0L) < (0xDE8DL < p_82)))) || l_768) & 0xB9F5L) <= l_768)))))), p_82)))
            {
                int8_t l_804 = 0xDEL;
                l_127 ^= ((p_83 <= l_741[4][2][0]) && (((l_804 <= ((~l_803) , (safe_rshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u(((safe_sub_func_uint16_t_u_u((safe_mul_func_int16_t_s_s(9L, (l_746[0] = ((safe_mod_func_int32_t_s_s(((((((!(((g_129 & (g_392[3][3] > (g_499 >= ((0L ^ p_83) >= 4294967295UL)))) , 0x40L) & g_211[1])) != g_332) != l_804) == l_126) , (-1L)) , (-7L)), p_82)) & p_82)))), 1L)) <= g_331[2]), 0x5CL)), g_570)))) > p_82) <= 0x7B698919L));
            }
            else
            {
                int8_t l_819[5];
                int32_t l_846 = (-10L);
                int32_t l_900[6] = {1L, 0L, 1L, 0L, 1L, 0L};
                uint16_t l_937 = 0x077AL;
                int i;
                for (i = 0; i < 5; i++)
                    {
for (g_570 = 0; (g_570 <= 0); g_570 += 1)
                    {
                        g_1925 = 0xB60EFBFCL;
                    };


                    l_819[i] = 0xDDL;}
                l_821--;
                g_128 = (((safe_lshift_func_int8_t_s_u((g_705 == (l_746[0] = (((l_768 != ((g_211[1] > (9UL & (safe_mul_func_int8_t_s_s(0x9AL, (((safe_rshift_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(p_83, (l_735 = (((safe_lshift_func_uint8_t_u_u((((l_125 = (safe_mod_func_int8_t_s_s((safe_mul_func_uint8_t_u_u(p_83, (safe_add_func_uint8_t_u_u(((((((safe_sub_func_int32_t_s_s(l_248, 0L)) , l_746[0]) | g_257) <= g_332) > g_256) | l_819[3]), g_497[0][4])))), g_298))) , l_842) && 4294967295UL), p_83)) > g_130) >= p_83)))), g_152[7][5])) && 0x4538234DL) >= l_124))))) || l_746[0])) , 65527UL) & p_82))), 5)) , g_348[1][2][0]) , 0x89005425L);
                if (g_256)
                {
                    for (g_128 = 0; (g_128 > 9); ++g_128)
                    {
                        int16_t l_845 = 0xB85FL;
                        g_820 = (l_846 = l_845);
                    }
                }
                else
                {
                    int8_t l_875 = (-1L);
                    int32_t l_897[5][6][8] = {{{(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}}, {{(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}}, {{(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}}, {{(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}}, {{(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}, {(-1L), 0x3A75AFEBL, 5L, (-1L), 0x546FA573L, 0xC5C7BDD0L, 0x3D831448L, 4L}}};
                    int32_t l_899 = 0x79F4FB2CL;
                    int i, j, k;
                    if ((p_82 <= (safe_sub_func_int16_t_s_s((0xA358L <= (((safe_sub_func_uint32_t_u_u((safe_rshift_func_int8_t_s_s(((safe_sub_func_int8_t_s_s(0L, (safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u((((safe_sub_func_uint8_t_u_u(((((safe_mod_func_int8_t_s_s((safe_sub_func_int8_t_s_s(g_489, (((((safe_mul_func_int16_t_s_s((safe_rshift_func_uint16_t_u_s((l_127 = (((safe_mul_func_uint16_t_u_u((0L ^ (((((safe_mod_func_int8_t_s_s((safe_mul_func_int16_t_s_s((p_83 ^ 0x67L), (g_348[0][3][0] <= p_83))), p_82)) && g_705) & g_152[3][6]) != p_82) == p_83)), g_498)) , l_746[0]) < p_83)), 8)), 1L)) ^ 0x84A3L) && g_259) ^ l_875) == g_152[7][5]))), g_184[6][1][1])) ^ (-1L)) & 0xCF8B20DCL) ^ l_741[3][2][2]), 252UL)) <= l_248) < 4294967295UL), g_489)), 0xCDL)))) || l_803), g_43)), l_875)) , p_82) > p_83)), 0UL))))
                    {
                        uint16_t l_876[2][9] = {{0x0531L, 1UL, 0xAB89L, 1UL, 0x0531L, 1UL, 0xAB89L, 1UL, 0x0531L}, {0x0531L, 1UL, 0xAB89L, 1UL, 0x0531L, 1UL, 0xAB89L, 1UL, 0x0531L}};
                        int i, j;
                        l_876[1][0]++;
                        return l_876[1][0];
                    }
                    else
                    {
                        uint32_t l_880 = 0x9BB784D6L;
                        uint16_t l_898[10] = {0x0A90L, 8UL, 0x0A90L, 8UL, 0x0A90L, 8UL, 0x0A90L, 8UL, 0x0A90L, 8UL};
                        int i;
                        l_880 = (g_820 = ((!p_82) == (g_348[0][6][0] ^ 0x968BD80DL)));
                        l_746[0] ^= ((((-10L) && (l_125 = ((((safe_lshift_func_int8_t_s_u(1L, g_298)) != (safe_add_func_int16_t_s_s(((+g_259) >= (((4294967295UL != ((l_900[2] |= ((((l_899 = ((((((4L <= (l_897[3][1][2] ^= (+(((safe_add_func_uint32_t_u_u((((0x6E8090E3L >= 0xCB13A50FL) | (((safe_add_func_uint32_t_u_u(((safe_mod_func_uint8_t_u_u(4UL, g_570)) >= p_83), p_82)) == 0xA4F42FC4L) >= 0L)) ^ 0L), l_650)) != 0L) == g_211[0])))) && p_83) & l_898[9]) , p_82) | p_82) > 0x7BC1L)) ^ l_819[1]) || g_186) ^ 0x69L)) == l_125)) , l_898[9]) || l_880)), g_128))) > l_898[2]) > 0xD9AEL))) ^ g_185[5][0][6]) > 4UL);
                        g_128 = ((((((((1L || ((safe_lshift_func_int16_t_s_s(((safe_add_func_int8_t_s_s((((+(safe_rshift_func_int16_t_s_u((safe_rshift_func_uint8_t_u_s((((l_746[0] <= ((g_211[0] == ((safe_mul_func_uint16_t_u_u((safe_sub_func_int32_t_s_s(((safe_sub_func_int16_t_s_s((+(g_392[2][4] , (((safe_rshift_func_uint16_t_u_s(l_875, (~l_617))) != (safe_mul_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u((!(safe_rshift_func_int8_t_s_u((l_550 , (g_332 &= (safe_lshift_func_int16_t_s_s((safe_mul_func_int16_t_s_s(g_259, (safe_lshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_s(((l_898[1] < p_83) || g_497[0][0]), l_819[3])) < p_82), g_130)), 12)))), 6)))), g_300))), 0x31L)) , g_300), g_8))) | 0xAEAD5E17L))), 0xED14L)) || p_82), 0x783F2A18L)), 65535UL)) >= p_82)) != 0xECL)) == 4UL) && 0xF17AL), 5)), l_897[2][0][2]))) == (-1L)) ^ l_768), g_392[2][5])) >= p_83), l_937)) & p_82)) < g_184[7][1][2]) & 0UL) && g_184[6][0][2]) >= l_768) , p_83) < (-1L)) , 0L);
                    }
                    l_952 = ((((((safe_rshift_func_uint16_t_u_s(p_82, (p_83 & (safe_mod_func_int32_t_s_s((g_128 = ((g_820 = (p_82 , ((safe_add_func_int8_t_s_s((0x8550A5FCL | ((safe_lshift_func_int16_t_s_u(g_130, ((l_950 ^= (safe_add_func_int32_t_s_s(((((g_152[3][0] , l_746[0]) , l_617) && ((((safe_lshift_func_int16_t_s_s(p_82, 4)) && g_185[2][0][7]) || 4294967295UL) , (-1L))) & 65529UL), p_82))) != g_331[2]))) , l_951)), 3L)) != p_83))) > g_392[2][4])), g_271))))) < p_82) , p_83) | 0UL) , l_951) ^ l_741[5][3][2]);
                    g_128 = (safe_lshift_func_int8_t_s_u((safe_mod_func_int16_t_s_s((l_900[4] = (g_152[7][5] = (safe_unary_minus_func_int32_t_s((0UL < (--g_130)))))), 65527UL)), g_300));
                }
            }
        }
    }
    return p_83;
}





int main (void)
{
    int i, j, k;
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
    transparent_crc(g_8, "g_8", print_hash_value);
    transparent_crc(g_43, "g_43", print_hash_value);
    transparent_crc(g_123, "g_123", print_hash_value);
    transparent_crc(g_128, "g_128", print_hash_value);
    transparent_crc(g_129, "g_129", print_hash_value);
    transparent_crc(g_130, "g_130", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 7; j++)
        {
            transparent_crc(g_152[i][j], "g_152[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 3; k++)
            {
                transparent_crc(g_184[i][j][k], "g_184[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 1; j++)
        {
            for (k = 0; k < 8; k++)
            {
                transparent_crc(g_185[i][j][k], "g_185[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_186, "g_186", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        transparent_crc(g_211[i], "g_211[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_256, "g_256", print_hash_value);
    transparent_crc(g_257, "g_257", print_hash_value);
    transparent_crc(g_259, "g_259", print_hash_value);
    transparent_crc(g_271, "g_271", print_hash_value);
    transparent_crc(g_298, "g_298", print_hash_value);
    transparent_crc(g_300, "g_300", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_331[i], "g_331[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_332, "g_332", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 1; k++)
            {
                transparent_crc(g_348[i][j][k], "g_348[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 10; j++)
        {
            transparent_crc(g_392[i][j], "g_392[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_483, "g_483", print_hash_value);
    transparent_crc(g_489, "g_489", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 10; j++)
        {
            transparent_crc(g_497[i][j], "g_497[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_498, "g_498", print_hash_value);
    transparent_crc(g_499, "g_499", print_hash_value);
    transparent_crc(g_570, "g_570", print_hash_value);
    transparent_crc(g_670, "g_670", print_hash_value);
    transparent_crc(g_705, "g_705", print_hash_value);
    transparent_crc(g_820, "g_820", print_hash_value);
    transparent_crc(g_1129, "g_1129", print_hash_value);
    transparent_crc(g_1232, "g_1232", print_hash_value);
    transparent_crc(g_1302, "g_1302", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_1303[i], "g_1303[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_1371, "g_1371", print_hash_value);
    transparent_crc(g_1482, "g_1482", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_1483[i], "g_1483[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_1596, "g_1596", print_hash_value);
    for (i = 0; i < 10; i++)
    {
        transparent_crc(g_1676[i], "g_1676[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_1752, "g_1752", print_hash_value);
    transparent_crc(g_1850, "g_1850", print_hash_value);
    transparent_crc(g_1925, "g_1925", print_hash_value);
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 4; j++)
        {
            transparent_crc(g_2108[i][j], "g_2108[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_2385, "g_2385", print_hash_value);
    transparent_crc(g_2560, "g_2560", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 10; j++)
        {
            transparent_crc(g_2792[i][j], "g_2792[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_2845, "g_2845", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_3008[i], "g_3008[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_3059, "g_3059", print_hash_value);
    transparent_crc(g_3069, "g_3069", print_hash_value);
    transparent_crc(g_3202, "g_3202", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 6; j++)
        {
            transparent_crc(g_3238[i][j], "g_3238[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_3475, "g_3475", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

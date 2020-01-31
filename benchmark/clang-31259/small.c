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



static int32_t g_2 = 1;
static int16_t g_70 = (-10);
static uint8_t g_83 = 0xE9;
static uint32_t g_126 = 4294967295U;
static int32_t g_140 = (-3);
static uint32_t g_143 = 5U;
static uint32_t g_147[7] = {4294967295U, 4294967295U, 4294967295U, 4294967295U, 4294967295U, 4294967295U, 4294967295U};
static uint8_t g_148 = 254U;
static uint8_t g_171 = 7U;
static uint32_t g_176 = 0x3249D86C;
static int16_t g_213 = 0xBBAC;
static uint32_t g_264 = 4294967287U;
static int8_t g_265 = 0;
static int32_t g_266 = (-1);
static uint32_t g_268 = 0xAFABA540;
static int32_t g_272 = 0xFC52F8FE;
static uint8_t g_274[8] = {255U, 255U, 0xD0, 255U, 255U, 0xD0, 255U, 255U};
static int16_t g_306 = (-6);
static int32_t g_308 = 6;
static int8_t g_317 = 0x6D;
static uint32_t g_350 = 4294967293U;
static int16_t g_352 = 0x1111;
static int8_t g_373 = 0;
static int32_t g_375 = 0x44E1BC11;
static int16_t g_376 = (-5);
static uint32_t g_377 = 0x86EDB65A;
static uint32_t g_477 = 0U;
static const int8_t g_553[3] = {4, 4, 4};
static uint8_t g_613 = 254U;
static int8_t g_643[7][5][7] = {{{8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}}, {{8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}}, {{8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}}, {{8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}}, {{8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}}, {{8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}}, {{8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}, {8, 0x98, (-2), 0xE0, 0x5B, 0x5A, 4}}};
static int16_t g_644 = 7;
static uint32_t g_646[9] = {7U, 0x4419A537, 7U, 0x4419A537, 7U, 0x4419A537, 7U, 0x4419A537, 7U};
static int16_t g_738 = (-8);
static int8_t g_865 = (-1);
static uint32_t g_866 = 1U;
static uint32_t g_869 = 1U;
static int32_t g_894[5][4] = {{0, 8, 0x093BC3F6, 8}, {0, 8, 0x093BC3F6, 8}, {0, 8, 0x093BC3F6, 8}, {0, 8, 0x093BC3F6, 8}, {0, 8, 0x093BC3F6, 8}};
static uint32_t g_898 = 0x72E5EF1B;
static int16_t g_911 = 0xD523;
static int8_t g_940 = (-7);
static int8_t g_942[3][3] = {{0x3B, 0x3B, 0x3B}, {0x3B, 0x3B, 0x3B}, {0x3B, 0x3B, 0x3B}};
static uint8_t g_944 = 254U;
static int32_t g_1081[1] = {1};
static int8_t g_1082 = 8;
static uint32_t g_1084 = 0x282B3569;
static uint8_t g_1130 = 0x35;
static int32_t g_1131 = 0x7BC1264D;
static uint32_t g_1132 = 4294967295U;
static int16_t g_1143[5][1][8] = {{{8, 0xAADC, 9, (-10), 9, 0xAADC, 8, 0x620B}}, {{8, 0xAADC, 9, (-10), 9, 0xAADC, 8, 0x620B}}, {{8, 0xAADC, 9, (-10), 9, 0xAADC, 8, 0x620B}}, {{8, 0xAADC, 9, (-10), 9, 0xAADC, 8, 0x620B}}, {{8, 0xAADC, 9, (-10), 9, 0xAADC, 8, 0x620B}}};
static uint32_t g_1146 = 0xD258F41F;
static int32_t g_1149 = 0xAFE9AC74;
static uint8_t g_1150 = 0x2A;
static uint16_t g_1247 = 0x8509;
static uint8_t g_1323 = 1U;
static int32_t g_1419 = (-1);
static uint32_t g_1420 = 0x3E230C74;
static uint16_t g_1442[5][6] = {{65526U, 65529U, 0x8934, 0x2732, 65529U, 0U}, {65526U, 65529U, 0x8934, 0x2732, 65529U, 0U}, {65526U, 65529U, 0x8934, 0x2732, 65529U, 0U}, {65526U, 65529U, 0x8934, 0x2732, 65529U, 0U}, {65526U, 65529U, 0x8934, 0x2732, 65529U, 0U}};
static int8_t g_1526 = 0x1D;
static uint16_t g_1857 = 4U;
static uint32_t g_1866 = 1U;
static int32_t g_1918[3] = {0x88AA529A, 0x88AA529A, 0x88AA529A};
static uint16_t g_1979 = 65530U;
static const uint8_t g_1997 = 0x5C;
static int8_t g_2203 = 5;
static uint32_t g_2593[10][8][3] = {{{0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}}, {{0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}}, {{0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}}, {{0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}}, {{0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}}, {{0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}}, {{0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}}, {{0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}}, {{0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}}, {{0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}, {0x973F44A0, 0U, 0x349B7DB6}}};
static uint32_t g_2627[1][2] = {{5U, 5U}};
static const int16_t g_2740 = (-1);



inline static int8_t func_1(void);
static uint32_t func_8(uint16_t p_9, int8_t p_10, int16_t p_11);
inline static int32_t func_12(int16_t p_13, int16_t p_14, int16_t p_15);
static int8_t func_21(int32_t p_22, uint8_t p_23, uint8_t p_24, int32_t p_25);
inline static int16_t func_31(int8_t p_32, uint8_t p_33, int32_t p_34);
static uint8_t func_39(int16_t p_40);
static const int32_t func_45(uint8_t p_46, const uint32_t p_47, uint32_t p_48, int8_t p_49, const uint8_t p_50);
static uint32_t func_54(int8_t p_55, uint8_t p_56, int32_t p_57, uint8_t p_58, int32_t p_59);
static int32_t func_61(int32_t p_62, uint8_t p_63, uint32_t p_64);
inline static const uint16_t func_88(const int32_t p_89);
inline static int8_t func_1(void)
{
    uint32_t l_7 = 0x0F023498;
    uint16_t l_1596 = 0U;
    int32_t l_1597 = 0xA67A1CEC;
    int32_t l_1598 = 0x2FA13EA1;
    uint32_t l_1651 = 0x387380E8;
    int32_t l_1829 = (-1);
    uint16_t l_1868 = 0x6F15;
    int8_t l_1931 = (-7);
    uint8_t l_2161 = 255U;
    int32_t l_2208 = 0xE515C256;
    uint16_t l_2255 = 65528U;
    int32_t l_2298 = 0;
    int32_t l_2299 = 0xE1508D0B;
    int32_t l_2300 = (-1);
    uint32_t l_2317 = 0x83B2A44A;
    int16_t l_2416 = 0x7640;
    int32_t l_2491 = 0x1E273E81;
    uint8_t l_2536 = 0x0E;
    uint32_t l_2538 = 0U;
    uint16_t l_2546 = 0x39B2;
    int16_t l_2592 = 1;
    uint32_t l_2695 = 0x9309CD33;
    uint32_t l_2712[4] = {0xDDA5EDE9, 1U, 0xDDA5EDE9, 1U};
    int32_t l_2747 = 5;
    int i;
    for (g_2 = 0; (g_2 != 14); g_2 = safe_add_func_uint16_t_u_u(g_2, 7))
    {
        int16_t l_1527 = 4;
        int32_t l_1528 = 8;
        l_1528 = (safe_mul_func_uint16_t_u_u((0xA4 && (l_1527 = ((0x5747 && (((l_7 && l_7) >= g_2) != l_7)) | func_8(l_7, g_2, l_7)))), g_1081[0]));
    }
    if (g_869)
    {
        uint16_t l_1557 = 3U;
        int32_t l_1565[2];
        int32_t l_1585 = 0xDE611C63;
        uint32_t l_1627[4][9] = {{0x757F4122, 0U, 1U, 4294967295U, 1U, 0xE8F22826, 0xE5F6BDEA, 4294967295U, 1U}, {0x757F4122, 0U, 1U, 4294967295U, 1U, 0xE8F22826, 0xE5F6BDEA, 4294967295U, 1U}, {0x757F4122, 0U, 1U, 4294967295U, 1U, 0xE8F22826, 0xE5F6BDEA, 4294967295U, 1U}, {0x757F4122, 0U, 1U, 4294967295U, 1U, 0xE8F22826, 0xE5F6BDEA, 4294967295U, 1U}};
        int8_t l_1655 = (-4);
        int32_t l_1695[2];
        int32_t l_1802 = (-1);
        int32_t l_1867 = 5;
        int16_t l_1978 = 0x5083;
        uint32_t l_2165 = 0xABA788A1;
        int i, j;
        for (i = 0; i < 2; i++)
            l_1565[i] = 8;
        for (i = 0; i < 2; i++)
            l_1695[i] = 7;
        for (g_265 = 3; (g_265 <= 8); g_265 += 1)
        {
            uint32_t l_1564 = 4294967291U;
            int32_t l_1643 = 0;
            const int16_t l_1719 = 5;
            int32_t l_1800 = (-1);
            int32_t l_1801[2][3][9] = {{{0xD4862293, 0xC48755B4, 0, 0x23F21FA2, 0x23F21FA2, 0, 0xC48755B4, 0xD4862293, 0x1A55B2D3}, {0xD4862293, 0xC48755B4, 0, 0x23F21FA2, 0x23F21FA2, 0, 0xC48755B4, 0xD4862293, 0x1A55B2D3}, {0xD4862293, 0xC48755B4, 0, 0x23F21FA2, 0x23F21FA2, 0, 0xC48755B4, 0xD4862293, 0x1A55B2D3}}, {{0xD4862293, 0xC48755B4, 0, 0x23F21FA2, 0x23F21FA2, 0, 0xC48755B4, 0xD4862293, 0x1A55B2D3}, {0xD4862293, 0xC48755B4, 0, 0x23F21FA2, 0x23F21FA2, 0, 0xC48755B4, 0xD4862293, 0x1A55B2D3}, {0xD4862293, 0xC48755B4, 0, 0x23F21FA2, 0x23F21FA2, 0, 0xC48755B4, 0xD4862293, 0x1A55B2D3}}};
            uint16_t l_1904[4][7] = {{65528U, 65535U, 0U, 0U, 65535U, 65528U, 65535U}, {65528U, 65535U, 0U, 0U, 65535U, 65528U, 65535U}, {65528U, 65535U, 0U, 0U, 65535U, 65528U, 65535U}, {65528U, 65535U, 0U, 0U, 65535U, 65528U, 65535U}};
            int32_t l_1927[6][7][6] = {{{1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}}, {{1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}}, {{1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}}, {{1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}}, {{1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}}, {{1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}, {1, 0, (-10), 0x8AC0ADAA, (-4), (-8)}}};
            int16_t l_1977 = 1;
            uint8_t l_1998 = 0x67;
            int32_t l_2105[10][1][3] = {{{3, 0xFA7C4257, 0xE1C66BA4}}, {{3, 0xFA7C4257, 0xE1C66BA4}}, {{3, 0xFA7C4257, 0xE1C66BA4}}, {{3, 0xFA7C4257, 0xE1C66BA4}}, {{3, 0xFA7C4257, 0xE1C66BA4}}, {{3, 0xFA7C4257, 0xE1C66BA4}}, {{3, 0xFA7C4257, 0xE1C66BA4}}, {{3, 0xFA7C4257, 0xE1C66BA4}}, {{3, 0xFA7C4257, 0xE1C66BA4}}, {{3, 0xFA7C4257, 0xE1C66BA4}}};
            uint32_t l_2129 = 0xFC073846;
            int32_t l_2149 = 0xC812937A;
            int i, j, k;
            for (g_613 = 1; (g_613 <= 4); g_613 += 1)
            {
                int8_t l_1529[5];
                uint8_t l_1571[10] = {7U, 0x23, 253U, 253U, 0x23, 7U, 0x23, 253U, 253U, 0x23};
                int i;
                for (i = 0; i < 5; i++)
                    l_1529[i] = 0x7A;
                for (g_213 = 0; (g_213 <= 8); g_213 += 1)
                {
                    uint32_t l_1536[4] = {4294967289U, 0x0C505958, 4294967289U, 0x0C505958};
                    int i;
                    for (g_1419 = 6; (g_1419 >= 0); g_1419 -= 1)
                    {
                        int i, j, k;
                        l_1529[3] = 0xEE514F02;
                        g_1131 |= 3;
                        g_375 = (safe_div_func_int8_t_s_s((l_1565[0] ^= (g_643[(g_613 + 1)][g_613][g_1419] = ((safe_mod_func_int32_t_s_s((((l_1536[1] = (safe_lshift_func_int16_t_s_u(g_643[g_1419][g_613][(g_613 + 2)], 13))) < g_274[g_1419]) | ((((safe_sub_func_uint8_t_u_u((1 != ((g_646[(g_1419 + 2)] = g_866) != (((((safe_div_func_int32_t_s_s((safe_mul_func_int16_t_s_s(1, (((safe_lshift_func_int16_t_s_u((safe_rshift_func_int8_t_s_s(0xFF, 5)), 0)) | (safe_sub_func_int32_t_s_s((safe_add_func_int16_t_s_s((safe_add_func_uint8_t_u_u(255U, ((safe_lshift_func_int16_t_s_s((safe_sub_func_int8_t_s_s(l_1557, ((safe_rshift_func_uint8_t_u_s((g_148--), (safe_mul_func_int8_t_s_s((0x6F & g_83), 1U)))) & (-10)))), 0)) & l_1564))), g_894[4][1])), 1U))) > 0xF64ADCDF))), 0x366762FB)) == g_272) && l_1529[3]) != l_1557) ^ 0x8C))), g_377)) && l_7) >= g_274[(g_1419 + 1)]) | l_7)), 4294967295U)) > l_7))), 0xCA));
                    }
                    for (g_738 = 0; (g_738 <= 0); g_738 += 1)
                    {
                        int i, j;
                        return g_894[(g_738 + 4)][(g_738 + 3)];
                    }
                }
                for (g_1082 = 4; (g_1082 >= 0); g_1082 -= 1)
                {
                    int32_t l_1599 = 0;
                    int i, j, k;
                    l_1571[5] = ((~g_643[(g_613 + 1)][g_613][g_1082]) || ((safe_lshift_func_int8_t_s_s(g_308, 1)) ^ ((l_1557 | g_1132) | (l_7 >= ((g_2 >= ((g_1081[0] || (0x6FA8A676 == (1U & g_265))) > 4294967290U)) <= l_7)))));
                    l_1599 = (((~l_7) && (safe_mul_func_uint8_t_u_u((l_1598 &= (safe_sub_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((0x80 > (((safe_sub_func_int16_t_s_s(l_1565[0], (safe_mod_func_uint16_t_u_u((l_1565[0] > (safe_mul_func_int8_t_s_s(((l_1585 = 0x315E) ^ (safe_rshift_func_int8_t_s_s(l_1571[6], 2))), ((g_1131 = (((safe_lshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((l_1596 ^= (safe_mul_func_uint16_t_u_u(l_7, (g_376 = (safe_rshift_func_uint8_t_u_u(255U, l_1529[3])))))), 2)) & g_1442[3][2]), 0)) == 7) >= l_1571[7])) != 0xBA93CEBE)))), l_1597)))) && g_147[0]) & 1U)), g_869)), l_7))), 0xD6))) != 0x6F);
                    if (l_1597)
                        continue;
                }
            }
            for (g_940 = 5; (g_940 >= 0); g_940 -= 1)
            {
                int32_t l_1626 = (-8);
                int32_t l_1644 = 1;
                uint16_t l_1670 = 1U;
                l_1598 = (safe_sub_func_uint32_t_u_u((0x9D36 > ((safe_lshift_func_uint16_t_u_s((safe_add_func_uint32_t_u_u((safe_add_func_int16_t_s_s((safe_div_func_uint8_t_u_u((g_738 != 0x548C13B8), (safe_rshift_func_uint16_t_u_s((safe_rshift_func_uint16_t_u_s((safe_mod_func_uint8_t_u_u(((safe_add_func_uint16_t_u_u((g_1247 = (safe_mul_func_int16_t_s_s(g_1081[0], (safe_add_func_int32_t_s_s(g_1323, ((safe_rshift_func_int16_t_s_s((((safe_mul_func_uint8_t_u_u(g_377, (l_1627[1][1] = l_1626))) && (safe_add_func_uint16_t_u_u(((--g_274[5]) || 1), (!((safe_mul_func_uint16_t_u_u(((safe_mul_func_int16_t_s_s((0x98C89E09 | l_1626), l_1597)) > l_7), 0x54B8)) | g_865))))) < 0), 6)) && 0x4002F82F)))))), l_1564)) != 1), l_7)), l_1597)), g_738)))), 1)), l_1626)), 4)) > g_869)), 0));
                l_1644 ^= (((g_865 == (-4)) || (safe_add_func_int16_t_s_s(((-8) != ((((((+0U) >= ((((l_1598 <= (safe_unary_minus_func_int32_t_s(l_1626))) ^ (safe_mul_func_uint8_t_u_u(0x5E, ((l_1643 = 0x55) <= (0x163993FF && g_350))))) >= 0U) | 0x10)) == 0x7903) ^ 8U) && g_1130) && g_898)), l_1565[0]))) != l_1596);
                for (g_83 = 0; (g_83 <= 4); g_83 += 1)
                {
                    uint16_t l_1671 = 0x4C59;
                    int32_t l_1672 = 0xA889F11B;
                    l_1643 = 0x2B97E775;
                    g_2 |= (safe_rshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_s((l_1672 &= (safe_mod_func_uint8_t_u_u((0x06 ^ l_1651), (0xF7DA | (+(safe_sub_func_int16_t_s_s((g_646[5] >= l_1655), (l_1643 = (((g_375 = (((((((safe_lshift_func_int16_t_s_s(((4U | (safe_sub_func_int8_t_s_s(((g_738 = ((safe_add_func_int8_t_s_s((safe_mod_func_uint8_t_u_u(g_126, l_1644)), ((safe_rshift_func_uint8_t_u_u((safe_add_func_uint32_t_u_u((safe_rshift_func_int16_t_s_s((l_1655 ^ 1U), l_1564)), 0xBBC0F7C5)), 7)) != g_1143[2][0][6]))) == l_1565[0])) ^ (-8)), 0x50))) ^ 0x8B4F52C6), 0)) | g_1084) >= 0) != l_1670) >= (-6)) && 0U) <= l_1596)) != l_1671) < 0x55B3))))))))), 11)), 10));
                }
            }
            for (g_940 = 3; (g_940 >= 0); g_940 -= 1)
            {
                int32_t l_1689[8] = {(-1), (-8), (-1), (-8), (-1), (-8), (-1), (-8)};
                int i, j;
                g_375 = (g_1149 |= g_894[(g_940 + 1)][g_940]);
                for (g_140 = 0; (g_140 <= 3); g_140 += 1)
                {
                    int32_t l_1688[6] = {1, 0xA4D84DD6, 1, 0xA4D84DD6, 1, 0xA4D84DD6};
                    int i, j, k;
                    g_375 = 0x56D3E059;
                    l_1585 ^= ((255U < (--g_274[(g_140 + 3)])) | (g_643[(g_140 + 1)][g_940][(g_140 + 2)] = l_1627[g_140][(g_140 + 4)]));
                    if ((g_940 < (g_1247++)))
                    {
                        uint8_t l_1677 = 0x44;
                        g_1419 ^= l_7;
                        g_1131 &= l_1677;
                    }
                    else
                    {
                        uint32_t l_1683 = 4294967288U;
                        int32_t l_1690[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_1690[i] = 0x2D754040;
                        g_2 &= g_1146;
                        g_1131 ^= 0xF1FE7C81;
                        l_1643 |= (~g_274[5]);
                        l_1690[4] = (safe_mul_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((g_1247 ^= ((((l_1683 > (g_894[(g_940 + 1)][g_940] > ((l_1689[2] = (l_1688[5] = (((g_894[(g_940 + 1)][g_940] >= ((l_1565[1] &= (g_213 > 0xAA3ADBBE)) != ((l_1643 > g_317) > ((safe_lshift_func_int8_t_s_u(g_894[(g_940 + 1)][g_940], 6)) | g_272)))) < g_268) | g_1442[4][2]))) < 0x5AF4))) && g_894[4][0]) > 0x39A5) && 1U)), 0)), l_1598));
                    }
                    l_1689[7] = (g_643[2][0][0] || (g_646[(g_940 + 2)] &= 1U));
                }
            }
            for (l_7 = 0; (l_7 <= 8); l_7 += 1)
            {
                int32_t l_1707 = 0xF3E6C229;
                int32_t l_1710 = 4;
                int8_t l_1781 = 1;
                uint8_t l_1908 = 0x77;
                int32_t l_2028 = (-1);
                uint32_t l_2070 = 6U;
                g_375 = ((safe_rshift_func_int16_t_s_u(g_1082, (3U || g_646[5]))) == (8U | (safe_add_func_uint32_t_u_u(g_1132, (l_1695[1] = 0)))));
                for (g_2 = 0; (g_2 <= 7); g_2 += 1)
                {
                    int32_t l_1746 = 0x33CF0918;
                    int32_t l_1782[2][4] = {{0x8A84389D, 1, 0x8A84389D, 1}, {0x8A84389D, 1, 0x8A84389D, 1}};
                    int i, j;
                    if ((safe_mod_func_int8_t_s_s(((g_274[g_2] < (l_1564 >= g_274[g_2])) <= 0x3E95), (((safe_mod_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(((l_7 & ((safe_lshift_func_uint16_t_u_u(((safe_unary_minus_func_uint16_t_u((l_1707 = g_274[g_2]))) < ((((safe_unary_minus_func_uint32_t_u((1 | (~(((((l_1710 | ((((safe_div_func_int8_t_s_s((((!(((safe_add_func_uint32_t_u_u((+((safe_div_func_uint16_t_u_u(l_1655, g_126)) & l_1719)), l_1655)) > 0xC4) & l_1598)) | g_213) != g_274[g_2]), l_1651)) && 7) && g_894[3][1]) < 2)) == 0xA1F1BBD8) <= 4294967295U) < l_1710) && g_643[2][2][2]))))) & 4294967292U) <= 65535U) != g_265)), 3)) < (-1))) >= (-10)), l_1719)), 0x49)) > l_1719) & g_375))))
                    {
                        int8_t l_1726 = (-5);
                        int32_t l_1733 = (-1);
                        int i;
                        g_1131 |= (g_375 = ((safe_lshift_func_int16_t_s_s((((safe_div_func_int8_t_s_s((0x09 == (((safe_mul_func_uint16_t_u_u((g_1442[4][2]++), (((((safe_mul_func_int16_t_s_s((l_1596 && ((0x94DE060A == (g_1419 = (l_1746 = ((l_1733 = l_1710) & (((safe_sub_func_int8_t_s_s((safe_mul_func_uint16_t_u_u((safe_div_func_int16_t_s_s((g_1143[2][0][6] = l_1707), (safe_mod_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s(4U, 12)), ((g_646[g_2] = (safe_mul_func_int16_t_s_s(g_865, 0x6084))) | ((0x473F79E0 <= g_1081[0]) <= g_272)))))), g_1419)), g_147[2])) ^ g_940) || g_70))))) >= 3)), g_147[0])) < 0x01) < g_143) & g_350) > g_308))) != g_869) | g_274[g_2])), g_1420)) >= 4294967286U) || l_1710), 4)) & 0x238F));
                        g_1131 = g_1130;
                    }
                    else
                    {
                        l_1643 = (safe_mod_func_int16_t_s_s(g_373, (safe_sub_func_int8_t_s_s(0x71, g_274[g_2]))));
                    }
                    l_1710 &= (safe_mul_func_uint16_t_u_u((l_1707 & ((safe_sub_func_int8_t_s_s((-2), (((((safe_mul_func_int16_t_s_s(6, (g_1146 == (((safe_div_func_int32_t_s_s((safe_mul_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u((safe_rshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u(g_1081[0], (safe_add_func_int8_t_s_s((safe_mod_func_int16_t_s_s(0x5D22, (++g_1442[1][4]))), (l_1781 = (g_140 || (safe_mul_func_int8_t_s_s(((safe_sub_func_int8_t_s_s((safe_div_func_uint32_t_u_u(g_265, g_268)), g_147[0])) ^ l_1651), g_147[5])))))))), 1)), l_1782[0][0])), g_375)), g_1149)) & 0x53FED7A1) && l_1655)))) > g_1081[0]) || g_268) > l_1651) >= l_1707))) <= 0)), 6U));
                }
                if ((safe_mod_func_int16_t_s_s(((safe_div_func_uint32_t_u_u((l_1627[1][6] && (l_7 & (l_1801[1][2][2] = ((safe_unary_minus_func_uint16_t_u(l_1651)) >= (safe_rshift_func_uint16_t_u_s((((((safe_lshift_func_uint8_t_u_u(l_1643, 3)) | (g_1526 = ((g_894[1][2] >= 0xEF5C) <= (l_1800 |= ((1 == ((((safe_lshift_func_uint16_t_u_s(((safe_add_func_uint32_t_u_u((0 < (safe_add_func_int32_t_s_s((safe_rshift_func_int8_t_s_s((g_942[1][1] != 0), l_1781)), l_1643))), l_1597)) >= g_477), 1)) & l_1719) || g_1420) > l_1597)) != g_1150))))) <= g_272) & g_1247) < (-2)), 3)))))), l_1564)) <= l_1802), g_308)))
                {
                    const int32_t l_1816 = 0x43261C9F;
                    int16_t l_1830[8][3] = {{(-1), (-1), (-4)}, {(-1), (-1), (-4)}, {(-1), (-1), (-4)}, {(-1), (-1), (-4)}, {(-1), (-1), (-4)}, {(-1), (-1), (-4)}, {(-1), (-1), (-4)}, {(-1), (-1), (-4)}};
                    int32_t l_1831[7] = {1, 0x8A4A74D2, 1, 0x8A4A74D2, 1, 0x8A4A74D2, 1};
                    uint8_t l_1907 = 0xF0;
                    int32_t l_1919 = 0x3639ACE0;
                    int32_t l_1920 = 0x04931CDF;
                    int i, j;
                    g_1131 ^= ((l_1831[4] ^= (safe_mul_func_uint16_t_u_u(((g_942[1][2] ^= ((safe_add_func_int8_t_s_s((safe_mul_func_uint8_t_u_u(((safe_div_func_uint16_t_u_u((safe_unary_minus_func_int16_t_s(((((--g_944) >= l_1816) == 0xC533) >= (((+(l_1643 = (((safe_lshift_func_uint8_t_u_s((!l_1651), 5)) <= (safe_mul_func_int8_t_s_s((0x68F7B23F >= (safe_div_func_uint8_t_u_u((safe_add_func_uint16_t_u_u((safe_mul_func_int16_t_s_s((l_1651 > (((g_646[g_265] = (g_1081[0] || ((-1) | (251U >= (-1))))) ^ l_1816) ^ l_1816)), g_1442[4][2])), g_894[3][1])), g_2))), g_375))) ^ l_1707))) != l_1829) > l_1816)))), g_268)) || 6U), 0xED)), l_1598)) > l_1564)) == 2), l_1830[1][2]))) != g_70);

i &= (((safe_sub_func_uint16_t_u_u((safe_add_func_int32_t_s_s(((safe_sub_func_int8_t_s_s(g_83, ((g_272 = ((((g_266 |= 1U) < (~(safe_add_func_int8_t_s_s((g_83 && (safe_rshift_func_int8_t_s_s(l_1998, ((0x36 >= (!255U)) > ((((safe_div_func_uint8_t_u_u(0x8E, g_1146)) > (safe_unary_minus_func_int8_t_s(l_1931))) & l_1931) > 0xF307))))), 1U)))) > g_83) > g_942[1][1])) && g_1084))) || g_643[2][2][2]), l_1931)), g_83)) ^ 0xB2) < 3U);


                    g_1131 |= (-1);
                    if ((+(g_176 | 7)))
                    {
                        uint16_t l_1833 = 65535U;
                        uint16_t l_1848 = 0x2A6E;
                        --l_1833;
                        l_1800 &= (((safe_mul_func_int8_t_s_s(0x9F, ((safe_sub_func_int32_t_s_s((safe_add_func_int8_t_s_s((l_1655 != l_1695[0]), (g_171 != g_646[g_265]))), (safe_lshift_func_uint8_t_u_s(g_894[3][3], (safe_mul_func_uint16_t_u_u(((l_1848 &= ((g_70 || (safe_rshift_func_int16_t_s_s(l_1831[4], 0))) != g_126)) == 0x6C), g_274[7])))))) >= g_1081[0]))) & g_1081[0]) <= 2);
                        g_375 = (((safe_lshift_func_int8_t_s_u((g_1149 != (safe_sub_func_uint32_t_u_u((safe_sub_func_int16_t_s_s((((l_1596 | (-1)) != (safe_rshift_func_int8_t_s_u(l_1833, (g_1857 &= 250U)))) | (safe_lshift_func_uint16_t_u_u((safe_mod_func_int16_t_s_s((l_1710 = ((((safe_mod_func_int32_t_s_s((safe_sub_func_uint16_t_u_u((65530U ^ l_1848), g_646[5])), 8U)) & l_1831[6]) > 0xE3C6) < 0xE44A)), 4)), g_643[2][2][2]))), g_1866)), g_147[1]))), 2)) ^ l_1801[0][0][0]) & 0x4AD0);
                    }
                    else
                    {
                        uint32_t l_1894[7] = {4294967295U, 4294967295U, 4294967295U, 4294967295U, 4294967295U, 4294967295U, 4294967295U};
                        int32_t l_1895[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_1895[i] = 7;
                        l_1868++;
                        g_375 = ((safe_mul_func_uint16_t_u_u((l_1895[3] &= (((((safe_mul_func_int8_t_s_s(0x5F, g_1082)) > ((~((l_1719 || g_1247) ^ (g_643[2][2][2] = (safe_rshift_func_uint8_t_u_u(((safe_mod_func_int16_t_s_s(((((safe_sub_func_uint16_t_u_u((g_1857--), ((g_865 = (safe_rshift_func_uint16_t_u_u(g_308, (safe_add_func_int8_t_s_s(((safe_add_func_int8_t_s_s((g_940 = (l_1598 & l_1719)), (safe_add_func_int32_t_s_s(g_1081[0], ((g_942[1][2] = ((safe_mul_func_int8_t_s_s((g_308 >= g_646[5]), g_613)) ^ g_1247)) && (-6)))))) & l_1564), 0))))) & 0x90))) && l_1894[6]) <= g_1084) > l_1596), g_911)) < 0xC3), l_1565[0]))))) || l_1894[2])) | g_147[5]) != g_1081[0]) || g_213)), 0x1997)) ^ 8);
                    }
                    l_1920 = ((safe_div_func_int8_t_s_s((((--g_646[l_7]) && ((((safe_mod_func_uint32_t_u_u(((safe_add_func_int32_t_s_s(((l_1904[0][6] = l_1800) && ((safe_rshift_func_uint16_t_u_s(g_317, 13)) == l_1907)), (l_1907 || (--l_1908)))) && ((l_1919 = ((((l_1585 ^= ((l_1800 = (l_1831[4] ^= g_375)) < g_352)) || (+((g_643[4][3][5] || ((safe_lshift_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(((((safe_mod_func_int32_t_s_s((l_1829 & g_176), g_2)) >= l_1643) & g_894[3][1]) ^ g_272), l_1829)), 3)) | g_553[1])) <= l_1695[1]))) < l_1651) && g_1918[1])) < g_147[0])), 1)) & g_70) | g_373) > (-2))) <= l_1597), (-8))) ^ l_1557);
                }
                else
                {
                    int16_t l_1928[5][2];
                    int32_t l_1980[6] = {0x62169CA6, 0xA1D457C3, 0x62169CA6, 0xA1D457C3, 0x62169CA6, 0xA1D457C3};
                    int32_t l_1981 = 5;
                    int i, j;
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 2; j++)
                            l_1928[i][j] = (-10);
                    }
                    l_1931 |= (safe_mul_func_int8_t_s_s(((l_1904[1][3] == (l_1719 < ((!(((l_1928[2][0] = ((+((l_1651 == l_1801[0][1][4]) > 0x86)) || (safe_mul_func_uint8_t_u_u(g_1918[1], l_1927[5][2][2])))) < (+(g_1857 = (safe_unary_minus_func_uint8_t_u((g_1323 = l_1651)))))) || ((g_147[4] & g_352) | l_7))) != 0x95849B15))) > 0xAE424188), 0xF8));
                    if (l_1904[0][6])
                    {
                        int32_t l_1962 = 1;
                        int32_t l_1994[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_1994[i] = 1;
                        l_1981 = (((safe_mod_func_int32_t_s_s((65532U > g_1081[0]), (safe_mod_func_int16_t_s_s((safe_unary_minus_func_uint8_t_u(((safe_rshift_func_int16_t_s_s((safe_rshift_func_uint8_t_u_u(((safe_rshift_func_uint8_t_u_s((safe_sub_func_uint16_t_u_u(((((((l_1980[3] = (g_375 |= ((safe_mul_func_uint16_t_u_u((g_1442[4][2]--), ((safe_unary_minus_func_int16_t_s((((((safe_sub_func_int16_t_s_s(((safe_div_func_uint32_t_u_u((l_1908 <= (safe_add_func_uint16_t_u_u(((g_646[3] = ((safe_mul_func_int8_t_s_s(((((safe_div_func_uint32_t_u_u((safe_add_func_int16_t_s_s(((++g_148) < (safe_rshift_func_int8_t_s_s((safe_mod_func_uint16_t_u_u((l_1627[1][1] && (g_1918[0] = l_1868)), (l_1710 || (safe_unary_minus_func_int16_t_s((safe_unary_minus_func_uint16_t_u((safe_mul_func_int16_t_s_s((safe_div_func_int16_t_s_s((((0x9027C1B9 > (safe_div_func_uint8_t_u_u(((0x8280878F != (((g_70 ^ l_1928[2][0]) ^ l_1962) ^ l_1565[0])) == 4294967295U), g_894[3][1]))) || l_1829) | l_1962), (-1))), g_143))))))))), l_1928[1][0]))), l_1565[0])), l_1710)) || 1U) < g_147[3]) & l_1977), g_1420)) <= l_1596)) & g_176), g_126))), l_1978)) & g_1979), g_738)) || g_942[1][2]) != g_1132) > (-6)) >= l_1908))) | g_869))) > g_1146))) > 0x17E7C9F5) && (-1)) != g_898) == (-4)) && g_308), 9)), 6)) | 250U), g_274[5])), 8)) & 0x2A))), g_643[4][2][5])))) >= g_1143[2][0][6]) & g_272);

{
                int8_t l_1529[5];
                uint8_t l_1571[10] = {7U, 0x23, 253U, 253U, 0x23, 7U, 0x23, 253U, 253U, 0x23};
                int i;
                for (i = 0; i < 5; i++)
                    l_1529[i] = 0x7A;
                for (l_2416 = 0; (l_2416 <= 8); l_2416 += 1)
                {
                    uint32_t l_1536[4] = {4294967289U, 0x0C505958, 4294967289U, 0x0C505958};
                    int i;
                    for (l_2299 = 6; (l_2299 >= 0); l_2299 -= 1)
                    {
                        int i, j, k;
                        l_1529[3] = 0xEE514F02;
                        g_266 |= 3;
                        g_1131 = (safe_div_func_int8_t_s_s((l_1565[0] ^= (g_643[(l_1908 + 1)][l_1908][l_2299] = ((safe_mod_func_int32_t_s_s((((l_1536[1] = (safe_lshift_func_int16_t_s_u(g_643[l_2299][l_1908][(l_1908 + 2)], 13))) < g_274[l_2299]) | ((((safe_sub_func_uint8_t_u_u((1 != ((g_646[(l_2299 + 2)] = g_126) != (((((safe_div_func_int32_t_s_s((safe_mul_func_int16_t_s_s(1, (((safe_lshift_func_int16_t_s_u((safe_rshift_func_int8_t_s_s(0xFF, 5)), 0)) | (safe_sub_func_int32_t_s_s((safe_add_func_int16_t_s_s((safe_add_func_uint8_t_u_u(255U, ((safe_lshift_func_int16_t_s_s((safe_sub_func_int8_t_s_s(g_1857, ((safe_rshift_func_uint8_t_u_s((l_1998--), (safe_mul_func_int8_t_s_s((0x6F & l_1998), 1U)))) & (-10)))), 0)) & g_1084))), g_894[4][1])), 1U))) > 0xF64ADCDF))), 0x366762FB)) == l_1707) && l_1529[3]) != g_1857) ^ 0x8C))), g_1084)) && l_2538) >= g_274[(l_2299 + 1)]) | l_2538)), 4294967295U)) > l_2538))), 0xCA));
                    }
                    for (g_70 = 0; (g_70 <= 0); g_70 += 1)
                    {
                        int i, j;
                        return g_894[(g_70 + 4)][(g_70 + 3)];
                    }
                }
                for (g_940 = 4; (g_940 >= 0); g_940 -= 1)
                {
                    int32_t l_1599 = 0;
                    int i, j, k;
                    l_1571[5] = ((~g_643[(l_1908 + 1)][l_1908][g_940]) || ((safe_lshift_func_int8_t_s_s(l_1707, 1)) ^ ((g_1857 | l_2129) | (l_2538 >= ((l_1867 >= ((g_1081[0] || (0x6FA8A676 == (1U & g_373))) > 4294967290U)) <= l_2538)))));
                    l_1599 = (((~l_2538) && (safe_mul_func_uint8_t_u_u((l_1707 &= (safe_sub_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((0x80 > (((safe_sub_func_int16_t_s_s(l_1565[0], (safe_mod_func_uint16_t_u_u((l_1565[0] > (safe_mul_func_int8_t_s_s(((l_1707 = 0x315E) ^ (safe_rshift_func_int8_t_s_s(l_1571[6], 2))), ((g_266 = (((safe_lshift_func_int8_t_s_s(((safe_rshift_func_int16_t_s_u((g_1979 ^= (safe_mul_func_uint16_t_u_u(l_2538, (l_1977 = (safe_rshift_func_uint8_t_u_u(255U, l_1529[3])))))), 2)) & g_1442[3][2]), 0)) == 7) >= l_1571[7])) != 0xBA93CEBE)))), l_1829)))) && g_147[0]) & 1U)), g_126)), l_2538))), 0xD6))) != 0x6F);
                    if (l_1829)
                        continue;
                }
            }

                    g_375 = (safe_mul_func_int16_t_s_s((g_176 > (l_1598 &= (safe_add_func_int8_t_s_s(l_1928[2][0], (((safe_div_func_uint32_t_u_u(l_1962, (safe_mul_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((0x2CF9 != (safe_add_func_int8_t_s_s((((l_1994[1] = 0x6248) != (safe_lshift_func_int8_t_s_s(g_646[4], (g_1997 && 4U)))) || ((0x1421 && 0x87E2) < l_1655)), g_1323))), 3)), l_1962)))) >= g_272) != l_1931))))), 0x3FE2));
                        l_1998--;
                        l_1994[1] = (safe_add_func_uint8_t_u_u((0xE4F21DB1 & (+l_1980[3])), (l_2028 |= (safe_add_func_int8_t_s_s((safe_div_func_int8_t_s_s(((safe_mul_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u(((safe_add_func_uint16_t_u_u(l_1980[1], ((safe_mul_func_int8_t_s_s(g_377, (safe_lshift_func_uint16_t_u_u(((safe_add_func_int16_t_s_s((((-1) | 1) != (g_1143[2][0][6] = ((safe_add_func_uint16_t_u_u((l_1707 == ((safe_sub_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(9, g_553[1])), 4)), 0xB20E)) & 0xE91E)), g_147[1])) >= l_1655))), g_1442[3][0])) >= g_268), g_1997)))) ^ l_1596))) && g_898), l_1710)), l_1980[3])) > 65535U), l_1981)), l_1627[2][3])))));
                    }
                    else
                    {
                        if (l_2028)
                            break;
                        g_1149 = (g_1084 != (g_643[2][2][2] = (safe_sub_func_int8_t_s_s(1, l_1928[2][0]))));
                        if (l_1928[2][0])
                            continue;
                        g_1149 = (safe_mod_func_uint8_t_u_u(0x3A, (l_1800 = g_377)));
                    }
                    l_1585 = ((safe_mod_func_int8_t_s_s(((l_1800 = l_7) | ((g_1918[1] = ((0 > (safe_mod_func_uint16_t_u_u(((l_1719 < (safe_div_func_int16_t_s_s((safe_lshift_func_int16_t_s_u(0x7DAF, 6)), (((safe_lshift_func_uint8_t_u_s((+(0x6938BFF6 < g_1150)), 6)) && 0x07) || ((4294967295U & (g_1419 = (safe_mod_func_int32_t_s_s((l_1598 = (g_1131 = 0x2D7FF6B0)), l_1980[3])))) && g_911))))) && g_894[2][3]), g_1323))) ^ l_1710)) <= g_213)), 0xB6)) > l_1695[0]);
                }
                for (g_266 = 4; (g_266 >= 0); g_266 -= 1)
                {
                    int32_t l_2069 = 0xC7083053;
                    int32_t l_2106 = 0x0CA01274;
                    int i, j;
                    for (g_1146 = 0; (g_1146 <= 4); g_1146 += 1)
                    {
                        int32_t l_2071 = 0xDDEB2143;
                        int i, j, k;
                        l_2071 &= ((0xE2 | g_1442[g_266][g_266]) >= ((g_375 &= (safe_add_func_int16_t_s_s(((((~(safe_rshift_func_int8_t_s_u((safe_mul_func_uint16_t_u_u(((g_643[(g_1146 + 1)][g_266][(g_266 + 1)] |= (safe_mul_func_int8_t_s_s((safe_add_func_uint8_t_u_u(g_1442[g_1146][(g_1146 + 1)], g_1323)), g_352))) && (safe_mod_func_uint8_t_u_u(l_1904[2][4], (g_865 = (safe_mul_func_uint8_t_u_u((~l_1598), (((safe_div_func_int8_t_s_s(((safe_mod_func_int32_t_s_s((safe_div_func_uint8_t_u_u(g_377, (~g_126))), 6)) || 0xBA1B), l_1867)) || g_1149) || l_2069))))))), g_1442[g_266][g_266])), 5))) && l_2070) ^ l_1598) < l_1597), g_894[3][1]))) & 0x47C55E04));
                    }
                    l_1598 = 0xBA58FDC6;
                    l_1710 ^= (g_375 = (0x3E54159B == g_70));
                    l_2106 = (safe_rshift_func_uint16_t_u_u((!(safe_mod_func_uint32_t_u_u((safe_lshift_func_int8_t_s_u((safe_mod_func_uint32_t_u_u((safe_add_func_int16_t_s_s(0, (g_1442[g_266][g_266]--))), (safe_mul_func_int8_t_s_s(l_1707, ((l_1565[0] = ((l_1565[0] != ((safe_mod_func_uint8_t_u_u(g_140, 0xAC)) == g_274[5])) >= (safe_mul_func_int16_t_s_s((safe_lshift_func_uint16_t_u_u(((((l_1800 = (safe_mul_func_int8_t_s_s(((g_1247 = ((safe_div_func_uint8_t_u_u((safe_mod_func_int8_t_s_s((g_944 <= ((safe_div_func_int8_t_s_s((l_1565[0] > ((safe_add_func_uint8_t_u_u((l_1598 |= (safe_mod_func_uint8_t_u_u((g_274[5] && 0x12), l_1564))), 0x92)) > l_1719)), l_2028)) < g_1857)), g_1979)), 0x23)) == g_1132)) | 7), l_1710))) >= 0x22B7) ^ g_317) == g_1526), 3)), l_2069)))) & l_1596))))), l_2105[3][0][2])), (-4)))), 15));
                }
                for (g_1146 = 0; (g_1146 <= 4); g_1146 += 1)
                {
                    const int8_t l_2122 = 0x80;
                    int32_t l_2148 = 0x607CEDF7;
                    int16_t l_2160[4] = {(-1), 9, (-1), 9};
                    int i;
                    if (g_1442[1][3])
                    {
                        int32_t l_2121 = 7;
                        uint16_t l_2134[10][2][4] = {{{0xB022, 0x853C, 0xE95A, 0x853C}, {0xB022, 0x853C, 0xE95A, 0x853C}}, {{0xB022, 0x853C, 0xE95A, 0x853C}, {0xB022, 0x853C, 0xE95A, 0x853C}}, {{0xB022, 0x853C, 0xE95A, 0x853C}, {0xB022, 0x853C, 0xE95A, 0x853C}}, {{0xB022, 0x853C, 0xE95A, 0x853C}, {0xB022, 0x853C, 0xE95A, 0x853C}}, {{0xB022, 0x853C, 0xE95A, 0x853C}, {0xB022, 0x853C, 0xE95A, 0x853C}}, {{0xB022, 0x853C, 0xE95A, 0x853C}, {0xB022, 0x853C, 0xE95A, 0x853C}}, {{0xB022, 0x853C, 0xE95A, 0x853C}, {0xB022, 0x853C, 0xE95A, 0x853C}}, {{0xB022, 0x853C, 0xE95A, 0x853C}, {0xB022, 0x853C, 0xE95A, 0x853C}}, {{0xB022, 0x853C, 0xE95A, 0x853C}, {0xB022, 0x853C, 0xE95A, 0x853C}}, {{0xB022, 0x853C, 0xE95A, 0x853C}, {0xB022, 0x853C, 0xE95A, 0x853C}}};
                        uint8_t l_2162[3];
                        int i, j, k;
                        for (i = 0; i < 3; i++)
                            l_2162[i] = 0U;
                        g_1918[0] = (safe_div_func_int16_t_s_s(((safe_lshift_func_int16_t_s_s(g_942[2][0], 9)) == l_1801[1][2][2]), ((safe_sub_func_uint16_t_u_u((((safe_sub_func_uint16_t_u_u((safe_unary_minus_func_int8_t_s((safe_div_func_int16_t_s_s(g_140, (safe_unary_minus_func_uint16_t_u((safe_lshift_func_int8_t_s_u(((g_643[g_1146][g_1146][(g_1146 + 1)] = g_613) <= (l_2121 ^ l_2122)), 6)))))))), (safe_mul_func_int16_t_s_s(((g_1150 = g_268) > (safe_mul_func_uint8_t_u_u((255U != (safe_add_func_int16_t_s_s(l_1564, l_1904[0][6]))), g_268))), l_2121)))) & l_1695[1]) && g_306), l_2129)) && l_1695[1])));
                        g_1131 &= (g_1323 ^ (safe_lshift_func_uint16_t_u_u(((safe_sub_func_int8_t_s_s(l_2134[2][1][2], (g_274[4] = (safe_rshift_func_int8_t_s_u((l_1596 & (safe_div_func_int16_t_s_s((safe_lshift_func_int16_t_s_u((g_643[2][0][1] & ((l_2148 |= ((safe_mul_func_int16_t_s_s((g_553[0] > ((safe_mul_func_uint16_t_u_u(((g_373 != ((l_1710 = (safe_sub_func_int32_t_s_s((~0x820CDD07), g_865))) == g_376)) && 0), l_1598)) < l_1904[3][2])), l_1598)) <= 0xD7)) < g_1081[0])), g_375)), l_1651))), g_317))))) >= l_2149), l_2028)));
                        g_1918[2] &= (((~g_266) || (-9)) != ((g_2 != (((((((safe_rshift_func_uint16_t_u_u((l_2148 = 0xEC83), (l_2161 = (((l_1978 & g_143) && ((~g_898) > (g_1442[2][1] && (safe_add_func_int32_t_s_s((safe_div_func_int8_t_s_s((l_2122 & 0xAD), l_2160[3])), g_1997))))) ^ g_1323)))) || 4294967288U) <= 0xC9) ^ 65535U) | l_2162[2]) > l_2162[1]) || 1U)) | g_865));
                    }
                    else
                    {
                        g_375 = ((safe_sub_func_int16_t_s_s(l_2165, l_2160[3])) < (g_264 < (g_317 >= ((g_1918[1] = (safe_mul_func_int8_t_s_s((((safe_rshift_func_uint16_t_u_s(0x230A, 8)) == ((g_268 && (!(g_1420 == (safe_rshift_func_int16_t_s_u((-10), 5))))) == 0)) && 1), g_2))) & g_1997))));
                        g_1419 ^= (safe_add_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s((g_1442[4][2] = l_1927[4][3][4]), g_1081[0])), ((!0xE1D05FAB) <= (safe_lshift_func_uint8_t_u_u(254U, 7)))));
                        g_1131 = 0x1F0AB61C;
                    }
                    g_1149 |= ((--g_1979) >= g_1420);
                }
            }
        }
        return l_1867;
    }
    else
    {
        uint32_t l_2190[5];
        int32_t l_2191 = 0x91226ACF;
        int32_t l_2200 = 0xEA503FD9;
        int32_t l_2201 = (-5);
        int8_t l_2251 = 0xDD;
        int8_t l_2295 = 0x45;
        int32_t l_2296[9] = {(-8), (-8), (-8), (-8), (-8), (-8), (-8), (-8), (-8)};
        int8_t l_2297[2];
        int16_t l_2323 = 0x6C1B;
        const int32_t l_2360 = 0xFABE3E91;
        int32_t l_2413[1][2][9] = {{{0x9917DB62, (-1), 0x9917DB62, (-1), 0x9917DB62, (-1), 0x9917DB62, (-1), 0x9917DB62}, {0x9917DB62, (-1), 0x9917DB62, (-1), 0x9917DB62, (-1), 0x9917DB62, (-1), 0x9917DB62}}};
        uint32_t l_2417 = 0xC08495F1;
        uint32_t l_2418 = 0xAF131353;
        uint16_t l_2521 = 0x07E5;
        int i, j, k;
        for (i = 0; i < 5; i++)
            l_2190[i] = 0xD5069842;
        for (i = 0; i < 2; i++)
            l_2297[i] = 0;
        if ((l_1598 = (((safe_mul_func_int8_t_s_s(((((safe_rshift_func_int8_t_s_u((g_940 = (-6)), (l_1597 < (g_866 ^ 0x6E1D)))) & ((l_2190[2] = (safe_lshift_func_int8_t_s_s(g_865, g_274[1]))) > (l_2191 = g_147[1]))) ^ (g_376 = (g_306 = (safe_mod_func_uint32_t_u_u(l_1597, (safe_add_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s(((safe_add_func_int16_t_s_s(((0x41A2 < l_2200) && g_1082), l_2200)) || 0xAE), 12)), g_148))))))) > l_2200), 0x6F)) >= l_2201) && g_268)))
        {
            uint32_t l_2219 = 0x41C3F0F8;
            int32_t l_2223 = 1;
            uint32_t l_2252[1];
            int i;
            for (i = 0; i < 1; i++)
                l_2252[i] = 3U;
            if (((l_2191 != l_1598) >= (l_2208 = (g_898 = (~(g_2203 <= ((safe_sub_func_int16_t_s_s(0x4663, (g_352 & (safe_div_func_uint8_t_u_u((g_171 = l_1651), l_2190[0]))))) && g_866)))))))
            {
                const uint8_t l_2224 = 251U;
                int32_t l_2225 = 0xD214110C;
                g_1918[2] &= (((g_1442[4][2] = 0U) == ((g_352 || ((safe_mod_func_int8_t_s_s((safe_mul_func_int16_t_s_s((((g_1420 >= (safe_lshift_func_int8_t_s_s(0x73, 0))) <= ((((g_1979 = (l_2219 ^ (((l_2225 = (+(safe_mul_func_int8_t_s_s((l_2223 = 0x61), (0x28CFC9D1 == ((l_2224 < l_2219) && 1)))))) != l_2219) == 1))) > l_1868) > 0x63712B73) == g_613)) | l_2191), g_643[2][2][2])), g_1420)) == 7U)) < g_898)) != l_2201);
            }
            else
            {
                uint32_t l_2226[2];
                int i;
                for (i = 0; i < 2; i++)
                    l_2226[i] = 0x76189873;
                l_1598 = (l_2226[1] &= (0U & 0x42EEECBB));
            }
            l_2223 = ((((safe_add_func_uint32_t_u_u((safe_div_func_int8_t_s_s((safe_mod_func_uint8_t_u_u((l_2252[0] ^= (((safe_add_func_int8_t_s_s((safe_mod_func_int8_t_s_s(((((safe_mod_func_uint32_t_u_u((l_2208 |= l_2219), (g_350 &= (safe_mod_func_int8_t_s_s((safe_div_func_uint8_t_u_u(((((g_317 < (safe_add_func_int16_t_s_s(g_643[4][1][2], ((((g_1131 <= ((8 != 0) != l_2219)) ^ (safe_sub_func_int32_t_s_s((g_375 |= ((safe_sub_func_uint32_t_u_u(((g_213 = l_2201) ^ (safe_lshift_func_int16_t_s_s(((((g_274[7] = (l_2191 = (l_1596 & g_940))) > 0x61) | 0xDEDEE7EE) >= l_2223), 6))), 0xD38A0A27)) | g_643[3][3][6])), (-5)))) && g_1442[4][2]) > 9)))) != g_1132) > l_2219) ^ g_143), l_2251)), l_1597))))) || (-8)) > g_866) & g_2203), 0x77)), 255U)) != l_1598) ^ g_1130)), g_613)), g_376)), 0U)) ^ g_70) ^ g_1132) != l_2219);
        }
        else
        {
            int32_t l_2253[10][3][7] = {{{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}};
            int16_t l_2254 = 8;
            int32_t l_2294[6][4][4] = {{{0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}}, {{0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}}, {{0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}}, {{0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}}, {{0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}}, {{0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}}};
            uint8_t l_2301 = 0xA5;
            int i, j, k;
            g_375 &= g_1979;
            l_2255--;
            g_1149 = ((((safe_lshift_func_uint8_t_u_u((0x7A5CE437 | (g_1132 = (safe_add_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(((safe_mul_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(g_1866, 4)), (g_1918[2] & (safe_sub_func_int32_t_s_s(((g_148 | (safe_unary_minus_func_int8_t_s((safe_add_func_uint32_t_u_u((safe_add_func_int16_t_s_s((((+(safe_lshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s(((((safe_sub_func_uint8_t_u_u((((((safe_sub_func_uint16_t_u_u(0x3992, (g_2 >= (safe_mod_func_int32_t_s_s(0x54FF8184, (safe_rshift_func_int16_t_s_s((((++g_83) == ((l_2208 |= ((safe_unary_minus_func_uint32_t_u((safe_add_func_int32_t_s_s((~(l_2294[4][3][0] = (l_1597 && (g_306 > l_1651)))), g_866)))) > l_2253[0][0][3])) ^ g_1979)) & l_1931), 1))))))) || g_147[3]) ^ 0xC168) | l_2254) | 4294967295U), l_7)) != g_644) & l_2191) | (-1)), l_2161)), g_147[0]))) <= 0x6DD13B86) ^ g_266), 0xD7F6)), l_2253[4][2][0]))))) < 4294967288U), 0xF0F5DEB2))))) > g_869), 0xEDFEABAE)), g_140)))), g_264)) != l_2254) || 0x9F969EA4) == g_140);
            l_2301++;
        }
        if ((g_375 = l_1868))
        {
            uint8_t l_2304 = 0x2D;
            int32_t l_2312[8];
            uint8_t l_2345[1][9][10] = {{{1U, 255U, 0x1B, 0U, 0xCF, 5U, 0U, 0x2A, 0U, 5U}, {1U, 255U, 0x1B, 0U, 0xCF, 5U, 0U, 0x2A, 0U, 5U}, {1U, 255U, 0x1B, 0U, 0xCF, 5U, 0U, 0x2A, 0U, 5U}, {1U, 255U, 0x1B, 0U, 0xCF, 5U, 0U, 0x2A, 0U, 5U}, {1U, 255U, 0x1B, 0U, 0xCF, 5U, 0U, 0x2A, 0U, 5U}, {1U, 255U, 0x1B, 0U, 0xCF, 5U, 0U, 0x2A, 0U, 5U}, {1U, 255U, 0x1B, 0U, 0xCF, 5U, 0U, 0x2A, 0U, 5U}, {1U, 255U, 0x1B, 0U, 0xCF, 5U, 0U, 0x2A, 0U, 5U}, {1U, 255U, 0x1B, 0U, 0xCF, 5U, 0U, 0x2A, 0U, 5U}}};
            int32_t l_2346 = (-10);
            int32_t l_2348 = 0x8B4BEDE8;
            uint16_t l_2414 = 0x7EE9;
            int8_t l_2537 = 0x75;
            int i, j, k;
            for (i = 0; i < 8; i++)
                l_2312[i] = 0x31E35E2E;

for (g_272 = 0; g_272 < 3; g_272++)
        {
            transparent_crc(g_942[l_1598][g_272], "g_942[l_1598][g_272]", l_2747);
            if (l_2747) printf("index = [%d][%d]\n", l_1598, g_272);

        };


                    ++l_2304;
            if (((safe_add_func_int32_t_s_s(g_643[5][2][2], (l_2300 &= ((g_1442[4][3] = (!g_264)) | (g_1081[0] & (((4 >= ((l_2312[3] ^= 0x06) && (g_2203 = ((safe_div_func_int16_t_s_s(((g_1130 || ((safe_div_func_uint32_t_u_u((((((l_2317 ^ (safe_rshift_func_uint16_t_u_u(((!(g_1997 == ((safe_mod_func_uint16_t_u_u(((l_2323 = 0xCD6DD173) > l_2295), g_643[2][2][2])) & 0xDDF68E3F))) == g_1150), l_2317))) && l_2304) ^ g_272) != 0xF543BF74) >= 65535U), g_375)) & l_2304)) ^ 0xCD82), g_942[1][0])) & 0)))) & l_2298) || g_171)))))) != (-3)))
            {
                uint32_t l_2335[9][8][3] = {{{0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}}, {{0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}}, {{0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}}, {{0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}}, {{0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}}, {{0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}}, {{0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}}, {{0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}}, {{0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}, {0x15A7956C, 4294967291U, 8U}}};
                int16_t l_2347 = 0x1F10;
                int32_t l_2389 = 0xD584B463;
                uint32_t l_2415 = 0U;
                int32_t l_2459[8][1] = {{9}, {9}, {9}, {9}, {9}, {9}, {9}, {9}};
                uint32_t l_2460[5][1][2] = {{{0U, 0U}}, {{0U, 0U}}, {{0U, 0U}}, {{0U, 0U}}, {{0U, 0U}}};
                int i, j, k;
                if (((l_2295 >= ((+(l_2312[1] = (safe_add_func_uint16_t_u_u(g_352, ((safe_lshift_func_int8_t_s_s((0x0C69 || (l_2348 |= (((safe_mod_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((l_2299 = (safe_div_func_uint16_t_u_u(0x8867, l_2335[5][3][2]))), (0xA9FA2498 || (safe_sub_func_int16_t_s_s((safe_lshift_func_uint8_t_u_u((~((l_2312[2] ^ g_1084) ^ (safe_sub_func_uint32_t_u_u((l_2346 = (safe_sub_func_int8_t_s_s((l_2345[0][5][6] < 4294967295U), g_268))), l_1597)))), 5)), 0x88AA))))), g_894[3][0])) && g_1146) >= l_2347))), 7)) != l_2297[1]))))) & g_83)) ^ g_911))
                {
                    uint32_t l_2349 = 0U;
                    ++l_2349;
                    if ((safe_sub_func_uint16_t_u_u((0x0C49EAF2 && (((safe_mod_func_int32_t_s_s((((248U == 4U) >= 251U) & (((0 ^ (l_1868 <= l_2348)) || l_2349) == (safe_div_func_uint8_t_u_u((g_944 = 0U), 0x83)))), l_1598)) > 4294967286U) | 0x92)), g_375)))
                    {
                        g_1918[1] = (safe_mod_func_uint8_t_u_u((l_2360 <= ((g_1149 = g_306) & (((~(safe_mul_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((g_1857 &= ((safe_mul_func_int16_t_s_s((safe_mul_func_int8_t_s_s((!0xB8), ((g_376 = l_2345[0][6][5]) >= g_898))), l_2296[5])) < g_911)) == (!(safe_lshift_func_int16_t_s_s(l_2312[3], (g_176 == l_2312[3]))))), g_898)), g_265))) ^ 0x23) != g_869))), g_2203));
                        g_1918[1] ^= g_265;

l_2349 += 1;


                    l_2312[0] |= (-1);
                    }
                    else
                    {
                        l_2389 = ((l_1868 == ((0xA3 ^ (g_738 >= ((+0xEAF956AC) >= (safe_mul_func_int16_t_s_s(g_613, (safe_add_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u((safe_mod_func_uint16_t_u_u((g_1247--), (safe_mod_func_uint32_t_u_u(l_2191, g_553[2])))), (safe_div_func_uint32_t_u_u(g_1442[2][5], (g_1918[1] = (-1)))))), 1U))))))) | g_143)) ^ g_911);
                    }
                }
                else
                {
                    int32_t l_2399 = 0;
                    int32_t l_2458[5];
                    int i;
                    for (i = 0; i < 5; i++)
                        l_2458[i] = 0x14BCD158;
                    if ((safe_sub_func_int32_t_s_s(0xDE82BF71, ((safe_rshift_func_int8_t_s_u(((g_738 = l_1651) <= ((l_2300 | (7U | ((((safe_lshift_func_int8_t_s_s((((safe_unary_minus_func_uint16_t_u(g_2203)) & l_2399) & ((safe_mul_func_int16_t_s_s(0xAD2D, (g_376 = (~((safe_mod_func_uint16_t_u_u((safe_div_func_int16_t_s_s((safe_div_func_uint16_t_u_u((safe_add_func_int32_t_s_s(g_176, ((((((safe_add_func_uint32_t_u_u(g_274[6], l_2413[0][1][8])) | l_2414) == 7) || l_2347) < l_2335[5][3][2]) | 1U))), l_2415)), l_2399)), 3)) || l_2312[6]))))) > 0x76E64A38)), g_1146)) | 7) ^ l_2416) ^ l_2417))) && 4)), 7)) == g_644))))
                    {
                        ++l_2418;
                    }
                    else
                    {
                        int32_t l_2457[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                        int i;
                        g_1149 = ((safe_mod_func_uint8_t_u_u(g_944, g_317)) | ((safe_mul_func_uint16_t_u_u(g_1130, ((255U > (safe_div_func_int32_t_s_s(g_894[3][1], (g_1131 & (g_1247 = l_2346))))) && ((((((safe_add_func_uint16_t_u_u((!(safe_lshift_func_uint16_t_u_u((((l_2208 >= (0x410292B0 < l_2297[1])) == g_553[1]) < g_373), 9))), l_2335[5][3][2])) & 0x49) > g_1979) ^ 0xDF) | g_1918[2]) >= g_942[1][0])))) == 0xD8));
                        l_2458[1] = ((safe_sub_func_int16_t_s_s((l_2413[0][1][8] = (safe_lshift_func_int8_t_s_s((safe_unary_minus_func_int32_t_s((safe_sub_func_int32_t_s_s((4 >= 1U), ((safe_unary_minus_func_uint32_t_u((safe_add_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(((safe_unary_minus_func_uint8_t_u((safe_add_func_uint16_t_u_u((g_894[3][1] ^ (l_2399 = (((safe_rshift_func_int8_t_s_s((safe_add_func_uint8_t_u_u(g_1132, (safe_sub_func_int32_t_s_s((-1), (0x7A8B != (safe_rshift_func_uint16_t_u_s(((safe_mod_func_uint32_t_u_u(0xF5E12D55, 0x35A4AFCF)) || 1U), g_942[1][0]))))))), 3)) && g_1143[4][0][7]) > l_2415))), g_1084)))) == l_2335[5][0][0]), l_2335[5][3][2])), g_646[5])))) && l_2399))))), l_2389))), l_2457[3])) < 0x65DD);
                    }
                }
                l_2460[2][0][0]--;
            }
            else
            {
                int16_t l_2468 = 0x24E1;
                uint8_t l_2490[9][6][4] = {{{0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}}, {{0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}}, {{0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}}, {{0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}}, {{0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}}, {{0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}}, {{0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}}, {{0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}}, {{0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}, {0xA3, 0x91, 1U, 0x6C}}};
                int i, j, k;
                for (g_738 = 0; (g_738 <= 4); g_738 += 1)
                {
                    int32_t l_2465 = 0xAFCAF454;
                    int i;
                    g_2 = (0xA9E06222 >= 0xD477E43A);
                    l_2413[0][1][8] |= l_2190[g_738];
                    l_2413[0][1][2] ^= l_2190[g_738];
                    l_2491 ^= (9 == (safe_lshift_func_int16_t_s_u((((l_2465 = 0xC61A) & (safe_lshift_func_uint8_t_u_u(l_2468, (safe_lshift_func_int16_t_s_s(((safe_lshift_func_uint8_t_u_u(g_1143[3][0][7], 1)) || (safe_sub_func_uint32_t_u_u((safe_mul_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_s((safe_add_func_int16_t_s_s(l_2161, (~(safe_div_func_uint16_t_u_u(g_375, (((0xC8 == ((!(safe_rshift_func_int8_t_s_s(g_176, 6))) >= (safe_sub_func_int8_t_s_s((safe_unary_minus_func_int8_t_s((l_2414 | g_1918[1]))), l_2468)))) && l_1597) ^ l_2490[6][0][2])))))), 8)) == l_2299), g_265)), l_2190[g_738]))), 2))))) == g_376), l_1829)));
                    for (l_1596 = 0; (l_1596 <= 4); l_1596 += 1)
                    {
                        g_2 = g_176;
                    }
                }
                g_1149 = g_148;
                l_2346 = ((((0xD99B | (safe_mul_func_int16_t_s_s((safe_lshift_func_uint8_t_u_s(g_352, 5)), (l_2208 ^= (((safe_mul_func_int8_t_s_s((l_2413[0][1][8] ^= (((g_1918[1] = ((safe_div_func_int32_t_s_s(((safe_div_func_uint8_t_u_u(((safe_mul_func_uint16_t_u_u(g_83, ((safe_mod_func_uint32_t_u_u(((g_1150 = 0x81) > ((safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((l_2521 = (safe_mul_func_uint8_t_u_u(((l_2312[3] = ((safe_mul_func_int16_t_s_s(1, (g_1442[4][2] = l_2200))) <= (~(l_2296[0] &= ((safe_div_func_uint8_t_u_u(g_306, l_2255)) >= ((safe_add_func_uint8_t_u_u(0x43, 0)) <= 0x771BA2D6)))))) | l_2490[3][5][0]), 0x65))), l_1596)), 0)) || g_126)), g_643[0][1][4])) < l_7))) == l_2201), g_148)) >= g_1419), l_2200)) >= 65529U)) != (-1)) != l_1598)), g_1997)) > g_2203) ^ 0xF04C5F1F))))) || g_377) || g_352) != l_2200);
                l_2200 = (g_266 < (safe_sub_func_uint16_t_u_u((((safe_div_func_int8_t_s_s((l_2208 |= 1), (safe_add_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u((l_2346 &= (g_738 = ((l_2537 = (safe_sub_func_uint8_t_u_u(0xCC, (safe_rshift_func_uint8_t_u_s((safe_mul_func_int8_t_s_s((g_264 <= (((0U <= l_2536) || l_2490[6][0][2]) > l_2416)), g_1997)), l_2312[3]))))) < g_2))), l_2345[0][5][6])), l_2538)))) || g_646[0]) | l_1597), g_171)));
            }
            l_2491 = g_1132;
            g_1131 = (safe_mul_func_uint16_t_u_u((((l_2346 = 0x29) <= (safe_add_func_uint16_t_u_u((safe_lshift_func_uint16_t_u_u((l_2208 = (!((0xA72A == l_2546) >= (0 != g_143)))), g_944)), 1U))) && ((safe_add_func_int8_t_s_s(g_1247, 0x59)) & g_1866)), g_126));
        }
        else
        {
            uint8_t l_2551 = 7U;
            int32_t l_2583 = 0x822C592E;
            int32_t l_2668 = 0x94BEEB5E;
            if (((safe_add_func_uint8_t_u_u((--l_2551), (((safe_sub_func_int32_t_s_s((safe_unary_minus_func_uint32_t_u((g_644 >= ((safe_sub_func_int32_t_s_s(l_2251, ((safe_sub_func_int8_t_s_s((safe_rshift_func_int8_t_s_s((((-1) == (safe_mod_func_uint32_t_u_u((safe_mul_func_int16_t_s_s(((l_2208 = ((safe_mod_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(65530U, (safe_mod_func_int8_t_s_s((safe_mul_func_int8_t_s_s((safe_sub_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_s((g_352 = (((safe_sub_func_uint32_t_u_u((safe_add_func_int8_t_s_s((g_1526 = g_553[0]), (l_2583 == g_83))), (safe_lshift_func_uint16_t_u_s((+(safe_mul_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((~(-3)), 9)), ((((((-3) & 1) ^ 0U) & 0xA8D4B01C) < 0) & l_2251)))), g_911)))) & 0x3E01) != (-1))), 11)) != 0x4F), 65528U)), g_1132)), g_148)))), 0xAF)) && 0x50)) && l_2296[2]), l_2538)), l_2583))) != 0x780F), g_1442[4][2])), g_376)) | l_2323))) || l_2592)))), 0xEDBE1912)) || 0x63B7D736) >= 0xC0))) <= g_274[5]))
            {
                ++g_2593[9][6][0];
            }
            else
            {
                uint32_t l_2602 = 0x5732216C;
                int32_t l_2639 = 0x89D404B5;
                uint32_t l_2660 = 0x301C9C1C;
                uint32_t l_2661 = 5U;
                int32_t l_2676 = (-1);
                if (((safe_div_func_int32_t_s_s(l_2538, l_2551)) && (safe_mul_func_uint16_t_u_u(l_1868, (safe_div_func_int8_t_s_s((l_2602 || l_2551), g_1442[1][1]))))))
                {
                    return g_1143[2][0][6];
                }
                else
                {
                    uint16_t l_2626 = 8U;
                    uint16_t l_2637 = 0xF3EC;
                    int8_t l_2675[7] = {(-1), 0x33, (-1), 0x33, (-1), 0x33, (-1)};
                    int i;
                    l_2583 = (l_2200 = 7);
                    g_2627[0][1] |= (safe_rshift_func_uint8_t_u_s((6 & g_911), (safe_add_func_int32_t_s_s((g_1131 ^= (safe_sub_func_int32_t_s_s((0x0B && (~(((-6) == (g_1918[1] = (safe_sub_func_int16_t_s_s((g_376 ^= (safe_add_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((--g_148), 7U)), (safe_rshift_func_uint8_t_u_u(g_2, 4))))), g_1442[4][2])))) & (safe_sub_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(((g_375 <= (g_1419 = (safe_rshift_func_uint16_t_u_s(0U, l_2626)))) == l_2602), l_1829)), l_1598))))), g_1149))), l_2602))));
                    for (g_1420 = (-29); (g_1420 < 45); g_1420 = safe_add_func_int32_t_s_s(g_1420, 2))
                    {
                        int16_t l_2636 = 0xCD15;
                        int32_t l_2638 = 0x9908A36F;
                        uint16_t l_2662 = 0x7EC3;
                        uint32_t l_2663 = 4294967295U;
                        l_2639 = (safe_rshift_func_int16_t_s_u(3, (safe_lshift_func_int8_t_s_u((safe_mul_func_uint16_t_u_u(((l_2636 = g_643[2][2][2]) | l_2637), (g_644 = (((l_2583 &= l_2638) > g_268) & g_148)))), 7))));
                        g_375 |= (safe_div_func_int16_t_s_s(((g_942[1][1] = ((g_1131 >= ((((g_940 ^ ((safe_sub_func_int32_t_s_s((safe_mod_func_int8_t_s_s((2 | (((safe_mul_func_uint8_t_u_u(l_2626, (g_2593[9][6][0] != (l_2626 <= l_2637)))) <= g_738) != (((safe_rshift_func_uint16_t_u_u(l_2639, l_2602)) < l_2551) == 0))), l_2323)), l_2637)) | 0x2D4F)) != l_2546) == l_2636) && 0x4AFEA392)) || g_553[1])) ^ g_126), l_2637));
                        l_2296[8] &= ((((g_317 = ((!((l_2626 != (+(((safe_sub_func_uint8_t_u_u(((-5) && g_2627[0][1]), (safe_div_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u((((g_1918[0] == (((safe_sub_func_uint16_t_u_u((l_1868 >= 0x7AEC), ((l_2660 |= (-8)) || (((((l_2661 < 0x0E) || 0x6803DC03) && 0xAD689F1F) >= l_2662) <= g_140)))) || l_2663) > l_2360)) >= g_1526) > g_1146), 1)), g_2627[0][0])))) < l_2208) ^ 65528U))) ^ g_1130)) == g_646[4])) != g_1130) || g_352) == l_1596);
                    }
                    l_2676 |= ((6U < 0x7B) <= ((l_2639 = l_2626) <= ((safe_rshift_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(((l_2675[6] ^= (l_2668 & (5 > ((g_213 != (0x4EFE || (safe_lshift_func_uint16_t_u_u(((l_2626 & (safe_div_func_int32_t_s_s(((safe_sub_func_uint8_t_u_u(1U, 0xFC)) || 0xDF), l_2583))) != 0x33), l_2602)))) != l_2637)))) < g_274[5]), l_2592)), l_2626)) & g_265)));
                }
            }
        }
        for (g_1084 = 23; (g_1084 > 10); g_1084 = safe_sub_func_uint32_t_u_u(g_1084, 7))
        {
            uint8_t l_2679 = 1U;
            if (l_2679)
                break;
            if (l_1596)
                continue;
            if (l_1597)
                {
if ((g_1419 = (((safe_mul_func_int8_t_s_s(((((safe_rshift_func_int8_t_s_u((g_1526 = (-6)), (l_2491 < (g_1146 ^ 0x6E1D)))) & ((l_2190[2] = (safe_lshift_func_int8_t_s_s(g_1082, g_274[1]))) > (k = g_147[1]))) ^ (l_2592 = (g_911 = (safe_mod_func_uint32_t_u_u(l_2491, (safe_add_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s(((safe_add_func_int16_t_s_s(((0x41A2 < i) && g_265), i)) || 0xAE), 12)), g_148))))))) > i), 0x6F)) >= g_2) && g_1084)))
        {
            uint32_t l_2219 = 0x41C3F0F8;
            int32_t l_2223 = 1;
            uint32_t l_2252[1];
            int i;
            for (i = 0; i < 1; i++)
                l_2252[i] = 3U;
            if (((k != g_1419) >= (g_2 = (g_869 = (~(g_1526 <= ((safe_sub_func_int16_t_s_s(0x4663, (g_352 & (safe_div_func_uint8_t_u_u((g_148 = g_866), l_2190[0]))))) && g_1146)))))))
            {
                const uint8_t l_2224 = 251U;
                int32_t l_2225 = 0xD214110C;
                g_1918[2] &= (((g_1442[4][2] = 0U) == ((g_352 || ((safe_mod_func_int8_t_s_s((safe_mul_func_int16_t_s_s((((l_2317 >= (safe_lshift_func_int8_t_s_s(0x73, 0))) <= ((((g_1247 = (l_2219 ^ (((l_2225 = (+(safe_mul_func_int8_t_s_s((l_2223 = 0x61), (0x28CFC9D1 == ((l_2224 < l_2219) && 1)))))) != l_2219) == 1))) > g_1247) > 0x63712B73) == g_944)) | k), g_643[2][2][2])), l_2317)) == 7U)) < g_869)) != g_2);
            }
            else
            {
                uint32_t l_2226[2];
                int i;
                for (i = 0; i < 2; i++)
                    l_2226[i] = 0x76189873;
                g_1419 = (l_2226[1] &= (0U & 0x42EEECBB));
            }
            l_2223 = ((((safe_add_func_uint32_t_u_u((safe_div_func_int8_t_s_s((safe_mod_func_uint8_t_u_u((l_2252[0] ^= (((safe_add_func_int8_t_s_s((safe_mod_func_int8_t_s_s(((((safe_mod_func_uint32_t_u_u((g_2 |= l_2219), (g_143 &= (safe_mod_func_int8_t_s_s((safe_div_func_uint8_t_u_u(((((g_1526 < (safe_add_func_int16_t_s_s(g_643[4][1][2], ((((j <= ((8 != 0) != l_2219)) ^ (safe_sub_func_int32_t_s_s((g_2 |= ((safe_sub_func_uint32_t_u_u(((g_352 = g_2) ^ (safe_lshift_func_int16_t_s_s(((((g_274[7] = (k = (g_1857 & g_1526))) > 0x61) | 0xDEDEE7EE) >= l_2223), 6))), 0xD38A0A27)) | g_643[3][3][6])), (-5)))) && g_1442[4][2]) > 9)))) != g_377) > l_2219) ^ l_2538), g_1526)), l_2491))))) || (-8)) > g_1146) & g_1526), 0x77)), 255U)) != g_1419) ^ g_83)), g_944)), l_2592)), 0U)) ^ l_2323) ^ g_377) != l_2219);
        }
        else
        {
            int32_t l_2253[10][3][7] = {{{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}, {{(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}, {(-1), 0xBB44033E, 0x8234FD10, 0x8E1DEAB4, (-1), 0x6001BEB3, 0}}};
            int16_t l_2254 = 8;
            int32_t l_2294[6][4][4] = {{{0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}}, {{0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}}, {{0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}}, {{0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}}, {{0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}}, {{0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}, {0x86749E1F, 0x306D1F92, (-2), (-6)}}};
            uint8_t l_2301 = 0xA5;
            int i, j, k;
            g_2 &= g_1247;
            l_2255--;
            g_1131 = ((((safe_lshift_func_uint8_t_u_u((0x7A5CE437 | (g_377 = (safe_add_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u(((safe_mul_func_int8_t_s_s((safe_rshift_func_int16_t_s_s(g_176, 4)), (g_1918[2] & (safe_sub_func_int32_t_s_s(((g_148 | (safe_unary_minus_func_int8_t_s((safe_add_func_uint32_t_u_u((safe_add_func_int16_t_s_s((((+(safe_lshift_func_int8_t_s_u((safe_lshift_func_uint8_t_u_s(((((safe_sub_func_uint8_t_u_u((((((safe_sub_func_uint16_t_u_u(0x3992, (g_1131 >= (safe_mod_func_int32_t_s_s(0x54FF8184, (safe_rshift_func_int16_t_s_s((((++g_83) == ((g_2 |= ((safe_unary_minus_func_uint32_t_u((safe_add_func_int32_t_s_s((~(l_2294[4][3][0] = (l_2491 && (g_911 > g_866)))), g_1146)))) > l_2253[0][0][3])) ^ g_1247)) & g_865), 1))))))) || g_147[3]) ^ 0xC168) | l_2254) | 4294967295U), l_2538)) != g_911) & k) | (-1)), g_1150)), g_147[0]))) <= 0x6DD13B86) ^ g_308), 0xD7F6)), l_2253[4][2][0]))))) < 4294967288U), 0xF0F5DEB2))))) > g_1866), 0xEDFEABAE)), g_1419)))), g_1146)) != l_2254) || 0x9F969EA4) == g_1419);
            l_2301++;
        };


                    continue;}
            l_1598 = (l_2413[0][1][8] = (safe_mul_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_u(g_1442[4][2], g_865)) <= (((7U <= (g_2593[9][6][0] < (((g_176 ^ 0) >= (((((g_274[5] = (safe_rshift_func_int8_t_s_s(((safe_add_func_uint16_t_u_u((l_1596 <= (safe_add_func_int8_t_s_s(((g_1143[3][0][6] = l_2679) & ((((0 >= 0U) ^ l_2679) | g_865) > g_553[1])), g_1149))), g_898)) >= 0xE0), 4))) ^ g_1866) < g_213) && 3U) < g_1918[1])) == l_2546))) | (-3)) > g_643[2][1][6])), l_2679)));
        }
    }
    for (g_264 = (-17); (g_264 >= 26); g_264 = safe_add_func_int32_t_s_s(g_264, 5))
    {
        uint8_t l_2694[5][10] = {{255U, 0x61, 255U, 249U, 249U, 255U, 0x61, 255U, 255U, 255U}, {255U, 0x61, 255U, 249U, 249U, 255U, 0x61, 255U, 255U, 255U}, {255U, 0x61, 255U, 249U, 249U, 255U, 0x61, 255U, 255U, 255U}, {255U, 0x61, 255U, 249U, 249U, 255U, 0x61, 255U, 255U, 255U}, {255U, 0x61, 255U, 249U, 249U, 255U, 0x61, 255U, 255U, 255U}};
        int32_t l_2741 = 0;
        uint32_t l_2742 = 2U;
        int32_t l_2746 = 0x07E7814C;
        uint32_t l_2749[4][7] = {{0U, 0xA28CB57A, 0xEFF88C95, 0xCAF47842, 0xB2E3088D, 0xCAF47842, 0xEFF88C95}, {0U, 0xA28CB57A, 0xEFF88C95, 0xCAF47842, 0xB2E3088D, 0xCAF47842, 0xEFF88C95}, {0U, 0xA28CB57A, 0xEFF88C95, 0xCAF47842, 0xB2E3088D, 0xCAF47842, 0xEFF88C95}, {0U, 0xA28CB57A, 0xEFF88C95, 0xCAF47842, 0xB2E3088D, 0xCAF47842, 0xEFF88C95}};
        int i, j;
        l_2694[2][5] = (-4);
        l_2695--;
        if (((g_1131 ^= (safe_mul_func_uint16_t_u_u((safe_rshift_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((safe_lshift_func_int16_t_s_u((safe_mul_func_uint16_t_u_u(((safe_mod_func_int32_t_s_s((safe_add_func_int32_t_s_s(l_2712[0], (((0x69 > (g_942[2][0] = l_2694[2][5])) & (safe_lshift_func_int16_t_s_u((safe_div_func_int8_t_s_s((l_1598 = ((safe_lshift_func_uint16_t_u_u((((safe_add_func_uint16_t_u_u(0xB52E, (safe_div_func_int8_t_s_s((safe_sub_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(((g_1419 |= ((g_866 ^ ((safe_mul_func_int16_t_s_s((-7), (safe_mul_func_uint16_t_u_u((safe_mul_func_int16_t_s_s((+((safe_sub_func_int32_t_s_s(g_898, g_738)) < ((((g_350 = (safe_rshift_func_int8_t_s_s(((safe_add_func_uint32_t_u_u(((((g_865 >= g_1526) || l_2694[2][5]) > g_1857) != g_1146), g_646[5])) >= g_1526), g_1247))) < g_375) >= g_264) > g_1918[1]))), l_2694[2][5])), g_1132)))) == l_2694[0][0])) != 0x73FD)) > (-1)), l_2538)), 4U)), g_70)))) < g_2740) <= l_2694[2][5]), l_2694[3][2])) & l_2546)), g_1132)), g_317))) > g_1857))), l_2712[0])) || g_1081[0]), g_2593[4][7][1])), 5)) && 1), 2)), 2)), 0xDF6E))) <= l_2694[2][5]))
        {
            int16_t l_2745 = 0x2EE7;
            int32_t l_2748 = 0x52A28E76;
            l_2742++;
            l_2749[2][4]--;
        }
        else
        {
            l_2300 = g_1526;
        }
    }
    return l_2298;
}







static uint32_t func_8(uint16_t p_9, int8_t p_10, int16_t p_11)
{
    int32_t l_16 = 1;
    int32_t l_26 = 0x939E63A5;
    int32_t l_1235 = 0x7AE02D14;
    int32_t l_1236 = 0;
    int32_t l_1525 = 9;
    g_1526 = (l_1525 = func_12(l_16, l_16, (((safe_lshift_func_int16_t_s_u((safe_mul_func_int8_t_s_s(func_21(g_2, (((l_1236 = (((0x5EC41505 && (l_26 = 0x7BF19931)) ^ (safe_div_func_uint8_t_u_u(((l_16 | ((l_1235 &= (safe_sub_func_int16_t_s_s(func_31(((safe_mul_func_int16_t_s_s(((safe_div_func_uint8_t_u_u(func_39(g_2), (p_11 | g_1081[0]))) != g_942[0][2]), l_16)) < g_940), g_266, l_16), l_16))) > g_272)) >= p_9), p_9))) ^ 0xF5)) <= 1) > g_1081[0]), l_16, l_16), p_11)), l_16)) != g_865) || g_553[1])));
    return l_1235;
}







inline static int32_t func_12(int16_t p_13, int16_t p_14, int16_t p_15)
{
    uint32_t l_1522 = 0x6BD8CA87;
    l_1522++;
    return g_865;
}







static int8_t func_21(int32_t p_22, uint8_t p_23, uint8_t p_24, int32_t p_25)
{
    int16_t l_1237 = (-2);
    int32_t l_1239 = 0x1C09BA82;
    int32_t l_1241 = 1;
    int32_t l_1243 = (-1);
    uint16_t l_1279[7][2] = {{0x178C, 0xDE46}, {0x178C, 0xDE46}, {0x178C, 0xDE46}, {0x178C, 0xDE46}, {0x178C, 0xDE46}, {0x178C, 0xDE46}, {0x178C, 0xDE46}};
    int16_t l_1281[1][7] = {{0xB0CB, 0xB0CB, 0xA678, 0xB0CB, 0xB0CB, 0xA678, 0xB0CB}};
    uint16_t l_1361 = 65528U;
    int32_t l_1492 = 1;
    int32_t l_1496 = 0x1C3A3192;
    int32_t l_1497 = 0x142D2E99;
    int i, j;
    for (g_375 = 0; (g_375 <= 6); g_375 += 1)
    {
        int8_t l_1238 = 0x65;
        int32_t l_1240 = 0xEB663C96;
        int32_t l_1242 = 0x6D2BB8B4;
        int32_t l_1244 = 8;
        int32_t l_1245 = 1;
        int32_t l_1246[2];
        int16_t l_1280 = (-4);
        uint8_t l_1340[5];
        int i;
        for (i = 0; i < 2; i++)
            l_1246[i] = 6;
                                            while (((l_1492 < g_865) && (g_944!=217)) )
{

g_377 += 1;


}
                    for (i = 0; i < 5; i++)
            l_1340[i] = 255U;
        --g_1247;
        g_1131 = (safe_rshift_func_uint8_t_u_s((+0), 0));
        for (g_866 = 0; (g_866 <= 3); g_866 += 1)
        {
            int32_t l_1282 = 0x764B3D90;
            int32_t l_1418[2];
            int i;
            for (i = 0; i < 2; i++)
                l_1418[i] = 0xB8012C02;
            l_1282 = (safe_mul_func_uint8_t_u_u((((g_147[(g_866 + 3)] ^ ((safe_lshift_func_uint8_t_u_u(l_1239, (((l_1244 = ((g_176 <= (safe_div_func_uint8_t_u_u((safe_div_func_uint8_t_u_u((g_2 & (safe_rshift_func_int16_t_s_u((safe_mul_func_uint16_t_u_u((((((safe_mod_func_uint8_t_u_u(((l_1243 ^= p_24) || ((4 >= ((safe_div_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((g_738 <= ((((g_1130 || (l_1280 = (g_1084 = (((l_1279[0][1] = ((l_1241 &= (l_1242 = (safe_mod_func_int8_t_s_s((g_643[2][2][2] |= (safe_mod_func_int8_t_s_s((safe_mod_func_uint16_t_u_u((safe_mul_func_int8_t_s_s(((l_1246[0] = ((((p_24 <= g_1132) != g_213) >= 0) <= l_1243)) | g_317), l_1244)), g_1082)), 0xE5))), 248U)))) != 1)) <= g_147[(g_866 + 3)]) == g_147[(g_866 + 3)])))) > p_23) || p_25) <= l_1281[0][1])), g_171)), l_1239)) == 0U)) > g_147[1])), l_1238)) && l_1237) == g_147[(g_866 + 3)]) || g_477) == g_147[(g_866 + 3)]), g_1149)), 9))), 0x44)), 4U))) >= 1)) || (-1)) | g_266))) != g_865)) >= p_23) > (-1)), l_1245));
            if ((safe_div_func_uint16_t_u_u((safe_mod_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s((safe_mul_func_uint8_t_u_u((~g_898), (1 < (g_1247 ^= (safe_div_func_uint8_t_u_u(g_1143[2][0][6], (g_1130 = (safe_lshift_func_int8_t_s_s((safe_div_func_int32_t_s_s((safe_add_func_uint16_t_u_u(p_22, l_1237)), (g_1132 = (((safe_add_func_int32_t_s_s(((((safe_mul_func_int16_t_s_s((safe_mod_func_int8_t_s_s((g_171 >= (safe_lshift_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(((safe_add_func_int16_t_s_s((l_1240 &= ((safe_div_func_int16_t_s_s((safe_lshift_func_uint8_t_u_u(((safe_add_func_int8_t_s_s((l_1239 &= (l_1241 &= ((safe_mod_func_uint32_t_u_u((l_1282 = 4294967295U), (safe_sub_func_uint8_t_u_u((0 != (!1U)), g_894[0][2])))) & 0x9E6D))), g_1131)) && l_1279[4][1]), p_24)), 0x9C85)) < g_477)), p_25)) | p_22), g_147[(g_866 + 3)])), 7))), l_1280)), g_147[(g_866 + 3)])) > p_25) >= 3U) && 1U), g_266)) && 1) ^ 0xCCD65FC1)))), 3))))))))), l_1243)), g_147[(g_866 + 3)])), 0xFA64)))
            {
                uint32_t l_1360 = 0U;
                if (l_1241)
                    break;
                g_1323--;

g_272 |= ((--g_1857) >= g_1420);

                    for (g_126 = 0; (g_126 <= 0); g_126 += 1)
                {
                    int32_t l_1339 = (-6);
                    int i, j, k;
                    if ((safe_rshift_func_int16_t_s_u(g_1143[(g_126 + 2)][g_126][(g_126 + 6)], 4)))
                    {
                        int i, j, k;
                        if (g_1143[(g_126 + 2)][g_126][(g_126 + 6)])
                            break;
                        g_1131 ^= (safe_sub_func_int32_t_s_s((safe_sub_func_uint16_t_u_u((g_176 > (0x8B | p_24)), p_24)), g_272));
                        l_1282 = ((p_22 < ((safe_add_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_u(0xC3, 5)), (safe_add_func_uint32_t_u_u((+g_894[1][3]), l_1282)))) > ((0x32C76A95 != ((((g_1143[g_126][g_126][(g_375 + 1)] |= g_140) <= ((0x327F >= (l_1339 = p_23)) || p_22)) & p_25) & p_24)) >= l_1340[3]))) > 0x8D774750);
                    }
                    else
                    {
                        uint32_t l_1378 = 0x6DB7287F;
                        int32_t l_1385 = 2;
                        l_1361 = ((l_1360 = (safe_add_func_int32_t_s_s(p_25, (((+g_140) ^ (((safe_rshift_func_uint16_t_u_s((safe_add_func_int32_t_s_s(((((safe_add_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_s(0x3496, 7)) > p_24), (safe_lshift_func_int16_t_s_u((safe_mul_func_uint8_t_u_u(g_265, (safe_mod_func_int32_t_s_s(0x755BCF62, (safe_div_func_uint16_t_u_u((((((((8U ^ ((0xAC == g_1132) != 0xB09F2BF6)) < g_373) && p_24) ^ 0) | 0x7BBD3C07) | 0x3E70134A) && p_24), (-1))))))), 4)))) != 1U) | l_1340[3]) >= (-1)), p_23)), 9)) > p_24) || p_24)) & 0U)))) != g_613);
                        l_1240 = (((0x83 <= (((!(0x06C3BAA9 < ((safe_div_func_uint16_t_u_u((l_1282 ^= ((safe_sub_func_int32_t_s_s((l_1339 = (p_22 != 0U)), (+(safe_add_func_uint16_t_u_u((~p_25), ((safe_sub_func_int32_t_s_s((g_1149 = (g_1131 = (safe_add_func_int8_t_s_s(p_22, (!g_148))))), g_147[0])) >= ((g_176 = (p_23 >= g_147[(g_866 + 3)])) == l_1378))))))) == g_306)), g_1132)) ^ 0))) && 0x4CBC) ^ g_1130)) >= g_317) != 0x7E);
                        l_1243 = (g_865 && (safe_div_func_int8_t_s_s((p_22 == ((safe_div_func_uint16_t_u_u(0U, (safe_sub_func_uint16_t_u_u(g_1143[(g_126 + 2)][g_126][(g_126 + 6)], p_25)))) && (--g_1146))), (safe_lshift_func_uint8_t_u_u((safe_div_func_int32_t_s_s((p_23 >= 0x68), g_147[(g_866 + 3)])), ((safe_sub_func_int32_t_s_s((safe_lshift_func_int16_t_s_u((-1), p_23)), l_1244)) == l_1279[0][1]))))));
                    }
                }
            }
            else
            {
                uint32_t l_1406[3];
                uint16_t l_1417 = 0x7864;
                int32_t l_1431[2][1];
                int32_t l_1433[5][2] = {{0x1718D21B, 1}, {0x1718D21B, 1}, {0x1718D21B, 1}, {0x1718D21B, 1}, {0x1718D21B, 1}};
                int i, j;
                for (i = 0; i < 3; i++)
                    l_1406[i] = 0xE32EA61A;
                for (i = 0; i < 2; i++)
                {
                    for (j = 0; j < 1; j++)
                        l_1431[i][j] = 0xD168D7B7;
                }
                for (g_126 = 0; (g_126 <= 1); g_126 += 1)
                {
                    int32_t l_1430 = 0x155D9E8B;
                    int i, j;
                                                       if ((g_1146<=3529045023U))
                    l_1282 = (((l_1279[(g_866 + 3)][g_126] > ((safe_sub_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s((safe_lshift_func_uint8_t_u_s((safe_rshift_func_uint16_t_u_u((safe_mul_func_uint16_t_u_u(((l_1406[2] |= g_942[(g_126 + 1)][g_126]) || (safe_add_func_uint8_t_u_u(((((l_1239 ^= p_25) == (safe_div_func_int32_t_s_s(g_944, (safe_mod_func_uint32_t_u_u(l_1279[(g_866 + 3)][g_126], g_866))))) <= (((safe_div_func_uint16_t_u_u((safe_add_func_uint8_t_u_u(0xF7, l_1417)), l_1279[3][1])) | 0xFA) && l_1279[1][1])) & 0xEA81), p_24))), g_477)), g_644)), 5)), 0)), l_1417)) != l_1417)) || p_25) | 0U);
                    for (g_83 = 0; (g_83 <= 3); g_83 += 1)
                    {
                        uint16_t l_1425[3][10][2] = {{{65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}}, {{65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}}, {{65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}, {65534U, 0x68FB}}};
                        int32_t l_1432 = 1;
                        int i, j, k;
                        g_1420--;
                        l_1433[2][1] = (safe_mod_func_int16_t_s_s((l_1431[1][0] = (((g_377 = (((p_23 >= (g_944 = ((0xEB1E >= (l_1425[0][0][1] ^= p_25)) || 1U))) & 0xF81E) <= 247U)) > 0) < (safe_div_func_uint32_t_u_u(p_23, (safe_add_func_int16_t_s_s((l_1430 |= (l_1238 >= p_24)), 0xF974)))))), l_1432));
                        return p_25;
                    }
                    g_1419 = (0xC1113AD5 < (safe_lshift_func_uint16_t_u_s(g_894[3][1], (safe_add_func_int8_t_s_s(0x91, (l_1430 ^= (safe_sub_func_int8_t_s_s(p_25, 1U))))))));
                    for (l_1242 = 0; (l_1242 <= 3); l_1242 += 1)
                    {
                        return g_266;
                    }
                }
                for (g_140 = 0; (g_140 <= 3); g_140 += 1)
                {
                    uint8_t l_1461[2];
                    int i;
                    for (i = 0; i < 2; i++)
                        l_1461[i] = 253U;
                    g_1419 |= (safe_mul_func_uint8_t_u_u(((g_1442[4][2]--) > (safe_rshift_func_uint16_t_u_u((l_1431[0][0] ^ ((p_25 != (safe_mod_func_uint32_t_u_u((((-4) || (safe_lshift_func_int16_t_s_u(((g_1323 | (safe_add_func_int8_t_s_s((l_1418[0] = (g_940 = ((safe_sub_func_uint32_t_u_u((l_1431[1][0] >= (safe_rshift_func_uint16_t_u_s(0x397F, 10))), (l_1282 = g_268))) || (((safe_mul_func_uint16_t_u_u(g_1131, (((safe_sub_func_uint32_t_u_u(g_264, 1U)) != 0x5617) != l_1418[0]))) <= 0xA3) && l_1431[0][0])))), 0x2D))) <= l_1406[2]), p_23))) < g_308), l_1461[0]))) > p_22)), 15))), p_24));
                }
                l_1241 = l_1406[2];
            }
        }
    }
    g_1149 = (((safe_mod_func_int16_t_s_s((safe_lshift_func_uint16_t_u_s((p_22 >= ((safe_unary_minus_func_uint16_t_u(g_1084)) ^ ((safe_mul_func_int8_t_s_s((((safe_mul_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s(l_1279[0][1], 8)), (65535U & (((251U == 0U) ^ (safe_mul_func_int16_t_s_s(((safe_add_func_uint8_t_u_u(6U, (safe_rshift_func_uint8_t_u_u((g_944 ^= (safe_mod_func_uint8_t_u_u((p_24 = 0U), ((p_23 || (-8)) ^ 0x9080)))), g_646[8])))) | l_1281[0][4]), 0xB0E0))) || 9)))) <= 0xC33BB592) == p_23), l_1281[0][1])) || l_1361))), p_25)), p_22)) <= 4294967295U) | 0x70);
    for (g_944 = (-29); (g_944 <= 3); ++g_944)
    {
        return g_274[2];
    }
    for (g_375 = (-2); (g_375 == (-6)); g_375 = safe_sub_func_int32_t_s_s(g_375, 8))
    {
        int8_t l_1495 = (-1);
        uint32_t l_1499 = 0x765327B6;
        for (g_644 = 4; (g_644 >= 19); g_644 = safe_add_func_uint32_t_u_u(g_644, 7))
        {
            int8_t l_1487 = 0xA2;
            int32_t l_1488 = 0xB348976B;
            int32_t l_1489 = 0xCB14215C;
            int32_t l_1490 = 0xBD02FBB1;
            int32_t l_1491 = 0;
            int32_t l_1493 = 0xC8AE7D3C;
            int32_t l_1494 = 1;
            int32_t l_1498 = 0xAAFD9045;
            --l_1499;
        }
        l_1492 &= (safe_sub_func_uint16_t_u_u(0x583A, (safe_rshift_func_int16_t_s_s((safe_div_func_int32_t_s_s(((safe_sub_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((safe_mod_func_uint32_t_u_u(l_1495, (l_1243 |= ((safe_add_func_uint16_t_u_u(((g_894[0][1] < (safe_rshift_func_uint16_t_u_u((safe_add_func_int16_t_s_s(0x20D8, (p_23 ^ (((p_22 >= ((safe_lshift_func_uint8_t_u_u(g_274[5], l_1281[0][1])) < l_1495)) | l_1279[0][1]) == g_213)))), 7))) | g_944), g_1082)) >= p_22)))), 0x44AB6D3D)), g_352)) || 0), g_865)), l_1497))));
        return p_22;
    }
    return l_1239;
}







inline static int16_t func_31(int8_t p_32, uint8_t p_33, int32_t p_34)
{
    int8_t l_1215 = 0;
    int32_t l_1222 = 1;
    int32_t l_1234 = 1;
    g_375 = (g_613 <= l_1215);
    p_34 = p_34;
    g_1149 ^= (g_375 &= (((safe_sub_func_uint16_t_u_u((safe_add_func_int32_t_s_s(((safe_sub_func_int8_t_s_s(p_33, ((l_1234 = ((((l_1222 |= 1U) < (~(safe_add_func_int8_t_s_s((p_33 && (safe_rshift_func_int8_t_s_s(g_83, ((0x36 >= (!255U)) > ((((safe_div_func_uint8_t_u_u(0x8E, g_477)) > (safe_unary_minus_func_int8_t_s(p_32))) & p_32) > 0xF307))))), 1U)))) > p_33) > g_942[1][1])) && g_268))) || g_643[2][2][2]), p_32)), p_33)) ^ 0xB2) < 3U));
    p_34 ^= (p_32 | 250U);
    return g_643[2][2][2];
}







static uint8_t func_39(int16_t p_40)
{
    int16_t l_41[7][4] = {{(-1), 0, 0x9ACB, 0x9ACB}, {(-1), 0, 0x9ACB, 0x9ACB}, {(-1), 0, 0x9ACB, 0x9ACB}, {(-1), 0, 0x9ACB, 0x9ACB}, {(-1), 0, 0x9ACB, 0x9ACB}, {(-1), 0, 0x9ACB, 0x9ACB}, {(-1), 0, 0x9ACB, 0x9ACB}};
    uint32_t l_42 = 4294967292U;
    int32_t l_53 = 0x5C1ED529;
    int32_t l_60 = 9;
    const int32_t l_430[3][1][6] = {{{1, 1, 1, 1, 1, 1}}, {{1, 1, 1, 1, 1, 1}}, {{1, 1, 1, 1, 1, 1}}};
    int32_t l_1191 = 3;
    int i, j, k;
    for (p_40 = 3; (p_40 >= 0); p_40 -= 1)
    {
        return l_42;
    }
    for (p_40 = (-6); (p_40 < (-23)); p_40 = safe_sub_func_uint32_t_u_u(p_40, 5))
    {
        return l_41[3][2];
    }
    l_1191 = func_45(p_40, (p_40 > (safe_mul_func_uint8_t_u_u(((l_53 = g_2) || (((func_54(l_60, g_2, func_61(p_40, (6U > (l_53 ^= g_2)), (safe_add_func_int8_t_s_s(g_2, g_2))), l_60, p_40) | 4294967290U) ^ l_42) | 0x61C0)), 1U))), p_40, p_40, l_430[0][0][0]);
    for (g_350 = (-17); (g_350 < 39); g_350 = safe_add_func_int8_t_s_s(g_350, 4))
    {
        int16_t l_1196[7][9] = {{0x8D21, 0xDDEE, 0x43F3, 0xDDEE, 0x8D21, 0x4085, 0x43F3, 0x4085, 0x8D21}, {0x8D21, 0xDDEE, 0x43F3, 0xDDEE, 0x8D21, 0x4085, 0x43F3, 0x4085, 0x8D21}, {0x8D21, 0xDDEE, 0x43F3, 0xDDEE, 0x8D21, 0x4085, 0x43F3, 0x4085, 0x8D21}, {0x8D21, 0xDDEE, 0x43F3, 0xDDEE, 0x8D21, 0x4085, 0x43F3, 0x4085, 0x8D21}, {0x8D21, 0xDDEE, 0x43F3, 0xDDEE, 0x8D21, 0x4085, 0x43F3, 0x4085, 0x8D21}, {0x8D21, 0xDDEE, 0x43F3, 0xDDEE, 0x8D21, 0x4085, 0x43F3, 0x4085, 0x8D21}, {0x8D21, 0xDDEE, 0x43F3, 0xDDEE, 0x8D21, 0x4085, 0x43F3, 0x4085, 0x8D21}};
        int32_t l_1205[8][10] = {{0xA74F5C2F, 0xA74F5C2F, (-1), 2, (-1), 0x6549C328, (-6), 0xA74F5C2F, 0xCF165014, (-6)}, {0xA74F5C2F, 0xA74F5C2F, (-1), 2, (-1), 0x6549C328, (-6), 0xA74F5C2F, 0xCF165014, (-6)}, {0xA74F5C2F, 0xA74F5C2F, (-1), 2, (-1), 0x6549C328, (-6), 0xA74F5C2F, 0xCF165014, (-6)}, {0xA74F5C2F, 0xA74F5C2F, (-1), 2, (-1), 0x6549C328, (-6), 0xA74F5C2F, 0xCF165014, (-6)}, {0xA74F5C2F, 0xA74F5C2F, (-1), 2, (-1), 0x6549C328, (-6), 0xA74F5C2F, 0xCF165014, (-6)}, {0xA74F5C2F, 0xA74F5C2F, (-1), 2, (-1), 0x6549C328, (-6), 0xA74F5C2F, 0xCF165014, (-6)}, {0xA74F5C2F, 0xA74F5C2F, (-1), 2, (-1), 0x6549C328, (-6), 0xA74F5C2F, 0xCF165014, (-6)}, {0xA74F5C2F, 0xA74F5C2F, (-1), 2, (-1), 0x6549C328, (-6), 0xA74F5C2F, 0xCF165014, (-6)}};
        int i, j;
        l_1191 ^= ((safe_mod_func_int32_t_s_s(p_40, (g_1132 ^= (1U ^ l_1196[6][2])))) == (p_40 < ((safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_s((safe_div_func_uint8_t_u_u(p_40, 8U)), 11)), 1U)) | (((safe_sub_func_int16_t_s_s(((g_1084++) & p_40), (safe_mul_func_int8_t_s_s(((((safe_mul_func_uint16_t_u_u(p_40, p_40)) <= g_553[1]) >= p_40) || l_60), 0U)))) || p_40) && 255U))));
        for (g_171 = (-26); (g_171 > 46); g_171 = safe_add_func_uint16_t_u_u(g_171, 8))
        {
            uint32_t l_1214 = 0U;
            if (l_1214)
                break;
        }
    }
    return p_40;
}







static const int32_t func_45(uint8_t p_46, const uint32_t p_47, uint32_t p_48, int8_t p_49, const uint8_t p_50)
{
    int32_t l_441 = 8;
    int32_t l_442 = (-1);
    int32_t l_455 = 0xD5F1C41A;
    int32_t l_456[6] = {0, 0, 9, 0, 0, 9};
    uint32_t l_496 = 0x7F588084;
    int32_t l_569 = 0xAE752BB4;
    int32_t l_688 = 0xE1189091;
    uint32_t l_739 = 1U;
    int8_t l_897 = 0x1B;
    uint16_t l_918 = 65535U;
    uint32_t l_920 = 1U;
    int i;
    l_441 = (safe_rshift_func_uint8_t_u_u((safe_div_func_int32_t_s_s((safe_mod_func_int8_t_s_s((g_352 <= (p_49 = g_147[0])), 0x4F)), (safe_div_func_uint16_t_u_u((safe_mul_func_int16_t_s_s(l_441, ((p_48 &= (g_377 = (l_442 = 0xDE55AF26))) && (l_442 & ((safe_mul_func_int16_t_s_s((safe_rshift_func_uint8_t_u_s((l_456[3] = (safe_mod_func_uint32_t_u_u(g_70, (safe_rshift_func_uint8_t_u_u((l_455 = ((g_126 == ((safe_add_func_int32_t_s_s((safe_add_func_int16_t_s_s(0x0C89, g_148)), l_442)) == g_264)) | 5)), l_442))))), g_274[5])), g_176)) | p_48))))), 65535U)))), g_264));
    for (g_70 = 0; (g_70 != 4); g_70 = safe_add_func_int32_t_s_s(g_70, 4))
    {
        const uint8_t l_459 = 247U;
        uint32_t l_484 = 0x43DF4C43;
        uint8_t l_485 = 0xF6;
        int16_t l_489 = 0xE97C;
        uint32_t l_540[8][9][2] = {{{0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}}, {{0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}}, {{0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}}, {{0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}}, {{0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}}, {{0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}}, {{0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}}, {{0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}, {0x08077E91, 0x99569A53}}};
        int32_t l_595 = (-1);
        uint8_t l_596 = 0xAD;
        int8_t l_597 = (-9);
        const int16_t l_661 = 0x087F;
        uint32_t l_759 = 0x2AF4A6B6;
        int32_t l_895 = (-1);
        uint32_t l_916 = 0xCA23C0DA;
        int32_t l_923 = 0x62EF15C2;
        int32_t l_956 = (-1);
        int32_t l_968 = (-8);
        int32_t l_1080 = (-9);
        int32_t l_1103 = (-1);
        uint32_t l_1163 = 0xD5E174C5;
        int i, j, k;
        if (l_459)
        {
            uint16_t l_464 = 65535U;
            int32_t l_486 = 0xB2C4DEC1;
            for (p_46 = (-21); (p_46 > 26); p_46 = safe_add_func_uint32_t_u_u(p_46, 8))
            {
                l_464 = ((safe_rshift_func_int8_t_s_s(p_49, 3)) || g_266);
            }
            if (g_350)
                continue;
            l_486 = (g_176 > (((safe_rshift_func_int16_t_s_u(((safe_div_func_int32_t_s_s((safe_mod_func_int8_t_s_s(((safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_u((g_274[5] = (l_459 || 0x32)), 0)), g_477)) >= (6 | (((safe_mul_func_int16_t_s_s(((0x505FBEA6 > (l_484 = (safe_div_func_uint16_t_u_u((g_317 & ((safe_rshift_func_uint16_t_u_s((0x8D >= l_456[3]), p_49)) < 4294967295U)), l_459)))) && g_264), p_47)) | l_442) == g_70))), (-1))), 0x88C29AAB)) && 1), 6)) <= l_485) >= 0xDE));
            g_375 = (safe_add_func_int16_t_s_s((l_489 && g_350), (safe_unary_minus_func_uint32_t_u(((0xFED8 | (safe_sub_func_int32_t_s_s(((+((safe_add_func_int32_t_s_s(l_456[3], (l_496--))) >= (safe_unary_minus_func_int32_t_s(((safe_mod_func_uint16_t_u_u(0x9F39, l_464)) || p_48))))) ^ p_46), (l_486 = ((safe_add_func_int16_t_s_s(g_83, 0U)) | 0xB3C5))))) != l_459)))));
        }
        else
        {
            uint32_t l_504 = 1U;
            --l_504;
            l_442 = (safe_lshift_func_uint16_t_u_u((safe_add_func_uint8_t_u_u((~p_47), (g_265 = l_442))), (p_48 || (safe_rshift_func_uint16_t_u_u((safe_div_func_int8_t_s_s((safe_add_func_int32_t_s_s(((g_148++) ^ (g_272 || ((l_455 = (safe_rshift_func_int16_t_s_s(((safe_add_func_uint32_t_u_u(((((p_49 == (safe_div_func_int32_t_s_s(((l_456[3] ^= (safe_add_func_uint32_t_u_u((safe_lshift_func_uint16_t_u_s((safe_add_func_int32_t_s_s(((g_171 = (l_441 = (safe_sub_func_int32_t_s_s((~l_441), (safe_lshift_func_uint8_t_u_u(l_504, (g_83 ^= (!(safe_rshift_func_int16_t_s_u((l_484 || ((l_540[0][3][1] != g_350) != g_176)), g_143)))))))))) ^ 0x6B), p_46)), 10)), p_46))) == 8), g_143))) | g_352) <= g_376) & p_47), l_504)) > g_274[2]), l_504))) != 0x78))), 1U)), l_496)), 8)))));
        }
        l_442 = (((safe_rshift_func_int16_t_s_u(8, (safe_div_func_int8_t_s_s((g_317 = p_48), (safe_mul_func_uint8_t_u_u(g_375, ((((((safe_mul_func_uint8_t_u_u((g_373 & (g_272 >= 0xFD14)), (safe_sub_func_uint8_t_u_u(((l_456[3] ^= (2 || ((safe_mul_func_int16_t_s_s(((g_553[1] != (l_489 == 0xC2DE2F56)) == p_49), 0x6C27)) ^ p_48))) <= g_171), l_441)))) || g_553[1]) && l_484) && 3) & p_46) > l_459))))))) == l_459) ^ 2U);
        if ((g_375 = (((safe_div_func_int16_t_s_s((safe_div_func_int16_t_s_s((((g_373 = (g_317 = (safe_mul_func_int8_t_s_s((l_596 = (g_265 = (p_50 || (~((safe_mul_func_int16_t_s_s((((safe_lshift_func_int8_t_s_s((safe_mod_func_int16_t_s_s(3, p_50)), 3)) > (safe_mod_func_uint8_t_u_u(l_569, 0x2D))) && ((~(safe_add_func_int32_t_s_s(((safe_sub_func_int16_t_s_s(((((((safe_div_func_uint32_t_u_u((((((safe_mod_func_uint8_t_u_u(g_376, (safe_sub_func_uint16_t_u_u((safe_mul_func_int16_t_s_s((safe_rshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s(((safe_mod_func_int32_t_s_s(((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s(l_484, (g_352 = 0x6350))), p_49)) != 0xFB), l_595)) | l_489), 6)), p_48)), 65532U)), p_46)))) | (-1)) == 0x0C013099) < 65535U) <= g_274[2]), (-1))) & 0x570B) == p_47) && 0U) >= l_484) && g_147[3]), g_274[6])) ^ 0), 0xAC8FC47F))) == 4294967288U)), l_455)) | 0xD4844485))))), (-1))))) < p_47) & l_597), l_456[5])), g_350)) <= g_148) | p_48)))
        {
            uint8_t l_601 = 1U;
            int32_t l_610 = 1;
            uint32_t l_755 = 9U;
            int8_t l_836 = 0;
            uint8_t l_864[6][9][4] = {{{1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}}, {{1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}}, {{1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}}, {{1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}}, {{1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}}, {{1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}}};
            int32_t l_896 = 1;
            int32_t l_941 = 0;
            int32_t l_943[3][3] = {{0xD427FCA6, 1, 0xD427FCA6}, {0xD427FCA6, 1, 0xD427FCA6}, {0xD427FCA6, 1, 0xD427FCA6}};
            int i, j, k;
            if ((safe_mod_func_uint8_t_u_u(1U, l_456[1])))
            {
                uint8_t l_600 = 255U;
                int32_t l_604 = 4;
                int32_t l_605 = 0x191F9277;
                int8_t l_606 = 0x5A;
                int32_t l_611 = 1;
                int32_t l_612 = 1;
                const int16_t l_622 = 0xC6C8;
                if ((l_601 |= l_600))
                {
                    uint32_t l_607 = 0xF83F992C;
                    for (g_373 = 20; (g_373 >= (-16)); g_373--)
                    {
                        ++l_607;
                    }
                }
                else
                {
                    int32_t l_618 = (-8);
                    if (p_49)
                        break;
                    ++g_613;
                    g_375 = (((safe_rshift_func_int16_t_s_s((l_618 = (0x14E0A851 == 7U)), 0)) == ((!(!l_595)) & (+l_455))) != (l_622 == (++g_171)));
                }
            }
            else
            {
                uint8_t l_636[10][2] = {{0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}};
                int32_t l_640 = 0x36AFFF2B;
                int32_t l_641 = (-1);
                int32_t l_642 = (-1);
                int i, j;
                if ((safe_add_func_uint16_t_u_u(l_610, g_274[1])))
                {
                    int32_t l_662[3][3];
                    int32_t l_677[1][3][10] = {{{0x559718EA, 1, (-1), 0x61261F33, 0x61261F33, (-1), 1, 0x559718EA, (-1), 0x559718EA}, {0x559718EA, 1, (-1), 0x61261F33, 0x61261F33, (-1), 1, 0x559718EA, (-1), 0x559718EA}, {0x559718EA, 1, (-1), 0x61261F33, 0x61261F33, (-1), 1, 0x559718EA, (-1), 0x559718EA}}};
                    int32_t l_740 = (-1);
                    int i, j, k;
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 0; j < 3; j++)
                            l_662[i][j] = 0xA6010A17;
                    }
                    g_375 = ((((safe_mod_func_int16_t_s_s((safe_add_func_uint8_t_u_u((safe_unary_minus_func_int16_t_s(p_50)), (0x3B != ((l_540[2][5][0] > (g_213 |= (g_306 = 0x5135))) | (l_610 = 0xC7))))), (l_456[2] = (safe_add_func_uint16_t_u_u((g_317 ^ (p_48 < (g_553[0] || 65534U))), g_352))))) != l_636[8][0]) == l_636[8][1]) & p_48);
                    for (l_595 = 0; (l_595 <= 23); l_595++)
                    {
                        int8_t l_639 = 0xF4;
                        int32_t l_645 = 0xE79238BF;
                        g_646[5]++;
                        g_375 &= ((safe_sub_func_int32_t_s_s(p_47, ((safe_sub_func_uint8_t_u_u((safe_unary_minus_func_int32_t_s(0x1A0E37F8)), ((safe_mul_func_int8_t_s_s(((safe_mul_func_uint16_t_u_u(3U, 65528U)) <= l_441), (!(0x6620879A == ((((l_642 ^= 9) != (l_442 = (safe_mod_func_uint32_t_u_u(l_645, (((g_2 && l_645) | l_540[3][3][1]) && l_661))))) || l_636[8][0]) || l_662[0][1]))))) | 0x90))) != g_643[2][4][4]))) || 0U);
                    }
                    if ((safe_add_func_uint16_t_u_u((l_662[0][1] || ((g_375 &= (((safe_lshift_func_uint16_t_u_u(l_601, (safe_mul_func_uint8_t_u_u(((safe_mod_func_int16_t_s_s((safe_lshift_func_int8_t_s_s((-3), 5)), (safe_mod_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((++g_274[5]), l_641)) || (safe_div_func_int8_t_s_s((1U <= ((safe_mul_func_int16_t_s_s(((safe_mod_func_uint8_t_u_u(0x28, (g_373 = 0x43))) > p_48), (safe_mod_func_uint8_t_u_u(g_265, g_143)))) ^ 0U)), 1))), p_47)))) && l_688), 255U)))) ^ l_662[0][1]) == l_459)) > 9U)), g_352)))
                    {
                        uint16_t l_697[5][2][3];
                        int i, j, k;
                        for (i = 0; i < 5; i++)
                        {
                            for (j = 0; j < 2; j++)
                            {
                                for (k = 0; k < 3; k++)
                                    l_697[i][j][k] = 0xA801;
                            }
                        }
                        g_375 &= ((safe_add_func_int8_t_s_s(((g_643[2][2][2] > (safe_lshift_func_uint8_t_u_s((safe_add_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(l_697[0][1][1], (safe_add_func_uint8_t_u_u(g_176, (safe_div_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(((((l_610 = (g_373 &= (((safe_mul_func_int16_t_s_s((safe_add_func_int8_t_s_s((((safe_lshift_func_int8_t_s_u((l_739 = ((safe_add_func_uint8_t_u_u((p_46 = (((((((l_642 |= ((l_610 != (safe_rshift_func_uint16_t_u_u((((p_49 ^= (65526U >= (safe_mod_func_int32_t_s_s(p_50, (p_48 ^= l_641))))) <= (g_265 ^ (g_171--))) ^ ((safe_mod_func_int8_t_s_s(((g_738 = ((safe_add_func_uint32_t_u_u((safe_div_func_int32_t_s_s(((safe_sub_func_int16_t_s_s((safe_add_func_int32_t_s_s((safe_add_func_uint32_t_u_u(((safe_mul_func_int8_t_s_s((safe_mul_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((safe_add_func_int32_t_s_s(p_50, g_148)), 0x1062D46E)), p_50)), p_47)) > l_610), 0U)), g_646[3])), 1)) | p_50), g_2)), 0x52250814)) <= p_50)) >= p_47), g_176)) ^ p_46)), 15))) <= 0)) <= l_661) == 0x6CC5ED28) || 0x232E) && 0x1C888861) == l_484) & 0U)), g_646[7])) > l_636[9][0])), 4)) == (-1)) | g_148), 0x73)), g_477)) & g_272) != g_148))) <= g_265) != l_740) >= 4U), p_50)), l_697[0][1][1])))))), p_47)), l_601))) >= l_697[4][0][2]), 0)) <= p_47);
                        l_610 ^= p_46;
                        return l_597;
                    }
                    else
                    {
                        return p_46;
                    }
                }
                else
                {
                    uint32_t l_810 = 0x32D066A9;
                    int32_t l_811[6][10] = {{(-10), (-10), 9, 0x5B68EDB2, 6, (-1), 0x5CAB97CD, (-10), 0x370FCE42, 0x5CAB97CD}, {(-10), (-10), 9, 0x5B68EDB2, 6, (-1), 0x5CAB97CD, (-10), 0x370FCE42, 0x5CAB97CD}, {(-10), (-10), 9, 0x5B68EDB2, 6, (-1), 0x5CAB97CD, (-10), 0x370FCE42, 0x5CAB97CD}, {(-10), (-10), 9, 0x5B68EDB2, 6, (-1), 0x5CAB97CD, (-10), 0x370FCE42, 0x5CAB97CD}, {(-10), (-10), 9, 0x5B68EDB2, 6, (-1), 0x5CAB97CD, (-10), 0x370FCE42, 0x5CAB97CD}, {(-10), (-10), 9, 0x5B68EDB2, 6, (-1), 0x5CAB97CD, (-10), 0x370FCE42, 0x5CAB97CD}};
                    int i, j;
                    if ((safe_mod_func_int32_t_s_s(0xDBE4D7E6, (safe_lshift_func_int8_t_s_u((-1), (safe_add_func_int16_t_s_s((safe_mul_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s((0 > (65532U | ((safe_lshift_func_uint16_t_u_s(65535U, 14)) != (g_317 = 0)))), 1)), l_755)), 0x662D)))))))
                    {
                        g_375 = ((safe_unary_minus_func_int8_t_s((l_759 = (-4)))) & (((safe_div_func_int8_t_s_s((p_47 <= (254U <= (safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(0xC0, 7)) == (l_610 = (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((g_171 &= (--p_46)), 3)), (g_643[2][2][2] = g_306))), p_47)))), (l_641 = (safe_lshift_func_int16_t_s_s(((l_595 ^= (l_636[7][0] || g_553[1])) | 0x4C94), g_148))))))), 0xD0)) ^ 0xB7) >= 0U));
                    }
                    else
                    {
                        uint32_t l_786[4];
                        int32_t l_812 = (-8);
                        int i;
                        for (i = 0; i < 4; i++)
                            l_786[i] = 8U;
                        l_786[3] = (safe_add_func_int16_t_s_s((safe_mul_func_uint8_t_u_u(l_455, (safe_sub_func_int8_t_s_s(1, (safe_mod_func_uint16_t_u_u(l_569, (safe_mod_func_uint8_t_u_u(246U, 0xD8)))))))), (0x3B84E7ED > p_48)));
                        l_812 = ((safe_mod_func_int32_t_s_s((l_595 = ((((safe_unary_minus_func_uint32_t_u((safe_mul_func_uint8_t_u_u(((l_811[3][4] |= ((safe_rshift_func_int16_t_s_u((safe_div_func_int16_t_s_s(g_643[0][2][6], (safe_sub_func_int16_t_s_s(((safe_lshift_func_uint16_t_u_u(g_147[1], 15)) >= (safe_mul_func_int8_t_s_s(0xED, 0x20))), g_70)))), 2)) != (safe_sub_func_uint8_t_u_u((l_786[3] | (safe_add_func_int16_t_s_s(((p_48 & (g_176 <= (safe_rshift_func_uint8_t_u_u((l_456[1] = g_268), 6)))) == l_459), l_810))), g_350)))) || p_48), 1U)))) || 1) == p_47) | 0xBC09786F)), 0xBBA88CD8)) >= l_755);
                    }
                    if (((safe_sub_func_int32_t_s_s((0U == (safe_add_func_int32_t_s_s((safe_add_func_uint8_t_u_u(0x04, (safe_lshift_func_int8_t_s_s((((g_613 = (safe_mul_func_uint8_t_u_u(0U, (l_595 = ((safe_add_func_int16_t_s_s(g_646[5], ((safe_sub_func_int32_t_s_s((l_610 = l_456[5]), (--g_147[0]))) ^ ((!p_49) & g_738)))) & (((safe_div_func_uint8_t_u_u(p_49, (p_46 = (safe_rshift_func_uint8_t_u_u((l_836 ^= (safe_rshift_func_int8_t_s_s(((((0x85 ^ 2) < (-10)) | 2) | 0x143B679D), p_47))), 3))))) < 0U) ^ g_373)))))) == 0x8B) <= 0), 2)))), p_47))), l_636[8][0])) <= l_755))
                    {
                        g_375 = ((((safe_lshift_func_uint16_t_u_u((safe_mul_func_uint16_t_u_u((((l_642 = (safe_mul_func_int16_t_s_s((l_610 &= l_601), ((safe_lshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((safe_rshift_func_int16_t_s_u(((safe_mod_func_uint8_t_u_u((((l_442 ^= (((!(l_595 = (251U || ((((+g_373) && (safe_div_func_uint16_t_u_u(1U, 0x19D5))) || (safe_mod_func_uint16_t_u_u((g_643[2][2][2] ^ (((safe_rshift_func_int8_t_s_u((safe_div_func_uint16_t_u_u(l_640, g_2)), (((safe_unary_minus_func_uint8_t_u(0x79)) >= 255U) || g_643[2][2][2]))) || p_48) & g_213)), p_48))) | p_49)))) >= g_553[0]) || p_50)) <= l_441) == g_272), g_646[0])) != g_2), g_646[0])), 6)), l_864[0][7][3])), 4)) < 0xBF88)))) >= l_810) & 1), l_864[5][0][0])), 15)) | (-1)) && g_126) >= g_171);
                        g_375 |= p_48;
                        ++g_866;
                        l_641 = l_485;
                    }
                    else
                    {
                        g_375 |= 8;
                        l_811[4][4] &= (-1);
                        return g_272;
                    }
                    if (l_595)
                        continue;
                    for (l_442 = 4; (l_442 >= 0); l_442 -= 1)
                    {
                        int i;
                        if (l_456[(l_442 + 1)])
                            break;
                    }
                }
                if (l_610)
                    break;
                return g_646[5];
            }
            --g_869;
            l_896 = ((safe_mul_func_uint8_t_u_u((((p_48 = 0x98FCCAFC) > (l_610 = (l_895 = ((l_441 = (g_266 || ((l_442 = (l_455 = (l_595 = (safe_add_func_int32_t_s_s((safe_div_func_uint8_t_u_u(((((safe_lshift_func_int8_t_s_u((g_613 && (safe_add_func_uint32_t_u_u(((((safe_div_func_uint16_t_u_u((g_894[3][1] &= (((l_456[3] &= (safe_add_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u((l_569 = (safe_sub_func_int16_t_s_s((~(l_540[0][3][1] != g_147[0])), p_49))), 12)), g_646[2]))) && (p_49 = (safe_unary_minus_func_int8_t_s(g_140)))) | (safe_mul_func_int16_t_s_s((g_147[6] > g_308), g_613)))), l_489)) & l_484) || g_894[3][1]) ^ g_317), p_46))), p_50)) == l_836) ^ l_485) >= g_274[5]), l_540[7][6][1])), g_308))))) != l_596))) > (-1))))) ^ g_171), 1)) | l_688);
            if (l_897)
            {
                --g_898;
            }
            else
            {
                uint32_t l_937 = 0U;
                for (l_441 = 0; (l_441 < (-21)); l_441 = safe_sub_func_int32_t_s_s(l_441, 1))
                {
                    uint32_t l_913 = 0x534F98FD;
                    int32_t l_917[7][9] = {{(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}, {(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}, {(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}, {(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}, {(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}, {(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}, {(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}};
                    int32_t l_919 = 0x92FB3904;
                    int i, j;
                    for (l_688 = 5; (l_688 >= 1); l_688 -= 1)
                    {
                        int i;
                        g_375 ^= ((l_456[l_688] = (~(l_919 = ((l_917[1][0] ^= ((g_646[(l_688 + 2)] && (l_456[l_688] >= (safe_div_func_int32_t_s_s((+(((safe_mul_func_int8_t_s_s(((safe_mul_func_uint8_t_u_u((l_456[l_688] && (g_308 < 1U)), g_911)) && ((+l_913) ^ (safe_lshift_func_uint16_t_u_s((9U >= (l_916 && l_739)), 14)))), 1U)) > g_350) >= g_373)), p_50)))) >= p_49)) == l_918)))) && l_596);
                        if (p_46)
                            continue;
                        l_455 = (g_213 <= l_920);
                    }
                    l_595 = g_83;
                    l_923 = (safe_lshift_func_uint8_t_u_s(254U, 1));
                    l_895 |= (p_50 != (safe_lshift_func_uint8_t_u_s(((safe_sub_func_uint8_t_u_u(p_49, (l_937 |= (safe_mul_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((l_864[3][0][0] && (safe_mul_func_uint16_t_u_u((+l_601), (safe_sub_func_uint32_t_u_u(l_919, l_864[0][7][3]))))), l_441)), g_376))))) & ((safe_rshift_func_uint8_t_u_s(g_553[1], 0)) ^ p_49)), p_48)));
                }
                --g_944;
            }
        }
        else
        {
            uint8_t l_953 = 1U;
            int32_t l_957 = 0x19442117;
            uint8_t l_958 = 1U;
            l_957 = (safe_mod_func_uint32_t_u_u((((safe_rshift_func_uint16_t_u_s((safe_add_func_uint32_t_u_u(p_46, ((l_455 &= (l_953++)) != g_213))), 15)) || l_956) != (p_49 = 0xCA)), 4294967294U));
            ++l_958;
            g_375 = l_918;
        }
        for (g_83 = 0; (g_83 <= 1); g_83 += 1)
        {
            uint32_t l_961[2][7][9] = {{{0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}, {0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}, {0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}, {0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}, {0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}, {0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}, {0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}}, {{0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}, {0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}, {0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}, {0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}, {0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}, {0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}, {0U, 0x18FBB734, 0U, 0xFD7EC99D, 4294967295U, 0x956D1E82, 4294967295U, 0xFD7EC99D, 0U}}};
            int32_t l_969 = 0xB420FD69;
            int16_t l_970 = 1;
            uint32_t l_1077 = 0x90854E4A;
            int32_t l_1133 = 0x228A4614;
            int32_t l_1141 = 1;
            int i, j, k;
            l_961[0][5][7]++;
            if ((l_897 < (safe_lshift_func_int8_t_s_u((safe_rshift_func_int8_t_s_s(6, 4)), (g_274[3]--)))))
            {
                int16_t l_994 = 9;
                uint8_t l_1003[1][9] = {{255U, 0xCA, 255U, 0xCA, 255U, 0xCA, 255U, 0xCA, 255U}};
                int32_t l_1083 = 0x9C61B267;
                int32_t l_1101 = 6;
                int32_t l_1145 = 0;
                int i, j;
                for (g_477 = 0; (g_477 <= 1); g_477 += 1)
                {
                    for (l_489 = 1; (l_489 >= 0); l_489 -= 1)
                    {
                        int i, j, k;
                        l_569 = ((p_46 = (((safe_add_func_int32_t_s_s(((+(safe_lshift_func_uint16_t_u_s(l_540[g_477][(g_477 + 5)][l_489], 6))) == (safe_sub_func_int8_t_s_s(((safe_lshift_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u(g_643[(g_83 + 3)][g_83][(g_477 + 5)], (safe_div_func_int16_t_s_s((safe_sub_func_int16_t_s_s((((safe_add_func_int32_t_s_s((p_47 ^ (safe_lshift_func_int16_t_s_s((+p_49), 4))), (+l_994))) & (4294967293U | p_50)) || 2), ((safe_sub_func_int8_t_s_s((g_373 = (safe_mod_func_int16_t_s_s((l_442 = (safe_mod_func_uint16_t_u_u(((safe_mul_func_int8_t_s_s(l_994, l_1003[0][8])) <= 0xB1263171), l_1003[0][2]))), 0x1AF4))), p_47)) & 0x7D))), l_918)))), 3)) | g_643[2][2][2]), p_48))), l_1003[0][8])) < p_47) ^ 0xCD)) < g_643[(g_83 + 3)][g_83][(g_477 + 5)]);
                        return p_49;
                    }
                }
                g_375 = ((~(((-1) >= ((safe_add_func_int8_t_s_s((safe_div_func_uint8_t_u_u(l_994, (safe_lshift_func_int8_t_s_u((g_274[7] > l_1003[0][4]), l_739)))), l_970)) & (safe_lshift_func_uint16_t_u_u((safe_rshift_func_uint16_t_u_s((safe_div_func_uint8_t_u_u(((((((safe_sub_func_uint16_t_u_u((safe_mod_func_uint32_t_u_u((3 && ((safe_sub_func_int8_t_s_s((~(~(safe_rshift_func_uint16_t_u_s((((safe_lshift_func_int8_t_s_s((l_994 <= 0xE2227C4F), 4)) > p_46) & l_1003[0][8]), 15)))), 0x58)) <= p_50)), p_47)), 0x0DD3)) > g_176) && g_375) | l_540[2][6][0]) == g_171) >= 0xE5E3), p_46)), g_274[1])), 14)))) >= p_47)) ^ 65531U);
                if ((+(g_317 >= 0x700F0D82)))
                {
                    uint32_t l_1078 = 1U;
                    for (l_918 = 0; (l_918 < 31); l_918 = safe_add_func_uint8_t_u_u(l_918, 1))
                    {
                        uint16_t l_1032 = 1U;
                        uint16_t l_1076 = 0x1462;
                        int32_t l_1079 = 0x39D1839D;
                        g_375 = (-1);
                        --l_1032;
                        g_375 = (safe_add_func_uint8_t_u_u((safe_add_func_uint8_t_u_u((safe_mul_func_int8_t_s_s((0x7CCE || (safe_mod_func_uint8_t_u_u(g_264, (safe_unary_minus_func_uint8_t_u((g_148 | l_456[0])))))), (((((l_1080 = (safe_lshift_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((safe_add_func_uint32_t_u_u(((safe_mul_func_int16_t_s_s((safe_add_func_uint16_t_u_u(((l_895 = 0x82D9) == (l_1079 = (p_50 | (0xCB & (safe_rshift_func_int16_t_s_u(((safe_lshift_func_uint8_t_u_s((safe_div_func_int16_t_s_s((g_644 = (~(safe_mul_func_int8_t_s_s((safe_mul_func_uint16_t_u_u((((((l_595 ^= (safe_mod_func_uint8_t_u_u(((safe_mul_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_u((+((((safe_mul_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((p_48 = 1U), p_50)), 0xDD)) & 1) >= g_944) == l_1076)), g_942[1][1])), g_126)) || l_1032), 0xF4))) & l_489) && 0) ^ p_47) ^ l_1077), 3U)), 0x76)))), p_50)), p_50)) == g_865), l_1078)))))), g_350)), 0x0B6C)) == p_47), l_1003[0][8])), 15)), l_969))) & (-6)) != g_147[1]) | l_994) | 1U))), 0xA6)), 0x9C));
                    }
                }
                else
                {
                    uint16_t l_1102 = 0xB0F7;
                    g_1084++;
                    g_375 = ((safe_lshift_func_int16_t_s_u((((l_1083 |= (safe_lshift_func_uint8_t_u_u((1 > g_2), 0))) >= ((safe_add_func_uint8_t_u_u((g_944 = (safe_sub_func_uint32_t_u_u((p_48 ^= p_46), g_1082))), (0x982CC75E && (((safe_div_func_int32_t_s_s((((safe_lshift_func_uint8_t_u_u(0x08, ((0x0C41F23A >= (l_1101 = (l_969 = g_126))) | l_1102))) | l_1003[0][7]) > g_274[5]), l_456[3])) <= p_47) <= 0x7F2D)))) || l_994)) < l_1103), p_50)) < p_47);
                    for (l_496 = 6; (l_496 >= 43); l_496 = safe_add_func_int32_t_s_s(l_496, 9))
                    {
                        g_375 = (safe_rshift_func_uint16_t_u_s(0xB500, 2));
                    }
                    l_1133 = (g_1132 = ((((safe_rshift_func_int8_t_s_s(0x4F, 2)) || l_1080) && (p_48 = (safe_div_func_int32_t_s_s((g_375 |= g_176), p_47)))) > ((g_213 >= (safe_mul_func_int8_t_s_s((safe_div_func_uint16_t_u_u(p_50, (l_569 ^= (safe_div_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u((((g_944 = (safe_lshift_func_uint8_t_u_s((g_1081[0] || ((l_455 = ((safe_rshift_func_uint16_t_u_u((l_895 = (g_1131 = ((safe_div_func_int8_t_s_s((safe_sub_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(0x37E1A0D4, (l_442 = (l_969 = (g_1130 |= g_272))))), l_540[0][3][1])), (-2))) & 0))), 15)) > p_46)) ^ 0xCD69)), g_171))) < p_49) != p_47), 65526U)), p_49))))), 1))) <= g_377)));
                }
                for (g_944 = 0; (g_944 != 51); ++g_944)
                {
                    int16_t l_1139 = 0;
                    int32_t l_1144 = 0x5BDD5A1C;
                    for (g_317 = 0; (g_317 < (-14)); g_317 = safe_sub_func_uint32_t_u_u(g_317, 1))
                    {
                        int16_t l_1138 = (-5);
                        int32_t l_1140 = 0x8C88BC6C;
                        int32_t l_1142 = 0x90C85C1A;
                        ++g_1146;
                        g_1131 = (-10);
                        g_1150--;
                    }
                    if ((((g_377 <= (-5)) < (safe_div_func_int16_t_s_s((safe_rshift_func_int16_t_s_s((safe_add_func_int16_t_s_s(p_48, ((((l_1133 || (-10)) && (safe_add_func_uint16_t_u_u((g_148 || g_944), 0x7F2A))) ^ (safe_mul_func_uint8_t_u_u(g_643[2][4][5], l_1163))) <= l_970))), p_47)), g_272))) != p_46))
                    {
                        int32_t l_1176 = 0xB68E56DC;

if ((g_266 = (((safe_div_func_int16_t_s_s((safe_div_func_int16_t_s_s((((g_1082 = (g_1082 = (safe_mul_func_int8_t_s_s((g_1323 = (g_265 = (g_1997 || (~((safe_mul_func_int16_t_s_s((((safe_lshift_func_int8_t_s_s((safe_mod_func_int16_t_s_s(3, g_1997)), 3)) > (safe_mod_func_uint8_t_u_u(l_1141, 0x2D))) && ((~(safe_add_func_int32_t_s_s(((safe_sub_func_int16_t_s_s(((((((safe_div_func_uint32_t_u_u((((((safe_mod_func_uint8_t_u_u(g_352, (safe_sub_func_uint16_t_u_u((safe_mul_func_int16_t_s_s((safe_rshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s(((safe_mod_func_int32_t_s_s(((safe_sub_func_uint8_t_u_u((safe_lshift_func_uint16_t_u_s(g_1420, (l_994 = 0x6350))), l_897)) != 0xFB), g_308)) | l_994), 6)), g_1420)), 65532U)), g_1150)))) | (-1)) == 0x0C013099) < 65535U) <= g_274[2]), (-1))) & 0x570B) == p_47) && 0U) >= g_1420) && g_147[3]), g_274[6])) ^ 0), 0xAC8FC47F))) == 4294967288U)), g_1419)) | 0xD4844485))))), (-1))))) < p_47) & g_265), l_456[5])), g_1866)) <= g_1130) | g_1420)))
        {
            uint8_t l_601 = 1U;
            int32_t l_610 = 1;
            uint32_t l_755 = 9U;
            int8_t l_836 = 0;
            uint8_t l_864[6][9][4] = {{{1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}}, {{1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}}, {{1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}}, {{1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}}, {{1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}}, {{1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}, {1U, 8U, 0xAB, 0x56}}};
            int32_t l_896 = 1;
            int32_t l_941 = 0;
            int32_t l_943[3][3] = {{0xD427FCA6, 1, 0xD427FCA6}, {0xD427FCA6, 1, 0xD427FCA6}, {0xD427FCA6, 1, 0xD427FCA6}};
            int i, j, k;
            if ((safe_mod_func_uint8_t_u_u(1U, l_456[1])))
            {
                uint8_t l_600 = 255U;
                int32_t l_604 = 4;
                int32_t l_605 = 0x191F9277;
                int8_t l_606 = 0x5A;
                int32_t l_611 = 1;
                int32_t l_612 = 1;
                const int16_t l_622 = 0xC6C8;
                if ((l_601 |= l_600))
                {
                    uint32_t l_607 = 0xF83F992C;
                    for (g_1082 = 20; (g_1082 >= (-16)); g_1082--)
                    {
                        ++l_607;
                    }
                }
                else
                {
                    int32_t l_618 = (-8);
                    if (l_897)
                        break;
                    ++g_148;
                    g_266 = (((safe_rshift_func_int16_t_s_s((l_618 = (0x14E0A851 == 7U)), 0)) == ((!(!g_308)) & (+g_1419))) != (l_622 == (++g_1323)));
                }
            }
            else
            {
                uint8_t l_636[10][2] = {{0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}, {0x63, 1U}};
                int32_t l_640 = 0x36AFFF2B;
                int32_t l_641 = (-1);
                int32_t l_642 = (-1);
                int i, j;
                if ((safe_add_func_uint16_t_u_u(l_610, g_274[1])))
                {
                    int32_t l_662[3][3];
                    int32_t l_677[1][3][10] = {{{0x559718EA, 1, (-1), 0x61261F33, 0x61261F33, (-1), 1, 0x559718EA, (-1), 0x559718EA}, {0x559718EA, 1, (-1), 0x61261F33, 0x61261F33, (-1), 1, 0x559718EA, (-1), 0x559718EA}, {0x559718EA, 1, (-1), 0x61261F33, 0x61261F33, (-1), 1, 0x559718EA, (-1), 0x559718EA}}};
                    int32_t l_740 = (-1);
                    int i, j, k;
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 0; j < 3; j++)
                            l_662[i][j] = 0xA6010A17;
                    }
                    g_266 = ((((safe_mod_func_int16_t_s_s((safe_add_func_uint8_t_u_u((safe_unary_minus_func_int16_t_s(g_1997)), (0x3B != ((l_540[2][5][0] > (l_994 |= (g_70 = 0x5135))) | (l_610 = 0xC7))))), (l_456[2] = (safe_add_func_uint16_t_u_u((g_1082 ^ (g_1420 < (g_553[0] || 65534U))), l_994))))) != l_636[8][0]) == l_636[8][1]) & g_1420);
                    for (g_308 = 0; (g_308 <= 23); g_308++)
                    {
                        int8_t l_639 = 0xF4;
                        int32_t l_645 = 0xE79238BF;
                        g_646[5]++;
                        g_266 &= ((safe_sub_func_int32_t_s_s(p_47, ((safe_sub_func_uint8_t_u_u((safe_unary_minus_func_int32_t_s(0x1A0E37F8)), ((safe_mul_func_int8_t_s_s(((safe_mul_func_uint16_t_u_u(3U, 65528U)) <= l_1080), (!(0x6620879A == ((((l_642 ^= 9) != (g_308 = (safe_mod_func_uint32_t_u_u(l_645, (((i && l_645) | l_540[3][3][1]) && l_661))))) || l_636[8][0]) || l_662[0][1]))))) | 0x90))) != g_643[2][4][4]))) || 0U);
                    }
                    if ((safe_add_func_uint16_t_u_u((l_662[0][1] || ((g_266 &= (((safe_lshift_func_uint16_t_u_u(l_601, (safe_mul_func_uint8_t_u_u(((safe_mod_func_int16_t_s_s((safe_lshift_func_int8_t_s_s((-3), 5)), (safe_mod_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u((++g_274[5]), l_641)) || (safe_div_func_int8_t_s_s((1U <= ((safe_mul_func_int16_t_s_s(((safe_mod_func_uint8_t_u_u(0x28, (g_1082 = 0x43))) > g_1420), (safe_mod_func_uint8_t_u_u(g_265, l_1077)))) ^ 0U)), 1))), p_47)))) && l_1080), 255U)))) ^ l_662[0][1]) == g_1997)) > 9U)), l_994)))
                    {
                        uint16_t l_697[5][2][3];
                        int i, j, k;
                        for (i = 0; i < 5; i++)
                        {
                            for (j = 0; j < 2; j++)
                            {
                                for (k = 0; k < 3; k++)
                                    l_697[i][j][k] = 0xA801;
                            }
                        }
                        g_266 &= ((safe_add_func_int8_t_s_s(((g_643[2][2][2] > (safe_lshift_func_uint8_t_u_s((safe_add_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(l_697[0][1][1], (safe_add_func_uint8_t_u_u(l_496, (safe_div_func_uint32_t_u_u((safe_add_func_uint8_t_u_u(((((l_610 = (g_1082 &= (((safe_mul_func_int16_t_s_s((safe_add_func_int8_t_s_s((((safe_lshift_func_int8_t_s_u((g_869 = ((safe_add_func_uint8_t_u_u((g_1150 = (((((((l_642 |= ((l_610 != (safe_rshift_func_uint16_t_u_u((((l_897 ^= (65526U >= (safe_mod_func_int32_t_s_s(g_1997, (g_1420 ^= l_641))))) <= (g_265 ^ (g_1323--))) ^ ((safe_mod_func_int8_t_s_s(((g_352 = ((safe_add_func_uint32_t_u_u((safe_div_func_int32_t_s_s(((safe_sub_func_int16_t_s_s((safe_add_func_int32_t_s_s((safe_add_func_uint32_t_u_u(((safe_mul_func_int8_t_s_s((safe_mul_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((safe_add_func_int32_t_s_s(g_1997, g_1130)), 0x1062D46E)), g_1997)), p_47)) > l_610), 0U)), g_646[3])), 1)) | g_1997), i)), 0x52250814)) <= g_1997)) >= p_47), l_496)) ^ g_1150)), 15))) <= 0)) <= l_661) == 0x6CC5ED28) || 0x232E) && 0x1C888861) == g_1420) & 0U)), g_646[7])) > l_636[9][0])), 4)) == (-1)) | g_1130), 0x73)), g_143)) & g_308) != g_1130))) <= g_265) != l_740) >= 4U), g_1997)), l_697[0][1][1])))))), p_47)), l_601))) >= l_697[4][0][2]), 0)) <= p_47);
                        l_610 ^= g_1150;
                        return g_265;
                    }
                    else
                    {
                        return g_1150;
                    }
                }
                else
                {
                    uint32_t l_810 = 0x32D066A9;
                    int32_t l_811[6][10] = {{(-10), (-10), 9, 0x5B68EDB2, 6, (-1), 0x5CAB97CD, (-10), 0x370FCE42, 0x5CAB97CD}, {(-10), (-10), 9, 0x5B68EDB2, 6, (-1), 0x5CAB97CD, (-10), 0x370FCE42, 0x5CAB97CD}, {(-10), (-10), 9, 0x5B68EDB2, 6, (-1), 0x5CAB97CD, (-10), 0x370FCE42, 0x5CAB97CD}, {(-10), (-10), 9, 0x5B68EDB2, 6, (-1), 0x5CAB97CD, (-10), 0x370FCE42, 0x5CAB97CD}, {(-10), (-10), 9, 0x5B68EDB2, 6, (-1), 0x5CAB97CD, (-10), 0x370FCE42, 0x5CAB97CD}, {(-10), (-10), 9, 0x5B68EDB2, 6, (-1), 0x5CAB97CD, (-10), 0x370FCE42, 0x5CAB97CD}};
                    int i, j;
                    if ((safe_mod_func_int32_t_s_s(0xDBE4D7E6, (safe_lshift_func_int8_t_s_u((-1), (safe_add_func_int16_t_s_s((safe_mul_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s((0 > (65532U | ((safe_lshift_func_uint16_t_u_s(65535U, 14)) != (g_1082 = 0)))), 1)), l_755)), 0x662D)))))))
                    {
                        g_266 = ((safe_unary_minus_func_int8_t_s((g_477 = (-4)))) & (((safe_div_func_int8_t_s_s((p_47 <= (254U <= (safe_sub_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_u(0xC0, 7)) == (l_610 = (safe_lshift_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_u((g_1323 &= (--g_1150)), 3)), (g_643[2][2][2] = g_70))), p_47)))), (l_641 = (safe_lshift_func_int16_t_s_s(((g_308 ^= (l_636[7][0] || g_553[1])) | 0x4C94), g_1130))))))), 0xD0)) ^ 0xB7) >= 0U));
                    }
                    else
                    {
                        uint32_t l_786[4];
                        int32_t l_812 = (-8);
                        int i;
                        for (i = 0; i < 4; i++)
                            l_786[i] = 8U;
                        l_786[3] = (safe_add_func_int16_t_s_s((safe_mul_func_uint8_t_u_u(g_1419, (safe_sub_func_int8_t_s_s(1, (safe_mod_func_uint16_t_u_u(l_1141, (safe_mod_func_uint8_t_u_u(246U, 0xD8)))))))), (0x3B84E7ED > g_1420)));
                        l_812 = ((safe_mod_func_int32_t_s_s((g_308 = ((((safe_unary_minus_func_uint32_t_u((safe_mul_func_uint8_t_u_u(((l_811[3][4] |= ((safe_rshift_func_int16_t_s_u((safe_div_func_int16_t_s_s(g_643[0][2][6], (safe_sub_func_int16_t_s_s(((safe_lshift_func_uint16_t_u_u(g_147[1], 15)) >= (safe_mul_func_int8_t_s_s(0xED, 0x20))), g_70)))), 2)) != (safe_sub_func_uint8_t_u_u((l_786[3] | (safe_add_func_int16_t_s_s(((g_1420 & (l_496 <= (safe_rshift_func_uint8_t_u_u((l_456[1] = g_477), 6)))) == g_1997), l_810))), g_1866)))) || g_1420), 1U)))) || 1) == p_47) | 0xBC09786F)), 0xBBA88CD8)) >= l_755);
                    }
                    if (((safe_sub_func_int32_t_s_s((0U == (safe_add_func_int32_t_s_s((safe_add_func_uint8_t_u_u(0x04, (safe_lshift_func_int8_t_s_s((((g_148 = (safe_mul_func_uint8_t_u_u(0U, (g_308 = ((safe_add_func_int16_t_s_s(g_646[5], ((safe_sub_func_int32_t_s_s((l_610 = l_456[5]), (--g_147[0]))) ^ ((!l_897) & g_352)))) & (((safe_div_func_uint8_t_u_u(l_897, (g_1150 = (safe_rshift_func_uint8_t_u_u((l_836 ^= (safe_rshift_func_int8_t_s_s(((((0x85 ^ 2) < (-10)) | 2) | 0x143B679D), p_47))), 3))))) < 0U) ^ g_1082)))))) == 0x8B) <= 0), 2)))), p_47))), l_636[8][0])) <= l_755))
                    {
                        g_266 = ((((safe_lshift_func_uint16_t_u_u((safe_mul_func_uint16_t_u_u((((l_642 = (safe_mul_func_int16_t_s_s((l_610 &= l_601), ((safe_lshift_func_uint8_t_u_s((safe_add_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((safe_rshift_func_int16_t_s_u(((safe_mod_func_uint8_t_u_u((((g_308 ^= (((!(g_308 = (251U || ((((+g_1082) && (safe_div_func_uint16_t_u_u(1U, 0x19D5))) || (safe_mod_func_uint16_t_u_u((g_643[2][2][2] ^ (((safe_rshift_func_int8_t_s_u((safe_div_func_uint16_t_u_u(l_640, i)), (((safe_unary_minus_func_uint8_t_u(0x79)) >= 255U) || g_643[2][2][2]))) || g_1420) & l_994)), g_1420))) | l_897)))) >= g_553[0]) || g_1997)) <= l_1080) == g_308), g_646[0])) != i), g_646[0])), 6)), l_864[0][7][3])), 4)) < 0xBF88)))) >= l_810) & 1), l_864[5][0][0])), 15)) | (-1)) && g_1084) >= g_1323);
                        g_266 |= g_1420;
                        ++g_350;
                        l_641 = g_944;
                    }
                    else
                    {
                        g_266 |= 8;
                        l_811[4][4] &= (-1);
                        return g_308;
                    }
                    if (g_308)
                        continue;
                    for (g_308 = 4; (g_308 >= 0); g_308 -= 1)
                    {
                        int i;
                        if (l_456[(g_308 + 1)])
                            break;
                    }
                }
                if (l_610)
                    break;
                return g_646[5];
            }
            --g_143;
            l_896 = ((safe_mul_func_uint8_t_u_u((((g_1420 = 0x98FCCAFC) > (l_610 = (l_1080 = ((l_1080 = (l_1141 || ((g_308 = (g_1419 = (g_308 = (safe_add_func_int32_t_s_s((safe_div_func_uint8_t_u_u(((((safe_lshift_func_int8_t_s_u((g_148 && (safe_add_func_uint32_t_u_u(((((safe_div_func_uint16_t_u_u((g_894[3][1] &= (((l_456[3] &= (safe_add_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u((l_1141 = (safe_sub_func_int16_t_s_s((~(l_540[0][3][1] != g_147[0])), l_897))), 12)), g_646[2]))) && (l_897 = (safe_unary_minus_func_int8_t_s(l_1080)))) | (safe_mul_func_int16_t_s_s((g_147[6] > l_1141), g_148)))), l_994)) & g_1420) || g_894[3][1]) ^ g_1082), g_1150))), g_1997)) == l_836) ^ g_944) >= g_274[5]), l_540[7][6][1])), l_1141))))) != g_1323))) > (-1))))) ^ g_1323), 1)) | l_1080);
            if (l_897)
            {
                --g_1420;
            }
            else
            {
                uint32_t l_937 = 0U;
                for (l_1080 = 0; (l_1080 < (-21)); l_1080 = safe_sub_func_int32_t_s_s(l_1080, 1))
                {
                    uint32_t l_913 = 0x534F98FD;
                    int32_t l_917[7][9] = {{(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}, {(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}, {(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}, {(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}, {(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}, {(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}, {(-8), 0x058ED3EC, 3, 0xD5A8D379, (-3), (-1), 1, 0x476055A2, 0x994FCAFA}};
                    int32_t l_919 = 0x92FB3904;
                    int i, j;
                    for (l_1080 = 5; (l_1080 >= 1); l_1080 -= 1)
                    {
                        int i;
                        g_266 ^= ((l_456[l_1080] = (~(l_919 = ((l_917[1][0] ^= ((g_646[(l_1080 + 2)] && (l_456[l_1080] >= (safe_div_func_int32_t_s_s((+(((safe_mul_func_int8_t_s_s(((safe_mul_func_uint8_t_u_u((l_456[l_1080] && (l_1141 < 1U)), g_306)) && ((+l_913) ^ (safe_lshift_func_uint16_t_u_s((9U >= (g_1146 && g_869)), 14)))), 1U)) > g_1866) >= g_1082)), g_1997)))) >= l_897)) == g_1857)))) && g_1323);
                        if (g_1150)
                            continue;
                        g_1419 = (l_994 <= g_1132);
                    }
                    g_308 = g_944;
                    j = (safe_lshift_func_uint8_t_u_s(254U, 1));
                    l_1080 |= (g_1997 != (safe_lshift_func_uint8_t_u_s(((safe_sub_func_uint8_t_u_u(l_897, (l_937 |= (safe_mul_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((l_864[3][0][0] && (safe_mul_func_uint16_t_u_u((+l_601), (safe_sub_func_uint32_t_u_u(l_919, l_864[0][7][3]))))), l_1080)), g_352))))) & ((safe_rshift_func_uint8_t_u_s(g_553[1], 0)) ^ l_897)), g_1420)));
                }
                --g_944;
            }
        }
        else
        {
            uint8_t l_953 = 1U;
            int32_t l_957 = 0x19442117;
            uint8_t l_958 = 1U;
            l_957 = (safe_mod_func_uint32_t_u_u((((safe_rshift_func_uint16_t_u_s((safe_add_func_uint32_t_u_u(g_1150, ((g_1419 &= (l_953++)) != l_994))), 15)) || l_1080) != (l_897 = 0xCA)), 4294967294U));
            ++l_958;
            g_266 = g_1857;
        };


                    l_569 = (l_456[3] < ((((safe_rshift_func_int16_t_s_u(p_47, 11)) < (l_1133 || (((l_442 ^= (safe_lshift_func_int8_t_s_s(g_377, 0))) <= (safe_sub_func_int32_t_s_s((g_1131 = 0xEC78FD24), 0x8735C8C4))) ^ (l_969 |= (safe_div_func_int16_t_s_s((g_1130 ^ (safe_mul_func_int8_t_s_s(l_569, ((l_455 = (safe_div_func_uint16_t_u_u((0x7770 && l_1144), g_83))) == l_920)))), g_1081[0])))))) & l_1176) >= g_376));
                    }
                    else
                    {
                        l_1083 |= (l_456[3] &= p_48);
                    }
                }
            }
            else
            {
                uint8_t l_1183 = 0x14;
                g_1149 ^= (safe_mul_func_int16_t_s_s((((safe_mod_func_uint32_t_u_u(((safe_sub_func_uint8_t_u_u(l_1183, (0x3F < (-4)))) || (safe_mod_func_uint32_t_u_u(((4294967292U == (safe_sub_func_uint32_t_u_u((g_176 = (safe_mod_func_int16_t_s_s(((l_1183 != l_918) | (l_489 & 0x1DE8EC7A)), (l_969 = (((safe_unary_minus_func_int8_t_s(p_48)) >= 1U) ^ g_894[1][3]))))), 0U))) | l_918), p_47))), p_50)) <= g_265) >= p_47), p_49));
                if (l_1183)
                    break;
            }
        }
    }

{
                    int32_t l_1746 = 0x33CF0918;
                    int32_t l_1782[2][4] = {{0x8A84389D, 1, 0x8A84389D, 1}, {0x8A84389D, 1, 0x8A84389D, 1}};
                    int i, j;
                    if ((safe_mod_func_int8_t_s_s(((g_274[l_569] < (g_1420 >= g_274[l_569])) <= 0x3E95), (((safe_mod_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(((g_477 & ((safe_lshift_func_uint16_t_u_u(((safe_unary_minus_func_uint16_t_u((l_455 = g_274[l_569]))) < ((((safe_unary_minus_func_uint32_t_u((1 | (~(((((l_569 | ((((safe_div_func_int8_t_s_s((((!(((safe_add_func_uint32_t_u_u((+((safe_div_func_uint16_t_u_u(l_897, g_1866)) & g_2740)), l_897)) > 0xC4) & l_569)) | g_70) != g_274[l_569]), l_739)) && 7) && g_894[3][1]) < 2)) == 0xA1F1BBD8) <= 4294967295U) < l_569) && g_643[2][2][2]))))) & 4294967292U) <= 65535U) != p_49)), 3)) < (-1))) >= (-10)), g_2740)), 0x49)) > g_2740) & g_1419))))
                    {
                        int8_t l_1726 = (-5);
                        int32_t l_1733 = (-1);
                        int i;
                        l_455 |= (g_1419 = ((safe_lshift_func_int16_t_s_s((((safe_div_func_int8_t_s_s((0x09 == (((safe_mul_func_uint16_t_u_u((g_1442[4][2]++), (((((safe_mul_func_int16_t_s_s((g_1979 && ((0x94DE060A == (g_1419 = (l_1746 = ((l_1733 = l_569) & (((safe_sub_func_int8_t_s_s((safe_mul_func_uint16_t_u_u((safe_div_func_int16_t_s_s((g_1143[2][0][6] = l_455), (safe_mod_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s(4U, 12)), ((g_646[l_569] = (safe_mul_func_int16_t_s_s(p_49, 0x6084))) | ((0x473F79E0 <= g_1081[0]) <= l_442)))))), g_1419)), g_147[2])) ^ g_1526) || g_70))))) >= 3)), g_147[0])) < 0x01) < l_496) & g_264) > g_308))) != g_1866) | g_274[l_569])), g_264)) >= 4294967286U) || l_569), 4)) & 0x238F));
                        l_455 = g_1323;
                    }
                    else
                    {
                        g_272 = (safe_mod_func_int16_t_s_s(g_1526, (safe_sub_func_int8_t_s_s(0x71, g_274[l_569]))));
                    }
                    l_569 &= (safe_mul_func_uint16_t_u_u((l_455 & ((safe_sub_func_int8_t_s_s((-2), (((((safe_mul_func_int16_t_s_s(6, (g_1084 == (((safe_div_func_int32_t_s_s((safe_mul_func_uint8_t_u_u((safe_lshift_func_int8_t_s_u((safe_rshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u(g_1081[0], (safe_add_func_int8_t_s_s((safe_mod_func_int16_t_s_s(0x5D22, (++g_1442[1][4]))), (g_373 = (l_569 || (safe_mul_func_int8_t_s_s(((safe_sub_func_int8_t_s_s((safe_div_func_uint32_t_u_u(p_49, l_739)), g_147[0])) ^ l_739), g_147[5])))))))), 1)), l_1782[0][0])), g_1419)), l_688)) & 0x53FED7A1) && l_897)))) > g_1081[0]) || l_739) > l_739) >= l_455))) <= 0)), 6U));
                }

                    return p_49;
}







static uint32_t func_54(int8_t p_55, uint8_t p_56, int32_t p_57, uint8_t p_58, int32_t p_59)
{
    uint32_t l_366[6][7][6] = {{{1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}}, {{1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}}, {{1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}}, {{1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}}, {{1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}}, {{1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}, {1U, 4294967295U, 5U, 4294967295U, 1U, 0x6ABE45C5}}};
    int32_t l_374[7] = {0, (-1), 0, (-1), 0, (-1), 0};
    int i, j, k;
    if (((l_374[1] = (g_306 == ((safe_sub_func_uint16_t_u_u(0xD281, ((((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint8_t_u_s(((safe_rshift_func_uint8_t_u_u(((p_58 || (l_366[0][5][5] < ((((((safe_mul_func_int8_t_s_s(((safe_sub_func_int32_t_s_s(((l_366[0][5][5] < g_274[4]) | ((safe_rshift_func_uint8_t_u_s((((l_366[0][5][5] != ((g_70 &= (-7)) <= 0x4814)) >= p_57) >= 0xE210), 2)) && l_366[0][5][5])), l_366[0][5][5])) >= p_55), g_147[0])) | g_143) <= l_366[1][4][2]) == 0x24FC) <= 0xF8) >= l_366[5][2][0]))) <= g_373), p_59)) == g_148), p_58)) > 0), g_317)) | p_57) == g_308) || l_366[0][5][1]))) != p_58))) == 0xDDF00D99))
    {
        g_377++;
    }
    else
    {
        int32_t l_380 = 0x152840A7;
        if (l_380)
        {
            uint16_t l_387 = 65532U;
            int32_t l_407[6];
            int i;
            for (i = 0; i < 6; i++)
                l_407[i] = 0x34898C60;

for (l_380 = 0; l_380 < 7; l_380++)
    {
        transparent_crc(g_147[l_380], "g_147[l_380]", g_272);
        if (g_272) printf("index = [%d]\n", l_380);

    };


                    g_375 &= (safe_mod_func_int8_t_s_s(p_57, 0xDC));
            for (g_268 = 0; (g_268 > 42); ++g_268)
            {
                g_375 = (((safe_div_func_uint32_t_u_u((l_387 = 0x8B259D47), (safe_lshift_func_uint8_t_u_s(((safe_rshift_func_int16_t_s_u((l_380 > (safe_mul_func_int16_t_s_s(g_83, (l_374[1] || (l_380 < (((safe_sub_func_uint8_t_u_u((((safe_rshift_func_int8_t_s_s((safe_div_func_int8_t_s_s(((l_374[6] >= ((safe_rshift_func_int16_t_s_s(l_380, 7)) & (safe_lshift_func_int16_t_s_s((((g_264 != (p_55 &= (safe_sub_func_int32_t_s_s((safe_unary_minus_func_int8_t_s(g_274[5])), g_147[0])))) >= g_352) && p_55), 7)))) && g_377), 0x2A)), p_58)) & 6) & p_57), 6)) <= l_407[5]) || g_268)))))), p_59)) == g_377), 1)))) != 9) | p_58);
                g_375 = (safe_lshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u(p_57, 7)), 1));
            }
        }
        else
        {
            l_374[1] &= ((safe_div_func_uint32_t_u_u((safe_sub_func_int8_t_s_s((safe_div_func_int16_t_s_s(1, (safe_add_func_uint32_t_u_u((safe_mul_func_int16_t_s_s(p_58, 0x6255)), (0xF6 != ((safe_rshift_func_int8_t_s_u((1 && ((g_350 <= (safe_sub_func_uint16_t_u_u(((safe_mul_func_int16_t_s_s((g_213 = g_213), 65532U)) ^ (--g_143)), 1))) | p_55)), 1)) > 0xBEA4E39C)))))), 0xD5)), g_140)) > p_58);
            return g_266;
        }
    }
    return g_268;
}







static int32_t func_61(int32_t p_62, uint8_t p_63, uint32_t p_64)
{
    int16_t l_69 = 0x6135;
    int32_t l_71 = (-9);
    uint16_t l_261[6] = {0x32A3, 0x32A3, 0x3F15, 0x32A3, 0x32A3, 0x3F15};
    int16_t l_262[6];
    int32_t l_267 = 0x13B45988;
    uint8_t l_304[9][3][9] = {{{247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}}, {{247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}}, {{247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}}, {{247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}}, {{247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}}, {{247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}}, {{247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}}, {{247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}}, {{247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}, {247U, 0U, 0x75, 0x48, 1U, 0x8D, 0xF0, 0U, 0x3D}}};
    int32_t l_305 = 0x3608916A;
    int32_t l_307[4] = {0x9892BBAF, 0xBA40AD9B, 0x9892BBAF, 0xBA40AD9B};
    int32_t l_323[2][2];
    int16_t l_351 = 0x3A52;
    int32_t l_353[6] = {0x95F37937, 0xD3D24E7D, 0x95F37937, 0xD3D24E7D, 0x95F37937, 0xD3D24E7D};
    int16_t l_354 = 9;
    int32_t l_355 = 8;
    int32_t l_356 = 0x9964395A;
    int32_t l_357 = 5;
    int i, j, k;
    for (i = 0; i < 6; i++)
        l_262[i] = 0;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            l_323[i][j] = 0;
    }
    for (p_63 = (-1); (p_63 >= 45); p_63 = safe_add_func_int8_t_s_s(p_63, 1))
    {
        uint8_t l_72 = 1U;
        int32_t l_81 = 0x11EAE524;
        int32_t l_82 = 0x3BFA4ACF;
        uint32_t l_111 = 0U;
        int32_t l_273 = 0;
        l_72++;
        g_148 = (safe_lshift_func_uint16_t_u_u((safe_rshift_func_int16_t_s_s(1, 6)), ((p_64 != ((safe_mul_func_uint16_t_u_u(((g_83--) > (safe_mod_func_int32_t_s_s((func_88((safe_add_func_int32_t_s_s((safe_mul_func_uint16_t_u_u(((safe_rshift_func_int16_t_s_s((g_70 = g_2), 1)) && 0U), (0xAF != ((safe_rshift_func_uint8_t_u_s((safe_rshift_func_uint8_t_u_u((!(((p_62 == (((safe_add_func_int8_t_s_s((safe_sub_func_uint16_t_u_u((safe_lshift_func_int8_t_s_s(l_71, ((safe_rshift_func_uint8_t_u_s((((l_82 = ((0x10B3F497 > (safe_mul_func_uint16_t_u_u(0U, l_72))) < 0xDFEB8596)) == g_2) ^ (-9)), 4)) || p_64))), l_111)), l_71)) || p_62) < 0)) < p_62) < g_2)), 3)), g_2)) < p_64)))), l_71))) < l_81), p_62))), g_2)) == 0x7C47)) & l_72)));
        if (((safe_lshift_func_int16_t_s_s(((l_69 ^ p_62) < g_143), 5)) > p_62))
        {
            int8_t l_259 = (-1);
            int32_t l_271 = 0x8605FCFF;
            for (l_69 = 6; (l_69 >= 0); l_69 -= 1)
            {
                int32_t l_153[7][3] = {{0, 0x3A2C9E81, (-1)}, {0, 0x3A2C9E81, (-1)}, {0, 0x3A2C9E81, (-1)}, {0, 0x3A2C9E81, (-1)}, {0, 0x3A2C9E81, (-1)}, {0, 0x3A2C9E81, (-1)}, {0, 0x3A2C9E81, (-1)}};
                int32_t l_263 = 0xDBAB105A;
                int i, j;
                if ((safe_sub_func_uint16_t_u_u(65535U, ((-1) == g_147[l_69]))))
                {
                    l_153[1][0] = ((g_83 = 252U) == p_63);
                }
                else
                {
                    if ((safe_lshift_func_uint8_t_u_s(l_71, 1)))
                    {
                        if (p_64)
                            break;
                        l_81 ^= p_64;
                    }
                    else
                    {
                        int16_t l_170 = 0x9F55;
                        g_171 = (safe_add_func_int16_t_s_s(p_64, (l_82 = ((safe_mod_func_uint16_t_u_u(0x387A, 0xF8E3)) || ((+(~(-10))) && (safe_div_func_uint32_t_u_u((safe_rshift_func_int8_t_s_s(((0 || (safe_sub_func_int16_t_s_s(g_148, (safe_lshift_func_uint16_t_u_u(0xF6D2, 8))))) | l_170), ((g_70 = (p_63 != g_2)) > g_83))), p_62)))))));
                    }
                }
                for (l_81 = 6; (l_81 >= 0); l_81 -= 1)
                {
                    uint32_t l_189[3][7] = {{0x40B77385, 0xE761F95E, 0x40B77385, 0xE761F95E, 0x40B77385, 0xE761F95E, 0x40B77385}, {0x40B77385, 0xE761F95E, 0x40B77385, 0xE761F95E, 0x40B77385, 0xE761F95E, 0x40B77385}, {0x40B77385, 0xE761F95E, 0x40B77385, 0xE761F95E, 0x40B77385, 0xE761F95E, 0x40B77385}};
                    int32_t l_214 = (-1);
                    int i, j;
                    for (g_140 = 2; (g_140 >= 0); g_140 -= 1)
                    {
                        int i, j;
                        l_71 |= (safe_mul_func_int16_t_s_s(g_147[l_81], (safe_div_func_int16_t_s_s((0xCD ^ (l_153[l_81][g_140] <= 0x2541)), 0x4B80))));
                        g_176 = g_70;
                        l_71 = ((safe_mod_func_uint8_t_u_u(g_126, (l_111 || p_63))) >= p_64);
                        if (g_148)
                            continue;
                    }
                    for (g_171 = 2; (g_171 <= 6); g_171 += 1)
                    {
                        int32_t l_239[8] = {(-1), 3, (-1), 3, (-1), 3, (-1), 3};
                        uint32_t l_258 = 0xA5245C12;
                        uint16_t l_260[2][2];
                        int i, j;
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 2; j++)
                                l_260[i][j] = 0xD8A5;
                        }
                        l_214 ^= (safe_lshift_func_uint16_t_u_s(65533U, (safe_rshift_func_int8_t_s_u((safe_sub_func_int32_t_s_s((safe_sub_func_uint8_t_u_u(0U, (l_189[0][6] |= ((0x73F7 < (safe_lshift_func_int16_t_s_s(g_147[l_69], 8))) == g_148)))), ((safe_rshift_func_uint16_t_u_s((((g_176 > (safe_add_func_int8_t_s_s((((g_147[l_69] <= (safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((g_213 = ((l_82 = ((safe_lshift_func_uint16_t_u_u((+(((g_176 != (safe_div_func_int8_t_s_s((safe_div_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u(((safe_mul_func_uint8_t_u_u((safe_div_func_int16_t_s_s((((safe_rshift_func_uint8_t_u_s(0xBF, p_64)) == l_111) | p_64), 0xADDF)), p_62)) < g_126), l_82)), 0xECD9)), g_70))) == l_153[4][1]) <= l_111)), p_62)) ^ g_83)) || p_64)), 0xE6562F83)), 0xA6))) > l_81) && 65535U), 251U))) > 0xD3) >= p_62), 14)) || g_171))), 6))));
                        l_82 = ((safe_lshift_func_int16_t_s_u((safe_lshift_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_u((safe_rshift_func_int8_t_s_u(((((safe_sub_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((safe_sub_func_uint32_t_u_u((0x2A0A < (l_153[5][1] = (safe_mul_func_uint8_t_u_u(((l_72 > (g_265 &= (safe_add_func_int16_t_s_s((((l_214 = ((safe_lshift_func_int8_t_s_s((safe_lshift_func_uint16_t_u_s(3U, ((g_213 &= g_126) | 0xDAE2))), g_143)) >= ((l_239[7] || (safe_mod_func_int32_t_s_s((g_264 = (((((g_176 |= (g_147[l_69]--)) <= (-1)) || (l_263 = (safe_rshift_func_int16_t_s_s(((safe_mul_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((safe_add_func_uint8_t_u_u((safe_lshift_func_int16_t_s_u((((safe_add_func_uint32_t_u_u(((safe_sub_func_int8_t_s_s(l_258, 255U)) != p_63), l_259)) == g_70) || p_64), l_260[1][1])), l_261[1])), 4)), l_262[4])) >= g_126), g_140)))) >= l_153[1][0]) && 248U)), p_64))) ^ l_261[1]))) <= 0xB854) >= g_126), 0x1F13)))) == 255U), 0x08)))), p_63)), p_63)), p_63)), p_63)) ^ p_64) == 4) || g_176), g_126)), 1)) & l_189[0][6]), g_143)), 11)) | l_259);
                        if (p_62)
                            break;
                        g_268++;
                    }
                }
                for (p_62 = 0; (p_62 <= 6); p_62 += 1)
                {
                    l_271 = 0x4E4277A2;
                    for (l_71 = 6; (l_71 >= 0); l_71 -= 1)
                    {
                        l_271 = 0x8F982563;
                    }
                }
                --g_274[5];
            }
        }
        else
        {
            return p_64;
        }
    }
    l_307[2] ^= (safe_mul_func_int8_t_s_s(((g_306 = (((safe_mul_func_uint8_t_u_u(((safe_lshift_func_int16_t_s_s(((safe_sub_func_uint8_t_u_u(l_69, (safe_lshift_func_int8_t_s_u(l_261[1], (((g_147[2] && 6) <= (0x9C & ((0U >= (~((safe_div_func_int8_t_s_s(g_147[0], (g_274[6] & ((safe_mul_func_int8_t_s_s((safe_lshift_func_int8_t_s_u((l_71 = (safe_mod_func_int32_t_s_s((safe_div_func_int8_t_s_s(((((safe_mul_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u((p_63 = ((safe_rshift_func_int8_t_s_u(((l_261[1] | 0x52B6) == g_83), p_63)) ^ 1)), l_261[1])), l_267)) ^ 0x689637CC) <= l_304[2][0][7]) || g_274[5]), g_274[5])), l_305))), g_140)), 0x15)) >= p_64)))) < g_264))) > p_62))) == l_262[4]))))) || p_64), g_268)) >= 0x7A), l_262[4])) <= l_261[1]) & l_261[4])) & p_62), g_268));
    l_323[0][1] = ((g_265 = ((g_308 = l_262[3]) ^ l_307[2])) & (safe_div_func_int16_t_s_s((l_267 ^= (((safe_sub_func_uint32_t_u_u((safe_mul_func_int8_t_s_s(l_307[2], p_62)), ((safe_rshift_func_uint16_t_u_u(g_317, (safe_mod_func_int8_t_s_s(l_307[2], g_126)))) ^ (l_71 = (+((safe_lshift_func_uint16_t_u_u((p_64 < 247U), 6)) ^ l_262[1])))))) ^ p_62) | 0x95)), p_64)));
    l_357 = ((l_356 = (((l_355 = (safe_sub_func_uint16_t_u_u(((l_323[0][1] = g_2) && (l_71 = ((safe_mul_func_int16_t_s_s(0, g_83)) <= (((safe_rshift_func_int16_t_s_u((safe_mul_func_int8_t_s_s((safe_div_func_int32_t_s_s((l_305 < (l_323[0][1] |= l_261[1])), (l_353[4] &= (safe_mul_func_uint8_t_u_u(l_305, ((safe_sub_func_uint8_t_u_u((safe_div_func_int16_t_s_s(p_64, (safe_sub_func_int32_t_s_s((g_352 = (((safe_lshift_func_int16_t_s_u((l_267 = (p_62 | (((safe_unary_minus_func_int8_t_s((((safe_sub_func_uint32_t_u_u((safe_lshift_func_uint8_t_u_s((+(g_350 ^= l_71)), g_308)), l_305)) || 0xAACF) != l_304[2][0][7]))) || p_62) ^ p_63))), l_262[4])) == 4U) >= l_351)), g_272)))), 0x92)) > p_64)))))), p_63)), l_354)) < l_261[3]) != p_64)))), 0x9E44))) < l_307[2]) && g_126)) >= g_317);
    return g_268;
}







inline static const uint16_t func_88(const int32_t p_89)
{
    uint32_t l_118[4] = {0x8B44A659, 0xB19522E6, 0x8B44A659, 0xB19522E6};
    int32_t l_129[7][9][3] = {{{1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}}, {{1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}}, {{1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}}, {{1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}}, {{1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}}, {{1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}}, {{1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}, {1, (-5), (-4)}}};
    int32_t l_142 = (-3);
    int i, j, k;
    for (g_70 = 0; (g_70 < (-15)); g_70 = safe_sub_func_int16_t_s_s(g_70, 7))
    {
        uint32_t l_121[5];
        int32_t l_130 = (-1);
        int32_t l_141 = (-1);
        int i;
        for (i = 0; i < 5; i++)
            l_121[i] = 1U;
        l_142 = (safe_add_func_uint32_t_u_u((safe_add_func_int32_t_s_s((l_118[1] |= p_89), g_2)), ((safe_mul_func_uint16_t_u_u(((l_121[0] <= (safe_mod_func_uint32_t_u_u((g_126 = (safe_mod_func_uint32_t_u_u(g_70, l_121[1]))), (safe_sub_func_uint32_t_u_u((((l_129[2][3][0] || (l_130 = 5U)) != ((l_141 = ((safe_mod_func_uint32_t_u_u((((+((4294967295U >= (safe_add_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s((g_140 = (safe_mul_func_uint8_t_u_u(g_2, p_89))), g_70)), p_89))) == p_89)) ^ g_70) & g_2), p_89)) == g_2)) == g_2)) >= l_121[3]), 4294967291U))))) == l_121[0]), 0xD0C0)) < 0xEFBA)));
        if (g_2)
        {
            g_143--;

{
            uint8_t l_146 = 0x9C;
            for (g_375 = 4; (g_375 >= 0); g_375 -= 1)
            {
                int i;
                return l_121[g_375];
            }
            if (l_146)
                break;
        }

                l_130 = 0x02534006;
            l_130 &= (l_142 = (0xE8 == (g_143 | p_89)));
        }
        else
        {
            uint8_t l_146 = 0x9C;
            for (l_141 = 4; (l_141 >= 0); l_141 -= 1)
            {
                int i;
                return l_121[l_141];
            }
            if (l_146)
                break;
        }
        g_147[0] = l_121[0];
        l_141 = g_140;
    }
    return l_118[2];
}





int main (void)
{
    int i, j, k;
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_70, "g_70", print_hash_value);
    transparent_crc(g_83, "g_83", print_hash_value);
    transparent_crc(g_126, "g_126", print_hash_value);
    transparent_crc(g_140, "g_140", print_hash_value);
    transparent_crc(g_143, "g_143", print_hash_value);
    for (i = 0; i < 7; i++)
    {
        transparent_crc(g_147[i], "g_147[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_148, "g_148", print_hash_value);
    transparent_crc(g_171, "g_171", print_hash_value);
    transparent_crc(g_176, "g_176", print_hash_value);
    transparent_crc(g_213, "g_213", print_hash_value);
    transparent_crc(g_264, "g_264", print_hash_value);
    transparent_crc(g_265, "g_265", print_hash_value);
    transparent_crc(g_266, "g_266", print_hash_value);
    transparent_crc(g_268, "g_268", print_hash_value);
    transparent_crc(g_272, "g_272", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_274[i], "g_274[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_306, "g_306", print_hash_value);
    transparent_crc(g_308, "g_308", print_hash_value);
    transparent_crc(g_317, "g_317", print_hash_value);
    transparent_crc(g_350, "g_350", print_hash_value);
    transparent_crc(g_352, "g_352", print_hash_value);
    transparent_crc(g_373, "g_373", print_hash_value);
    transparent_crc(g_375, "g_375", print_hash_value);
    transparent_crc(g_376, "g_376", print_hash_value);
    transparent_crc(g_377, "g_377", print_hash_value);
    transparent_crc(g_477, "g_477", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_553[i], "g_553[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_613, "g_613", print_hash_value);
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 5; j++)
        {
            for (k = 0; k < 7; k++)
            {
                transparent_crc(g_643[i][j][k], "g_643[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_644, "g_644", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_646[i], "g_646[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_738, "g_738", print_hash_value);
    transparent_crc(g_865, "g_865", print_hash_value);
    transparent_crc(g_866, "g_866", print_hash_value);
    transparent_crc(g_869, "g_869", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            transparent_crc(g_894[i][j], "g_894[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_898, "g_898", print_hash_value);
    transparent_crc(g_911, "g_911", print_hash_value);
    transparent_crc(g_940, "g_940", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transparent_crc(g_942[i][j], "g_942[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_944, "g_944", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_1081[i], "g_1081[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_1082, "g_1082", print_hash_value);
    transparent_crc(g_1084, "g_1084", print_hash_value);
    transparent_crc(g_1130, "g_1130", print_hash_value);
    transparent_crc(g_1131, "g_1131", print_hash_value);
    transparent_crc(g_1132, "g_1132", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 1; j++)
        {
            for (k = 0; k < 8; k++)
            {
                transparent_crc(g_1143[i][j][k], "g_1143[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_1146, "g_1146", print_hash_value);
    transparent_crc(g_1149, "g_1149", print_hash_value);
    transparent_crc(g_1150, "g_1150", print_hash_value);
    transparent_crc(g_1247, "g_1247", print_hash_value);
    transparent_crc(g_1323, "g_1323", print_hash_value);
    transparent_crc(g_1419, "g_1419", print_hash_value);
    transparent_crc(g_1420, "g_1420", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            transparent_crc(g_1442[i][j], "g_1442[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_1526, "g_1526", print_hash_value);
    transparent_crc(g_1857, "g_1857", print_hash_value);
    transparent_crc(g_1866, "g_1866", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_1918[i], "g_1918[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_1979, "g_1979", print_hash_value);
    transparent_crc(g_1997, "g_1997", print_hash_value);
    transparent_crc(g_2203, "g_2203", print_hash_value);
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 8; j++)
        {
            for (k = 0; k < 3; k++)
            {
                transparent_crc(g_2593[i][j][k], "g_2593[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 2; j++)
        {
            transparent_crc(g_2627[i][j], "g_2627[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_2740, "g_2740", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

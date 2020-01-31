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
void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);void __profile__dump_on_exit();void __profile__unsigned_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, unsigned long long value);void __profile__signed_var(unsigned program_point, const char *var_name, int is_const, unsigned byte_width, long long value);static long __undefined;


struct S0 {
   unsigned f0 : 20;
   unsigned f1 : 27;
   signed f2 : 18;
   unsigned f3 : 21;
   unsigned f4 : 18;
   signed f5 : 3;
   signed f6 : 22;
   unsigned f7 : 17;
   int8_t f8;
};


static int16_t g_4 = 0xF0BC;
static int32_t g_11[1] = {3};
static int32_t g_21 = 0xF0A0CD95;
static struct S0 g_27 = {331,6943,151,1108,188,-1,1793,352,0x83};
static int32_t g_33[5] = {0,0,0,0,0};
static int32_t *g_32[3] = {&g_33[2],&g_33[2],&g_33[2]};
static int32_t g_80 = 0;
static int32_t *g_148 = &g_11[0];
static struct S0 g_210 = {62,11457,186,46,227,-1,-603,351,0xA8};
static int32_t **g_297 = (void*)0;
static int32_t ***g_296 = &g_297;
static struct S0 *g_466 = &g_210;
static struct S0 **g_465 = &g_466;
static uint8_t g_784[4] = {0x84,0x84,0x84,0x84};
static int32_t *g_944[7][4][9] = {{{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0}},{{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0}},{{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0}},{{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0}},{{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0}},{{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0}},{{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0},{(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0}}};
static int32_t *g_986[5][6][4] = {{{&g_11[0],&g_11[0],&g_21,&g_11[0]},{&g_11[0],&g_11[0],&g_33[2],&g_11[0]},{&g_33[2],&g_11[0],&g_33[2],&g_11[0]},{&g_11[0],&g_11[0],&g_21,&g_11[0]},{&g_11[0],&g_11[0],&g_33[2],&g_11[0]},{&g_33[2],&g_11[0],&g_33[2],&g_11[0]}},{{&g_11[0],&g_11[0],&g_21,&g_11[0]},{&g_11[0],&g_11[0],&g_33[2],&g_11[0]},{&g_33[2],&g_11[0],&g_33[2],&g_11[0]},{&g_11[0],&g_11[0],&g_21,&g_11[0]},{&g_11[0],&g_11[0],&g_33[2],&g_11[0]},{&g_33[2],&g_11[0],&g_33[2],&g_11[0]}},{{&g_11[0],&g_11[0],&g_21,&g_11[0]},{&g_11[0],&g_11[0],&g_33[2],&g_11[0]},{&g_33[2],&g_11[0],&g_33[2],&g_11[0]},{&g_11[0],&g_11[0],&g_21,&g_11[0]},{&g_11[0],&g_11[0],&g_33[2],&g_11[0]},{&g_33[2],&g_11[0],&g_33[2],&g_11[0]}},{{&g_11[0],&g_11[0],&g_21,&g_11[0]},{&g_11[0],&g_11[0],&g_33[2],&g_11[0]},{&g_33[2],&g_11[0],&g_33[2],&g_11[0]},{&g_11[0],&g_11[0],&g_21,&g_11[0]},{&g_11[0],&g_11[0],&g_33[2],&g_11[0]},{&g_33[2],&g_11[0],&g_33[2],&g_11[0]}},{{&g_11[0],&g_11[0],&g_21,&g_11[0]},{&g_11[0],&g_11[0],&g_33[2],&g_11[0]},{&g_33[2],&g_11[0],&g_33[2],&g_11[0]},{&g_11[0],&g_11[0],&g_21,&g_11[0]},{&g_11[0],&g_11[0],&g_33[2],&g_11[0]},{&g_33[2],&g_11[0],&g_33[2],&g_11[0]}}};
static uint32_t g_1031[5] = {4294967290U,4294967290U,4294967290U,4294967290U,4294967290U};
static uint32_t g_1094 = 0x1A48B120;
static int32_t g_1240 = (-4);
static uint32_t g_1271[3][6] = {{1U,4294967290U,0xD681EDCC,0xD681EDCC,4294967290U,1U},{0x99BFD6CB,1U,0x5736E71B,4294967290U,0x5736E71B,1U},{0x5736E71B,0x99BFD6CB,0xD681EDCC,0xD41561A5,0xD41561A5,0xD681EDCC}};
static uint16_t g_1484 = 65535U;
static int16_t g_2054[9][2][2] = {{{0x873A,0x8E43},{0x8E43,0xA2DC}},{{1,(-8)},{0x873A,1}},{{(-8),0xA2DC},{(-8),1}},{{0x873A,(-8)},{1,0xA2DC}},{{0x8E43,0x8E43},{0x873A,0x873A}},{{0x873A,0xACB4},{0xA2DC,3}},{{1,0xA2DC},{3,0xACB4}},{{3,0xA2DC},{1,3}},{{0xA2DC,0xACB4},{0x873A,0x873A}}};
static int32_t *g_2221 = &g_11[0];
static uint32_t g_2318 = 4294967287U;
static uint16_t g_2351 = 65532U;
static struct S0 **g_2531[2][2] = {{(void*)0,(void*)0},{(void*)0,(void*)0}};
static int16_t g_2619 = 6;
static uint32_t g_2647 = 4294967291U;
static int32_t ***g_2770 = &g_297;
static int32_t g_2803 = 0x84F8D1EF;
static uint8_t g_2805 = 5U;
static int32_t g_2956 = 0x042F7866;



static int8_t func_1(void);
static int32_t * func_2(uint16_t p_3);
static int16_t func_5(int32_t p_6, int32_t * p_7, uint32_t p_8);
static uint16_t func_12(uint8_t p_13, uint8_t p_14, uint32_t p_15, int32_t * p_16, int32_t p_17);
static int32_t * func_19(int32_t * p_20);
static uint16_t func_38(uint8_t p_39, struct S0 * p_40, uint8_t p_41, int32_t p_42);
static int32_t * func_49(int32_t * p_50, int32_t ** p_51, int32_t ** p_52, struct S0 * p_53, uint8_t p_54);
static int32_t * func_55(uint32_t p_56, int8_t p_57, uint32_t p_58);
static int32_t * func_64(uint32_t p_65, int8_t p_66);
static uint8_t func_71(int16_t p_72, int32_t ** p_73, int16_t p_74);
static int8_t func_1(void)
{
    int32_t l_9 = 0xDCD16652;
    int32_t *l_10[8][2][10] = {{{&g_11[0],(void*)0,&g_11[0],&g_11[0],&g_11[0],&g_11[0],(void*)0,&g_11[0],&g_11[0],(void*)0},{&g_11[0],&g_11[0],(void*)0,(void*)0,&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0]}},{{&g_11[0],(void*)0,(void*)0,&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],(void*)0},{&g_11[0],&g_11[0],&g_11[0],(void*)0,&g_11[0],&g_11[0],(void*)0,&g_11[0],&g_11[0],&g_11[0]}},{{&g_11[0],(void*)0,&g_11[0],&g_11[0],&g_11[0],&g_11[0],(void*)0,&g_11[0],&g_11[0],(void*)0},{&g_11[0],&g_11[0],(void*)0,(void*)0,&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0]}},{{&g_11[0],(void*)0,(void*)0,&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],(void*)0},{&g_11[0],&g_11[0],&g_11[0],(void*)0,&g_11[0],&g_11[0],(void*)0,&g_11[0],&g_11[0],&g_11[0]}},{{&g_11[0],(void*)0,&g_11[0],&g_11[0],&g_11[0],&g_11[0],(void*)0,&g_11[0],&g_11[0],(void*)0},{&g_11[0],&g_11[0],(void*)0,(void*)0,&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0]}},{{&g_11[0],(void*)0,(void*)0,&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],(void*)0},{&g_11[0],&g_11[0],&g_11[0],(void*)0,&g_11[0],&g_11[0],(void*)0,&g_11[0],&g_11[0],&g_11[0]}},{{&g_11[0],(void*)0,&g_11[0],&g_11[0],&g_11[0],&g_11[0],(void*)0,&g_11[0],&g_11[0],(void*)0},{&g_11[0],&g_11[0],(void*)0,(void*)0,&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0]}},{{&g_11[0],(void*)0,(void*)0,&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],(void*)0},{&g_11[0],&g_11[0],&g_11[0],(void*)0,&g_11[0],&g_11[0],(void*)0,&g_11[0],&g_11[0],&g_11[0]}}};
    uint32_t l_18 = 4294967291U;
    uint8_t l_31 = 254U;
    int32_t **l_2926 = &g_944[6][0][7];
    struct S0 *l_2933 = &g_210;
    int i, j, k;
    (*l_2926) = func_2(((g_4 > func_5(l_9, l_10[2][1][5], (g_11[0] & g_11[0]))) , func_12(((l_18 < func_5(g_4, func_19(l_10[3][0][8]), g_4)) != l_31), g_4, g_4, g_32[1], g_33[2])));


    for (l_31 = 2; (l_31 >= 51); l_31 = safe_add_func_int32_t_s_s(l_31, 1))
    {
        uint16_t l_2940[8] = {0U,0U,0U,0U,0U,0U,0U,0U};
        int i;

for (g_4 = 4; (g_4 >= 0); g_4 -= 1)
                {
                    int32_t *l_197 = &g_33[g_4];
                    int i;
                    g_33[g_4] = (safe_lshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u((&g_33[g_4] != (*(*g_296))), ((safe_sub_func_int8_t_s_s(0x77, (safe_div_func_int8_t_s_s(((g_33[g_4] || g_11[0]) <= ((void*)0 == g_466)), (safe_mul_func_uint8_t_u_u((safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((**(*g_296)), (((((((*(*g_296)) != (void*)0) , g_4) != 0x4492) , g_4) == (*g_148)) == g_210.f6))), 6)), (*g_2221))), 1U)), g_210.f0)))))) >= (*g_2221)))), 13));
                    g_2647 = (safe_mod_func_int16_t_s_s(0, g_4));
                    g_148 = (*(*g_296));

                    (((g_148 >= &g_33[0] && g_148 <= &g_33[4])) ? (void) (0) : __assert_fail ("(g_148 >= &g_33[0] && g_148 <= &g_33[4])", "t.c", 130, __PRETTY_FUNCTION__));
                    l_197 = (*(*g_296));
                }
if ((**(*g_2770)))
                        break;

                  ;


                  for (g_21 = 0; (g_21 > (-15)); g_21 = safe_sub_func_int32_t_s_s(g_21, 1))
        {
            uint16_t l_2954 = 0xBB7C;
            struct S0 **l_2955 = (void*)0;

{
            transparent_crc(g_1271[g_2956][l_9], "g_1271[g_2956][l_9]", g_2803);
            if (g_2803) printf("index = [%d][%d]\n", g_2956, l_9);

        }

                    (*g_148) = 0x64EAFE29;
            for (g_2805 = 0; (g_2805 <= 3); g_2805 += 1)
            {
                struct S0 ***l_2957 = &g_2531[1][1];
                int16_t l_2958 = 0x8258;
                int i, j, k;
            }
        }
    }
    return g_11[0];
}







static int32_t * func_2(uint16_t p_3)
{
    int32_t *l_2742 = &g_33[2];
    int32_t **l_2743 = &g_986[0][5][1];
    struct S0 ***l_2771 = &g_2531[0][0];
    uint32_t l_2842[8] = {4294967288U,4294967288U,4294967288U,0x2C0253A1,0x2C0253A1,4294967288U,0x2C0253A1,0x2C0253A1};
    int i;
                                        if ((g_27.f5>-1) )
{

{

{
        struct S0 l_989 = {907,8858,-498,755,59,1,-1185,276,0};
        (*(&g_27)) = l_989;
    }

            (*l_2743) = &(*g_2221);

            (((*l_2743) == &(*g_2221)) ? (void) (0) : __assert_fail ("(*l_2743) == &(*g_2221)", "t.c", 187, __PRETTY_FUNCTION__));
        }

}
            (*l_2743) = l_2742;
                                        while ((!g_210.f3) )
{

{
    int32_t *l_2742 = &g_33[2];
    int32_t **l_2743 = &g_986[0][5][1];
    struct S0 ***l_2771 = &g_2531[0][0];
    uint32_t l_2842[8] = {4294967288U,4294967288U,4294967288U,0x2C0253A1,0x2C0253A1,4294967288U,0x2C0253A1,0x2C0253A1};
    int i;
    (*l_2743) = l_2742;
    for ((*l_2742) = 0; ((*l_2742) <= 2); (*l_2742) += 1)
    {
        int32_t ***l_2774 = &g_297;
        struct S0 l_2818 = {24,6738,-426,165,390,-0,1153,115,0xEA};
        struct S0 ***l_2865[3];
        int i;

{
                (**(*l_2771)) = (*g_466);
            }

                    for (i = 0; i < 3; i++)
            l_2865[i] = &(*l_2771);
        g_32[(*l_2742)] = g_32[(*l_2742)];
        (*(&i)) = ((safe_unary_minus_func_uint32_t_u((safe_unary_minus_func_int32_t_s(((+((((safe_mod_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(((((((safe_sub_func_uint8_t_u_u((p_3 , (*(*g_465)).f5), ((0xE948A20E < (0x51576ED4 < (safe_rshift_func_uint8_t_u_u((((safe_div_func_int32_t_s_s(((p_3 , (0 > ((safe_div_func_int8_t_s_s(((((safe_mul_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s((((((safe_lshift_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_s((&g_32[(*l_2742)] == &g_32[(*l_2742)]), 6)) != (0x3A76E62F < (*l_2742))) , 0x6C), p_3)) , &l_2743) != (&l_2743)) | p_3) <= p_3), 1)), (*(*g_465)).f3)), p_3)) | 0x23CC) != g_33[3]) | 0x0B28), p_3)) , (*(*g_465)).f7))) && 0x38), p_3)) && (*(*g_465)).f6) | 1), (*l_2742))))) == p_3))) , (*(*g_465)).f1) , 0x7D5F7640) || (-1)) , (void*)0) != l_2771))), 0xEA)) | (-7)) < 0x54EA) || (*l_2742))) , 3))))) | 65535U);
        for (p_3 = (-12); (p_3 == 60); p_3 = safe_add_func_int32_t_s_s(p_3, 6))
        {
            uint16_t l_2775 = 0xE2FA;
            int16_t l_2804 = 8;
            struct S0 **l_2817[2][8][4] = {{{&(*g_465),&(*g_465),&(*g_465),&(*g_465)},{&(*g_465),&(*g_465),(void*)0,&(*g_465)},{&(*g_465),&(*g_465),&(*g_465),(void*)0},{&(*g_465),(void*)0,(void*)0,(void*)0},{&(*g_465),&(*g_465),&(*g_465),&(*g_465)},{(void*)0,&(*g_465),&(*g_465),(void*)0},{&(*g_465),&(*g_465),(void*)0,&(*g_465)},{&(*g_465),&(*g_465),&(*g_465),(void*)0}},{{(void*)0,&(*g_465),&(*g_465),&(*g_465)},{&(*g_465),&(*g_465),(void*)0,(void*)0},{&(*g_465),&(*g_465),&(*g_465),&(*g_465)},{&(*g_465),&(*g_465),(void*)0,&(*g_465)},{&(*g_465),&(*g_465),&(*g_465),(void*)0},{&(*g_465),&(*g_465),(void*)0,&(*g_465)},{&(*g_465),&(*g_465),&(*g_465),&(*g_465)},{&(*g_465),&(*g_465),(void*)0,(void*)0}}};
            int32_t l_2882 = (-4);
            int32_t *l_2884[4][4][8] = {{{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]},{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]},{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]},{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]}},{{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]},{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]},{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]},{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]}},{{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]},{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]},{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]},{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]}},{{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]},{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]},{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]},{&g_33[2],&(*l_2742),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*l_2742),&g_33[2]}}};
            int i, j, k;
        }
        for (l_2818.f8 = 1; (l_2818.f8 <= 7); l_2818.f8 += 1)
        {
            uint16_t l_2912[10][5] = {{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U}};
            int32_t *l_2923 = (void*)0;
            int i, j;
        }
    }
    (*l_2743) = (*l_2743);
    (*l_2743) = (*l_2743);
    return (*l_2743);


}

}
            for (g_80 = 0; (g_80 <= 2); g_80 += 1)
    {
        int32_t ***l_2774 = &g_297;
        struct S0 l_2818 = {24,6738,-426,165,390,-0,1153,115,0xEA};
        struct S0 ***l_2865[3];
        int i;
                                            if ((l_2818.f0>24) )
{

{
            int i;
            if (g_2318)
                break;
        }

}
                    for (i = 0; i < 3; i++)
            l_2865[i] = &g_465;
                                           if (l_2818.f4)
                    g_32[g_80] = g_32[g_80];
        (*g_148) = ((safe_unary_minus_func_uint32_t_u((safe_unary_minus_func_int32_t_s(((+((((safe_mod_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(((((((safe_sub_func_uint8_t_u_u((p_3 , g_27.f5), ((0xE948A20E < (0x51576ED4 < (safe_rshift_func_uint8_t_u_u((((safe_div_func_int32_t_s_s(((p_3 , (0 > ((safe_div_func_int8_t_s_s(((((safe_mul_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s((((((safe_lshift_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_s((&g_32[g_80] == &g_32[g_80]), 6)) != (0x3A76E62F < (*l_2742))) , 0x6C), p_3)) , &l_2743) != g_2770) | p_3) <= p_3), 1)), g_210.f3)), p_3)) | 0x23CC) != g_33[3]) | 0x0B28), p_3)) , g_27.f7))) && 0x38), p_3)) && g_210.f6) | 1), (*l_2742))))) == p_3))) , g_27.f1) , 0x7D5F7640) || (-1)) , (void*)0) != l_2771))), 0xEA)) | (-7)) < 0x54EA) || (*l_2742))) , 3))))) | 65535U);
        for (p_3 = (-12); (p_3 == 60); p_3 = safe_add_func_int32_t_s_s(p_3, 6))
        {
            uint16_t l_2775 = 0xE2FA;
            int16_t l_2804 = 8;
            struct S0 **l_2817[2][8][4] = {{{&g_466,&g_466,&g_466,&g_466},{&g_466,&g_466,(void*)0,&g_466},{&g_466,&g_466,&g_466,(void*)0},{&g_466,(void*)0,(void*)0,(void*)0},{&g_466,&g_466,&g_466,&g_466},{(void*)0,&g_466,&g_466,(void*)0},{&g_466,&g_466,(void*)0,&g_466},{&g_466,&g_466,&g_466,(void*)0}},{{(void*)0,&g_466,&g_466,&g_466},{&g_466,&g_466,(void*)0,(void*)0},{&g_466,&g_466,&g_466,&g_466},{&g_466,&g_466,(void*)0,&g_466},{&g_466,&g_466,&g_466,(void*)0},{&g_466,&g_466,(void*)0,&g_466},{&g_466,&g_466,&g_466,&g_466},{&g_466,&g_466,(void*)0,(void*)0}}};
            int32_t l_2882 = (-4);
            int32_t *l_2884[4][4][8] = {{{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]},{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]},{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]},{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]}},{{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]},{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]},{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]},{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]}},{{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]},{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]},{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]},{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]}},{{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]},{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]},{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]},{&g_33[2],&g_2803,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&g_2803,&g_33[2]}}};
            int i, j, k;
        }
                                       int32_t BHbHbl_2818_f6 = (~(((~(((~(l_2818.f3)) | ((l_2818.f2 / l_2818.f0) / (l_2818.f1 | l_2818.f5))))) & (((-(l_2818.f6)) * ((-((g_27.f7 & g_210.f3))) * (~(g_80)))) / (~(g_210.f6))))));
uint32_t BHbHbbl_2818_f0 = (~(((((~(l_2818.f2)) & ((-(l_2818.f6)) * g_210.f3)) / (~((g_210.f6 * g_27.f7)))) * (((-((l_2818.f1 | l_2818.f3))) & g_80) | (~((l_2818.f0 ^ l_2818.f5)))))));
uint32_t BHbHbcg_27_f7 = (-((((g_210.f6 * (g_27.f7 / BHbHbl_2818_f6)) ^ (l_2818.f1 * (~((-((((~(g_210.f3)) | ((l_2818.f5 * l_2818.f3) / l_2818.f6)) ^ (~(l_2818.f2))))))))) & (~((~(g_80)))))));
int32_t BHbHbdl_2818_f2 = (~((((((~((BHbHbbl_2818_f0 / l_2818.f1))) * (-(l_2818.f2))) << (-((~(l_2818.f0))))) * (((~(((~(g_27.f7)) ^ (~(g_80))))) * l_2818.f3) / g_210.f3)) ^ (~((~((~((-((BHbHbl_2818_f6 & l_2818.f5))))))))))));
                               uint32_t B2b2bg_27_f1 = (~((((((~(l_2818.f8)) & ((-(g_27.f1)) ^ ((l_2818.f0 & (~(l_2818.f6))) | (~(g_80))))) ^ (~(l_2818.f1))) | (l_2818.f5 & (~(l_2818.f7)))) || (g_210.f6 % g_27.f5))));
int32_t B2b2bbg_80 = (~(((-((~(((~(g_80)) | l_2818.f7))))) & (~(((~(((~(l_2818.f6)) | ((-(g_27.f1)) / (~((l_2818.f5 ^ ((g_27.f5 + ((~(l_2818.f8)) >> l_2818.f0)) / l_2818.f1)))))))) || (~(g_210.f6))))))));
uint32_t B2b2bcl_2818_f7 = (~((g_210.f6 + (~((((l_2818.f6 % g_27.f5) ^ (-((~(l_2818.f5))))) + ((g_80 + B2b2bg_27_f1) & ((~((~(l_2818.f8)))) + (l_2818.f7 ^ (-((~((l_2818.f1 % B2b2bbg_80))))))))))))));
uint32_t B2b2bdl_2818_f1 = (~(((~((g_80 ^ (-(((~(l_2818.f7)) + g_27.f1)))))) ^ ((g_210.f6 ^ ((~(B2b2bg_27_f1)) | ((l_2818.f8 / B2b2bbg_80) || (~((l_2818.f0 % B2b2bcl_2818_f7)))))) << l_2818.f5))));
if(((g_27.f5>-1) || g_210.f6)){
B2b2bg_27_f1 = g_27.f1;
B2b2bbg_80 = g_80;
B2b2bcl_2818_f7 = l_2818.f7;
B2b2bdl_2818_f1 = l_2818.f1;
g_27.f1 = (~(((~((B2b2bdl_2818_f1 || ((B2b2bcl_2818_f7 + g_27.f1) >> (l_2818.f8 / (~(l_2818.f6))))))) || (~((((-((g_80 ^ (l_2818.f1 | B2b2bbg_80)))) & l_2818.f7) ^ l_2818.f5))))));
g_80 = (~(((~((~(((((g_27.f1 + l_2818.f8) | (l_2818.f1 & l_2818.f7)) & (g_80 / g_27.f5)) / (~(l_2818.f6))))))) + ((l_2818.f5 / l_2818.f0) >> (-((~(B2b2bbg_80))))))));
l_2818.f7 = (-(((-(((~(l_2818.f6)) || (~(B2b2bbg_80))))) & (-((~(((((-(l_2818.f7)) | g_80) & (B2b2bdl_2818_f1 & (~((g_27.f1 % l_2818.f8))))) & ((B2b2bcl_2818_f7 + (~(l_2818.f0))) || g_210.f6)))))))));
l_2818.f1 = (~(((~(B2b2bbg_80)) | (((l_2818.f1 ^ (-(g_27.f1))) || ((~(g_27.f5)) % B2b2bcl_2818_f7)) + ((B2b2bg_27_f1 & (-(g_210.f6))) % (-((~(((~((l_2818.f5 % l_2818.f8))) ^ l_2818.f7))))))))));
if(!((B2b2bg_27_f1 > B2b2bdl_2818_f1))){
printf("g_27.f1=%llu\n", (unsigned long long)g_27.f1);
continue;
}
if((g_27.f5>-1)){
printf("g_80=%lld\n", (long long)g_80);
continue;
}
                               int8_t Bececl_2818_f8 = (~((((~((~((~(l_2818.f2)))))) | (((~(g_27.f5)) & l_2818.f3) | (~(((l_2818.f4 && l_2818.f1) & (l_2818.f8 && (g_80 + g_210.f3))))))) * ((~((~(l_2818.f6)))) + l_2818.f0))));
uint32_t Bececbl_2818_f0 = (~(((~((((l_2818.f2 * l_2818.f6) && g_210.f3) + (Bececl_2818_f8 & (l_2818.f8 * (g_80 | l_2818.f1)))))) + (~((~(((l_2818.f3 ^ l_2818.f4) * g_27.f5))))))));
int8_t Bececcg_27_f5 = (~((((~((~(l_2818.f8)))) * (l_2818.f0 | ((~(g_80)) && (g_27.f5 + (l_2818.f3 && l_2818.f1))))) ^ ((Bececbl_2818_f0 + (g_210.f3 && l_2818.f6)) & Bececl_2818_f8))));
int32_t Bececdl_2818_f6 = (-(((-(((~(((l_2818.f1 + l_2818.f4) | Bececcg_27_f5))) + (~(((l_2818.f2 * (l_2818.f0 & Bececl_2818_f8)) ^ (-(l_2818.f6)))))))) * (~((g_80 + (g_27.f5 && l_2818.f8)))))));
if(((l_2818.f3>=165) || (!l_2818.f3))){
Bececl_2818_f8 = l_2818.f8;
Bececbl_2818_f0 = l_2818.f0;
LABEL_ecece: Bececcg_27_f5 = g_27.f5;
Bececdl_2818_f6 = l_2818.f6;
                                   if (l_2818.f6)
                    l_2818.f8 = (-((((~(((Bececbl_2818_f0 & l_2818.f0) & ((~(l_2818.f4)) * (~((-(g_80)))))))) ^ (~(g_27.f5))) * ((~(l_2818.f2)) && (-((Bececl_2818_f8 && (Bececcg_27_f5 ^ (-((l_2818.f3 ^ l_2818.f1)))))))))));
l_2818.f0 = (-((((-(Bececl_2818_f8)) * (g_27.f5 & g_210.f3)) + (((~(l_2818.f8)) * (~(Bececdl_2818_f6))) ^ ((((l_2818.f4 && (-(g_80))) && l_2818.f6) * l_2818.f1) | l_2818.f0)))));
g_27.f5 = (~((((((~(Bececdl_2818_f6)) + (l_2818.f8 * l_2818.f0)) << (-(Bececcg_27_f5))) + (-((~((~(g_210.f3))))))) & (~(((-((~(((l_2818.f2 ^ l_2818.f3) & (l_2818.f4 & g_27.f5)))))) >> l_2818.f1))))));
l_2818.f6 = (-((((~(((~((l_2818.f2 & Bececbl_2818_f0))) | g_80))) * ((~(l_2818.f6)) * g_210.f3)) & (~(((-((l_2818.f4 << l_2818.f1))) | ((g_27.f5 & l_2818.f8) | l_2818.f3)))))));
if((g_210.f3>46)){
printf("l_2818.f8=%lld\n", (long long)l_2818.f8);
goto LABEL_ecece;
}
if((Bececl_2818_f8>-22)){
printf("g_27.f5=%lld\n", (long long)g_27.f5);
break;
}
if((l_2818.f0<1026766)){
printf("l_2818.f6=%lld\n", (long long)l_2818.f6);
Bececcg_27_f5 = (-(((~(((((-(l_2818.f0)) << l_2818.f3) * (-((-(Bececl_2818_f8))))) + (Bececdl_2818_f6 >> Bececbl_2818_f0)))) >> (~((((~(l_2818.f4)) << ((~(g_27.f5)) << (g_210.f3 | l_2818.f2))) ^ (~(g_80))))))));
goto LABEL_ecece;
}
}
l_2818.f8 = Bececl_2818_f8;
l_2818.f0 = Bececbl_2818_f0;
g_27.f5 = Bececcg_27_f5;
l_2818.f6 = Bececdl_2818_f6;

                    if((B2b2bg_27_f1>6943U)){
printf("l_2818.f7=%llu\n", (unsigned long long)l_2818.f7);
break;
}
if((g_27.f1 && (B2b2bcl_2818_f7 < l_2818.f5))){
printf("l_2818.f1=%llu\n", (unsigned long long)l_2818.f1);

g_2619 += 1;


                    g_27.f1 = (~(((~((~((~(B2b2bg_27_f1)))))) + (((g_27.f5 / (-(B2b2bcl_2818_f7))) ^ (~((-((B2b2bdl_2818_f1 | B2b2bbg_80)))))) ^ (((l_2818.f0 | l_2818.f6) % g_210.f6) >> (~(((~(l_2818.f7)) << (~((~(g_80))))))))))));
l_2818.f1 = (-((((l_2818.f8 + (B2b2bcl_2818_f7 || (-(l_2818.f0)))) << (-(((l_2818.f1 / l_2818.f7) ^ (~((~((g_210.f6 >> l_2818.f5))))))))) >> (-(((-((~(l_2818.f6)))) || (~((g_27.f1 + (~(g_27.f5)))))))))));
break;
}
}
g_27.f1 = B2b2bg_27_f1;
g_80 = B2b2bbg_80;
l_2818.f7 = B2b2bcl_2818_f7;
l_2818.f1 = B2b2bdl_2818_f1;

                    if((g_210.f6 && (l_2818.f3 > l_2818.f0))){
BHbHbl_2818_f6 = l_2818.f6;
                                   if ((g_27.f5 > l_2818.f8))
                    BHbHbbl_2818_f0 = l_2818.f0;
BHbHbcg_27_f7 = g_27.f7;
BHbHbdl_2818_f2 = l_2818.f2;
l_2818.f6 = (~((((-((~(g_210.f3)))) * (~((-((((~(BHbHbl_2818_f6)) * (l_2818.f0 * BHbHbcg_27_f7)) * (l_2818.f2 & g_210.f6))))))) ^ (~(((~((BHbHbbl_2818_f0 & (l_2818.f5 & (~(g_27.f7)))))) & BHbHbdl_2818_f2))))));
l_2818.f0 = (~(((-((g_210.f6 | (~((l_2818.f1 & l_2818.f0)))))) / (~(((-((g_80 & (BHbHbl_2818_f6 ^ BHbHbcg_27_f7)))) & (~((((l_2818.f5 ^ g_27.f7) * g_210.f3) / BHbHbdl_2818_f2)))))))));
g_27.f7 = (~(((-(((~(l_2818.f0)) | l_2818.f6))) * (((~((~(((((BHbHbcg_27_f7 * BHbHbdl_2818_f2) | g_27.f7) ^ (~(g_210.f3))) * (l_2818.f3 | l_2818.f2)))))) & (-(l_2818.f1))) << BHbHbbl_2818_f0))));
l_2818.f2 = (-((((l_2818.f0 | (g_80 << BHbHbbl_2818_f0)) & l_2818.f2) & (~(((((~((g_210.f3 ^ (~(l_2818.f3))))) * (-(l_2818.f1))) / (-((~(g_210.f6))))) & (l_2818.f6 ^ (~(BHbHbdl_2818_f2)))))))));
if((BHbHbcg_27_f7<352U)){
printf("l_2818.f6=%lld\n", (long long)l_2818.f6);
l_2818.f0 = (~((((BHbHbdl_2818_f2 >> l_2818.f6) ^ (~((~((g_210.f3 * g_27.f7)))))) ^ ((((~(BHbHbbl_2818_f0)) * (g_80 / l_2818.f3)) << (-(BHbHbl_2818_f6))) & (~((l_2818.f2 * (-(g_210.f6)))))))));

if (BHbHbcg_27_f7)
                break;

                    BHbHbl_2818_f6 = (~((((~(((BHbHbbl_2818_f0 | (BHbHbdl_2818_f2 | BHbHbcg_27_f7)) / ((-(l_2818.f3)) & (~(((~(g_210.f6)) / (g_27.f7 << l_2818.f1)))))))) / (-(((-((~(l_2818.f0)))) * g_80)))) & (-((-(l_2818.f6)))))));
g_27.f7 = (~(((~(BHbHbcg_27_f7)) >> ((~((g_80 >> g_210.f6))) & (~(((l_2818.f3 << (((~((BHbHbbl_2818_f0 << l_2818.f0))) >> (~((g_27.f7 << l_2818.f5)))) * BHbHbl_2818_f6)) * (-((-(BHbHbdl_2818_f2)))))))))));
}
if((l_2818.f6 < BHbHbcg_27_f7)){
printf("l_2818.f0=%llu\n", (unsigned long long)l_2818.f0);

for (g_80 = 4; (g_80 >= 0); g_80 -= 1)
                    {
                        return (*(&g_2221));



                    };


                    BHbHbbl_2818_f0 = (~(((g_210.f6 & (l_2818.f2 >> (~((((-(l_2818.f1)) / g_80) >> (~((l_2818.f3 * BHbHbbl_2818_f0)))))))) / ((~(g_27.f7)) | ((~((BHbHbl_2818_f6 & BHbHbcg_27_f7))) << l_2818.f0)))));
continue;
}
if(!((l_2818.f6 > l_2818.f1))){
printf("g_27.f7=%llu\n", (unsigned long long)g_27.f7);
break;
}
if(!((l_2818.f3 && l_2818.f1))){
printf("l_2818.f2=%lld\n", (long long)l_2818.f2);

g_2805 += 1;


                    BHbHbcg_27_f7 = (-(((g_210.f6 * BHbHbdl_2818_f2) >> ((l_2818.f2 << l_2818.f6) / ((~(((-((BHbHbbl_2818_f0 / (g_210.f3 * l_2818.f0)))) >> (-(l_2818.f3))))) ^ (~((BHbHbcg_27_f7 * BHbHbl_2818_f6))))))));
}
}
l_2818.f6 = BHbHbl_2818_f6;
l_2818.f0 = BHbHbbl_2818_f0;
g_27.f7 = BHbHbcg_27_f7;
                                    while (((l_2818.f3 < l_2818.f6) && (l_2818.f4 < l_2818.f0)) )
{

g_4 -= 1;


}
                    l_2818.f2 = BHbHbdl_2818_f2;

                                                   int32_t Brcrcl_2818_f2 = (~(((~(((-((l_2818.f0 + (~(g_27.f7))))) >> l_2818.f5))) - (-(((~(l_2818.f6)) ^ (~(((((l_2818.f4 - g_210.f3) * l_2818.f3) + (g_210.f6 - g_27.f5)) && l_2818.f2)))))))));
int32_t Brcrcbl_2818_f6 = (~((((~((~((-((l_2818.f6 || l_2818.f0))))))) | (~(((~(l_2818.f4)) | (Brcrcl_2818_f2 ^ l_2818.f5))))) * (g_210.f3 * ((l_2818.f2 ^ (l_2818.f3 | g_27.f5)) * g_27.f7)))));
int8_t Brcrccg_27_f5 = (-(((((-(((g_210.f3 - (~(l_2818.f6))) + (g_27.f5 * l_2818.f5)))) && l_2818.f3) & Brcrcbl_2818_f6) | ((-(((l_2818.f4 || g_210.f6) && l_2818.f2))) - (~(Brcrcl_2818_f2))))));
uint32_t Brcrcdg_210_f3 = (-(((-(((~((-(l_2818.f4)))) && ((-((g_27.f7 ^ (-(((l_2818.f0 - (~(Brcrcl_2818_f2))) && l_2818.f3)))))) >> l_2818.f5)))) & (~(((~(Brcrccg_27_f5)) | (~(((~(g_27.f5)) && (~(((~(l_2818.f2)) && l_2818.f6))))))))))));
if((g_27.f5<=-1)){
Brcrcl_2818_f2 = l_2818.f2;
Brcrcbl_2818_f6 = l_2818.f6;
Brcrccg_27_f5 = g_27.f5;
Brcrcdg_210_f3 = g_210.f3;
l_2818.f2 = (-(((-((-(((g_210.f3 * (-(l_2818.f6))) && l_2818.f3))))) & (-((((((~(Brcrcl_2818_f2)) & l_2818.f4) + (-(Brcrcbl_2818_f6))) + l_2818.f2) + (-(((~((~(g_27.f5)))) || (l_2818.f0 + g_210.f6))))))))));
l_2818.f6 = (~(((((~((Brcrccg_27_f5 & (~((~(l_2818.f2))))))) && (-((g_27.f7 || g_210.f6)))) + (((-(Brcrcbl_2818_f6)) - (l_2818.f6 * Brcrcl_2818_f2)) ^ ((-(l_2818.f5)) || g_27.f5))) & (~((-(l_2818.f4)))))));
g_27.f5 = (-((((-(((~(l_2818.f6)) & (~((l_2818.f2 - (g_27.f7 - g_210.f3))))))) * ((l_2818.f3 * g_27.f5) + ((Brcrccg_27_f5 && (~(l_2818.f5))) && (~((-(l_2818.f4))))))) | g_210.f6)));
g_210.f3 = (-(((~((~(Brcrcbl_2818_f6)))) ^ ((~(((Brcrcl_2818_f2 || Brcrcdg_210_f3) && ((-((l_2818.f2 + (g_27.f7 ^ l_2818.f0)))) | (l_2818.f4 | g_27.f5))))) * (~((g_210.f3 - l_2818.f6)))))));
if((!l_2818.f6)){
printf("l_2818.f2=%lld\n", (long long)l_2818.f2);
break;
}
if((g_27.f7>352)){
printf("l_2818.f6=%lld\n", (long long)l_2818.f6);
g_27.f5 = (~((((~((Brcrccg_27_f5 + l_2818.f3))) * (-((~((~(((l_2818.f2 ^ l_2818.f4) ^ (~(g_210.f6)))))))))) & (((~(Brcrcl_2818_f2)) ^ l_2818.f6) || (~(((g_27.f7 | l_2818.f0) >> (-((~(Brcrcbl_2818_f6)))))))))));
Brcrcdg_210_f3 = (~(((((-((((~(Brcrcl_2818_f2)) + g_27.f5) & l_2818.f6))) || (((~(l_2818.f3)) && g_27.f7) * l_2818.f0)) - (-((g_210.f3 << (~((~(Brcrcbl_2818_f6)))))))) ^ (l_2818.f4 & (~(l_2818.f5))))));
break;
}
if((((l_2818.f2<=0) && (l_2818.f3 < l_2818.f5)) || !((l_2818.f0<=24)))){
printf("g_27.f5=%lld\n", (long long)g_27.f5);
g_210.f3 = (~((l_2818.f6 || ((~(((~(Brcrcl_2818_f2)) & (((-(Brcrccg_27_f5)) || Brcrcdg_210_f3) & (l_2818.f2 >> l_2818.f0))))) * ((~(l_2818.f3)) - (g_210.f3 * (l_2818.f4 && (~(g_210.f6)))))))));
continue;
}
if((((!g_210.f6) || (l_2818.f2<=0)) && (l_2818.f4 && (l_2818.f4>390)))){
printf("g_210.f3=%llu\n", (unsigned long long)g_210.f3);
continue;
}
}
l_2818.f2 = Brcrcl_2818_f2;
l_2818.f6 = Brcrcbl_2818_f6;
g_27.f5 = Brcrccg_27_f5;
g_210.f3 = Brcrcdg_210_f3;

                    for (l_2818.f8 = 1; (l_2818.f8 <= 7); l_2818.f8 += 1)
        {
            uint16_t l_2912[10][5] = {{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U}};
            int32_t *l_2923 = (void*)0;
            int i, j;
        }
    }
                                       if ((g_80 < g_27.f1))
            (*l_2743) = (*l_2743);
    (*l_2743) = (*l_2743);
                                        while (((!g_210.f3) || (g_210.f3 > g_27.f7)) )
{

(*g_148) += 1;


}
            return (*l_2743);


}







static int16_t func_5(int32_t p_6, int32_t * p_7, uint32_t p_8)
{
                                        if ((g_4<-3908) )
{


g_27.f8 += 1;


  for (g_1240 = 0; g_1240 < 6; g_1240++)
        {
            transparent_crc(g_1271[g_2803][g_1240], "g_1271[g_2803][g_1240]", g_2803);
            if (g_2803) {
{
                        uint8_t l_1841 = 0xAC;
                        (*(&g_2221)) = g_2221;
                        (**(&(*g_465))) = (*(*g_465));
                        (*(&g_2221)) = &g_11[0];
                        g_2221 = (&g_2956);

                        ((g_2221 == 0) ? (void) (0) : __assert_fail ("g_2221 == 0", "t.c", 495, __PRETTY_FUNCTION__));
                    }

  printf("index = [%d][%d]\n", g_2803, g_1240);}

        };


}
  return g_4;
}







static uint16_t func_12(uint8_t p_13, uint8_t p_14, uint32_t p_15, int32_t * p_16, int32_t p_17)
{
    int8_t l_43 = 0x32;
    struct S0 *l_61[3][4][8] = {{{&g_27,&g_27,&g_27,&g_27,(void*)0,(void*)0,&g_27,&g_27},{&g_27,&g_27,&g_27,&g_27,&g_27,&g_27,&g_27,(void*)0},{&g_27,(void*)0,&g_27,&g_27,&g_27,(void*)0,&g_27,(void*)0},{(void*)0,&g_27,&g_27,&g_27,&g_27,&g_27,&g_27,&g_27}},{{&g_27,(void*)0,&g_27,&g_27,(void*)0,&g_27,&g_27,&g_27},{&g_27,&g_27,&g_27,&g_27,&g_27,&g_27,&g_27,&g_27},{&g_27,&g_27,&g_27,&g_27,&g_27,&g_27,&g_27,&g_27},{(void*)0,(void*)0,&g_27,&g_27,&g_27,&g_27,(void*)0,&g_27}},{{&g_27,&g_27,&g_27,&g_27,&g_27,&g_27,&g_27,&g_27},{(void*)0,&g_27,&g_27,&g_27,&g_27,&g_27,(void*)0,&g_27},{&g_27,&g_27,&g_27,(void*)0,&g_27,&g_27,&g_27,&g_27},{&g_27,&g_27,&g_27,&g_27,(void*)0,&g_27,&g_27,(void*)0}}};
    uint8_t l_62 = 0xC4;
    int32_t l_2566 = 0xB3E5C69E;
    int32_t ***l_2579[1];
    int8_t l_2582[2][3] = {{(-2),0,0},{(-2),0,0}};
    int32_t l_2617 = 4;
    struct S0 ***l_2658 = &g_465;
    int8_t l_2665[3];
    int8_t l_2722 = (-1);
    int i, j, k;
    for (i = 0; i < 1; i++)
        l_2579[i] = &g_297;
                                        if (((l_62<=196) && (l_2722 < g_27.f8)) )
{

{
                        uint8_t l_1841 = 0xAC;
                        (*(&g_2221)) = g_148;
                        (**g_465) = (*(&g_27));
                        (*(&g_2221)) = &g_11[0];
                        (*g_297) = (&g_2803);

                        (((*g_297) == 0) ? (void) (0) : __assert_fail ("(*g_297) == 0", "t.c", 538, __PRETTY_FUNCTION__));
                    }

}
            for (i = 0; i < 3; i++)
        l_2665[i] = (-1);
                                       if (!((g_27.f8 > l_2617)))
            for (g_27.f8 = 0; (g_27.f8 <= (-11)); g_27.f8 = safe_sub_func_uint32_t_u_u(g_27.f8, 9))
    {
        struct S0 *l_46 = &g_27;
        int32_t l_2567 = 5;
        struct S0 l_2635 = {146,1898,-222,140,56,-0,-298,38,0x28};
        int32_t l_2699[5] = {0x4100C087,0x4100C087,0x4100C087,0x4100C087,0x4100C087};
        int32_t ***l_2715 = &g_297;
        int32_t *l_2725 = (void*)0;
        struct S0 ***l_2735 = (void*)0;
        int i;
    }
                                        while (!(l_2566) )
{

{
                    int32_t **l_2560[2];
                    int i;
                    for (i = 0; i < 2; i++)
                        l_2560[i] = &g_944[3][3][1];

for (g_210.f8 = 0; (g_210.f8 <= (-11)); g_210.f8 = safe_sub_func_uint32_t_u_u(g_210.f8, 9))
    {
        struct S0 *l_46 = &g_210;
        int32_t l_2567 = 5;
        struct S0 l_2635 = {146,1898,-222,140,56,-0,-298,38,0x28};
        int32_t l_2699[5] = {0x4100C087,0x4100C087,0x4100C087,0x4100C087,0x4100C087};
        int32_t ***l_2715 = &g_297;
        int32_t *l_2725 = (void*)0;
        struct S0 ***l_2735 = (void*)0;
        int i;
    };


            g_148 = &i;

                    ((g_148 == &i) ? (void) (0) : __assert_fail ("g_148 == &i", "t.c", 580, __PRETTY_FUNCTION__));
                }

}
            return p_13;
}







static int32_t * func_19(int32_t * p_20)
{
    int32_t *l_26 = &g_11[0];
    struct S0 *l_28 = &g_27;
    for (g_21 = (-7); (g_21 != (-23)); g_21--)
    {
        int32_t *l_25 = &g_21;
        int32_t **l_24[1][5] = {{&l_25,&l_25,&l_25,&l_25,&l_25}};
        int i, j;
        l_26 = &g_11[0];
    }
                                   int16_t B2b2beg_4 = (-((g_21 & g_4)));
int32_t B2b2bfg_21 = (~(((~((B2b2beg_4 & g_4))) + g_21)));
if(((g_4<=-3908) && (B2b2beg_4 > g_21))){
B2b2beg_4 = g_4;
B2b2bfg_21 = g_21;
g_4 = (~(((g_4 | (g_21 ^ B2b2bfg_21)) / (-((-(B2b2beg_4)))))));
g_21 = (~((((g_21 || B2b2beg_4) ^ (-(B2b2bfg_21))) | (~(g_4)))));
if(((B2b2bfg_21>=-23) && (B2b2bfg_21<-23))){
printf("g_4=%lld\n", (long long)g_4);
g_4 = (~((((-((-(B2b2bfg_21)))) || ((~(g_4)) % B2b2beg_4)) ^ g_21)));
g_21 = (-(((-(g_4)) || ((B2b2bfg_21 / (~(B2b2beg_4))) / g_21))));
B2b2beg_4 = (~(((B2b2bfg_21 + (g_4 | g_21)) / B2b2beg_4)));
}
if((g_21<-24)){
printf("g_21=%lld\n", (long long)g_21);


for (g_2803 = 0; (g_2803 > (-15)); g_2803 = safe_sub_func_int32_t_s_s(g_2803, 1))
        {
            uint16_t l_2954 = 0xBB7C;
            struct S0 **l_2955 = (void*)0;
            (*(&g_80)) = 0x64EAFE29;
            for (g_2805 = 0; (g_2805 <= 3); g_2805 += 1)
            {
                struct S0 ***l_2957 = &g_2531[1][1];
                int16_t l_2958 = 0x8258;
                int i, j, k;
            }
        };


    g_2318 += 1;



{
                    (**g_465) = (*(&g_27));
                }

    B2b2beg_4 = (-(((~((~(B2b2beg_4)))) % ((~(g_4)) % (B2b2bfg_21 & g_21)))));
B2b2bfg_21 = (-(((~((-((~((~((g_21 >> B2b2bfg_21))))))))) | (B2b2beg_4 | g_4))));
g_21 = (~(((B2b2beg_4 % (-((~(B2b2bfg_21))))) / (g_4 / g_21))));
}
}
g_4 = B2b2beg_4;
g_21 = B2b2bfg_21;

    (*l_28) = g_27;
                                        while ((g_4>-3908) )
{

{
        struct S0 l_989 = {907,8858,-498,755,59,1,-1185,276,0};

{
                l_26 = &g_11[0];
            }

                    (*(&g_210)) = l_989;
    }

}
    (*l_26) = func_5((safe_mul_func_uint16_t_u_u(0U, g_27.f7)), p_20, g_27.f5);
    return l_26;


}







static uint16_t func_38(uint8_t p_39, struct S0 * p_40, uint8_t p_41, int32_t p_42)
{
    for (g_2318 = 0; (g_2318 < 57); g_2318 = safe_add_func_uint16_t_u_u(g_2318, 6))
    {
        return g_27.f0;
    }
    return g_27.f7;
}







static int32_t * func_49(int32_t * p_50, int32_t ** p_51, int32_t ** p_52, struct S0 * p_53, uint8_t p_54)
{
    uint8_t l_991 = 0x6C;
    uint16_t l_1009 = 65534U;
    uint8_t l_1052 = 1U;
    int32_t *l_1082 = &g_33[2];
    int32_t *l_1096[1];
    uint16_t l_1122 = 0xCFD7;
    uint32_t l_1129[6];
    int32_t l_1167[9][7] = {{0x686354AF,0xEAADA604,0x9F3A8292,(-8),0xEAADA604,1,0xDF626FC6},{0x92D01035,6,0x8E4ABF52,(-10),(-10),0x8E4ABF52,6},{0x92D01035,0xDF626FC6,1,0xEAADA604,(-8),0x9F3A8292,0xEAADA604},{0x686354AF,0x79026E8D,8,0x355533EA,0xDF626FC6,0x8E4ABF52,0xCD6D9634},{0xDF626FC6,(-8),0xCFECAA7B,0x9F3A8292,0x79026E8D,(-10),0xAFAB2168},{0xAFAB2168,0xCD6D9634,7,1,7,0xCD6D9634,0xAFAB2168},{0x58BE81C1,0x686354AF,0xCAC2F4B7,7,0xAFAB2168,4,0xCD6D9634},{0x686354AF,1,(-10),0xDF626FC6,(-8),0xCFECAA7B,0x9F3A8292},{0x79026E8D,0xCD6D9634,0xCAC2F4B7,0x79026E8D,0x355533EA,0x8C452FAF,0xCAEB1F53}};
    int16_t l_1181 = 0;
    struct S0 l_1217 = {691,4172,-26,896,429,0,-1765,207,1};
    int16_t l_1262 = 0;
    int16_t l_1306[7][6][5] = {{{(-9),(-3),(-4),(-4),(-3)},{0xDE7E,1,(-4),0x09A5,0},{(-4),0xDE7E,3,0xDE5D,0x09A5},{0xD503,5,0,(-9),(-3)},{(-4),(-9),(-7),(-3),(-7)},{0xDE7E,0xDE7E,0,(-3),0x6C36}},{{(-9),(-4),1,(-9),0xDE7E},{5,0xD503,(-4),0xDE5D,0xD503},{0xDE7E,(-4),8,0x09A5,0x09A5},{1,0xDE7E,1,(-4),0x09A5},{(-3),(-9),0,5,0xD503},{(-4),5,0x06AE,(-3),0xDE7E}},{{(-7),0xDE7E,0,0xD503,0x6C36},{5,1,1,5,(-7)},{5,(-3),8,0xDE5D,(-3)},{(-7),(-4),(-4),0,0x09A5},{(-4),(-7),1,0xDE5D,0},{(-3),5,0,5,(-3)}},{{1,5,(-7),0xD503,0xDE7E},{0xDE7E,(-7),0,(-3),1},{5,(-4),3,5,0xDE7E},{(-9),(-3),(-4),(-4),(-3)},{0xDE7E,1,(-4),0x09A5,0},{(-4),0xDE7E,3,0xDE5D,0x09A5}},{{0xD503,5,0,(-9),(-3)},{(-4),(-9),(-7),(-3),(-7)},{0xDE7E,0xDE7E,0,(-3),0x6C36},{(-9),(-4),1,(-9),0xDE7E},{5,0xD503,(-4),0xDE5D,0xD503},{0xDE7E,(-4),8,0x09A5,(-7)}},{{3,1,3,0,(-7)},{(-4),3,0x06AE,1,8},{0xD503,1,0x6C36,(-4),1},{0xE168,1,0x06AE,8,(-9)},{1,3,3,1,0xE168},{1,(-4),0x09A5,0,(-4)}},{{0xE168,0xD503,0,0x06AE,(-7)},{0xD503,0xE168,3,0,0x06AE},{(-4),1,0xDE7E,1,(-4)},{3,1,0xE168,8,1},{1,0xE168,0x06AE,(-4),8},{1,0xD503,(-3),1,1}}};
    uint32_t l_1351 = 0xF5100CD3;
    uint8_t l_1363 = 255U;
    int16_t l_1383 = (-5);
    int32_t *l_1412 = &g_33[2];
    struct S0 **l_1431 = (void*)0;
    uint32_t l_1452 = 0U;
    int32_t ***l_1508 = &g_297;
    int32_t l_1614 = (-10);
    int32_t l_1706 = 1;
    int32_t l_1735 = (-1);
    struct S0 **l_1831 = &g_466;
    int32_t *l_1850 = (void*)0;
    int32_t l_1855 = 1;
    int32_t ***l_1893 = &g_297;
    int16_t l_1904 = 5;
    uint32_t l_1986 = 0xAF73F11C;
    int32_t l_2003 = 0xC4B060B8;
    int16_t l_2094[1];
    struct S0 l_2105 = {208,10300,473,864,61,1,1876,193,1};
    int8_t l_2176[1];
    int32_t *l_2212 = (void*)0;
    uint16_t l_2309[4] = {0x0F2B,0x0F2B,0x0F2B,0x0F2B};
    uint16_t l_2350 = 1U;
    struct S0 l_2370 = {772,208,47,347,326,0,-89,82,-1};
    int32_t *l_2437 = &l_1167[1][1];
    uint32_t l_2500 = 0xB3D0DFD0;
    int i, j, k;
    for (i = 0; i < 1; i++)
        l_1096[i] = &g_21;
    for (i = 0; i < 6; i++)
        l_1129[i] = 0xE8557963;
    for (i = 0; i < 1; i++)
        l_2094[i] = 4;
    for (i = 0; i < 1; i++)
        {
for (g_1240 = (-7); (g_1240 != (-23)); g_1240--)
    {
        int32_t *l_25 = &g_1240;
        int32_t **l_24[1][5] = {{&l_25,&l_25,&l_25,&l_25,&l_25}};
        int i, j;
        l_2212 = &g_11[0];
    };


                    l_2176[i] = 0x5C;}
    if (((!(l_991 <= (safe_div_func_uint32_t_u_u((safe_unary_minus_func_int16_t_s(g_27.f1)), 0x71FB2D1A)))) > (l_991 , g_4)))
    {
        int32_t *l_1024 = (void*)0;
        int16_t l_1053 = 0;
        int32_t *l_1067 = &g_11[0];
        uint32_t l_1119 = 4294967295U;
        struct S0 *l_1144 = &g_210;
        if (l_991)
        {
            int16_t l_1025[9] = {0x25BB,0x25BB,0x9403,0x25BB,0x25BB,0x9403,0x25BB,0x25BB,0x9403};
            int32_t *l_1028 = &g_21;
            int32_t ***l_1036 = &g_297;
            int32_t l_1051[8] = {(-2),(-2),0x49B69B4F,(-2),(-2),0x49B69B4F,(-2),(-2)};
            struct S0 l_1146 = {455,1102,-24,303,249,0,-2001,173,0x96};
            int i;
            for (g_80 = 3; (g_80 >= 0); g_80 -= 1)
            {
                struct S0 ***l_1017 = &g_465;
                int32_t l_1026 = 0xF68FD735;
                int32_t **l_1027 = &g_944[6][0][7];
                struct S0 l_1093 = {956,5097,355,1225,202,-1,-1964,61,0x03};
                (*l_1027) = &l_1026;


                (*l_1027) = l_1028;

{
                int32_t *l_1433 = &g_11[0];
                int32_t l_1451 = 0x78DACA4D;
                struct S0 ***l_1493 = (void*)0;
                uint16_t l_1500 = 65532U;
                uint32_t l_1513 = 0U;
            }

                    for (l_1009 = 0; (l_1009 <= 3); l_1009 += 1)
                {
                    uint32_t l_1039[9];
                    int32_t **l_1063 = &l_1024;
                    int i;
                    for (i = 0; i < 9; i++)
                        {
{
        uint16_t l_2940[8] = {0U,0U,0U,0U,0U,0U,0U,0U};
        int i;
        for (g_21 = 0; (g_21 > (-15)); g_21 = safe_sub_func_int32_t_s_s(g_21, 1))
        {
            uint16_t l_2954 = 0xBB7C;
            struct S0 **l_2955 = (void*)0;
            (*(&l_1735)) = 0x64EAFE29;
            for (g_2805 = 0; (g_2805 <= 3); g_2805 += 1)
            {
                struct S0 ***l_2957 = &g_2531[1][1];
                int16_t l_2958 = 0x8258;
                int i, j, k;
            }
        }
    }

                    l_1039[i] = 0x85EF642C;}
                    (*p_50) = ((((((0xFC27 || (safe_sub_func_int8_t_s_s(((void*)0 != &p_50), 0xC3))) <= (*l_1028)) || ((*l_1028) , 1U)) < g_1031[4]) >= (safe_div_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u(((&g_297 == l_1036) >= 0x4F), 0)) != 1U), 0x1254979A))) && (*p_50));
                    if ((safe_mod_func_int16_t_s_s((l_1039[8] , (((safe_mod_func_int32_t_s_s(((+(((safe_mul_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(((l_1017 != &g_465) & l_1039[8]), 1)), (p_54 == (safe_add_func_int8_t_s_s(((l_1039[4] <= (*p_50)) != l_1009), ((safe_mul_func_int16_t_s_s((l_1051[5] <= l_1052), p_54)) | 1)))))) && 0U) <= 65535U)) & 4294967295U), 1U)) | g_210.f1) || 0x6CF6)), 1U)))
                    {

l_2105.f8 -= 1;



{
                        int32_t **l_2503 = &(*l_1063);
                        (*l_2503) = l_1067;

                        (((*l_1063) == 0) ? (void) (0) : __assert_fail ("(*l_1063) == 0", "t.c", 823, __PRETTY_FUNCTION__));
                        (*l_2503) = (&g_2803);

                        ((((*l_1063) >= &l_1167[0][0] && (*l_1063) <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("((*l_1063) >= &l_1167[0][0] && (*l_1063) <= &l_1167[8][6])", "t.c", 826, __PRETTY_FUNCTION__));
                        if ((**l_2503))
                            break;
                        (*(&l_1706)) = (**l_2503);
                    }

                    (*l_1027) = &g_11[0];
                        (*l_1028) = 0xF85D6DC6;

g_2619 += 1;


                    if ((*p_50))
                            continue;
                    }
                    else
                    {
                        if (l_1053)
                            break;
                    }
                    if (l_1039[8])
                        break;
                    if ((*l_1028))
                        break;
                    for (g_4 = 0; (g_4 <= 3); g_4 += 1)
                    {
                        int32_t *l_1054[6][1] = {{&g_33[2]},{&g_11[0]},{&g_33[2]},{&g_11[0]},{&g_33[2]},{&g_11[0]}};
                        int i, j, k;
                        g_986[g_4][g_4][g_4] = l_1054[2][0];

for (l_1119 = 1; (l_1119 > 38); ++l_1119)
                {
                    int32_t *l_2419 = &g_11[0];
                    return l_2419;



                }
for (l_1119 = 22; (l_1119 > 12); l_1119 = safe_sub_func_uint32_t_u_u(l_1119, 8))
                {
                    int32_t *l_677 = &g_11[0];
                    (**(&g_297)) = l_677;

                    (((l_1067 >= &g_11[0] && l_1067 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_1067 >= &g_11[0] && l_1067 <= &g_11[0])", "t.c", 869, __PRETTY_FUNCTION__));
                };


                    ;


                    (*l_1027) = (((safe_add_func_uint16_t_u_u((safe_mul_func_uint16_t_u_u((safe_div_func_int32_t_s_s((safe_lshift_func_int8_t_s_u(0x32, 5)), (((l_991 > p_54) , 249U) && (l_1063 == l_1027)))), (((!(safe_rshift_func_int8_t_s_s(0, 2))) == (((l_1067 != (void*)0) ^ 0xFA0732C2) && p_54)) || l_1009))), g_210.f6)) , p_54) , p_50);
                    }
                }

{
                        (*(*g_297)) = (((safe_rshift_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_u(((safe_unary_minus_func_int8_t_s(((g_2054[7][0][1] , (!(*(*g_297)))) < (safe_sub_func_uint8_t_u_u((*(&l_2105)).f4, 0xD7))))) | (g_1484 & (-8))), (*l_1144).f1)) && (safe_sub_func_uint32_t_u_u((((*(&l_2105)).f5 > (~g_1484)) , l_1052), l_1052))), g_2054[7][0][1])) == l_1706) < l_1052);
                        (*(*p_51)) = ((safe_mod_func_uint32_t_u_u(((((safe_mul_func_int16_t_s_s(l_1052, (((l_1052 | (safe_add_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_u((-9), (*l_1144).f4)) , ((safe_sub_func_uint8_t_u_u((((*(*p_51)) || (safe_rshift_func_uint8_t_u_s((g_33[2] & (l_1052 != (0x9C > (((l_1986 == l_1052) != (*g_148)) , l_1052)))), l_1052))) != l_1052), l_1052)) && (*(&g_21)))), g_1484))) , (void*)0) != l_1017))) <= 0) & l_1052) & l_1052), 0x51332F8E)) ^ (*(&l_2105)).f5);
                        l_1217 = (*(&l_2105));
                    }

                    for (g_4 = 3; (g_4 >= 0); g_4 -= 1)
                {
                    int8_t l_1072 = (-1);
                    uint32_t l_1076 = 1U;
                    int32_t *l_1083 = &g_33[2];
                    struct S0 l_1095 = {631,1691,-119,1361,102,1,-551,267,-4};
                    if ((safe_div_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(l_1072, 1)), p_54)))
                    {
                        int32_t *l_1073 = (void*)0;
                        (*l_1027) = l_1073;
                        (*l_1027) = ((((+p_54) || (g_1031[4] <= (~(l_1076 ^ (safe_mod_func_uint16_t_u_u(((!((((safe_div_func_int16_t_s_s((l_1082 != l_1083), (((((safe_unary_minus_func_int32_t_s(1)) || (((((safe_add_func_uint16_t_u_u((0xFC05510A | ((safe_sub_func_uint32_t_u_u(0x237EEA70, (safe_add_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_s((g_33[2] , (*l_1083)), p_54)) > 0xA091E223), g_27.f3)))) , 1U)), 0xF723)) <= 7U) ^ g_80) , (*l_1083)) != 0x7BD9C737)) >= (*p_50)) , (*l_1082)) || p_54))) != g_210.f5) ^ (*l_1028)) , g_27.f1)) & g_210.f4), p_54)))))) == p_54) , (void*)0);
                    }
                    else
                    {
                        (*g_466) = l_1093;
                        if (g_1094)
                            continue;
                    }

if (l_1262)
                            break;

                    (*g_466) = l_1095;
                    for (l_1095.f8 = 3; (l_1095.f8 >= 0); l_1095.f8 -= 1)
                    {
                        int i, j, k;
                        g_986[(g_4 + 1)][(l_1095.f8 + 1)][g_80] = l_1096[0];
                        (*g_466) = ((l_1067 != g_986[(g_4 + 1)][(l_1095.f8 + 1)][g_80]) , ((p_54 > ((safe_mul_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u((((7 != (((g_210.f1 , 0) , 5) != (g_11[0] < (safe_rshift_func_uint16_t_u_u(((0xAB && (-8)) & 0x4915), g_27.f2))))) , p_54) & 247U), g_33[2])) ^ 1U), 250U)) > 1)) , (*p_53)));
                    }
                }
            }


            (*p_50) = (g_27.f1 <= (safe_lshift_func_uint8_t_u_s(((safe_div_func_uint16_t_u_u((safe_div_func_int32_t_s_s((*l_1082), (safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s((((void*)0 == (*g_465)) != (safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((2U >= g_784[1]), 2)), (((safe_add_func_int8_t_s_s(p_54, ((((-1) | ((((void*)0 == &g_466) >= g_210.f3) , p_54)) && g_1094) || 247U))) <= p_54) || l_1119)))), 1U)), g_210.f3)))), p_54)) & 0xA376), 0)));

{
                    uint32_t l_1785 = 0x464AA3C8;
                    int32_t *l_1786 = &l_1167[6][2];
                    (*(&l_1735)) = 0x15E7E107;
                    (*(&l_1735)) = (safe_mod_func_int32_t_s_s(0x375D5BBD, ((&(*(&p_52)) != (&p_52)) , (safe_rshift_func_uint16_t_u_u(((0x9E <= (((void*)0 == &l_1028) <= (safe_div_func_uint8_t_u_u((((safe_mod_func_uint16_t_u_u((*l_1144).f8, l_1785)) , l_1786) == (void*)0), p_54)))) < l_1904), 8)))));
                    for ((*(&l_1735)) = 1; ((*(&l_1735)) <= 4); (*(&l_1735)) += 1)
                    {
                        int i;
                        (*(&l_2437)) = ((0U < g_1031[(*(&l_1735))]) , &g_33[(*(&l_1735))]);
                    }
                }


l_1383 += 1;


                    for (g_210.f8 = 22; (g_210.f8 != (-14)); --g_210.f8)
            {
                int8_t l_1145 = 0;
                int32_t **l_1147[10] = {&g_32[0],&g_148,&g_32[0],&g_986[0][4][1],&g_986[0][4][1],&g_32[0],&g_148,&g_32[0],&g_986[0][4][1],&g_986[0][4][1]};
                int i;
                (*l_1028) = l_1122;
                l_1146 = (((safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(p_54, (*p_50))), g_27.f7)) == (safe_mul_func_int8_t_s_s((l_1129[3] | g_210.f3), g_80))) , (((safe_lshift_func_int16_t_s_u((p_54 < (safe_mod_func_int32_t_s_s((safe_mod_func_int16_t_s_s((safe_mul_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s((((safe_div_func_uint16_t_u_u(((l_1144 == p_53) < p_54), g_27.f3)) < g_210.f2) , l_1145), 0x9282)), 2)), l_1145)), g_33[2])), 1))), 9)) >= g_21) , (*p_53)));
                g_944[3][0][7] = l_1096[0];
            }
        }
        else
        {
            struct S0 l_1148 = {513,9870,-147,246,399,1,-1229,339,-7};
            int32_t *l_1149 = &g_11[0];
            g_32[1] = l_1082;
            (**g_465) = l_1148;
            return l_1149;


        }


    }
    else
    {
        uint16_t l_1163 = 0xC70C;
        int32_t *l_1168 = (void*)0;
        int32_t ***l_1173 = &g_297;
        int32_t l_1180 = 0xE5966CEA;
        int32_t l_1182 = 1;
        struct S0 **l_1203 = (void*)0;
        int32_t ***l_1214 = &g_297;
        uint32_t l_1341 = 4294967295U;
        int8_t l_1538 = 0xDF;
        int32_t ***l_1550 = &g_297;
        int32_t l_1551 = 0x58DAA0B5;
        uint32_t l_1583 = 0xAAF3E96A;
        for (l_1052 = 1; (l_1052 <= 4); l_1052 += 1)
        {
            struct S0 ***l_1162 = &g_465;
            int32_t **l_1169 = (void*)0;
            int32_t **l_1170 = &l_1082;
            int i;
            (**g_465) = (*g_466);
        }
        if (((((l_1163 < ((l_1163 ^ (((g_784[3] , l_1173) == &p_52) , ((((255U == (((*l_1082) && (safe_sub_func_uint32_t_u_u((1 ^ (~(((~((safe_add_func_uint32_t_u_u(0xBB6AE9AE, l_1180)) || 0x34)) <= g_27.f2) && l_1181))), p_54))) | p_54)) < p_54) | (-1)) & 250U))) >= g_27.f6)) || 0xA9) < l_1182) | 65531U))
        {
            int32_t l_1191 = 0x55505A39;
            struct S0 *l_1198 = &g_27;
            int32_t ***l_1213 = (void*)0;
            int32_t l_1318 = 3;
            int32_t l_1411 = (-4);
            int32_t *l_1417 = &l_1191;
            if ((!(-1)))
            {
                int16_t l_1184 = 0x7143;
                uint16_t l_1199 = 0x6469;
                int32_t **l_1200 = &g_32[1];
                (*l_1200) = p_50;
            }
            else
            {

for (g_2619 = 0; (g_2619 >= (-19)); --g_2619)
                    {
                        (**(&l_1198)) = (*(*l_1203));
                    };


                    (**g_465) = (*p_53);
            }
            (*l_1082) = (p_54 , (((l_1191 < (((p_54 == ((((0x3079 || ((((*g_465) == (*g_465)) != l_1191) || ((safe_mul_func_int8_t_s_s(((&g_466 == l_1203) == g_21), 255U)) & p_54))) , (*l_1082)) <= g_1094) & p_54)) , &l_1191) == &l_1167[5][0])) > (*l_1082)) <= g_210.f1));
            if ((~(((((safe_lshift_func_int8_t_s_u(((safe_rshift_func_int16_t_s_u((0x40 == (((g_11[0] >= (safe_sub_func_int16_t_s_s(g_27.f6, (safe_lshift_func_uint16_t_u_u(0x8C85, 9))))) , l_1213) != l_1214)), (safe_lshift_func_int16_t_s_s(g_210.f0, 10)))) < 4294967286U), ((((((p_54 < (-9)) == (*l_1082)) , (void*)0) != (void*)0) , 0x1611) ^ p_54))) , (*p_50)) < 0U) , l_1217) , p_54)))
            {
                int32_t *l_1220 = &l_1167[5][4];
                int32_t l_1239 = 5;
                int32_t l_1319 = 0x0E489A9E;
                uint16_t l_1349 = 1U;
                struct S0 ***l_1362[8];
                struct S0 *l_1407 = (void*)0;
                int32_t l_1410 = 9;
                int i;
                for (i = 0; i < 8; i++)
                    l_1362[i] = (void*)0;
                if ((*p_50))
                {
                    int32_t *l_1219 = &g_33[2];
                    struct S0 ***l_1250[4] = {&g_465,&g_465,&g_465,&g_465};
                    struct S0 l_1255 = {192,4318,-489,36,135,-0,1153,251,0x86};
                    int i;
                    if ((~p_54))
                    {
                        l_1219 = l_1219;
                        l_1220 = (void*)0;

                        ((l_1220 == 0) ? (void) (0) : __assert_fail ("l_1220 == 0", "t.c", 1032, __PRETTY_FUNCTION__));
                    }
                    else
                    {
                        int32_t **l_1241 = &g_32[0];
                        (*l_1220) = (safe_add_func_uint16_t_u_u((l_1219 == &g_11[0]), (((safe_add_func_uint32_t_u_u((((safe_rshift_func_uint16_t_u_s(g_210.f2, ((((*l_1219) & ((safe_rshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s(((safe_sub_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u(((void*)0 == &p_51), 10)), (((*p_53) , (((p_54 != p_54) || p_54) && p_54)) ^ 0x76))) >= p_54), (*l_1220))) >= l_1239), 0x8F)), 0)) == g_4)) >= p_54) < 0x6B1FB5AC))) > g_1031[4]) , (*l_1219)), g_1240)) || (*p_50)) <= (*l_1220))));

{
                        (*l_1407).f6 = (safe_lshift_func_int8_t_s_s((g_2647 & (l_1831 != ((safe_unary_minus_func_int32_t_s((3U != ((void*)0 != &l_1241)))) , g_465))), ((!(*p_53).f5) && (safe_mod_func_int16_t_s_s((~((void*)0 == (&p_53))), 0xC8AF)))));
                    }

                    (*l_1241) = (void*)0;
                        l_1180 = ((safe_mul_func_int16_t_s_s((p_54 > (safe_div_func_int32_t_s_s(((safe_sub_func_int8_t_s_s((0x76 ^ (0xFD != ((*l_1219) > (*p_50)))), (safe_mul_func_uint16_t_u_u(0x6A67, 0xFFEE)))) | (((l_1250[0] != (void*)0) , p_54) > 65535U)), (*l_1219)))), 0xC94C)) && p_54);
                        (*g_466) = (*p_53);
                    }

                    (((l_1220 >= &l_1167[0][0] && l_1220 <= &l_1167[8][6]) || l_1220 == 0) ? (void) (0) : __assert_fail ("(l_1220 >= &l_1167[0][0] && l_1220 <= &l_1167[8][6]) || l_1220 == 0", "t.c", 1048, __PRETTY_FUNCTION__));
                    l_1219 = &l_1167[4][3];

                    (((l_1219 >= &l_1167[0][0] && l_1219 <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("(l_1219 >= &l_1167[0][0] && l_1219 <= &l_1167[8][6])", "t.c", 1051, __PRETTY_FUNCTION__));
                }
                else
                {
                    (*l_1082) = (*p_50);
                }

                (((l_1220 >= &l_1167[0][0] && l_1220 <= &l_1167[8][6]) || l_1220 == 0) ? (void) (0) : __assert_fail ("(l_1220 >= &l_1167[0][0] && l_1220 <= &l_1167[8][6]) || l_1220 == 0", "t.c", 1058, __PRETTY_FUNCTION__));
                for (g_80 = (-2); (g_80 > (-21)); --g_80)
                {
                    int8_t l_1279 = 0;
                    int8_t l_1329 = (-1);
                    int32_t ***l_1336 = (void*)0;
                    int8_t l_1348 = 1;
                    struct S0 l_1350 = {599,171,-440,1398,438,-1,-231,342,0};
                    (*l_1214) = &p_50;

                    ((g_297 == &p_50) ? (void) (0) : __assert_fail ("g_297 == &p_50", "t.c", 1068, __PRETTY_FUNCTION__));
                    if ((((safe_mod_func_uint8_t_u_u((((+((((g_27.f3 , ((((safe_div_func_uint32_t_u_u(p_54, l_1279)) == ((void*)0 == (*g_296))) <= ((!((safe_rshift_func_int16_t_s_u(p_54, 5)) == ((safe_lshift_func_uint16_t_u_u(((((safe_rshift_func_int16_t_s_s((safe_mul_func_int16_t_s_s((l_1279 & (((((**l_1214) == ((p_54 >= p_54) , (*g_297))) || 0x4474) < 0xF0E8F346) & g_11[0])), l_1279)), g_784[0])) < g_27.f5) , l_1279) , g_27.f4), p_54)) && (***l_1173)))) , 0x66C85F8A)) , 0x993C)) != l_1279) , (*g_465)) != (void*)0)) > l_1279) & 0x8FA0), 5U)) , g_1271[2][1]) < l_1279))
                    {
                        (*p_50) = ((!(g_1094 && (safe_rshift_func_uint16_t_u_s(p_54, (p_54 != (safe_sub_func_int16_t_s_s((+((+(safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((((((&p_50 == ((p_54 > (safe_rshift_func_uint8_t_u_u(g_21, 2))) , &p_50)) && (***l_1214)) & ((((safe_sub_func_int8_t_s_s(((p_53 == p_53) & p_54), l_1279)) || 1) , g_210.f7) <= g_1094)) | 0x7B86) == 0) == p_54), 0x08)), p_54)), g_210.f4))) != 0)), l_1306[4][2][4]))))))) , 0);
                    }
                    else
                    {
                        int16_t l_1344 = 1;
                        int32_t ***l_1347 = &g_297;
                        (**g_297) = (+(((((((safe_rshift_func_uint16_t_u_s(((**g_297) && (*p_50)), (safe_add_func_uint16_t_u_u(g_11[0], ((safe_lshift_func_int16_t_s_u((((void*)0 != &g_297) >= p_54), (safe_div_func_int8_t_s_s((g_784[3] , ((p_54 <= (safe_rshift_func_uint16_t_u_s(65529U, 2))) && (***l_1173))), p_54)))) && 0x4B36))))) < 255U) < p_54) < g_33[2]) ^ l_1318) == 0) < 0x6094));
                        (**l_1173) = (**l_1173);
                        (**g_297) = ((((((safe_mul_func_int16_t_s_s((((void*)0 == (*g_297)) ^ ((g_210.f7 , (***g_296)) ^ (safe_div_func_int16_t_s_s((((safe_rshift_func_int16_t_s_s((l_1336 != (((safe_add_func_uint8_t_u_u(g_210.f0, (safe_sub_func_int8_t_s_s(l_1341, (safe_mod_func_int16_t_s_s((l_1344 | (safe_mod_func_uint32_t_u_u((p_53 == (void*)0), l_1344))), (-8))))))) && 0x3B) , l_1347)), p_54)) , 0xD8) < p_54), g_1031[3])))), l_1348)) && (***l_1347)) < 0xD0DF30A5) ^ (*l_1082)) | (***g_296)) , l_1349);
                        l_1350 = (*p_53);
                    }
                }

                ((g_297 == &p_50 || g_297 == 0) ? (void) (0) : __assert_fail ("g_297 == &p_50 || g_297 == 0", "t.c", 1084, __PRETTY_FUNCTION__));
                if ((l_1351 , (((0xFED2 == (l_1318 >= ((((1 && (((((p_50 != (void*)0) & (safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((safe_mul_func_int16_t_s_s((safe_div_func_uint16_t_u_u(p_54, p_54)), (safe_add_func_int32_t_s_s((((&g_465 == l_1362[5]) != (*p_50)) >= l_1363), (*p_50))))), g_784[3])), g_784[3]))) ^ g_1031[3]) <= l_1191) > p_54)) > p_54) == 0x9A) < (*l_1082)))) & 0xCABBB83D) , l_1191)))
                {
                    for (l_1341 = (-6); (l_1341 != 19); l_1341 = safe_add_func_int8_t_s_s(l_1341, 5))
                    {
                        struct S0 *l_1374 = &l_1217;
                        uint8_t l_1375 = 0xEB;
                        int32_t **l_1384 = &g_944[6][1][4];

{
                    int32_t *l_1219 = &g_33[2];
                    struct S0 ***l_1250[4] = {&l_1431,&l_1431,&l_1431,&l_1431};
                    struct S0 l_1255 = {192,4318,-489,36,135,-0,1153,251,0x86};
                    int i;
                    if ((~l_1363))
                    {
                        l_1219 = l_1219;
                        (*g_297) = (void*)0;

                        (((*g_297) == 0) ? (void) (0) : __assert_fail ("(*g_297) == 0", "t.c", 1103, __PRETTY_FUNCTION__));
                    }
                    else
                    {
                        int32_t **l_1241 = &g_32[0];
                        (*(*g_297)) = (safe_add_func_uint16_t_u_u((l_1219 == &g_11[0]), (((safe_add_func_uint32_t_u_u((((safe_rshift_func_uint16_t_u_s((*l_1198).f2, ((((*l_1219) & ((safe_rshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s(((safe_sub_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u(((void*)0 == &(*l_1893)), 10)), (((*l_1407) , (((l_1363 != l_1363) || l_1363) && l_1363)) ^ 0x76))) >= l_1363), (*(*g_297)))) >= g_2956), 0x8F)), 0)) == l_1904)) >= l_1363) < 0x6B1FB5AC))) > g_1031[4]) , (*l_1219)), l_1855)) || (*(&l_1706))) <= (*(*g_297)))));
                        (*l_1241) = (void*)0;
                        l_1855 = ((safe_mul_func_int16_t_s_s((l_1363 > (safe_div_func_int32_t_s_s(((safe_sub_func_int8_t_s_s((0x76 ^ (0xFD != ((*l_1219) > (*(&l_1706))))), (safe_mul_func_uint16_t_u_u(0x6A67, 0xFFEE)))) | (((l_1250[0] != (void*)0) , l_1363) > 65535U)), (*l_1219)))), 0xC94C)) && l_1363);
                        (*(&l_1217)) = (*l_1407);
                    }

                    ((((*g_297) >= &l_1167[0][0] && (*g_297) <= &l_1167[8][6]) || (*g_297) == 0) ? (void) (0) : __assert_fail ("((*g_297) >= &l_1167[0][0] && (*g_297) <= &l_1167[8][6]) || (*g_297) == 0", "t.c", 1114, __PRETTY_FUNCTION__));
                    l_1219 = &l_1167[4][3];

                    (((l_1219 >= &l_1167[0][0] && l_1219 <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("(l_1219 >= &l_1167[0][0] && l_1219 <= &l_1167[8][6])", "t.c", 1117, __PRETTY_FUNCTION__));
                }

                    (*l_1384) = ((safe_sub_func_int8_t_s_s(g_27.f6, (safe_add_func_uint32_t_u_u(((safe_add_func_int8_t_s_s((-5), (safe_add_func_int8_t_s_s(0x81, (((l_1374 != p_53) | l_1375) && (safe_lshift_func_int8_t_s_s(g_1094, (safe_add_func_uint8_t_u_u(((*p_50) > ((!(safe_mul_func_uint8_t_u_u(g_210.f1, (-9)))) || 0xBB08)), 0x6F))))))))) ^ l_1383), 4294967294U)))) , (void*)0);
                    }
                }
                else
                {
                    int16_t l_1402 = (-1);
                    int32_t *l_1415 = &g_21;

{
                    int32_t *l_1219 = &g_33[2];
                    struct S0 ***l_1250[4] = {&l_1203,&l_1203,&l_1203,&l_1203};
                    struct S0 l_1255 = {192,4318,-489,36,135,-0,1153,251,0x86};
                    int i;
                    if ((~l_1363))
                    {
                        l_1219 = l_1219;
                        l_2437 = (void*)0;

                        ((l_2437 == 0) ? (void) (0) : __assert_fail ("l_2437 == 0", "t.c", 1138, __PRETTY_FUNCTION__));
                    }
                    else
                    {
                        int32_t **l_1241 = &g_32[0];
                        (*l_2437) = (safe_add_func_uint16_t_u_u((l_1219 == &g_11[0]), (((safe_add_func_uint32_t_u_u((((safe_rshift_func_uint16_t_u_s(g_27.f2, ((((*l_1219) & ((safe_rshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s(((safe_sub_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u(((void*)0 == &p_51), 10)), (((*(&l_1217)) , (((l_1363 != l_1363) || l_1363) && l_1363)) ^ 0x76))) >= l_1363), (*l_2437))) >= l_1318), 0x8F)), 0)) == l_1181)) >= l_1363) < 0x6B1FB5AC))) > g_1031[4]) , (*l_1219)), l_1706)) || (*(&i))) <= (*l_2437))));
                        (*l_1241) = (void*)0;

g_2318 += 1;


                    l_1706 = ((safe_mul_func_int16_t_s_s((l_1363 > (safe_div_func_int32_t_s_s(((safe_sub_func_int8_t_s_s((0x76 ^ (0xFD != ((*l_1219) > (*(&i))))), (safe_mul_func_uint16_t_u_u(0x6A67, 0xFFEE)))) | (((l_1250[0] != (void*)0) , l_1363) > 65535U)), (*l_1219)))), 0xC94C)) && l_1363);
                        (*(&l_1217)) = (*(&l_1217));
                    }

                    (((l_2437 >= &l_1167[0][0] && l_2437 <= &l_1167[8][6]) || l_2437 == 0) ? (void) (0) : __assert_fail ("(l_2437 >= &l_1167[0][0] && l_2437 <= &l_1167[8][6]) || l_2437 == 0", "t.c", 1153, __PRETTY_FUNCTION__));

{
                        int32_t l_229 = 0xD1979944;
                        int32_t l_232[2];
                        struct S0 l_250 = {931,139,-316,1333,426,1,-370,282,0x71};
                        struct S0 *l_251 = &(*p_53);
                        int16_t l_257 = 9;
                        int i;
                        for (i = 0; i < 2; i++)
                            l_232[i] = 0xBE73AF67;
                        (**(*l_1550)) = (*(&l_1706));
                        (*l_1214) = &l_2437;

                        (((*l_1214) == &l_2437) ? (void) (0) : __assert_fail ("(*l_1214) == &l_2437", "t.c", 1167, __PRETTY_FUNCTION__));
                        (*l_251) = ((((+(((((**(*l_1893)) , (l_229 == ((g_33[2] == (0 > l_232[1])) ^ (l_1383 <= (((safe_lshift_func_int16_t_s_u((safe_mul_func_int16_t_s_s(0xDFC1, ((~(safe_sub_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_mul_func_int8_t_s_s(l_2003, ((((safe_div_func_uint16_t_u_u(((safe_div_func_int32_t_s_s((l_1904 >= l_1383), g_33[0])) < g_210.f7), g_210.f2)) >= 0x1CCE74E1) == g_1484) & g_1094))), 4)), g_4))) | (*l_2437)))), l_1383)) != 0xB84F7E7F) >= l_1402))))) || 0x399F47FE) ^ 0x98) , (**(*l_1893)))) , l_2370) , g_210) , l_250);
                        (*p_52) = ((((safe_unary_minus_func_int16_t_s(((((safe_add_func_int8_t_s_s(l_1904, (safe_unary_minus_func_uint32_t_u(((*(&l_1706)) <= ((g_4 >= l_1402) | ((g_210.f0 < (&l_250 != ((*(&l_1706)) , p_53))) < l_2003))))))) | l_250.f3) , l_257) , 0xC70D))) , (void*)0) == &g_32[1]) , (void*)0);

                        (((*p_52) == 0) ? (void) (0) : __assert_fail ("(*p_52) == 0", "t.c", 1171, __PRETTY_FUNCTION__));
                    }

                    l_1219 = &l_1167[4][3];

                    (((l_1219 >= &l_1167[0][0] && l_1219 <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("(l_1219 >= &l_1167[0][0] && l_1219 <= &l_1167[8][6])", "t.c", 1176, __PRETTY_FUNCTION__));
                }

                    (*l_1082) = (safe_div_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((safe_lshift_func_int16_t_s_u(((safe_div_func_int32_t_s_s(((void*)0 != &l_1167[4][2]), (safe_mul_func_uint8_t_u_u((g_784[1] >= ((safe_div_func_uint16_t_u_u(((safe_mul_func_int8_t_s_s(0xAE, ((*p_50) <= (!(*p_50))))) | ((((*l_1082) < (((safe_add_func_int8_t_s_s(((((((*p_50) == p_54) || 65535U) , (void*)0) != &g_466) > (*p_50)), g_80)) || g_33[2]) && 0xF8180D4D)) && p_54) , 0)), p_54)) != g_27.f4)), g_11[0])))) && l_1402), 15)), g_784[1])), 0x40));
                    l_1412 = ((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((((l_1407 != &l_1217) , 0x813C1E7A) & (p_54 && ((((void*)0 == p_53) | g_210.f4) < ((((safe_rshift_func_uint8_t_u_s(p_54, 4)) <= g_4) ^ l_1410) || 0x6C)))), l_1411)), 0x9F)) , &g_11[0]);

                    (((l_1412 >= &g_11[0] && l_1412 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_1412 >= &g_11[0] && l_1412 <= &g_11[0])", "t.c", 1182, __PRETTY_FUNCTION__));
                    for (l_1182 = 0; (l_1182 >= 11); l_1182 = safe_add_func_int8_t_s_s(l_1182, 7))
                    {
                        int32_t **l_1416[5];
                        int i;


if (g_784[g_2351])
                            break;


{
                    int32_t *l_1712 = (void*)0;
                    l_1712 = &g_11[0];

                    (((l_1712 >= &g_11[0] && l_1712 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_1712 >= &g_11[0] && l_1712 <= &g_11[0])", "t.c", 1197, __PRETTY_FUNCTION__));
                    for (l_1452 = 0; (l_1452 <= 2); l_1452 += 1)
                    {
                        int i;
                        return g_32[l_1452];



                    }
                }

                    for ((*l_1412) = 0; ((*l_1412) == 6); ++(*l_1412))
                    {
                        (*(*l_1214)) = (*p_51);

{
        uint8_t l_76 = 4U;
        int32_t *l_478 = &g_2803;
        int i;
        for (g_2803 = 0; (g_2803 <= 4); g_2803 += 1)
        {
            int i;
        }
        g_33[(g_2318 + 1)] = g_33[(g_2318 + 1)];
        g_32[g_2318] = &g_33[(g_2318 + 1)];
    }

                    if ((*(*p_51)))
                            {
(*l_2437) += 1;


                    break;}
                    };



{
                        int32_t **l_2503 = &g_148;
                        (*l_2503) = (*p_52);

                        ((g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == 0", "t.c", 1238, __PRETTY_FUNCTION__));
                        (*l_2503) = (&g_21);

                        (((g_148 >= &l_1167[0][0] && g_148 <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("(g_148 >= &l_1167[0][0] && g_148 <= &l_1167[8][6])", "t.c", 1241, __PRETTY_FUNCTION__));
                        if ((**l_2503))
                            break;
                        (*(&k)) = (**l_2503);
                    }


for (l_1452 = 0; (l_1452 <= 0); l_1452 += 1)
                    {
                        int i;
                        (*(*l_1550)) = &g_11[l_1538];

                        ((((&l_1706) >= &g_11[0] && (&l_1706) <= &g_11[0])) ? (void) (0) : __assert_fail ("((&l_1706) >= &g_11[0] && (&l_1706) <= &g_11[0])", "t.c", 1253, __PRETTY_FUNCTION__));
                    };


                    for (i = 0; i < 5; i++)
                            l_1416[i] = &g_986[1][2][3];
                        g_148 = l_1415;

                        ((g_148 == &g_21) ? (void) (0) : __assert_fail ("g_148 == &g_21", "t.c", 1261, __PRETTY_FUNCTION__));
                    }

                    ((g_148 == &g_21 || g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("g_148 == &g_21 || g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 1264, __PRETTY_FUNCTION__));
                }

                ((g_148 == &g_21 || g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("g_148 == &g_21 || g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 1267, __PRETTY_FUNCTION__));
                (((l_1412 >= &g_11[0] && l_1412 <= &g_11[0]) || (l_1412 >= &g_33[0] && l_1412 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_1412 >= &g_11[0] && l_1412 <= &g_11[0]) || (l_1412 >= &g_33[0] && l_1412 <= &g_33[4])", "t.c", 1268, __PRETTY_FUNCTION__));
            }
            else
            {
                int32_t **l_1418 = &l_1412;
                int32_t *l_1419 = (void*)0;


for ((*l_2437) = 0; (*l_2437) < 1; (*l_2437)++)
        l_1096[(*l_2437)] = &(*l_2437);

                    l_1904 -= 1;


                    (*l_1418) = l_1417;

                ((l_1412 == &l_1191) ? (void) (0) : __assert_fail ("l_1412 == &l_1191", "t.c", 1284, __PRETTY_FUNCTION__));
                return l_1419;


            }

            ((g_148 == &g_21 || g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("g_148 == &g_21 || g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 1290, __PRETTY_FUNCTION__));
            ((g_297 == &p_50 || g_297 == 0) ? (void) (0) : __assert_fail ("g_297 == &p_50 || g_297 == 0", "t.c", 1291, __PRETTY_FUNCTION__));
            (((l_1412 >= &g_11[0] && l_1412 <= &g_11[0]) || (l_1412 >= &g_33[0] && l_1412 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_1412 >= &g_11[0] && l_1412 <= &g_11[0]) || (l_1412 >= &g_33[0] && l_1412 <= &g_33[4])", "t.c", 1292, __PRETTY_FUNCTION__));

for (l_1452 = 22; (l_1452 > 12); l_1452 = safe_sub_func_uint32_t_u_u(l_1452, 8))
                {
                    int32_t *l_677 = &g_11[0];
                    (**l_1508) = l_677;

                    ((((&g_21) >= &g_11[0] && (&g_21) <= &g_11[0])) ? (void) (0) : __assert_fail ("((&g_21) >= &g_11[0] && (&g_21) <= &g_11[0])", "t.c", 1299, __PRETTY_FUNCTION__));
                };


                    (**g_465) = (*l_1198);
        }
        else
        {
            int32_t **l_1420 = &l_1096[0];
            struct S0 ***l_1436 = &g_465;
            int32_t l_1453 = 0xA004A054;

if (((*p_53).f1 == ((safe_mul_func_uint16_t_u_u(0x3B46, g_11[0])) , (((safe_div_func_uint8_t_u_u((l_1452 != (safe_lshift_func_int16_t_s_u((((((((((((void*)0 == (*(&l_1203))) , (*l_1203)) == ((((((((*p_53).f0 , (&l_1551)) != (*(&l_1412))) , 1U) > l_1538) , 0x5D39) >= l_1452) , (void*)0)) <= l_1452) || (**(&l_1412))) , l_1538) , 0U) > l_1538) ^ (*l_1082)) && l_1452), (*p_53).f8))), 1U)) , (-2)) ^ 1U))))
    {
        (**(&l_1412)) = (**(&l_1412));
        (*(*l_1893)) = (*(&l_1412));

        ((((*p_52) >= &g_33[0] && (*p_52) <= &g_33[4])) ? (void) (0) : __assert_fail ("((*p_52) >= &g_33[0] && (*p_52) <= &g_33[4])", "t.c", 1316, __PRETTY_FUNCTION__));
        (*(*l_1893)) = (*(&l_1412));
    }
    else
    {
        int32_t *l_893 = (void*)0;
        return l_893;



    };


                    (*l_1420) = p_50;


            for (l_1182 = 3; (l_1182 >= 0); l_1182 -= 1)
            {
                int32_t *l_1433 = &g_11[0];
                int32_t l_1451 = 0x78DACA4D;
                struct S0 ***l_1493 = (void*)0;
                uint16_t l_1500 = 65532U;
                uint32_t l_1513 = 0U;
            }
        }

        ((g_148 == &g_21 || g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("g_148 == &g_21 || g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 1342, __PRETTY_FUNCTION__));
        ((g_297 == &p_50 || g_297 == 0) ? (void) (0) : __assert_fail ("g_297 == &p_50 || g_297 == 0", "t.c", 1343, __PRETTY_FUNCTION__));

        (((l_1412 >= &g_11[0] && l_1412 <= &g_11[0]) || (l_1412 >= &g_33[0] && l_1412 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_1412 >= &g_11[0] && l_1412 <= &g_11[0]) || (l_1412 >= &g_33[0] && l_1412 <= &g_33[4])", "t.c", 1345, __PRETTY_FUNCTION__));
        if (((((*p_53) , ((-7) >= (safe_rshift_func_int8_t_s_s((safe_mod_func_uint8_t_u_u(1U, g_27.f4)), 3)))) , &l_1431) != &g_465))
        {
            int32_t ***l_1560 = &g_297;
            uint32_t l_1561 = 1U;
            (**g_465) = (((safe_rshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u(((void*)0 == l_1560), ((g_33[3] <= g_27.f5) , (((p_54 & p_54) <= l_1561) & ((((-1) | (safe_mul_func_uint16_t_u_u(((+((safe_sub_func_int8_t_s_s(((*p_53) , 0x8C), g_210.f2)) ^ (*p_50))) > g_11[0]), 5))) >= g_210.f7) != (*l_1082)))))), 4)) || p_54) , (*p_53));
        }
        else
        {
            struct S0 ***l_1573 = &g_465;
            int32_t l_1584 = 0x3E9E2198;
            l_1584 = (safe_sub_func_int8_t_s_s(((safe_div_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u((((((void*)0 == l_1573) < (g_27.f4 == (((0xA69270CB <= (safe_mod_func_int32_t_s_s((*p_50), (safe_lshift_func_uint8_t_u_u((0x1A435ED4 || 0x293A6C42), ((safe_div_func_uint32_t_u_u(((((((((+(((safe_div_func_int16_t_s_s(((&g_297 == &p_51) != p_54), (-1))) && 6U) , l_1583)) <= 1) ^ p_54) , (*p_53)) , (*g_466)) , (*l_1508)) == (void*)0) == p_54), (*p_50))) | (*p_50))))))) , &g_11[0]) != (void*)0))) < p_54) && 0xFCF112B4), 13)), p_54)) ^ 0xD9BD5AFF), 0xAE));
        }
    }

    ((g_148 == &g_21 || g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("g_148 == &g_21 || g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 1360, __PRETTY_FUNCTION__));
    ((g_297 == &p_50 || g_297 == 0) ? (void) (0) : __assert_fail ("g_297 == &p_50 || g_297 == 0", "t.c", 1361, __PRETTY_FUNCTION__));


    (((l_1412 >= &g_11[0] && l_1412 <= &g_11[0]) || (l_1412 >= &g_33[0] && l_1412 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_1412 >= &g_11[0] && l_1412 <= &g_11[0]) || (l_1412 >= &g_33[0] && l_1412 <= &g_33[4])", "t.c", 1364, __PRETTY_FUNCTION__));

for (l_2003 = 4; (l_2003 >= 1); l_2003 -= 1)
                    {
                        int i;
                        g_11[l_1262] = (g_1484 || 0x38);
                        l_1082 = l_1412;

{
                    int32_t *l_2419 = &g_11[0];

{
                        struct S0 l_389[5] = {{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43}};
                        struct S0 *l_390 = (void*)0;
                        struct S0 *l_391 = &l_389[4];
                        int32_t *l_395 = &(*l_1082);
                        int i;
                        (*l_391) = l_389[4];
                        l_991 = (safe_rshift_func_int8_t_s_s(l_2370.f5, 3));
                        l_2437 = l_395;

                        ((l_2437 == &(*l_1082)) ? (void) (0) : __assert_fail ("l_2437 == &(*l_1082)", "t.c", 1385, __PRETTY_FUNCTION__));
                    }

                    return l_2419;



                }

                    g_210 = g_27;
                    };


                    if ((((safe_mul_func_uint16_t_u_u(((((safe_add_func_int32_t_s_s((((safe_rshift_func_uint8_t_u_s(((((*l_1082) == (*l_1082)) | (g_27.f1 > ((*l_1082) >= ((0x7836 > (-1)) <= (safe_sub_func_uint32_t_u_u((safe_rshift_func_int16_t_s_s(g_80, 7)), (*l_1082))))))) == (safe_sub_func_uint8_t_u_u(g_1031[0], g_784[3]))), g_4)) != p_54) , (*l_1082)), (*l_1412))) >= g_210.f8) == 0x553A) , g_1031[4]), 1)) > g_4) , 0x11F6AFA3))
    {
        uint16_t l_1597 = 65528U;
        int32_t **l_1608 = &g_986[1][5][2];
        uint16_t l_1609[6][7][6] = {{{0x02EE,0xE191,0xE191,0x02EE,1U,1U},{0x02EE,1U,1U,0U,0xE191,1U},{0x884F,0x3595,0xE191,0xB230,0xE191,0x3595},{0U,1U,0xAD39,0xB230,1U,0xE191},{0x884F,0xE191,0xAD39,0U,0x3595,0x3595},{0x02EE,0xE191,0xE191,0x02EE,1U,1U},{0x02EE,1U,1U,0U,0xE191,1U}},{{0x884F,0x3595,0xE191,0xB230,0xE191,0x3595},{0U,1U,0xAD39,0xB230,1U,0xE191},{0x884F,0xE191,0xAD39,0U,0x3595,0x3595},{0x02EE,0xE191,0xE191,0x02EE,1U,1U},{0x02EE,1U,1U,0U,0xE191,1U},{0x884F,0x3595,0xE191,0xB230,0xE191,0x3595},{0U,1U,0xAD39,0xB230,1U,0xE191}},{{0x884F,0xE191,0xAD39,0U,0x3595,0xE347},{0xAD39,0x6674,0x6674,0xAD39,65535U,2U},{0xAD39,65535U,2U,1U,0x6674,2U},{0xE191,0xE347,0x6674,1U,0x6674,0xE347},{1U,65535U,0x9E0E,1U,65535U,0x6674},{0xE191,0x6674,0x9E0E,1U,0xE347,0xE347},{0xAD39,0x6674,0x6674,0xAD39,65535U,2U}},{{0xAD39,65535U,2U,1U,0x6674,2U},{0xE191,0xE347,0x6674,1U,0x6674,0xE347},{1U,65535U,0x9E0E,1U,65535U,0x6674},{0xE191,0x6674,0x9E0E,1U,0xE347,0xE347},{0xAD39,0x6674,0x6674,0xAD39,65535U,2U},{0xAD39,65535U,2U,1U,0x6674,2U},{0xE191,0xE347,0x6674,1U,0x6674,0xE347}},{{1U,65535U,0x9E0E,1U,65535U,0x6674},{0xE191,0x6674,0x9E0E,1U,0xE347,0xE347},{0xAD39,0x6674,0x6674,0xAD39,65535U,2U},{0xAD39,65535U,2U,1U,0x6674,2U},{0xE191,0xE347,0x6674,1U,0x6674,0xE347},{1U,65535U,0x9E0E,1U,65535U,0x6674},{0xE191,0x6674,0x9E0E,1U,0xE347,0xE347}},{{0xAD39,0x6674,0x6674,0xAD39,65535U,2U},{0xAD39,65535U,2U,1U,0x6674,2U},{0xE191,0xE347,0x6674,1U,0x6674,0xE347},{1U,65535U,0x9E0E,1U,65535U,0x6674},{0xE191,0x6674,0x9E0E,1U,0xE347,0xE347},{0xAD39,0x6674,0x6674,0xAD39,65535U,2U},{0xAD39,65535U,2U,1U,0x6674,2U}}};
        int8_t l_1631 = (-1);
        int32_t *l_1645 = &g_33[1];
        int16_t l_1806[4];
        int32_t l_1811 = 0x9220D5ED;
        struct S0 ***l_1828 = &l_1431;
        struct S0 l_1988[1][10][6] = {{{{930,10484,-33,408,498,-1,-2044,351,0x20},{667,1881,484,1397,443,-1,-1876,345,1},{862,10148,-29,791,60,-1,1396,225,0xA0},{629,3324,222,285,186,-1,-430,60,0x39},{862,10148,-29,791,60,-1,1396,225,0xA0},{667,1881,484,1397,443,-1,-1876,345,1}},{{862,10148,-29,791,60,-1,1396,225,0xA0},{930,10484,-33,408,498,-1,-2044,351,0x20},{472,474,97,1332,432,0,784,238,0x70},{375,5022,-201,935,395,1,-242,0,9},{375,5022,-201,935,395,1,-242,0,9},{472,474,97,1332,432,0,784,238,0x70}},{{862,10148,-29,791,60,-1,1396,225,0xA0},{862,10148,-29,791,60,-1,1396,225,0xA0},{375,5022,-201,935,395,1,-242,0,9},{629,3324,222,285,186,-1,-430,60,0x39},{873,5672,238,983,263,0,568,315,0x21},{629,3324,222,285,186,-1,-430,60,0x39}},{{930,10484,-33,408,498,-1,-2044,351,0x20},{862,10148,-29,791,60,-1,1396,225,0xA0},{930,10484,-33,408,498,-1,-2044,351,0x20},{472,474,97,1332,432,0,784,238,0x70},{375,5022,-201,935,395,1,-242,0,9},{375,5022,-201,935,395,1,-242,0,9}},{{667,1881,484,1397,443,-1,-1876,345,1},{930,10484,-33,408,498,-1,-2044,351,0x20},{930,10484,-33,408,498,-1,-2044,351,0x20},{667,1881,484,1397,443,-1,-1876,345,1},{873,5672,238,983,263,0,568,315,0x21},{472,474,97,1332,432,0,784,238,0x70}},{{472,474,97,1332,432,0,784,238,0x70},{930,10484,-33,408,498,-1,-2044,351,0x20},{862,10148,-29,791,60,-1,1396,225,0xA0},{930,10484,-33,408,498,-1,-2044,351,0x20},{472,474,97,1332,432,0,784,238,0x70},{375,5022,-201,935,395,1,-242,0,9}},{{930,10484,-33,408,498,-1,-2044,351,0x20},{472,474,97,1332,432,0,784,238,0x70},{375,5022,-201,935,395,1,-242,0,9},{375,5022,-201,935,395,1,-242,0,9},{472,474,97,1332,432,0,784,238,0x70},{930,10484,-33,408,498,-1,-2044,351,0x20}},{{629,3324,222,285,186,-1,-430,60,0x39},{930,10484,-33,408,498,-1,-2044,351,0x20},{873,5672,238,983,263,0,568,315,0x21},{472,474,97,1332,432,0,784,238,0x70},{873,5672,238,983,263,0,568,315,0x21},{930,10484,-33,408,498,-1,-2044,351,0x20}},{{873,5672,238,983,263,0,568,315,0x21},{629,3324,222,285,186,-1,-430,60,0x39},{375,5022,-201,935,395,1,-242,0,9},{862,10148,-29,791,60,-1,1396,225,0xA0},{862,10148,-29,791,60,-1,1396,225,0xA0},{375,5022,-201,935,395,1,-242,0,9}},{{873,5672,238,983,263,0,568,315,0x21},{873,5672,238,983,263,0,568,315,0x21},{862,10148,-29,791,60,-1,1396,225,0xA0},{472,474,97,1332,432,0,784,238,0x70},{667,1881,484,1397,443,-1,-1876,345,1},{472,474,97,1332,432,0,784,238,0x70}}}};
        int32_t *l_2034[4][9][4] = {{{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21}},{{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21}},{{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21}},{{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21},{&g_21,&g_11[0],&g_11[0],&g_21},{&l_1167[6][6],&g_11[0],&g_11[0],&g_21}}};
        int16_t l_2127 = 0x6528;
        int32_t l_2146[7];
        int32_t l_2164 = 0xA94B3798;
        uint8_t l_2169[9][5][1] = {{{0xAC},{0U},{255U},{0U},{0xAC}},{{0x4A},{0x4A},{0xBE},{0x4A},{0x4A}},{{0xAC},{0U},{255U},{0U},{0x8B}},{{0x1D},{255U},{0x4A},{255U},{0x1D}},{{0x8B},{0xBE},{0xAC},{0xBE},{0x8B}},{{0x1D},{255U},{0x4A},{255U},{0x1D}},{{0x8B},{0xBE},{0xAC},{0xBE},{0x8B}},{{0x1D},{255U},{0x4A},{255U},{0x1D}},{{0x8B},{0xBE},{0xAC},{0xBE},{0x8B}}};
        int32_t *l_2291 = (void*)0;
        uint32_t l_2323 = 9U;
        int i, j, k;
        for (i = 0; i < 4; i++)
            l_1806[i] = 0x2AE3;
        for (i = 0; i < 7; i++)
            l_2146[i] = 0;
        if ((l_1597 , (p_54 ^ (safe_rshift_func_uint8_t_u_u(p_54, (safe_mod_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s((safe_mod_func_int32_t_s_s((((safe_div_func_int16_t_s_s(p_54, ((l_1608 == ((p_54 >= 0xBFE530C4) , (void*)0)) ^ l_1597))) < l_1609[4][4][0]) & 0x15), p_54)), 3)) , g_210.f1), g_21)))))))
        {
            int32_t l_1624 = 0x628DB18D;
            uint16_t l_1625[6] = {0x62D2,0x62D2,0x62D2,0x62D2,0x62D2,0x62D2};
            int32_t *l_1644 = &g_11[0];
            int8_t l_1650 = 0x66;
            uint8_t l_1716 = 249U;
            struct S0 **l_1768 = &g_466;
            int32_t l_1807 = 0xEB0E47A2;
            int32_t *l_1921 = &l_1811;
            int32_t l_1937[6][2][9] = {{{3,(-7),0x283AE863,0x9EC4EBA9,1,0x3F82680D,1,2,9},{0x92F47D50,7,0x9EC4EBA9,(-1),(-1),0x9EC4EBA9,7,0x92F47D50,(-1)}},{{1,(-1),2,0xE04201F9,3,0x571F4D4F,(-10),0x3F82680D,0xD54CC6FA},{0x1B72C53B,0x6864222F,0xCE274C68,0x88EB1EBE,0x746D1AB6,0x71218D43,1,3,(-1)}},{{0xCE274C68,0x1B72C53B,0xE04201F9,(-8),5,1,0xD54CC6FA,0x51722963,9},{6,0xF54EDA0C,7,0xD54CC6FA,(-7),0,0x38FFB9A0,(-10),0x72DEC890}},{{6,1,0x25CE7411,0,1,1,0,0x25CE7411,1},{0xCE274C68,0x51722963,(-7),0x9436678D,0x88EB1EBE,0x283AE863,9,5,0x571F4D4F}},{{0x1B72C53B,1,0xF54EDA0C,(-10),0xE1B54DE9,0xE04201F9,0x571F4D4F,1,0x88EB1EBE},{1,0x51722963,(-8),0x3F82680D,0x0A9A4735,(-1),(-1),0x88EB1EBE,5}},{{0x92F47D50,1,0x38FFB9A0,1,0x71218D43,0xF54EDA0C,0x746D1AB6,0x72DEC890,(-8)},{3,0xF54EDA0C,0x38FFB9A0,1,0x283AE863,0x0A9A4735,0x0A9A4735,0x283AE863,1}}};
            uint32_t l_1939 = 0x5C059D13;
            int i, j, k;

{
        int32_t *l_503 = &g_33[4];
        return l_503;


    }

                    if (((safe_mod_func_int8_t_s_s(((l_1614 || 0xE899) == (((safe_mul_func_int16_t_s_s((((g_33[3] && g_784[3]) , (((safe_lshift_func_int8_t_s_u(((+(((((p_53 != (void*)0) , (g_210.f3 <= ((((0xBF | (((safe_mod_func_int8_t_s_s(((0x0C63EB16 && 0x37A43F76) > (-7)), 1)) , 0x56C26C1F) , p_54)) <= g_27.f3) , g_27.f4) != l_1609[4][4][0]))) >= p_54) && 0xFA5D) <= (*p_50))) < (*p_50)), 4)) != 0U) <= p_54)) == 3), p_54)) , l_1624) >= (-1))), l_1625[1])) > g_27.f4))
            {
                int16_t l_1662[9] = {0x60FB,0x60FB,0x60FB,0x60FB,0x60FB,0x60FB,0x60FB,0x60FB,0x60FB};
                uint16_t l_1663 = 0x2A05;
                int32_t **l_1676 = (void*)0;
                int i;

for (l_2127 = (-5); (l_2127 != (-23)); l_2127 = safe_sub_func_uint32_t_u_u(l_2127, 7))
                    {
                        (*(*p_52)) = (*(&g_80));
                        (*(&g_80)) = ((1 || ((((safe_rshift_func_uint8_t_u_u(((~(safe_rshift_func_int16_t_s_s((safe_mod_func_int8_t_s_s(l_2370.f1, l_1811)), 0))) ^ g_1094), 2)) , ((*p_53).f6 , (*p_53).f7)) | ((safe_lshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(l_2370.f0, (safe_div_func_uint16_t_u_u((safe_unary_minus_func_int32_t_s((+(g_11[0] , (((void*)0 == &(*g_465)) || (*(&g_80))))))), 0xE6B3)))), 0)) != g_1094)) && l_1363)) || (-4));
                    };



{
            uint16_t l_2954 = 0xBB7C;
            struct S0 **l_2955 = (void*)0;
            (*l_2437) = 0x64EAFE29;
            for (l_991 = 0; (l_991 <= 3); l_991 += 1)
            {
                struct S0 ***l_2957 = &g_2531[1][1];
                int16_t l_2958 = 0x8258;
                int i, j, k;
            }
        }

                    (*l_1645) = (safe_rshift_func_int16_t_s_u((!((g_80 , ((safe_mod_func_int8_t_s_s(((l_1631 != (p_54 , (0xF8 >= 0x19))) > (safe_mod_func_uint16_t_u_u(p_54, (safe_sub_func_int32_t_s_s(((safe_sub_func_uint16_t_u_u(g_1271[2][1], ((safe_add_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u(g_4, (safe_rshift_func_uint8_t_u_u(((((&p_50 == (void*)0) && 9) , l_1644) != l_1645), 5)))), g_27.f7)) >= (-1)))) | (*l_1644)), 0x2153F809))))), 0x42)) , 9)) > (*l_1645))), 3));
                (*p_50) = (safe_add_func_int32_t_s_s((*l_1644), (safe_sub_func_int32_t_s_s(((((*l_1644) == l_1650) , g_1031[4]) | ((-9) == p_54)), (safe_rshift_func_int8_t_s_s(((*l_1644) <= (safe_unary_minus_func_int16_t_s(((((safe_mul_func_uint16_t_u_u(p_54, ((safe_rshift_func_uint16_t_u_s(((((safe_lshift_func_uint8_t_u_s((safe_sub_func_int16_t_s_s((4U <= p_54), l_1662[3])), (*l_1645))) > (*l_1644)) > p_54) || p_54), (*l_1644))) , g_27.f0))) >= g_210.f7) >= 0x75F9A0D7) | l_1663)))), p_54))))));
                if ((0xE37E | (((((safe_lshift_func_uint16_t_u_u((safe_div_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u((((l_1508 != (void*)0) , (((((((((safe_rshift_func_int16_t_s_u(((0x02 || (g_80 || (safe_mod_func_uint8_t_u_u((safe_div_func_uint32_t_u_u((0x47BAC912 && (((void*)0 == &g_466) , 1)), (*l_1645))), p_54)))) && 0xF4), g_27.f6)) , &g_11[0]) == (void*)0) || (*l_1644)) , (void*)0) == l_1676) , (*g_465)) == (*g_465)) > 0x3DE1)) , p_54), 1)), g_27.f0)), p_54)) != 0xF3C0) < p_54) , (-1)) | g_784[1])))
                {
                    for (g_21 = 4; (g_21 >= 0); g_21 -= 1)
                    {

{
                        l_2164 = (((safe_div_func_uint32_t_u_u(g_1484, l_1631)) , &(*l_1828)) == (&l_1431));
                        (*p_51) = (*p_51);
                        (*g_297) = (**l_1893);

                        (((*g_297) == 0 || ((*g_297) >= &g_11[0] && (*g_297) <= &g_11[0]) || ((*g_297) >= &g_33[0] && (*g_297) <= &g_33[4])) ? (void) (0) : __assert_fail ("(*g_297) == 0 || ((*g_297) >= &g_11[0] && (*g_297) <= &g_11[0]) || ((*g_297) >= &g_33[0] && (*g_297) <= &g_33[4])", "t.c", 1481, __PRETTY_FUNCTION__));
                    }

                    return (*l_1608);



                    }
                }
                else
                {
                    uint32_t l_1686 = 4294967293U;

for ((*g_148) = 0; (*g_148) < 9; (*g_148)++)
    {
        for ((*l_1412) = 0; (*l_1412) < 2; (*l_1412)++)
        {
            for ((*g_2221) = 0; (*g_2221) < 2; (*g_2221)++)
            {
                transparent_crc(g_2054[(*g_148)][(*l_1412)][(*g_2221)], "g_2054[(*g_148)][(*l_1412)][(*g_2221)]", (*l_1645));
                if ((*l_1645)) printf("index = [%d][%d][%d]\n", (*g_148), (*l_1412), (*g_2221));

            }
        }
    };


                    for (l_1262 = (-5); (l_1262 != (-23)); l_1262 = safe_sub_func_uint32_t_u_u(l_1262, 7))
                    {
                        (*l_1082) = (*p_50);
                        (*l_1412) = ((1 || ((((safe_rshift_func_uint8_t_u_u(((~(safe_rshift_func_int16_t_s_s((safe_mod_func_int8_t_s_s(g_27.f1, g_1240)), 0))) ^ l_1686), 2)) , (g_210.f6 , g_210.f7)) | ((safe_lshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(g_27.f0, (safe_div_func_uint16_t_u_u((safe_unary_minus_func_int32_t_s((+(g_11[0] , (((void*)0 == &g_466) || (*p_50)))))), 0xE6B3)))), 0)) != l_1686)) && p_54)) || (-4));
                    }
                }
            }
            else
            {
                int32_t l_1711 = 0xA6BF7172;
                int32_t l_1753 = 0;
                uint16_t l_1791 = 65532U;
                struct S0 ***l_1873 = &l_1768;
                if ((safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(((((!0xB5) , (safe_mod_func_uint16_t_u_u(l_1706, g_27.f8))) == (safe_add_func_int16_t_s_s((p_54 & (*p_50)), p_54))) == p_54), (safe_lshift_func_uint16_t_u_u(g_27.f3, 8)))), l_1711)), 9)), 0x95E60F64)))
                {
                    int32_t *l_1712 = (void*)0;
                    l_1712 = &g_11[0];

                    (((l_1712 >= &g_11[0] && l_1712 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_1712 >= &g_11[0] && l_1712 <= &g_11[0])", "t.c", 1526, __PRETTY_FUNCTION__));
                    for (l_1351 = 0; (l_1351 <= 2); l_1351 += 1)
                    {
                        int i;
                        return g_32[l_1351];



                    }
                }
                else
                {
                    int8_t l_1751 = 0;
                    int8_t l_1752 = (-6);
                    int32_t *l_1760 = &l_1167[6][6];

{
            uint16_t l_2775 = 0xE2FA;
            int16_t l_2804 = 8;
            struct S0 **l_2817[2][8][4] = {{{&(*l_1768),&(*l_1768),&(*l_1768),&(*l_1768)},{&(*l_1768),&(*l_1768),(void*)0,&(*l_1768)},{&(*l_1768),&(*l_1768),&(*l_1768),(void*)0},{&(*l_1768),(void*)0,(void*)0,(void*)0},{&(*l_1768),&(*l_1768),&(*l_1768),&(*l_1768)},{(void*)0,&(*l_1768),&(*l_1768),(void*)0},{&(*l_1768),&(*l_1768),(void*)0,&(*l_1768)},{&(*l_1768),&(*l_1768),&(*l_1768),(void*)0}},{{(void*)0,&(*l_1768),&(*l_1768),&(*l_1768)},{&(*l_1768),&(*l_1768),(void*)0,(void*)0},{&(*l_1768),&(*l_1768),&(*l_1768),&(*l_1768)},{&(*l_1768),&(*l_1768),(void*)0,&(*l_1768)},{&(*l_1768),&(*l_1768),&(*l_1768),(void*)0},{&(*l_1768),&(*l_1768),(void*)0,&(*l_1768)},{&(*l_1768),&(*l_1768),&(*l_1768),&(*l_1768)},{&(*l_1768),&(*l_1768),(void*)0,(void*)0}}};
            int32_t l_2882 = (-4);
            int32_t *l_2884[4][4][8] = {{{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]}},{{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]}},{{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]}},{{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]}}};
            int i, j, k;
        }

                    for (l_1711 = 0; (l_1711 <= (-6)); l_1711--)
                    {
                        int32_t *l_1715 = &g_11[0];
                        (*l_1608) = (void*)0;
                        (*l_1644) = (*p_50);

{
    int32_t *l_26 = &g_11[0];
    struct S0 *l_28 = &l_2105;
    for (l_1711 = (-7); (l_1711 != (-23)); l_1711--)
    {
        int32_t *l_25 = &l_1711;
        int32_t **l_24[1][5] = {{&l_25,&l_25,&l_25,&l_25,&l_25}};
        int i, j;
        l_26 = &g_11[0];
    }
    (*l_28) = l_2105;
    (*l_26) = func_5((safe_mul_func_uint16_t_u_u(0U, l_2105.f7)), (*l_1608), l_2105.f5);
    return l_26;


}

                    (*l_1608) = l_1715;
                    }
                    if (l_1716)
                    {
                        uint8_t l_1730 = 0xB5;
                        int32_t ***l_1733[5][5][9] = {{{&g_297,&g_297,&l_1608,&g_297,(void*)0,(void*)0,&l_1608,&l_1608,&l_1608},{&l_1608,&l_1608,(void*)0,&l_1608,&g_297,&l_1608,(void*)0,&l_1608,&l_1608},{(void*)0,&g_297,&g_297,&l_1608,&l_1608,&l_1608,&g_297,&g_297,(void*)0},{&l_1608,(void*)0,(void*)0,&l_1608,&g_297,&g_297,&g_297,&g_297,&g_297},{(void*)0,&g_297,&g_297,&l_1608,&l_1608,&g_297,&l_1608,&g_297,(void*)0}},{{(void*)0,&g_297,&l_1608,&l_1608,(void*)0,&g_297,&g_297,&l_1608,(void*)0},{&g_297,&l_1608,&l_1608,&g_297,&l_1608,&l_1608,(void*)0,&g_297,&l_1608},{&g_297,&l_1608,&l_1608,&l_1608,(void*)0,&l_1608,&g_297,&g_297,(void*)0},{&g_297,(void*)0,&l_1608,&l_1608,(void*)0,&l_1608,&g_297,&g_297,(void*)0},{&g_297,&g_297,(void*)0,(void*)0,&l_1608,&g_297,(void*)0,&g_297,&l_1608}},{{&l_1608,&g_297,&g_297,&g_297,&g_297,&g_297,&l_1608,&l_1608,&g_297},{&l_1608,&g_297,(void*)0,&g_297,&l_1608,(void*)0,&g_297,&g_297,(void*)0},{&l_1608,&l_1608,&l_1608,&g_297,(void*)0,&g_297,&l_1608,(void*)0,(void*)0},{&g_297,(void*)0,&l_1608,&l_1608,&g_297,(void*)0,&l_1608,(void*)0,&l_1608},{&g_297,(void*)0,&l_1608,&l_1608,&g_297,&g_297,&l_1608,&l_1608,&l_1608}},{{&g_297,&l_1608,(void*)0,&l_1608,(void*)0,&g_297,&g_297,(void*)0,(void*)0},{&l_1608,&g_297,&l_1608,&l_1608,(void*)0,&l_1608,(void*)0,&g_297,(void*)0},{&l_1608,&l_1608,&l_1608,&l_1608,&l_1608,&l_1608,(void*)0,&l_1608,&g_297},{(void*)0,(void*)0,(void*)0,&l_1608,(void*)0,&l_1608,&g_297,(void*)0,&l_1608},{&l_1608,&l_1608,&l_1608,&l_1608,&g_297,&g_297,&l_1608,&l_1608,&l_1608}},{{&g_297,&l_1608,&l_1608,&l_1608,&l_1608,&g_297,&g_297,&g_297,&l_1608},{&l_1608,&g_297,&l_1608,&g_297,(void*)0,&g_297,(void*)0,&l_1608,&l_1608},{&g_297,&l_1608,&l_1608,&g_297,&g_297,(void*)0,&g_297,(void*)0,&g_297},{&g_297,&l_1608,(void*)0,&g_297,&g_297,&l_1608,&g_297,&g_297,(void*)0},{&l_1608,(void*)0,&g_297,(void*)0,&g_297,&l_1608,&l_1608,(void*)0,&l_1608}}};
                        int i, j, k;
                        (*l_1412) = ((safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_s(g_1271[0][0], 5)), (0x7F ^ p_54))) && (*p_50));
                        (*l_1644) = (safe_sub_func_uint32_t_u_u((safe_add_func_uint8_t_u_u((0x322C < (safe_lshift_func_int8_t_s_s((+(safe_rshift_func_uint8_t_u_s(l_1730, (safe_sub_func_uint8_t_u_u((&g_297 != l_1733[4][1][2]), g_27.f7))))), (((!0) && l_1735) < (safe_mod_func_int32_t_s_s((*l_1644), (*p_50))))))), 0U)), l_1711));
                    }
                    else
                    {
                        (**g_465) = (p_54 , (*p_53));
                    }
                    for (l_1122 = 1; (l_1122 <= 5); l_1122 += 1)
                    {
                        int32_t l_1740 = (-2);
                        (*g_466) = (**g_465);
                        (*p_50) = (safe_mod_func_uint16_t_u_u((l_1740 || (g_1271[1][2] < (((((safe_lshift_func_uint8_t_u_s((safe_mul_func_uint16_t_u_u(0xBABA, 3)), 7)) >= (safe_mul_func_int8_t_s_s((g_11[0] >= ((g_33[4] , 0x05D97D54) == (safe_div_func_uint32_t_u_u(((((((safe_mul_func_uint8_t_u_u(p_54, (((l_1740 < l_1751) , &p_52) == &p_51))) > 0x5C49B460) >= g_210.f0) || 1) >= l_1711) <= (*l_1645)), l_1752)))), (-1)))) , l_1711) , 65532U) == 0x6130))), g_27.f1));
                        (*g_296) = &p_50;

                        ((g_297 == &p_50) ? (void) (0) : __assert_fail ("g_297 == &p_50", "t.c", 1595, __PRETTY_FUNCTION__));
                    }
                    l_1760 = ((l_1753 , (((p_54 != 1) > ((safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint8_t_u_s((safe_div_func_uint8_t_u_u((&p_53 != &p_53), 3)), 5)), ((void*)0 != &l_1431))) == ((0x5E99 || p_54) | g_210.f7))) , (*g_466))) , (void*)0);

                    ((l_1760 == 0) ? (void) (0) : __assert_fail ("l_1760 == 0", "t.c", 1599, __PRETTY_FUNCTION__));
                }


{
    int32_t *l_2742 = &g_33[2];
    int32_t **l_2743 = &g_986[0][5][1];
    struct S0 ***l_2771 = &g_2531[0][0];
    uint32_t l_2842[8] = {4294967288U,4294967288U,4294967288U,0x2C0253A1,0x2C0253A1,4294967288U,0x2C0253A1,0x2C0253A1};
    int i;
    (*l_2743) = l_2742;
    for ((*l_2291) = 0; ((*l_2291) <= 2); (*l_2291) += 1)
    {
        int32_t ***l_2774 = &p_52;
        struct S0 l_2818 = {24,6738,-426,165,390,-0,1153,115,0xEA};
        struct S0 ***l_2865[3];
        int i;
        for (i = 0; i < 3; i++)
            l_2865[i] = &(*l_1873);
        g_32[(*l_2291)] = g_32[(*l_2291)];
        (*(&(*l_2291))) = ((safe_unary_minus_func_uint32_t_u((safe_unary_minus_func_int32_t_s(((+((((safe_mod_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(((((((safe_sub_func_uint8_t_u_u((g_1484 , g_210.f5), ((0xE948A20E < (0x51576ED4 < (safe_rshift_func_uint8_t_u_u((((safe_div_func_int32_t_s_s(((g_1484 , (0 > ((safe_div_func_int8_t_s_s(((((safe_mul_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s((((((safe_lshift_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_s((&g_32[(*l_2291)] == &g_32[(*l_2291)]), 6)) != (0x3A76E62F < (*l_2742))) , 0x6C), g_1484)) , &l_2743) != (&p_52)) | g_1484) <= g_1484), 1)), l_2370.f3)), g_1484)) | 0x23CC) != g_33[3]) | 0x0B28), g_1484)) , g_210.f7))) && 0x38), g_1484)) && l_2370.f6) | 1), (*l_2742))))) == g_1484))) , g_210.f1) , 0x7D5F7640) || (-1)) , (void*)0) != l_2771))), 0xEA)) | (-7)) < 0x54EA) || (*l_2742))) , 3))))) | 65535U);
        for (g_1484 = (-12); (g_1484 == 60); g_1484 = safe_add_func_int32_t_s_s(g_1484, 6))
        {
            uint16_t l_2775 = 0xE2FA;
            int16_t l_2804 = 8;
            struct S0 **l_2817[2][8][4] = {{{&(*g_465),&(*g_465),&(*g_465),&(*g_465)},{&(*g_465),&(*g_465),(void*)0,&(*g_465)},{&(*g_465),&(*g_465),&(*g_465),(void*)0},{&(*g_465),(void*)0,(void*)0,(void*)0},{&(*g_465),&(*g_465),&(*g_465),&(*g_465)},{(void*)0,&(*g_465),&(*g_465),(void*)0},{&(*g_465),&(*g_465),(void*)0,&(*g_465)},{&(*g_465),&(*g_465),&(*g_465),(void*)0}},{{(void*)0,&(*g_465),&(*g_465),&(*g_465)},{&(*g_465),&(*g_465),(void*)0,(void*)0},{&(*g_465),&(*g_465),&(*g_465),&(*g_465)},{&(*g_465),&(*g_465),(void*)0,&(*g_465)},{&(*g_465),&(*g_465),&(*g_465),(void*)0},{&(*g_465),&(*g_465),(void*)0,&(*g_465)},{&(*g_465),&(*g_465),&(*g_465),&(*g_465)},{&(*g_465),&(*g_465),(void*)0,(void*)0}}};
            int32_t l_2882 = (-4);
            int32_t *l_2884[4][4][8] = {{{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]},{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]},{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]},{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]}},{{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]},{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]},{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]},{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]}},{{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]},{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]},{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]},{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]}},{{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]},{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]},{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]},{&g_33[2],&l_1706,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1706,&g_33[2]}}};
            int i, j, k;
        }
        for (l_2818.f8 = 1; (l_2818.f8 <= 7); l_2818.f8 += 1)
        {
            uint16_t l_2912[10][5] = {{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U}};
            int32_t *l_2923 = (void*)0;
            int i, j;
        }
    }
    (*l_2743) = (*l_2743);
    (*l_2743) = (*l_2743);
    return (*l_2743);


}

                    for (l_1363 = 2; (l_1363 >= 51); l_1363 = safe_add_func_int32_t_s_s(l_1363, 1))
    {
        uint16_t l_2940[8] = {0U,0U,0U,0U,0U,0U,0U,0U};
        int i;
        for ((*l_1921) = 0; ((*l_1921) > (-15)); (*l_1921) = safe_sub_func_int32_t_s_s((*l_1921), 1))
        {
            uint16_t l_2954 = 0xBB7C;
            struct S0 **l_2955 = (void*)0;

{
                        int32_t *l_1054[6][1] = {{&g_33[2]},{&g_11[0]},{&g_33[2]},{&g_11[0]},{&g_33[2]},{&g_11[0]}};
                        int i, j, k;
                        g_986[l_2127][l_2127][l_2127] = l_1054[2][0];
                        (*p_51) = (((safe_add_func_uint16_t_u_u((safe_mul_func_uint16_t_u_u((safe_div_func_int32_t_s_s((safe_lshift_func_int8_t_s_u(0x32, 5)), (((l_1363 > l_1052) , 249U) && (p_51 == p_51)))), (((!(safe_rshift_func_int8_t_s_s(0, 2))) == (((l_2291 != (void*)0) ^ 0xFA0732C2) && l_1052)) || g_2351))), (*g_466).f6)) , l_1052) , (*p_51));
                    }

                    (*(&l_1711)) = 0x64EAFE29;
            for (l_1716 = 0; (l_1716 <= 3); l_1716 += 1)
            {
                struct S0 ***l_2957 = &g_2531[1][1];
                int16_t l_2958 = 0x8258;
                int i, j, k;
            }
        }
    };


                    if ((~((safe_add_func_int8_t_s_s((((*l_1644) < (g_784[3] , (*l_1644))) >= (g_210.f5 | p_54)), (safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(((l_1768 == (void*)0) < (g_80 == ((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u(((safe_rshift_func_uint8_t_u_s(249U, g_4)) | 0x53D3), 3)), p_54)) != 4294967295U))), p_54)), 4)))) | p_54)))
                {
                    uint32_t l_1785 = 0x464AA3C8;
                    int32_t *l_1786 = &l_1167[6][2];
                    (*l_1082) = 0x15E7E107;
                    (*l_1082) = (safe_mod_func_int32_t_s_s(0x375D5BBD, ((&g_297 != l_1508) , (safe_rshift_func_uint16_t_u_u(((0x9E <= (((void*)0 == &l_1644) <= (safe_div_func_uint8_t_u_u((((safe_mod_func_uint16_t_u_u(g_210.f8, l_1785)) , l_1786) == (void*)0), p_54)))) < g_4), 8)))));
                    for (g_80 = 1; (g_80 <= 4); g_80 += 1)
                    {
                        int i;
                        (*l_1608) = ((0U < g_1031[g_80]) , &g_33[g_80]);
                    }
                }
                else
                {
                    (**l_1768) = ((((1U >= 0x4C74) == (*l_1412)) || (p_54 <= ((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((l_1711 ^ l_1791) && (safe_rshift_func_uint8_t_u_s((0x6C4F ^ ((safe_rshift_func_uint16_t_u_s((safe_lshift_func_int16_t_s_s((safe_add_func_int32_t_s_s((((safe_mul_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(((safe_mul_func_int16_t_s_s(((((g_1031[4] > 0U) == 1) & l_1806[3]) | (*l_1644)), 0U)) & g_27.f1), p_54)), 0x72)) >= 0x0947D3B4) ^ 0xF37EABE7), l_1711)), 6)), 7)) , p_54)), 1))), g_210.f7)) != 0xDB) != p_54) | l_1807), (*l_1645))) & 0x0C))) , (*p_53));
                    (*l_1645) = (!((-1) || (safe_mul_func_uint16_t_u_u(l_1811, ((**g_465) , p_54)))));

{
                int32_t l_1711 = 0xA6BF7172;
                int32_t l_1753 = 0;
                uint16_t l_1791 = 65532U;
                struct S0 ***l_1873 = &(*l_1873);
                if ((safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(((((!0xB5) , (safe_mod_func_uint16_t_u_u((*g_2221), (*(*g_465)).f8))) == (safe_add_func_int16_t_s_s((l_991 & (*l_2212)), l_991))) == l_991), (safe_lshift_func_uint16_t_u_u((*(*g_465)).f3, 8)))), l_1711)), 9)), 0x95E60F64)))
                {
                    int32_t *l_1712 = (void*)0;
                    l_1712 = &g_11[0];

                    (((l_1712 >= &g_11[0] && l_1712 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_1712 >= &g_11[0] && l_1712 <= &g_11[0])", "t.c", 1697, __PRETTY_FUNCTION__));
                    for (g_2318 = 0; (g_2318 <= 2); g_2318 += 1)
                    {
                        int i;
                        return g_32[g_2318];



                    }
                }
                else
                {
                    int8_t l_1751 = 0;
                    int8_t l_1752 = (-6);
                    int32_t *l_1760 = &l_1167[6][6];
                    for (l_1711 = 0; (l_1711 <= (-6)); l_1711--)
                    {
                        int32_t *l_1715 = &g_11[0];
                        (*(*g_296)) = (void*)0;
                        (*g_2221) = (*l_2212);
                        (*(*g_296)) = l_1715;
                    }

for ((*l_1921) = 4; ((*l_1921) >= 1); (*l_1921) -= 1)
                    {
                        int i;
                        g_11[l_2127] = (l_1009 || 0x38);
                        g_148 = l_1760;
                        g_27 = l_2105;
                    };


                    if (l_991)
                    {
                        uint8_t l_1730 = 0xB5;
                        int32_t ***l_1733[5][5][9] = {{{&(*g_2770),&(*g_2770),&(*g_296),&(*g_2770),(void*)0,(void*)0,&(*g_296),&(*g_296),&(*g_296)},{&(*g_296),&(*g_296),(void*)0,&(*g_296),&(*g_2770),&(*g_296),(void*)0,&(*g_296),&(*g_296)},{(void*)0,&(*g_2770),&(*g_2770),&(*g_296),&(*g_296),&(*g_296),&(*g_2770),&(*g_2770),(void*)0},{&(*g_296),(void*)0,(void*)0,&(*g_296),&(*g_2770),&(*g_2770),&(*g_2770),&(*g_2770),&(*g_2770)},{(void*)0,&(*g_2770),&(*g_2770),&(*g_296),&(*g_296),&(*g_2770),&(*g_296),&(*g_2770),(void*)0}},{{(void*)0,&(*g_2770),&(*g_296),&(*g_296),(void*)0,&(*g_2770),&(*g_2770),&(*g_296),(void*)0},{&(*g_2770),&(*g_296),&(*g_296),&(*g_2770),&(*g_296),&(*g_296),(void*)0,&(*g_2770),&(*g_296)},{&(*g_2770),&(*g_296),&(*g_296),&(*g_296),(void*)0,&(*g_296),&(*g_2770),&(*g_2770),(void*)0},{&(*g_2770),(void*)0,&(*g_296),&(*g_296),(void*)0,&(*g_296),&(*g_2770),&(*g_2770),(void*)0},{&(*g_2770),&(*g_2770),(void*)0,(void*)0,&(*g_296),&(*g_2770),(void*)0,&(*g_2770),&(*g_296)}},{{&(*g_296),&(*g_2770),&(*g_2770),&(*g_2770),&(*g_2770),&(*g_2770),&(*g_296),&(*g_296),&(*g_2770)},{&(*g_296),&(*g_2770),(void*)0,&(*g_2770),&(*g_296),(void*)0,&(*g_2770),&(*g_2770),(void*)0},{&(*g_296),&(*g_296),&(*g_296),&(*g_2770),(void*)0,&(*g_2770),&(*g_296),(void*)0,(void*)0},{&(*g_2770),(void*)0,&(*g_296),&(*g_296),&(*g_2770),(void*)0,&(*g_296),(void*)0,&(*g_296)},{&(*g_2770),(void*)0,&(*g_296),&(*g_296),&(*g_2770),&(*g_2770),&(*g_296),&(*g_296),&(*g_296)}},{{&(*g_2770),&(*g_296),(void*)0,&(*g_296),(void*)0,&(*g_2770),&(*g_2770),(void*)0,(void*)0},{&(*g_296),&(*g_2770),&(*g_296),&(*g_296),(void*)0,&(*g_296),(void*)0,&(*g_2770),(void*)0},{&(*g_296),&(*g_296),&(*g_296),&(*g_296),&(*g_296),&(*g_296),(void*)0,&(*g_296),&(*g_2770)},{(void*)0,(void*)0,(void*)0,&(*g_296),(void*)0,&(*g_296),&(*g_2770),(void*)0,&(*g_296)},{&(*g_296),&(*g_296),&(*g_296),&(*g_296),&(*g_2770),&(*g_2770),&(*g_296),&(*g_296),&(*g_296)}},{{&(*g_2770),&(*g_296),&(*g_296),&(*g_296),&(*g_296),&(*g_2770),&(*g_2770),&(*g_2770),&(*g_296)},{&(*g_296),&(*g_2770),&(*g_296),&(*g_2770),(void*)0,&(*g_2770),(void*)0,&(*g_296),&(*g_296)},{&(*g_2770),&(*g_296),&(*g_296),&(*g_2770),&(*g_2770),(void*)0,&(*g_2770),(void*)0,&(*g_2770)},{&(*g_2770),&(*g_296),(void*)0,&(*g_2770),&(*g_2770),&(*g_296),&(*g_2770),&(*g_2770),(void*)0},{&(*g_296),(void*)0,&(*g_2770),(void*)0,&(*g_2770),&(*g_296),&(*g_296),(void*)0,&(*g_296)}}};
                        int i, j, k;
                        (*(&g_2803)) = ((safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_s(g_1271[0][0], 5)), (0x7F ^ l_991))) && (*l_2212));
                        (*g_2221) = (safe_sub_func_uint32_t_u_u((safe_add_func_uint8_t_u_u((0x322C < (safe_lshift_func_int8_t_s_s((+(safe_rshift_func_uint8_t_u_s(l_1730, (safe_sub_func_uint8_t_u_u((&(*g_2770) != l_1733[4][1][2]), (*(*g_465)).f7))))), (((!0) && (*l_2437)) < (safe_mod_func_int32_t_s_s((*g_2221), (*l_2212))))))), 0U)), l_1711));
                    }
                    else
                    {
                        (**l_1431) = (l_991 , (*(*l_1431)));
                    }

{

{
            struct S0 l_1148 = {513,9870,-147,246,399,1,-1229,339,-7};
            int32_t *l_1149 = &g_11[0];
            g_32[1] = (&l_1614);
            (**(*l_1828)) = l_1148;
            return l_1149;


        }

                    (*(&l_1624)) = (*(&i));
                        (*l_1082) = ((1 || ((((safe_rshift_func_uint8_t_u_u(((~(safe_rshift_func_int16_t_s_s((safe_mod_func_int8_t_s_s(l_1217.f1, l_2164)), 0))) ^ g_2318), 2)) , (l_1217.f6 , l_1217.f7)) | ((safe_lshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(l_1217.f0, (safe_div_func_uint16_t_u_u((safe_unary_minus_func_int32_t_s((+(g_11[0] , (((void*)0 == &(*g_465)) || (*(&i))))))), 0xE6B3)))), 0)) != g_2318)) && p_54)) || (-4));
                    }

                    for (l_1122 = 1; (l_1122 <= 5); l_1122 += 1)
                    {
                        int32_t l_1740 = (-2);
                        (*(*g_465)) = (**l_1431);
                        (*l_2212) = (safe_mod_func_uint16_t_u_u((l_1740 || (g_1271[1][2] < (((((safe_lshift_func_uint8_t_u_s((safe_mul_func_uint16_t_u_u(0xBABA, 3)), 7)) >= (safe_mul_func_int8_t_s_s((g_11[0] >= ((g_33[4] , 0x05D97D54) == (safe_div_func_uint32_t_u_u(((((((safe_mul_func_uint8_t_u_u(l_991, (((l_1740 < l_1751) , &(*g_296)) == &(*g_2770)))) > 0x5C49B460) >= l_1217.f0) || 1) >= l_1711) <= (*(&l_2164))), l_1752)))), (-1)))) , l_1711) , 65532U) == 0x6130))), (*(*g_465)).f1));
                        (*(&(*g_296))) = &l_2212;

                        (((*g_2770) == &l_2212) ? (void) (0) : __assert_fail ("(*g_2770) == &l_2212", "t.c", 1765, __PRETTY_FUNCTION__));
                    }
                    l_1760 = ((l_1753 , (((l_991 != 1) > ((safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint8_t_u_s((safe_div_func_uint8_t_u_u((&(*l_1431) != &(*l_1431)), 3)), 5)), ((void*)0 != &(*l_1873)))) == ((0x5E99 || l_991) | l_1217.f7))) , (*(*g_465)))) , (void*)0);

                    ((l_1760 == 0) ? (void) (0) : __assert_fail ("l_1760 == 0", "t.c", 1769, __PRETTY_FUNCTION__));
                }
                if ((~((safe_add_func_int8_t_s_s((((*g_2221) < (g_784[3] , (*g_2221))) >= (l_1217.f5 | l_991)), (safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u((((*l_1873) == (void*)0) < (g_2956 == ((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u(((safe_rshift_func_uint8_t_u_s(249U, l_1904)) | 0x53D3), 3)), l_991)) != 4294967295U))), l_991)), 4)))) | l_991)))
                {
                    uint32_t l_1785 = 0x464AA3C8;
                    int32_t *l_1786 = &l_1167[6][2];

{
            int32_t **l_1420 = &l_1096[0];
            struct S0 ***l_1436 = &(*l_1873);
            int32_t l_1453 = 0xA004A054;
            (*l_1420) = (&l_1711);


            for (l_1855 = 3; (l_1855 >= 0); l_1855 -= 1)
            {
                int32_t *l_1433 = &g_11[0];
                int32_t l_1451 = 0x78DACA4D;
                struct S0 ***l_1493 = (void*)0;
                uint16_t l_1500 = 65532U;
                uint32_t l_1513 = 0U;
            }
        }

                    (*l_2212) = 0x15E7E107;
                    (*l_2212) = (safe_mod_func_int32_t_s_s(0x375D5BBD, ((&(*g_2770) != (&(*g_296))) , (safe_rshift_func_uint16_t_u_u(((0x9E <= (((void*)0 == &g_2221) <= (safe_div_func_uint8_t_u_u((((safe_mod_func_uint16_t_u_u(l_1217.f8, l_1785)) , l_1786) == (void*)0), l_991)))) < l_1904), 8)))));
                    for (g_2956 = 1; (g_2956 <= 4); g_2956 += 1)
                    {
                        int i;
                        (*(*g_296)) = ((0U < g_1031[g_2956]) , &g_33[g_2956]);
                    }
                }
                else
                {

{
            struct S0 l_1148 = {513,9870,-147,246,399,1,-1229,339,-7};
            int32_t *l_1149 = &g_11[0];
            g_32[1] = g_148;
            (**l_1431) = l_1148;
            return l_1149;


        }

                    (**(*l_1873)) = ((((1U >= 0x4C74) == (*(&g_2803))) || (l_991 <= ((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((l_1711 ^ l_1791) && (safe_rshift_func_uint8_t_u_s((0x6C4F ^ ((safe_rshift_func_uint16_t_u_s((safe_lshift_func_int16_t_s_s((safe_add_func_int32_t_s_s((((safe_mul_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(((safe_mul_func_int16_t_s_s(((((g_1031[4] > 0U) == 1) & l_1806[3]) | (*g_2221)), 0U)) & (*(*g_465)).f1), l_991)), 0x72)) >= 0x0947D3B4) ^ 0xF37EABE7), l_1711)), 6)), 7)) , l_991)), 1))), l_1217.f7)) != 0xDB) != l_991) | g_1240), (*(&l_2164)))) & 0x0C))) , (*(*l_1431)));

{
                        (*(&g_27)) = ((*(&g_210)) , (((((((safe_div_func_int8_t_s_s((-1), ((l_2370.f5 | l_1716) || (safe_lshift_func_int16_t_s_u((safe_unary_minus_func_int8_t_s(((l_1631 , (g_2318 , ((safe_mod_func_int32_t_s_s(((((0x32A1 || (g_1031[0] >= (safe_div_func_uint8_t_u_u((l_2370.f3 | (-10)), 252U)))) && l_1631) , g_2318) <= 0U), 0xCF49745F)) >= g_11[0]))) <= 7))), 3))))) >= g_2318) == g_2318) < l_1716) < (*l_2437)) >= 0U) , (*(&g_210))));
                        (*p_52) = (&l_1807);

                        ((((*p_52) >= &g_11[0] && (*p_52) <= &g_11[0])) ? (void) (0) : __assert_fail ("((*p_52) >= &g_11[0] && (*p_52) <= &g_11[0])", "t.c", 1820, __PRETTY_FUNCTION__));
                    }

                    (*(&l_2164)) = (!((-1) || (safe_mul_func_uint16_t_u_u(l_1735, ((**l_1431) , l_991)))));
                    for (l_1904 = 0; (l_1904 >= (-19)); --l_1904)
                    {
                        (**l_1431) = (*(*g_465));
                    }
                }
                if ((((l_1217.f4 != (safe_mod_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_u((((safe_add_func_int16_t_s_s((((safe_mod_func_int32_t_s_s(((((safe_mod_func_uint32_t_u_u(((((safe_mul_func_int8_t_s_s(l_1791, ((&(*g_296) != &(*g_296)) , (0x51C4228E && 0x9390675F)))) <= ((((&l_1431 == ((((*l_2212) == (*l_2291)) , l_1791) , l_1873)) && g_1271[2][1]) , 8) || (*(*g_465)).f1)) > l_1711) < (*(&l_2164))), l_1711)) == (*g_2221)) > l_991) ^ (*l_2212)), (-1))) , (-10)) < 4U), 1U)) ^ l_991) != g_784[2]), g_2956)) , (*(*g_465)).f0) , l_1217.f6), g_11[0])), l_991))) , g_1271[2][1]) , (*(&l_2164))))
                {
                    int32_t l_1835 = 0xBAE4E033;
                    int32_t l_1837 = 0;
                    (*(*g_296)) = g_2221;
                    (*(&g_2803)) = (!l_1837);
                }
                else
                {
                    int32_t *l_1840 = &(*l_2291);
                    for (l_1711 = 22; (l_1711 == (-3)); l_1711 = safe_sub_func_int32_t_s_s(l_1711, 1))
                    {
                        uint8_t l_1841 = 0xAC;

{
                        return (&l_1807);


                    }

                    (*(*g_296)) = l_1840;
                        (**l_1431) = (*(*g_465));

{
                int8_t l_1145 = 0;
                int32_t **l_1147[10] = {&g_32[0],&l_1412,&g_32[0],&g_986[0][4][1],&g_986[0][4][1],&g_32[0],&l_1412,&g_32[0],&g_986[0][4][1],&g_986[0][4][1]};
                int i;
                (*(&g_80)) = l_1009;

if (((safe_sub_func_int32_t_s_s((safe_rshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((l_1262 , (**l_1831)) , (safe_mod_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(0x497B, 0U)), (((safe_rshift_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(((((**l_1831) , (((((((((safe_add_func_int8_t_s_s((*p_53).f8, (safe_rshift_func_uint16_t_u_u((~(1U < (((((void*)0 == &g_33[2]) == g_2054[3][1][0]) ^ l_1262) & 0x9DD8))), (*p_53).f4)))) <= g_210.f0) < 0xA736BD57) > 0x4985) , (*p_53)) , (void*)0) == l_1893) || g_1094) , 0xE6)) < 0x78) > l_1363), 65535U)), l_1363)) < (*(&i))) , l_1363)))), g_1094)), l_1363)), l_1363)) < 0U))
                    {
                        int32_t **l_2477 = (void*)0;
                        g_148 = &g_33[4];
                        if ((*p_53).f6)
                            continue;
                        return (&l_1811);



                    }
                    else
                    {
                        uint32_t l_2493[3][6];
                        int i, j;
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 6; j++)
                                l_2493[i][j] = 1U;
                        }
                        (*(&g_2956)) = ((l_1262 & (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u(((((((safe_lshift_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((l_1262 , (safe_lshift_func_uint16_t_u_s(((safe_sub_func_int32_t_s_s((((((l_2493[0][4] && ((l_1262 <= (((safe_sub_func_int8_t_s_s(((safe_mul_func_int16_t_s_s(0x1FF6, ((g_210.f7 > (*p_53).f8) >= ((l_1828 == (void*)0) , (-1))))) , (*g_148)), g_1031[3])) , (*l_2437)) & 7)) > g_210.f0)) , (**l_1831)) , g_210.f8) && l_1262) , l_1650), 0x8ADDA95C)) , l_1363), 2))), l_2500)) | l_1363), l_1363)) ^ (*l_2437)) >= 0x4B) || (*p_53).f0) == 0x09) , (*p_53).f1), 5)), 6)), 0))) , (*g_148));
                    };


                    g_27 = (((safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(l_1052, (*(&g_2956)))), l_1217.f7)) == (safe_mul_func_int8_t_s_s((l_1129[3] | l_2370.f3), l_1735))) , (((safe_lshift_func_int16_t_s_u((l_1052 < (safe_mod_func_int32_t_s_s((safe_mod_func_int16_t_s_s((safe_mul_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s((((safe_div_func_uint16_t_u_u((((*l_1431) == (*l_1831)) < l_1052), l_1217.f3)) < l_2370.f2) , l_1145), 0x9282)), 2)), l_1145)), g_33[2])), 1))), 9)) >= l_1811) , (*(*l_1831))));
                g_944[3][0][7] = l_1096[0];
            }

                    (*(*g_296)) = &g_11[0];
                        l_2212 = (*(*g_2770));

                        ((l_2212 == 0) ? (void) (0) : __assert_fail ("l_2212 == 0", "t.c", 1889, __PRETTY_FUNCTION__));
                    }

                    ((l_2212 == 0 || (l_2212 >= &g_33[0] && l_2212 <= &g_33[4])) ? (void) (0) : __assert_fail ("l_2212 == 0 || (l_2212 >= &g_33[0] && l_2212 <= &g_33[4])", "t.c", 1892, __PRETTY_FUNCTION__));

for (g_2351 = (-12); (g_2351 == 60); g_2351 = safe_add_func_int32_t_s_s(g_2351, 6))
        {
            uint16_t l_2775 = 0xE2FA;
            int16_t l_2804 = 8;
            struct S0 **l_2817[2][8][4] = {{{&(*l_1768),&(*l_1768),&(*l_1768),&(*l_1768)},{&(*l_1768),&(*l_1768),(void*)0,&(*l_1768)},{&(*l_1768),&(*l_1768),&(*l_1768),(void*)0},{&(*l_1768),(void*)0,(void*)0,(void*)0},{&(*l_1768),&(*l_1768),&(*l_1768),&(*l_1768)},{(void*)0,&(*l_1768),&(*l_1768),(void*)0},{&(*l_1768),&(*l_1768),(void*)0,&(*l_1768)},{&(*l_1768),&(*l_1768),&(*l_1768),(void*)0}},{{(void*)0,&(*l_1768),&(*l_1768),&(*l_1768)},{&(*l_1768),&(*l_1768),(void*)0,(void*)0},{&(*l_1768),&(*l_1768),&(*l_1768),&(*l_1768)},{&(*l_1768),&(*l_1768),(void*)0,&(*l_1768)},{&(*l_1768),&(*l_1768),&(*l_1768),(void*)0},{&(*l_1768),&(*l_1768),(void*)0,&(*l_1768)},{&(*l_1768),&(*l_1768),&(*l_1768),&(*l_1768)},{&(*l_1768),&(*l_1768),(void*)0,(void*)0}}};
            int32_t l_2882 = (-4);
            int32_t *l_2884[4][4][8] = {{{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]}},{{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]}},{{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]}},{{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]},{&g_33[2],&l_1807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1807,&g_33[2]}}};
            int i, j, k;
        };


                    for (l_2350 = 23; (l_2350 >= 1); l_2350--)
                    {
                        int8_t l_1862 = 2;
                        (*(*g_296)) = (((*l_1840) & ((+((safe_unary_minus_func_uint32_t_u((g_2956 | ((((safe_div_func_int16_t_s_s((safe_div_func_uint8_t_u_u(((l_1862 >= ((safe_mul_func_int8_t_s_s((g_2956 , (((safe_mul_func_int8_t_s_s(((*g_2221) | ((safe_mul_func_int16_t_s_s((safe_lshift_func_int8_t_s_s((-2), ((l_991 || (safe_rshift_func_int16_t_s_s(0x5560, 5))) | 1))), l_1862)) == l_991)), 0x3C)) , 0U) < l_1217.f6)), 0)) ^ l_1217.f8)) , l_991), 0x04)), 0xF8B9)) | l_1217.f6) < 0xDE83) && 0U)))) , l_1753)) >= 0x8A4328FC)) , g_2221);
                        (**(*l_1873)) = (((void*)0 == l_1873) , (((l_1873 == ((*l_2212) , &(*l_1873))) == l_991) , (*(*g_465))));
                        (**l_1431) = ((*g_2221) , (**l_1431));
                        return (*(*g_296));



                    }
                    g_2221 = &l_1753;

                    ((g_2221 == &l_1753) ? (void) (0) : __assert_fail ("g_2221 == &l_1753", "t.c", 1918, __PRETTY_FUNCTION__));
                }

                ((l_2212 == 0 || (l_2212 >= &g_33[0] && l_2212 <= &g_33[4])) ? (void) (0) : __assert_fail ("l_2212 == 0 || (l_2212 >= &g_33[0] && l_2212 <= &g_33[4])", "t.c", 1921, __PRETTY_FUNCTION__));
                ((g_2221 == &l_1753 || (g_2221 >= &g_11[0] && g_2221 <= &g_11[0])) ? (void) (0) : __assert_fail ("g_2221 == &l_1753 || (g_2221 >= &g_11[0] && g_2221 <= &g_11[0])", "t.c", 1922, __PRETTY_FUNCTION__));
            }

                    for (l_1383 = 0; (l_1383 >= (-19)); --l_1383)
                    {
                        (**g_465) = (*g_466);
                    }
                }

{
                    int32_t *l_1219 = &g_33[2];
                    struct S0 ***l_1250[4] = {&(*l_1873),&(*l_1873),&(*l_1873),&(*l_1873)};
                    struct S0 l_1255 = {192,4318,-489,36,135,-0,1153,251,0x86};
                    int i;
                    if ((~l_1052))
                    {
                        l_1219 = l_1219;

{
    int32_t *l_26 = &g_11[0];
    struct S0 *l_28 = &l_2370;
    for ((*l_1644) = (-7); ((*l_1644) != (-23)); (*l_1644)--)
    {
        int32_t *l_25 = &(*l_1644);
        int32_t **l_24[1][5] = {{&l_25,&l_25,&l_25,&l_25,&l_25}};
        int i, j;
        l_26 = &g_11[0];
    }
    (*l_28) = l_2370;
    (*l_26) = func_5((safe_mul_func_uint16_t_u_u(0U, l_2370.f7)), (&g_21), l_2370.f5);
    return l_26;


}

                    l_1644 = (void*)0;

                        ((l_1644 == 0) ? (void) (0) : __assert_fail ("l_1644 == 0", "t.c", 1959, __PRETTY_FUNCTION__));
                    }
                    else
                    {
                        int32_t **l_1241 = &g_32[0];
                        (*l_1644) = (safe_add_func_uint16_t_u_u((l_1219 == &g_11[0]), (((safe_add_func_uint32_t_u_u((((safe_rshift_func_uint16_t_u_s(g_27.f2, ((((*l_1219) & ((safe_rshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s(((safe_sub_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u(((void*)0 == &(*g_2770)), 10)), (((*(*l_1768)) , (((l_1052 != l_1052) || l_1052) && l_1052)) ^ 0x76))) >= l_1052), (*l_1644))) >= l_2003), 0x8F)), 0)) == l_1383)) >= l_1052) < 0x6B1FB5AC))) > g_1031[4]) , (*l_1219)), (*l_1644))) || (*l_2437)) <= (*l_1644))));
                        (*l_1241) = (void*)0;
                        l_2003 = ((safe_mul_func_int16_t_s_s((l_1052 > (safe_div_func_int32_t_s_s(((safe_sub_func_int8_t_s_s((0x76 ^ (0xFD != ((*l_1219) > (*l_2437)))), (safe_mul_func_uint16_t_u_u(0x6A67, 0xFFEE)))) | (((l_1250[0] != (void*)0) , l_1052) > 65535U)), (*l_1219)))), 0xC94C)) && l_1052);
                        (*(*g_465)) = (*(*l_1768));
                    }

                    (((l_1644 >= &l_1167[0][0] && l_1644 <= &l_1167[8][6]) || l_1644 == 0) ? (void) (0) : __assert_fail ("(l_1644 >= &l_1167[0][0] && l_1644 <= &l_1167[8][6]) || l_1644 == 0", "t.c", 1970, __PRETTY_FUNCTION__));
                    l_1219 = &l_1167[4][3];

                    (((l_1219 >= &l_1167[0][0] && l_1219 <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("(l_1219 >= &l_1167[0][0] && l_1219 <= &l_1167[8][6])", "t.c", 1973, __PRETTY_FUNCTION__));
                }

                    if ((((g_210.f4 != (safe_mod_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_u((((safe_add_func_int16_t_s_s((((safe_mod_func_int32_t_s_s(((((safe_mod_func_uint32_t_u_u(((((safe_mul_func_int8_t_s_s(l_1791, ((&p_52 != &l_1608) , (0x51C4228E && 0x9390675F)))) <= ((((&g_465 == ((((*l_1082) == g_21) , l_1791) , l_1828)) && g_1271[2][1]) , 8) || g_27.f1)) > l_1711) < (*l_1645)), l_1711)) == (*l_1644)) > p_54) ^ (*p_50)), (-1))) , (-10)) < 4U), 1U)) ^ p_54) != g_784[2]), g_80)) , g_27.f0) , g_210.f6), g_11[0])), p_54))) , g_1271[2][1]) , (*l_1645)))
                {
                    int32_t l_1835 = 0xBAE4E033;
                    int32_t l_1837 = 0;
                    (*l_1608) = l_1644;
                    (*l_1412) = (!l_1837);
                }
                else
                {
                    int32_t *l_1840 = &g_21;
                    for (l_1711 = 22; (l_1711 == (-3)); l_1711 = safe_sub_func_int32_t_s_s(l_1711, 1))
                    {
                        uint8_t l_1841 = 0xAC;

{
                            for ((*l_2437) = 0; (*l_2437) < 6; (*l_2437)++)
                                g_1271[(*l_1840)][(*l_2437)] = 1U;
                        }

                    (*l_1608) = l_1840;
                        (**g_465) = (*g_466);

if ((*l_1412))
                            break;

                    (*l_1608) = &g_11[0];
                        l_1082 = l_1850;

                        ((l_1082 == 0) ? (void) (0) : __assert_fail ("l_1082 == 0", "t.c", 2004, __PRETTY_FUNCTION__));
                    }

                    ((l_1082 == 0 || (l_1082 >= &g_33[0] && l_1082 <= &g_33[4])) ? (void) (0) : __assert_fail ("l_1082 == 0 || (l_1082 >= &g_33[0] && l_1082 <= &g_33[4])", "t.c", 2007, __PRETTY_FUNCTION__));
                    for (g_1484 = 23; (g_1484 >= 1); g_1484--)
                    {
                        int8_t l_1862 = 2;
                        (*l_1608) = (((*l_1840) & ((+((safe_unary_minus_func_uint32_t_u((l_1855 | ((((safe_div_func_int16_t_s_s((safe_div_func_uint8_t_u_u(((l_1862 >= ((safe_mul_func_int8_t_s_s((g_80 , (((safe_mul_func_int8_t_s_s(((*l_1644) | ((safe_mul_func_int16_t_s_s((safe_lshift_func_int8_t_s_s((-2), ((p_54 || (safe_rshift_func_int16_t_s_s(0x5560, 5))) | 1))), l_1862)) == p_54)), 0x3C)) , 0U) < g_210.f6)), 0)) ^ g_210.f8)) , p_54), 0x04)), 0xF8B9)) | g_210.f6) < 0xDE83) && 0U)))) , l_1753)) >= 0x8A4328FC)) , l_1644);

{
            int32_t *l_2383 = &l_1167[6][6];
            if ((((safe_mul_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((void*)0 == (*(*l_1873))), ((g_1271[2][1] != ((((g_2805 & (safe_add_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u(((((safe_mod_func_uint16_t_u_u(((((*p_53) , l_1650) , (void*)0) != (void*)0), (safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(0x692C583B, 0x083CD9AE)), g_2805)))) , (void*)0) != g_2770) , l_1217.f5), g_1031[4])) , l_2212) != l_2212), g_2805))) > g_2805) == g_2805) ^ g_33[2])) >= 0x24))), 0xD203)) <= g_2805) & 0xCB))
            {
                int16_t l_2385 = 1;
                int32_t l_2386[9][3][9] = {{{0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0,(-5),0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0},{1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11},{0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46}},{{0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7},{0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46},{0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11,0xD11FB6A6,0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11}},{{0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0},{0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6},{0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2}},{{1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6},{0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0,(-5),0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0},{1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11}},{{0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46},{0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7},{0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46}},{{0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11,0xD11FB6A6,0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11},{0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5)},{0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7}},{{0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0},{0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7},{0x18DF85E2,0x15E3D6FB,(-5),(-5),0x15E3D6FB,0x18DF85E2,0x15E3D6FB,(-5),(-5)}},{{0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6},{0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2},{0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11}},{{0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2},{0x412DFEB7,1,0xD11FB6A6,0xD11FB6A6,1,0x412DFEB7,1,0xD11FB6A6,0xD11FB6A6},{0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5)}}};
                int32_t ***l_2414 = &(*g_2770);
                int i, j, k;
                for ((*l_2291) = 4; ((*l_2291) >= (-19)); --(*l_2291))
                {
                    int32_t l_2384[2][6][6] = {{{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0}},{{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0}}};
                    int32_t *l_2416 = &g_33[2];
                    int i, j, k;
                    if ((*(*l_1608)))
                    {
                        struct S0 *l_2369[9][1];
                        int32_t l_2381 = (-1);
                        int i, j;
                        for (i = 0; i < 9; i++)
                        {
                            for (j = 0; j < 1; j++)
                                l_2369[i][j] = (void*)0;
                        }
                        (*l_2212) = (l_2369[8][0] == p_53);
                        l_1217 = (l_1217.f0 , (*(*l_1768)));
                        (*(&l_1711)) = (safe_mod_func_int32_t_s_s(((safe_div_func_uint32_t_u_u(((safe_mul_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_s((((l_2381 & g_2805) | ((((g_2770 != (void*)0) == g_2054[0][0][1]) , l_2383) == ((*(*l_1608)) , (*l_1608)))) , g_2805), (*l_2383))), 3)), l_1855)) ^ l_2384[0][4][4]), l_2385)) != l_2386[5][2][8]), l_2386[1][0][7]));
                    }
                    else
                    {
                        int32_t l_2413 = 0x35119CD0;
                        uint8_t l_2415 = 2U;
                        (*l_2212) = (*(*l_1608));
                        (*l_2383) = (safe_mul_func_uint8_t_u_u(((((g_784[3] > (((((l_1217.f4 >= (safe_rshift_func_uint8_t_u_u((!(safe_sub_func_uint16_t_u_u(((((l_1217.f2 && 248U) >= (!((safe_div_func_uint32_t_u_u(1U, ((((safe_lshift_func_int8_t_s_s((safe_mul_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_s(1U, (safe_add_func_int8_t_s_s((safe_mul_func_int16_t_s_s(l_1217.f0, (safe_rshift_func_int16_t_s_s(l_2413, 12)))), (((void*)0 == l_2414) , l_2384[0][4][4]))))) , l_2415), 3)), 0xB4AC)), (*l_2212))) & g_33[2]) != 1U) , (*(*l_1608))))) > g_2805))) , l_2384[0][4][5]) ^ g_33[2]), g_2054[7][0][1]))), 0))) , 0xCE1E) == g_784[3]) , 0xB4BE) == g_1484)) <= g_2805) , (-4)) || g_784[3]), (-10)));
                    }
                    return l_2416;



                }
                for (l_1986 = 1; (l_1986 > 38); ++l_1986)
                {
                    int32_t *l_2419 = &g_11[0];
                    return l_2419;



                }
                (*(*p_51)) = (*(*l_1608));
            }
            else
            {
                struct S0 **l_2428 = &(*l_1768);
                int32_t l_2438[9][9] = {{0xA15E527E,(-10),(-8),(-10),0xA15E527E,(-8),0x01077C09,0x01077C09,(-8)},{0xA15E527E,(-10),(-8),(-10),0xA15E527E,(-8),0x01077C09,0x01077C09,(-8)},{0xA15E527E,(-10),(-8),(-10),0xA15E527E,(-8),0x01077C09,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09}};
                int i, j;
                (*(&l_1711)) = (((safe_mul_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u((((((void*)0 != &(*g_2770)) , l_2383) == &l_2438[5][1]) , l_1217.f4), 1)) > l_1217.f0), 0x5D)), (-5))) > l_2438[2][3]) , 0xD350549E);
                (*l_2212) = 0x5CE0142A;
            }
            return (*l_1608);



        }

                    (**l_1768) = (((void*)0 == l_1873) , (((l_1828 == ((*p_50) , &l_1768)) == p_54) , (*g_466)));
                        (**l_1831) = ((*l_1644) , (**l_1831));
                        return (*l_1608);



                    }

for (g_21 = 4; (g_21 >= 1); g_21 -= 1)
                    {
                        int i;
                        g_11[g_4] = (l_1122 || 0x38);
                        g_148 = (&g_1240);
                        l_1217 = g_27;
                    };


                    l_1644 = &l_1753;

                    ((l_1644 == &l_1753) ? (void) (0) : __assert_fail ("l_1644 == &l_1753", "t.c", 2095, __PRETTY_FUNCTION__));
                }

                ((l_1082 == 0 || (l_1082 >= &g_33[0] && l_1082 <= &g_33[4])) ? (void) (0) : __assert_fail ("l_1082 == 0 || (l_1082 >= &g_33[0] && l_1082 <= &g_33[4])", "t.c", 2098, __PRETTY_FUNCTION__));
                ((l_1644 == &l_1753 || (l_1644 >= &g_11[0] && l_1644 <= &g_11[0])) ? (void) (0) : __assert_fail ("l_1644 == &l_1753 || (l_1644 >= &g_11[0] && l_1644 <= &g_11[0])", "t.c", 2099, __PRETTY_FUNCTION__));
            }

            ((l_1082 == 0 || (l_1082 >= &g_33[0] && l_1082 <= &g_33[4])) ? (void) (0) : __assert_fail ("l_1082 == 0 || (l_1082 >= &g_33[0] && l_1082 <= &g_33[4])", "t.c", 2102, __PRETTY_FUNCTION__));


for (l_2323 = 22; (l_2323 > 12); l_2323 = safe_sub_func_uint32_t_u_u(l_2323, 8))
                {
                    int32_t *l_677 = &g_11[0];
                    (**l_1508) = l_677;

                    (((l_1412 >= &g_11[0] && l_1412 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_1412 >= &g_11[0] && l_1412 <= &g_11[0])", "t.c", 2110, __PRETTY_FUNCTION__));
                };


                    (*l_1608) = (*l_1608);
            if (((safe_lshift_func_int8_t_s_s(0xF2, 0)) > (safe_mod_func_uint32_t_u_u(g_27.f0, p_54))))
            {
                uint32_t l_1901 = 0xCA91294B;
                (*l_1828) = l_1831;

                ((l_1431 == &g_466) ? (void) (0) : __assert_fail ("l_1431 == &g_466", "t.c", 2120, __PRETTY_FUNCTION__));
                l_1901 = (((((*l_1828) == (void*)0) | (*l_1645)) , ((safe_unary_minus_func_int32_t_s((~(((g_1271[1][1] , 0x6E) != p_54) ^ (safe_unary_minus_func_int32_t_s((*p_50))))))) < ((l_1828 == (void*)0) & l_1807))) && g_27.f2);
                (*l_1608) = (((safe_lshift_func_int8_t_s_s(l_1904, (!(safe_mod_func_uint8_t_u_u((l_1831 != (void*)0), 1U))))) | ((0U >= ((-1) ^ (p_50 != (void*)0))) > (safe_add_func_uint16_t_u_u((safe_rshift_func_int8_t_s_u((safe_mul_func_int8_t_s_s((safe_mul_func_int16_t_s_s(8, l_1901)), g_27.f6)), 1)), 0x1BE4)))) , (*l_1608));
            }
            else
            {
                uint32_t l_1926 = 8U;
                uint32_t l_1936 = 8U;
                uint32_t l_1938 = 0x54CF833C;
                int32_t *l_1940 = &g_11[0];
                struct S0 ***l_1943[4][1][7] = {{{(void*)0,&l_1431,(void*)0,&l_1831,&l_1431,&l_1831,&l_1431}},{{(void*)0,&g_465,&g_465,(void*)0,&g_465,&l_1831,&l_1431}},{{&l_1431,&l_1831,&g_465,(void*)0,&g_465,&g_465,(void*)0}},{{&l_1431,&l_1831,&l_1431,&l_1831,&g_465,&l_1431,&l_1431}}};
                int32_t ***l_1952 = &l_1608;
                int i, j, k;
                (*p_50) = (safe_mod_func_uint16_t_u_u(g_210.f0, (g_210.f2 , (safe_add_func_int32_t_s_s((*p_50), ((!g_27.f8) <= 0))))));
                (*l_1608) = l_1921;


                (*l_1608) = l_1940;

for (i = (-2); (i > (-21)); --i)
                {
                    int8_t l_1279 = 0;
                    int8_t l_1329 = (-1);
                    int32_t ***l_1336 = (void*)0;
                    int8_t l_1348 = 1;
                    struct S0 l_1350 = {599,171,-440,1398,438,-1,-231,342,0};

if (((safe_div_func_int16_t_s_s(l_1348, l_2164)) && 0xD865))
                    {
                        (*(&l_1921)) = (&l_1614);

                        (((*g_297) == 0) ? (void) (0) : __assert_fail ("(*g_297) == 0", "t.c", 2151, __PRETTY_FUNCTION__));
                        return g_148;


                    }
                    else
                    {
                        g_32[1] = &g_80;


                    };


                    (*l_1508) = &g_2221;

                    ((l_1608 == &g_2221) ? (void) (0) : __assert_fail ("l_1608 == &g_2221", "t.c", 2166, __PRETTY_FUNCTION__));
                    if ((((safe_mod_func_uint8_t_u_u((((+((((l_2370.f3 , ((((safe_div_func_uint32_t_u_u(l_1363, l_1279)) == ((void*)0 == (*(&l_1608)))) <= ((!((safe_rshift_func_int16_t_s_u(l_1363, 5)) == ((safe_lshift_func_uint16_t_u_u(((((safe_rshift_func_int16_t_s_s((safe_mul_func_int16_t_s_s((l_1279 & (((((**l_1508) == ((l_1363 >= l_1363) , (*l_1608))) || 0x4474) < 0xF0E8F346) & g_11[0])), l_1279)), g_784[0])) < l_2370.f5) , l_1279) , l_2370.f4), l_1363)) && (***l_1508)))) , 0x66C85F8A)) , 0x993C)) != l_1279) , (*l_1431)) != (void*)0)) > l_1279) & 0x8FA0), 5U)) , g_1271[2][1]) < l_1279))
                    {
                        (*g_2221) = ((!(l_1936 && (safe_rshift_func_uint16_t_u_s(l_1363, (l_1363 != (safe_sub_func_int16_t_s_s((+((+(safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((((((&g_2221 == ((l_1363 > (safe_rshift_func_uint8_t_u_u((*g_2221), 2))) , &g_2221)) && (***l_1508)) & ((((safe_sub_func_int8_t_s_s((((*l_1768) == (*l_1768)) & l_1363), l_1279)) || 1) , l_2105.f7) <= l_1936)) | 0x7B86) == 0) == l_1363), 0x08)), l_1363)), l_2105.f4))) != 0)), l_1306[4][2][4]))))))) , 0);
                    }
                    else
                    {
                        int16_t l_1344 = 1;
                        int32_t ***l_1347 = &l_1608;
                        (**l_1608) = (+(((((((safe_rshift_func_uint16_t_u_s(((**l_1608) && (*g_2221)), (safe_add_func_uint16_t_u_u(g_11[0], ((safe_lshift_func_int16_t_s_u((((void*)0 != &l_1608) >= l_1363), (safe_div_func_int8_t_s_s((g_784[3] , ((l_1363 <= (safe_rshift_func_uint16_t_u_s(65529U, 2))) && (***l_1508))), l_1363)))) && 0x4B36))))) < 255U) < l_1363) < g_33[2]) ^ (*g_2221)) == 0) < 0x6094));

if ((~((safe_add_func_int8_t_s_s((((*p_50) < (g_784[3] , (*p_50))) >= (l_2370.f5 | p_54)), (safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(((l_1831 == (void*)0) < (l_1706 == ((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u(((safe_rshift_func_uint8_t_u_s(249U, l_1181)) | 0x53D3), 3)), p_54)) != 4294967295U))), p_54)), 4)))) | p_54)))
                {
                    uint32_t l_1785 = 0x464AA3C8;
                    int32_t *l_1786 = &l_1167[6][2];
                    (*l_1082) = 0x15E7E107;
                    (*l_1082) = (safe_mod_func_int32_t_s_s(0x375D5BBD, ((&(*l_1347) != l_1347) , (safe_rshift_func_uint16_t_u_u(((0x9E <= (((void*)0 == &p_50) <= (safe_div_func_uint8_t_u_u((((safe_mod_func_uint16_t_u_u(l_2370.f8, l_1785)) , l_1786) == (void*)0), p_54)))) < l_1181), 8)))));
                    for (l_1706 = 1; (l_1706 <= 4); l_1706 += 1)
                    {
                        int i;
                        (*(&p_50)) = ((0U < g_1031[l_1706]) , &g_33[l_1706]);
                    }
                }
                else
                {
                    (**l_1831) = ((((1U >= 0x4C74) == (*(&g_21))) || (p_54 <= ((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((g_21 ^ l_1009) && (safe_rshift_func_uint8_t_u_s((0x6C4F ^ ((safe_rshift_func_uint16_t_u_s((safe_lshift_func_int16_t_s_s((safe_add_func_int32_t_s_s((((safe_mul_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(((safe_mul_func_int16_t_s_s(((((g_1031[4] > 0U) == 1) & l_1806[3]) | (*p_50)), 0U)) & l_2105.f1), p_54)), 0x72)) >= 0x0947D3B4) ^ 0xF37EABE7), g_21)), 6)), 7)) , p_54)), 1))), l_2370.f7)) != 0xDB) != p_54) | g_2956), (*(&g_1240)))) & 0x0C))) , (*(&g_210)));
                    (*(&g_1240)) = (!((-1) || (safe_mul_func_uint16_t_u_u(l_1624, ((**l_1831) , p_54)))));
                    for (l_1181 = 0; (l_1181 >= (-19)); --l_1181)
                    {
                        (**l_1831) = (*(&l_2105));
                    }
                };


                    (**l_1508) = (**l_1508);
                        (**l_1608) = ((((((safe_mul_func_int16_t_s_s((((void*)0 == (*l_1608)) ^ ((l_2105.f7 , (***(&l_1608))) ^ (safe_div_func_int16_t_s_s((((safe_rshift_func_int16_t_s_s((l_1336 != (((safe_add_func_uint8_t_u_u(l_2105.f0, (safe_sub_func_int8_t_s_s(l_1926, (safe_mod_func_int16_t_s_s((l_1344 | (safe_mod_func_uint32_t_u_u(((*l_1768) == (void*)0), l_1344))), (-8))))))) && 0x3B) , l_1347)), l_1363)) , 0xD8) < l_1363), g_1031[3])))), l_1348)) && (***l_1347)) < 0xD0DF30A5) ^ (*l_1921)) | (***(&l_1608))) , l_1597);
                        l_1350 = (*(*l_1768));
                    }
                };


                    if ((safe_mul_func_int8_t_s_s((4294967295U < (&g_465 == l_1943[1][0][4])), ((((safe_unary_minus_func_uint8_t_u(g_21)) , (g_1271[0][4] ^ ((((safe_lshift_func_int8_t_s_s(1, ((+((safe_rshift_func_uint16_t_u_s(((((((safe_add_func_uint32_t_u_u(p_54, ((*l_1940) < (0xA6 >= g_27.f2)))) == p_54) , (*p_50)) , 0xF8C4376E) ^ 0x6BBC687B) < (*l_1940)), g_27.f8)) >= p_54)) , 1))) , 0x58) | 0x89) & 8U))) , &p_52) != l_1952))))
                {
                    int32_t *l_1953 = &l_1167[6][6];
                    uint32_t l_1954 = 3U;
                    struct S0 l_1987 = {587,4246,182,1176,256,0,1763,200,8};
                    l_1953 = &l_1937[3][0][1];

                    (((l_1953 >= &l_1937[0][0][0] && l_1953 <= &l_1937[5][1][8])) ? (void) (0) : __assert_fail ("(l_1953 >= &l_1937[0][0][0] && l_1953 <= &l_1937[5][1][8])", "t.c", 2214, __PRETTY_FUNCTION__));
                    (**l_1952) = &g_11[0];
                    (*g_466) = (((safe_sub_func_uint32_t_u_u((safe_sub_func_uint8_t_u_u((safe_mul_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s(((((safe_mul_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((1U & (safe_add_func_uint8_t_u_u((((g_1094 == (~(safe_mod_func_uint16_t_u_u(((void*)0 == &p_50), (-1))))) | ((*l_1953) == (*l_1645))) && (safe_div_func_uint32_t_u_u(0x608AA6BE, (-7)))), p_54))), 14)), (*l_1940))) < 0xFA) == g_1031[4]) > g_33[1]), 9)), 0)), g_1271[2][1])), l_1986)) , 0x87B2CA8D) , l_1987);
                }
                else
                {
                    l_1988[0][2][5] = (*g_466);
                    (*l_1412) = (safe_sub_func_int8_t_s_s((~(g_27.f5 >= (l_1943[2][0][0] != (void*)0))), 1U));
                    for (l_1181 = (-5); (l_1181 < 0); l_1181 = safe_add_func_uint16_t_u_u(l_1181, 2))
                    {
                        (*l_1608) = &g_21;
                    }

{
                        (*l_1082) = (((safe_rshift_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_u(((safe_unary_minus_func_int8_t_s(((g_2054[7][0][1] , (!(*l_1082))) < (safe_sub_func_uint8_t_u_u((*g_466).f4, 0xD7))))) | (g_1484 & (-8))), l_2105.f1)) && (safe_sub_func_uint32_t_u_u((((*g_466).f5 > (~g_1484)) , g_2805), g_2805))), g_2054[7][0][1])) == g_1240) < g_2805);
                        (*(&l_1735)) = ((safe_mod_func_uint32_t_u_u(((((safe_mul_func_int16_t_s_s(g_2805, (((g_2805 | (safe_add_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_u((-9), l_2105.f4)) , ((safe_sub_func_uint8_t_u_u((((*(&l_1735)) || (safe_rshift_func_uint8_t_u_s((g_33[2] & (g_2805 != (0x9C > (((g_2318 == g_2805) != l_2164) , g_2805)))), g_2805))) != g_2805), g_2805)) && (*(&k)))), g_1484))) , (void*)0) != (&g_465)))) <= 0) & g_2805) & g_2805), 0x51332F8E)) ^ (*g_466).f5);
                        l_2105 = (*(*l_1831));
                    }

                    return p_50;




                }
            }


            ((l_1431 == 0 || l_1431 == &g_466) ? (void) (0) : __assert_fail ("l_1431 == 0 || l_1431 == &g_466", "t.c", 2242, __PRETTY_FUNCTION__));

for (l_991 = 0; (l_991 <= 3); l_991 += 1)
            {
                struct S0 ***l_2957 = &g_2531[1][1];
                int16_t l_2958 = 0x8258;
                int i, j, k;
            };


                    (*p_50) = (*p_50);
        }
        else
        {
            struct S0 **l_2020 = &g_466;
            int32_t l_2030 = 0xDD04508F;
            uint8_t l_2061 = 255U;
            int32_t **l_2072[1];
            uint16_t l_2122 = 65535U;
            int i;

if (((safe_div_func_int16_t_s_s(l_1631, k)) && 0xD865))
                    {
                        (*(&l_2291)) = (&l_1855);

                        ((l_2437 == 0) ? (void) (0) : __assert_fail ("l_2437 == 0", "t.c", 2267, __PRETTY_FUNCTION__));
                        return l_2291;


                    }
                    else
                    {
                        g_32[1] = &g_21;


                    };


                    for (i = 0; i < 1; i++)
                {
l_1631 += 1;


                    l_2072[i] = &g_986[4][2][3];}


{
                uint32_t l_1901 = 0xCA91294B;
                (*l_1828) = l_1431;

                ((g_465 == &(*l_1431)) ? (void) (0) : __assert_fail ("g_465 == &(*l_1431)", "t.c", 2292, __PRETTY_FUNCTION__));
                l_1901 = (((((*l_1828) == (void*)0) | (*l_2212)) , ((safe_unary_minus_func_int32_t_s((~(((g_1271[1][1] , 0x6E) != l_2061) ^ (safe_unary_minus_func_int32_t_s((*(&g_21)))))))) < ((l_1828 == (void*)0) & (*l_1850)))) && l_2105.f2);
                (*(*l_1893)) = (((safe_lshift_func_int8_t_s_s(g_2619, (!(safe_mod_func_uint8_t_u_u((l_1431 != (void*)0), 1U))))) | ((0U >= ((-1) ^ ((&g_21) != (void*)0))) > (safe_add_func_uint16_t_u_u((safe_rshift_func_int8_t_s_u((safe_mul_func_int8_t_s_s((safe_mul_func_int16_t_s_s(8, l_1901)), l_2105.f6)), 1)), 0x1BE4)))) , (*(*l_1893)));
            }

                    g_1094 += 1;


                    for (g_1240 = (-27); (g_1240 != 13); g_1240++)
            {
                int32_t l_2033 = 5;
                for (g_80 = (-9); (g_80 == 24); g_80 = safe_add_func_uint8_t_u_u(g_80, 9))
                {
                    struct S0 l_2012 = {734,8056,385,947,467,1,241,129,7};
                    struct S0 ***l_2021 = &l_2020;
                    int32_t *l_2036 = &g_33[1];
                    (**g_465) = l_2012;
                    if ((safe_rshift_func_int8_t_s_s(p_54, (safe_rshift_func_int16_t_s_u((((*l_1645) && 0xBB07A94C) <= ((!((g_27.f8 != (((((safe_mul_func_uint16_t_u_u(((&p_53 == (((void*)0 == p_53) , l_2020)) || (((void*)0 != l_2021) || p_54)), 0x9F3C)) , g_27.f3) >= p_54) > p_54) & p_54)) < g_1484)) > p_54)), 3)))))
                    {
                        (*l_1608) = l_2034[1][8][1];
                    }
                    else
                    {
                        struct S0 **l_2035 = &g_466;
                        int32_t *l_2037 = (void*)0;
                        (*l_1608) = p_50;

for (g_4 = 4; (g_4 >= 0); g_4 -= 1)
                {
                    int32_t *l_197 = &g_33[g_2619];
                    int i;
                    g_33[g_2619] = (safe_lshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u((&g_33[g_2619] != (*l_1608)), ((safe_sub_func_int8_t_s_s(0x77, (safe_div_func_int8_t_s_s(((g_33[g_2619] || g_11[0]) <= ((void*)0 == g_466)), (safe_mul_func_uint8_t_u_u((safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((**(&l_1412)), (((((((*(&l_1412)) != (void*)0) , g_4) != 0x4492) , g_2619) == (*l_2036)) == l_2105.f6))), 6)), (*l_1850))), 1U)), l_2105.f0)))))) >= (*l_1850)))), 13));
                    l_1351 = (safe_mod_func_int16_t_s_s(0, g_2619));
                    l_2036 = (*l_1608);

                    (((l_2036 >= &g_33[0] && l_2036 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_2036 >= &g_33[0] && l_2036 <= &g_33[4])", "t.c", 2327, __PRETTY_FUNCTION__));
                    l_197 = (*l_1608);
                };


                    (*p_50) = (&g_466 != l_2035);
                        l_2037 = l_2036;

                        (((l_2037 >= &g_33[0] && l_2037 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_2037 >= &g_33[0] && l_2037 <= &g_33[4])", "t.c", 2335, __PRETTY_FUNCTION__));
                    }
                    (*p_50) = (safe_sub_func_uint16_t_u_u(l_2030, (g_1094 && ((*l_1082) <= (g_784[3] | ((safe_sub_func_uint8_t_u_u(l_2033, (((safe_div_func_uint32_t_u_u(((safe_mod_func_uint8_t_u_u(g_784[3], l_2030)) == (safe_div_func_int16_t_s_s((safe_lshift_func_int8_t_s_u(((((safe_add_func_uint32_t_u_u(0U, ((safe_sub_func_int8_t_s_s((((*g_466) , g_1271[2][1]) > p_54), (*l_2036))) , l_2030))) , 0x52D8) && g_27.f3) || l_2033), 0)), g_2054[7][0][1]))), (*p_50))) >= (*p_50)) ^ p_54))) , p_54))))));
                    for (l_1855 = 0; (l_1855 == 6); ++l_1855)
                    {
                        (*l_1608) = l_2036;
                        if ((*l_2036))
                            break;
                    }
                }
                if ((safe_div_func_int16_t_s_s(0x29FA, p_54)))
                {

{
                    int32_t *l_527 = &(*l_2212);
                    int32_t *l_538 = &g_11[0];
                    (**g_2770) = (void*)0;

                    ((l_2437 == 0) ? (void) (0) : __assert_fail ("l_2437 == 0", "t.c", 2353, __PRETTY_FUNCTION__));
                    (*l_538) = ((safe_mod_func_uint32_t_u_u((*p_53).f0, (*(&g_27)).f7)) , ((safe_rshift_func_uint16_t_u_s(((safe_rshift_func_uint16_t_u_s(((((safe_mul_func_uint8_t_u_u(l_1631, ((l_2370 , l_527) != (((&l_1831 != (void*)0) >= ((safe_mul_func_int16_t_s_s((-1), (((((safe_mod_func_int8_t_s_s(((~(safe_add_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_u((+(((*(&g_27)) , 0xB9E8) , (-4))), (*l_527))) && (*(&g_27)).f2), 4U))) ^ (*(&g_27)).f4), 0x37)) <= l_2370.f6) ^ (*(&g_27)).f1) != g_2647) == l_1631))) < l_2370.f2)) , (void*)0)))) > (*l_2212)) ^ (*p_53).f8) >= (*p_53).f0), 9)) ^ l_2370.f0), 6)) , g_2647));
                }

                    (*p_50) = (safe_mul_func_uint8_t_u_u(0x33, (safe_add_func_uint16_t_u_u((((p_50 == (((safe_rshift_func_int8_t_s_u(((safe_rshift_func_int16_t_s_s(((l_2072[0] != &p_50) > (safe_mod_func_int16_t_s_s(g_784[3], ((safe_sub_func_int16_t_s_s(5, p_54)) , (safe_div_func_int8_t_s_s((safe_unary_minus_func_int8_t_s((safe_rshift_func_int16_t_s_u((safe_sub_func_int8_t_s_s(((p_54 || l_2033) ^ l_2033), (*l_1645))), 6)))), 0xAB)))))), p_54)) < g_1484), g_2054[7][0][1])) > 0U) , (void*)0)) && 0x9B) == l_2033), 0))));
                    (*l_1608) = (void*)0;
                }
                else
                {
                    int32_t *l_2084 = &l_2030;
                    return p_50;




                }
                (*p_50) = 0xE8417F98;
            }



i += 1;


                    (*l_1082) = (+(safe_div_func_uint32_t_u_u(((((((void*)0 == &g_297) <= (((safe_add_func_uint8_t_u_u((0x69B9 < (&l_1831 == &l_2020)), p_54)) , (safe_mod_func_uint8_t_u_u((l_2094[0] && (safe_add_func_int8_t_s_s(((safe_sub_func_int16_t_s_s(g_27.f0, (safe_mul_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((((2 == g_4) < 0xF3) , g_27.f5), p_54)) && p_54), 0)))) < 1), 0U))), 0x48))) ^ g_1240)) || (-5)) | g_21) >= g_1271[2][1]), 0x08BF5774)));

{
                int32_t *l_710 = &l_1735;
                int32_t *l_711 = &(*l_1850);
                if (((safe_lshift_func_int8_t_s_s((safe_sub_func_uint32_t_u_u((safe_div_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((l_1735 < (*g_148)) >= l_1631), (safe_rshift_func_uint16_t_u_s(65535U, (safe_add_func_uint16_t_u_u(6U, (((void*)0 == &(*l_1828)) >= (safe_sub_func_int16_t_s_s(l_2370.f5, (l_2370.f4 < l_2370.f5)))))))))), l_2370.f8)) != l_1986), 1U)), l_2370.f7)), 5)) , (-10)))
                {
                    int32_t *l_702 = (void*)0;
                    if (((safe_div_func_int16_t_s_s(l_1631, (*l_1850))) && 0xD865))
                    {
                        (*(&g_2221)) = l_702;

                        ((l_1412 == 0) ? (void) (0) : __assert_fail ("l_1412 == 0", "t.c", 2389, __PRETTY_FUNCTION__));
                        return l_1412;


                    }
                    else
                    {
                        g_32[1] = &(*g_2221);


                    }


                }
                else
                {
                    int32_t *l_708[5][2][2] = {{{&g_33[2],(void*)0},{&g_33[2],&g_33[2]}},{{&g_33[2],(void*)0},{&g_33[2],&g_33[2]}},{{&g_33[2],(void*)0},{&g_33[2],&g_33[2]}},{{&g_33[2],(void*)0},{&g_33[2],&g_33[2]}},{{&g_33[2],(void*)0},{&g_33[2],&g_33[2]}}};
                    int i, j, k;

{
                    int32_t *l_2419 = &g_11[0];

{
                        (**(&(*g_465))) = (p_54 , (*(*g_465)));
                    }

                    return l_2419;



                }

                    for (l_2370.f8 = 0; (l_2370.f8 >= (-28)); l_2370.f8 = safe_sub_func_uint8_t_u_u(l_2370.f8, 8))
                    {
                        return &g_33[0];



                    }
                    for (l_991 = (-7); (l_991 >= 57); ++l_991)
                    {
                        int32_t *l_709 = &(*l_1850);
                        return l_709;



                    }
                    (*(&g_2221)) = &l_1735;

                    ((l_1412 == &l_1735) ? (void) (0) : __assert_fail ("l_1412 == &l_1735", "t.c", 2438, __PRETTY_FUNCTION__));
                }



                return l_711;




            }

                    for (l_1735 = 25; (l_1735 == (-2)); l_1735--)
            {
                uint32_t l_2108 = 0xA059FF2B;
                struct S0 l_2115 = {76,4931,263,428,393,1,-1125,326,-1};
                (**g_465) = l_2105;
                if ((safe_sub_func_int16_t_s_s(l_2108, ((safe_div_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(((((g_11[0] == ((safe_mod_func_int8_t_s_s((((((((((l_2115 , (safe_div_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u(((((safe_sub_func_int16_t_s_s((p_54 >= ((&p_52 != (g_80 , (void*)0)) | l_2122)), (safe_lshift_func_uint8_t_u_s((((safe_sub_func_int8_t_s_s(((p_54 , (*g_465)) == p_53), (*l_1412))) <= l_2115.f3) < p_54), 5)))) && p_54) < 0) , l_2127), 7)), l_2115.f8))) & 1) >= p_54) | g_1271[2][1]) != g_1240) < 0xBB) | 255U) != g_210.f7) , (-1)), 247U)) >= g_1031[2])) , 5U) | 0xD112) | (*p_50)), 4)) != (*p_50)), l_2115.f5)) && 0x009A5A65))))
                {
                    for (l_2122 = (-17); (l_2122 == 60); l_2122 = safe_add_func_uint8_t_u_u(l_2122, 6))
                    {
                        int32_t *l_2133 = &g_11[0];
                        uint16_t l_2139 = 0x3C07;
                        (*p_50) = ((safe_lshift_func_uint16_t_u_s(((((g_2054[7][0][0] , ((safe_unary_minus_func_int8_t_s((l_2133 != &g_21))) | ((*l_2133) || ((((safe_add_func_uint8_t_u_u(p_54, (g_210.f4 >= ((+(safe_div_func_int8_t_s_s(((((0xDA && ((&p_50 != (*g_296)) , l_2139)) == 0x8C50) && p_54) , (-1)), g_1271[1][1]))) && (*l_2133))))) || g_27.f5) , g_210.f7) , g_1484)))) , (-1)) ^ 0x68) & (*l_2133)), g_27.f1)) | 0U);

for ((*l_2291) = 0; (*l_2291) < 5; (*l_2291)++)
    {

if (l_1631)
                            break;

                    transparent_crc(g_1031[(*l_2291)], "g_1031[(*l_2291)]", (*l_2133));
        if ((*l_2133)) printf("index = [%d]\n", (*l_2291));

    };


                    (*l_1608) = (((safe_mul_func_int16_t_s_s((safe_sub_func_int32_t_s_s((p_54 , l_2115.f2), (safe_mul_func_uint16_t_u_u((l_2146[3] , 65526U), ((safe_lshift_func_uint8_t_u_s((0x2E & (*l_2133)), 2)) , g_210.f5))))), (g_1271[2][1] | 0xD006))) < g_4) , l_2133);
                        (**l_2020) = (*g_466);
                    }
                }
                else
                {

if ((((safe_mul_func_uint16_t_u_u(((((safe_add_func_int32_t_s_s((((safe_rshift_func_uint8_t_u_s(((((*g_2221) == (*g_2221)) | (g_210.f1 > ((*g_2221) >= ((0x7836 > (-1)) <= (safe_sub_func_uint32_t_u_u((safe_rshift_func_int16_t_s_s((*g_2221), 7)), (*g_2221))))))) == (safe_sub_func_uint8_t_u_u(g_1031[0], g_784[3]))), l_2127)) != l_1363) , (*g_2221)), (*(&k)))) >= g_210.f8) == 0x553A) , g_1031[4]), 1)) > l_2127) , 0x11F6AFA3))
    {
        uint16_t l_1597 = 65528U;
        int32_t **l_1608 = &g_986[1][5][2];
        uint16_t l_1609[6][7][6] = {{{0x02EE,0xE191,0xE191,0x02EE,1U,1U},{0x02EE,1U,1U,0U,0xE191,1U},{0x884F,0x3595,0xE191,0xB230,0xE191,0x3595},{0U,1U,0xAD39,0xB230,1U,0xE191},{0x884F,0xE191,0xAD39,0U,0x3595,0x3595},{0x02EE,0xE191,0xE191,0x02EE,1U,1U},{0x02EE,1U,1U,0U,0xE191,1U}},{{0x884F,0x3595,0xE191,0xB230,0xE191,0x3595},{0U,1U,0xAD39,0xB230,1U,0xE191},{0x884F,0xE191,0xAD39,0U,0x3595,0x3595},{0x02EE,0xE191,0xE191,0x02EE,1U,1U},{0x02EE,1U,1U,0U,0xE191,1U},{0x884F,0x3595,0xE191,0xB230,0xE191,0x3595},{0U,1U,0xAD39,0xB230,1U,0xE191}},{{0x884F,0xE191,0xAD39,0U,0x3595,0xE347},{0xAD39,0x6674,0x6674,0xAD39,65535U,2U},{0xAD39,65535U,2U,1U,0x6674,2U},{0xE191,0xE347,0x6674,1U,0x6674,0xE347},{1U,65535U,0x9E0E,1U,65535U,0x6674},{0xE191,0x6674,0x9E0E,1U,0xE347,0xE347},{0xAD39,0x6674,0x6674,0xAD39,65535U,2U}},{{0xAD39,65535U,2U,1U,0x6674,2U},{0xE191,0xE347,0x6674,1U,0x6674,0xE347},{1U,65535U,0x9E0E,1U,65535U,0x6674},{0xE191,0x6674,0x9E0E,1U,0xE347,0xE347},{0xAD39,0x6674,0x6674,0xAD39,65535U,2U},{0xAD39,65535U,2U,1U,0x6674,2U},{0xE191,0xE347,0x6674,1U,0x6674,0xE347}},{{1U,65535U,0x9E0E,1U,65535U,0x6674},{0xE191,0x6674,0x9E0E,1U,0xE347,0xE347},{0xAD39,0x6674,0x6674,0xAD39,65535U,2U},{0xAD39,65535U,2U,1U,0x6674,2U},{0xE191,0xE347,0x6674,1U,0x6674,0xE347},{1U,65535U,0x9E0E,1U,65535U,0x6674},{0xE191,0x6674,0x9E0E,1U,0xE347,0xE347}},{{0xAD39,0x6674,0x6674,0xAD39,65535U,2U},{0xAD39,65535U,2U,1U,0x6674,2U},{0xE191,0xE347,0x6674,1U,0x6674,0xE347},{1U,65535U,0x9E0E,1U,65535U,0x6674},{0xE191,0x6674,0x9E0E,1U,0xE347,0xE347},{0xAD39,0x6674,0x6674,0xAD39,65535U,2U},{0xAD39,65535U,2U,1U,0x6674,2U}}};
        int8_t l_1631 = (-1);
        int32_t *l_1645 = &g_33[1];
        int16_t l_1806[4];
        int32_t l_1811 = 0x9220D5ED;
        struct S0 ***l_1828 = &(*l_1828);
        struct S0 l_1988[1][10][6] = {{{{930,10484,-33,408,498,-1,-2044,351,0x20},{667,1881,484,1397,443,-1,-1876,345,1},{862,10148,-29,791,60,-1,1396,225,0xA0},{629,3324,222,285,186,-1,-430,60,0x39},{862,10148,-29,791,60,-1,1396,225,0xA0},{667,1881,484,1397,443,-1,-1876,345,1}},{{862,10148,-29,791,60,-1,1396,225,0xA0},{930,10484,-33,408,498,-1,-2044,351,0x20},{472,474,97,1332,432,0,784,238,0x70},{375,5022,-201,935,395,1,-242,0,9},{375,5022,-201,935,395,1,-242,0,9},{472,474,97,1332,432,0,784,238,0x70}},{{862,10148,-29,791,60,-1,1396,225,0xA0},{862,10148,-29,791,60,-1,1396,225,0xA0},{375,5022,-201,935,395,1,-242,0,9},{629,3324,222,285,186,-1,-430,60,0x39},{873,5672,238,983,263,0,568,315,0x21},{629,3324,222,285,186,-1,-430,60,0x39}},{{930,10484,-33,408,498,-1,-2044,351,0x20},{862,10148,-29,791,60,-1,1396,225,0xA0},{930,10484,-33,408,498,-1,-2044,351,0x20},{472,474,97,1332,432,0,784,238,0x70},{375,5022,-201,935,395,1,-242,0,9},{375,5022,-201,935,395,1,-242,0,9}},{{667,1881,484,1397,443,-1,-1876,345,1},{930,10484,-33,408,498,-1,-2044,351,0x20},{930,10484,-33,408,498,-1,-2044,351,0x20},{667,1881,484,1397,443,-1,-1876,345,1},{873,5672,238,983,263,0,568,315,0x21},{472,474,97,1332,432,0,784,238,0x70}},{{472,474,97,1332,432,0,784,238,0x70},{930,10484,-33,408,498,-1,-2044,351,0x20},{862,10148,-29,791,60,-1,1396,225,0xA0},{930,10484,-33,408,498,-1,-2044,351,0x20},{472,474,97,1332,432,0,784,238,0x70},{375,5022,-201,935,395,1,-242,0,9}},{{930,10484,-33,408,498,-1,-2044,351,0x20},{472,474,97,1332,432,0,784,238,0x70},{375,5022,-201,935,395,1,-242,0,9},{375,5022,-201,935,395,1,-242,0,9},{472,474,97,1332,432,0,784,238,0x70},{930,10484,-33,408,498,-1,-2044,351,0x20}},{{629,3324,222,285,186,-1,-430,60,0x39},{930,10484,-33,408,498,-1,-2044,351,0x20},{873,5672,238,983,263,0,568,315,0x21},{472,474,97,1332,432,0,784,238,0x70},{873,5672,238,983,263,0,568,315,0x21},{930,10484,-33,408,498,-1,-2044,351,0x20}},{{873,5672,238,983,263,0,568,315,0x21},{629,3324,222,285,186,-1,-430,60,0x39},{375,5022,-201,935,395,1,-242,0,9},{862,10148,-29,791,60,-1,1396,225,0xA0},{862,10148,-29,791,60,-1,1396,225,0xA0},{375,5022,-201,935,395,1,-242,0,9}},{{873,5672,238,983,263,0,568,315,0x21},{873,5672,238,983,263,0,568,315,0x21},{862,10148,-29,791,60,-1,1396,225,0xA0},{472,474,97,1332,432,0,784,238,0x70},{667,1881,484,1397,443,-1,-1876,345,1},{472,474,97,1332,432,0,784,238,0x70}}}};
        int32_t *l_2034[4][9][4] = {{{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j}},{{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j}},{{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j}},{{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j},{&j,&g_11[0],&g_11[0],&j},{&l_1167[6][6],&g_11[0],&g_11[0],&j}}};
        int16_t l_2127 = 0x6528;
        int32_t l_2146[7];
        int32_t l_2164 = 0xA94B3798;
        uint8_t l_2169[9][5][1] = {{{0xAC},{0U},{255U},{0U},{0xAC}},{{0x4A},{0x4A},{0xBE},{0x4A},{0x4A}},{{0xAC},{0U},{255U},{0U},{0x8B}},{{0x1D},{255U},{0x4A},{255U},{0x1D}},{{0x8B},{0xBE},{0xAC},{0xBE},{0x8B}},{{0x1D},{255U},{0x4A},{255U},{0x1D}},{{0x8B},{0xBE},{0xAC},{0xBE},{0x8B}},{{0x1D},{255U},{0x4A},{255U},{0x1D}},{{0x8B},{0xBE},{0xAC},{0xBE},{0x8B}}};
        int32_t *l_2291 = (void*)0;
        uint32_t l_2323 = 9U;
        int i, j, k;

for ((*g_148) = 3; ((*g_148) >= 0); (*g_148) -= 1)
            {
                int32_t *l_1433 = &g_11[0];
                int32_t l_1451 = 0x78DACA4D;
                struct S0 ***l_1493 = (void*)0;
                uint16_t l_1500 = 65532U;
                uint32_t l_1513 = 0U;
            };


                    for (i = 0; i < 4; i++)
            l_1806[i] = 0x2AE3;
        for (i = 0; i < 7; i++)
            {
{
                uint32_t l_663 = 0x8AA41A1D;
                int32_t l_664[7];
                struct S0 l_678 = {434,4928,306,294,0,0,-984,261,0};
                int i;
                for (i = 0; i < 7; i++)
                    l_664[i] = 0x017C58A9;
                for (l_1631 = 0; (l_1631 <= 0); l_1631 += 1)
                {
                    uint16_t l_673 = 2U;
                    struct S0 *l_674 = (void*)0;
                    for (g_1094 = 0; (g_1094 <= 0); g_1094 += 1)
                    {
                        int i;
                        (*(*l_1508)) = &g_11[l_1631];

                        (((l_1412 >= &g_11[0] && l_1412 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_1412 >= &g_11[0] && l_1412 <= &g_11[0])", "t.c", 2532, __PRETTY_FUNCTION__));
                    }
                    for (g_2318 = 0; (g_2318 <= 0); g_2318 += 1)
                    {
                        int i, j, k;
                        (*(*l_1508)) = (void*)0;

                        ((l_1412 == 0) ? (void) (0) : __assert_fail ("l_1412 == 0", "t.c", 2539, __PRETTY_FUNCTION__));
                        if (l_1631)
                            continue;
                        l_664[6] = (((safe_div_func_uint16_t_u_u(l_2115.f4, (safe_unary_minus_func_int8_t_s((l_2115.f0 || l_2108))))) <= l_663) && l_1631);
                        (*(&g_1240)) = (l_2115.f8 ^ (safe_rshift_func_int16_t_s_s((((**(&g_465)) != ((safe_unary_minus_func_int16_t_s(((safe_mod_func_int32_t_s_s((l_2108 , (((safe_add_func_int8_t_s_s(((l_664[5] & g_33[2]) && l_1631), (((((((4U > g_210.f2) < (l_1363 & l_673)) , 0xB124) ^ l_2108) & l_2115.f7) || l_2115.f0) , l_2115.f4))) , l_673) < l_1631)), 1)) | g_210.f6))) , l_674)) <= l_664[6]), 7)));
                    }
                }
                for (l_663 = 22; (l_663 > 12); l_663 = safe_sub_func_uint32_t_u_u(l_663, 8))
                {
                    int32_t *l_677 = &g_11[0];
                    (**g_296) = l_677;

                    (((l_1412 >= &g_11[0] && l_1412 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_1412 >= &g_11[0] && l_1412 <= &g_11[0])", "t.c", 2551, __PRETTY_FUNCTION__));
                }
                (***(&g_465)) = l_678;
            }

                    l_2146[i] = 0;}
        if ((l_1597 , (l_1363 ^ (safe_rshift_func_uint8_t_u_u(l_1363, (safe_mod_func_uint32_t_u_u(((safe_lshift_func_int8_t_s_s((safe_mod_func_int32_t_s_s((((safe_div_func_int16_t_s_s(l_1363, ((l_1608 == ((l_1363 >= 0xBFE530C4) , (void*)0)) ^ l_1597))) < l_1609[4][4][0]) & 0x15), l_1363)), 3)) , g_210.f1), j)))))))
        {
            int32_t l_1624 = 0x628DB18D;
            uint16_t l_1625[6] = {0x62D2,0x62D2,0x62D2,0x62D2,0x62D2,0x62D2};
            int32_t *l_1644 = &g_11[0];
            int8_t l_1650 = 0x66;
            uint8_t l_1716 = 249U;
            struct S0 **l_1768 = &g_466;
            int32_t l_1807 = 0xEB0E47A2;
            int32_t *l_1921 = &l_1811;
            int32_t l_1937[6][2][9] = {{{3,(-7),0x283AE863,0x9EC4EBA9,1,0x3F82680D,1,2,9},{0x92F47D50,7,0x9EC4EBA9,(-1),(-1),0x9EC4EBA9,7,0x92F47D50,(-1)}},{{1,(-1),2,0xE04201F9,3,0x571F4D4F,(-10),0x3F82680D,0xD54CC6FA},{0x1B72C53B,0x6864222F,0xCE274C68,0x88EB1EBE,0x746D1AB6,0x71218D43,1,3,(-1)}},{{0xCE274C68,0x1B72C53B,0xE04201F9,(-8),5,1,0xD54CC6FA,0x51722963,9},{6,0xF54EDA0C,7,0xD54CC6FA,(-7),0,0x38FFB9A0,(-10),0x72DEC890}},{{6,1,0x25CE7411,0,1,1,0,0x25CE7411,1},{0xCE274C68,0x51722963,(-7),0x9436678D,0x88EB1EBE,0x283AE863,9,5,0x571F4D4F}},{{0x1B72C53B,1,0xF54EDA0C,(-10),0xE1B54DE9,0xE04201F9,0x571F4D4F,1,0x88EB1EBE},{1,0x51722963,(-8),0x3F82680D,0x0A9A4735,(-1),(-1),0x88EB1EBE,5}},{{0x92F47D50,1,0x38FFB9A0,1,0x71218D43,0xF54EDA0C,0x746D1AB6,0x72DEC890,(-8)},{3,0xF54EDA0C,0x38FFB9A0,1,0x283AE863,0x0A9A4735,0x0A9A4735,0x283AE863,1}}};
            uint32_t l_1939 = 0x5C059D13;
            int i, j, k;
            if (((safe_mod_func_int8_t_s_s(((g_80 || 0xE899) == (((safe_mul_func_int16_t_s_s((((g_33[3] && g_784[3]) , (((safe_lshift_func_int8_t_s_u(((+((((((*g_465) != (void*)0) , (g_210.f3 <= ((((0xBF | (((safe_mod_func_int8_t_s_s(((0x0C63EB16 && 0x37A43F76) > (-7)), 1)) , 0x56C26C1F) , l_1363)) <= g_210.f3) , g_210.f4) != l_1609[4][4][0]))) >= l_1363) && 0xFA5D) <= (*(*p_52)))) < (*(*p_52))), 4)) != 0U) <= l_1363)) == 3), l_1363)) , l_1624) >= (-1))), l_1625[1])) > g_210.f4))
            {
                int16_t l_1662[9] = {0x60FB,0x60FB,0x60FB,0x60FB,0x60FB,0x60FB,0x60FB,0x60FB,0x60FB};
                uint16_t l_1663 = 0x2A05;
                int32_t **l_1676 = (void*)0;
                int i;

{
                int32_t *l_1220 = &l_1167[5][4];
                int32_t l_1239 = 5;
                int32_t l_1319 = 0x0E489A9E;
                uint16_t l_1349 = 1U;
                struct S0 ***l_1362[8];
                struct S0 *l_1407 = (void*)0;
                int32_t l_1410 = 9;
                int i;
                for (i = 0; i < 8; i++)
                    l_1362[i] = (void*)0;
                if ((*l_1644))
                {
                    int32_t *l_1219 = &g_33[2];
                    struct S0 ***l_1250[4] = {&l_1831,&l_1831,&l_1831,&l_1831};
                    struct S0 l_1255 = {192,4318,-489,36,135,-0,1153,251,0x86};
                    int i;
                    if ((~l_1716))
                    {
                        l_1219 = l_1219;
                        l_1220 = (void*)0;

                        ((l_1220 == 0) ? (void) (0) : __assert_fail ("l_1220 == 0", "t.c", 2599, __PRETTY_FUNCTION__));
                    }
                    else
                    {
                        int32_t **l_1241 = &g_32[0];
                        (*l_1220) = (safe_add_func_uint16_t_u_u((l_1219 == &g_11[0]), (((safe_add_func_uint32_t_u_u((((safe_rshift_func_uint16_t_u_s(g_210.f2, ((((*l_1219) & ((safe_rshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s(((safe_sub_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u(((void*)0 == &l_1676), 10)), (((*(*l_1768)) , (((l_1716 != l_1716) || l_1716) && l_1716)) ^ 0x76))) >= l_1716), (*l_1220))) >= l_1239), 0x8F)), 0)) == l_1904)) >= l_1716) < 0x6B1FB5AC))) > g_1031[4]) , (*l_1219)), j)) || (*l_1644)) <= (*l_1220))));
                        (*l_1241) = (void*)0;
                        (*l_2212) = ((safe_mul_func_int16_t_s_s((l_1716 > (safe_div_func_int32_t_s_s(((safe_sub_func_int8_t_s_s((0x76 ^ (0xFD != ((*l_1219) > (*l_1644)))), (safe_mul_func_uint16_t_u_u(0x6A67, 0xFFEE)))) | (((l_1250[0] != (void*)0) , l_1716) > 65535U)), (*l_1219)))), 0xC94C)) && l_1716);
                        (*(*l_1768)) = (*(*l_1768));
                    }

                    (((l_1220 >= &l_1167[0][0] && l_1220 <= &l_1167[8][6]) || l_1220 == 0) ? (void) (0) : __assert_fail ("(l_1220 >= &l_1167[0][0] && l_1220 <= &l_1167[8][6]) || l_1220 == 0", "t.c", 2610, __PRETTY_FUNCTION__));
                    l_1219 = &l_1167[4][3];

                    (((l_1219 >= &l_1167[0][0] && l_1219 <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("(l_1219 >= &l_1167[0][0] && l_1219 <= &l_1167[8][6])", "t.c", 2613, __PRETTY_FUNCTION__));
                }
                else
                {
                    (*(&k)) = (*l_1644);
                }

                (((l_1220 >= &l_1167[0][0] && l_1220 <= &l_1167[8][6]) || l_1220 == 0) ? (void) (0) : __assert_fail ("(l_1220 >= &l_1167[0][0] && l_1220 <= &l_1167[8][6]) || l_1220 == 0", "t.c", 2620, __PRETTY_FUNCTION__));
                for ((*l_2437) = (-2); ((*l_2437) > (-21)); --(*l_2437))
                {
                    int8_t l_1279 = 0;
                    int8_t l_1329 = (-1);
                    int32_t ***l_1336 = (void*)0;
                    int8_t l_1348 = 1;
                    struct S0 l_1350 = {599,171,-440,1398,438,-1,-231,342,0};
                    (*(&g_297)) = &l_1644;

                    ((l_1676 == &l_1644) ? (void) (0) : __assert_fail ("l_1676 == &l_1644", "t.c", 2630, __PRETTY_FUNCTION__));
                    if ((((safe_mod_func_uint8_t_u_u((((+((((g_210.f3 , ((((safe_div_func_uint32_t_u_u(l_1716, l_1279)) == ((void*)0 == (*(&l_1676)))) <= ((!((safe_rshift_func_int16_t_s_u(l_1716, 5)) == ((safe_lshift_func_uint16_t_u_u(((((safe_rshift_func_int16_t_s_s((safe_mul_func_int16_t_s_s((l_1279 & (((((**(&g_297)) == ((l_1716 >= l_1716) , (*l_1676))) || 0x4474) < 0xF0E8F346) & g_11[0])), l_1279)), g_784[0])) < g_210.f5) , l_1279) , g_210.f4), l_1716)) && (***(&l_1608))))) , 0x66C85F8A)) , 0x993C)) != l_1279) , (*l_1831)) != (void*)0)) > l_1279) & 0x8FA0), 5U)) , g_1271[2][1]) < l_1279))
                    {
                        (*l_1644) = ((!(l_1986 && (safe_rshift_func_uint16_t_u_s(l_1716, (l_1716 != (safe_sub_func_int16_t_s_s((+((+(safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((((((&l_1644 == ((l_1716 > (safe_rshift_func_uint8_t_u_u((*l_1921), 2))) , &l_1644)) && (***(&g_297))) & ((((safe_sub_func_int8_t_s_s((((*l_1768) == (*l_1768)) & l_1716), l_1279)) || 1) , g_210.f7) <= l_1986)) | 0x7B86) == 0) == l_1716), 0x08)), l_1716)), g_210.f4))) != 0)), l_1306[4][2][4]))))))) , 0);
                    }
                    else
                    {
                        int16_t l_1344 = 1;
                        int32_t ***l_1347 = &l_1676;
                        (**l_1676) = (+(((((((safe_rshift_func_uint16_t_u_s(((**l_1676) && (*l_1644)), (safe_add_func_uint16_t_u_u(g_11[0], ((safe_lshift_func_int16_t_s_u((((void*)0 != &l_1676) >= l_1716), (safe_div_func_int8_t_s_s((g_784[3] , ((l_1716 <= (safe_rshift_func_uint16_t_u_s(65529U, 2))) && (***(&l_1608)))), l_1716)))) && 0x4B36))))) < 255U) < l_1716) < g_33[2]) ^ (*l_1644)) == 0) < 0x6094));
                        (**(&l_1608)) = (**(&l_1608));
                        (**l_1676) = ((((((safe_mul_func_int16_t_s_s((((void*)0 == (*l_1676)) ^ ((g_210.f7 , (***(&l_1676))) ^ (safe_div_func_int16_t_s_s((((safe_rshift_func_int16_t_s_s((l_1336 != (((safe_add_func_uint8_t_u_u(g_210.f0, (safe_sub_func_int8_t_s_s(l_2500, (safe_mod_func_int16_t_s_s((l_1344 | (safe_mod_func_uint32_t_u_u(((*l_1768) == (void*)0), l_1344))), (-8))))))) && 0x3B) , l_1347)), l_1716)) , 0xD8) < l_1716), g_1031[3])))), l_1348)) && (***l_1347)) < 0xD0DF30A5) ^ (*(&k))) | (***(&l_1676))) , l_1349);
                        l_1350 = (*(*l_1768));
                    }
                }

                ((l_1676 == &l_1644 || l_1676 == 0) ? (void) (0) : __assert_fail ("l_1676 == &l_1644 || l_1676 == 0", "t.c", 2646, __PRETTY_FUNCTION__));
                if ((g_2318 , (((0xFED2 == ((*l_1644) >= ((((1 && (((((l_1644 != (void*)0) & (safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((safe_mul_func_int16_t_s_s((safe_div_func_uint16_t_u_u(l_1716, l_1716)), (safe_add_func_int32_t_s_s((((&l_1831 == l_1362[5]) != (*l_1644)) >= g_2805), (*l_1644))))), g_784[3])), g_784[3]))) ^ g_1031[3]) <= (*g_2221)) > l_1716)) > l_1716) == 0x9A) < (*(&k))))) & 0xCABBB83D) , (*g_2221))))
                {
                    for (l_2500 = (-6); (l_2500 != 19); l_2500 = safe_add_func_int8_t_s_s(l_2500, 5))
                    {
                        struct S0 *l_1374 = &l_2370;
                        uint8_t l_1375 = 0xEB;
                        int32_t **l_1384 = &g_944[6][1][4];
                        (*l_1384) = ((safe_sub_func_int8_t_s_s(g_210.f6, (safe_add_func_uint32_t_u_u(((safe_add_func_int8_t_s_s((-5), (safe_add_func_int8_t_s_s(0x81, (((l_1374 != (*l_1768)) | l_1375) && (safe_lshift_func_int8_t_s_s(l_1986, (safe_add_func_uint8_t_u_u(((*l_1644) > ((!(safe_mul_func_uint8_t_u_u(g_210.f1, (-9)))) || 0xBB08)), 0x6F))))))))) ^ l_1181), 4294967294U)))) , (void*)0);
                    }
                }
                else
                {
                    int16_t l_1402 = (-1);
                    int32_t *l_1415 = &(*l_1921);
                    (*(&k)) = (safe_div_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((safe_lshift_func_int16_t_s_u(((safe_div_func_int32_t_s_s(((void*)0 != &l_1167[4][2]), (safe_mul_func_uint8_t_u_u((g_784[1] >= ((safe_div_func_uint16_t_u_u(((safe_mul_func_int8_t_s_s(0xAE, ((*l_1644) <= (!(*l_1644))))) | ((((*(&k)) < (((safe_add_func_int8_t_s_s(((((((*l_1644) == l_1716) || 65535U) , (void*)0) != &(*l_1768)) > (*l_1644)), (*l_2437))) || g_33[2]) && 0xF8180D4D)) && l_1716) , 0)), l_1716)) != g_210.f4)), g_11[0])))) && l_1402), 15)), g_784[1])), 0x40));
                    (*g_297) = ((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((((l_1407 != &l_2370) , 0x813C1E7A) & (l_1716 && ((((void*)0 == (*l_1768)) | g_210.f4) < ((((safe_rshift_func_uint8_t_u_s(l_1716, 4)) <= l_1904) ^ l_1410) || 0x6C)))), g_1240)), 0x9F)) , &g_11[0]);

                    ((((*g_297) >= &g_11[0] && (*g_297) <= &g_11[0])) ? (void) (0) : __assert_fail ("((*g_297) >= &g_11[0] && (*g_297) <= &g_11[0])", "t.c", 2664, __PRETTY_FUNCTION__));
                    for ((*l_1850) = 0; ((*l_1850) >= 11); (*l_1850) = safe_add_func_int8_t_s_s((*l_1850), 7))
                    {
                        int32_t **l_1416[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_1416[i] = &g_986[1][2][3];
                        l_1850 = l_1415;

                        ((l_1850 == &(*l_1921)) ? (void) (0) : __assert_fail ("l_1850 == &(*l_1921)", "t.c", 2673, __PRETTY_FUNCTION__));
                    }

                    ((l_1850 == &(*l_1921) || l_1850 == 0 || (l_1850 >= &g_11[0] && l_1850 <= &g_11[0])) ? (void) (0) : __assert_fail ("l_1850 == &(*l_1921) || l_1850 == 0 || (l_1850 >= &g_11[0] && l_1850 <= &g_11[0])", "t.c", 2676, __PRETTY_FUNCTION__));
                }

                ((l_1850 == &(*l_1921) || l_1850 == 0 || (l_1850 >= &g_11[0] && l_1850 <= &g_11[0])) ? (void) (0) : __assert_fail ("l_1850 == &(*l_1921) || l_1850 == 0 || (l_1850 >= &g_11[0] && l_1850 <= &g_11[0])", "t.c", 2679, __PRETTY_FUNCTION__));
                ((((*g_297) >= &g_11[0] && (*g_297) <= &g_11[0]) || ((*g_297) >= &g_33[0] && (*g_297) <= &g_33[4])) ? (void) (0) : __assert_fail ("((*g_297) >= &g_11[0] && (*g_297) <= &g_11[0]) || ((*g_297) >= &g_33[0] && (*g_297) <= &g_33[4])", "t.c", 2680, __PRETTY_FUNCTION__));
            }

                    (*l_1645) = (safe_rshift_func_int16_t_s_u((!(((*g_2221) , ((safe_mod_func_int8_t_s_s(((l_1631 != (l_1363 , (0xF8 >= 0x19))) > (safe_mod_func_uint16_t_u_u(l_1363, (safe_sub_func_int32_t_s_s(((safe_sub_func_uint16_t_u_u(g_1271[2][1], ((safe_add_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u(l_2127, (safe_rshift_func_uint8_t_u_u(((((&(*p_52) == (void*)0) && 9) , l_1644) != l_1645), 5)))), g_210.f7)) >= (-1)))) | (*l_1644)), 0x2153F809))))), 0x42)) , 9)) > (*l_1645))), 3));
                (*(*p_52)) = (safe_add_func_int32_t_s_s((*l_1644), (safe_sub_func_int32_t_s_s(((((*l_1644) == l_1650) , g_1031[4]) | ((-9) == l_1363)), (safe_rshift_func_int8_t_s_s(((*l_1644) <= (safe_unary_minus_func_int16_t_s(((((safe_mul_func_uint16_t_u_u(l_1363, ((safe_rshift_func_uint16_t_u_s(((((safe_lshift_func_uint8_t_u_s((safe_sub_func_int16_t_s_s((4U <= l_1363), l_1662[3])), (*l_1645))) > (*l_1644)) > l_1363) || l_1363), (*l_1644))) , g_210.f0))) >= g_210.f7) >= 0x75F9A0D7) | l_1663)))), l_1363))))));
                if ((0xE37E | (((((safe_lshift_func_uint16_t_u_u((safe_div_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(((((&p_52) != (void*)0) , (((((((((safe_rshift_func_int16_t_s_u(((0x02 || ((*g_2221) || (safe_mod_func_uint8_t_u_u((safe_div_func_uint32_t_u_u((0x47BAC912 && (((void*)0 == &g_466) , 1)), (*l_1645))), l_1363)))) && 0xF4), g_210.f6)) , &g_11[0]) == (void*)0) || (*l_1644)) , (void*)0) == l_1676) , (*l_2020)) == (*l_2020)) > 0x3DE1)) , l_1363), 1)), g_210.f0)), l_1363)) != 0xF3C0) < l_1363) , (-1)) | g_784[1])))
                {
                    for (j = 4; (j >= 0); j -= 1)
                    {


(*l_1850) -= 1;


                    for (l_2003 = 22; (l_2003 == (-3)); l_2003 = safe_sub_func_int32_t_s_s(l_2003, 1))
                    {
                        uint8_t l_1841 = 0xAC;
                        (*(&l_2437)) = l_1921;
                        (**l_1431) = (*(*l_1768));

if ((((safe_mod_func_uint8_t_u_u((((+((((g_210.f3 , ((((safe_div_func_uint32_t_u_u(l_1052, l_1650)) == ((void*)0 == (*(&p_51)))) <= ((!((safe_rshift_func_int16_t_s_u(l_1052, 5)) == ((safe_lshift_func_uint16_t_u_u(((((safe_rshift_func_int16_t_s_s((safe_mul_func_int16_t_s_s((l_1650 & (((((**l_1508) == ((l_1052 >= l_1052) , (*l_1608))) || 0x4474) < 0xF0E8F346) & g_11[0])), l_1650)), g_784[0])) < g_210.f5) , l_1650) , g_210.f4), l_1052)) && (***l_1508)))) , 0x66C85F8A)) , 0x993C)) != l_1650) , (*l_1831)) != (void*)0)) > l_1650) & 0x8FA0), 5U)) , g_1271[2][1]) < l_1650))
                    {
                        (*l_1850) = ((!(g_2647 && (safe_rshift_func_uint16_t_u_s(l_1052, (l_1052 != (safe_sub_func_int16_t_s_s((+((+(safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((((((&l_1850 == ((l_1052 > (safe_rshift_func_uint8_t_u_u((*g_148), 2))) , &l_1850)) && (***l_1508)) & ((((safe_sub_func_int8_t_s_s((((*l_1831) == (*l_1831)) & l_1052), l_1650)) || 1) , g_210.f7) <= g_2647)) | 0x7B86) == 0) == l_1052), 0x08)), l_1052)), g_210.f4))) != 0)), l_1306[4][2][4]))))))) , 0);
                    }
                    else
                    {
                        int16_t l_1344 = 1;
                        int32_t ***l_1347 = &l_1608;
                        (**l_1608) = (+(((((((safe_rshift_func_uint16_t_u_s(((**l_1608) && (*l_1850)), (safe_add_func_uint16_t_u_u(g_11[0], ((safe_lshift_func_int16_t_s_u((((void*)0 != &l_1608) >= l_1052), (safe_div_func_int8_t_s_s((g_784[3] , ((l_1052 <= (safe_rshift_func_uint16_t_u_s(65529U, 2))) && (***l_1508))), l_1052)))) && 0x4B36))))) < 255U) < l_1052) < g_33[2]) ^ (*l_1644)) == 0) < 0x6094));
                        (**l_1508) = (**l_1508);
                        (**l_1608) = ((((((safe_mul_func_int16_t_s_s((((void*)0 == (*l_1608)) ^ ((g_210.f7 , (***(&p_51))) ^ (safe_div_func_int16_t_s_s((((safe_rshift_func_int16_t_s_s(((&l_1676) != (((safe_add_func_uint8_t_u_u(g_210.f0, (safe_sub_func_int8_t_s_s(g_2647, (safe_mod_func_int16_t_s_s((l_1344 | (safe_mod_func_uint32_t_u_u(((*l_1831) == (void*)0), l_1344))), (-8))))))) && 0x3B) , l_1347)), l_1052)) , 0xD8) < l_1052), g_1031[3])))), l_1650)) && (***l_1347)) < 0xD0DF30A5) ^ (*(*p_51))) | (***(&p_51))) , l_1122);
                        g_210 = (*(*l_1831));
                    };


                    (*(&l_2437)) = &g_11[0];
                        l_1645 = p_50;

                        ((l_1645 == 0) ? (void) (0) : __assert_fail ("l_1645 == 0", "t.c", 2718, __PRETTY_FUNCTION__));
                    };


                    return (*l_1608);



                    }
                }
                else
                {
                    uint32_t l_1686 = 4294967293U;
                    for (g_2619 = (-5); (g_2619 != (-23)); g_2619 = safe_sub_func_uint32_t_u_u(g_2619, 7))
                    {
                        (*g_2221) = (*(*p_52));
                        (*(&k)) = ((1 || ((((safe_rshift_func_uint8_t_u_u(((~(safe_rshift_func_int16_t_s_s((safe_mod_func_int8_t_s_s(g_210.f1, (*l_2291))), 0))) ^ l_1686), 2)) , (g_210.f6 , g_210.f7)) | ((safe_lshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(g_210.f0, (safe_div_func_uint16_t_u_u((safe_unary_minus_func_int32_t_s((+(g_11[0] , (((void*)0 == &g_466) || (*(*p_52))))))), 0xE6B3)))), 0)) != l_1686)) && l_1363)) || (-4));
                    }
                }
            }
            else
            {
                int32_t l_1711 = 0xA6BF7172;
                int32_t l_1753 = 0;
                uint16_t l_1791 = 65532U;
                struct S0 ***l_1873 = &l_1768;
                if ((safe_sub_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s((safe_sub_func_uint8_t_u_u((safe_sub_func_uint16_t_u_u(((((!0xB5) , (safe_mod_func_uint16_t_u_u(g_80, g_210.f8))) == (safe_add_func_int16_t_s_s((l_1363 & (*(*p_52))), l_1363))) == l_1363), (safe_lshift_func_uint16_t_u_u(g_210.f3, 8)))), l_1711)), 9)), 0x95E60F64)))
                {
                    int32_t *l_1712 = (void*)0;
                    l_1712 = &g_11[0];

                    (((l_1712 >= &g_11[0] && l_1712 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_1712 >= &g_11[0] && l_1712 <= &g_11[0])", "t.c", 2749, __PRETTY_FUNCTION__));
                    for (l_2108 = 0; (l_2108 <= 2); l_2108 += 1)
                    {
                        int i;
                        return g_32[l_2108];



                    }
                }
                else
                {
                    int8_t l_1751 = 0;
                    int8_t l_1752 = (-6);
                    int32_t *l_1760 = &l_1167[6][6];
                    for (l_1711 = 0; (l_1711 <= (-6)); l_1711--)
                    {
                        int32_t *l_1715 = &g_11[0];
                        (*l_1608) = (void*)0;
                        (*l_1644) = (*(*p_52));
                        (*l_1608) = l_1715;
                    }
                    if (l_1716)
                    {
                        uint8_t l_1730 = 0xB5;
                        int32_t ***l_1733[5][5][9] = {{{&p_52,&p_52,&l_1608,&p_52,(void*)0,(void*)0,&l_1608,&l_1608,&l_1608},{&l_1608,&l_1608,(void*)0,&l_1608,&p_52,&l_1608,(void*)0,&l_1608,&l_1608},{(void*)0,&p_52,&p_52,&l_1608,&l_1608,&l_1608,&p_52,&p_52,(void*)0},{&l_1608,(void*)0,(void*)0,&l_1608,&p_52,&p_52,&p_52,&p_52,&p_52},{(void*)0,&p_52,&p_52,&l_1608,&l_1608,&p_52,&l_1608,&p_52,(void*)0}},{{(void*)0,&p_52,&l_1608,&l_1608,(void*)0,&p_52,&p_52,&l_1608,(void*)0},{&p_52,&l_1608,&l_1608,&p_52,&l_1608,&l_1608,(void*)0,&p_52,&l_1608},{&p_52,&l_1608,&l_1608,&l_1608,(void*)0,&l_1608,&p_52,&p_52,(void*)0},{&p_52,(void*)0,&l_1608,&l_1608,(void*)0,&l_1608,&p_52,&p_52,(void*)0},{&p_52,&p_52,(void*)0,(void*)0,&l_1608,&p_52,(void*)0,&p_52,&l_1608}},{{&l_1608,&p_52,&p_52,&p_52,&p_52,&p_52,&l_1608,&l_1608,&p_52},{&l_1608,&p_52,(void*)0,&p_52,&l_1608,(void*)0,&p_52,&p_52,(void*)0},{&l_1608,&l_1608,&l_1608,&p_52,(void*)0,&p_52,&l_1608,(void*)0,(void*)0},{&p_52,(void*)0,&l_1608,&l_1608,&p_52,(void*)0,&l_1608,(void*)0,&l_1608},{&p_52,(void*)0,&l_1608,&l_1608,&p_52,&p_52,&l_1608,&l_1608,&l_1608}},{{&p_52,&l_1608,(void*)0,&l_1608,(void*)0,&p_52,&p_52,(void*)0,(void*)0},{&l_1608,&p_52,&l_1608,&l_1608,(void*)0,&l_1608,(void*)0,&p_52,(void*)0},{&l_1608,&l_1608,&l_1608,&l_1608,&l_1608,&l_1608,(void*)0,&l_1608,&p_52},{(void*)0,(void*)0,(void*)0,&l_1608,(void*)0,&l_1608,&p_52,(void*)0,&l_1608},{&l_1608,&l_1608,&l_1608,&l_1608,&p_52,&p_52,&l_1608,&l_1608,&l_1608}},{{&p_52,&l_1608,&l_1608,&l_1608,&l_1608,&p_52,&p_52,&p_52,&l_1608},{&l_1608,&p_52,&l_1608,&p_52,(void*)0,&p_52,(void*)0,&l_1608,&l_1608},{&p_52,&l_1608,&l_1608,&p_52,&p_52,(void*)0,&p_52,(void*)0,&p_52},{&p_52,&l_1608,(void*)0,&p_52,&p_52,&l_1608,&p_52,&p_52,(void*)0},{&l_1608,(void*)0,&p_52,(void*)0,&p_52,&l_1608,&l_1608,(void*)0,&l_1608}}};
                        int i, j, k;
                        (*(&k)) = ((safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_s(g_1271[0][0], 5)), (0x7F ^ l_1363))) && (*(*p_52)));

{
        (**(&l_1412)) = (**(&l_1412));
        (*(*g_296)) = (*(&l_1412));

        (((l_2212 >= &g_33[0] && l_2212 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_2212 >= &g_33[0] && l_2212 <= &g_33[4])", "t.c", 2782, __PRETTY_FUNCTION__));
        (*(*g_296)) = (*(&l_1412));
    }

                    (*l_1644) = (safe_sub_func_uint32_t_u_u((safe_add_func_uint8_t_u_u((0x322C < (safe_lshift_func_int8_t_s_s((+(safe_rshift_func_uint8_t_u_s(l_1730, (safe_sub_func_uint8_t_u_u((&p_52 != l_1733[4][1][2]), g_210.f7))))), (((!0) && (*g_2221)) < (safe_mod_func_int32_t_s_s((*l_1644), (*(*p_52)))))))), 0U)), l_1711));
                    }
                    else
                    {
                        (**l_2020) = (l_1363 , (*(*g_465)));
                    }
                    for (l_1122 = 1; (l_1122 <= 5); l_1122 += 1)
                    {
                        int32_t l_1740 = (-2);
                        (*g_466) = (**l_2020);
                        (*(*p_52)) = (safe_mod_func_uint16_t_u_u((l_1740 || (g_1271[1][2] < (((((safe_lshift_func_uint8_t_u_s((safe_mul_func_uint16_t_u_u(0xBABA, 3)), 7)) >= (safe_mul_func_int8_t_s_s((g_11[0] >= ((g_33[4] , 0x05D97D54) == (safe_div_func_uint32_t_u_u(((((((safe_mul_func_uint8_t_u_u(l_1363, (((l_1740 < l_1751) , &p_52) == &g_297))) > 0x5C49B460) >= g_210.f0) || 1) >= l_1711) <= (*l_1645)), l_1752)))), (-1)))) , l_1711) , 65532U) == 0x6130))), g_210.f1));
                        (*(&l_1608)) = &(*p_52);

                        ((p_52 == &(*p_52)) ? (void) (0) : __assert_fail ("p_52 == &(*p_52)", "t.c", 2799, __PRETTY_FUNCTION__));
                    }
                    l_1760 = ((l_1753 , (((l_1363 != 1) > ((safe_lshift_func_uint16_t_u_s((safe_rshift_func_uint8_t_u_s((safe_div_func_uint8_t_u_u((&(*g_465) != &(*g_465)), 3)), 5)), ((void*)0 != &(*l_1828)))) == ((0x5E99 || l_1363) | g_210.f7))) , (*g_466))) , (void*)0);

                    ((l_1760 == 0) ? (void) (0) : __assert_fail ("l_1760 == 0", "t.c", 2803, __PRETTY_FUNCTION__));
                }
                if ((~((safe_add_func_int8_t_s_s((((*l_1644) < (g_784[3] , (*l_1644))) >= (g_210.f5 | l_1363)), (safe_rshift_func_uint16_t_u_s((safe_rshift_func_int8_t_s_u(((l_1768 == (void*)0) < ((*g_2221) == ((safe_rshift_func_int16_t_s_s((safe_lshift_func_int8_t_s_u(((safe_rshift_func_uint8_t_u_s(249U, l_2127)) | 0x53D3), 3)), l_1363)) != 4294967295U))), l_1363)), 4)))) | l_1363)))
                {
                    uint32_t l_1785 = 0x464AA3C8;
                    int32_t *l_1786 = &l_1167[6][2];
                    (*g_2221) = 0x15E7E107;

{
            int16_t l_1025[9] = {0x25BB,0x25BB,0x9403,0x25BB,0x25BB,0x9403,0x25BB,0x25BB,0x9403};
            int32_t *l_1028 = &l_1614;
            int32_t ***l_1036 = &(*g_296);
            int32_t l_1051[8] = {(-2),(-2),0x49B69B4F,(-2),(-2),0x49B69B4F,(-2),(-2)};
            struct S0 l_1146 = {455,1102,-24,303,249,0,-2001,173,0x96};
            int i;
            for ((*l_1786) = 3; ((*l_1786) >= 0); (*l_1786) -= 1)
            {
                struct S0 ***l_1017 = &g_465;
                int32_t l_1026 = 0xF68FD735;
                int32_t **l_1027 = &g_944[6][0][7];
                struct S0 l_1093 = {956,5097,355,1225,202,-1,-1964,61,0x03};
                (*l_1027) = &l_1026;


                (*l_1027) = l_1028;
                for (l_1009 = 0; (l_1009 <= 3); l_1009 += 1)
                {
                    uint32_t l_1039[9];
                    int32_t **l_1063 = &l_2437;
                    int i;
                    for (i = 0; i < 9; i++)
                        l_1039[i] = 0x85EF642C;
                    (*l_1921) = ((((((0xFC27 || (safe_sub_func_int8_t_s_s(((void*)0 != &l_1921), 0xC3))) <= (*l_1028)) || ((*l_1028) , 1U)) < g_1031[4]) >= (safe_div_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u(((&(*g_296) == l_1036) >= 0x4F), 0)) != 1U), 0x1254979A))) && (*l_1921));
                    if ((safe_mod_func_int16_t_s_s((l_1039[8] , (((safe_mod_func_int32_t_s_s(((+(((safe_mul_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(((l_1017 != &g_465) & l_1039[8]), 1)), (l_1363 == (safe_add_func_int8_t_s_s(((l_1039[4] <= (*l_1921)) != l_1009), ((safe_mul_func_int16_t_s_s((l_1051[5] <= l_1363), l_1363)) | 1)))))) && 0U) <= 65535U)) & 4294967295U), 1U)) | g_210.f1) || 0x6CF6)), 1U)))
                    {
                        (*l_1027) = &g_11[0];
                        (*l_1028) = 0xF85D6DC6;
                        if ((*l_1921))
                            continue;
                    }
                    else
                    {
                        if (l_1904)
                            break;
                    }
                    if (l_1039[8])
                        break;
                    if ((*l_1028))
                        break;
                    for (g_2619 = 0; (g_2619 <= 3); g_2619 += 1)
                    {
                        int32_t *l_1054[6][1] = {{&g_33[2]},{&g_11[0]},{&g_33[2]},{&g_11[0]},{&g_33[2]},{&g_11[0]}};
                        int i, j, k;
                        g_986[g_2619][g_2619][g_2619] = l_1054[2][0];
                        (*l_1027) = (((safe_add_func_uint16_t_u_u((safe_mul_func_uint16_t_u_u((safe_div_func_int32_t_s_s((safe_lshift_func_int8_t_s_u(0x32, 5)), (((l_1716 > l_1363) , 249U) && (l_1063 == l_1027)))), (((!(safe_rshift_func_int8_t_s_s(0, 2))) == ((((*p_51) != (void*)0) ^ 0xFA0732C2) && l_1363)) || l_1009))), g_210.f6)) , l_1363) , l_1921);
                    }
                }
                for (g_2619 = 3; (g_2619 >= 0); g_2619 -= 1)
                {
                    int8_t l_1072 = (-1);
                    uint32_t l_1076 = 1U;
                    int32_t *l_1083 = &g_33[2];
                    struct S0 l_1095 = {631,1691,-119,1361,102,1,-551,267,-4};

(*g_148) -= 1;


                    if ((safe_div_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(l_1072, 1)), l_1363)))
                    {
                        int32_t *l_1073 = (void*)0;
                        (*l_1027) = l_1073;
                        (*l_1027) = ((((+l_1363) || (g_1031[4] <= (~(l_1076 ^ (safe_mod_func_uint16_t_u_u(((!((((safe_div_func_int16_t_s_s(((&l_1624) != l_1083), (((((safe_unary_minus_func_int32_t_s(1)) || (((((safe_add_func_uint16_t_u_u((0xFC05510A | ((safe_sub_func_uint32_t_u_u(0x237EEA70, (safe_add_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_s((g_33[2] , (*l_1083)), l_1363)) > 0xA091E223), (*g_466).f3)))) , 1U)), 0xF723)) <= 7U) ^ (*l_1786)) , (*l_1083)) != 0x7BD9C737)) >= (*l_1921)) , (*(&l_1624))) || l_1363))) != g_210.f5) ^ (*l_1028)) , (*g_466).f1)) & g_210.f4), l_1363)))))) == l_1363) , (void*)0);
                    }
                    else
                    {
                        (*(*g_465)) = l_1093;
                        if (l_2108)
                            continue;
                    }
                    (*(*g_465)) = l_1095;
                    for (l_1095.f8 = 3; (l_1095.f8 >= 0); l_1095.f8 -= 1)
                    {
                        int i, j, k;
                        g_986[(g_2619 + 1)][(l_1095.f8 + 1)][(*l_1786)] = l_1096[0];
                        (*(*g_465)) = (((*p_51) != g_986[(g_2619 + 1)][(l_1095.f8 + 1)][(*l_1786)]) , ((l_1363 > ((safe_mul_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u((((7 != (((g_210.f1 , 0) , 5) != (g_11[0] < (safe_rshift_func_uint16_t_u_u(((0xAB && (-8)) & 0x4915), (*g_466).f2))))) , l_1363) & 247U), g_33[2])) ^ 1U), 250U)) > 1)) , (*g_466)));
                    }
                }
            }


            (*l_1921) = ((*g_466).f1 <= (safe_lshift_func_uint8_t_u_s(((safe_div_func_uint16_t_u_u((safe_div_func_int32_t_s_s((*(&l_1624)), (safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s((((void*)0 == (*g_465)) != (safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((2U >= g_784[1]), 2)), (((safe_add_func_int8_t_s_s(l_1363, ((((-1) | ((((void*)0 == &(*g_465)) >= g_210.f3) , l_1363)) && l_2108) || 247U))) <= l_1363) || l_2108)))), 1U)), g_210.f3)))), l_1363)) & 0xA376), 0)));
            for (g_210.f8 = 22; (g_210.f8 != (-14)); --g_210.f8)
            {
                int8_t l_1145 = 0;
                int32_t **l_1147[10] = {&g_32[0],&g_148,&g_32[0],&g_986[0][4][1],&g_986[0][4][1],&g_32[0],&g_148,&g_32[0],&g_986[0][4][1],&g_986[0][4][1]};
                int i;
                (*l_1028) = l_2350;
                l_1146 = (((safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(l_1363, (*l_1921))), (*g_466).f7)) == (safe_mul_func_int8_t_s_s((l_1129[3] | g_210.f3), (*l_1786)))) , (((safe_lshift_func_int16_t_s_u((l_1363 < (safe_mod_func_int32_t_s_s((safe_mod_func_int16_t_s_s((safe_mul_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s((((safe_div_func_uint16_t_u_u(((g_466 == g_466) < l_1363), (*g_466).f3)) < g_210.f2) , l_1145), 0x9282)), 2)), l_1145)), g_33[2])), 1))), 9)) >= l_1614) , (*g_466)));

{
                        uint32_t l_2493[3][6];
                        int i, j;
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 6; j++)
                                l_2493[i][j] = 1U;
                        }
                        (*(&l_1807)) = ((g_2619 & (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u(((((((safe_lshift_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((g_2619 , (safe_lshift_func_uint16_t_u_s(((safe_sub_func_int32_t_s_s((((((l_2493[0][4] && ((g_2619 <= (((safe_sub_func_int8_t_s_s(((safe_mul_func_int16_t_s_s(0x1FF6, ((l_2370.f7 > l_1217.f8) >= ((l_1828 == (void*)0) , (-1))))) , (*(*p_51))), g_1031[3])) , (*(&g_2956))) & 7)) > l_2370.f0)) , (**l_1831)) , l_2370.f8) && g_2619) , l_1650), 0x8ADDA95C)) , g_2805), 2))), l_1785)) | g_2805), g_2805)) ^ (*(&g_2956))) >= 0x4B) || l_1217.f0) == 0x09) , l_1217.f1), 5)), 6)), 0))) , (*(*p_51)));
                    }

                    g_944[3][0][7] = l_1096[0];
            }
        }

                    (*g_2221) = (safe_mod_func_int32_t_s_s(0x375D5BBD, ((&p_52 != (&p_52)) , (safe_rshift_func_uint16_t_u_u(((0x9E <= (((void*)0 == &l_1644) <= (safe_div_func_uint8_t_u_u((((safe_mod_func_uint16_t_u_u(g_210.f8, l_1785)) , l_1786) == (void*)0), l_1363)))) < l_2127), 8)))));
                    for ((*g_2221) = 1; ((*g_2221) <= 4); (*g_2221) += 1)
                    {
                        int i;
                        (*l_1608) = ((0U < g_1031[(*g_2221)]) , &g_33[(*g_2221)]);
                    }
                }
                else
                {
                    (**l_1768) = ((((1U >= 0x4C74) == (*(&k))) || (l_1363 <= ((safe_sub_func_int32_t_s_s(((((safe_sub_func_uint16_t_u_u(((l_1711 ^ l_1791) && (safe_rshift_func_uint8_t_u_s((0x6C4F ^ ((safe_rshift_func_uint16_t_u_s((safe_lshift_func_int16_t_s_s((safe_add_func_int32_t_s_s((((safe_mul_func_uint8_t_u_u((safe_div_func_uint16_t_u_u(((safe_mul_func_int16_t_s_s(((((g_1031[4] > 0U) == 1) & l_1806[3]) | (*l_1644)), 0U)) & g_210.f1), l_1363)), 0x72)) >= 0x0947D3B4) ^ 0xF37EABE7), l_1711)), 6)), 7)) , l_1363)), 1))), g_210.f7)) != 0xDB) != l_1363) | l_1807), (*l_1645))) & 0x0C))) , (*(*g_465)));

{
                        int i;
                        (**(&l_1412)) = (((~g_33[(*p_53).f8]) < (g_33[(*p_53).f8] >= (((g_33[(*p_53).f8] < (*l_1412)) , g_27.f1) & (+(*l_1412))))) && ((*p_53) , (((((safe_add_func_uint8_t_u_u((**(&l_1412)), (l_1082 == (*(*g_296))))) ^ (**(*g_296))) && l_2164) <= (*l_1082)) >= l_1904)));
                        (**(*g_296)) = (((safe_rshift_func_uint8_t_u_s(l_1181, 5)) , (*(*g_296))) != (((safe_div_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u((safe_mul_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(((((((((safe_rshift_func_uint8_t_u_s((l_1181 , 0x0F), (safe_mod_func_int32_t_s_s(((((*(*g_296)) != ((l_1181 != ((**(*g_296)) <= (((&p_51) != ((&g_33[(*p_53).f8] != l_2437) , (void*)0)) || 0))) , (void*)0)) <= 0x66BC) | (*l_2437)), g_33[(*p_53).f8])))) , (*(&l_1412))) == (void*)0) & l_1181) & g_27.f3) , &l_1608) == &(*g_296)) , 0x6F4C6E71), 0x5A340AF4)), g_1484)), (**(*g_296)))) , l_1904), (*l_2437))), g_33[(*p_53).f8])) > l_2370.f8) , l_1082));
                    }

                    (*l_1645) = (!((-1) || (safe_mul_func_uint16_t_u_u(l_1811, ((**l_2020) , l_1363)))));
                    for (l_1181 = 0; (l_1181 >= (-19)); --l_1181)
                    {
                        (**l_2020) = (*g_466);
                    }
                }
                if ((((g_210.f4 != (safe_mod_func_uint32_t_u_u((safe_sub_func_uint16_t_u_u((((safe_lshift_func_uint8_t_u_u((((safe_add_func_int16_t_s_s((((safe_mod_func_int32_t_s_s(((((safe_mod_func_uint32_t_u_u(((((safe_mul_func_int8_t_s_s(l_1791, ((&p_52 != &l_1608) , (0x51C4228E && 0x9390675F)))) <= ((((&l_2020 == ((((*g_2221) == j) , l_1791) , l_1828)) && g_1271[2][1]) , 8) || g_210.f1)) > l_1711) < (*l_1645)), l_1711)) == (*l_1644)) > l_1363) ^ (*(*p_52))), (-1))) , (-10)) < 4U), 1U)) ^ l_1363) != g_784[2]), (*g_2221))) , g_210.f0) , g_210.f6), g_11[0])), l_1363))) , g_1271[2][1]) , (*l_1645)))
                {
                    int32_t l_1835 = 0xBAE4E033;
                    int32_t l_1837 = 0;
                    (*l_1608) = l_1644;
                    (*(&k)) = (!l_1837);
                }
                else
                {
                    int32_t *l_1840 = &j;
                    for (l_1711 = 22; (l_1711 == (-3)); l_1711 = safe_sub_func_int32_t_s_s(l_1711, 1))
                    {
                        uint8_t l_1841 = 0xAC;
                        (*l_1608) = l_1840;
                        (**l_2020) = (*g_466);

l_1904 += 1;


                    (*l_1608) = &g_11[0];

g_2647 += 1;


                    g_2221 = (*p_52);

                        ((g_2221 == 0) ? (void) (0) : __assert_fail ("g_2221 == 0", "t.c", 2966, __PRETTY_FUNCTION__));
                    }

                    ((g_2221 == 0 || (g_2221 >= &g_33[0] && g_2221 <= &g_33[4])) ? (void) (0) : __assert_fail ("g_2221 == 0 || (g_2221 >= &g_33[0] && g_2221 <= &g_33[4])", "t.c", 2969, __PRETTY_FUNCTION__));
                    for (l_2122 = 23; (l_2122 >= 1); l_2122--)
                    {
                        int8_t l_1862 = 2;
                        (*l_1608) = (((*l_1840) & ((+((safe_unary_minus_func_uint32_t_u(((*(*p_52)) | ((((safe_div_func_int16_t_s_s((safe_div_func_uint8_t_u_u(((l_1862 >= ((safe_mul_func_int8_t_s_s(((*g_2221) , (((safe_mul_func_int8_t_s_s(((*l_1644) | ((safe_mul_func_int16_t_s_s((safe_lshift_func_int8_t_s_s((-2), ((l_1363 || (safe_rshift_func_int16_t_s_s(0x5560, 5))) | 1))), l_1862)) == l_1363)), 0x3C)) , 0U) < g_210.f6)), 0)) ^ g_210.f8)) , l_1363), 0x04)), 0xF8B9)) | g_210.f6) < 0xDE83) && 0U)))) , l_1753)) >= 0x8A4328FC)) , l_1644);
                        (**l_1768) = (((void*)0 == l_1873) , (((l_1828 == ((*(*p_52)) , &l_1768)) == l_1363) , (*g_466)));
                        (**l_2020) = ((*l_1644) , (**l_2020));
                        return (*l_1608);



                    }
                    l_1644 = &l_1753;

                    ((l_1644 == &l_1753) ? (void) (0) : __assert_fail ("l_1644 == &l_1753", "t.c", 2983, __PRETTY_FUNCTION__));
                }

                ((g_2221 == 0 || (g_2221 >= &g_33[0] && g_2221 <= &g_33[4])) ? (void) (0) : __assert_fail ("g_2221 == 0 || (g_2221 >= &g_33[0] && g_2221 <= &g_33[4])", "t.c", 2986, __PRETTY_FUNCTION__));
                ((l_1644 == &l_1753 || (l_1644 >= &g_11[0] && l_1644 <= &g_11[0])) ? (void) (0) : __assert_fail ("l_1644 == &l_1753 || (l_1644 >= &g_11[0] && l_1644 <= &g_11[0])", "t.c", 2987, __PRETTY_FUNCTION__));
            }

            ((g_2221 == 0 || (g_2221 >= &g_33[0] && g_2221 <= &g_33[4])) ? (void) (0) : __assert_fail ("g_2221 == 0 || (g_2221 >= &g_33[0] && g_2221 <= &g_33[4])", "t.c", 2990, __PRETTY_FUNCTION__));

            (*l_1608) = (*l_1608);

for (l_1855 = 0; (l_1855 > 12); l_1855++)
            {
                int32_t *l_2280 = &j;
                for (l_1597 = 0; (l_1597 <= 3); l_1597 += 1)
                {
                    int32_t l_2283 = 0xE2C51E0A;
                    if (((void*)0 == &(*g_296)))
                    {
                        int i;
                        if (l_1806[l_1597])
                            break;

{
                        int16_t l_847 = 0x83AA;
                        int32_t *l_848 = (void*)0;
                        (*(&l_2283)) = (safe_mul_func_uint8_t_u_u(0x03, (safe_div_func_int8_t_s_s((safe_mul_func_uint8_t_u_u(l_1650, (((safe_rshift_func_uint16_t_u_s((safe_add_func_uint16_t_u_u(l_1904, (safe_mod_func_int8_t_s_s(((8U ^ (safe_add_func_uint32_t_u_u(l_1650, (0xCA840E31 & 4294967293U)))) , ((*p_53).f8 && g_784[3])), l_847)))), 15)) == g_27.f2) & 0))), l_1650))));
                        return l_848;



                    }

                    if (g_784[l_1597])
                            break;
                        (**g_465) = (**g_465);
                    }
                    else
                    {
                        uint8_t l_2278[8] = {0x98,0U,0x98,0U,0x98,0U,0x98,0U};
                        int i;
                        (*(*p_51)) = l_2278[3];
                        p_50 = l_2280;

                        ((p_50 == &j) ? (void) (0) : __assert_fail ("p_50 == &j", "t.c", 3027, __PRETTY_FUNCTION__));
                    }
                    (*(*g_296)) = ((safe_add_func_int16_t_s_s((l_2283 & 0x8AA9DF5A), (((*(&l_2115)) , g_2351) >= ((((safe_mod_func_int32_t_s_s((safe_mul_func_uint16_t_u_u(0xA3A4, l_2283)), (safe_div_func_int32_t_s_s((((g_2805 , (**g_465)) , (*l_1508)) == (*l_1508)), g_2805)))) && 0x7B21) , g_2805) , 255U)))) , p_50);
                    (*(*g_296)) = l_2280;
                }
            };


                    if (((safe_lshift_func_int8_t_s_s(0xF2, 0)) > (safe_mod_func_uint32_t_u_u(g_210.f0, l_1363))))
            {
                uint32_t l_1901 = 0xCA91294B;
                (*l_1828) = l_2020;

                (((*l_1828) == &g_466) ? (void) (0) : __assert_fail ("(*l_1828) == &g_466", "t.c", 3040, __PRETTY_FUNCTION__));
                l_1901 = (((((*l_1828) == (void*)0) | (*l_1645)) , ((safe_unary_minus_func_int32_t_s((~(((g_1271[1][1] , 0x6E) != l_1363) ^ (safe_unary_minus_func_int32_t_s((*(*p_52)))))))) < ((l_1828 == (void*)0) & l_1807))) && g_210.f2);
                (*l_1608) = (((safe_lshift_func_int8_t_s_s(g_2619, (!(safe_mod_func_uint8_t_u_u((l_2020 != (void*)0), 1U))))) | ((0U >= ((-1) ^ ((*p_52) != (void*)0))) > (safe_add_func_uint16_t_u_u((safe_rshift_func_int8_t_s_u((safe_mul_func_int8_t_s_s((safe_mul_func_int16_t_s_s(8, l_1901)), g_210.f6)), 1)), 0x1BE4)))) , (*l_1608));
            }
            else
            {
                uint32_t l_1926 = 8U;
                uint32_t l_1936 = 8U;
                uint32_t l_1938 = 0x54CF833C;
                int32_t *l_1940 = &g_11[0];
                struct S0 ***l_1943[4][1][7] = {{{(void*)0,&(*l_1828),(void*)0,&l_2020,&(*l_1828),&l_2020,&(*l_1828)}},{{(void*)0,&l_2020,&l_2020,(void*)0,&l_2020,&l_2020,&(*l_1828)}},{{&(*l_1828),&l_2020,&l_2020,(void*)0,&l_2020,&l_2020,(void*)0}},{{&(*l_1828),&l_2020,&(*l_1828),&l_2020,&l_2020,&(*l_1828),&(*l_1828)}}};
                int32_t ***l_1952 = &l_1608;
                int i, j, k;
                (*(*p_52)) = (safe_mod_func_uint16_t_u_u(g_210.f0, (g_210.f2 , (safe_add_func_int32_t_s_s((*(*p_52)), ((!g_210.f8) <= 0))))));
                (*l_1608) = l_1921;



{
                        uint32_t l_2241 = 0U;
                        struct S0 l_2242 = {718,7833,20,468,426,1,-754,198,-1};
                        (**(*l_1828)) = (*(&l_2370));
                        if (g_2647)
                            break;
                        (**(*l_1828)) = (((l_2122 ^ 0) , l_2241) , l_2242);
                        (*l_2291) = (g_2805 , 0xA5E0E56F);
                    }

                    (*l_1608) = l_1940;

if ((safe_rshift_func_int8_t_s_s(l_1052, (safe_rshift_func_int16_t_s_u((((*(&l_1614)) && 0xBB07A94C) <= ((!((l_2105.f8 != (((((safe_mul_func_uint16_t_u_u(((&(*g_465) == (((void*)0 == (*g_465)) , l_1831)) || (((void*)0 != (&l_1831)) || l_1052)), 0x9F3C)) , l_2105.f3) >= l_1052) > l_1052) & l_1052)) < l_1597)) > l_1052)), 3)))))
                    {
                        (*(*l_1508)) = l_2034[1][8][1];
                    }
                    else
                    {
                        struct S0 **l_2035 = &(*g_465);
                        int32_t *l_2037 = (void*)0;
                        (*(*l_1508)) = (*l_1608);
                        (*(*l_1608)) = (&(*g_465) != l_2035);
                        l_2037 = (&g_1240);

                        (((l_2037 >= &g_33[0] && l_2037 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_2037 >= &g_33[0] && l_2037 <= &g_33[4])", "t.c", 3082, __PRETTY_FUNCTION__));
                    };


                    if ((safe_mul_func_int8_t_s_s((4294967295U < (&l_2020 == l_1943[1][0][4])), ((((safe_unary_minus_func_uint8_t_u(j)) , (g_1271[0][4] ^ ((((safe_lshift_func_int8_t_s_s(1, ((+((safe_rshift_func_uint16_t_u_s(((((((safe_add_func_uint32_t_u_u(l_1363, ((*l_1940) < (0xA6 >= g_210.f2)))) == l_1363) , (*(*p_52))) , 0xF8C4376E) ^ 0x6BBC687B) < (*l_1940)), g_210.f8)) >= l_1363)) , 1))) , 0x58) | 0x89) & 8U))) , &p_52) != l_1952))))
                {
                    int32_t *l_1953 = &l_1167[6][6];
                    uint32_t l_1954 = 3U;
                    struct S0 l_1987 = {587,4246,182,1176,256,0,1763,200,8};
                    l_1953 = &l_1937[3][0][1];

                    (((l_1953 >= &l_1937[0][0][0] && l_1953 <= &l_1937[5][1][8])) ? (void) (0) : __assert_fail ("(l_1953 >= &l_1937[0][0][0] && l_1953 <= &l_1937[5][1][8])", "t.c", 3093, __PRETTY_FUNCTION__));
                    (**l_1952) = &g_11[0];
                    (*g_466) = (((safe_sub_func_uint32_t_u_u((safe_sub_func_uint8_t_u_u((safe_mul_func_int32_t_s_s((safe_lshift_func_uint16_t_u_s(((((safe_mul_func_uint16_t_u_u((safe_rshift_func_int16_t_s_u((1U & (safe_add_func_uint8_t_u_u((((g_1094 == (~(safe_mod_func_uint16_t_u_u(((void*)0 == &(*p_52)), (-1))))) | ((*l_1953) == (*l_1645))) && (safe_div_func_uint32_t_u_u(0x608AA6BE, (-7)))), l_1363))), 14)), (*l_1940))) < 0xFA) == g_1031[4]) > g_33[1]), 9)), 0)), g_1271[2][1])), l_1986)) , 0x87B2CA8D) , l_1987);
                }
                else
                {
                    l_1988[0][2][5] = (*g_466);
                    (*(&k)) = (safe_sub_func_int8_t_s_s((~(g_210.f5 >= (l_1943[2][0][0] != (void*)0))), 1U));
                    for (g_2619 = (-5); (g_2619 < 0); g_2619 = safe_add_func_uint16_t_u_u(g_2619, 2))
                    {
                        (*l_1608) = &j;
                    }
                    return (*p_52);




                }
            }


            (((*l_1828) == 0 || (*l_1828) == &g_466) ? (void) (0) : __assert_fail ("(*l_1828) == 0 || (*l_1828) == &g_466", "t.c", 3114, __PRETTY_FUNCTION__));
            (*(*p_52)) = (*(*p_52));
        }
        else
        {
            struct S0 **l_2020 = &g_466;
            int32_t l_2030 = 0xDD04508F;
            uint8_t l_2061 = 255U;
            int32_t **l_2072[1];
            uint16_t l_2122 = 65535U;
            int i;
            for (i = 0; i < 1; i++)
                l_2072[i] = &g_986[4][2][3];

j -= 1;


                    for ((*l_2291) = (-27); ((*l_2291) != 13); (*l_2291)++)
            {
                int32_t l_2033 = 5;
                for ((*g_2221) = (-9); ((*g_2221) == 24); (*g_2221) = safe_add_func_uint8_t_u_u((*g_2221), 9))
                {
                    struct S0 l_2012 = {734,8056,385,947,467,1,241,129,7};
                    struct S0 ***l_2021 = &l_2020;
                    int32_t *l_2036 = &g_33[1];

{
                uint32_t l_663 = 0x8AA41A1D;
                int32_t l_664[7];
                struct S0 l_678 = {434,4928,306,294,0,0,-984,261,0};
                int i;
                for (i = 0; i < 7; i++)
                    l_664[i] = 0x017C58A9;
                for (l_1631 = 0; (l_1631 <= 0); l_1631 += 1)
                {
                    uint16_t l_673 = 2U;
                    struct S0 *l_674 = (void*)0;
                    for (l_1351 = 0; (l_1351 <= 0); l_1351 += 1)
                    {
                        int i;
                        (*p_52) = &g_11[l_1631];

                        (((l_2212 >= &g_11[0] && l_2212 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_2212 >= &g_11[0] && l_2212 <= &g_11[0])", "t.c", 3156, __PRETTY_FUNCTION__));
                    }
                    for (g_1094 = 0; (g_1094 <= 0); g_1094 += 1)
                    {
                        int i, j, k;
                        (*p_52) = (void*)0;

                        ((l_2212 == 0) ? (void) (0) : __assert_fail ("l_2212 == 0", "t.c", 3163, __PRETTY_FUNCTION__));
                        if (l_1631)
                            continue;
                        l_664[6] = (((safe_div_func_uint16_t_u_u(l_2012.f4, (safe_unary_minus_func_int8_t_s((l_2012.f0 || l_1986))))) <= l_663) && l_1631);
                        (*(&g_21)) = (l_2012.f8 ^ (safe_rshift_func_int16_t_s_s((((**(&l_2020)) != ((safe_unary_minus_func_int16_t_s(((safe_mod_func_int32_t_s_s((l_1986 , (((safe_add_func_int8_t_s_s(((l_664[5] & g_33[2]) && l_1631), (((((((4U > g_210.f2) < (p_54 & l_673)) , 0xB124) ^ l_1986) & l_2012.f7) || l_2012.f0) , l_2012.f4))) , l_673) < l_1631)), 1)) | g_210.f6))) , l_674)) <= l_664[6]), 7)));
                    }
                }
                for (l_663 = 22; (l_663 > 12); l_663 = safe_sub_func_uint32_t_u_u(l_663, 8))
                {
                    int32_t *l_677 = &g_11[0];
                    (**g_2770) = l_677;

                    (((l_2212 >= &g_11[0] && l_2212 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_2212 >= &g_11[0] && l_2212 <= &g_11[0])", "t.c", 3175, __PRETTY_FUNCTION__));
                }
                (***(&l_2020)) = l_678;
            }

                    (**l_2020) = l_2012;

if (l_1363)
                    {
                        uint8_t l_1730 = 0xB5;
                        int32_t ***l_1733[5][5][9] = {{{&g_297,&g_297,&g_297,&g_297,(void*)0,(void*)0,&g_297,&g_297,&g_297},{&g_297,&g_297,(void*)0,&g_297,&g_297,&g_297,(void*)0,&g_297,&g_297},{(void*)0,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,(void*)0},{&g_297,(void*)0,(void*)0,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297},{(void*)0,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,(void*)0}},{{(void*)0,&g_297,&g_297,&g_297,(void*)0,&g_297,&g_297,&g_297,(void*)0},{&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,(void*)0,&g_297,&g_297},{&g_297,&g_297,&g_297,&g_297,(void*)0,&g_297,&g_297,&g_297,(void*)0},{&g_297,(void*)0,&g_297,&g_297,(void*)0,&g_297,&g_297,&g_297,(void*)0},{&g_297,&g_297,(void*)0,(void*)0,&g_297,&g_297,(void*)0,&g_297,&g_297}},{{&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297},{&g_297,&g_297,(void*)0,&g_297,&g_297,(void*)0,&g_297,&g_297,(void*)0},{&g_297,&g_297,&g_297,&g_297,(void*)0,&g_297,&g_297,(void*)0,(void*)0},{&g_297,(void*)0,&g_297,&g_297,&g_297,(void*)0,&g_297,(void*)0,&g_297},{&g_297,(void*)0,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297}},{{&g_297,&g_297,(void*)0,&g_297,(void*)0,&g_297,&g_297,(void*)0,(void*)0},{&g_297,&g_297,&g_297,&g_297,(void*)0,&g_297,(void*)0,&g_297,(void*)0},{&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,(void*)0,&g_297,&g_297},{(void*)0,(void*)0,(void*)0,&g_297,(void*)0,&g_297,&g_297,(void*)0,&g_297},{&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297}},{{&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,&g_297},{&g_297,&g_297,&g_297,&g_297,(void*)0,&g_297,(void*)0,&g_297,&g_297},{&g_297,&g_297,&g_297,&g_297,&g_297,(void*)0,&g_297,(void*)0,&g_297},{&g_297,&g_297,(void*)0,&g_297,&g_297,&g_297,&g_297,&g_297,(void*)0},{&g_297,(void*)0,&g_297,(void*)0,&g_297,&g_297,&g_297,(void*)0,&g_297}}};
                        int i, j, k;
                        (*l_2036) = ((safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_s(g_1271[0][0], 5)), (0x7F ^ l_1363))) && (*(*g_297)));
                        (*(&l_1614)) = (safe_sub_func_uint32_t_u_u((safe_add_func_uint8_t_u_u((0x322C < (safe_lshift_func_int8_t_s_s((+(safe_rshift_func_uint8_t_u_s(l_1730, (safe_sub_func_uint8_t_u_u((&g_297 != l_1733[4][1][2]), g_210.f7))))), (((!0) && g_21) < (safe_mod_func_int32_t_s_s((*(&l_1614)), (*(*g_297)))))))), 0U)), l_2164));
                    }
                    else
                    {
                        (**l_1431) = (l_1363 , (*(&l_1217)));
                    };



for ((*p_53).f8 = 1; ((*p_53).f8 <= 7); (*p_53).f8 += 1)
        {
            uint16_t l_2912[10][5] = {{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U}};
            int32_t *l_2923 = (void*)0;
            int i, j;
        };


                    if ((safe_rshift_func_int8_t_s_s(l_1363, (safe_rshift_func_int16_t_s_u((((*l_1645) && 0xBB07A94C) <= ((!((g_210.f8 != (((((safe_mul_func_uint16_t_u_u(((&(*g_465) == (((void*)0 == (*g_465)) , l_2020)) || (((void*)0 != l_2021) || l_1363)), 0x9F3C)) , g_210.f3) >= l_1363) > l_1363) & l_1363)) < l_2122)) > l_1363)), 3)))))
                    {
                        (*l_1608) = l_2034[1][8][1];
                    }
                    else
                    {
                        struct S0 **l_2035 = &g_466;
                        int32_t *l_2037 = (void*)0;
                        (*l_1608) = (*p_52);
                        (*(*p_52)) = (&g_466 != l_2035);
                        l_2037 = l_2036;

                        (((l_2037 >= &g_33[0] && l_2037 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_2037 >= &g_33[0] && l_2037 <= &g_33[4])", "t.c", 3217, __PRETTY_FUNCTION__));
                    }
                    (*(*p_52)) = (safe_sub_func_uint16_t_u_u(l_2030, (g_1094 && ((*g_2221) <= (g_784[3] | ((safe_sub_func_uint8_t_u_u(l_2033, (((safe_div_func_uint32_t_u_u(((safe_mod_func_uint8_t_u_u(g_784[3], l_2030)) == (safe_div_func_int16_t_s_s((safe_lshift_func_int8_t_s_u(((((safe_add_func_uint32_t_u_u(0U, ((safe_sub_func_int8_t_s_s((((*g_466) , g_1271[2][1]) > l_1363), (*l_2036))) , l_2030))) , 0x52D8) && g_210.f3) || l_2033), 0)), g_2054[7][0][1]))), (*(*p_52)))) >= (*(*p_52))) ^ l_1363))) , l_1363))))));
                    for ((*(*p_52)) = 0; ((*(*p_52)) == 6); ++(*(*p_52)))
                    {
                        (*l_1608) = l_2036;
                        if ((*l_2036))
                            break;
                    }
                }
                if ((safe_div_func_int16_t_s_s(0x29FA, l_1363)))
                {
                    (*(*p_52)) = (safe_mul_func_uint8_t_u_u(0x33, (safe_add_func_uint16_t_u_u(((((*p_52) == (((safe_rshift_func_int8_t_s_u(((safe_rshift_func_int16_t_s_s(((l_2072[0] != &(*p_52)) > (safe_mod_func_int16_t_s_s(g_784[3], ((safe_sub_func_int16_t_s_s(5, l_1363)) , (safe_div_func_int8_t_s_s((safe_unary_minus_func_int8_t_s((safe_rshift_func_int16_t_s_u((safe_sub_func_int8_t_s_s(((l_1363 || l_2033) ^ l_2033), (*l_1645))), 6)))), 0xAB)))))), l_1363)) < l_2122), g_2054[7][0][1])) > 0U) , (void*)0)) && 0x9B) == l_2033), 0))));
                    (*l_1608) = (void*)0;
                }
                else
                {
                    int32_t *l_2084 = &l_2030;
                    return (*p_52);




                }
                (*(*p_52)) = 0xE8417F98;
            }



{
    int32_t *l_2742 = &g_33[2];
    int32_t **l_2743 = &g_986[0][5][1];
    struct S0 ***l_2771 = &g_2531[0][0];
    uint32_t l_2842[8] = {4294967288U,4294967288U,4294967288U,0x2C0253A1,0x2C0253A1,4294967288U,0x2C0253A1,0x2C0253A1};
    int i;

if (l_2323)
                break;

                    (*l_2743) = l_2742;

for (l_1811 = (-2); (l_1811 > (-21)); --l_1811)
                {
                    int8_t l_1279 = 0;
                    int8_t l_1329 = (-1);
                    int32_t ***l_1336 = (void*)0;
                    int8_t l_1348 = 1;
                    struct S0 l_1350 = {599,171,-440,1398,438,-1,-231,342,0};
                    (*(&g_297)) = &l_1082;

                    (((*g_2770) == &l_1082) ? (void) (0) : __assert_fail ("(*g_2770) == &l_1082", "t.c", 3267, __PRETTY_FUNCTION__));
                    if ((((safe_mod_func_uint8_t_u_u((((+((((g_210.f3 , ((((safe_div_func_uint32_t_u_u(l_1363, l_1279)) == ((void*)0 == (*(&(*g_2770))))) <= ((!((safe_rshift_func_int16_t_s_u(l_1363, 5)) == ((safe_lshift_func_uint16_t_u_u(((((safe_rshift_func_int16_t_s_s((safe_mul_func_int16_t_s_s((l_1279 & (((((**(&g_297)) == ((l_1363 >= l_1363) , (*(*g_2770)))) || 0x4474) < 0xF0E8F346) & g_11[0])), l_1279)), g_784[0])) < g_210.f5) , l_1279) , g_210.f4), l_1363)) && (***(&l_2743))))) , 0x66C85F8A)) , 0x993C)) != l_1279) , (*(*l_2771))) != (void*)0)) > l_1279) & 0x8FA0), 5U)) , g_1271[2][1]) < l_1279))
                    {
                        (*l_1082) = ((!(l_1452 && (safe_rshift_func_uint16_t_u_s(l_1363, (l_1363 != (safe_sub_func_int16_t_s_s((+((+(safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((((((&l_1082 == ((l_1363 > (safe_rshift_func_uint8_t_u_u(j, 2))) , &l_1082)) && (***(&g_297))) & ((((safe_sub_func_int8_t_s_s((((*l_1831) == (*l_1831)) & l_1363), l_1279)) || 1) , (*g_466).f7) <= l_1452)) | 0x7B86) == 0) == l_1363), 0x08)), l_1363)), (*g_466).f4))) != 0)), l_1306[4][2][4]))))))) , 0);
                    }
                    else
                    {
                        int16_t l_1344 = 1;
                        int32_t ***l_1347 = &(*g_2770);
                        (**(*g_2770)) = (+(((((((safe_rshift_func_uint16_t_u_s(((**(*g_2770)) && (*l_1082)), (safe_add_func_uint16_t_u_u(g_11[0], ((safe_lshift_func_int16_t_s_u((((void*)0 != &(*g_2770)) >= l_1363), (safe_div_func_int8_t_s_s((g_784[3] , ((l_1363 <= (safe_rshift_func_uint16_t_u_s(65529U, 2))) && (***(&l_2743)))), l_1363)))) && 0x4B36))))) < 255U) < l_1363) < g_33[2]) ^ l_2003) == 0) < 0x6094));
                        (**(&l_2743)) = (**(&l_2743));
                        (**(*g_2770)) = ((((((safe_mul_func_int16_t_s_s((((void*)0 == (*(*g_2770))) ^ (((*g_466).f7 , (***(&(*g_2770)))) ^ (safe_div_func_int16_t_s_s((((safe_rshift_func_int16_t_s_s((l_1336 != (((safe_add_func_uint8_t_u_u((*g_466).f0, (safe_sub_func_int8_t_s_s(l_1351, (safe_mod_func_int16_t_s_s((l_1344 | (safe_mod_func_uint32_t_u_u(((*l_1831) == (void*)0), l_1344))), (-8))))))) && 0x3B) , l_1347)), l_1363)) , 0xD8) < l_1363), g_1031[3])))), l_1348)) && (***l_1347)) < 0xD0DF30A5) ^ (*l_1850)) | (***(&(*g_2770)))) , l_2350);
                        l_1350 = (*(*l_1831));
                    }
                };


                    for (l_1811 = 0; (l_1811 <= 2); l_1811 += 1)
    {
        int32_t ***l_2774 = &l_1608;
        struct S0 l_2818 = {24,6738,-426,165,390,-0,1153,115,0xEA};
        struct S0 ***l_2865[3];
        int i;
        for (i = 0; i < 3; i++)
            l_2865[i] = &(*l_1828);
        g_32[l_1811] = g_32[l_1811];
        (*(*l_1608)) = ((safe_unary_minus_func_uint32_t_u((safe_unary_minus_func_int32_t_s(((+((((safe_mod_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(((((((safe_sub_func_uint8_t_u_u((l_1122 , l_2115.f5), ((0xE948A20E < (0x51576ED4 < (safe_rshift_func_uint8_t_u_u((((safe_div_func_int32_t_s_s(((l_1122 , (0 > ((safe_div_func_int8_t_s_s(((((safe_mul_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s((((((safe_lshift_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_s((&g_32[l_1811] == &g_32[l_1811]), 6)) != (0x3A76E62F < (*l_2742))) , 0x6C), l_1122)) , &l_2743) != g_2770) | l_1122) <= l_1122), 1)), (*p_53).f3)), l_1122)) | 0x23CC) != g_33[3]) | 0x0B28), l_1122)) , l_2115.f7))) && 0x38), l_1122)) && (*p_53).f6) | 1), (*l_2742))))) == l_1122))) , l_2115.f1) , 0x7D5F7640) || (-1)) , (void*)0) != l_2771))), 0xEA)) | (-7)) < 0x54EA) || (*l_2742))) , 3))))) | 65535U);
        for (l_1122 = (-12); (l_1122 == 60); l_1122 = safe_add_func_int32_t_s_s(l_1122, 6))
        {
            uint16_t l_2775 = 0xE2FA;
            int16_t l_2804 = 8;
            struct S0 **l_2817[2][8][4] = {{{&(*l_2020),&(*l_2020),&(*l_2020),&(*l_2020)},{&(*l_2020),&(*l_2020),(void*)0,&(*l_2020)},{&(*l_2020),&(*l_2020),&(*l_2020),(void*)0},{&(*l_2020),(void*)0,(void*)0,(void*)0},{&(*l_2020),&(*l_2020),&(*l_2020),&(*l_2020)},{(void*)0,&(*l_2020),&(*l_2020),(void*)0},{&(*l_2020),&(*l_2020),(void*)0,&(*l_2020)},{&(*l_2020),&(*l_2020),&(*l_2020),(void*)0}},{{(void*)0,&(*l_2020),&(*l_2020),&(*l_2020)},{&(*l_2020),&(*l_2020),(void*)0,(void*)0},{&(*l_2020),&(*l_2020),&(*l_2020),&(*l_2020)},{&(*l_2020),&(*l_2020),(void*)0,&(*l_2020)},{&(*l_2020),&(*l_2020),&(*l_2020),(void*)0},{&(*l_2020),&(*l_2020),(void*)0,&(*l_2020)},{&(*l_2020),&(*l_2020),&(*l_2020),&(*l_2020)},{&(*l_2020),&(*l_2020),(void*)0,(void*)0}}};
            int32_t l_2882 = (-4);
            int32_t *l_2884[4][4][8] = {{{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]},{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]},{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]},{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]}},{{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]},{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]},{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]},{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]}},{{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]},{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]},{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]},{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]}},{{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]},{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]},{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]},{&g_33[2],&l_2003,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_2003,&g_33[2]}}};
            int i, j, k;
        }

{
        int32_t ***l_2774 = &p_52;
        struct S0 l_2818 = {24,6738,-426,165,390,-0,1153,115,0xEA};
        struct S0 ***l_2865[3];
        int i;
        for (i = 0; i < 3; i++)
            l_2865[i] = &l_2020;
        g_32[g_2956] = g_32[g_2956];
        (*(&g_1240)) = ((safe_unary_minus_func_uint32_t_u((safe_unary_minus_func_int32_t_s(((+((((safe_mod_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(((((((safe_sub_func_uint8_t_u_u((g_1484 , l_2370.f5), ((0xE948A20E < (0x51576ED4 < (safe_rshift_func_uint8_t_u_u((((safe_div_func_int32_t_s_s(((g_1484 , (0 > ((safe_div_func_int8_t_s_s(((((safe_mul_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s((((((safe_lshift_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_s((&g_32[g_2956] == &g_32[g_2956]), 6)) != (0x3A76E62F < (*(&g_1240)))) , 0x6C), g_1484)) , &(*g_2770)) != g_296) | g_1484) <= g_1484), 1)), l_1217.f3)), g_1484)) | 0x23CC) != g_33[3]) | 0x0B28), g_1484)) , l_2370.f7))) && 0x38), g_1484)) && l_1217.f6) | 1), (*(&g_1240)))))) == g_1484))) , l_2370.f1) , 0x7D5F7640) || (-1)) , (void*)0) != (&g_465)))), 0xEA)) | (-7)) < 0x54EA) || (*(&g_1240)))) , 3))))) | 65535U);
        for (g_1484 = (-12); (g_1484 == 60); g_1484 = safe_add_func_int32_t_s_s(g_1484, 6))
        {
            uint16_t l_2775 = 0xE2FA;
            int16_t l_2804 = 8;
            struct S0 **l_2817[2][8][4] = {{{&g_466,&g_466,&g_466,&g_466},{&g_466,&g_466,(void*)0,&g_466},{&g_466,&g_466,&g_466,(void*)0},{&g_466,(void*)0,(void*)0,(void*)0},{&g_466,&g_466,&g_466,&g_466},{(void*)0,&g_466,&g_466,(void*)0},{&g_466,&g_466,(void*)0,&g_466},{&g_466,&g_466,&g_466,(void*)0}},{{(void*)0,&g_466,&g_466,&g_466},{&g_466,&g_466,(void*)0,(void*)0},{&g_466,&g_466,&g_466,&g_466},{&g_466,&g_466,(void*)0,&g_466},{&g_466,&g_466,&g_466,(void*)0},{&g_466,&g_466,(void*)0,&g_466},{&g_466,&g_466,&g_466,&g_466},{&g_466,&g_466,(void*)0,(void*)0}}};
            int32_t l_2882 = (-4);
            int32_t *l_2884[4][4][8] = {{{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]},{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]},{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]},{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]}},{{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]},{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]},{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]},{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]}},{{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]},{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]},{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]},{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]}},{{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]},{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]},{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]},{&g_33[2],&j,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&j,&g_33[2]}}};
            int i, j, k;
        }
        for (l_2818.f8 = 1; (l_2818.f8 <= 7); l_2818.f8 += 1)
        {
            uint16_t l_2912[10][5] = {{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U}};
            int32_t *l_2923 = (void*)0;
            int i, j;
        }
    }

                    for (l_2818.f8 = 1; (l_2818.f8 <= 7); l_2818.f8 += 1)
        {
            uint16_t l_2912[10][5] = {{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U}};
            int32_t *l_2923 = (void*)0;
            int i, j;
        }
    }
    (*l_2743) = (*l_2743);
    (*l_2743) = (*l_2743);
    return (*l_2743);


}

                    (*g_2221) = (+(safe_div_func_uint32_t_u_u(((((((void*)0 == &p_52) <= (((safe_add_func_uint8_t_u_u((0x69B9 < (&l_2020 == &l_2020)), l_1363)) , (safe_mod_func_uint8_t_u_u((l_2094[0] && (safe_add_func_int8_t_s_s(((safe_sub_func_int16_t_s_s(g_210.f0, (safe_mul_func_int8_t_s_s(((safe_sub_func_uint8_t_u_u((((2 == l_2127) < 0xF3) , g_210.f5), l_1363)) && l_1363), 0)))) < 1), 0U))), 0x48))) ^ (*l_2291))) || (-5)) | j) >= g_1271[2][1]), 0x08BF5774)));

{
                    int32_t l_1835 = 0xBAE4E033;
                    int32_t l_1837 = 0;
                    (*(*g_2770)) = l_1412;

if ((safe_div_func_int16_t_s_s(0x29FA, l_1052)))
                {
                    (*g_148) = (safe_mul_func_uint8_t_u_u(0x33, (safe_add_func_uint16_t_u_u((((g_148 == (((safe_rshift_func_int8_t_s_u(((safe_rshift_func_int16_t_s_s(((l_2072[0] != &g_148) > (safe_mod_func_int16_t_s_s(g_784[3], ((safe_sub_func_int16_t_s_s(5, l_1052)) , (safe_div_func_int8_t_s_s((safe_unary_minus_func_int8_t_s((safe_rshift_func_int16_t_s_u((safe_sub_func_int8_t_s_s(((l_1052 || (*g_148)) ^ (*g_148)), (*l_1412))), 6)))), 0xAB)))))), l_1052)) < g_1484), g_2054[7][0][1])) > 0U) , (void*)0)) && 0x9B) == (*g_148)), 0))));
                    (*(*g_296)) = (void*)0;
                }
                else
                {
                    int32_t *l_2084 = &(*l_1412);
                    return g_148;




                };


                    (*l_2437) = (!l_1837);
                }

                    for ((*g_2221) = 25; ((*g_2221) == (-2)); (*g_2221)--)
            {
                uint32_t l_2108 = 0xA059FF2B;
                struct S0 l_2115 = {76,4931,263,428,393,1,-1125,326,-1};
                (**l_2020) = (*g_466);
                if ((safe_sub_func_int16_t_s_s(l_2108, ((safe_div_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(((((g_11[0] == ((safe_mod_func_int8_t_s_s((((((((((l_2115 , (safe_div_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u(((((safe_sub_func_int16_t_s_s((l_1363 >= ((&p_52 != ((*g_2221) , (void*)0)) | l_2122)), (safe_lshift_func_uint8_t_u_s((((safe_sub_func_int8_t_s_s(((l_1363 , (*l_2020)) == (*g_465)), (*(&k)))) <= l_2115.f3) < l_1363), 5)))) && l_1363) < 0) , l_2127), 7)), l_2115.f8))) & 1) >= l_1363) | g_1271[2][1]) != (*l_2291)) < 0xBB) | 255U) != g_210.f7) , (-1)), 247U)) >= g_1031[2])) , 5U) | 0xD112) | (*(*p_52))), 4)) != (*(*p_52))), l_2115.f5)) && 0x009A5A65))))
                {
                    for (l_2122 = (-17); (l_2122 == 60); l_2122 = safe_add_func_uint8_t_u_u(l_2122, 6))
                    {
                        int32_t *l_2133 = &g_11[0];
                        uint16_t l_2139 = 0x3C07;
                        (*(*p_52)) = ((safe_lshift_func_uint16_t_u_s(((((g_2054[7][0][0] , ((safe_unary_minus_func_int8_t_s((l_2133 != &j))) | ((*l_2133) || ((((safe_add_func_uint8_t_u_u(l_1363, (g_210.f4 >= ((+(safe_div_func_int8_t_s_s(((((0xDA && ((&(*p_52) != (*(&l_1608))) , l_2139)) == 0x8C50) && l_1363) , (-1)), g_1271[1][1]))) && (*l_2133))))) || g_210.f5) , g_210.f7) , l_2122)))) , (-1)) ^ 0x68) & (*l_2133)), g_210.f1)) | 0U);
                        (*l_1608) = (((safe_mul_func_int16_t_s_s((safe_sub_func_int32_t_s_s((l_1363 , l_2115.f2), (safe_mul_func_uint16_t_u_u((l_2146[3] , 65526U), ((safe_lshift_func_uint8_t_u_s((0x2E & (*l_2133)), 2)) , g_210.f5))))), (g_1271[2][1] | 0xD006))) < l_2127) , l_2133);
                        (**l_2020) = (*g_466);
                    }
                }
                else
                {
                    if (((((0xE670 < l_1363) & (l_1363 && (l_1363 <= ((safe_add_func_uint8_t_u_u((((((safe_mod_func_int16_t_s_s(g_210.f5, (0U | ((safe_add_func_uint32_t_u_u((((safe_add_func_int32_t_s_s((!((2 || ((safe_rshift_func_uint8_t_u_u((safe_sub_func_int8_t_s_s(l_1363, (safe_sub_func_int32_t_s_s((((4294967295U && l_2115.f6) , g_784[3]) != l_1363), 0xC71B2F44)))), l_1363)) | 4)) , g_210.f3)), (*(*p_52)))) >= l_2122) | l_1363), l_2164)) ^ l_1363)))) == 0x31188911) , (*(*p_52))) > l_2115.f8) || l_1363), l_2122)) , 0xEC623E69)))) | 0xB2DD) , 0xCB6594A1))
                    {
                        uint32_t l_2165 = 0x9E97B283;
                        (*(*p_52)) = (*(*p_52));
                        if (l_2165)
                            continue;
                    }
                    else
                    {

{
        transparent_crc(g_33[l_1855], "g_33[l_1855]", i);
        if (i) printf("index = [%d]\n", l_1855);

    }

                    return (*p_52);




                    }
                }
            }
        }


        ((g_2221 == 0 || (g_2221 >= &g_33[0] && g_2221 <= &g_33[4])) ? (void) (0) : __assert_fail ("g_2221 == 0 || (g_2221 >= &g_33[0] && g_2221 <= &g_33[4])", "t.c", 3415, __PRETTY_FUNCTION__));
        (((*l_1828) == 0 || (*l_1828) == &g_466) ? (void) (0) : __assert_fail ("(*l_1828) == 0 || (*l_1828) == &g_466", "t.c", 3416, __PRETTY_FUNCTION__));

if (l_2323)
                        break;

                    if ((((0x105C1531 >= ((((safe_unary_minus_func_int8_t_s((g_210.f4 >= (safe_mul_func_uint16_t_u_u(l_2169[5][4][0], g_210.f4))))) && ((((g_1271[1][2] , (safe_sub_func_uint8_t_u_u((0U <= (*l_1645)), (((safe_lshift_func_uint16_t_u_s((((safe_mul_func_uint8_t_u_u(l_1363, (&(*p_52) == (void*)0))) & l_1363) >= 0xE3EF), 4)) != l_1363) > (*(&k)))))) , (*l_1645)) || 8) ^ l_1363)) & g_210.f0) != l_2176[0])) == l_1363) || g_1271[0][3]))
        {
            int8_t l_2206 = 0x56;
            int32_t *l_2218[2][4] = {{&g_11[0],&g_33[2],&g_11[0],&g_11[0]},{&g_33[2],&g_33[2],&l_1167[2][4],&g_33[2]}};
            int8_t l_2237 = 8;
            struct S0 l_2275 = {744,5810,31,1053,134,-0,1051,335,0x6F};
            int i, j;
            for ((*g_2221) = 8; ((*g_2221) < 12); (*g_2221) = safe_add_func_uint32_t_u_u((*g_2221), 4))
            {
                uint32_t l_2179 = 0U;
                int32_t *l_2211 = &g_11[0];
                if ((l_2179 || l_1363))
                {
                    int8_t l_2198 = 8;
                    for (g_210.f8 = 15; (g_210.f8 == (-8)); g_210.f8 = safe_sub_func_uint32_t_u_u(g_210.f8, 2))
                    {
                        int32_t l_2197 = 0xCAD7CAE7;
                        (*(*p_52)) = (*(*p_52));
                        (*(*p_52)) = (7 & ((safe_div_func_int16_t_s_s((((l_1363 == l_1363) > (0x12B8 <= 0x6CA9)) <= (((safe_div_func_uint8_t_u_u(((safe_mul_func_int8_t_s_s((((((safe_lshift_func_uint16_t_u_u((safe_div_func_int16_t_s_s((-3), 2U)), (((!l_2179) == ((((safe_mul_func_int8_t_s_s((safe_mul_func_int8_t_s_s((l_1363 || l_2179), l_1363)), l_2197)) | 65531U) > (-3)) | l_2198)) | g_33[0]))) & 0x44) & l_1363) != l_1363) && 0xC4906F4E), 0xC7)) & j), l_1363)) <= l_1363) , l_1363)), 0x1AA4)) || 4U));
                        (*l_1608) = &l_2197;


                    }
                    for (l_1986 = (-24); (l_1986 < 5); l_1986++)
                    {
                        (*g_466) = ((*(*g_465)) , (((((((safe_div_func_int8_t_s_s((-1), ((g_210.f5 | l_1363) || (safe_lshift_func_int16_t_s_u((safe_unary_minus_func_int8_t_s(((l_2206 , (l_2179 , ((safe_mod_func_int32_t_s_s(((((0x32A1 || (g_1031[0] >= (safe_div_func_uint8_t_u_u((g_210.f3 | (-10)), 252U)))) && l_2198) , l_2179) <= 0U), 0xCF49745F)) >= g_11[0]))) <= 7))), 3))))) >= l_2179) == l_2179) < l_1363) < (*(*p_52))) >= 0U) , (*(*g_465))));
                        g_2221 = l_2211;

                        (((g_2221 >= &g_11[0] && g_2221 <= &g_11[0])) ? (void) (0) : __assert_fail ("(g_2221 >= &g_11[0] && g_2221 <= &g_11[0])", "t.c", 3449, __PRETTY_FUNCTION__));
                    }
                }
                else
                {
                    int32_t l_2215 = (-9);
                    for (g_1094 = (-17); (g_1094 < 49); g_1094 = safe_add_func_uint8_t_u_u(g_1094, 6))
                    {
                        int8_t l_2217 = 2;
                        if (l_2215)
                            break;
                        l_2217 = (~0U);
                    }
                    (*l_1828) = &(*g_465);

                    (((*l_1828) == &(*g_465)) ? (void) (0) : __assert_fail ("(*l_1828) == &(*g_465)", "t.c", 3464, __PRETTY_FUNCTION__));
                    l_2218[0][1] = (void*)0;
                }
            }


            (((*l_1828) == &(*g_465) || (*l_1828) == 0 || (*l_1828) == &g_466) ? (void) (0) : __assert_fail ("(*l_1828) == &(*g_465) || (*l_1828) == 0 || (*l_1828) == &g_466", "t.c", 3470, __PRETTY_FUNCTION__));
            (((g_2221 >= &g_11[0] && g_2221 <= &g_11[0]) || g_2221 == 0) ? (void) (0) : __assert_fail ("(g_2221 >= &g_11[0] && g_2221 <= &g_11[0]) || g_2221 == 0", "t.c", 3471, __PRETTY_FUNCTION__));

            (**l_2020) = (*(*g_465));

{
                int16_t l_1662[9] = {0x60FB,0x60FB,0x60FB,0x60FB,0x60FB,0x60FB,0x60FB,0x60FB,0x60FB};
                uint16_t l_1663 = 0x2A05;
                int32_t **l_1676 = (void*)0;
                int i;
                (*(&l_1735)) = (safe_rshift_func_int16_t_s_u((!((k , ((safe_mod_func_int8_t_s_s(((l_1631 != (p_54 , (0xF8 >= 0x19))) > (safe_mod_func_uint16_t_u_u(p_54, (safe_sub_func_int32_t_s_s(((safe_sub_func_uint16_t_u_u(g_1271[2][1], ((safe_add_func_uint16_t_u_u((safe_sub_func_uint8_t_u_u(g_2619, (safe_rshift_func_uint8_t_u_u(((((&(*p_52) == (void*)0) && 9) , (&l_1735)) != (&l_1735)), 5)))), l_2105.f7)) >= (-1)))) | (*(&l_1735))), 0x2153F809))))), 0x42)) , 9)) > (*(&l_1735)))), 3));
                (*(*p_52)) = (safe_add_func_int32_t_s_s((*(&l_1735)), (safe_sub_func_int32_t_s_s(((((*(&l_1735)) == l_2237) , g_1031[4]) | ((-9) == p_54)), (safe_rshift_func_int8_t_s_s(((*(&l_1735)) <= (safe_unary_minus_func_int16_t_s(((((safe_mul_func_uint16_t_u_u(p_54, ((safe_rshift_func_uint16_t_u_s(((((safe_lshift_func_uint8_t_u_s((safe_sub_func_int16_t_s_s((4U <= p_54), l_1662[3])), (*(&l_1735)))) > (*(&l_1735))) > p_54) || p_54), (*(&l_1735)))) , l_2105.f0))) >= l_1217.f7) >= 0x75F9A0D7) | l_1663)))), p_54))))));
                if ((0xE37E | (((((safe_lshift_func_uint16_t_u_u((safe_div_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(((((&(*l_1893)) != (void*)0) , (((((((((safe_rshift_func_int16_t_s_u(((0x02 || (k || (safe_mod_func_uint8_t_u_u((safe_div_func_uint32_t_u_u((0x47BAC912 && (((void*)0 == &(*g_465)) , 1)), (*(&l_1735)))), p_54)))) && 0xF4), l_2105.f6)) , &g_11[0]) == (void*)0) || (*(&l_1735))) , (void*)0) == l_1676) , (*l_1831)) == (*l_1831)) > 0x3DE1)) , p_54), 1)), l_2105.f0)), p_54)) != 0xF3C0) < p_54) , (-1)) | g_784[1])))
                {
                    for (i = 4; (i >= 0); i -= 1)
                    {
                        return (*(*l_1893));



                    }
                }
                else
                {
                    uint32_t l_1686 = 4294967293U;
                    for (g_2619 = (-5); (g_2619 != (-23)); g_2619 = safe_sub_func_uint32_t_u_u(g_2619, 7))
                    {
                        (*g_148) = (*(*p_52));
                        (*(&k)) = ((1 || ((((safe_rshift_func_uint8_t_u_u(((~(safe_rshift_func_int16_t_s_s((safe_mod_func_int8_t_s_s(l_2105.f1, (*l_2212))), 0))) ^ l_1686), 2)) , (l_1217.f6 , l_1217.f7)) | ((safe_lshift_func_uint8_t_u_u((safe_mod_func_int8_t_s_s(l_2105.f0, (safe_div_func_uint16_t_u_u((safe_unary_minus_func_int32_t_s((+(g_11[0] , (((void*)0 == &(*g_465)) || (*(*p_52))))))), 0xE6B3)))), 0)) != l_1686)) && p_54)) || (-4));
                    }
                }
            }

                    for ((*g_2221) = (-3); ((*g_2221) != (-21)); (*g_2221) = safe_sub_func_uint16_t_u_u((*g_2221), 1))
            {
                uint32_t l_2238 = 4294967295U;
                int32_t l_2257 = 0xEE87F0FB;
                struct S0 ***l_2274 = &l_2020;

{
                transparent_crc(g_2054[(*l_1645)][l_2030][i], "g_2054[(*l_1645)][l_2030][i]", g_80);
                if (g_80) {
for ((*p_50) = 0; (*p_50) < 4; (*p_50)++)
            l_1806[(*p_50)] = 0x2AE3;

                    printf("index = [%d][%d][%d]\n", (*l_1645), l_2030, i);}

            }

                    (*l_1608) = (&(*(*p_52)));
                for ((*l_2291) = 5; ((*l_2291) != (-4)); --(*l_2291))
                {
                    uint16_t l_2236 = 0x7F4B;
                    if ((((safe_mul_func_int16_t_s_s(((safe_mul_func_int8_t_s_s((((((safe_rshift_func_uint16_t_u_s((((*(&l_1608)) == (*(&l_1608))) < (safe_mod_func_uint8_t_u_u(0xB1, l_1363))), l_1363)) != ((safe_mod_func_int16_t_s_s(((((l_2122 , (*(*g_465))) , l_1363) != ((safe_mul_func_int8_t_s_s(l_2236, g_210.f4)) , l_1363)) != 1U), l_1363)) , g_210.f1)) & l_2237) <= (-2)) || 1U), 9U)) < l_1363), g_210.f6)) & l_1363) , l_2236))
                    {
                        uint32_t l_2241 = 0U;
                        struct S0 l_2242 = {718,7833,20,468,426,1,-754,198,-1};
                        (**l_2020) = (*(*g_465));
                        if (l_2238)
                            break;
                        (**l_2020) = (((l_2122 ^ 0) , l_2241) , l_2242);
                        (*(&k)) = (l_1363 , 0xA5E0E56F);
                    }
                    else
                    {
                        uint32_t l_2243 = 0x1478837A;
                        l_2243 = 0x168497EF;
                    }
                    if ((*(*p_52)))
                        {
if ((((safe_mod_func_uint8_t_u_u((((+((((g_210.f3 , ((((safe_div_func_uint32_t_u_u(l_991, l_2237)) == ((void*)0 == (*(&p_51)))) <= ((!((safe_rshift_func_int16_t_s_u(l_991, 5)) == ((safe_lshift_func_uint16_t_u_u(((((safe_rshift_func_int16_t_s_s((safe_mul_func_int16_t_s_s((l_2237 & (((((**(&g_297)) == ((l_991 >= l_991) , (*g_297))) || 0x4474) < 0xF0E8F346) & g_11[0])), l_2237)), g_784[0])) < g_210.f5) , l_2237) , g_210.f4), l_991)) && (***l_1508)))) , 0x66C85F8A)) , 0x993C)) != l_2237) , (*(&g_466))) != (void*)0)) > l_2237) & 0x8FA0), 5U)) , g_1271[2][1]) < l_2237))
                    {
                        (*(*p_52)) = ((!(l_2323 && (safe_rshift_func_uint16_t_u_s(l_991, (l_991 != (safe_sub_func_int16_t_s_s((+((+(safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((((((&(*p_52) == ((l_991 > (safe_rshift_func_uint8_t_u_u(l_2030, 2))) , &(*p_52))) && (***(&g_297))) & ((((safe_sub_func_int8_t_s_s((((*l_1831) == (*l_1831)) & l_991), l_2237)) || 1) , l_2115.f7) <= l_2323)) | 0x7B86) == 0) == l_991), 0x08)), l_991)), l_2115.f4))) != 0)), l_1306[4][2][4]))))))) , 0);
                    }
                    else
                    {
                        int16_t l_1344 = 1;
                        int32_t ***l_1347 = &g_297;
                        (**g_297) = (+(((((((safe_rshift_func_uint16_t_u_s(((**g_297) && (*(*p_52))), (safe_add_func_uint16_t_u_u(g_11[0], ((safe_lshift_func_int16_t_s_u((((void*)0 != &g_297) >= l_991), (safe_div_func_int8_t_s_s((g_784[3] , ((l_991 <= (safe_rshift_func_uint16_t_u_s(65529U, 2))) && (***l_1508))), l_991)))) && 0x4B36))))) < 255U) < l_991) < g_33[2]) ^ (*l_1082)) == 0) < 0x6094));
                        (**l_1508) = (**l_1508);
                        (**g_297) = ((((((safe_mul_func_int16_t_s_s((((void*)0 == (*g_297)) ^ ((l_2115.f7 , (***(&p_51))) ^ (safe_div_func_int16_t_s_s((((safe_rshift_func_int16_t_s_s(((&p_52) != (((safe_add_func_uint8_t_u_u(l_2115.f0, (safe_sub_func_int8_t_s_s(l_1986, (safe_mod_func_int16_t_s_s((l_1344 | (safe_mod_func_uint32_t_u_u(((*l_1831) == (void*)0), l_1344))), (-8))))))) && 0x3B) , l_1347)), l_991)) , 0xD8) < l_991), g_1031[3])))), l_1631)) && (***l_1347)) < 0xD0DF30A5) ^ (*g_2221)) | (***(&p_51))) , l_1122);
                        l_2370 = (*(*l_1831));
                    };


                    continue;}

{
                int16_t l_1184 = 0x7143;
                uint16_t l_1199 = 0x6469;
                int32_t **l_1200 = &g_32[1];
                (*l_1200) = (&l_1614);
            }

                    if ((*(*p_52)))
                        break;
                    for (g_210.f8 = 17; (g_210.f8 >= (-22)); g_210.f8 = safe_sub_func_int32_t_s_s(g_210.f8, 7))
                    {
                        (*(&(*(*p_52)))) = (((safe_rshift_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_u(((safe_unary_minus_func_int8_t_s(((g_2054[7][0][1] , (!(*(&(*(*p_52)))))) < (safe_sub_func_uint8_t_u_u(g_210.f4, 0xD7))))) | (l_2236 & (-8))), g_210.f1)) && (safe_sub_func_uint32_t_u_u(((g_210.f5 > (~l_2236)) , l_1363), l_1363))), g_2054[7][0][1])) == l_2257) < l_1363);
                        (*l_1645) = ((safe_mod_func_uint32_t_u_u(((((safe_mul_func_int16_t_s_s(l_1363, (((l_1363 | (safe_add_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_u((-9), g_210.f4)) , ((safe_sub_func_uint8_t_u_u((((*l_1645) || (safe_rshift_func_uint8_t_u_s((g_33[2] & (l_1363 != (0x9C > (((l_2238 == l_1363) != (*l_2291)) , l_1363)))), l_1363))) != l_1363), l_1363)) && (*(*p_52)))), l_2236))) , (void*)0) != l_2274))) <= 0) & l_1363) & l_1363), 0x51332F8E)) ^ g_210.f5);
                        l_2275 = (*(*g_465));
                    }
                }
                (*(&(*(*p_52)))) = (l_2257 ^ (&g_33[2] == ((*g_466) , &g_33[4])));
            }
            (*l_1645) = 0x04A65864;
        }
        else
        {
            uint32_t l_2279 = 0xB32EDEE1;
            int32_t *l_2290 = &l_1167[8][1];
            for ((*g_2221) = 0; ((*g_2221) > 12); (*g_2221)++)
            {
                int32_t *l_2280 = &l_1811;

for (g_210.f8 = 22; (g_210.f8 != (-14)); --g_210.f8)
            {
                int8_t l_1145 = 0;
                int32_t **l_1147[10] = {&g_32[0],&l_2290,&g_32[0],&g_986[0][4][1],&g_986[0][4][1],&g_32[0],&l_2290,&g_32[0],&g_986[0][4][1],&g_986[0][4][1]};
                int i;
                (*(&g_2803)) = l_1009;

if (((void*)0 == &(*g_296)))
                    {
                        int i;
                        if (l_1806[l_2350])
                            break;
                        if (g_784[l_2350])
                            break;
                        (**(*l_1828)) = (**(*l_1828));
                    }
                    else
                    {
                        uint8_t l_2278[8] = {0x98,0U,0x98,0U,0x98,0U,0x98,0U};
                        int i;
                        (*(&l_1735)) = l_2278[3];
                        l_2437 = l_1082;

                        ((l_2437 == &(*l_1850)) ? (void) (0) : __assert_fail ("l_2437 == &(*l_1850)", "t.c", 3608, __PRETTY_FUNCTION__));
                    };


                    (*g_466) = (((safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(l_2061, (*l_2290))), l_2115.f7)) == (safe_mul_func_int8_t_s_s((l_1129[3] | g_210.f3), (*l_2290)))) , (((safe_lshift_func_int16_t_s_u((l_2061 < (safe_mod_func_int32_t_s_s((safe_mod_func_int16_t_s_s((safe_mul_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s((((safe_div_func_uint16_t_u_u((((*l_1431) == (*l_1431)) < l_2061), l_2115.f3)) < g_210.f2) , l_1145), 0x9282)), 2)), l_1145)), g_33[2])), 1))), 9)) >= (*l_2437)) , (*(*l_1431))));
                g_944[3][0][7] = l_1096[0];
            };


                    for (l_1597 = 0; (l_1597 <= 3); l_1597 += 1)
                {
                    int32_t l_2283 = 0xE2C51E0A;

if (((!(l_2061 <= (safe_div_func_uint32_t_u_u((safe_unary_minus_func_int16_t_s(l_2370.f1)), 0x71FB2D1A)))) > (l_2061 , g_2619)))
    {
        int32_t *l_1024 = (void*)0;
        int16_t l_1053 = 0;
        int32_t *l_1067 = &g_11[0];
        uint32_t l_1119 = 4294967295U;
        struct S0 *l_1144 = &g_210;
        if (l_2061)
        {
            int16_t l_1025[9] = {0x25BB,0x25BB,0x9403,0x25BB,0x25BB,0x9403,0x25BB,0x25BB,0x9403};
            int32_t *l_1028 = &(*l_2437);
            int32_t ***l_1036 = &(*g_2770);
            int32_t l_1051[8] = {(-2),(-2),0x49B69B4F,(-2),(-2),0x49B69B4F,(-2),(-2)};
            struct S0 l_1146 = {455,1102,-24,303,249,0,-2001,173,0x96};
            int i;
            for (l_1706 = 3; (l_1706 >= 0); l_1706 -= 1)
            {
                struct S0 ***l_1017 = &l_2020;
                int32_t l_1026 = 0xF68FD735;
                int32_t **l_1027 = &g_944[6][0][7];
                struct S0 l_1093 = {956,5097,355,1225,202,-1,-1964,61,0x03};
                (*l_1027) = &l_1026;


                (*l_1027) = l_1028;
                for (l_1009 = 0; (l_1009 <= 3); l_1009 += 1)
                {
                    uint32_t l_1039[9];
                    int32_t **l_1063 = &l_1024;
                    int i;
                    for (i = 0; i < 9; i++)
                        l_1039[i] = 0x85EF642C;
                    (*p_50) = ((((((0xFC27 || (safe_sub_func_int8_t_s_s(((void*)0 != &p_50), 0xC3))) <= (*l_1028)) || ((*l_1028) , 1U)) < g_1031[4]) >= (safe_div_func_int32_t_s_s(((safe_lshift_func_int8_t_s_u(((&(*g_2770) == l_1036) >= 0x4F), 0)) != 1U), 0x1254979A))) && (*p_50));
                    if ((safe_mod_func_int16_t_s_s((l_1039[8] , (((safe_mod_func_int32_t_s_s(((+(((safe_mul_func_uint16_t_u_u((safe_rshift_func_uint8_t_u_s(((l_1017 != &l_2020) & l_1039[8]), 1)), (l_991 == (safe_add_func_int8_t_s_s(((l_1039[4] <= (*p_50)) != l_1009), ((safe_mul_func_int16_t_s_s((l_1051[5] <= l_2061), l_991)) | 1)))))) && 0U) <= 65535U)) & 4294967295U), 1U)) | g_210.f1) || 0x6CF6)), 1U)))
                    {
                        (*l_1027) = &g_11[0];
                        (*l_1028) = 0xF85D6DC6;
                        if ((*p_50))
                            continue;
                    }
                    else
                    {

if (l_1614) printf("index = [%d][%d][%d]\n", (*l_1850), g_2803, (*l_1412));

                    if (l_1053)
                            break;
                    }
                    if (l_1039[8])
                        break;
                    if ((*l_1028))
                        break;
                    for (g_2619 = 0; (g_2619 <= 3); g_2619 += 1)
                    {
                        int32_t *l_1054[6][1] = {{&g_33[2]},{&g_11[0]},{&g_33[2]},{&g_11[0]},{&g_33[2]},{&g_11[0]}};
                        int i, j, k;
                        g_986[g_2619][g_2619][g_2619] = l_1054[2][0];
                        (*l_1027) = (((safe_add_func_uint16_t_u_u((safe_mul_func_uint16_t_u_u((safe_div_func_int32_t_s_s((safe_lshift_func_int8_t_s_u(0x32, 5)), (((l_2061 > l_991) , 249U) && (l_1063 == l_1027)))), (((!(safe_rshift_func_int8_t_s_s(0, 2))) == (((l_1067 != (void*)0) ^ 0xFA0732C2) && l_991)) || l_1009))), g_210.f6)) , l_991) , p_50);
                    }
                }
                for (g_2619 = 3; (g_2619 >= 0); g_2619 -= 1)
                {
                    int8_t l_1072 = (-1);
                    uint32_t l_1076 = 1U;
                    int32_t *l_1083 = &g_33[2];
                    struct S0 l_1095 = {631,1691,-119,1361,102,1,-551,267,-4};
                    if ((safe_div_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(l_1072, 1)), l_991)))
                    {
                        int32_t *l_1073 = (void*)0;
                        (*l_1027) = l_1073;
                        (*l_1027) = ((((+l_991) || (g_1031[4] <= (~(l_1076 ^ (safe_mod_func_uint16_t_u_u(((!((((safe_div_func_int16_t_s_s(((*(*l_1893)) != l_1083), (((((safe_unary_minus_func_int32_t_s(1)) || (((((safe_add_func_uint16_t_u_u((0xFC05510A | ((safe_sub_func_uint32_t_u_u(0x237EEA70, (safe_add_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_s((g_33[2] , (*l_1083)), l_991)) > 0xA091E223), l_2370.f3)))) , 1U)), 0xF723)) <= 7U) ^ l_1706) , (*l_1083)) != 0x7BD9C737)) >= (*p_50)) , (*(*(*l_1893)))) || l_991))) != g_210.f5) ^ (*l_1028)) , l_2370.f1)) & g_210.f4), l_991)))))) == l_991) , (void*)0);
                    }
                    else
                    {
                        (*(*g_465)) = l_1093;
                        if (l_2279)
                            continue;
                    }
                    (*(*g_465)) = l_1095;
                    for (l_1095.f8 = 3; (l_1095.f8 >= 0); l_1095.f8 -= 1)
                    {
                        int i, j, k;
                        g_986[(g_2619 + 1)][(l_1095.f8 + 1)][l_1706] = l_1096[0];
                        (*(*g_465)) = ((l_1067 != g_986[(g_2619 + 1)][(l_1095.f8 + 1)][l_1706]) , ((l_991 > ((safe_mul_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u((((7 != (((g_210.f1 , 0) , 5) != (g_11[0] < (safe_rshift_func_uint16_t_u_u(((0xAB && (-8)) & 0x4915), l_2370.f2))))) , l_991) & 247U), g_33[2])) ^ 1U), 250U)) > 1)) , (*(*l_1831))));
                    }
                }
            }


            (*p_50) = (l_2370.f1 <= (safe_lshift_func_uint8_t_u_s(((safe_div_func_uint16_t_u_u((safe_div_func_int32_t_s_s((*(*(*l_1893))), (safe_add_func_int32_t_s_s((safe_mod_func_int16_t_s_s((((void*)0 == (*l_2020)) != (safe_sub_func_uint8_t_u_u((safe_rshift_func_uint8_t_u_s((2U >= g_784[1]), 2)), (((safe_add_func_int8_t_s_s(l_991, ((((-1) | ((((void*)0 == &(*g_465)) >= g_210.f3) , l_991)) && l_2279) || 247U))) <= l_991) || l_1119)))), 1U)), g_210.f3)))), l_991)) & 0xA376), 0)));
            for (g_210.f8 = 22; (g_210.f8 != (-14)); --g_210.f8)
            {
                int8_t l_1145 = 0;
                int32_t **l_1147[10] = {&g_32[0],&l_2437,&g_32[0],&g_986[0][4][1],&g_986[0][4][1],&g_32[0],&l_2437,&g_32[0],&g_986[0][4][1],&g_986[0][4][1]};
                int i;
                (*l_1028) = l_2122;
                l_1146 = (((safe_add_func_int8_t_s_s((safe_sub_func_uint32_t_u_u(l_991, (*p_50))), l_2370.f7)) == (safe_mul_func_int8_t_s_s((l_1129[3] | g_210.f3), l_1706))) , (((safe_lshift_func_int16_t_s_u((l_991 < (safe_mod_func_int32_t_s_s((safe_mod_func_int16_t_s_s((safe_mul_func_int16_t_s_s((safe_rshift_func_int8_t_s_u((safe_sub_func_int16_t_s_s((((safe_div_func_uint16_t_u_u(((l_1144 == (*l_1831)) < l_991), l_2370.f3)) < g_210.f2) , l_1145), 0x9282)), 2)), l_1145)), g_33[2])), 1))), 9)) >= (*l_2437)) , (*(*l_1831))));
                g_944[3][0][7] = l_1096[0];
            }
        }
        else
        {
            struct S0 l_1148 = {513,9870,-147,246,399,1,-1229,339,-7};
            int32_t *l_1149 = &g_11[0];
            g_32[1] = (*(*l_1893));
            (**l_2020) = l_1148;
            return l_1149;


        }


    }
    else
    {
        uint16_t l_1163 = 0xC70C;
        int32_t *l_1168 = (void*)0;
        int32_t ***l_1173 = &(*g_2770);
        int32_t l_1180 = 0xE5966CEA;
        int32_t l_1182 = 1;
        struct S0 **l_1203 = (void*)0;
        int32_t ***l_1214 = &(*g_2770);
        uint32_t l_1341 = 4294967295U;
        int8_t l_1538 = 0xDF;
        int32_t ***l_1550 = &(*g_2770);
        int32_t l_1551 = 0x58DAA0B5;
        uint32_t l_1583 = 0xAAF3E96A;
        for (l_2061 = 1; (l_2061 <= 4); l_2061 += 1)
        {
            struct S0 ***l_1162 = &l_2020;
            int32_t **l_1169 = (void*)0;
            int32_t **l_1170 = &(*(*l_1893));
            int i;
            (**l_2020) = (*(*g_465));
        }
        if (((((l_1163 < ((l_1163 ^ (((g_784[3] , l_1173) == &(*l_1893)) , ((((255U == (((*(*(*l_1893))) && (safe_sub_func_uint32_t_u_u((1 ^ (~(((~((safe_add_func_uint32_t_u_u(0xBB6AE9AE, l_1180)) || 0x34)) <= l_2370.f2) && g_2619))), l_991))) | l_991)) < l_991) | (-1)) & 250U))) >= l_2370.f6)) || 0xA9) < l_1182) | 65531U))
        {
            int32_t l_1191 = 0x55505A39;
            struct S0 *l_1198 = &l_2370;
            int32_t ***l_1213 = (void*)0;
            int32_t l_1318 = 3;
            int32_t l_1411 = (-4);
            int32_t *l_1417 = &l_1191;
            if ((!(-1)))
            {
                int16_t l_1184 = 0x7143;
                uint16_t l_1199 = 0x6469;
                int32_t **l_1200 = &g_32[1];
                (*l_1200) = p_50;
            }
            else
            {
                (**l_2020) = (*(*l_1831));
            }
            (*(*(*l_1893))) = (l_991 , (((l_1191 < (((l_991 == ((((0x3079 || ((((*l_2020) == (*l_2020)) != l_1191) || ((safe_mul_func_int8_t_s_s(((&(*g_465) == l_1203) == (*l_2437)), 255U)) & l_991))) , (*(*(*l_1893)))) <= l_2279) & l_991)) , &l_1191) == &l_1167[5][0])) > (*(*(*l_1893)))) <= g_210.f1));
            if ((~(((((safe_lshift_func_int8_t_s_u(((safe_rshift_func_int16_t_s_u((0x40 == (((g_11[0] >= (safe_sub_func_int16_t_s_s(l_2370.f6, (safe_lshift_func_uint16_t_u_u(0x8C85, 9))))) , l_1213) != l_1214)), (safe_lshift_func_int16_t_s_s(g_210.f0, 10)))) < 4294967286U), ((((((l_991 < (-9)) == (*(*(*l_1893)))) , (void*)0) != (void*)0) , 0x1611) ^ l_991))) , (*p_50)) < 0U) , l_2105) , l_991)))
            {
                int32_t *l_1220 = &l_1167[5][4];
                int32_t l_1239 = 5;
                int32_t l_1319 = 0x0E489A9E;
                uint16_t l_1349 = 1U;
                struct S0 ***l_1362[8];
                struct S0 *l_1407 = (void*)0;
                int32_t l_1410 = 9;
                int i;
                for (i = 0; i < 8; i++)
                    l_1362[i] = (void*)0;
                if ((*p_50))
                {
                    int32_t *l_1219 = &g_33[2];
                    struct S0 ***l_1250[4] = {&l_2020,&l_2020,&l_2020,&l_2020};
                    struct S0 l_1255 = {192,4318,-489,36,135,-0,1153,251,0x86};
                    int i;
                    if ((~l_991))
                    {
                        l_1219 = l_1219;
                        l_1220 = (void*)0;

                        ((l_1220 == 0) ? (void) (0) : __assert_fail ("l_1220 == 0", "t.c", 3799, __PRETTY_FUNCTION__));
                    }
                    else
                    {
                        int32_t **l_1241 = &g_32[0];
                        (*l_1220) = (safe_add_func_uint16_t_u_u((l_1219 == &g_11[0]), (((safe_add_func_uint32_t_u_u((((safe_rshift_func_uint16_t_u_s(g_210.f2, ((((*l_1219) & ((safe_rshift_func_uint8_t_u_s((safe_mod_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_s(((safe_sub_func_int16_t_s_s((safe_rshift_func_uint16_t_u_u(((void*)0 == &(*g_2770)), 10)), (((*(*l_1831)) , (((l_991 != l_991) || l_991) && l_991)) ^ 0x76))) >= l_991), (*l_1220))) >= l_1239), 0x8F)), 0)) == g_2619)) >= l_991) < 0x6B1FB5AC))) > g_1031[4]) , (*l_1219)), l_1614)) || (*p_50)) <= (*l_1220))));
                        (*l_1241) = (void*)0;
                        l_1180 = ((safe_mul_func_int16_t_s_s((l_991 > (safe_div_func_int32_t_s_s(((safe_sub_func_int8_t_s_s((0x76 ^ (0xFD != ((*l_1219) > (*p_50)))), (safe_mul_func_uint16_t_u_u(0x6A67, 0xFFEE)))) | (((l_1250[0] != (void*)0) , l_991) > 65535U)), (*l_1219)))), 0xC94C)) && l_991);
                        (*(*g_465)) = (*(*l_1831));
                    }

                    (((l_1220 >= &l_1167[0][0] && l_1220 <= &l_1167[8][6]) || l_1220 == 0) ? (void) (0) : __assert_fail ("(l_1220 >= &l_1167[0][0] && l_1220 <= &l_1167[8][6]) || l_1220 == 0", "t.c", 3810, __PRETTY_FUNCTION__));
                    l_1219 = &l_1167[4][3];

                    (((l_1219 >= &l_1167[0][0] && l_1219 <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("(l_1219 >= &l_1167[0][0] && l_1219 <= &l_1167[8][6])", "t.c", 3813, __PRETTY_FUNCTION__));
                }
                else
                {
                    (*(*(*l_1893))) = (*p_50);
                }

                (((l_1220 >= &l_1167[0][0] && l_1220 <= &l_1167[8][6]) || l_1220 == 0) ? (void) (0) : __assert_fail ("(l_1220 >= &l_1167[0][0] && l_1220 <= &l_1167[8][6]) || l_1220 == 0", "t.c", 3820, __PRETTY_FUNCTION__));
                for (l_1706 = (-2); (l_1706 > (-21)); --l_1706)
                {
                    int8_t l_1279 = 0;
                    int8_t l_1329 = (-1);
                    int32_t ***l_1336 = (void*)0;
                    int8_t l_1348 = 1;
                    struct S0 l_1350 = {599,171,-440,1398,438,-1,-231,342,0};
                    (*l_1214) = &p_50;

                    (((*g_2770) == &p_50) ? (void) (0) : __assert_fail ("(*g_2770) == &p_50", "t.c", 3830, __PRETTY_FUNCTION__));
                    if ((((safe_mod_func_uint8_t_u_u((((+((((l_2370.f3 , ((((safe_div_func_uint32_t_u_u(l_991, l_1279)) == ((void*)0 == (*(&(*g_2770))))) <= ((!((safe_rshift_func_int16_t_s_u(l_991, 5)) == ((safe_lshift_func_uint16_t_u_u(((((safe_rshift_func_int16_t_s_s((safe_mul_func_int16_t_s_s((l_1279 & (((((**l_1214) == ((l_991 >= l_991) , (*(*g_2770)))) || 0x4474) < 0xF0E8F346) & g_11[0])), l_1279)), g_784[0])) < l_2370.f5) , l_1279) , l_2370.f4), l_991)) && (***l_1173)))) , 0x66C85F8A)) , 0x993C)) != l_1279) , (*l_2020)) != (void*)0)) > l_1279) & 0x8FA0), 5U)) , g_1271[2][1]) < l_1279))
                    {
                        (*p_50) = ((!(l_2279 && (safe_rshift_func_uint16_t_u_s(l_991, (l_991 != (safe_sub_func_int16_t_s_s((+((+(safe_sub_func_int16_t_s_s((safe_rshift_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((((((&p_50 == ((l_991 > (safe_rshift_func_uint8_t_u_u((*l_2437), 2))) , &p_50)) && (***l_1214)) & ((((safe_sub_func_int8_t_s_s((((*l_1831) == (*l_1831)) & l_991), l_1279)) || 1) , g_210.f7) <= l_2279)) | 0x7B86) == 0) == l_991), 0x08)), l_991)), g_210.f4))) != 0)), l_1306[4][2][4]))))))) , 0);
                    }
                    else
                    {
                        int16_t l_1344 = 1;
                        int32_t ***l_1347 = &(*g_2770);
                        (**(*g_2770)) = (+(((((((safe_rshift_func_uint16_t_u_s(((**(*g_2770)) && (*p_50)), (safe_add_func_uint16_t_u_u(g_11[0], ((safe_lshift_func_int16_t_s_u((((void*)0 != &(*g_2770)) >= l_991), (safe_div_func_int8_t_s_s((g_784[3] , ((l_991 <= (safe_rshift_func_uint16_t_u_s(65529U, 2))) && (***l_1173))), l_991)))) && 0x4B36))))) < 255U) < l_991) < g_33[2]) ^ l_1318) == 0) < 0x6094));
                        (**l_1173) = (**l_1173);
                        (**(*g_2770)) = ((((((safe_mul_func_int16_t_s_s((((void*)0 == (*(*g_2770))) ^ ((g_210.f7 , (***(&(*g_2770)))) ^ (safe_div_func_int16_t_s_s((((safe_rshift_func_int16_t_s_s((l_1336 != (((safe_add_func_uint8_t_u_u(g_210.f0, (safe_sub_func_int8_t_s_s(l_1341, (safe_mod_func_int16_t_s_s((l_1344 | (safe_mod_func_uint32_t_u_u(((*l_1831) == (void*)0), l_1344))), (-8))))))) && 0x3B) , l_1347)), l_991)) , 0xD8) < l_991), g_1031[3])))), l_1348)) && (***l_1347)) < 0xD0DF30A5) ^ (*(*(*l_1893)))) | (***(&(*g_2770)))) , l_1349);
                        l_1350 = (*(*l_1831));
                    }
                }

                (((*g_2770) == &p_50 || (*g_2770) == 0) ? (void) (0) : __assert_fail ("(*g_2770) == &p_50 || (*g_2770) == 0", "t.c", 3846, __PRETTY_FUNCTION__));
                if ((l_2108 , (((0xFED2 == (l_1318 >= ((((1 && (((((p_50 != (void*)0) & (safe_add_func_uint8_t_u_u((safe_rshift_func_int8_t_s_s((safe_mul_func_int16_t_s_s((safe_div_func_uint16_t_u_u(l_991, l_991)), (safe_add_func_int32_t_s_s((((&l_2020 == l_1362[5]) != (*p_50)) >= g_2805), (*p_50))))), g_784[3])), g_784[3]))) ^ g_1031[3]) <= l_1191) > l_991)) > l_991) == 0x9A) < (*(*(*l_1893)))))) & 0xCABBB83D) , l_1191)))
                {
                    for (l_1341 = (-6); (l_1341 != 19); l_1341 = safe_add_func_int8_t_s_s(l_1341, 5))
                    {
                        struct S0 *l_1374 = &l_2105;
                        uint8_t l_1375 = 0xEB;
                        int32_t **l_1384 = &g_944[6][1][4];
                        (*l_1384) = ((safe_sub_func_int8_t_s_s(l_2370.f6, (safe_add_func_uint32_t_u_u(((safe_add_func_int8_t_s_s((-5), (safe_add_func_int8_t_s_s(0x81, (((l_1374 != (*l_1831)) | l_1375) && (safe_lshift_func_int8_t_s_s(l_2279, (safe_add_func_uint8_t_u_u(((*p_50) > ((!(safe_mul_func_uint8_t_u_u(g_210.f1, (-9)))) || 0xBB08)), 0x6F))))))))) ^ l_1181), 4294967294U)))) , (void*)0);
                    }
                }
                else
                {
                    int16_t l_1402 = (-1);
                    int32_t *l_1415 = &(*l_2437);
                    (*(*(*l_1893))) = (safe_div_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((safe_lshift_func_int16_t_s_u(((safe_div_func_int32_t_s_s(((void*)0 != &l_1167[4][2]), (safe_mul_func_uint8_t_u_u((g_784[1] >= ((safe_div_func_uint16_t_u_u(((safe_mul_func_int8_t_s_s(0xAE, ((*p_50) <= (!(*p_50))))) | ((((*(*(*l_1893))) < (((safe_add_func_int8_t_s_s(((((((*p_50) == l_991) || 65535U) , (void*)0) != &(*g_465)) > (*p_50)), l_1706)) || g_33[2]) && 0xF8180D4D)) && l_991) , 0)), l_991)) != l_2370.f4)), g_11[0])))) && l_1402), 15)), g_784[1])), 0x40));
                    l_2290 = ((safe_sub_func_int8_t_s_s((safe_add_func_int32_t_s_s((((l_1407 != &l_2105) , 0x813C1E7A) & (l_991 && ((((void*)0 == (*l_1831)) | g_210.f4) < ((((safe_rshift_func_uint8_t_u_s(l_991, 4)) <= g_2619) ^ l_1410) || 0x6C)))), l_1411)), 0x9F)) , &g_11[0]);

                    (((l_2290 >= &g_11[0] && l_2290 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_2290 >= &g_11[0] && l_2290 <= &g_11[0])", "t.c", 3864, __PRETTY_FUNCTION__));
                    for (l_1182 = 0; (l_1182 >= 11); l_1182 = safe_add_func_int8_t_s_s(l_1182, 7))
                    {
                        int32_t **l_1416[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_1416[i] = &g_986[1][2][3];
                        l_2437 = l_1415;

                        ((l_2437 == &(*l_2437)) ? (void) (0) : __assert_fail ("l_2437 == &(*l_2437)", "t.c", 3873, __PRETTY_FUNCTION__));
                    }

                    ((l_2437 == &(*l_2437) || l_2437 == 0 || (l_2437 >= &g_11[0] && l_2437 <= &g_11[0])) ? (void) (0) : __assert_fail ("l_2437 == &(*l_2437) || l_2437 == 0 || (l_2437 >= &g_11[0] && l_2437 <= &g_11[0])", "t.c", 3876, __PRETTY_FUNCTION__));
                }

                ((l_2437 == &(*l_2437) || l_2437 == 0 || (l_2437 >= &g_11[0] && l_2437 <= &g_11[0])) ? (void) (0) : __assert_fail ("l_2437 == &(*l_2437) || l_2437 == 0 || (l_2437 >= &g_11[0] && l_2437 <= &g_11[0])", "t.c", 3879, __PRETTY_FUNCTION__));
                (((l_2290 >= &g_11[0] && l_2290 <= &g_11[0]) || (l_2290 >= &g_33[0] && l_2290 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_2290 >= &g_11[0] && l_2290 <= &g_11[0]) || (l_2290 >= &g_33[0] && l_2290 <= &g_33[4])", "t.c", 3880, __PRETTY_FUNCTION__));
            }
            else
            {
                int32_t **l_1418 = &l_2290;
                int32_t *l_1419 = (void*)0;
                (*l_1418) = l_1417;

                ((l_2290 == &l_1191) ? (void) (0) : __assert_fail ("l_2290 == &l_1191", "t.c", 3888, __PRETTY_FUNCTION__));
                return l_1419;


            }

            ((l_2437 == &(*l_2437) || l_2437 == 0 || (l_2437 >= &g_11[0] && l_2437 <= &g_11[0])) ? (void) (0) : __assert_fail ("l_2437 == &(*l_2437) || l_2437 == 0 || (l_2437 >= &g_11[0] && l_2437 <= &g_11[0])", "t.c", 3894, __PRETTY_FUNCTION__));
            (((*g_2770) == &p_50 || (*g_2770) == 0) ? (void) (0) : __assert_fail ("(*g_2770) == &p_50 || (*g_2770) == 0", "t.c", 3895, __PRETTY_FUNCTION__));
            (((l_2290 >= &g_11[0] && l_2290 <= &g_11[0]) || (l_2290 >= &g_33[0] && l_2290 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_2290 >= &g_11[0] && l_2290 <= &g_11[0]) || (l_2290 >= &g_33[0] && l_2290 <= &g_33[4])", "t.c", 3896, __PRETTY_FUNCTION__));
            (**l_2020) = (*l_1198);
        }
        else
        {
            int32_t **l_1420 = &l_1096[0];
            struct S0 ***l_1436 = &l_2020;
            int32_t l_1453 = 0xA004A054;
            (*l_1420) = p_50;


            for (l_1182 = 3; (l_1182 >= 0); l_1182 -= 1)
            {
                int32_t *l_1433 = &g_11[0];
                int32_t l_1451 = 0x78DACA4D;
                struct S0 ***l_1493 = (void*)0;
                uint16_t l_1500 = 65532U;
                uint32_t l_1513 = 0U;
            }
        }

        ((l_2437 == &(*l_2437) || l_2437 == 0 || (l_2437 >= &g_11[0] && l_2437 <= &g_11[0])) ? (void) (0) : __assert_fail ("l_2437 == &(*l_2437) || l_2437 == 0 || (l_2437 >= &g_11[0] && l_2437 <= &g_11[0])", "t.c", 3917, __PRETTY_FUNCTION__));
        (((*g_2770) == &p_50 || (*g_2770) == 0) ? (void) (0) : __assert_fail ("(*g_2770) == &p_50 || (*g_2770) == 0", "t.c", 3918, __PRETTY_FUNCTION__));

        (((l_2290 >= &g_11[0] && l_2290 <= &g_11[0]) || (l_2290 >= &g_33[0] && l_2290 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_2290 >= &g_11[0] && l_2290 <= &g_11[0]) || (l_2290 >= &g_33[0] && l_2290 <= &g_33[4])", "t.c", 3920, __PRETTY_FUNCTION__));
        if (((((*(*l_1831)) , ((-7) >= (safe_rshift_func_int8_t_s_s((safe_mod_func_uint8_t_u_u(1U, l_2370.f4)), 3)))) , &l_1831) != &l_2020))
        {
            int32_t ***l_1560 = &(*g_2770);
            uint32_t l_1561 = 1U;
            (**l_2020) = (((safe_rshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u(((void*)0 == l_1560), ((g_33[3] <= l_2370.f5) , (((l_991 & l_991) <= l_1561) & ((((-1) | (safe_mul_func_uint16_t_u_u(((+((safe_sub_func_int8_t_s_s(((*(*l_1831)) , 0x8C), g_210.f2)) ^ (*p_50))) > g_11[0]), 5))) >= g_210.f7) != (*(*(*l_1893)))))))), 4)) || l_991) , (*(*l_1831)));
        }
        else
        {
            struct S0 ***l_1573 = &l_2020;
            int32_t l_1584 = 0x3E9E2198;
            l_1584 = (safe_sub_func_int8_t_s_s(((safe_div_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u((((((void*)0 == l_1573) < (l_2370.f4 == (((0xA69270CB <= (safe_mod_func_int32_t_s_s((*p_50), (safe_lshift_func_uint8_t_u_u((0x1A435ED4 || 0x293A6C42), ((safe_div_func_uint32_t_u_u(((((((((+(((safe_div_func_int16_t_s_s(((&(*g_2770) == &(*g_2770)) != l_991), (-1))) && 6U) , l_1583)) <= 1) ^ l_991) , (*(*l_1831))) , (*(*g_465))) , (*g_2770)) == (void*)0) == l_991), (*p_50))) | (*p_50))))))) , &g_11[0]) != (void*)0))) < l_991) && 0xFCF112B4), 13)), l_991)) ^ 0xD9BD5AFF), 0xAE));
        }
    };


                    if (((void*)0 == &p_52))
                    {
                        int i;
                        if (l_1806[l_1597])
                            break;
                        if (g_784[l_1597])
                            break;
                        (**l_2020) = (**l_2020);
                    }
                    else
                    {
                        uint8_t l_2278[8] = {0x98,0U,0x98,0U,0x98,0U,0x98,0U};
                        int i;

for (l_2164 = 0; (l_2164 == 6); ++l_2164)
                    {
                        (*(&l_2291)) = l_2212;
                        if ((*l_2212))
                            break;
                    };


                    (*(&k)) = l_2278[3];
                        (*p_52) = l_2280;

                        (((*p_52) == &l_1811) ? (void) (0) : __assert_fail ("(*p_52) == &l_1811", "t.c", 3961, __PRETTY_FUNCTION__));
                    }
                    (*l_1608) = ((safe_add_func_int16_t_s_s((l_2283 & 0x8AA9DF5A), (((*(*g_465)) , l_2122) >= ((((safe_mod_func_int32_t_s_s((safe_mul_func_uint16_t_u_u(0xA3A4, l_2283)), (safe_div_func_int32_t_s_s((((l_1363 , (**l_2020)) , (*(&l_1608))) == (*(&l_1608))), l_1363)))) && 0x7B21) , l_1363) , 255U)))) , (*p_52));
                    (*l_1608) = l_2280;
                }
            }

            (((*p_52) == &l_1811 || ((*p_52) >= &g_33[0] && (*p_52) <= &g_33[4])) ? (void) (0) : __assert_fail ("(*p_52) == &l_1811 || ((*p_52) >= &g_33[0] && (*p_52) <= &g_33[4])", "t.c", 3968, __PRETTY_FUNCTION__));
            return l_2291;




        }


        (((*l_1828) == &(*g_465) || (*l_1828) == 0 || (*l_1828) == &g_466) ? (void) (0) : __assert_fail ("(*l_1828) == &(*g_465) || (*l_1828) == 0 || (*l_1828) == &g_466", "t.c", 3977, __PRETTY_FUNCTION__));
        (((g_2221 >= &g_11[0] && g_2221 <= &g_11[0]) || g_2221 == 0) ? (void) (0) : __assert_fail ("(g_2221 >= &g_11[0] && g_2221 <= &g_11[0]) || g_2221 == 0", "t.c", 3978, __PRETTY_FUNCTION__));
        for (l_1363 = (-27); (l_1363 > 36); l_1363 = safe_add_func_uint32_t_u_u(l_1363, 3))
        {
            uint16_t l_2316 = 0U;
            uint32_t l_2317 = 7U;
            (*l_1645) = ((safe_lshift_func_uint8_t_u_u(g_210.f3, (((&(*g_465) != (((safe_add_func_uint8_t_u_u((+(safe_add_func_uint8_t_u_u(g_210.f4, ((safe_mod_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((g_210.f4 <= ((((((safe_add_func_int32_t_s_s((((safe_mul_func_int16_t_s_s(g_210.f3, 9)) , l_2309[3]) == (safe_add_func_uint8_t_u_u(((safe_mul_func_int16_t_s_s((safe_div_func_int16_t_s_s((((l_1363 != l_2316) && l_1363) || l_2316), g_210.f1)), l_1363)) , l_2317), g_210.f3))), (-1))) || l_1363) , 9) != 255U) <= g_1271[2][1]) && g_2647)), 13)), 0x6C1B)) < l_1363)))), l_1363)) , l_1988[0][2][5]) , &g_466)) < 0xC785) | l_1363))) , (*(*p_52)));
        }
        (*(&k)) = ((((0xAC87D08D & (((safe_mod_func_int32_t_s_s((safe_mul_func_int8_t_s_s(l_2323, l_1363)), (safe_lshift_func_int8_t_s_u((&l_2020 != l_1828), 3)))) , (safe_rshift_func_int16_t_s_s(((g_11[0] , ((g_784[0] , ((safe_mul_func_uint8_t_u_u((safe_mul_func_int8_t_s_s((255U >= (safe_div_func_uint16_t_u_u((2 || (*(&k))), 65532U))), l_1363)), 0x41)) & 0xF0B61FC1)) != g_1031[4])) , l_1363), 9))) , (-1))) == l_1363) <= (*l_1645)) <= g_210.f3);
    }
    else
    {
        int8_t l_2340 = 0x2F;
        int32_t *l_2366 = &l_1167[6][6];
        int32_t ***l_2382 = &p_52;
        int32_t ***l_2466 = &p_52;
        uint8_t l_2522 = 8U;
        int32_t *l_2565[7];
        int i;
        for (i = 0; i < 7; i++)
            l_2565[i] = &g_33[3];

{
    int32_t l_75 = 6;
    struct S0 ***l_896 = &(*l_1828);
    int32_t l_901 = 0x6C9D0AB9;
    int32_t **l_909[4][9] = {{&l_1412,&l_1412,&g_32[1],&g_32[1],&g_32[1],&g_32[1],&l_1412,&l_1412,&g_32[1]},{&l_1412,&g_32[1],(void*)0,&l_1412,&l_1412,(void*)0,&g_32[1],&l_1412,(void*)0},{&l_1412,&l_1412,&g_32[1],&g_32[1],&g_32[1],&g_32[1],&l_1412,&l_1412,&g_32[1]},{&l_1412,&g_32[1],(void*)0,&l_1412,&l_1412,(void*)0,&g_32[1],&l_1412,(void*)0}};
    int i, j;
    for (l_2323 = 0; (l_2323 <= 2); l_2323 += 1)
    {
        uint8_t l_76 = 4U;
        int32_t *l_478 = &(*l_1082);
        int i;
        for ((*l_1082) = 0; ((*l_1082) <= 4); (*l_1082) += 1)
        {
            int i;
        }
        g_33[(l_2323 + 1)] = g_33[(l_2323 + 1)];

{
                        int16_t l_847 = 0x83AA;
                        int32_t *l_848 = (void*)0;
                        (*(&l_2164)) = (safe_mul_func_uint8_t_u_u(0x03, (safe_div_func_int8_t_s_s((safe_mul_func_uint8_t_u_u(l_2340, (((safe_rshift_func_uint16_t_u_s((safe_add_func_uint16_t_u_u(g_2619, (safe_mod_func_int8_t_s_s(((8U ^ (safe_add_func_uint32_t_u_u(l_2340, (0xCA840E31 & 4294967293U)))) , (l_2105.f8 && g_784[3])), l_847)))), 15)) == l_2370.f2) & 0))), l_2340))));
                        return l_848;



                    }

                    g_32[l_2323] = &g_33[(l_2323 + 1)];
    }
    if (((l_75 & l_1631) & (l_896 != (((l_1217.f5 , (safe_sub_func_int8_t_s_s(((l_901 || ((safe_mul_func_int16_t_s_s((l_1631 >= (safe_sub_func_int16_t_s_s((safe_add_func_int16_t_s_s((((((((safe_unary_minus_func_int16_t_s(((void*)0 != l_909[0][7]))) , (safe_add_func_int16_t_s_s((+l_2323), 0xDF67))) && 0xB20DAD22) < l_1631) | l_1217.f3) , l_2323) ^ 1U), l_1217.f0)), (*p_53).f0))), l_1217.f7)) == l_1631)) , 0x06), g_33[3]))) && 0xF89A) , (void*)0))))
    {
        int32_t *l_915[6][3] = {{(void*)0,&(*l_1082),(void*)0},{&g_33[1],&g_33[1],&g_33[2]},{&(*l_1082),&(*l_1082),&(*l_1082)},{&g_33[1],&g_33[2],&g_33[2]},{(void*)0,&(*l_1082),(void*)0},{&g_33[1],&g_33[1],&g_33[2]}};
        int32_t ***l_925 = &l_909[3][6];
        uint32_t l_938[1][7][8] = {{{0xFED5CCC8,0xFED5CCC8,0x447CA895,0xAFA15E54,0xAB0FB7AA,0xAFA15E54,0x447CA895,0xFED5CCC8},{0xFED5CCC8,0xA6BF248C,0x9AA94303,0x447CA895,0x447CA895,0x9AA94303,0xA6BF248C,0xFED5CCC8},{0xA6BF248C,4U,0xFED5CCC8,0xAFA15E54,0xFED5CCC8,4U,0xA6BF248C,0xA6BF248C},{4U,0xAFA15E54,0x9AA94303,0x9AA94303,0xAFA15E54,4U,0x447CA895,4U},{0xAFA15E54,4U,0x447CA895,4U,0xAFA15E54,0x9AA94303,0x9AA94303,0xAFA15E54},{4U,0xA6BF248C,0xA6BF248C,4U,0xFED5CCC8,0xAFA15E54,0xFED5CCC8,4U},{0xA6BF248C,0xFED5CCC8,0xA6BF248C,0x9AA94303,0x447CA895,0x447CA895,0x9AA94303,0xA6BF248C}}};
        int8_t l_943 = 2;
        int i, j, k;
        (*l_1412) = (0xE12F452C > (safe_mod_func_int32_t_s_s((l_915[2][2] == l_915[2][2]), (safe_add_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((0x9B <= (0x1E1C != ((safe_mul_func_uint16_t_u_u(((+((&g_297 == (void*)0) , ((l_925 == &l_909[2][2]) <= g_11[0]))) < l_1631), l_2323)) == l_2323))), l_2323)), l_1631)))));

{
                    struct S0 l_2443 = {534,2588,69,470,37,-0,1036,319,-9};
                    uint32_t l_2476 = 4294967295U;
                    int32_t *l_2478 = (void*)0;
                    struct S0 ***l_2498 = &g_465;
                    l_2443 = (**g_465);
                    if (((safe_sub_func_int32_t_s_s((safe_rshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((g_2619 , (**g_465)) , (safe_mod_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(0x497B, 0U)), (((safe_rshift_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(((((**g_465) , (((((((((safe_add_func_int8_t_s_s((*g_466).f8, (safe_rshift_func_uint16_t_u_u((~(1U < (((((void*)0 == &g_33[2]) == g_2054[3][1][0]) ^ g_2619) & 0x9DD8))), l_2443.f4)))) <= (*g_466).f0) < 0xA736BD57) > 0x4985) , l_2443) , (void*)0) == (&p_52)) || l_1986) , 0xE6)) < 0x78) > g_2805), 65535U)), g_2805)) < (*(*l_1608))) , g_2805)))), l_1986)), g_2805)), g_2805)) < 0U))
                    {
                        int32_t **l_2477 = (void*)0;
                        l_1082 = &g_33[4];
                        if (l_2443.f6)
                            continue;
                        return l_2478;



                    }
                    else
                    {
                        uint32_t l_2493[3][6];
                        int i, j;
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 6; j++)
                                l_2493[i][j] = 1U;
                        }
                        (*l_1850) = ((g_2619 & (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u(((((((safe_lshift_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((g_2619 , (safe_lshift_func_uint16_t_u_s(((safe_sub_func_int32_t_s_s((((((l_2493[0][4] && ((g_2619 <= (((safe_sub_func_int8_t_s_s(((safe_mul_func_int16_t_s_s(0x1FF6, (((*g_466).f7 > (*g_466).f8) >= ((l_2498 == (void*)0) , (-1))))) , (*l_1082)), g_1031[3])) , (*(&l_2030))) & 7)) > (*g_466).f0)) , (**g_465)) , (*g_466).f8) && g_2619) , l_1631), 0x8ADDA95C)) , g_2805), 2))), g_1094)) | g_2805), g_2805)) ^ (*(&l_2030))) >= 0x4B) || (*g_466).f0) == 0x09) , (*g_466).f1), 5)), 6)), 0))) , (*l_1082));
                    }
                    for (l_2108 = 4; (l_2108 < 59); l_2108++)
                    {
                        int32_t **l_2503 = &(*l_1608);
                        (*l_2503) = l_2478;

                        (((*l_1608) == 0) ? (void) (0) : __assert_fail ("(*l_1608) == 0", "t.c", 4070, __PRETTY_FUNCTION__));
                        (*l_2503) = (*p_52);

                        ((((*l_1608) >= &l_1167[0][0] && (*l_1608) <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("((*l_1608) >= &l_1167[0][0] && (*l_1608) <= &l_1167[8][6])", "t.c", 4073, __PRETTY_FUNCTION__));
                        if ((**l_2503))
                            break;
                        (*(&l_1735)) = (**l_2503);
                    }
                    (*(&g_21)) = (safe_rshift_func_uint8_t_u_s(((((*(&l_2030)) == ((safe_rshift_func_int16_t_s_s((0x81 < (g_2805 && ((0x79A0 && g_2805) || (((((g_2805 != ((4U != l_2108) ^ (safe_lshift_func_int16_t_s_s((-1), (*g_466).f8)))) == 0x7CB1) , (*g_466).f4) ^ 0x0273614A) , 1)))), g_1031[4])) ^ (*l_1082))) , (*l_1082)) > l_2350), g_2805));
                }

                    if ((safe_div_func_uint32_t_u_u((l_1631 , (safe_unary_minus_func_int16_t_s((((l_2323 , ((((safe_div_func_int32_t_s_s((l_1217.f1 != ((safe_unary_minus_func_uint32_t_u((safe_rshift_func_uint16_t_u_u((+((0 == ((((((safe_unary_minus_func_int16_t_s(((l_938[0][5][3] >= ((((((l_2323 < ((safe_mul_func_uint32_t_u_u(l_1904, ((safe_mul_func_uint16_t_u_u((l_915[2][2] != (l_1217.f5 , &g_11[0])), 0xD9A6)) >= 254U))) && l_1217.f1)) , g_33[2]) & l_2323) != (-10)) >= l_1217.f4) != l_943)) , 0x3570))) > 1) <= (*p_53).f6) & l_1217.f2) < 0x86E2) != (-1))) & l_2323)), 0)))) <= (*l_1412))), l_2323)) > l_2323) <= (*p_53).f8) ^ 65528U)) , (void*)0) != (*l_925))))), l_2323)))
        {
            g_944[6][0][7] = &g_11[0];


        }
        else
        {
            int32_t *l_945 = (void*)0;
            struct S0 l_954 = {759,10814,-151,1367,80,-0,261,103,0xB5};
            l_1412 = l_945;

            ((l_1412 == 0) ? (void) (0) : __assert_fail ("l_1412 == 0", "t.c", 4093, __PRETTY_FUNCTION__));
            for (l_75 = 2; (l_75 >= 0); l_75 -= 1)
            {
                uint8_t l_953 = 0x18;
                int32_t l_955[7] = {1,1,1,1,1,1,1};
                int i;
                l_945 = (void*)0;
                for (l_2323 = 0; (l_2323 <= 2); l_2323 += 1)
                {
                    int i, j;
                    l_955[2] = (safe_rshift_func_int16_t_s_s(0x6619, (((0xB5C21137 || ((safe_lshift_func_int8_t_s_s((((((l_1631 , ((0U & (((safe_mod_func_int16_t_s_s(((((~(l_915[(l_2323 + 3)][l_2323] != g_32[l_2323])) & l_2323) , l_2323) ^ (((((l_1217.f3 & l_1217.f6) || l_2323) < g_784[3]) && g_784[1]) <= l_953)), 0x5977)) > l_2323) , l_2323)) , l_954)) , l_2323) , l_1217.f6) <= 0x91E96527) > g_2956), 2)) , l_953)) < l_1631) > (-3))));
                    for (l_953 = 0; (l_953 <= 2); l_953 += 1)
                    {
                        uint8_t l_963 = 1U;
                        int i, j;
                    }
                    l_915[(l_2323 + 2)][l_75] = (void*)0;
                }
            }
        }

        ((l_1412 == 0 || (l_1412 >= &g_11[0] && l_1412 <= &g_11[0])) ? (void) (0) : __assert_fail ("l_1412 == 0 || (l_1412 >= &g_11[0] && l_1412 <= &g_11[0])", "t.c", 4114, __PRETTY_FUNCTION__));

        l_915[4][1] = (((safe_sub_func_int32_t_s_s(0, (safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_add_func_uint16_t_u_u(l_1217.f4, (((((((l_1217.f4 == (g_11[0] || (65535U <= ((safe_lshift_func_int8_t_s_s(0x4B, 3)) ^ ((((safe_div_func_int16_t_s_s((65529U || ((void*)0 != &l_909[2][0])), (*p_53).f2)) , l_2323) & l_1631) && 0x4BE31D81))))) >= l_2323) <= l_2323) , &g_11[0]) == (void*)0) >= g_2956) , l_1631))), 11)), l_2323)))) || l_2323) , l_915[3][0]);
        for (l_1904 = 0; (l_1904 <= 2); l_1904 += 1)
        {
            int i;
            if (l_2323)
                break;
        }
    }
    else
    {
        int32_t *l_978[5] = {&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0]};
        struct S0 l_985 = {577,3425,213,511,506,-1,-392,159,0xDE};
        int i;
        g_944[3][3][1] = l_978[2];


        l_978[2] = &g_11[0];
        (*l_1412) = ((safe_lshift_func_int8_t_s_s((((safe_mul_func_uint8_t_u_u((((l_978[2] == (void*)0) , ((void*)0 != (**l_896))) == 0x62), ((((safe_mod_func_int32_t_s_s(((&l_978[2] == (l_985 , l_909[1][0])) | ((void*)0 == l_909[3][5])), (*l_1412))) ^ l_1217.f4) , g_11[0]) , l_1217.f1))) , l_1631) | l_1631), l_2323)) && l_1631);
    }

    ((l_1412 == 0 || (l_1412 >= &g_11[0] && l_1412 <= &g_11[0])) ? (void) (0) : __assert_fail ("l_1412 == 0 || (l_1412 >= &g_11[0] && l_1412 <= &g_11[0])", "t.c", 4136, __PRETTY_FUNCTION__));

    g_32[1] = g_986[4][2][3];


    for (l_1631 = 0; (l_1631 == (-27)); l_1631--)
    {
        struct S0 l_989 = {907,8858,-498,755,59,1,-1185,276,0};
        (*(*l_2020)) = l_989;
    }
    return &g_33[2];


}

                    if ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_s((safe_mul_func_int8_t_s_s((g_33[3] == l_2340), 0xF8)), 1)) < l_1363), (((safe_add_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((+(((*(*g_465)) , ((safe_rshift_func_int8_t_s_s((((((((&l_1167[6][6] == ((g_210.f5 & (safe_div_func_uint16_t_u_u((g_210.f5 & ((l_2340 || l_1122) , 65535U)), g_210.f4))) , &g_11[0])) != l_1363) , 1U) || l_1363) , g_33[2]) == 0x8C) | l_1363), l_1363)) , (*(*g_465)))) , g_2351)), 0)), (*g_2221))) , &p_52) != (void*)0))))
        {
            int32_t *l_2383 = &l_1167[6][6];

{

{
                        (*(&l_1082)) = l_2383;

                        (((*p_51) == 0) ? (void) (0) : __assert_fail ("(*p_51) == 0", "t.c", 4160, __PRETTY_FUNCTION__));
                        return (&l_2030);


                    }

                    (*g_148) = (((safe_rshift_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_u(((safe_unary_minus_func_int8_t_s(((g_2054[7][0][1] , (!(*g_148))) < (safe_sub_func_uint8_t_u_u(l_1217.f4, 0xD7))))) | (l_1597 & (-8))), l_1217.f1)) && (safe_sub_func_uint32_t_u_u(((l_1217.f5 > (~l_1597)) , l_991), l_991))), g_2054[7][0][1])) == l_2003) < l_991);
                        (*(&g_21)) = ((safe_mod_func_uint32_t_u_u(((((safe_mul_func_int16_t_s_s(l_991, (((l_991 | (safe_add_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_u((-9), l_1217.f4)) , ((safe_sub_func_uint8_t_u_u((((*(&g_21)) || (safe_rshift_func_uint8_t_u_s((g_33[2] & (l_991 != (0x9C > (((l_2500 == l_991) != g_80) , l_991)))), l_991))) != l_991), l_991)) && (*(&g_2956)))), l_1597))) , (void*)0) != (&l_1831)))) <= 0) & l_991) & l_991), 0x51332F8E)) ^ l_1217.f5);
                        (*(*l_1431)) = (*(*l_1431));
                    }


{
                        uint8_t l_2278[8] = {0x98,0U,0x98,0U,0x98,0U,0x98,0U};
                        int i;

l_1181 -= 1;


                    (*(*g_297)) = l_2278[3];
                        l_1082 = l_1850;

                        ((l_1082 == &l_1706) ? (void) (0) : __assert_fail ("l_1082 == &l_1706", "t.c", 4182, __PRETTY_FUNCTION__));
                    }

                    if ((((safe_mul_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((void*)0 == (*l_2020)), ((g_1271[2][1] != ((((l_1363 & (safe_add_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u(((((safe_mod_func_uint16_t_u_u(((((*(*g_465)) , l_2340) , (void*)0) != (void*)0), (safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(0x692C583B, 0x083CD9AE)), l_1363)))) , (void*)0) != (&p_52)) , g_210.f5), g_1031[4])) , l_2366) != l_2366), l_1363))) > l_1363) == l_1363) ^ g_33[2])) >= 0x24))), 0xD203)) <= l_1363) & 0xCB))
            {
                int16_t l_2385 = 1;
                int32_t l_2386[9][3][9] = {{{0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0,(-5),0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0},{1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11},{0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46}},{{0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7},{0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46},{0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11,0xD11FB6A6,0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11}},{{0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0},{0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6},{0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2}},{{1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6},{0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0,(-5),0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0},{1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11}},{{0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46},{0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7},{0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46}},{{0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11,0xD11FB6A6,0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11},{0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5)},{0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7}},{{0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0},{0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7},{0x18DF85E2,0x15E3D6FB,(-5),(-5),0x15E3D6FB,0x18DF85E2,0x15E3D6FB,(-5),(-5)}},{{0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6},{0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2},{0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11}},{{0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2},{0x412DFEB7,1,0xD11FB6A6,0xD11FB6A6,1,0x412DFEB7,1,0xD11FB6A6,0xD11FB6A6},{0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5)}}};
                int32_t ***l_2414 = &p_52;
                int i, j, k;
                for ((*g_2221) = 4; ((*g_2221) >= (-19)); --(*g_2221))
                {
                    int32_t l_2384[2][6][6] = {{{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0}},{{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0}}};
                    int32_t *l_2416 = &g_33[2];
                    int i, j, k;

{
        uint16_t l_2940[8] = {0U,0U,0U,0U,0U,0U,0U,0U};
        int i;
        for (l_1614 = 0; (l_1614 > (-15)); l_1614 = safe_sub_func_int32_t_s_s(l_1614, 1))
        {
            uint16_t l_2954 = 0xBB7C;
            struct S0 **l_2955 = (void*)0;
            (*(*p_51)) = 0x64EAFE29;
            for (l_1363 = 0; (l_1363 <= 3); l_1363 += 1)
            {
                struct S0 ***l_2957 = &g_2531[1][1];
                int16_t l_2958 = 0x8258;
                int i, j, k;
            }
        }
    }

                    if ((*(*p_52)))
                    {
                        struct S0 *l_2369[9][1];
                        int32_t l_2381 = (-1);
                        int i, j;
                        for (i = 0; i < 9; i++)
                        {
                            for (j = 0; j < 1; j++)
                                l_2369[i][j] = (void*)0;
                        }
                        (*l_2366) = (l_2369[8][0] == (*g_465));
                        l_1217 = (g_210.f0 , (*g_466));
                        (*g_2221) = (safe_mod_func_int32_t_s_s(((safe_div_func_uint32_t_u_u(((safe_mul_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_s((((l_2381 & l_1363) | ((((l_2382 != (void*)0) == g_2054[0][0][1]) , l_2383) == ((*(*p_52)) , (*p_52)))) , l_1363), (*l_2383))), 3)), (*g_2221))) ^ l_2384[0][4][4]), l_2385)) != l_2386[5][2][8]), l_2386[1][0][7]));
                    }
                    else
                    {
                        int32_t l_2413 = 0x35119CD0;
                        uint8_t l_2415 = 2U;
                        (*l_2366) = (*(*p_52));
                        (*l_2383) = (safe_mul_func_uint8_t_u_u(((((g_784[3] > (((((g_210.f4 >= (safe_rshift_func_uint8_t_u_u((!(safe_sub_func_uint16_t_u_u(((((g_210.f2 && 248U) >= (!((safe_div_func_uint32_t_u_u(1U, ((((safe_lshift_func_int8_t_s_s((safe_mul_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_s(1U, (safe_add_func_int8_t_s_s((safe_mul_func_int16_t_s_s(g_210.f0, (safe_rshift_func_int16_t_s_s(l_2413, 12)))), (((void*)0 == l_2414) , l_2384[0][4][4]))))) , l_2415), 3)), 0xB4AC)), (*l_2366))) & g_33[2]) != 1U) , (*(*p_52))))) > l_1363))) , l_2384[0][4][5]) ^ g_33[2]), g_2054[7][0][1]))), 0))) , 0xCE1E) == g_784[3]) , 0xB4BE) == g_2351)) <= l_1363) , (-4)) || g_784[3]), (-10)));
                    }
                    return l_2416;



                }
                for (g_2647 = 1; (g_2647 > 38); ++g_2647)
                {
                    int32_t *l_2419 = &g_11[0];
                    return l_2419;



                }
                (*(&k)) = (*(*p_52));
            }
            else
            {
                struct S0 **l_2428 = &g_466;
                int32_t l_2438[9][9] = {{0xA15E527E,(-10),(-8),(-10),0xA15E527E,(-8),0x01077C09,0x01077C09,(-8)},{0xA15E527E,(-10),(-8),(-10),0xA15E527E,(-8),0x01077C09,0x01077C09,(-8)},{0xA15E527E,(-10),(-8),(-10),0xA15E527E,(-8),0x01077C09,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09}};
                int i, j;
                (*g_2221) = (((safe_mul_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u((((((void*)0 != &p_52) , l_2383) == &l_2438[5][1]) , g_210.f4), 1)) > g_210.f0), 0x5D)), (-5))) > l_2438[2][3]) , 0xD350549E);

{
                        int32_t *l_832 = &g_33[2];
                        if (g_2647)
                            break;
                        l_832 = &g_33[2];
                        (*(*l_1431)) = (*g_466);
                        (*l_832) = (-1);
                    }

                    (*l_2366) = 0x5CE0142A;
            }
            return (*p_52);



        }
        else
        {
            uint32_t l_2467 = 0xE6B0EF31;
            int32_t *l_2470 = &g_33[2];
            struct S0 l_2558 = {88,7141,234,1173,28,-0,-1034,196,1};
            int16_t l_2559[6] = {0x641F,0x641F,0x91BC,0x641F,0x641F,0x91BC};
            int32_t *l_2563 = &g_33[3];
            int32_t **l_2564 = &g_32[1];
            int i;
            for (l_1363 = 27; (l_1363 <= 8); --l_1363)
            {
                int16_t l_2452 = 0x9563;
                int8_t l_2499 = 1;
                int32_t *l_2504 = &l_1167[6][6];
                for (g_210.f8 = 0; (g_210.f8 == 2); g_210.f8 = safe_add_func_int8_t_s_s(g_210.f8, 6))
                {
                    struct S0 l_2443 = {534,2588,69,470,37,-0,1036,319,-9};
                    uint32_t l_2476 = 4294967295U;
                    int32_t *l_2478 = (void*)0;
                    struct S0 ***l_2498 = &l_2020;
                    l_2443 = (**l_2020);
                    if (((safe_sub_func_int32_t_s_s((safe_rshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((l_2452 , (**l_2020)) , (safe_mod_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(0x497B, 0U)), (((safe_rshift_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(((((**l_2020) , (((((((((safe_add_func_int8_t_s_s(g_210.f8, (safe_rshift_func_uint16_t_u_u((~(1U < (((((void*)0 == &g_33[2]) == g_2054[3][1][0]) ^ l_2452) & 0x9DD8))), l_2443.f4)))) <= g_210.f0) < 0xA736BD57) > 0x4985) , l_2443) , (void*)0) == l_2466) || l_2467) , 0xE6)) < 0x78) > l_1363), 65535U)), l_1363)) < (*l_2366)) , l_1363)))), l_2467)), l_1363)), l_1363)) < 0U))
                    {
                        int32_t **l_2477 = (void*)0;
                        l_2470 = &g_33[4];
                        if (l_2443.f6)
                            continue;
                        return l_2478;



                    }
                    else
                    {
                        uint32_t l_2493[3][6];
                        int i, j;
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 6; j++)
                                l_2493[i][j] = 1U;
                        }
                        (*g_2221) = ((l_2452 & (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u(((((((safe_lshift_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((l_2452 , (safe_lshift_func_uint16_t_u_s(((safe_sub_func_int32_t_s_s((((((l_2493[0][4] && ((l_2452 <= (((safe_sub_func_int8_t_s_s(((safe_mul_func_int16_t_s_s(0x1FF6, ((g_210.f7 > g_210.f8) >= ((l_2498 == (void*)0) , (-1))))) , (*l_2470)), g_1031[3])) , (*(*p_52))) & 7)) > g_210.f0)) , (**l_2020)) , g_210.f8) && l_2452) , l_2499), 0x8ADDA95C)) , l_1363), 2))), l_1452)) | l_1363), l_1363)) ^ (*(*p_52))) >= 0x4B) || g_210.f0) == 0x09) , g_210.f1), 5)), 6)), 0))) , (*l_2470));
                    }
                    for (g_2647 = 4; (g_2647 < 59); g_2647++)
                    {
                        int32_t **l_2503 = &l_2366;

for (l_2370.f8 = 0; (l_2370.f8 <= (-11)); l_2370.f8 = safe_sub_func_uint32_t_u_u(l_2370.f8, 9))
    {
        struct S0 *l_46 = &l_2370;
        int32_t l_2567 = 5;
        struct S0 l_2635 = {146,1898,-222,140,56,-0,-298,38,0x28};
        int32_t l_2699[5] = {0x4100C087,0x4100C087,0x4100C087,0x4100C087,0x4100C087};
        int32_t ***l_2715 = &l_1608;
        int32_t *l_2725 = (void*)0;
        struct S0 ***l_2735 = (void*)0;
        int i;
    };


                    (*l_2503) = l_2478;

                        ((l_2366 == 0) ? (void) (0) : __assert_fail ("l_2366 == 0", "t.c", 4335, __PRETTY_FUNCTION__));
                        (*l_2503) = l_2504;

                        (((l_2366 >= &l_1167[0][0] && l_2366 <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("(l_2366 >= &l_1167[0][0] && l_2366 <= &l_1167[8][6])", "t.c", 4338, __PRETTY_FUNCTION__));
                        if ((**l_2503))
                            break;
                        (*g_2221) = (**l_2503);
                    }
                    (*(&(*(*p_52)))) = (safe_rshift_func_uint8_t_u_s(((((*(*p_52)) == ((safe_rshift_func_int16_t_s_s((0x81 < (l_1363 && ((0x79A0 && l_1363) || (((((l_1363 != ((4U != g_2647) ^ (safe_lshift_func_int16_t_s_s((-1), g_210.f8)))) == 0x7CB1) , g_210.f4) ^ 0x0273614A) , 1)))), g_1031[4])) ^ (*l_2470))) , (*l_2470)) > g_2351), l_1363));
                }
                if (((safe_sub_func_int8_t_s_s(((((*l_2504) != (l_1363 | ((0xDC21 < (2 != g_210.f2)) != ((safe_mul_func_uint16_t_u_u((((((((safe_unary_minus_func_int32_t_s(((l_1363 > (safe_lshift_func_int8_t_s_u((safe_div_func_uint16_t_u_u((safe_div_func_uint16_t_u_u(((void*)0 != &g_466), ((((*(*g_465)) , (*(&l_1608))) == &(*p_52)) && (*(*p_52))))), (*l_2504))), l_1363))) && g_210.f6))) != (*g_2221)) && 2U) >= l_1363) >= l_2522) != (*l_2366)) && l_1363), (*(&k)))) != (-1))))) && g_210.f4) , g_1031[1]), (*l_2504))) <= 0x3D))
                {
                    int32_t **l_2533 = &l_2366;
                    (*l_2533) = &g_11[0];

                    (((l_2366 >= &g_11[0] && l_2366 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_2366 >= &g_11[0] && l_2366 <= &g_11[0])", "t.c", 4350, __PRETTY_FUNCTION__));
                    (*(&(*(*p_52)))) = (((((((safe_rshift_func_uint8_t_u_u(((safe_mul_func_uint8_t_u_u(l_1363, (((safe_mod_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(g_210.f1, 5)), (safe_mul_func_uint16_t_u_u((~g_11[0]), ((!(safe_add_func_int32_t_s_s((((*(*p_52)) ^ (3U && (safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(((safe_div_func_uint16_t_u_u((&g_33[2] == &g_33[2]), g_2054[4][0][1])) || ((safe_rshift_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((((((*l_2020) != (void*)0) ^ 0xE254033A) | (**l_2533)) & l_1363), l_1363)), l_1363)) != 0x6629)), 13)), g_33[2])))) <= 0xD6B6E273), (*l_2504)))) | l_1363))))) , l_2558) , 9U))) , 0U), 1)) < l_2559[4]) == g_210.f5) >= 0xFF) >= g_210.f0) >= 0xEE71) >= 0xC4);
                }
                else
                {
                    int32_t **l_2560[2];
                    int i;

{
                    int32_t *l_2084 = &g_21;

l_2323 += 1;


                    return l_2504;




                }

                    for (i = 0; i < 2; i++)
                        l_2560[i] = &g_944[3][3][1];
                    (*p_52) = &j;

                    (((*p_52) == &j) ? (void) (0) : __assert_fail ("(*p_52) == &j", "t.c", 4375, __PRETTY_FUNCTION__));
                }
                (*g_2221) = (*(*p_52));
                for ((*(*p_52)) = 15; ((*(*p_52)) < 20); (*(*p_52))++)
                {

{
            (*l_1608) = &g_80;

            (((*l_1608) == &g_80) ? (void) (0) : __assert_fail ("(*l_1608) == &g_80", "t.c", 4384, __PRETTY_FUNCTION__));
        }

                    (**l_2020) = (*(*g_465));
                }
            }

            (((*p_52) == &j || ((*p_52) >= &g_33[0] && (*p_52) <= &g_33[4])) ? (void) (0) : __assert_fail ("(*p_52) == &j || ((*p_52) >= &g_33[0] && (*p_52) <= &g_33[4])", "t.c", 4391, __PRETTY_FUNCTION__));
            (((l_2366 >= &l_1167[0][0] && l_2366 <= &l_1167[8][6]) || (l_2366 >= &g_11[0] && l_2366 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_2366 >= &l_1167[0][0] && l_2366 <= &l_1167[8][6]) || (l_2366 >= &g_11[0] && l_2366 <= &g_11[0])", "t.c", 4392, __PRETTY_FUNCTION__));
            g_32[1] = l_2470;
            (*l_2564) = l_2563;
        }

        (((*p_52) == &j || ((*p_52) >= &g_33[0] && (*p_52) <= &g_33[4])) ? (void) (0) : __assert_fail ("(*p_52) == &j || ((*p_52) >= &g_33[0] && (*p_52) <= &g_33[4])", "t.c", 4397, __PRETTY_FUNCTION__));
        (((l_2366 >= &l_1167[0][0] && l_2366 <= &l_1167[8][6]) || (l_2366 >= &g_11[0] && l_2366 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_2366 >= &l_1167[0][0] && l_2366 <= &l_1167[8][6]) || (l_2366 >= &g_11[0] && l_2366 <= &g_11[0])", "t.c", 4398, __PRETTY_FUNCTION__));
        return l_2565[5];



    };


                    if (((((0xE670 < p_54) & (p_54 && (p_54 <= ((safe_add_func_uint8_t_u_u((((((safe_mod_func_int16_t_s_s(g_210.f5, (0U | ((safe_add_func_uint32_t_u_u((((safe_add_func_int32_t_s_s((!((2 || ((safe_rshift_func_uint8_t_u_u((safe_sub_func_int8_t_s_s(p_54, (safe_sub_func_int32_t_s_s((((4294967295U && l_2115.f6) , g_784[3]) != p_54), 0xC71B2F44)))), p_54)) | 4)) , g_210.f3)), (*p_50))) >= g_1484) | p_54), l_2164)) ^ p_54)))) == 0x31188911) , (*p_50)) > l_2115.f8) || p_54), g_1484)) , 0xEC623E69)))) | 0xB2DD) , 0xCB6594A1))
                    {
                        uint32_t l_2165 = 0x9E97B283;

{
                    if (((((0xE670 < g_2805) & (g_2805 && (g_2805 <= ((safe_add_func_uint8_t_u_u((((((safe_mod_func_int16_t_s_s(l_2370.f5, (0U | ((safe_add_func_uint32_t_u_u((((safe_add_func_int32_t_s_s((!((2 || ((safe_rshift_func_uint8_t_u_u((safe_sub_func_int8_t_s_s(g_2805, (safe_sub_func_int32_t_s_s((((4294967295U && g_210.f6) , g_784[3]) != g_2805), 0xC71B2F44)))), g_2805)) | 4)) , l_2370.f3)), (*g_148))) >= l_2350) | g_2805), (*g_148))) ^ g_2805)))) == 0x31188911) , (*g_148)) > g_210.f8) || g_2805), l_2350)) , 0xEC623E69)))) | 0xB2DD) , 0xCB6594A1))
                    {
                        uint32_t l_2165 = 0x9E97B283;
                        (*g_148) = (*g_148);
                        if (l_2165)
                            continue;
                    }
                    else
                    {
                        return g_148;




                    }
                }

                    (*p_50) = (*p_50);

if (((safe_sub_func_int32_t_s_s((safe_rshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((l_1904 , (**(&g_466))) , (safe_mod_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(0x497B, 0U)), (((safe_rshift_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(((((**(&g_466)) , (((((((((safe_add_func_int8_t_s_s((*g_466).f8, (safe_rshift_func_uint16_t_u_u((~(1U < (((((void*)0 == &g_33[2]) == g_2054[3][1][0]) ^ l_1904) & 0x9DD8))), g_210.f4)))) <= g_210.f0) < 0xA736BD57) > 0x4985) , g_210) , (void*)0) == (&l_1608)) || l_2165) , 0xE6)) < 0x78) > p_54), 65535U)), p_54)) < (*(&l_2003))) , p_54)))), l_2165)), p_54)), p_54)) < 0U))
                    {
                        int32_t **l_2477 = (void*)0;
                        (*p_52) = &g_33[4];
                        if (g_210.f6)
                            continue;

{
                    int32_t *l_1840 = &(*l_2437);

{
            uint32_t l_2467 = 0xE6B0EF31;
            int32_t *l_2470 = &g_33[2];
            struct S0 l_2558 = {88,7141,234,1173,28,-0,-1034,196,1};
            int16_t l_2559[6] = {0x641F,0x641F,0x91BC,0x641F,0x641F,0x91BC};
            int32_t *l_2563 = &g_33[3];
            int32_t **l_2564 = &g_32[1];
            int i;
            for (l_991 = 27; (l_991 <= 8); --l_991)
            {
                int16_t l_2452 = 0x9563;
                int8_t l_2499 = 1;
                int32_t *l_2504 = &l_1167[6][6];
                for (g_27.f8 = 0; (g_27.f8 == 2); g_27.f8 = safe_add_func_int8_t_s_s(g_27.f8, 6))
                {
                    struct S0 l_2443 = {534,2588,69,470,37,-0,1036,319,-9};
                    uint32_t l_2476 = 4294967295U;
                    int32_t *l_2478 = (void*)0;
                    struct S0 ***l_2498 = &(*l_1828);
                    l_2443 = (**(*l_1828));
                    if (((safe_sub_func_int32_t_s_s((safe_rshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((l_2452 , (**(*l_1828))) , (safe_mod_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(0x497B, 0U)), (((safe_rshift_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(((((**(*l_1828)) , (((((((((safe_add_func_int8_t_s_s(g_210.f8, (safe_rshift_func_uint16_t_u_u((~(1U < (((((void*)0 == &g_33[2]) == g_2054[3][1][0]) ^ l_2452) & 0x9DD8))), l_2443.f4)))) <= g_210.f0) < 0xA736BD57) > 0x4985) , l_2443) , (void*)0) == (&p_52)) || l_2467) , 0xE6)) < 0x78) > l_2061), 65535U)), l_2061)) < (*g_148)) , l_2061)))), l_2467)), l_2061)), l_2061)) < 0U))
                    {
                        int32_t **l_2477 = (void*)0;
                        l_2470 = &g_33[4];
                        if (l_2443.f6)
                            continue;
                        return l_2478;



                    }
                    else
                    {
                        uint32_t l_2493[3][6];
                        int i, j;
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 6; j++)
                                l_2493[i][j] = 1U;
                        }
                        (*(*l_1608)) = ((l_2452 & (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u(((((((safe_lshift_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((l_2452 , (safe_lshift_func_uint16_t_u_s(((safe_sub_func_int32_t_s_s((((((l_2493[0][4] && ((l_2452 <= (((safe_sub_func_int8_t_s_s(((safe_mul_func_int16_t_s_s(0x1FF6, ((g_210.f7 > g_210.f8) >= ((l_2498 == (void*)0) , (-1))))) , (*l_2470)), g_1031[3])) , (*l_1840)) & 7)) > g_210.f0)) , (**(*l_1828))) , g_210.f8) && l_2452) , l_2499), 0x8ADDA95C)) , l_2061), 2))), l_2323)) | l_2061), l_2061)) ^ (*l_1840)) >= 0x4B) || g_210.f0) == 0x09) , g_210.f1), 5)), 6)), 0))) , (*l_2470));
                    }
                    for (l_2108 = 4; (l_2108 < 59); l_2108++)
                    {
                        int32_t **l_2503 = &g_148;
                        (*l_2503) = l_2478;

                        ((g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == 0", "t.c", 4487, __PRETTY_FUNCTION__));
                        (*l_2503) = l_2504;

                        (((g_148 >= &l_1167[0][0] && g_148 <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("(g_148 >= &l_1167[0][0] && g_148 <= &l_1167[8][6])", "t.c", 4490, __PRETTY_FUNCTION__));
                        if ((**l_2503))
                            break;
                        (*(*p_51)) = (**l_2503);
                    }
                    (*(*p_52)) = (safe_rshift_func_uint8_t_u_s(((((*l_1840) == ((safe_rshift_func_int16_t_s_s((0x81 < (l_2061 && ((0x79A0 && l_2061) || (((((l_2061 != ((4U != l_2108) ^ (safe_lshift_func_int16_t_s_s((-1), g_210.f8)))) == 0x7CB1) , g_210.f4) ^ 0x0273614A) , 1)))), g_1031[4])) ^ (*l_2470))) , (*l_2470)) > l_1597), l_2061));
                }
                if (((safe_sub_func_int8_t_s_s(((((*l_2504) != (l_2061 | ((0xDC21 < (2 != g_210.f2)) != ((safe_mul_func_uint16_t_u_u((((((((safe_unary_minus_func_int32_t_s(((l_2061 > (safe_lshift_func_int8_t_s_u((safe_div_func_uint16_t_u_u((safe_div_func_uint16_t_u_u(((void*)0 != &(*g_465)), ((((*g_466) , (*(&p_51))) == &l_1840) && (*l_1840)))), (*l_2504))), l_2061))) && g_210.f6))) != l_2164) && 2U) >= l_2061) >= l_2061) != (*g_148)) && l_2061), (*(&g_1240)))) != (-1))))) && g_210.f4) , g_1031[1]), (*l_2504))) <= 0x3D))
                {
                    int32_t **l_2533 = &g_148;
                    (*l_2533) = &g_11[0];

                    (((g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("(g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 4502, __PRETTY_FUNCTION__));
                    (*(*p_52)) = (((((((safe_rshift_func_uint8_t_u_u(((safe_mul_func_uint8_t_u_u(l_2061, (((safe_mod_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(g_210.f1, 5)), (safe_mul_func_uint16_t_u_u((~g_11[0]), ((!(safe_add_func_int32_t_s_s((((*l_1840) ^ (3U && (safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(((safe_div_func_uint16_t_u_u((&g_33[2] == &g_33[2]), g_2054[4][0][1])) || ((safe_rshift_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((((((*(*l_1828)) != (void*)0) ^ 0xE254033A) | (**l_2533)) & l_2061), l_2061)), l_2061)) != 0x6629)), 13)), g_33[2])))) <= 0xD6B6E273), (*l_2504)))) | l_2061))))) , l_2558) , 9U))) , 0U), 1)) < l_2559[4]) == g_210.f5) >= 0xFF) >= g_210.f0) >= 0xEE71) >= 0xC4);
                }
                else
                {
                    int32_t **l_2560[2];
                    int i;
                    for (i = 0; i < 2; i++)
                        l_2560[i] = &g_944[3][3][1];
                    l_1840 = &(*l_1850);

                    ((l_1840 == &(*l_1850)) ? (void) (0) : __assert_fail ("l_1840 == &(*l_1850)", "t.c", 4513, __PRETTY_FUNCTION__));
                }
                (*(*p_51)) = (*l_1840);
                for (i = 15; (i < 20); i++)
                {
                    (**(*l_1828)) = (*g_466);
                }
            }

            ((l_1840 == &(*l_1850) || (l_1840 >= &g_33[0] && l_1840 <= &g_33[4])) ? (void) (0) : __assert_fail ("l_1840 == &(*l_1850) || (l_1840 >= &g_33[0] && l_1840 <= &g_33[4])", "t.c", 4522, __PRETTY_FUNCTION__));
            (((g_148 >= &l_1167[0][0] && g_148 <= &l_1167[8][6]) || (g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("(g_148 >= &l_1167[0][0] && g_148 <= &l_1167[8][6]) || (g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 4523, __PRETTY_FUNCTION__));
            g_32[1] = l_2470;
            (*l_2564) = l_2563;
        }

                    for (l_1811 = 22; (l_1811 == (-3)); l_1811 = safe_sub_func_int32_t_s_s(l_1811, 1))
                    {
                        uint8_t l_1841 = 0xAC;
                        (*(&l_2291)) = l_1840;
                        (**l_2020) = (*(*g_465));
                        (*(&l_2291)) = &g_11[0];
                        g_148 = (*g_297);

                        ((g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == 0", "t.c", 4536, __PRETTY_FUNCTION__));
                    }

                    ((g_148 == 0 || (g_148 >= &g_33[0] && g_148 <= &g_33[4])) ? (void) (0) : __assert_fail ("g_148 == 0 || (g_148 >= &g_33[0] && g_148 <= &g_33[4])", "t.c", 4539, __PRETTY_FUNCTION__));
                    for (g_2351 = 23; (g_2351 >= 1); g_2351--)
                    {
                        int8_t l_1862 = 2;
                        (*(&l_2291)) = (((*l_1840) & ((+((safe_unary_minus_func_uint32_t_u((g_2956 | ((((safe_div_func_int16_t_s_s((safe_div_func_uint8_t_u_u(((l_1862 >= ((safe_mul_func_int8_t_s_s((g_80 , (((safe_mul_func_int8_t_s_s(((*(*g_297)) | ((safe_mul_func_int16_t_s_s((safe_lshift_func_int8_t_s_s((-2), ((l_2061 || (safe_rshift_func_int16_t_s_s(0x5560, 5))) | 1))), l_1862)) == l_2061)), 0x3C)) , 0U) < (*(*g_465)).f6)), 0)) ^ (*(*g_465)).f8)) , l_2061), 0x04)), 0xF8B9)) | (*(*g_465)).f6) < 0xDE83) && 0U)))) , g_2956)) >= 0x8A4328FC)) , (*g_297));
                        (**g_465) = (((void*)0 == (&g_465)) , (((l_1828 == ((*l_1082) , &g_465)) == l_2061) , (*(*g_465))));
                        (**l_2020) = ((*(*g_297)) , (**l_2020));

if ((safe_sub_func_int16_t_s_s(l_2500, ((safe_div_func_uint16_t_u_u(((safe_rshift_func_uint8_t_u_u(((((g_11[0] == ((safe_mod_func_int8_t_s_s((((((((((l_2115 , (safe_div_func_int32_t_s_s((safe_rshift_func_uint16_t_u_u(((((safe_sub_func_int16_t_s_s((g_2805 >= ((&(*g_296) != ((*g_148) , (void*)0)) | l_1122)), (safe_lshift_func_uint8_t_u_s((((safe_sub_func_int8_t_s_s(((g_2805 , (*l_1431)) == (*g_465)), (*(&g_2803)))) <= l_2115.f3) < g_2805), 5)))) && g_2805) < 0) , l_1904), 7)), l_2115.f8))) & 1) >= g_2805) | g_1271[2][1]) != (*g_148)) < 0xBB) | 255U) != (*(*l_1431)).f7) , (-1)), 247U)) >= g_1031[2])) , 5U) | 0xD112) | (*l_2437)), 4)) != (*l_2437)), l_2115.f5)) && 0x009A5A65))))
                {
                    for (l_1122 = (-17); (l_1122 == 60); l_1122 = safe_add_func_uint8_t_u_u(l_1122, 6))
                    {
                        int32_t *l_2133 = &g_11[0];
                        uint16_t l_2139 = 0x3C07;
                        (*l_2437) = ((safe_lshift_func_uint16_t_u_s(((((g_2054[7][0][0] , ((safe_unary_minus_func_int8_t_s((l_2133 != &g_2956))) | ((*l_2133) || ((((safe_add_func_uint8_t_u_u(g_2805, ((*(*l_1431)).f4 >= ((+(safe_div_func_int8_t_s_s(((((0xDA && ((&l_2437 != (*l_1508)) , l_2139)) == 0x8C50) && g_2805) , (-1)), g_1271[1][1]))) && (*l_2133))))) || g_27.f5) , (*(*l_1431)).f7) , l_1122)))) , (-1)) ^ 0x68) & (*l_2133)), g_27.f1)) | 0U);
                        (*(&l_1645)) = (((safe_mul_func_int16_t_s_s((safe_sub_func_int32_t_s_s((g_2805 , l_2115.f2), (safe_mul_func_uint16_t_u_u((l_2146[3] , 65526U), ((safe_lshift_func_uint8_t_u_s((0x2E & (*l_2133)), 2)) , (*(*l_1431)).f5))))), (g_1271[2][1] | 0xD006))) < l_1181) , l_2133);
                        (**(&(*g_465))) = (*(*l_1431));
                    }
                }
                else
                {
                    if (((((0xE670 < g_2805) & (g_2805 && (g_2805 <= ((safe_add_func_uint8_t_u_u((((((safe_mod_func_int16_t_s_s((*(*l_1431)).f5, (0U | ((safe_add_func_uint32_t_u_u((((safe_add_func_int32_t_s_s((!((2 || ((safe_rshift_func_uint8_t_u_u((safe_sub_func_int8_t_s_s(g_2805, (safe_sub_func_int32_t_s_s((((4294967295U && l_2115.f6) , g_784[3]) != g_2805), 0xC71B2F44)))), g_2805)) | 4)) , (*(*l_1431)).f3)), (*l_2437))) >= l_1122) | g_2805), k)) ^ g_2805)))) == 0x31188911) , (*l_2437)) > l_2115.f8) || g_2805), l_1122)) , 0xEC623E69)))) | 0xB2DD) , 0xCB6594A1))
                    {
                        uint32_t l_2165 = 0x9E97B283;
                        (*l_2437) = (*l_2437);
                        if (l_2165)
                            continue;
                    }
                    else
                    {
                        return l_2437;




                    }
                };


                    return (*(&l_2291));



                    }
                    (*g_297) = &g_2956;

                    (((*g_297) == &g_2956) ? (void) (0) : __assert_fail ("(*g_297) == &g_2956", "t.c", 4585, __PRETTY_FUNCTION__));
                }

                    return (&g_21);



                    }
                    else
                    {
                        uint32_t l_2493[3][6];
                        int i, j;
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 6; j++)
                                l_2493[i][j] = 1U;
                        }
                        (*l_1645) = ((l_1904 & (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u(((((((safe_lshift_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((l_1904 , (safe_lshift_func_uint16_t_u_s(((safe_sub_func_int32_t_s_s((((((l_2493[0][4] && ((l_1904 <= (((safe_sub_func_int8_t_s_s(((safe_mul_func_int16_t_s_s(0x1FF6, ((g_210.f7 > (*g_466).f8) >= ((l_1828 == (void*)0) , (-1))))) , (*(*p_52))), g_1031[3])) , (*(*p_52))) & 7)) > g_210.f0)) , (**(&g_466))) , g_210.f8) && l_1904) , l_1631), 0x8ADDA95C)) , p_54), 2))), l_2500)) | p_54), p_54)) ^ (*(*p_52))) >= 0x4B) || (*g_466).f0) == 0x09) , (*g_466).f1), 5)), 6)), 0))) , (*(*p_52)));
                    };


                    if (l_2165)
                            continue;
                    }
                    else
                    {
                        return p_50;




                    }
                }
            }
        }


        ((l_1082 == 0 || (l_1082 >= &g_33[0] && l_1082 <= &g_33[4])) ? (void) (0) : __assert_fail ("l_1082 == 0 || (l_1082 >= &g_33[0] && l_1082 <= &g_33[4])", "t.c", 4622, __PRETTY_FUNCTION__));
        ((l_1431 == 0 || l_1431 == &g_466) ? (void) (0) : __assert_fail ("l_1431 == 0 || l_1431 == &g_466", "t.c", 4623, __PRETTY_FUNCTION__));
        if ((((0x105C1531 >= ((((safe_unary_minus_func_int8_t_s((g_27.f4 >= (safe_mul_func_uint16_t_u_u(l_2169[5][4][0], g_27.f4))))) && ((((g_1271[1][2] , (safe_sub_func_uint8_t_u_u((0U <= (*l_1645)), (((safe_lshift_func_uint16_t_u_s((((safe_mul_func_uint8_t_u_u(p_54, (&p_50 == (void*)0))) & p_54) >= 0xE3EF), 4)) != p_54) > (*l_1412))))) , (*l_1645)) || 8) ^ p_54)) & g_27.f0) != l_2176[0])) == p_54) || g_1271[0][3]))
        {
            int8_t l_2206 = 0x56;
            int32_t *l_2218[2][4] = {{&g_11[0],&g_33[2],&g_11[0],&g_11[0]},{&g_33[2],&g_33[2],&l_1167[2][4],&g_33[2]}};
            int8_t l_2237 = 8;
            struct S0 l_2275 = {744,5810,31,1053,134,-0,1051,335,0x6F};
            int i, j;
            for (l_2003 = 8; (l_2003 < 12); l_2003 = safe_add_func_uint32_t_u_u(l_2003, 4))
            {
                uint32_t l_2179 = 0U;
                int32_t *l_2211 = &g_11[0];
                if ((l_2179 || p_54))
                {
                    int8_t l_2198 = 8;

if (g_33[g_2318])
                            break;

                    for (g_210.f8 = 15; (g_210.f8 == (-8)); g_210.f8 = safe_sub_func_uint32_t_u_u(g_210.f8, 2))
                    {
                        int32_t l_2197 = 0xCAD7CAE7;
                        (*p_50) = (*p_50);
                        (*p_50) = (7 & ((safe_div_func_int16_t_s_s((((p_54 == p_54) > (0x12B8 <= 0x6CA9)) <= (((safe_div_func_uint8_t_u_u(((safe_mul_func_int8_t_s_s((((((safe_lshift_func_uint16_t_u_u((safe_div_func_int16_t_s_s((-3), 2U)), (((!l_2179) == ((((safe_mul_func_int8_t_s_s((safe_mul_func_int8_t_s_s((p_54 || l_2179), p_54)), l_2197)) | 65531U) > (-3)) | l_2198)) | g_33[0]))) & 0x44) & p_54) != p_54) && 0xC4906F4E), 0xC7)) & g_21), p_54)) <= p_54) , p_54)), 0x1AA4)) || 4U));
                        (*l_1608) = &l_2197;


                    }

{
                        uint32_t l_2243 = 0x1478837A;
                        l_2243 = 0x168497EF;
                    }

                    for (l_1986 = (-24); (l_1986 < 5); l_1986++)
                    {

if ((((safe_mul_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((void*)0 == (*l_1831)), ((g_1271[2][1] != ((((p_54 & (safe_add_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u(((((safe_mod_func_uint16_t_u_u(((((*p_53) , l_2198) , (void*)0) != (void*)0), (safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(0x692C583B, 0x083CD9AE)), p_54)))) , (void*)0) != l_1508) , (*p_53).f5), g_1031[4])) , l_2212) != l_2212), p_54))) > p_54) == p_54) ^ g_33[2])) >= 0x24))), 0xD203)) <= p_54) & 0xCB))
            {
                int16_t l_2385 = 1;
                int32_t l_2386[9][3][9] = {{{0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0,(-5),0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0},{1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11},{0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46}},{{0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7},{0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46},{0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11,0xD11FB6A6,0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11}},{{0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0},{0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6},{0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2}},{{1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6},{0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0,(-5),0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0},{1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11}},{{0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46},{0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7},{0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46}},{{0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11,0xD11FB6A6,0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11},{0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5)},{0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7}},{{0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0},{0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7},{0x18DF85E2,0x15E3D6FB,(-5),(-5),0x15E3D6FB,0x18DF85E2,0x15E3D6FB,(-5),(-5)}},{{0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6},{0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2},{0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11}},{{0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2},{0x412DFEB7,1,0xD11FB6A6,0xD11FB6A6,1,0x412DFEB7,1,0xD11FB6A6,0xD11FB6A6},{0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5)}}};
                int32_t ***l_2414 = &p_51;
                int i, j, k;
                for (g_1240 = 4; (g_1240 >= (-19)); --g_1240)
                {
                    int32_t l_2384[2][6][6] = {{{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0}},{{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0}}};
                    int32_t *l_2416 = &g_33[2];
                    int i, j, k;
                    if ((*g_2221))
                    {
                        struct S0 *l_2369[9][1];
                        int32_t l_2381 = (-1);
                        int i, j;
                        for (i = 0; i < 9; i++)
                        {
                            for (j = 0; j < 1; j++)
                                l_2369[i][j] = (void*)0;
                        }
                        (*l_2212) = (l_2369[8][0] == p_53);
                        g_210 = ((*p_53).f0 , (*(*l_1431)));

if ((safe_rshift_func_int8_t_s_s(l_1052, (safe_rshift_func_int16_t_s_u((((*l_1850) && 0xBB07A94C) <= ((!(((*g_466).f8 != (((((safe_mul_func_uint16_t_u_u(((&p_53 == (((void*)0 == p_53) , g_465)) || (((void*)0 != l_1828) || l_1052)), 0x9F3C)) , (*g_466).f3) >= l_1052) > l_1052) & l_1052)) < g_2351)) > l_1052)), 3)))))
                    {
                        (*(*g_296)) = l_2034[1][8][1];
                    }
                    else
                    {
                        struct S0 **l_2035 = &g_466;
                        int32_t *l_2037 = (void*)0;
                        (*(*g_296)) = l_1850;
                        (*l_1850) = (&g_466 != l_2035);
                        l_2037 = l_1082;

                        (((l_2037 >= &g_33[0] && l_2037 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_2037 >= &g_33[0] && l_2037 <= &g_33[4])", "t.c", 4696, __PRETTY_FUNCTION__));
                    };


                    (*(&g_80)) = (safe_mod_func_int32_t_s_s(((safe_div_func_uint32_t_u_u(((safe_mul_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_s((((l_2381 & p_54) | ((((l_1508 != (void*)0) == g_2054[0][0][1]) , (&k)) == ((*g_2221) , g_2221))) , p_54), (*(&k)))), 3)), (*l_2211))) ^ l_2384[0][4][4]), l_2385)) != l_2386[5][2][8]), l_2386[1][0][7]));
                    }
                    else
                    {
                        int32_t l_2413 = 0x35119CD0;
                        uint8_t l_2415 = 2U;
                        (*l_2212) = (*g_2221);
                        (*(&k)) = (safe_mul_func_uint8_t_u_u(((((g_784[3] > (((((l_1217.f4 >= (safe_rshift_func_uint8_t_u_u((!(safe_sub_func_uint16_t_u_u((((((*p_53).f2 && 248U) >= (!((safe_div_func_uint32_t_u_u(1U, ((((safe_lshift_func_int8_t_s_s((safe_mul_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_s(1U, (safe_add_func_int8_t_s_s((safe_mul_func_int16_t_s_s(l_1217.f0, (safe_rshift_func_int16_t_s_s(l_2413, 12)))), (((void*)0 == l_2414) , l_2384[0][4][4]))))) , l_2415), 3)), 0xB4AC)), (*l_2212))) & g_33[2]) != 1U) , (*g_2221)))) > p_54))) , l_2384[0][4][5]) ^ g_33[2]), g_2054[7][0][1]))), 0))) , 0xCE1E) == g_784[3]) , 0xB4BE) == l_1009)) <= p_54) , (-4)) || g_784[3]), (-10)));
                    }
                    return l_2416;



                }
                for (l_2179 = 1; (l_2179 > 38); ++l_2179)
                {
                    int32_t *l_2419 = &g_11[0];
                    return l_2419;



                }
                (*(&g_80)) = (*g_2221);
            }
            else
            {
                struct S0 **l_2428 = &(*l_1431);
                int32_t l_2438[9][9] = {{0xA15E527E,(-10),(-8),(-10),0xA15E527E,(-8),0x01077C09,0x01077C09,(-8)},{0xA15E527E,(-10),(-8),(-10),0xA15E527E,(-8),0x01077C09,0x01077C09,(-8)},{0xA15E527E,(-10),(-8),(-10),0xA15E527E,(-8),0x01077C09,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09}};
                int i, j;
                (*(&g_80)) = (((safe_mul_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u((((((void*)0 != &p_51) , (&k)) == &l_2438[5][1]) , l_1217.f4), 1)) > (*p_53).f0), 0x5D)), (-5))) > l_2438[2][3]) , 0xD350549E);
                (*l_2212) = 0x5CE0142A;
            };


                    (*g_466) = ((*p_53) , (((((((safe_div_func_int8_t_s_s((-1), ((g_27.f5 | p_54) || (safe_lshift_func_int16_t_s_u((safe_unary_minus_func_int8_t_s(((l_2206 , (l_2179 , ((safe_mod_func_int32_t_s_s(((((0x32A1 || (g_1031[0] >= (safe_div_func_uint8_t_u_u((g_27.f3 | (-10)), 252U)))) && l_2198) , l_2179) <= 0U), 0xCF49745F)) >= g_11[0]))) <= 7))), 3))))) >= l_2179) == l_2179) < p_54) < (*p_50)) >= 0U) , (*p_53)));

if ((safe_rshift_func_int8_t_s_s(g_2805, (safe_rshift_func_int16_t_s_u((((*g_148) && 0xBB07A94C) <= ((!((l_2105.f8 != (((((safe_mul_func_uint16_t_u_u(((&(*g_465) == (((void*)0 == (*g_465)) , l_1831)) || (((void*)0 != (&l_1831)) || g_2805)), 0x9F3C)) , l_2105.f3) >= g_2805) > g_2805) & g_2805)) < g_1484)) > g_2805)), 3)))))
                    {
                        (*l_1608) = l_2034[1][8][1];
                    }
                    else
                    {
                        struct S0 **l_2035 = &(*l_1431);
                        int32_t *l_2037 = (void*)0;
                        (*l_1608) = l_1850;
                        (*l_1850) = (&(*l_1431) != l_2035);
                        l_2037 = (&l_1706);

                        (((l_2037 >= &g_33[0] && l_2037 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_2037 >= &g_33[0] && l_2037 <= &g_33[4])", "t.c", 4748, __PRETTY_FUNCTION__));
                    };


                    l_2212 = l_2211;

                        (((l_2212 >= &g_11[0] && l_2212 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_2212 >= &g_11[0] && l_2212 <= &g_11[0])", "t.c", 4754, __PRETTY_FUNCTION__));
                    }
                }
                else
                {
                    int32_t l_2215 = (-9);
                    for (g_1094 = (-17); (g_1094 < 49); g_1094 = safe_add_func_uint8_t_u_u(g_1094, 6))
                    {
                        int8_t l_2217 = 2;
                        if (l_2215)
                            break;
                        l_2217 = (~0U);
                    }
                    (*l_1828) = &p_53;

                    ((l_1431 == &p_53) ? (void) (0) : __assert_fail ("l_1431 == &p_53", "t.c", 4769, __PRETTY_FUNCTION__));
                    l_2218[0][1] = (void*)0;
                }
            }


            ((l_1431 == &p_53 || l_1431 == 0 || l_1431 == &g_466) ? (void) (0) : __assert_fail ("l_1431 == &p_53 || l_1431 == 0 || l_1431 == &g_466", "t.c", 4775, __PRETTY_FUNCTION__));
            (((l_2212 >= &g_11[0] && l_2212 <= &g_11[0]) || l_2212 == 0) ? (void) (0) : __assert_fail ("(l_2212 >= &g_11[0] && l_2212 <= &g_11[0]) || l_2212 == 0", "t.c", 4776, __PRETTY_FUNCTION__));

            (**g_465) = (*p_53);
            for (l_1735 = (-3); (l_1735 != (-21)); l_1735 = safe_sub_func_uint16_t_u_u(l_1735, 1))
            {
                uint32_t l_2238 = 4294967295U;
                int32_t l_2257 = 0xEE87F0FB;
                struct S0 ***l_2274 = &l_1831;
                (*l_1608) = g_2221;
                for (g_1240 = 5; (g_1240 != (-4)); --g_1240)
                {
                    uint16_t l_2236 = 0x7F4B;

for (l_1181 = 0; (l_1181 <= 2); l_1181 += 1)
        {
            int i;
            if (l_1986)
                break;
        };



for (l_1855 = 0; l_1855 < 6; l_1855++)
                                g_1271[l_1735][l_1855] = 1U;


for ((*l_1645) = 0; ((*l_1645) > (-15)); (*l_1645) = safe_sub_func_int32_t_s_s((*l_1645), 1))
        {
            uint16_t l_2954 = 0xBB7C;
            struct S0 **l_2955 = (void*)0;
            (*(&l_1706)) = 0x64EAFE29;
            for (l_1363 = 0; (l_1363 <= 3); l_1363 += 1)
            {
                struct S0 ***l_2957 = &g_2531[1][1];
                int16_t l_2958 = 0x8258;
                int i, j, k;
            }
        };


                    if ((((safe_mul_func_int16_t_s_s(((safe_mul_func_int8_t_s_s((((((safe_rshift_func_uint16_t_u_s((((*g_296) == (*g_296)) < (safe_mod_func_uint8_t_u_u(0xB1, p_54))), p_54)) != ((safe_mod_func_int16_t_s_s(((((g_1484 , (*p_53)) , p_54) != ((safe_mul_func_int8_t_s_s(l_2236, g_27.f4)) , p_54)) != 1U), p_54)) , g_210.f1)) & l_2237) <= (-2)) || 1U), 9U)) < p_54), g_27.f6)) & p_54) , l_2236))
                    {
                        uint32_t l_2241 = 0U;
                        struct S0 l_2242 = {718,7833,20,468,426,1,-754,198,-1};
                        (**l_1831) = (*p_53);

{
                        int32_t **l_2503 = &(*g_297);

{
                    struct S0 l_2443 = {534,2588,69,470,37,-0,1036,319,-9};
                    uint32_t l_2476 = 4294967295U;
                    int32_t *l_2478 = (void*)0;
                    struct S0 ***l_2498 = &g_465;
                    l_2443 = (**g_465);
                    if (((safe_sub_func_int32_t_s_s((safe_rshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((g_2619 , (**g_465)) , (safe_mod_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(0x497B, 0U)), (((safe_rshift_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(((((**g_465) , (((((((((safe_add_func_int8_t_s_s(l_2275.f8, (safe_rshift_func_uint16_t_u_u((~(1U < (((((void*)0 == &g_33[2]) == g_2054[3][1][0]) ^ g_2619) & 0x9DD8))), l_2443.f4)))) <= (*p_53).f0) < 0xA736BD57) > 0x4985) , l_2443) , (void*)0) == g_296) || l_2323) , 0xE6)) < 0x78) > p_54), 65535U)), p_54)) < (*l_2291)) , p_54)))), l_2323)), p_54)), p_54)) < 0U))
                    {
                        int32_t **l_2477 = (void*)0;
                        l_2291 = &g_33[4];
                        if (l_2443.f6)
                            continue;
                        return l_2478;



                    }
                    else
                    {
                        uint32_t l_2493[3][6];
                        int i, j;
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 6; j++)
                                l_2493[i][j] = 1U;
                        }
                        (*(&k)) = ((g_2619 & (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u(((((((safe_lshift_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((g_2619 , (safe_lshift_func_uint16_t_u_s(((safe_sub_func_int32_t_s_s((((((l_2493[0][4] && ((g_2619 <= (((safe_sub_func_int8_t_s_s(((safe_mul_func_int16_t_s_s(0x1FF6, (((*p_53).f7 > l_2275.f8) >= ((l_2498 == (void*)0) , (-1))))) , (*l_2291)), g_1031[3])) , (*l_2212)) & 7)) > (*p_53).f0)) , (**g_465)) , (*p_53).f8) && g_2619) , l_2237), 0x8ADDA95C)) , p_54), 2))), g_2318)) | p_54), p_54)) ^ (*l_2212)) >= 0x4B) || l_2275.f0) == 0x09) , l_2275.f1), 5)), 6)), 0))) , (*l_2291));
                    }
                    for (g_2318 = 4; (g_2318 < 59); g_2318++)
                    {
                        int32_t **l_2503 = &l_2291;
                        (*l_2503) = l_2478;

                        ((l_2291 == 0) ? (void) (0) : __assert_fail ("l_2291 == 0", "t.c", 4858, __PRETTY_FUNCTION__));
                        (*l_2503) = l_2212;

                        (((l_2291 >= &l_1167[0][0] && l_2291 <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("(l_2291 >= &l_1167[0][0] && l_2291 <= &l_1167[8][6])", "t.c", 4861, __PRETTY_FUNCTION__));
                        if ((**l_2503))
                            break;
                        (*(&l_1855)) = (**l_2503);
                    }
                    (*(&i)) = (safe_rshift_func_uint8_t_u_s(((((*l_2212) == ((safe_rshift_func_int16_t_s_s((0x81 < (p_54 && ((0x79A0 && p_54) || (((((p_54 != ((4U != g_2318) ^ (safe_lshift_func_int16_t_s_s((-1), l_2275.f8)))) == 0x7CB1) , l_2275.f4) ^ 0x0273614A) , 1)))), g_1031[4])) ^ (*l_2291))) , (*l_2291)) > g_1484), p_54));
                }

                    (*l_2503) = (&l_2257);

                        (((*g_297) == 0) ? (void) (0) : __assert_fail ("(*g_297) == 0", "t.c", 4871, __PRETTY_FUNCTION__));

{
            struct S0 *l_107 = &l_2105;
            (*l_107) = l_2105;
            (*l_107) = ((**l_1608) , (*p_53));
        }

                    (*l_2503) = (*g_297);

                        ((((*g_297) >= &l_1167[0][0] && (*g_297) <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("((*g_297) >= &l_1167[0][0] && (*g_297) <= &l_1167[8][6])", "t.c", 4881, __PRETTY_FUNCTION__));
                        if ((**l_2503))
                            break;
                        (*(&g_21)) = (**l_2503);
                    }

                    if (l_2238)
                            break;
                        (**l_1831) = (((g_1484 ^ 0) , l_2241) , l_2242);
                        (*l_1412) = (p_54 , 0xA5E0E56F);
                    }
                    else
                    {
                        uint32_t l_2243 = 0x1478837A;

if (l_2003) printf("index = [%d][%d][%d]\n", l_1811, g_2956, (*l_1645));

                    l_2243 = 0x168497EF;
                    }
                    if ((*p_50))
                        continue;
                    if ((*p_50))
                        break;
                    for (g_210.f8 = 17; (g_210.f8 >= (-22)); g_210.f8 = safe_sub_func_int32_t_s_s(g_210.f8, 7))
                    {

for (l_2275.f8 = 15; (l_2275.f8 == (-8)); l_2275.f8 = safe_sub_func_uint32_t_u_u(l_2275.f8, 2))
                    {
                        int32_t l_2197 = 0xCAD7CAE7;
                        (*(&g_1240)) = (*(&g_1240));
                        (*(&g_1240)) = (7 & ((safe_div_func_int16_t_s_s((((g_2805 == g_2805) > (0x12B8 <= 0x6CA9)) <= (((safe_div_func_uint8_t_u_u(((safe_mul_func_int8_t_s_s((((((safe_lshift_func_uint16_t_u_u((safe_div_func_int16_t_s_s((-3), 2U)), (((!l_2500) == ((((safe_mul_func_int8_t_s_s((safe_mul_func_int8_t_s_s((g_2805 || l_2500), g_2805)), l_2197)) | 65531U) > (-3)) | l_2206)) | g_33[0]))) & 0x44) & g_2805) != g_2805) && 0xC4906F4E), 0xC7)) & l_2003), g_2805)) <= g_2805) , g_2805)), 0x1AA4)) || 4U));
                        (*(&l_1412)) = &l_2197;


                    };


                    (*g_2221) = (((safe_rshift_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_u(((safe_unary_minus_func_int8_t_s(((g_2054[7][0][1] , (!(*g_2221))) < (safe_sub_func_uint8_t_u_u(g_27.f4, 0xD7))))) | (l_2236 & (-8))), g_210.f1)) && (safe_sub_func_uint32_t_u_u(((g_27.f5 > (~l_2236)) , p_54), p_54))), g_2054[7][0][1])) == l_2257) < p_54);
                        (*l_1645) = ((safe_mod_func_uint32_t_u_u(((((safe_mul_func_int16_t_s_s(p_54, (((p_54 | (safe_add_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_u((-9), g_210.f4)) , ((safe_sub_func_uint8_t_u_u((((*l_1645) || (safe_rshift_func_uint8_t_u_s((g_33[2] & (p_54 != (0x9C > (((l_2238 == p_54) != g_1240) , p_54)))), p_54))) != p_54), p_54)) && (*p_50))), l_2236))) , (void*)0) != l_2274))) <= 0) & p_54) & p_54), 0x51332F8E)) ^ g_27.f5);
                        l_2275 = (*p_53);
                    }
                }
                (*g_2221) = (l_2257 ^ (&g_33[2] == ((*g_466) , &g_33[4])));
            }
            (*l_1645) = 0x04A65864;
        }
        else
        {
            uint32_t l_2279 = 0xB32EDEE1;
            int32_t *l_2290 = &l_1167[8][1];
            for (g_80 = 0; (g_80 > 12); g_80++)
            {
                int32_t *l_2280 = &l_1811;
                for (l_1597 = 0; (l_1597 <= 3); l_1597 += 1)
                {
                    int32_t l_2283 = 0xE2C51E0A;
                    if (((void*)0 == &g_297))
                    {
                        int i;
                        if (l_1806[l_1597])
                            break;
                        if (g_784[l_1597])
                            break;
                        (**g_465) = (**g_465);
                    }
                    else
                    {
                        uint8_t l_2278[8] = {0x98,0U,0x98,0U,0x98,0U,0x98,0U};
                        int i;
                        (*l_1412) = l_2278[3];
                        p_50 = l_2280;

                        ((p_50 == &l_1811) ? (void) (0) : __assert_fail ("p_50 == &l_1811", "t.c", 4953, __PRETTY_FUNCTION__));
                    }
                    (*l_1608) = ((safe_add_func_int16_t_s_s((l_2283 & 0x8AA9DF5A), (((*p_53) , g_1484) >= ((((safe_mod_func_int32_t_s_s((safe_mul_func_uint16_t_u_u(0xA3A4, l_2283)), (safe_div_func_int32_t_s_s((((p_54 , (**g_465)) , (*g_296)) == (*g_296)), p_54)))) && 0x7B21) , p_54) , 255U)))) , p_50);
                    (*l_1608) = l_2280;
                }
            }

            ((p_50 == &l_1811 || (p_50 >= &g_33[0] && p_50 <= &g_33[4])) ? (void) (0) : __assert_fail ("p_50 == &l_1811 || (p_50 >= &g_33[0] && p_50 <= &g_33[4])", "t.c", 4960, __PRETTY_FUNCTION__));
            return l_2291;




        }


        ((l_1431 == &p_53 || l_1431 == 0 || l_1431 == &g_466) ? (void) (0) : __assert_fail ("l_1431 == &p_53 || l_1431 == 0 || l_1431 == &g_466", "t.c", 4969, __PRETTY_FUNCTION__));
        (((l_2212 >= &g_11[0] && l_2212 <= &g_11[0]) || l_2212 == 0) ? (void) (0) : __assert_fail ("(l_2212 >= &g_11[0] && l_2212 <= &g_11[0]) || l_2212 == 0", "t.c", 4970, __PRETTY_FUNCTION__));
        for (l_991 = (-27); (l_991 > 36); l_991 = safe_add_func_uint32_t_u_u(l_991, 3))
        {
            uint16_t l_2316 = 0U;
            uint32_t l_2317 = 7U;

{
                int16_t l_2385 = 1;
                int32_t l_2386[9][3][9] = {{{0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0,(-5),0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0},{1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11},{0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46}},{{0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7},{0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46},{0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11,0xD11FB6A6,0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11}},{{0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0},{0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6},{0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2}},{{1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6},{0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0,(-5),0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0},{1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11}},{{0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46},{0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7},{0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46}},{{0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11,0xD11FB6A6,0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11},{0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5)},{0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7}},{{0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0},{0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7},{0x18DF85E2,0x15E3D6FB,(-5),(-5),0x15E3D6FB,0x18DF85E2,0x15E3D6FB,(-5),(-5)}},{{0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6},{0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2},{0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11}},{{0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2},{0x412DFEB7,1,0xD11FB6A6,0xD11FB6A6,1,0x412DFEB7,1,0xD11FB6A6,0xD11FB6A6},{0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5)}}};
                int32_t ***l_2414 = &(*g_296);
                int i, j, k;
                for ((*l_2212) = 4; ((*l_2212) >= (-19)); --(*l_2212))
                {
                    int32_t l_2384[2][6][6] = {{{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0}},{{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0}}};
                    int32_t *l_2416 = &g_33[2];
                    int i, j, k;
                    if ((*(&l_1855)))
                    {
                        struct S0 *l_2369[9][1];
                        int32_t l_2381 = (-1);
                        int i, j;

{
            transparent_crc(g_1271[(*l_1412)][l_2381], "g_1271[(*l_1412)][l_2381]", l_1855);
            if (l_1855) printf("index = [%d][%d]\n", (*l_1412), l_2381);

        }

                    for (i = 0; i < 9; i++)
                        {
                            for (j = 0; j < 1; j++)
                                l_2369[i][j] = (void*)0;
                        }
                        (*(&l_1735)) = (l_2369[8][0] == (*l_1831));
                        g_210 = ((*(&g_210)).f0 , (*(&g_210)));
                        (*(&l_1855)) = (safe_mod_func_int32_t_s_s(((safe_div_func_uint32_t_u_u(((safe_mul_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_s((((l_2381 & l_991) | ((((g_296 != (void*)0) == g_2054[0][0][1]) , (&i)) == ((*(&l_1855)) , (&l_1855)))) , l_991), (*(&i)))), 3)), (*l_2291))) ^ l_2384[0][4][4]), l_2385)) != l_2386[5][2][8]), l_2386[1][0][7]));
                    }
                    else
                    {
                        int32_t l_2413 = 0x35119CD0;
                        uint8_t l_2415 = 2U;
                        (*(&l_1735)) = (*(&l_1855));
                        (*(&i)) = (safe_mul_func_uint8_t_u_u(((((g_784[3] > (((((g_210.f4 >= (safe_rshift_func_uint8_t_u_u((!(safe_sub_func_uint16_t_u_u((((((*(&g_210)).f2 && 248U) >= (!((safe_div_func_uint32_t_u_u(1U, ((((safe_lshift_func_int8_t_s_s((safe_mul_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_s(1U, (safe_add_func_int8_t_s_s((safe_mul_func_int16_t_s_s(g_210.f0, (safe_rshift_func_int16_t_s_s(l_2413, 12)))), (((void*)0 == l_2414) , l_2384[0][4][4]))))) , l_2415), 3)), 0xB4AC)), (*(&l_1735)))) & g_33[2]) != 1U) , (*(&l_1855))))) > l_991))) , l_2384[0][4][5]) ^ g_33[2]), g_2054[7][0][1]))), 0))) , 0xCE1E) == g_784[3]) , 0xB4BE) == l_1009)) <= l_991) , (-4)) || g_784[3]), (-10)));
                    }
                    return l_2416;



                }
                for (l_2500 = 1; (l_2500 > 38); ++l_2500)
                {
                    int32_t *l_2419 = &g_11[0];
                    return l_2419;



                }
                (*(&l_2003)) = (*(&l_1855));
            }

                    (*l_1645) = ((safe_lshift_func_uint8_t_u_u(g_210.f3, (((&p_53 != (((safe_add_func_uint8_t_u_u((+(safe_add_func_uint8_t_u_u(g_210.f4, ((safe_mod_func_uint16_t_u_u((safe_lshift_func_int16_t_s_u((g_27.f4 <= ((((((safe_add_func_int32_t_s_s((((safe_mul_func_int16_t_s_s(g_210.f3, 9)) , l_2309[3]) == (safe_add_func_uint8_t_u_u(((safe_mul_func_int16_t_s_s((safe_div_func_int16_t_s_s((((p_54 != l_2316) && p_54) || l_2316), g_27.f1)), p_54)) , l_2317), g_210.f3))), (-1))) || p_54) , 9) != 255U) <= g_1271[2][1]) && g_2318)), 13)), 0x6C1B)) < p_54)))), p_54)) , l_1988[0][2][5]) , &g_466)) < 0xC785) | p_54))) , (*p_50));
        }
        (*l_1412) = ((((0xAC87D08D & (((safe_mod_func_int32_t_s_s((safe_mul_func_int8_t_s_s(l_2323, p_54)), (safe_lshift_func_int8_t_s_u((&g_465 != l_1828), 3)))) , (safe_rshift_func_int16_t_s_s(((g_11[0] , ((g_784[0] , ((safe_mul_func_uint8_t_u_u((safe_mul_func_int8_t_s_s((255U >= (safe_div_func_uint16_t_u_u((2 || (*l_1412)), 65532U))), p_54)), 0x41)) & 0xF0B61FC1)) != g_1031[4])) , p_54), 9))) , (-1))) == p_54) <= (*l_1645)) <= g_210.f3);
    }
    else
    {
        int8_t l_2340 = 0x2F;
        int32_t *l_2366 = &l_1167[6][6];
        int32_t ***l_2382 = &g_297;
        int32_t ***l_2466 = &g_297;
        uint8_t l_2522 = 8U;
        int32_t *l_2565[7];
        int i;
        for (i = 0; i < 7; i++)
            l_2565[i] = &g_33[3];
        if ((safe_sub_func_uint16_t_u_u(((safe_lshift_func_int8_t_s_s((safe_mul_func_int8_t_s_s((g_33[3] == l_2340), 0xF8)), 1)) < p_54), (((safe_add_func_int16_t_s_s((safe_rshift_func_int16_t_s_u((+(((*p_53) , ((safe_rshift_func_int8_t_s_s((((((((&l_1167[6][6] == ((g_210.f5 & (safe_div_func_uint16_t_u_u((g_27.f5 & ((l_2340 || l_2350) , 65535U)), g_210.f4))) , &g_11[0])) != p_54) , 1U) || p_54) , g_33[2]) == 0x8C) | p_54), p_54)) , (*p_53))) , g_2351)), 0)), g_80)) , &g_297) != (void*)0))))
        {
            int32_t *l_2383 = &l_1167[6][6];
            if ((((safe_mul_func_int16_t_s_s((safe_add_func_uint8_t_u_u(((void*)0 == (*g_465)), ((g_1271[2][1] != ((((p_54 & (safe_add_func_uint8_t_u_u((((safe_lshift_func_int8_t_s_u(((((safe_mod_func_uint16_t_u_u(((((*p_53) , l_2340) , (void*)0) != (void*)0), (safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u(0x692C583B, 0x083CD9AE)), p_54)))) , (void*)0) != l_1508) , g_210.f5), g_1031[4])) , l_2366) != l_2366), p_54))) > p_54) == p_54) ^ g_33[2])) >= 0x24))), 0xD203)) <= p_54) & 0xCB))
            {
                int16_t l_2385 = 1;
                int32_t l_2386[9][3][9] = {{{0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0,(-5),0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0},{1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11},{0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46}},{{0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7},{0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46},{0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11,0xD11FB6A6,0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11}},{{0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0},{0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6},{0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2}},{{1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6},{0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0,(-5),0xE6D5AA46,(-5),0x5A7BF8D0,0x5A7BF8D0},{1,1,0x5E1CF3F6,0xA0EB4A11,0x5E1CF3F6,1,1,0x5E1CF3F6,0xA0EB4A11}},{{0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46},{0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7},{0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46}},{{0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11,0xD11FB6A6,0x5E1CF3F6,0xD11FB6A6,0xA0EB4A11,0xA0EB4A11},{0x15E3D6FB,0x15E3D6FB,0xE6D5AA46,0x5A7BF8D0,0xE6D5AA46,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5)},{0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7}},{{0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0},{0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7},{0x18DF85E2,0x15E3D6FB,(-5),(-5),0x15E3D6FB,0x18DF85E2,0x15E3D6FB,(-5),(-5)}},{{0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6,0x412DFEB7,0x5E1CF3F6,0x5E1CF3F6,0x412DFEB7,0xD11FB6A6},{0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2,0x18DF85E2,0x5A7BF8D0,0x15E3D6FB,0x5A7BF8D0,0x18DF85E2},{0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11,1,0xA0EB4A11,0x412DFEB7,0x412DFEB7,0xA0EB4A11}},{{0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2},{0x412DFEB7,1,0xD11FB6A6,0xD11FB6A6,1,0x412DFEB7,1,0xD11FB6A6,0xD11FB6A6},{0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5),0x18DF85E2,0xE6D5AA46,0xE6D5AA46,0x18DF85E2,(-5)}}};
                int32_t ***l_2414 = &g_297;
                int i, j, k;
                for (l_1735 = 4; (l_1735 >= (-19)); --l_1735)
                {
                    int32_t l_2384[2][6][6] = {{{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0}},{{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0},{1,1,0,1,1,0}}};
                    int32_t *l_2416 = &g_33[2];
                    int i, j, k;
                    if ((*p_50))
                    {
                        struct S0 *l_2369[9][1];
                        int32_t l_2381 = (-1);
                        int i, j;
                        for (i = 0; i < 9; i++)
                        {
                            for (j = 0; j < 1; j++)
                                l_2369[i][j] = (void*)0;
                        }

for (l_2350 = 1; (l_2350 <= 5); l_2350 += 1)
                    {
                        int32_t l_1740 = (-2);
                        (*(&l_1217)) = (**(&p_53));
                        (*l_2437) = (safe_mod_func_uint16_t_u_u((l_1740 || (g_1271[1][2] < (((((safe_lshift_func_uint8_t_u_s((safe_mul_func_uint16_t_u_u(0xBABA, 3)), 7)) >= (safe_mul_func_int8_t_s_s((g_11[0] >= ((g_33[4] , 0x05D97D54) == (safe_div_func_uint32_t_u_u(((((((safe_mul_func_uint8_t_u_u(l_991, (((l_1740 < l_2340) , &p_51) == &(*g_296)))) > 0x5C49B460) >= l_2370.f0) || 1) >= (*l_1412)) <= (*l_2383)), l_2340)))), (-1)))) , (*l_1412)) , 65532U) == 0x6130))), g_210.f1));

{
                        int i, j, k;

{
                        (*(&k)) = (((safe_rshift_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_u(((safe_unary_minus_func_int8_t_s(((g_2054[7][0][1] , (!(*(&k)))) < (safe_sub_func_uint8_t_u_u(g_210.f4, 0xD7))))) | (l_2350 & (-8))), l_1217.f1)) && (safe_sub_func_uint32_t_u_u(((g_210.f5 > (~l_2350)) , l_1363), l_1363))), g_2054[7][0][1])) == (*l_1082)) < l_1363);
                        (*l_1412) = ((safe_mod_func_uint32_t_u_u(((((safe_mul_func_int16_t_s_s(l_1363, (((l_1363 | (safe_add_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_u((-9), l_1217.f4)) , ((safe_sub_func_uint8_t_u_u((((*l_1412) || (safe_rshift_func_uint8_t_u_s((g_33[2] & (l_1363 != (0x9C > (((g_2647 == l_1363) != (*l_2416)) , l_1363)))), l_1363))) != l_1363), l_1363)) && (*(&g_2803)))), l_2350))) , (void*)0) != (&l_1431)))) <= 0) & l_1363) & l_1363), 0x51332F8E)) ^ g_210.f5);
                        (*g_466) = (*(&g_27));
                    }

                    g_986[(l_2385 + 1)][(g_210.f8 + 1)][l_2003] = l_1096[0];
                        (*(*l_1431)) = (((&k) != g_986[(l_2385 + 1)][(g_210.f8 + 1)][l_2003]) , ((l_1363 > ((safe_mul_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u((((7 != ((((*g_466).f1 , 0) , 5) != (g_11[0] < (safe_rshift_func_uint16_t_u_u(((0xAB && (-8)) & 0x4915), l_2105.f2))))) , l_1363) & 247U), g_33[2])) ^ 1U), 250U)) > 1)) , (*g_466)));
                    }

                    (*g_2770) = &l_2437;

                        (((*l_2414) == &l_2437) ? (void) (0) : __assert_fail ("(*l_2414) == &l_2437", "t.c", 5091, __PRETTY_FUNCTION__));
                    };


                    (*l_2366) = (l_2369[8][0] == p_53);
                        l_2370 = (g_210.f0 , (*g_466));
                        (*l_1082) = (safe_mod_func_int32_t_s_s(((safe_div_func_uint32_t_u_u(((safe_mul_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_s((((l_2381 & p_54) | ((((l_2382 != (void*)0) == g_2054[0][0][1]) , l_2383) == ((*p_50) , p_50))) , p_54), (*l_2383))), 3)), g_80)) ^ l_2384[0][4][4]), l_2385)) != l_2386[5][2][8]), l_2386[1][0][7]));
                    }
                    else
                    {
                        int32_t l_2413 = 0x35119CD0;
                        uint8_t l_2415 = 2U;
                        (*l_2366) = (*p_50);
                        (*l_2383) = (safe_mul_func_uint8_t_u_u(((((g_784[3] > (((((g_27.f4 >= (safe_rshift_func_uint8_t_u_u((!(safe_sub_func_uint16_t_u_u(((((g_210.f2 && 248U) >= (!((safe_div_func_uint32_t_u_u(1U, ((((safe_lshift_func_int8_t_s_s((safe_mul_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(((safe_rshift_func_uint16_t_u_s(1U, (safe_add_func_int8_t_s_s((safe_mul_func_int16_t_s_s(g_27.f0, (safe_rshift_func_int16_t_s_s(l_2413, 12)))), (((void*)0 == l_2414) , l_2384[0][4][4]))))) , l_2415), 3)), 0xB4AC)), (*l_2366))) & g_33[2]) != 1U) , (*p_50)))) > p_54))) , l_2384[0][4][5]) ^ g_33[2]), g_2054[7][0][1]))), 0))) , 0xCE1E) == g_784[3]) , 0xB4BE) == g_2351)) <= p_54) , (-4)) || g_784[3]), (-10)));
                    }
                    return l_2416;



                }
                for (g_2318 = 1; (g_2318 > 38); ++g_2318)
                {
                    int32_t *l_2419 = &g_11[0];
                    return l_2419;



                }
                (*l_1412) = (*p_50);
            }
            else
            {
                struct S0 **l_2428 = &g_466;
                int32_t l_2438[9][9] = {{0xA15E527E,(-10),(-8),(-10),0xA15E527E,(-8),0x01077C09,0x01077C09,(-8)},{0xA15E527E,(-10),(-8),(-10),0xA15E527E,(-8),0x01077C09,0x01077C09,(-8)},{0xA15E527E,(-10),(-8),(-10),0xA15E527E,(-8),0x01077C09,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09},{3,0,0x01077C09,0,3,0x01077C09,0xBA1A3332,0xBA1A3332,0x01077C09}};
                int i, j;
                (*l_1082) = (((safe_mul_func_uint8_t_u_u((safe_add_func_uint8_t_u_u(((safe_lshift_func_uint16_t_u_u((((((void*)0 != &p_52) , l_2383) == &l_2438[5][1]) , g_27.f4), 1)) > g_210.f0), 0x5D)), (-5))) > l_2438[2][3]) , 0xD350549E);
                (*l_2366) = 0x5CE0142A;
            }

(*g_466).f8 += 1;



{
        int32_t ***l_2774 = &(*l_1508);
        struct S0 l_2818 = {24,6738,-426,165,390,-0,1153,115,0xEA};
        struct S0 ***l_2865[3];
        int i;
        for (i = 0; i < 3; i++)
            l_2865[i] = &g_465;
        g_32[(*l_1082)] = g_32[(*l_1082)];
        (*l_1082) = ((safe_unary_minus_func_uint32_t_u((safe_unary_minus_func_int32_t_s(((+((((safe_mod_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(((((((safe_sub_func_uint8_t_u_u((l_1122 , g_210.f5), ((0xE948A20E < (0x51576ED4 < (safe_rshift_func_uint8_t_u_u((((safe_div_func_int32_t_s_s(((l_1122 , (0 > ((safe_div_func_int8_t_s_s(((((safe_mul_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s((((((safe_lshift_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_s((&g_32[(*l_1082)] == &g_32[(*l_1082)]), 6)) != (0x3A76E62F < (*l_1850))) , 0x6C), l_1122)) , &p_52) != l_1508) | l_1122) <= l_1122), 1)), (*(*l_1431)).f3)), l_1122)) | 0x23CC) != g_33[3]) | 0x0B28), l_1122)) , g_210.f7))) && 0x38), l_1122)) && (*(*l_1431)).f6) | 1), (*l_1850))))) == l_1122))) , g_210.f1) , 0x7D5F7640) || (-1)) , (void*)0) != (&l_1431)))), 0xEA)) | (-7)) < 0x54EA) || (*l_1850))) , 3))))) | 65535U);
        for (l_1122 = (-12); (l_1122 == 60); l_1122 = safe_add_func_int32_t_s_s(l_1122, 6))
        {
            uint16_t l_2775 = 0xE2FA;
            int16_t l_2804 = 8;
            struct S0 **l_2817[2][8][4] = {{{&(*l_1431),&(*l_1431),&(*l_1431),&(*l_1431)},{&(*l_1431),&(*l_1431),(void*)0,&(*l_1431)},{&(*l_1431),&(*l_1431),&(*l_1431),(void*)0},{&(*l_1431),(void*)0,(void*)0,(void*)0},{&(*l_1431),&(*l_1431),&(*l_1431),&(*l_1431)},{(void*)0,&(*l_1431),&(*l_1431),(void*)0},{&(*l_1431),&(*l_1431),(void*)0,&(*l_1431)},{&(*l_1431),&(*l_1431),&(*l_1431),(void*)0}},{{(void*)0,&(*l_1431),&(*l_1431),&(*l_1431)},{&(*l_1431),&(*l_1431),(void*)0,(void*)0},{&(*l_1431),&(*l_1431),&(*l_1431),&(*l_1431)},{&(*l_1431),&(*l_1431),(void*)0,&(*l_1431)},{&(*l_1431),&(*l_1431),&(*l_1431),(void*)0},{&(*l_1431),&(*l_1431),(void*)0,&(*l_1431)},{&(*l_1431),&(*l_1431),&(*l_1431),&(*l_1431)},{&(*l_1431),&(*l_1431),(void*)0,(void*)0}}};
            int32_t l_2882 = (-4);
            int32_t *l_2884[4][4][8] = {{{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]},{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]},{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]},{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]}},{{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]},{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]},{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]},{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]}},{{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]},{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]},{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]},{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]}},{{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]},{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]},{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]},{&g_33[2],&l_1855,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_1855,&g_33[2]}}};
            int i, j, k;
        }
        for (l_2818.f8 = 1; (l_2818.f8 <= 7); l_2818.f8 += 1)
        {
            uint16_t l_2912[10][5] = {{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U}};
            int32_t *l_2923 = (void*)0;
            int i, j;
        }
    }

                    return p_50;



        }
        else
        {
            uint32_t l_2467 = 0xE6B0EF31;
            int32_t *l_2470 = &g_33[2];
            struct S0 l_2558 = {88,7141,234,1173,28,-0,-1034,196,1};
            int16_t l_2559[6] = {0x641F,0x641F,0x91BC,0x641F,0x641F,0x91BC};
            int32_t *l_2563 = &g_33[3];
            int32_t **l_2564 = &g_32[1];
            int i;
            for (l_991 = 27; (l_991 <= 8); --l_991)
            {
                int16_t l_2452 = 0x9563;
                int8_t l_2499 = 1;
                int32_t *l_2504 = &l_1167[6][6];

for ((*g_466).f8 = 0; ((*g_466).f8 == 2); (*g_466).f8 = safe_add_func_int8_t_s_s((*g_466).f8, 6))
                {
                    struct S0 l_2443 = {534,2588,69,470,37,-0,1036,319,-9};
                    uint32_t l_2476 = 4294967295U;
                    int32_t *l_2478 = (void*)0;
                    struct S0 ***l_2498 = &g_465;
                    l_2443 = (**g_465);
                    if (((safe_sub_func_int32_t_s_s((safe_rshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((l_2452 , (**g_465)) , (safe_mod_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(0x497B, 0U)), (((safe_rshift_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(((((**g_465) , (((((((((safe_add_func_int8_t_s_s((*p_53).f8, (safe_rshift_func_uint16_t_u_u((~(1U < (((((void*)0 == &g_33[2]) == g_2054[3][1][0]) ^ l_2452) & 0x9DD8))), l_2443.f4)))) <= l_2105.f0) < 0xA736BD57) > 0x4985) , l_2443) , (void*)0) == l_1508) || g_1094) , 0xE6)) < 0x78) > l_1363), 65535U)), l_1363)) < (*l_2563)) , l_1363)))), g_1094)), l_1363)), l_1363)) < 0U))
                    {
                        int32_t **l_2477 = (void*)0;
                        l_1850 = &g_33[4];
                        if (l_2443.f6)
                            continue;
                        return l_2478;



                    }
                    else
                    {
                        uint32_t l_2493[3][6];
                        int i, j;
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 6; j++)
                                l_2493[i][j] = 1U;
                        }
                        (*(&l_1855)) = ((l_2452 & (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u(((((((safe_lshift_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((l_2452 , (safe_lshift_func_uint16_t_u_s(((safe_sub_func_int32_t_s_s((((((l_2493[0][4] && ((l_2452 <= (((safe_sub_func_int8_t_s_s(((safe_mul_func_int16_t_s_s(0x1FF6, ((l_2105.f7 > (*p_53).f8) >= ((l_2498 == (void*)0) , (-1))))) , (*l_1850)), g_1031[3])) , (*l_2563)) & 7)) > l_2105.f0)) , (**g_465)) , l_2105.f8) && l_2452) , l_2499), 0x8ADDA95C)) , l_1363), 2))), l_1986)) | l_1363), l_1363)) ^ (*l_2563)) >= 0x4B) || (*p_53).f0) == 0x09) , (*p_53).f1), 5)), 6)), 0))) , (*l_1850));
                    }
                    for (g_1094 = 4; (g_1094 < 59); g_1094++)
                    {
                        int32_t **l_2503 = &l_2563;

(*l_2470) -= 1;


                    (*l_2503) = l_2478;

                        ((l_2563 == 0) ? (void) (0) : __assert_fail ("l_2563 == 0", "t.c", 5218, __PRETTY_FUNCTION__));
                        (*l_2503) = (&g_80);

                        (((l_2563 >= &l_1167[0][0] && l_2563 <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("(l_2563 >= &l_1167[0][0] && l_2563 <= &l_1167[8][6])", "t.c", 5221, __PRETTY_FUNCTION__));
                        if ((**l_2503))
                            break;
                        (*(&g_2803)) = (**l_2503);
                    }
                    (*(&l_1614)) = (safe_rshift_func_uint8_t_u_s(((((*l_2563) == ((safe_rshift_func_int16_t_s_s((0x81 < (l_1363 && ((0x79A0 && l_1363) || (((((l_1363 != ((4U != g_1094) ^ (safe_lshift_func_int16_t_s_s((-1), (*p_53).f8)))) == 0x7CB1) , (*p_53).f4) ^ 0x0273614A) , 1)))), g_1031[4])) ^ (*l_1850))) , (*l_1850)) > l_2350), l_1363));
                };


                    for (l_1217.f8 = 0; (l_1217.f8 == 2); l_1217.f8 = safe_add_func_int8_t_s_s(l_1217.f8, 6))
                {
                    struct S0 l_2443 = {534,2588,69,470,37,-0,1036,319,-9};
                    uint32_t l_2476 = 4294967295U;
                    int32_t *l_2478 = (void*)0;
                    struct S0 ***l_2498 = &g_465;
                    l_2443 = (**g_465);
                    if (((safe_sub_func_int32_t_s_s((safe_rshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((l_2452 , (**g_465)) , (safe_mod_func_uint8_t_u_u((safe_mul_func_int16_t_s_s(0x497B, 0U)), (((safe_rshift_func_int8_t_s_s((safe_mul_func_uint16_t_u_u(((((**g_465) , (((((((((safe_add_func_int8_t_s_s(g_210.f8, (safe_rshift_func_uint16_t_u_u((~(1U < (((((void*)0 == &g_33[2]) == g_2054[3][1][0]) ^ l_2452) & 0x9DD8))), l_2443.f4)))) <= g_27.f0) < 0xA736BD57) > 0x4985) , l_2443) , (void*)0) == l_2466) || l_2467) , 0xE6)) < 0x78) > p_54), 65535U)), p_54)) < (*l_2366)) , p_54)))), l_2467)), p_54)), p_54)) < 0U))
                    {
                        int32_t **l_2477 = (void*)0;

for (l_1904 = 3; (l_1904 >= 0); l_1904 -= 1)
                {
                    int8_t l_1072 = (-1);
                    uint32_t l_1076 = 1U;
                    int32_t *l_1083 = &g_33[2];
                    struct S0 l_1095 = {631,1691,-119,1361,102,1,-551,267,-4};
                    if ((safe_div_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(l_1072, 1)), g_2805)))
                    {
                        int32_t *l_1073 = (void*)0;
                        (*g_297) = l_1073;
                        (*g_297) = ((((+g_2805) || (g_1031[4] <= (~(l_1076 ^ (safe_mod_func_uint16_t_u_u(((!((((safe_div_func_int16_t_s_s(((&k) != l_1083), (((((safe_unary_minus_func_int32_t_s(1)) || (((((safe_add_func_uint16_t_u_u((0xFC05510A | ((safe_sub_func_uint32_t_u_u(0x237EEA70, (safe_add_func_int16_t_s_s(((safe_rshift_func_uint8_t_u_s((g_33[2] , (*l_1083)), g_2805)) > 0xA091E223), l_2105.f3)))) , 1U)), 0xF723)) <= 7U) ^ g_2803) , (*l_1083)) != 0x7BD9C737)) >= (*(&g_1240))) , (*(&k))) || g_2805))) != l_2105.f5) ^ (*(&l_2003))) , l_2105.f1)) & l_2105.f4), g_2805)))))) == g_2805) , (void*)0);
                    }
                    else
                    {
                        (*(&l_2105)) = l_1217;
                        if (l_2476)
                            continue;
                    }
                    (*(&l_2105)) = l_1095;
                    for (l_1095.f8 = 3; (l_1095.f8 >= 0); l_1095.f8 -= 1)
                    {
                        int i, j, k;
                        g_986[(l_1904 + 1)][(l_1095.f8 + 1)][g_2803] = l_1096[0];
                        (*(&l_2105)) = (((&i) != g_986[(l_1904 + 1)][(l_1095.f8 + 1)][g_2803]) , ((g_2805 > ((safe_mul_func_int8_t_s_s(((safe_sub_func_uint16_t_u_u((((7 != (((l_2105.f1 , 0) , 5) != (g_11[0] < (safe_rshift_func_uint16_t_u_u(((0xAB && (-8)) & 0x4915), l_2105.f2))))) , g_2805) & 247U), g_33[2])) ^ 1U), 250U)) > 1)) , (*(&l_2558))));
                    }
                };


                    l_2470 = &g_33[4];
                        if (l_2443.f6)
                            continue;
                        return l_2478;



                    }
                    else
                    {
                        uint32_t l_2493[3][6];
                        int i, j;
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 6; j++)
                                l_2493[i][j] = 1U;
                        }
                        (*l_2437) = ((l_2452 & (safe_lshift_func_int8_t_s_s((safe_lshift_func_uint8_t_u_s((safe_lshift_func_uint16_t_u_u(((((((safe_lshift_func_int8_t_s_s(((safe_add_func_uint32_t_u_u((l_2452 , (safe_lshift_func_uint16_t_u_s(((safe_sub_func_int32_t_s_s((((((l_2493[0][4] && ((l_2452 <= (((safe_sub_func_int8_t_s_s(((safe_mul_func_int16_t_s_s(0x1FF6, ((g_27.f7 > g_210.f8) >= ((l_2498 == (void*)0) , (-1))))) , (*l_2470)), g_1031[3])) , (*p_50)) & 7)) > g_27.f0)) , (**g_465)) , g_27.f8) && l_2452) , l_2499), 0x8ADDA95C)) , p_54), 2))), l_2500)) | p_54), p_54)) ^ (*p_50)) >= 0x4B) || g_210.f0) == 0x09) , g_210.f1), 5)), 6)), 0))) , (*l_2470));
                    }

for ((*g_2221) = 0; ((*g_2221) > (-15)); (*g_2221) = safe_sub_func_int32_t_s_s((*g_2221), 1))
        {
            uint16_t l_2954 = 0xBB7C;
            struct S0 **l_2955 = (void*)0;
            (*(*l_2564)) = 0x64EAFE29;
            for (p_54 = 0; (p_54 <= 3); p_54 += 1)
            {
                struct S0 ***l_2957 = &g_2531[1][1];
                int16_t l_2958 = 0x8258;
                int i, j, k;
            }
        };


                    for (g_2318 = 4; (g_2318 < 59); g_2318++)
                    {
                        int32_t **l_2503 = &l_2366;
                        (*l_2503) = l_2478;

                        ((l_2366 == 0) ? (void) (0) : __assert_fail ("l_2366 == 0", "t.c", 5308, __PRETTY_FUNCTION__));
                        (*l_2503) = l_2504;

                        (((l_2366 >= &l_1167[0][0] && l_2366 <= &l_1167[8][6])) ? (void) (0) : __assert_fail ("(l_2366 >= &l_1167[0][0] && l_2366 <= &l_1167[8][6])", "t.c", 5311, __PRETTY_FUNCTION__));

for (g_27.f8 = (-2); (g_27.f8 >= 5); g_27.f8 = safe_add_func_uint16_t_u_u(g_27.f8, 4))
            {
                int32_t **l_302 = &g_32[1];
                (*g_148) = ((0 | ((l_1383 ^ ((safe_rshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u(((((g_210.f2 != (**(*g_296))) , ((&p_51) != &(*l_2466))) | ((safe_add_func_int8_t_s_s((((safe_mod_func_int16_t_s_s(((l_302 == (((safe_lshift_func_int16_t_s_u((0xFA & (safe_mul_func_int8_t_s_s((**l_302), g_210.f2))), 15)) == 0x3A923A02) , (*g_296))) == g_210.f3), l_2467)) ^ l_1383) && l_2467), 0x72)) , (**(*g_296)))) ^ (-9)), (**l_302))), 0)) > 6U)) , g_210.f1)) <= l_1351);
            };


                    if ((**l_2503))
                            break;
                        (*l_1082) = (**l_2503);
                    }
                    (*g_2221) = (safe_rshift_func_uint8_t_u_s(((((*p_50) == ((safe_rshift_func_int16_t_s_s((0x81 < (p_54 && ((0x79A0 && p_54) || (((((p_54 != ((4U != g_2318) ^ (safe_lshift_func_int16_t_s_s((-1), g_210.f8)))) == 0x7CB1) , g_210.f4) ^ 0x0273614A) , 1)))), g_1031[4])) ^ (*l_2470))) , (*l_2470)) > g_2351), p_54));
                }
                if (((safe_sub_func_int8_t_s_s(((((*l_2504) != (p_54 | ((0xDC21 < (2 != g_27.f2)) != ((safe_mul_func_uint16_t_u_u((((((((safe_unary_minus_func_int32_t_s(((p_54 > (safe_lshift_func_int8_t_s_u((safe_div_func_uint16_t_u_u((safe_div_func_uint16_t_u_u(((void*)0 != &g_466), ((((*p_53) , (*g_296)) == &p_50) && (*p_50)))), (*l_2504))), p_54))) && g_27.f6))) != g_80) && 2U) >= p_54) >= l_2522) != (*l_2366)) && p_54), (*l_1412))) != (-1))))) && g_210.f4) , g_1031[1]), (*l_2504))) <= 0x3D))
                {
                    int32_t **l_2533 = &l_2366;
                    (*l_2533) = &g_11[0];

                    (((l_2366 >= &g_11[0] && l_2366 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_2366 >= &g_11[0] && l_2366 <= &g_11[0])", "t.c", 5331, __PRETTY_FUNCTION__));
                    (*g_2221) = (((((((safe_rshift_func_uint8_t_u_u(((safe_mul_func_uint8_t_u_u(p_54, (((safe_mod_func_uint8_t_u_u((safe_rshift_func_int8_t_s_u(g_27.f1, 5)), (safe_mul_func_uint16_t_u_u((~g_11[0]), ((!(safe_add_func_int32_t_s_s((((*p_50) ^ (3U && (safe_sub_func_int8_t_s_s((safe_rshift_func_uint16_t_u_u(((safe_div_func_uint16_t_u_u((&g_33[2] == &g_33[2]), g_2054[4][0][1])) || ((safe_rshift_func_int8_t_s_s((safe_mod_func_uint32_t_u_u((((((*g_465) != (void*)0) ^ 0xE254033A) | (**l_2533)) & p_54), p_54)), p_54)) != 0x6629)), 13)), g_33[2])))) <= 0xD6B6E273), (*l_2504)))) | p_54))))) , l_2558) , 9U))) , 0U), 1)) < l_2559[4]) == g_210.f5) >= 0xFF) >= g_27.f0) >= 0xEE71) >= 0xC4);
                }
                else
                {
                    int32_t **l_2560[2];
                    int i;
                    for (i = 0; i < 2; i++)
                        l_2560[i] = &g_944[3][3][1];
                    p_50 = &g_21;

                    ((p_50 == &g_21) ? (void) (0) : __assert_fail ("p_50 == &g_21", "t.c", 5342, __PRETTY_FUNCTION__));
                }
                (*l_1082) = (*p_50);
                for (l_1855 = 15; (l_1855 < 20); l_1855++)
                {
                    (**g_465) = (*p_53);
                }
            }

            ((p_50 == &g_21 || (p_50 >= &g_33[0] && p_50 <= &g_33[4])) ? (void) (0) : __assert_fail ("p_50 == &g_21 || (p_50 >= &g_33[0] && p_50 <= &g_33[4])", "t.c", 5351, __PRETTY_FUNCTION__));
            (((l_2366 >= &l_1167[0][0] && l_2366 <= &l_1167[8][6]) || (l_2366 >= &g_11[0] && l_2366 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_2366 >= &l_1167[0][0] && l_2366 <= &l_1167[8][6]) || (l_2366 >= &g_11[0] && l_2366 <= &g_11[0])", "t.c", 5352, __PRETTY_FUNCTION__));

if ((safe_add_func_uint8_t_u_u(0xD4, (safe_lshift_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(0U, (safe_mul_func_int8_t_s_s((safe_div_func_int32_t_s_s((safe_lshift_func_uint8_t_u_u(((*g_466).f0 < ((l_1181 || (safe_add_func_uint8_t_u_u(0U, (((**(&g_148)) >= l_1262) , (((((void*)0 == &(*g_466)) >= (*g_466).f5) , (*(*p_51))) | l_1262))))) , g_2619)), g_2619)), 3)), 0xD3)))), g_33[2])))))
            {
                l_1082 = &g_11[0];
            }
            else
            {
                int32_t **l_164[1][1][4] = {{{&l_1082,&l_1082,&l_1082,&l_1082}}};
                struct S0 *l_166 = &(*g_466);
                int i, j, k;
                (*g_297) = ((safe_div_func_uint32_t_u_u(((safe_mod_func_int16_t_s_s((safe_mul_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s(65533U, 10)), ((void*)0 != (&l_1850)))), l_1181)) && ((safe_sub_func_uint8_t_u_u((l_1262 >= 0x7467), ((safe_rshift_func_int16_t_s_u((&(*g_466) == &(*g_466)), 8)) | (!(safe_sub_func_uint8_t_u_u((&g_1240 == (*(&l_1850))), l_1181)))))) < l_1181)), (**(&l_1850)))) , (void*)0);

                (((*g_297) == 0) ? (void) (0) : __assert_fail ("(*g_297) == 0", "t.c", 5365, __PRETTY_FUNCTION__));
                (*l_166) = (*g_466);
                (**(&g_148)) = (safe_add_func_int8_t_s_s((l_1181 == (safe_mul_func_int16_t_s_s(((safe_sub_func_int8_t_s_s(5, ((*g_466).f4 | 0xDB3D))) ^ g_2619), (l_1181 ^ 0x9E95)))), (safe_mod_func_int16_t_s_s((((void*)0 != (&g_148)) , (-1)), 65535U))));
            };



{
                        struct S0 *l_1374 = &l_1217;
                        uint8_t l_1375 = 0xEB;
                        int32_t **l_1384 = &g_944[6][1][4];
                        (*l_1384) = ((safe_sub_func_int8_t_s_s(g_210.f6, (safe_add_func_uint32_t_u_u(((safe_add_func_int8_t_s_s((-5), (safe_add_func_int8_t_s_s(0x81, (((l_1374 != (&l_1217)) | l_1375) && (safe_lshift_func_int8_t_s_s(g_2318, (safe_add_func_uint8_t_u_u(((*l_1850) > ((!(safe_mul_func_uint8_t_u_u(l_2370.f1, (-9)))) || 0xBB08)), 0x6F))))))))) ^ l_1383), 4294967294U)))) , (void*)0);
                    }

                    g_32[1] = l_2470;
            (*l_2564) = l_2563;
        }

        ((p_50 == &g_21 || (p_50 >= &g_33[0] && p_50 <= &g_33[4])) ? (void) (0) : __assert_fail ("p_50 == &g_21 || (p_50 >= &g_33[0] && p_50 <= &g_33[4])", "t.c", 5383, __PRETTY_FUNCTION__));
        (((l_2366 >= &l_1167[0][0] && l_2366 <= &l_1167[8][6]) || (l_2366 >= &g_11[0] && l_2366 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_2366 >= &l_1167[0][0] && l_2366 <= &l_1167[8][6]) || (l_2366 >= &g_11[0] && l_2366 <= &g_11[0])", "t.c", 5384, __PRETTY_FUNCTION__));
        return l_2565[5];



    }


    ((l_1082 == 0 || (l_1082 >= &g_33[0] && l_1082 <= &g_33[4])) ? (void) (0) : __assert_fail ("l_1082 == 0 || (l_1082 >= &g_33[0] && l_1082 <= &g_33[4])", "t.c", 5392, __PRETTY_FUNCTION__));
    ((l_1431 == &p_53 || l_1431 == 0 || l_1431 == &g_466) ? (void) (0) : __assert_fail ("l_1431 == &p_53 || l_1431 == 0 || l_1431 == &g_466", "t.c", 5393, __PRETTY_FUNCTION__));
    (((l_2212 >= &g_11[0] && l_2212 <= &g_11[0]) || l_2212 == 0) ? (void) (0) : __assert_fail ("(l_2212 >= &g_11[0] && l_2212 <= &g_11[0]) || l_2212 == 0", "t.c", 5394, __PRETTY_FUNCTION__));
    (*g_2221) = (l_1831 == (void*)0);
    return p_50;




}







static int32_t * func_55(uint32_t p_56, int8_t p_57, uint32_t p_58)
{
    int32_t l_75 = 6;
    struct S0 ***l_896 = &g_465;
    int32_t l_901 = 0x6C9D0AB9;
    int32_t **l_909[4][9] = {{&g_148,&g_148,&g_32[1],&g_32[1],&g_32[1],&g_32[1],&g_148,&g_148,&g_32[1]},{&g_148,&g_32[1],(void*)0,&g_148,&g_148,(void*)0,&g_32[1],&g_148,(void*)0},{&g_148,&g_148,&g_32[1],&g_32[1],&g_32[1],&g_32[1],&g_148,&g_148,&g_32[1]},{&g_148,&g_32[1],(void*)0,&g_148,&g_148,(void*)0,&g_32[1],&g_148,(void*)0}};
    int i, j;
    for (p_56 = 0; (p_56 <= 2); p_56 += 1)
    {
        uint8_t l_76 = 4U;
        int32_t *l_478 = &g_21;
        int i;
        for (g_21 = 0; (g_21 <= 4); g_21 += 1)
        {
            int i;
        }
        g_33[(p_56 + 1)] = g_33[(p_56 + 1)];
        g_32[p_56] = &g_33[(p_56 + 1)];
    }

for (g_2619 = 0; (g_2619 >= (-19)); --g_2619)
                    {
                        (**(*l_896)) = (*(*g_465));
                    };


                    if (((l_75 & p_57) & (l_896 != (((g_210.f5 , (safe_sub_func_int8_t_s_s(((l_901 || ((safe_mul_func_int16_t_s_s((p_57 >= (safe_sub_func_int16_t_s_s((safe_add_func_int16_t_s_s((((((((safe_unary_minus_func_int16_t_s(((void*)0 != l_909[0][7]))) , (safe_add_func_int16_t_s_s((+p_56), 0xDF67))) && 0xB20DAD22) < p_57) | g_210.f3) , p_56) ^ 1U), g_210.f0)), g_27.f0))), g_210.f7)) == p_57)) , 0x06), g_33[3]))) && 0xF89A) , (void*)0))))
    {
        int32_t *l_915[6][3] = {{(void*)0,&g_21,(void*)0},{&g_33[1],&g_33[1],&g_33[2]},{&g_21,&g_21,&g_21},{&g_33[1],&g_33[2],&g_33[2]},{(void*)0,&g_21,(void*)0},{&g_33[1],&g_33[1],&g_33[2]}};
        int32_t ***l_925 = &l_909[3][6];
        uint32_t l_938[1][7][8] = {{{0xFED5CCC8,0xFED5CCC8,0x447CA895,0xAFA15E54,0xAB0FB7AA,0xAFA15E54,0x447CA895,0xFED5CCC8},{0xFED5CCC8,0xA6BF248C,0x9AA94303,0x447CA895,0x447CA895,0x9AA94303,0xA6BF248C,0xFED5CCC8},{0xA6BF248C,4U,0xFED5CCC8,0xAFA15E54,0xFED5CCC8,4U,0xA6BF248C,0xA6BF248C},{4U,0xAFA15E54,0x9AA94303,0x9AA94303,0xAFA15E54,4U,0x447CA895,4U},{0xAFA15E54,4U,0x447CA895,4U,0xAFA15E54,0x9AA94303,0x9AA94303,0xAFA15E54},{4U,0xA6BF248C,0xA6BF248C,4U,0xFED5CCC8,0xAFA15E54,0xFED5CCC8,4U},{0xA6BF248C,0xFED5CCC8,0xA6BF248C,0x9AA94303,0x447CA895,0x447CA895,0x9AA94303,0xA6BF248C}}};
        int8_t l_943 = 2;
        int i, j, k;
        (*g_148) = (0xE12F452C > (safe_mod_func_int32_t_s_s((l_915[2][2] == l_915[2][2]), (safe_add_func_int8_t_s_s((safe_lshift_func_int16_t_s_s((0x9B <= (0x1E1C != ((safe_mul_func_uint16_t_u_u(((+((&g_297 == (void*)0) , ((l_925 == &l_909[2][2]) <= g_11[0]))) < p_57), p_56)) == p_58))), p_58)), p_57)))));

if (g_2803) printf("index = [%d]\n", l_75);

                    if ((safe_div_func_uint32_t_u_u((p_57 , (safe_unary_minus_func_int16_t_s((((p_56 , ((((safe_div_func_int32_t_s_s((g_210.f1 != ((safe_unary_minus_func_uint32_t_u((safe_rshift_func_uint16_t_u_u((+((0 == ((((((safe_unary_minus_func_int16_t_s(((l_938[0][5][3] >= ((((((p_56 < ((safe_mul_func_uint32_t_u_u(g_4, ((safe_mul_func_uint16_t_u_u((l_915[2][2] != (g_210.f5 , &g_11[0])), 0xD9A6)) >= 254U))) && g_210.f1)) , g_33[2]) & p_58) != (-10)) >= g_210.f4) != l_943)) , 0x3570))) > 1) <= g_27.f6) & g_210.f2) < 0x86E2) != (-1))) & p_58)), 0)))) <= (*g_148))), p_56)) > p_58) <= g_27.f8) ^ 65528U)) , (void*)0) != (*l_925))))), p_58)))
        {
            g_944[6][0][7] = &g_11[0];


        }
        else
        {
            int32_t *l_945 = (void*)0;
            struct S0 l_954 = {759,10814,-151,1367,80,-0,261,103,0xB5};
            g_148 = l_945;

            ((g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == 0", "t.c", 5458, __PRETTY_FUNCTION__));
            for (l_75 = 2; (l_75 >= 0); l_75 -= 1)
            {
                uint8_t l_953 = 0x18;
                int32_t l_955[7] = {1,1,1,1,1,1,1};
                int i;
                l_945 = (void*)0;
                for (p_56 = 0; (p_56 <= 2); p_56 += 1)
                {
                    int i, j;


for (g_2803 = 5; (g_2803 != (-4)); --g_2803)
                {
                    uint16_t l_2236 = 0x7F4B;
                    if ((((safe_mul_func_int16_t_s_s(((safe_mul_func_int8_t_s_s((((((safe_rshift_func_uint16_t_u_s((((*g_296) == (*g_296)) < (safe_mod_func_uint8_t_u_u(0xB1, l_953))), l_953)) != ((safe_mod_func_int16_t_s_s(((((g_2351 , (*(*g_465))) , l_953) != ((safe_mul_func_int8_t_s_s(l_2236, (*g_466).f4)) , l_953)) != 1U), l_953)) , (*g_466).f1)) & l_943) <= (-2)) || 1U), 9U)) < l_953), (*g_466).f6)) & l_953) , l_2236))
                    {
                        uint32_t l_2241 = 0U;
                        struct S0 l_2242 = {718,7833,20,468,426,1,-754,198,-1};
                        (**(*l_896)) = (*(*g_465));
                        if (g_1094)
                            break;
                        (**(*l_896)) = (((g_2351 ^ 0) , l_2241) , l_2242);
                        (*(&l_901)) = (l_953 , 0xA5E0E56F);
                    }
                    else
                    {
                        uint32_t l_2243 = 0x1478837A;
                        l_2243 = 0x168497EF;
                    }
                    if ((*(&g_2803)))
                        continue;
                    if ((*(&g_2803)))
                        break;
                    for ((*g_466).f8 = 17; ((*g_466).f8 >= (-22)); (*g_466).f8 = safe_sub_func_int32_t_s_s((*g_466).f8, 7))
                    {
                        (*(&g_2956)) = (((safe_rshift_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_u(((safe_unary_minus_func_int8_t_s(((g_2054[7][0][1] , (!(*(&g_2956)))) < (safe_sub_func_uint8_t_u_u((*g_466).f4, 0xD7))))) | (l_2236 & (-8))), (*g_466).f1)) && (safe_sub_func_uint32_t_u_u((((*g_466).f5 > (~l_2236)) , l_953), l_953))), g_2054[7][0][1])) == (*g_2221)) < l_953);
                        (*(&g_1240)) = ((safe_mod_func_uint32_t_u_u(((((safe_mul_func_int16_t_s_s(l_953, (((l_953 | (safe_add_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_u((-9), (*g_466).f4)) , ((safe_sub_func_uint8_t_u_u((((*(&g_1240)) || (safe_rshift_func_uint8_t_u_s((g_33[2] & (l_953 != (0x9C > (((g_1094 == l_953) != g_2803) , l_953)))), l_953))) != l_953), l_953)) && (*(&g_2803)))), l_2236))) , (void*)0) != l_896))) <= 0) & l_953) & l_953), 0x51332F8E)) ^ (*g_466).f5);
                        g_27 = (*(*g_465));
                    }
                };


                    for ((*g_148) = (-7); ((*g_148) != (-23)); (*g_148)--)
    {
        int32_t *l_25 = &(*g_148);
        int32_t **l_24[1][5] = {{&l_25,&l_25,&l_25,&l_25,&l_25}};
        int i, j;
        g_2221 = &g_11[0];
    };



for (g_210.f8 = 17; (g_210.f8 >= (-22)); g_210.f8 = safe_sub_func_int32_t_s_s(g_210.f8, 7))
                    {
                        (*g_2221) = (((safe_rshift_func_uint16_t_u_u(((safe_lshift_func_int16_t_s_u(((safe_unary_minus_func_int8_t_s(((g_2054[7][0][1] , (!(*g_2221))) < (safe_sub_func_uint8_t_u_u(l_954.f4, 0xD7))))) | (g_1484 & (-8))), g_210.f1)) && (safe_sub_func_uint32_t_u_u(((l_954.f5 > (~g_1484)) , g_2805), g_2805))), g_2054[7][0][1])) == (*g_2221)) < g_2805);
                        (*g_2221) = ((safe_mod_func_uint32_t_u_u(((((safe_mul_func_int16_t_s_s(g_2805, (((g_2805 | (safe_add_func_uint8_t_u_u(((safe_rshift_func_int16_t_s_u((-9), g_210.f4)) , ((safe_sub_func_uint8_t_u_u((((*g_2221) || (safe_rshift_func_uint8_t_u_s((g_33[2] & (g_2805 != (0x9C > (((p_58 == g_2805) != l_75) , g_2805)))), g_2805))) != g_2805), g_2805)) && (*(&g_21)))), g_1484))) , (void*)0) != (&g_465)))) <= 0) & g_2805) & g_2805), 0x51332F8E)) ^ l_954.f5);
                        g_210 = (*(&g_210));
                    };


                    l_955[2] = (safe_rshift_func_int16_t_s_s(0x6619, (((0xB5C21137 || ((safe_lshift_func_int8_t_s_s((((((p_57 , ((0U & (((safe_mod_func_int16_t_s_s(((((~(l_915[(p_56 + 3)][p_56] != g_32[p_56])) & p_56) , p_56) ^ (((((g_210.f3 & g_210.f6) || p_56) < g_784[3]) && g_784[1]) <= l_953)), 0x5977)) > p_56) , p_56)) , l_954)) , p_56) , g_210.f6) <= 0x91E96527) > g_80), 2)) , l_953)) < p_57) > (-3))));
                    for (l_953 = 0; (l_953 <= 2); l_953 += 1)
                    {
                        uint8_t l_963 = 1U;
                        int i, j;
                    }
                    l_915[(p_56 + 2)][l_75] = (void*)0;
                }
            }
        }

        ((g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 5530, __PRETTY_FUNCTION__));

        l_915[4][1] = (((safe_sub_func_int32_t_s_s(0, (safe_sub_func_int8_t_s_s((safe_rshift_func_int16_t_s_u((safe_add_func_uint16_t_u_u(g_210.f4, (((((((g_210.f4 == (g_11[0] || (65535U <= ((safe_lshift_func_int8_t_s_s(0x4B, 3)) ^ ((((safe_div_func_int16_t_s_s((65529U || ((void*)0 != &l_909[2][0])), g_27.f2)) , p_58) & p_57) && 0x4BE31D81))))) >= p_56) <= p_56) , &g_11[0]) == (void*)0) >= g_80) , p_57))), 11)), p_56)))) || p_56) , l_915[3][0]);
        for (g_4 = 0; (g_4 <= 2); g_4 += 1)
        {
            int i;
            if (p_56)
                break;
        }
    }
    else
    {
        int32_t *l_978[5] = {&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0]};
        struct S0 l_985 = {577,3425,213,511,506,-1,-392,159,0xDE};
        int i;
        g_944[3][3][1] = l_978[2];



{
            struct S0 l_204[4][9][7] = {{{{771,1558,-451,513,27,-1,1511,192,-1},{935,10289,25,52,406,0,46,215,0xCA},{120,9908,-425,372,430,-1,221,40,0x75},{910,3461,-269,465,261,-1,-660,305,1},{5,3937,-289,114,110,-1,9,312,1},{954,7668,199,671,229,-0,-167,164,0x06},{754,9876,420,277,125,-1,380,261,-1}},{{350,924,-4,256,182,-1,1188,245,0x1F},{591,4688,-381,515,88,0,604,162,-4},{121,367,-63,502,122,-1,45,265,-6},{315,1455,177,528,36,-1,-1844,313,1},{481,8269,239,242,179,-1,-1345,298,2},{60,6210,-350,1438,357,1,1639,98,0x3D},{233,9578,117,827,391,-0,724,41,0x15}},{{959,822,223,164,471,0,487,121,-1},{273,1597,133,825,244,-0,-1846,197,0x54},{821,9799,280,114,119,0,41,243,0x8F},{910,3461,-269,465,261,-1,-660,305,1},{591,4688,-381,515,88,0,604,162,-4},{199,4007,-191,1395,150,-1,-1324,22,0x08},{709,4173,0,827,80,0,1811,48,-1}},{{709,4173,0,827,80,0,1811,48,-1},{233,9578,117,827,391,-0,724,41,0x15},{553,2374,-152,183,243,0,669,330,0},{264,10326,227,158,49,0,-1685,171,0},{541,7944,-15,820,53,-1,-1120,57,1},{841,2620,-469,60,336,-1,-204,123,0xEF},{264,10326,227,158,49,0,-1685,171,0}},{{350,924,-4,256,182,-1,1188,245,0x1F},{231,9669,-231,1382,360,0,-750,95,8},{60,6210,-350,1438,357,1,1639,98,0x3D},{954,7668,199,671,229,-0,-167,164,0x06},{264,10326,227,158,49,0,-1685,171,0},{315,1455,177,528,36,-1,-1844,313,1},{935,10289,25,52,406,0,46,215,0xCA}},{{264,10326,227,158,49,0,-1685,171,0},{231,9669,-231,1382,360,0,-750,95,8},{335,5168,70,157,46,-0,-4,71,0xC1},{303,5148,510,1166,279,-1,-319,238,-4},{754,9876,420,277,125,-1,380,261,-1},{821,9799,280,114,119,0,41,243,0x8F},{754,9876,420,277,125,-1,380,261,-1}},{{405,7883,-403,939,348,0,219,335,0},{233,9578,117,827,391,-0,724,41,0x15},{233,9578,117,827,391,-0,724,41,0x15},{405,7883,-403,939,348,0,219,335,0},{5,3937,-289,114,110,-1,9,312,1},{350,924,-4,256,182,-1,1188,245,0x1F},{591,4688,-381,515,88,0,604,162,-4}},{{145,8738,-386,467,126,1,1110,55,0x98},{273,1597,133,825,244,-0,-1846,197,0x54},{954,7668,199,671,229,-0,-167,164,0x06},{553,2374,-152,183,243,0,669,330,0},{771,1558,-451,513,27,-1,1511,192,-1},{145,8738,-386,467,126,1,1110,55,0x98},{841,2620,-469,60,336,-1,-204,123,0xEF}},{{273,1597,133,825,244,-0,-1846,197,0x54},{591,4688,-381,515,88,0,604,162,-4},{335,5168,70,157,46,-0,-4,71,0xC1},{264,10326,227,158,49,0,-1685,171,0},{709,4173,0,827,80,0,1811,48,-1},{199,4007,-191,1395,150,-1,-1324,22,0x08},{591,4688,-381,515,88,0,604,162,-4}}},{{{23,9155,154,355,16,-1,-1706,283,0x7E},{935,10289,25,52,406,0,46,215,0xCA},{350,924,-4,256,182,-1,1188,245,0x1F},{771,1558,-451,513,27,-1,1511,192,-1},{954,7668,199,671,229,-0,-167,164,0x06},{315,1455,177,528,36,-1,-1844,313,1},{754,9876,420,277,125,-1,380,261,-1}},{{121,367,-63,502,122,-1,45,265,-6},{481,8269,239,242,179,-1,-1345,298,2},{120,9908,-425,372,430,-1,221,40,0x75},{553,2374,-152,183,243,0,669,330,0},{481,8269,239,242,179,-1,-1345,298,2},{233,9578,117,827,391,-0,724,41,0x15},{935,10289,25,52,406,0,46,215,0xCA}},{{405,7883,-403,939,348,0,219,335,0},{771,1558,-451,513,27,-1,1511,192,-1},{821,9799,280,114,119,0,41,243,0x8F},{23,9155,154,355,16,-1,-1706,283,0x7E},{481,8269,239,242,179,-1,-1345,298,2},{421,8163,-283,376,507,-1,-1353,77,0},{264,10326,227,158,49,0,-1685,171,0}},{{709,4173,0,827,80,0,1811,48,-1},{841,2620,-469,60,336,-1,-204,123,0xEF},{954,7668,199,671,229,-0,-167,164,0x06},{83,8132,354,256,108,1,171,249,0xAC},{954,7668,199,671,229,-0,-167,164,0x06},{841,2620,-469,60,336,-1,-204,123,0xEF},{709,4173,0,827,80,0,1811,48,-1}},{{145,8738,-386,467,126,1,1110,55,0x98},{264,10326,227,158,49,0,-1685,171,0},{746,7980,-107,1112,83,-1,374,358,0xDC},{954,7668,199,671,229,-0,-167,164,0x06},{709,4173,0,827,80,0,1811,48,-1},{541,7944,-15,820,53,-1,-1120,57,1},{233,9578,117,827,391,-0,724,41,0x15}},{{333,3571,365,904,451,-1,-1762,326,6},{231,9669,-231,1382,360,0,-750,95,8},{421,8163,-283,376,507,-1,-1353,77,0},{591,4688,-381,515,88,0,604,162,-4},{771,1558,-451,513,27,-1,1511,192,-1},{421,8163,-283,376,507,-1,-1353,77,0},{754,9876,420,277,125,-1,380,261,-1}},{{591,4688,-381,515,88,0,604,162,-4},{935,10289,25,52,406,0,46,215,0xCA},{159,1031,327,1210,73,-0,251,185,0x5B},{935,10289,25,52,406,0,46,215,0xCA},{988,5032,8,601,102,1,29,300,-3},{990,7696,-406,140,54,1,-1764,223,0xF4},{841,2620,-469,60,336,-1,-204,123,0xEF}},{{593,5506,-426,876,79,-0,-117,52,-1},{315,1455,177,528,36,-1,-1844,313,1},{801,2002,104,432,75,-0,-86,145,0x1B},{536,6144,-132,1039,370,1,1310,139,0xBF},{541,7944,-15,820,53,-1,-1120,57,1},{593,5506,-426,876,79,-0,-117,52,-1},{421,8163,-283,376,507,-1,-1353,77,0}},{{954,7668,199,671,229,-0,-167,164,0x06},{233,9578,117,827,391,-0,724,41,0x15},{333,3571,365,904,451,-1,-1762,326,6},{228,5552,-161,809,98,-0,1993,56,7},{350,924,-4,256,182,-1,1188,245,0x1F},{264,10326,227,158,49,0,-1685,171,0},{233,9578,117,827,391,-0,724,41,0x15}}},{{{954,7668,199,671,229,-0,-167,164,0x06},{421,8163,-283,376,507,-1,-1353,77,0},{114,2214,234,968,371,1,-155,182,0},{315,1455,177,528,36,-1,-1844,313,1},{372,4980,152,898,171,-1,919,230,0xA4},{372,4980,152,898,171,-1,919,230,0xA4},{315,1455,177,528,36,-1,-1844,313,1}},{{593,5506,-426,876,79,-0,-117,52,-1},{841,2620,-469,60,336,-1,-204,123,0xEF},{593,5506,-426,876,79,-0,-117,52,-1},{801,2002,104,432,75,-0,-86,145,0x1B},{60,6210,-350,1438,357,1,1639,98,0x3D},{335,5168,70,157,46,-0,-4,71,0xC1},{199,4007,-191,1395,150,-1,-1324,22,0x08}},{{60,6210,-350,1438,357,1,1639,98,0x3D},{541,7944,-15,820,53,-1,-1120,57,1},{231,9669,-231,1382,360,0,-750,95,8},{5,3937,-289,114,110,-1,9,312,1},{841,2620,-469,60,336,-1,-204,123,0xEF},{333,3571,365,904,451,-1,-1762,326,6},{145,8738,-386,467,126,1,1110,55,0x98}},{{120,9908,-425,372,430,-1,221,40,0x75},{421,8163,-283,376,507,-1,-1353,77,0},{801,2002,104,432,75,-0,-86,145,0x1B},{120,9908,-425,372,430,-1,221,40,0x75},{988,5032,8,601,102,1,29,300,-3},{335,5168,70,157,46,-0,-4,71,0xC1},{350,924,-4,256,182,-1,1188,245,0x1F}},{{566,5010,-48,41,313,0,-800,262,5},{121,367,-63,502,122,-1,45,265,-6},{421,8163,-283,376,507,-1,-1353,77,0},{624,3037,35,367,311,0,959,318,0},{350,924,-4,256,182,-1,1188,245,0x1F},{372,4980,152,898,171,-1,919,230,0xA4},{821,9799,280,114,119,0,41,243,0x8F}},{{121,367,-63,502,122,-1,45,265,-6},{350,924,-4,256,182,-1,1188,245,0x1F},{231,9669,-231,1382,360,0,-750,95,8},{60,6210,-350,1438,357,1,1639,98,0x3D},{954,7668,199,671,229,-0,-167,164,0x06},{264,10326,227,158,49,0,-1685,171,0},{315,1455,177,528,36,-1,-1844,313,1}},{{746,7980,-107,1112,83,-1,374,358,0xDC},{199,4007,-191,1395,150,-1,-1324,22,0x08},{335,5168,70,157,46,-0,-4,71,0xC1},{60,6210,-350,1438,357,1,1639,98,0x3D},{801,2002,104,432,75,-0,-86,145,0x1B},{593,5506,-426,876,79,-0,-117,52,-1},{841,2620,-469,60,336,-1,-204,123,0xEF}},{{990,7696,-406,140,54,1,-1764,223,0xF4},{541,7944,-15,820,53,-1,-1120,57,1},{624,3037,35,367,311,0,959,318,0},{624,3037,35,367,311,0,959,318,0},{541,7944,-15,820,53,-1,-1120,57,1},{990,7696,-406,140,54,1,-1764,223,0xF4},{199,4007,-191,1395,150,-1,-1324,22,0x08}},{{553,2374,-152,183,243,0,669,330,0},{60,6210,-350,1438,357,1,1639,98,0x3D},{333,3571,365,904,451,-1,-1762,326,6},{120,9908,-425,372,430,-1,221,40,0x75},{145,8738,-386,467,126,1,1110,55,0x98},{83,8132,354,256,108,1,171,249,0xAC},{60,6210,-350,1438,357,1,1639,98,0x3D}}},{{{954,7668,199,671,229,-0,-167,164,0x06},{821,9799,280,114,119,0,41,243,0x8F},{990,7696,-406,140,54,1,-1764,223,0xF4},{5,3937,-289,114,110,-1,9,312,1},{801,2002,104,432,75,-0,-86,145,0x1B},{372,4980,152,898,171,-1,919,230,0xA4},{954,7668,199,671,229,-0,-167,164,0x06}},{{566,5010,-48,41,313,0,-800,262,5},{60,6210,-350,1438,357,1,1639,98,0x3D},{114,2214,234,968,371,1,-155,182,0},{801,2002,104,432,75,-0,-86,145,0x1B},{233,9578,117,827,391,-0,724,41,0x15},{821,9799,280,114,119,0,41,243,0x8F},{421,8163,-283,376,507,-1,-1353,77,0}},{{746,7980,-107,1112,83,-1,374,358,0xDC},{541,7944,-15,820,53,-1,-1120,57,1},{83,8132,354,256,108,1,171,249,0xAC},{315,1455,177,528,36,-1,-1844,313,1},{60,6210,-350,1438,357,1,1639,98,0x3D},{83,8132,354,256,108,1,171,249,0xAC},{145,8738,-386,467,126,1,1110,55,0x98}},{{350,924,-4,256,182,-1,1188,245,0x1F},{199,4007,-191,1395,150,-1,-1324,22,0x08},{624,3037,35,367,311,0,959,318,0},{228,5552,-161,809,98,-0,1993,56,7},{988,5032,8,601,102,1,29,300,-3},{421,8163,-283,376,507,-1,-1353,77,0},{145,8738,-386,467,126,1,1110,55,0x98}},{{593,5506,-426,876,79,-0,-117,52,-1},{350,924,-4,256,182,-1,1188,245,0x1F},{421,8163,-283,376,507,-1,-1353,77,0},{536,6144,-132,1039,370,1,1310,139,0xBF},{145,8738,-386,467,126,1,1110,55,0x98},{536,6144,-132,1039,370,1,1310,139,0xBF},{421,8163,-283,376,507,-1,-1353,77,0}},{{121,367,-63,502,122,-1,45,265,-6},{121,367,-63,502,122,-1,45,265,-6},{333,3571,365,904,451,-1,-1762,326,6},{935,10289,25,52,406,0,46,215,0xCA},{315,1455,177,528,36,-1,-1844,313,1},{264,10326,227,158,49,0,-1685,171,0},{954,7668,199,671,229,-0,-167,164,0x06}},{{233,9578,117,827,391,-0,724,41,0x15},{421,8163,-283,376,507,-1,-1353,77,0},{159,1031,327,1210,73,-0,251,185,0x5B},{60,6210,-350,1438,357,1,1639,98,0x3D},{372,4980,152,898,171,-1,919,230,0xA4},{566,5010,-48,41,313,0,-800,262,5},{60,6210,-350,1438,357,1,1639,98,0x3D}},{{593,5506,-426,876,79,-0,-117,52,-1},{541,7944,-15,820,53,-1,-1120,57,1},{536,6144,-132,1039,370,1,1310,139,0xBF},{801,2002,104,432,75,-0,-86,145,0x1B},{315,1455,177,528,36,-1,-1844,313,1},{593,5506,-426,876,79,-0,-117,52,-1},{199,4007,-191,1395,150,-1,-1324,22,0x08}},{{315,1455,177,528,36,-1,-1844,313,1},{841,2620,-469,60,336,-1,-204,123,0xEF},{231,9669,-231,1382,360,0,-750,95,8},{228,5552,-161,809,98,-0,1993,56,7},{145,8738,-386,467,126,1,1110,55,0x98},{333,3571,365,904,451,-1,-1762,326,6},{841,2620,-469,60,336,-1,-204,123,0xEF}}}};
            int i, j, k;
            g_210 = (l_204[0][2][0] , (*g_466));
        }

                    l_978[2] = &g_11[0];
        (*g_148) = ((safe_lshift_func_int8_t_s_s((((safe_mul_func_uint8_t_u_u((((l_978[2] == (void*)0) , ((void*)0 != (**l_896))) == 0x62), ((((safe_mod_func_int32_t_s_s(((&l_978[2] == (l_985 , l_909[1][0])) | ((void*)0 == l_909[3][5])), (*g_148))) ^ g_210.f4) , g_11[0]) , g_210.f1))) , p_57) | p_57), p_58)) && p_57);
    }

    ((g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 5559, __PRETTY_FUNCTION__));

    g_32[1] = g_986[4][2][3];


    for (p_57 = 0; (p_57 == (-27)); p_57--)
    {
        struct S0 l_989 = {907,8858,-498,755,59,1,-1185,276,0};
        (*g_466) = l_989;
    }
    return &g_33[2];


}







static int32_t * func_64(uint32_t p_65, int8_t p_66)
{
    int32_t **l_483 = &g_148;
    int32_t l_484 = 0x134B46BF;
    int16_t l_486 = 0x7760;
    uint8_t l_502 = 0U;
    struct S0 l_505[3] = {{504,1119,-334,589,69,-1,-1458,263,0x47},{504,1119,-334,589,69,-1,-1458,263,0x47},{504,1119,-334,589,69,-1,-1458,263,0x47}};
    uint32_t l_513 = 0x90DCB62E;
    uint32_t l_514 = 4294967289U;
    struct S0 ***l_605 = &g_465;
    int16_t l_744 = 0x0DAA;
    struct S0 **l_864 = &g_466;
    int32_t **l_874 = &g_32[0];
    struct S0 *l_878 = &g_27;
    int32_t *l_892 = (void*)0;
    int i;
    l_484 = ((safe_mul_func_uint16_t_u_u(((l_483 == (*g_296)) , p_66), ((l_484 , (p_65 , (*l_483))) != (*l_483)))) > ((((~(-3)) , (p_66 & l_486)) , 0x3C17BD79) == p_66));
    l_502 = (safe_mul_func_uint16_t_u_u((safe_div_func_int32_t_s_s((((p_65 != (p_65 == (((0xE95A && ((1 ^ ((((0x7F07BE54 <= ((l_484 , (safe_sub_func_uint32_t_u_u((safe_lshift_func_int8_t_s_s((g_210.f0 || (safe_mod_func_uint16_t_u_u(((+(safe_mul_func_int8_t_s_s(g_27.f6, ((safe_sub_func_uint32_t_u_u(g_210.f2, l_484)) | p_66)))) , p_66), g_210.f2))), g_27.f3)), g_27.f4))) , p_65)) && p_66) != (-1)) && 0x6F99F1B5)) <= p_66)) , g_11[0]) > p_65))) == 1) , 0x86C95569), p_66)), g_27.f4));
    if (l_502)
    {
        int32_t *l_503 = &g_33[4];
        return l_503;


    }
    else
    {
        struct S0 l_504 = {168,8079,-485,460,489,1,897,9,0};
        struct S0 ***l_512 = &g_465;
        uint16_t l_603 = 6U;
        int8_t l_622 = 1;
        struct S0 **l_632 = (void*)0;
        int32_t *l_648 = &g_11[0];
        int32_t ***l_658[3][1][10] = {{{&l_483,&l_483,&l_483,&l_483,&l_483,&l_483,&l_483,&l_483,&l_483,&l_483}},{{&l_483,&l_483,&l_483,&l_483,&l_483,&l_483,&l_483,&l_483,&l_483,&l_483}},{{&l_483,&l_483,&l_483,&l_483,&l_483,&l_483,&l_483,&l_483,&l_483,&l_483}}};
        uint8_t l_672 = 0x7B;
        uint8_t l_743 = 0x79;
        int32_t *l_827[1][10];
        uint32_t l_883 = 4294967295U;
        uint32_t l_884 = 4294967295U;
        uint8_t l_885 = 0x88;
        int i, j, k;
        for (i = 0; i < 1; i++)
        {
            for (j = 0; j < 10; j++)
                l_827[i][j] = &g_11[0];
        }
        l_505[2] = (((void*)0 == (*l_483)) , l_504);

{
                        return (*l_874);



                    }

                    for (l_504.f8 = 0; (l_504.f8 == 18); l_504.f8++)
        {
            int32_t ***l_515 = &l_483;
            int32_t l_599 = 0x7B9C64B1;
            int32_t l_606 = 0xDE6D6DF2;
            struct S0 **l_627 = (void*)0;
            if ((((l_504 , (((safe_mul_func_int16_t_s_s(p_65, 0x47D9)) <= (((((*l_483) != ((safe_lshift_func_int16_t_s_s(p_66, 2)) , (*l_483))) , &g_465) != l_512) , (l_513 != l_514))) < 0x30)) , (void*)0) == l_515))
            {
                struct S0 l_526 = {221,7632,372,1118,469,0,-1196,339,8};
                int32_t ***l_539 = &l_483;
                uint32_t l_556[3];
                struct S0 **l_625 = &g_466;
                int32_t ***l_642[6] = {&g_297,(void*)0,&g_297,&g_297,(void*)0,&g_297};
                int32_t l_659 = (-5);
                int i;
                for (i = 0; i < 3; i++)
                    l_556[i] = 0x18C087AE;
                for (l_514 = (-3); (l_514 < 12); ++l_514)
                {
                    int32_t *l_527 = &g_21;
                    int32_t *l_538 = &g_11[0];
                    (**l_515) = (void*)0;

                    ((g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == 0", "t.c", 5658, __PRETTY_FUNCTION__));
                    (*l_538) = ((safe_mod_func_uint32_t_u_u(g_210.f0, g_27.f7)) , ((safe_rshift_func_uint16_t_u_s(((safe_rshift_func_uint16_t_u_s(((((safe_mul_func_uint8_t_u_u(p_66, ((l_526 , l_527) != (((&g_465 != (void*)0) >= ((safe_mul_func_int16_t_s_s((-1), (((((safe_mod_func_int8_t_s_s(((~(safe_add_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_u((+(((*g_466) , 0xB9E8) , (-4))), (*l_527))) && g_27.f2), 4U))) ^ g_27.f4), 0x37)) <= l_526.f6) ^ g_27.f1) != p_65) == p_66))) < l_526.f2)) , (void*)0)))) > g_21) ^ l_504.f8) >= g_210.f0), 9)) ^ l_526.f0), 6)) , p_65));
                }
                if ((l_539 != &g_297))
                {
                    uint32_t l_562 = 1U;
                    int32_t *l_564 = (void*)0;
                    int8_t l_604 = (-1);
                    for (l_526.f8 = (-26); (l_526.f8 != (-10)); l_526.f8++)
                    {
                        int32_t *l_563 = &g_33[4];
                        (**l_515) = (void*)0;

                        ((g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == 0", "t.c", 5671, __PRETTY_FUNCTION__));

{
                        (*l_483) = (&g_80);

                        ((l_892 == 0) ? (void) (0) : __assert_fail ("l_892 == 0", "t.c", 5676, __PRETTY_FUNCTION__));
                        return (&k);


                    }

                    l_504.f6 = ((+(safe_rshift_func_uint8_t_u_u((safe_div_func_int16_t_s_s(p_65, (((+((safe_div_func_uint32_t_u_u((l_526 , (((safe_add_func_uint16_t_u_u((((safe_rshift_func_uint8_t_u_u(g_210.f6, 5)) >= ((*g_466) , (safe_mod_func_uint32_t_u_u(l_556[0], p_65)))) ^ (((safe_div_func_uint8_t_u_u((safe_sub_func_int8_t_s_s((0x6AED & (safe_unary_minus_func_int16_t_s(g_210.f4))), ((l_562 ^ l_562) > 1))), p_65)) , p_65) >= g_27.f6)), g_210.f7)) >= (-5)) > 4294967295U)), (-5))) , g_210.f6)) || g_27.f2) , 1))), g_27.f1))) != 0x9F);
                        l_564 = l_563;

                        (((l_564 >= &g_33[0] && l_564 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_564 >= &g_33[0] && l_564 <= &g_33[4])", "t.c", 5685, __PRETTY_FUNCTION__));
                        (*g_466) = (**g_465);
                    }

                    (((l_564 >= &g_33[0] && l_564 <= &g_33[4]) || l_564 == 0) ? (void) (0) : __assert_fail ("(l_564 >= &g_33[0] && l_564 <= &g_33[4]) || l_564 == 0", "t.c", 5689, __PRETTY_FUNCTION__));
                    if ((safe_mul_func_uint8_t_u_u((safe_sub_func_uint8_t_u_u((((*g_296) != &l_564) < (safe_rshift_func_int8_t_s_s(g_210.f3, (0xEDE5F775 & (safe_mul_func_uint8_t_u_u(((((safe_add_func_int32_t_s_s(((safe_unary_minus_func_int32_t_s((((((p_66 , (safe_rshift_func_int16_t_s_s(0xA605, (p_66 , (((safe_add_func_uint32_t_u_u((safe_rshift_func_int8_t_s_s(((safe_mul_func_int16_t_s_s((((g_27.f5 || (safe_mod_func_int32_t_s_s((safe_div_func_int16_t_s_s((p_66 ^ 0x4F3FB114), 65535U)), p_66))) , g_11[0]) ^ g_210.f7), 0xEDB8)) != 6), g_210.f4)), p_65)) != p_66) >= 250U))))) && g_27.f6) , 0x1F) || p_65) , p_66))) && p_65), g_27.f4)) == 0xD7A9) || g_27.f7) < 0x5E78FEAC), 255U)))))), 0x24)), g_210.f6)))
                    {
                        int32_t *l_596 = &g_11[0];
                        (*l_596) = (safe_rshift_func_int16_t_s_u(g_210.f5, ((g_27.f3 ^ ((safe_rshift_func_int16_t_s_u((p_65 || (safe_mod_func_uint32_t_u_u((g_33[2] , g_4), ((safe_add_func_int8_t_s_s(p_66, p_65)) & g_27.f7)))), ((-1) & 65528U))) && p_66)) | g_4)));

{
                    int32_t *l_2084 = &l_606;
                    return g_148;




                }

                    (*l_596) = ((((p_66 , (((((void*)0 == &g_11[0]) != ((-1) == (*l_596))) , ((((safe_rshift_func_uint16_t_u_u((((void*)0 != &l_564) && l_504.f2), 12)) , ((((*l_515) == &l_596) && 1) | 0U)) , p_66) , (**l_515))) == (void*)0)) | l_505[2].f3) && 0xCA7CFC12) < l_599);
                        (*l_596) = ((((!p_65) , (*g_465)) == (void*)0) <= 0x7A8A);
                    }
                    else
                    {
                        l_606 = (((safe_div_func_uint32_t_u_u(l_603, l_604)) , &g_465) == l_605);
                        (*l_483) = (*l_483);
                        l_564 = (**l_515);

                        ((l_564 == 0 || (l_564 >= &g_11[0] && l_564 <= &g_11[0]) || (l_564 >= &g_33[0] && l_564 <= &g_33[4])) ? (void) (0) : __assert_fail ("l_564 == 0 || (l_564 >= &g_11[0] && l_564 <= &g_11[0]) || (l_564 >= &g_33[0] && l_564 <= &g_33[4])", "t.c", 5713, __PRETTY_FUNCTION__));
                    }

                    ((l_564 == 0 || (l_564 >= &g_11[0] && l_564 <= &g_11[0]) || (l_564 >= &g_33[0] && l_564 <= &g_33[4])) ? (void) (0) : __assert_fail ("l_564 == 0 || (l_564 >= &g_11[0] && l_564 <= &g_11[0]) || (l_564 >= &g_33[0] && l_564 <= &g_33[4])", "t.c", 5716, __PRETTY_FUNCTION__));
                }
                else
                {
                    struct S0 l_607 = {93,5110,425,994,20,1,-800,138,0xCA};
                    int32_t ***l_612[6][3][2] = {{{&g_297,&g_297},{&g_297,&g_297},{(void*)0,&g_297}},{{(void*)0,&g_297},{&g_297,&g_297},{&g_297,&g_297}},{{(void*)0,&g_297},{(void*)0,&g_297},{&g_297,&g_297}},{{&g_297,&g_297},{(void*)0,&g_297},{(void*)0,&g_297}},{{&g_297,&g_297},{&g_297,&g_297},{(void*)0,&g_297}},{{(void*)0,&g_297},{&g_297,&g_297},{&g_297,&g_297}}};
                    struct S0 ***l_621 = &g_465;
                    int i, j, k;
                    (**g_465) = l_607;
                    if ((safe_lshift_func_int8_t_s_s(((safe_rshift_func_uint16_t_u_u(g_27.f8, 14)) || (((l_612[5][0][0] == l_612[5][0][0]) , &g_465) == &g_465)), ((!((safe_lshift_func_uint8_t_u_s((safe_mul_func_uint16_t_u_u(g_210.f3, (+((safe_mod_func_uint8_t_u_u(p_66, 2U)) , ((void*)0 != l_621))))), 4)) < g_33[2])) != l_622))))
                    {
                        l_526.f6 = (safe_lshift_func_int8_t_s_s((p_65 & (l_625 != ((safe_unary_minus_func_int32_t_s((3U != ((void*)0 != &g_297)))) , l_627))), ((!g_210.f5) && (safe_mod_func_int16_t_s_s((~((void*)0 == l_632)), 0xC8AF)))));
                    }
                    else
                    {
                        int8_t l_646 = 0;
                        int32_t l_647 = 0x1D811D60;
                        if (p_66)
                            break;
                        l_647 = (safe_mod_func_int32_t_s_s(((l_504.f4 , (safe_rshift_func_int8_t_s_u(((safe_sub_func_int32_t_s_s((l_504.f0 | (!(p_65 > p_65))), (safe_lshift_func_int16_t_s_u((&g_297 != l_642[0]), p_66)))) & (+(((((((((safe_mul_func_uint16_t_u_u(0x1DE6, l_646)) | l_646) , 0U) <= g_27.f6) , &g_465) != (void*)0) , g_80) , 0xC7AE) & g_11[0]))), p_66))) , (-1)), g_4));


{
            struct S0 l_204[4][9][7] = {{{{771,1558,-451,513,27,-1,1511,192,-1},{935,10289,25,52,406,0,46,215,0xCA},{120,9908,-425,372,430,-1,221,40,0x75},{910,3461,-269,465,261,-1,-660,305,1},{5,3937,-289,114,110,-1,9,312,1},{954,7668,199,671,229,-0,-167,164,0x06},{754,9876,420,277,125,-1,380,261,-1}},{{350,924,-4,256,182,-1,1188,245,0x1F},{591,4688,-381,515,88,0,604,162,-4},{121,367,-63,502,122,-1,45,265,-6},{315,1455,177,528,36,-1,-1844,313,1},{481,8269,239,242,179,-1,-1345,298,2},{60,6210,-350,1438,357,1,1639,98,0x3D},{233,9578,117,827,391,-0,724,41,0x15}},{{959,822,223,164,471,0,487,121,-1},{273,1597,133,825,244,-0,-1846,197,0x54},{821,9799,280,114,119,0,41,243,0x8F},{910,3461,-269,465,261,-1,-660,305,1},{591,4688,-381,515,88,0,604,162,-4},{199,4007,-191,1395,150,-1,-1324,22,0x08},{709,4173,0,827,80,0,1811,48,-1}},{{709,4173,0,827,80,0,1811,48,-1},{233,9578,117,827,391,-0,724,41,0x15},{553,2374,-152,183,243,0,669,330,0},{264,10326,227,158,49,0,-1685,171,0},{541,7944,-15,820,53,-1,-1120,57,1},{841,2620,-469,60,336,-1,-204,123,0xEF},{264,10326,227,158,49,0,-1685,171,0}},{{350,924,-4,256,182,-1,1188,245,0x1F},{231,9669,-231,1382,360,0,-750,95,8},{60,6210,-350,1438,357,1,1639,98,0x3D},{954,7668,199,671,229,-0,-167,164,0x06},{264,10326,227,158,49,0,-1685,171,0},{315,1455,177,528,36,-1,-1844,313,1},{935,10289,25,52,406,0,46,215,0xCA}},{{264,10326,227,158,49,0,-1685,171,0},{231,9669,-231,1382,360,0,-750,95,8},{335,5168,70,157,46,-0,-4,71,0xC1},{303,5148,510,1166,279,-1,-319,238,-4},{754,9876,420,277,125,-1,380,261,-1},{821,9799,280,114,119,0,41,243,0x8F},{754,9876,420,277,125,-1,380,261,-1}},{{405,7883,-403,939,348,0,219,335,0},{233,9578,117,827,391,-0,724,41,0x15},{233,9578,117,827,391,-0,724,41,0x15},{405,7883,-403,939,348,0,219,335,0},{5,3937,-289,114,110,-1,9,312,1},{350,924,-4,256,182,-1,1188,245,0x1F},{591,4688,-381,515,88,0,604,162,-4}},{{145,8738,-386,467,126,1,1110,55,0x98},{273,1597,133,825,244,-0,-1846,197,0x54},{954,7668,199,671,229,-0,-167,164,0x06},{553,2374,-152,183,243,0,669,330,0},{771,1558,-451,513,27,-1,1511,192,-1},{145,8738,-386,467,126,1,1110,55,0x98},{841,2620,-469,60,336,-1,-204,123,0xEF}},{{273,1597,133,825,244,-0,-1846,197,0x54},{591,4688,-381,515,88,0,604,162,-4},{335,5168,70,157,46,-0,-4,71,0xC1},{264,10326,227,158,49,0,-1685,171,0},{709,4173,0,827,80,0,1811,48,-1},{199,4007,-191,1395,150,-1,-1324,22,0x08},{591,4688,-381,515,88,0,604,162,-4}}},{{{23,9155,154,355,16,-1,-1706,283,0x7E},{935,10289,25,52,406,0,46,215,0xCA},{350,924,-4,256,182,-1,1188,245,0x1F},{771,1558,-451,513,27,-1,1511,192,-1},{954,7668,199,671,229,-0,-167,164,0x06},{315,1455,177,528,36,-1,-1844,313,1},{754,9876,420,277,125,-1,380,261,-1}},{{121,367,-63,502,122,-1,45,265,-6},{481,8269,239,242,179,-1,-1345,298,2},{120,9908,-425,372,430,-1,221,40,0x75},{553,2374,-152,183,243,0,669,330,0},{481,8269,239,242,179,-1,-1345,298,2},{233,9578,117,827,391,-0,724,41,0x15},{935,10289,25,52,406,0,46,215,0xCA}},{{405,7883,-403,939,348,0,219,335,0},{771,1558,-451,513,27,-1,1511,192,-1},{821,9799,280,114,119,0,41,243,0x8F},{23,9155,154,355,16,-1,-1706,283,0x7E},{481,8269,239,242,179,-1,-1345,298,2},{421,8163,-283,376,507,-1,-1353,77,0},{264,10326,227,158,49,0,-1685,171,0}},{{709,4173,0,827,80,0,1811,48,-1},{841,2620,-469,60,336,-1,-204,123,0xEF},{954,7668,199,671,229,-0,-167,164,0x06},{83,8132,354,256,108,1,171,249,0xAC},{954,7668,199,671,229,-0,-167,164,0x06},{841,2620,-469,60,336,-1,-204,123,0xEF},{709,4173,0,827,80,0,1811,48,-1}},{{145,8738,-386,467,126,1,1110,55,0x98},{264,10326,227,158,49,0,-1685,171,0},{746,7980,-107,1112,83,-1,374,358,0xDC},{954,7668,199,671,229,-0,-167,164,0x06},{709,4173,0,827,80,0,1811,48,-1},{541,7944,-15,820,53,-1,-1120,57,1},{233,9578,117,827,391,-0,724,41,0x15}},{{333,3571,365,904,451,-1,-1762,326,6},{231,9669,-231,1382,360,0,-750,95,8},{421,8163,-283,376,507,-1,-1353,77,0},{591,4688,-381,515,88,0,604,162,-4},{771,1558,-451,513,27,-1,1511,192,-1},{421,8163,-283,376,507,-1,-1353,77,0},{754,9876,420,277,125,-1,380,261,-1}},{{591,4688,-381,515,88,0,604,162,-4},{935,10289,25,52,406,0,46,215,0xCA},{159,1031,327,1210,73,-0,251,185,0x5B},{935,10289,25,52,406,0,46,215,0xCA},{988,5032,8,601,102,1,29,300,-3},{990,7696,-406,140,54,1,-1764,223,0xF4},{841,2620,-469,60,336,-1,-204,123,0xEF}},{{593,5506,-426,876,79,-0,-117,52,-1},{315,1455,177,528,36,-1,-1844,313,1},{801,2002,104,432,75,-0,-86,145,0x1B},{536,6144,-132,1039,370,1,1310,139,0xBF},{541,7944,-15,820,53,-1,-1120,57,1},{593,5506,-426,876,79,-0,-117,52,-1},{421,8163,-283,376,507,-1,-1353,77,0}},{{954,7668,199,671,229,-0,-167,164,0x06},{233,9578,117,827,391,-0,724,41,0x15},{333,3571,365,904,451,-1,-1762,326,6},{228,5552,-161,809,98,-0,1993,56,7},{350,924,-4,256,182,-1,1188,245,0x1F},{264,10326,227,158,49,0,-1685,171,0},{233,9578,117,827,391,-0,724,41,0x15}}},{{{954,7668,199,671,229,-0,-167,164,0x06},{421,8163,-283,376,507,-1,-1353,77,0},{114,2214,234,968,371,1,-155,182,0},{315,1455,177,528,36,-1,-1844,313,1},{372,4980,152,898,171,-1,919,230,0xA4},{372,4980,152,898,171,-1,919,230,0xA4},{315,1455,177,528,36,-1,-1844,313,1}},{{593,5506,-426,876,79,-0,-117,52,-1},{841,2620,-469,60,336,-1,-204,123,0xEF},{593,5506,-426,876,79,-0,-117,52,-1},{801,2002,104,432,75,-0,-86,145,0x1B},{60,6210,-350,1438,357,1,1639,98,0x3D},{335,5168,70,157,46,-0,-4,71,0xC1},{199,4007,-191,1395,150,-1,-1324,22,0x08}},{{60,6210,-350,1438,357,1,1639,98,0x3D},{541,7944,-15,820,53,-1,-1120,57,1},{231,9669,-231,1382,360,0,-750,95,8},{5,3937,-289,114,110,-1,9,312,1},{841,2620,-469,60,336,-1,-204,123,0xEF},{333,3571,365,904,451,-1,-1762,326,6},{145,8738,-386,467,126,1,1110,55,0x98}},{{120,9908,-425,372,430,-1,221,40,0x75},{421,8163,-283,376,507,-1,-1353,77,0},{801,2002,104,432,75,-0,-86,145,0x1B},{120,9908,-425,372,430,-1,221,40,0x75},{988,5032,8,601,102,1,29,300,-3},{335,5168,70,157,46,-0,-4,71,0xC1},{350,924,-4,256,182,-1,1188,245,0x1F}},{{566,5010,-48,41,313,0,-800,262,5},{121,367,-63,502,122,-1,45,265,-6},{421,8163,-283,376,507,-1,-1353,77,0},{624,3037,35,367,311,0,959,318,0},{350,924,-4,256,182,-1,1188,245,0x1F},{372,4980,152,898,171,-1,919,230,0xA4},{821,9799,280,114,119,0,41,243,0x8F}},{{121,367,-63,502,122,-1,45,265,-6},{350,924,-4,256,182,-1,1188,245,0x1F},{231,9669,-231,1382,360,0,-750,95,8},{60,6210,-350,1438,357,1,1639,98,0x3D},{954,7668,199,671,229,-0,-167,164,0x06},{264,10326,227,158,49,0,-1685,171,0},{315,1455,177,528,36,-1,-1844,313,1}},{{746,7980,-107,1112,83,-1,374,358,0xDC},{199,4007,-191,1395,150,-1,-1324,22,0x08},{335,5168,70,157,46,-0,-4,71,0xC1},{60,6210,-350,1438,357,1,1639,98,0x3D},{801,2002,104,432,75,-0,-86,145,0x1B},{593,5506,-426,876,79,-0,-117,52,-1},{841,2620,-469,60,336,-1,-204,123,0xEF}},{{990,7696,-406,140,54,1,-1764,223,0xF4},{541,7944,-15,820,53,-1,-1120,57,1},{624,3037,35,367,311,0,959,318,0},{624,3037,35,367,311,0,959,318,0},{541,7944,-15,820,53,-1,-1120,57,1},{990,7696,-406,140,54,1,-1764,223,0xF4},{199,4007,-191,1395,150,-1,-1324,22,0x08}},{{553,2374,-152,183,243,0,669,330,0},{60,6210,-350,1438,357,1,1639,98,0x3D},{333,3571,365,904,451,-1,-1762,326,6},{120,9908,-425,372,430,-1,221,40,0x75},{145,8738,-386,467,126,1,1110,55,0x98},{83,8132,354,256,108,1,171,249,0xAC},{60,6210,-350,1438,357,1,1639,98,0x3D}}},{{{954,7668,199,671,229,-0,-167,164,0x06},{821,9799,280,114,119,0,41,243,0x8F},{990,7696,-406,140,54,1,-1764,223,0xF4},{5,3937,-289,114,110,-1,9,312,1},{801,2002,104,432,75,-0,-86,145,0x1B},{372,4980,152,898,171,-1,919,230,0xA4},{954,7668,199,671,229,-0,-167,164,0x06}},{{566,5010,-48,41,313,0,-800,262,5},{60,6210,-350,1438,357,1,1639,98,0x3D},{114,2214,234,968,371,1,-155,182,0},{801,2002,104,432,75,-0,-86,145,0x1B},{233,9578,117,827,391,-0,724,41,0x15},{821,9799,280,114,119,0,41,243,0x8F},{421,8163,-283,376,507,-1,-1353,77,0}},{{746,7980,-107,1112,83,-1,374,358,0xDC},{541,7944,-15,820,53,-1,-1120,57,1},{83,8132,354,256,108,1,171,249,0xAC},{315,1455,177,528,36,-1,-1844,313,1},{60,6210,-350,1438,357,1,1639,98,0x3D},{83,8132,354,256,108,1,171,249,0xAC},{145,8738,-386,467,126,1,1110,55,0x98}},{{350,924,-4,256,182,-1,1188,245,0x1F},{199,4007,-191,1395,150,-1,-1324,22,0x08},{624,3037,35,367,311,0,959,318,0},{228,5552,-161,809,98,-0,1993,56,7},{988,5032,8,601,102,1,29,300,-3},{421,8163,-283,376,507,-1,-1353,77,0},{145,8738,-386,467,126,1,1110,55,0x98}},{{593,5506,-426,876,79,-0,-117,52,-1},{350,924,-4,256,182,-1,1188,245,0x1F},{421,8163,-283,376,507,-1,-1353,77,0},{536,6144,-132,1039,370,1,1310,139,0xBF},{145,8738,-386,467,126,1,1110,55,0x98},{536,6144,-132,1039,370,1,1310,139,0xBF},{421,8163,-283,376,507,-1,-1353,77,0}},{{121,367,-63,502,122,-1,45,265,-6},{121,367,-63,502,122,-1,45,265,-6},{333,3571,365,904,451,-1,-1762,326,6},{935,10289,25,52,406,0,46,215,0xCA},{315,1455,177,528,36,-1,-1844,313,1},{264,10326,227,158,49,0,-1685,171,0},{954,7668,199,671,229,-0,-167,164,0x06}},{{233,9578,117,827,391,-0,724,41,0x15},{421,8163,-283,376,507,-1,-1353,77,0},{159,1031,327,1210,73,-0,251,185,0x5B},{60,6210,-350,1438,357,1,1639,98,0x3D},{372,4980,152,898,171,-1,919,230,0xA4},{566,5010,-48,41,313,0,-800,262,5},{60,6210,-350,1438,357,1,1639,98,0x3D}},{{593,5506,-426,876,79,-0,-117,52,-1},{541,7944,-15,820,53,-1,-1120,57,1},{536,6144,-132,1039,370,1,1310,139,0xBF},{801,2002,104,432,75,-0,-86,145,0x1B},{315,1455,177,528,36,-1,-1844,313,1},{593,5506,-426,876,79,-0,-117,52,-1},{199,4007,-191,1395,150,-1,-1324,22,0x08}},{{315,1455,177,528,36,-1,-1844,313,1},{841,2620,-469,60,336,-1,-204,123,0xEF},{231,9669,-231,1382,360,0,-750,95,8},{228,5552,-161,809,98,-0,1993,56,7},{145,8738,-386,467,126,1,1110,55,0x98},{333,3571,365,904,451,-1,-1762,326,6},{841,2620,-469,60,336,-1,-204,123,0xEF}}}};
            int i, j, k;
            l_526 = (l_204[0][2][0] , (*l_878));
        }

                    g_4 += 1;


                    (**l_539) = l_648;

                        (((g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("(g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 5749, __PRETTY_FUNCTION__));
                        (*l_483) = &l_647;

                        ((g_148 == &l_647) ? (void) (0) : __assert_fail ("g_148 == &l_647", "t.c", 5752, __PRETTY_FUNCTION__));
                    }


                    if (p_66)
                        break;

{
                        uint32_t l_2241 = 0U;
                        struct S0 l_2242 = {718,7833,20,468,426,1,-754,198,-1};
                        (**(&l_878)) = (*(&g_210));
                        if (l_514)
                            break;
                        (**(&l_878)) = (((g_2351 ^ 0) , l_2241) , l_2242);
                        (*(&k)) = (l_885 , 0xA5E0E56F);
                    }

                    return &g_33[2];


                }

if ((*(&g_80)))
                            break;


for (i = 0; (i <= 4); i += 1)
        {
            int i;
        };


                    if (l_505[2].f5)
                    continue;
                for (l_526.f8 = 0; (l_526.f8 != (-28)); l_526.f8 = safe_sub_func_uint32_t_u_u(l_526.f8, 6))
                {
                    int32_t *l_655 = (void*)0;

{
                        int32_t *l_1054[6][1] = {{&g_33[2]},{&g_11[0]},{&g_33[2]},{&g_11[0]},{&g_33[2]},{&g_11[0]}};
                        int i, j, k;
                        g_986[g_4][g_4][g_4] = l_1054[2][0];
                        (*g_297) = (((safe_add_func_uint16_t_u_u((safe_mul_func_uint16_t_u_u((safe_div_func_int32_t_s_s((safe_lshift_func_int8_t_s_u(0x32, 5)), (((l_502 > l_743) , 249U) && ((*g_296) == g_297)))), (((!(safe_rshift_func_int8_t_s_s(0, 2))) == (((l_648 != (void*)0) ^ 0xFA0732C2) && l_743)) || g_2351))), l_504.f6)) , l_743) , l_655);
                    }

                    (***l_605) = (**l_625);
                    (*l_648) = ((p_66 , ((255U | (((safe_unary_minus_func_uint8_t_u(5U)) && g_4) > ((~(((void*)0 == l_655) , (0xFA70 && (safe_mod_func_uint8_t_u_u(((((void*)0 == l_658[2][0][7]) >= l_659) && g_33[0]), p_65))))) != p_66))) >= p_65)) | p_65);
                }
            }
            else
            {
                uint32_t l_663 = 0x8AA41A1D;
                int32_t l_664[7];
                struct S0 l_678 = {434,4928,306,294,0,0,-984,261,0};
                int i;
                for (i = 0; i < 7; i++)
                    {
for (l_513 = (-17); (l_513 < 49); l_513 = safe_add_func_uint8_t_u_u(l_513, 6))
                    {
                        int8_t l_2217 = 2;
                        if (g_80)
                            break;

for (g_2803 = 0; g_2803 < 5; g_2803++)
    {
        transparent_crc(g_1031[g_2803], "g_1031[g_2803]", l_484);
        if (l_484) printf("index = [%d]\n", g_2803);

    };


                    l_2217 = (~0U);
                    };


                    l_664[i] = 0x017C58A9;}
                for (l_622 = 0; (l_622 <= 0); l_622 += 1)
                {
                    uint16_t l_673 = 2U;
                    struct S0 *l_674 = (void*)0;
                    for (l_514 = 0; (l_514 <= 0); l_514 += 1)
                    {
                        int i;

for (l_513 = 0; (l_513 <= 6); l_513 = safe_add_func_int16_t_s_s(l_513, 2))
                    {
                        (**(&l_648)) = (**(&g_148));
                    };


                    (*l_483) = &g_11[l_622];

                        (((g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("(g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 5844, __PRETTY_FUNCTION__));
                    }
                    for (l_513 = 0; (l_513 <= 0); l_513 += 1)
                    {
                        int i, j, k;
                        (*l_483) = (void*)0;

                        ((g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == 0", "t.c", 5851, __PRETTY_FUNCTION__));


{
                        return &g_33[0];



                    }

                    if (l_514)
                break;

                    if (p_66)
                            continue;
                        l_664[6] = (((safe_div_func_uint16_t_u_u(g_27.f4, (safe_unary_minus_func_int8_t_s((g_27.f0 || p_65))))) <= l_663) && p_66);
                        (*l_648) = (g_27.f8 ^ (safe_rshift_func_int16_t_s_s((((**l_605) != ((safe_unary_minus_func_int16_t_s(((safe_mod_func_int32_t_s_s((p_65 , (((safe_add_func_int8_t_s_s(((l_664[5] & g_33[2]) && p_66), (((((((4U > g_210.f2) < (l_672 & l_673)) , 0xB124) ^ p_65) & g_27.f7) || g_27.f0) , g_27.f4))) , l_673) < p_66)), 1)) | g_210.f6))) , l_674)) <= l_664[6]), 7)));
                    }
                }
                for (l_663 = 22; (l_663 > 12); l_663 = safe_sub_func_uint32_t_u_u(l_663, 8))
                {
                    int32_t *l_677 = &g_11[0];
                    (**l_515) = l_677;

                    (((g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("(g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 5875, __PRETTY_FUNCTION__));
                }
                (***l_605) = l_678;
            }
        }



{
        transparent_crc(g_784[g_80], "g_784[g_80]", g_2803);
        if (g_2803) printf("index = [%d]\n", g_80);

    }

                    for (l_502 = (-12); (l_502 >= 9); l_502 = safe_add_func_uint32_t_u_u(l_502, 2))
        {
            int32_t l_693 = 0xF45578ED;
            int32_t *l_703 = &g_21;
            struct S0 l_712 = {727,7545,-209,903,289,-0,189,214,0xC2};
            int32_t ***l_742 = &g_297;
            uint32_t l_785 = 1U;
            for (g_80 = 0; (g_80 != 20); g_80 = safe_add_func_uint32_t_u_u(g_80, 1))
            {
                int32_t *l_710 = &l_693;
                int32_t *l_711 = &g_21;

{
        transparent_crc(g_11[i], "g_11[i]", (*l_703));
        if ((*l_703)) printf("index = [%d]\n", i);

    }

                    if (((safe_lshift_func_int8_t_s_s((safe_sub_func_uint32_t_u_u((safe_div_func_uint32_t_u_u(((safe_rshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u(((l_693 < (*l_648)) >= p_66), (safe_rshift_func_uint16_t_u_s(65535U, (safe_add_func_uint16_t_u_u(6U, (((void*)0 == &g_465) >= (safe_sub_func_int16_t_s_s(g_27.f5, (g_27.f4 < g_27.f5)))))))))), g_210.f8)) != p_65), 1U)), g_27.f7)), 5)) , (-10)))
                {
                    int32_t *l_702 = (void*)0;

for ((*g_148) = 0; ((*g_148) == 6); ++(*g_148))
                    {
                        (*(&l_711)) = l_710;
                        if ((*l_710))
                            break;
                    };


                    if (((safe_div_func_int16_t_s_s(p_66, g_21)) && 0xD865))
                    {
                        (*l_483) = l_702;

                        ((g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == 0", "t.c", 5923, __PRETTY_FUNCTION__));
                        return l_703;


                    }
                    else
                    {

{
                    (**(&g_466)) = (*g_466);
                }

                    g_32[1] = &l_484;


                    }


                }
                else
                {
                    int32_t *l_708[5][2][2] = {{{&g_33[2],(void*)0},{&g_33[2],&g_33[2]}},{{&g_33[2],(void*)0},{&g_33[2],&g_33[2]}},{{&g_33[2],(void*)0},{&g_33[2],&g_33[2]}},{{&g_33[2],(void*)0},{&g_33[2],&g_33[2]}},{{&g_33[2],(void*)0},{&g_33[2],&g_33[2]}}};
                    int i, j, k;

{
                int32_t **l_164[1][1][4] = {{{&l_648,&l_648,&l_648,&l_648}}};
                struct S0 *l_166 = &g_27;
                int i, j, k;
                (*g_297) = ((safe_div_func_uint32_t_u_u(((safe_mod_func_int16_t_s_s((safe_mul_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s(65533U, 10)), ((void*)0 != (&l_648)))), g_4)) && ((safe_sub_func_uint8_t_u_u((l_744 >= 0x7467), ((safe_rshift_func_int16_t_s_u((&(*l_878) == &g_27), 8)) | (!(safe_sub_func_uint8_t_u_u((&k == (*(&l_648))), g_4)))))) < g_4)), (**(&l_648)))) , (void*)0);

                (((*g_297) == 0) ? (void) (0) : __assert_fail ("(*g_297) == 0", "t.c", 5953, __PRETTY_FUNCTION__));
                (*l_166) = g_27;
                (**(*g_296)) = (safe_add_func_int8_t_s_s((g_4 == (safe_mul_func_int16_t_s_s(((safe_sub_func_int8_t_s_s(5, ((*l_878).f4 | 0xDB3D))) ^ g_2619), (g_4 ^ 0x9E95)))), (safe_mod_func_int16_t_s_s((((void*)0 != (*g_296)) , (-1)), 65535U))));
            }

                    for (g_210.f8 = 0; (g_210.f8 >= (-28)); g_210.f8 = safe_sub_func_uint8_t_u_u(g_210.f8, 8))
                    {
                        return &g_33[0];



                    }
                    for (l_672 = (-7); (l_672 >= 57); ++l_672)
                    {
                        int32_t *l_709 = &g_21;
                        return l_709;



                    }
                    (*l_483) = &l_693;

                    ((g_148 == &l_693) ? (void) (0) : __assert_fail ("g_148 == &l_693", "t.c", 5975, __PRETTY_FUNCTION__));
                }



                return l_711;




            }
            if (p_65)
                {
g_210.f8 -= 1;


                    break;}


{
                        uint32_t l_2241 = 0U;
                        struct S0 l_2242 = {718,7833,20,468,426,1,-754,198,-1};
                        (**(&g_466)) = (*(&g_27));
                        if (l_514)
                            break;
                        (**(&g_466)) = (((g_1484 ^ 0) , l_2241) , l_2242);

g_2318 += 1;


                    (*(&g_80)) = (l_502 , 0xA5E0E56F);
                    }

                    for (g_2956 = 0; (g_2956 >= 11); g_2956 = safe_add_func_int8_t_s_s(g_2956, 7))
                    {
                        int32_t **l_1416[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            {
{
            struct S0 l_204[4][9][7] = {{{{771,1558,-451,513,27,-1,1511,192,-1},{935,10289,25,52,406,0,46,215,0xCA},{120,9908,-425,372,430,-1,221,40,0x75},{910,3461,-269,465,261,-1,-660,305,1},{5,3937,-289,114,110,-1,9,312,1},{954,7668,199,671,229,-0,-167,164,0x06},{754,9876,420,277,125,-1,380,261,-1}},{{350,924,-4,256,182,-1,1188,245,0x1F},{591,4688,-381,515,88,0,604,162,-4},{121,367,-63,502,122,-1,45,265,-6},{315,1455,177,528,36,-1,-1844,313,1},{481,8269,239,242,179,-1,-1345,298,2},{60,6210,-350,1438,357,1,1639,98,0x3D},{233,9578,117,827,391,-0,724,41,0x15}},{{959,822,223,164,471,0,487,121,-1},{273,1597,133,825,244,-0,-1846,197,0x54},{821,9799,280,114,119,0,41,243,0x8F},{910,3461,-269,465,261,-1,-660,305,1},{591,4688,-381,515,88,0,604,162,-4},{199,4007,-191,1395,150,-1,-1324,22,0x08},{709,4173,0,827,80,0,1811,48,-1}},{{709,4173,0,827,80,0,1811,48,-1},{233,9578,117,827,391,-0,724,41,0x15},{553,2374,-152,183,243,0,669,330,0},{264,10326,227,158,49,0,-1685,171,0},{541,7944,-15,820,53,-1,-1120,57,1},{841,2620,-469,60,336,-1,-204,123,0xEF},{264,10326,227,158,49,0,-1685,171,0}},{{350,924,-4,256,182,-1,1188,245,0x1F},{231,9669,-231,1382,360,0,-750,95,8},{60,6210,-350,1438,357,1,1639,98,0x3D},{954,7668,199,671,229,-0,-167,164,0x06},{264,10326,227,158,49,0,-1685,171,0},{315,1455,177,528,36,-1,-1844,313,1},{935,10289,25,52,406,0,46,215,0xCA}},{{264,10326,227,158,49,0,-1685,171,0},{231,9669,-231,1382,360,0,-750,95,8},{335,5168,70,157,46,-0,-4,71,0xC1},{303,5148,510,1166,279,-1,-319,238,-4},{754,9876,420,277,125,-1,380,261,-1},{821,9799,280,114,119,0,41,243,0x8F},{754,9876,420,277,125,-1,380,261,-1}},{{405,7883,-403,939,348,0,219,335,0},{233,9578,117,827,391,-0,724,41,0x15},{233,9578,117,827,391,-0,724,41,0x15},{405,7883,-403,939,348,0,219,335,0},{5,3937,-289,114,110,-1,9,312,1},{350,924,-4,256,182,-1,1188,245,0x1F},{591,4688,-381,515,88,0,604,162,-4}},{{145,8738,-386,467,126,1,1110,55,0x98},{273,1597,133,825,244,-0,-1846,197,0x54},{954,7668,199,671,229,-0,-167,164,0x06},{553,2374,-152,183,243,0,669,330,0},{771,1558,-451,513,27,-1,1511,192,-1},{145,8738,-386,467,126,1,1110,55,0x98},{841,2620,-469,60,336,-1,-204,123,0xEF}},{{273,1597,133,825,244,-0,-1846,197,0x54},{591,4688,-381,515,88,0,604,162,-4},{335,5168,70,157,46,-0,-4,71,0xC1},{264,10326,227,158,49,0,-1685,171,0},{709,4173,0,827,80,0,1811,48,-1},{199,4007,-191,1395,150,-1,-1324,22,0x08},{591,4688,-381,515,88,0,604,162,-4}}},{{{23,9155,154,355,16,-1,-1706,283,0x7E},{935,10289,25,52,406,0,46,215,0xCA},{350,924,-4,256,182,-1,1188,245,0x1F},{771,1558,-451,513,27,-1,1511,192,-1},{954,7668,199,671,229,-0,-167,164,0x06},{315,1455,177,528,36,-1,-1844,313,1},{754,9876,420,277,125,-1,380,261,-1}},{{121,367,-63,502,122,-1,45,265,-6},{481,8269,239,242,179,-1,-1345,298,2},{120,9908,-425,372,430,-1,221,40,0x75},{553,2374,-152,183,243,0,669,330,0},{481,8269,239,242,179,-1,-1345,298,2},{233,9578,117,827,391,-0,724,41,0x15},{935,10289,25,52,406,0,46,215,0xCA}},{{405,7883,-403,939,348,0,219,335,0},{771,1558,-451,513,27,-1,1511,192,-1},{821,9799,280,114,119,0,41,243,0x8F},{23,9155,154,355,16,-1,-1706,283,0x7E},{481,8269,239,242,179,-1,-1345,298,2},{421,8163,-283,376,507,-1,-1353,77,0},{264,10326,227,158,49,0,-1685,171,0}},{{709,4173,0,827,80,0,1811,48,-1},{841,2620,-469,60,336,-1,-204,123,0xEF},{954,7668,199,671,229,-0,-167,164,0x06},{83,8132,354,256,108,1,171,249,0xAC},{954,7668,199,671,229,-0,-167,164,0x06},{841,2620,-469,60,336,-1,-204,123,0xEF},{709,4173,0,827,80,0,1811,48,-1}},{{145,8738,-386,467,126,1,1110,55,0x98},{264,10326,227,158,49,0,-1685,171,0},{746,7980,-107,1112,83,-1,374,358,0xDC},{954,7668,199,671,229,-0,-167,164,0x06},{709,4173,0,827,80,0,1811,48,-1},{541,7944,-15,820,53,-1,-1120,57,1},{233,9578,117,827,391,-0,724,41,0x15}},{{333,3571,365,904,451,-1,-1762,326,6},{231,9669,-231,1382,360,0,-750,95,8},{421,8163,-283,376,507,-1,-1353,77,0},{591,4688,-381,515,88,0,604,162,-4},{771,1558,-451,513,27,-1,1511,192,-1},{421,8163,-283,376,507,-1,-1353,77,0},{754,9876,420,277,125,-1,380,261,-1}},{{591,4688,-381,515,88,0,604,162,-4},{935,10289,25,52,406,0,46,215,0xCA},{159,1031,327,1210,73,-0,251,185,0x5B},{935,10289,25,52,406,0,46,215,0xCA},{988,5032,8,601,102,1,29,300,-3},{990,7696,-406,140,54,1,-1764,223,0xF4},{841,2620,-469,60,336,-1,-204,123,0xEF}},{{593,5506,-426,876,79,-0,-117,52,-1},{315,1455,177,528,36,-1,-1844,313,1},{801,2002,104,432,75,-0,-86,145,0x1B},{536,6144,-132,1039,370,1,1310,139,0xBF},{541,7944,-15,820,53,-1,-1120,57,1},{593,5506,-426,876,79,-0,-117,52,-1},{421,8163,-283,376,507,-1,-1353,77,0}},{{954,7668,199,671,229,-0,-167,164,0x06},{233,9578,117,827,391,-0,724,41,0x15},{333,3571,365,904,451,-1,-1762,326,6},{228,5552,-161,809,98,-0,1993,56,7},{350,924,-4,256,182,-1,1188,245,0x1F},{264,10326,227,158,49,0,-1685,171,0},{233,9578,117,827,391,-0,724,41,0x15}}},{{{954,7668,199,671,229,-0,-167,164,0x06},{421,8163,-283,376,507,-1,-1353,77,0},{114,2214,234,968,371,1,-155,182,0},{315,1455,177,528,36,-1,-1844,313,1},{372,4980,152,898,171,-1,919,230,0xA4},{372,4980,152,898,171,-1,919,230,0xA4},{315,1455,177,528,36,-1,-1844,313,1}},{{593,5506,-426,876,79,-0,-117,52,-1},{841,2620,-469,60,336,-1,-204,123,0xEF},{593,5506,-426,876,79,-0,-117,52,-1},{801,2002,104,432,75,-0,-86,145,0x1B},{60,6210,-350,1438,357,1,1639,98,0x3D},{335,5168,70,157,46,-0,-4,71,0xC1},{199,4007,-191,1395,150,-1,-1324,22,0x08}},{{60,6210,-350,1438,357,1,1639,98,0x3D},{541,7944,-15,820,53,-1,-1120,57,1},{231,9669,-231,1382,360,0,-750,95,8},{5,3937,-289,114,110,-1,9,312,1},{841,2620,-469,60,336,-1,-204,123,0xEF},{333,3571,365,904,451,-1,-1762,326,6},{145,8738,-386,467,126,1,1110,55,0x98}},{{120,9908,-425,372,430,-1,221,40,0x75},{421,8163,-283,376,507,-1,-1353,77,0},{801,2002,104,432,75,-0,-86,145,0x1B},{120,9908,-425,372,430,-1,221,40,0x75},{988,5032,8,601,102,1,29,300,-3},{335,5168,70,157,46,-0,-4,71,0xC1},{350,924,-4,256,182,-1,1188,245,0x1F}},{{566,5010,-48,41,313,0,-800,262,5},{121,367,-63,502,122,-1,45,265,-6},{421,8163,-283,376,507,-1,-1353,77,0},{624,3037,35,367,311,0,959,318,0},{350,924,-4,256,182,-1,1188,245,0x1F},{372,4980,152,898,171,-1,919,230,0xA4},{821,9799,280,114,119,0,41,243,0x8F}},{{121,367,-63,502,122,-1,45,265,-6},{350,924,-4,256,182,-1,1188,245,0x1F},{231,9669,-231,1382,360,0,-750,95,8},{60,6210,-350,1438,357,1,1639,98,0x3D},{954,7668,199,671,229,-0,-167,164,0x06},{264,10326,227,158,49,0,-1685,171,0},{315,1455,177,528,36,-1,-1844,313,1}},{{746,7980,-107,1112,83,-1,374,358,0xDC},{199,4007,-191,1395,150,-1,-1324,22,0x08},{335,5168,70,157,46,-0,-4,71,0xC1},{60,6210,-350,1438,357,1,1639,98,0x3D},{801,2002,104,432,75,-0,-86,145,0x1B},{593,5506,-426,876,79,-0,-117,52,-1},{841,2620,-469,60,336,-1,-204,123,0xEF}},{{990,7696,-406,140,54,1,-1764,223,0xF4},{541,7944,-15,820,53,-1,-1120,57,1},{624,3037,35,367,311,0,959,318,0},{624,3037,35,367,311,0,959,318,0},{541,7944,-15,820,53,-1,-1120,57,1},{990,7696,-406,140,54,1,-1764,223,0xF4},{199,4007,-191,1395,150,-1,-1324,22,0x08}},{{553,2374,-152,183,243,0,669,330,0},{60,6210,-350,1438,357,1,1639,98,0x3D},{333,3571,365,904,451,-1,-1762,326,6},{120,9908,-425,372,430,-1,221,40,0x75},{145,8738,-386,467,126,1,1110,55,0x98},{83,8132,354,256,108,1,171,249,0xAC},{60,6210,-350,1438,357,1,1639,98,0x3D}}},{{{954,7668,199,671,229,-0,-167,164,0x06},{821,9799,280,114,119,0,41,243,0x8F},{990,7696,-406,140,54,1,-1764,223,0xF4},{5,3937,-289,114,110,-1,9,312,1},{801,2002,104,432,75,-0,-86,145,0x1B},{372,4980,152,898,171,-1,919,230,0xA4},{954,7668,199,671,229,-0,-167,164,0x06}},{{566,5010,-48,41,313,0,-800,262,5},{60,6210,-350,1438,357,1,1639,98,0x3D},{114,2214,234,968,371,1,-155,182,0},{801,2002,104,432,75,-0,-86,145,0x1B},{233,9578,117,827,391,-0,724,41,0x15},{821,9799,280,114,119,0,41,243,0x8F},{421,8163,-283,376,507,-1,-1353,77,0}},{{746,7980,-107,1112,83,-1,374,358,0xDC},{541,7944,-15,820,53,-1,-1120,57,1},{83,8132,354,256,108,1,171,249,0xAC},{315,1455,177,528,36,-1,-1844,313,1},{60,6210,-350,1438,357,1,1639,98,0x3D},{83,8132,354,256,108,1,171,249,0xAC},{145,8738,-386,467,126,1,1110,55,0x98}},{{350,924,-4,256,182,-1,1188,245,0x1F},{199,4007,-191,1395,150,-1,-1324,22,0x08},{624,3037,35,367,311,0,959,318,0},{228,5552,-161,809,98,-0,1993,56,7},{988,5032,8,601,102,1,29,300,-3},{421,8163,-283,376,507,-1,-1353,77,0},{145,8738,-386,467,126,1,1110,55,0x98}},{{593,5506,-426,876,79,-0,-117,52,-1},{350,924,-4,256,182,-1,1188,245,0x1F},{421,8163,-283,376,507,-1,-1353,77,0},{536,6144,-132,1039,370,1,1310,139,0xBF},{145,8738,-386,467,126,1,1110,55,0x98},{536,6144,-132,1039,370,1,1310,139,0xBF},{421,8163,-283,376,507,-1,-1353,77,0}},{{121,367,-63,502,122,-1,45,265,-6},{121,367,-63,502,122,-1,45,265,-6},{333,3571,365,904,451,-1,-1762,326,6},{935,10289,25,52,406,0,46,215,0xCA},{315,1455,177,528,36,-1,-1844,313,1},{264,10326,227,158,49,0,-1685,171,0},{954,7668,199,671,229,-0,-167,164,0x06}},{{233,9578,117,827,391,-0,724,41,0x15},{421,8163,-283,376,507,-1,-1353,77,0},{159,1031,327,1210,73,-0,251,185,0x5B},{60,6210,-350,1438,357,1,1639,98,0x3D},{372,4980,152,898,171,-1,919,230,0xA4},{566,5010,-48,41,313,0,-800,262,5},{60,6210,-350,1438,357,1,1639,98,0x3D}},{{593,5506,-426,876,79,-0,-117,52,-1},{541,7944,-15,820,53,-1,-1120,57,1},{536,6144,-132,1039,370,1,1310,139,0xBF},{801,2002,104,432,75,-0,-86,145,0x1B},{315,1455,177,528,36,-1,-1844,313,1},{593,5506,-426,876,79,-0,-117,52,-1},{199,4007,-191,1395,150,-1,-1324,22,0x08}},{{315,1455,177,528,36,-1,-1844,313,1},{841,2620,-469,60,336,-1,-204,123,0xEF},{231,9669,-231,1382,360,0,-750,95,8},{228,5552,-161,809,98,-0,1993,56,7},{145,8738,-386,467,126,1,1110,55,0x98},{333,3571,365,904,451,-1,-1762,326,6},{841,2620,-469,60,336,-1,-204,123,0xEF}}}};
            int i, j, k;
            l_504 = (l_204[0][2][0] , g_27);
        }

                    l_1416[i] = &g_986[1][2][3];}
                        l_648 = (&g_2956);

                        ((l_648 == &l_484) ? (void) (0) : __assert_fail ("l_648 == &l_484", "t.c", 6023, __PRETTY_FUNCTION__));
                    };


                    (***l_512) = l_712;
            for (g_210.f8 = (-21); (g_210.f8 <= (-7)); ++g_210.f8)
            {
                uint8_t l_741 = 0U;
                int32_t *l_781[8] = {&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0],&g_11[0]};
                struct S0 *l_822 = &l_505[0];
                int32_t ***l_823 = &l_483;
                int32_t *l_871 = &g_33[2];
                int i;
                (*l_648) = ((*l_703) != ((+(((((safe_lshift_func_int16_t_s_u((safe_mod_func_uint16_t_u_u((p_66 , ((-8) && (((safe_div_func_uint32_t_u_u(p_65, (p_66 , g_210.f8))) <= (+(((p_66 && (((((safe_sub_func_uint32_t_u_u((safe_unary_minus_func_uint32_t_u((!((safe_add_func_int16_t_s_s((((safe_div_func_uint8_t_u_u(((&g_297 != (((safe_lshift_func_int16_t_s_u(((safe_mul_func_int8_t_s_s((safe_add_func_uint8_t_u_u(((safe_mul_func_int16_t_s_s((safe_rshift_func_int16_t_s_s(((0x3B30 == 65530U) || p_66), 3)), (*l_703))) >= g_210.f7), 0x4A)), 0)) , p_65), l_741)) >= p_65) , l_742)) , l_741), 1U)) || 5U) | l_743), l_741)) >= 2U)))), l_741)) >= l_744) ^ g_80) != g_210.f8) ^ 0x4D)) && 0xDE553C88) | 0x974C))) <= 0x4E4D157B))), p_66)), 9)) <= p_65) , (void*)0) != &g_466) > 1)) ^ 65533U));
                if (((safe_mul_func_uint16_t_u_u((safe_mod_func_int16_t_s_s(((safe_mul_func_int8_t_s_s(((((safe_div_func_uint16_t_u_u(((0x8A2D <= (p_66 , ((((((safe_mul_func_uint8_t_u_u((safe_div_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u((((safe_mod_func_int8_t_s_s(((g_27.f6 == 249U) != (safe_mod_func_int16_t_s_s((safe_mul_func_int16_t_s_s((safe_rshift_func_int8_t_s_s((safe_sub_func_int32_t_s_s((p_65 , (safe_sub_func_uint16_t_u_u((((safe_lshift_func_int8_t_s_s(((((safe_mod_func_int32_t_s_s((safe_div_func_int32_t_s_s(p_66, ((((safe_rshift_func_int8_t_s_s((((l_781[1] != l_781[7]) & ((((safe_mod_func_uint8_t_u_u(g_80, 0xE3)) < g_27.f4) , g_210.f3) , g_210.f3)) , (*l_648)), g_210.f3)) <= p_66) , 0x054A) , 0x12462ABA))), p_65)) && 0x2C41) < (*l_648)) >= 1U), 7)) ^ g_784[3]) , 0xA17A), 0xDB26))), p_65)), p_65)), 4)), p_65))), p_66)) , p_66) , p_66), g_27.f2)), 1)), p_65)) , l_785) , g_210.f8) & (-1)) && g_27.f1) == 0x7C5E))) <= p_65), (-3))) || g_210.f2) && 0x98E3A84F) | g_784[1]), 0x39)) < g_27.f6), p_66)), g_27.f8)) | g_27.f4))
                {
                    int32_t *l_786[3][5][4] = {{{&g_21,&g_21,&l_484,&g_11[0]},{(void*)0,&g_21,&g_33[2],&g_11[0]},{&g_33[2],&g_11[0],&g_33[2],&g_11[0]},{&g_33[2],&g_21,(void*)0,&g_11[0]},{&l_484,&g_21,&g_21,&g_21}},{{(void*)0,(void*)0,&g_21,&g_33[2]},{&l_484,&g_11[0],(void*)0,&g_21},{&g_33[2],(void*)0,&g_33[2],(void*)0},{&g_33[2],(void*)0,&g_33[2],&g_21},{(void*)0,&g_11[0],&l_484,&g_33[2]}},{{&g_21,(void*)0,(void*)0,&g_21},{&g_21,&g_21,&l_484,&g_11[0]},{(void*)0,&g_21,&g_33[2],&g_11[0]},{&g_33[2],&g_11[0],&g_33[2],&g_11[0]},{&g_33[2],&g_21,(void*)0,&g_11[0]}}};
                    int i, j, k;


{
                    int32_t l_362 = 0x19E7241B;
                    int32_t *l_385 = &g_33[1];
                    struct S0 *l_397 = &(*g_466);
                    for ((*l_822).f8 = 0; ((*l_822).f8 <= 4); (*l_822).f8 += 1)
                    {
                        int i;
                        (**(*g_296)) = (((~g_33[(*l_822).f8]) < (g_33[(*l_822).f8] >= (((g_33[(*l_822).f8] < l_362) , (*l_878).f1) & (+l_362)))) && ((*g_466) , (((((safe_add_func_uint8_t_u_u((**(*g_296)), ((*g_297) == (*(*g_296))))) ^ (**(*g_296))) && (*g_148)) <= (*(*g_297))) >= g_2619)));
                        (**(*g_296)) = (((safe_rshift_func_uint8_t_u_s(g_4, 5)) , (*(*g_296))) != (((safe_div_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u((safe_mul_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(((((((((safe_rshift_func_uint8_t_u_s((g_4 , 0x0F), (safe_mod_func_int32_t_s_s(((((*(*g_296)) != ((g_4 != ((**(*g_296)) <= ((g_2770 != ((&g_33[(*l_822).f8] != l_385) , (void*)0)) || 0))) , (void*)0)) <= 0x66BC) | (*l_385)), g_33[(*l_822).f8])))) , (*(*g_296))) == (void*)0) & g_4) & (*l_878).f3) , &(*g_296)) == &(*g_296)) , 0x6F4C6E71), 0x5A340AF4)), g_1484)), (**(*g_296)))) , g_2619), (*l_385))), g_33[(*l_822).f8])) > (*l_822).f8) , (*g_297)));
                    }
                    for (l_741 = (-17); (l_741 < 30); ++l_741)
                    {
                        struct S0 l_389[5] = {{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43}};
                        struct S0 *l_390 = (void*)0;
                        struct S0 *l_391 = &l_389[4];
                        int32_t *l_395 = &l_693;
                        int i;
                        (*l_391) = l_389[4];
                        l_502 = (safe_rshift_func_int8_t_s_s((*l_878).f5, 3));
                        l_892 = l_395;

                        ((l_892 == &l_693) ? (void) (0) : __assert_fail ("l_892 == &l_693", "t.c", 6064, __PRETTY_FUNCTION__));
                    }
                    (*l_397) = (*l_878);
                }

                    for ((*l_822).f8 = 1; ((*l_822).f8 <= 7); (*l_822).f8 += 1)
        {
            uint16_t l_2912[10][5] = {{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U}};
            int32_t *l_2923 = (void*)0;
            int i, j;
        };



for (l_484 = 0; l_484 < 1; l_484++)
    {
        transparent_crc(g_11[l_484], "g_11[l_484]", (*l_648));
        if ((*l_648)) printf("index = [%d]\n", l_484);

    }
g_4 += 1;


                    ;


                    (*l_483) = l_786[2][3][0];

                    ((g_148 == &l_484 || g_148 == &l_693 || g_148 == &g_21 || (g_148 >= &g_33[0] && g_148 <= &g_33[4]) || (g_148 >= &g_11[0] && g_148 <= &g_11[0]) || g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == &l_484 || g_148 == &l_693 || g_148 == &g_21 || (g_148 >= &g_33[0] && g_148 <= &g_33[4]) || (g_148 >= &g_11[0] && g_148 <= &g_11[0]) || g_148 == 0", "t.c", 6092, __PRETTY_FUNCTION__));
                    for (l_622 = 6; (l_622 >= 2); l_622 -= 1)
                    {
                        int i;
                        return l_781[l_622];



                    }
                    if (p_65)
                        break;
                }
                else
                {
                    uint8_t l_793 = 4U;
                    struct S0 *l_794 = &g_27;
                    int32_t l_807 = 0;
                    int32_t *l_824 = &g_11[0];
                    (*l_483) = (void*)0;

                    ((g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == 0", "t.c", 6112, __PRETTY_FUNCTION__));
                    if ((safe_mod_func_int8_t_s_s(((safe_lshift_func_uint16_t_u_u(((safe_mul_func_uint16_t_u_u(l_793, (l_794 != (void*)0))) ^ ((safe_add_func_int8_t_s_s((((~((~((safe_sub_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(g_210.f0, (safe_rshift_func_uint16_t_u_s(((safe_div_func_int8_t_s_s((l_807 && (l_712 , (safe_lshift_func_uint16_t_u_u(((safe_mul_func_uint16_t_u_u(0U, (safe_lshift_func_uint8_t_u_s((safe_sub_func_int8_t_s_s((0xCE && (((((((((((safe_div_func_uint32_t_u_u(((safe_mod_func_int32_t_s_s((((((***l_605) , l_822) != (void*)0) || 0x35290354) > (-1)), 2U)) , g_210.f7), (*l_703))) ^ p_65) , (void*)0) != l_823) > l_807) > l_793) || p_66) > (*l_703)) , (void*)0) == &g_466) < g_27.f3)), l_807)), l_807)))) , p_66), 7)))), g_80)) > g_27.f8), p_66)))), 0x3D104C00)) , g_27.f0)) , p_66)) , (*l_648)) >= g_21), p_65)) && p_66)), 6)) < g_210.f8), l_793)))
                    {
                        return l_824;


                    }
                    else
                    {
                        (**l_823) = &g_21;

                        ((g_148 == &g_21) ? (void) (0) : __assert_fail ("g_148 == &g_21", "t.c", 6123, __PRETTY_FUNCTION__));
                        if ((*g_148))
                            {
for (l_603 = (-12); (l_603 == 60); l_603 = safe_add_func_int32_t_s_s(l_603, 6))
        {
            uint16_t l_2775 = 0xE2FA;
            int16_t l_2804 = 8;
            struct S0 **l_2817[2][8][4] = {{{&g_466,&g_466,&g_466,&g_466},{&g_466,&g_466,(void*)0,&g_466},{&g_466,&g_466,&g_466,(void*)0},{&g_466,(void*)0,(void*)0,(void*)0},{&g_466,&g_466,&g_466,&g_466},{(void*)0,&g_466,&g_466,(void*)0},{&g_466,&g_466,(void*)0,&g_466},{&g_466,&g_466,&g_466,(void*)0}},{{(void*)0,&g_466,&g_466,&g_466},{&g_466,&g_466,(void*)0,(void*)0},{&g_466,&g_466,&g_466,&g_466},{&g_466,&g_466,(void*)0,&g_466},{&g_466,&g_466,&g_466,(void*)0},{&g_466,&g_466,(void*)0,&g_466},{&g_466,&g_466,&g_466,&g_466},{&g_466,&g_466,(void*)0,(void*)0}}};
            int32_t l_2882 = (-4);
            int32_t *l_2884[4][4][8] = {{{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]},{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]},{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]},{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]}},{{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]},{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]},{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]},{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]}},{{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]},{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]},{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]},{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]}},{{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]},{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]},{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]},{&g_33[2],&l_807,&g_33[1],&g_33[2],&g_33[2],&g_33[1],&l_807,&g_33[2]}}};
            int i, j, k;
        };


                    break;}
                        (**l_823) = &g_33[2];

                        (((g_148 >= &g_33[0] && g_148 <= &g_33[4])) ? (void) (0) : __assert_fail ("(g_148 >= &g_33[0] && g_148 <= &g_33[4])", "t.c", 6140, __PRETTY_FUNCTION__));
                    }

                    (((g_148 >= &g_33[0] && g_148 <= &g_33[4])) ? (void) (0) : __assert_fail ("(g_148 >= &g_33[0] && g_148 <= &g_33[4])", "t.c", 6143, __PRETTY_FUNCTION__));
                    for (l_793 = 0; (l_793 != 22); l_793 = safe_add_func_uint16_t_u_u(l_793, 7))
                    {

l_744 -= 1;


                    l_827[0][8] = (**l_823);
                        if ((*g_148))
                            continue;
                        return (**l_823);


                    }
                }

                ((g_148 == &l_484 || g_148 == &l_693 || g_148 == &g_21 || (g_148 >= &g_33[0] && g_148 <= &g_33[4]) || (g_148 >= &g_11[0] && g_148 <= &g_11[0]) || g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == &l_484 || g_148 == &l_693 || g_148 == &g_21 || (g_148 >= &g_33[0] && g_148 <= &g_33[4]) || (g_148 >= &g_11[0] && g_148 <= &g_11[0]) || g_148 == 0", "t.c", 6159, __PRETTY_FUNCTION__));

{
            uint16_t l_2912[10][5] = {{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U}};
            int32_t *l_2923 = (void*)0;
            int i, j;
        }

                    for (l_622 = (-19); (l_622 < (-1)); l_622 = safe_add_func_uint16_t_u_u(l_622, 8))
                {
                    int32_t *l_849[9] = {&l_484,&l_484,&l_484,&l_484,&l_484,&l_484,&l_484,&l_484,&l_484};
                    int16_t l_869 = 0xD887;
                    int32_t **l_870 = &l_849[7];
                    int i;

{
                    int32_t *l_1840 = &(*g_148);
                    for ((*l_703) = 22; ((*l_703) == (-3)); (*l_703) = safe_sub_func_int32_t_s_s((*l_703), 1))
                    {
                        uint8_t l_1841 = 0xAC;
                        (*g_297) = l_1840;
                        (**(*l_605)) = (*(&l_712));
                        (*g_297) = &g_11[0];

if (l_785)
                            break;

                    g_148 = l_648;

                        ((g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == 0", "t.c", 6188, __PRETTY_FUNCTION__));
                    }

                    ((g_148 == 0 || (g_148 >= &g_33[0] && g_148 <= &g_33[4])) ? (void) (0) : __assert_fail ("g_148 == 0 || (g_148 >= &g_33[0] && g_148 <= &g_33[4])", "t.c", 6191, __PRETTY_FUNCTION__));
                    for (g_1484 = 23; (g_1484 >= 1); g_1484--)
                    {
                        int8_t l_1862 = 2;
                        (*g_297) = (((*l_1840) & ((+((safe_unary_minus_func_uint32_t_u((l_484 | ((((safe_div_func_int16_t_s_s((safe_div_func_uint8_t_u_u(((l_1862 >= ((safe_mul_func_int8_t_s_s((g_2803 , (((safe_mul_func_int8_t_s_s(((*l_703) | ((safe_mul_func_int16_t_s_s((safe_lshift_func_int8_t_s_s((-2), ((l_502 || (safe_rshift_func_int16_t_s_s(0x5560, 5))) | 1))), l_1862)) == l_502)), 0x3C)) , 0U) < g_210.f6)), 0)) ^ g_210.f8)) , l_502), 0x04)), 0xF8B9)) | g_210.f6) < 0xDE83) && 0U)))) , g_80)) >= 0x8A4328FC)) , l_703);
                        (**l_864) = (((void*)0 == (&l_632)) , (((l_512 == ((*(&l_693)) , &l_864)) == l_502) , (*(&l_712))));
                        (**(&l_878)) = ((*l_703) , (**(&l_878)));
                        return (*g_297);



                    }
                    l_703 = &g_80;

                    ((l_703 == &g_80) ? (void) (0) : __assert_fail ("l_703 == &g_80", "t.c", 6205, __PRETTY_FUNCTION__));
                }

                    for (l_514 = 0; (l_514 <= 4); l_514 += 1)
                    {
                        int i;
                        (*l_648) = (safe_rshift_func_uint8_t_u_u((9U >= (g_33[l_514] ^ g_27.f6)), ((0x5259 < 0xDEC3) != 0x4EB0)));
                        if (g_33[l_514])
                            {
{
            int32_t ***l_1560 = &(*g_296);
            uint32_t l_1561 = 1U;
            (**(*l_512)) = (((safe_rshift_func_int8_t_s_u((safe_sub_func_uint32_t_u_u(((void*)0 == l_1560), ((g_33[3] <= (*l_822).f5) , (((l_885 & l_885) <= l_1561) & ((((-1) | (safe_mul_func_uint16_t_u_u(((+((safe_sub_func_int8_t_s_s(((*(&g_210)) , 0x8C), l_504.f2)) ^ (*(*g_297)))) > g_11[0]), 5))) >= l_504.f7) != (*(&g_2803))))))), 4)) || l_885) , (*(&g_210)));
        }

                    break;}
                    }

if (l_622)
                    {
                        int32_t *l_832 = &g_33[2];
                        if (l_513)
                            break;
                        l_832 = &g_33[2];
                        (*l_822) = g_210;
                        (*l_832) = (-1);
                    }
                    else
                    {
                        int16_t l_847 = 0x83AA;
                        int32_t *l_848 = (void*)0;
                        (*(&k)) = (safe_mul_func_uint8_t_u_u(0x03, (safe_div_func_int8_t_s_s((safe_mul_func_uint8_t_u_u(l_622, (((safe_rshift_func_uint16_t_u_s((safe_add_func_uint16_t_u_u(g_4, (safe_mod_func_int8_t_s_s(((8U ^ (safe_add_func_uint32_t_u_u(l_622, (0xCA840E31 & 4294967293U)))) , (g_210.f8 && g_784[3])), l_847)))), 15)) == g_210.f2) & 0))), l_622))));
                        return l_848;



                    };


                    if (p_66)
                    {
                        int32_t *l_832 = &g_33[2];
                        if (p_65)
                            {
for ((*l_871) = 0; (*l_871) < 9; (*l_871)++)
    {
        for ((*l_892) = 0; (*l_892) < 2; (*l_892)++)
        {
            for (j = 0; j < 2; j++)
            {
                transparent_crc(g_2054[(*l_871)][(*l_892)][j], "g_2054[(*l_871)][(*l_892)][j]", g_2803);
                if (g_2803) printf("index = [%d][%d][%d]\n", (*l_871), (*l_892), j);

            }
        }
    };


                    break;}
                        l_832 = &g_33[2];
                        (*l_822) = l_712;
                        (*l_832) = (-1);
                    }
                    else
                    {
                        int16_t l_847 = 0x83AA;
                        int32_t *l_848 = (void*)0;

l_869 -= 1;


                    (*l_648) = (safe_mul_func_uint8_t_u_u(0x03, (safe_div_func_int8_t_s_s((safe_mul_func_uint8_t_u_u(p_66, (((safe_rshift_func_uint16_t_u_s((safe_add_func_uint16_t_u_u(g_4, (safe_mod_func_int8_t_s_s(((8U ^ (safe_add_func_uint32_t_u_u(p_66, (0xCA840E31 & 4294967293U)))) , (g_210.f8 && g_784[3])), l_847)))), 15)) == g_27.f2) & 0))), p_66))));

{
            struct S0 ***l_1573 = &g_465;
            int32_t l_1584 = 0x3E9E2198;
            l_1584 = (safe_sub_func_int8_t_s_s(((safe_div_func_int8_t_s_s((safe_lshift_func_uint16_t_u_u((((((void*)0 == l_1573) < ((*(*l_864)).f4 == (((0xA69270CB <= (safe_mod_func_int32_t_s_s((*(*l_483)), (safe_lshift_func_uint8_t_u_u((0x1A435ED4 || 0x293A6C42), ((safe_div_func_uint32_t_u_u(((((((((+(((safe_div_func_int16_t_s_s(((&(*l_823) == &l_874) != l_885), (-1))) && 6U) , l_513)) <= 1) ^ l_885) , (*l_878)) , (*(*l_864))) , (*(&g_297))) == (void*)0) == l_885), (*(*l_483)))) | (*(*l_483)))))))) , &g_11[0]) != (void*)0))) < l_885) && 0xFCF112B4), 13)), l_885)) ^ 0xD9BD5AFF), 0xAE));
        }


{
        struct S0 l_989 = {907,8858,-498,755,59,1,-1185,276,0};

for ((*g_148) = 0; (*g_148) < 6; (*g_148)++)
        {
            transparent_crc(g_1271[(*l_703)][(*g_148)], "g_1271[(*l_703)][(*g_148)]", g_21);
            if (g_21) printf("index = [%d][%d]\n", (*l_703), (*g_148));

        };


                    (*l_878) = l_989;
    }

                    return l_848;



                    }
                    (**l_823) = l_849[7];

                    ((g_148 == &g_21 || (g_148 >= &g_11[0] && g_148 <= &g_11[0]) || g_148 == &l_484) ? (void) (0) : __assert_fail ("g_148 == &g_21 || (g_148 >= &g_11[0] && g_148 <= &g_11[0]) || g_148 == &l_484", "t.c", 6306, __PRETTY_FUNCTION__));

{
                        l_827[0][8] = (**(&l_483));
                        if ((*(&g_21)))
                            continue;
                        return (**(&l_483));


                    }

                    if ((safe_add_func_int8_t_s_s((safe_rshift_func_uint8_t_u_s((safe_mul_func_uint16_t_u_u((safe_mod_func_int8_t_s_s((((((safe_add_func_uint32_t_u_u(0x1F548BC5, (safe_mul_func_int16_t_s_s((**l_483), (safe_mul_func_int16_t_s_s((l_864 == (void*)0), ((**l_483) && g_80))))))) , (g_784[0] , ((safe_mul_func_int8_t_s_s((safe_add_func_int8_t_s_s((((***l_823) , 0x34FD2234) < p_65), 0x2F)), 6)) == l_869))) & 1) >= g_210.f8) < 1), 0x5D)), 65527U)), p_65)), 0x47)))
                    {
                        (*l_742) = l_870;

                        (((g_297 >= &l_849[0] && g_297 <= &l_849[8])) ? (void) (0) : __assert_fail ("(g_297 >= &l_849[0] && g_297 <= &l_849[8])", "t.c", 6321, __PRETTY_FUNCTION__));

{
            transparent_crc(g_1271[g_1240][(*l_892)], "g_1271[g_1240][(*l_892)]", j);
            if (j) printf("index = [%d][%d]\n", g_1240, (*l_892));

        }

                    (*l_870) = (**l_823);
                        (**g_296) = l_871;


                    }
                    else
                    {

{
                        g_2956 = (((safe_div_func_uint32_t_u_u(g_1484, l_622)) , &l_864) == (&l_632));
                        (*(*l_823)) = (*(*l_823));
                        l_892 = (**l_823);

                        ((l_892 == 0 || (l_892 >= &g_11[0] && l_892 <= &g_11[0]) || (l_892 >= &g_33[0] && l_892 <= &g_33[4])) ? (void) (0) : __assert_fail ("l_892 == 0 || (l_892 >= &g_11[0] && l_892 <= &g_11[0]) || (l_892 >= &g_33[0] && l_892 <= &g_33[4])", "t.c", 6342, __PRETTY_FUNCTION__));
                    }

                    (*l_870) = (*l_870);
                    }



                }
            }


        }




        (*g_466) = ((((void*)0 == (*g_465)) == (safe_lshift_func_int16_t_s_u(0x462A, (((((((&g_32[1] != l_874) || (!(safe_mul_func_int8_t_s_s((((void*)0 == l_878) >= (safe_mul_func_uint8_t_u_u((safe_sub_func_int8_t_s_s(l_883, ((l_884 && (**l_874)) < p_65))), g_27.f5))), 0x3C)))) && l_885) && 0) ^ p_65) && 2) | g_27.f7)))) , (***l_605));
    }



    if ((g_210.f1 == ((safe_mul_func_uint16_t_u_u(0x3B46, g_11[0])) , (((safe_div_func_uint8_t_u_u((p_65 != (safe_lshift_func_int16_t_s_u((((((((((((void*)0 == (*l_605)) , (*g_465)) == (((((((g_27.f0 , l_892) != (*l_874)) , 1U) > p_66) , 0x5D39) >= p_65) , (void*)0)) <= p_65) || (**l_874)) , p_66) , 0U) > p_66) ^ g_21) && p_65), g_210.f8))), 1U)) , (-2)) ^ 1U))))
    {

g_4 -= 1;


                    (**l_874) = (**l_874);
        (*l_483) = (*l_874);

        (((g_148 >= &g_33[0] && g_148 <= &g_33[4])) ? (void) (0) : __assert_fail ("(g_148 >= &g_33[0] && g_148 <= &g_33[4])", "t.c", 6373, __PRETTY_FUNCTION__));
        (*l_483) = (*l_874);
    }
    else
    {
        int32_t *l_893 = (void*)0;

g_2619 += 1;


                    return l_893;



    }

    (((g_148 >= &g_33[0] && g_148 <= &g_33[4])) ? (void) (0) : __assert_fail ("(g_148 >= &g_33[0] && g_148 <= &g_33[4])", "t.c", 6389, __PRETTY_FUNCTION__));
    return (*l_874);


}







static uint8_t func_71(int16_t p_72, int32_t ** p_73, int16_t p_74)
{
    struct S0 l_79 = {713,1995,-419,31,344,-0,-2044,160,-10};
    int32_t **l_89 = &g_32[1];
    int32_t *l_201[4][5][3] = {{{&g_33[2],(void*)0,&g_21},{(void*)0,&g_33[0],&g_33[0]},{&g_21,&g_33[2],&g_33[0]},{&g_33[2],(void*)0,&g_11[0]},{&g_21,&g_21,&g_33[3]}},{{(void*)0,&g_33[2],&g_11[0]},{&g_33[2],&g_21,&g_33[2]},{&g_33[0],(void*)0,&g_33[2]},{(void*)0,&g_33[2],&g_21},{(void*)0,&g_33[2],&g_11[0]}},{{&g_33[0],&g_33[2],&g_21},{(void*)0,(void*)0,&g_33[2]},{&g_33[2],&g_33[0],&g_33[3]},{&g_33[2],(void*)0,&g_33[2]},{&g_21,&g_33[2],(void*)0}},{{&g_33[0],&g_33[2],&g_33[2]},{(void*)0,&g_21,&g_33[3]},{&g_11[0],&g_33[0],&g_33[2]},{(void*)0,(void*)0,&g_21},{&g_33[0],&g_11[0],&g_11[0]}}};
    int32_t l_215 = (-5);
    uint32_t l_249 = 0x93C2C641;
    int32_t l_346 = 0x0EA3A9A2;
    struct S0 l_347 = {299,1835,311,744,328,1,-1032,177,0};
    uint32_t l_358[3];
    int16_t l_454 = (-1);
    struct S0 *l_459[9][5] = {{&g_27,(void*)0,&g_27,&l_79,&g_27},{&g_210,&g_210,&l_347,&l_347,&g_210},{&l_79,&l_79,&l_347,&l_79,&l_79},{&g_210,&l_347,&l_347,&g_210,&g_210},{&g_27,&l_79,&g_27,(void*)0,&g_27},{&g_210,&g_210,(void*)0,&l_347,&g_210},{&l_79,(void*)0,&l_347,(void*)0,&l_79},{&g_210,&l_347,(void*)0,&g_210,&g_210},{&g_27,(void*)0,&g_27,&l_79,&g_27}};
    struct S0 **l_458 = &l_459[2][4];
    uint32_t l_477 = 0xD8AB56FD;
    int i, j, k;
    for (i = 0; i < 3; i++)
        l_358[i] = 9U;

for (k = 0; k < 1; k++)
    {

if (g_2805)
                    {
                        uint8_t l_1730 = 0xB5;
                        int32_t ***l_1733[5][5][9] = {{{&l_89,&l_89,&(*g_296),&l_89,(void*)0,(void*)0,&(*g_296),&(*g_296),&(*g_296)},{&(*g_296),&(*g_296),(void*)0,&(*g_296),&l_89,&(*g_296),(void*)0,&(*g_296),&(*g_296)},{(void*)0,&l_89,&l_89,&(*g_296),&(*g_296),&(*g_296),&l_89,&l_89,(void*)0},{&(*g_296),(void*)0,(void*)0,&(*g_296),&l_89,&l_89,&l_89,&l_89,&l_89},{(void*)0,&l_89,&l_89,&(*g_296),&(*g_296),&l_89,&(*g_296),&l_89,(void*)0}},{{(void*)0,&l_89,&(*g_296),&(*g_296),(void*)0,&l_89,&l_89,&(*g_296),(void*)0},{&l_89,&(*g_296),&(*g_296),&l_89,&(*g_296),&(*g_296),(void*)0,&l_89,&(*g_296)},{&l_89,&(*g_296),&(*g_296),&(*g_296),(void*)0,&(*g_296),&l_89,&l_89,(void*)0},{&l_89,(void*)0,&(*g_296),&(*g_296),(void*)0,&(*g_296),&l_89,&l_89,(void*)0},{&l_89,&l_89,(void*)0,(void*)0,&(*g_296),&l_89,(void*)0,&l_89,&(*g_296)}},{{&(*g_296),&l_89,&l_89,&l_89,&l_89,&l_89,&(*g_296),&(*g_296),&l_89},{&(*g_296),&l_89,(void*)0,&l_89,&(*g_296),(void*)0,&l_89,&l_89,(void*)0},{&(*g_296),&(*g_296),&(*g_296),&l_89,(void*)0,&l_89,&(*g_296),(void*)0,(void*)0},{&l_89,(void*)0,&(*g_296),&(*g_296),&l_89,(void*)0,&(*g_296),(void*)0,&(*g_296)},{&l_89,(void*)0,&(*g_296),&(*g_296),&l_89,&l_89,&(*g_296),&(*g_296),&(*g_296)}},{{&l_89,&(*g_296),(void*)0,&(*g_296),(void*)0,&l_89,&l_89,(void*)0,(void*)0},{&(*g_296),&l_89,&(*g_296),&(*g_296),(void*)0,&(*g_296),(void*)0,&l_89,(void*)0},{&(*g_296),&(*g_296),&(*g_296),&(*g_296),&(*g_296),&(*g_296),(void*)0,&(*g_296),&l_89},{(void*)0,(void*)0,(void*)0,&(*g_296),(void*)0,&(*g_296),&l_89,(void*)0,&(*g_296)},{&(*g_296),&(*g_296),&(*g_296),&(*g_296),&l_89,&l_89,&(*g_296),&(*g_296),&(*g_296)}},{{&l_89,&(*g_296),&(*g_296),&(*g_296),&(*g_296),&l_89,&l_89,&l_89,&(*g_296)},{&(*g_296),&l_89,&(*g_296),&l_89,(void*)0,&l_89,(void*)0,&(*g_296),&(*g_296)},{&l_89,&(*g_296),&(*g_296),&l_89,&l_89,(void*)0,&l_89,(void*)0,&l_89},{&l_89,&(*g_296),(void*)0,&l_89,&l_89,&(*g_296),&l_89,&l_89,(void*)0},{&(*g_296),(void*)0,&l_89,(void*)0,&l_89,&(*g_296),&(*g_296),(void*)0,&(*g_296)}}};
                        int i, j, k;
                        (*(&g_80)) = ((safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_s(g_1271[0][0], 5)), (0x7F ^ g_2805))) && (*(&g_1240)));
                        (*(&g_80)) = (safe_sub_func_uint32_t_u_u((safe_add_func_uint8_t_u_u((0x322C < (safe_lshift_func_int8_t_s_s((+(safe_rshift_func_uint8_t_u_s(l_1730, (safe_sub_func_uint8_t_u_u((&l_89 != l_1733[4][1][2]), g_210.f7))))), (((!0) && g_2803) < (safe_mod_func_int32_t_s_s((*(&g_80)), (*(&g_1240)))))))), 0U)), l_346));
                    }
                    else
                    {
                        (**l_458) = (g_2805 , (*(*g_465)));
                    };


                    transparent_crc(g_11[k], "g_11[k]", g_2803);

if (((((((safe_add_func_int8_t_s_s((+l_347.f1), l_454)) , (*g_296)) != (g_210 , (*(&(*g_296))))) ^ ((((safe_mul_func_uint8_t_u_u((+(((((safe_lshift_func_uint8_t_u_u(0x06, ((((g_11[0] && (*g_466).f1) || (g_2619 < l_347.f8)) >= (*g_466).f5) , g_33[3]))) , g_210) , l_347.f2) && (**(*g_296))) | l_454)), l_347.f3)) > g_2619) & (**(*g_296))) & l_454)) & 0x2C85) && l_454))
    {
        return l_454;
    }
    else
    {
        int32_t **l_419 = &(*g_297);
        struct S0 *l_435 = &(*g_466);
        (*l_419) = (*(*g_296));

        ((((*g_297) >= &g_33[0] && (*g_297) <= &g_33[4])) ? (void) (0) : __assert_fail ("((*g_297) >= &g_33[0] && (*g_297) <= &g_33[4])", "t.c", 6448, __PRETTY_FUNCTION__));
        (**(*g_296)) = ((((((safe_lshift_func_uint16_t_u_s(g_2619, 12)) ^ (~(safe_add_func_uint16_t_u_u((safe_mul_func_int8_t_s_s((**l_419), (0xA7B4 && (safe_div_func_int16_t_s_s((((((safe_rshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_u((&l_347 != (void*)0), g_1240)), (safe_sub_func_int32_t_s_s((g_2619 ^ (l_435 == (void*)0)), (**(*g_296)))))) > l_347.f6) < l_454) < g_11[0]) >= (*g_466).f5), 1U))))), (*g_466).f8)))) < 0) & (**(*g_296))) | l_454) , (**(*g_296)));
        if (((l_347.f5 , (((((((((g_1240 >= (((~(safe_mod_func_int16_t_s_s((safe_add_func_int32_t_s_s(((safe_sub_func_uint32_t_u_u(((safe_mul_func_int16_t_s_s(((((((safe_div_func_uint16_t_u_u((((((((((((+(*g_466).f7) > 5U) , (*g_296)) == l_419) ^ (safe_unary_minus_func_uint16_t_u((g_2619 == (g_2619 > (((((safe_div_func_int8_t_s_s((((((~(safe_div_func_uint16_t_u_u((*g_466).f7, l_454))) , &l_347) != &g_210) || (-1)) ^ l_347.f8), g_11[0])) > 0xE3) , (*g_296)) != (*g_296)) > 0xF597F79F)))))) || l_347.f5) >= l_454) >= 0x15) , 0xBB2F7794) , (**(*g_296))) & g_2619), (*g_466).f8)) , 0xF7) <= (**(*g_296))) , 246U) , &(*g_466)) == (void*)0), 6)) == 0), l_347.f0)) , 0), (**(*g_296)))), 0xED22))) , (**l_419)) | (**l_419))) ^ l_347.f8) | 1) , l_454) && l_454) == l_454) > (**(*g_296))) , (**(*g_296))) != (-5))) < 5U))
        {
            for (l_347.f8 = 0; (l_347.f8 != 3); ++l_347.f8)
            {
                int32_t l_457[2][3][5] = {{{5,0xC87DFD15,5,0x1F69C2A5,0x1F69C2A5},{5,0xC87DFD15,5,0x1F69C2A5,0x1F69C2A5},{5,0xC87DFD15,5,0x1F69C2A5,0x1F69C2A5}},{{0x62CDD30D,0xD438CA16,0x62CDD30D,5,5},{0x62CDD30D,0xD438CA16,0x62CDD30D,5,5},{0x62CDD30D,0xD438CA16,0x62CDD30D,5,5}}};
                int i, j, k;
                if (l_457[0][0][2])
                {
                    if ((**l_419))
                        break;
                    return (**l_419);
                }
                else
                {
                    for (j = 2; (j >= 0); j -= 1)
                    {
                        (*l_419) = (*l_419);
                        return (*g_148);
                    }
                }
            }

{
                int32_t **l_302 = &g_32[1];
                l_215 = ((0 | ((l_454 ^ ((safe_rshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u(((((l_347.f2 != (**(*g_2770))) , ((&l_419) != &(*g_296))) | ((safe_add_func_int8_t_s_s((((safe_mod_func_int16_t_s_s(((l_302 == (((safe_lshift_func_int16_t_s_u((0xFA & (safe_mul_func_int8_t_s_s((**l_302), l_347.f2))), 15)) == 0x3A923A02) , (*g_2770))) == (*g_466).f3), l_477)) ^ l_454) && l_477), 0x72)) , (**(*g_2770)))) ^ (-9)), (**l_302))), 0)) > 6U)) , (*g_466).f1)) <= l_477);
            }

                    (*l_419) = (*(*g_296));
        }
        else
        {
            struct S0 ***l_460 = &l_458;
            (*l_460) = l_458;
            for (g_2318 = 0; (g_2318 > 39); g_2318 = safe_add_func_uint8_t_u_u(g_2318, 5))
            {
                (*l_419) = (*(*g_296));
                if ((**(*g_296)))
                    continue;
            }
            g_2318 = (safe_add_func_int32_t_s_s(((void*)0 == l_458), ((((&l_435 != (*l_460)) < ((**l_460) != (*l_458))) && ((&l_459[1][1] != &l_435) <= ((safe_div_func_int16_t_s_s((safe_lshift_func_int8_t_s_s((((((safe_mod_func_uint8_t_u_u((0 < 0x71B8), (**l_419))) != l_454) == l_347.f6) ^ (**(*g_296))) | (-2)), 4)), (*g_466).f7)) == l_347.f8))) && g_2619)));
        }
    };


                    if (g_2803) printf("index = [%d]\n", k);

    };


                    if ((safe_lshift_func_uint8_t_u_u((((l_79 , (((((g_80 & 0xA263) & l_79.f2) && ((safe_unary_minus_func_uint8_t_u((p_74 | (g_33[2] >= (safe_add_func_int32_t_s_s(0, 0)))))) , (safe_div_func_int8_t_s_s(((safe_mul_func_uint16_t_u_u(((((((~((void*)0 == l_89)) , &g_32[0]) != &g_32[0]) , 0x7B) == p_72) & p_72), 0x2552)) == p_74), 0x11)))) > (**l_89)) > (**p_73))) ^ (**l_89)) > 0x6495), g_33[1])))
    {
        int32_t l_94 = 7;
        int32_t *l_132 = &g_21;
        struct S0 *l_183 = &l_79;

{
        transparent_crc(g_33[l_215], "g_33[l_215]", g_80);
        if (g_80) printf("index = [%d]\n", l_215);

    }

                    if ((safe_div_func_uint16_t_u_u((safe_mod_func_int8_t_s_s(0x6B, (l_94 ^ (safe_rshift_func_int8_t_s_u(((p_72 , &l_79) != (void*)0), (safe_div_func_uint8_t_u_u(p_74, (((safe_div_func_uint32_t_u_u(p_72, (safe_add_func_int16_t_s_s((safe_lshift_func_int16_t_s_s(((safe_add_func_uint16_t_u_u((**l_89), ((*l_89) != &g_11[0]))) , p_74), g_27.f6)), 0x2722)))) || p_74) , g_27.f7)))))))), l_94)))
        {
            struct S0 *l_107 = &l_79;
            (*l_107) = l_79;
            (*l_107) = ((**p_73) , g_27);
        }
        else
        {
            int16_t l_147 = 0x1D9A;
            int32_t *l_165 = &g_11[0];
            for (l_94 = 0; (l_94 <= 0); l_94 += 1)
            {
                for (p_72 = 0; (p_72 <= 0); p_72 += 1)
                {
                    int i;
                    if ((l_79 , ((g_11[l_94] > g_33[(p_72 + 4)]) == ((((((void*)0 == &g_33[(p_72 + 2)]) > (0xE5FF039C >= ((~0) && (safe_lshift_func_int8_t_s_s((-2), 2))))) && ((safe_add_func_int8_t_s_s(((g_33[(p_72 + 2)] || 1) | g_33[(l_94 + 4)]), g_33[4])) , p_72)) , p_74) == g_27.f4))))
                    {
                        int32_t *l_114 = &g_33[(p_72 + 2)];
                        int32_t **l_113 = &l_114;
                        (*l_113) = (*p_73);

(*l_183).f8 += 1;


                    return g_27.f4;
                    }
                    else
                    {
                        struct S0 *l_115 = &l_79;
                        int i;
                        (*l_115) = g_27;
                        g_11[p_72] = (((g_11[0] , ((safe_mod_func_int8_t_s_s((g_33[(p_72 + 4)] && (safe_div_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s((0xF96B43B7 != (safe_lshift_func_int16_t_s_u(((p_72 >= (safe_add_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u((l_94 <= 0x14D0EF1D), (((((p_73 == (void*)0) > p_74) , &g_27) != l_115) > 1U))), (-1)))) , p_74), p_74))), p_74)), p_74)) | 0), 0)) && (**p_73)), 0x94))), g_27.f1)) , l_132)) == (void*)0) == g_11[0]);
                        return g_4;
                    }
                }
                return p_74;
            }
            if ((safe_add_func_uint8_t_u_u(0xD4, (safe_lshift_func_uint16_t_u_u((safe_add_func_uint32_t_u_u(0U, (safe_mul_func_int8_t_s_s((safe_div_func_int32_t_s_s((safe_lshift_func_uint8_t_u_u((g_27.f0 < ((p_72 || (safe_add_func_uint8_t_u_u(0U, (((**l_89) >= l_147) , (((((void*)0 == &g_27) >= g_27.f5) , (*l_132)) | g_4))))) , p_74)), p_74)), 3)), 0xD3)))), g_33[2])))))
            {
                g_148 = &g_11[0];
            }
            else
            {
                int32_t **l_164[1][1][4] = {{{&g_148,&g_148,&g_148,&g_148}}};
                struct S0 *l_166 = &l_79;
                int i, j, k;

{
                        uint8_t l_1730 = 0xB5;
                        int32_t ***l_1733[5][5][9] = {{{&(*g_2770),&(*g_2770),&g_297,&(*g_2770),(void*)0,(void*)0,&g_297,&g_297,&g_297},{&g_297,&g_297,(void*)0,&g_297,&(*g_2770),&g_297,(void*)0,&g_297,&g_297},{(void*)0,&(*g_2770),&(*g_2770),&g_297,&g_297,&g_297,&(*g_2770),&(*g_2770),(void*)0},{&g_297,(void*)0,(void*)0,&g_297,&(*g_2770),&(*g_2770),&(*g_2770),&(*g_2770),&(*g_2770)},{(void*)0,&(*g_2770),&(*g_2770),&g_297,&g_297,&(*g_2770),&g_297,&(*g_2770),(void*)0}},{{(void*)0,&(*g_2770),&g_297,&g_297,(void*)0,&(*g_2770),&(*g_2770),&g_297,(void*)0},{&(*g_2770),&g_297,&g_297,&(*g_2770),&g_297,&g_297,(void*)0,&(*g_2770),&g_297},{&(*g_2770),&g_297,&g_297,&g_297,(void*)0,&g_297,&(*g_2770),&(*g_2770),(void*)0},{&(*g_2770),(void*)0,&g_297,&g_297,(void*)0,&g_297,&(*g_2770),&(*g_2770),(void*)0},{&(*g_2770),&(*g_2770),(void*)0,(void*)0,&g_297,&(*g_2770),(void*)0,&(*g_2770),&g_297}},{{&g_297,&(*g_2770),&(*g_2770),&(*g_2770),&(*g_2770),&(*g_2770),&g_297,&g_297,&(*g_2770)},{&g_297,&(*g_2770),(void*)0,&(*g_2770),&g_297,(void*)0,&(*g_2770),&(*g_2770),(void*)0},{&g_297,&g_297,&g_297,&(*g_2770),(void*)0,&(*g_2770),&g_297,(void*)0,(void*)0},{&(*g_2770),(void*)0,&g_297,&g_297,&(*g_2770),(void*)0,&g_297,(void*)0,&g_297},{&(*g_2770),(void*)0,&g_297,&g_297,&(*g_2770),&(*g_2770),&g_297,&g_297,&g_297}},{{&(*g_2770),&g_297,(void*)0,&g_297,(void*)0,&(*g_2770),&(*g_2770),(void*)0,(void*)0},{&g_297,&(*g_2770),&g_297,&g_297,(void*)0,&g_297,(void*)0,&(*g_2770),(void*)0},{&g_297,&g_297,&g_297,&g_297,&g_297,&g_297,(void*)0,&g_297,&(*g_2770)},{(void*)0,(void*)0,(void*)0,&g_297,(void*)0,&g_297,&(*g_2770),(void*)0,&g_297},{&g_297,&g_297,&g_297,&g_297,&(*g_2770),&(*g_2770),&g_297,&g_297,&g_297}},{{&(*g_2770),&g_297,&g_297,&g_297,&g_297,&(*g_2770),&(*g_2770),&(*g_2770),&g_297},{&g_297,&(*g_2770),&g_297,&(*g_2770),(void*)0,&(*g_2770),(void*)0,&g_297,&g_297},{&(*g_2770),&g_297,&g_297,&(*g_2770),&(*g_2770),(void*)0,&(*g_2770),(void*)0,&(*g_2770)},{&(*g_2770),&g_297,(void*)0,&(*g_2770),&(*g_2770),&g_297,&(*g_2770),&(*g_2770),(void*)0},{&g_297,(void*)0,&(*g_2770),(void*)0,&(*g_2770),&g_297,&g_297,(void*)0,&g_297}}};
                        int i, j, k;
                        (*g_2221) = ((safe_lshift_func_int8_t_s_s((safe_rshift_func_int8_t_s_s(g_1271[0][0], 5)), (0x7F ^ g_2805))) && (*(&i)));
                        (*(&g_2956)) = (safe_sub_func_uint32_t_u_u((safe_add_func_uint8_t_u_u((0x322C < (safe_lshift_func_int8_t_s_s((+(safe_rshift_func_uint8_t_u_s(l_1730, (safe_sub_func_uint8_t_u_u((&(*g_2770) != l_1733[4][1][2]), (*g_466).f7))))), (((!0) && g_1240) < (safe_mod_func_int32_t_s_s((*(&g_2956)), (*(&i)))))))), 0U)), g_2956));
                    }

                    l_165 = ((safe_div_func_uint32_t_u_u(((safe_mod_func_int16_t_s_s((safe_mul_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s(65533U, 10)), ((void*)0 != p_73))), p_72)) && ((safe_sub_func_uint8_t_u_u((g_4 >= 0x7467), ((safe_rshift_func_int16_t_s_u((&g_27 == &l_79), 8)) | (!(safe_sub_func_uint8_t_u_u((&g_21 == (*p_73)), p_72)))))) < p_72)), (**p_73))) , (void*)0);

                ((l_165 == 0) ? (void) (0) : __assert_fail ("l_165 == 0", "t.c", 6568, __PRETTY_FUNCTION__));

{
                    int i;
                    if (((*l_166) , ((g_11[(*l_165)] > g_33[(g_4 + 4)]) == ((((((void*)0 == &g_33[(g_4 + 2)]) > (0xE5FF039C >= ((~0) && (safe_lshift_func_int8_t_s_s((-2), 2))))) && ((safe_add_func_int8_t_s_s(((g_33[(g_4 + 2)] || 1) | g_33[((*l_165) + 4)]), g_33[4])) , g_4)) , l_454) == (*l_166).f4))))
                    {
                        int32_t *l_114 = &g_33[(g_4 + 2)];
                        int32_t **l_113 = &l_114;
                        (*l_113) = (*(*g_2770));
                        return (*l_166).f4;
                    }
                    else
                    {
                        struct S0 *l_115 = &(*l_166);
                        int i;
                        (*l_115) = (*l_166);
                        g_11[g_4] = (((g_11[0] , ((safe_mod_func_int8_t_s_s((g_33[(g_4 + 4)] && (safe_div_func_uint8_t_u_u(((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint16_t_u_u((safe_lshift_func_int16_t_s_s((0xF96B43B7 != (safe_lshift_func_int16_t_s_u(((g_4 >= (safe_add_func_uint16_t_u_u((safe_sub_func_uint16_t_u_u(((*l_165) <= 0x14D0EF1D), ((((((*g_2770) == (void*)0) > l_454) , &(*l_166)) != l_115) > 1U))), (-1)))) , l_454), l_454))), l_454)), l_454)) | 0), 0)) && (**(*g_2770))), 0x94))), (*l_166).f1)) , g_2221)) == (void*)0) == g_11[0]);
                        return g_4;
                    }
                }

                    (*l_166) = l_79;
                (**l_89) = (safe_add_func_int8_t_s_s((p_72 == (safe_mul_func_int16_t_s_s(((safe_sub_func_int8_t_s_s(5, (g_27.f4 | 0xDB3D))) ^ p_74), (p_72 ^ 0x9E95)))), (safe_mod_func_int16_t_s_s((((void*)0 != l_89) , (-1)), 65535U))));
            }

            ((l_165 == 0 || (l_165 >= &g_11[0] && l_165 <= &g_11[0])) ? (void) (0) : __assert_fail ("l_165 == 0 || (l_165 >= &g_11[0] && l_165 <= &g_11[0])", "t.c", 6593, __PRETTY_FUNCTION__));
            for (p_72 = 0; (p_72 <= 4); p_72 += 1)
            {
                uint32_t l_196 = 0U;
                int i;
                for (p_74 = 4; (p_74 >= 0); p_74 -= 1)
                {
                    int32_t *l_197 = &g_33[p_72];
                    int i;

g_2956 -= 1;


                    g_33[p_72] = (safe_lshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u((&g_33[p_72] != (*p_73)), ((safe_sub_func_int8_t_s_s(0x77, (safe_div_func_int8_t_s_s(((g_33[p_72] || g_11[0]) <= ((void*)0 == l_183)), (safe_mul_func_uint8_t_u_u((safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((**l_89), (((((((*l_89) != (void*)0) , p_74) != 0x4492) , p_72) == (*l_132)) == g_27.f6))), 6)), g_21)), 1U)), g_27.f0)))))) >= g_21))), 13));
                    l_196 = (safe_mod_func_int16_t_s_s(0, p_72));
                    l_132 = (*p_73);

                    (((l_132 >= &g_33[0] && l_132 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_132 >= &g_33[0] && l_132 <= &g_33[4])", "t.c", 6610, __PRETTY_FUNCTION__));
                    l_197 = (*p_73);
                }

                (((l_132 >= &g_33[0] && l_132 <= &g_33[4]) || l_132 == &g_21) ? (void) (0) : __assert_fail ("(l_132 >= &g_33[0] && l_132 <= &g_33[4]) || l_132 == &g_21", "t.c", 6614, __PRETTY_FUNCTION__));
                return g_33[p_72];
            }
        }
        for (p_74 = (-30); (p_74 != 27); p_74++)
        {
            int32_t **l_200[4];
            int i;
            for (i = 0; i < 4; i++)
                l_200[i] = &g_148;
            g_148 = (void*)0;

            ((g_148 == 0) ? (void) (0) : __assert_fail ("g_148 == 0", "t.c", 6626, __PRETTY_FUNCTION__));

for (l_454 = 0; (l_454 <= 4); l_454 += 1)
            {
                uint32_t l_196 = 0U;
                int i;
                for (g_4 = 4; (g_4 >= 0); g_4 -= 1)
                {
                    int32_t *l_197 = &g_33[l_454];
                    int i;
                    g_33[l_454] = (safe_lshift_func_int16_t_s_u((safe_sub_func_uint8_t_u_u((&g_33[l_454] != (*(&g_148))), ((safe_sub_func_int8_t_s_s(0x77, (safe_div_func_int8_t_s_s(((g_33[l_454] || g_11[0]) <= ((void*)0 == l_183)), (safe_mul_func_uint8_t_u_u((safe_add_func_uint8_t_u_u((safe_mod_func_uint32_t_u_u((safe_lshift_func_int16_t_s_s((safe_sub_func_uint32_t_u_u((**(&g_148)), (((((((*(&g_148)) != (void*)0) , g_4) != 0x4492) , l_454) == (*(*(&g_148)))) == l_347.f6))), 6)), (*(*(&g_148))))), 1U)), l_347.f0)))))) >= (*(*(&g_148)))))), 13));
                    l_196 = (safe_mod_func_int16_t_s_s(0, l_454));
                    (*(&g_148)) = (*(&g_148));

                    ((((*(&g_148)) >= &g_33[0] && (*(&g_148)) <= &g_33[4])) ? (void) (0) : __assert_fail ("((*(&g_148)) >= &g_33[0] && (*(&g_148)) <= &g_33[4])", "t.c", 6640, __PRETTY_FUNCTION__));
                    l_197 = (*(&g_148));
                }

                ((((*(&g_148)) >= &g_33[0] && (*(&g_148)) <= &g_33[4]) || (*(&g_148)) == &(*(*(&g_148)))) ? (void) (0) : __assert_fail ("((*(&g_148)) >= &g_33[0] && (*(&g_148)) <= &g_33[4]) || (*(&g_148)) == &(*(*(&g_148)))", "t.c", 6644, __PRETTY_FUNCTION__));
                return g_33[l_454];
            };


                    l_201[3][1][0] = l_132;
        }

        ((g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 6652, __PRETTY_FUNCTION__));
        (**l_89) = (-3);
        for (g_80 = 0; (g_80 > (-25)); g_80 = safe_sub_func_uint8_t_u_u(g_80, 2))
        {
            struct S0 l_204[4][9][7] = {{{{771,1558,-451,513,27,-1,1511,192,-1},{935,10289,25,52,406,0,46,215,0xCA},{120,9908,-425,372,430,-1,221,40,0x75},{910,3461,-269,465,261,-1,-660,305,1},{5,3937,-289,114,110,-1,9,312,1},{954,7668,199,671,229,-0,-167,164,0x06},{754,9876,420,277,125,-1,380,261,-1}},{{350,924,-4,256,182,-1,1188,245,0x1F},{591,4688,-381,515,88,0,604,162,-4},{121,367,-63,502,122,-1,45,265,-6},{315,1455,177,528,36,-1,-1844,313,1},{481,8269,239,242,179,-1,-1345,298,2},{60,6210,-350,1438,357,1,1639,98,0x3D},{233,9578,117,827,391,-0,724,41,0x15}},{{959,822,223,164,471,0,487,121,-1},{273,1597,133,825,244,-0,-1846,197,0x54},{821,9799,280,114,119,0,41,243,0x8F},{910,3461,-269,465,261,-1,-660,305,1},{591,4688,-381,515,88,0,604,162,-4},{199,4007,-191,1395,150,-1,-1324,22,0x08},{709,4173,0,827,80,0,1811,48,-1}},{{709,4173,0,827,80,0,1811,48,-1},{233,9578,117,827,391,-0,724,41,0x15},{553,2374,-152,183,243,0,669,330,0},{264,10326,227,158,49,0,-1685,171,0},{541,7944,-15,820,53,-1,-1120,57,1},{841,2620,-469,60,336,-1,-204,123,0xEF},{264,10326,227,158,49,0,-1685,171,0}},{{350,924,-4,256,182,-1,1188,245,0x1F},{231,9669,-231,1382,360,0,-750,95,8},{60,6210,-350,1438,357,1,1639,98,0x3D},{954,7668,199,671,229,-0,-167,164,0x06},{264,10326,227,158,49,0,-1685,171,0},{315,1455,177,528,36,-1,-1844,313,1},{935,10289,25,52,406,0,46,215,0xCA}},{{264,10326,227,158,49,0,-1685,171,0},{231,9669,-231,1382,360,0,-750,95,8},{335,5168,70,157,46,-0,-4,71,0xC1},{303,5148,510,1166,279,-1,-319,238,-4},{754,9876,420,277,125,-1,380,261,-1},{821,9799,280,114,119,0,41,243,0x8F},{754,9876,420,277,125,-1,380,261,-1}},{{405,7883,-403,939,348,0,219,335,0},{233,9578,117,827,391,-0,724,41,0x15},{233,9578,117,827,391,-0,724,41,0x15},{405,7883,-403,939,348,0,219,335,0},{5,3937,-289,114,110,-1,9,312,1},{350,924,-4,256,182,-1,1188,245,0x1F},{591,4688,-381,515,88,0,604,162,-4}},{{145,8738,-386,467,126,1,1110,55,0x98},{273,1597,133,825,244,-0,-1846,197,0x54},{954,7668,199,671,229,-0,-167,164,0x06},{553,2374,-152,183,243,0,669,330,0},{771,1558,-451,513,27,-1,1511,192,-1},{145,8738,-386,467,126,1,1110,55,0x98},{841,2620,-469,60,336,-1,-204,123,0xEF}},{{273,1597,133,825,244,-0,-1846,197,0x54},{591,4688,-381,515,88,0,604,162,-4},{335,5168,70,157,46,-0,-4,71,0xC1},{264,10326,227,158,49,0,-1685,171,0},{709,4173,0,827,80,0,1811,48,-1},{199,4007,-191,1395,150,-1,-1324,22,0x08},{591,4688,-381,515,88,0,604,162,-4}}},{{{23,9155,154,355,16,-1,-1706,283,0x7E},{935,10289,25,52,406,0,46,215,0xCA},{350,924,-4,256,182,-1,1188,245,0x1F},{771,1558,-451,513,27,-1,1511,192,-1},{954,7668,199,671,229,-0,-167,164,0x06},{315,1455,177,528,36,-1,-1844,313,1},{754,9876,420,277,125,-1,380,261,-1}},{{121,367,-63,502,122,-1,45,265,-6},{481,8269,239,242,179,-1,-1345,298,2},{120,9908,-425,372,430,-1,221,40,0x75},{553,2374,-152,183,243,0,669,330,0},{481,8269,239,242,179,-1,-1345,298,2},{233,9578,117,827,391,-0,724,41,0x15},{935,10289,25,52,406,0,46,215,0xCA}},{{405,7883,-403,939,348,0,219,335,0},{771,1558,-451,513,27,-1,1511,192,-1},{821,9799,280,114,119,0,41,243,0x8F},{23,9155,154,355,16,-1,-1706,283,0x7E},{481,8269,239,242,179,-1,-1345,298,2},{421,8163,-283,376,507,-1,-1353,77,0},{264,10326,227,158,49,0,-1685,171,0}},{{709,4173,0,827,80,0,1811,48,-1},{841,2620,-469,60,336,-1,-204,123,0xEF},{954,7668,199,671,229,-0,-167,164,0x06},{83,8132,354,256,108,1,171,249,0xAC},{954,7668,199,671,229,-0,-167,164,0x06},{841,2620,-469,60,336,-1,-204,123,0xEF},{709,4173,0,827,80,0,1811,48,-1}},{{145,8738,-386,467,126,1,1110,55,0x98},{264,10326,227,158,49,0,-1685,171,0},{746,7980,-107,1112,83,-1,374,358,0xDC},{954,7668,199,671,229,-0,-167,164,0x06},{709,4173,0,827,80,0,1811,48,-1},{541,7944,-15,820,53,-1,-1120,57,1},{233,9578,117,827,391,-0,724,41,0x15}},{{333,3571,365,904,451,-1,-1762,326,6},{231,9669,-231,1382,360,0,-750,95,8},{421,8163,-283,376,507,-1,-1353,77,0},{591,4688,-381,515,88,0,604,162,-4},{771,1558,-451,513,27,-1,1511,192,-1},{421,8163,-283,376,507,-1,-1353,77,0},{754,9876,420,277,125,-1,380,261,-1}},{{591,4688,-381,515,88,0,604,162,-4},{935,10289,25,52,406,0,46,215,0xCA},{159,1031,327,1210,73,-0,251,185,0x5B},{935,10289,25,52,406,0,46,215,0xCA},{988,5032,8,601,102,1,29,300,-3},{990,7696,-406,140,54,1,-1764,223,0xF4},{841,2620,-469,60,336,-1,-204,123,0xEF}},{{593,5506,-426,876,79,-0,-117,52,-1},{315,1455,177,528,36,-1,-1844,313,1},{801,2002,104,432,75,-0,-86,145,0x1B},{536,6144,-132,1039,370,1,1310,139,0xBF},{541,7944,-15,820,53,-1,-1120,57,1},{593,5506,-426,876,79,-0,-117,52,-1},{421,8163,-283,376,507,-1,-1353,77,0}},{{954,7668,199,671,229,-0,-167,164,0x06},{233,9578,117,827,391,-0,724,41,0x15},{333,3571,365,904,451,-1,-1762,326,6},{228,5552,-161,809,98,-0,1993,56,7},{350,924,-4,256,182,-1,1188,245,0x1F},{264,10326,227,158,49,0,-1685,171,0},{233,9578,117,827,391,-0,724,41,0x15}}},{{{954,7668,199,671,229,-0,-167,164,0x06},{421,8163,-283,376,507,-1,-1353,77,0},{114,2214,234,968,371,1,-155,182,0},{315,1455,177,528,36,-1,-1844,313,1},{372,4980,152,898,171,-1,919,230,0xA4},{372,4980,152,898,171,-1,919,230,0xA4},{315,1455,177,528,36,-1,-1844,313,1}},{{593,5506,-426,876,79,-0,-117,52,-1},{841,2620,-469,60,336,-1,-204,123,0xEF},{593,5506,-426,876,79,-0,-117,52,-1},{801,2002,104,432,75,-0,-86,145,0x1B},{60,6210,-350,1438,357,1,1639,98,0x3D},{335,5168,70,157,46,-0,-4,71,0xC1},{199,4007,-191,1395,150,-1,-1324,22,0x08}},{{60,6210,-350,1438,357,1,1639,98,0x3D},{541,7944,-15,820,53,-1,-1120,57,1},{231,9669,-231,1382,360,0,-750,95,8},{5,3937,-289,114,110,-1,9,312,1},{841,2620,-469,60,336,-1,-204,123,0xEF},{333,3571,365,904,451,-1,-1762,326,6},{145,8738,-386,467,126,1,1110,55,0x98}},{{120,9908,-425,372,430,-1,221,40,0x75},{421,8163,-283,376,507,-1,-1353,77,0},{801,2002,104,432,75,-0,-86,145,0x1B},{120,9908,-425,372,430,-1,221,40,0x75},{988,5032,8,601,102,1,29,300,-3},{335,5168,70,157,46,-0,-4,71,0xC1},{350,924,-4,256,182,-1,1188,245,0x1F}},{{566,5010,-48,41,313,0,-800,262,5},{121,367,-63,502,122,-1,45,265,-6},{421,8163,-283,376,507,-1,-1353,77,0},{624,3037,35,367,311,0,959,318,0},{350,924,-4,256,182,-1,1188,245,0x1F},{372,4980,152,898,171,-1,919,230,0xA4},{821,9799,280,114,119,0,41,243,0x8F}},{{121,367,-63,502,122,-1,45,265,-6},{350,924,-4,256,182,-1,1188,245,0x1F},{231,9669,-231,1382,360,0,-750,95,8},{60,6210,-350,1438,357,1,1639,98,0x3D},{954,7668,199,671,229,-0,-167,164,0x06},{264,10326,227,158,49,0,-1685,171,0},{315,1455,177,528,36,-1,-1844,313,1}},{{746,7980,-107,1112,83,-1,374,358,0xDC},{199,4007,-191,1395,150,-1,-1324,22,0x08},{335,5168,70,157,46,-0,-4,71,0xC1},{60,6210,-350,1438,357,1,1639,98,0x3D},{801,2002,104,432,75,-0,-86,145,0x1B},{593,5506,-426,876,79,-0,-117,52,-1},{841,2620,-469,60,336,-1,-204,123,0xEF}},{{990,7696,-406,140,54,1,-1764,223,0xF4},{541,7944,-15,820,53,-1,-1120,57,1},{624,3037,35,367,311,0,959,318,0},{624,3037,35,367,311,0,959,318,0},{541,7944,-15,820,53,-1,-1120,57,1},{990,7696,-406,140,54,1,-1764,223,0xF4},{199,4007,-191,1395,150,-1,-1324,22,0x08}},{{553,2374,-152,183,243,0,669,330,0},{60,6210,-350,1438,357,1,1639,98,0x3D},{333,3571,365,904,451,-1,-1762,326,6},{120,9908,-425,372,430,-1,221,40,0x75},{145,8738,-386,467,126,1,1110,55,0x98},{83,8132,354,256,108,1,171,249,0xAC},{60,6210,-350,1438,357,1,1639,98,0x3D}}},{{{954,7668,199,671,229,-0,-167,164,0x06},{821,9799,280,114,119,0,41,243,0x8F},{990,7696,-406,140,54,1,-1764,223,0xF4},{5,3937,-289,114,110,-1,9,312,1},{801,2002,104,432,75,-0,-86,145,0x1B},{372,4980,152,898,171,-1,919,230,0xA4},{954,7668,199,671,229,-0,-167,164,0x06}},{{566,5010,-48,41,313,0,-800,262,5},{60,6210,-350,1438,357,1,1639,98,0x3D},{114,2214,234,968,371,1,-155,182,0},{801,2002,104,432,75,-0,-86,145,0x1B},{233,9578,117,827,391,-0,724,41,0x15},{821,9799,280,114,119,0,41,243,0x8F},{421,8163,-283,376,507,-1,-1353,77,0}},{{746,7980,-107,1112,83,-1,374,358,0xDC},{541,7944,-15,820,53,-1,-1120,57,1},{83,8132,354,256,108,1,171,249,0xAC},{315,1455,177,528,36,-1,-1844,313,1},{60,6210,-350,1438,357,1,1639,98,0x3D},{83,8132,354,256,108,1,171,249,0xAC},{145,8738,-386,467,126,1,1110,55,0x98}},{{350,924,-4,256,182,-1,1188,245,0x1F},{199,4007,-191,1395,150,-1,-1324,22,0x08},{624,3037,35,367,311,0,959,318,0},{228,5552,-161,809,98,-0,1993,56,7},{988,5032,8,601,102,1,29,300,-3},{421,8163,-283,376,507,-1,-1353,77,0},{145,8738,-386,467,126,1,1110,55,0x98}},{{593,5506,-426,876,79,-0,-117,52,-1},{350,924,-4,256,182,-1,1188,245,0x1F},{421,8163,-283,376,507,-1,-1353,77,0},{536,6144,-132,1039,370,1,1310,139,0xBF},{145,8738,-386,467,126,1,1110,55,0x98},{536,6144,-132,1039,370,1,1310,139,0xBF},{421,8163,-283,376,507,-1,-1353,77,0}},{{121,367,-63,502,122,-1,45,265,-6},{121,367,-63,502,122,-1,45,265,-6},{333,3571,365,904,451,-1,-1762,326,6},{935,10289,25,52,406,0,46,215,0xCA},{315,1455,177,528,36,-1,-1844,313,1},{264,10326,227,158,49,0,-1685,171,0},{954,7668,199,671,229,-0,-167,164,0x06}},{{233,9578,117,827,391,-0,724,41,0x15},{421,8163,-283,376,507,-1,-1353,77,0},{159,1031,327,1210,73,-0,251,185,0x5B},{60,6210,-350,1438,357,1,1639,98,0x3D},{372,4980,152,898,171,-1,919,230,0xA4},{566,5010,-48,41,313,0,-800,262,5},{60,6210,-350,1438,357,1,1639,98,0x3D}},{{593,5506,-426,876,79,-0,-117,52,-1},{541,7944,-15,820,53,-1,-1120,57,1},{536,6144,-132,1039,370,1,1310,139,0xBF},{801,2002,104,432,75,-0,-86,145,0x1B},{315,1455,177,528,36,-1,-1844,313,1},{593,5506,-426,876,79,-0,-117,52,-1},{199,4007,-191,1395,150,-1,-1324,22,0x08}},{{315,1455,177,528,36,-1,-1844,313,1},{841,2620,-469,60,336,-1,-204,123,0xEF},{231,9669,-231,1382,360,0,-750,95,8},{228,5552,-161,809,98,-0,1993,56,7},{145,8738,-386,467,126,1,1110,55,0x98},{333,3571,365,904,451,-1,-1762,326,6},{841,2620,-469,60,336,-1,-204,123,0xEF}}}};
            int i, j, k;

for ((*l_183).f8 = 2; ((*l_183).f8 >= 0); (*l_183).f8 -= 1)
                {
                    for (g_2647 = 0; (g_2647 <= 2); g_2647 += 1)
                    {
                        int32_t ***l_283 = (void*)0;
                        int32_t ***l_284 = (void*)0;
                        int32_t ***l_285 = &l_89;
                        int i, j, k;
                        g_33[(*l_183).f8] = (safe_sub_func_int8_t_s_s((safe_div_func_int8_t_s_s(((((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint8_t_u_s(g_33[((*l_183).f8 + 1)], (safe_lshift_func_uint16_t_u_u(g_2619, 2)))) , ((safe_add_func_int8_t_s_s(p_72, g_1484)) , p_72)), (safe_sub_func_uint16_t_u_u((((65533U != 0x2256) , l_201[(g_2647 + 1)][(g_2647 + 2)][g_2647]) == ((safe_add_func_uint32_t_u_u(3U, (**l_89))) , &g_33[2])), 65533U)))) , g_210.f3) , g_27) , g_27.f3), g_210.f8)), g_2619));
                        (*l_89) = &g_11[0];
                        (*l_285) = &l_201[2][3][2];

                        (((l_89 >= &l_201[0][0][0] && l_89 <= &l_201[3][4][2])) ? (void) (0) : __assert_fail ("(l_89 >= &l_201[0][0][0] && l_89 <= &l_201[3][4][2])", "t.c", 6671, __PRETTY_FUNCTION__));
                    }
                };


                    l_79 = (l_204[0][2][0] , g_27);
        }
    }
    else
    {
        int32_t l_205[9] = {0xF74A46D3,0xF74A46D3,0xF74A46D3,0xF74A46D3,0xF74A46D3,0xF74A46D3,0xF74A46D3,0xF74A46D3,0xF74A46D3};
        int32_t *l_206 = &g_33[2];
        uint16_t l_248 = 8U;
        int i;
        if (l_205[7])
        {
            l_206 = &g_21;

            ((l_206 == &g_21) ? (void) (0) : __assert_fail ("l_206 == &g_21", "t.c", 6689, __PRETTY_FUNCTION__));
        }
        else
        {
            uint16_t l_208 = 6U;
            int32_t *l_225 = (void*)0;
            int32_t **l_227 = &l_225;
            struct S0 *l_256 = &g_27;
            for (p_74 = 0; (p_74 <= 0); p_74 += 1)
            {
                int32_t **l_207[9] = {&g_32[1],&g_32[1],&g_32[1],&g_32[1],&g_32[1],&g_32[1],&g_32[1],&g_32[1],&g_32[1]};
                struct S0 l_209 = {947,10135,-30,1073,154,1,-1298,144,0x49};
                int i;

{
                    if ((**g_297))
                        break;
                    return (**g_297);
                }


{
                        uint8_t l_1841 = 0xAC;
                        (*(*g_296)) = (&g_2956);
                        (**(&(*l_458))) = (*(*l_458));

(*l_256).f8 += 1;


                    (*(*g_296)) = &g_11[0];
                        g_2221 = (&l_215);

                        ((g_2221 == 0) ? (void) (0) : __assert_fail ("g_2221 == 0", "t.c", 6721, __PRETTY_FUNCTION__));
                    }

                    l_206 = &g_11[p_74];

                (((l_206 >= &g_11[0] && l_206 <= &g_11[0])) ? (void) (0) : __assert_fail ("(l_206 >= &g_11[0] && l_206 <= &g_11[0])", "t.c", 6726, __PRETTY_FUNCTION__));
                for (p_72 = 0; (p_72 >= 0); p_72 -= 1)
                {
                    int16_t l_224 = 0xB01B;
                    int32_t *l_258 = &g_33[2];

if (g_80) printf("index = [%d][%d]\n", (*g_148), (*g_148));

                    for (g_80 = 4; (g_80 >= 1); g_80 -= 1)
                    {
                        int i;
                        g_11[p_74] = (l_208 || 0x38);
                        g_148 = l_206;
                        g_210 = l_209;
                    }
                    if ((safe_lshift_func_uint8_t_u_u(((safe_lshift_func_uint8_t_u_u(((l_215 & ((safe_sub_func_int32_t_s_s((safe_mul_func_int16_t_s_s((l_208 ^ (*g_148)), (l_207[7] != &g_148))), (p_72 < (safe_mod_func_uint8_t_u_u(((safe_add_func_uint8_t_u_u((p_72 , (0x23 >= (l_208 > 0x873CE92A))), p_72)) , l_224), p_74))))) , l_208)) && g_210.f7), 4)) , g_210.f0), p_74)))
                    {
                        int32_t *l_226 = (void*)0;
                        int i;
                        l_226 = l_225;
                        g_33[p_72] = (**p_73);
                        if (g_33[p_72])
                            continue;
                    }
                    else
                    {
                        int32_t l_229 = 0xD1979944;
                        int32_t l_232[2];
                        struct S0 l_250 = {931,139,-316,1333,426,1,-370,282,0x71};
                        struct S0 *l_251 = &g_210;
                        int16_t l_257 = 9;
                        int i;
                        for (i = 0; i < 2; i++)
                            l_232[i] = 0xBE73AF67;

{
        (**l_89) = (**l_89);

g_2351 += 1;


                    (*(&g_2221)) = (*l_89);

        ((((&g_80) >= &g_33[0] && (&g_80) <= &g_33[4])) ? (void) (0) : __assert_fail ("((&g_80) >= &g_33[0] && (&g_80) <= &g_33[4])", "t.c", 6769, __PRETTY_FUNCTION__));
        (*(&g_2221)) = (*l_89);
    }

                    (**l_89) = (*l_206);
                        l_227 = &g_148;

                        ((l_227 == &g_148) ? (void) (0) : __assert_fail ("l_227 == &g_148", "t.c", 6776, __PRETTY_FUNCTION__));

for (l_215 = 0; l_215 < 5; l_215++)
    {
        transparent_crc(g_1031[l_215], "g_1031[l_215]", l_346);
        if (l_346) printf("index = [%d]\n", l_215);

    };


                    (*l_251) = ((((+(((((**p_73) , (l_229 == ((g_33[2] == (0 > l_232[1])) ^ (p_74 <= (((safe_lshift_func_int16_t_s_u((safe_mul_func_int16_t_s_s(0xDFC1, ((~(safe_sub_func_uint16_t_u_u((safe_lshift_func_int8_t_s_u((safe_mul_func_int8_t_s_s(g_21, ((((safe_div_func_uint16_t_u_u(((safe_div_func_int32_t_s_s((l_224 >= p_74), g_33[0])) < g_27.f7), g_27.f2)) >= 0x1CCE74E1) == l_248) & l_249))), 4)), p_72))) | (*g_148)))), p_74)) != 0xB84F7E7F) >= g_4))))) || 0x399F47FE) ^ 0x98) , (**p_73))) , l_79) , g_27) , l_250);
                        l_258 = ((((safe_unary_minus_func_int16_t_s(((((safe_add_func_int8_t_s_s(l_224, (safe_unary_minus_func_uint32_t_u(((*l_206) <= ((p_72 >= g_4) | ((g_27.f0 < (&l_250 != ((*l_206) , l_256))) < g_21))))))) | l_250.f3) , l_257) , 0xC70D))) , (void*)0) == &g_32[1]) , (void*)0);

                        ((l_258 == 0) ? (void) (0) : __assert_fail ("l_258 == 0", "t.c", 6789, __PRETTY_FUNCTION__));
                    }

                    ((l_227 == &g_148 || l_227 == &l_225) ? (void) (0) : __assert_fail ("l_227 == &g_148 || l_227 == &l_225", "t.c", 6792, __PRETTY_FUNCTION__));
                    ((l_258 == 0 || (l_258 >= &g_33[0] && l_258 <= &g_33[4])) ? (void) (0) : __assert_fail ("l_258 == 0 || (l_258 >= &g_33[0] && l_258 <= &g_33[4])", "t.c", 6793, __PRETTY_FUNCTION__));

{
                        int32_t **l_1416[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_1416[i] = &g_986[1][2][3];
                        (*p_73) = (&g_1240);

                        (((*p_73) == &i) ? (void) (0) : __assert_fail ("(*p_73) == &i", "t.c", 6802, __PRETTY_FUNCTION__));
                    }

                    for (l_249 = 0; (l_249 <= 6); l_249 = safe_add_func_int16_t_s_s(l_249, 2))
                    {
                        (**l_89) = (**p_73);
                    }
                    return (*l_206);
                }
                g_11[p_74] = (safe_sub_func_uint32_t_u_u(0x6724EC48, ((*l_256) , ((void*)0 != &g_27))));
            }

            (((l_206 >= &g_11[0] && l_206 <= &g_11[0]) || (l_206 >= &g_33[0] && l_206 <= &g_33[4])) ? (void) (0) : __assert_fail ("(l_206 >= &g_11[0] && l_206 <= &g_11[0]) || (l_206 >= &g_33[0] && l_206 <= &g_33[4])", "t.c", 6814, __PRETTY_FUNCTION__));
            (*l_206) = (&g_27 != &g_210);
            for (p_74 = 0; (p_74 >= 16); ++p_74)
            {
                uint16_t l_277 = 0x1CB2;
                struct S0 l_282 = {280,730,496,1318,273,-0,-1103,209,0x8D};
                (*l_227) = l_206;
                for (l_79.f8 = 2; (l_79.f8 >= 0); l_79.f8 -= 1)
                {
                    for (l_249 = 0; (l_249 <= 2); l_249 += 1)
                    {
                        int32_t ***l_283 = (void*)0;
                        int32_t ***l_284 = (void*)0;
                        int32_t ***l_285 = &l_227;
                        int i, j, k;
                        g_33[l_79.f8] = (safe_sub_func_int8_t_s_s((safe_div_func_int8_t_s_s(((((safe_sub_func_uint8_t_u_u(((safe_rshift_func_uint8_t_u_s(g_33[(l_79.f8 + 1)], (safe_lshift_func_uint16_t_u_u(p_72, 2)))) , ((safe_add_func_int8_t_s_s(p_74, l_277)) , p_74)), (safe_sub_func_uint16_t_u_u((((65533U != 0x2256) , l_201[(l_249 + 1)][(l_249 + 2)][l_249]) == ((safe_add_func_uint32_t_u_u(3U, (**p_73))) , &g_33[2])), 65533U)))) , g_27.f3) , l_282) , l_282.f3), g_210.f8)), p_72));
                        (*l_227) = &g_11[0];
                        (*l_285) = &l_201[2][3][2];

                        (((l_227 >= &l_201[0][0][0] && l_227 <= &l_201[3][4][2])) ? (void) (0) : __assert_fail ("(l_227 >= &l_201[0][0][0] && l_227 <= &l_201[3][4][2])", "t.c", 6833, __PRETTY_FUNCTION__));
                    }
                }
                (*l_227) = (*p_73);
            }

            (((l_225 >= &g_11[0] && l_225 <= &g_11[0]) || (l_225 >= &g_33[0] && l_225 <= &g_33[4]) || l_225 == 0) ? (void) (0) : __assert_fail ("(l_225 >= &g_11[0] && l_225 <= &g_11[0]) || (l_225 >= &g_33[0] && l_225 <= &g_33[4]) || l_225 == 0", "t.c", 6839, __PRETTY_FUNCTION__));
            (((l_227 >= &l_201[0][0][0] && l_227 <= &l_201[3][4][2]) || l_227 == &l_225) ? (void) (0) : __assert_fail ("(l_227 >= &l_201[0][0][0] && l_227 <= &l_201[3][4][2]) || l_227 == &l_225", "t.c", 6840, __PRETTY_FUNCTION__));
        }

        (((l_206 >= &g_11[0] && l_206 <= &g_11[0]) || (l_206 >= &g_33[0] && l_206 <= &g_33[4]) || l_206 == &g_21) ? (void) (0) : __assert_fail ("(l_206 >= &g_11[0] && l_206 <= &g_11[0]) || (l_206 >= &g_33[0] && l_206 <= &g_33[4]) || l_206 == &g_21", "t.c", 6843, __PRETTY_FUNCTION__));
        return g_210.f8;
    }

    ((g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])) ? (void) (0) : __assert_fail ("g_148 == 0 || (g_148 >= &g_11[0] && g_148 <= &g_11[0])", "t.c", 6847, __PRETTY_FUNCTION__));
    for (p_74 = 0; (p_74 <= (-15)); p_74--)
    {
        uint32_t l_307 = 4294967295U;
        int32_t **l_316 = (void*)0;
        uint16_t l_386 = 65535U;
        int32_t *l_396 = (void*)0;
        for (l_249 = (-7); (l_249 < 24); l_249 = safe_add_func_int16_t_s_s(l_249, 8))
        {
            uint32_t l_308 = 4294967286U;
            int32_t l_309 = 2;
            int32_t **l_310 = &l_201[3][1][0];
            for (l_79.f8 = (-2); (l_79.f8 >= 5); l_79.f8 = safe_add_func_uint16_t_u_u(l_79.f8, 4))
            {
                int32_t **l_302 = &g_32[1];
                l_309 = ((0 | ((p_74 ^ ((safe_rshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u(((((g_27.f2 != (**p_73)) , (g_296 != &g_297)) | ((safe_add_func_int8_t_s_s((((safe_mod_func_int16_t_s_s(((l_302 == (((safe_lshift_func_int16_t_s_u((0xFA & (safe_mul_func_int8_t_s_s((**l_302), g_27.f2))), 15)) == 0x3A923A02) , p_73)) == g_210.f3), l_307)) ^ p_74) && l_307), 0x72)) , (**p_73))) ^ (-9)), (**l_302))), 0)) > 6U)) , g_210.f1)) <= l_308);
            }
            (*l_310) = &l_309;


        }

{
                        struct S0 *l_1374 = &l_347;
                        uint8_t l_1375 = 0xEB;
                        int32_t **l_1384 = &g_944[6][1][4];
                        (*l_1384) = ((safe_sub_func_int8_t_s_s(g_27.f6, (safe_add_func_uint32_t_u_u(((safe_add_func_int8_t_s_s((-5), (safe_add_func_int8_t_s_s(0x81, (((l_1374 != (&g_27)) | l_1375) && (safe_lshift_func_int8_t_s_s(g_2647, (safe_add_func_uint8_t_u_u(((*(*g_297)) > ((!(safe_mul_func_uint8_t_u_u(g_27.f1, (-9)))) || 0xBB08)), 0x6F))))))))) ^ g_4), 4294967294U)))) , (void*)0);
                    }

                    for (l_79.f8 = 22; (l_79.f8 == (-5)); l_79.f8 = safe_sub_func_uint8_t_u_u(l_79.f8, 1))
        {
            int32_t l_328 = 0xFDE5E681;
            uint8_t l_329 = 0xC6;
            int32_t **l_344[8] = {(void*)0,&l_201[3][1][0],&l_201[3][1][0],(void*)0,&l_201[3][1][0],&l_201[3][1][0],(void*)0,&l_201[3][1][0]};
            struct S0 l_364 = {834,7947,123,1415,245,0,-126,306,0xE6};
            int32_t ***l_384 = &g_297;
            uint8_t l_394 = 0x3F;
            int i;

for (g_27.f8 = 22; (g_27.f8 == (-5)); g_27.f8 = safe_sub_func_uint8_t_u_u(g_27.f8, 1))
        {
            int32_t l_328 = 0xFDE5E681;
            uint8_t l_329 = 0xC6;
            int32_t **l_344[8] = {(void*)0,&l_201[3][1][0],&l_201[3][1][0],(void*)0,&l_201[3][1][0],&l_201[3][1][0],(void*)0,&l_201[3][1][0]};
            struct S0 l_364 = {834,7947,123,1415,245,0,-126,306,0xE6};
            int32_t ***l_384 = &g_297;
            uint8_t l_394 = 0x3F;
            int i;
            if (((safe_unary_minus_func_int32_t_s((((((safe_lshift_func_uint16_t_u_u((((void*)0 == (*g_2770)) || (safe_add_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((l_364.f7 , ((safe_mul_func_int16_t_s_s(0, g_2619)) == 4294967290U)), ((&g_297 == ((safe_rshift_func_int16_t_s_s(3, (((+(safe_div_func_uint16_t_u_u(0x77F4, g_2619))) , (*g_297)) == (void*)0))) , (void*)0)) > l_328))), l_328))), 6)) <= l_328) < 3) | 0x57) , l_328))) || l_329))
            {
                uint16_t l_332 = 0x647F;
                int32_t l_345 = 0x9BF6B608;
                struct S0 *l_348 = (void*)0;
                struct S0 *l_349 = &l_364;
                (**(&g_148)) = ((safe_mul_func_uint8_t_u_u(l_332, (((safe_unary_minus_func_uint32_t_u((((((safe_mod_func_int8_t_s_s((safe_div_func_int16_t_s_s((g_27.f1 == ((((((safe_mod_func_int32_t_s_s((**g_297), (**g_297))) >= (safe_rshift_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(((void*)0 == l_344[2]), g_27.f5)), 0))) & ((l_332 | (**g_297)) == l_332)) != l_332) >= 0x53) && l_345)), g_2619)), g_27.f2)) == g_2619) , g_2619) >= 0x2B71) | g_2803))) == 0x61F614FD) == g_2619))) >= 0U);
                if (l_345)
                    continue;
                (*l_349) = l_364;
            }
            else
            {
                int32_t *l_367 = &g_33[2];
                if (((safe_lshift_func_uint16_t_u_u(0xED67, 3)) , ((safe_rshift_func_int16_t_s_u((0 <= (safe_div_func_int16_t_s_s((0xDE2F1190 != (((*g_297) != (void*)0) ^ ((void*)0 != (*g_297)))), g_2619))), 10)) , ((g_2619 , 0x16663C9B) & 0xBDD39E80))))
                {
                    for (g_2803 = 0; (g_2803 < 0); g_2803 = safe_add_func_int16_t_s_s(g_2803, 8))
                    {
                        return l_358[1];
                    }
                }
                else
                {
                    int32_t l_362 = 0x19E7241B;
                    int32_t *l_385 = &g_33[1];
                    struct S0 *l_397 = &l_364;
                    for (l_364.f8 = 0; (l_364.f8 <= 4); l_364.f8 += 1)
                    {
                        int i;
                        (**(&g_148)) = (((~g_33[l_364.f8]) < (g_33[l_364.f8] >= (((g_33[l_364.f8] < l_362) , g_27.f1) & (+l_362)))) && (l_364 , (((((safe_add_func_uint8_t_u_u((**(&g_148)), (l_367 == (*g_297)))) ^ (**g_297)) && g_2803) <= (*l_367)) >= g_2619)));
                        (**g_297) = (((safe_rshift_func_uint8_t_u_s(g_2619, 5)) , (*g_297)) != (((safe_div_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u((safe_mul_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(((((((((safe_rshift_func_uint8_t_u_s((g_2619 , 0x0F), (safe_mod_func_int32_t_s_s(((((*g_297) != ((g_2619 != ((**g_297) <= ((l_384 != ((&g_33[l_364.f8] != l_385) , (void*)0)) || 0))) , (void*)0)) <= 0x66BC) | (*l_385)), g_33[l_364.f8])))) , (*(&g_148))) == (void*)0) & g_2619) & g_27.f3) , &g_297) == &g_297) , 0x6F4C6E71), 0x5A340AF4)), l_386)), (**g_297))) , g_2619), (*l_385))), g_33[l_364.f8])) > l_364.f8) , l_367));
                    }
                    for (l_329 = (-17); (l_329 < 30); ++l_329)
                    {
                        struct S0 l_389[5] = {{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43}};
                        struct S0 *l_390 = (void*)0;
                        struct S0 *l_391 = &l_389[4];
                        int32_t *l_395 = &(*(*l_316));
                        int i;
                        (*l_391) = l_389[4];
                        l_394 = (safe_rshift_func_int8_t_s_s(g_27.f5, 3));
                        (*l_316) = l_395;

                        (((*l_316) == &(*(*l_316))) ? (void) (0) : __assert_fail ("(*l_316) == &(*(*l_316))", "t.c", 6938, __PRETTY_FUNCTION__));
                    }
                    (*l_397) = g_27;
                }
            }
            (**(&g_148)) = ((safe_lshift_func_uint16_t_u_u((((-1) < (safe_add_func_uint16_t_u_u(((-1) && g_27.f0), (safe_sub_func_int8_t_s_s((((**g_297) || (~0xA3)) < ((((safe_lshift_func_int16_t_s_u(0x3CEC, (g_2619 != (safe_mod_func_uint32_t_u_u(((((g_27.f7 && ((g_27.f1 , 0x04CD) != 0xF897)) , (**(&g_148))) , g_2619) , g_2619), g_2619))))) || g_27.f1) & 4) , g_27.f4)), g_2619))))) >= g_27.f2), 9)) , (**(&g_148)));
        };


                    if (((safe_unary_minus_func_int32_t_s((((((safe_lshift_func_uint16_t_u_u((((void*)0 == l_316) || (safe_add_func_uint8_t_u_u((safe_sub_func_int32_t_s_s((g_210.f7 , ((safe_mul_func_int16_t_s_s(0, p_72)) == 4294967290U)), ((&p_73 == ((safe_rshift_func_int16_t_s_s(3, (((+(safe_div_func_uint16_t_u_u(0x77F4, p_74))) , (*p_73)) == (void*)0))) , (void*)0)) > l_328))), l_328))), 6)) <= l_328) < 3) | 0x57) , l_328))) || l_329))
            {
                uint16_t l_332 = 0x647F;
                int32_t l_345 = 0x9BF6B608;
                struct S0 *l_348 = (void*)0;
                struct S0 *l_349 = &l_347;
                (**l_89) = ((safe_mul_func_uint8_t_u_u(l_332, (((safe_unary_minus_func_uint32_t_u((((((safe_mod_func_int8_t_s_s((safe_div_func_int16_t_s_s((g_27.f1 == ((((((safe_mod_func_int32_t_s_s((**p_73), (**p_73))) >= (safe_rshift_func_uint8_t_u_u((safe_sub_func_uint32_t_u_u(((void*)0 == l_344[2]), g_27.f5)), 0))) & ((l_332 | (**p_73)) == l_332)) != l_332) >= 0x53) && l_345)), p_72)), g_27.f2)) == p_74) , p_72) >= 0x2B71) | l_346))) == 0x61F614FD) == p_72))) >= 0U);
                if (l_345)
                    {
for ((*l_396) = 0; ((*l_396) == 6); ++(*l_396))
                    {
                        (*(*g_2770)) = l_396;
                        if ((*l_396))
                            break;
                    };


                    continue;}
                (*l_349) = l_347;
            }
            else
            {
                int32_t *l_367 = &g_33[2];
                if (((safe_lshift_func_uint16_t_u_u(0xED67, 3)) , ((safe_rshift_func_int16_t_s_u((0 <= (safe_div_func_int16_t_s_s((0xDE2F1190 != (((*p_73) != (void*)0) ^ ((void*)0 != (*p_73)))), p_72))), 10)) , ((p_74 , 0x16663C9B) & 0xBDD39E80))))
                {
                    for (g_80 = 0; (g_80 < 0); g_80 = safe_add_func_int16_t_s_s(g_80, 8))
                    {
                        return l_358[1];
                    }
                }
                else
                {
                    int32_t l_362 = 0x19E7241B;
                    int32_t *l_385 = &g_33[1];
                    struct S0 *l_397 = &l_364;
                    for (l_347.f8 = 0; (l_347.f8 <= 4); l_347.f8 += 1)
                    {
                        int i;
                        (**l_89) = (((~g_33[l_347.f8]) < (g_33[l_347.f8] >= (((g_33[l_347.f8] < l_362) , g_27.f1) & (+l_362)))) && (l_364 , (((((safe_add_func_uint8_t_u_u((**l_89), (l_367 == (*p_73)))) ^ (**p_73)) && g_80) <= (*l_367)) >= p_72)));
                        (**p_73) = (((safe_rshift_func_uint8_t_u_s(p_74, 5)) , (*p_73)) != (((safe_div_func_int32_t_s_s((safe_rshift_func_uint16_t_u_s(((safe_sub_func_uint32_t_u_u((safe_mul_func_int8_t_s_s((safe_mod_func_uint32_t_u_u(((((((((safe_rshift_func_uint8_t_u_s((p_74 , 0x0F), (safe_mod_func_int32_t_s_s(((((*p_73) != ((p_74 != ((**p_73) <= ((l_384 != ((&g_33[l_347.f8] != l_385) , (void*)0)) || 0))) , (void*)0)) <= 0x66BC) | (*l_385)), g_33[l_347.f8])))) , (*l_89)) == (void*)0) & p_74) & g_27.f3) , &g_297) == &p_73) , 0x6F4C6E71), 0x5A340AF4)), l_386)), (**p_73))) , p_72), (*l_385))), g_33[l_347.f8])) > g_210.f8) , l_367));
                    }
                    for (l_329 = (-17); (l_329 < 30); ++l_329)
                    {
                        struct S0 l_389[5] = {{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43}};
                        struct S0 *l_390 = (void*)0;
                        struct S0 *l_391 = &l_389[4];
                        int32_t *l_395 = &g_21;
                        int i;
                        (*l_391) = l_389[4];

{
            for (l_79.f8 = 0; (l_79.f8 != 3); ++l_79.f8)
            {
                int32_t l_457[2][3][5] = {{{5,0xC87DFD15,5,0x1F69C2A5,0x1F69C2A5},{5,0xC87DFD15,5,0x1F69C2A5,0x1F69C2A5},{5,0xC87DFD15,5,0x1F69C2A5,0x1F69C2A5}},{{0x62CDD30D,0xD438CA16,0x62CDD30D,5,5},{0x62CDD30D,0xD438CA16,0x62CDD30D,5,5},{0x62CDD30D,0xD438CA16,0x62CDD30D,5,5}}};
                int i, j, k;
                if (l_457[0][0][2])
                {
                    if ((**(*g_2770)))
                        break;
                    return (**(*g_2770));
                }
                else
                {
                    for ((*l_385) = 2; ((*l_385) >= 0); (*l_385) -= 1)
                    {
                        (*(*g_2770)) = (*(*g_2770));
                        return (*l_367);
                    }
                }
            }
            (*(*g_2770)) = (*(*g_2770));
        }

                    l_394 = (safe_rshift_func_int8_t_s_s(g_27.f5, 3));
                        l_396 = l_395;

                        ((l_396 == &g_21) ? (void) (0) : __assert_fail ("l_396 == &g_21", "t.c", 7023, __PRETTY_FUNCTION__));
                    }
                    (*l_397) = g_27;
                }
            }

{
                        (*(*g_296)) = &g_11[0];
                        (*(*l_316)) = 0xF85D6DC6;
                        if ((*g_2221))
                            continue;
                    }

                    (**l_89) = ((safe_lshift_func_uint16_t_u_u((((-1) < (safe_add_func_uint16_t_u_u(((-1) && g_27.f0), (safe_sub_func_int8_t_s_s((((**p_73) || (~0xA3)) < ((((safe_lshift_func_int16_t_s_u(0x3CEC, (p_72 != (safe_mod_func_uint32_t_u_u(((((g_27.f7 && ((g_27.f1 , 0x04CD) != 0xF897)) , (**l_89)) , p_74) , p_72), p_72))))) || g_27.f1) & 4) , g_27.f4)), p_74))))) >= g_27.f2), 9)) , (**l_89));
        }

        ((l_396 == &g_21 || l_396 == 0) ? (void) (0) : __assert_fail ("l_396 == &g_21 || l_396 == 0", "t.c", 7039, __PRETTY_FUNCTION__));
    }


    if (((((((safe_add_func_int8_t_s_s((+g_27.f1), g_4)) , p_73) != (l_347 , (*g_296))) ^ ((((safe_mul_func_uint8_t_u_u((+(((((safe_lshift_func_uint8_t_u_u(0x06, ((((g_11[0] && g_210.f1) || (p_72 < g_27.f8)) >= g_210.f5) , g_33[3]))) , l_347) , g_27.f2) && (**p_73)) | p_74)), g_27.f3)) > p_72) & (**l_89)) & p_74)) & 0x2C85) && p_74))
    {
        return p_74;
    }
    else
    {
        int32_t **l_419 = &g_148;
        struct S0 *l_435 = &g_210;
        (*l_419) = (*l_89);

        (((g_148 >= &g_33[0] && g_148 <= &g_33[4])) ? (void) (0) : __assert_fail ("(g_148 >= &g_33[0] && g_148 <= &g_33[4])", "t.c", 7053, __PRETTY_FUNCTION__));
        (**l_89) = ((((((safe_lshift_func_uint16_t_u_s(p_72, 12)) ^ (~(safe_add_func_uint16_t_u_u((safe_mul_func_int8_t_s_s((**l_419), (0xA7B4 && (safe_div_func_int16_t_s_s((((((safe_rshift_func_int16_t_s_u((safe_rshift_func_int16_t_s_u((&l_79 != (void*)0), g_21)), (safe_sub_func_int32_t_s_s((p_72 ^ (l_435 == (void*)0)), (**p_73))))) > g_27.f6) < g_4) < g_11[0]) >= g_210.f5), 1U))))), g_210.f8)))) < 0) & (**p_73)) | p_74) , (**p_73));
        if (((g_27.f5 , (((((((((g_21 >= (((~(safe_mod_func_int16_t_s_s((safe_add_func_int32_t_s_s(((safe_sub_func_uint32_t_u_u(((safe_mul_func_int16_t_s_s(((((((safe_div_func_uint16_t_u_u((((((((((((+g_210.f7) > 5U) , p_73) == l_419) ^ (safe_unary_minus_func_uint16_t_u((p_72 == (p_72 > (((((safe_div_func_int8_t_s_s((((((~(safe_div_func_uint16_t_u_u(g_210.f7, p_74))) , &l_79) != &l_347) || (-1)) ^ g_27.f8), g_11[0])) > 0xE3) , p_73) != p_73) > 0xF597F79F)))))) || g_27.f5) >= p_74) >= 0x15) , 0xBB2F7794) , (**l_89)) & p_72), g_210.f8)) , 0xF7) <= (**l_89)) , 246U) , &g_210) == (void*)0), 6)) == 0), g_27.f0)) , 0), (**p_73))), 0xED22))) , (**l_419)) | (**l_419))) ^ g_27.f8) | 1) , p_74) && l_454) == p_74) > (**l_89)) , (**p_73)) != (-5))) < 5U))
        {

{
            transparent_crc(g_1271[(*g_2221)][i], "g_1271[(*g_2221)][i]", g_2956);
            if (g_2956) printf("index = [%d][%d]\n", (*g_2221), i);

        }

                    for (l_79.f8 = 0; (l_79.f8 != 3); ++l_79.f8)
            {
                int32_t l_457[2][3][5] = {{{5,0xC87DFD15,5,0x1F69C2A5,0x1F69C2A5},{5,0xC87DFD15,5,0x1F69C2A5,0x1F69C2A5},{5,0xC87DFD15,5,0x1F69C2A5,0x1F69C2A5}},{{0x62CDD30D,0xD438CA16,0x62CDD30D,5,5},{0x62CDD30D,0xD438CA16,0x62CDD30D,5,5},{0x62CDD30D,0xD438CA16,0x62CDD30D,5,5}}};
                int i, j, k;

if ((*(&k)))
                            break;

                    if (l_457[0][0][2])
                {
                    if ((**l_419))
                        break;
                    return (**l_419);
                }
                else
                {
                    for (l_215 = 2; (l_215 >= 0); l_215 -= 1)
                    {
                        (*l_419) = (*l_419);

if (g_784[g_1484])
                            break;

                    return g_80;
                    }
                }
            }

{
                    (**(&g_466)) = (*(*g_465));
                }

                    (*l_419) = (*l_89);
        }
        else
        {
            struct S0 ***l_460 = &l_458;

{
        uint16_t l_2940[8] = {0U,0U,0U,0U,0U,0U,0U,0U};
        int i;

for (g_2805 = 2; (g_2805 >= 51); g_2805 = safe_add_func_int32_t_s_s(g_2805, 1))
    {
        uint16_t l_2940[8] = {0U,0U,0U,0U,0U,0U,0U,0U};
        int i;
        for (j = 0; (j > (-15)); j = safe_sub_func_int32_t_s_s(j, 1))
        {
            uint16_t l_2954 = 0xBB7C;
            struct S0 **l_2955 = (void*)0;
            (*(&g_2803)) = 0x64EAFE29;
            for (g_2805 = 0; (g_2805 <= 3); g_2805 += 1)
            {
                struct S0 ***l_2957 = &g_2531[1][1];
                int16_t l_2958 = 0x8258;
                int i, j, k;
            }
        }
    };


                    for (l_346 = 0; (l_346 > (-15)); l_346 = safe_sub_func_int32_t_s_s(l_346, 1))
        {
            uint16_t l_2954 = 0xBB7C;
            struct S0 **l_2955 = (void*)0;

{
        int32_t ***l_2774 = &l_419;
        struct S0 l_2818 = {24,6738,-426,165,390,-0,1153,115,0xEA};
        struct S0 ***l_2865[3];
        int i;
        for (i = 0; i < 3; i++)
            l_2865[i] = &g_465;
        g_32[(*g_2221)] = g_32[(*g_2221)];
        (*(*p_73)) = ((safe_unary_minus_func_uint32_t_u((safe_unary_minus_func_int32_t_s(((+((((safe_mod_func_int8_t_s_s((safe_unary_minus_func_int8_t_s(((((((safe_sub_func_uint8_t_u_u((g_2351 , l_79.f5), ((0xE948A20E < (0x51576ED4 < (safe_rshift_func_uint8_t_u_u((((safe_div_func_int32_t_s_s(((g_2351 , (0 > ((safe_div_func_int8_t_s_s(((((safe_mul_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s((((((safe_lshift_func_uint8_t_u_u((((safe_lshift_func_uint8_t_u_s((&g_32[(*g_2221)] == &g_32[(*g_2221)]), 6)) != (0x3A76E62F < (*(&l_215)))) , 0x6C), g_2351)) , &p_73) != (&l_89)) | g_2351) <= g_2351), 1)), (*l_435).f3)), g_2351)) | 0x23CC) != g_33[3]) | 0x0B28), g_2351)) , l_79.f7))) && 0x38), g_2351)) && (*l_435).f6) | 1), (*(&l_215)))))) == g_2351))) , l_79.f1) , 0x7D5F7640) || (-1)) , (void*)0) != (&l_2955)))), 0xEA)) | (-7)) < 0x54EA) || (*(&l_215)))) , 3))))) | 65535U);
        for (g_2351 = (-12); (g_2351 == 60); g_2351 = safe_add_func_int32_t_s_s(g_2351, 6))
        {
            uint16_t l_2775 = 0xE2FA;
            int16_t l_2804 = 8;
            struct S0 **l_2817[2][8][4] = {{{&l_435,&l_435,&l_435,&l_435},{&l_435,&l_435,(void*)0,&l_435},{&l_435,&l_435,&l_435,(void*)0},{&l_435,(void*)0,(void*)0,(void*)0},{&l_435,&l_435,&l_435,&l_435},{(void*)0,&l_435,&l_435,(void*)0},{&l_435,&l_435,(void*)0,&l_435},{&l_435,&l_435,&l_435,(void*)0}},{{(void*)0,&l_435,&l_435,&l_435},{&l_435,&l_435,(void*)0,(void*)0},{&l_435,&l_435,&l_435,&l_435},{&l_435,&l_435,(void*)0,&l_435},{&l_435,&l_435,&l_435,(void*)0},{&l_435,&l_435,(void*)0,&l_435},{&l_435,&l_435,&l_435,&l_435},{&l_435,&l_435,(void*)0,(void*)0}}};
            int32_t l_2882 = (-4);
            int32_t *l_2884[4][4][8] = {{{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]},{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]},{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]},{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]}},{{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]},{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]},{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]},{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]}},{{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]},{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]},{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]},{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]}},{{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]},{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]},{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]},{&g_33[2],&(*g_2221),&g_33[1],&g_33[2],&g_33[2],&g_33[1],&(*g_2221),&g_33[2]}}};
            int i, j, k;
        }
        for (l_2818.f8 = 1; (l_2818.f8 <= 7); l_2818.f8 += 1)
        {
            uint16_t l_2912[10][5] = {{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U},{65535U,65531U,0x8995,65531U,65535U},{1U,0xB873,0x1C2D,0xB873,1U}};
            int32_t *l_2923 = (void*)0;
            int i, j;
        }
    }

                    (*(*p_73)) = 0x64EAFE29;
            for (g_2805 = 0; (g_2805 <= 3); g_2805 += 1)
            {
                struct S0 ***l_2957 = &g_2531[1][1];
                int16_t l_2958 = 0x8258;
                int i, j, k;
            }
        }
    }

                    (*l_460) = l_458;

{
                        struct S0 l_389[5] = {{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43},{858,1140,-368,138,152,-1,-372,64,0x43}};
                        struct S0 *l_390 = (void*)0;
                        struct S0 *l_391 = &l_389[4];
                        int32_t *l_395 = &l_346;
                        int i;
                        (*l_391) = l_389[4];
                        g_2805 = (safe_rshift_func_int8_t_s_s(g_210.f5, 3));
                        (*l_419) = l_395;

                        (((*l_419) == &l_346) ? (void) (0) : __assert_fail ("(*l_419) == &l_346", "t.c", 7178, __PRETTY_FUNCTION__));
                    }


{
                int32_t **l_302 = &g_32[1];
                i = ((0 | ((g_2619 ^ ((safe_rshift_func_int8_t_s_u((safe_sub_func_uint16_t_u_u(((((g_27.f2 != (**(*g_296))) , ((&l_89) != &(*g_2770))) | ((safe_add_func_int8_t_s_s((((safe_mod_func_int16_t_s_s(((l_302 == (((safe_lshift_func_int16_t_s_u((0xFA & (safe_mul_func_int8_t_s_s((**l_302), g_27.f2))), 15)) == 0x3A923A02) , (*g_296))) == (*l_435).f3), g_1094)) ^ g_2619) && g_1094), 0x72)) , (**(*g_296)))) ^ (-9)), (**l_302))), 0)) > 6U)) , (*l_435).f1)) <= l_249);
            }

                    for (l_249 = 0; (l_249 > 39); l_249 = safe_add_func_uint8_t_u_u(l_249, 5))
            {
                (*l_419) = (*p_73);
                if ((**p_73))
                    {
{
                        (**g_465) = (*g_466);
                    }

                    continue;}
            }
            l_477 = (safe_add_func_int32_t_s_s(((void*)0 == g_465), ((((&l_435 != (*l_460)) < ((**l_460) != (*g_465))) && ((&l_459[1][1] != &l_435) <= ((safe_div_func_int16_t_s_s((safe_lshift_func_int8_t_s_s((((((safe_mod_func_uint8_t_u_u((0 < 0x71B8), (**l_419))) != p_74) == g_27.f6) ^ (**p_73)) | (-2)), 4)), g_210.f7)) == g_27.f8))) && p_72)));
        }
    }

    (((g_148 >= &g_33[0] && g_148 <= &g_33[4])) ? (void) (0) : __assert_fail ("(g_148 >= &g_33[0] && g_148 <= &g_33[4])", "t.c", 7202, __PRETTY_FUNCTION__));

for (g_21 = 0; g_21 < 6; g_21++)
                                g_1271[i][g_21] = 1U;

                    return p_74;
}





int main (int argc, char* argv[])
{
    int i, j, k;
    int print_hash_value = 0;
    crc32_gentab();
    func_1();
    transparent_crc(g_4, "g_4", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_11[i], "g_11[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_21, "g_21", print_hash_value);
    transparent_crc(g_27.f0, "g_27.f0", print_hash_value);
    transparent_crc(g_27.f1, "g_27.f1", print_hash_value);
    transparent_crc(g_27.f2, "g_27.f2", print_hash_value);
    transparent_crc(g_27.f3, "g_27.f3", print_hash_value);
    transparent_crc(g_27.f4, "g_27.f4", print_hash_value);
    transparent_crc(g_27.f5, "g_27.f5", print_hash_value);
    transparent_crc(g_27.f6, "g_27.f6", print_hash_value);
    transparent_crc(g_27.f7, "g_27.f7", print_hash_value);
    transparent_crc(g_27.f8, "g_27.f8", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        transparent_crc(g_33[i], "g_33[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_80, "g_80", print_hash_value);
    transparent_crc(g_210.f0, "g_210.f0", print_hash_value);
    transparent_crc(g_210.f1, "g_210.f1", print_hash_value);
    transparent_crc(g_210.f2, "g_210.f2", print_hash_value);
    transparent_crc(g_210.f3, "g_210.f3", print_hash_value);
    transparent_crc(g_210.f4, "g_210.f4", print_hash_value);
    transparent_crc(g_210.f5, "g_210.f5", print_hash_value);
    transparent_crc(g_210.f6, "g_210.f6", print_hash_value);
    transparent_crc(g_210.f7, "g_210.f7", print_hash_value);
    transparent_crc(g_210.f8, "g_210.f8", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        transparent_crc(g_784[i], "g_784[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 5; i++)
    {
        transparent_crc(g_1031[i], "g_1031[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_1094, "g_1094", print_hash_value);
    transparent_crc(g_1240, "g_1240", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 6; j++)
        {
            transparent_crc(g_1271[i][j], "g_1271[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_1484, "g_1484", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                transparent_crc(g_2054[i][j][k], "g_2054[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);

            }
        }
    }
    transparent_crc(g_2318, "g_2318", print_hash_value);
    transparent_crc(g_2351, "g_2351", print_hash_value);
    transparent_crc(g_2619, "g_2619", print_hash_value);
    transparent_crc(g_2647, "g_2647", print_hash_value);
    transparent_crc(g_2803, "g_2803", print_hash_value);
    transparent_crc(g_2805, "g_2805", print_hash_value);
    transparent_crc(g_2956, "g_2956", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}

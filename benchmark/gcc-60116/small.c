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


    (si==(-9223372036854775807LL -1)) ?
    ((si)) :


    -si;
}

static int64_t
(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return


    (((si1>0) && (si2>0) && (si1 > ((9223372036854775807LL)-si2))) || ((si1<0) && (si2<0) && (si1 < ((-9223372036854775807LL -1)-si2)))) ?
    ((si1)) :


    (si1 + si2);
}

static int64_t
(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return


    (((si1^si2) & (((si1 ^ ((si1^si2) & (~(9223372036854775807LL))))-si2)^si2)) < 0) ?
    ((si1)) :


    (si1 - si2);
}

static int64_t
(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return


    (((si1 > 0) && (si2 > 0) && (si1 > ((9223372036854775807LL) / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < ((-9223372036854775807LL -1) / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < ((-9223372036854775807LL -1) / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((9223372036854775807LL) / si1)))) ?
    ((si1)) :


    si1 * si2;
}

static int64_t
(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return

    ((si2 == 0) || ((si1 == (-9223372036854775807LL -1)) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 % si2);
}

static int64_t
(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return

    ((si2 == 0) || ((si1 == (-9223372036854775807LL -1)) && (si2 == (-1)))) ?
    ((si1)) :

    (si1 / si2);
}

static int64_t
(safe_lshift_func_int64_t_s_s)(int64_t left, int right )
{
 
  return

    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > ((9223372036854775807LL) >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static int64_t
(safe_lshift_func_int64_t_s_u)(int64_t left, unsigned int right )
{
 
  return

    ((left < 0) || (((unsigned int)right) >= 32) || (left > ((9223372036854775807LL) >> ((unsigned int)right)))) ?
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

    ((((int)right) < 0) || (((int)right) >= 32) || (left > ((18446744073709551615ULL) >> ((int)right)))) ?
    ((left)) :

    (left << ((int)right));
}

static uint64_t
(safe_lshift_func_uint64_t_u_u)(uint64_t left, unsigned int right )
{
 
  return

    ((((unsigned int)right) >= 32) || (left > ((18446744073709551615ULL) >> ((unsigned int)right)))) ?
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



static volatile int32_t g_3 = (-9L);
static int32_t g_4[2][10] = {
  {0xC01D4C3FL,
   0L,
   0xC01D4C3FL,
   0xC01D4C3FL,
   0L,
   0xC01D4C3FL,
   0xC01D4C3FL,
   0L,
   0xC01D4C3FL,
   0xC01D4C3FL},
  {0L,
   0L,
   1L,
   0L, 0L,
   1L, 0L,
   0L, 1L, 0L}
};

static int8_t g_56 = 1L;
static uint32_t g_75 = 0xDC6F3D13L;
static int32_t g_97 = 0xD68C9157L;
static int32_t g_98 = 0xBD6B4620L;
static uint64_t g_99[4] = {
  0x819422B6A99605DBLL,
  0x819422B6A99605DBLL,
  0x819422B6A99605DBLL,
  0x819422B6A99605DBLL
};

static uint16_t g_178 = 1UL;
static int16_t g_189 = 0L;
static int32_t g_208[3] = {
  (-4L),
  (-4L),
  (-4L)
};

static int16_t g_209 = 0L;
static uint8_t g_236 = 0x61L;
static uint32_t g_280 = 18446744073709551615UL;
static uint8_t g_357 = 0xD8L;
static uint8_t g_359 = 1UL;
static int64_t g_455 = (-7L);
static int16_t g_540[1][1][10] = {
  {{0xA42FL, 0xA42FL, 0xA42FL, 0xA42FL, 0xA42FL, 0xA42FL, 0xA42FL, 0xA42FL,
    0xA42FL, 0xA42FL}}
};

static int32_t g_575 = 0xFE5494DAL;
static int16_t g_655 = 0L;
static int32_t g_675 = 0x77B6C026L;
static uint32_t g_703 = 0xFD21AA41L;
static uint64_t g_806 = 0UL;
static uint32_t g_897 = 0x4F78D624L;
static int32_t g_902 = 1L;
static int32_t g_921[8][10][1] = {
  {{9L}, {0x6DD76205L}, {0x26D23D1FL}, {1L}, {9L}, {1L}, {0x26D23D1FL},
   {0x6DD76205L}, {9L}, {0x6DD76205L}}, {{0x26D23D1FL}, {1L}, {9L}, {1L},
      {0x26D23D1FL}, {0x6DD76205L}, {9L},
      {0x6DD76205L}, {0x26D23D1FL}, {1L}},
{{9L}, {1L}, {0x26D23D1FL}, {0x6DD76205L}, {9L}, {0x6DD76205L}, {0x26D23D1FL}, {1L}, {9L}, {1L}}, {{0x26D23D1FL}, {0x6DD76205L}, {9L},
      {0x6DD76205L}, {0x26D23D1FL}, {1L}, {9L},
      {1L}, {0x26D23D1FL}, {0x6DD76205L}}, {{9L},
         {0x6DD76205L},
         {0x26D23D1FL},
         {1L},
         {9L},
         {1L},
         {0x26D23D1FL},
         {0x6DD76205L},
         {9L},
         {0x6DD76205L}},
{{0x26D23D1FL}, {1L}, {9L}, {1L}, {0x26D23D1FL}, {0x6DD76205L}, {9L}, {0x6DD76205L}, {0x26D23D1FL}, {1L}}, {{9L}, {1L}, {0x26D23D1FL},
        {0x6DD76205L}, {9L}, {0x6DD76205L},
        {0x26D23D1FL}, {1L}, {9L}, {1L}},
{{0x26D23D1FL}, {0x6DD76205L}, {9L}, {0x6DD76205L}, {0x26D23D1FL}, {1L}, {9L}, {1L}, {0x26D23D1FL}, {0x6DD76205L}}
};

static uint16_t g_922 = 65535UL;
static uint32_t g_983 = 0xDE5240FBL;
static uint8_t g_1060 = 0xC8L;
static uint32_t g_1081[1][10] = {
  {0x7202682FL,
   0x7202682FL,
   0x7202682FL,
   0x7202682FL,
   0x7202682FL,
   0x7202682FL,
   0x7202682FL,
   0x7202682FL,
   0x7202682FL,
   0x7202682FL}
};

static int16_t g_1182[3] = {
  0xE348L,
  0xE348L,
  0xE348L
};

static int32_t g_1272 = 0x41AEA787L;
static uint8_t g_1394 = 0x36L;
static int64_t g_1395 = 4L;
static uint32_t g_1513 = 1UL;
static int8_t g_1551 = 0xAFL;
static uint16_t g_1678 = 0x9F7CL;
static uint8_t g_1863 = 0UL;
static int32_t g_1923 = 0x2A8A2152L;
static uint64_t g_2227 = 0UL;
static uint32_t g_2241 = 0x610B7749L;
static int16_t g_2519 = (-6L);
static uint64_t g_2599 = 3UL;
static int8_t g_2791 = 0xADL;
static int8_t g_2945 = (-1L);
static int16_t g_2974 = 0x061DL;
static int8_t g_3175 = 0x31L;
static int32_t g_3331 = (-4L);
static uint32_t g_3487 = 0x2836864CL;
static int64_t g_3807 = (-7L);
static volatile int32_t g_3898 = (-1L);
static int16_t g_3950 = 0xD215L;
static volatile uint16_t g_4447 = 0UL;
static int8_t g_4576[3] = {
  0xA0L,
  0xA0L,
  0xA0L
};

static uint8_t g_4669 = 0x4FL;
static uint32_t g_4880 = 0xA38F5E48L;
static uint32_t g_5019 = 0xBFA07EA0L;



static int64_t func_1 (void);
static
  int8_t
  func_13
  (uint8_t p_14, int32_t p_15, uint32_t p_16, int32_t p_17, uint16_t p_18);
static int32_t func_20 (uint32_t p_21, uint8_t p_22, int16_t p_23);
static
  int16_t
  func_36
  (uint32_t p_37, int32_t p_38, int32_t p_39, int64_t p_40, uint8_t p_41);
static
  int32_t func_46 (int32_t p_47, uint64_t p_48, uint16_t p_49, uint32_t p_50);
static uint8_t func_66 (uint32_t p_67, uint8_t p_68);
static
  int32_t func_76 (uint16_t p_77, int8_t p_78, uint32_t p_79, uint32_t p_80);
static int32_t func_81 (uint16_t p_82, int16_t p_83, int32_t p_84);
static uint8_t func_91 (uint8_t p_92, uint16_t p_93, uint8_t p_94);
static int32_t func_100 (uint32_t p_101);
static int64_t
func_1 (void)
{
  uint32_t l_2[8][8][4] =
  {
    {
      {
      0x37F4A1D2L, 0x5AD058BBL, 0xA7C6DD3EL, 0xEA0627E8L},
      {
      0x4D0F4F23L, 0xD013D0BBL, 0xD013D0BBL, 0x4D0F4F23L},
      {
      0x1DED6804L, 0x45559507L, 0xBDA7FE64L, 1UL},
      {
      0x89276496L, 0x3F8DE905L, 0xC4B4E126L, 18446744073709551608UL},
      {
      0x2B2FAA96L, 0x81606DC0L, 18446744073709551615UL,
   18446744073709551608UL},
      {
      0x1B36C938L, 0x3F8DE905L, 0xAAAEB9AEL, 1UL},
      {
      0x9BEB0647L, 0x45559507L, 1UL, 0x4D0F4F23L},
      {
    0x14B58E17L, 0xD013D0BBL, 5UL, 0xEA0627E8L}},
    {
      {
      0UL, 0x5AD058BBL, 0xE62699FFL, 0xBDA7FE64L},
      {
      1UL, 0x14B58E17L, 0x7AF2C9A1L, 9UL},
      {
      0x799040C3L, 0xA898CBDBL, 0xAAAEB9AEL, 0x4A90611BL},
      {
      0UL, 0UL, 18446744073709551615UL, 0xAAAEB9AEL},
      {
      1UL, 0x4A90611BL, 0x30B91EE4L, 0x89276496L},
      {
      0x89276496L, 0x582F80C3L, 5UL, 0x6F263393L},
      {
      0x81606DC0L, 0x14B58E17L, 0UL, 0xE62699FFL},
      {
    0x9BEB0647L, 0x3F6085E0L, 0xA7C6DD3EL, 0x45559507L}},
    {
      {
      18446744073709551615UL, 0UL, 18446744073709551615UL, 0x4D0F4F23L},
      {
      0x4FF5452FL, 0x89276496L, 0x9F3FAA32L, 18446744073709551615UL},
      {
      0x89276496L, 0x3F6085E0L, 9UL, 0UL},
      {
      0x71A05132L, 0x81606DC0L, 0xD013D0BBL, 0x6F263393L},
      {
      0xAAAEB9AEL, 0x13BF58AAL, 0xAAAEB9AEL, 0UL},
      {
      0x37F4A1D2L, 0x4A90611BL, 1UL, 0x4D0F4F23L},
      {
      0x4D996497L, 1UL, 5UL, 0x4A90611BL},
      {
    0UL, 18446744073709551615UL, 5UL, 0x9F3FAA32L}},
    {
      {
      0x4D996497L, 0x14B58E17L, 1UL, 0xDDAE974CL},
      {
      0x37F4A1D2L, 18446744073709551615UL, 0xAAAEB9AEL, 0xEA0627E8L},
      {
      0x1355FFF8L, 0xAAAEB9AEL, 0xA7C6DD3EL, 0x1355FFF8L},
      {
      18446744073709551615UL, 18446744073709551611UL,
   18446744073709551615UL, 0x1B36C938L},
      {
      0UL, 0xBCA63185L, 18446744073709551610UL, 18446744073709551615UL},
      {
      1UL, 0UL, 0x383C67EEL, 0UL},
      {
      5UL, 5UL, 18446744073709551608UL, 0x1B36C938L},
      {
    0x9F3FAA32L, 0x7DFE4D9EL, 0x0B2811FFL, 5UL}},
    {
      {
      1UL, 0xAAAEB9AEL, 0xB839BF5BL, 0xA7C6DD3EL},
      {
      0UL, 0x1DED6804L, 0x3F8DE905L, 0xA898CBDBL},
      {
      0xD013D0BBL, 1UL, 0x7DFE4D9EL, 0xAB3E90A6L},
      {
      0x30B91EE4L, 0x4FF5452FL, 0x1355FFF8L, 0x383C67EEL},
      {
      0xE62699FFL, 0x1B36C938L, 0x37F4A1D2L, 5UL},
      {
      0xD013D0BBL, 0x383C67EEL, 0x5C8100C4L, 0UL},
      {
      0x0B2811FFL, 0x81606DC0L, 0xB839BF5BL, 0xB839BF5BL},
      {
    0UL, 0UL, 0x799040C3L, 0xFF15CC7CL}},
    {
      {
      0x9F3FAA32L, 18446744073709551614UL, 0x1355FFF8L,
   18446744073709551611UL},
      {
      0x418A5273L, 0UL, 0x383C67EEL, 0x1355FFF8L},
      {
      1UL, 0UL, 0x3F6085E0L, 18446744073709551611UL},
      {
      0UL, 18446744073709551614UL, 0x77904128L, 0xFF15CC7CL},
      {
      0x7AF2C9A1L, 0UL, 0xA7C6DD3EL, 0xB839BF5BL},
      {
      5UL, 0x81606DC0L, 18446744073709551608UL, 0UL},
      {
      0xBDA7FE64L, 0x383C67EEL, 0UL, 5UL},
      {
    1UL, 0x1B36C938L, 0UL, 0x383C67EEL}},
    {
      {
      0UL, 0x4FF5452FL, 0x5AD058BBL, 0xAB3E90A6L},
      {
      18446744073709551615UL, 1UL, 0UL, 0xA898CBDBL},
      {
      9UL, 0x1DED6804L, 0x1355FFF8L, 0xA7C6DD3EL},
      {
      5UL, 0xAAAEB9AEL, 0x4D0F4F23L, 5UL},
      {
      18446744073709551615UL, 0x7DFE4D9EL, 0x77904128L, 0x1B36C938L},
      {
      0x0B2811FFL, 5UL, 18446744073709551610UL, 0UL},
      {
      1UL, 0UL, 0x9BEB0647L, 18446744073709551615UL},
      {
    5UL, 0xBCA63185L, 0x1355FFF8L, 0x1B36C938L}},
    {
      {
      0xC4B4E126L, 18446744073709551611UL, 0x0B2811FFL, 0x1355FFF8L},
      {
      0UL, 0xAAAEB9AEL, 0x13BF58AAL, 0xAAAEB9AEL},
      {
      0UL, 0x58ED0BD2L, 0x5C8100C4L, 0xA898CBDBL},
      {
      18446744073709551614UL, 0UL, 0x7DFE4D9EL, 18446744073709551610UL},
      {
      0xE62699FFL, 0x4FF5452FL, 18446744073709551608UL, 0x71DBCABEL},
      {
      0xE62699FFL, 0UL, 0x7DFE4D9EL, 5UL},
      {
      18446744073709551614UL, 0x71DBCABEL, 0x5C8100C4L, 0x0B2811FFL},
      {
  0UL, 0x81606DC0L, 0x13BF58AAL, 0x582F80C3L}}};
  uint8_t l_19 = 4UL;
  int32_t l_4768[7][9][3] =
  {
    {
      {
      0x6F93F8E4L, 0L, 0L},
      {
      0xBCED9506L, (-1L), 1L},
      {
      0x407BAE69L, 0x8030389FL, 9L},
      {
      (-1L), 6L, 2L},
      {
      (-1L), (-9L), 0x19A92BE5L},
      {
      1L, 0xE3332CFCL, 1L},
      {
      (-1L), 0x6F93F8E4L, 0x08E852D4L},
      {
      0xDD32B7ABL, 0L, 0x9DE17132L},
      {
    0x381A88EDL, 0xCD5F16A9L, 0xB5B1B244L}},
    {
      {
      0xE3332CFCL, 0x86998E08L, 0xDB8DC516L},
      {
      0xB5B1B244L, 0x08E852D4L, 0xA407A085L},
      {
      0xAB96A36AL, 0xAB96A36AL, 0x4529A934L},
      {
      0L, (-9L), 0L},
      {
      0x432A9120L, (-1L), 0x063C23FDL},
      {
      (-1L), 0x1C1793E0L, (-6L)},
      {
      (-7L), 0x432A9120L, 0x063C23FDL},
      {
      1L, 0L, 0L},
      {
    (-5L), 8L, 0L}},
    {
      {
      0x19A92BE5L, 4L, 1L},
      {
      1L, (-5L), 0xF28FA565L},
      {
      0x407BAE69L, (-9L), (-10L)},
      {
      0L, 0x2E05679EL, 0x4529A934L},
      {
      0xCD5F16A9L, 0x08E852D4L, 0L},
      {
      0x55D20815L, 0x349578D6L, 8L},
      {
      (-6L), 0xAFF17ACDL, 0x407BAE69L},
      {
      1L, (-1L), 1L},
      {
    (-4L), 0x239DFD81L, (-1L)}},
    {
      {
      0xC6F15672L, (-1L), 0L},
      {
      (-9L), (-1L), 0xAFF17ACDL},
      {
      9L, 8L, 0L},
      {
      (-9L), 0L, 0L},
      {
      0xC6F15672L, 0xDB8DC516L, 8L},
      {
      (-4L), (-6L), (-9L)},
      {
      1L, 0xD4428E3AL, 0x432A9120L},
      {
      (-6L), 0L, 0xA407A085L},
      {
    0x55D20815L, (-7L), 0xDCE8B061L}},
    {
      {
      0xCD5F16A9L, 0xA407A085L, 0x19A92BE5L},
      {
      0L, (-7L), 6L},
      {
      0x407BAE69L, 0xDF137B5EL, (-1L)},
      {
      1L, 0xC6F15672L, 0xC6F15672L},
      {
      0x19A92BE5L, 1L, 0x1C1793E0L},
      {
      (-5L), 0xDCE8B061L, 0xF5F490A1L},
      {
      1L, 0x8030389FL, (-7L)},
      {
      (-7L), 1L, (-5L)},
      {
    (-1L), 0x8030389FL, 0x6F93F8E4L}},
    {
      {
      0x432A9120L, 0xDCE8B061L, 1L},
      {
      6L, 1L, 0x90AEB8D0L},
      {
      0x86998E08L, 0xC6F15672L, 0xC83337E4L},
      {
      (-10L), 0xDF137B5EL, 0x239DFD81L},
      {
      2L, (-7L), 0xD4428E3AL},
      {
      4L, 0xA407A085L, 3L},
      {
      (-1L), (-7L), 0x8892F792L},
      {
      0xDF137B5EL, 0L, 0xCD5F16A9L},
      {
    0x8892F792L, 0xD4428E3AL, 8L}},
    {
      {
      (-6L), (-6L), 0xF33BD556L},
      {
      1L, 0xDB8DC516L, (-1L)},
      {
      (-1L), 0L, (-6L)},
      {
      0xE3332CFCL, 8L, (-7L)},
      {
      (-6L), (-1L), (-6L)},
      {
      8L, (-1L), (-1L)},
      {
      0x60180667L, 0x239DFD81L, 0xF33BD556L},
      {
      0xDCE8B061L, (-1L), 8L},
      {
  0xB5B1B244L, 0xAFF17ACDL, 0xCD5F16A9L}}};
  int32_t l_4780 = (-1L);
  uint16_t l_4839 = 0x2432L;
  int32_t l_4845 = 8L;
  int32_t l_4872[3];
  int32_t l_4873[6][9] =
  {
    {
    0x8FF09EB2L, 5L, 0xE715FA55L, 5L, 0xCD7D07BDL, 3L, 3L, 0xCD7D07BDL, 5L},
    {
    0x8FF09EB2L,
 0x74158486L,
 0x8FF09EB2L, 3L, 0L, 0xE715FA55L, (-3L), (-3L), 0xE715FA55L},
    {
    0xE715FA55L, 5L, 0x8FF09EB2L, 5L, 0xE715FA55L, 5L, 0xCD7D07BDL, 3L, 3L},
    {
    5L, 0xAD18FF4BL, 0xE715FA55L, 3L, 0xE715FA55L, 0xAD18FF4BL, 5L, 0L,
 0xD53E6E15L},
    {
    (-3L), 0xD53E6E15L, 5L, 5L, 0xD53E6E15L, 0xAD18FF4BL, 0x74158486L,
 0xE715FA55L, 0x8FF09EB2L},
    {
  0xCD7D07BDL, 0xAD18FF4BL, 0x8FF09EB2L, 0xD53E6E15L, 3L, (-3L), 3L,
 0xD53E6E15L, 0x8FF09EB2L}};
  uint16_t l_4990 = 9UL;
  int16_t l_4998 = 1L;
  int16_t l_5017 = 7L;
  uint32_t l_5020 = 0x2B100354L;
  uint32_t l_5153 = 18446744073709551615UL;
  uint16_t l_5171 = 65526UL;
  int32_t l_5172 = 0L;
  int i, j, k;
  for (i = 0; i < 3; i++)
    l_4872[i] = 0x0860B758L;
  for (g_4[1][2] = 3; (g_4[1][2] >= 0); g_4[1][2] -= 1)
    {
      int16_t l_24 = (-1L);
      int32_t l_4769 = 1L;
      int32_t l_4783 = 0x3DFDB016L;
      int64_t l_4784 = 7L;
      int32_t l_4837[5][2][10] =
      {
 {
   {
   (-4L), 0xE9C0DC89L, 0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L,
       0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L}
   ,
   {
   (-4L), (-4L), 0xE9C0DC89L, 0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L,
       0xE9C0DC89L, (-4L), (-4L)}
 }
 ,
 {
   {
   (-4L), 0xE9C0DC89L, 0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L,
       0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L}
   ,
   {
   (-4L), (-4L), 0xE9C0DC89L, 0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L,
       0xE9C0DC89L, (-4L), (-4L)}
 }
 ,
 {
   {
   (-4L), 0xE9C0DC89L, 0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L,
       0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L}
   ,
   {
   (-4L), (-4L), 0xE9C0DC89L, 0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L,
       0xE9C0DC89L, (-4L), (-4L)}
 }
 ,
 {
   {
   (-4L), 0xE9C0DC89L, 0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L,
       0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L}
   ,
   {
   (-4L), (-4L), 0xE9C0DC89L, 0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L,
       0xE9C0DC89L, (-4L), (-4L)}
 }
 ,
 {
   {
   (-4L), 0xE9C0DC89L, 0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L,
       0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L}
   ,
   {
   (-4L), (-4L), 0xE9C0DC89L, 0xE9C0DC89L, (-4L), (-4L), 0xE9C0DC89L,
       0xE9C0DC89L, (-4L), (-4L)}
 }
      };
      int8_t l_4842[6] =
      {
      0x01L, 1L, 0x01L, 0x01L, 1L, 0x01L};
      uint16_t l_4959[10];
      uint32_t l_5102 = 0x3EEA3C23L;
      uint32_t l_5156 = 0x3103012CL;
      int i, j, k;
      for (i = 0; i < 10; i++)
 l_4959[i] = 1UL;
      l_4769
 =
 (safe_rshift_func_int16_t_s_s
  ((~
    (safe_mul_func_uint16_t_u_u
     ((safe_mul_func_int16_t_s_s
       ((g_540[0][0][0] =
  (g_4[1][5] <
   (safe_mul_func_uint8_t_u_u
    (2UL,
     (l_4768[2][2][0] =
      func_13 (l_19,
        func_20 ((l_24
           || l_2[6][3][2]), l_24, l_24),
        g_4[1][3], g_4[0][0], l_2[4][2][2])))))), l_19)),
      g_4[1][2]))), g_2945));
      l_4769 =
 ((l_4768[5][5][1] !=
   (((g_1551 !=
      (safe_lshift_func_uint8_t_u_u
       ((safe_add_func_uint8_t_u_u
  ((!l_24),
   ((safe_sub_func_uint16_t_u_u
     (g_2227,
      ((safe_rshift_func_int8_t_s_s
        ((safe_add_func_uint64_t_u_u ((l_4780 = l_24), g_455)),
         (g_4576[2] =
   0xF5L))) <
       ((g_455 &
         ((((safe_add_func_int32_t_s_s (g_98, l_4783)) <= g_280)
    || l_4768[2][2][0])
   || g_98)) ^ l_4784)))) < g_1513))),
        l_2[7][0][0]))) | 0xE38AL) | 252UL)) | l_4768[5][1][0]);
      for (g_806 = 0; (g_806 <= 3); g_806 += 1)
 {
   int8_t l_4838 = (-4L);
   int64_t l_4846 = 0x55EF57147219764BLL;
   uint32_t l_4851 = 0xC5599B89L;
   uint8_t l_4883 = 1UL;
   int32_t l_4906 = 0xDE4468F8L;
   int32_t l_4907 = 0x859DA2E8L;
   uint16_t l_5018 = 0xD1EAL;
   int32_t l_5022[10][3] =
   {
     {
     0x7EA7B377L, 0x14A9940BL, 0x6C8FA663L}
     ,
     {
     1L, 0x6C398603L, 1L}
     ,
     {
     0x6C8FA663L, 0x14A9940BL, 0x7EA7B377L}
     ,
     {
     (-1L), 0L, 0x7EA7B377L}
     ,
     {
     (-1L), (-1L), 1L}
     ,
     {
     1L, 1L, 0x6C8FA663L}
     ,
     {
     (-1L), 0x6C8FA663L, (-1L)}
     ,
     {
     (-1L), 0x6C8FA663L, (-1L)}
     ,
     {
     0x6C8FA663L, 1L, 1L}
     ,
     {
     1L, (-1L), (-1L)}
   };
   uint8_t l_5103 = 255UL;
   int i, j;
   for (g_189 = 0; (g_189 <= 3); g_189 += 1)
     {
       int64_t l_4803 = 0x96458143B7FABA93LL;
       int32_t l_4836 = (-8L);
       int16_t l_4909 = (-9L);
       uint16_t l_4960 = 5UL;
       if (g_1395)
  {
    uint16_t l_4787[1];
    int32_t l_4871 = 0x22DB2806L;
    int i;
    for (i = 0; i < 1; i++)
      l_4787[i] = 65529UL;
    g_921
      [1]
      [9]
      [0]
      =
      ((((!g_56) ==
         (((safe_lshift_func_uint8_t_u_u (g_1272, 5)) & g_2227)
   <
   ((1UL & l_4787[0]) |
    (safe_sub_func_int32_t_s_s
     (((g_208[2] <=
        (((safe_mul_func_int8_t_s_s
    ((safe_rshift_func_uint8_t_u_s
      (255UL,
       (((safe_lshift_func_int16_t_s_u
          (((safe_mod_func_int32_t_s_s
      ((safe_rshift_func_uint8_t_u_s
        ((safe_unary_minus_func_uint64_t_u
          (((safe_mul_func_int16_t_s_s
      (0L,
       (l_4769 =
        (g_1551
         && g_655)))) >= g_3175))),
         g_359)), l_4803)) != 4UL), 8))
         || g_922) <= 0xA2D7L))),
     1UL)) ^ l_4787[0]) == g_359)) != g_357),
      g_575))))) | 0x9B076F311E52A69CLL) || g_4669);
    for (g_897 = 0; (g_897 <= 3); g_897 += 1)
      {
        g_1923 = g_1060;
      }
    if ((safe_mul_func_uint16_t_u_u
         ((g_75 >=
    (((4L |
       (safe_add_func_uint8_t_u_u
        ((g_359 =
          (safe_mod_func_uint16_t_u_u
    (l_19,
     (((safe_mod_func_int16_t_s_s
        (((safe_rshift_func_uint8_t_u_u
           ((safe_add_func_uint32_t_u_u
      (((safe_rshift_func_int16_t_s_u
         ((safe_mul_func_uint16_t_u_u
           (g_3898,
            (safe_lshift_func_uint8_t_u_s
      (g_236,
       (l_4769 <=
        ((l_4837[4][1][5] =
          ((safe_add_func_uint64_t_u_u ((~(safe_mul_func_uint8_t_u_u ((safe_mul_func_uint8_t_u_u (((l_4836 = (safe_add_func_int64_t_s_s ((g_455 = (g_3807 = g_3950)), (safe_mul_func_int8_t_s_s ((safe_mod_func_int16_t_s_s (g_3487, l_24)), g_280))))) != g_540[0][0][5]), g_1394)), l_4803))), g_806)) && 0x57L)) == g_540[0][0][1])))))), g_1513)) | 0x5379D1F7L), 0x69F15ACDL)), l_4838)) && 0x4229L), 0xDA2DL)) != g_75) | 0x5C5773AEL)))), 0UL))) > g_4576[2]) != 0x563A4A5C11C1B531LL)), l_4803)))
      {
        int32_t l_4852 = 0x403283DFL;
        int32_t l_4884 = 9L;
        int32_t l_4885 = (-1L);
        int32_t l_4908 = 0xFE3073B2L;
        g_208
   [2]
   =
   (((1L !=
      (l_4839
       ||
       ((safe_mod_func_uint64_t_u_u
         ((l_4837[4][0][4] =
    l_4787[0]),
          l_4842[3])) >
        (((safe_mul_func_uint8_t_u_u
    ((l_4845 =
      l_4838), ((l_4836 =
          (((g_2599 =
      l_4846) >=
            0x34B82D244A8AF717LL) >=
           (safe_sub_func_int64_t_s_s
            ((safe_rshift_func_int16_t_s_u
       (l_4846, 9)), 4L))))
         && l_4787[0]))) !=
          g_4[1][2]) & g_703)))) ^ 1L) & 2L);
        g_3 = (g_1272 =
        (g_2241 >=
         (l_4768[2][2][0] !=
          ((l_4851 == l_4852) >=
    (safe_rshift_func_int16_t_s_s
     (((0x5C91L <
        ((safe_rshift_func_uint16_t_u_s
          ((safe_rshift_func_int8_t_s_s
     ((safe_rshift_func_uint16_t_u_u
       (((safe_mod_func_int8_t_s_s
          ((l_4836 ==
            (safe_mod_func_int8_t_s_s
      ((safe_rshift_func_int16_t_s_u
        (((safe_lshift_func_uint8_t_u_u (0x68L, (l_4871 = g_4447))) || l_4872[2]), l_4873[4][7])), (-2L)))), g_921[6][6][0])) > g_3487), g_2791)), g_675)), l_4851)) >= l_4837[4][1][5])) < 0x991BL), l_4787[0]))))));
        g_208[1] =
   ((g_3487 =
     ((((l_4884 =
         ((safe_mod_func_uint8_t_u_u
    ((((safe_mul_func_int8_t_s_s
        ((g_56 =
          (l_24 <= (l_4871 = 0UL))),
         ((g_97 ^
           ((((safe_mul_func_uint8_t_u_u
        ((l_4852 =
          g_4880), 0x91L)) <= 0x1A6AL)
      &&
      ((0x3E57L >
        (safe_sub_func_int64_t_s_s
         ((l_4769 <=
           ((l_4837[0][1][9] =
      l_4883) <= l_4842[4])),
          g_208[2]))) > g_2241))
     && g_4447)) & g_806))) <= g_4880) ==
      g_1678),
     g_1923)) ^ l_4872[0])) < g_4576[2]) <=
       l_4885) > (-5L))) >= g_2974);
        g_921[5][3][0] =
   ((((safe_mul_func_uint8_t_u_u
       (l_4837[4][1][4],
        (l_4909 =
         (+
          (((~
      ((((+
          ((((l_4908 =
       (((((g_99[3] =
            l_4837[4][1][5]) >
           (safe_mul_func_int16_t_s_s
            (((g_178 =
        l_4883) &
       (((l_4884 =
          ((((g_2227 =
       ((safe_sub_func_uint16_t_u_u (g_2945, (l_4907 = (safe_add_func_int32_t_s_s ((l_4769 = (-5L)), ((safe_add_func_uint8_t_u_u ((safe_mod_func_int16_t_s_s ((l_4884 & 2L), (safe_add_func_uint8_t_u_u ((l_4906 = ((safe_rshift_func_int16_t_s_s (((safe_rshift_func_int16_t_s_s (g_75, 2)) & ((g_3487 && 1L) & g_3807)), l_4871)) < g_3)), l_4842[2])))), g_208[2])) || l_4780)))))) > g_280)) > g_280) && g_1081[0][0]) == 0x0933C1602E5D7963LL)) != g_359) >= g_1395)), g_4669))) >= l_4787[0]) ^ l_4885) | g_56)) > 0x9CL) || g_540[0][0][4]) == l_4787[0])) & 2L) != 0x9F52L) | g_983)) | l_4871) | g_897))))) >= g_1394) | g_3175) == l_4885);
      }
    else
      {
        uint64_t l_4937 = 0x38F9D73A0A794B48LL;
        int32_t l_4938[1];
        int i;


        l_4959[i] = 1UL;


        g_3331
   =
   (safe_lshift_func_int8_t_s_u
    ((safe_add_func_uint16_t_u_u
      ((safe_mul_func_uint8_t_u_u
        (((safe_sub_func_int64_t_s_s
    (((((~
         (safe_lshift_func_int8_t_s_u
          ((l_4787[0] |
     (safe_add_func_int8_t_s_s
      (((-9L) <
        (l_4837[4][1][5] <
         (g_922 =
          (!g_3175)))),
       (safe_mod_func_int64_t_s_s
        ((((safe_mod_func_uint64_t_u_u
            (4UL,
      0xAB8CCC50124A0B7ELL)) |
           ((safe_mod_func_uint32_t_u_u
      ((safe_unary_minus_func_uint8_t_u (g_455)), ((safe_mod_func_uint64_t_u_u ((g_2599 = ((safe_sub_func_int16_t_s_s (((safe_mul_func_uint8_t_u_u (((((l_4937 = ((safe_sub_func_uint64_t_u_u (((g_1551 | g_575) != 1L), g_4447)) >= (-9L))) > l_4872[2]) >= 0x49L) | g_540[0][0][0]), g_675)) | g_1182[2]), g_208[1])) | g_3807)), g_208[0])) && g_655))) | 0x58A0L)) != l_4871), g_2519))))), l_19))) == l_4938[0]) < g_357) >= g_189), 0x36CCBABFFCE52C27LL)) < l_4837[4][1][5]), l_4787[0])), l_4838)), g_1394));
        l_4960 =
   ((g_983 =
     (g_1272 >=
      (safe_add_func_uint32_t_u_u
       ((safe_rshift_func_uint16_t_u_u
         (((safe_mod_func_int32_t_s_s
     (((safe_sub_func_uint8_t_u_u
        (((safe_lshift_func_uint16_t_u_u
           (((safe_mod_func_int8_t_s_s
       (l_4787[0],
        g_540[0][0][0])) <
      ((((g_2227 =
          0x2607FB2D10C9B352LL) &
         (((~
            (g_922 =
      (safe_sub_func_int16_t_s_s
       (((0xEE04A600D6338CD1LL >=
          ((-9L) <=
           (((l_4787[0]
       && (l_4871 =
           (l_4938[0] =
            (g_1395 =
             (safe_add_func_uint16_t_u_u
              ((g_1678 =
         (((-10L) >=
           (safe_rshift_func_uint8_t_u_u
            ((safe_lshift_func_int16_t_s_u ((l_4768[2][2][0] ^ 1L), 7)), g_236))) >= 5L)), l_4909)))))) != l_4839) >= g_3950))) > (-1L)), 0UL)))) == 0x1BD2L) | l_4959[8])) || g_1863) ^ g_1060)), 9)) || 251UL), l_4837[3][1][3])) ^ l_4873[3][7]), l_4909)) & 0xD3A392EBE6E8EF1ALL), 15)), l_4787[0])))) && g_703);
        g_208[2] =
   (((((safe_mod_func_uint8_t_u_u (0x43L, 254UL)) !=
       g_178) | (l_4906 =
          (safe_sub_func_uint8_t_u_u
           (l_4883,
     (l_4907 =
      g_540[0][0][5]))))) &
     (safe_mod_func_int64_t_s_s
      ((l_4938[0] ==
        (safe_mul_func_uint8_t_u_u
         (9UL,
          (l_4836 =
    (safe_mul_func_uint8_t_u_u
     ((g_1060 =
       (l_4937 >
        (safe_sub_func_int32_t_s_s
         ((safe_lshift_func_int8_t_s_u
           (l_4960, 4)), g_921[2][0][0])))),
      l_4838)))))),
       0x67BA2B2E2B7C8DD9LL))) ^ l_4787[0]);
      }
    if (l_4768[2][2][0])
      break;
  }
       else
  {
    uint32_t l_4989 = 9UL;
    g_921
      [1]
      [9]
      [0]
      =
      ((l_4906 <= g_3950) >=
       (safe_mod_func_int16_t_s_s
        (l_4838,
         (l_4769
   &&
   ((g_455 =
     ((0x3D222EB2D167D453LL
       ||
       ((safe_rshift_func_uint16_t_u_u
         (((safe_sub_func_uint8_t_u_u
     (((safe_lshift_func_int16_t_s_s
        (l_4909,
         (safe_mod_func_int32_t_s_s
          (g_2599,
           (((g_209
       ||
       (safe_mod_func_int64_t_s_s
        (((l_4837[2][1][6] >=
           l_4837[3][1][6])
          && g_2974), g_1060)))
      && l_4989) & l_4872[1])))))
       || g_189), 0x99L)) <= 0L),
          g_178)) != l_4768[0][6][1])) >
      l_4783)) ^ l_4990)))));


  }
       if (g_3331)
  break;
       l_4769
  =
  ((l_4768[5][5][1] !=
    (((g_1551 !=
       (safe_lshift_func_uint8_t_u_u
        ((safe_add_func_uint8_t_u_u
   ((!l_24),
    ((safe_sub_func_uint16_t_u_u
      (g_2227,
       ((safe_rshift_func_int8_t_s_s
         ((safe_add_func_uint64_t_u_u
    ((l_4780 = l_24), g_455)), (g_4576[2] =
           0xF5L))) <
        ((g_455 &
          ((((safe_add_func_int32_t_s_s (g_98, l_4783))
      <= g_280) || l_4768[2][2][0])
    || g_98)) ^ l_4784)))) < g_1513))),
         l_2[7][0][0]))) | 0xE38AL) | 252UL)) |
   l_4768[5][1][0]);



       g_3 = l_4783;


     }
   for (g_1863 = 0; (g_1863 <= 3); g_1863 += 1)
     {
       uint64_t l_5084 = 0xA9C667284D8615AFLL;
       int32_t l_5147 = 0x9BA5D540L;
       g_3331
  =
  (safe_mul_func_uint16_t_u_u
   ((l_5084 = 0x7C8FL), (l_4845 =
           ((safe_mod_func_uint8_t_u_u
      (((safe_mod_func_int64_t_s_s
         ((((safe_rshift_func_uint8_t_u_u
      ((((0xD5A6F832L
          &&
          ((safe_sub_func_int16_t_s_s (g_1182[2], (g_2227 >= (safe_mul_func_int8_t_s_s (l_4769, g_922))))) >= (l_4768[5][6][1] = ((l_4883 < (safe_unary_minus_func_int8_t_s (((safe_lshift_func_int8_t_s_s (((safe_sub_func_uint8_t_u_u (((safe_rshift_func_uint16_t_u_s (l_4990, (l_4873[5][8] = (((g_2519 && 3L) ^ 0x23F44EC9L) < l_5102)))) != g_575), l_5103)) & l_4784), l_19)) ^ g_2519)))) & g_97)))) >= (-1L)) > l_4883), g_99[3])) > l_4846) | l_4959[8]), l_4998)) | l_4851), g_1395)) != 0x0BCCL))));
       for (g_2945 = 0; (g_2945 <= 3); g_2945 += 1)
  {
    int8_t l_5124 = 1L;
    for (g_1923 = 3; (g_1923 >= 0); g_1923 -= 1)
      {
        int64_t l_5123 = 0xCCDB0BE861047541LL;
        l_4873
   [4]
   [7]
   =
   (safe_sub_func_uint32_t_u_u
    (((safe_lshift_func_int8_t_s_u
       (0x20L,
        (l_5017 !=
         (((~(g_99[2] = g_280)) >= g_3950) >
          (((safe_sub_func_int32_t_s_s
      ((g_921[5][7][0] =
        (safe_sub_func_int64_t_s_s
         (0xFE2B8FA57479FD98LL,
          (g_3807 <=
           ((safe_add_func_uint8_t_u_u
      ((safe_unary_minus_func_uint32_t_u
        (((safe_mul_func_uint16_t_u_u
           ((g_1678 =
      (safe_lshift_func_uint8_t_u_u
       ((safe_add_func_uint32_t_u_u
         ((((((((safe_rshift_func_int8_t_s_s ((g_4880 == g_3331), (l_4959[1] && 8UL))) | g_675) && g_4576[2]) != 0xA5B9L) < l_5022[9][1]) && 7UL) | g_1395), l_4959[8])), 6))), l_5123)) & l_4784))), g_4880)) | 0x1A6A892DD97E9186LL))))), l_5124)) >= l_5123) != l_5084))))) == l_4851), g_902));
        return g_983;
      }


    l_4769
      =
      (safe_rshift_func_int16_t_s_s
       ((~
         (safe_mul_func_uint16_t_u_u
   ((safe_mul_func_int16_t_s_s
     ((g_540[0][0][0] =
       (g_4[1][5] <
        (safe_mul_func_uint8_t_u_u
         (2UL,
          (l_4768[2][2][0] =
    func_13 (l_19,
      func_20 ((l_24
         || l_2[6][3][2]), l_24,
        l_24), g_4[1][3], g_4[0][0],
      l_2[4][2][2])))))), l_19)),
    g_4[1][2]))), g_2945));


    l_4907 = 0xFF4EE7B1L;
  }
       for (g_897 = 0; (g_897 <= 3); g_897 += 1)
  {
    int32_t l_5146 = (-1L);
    l_5147
      =
      (g_1272
       ^
       ((safe_rshift_func_uint8_t_u_u
         (((safe_sub_func_uint16_t_u_u
     (((((g_2241 >
          (((l_4990 <
      ((safe_mul_func_int8_t_s_s
        ((l_4768[2][2][0] =
          (safe_rshift_func_int16_t_s_u
           (l_4784,
     (g_2241 ==
      (safe_lshift_func_uint16_t_u_s
       ((!(18446744073709551615UL !=
           (((safe_add_func_int32_t_s_s
       ((safe_mul_func_uint16_t_u_u
         ((safe_sub_func_int8_t_s_s
           ((g_56
             && g_1551),
            (safe_sub_func_int8_t_s_s
             (((safe_mul_func_int8_t_s_s (((0L && g_208[1]) || g_3487), l_4883)) || g_540[0][0][6]), l_5146)))), g_357)), (-1L))) || g_2945) >= l_5146))), 1)))))), l_5084)) <= 4UL)) >= l_4837[4][1][5]) || g_3331)) != 0x3CL) >= g_3) | g_208[1]), 1L)) || l_5084), l_4959[8])) < 0L));
    g_1923 = 0L;
    for (l_24 = 3; (l_24 >= 0); l_24 -= 1)
      {
        int16_t l_5148 = 1L;


        for (g_2945 = 0; (g_2945 <= 3); g_2945 += 1)
   {
     int8_t l_5124 = 1L;
     for (g_1923 = 3; (g_1923 >= 0); g_1923 -= 1)
       {
         int64_t l_5123 = 0xCCDB0BE861047541LL;
         l_4873
    [4]
    [7]
    =
    (safe_sub_func_uint32_t_u_u
     (((safe_lshift_func_int8_t_s_u
        (0x20L,
         (l_5017 !=
          (((~(g_99[2] = g_280)) >= g_3950) >
           (((safe_sub_func_int32_t_s_s
       ((g_921[5][7][0] =
         (safe_sub_func_int64_t_s_s
          (0xFE2B8FA57479FD98LL,
           (g_3807 <=
            ((safe_add_func_uint8_t_u_u
       ((safe_unary_minus_func_uint32_t_u (((safe_mul_func_uint16_t_u_u ((g_1678 = (safe_lshift_func_uint8_t_u_u ((safe_add_func_uint32_t_u_u ((((((((safe_rshift_func_int8_t_s_s ((g_4880 == g_3331), (l_4959[1] && 8UL))) | g_675) && g_4576[2]) != 0xA5B9L) < l_5022[9][1]) && 7UL) | g_1395), l_4959[8])), 6))), l_5123)) & l_4784))), g_4880)) | 0x1A6A892DD97E9186LL))))), l_5124)) >= l_5123) != l_5084))))) == l_4851), g_902));
         return g_983;
       }
     for (l_5017 = 0; (l_5017 <= 3); l_5017 += 1)
       {
         uint32_t l_5125 = 0UL;
         return l_5125;
       }
     l_4907 = 0xFF4EE7B1L;
   }




      }
    for (g_897 = 0; (g_897 <= 3); g_897 += 1)
      {
        int32_t l_5146 = (-1L);
        l_5147
   =
   (g_1272
    ^
    ((safe_rshift_func_uint8_t_u_u
      (((safe_sub_func_uint16_t_u_u
         (((((g_2241 >
       (((l_4990 <
          ((safe_mul_func_int8_t_s_s
     ((l_4768[2][2][0] =
       (safe_rshift_func_int16_t_s_u
        (l_4784,
         (g_2241 ==
          (safe_lshift_func_uint16_t_u_s
           ((!(18446744073709551615UL !=
        (((safe_add_func_int32_t_s_s
           ((safe_mul_func_uint16_t_u_u ((safe_sub_func_int8_t_s_s ((g_56 && g_1551), (safe_sub_func_int8_t_s_s (((safe_mul_func_int8_t_s_s (((0L && g_208[1]) || g_3487), l_4883)) || g_540[0][0][6]), l_5146)))), g_357)), (-1L))) || g_2945) >= l_5146))), 1)))))), l_5084)) <= 4UL)) >= l_4837[4][1][5]) || g_3331)) != 0x3CL) >= g_3) | g_208[1]), 1L)) || l_5084), l_4959[8])) < 0L));
        g_1923 = 0L;
        for (l_24 = 3; (l_24 >= 0); l_24 -= 1)
   {
     int16_t l_5148 = 1L;
     l_4837[4][1][5] = (1L == l_5148);
     l_5146
       =
       (l_5146
        >=
        (safe_mul_func_uint8_t_u_u
         (g_1551,
          ((safe_add_func_uint8_t_u_u
     ((g_4669 = (0xCFL == g_1081[0][2])), (l_5153
               &&
               0xA7D3L)))
    || g_1182[1]))));
   }
        l_5146
   =
   (safe_mod_func_uint64_t_u_u
    ((((((l_5156 > (0L & 0x9421E21DB828B6DELL))
         ||
         (safe_add_func_int64_t_s_s
          ((g_3807 =
     (-8L)),
    (-10L)))) !=
        ((safe_sub_func_int32_t_s_s
          ((((safe_lshift_func_int16_t_s_s
       ((safe_mod_func_uint32_t_u_u
         ((g_983 =
           (g_4880 =
     ((((safe_sub_func_uint8_t_u_u
         ((g_1394 =
           (safe_unary_minus_func_int64_t_s
            (((g_178 =
        (0x8CBBB171B3042B5FLL ^
         (safe_mul_func_int16_t_s_s
          ((g_2974 =
            (g_540[0][0][0] =
             l_5103)),
           g_1394)))) <= g_1272)))),
          g_2945)) ^ g_99[3]) & g_1182[2])
      < g_4[1][9]))), g_1060)),
        10)) ^ 3UL) != l_4907),
    4294967289UL)) == 0x33A5L)) >=
       g_1081[0][6]) & 247UL), g_2945));
      }





    for (l_24 = 3; (l_24 >= 0); l_24 -= 1)
      {
        int16_t l_5148 = 1L;
        l_4837[4][1][5] = (1L == l_5148);
        l_5146
   =
   (l_5146
    >=
    (safe_mul_func_uint8_t_u_u
     (g_1551,
      ((safe_add_func_uint8_t_u_u
        ((g_4669 = (0xCFL == g_1081[0][2])), (l_5153
           &&
           0xA7D3L)))
       || g_1182[1]))));
      }


  }
       for (g_4669 = 0; (g_4669 <= 3); g_4669 += 1)
  {
    int64_t l_5170 = 0xE56F299D56E42AFCLL;
    for (g_5019 = 0; (g_5019 <= 3); g_5019 += 1)
      {
        return g_189;
      }
    {
      int8_t l_4838 = (-4L);
      int64_t l_4846 = 0x55EF57147219764BLL;
      uint32_t l_4851 = 0xC5599B89L;
      uint8_t l_4883 = 1UL;
      int32_t l_4906 = 0xDE4468F8L;
      int32_t l_4907 = 0x859DA2E8L;
      uint16_t l_5018 = 0xD1EAL;
      int32_t l_5022[10][3] =
      {
        {
        0x7EA7B377L, 0x14A9940BL, 0x6C8FA663L}
        ,
        {
        1L, 0x6C398603L, 1L}
        ,
        {
        0x6C8FA663L, 0x14A9940BL, 0x7EA7B377L}
        ,
        {
        (-1L), 0L, 0x7EA7B377L}
        ,
        {
        (-1L), (-1L), 1L}
        ,
        {
        1L, 1L, 0x6C8FA663L}
        ,
        {
        (-1L), 0x6C8FA663L, (-1L)}
        ,
        {
        (-1L), 0x6C8FA663L, (-1L)}
        ,
        {
        0x6C8FA663L, 1L, 1L}
        ,
        {
        1L, (-1L), (-1L)}
      };
      uint8_t l_5103 = 255UL;
      int i, j;
      for (g_189 = 0; (g_189 <= 3); g_189 += 1)
        {
   int64_t l_4803 = 0x96458143B7FABA93LL;
   int32_t l_4836 = (-8L);
   int16_t l_4909 = (-9L);
   uint16_t l_4960 = 5UL;
   if (g_1395)
     {
       uint16_t l_4787[1];
       int32_t l_4871 = 0x22DB2806L;
       int i;
       for (i = 0; i < 1; i++)
         l_4787[i] = 65529UL;
       g_921
         [1]
         [9]
         [0]
         =
         ((((!g_56) ==
     (((safe_lshift_func_uint8_t_u_u (g_1272, 5))
       & g_2227) <
      ((1UL & l_4787[0]) |
       (safe_sub_func_int32_t_s_s
        (((g_208[2] <=
           (((safe_mul_func_int8_t_s_s
       ((safe_rshift_func_uint8_t_u_s
         (255UL,
          (((safe_lshift_func_int16_t_s_u
      (((safe_mod_func_int32_t_s_s
         ((safe_rshift_func_uint8_t_u_s ((safe_unary_minus_func_uint64_t_u (((safe_mul_func_int16_t_s_s (0L, (l_4769 = (g_1551 && g_655)))) >= g_3175))), g_359)), l_4803)) != 4UL), 8)) || g_922) <= 0xA2D7L))), 1UL)) ^ l_4787[0]) == g_359)) != g_357), g_575))))) | 0x9B076F311E52A69CLL) || g_4669);
       for (g_897 = 0; (g_897 <= 3); g_897 += 1)
         {
    g_1923 = g_1060;
         }
       if ((safe_mul_func_uint16_t_u_u
     ((g_75 >=
       (((4L |
          (safe_add_func_uint8_t_u_u
           ((g_359 =
      (safe_mod_func_uint16_t_u_u
       (l_19,
        (((safe_mod_func_int16_t_s_s
           (((safe_rshift_func_uint8_t_u_u
       ((safe_add_func_uint32_t_u_u
         (((safe_rshift_func_int16_t_s_u ((safe_mul_func_uint16_t_u_u (g_3898, (safe_lshift_func_uint8_t_u_s (g_236, (l_4769 <= ((l_4837[4][1][5] = ((safe_add_func_uint64_t_u_u ((~(safe_mul_func_uint8_t_u_u ((safe_mul_func_uint8_t_u_u (((l_4836 = (safe_add_func_int64_t_s_s ((g_455 = (g_3807 = g_3950)), (safe_mul_func_int8_t_s_s ((safe_mod_func_int16_t_s_s (g_3487, l_24)), g_280))))) != g_540[0][0][5]), g_1394)), l_4803))), g_806)) && 0x57L)) == g_540[0][0][1])))))), g_1513)) | 0x5379D1F7L), 0x69F15ACDL)), l_4838)) && 0x4229L), 0xDA2DL)) != g_75) | 0x5C5773AEL)))), 0UL))) > g_4576[2]) != 0x563A4A5C11C1B531LL)), l_4803)))
         {
    int32_t l_4852 = 0x403283DFL;
    int32_t l_4884 = 9L;
    int32_t l_4885 = (-1L);
    int32_t l_4908 = 0xFE3073B2L;
    g_208
      [2]
      =
      (((1L !=
         (l_4839
          ||
          ((safe_mod_func_uint64_t_u_u
     ((l_4837[4][0][4] =
       l_4787[0]),
      l_4842[3])) >
           (((safe_mul_func_uint8_t_u_u
       ((l_4845 =
         l_4838), ((l_4836 =
             (((g_2599 =
         l_4846) >=
        0x34B82D244A8AF717LL)
       >=
       (safe_sub_func_int64_t_s_s
        ((safe_rshift_func_int16_t_s_u (l_4846, 9)), 4L)))) && l_4787[0]))) != g_4[1][2]) & g_703)))) ^ 1L) & 2L);
    g_3 = (g_1272 =
           (g_2241 >=
     (l_4768[2][2][0] !=
      ((l_4851 == l_4852) >=
       (safe_rshift_func_int16_t_s_s
        (((0x5C91L <
           ((safe_rshift_func_uint16_t_u_s
      ((safe_rshift_func_int8_t_s_s
        ((safe_rshift_func_uint16_t_u_u (((safe_mod_func_int8_t_s_s ((l_4836 == (safe_mod_func_int8_t_s_s ((safe_rshift_func_int16_t_s_u (((safe_lshift_func_uint8_t_u_u (0x68L, (l_4871 = g_4447))) || l_4872[2]), l_4873[4][7])), (-2L)))), g_921[6][6][0])) > g_3487), g_2791)), g_675)), l_4851)) >= l_4837[4][1][5])) < 0x991BL), l_4787[0]))))));
    g_208[1] =
      ((g_3487 =
        ((((l_4884 =
     ((safe_mod_func_uint8_t_u_u
       ((((safe_mul_func_int8_t_s_s
           ((g_56 =
      (l_24 <= (l_4871 = 0UL))),
            ((g_97 ^
       ((((safe_mul_func_uint8_t_u_u
           ((l_4852 =
             g_4880),
            0x91L)) <= 0x1A6AL)
         &&
         ((0x3E57L >
           (safe_sub_func_int64_t_s_s
            ((l_4769 <=
       ((l_4837[0][1][9] =
         l_4883) <=
        l_4842[4])),
             g_208[2]))) > g_2241))
        && g_4447)) & g_806))) <=
          g_4880) == g_1678),
        g_1923)) ^ l_4872[0])) <
           g_4576[2]) <= l_4885) > (-5L))) >=
       g_2974);
    g_921[5][3][0] =
      ((((safe_mul_func_uint8_t_u_u
          (l_4837[4][1][4],
           (l_4909 =
     (+
      (((~
         ((((+
      ((((l_4908 =
          (((((g_99[3] =
        l_4837[4][1][5]) >
       (safe_mul_func_int16_t_s_s
        (((g_178 =
           l_4883) &
          (((l_4884 =
             ((((g_2227 =
          ((safe_sub_func_uint16_t_u_u (g_2945, (l_4907 = (safe_add_func_int32_t_s_s ((l_4769 = (-5L)), ((safe_add_func_uint8_t_u_u ((safe_mod_func_int16_t_s_s ((l_4884 & 2L), (safe_add_func_uint8_t_u_u ((l_4906 = ((safe_rshift_func_int16_t_s_s (((safe_rshift_func_int16_t_s_s (g_75, 2)) & ((g_3487 && 1L) & g_3807)), l_4871)) < g_3)), l_4842[2])))), g_208[2])) || l_4780)))))) > g_280)) > g_280) && g_1081[0][0]) == 0x0933C1602E5D7963LL)) != g_359) >= g_1395)), g_4669))) >= l_4787[0]) ^ l_4885) | g_56)) > 0x9CL) || g_540[0][0][4]) == l_4787[0])) & 2L) != 0x9F52L) | g_983)) | l_4871) | g_897))))) >= g_1394) | g_3175) == l_4885);
         }
       else
         {
    uint64_t l_4937 = 0x38F9D73A0A794B48LL;
    int32_t l_4938[1];
    int i;
    for (i = 0; i < 1; i++)
      l_4938[i] = 0x711BE57AL;
    g_3331
      =
      (safe_lshift_func_int8_t_s_u
       ((safe_add_func_uint16_t_u_u
         ((safe_mul_func_uint8_t_u_u
           (((safe_sub_func_int64_t_s_s
       (((((~
            (safe_lshift_func_int8_t_s_u
      ((l_4787[0] |
        (safe_add_func_int8_t_s_s
         (((-9L) <
           (l_4837[4][1][5] <
            (g_922 =
             (!g_3175)))),
          (safe_mod_func_int64_t_s_s
           ((((safe_mod_func_uint64_t_u_u (4UL, 0xAB8CCC50124A0B7ELL)) | ((safe_mod_func_uint32_t_u_u ((safe_unary_minus_func_uint8_t_u (g_455)), ((safe_mod_func_uint64_t_u_u ((g_2599 = ((safe_sub_func_int16_t_s_s (((safe_mul_func_uint8_t_u_u (((((l_4937 = ((safe_sub_func_uint64_t_u_u (((g_1551 | g_575) != 1L), g_4447)) >= (-9L))) > l_4872[2]) >= 0x49L) | g_540[0][0][0]), g_675)) | g_1182[2]), g_208[1])) | g_3807)), g_208[0])) && g_655))) | 0x58A0L)) != l_4871), g_2519))))), l_19))) == l_4938[0]) < g_357) >= g_189), 0x36CCBABFFCE52C27LL)) < l_4837[4][1][5]), l_4787[0])), l_4838)), g_1394));
    l_4960 =
      ((g_983 =
        (g_1272 >=
         (safe_add_func_uint32_t_u_u
          ((safe_rshift_func_uint16_t_u_u
     (((safe_mod_func_int32_t_s_s
        (((safe_sub_func_uint8_t_u_u
           (((safe_lshift_func_uint16_t_u_u
       (((safe_mod_func_int8_t_s_s
          (l_4787[0],
           g_540[0][0][0])) <
         ((((g_2227 =
             0x2607FB2D10C9B352LL) &
            (((~
        (g_922 =
         (safe_sub_func_int16_t_s_s
          (((0xEE04A600D6338CD1LL >= ((-9L) <= (((l_4787[0] && (l_4871 = (l_4938[0] = (g_1395 = (safe_add_func_uint16_t_u_u ((g_1678 = (((-10L) >= (safe_rshift_func_uint8_t_u_u ((safe_lshift_func_int16_t_s_u ((l_4768[2][2][0] ^ 1L), 7)), g_236))) >= 5L)), l_4909)))))) != l_4839) >= g_3950))) > (-1L)), 0UL)))) == 0x1BD2L) | l_4959[8])) || g_1863) ^ g_1060)), 9)) || 251UL), l_4837[3][1][3])) ^ l_4873[3][7]), l_4909)) & 0xD3A392EBE6E8EF1ALL), 15)), l_4787[0])))) && g_703);
    g_208[2] =
      (((((safe_mod_func_uint8_t_u_u
           (0x43L, 254UL)) != g_178) | (l_4906 =
            (safe_sub_func_uint8_t_u_u
             (l_4883,
              (l_4907
               =
               g_540
               [0][0]
               [5])))))
        &
        (safe_mod_func_int64_t_s_s
         ((l_4938[0] ==
           (safe_mul_func_uint8_t_u_u
     (9UL,
      (l_4836 =
       (safe_mul_func_uint8_t_u_u
        ((g_1060 =
          (l_4937 >
           (safe_sub_func_int32_t_s_s
            ((safe_lshift_func_int8_t_s_u
       (l_4960, 4)),
      g_921[2][0][0])))),
         l_4838)))))),
          0x67BA2B2E2B7C8DD9LL))) ^ l_4787[0]);
         }
       if (l_4768[2][2][0])
         break;
     }
   else
     {
       uint32_t l_4989 = 9UL;
       g_921
         [1]
         [9]
         [0]
         =
         ((l_4906 <= g_3950) >=
          (safe_mod_func_int16_t_s_s
    (l_4838,
     (l_4769
      &&
      ((g_455 =
        ((0x3D222EB2D167D453LL
          ||
          ((safe_rshift_func_uint16_t_u_u
     (((safe_sub_func_uint8_t_u_u
        (((safe_lshift_func_int16_t_s_s
           (l_4909,
            (safe_mod_func_int32_t_s_s
      (g_2599,
       (((g_209
          ||
          (safe_mod_func_int64_t_s_s
           (((l_4837[2][1][6] >=
       l_4837[3][1][6])
             && g_2974), g_1060)))
         && l_4989) & l_4872[1])))))
          || g_189), 0x99L)) <= 0L),
      g_178)) != l_4768[0][6][1])) >
         l_4783)) ^ l_4990)))));
       for (g_209 = 0; (g_209 <= 3); g_209 += 1)
         {
    uint32_t l_4993[5][5][1] =
    {
      {
        {
        0x66253786L}
        ,
        {
        0UL}
        ,
        {
        1UL}
        ,
        {
        0UL}
        ,
        {
        0x66253786L}
      }
      ,
      {
        {
        0x66253786L}
        ,
        {
        0UL}
        ,
        {
        1UL}
        ,
        {
        0UL}
        ,
        {
        0x66253786L}
      }
      ,
      {
        {
        0x66253786L}
        ,
        {
        0UL}
        ,
        {
        1UL}
        ,
        {
        0UL}
        ,
        {
        0x66253786L}
      }
      ,
      {
        {
        0x66253786L}
        ,
        {
        0UL}
        ,
        {
        1UL}
        ,
        {
        0UL}
        ,
        {
        0x66253786L}
      }
      ,
      {
        {
        0x66253786L}
        ,
        {
        0UL}
        ,
        {
        1UL}
        ,
        {
        0UL}
        ,
        {
        0x66253786L}
      }
    };
    int32_t l_5021 = 0x2254F480L;
    int i, j, k;
    g_921
      [1]
      [2]
      [0]
      =
      ((l_4836 =
        ((l_4909 ==
          (g_2974 =
           ((l_4993[3][1][0] &
      (((safe_mod_func_int64_t_s_s
         (((l_5021 =
            (((g_1923 =
        (safe_mul_func_int8_t_s_s
         (l_4993[3][4][0],
          ((l_4998 =
            0x426DL) !=
           (safe_mul_func_int16_t_s_s
            (l_4993[3][1][0],
             (((0x7BL <=
         ((safe_mul_func_int16_t_s_s (((safe_sub_func_uint16_t_u_u (((safe_sub_func_uint64_t_u_u ((((((((safe_mul_func_uint8_t_u_u ((l_4837[4][1][5] = g_575), (((g_5019 = (safe_add_func_int8_t_s_s ((((safe_mul_func_uint16_t_u_u ((((((((safe_rshift_func_uint16_t_u_s ((g_359 && (safe_add_func_uint8_t_u_u (((l_5017 || 0x0C09L) <= l_4993[1][0][0]), l_4909))), l_4836)) ^ g_2791) || l_4989) || l_5018) || 0xE976317DL) == l_4959[8]) <= g_902), g_921[2][8][0])) >= 0x8D4DL) != g_2974), 0x51L))) < l_4993[3][1][0]) >= l_4993[3][1][0]))) & l_4989) || g_2519) != g_4880) && (-1L)) && g_98) < l_4989), (-1L))) ^ l_4989), l_4851)) < 0x33FA22850328C63BLL), (-1L))) & 0x40FBD257L)) < 0x4017L) > l_5020))))))) || 0UL) < g_1395)) ^ 0x4CL), g_2227)) != 0x81E9A8E7D5063958LL) < g_2241)) > l_4839))) | 9UL)) | l_5022[0][0]);
    return l_5021;
         }
     }
   if (g_3331)
     break;
   g_3 = l_4783;
   for (g_4880 = 0; (g_4880 <= 3); g_4880 += 1)
     {
       int32_t l_5037 = 0xA0F8C221L;
       int32_t l_5038 = (-1L);
       int32_t l_5043 = 1L;
       for (g_2599 = 0; (g_2599 <= 3); g_2599 += 1)
         {
    uint32_t l_5044 = 0x1BC7470AL;
    l_5044
      =
      ((~
        ((safe_rshift_func_int16_t_s_s
          ((((safe_mod_func_int64_t_s_s
       ((safe_rshift_func_uint8_t_u_s
         ((l_4839 <=
           (((g_1395 =
       (((g_1182[2] =
          (safe_mod_func_uint16_t_u_u
           ((safe_lshift_func_uint16_t_u_u ((g_4576[2] != ((((((g_1678 == ((safe_rshift_func_uint16_t_u_s ((5UL ^ (safe_add_func_uint32_t_u_u (l_5037, (((g_2791 < (l_5038 = 4294967295UL)) != ((((l_5043 = (((((safe_add_func_uint8_t_u_u ((g_897 >= (g_1923 = (safe_mod_func_uint64_t_u_u (((0x4433L < l_4783) | l_4851), l_4960)))), 250UL)) || l_4803) & 0x53L) || g_540[0][0][3]) && g_1395)) ^ 0x0F80L) == l_5037) <= 0xC661L)) < 0x0D03L)))), 3)) && 1L)) < g_99[3]) >= l_5037) == 0xCCL) ^ 0x220516D6DA4FF791LL) > 0xC8A338F7B0981ECELL)), g_922)), g_540[0][0][2]))) == 0xBB15L) >= 1L)) ^ (-1L)) < l_4768[2][2][0])), g_455)), l_5037)) >= 0x31E3L) && g_178), 5)) < 0x1A88L)) >= (-1L));
    l_4907 = g_4[0][9];
    g_1272
      =
      ((+
        (g_1863 =
         ((0x76L <=
           (+
     (l_4836 =
      ((l_5038 <=
        (g_575 =
         (safe_mod_func_int64_t_s_s
          ((-1L),
           18446744073709551607UL)))) &
       1L)))) == (+(g_178
             && (l_5044 ==
          l_4837[4][1]
          [5])))))) |
       (safe_sub_func_uint64_t_u_u
        ((0xD8L <= g_2599),
         0xDEC69502AF2911C7LL)));
         }
       for (g_75 = 0; (g_75 <= 3); g_75 += 1)
         {
    int32_t l_5080[10][2] =
    {
      {
      8L, 8L}
      ,
      {
      (-7L), 8L}
      ,
      {
      8L, (-7L)}
      ,
      {
      8L, 8L}
      ,
      {
      (-7L), 8L}
      ,
      {
      8L, (-7L)}
      ,
      {
      8L, 8L}
      ,
      {
      (-7L), 8L}
      ,
      {
      (-7L), 1L}
      ,
      {
      (-7L), (-7L)}
    };
    int32_t l_5081 = 0xD732A321L;
    int i, j;
    g_1272
      =
      (((safe_add_func_uint8_t_u_u
         ((safe_add_func_int16_t_s_s
           (l_4842[(g_4[1][2] + 2)],
     (l_4783 ^ (0L >= (l_4836 = l_24))))),
          ((0xAB2DF2926BDCC446LL
     && 3L) == ((g_3331 == g_675) !=
         (safe_mod_func_uint64_t_u_u
          (((safe_mul_func_uint16_t_u_u (l_4906, g_4669)) || l_5038), 0x58C3F60E4CE3BEAALL)))))) == 0UL) ^ (-1L));
    g_3331 =
      (safe_lshift_func_int8_t_s_u
       ((safe_mod_func_int64_t_s_s
         (((l_5043 =
     ((safe_mul_func_int8_t_s_s
       ((safe_lshift_func_int16_t_s_u
         ((l_5081 =
           ((0L !=
      (safe_lshift_func_uint8_t_u_u
       ((safe_rshift_func_uint16_t_u_s (0xEDBFL, ((safe_mul_func_uint8_t_u_u (((safe_add_func_int32_t_s_s (((l_4842[2] ^ 0x8DBD52B5L) & g_921[1][3][0]), g_3175)) | ((safe_rshift_func_int16_t_s_u ((-6L), 10)) >= (safe_add_func_uint64_t_u_u ((l_5080[3][0] = ((l_4837[3][1][7] = ((g_4669 == (((safe_unary_minus_func_uint16_t_u (((g_359 | l_5037) > g_189))) != 18446744073709551615UL) || g_983)) || g_3487)) >= g_1513)), g_1272)))), g_236)) <= 0x8DL))), l_4846))) && 0x5DL)), l_4873[2][2])), l_4960)) != l_4851)) | g_56), l_5038)), 5));
    if (g_1394)
      continue;
    g_208[1] = (-1L);
         }
     }
        }
      for (g_1863 = 0; (g_1863 <= 3); g_1863 += 1)
        {
   uint64_t l_5084 = 0xA9C667284D8615AFLL;
   int32_t l_5147 = 0x9BA5D540L;
   g_3331
     =
     (safe_mul_func_uint16_t_u_u
      ((l_5084 = 0x7C8FL), (l_4845 =
       ((safe_mod_func_uint8_t_u_u
         (((safe_mod_func_int64_t_s_s ((((safe_rshift_func_uint8_t_u_u ((((0xD5A6F832L && ((safe_sub_func_int16_t_s_s (g_1182[2], (g_2227 >= (safe_mul_func_int8_t_s_s (l_4769, g_922))))) >= (l_4768[5][6][1] = ((l_4883 < (safe_unary_minus_func_int8_t_s (((safe_lshift_func_int8_t_s_s (((safe_sub_func_uint8_t_u_u (((safe_rshift_func_uint16_t_u_s (l_4990, (l_4873[5][8] = (((g_2519 && 3L) ^ 0x23F44EC9L) < l_5102)))) != g_575), l_5103)) & l_4784), l_19)) ^ g_2519)))) & g_97)))) >= (-1L)) > l_4883), g_99[3])) > l_4846) | l_4959[8]), l_4998)) | l_4851), g_1395)) != 0x0BCCL))));
   for (g_2945 = 0; (g_2945 <= 3); g_2945 += 1)
     {
       int8_t l_5124 = 1L;
       for (g_1923 = 3; (g_1923 >= 0); g_1923 -= 1)
         {
    int64_t l_5123 = 0xCCDB0BE861047541LL;
    l_4873
      [4]
      [7]
      =
      (safe_sub_func_uint32_t_u_u
       (((safe_lshift_func_int8_t_s_u
          (0x20L,
           (l_5017 !=
     (((~(g_99[2] = g_280)) >= g_3950) >
      (((safe_sub_func_int32_t_s_s
         ((g_921[5][7][0] =
           (safe_sub_func_int64_t_s_s
            (0xFE2B8FA57479FD98LL,
      (g_3807 <=
       ((safe_add_func_uint8_t_u_u
         ((safe_unary_minus_func_uint32_t_u (((safe_mul_func_uint16_t_u_u ((g_1678 = (safe_lshift_func_uint8_t_u_u ((safe_add_func_uint32_t_u_u ((((((((safe_rshift_func_int8_t_s_s ((g_4880 == g_3331), (l_4959[1] && 8UL))) | g_675) && g_4576[2]) != 0xA5B9L) < l_5022[9][1]) && 7UL) | g_1395), l_4959[8])), 6))), l_5123)) & l_4784))), g_4880)) | 0x1A6A892DD97E9186LL))))), l_5124)) >= l_5123) != l_5084))))) == l_4851), g_902));
    return g_983;
         }
       for (l_5017 = 0; (l_5017 <= 3); l_5017 += 1)
         {
    uint32_t l_5125 = 0UL;
    return l_5125;
         }
       l_4907 = 0xFF4EE7B1L;
     }
   for (g_897 = 0; (g_897 <= 3); g_897 += 1)
     {
       int32_t l_5146 = (-1L);
       l_5147
         =
         (g_1272
          ^
          ((safe_rshift_func_uint8_t_u_u
     (((safe_sub_func_uint16_t_u_u
        (((((g_2241 >
      (((l_4990 <
         ((safe_mul_func_int8_t_s_s
           ((l_4768[2][2][0] =
      (safe_rshift_func_int16_t_s_u
       (l_4784,
        (g_2241 ==
         (safe_lshift_func_uint16_t_u_s
          ((!(18446744073709551615UL
       !=
       (((safe_add_func_int32_t_s_s ((safe_mul_func_uint16_t_u_u ((safe_sub_func_int8_t_s_s ((g_56 && g_1551), (safe_sub_func_int8_t_s_s (((safe_mul_func_int8_t_s_s (((0L && g_208[1]) || g_3487), l_4883)) || g_540[0][0][6]), l_5146)))), g_357)), (-1L))) || g_2945) >= l_5146))), 1)))))), l_5084)) <= 4UL)) >= l_4837[4][1][5]) || g_3331)) != 0x3CL) >= g_3) | g_208[1]), 1L)) || l_5084), l_4959[8])) < 0L));
       g_1923 = 0L;
       for (l_24 = 3; (l_24 >= 0); l_24 -= 1)
         {
    int16_t l_5148 = 1L;
    l_4837[4][1][5] = (1L == l_5148);
    l_5146
      =
      (l_5146
       >=
       (safe_mul_func_uint8_t_u_u
        (g_1551,
         ((safe_add_func_uint8_t_u_u
           ((g_4669 =
      (0xCFL == g_1081[0][2])), (l_5153
            &&
            0xA7D3L)))
          || g_1182[1]))));
         }
       l_5146
         =
         (safe_mod_func_uint64_t_u_u
          ((((((l_5156 > (0L & 0x9421E21DB828B6DELL))
        ||
        (safe_add_func_int64_t_s_s
         ((g_3807 =
           (-8L)),
          (-10L)))) !=
       ((safe_sub_func_int32_t_s_s
         ((((safe_lshift_func_int16_t_s_s
      ((safe_mod_func_uint32_t_u_u
        ((g_983 =
          (g_4880 =
           ((((safe_sub_func_uint8_t_u_u
        ((g_1394 =
          (safe_unary_minus_func_int64_t_s
           (((g_178 =
       (0x8CBBB171B3042B5FLL
        ^
        (safe_mul_func_int16_t_s_s
         ((g_2974 =
           (g_540[0][0][0] =
            l_5103)),
          g_1394)))) <=
             g_1272)))),
         g_2945)) ^ g_99[3]) &
      g_1182[2]) < g_4[1][9]))),
         g_1060)), 10)) ^ 3UL) != l_4907),
          4294967289UL)) == 0x33A5L)) >=
      g_1081[0][6]) & 247UL), g_2945));
     }
   for (g_4669 = 0; (g_4669 <= 3); g_4669 += 1)
     {
       int64_t l_5170 = 0xE56F299D56E42AFCLL;
       for (g_5019 = 0; (g_5019 <= 3); g_5019 += 1)
         {
    return g_189;
         }
       l_5170 = 2L;
     }
        }
      for (g_902 = 3; (g_902 >= 0); g_902 -= 1)
        {
   return g_4880;
        }
      for (g_4669 = 0; (g_4669 <= 3); g_4669 += 1)
        {
   g_921[5][7][0] = ((+l_5171) <= l_4851);
   l_5172 = l_4990;
        }
    }





  }
       {
  int8_t l_4838 = (-4L);
  int64_t l_4846 = 0x55EF57147219764BLL;
  uint32_t l_4851 = 0xC5599B89L;
  uint8_t l_4883 = 1UL;
  int32_t l_4906 = 0xDE4468F8L;
  int32_t l_4907 = 0x859DA2E8L;
  uint16_t l_5018 = 0xD1EAL;
  int32_t l_5022[10][3] =
  {
    {
    0x7EA7B377L, 0x14A9940BL, 0x6C8FA663L}
    ,
    {
    1L, 0x6C398603L, 1L}
    ,
    {
    0x6C8FA663L, 0x14A9940BL, 0x7EA7B377L}
    ,
    {
    (-1L), 0L, 0x7EA7B377L}
    ,
    {
    (-1L), (-1L), 1L}
    ,
    {
    1L, 1L, 0x6C8FA663L}
    ,
    {
    (-1L), 0x6C8FA663L, (-1L)}
    ,
    {
    (-1L), 0x6C8FA663L, (-1L)}
    ,
    {
    0x6C8FA663L, 1L, 1L}
    ,
    {
    1L, (-1L), (-1L)}
  };
  uint8_t l_5103 = 255UL;
  int i, j;
  for (g_189 = 0; (g_189 <= 3); g_189 += 1)
    {
      int64_t l_4803 = 0x96458143B7FABA93LL;
      int32_t l_4836 = (-8L);
      int16_t l_4909 = (-9L);
      uint16_t l_4960 = 5UL;
      if (g_1395)
        {
   uint16_t l_4787[1];
   int32_t l_4871 = 0x22DB2806L;
   int i;
   for (i = 0; i < 1; i++)
     l_4787[i] = 65529UL;
   g_921
     [1]
     [9]
     [0]
     =
     ((((!g_56) ==
        (((safe_lshift_func_uint8_t_u_u (g_1272, 5)) &
          g_2227) <
         ((1UL & l_4787[0]) |
          (safe_sub_func_int32_t_s_s
    (((g_208[2] <=
       (((safe_mul_func_int8_t_s_s
          ((safe_rshift_func_uint8_t_u_s
     (255UL,
      (((safe_lshift_func_int16_t_s_u
         (((safe_mod_func_int32_t_s_s
            ((safe_rshift_func_uint8_t_u_s
       ((safe_unary_minus_func_uint64_t_u (((safe_mul_func_int16_t_s_s (0L, (l_4769 = (g_1551 && g_655)))) >= g_3175))), g_359)), l_4803)) != 4UL), 8)) || g_922) <= 0xA2D7L))), 1UL)) ^ l_4787[0]) == g_359)) != g_357), g_575))))) | 0x9B076F311E52A69CLL) || g_4669);
   for (g_897 = 0; (g_897 <= 3); g_897 += 1)
     {
       g_1923 = g_1060;
     }
   if ((safe_mul_func_uint16_t_u_u
        ((g_75 >=
          (((4L |
      (safe_add_func_uint8_t_u_u
       ((g_359 =
         (safe_mod_func_uint16_t_u_u
          (l_19,
           (((safe_mod_func_int16_t_s_s
       (((safe_rshift_func_uint8_t_u_u
          ((safe_add_func_uint32_t_u_u
            (((safe_rshift_func_int16_t_s_u
        ((safe_mul_func_uint16_t_u_u
          (g_3898,
           (safe_lshift_func_uint8_t_u_s
            (g_236,
             (l_4769 <=
       ((l_4837[4][1][5] =
         ((safe_add_func_uint64_t_u_u ((~(safe_mul_func_uint8_t_u_u ((safe_mul_func_uint8_t_u_u (((l_4836 = (safe_add_func_int64_t_s_s ((g_455 = (g_3807 = g_3950)), (safe_mul_func_int8_t_s_s ((safe_mod_func_int16_t_s_s (g_3487, l_24)), g_280))))) != g_540[0][0][5]), g_1394)), l_4803))), g_806)) && 0x57L)) == g_540[0][0][1])))))), g_1513)) | 0x5379D1F7L), 0x69F15ACDL)), l_4838)) && 0x4229L), 0xDA2DL)) != g_75) | 0x5C5773AEL)))), 0UL))) > g_4576[2]) != 0x563A4A5C11C1B531LL)), l_4803)))
     {
       int32_t l_4852 = 0x403283DFL;
       int32_t l_4884 = 9L;
       int32_t l_4885 = (-1L);
       int32_t l_4908 = 0xFE3073B2L;
       g_208
         [2]
         =
         (((1L !=
     (l_4839
      ||
      ((safe_mod_func_uint64_t_u_u
        ((l_4837[4][0][4] =
          l_4787[0]),
         l_4842[3])) >
       (((safe_mul_func_uint8_t_u_u
          ((l_4845 =
     l_4838), ((l_4836 =
         (((g_2599 =
            l_4846) >=
           0x34B82D244A8AF717LL) >=
          (safe_sub_func_int64_t_s_s
           ((safe_rshift_func_int16_t_s_u (l_4846, 9)), 4L)))) && l_4787[0]))) != g_4[1][2]) & g_703)))) ^ 1L) & 2L);
       g_3 = (g_1272 =
       (g_2241 >=
        (l_4768[2][2][0] !=
         ((l_4851 == l_4852) >=
          (safe_rshift_func_int16_t_s_s
           (((0x5C91L <
       ((safe_rshift_func_uint16_t_u_s
         ((safe_rshift_func_int8_t_s_s
           ((safe_rshift_func_uint16_t_u_u
      (((safe_mod_func_int8_t_s_s
         ((l_4836 ==
           (safe_mod_func_int8_t_s_s
            ((safe_rshift_func_int16_t_s_u (((safe_lshift_func_uint8_t_u_u (0x68L, (l_4871 = g_4447))) || l_4872[2]), l_4873[4][7])), (-2L)))), g_921[6][6][0])) > g_3487), g_2791)), g_675)), l_4851)) >= l_4837[4][1][5])) < 0x991BL), l_4787[0]))))));
       g_208[1] =
         ((g_3487 =
    ((((l_4884 =
        ((safe_mod_func_uint8_t_u_u
          ((((safe_mul_func_int8_t_s_s
       ((g_56 =
         (l_24 <= (l_4871 = 0UL))),
        ((g_97 ^
          ((((safe_mul_func_uint8_t_u_u
       ((l_4852 =
         g_4880),
        0x91L)) <= 0x1A6AL)
            &&
            ((0x3E57L >
       (safe_sub_func_int64_t_s_s
        ((l_4769 <=
          ((l_4837[0][1][9] =
            l_4883) <= l_4842[4])),
         g_208[2]))) > g_2241))
           && g_4447)) & g_806))) <=
      g_4880) == g_1678),
           g_1923)) ^ l_4872[0])) < g_4576[2]) <=
      l_4885) > (-5L))) >= g_2974);
       g_921[5][3][0] =
         ((((safe_mul_func_uint8_t_u_u
      (l_4837[4][1][4],
       (l_4909 =
        (+
         (((~
     ((((+
         ((((l_4908 =
      (((((g_99[3] =
           l_4837[4][1][5]) >
          (safe_mul_func_int16_t_s_s
           (((g_178 =
       l_4883) &
             (((l_4884 =
         ((((g_2227 =
             ((safe_sub_func_uint16_t_u_u (g_2945, (l_4907 = (safe_add_func_int32_t_s_s ((l_4769 = (-5L)), ((safe_add_func_uint8_t_u_u ((safe_mod_func_int16_t_s_s ((l_4884 & 2L), (safe_add_func_uint8_t_u_u ((l_4906 = ((safe_rshift_func_int16_t_s_s (((safe_rshift_func_int16_t_s_s (g_75, 2)) & ((g_3487 && 1L) & g_3807)), l_4871)) < g_3)), l_4842[2])))), g_208[2])) || l_4780)))))) > g_280)) > g_280) && g_1081[0][0]) == 0x0933C1602E5D7963LL)) != g_359) >= g_1395)), g_4669))) >= l_4787[0]) ^ l_4885) | g_56)) > 0x9CL) || g_540[0][0][4]) == l_4787[0])) & 2L) != 0x9F52L) | g_983)) | l_4871) | g_897))))) >= g_1394) | g_3175) == l_4885);
     }
   else
     {
       uint64_t l_4937 = 0x38F9D73A0A794B48LL;
       int32_t l_4938[1];
       int i;
       for (i = 0; i < 1; i++)
         l_4938[i] = 0x711BE57AL;
       g_3331
         =
         (safe_lshift_func_int8_t_s_u
          ((safe_add_func_uint16_t_u_u
     ((safe_mul_func_uint8_t_u_u
       (((safe_sub_func_int64_t_s_s
          (((((~
        (safe_lshift_func_int8_t_s_u
         ((l_4787[0] |
           (safe_add_func_int8_t_s_s
            (((-9L) <
       (l_4837[4][1][5] <
        (g_922 =
         (!g_3175)))),
      (safe_mod_func_int64_t_s_s
       ((((safe_mod_func_uint64_t_u_u (4UL, 0xAB8CCC50124A0B7ELL)) | ((safe_mod_func_uint32_t_u_u ((safe_unary_minus_func_uint8_t_u (g_455)), ((safe_mod_func_uint64_t_u_u ((g_2599 = ((safe_sub_func_int16_t_s_s (((safe_mul_func_uint8_t_u_u (((((l_4937 = ((safe_sub_func_uint64_t_u_u (((g_1551 | g_575) != 1L), g_4447)) >= (-9L))) > l_4872[2]) >= 0x49L) | g_540[0][0][0]), g_675)) | g_1182[2]), g_208[1])) | g_3807)), g_208[0])) && g_655))) | 0x58A0L)) != l_4871), g_2519))))), l_19))) == l_4938[0]) < g_357) >= g_189), 0x36CCBABFFCE52C27LL)) < l_4837[4][1][5]), l_4787[0])), l_4838)), g_1394));
       l_4960 =
         ((g_983 =
    (g_1272 >=
     (safe_add_func_uint32_t_u_u
      ((safe_rshift_func_uint16_t_u_u
        (((safe_mod_func_int32_t_s_s
           (((safe_sub_func_uint8_t_u_u
       (((safe_lshift_func_uint16_t_u_u
          (((safe_mod_func_int8_t_s_s
      (l_4787[0],
       g_540[0][0][0])) <
            ((((g_2227 =
         0x2607FB2D10C9B352LL) &
        (((~
           (g_922 =
            (safe_sub_func_int16_t_s_s
             (((0xEE04A600D6338CD1LL
         >= ((-9L) <=
             (((l_4787[0]
         && (l_4871 =
             (l_4938
              [0] =
              (g_1395
               =
               (safe_add_func_uint16_t_u_u
         ((g_1678 = (((-10L) >= (safe_rshift_func_uint8_t_u_u ((safe_lshift_func_int16_t_s_u ((l_4768[2][2][0] ^ 1L), 7)), g_236))) >= 5L)), l_4909)))))) != l_4839) >= g_3950))) > (-1L)), 0UL)))) == 0x1BD2L) | l_4959[8])) || g_1863) ^ g_1060)), 9)) || 251UL), l_4837[3][1][3])) ^ l_4873[3][7]), l_4909)) & 0xD3A392EBE6E8EF1ALL), 15)), l_4787[0])))) && g_703);
       g_208[2] =
         (((((safe_mod_func_uint8_t_u_u (0x43L, 254UL))
      != g_178) | (l_4906 =
            (safe_sub_func_uint8_t_u_u
      (l_4883,
       (l_4907 =
        g_540[0][0][5]))))) &
    (safe_mod_func_int64_t_s_s
     ((l_4938[0] ==
       (safe_mul_func_uint8_t_u_u
        (9UL,
         (l_4836 =
          (safe_mul_func_uint8_t_u_u
           ((g_1060 =
      (l_4937 >
       (safe_sub_func_int32_t_s_s
        ((safe_lshift_func_int8_t_s_u
          (l_4960, 4)), g_921[2][0][0])))),
     l_4838)))))),
      0x67BA2B2E2B7C8DD9LL))) ^ l_4787[0]);
     }
   if (l_4768[2][2][0])
     break;
        }
      else
        {
   uint32_t l_4989 = 9UL;
   g_921
     [1]
     [9]
     [0]
     =
     ((l_4906 <= g_3950) >=
      (safe_mod_func_int16_t_s_s
       (l_4838,
        (l_4769
         &&
         ((g_455 =
    ((0x3D222EB2D167D453LL
      ||
      ((safe_rshift_func_uint16_t_u_u
        (((safe_sub_func_uint8_t_u_u
           (((safe_lshift_func_int16_t_s_s
       (l_4909,
        (safe_mod_func_int32_t_s_s
         (g_2599,
          (((g_209
      ||
      (safe_mod_func_int64_t_s_s
       (((l_4837[2][1][6] >=
          l_4837[3][1][6])
         && g_2974), g_1060)))
            && l_4989) & l_4872[1])))))
      || g_189), 0x99L)) <= 0L),
         g_178)) != l_4768[0][6][1])) >
     l_4783)) ^ l_4990)))));
   for (g_209 = 0; (g_209 <= 3); g_209 += 1)
     {
       uint32_t l_4993[5][5][1] =
       {
         {
    {
    0x66253786L}
    ,
    {
    0UL}
    ,
    {
    1UL}
    ,
    {
    0UL}
    ,
    {
    0x66253786L}
         }
         ,
         {
    {
    0x66253786L}
    ,
    {
    0UL}
    ,
    {
    1UL}
    ,
    {
    0UL}
    ,
    {
    0x66253786L}
         }
         ,
         {
    {
    0x66253786L}
    ,
    {
    0UL}
    ,
    {
    1UL}
    ,
    {
    0UL}
    ,
    {
    0x66253786L}
         }
         ,
         {
    {
    0x66253786L}
    ,
    {
    0UL}
    ,
    {
    1UL}
    ,
    {
    0UL}
    ,
    {
    0x66253786L}
         }
         ,
         {
    {
    0x66253786L}
    ,
    {
    0UL}
    ,
    {
    1UL}
    ,
    {
    0UL}
    ,
    {
    0x66253786L}
         }
       };
       int32_t l_5021 = 0x2254F480L;
       int i, j, k;
       g_921
         [1]
         [2]
         [0]
         =
         ((l_4836 =
    ((l_4909 ==
      (g_2974 =
       ((l_4993[3][1][0] &
         (((safe_mod_func_int64_t_s_s
     (((l_5021 =
        (((g_1923 =
           (safe_mul_func_int8_t_s_s
            (l_4993[3][4][0],
      ((l_4998 =
        0x426DL) !=
       (safe_mul_func_int16_t_s_s
        (l_4993[3][1][0],
         (((0x7BL <=
            ((safe_mul_func_int16_t_s_s (((safe_sub_func_uint16_t_u_u (((safe_sub_func_uint64_t_u_u ((((((((safe_mul_func_uint8_t_u_u ((l_4837[4][1][5] = g_575), (((g_5019 = (safe_add_func_int8_t_s_s ((((safe_mul_func_uint16_t_u_u ((((((((safe_rshift_func_uint16_t_u_s ((g_359 && (safe_add_func_uint8_t_u_u (((l_5017 || 0x0C09L) <= l_4993[1][0][0]), l_4909))), l_4836)) ^ g_2791) || l_4989) || l_5018) || 0xE976317DL) == l_4959[8]) <= g_902), g_921[2][8][0])) >= 0x8D4DL) != g_2974), 0x51L))) < l_4993[3][1][0]) >= l_4993[3][1][0]))) & l_4989) || g_2519) != g_4880) && (-1L)) && g_98) < l_4989), (-1L))) ^ l_4989), l_4851)) < 0x33FA22850328C63BLL), (-1L))) & 0x40FBD257L)) < 0x4017L) > l_5020))))))) || 0UL) < g_1395)) ^ 0x4CL), g_2227)) != 0x81E9A8E7D5063958LL) < g_2241)) > l_4839))) | 9UL)) | l_5022[0][0]);
       return l_5021;
     }
        }
      if (g_3331)
        break;
      g_3 = l_4783;
      for (g_4880 = 0; (g_4880 <= 3); g_4880 += 1)
        {
   int32_t l_5037 = 0xA0F8C221L;
   int32_t l_5038 = (-1L);
   int32_t l_5043 = 1L;
   for (g_2599 = 0; (g_2599 <= 3); g_2599 += 1)
     {
       uint32_t l_5044 = 0x1BC7470AL;
       l_5044
         =
         ((~
    ((safe_rshift_func_int16_t_s_s
      ((((safe_mod_func_int64_t_s_s
          ((safe_rshift_func_uint8_t_u_s
     ((l_4839 <=
       (((g_1395 =
          (((g_1182[2] =
      (safe_mod_func_uint16_t_u_u
       ((safe_lshift_func_uint16_t_u_u ((g_4576[2] != ((((((g_1678 == ((safe_rshift_func_uint16_t_u_s ((5UL ^ (safe_add_func_uint32_t_u_u (l_5037, (((g_2791 < (l_5038 = 4294967295UL)) != ((((l_5043 = (((((safe_add_func_uint8_t_u_u ((g_897 >= (g_1923 = (safe_mod_func_uint64_t_u_u (((0x4433L < l_4783) | l_4851), l_4960)))), 250UL)) || l_4803) & 0x53L) || g_540[0][0][3]) && g_1395)) ^ 0x0F80L) == l_5037) <= 0xC661L)) < 0x0D03L)))), 3)) && 1L)) < g_99[3]) >= l_5037) == 0xCCL) ^ 0x220516D6DA4FF791LL) > 0xC8A338F7B0981ECELL)), g_922)), g_540[0][0][2]))) == 0xBB15L) >= 1L)) ^ (-1L)) < l_4768[2][2][0])), g_455)), l_5037)) >= 0x31E3L) && g_178), 5)) < 0x1A88L)) >= (-1L));
       l_4907 = g_4[0][9];
       g_1272
         =
         ((+
    (g_1863 =
     ((0x76L <=
       (+
        (l_4836 =
         ((l_5038 <=
           (g_575 =
     (safe_mod_func_int64_t_s_s
      ((-1L),
       18446744073709551607UL)))) & 1L))))
      ==
      (+(g_178 && (l_5044 == l_4837[4][1][5]))))))
          |
          (safe_sub_func_uint64_t_u_u
    ((0xD8L <= g_2599), 0xDEC69502AF2911C7LL)));
     }
   for (g_75 = 0; (g_75 <= 3); g_75 += 1)
     {
       int32_t l_5080[10][2] =
       {
         {
         8L, 8L}
         ,
         {
         (-7L), 8L}
         ,
         {
         8L, (-7L)}
         ,
         {
         8L, 8L}
         ,
         {
         (-7L), 8L}
         ,
         {
         8L, (-7L)}
         ,
         {
         8L, 8L}
         ,
         {
         (-7L), 8L}
         ,
         {
         (-7L), 1L}
         ,
         {
         (-7L), (-7L)}
       };
       int32_t l_5081 = 0xD732A321L;
       int i, j;
       g_1272
         =
         (((safe_add_func_uint8_t_u_u
     ((safe_add_func_int16_t_s_s
       (l_4842[(g_4[1][2] + 2)],
        (l_4783 ^ (0L >= (l_4836 = l_24))))),
      ((0xAB2DF2926BDCC446LL
        && 3L) == ((g_3331 == g_675) !=
            (safe_mod_func_uint64_t_u_u
      (((safe_mul_func_uint16_t_u_u
         (l_4906, g_4669))
        || l_5038),
       0x58C3F60E4CE3BEAALL)))))) ==
    0UL) ^ (-1L));
       g_3331 =
         (safe_lshift_func_int8_t_s_u
          ((safe_mod_func_int64_t_s_s
     (((l_5043 =
        ((safe_mul_func_int8_t_s_s
          ((safe_lshift_func_int16_t_s_u
     ((l_5081 =
       ((0L !=
         (safe_lshift_func_uint8_t_u_u
          ((safe_rshift_func_uint16_t_u_s
            (0xEDBFL,
      ((safe_mul_func_uint8_t_u_u
        (((safe_add_func_int32_t_s_s
           (((l_4842[2] ^
       0x8DBD52B5L) &
             g_921[1][3][0]),
            g_3175)) |
          ((safe_rshift_func_int16_t_s_u ((-6L), 10)) >= (safe_add_func_uint64_t_u_u ((l_5080[3][0] = ((l_4837[3][1][7] = ((g_4669 == (((safe_unary_minus_func_uint16_t_u (((g_359 | l_5037) > g_189))) != 18446744073709551615UL) || g_983)) || g_3487)) >= g_1513)), g_1272)))), g_236)) <= 0x8DL))), l_4846))) && 0x5DL)), l_4873[2][2])), l_4960)) != l_4851)) | g_56), l_5038)), 5));
       if (g_1394)
         continue;
       g_208[1] = (-1L);
     }
        }
    }
  for (g_1863 = 0; (g_1863 <= 3); g_1863 += 1)
    {
      uint64_t l_5084 = 0xA9C667284D8615AFLL;
      int32_t l_5147 = 0x9BA5D540L;
      g_3331
        =
        (safe_mul_func_uint16_t_u_u
         ((l_5084 = 0x7C8FL), (l_4845 =
          ((safe_mod_func_uint8_t_u_u
            (((safe_mod_func_int64_t_s_s
        ((((safe_rshift_func_uint8_t_u_u ((((0xD5A6F832L && ((safe_sub_func_int16_t_s_s (g_1182[2], (g_2227 >= (safe_mul_func_int8_t_s_s (l_4769, g_922))))) >= (l_4768[5][6][1] = ((l_4883 < (safe_unary_minus_func_int8_t_s (((safe_lshift_func_int8_t_s_s (((safe_sub_func_uint8_t_u_u (((safe_rshift_func_uint16_t_u_s (l_4990, (l_4873[5][8] = (((g_2519 && 3L) ^ 0x23F44EC9L) < l_5102)))) != g_575), l_5103)) & l_4784), l_19)) ^ g_2519)))) & g_97)))) >= (-1L)) > l_4883), g_99[3])) > l_4846) | l_4959[8]), l_4998)) | l_4851), g_1395)) != 0x0BCCL))));
      for (g_2945 = 0; (g_2945 <= 3); g_2945 += 1)
        {
   int8_t l_5124 = 1L;
   for (g_1923 = 3; (g_1923 >= 0); g_1923 -= 1)
     {
       int64_t l_5123 = 0xCCDB0BE861047541LL;
       l_4873
         [4]
         [7]
         =
         (safe_sub_func_uint32_t_u_u
          (((safe_lshift_func_int8_t_s_u
      (0x20L,
       (l_5017 !=
        (((~(g_99[2] = g_280)) >= g_3950) >
         (((safe_sub_func_int32_t_s_s
     ((g_921[5][7][0] =
       (safe_sub_func_int64_t_s_s
        (0xFE2B8FA57479FD98LL,
         (g_3807 <=
          ((safe_add_func_uint8_t_u_u
            ((safe_unary_minus_func_uint32_t_u (((safe_mul_func_uint16_t_u_u ((g_1678 = (safe_lshift_func_uint8_t_u_u ((safe_add_func_uint32_t_u_u ((((((((safe_rshift_func_int8_t_s_s ((g_4880 == g_3331), (l_4959[1] && 8UL))) | g_675) && g_4576[2]) != 0xA5B9L) < l_5022[9][1]) && 7UL) | g_1395), l_4959[8])), 6))), l_5123)) & l_4784))), g_4880)) | 0x1A6A892DD97E9186LL))))), l_5124)) >= l_5123) != l_5084))))) == l_4851), g_902));
       return g_983;
     }
   for (l_5017 = 0; (l_5017 <= 3); l_5017 += 1)
     {
       uint32_t l_5125 = 0UL;
       return l_5125;
     }
   l_4907 = 0xFF4EE7B1L;
        }
      for (g_897 = 0; (g_897 <= 3); g_897 += 1)
        {
   int32_t l_5146 = (-1L);
   l_5147
     =
     (g_1272
      ^
      ((safe_rshift_func_uint8_t_u_u
        (((safe_sub_func_uint16_t_u_u
    (((((g_2241 >
         (((l_4990 <
     ((safe_mul_func_int8_t_s_s
       ((l_4768[2][2][0] =
         (safe_rshift_func_int16_t_s_u
          (l_4784,
           (g_2241 ==
            (safe_lshift_func_uint16_t_u_s
      ((!(18446744073709551615UL !=
          (((safe_add_func_int32_t_s_s ((safe_mul_func_uint16_t_u_u ((safe_sub_func_int8_t_s_s ((g_56 && g_1551), (safe_sub_func_int8_t_s_s (((safe_mul_func_int8_t_s_s (((0L && g_208[1]) || g_3487), l_4883)) || g_540[0][0][6]), l_5146)))), g_357)), (-1L))) || g_2945) >= l_5146))), 1)))))), l_5084)) <= 4UL)) >= l_4837[4][1][5]) || g_3331)) != 0x3CL) >= g_3) | g_208[1]), 1L)) || l_5084), l_4959[8])) < 0L));
   g_1923 = 0L;
   for (l_24 = 3; (l_24 >= 0); l_24 -= 1)
     {
       int16_t l_5148 = 1L;
       l_4837[4][1][5] = (1L == l_5148);
       l_5146
         =
         (l_5146
          >=
          (safe_mul_func_uint8_t_u_u
    (g_1551,
     ((safe_add_func_uint8_t_u_u
       ((g_4669 =
         (0xCFL == g_1081[0][2])), (l_5153
        && 0xA7D3L)))
      || g_1182[1]))));
     }
   l_5146
     =
     (safe_mod_func_uint64_t_u_u
      ((((((l_5156 > (0L & 0x9421E21DB828B6DELL))
    ||
    (safe_add_func_int64_t_s_s
     ((g_3807 =
       (-8L)),
      (-10L)))) !=
          ((safe_sub_func_int32_t_s_s
     ((((safe_lshift_func_int16_t_s_s
         ((safe_mod_func_uint32_t_u_u
           ((g_983 =
      (g_4880 =
       ((((safe_sub_func_uint8_t_u_u
           ((g_1394 =
      (safe_unary_minus_func_int64_t_s
       (((g_178 =
          (0x8CBBB171B3042B5FLL ^
           (safe_mul_func_int16_t_s_s
            ((g_2974 =
       (g_540[0][0][0] =
        l_5103)),
             g_1394)))) <=
         g_1272)))),
            g_2945)) ^ g_99[3]) &
         g_1182[2]) < g_4[1][9]))),
     g_1060)), 10)) ^ 3UL) != l_4907),
      4294967289UL)) == 0x33A5L)) >=
         g_1081[0][6]) & 247UL), g_2945));
        }
      for (g_4669 = 0; (g_4669 <= 3); g_4669 += 1)
        {
   int64_t l_5170 = 0xE56F299D56E42AFCLL;
   for (g_5019 = 0; (g_5019 <= 3); g_5019 += 1)
     {
       return g_189;
     }
   l_5170 = 2L;
        }
    }
  for (g_902 = 3; (g_902 >= 0); g_902 -= 1)
    {
      return g_4880;
    }
  for (g_4669 = 0; (g_4669 <= 3); g_4669 += 1)
    {
      g_921[5][7][0] = ((+l_5171) <= l_4851);
      l_5172 = l_4990;
    }
       }



     }


   for (g_4669 = 0; (g_4669 <= 3); g_4669 += 1)
     {
       g_921[5][7][0] = ((+l_5171) <= l_4851);
       {
  g_921[5][7][0] = ((+l_5171) <= l_4851);
  l_5172 = l_4990;
       }



       l_5172 = l_4990;
     }
 }
    }
  return l_4839;
}







static int8_t
  func_13
  (uint8_t p_14, int32_t p_15, uint32_t p_16, int32_t p_17, uint16_t p_18)
{
  int8_t l_26[10][6][4] =
  {
    {
      {
      0x0FL, 0x12L, (-1L), (-1L)},
      {
      8L, 1L, 0xC3L, 0x01L},
      {
      0x9CL, 5L, 0L, 8L},
      {
      0L, 0x13L, (-6L), 0xE9L},
      {
      0xD3L, 0x48L, 1L, 0xDBL},
      {
    0x94L, 5L, 8L, (-1L)}},
    {
      {
      0xE6L, (-1L), 2L, 2L},
      {
      0xDEL, 8L, 0x64L, (-4L)},
      {
      0xDBL, 0xABL, (-4L), 0x13L},
      {
      (-1L), 0x01L, 1L, 0xBDL},
      {
      0L, (-1L), 2L, 0xECL},
      {
    1L, 0xDBL, 2L, 2L}},
    {
      {
      (-7L), 1L, 0x7CL, 0L},
      {
      2L, (-1L), 2L, 0xDFL},
      {
      0x58L, 3L, (-4L), 0xD1L},
      {
      0x47L, 0x0FL, (-5L), 3L},
      {
      1L, 0xF5L, (-5L), 1L},
      {
    0x47L, 1L, (-4L), (-6L)}},
    {
      {
      0x58L, 0xE6L, 2L, (-6L)},
      {
      2L, (-6L), 0x7CL, (-4L)},
      {
      (-7L), 8L, 2L, 1L},
      {
      1L, 0L, 2L, 4L},
      {
      0L, (-1L), 1L, 1L},
      {
    (-1L), 0xBFL, (-4L), (-1L)}},
    {
      {
      0xDBL, (-1L), 0x64L, 0x94L},
      {
      0xDEL, (-1L), 2L, 0x63L},
      {
      0xE6L, 2L, 8L, 0x4BL},
      {
      0x94L, 0x78L, 1L, 0x12L},
      {
      0xD3L, 0L, (-6L), 0xE6L},
      {
    0L, (-5L), 0L, 0xFAL}},
    {
      {
      0x9CL, (-1L), 0xC3L, 0xABL},
      {
      8L, 1L, (-1L), 1L},
      {
      0x0FL, 0x37L, 0x78L, 0x58L},
      {
      0x64L, 0xC6L, 0xF5L, 0x33L},
      {
      (-5L), 1L, 4L, 0x64L},
      {
    0x37L, (-2L), 0L, 1L}},
    {
      {
      0x7DL, 0x07L, (-1L), 0L},
      {
      1L, 0xC7L, 0xD3L, 0L},
      {
      (-1L), 0L, 0xDEL, (-1L)},
      {
      (-6L), 0L, (-1L), (-1L)},
      {
      0xCAL, 0xCAL, 0L, 0x7CL},
      {
    1L, 0xD3L, 8L, 0L}},
    {
      {
      0xE9L, 0x5CL, (-1L), 8L},
      {
      0x01L, 0x5CL, 0xAAL, 0L},
      {
      0x5CL, 0xD3L, 0x79L, 0x7CL},
      {
      0x33L, 0xCAL, 5L, (-1L)},
      {
      (-3L), 0L, 0x07L, 0xECL},
      {
    1L, 0xE6L, 0x07L, 0xDEL}},
    {
      {
      0xC3L, (-5L), 0xE9L, 0x33L},
      {
      0xDBL, 0x7CL, 0xE6L, (-1L)},
      {
      4L, (-1L), 0x78L, 1L},
      {
      2L, 1L, 4L, 0xBDL},
      {
      0L, (-1L), (-1L), (-1L)},
      {
    2L, (-1L), (-1L), 5L}},
    {
      {
      3L, (-1L), 0x1EL, 2L},
      {
      0L, 0x12L, (-5L), 8L},
      {
      0x37L, 0xABL, (-1L), 0x37L},
      {
      0x94L, 0xD7L, 5L, 1L},
      {
      0x13L, 0xC3L, 0x5CL, 3L},
      {
  0x64L, 0L, 0x94L, 4L}}};
  int32_t l_3709 = 0x71CB1649L;
  uint8_t l_3759 = 0x4AL;
  int16_t l_3976 = 0x4737L;
  uint32_t l_4024 = 1UL;
  uint16_t l_4066 = 1UL;
  int16_t l_4136 = (-1L);
  int32_t l_4147 = 0x216DE20FL;
  int32_t l_4148 = 0x5A8B1347L;
  int32_t l_4149 = (-9L);
  int32_t l_4150[5];
  uint8_t l_4151[5][7] =
  {
    {
    0x1FL, 6UL, 0x1FL, 6UL, 0x1FL, 6UL, 0x1FL},
    {
    0x5FL, 0x5FL, 0x5FL, 0x5FL, 0x5FL, 0x5FL, 0x5FL},
    {
    0x1FL, 6UL, 0x1FL, 6UL, 0x1FL, 6UL, 0x1FL},
    {
    0x5FL, 0x5FL, 0x5FL, 0x5FL, 0x5FL, 0x5FL, 0x5FL},
    {
  0x1FL, 6UL, 0x1FL, 6UL, 0x1FL, 6UL, 0x1FL}};
  uint32_t l_4154 = 18446744073709551615UL;
  uint64_t l_4172 = 0x151FACFC27259E01LL;
  int8_t l_4404 = 0x5DL;
  int32_t l_4574 = 0xCCA4F45DL;
  uint32_t l_4575 = 0xBD75E6E1L;
  int32_t l_4657 = 1L;
  int32_t l_4701 = 0x13C5AB4DL;
  int i, j, k;
  for (i = 0; i < 5; i++)
    l_4150[i] = 0L;
lbl_4042:
  for (p_16 = 0; (p_16 <= 3); p_16 += 1)
    {
      int32_t l_35 = (-1L);
      int32_t l_3859 = 0xC0575F56L;
      uint8_t l_3897 = 0xF7L;
      int16_t l_3991 = 0xF060L;
      int8_t l_4002 = 0x4EL;
      for (p_14 = 0; (p_14 <= 3); p_14 += 1)
 {
   int64_t l_42 = 0xE3B8AEA20016C6A4LL;
   int32_t l_3710 = 0x577A1927L;
   p_17
     =
     ((65533UL >=
       (safe_rshift_func_int16_t_s_u
        ((g_4[0][8] |
   (safe_mul_func_int16_t_s_s
    (g_4[0][6],
     ((((+func_20
         ((safe_mul_func_int8_t_s_s
    (0x6DL,
     (1L ==
      (safe_sub_func_uint64_t_u_u
       (func_20
        (func_20
         (g_4[0][7], l_35,
          func_36 (p_18, l_42, p_17, g_4[1][4], p_17)),
         g_4[1][2], l_26[6][2][2]), p_15))))),
   l_26[9][3][1], g_4[1][2])) != g_4[1][2])
       && p_16) & p_15)))), g_2945))) >= l_26[7][5][2]);
   for (g_1272 = 0; (g_1272 <= 3); g_1272 += 1)
     {
       int i, j, k;
       l_3710
  =
  (0xFD1FC5C872D799A5LL
   ^
   ((safe_add_func_int8_t_s_s
     ((((safe_sub_func_int16_t_s_s
         ((safe_mul_func_uint8_t_u_u
    (l_26[(p_14 + 6)][g_1272][p_14], p_18)),
   0xE292L)) ^ 0x4BE91178L) ==
       (safe_mod_func_int64_t_s_s
        ((g_455 =
   (-1L)),
         (((safe_mul_func_int8_t_s_s
     (((safe_mul_func_uint16_t_u_u (g_2241, 9UL))
       ||
       ((safe_add_func_uint8_t_u_u
         ((l_3709 =
    l_26[(p_14 + 6)][g_1272][p_14]),
          g_1551)) | g_902)), g_2241)) != p_15)
   || l_3709)))), 0UL)) | p_18));
     }
 }
      if ((p_18 ==
    (safe_rshift_func_uint8_t_u_u
     (((safe_mod_func_int8_t_s_s (0xD2L, g_75)) | g_2519), 4))))
 {
   uint64_t l_3718 = 0x1A200B15A4E9F594LL;
   int8_t l_3721 = 0x29L;
   int32_t l_3792 = 0L;
   int32_t l_3796 = 0xBE6752B7L;
   int16_t l_3801 = (-5L);
   int8_t l_3896 = 0x76L;
   g_1272 = g_1395;
   for (p_14 = 0; (p_14 <= 3); p_14 += 1)
     {
       uint64_t l_3717 = 0x2A592DFB3A13E1CFLL;
       int32_t l_3793 = 0xADBFB178L;
       int64_t l_3917 = 1L;
       l_3718 = (safe_sub_func_uint32_t_u_u (l_35, l_3717));
       if ((safe_add_func_int8_t_s_s
     (l_35, ((l_3721 = g_455) | g_98))))
  {
    int64_t l_3723[5][7] =
    {
      {
      0L, 1L, 1L, 0L, 1L, 1L, 0L}
      ,
      {
      0xFDC5CA69A0212BC3LL, 0x30AFA6C8B9881059LL,
   0xFDC5CA69A0212BC3LL, 0x236DCCB5A495CFBDLL, 7L,
   0x236DCCB5A495CFBDLL, 0xFDC5CA69A0212BC3LL}
      ,
      {
      0L, 0L, (-5L), 0L, 0L, (-5L), 0L}
      ,
      {
      7L, 0x236DCCB5A495CFBDLL, 0xFDC5CA69A0212BC3LL,
   0x30AFA6C8B9881059LL, 0xFDC5CA69A0212BC3LL,
   0x236DCCB5A495CFBDLL, 7L}
      ,
      {
      1L, 0L, 1L, 1L, 0L, 1L, 1L}
    };
    int32_t l_3772 = (-1L);
    int i, j;
    p_17 = (safe_unary_minus_func_int64_t_s (l_3717));
    if (l_3723[1][6])
      {
        int16_t l_3730[8] =
        {
        2L, 2L, 1L, 2L, 2L, 1L, 2L, 2L};
        int32_t l_3758 = 5L;
        int i;
        if (p_18)
   break;
        p_17 = l_3723[1][6];
        l_3759
   =
   ((-8L) ==
    (g_1863 =
     (((((((safe_lshift_func_uint16_t_u_u
     (((safe_sub_func_int32_t_s_s
        (g_1863,
         (p_17 =
          (safe_rshift_func_int16_t_s_s
           (l_3730[0],
     (((safe_mul_func_int8_t_s_s
        ((safe_mul_func_uint8_t_u_u
          ((safe_rshift_func_uint8_t_u_s
            (((safe_mod_func_uint8_t_u_u
        ((((safe_mod_func_uint16_t_u_u (((safe_unary_minus_func_uint8_t_u ((g_1678 & (safe_lshift_func_int8_t_s_u ((((l_3758 = (safe_rshift_func_uint16_t_u_u ((p_14 == (safe_lshift_func_uint8_t_u_s ((((safe_mul_func_uint16_t_u_u ((+(safe_sub_func_uint64_t_u_u ((((safe_sub_func_int32_t_s_s ((-1L), ((safe_mul_func_uint8_t_u_u (p_18, (g_75 || ((safe_rshift_func_uint8_t_u_s ((0xDF1AL ^ g_4[1][2]), p_15)) <= p_14)))) ^ l_3709))) >= l_3730[3]) & g_655), g_922))), g_2791)) | g_208[2]) >= g_455), 6))), 11))) && 2L) | l_3723[3][3]), 6))))) == l_3718), l_3717)) ^ l_3730[6]) == 0xD6L), 0xEDL)) > p_14), 2)), g_1395)), p_17)) && g_2241) & l_3709)))))) <= p_18), g_1182[1])) >= 0x3CL) <= 1L) | p_15) > l_3730[3]) == p_16) != g_921[5][7][0])));
      }
    else
      {
        int32_t l_3778 = 1L;
        g_208
   [0]
   =
   (l_3717
    &&
    (safe_mul_func_int8_t_s_s
     (g_575,
      ((safe_mul_func_int8_t_s_s
        ((safe_add_func_int8_t_s_s ((-1L), p_14)),
         ((((safe_add_func_int32_t_s_s
      ((safe_add_func_int16_t_s_s
        ((safe_sub_func_uint8_t_u_u
          (l_3772,
           ((safe_unary_minus_func_uint32_t_u
      ((safe_mod_func_uint16_t_u_u
        (g_3331,
         ((l_3759 |
           (((safe_rshift_func_uint16_t_u_s
       (0x4C6AL,
        p_16)) != g_703) !=
            0x722FL)) || l_3717)))))
     && 9UL))), l_35)), g_455))
     && p_18) >= l_35)
          || (-1L)))) >= 0x344011D6A93DFA71LL))));
        l_3793 =
   (+
    (((l_3778 ==
       ((g_922 >=
         (p_14
          &&
          ((safe_mul_func_int8_t_s_s
     ((l_35 =
       (g_3175 =
        (safe_rshift_func_uint16_t_u_s
         ((safe_mod_func_uint64_t_u_u
           ((safe_mod_func_int16_t_s_s
      (l_35,
       (safe_sub_func_uint32_t_u_u
        ((((g_2241
            &&
            ((l_35 !=
       ((0xD24DBAB3L !=
         ((~
           ((((g_983 =
        g_1182[2]) <=
       (safe_unary_minus_func_int64_t_s
        ((safe_sub_func_uint8_t_u_u ((((g_75 < l_3792) > g_75) & p_18), p_15))))) ^ 0x794B7A2DA470135BLL) <= 1UL)) != g_3331)) || l_3721)) & l_3778)) && 0x31D4L) <= l_3717), p_18)))), p_18)), 12)))), g_1182[2])) || g_208[2]))) | 1L)) || l_3721) || 0L));
        p_17 =
   ((l_35 =
     (safe_mul_func_uint16_t_u_u
      (((l_3778 =
         (l_3796 =
          p_14)) > 18446744073709551615UL),
       ((safe_sub_func_uint8_t_u_u
         ((g_3807 =
    ((0x77C2L
      ||
      ((~
        (((p_18 =
           (safe_lshift_func_uint16_t_u_s
     (g_540[0][0][0], 7))) <= ((0L
           || (l_3801
               ||
               (l_3723
         [1][2]
         ||
         ((l_3709 = ((safe_unary_minus_func_int64_t_s ((safe_rshift_func_uint8_t_u_u ((safe_add_func_uint32_t_u_u ((l_3717 && (g_2974 | l_35)), l_3717)), g_3487)))) == 0x9499EF2F5C437C3FLL)) <= p_14)))) > 0UL)) == g_1551)) & g_921[5][7][0])) | p_15)), g_540[0][0][0])) <= (-4L))))) <= l_3793);
      }
    p_17 = (safe_sub_func_int64_t_s_s ((-1L), (g_1395 = g_56)));
    for (g_2791 = 0; (g_2791 <= 3); g_2791 += 1)
      {
        l_35 = p_16;
        g_921[5][7][0] = (g_2227 < p_18);
        return l_3717;
      }
  }
       else
  {
    uint32_t l_3835[6][10][4] =
    {
      {
        {
        0UL, 0x631B92F9L, 1UL, 4294967291UL}
        ,
        {
        0x9085800BL, 1UL, 4294967295UL, 0x81ABB1ADL}
        ,
        {
        0x9085800BL, 1UL, 1UL, 0x5CADD375L}
        ,
        {
        0UL, 0x81ABB1ADL, 0x4271C282L, 1UL}
        ,
        {
        0x9085800BL, 0x631B92F9L, 0xEDC58E0FL, 0x631B92F9L}
        ,
        {
        0x9085800BL, 1UL, 0x4271C282L, 0x81ABB1ADL}
        ,
        {
        0UL, 0x5CADD375L, 1UL, 1UL}
        ,
        {
        0x9085800BL, 0x81ABB1ADL, 4294967295UL, 1UL}
        ,
        {
        0x9085800BL, 4294967291UL, 1UL, 0x631B92F9L}
        ,
        {
        0UL, 1UL, 0x4271C282L, 0xA9426266L}
      }
      ,
      {
        {
        0x9085800BL, 0x5CADD375L, 0xEDC58E0FL, 0x5CADD375L}
        ,
        {
        0x9085800BL, 0xA9426266L, 0x4271C282L, 1UL}
        ,
        {
        0UL, 0x631B92F9L, 1UL, 4294967291UL}
        ,
        {
        0x9085800BL, 1UL, 4294967295UL, 0x81ABB1ADL}
        ,
        {
        0x9085800BL, 1UL, 1UL, 1UL}
        ,
        {
        0x6579A3ABL, 0xA9426266L, 4294967295UL, 0UL}
        ,
        {
        0UL, 4294967291UL, 4294967295UL, 4294967291UL}
        ,
        {
        0UL, 0UL, 4294967295UL, 0xA9426266L}
        ,
        {
        0x6579A3ABL, 1UL, 0xEDC58E0FL, 1UL}
        ,
        {
        0UL, 0xA9426266L, 3UL, 1UL}
      }
      ,
      {
        {
        0UL, 4294967294UL, 0xEDC58E0FL, 4294967291UL}
        ,
        {
        0x6579A3ABL, 1UL, 4294967295UL, 0UL}
        ,
        {
        0UL, 1UL, 4294967295UL, 1UL}
        ,
        {
        0UL, 0UL, 4294967295UL, 1UL}
        ,
        {
        0x6579A3ABL, 4294967291UL, 0xEDC58E0FL, 4294967294UL}
        ,
        {
        0UL, 1UL, 3UL, 0xA9426266L}
        ,
        {
        0UL, 1UL, 0xEDC58E0FL, 1UL}
        ,
        {
        0x6579A3ABL, 0xA9426266L, 4294967295UL, 0UL}
        ,
        {
        0UL, 4294967291UL, 4294967295UL, 4294967291UL}
        ,
        {
        0UL, 0UL, 4294967295UL, 0xA9426266L}
      }
      ,
      {
        {
        0x6579A3ABL, 1UL, 0xEDC58E0FL, 1UL}
        ,
        {
        0UL, 0xA9426266L, 3UL, 1UL}
        ,
        {
        0UL, 4294967294UL, 0xEDC58E0FL, 4294967291UL}
        ,
        {
        0x6579A3ABL, 1UL, 4294967295UL, 0UL}
        ,
        {
        0UL, 1UL, 4294967295UL, 1UL}
        ,
        {
        0UL, 0UL, 4294967295UL, 1UL}
        ,
        {
        0x6579A3ABL, 4294967291UL, 0xEDC58E0FL, 4294967294UL}
        ,
        {
        0UL, 1UL, 3UL, 0xA9426266L}
        ,
        {
        0UL, 1UL, 0xEDC58E0FL, 1UL}
        ,
        {
        0x6579A3ABL, 0xA9426266L, 4294967295UL, 0UL}
      }
      ,
      {
        {
        0UL, 4294967291UL, 4294967295UL, 4294967291UL}
        ,
        {
        0UL, 0UL, 4294967295UL, 0xA9426266L}
        ,
        {
        0x6579A3ABL, 1UL, 0xEDC58E0FL, 1UL}
        ,
        {
        0UL, 0xA9426266L, 3UL, 1UL}
        ,
        {
        0UL, 4294967294UL, 0xEDC58E0FL, 4294967291UL}
        ,
        {
        0x6579A3ABL, 1UL, 4294967295UL, 0UL}
        ,
        {
        0UL, 1UL, 4294967295UL, 1UL}
        ,
        {
        0UL, 0UL, 4294967295UL, 1UL}
        ,
        {
        0x6579A3ABL, 4294967291UL, 0xEDC58E0FL, 4294967294UL}
        ,
        {
        0UL, 1UL, 3UL, 0xA9426266L}
      }
      ,
      {
        {
        0UL, 1UL, 0xEDC58E0FL, 1UL}
        ,
        {
        0x6579A3ABL, 0xA9426266L, 4294967295UL, 0UL}
        ,
        {
        0UL, 4294967291UL, 4294967295UL, 4294967291UL}
        ,
        {
        0UL, 0UL, 4294967295UL, 0xA9426266L}
        ,
        {
        0x6579A3ABL, 1UL, 0xEDC58E0FL, 1UL}
        ,
        {
        0UL, 0xA9426266L, 3UL, 1UL}
        ,
        {
        0UL, 4294967294UL, 0xEDC58E0FL, 4294967291UL}
        ,
        {
        0x6579A3ABL, 1UL, 4294967295UL, 0UL}
        ,
        {
        0UL, 1UL, 4294967295UL, 1UL}
        ,
        {
        0UL, 0UL, 4294967295UL, 1UL}
      }
    };
    int32_t l_3860[6][5] =
    {
      {
      0x341BF478L, 1L, 0x341BF478L, 1L, 0x341BF478L}
      ,
      {
      0x7915107CL, 0xAEAFD669L, 0xAEAFD669L, 0x7915107CL,
   0x7915107CL}
      ,
      {
      0L, 1L, 0L, 1L, 0L}
      ,
      {
      0x7915107CL, 0x7915107CL, 0xAEAFD669L, 0xAEAFD669L,
   0x7915107CL}
      ,
      {
      0x341BF478L, 1L, 0x341BF478L, 1L, 0x341BF478L}
      ,
      {
      0x7915107CL, 0xAEAFD669L, 0xAEAFD669L, 0x7915107CL,
   0x7915107CL}
    };
    int i, j, k;
    g_575
      =
      (l_3718
       ==
       (((safe_lshift_func_int16_t_s_s
   ((safe_rshift_func_int16_t_s_u
     ((safe_mod_func_int64_t_s_s
       (g_1182[2],
        (safe_sub_func_int16_t_s_s
         (0xC37CL,
          (((safe_add_func_int8_t_s_s
      ((p_14 !=
        (safe_add_func_int8_t_s_s
         (((safe_unary_minus_func_uint32_t_u
     ((safe_mul_func_uint16_t_u_u
       ((~
         (safe_sub_func_int16_t_s_s
          (l_3793, g_1081[0][4]))),
        ((+
          (safe_add_func_uint16_t_u_u
           (((((5L <
         ((safe_add_func_int16_t_s_s
           ((safe_sub_func_uint8_t_u_u (g_1923, (g_359 = (safe_mul_func_uint8_t_u_u (1UL, l_3835[0][6][2]))))), l_35)) < p_16)) <= g_99[1]) > p_16) & p_18), p_14))) != g_2974))))) | 1L), 0xB6L))), l_3835[0][6][2])) && p_15) != g_1551))))), 3)), l_3801)) != g_540[0][0][7]) != 7L));
    p_17 = (safe_unary_minus_func_int16_t_s (0x1358L));
    p_17 = 4L;
    p_17
      =
      (l_3860
       [1]
       [4]
       =
       ((g_1678 =
         (safe_mul_func_int8_t_s_s
   ((1L >= l_3721),
    (safe_rshift_func_uint16_t_u_s
     ((((0UL
         &&
         (safe_lshift_func_uint8_t_u_u
          (246UL,
    (l_3859 =
     (p_14 >=
      (safe_add_func_uint16_t_u_u
       (((l_35 =
          (safe_mul_func_int8_t_s_s
           (((safe_sub_func_int64_t_s_s
       (g_236,
        ((p_18 &
          (safe_mod_func_int32_t_s_s
           ((safe_mod_func_int16_t_s_s
      ((safe_mul_func_uint8_t_u_u
        ((l_3793 ==
          (safe_mod_func_int32_t_s_s
           ((((safe_rshift_func_int16_t_s_s ((p_18 < 0x57L), g_3)) <= l_3835[0][6][2]) || l_35), l_3717))), l_3759)), g_1272)), p_16))) & p_15))) == p_14), g_540[0][0][0]))) >= l_3793), 4UL))))))) != (-4L)) >= g_806), 13))))) >= l_3718));
  }
       g_3
  =
  ((safe_mod_func_uint16_t_u_u
    (((safe_add_func_int64_t_s_s
       ((safe_sub_func_uint32_t_u_u
         ((safe_rshift_func_uint8_t_u_u
    (0xFFL,
     (((p_18 &
        ((p_18 |
          ((((l_3759 >=
       ((safe_mul_func_uint16_t_u_u
         (((((g_1551 =
       (safe_add_func_uint16_t_u_u
        ((safe_sub_func_int64_t_s_s
          (p_15, 0xA4746D6BFFAA20B5LL)),
         p_18))) | (l_3796 =
             (((((p_17 =
           ((~0xBCL) &
            (1L | g_1678)))
          >= 0x241F9B21L) >
         g_2519) ==
        g_897) & g_209))) <=
     3UL) | 5UL), 65535UL)) <= l_3793))
      || p_17)
     || p_15) != 5L)) < 1UL)) & 0x9FL) <=
      g_4[1][2]))), g_983)), g_1182[2])) <= g_1182[1]),
     l_3709)) | g_2227);
       for (g_806 = 0; (g_806 <= 3); g_806 += 1)
  {
    int32_t l_3881 = 0xC97E8082L;
    int i, j, k;
    if (((((safe_sub_func_uint8_t_u_u
     (g_99[p_16],
      l_26[(p_14 + 1)][(p_14 +
          1)][p_16])) ^
    (((((safe_sub_func_int32_t_s_s
         ((safe_lshift_func_int8_t_s_s
    (((-1L)
      || (l_3881 ==
          ((safe_mod_func_int16_t_s_s
     ((safe_sub_func_int16_t_s_s
       ((safe_mul_func_uint16_t_u_u
         ((safe_mul_func_int32_t_s_s
           (p_15,
            ((safe_sub_func_uint16_t_u_u
       ((safe_add_func_int64_t_s_s
         (((safe_rshift_func_uint16_t_u_s (g_1863, ((l_3896 < (l_3717 == ((((l_3801 < 4294967295UL) > l_3717) || (-1L)) || p_18))) ^ g_655))) >= l_3897), p_15)), g_655)) == l_3759))), g_98)), 0x8DBFL)), l_3709)) & (-1L)))), l_3793)), p_14)) ^ g_575) < g_3898) | 2L) != 1L)) || l_3793) != 1UL))
      {
        uint32_t l_3899 = 0x2CAB29C4L;
        l_3899 = p_18;
        return p_17;
      }
    else
      {
        int32_t l_3916[9] =
        {
        0xC178DC66L,
     0x0F3C143BL,
     0xC178DC66L,
     0xC178DC66L,
     0x0F3C143BL,
     0xC178DC66L, 0xC178DC66L, 0x0F3C143BL, 0xC178DC66L};
        int i;
        g_208
   [1]
   =
   (safe_sub_func_int16_t_s_s
    ((safe_add_func_uint16_t_u_u
      (((-2L) <=
        (((0x8EL != p_18)
          || ((p_16 && p_16) <=
       ((safe_sub_func_int64_t_s_s
         (((p_17 ==
     ((safe_rshift_func_uint16_t_u_s
       ((safe_sub_func_int64_t_s_s
         ((safe_sub_func_uint16_t_u_u
           ((g_178 =
      (l_3796 !=
       (g_983 <
        (safe_mul_func_uint8_t_u_u
         (((0x9BL | 0x09L) <
           l_3717), 0x6DL))))),
            0x812AL)), g_2241)),
        g_1081[0][0]))
      || g_2241)) & p_18), (-6L)))
        || g_540[0][0][3]))) == l_3916[1])),
       g_99[p_16])), p_15));
        return l_3917;
      }
  }
       for (l_3718 = 0; (l_3718 <= 3); l_3718 += 1)
  {
    int8_t l_3927 = 0xFFL;
    uint64_t l_4005 = 0x44905046337D9467LL;
    int i, j, k;
    p_17 = p_18;
    g_3
      =
      (g_921
       [5]
       [7]
       [0]
       =
       (g_1182
        [1]
        &&
        ((!4294967287UL) <=
         (safe_sub_func_uint32_t_u_u
   (g_236,
    ((g_208[1] >= p_17) >
     (l_3793 =
      ((((((safe_rshift_func_int8_t_s_u
     (((safe_unary_minus_func_uint16_t_u
        ((0xB15341CCL
          && (0x195AD1950E6343E3LL
       && 0xB8F5825BC5AB5CC4LL)))) |
       (l_26[(p_16 + 1)][(p_16 + 2)][l_3718] =
        (((((safe_mul_func_uint64_t_u_u
      (((((safe_mod_func_int8_t_s_s
           (g_99[3], 0x92L)) != l_3927)
         && p_14) != 0x0B60D10A58D1E928LL),
       0L)) >= g_3807) !=
           p_18) & g_1081[0][8]) != p_15))),
      p_14))
    && g_2519) != p_18) & 0x28L) | 0xB086L)
       && g_1394))))))));
    if (((((safe_sub_func_int16_t_s_s
     ((g_189 =
       l_3721),
      (((safe_add_func_uint16_t_u_u
         ((safe_rshift_func_uint16_t_u_s
    ((g_3950 =
      ((g_56 =
        (safe_add_func_int32_t_s_s
         (((safe_mul_func_uint8_t_u_u
     (0x21L,
      ((((safe_mod_func_int32_t_s_s
          ((safe_lshift_func_int16_t_s_s
            (0x42E8L, 10)), (g_3487 =
        g_983))) <=
         ((((g_2241 =
      (~(!0xB31E2465L))) |
            (safe_lshift_func_int16_t_s_s
      ((g_2599
        &&
        (safe_mul_func_uint16_t_u_u
         ((0UL <
           (safe_mul_func_int16_t_s_s
            ((safe_sub_func_int16_t_s_s (l_3897, (g_1678 = p_16))), g_359))), p_17))), p_15))) & l_35) <= g_3807)) >= l_3897) ^ g_3175))) > l_26[2][1][2]), g_1182[0]))) || g_1863)), 4)), 8L)) >= g_97) != 4L))) <= p_15) | p_14) != 0x098CL))
      {
        g_3
   =
   (safe_rshift_func_int16_t_s_u
    ((safe_rshift_func_uint16_t_u_s
      (((safe_mod_func_int32_t_s_s
         (((((safe_lshift_func_int8_t_s_s
       (((safe_sub_func_uint64_t_u_u
          (((safe_mul_func_uint8_t_u_u
      ((g_1863 =
        248UL),
       (0x40D1L !=
        0x8931L))) ^ (g_1182[2] =
        (safe_unary_minus_func_int16_t_s
         ((safe_rshift_func_int8_t_s_u ((!(l_35 = (safe_sub_func_uint32_t_u_u ((safe_add_func_int32_t_s_s ((l_3859 = (p_16 != (((safe_add_func_int64_t_s_s ((l_3801 & 0xDF5DA105L), ((~(safe_mul_func_uint16_t_u_u ((safe_mod_func_uint16_t_u_u (p_15, g_2519)), (((g_455 = ((((p_15 < l_3717) == p_16) | l_3859) ^ p_16)) >= l_26[0][2][1]) & (-8L))))) & g_1081[0][0]))) >= l_3717) >= g_280))), p_17)), 4294967295UL)))), 5)))))), 0x0769C4080DEC03ECLL)) ^ g_2519), 3)) >= g_3487) <= 18446744073709551615UL) || g_97), g_1081[0][1])) == 0xC1A39ED2L), g_3898)), l_3976));
        if (p_18)
   continue;
      }
    else
      {
        uint16_t l_4000 = 5UL;
        int16_t l_4001 = 0x886CL;
        g_921
   [2]
   [8]
   [0]
   =
   (safe_mod_func_int64_t_s_s
    ((safe_lshift_func_uint16_t_u_s
      ((0xEC0BL
        ||
        ((safe_add_func_int16_t_s_s
          ((l_3793 =
     0xB97CL),
    ((safe_lshift_func_int16_t_s_u
      (((safe_mod_func_uint32_t_u_u
         ((safe_sub_func_int8_t_s_s
           (((l_35 =
       0xE3L) & (~(l_3792 <=
            (safe_sub_func_uint32_t_u_u
             (g_4[1][3],
       (g_208[1] =
        (1L |
         (+g_3898)))))))),
     l_3859)), (-2L))) & 7UL),
       l_26[(p_16 + 1)][(p_16 +
           2)][l_3718])) & l_3991)))
         ^ p_16)), g_1551)), g_357));
        g_3 = (l_3796 = 0x979B7497L);
        g_208
   [2]
   =
   (((g_56
      ||
      (safe_rshift_func_int16_t_s_u
       (((safe_mul_func_int8_t_s_s
          ((g_655 ^
     (l_26[(p_16 + 1)][(p_16 + 2)][l_3718] &
      (0x43L == l_3976))),
    ((safe_add_func_uint64_t_u_u
      ((g_98 < l_4000),
       (0x6DL <=
        ((65535UL < l_3897) | g_1394)))) != 0UL)))
         || 9L), l_4001))) == p_17) <= l_3897);
        if (p_15)
   break;
      }
    g_208
      [2]
      =
      ((l_4002 =
        0xB72C47E3L) !=
       (safe_sub_func_uint32_t_u_u
        ((l_4005 =
   p_14),
         ((safe_mul_func_uint16_t_u_u
    (g_1272,
     (safe_mod_func_int8_t_s_s (l_3897, g_2519)))) ^
   ((safe_rshift_func_uint8_t_u_u (g_2227, 4)) <
    (l_3793 = g_806))))));
  }
     }
   g_1923
     =
     (((safe_lshift_func_int8_t_s_s
        ((4294967295UL
   || p_17),
  ((safe_mod_func_uint16_t_u_u
    (((-2L) < (l_3859 != g_1081[0][0])),
     ((l_4024 =
       ((l_3801 ^
         (((safe_add_func_int64_t_s_s
     ((l_4002 < p_15),
      ((l_3796 =
        (safe_mul_func_uint8_t_u_u
         ((safe_rshift_func_int16_t_s_s
    ((safe_sub_func_uint8_t_u_u (g_357, 254UL)),
     g_209)), l_3976)))
       || l_3897))) ^ g_208[2]) & p_17)) == 246UL))
      || p_15))) <= p_16))) && 0xEC49F14CC0427872LL) <= l_3897);
   g_921[5][7][0] = p_15;
 }
      else
 {
   return g_99[1];
 }
      p_17 = (safe_lshift_func_uint8_t_u_u (g_3331, 3));
    }


lbl_4619:
  l_3709 = 0xD0B8A6E9L;
  if (((safe_mul_func_uint16_t_u_u (p_14, p_16)) <=
       ((((safe_sub_func_int8_t_s_s
    ((safe_rshift_func_int8_t_s_s
      ((safe_rshift_func_uint16_t_u_u
        (((l_3759
    &&
    ((l_4150[0] =
      (l_4149 =
       (safe_sub_func_uint16_t_u_u
        ((safe_rshift_func_int16_t_s_s
   ((l_3759 ^
     (((((((safe_add_func_int64_t_s_s
     ((l_3709
       ||
       (safe_rshift_func_int8_t_s_u
        (l_4136,
         (safe_lshift_func_uint8_t_u_u
          (((safe_rshift_func_uint8_t_u_s
      (((safe_mul_func_int8_t_s_s
         (((l_3709 =
            0x8365EBBCABBD9615LL) < p_17),
          (safe_mod_func_uint64_t_u_u
           ((g_806 =
      (l_4148 =
       (+
        (l_4147 =
         (safe_add_func_int8_t_s_s
          ((1UL ^ 0x6D9D2375L),
           g_4[1][2])))))),
            p_15)))) &
        0x7ADC2CD341480F78LL),
       6)) <= 0xE8L), 4))))),
      g_1678)) <= g_4[0][6]) <= g_1060) >=
         g_540[0][0][1]) > g_983) == p_16) >
      0x929B66180C6DEFA5LL)), l_4066)),
         l_3976)))) == p_17)) > l_4024), 4)), 6)),
     251UL)) == g_1395) < g_209) < p_18)))
    {
      int16_t l_4157 = 0L;
      int32_t l_4158 = 0x8A5423E5L;
      uint32_t l_4171 = 0x507BCBEFL;
      int32_t l_4301 = 0xCCCE85EBL;
      uint16_t l_4337 = 0x8719L;
      uint32_t l_4377[5];
      int8_t l_4536 = (-3L);
      int64_t l_4551 = 0x238BC2E5ED6E22E9LL;
      int8_t l_4591 = 0x81L;
      int16_t l_4620[5][10] =
      {
 {
 1L, 0L, (-3L), 0L, 1L, 1L, 0L, (-3L), 0L, 1L}
 ,
 {
 1L, 0L, (-3L), 0L, 1L, 1L, 0L, (-3L), 0L, 1L}
 ,
 {
 1L, 0L, (-3L), 0L, 1L, 1L, 0L, (-3L), 0L, 1L}
 ,
 {
 1L, 0L, (-3L), 0L, 1L, 1L, 0L, (-3L), 0L, 1L}
 ,
 {
 1L, 0L, (-3L), 0L, 1L, 1L, 0L, (-3L), 0L, 1L}
      };
      int i, j;


    lbl_4285:
      l_4151[3][2] = ((-1L) | (-6L));
    lbl_4517:
      g_1923 =
 ((((l_4150[0] =
     (0L >
      (l_4158 =
       (safe_lshift_func_int8_t_s_s
        (l_4154,
  (g_3175 <
   (l_4149 =
    (safe_mul_func_uint8_t_u_u (l_4151[3][2], l_4157))))))))) <
    (safe_mod_func_int16_t_s_s
     ((((safe_mod_func_int8_t_s_s (0xF4L, 0x2AL)) ^
        (p_16 <= 0x00121A3730ED7807LL)) & l_4154),
      0xFE16L))) >= p_18) & 0UL);
    lbl_4518:
      p_17 = l_4157;


    }
  else
    {
      uint8_t l_4666[3];
      int32_t l_4689 = 0xFBEDA966L;
      int i;


      for (i = 0; i < 5; i++)
 l_4150[i] = 0L;


      p_17 = (g_455 >= g_1182[1]);
      for (i = 0; i < 3; i++)
 l_4666[i] = 0xD2L;







      p_17 = (g_455 >= g_1182[1]);


    }
  l_4150[i] = 0L;



  return g_2519;
}







static int32_t func_20 (uint32_t p_21, uint8_t p_22, int16_t p_23)
{
  uint16_t l_25 = 0x5435L;
  l_25 = p_21;
  return p_23;
}







static int16_t
  func_36
  (uint32_t p_37, int32_t p_38, int32_t p_39, int64_t p_40, uint8_t p_41)
{
  uint64_t l_45[9];
  int32_t l_3381 = 0x3AFA29F6L;
  int32_t l_3383 = (-7L);
  uint8_t l_3512 = 0x0BL;
  int32_t l_3515[4][2] =
  {
    {
    (-5L), 0L},
    {
    0L, (-5L)},
    {
    0L, 0L},
    {
  (-5L), 0L}};
  int i, j;
  for (i = 0; i < 9; i++)
    l_45[i] = 0x263D1F0774A76864LL;
  for (p_37 = (-14); (p_37 < 21); p_37 = safe_add_func_uint16_t_u_u (p_37, 2))
    {
      uint64_t l_55 = 0xEE2C543511282808LL;
      int32_t l_69 = 0x633F4C62L;
      int32_t l_70 = 5L;
      int16_t l_3543 = 0xE64AL;


      if (l_3515[1][0])
 {
   return l_70;
 }
      else
 {
   uint16_t l_3542 = 1UL;
   int32_t l_3544 = 2L;
   int64_t l_3649 = 1L;




 }
      p_39 = l_45[1];
    }
  l_3381
    =
    ((((0xE4443A13L <
 ((safe_mul_func_uint16_t_u_u
   ((0xB0527F44L ^
     ((safe_mod_func_int8_t_s_s
       ((g_56 =
  (safe_mul_func_int8_t_s_s
   ((safe_add_func_uint8_t_u_u
     ((safe_add_func_uint64_t_u_u
       ((g_806 =
         ((safe_unary_minus_func_int32_t_s ((p_39 = l_3381)))
   &&
   (((safe_sub_func_uint16_t_u_u
      (((!(safe_sub_func_int8_t_s_s
    ((safe_add_func_uint8_t_u_u
      (((safe_rshift_func_uint8_t_u_u
         (g_540[0][0][6], 3)) & ((l_3383 =
             0UL) == 3L)),
       g_3487)),
     ((-9L) <
      (safe_lshift_func_int8_t_s_u
       ((safe_mul_func_uint16_t_u_u
         ((0L < l_45[7]), p_41)), g_178))))))
        || g_1060), p_37)) | 0x6B92L)
    && p_37))), 5L)), l_3381)), g_3175))),
        g_1272)) | l_3515[1][0])),
    0x2783L)) < p_38)) == g_540[0][0][2]) > 0x98391A6F28005721LL) <
     l_45[4]);
  p_39 = 7L;
  return p_37;
}







static int32_t
  func_46 (int32_t p_47, uint64_t p_48, uint16_t p_49, uint32_t p_50)
{
  uint8_t l_2696 = 254UL;
  int32_t l_2697[1][8] =
  {
    {
    1L, 1L, 1L, 1L, 1L, 1L, 1L, 1L}
  };
  int32_t l_2722 = (-1L);
  uint8_t l_2767[5];
  int32_t l_2898[9];
  int64_t l_2999 = 0x4F8D2B2D30D94C51LL;
  int64_t l_3066 = 7L;
  int i, j;
  for (i = 0; i < 5; i++)
    ;



  for (i = 0; i < 9; i++)
    l_2898[i] = 0L;




  return g_178;
}







static uint8_t func_66 (uint32_t p_67, uint8_t p_68)
{
  int32_t l_71[10][9] =
  {
    {
    0x835E52A1L,
 0x835E52A1L,
 6L, 0x5B60A5FBL, 6L, 0x835E52A1L, 0x835E52A1L, 6L, 0x5B60A5FBL},
    {
    3L,
 (-10L),
 3L, 8L, 0xFEE841A1L, 0x55787DF3L, 0x30FE8BACL, 0x55787DF3L,
 0xFEE841A1L},
    {
    0x9B852D78L, 6L, 6L, 0x9B852D78L, 0L, 0x9B852D78L, 6L, 6L, 0x9B852D78L},
    {
    0xFCAFA235L, 8L, 1L, 8L, 0xFCAFA235L, (-7L), 0xFEE841A1L, 0x3DA4F77CL,
 0xFEE841A1L},
    {
    6L, 0L, 0x5B60A5FBL, 0x5B60A5FBL, 0L, 6L, 0L, 0x5B60A5FBL, 0x5B60A5FBL},
    {
    0xFCAFA235L, (-7L), 0xFEE841A1L, 0x3DA4F77CL, 0xFEE841A1L, (-7L),
 0xFCAFA235L, 8L, 1L},
    {
    0x9B852D78L, 0L, 0x9B852D78L, 6L, 6L, 0x9B852D78L, 0L, 0x9B852D78L, 6L},
    {
    3L, 8L, 0xFEE841A1L, 0x55787DF3L, 0x30FE8BACL, 0x55787DF3L, 0xFEE841A1L,
 8L, 3L},
    {
    0x835E52A1L, 6L, 0x5B60A5FBL, 6L, 0x835E52A1L, 0x835E52A1L, 6L,
 0x5B60A5FBL, 6L},
    {
  0xFEE841A1L, (-10L), 1L, 0x3DA4F77CL, 0x30FE8BACL, 8L, 0x30FE8BACL,
 0x3DA4F77CL, 1L}};
  int32_t l_74 = 0xB1D7879CL;
  int32_t l_826 = 1L;
  int32_t l_2581 = 0xDB8F6877L;
  int32_t l_2586[5];
  int32_t l_2624 = 0xC2820EFCL;
  int i, j;


  for (i = 0; i < 5; i++)
    l_2586[i] = 0x7960FA45L;


lbl_2478:
  l_71[6][3] = 0x69BA6CE2L;
  l_74
    =
    (safe_mul_func_int8_t_s_s
     (2L,
      ((func_20
 (g_4[1][2], l_74,
  func_20 (((((g_75 =
        g_4[1][2]) > p_68) != (func_76 (l_71[1][7],
            ((func_81
       (((l_826 =
          (safe_mul_func_uint16_t_u_u
           ((g_4[1][2] <=
             (safe_mul_func_uint8_t_u_u
              (g_4[1][2],
        (safe_rshift_func_uint8_t_u_s
         (func_91
          (((g_98 =
             (g_97 =
              ((safe_lshift_func_uint16_t_u_s (func_20 (g_4[1][2], p_68, g_4[1][1]), l_71[6][3])) | l_74))) && p_68), l_71[6][3], l_74), 5))))), 0xFFD7L))) && 0x5159L), l_71[6][3], p_67) && p_68) != l_71[6][3]), l_71[6][3], g_2241) <= l_71[6][3])) & g_2241), p_67, p_68)) == g_2241) & 0L)));


  for (i = 0; i < 5; i++)
    l_2586[i] = 0x7960FA45L;


  for (g_575 = 0; (g_575 >= 10); ++g_575)
    {
      int64_t l_2602 = (-1L);
      int32_t l_2625 = (-6L);
      g_208[0] = (!(((l_71[3][3] ^ (l_2602 >= (+(+(safe_lshift_func_uint16_t_u_u (g_359, (l_2586[2] = ((safe_unary_minus_func_uint16_t_u ((g_922 = (+(g_902 & (((safe_lshift_func_int16_t_s_s ((((safe_rshift_func_int16_t_s_u (((safe_mod_func_int16_t_s_s ((1UL >= (g_359 && g_2599)), g_189)) | (!(safe_rshift_func_int8_t_s_s ((safe_rshift_func_int16_t_s_s (g_178, g_209)), 6)))), p_67)) >= 0x99D190852898EA8ALL) ^ g_2519), 10)) != p_67) >= g_540[0][0][0])))))) & g_703)))))))) <= p_68) | p_67));
      {
 int64_t l_2602 = (-1L);
 int32_t l_2625 = (-6L);
 g_208
   [0]
   =
   (!
    (((l_71[3][3] ^
       (l_2602 >=
        (+
  (+
   (safe_lshift_func_uint16_t_u_u
    (g_359,
     (l_2586[2] =
      ((safe_unary_minus_func_uint16_t_u
        ((g_922 =
   (+
    (g_902 &
     (((safe_lshift_func_int16_t_s_s
        ((((safe_rshift_func_int16_t_s_u
     (((safe_mod_func_int16_t_s_s
        ((1UL >= (g_359 && g_2599)),
         g_189)) |
       (!(safe_rshift_func_int8_t_s_s
          ((safe_rshift_func_int16_t_s_s
     (g_178, g_209)), 6)))),
      p_67)) >= 0x99D190852898EA8ALL) ^ g_2519),
         10)) != p_67) >=
      g_540[0][0][0])))))) & g_703)))))))) <=
      p_68) | p_67));
 g_1923 = (p_68 & ((-1L) == (-8L)));
 for
   (g_1272
    =
    16;
    (g_1272 == (-4)); g_1272 = safe_sub_func_uint8_t_u_u (g_1272, 1))
   {
     l_2625
       =
       (safe_lshift_func_uint8_t_u_u
        ((safe_rshift_func_int8_t_s_s (l_2624, 7)), 3));
   }
      }



      g_1923 = (p_68 & ((-1L) == (-8L)));


    }
  return g_1395;
}







static int32_t
  func_76 (uint16_t p_77, int8_t p_78, uint32_t p_79, uint32_t p_80)
{
  g_921[5][7][0] = (+g_2227);
  return p_78;
}







static int32_t func_81 (uint16_t p_82, int16_t p_83, int32_t p_84)
{
  int64_t l_827 = (-7L);
  int32_t l_828 = 6L;
  int32_t l_880[4];
  int64_t l_986 = 0x29ECED7B2CEED1E7LL;
  int32_t l_987 = 0xC8FE9740L;
  uint16_t l_1113 = 0x2DC3L;
  int32_t l_1149 = (-1L);
  int32_t l_1323 = (-1L);
  uint32_t l_1325 = 0x137A253DL;
  int32_t l_1586 = 0x5BD1BA55L;
  int32_t l_1725 = 0x5B24C5C6L;
  int32_t l_1735 = 0L;
  uint32_t l_1833 = 4294967295UL;
  uint64_t l_1961 = 0x477546A7C3534B6DLL;
  int32_t l_1971 = 0x6C940B56L;
  int32_t l_2043 = 0x1C6E7B5AL;
  uint16_t l_2124[6][5][5] =
  {
    {
      {
      0x8647L, 0UL, 0xD2FDL, 0x0CA1L, 0x24CAL},
      {
      0xC911L, 0xB8E3L, 65535UL, 1UL, 65535UL},
      {
      0x2494L, 0xC100L, 0x68FFL, 0xB8E3L, 0x68FFL},
      {
      0x49E2L, 0x49E2L, 0x00A5L, 0xD17CL, 1UL},
      {
    3UL, 0x78BCL, 0x49E2L, 0UL, 7UL}},
    {
      {
      0x8647L, 0x031BL, 0x0CA1L, 65532UL, 65535UL},
      {
      0UL, 0x78BCL, 4UL, 65531UL, 0UL},
      {
      0x7E6BL, 0x49E2L, 0x59DAL, 0xB75DL, 0x031BL},
      {
      0x5A7AL, 65527UL, 1UL, 0x68FFL, 0UL},
      {
    1UL, 65535UL, 65531UL, 4UL, 65535UL}},
    {
      {
      0x24CAL, 3UL, 4UL, 65533UL, 1UL},
      {
      0UL, 0xD2FDL, 65530UL, 1UL, 1UL},
      {
      65531UL, 1UL, 0xC100L, 65535UL, 65535UL},
      {
      65531UL, 65535UL, 0UL, 0x00A5L, 0UL},
      {
    0x0CA1L, 0xBB4DL, 9UL, 0x031BL, 0x031BL}},
    {
      {
      0x8568L, 0x7E6BL, 0x8568L, 65532UL, 0UL},
      {
      4UL, 65531UL, 0x2494L, 0xCD24L, 65535UL},
      {
      4UL, 0x8568L, 65535UL, 0x4990L, 7UL},
      {
      0x4990L, 0x834CL, 0x2494L, 65535UL, 1UL},
      {
    0x00A5L, 0x5E4DL, 0x8568L, 1UL, 65531UL}},
    {
      {
      65528UL, 65528UL, 9UL, 0x7E6BL, 4UL},
      {
      4UL, 0UL, 0UL, 0x8568L, 0x6C41L},
      {
      0x5E4DL, 0UL, 0xC100L, 0x5A7AL, 0UL},
      {
      1UL, 0x2494L, 65530UL, 0UL, 0x8568L},
      {
    1UL, 65535UL, 4UL, 1UL, 0x8647L}},
    {
      {
      0x5E4DL, 0UL, 65531UL, 1UL, 0xB75DL},
      {
      4UL, 65533UL, 1UL, 0x92D6L, 0UL},
      {
      65528UL, 0x59DAL, 0x59DAL, 65528UL, 65535UL},
      {
      0x00A5L, 0x4990L, 4UL, 0xBB4DL, 0xB8E3L},
      {
  0x4990L, 9UL, 0x0CA1L, 0x2494L, 3UL}}};
  int i, j, k;
  for (i = 0; i < 4; i++)


    {
      for (i = 0; i < 4; i++)
 l_880[i] = 0xB7A65FD8L;
    }


  if (((g_655 = l_827) || (l_828 = g_806)))
    {
      uint32_t l_867 = 0UL;
      int64_t l_901 = 8L;
      uint64_t l_923 = 18446744073709551615UL;
      int64_t l_960 = 0x5FD7708CD640F182LL;
      int32_t l_961 = 0L;
      uint8_t l_984 = 0UL;
      int32_t l_985[10];
      uint64_t l_1124[2];
      uint16_t l_1184 = 65533UL;
      int i;
      for (i = 0; i < 10; i++)


 {
   for (i = 0; i < 4; i++)
     l_880[i] = 0xB7A65FD8L;
 }


      for (i = 0; i < 10; i++)
 l_985[i] = 4L;





      for (i = 0; i < 4; i++)
 l_880[i] = 0xB7A65FD8L;




      for (i = 0; i < 10; i++)
 l_985[i] = 4L;




      for (i = 0; i < 4; i++)
 l_880[i] = 0xB7A65FD8L;




      for (i = 0; i < 4; i++)
 l_880[i] = 0xB7A65FD8L;


      if ((l_987 =
    (safe_lshift_func_uint16_t_u_s
     ((safe_sub_func_uint16_t_u_u
       ((g_922 =
  (((((l_985[8] =
       (safe_lshift_func_uint8_t_u_u
        ((safe_mul_func_int16_t_s_s
   (l_867,
    (+
     (p_83 &
      ((l_828 =
        (((g_540[0][0][0] =
    (0L |
     (safe_add_func_uint32_t_u_u
      ((safe_add_func_uint16_t_u_u
        ((((g_675 |
     (safe_rshift_func_uint16_t_u_u
      (((0xA0C43BF149A445E5LL |
         ((safe_mul_func_int16_t_s_s
           ((p_83 &
      ((safe_mul_func_int16_t_s_s
        ((((l_961 =
            p_84) & 1UL) <
          ((((((safe_add_func_uint8_t_u_u (((l_880[1] = (0x5978E086L == g_983)) | g_4[1][2]), 1UL)) | p_83) || p_82) | p_82) >= g_983) | p_83)), p_82)) & (-1L))), l_827)) >= g_575)) && 0x26BBB7F2D0050A53LL), l_984))) <= g_280) > 0x5B01CEB8L), p_84)), g_280)))) & 0UL) && g_983)) == g_455))))), l_901))) <= g_189) == l_827) > 0x046E677C2916CF12LL) && l_880[1])), l_986)), l_827))))
 {
   int16_t l_1005 = 0x146FL;
   int32_t l_1006 = 7L;
   int32_t l_1025 = 0xD0852C9AL;
   for (l_986 = (-9); (l_986 != (-20)); --l_986)
     {
       uint8_t l_998 = 251UL;
       int8_t l_1021 = 0xF0L;
       int32_t l_1026 = 0x6CD6C004L;
       uint8_t l_1027 = 0xC1L;






       {
  uint8_t l_998 = 251UL;
  int8_t l_1021 = 0xF0L;
  int32_t l_1026 = 0x6CD6C004L;
  uint8_t l_1027 = 0xC1L;
  for (g_359 = (-20); (g_359 <= 39); g_359++)
    {
      int32_t l_1004 = (-7L);
      int32_t l_1036 = 0xCA360F78L;
      uint32_t l_1107 = 18446744073709551613UL;
      for (l_984 = 0; (l_984 != 20); l_984++)
        {
   uint32_t l_1003[9];
   int i;
   for (i = 0; i < 9; i++)
     l_1003[i] = 4UL;
   p_84
     =
     ((~p_84) &
      ((l_923 > 0x08CBL) >
       ((safe_rshift_func_uint16_t_u_s
         (((safe_add_func_uint8_t_u_u
     ((l_1006 =
       (!((((p_83 ^ l_998) ^
     (safe_add_func_uint64_t_u_u
      (((((safe_lshift_func_uint16_t_u_u
           (((l_1004 =
       ((p_82 <=
         (l_1003[2] =
          0x1DEDL)) | 0xB2B6L)) >=
      l_1005),
            g_209)) != p_82) != g_357) ==
        6UL), g_209)))
           || 0UL) | g_703))), 0L)) < 1L),
          l_1005)) | 255UL)));
        }
      l_828
        =
        ((safe_lshift_func_uint8_t_u_s (0xA0L, 2)) ^
         ((g_455 =
    (safe_mul_func_uint8_t_u_u
     (((safe_sub_func_int64_t_s_s
        (0L,
         (safe_lshift_func_uint8_t_u_u
          (250UL,
    (g_357 =
     ((((g_455 !=
         (safe_mul_func_uint16_t_u_u
          ((((p_84 =
       (((g_178 >
          (safe_sub_func_int64_t_s_s
           ((safe_mod_func_int16_t_s_s
      (l_1021,
       ((g_98 ^
         (safe_unary_minus_func_uint32_t_u
          (((((((safe_lshift_func_uint8_t_u_u (l_1025, (((p_84 < 0xE4EDL) || l_1021) != g_655))) && 0x1E262F35L) <= p_84) != p_82) | p_82) >= g_655)))) || p_82))), l_1026))) != g_236) >= 0xA9DE1A5DL)) && p_82) >= p_83), l_1004))) == 0xA3L) <= 0x5EL) <= l_1027)))))) >= g_540[0][0][1]), 6UL))) && g_902));
      for (l_1027 = 25; (l_1027 >= 52);
    l_1027 = safe_add_func_int64_t_s_s (l_1027, 6))
        {
   int16_t l_1040 = 0x09A3L;
   int32_t l_1041 = 0xFCD6C1EDL;
   int16_t l_1108 = 1L;
   l_1006
     =
     (!
      ((l_1040 =
        (((((p_83 <
      (g_902 >=
       (((safe_sub_func_uint64_t_u_u
          ((safe_sub_func_int64_t_s_s
     ((safe_add_func_uint16_t_u_u
       ((l_1004 =
         65535UL),
        (~
         (((p_82 > ((l_1036 = l_901) ^ 1L))
           &&
           (safe_rshift_func_int8_t_s_u
            ((((safe_unary_minus_func_int32_t_s (l_1025)) >= l_986) == (p_82 <= 0x95A4AABEA3F69DF3LL)), g_97))) <= p_84)))), 9UL)), 0L)) || p_84) & g_4[0][0]))) || l_1027) || g_921[5][7][0]) == 0xFDL) <= p_83)) < l_1041));
   p_84 = (p_82
    && (l_1036 =
        (l_1006 =
         (safe_rshift_func_uint8_t_u_u
          ((((l_987 = l_1026) ^ (l_880[1] =
            (((g_1060 =
        (g_455 =
         (safe_rshift_func_int16_t_s_u
          ((safe_mod_func_uint32_t_u_u ((safe_mod_func_int64_t_s_s (g_703, (safe_mul_func_int16_t_s_s ((p_83 = ((p_84 | 1L) == (safe_sub_func_uint8_t_u_u ((((!(l_880[2] != ((+0xC8L) & (safe_mod_func_uint8_t_u_u ((((safe_mul_func_int16_t_s_s (((((((l_828 = ((g_983 = (safe_rshift_func_int16_t_s_u ((0L != ((p_84 || p_83) > g_575)), 8))) & p_83)) & 0x0A014E370962E30ALL) || 1L) < 0x000B07A7L) & p_83) >= 1UL), g_178)) && 0x37CF9292E2B7606BLL) ^ l_1036), 247UL))))) & p_82) & g_921[4][2][0]), l_998)))), 65531UL)))), g_806)), l_986)))) == p_84) || p_83))) >= 0x58ECDCBC6B9BE738LL), 3)))));
   p_84 =
     (safe_mod_func_uint32_t_u_u
      ((safe_mul_func_int8_t_s_s
        ((safe_mod_func_uint64_t_u_u
          (((safe_mod_func_int64_t_s_s
      (p_84,
       (p_83
        ||
        ((safe_add_func_uint64_t_u_u
          (((g_806 =
      ((l_1040 ^
        (((((safe_mul_func_int8_t_s_s
      ((safe_lshift_func_int8_t_s_s
        (((0xDEL >=
           ((l_1036 =
             (((((safe_rshift_func_uint16_t_u_s (p_82, 12)) | (safe_sub_func_uint32_t_u_u (g_540[0][0][0], l_960))) < (((safe_rshift_func_int16_t_s_u (g_357, 14)) <= 0x64L) ^ g_455)) <= l_1027) < 18446744073709551609UL)) & l_1021)) <= l_1005), 6)), g_1060)) || g_455) >= 0UL) | g_99[2]) >= g_1081[0][0])) || p_84)) != 1UL), p_83)) >= l_901)))) == g_4[1][2]), p_82)), p_83)), l_985[8]));
   g_575 =
     (safe_rshift_func_int8_t_s_u
      ((safe_mod_func_int64_t_s_s
        ((safe_sub_func_uint64_t_u_u
          (((safe_mul_func_uint16_t_u_u
      (l_1021,
       ((safe_sub_func_int64_t_s_s
         ((1L >=
           (safe_lshift_func_int8_t_s_s
     (p_82, 4))),
          ((safe_unary_minus_func_uint16_t_u
     (((g_1081[0][2] <
        (p_82 <=
         ((((0x07L
      &&
      (((safe_mul_func_int8_t_s_s
         ((safe_lshift_func_uint16_t_u_s (((safe_sub_func_uint32_t_u_u ((g_983 = (safe_add_func_int8_t_s_s ((((~((((l_880[1] = (safe_add_func_int8_t_s_s ((l_1040 == (safe_mod_func_uint8_t_u_u (l_1107, ((((((l_1025 | g_575) <= g_1081[0][0]) || g_540[0][0][0]) || p_84) > l_1108) || g_897)))), 0L))) >= l_1004) == g_703) | p_84)) >= l_1021) > g_921[3][4][0]), g_4[1][8]))), 0xCE59244FL)) ^ 1UL), 0)), p_82)) ^ 5UL) && p_82)) <= p_83) > 0x46BBC702L) && l_960))) != 9L))) & 0L))) <= l_1040))) & g_4[1][2]), 0xC8D3F71926B9AAC0LL)), l_923)), 6));
        }
    }
  l_828 = l_1006;
  l_987
    =
    (g_921
     [6]
     [7]
     [0]
     =
     ((safe_lshift_func_int8_t_s_s
       (p_83,
        (((safe_add_func_int64_t_s_s
    (((l_1113 =
       g_921[2][4][0]) ==
      (((safe_mod_func_int32_t_s_s
         ((-1L),
          (safe_lshift_func_uint8_t_u_s (1UL, 4)))) >=
        ((safe_sub_func_int8_t_s_s
          (p_84,
    (0x50CFL !=
     (l_987 <=
      (safe_mod_func_int64_t_s_s
       (l_998,
        (((g_922 =
           ((l_828 =
      (safe_sub_func_uint8_t_u_u
       ((((((l_1006 | 0x93L) !=
            (-1L)) ^ (-1L))
          || (-10L)) < p_84),
        l_1124[0]))) != l_1027)) <
          g_703) & 0xF540L))))))) > 4L))
       || p_82)), p_83)) != l_867) || l_901))) != 1L));
  g_575 =
    ((safe_rshift_func_uint16_t_u_s (l_1027, g_655)) |
     (safe_mod_func_int64_t_s_s
      (((~g_1081[0][5]) ^
        ((0UL ^
   ((((safe_sub_func_uint64_t_u_u
       (4UL,
        (safe_lshift_func_int16_t_s_u
         ((safe_lshift_func_uint8_t_u_u
    (p_83,
     (safe_sub_func_int16_t_s_s
      ((safe_rshift_func_int16_t_s_s
        ((g_209 =
          (l_1026 =
           (safe_sub_func_int32_t_s_s
     ((l_1026 ^
       (safe_add_func_int32_t_s_s
        (p_84,
         (safe_mod_func_uint16_t_u_u
          ((((safe_sub_func_int32_t_s_s
       ((safe_sub_func_uint8_t_u_u
         (p_83, p_84)), l_1149))
      && p_83)
            && p_84), 0x4E90L))))), 8L)))),
         p_82)), g_703)))),
          l_1005)))) | l_1021) & g_359) ^ p_84)) < 1L)),
       0xC3845CFE99179DA8LL)));
       }


       g_575
  =
  ((safe_rshift_func_uint16_t_u_s (l_1027, g_655)) |
   (safe_mod_func_int64_t_s_s
    (((~g_1081[0][5]) ^
      ((0UL ^
        ((((safe_sub_func_uint64_t_u_u
     (4UL,
      (safe_lshift_func_int16_t_s_u
       ((safe_lshift_func_uint8_t_u_u
         (p_83,
          (safe_sub_func_int16_t_s_s
    ((safe_rshift_func_int16_t_s_s
      ((g_209 =
        (l_1026 =
         (safe_sub_func_int32_t_s_s
          ((l_1026 ^
     (safe_add_func_int32_t_s_s
      (p_84,
       (safe_mod_func_uint16_t_u_u
        ((((safe_sub_func_int32_t_s_s
            ((safe_sub_func_uint8_t_u_u
       (p_83, p_84)), l_1149))
           && p_83)
          && p_84), 0x4E90L))))), 8L)))),
       p_82)), g_703)))),
        l_1005)))) | l_1021) & g_359) ^ p_84)) < 1L)),
     0xC3845CFE99179DA8LL)));
     }
   {
     int16_t l_1005 = 0x146FL;
     int32_t l_1006 = 7L;
     int32_t l_1025 = 0xD0852C9AL;
     for (l_986 = (-9); (l_986 != (-20)); --l_986)
       {
  uint8_t l_998 = 251UL;
  int8_t l_1021 = 0xF0L;
  int32_t l_1026 = 0x6CD6C004L;
  uint8_t l_1027 = 0xC1L;
  for (g_359 = (-20); (g_359 <= 39); g_359++)
    {
      int32_t l_1004 = (-7L);
      int32_t l_1036 = 0xCA360F78L;
      uint32_t l_1107 = 18446744073709551613UL;
      for (l_984 = 0; (l_984 != 20); l_984++)
        {
   uint32_t l_1003[9];
   int i;
   for (i = 0; i < 9; i++)
     l_1003[i] = 4UL;
   p_84
     =
     ((~p_84) &
      ((l_923 > 0x08CBL) >
       ((safe_rshift_func_uint16_t_u_s
         (((safe_add_func_uint8_t_u_u
     ((l_1006 =
       (!((((p_83 ^ l_998) ^
     (safe_add_func_uint64_t_u_u
      (((((safe_lshift_func_uint16_t_u_u
           (((l_1004 =
       ((p_82 <=
         (l_1003[2] =
          0x1DEDL)) | 0xB2B6L)) >=
      l_1005),
            g_209)) != p_82) != g_357) ==
        6UL), g_209)))
           || 0UL) | g_703))), 0L)) < 1L),
          l_1005)) | 255UL)));
        }
      l_828
        =
        ((safe_lshift_func_uint8_t_u_s (0xA0L, 2)) ^
         ((g_455 =
    (safe_mul_func_uint8_t_u_u
     (((safe_sub_func_int64_t_s_s
        (0L,
         (safe_lshift_func_uint8_t_u_u
          (250UL,
    (g_357 =
     ((((g_455 !=
         (safe_mul_func_uint16_t_u_u
          ((((p_84 =
       (((g_178 >
          (safe_sub_func_int64_t_s_s
           ((safe_mod_func_int16_t_s_s
      (l_1021,
       ((g_98 ^
         (safe_unary_minus_func_uint32_t_u
          (((((((safe_lshift_func_uint8_t_u_u (l_1025, (((p_84 < 0xE4EDL) || l_1021) != g_655))) && 0x1E262F35L) <= p_84) != p_82) | p_82) >= g_655)))) || p_82))), l_1026))) != g_236) >= 0xA9DE1A5DL)) && p_82) >= p_83), l_1004))) == 0xA3L) <= 0x5EL) <= l_1027)))))) >= g_540[0][0][1]), 6UL))) && g_902));
      for (l_1027 = 25; (l_1027 >= 52);
    l_1027 = safe_add_func_int64_t_s_s (l_1027, 6))
        {
   int16_t l_1040 = 0x09A3L;
   int32_t l_1041 = 0xFCD6C1EDL;
   int16_t l_1108 = 1L;
   l_1006
     =
     (!
      ((l_1040 =
        (((((p_83 <
      (g_902 >=
       (((safe_sub_func_uint64_t_u_u
          ((safe_sub_func_int64_t_s_s
     ((safe_add_func_uint16_t_u_u
       ((l_1004 =
         65535UL),
        (~
         (((p_82 > ((l_1036 = l_901) ^ 1L))
           &&
           (safe_rshift_func_int8_t_s_u
            ((((safe_unary_minus_func_int32_t_s (l_1025)) >= l_986) == (p_82 <= 0x95A4AABEA3F69DF3LL)), g_97))) <= p_84)))), 9UL)), 0L)) || p_84) & g_4[0][0]))) || l_1027) || g_921[5][7][0]) == 0xFDL) <= p_83)) < l_1041));
   p_84 = (p_82
    && (l_1036 =
        (l_1006 =
         (safe_rshift_func_uint8_t_u_u
          ((((l_987 = l_1026) ^ (l_880[1] =
            (((g_1060 =
        (g_455 =
         (safe_rshift_func_int16_t_s_u
          ((safe_mod_func_uint32_t_u_u ((safe_mod_func_int64_t_s_s (g_703, (safe_mul_func_int16_t_s_s ((p_83 = ((p_84 | 1L) == (safe_sub_func_uint8_t_u_u ((((!(l_880[2] != ((+0xC8L) & (safe_mod_func_uint8_t_u_u ((((safe_mul_func_int16_t_s_s (((((((l_828 = ((g_983 = (safe_rshift_func_int16_t_s_u ((0L != ((p_84 || p_83) > g_575)), 8))) & p_83)) & 0x0A014E370962E30ALL) || 1L) < 0x000B07A7L) & p_83) >= 1UL), g_178)) && 0x37CF9292E2B7606BLL) ^ l_1036), 247UL))))) & p_82) & g_921[4][2][0]), l_998)))), 65531UL)))), g_806)), l_986)))) == p_84) || p_83))) >= 0x58ECDCBC6B9BE738LL), 3)))));
   p_84 =
     (safe_mod_func_uint32_t_u_u
      ((safe_mul_func_int8_t_s_s
        ((safe_mod_func_uint64_t_u_u
          (((safe_mod_func_int64_t_s_s
      (p_84,
       (p_83
        ||
        ((safe_add_func_uint64_t_u_u
          (((g_806 =
      ((l_1040 ^
        (((((safe_mul_func_int8_t_s_s
      ((safe_lshift_func_int8_t_s_s
        (((0xDEL >=
           ((l_1036 =
             (((((safe_rshift_func_uint16_t_u_s (p_82, 12)) | (safe_sub_func_uint32_t_u_u (g_540[0][0][0], l_960))) < (((safe_rshift_func_int16_t_s_u (g_357, 14)) <= 0x64L) ^ g_455)) <= l_1027) < 18446744073709551609UL)) & l_1021)) <= l_1005), 6)), g_1060)) || g_455) >= 0UL) | g_99[2]) >= g_1081[0][0])) || p_84)) != 1UL), p_83)) >= l_901)))) == g_4[1][2]), p_82)), p_83)), l_985[8]));
   g_575 =
     (safe_rshift_func_int8_t_s_u
      ((safe_mod_func_int64_t_s_s
        ((safe_sub_func_uint64_t_u_u
          (((safe_mul_func_uint16_t_u_u
      (l_1021,
       ((safe_sub_func_int64_t_s_s
         ((1L >=
           (safe_lshift_func_int8_t_s_s
     (p_82, 4))),
          ((safe_unary_minus_func_uint16_t_u
     (((g_1081[0][2] <
        (p_82 <=
         ((((0x07L
      &&
      (((safe_mul_func_int8_t_s_s
         ((safe_lshift_func_uint16_t_u_s (((safe_sub_func_uint32_t_u_u ((g_983 = (safe_add_func_int8_t_s_s ((((~((((l_880[1] = (safe_add_func_int8_t_s_s ((l_1040 == (safe_mod_func_uint8_t_u_u (l_1107, ((((((l_1025 | g_575) <= g_1081[0][0]) || g_540[0][0][0]) || p_84) > l_1108) || g_897)))), 0L))) >= l_1004) == g_703) | p_84)) >= l_1021) > g_921[3][4][0]), g_4[1][8]))), 0xCE59244FL)) ^ 1UL), 0)), p_82)) ^ 5UL) && p_82)) <= p_83) > 0x46BBC702L) && l_960))) != 9L))) & 0L))) <= l_1040))) & g_4[1][2]), 0xC8D3F71926B9AAC0LL)), l_923)), 6));
        }
    }
  l_828 = l_1006;
  l_987
    =
    (g_921
     [6]
     [7]
     [0]
     =
     ((safe_lshift_func_int8_t_s_s
       (p_83,
        (((safe_add_func_int64_t_s_s
    (((l_1113 =
       g_921[2][4][0]) ==
      (((safe_mod_func_int32_t_s_s
         ((-1L),
          (safe_lshift_func_uint8_t_u_s (1UL, 4)))) >=
        ((safe_sub_func_int8_t_s_s
          (p_84,
    (0x50CFL !=
     (l_987 <=
      (safe_mod_func_int64_t_s_s
       (l_998,
        (((g_922 =
           ((l_828 =
      (safe_sub_func_uint8_t_u_u
       ((((((l_1006 | 0x93L) !=
            (-1L)) ^ (-1L))
          || (-10L)) < p_84),
        l_1124[0]))) != l_1027)) <
          g_703) & 0xF540L))))))) > 4L))
       || p_82)), p_83)) != l_867) || l_901))) != 1L));
  g_575 =
    ((safe_rshift_func_uint16_t_u_s (l_1027, g_655)) |
     (safe_mod_func_int64_t_s_s
      (((~g_1081[0][5]) ^
        ((0UL ^
   ((((safe_sub_func_uint64_t_u_u
       (4UL,
        (safe_lshift_func_int16_t_s_u
         ((safe_lshift_func_uint8_t_u_u
    (p_83,
     (safe_sub_func_int16_t_s_s
      ((safe_rshift_func_int16_t_s_s
        ((g_209 =
          (l_1026 =
           (safe_sub_func_int32_t_s_s
     ((l_1026 ^
       (safe_add_func_int32_t_s_s
        (p_84,
         (safe_mod_func_uint16_t_u_u
          ((((safe_sub_func_int32_t_s_s
       ((safe_sub_func_uint8_t_u_u
         (p_83, p_84)), l_1149))
      && p_83)
            && p_84), 0x4E90L))))), 8L)))),
         p_82)), g_703)))),
          l_1005)))) | l_1021) & g_359) ^ p_84)) < 1L)),
       0xC3845CFE99179DA8LL)));
       }
   }



 }
      else
 {
   int16_t l_1162 = 9L;
   int32_t l_1181 = 0x047C4F7FL;
   uint32_t l_1183[5] =
   {
   0UL, 0UL, 0UL, 0UL, 0UL};
   int i;
   l_1184
     =
     ((l_1181 =
       (((safe_lshift_func_int16_t_s_u
   ((safe_mod_func_uint64_t_u_u
     ((safe_rshift_func_int8_t_s_u
       ((safe_mul_func_int8_t_s_s
         ((((g_208[2] ==
      ((((((((p_83 =
       (safe_mul_func_uint16_t_u_u
        ((safe_mul_func_uint16_t_u_u
          (((l_1162 = 0xDA926A1CL) < (l_987 =
          (g_1182[2] =
           (safe_mod_func_uint16_t_u_u
            (0xB370L,
             (safe_sub_func_int32_t_s_s
              ((p_84 =
         g_675),
               (safe_add_func_uint64_t_u_u
         (((safe_rshift_func_uint8_t_u_s (p_82, ((safe_add_func_uint32_t_u_u (0xD460FB0DL, (safe_lshift_func_int16_t_s_s (0x487BL, 13)))) >= (safe_mul_func_int16_t_s_s (((g_983 = 0x207A0B8BL) ^ (safe_rshift_func_uint16_t_u_s ((!((safe_add_func_int64_t_s_s (l_1124[0], l_984)) | 0x18L)), 14))), l_867))))) || p_82), l_1181))))))))), g_357)), p_82))) == g_178) >= l_984) >= p_82) && (-8L)) > g_575) == l_985[8]) | p_82)) & l_1183[0]) & g_189), 0x4DL)), 7)), 0x305C09DB65BDC258LL)), l_827)) & l_961) & l_985[7])) ^ p_82);
 lbl_1189:
   for (g_359 = 0; (g_359 <= 4); g_359 += 1)
     {
       g_921
  [5]
  [8]
  [0]
  =
  (safe_lshift_func_int8_t_s_s
   (g_921[2][0][0], (0x5A91L | p_82)));
       return g_897;
     }
   for (g_280 = 23; (g_280 < 52); g_280++)
     {
       if (g_357)
  goto lbl_1189;
       l_828 = 9L;



     }
 }
    }
  else
    {
      int64_t l_1196 = 0x4916963200CF7D4ALL;
      int32_t l_1204 = 8L;
      g_921
 [4]
 [1]
 [0]
 =
 (((0xF940L
    && (l_828 =
        ((safe_rshift_func_int16_t_s_u (g_897, 8)) != 0xF339L))) <
   l_1113)
  || (l_1204 =
      (safe_rshift_func_int16_t_s_u
       (g_921[3][9][0],
        (safe_rshift_func_uint8_t_u_s
  ((g_1060 =
    0x1AL),
   (l_1196 >=
    (safe_add_func_uint8_t_u_u
     (((safe_add_func_int64_t_s_s
        ((0x53L <
   (safe_unary_minus_func_int32_t_s
    ((safe_sub_func_int32_t_s_s (4L, g_455))))),
         0xB8F9271DD0F253FCLL)) >= 0x71B0AD7BL),
      g_208[0])))))))));
      for (g_1060 = 0; g_1060 < 1; g_1060 += 1)
 {


   for (i = 0; i < 4; i++)
     l_880[i] = 0xB7A65FD8L;


 }
      for (i = 0; i < 4; i++)
 l_880[i] = 0xB7A65FD8L;



    }
  for (i = 0; i < 4; i++)
    l_880[i] = 0xB7A65FD8L;



  if (p_83)
    {
      int32_t l_1228[10][8] =
      {
 {
 1L,
     0x796F276DL,
     0x796F276DL, 1L, 0x585D394AL, 1L, 0x796F276DL, 0x796F276DL}
 ,
 {
 0x796F276DL, 0x585D394AL, 0L, 0L, 0xFFE73D59L, 1L, 0xFFE73D59L,
     0x585D394AL}
 ,
 {
 0L, 0xFFE73D59L, 0L, 1L, 1L, 0L, 0xFFE73D59L, 0L}
 ,
 {
 0x796F276DL, 1L, 0x585D394AL, 1L, 0x796F276DL, 0x796F276DL, 1L,
     0x585D394AL}
 ,
 {
 0x796F276DL, 0x796F276DL, 1L, 0x585D394AL, 1L, 0x796F276DL,
     0x796F276DL, 1L}
 ,
 {
 0L, 1L, 1L, 0L, 0xFFE73D59L, 0L, 1L, 1L}
 ,
 {
 1L, 0xFFE73D59L, 0x585D394AL, 0x585D394AL, 0xFFE73D59L, 1L,
     0xFFE73D59L, 0x585D394AL}
 ,
 {
 0L, 0xFFE73D59L, 0L, 1L, 1L, 0L, 0xFFE73D59L, 0L}
 ,
 {
 0x796F276DL, 1L, 0x585D394AL, 1L, 0x796F276DL, 0x796F276DL, 1L,
     0x585D394AL}
 ,
 {
 0x796F276DL, 0x796F276DL, 1L, 0x585D394AL, 1L, 0x796F276DL,
     0x796F276DL, 1L}
      };
      int32_t l_1233 = 0x9DB5957AL;
      uint16_t l_1313 = 5UL;
      int32_t l_1453 = 0xA6EAE12DL;
      int64_t l_1780 = 0xC2136000B633248FLL;
      uint8_t l_1854 = 0x3CL;
      uint8_t l_1906[2][3][8] =
      {
 {
   {
   0UL, 1UL, 0xEDL, 1UL, 0UL, 1UL, 0xEDL, 1UL}
   ,
   {
   0UL, 1UL, 0xEDL, 1UL, 0UL, 1UL, 0xEDL, 1UL}
   ,
   {
   0UL, 1UL, 0xEDL, 1UL, 0UL, 1UL, 0xEDL, 1UL}
 }
 ,
 {
   {
   0UL, 1UL, 0xEDL, 1UL, 0UL, 1UL, 0xEDL, 1UL}
   ,
   {
   0UL, 1UL, 0xEDL, 1UL, 0UL, 1UL, 0xEDL, 1UL}
   ,
   {
   0UL, 1UL, 0xEDL, 1UL, 0UL, 1UL, 0xEDL, 1UL}
 }
      };
      int32_t l_2024[10][7][3] =
      {
 {
   {
   (-9L), 3L, 1L}
   ,
   {
   0xC29A41ABL, (-3L), 0x3B8DA1CAL}
   ,
   {
   0L, 3L, (-1L)}
   ,
   {
   0xC29A41ABL, 0x369273ACL, 0xB130F6F0L}
   ,
   {
   (-9L), 0xF5B82778L, 0x1C7FF1FFL}
   ,
   {
   0xA5028F61L, (-5L), 0x369273ACL}
   ,
   {
   2L, 0xE95D3933L, (-1L)}
 }
 ,
 {
   {
   (-1L), (-1L), 0xEECF12F8L}
   ,
   {
   1L, 0xE95D3933L, 1L}
   ,
   {
   (-5L), (-5L), 0L}
   ,
   {
   0L, 0xF5B82778L, 2L}
   ,
   {
   (-3L), 0x369273ACL, 0xB70A5A4DL}
   ,
   {
   1L, 3L, 0x1C7FF1FFL}
   ,
   {
   0xCD9DE5C5L, (-3L), 0xB70A5A4DL}
 }
 ,
 {
   {
   2L, 3L, 2L}
   ,
   {
   0x3B8FC9D6L, (-1L), 0L}
   ,
   {
   (-9L), 8L, 1L}
   ,
   {
   0x71E2B383L, (-3L), 0xEECF12F8L}
   ,
   {
   0L, 0x360341C3L, (-1L)}
   ,
   {
   0x71E2B383L, 0x369273ACL, 0x369273ACL}
   ,
   {
   (-9L), 0x561FBEEFL, 0x1C7FF1FFL}
 }
 ,
 {
   {
   0x3B8FC9D6L, (-5L), 0xB130F6F0L}
   ,
   {
   2L, 0xD682C71AL, (-1L)}
   ,
   {
   0xCD9DE5C5L, (-1L), 0x3B8DA1CAL}
   ,
   {
   1L, 0xD682C71AL, 1L}
   ,
   {
   (-3L), (-5L), 8L}
   ,
   {
   0L, 0x561FBEEFL, 2L}
   ,
   {
   (-5L), 0x369273ACL, (-1L)}
 }
 ,
 {
   {
   1L, 0x360341C3L, 0x1C7FF1FFL}
   ,
   {
   (-1L), (-3L), (-1L)}
   ,
   {
   2L, 8L, 2L}
   ,
   {
   0xA5028F61L, (-1L), 8L}
   ,
   {
   (-9L), 3L, 1L}
   ,
   {
   0xC29A41ABL, (-3L), 0x3B8DA1CAL}
   ,
   {
   0L, 3L, (-1L)}
 }
 ,
 {
   {
   0xC29A41ABL, 0x369273ACL, 0xB130F6F0L}
   ,
   {
   (-9L), 0xF5B82778L, 0x1C7FF1FFL}
   ,
   {
   0xA5028F61L, (-5L), 0x369273ACL}
   ,
   {
   2L, 0xE95D3933L, (-1L)}
   ,
   {
   (-1L), (-1L), 0xEECF12F8L}
   ,
   {
   1L, 0xE95D3933L, 1L}
   ,
   {
   (-5L), (-5L), 0L}
 }
 ,
 {
   {
   0L, 0xF5B82778L, 2L}
   ,
   {
   (-3L), 0x369273ACL, 0xB70A5A4DL}
   ,
   {
   1L, 3L, 0x1C7FF1FFL}
   ,
   {
   0xCD9DE5C5L, (-3L), 0xB70A5A4DL}
   ,
   {
   2L, 3L, 2L}
   ,
   {
   0x3B8FC9D6L, (-1L), 0L}
   ,
   {
   (-9L), 8L, 1L}
 }
 ,
 {
   {
   0x71E2B383L, (-3L), 0xEECF12F8L}
   ,
   {
   0L, 0x360341C3L, (-1L)}
   ,
   {
   0x71E2B383L, 0x369273ACL, 0x369273ACL}
   ,
   {
   (-9L), 0x561FBEEFL, 0x1C7FF1FFL}
   ,
   {
   0x3B8FC9D6L, (-5L), 0xB130F6F0L}
   ,
   {
   2L, 0xD682C71AL, (-1L)}
   ,
   {
   0xCD9DE5C5L, (-1L), 0x3B8DA1CAL}
 }
 ,
 {
   {
   1L, 0xD682C71AL, 1L}
   ,
   {
   (-3L), (-5L), 8L}
   ,
   {
   0L, 0x561FBEEFL, 2L}
   ,
   {
   (-5L), 0x369273ACL, (-1L)}
   ,
   {
   1L, 0x360341C3L, 0x1C7FF1FFL}
   ,
   {
   (-1L), (-3L), (-1L)}
   ,
   {
   2L, 8L, 2L}
 }
 ,
 {
   {
   0xA5028F61L, (-1L), 8L}
   ,
   {
   (-9L), 3L, 1L}
   ,
   {
   0xC29A41ABL, (-3L), 0x3B8DA1CAL}
   ,
   {
   0L, 3L, (-1L)}
   ,
   {
   0xC29A41ABL, 0x369273ACL, 0xB130F6F0L}
   ,
   {
   (-9L), 0xF5B82778L, 0x1C7FF1FFL}
   ,
   {
   0xA5028F61L, (-5L), 0x369273ACL}
 }
      };
      int8_t l_2042 = 1L;
      int i, j, k;
      l_987 = (p_83 || (!(safe_unary_minus_func_int8_t_s (g_675))));
    lbl_2023:
      if (((safe_sub_func_int16_t_s_s
     ((((((((g_1060 =
      (p_84 ^
       (safe_mul_func_uint16_t_u_u
        (((g_4[1][2]
    || (g_455 =
        (safe_add_func_uint32_t_u_u
         ((l_880[1] =
    (0x66CDL
     && ((l_828 = g_540[0][0][0])
         &&
         (safe_add_func_int32_t_s_s
          (((safe_rshift_func_uint8_t_u_u
      (p_84,
       0)) <=
     (((safe_sub_func_int32_t_s_s
        (((safe_mul_func_int8_t_s_s
           (p_82,
            (0x7F6553DD6FAD4D34LL ^
      l_828))) < ((g_178 < g_675) <
           0xE6L)),
         p_83)) > l_986) | g_357)),
           p_82))))), 1L)))) & p_83),
         0x3A21L)))) > p_84) < p_83) & l_986) <=
  18446744073709551613UL) == g_675) == p_83),
      0L)) ^ 0x231450B0L))
 {
   uint32_t l_1248 = 0x2FC0B341L;
   int32_t l_1249 = 0xE57EFF83L;
   int32_t l_1256 = (-9L);
   uint8_t l_1284[1];
   uint32_t l_1285 = 0x88A528B5L;
   int16_t l_1312 = 1L;
   int i;
   for (i = 0; i < 1; i++)
     l_1284[i] = 1UL;
   l_1233
     =
     (safe_sub_func_uint32_t_u_u
      (((safe_sub_func_int64_t_s_s
  ((safe_mod_func_int32_t_s_s (p_84, (-1L))),
   ((safe_lshift_func_uint8_t_u_s (p_84, g_1182[1])) |
    0x2AF895A7L))) < l_1228[2][3]),
       (!(((safe_add_func_int8_t_s_s
     ((safe_lshift_func_uint8_t_u_u (p_83, 5)),
      254UL)) & g_98) ^ 0x10L))));
   for (g_209 = (-22); (g_209 != (-23));
        g_209 = safe_sub_func_uint64_t_u_u (g_209, 9))
     {
       uint16_t l_1253 = 65535UL;
       for (g_98 = 3; (g_98 >= 0); g_98 -= 1)
  {
    uint32_t l_1250 = 0xA8258719L;
    for (g_455 = 0; (g_455 <= 3); g_455 += 1)
      {
        int i;
        l_880
   [g_98]
   =
   (safe_lshift_func_uint8_t_u_u
    ((((safe_add_func_int64_t_s_s
        ((safe_add_func_int32_t_s_s
          ((safe_add_func_uint16_t_u_u
     (((g_921[5][7][0]
        ||
        (safe_mul_func_uint8_t_u_u
         ((p_84 ==
           ((safe_add_func_uint64_t_u_u
      (l_1248,
       (0xB628AF255C83099ALL !=
        (l_1249 =
         l_1228[2][3])))) <= (0L ==
         ((((g_97 !=
             (l_1250 ^
              (safe_mod_func_int16_t_s_s
               (g_189,
         l_1253))))
            <= g_236)
           &&
           0x7C81712DL)
          == p_84)))),
          (-1L)))) | l_1250), 0x6169L)),
    0xC0ADFAE2L)), (-1L)))
       && 0x9EF012ABE104346BLL) | p_84), g_280));
      }
  }
       g_921
  [5]
  [7]
  [0]
  =
  ((safe_mul_func_int8_t_s_s
    ((l_1256 > (g_540[0][0][8] == (+p_82))),
     ((safe_unary_minus_func_uint64_t_u ((7UL < l_1228[2][3])))
      >=
      (((+
         ((6L &
    ((g_1272 =
      ((safe_sub_func_int64_t_s_s
        ((p_82 |
          (safe_rshift_func_int16_t_s_s
    ((safe_lshift_func_int8_t_s_s
      ((safe_sub_func_int8_t_s_s
        ((((safe_lshift_func_int8_t_s_s
     ((((g_455 =
         (l_1233 =
          g_4[0][3])) >
        ((((safe_mul_func_int16_t_s_s
            (((((g_575 =
          (l_1256 > 0x2488L)) >=
         0xE941BDABL) <= g_806) >
       g_189),
      g_921[6][6][0])) >=
           l_987) | g_1182[1]) >
         g_189)) & g_540[0][0][2]),
      5)) | 0x4368L) < l_1228[4][6]),
         0xF3L)), g_4[0][0])), 15))),
         18446744073709551615UL)) < l_1253))
     && l_987)) ^ g_357)) > g_922) >= g_208[2])))) >=
   g_98);
       g_921[5][7][0] = l_1253;
     }
   l_987 = ((p_84 < 3UL) || (safe_lshift_func_uint16_t_u_s (0UL, 12)));
   for (l_1256 = 0; (l_1256 >= 0); l_1256 -= 1)
     {
       for (l_1113 = 0; (l_1113 <= 0); l_1113 += 1)
  {
    uint32_t l_1286 = 0xB60F968FL;
    uint32_t l_1310 = 0UL;
    int i;
    l_1233 = g_99[(l_1256 + 3)];
    if ((((((p_82 =
      65529UL) !=
     ((safe_unary_minus_func_int8_t_s ((1L ^ 0UL))) !=
      ((safe_mul_func_int16_t_s_s
        ((+(p_84 >= g_236)),
         (((((p_83 =
       (safe_sub_func_uint8_t_u_u
        (p_84,
         ((g_1182[2] =
           (g_99[2]
     &&
     (safe_mod_func_uint8_t_u_u
      (g_99[(l_1256 + 3)],
       (+
        ((18446744073709551610UL | l_1248)
         > l_1233)))))) | l_987)))) >
      p_84) & 18446744073709551610UL) <=
    1UL) & p_84))) == p_84))) | 0xC2L) !=
   p_84) | l_1284[0]))
      {
        uint16_t l_1291 = 1UL;
        int32_t l_1311 = 1L;
        l_1285 = ((!(-8L)) == (l_1284[0] || l_1228[2][5]));
        p_84 = p_83;
        l_1286 = p_84;
        g_575
   =
   (g_921
    [5]
    [7]
    [0]
    =
    (safe_lshift_func_uint16_t_u_u
     ((((+g_359) !=
        ((!((safe_lshift_func_uint16_t_u_u
      (l_1291,
       (safe_mul_func_uint8_t_u_u
        ((safe_rshift_func_int8_t_s_s
          ((safe_mod_func_uint64_t_u_u
     ((safe_mod_func_int32_t_s_s
       ((safe_mul_func_uint8_t_u_u
         ((safe_rshift_func_int8_t_s_u
           ((p_83 >=
      (l_1311 =
       ((g_897 >=
         (safe_sub_func_uint32_t_u_u
          (4294967295UL,
           (((safe_rshift_func_uint8_t_u_u (l_1233, 6)) <= ((safe_sub_func_int64_t_s_s (g_208[1], (l_1310 = ((l_987 = p_83) ^ (g_1182[2] = (g_209 = ((((g_922 = 1UL) <= g_1081[0][7]) && 2L) > p_84))))))) < l_1113)) & 1UL)))) ^ g_178))), 5)), 0x4DL)), l_1312)), 0x044A86113D2427FALL)), g_359)), 255UL)))) && p_82)) >= l_1256)) >= l_1284[0]), l_880[1])));
      }
    else
      {
        g_921[2][2][0] = p_83;
        p_84 = 0x581CE7A0L;
        return g_1081[0][4];
      }
    g_921[6][1][0] = (g_455 && g_902);
    for (l_1249 = 0; (l_1249 >= 0); l_1249 -= 1)
      {
        int i, j, k;
        g_921[(l_1256 + 4)][(l_1256 + 8)][l_1249] = 7L;
      }
  }
     }
 }
      else
 {
   uint8_t l_1322 = 0x2BL;
   int32_t l_1328 = 0xE4119F90L;
   int32_t l_1354 = 0x35965C99L;
   uint32_t l_1567 = 0xBF120175L;
   uint32_t l_1666 = 4UL;
   l_1313 = p_83;
   p_84 = l_987;
   if ((g_1272 != (p_83 = 1L)))
     {
       uint64_t l_1324 = 0xF7EFE41B577EFF9FLL;
       uint8_t l_1522 = 0x38L;
       int32_t l_1566 = 0xF62D4426L;
       int32_t l_1585 = 0x92EAFE06L;
       uint32_t l_1632 = 0xC6B63528L;
     lbl_1634:
       if ((((((((safe_rshift_func_uint16_t_u_s
    ((safe_mul_func_int16_t_s_s
      ((safe_mul_func_int16_t_s_s
        ((g_1182[1] =
          g_1182[0]),
         (safe_add_func_uint32_t_u_u
          ((0x43A7935184CA0C26LL == (-1L)), l_1322)))),
       ((g_1060 >
         (0x9CL ^ (g_806 == 0x6DA792DFF20239F3LL))) ==
        l_1323))), g_178)) > l_1228[7][1]) & l_1113)
        || p_84) ^ 0xC861EC58L) | g_178) >= 0x9E64C8AFL))
  {
    int16_t l_1351 = 0x4B2DL;
    l_1325 = l_1324;
    l_1233
      =
      (p_84
       =
       (((safe_mod_func_int32_t_s_s
   ((l_1328 =
     l_1324),
    (18446744073709551615UL ^
     ((0UL >=
       (p_82 !=
        ((((l_1354 =
     ((safe_add_func_int16_t_s_s
       ((safe_rshift_func_int16_t_s_u
         ((safe_mod_func_int8_t_s_s
           (0xACL,
     (p_84
      ||
      (safe_sub_func_uint64_t_u_u
       ((safe_mod_func_uint64_t_u_u
         ((safe_rshift_func_int8_t_s_u
           (((safe_sub_func_uint32_t_u_u
       (((safe_sub_func_uint64_t_u_u
          ((l_880[0] =
            (safe_lshift_func_uint8_t_u_u
             ((safe_mul_func_int16_t_s_s (((p_83 = (((safe_lshift_func_int8_t_s_u ((l_1351 = 1L), p_82)) | ((((safe_add_func_int32_t_s_s (0xFD118E34L, (-7L))) == g_897) | g_1272) <= p_84)) > 0x31FAE6F7L)) || l_1324), 65535UL)), 5))), (-1L))) && 2UL), 0xEE284F24L)) & l_1228[0][6]), 3)), 0x086968330A709463LL)), g_540[0][0][0]))))), 13)), p_84)) <= 0x9B60L)) || l_1354) != g_1081[0][0]) == g_922))) < 8L)))) > l_827) <= p_82));
    g_208[0] =
      ((l_1324 !=
        (safe_add_func_uint16_t_u_u
         (0x0CD0L,
   (safe_unary_minus_func_int16_t_s
    ((safe_sub_func_int16_t_s_s
      ((safe_rshift_func_uint16_t_u_s
        ((g_178 =
          (safe_rshift_func_int16_t_s_s (g_359, 12))),
         (((g_236 =
     (safe_lshift_func_uint8_t_u_u (p_83, 0))) <
    (safe_add_func_int16_t_s_s
     (((safe_rshift_func_uint8_t_u_u
        ((safe_rshift_func_uint16_t_u_s
          ((safe_rshift_func_int16_t_s_s
     (l_1322, 9)), (p_82
             || 255UL))),
         2)) < ((safe_mul_func_int8_t_s_s (p_83,
               p_83))
         > l_1324)), p_84))) != l_1325))),
       1L))))))) >= p_83);
  }
       else
  {
    uint16_t l_1413 = 0x2F7DL;
    uint64_t l_1456[3][7] =
    {
      {
      1UL,
   18446744073709551615UL,
   1UL,
   18446744073709551615UL,
   1UL, 18446744073709551615UL, 1UL}
      ,
      {
      0x6E61CF0A9CFA961ALL, 18446744073709551612UL,
   18446744073709551612UL, 0x6E61CF0A9CFA961ALL,
   0x6E61CF0A9CFA961ALL, 18446744073709551612UL,
   18446744073709551612UL}
      ,
      {
      18446744073709551611UL, 18446744073709551615UL,
   18446744073709551611UL, 18446744073709551615UL,
   18446744073709551611UL, 18446744073709551615UL,
   18446744073709551611UL}
    };
    int32_t l_1486[8][8][4] =
    {
      {
        {
        0xFB5F544CL, 0x4A3D6AA1L, (-1L), 1L}
        ,
        {
        0x4A3D6AA1L, 0L, 0x1D84D87CL, 0xF37F93CAL}
        ,
        {
        1L, 0xFB5F544CL, 8L, 0x1D84D87CL}
        ,
        {
        0x86CE6646L, 4L, (-10L), 1L}
        ,
        {
        0x86CE6646L, 0x29A9A138L, 8L, 2L}
        ,
        {
        1L, 0x4A3D6AA1L, 0x1D84D87CL, 8L}
        ,
        {
        0x4A3D6AA1L, 4L, (-1L), 0xF37F93CAL}
        ,
        {
        0xFB5F544CL, 1L, 8L, 0xF37F93CAL}
      }
      ,
      {
        {
        (-1L), 4L, (-1L), (-10L)}
        ,
        {
        0xB0144AA9L, (-1L), 2L, 0x1D84D87CL}
        ,
        {
        0x29A9A138L, 0x86FAB091L, 0x627C2CA8L, 0x5CD801A0L}
        ,
        {
        0x86FAB091L, 1L, 0x627C2CA8L, 0x627C2CA8L}
        ,
        {
        0x29A9A138L, 0x29A9A138L, 2L, (-8L)}
        ,
        {
        0xB0144AA9L, 0x79E17F82L, (-1L), 0x5CD801A0L}
        ,
        {
        (-9L), (-1L), (-10L), (-1L)}
        ,
        {
        0x29A9A138L, (-1L), 0x5B532775L, 0x5CD801A0L}
      }
      ,
      {
        {
        (-1L), 0x79E17F82L, 0x627C2CA8L, (-8L)}
        ,
        {
        (-2L), 0x29A9A138L, (-10L), 0x627C2CA8L}
        ,
        {
        0xB0144AA9L, 1L, 0xF37F93CAL, 0x5CD801A0L}
        ,
        {
        0xB0144AA9L, 0x86FAB091L, (-10L), 0x1D84D87CL}
        ,
        {
        (-2L), (-1L), 0x627C2CA8L, (-10L)}
        ,
        {
        (-1L), 1L, 0x5B532775L, (-8L)}
        ,
        {
        0x29A9A138L, (-2L), (-10L), (-8L)}
        ,
        {
        (-9L), 1L, (-1L), (-10L)}
      }
      ,
      {
        {
        0xB0144AA9L, (-1L), 2L, 0x1D84D87CL}
        ,
        {
        0x29A9A138L, 0x86FAB091L, 0x627C2CA8L, 0x5CD801A0L}
        ,
        {
        0x86FAB091L, 1L, 0x627C2CA8L, 0x627C2CA8L}
        ,
        {
        0x29A9A138L, 0x29A9A138L, 2L, (-8L)}
        ,
        {
        0xB0144AA9L, 0x79E17F82L, (-1L), 0x5CD801A0L}
        ,
        {
        (-9L), (-1L), (-10L), (-1L)}
        ,
        {
        0x29A9A138L, (-1L), 0x5B532775L, 0x5CD801A0L}
        ,
        {
        (-1L), 0x79E17F82L, 0x627C2CA8L, (-8L)}
      }
      ,
      {
        {
        (-2L), 0x29A9A138L, (-10L), 0x627C2CA8L}
        ,
        {
        0xB0144AA9L, 1L, 0xF37F93CAL, 0x5CD801A0L}
        ,
        {
        0xB0144AA9L, 0x86FAB091L, (-10L), 0x1D84D87CL}
        ,
        {
        (-2L), (-1L), 0x627C2CA8L, (-10L)}
        ,
        {
        (-1L), 1L, 0x5B532775L, (-8L)}
        ,
        {
        0x29A9A138L, (-2L), (-10L), (-8L)}
        ,
        {
        (-9L), 1L, (-1L), (-10L)}
        ,
        {
        0xB0144AA9L, (-1L), 2L, 0x1D84D87CL}
      }
      ,
      {
        {
        0x29A9A138L, 0x86FAB091L, 0x627C2CA8L, 0x5CD801A0L}
        ,
        {
        0x86FAB091L, 1L, 0x627C2CA8L, 0x627C2CA8L}
        ,
        {
        0x29A9A138L, 0x29A9A138L, 2L, (-8L)}
        ,
        {
        0xB0144AA9L, 0x79E17F82L, (-1L), 0x5CD801A0L}
        ,
        {
        (-9L), (-1L), (-10L), (-1L)}
        ,
        {
        0x29A9A138L, (-1L), 0x5B532775L, 0x5CD801A0L}
        ,
        {
        (-1L), 0x79E17F82L, 0x627C2CA8L, (-8L)}
        ,
        {
        (-2L), 0x29A9A138L, (-10L), 0x627C2CA8L}
      }
      ,
      {
        {
        0xB0144AA9L, 1L, 0xF37F93CAL, 0x5CD801A0L}
        ,
        {
        0xB0144AA9L, 0x86FAB091L, (-10L), 0x1D84D87CL}
        ,
        {
        (-2L), (-1L), 0x627C2CA8L, (-10L)}
        ,
        {
        (-1L), 1L, 0x5B532775L, (-8L)}
        ,
        {
        0x29A9A138L, (-2L), (-10L), (-8L)}
        ,
        {
        (-9L), 1L, (-1L), (-10L)}
        ,
        {
        0xB0144AA9L, (-1L), 2L, 0x1D84D87CL}
        ,
        {
        0x29A9A138L, 0x86FAB091L, 0x627C2CA8L, 0x5CD801A0L}
      }
      ,
      {
        {
        0x86FAB091L, (-2L), 0L, 0L}
        ,
        {
        0x86FAB091L, 0x86FAB091L, 0x1D84D87CL, 0xA8CFD2DEL}
        ,
        {
        7L, 0x4A3D6AA1L, 0x5B532775L, (-1L)}
        ,
        {
        4L, (-9L), 0xF37F93CAL, 0x5B532775L}
        ,
        {
        0x86FAB091L, (-9L), (-6L), (-1L)}
        ,
        {
        (-9L), 0x4A3D6AA1L, 0L, 0xA8CFD2DEL}
        ,
        {
        0x86CE6646L, 0x86FAB091L, 0xF37F93CAL, 0L}
        ,
        {
        7L, (-2L), (-8L), (-1L)}
      }
    };
    uint32_t l_1514 = 1UL;
    int i, j, k;
    for
      (l_1325
       =
       26;
       (l_1325
        > 6); l_1325 = safe_sub_func_uint32_t_u_u (l_1325, 2))
      {
        g_575
   =
   ((0x27C1L ^ p_82) <=
    ((l_1233 = 0x4DA5E7E3F3D57E04LL) && p_82));
      }
    if (((safe_sub_func_int64_t_s_s
   (((safe_mod_func_int64_t_s_s
      ((safe_sub_func_int32_t_s_s
        ((1L !=
          ((g_983 > g_99[1]) >= 18446744073709551609UL)),
         ((safe_sub_func_int16_t_s_s
    (((!((g_1395 =
          ((safe_add_func_int32_t_s_s
     (g_921[5][8][0],
      ((g_1394 =
        (safe_sub_func_int32_t_s_s
         ((p_84 =
           (safe_sub_func_int32_t_s_s
            (g_209,
      (2L != (p_82 = l_880[1]))))),
          (0x2505C3F9L < 7L)))) >=
       g_4[1][2]))) | l_880[1])) >
         g_208[0])) | p_83),
     g_208[1])) > 0xFD4F772AE241B758LL))),
       l_1324)) & g_806), p_83)) == l_1322))
      {
        g_921[5][7][0] = (0xBB7FL & g_1394);
        g_208
   [2]
   =
   (p_84
    &&
    (safe_mod_func_uint64_t_u_u
     (((((safe_rshift_func_int8_t_s_u
          (g_806,
    (g_236 ^ g_1272))) >
         (0UL |
          (safe_lshift_func_int16_t_s_s
    ((safe_mul_func_uint16_t_u_u
      (g_1182[1], p_83)),
     13)))) ==
        (safe_rshift_func_int8_t_s_u ((-1L), 4))) ==
       (safe_rshift_func_int16_t_s_s
        ((safe_mul_func_uint16_t_u_u
          (((safe_mod_func_int32_t_s_s
      ((safe_unary_minus_func_int16_t_s
        (l_1228[2][3])), p_83)) | l_1413),
    (-1L))), p_84))), 1L)));
      }
    else
      {
        return g_1081[0][3];
      }
    if ((g_575 =
         (safe_mul_func_int16_t_s_s
   ((safe_add_func_int32_t_s_s
     (((safe_add_func_uint64_t_u_u
        ((l_880[1] =
          ((((p_83 =
       (safe_unary_minus_func_int32_t_s (l_1324)))
      >= g_922) !=
     (((safe_mul_func_uint8_t_u_u
        (0x33L,
         ((safe_rshift_func_uint16_t_u_u
           ((safe_lshift_func_uint16_t_u_u
      ((g_178 =
        (safe_rshift_func_int16_t_s_u
         (((((safe_mod_func_int16_t_s_s
       ((((0x566DL
           ||
           ((g_983
             &&
             ((((0x4818L ^ g_208[2])
         != (l_1233 =
             (l_1328 &
              0x30D39E325FA5BCD2LL)))
        >= 1UL)
       && g_357)) <=
            p_84)) ^ l_1413) <=
         l_1324),
        l_1322)) | g_675) >
            0x9FL) == p_84), 9))), 8)),
     13)) ^ 4294967292UL))) != 5UL) >
      p_84)) < g_236)), p_82)) > p_82), p_82)),
    p_82))))
      {
        return p_83;
      }
    else
      {
        int64_t l_1435 = 0x1601124BB857B320LL;
        int32_t l_1440 = 6L;
        l_880
   [1]
   =
   (p_84
    =
    (safe_lshift_func_uint16_t_u_s
     ((g_178 =
       ((g_236 &
         (safe_add_func_uint16_t_u_u
          ((~
     ((l_1435 ^
       (safe_lshift_func_uint8_t_u_s
        ((p_84 &
          (safe_mod_func_uint8_t_u_u
           ((l_1440 =
      p_84), 0xE5L))),
         ((safe_mul_func_int16_t_s_s
           (g_675,
     ((g_189 |
       (((safe_add_func_uint8_t_u_u
          (g_902,
           g_540[0][0][5])) ^ g_1182[2])
        && 0xC0CED316L)) != p_84))) <
          g_208[1])))) & 1L)),
    p_84))) | g_1182[2])), 6)));
        p_84 =
   ((safe_sub_func_int8_t_s_s
     (((safe_sub_func_uint32_t_u_u
        ((0xC251L >
          (l_1440 =
    (safe_add_func_uint32_t_u_u
     (0x0423536CL, l_1354)))),
         (safe_add_func_int32_t_s_s
          (((g_178 = l_1453) == g_575), 1UL))))
       &&
       ((p_82 =
         (safe_mul_func_int8_t_s_s
          (0x52L, (p_82 | l_1456[1][6])))) ^ g_806)),
      0xAFL)) == p_84);
        l_987 = (0x774A92FCL
          ||
          ((g_98 <
     (safe_lshift_func_uint8_t_u_u
      ((p_83 <= g_1394),
       6))) > ((g_655 !=
         ((((255UL <
      ((safe_lshift_func_int16_t_s_s
        ((safe_rshift_func_uint16_t_u_u ((p_82 = (g_280 == (((p_82 >= ((+(l_1322 == p_83)) >= (-2L))) <= p_84) < 0x79BFL))), g_1272)), l_828)) ^ 0x1274L)) | g_1182[1]) || g_983) > 18446744073709551615UL)) < p_83)));
      }
    for (g_575 = 0; (g_575 != 17); ++g_575)
      {
        uint16_t l_1489 = 65535UL;
        int32_t l_1490 = (-1L);
        l_1490
   =
   (safe_sub_func_int64_t_s_s
    (((safe_mod_func_int8_t_s_s
       ((safe_rshift_func_int8_t_s_u
         ((l_1453 =
    ((safe_rshift_func_int16_t_s_u
      ((safe_unary_minus_func_uint64_t_u (p_83)),
       10))
     && l_1456[0][2])), 4)),
        0xE8L)) |
      ((safe_mod_func_uint16_t_u_u
        (((0x17854D99L ^
    ((safe_mod_func_int64_t_s_s
      ((safe_mod_func_uint64_t_u_u
        ((safe_mul_func_uint8_t_u_u
          ((safe_sub_func_uint32_t_u_u
     ((0x36L
       && (l_1489 =
           ((-1L) ^
            ((((p_82 |
         (safe_lshift_func_int8_t_s_u
          ((l_1486[4][7][2] =
            1L),
           4))) <=
        (safe_sub_func_int64_t_s_s
         ((+(l_1324 | l_1413)),
          0L))) ^ 3L) ^ g_897)))),
      g_806)), l_1149)), 1UL)),
       p_83)) <= l_1313))
          && 0xF624F652L), g_189)) & l_1313)), l_1149));
        g_208[0] =
   (((p_83 || p_84)
     || l_1324) ==
    (safe_mul_func_uint16_t_u_u
     ((0xACAFC7DEBDA6C0E5LL |
       (g_455 =
        (l_1324 < 0xD2F041A4L))),
      (safe_sub_func_int32_t_s_s
       ((((safe_lshift_func_int16_t_s_s
    ((((safe_lshift_func_uint16_t_u_u
        (l_1486[4][7][2],
         ((safe_sub_func_uint16_t_u_u
           (((safe_mod_func_uint64_t_u_u
       ((p_83 != 0xAB67135D34B6704ALL),
        0xB64E942AB41C1C96LL)) ^ p_83),
     g_1060)) ^ g_575))) & l_1354) <=
      0x47471EF7L), g_99[1]))
          || g_208[0]) < p_83), 0x5A63CDFDL)))));
        p_84 =
   ((safe_sub_func_uint16_t_u_u
     (9UL,
      (safe_mod_func_int16_t_s_s
       ((l_1489 >=
         (safe_lshift_func_uint16_t_u_u
          (p_84,
    ((((safe_mod_func_int8_t_s_s
        (((((((((l_1522 =
          ((safe_sub_func_int32_t_s_s
            (((g_1513 =
        (g_983 = p_83)) != (l_1514 =
              l_1322)),
      ((((safe_lshift_func_int8_t_s_u ((safe_unary_minus_func_uint32_t_u (((safe_add_func_uint8_t_u_u (l_1324, l_1228[2][3])) || (safe_lshift_func_uint16_t_u_s ((p_83 >= (l_986 && l_1324)), 10))))), g_897)) >= l_880[0]) >= l_1413) != l_1328))) >= 9UL)) ^ l_1486[5][6][0]) == p_83) != g_703) || l_1522) || 0x92EB43EEL) != g_921[3][6][0]) != p_83), p_83)) || l_1228[2][3]) == g_4[0][4]) & 0xACE7L)))), g_208[1])))) <= 0UL);
      }
  }
       if ((safe_lshift_func_uint16_t_u_s
     ((l_1233 =
       (safe_mod_func_uint64_t_u_u (l_1522, l_1325))), g_97)))
  {
    int32_t l_1565 = (-8L);
    g_575
      =
      ((safe_mod_func_int32_t_s_s
        ((safe_unary_minus_func_uint8_t_u
   ((0x2E96D7C45DF5A736LL
     && (g_806
         ||
         (safe_mul_func_uint16_t_u_u
          (0x8ACDL,
    ((g_208[2] =
      ((p_84 =
        ((safe_mul_func_int8_t_s_s
          ((((safe_mod_func_int8_t_s_s
       ((((((safe_mod_func_uint16_t_u_u
      ((safe_mul_func_uint8_t_u_u
        ((safe_add_func_uint8_t_u_u
          (((l_1566 =
             (safe_add_func_uint8_t_u_u
       (((safe_sub_func_int32_t_s_s ((l_1328 = (((safe_mod_func_uint64_t_u_u ((safe_unary_minus_func_uint64_t_u (18446744073709551610UL)), (safe_rshift_func_int16_t_s_u (g_1551, 6)))) <= 65535UL) && p_84)), (~(safe_rshift_func_int8_t_s_u ((((safe_mod_func_uint64_t_u_u (p_84, ((safe_rshift_func_int8_t_s_s (((((safe_add_func_int16_t_s_s ((+(safe_unary_minus_func_int32_t_s ((safe_add_func_uint8_t_u_u ((((g_357 = ((safe_add_func_uint32_t_u_u (g_1551, 1UL)) > l_1522)) == 0x97L) == l_1565), g_4[1][2]))))), p_84)) && g_655) || p_82) ^ g_1060), p_83)) | 9L))) == l_1522) < l_880[1]), g_98))))) < g_983), g_1272))) == l_1522), 1UL)), g_921[5][7][0])), 1L)) <= p_82) & 250UL) <= p_82) || l_1313), g_209)) ^ g_1272) & g_280), 0xE5L)) == 0xF0L)) >= l_1567)) < l_827))))))), g_540[0][0][0])) || 18446744073709551615UL);
  }
       else
  {
    int8_t l_1568 = 0xAEL;
    int32_t l_1623 = 0xE82A9B9EL;
    int32_t l_1647 = 0x3F5BCADFL;
    for (l_1453 = 0; (l_1453 <= 3); l_1453 += 1)
      {
        int i;
        if (p_82)
   break;
        l_880[l_1453] = (g_1081[0][2] > p_82);
        l_1568 = l_1522;
      }
    for (l_1566 = 0; (l_1566 >= 0); l_1566 -= 1)
      {
        int16_t l_1633 = 1L;
        int i;
        g_208
   [l_1566]
   =
   ((((l_1586 =
       ((l_880[(l_1566 + 3)] ==
         ((~(250UL == l_880[(l_1566 + 2)])) &
          (((safe_rshift_func_uint8_t_u_s
      ((!(safe_mod_func_int8_t_s_s
          (g_208[2],
           ((safe_mul_func_int16_t_s_s
      ((safe_add_func_int16_t_s_s
        ((safe_sub_func_uint32_t_u_u
          ((safe_mod_func_int32_t_s_s
            (p_84,
      (safe_mod_func_uint16_t_u_u
       ((safe_sub_func_int64_t_s_s
         ((g_1081[0][0]
           || ((l_1354 = g_1182[2])
        >= (l_1585 =
            (l_828 <=
             l_1228[6]
             [4])))),
          l_880[(l_1566 + 3)])),
        g_455)))), g_806)), p_82)),
       p_84)) | 4L)))), 6)) >= l_1522)
    && 0L))) <= p_83)) | l_1313) <=
     0UL) & 0x938CL);
        l_880[(l_1566 + 2)] =
   (safe_add_func_uint32_t_u_u
    (((safe_mod_func_int64_t_s_s
       ((((g_208[l_1566] !=
    ((safe_lshift_func_uint8_t_u_u
      (((0x9F0C1CE9L
         ||
         (safe_lshift_func_int8_t_s_s (p_82, 5)))
        <=
        (safe_rshift_func_uint16_t_u_s
         (0x3DFDL,
          (safe_add_func_int16_t_s_s
           (0xB5D0L,
     (~
      ((3L <
        l_1566) ^
       (+
        (safe_mul_func_int16_t_s_s
         ((((g_1551 =
      (safe_lshift_func_int8_t_s_s
       ((safe_add_func_int16_t_s_s
         (p_83,
          (safe_add_func_uint16_t_u_u
           (0x1E10L, 0x62E2L)))),
        5))) | g_1395) == (-1L)),
          g_4[1][2])))))))))), l_1522))
     || (-7L))) < 0x875C13D606B252A8LL)
         && 0x50ABL), p_82)) | l_1228[6][2]), 3UL));
        g_1272 =
   ((safe_mod_func_uint64_t_u_u
     ((g_1272 <=
       (safe_rshift_func_uint16_t_u_u
        ((((~
     (l_1633 =
      (((!((+
     ((p_84 =
       (safe_mod_func_int64_t_s_s
        (((((l_1233 =
      (0x90L != l_828)) >
            (safe_lshift_func_int8_t_s_s
      ((safe_add_func_uint64_t_u_u
        (((((safe_sub_func_uint32_t_u_u ((~(safe_lshift_func_uint16_t_u_s ((g_208[l_1566] = ((g_359 = (l_1453 = (safe_mod_func_int32_t_s_s ((l_1623 = (g_921[2][7][0] = l_1567)), (safe_mod_func_uint8_t_u_u ((l_880[1] = (safe_mul_func_uint16_t_u_u ((g_189 < (safe_add_func_uint32_t_u_u (5UL, (0xDBL || 0x58L)))), (safe_mod_func_int8_t_s_s (p_84, g_99[0]))))), p_83)))))) && l_1322)), 8))), l_986)) && l_880[(l_1566 + 2)]) < g_983) == g_675), 3L)), 0))) <= l_1632) > l_1568), 0x24AB3E55A769AA44LL))) ^ 1L)) ^ g_209)) ^ l_1566) <= g_703))) >= g_236) || p_83), g_1081[0][0]))), 0x933AF9A3A9F54801LL)) & 1L);
        return p_82;
      }
    if (((-1L) & 1UL))
      {
        uint32_t l_1644 = 18446744073709551606UL;
        int8_t l_1648 = 0xC1L;
        if (g_983)
   goto lbl_1634;
        p_84
   =
   (l_1648
    =
    ((safe_rshift_func_uint8_t_u_s
      (((-1L) >=
        (safe_mod_func_int16_t_s_s
         ((l_1453 =
    ((safe_add_func_int16_t_s_s
      ((safe_sub_func_int16_t_s_s
        ((safe_unary_minus_func_uint32_t_u
          ((g_806
     && 0xDB113F1BL))), (p_83 =
           (0UL !=
            l_1328)))),
       (1UL ^
        (l_1644 <=
         (l_1623 ^
          (safe_sub_func_int8_t_s_s
           ((l_1647 =
      (p_82 != 0x51D9B541L)),
     l_1328))))))) < p_82)),
          g_1081[0][1]))), 5)) && l_828));
        l_1585 =
   (!((safe_unary_minus_func_int8_t_s
       (((g_189 =
          (safe_add_func_uint16_t_u_u
    ((l_1228[7][5] > (g_208[2] || g_280)),
     ((l_1453 =
       (p_83 |
        (((safe_unary_minus_func_int64_t_s
           ((0x6C47L && (g_922 = p_84))))
          || 8L) & (0x85L |
      (safe_lshift_func_uint16_t_u_u
       (1UL,
        12)))))) & 0xE08DL)))) >
         p_82))) < 0xF7L));
        l_828 =
   (safe_add_func_int16_t_s_s
    (l_828, (l_880[1] = p_82)));
      }
    else
      {
        p_84 = (-1L);
      }
  }
     }
   else
     {
       uint8_t l_1670 = 1UL;
       int32_t l_1677 = 5L;
       uint64_t l_1781 = 0xE9C26500479A43CALL;
       int32_t l_1782 = 0x54EEBEE9L;
       uint64_t l_1807 = 0x0BBDA714538BC9EELL;
       int32_t l_1834 = 0x0CAEA875L;
     lbl_1751:
       if (((safe_add_func_uint64_t_u_u
      ((((safe_mod_func_uint16_t_u_u
   ((l_1453 =
     ((((safe_unary_minus_func_uint32_t_u
         ((safe_mod_func_int16_t_s_s
    (((safe_mod_func_int8_t_s_s
       ((l_1233 =
         (6L >= l_1586)),
        l_1666)) &
      (safe_rshift_func_uint8_t_u_s
       ((safe_unary_minus_func_int32_t_s
         (l_1670)), l_986))), (p_83 =
          (safe_add_func_uint16_t_u_u
           (l_1228[9][2],
            ((safe_add_func_uint64_t_u_u (g_1182[2], p_83)) || ((safe_lshift_func_uint16_t_u_u (((g_178 = ((l_1328 = 0x79D9AE7CEC3C62C7LL) != g_1081[0][2])) <= p_82), l_1666)) >= 1L))))))))) < g_4[0][9]) ^ l_1354) & 1UL)), 1L)) ^ 0x6E1997D4L) ^ l_1677), p_82)) < l_1228[2][1]))
  {
    int8_t l_1691 = (-9L);
    for (g_1060 = 0; (g_1060 <= 3); g_1060 += 1)
      {
        int i;
        g_1272 = 8L;
        p_84
   =
   ((l_1328 =
     ((((g_1551 =
         g_99[g_1060]) ^ (((g_1678 = 0xDAL) &
      ((0xAC5FL >= 3UL) ==
       ((l_1322
         && (l_1677 =
             l_1677)) < (g_1272 ==
           (safe_mul_func_uint16_t_u_u
            (((safe_rshift_func_uint16_t_u_s (0x485CL, 7)) || (((safe_mod_func_uint32_t_u_u ((((safe_sub_func_uint8_t_u_u ((0xEB8F51CB6BA84F75LL > g_99[g_1060]), g_575)) < g_99[1]) >= p_84), 0xC3713C71L)) <= 0x214BL) >= l_1670)), 0x3EF1L)))))) < g_99[g_1060])) == (-4L)) && 4L)) ^ p_83);
        l_1453 =
   (safe_rshift_func_int8_t_s_s
    ((((safe_rshift_func_int16_t_s_s
        ((((p_84 =
     0x91F8C060L) ^ l_1691) <
          (safe_lshift_func_uint8_t_u_s
    (246UL,
     (g_4[0][4] &
      (safe_mod_func_uint8_t_u_u
       (p_83,
        (safe_mod_func_int8_t_s_s
         ((l_987 =
           (l_1233 =
     l_1453)), 4L)))))))), 0)) & p_82)
      || ((safe_mul_func_int16_t_s_s (l_1666, 0xB62EL)) |
          l_1677)), g_208[0]));
      }
    if (g_1272)
      goto lbl_1751;
    for (l_827 = 0; (l_827 <= 0); l_827 += 1)
      {
        int32_t l_1704 = 0xD0F49862L;
        if (p_83)
   break;
        l_1453
   =
   (safe_sub_func_int64_t_s_s
    ((safe_sub_func_int32_t_s_s
      ((-7L), (l_1233 = (l_1322 & 0L)))),
     (l_1704 ==
      ((safe_sub_func_int16_t_s_s
        ((0x1466D22C26F1E18FLL &
          (l_1691 !=
    ((l_987 = l_1704)
     ||
     (safe_mul_func_uint8_t_u_u
      (0x52L,
       (((((safe_mul_func_uint8_t_u_u
     (((0x12L | (-1L)) !=
       0xC2E3A521504A2681LL),
      p_84)) > 1UL) < 0L) | 7L)
        && (-9L))))))), g_1272)) < p_82))));
        return p_84;
      }
  }
       else
  {
    uint16_t l_1732 = 0x4680L;
    int32_t l_1750 = 2L;
    l_1328
      =
      (g_208
       [2]
       >
       ((p_83 <= l_986) ==
        (safe_add_func_uint16_t_u_u
         ((p_82 |
    ((safe_mod_func_uint32_t_u_u
      ((~
        (safe_rshift_func_uint8_t_u_s
         ((safe_sub_func_int16_t_s_s
    ((-9L),
     (safe_add_func_uint64_t_u_u
      (((safe_add_func_uint16_t_u_u
         (l_1725, p_84))
        || 0x81L),
       (safe_sub_func_int8_t_s_s
        ((g_280 > 0xBEB0A2990C09A926LL),
         0x7EL)))))), g_1272))), p_82))
     && p_84)), l_1670))));
    for (g_1272 = 0; (g_1272 <= 2); g_1272 += 1)
      {
        int i;
        return g_99[(g_1272 + 1)];
      }
    if ((p_84 =
         (3UL <
   (+
    (safe_sub_func_int8_t_s_s
     ((~
       (0x94L ^
        (((l_1328 &
    (((safe_rshift_func_int8_t_s_u
       (((8L >=
          ((0UL <=
     ((l_1732 = g_921[0][6][0])
      ||
      ((safe_mul_func_uint8_t_u_u
        ((3UL == p_82), g_1395))
       || l_1732))) > p_82)) ^ 1UL),
        l_1322)) ^ l_1735)
     || 9UL)) <=
          g_1182[1]) & 0x0CE8641D4AB25EB1LL))),
      p_83))))))
      {
        return g_209;
      }
    else
      {
        l_880
   [1]
   =
   (+
    (safe_sub_func_int64_t_s_s
     (g_806,
      (safe_rshift_func_int16_t_s_u
       (((0L >
          (safe_mul_func_uint16_t_u_u
    (l_1732,
     (0x75AC75D4F7E021C5LL ^
      (((1UL |
         (safe_rshift_func_uint8_t_u_u
          (l_1732, 3))) & g_1182[2])
       || p_82))))) ^ ((-7L) < g_4[1][2])),
        g_1678)))));
        g_208[2] = g_1678;
        g_1272
   =
   ((0xE7A556D0L >
     ((safe_rshift_func_int8_t_s_s
       (((((g_806 <= p_82) & (g_178 == p_84)) !=
          ((safe_sub_func_uint32_t_u_u
     (((l_1677 = l_1453) == (l_1750 =
        ((l_1354 =
          (p_84 <=
           (1L <=
            (((g_921[6][2][0]
        = (-1L))
              && 5L)
             && l_1354))))
         || p_83))),
      g_1678)) < g_1513)) > (-3L)),
        3)) < 4294967288UL)) <= 0x96FE76EE0E14BFF1LL);
      }
  }
       g_921
  [5]
  [7]
  [0]
  =
  (safe_lshift_func_uint16_t_u_s
   (1UL,
    (l_1328
     =
     (safe_mod_func_uint32_t_u_u
      ((((l_1782 =
   (g_1513 >=
    ((((safe_add_func_int64_t_s_s
        ((g_455 =
          (g_1395 =
    ((((~
        ((l_880[0] =
          ((safe_sub_func_uint8_t_u_u
     ((safe_add_func_int8_t_s_s
       (((safe_mul_func_int16_t_s_s
          (((((~g_1182[2]) != p_83) <=
      p_82) <=
            ((((l_1453 =
         (safe_sub_func_uint16_t_u_u
          ((0xEEL
            ||
            ((safe_mul_func_uint16_t_u_u (((((safe_rshift_func_int16_t_s_s ((safe_lshift_func_uint8_t_u_s ((safe_lshift_func_int8_t_s_u (l_1735, (g_359 = (l_1677 = ((((((safe_mul_func_int16_t_s_s ((g_540[0][0][0] = (l_1233 = (safe_rshift_func_uint16_t_u_s (((((0xD94EA4E5L <= (safe_rshift_func_int16_t_s_u (((g_99[2] = p_82) != 8UL), 8))) <= g_1182[2]) == 0xB253L) && p_83), l_1670)))), g_1272)) | 246UL) & l_1780) & 253UL) & l_1781) != p_84))))), 4)), 5)) && l_1228[2][3]) | l_1670) ^ l_1228[2][3]), p_82)) == p_83)), 0xE3CCL))) & l_1781) || p_83) > 4UL)), 0xFE9CL)) == g_1182[2]), g_455)), 0xDAL)) == g_922)) == 0L)) >= 65532UL) != 0x3AB69519L) == g_98))), (-10L))) && 65535UL) == g_1060) | 0x47A8A693L))) || g_540[0][0][4]) >= l_1228[6][5]), 4294967291UL)))));
       for (g_806 = 0; (g_806 <= 5); g_806++)
  {
    p_84 = p_84;
    if (p_83)
      continue;
  }
       for (l_1313 = 1; (l_1313 <= 47); ++l_1313)
  {
    int16_t l_1789 = 0x284DL;
    int32_t l_1804[6] =
    {
    2L, 0xFACF9868L, 0xFACF9868L, 2L, 0xFACF9868L, 0xFACF9868L};
    int32_t l_1835 = 0x9E3A02D6L;
    int i;
    for (g_675 = 0; (g_675 <= 2); g_675 += 1)
      {
        int i, j;
        p_84
   =
   (safe_add_func_int8_t_s_s
    (0xC1L,
     ((l_1228[g_675][g_675] > l_1789) >
      (safe_mod_func_uint32_t_u_u
       ((safe_sub_func_uint64_t_u_u
         ((((safe_add_func_uint8_t_u_u
      ((safe_sub_func_int16_t_s_s
        ((((l_1781
     &&
     (safe_rshift_func_uint16_t_u_u
      ((((safe_rshift_func_int8_t_s_s
          (((safe_add_func_int16_t_s_s
      (8L,
       (((l_1804[0] = l_1780)
         || 0UL) |
        ((safe_sub_func_uint32_t_u_u
          ((g_1081[0][3] |
            18446744073709551612UL),
           g_1081[0][5])) <=
         p_82)))) >=
            18446744073709551614UL), 6))
         && l_1807) ^
        0x501C44B94CA3BBE9LL),
       9))) > g_1395)
          && g_1182[2]), 0x63E1L)),
       l_1313)) ^ p_84) != g_921[5][7][0]),
          0x73794F599140E9E7LL)), l_1228[5][5])))));
        if (p_82)
   continue;
        if (p_84)
   break;
      }
    for (g_97 = 0; g_97 < 3; g_97 += 1)
      {
        g_208[g_97] = 0x521E8803L;
      }
    l_1453
      =
      (l_1670
       ||
       ((safe_lshift_func_int8_t_s_s
         ((safe_mul_func_uint16_t_u_u
    ((safe_mod_func_uint64_t_u_u
      ((0x0713CBF8L !=
        (l_1233 =
         ((l_1835 =
    (((((l_1834 =
         ((~
           (l_1677 =
     (l_1782 =
      ((l_1804[0] =
        (((safe_sub_func_uint64_t_u_u
           ((safe_mod_func_int8_t_s_s
      (((-1L) ==
        (safe_add_func_uint64_t_u_u
         ((((g_1551 =
             ((safe_unary_minus_func_int8_t_s ((l_1781 > (g_675 < (safe_lshift_func_uint16_t_u_u (((safe_mul_func_int16_t_s_s ((((((g_1081[0][0] ^ (safe_mod_func_int8_t_s_s ((safe_mod_func_int64_t_s_s (((g_897 >= g_98) > (safe_add_func_int16_t_s_s (((((safe_mod_func_uint16_t_u_u (1UL, p_84)) ^ p_84) != g_455) == l_1804[0]), l_1313))), g_4[1][5])), g_675))) & 0xDDCBB4C1C76D8299LL) <= 0L) > l_1780) != l_987), g_675)) > l_986), l_1781)))))) && 0xF13DL)) ^ p_83) <= g_97), p_84))), l_1833)), l_1567)) <= g_98) == 0xB884E710L)) < p_83)))) && l_987)) > 5UL) >= p_82) >= g_806) < l_827)) <= 6UL))), p_82)), 1UL)), g_540[0][0][0])) <= l_1789));
    for (g_655 = 27; (g_655 >= 17); --g_655)
      {
        g_208
   [1]
   =
   (safe_lshift_func_int8_t_s_s
    ((safe_lshift_func_int8_t_s_s
      ((((safe_sub_func_int8_t_s_s
          (((g_455 =
      0xB28F1B417A913D1ALL) != p_82),
    (safe_add_func_uint16_t_u_u
     (p_82,
      ((safe_rshift_func_uint16_t_u_s
        ((safe_sub_func_uint64_t_u_u
          (0x3357125605637908LL,
           (safe_add_func_uint8_t_u_u
     ((safe_sub_func_uint32_t_u_u
       (l_1854,
        ((((((safe_lshift_func_int8_t_s_s
       (p_82,
        (safe_add_func_uint64_t_u_u
         ((safe_rshift_func_int16_t_s_u (p_84, (p_83 & (safe_mul_func_uint8_t_u_u (g_897, g_1272))))), 0x8F7A3C7D3CC29EB0LL)))) <= g_655) || 6L) <= 65533UL) & g_1182[2]) >= g_1863))), g_1272)))), p_83)) | 0x4760L))))) == 18446744073709551615UL) <= p_83), p_83)), l_1322));
        if (g_575)
   break;
        g_575
   =
   (safe_rshift_func_uint8_t_u_s
    (((safe_sub_func_uint16_t_u_u ((+g_1551), 0xA88EL))
      ==
      (safe_lshift_func_int16_t_s_s
       (p_82,
        (((!(safe_mul_func_uint8_t_u_u
      (p_82,
       ((safe_lshift_func_int16_t_s_s
         (l_1328,
          l_1835)) !=
        (safe_mod_func_int16_t_s_s
         ((safe_lshift_func_int16_t_s_u
           (p_83,
     (safe_add_func_int64_t_s_s
      (l_1835, 0x5B2801ADFE173DBELL)))),
          g_983)))))) != p_84) ^ g_1394)))), 5));
      }
  }
     }
 }
      g_575
 =
 ((safe_mod_func_uint64_t_u_u
   ((p_82 !=
     (safe_sub_func_uint16_t_u_u
      ((safe_sub_func_int8_t_s_s
        (p_84,
  (((safe_sub_func_uint16_t_u_u
     (1UL,
      ((p_84 ^
        ((safe_add_func_uint8_t_u_u
   ((l_1325 || g_4[1][2]), ((g_99[3] = l_1325) || 0UL)))
         ||
         (safe_mul_func_int16_t_s_s
   (((safe_rshift_func_int8_t_s_s
      ((safe_lshift_func_int16_t_s_u ((p_82 & g_97), 2)),
       7)) ^ l_1323),
    p_82)))) ^ 0x9D5E48A1L))) == l_1453) ^ l_828))),
       0x914BL))), l_1325)) && 1UL);


    }
  else
    {
      uint64_t l_2070 = 18446744073709551610UL;
      int32_t l_2123 = 0xF5D790DEL;
      uint32_t l_2296 = 0x51B3FDA5L;
    lbl_2208:
      g_575 = 0L;


      return g_575;
    }
  g_575
    =
    (safe_mul_func_uint16_t_u_u
     ((safe_mul_func_int16_t_s_s
       ((((l_986
    && (-1L)) != ((l_1735 =
     ((((safe_lshift_func_int16_t_s_u
         ((safe_lshift_func_uint8_t_u_s
    (((g_209 =
       l_1323) <= l_1961), 3)),
          12)) ^
        ((safe_lshift_func_uint8_t_u_u
          ((safe_sub_func_uint64_t_u_u
     ((g_2227 =
       (safe_lshift_func_int8_t_s_s
        (l_1325,
         ((safe_rshift_func_int16_t_s_u
           (((!(safe_lshift_func_int8_t_s_u
         ((safe_add_func_int64_t_s_s
           ((p_84 >=
      ((safe_add_func_uint16_t_u_u
        ((safe_mod_func_uint16_t_u_u
          ((safe_sub_func_int8_t_s_s
            ((0xA776B0C5L
       ||
       (((l_1725 ==
          (safe_mod_func_uint32_t_u_u
           (g_1551,
            g_208[2]))) <=
         p_82) | 0xE5E7L)),
             p_84)), 7L)),
         g_897)) ^
       0x204F086E254DB323LL)),
            g_1182[2])), 2))) | g_99[2]),
     15)) >= l_1323)))), p_83)),
    g_540[0][0][7])) > 0x85D4L)) != (-2L)) <
      0x5716L)) | 1UL)) <= 0xAC39482E04F96321LL),
 0x3543L)), p_82));
  return g_98;
}







static uint8_t func_91 (uint8_t p_92, uint16_t p_93, uint8_t p_94)
{
  uint64_t l_173 = 0x5B3299B2AD0072B3LL;
  int32_t l_210 = (-1L);
  int32_t l_211 = 0xFA455216L;
  int32_t l_229 = 0x7219EB45L;
  int32_t l_251[6][10] =
  {
    {
    0xD8EA7C6DL,
 0x68F5A85FL,
 0xA5DDA629L,
 0x68F5A85FL, 0xD8EA7C6DL, 1L, 0x1452917BL, 1L, (-1L), (-1L)},
    {
    1L, 0x1452917BL, 1L, (-1L), (-1L), 7L, 1L, 1L, 7L, (-1L)},
    {
    0xA5DDA629L, (-1L), (-1L), 0xA5DDA629L, 0xD8EA7C6DL, (-1L), 0xF45CD968L,
 1L, 0x3E52E987L, 0x1452917BL},
    {
    9L, 0xD8EA7C6DL, 0x61E81591L, 7L, 0x3E52E987L, 0xF45CD968L, (-1L),
 0xF45CD968L, 0x3E52E987L, 7L},
    {
    0x1452917BL, 9L, 0x1452917BL, 0xA5DDA629L, 1L, 0x9C3501ADL, 0x3E52E987L,
 0L, 7L, 0L},
    {
  0L, 0x9C3501ADL, 0xD8EA7C6DL, (-1L), 0L, (-1L), (-1L), 0L, (-1L),
 0xD8EA7C6DL}};
  int32_t l_279 = 0xE0A9FA56L;
  uint8_t l_405 = 0xF5L;
  uint64_t l_454[7] =
  {
  0x0489F0D1E4D8781CLL,
      0UL, 0UL, 0x0489F0D1E4D8781CLL, 0UL, 0UL, 0x0489F0D1E4D8781CLL};
  int16_t l_541 = (-2L);
  int32_t l_603 = 0L;
  uint32_t l_738 = 0x79DDECCEL;
  int32_t l_807 = (-1L);
  int i, j;
lbl_302:
  for (p_93 = 0; (p_93 <= 3); p_93 += 1)
    {
      int32_t l_102[10];
      int32_t l_186 = 1L;
      int i;
      for (i = 0; i < 10; i++)
 l_102[i] = 0x6043366FL;
      if (func_100 ((l_102[4] = g_99[p_93])))
 {
   uint32_t l_179 = 0xF59071E4L;
   for (p_92 = 0; (p_92 <= 3); p_92 += 1)
     {
       uint64_t l_154 = 0x27D408D08F60D6E8LL;
       int32_t l_180[2][1][6] =
       {
  {
    {
    (-1L), 0x3E24EADEL, 0L, 0L, (-1L), 0L}
  }
  ,
  {
    {
    0L, (-1L), 0L, 0L, (-1L), 0L}
  }
       };
       int i, j, k;
       l_154 = 0xA15C47ABL;
       l_180
  [1]
  [0]
  [5]
  =
  (safe_rshift_func_uint16_t_u_s
   (((safe_sub_func_int16_t_s_s
      ((((g_99[p_93] <=
   (safe_lshift_func_uint8_t_u_u (0xFEL, 6))) >=
         (((g_4[1][2] <=
     (safe_mul_func_uint8_t_u_u
      (((!(0xA209B0CDL >
    (safe_rshift_func_int8_t_s_s
     ((g_178 =
       (safe_add_func_int16_t_s_s
        ((safe_sub_func_int8_t_s_s
          (((((safe_rshift_func_uint8_t_u_u
        ((safe_add_func_uint64_t_u_u
          (((0x7775L >= 65533UL)
            || 4UL), l_173)),
         (safe_mul_func_uint8_t_u_u
          (((((safe_lshift_func_uint16_t_u_u (l_173, 2)) < 0UL) ^ p_93) < g_4[0][4]), l_173)))) && l_154) ^ 0L) != p_92), g_97)), p_93))), l_179)))) == 4294967293UL), g_98))) == g_99[p_93]) ^ 0x016036A6L)) && 0xBB1FL), 65535UL)) ^ p_92), 15));
     }
 }
      else
 {
   uint16_t l_185 = 65534UL;
   g_189
     =
     ((l_186 =
       (((-1L) <=
  (l_102[1] =
   (safe_sub_func_int64_t_s_s
    (((p_93 ^ p_92) !=
      (safe_mul_func_uint8_t_u_u (p_94, (l_185 ^ g_4[1][2])))),
     18446744073709551615UL)))) ^ g_97)) !=
      ((((safe_lshift_func_uint8_t_u_u (p_93, l_173)) !=
  255UL) ^ g_99[p_93]) <= g_178));
   l_186 = (-1L);
 }
    }
  l_211
    =
    (safe_rshift_func_uint16_t_u_u
     ((g_178 !=
       ((g_99[3] =
  (safe_mod_func_uint16_t_u_u
   ((((l_210 =
       (safe_lshift_func_uint16_t_u_u
        ((~
   (safe_sub_func_uint32_t_u_u
    (p_92,
     (g_189 |
      ((safe_mod_func_uint64_t_u_u
        (((p_94 =
    (((safe_mul_func_uint16_t_u_u
       (0x4C97L,
        ((safe_lshift_func_int16_t_s_u
          ((g_209 =
     (g_208[2] =
      (~
       (safe_lshift_func_uint8_t_u_u
        (((((safe_add_func_int8_t_s_s
      ((8UL
        && g_98),
       (65533UL <= p_92))) >=
     0xC2FFDF52C73AE872LL) != l_173) >
          p_92), l_173))))),
    5)) > p_92))) & 0xF2569BDC76872175LL) >
     0x8814L)) | l_173), l_173)) | 0xB29FL))))),
  p_93))) ^ 0UL) != p_93), l_173))) ^ g_189)), 1));
  if ((l_211 = g_189))
    {
      int32_t l_224 = 9L;
      int32_t l_225 = 0xD34CFEFFL;
      int32_t l_230 = 0x575F5937L;
      if ((safe_mod_func_uint32_t_u_u
    ((!(((-5L) <=
  ((+
    ((safe_rshift_func_uint8_t_u_s (0xE6L, p_93)) ==
     ((safe_sub_func_int64_t_s_s
       (((safe_lshift_func_uint8_t_u_u
   ((((0x67A6C11AL <=
       (safe_mul_func_int8_t_s_s
        ((safe_rshift_func_uint16_t_u_u
          (((l_225 =
      ((l_224 =
        g_208[2]) >= l_210)) >=
     ((safe_mul_func_uint16_t_u_u
       (0UL,
        ((safe_unary_minus_func_uint32_t_u
          ((l_229 =
     (l_211 = 0xBED90661L)))) > (6UL
            && 5UL))))
      > g_208[2])), 14)),
         p_92))) != 65526UL) & g_178),
    g_97)) > 18446744073709551612UL),
        0xAFBF69327C09D144LL)) & p_94))) < 1UL)) >= l_230)),
     l_210)))
 {
   return l_211;
 }
      else
 {
   int16_t l_254[8][8][4] =
   {
     {
       {
       (-1L), 0x132BL, (-1L), 4L}
       ,
       {
       (-5L), 0x7712L, (-10L), 0x7712L}
       ,
       {
       0x7712L, (-1L), (-1L), 0x7712L}
       ,
       {
       (-1L), 0x7712L, 4L, 4L}
       ,
       {
       0x132BL, 0x132BL, (-10L), (-5L)}
       ,
       {
       0x132BL, (-1L), 4L, 0x132BL}
       ,
       {
       (-1L), (-5L), (-1L), 4L}
       ,
       {
       0x7712L, (-5L), (-10L), 0x132BL}
     }
     ,
     {
       {
       (-5L), (-1L), (-1L), (-5L)}
       ,
       {
       (-1L), 0x132BL, (-1L), 4L}
       ,
       {
       (-5L), 0x7712L, (-10L), 0x7712L}
       ,
       {
       0x7712L, (-1L), (-1L), 0x7712L}
       ,
       {
       (-1L), 0x7712L, 4L, 4L}
       ,
       {
       0x132BL, 0x132BL, (-10L), (-5L)}
       ,
       {
       0x132BL, (-1L), 4L, 0x132BL}
       ,
       {
       (-1L), (-5L), (-1L), 4L}
     }
     ,
     {
       {
       0x7712L, (-5L), (-10L), 0x132BL}
       ,
       {
       (-5L), (-1L), (-1L), (-5L)}
       ,
       {
       (-1L), 0x132BL, (-1L), 4L}
       ,
       {
       (-5L), 0x7712L, (-10L), 0x7712L}
       ,
       {
       0x7712L, (-1L), (-1L), 0x7712L}
       ,
       {
       (-1L), 0x7712L, 4L, 4L}
       ,
       {
       0x132BL, 0x132BL, (-10L), (-5L)}
       ,
       {
       0x132BL, (-1L), 4L, 0x132BL}
     }
     ,
     {
       {
       (-1L), (-5L), (-1L), 4L}
       ,
       {
       0x7712L, (-5L), (-10L), 0x132BL}
       ,
       {
       (-5L), (-1L), (-1L), (-5L)}
       ,
       {
       (-1L), 0x132BL, (-1L), 4L}
       ,
       {
       (-5L), 0x7712L, (-10L), 0x7712L}
       ,
       {
       0x7712L, (-1L), (-1L), 0x7712L}
       ,
       {
       (-1L), 0x7712L, 4L, 4L}
       ,
       {
       0x132BL, 0x132BL, (-10L), (-5L)}
     }
     ,
     {
       {
       0x132BL, (-1L), 4L, 0x132BL}
       ,
       {
       (-1L), (-5L), (-1L), 4L}
       ,
       {
       0x7712L, (-5L), (-10L), 0x132BL}
       ,
       {
       (-5L), (-1L), (-1L), (-5L)}
       ,
       {
       (-1L), 0x132BL, (-1L), 4L}
       ,
       {
       (-5L), 0x7712L, (-10L), 0x7712L}
       ,
       {
       0x7712L, (-1L), (-1L), 0x7712L}
       ,
       {
       (-1L), 0x7712L, 4L, 4L}
     }
     ,
     {
       {
       0x132BL, 0x132BL, (-10L), (-5L)}
       ,
       {
       0x132BL, (-1L), 4L, 0x132BL}
       ,
       {
       (-1L), (-5L), (-1L), 4L}
       ,
       {
       0x7712L, (-5L), (-10L), 0x132BL}
       ,
       {
       (-5L), (-1L), (-1L), (-5L)}
       ,
       {
       (-1L), (-1L), (-10L), 0x3FD3L}
       ,
       {
       (-1L), 4L, 0x132BL, 4L}
       ,
       {
       4L, (-10L), 0x24D7L, 4L}
     }
     ,
     {
       {
       0x24D7L, 4L, 0x3FD3L, 0x3FD3L}
       ,
       {
       (-1L), (-1L), 0x132BL, (-1L)}
       ,
       {
       (-1L), (-10L), 0x3FD3L, (-1L)}
       ,
       {
       0x24D7L, (-1L), 0x24D7L, 0x3FD3L}
       ,
       {
       4L, (-1L), 0x132BL, (-1L)}
       ,
       {
       (-1L), (-10L), (-10L), (-1L)}
       ,
       {
       0x24D7L, (-1L), (-10L), 0x3FD3L}
       ,
       {
       (-1L), 4L, 0x132BL, 4L}
     }
     ,
     {
       {
       4L, (-10L), 0x24D7L, 4L}
       ,
       {
       0x24D7L, 4L, 0x3FD3L, 0x3FD3L}
       ,
       {
       (-1L), (-1L), 0x132BL, (-1L)}
       ,
       {
       (-1L), (-10L), 0x3FD3L, (-1L)}
       ,
       {
       0x24D7L, (-1L), 0x24D7L, 0x3FD3L}
       ,
       {
       4L, (-1L), 0x132BL, (-1L)}
       ,
       {
       (-1L), (-10L), (-10L), (-1L)}
       ,
       {
       0x24D7L, (-1L), (-10L), 0x3FD3L}
     }
   };
   int32_t l_295 = 0xB576518FL;
   int32_t l_354 = 1L;
   int16_t l_376 = (-1L);
   int i, j, k;
 lbl_412:
   if ((safe_add_func_uint16_t_u_u
        (p_93,
  ((safe_unary_minus_func_uint8_t_u (0UL))
   &&
   (safe_mod_func_int64_t_s_s
    (((g_236 == p_94) <=
      (safe_rshift_func_uint8_t_u_s
       (((l_225 =
   ((g_178 =
     p_92) &
    ((safe_add_func_int32_t_s_s
      ((((+
          (((((safe_lshift_func_int16_t_s_u
        (((safe_mul_func_int16_t_s_s
           (((safe_rshift_func_uint16_t_u_u
       ((((safe_mul_func_uint8_t_u_u
           ((safe_lshift_func_int8_t_s_s
      ((l_251[2][9] <=
        (safe_sub_func_uint64_t_u_u
         (l_224,
          (p_94 ^
           ((1UL != g_99[0]) !=
            (-2L)))))), 1)),
            g_99[3])) > l_254[4][4][1])
         || 0xD77BE777DDB8EC8CLL),
        13)) < l_224), p_92)) < (-1L)), 0))
       && g_236) != p_92) >
     g_99[3]) & 0UL)) | g_98) |
        0xA6FA7AC4E5C6B997LL), g_189))
     && 0L))) <= g_99[2]), p_93))), g_236))))))
     {
       uint16_t l_259 = 0x1E3EL;
       int32_t l_281 = 0x8252909BL;
       l_251[2][9] = 0x488E89D4L;
       l_210
  =
  (((l_251[2][9] =
     p_92) | (p_93 >= p_93)) ==
   ((0xD81AABCE9E38342FLL ^ p_93) ==
    (safe_lshift_func_uint16_t_u_u (p_92, 12))));
       for (g_178 = 0; (g_178 > 40);
     g_178 = safe_add_func_uint16_t_u_u (g_178, 1))
  {
    uint32_t l_278[10][6] =
    {
      {
      4UL, 4UL, 4UL, 4UL, 4UL, 4UL}
      ,
      {
      4UL, 4UL, 4UL, 4UL, 4UL, 4UL}
      ,
      {
      4UL, 4UL, 4UL, 4UL, 4UL, 4UL}
      ,
      {
      4UL, 4UL, 4UL, 4UL, 4UL, 4UL}
      ,
      {
      4UL, 4UL, 4UL, 4UL, 4UL, 4UL}
      ,
      {
      4UL, 4UL, 4UL, 4UL, 4UL, 4UL}
      ,
      {
      4UL, 4UL, 4UL, 4UL, 4UL, 4UL}
      ,
      {
      4UL, 4UL, 4UL, 4UL, 4UL, 4UL}
      ,
      {
      4UL, 4UL, 4UL, 4UL, 4UL, 4UL}
      ,
      {
      4UL, 4UL, 4UL, 4UL, 4UL, 4UL}
    };
    int i, j;
    l_281
      =
      (((+
         (g_280 =
   (((l_211 = (l_259 = p_94)) && (!0UL))
    ||
    (((safe_mul_func_int16_t_s_s
       (((safe_add_func_uint32_t_u_u
          ((safe_mul_func_int16_t_s_s
     ((safe_mul_func_int16_t_s_s
       ((!g_236),
        (safe_mod_func_int8_t_s_s
         ((((l_279 =
      (safe_mul_func_uint8_t_u_u
       (((l_259 & 0x543C7B79E97E57FELL) >=
         l_251[2][9]),
        ((+
          ((-1L) & 18446744073709551615UL))
         &&
         (((l_211 =
            (!(safe_mod_func_int64_t_s_s
        (((safe_lshift_func_uint16_t_u_s (((safe_add_func_uint64_t_u_u ((l_210 & l_254[4][4][1]), 0xBBCD69BB4E128B6DLL)) != p_92), g_99[0])) ^ g_178), l_278[9][0])))) ^ g_208[0]) < g_97))))) == g_189) | p_94), g_189)))), g_208[2])), 0L)) && p_92), p_92)) > p_93) ^ p_93)))) >= p_93) | p_93);
    return l_281;
  }
     }
   else
     {
       int32_t l_284[10][9] =
       {
  {
  0xA434B96EL,
      (-5L), 0x39551F97L, 0xB0DC29E2L, 1L, 8L, (-9L), (-1L), 0L}
  ,
  {
  1L, 7L, 0x36C56402L, (-9L), (-1L), 7L, 0x39551F97L,
      0x36C56402L, 0x39551F97L}
  ,
  {
  7L, 0x411491ABL, (-1L), (-1L), 0x411491ABL, 7L, 1L,
      0x36C56402L, 0x881E0420L}
  ,
  {
  7L, (-1L), (-9L), 0x36C56402L, 7L, 1L, (-1L), (-1L),
      0x36C56402L}
  ,
  {
  8L, 1L, 0xB0DC29E2L, 0x39551F97L, (-5L), 0xA434B96EL, 1L,
      0xA434B96EL, (-5L)}
  ,
  {
  0xB0DC29E2L, (-1L), (-1L), 0xB0DC29E2L, 1L, 0xA434B96EL,
      0x39551F97L, 7L, 0L}
  ,
  {
  0xB915A60AL, 0x39551F97L, 1L, 0L, 7L, 0x39551F97L,
      0xA434B96EL, 1L, 0xB0DC29E2L}
  ,
  {
  0x9B17201FL, 7L, 0x55E27A0AL, 1L, (-1L), 0x9B17201FL, (-1L),
      1L, 0x55E27A0AL}
  ,
  {
  7L, 7L, 0x9B17201FL, 1L, 0L, (-1L), (-9L), 8L, 1L}
  ,
  {
  (-1L), 1L, 0x881E0420L, 0L, 0x9B17201FL, (-1L), 1L,
      0x2C8324DFL, 0xA434B96EL}
       };
       int32_t l_287 = 0xA8841FF7L;
       int i, j;
       l_230
  =
  ((g_189 =
    (-1L)) | (safe_lshift_func_uint16_t_u_u (l_254[4][4][1],
          14)));
       l_295 =
  ((l_284[0][5] =
    (l_225 =
     p_94)) == ((safe_rshift_func_uint16_t_u_u ((l_287 = g_280),
             3))
         ||
         (safe_unary_minus_func_int8_t_s
          ((safe_lshift_func_int16_t_s_s
     (((safe_mul_func_int16_t_s_s
        ((p_93 !=
          ((((-1L) != (~g_208[2])) & l_230)
           &&
           (((p_94 <= 0UL) ==
      (safe_mul_func_int8_t_s_s
       ((l_211 && g_236), p_93)))
     && p_92))), l_254[4][4][1])) == p_92),
      3))))));
     }
   for (p_93 = (-19); (p_93 < 44); ++p_93)
     {
       uint32_t l_332 = 3UL;
       int64_t l_353 = 0xD4DE7019B247C13DLL;
       int32_t l_355 = 0xEEFD7E30L;
       int32_t l_356 = (-5L);
       uint32_t l_358[4] =
       {
       4294967287UL, 4294967287UL, 4294967287UL, 4294967287UL};
       int16_t l_437[7][9][1] =
       {
  {
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
  }
  ,
  {
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
  }
  ,
  {
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
  }
  ,
  {
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
  }
  ,
  {
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
  }
  ,
  {
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
  }
  ,
  {
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
  }
       };
       int i, j, k;
       for (l_295 = 3; (l_295 >= 0); l_295 -= 1)
  {
    int32_t l_330 = 8L;
    int i, j;
    if (((safe_rshift_func_uint8_t_u_u
   ((safe_rshift_func_uint16_t_u_s
     ((0xE0L <
       ((l_225 =
         (0xA787L
          || l_251[(l_295 + 2)][(l_295 + 6)])) ^ p_92)),
      p_93)), p_94))
         || ((l_251[(l_295 + 1)][(l_295 + 3)] = 0x442AE9B4L) <
      0xC048E1D8L)))
      {
        int16_t l_307 = 1L;
        int32_t l_331[9][9][3] =
        {
   {
     {
     0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
     ,
     {
     0L, (-1L), 0x5D116E59L}
     ,
     {
     0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
     ,
     {
     0x0E7B4870L, (-5L), (-1L)}
     ,
     {
     0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
     ,
     {
     0L, (-5L), 0x5D116E59L}
     ,
     {
     0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
     ,
     {
     0x0E7B4870L, (-1L), (-1L)}
     ,
     {
     0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
   }
   ,
   {
     {
     0L, (-1L), 0x5D116E59L}
     ,
     {
     0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
     ,
     {
     0x0E7B4870L, (-5L), (-1L)}
     ,
     {
     0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
     ,
     {
     0L, (-5L), 0x5D116E59L}
     ,
     {
     0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
     ,
     {
     0x0E7B4870L, (-1L), (-1L)}
     ,
     {
     0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
     ,
     {
     0L, (-1L), 0x5D116E59L}
   }
   ,
   {
     {
     0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
     ,
     {
     0x0E7B4870L, (-5L), (-1L)}
     ,
     {
     0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
     ,
     {
     0L, (-5L), 0x5D116E59L}
     ,
     {
     0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
     ,
     {
     0x0E7B4870L, (-1L), (-1L)}
     ,
     {
     0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
     ,
     {
     0L, (-1L), 0x5D116E59L}
     ,
     {
     0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
   }
   ,
   {
     {
     0x0E7B4870L, (-5L), (-1L)}
     ,
     {
     0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
     ,
     {
     0L, (-5L), (-1L)}
     ,
     {
     0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
     ,
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
     ,
     {
     0x7C8294B8L, (-4L), (-4L)}
     ,
     {
     0L, 0x14600C48L, (-1L)}
     ,
     {
     (-4L), 0x44A49926L, (-4L)}
     ,
     {
     (-1L), 5L, 0xB9BABAE2L}
   }
   ,
   {
     {
     (-4L), (-4L), 0x8ECCDEC7L}
     ,
     {
     0L, 5L, (-1L)}
     ,
     {
     0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
     ,
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
     ,
     {
     0x7C8294B8L, (-4L), (-4L)}
     ,
     {
     0L, 0x14600C48L, (-1L)}
     ,
     {
     (-4L), 0x44A49926L, (-4L)}
     ,
     {
     (-1L), 5L, 0xB9BABAE2L}
     ,
     {
     (-4L), (-4L), 0x8ECCDEC7L}
   }
   ,
   {
     {
     0L, 5L, (-1L)}
     ,
     {
     0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
     ,
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
     ,
     {
     0x7C8294B8L, (-4L), (-4L)}
     ,
     {
     0L, 0x14600C48L, (-1L)}
     ,
     {
     (-4L), 0x44A49926L, (-4L)}
     ,
     {
     (-1L), 5L, 0xB9BABAE2L}
     ,
     {
     (-4L), (-4L), 0x8ECCDEC7L}
     ,
     {
     0L, 5L, (-1L)}
   }
   ,
   {
     {
     0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
     ,
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
     ,
     {
     0x7C8294B8L, (-4L), (-4L)}
     ,
     {
     0L, 0x14600C48L, (-1L)}
     ,
     {
     (-4L), 0x44A49926L, (-4L)}
     ,
     {
     (-1L), 5L, 0xB9BABAE2L}
     ,
     {
     (-4L), (-4L), 0x8ECCDEC7L}
     ,
     {
     0L, 5L, (-1L)}
     ,
     {
     0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
   }
   ,
   {
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
     ,
     {
     0x7C8294B8L, (-4L), (-4L)}
     ,
     {
     0L, 0x14600C48L, (-1L)}
     ,
     {
     (-4L), 0x44A49926L, (-4L)}
     ,
     {
     (-1L), 5L, 0xB9BABAE2L}
     ,
     {
     (-4L), (-4L), 0x8ECCDEC7L}
     ,
     {
     0L, 5L, (-1L)}
     ,
     {
     0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
     ,
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
   }
   ,
   {
     {
     0x7C8294B8L, (-4L), (-4L)}
     ,
     {
     0L, 0x14600C48L, (-1L)}
     ,
     {
     (-4L), 0x44A49926L, (-4L)}
     ,
     {
     (-1L), 5L, 0xB9BABAE2L}
     ,
     {
     (-4L), (-4L), 0x8ECCDEC7L}
     ,
     {
     0L, 5L, (-1L)}
     ,
     {
     0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
     ,
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
     ,
     {
     0x7C8294B8L, (-4L), (-4L)}
   }
        };
        int i, j, k;
        if (g_189)


   {
     {
       uint32_t l_332 = 3UL;
       int64_t l_353 = 0xD4DE7019B247C13DLL;
       int32_t l_355 = 0xEEFD7E30L;
       int32_t l_356 = (-5L);
       uint32_t l_358[4] =
       {
       4294967287UL,
    4294967287UL, 4294967287UL, 4294967287UL};
       int16_t l_437[7][9][1] =
       {
         {
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
         }
         ,
         {
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
         }
         ,
         {
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
         }
         ,
         {
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
         }
         ,
         {
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
         }
         ,
         {
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
         }
         ,
         {
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
    ,
    {
    (-7L)}
    ,
    {
    0L}
    ,
    {
    (-7L)}
    ,
    {
    0xB237L}
    ,
    {
    0L}
    ,
    {
    0xB237L}
         }
       };
       int i, j, k;
       for (l_295 = 3; (l_295 >= 0); l_295 -= 1)
         {
    int32_t l_330 = 8L;
    int i, j;
    if (((safe_rshift_func_uint8_t_u_u
          ((safe_rshift_func_uint16_t_u_s
     ((0xE0L <
       ((l_225 =
         (0xA787L
          ||
          l_251[(l_295 + 2)][(l_295 +
         6)])) ^
        p_92)), p_93)), p_94))
         ||
         ((l_251[(l_295 + 1)][(l_295 + 3)] =
           0x442AE9B4L) < 0xC048E1D8L)))
      {
        int16_t l_307 = 1L;
        int32_t l_331[9][9][3] =
        {
          {
     {
     0xED5BF0DDL, 0x6BBA4375L,
         0x6BBA4375L}
     ,
     {
     0L, (-1L), 0x5D116E59L}
     ,
     {
     0xCEC61A21L,
         0x7C8294B8L, 0x6BBA4375L}
     ,
     {
     0x0E7B4870L, (-5L), (-1L)}
     ,
     {
     0xCEC61A21L,
         0x6BBA4375L, 0x6F02A8A9L}
     ,
     {
     0L, (-5L), 0x5D116E59L}
     ,
     {
     0xED5BF0DDL,
         0x7C8294B8L, 0x6F02A8A9L}
     ,
     {
     0x0E7B4870L, (-1L), (-1L)}
     ,
     {
     0xED5BF0DDL,
         0x6BBA4375L, 0x6BBA4375L}
          }
          ,
          {
     {
     0L, (-1L), 0x5D116E59L}
     ,
     {
     0xCEC61A21L,
         0x7C8294B8L, 0x6BBA4375L}
     ,
     {
     0x0E7B4870L, (-5L), (-1L)}
     ,
     {
     0xCEC61A21L,
         0x6BBA4375L, 0x6F02A8A9L}
     ,
     {
     0L, (-5L), 0x5D116E59L}
     ,
     {
     0xED5BF0DDL,
         0x7C8294B8L, 0x6F02A8A9L}
     ,
     {
     0x0E7B4870L, (-1L), (-1L)}
     ,
     {
     0xED5BF0DDL,
         0x6BBA4375L, 0x6BBA4375L}
     ,
     {
     0L, (-1L), 0x5D116E59L}
          }
          ,
          {
     {
     0xCEC61A21L, 0x7C8294B8L,
         0x6BBA4375L}
     ,
     {
     0x0E7B4870L, (-5L), (-1L)}
     ,
     {
     0xCEC61A21L,
         0x6BBA4375L, 0x6F02A8A9L}
     ,
     {
     0L, (-5L), 0x5D116E59L}
     ,
     {
     0xED5BF0DDL,
         0x7C8294B8L, 0x6F02A8A9L}
     ,
     {
     0x0E7B4870L, (-1L), (-1L)}
     ,
     {
     0xED5BF0DDL,
         0x6BBA4375L, 0x6BBA4375L}
     ,
     {
     0L, (-1L), 0x5D116E59L}
     ,
     {
     0xCEC61A21L,
         0x7C8294B8L, 0x6BBA4375L}
          }
          ,
          {
     {
     0x0E7B4870L, (-5L), (-1L)}
     ,
     {
     0xCEC61A21L,
         0x6BBA4375L, 0x6F02A8A9L}
     ,
     {
     0L, (-5L), (-1L)}
     ,
     {
     0x7C8294B8L,
         0x44A49926L, 0x8ECCDEC7L}
     ,
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
     ,
     {
     0x7C8294B8L, (-4L), (-4L)}
     ,
     {
     0L, 0x14600C48L, (-1L)}
     ,
     {
     (-4L), 0x44A49926L, (-4L)}
     ,
     {
     (-1L), 5L, 0xB9BABAE2L}
          }
          ,
          {
     {
     (-4L), (-4L), 0x8ECCDEC7L}
     ,
     {
     0L, 5L, (-1L)}
     ,
     {
     0x7C8294B8L,
         0x44A49926L, 0x8ECCDEC7L}
     ,
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
     ,
     {
     0x7C8294B8L, (-4L), (-4L)}
     ,
     {
     0L, 0x14600C48L, (-1L)}
     ,
     {
     (-4L), 0x44A49926L, (-4L)}
     ,
     {
     (-1L), 5L, 0xB9BABAE2L}
     ,
     {
     (-4L), (-4L), 0x8ECCDEC7L}
          }
          ,
          {
     {
     0L, 5L, (-1L)}
     ,
     {
     0x7C8294B8L,
         0x44A49926L, 0x8ECCDEC7L}
     ,
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
     ,
     {
     0x7C8294B8L, (-4L), (-4L)}
     ,
     {
     0L, 0x14600C48L, (-1L)}
     ,
     {
     (-4L), 0x44A49926L, (-4L)}
     ,
     {
     (-1L), 5L, 0xB9BABAE2L}
     ,
     {
     (-4L), (-4L), 0x8ECCDEC7L}
     ,
     {
     0L, 5L, (-1L)}
          }
          ,
          {
     {
     0x7C8294B8L, 0x44A49926L,
         0x8ECCDEC7L}
     ,
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
     ,
     {
     0x7C8294B8L, (-4L), (-4L)}
     ,
     {
     0L, 0x14600C48L, (-1L)}
     ,
     {
     (-4L), 0x44A49926L, (-4L)}
     ,
     {
     (-1L), 5L, 0xB9BABAE2L}
     ,
     {
     (-4L), (-4L), 0x8ECCDEC7L}
     ,
     {
     0L, 5L, (-1L)}
     ,
     {
     0x7C8294B8L,
         0x44A49926L, 0x8ECCDEC7L}
          }
          ,
          {
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
     ,
     {
     0x7C8294B8L, (-4L), (-4L)}
     ,
     {
     0L, 0x14600C48L, (-1L)}
     ,
     {
     (-4L), 0x44A49926L, (-4L)}
     ,
     {
     (-1L), 5L, 0xB9BABAE2L}
     ,
     {
     (-4L), (-4L), 0x8ECCDEC7L}
     ,
     {
     0L, 5L, (-1L)}
     ,
     {
     0x7C8294B8L,
         0x44A49926L, 0x8ECCDEC7L}
     ,
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
          }
          ,
          {
     {
     0x7C8294B8L, (-4L), (-4L)}
     ,
     {
     0L, 0x14600C48L, (-1L)}
     ,
     {
     (-4L), 0x44A49926L, (-4L)}
     ,
     {
     (-1L), 5L, 0xB9BABAE2L}
     ,
     {
     (-4L), (-4L), 0x8ECCDEC7L}
     ,
     {
     0L, 5L, (-1L)}
     ,
     {
     0x7C8294B8L,
         0x44A49926L, 0x8ECCDEC7L}
     ,
     {
     (-1L), 0x14600C48L, 0xB9BABAE2L}
     ,
     {
     0x7C8294B8L, (-4L), (-4L)}
          }
        };
        int i, j, k;
        if (g_189)
          goto lbl_302;
        l_230
          =
          ((((safe_mul_func_uint8_t_u_u
       (l_224,
        (l_307 =
         (safe_mod_func_uint8_t_u_u
          (255UL,
           p_92))))) !=
      ((safe_lshift_func_int8_t_s_s
        ((p_92 >
          (safe_mod_func_uint64_t_u_u
           ((safe_mod_func_uint8_t_u_u
      (((safe_sub_func_uint64_t_u_u
         ((safe_mod_func_int64_t_s_s
           ((l_251[2][9] =
             ((((safe_mod_func_uint64_t_u_u (p_92, (safe_lshift_func_int8_t_s_s ((safe_mod_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u (((safe_lshift_func_int8_t_s_u ((~((safe_add_func_int8_t_s_s ((l_330 == ((p_94 < ((((p_93 || 6L) != (-1L)) > g_208[2]) >= p_94)) == p_93)), l_254[3][0][3])) | 0UL)), 1)) && l_279), 0L)), g_4[0][2])), 1)))) && p_93) <= (-5L)) || 0x57C1A50624BA6F3BLL)), 18446744073709551612UL)), p_93)) == p_93), l_331[8][6][1])), g_208[2]))), l_254[5][3][0])) | 1UL)) == p_94) <= (-1L));
      }
    else
      {
        int16_t l_337[3];
        int i;
        for (i = 0; i < 3; i++)
          l_337[i] = (-2L);
        g_208
          [2]
          =
          (l_332
           <=
           ((g_359 =
      (safe_rshift_func_int8_t_s_s
       ((((((((((safe_mod_func_int8_t_s_s
          (((g_208[2] !=
             ((l_337[1] =
        4294967294UL)
       &&
       ((g_357 =
         (l_356 =
          (safe_add_func_uint32_t_u_u
           ((safe_rshift_func_uint8_t_u_s ((safe_sub_func_int32_t_s_s ((p_92 != (0x43B4L == (l_355 = (safe_lshift_func_uint16_t_u_u (((((l_354 = (safe_unary_minus_func_int16_t_s ((safe_add_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_u (0xB2BBL, 6)) & (((safe_add_func_int32_t_s_s (p_93, 1L)) == 4294967295UL) == l_353)), g_208[1]))))) | 0x7B1FL) == 0xFEL) || p_92), p_92))))), l_225)), 5)), p_94)))) && l_358[3]))) >= l_251[(l_295 + 1)][(l_295 + 3)]), p_92)) <= g_208[0]) < g_208[2]) != 0x0E83303B9F7BD04FLL) | p_93) <= g_189) >= l_330) ^ l_224) <= 1L), g_236))) != g_236));
      }
    l_251
      [(l_295 + 2)][(l_295 + 6)] =
      (safe_lshift_func_uint8_t_u_u (p_92, 1));
    l_356 =
      (safe_sub_func_uint16_t_u_u
       ((0xDCL ^
         (((g_208[2] =
     (((safe_sub_func_int64_t_s_s
        ((((safe_add_func_int8_t_s_s
            (((safe_add_func_int32_t_s_s
        (0x17AFCBD4L,
         9UL)) != 0xC7L),
      (safe_sub_func_uint64_t_u_u
       (((1UL <=
          (1L <
           (safe_lshift_func_uint16_t_u_s
            ((safe_add_func_uint64_t_u_u (g_280, (0UL || (l_211 = 0xE64348B5L)))), 5)))) | l_230), g_357)))) | 0xAFCEL) && 7L), l_229)) <= l_353) | p_94)) != l_376) <= g_359)), p_93));
    for (l_353 = 0; (l_353 <= 3); l_353 += 1)
      {
        int32_t l_377 = 0xE64B3CA6L;
        int i, j, k;
        l_377 = l_254[(l_295 + 2)][l_353][l_353];
        return p_94;
      }
         }
       if (((safe_add_func_int16_t_s_s
      ((((safe_add_func_uint32_t_u_u
          ((((safe_rshift_func_int16_t_s_u
       (7L,
        (l_354 =
         ((safe_sub_func_uint16_t_u_u
           (0UL,
            ((l_295 =
       p_94) <
      ((safe_rshift_func_uint8_t_u_s
        (l_230,
         (l_254[6][7][3] !=
          0x9AL))) &
       (safe_lshift_func_int16_t_s_s
        ((g_4[1][7] & g_236),
         (safe_add_func_int64_t_s_s
          (((safe_add_func_uint16_t_u_u ((4294967286UL <= l_358[3]), l_230)) == g_208[2]), 0x3E78FA6BBBD3E55ALL)))))))) <= l_376)))) < 65532UL) | 1L), g_208[2])) >= g_208[2]) & l_230), 0x9C3CL)) && 0x2934253AL))
         {
    uint64_t l_404 = 18446744073709551615UL;
    l_356
      =
      (((safe_lshift_func_uint8_t_u_s
         (((safe_add_func_uint32_t_u_u
     (((safe_rshift_func_int16_t_s_u
        (0xAF4AL, 0)) < p_93),
      (safe_mod_func_int64_t_s_s
       (((l_404 |
          (((l_405 ^
      ((((+p_94)
         && (l_355 =
             (1UL == 0x6F29L))) ==
        1L) &
       ((safe_lshift_func_uint16_t_u_u (((p_92 & l_376) < g_98), l_279)) >= p_94))) & l_230) == g_236)) & 0x6EL), l_254[3][5][0])))) >= 1L), p_93)) | l_279) < 7L);
    if (l_211)
      goto lbl_412;
    if (((safe_mod_func_uint64_t_u_u
          ((0xED956FEEA5F8B7EBLL &
     (safe_lshift_func_int16_t_s_u
      ((((safe_mul_func_int16_t_s_s
          ((safe_lshift_func_uint8_t_u_u
            ((safe_add_func_uint16_t_u_u
       (((0x98BDL >=
          (p_94 ^
           (safe_sub_func_int16_t_s_s
            ((p_94
       || (+g_189)),
             (((g_209 =
         p_94) >= g_178)
       || p_94))))) <=
         ((safe_lshift_func_int8_t_s_s ((((p_93 == g_357) > g_280) ^ g_236), p_92)) && 0xACL)), g_99[1])), 3)), p_92)) >= g_359) < p_94), l_251[1][0]))), 0x0E271EE976597471LL)) ^ l_295))
      {
        uint64_t l_453 = 0x5A6B217372B41566LL;
        g_208
          [2]
          =
          ((safe_lshift_func_int8_t_s_u
     ((safe_mod_func_int32_t_s_s
       ((safe_rshift_func_int8_t_s_s
         ((safe_add_func_uint32_t_u_u
           ((5UL >= (!p_92)),
            (g_455 =
      (l_454[1] =
       (safe_sub_func_uint8_t_u_u
        ((((l_437[6][8][0]
            &&
            (((6UL >
        ((safe_lshift_func_uint8_t_u_s (((p_94 ^ (safe_add_func_int64_t_s_s (((safe_sub_func_uint16_t_u_u ((safe_lshift_func_uint16_t_u_s ((((safe_rshift_func_int8_t_s_s ((g_236 || (g_98 <= (safe_rshift_func_int16_t_s_s ((safe_unary_minus_func_uint8_t_u ((safe_sub_func_uint64_t_u_u ((((g_236 || l_254[1][5][0]) != 0xB5FB86B1F9055481LL) <= p_92), 18446744073709551615UL)))), 1)))), l_453)) & p_92) < 0UL), 11)), g_236)) & l_453), 0x5759DA75A76652DCLL))) <= p_94), g_4[1][6])) && p_93)) ^ 0x972D0B17C0A01B54LL) < p_94)) != l_230) ^ 1UL), g_357)))))), p_94)), g_280)), 7)) || l_210);
        if (p_94)
          break;
        return g_357;
      }
    else
      {
        return l_332;
      }
         }
       else
         {
    l_229
      =
      (safe_add_func_uint64_t_u_u
       (g_4[1][2], p_94));
         }
     }
   }


        for (l_295 = 3; (l_295 >= 0); l_295 -= 1)
   {
     int32_t l_330 = 8L;
     int i, j;
     if (((safe_rshift_func_uint8_t_u_u
    ((safe_rshift_func_uint16_t_u_s
      ((0xE0L <
        ((l_225 =
          (0xA787L
           || l_251[(l_295 + 2)][(l_295 + 6)])) ^
         p_92)), p_93)), p_94))
          ||
          ((l_251[(l_295 + 1)][(l_295 + 3)] =
     0x442AE9B4L) < 0xC048E1D8L)))
       {
         int16_t l_307 = 1L;
         int32_t l_331[9][9][3] =
         {
    {
      {
      0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
      ,
      {
      0L, (-1L), 0x5D116E59L}
      ,
      {
      0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
      ,
      {
      0x0E7B4870L, (-5L), (-1L)}
      ,
      {
      0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
      ,
      {
      0L, (-5L), 0x5D116E59L}
      ,
      {
      0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
      ,
      {
      0x0E7B4870L, (-1L), (-1L)}
      ,
      {
      0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
    }
    ,
    {
      {
      0L, (-1L), 0x5D116E59L}
      ,
      {
      0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
      ,
      {
      0x0E7B4870L, (-5L), (-1L)}
      ,
      {
      0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
      ,
      {
      0L, (-5L), 0x5D116E59L}
      ,
      {
      0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
      ,
      {
      0x0E7B4870L, (-1L), (-1L)}
      ,
      {
      0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
      ,
      {
      0L, (-1L), 0x5D116E59L}
    }
    ,
    {
      {
      0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
      ,
      {
      0x0E7B4870L, (-5L), (-1L)}
      ,
      {
      0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
      ,
      {
      0L, (-5L), 0x5D116E59L}
      ,
      {
      0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
      ,
      {
      0x0E7B4870L, (-1L), (-1L)}
      ,
      {
      0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
      ,
      {
      0L, (-1L), 0x5D116E59L}
      ,
      {
      0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
    }
    ,
    {
      {
      0x0E7B4870L, (-5L), (-1L)}
      ,
      {
      0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
      ,
      {
      0L, (-5L), (-1L)}
      ,
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
      ,
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
      ,
      {
      0x7C8294B8L, (-4L), (-4L)}
      ,
      {
      0L, 0x14600C48L, (-1L)}
      ,
      {
      (-4L), 0x44A49926L, (-4L)}
      ,
      {
      (-1L), 5L, 0xB9BABAE2L}
    }
    ,
    {
      {
      (-4L), (-4L), 0x8ECCDEC7L}
      ,
      {
      0L, 5L, (-1L)}
      ,
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
      ,
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
      ,
      {
      0x7C8294B8L, (-4L), (-4L)}
      ,
      {
      0L, 0x14600C48L, (-1L)}
      ,
      {
      (-4L), 0x44A49926L, (-4L)}
      ,
      {
      (-1L), 5L, 0xB9BABAE2L}
      ,
      {
      (-4L), (-4L), 0x8ECCDEC7L}
    }
    ,
    {
      {
      0L, 5L, (-1L)}
      ,
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
      ,
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
      ,
      {
      0x7C8294B8L, (-4L), (-4L)}
      ,
      {
      0L, 0x14600C48L, (-1L)}
      ,
      {
      (-4L), 0x44A49926L, (-4L)}
      ,
      {
      (-1L), 5L, 0xB9BABAE2L}
      ,
      {
      (-4L), (-4L), 0x8ECCDEC7L}
      ,
      {
      0L, 5L, (-1L)}
    }
    ,
    {
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
      ,
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
      ,
      {
      0x7C8294B8L, (-4L), (-4L)}
      ,
      {
      0L, 0x14600C48L, (-1L)}
      ,
      {
      (-4L), 0x44A49926L, (-4L)}
      ,
      {
      (-1L), 5L, 0xB9BABAE2L}
      ,
      {
      (-4L), (-4L), 0x8ECCDEC7L}
      ,
      {
      0L, 5L, (-1L)}
      ,
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
    }
    ,
    {
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
      ,
      {
      0x7C8294B8L, (-4L), (-4L)}
      ,
      {
      0L, 0x14600C48L, (-1L)}
      ,
      {
      (-4L), 0x44A49926L, (-4L)}
      ,
      {
      (-1L), 5L, 0xB9BABAE2L}
      ,
      {
      (-4L), (-4L), 0x8ECCDEC7L}
      ,
      {
      0L, 5L, (-1L)}
      ,
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
      ,
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
    }
    ,
    {
      {
      0x7C8294B8L, (-4L), (-4L)}
      ,
      {
      0L, 0x14600C48L, (-1L)}
      ,
      {
      (-4L), 0x44A49926L, (-4L)}
      ,
      {
      (-1L), 5L, 0xB9BABAE2L}
      ,
      {
      (-4L), (-4L), 0x8ECCDEC7L}
      ,
      {
      0L, 5L, (-1L)}
      ,
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
      ,
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
      ,
      {
      0x7C8294B8L, (-4L), (-4L)}
    }
         };
         int i, j, k;
         if (g_189)
    goto lbl_302;
         l_230
    =
    ((((safe_mul_func_uint8_t_u_u
        (l_224,
         (l_307 =
          (safe_mod_func_uint8_t_u_u
           (255UL,
     p_92))))) !=
       ((safe_lshift_func_int8_t_s_s
         ((p_92 >
           (safe_mod_func_uint64_t_u_u
     ((safe_mod_func_uint8_t_u_u
       (((safe_sub_func_uint64_t_u_u
          ((safe_mod_func_int64_t_s_s
            ((l_251[2][9] =
       ((((safe_mod_func_uint64_t_u_u (p_92, (safe_lshift_func_int8_t_s_s ((safe_mod_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u (((safe_lshift_func_int8_t_s_u ((~((safe_add_func_int8_t_s_s ((l_330 == ((p_94 < ((((p_93 || 6L) != (-1L)) > g_208[2]) >= p_94)) == p_93)), l_254[3][0][3])) | 0UL)), 1)) && l_279), 0L)), g_4[0][2])), 1)))) && p_93) <= (-5L)) || 0x57C1A50624BA6F3BLL)), 18446744073709551612UL)), p_93)) == p_93), l_331[8][6][1])), g_208[2]))), l_254[5][3][0])) | 1UL)) == p_94) <= (-1L));
       }
     else
       {
         int16_t l_337[3];
         int i;
         for (i = 0; i < 3; i++)
    l_337[i] = (-2L);
         g_208
    [2]
    =
    (l_332
     <=
     ((g_359 =
       (safe_rshift_func_int8_t_s_s
        ((((((((((safe_mod_func_int8_t_s_s
           (((g_208[2] !=
       ((l_337[1] = 4294967294UL)
        &&
        ((g_357 =
          (l_356 =
           (safe_add_func_uint32_t_u_u
            ((safe_rshift_func_uint8_t_u_s ((safe_sub_func_int32_t_s_s ((p_92 != (0x43B4L == (l_355 = (safe_lshift_func_uint16_t_u_u (((((l_354 = (safe_unary_minus_func_int16_t_s ((safe_add_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_u (0xB2BBL, 6)) & (((safe_add_func_int32_t_s_s (p_93, 1L)) == 4294967295UL) == l_353)), g_208[1]))))) | 0x7B1FL) == 0xFEL) || p_92), p_92))))), l_225)), 5)), p_94)))) && l_358[3]))) >= l_251[(l_295 + 1)][(l_295 + 3)]), p_92)) <= g_208[0]) < g_208[2]) != 0x0E83303B9F7BD04FLL) | p_93) <= g_189) >= l_330) ^ l_224) <= 1L), g_236))) != g_236));
       }
     l_251
       [(l_295 + 2)][(l_295 + 6)] =
       (safe_lshift_func_uint8_t_u_u (p_92, 1));
     l_356 =
       (safe_sub_func_uint16_t_u_u
        ((0xDCL ^
          (((g_208[2] =
      (((safe_sub_func_int64_t_s_s
         ((((safe_add_func_int8_t_s_s
      (((safe_add_func_int32_t_s_s
         (0x17AFCBD4L, 9UL)) != 0xC7L),
       (safe_sub_func_uint64_t_u_u
        (((1UL <=
           (1L <
            (safe_lshift_func_uint16_t_u_s
      ((safe_add_func_uint64_t_u_u
        (g_280,
         (0UL
          || (l_211 =
       0xE64348B5L)))),
       5)))) | l_230),
         g_357)))) | 0xAFCEL)
           && 7L),
          l_229)) <= l_353) | p_94)) != l_376) <=
    g_359)), p_93));
     for (l_353 = 0; (l_353 <= 3); l_353 += 1)
       {
         int32_t l_377 = 0xE64B3CA6L;
         int i, j, k;
         l_377 = l_254[(l_295 + 2)][l_353][l_353];
         return p_94;
       }
   }



        l_230
   =
   ((((safe_mul_func_uint8_t_u_u
       (l_224,
        (l_307 =
         (safe_mod_func_uint8_t_u_u (255UL, p_92))))) !=
      ((safe_lshift_func_int8_t_s_s
        ((p_92 >
          (safe_mod_func_uint64_t_u_u
    ((safe_mod_func_uint8_t_u_u
      (((safe_sub_func_uint64_t_u_u
         ((safe_mod_func_int64_t_s_s
           ((l_251[2][9] =
      ((((safe_mod_func_uint64_t_u_u
          (p_92,
           (safe_lshift_func_int8_t_s_s
            ((safe_mod_func_uint8_t_u_u
       ((safe_sub_func_uint32_t_u_u
         (((safe_lshift_func_int8_t_s_u ((~((safe_add_func_int8_t_s_s ((l_330 == ((p_94 < ((((p_93 || 6L) != (-1L)) > g_208[2]) >= p_94)) == p_93)), l_254[3][0][3])) | 0UL)), 1)) && l_279), 0L)), g_4[0][2])), 1)))) && p_93) <= (-5L)) || 0x57C1A50624BA6F3BLL)), 18446744073709551612UL)), p_93)) == p_93), l_331[8][6][1])), g_208[2]))), l_254[5][3][0])) | 1UL)) == p_94) <= (-1L));
      }
    else
      {
        int16_t l_337[3];
        int i;
        for (i = 0; i < 3; i++)
   l_337[i] = (-2L);
        for (l_295 = 3; (l_295 >= 0); l_295 -= 1)
   {
     int32_t l_330 = 8L;
     int i, j;
     if (((safe_rshift_func_uint8_t_u_u
    ((safe_rshift_func_uint16_t_u_s
      ((0xE0L <
        ((l_225 =
          (0xA787L
           || l_251[(l_295 + 2)][(l_295 + 6)])) ^
         p_92)), p_93)), p_94))
          ||
          ((l_251[(l_295 + 1)][(l_295 + 3)] =
     0x442AE9B4L) < 0xC048E1D8L)))
       {
         int16_t l_307 = 1L;
         int32_t l_331[9][9][3] =
         {
    {
      {
      0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
      ,
      {
      0L, (-1L), 0x5D116E59L}
      ,
      {
      0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
      ,
      {
      0x0E7B4870L, (-5L), (-1L)}
      ,
      {
      0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
      ,
      {
      0L, (-5L), 0x5D116E59L}
      ,
      {
      0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
      ,
      {
      0x0E7B4870L, (-1L), (-1L)}
      ,
      {
      0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
    }
    ,
    {
      {
      0L, (-1L), 0x5D116E59L}
      ,
      {
      0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
      ,
      {
      0x0E7B4870L, (-5L), (-1L)}
      ,
      {
      0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
      ,
      {
      0L, (-5L), 0x5D116E59L}
      ,
      {
      0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
      ,
      {
      0x0E7B4870L, (-1L), (-1L)}
      ,
      {
      0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
      ,
      {
      0L, (-1L), 0x5D116E59L}
    }
    ,
    {
      {
      0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
      ,
      {
      0x0E7B4870L, (-5L), (-1L)}
      ,
      {
      0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
      ,
      {
      0L, (-5L), 0x5D116E59L}
      ,
      {
      0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
      ,
      {
      0x0E7B4870L, (-1L), (-1L)}
      ,
      {
      0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
      ,
      {
      0L, (-1L), 0x5D116E59L}
      ,
      {
      0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
    }
    ,
    {
      {
      0x0E7B4870L, (-5L), (-1L)}
      ,
      {
      0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
      ,
      {
      0L, (-5L), (-1L)}
      ,
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
      ,
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
      ,
      {
      0x7C8294B8L, (-4L), (-4L)}
      ,
      {
      0L, 0x14600C48L, (-1L)}
      ,
      {
      (-4L), 0x44A49926L, (-4L)}
      ,
      {
      (-1L), 5L, 0xB9BABAE2L}
    }
    ,
    {
      {
      (-4L), (-4L), 0x8ECCDEC7L}
      ,
      {
      0L, 5L, (-1L)}
      ,
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
      ,
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
      ,
      {
      0x7C8294B8L, (-4L), (-4L)}
      ,
      {
      0L, 0x14600C48L, (-1L)}
      ,
      {
      (-4L), 0x44A49926L, (-4L)}
      ,
      {
      (-1L), 5L, 0xB9BABAE2L}
      ,
      {
      (-4L), (-4L), 0x8ECCDEC7L}
    }
    ,
    {
      {
      0L, 5L, (-1L)}
      ,
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
      ,
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
      ,
      {
      0x7C8294B8L, (-4L), (-4L)}
      ,
      {
      0L, 0x14600C48L, (-1L)}
      ,
      {
      (-4L), 0x44A49926L, (-4L)}
      ,
      {
      (-1L), 5L, 0xB9BABAE2L}
      ,
      {
      (-4L), (-4L), 0x8ECCDEC7L}
      ,
      {
      0L, 5L, (-1L)}
    }
    ,
    {
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
      ,
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
      ,
      {
      0x7C8294B8L, (-4L), (-4L)}
      ,
      {
      0L, 0x14600C48L, (-1L)}
      ,
      {
      (-4L), 0x44A49926L, (-4L)}
      ,
      {
      (-1L), 5L, 0xB9BABAE2L}
      ,
      {
      (-4L), (-4L), 0x8ECCDEC7L}
      ,
      {
      0L, 5L, (-1L)}
      ,
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
    }
    ,
    {
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
      ,
      {
      0x7C8294B8L, (-4L), (-4L)}
      ,
      {
      0L, 0x14600C48L, (-1L)}
      ,
      {
      (-4L), 0x44A49926L, (-4L)}
      ,
      {
      (-1L), 5L, 0xB9BABAE2L}
      ,
      {
      (-4L), (-4L), 0x8ECCDEC7L}
      ,
      {
      0L, 5L, (-1L)}
      ,
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
      ,
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
    }
    ,
    {
      {
      0x7C8294B8L, (-4L), (-4L)}
      ,
      {
      0L, 0x14600C48L, (-1L)}
      ,
      {
      (-4L), 0x44A49926L, (-4L)}
      ,
      {
      (-1L), 5L, 0xB9BABAE2L}
      ,
      {
      (-4L), (-4L), 0x8ECCDEC7L}
      ,
      {
      0L, 5L, (-1L)}
      ,
      {
      0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
      ,
      {
      (-1L), 0x14600C48L, 0xB9BABAE2L}
      ,
      {
      0x7C8294B8L, (-4L), (-4L)}
    }
         };
         int i, j, k;
         if (g_189)
    goto lbl_302;
         l_230
    =
    ((((safe_mul_func_uint8_t_u_u
        (l_224,
         (l_307 =
          (safe_mod_func_uint8_t_u_u
           (255UL,
     p_92))))) !=
       ((safe_lshift_func_int8_t_s_s
         ((p_92 >
           (safe_mod_func_uint64_t_u_u
     ((safe_mod_func_uint8_t_u_u
       (((safe_sub_func_uint64_t_u_u
          ((safe_mod_func_int64_t_s_s
            ((l_251[2][9] =
       ((((safe_mod_func_uint64_t_u_u (p_92, (safe_lshift_func_int8_t_s_s ((safe_mod_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u (((safe_lshift_func_int8_t_s_u ((~((safe_add_func_int8_t_s_s ((l_330 == ((p_94 < ((((p_93 || 6L) != (-1L)) > g_208[2]) >= p_94)) == p_93)), l_254[3][0][3])) | 0UL)), 1)) && l_279), 0L)), g_4[0][2])), 1)))) && p_93) <= (-5L)) || 0x57C1A50624BA6F3BLL)), 18446744073709551612UL)), p_93)) == p_93), l_331[8][6][1])), g_208[2]))), l_254[5][3][0])) | 1UL)) == p_94) <= (-1L));
       }
     else
       {
         int16_t l_337[3];
         int i;
         for (i = 0; i < 3; i++)
    l_337[i] = (-2L);
         g_208
    [2]
    =
    (l_332
     <=
     ((g_359 =
       (safe_rshift_func_int8_t_s_s
        ((((((((((safe_mod_func_int8_t_s_s
           (((g_208[2] !=
       ((l_337[1] = 4294967294UL)
        &&
        ((g_357 =
          (l_356 =
           (safe_add_func_uint32_t_u_u
            ((safe_rshift_func_uint8_t_u_s ((safe_sub_func_int32_t_s_s ((p_92 != (0x43B4L == (l_355 = (safe_lshift_func_uint16_t_u_u (((((l_354 = (safe_unary_minus_func_int16_t_s ((safe_add_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_u (0xB2BBL, 6)) & (((safe_add_func_int32_t_s_s (p_93, 1L)) == 4294967295UL) == l_353)), g_208[1]))))) | 0x7B1FL) == 0xFEL) || p_92), p_92))))), l_225)), 5)), p_94)))) && l_358[3]))) >= l_251[(l_295 + 1)][(l_295 + 3)]), p_92)) <= g_208[0]) < g_208[2]) != 0x0E83303B9F7BD04FLL) | p_93) <= g_189) >= l_330) ^ l_224) <= 1L), g_236))) != g_236));
       }
     l_251
       [(l_295 + 2)][(l_295 + 6)] =
       (safe_lshift_func_uint8_t_u_u (p_92, 1));
     l_356 =
       (safe_sub_func_uint16_t_u_u
        ((0xDCL ^
          (((g_208[2] =
      (((safe_sub_func_int64_t_s_s
         ((((safe_add_func_int8_t_s_s
      (((safe_add_func_int32_t_s_s
         (0x17AFCBD4L, 9UL)) != 0xC7L),
       (safe_sub_func_uint64_t_u_u
        (((1UL <=
           (1L <
            (safe_lshift_func_uint16_t_u_s
      ((safe_add_func_uint64_t_u_u
        (g_280,
         (0UL
          || (l_211 =
       0xE64348B5L)))),
       5)))) | l_230),
         g_357)))) | 0xAFCEL)
           && 7L),
          l_229)) <= l_353) | p_94)) != l_376) <=
    g_359)), p_93));
     for (l_353 = 0; (l_353 <= 3); l_353 += 1)
       {
         int32_t l_377 = 0xE64B3CA6L;
         int i, j, k;
         l_377 = l_254[(l_295 + 2)][l_353][l_353];
         return p_94;
       }
   }





        {
   int16_t l_307 = 1L;
   int32_t l_331[9][9][3] =
   {
     {
       {
       0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
       ,
       {
       0L, (-1L), 0x5D116E59L}
       ,
       {
       0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
       ,
       {
       0x0E7B4870L, (-5L), (-1L)}
       ,
       {
       0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
       ,
       {
       0L, (-5L), 0x5D116E59L}
       ,
       {
       0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
       ,
       {
       0x0E7B4870L, (-1L), (-1L)}
       ,
       {
       0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
     }
     ,
     {
       {
       0L, (-1L), 0x5D116E59L}
       ,
       {
       0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
       ,
       {
       0x0E7B4870L, (-5L), (-1L)}
       ,
       {
       0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
       ,
       {
       0L, (-5L), 0x5D116E59L}
       ,
       {
       0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
       ,
       {
       0x0E7B4870L, (-1L), (-1L)}
       ,
       {
       0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
       ,
       {
       0L, (-1L), 0x5D116E59L}
     }
     ,
     {
       {
       0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
       ,
       {
       0x0E7B4870L, (-5L), (-1L)}
       ,
       {
       0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
       ,
       {
       0L, (-5L), 0x5D116E59L}
       ,
       {
       0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
       ,
       {
       0x0E7B4870L, (-1L), (-1L)}
       ,
       {
       0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
       ,
       {
       0L, (-1L), 0x5D116E59L}
       ,
       {
       0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
     }
     ,
     {
       {
       0x0E7B4870L, (-5L), (-1L)}
       ,
       {
       0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
       ,
       {
       0L, (-5L), (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
     }
     ,
     {
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
     }
     ,
     {
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
     }
     ,
     {
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
     }
     ,
     {
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
     }
     ,
     {
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
     }
   };
   int i, j, k;
   if (g_189)
     goto lbl_302;
   l_230
     =
     ((((safe_mul_func_uint8_t_u_u
         (l_224,
          (l_307 =
    (safe_mod_func_uint8_t_u_u (255UL, p_92)))))
        !=
        ((safe_lshift_func_int8_t_s_s
          ((p_92 >
     (safe_mod_func_uint64_t_u_u
      ((safe_mod_func_uint8_t_u_u
        (((safe_sub_func_uint64_t_u_u
           ((safe_mod_func_int64_t_s_s
      ((l_251[2][9] =
        ((((safe_mod_func_uint64_t_u_u
            (p_92,
      (safe_lshift_func_int8_t_s_s
       ((safe_mod_func_uint8_t_u_u
         ((safe_sub_func_uint32_t_u_u (((safe_lshift_func_int8_t_s_u ((~((safe_add_func_int8_t_s_s ((l_330 == ((p_94 < ((((p_93 || 6L) != (-1L)) > g_208[2]) >= p_94)) == p_93)), l_254[3][0][3])) | 0UL)), 1)) && l_279), 0L)), g_4[0][2])), 1)))) && p_93) <= (-5L)) || 0x57C1A50624BA6F3BLL)), 18446744073709551612UL)), p_93)) == p_93), l_331[8][6][1])), g_208[2]))), l_254[5][3][0])) | 1UL)) == p_94) <= (-1L));
        }


      }


    l_211
      =
      (safe_rshift_func_uint16_t_u_u
       ((g_178 !=
         ((g_99[3] =
    (safe_mod_func_uint16_t_u_u
     ((((l_210 =
         (safe_lshift_func_uint16_t_u_u
          ((~
     (safe_sub_func_uint32_t_u_u
      (p_92,
       (g_189 |
        ((safe_mod_func_uint64_t_u_u
          (((p_94 =
      (((safe_mul_func_uint16_t_u_u
         (0x4C97L,
          ((safe_lshift_func_int16_t_s_u
            ((g_209 =
       (g_208[2] =
        (~
         (safe_lshift_func_uint8_t_u_u
          (((((safe_add_func_int8_t_s_s ((8UL && g_98), (65533UL <= p_92))) >= 0xC2FFDF52C73AE872LL) != l_173) > p_92), l_173))))), 5)) > p_92))) & 0xF2569BDC76872175LL) > 0x8814L)) | l_173), l_173)) | 0xB29FL))))), p_93))) ^ 0UL) != p_93), l_173))) ^ g_189)), 1));




    {
      return l_211;
    }


    for (l_353 = 0; (l_353 <= 3); l_353 += 1)
      {
        int32_t l_377 = 0xE64B3CA6L;
        int i, j, k;
        l_377 = l_254[(l_295 + 2)][l_353][l_353];
        if (((safe_rshift_func_uint8_t_u_u
       ((safe_rshift_func_uint16_t_u_s
         ((0xE0L <
    ((l_225 =
      (0xA787L
       || l_251[(l_295 + 2)][(l_295 + 6)])) ^
     p_92)), p_93)), p_94))
      || ((l_251[(l_295 + 1)][(l_295 + 3)] = 0x442AE9B4L)
          < 0xC048E1D8L)))
   {
     int16_t l_307 = 1L;
     int32_t l_331[9][9][3] =
     {
       {
         {
         0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
         ,
         {
         0L, (-1L), 0x5D116E59L}
         ,
         {
         0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
         ,
         {
         0x0E7B4870L, (-5L), (-1L)}
         ,
         {
         0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
         ,
         {
         0L, (-5L), 0x5D116E59L}
         ,
         {
         0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
         ,
         {
         0x0E7B4870L, (-1L), (-1L)}
         ,
         {
         0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
       }
       ,
       {
         {
         0L, (-1L), 0x5D116E59L}
         ,
         {
         0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
         ,
         {
         0x0E7B4870L, (-5L), (-1L)}
         ,
         {
         0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
         ,
         {
         0L, (-5L), 0x5D116E59L}
         ,
         {
         0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
         ,
         {
         0x0E7B4870L, (-1L), (-1L)}
         ,
         {
         0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
         ,
         {
         0L, (-1L), 0x5D116E59L}
       }
       ,
       {
         {
         0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
         ,
         {
         0x0E7B4870L, (-5L), (-1L)}
         ,
         {
         0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
         ,
         {
         0L, (-5L), 0x5D116E59L}
         ,
         {
         0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
         ,
         {
         0x0E7B4870L, (-1L), (-1L)}
         ,
         {
         0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
         ,
         {
         0L, (-1L), 0x5D116E59L}
         ,
         {
         0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
       }
       ,
       {
         {
         0x0E7B4870L, (-5L), (-1L)}
         ,
         {
         0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
         ,
         {
         0L, (-5L), (-1L)}
         ,
         {
         0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
         ,
         {
         (-1L), 0x14600C48L, 0xB9BABAE2L}
         ,
         {
         0x7C8294B8L, (-4L), (-4L)}
         ,
         {
         0L, 0x14600C48L, (-1L)}
         ,
         {
         (-4L), 0x44A49926L, (-4L)}
         ,
         {
         (-1L), 5L, 0xB9BABAE2L}
       }
       ,
       {
         {
         (-4L), (-4L), 0x8ECCDEC7L}
         ,
         {
         0L, 5L, (-1L)}
         ,
         {
         0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
         ,
         {
         (-1L), 0x14600C48L, 0xB9BABAE2L}
         ,
         {
         0x7C8294B8L, (-4L), (-4L)}
         ,
         {
         0L, 0x14600C48L, (-1L)}
         ,
         {
         (-4L), 0x44A49926L, (-4L)}
         ,
         {
         (-1L), 5L, 0xB9BABAE2L}
         ,
         {
         (-4L), (-4L), 0x8ECCDEC7L}
       }
       ,
       {
         {
         0L, 5L, (-1L)}
         ,
         {
         0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
         ,
         {
         (-1L), 0x14600C48L, 0xB9BABAE2L}
         ,
         {
         0x7C8294B8L, (-4L), (-4L)}
         ,
         {
         0L, 0x14600C48L, (-1L)}
         ,
         {
         (-4L), 0x44A49926L, (-4L)}
         ,
         {
         (-1L), 5L, 0xB9BABAE2L}
         ,
         {
         (-4L), (-4L), 0x8ECCDEC7L}
         ,
         {
         0L, 5L, (-1L)}
       }
       ,
       {
         {
         0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
         ,
         {
         (-1L), 0x14600C48L, 0xB9BABAE2L}
         ,
         {
         0x7C8294B8L, (-4L), (-4L)}
         ,
         {
         0L, 0x14600C48L, (-1L)}
         ,
         {
         (-4L), 0x44A49926L, (-4L)}
         ,
         {
         (-1L), 5L, 0xB9BABAE2L}
         ,
         {
         (-4L), (-4L), 0x8ECCDEC7L}
         ,
         {
         0L, 5L, (-1L)}
         ,
         {
         0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       }
       ,
       {
         {
         (-1L), 0x14600C48L, 0xB9BABAE2L}
         ,
         {
         0x7C8294B8L, (-4L), (-4L)}
         ,
         {
         0L, 0x14600C48L, (-1L)}
         ,
         {
         (-4L), 0x44A49926L, (-4L)}
         ,
         {
         (-1L), 5L, 0xB9BABAE2L}
         ,
         {
         (-4L), (-4L), 0x8ECCDEC7L}
         ,
         {
         0L, 5L, (-1L)}
         ,
         {
         0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
         ,
         {
         (-1L), 0x14600C48L, 0xB9BABAE2L}
       }
       ,
       {
         {
         0x7C8294B8L, (-4L), (-4L)}
         ,
         {
         0L, 0x14600C48L, (-1L)}
         ,
         {
         (-4L), 0x44A49926L, (-4L)}
         ,
         {
         (-1L), 5L, 0xB9BABAE2L}
         ,
         {
         (-4L), (-4L), 0x8ECCDEC7L}
         ,
         {
         0L, 5L, (-1L)}
         ,
         {
         0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
         ,
         {
         (-1L), 0x14600C48L, 0xB9BABAE2L}
         ,
         {
         0x7C8294B8L, (-4L), (-4L)}
       }
     };
     int i, j, k;
     if (g_189)
       goto lbl_302;
     l_230
       =
       ((((safe_mul_func_uint8_t_u_u
    (l_224,
     (l_307 =
      (safe_mod_func_uint8_t_u_u (255UL, p_92)))))
          !=
          ((safe_lshift_func_int8_t_s_s
     ((p_92 >
       (safe_mod_func_uint64_t_u_u
        ((safe_mod_func_uint8_t_u_u
          (((safe_sub_func_uint64_t_u_u
      ((safe_mod_func_int64_t_s_s
        ((l_251[2][9] =
          ((((safe_mod_func_uint64_t_u_u
       (p_92,
        (safe_lshift_func_int8_t_s_s
         ((safe_mod_func_uint8_t_u_u
           ((safe_sub_func_uint32_t_u_u (((safe_lshift_func_int8_t_s_u ((~((safe_add_func_int8_t_s_s ((l_330 == ((p_94 < ((((p_93 || 6L) != (-1L)) > g_208[2]) >= p_94)) == p_93)), l_254[3][0][3])) | 0UL)), 1)) && l_279), 0L)), g_4[0][2])), 1)))) && p_93) <= (-5L)) || 0x57C1A50624BA6F3BLL)), 18446744073709551612UL)), p_93)) == p_93), l_331[8][6][1])), g_208[2]))), l_254[5][3][0])) | 1UL)) == p_94) <= (-1L));
   }
        else
   {
     int16_t l_337[3];
     int i;
     for (i = 0; i < 3; i++)
       l_337[i] = (-2L);
     g_208
       [2]
       =
       (l_332
        <=
        ((g_359 =
          (safe_rshift_func_int8_t_s_s
    ((((((((((safe_mod_func_int8_t_s_s
       (((g_208[2] !=
          ((l_337[1] = 4294967294UL)
           &&
           ((g_357 =
      (l_356 =
       (safe_add_func_uint32_t_u_u
        ((safe_rshift_func_uint8_t_u_s ((safe_sub_func_int32_t_s_s ((p_92 != (0x43B4L == (l_355 = (safe_lshift_func_uint16_t_u_u (((((l_354 = (safe_unary_minus_func_int16_t_s ((safe_add_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_u (0xB2BBL, 6)) & (((safe_add_func_int32_t_s_s (p_93, 1L)) == 4294967295UL) == l_353)), g_208[1]))))) | 0x7B1FL) == 0xFEL) || p_92), p_92))))), l_225)), 5)), p_94)))) && l_358[3]))) >= l_251[(l_295 + 1)][(l_295 + 3)]), p_92)) <= g_208[0]) < g_208[2]) != 0x0E83303B9F7BD04FLL) | p_93) <= g_189) >= l_330) ^ l_224) <= 1L), g_236))) != g_236));
   }



        return p_94;
      }
    l_251
      [(l_295 + 2)][(l_295 + 6)] =
      (safe_lshift_func_uint8_t_u_u (p_92, 1));



  }
       {
  uint32_t l_332 = 3UL;
  int64_t l_353 = 0xD4DE7019B247C13DLL;
  int32_t l_355 = 0xEEFD7E30L;
  int32_t l_356 = (-5L);
  uint32_t l_358[4] =
  {
  4294967287UL, 4294967287UL, 4294967287UL, 4294967287UL};
  int16_t l_437[7][9][1] =
  {
    {
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
    }
    ,
    {
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
    }
    ,
    {
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
    }
    ,
    {
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
    }
    ,
    {
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
    }
    ,
    {
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
    }
    ,
    {
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
    }
  };
  int i, j, k;
  for (l_295 = 3; (l_295 >= 0); l_295 -= 1)
    {
      int32_t l_330 = 8L;
      int i, j;
      if (((safe_rshift_func_uint8_t_u_u
     ((safe_rshift_func_uint16_t_u_s
       ((0xE0L <
         ((l_225 =
    (0xA787L
     || l_251[(l_295 + 2)][(l_295 + 6)])) ^
          p_92)), p_93)), p_94))
    || ((l_251[(l_295 + 1)][(l_295 + 3)] = 0x442AE9B4L) <
        0xC048E1D8L)))
        {
   int16_t l_307 = 1L;
   int32_t l_331[9][9][3] =
   {
     {
       {
       0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
       ,
       {
       0L, (-1L), 0x5D116E59L}
       ,
       {
       0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
       ,
       {
       0x0E7B4870L, (-5L), (-1L)}
       ,
       {
       0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
       ,
       {
       0L, (-5L), 0x5D116E59L}
       ,
       {
       0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
       ,
       {
       0x0E7B4870L, (-1L), (-1L)}
       ,
       {
       0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
     }
     ,
     {
       {
       0L, (-1L), 0x5D116E59L}
       ,
       {
       0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
       ,
       {
       0x0E7B4870L, (-5L), (-1L)}
       ,
       {
       0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
       ,
       {
       0L, (-5L), 0x5D116E59L}
       ,
       {
       0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
       ,
       {
       0x0E7B4870L, (-1L), (-1L)}
       ,
       {
       0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
       ,
       {
       0L, (-1L), 0x5D116E59L}
     }
     ,
     {
       {
       0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
       ,
       {
       0x0E7B4870L, (-5L), (-1L)}
       ,
       {
       0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
       ,
       {
       0L, (-5L), 0x5D116E59L}
       ,
       {
       0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
       ,
       {
       0x0E7B4870L, (-1L), (-1L)}
       ,
       {
       0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
       ,
       {
       0L, (-1L), 0x5D116E59L}
       ,
       {
       0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
     }
     ,
     {
       {
       0x0E7B4870L, (-5L), (-1L)}
       ,
       {
       0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
       ,
       {
       0L, (-5L), (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
     }
     ,
     {
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
     }
     ,
     {
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
     }
     ,
     {
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
     }
     ,
     {
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
     }
     ,
     {
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
     }
   };
   int i, j, k;
   if (g_189)
     goto lbl_302;
   l_230
     =
     ((((safe_mul_func_uint8_t_u_u
         (l_224,
          (l_307 =
    (safe_mod_func_uint8_t_u_u (255UL, p_92)))))
        !=
        ((safe_lshift_func_int8_t_s_s
          ((p_92 >
     (safe_mod_func_uint64_t_u_u
      ((safe_mod_func_uint8_t_u_u
        (((safe_sub_func_uint64_t_u_u
           ((safe_mod_func_int64_t_s_s
      ((l_251[2][9] =
        ((((safe_mod_func_uint64_t_u_u
            (p_92,
      (safe_lshift_func_int8_t_s_s
       ((safe_mod_func_uint8_t_u_u
         ((safe_sub_func_uint32_t_u_u (((safe_lshift_func_int8_t_s_u ((~((safe_add_func_int8_t_s_s ((l_330 == ((p_94 < ((((p_93 || 6L) != (-1L)) > g_208[2]) >= p_94)) == p_93)), l_254[3][0][3])) | 0UL)), 1)) && l_279), 0L)), g_4[0][2])), 1)))) && p_93) <= (-5L)) || 0x57C1A50624BA6F3BLL)), 18446744073709551612UL)), p_93)) == p_93), l_331[8][6][1])), g_208[2]))), l_254[5][3][0])) | 1UL)) == p_94) <= (-1L));
        }
      else
        {
   int16_t l_337[3];
   int i;
   for (i = 0; i < 3; i++)
     l_337[i] = (-2L);
   g_208
     [2]
     =
     (l_332
      <=
      ((g_359 =
        (safe_rshift_func_int8_t_s_s
         ((((((((((safe_mod_func_int8_t_s_s
     (((g_208[2] !=
        ((l_337[1] = 4294967294UL)
         &&
         ((g_357 =
           (l_356 =
            (safe_add_func_uint32_t_u_u
      ((safe_rshift_func_uint8_t_u_s
        ((safe_sub_func_int32_t_s_s
          ((p_92 !=
            (0x43B4L ==
             (l_355 =
       (safe_lshift_func_uint16_t_u_u
        (((((l_354 =
             (safe_unary_minus_func_int16_t_s
              ((safe_add_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_u (0xB2BBL, 6)) & (((safe_add_func_int32_t_s_s (p_93, 1L)) == 4294967295UL) == l_353)), g_208[1]))))) | 0x7B1FL) == 0xFEL) || p_92), p_92))))), l_225)), 5)), p_94)))) && l_358[3]))) >= l_251[(l_295 + 1)][(l_295 + 3)]), p_92)) <= g_208[0]) < g_208[2]) != 0x0E83303B9F7BD04FLL) | p_93) <= g_189) >= l_330) ^ l_224) <= 1L), g_236))) != g_236));
        }
      l_251
        [(l_295 + 2)][(l_295 + 6)] =
        (safe_lshift_func_uint8_t_u_u (p_92, 1));
      l_356 =
        (safe_sub_func_uint16_t_u_u
         ((0xDCL ^
    (((g_208[2] =
       (((safe_sub_func_int64_t_s_s
          ((((safe_add_func_int8_t_s_s
       (((safe_add_func_int32_t_s_s
          (0x17AFCBD4L, 9UL)) != 0xC7L),
        (safe_sub_func_uint64_t_u_u
         (((1UL <=
     (1L <
      (safe_lshift_func_uint16_t_u_s
       ((safe_add_func_uint64_t_u_u
         (g_280,
          (0UL
           || (l_211 =
        0xE64348B5L)))),
        5)))) | l_230),
          g_357)))) | 0xAFCEL)
     && 7L),
    l_229)) <= l_353) | p_94)) != l_376) <=
     g_359)), p_93));
      for (l_353 = 0; (l_353 <= 3); l_353 += 1)
        {
   int32_t l_377 = 0xE64B3CA6L;
   int i, j, k;
   l_377 = l_254[(l_295 + 2)][l_353][l_353];
   return p_94;
        }
    }
  if (((safe_add_func_int16_t_s_s
        ((((safe_add_func_uint32_t_u_u
     ((((safe_rshift_func_int16_t_s_u
         (7L,
          (l_354 =
    ((safe_sub_func_uint16_t_u_u
      (0UL,
       ((l_295 =
         p_94) <
        ((safe_rshift_func_uint8_t_u_s
          (l_230,
           (l_254[6][7][3] !=
     0x9AL))) &
         (safe_lshift_func_int16_t_s_s
          ((g_4[1][7] & g_236),
           (safe_add_func_int64_t_s_s
     (((safe_add_func_uint16_t_u_u
        ((4294967286UL <= l_358[3]),
         l_230)) == g_208[2]),
      0x3E78FA6BBBD3E55ALL)))))))) <=
     l_376)))) < 65532UL) | 1L),
      g_208[2])) >= g_208[2]) & l_230), 0x9C3CL))
       && 0x2934253AL))
    {
      uint64_t l_404 = 18446744073709551615UL;
      l_356
        =
        (((safe_lshift_func_uint8_t_u_s
    (((safe_add_func_uint32_t_u_u
       (((safe_rshift_func_int16_t_s_u (0xAF4AL, 0)) <
         p_93),
        (safe_mod_func_int64_t_s_s
         (((l_404 |
     (((l_405 ^
        ((((+p_94)
           && (l_355 =
        (1UL == 0x6F29L))) ==
          1L) &
         ((safe_lshift_func_uint16_t_u_u
           (((p_92 & l_376) < g_98),
     l_279)) >= p_94))) & l_230) ==
      g_236)) & 0x6EL), l_254[3][5][0])))) >= 1L),
     p_93)) | l_279) < 7L);
      if (l_211)
        goto lbl_412;
      if (((safe_mod_func_uint64_t_u_u
     ((0xED956FEEA5F8B7EBLL &
       (safe_lshift_func_int16_t_s_u
        ((((safe_mul_func_int16_t_s_s
     ((safe_lshift_func_uint8_t_u_u
       ((safe_add_func_uint16_t_u_u
         (((0x98BDL >=
     (p_94 ^
      (safe_sub_func_int16_t_s_s
       ((p_94
         || (+g_189)),
        (((g_209 = p_94) >= g_178)
         || p_94))))) <=
           ((safe_lshift_func_int8_t_s_s
      ((((p_93 == g_357) > g_280) ^ g_236),
       p_92))
     && 0xACL)), g_99[1])), 3)),
      p_92)) >= g_359) < p_94), l_251[1][0]))),
      0x0E271EE976597471LL)) ^ l_295))
        {
   uint64_t l_453 = 0x5A6B217372B41566LL;
   g_208
     [2]
     =
     ((safe_lshift_func_int8_t_s_u
       ((safe_mod_func_int32_t_s_s
         ((safe_rshift_func_int8_t_s_s
    ((safe_add_func_uint32_t_u_u
      ((5UL >= (!p_92)),
       (g_455 =
        (l_454[1] =
         (safe_sub_func_uint8_t_u_u
          ((((l_437[6][8][0]
       &&
       (((6UL >
          ((safe_lshift_func_uint8_t_u_s
            (((p_94 ^
        (safe_add_func_int64_t_s_s
         (((safe_sub_func_uint16_t_u_u ((safe_lshift_func_uint16_t_u_s ((((safe_rshift_func_int8_t_s_s ((g_236 || (g_98 <= (safe_rshift_func_int16_t_s_s ((safe_unary_minus_func_uint8_t_u ((safe_sub_func_uint64_t_u_u ((((g_236 || l_254[1][5][0]) != 0xB5FB86B1F9055481LL) <= p_92), 18446744073709551615UL)))), 1)))), l_453)) & p_92) < 0UL), 11)), g_236)) & l_453), 0x5759DA75A76652DCLL))) <= p_94), g_4[1][6])) && p_93)) ^ 0x972D0B17C0A01B54LL) < p_94)) != l_230) ^ 1UL), g_357)))))), p_94)), g_280)), 7)) || l_210);
   if (p_94)
     break;
   return g_357;
        }
      else
        {
   return l_332;
        }
    }
  else
    {
      l_229 = (safe_add_func_uint64_t_u_u (g_4[1][2], p_94));
    }
       }



       if (((safe_add_func_int16_t_s_s
      ((((safe_add_func_uint32_t_u_u
   ((((safe_rshift_func_int16_t_s_u
       (7L,
        (l_354 =
         ((safe_sub_func_uint16_t_u_u
    (0UL,
     ((l_295 =
       p_94) <
      ((safe_rshift_func_uint8_t_u_s
        (l_230,
         (l_254[6][7][3] !=
          0x9AL))) &
       (safe_lshift_func_int16_t_s_s
        ((g_4[1][7] & g_236),
         (safe_add_func_int64_t_s_s
          (((safe_add_func_uint16_t_u_u
      ((4294967286UL <= l_358[3]),
       l_230)) == g_208[2]),
           0x3E78FA6BBBD3E55ALL)))))))) <=
          l_376)))) < 65532UL) | 1L),
    g_208[2])) >= g_208[2]) & l_230), 0x9C3CL))
     && 0x2934253AL))
  {
    uint64_t l_404 = 18446744073709551615UL;
    l_356 = (((safe_lshift_func_uint8_t_u_s (((safe_add_func_uint32_t_u_u (((safe_rshift_func_int16_t_s_u (0xAF4AL, 0)) < p_93), (safe_mod_func_int64_t_s_s (((l_404 | (((l_405 ^ ((((+p_94) && (l_355 = (1UL == 0x6F29L))) == 1L) & ((safe_lshift_func_uint16_t_u_u (((p_92 & l_376) < g_98), l_279)) >= p_94))) & l_230) == g_236)) & 0x6EL), l_254[3][5][0])))) >= 1L), p_93)) | l_279) < 7L);
    {
      return l_211;
    }



    if (l_211)
      goto lbl_412;


  }
       else
  {
    l_229 = (safe_add_func_uint64_t_u_u (g_4[1][2], p_94));
  }
       {
  uint32_t l_332 = 3UL;
  int64_t l_353 = 0xD4DE7019B247C13DLL;
  int32_t l_355 = 0xEEFD7E30L;
  int32_t l_356 = (-5L);
  uint32_t l_358[4] =
  {
  4294967287UL, 4294967287UL, 4294967287UL, 4294967287UL};
  int16_t l_437[7][9][1] =
  {
    {
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
    }
    ,
    {
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
    }
    ,
    {
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
    }
    ,
    {
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
    }
    ,
    {
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
    }
    ,
    {
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
    }
    ,
    {
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
      ,
      {
      (-7L)}
      ,
      {
      0L}
      ,
      {
      (-7L)}
      ,
      {
      0xB237L}
      ,
      {
      0L}
      ,
      {
      0xB237L}
    }
  };
  int i, j, k;
  for (l_295 = 3; (l_295 >= 0); l_295 -= 1)
    {
      int32_t l_330 = 8L;
      int i, j;
      if (((safe_rshift_func_uint8_t_u_u
     ((safe_rshift_func_uint16_t_u_s
       ((0xE0L <
         ((l_225 =
    (0xA787L
     || l_251[(l_295 + 2)][(l_295 + 6)])) ^
          p_92)), p_93)), p_94))
    || ((l_251[(l_295 + 1)][(l_295 + 3)] = 0x442AE9B4L) <
        0xC048E1D8L)))
        {
   int16_t l_307 = 1L;
   int32_t l_331[9][9][3] =
   {
     {
       {
       0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
       ,
       {
       0L, (-1L), 0x5D116E59L}
       ,
       {
       0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
       ,
       {
       0x0E7B4870L, (-5L), (-1L)}
       ,
       {
       0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
       ,
       {
       0L, (-5L), 0x5D116E59L}
       ,
       {
       0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
       ,
       {
       0x0E7B4870L, (-1L), (-1L)}
       ,
       {
       0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
     }
     ,
     {
       {
       0L, (-1L), 0x5D116E59L}
       ,
       {
       0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
       ,
       {
       0x0E7B4870L, (-5L), (-1L)}
       ,
       {
       0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
       ,
       {
       0L, (-5L), 0x5D116E59L}
       ,
       {
       0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
       ,
       {
       0x0E7B4870L, (-1L), (-1L)}
       ,
       {
       0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
       ,
       {
       0L, (-1L), 0x5D116E59L}
     }
     ,
     {
       {
       0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
       ,
       {
       0x0E7B4870L, (-5L), (-1L)}
       ,
       {
       0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
       ,
       {
       0L, (-5L), 0x5D116E59L}
       ,
       {
       0xED5BF0DDL, 0x7C8294B8L, 0x6F02A8A9L}
       ,
       {
       0x0E7B4870L, (-1L), (-1L)}
       ,
       {
       0xED5BF0DDL, 0x6BBA4375L, 0x6BBA4375L}
       ,
       {
       0L, (-1L), 0x5D116E59L}
       ,
       {
       0xCEC61A21L, 0x7C8294B8L, 0x6BBA4375L}
     }
     ,
     {
       {
       0x0E7B4870L, (-5L), (-1L)}
       ,
       {
       0xCEC61A21L, 0x6BBA4375L, 0x6F02A8A9L}
       ,
       {
       0L, (-5L), (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
     }
     ,
     {
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
     }
     ,
     {
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
     }
     ,
     {
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
     }
     ,
     {
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
     }
     ,
     {
       {
       0x7C8294B8L, (-4L), (-4L)}
       ,
       {
       0L, 0x14600C48L, (-1L)}
       ,
       {
       (-4L), 0x44A49926L, (-4L)}
       ,
       {
       (-1L), 5L, 0xB9BABAE2L}
       ,
       {
       (-4L), (-4L), 0x8ECCDEC7L}
       ,
       {
       0L, 5L, (-1L)}
       ,
       {
       0x7C8294B8L, 0x44A49926L, 0x8ECCDEC7L}
       ,
       {
       (-1L), 0x14600C48L, 0xB9BABAE2L}
       ,
       {
       0x7C8294B8L, (-4L), (-4L)}
     }
   };
   int i, j, k;
   if (g_189)
     goto lbl_302;
   l_230
     =
     ((((safe_mul_func_uint8_t_u_u
         (l_224,
          (l_307 =
    (safe_mod_func_uint8_t_u_u (255UL, p_92)))))
        !=
        ((safe_lshift_func_int8_t_s_s
          ((p_92 >
     (safe_mod_func_uint64_t_u_u
      ((safe_mod_func_uint8_t_u_u
        (((safe_sub_func_uint64_t_u_u
           ((safe_mod_func_int64_t_s_s
      ((l_251[2][9] =
        ((((safe_mod_func_uint64_t_u_u
            (p_92,
      (safe_lshift_func_int8_t_s_s
       ((safe_mod_func_uint8_t_u_u
         ((safe_sub_func_uint32_t_u_u (((safe_lshift_func_int8_t_s_u ((~((safe_add_func_int8_t_s_s ((l_330 == ((p_94 < ((((p_93 || 6L) != (-1L)) > g_208[2]) >= p_94)) == p_93)), l_254[3][0][3])) | 0UL)), 1)) && l_279), 0L)), g_4[0][2])), 1)))) && p_93) <= (-5L)) || 0x57C1A50624BA6F3BLL)), 18446744073709551612UL)), p_93)) == p_93), l_331[8][6][1])), g_208[2]))), l_254[5][3][0])) | 1UL)) == p_94) <= (-1L));
        }
      else
        {
   int16_t l_337[3];
   int i;
   for (i = 0; i < 3; i++)
     l_337[i] = (-2L);
   g_208
     [2]
     =
     (l_332
      <=
      ((g_359 =
        (safe_rshift_func_int8_t_s_s
         ((((((((((safe_mod_func_int8_t_s_s
     (((g_208[2] !=
        ((l_337[1] = 4294967294UL)
         &&
         ((g_357 =
           (l_356 =
            (safe_add_func_uint32_t_u_u
      ((safe_rshift_func_uint8_t_u_s
        ((safe_sub_func_int32_t_s_s
          ((p_92 !=
            (0x43B4L ==
             (l_355 =
       (safe_lshift_func_uint16_t_u_u
        (((((l_354 =
             (safe_unary_minus_func_int16_t_s
              ((safe_add_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_u (0xB2BBL, 6)) & (((safe_add_func_int32_t_s_s (p_93, 1L)) == 4294967295UL) == l_353)), g_208[1]))))) | 0x7B1FL) == 0xFEL) || p_92), p_92))))), l_225)), 5)), p_94)))) && l_358[3]))) >= l_251[(l_295 + 1)][(l_295 + 3)]), p_92)) <= g_208[0]) < g_208[2]) != 0x0E83303B9F7BD04FLL) | p_93) <= g_189) >= l_330) ^ l_224) <= 1L), g_236))) != g_236));
        }
      l_251
        [(l_295 + 2)][(l_295 + 6)] =
        (safe_lshift_func_uint8_t_u_u (p_92, 1));
      l_356 =
        (safe_sub_func_uint16_t_u_u
         ((0xDCL ^
    (((g_208[2] =
       (((safe_sub_func_int64_t_s_s
          ((((safe_add_func_int8_t_s_s
       (((safe_add_func_int32_t_s_s
          (0x17AFCBD4L, 9UL)) != 0xC7L),
        (safe_sub_func_uint64_t_u_u
         (((1UL <=
     (1L <
      (safe_lshift_func_uint16_t_u_s
       ((safe_add_func_uint64_t_u_u
         (g_280,
          (0UL
           || (l_211 =
        0xE64348B5L)))),
        5)))) | l_230),
          g_357)))) | 0xAFCEL)
     && 7L),
    l_229)) <= l_353) | p_94)) != l_376) <=
     g_359)), p_93));
      for (l_353 = 0; (l_353 <= 3); l_353 += 1)
        {
   int32_t l_377 = 0xE64B3CA6L;
   int i, j, k;
   l_377 = l_254[(l_295 + 2)][l_353][l_353];
   return p_94;
        }
    }
  if (((safe_add_func_int16_t_s_s
        ((((safe_add_func_uint32_t_u_u
     ((((safe_rshift_func_int16_t_s_u
         (7L,
          (l_354 =
    ((safe_sub_func_uint16_t_u_u
      (0UL,
       ((l_295 =
         p_94) <
        ((safe_rshift_func_uint8_t_u_s
          (l_230,
           (l_254[6][7][3] !=
     0x9AL))) &
         (safe_lshift_func_int16_t_s_s
          ((g_4[1][7] & g_236),
           (safe_add_func_int64_t_s_s
     (((safe_add_func_uint16_t_u_u
        ((4294967286UL <= l_358[3]),
         l_230)) == g_208[2]),
      0x3E78FA6BBBD3E55ALL)))))))) <=
     l_376)))) < 65532UL) | 1L),
      g_208[2])) >= g_208[2]) & l_230), 0x9C3CL))
       && 0x2934253AL))
    {
      uint64_t l_404 = 18446744073709551615UL;
      l_356
        =
        (((safe_lshift_func_uint8_t_u_s
    (((safe_add_func_uint32_t_u_u
       (((safe_rshift_func_int16_t_s_u (0xAF4AL, 0)) <
         p_93),
        (safe_mod_func_int64_t_s_s
         (((l_404 |
     (((l_405 ^
        ((((+p_94)
           && (l_355 =
        (1UL == 0x6F29L))) ==
          1L) &
         ((safe_lshift_func_uint16_t_u_u
           (((p_92 & l_376) < g_98),
     l_279)) >= p_94))) & l_230) ==
      g_236)) & 0x6EL), l_254[3][5][0])))) >= 1L),
     p_93)) | l_279) < 7L);
      if (l_211)
        goto lbl_412;
      if (((safe_mod_func_uint64_t_u_u
     ((0xED956FEEA5F8B7EBLL &
       (safe_lshift_func_int16_t_s_u
        ((((safe_mul_func_int16_t_s_s
     ((safe_lshift_func_uint8_t_u_u
       ((safe_add_func_uint16_t_u_u
         (((0x98BDL >=
     (p_94 ^
      (safe_sub_func_int16_t_s_s
       ((p_94
         || (+g_189)),
        (((g_209 = p_94) >= g_178)
         || p_94))))) <=
           ((safe_lshift_func_int8_t_s_s
      ((((p_93 == g_357) > g_280) ^ g_236),
       p_92))
     && 0xACL)), g_99[1])), 3)),
      p_92)) >= g_359) < p_94), l_251[1][0]))),
      0x0E271EE976597471LL)) ^ l_295))
        {
   uint64_t l_453 = 0x5A6B217372B41566LL;
   g_208
     [2]
     =
     ((safe_lshift_func_int8_t_s_u
       ((safe_mod_func_int32_t_s_s
         ((safe_rshift_func_int8_t_s_s
    ((safe_add_func_uint32_t_u_u
      ((5UL >= (!p_92)),
       (g_455 =
        (l_454[1] =
         (safe_sub_func_uint8_t_u_u
          ((((l_437[6][8][0]
       &&
       (((6UL >
          ((safe_lshift_func_uint8_t_u_s
            (((p_94 ^
        (safe_add_func_int64_t_s_s
         (((safe_sub_func_uint16_t_u_u ((safe_lshift_func_uint16_t_u_s ((((safe_rshift_func_int8_t_s_s ((g_236 || (g_98 <= (safe_rshift_func_int16_t_s_s ((safe_unary_minus_func_uint8_t_u ((safe_sub_func_uint64_t_u_u ((((g_236 || l_254[1][5][0]) != 0xB5FB86B1F9055481LL) <= p_92), 18446744073709551615UL)))), 1)))), l_453)) & p_92) < 0UL), 11)), g_236)) & l_453), 0x5759DA75A76652DCLL))) <= p_94), g_4[1][6])) && p_93)) ^ 0x972D0B17C0A01B54LL) < p_94)) != l_230) ^ 1UL), g_357)))))), p_94)), g_280)), 7)) || l_210);
   if (p_94)
     break;
   return g_357;
        }
      else
        {
   return l_332;
        }
    }
  else
    {
      l_229 = (safe_add_func_uint64_t_u_u (g_4[1][2], p_94));
    }
       }



     }
   l_211
     =
     (safe_rshift_func_uint16_t_u_u
      ((g_178 !=
        ((g_99[3] =
   (safe_mod_func_uint16_t_u_u
    ((((l_210 =
        (safe_lshift_func_uint16_t_u_u
         ((~
    (safe_sub_func_uint32_t_u_u
     (p_92,
      (g_189 |
       ((safe_mod_func_uint64_t_u_u
         (((p_94 =
     (((safe_mul_func_uint16_t_u_u
        (0x4C97L,
         ((safe_lshift_func_int16_t_s_u
           ((g_209 =
      (g_208[2] =
       (~
        (safe_lshift_func_uint8_t_u_u
         (((((safe_add_func_int8_t_s_s
       ((8UL
         && g_98),
        (65533UL <= p_92))) >=
      0xC2FFDF52C73AE872LL) !=
            l_173) > p_92), l_173))))),
     5)) >
          p_92))) & 0xF2569BDC76872175LL) >
      0x8814L)) | l_173), l_173)) | 0xB29FL))))),
   p_93))) ^ 0UL) != p_93), l_173))) ^ g_189)), 1));



 }
      l_211
 =
 (safe_rshift_func_uint16_t_u_u
  ((g_178 !=
    ((g_99[3] =
      (safe_mod_func_uint16_t_u_u
       ((((l_210 =
    (safe_lshift_func_uint16_t_u_u
     ((~
       (safe_sub_func_uint32_t_u_u
        (p_92,
         (g_189 |
   ((safe_mod_func_uint64_t_u_u
     (((p_94 =
        (((safe_mul_func_uint16_t_u_u
    (0x4C97L,
     ((safe_lshift_func_int16_t_s_u
       ((g_209 =
         (g_208[2] =
          (~
           (safe_lshift_func_uint8_t_u_u
     (((((safe_add_func_int8_t_s_s
          ((8UL
            && g_98),
           (65533UL <= p_92))) >=
         0xC2FFDF52C73AE872LL) != l_173) >
       p_92), l_173))))),
        5)) > p_92))) & 0xF2569BDC76872175LL) >
         0x8814L)) | l_173), l_173)) | 0xB29FL))))),
      p_93))) ^ 0UL) != p_93), l_173))) ^ g_189)), 1));



    }
  else
    {
      int32_t l_464 = (-1L);
      int32_t l_469 = 0x040CA63DL;
      uint16_t l_470 = 0x50A4L;
      int32_t l_487 = 9L;
      int32_t l_676[5];
      int32_t l_735 = 0L;
      int16_t l_737[5][3] =
      {
 {
 0xD1DAL, 0xD775L, 0xD1DAL}
 ,
 {
 0x0E2EL, 0x0E2EL, 0x0E2EL}
 ,
 {
 0xD1DAL, 0xD775L, 0xD1DAL}
 ,
 {
 0x0E2EL, 0x0E2EL, 0x0E2EL}
 ,
 {
 0xD1DAL, 0xD775L, 0xD1DAL}
      };
      int i, j;
      for (i = 0; i < 5; i++)
 {
   l_676[i] = 0xDDA7A95BL;
   l_211
     =
     (safe_rshift_func_uint16_t_u_u
      ((g_178 !=
        ((g_99[3] =
   (safe_mod_func_uint16_t_u_u
    ((((l_210 =
        (safe_lshift_func_uint16_t_u_u
         ((~
    (safe_sub_func_uint32_t_u_u
     (p_92,
      (g_189 |
       ((safe_mod_func_uint64_t_u_u
         (((p_94 =
     (((safe_mul_func_uint16_t_u_u
        (0x4C97L,
         ((safe_lshift_func_int16_t_s_u
           ((g_209 =
      (g_208[2] =
       (~
        (safe_lshift_func_uint8_t_u_u
         (((((safe_add_func_int8_t_s_s
       ((8UL
         && g_98),
        (65533UL <= p_92))) >=
      0xC2FFDF52C73AE872LL) !=
            l_173) > p_92), l_173))))),
     5)) >
          p_92))) & 0xF2569BDC76872175LL) >
      0x8814L)) | l_173), l_173)) | 0xB29FL))))),
   p_93))) ^ 0UL) != p_93), l_173))) ^ g_189)), 1));



   for (i = 0; i < 5; i++)
     l_676[i] = 0xDDA7A95BL;

 }


      if (((safe_mul_func_uint16_t_u_u
     ((((safe_sub_func_uint8_t_u_u
  (((g_178 =
     ((safe_sub_func_int32_t_s_s (1L, l_464)) <
      l_464)) | ((((g_357 = 255UL) <
     (l_454[1] |
      (((safe_add_func_uint32_t_u_u
         (0x62FD1387L,
          (l_469 =
           (p_93 ==
     (safe_mod_func_int16_t_s_s
      (l_464,
       g_99[2])))))) >= 0x5527L) <=
       l_470))) != p_93) == p_92)),
   0xD3L)) < g_236) <= p_92), l_454[2])) < l_173))
 {
   int64_t l_502 = 0xB284F1512807B3F7LL;
   int32_t l_503[7][3][8] =
   {
     {
       {
       0x24AB212BL, 0xBFD57F4BL, 0x6FA1C930L, 7L, 0xD226A061L, 5L,
    0x81D3EAD7L, 0x97D46C52L}
       ,
       {
       0xA99503C9L,
    6L,
    0x8CAA2FA2L,
    0xB950D48EL,
    0xD8E4BD24L, 0x59E75CB0L, 0x7BFD730CL, 0x6FA1C930L}
       ,
       {
       0x8CAA2FA2L,
    0L, 5L, (-3L), 0x3469A6C3L, (-3L), 0xD226A061L, 0L}
     }
     ,
     {
       {
       0L, 2L, 0x36337888L, 0xBFD57F4BL, 0L, 0x6FA1C930L, 6L,
    0xB950D48EL}
       ,
       {
       0xD226A061L,
    0x81D3EAD7L, 0xBFD57F4BL, 0x735146A9L, 0L, (-1L), 6L, (-1L)}
       ,
       {
       (-2L), 0x735146A9L, 0x36337888L, 0x6FA1C930L, 5L, 6L,
    0xD226A061L, 1L}
     }
     ,
     {
       {
       5L, 6L, 0xD226A061L, 1L, 0xB950D48EL, (-3L), 7L, 7L}
       ,
       {
       0x3469A6C3L,
    0xD8E4BD24L, 2L, 2L, 0xD8E4BD24L, 0x3469A6C3L, (-1L), (-1L)}
       ,
       {
       0xA8990C81L,
    0x69D2D8EEL,
    0xD8E4BD24L, 5L, (-1L), 0x59E75CB0L, 5L, 0xD226A061L}
     }
     ,
     {
       {
       7L, 1L, 0x24AB212BL, 5L, (-1L), 0xB950D48EL, 0x69D2D8EEL,
    (-1L)}
       ,
       {
       0xBFD57F4BL, (-1L), 0xA99503C9L, 2L, 0x92F04986L, 1L, 5L, 7L}
       ,
       {
       0L,
    0xA8990C81L, 0x8CAA2FA2L, 1L, (-8L), 0xA99503C9L, (-8L), 1L}
     }
     ,
     {
       {
       0x735146A9L, (-1L), 0x735146A9L, 0x6FA1C930L, 0xA8990C81L, 0L,
    0xBFD57F4BL, (-1L)}
       ,
       {
       0x24AB212BL,
    0L,
    5L,
    0x735146A9L, 0x81D3EAD7L, (-1L), 0xA8990C81L, 0xB950D48EL}
       ,
       {
       0x24AB212BL,
    5L,
    0x92F04986L, 0xBFD57F4BL, 0xA8990C81L, 0L, 0x36337888L, 0L}
     }
     ,
     {
       {
       0x735146A9L, (-3L), 0x59E75CB0L, 0x8CAA2FA2L, (-8L),
    0xBFD57F4BL, (-2L), 0xD8E4BD24L}
       ,
       {
       0L,
    0x59E75CB0L,
    (-1L), 0x92F04986L, 0x92F04986L, (-1L), 0x59E75CB0L, 0L}
       ,
       {
       0xBFD57F4BL,
    5L, (-8L), (-1L), (-1L), 0L, 0xA99503C9L, 0x7BFD730CL}
     }
     ,
     {
       {
       7L, 0L, 0x7BFD730CL, (-2L), (-1L), 0L, 0x735146A9L,
    0x3469A6C3L}
       ,
       {
       0xA8990C81L, 5L, 0L, 0L, 0xD8E4BD24L, (-1L), (-1L), (-1L)}
       ,
       {
       0x3469A6C3L,
    0x59E75CB0L,
    0x97D46C52L,
    (-1L), 0xB950D48EL, 0xBFD57F4BL, (-3L), 0xBFD57F4BL}
     }
   };
   int16_t l_516 = 0x481AL;
   int16_t l_576 = 0xB260L;
   int i, j, k;
   if (p_92)
     {
       int16_t l_486 = 0x96E4L;
       uint32_t l_514 = 18446744073709551615UL;
       l_487 = (safe_mul_func_int16_t_s_s (((safe_sub_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_s ((((l_469 = 0xBAL) && 0x3CL) && 0xC49D329C4F5B0900LL), ((safe_mul_func_int8_t_s_s ((((safe_sub_func_int32_t_s_s ((-1L), g_280)) & (((safe_unary_minus_func_uint16_t_u ((g_178 = p_94))) && (((0x558134D8C914E6DELL > g_209) >= (safe_rshift_func_uint8_t_u_u ((safe_rshift_func_uint16_t_u_s (0xDF32L, p_94)), 2))) ^ l_470)) && 4294967295UL)) | l_486), 0xE1L)) == 3UL))), g_455)) == l_464), g_209));
       l_211
  =
  (safe_rshift_func_uint16_t_u_u
   ((g_178 !=
     ((g_99[3] =
       (safe_mod_func_uint16_t_u_u
        ((((l_210 =
     (safe_lshift_func_uint16_t_u_u
      ((~
        (safe_sub_func_uint32_t_u_u
         (p_92,
          (g_189 |
    ((safe_mod_func_uint64_t_u_u
      (((p_94 =
         (((safe_mul_func_uint16_t_u_u
     (0x4C97L,
      ((safe_lshift_func_int16_t_s_u
        ((g_209 =
          (g_208[2] =
           (~
            (safe_lshift_func_uint8_t_u_u
      (((((safe_add_func_int8_t_s_s
           ((8UL
             && g_98),
            (65533UL <= p_92))) >=
          0xC2FFDF52C73AE872LL) !=
         l_173) > p_92), l_173))))),
         5)) >
       p_92))) & 0xF2569BDC76872175LL) >
          0x8814L)) | l_173),
       l_173)) | 0xB29FL))))),
       p_93))) ^ 0UL) != p_93), l_173))) ^ g_189)), 1));





       return g_359;
     }
   else
     {
       int32_t l_517 = 1L;
       g_208[2] = l_517;
       if (p_92)
  {
    int16_t l_486 = 0x96E4L;
    uint32_t l_514 = 18446744073709551615UL;
    l_487
      =
      (safe_mul_func_int16_t_s_s
       (((safe_sub_func_uint8_t_u_u
   ((safe_lshift_func_int8_t_s_s
     ((((l_469 = 0xBAL) && 0x3CL)
       && 0xC49D329C4F5B0900LL),
      ((safe_mul_func_int8_t_s_s
        ((((safe_sub_func_int32_t_s_s ((-1L), g_280)) &
    (((safe_unary_minus_func_uint16_t_u
       ((g_178 = p_94)))
      &&
      (((0x558134D8C914E6DELL > g_209) >=
        (safe_rshift_func_uint8_t_u_u
         ((safe_rshift_func_uint16_t_u_s
           (0xDF32L, p_94)), 2))) ^ l_470))
     && 4294967295UL)) | l_486),
         0xE1L)) == 3UL))), g_455)) == l_464), g_209));
    for (l_487 = (-8); (l_487 > (-14)); --l_487)
      {
        uint8_t l_515[5] =
        {
        0x53L, 0x53L, 0x53L, 0x53L, 0x53L};
        int i;
        l_516
   =
   (((g_209
      || p_93) <=
     (~
      ((safe_sub_func_uint32_t_u_u
        ((safe_mul_func_uint8_t_u_u
          ((((9UL ==
       (((safe_add_func_uint8_t_u_u
          ((safe_sub_func_uint64_t_u_u
     ((safe_sub_func_int16_t_s_s
       (((safe_rshift_func_int8_t_s_s
          (p_94,
           (l_503[6][1][7] =
            (0xE9200326L !=
      (l_502 =
       1UL))))) ^
         ((safe_mul_func_int8_t_s_s
           ((5UL &
      (safe_sub_func_uint8_t_u_u
       (((l_210 =
          (safe_rshift_func_uint8_t_u_s
           ((l_469 =
             (safe_sub_func_uint64_t_u_u
       ((p_94 <=
         (((safe_lshift_func_int16_t_s_u (g_4[1][2], 11)) >= l_514) | 0xCD04215EL)), 0x594DEE00CD75C92ELL))), p_94))) <= g_357), 0x70L))), p_94)) && g_189)), p_93)), p_92)), l_515[1])) || 0x63D4L) > g_357)) || g_209) ^ 0x81D7L), l_470)), 1UL)) != l_229))) == p_94);
      }
    return g_359;
  }
       else
  {
    int32_t l_517 = 1L;
    g_208[2] = l_517;
    for (p_92 = 0; (p_92 <= 16); p_92++)
      {
        uint32_t l_538 = 0x10A82951L;
        int32_t l_539 = 0x2158B6CBL;
        for (g_455 = 0; (g_455 >= 7); ++g_455)
   {
     int8_t l_542 = 0L;
     int32_t l_577 = 0x058D355FL;
     l_542
       =
       (!
        ((((g_455 >
     (g_540[0][0][0] =
      ((g_209 <
        g_280) |
       ((safe_mul_func_int16_t_s_s
         ((l_539 =
           ((((safe_lshift_func_int8_t_s_u
        ((((l_469 = p_92)
           &&
           ((((((safe_mul_func_int8_t_s_s
          (p_93,
           (g_359 =
            (p_94 =
             (safe_mul_func_int16_t_s_s
       (((safe_mod_func_int16_t_s_s (((safe_add_func_int8_t_s_s ((l_538 = (safe_lshift_func_int8_t_s_u (((g_4[1][2] | ((-10L) == ((safe_sub_func_int64_t_s_s (p_93, (p_93 != p_93))) == (-6L)))) == g_98), l_470))), p_94)) < p_93), 0x1002L)) || g_208[0]), p_92)))))) > l_517) && p_93) >= 0UL) ^ l_539) | 6L)) == g_280), 7)) & p_93) | l_454[4]) > 0x67318379L)), g_208[2])) >= 0x860F0DB8L)))) & l_541) != l_487) & g_4[1][2]));
     g_208[2] =
       ((((p_93 > 3L)
          || g_209) ==
         ((p_94 ^ g_540[0][0][0]) ^ 0UL)) ^ 0x76918559L);
     g_208[2] =
       ((l_487 =
         ((((safe_rshift_func_uint16_t_u_s
      ((safe_mul_func_uint16_t_u_u
        (((((safe_lshift_func_int8_t_s_s
      ((p_92 <
        (safe_unary_minus_func_uint16_t_u
         (((!(safe_rshift_func_uint8_t_u_u
       ((l_539 =
         g_209), 2))) <= 4UL)))),
       0)) == (l_542
        ||
        ((safe_rshift_func_int16_t_s_u (((safe_unary_minus_func_uint8_t_u ((g_236 = (((((g_575 = (((g_357 = (safe_rshift_func_uint16_t_u_u ((safe_rshift_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u ((safe_lshift_func_uint8_t_u_s (g_359, 3)), (safe_sub_func_uint64_t_u_u ((p_92 & ((safe_mod_func_uint32_t_u_u (l_454[0], ((safe_sub_func_int32_t_s_s ((safe_mul_func_uint16_t_u_u ((safe_add_func_int64_t_s_s ((p_92 || 0x20157C39L), p_92)), g_236)), p_94)) & p_93))) != 254UL)), l_469)))), 4)), 0))) & l_211) < 0L)) != 0x950EF6B4L) > 0x88L) & l_173) && l_576)))) == l_251[2][6]), l_517)) || l_517))) || g_208[0]) >= l_538), l_576)), l_517)) <= l_538) & l_577) || g_99[1])) ^ g_359);
   }
        l_503[6][1][7] = 2L;
      }
    return g_97;
  }



       for (p_92 = 0; (p_92 <= 16); p_92++)
  {
    uint32_t l_538 = 0x10A82951L;
    int32_t l_539 = 0x2158B6CBL;
    for (g_455 = 0; (g_455 >= 7); ++g_455)
      {
        int8_t l_542 = 0L;
        int32_t l_577 = 0x058D355FL;


        {
   int8_t l_542 = 0L;
   int32_t l_577 = 0x058D355FL;
   l_542
     =
     (!
      ((((g_455 >
          (g_540[0][0][0] =
    ((g_209 <
      g_280) |
     ((safe_mul_func_int16_t_s_s
       ((l_539 =
         ((((safe_lshift_func_int8_t_s_u
      ((((l_469 = p_92)
         &&
         ((((((safe_mul_func_int8_t_s_s
        (p_93,
         (g_359 =
          (p_94 =
           (safe_mul_func_int16_t_s_s
            (((safe_mod_func_int16_t_s_s (((safe_add_func_int8_t_s_s ((l_538 = (safe_lshift_func_int8_t_s_u (((g_4[1][2] | ((-10L) == ((safe_sub_func_int64_t_s_s (p_93, (p_93 != p_93))) == (-6L)))) == g_98), l_470))), p_94)) < p_93), 0x1002L)) || g_208[0]), p_92)))))) > l_517) && p_93) >= 0UL) ^ l_539) | 6L)) == g_280), 7)) & p_93) | l_454[4]) > 0x67318379L)), g_208[2])) >= 0x860F0DB8L)))) & l_541) != l_487) & g_4[1][2]));
   g_208[2] =
     ((((p_93 > 3L)
        || g_209) ==
       ((p_94 ^ g_540[0][0][0]) ^ 0UL)) ^ 0x76918559L);
   g_208[2] =
     ((l_487 =
       ((((safe_rshift_func_uint16_t_u_s
    ((safe_mul_func_uint16_t_u_u
      (((((safe_lshift_func_int8_t_s_s
           ((p_92 <
      (safe_unary_minus_func_uint16_t_u
       (((!(safe_rshift_func_uint8_t_u_u
            ((l_539 =
       g_209), 2))) <= 4UL)))),
     0)) == (l_542
      ||
      ((safe_rshift_func_int16_t_s_u
        (((safe_unary_minus_func_uint8_t_u ((g_236 = (((((g_575 = (((g_357 = (safe_rshift_func_uint16_t_u_u ((safe_rshift_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u ((safe_lshift_func_uint8_t_u_s (g_359, 3)), (safe_sub_func_uint64_t_u_u ((p_92 & ((safe_mod_func_uint32_t_u_u (l_454[0], ((safe_sub_func_int32_t_s_s ((safe_mul_func_uint16_t_u_u ((safe_add_func_int64_t_s_s ((p_92 || 0x20157C39L), p_92)), g_236)), p_94)) & p_93))) != 254UL)), l_469)))), 4)), 0))) & l_211) < 0L)) != 0x950EF6B4L) > 0x88L) & l_173) && l_576)))) == l_251[2][6]), l_517)) || l_517))) || g_208[0]) >= l_538), l_576)), l_517)) <= l_538) & l_577) || g_99[1])) ^ g_359);
        }


        g_208[2] = ((((p_93 > 3L) || g_209) == ((p_94 ^ g_540[0][0][0]) ^ 0UL)) ^ 0x76918559L);
        g_208
   [2]
   =
   ((((p_93 > 3L)
      || g_209) ==
     ((p_94 ^ g_540[0][0][0]) ^ 0UL)) ^ 0x76918559L);



        g_208
   [2]
   =
   ((l_487 =
     ((((safe_rshift_func_uint16_t_u_s
         ((safe_mul_func_uint16_t_u_u
    (((((safe_lshift_func_int8_t_s_s
         ((p_92 <
           (safe_unary_minus_func_uint16_t_u
     (((!(safe_rshift_func_uint8_t_u_u
          ((l_539 =
            g_209), 2))) <= 4UL)))),
          0)) == (l_542
           ||
           ((safe_rshift_func_int16_t_s_u
      (((safe_unary_minus_func_uint8_t_u ((g_236 = (((((g_575 = (((g_357 = (safe_rshift_func_uint16_t_u_u ((safe_rshift_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u ((safe_lshift_func_uint8_t_u_s (g_359, 3)), (safe_sub_func_uint64_t_u_u ((p_92 & ((safe_mod_func_uint32_t_u_u (l_454[0], ((safe_sub_func_int32_t_s_s ((safe_mul_func_uint16_t_u_u ((safe_add_func_int64_t_s_s ((p_92 || 0x20157C39L), p_92)), g_236)), p_94)) & p_93))) != 254UL)), l_469)))), 4)), 0))) & l_211) < 0L)) != 0x950EF6B4L) > 0x88L) & l_173) && l_576)))) == l_251[2][6]), l_517)) || l_517))) || g_208[0]) >= l_538), l_576)), l_517)) <= l_538) & l_577) || g_99[1])) ^ g_359);
      }
    {
      int16_t l_486 = 0x96E4L;
      uint32_t l_514 = 18446744073709551615UL;
      l_487
        =
        (safe_mul_func_int16_t_s_s
         (((safe_sub_func_uint8_t_u_u
     ((safe_lshift_func_int8_t_s_s
       ((((l_469 = 0xBAL) && 0x3CL)
         && 0xC49D329C4F5B0900LL),
        ((safe_mul_func_int8_t_s_s
          ((((safe_sub_func_int32_t_s_s ((-1L), g_280)) &
      (((safe_unary_minus_func_uint16_t_u
         ((g_178 = p_94)))
        &&
        (((0x558134D8C914E6DELL > g_209) >=
          (safe_rshift_func_uint8_t_u_u
           ((safe_rshift_func_uint16_t_u_s
      (0xDF32L, p_94)), 2))) ^ l_470))
       && 4294967295UL)) | l_486),
    0xE1L)) == 3UL))), g_455)) == l_464), g_209));
      for (l_487 = (-8); (l_487 > (-14)); --l_487)
        {
   uint8_t l_515[5] =
   {
   0x53L, 0x53L, 0x53L, 0x53L, 0x53L};
   int i;
   l_516
     =
     (((g_209
        || p_93) <=
       (~
        ((safe_sub_func_uint32_t_u_u
          ((safe_mul_func_uint8_t_u_u
     ((((9UL ==
         (((safe_add_func_uint8_t_u_u
     ((safe_sub_func_uint64_t_u_u
       ((safe_sub_func_int16_t_s_s
         (((safe_rshift_func_int8_t_s_s
            (p_94,
      (l_503[6][1][7] =
       (0xE9200326L !=
        (l_502 =
         1UL))))) ^
           ((safe_mul_func_int8_t_s_s
      ((5UL &
        (safe_sub_func_uint8_t_u_u
         (((l_210 =
            (safe_rshift_func_uint8_t_u_s
             ((l_469 =
        (safe_sub_func_uint64_t_u_u
         ((p_94 <=
           (((safe_lshift_func_int16_t_s_u (g_4[1][2], 11)) >= l_514) | 0xCD04215EL)), 0x594DEE00CD75C92ELL))), p_94))) <= g_357), 0x70L))), p_94)) && g_189)), p_93)), p_92)), l_515[1])) || 0x63D4L) > g_357)) || g_209) ^ 0x81D7L), l_470)), 1UL)) != l_229))) == p_94);
        }
      return g_359;
    }



    l_503[6][1][7] = 2L;
  }
       for (i = 0; i < 5; i++)
  l_676[i] = 0xDDA7A95BL;



       return g_97;
     }
   if (p_92)
     {
       int16_t l_486 = 0x96E4L;
       uint32_t l_514 = 18446744073709551615UL;
       l_487
  =
  (safe_mul_func_int16_t_s_s
   (((safe_sub_func_uint8_t_u_u
      ((safe_lshift_func_int8_t_s_s
        ((((l_469 = 0xBAL) && 0x3CL)
   && 0xC49D329C4F5B0900LL),
         ((safe_mul_func_int8_t_s_s
    ((((safe_sub_func_int32_t_s_s ((-1L), g_280)) &
       (((safe_unary_minus_func_uint16_t_u
          ((g_178 = p_94)))
         &&
         (((0x558134D8C914E6DELL > g_209) >=
    (safe_rshift_func_uint8_t_u_u
     ((safe_rshift_func_uint16_t_u_s
       (0xDF32L, p_94)), 2))) ^ l_470))
        && 4294967295UL)) | l_486), 0xE1L)) == 3UL))),
       g_455)) == l_464), g_209));
       for (l_487 = (-8); (l_487 > (-14)); --l_487)
  {
    uint8_t l_515[5] =
    {
    0x53L, 0x53L, 0x53L, 0x53L, 0x53L};
    int i;
    l_516
      =
      (((g_209
         || p_93) <=
        (~
         ((safe_sub_func_uint32_t_u_u
    ((safe_mul_func_uint8_t_u_u
      ((((9UL ==
          (((safe_add_func_uint8_t_u_u
      ((safe_sub_func_uint64_t_u_u
        ((safe_sub_func_int16_t_s_s
          (((safe_rshift_func_int8_t_s_s
      (p_94,
       (l_503[6][1][7] =
        (0xE9200326L !=
         (l_502 =
          1UL))))) ^
     ((safe_mul_func_int8_t_s_s
       ((5UL &
         (safe_sub_func_uint8_t_u_u
          (((l_210 =
      (safe_rshift_func_uint8_t_u_s
       ((l_469 =
         (safe_sub_func_uint64_t_u_u
          ((p_94 <=
            (((safe_lshift_func_int16_t_s_u (g_4[1][2], 11)) >= l_514) | 0xCD04215EL)), 0x594DEE00CD75C92ELL))), p_94))) <= g_357), 0x70L))), p_94)) && g_189)), p_93)), p_92)), l_515[1])) || 0x63D4L) > g_357)) || g_209) ^ 0x81D7L), l_470)), 1UL)) != l_229))) == p_94);
  }
       return g_359;
     }
   else
     {
       int32_t l_517 = 1L;
       g_208[2] = l_517;
       for (p_92 = 0; (p_92 <= 16); p_92++)
  {
    uint32_t l_538 = 0x10A82951L;
    int32_t l_539 = 0x2158B6CBL;
    for (g_455 = 0; (g_455 >= 7); ++g_455)
      {
        int8_t l_542 = 0L;
        int32_t l_577 = 0x058D355FL;
        l_542
   =
   (!
    ((((g_455 >
        (g_540[0][0][0] =
         ((g_209 <
    g_280) |
          ((safe_mul_func_int16_t_s_s
     ((l_539 =
       ((((safe_lshift_func_int8_t_s_u
           ((((l_469 = p_92)
       &&
       ((((((safe_mul_func_int8_t_s_s
      (p_93,
       (g_359 =
        (p_94 =
         (safe_mul_func_int16_t_s_s
          (((safe_mod_func_int16_t_s_s (((safe_add_func_int8_t_s_s ((l_538 = (safe_lshift_func_int8_t_s_u (((g_4[1][2] | ((-10L) == ((safe_sub_func_int64_t_s_s (p_93, (p_93 != p_93))) == (-6L)))) == g_98), l_470))), p_94)) < p_93), 0x1002L)) || g_208[0]), p_92)))))) > l_517) && p_93) >= 0UL) ^ l_539) | 6L)) == g_280), 7)) & p_93) | l_454[4]) > 0x67318379L)), g_208[2])) >= 0x860F0DB8L)))) & l_541) != l_487) & g_4[1][2]));
        g_208[2] =
   ((((p_93 > 3L)
      || g_209) ==
     ((p_94 ^ g_540[0][0][0]) ^ 0UL)) ^ 0x76918559L);
        g_208[2] =
   ((l_487 =
     ((((safe_rshift_func_uint16_t_u_s
         ((safe_mul_func_uint16_t_u_u
    (((((safe_lshift_func_int8_t_s_s
         ((p_92 <
           (safe_unary_minus_func_uint16_t_u
     (((!(safe_rshift_func_uint8_t_u_u
          ((l_539 =
            g_209), 2))) <= 4UL)))),
          0)) == (l_542
           ||
           ((safe_rshift_func_int16_t_s_u
      (((safe_unary_minus_func_uint8_t_u ((g_236 = (((((g_575 = (((g_357 = (safe_rshift_func_uint16_t_u_u ((safe_rshift_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u ((safe_lshift_func_uint8_t_u_s (g_359, 3)), (safe_sub_func_uint64_t_u_u ((p_92 & ((safe_mod_func_uint32_t_u_u (l_454[0], ((safe_sub_func_int32_t_s_s ((safe_mul_func_uint16_t_u_u ((safe_add_func_int64_t_s_s ((p_92 || 0x20157C39L), p_92)), g_236)), p_94)) & p_93))) != 254UL)), l_469)))), 4)), 0))) & l_211) < 0L)) != 0x950EF6B4L) > 0x88L) & l_173) && l_576)))) == l_251[2][6]), l_517)) || l_517))) || g_208[0]) >= l_538), l_576)), l_517)) <= l_538) & l_577) || g_99[1])) ^ g_359);
      }
    l_503[6][1][7] = 2L;
  }
       return g_97;
     }



 }
      else
 {
   uint64_t l_580 = 1UL;
   int32_t l_604[4];
   uint32_t l_622 = 0xEA9DDCE7L;
   int16_t l_654[8][3][7] =
   {
     {
       {
       0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L}
       ,
       {
       4L, 4L, 4L, 4L, 4L, 4L, 4L}
       ,
       {
       0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L}
     }
     ,
     {
       {
       4L, 4L, 4L, 4L, 4L, 4L, 4L}
       ,
       {
       0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L}
       ,
       {
       4L, 4L, 4L, 4L, 4L, 4L, 4L}
     }
     ,
     {
       {
       0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L}
       ,
       {
       4L, 4L, 4L, 4L, 4L, 4L, 4L}
       ,
       {
       0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L}
     }
     ,
     {
       {
       4L, 4L, 4L, 4L, 4L, 4L, 4L}
       ,
       {
       0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L}
       ,
       {
       4L, 4L, 4L, 4L, 4L, 4L, 4L}
     }
     ,
     {
       {
       0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L}
       ,
       {
       4L, 4L, 4L, 4L, 4L, 4L, 4L}
       ,
       {
       0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L}
     }
     ,
     {
       {
       4L, 4L, 4L, 4L, 4L, 4L, 4L}
       ,
       {
       0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L}
       ,
       {
       4L, 4L, 4L, 4L, 4L, 4L, 4L}
     }
     ,
     {
       {
       0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L}
       ,
       {
       4L, 4L, 4L, 4L, 4L, 4L, 4L}
       ,
       {
       0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L}
     }
     ,
     {
       {
       4L, 4L, 4L, 4L, 4L, 4L, 4L}
       ,
       {
       0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L, 0x7E52L}
       ,
       {
       4L, 4L, 4L, 4L, 4L, 4L, 4L}
     }
   };
   int32_t l_704 = 0xC6FFE904L;
   int32_t l_808 = (-5L);
   int i, j, k;
   for (i = 0; i < 4; i++)
     ;

 lbl_755:
   l_469 = l_487;
   l_251[2][9] = (safe_mul_func_uint16_t_u_u ((p_94 ^ 0x654FB5CBL), l_580));
   {
     int64_t l_502 = 0xB284F1512807B3F7LL;
     int32_t l_503[7][3][8] =
     {
       {
  {
  0x24AB212BL, 0xBFD57F4BL, 0x6FA1C930L, 7L, 0xD226A061L, 5L,
      0x81D3EAD7L, 0x97D46C52L}
  ,
  {
  0xA99503C9L,
      6L,
      0x8CAA2FA2L,
      0xB950D48EL,
      0xD8E4BD24L, 0x59E75CB0L, 0x7BFD730CL, 0x6FA1C930L}
  ,
  {
  0x8CAA2FA2L,
      0L, 5L, (-3L), 0x3469A6C3L, (-3L), 0xD226A061L, 0L}
       }
       ,
       {
  {
  0L, 2L, 0x36337888L, 0xBFD57F4BL, 0L, 0x6FA1C930L, 6L,
      0xB950D48EL}
  ,
  {
  0xD226A061L,
      0x81D3EAD7L,
      0xBFD57F4BL, 0x735146A9L, 0L, (-1L), 6L, (-1L)}
  ,
  {
  (-2L), 0x735146A9L, 0x36337888L, 0x6FA1C930L, 5L, 6L,
      0xD226A061L, 1L}
       }
       ,
       {
  {
  5L, 6L, 0xD226A061L, 1L, 0xB950D48EL, (-3L), 7L, 7L}
  ,
  {
  0x3469A6C3L,
      0xD8E4BD24L,
      2L, 2L, 0xD8E4BD24L, 0x3469A6C3L, (-1L), (-1L)}
  ,
  {
  0xA8990C81L,
      0x69D2D8EEL,
      0xD8E4BD24L, 5L, (-1L), 0x59E75CB0L, 5L, 0xD226A061L}
       }
       ,
       {
  {
  7L, 1L, 0x24AB212BL, 5L, (-1L), 0xB950D48EL, 0x69D2D8EEL,
      (-1L)}
  ,
  {
  0xBFD57F4BL, (-1L), 0xA99503C9L, 2L, 0x92F04986L, 1L, 5L, 7L}
  ,
  {
  0L,
      0xA8990C81L,
      0x8CAA2FA2L, 1L, (-8L), 0xA99503C9L, (-8L), 1L}
       }
       ,
       {
  {
  0x735146A9L, (-1L), 0x735146A9L, 0x6FA1C930L, 0xA8990C81L,
      0L, 0xBFD57F4BL, (-1L)}
  ,
  {
  0x24AB212BL,
      0L,
      5L,
      0x735146A9L, 0x81D3EAD7L, (-1L), 0xA8990C81L, 0xB950D48EL}
  ,
  {
  0x24AB212BL,
      5L,
      0x92F04986L,
      0xBFD57F4BL, 0xA8990C81L, 0L, 0x36337888L, 0L}
       }
       ,
       {
  {
  0x735146A9L, (-3L), 0x59E75CB0L, 0x8CAA2FA2L, (-8L),
      0xBFD57F4BL, (-2L), 0xD8E4BD24L}
  ,
  {
  0L,
      0x59E75CB0L,
      (-1L), 0x92F04986L, 0x92F04986L, (-1L), 0x59E75CB0L, 0L}
  ,
  {
  0xBFD57F4BL,
      5L, (-8L), (-1L), (-1L), 0L, 0xA99503C9L, 0x7BFD730CL}
       }
       ,
       {
  {
  7L, 0L, 0x7BFD730CL, (-2L), (-1L), 0L, 0x735146A9L,
      0x3469A6C3L}
  ,
  {
  0xA8990C81L, 5L, 0L, 0L, 0xD8E4BD24L, (-1L), (-1L), (-1L)}
  ,
  {
  0x3469A6C3L,
      0x59E75CB0L,
      0x97D46C52L,
      (-1L), 0xB950D48EL, 0xBFD57F4BL, (-3L), 0xBFD57F4BL}
       }
     };
     int16_t l_516 = 0x481AL;
     int16_t l_576 = 0xB260L;
     int i, j, k;
     if (p_92)
       {
  int16_t l_486 = 0x96E4L;
  uint32_t l_514 = 18446744073709551615UL;
  l_487
    =
    (safe_mul_func_int16_t_s_s
     (((safe_sub_func_uint8_t_u_u
        ((safe_lshift_func_int8_t_s_s
   ((((l_469 = 0xBAL) && 0x3CL)
     && 0xC49D329C4F5B0900LL),
    ((safe_mul_func_int8_t_s_s
      ((((safe_sub_func_int32_t_s_s ((-1L), g_280)) &
         (((safe_unary_minus_func_uint16_t_u
     ((g_178 = p_94)))
    &&
    (((0x558134D8C914E6DELL > g_209) >=
      (safe_rshift_func_uint8_t_u_u
       ((safe_rshift_func_uint16_t_u_s
         (0xDF32L, p_94)), 2))) ^ l_470))
          && 4294967295UL)) | l_486), 0xE1L)) == 3UL))),
         g_455)) == l_464), g_209));
  for (l_487 = (-8); (l_487 > (-14)); --l_487)
    {
      uint8_t l_515[5] =
      {
      0x53L, 0x53L, 0x53L, 0x53L, 0x53L};
      int i;
      l_516
        =
        (((g_209
    || p_93) <=
   (~
    ((safe_sub_func_uint32_t_u_u
      ((safe_mul_func_uint8_t_u_u
        ((((9UL ==
     (((safe_add_func_uint8_t_u_u
        ((safe_sub_func_uint64_t_u_u
          ((safe_sub_func_int16_t_s_s
     (((safe_rshift_func_int8_t_s_s
        (p_94,
         (l_503[6][1][7] =
          (0xE9200326L !=
           (l_502 =
            1UL))))) ^
       ((safe_mul_func_int8_t_s_s
         ((5UL &
           (safe_sub_func_uint8_t_u_u
            (((l_210 =
        (safe_rshift_func_uint8_t_u_s
         ((l_469 =
           (safe_sub_func_uint64_t_u_u
            ((p_94 <=
       (((safe_lshift_func_int16_t_s_u (g_4[1][2], 11)) >= l_514) | 0xCD04215EL)), 0x594DEE00CD75C92ELL))), p_94))) <= g_357), 0x70L))), p_94)) && g_189)), p_93)), p_92)), l_515[1])) || 0x63D4L) > g_357)) || g_209) ^ 0x81D7L), l_470)), 1UL)) != l_229))) == p_94);
    }
  return g_359;
       }
     else
       {
  int32_t l_517 = 1L;
  g_208[2] = l_517;
  for (p_92 = 0; (p_92 <= 16); p_92++)
    {
      uint32_t l_538 = 0x10A82951L;
      int32_t l_539 = 0x2158B6CBL;
      for (g_455 = 0; (g_455 >= 7); ++g_455)
        {
   int8_t l_542 = 0L;
   int32_t l_577 = 0x058D355FL;
   l_542
     =
     (!
      ((((g_455 >
          (g_540[0][0][0] =
    ((g_209 <
      g_280) |
     ((safe_mul_func_int16_t_s_s
       ((l_539 =
         ((((safe_lshift_func_int8_t_s_u
      ((((l_469 = p_92)
         &&
         ((((((safe_mul_func_int8_t_s_s
        (p_93,
         (g_359 =
          (p_94 =
           (safe_mul_func_int16_t_s_s
            (((safe_mod_func_int16_t_s_s (((safe_add_func_int8_t_s_s ((l_538 = (safe_lshift_func_int8_t_s_u (((g_4[1][2] | ((-10L) == ((safe_sub_func_int64_t_s_s (p_93, (p_93 != p_93))) == (-6L)))) == g_98), l_470))), p_94)) < p_93), 0x1002L)) || g_208[0]), p_92)))))) > l_517) && p_93) >= 0UL) ^ l_539) | 6L)) == g_280), 7)) & p_93) | l_454[4]) > 0x67318379L)), g_208[2])) >= 0x860F0DB8L)))) & l_541) != l_487) & g_4[1][2]));
   g_208[2] =
     ((((p_93 > 3L)
        || g_209) ==
       ((p_94 ^ g_540[0][0][0]) ^ 0UL)) ^ 0x76918559L);
   g_208[2] =
     ((l_487 =
       ((((safe_rshift_func_uint16_t_u_s
    ((safe_mul_func_uint16_t_u_u
      (((((safe_lshift_func_int8_t_s_s
           ((p_92 <
      (safe_unary_minus_func_uint16_t_u
       (((!(safe_rshift_func_uint8_t_u_u
            ((l_539 =
       g_209), 2))) <= 4UL)))),
     0)) == (l_542
      ||
      ((safe_rshift_func_int16_t_s_u
        (((safe_unary_minus_func_uint8_t_u ((g_236 = (((((g_575 = (((g_357 = (safe_rshift_func_uint16_t_u_u ((safe_rshift_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u ((safe_lshift_func_uint8_t_u_s (g_359, 3)), (safe_sub_func_uint64_t_u_u ((p_92 & ((safe_mod_func_uint32_t_u_u (l_454[0], ((safe_sub_func_int32_t_s_s ((safe_mul_func_uint16_t_u_u ((safe_add_func_int64_t_s_s ((p_92 || 0x20157C39L), p_92)), g_236)), p_94)) & p_93))) != 254UL)), l_469)))), 4)), 0))) & l_211) < 0L)) != 0x950EF6B4L) > 0x88L) & l_173) && l_576)))) == l_251[2][6]), l_517)) || l_517))) || g_208[0]) >= l_538), l_576)), l_517)) <= l_538) & l_577) || g_99[1])) ^ g_359);
        }
      l_503[6][1][7] = 2L;
    }
  return g_97;
       }
   }





   l_251
     [2]
     [9] = (safe_mul_func_uint16_t_u_u ((p_94 ^ 0x654FB5CBL), l_580));


   for
     (l_279
      = 0; (l_279 > 29); l_279 = safe_add_func_int16_t_s_s (l_279, 5))
     {
       int64_t l_634 = 0x5FA7F40F6B3D5CD2LL;
       int32_t l_651 = 0xA61375C9L;
       int32_t l_657 = (-6L);
       int32_t l_736 = 0L;
       for
  (l_469
   =
   26;
   (l_469
    == (-17)); l_469 = safe_sub_func_int8_t_s_s (l_469, 1))
  {
    int16_t l_623 = 0x1C80L;
    int32_t l_624[9];
    uint16_t l_656 = 65535UL;
    int32_t l_664[3][10] =
    {
      {
      0x4162B7BDL,
   0L,
   1L,
   0L,
   0x4162B7BDL,
   0x130FEA67L, 0x130FEA67L, 0x4162B7BDL, 0L, 1L}
      ,
      {
      (-1L), (-1L), 1L, 0x4162B7BDL, (-9L), 0x4162B7BDL, 1L,
   (-1L), (-1L), 1L}
      ,
      {
      0L, 0x4162B7BDL, 0x130FEA67L, 0x130FEA67L, 0x4162B7BDL,
   0L, 1L, 0L, 0x4162B7BDL, 0x130FEA67L}
    };
    int i, j;


    {
      int16_t l_623 = 0x1C80L;
      int32_t l_624[9];
      uint16_t l_656 = 65535UL;
      int32_t l_664[3][10] =
      {
        {
        0x4162B7BDL,
     0L,
     1L,
     0L,
     0x4162B7BDL,
     0x130FEA67L, 0x130FEA67L, 0x4162B7BDL, 0L, 1L}
        ,
        {
        (-1L), (-1L), 1L, 0x4162B7BDL, (-9L), 0x4162B7BDL, 1L,
     (-1L), (-1L), 1L}
        ,
        {
        0L, 0x4162B7BDL, 0x130FEA67L, 0x130FEA67L,
     0x4162B7BDL, 0L, 1L, 0L, 0x4162B7BDL, 0x130FEA67L}
      };
      int i, j;
      for (i = 0; i < 9; i++)
        l_624[i] = 0x49E2B68EL;
      for
        (g_359
         =
         0;
         (g_359
   == 28); g_359 = safe_add_func_int16_t_s_s (g_359, 6))
        {
   uint32_t l_627 = 4294967295UL;
   l_604
     [2]
     =
     (safe_rshift_func_uint16_t_u_u
      ((safe_lshift_func_int8_t_s_s
        (((safe_lshift_func_int16_t_s_s
    ((l_580 >=
      (65533UL >=
       (g_575 >
        (((l_604[2] ^ g_236) ^ (p_94 != p_92)) !=
         ((l_623 =
           (safe_mul_func_uint16_t_u_u
     ((65533UL == (l_622 = p_94)),
      l_604[2]))) != g_4[1][4]))))),
     5)) | l_624[2]), g_540[0][0][0])), 6));
   l_251[2][9] =
     (((safe_rshift_func_uint16_t_u_u
        (l_580,
         ((l_627 =
    p_94) !=
          ((safe_lshift_func_uint8_t_u_s
     (l_623,
      (safe_add_func_int16_t_s_s
       (l_624[4],
        (((g_540[0][0][8] < l_623) >=
          ((safe_mod_func_uint64_t_u_u
     (1UL, (l_634 | g_540[0][0][4])))
           || 3UL)) == l_624[2])))))
    && g_208[2])))) > g_209) <
      0xCD8C874ED5640E0ALL);
   l_657 =
     ((g_208[0] <
       (+
        (((safe_add_func_uint8_t_u_u
    ((safe_mod_func_uint64_t_u_u
      ((safe_mod_func_uint64_t_u_u
        (0xF03CAD15DEDACC3BLL,
         (safe_mul_func_int16_t_s_s
          (((g_655 =
      (l_487 =
       (safe_sub_func_uint16_t_u_u
        ((g_178 =
          ((safe_add_func_int32_t_s_s
            (((((g_575 =
          g_98) > ((g_97
             &&
             ((g_455 =
        ((safe_mod_func_uint16_t_u_u (g_4[0][0], (l_651 = 9L))) && g_359)) & ((l_627 & (safe_lshift_func_uint16_t_u_u (g_178, 12))) >= 1L))) != 0x2156A169L)) <= l_654[3][0][4]) != g_236), p_94)) != p_94)), l_211)))) && l_651), l_627)))), g_359)), 0UL)) > 0x88DFL) ^ 3UL))) >= l_656);
   g_208[2] =
     (l_624[5] >=
      (l_664[0][8] =
       (safe_mod_func_int16_t_s_s
        ((((~g_280) != 4294967289UL) > (p_93 = g_178)),
         (l_541
          &&
          ((g_99[2] =
     (safe_sub_func_int32_t_s_s
      ((p_92 >=
        (safe_mul_func_int16_t_s_s
         (p_92, (-1L)))),
       (p_94 >= l_604[2])))) ^ l_627))))));
        }
      l_657
        =
        (l_676
         [4]
         =
         ((safe_add_func_uint8_t_u_u
    ((safe_mul_func_uint8_t_u_u
      (((l_487 =
         (255UL ^ (((1L & l_622) < l_634) | 250UL))) >=
        (safe_lshift_func_uint16_t_u_u
         ((safe_rshift_func_int16_t_s_s
    (((safe_add_func_int8_t_s_s (l_657, g_359)) &
      ((g_675 =
        g_359) & 4UL)), 0)), l_469))), l_634)),
     255UL)) == l_251[2][9]));
      for (g_236 = 0; (g_236 >= 45);
    g_236 = safe_add_func_uint8_t_u_u (g_236, 8))
        {
   return l_469;
        }
    }




    for (i = 0; i < 4; i++)
      l_604[i] = 1L;




    for
      (g_236
       =
       0;
       (g_236
        >= 45); g_236 = safe_add_func_uint8_t_u_u (g_236, 8))
      {
        return l_469;
      }
  }
       {
  int64_t l_502 = 0xB284F1512807B3F7LL;
  int32_t l_503[7][3][8] =
  {
    {
      {
      0x24AB212BL, 0xBFD57F4BL, 0x6FA1C930L, 7L, 0xD226A061L,
   5L, 0x81D3EAD7L, 0x97D46C52L}
      ,
      {
      0xA99503C9L,
   6L,
   0x8CAA2FA2L,
   0xB950D48EL,
   0xD8E4BD24L, 0x59E75CB0L, 0x7BFD730CL, 0x6FA1C930L}
      ,
      {
      0x8CAA2FA2L,
   0L, 5L, (-3L), 0x3469A6C3L, (-3L), 0xD226A061L, 0L}
    }
    ,
    {
      {
      0L, 2L, 0x36337888L, 0xBFD57F4BL, 0L, 0x6FA1C930L, 6L,
   0xB950D48EL}
      ,
      {
      0xD226A061L,
   0x81D3EAD7L,
   0xBFD57F4BL, 0x735146A9L, 0L, (-1L), 6L, (-1L)}
      ,
      {
      (-2L), 0x735146A9L, 0x36337888L, 0x6FA1C930L, 5L, 6L,
   0xD226A061L, 1L}
    }
    ,
    {
      {
      5L, 6L, 0xD226A061L, 1L, 0xB950D48EL, (-3L), 7L, 7L}
      ,
      {
      0x3469A6C3L,
   0xD8E4BD24L,
   2L, 2L, 0xD8E4BD24L, 0x3469A6C3L, (-1L), (-1L)}
      ,
      {
      0xA8990C81L,
   0x69D2D8EEL,
   0xD8E4BD24L, 5L, (-1L), 0x59E75CB0L, 5L, 0xD226A061L}
    }
    ,
    {
      {
      7L, 1L, 0x24AB212BL, 5L, (-1L), 0xB950D48EL,
   0x69D2D8EEL, (-1L)}
      ,
      {
      0xBFD57F4BL,
   (-1L), 0xA99503C9L, 2L, 0x92F04986L, 1L, 5L, 7L}
      ,
      {
      0L,
   0xA8990C81L,
   0x8CAA2FA2L, 1L, (-8L), 0xA99503C9L, (-8L), 1L}
    }
    ,
    {
      {
      0x735146A9L, (-1L), 0x735146A9L, 0x6FA1C930L,
   0xA8990C81L, 0L, 0xBFD57F4BL, (-1L)}
      ,
      {
      0x24AB212BL,
   0L,
   5L,
   0x735146A9L,
   0x81D3EAD7L, (-1L), 0xA8990C81L, 0xB950D48EL}
      ,
      {
      0x24AB212BL,
   5L,
   0x92F04986L,
   0xBFD57F4BL, 0xA8990C81L, 0L, 0x36337888L, 0L}
    }
    ,
    {
      {
      0x735146A9L, (-3L), 0x59E75CB0L, 0x8CAA2FA2L, (-8L),
   0xBFD57F4BL, (-2L), 0xD8E4BD24L}
      ,
      {
      0L,
   0x59E75CB0L,
   (-1L),
   0x92F04986L, 0x92F04986L, (-1L), 0x59E75CB0L, 0L}
      ,
      {
      0xBFD57F4BL,
   5L, (-8L), (-1L), (-1L), 0L, 0xA99503C9L, 0x7BFD730CL}
    }
    ,
    {
      {
      7L, 0L, 0x7BFD730CL, (-2L), (-1L), 0L, 0x735146A9L,
   0x3469A6C3L}
      ,
      {
      0xA8990C81L,
   5L, 0L, 0L, 0xD8E4BD24L, (-1L), (-1L), (-1L)}
      ,
      {
      0x3469A6C3L,
   0x59E75CB0L,
   0x97D46C52L,
   (-1L), 0xB950D48EL, 0xBFD57F4BL, (-3L), 0xBFD57F4BL}
    }
  };
  int16_t l_516 = 0x481AL;
  int16_t l_576 = 0xB260L;
  int i, j, k;
  if (p_92)
    {
      int16_t l_486 = 0x96E4L;
      uint32_t l_514 = 18446744073709551615UL;
      l_487
        =
        (safe_mul_func_int16_t_s_s
         (((safe_sub_func_uint8_t_u_u
     ((safe_lshift_func_int8_t_s_s
       ((((l_469 = 0xBAL) && 0x3CL)
         && 0xC49D329C4F5B0900LL),
        ((safe_mul_func_int8_t_s_s
          ((((safe_sub_func_int32_t_s_s ((-1L), g_280)) &
      (((safe_unary_minus_func_uint16_t_u
         ((g_178 = p_94)))
        &&
        (((0x558134D8C914E6DELL > g_209) >=
          (safe_rshift_func_uint8_t_u_u
           ((safe_rshift_func_uint16_t_u_s
      (0xDF32L, p_94)), 2))) ^ l_470))
       && 4294967295UL)) | l_486),
    0xE1L)) == 3UL))), g_455)) == l_464), g_209));
      for (l_487 = (-8); (l_487 > (-14)); --l_487)
        {
   uint8_t l_515[5] =
   {
   0x53L, 0x53L, 0x53L, 0x53L, 0x53L};
   int i;
   l_516
     =
     (((g_209
        || p_93) <=
       (~
        ((safe_sub_func_uint32_t_u_u
          ((safe_mul_func_uint8_t_u_u
     ((((9UL ==
         (((safe_add_func_uint8_t_u_u
     ((safe_sub_func_uint64_t_u_u
       ((safe_sub_func_int16_t_s_s
         (((safe_rshift_func_int8_t_s_s
            (p_94,
      (l_503[6][1][7] =
       (0xE9200326L !=
        (l_502 =
         1UL))))) ^
           ((safe_mul_func_int8_t_s_s
      ((5UL &
        (safe_sub_func_uint8_t_u_u
         (((l_210 =
            (safe_rshift_func_uint8_t_u_s
             ((l_469 =
        (safe_sub_func_uint64_t_u_u
         ((p_94 <=
           (((safe_lshift_func_int16_t_s_u (g_4[1][2], 11)) >= l_514) | 0xCD04215EL)), 0x594DEE00CD75C92ELL))), p_94))) <= g_357), 0x70L))), p_94)) && g_189)), p_93)), p_92)), l_515[1])) || 0x63D4L) > g_357)) || g_209) ^ 0x81D7L), l_470)), 1UL)) != l_229))) == p_94);
        }
      return g_359;
    }
  else
    {
      int32_t l_517 = 1L;
      g_208[2] = l_517;
      for (p_92 = 0; (p_92 <= 16); p_92++)
        {
   uint32_t l_538 = 0x10A82951L;
   int32_t l_539 = 0x2158B6CBL;
   for (g_455 = 0; (g_455 >= 7); ++g_455)
     {
       int8_t l_542 = 0L;
       int32_t l_577 = 0x058D355FL;
       l_542
         =
         (!
          ((((g_455 >
       (g_540[0][0][0] =
        ((g_209 <
          g_280) |
         ((safe_mul_func_int16_t_s_s
           ((l_539 =
      ((((safe_lshift_func_int8_t_s_u
          ((((l_469 = p_92)
      &&
      ((((((safe_mul_func_int8_t_s_s
            (p_93,
             (g_359 =
       (p_94 =
        (safe_mul_func_int16_t_s_s
         (((safe_mod_func_int16_t_s_s (((safe_add_func_int8_t_s_s ((l_538 = (safe_lshift_func_int8_t_s_u (((g_4[1][2] | ((-10L) == ((safe_sub_func_int64_t_s_s (p_93, (p_93 != p_93))) == (-6L)))) == g_98), l_470))), p_94)) < p_93), 0x1002L)) || g_208[0]), p_92)))))) > l_517) && p_93) >= 0UL) ^ l_539) | 6L)) == g_280), 7)) & p_93) | l_454[4]) > 0x67318379L)), g_208[2])) >= 0x860F0DB8L)))) & l_541) != l_487) & g_4[1][2]));
       g_208[2] =
         ((((p_93 > 3L)
     || g_209) ==
    ((p_94 ^ g_540[0][0][0]) ^ 0UL)) ^
          0x76918559L);
       g_208[2] =
         ((l_487 =
    ((((safe_rshift_func_uint16_t_u_s
        ((safe_mul_func_uint16_t_u_u
          (((((safe_lshift_func_int8_t_s_s
        ((p_92 <
          (safe_unary_minus_func_uint16_t_u
           (((!
       (safe_rshift_func_uint8_t_u_u
        ((l_539 =
          g_209), 2))) <= 4UL)))),
         0)) == (l_542
          ||
          ((safe_rshift_func_int16_t_s_u (((safe_unary_minus_func_uint8_t_u ((g_236 = (((((g_575 = (((g_357 = (safe_rshift_func_uint16_t_u_u ((safe_rshift_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u ((safe_lshift_func_uint8_t_u_s (g_359, 3)), (safe_sub_func_uint64_t_u_u ((p_92 & ((safe_mod_func_uint32_t_u_u (l_454[0], ((safe_sub_func_int32_t_s_s ((safe_mul_func_uint16_t_u_u ((safe_add_func_int64_t_s_s ((p_92 || 0x20157C39L), p_92)), g_236)), p_94)) & p_93))) != 254UL)), l_469)))), 4)), 0))) & l_211) < 0L)) != 0x950EF6B4L) > 0x88L) & l_173) && l_576)))) == l_251[2][6]), l_517)) || l_517))) || g_208[0]) >= l_538), l_576)), l_517)) <= l_538) & l_577) || g_99[1])) ^ g_359);
     }
   l_503[6][1][7] = 2L;
        }
      return g_97;
    }
       }
     }
   for
     (l_279
      = 0; (l_279 > 29); l_279 = safe_add_func_int16_t_s_s (l_279, 5))
     {
       int64_t l_634 = 0x5FA7F40F6B3D5CD2LL;
       int32_t l_651 = 0xA61375C9L;
       int32_t l_657 = (-6L);
       int32_t l_736 = 0L;
       for
  (l_469
   =
   26;
   (l_469
    == (-17)); l_469 = safe_sub_func_int8_t_s_s (l_469, 1))
  {
    int16_t l_623 = 0x1C80L;
    int32_t l_624[9];
    uint16_t l_656 = 65535UL;
    int32_t l_664[3][10] =
    {
      {
      0x4162B7BDL,
   0L,
   1L,
   0L,
   0x4162B7BDL,
   0x130FEA67L, 0x130FEA67L, 0x4162B7BDL, 0L, 1L}
      ,
      {
      (-1L), (-1L), 1L, 0x4162B7BDL, (-9L), 0x4162B7BDL, 1L,
   (-1L), (-1L), 1L}
      ,
      {
      0L, 0x4162B7BDL, 0x130FEA67L, 0x130FEA67L, 0x4162B7BDL,
   0L, 1L, 0L, 0x4162B7BDL, 0x130FEA67L}
    };
    int i, j;
    for (i = 0; i < 9; i++)
      l_624[i] = 0x49E2B68EL;
    for
      (g_359
       =
       0;
       (g_359
        == 28); g_359 = safe_add_func_int16_t_s_s (g_359, 6))
      {
        uint32_t l_627 = 4294967295UL;
        l_604
   [2]
   =
   (safe_rshift_func_uint16_t_u_u
    ((safe_lshift_func_int8_t_s_s
      (((safe_lshift_func_int16_t_s_s
         ((l_580 >=
    (65533UL >=
     (g_575 >
      (((l_604[2] ^ g_236) ^ (p_94 != p_92)) !=
       ((l_623 =
         (safe_mul_func_uint16_t_u_u
          ((65533UL == (l_622 = p_94)),
           l_604[2]))) != g_4[1][4]))))),
          5)) | l_624[2]), g_540[0][0][0])), 6));
        l_251[2][9] =
   (((safe_rshift_func_uint16_t_u_u
      (l_580,
       ((l_627 =
         p_94) !=
        ((safe_lshift_func_uint8_t_u_s
          (l_623,
    (safe_add_func_int16_t_s_s
     (l_624[4],
      (((g_540[0][0][8] < l_623) >=
        ((safe_mod_func_uint64_t_u_u
          (1UL, (l_634 | g_540[0][0][4])))
         || 3UL)) == l_624[2])))))
         && g_208[2])))) > g_209) <
    0xCD8C874ED5640E0ALL);
        l_657 =
   ((g_208[0] <
     (+
      (((safe_add_func_uint8_t_u_u
         ((safe_mod_func_uint64_t_u_u
    ((safe_mod_func_uint64_t_u_u
      (0xF03CAD15DEDACC3BLL,
       (safe_mul_func_int16_t_s_s
        (((g_655 =
           (l_487 =
     (safe_sub_func_uint16_t_u_u
      ((g_178 =
        ((safe_add_func_int32_t_s_s
          (((((g_575 =
        g_98) > ((g_97
           &&
           ((g_455 =
             ((safe_mod_func_uint16_t_u_u (g_4[0][0], (l_651 = 9L))) && g_359)) & ((l_627 & (safe_lshift_func_uint16_t_u_u (g_178, 12))) >= 1L))) != 0x2156A169L)) <= l_654[3][0][4]) != g_236), p_94)) != p_94)), l_211)))) && l_651), l_627)))), g_359)), 0UL)) > 0x88DFL) ^ 3UL))) >= l_656);
        g_208[2] =
   (l_624[5] >=
    (l_664[0][8] =
     (safe_mod_func_int16_t_s_s
      ((((~g_280) != 4294967289UL) > (p_93 = g_178)),
       (l_541
        &&
        ((g_99[2] =
          (safe_sub_func_int32_t_s_s
    ((p_92 >=
      (safe_mul_func_int16_t_s_s (p_92, (-1L)))),
     (p_94 >= l_604[2])))) ^ l_627))))));
      }
    l_657
      =
      (l_676
       [4]
       =
       ((safe_add_func_uint8_t_u_u
         ((safe_mul_func_uint8_t_u_u
    (((l_487 =
       (255UL ^ (((1L & l_622) < l_634) | 250UL))) >=
      (safe_lshift_func_uint16_t_u_u
       ((safe_rshift_func_int16_t_s_s
         (((safe_add_func_int8_t_s_s (l_657, g_359)) &
    ((g_675 =
      g_359) & 4UL)), 0)), l_469))), l_634)),
   255UL)) == l_251[2][9]));
    for (g_236 = 0; (g_236 >= 45);
         g_236 = safe_add_func_uint8_t_u_u (g_236, 8))
      {
        return l_469;
      }
  }
       l_210
  =
  (g_4
   [0]
   [7]
   >
   ((l_657 =
     ((~
       (g_357 =
        (!(g_99[2] ==
    (4294967289UL &
     ((safe_rshift_func_uint16_t_u_u
       (((safe_mod_func_int64_t_s_s
          ((safe_lshift_func_uint8_t_u_u
     (0x3CL,
      (safe_sub_func_int32_t_s_s
       (((((~
     (safe_sub_func_int32_t_s_s
      ((safe_add_func_int64_t_s_s
        ((safe_mod_func_uint8_t_u_u
          ((safe_rshift_func_uint16_t_u_u
            ((((l_604[3] =
         (safe_sub_func_uint64_t_u_u
          ((l_604[3] <
            (safe_rshift_func_uint8_t_u_u
             ((safe_sub_func_uint16_t_u_u (((l_676[1] = p_93) < 0xD9131F3BL), (l_704 = (safe_add_func_uint32_t_u_u ((((p_94 != (((-5L) > 0UL) ^ 0x26L)) <= l_654[4][1][4]) > g_703), l_469))))), 5))), p_92))) > (-1L)) <= 0xA12176B7DF624563LL), 7)), 0xA6L)), g_359)), g_98))) || 0xEA10L) && g_540[0][0][5]) & 0x68ACF380L), 4294967293UL)))), g_99[1])) == 0xC7686749C67A710CLL), 6)) <= g_655)))))) > g_540[0][0][0])) < l_469));
       if ((((l_622 <
       ((((l_676[0] =
    p_93) >=
   (l_464 |
    (safe_sub_func_int16_t_s_s
     ((((safe_add_func_int32_t_s_s
         (p_93,
          (((((safe_sub_func_uint8_t_u_u
        ((safe_add_func_int8_t_s_s
          (((l_229 =
      g_189) !=
     ((!(safe_mul_func_uint16_t_u_u
         (((safe_rshift_func_int8_t_s_s
            ((safe_mod_func_uint8_t_u_u
       (((safe_add_func_uint8_t_u_u
          ((safe_lshift_func_uint16_t_u_u (((((((safe_mod_func_uint8_t_u_u (((safe_add_func_uint64_t_u_u ((g_189 <= (safe_mod_func_uint16_t_u_u (((safe_add_func_uint32_t_u_u (l_580, (+g_236))) || ((l_469 = (safe_mul_func_uint16_t_u_u (((safe_mod_func_int64_t_s_s (g_575, 0xFC8EF02696175EAFLL)) & g_703), 0xD644L))) && 1L)), l_251[3][0]))), g_236)) | g_655), 251UL)) > g_575) >= (-10L)) && p_92) && p_92) & l_541), g_540[0][0][9])), 0x42L)) >= g_178), g_208[2])), l_634)) <= l_634), g_455))) || g_4[1][2])), p_94)), p_92)) <= 0xB3L) & l_487) ^ p_92) && g_97))) >= l_735) ^ l_736), l_735)))) != 0xEA41L) || l_737[0][0])) < 0xFE70F53EL) || l_738))
  {
    uint16_t l_741 = 0x08A3L;
    int32_t l_754[3];
    int i;
    for (i = 0; i < 3; i++)
      l_754[i] = 1L;
    if ((l_657 = g_98))
      {
        l_210
   =
   (l_741
    = (safe_rshift_func_uint16_t_u_u (g_208[2], 12)));
      }
    else
      {
        int32_t l_768 = 0xC63D3A7DL;
        l_704
   =
   (safe_sub_func_uint32_t_u_u
    (((!l_741) &
      ((g_4[1][1]
        ||
        (safe_sub_func_int64_t_s_s
         (0x9BA1CD3E25E155DFLL,
          (((p_94 =
      p_92) | ((l_754[2] =
         (safe_mod_func_uint16_t_u_u
          ((safe_sub_func_int32_t_s_s
            (((safe_add_func_int16_t_s_s
        ((l_737[0][0] <
          (7UL
           && p_92)),
         ((safe_mul_func_uint8_t_u_u
           (p_92,
            (g_4[1][2] ^ l_741)))
          && p_93))) != p_93),
      p_92)), 0x69E3L)))
        && g_4[1][2])) > g_675)))) <
       g_4[0][3])), 0x9A0458D6L));
        if (l_211)
   goto lbl_755;
        l_676
   [3]
   =
   (safe_sub_func_int64_t_s_s
    (g_98,
     (safe_mul_func_uint16_t_u_u
      ((+
        (((l_657 =
    ((safe_mul_func_uint8_t_u_u
      ((safe_mod_func_uint64_t_u_u
        ((safe_mul_func_uint8_t_u_u
          ((((safe_mod_func_uint32_t_u_u
       (g_97, p_92)) ^ (0x2804L > (l_768 =
              g_98)))
     != (0xBA68L <= (g_357 > p_92))),
           ((safe_rshift_func_uint16_t_u_u
      ((safe_rshift_func_int16_t_s_u
        ((safe_rshift_func_int16_t_s_u
          ((l_211 =
            (safe_lshift_func_uint16_t_u_s
      (((l_754[2] =
         l_657) <=
        0xBD81C3C37A7CA171LL),
       12))), g_703)), p_94)),
       9)) > g_575))), g_4[1][0])),
       g_675)) | l_580)) | g_209)
         && p_93)), 0x2CECL))));
      }
  }
       else
  {
    int32_t l_805 = 0L;
    int32_t l_809[6] =
    {
    0x4B0EAF7DL,
        0x4B0EAF7DL,
        0x4B0EAF7DL, 0x4B0EAF7DL, 0x4B0EAF7DL, 0x4B0EAF7DL};
    int i;
    g_575 = 0L;
    l_657
      =
      ((safe_add_func_uint8_t_u_u
        ((1L
   && g_236),
         (safe_rshift_func_int8_t_s_s
   ((safe_mul_func_int16_t_s_s
     ((safe_rshift_func_uint8_t_u_u
       ((l_809[0] =
         ((safe_rshift_func_uint8_t_u_u
    ((p_94 = g_189), 6))
          || (g_359 =
       (((safe_rshift_func_uint16_t_u_u
          ((0xD97EL |
     (safe_mul_func_int8_t_s_s
      ((+
        ((safe_unary_minus_func_int32_t_s
          (g_280)) ^
         (safe_lshift_func_int16_t_s_s
          (((((l_808 =
        (((l_704 =
           (safe_unary_minus_func_uint8_t_u
            ((p_94 =
       ((l_604[1] =
         (safe_rshift_func_int16_t_s_s
          (g_4[1][5],
           (safe_mul_func_int8_t_s_s
            ((safe_add_func_int32_t_s_s ((safe_mod_func_uint8_t_u_u (l_676[4], ((((g_357 = (safe_add_func_uint8_t_u_u (((g_806 = (l_805 = 7L)) || (l_736 = (g_236 >= l_807))), p_94))) >= 0xDDL) || 0x56F5195AL) & 0x4565F4F100E99619LL))), g_703)), p_92))))) < g_97))))) || p_94) || g_280)) && g_357) <= p_92) | l_676[4]), g_99[0])))), 255UL))), 12)) | l_487) <= 1UL)))), g_208[2])), 4UL)), 7)))) & (-1L));
  }
       g_208
  [0]
  =
  (safe_rshift_func_int16_t_s_s
   ((p_92 >
     (((+(-1L))
       && p_92) <
      (safe_lshift_func_int16_t_s_s
       ((safe_sub_func_int8_t_s_s
         ((safe_mod_func_int8_t_s_s
    ((l_622
      &&
      (safe_mod_func_uint64_t_u_u
       ((l_808 =
         0xF036CAF7C5DB8C90LL), ((p_94
             ||
             ((safe_add_func_int32_t_s_s (((safe_mod_func_int8_t_s_s (l_454[2], g_357)) | ((g_806 = p_94) | (-1L))), g_675)) <= p_93)) & p_93)))), p_92)), l_676[4])), g_4[1][2])))), g_655));
     }



 }
      l_211
 =
 (safe_rshift_func_uint16_t_u_u
  ((g_178 !=
    ((g_99[3] =
      (safe_mod_func_uint16_t_u_u
       ((((l_210 =
    (safe_lshift_func_uint16_t_u_u
     ((~
       (safe_sub_func_uint32_t_u_u
        (p_92,
         (g_189 |
   ((safe_mod_func_uint64_t_u_u
     (((p_94 =
        (((safe_mul_func_uint16_t_u_u
    (0x4C97L,
     ((safe_lshift_func_int16_t_s_u
       ((g_209 =
         (g_208[2] =
          (~
           (safe_lshift_func_uint8_t_u_u
     (((((safe_add_func_int8_t_s_s
          ((8UL
            && g_98),
           (65533UL <= p_92))) >=
         0xC2FFDF52C73AE872LL) != l_173) >
       p_92), l_173))))),
        5)) > p_92))) & 0xF2569BDC76872175LL) >
         0x8814L)) | l_173), l_173)) | 0xB29FL))))),
      p_93))) ^ 0UL) != p_93), l_173))) ^ g_189)), 1));



      l_229 = (safe_lshift_func_uint16_t_u_u (0xAED3L, 7));
      l_211
 =
 (safe_rshift_func_uint16_t_u_u
  ((g_178 !=
    ((g_99[3] =
      (safe_mod_func_uint16_t_u_u
       ((((l_210 =
    (safe_lshift_func_uint16_t_u_u
     ((~
       (safe_sub_func_uint32_t_u_u
        (p_92,
         (g_189 |
   ((safe_mod_func_uint64_t_u_u
     (((p_94 =
        (((safe_mul_func_uint16_t_u_u
    (0x4C97L,
     ((safe_lshift_func_int16_t_s_u
       ((g_209 =
         (g_208[2] =
          (~
           (safe_lshift_func_uint8_t_u_u
     (((((safe_add_func_int8_t_s_s
          ((8UL
            && g_98),
           (65533UL <= p_92))) >=
         0xC2FFDF52C73AE872LL) != l_173) >
       p_92), l_173))))),
        5)) > p_92))) & 0xF2569BDC76872175LL) >
         0x8814L)) | l_173), l_173)) | 0xB29FL))))),
      p_93))) ^ 0UL) != p_93), l_173))) ^ g_189)), 1));



    }
  return p_92;
}







static int32_t func_100 (uint32_t p_101)
{
  int16_t l_130 = 0xAFD8L;
  int32_t l_132 = 0x379FF8A6L;
  int16_t l_150 = 0L;
  for (g_97 = (-2); (g_97 <= (-11)); g_97--)
    {
      int32_t l_129[3];
      uint64_t l_152 = 0x2A5DBB92B385C65ELL;
      int32_t l_153 = (-1L);
      int i;


      for (i = 0; i < 3; i++)
 l_129[i] = 7L;




      for
 (p_101
  = 24; (p_101 == 24); p_101 = safe_add_func_uint16_t_u_u (p_101, 8))
 {
   uint64_t l_131 = 0x37EAFC3DE15252ECLL;
   int32_t l_133 = 0x9BFB87D1L;


 }




    }
  return p_101;
}





int
main (void)
{
  int i, j, k;
  int print_hash_value = 0;
  crc32_gentab ();
  func_1 ();
  transparent_crc (g_3, "g_3", print_hash_value);
  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 10; j++)
 {
   transparent_crc (g_4[i][j], "g_4[i][j]", print_hash_value);
   if (print_hash_value)
     printf ("index = [%d][%d]\n", i, j);

 }
    }
  transparent_crc (g_56, "g_56", print_hash_value);
  transparent_crc (g_75, "g_75", print_hash_value);
  transparent_crc (g_97, "g_97", print_hash_value);
  transparent_crc (g_98, "g_98", print_hash_value);
  for (i = 0; i < 4; i++)
    {
      transparent_crc (g_99[i], "g_99[i]", print_hash_value);
      if (print_hash_value)
 printf ("index = [%d]\n", i);

    }
  transparent_crc (g_178, "g_178", print_hash_value);
  transparent_crc (g_189, "g_189", print_hash_value);
  for (i = 0; i < 3; i++)
    {
      transparent_crc (g_208[i], "g_208[i]", print_hash_value);
      if (print_hash_value)
 printf ("index = [%d]\n", i);

    }
  transparent_crc (g_209, "g_209", print_hash_value);
  transparent_crc (g_236, "g_236", print_hash_value);
  transparent_crc (g_280, "g_280", print_hash_value);
  transparent_crc (g_357, "g_357", print_hash_value);
  transparent_crc (g_359, "g_359", print_hash_value);
  transparent_crc (g_455, "g_455", print_hash_value);
  for (i = 0; i < 1; i++)
    {
      for (j = 0; j < 1; j++)
 {
   for (k = 0; k < 10; k++)
     {
       transparent_crc
  (g_540[i][j][k], "g_540[i][j][k]", print_hash_value);
       if (print_hash_value)
  printf ("index = [%d][%d][%d]\n", i, j, k);

     }
 }
    }
  transparent_crc (g_575, "g_575", print_hash_value);
  transparent_crc (g_655, "g_655", print_hash_value);
  transparent_crc (g_675, "g_675", print_hash_value);
  transparent_crc (g_703, "g_703", print_hash_value);
  transparent_crc (g_806, "g_806", print_hash_value);
  transparent_crc (g_897, "g_897", print_hash_value);
  transparent_crc (g_902, "g_902", print_hash_value);
  for (i = 0; i < 8; i++)
    {
      for (j = 0; j < 10; j++)
 {
   for (k = 0; k < 1; k++)
     {
       transparent_crc
  (g_921[i][j][k], "g_921[i][j][k]", print_hash_value);
       if (print_hash_value)
  printf ("index = [%d][%d][%d]\n", i, j, k);

     }
 }
    }
  transparent_crc (g_922, "g_922", print_hash_value);
  transparent_crc (g_983, "g_983", print_hash_value);
  transparent_crc (g_1060, "g_1060", print_hash_value);
  for (i = 0; i < 1; i++)
    {
      for (j = 0; j < 10; j++)
 {
   transparent_crc (g_1081[i][j], "g_1081[i][j]", print_hash_value);
   if (print_hash_value)
     printf ("index = [%d][%d]\n", i, j);

 }
    }
  for (i = 0; i < 3; i++)
    {
      transparent_crc (g_1182[i], "g_1182[i]", print_hash_value);
      if (print_hash_value)
 printf ("index = [%d]\n", i);

    }
  transparent_crc (g_1272, "g_1272", print_hash_value);
  transparent_crc (g_1394, "g_1394", print_hash_value);
  transparent_crc (g_1395, "g_1395", print_hash_value);
  transparent_crc (g_1513, "g_1513", print_hash_value);
  transparent_crc (g_1551, "g_1551", print_hash_value);
  transparent_crc (g_1678, "g_1678", print_hash_value);
  transparent_crc (g_1863, "g_1863", print_hash_value);
  transparent_crc (g_1923, "g_1923", print_hash_value);
  transparent_crc (g_2227, "g_2227", print_hash_value);
  transparent_crc (g_2241, "g_2241", print_hash_value);
  transparent_crc (g_2519, "g_2519", print_hash_value);
  transparent_crc (g_2599, "g_2599", print_hash_value);
  transparent_crc (g_2791, "g_2791", print_hash_value);
  transparent_crc (g_2945, "g_2945", print_hash_value);
  transparent_crc (g_2974, "g_2974", print_hash_value);
  transparent_crc (g_3175, "g_3175", print_hash_value);
  transparent_crc (g_3331, "g_3331", print_hash_value);
  transparent_crc (g_3487, "g_3487", print_hash_value);
  transparent_crc (g_3807, "g_3807", print_hash_value);
  transparent_crc (g_3898, "g_3898", print_hash_value);
  transparent_crc (g_3950, "g_3950", print_hash_value);
  transparent_crc (g_4447, "g_4447", print_hash_value);
  for (i = 0; i < 3; i++)
    {
      transparent_crc (g_4576[i], "g_4576[i]", print_hash_value);
      if (print_hash_value)
 printf ("index = [%d]\n", i);

    }
  transparent_crc (g_4669, "g_4669", print_hash_value);
  transparent_crc (g_4880, "g_4880", print_hash_value);
  transparent_crc (g_5019, "g_5019", print_hash_value);
  platform_main_end (crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}

typedef unsigned int size_t;
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long long int int64_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;
int printf(const char *, ...);
void __assert_fail(const char *__assertion, const char *__file,
                   unsigned int __line, const char *__function);
static void platform_main_end(uint32_t crc, int flag) {
  printf("checksum = %X\n", crc);
}
static int8_t(safe_unary_minus_func_int8_t_s)(int8_t si) { return -si; }
static int8_t(safe_add_func_int8_t_s_s)(int8_t si1, int8_t si2) {
  return (si1 + si2);
}
static int8_t(safe_sub_func_int8_t_s_s)(int8_t si1, int8_t si2) {
  return (si1 - si2);
}
static int8_t(safe_mul_func_int8_t_s_s)(int8_t si1, int8_t si2) {
  return si1 * si2;
}
static int8_t(safe_mod_func_int8_t_s_s)(int8_t si1, int8_t si2) {
  return ((si2 == 0) || ((si1 == (-128)) && (si2 == (-1)))) ? ((si1))
                                                            : (si1 % si2);
}
static int8_t(safe_div_func_int8_t_s_s)(int8_t si1, int8_t si2) {
  return ((si2 == 0) || ((si1 == (-128)) && (si2 == (-1)))) ? ((si1))
                                                            : (si1 / si2);
}
static int8_t(safe_lshift_func_int8_t_s_s)(int8_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((127) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static int8_t(safe_lshift_func_int8_t_s_u)(int8_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32) ||
          (left > ((127) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static int8_t(safe_rshift_func_int8_t_s_s)(int8_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
             ? ((left))
             : (left >> ((int)right));
}
static int8_t(safe_rshift_func_int8_t_s_u)(int8_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32))
             ? ((left))
             : (left >> ((unsigned int)right));
}
static int16_t(safe_unary_minus_func_int16_t_s)(int16_t si) { return -si; }
static int16_t(safe_add_func_int16_t_s_s)(int16_t si1, int16_t si2) {
  return (si1 + si2);
}
static int16_t(safe_sub_func_int16_t_s_s)(int16_t si1, int16_t si2) {
  return (si1 - si2);
}
static int16_t(safe_mul_func_int16_t_s_s)(int16_t si1, int16_t si2) {
  return si1 * si2;
}
static int16_t(safe_mod_func_int16_t_s_s)(int16_t si1, int16_t si2) {
  return ((si2 == 0) || ((si1 == (-32767 - 1)) && (si2 == (-1)))) ? ((si1))
                                                                  : (si1 % si2);
}
static int16_t(safe_div_func_int16_t_s_s)(int16_t si1, int16_t si2) {
  return ((si2 == 0) || ((si1 == (-32767 - 1)) && (si2 == (-1)))) ? ((si1))
                                                                  : (si1 / si2);
}
static int16_t(safe_lshift_func_int16_t_s_s)(int16_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((32767) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static int16_t(safe_lshift_func_int16_t_s_u)(int16_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32) ||
          (left > ((32767) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static int16_t(safe_rshift_func_int16_t_s_s)(int16_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
             ? ((left))
             : (left >> ((int)right));
}
static int16_t(safe_rshift_func_int16_t_s_u)(int16_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32))
             ? ((left))
             : (left >> ((unsigned int)right));
}
static int32_t(safe_unary_minus_func_int32_t_s)(int32_t si) {
  return (si == (-2147483647 - 1)) ? ((si)) : -si;
}
static int32_t(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2) {
  return (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) - si2))) ||
          ((si1 < 0) && (si2 < 0) && (si1 < ((-2147483647 - 1) - si2))))
             ? ((si1))
             : (si1 + si2);
}
static int32_t(safe_sub_func_int32_t_s_s)(int32_t si1, int32_t si2) {
  return (((si1 ^ si2) &
           (((si1 ^ ((si1 ^ si2) & (~(2147483647)))) - si2) ^ si2)) < 0)
             ? ((si1))
             : (si1 - si2);
}
static int32_t(safe_mul_func_int32_t_s_s)(int32_t si1, int32_t si2) {
  return (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) / si2))) ||
          ((si1 > 0) && (si2 <= 0) && (si2 < ((-2147483647 - 1) / si1))) ||
          ((si1 <= 0) && (si2 > 0) && (si1 < ((-2147483647 - 1) / si2))) ||
          ((si1 <= 0) && (si2 <= 0) && (si1 != 0) &&
           (si2 < ((2147483647) / si1))))
             ? ((si1))
             : si1 * si2;
}
static int32_t(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2) {
  return ((si2 == 0) || ((si1 == (-2147483647 - 1)) && (si2 == (-1))))
             ? ((si1))
             : (si1 % si2);
}
static int32_t(safe_div_func_int32_t_s_s)(int32_t si1, int32_t si2) {
  return ((si2 == 0) || ((si1 == (-2147483647 - 1)) && (si2 == (-1))))
             ? ((si1))
             : (si1 / si2);
}
static int32_t(safe_lshift_func_int32_t_s_s)(int32_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((2147483647) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static int32_t(safe_lshift_func_int32_t_s_u)(int32_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32) ||
          (left > ((2147483647) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static int32_t(safe_rshift_func_int32_t_s_s)(int32_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
             ? ((left))
             : (left >> ((int)right));
}
static int32_t(safe_rshift_func_int32_t_s_u)(int32_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32))
             ? ((left))
             : (left >> ((unsigned int)right));
}
static int64_t(safe_unary_minus_func_int64_t_s)(int64_t si) {
  return (si == (-9223372036854775807L - 1)) ? ((si)) : -si;
}
static int64_t(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2) {
  return (((si1 > 0) && (si2 > 0) && (si1 > ((9223372036854775807L) - si2))) ||
          ((si1 < 0) && (si2 < 0) &&
           (si1 < ((-9223372036854775807L - 1) - si2))))
             ? ((si1))
             : (si1 + si2);
}
static int64_t(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2) {
  return (((si1 ^ si2) &
           (((si1 ^ ((si1 ^ si2) & (~(9223372036854775807L)))) - si2) ^ si2)) <
          0)
             ? ((si1))
             : (si1 - si2);
}
static int64_t(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2) {
  return (((si1 > 0) && (si2 > 0) && (si1 > ((9223372036854775807L) / si2))) ||
          ((si1 > 0) && (si2 <= 0) &&
           (si2 < ((-9223372036854775807L - 1) / si1))) ||
          ((si1 <= 0) && (si2 > 0) &&
           (si1 < ((-9223372036854775807L - 1) / si2))) ||
          ((si1 <= 0) && (si2 <= 0) && (si1 != 0) &&
           (si2 < ((9223372036854775807L) / si1))))
             ? ((si1))
             : si1 * si2;
}
static int64_t(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2) {
  return ((si2 == 0) || ((si1 == (-9223372036854775807L - 1)) && (si2 == (-1))))
             ? ((si1))
             : (si1 % si2);
}
static int64_t(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2) {
  return ((si2 == 0) || ((si1 == (-9223372036854775807L - 1)) && (si2 == (-1))))
             ? ((si1))
             : (si1 / si2);
}
static int64_t(safe_lshift_func_int64_t_s_s)(int64_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((9223372036854775807L) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static int64_t(safe_lshift_func_int64_t_s_u)(int64_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32) ||
          (left > ((9223372036854775807L) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static int64_t(safe_rshift_func_int64_t_s_s)(int64_t left, int right) {
  return ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))
             ? ((left))
             : (left >> ((int)right));
}
static int64_t(safe_rshift_func_int64_t_s_u)(int64_t left, unsigned int right) {
  return ((left < 0) || (((unsigned int)right) >= 32))
             ? ((left))
             : (left >> ((unsigned int)right));
}
static uint8_t(safe_unary_minus_func_uint8_t_u)(uint8_t ui) { return -ui; }
static uint8_t(safe_add_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {
  return ui1 + ui2;
}
static uint8_t(safe_sub_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {
  return ui1 - ui2;
}
static uint8_t(safe_mul_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {
  return ((unsigned int)ui1) * ((unsigned int)ui2);
}
static uint8_t(safe_mod_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 % ui2);
}
static uint8_t(safe_div_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 / ui2);
}
static uint8_t(safe_lshift_func_uint8_t_u_s)(uint8_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((255) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static uint8_t(safe_lshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {
  return ((((unsigned int)right) >= 32) ||
          (left > ((255) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static uint8_t(safe_rshift_func_uint8_t_u_s)(uint8_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32)) ? ((left))
                                                      : (left >> ((int)right));
}
static uint8_t(safe_rshift_func_uint8_t_u_u)(uint8_t left, unsigned int right) {
  return (((unsigned int)right) >= 32) ? ((left))
                                       : (left >> ((unsigned int)right));
}
static uint16_t(safe_unary_minus_func_uint16_t_u)(uint16_t ui) { return -ui; }
static uint16_t(safe_add_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {
  return ui1 + ui2;
}
static uint16_t(safe_sub_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {
  return ui1 - ui2;
}
static uint16_t(safe_mul_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {
  return ((unsigned int)ui1) * ((unsigned int)ui2);
}
static uint16_t(safe_mod_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 % ui2);
}
static uint16_t(safe_div_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 / ui2);
}
static uint16_t(safe_lshift_func_uint16_t_u_s)(uint16_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((65535) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static uint16_t(safe_lshift_func_uint16_t_u_u)(uint16_t left,
                                               unsigned int right) {
  return ((((unsigned int)right) >= 32) ||
          (left > ((65535) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static uint16_t(safe_rshift_func_uint16_t_u_s)(uint16_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32)) ? ((left))
                                                      : (left >> ((int)right));
}
static uint16_t(safe_rshift_func_uint16_t_u_u)(uint16_t left,
                                               unsigned int right) {
  return (((unsigned int)right) >= 32) ? ((left))
                                       : (left >> ((unsigned int)right));
}
static uint32_t(safe_unary_minus_func_uint32_t_u)(uint32_t ui) { return -ui; }
static uint32_t(safe_add_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {
  return ui1 + ui2;
}
static uint32_t(safe_sub_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {
  return ui1 - ui2;
}
static uint32_t(safe_mul_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {
  return ((unsigned int)ui1) * ((unsigned int)ui2);
}
static uint32_t(safe_mod_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 % ui2);
}
static uint32_t(safe_div_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 / ui2);
}
static uint32_t(safe_lshift_func_uint32_t_u_s)(uint32_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((4294967295U) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static uint32_t(safe_lshift_func_uint32_t_u_u)(uint32_t left,
                                               unsigned int right) {
  return ((((unsigned int)right) >= 32) ||
          (left > ((4294967295U) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static uint32_t(safe_rshift_func_uint32_t_u_s)(uint32_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32)) ? ((left))
                                                      : (left >> ((int)right));
}
static uint32_t(safe_rshift_func_uint32_t_u_u)(uint32_t left,
                                               unsigned int right) {
  return (((unsigned int)right) >= 32) ? ((left))
                                       : (left >> ((unsigned int)right));
}
static uint64_t(safe_unary_minus_func_uint64_t_u)(uint64_t ui) { return -ui; }
static uint64_t(safe_add_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {
  return ui1 + ui2;
}
static uint64_t(safe_sub_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {
  return ui1 - ui2;
}
static uint64_t(safe_mul_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {
  return ((unsigned long long)ui1) * ((unsigned long long)ui2);
}
static uint64_t(safe_mod_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 % ui2);
}
static uint64_t(safe_div_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2) {
  return (ui2 == 0) ? ((ui1)) : (ui1 / ui2);
}
static uint64_t(safe_lshift_func_uint64_t_u_s)(uint64_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32) ||
          (left > ((18446744073709551615UL) >> ((int)right))))
             ? ((left))
             : (left << ((int)right));
}
static uint64_t(safe_lshift_func_uint64_t_u_u)(uint64_t left,
                                               unsigned int right) {
  return ((((unsigned int)right) >= 32) ||
          (left > ((18446744073709551615UL) >> ((unsigned int)right))))
             ? ((left))
             : (left << ((unsigned int)right));
}
static uint64_t(safe_rshift_func_uint64_t_u_s)(uint64_t left, int right) {
  return ((((int)right) < 0) || (((int)right) >= 32)) ? ((left))
                                                      : (left >> ((int)right));
}
static uint64_t(safe_rshift_func_uint64_t_u_u)(uint64_t left,
                                               unsigned int right) {
  return (((unsigned int)right) >= 32) ? ((left))
                                       : (left >> ((unsigned int)right));
}
static int32_t(safe_convert_func_float_to_int32_t)(float sf1) {
  return ((sf1 <= (-2147483647 - 1)) || (sf1 >= (2147483647)))
             ? ((2147483647))
             : ((int32_t)(sf1));
}
static uint32_t crc32_tab[256];
static uint32_t crc32_context = 0xFFFFFFFFUL;
static void crc32_gentab(void) {
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
static void crc32_byte(uint8_t b) {
  crc32_context = ((crc32_context >> 8) & 0x00FFFFFF) ^
                  crc32_tab[(crc32_context ^ b) & 0xFF];
}
static void crc32_8bytes(uint64_t val) {
  crc32_byte((val >> 0) & 0xff);
  crc32_byte((val >> 8) & 0xff);
  crc32_byte((val >> 16) & 0xff);
  crc32_byte((val >> 24) & 0xff);
  crc32_byte((val >> 32) & 0xff);
  crc32_byte((val >> 40) & 0xff);
  crc32_byte((val >> 48) & 0xff);
  crc32_byte((val >> 56) & 0xff);
}
static void transparent_crc(uint64_t val, char *vname, int flag) {
  crc32_8bytes(val);
  if (flag) {
    printf("...checksum after hashing %s : %lX\n", vname,
           crc32_context ^ 0xFFFFFFFFUL);
  }
}
static void transparent_crc_bytes(char *ptr, int nbytes, char *vname,
                                  int flag) {
  int i;
  for (i = 0; i < nbytes; i++) {
    crc32_byte(ptr[i]);
  }
  if (flag) {
    printf("...checksum after hashing %s : %lX\n", vname,
           crc32_context ^ 0xFFFFFFFFUL);
  }
}
static long __undefined;
static volatile int32_t g_6 = 1L;
static int32_t g_7 = 1L;
static uint32_t g_20 = 0UL;
static uint32_t g_28 = 1UL;
static uint32_t g_33 = 0x0C0E0752L;
static uint8_t g_80[8] = {0xD0L, 7UL, 0xD0L, 7UL, 0xD0L, 7UL, 0xD0L, 7UL};
static uint8_t g_93 = 9UL;
static int8_t g_97 = (-1L);
static uint32_t g_98[4][6][6] = {{{0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL}},
                                 {{0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL}},
                                 {{0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL}},
                                 {{0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL},
                                  {0x893D9136L, 0xD74E5B04L, 0xD74E5B04L,
                                   0x893D9136L, 0x67DEC96EL, 4294967290UL}}};
static int8_t g_108 = 0x0AL;
static uint32_t g_119 = 4294967286UL;
static int16_t g_160[5] = {(-1L), (-1L), (-1L), (-1L), (-1L)};
static int64_t g_167 = 0x5843D7D1579E7742LL;
static int16_t g_186 = 0L;
static int32_t g_209 = 0xE9AB5F3CL;
static uint16_t g_242 = 0UL;
static int64_t g_287 = 0L;
static int16_t g_288 = 1L;
static int64_t g_289 = 0x0C50820BE9473F7FLL;
static uint32_t g_290 = 0xDFD20B68L;
static uint64_t g_522 = 0x2ABE865AEAE53234LL;
static uint16_t g_570[4][9][4] = {{{0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L}},
                                  {{0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L}},
                                  {{0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L}},
                                  {{0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L},
                                   {0x9112L, 0UL, 0xCC7AL, 0xBCD2L}}};
static int8_t g_683 = 0L;
static uint64_t g_711 = 0x9B6B5A0FAFE867B5LL;
static int16_t g_757[3] = {0xD58DL, 0xD58DL, 0xD58DL};
static int8_t g_758 = 0L;
static int8_t g_790 = (-1L);
static uint32_t g_792 = 4294967295UL;
static uint32_t g_818[8][6][2] = {{{4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL}},
                                  {{4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL}},
                                  {{4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL}},
                                  {{4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL}},
                                  {{4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL}},
                                  {{4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL}},
                                  {{4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL}},
                                  {{4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL},
                                   {4294967289UL, 4294967286UL}}};
static int32_t g_881 = 0x46FCE11CL;
static uint32_t g_904 = 0x9879C2FAL;
static int64_t g_929 = (-2L);
static uint64_t g_930 = 7UL;
static uint64_t g_1066 = 7UL;
static uint32_t g_1072 = 0UL;
static int8_t g_1100 = 0x88L;
static uint32_t g_1157 = 4294967295UL;
static int16_t g_1158 = 6L;
static uint32_t g_1257 = 5UL;
static volatile int16_t g_1348 = (-2L);
static volatile uint8_t g_1349 = 1UL;
static int8_t func_1(void);
static uint8_t func_2(uint8_t p_3, int32_t p_4, uint32_t p_5);
static int64_t func_8(int32_t p_9);
static int32_t func_11(int32_t p_12, uint32_t p_13, uint32_t p_14);
static uint32_t func_16(int8_t p_17);
static int32_t func_23(uint16_t p_24, uint64_t p_25, int64_t p_26);
static uint8_t func_43(int32_t p_44, int32_t p_45, uint8_t p_46);
static int32_t func_48(int16_t p_49, uint8_t p_50);
static int16_t func_57(int64_t p_58, uint32_t p_59, int32_t p_60, int16_t p_61);
static int64_t func_62(uint8_t p_63, int16_t p_64, uint16_t p_65, uint64_t p_66,
                       uint64_t p_67);
static int8_t func_1(void) {
  uint64_t l_10[7];
  int32_t l_1148 = 1L;
  int32_t l_1156 = 1L;
  int32_t l_1334 = 0x70E7C518L;
  uint64_t l_1341 = 18446744073709551615UL;
  int8_t l_1364 = (-1L);
  int32_t l_1367 = 0xE87CD21AL;
  int i;
  for (i = 0; i < 7; i++)
    l_10[i] = 1UL;
  l_1334 = (func_2((l_1148 = (((+(-1L)) || (g_7 ^= (g_6 | 4294967291UL))) <
                              func_8(l_10[4]))),
                   l_10[4],
                   (g_1158 = (safe_mod_func_uint64_t_u_u(
                        ((g_1157 = (safe_lshift_func_int16_t_s_u(
                              l_10[0],
                              (safe_sub_func_int64_t_s_s(
                                  ((safe_unary_minus_func_uint32_t_u((
                                       (l_1156 = (0x8DB9L <= g_818[5][5][1])) ||
                                       g_818[5][5][1]))) ^
                                   g_790),
                                  g_818[5][5][1]))))) <= l_10[3]),
                        (-10L))))) < l_10[4]);
  g_881 = (+(safe_rshift_func_uint16_t_u_s(
      ((safe_div_func_uint32_t_u_u(
           (safe_rshift_func_int16_t_s_s(
               (g_186 = (l_1341 <=
                         ((safe_div_func_int8_t_s_s(
                              g_80[0],
                              (((l_1334 &&
                                 ((((1L ==
                                     (((((g_97 = g_289) > g_80[4]) || l_1156) <
                                       (g_108 <
                                        (safe_rshift_func_int16_t_s_u(
                                            ((0xF16B74CEL != l_1156) | l_10[4]),
                                            g_522)))) <= l_10[4])) ^
                                    g_209) |
                                   g_1072) &&
                                  l_1156)) > g_522) ^
                               0x58L))) &&
                          g_167))),
               l_1156)),
           0x08DF978DL)) |
       l_1148),
      0)));
  --g_1349;
  l_1148 =
      (g_209 =
           (((safe_lshift_func_uint8_t_u_u(
                 (g_80[5] = (safe_rshift_func_int16_t_s_u(
                      (l_1367 =
                           ((((65529UL &
                               (safe_lshift_func_uint8_t_u_s(0x6FL, 2))) ^
                              (-9L)) !=
                             (g_929 ||
                              ((safe_lshift_func_int16_t_s_s(
                                   l_1334,
                                   (safe_sub_func_int8_t_s_s(
                                       (l_10[4] !=
                                        (+((0x2F37L <=
                                            (g_160[3] =
                                                 (safe_add_func_uint64_t_u_u(
                                                     (--g_930),
                                                     ((g_818[1][4][0] &
                                                       l_1367) >=
                                                      g_98[3][0][3]))))) ||
                                           g_1257))),
                                       0x6DL)))) &
                               l_1341))) <= l_10[4])),
                      l_10[2]))),
                 7)) <= g_1157) != g_33));
  return l_1156;
}
static uint8_t func_2(uint8_t p_3, int32_t p_4, uint32_t p_5) {
  uint8_t l_1165 = 1UL;
  int32_t l_1180[3];
  uint64_t l_1181 = 0x1A8AB41C7C9372D0LL;
  int32_t l_1182[6];
  int32_t l_1212 = 0L;
  int32_t l_1233 = 0x3F31A26CL;
  int32_t l_1330 = (-1L);
  int i;
  for (i = 0; i < 3; i++)
    l_1180[i] = (-1L);
  for (i = 0; i < 6; i++)
    l_1182[i] = 0xE67925ADL;
  l_1182[5] = (safe_rshift_func_int8_t_s_s(
      ((g_287 | p_3) !=
       ((7UL < ((l_1180[1] ^= (safe_rshift_func_uint16_t_u_s(
                     (safe_rshift_func_uint8_t_u_u(
                         (((l_1165 && l_1165) <=
                           (safe_add_func_uint64_t_u_u(
                               ((safe_rshift_func_int8_t_s_s(
                                    (safe_rshift_func_uint16_t_u_s(
                                        (safe_div_func_uint16_t_u_u(p_5, p_3)),
                                        ((safe_mod_func_int64_t_s_s(
                                             (safe_div_func_int8_t_s_s(
                                                 (safe_add_func_uint64_t_u_u(
                                                     1UL, (-1L))),
                                                 0x22L)),
                                             p_4)) ^
                                         4294967295UL))),
                                    5)) >= g_80[7]),
                               g_881))) > g_757[2]),
                         1)),
                     11))) ||
                l_1181)) &&
        p_3)),
      7));
  if ((safe_div_func_int16_t_s_s(
          (safe_lshift_func_int16_t_s_s(
              (l_1182[5] ^
               ((safe_div_func_int16_t_s_s(
                    0L, (safe_unary_minus_func_int8_t_s(g_242)))) >=
                ((g_160[4] &&
                  (l_1180[1] = (safe_mod_func_int32_t_s_s(
                       l_1180[1],
                       (safe_mul_func_uint8_t_u_u(
                           (9UL >= (l_1180[0] & (safe_sub_func_uint32_t_u_u(
                                                    (0xE7D33A04FEA01CF4LL & 0L),
                                                    4294967291UL)))),
                           p_4)))))) < l_1182[5]))),
              l_1181)),
          0x34D8L))) {
    return g_160[4];
  } else {
    uint64_t l_1211 = 0x6EDA6D36072CC977LL;
    int32_t l_1219 = 0x74EE19EBL;
    int8_t l_1250 = 0xBAL;
    int32_t l_1256 = 0xB3BDC0A5L;
    int32_t l_1319 = (-5L);
    uint32_t l_1331 = 8UL;
    g_7 = ((safe_unary_minus_func_int32_t_s(
               (((safe_mul_func_int16_t_s_s(
                     (safe_rshift_func_uint16_t_u_u(g_881, 3)),
                     ((p_5 ^
                       (0L >=
                        (safe_add_func_uint32_t_u_u(
                            1UL,
                            (safe_sub_func_uint16_t_u_u(
                                (safe_sub_func_uint32_t_u_u(
                                    (l_1180[1] = (safe_mod_func_uint16_t_u_u(
                                         (safe_lshift_func_uint8_t_u_u(
                                             ((l_1211 = 1L) >= l_1212), 7)),
                                         (safe_add_func_uint32_t_u_u(
                                             1UL,
                                             ((((((((~p_4) ==
                                                    ((safe_mod_func_int8_t_s_s(
                                                         (g_522 && l_1219),
                                                         l_1219)) >= g_522)) ==
                                                   g_1100) == 0x070EL) <=
                                                 0xB7A9L) < g_287) < 0UL) &
                                              l_1219)))))),
                                    l_1219)),
                                g_97)))))) >= g_28))) >= g_287) ^
                l_1219))) ^
           p_4);
    for (g_289 = 0; (g_289 < (-20)); --g_289) {
      uint16_t l_1226 = 5UL;
      uint64_t l_1248 = 0x8A76B2F269C10BCALL;
      int32_t l_1252 = 0x4D857D12L;
      int32_t l_1253 = 0x3BC1A4C4L;
      int32_t l_1254[2][9][7] = {
          {{(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L}},
          {{(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L},
           {(-1L), 2L, 0L, 4L, 0x102B6341L, 8L, 0xB2008291L}}};
      int i, j, k;
      for (g_1158 = (-30); (g_1158 == (-1));
           g_1158 = safe_add_func_int32_t_s_s(g_1158, 3)) {
        int16_t l_1249 = (-1L);
        int32_t l_1251 = 0L;
        uint16_t l_1305 = 0xA212L;
        l_1226 = ((g_1100 = (safe_sub_func_int64_t_s_s((g_929 = p_3), p_4))) &
                  (p_5 <= (p_5 || l_1211)));
        for (g_1100 = 4; (g_1100 >= 0); g_1100 -= 1) {
          int32_t l_1255 = 0x32DA7762L;
          int32_t l_1267 = 0xCA1C2244L;
          int i;
          g_881 =
              (8L <
               ((l_1249 = (safe_rshift_func_int16_t_s_s(
                     (((~(g_160[g_1100] &
                          ((safe_sub_func_int64_t_s_s(
                               (-8L),
                               (l_1226 ^
                                ((safe_div_func_uint32_t_u_u(l_1233,
                                                             0xB684D285L)) !=
                                 (safe_mod_func_uint64_t_u_u(
                                     g_93,
                                     ((safe_lshift_func_uint16_t_u_s(
                                          (safe_sub_func_int8_t_s_s(
                                              g_818[5][5][1],
                                              (safe_lshift_func_uint16_t_u_u(
                                                  (safe_add_func_int32_t_s_s(
                                                      (safe_rshift_func_int16_t_s_u(
                                                          (safe_rshift_func_int8_t_s_s(
                                                              0x07L, g_929)),
                                                          g_904)),
                                                      l_1219)),
                                                  p_4)))),
                                          l_1248)) &
                                      p_4))))))) &&
                           g_757[2]))) >= 8L) < 0x25F4L),
                     4))) == g_790));
          safe_add_func_int32_t_s_s(
              (g_93 && ((g_242 = (g_1157 = g_758)) |
                        ((g_93 = (g_80[g_93] == g_7)) < 1UL))),
              g_288);
          ++g_1257;
          l_1267 = (l_1255 ^=
                    (safe_unary_minus_func_int32_t_s((safe_add_func_int64_t_s_s(
                        (p_3 && (safe_rshift_func_int8_t_s_s(
                                    (safe_lshift_func_int8_t_s_u(
                                        (0x0B55FA67D18B5D94LL || g_209), 7)),
                                    2))),
                        p_3)))));
          return l_1255;
        }
        for (g_790 = 0; (g_790 <= 2); g_790 += 1) {
          uint64_t l_1303[5];
          int32_t l_1304[10] = {7L, 0xF784AFD7L, 7L, 0xF784AFD7L,
                                7L, 0xF784AFD7L, 7L, 0xF784AFD7L,
                                7L, 0xF784AFD7L};
          int32_t l_1306 = 0x4EC709CAL;
          int i;
          for (i = 0; i < 5; i++)
            l_1303[i] = 4UL;
   g_7
     |=
     ((g_288 = (g_160[4] &= (g_757[g_790] = (safe_rshift_func_uint8_t_u_s (g_242, (safe_mod_func_int64_t_s_s ((g_929 = (l_1180[1] = ((safe_lshift_func_uint16_t_u_s ((l_1182[5] = ((safe_lshift_func_int16_t_s_s ((safe_sub_func_uint16_t_u_u (((l_1306 = (safe_sub_func_uint16_t_u_u (((((safe_lshift_func_uint8_t_u_s (((((safe_sub_func_int64_t_s_s (p_3, (~(0x02279B2AEA80FE72LL <= (g_522 |= ((~(safe_lshift_func_uint8_t_u_u ((safe_mul_func_uint16_t_u_u ((l_1251 = ((safe_sub_func_int16_t_s_s (((p_4 || 0xF8L) ^ ((safe_rshift_func_int16_t_s_s ((safe_unary_minus_func_uint32_t_u ((l_1304[2] = (safe_sub_func_int64_t_s_s ((p_5 & (safe_div_func_uint16_t_u_u ((g_242 <= (((safe_add_func_uint16_t_u_u (((safe_add_func_uint32_t_u_u (((~g_1072) >= (~((safe_mod_func_uint16_t_u_u ((p_3 & g_20), l_1303[4])) > 4294967295UL))), p_5)) && g_1257), 1UL)) | 0xD4C4L) ^ l_1219)), g_929))), p_4))))), l_1248)) < l_1303[1])), g_28)) <= l_1305)), 0xBE4CL)), 4))) & g_290)))))) || g_97) <= g_1100) | g_757[2]), 1)) > l_1303[2]) <= l_1233) > p_4), 0x6EBDL))) ^ 9UL), l_1252)), p_5)) | 0x5CL)), 8)) && l_1305))), 18446744073709551608UL))))))) < l_1252);
   if (g_80[6])
     continue;
   (func_57((~(!(g_881 |= func_62(g_20, g_792, g_7, g_792, g_20)))), p_4, g_289,
            g_7) ||
    g_792);
        }
        g_93 = (safe_mod_func_uint8_t_u_u(
            (((g_33 || (!p_4)) > (g_209 = p_4)) | g_289),
            (g_7 &= (safe_sub_func_uint64_t_u_u(
                 (safe_sub_func_int8_t_s_s(p_4, g_290)), p_4)))));
        g_881 = (safe_lshift_func_uint16_t_u_u(
            (safe_div_func_uint8_t_u_u(
                ((((safe_mod_func_uint8_t_u_u(
                       1UL, (l_1251 = ((p_3 = 0x33L) &
                                       (0x9386BB024709BCE2LL <
                                        (safe_div_func_int32_t_s_s(
                                            l_1219, (g_119++)))))))) ||
                   p_5) ==
                  ((safe_mod_func_int64_t_s_s(
                       (l_1182[5] =
                            ((g_167 !=
                              ((+(g_1066 != p_4)) ==
                               (safe_rshift_func_int16_t_s_u(
                                   (safe_sub_func_int32_t_s_s(
                                       (l_1252 =
                                            ((l_1319 =
                                                  (((safe_add_func_uint32_t_u_u(
                                                        (!((0x6B8BL || (-5L)) <
                                                           g_160[4])),
                                                        0x76D39D0DL)) >=
                                                    l_1330) >= g_758)) != 1UL)),
                                       g_1100)),
                                   p_4)))) |
                             l_1180[1])),
                       g_683)) >= l_1250)) ||
                 0UL),
                g_930)),
            p_5));
        (safe_sub_func_uint16_t_u_u(g_881, ((+g_818[5][5][1]) ^ p_3)));
      }
      (p_4 = (safe_sub_func_uint64_t_u_u(g_881, 0xD1990C90AB741CE7LL)));
    }
    --l_1331;
    return l_1250;
  }
}
static int64_t func_8(int32_t p_9) {
  int32_t l_15[1][10][1] = {{{0xE7B79F6AL},
                             {0xE7B79F6AL},
                             {0xE7B79F6AL},
                             {0xE7B79F6AL},
                             {0xE7B79F6AL},
                             {0xE7B79F6AL},
                             {0xE7B79F6AL},
                             {0xE7B79F6AL},
                             {0xE7B79F6AL},
                             {0xE7B79F6AL}}};
  uint32_t l_1101[5][5][5] = {
      {{0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL}},
      {{0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL}},
      {{0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL}},
      {{0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL}},
      {{0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL},
       {0x9B6F5DBAL, 6UL, 0x5233ADEBL, 0UL, 18446744073709551615UL}}};
  int32_t l_1111 = 0xADCD3EA3L;
  int32_t l_1114 = 4L;
  int32_t l_1115[1];
  int32_t l_1116 = 0xB90A1467L;
  int32_t l_1117 = 1L;
  uint16_t l_1147 = 0x5F57L;
  int i, j, k;
  for (i = 0; i < 1; i++)
    l_1115[i] = 2L;
  l_1101[1][2][3] = func_11(l_15[0][1][0], p_9, func_16(p_9));
  l_1117 = (safe_mul_func_uint16_t_u_u(
      (((g_160[4] =
             (l_1116 =
                  (p_9 |
                   (l_1111 =
                        ((safe_div_func_uint64_t_u_u(
                             0UL, (safe_sub_func_int32_t_s_s(
                                      l_1101[4][3][0], (p_9 > g_1066))))) >=
                         (((safe_unary_minus_func_int8_t_s(
                               (safe_mod_func_int16_t_s_s(
                                   (l_15[0][1][0] = l_1111), (g_242--))))) &
                           (((l_1114 = p_9) |
                             (l_1115[0] = ((p_9 ^ p_9) ^ 0x9BL))) &
                            g_20)) < 8L)))))) &
        l_1101[1][2][3]) <= p_9),
      p_9));
  for (g_28 = 0; (g_28 > 43); g_28++) {
    return g_33;
  }
  g_881 = (safe_sub_func_uint8_t_u_u(
      (safe_lshift_func_int8_t_s_s(0xB4L, 4)),
      (safe_rshift_func_uint16_t_u_u(
          (safe_div_func_int8_t_s_s(
              (safe_div_func_uint8_t_u_u(
                  l_1101[1][2][3],
                  (((safe_mod_func_uint64_t_u_u(
                        g_570[0][1][3],
                        ((safe_sub_func_int16_t_s_s(
                             l_1115[0],
                             (safe_sub_func_uint16_t_u_u(
                                 l_1101[0][1][0],
                                 (safe_sub_func_int16_t_s_s(
                                     ((~((l_1147 = (safe_div_func_uint64_t_u_u(
                                              ((p_9 <
                                                (safe_unary_minus_func_uint32_t_u(
                                                    g_758))) <=
                                               (((safe_div_func_int8_t_s_s(
                                                     ((g_758 <=
                                                       (safe_mul_func_uint8_t_u_u(
                                                           (safe_sub_func_uint8_t_u_u(
                                                               253UL,
                                                               l_1115[0])),
                                                           g_757[2]))) ^
                                                      g_20),
                                                     p_9)) &&
                                                 l_1114) == g_881)),
                                              0x0B28479BE9FCD0AFLL))) ||
                                         g_93)) < g_119),
                                     l_15[0][1][0])))))) ||
                         (-6L)))) > 6L) |
                   g_522))),
              p_9)),
          g_792))));
  return l_1101[3][3][0];
}
static int32_t func_11(int32_t p_12, uint32_t p_13, uint32_t p_14) {
  int16_t l_53 = 0x6A6FL;
  int32_t l_56 = 0x262954F6L;
  int32_t l_68 = 0x6E71EBDCL;
  int32_t l_312 = 0xA6890B97L;
  for (g_33 = (-30); (g_33 < 8); g_33 = safe_add_func_int32_t_s_s(g_33, 9)) {
    uint64_t l_47 = 0x3922CBD4DAED0F12LL;
    g_1100 |=
        (func_43(
             l_47,
             func_48(
                 (p_13 ^ ((((safe_mod_func_uint16_t_u_u(p_12, l_47)) & 4UL) ^
                           (l_53 |= p_13)) &
                          ((l_56 = (!(safe_lshift_func_int16_t_s_u(l_56, 8)))) <
                           l_47))),
                 ((func_57(
                       (~(!(l_312 |= func_62(g_20, p_14, l_68, p_14, g_20)))),
                       p_12, g_289, l_68) ||
                   p_14) &
                  p_13)),
             l_47) |
         0x2BL);
  }
  return l_53;
}
static uint32_t func_16(int8_t p_17) {
  int16_t l_27 = 0L;
  int32_t l_40 = 0xAD6CAD8EL;
  l_40 = (safe_lshift_func_int16_t_s_u(
      (g_20 &
       (((safe_rshift_func_int8_t_s_s(
             (4294967295UL != func_23(l_27, g_20, p_17)), p_17)) |
         ((-10L) |
          ((+((safe_add_func_int8_t_s_s(
                  ((safe_rshift_func_uint16_t_u_s(0xCA25L, g_20)) | p_17),
                  l_27)) == 0x80366E52324067BCLL)) > l_27))) != p_17)),
      7));
  l_40 = g_20;
  return l_27;
}
static int32_t func_23(uint16_t p_24, uint64_t p_25, int64_t p_26) {
  uint64_t l_31 = 0UL;
  int32_t l_32 = (-1L);
  --g_28;
  l_31 = 0xAC895352L;
  ++g_33;
  return g_28;
}
static uint8_t func_43(int32_t p_44, int32_t p_45, uint8_t p_46) {
  int64_t l_358[8][7] = {
      {0x0A066732F6BFA9C1LL, (-1L), 0xD19DE9F1F9AA6CD7LL, 0xCCB464E269161BFELL,
       0xD663A1CFE7ECB968LL, 0xCCB464E269161BFELL, 0xD19DE9F1F9AA6CD7LL},
      {0x0A066732F6BFA9C1LL, (-1L), 0xD19DE9F1F9AA6CD7LL, 0xCCB464E269161BFELL,
       0xD663A1CFE7ECB968LL, 0xCCB464E269161BFELL, 0xD19DE9F1F9AA6CD7LL},
      {0x0A066732F6BFA9C1LL, (-1L), 0xD19DE9F1F9AA6CD7LL, 0xCCB464E269161BFELL,
       0xD663A1CFE7ECB968LL, 0xCCB464E269161BFELL, 0xD19DE9F1F9AA6CD7LL},
      {0x0A066732F6BFA9C1LL, (-1L), 0xD19DE9F1F9AA6CD7LL, 0xCCB464E269161BFELL,
       0xD663A1CFE7ECB968LL, 0xCCB464E269161BFELL, 0xD19DE9F1F9AA6CD7LL},
      {0x0A066732F6BFA9C1LL, (-1L), 0xD19DE9F1F9AA6CD7LL, 0xCCB464E269161BFELL,
       0xD663A1CFE7ECB968LL, 0xCCB464E269161BFELL, 0xD19DE9F1F9AA6CD7LL},
      {0x0A066732F6BFA9C1LL, (-1L), 0xD19DE9F1F9AA6CD7LL, 0xCCB464E269161BFELL,
       0xD663A1CFE7ECB968LL, 0xCCB464E269161BFELL, 0xD19DE9F1F9AA6CD7LL},
      {0x0A066732F6BFA9C1LL, (-1L), 0xD19DE9F1F9AA6CD7LL, 0xCCB464E269161BFELL,
       0xD663A1CFE7ECB968LL, 0xCCB464E269161BFELL, 0xD19DE9F1F9AA6CD7LL},
      {0x0A066732F6BFA9C1LL, (-1L), 0xD19DE9F1F9AA6CD7LL, 0xCCB464E269161BFELL,
       0xD663A1CFE7ECB968LL, 0xCCB464E269161BFELL, 0xD19DE9F1F9AA6CD7LL}};
  int32_t l_359 = 0xB5FC595CL;
  int32_t l_370[6] = {0x8199D4A9L, 0x8199D4A9L, 0xC15202C7L,
                      0x8199D4A9L, 0x8199D4A9L, 0xC15202C7L};
  int32_t l_391 = 0xE5FC7B0AL;
  int32_t l_392[10] = {1L, 0xBDCE6ECEL, 5L, 5L, 0xBDCE6ECEL,
                       1L, 0xBDCE6ECEL, 5L, 5L, 0xBDCE6ECEL};
  int32_t l_486 = 0xE03C6FA8L;
  int32_t l_487 = 0xFFD58227L;
  int32_t l_886 = 1L;
  uint64_t l_971 = 1UL;
  int16_t l_1050 = 0xDA8DL;
  int32_t l_1099 = 7L;
  int i, j;
  for (p_45 = 7; (p_45 >= 0); p_45 -= 1) {
    int32_t l_341 = 0xFC1A0B69L;
    uint16_t l_373 = 0x9853L;
    int32_t l_386 = 0x5ABC4564L;
    int i;
    if ((l_341 = (~g_80[p_45]))) {
      uint16_t l_342[3];
      int i;
      for (i = 0; i < 3; i++) {
        l_342[i] = 3UL;
        (safe_mul_func_int8_t_s_s(
            (safe_div_func_int16_t_s_s(
                (p_46 <= (+(safe_rshift_func_uint8_t_u_s(0x0BL, g_80[g_93])))),
                0x747CL)),
            (g_209 = ((g_209 ^= p_46) <=
                      ((safe_rshift_func_int16_t_s_s(
                           (((p_45 = (safe_sub_func_uint64_t_u_u(
                                  g_7, 0xD1990C90AB741CE7LL))) <= g_209) &&
                            0L),
                           3)) < 0UL)))));
        if (g_790)
          break;
      }
      if (l_342[0]) {
        break;
        (safe_sub_func_int8_t_s_s(
            (g_683 = 1L),
            ((((((safe_sub_func_int32_t_s_s(
                     ((g_792++) < p_44), g_98[0][4][3])) <= (p_45 | 65530UL)) ==
                ((safe_sub_func_uint32_t_u_u(
                     (safe_div_func_int32_t_s_s(
                         p_45, ((safe_rshift_func_uint8_t_u_u(p_44, 2)) |
                                (safe_mod_func_int16_t_s_s(
                                    g_80[6], (safe_sub_func_int16_t_s_s(
                                                 g_711, p_46))))))),
                     g_7)) != 0xB09A972074621008LL)) ^
               0x0216L) |
              g_287) != 0x6EE7L)));
        (safe_div_func_int32_t_s_s(
            p_45, ((safe_rshift_func_uint8_t_u_u(p_44, 2)) |
                   (safe_mod_func_int16_t_s_s(
                       g_80[6], (safe_sub_func_int16_t_s_s(g_711, p_46)))))));
      }
    } else {
      for (g_167 = (-19); (g_167 < (-13));
           g_167 = safe_add_func_uint32_t_u_u(g_167, 4)) {
        for (g_28 = 0; (g_28 >= 38);
             g_28 = safe_add_func_uint8_t_u_u(g_28, 2)) {
          int64_t l_357 = 0x8AE52A071473C660LL;
          for (g_108 = 4; (g_108 >= 0); g_108 -= 1) {
            int i;
            g_209 ^= (safe_mod_func_int16_t_s_s(
                g_80[g_108],
                (g_160[g_108] &
                 (safe_mod_func_int8_t_s_s(
                     (((safe_add_func_int16_t_s_s(
                           0L,
                           (((safe_lshift_func_int8_t_s_u(
                                 ((safe_mul_func_uint8_t_u_u(
                                      (g_160[g_108] &&
                                       (g_287 =
                                            ((l_341 = ((3UL && (g_289 >
                                                                4294967290UL)) &
                                                       (g_80[p_45] < p_46))) !=
                                             0xA3C1983CL))),
                                      l_357)) &&
                                  l_358[5][1]),
                                 g_288)) >= 0x76741604F6BAB0A8LL) > l_357))) &&
                       0xFCL) ||
                      g_242),
                     p_45)))));
            l_359 = 0xE8D5280BL;
            (((safe_rshift_func_int8_t_s_s(
                  (4294967295UL != func_23(g_288, g_20, g_1100)), g_1100)) |
              ((-10L) |
               ((+((safe_add_func_int8_t_s_s(
                       ((safe_rshift_func_uint16_t_u_s(0xCA25L, g_20)) |
                        g_1100),
                       g_288)) == 0x80366E52324067BCLL)) > g_288))) != g_1100);
          }
          ((safe_rshift_func_int8_t_s_s(
               (safe_rshift_func_uint16_t_u_s(
                   (safe_div_func_uint16_t_u_u(g_33, g_93)),
                   ((safe_mod_func_int64_t_s_s(
                        (safe_div_func_int8_t_s_s(
                            (safe_add_func_uint64_t_u_u(1UL, (-1L))), 0x22L)),
                        p_44)) ^
                    4294967295UL))),
               5)) >= g_80[7]);
        }
        safe_add_func_int32_t_s_s(g_1158, 3);
      }
      ((safe_sub_func_int32_t_s_s(
           (((safe_mod_func_int16_t_s_s(
                 ((safe_mul_func_int16_t_s_s(
                      (0UL & 4294967295UL),
                      (safe_add_func_int32_t_s_s(
                          g_683,
                          ((g_289 = (g_287 = 1L)) |
                           ((8L >=
                             (g_209 = ((safe_sub_func_uint64_t_u_u(
                                           18446744073709551614UL, g_186)) <=
                                       (safe_mul_func_uint8_t_u_u(
                                           (g_711 !=
                                            ((safe_unary_minus_func_uint16_t_u(
                                                 (+(safe_mul_func_int16_t_s_s(
                                                     (g_290 >= g_28),
                                                     g_757[2]))))) > g_108)),
                                           0x92L))))) ^
                            p_46)))))) &&
                  1UL),
                 g_290)) != p_44) |
            g_186),
           p_44)) != p_45);
      return l_358[5][1];
    }
    if ((p_44 ||
         (0xAD2BFC735E5396FELL >
          (((((p_44 && 0xE1L) <=
              (safe_mod_func_int8_t_s_s(
                  (safe_div_func_uint16_t_u_u(
                      (l_359 >= (safe_mod_func_uint64_t_u_u(
                                    1UL, (safe_mul_func_int8_t_s_s(
                                             (g_97 = l_370[0]), (~p_45)))))),
                      (safe_rshift_func_int16_t_s_s(
                          ((((((l_341 = 3UL) || 0xC9BA8D2CL) != g_287) ||
                             l_358[5][1]) >= l_358[5][1]) |
                           0x1DF6L),
                          1)))),
                  g_93))) ^
             l_373) &
            0L) ^
           0xBBL)))) {
      uint8_t l_382 = 1UL;
      int32_t l_385 = 0x090D0453L;
      int32_t l_494 = 0x9F0504AAL;
      int16_t l_513 = (-1L);
      l_386 =
          (l_359 =
               ((l_382 = (safe_mod_func_uint8_t_u_u(
                     (((g_33 || (!p_45)) > (g_209 = p_44)) | g_289),
                     (l_341 &= (safe_sub_func_uint64_t_u_u(
                          (safe_sub_func_int8_t_s_s(p_45, g_290)), p_45)))))) <=
                (((safe_sub_func_int64_t_s_s(
                      g_160[3],
                      (((g_20 |= (g_119 = ((0x6EA25E125C940483LL && l_385) &&
                                           g_98[3][3][5]))) ^
                        g_28) >= 0xCCD0EB458E618EA5LL))) != l_385) &&
                 g_28)));
      (safe_mul_func_int8_t_s_s(
          (safe_sub_func_uint64_t_u_u(
              ((safe_mul_func_uint16_t_u_u(
                   g_881,
                   (g_881 !=
                    (safe_mod_func_int8_t_s_s(
                        (((safe_div_func_uint8_t_u_u(
                              (safe_lshift_func_uint8_t_u_u(
                                  (p_44 = (safe_sub_func_int16_t_s_s(
                                       g_97,
                                       (255UL < (g_209 = (g_881 = g_93)))))),
                                  g_287)),
                              g_20)) < g_929) < g_929),
                        g_881))))) <= g_98[2][2][0]),
              7L)),
          (-4L))) <= 6UL;
      for (g_167 = 14; (g_167 > 21); g_167++) {
        uint32_t l_417 = 2UL;
        uint64_t l_478 = 0xE74D695708A3DC93LL;
        if ((0x06L > (++g_93))) {
          uint16_t l_393 = 0xB5D0L;
          int32_t l_400 = 0x5FCA8164L;
          int32_t l_436 = 0L;
          --l_393;
          for (g_242 = 0; (g_242 <= 6); g_242 += 1) {
            int32_t l_401 = 1L;
            int i, j;
            l_401 = (l_358[p_45][g_242] ||
                     ((safe_div_func_uint64_t_u_u(p_46, l_341)) |
                      (safe_rshift_func_int8_t_s_u(g_289, (l_400 |= l_373)))));
            g_209 =
                ((safe_mul_func_int16_t_s_s(
                     l_358[p_45][g_242],
                     (safe_unary_minus_func_int64_t_s(
                         (g_289 |=
                          ((((safe_mod_func_int8_t_s_s(
                                 (g_209 &&
                                  (safe_sub_func_int32_t_s_s(
                                      (((safe_lshift_func_int16_t_s_s(p_45,
                                                                      14)) <
                                        (safe_lshift_func_int8_t_s_s(g_80[1],
                                                                     3))) ||
                                       p_46),
                                      ((-9L) <=
                                       (safe_add_func_uint16_t_u_u(
                                           g_80[6], (safe_add_func_uint16_t_u_u(
                                                        (~0x9067L),
                                                        (l_400 ^ p_46))))))))),
                                 0x9AL)) >= l_417) |
                            p_46) &
                           g_98[1][4][3])))))) > g_80[0]);
            l_385 = g_289;
            if (p_46) {
              continue;
              safe_div_func_int64_t_s_s(
                  ((safe_div_func_int16_t_s_s(
                       (g_186 =
                            ((safe_mod_func_int32_t_s_s(
                                 (((((safe_lshift_func_uint8_t_u_u(
                                         p_44, ((p_44 > 0x13F8DDA601CE15D2LL) >=
                                                65531UL))) &&
                                     g_80[1]) &&
                                    g_7) != p_46) |
                                  g_119),
                                 5UL)) != g_80[6])),
                       g_160[4])) &&
                   1UL),
                  18446744073709551607UL);
            }
          }
          (safe_mod_func_int8_t_s_s(
              (g_881 =
                   ((safe_mul_func_int8_t_s_s(
                        (safe_sub_func_uint64_t_u_u(
                            ((safe_mul_func_uint16_t_u_u(
                                 p_44,
                                 (p_44 !=
                                  (safe_mod_func_int8_t_s_s(
                                      (((safe_div_func_uint8_t_u_u(
                                            (safe_lshift_func_uint8_t_u_u(
                                                (p_44 =
                                                     (safe_sub_func_int16_t_s_s(
                                                         g_97,
                                                         (255UL <
                                                          (g_7 =
                                                               (g_209 =
                                                                    g_93)))))),
                                                g_287)),
                                            g_119)) < g_289) < g_289),
                                      p_44))))) <= g_98[2][2][0]),
                            7L)),
                        (-4L))) <= 6UL)),
              g_209));
          for (l_382 = (-3); (l_382 <= 4);
               l_382 = safe_add_func_uint8_t_u_u(l_382, 9)) {
            return g_20;
          }
          g_167 !=
              ((+(g_1066 != g_209)) ==
               (safe_rshift_func_int16_t_s_u(
                   (safe_sub_func_int32_t_s_s(
                       (g_881 =
                            ((g_881 = (((safe_add_func_uint32_t_u_u(
                                            (!((0x6B8BL || (-5L)) < g_160[4])),
                                            0x76D39D0DL)) >= p_45) >= g_758)) !=
                             1UL)),
                       g_1100)),
                   g_209)));
          g_209 = (safe_sub_func_uint32_t_u_u(
              ((p_45 >
                ((((safe_mod_func_uint8_t_u_u(
                       ((safe_lshift_func_uint8_t_u_u(
                            (safe_sub_func_uint8_t_u_u(
                                0x47L,
                                (safe_mod_func_int8_t_s_s(
                                    l_400, ((safe_div_func_int32_t_s_s(
                                                (safe_add_func_int32_t_s_s(
                                                    p_44, 0x94EE3061L)),
                                                l_358[6][0])) &&
                                            ((safe_mul_func_uint8_t_u_u(
                                                 (l_436 = ((p_44 ^ l_370[0]) <
                                                           (p_44 <= p_46))),
                                                 g_28)) < l_417)))))),
                            2)) ^
                        0x93E3L),
                       g_160[1])) ||
                   l_370[4]) &&
                  250UL) >= g_108)) ||
               l_382),
              l_385));
        } else {
          int64_t l_479[9] = {
              0x5FED9247DC389D37LL, 0x5FED9247DC389D37LL, 0x4F24E26514CB11C3LL,
              0x5FED9247DC389D37LL, 0x5FED9247DC389D37LL, 0x4F24E26514CB11C3LL,
              0x5FED9247DC389D37LL, 0x5FED9247DC389D37LL, 0x4F24E26514CB11C3LL};
          int i;
          for (l_359 = (-2); (l_359 <= 5); ++l_359) {
            int32_t l_457 = 0L;
            g_209 =
                ((safe_lshift_func_uint8_t_u_s(
                     (((safe_sub_func_uint16_t_u_u(
                           p_44, (safe_rshift_func_int16_t_s_s(g_33, g_20)))) >=
                       (g_290 &&
                        (((((+(safe_mod_func_uint32_t_u_u(
                                (safe_lshift_func_uint8_t_u_u(0xA3L, 1)),
                                ((g_287 !=
                                  (((safe_lshift_func_uint8_t_u_s(
                                        (g_80[6] =
                                             (g_93 ^=
                                              (safe_div_func_int32_t_s_s(
                                                  0x5255962FL, 0x238FD6C5L)))),
                                        1)) <
                                    ((safe_mod_func_uint8_t_u_u(
                                         (safe_sub_func_uint32_t_u_u(
                                             (0x9B101B88L ^ l_341), g_242)),
                                         g_33)) ||
                                     g_290)) > g_98[3][1][2])) &
                                 0xDCAF8491147520D1LL)))) != l_457) >= l_382) ^
                          0UL) |
                         0x171CL))) &
                      g_290),
                     3)) <= p_45);
            g_209 = (safe_add_func_uint8_t_u_u(
                (p_44 >=
                 (0x13CFED869FF80C6CLL <
                  (0x922DL ==
                   (safe_rshift_func_uint8_t_u_s(
                       ((safe_rshift_func_uint16_t_u_s(
                            (g_242 =
                                 ((g_160[2] <=
                                   ((safe_add_func_int64_t_s_s(
                                        (((safe_lshift_func_int16_t_s_u(
                                              ((safe_add_func_int8_t_s_s(
                                                   ((safe_lshift_func_int8_t_s_u(
                                                        l_386, 0)) ^
                                                    ((((safe_div_func_int64_t_s_s(
                                                           (safe_rshift_func_int8_t_s_u(
                                                               (((l_385 = (safe_div_func_int8_t_s_s(
                                                                      ((g_290 ||
                                                                        l_457) &&
                                                                       l_457),
                                                                      ((g_119 ^=
                                                                        (g_80[5] ^
                                                                         6L)) ^
                                                                       g_80[1])))) &
                                                                 (-1L)) |
                                                                65535UL),
                                                               l_370[0])),
                                                           p_44)) ||
                                                       7UL) == p_46) == l_382)),
                                                   l_382)) &&
                                               (-7L)),
                                              0)) &
                                          l_478) >= g_93),
                                        p_45)) >= (-3L))) &
                                  l_479[6])),
                            g_97)) |
                        l_370[0]),
                       p_46))))),
                p_45));
            safe_sub_func_uint16_t_u_u(
                p_44, (safe_rshift_func_int16_t_s_s(g_33, g_20)));
            return g_97;
          }
          for (g_108 = 16; (g_108 >= (-27)); --g_108) {
            return g_209;
          }
          (((((safe_lshift_func_uint8_t_u_u(
                  g_209, ((p_44 > 0x13F8DDA601CE15D2LL) >= 65531UL))) &&
              g_80[1]) &&
             g_881) != p_46) |
           g_119);
        }
        ((p_46 = (g_80[g_93] == p_44)) < 1UL);
      }
      ((((((safe_div_func_int8_t_s_s(g_287, g_28)) |
           (((safe_mul_func_int8_t_s_s(
                 (safe_div_func_int16_t_s_s(
                     (p_46 <=
                      (+(safe_rshift_func_uint8_t_u_s(0x0BL, g_80[g_93])))),
                     0x747CL)),
                 (g_7 = ((g_209 ^= p_46) <=
                         ((safe_rshift_func_int16_t_s_s(
                              (((g_209 = (safe_sub_func_uint64_t_u_u(
                                     g_881, 0xD1990C90AB741CE7LL))) <= p_44) &&
                               0L),
                              3)) < 0UL))))) ||
             0xD700L) < p_45)) > p_44) &&
         g_186) > g_119) &&
       g_289);
      l_494 &=
          ((((!((safe_mod_func_uint64_t_u_u(
                    (safe_mul_func_int8_t_s_s(
                        ((p_46 != (l_487 |= l_486)) == p_46), g_160[2])),
                    (l_385 &= l_382))) ^
                (safe_rshift_func_int8_t_s_s(
                    (g_108 ^= p_46),
                    ((((p_46 > (+(g_209 = (safe_div_func_uint16_t_u_u(
                                      g_288, (safe_rshift_func_int16_t_s_u(
                                                 0x8DE6L, 8))))))) <=
                       0xC13CL) <= 0x8BL) > l_386))))) >= (-1L)) != g_20) ||
           0xE9L);
      ((((safe_sub_func_int32_t_s_s(
             (((safe_mod_func_int16_t_s_s(
                   ((safe_mul_func_int16_t_s_s(
                        (0UL & 4294967295UL),
                        (safe_add_func_int32_t_s_s(
                            g_790,
                            ((g_289 = (g_287 = 1L)) |
                             ((8L >=
                               (g_209 =
                                    ((safe_sub_func_uint64_t_u_u(
                                         18446744073709551614UL, g_186)) <=
                                     (safe_mul_func_uint8_t_u_u(
                                         (g_711 !=
                                          ((safe_unary_minus_func_uint16_t_u(
                                               (+(safe_mul_func_int16_t_s_s(
                                                   (g_33 >= g_28),
                                                   g_757[2]))))) > g_108)),
                                         0x92L))))) ^
                              p_46)))))) &&
                    1UL),
                   g_33)) != p_44) |
              g_186),
             p_44)) != p_45) ||
        g_287) ^
       g_33);
      g_209 =
          ((l_487 | (safe_lshift_func_int8_t_s_s(p_44, l_487))) !=
           ((safe_rshift_func_int8_t_s_s(
                (((((l_385 =
                         (l_386 = (safe_lshift_func_uint16_t_u_u(g_289, 2)))) &&
                    (0x8E89L ^
                     (g_288 &= (safe_mod_func_int8_t_s_s(
                          (safe_mod_func_uint32_t_u_u(
                              (safe_mul_func_int16_t_s_s(
                                  ((safe_mod_func_uint8_t_u_u(
                                       (safe_sub_func_uint32_t_u_u(
                                           g_242,
                                           (safe_rshift_func_int16_t_s_s(
                                               (l_513 ^= (-1L)),
                                               ((safe_div_func_int64_t_s_s(
                                                    ((safe_div_func_int16_t_s_s(
                                                         (g_186 =
                                                              ((safe_mod_func_int32_t_s_s(
                                                                   (((((safe_lshift_func_uint8_t_u_u(
                                                                           l_385,
                                                                           ((p_44 >
                                                                             0x13F8DDA601CE15D2LL) >=
                                                                            65531UL))) &&
                                                                       g_80[1]) &&
                                                                      l_487) !=
                                                                     p_46) |
                                                                    g_119),
                                                                   5UL)) !=
                                                               g_80[6])),
                                                         g_160[4])) &&
                                                     1UL),
                                                    18446744073709551607UL)) &
                                                p_44))))),
                                       p_45)) &&
                                   p_46),
                                  p_46)),
                              0xD55B61E1L)),
                          0x5DL))))) |
                   0x6BL) > g_33) &&
                 l_341),
                l_373)) |
            l_494));
      p_45 &((safe_sub_func_uint16_t_u_u(p_45, ((+g_818[5][5][1]) ^ p_46))) >=
             1UL);
    } else {
      l_391 = 0xB0793940L;
      (safe_rshift_func_int16_t_s_s(0x746BL, 2));
      ++g_522;
      ((((((safe_sub_func_int32_t_s_s(
               (((safe_mod_func_int16_t_s_s(
                     ((safe_mul_func_int16_t_s_s(
                          (0UL & 4294967295UL),
                          (safe_add_func_int32_t_s_s(
                              g_790,
                              ((g_289 = (g_287 = 1L)) |
                               ((8L >=
                                 (p_44 =
                                      ((safe_sub_func_uint64_t_u_u(
                                           18446744073709551614UL, g_186)) <=
                                       (safe_mul_func_uint8_t_u_u(
                                           (g_711 !=
                                            ((safe_unary_minus_func_uint16_t_u(
                                                 (+(safe_mul_func_int16_t_s_s(
                                                     (g_119 >= g_28),
                                                     g_757[2]))))) > g_108)),
                                           0x92L))))) ^
                                p_46)))))) &&
                      1UL),
                     g_119)) != p_44) |
                g_186),
               p_44)) != p_45) ||
          g_287) ^
         g_119) <= 1L) &&
       g_711) ^
          g_522;
    }
    (safe_rshift_func_int16_t_s_s(
        (((p_45 = (safe_sub_func_uint64_t_u_u(g_209, 0xD1990C90AB741CE7LL))) <=
          p_45) &&
         0L),
        3)) < 0UL;
    l_386 = (safe_div_func_int8_t_s_s(0x3FL, 1L));
    g_7 |= (safe_rshift_func_int8_t_s_s(g_209, 3));
  }
  if ((l_392[3] = (p_45 == ((((safe_mod_func_uint64_t_u_u ((safe_div_func_int16_t_s_s ((safe_add_func_uint64_t_u_u (((((safe_add_func_int64_t_s_s (((1L && ((safe_rshift_func_uint8_t_u_s (((safe_sub_func_uint8_t_u_u (((safe_rshift_func_int8_t_s_s ((safe_sub_func_uint8_t_u_u ((g_20 != ((safe_div_func_int16_t_s_s (p_45, (safe_lshift_func_uint8_t_u_s ((~(((safe_mod_func_uint64_t_u_u ((safe_lshift_func_uint8_t_u_u ((safe_add_func_int8_t_s_s ((p_44 > (safe_mul_func_uint8_t_u_u (3UL, (safe_div_func_uint16_t_u_u ((safe_mod_func_uint32_t_u_u (((safe_mod_func_int16_t_s_s (l_358[0][1], (safe_unary_minus_func_int32_t_s ((safe_sub_func_int32_t_s_s (((l_487 = 0x94F52823067E3487LL) <= ((safe_mod_func_int16_t_s_s (1L, l_392[3])) == 0x5583L)), l_486)))))) == 0xC1L), (-1L))), g_80[6]))))), p_44)), l_359)), (-5L))) ^ g_209) >= g_167)), 6)))) < g_570[0][1][3])), g_97)), 7)) <= p_46), 252UL)) >= 0xB6L), g_119)) <= 0xD7A0L)) >= g_80[6]), p_45)) > 18446744073709551608UL) < 0x0D03L) == p_46), g_570[3][7][2])), 0x49A8L)), 0x74CF1EF87AD28326LL)) == l_392[3]) <= 0xCEL) != l_358[5][1]))))
  {
    int8_t l_575 = 0xC5L;
    int32_t l_584 = 1L;
    int8_t l_676 = 0x22L;
    int8_t l_705 = (-1L);
    uint64_t l_728 = 0xB4B3AD32F2DA4138LL;
    int32_t l_733 = 0xB5357481L;
    int32_t l_734 = 0xC3D19C16L;
    if ((p_45 &&
         (((safe_lshift_func_int8_t_s_u(p_45, 1)) ==
           (g_522 = (safe_sub_func_int32_t_s_s(l_575, (~(0x1262L == 9UL)))))) <
          (safe_div_func_int64_t_s_s(
              ((safe_sub_func_int8_t_s_s(
                   0xC0L,
                   ((((safe_mul_func_int8_t_s_s(
                          g_186, ((((safe_sub_func_int64_t_s_s(
                                        (l_392[2] = (l_584 ^= g_93)),
                                        (safe_mod_func_uint64_t_u_u(
                                            (+(safe_lshift_func_uint16_t_u_s(
                                                (safe_sub_func_int32_t_s_s(
                                                    g_108, p_45)),
                                                13))),
                                            (-1L))))) |
                                    l_575) &
                                   g_290) |
                                  0L))) ^
                      g_289) <= p_44) &
                    l_391))) >= l_391),
              g_570[0][1][3]))))) {
      int8_t l_591 = 0L;
      uint64_t l_609[9][9] = {
          {18446744073709551615UL, 18446744073709551610UL, 1UL,
           18446744073709551610UL, 18446744073709551615UL, 0xB933ADC69FB1676ALL,
           1UL, 18446744073709551610UL, 18446744073709551609UL},
          {18446744073709551615UL, 18446744073709551610UL, 1UL,
           18446744073709551610UL, 18446744073709551615UL, 0xB933ADC69FB1676ALL,
           1UL, 18446744073709551610UL, 18446744073709551609UL},
          {18446744073709551615UL, 18446744073709551610UL, 1UL,
           18446744073709551610UL, 18446744073709551615UL, 0xB933ADC69FB1676ALL,
           1UL, 18446744073709551610UL, 18446744073709551609UL},
          {18446744073709551615UL, 18446744073709551610UL, 1UL,
           18446744073709551610UL, 18446744073709551615UL, 0xB933ADC69FB1676ALL,
           1UL, 18446744073709551610UL, 18446744073709551609UL},
          {18446744073709551615UL, 18446744073709551610UL, 1UL,
           18446744073709551610UL, 18446744073709551615UL, 0xB933ADC69FB1676ALL,
           1UL, 18446744073709551610UL, 18446744073709551609UL},
          {18446744073709551615UL, 18446744073709551610UL, 1UL,
           18446744073709551610UL, 18446744073709551615UL, 0xB933ADC69FB1676ALL,
           1UL, 18446744073709551610UL, 18446744073709551609UL},
          {18446744073709551615UL, 18446744073709551610UL, 1UL,
           18446744073709551610UL, 18446744073709551615UL, 0xB933ADC69FB1676ALL,
           1UL, 18446744073709551610UL, 18446744073709551609UL},
          {18446744073709551615UL, 18446744073709551610UL, 1UL,
           18446744073709551610UL, 18446744073709551615UL, 0xB933ADC69FB1676ALL,
           1UL, 18446744073709551610UL, 18446744073709551609UL},
          {18446744073709551615UL, 18446744073709551610UL, 1UL,
           18446744073709551610UL, 18446744073709551615UL, 0xB933ADC69FB1676ALL,
           1UL, 18446744073709551610UL, 18446744073709551609UL}};
      int32_t l_610 = 9L;
      int16_t l_640 = 0xCE6AL;
      int32_t l_678 = 0xBA44F3FBL;
      int8_t l_755[5];
      int i, j;
      for (i = 0; i < 5; i++) {
        l_755[i] = 0x51L;
        (safe_sub_func_uint32_t_u_u(
            (safe_div_func_int32_t_s_s(
                p_45,
                ((safe_rshift_func_uint8_t_u_u(p_44, 2)) |
                 (safe_mod_func_int16_t_s_s(
                     g_80[6], (safe_sub_func_int16_t_s_s(g_711, p_46))))))),
            g_881));
      }
      if ((l_591 >
           (safe_mod_func_uint32_t_u_u(
               (l_610 =
                    ((g_209 = (safe_mod_func_int64_t_s_s(
                          ((g_33 ||
                            (((g_242++) <= 0x1EACL) ^
                             ((g_93 &=
                               (((safe_unary_minus_func_int16_t_s(2L)) >
                                 p_46) >=
                                (safe_add_func_int16_t_s_s(
                                    ((1L || l_591) |
                                     ((((safe_sub_func_int8_t_s_s(
                                            ((((0x4DA77586BB253348LL !=
                                                (safe_rshift_func_uint16_t_u_u(
                                                    (safe_lshift_func_int16_t_s_s(
                                                        ((l_591 != l_591) >=
                                                         p_46),
                                                        4)),
                                                    p_45))) ||
                                               (-1L)) &&
                                              g_160[4]) &&
                                             p_46),
                                            (-9L))) <= g_289) &
                                       l_591) <= g_209)),
                                    l_609[1][7])))) ^
                              l_609[1][7]))) |
                           g_570[0][1][3]),
                          0x85072803D8013A0ELL))) &
                     l_609[1][7])),
               1UL)))) {
        int16_t l_626 = 0xE00EL;
        int32_t l_627 = 6L;
        if (g_33) {
          int8_t l_613[7] = {0xE5L, 0x09L, 0xE5L, 0x09L, 0xE5L, 0x09L, 0xE5L};
          int32_t l_648 = 0L;
          int32_t l_658 = 0x1A6A6168L;
          int i;
          for (g_289 = 0; (g_289 != 7);
               g_289 = safe_add_func_uint32_t_u_u(g_289, 6)) {
            l_613[3] = l_575;
          }
          g_167 &= g_160[2];
          l_610 &=
              (g_97 ^
               (safe_mul_func_uint8_t_u_u(
                   g_287,
                   (safe_mod_func_uint16_t_u_u(
                       (safe_mul_func_int16_t_s_s(
                           (((0x0D05L !=
                              (((l_392[3] = (safe_div_func_int64_t_s_s(
                                     (safe_div_func_int32_t_s_s(
                                         (safe_div_func_uint8_t_u_u(
                                             (0x39L >=
                                              (l_584 >=
                                               (l_627 ^= (l_626 && 255UL)))),
                                             (l_391 &=
                                              (0xC0B6L <
                                               ((((g_522 != 0UL) >= g_289) ==
                                                 18446744073709551607UL) &
                                                g_98[1][0][4]))))),
                                         p_44)),
                                     g_80[1]))) < l_626) <= (-1L))) > g_209) &
                            0x67L),
                           1L)),
                       p_45)))));
          g_209 = (safe_div_func_uint8_t_u_u(
              l_575,
              (safe_mod_func_int64_t_s_s(
                  (g_287 = (((p_45 ^ (safe_add_func_uint32_t_u_u(l_575, 0L))) &&
                             (safe_lshift_func_int8_t_s_u(
                                 (safe_lshift_func_int8_t_s_s(l_584, g_160[4])),
                                 3))) &
                            (p_45 ||
                             (g_80[6] = (l_626 >= (safe_add_func_uint16_t_u_u(
                                                      g_522, 0x196CL))))))),
                  l_640))));
          for (l_391 = 0; (l_391 < 10); ++l_391) {
            int32_t l_647 = 1L;
            l_359 =
                (g_209 =
                     ((safe_add_func_int16_t_s_s(
                          (safe_mod_func_int64_t_s_s(
                              (((g_98[3][3][5]++) & g_522) >=
                               (safe_mul_func_int8_t_s_s(
                                   (((safe_unary_minus_func_int16_t_s(
                                         (g_288 = 0xD04DL))) >
                                     (g_160[4] = (safe_div_func_int64_t_s_s(
                                          p_44, (safe_lshift_func_uint8_t_u_u(
                                                    l_658, 1)))))) &
                                    (l_647 && (p_46 = g_570[0][1][3]))),
                                   (((safe_mul_func_uint16_t_u_u(
                                         (safe_add_func_uint16_t_u_u(p_44,
                                                                     l_584)),
                                         l_647)) <= p_44) < 0x35471BC2L)))),
                              g_242)),
                          (-6L))) < p_45));
            safe_add_func_uint32_t_u_u(
                g_119,
                (safe_rshift_func_uint16_t_u_u(
                    (safe_mul_func_uint16_t_u_u(g_242, (g_97 == g_288))), 1)));
            return l_575;
          }
        } else {
          l_584 = l_591;
          (safe_mod_func_int32_t_s_s(
              (safe_mul_func_uint16_t_u_u(
                  g_186,
                  (g_20 |
                   ((g_522 |= (safe_add_func_int16_t_s_s(
                         (-9L),
                         (safe_mod_func_uint32_t_u_u(
                             g_186, (safe_add_func_uint32_t_u_u(
                                        g_119, (safe_rshift_func_uint16_t_u_u(
                                                   (safe_mul_func_uint16_t_u_u(
                                                       g_242, (g_97 == g_186))),
                                                   1))))))))) < g_209)))),
              3L));
        }
      } else {
        uint16_t l_679 = 0x4F4FL;
        int32_t l_687 = 0x46B8FEBAL;
        int32_t l_690[7][8];
        int i, j;
        for (i = 0; i < 7; i++) {
          for (j = 0; j < 8; j++)
            l_690[i][j] = 0L;
          safe_add_func_int32_t_s_s(g_33, 9);
        }
        (safe_sub_func_uint64_t_u_u(
            18446744073709551606UL,
            (safe_lshift_func_uint16_t_u_u(
                p_46, (safe_unary_minus_func_uint32_t_u(0x7B47903EL))))));
        for (l_575 = 6; (l_575 >= 2); l_575 -= 1) {
          uint64_t l_673[1];
          int32_t l_677 = 3L;
          uint64_t l_684 = 18446744073709551615UL;
          int i;
          for (i = 0; i < 1; i++)
            l_673[i] = 18446744073709551615UL;
          for (l_487 = 0; (l_487 <= 3); l_487 += 1) {
            int32_t l_682 = 3L;
            int i, j;
            l_584 |=
                ((+((safe_mod_func_uint16_t_u_u(
                        (safe_mod_func_uint32_t_u_u(
                            ((safe_rshift_func_int8_t_s_s(
                                 ((safe_div_func_int16_t_s_s(
                                      ((l_609[l_487][(l_575 + 1)] &&
                                        ((safe_mod_func_uint32_t_u_u(
                                             0x56B15810L, 0x70F5A9ADL)) <
                                         0x3C8CL)) &&
                                       g_160[4]),
                                      l_575)) >
                                  (l_673[0] == (safe_add_func_int64_t_s_s(
                                                   g_288, ((-3L) > l_676))))),
                                 p_44)) >= l_673[0]),
                            9UL)),
                        p_44)) ||
                    l_591)) <= 0x53A27A56877D466FLL);
            (g_570[0][6][3] = g_930);
            ++l_679;
            if (g_33)
              break;
            ++l_684;
          }
          if (l_591) {
            break;
            g_209 = ((p_45 &= (g_881 = (-8L))) &
                     (safe_add_func_int32_t_s_s(
                         (p_46 && ((g_242 = (g_1257 = g_758)) |
                                   ((p_46 = (g_80[g_93] == p_44)) < 1UL))),
                         g_288)));
          }
          if (l_609[3][5]) {
            l_584 = l_679;
            safe_mod_func_int8_t_s_s(
                (safe_mod_func_uint32_t_u_u(
                    (safe_mul_func_int16_t_s_s(
                        ((safe_mod_func_uint8_t_u_u(
                             (safe_sub_func_uint32_t_u_u(
                                 g_242,
                                 (safe_rshift_func_int16_t_s_s(
                                     (g_288 ^= (-1L)),
                                     ((safe_div_func_int64_t_s_s(
                                          ((safe_div_func_int16_t_s_s(
                                               (g_186 =
                                                    ((safe_mod_func_int32_t_s_s(
                                                         (((((safe_lshift_func_uint8_t_u_u(
                                                                 g_209,
                                                                 ((p_44 >
                                                                   0x13F8DDA601CE15D2LL) >=
                                                                  65531UL))) &&
                                                             g_80[1]) &&
                                                            g_7) != p_46) |
                                                          g_119),
                                                         5UL)) != g_80[6])),
                                               g_160[4])) &&
                                           1UL),
                                          18446744073709551607UL)) &
                                      p_44))))),
                             p_45)) &&
                         p_46),
                        p_46)),
                    0xD55B61E1L)),
                0x5DL);
          } else {
            uint64_t l_691[9][7][3] = {
                {{18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL}},
                {{18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL}},
                {{18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL}},
                {{18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL}},
                {{18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL}},
                {{18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL}},
                {{18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL}},
                {{18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL}},
                {{18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL},
                 {18446744073709551611UL, 0x6791CC625B7BF462LL,
                  18446744073709551613UL}}};
            int32_t l_702 = 1L;
            int64_t l_706 = 0xFB23636DAB609B79LL;
            int i, j, k;
            l_706 =
                ((((p_46 && (l_687 = (g_97 = (~p_46)))) <
                   (((safe_div_func_uint64_t_u_u(
                         (l_691[2][2][0]--),
                         (safe_mul_func_int16_t_s_s(
                             (g_186 &=
                              (((p_44 ==
                                 ((g_108 &=
                                   ((l_609[1][7] &&
                                     ((g_522 = (!(
                                           (p_44 ^
                                            (((((safe_sub_func_uint16_t_u_u(
                                                    (p_45 !=
                                                     (safe_add_func_int32_t_s_s(
                                                         (safe_add_func_int64_t_s_s(
                                                             l_702,
                                                             (safe_lshift_func_uint16_t_u_u(
                                                                 ((((1UL <=
                                                                     ((+((((l_370
                                                                                [0] <=
                                                                            l_575) >=
                                                                           g_80[4]) &&
                                                                          g_160
                                                                              [4]) |
                                                                         0L)) >=
                                                                      p_45)) <
                                                                    g_98[1][5]
                                                                        [2]) ^
                                                                   g_522) ==
                                                                  l_610),
                                                                 11)))),
                                                         g_290))),
                                                    p_44)) ||
                                                g_80[6]) == l_591) <= g_288) ==
                                             l_705)) |
                                           p_45))) ^
                                      g_570[0][1][3])) >= l_673[0])) <
                                  l_702)) != p_44) |
                               l_370[0])),
                             l_702)))) < p_46) != (-10L))) < p_46) >= l_487);
            p_45 &((safe_sub_func_uint16_t_u_u(
                       p_45, ((+g_818[5][5][1]) ^ p_46))) >= 1UL);
            g_209 = ((safe_lshift_func_int16_t_s_s(
                         (safe_mul_func_int8_t_s_s(l_677, g_242)), 10)) |
                     4UL);
            g_7 = 3UL;
            if (p_46) {
              continue;
              (safe_mod_func_int8_t_s_s(
                  (g_209 &&
                   (safe_sub_func_int32_t_s_s(
                       (((safe_lshift_func_int16_t_s_s(p_45, 14)) <
                         (safe_lshift_func_int8_t_s_s(g_80[1], 3))) ||
                        p_46),
                       ((-9L) <=
                        (safe_add_func_uint16_t_u_u(
                            g_80[6], (safe_add_func_uint16_t_u_u(
                                         (~0x9067L), (g_209 ^ p_46))))))))),
                  0x9AL));
            }
          }
          for (g_209 = 0; (g_209 <= 8); g_209 += 1) {
            g_711++;
            (safe_lshift_func_int8_t_s_u(
                (safe_lshift_func_int8_t_s_s(g_881, g_160[4])), 3));
          }
          (+(safe_rshift_func_uint8_t_u_s(0x0BL, g_80[g_93])));
          for (g_289 = 8; (g_289 >= 2); g_289 -= 1) {
            l_610 ^= (-1L);
            (safe_div_func_int64_t_s_s(
                (safe_div_func_int32_t_s_s(
                    (safe_div_func_uint8_t_u_u(
                        (0x39L >= (g_881 >= (p_45 ^= (g_186 && 255UL)))),
                        (p_45 &= (0xC0B6L < ((((g_522 != 0UL) >= g_289) ==
                                              18446744073709551607UL) &
                                             g_98[1][0][4]))))),
                    p_44)),
                g_80[1]));
            g_209 = p_46;
          }
        }
        p_45 = (g_881 = ((p_45 &= (g_881 = (-8L))) &
                         (safe_add_func_int32_t_s_s(
                             (p_46 && ((g_242 = (g_28 = g_758)) |
                                       ((p_46 = (g_80[g_93] == p_44)) < 1UL))),
                             g_288))));
        for (l_584 = 0; l_584 < 9; l_584 += 1) {
          for (g_242 = 0; g_242 < 9; g_242 += 1) {
            l_609[l_584][g_242] = 2UL;
            safe_sub_func_int32_t_s_s(
                (g_209 =
                     ((p_44 = (((safe_add_func_uint32_t_u_u(
                                    (!((0x6B8BL || (-5L)) < g_160[4])),
                                    0x76D39D0DL)) >= p_45) >= g_758)) != 1UL)),
                g_1100);
          }
        }
        (safe_lshift_func_uint8_t_u_s(
            (g_80[6] = (g_93 ^=
                        (safe_div_func_int32_t_s_s(0x5255962FL, 0x238FD6C5L)))),
            1));
      }
      if (((safe_div_func_int8_t_s_s(
               (((safe_div_func_int64_t_s_s(
                     (safe_sub_func_uint32_t_u_u(
                         ((g_570[0][1][3] ||
                           (safe_div_func_uint8_t_u_u(
                               (safe_mod_func_uint8_t_u_u(
                                   p_45,
                                   (safe_lshift_func_uint8_t_u_s(
                                       (0x18L && (safe_rshift_func_int16_t_s_s(
                                                     0x746BL, 2))),
                                       ((g_570[0][6][3] = l_728) &&
                                        (safe_div_func_int8_t_s_s(
                                            (-1L),
                                            ((safe_sub_func_int32_t_s_s(
                                                 (g_160[4] | l_370[4]),
                                                 (l_734 =
                                                      (g_119 =
                                                           (l_733 =
                                                                (l_584 = g_98
                                                                     [3][0]
                                                                     [1])))))) &&
                                             l_392[3])))))))),
                               g_80[6]))) &&
                          0xA647L),
                         0x733BC389L)),
                     g_108)) > g_167) > 0UL),
               l_609[0][0])) == g_287)) {
        for (l_575 = 0; (l_575 <= 6); l_575 += 1) {
          for (g_683 = 0; (g_683 <= 6); g_683 += 1) {
            int i, j;
            return l_358[g_683][l_575];
          }
        }
        (g_6 | 4294967291UL);
      } else {
        int8_t l_754[9][2][3] = {
            {{(-8L), 0x0FL, (-8L)}, {(-8L), 0x0FL, (-8L)}},
            {{(-8L), 0x0FL, (-8L)}, {(-8L), 0x0FL, (-8L)}},
            {{(-8L), 0x0FL, (-8L)}, {(-8L), 0x0FL, (-8L)}},
            {{(-8L), 0x0FL, (-8L)}, {(-8L), 0x0FL, (-8L)}},
            {{(-8L), 0x0FL, (-8L)}, {(-8L), 0x0FL, (-8L)}},
            {{(-8L), 0x0FL, (-8L)}, {(-8L), 0x0FL, (-8L)}},
            {{(-8L), 0x0FL, (-8L)}, {(-8L), 0x0FL, (-8L)}},
            {{(-8L), 0x0FL, (-8L)}, {(-8L), 0x0FL, (-8L)}},
            {{(-8L), 0x0FL, (-8L)}, {(-8L), 0x0FL, (-8L)}}};
        int32_t l_756 = 9L;
        int i, j, k;
        for (g_28 = 0; (g_28 == 56);
             g_28 = safe_add_func_uint16_t_u_u(g_28, 4)) {
          uint32_t l_759 = 4294967295UL;
          int32_t l_791 = 0x31EABBE9L;
          if (p_45) {
            uint8_t l_745 = 0xBFL;
            l_734 |= (safe_div_func_int8_t_s_s(
                (safe_add_func_int8_t_s_s(
                    (safe_sub_func_int16_t_s_s(
                        g_683,
                        (safe_lshift_func_uint8_t_u_u(
                            (g_80[6] = l_745),
                            (4L ||
                             (l_745 ==
                              ((safe_sub_func_int32_t_s_s(
                                   ((g_160[4] !=
                                     (safe_mul_func_int16_t_s_s(
                                         (safe_div_func_uint32_t_u_u(
                                             4294967289UL, l_754[6][1][2])),
                                         0x7BE3L))) ==
                                    (((g_242 ^ p_44) && g_97) <= l_755[1])),
                                   p_45)) &&
                               l_745))))))),
                    0x27L)),
                255UL));
            if (l_392[6])
              continue;
            g_209 ^= l_754[3][0][2];
            p_46 &= 0xBDL;
          } else {
            uint16_t l_789[9];
            int i;
            for (i = 0; i < 9; i++) {
              l_789[i] = 1UL;
              (safe_div_func_int8_t_s_s(g_287, g_28));
              (safe_add_func_int32_t_s_s(
                  ((safe_add_func_uint8_t_u_u((g_93 != p_46), (g_7 > 0x66L))) >
                   8L),
                  7UL));
            }
            g_209 = 0xE4FD6E78L;
            ((safe_mul_func_uint8_t_u_u(4UL, g_80[6])) || (-1L));
            ++l_759;
            safe_add_func_int64_t_s_s(p_45, 6);
            if (p_46) {
              continue;
              g_209 =
                  ((p_45 | (safe_lshift_func_int8_t_s_s(p_44, p_45))) !=
                   ((safe_rshift_func_int8_t_s_s(
                        (((((g_881 = (g_881 = (safe_lshift_func_uint16_t_u_u(
                                          g_289, 2)))) &&
                            (0x8E89L ^
                             (g_288 &= (safe_mod_func_int8_t_s_s(
                                  (safe_mod_func_uint32_t_u_u(
                                      (safe_mul_func_int16_t_s_s(
                                          ((safe_mod_func_uint8_t_u_u(
                                               (safe_sub_func_uint32_t_u_u(
                                                   g_242,
                                                   (safe_rshift_func_int16_t_s_s(
                                                       (g_1158 ^= (-1L)),
                                                       ((safe_div_func_int64_t_s_s(
                                                            ((safe_div_func_int16_t_s_s(
                                                                 (g_186 =
                                                                      ((safe_mod_func_int32_t_s_s(
                                                                           (((((safe_lshift_func_uint8_t_u_u(
                                                                                   g_881,
                                                                                   ((p_44 >
                                                                                     0x13F8DDA601CE15D2LL) >=
                                                                                    65531UL))) &&
                                                                               g_80[1]) &&
                                                                              p_45) !=
                                                                             p_46) |
                                                                            g_119),
                                                                           5UL)) !=
                                                                       g_80[6])),
                                                                 g_160[4])) &&
                                                             1UL),
                                                            18446744073709551607UL)) &
                                                        p_44))))),
                                               p_45)) &&
                                           p_46),
                                          p_46)),
                                      0xD55B61E1L)),
                                  0x5DL))))) |
                           0x6BL) > g_33) &&
                         g_881),
                        g_242)) |
                    g_7));
              (((safe_div_func_uint16_t_u_u(8UL, 5UL)) && g_108) ^
               18446744073709551615UL);
            }
     l_584
       =
       (~
        (safe_div_func_uint64_t_u_u
  ((safe_add_func_uint8_t_u_u ((g_80[2] = (((~((safe_lshift_func_int16_t_s_u ((l_678 &= ((((safe_lshift_func_int16_t_s_s (((safe_lshift_func_uint8_t_u_u (((((safe_rshift_func_uint16_t_u_u ((((((((safe_sub_func_int32_t_s_s ((((safe_mod_func_int16_t_s_s (((safe_mul_func_int16_t_s_s ((0UL & 4294967295UL), (safe_add_func_int32_t_s_s (l_575, ((g_289 = (g_287 = 1L)) | ((8L >= (l_359 = ((safe_sub_func_uint64_t_u_u (18446744073709551614UL, g_186)) <= (safe_mul_func_uint8_t_u_u ((g_711 != ((safe_unary_minus_func_uint16_t_u ((+(safe_mul_func_int16_t_s_s ((l_759 >= g_28), g_757[2]))))) > g_108)), 0x92L))))) ^ p_46)))))) && 1UL), l_759)) != p_44) | g_186), p_44)) != p_45) || g_287) ^ l_759) <= 1L) && g_711) ^ g_522), p_45)) & g_758) & l_756) & 0x4DC30212L), l_759)) && g_711), l_759)) < l_754[1][1][2]) && l_754[4][1][2]) || l_789[3])), l_584)) < 1L)) == 0UL) <= g_167)), 1L)), l_754[6][1][2])));
     (safe_add_func_int16_t_s_s(
         (safe_mod_func_int64_t_s_s(
             (((g_98[3][3][5]++) & g_522) >=
              (safe_mul_func_int8_t_s_s(
                  (((safe_unary_minus_func_int16_t_s((g_288 = 0xD04DL))) >
                    (g_160[4] = (safe_div_func_int64_t_s_s(
                         p_44, (safe_lshift_func_uint8_t_u_u(g_7, 1)))))) &
                   (g_881 && (p_46 = g_570[0][1][3]))),
                  (((safe_mul_func_uint16_t_u_u(
                        (safe_add_func_uint16_t_u_u(p_44, p_44)), g_881)) <=
                    p_44) < 0x35471BC2L)))),
             g_242)),
         (-6L))) < p_45;
          }
          for (l_640 = 4; (l_640 >= 1); l_640 -= 1) {
            int i;
            l_391 &= (!(!g_160[l_640]));
            ((safe_sub_func_uint16_t_u_u(
                 p_44, (safe_rshift_func_int16_t_s_s(g_33, g_20)))) >=
             (g_290 &&
              (((((+(safe_mod_func_uint32_t_u_u(
                      (safe_lshift_func_uint8_t_u_u(0xA3L, 1)),
                      ((g_287 !=
                        (((safe_lshift_func_uint8_t_u_s(
                              (g_80[6] = (g_93 ^= (safe_div_func_int32_t_s_s(
                                              0x5255962FL, 0x238FD6C5L)))),
                              1)) <
                          ((safe_mod_func_uint8_t_u_u(
                               (safe_sub_func_uint32_t_u_u((0x9B101B88L ^ p_45),
                                                           g_242)),
                               g_33)) ||
                           g_290)) > g_98[3][1][2])) &
                       0xDCAF8491147520D1LL)))) != g_209) >= g_93) ^
                0UL) |
               0x171CL)));
            g_792++;
          }
          g_287 = (((p_45 ^ (safe_add_func_uint32_t_u_u(g_790, 0L))) &&
                    (safe_lshift_func_int8_t_s_u(
                        (safe_lshift_func_int8_t_s_s(g_7, g_160[4])), 3))) &
                   (p_45 || (g_80[6] = (g_186 >= (safe_add_func_uint16_t_u_u(
                                                     g_522, 0x196CL))))));
          for (l_640 = (-21); (l_640 < 0);
               l_640 = safe_add_func_uint64_t_u_u(l_640, 9)) {
            if (l_358[3][0])
              break;
            return g_98[3][3][5];
          }
          return g_522;
        }
        (+(g_20 != 0x78016B84L)) | (--g_98[3][3][5]);
        for (p_45 = (-21); (p_45 > (-8)); p_45++) {
          int16_t l_819 = 2L;
          int32_t l_820[4][5];
          int32_t l_829 = (-1L);
          int i, j;
          for (i = 0; i < 4; i++) {
            for (j = 0; j < 5; j++)
              l_820[i][j] = 0xECF4C802L;
            safe_add_func_uint64_t_u_u(
                ((safe_rshift_func_int8_t_s_s(
                     (safe_rshift_func_uint16_t_u_s(
                         (safe_div_func_uint16_t_u_u(g_904, p_46)),
                         ((safe_mod_func_int64_t_s_s(
                              (safe_div_func_int8_t_s_s(
                                  (safe_add_func_uint64_t_u_u(1UL, (-1L))),
                                  0x22L)),
                              p_45)) ^
                          4294967295UL))),
                     5)) >= g_80[7]),
                g_881);
          }
          safe_div_func_int16_t_s_s(0L,
                                    (safe_unary_minus_func_int8_t_s(g_242)));
          l_756 =
              (g_758 ^
               ((safe_mul_func_uint16_t_u_u(
                    0x8E37L,
                    (safe_mod_func_int16_t_s_s(
                        l_610,
                        (safe_mod_func_int32_t_s_s(
                            (safe_add_func_uint32_t_u_u(
                                (~(safe_lshift_func_uint16_t_u_u(
                                    p_44,
                                    (safe_lshift_func_uint8_t_u_u(
                                        ((0x57227E63L |
                                          ((safe_sub_func_uint16_t_u_u(
                                               ((l_819 =
                                                     ((((safe_unary_minus_func_uint8_t_u((
                                                            (safe_mod_func_int8_t_s_s(
                                                                ((p_45 &
                                                                  ((safe_sub_func_uint16_t_u_u(
                                                                       p_45,
                                                                       ((+g_818
                                                                             [5]
                                                                             [5]
                                                                             [1]) ^
                                                                        p_46))) >=
                                                                   1UL)) ^
                                                                 0x9D9E5A98B67BD671LL),
                                                                g_242)) |
                                                            l_609[1][7]))) &&
                                                        g_119) &&
                                                       l_486) |
                                                      p_46)) != 0L),
                                               l_678)) != l_820[1][4])) ==
                                         p_44),
                                        l_640))))),
                                p_45)),
                            p_45)))))) != g_711));
          (safe_div_func_int8_t_s_s(g_287, g_28));
          for (l_487 = (-6); (l_487 <= (-9));
               l_487 = safe_sub_func_int8_t_s_s(l_487, 1)) {
            int64_t l_838[9][7] = {{(-8L), 0x3A2827331975AB1FLL, (-5L),
                                    0x92ED3B5F7EA75A99LL, 0x3A2827331975AB1FLL,
                                    0x24BBEFABC2B520E3LL, 0x3A2827331975AB1FLL},
                                   {(-8L), 0x3A2827331975AB1FLL, (-5L),
                                    0x92ED3B5F7EA75A99LL, 0x3A2827331975AB1FLL,
                                    0x24BBEFABC2B520E3LL, 0x3A2827331975AB1FLL},
                                   {(-8L), 0x3A2827331975AB1FLL, (-5L),
                                    0x92ED3B5F7EA75A99LL, 0x3A2827331975AB1FLL,
                                    0x24BBEFABC2B520E3LL, 0x3A2827331975AB1FLL},
                                   {(-8L), 0x3A2827331975AB1FLL, (-5L),
                                    0x92ED3B5F7EA75A99LL, 0x3A2827331975AB1FLL,
                                    0x24BBEFABC2B520E3LL, 0x3A2827331975AB1FLL},
                                   {(-8L), 0x3A2827331975AB1FLL, (-5L),
                                    0x92ED3B5F7EA75A99LL, 0x3A2827331975AB1FLL,
                                    0x24BBEFABC2B520E3LL, 0x3A2827331975AB1FLL},
                                   {(-8L), 0x3A2827331975AB1FLL, (-5L),
                                    0x92ED3B5F7EA75A99LL, 0x3A2827331975AB1FLL,
                                    0x24BBEFABC2B520E3LL, 0x3A2827331975AB1FLL},
                                   {(-8L), 0x3A2827331975AB1FLL, (-5L),
                                    0x92ED3B5F7EA75A99LL, 0x3A2827331975AB1FLL,
                                    0x24BBEFABC2B520E3LL, 0x3A2827331975AB1FLL},
                                   {(-8L), 0x3A2827331975AB1FLL, (-5L),
                                    0x92ED3B5F7EA75A99LL, 0x3A2827331975AB1FLL,
                                    0x24BBEFABC2B520E3LL, 0x3A2827331975AB1FLL},
                                   {(-8L), 0x3A2827331975AB1FLL, (-5L),
                                    0x92ED3B5F7EA75A99LL, 0x3A2827331975AB1FLL,
                                    0x24BBEFABC2B520E3LL,
                                    0x3A2827331975AB1FLL}};
            int i, j;
            l_359 =
                ((safe_div_func_uint32_t_u_u(
                     ((safe_mod_func_uint32_t_u_u(
                          ((safe_sub_func_uint32_t_u_u(
                               ((l_829 == (-5L)) < 0xABL),
                               (p_45 ||
                                (safe_sub_func_uint8_t_u_u(
                                    (safe_mul_func_int8_t_s_s(
                                        ((safe_mul_func_uint8_t_u_u(4UL,
                                                                    g_80[6])) ||
                                         (-1L)),
                                        (safe_sub_func_uint16_t_u_u(
                                            (l_734 = 0x09E4L), l_838[6][2])))),
                                    l_610))))) &
                           4294967286UL),
                          l_678)) == 0xBEL),
                     p_46)) &&
                 p_44);
            g_209 = 5L;
            g_209 = ((l_359 = (g_98[3][3][5] ^= 0x674DFE66L)) < 0xA8B89E61L);
            (safe_mul_func_int16_t_s_s(
                ((safe_add_func_int32_t_s_s(
                     ((safe_add_func_uint8_t_u_u((g_93 != p_46),
                                                 (g_7 > 0x66L))) > 8L),
                     7UL)) ||
                 4294967289UL),
                g_80[7]));
            g_209 = (safe_rshift_func_uint16_t_u_s(
                (safe_sub_func_uint32_t_u_u(
                    (safe_mul_func_int16_t_s_s(
                        (((g_186 ^= l_358[5][1]) <=
                          ((p_46 >= ((l_838[6][2] ^ p_46) | p_44)) >
                           (safe_mod_func_int16_t_s_s(g_93, g_209)))) &
                         (2L | (((((safe_lshift_func_int16_t_s_u(
                                       ((safe_mul_func_int8_t_s_s(
                                            (((((safe_mul_func_uint16_t_u_u(
                                                    (g_288 > g_790), 0x244FL)) ^
                                                l_358[7][5]) |
                                               0x2FADCC73L) > 4294967289UL) &
                                             0xC4A2CD4DL),
                                            l_819)) != l_676),
                                       7)) > l_358[5][1]) > p_45) |
                                 0x0A28BDAC16F4C2DBLL) |
                                g_97))),
                        p_44)),
                    l_733)),
                6));
          }
          (0x2F37L <=
           (g_160[3] = (safe_add_func_uint64_t_u_u(
                (--g_930), ((g_818[1][4][0] & p_44) >= g_98[3][0][3])))));
          if (((safe_lshift_func_int8_t_s_u(p_46, 0)) >=
               (safe_unary_minus_func_int32_t_s((safe_sub_func_int8_t_s_s(
                   ((safe_div_func_int8_t_s_s(
                        (safe_lshift_func_int8_t_s_s(
                            (p_44 |
                             (safe_mul_func_int8_t_s_s(
                                 ((safe_div_func_int8_t_s_s(
                                      ((safe_lshift_func_int16_t_s_u(
                                           (safe_rshift_func_uint16_t_u_u(
                                               ((safe_lshift_func_int8_t_s_u(
                                                    l_728, 7)) <
                                                (l_756 =
                                                     (safe_lshift_func_uint8_t_u_u(
                                                         (g_97 == 0xFEC6L),
                                                         0)))),
                                               ((7UL != p_46) <=
                                                (l_392[0] = g_209)))),
                                           1)) ==
                                       (safe_rshift_func_uint8_t_u_s(
                                           (((safe_div_func_int8_t_s_s(p_44,
                                                                       8UL)) &
                                             p_44) < 0L),
                                           g_792))),
                                      255UL)) &&
                                  g_790),
                                 g_98[3][3][5]))),
                            5)),
                        p_46)) <= p_45),
                   255UL)))))) {
            uint16_t l_878 = 1UL;
            l_391 |= ((-3L) | (p_46 &= 0xBDL));
            --l_878;
          } else {
            return p_44;
          }
        }
      }
      g_7 = (safe_div_func_int8_t_s_s(((g_290 || g_7) && g_7),
                                      ((g_119 ^= (g_80[5] ^ 6L)) ^ g_80[1])));
    } else {
      uint64_t l_882 = 0xC4FAA6AFB3AA35BELL;
      int32_t l_885[7][10] = {
          {1L, 0x85F7A62DL, 0x2EF11AB3L, 0xA9F21676L, 0x977CB2F5L, 0xF0F48E68L,
           0xEB176F88L, 0L, 0xEB176F88L, 0xF0F48E68L},
          {1L, 0x85F7A62DL, 0x2EF11AB3L, 0xA9F21676L, 0x977CB2F5L, 0xF0F48E68L,
           0xEB176F88L, 0L, 0xEB176F88L, 0xF0F48E68L},
          {1L, 0x85F7A62DL, 0x2EF11AB3L, 0xA9F21676L, 0x977CB2F5L, 0xF0F48E68L,
           0xEB176F88L, 0L, 0xEB176F88L, 0xF0F48E68L},
          {1L, 0x85F7A62DL, 0x2EF11AB3L, 0xA9F21676L, 0x977CB2F5L, 0xF0F48E68L,
           0xEB176F88L, 0L, 0xEB176F88L, 0xF0F48E68L},
          {1L, 0x85F7A62DL, 0x2EF11AB3L, 0xA9F21676L, 0x977CB2F5L, 0xF0F48E68L,
           0xEB176F88L, 0L, 0xEB176F88L, 0xF0F48E68L},
          {1L, 0x85F7A62DL, 0x2EF11AB3L, 0xA9F21676L, 0x977CB2F5L, 0xF0F48E68L,
           0xEB176F88L, 0L, 0xEB176F88L, 0xF0F48E68L},
          {1L, 0x85F7A62DL, 0x2EF11AB3L, 0xA9F21676L, 0x977CB2F5L, 0xF0F48E68L,
           0xEB176F88L, 0L, 0xEB176F88L, 0xF0F48E68L}};
      uint8_t l_887 = 0x2CL;
      int i, j;
      l_882--;
      (safe_lshift_func_uint8_t_u_u((g_97 == 0xFEC6L), 0));
      l_887--;
    }
  } else {
    uint8_t l_900 = 6UL;
    int32_t l_901[5][7][5] = {
        {{0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L}},
        {{0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L}},
        {{0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L}},
        {{0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L}},
        {{0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L},
         {0x10FE3511L, 0xA4B54BD4L, (-1L), 0xF67C02A0L, 6L}}};
    int32_t l_902 = 0L;
    int32_t l_903 = 0L;
    int32_t l_969[1];
    uint64_t l_1070 = 0xE56B680A9D8B0594LL;
    int i, j, k;
    for (i = 0; i < 1; i++)
      l_969[i] = 0x95D80C93L;
    l_392[1] =
        ((safe_rshift_func_int8_t_s_u((safe_sub_func_uint64_t_u_u(p_44, g_186)),
                                      3)) <=
         (safe_mod_func_int8_t_s_s(
             p_46, (l_359 ^= ((0xFE0AL >=
                               ((((!(-1L)) || 0xA5L) &&
                                 (((safe_rshift_func_int16_t_s_u(
                                       ((((((safe_add_func_int16_t_s_s(
                                                ((p_46 > p_46) <= p_44),
                                                l_900)) != p_44) >= l_392[3]) &
                                          0x5FL) |
                                         8L) &
                                        l_900),
                                       0)) == p_44) &&
                                  l_901[4][3][4])) &
                                g_186)) &
                              p_45)))));
    g_904--;
    if (p_45) {
      int32_t l_920 = 0x41239524L;
      int32_t l_927 = 0x905DF63AL;
      int32_t l_928 = 0xA3D2E98AL;
      uint32_t l_970 = 18446744073709551606UL;
      l_391 = (safe_add_func_uint16_t_u_u(
          (~(((safe_rshift_func_int16_t_s_s(
                  ((((safe_mul_func_int8_t_s_s(
                         (((safe_mul_func_uint8_t_u_u(
                               g_792,
                               (safe_sub_func_uint64_t_u_u(
                                   18446744073709551606UL,
                                   (safe_lshift_func_uint16_t_u_u(
                                       p_46, (safe_unary_minus_func_uint32_t_u(
                                                 0x7B47903EL)))))))) <=
                           ((l_920 >
                             (safe_mul_func_uint8_t_u_u(
                                 (1UL !=
                                  (safe_add_func_uint64_t_u_u(
                                      (+18446744073709551615UL), l_487))),
                                 ((safe_mod_func_uint16_t_u_u(
                                      (((-4L) <= l_920) != l_901[1][1][3]),
                                      l_920)) != l_487)))) &
                            l_900)) ||
                          g_242),
                         p_46)) != 0UL) != p_45) <= 0x05D8F5F7L),
                  7)) ^
              g_757[1]) == 0xA648F9ABL)),
          g_119));
      g_930++;
      g_108 &= (0UL <= g_80[6]);
      l_903 &= (safe_div_func_int64_t_s_s(
          ((~(l_487 =
                  ((((safe_sub_func_int8_t_s_s(
                         (g_683 = 1L),
                         ((((((safe_sub_func_int32_t_s_s(((g_792++) < p_44),
                                                         g_98[0][4][3])) <=
                              (p_45 | 65530UL)) ==
                             ((safe_sub_func_uint32_t_u_u(
                                  (safe_div_func_int32_t_s_s(
                                      p_45,
                                      ((safe_rshift_func_uint8_t_u_u(p_44, 2)) |
                                       (safe_mod_func_int16_t_s_s(
                                           g_80[6], (safe_sub_func_int16_t_s_s(
                                                        g_711, p_46))))))),
                                  l_486)) != 0xB09A972074621008LL)) ^
                            0x0216L) |
                           g_287) != 0x6EE7L))) ||
                     l_358[5][1]) == p_44) &
                   g_881))) |
           p_46),
          l_901[3][5][4]));
      g_28 = 0;
      l_928 =
          ((((l_927 == l_370[0]) <= 0x24C1L) ==
            (safe_mul_func_int16_t_s_s(
                ((g_108 =
                      ((safe_mod_func_int8_t_s_s(
                           ((safe_add_func_uint32_t_u_u(
                                g_108,
                                ((l_902 &= (l_920 &= l_927)) |
                                 (safe_add_func_int64_t_s_s(
                                     (((safe_mul_func_int8_t_s_s(
                                           ((safe_lshift_func_uint16_t_u_s(
                                                (l_928 >= (0L < l_903)), 3)) >=
                                            (safe_mod_func_uint32_t_u_u(
                                                ((l_969[0] =
                                                      (safe_mod_func_uint16_t_u_u(
                                                          (safe_mod_func_uint32_t_u_u(
                                                              (((g_711 >
                                                                 l_927) <
                                                                g_97) != 248UL),
                                                              l_927)),
                                                          p_46))) > g_904),
                                                p_46))),
                                           (-1L))) == (-9L)) <= l_970),
                                     1L))))) &&
                            p_45),
                           l_358[2][6])) >= g_20)) == p_46),
                l_971))) ^
           p_45);
    } else {
      uint32_t l_1003 = 1UL;
      int32_t l_1004 = 0x77783C91L;
      int32_t l_1005 = 0x743BF802L;
      if (g_930) {
        int16_t l_979 = (-10L);
        int32_t l_986 = 0xFC21A6DCL;
        l_391 ^= (safe_unary_minus_func_int64_t_s(
            (((safe_add_func_uint64_t_u_u(4UL, p_45)) <
              ((safe_mod_func_uint64_t_u_u(
                   ((p_45 <
                     ((((safe_lshift_func_int8_t_s_s(l_979, 1)) || l_487) ^
                       (g_28 |
                        (l_359 ^=
                         ((0x0FL ==
                           (((p_45 ^
                              (safe_sub_func_uint32_t_u_u(
                                  ((g_758 =
                                        (l_986 |= (safe_rshift_func_int8_t_s_s(
                                             ((safe_mod_func_int32_t_s_s(
                                                  (l_392[3] = p_44), g_289)) <
                                              p_44),
                                             6)))) > p_46),
                                  l_979))) <= p_45) |
                            l_979)) &
                          0x115A6EDAL)))) &&
                      0x0B41L)) <= p_46),
                   p_44)) > 0x49C5432DCB1A87BALL)) == g_242)));
        safe_mul_func_uint8_t_u_u(
            (g_711 !=
             ((safe_unary_minus_func_uint16_t_u((+(safe_mul_func_int16_t_s_s(
                  (g_33 >= g_28), g_757[2]))))) > g_108)),
            0x92L);
      } else {
        int32_t l_1000 = 0x7B81EE53L;
        int32_t l_1006 = 0L;
        int32_t l_1008 = (-1L);
        uint8_t l_1049 = 247UL;
        for (g_93 = 0; (g_93 <= 7); g_93 += 1) {
          int16_t l_991 = 0xFC10L;
          int32_t l_1027 = (-1L);
          int32_t l_1048 = 0xCDDD98D3L;
          int i;
          l_969[0] = ((~g_80[g_93]) &&
                      ((safe_add_func_uint32_t_u_u(
                           (g_20 |= (safe_mul_func_uint16_t_u_u(
                                ((g_80[g_93] <= l_392[4]) >=
                                 (l_391 = (l_370[0] != g_160[1]))),
                                (l_991 >= (safe_mul_func_int16_t_s_s(
                                              ((~((!g_929) != 0x2CCC1DEBL)) <
                                               (((safe_sub_func_int32_t_s_s(
                                                     l_901[4][3][4], g_80[1])) >
                                                 (-3L)) < l_901[4][3][4])),
                                              p_46)))))),
                           p_45)) < 0xD4L));
          for (g_20 = 0; (g_20 <= 0); g_20 += 1) {
            int32_t l_1007 = 0L;
            int i;
            l_1008 = (safe_add_func_uint64_t_u_u(
                l_969[g_20],
                (((~(((l_969[g_20] <= (g_160[3] <= g_33)) == p_44) |
                     (l_1007 =
                          (((l_1006 =
                                 ((l_1005 =
                                       ((((safe_rshift_func_int16_t_s_u(
                                              (l_1004 =
                                                   (l_903 =
                                                        ((l_1000 &=
                                                          (g_881 = (-8L))) &
                                                         (safe_add_func_int32_t_s_s(
                                                             (p_46 &&
                                                              ((g_242 =
                                                                    (l_1003 =
                                                                         g_758)) |
                                                               ((p_46 =
                                                                     (g_80[g_93] ==
                                                                      p_44)) <
                                                                1UL))),
                                                             g_288))))),
                                              12)) |
                                          4L) &&
                                         l_969[g_20]) < p_45)) >= 0UL)) !=
                            (-7L)) < l_901[4][2][1])))) &
                  p_45) &&
                 2UL)));
            return l_370[0];
          }
          if ((safe_add_func_int16_t_s_s(
                  (g_93 |
                   (g_881 =
                        (((safe_div_func_int8_t_s_s(
                              (safe_mul_func_int8_t_s_s(
                                  ((((((safe_div_func_int8_t_s_s(g_287, g_28)) |
                                       (((safe_mul_func_int8_t_s_s(
                                             (safe_div_func_int16_t_s_s(
                                                 (p_46 <=
                                                  (+(safe_rshift_func_uint8_t_u_s(
                                                      0x0BL, g_80[g_93])))),
                                                 0x747CL)),
                                             (l_391 =
                                                  ((g_209 ^= l_900) <=
                                                   ((safe_rshift_func_int16_t_s_s(
                                                        (((l_359 = (safe_sub_func_uint64_t_u_u(
                                                               l_1004,
                                                               0xD1990C90AB741CE7LL))) <=
                                                          l_1008) &&
                                                         0L),
                                                        3)) < 0UL))))) ||
                                         0xD700L) < p_45)) > l_1008) &&
                                     g_186) > g_119) &&
                                   g_289),
                                  254UL)),
                              0xFDL)) >= 0L) == p_44))),
                  l_1027))) {
            uint32_t l_1034[3];
            int i;
            for (i = 0; i < 3; i++) {
              l_1034[i] = 4294967295UL;
              p_45 = ((g_7 &= (g_881 = (-8L))) &
                      (safe_add_func_int32_t_s_s(
                          (p_46 && ((g_242 = (g_290 = g_758)) |
                                    ((p_46 = (g_80[g_93] == p_44)) < 1UL))),
                          g_288)));
              (g_97 = p_44);
            }
            g_209 &= (safe_mod_func_int32_t_s_s(
                (l_902 =
                     ((safe_mod_func_int16_t_s_s(
                          (safe_lshift_func_int8_t_s_s(
                              ((l_1034[2] != p_45) ==
                               (safe_rshift_func_uint8_t_u_u(
                                   (l_358[2][3] |
                                    (0x7FACC498FE45646FLL &&
                                     ((g_108 <
                                       (((((safe_mod_func_uint32_t_u_u(
                                               (safe_mul_func_int8_t_s_s(
                                                   (l_1004 =
                                                        ((((g_160[2] &=
                                                            g_522) !=
                                                           (safe_mod_func_int32_t_s_s(
                                                               (safe_mul_func_int8_t_s_s(
                                                                   (safe_mul_func_uint8_t_u_u(
                                                                       (safe_unary_minus_func_int16_t_s(
                                                                           0L)),
                                                                       g_757
                                                                           [0])),
                                                                   p_44)),
                                                               p_44))) ^
                                                          g_97) &
                                                         p_44)),
                                                   l_1048)),
                                               l_1049)) &&
                                           p_45) <= p_46) == l_1050) ^
                                        g_242)) &&
                                      g_570[2][0][2]))),
                                   g_242))),
                              2)),
                          65530UL)) ||
                      l_1034[2])),
                p_45));
          } else {
            uint32_t l_1065[5][3] = {{0x9FB3758DL, 0x9FB3758DL, 0xE2466839L},
                                     {0x9FB3758DL, 0x9FB3758DL, 0xE2466839L},
                                     {0x9FB3758DL, 0x9FB3758DL, 0xE2466839L},
                                     {0x9FB3758DL, 0x9FB3758DL, 0xE2466839L},
                                     {0x9FB3758DL, 0x9FB3758DL, 0xE2466839L}};
            int32_t l_1067 = 0x6760B56FL;
            int i, j;
            l_1067 ^=
                (0L <
                 (g_1066 &=
                  (0x86C053D3L !=
                   (p_45 !=
                    (l_1004 |= (safe_sub_func_int64_t_s_s(
                         (g_80[g_93] ^
                          ((safe_sub_func_int8_t_s_s(
                               (65530UL |
                                (((safe_div_func_int8_t_s_s(
                                      (safe_mul_func_uint16_t_u_u(
                                          (g_242 ^=
                                           ((!(p_45 ==
                                               (0xE3EAA11AL && (+1UL)))) &&
                                            ((safe_mod_func_uint64_t_u_u(
                                                 (safe_add_func_uint64_t_u_u(
                                                     (safe_sub_func_int32_t_s_s(
                                                         g_288,
                                                         l_901[3][1][1])),
                                                     l_1065[2][1])),
                                                 p_46)) != 1UL))),
                                          g_80[g_93])),
                                      g_167)) == 0xE6DBF25E9BA19536LL) &&
                                 p_45)),
                               l_1000)) > p_44)),
                         p_44)))))));
            l_1067 = g_160[2];
            l_1070 ^= (safe_sub_func_uint64_t_u_u(0x5B58B4B693C4496ELL,
                                                  (g_167 = 5L)));
          }
        }
      }
      ((safe_mod_func_uint8_t_u_u(
           (safe_sub_func_uint32_t_u_u((0x9B101B88L ^ p_45), g_242)), g_33)) ||
       g_290);
    }
  }
  g_930--;
  for (g_1066 = 0; (g_1066 <= 4); g_1066 += 1) {
    int16_t l_1071 = 0x0622L;
    int i;
    ++g_1072;
    g_881 &= (safe_lshift_func_int16_t_s_u(g_160[g_1066], 10));
    l_487 = (safe_div_func_uint32_t_u_u(
        (g_98[3][3][5] =
             ((safe_rshift_func_uint16_t_u_s(
                  l_971,
                  (((g_80[3] &&
                     (~(((safe_rshift_func_int16_t_s_u(
                             l_1071,
                             (((safe_add_func_int32_t_s_s(
                                   g_929,
                                   (l_359 &= (safe_div_func_int64_t_s_s(
                                        (-1L),
                                        (safe_div_func_int16_t_s_s(
                                            ((g_242 =
                                                  (safe_rshift_func_int16_t_s_u(
                                                      p_46, l_1071))) ||
                                             (safe_mul_func_int16_t_s_s(
                                                 (safe_div_func_uint16_t_u_u(
                                                     ((((safe_div_func_uint16_t_u_u(
                                                            (((safe_div_func_uint16_t_u_u(
                                                                  8UL, 5UL)) &&
                                                              g_108) ^
                                                             18446744073709551615UL),
                                                            g_288)) &&
                                                        g_98[2][4][2]) &&
                                                       0xB4157F29L) >= p_46),
                                                     p_46)),
                                                 l_358[5][1]))),
                                            p_44))))))) ||
                               l_1071) == 0xDA39CE5FC90F89B7LL))) ^
                         l_391) |
                        l_1099))) &&
                    0L) == 0UL))) |
              g_711)),
        0xEA27E73AL));
    (safe_sub_func_uint64_t_u_u(0x5B58B4B693C4496ELL, (g_167 = 5L)));
    if (g_904)
      break;
  }
  return l_359;
}
static int32_t func_48(int16_t p_49, uint8_t p_50) { return g_290; }
static int16_t func_57(int64_t p_58, uint32_t p_59, int32_t p_60,
                       int16_t p_61) {
  int32_t l_327 = 0L;
  int32_t l_336 = 0xE5E51F4DL;
  int32_t l_337 = 0x2F055FC9L;
  int32_t l_338 = (-1L);
  int32_t l_339 = 0x5E111E5CL;
  int32_t l_340 = 0x800E9987L;
  l_340 ^=
      ((0UL >=
        (((g_108 &=
           ((((((((safe_lshift_func_uint8_t_u_s(
                      (((g_167 ^= (safe_div_func_int8_t_s_s(
                             (safe_add_func_int8_t_s_s(5L, 0x08L)),
                             ((safe_mod_func_int8_t_s_s(
                                  (l_339 =
                                       ((safe_mul_func_int8_t_s_s(
                                            (safe_sub_func_uint64_t_u_u(
                                                ((safe_mul_func_uint16_t_u_u(
                                                     l_327,
                                                     (l_327 !=
                                                      (safe_mod_func_int8_t_s_s(
                                                          (((safe_div_func_uint8_t_u_u(
                                                                (safe_lshift_func_uint8_t_u_u(
                                                                    (l_338 = (safe_sub_func_int16_t_s_s(
                                                                         g_97,
                                                                         (255UL <
                                                                          (l_337 =
                                                                               (l_336 =
                                                                                    g_93)))))),
                                                                    g_287)),
                                                                p_59)) < p_58) <
                                                           p_58),
                                                          l_327))))) <=
                                                 g_98[2][2][0]),
                                                7L)),
                                            (-4L))) <= 6UL)),
                                  g_209)) ||
                              0xD0FAL)))) <= p_59) ^
                       0x07L),
                      1)) >= 1L) ^
                 0xC6D7EFADBB9006ACLL) &&
                0x0DAE1A5DL) < p_60) <= g_80[0]) == 1L) ^
            g_160[4])) == p_60) < g_80[6])) ||
       g_209);
  return p_60;
}
static int64_t func_62(uint8_t p_63, int16_t p_64, uint16_t p_65, uint64_t p_66,
                       uint64_t p_67) {
  uint8_t l_69 = 0x2AL;
  int32_t l_70[2];
  int32_t l_77[1];
  int32_t l_103 = 0xF9E9296DL;
  uint32_t l_185 = 18446744073709551615UL;
  int i;
  for (i = 0; i < 2; i++)
    l_70[i] = 0x8D7CD142L;
  for (i = 0; i < 1; i++)
    l_77[i] = (-1L);
lbl_81:
  l_70[0] = l_69;
  if ((p_65 !=
       (255UL &
        (((safe_mul_func_int16_t_s_s(
              ((-4L) >= g_20),
              (safe_div_func_uint64_t_u_u(
                  ((safe_add_func_int64_t_s_s(g_20, (l_77[0] |= l_70[0]))) &&
                   g_20),
                  (g_80[6] ^= (safe_sub_func_int32_t_s_s(
                       (0xCDB59559C29C84D8LL | l_70[1]), g_33))))))) ^
          1UL) <= g_33)))) {
    if (p_65)
      goto lbl_81;
    return p_65;
  } else {
    int32_t l_84 = 1L;
    int32_t l_85 = (-3L);
    int32_t l_96[10][6] = {
        {0xFEA38A5BL, (-9L), 8L, 0xE528CFE7L, 0x672E3E38L, 0xE528CFE7L},
        {0xFEA38A5BL, (-9L), 8L, 0xE528CFE7L, 0x672E3E38L, 0xE528CFE7L},
        {0xFEA38A5BL, (-9L), 8L, 0xE528CFE7L, 0x672E3E38L, 0xE528CFE7L},
        {0xFEA38A5BL, (-9L), 8L, 0xE528CFE7L, 0x672E3E38L, 0xE528CFE7L},
        {0xFEA38A5BL, (-9L), 8L, 0xE528CFE7L, 0x672E3E38L, 0xE528CFE7L},
        {0xFEA38A5BL, (-9L), 8L, 0xE528CFE7L, 0x672E3E38L, 0xE528CFE7L},
        {0xFEA38A5BL, (-9L), 8L, 0xE528CFE7L, 0x672E3E38L, 0xE528CFE7L},
        {0xFEA38A5BL, (-9L), 8L, 0xE528CFE7L, 0x672E3E38L, 0xE528CFE7L},
        {0xFEA38A5BL, (-9L), 8L, 0xE528CFE7L, 0x672E3E38L, 0xE528CFE7L},
        {0xFEA38A5BL, (-9L), 8L, 0xE528CFE7L, 0x672E3E38L, 0xE528CFE7L}};
    int32_t l_115 = 0L;
    int i, j;
    l_85 |= (safe_rshift_func_int8_t_s_s(l_84, 3));
    if ((safe_sub_func_uint64_t_u_u(
            (((l_96[6][4] =
                   ((safe_unary_minus_func_int32_t_s(l_70[0])) ^
                    (((l_85 = (safe_sub_func_int8_t_s_s(1L, g_80[6]))) >
                      (safe_mul_func_uint8_t_u_u(
                          (((p_64 && (!p_65)) !=
                            ((g_93 = g_20) >=
                             ((l_103 = (l_77[0] |= (safe_lshift_func_int8_t_s_u(
                                            (g_97 = ((+(g_20 != 0x78016B84L)) |
                                                     (--g_98[3][3][5]))),
                                            (safe_mod_func_uint16_t_u_u(
                                                (0x00L | 0x93L), p_67)))))) <
                              l_96[3][0]))) &&
                           g_80[6]),
                          l_69))) != 0xB1A94CD5359122B3LL))) |
              (-1L)) == p_67),
            0xD7A8D5DA263B4A82LL))) {
      l_85 = (safe_lshift_func_int16_t_s_u(
          (0xA5A204FE417BD45ELL >
           (l_103 |=
            (((~((g_20 ||
                  (safe_mul_func_uint16_t_u_u(l_96[6][4], (g_108 &= p_64)))) !=
                 g_98[3][3][5])) >
              (safe_div_func_uint32_t_u_u(
                  g_98[2][0][1],
                  (safe_sub_func_int64_t_s_s(
                      g_93, (l_77[0] != (safe_mod_func_int8_t_s_s(
                                            l_115, g_20)))))))) == p_67))),
          g_93));
    } else {
      int32_t l_118 = 0x69D051F7L;
      uint64_t l_163 = 18446744073709551613UL;
      uint32_t l_164 = 0x5938E44DL;
      for (l_103 = 29; (l_103 >= 20); l_103--) {
        uint16_t l_165[4][8][2] = {{{0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL}},
                                   {{0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL}},
                                   {{0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL}},
                                   {{0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL},
                                    {0xB03DL, 0x8A4AL}}};
        int32_t l_166 = 0xE2628837L;
        int i, j, k;
        g_119++;
 l_96
   [6]
   [4]
   =
   (!
    (l_166
     =
     (safe_mul_func_uint16_t_u_u
      (p_64,
       (((((safe_sub_func_uint32_t_u_u ((safe_div_func_int16_t_s_s ((safe_add_func_int64_t_s_s (g_33, (((safe_add_func_uint8_t_u_u (g_20, (safe_rshift_func_uint8_t_u_u ((((safe_rshift_func_uint8_t_u_s ((safe_rshift_func_uint8_t_u_u (((safe_mul_func_int8_t_s_s (((safe_mul_func_uint16_t_u_u (((safe_lshift_func_int16_t_s_s (((+((p_65 <= g_80[6]) & ((safe_lshift_func_int8_t_s_s ((safe_mod_func_int16_t_s_s ((safe_rshift_func_int16_t_s_s (((safe_sub_func_int16_t_s_s ((l_115 = (((((safe_lshift_func_int8_t_s_u (((g_160[4] |= (safe_rshift_func_int8_t_s_u ((safe_mul_func_int8_t_s_s ((safe_lshift_func_int8_t_s_s (g_80[2], 0)), g_33)), 7))) > g_33), (((safe_lshift_func_int8_t_s_s ((g_108 &= (0UL <= g_80[6])), 2)) & 1L) | 0x3C61D2E95C9911E2LL))) && 0x8C886831L) && l_118) > p_65) > l_77[0])), 0xF977L)) > l_163), 10)), l_70[0])), g_93)) & p_63))) >= 0L), 10)) < g_80[6]), g_98[2][4][5])) < 0xE19FA1A8EB3B5FD3LL), p_66)) > 0x42L), 3)), g_80[6])) ^ g_33) > 7UL), 2)))) < l_164) > l_96[9][1]))), p_63)), p_67)) | p_65) > (-1L)) == l_164) || l_165[1][1][1])))));
 (safe_div_func_int16_t_s_s(0L, (safe_unary_minus_func_int8_t_s(g_242))));
 g_167 &= g_160[2];
 for (l_163 = 22; (l_163 > 48); l_163++) {
   int16_t l_184 = 3L;
   g_186 =
       ((-6L) ||
        (safe_div_func_int32_t_s_s(
            (safe_sub_func_int32_t_s_s(
                (0xFDC4L ^
                 (((safe_mod_func_uint32_t_u_u(
                       ((g_98[3][3][5] >
                         ((safe_sub_func_int8_t_s_s(
                              ((l_84 !=
                                (safe_mod_func_uint64_t_u_u(l_166, g_119))) ||
                               ((((+(safe_add_func_uint8_t_u_u(
                                      (p_66 <= g_160[4]), g_98[2][5][1]))) !=
                                  l_165[1][1][1]) ||
                                 l_184) == 0x00L)),
                              g_160[4])) > l_184)) &&
                        l_164),
                       l_85)) &&
                   0UL) &
                  l_185)),
                l_184)),
            p_66)));
 }
 ((g_881 = (!(safe_lshift_func_int16_t_s_u(g_881, 8)))) < p_66);
      }
    }
    if ((g_93 > 2UL)) {
      int16_t l_219 = (-6L);
      int32_t l_232 = 0x12FE6111L;
      l_115 =
          (g_209 = (+(safe_add_func_uint16_t_u_u(
               (l_103 <= (safe_mul_func_uint16_t_u_u(0xCBD7L, (+65535UL)))),
               (safe_mod_func_uint64_t_u_u(
                   (safe_div_func_uint32_t_u_u(
                       (g_119 = (safe_div_func_int32_t_s_s(
                            (safe_mul_func_uint16_t_u_u(
                                (+g_108), (safe_mod_func_uint32_t_u_u(
                                              g_98[1][5][2], 0xC786B904L)))),
                            ((l_77[0] = (safe_div_func_int8_t_s_s(
                                  (safe_mul_func_int16_t_s_s(
                                      ((safe_add_func_int32_t_s_s(
                                           ((safe_add_func_uint8_t_u_u(
                                                (g_93 != p_63),
                                                (l_103 > 0x66L))) > 8L),
                                           7UL)) ||
                                       4294967289UL),
                                      g_80[7])),
                                  0x29L))) ||
                             l_84)))),
                       l_96[6][4])),
                   p_66))))));
      ((safe_mod_func_uint8_t_u_u(
           1UL, (g_7 = ((p_63 = 0x33L) &
                        (0x9386BB024709BCE2LL <
                         (safe_div_func_int32_t_s_s(g_209, (g_119++)))))))) ||
       g_792);
      if (((p_66 &
            (((safe_unary_minus_func_uint16_t_u((safe_rshift_func_uint16_t_u_u(
                  (safe_mul_func_int16_t_s_s(
                      ((((safe_mod_func_int32_t_s_s(
                             (safe_mul_func_uint16_t_u_u(
                                 l_219,
                                 (g_20 |
                                  ((p_67 |= (safe_add_func_int16_t_s_s(
                                        (-9L),
                                        (safe_mod_func_uint32_t_u_u(
                                            p_64,
                                            (safe_add_func_uint32_t_u_u(
                                                g_119,
                                                (safe_rshift_func_uint16_t_u_u(
                                                    (safe_mul_func_uint16_t_u_u(
                                                        p_65, (g_97 == l_219))),
                                                    1))))))))) < l_85)))),
                             3L)) &&
                         g_80[0]) < g_28) &
                       l_77[0]),
                      g_108)),
                  g_80[3])))) >= l_115) >= 1UL)) ||
           0x35L)) {
        int16_t l_233 = 0x52FCL;
        for (l_103 = 0; (l_103 != 24);
             l_103 = safe_add_func_int64_t_s_s(l_103, 6)) {
          uint16_t l_234 = 65534UL;
          --l_234;
          for (g_167 = 5; (g_167 >= 1); g_167 -= 1) {
            int i, j;
            return l_96[(g_167 + 1)][g_167];
          }
        }
      } else {
        int32_t l_239[6][7] = {
            {0x647370D0L, 0x647370D0L, 0x8E0B751DL, 0x647370D0L, 0x647370D0L,
             0x8E0B751DL, 0x647370D0L},
            {0x647370D0L, 0x647370D0L, 0x8E0B751DL, 0x647370D0L, 0x647370D0L,
             0x8E0B751DL, 0x647370D0L},
            {0x647370D0L, 0x647370D0L, 0x8E0B751DL, 0x647370D0L, 0x647370D0L,
             0x8E0B751DL, 0x647370D0L},
            {0x647370D0L, 0x647370D0L, 0x8E0B751DL, 0x647370D0L, 0x647370D0L,
             0x8E0B751DL, 0x647370D0L},
            {0x647370D0L, 0x647370D0L, 0x8E0B751DL, 0x647370D0L, 0x647370D0L,
             0x8E0B751DL, 0x647370D0L},
            {0x647370D0L, 0x647370D0L, 0x8E0B751DL, 0x647370D0L, 0x647370D0L,
             0x8E0B751DL, 0x647370D0L}};
        int i, j;
        for (g_119 = 0; (g_119 > 33);
             g_119 = safe_add_func_uint64_t_u_u(g_119, 6)) {
          l_239[1][5] = (g_209 &= g_80[4]);
          (safe_mod_func_int16_t_s_s(
              ((safe_mul_func_int16_t_s_s(
                   (0UL & 4294967295UL),
                   (safe_add_func_int32_t_s_s(
                       g_758,
                       ((g_289 = (g_287 = 1L)) |
                        ((8L >=
                          (g_209 = ((safe_sub_func_uint64_t_u_u(
                                        18446744073709551614UL, g_186)) <=
                                    (safe_mul_func_uint8_t_u_u(
                                        (g_711 !=
                                         ((safe_unary_minus_func_uint16_t_u(
                                              (+(safe_mul_func_int16_t_s_s(
                                                  (g_1157 >= g_28),
                                                  g_757[2]))))) > g_108)),
                                        0x92L))))) ^
                         p_63)))))) &&
               1UL),
              g_1157)) != g_209;
        }
        for (g_97 = 4; (g_97 >= 0); g_97 -= 1) {
          g_209 = 1L;
          (((safe_sub_func_int32_t_s_s(
                (((safe_mod_func_int16_t_s_s(
                      ((safe_mul_func_int16_t_s_s(
                           (0UL & 4294967295UL),
                           (safe_add_func_int32_t_s_s(
                               g_108,
                               ((g_289 = (g_287 = 1L)) |
                                ((8L >=
                                  (g_881 =
                                       ((safe_sub_func_uint64_t_u_u(
                                            18446744073709551614UL, g_186)) <=
                                        (safe_mul_func_uint8_t_u_u(
                                            (g_711 !=
                                             ((safe_unary_minus_func_uint16_t_u(
                                                  (+(safe_mul_func_int16_t_s_s(
                                                      (g_290 >= g_28),
                                                      g_757[2]))))) > g_108)),
                                            0x92L))))) ^
                                 p_63)))))) &&
                       1UL),
                      g_290)) != g_881) |
                 g_186),
                g_881)) != g_7) ||
           g_287) ^
              g_290;
        }
        l_232 = (l_239[1][5] | p_65);
        (safe_add_func_int64_t_s_s(
            (p_63 && (safe_rshift_func_int8_t_s_s(
                         (safe_lshift_func_int8_t_s_u(
                             (0x0B55FA67D18B5D94LL || g_209), 7)),
                         2))),
            p_63));
      }
      g_209 = p_67;
      safe_rshift_func_uint8_t_u_s(0x0BL, g_80[g_93]);
    } else {
      uint16_t l_247[3][8][6] = {{{1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L}},
                                 {{1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L}},
                                 {{1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L},
                                  {1UL, 0x40B6L, 1UL, 0x40B6L, 1UL, 0x40B6L}}};
      int32_t l_263 = 0x1228030AL;
      int i, j, k;
      for (g_28 = (-14); (g_28 <= 3); ++g_28) {
        for (g_119 = 0; g_119 < 1; g_119 += 1) {
          l_77[g_119] = 0L;
        }
        g_881 &= g_93;
      }
      safe_mod_func_int16_t_s_s(g_93, g_209);
      ++g_242;
      (((safe_mod_func_int16_t_s_s(
            ((safe_mul_func_int16_t_s_s(
                 (0UL & 4294967295UL),
                 (safe_add_func_int32_t_s_s(
                     g_683,
                     ((g_289 = (g_287 = 1L)) |
                      ((8L >= (g_7 = ((safe_sub_func_uint64_t_u_u(
                                          18446744073709551614UL, g_186)) <=
                                      (safe_mul_func_uint8_t_u_u(
                                          (g_711 !=
                                           ((safe_unary_minus_func_uint16_t_u(
                                                (+(safe_mul_func_int16_t_s_s(
                                                    (g_1257 >= g_28),
                                                    g_757[2]))))) > g_108)),
                                          0x92L))))) ^
                       p_63)))))) &&
             1UL),
            g_1257)) != g_209) |
       g_186);
      l_263 = (safe_sub_func_int8_t_s_s(
          p_64,
          (((!(l_247[2][6][3] <=
               (safe_mod_func_uint64_t_u_u(
                   ((safe_unary_minus_func_uint8_t_u(
                        (g_80[6] <
                         ((safe_rshift_func_uint16_t_u_s(
                              (safe_add_func_uint32_t_u_u(
                                  ((safe_add_func_int16_t_s_s(
                                       (+((l_77[0] =
                                               (((0xBDL ^ l_96[6][4]) &
                                                 (safe_lshift_func_uint8_t_u_u(
                                                     p_64, g_80[6]))) &
                                                ((safe_mod_func_int8_t_s_s(
                                                     l_84, 1L)) <= p_67))) ||
                                          g_242)),
                                       p_64)) < l_247[2][6][3]),
                                  (-1L))),
                              g_80[6])) &
                          0x44B8A7ECDA51E4EFLL)))) &
                    0xB8L),
                   6UL)))) &&
            0xAD46L) &&
           p_66)));
      (safe_mul_func_uint8_t_u_u(0UL, (g_97 = g_881)));
    }
  }
  for (p_64 = 0; (p_64 <= (-8)); p_64 = safe_sub_func_int64_t_s_s(p_64, 9)) {
    int32_t l_274[2][3];
    int i, j;
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 3; j++) {
        l_274[i][j] = 0L;
        p_64 = safe_sub_func_int64_t_s_s(p_64, 9);
        (safe_add_func_uint8_t_u_u((g_93 != p_63), (g_7 > 0x66L)));
      }
    }
    safe_sub_func_int8_t_s_s(
        g_818[5][5][1],
        (safe_lshift_func_uint16_t_u_u(
            (safe_add_func_int32_t_s_s(
                (safe_rshift_func_int16_t_s_u(
                    (safe_rshift_func_int8_t_s_s(0x07L, g_929)), g_904)),
                g_209)),
            g_209)));
    g_209 = (safe_lshift_func_uint16_t_u_s(
        ((safe_mul_func_int8_t_s_s(
             ((((safe_add_func_uint32_t_u_u((g_98[1][1][0]++), l_274[0][1])) ||
                (((((safe_rshift_func_int16_t_s_u(
                        (safe_div_func_uint8_t_u_u(
                            (safe_mul_func_int16_t_s_s(
                                (l_103 == p_67),
                                ((((-9L) ||
                                   (g_160[4] ==
                                    (safe_add_func_int32_t_s_s(
                                        ((p_65 >=
                                          (safe_sub_func_int64_t_s_s(
                                              (l_70[0] |
                                               (g_98[3][3][5] ==
                                                (((~l_70[0]) < 0L) < p_67))),
                                              p_64))) ||
                                         g_80[6]),
                                        l_274[0][1])))) != p_63) >= g_119))),
                            g_98[0][0][4])),
                        13)) ^
                    0xEECEFAA5L) &&
                   l_274[1][2]) > 0x68031B64L) <= g_80[6])) != 8L) |
              246UL),
             g_119)) != (-1L)),
        2));
    (g_160[g_108] && (g_287 = ((g_7 = ((3UL && (g_289 > 4294967290UL)) &
                                       (g_80[g_881] < g_93))) != 0xA3C1983CL)));
    for (l_185 = 0; (l_185 >= 47); l_185++) {
      g_209 = (-2L);
      g_7 = (safe_sub_func_uint64_t_u_u(g_209, 0xD1990C90AB741CE7LL));
    }
    +((safe_add_func_int8_t_s_s(
          ((safe_rshift_func_uint16_t_u_s(0xCA25L, g_20)) | g_683), p_64)) ==
      0x80366E52324067BCLL);
    --g_290;
    safe_lshift_func_int16_t_s_s(((g_758 != g_758) >= p_63), 4);
  }
  (safe_lshift_func_int16_t_s_s(g_7, 14));
  if ((safe_mod_func_uint64_t_u_u(
          (g_288 ||
           ((safe_mul_func_uint8_t_u_u(
                ((safe_mul_func_uint8_t_u_u(0UL, (g_97 = l_103))) >=
                 (safe_mul_func_uint16_t_u_u(
                     (safe_unary_minus_func_uint32_t_u(p_63)),
                     ((safe_lshift_func_uint8_t_u_u(
                          (safe_add_func_uint8_t_u_u(
                              l_70[0],
                              (safe_add_func_uint8_t_u_u(
                                  (p_66 |
                                   ((l_70[0] ^ ((g_93 = 0xF2L) !=
                                                ((((safe_rshift_func_int8_t_s_u(
                                                       0x34L, 5)) ^
                                                   0xE7C7L) &
                                                  p_65) <= (-1L)))) |
                                    0x6841L)),
                                  p_67)))),
                          p_66)) ^
                      g_98[3][3][5])))),
                l_77[0])) > 1UL)),
          p_65))) {
    l_70[1] = (-1L);
  } else {
    return p_65;
  }
  (safe_div_func_int8_t_s_s(((g_290 || g_881) && g_881),
                            ((g_119 ^= (g_80[5] ^ 6L)) ^ g_80[1])));
  return p_64;
}
int main(int argc, char *argv[]) {
  int i, j, k;
  int print_hash_value = 0;
  if (argc == 2 && strcmp(argv[1], "1") == 0)
    print_hash_value = 1;
  crc32_gentab();
  func_1();
  transparent_crc(g_6, "g_6", print_hash_value);
  transparent_crc(g_7, "g_7", print_hash_value);
  transparent_crc(g_20, "g_20", print_hash_value);
  transparent_crc(g_28, "g_28", print_hash_value);
  transparent_crc(g_33, "g_33", print_hash_value);
  for (i = 0; i < 8; i++) {
    transparent_crc(g_80[i], "g_80[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_93, "g_93", print_hash_value);
  transparent_crc(g_97, "g_97", print_hash_value);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 6; j++) {
      for (k = 0; k < 6; k++) {
        transparent_crc(g_98[i][j][k], "g_98[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_108, "g_108", print_hash_value);
  transparent_crc(g_119, "g_119", print_hash_value);
  for (i = 0; i < 5; i++) {
    transparent_crc(g_160[i], "g_160[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_167, "g_167", print_hash_value);
  transparent_crc(g_186, "g_186", print_hash_value);
  transparent_crc(g_209, "g_209", print_hash_value);
  transparent_crc(g_242, "g_242", print_hash_value);
  transparent_crc(g_287, "g_287", print_hash_value);
  transparent_crc(g_288, "g_288", print_hash_value);
  transparent_crc(g_289, "g_289", print_hash_value);
  transparent_crc(g_290, "g_290", print_hash_value);
  transparent_crc(g_522, "g_522", print_hash_value);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 9; j++) {
      for (k = 0; k < 4; k++) {
        transparent_crc(g_570[i][j][k], "g_570[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_683, "g_683", print_hash_value);
  transparent_crc(g_711, "g_711", print_hash_value);
  for (i = 0; i < 3; i++) {
    transparent_crc(g_757[i], "g_757[i]", print_hash_value);
    if (print_hash_value)
      printf("index = [%d]\n", i);
  }
  transparent_crc(g_758, "g_758", print_hash_value);
  transparent_crc(g_790, "g_790", print_hash_value);
  transparent_crc(g_792, "g_792", print_hash_value);
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 6; j++) {
      for (k = 0; k < 2; k++) {
        transparent_crc(g_818[i][j][k], "g_818[i][j][k]", print_hash_value);
        if (print_hash_value)
          printf("index = [%d][%d][%d]\n", i, j, k);
      }
    }
  }
  transparent_crc(g_881, "g_881", print_hash_value);
  transparent_crc(g_904, "g_904", print_hash_value);
  transparent_crc(g_929, "g_929", print_hash_value);
  transparent_crc(g_930, "g_930", print_hash_value);
  transparent_crc(g_1066, "g_1066", print_hash_value);
  transparent_crc(g_1072, "g_1072", print_hash_value);
  transparent_crc(g_1100, "g_1100", print_hash_value);
  transparent_crc(g_1157, "g_1157", print_hash_value);
  transparent_crc(g_1158, "g_1158", print_hash_value);
  transparent_crc(g_1257, "g_1257", print_hash_value);
  transparent_crc(g_1348, "g_1348", print_hash_value);
  transparent_crc(g_1349, "g_1349", print_hash_value);
  platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
  return 0;
}

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef unsigned uint32_t;
typedef unsigned uint64_t;
void platform_main_end(uint32_t crc, int flag) {
  printf("checksum = %X\n", crc);
}
uint32_t crc32_context;
void crc32_byte(b) { crc32_context = b; }
void crc32_8bytes(val) { crc32_byte(val); }
void transparent_crc(uint64_t val, char *vname, int flag) { crc32_8bytes(val); }
int32_t g_573;
int8_t g_4689;
int8_t func_1() {
  int16_t l_5913;
  int i;
  int32_t BGCGCl_6280 = g_573;
  l_5913 = BGCGCl_6280;
  int32_t l_6726 = 1L;
  for (i = 0; i < 10; i++)
    while (l_5913 > l_6726)
      l_5913 -= 1;
  if (g_4689 = l_5913)
    ;
}
int main() {
  int print_hash_value = 0;
  func_1();
  transparent_crc(g_4689, "g_4689", print_hash_value);
  platform_main_end(crc32_context, print_hash_value);
  return 0;
}

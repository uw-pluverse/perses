typedef short int16_t;
typedef int int32_t;
typedef unsigned uint16_t;
typedef unsigned uint32_t;
uint32_t safe_add_func_uint32_t_u_u(uint32_t ui1, uint32_t ui2) {
  return ui1 + ui2;
}
uint32_t safe_sub_func_uint32_t_u_u(uint32_t ui1, uint32_t ui2) {
  return ui1 - ui2;
}
uint16_t g_538;
uint16_t func_8(int16_t);
int32_t func_1() {
  if (func_8(1))
    return g_538;
}
uint16_t func_8(int16_t p_9) {
  int32_t l_1179;
  int16_t l_1271 = 0x809CL;
  uint32_t l_1288;
  for (l_1288 = 0; l_1288 <= 49;
       l_1288 = safe_add_func_uint32_t_u_u(l_1288, 8)) {
    uint32_t l_1423 = 0xE576516EL;
    if (g_538)
      printf("l_1179=%lld\n", (long long)l_1179);
    p_9 = safe_sub_func_uint32_t_u_u(0x60781BCDL >= l_1271 ^ 4294967287UL,
                                     l_1423);
  }
  return p_9;
}
int main() { func_1(); }

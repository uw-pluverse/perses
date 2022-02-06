typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef unsigned char uint8_t;
typedef unsigned uint16_t;
typedef unsigned uint32_t;
uint8_t safe_lshift_func_uint8_t_u_s(uint8_t left, int right) {
  return left > right ? left : left << right;
}
struct S0 {
  int8_t f0;
  int8_t f1;
  int32_t f3;
};
uint32_t g_81[4];
struct S0 g_152[2];
uint16_t g_203[3];
struct S0 func_129(int32_t, struct S0, uint32_t, int16_t);
uint8_t func_99(p_100) {
  uint8_t l_110[7][7];
  int32_t l_142;
  struct S0 l_147;
  uint32_t l_148;
  if (func_129(l_142, l_147, l_148, l_110[0][0]), p_100)
    ;
  return p_100;
}
struct S0 func_129(int32_t p_130, struct S0 p_131, uint32_t p_132,
                   int16_t p_133) {
  struct S0 l_151 = {0x15L, -5L};
  int32_t l_195;
  int32_t l_164;
  if (p_133 ^ l_151.f1)
    ;
  else
    l_151 = g_152[1];
  for (; l_195; l_195 += 1)
    for (p_132 = 0; p_132 <= 39; ++p_132)
      for (p_131.f0 = 0; p_131.f0 <= 2; p_131.f0 += 1) {
        g_152[0] = l_151;
        l_151.f3 = g_81[p_131.f0];
        if (!g_152[0].f0)
          ;
        else {
          l_195 = safe_lshift_func_uint8_t_u_s(g_152[0].f3, 2) && p_131.f1;
          for (; l_164; l_164 += 1)
            g_203[2]++;
        }
      }
  return p_131;
}
int main() {}

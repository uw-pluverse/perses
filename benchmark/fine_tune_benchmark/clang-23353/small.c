typedef char int8_t;
typedef int int32_t;
typedef unsigned uint8_t;
int8_t safe_mul_func_int8_t_s_s(int8_t si1, int8_t si2) { return si1 * si2; }
struct S1 {
  signed f0;
};
int32_t g_62;
struct S1 g_80;
int32_t *func_49(uint8_t p_50, int32_t *p_51, int8_t p_52) {
  for (p_52 = 6; p_52 != -7; p_52--)
    g_80.f0 ^= safe_mul_func_int8_t_s_s(p_52, g_62) && 1L;
  return p_51;
}
int main() { return 0; }

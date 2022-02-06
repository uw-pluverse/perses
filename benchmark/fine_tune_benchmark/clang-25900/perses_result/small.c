typedef signed int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int64_t;
typedef unsigned uint8_t;
typedef unsigned uint16_t;
typedef unsigned uint32_t;
uint8_t safe_rshift_func_uint8_t_u_s(uint8_t left, int right) { return right; }
struct S0 {
  uint16_t f0;
};
struct S1 {
  signed f4 : 18;
  signed f5 : 1;
};
int8_t g_12;
struct S0 g_21;
int32_t g_37;
static int8_t g_66 = -5L;
uint32_t g_80;
int32_t g_377;
uint32_t g_968;
int8_t func_14(int8_t, struct S1, struct S0, struct S0, int32_t);
int16_t func_44(uint32_t);
int64_t func_1() {
  struct S1 l_20;
  func_14(g_12, l_20, g_21, g_21, g_21.f0);
}
int8_t func_14(int8_t p_15, struct S1 p_16, struct S0 p_17, struct S0 p_18,
               int32_t p_19) {
  func_44(p_19);
}
int16_t func_44(uint32_t p_45) {
  struct S1 l_59 = {1957};
  l_59.f5 = safe_rshift_func_uint8_t_u_s(g_968, 5);
  int8_t backup_0_8502_91289_l_59_f5;
  int32_t backup_2_8502_22363_g_183 = g_80;
  backup_0_8502_91289_l_59_f5 = l_59.f5;
  l_59.f5 = g_377;
  g_37 = backup_2_8502_22363_g_183 % (~g_66 / backup_0_8502_91289_l_59_f5);
  l_59.f5;
}
int main() { func_1(); }

typedef int int32_t;
typedef char uint8_t;
struct S0 {
  int32_t f4;
  int32_t f6;
};
struct S0 g_20;
uint8_t func_65() {
  int32_t l_71 = 6L;
  if (g_20.f6)
    goto lbl_93;
  func_65();
  uint8_t l_1454;
  return l_1454;
lbl_93:
  g_20.f4 = l_71;
  func_65();
  l_1454 = 0xEEACFBBFL;
  return l_1454;
}
int main() {}

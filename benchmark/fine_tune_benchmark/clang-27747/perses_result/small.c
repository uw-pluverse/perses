typedef signed int8_t;
typedef int int32_t;
struct S0 {
  signed f2 : 18;
  unsigned f3;
  unsigned f4;
  signed f5;
  signed f6;
};
struct S0 g_27;
struct S0 g_210;
int32_t func_2() {
  struct S0 l_2818 = {24, 6738, 165};
  int32_t BHbHbdl_2818_f2 = g_210.f3;
  l_2818.f2 = BHbHbdl_2818_f2;
  int32_t Brcrcl_2818_f2 = g_210.f6 && l_2818.f2;
  int32_t Brcrcbl_2818_f6 = l_2818.f2;
  int8_t Brcrccg_27_f5 =
      Brcrcbl_2818_f6 | -(l_2818.f4 && l_2818.f2) - Brcrcl_2818_f2;
  g_27.f5 = Brcrccg_27_f5;
}
int main() {}

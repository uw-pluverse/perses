void test1() {
  extern volatile int f11G, a, b;
  f11G = a + b;
  f11G = a - b;
  f11G = a * b;
  f11G = -a;
  ++a;
  --a;
  extern int* P;
  ++P;
  extern volatile signed char PR9350_char_inc;
  ++PR9350_char_inc;
  extern volatile signed char PR9350_char_dec;
  --PR9350_char_dec;
  extern volatile signed short PR9350_short_inc;
  ++PR9350_short_inc;
  extern volatile signed short PR9350_short_dec;
  --PR9350_short_dec;
  __builtin_frame_address(0 + 0);
}

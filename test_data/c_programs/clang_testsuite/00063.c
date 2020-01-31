void clang_analyzer_eval(int);
void smallAdjustmentGT (unsigned a) {
  if (a+2 > 1)
    clang_analyzer_eval(a < (~0U)-1);
  else
    clang_analyzer_eval(a == (~0U)-1 || a == (~0U));
}
void smallAdjustmentGE (unsigned a) {
  if (a+2 >= 1)
    clang_analyzer_eval(a < (~0U)-1 || a == (~0U));
  else
    clang_analyzer_eval(a == (~0U)-1);
}
void smallAdjustmentLT (unsigned a) {
  if (a+1 < 2)
    clang_analyzer_eval(a == 0 || a == (~0U));
}
void smallAdjustmentLE (unsigned a) {
  if (a+1 <= 2)
    clang_analyzer_eval(a == 0 || a == 1 || a == (~0U));
}
void largeAdjustmentGT (unsigned a) {
  if (a-2 > (~0U)-1)
    clang_analyzer_eval(a == 1);
  else
    clang_analyzer_eval(a != 1);
}
void largeAdjustmentGE (unsigned a) {
  if (a-2 >= (~0U)-1)
    clang_analyzer_eval(a == 1 || a == 0);
  else
    clang_analyzer_eval(a > 1);
}
void largeAdjustmentLT (unsigned a) {
  if (a+2 < 1)
    clang_analyzer_eval(a == (~0U)-1);
  else
    clang_analyzer_eval(a != (~0U)-1);
}
void largeAdjustmentLE (unsigned a) {
  if (a+2 <= 1)
    clang_analyzer_eval(a == (~0U)-1 || a == (~0U));
  else
    clang_analyzer_eval(a < (~0U)-1);
}
void mixedComparisons1(signed char a) {
  int min = (-((~0U) & ((~0U) >> 1)) - 1);
  clang_analyzer_eval((a - 2) >= (min + 5LL));
  clang_analyzer_eval(a == 0);
  clang_analyzer_eval(a == 0x7F);
  clang_analyzer_eval(a == -0x80);
}
void mixedComparisons2(signed char a) {
  clang_analyzer_eval((a - 5) < (-0x81LL));
  if ((a - 5) < (-0x81LL)) {
    clang_analyzer_eval(a == 0);
    clang_analyzer_eval(a == 0x7F);
    clang_analyzer_eval(a == -0x80);
  }
}
void mixedComparisons3(signed char a) {
  clang_analyzer_eval((a - 0x200) < -0x100LL);
  clang_analyzer_eval(a == 0);
  clang_analyzer_eval(a == 0x7F);
  clang_analyzer_eval(a == -0x80);
}
void mixedComparisons4(signed char a) {
  clang_analyzer_eval((a - 5) > 0LL);
  if ((a - 5) > 0LL) {
    clang_analyzer_eval(a == 0);
    clang_analyzer_eval(a == 0x7F);
    clang_analyzer_eval(a == -0x80);
  }
}
void mixedComparisons5(signed char a) {
  clang_analyzer_eval((a + 5) == 0LL);
  if ((a + 5) == 0LL) {
    clang_analyzer_eval(a == 0);
    clang_analyzer_eval(a == 0x7F);
    clang_analyzer_eval(a == -0x80);
  } else {
    clang_analyzer_eval(a == 0);
    clang_analyzer_eval(a == 0x7F);
    clang_analyzer_eval(a == -0x80);
  }
}
void mixedComparisons6(signed char a) {
  clang_analyzer_eval((a + 5) > 0x81LL);
  if ((a + 5) > 0x81LL) {
    clang_analyzer_eval(a == 0);
    clang_analyzer_eval(a == 0x7F);
    clang_analyzer_eval(a == -0x80);
  }
}
void mixedComparisons7(signed char a) {
  int min = (-((~0U) & ((~0U) >> 1)) - 1);
  clang_analyzer_eval((a + 2) >= (min + 5LL));
  clang_analyzer_eval(a == 0);
  clang_analyzer_eval(a == 0x7F);
  clang_analyzer_eval(a == -0x80);
}
void mixedComparisons8(signed char a) {
  clang_analyzer_eval((a + 5) < 0LL);
  if ((a + 5) < 0LL) {
    clang_analyzer_eval(a == 0);
    clang_analyzer_eval(a == 0x7F);
    clang_analyzer_eval(a == -0x80);
  }
}
void mixedComparisons9(signed char a) {
  int max = ((~0U) & ((~0U) >> 1));
  clang_analyzer_eval((a + 2) <= (max - 5LL));
  clang_analyzer_eval(a == 0);
  clang_analyzer_eval(a == 0x7F);
  clang_analyzer_eval(a == -0x80);
}
void mixedSignedness1(int a) {
  unsigned max = (~0U);
  clang_analyzer_eval(a < max);
  clang_analyzer_eval((a + 2) < max);
  clang_analyzer_eval((a + 2U) < max);
}
void mixedSignedness2(int a) {
  unsigned max = (~0U);
  clang_analyzer_eval(a <= max);
  clang_analyzer_eval((a + 2) <= max);
  clang_analyzer_eval((a + 2U) <= max);
}
void mixedSignedness3(unsigned a) {
  int max = ((~0U) & ((~0U) >> 1));
  clang_analyzer_eval(a < max);
  clang_analyzer_eval((a + 2) < max);
  clang_analyzer_eval((a + 2U) < max);
}
void mixedSignedness4(unsigned a) {
  int max = ((~0U) & ((~0U) >> 1));
  clang_analyzer_eval(a <= max);
  clang_analyzer_eval((a + 2) <= max);
  clang_analyzer_eval((a + 2U) <= max);
}
void mixedSignedness5(unsigned a) {
  int min = (-((~0U) & ((~0U) >> 1)) - 1);
  clang_analyzer_eval(a < min);
  clang_analyzer_eval((a + 2) < min);
  clang_analyzer_eval((a + 2U) < min);
}
void mixedSignedness6(unsigned a) {
  int min = (-((~0U) & ((~0U) >> 1)) - 1);
  clang_analyzer_eval(a <= min);
  clang_analyzer_eval((a + 2) <= min);
  clang_analyzer_eval((a + 2U) <= min);
}
void mixedSignedness7(unsigned a) {
  unsigned min = 0;
  clang_analyzer_eval(a < min);
  clang_analyzer_eval((a + 2) < min);
  clang_analyzer_eval((a + 2U) < min);
}
void mixedSignedness8(unsigned a) {
  unsigned min = 0;
  clang_analyzer_eval(a <= min);
  clang_analyzer_eval((a + 2) <= min);
  clang_analyzer_eval((a + 2U) <= min);
}
void mixedSignedness9(unsigned a) {
  int min = 0;
  clang_analyzer_eval(a < min);
  clang_analyzer_eval((a + 2) < min);
  clang_analyzer_eval((a + 2U) < min);
}
void mixedSignedness10(unsigned a) {
  int min = 0;
  clang_analyzer_eval(a <= min);
  clang_analyzer_eval((a + 2) <= min);
  clang_analyzer_eval((a + 2U) <= min);
}
void mixedSignedness11(int a) {
  int min = 0;
  clang_analyzer_eval(a < min);
  clang_analyzer_eval((a + 2) < min);
  clang_analyzer_eval((a + 2U) < min);
}
void mixedSignedness12(int a) {
  int min = 0;
  clang_analyzer_eval(a <= min);
  clang_analyzer_eval((a + 2) <= min);
  clang_analyzer_eval((a + 2U) <= min);
}
void mixedSignedness13(int a) {
  unsigned max = ((~0U) & ((~0U) >> 1));
  clang_analyzer_eval(a < max);
  clang_analyzer_eval((a + 2) < max);
  clang_analyzer_eval((a + 2U) < max);
}
void mixedSignedness14(int a) {
  unsigned max = ((~0U) & ((~0U) >> 1));
  clang_analyzer_eval(a <= max);
  clang_analyzer_eval((a + 2) <= max);
  clang_analyzer_eval((a + 2U) <= max);
}
void mixedSignedness15(int a) {
  unsigned min = (-((~0U) & ((~0U) >> 1)) - 1);
  clang_analyzer_eval(a < min);
  clang_analyzer_eval((a + 2) < min);
  clang_analyzer_eval((a + 2U) < min);
}
void mixedSignedness16(int a) {
  unsigned min = (-((~0U) & ((~0U) >> 1)) - 1);
  clang_analyzer_eval(a <= min);
  clang_analyzer_eval((a + 2) <= min);
  clang_analyzer_eval((a + 2U) <= min);
}
void mixedSignedness17(int a) {
  unsigned max = ((~0U) & ((~0U) >> 1));
  if (a < max)
    return;
  clang_analyzer_eval(a < 0);
  clang_analyzer_eval(a == 0);
  clang_analyzer_eval(a == ((~0U) & ((~0U) >> 1)));
}
void mixedSignedness18(int a) {
  if (a >= 0)
    return;
  clang_analyzer_eval(a < 0);
  clang_analyzer_eval(a == (unsigned)(-((~0U) & ((~0U) >> 1)) - 1));
  clang_analyzer_eval(a == (~0U));
}

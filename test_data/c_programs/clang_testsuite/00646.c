typedef __attribute__((__ext_vector_type__(16))) signed char int8x16_t;
typedef __attribute__((__ext_vector_type__(3))) float float32x3_t;
typedef struct { float32x3_t arr[4]; } HFAv3;
typedef struct { float32x3_t arr[3]; int8x16_t b; } MixedHFAv3;
HFAv3 test(HFAv3 a0, HFAv3 a1, HFAv3 a2) {
  return a2;
}
MixedHFAv3 test_mixed(MixedHFAv3 a0, MixedHFAv3 a1, MixedHFAv3 a2) {
  return a2;
}

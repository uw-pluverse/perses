







extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));






volatile __fp16 h0 = 0.0;
volatile __fp16 h1 = 1.0;
volatile __fp16 h42 = 42.0;
volatile __fp16 hm2 = -2.0;
volatile __fp16 temp;

volatile float f0 = 0.0;
volatile float f1 = 1.0;
volatile float f42 = 42.0;
volatile float fm2 = -2.0;

int main (void)
{
  ((h1) ? (void) (0) : __assert_fail ("h1", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 23, __PRETTY_FUNCTION__));
  ((!(h0)) ? (void) (0) : __assert_fail ("!(h0)", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 24, __PRETTY_FUNCTION__));
  ((!h0) ? (void) (0) : __assert_fail ("!h0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 25, __PRETTY_FUNCTION__));
  ((!(!h1)) ? (void) (0) : __assert_fail ("!(!h1)", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 26, __PRETTY_FUNCTION__));

  ((((-h1) == -1.0) ? (void) (0) : __assert_fail ("(-h1) == -1.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 28, __PRETTY_FUNCTION__)), temp = (-h1), ((temp == -1.0) ? (void) (0) : __assert_fail ("temp == -1.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 28, __PRETTY_FUNCTION__)));
  ((((+h1) == 1.0) ? (void) (0) : __assert_fail ("(+h1) == 1.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 29, __PRETTY_FUNCTION__)), temp = (+h1), ((temp == 1.0) ? (void) (0) : __assert_fail ("temp == 1.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 29, __PRETTY_FUNCTION__)));

  (((h1++) == 1.0) ? (void) (0) : __assert_fail ("(h1++) == 1.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 31, __PRETTY_FUNCTION__));
  (((h1) == 2.0) ? (void) (0) : __assert_fail ("(h1) == 2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 32, __PRETTY_FUNCTION__));
  (((++h1) == 3.0) ? (void) (0) : __assert_fail ("(++h1) == 3.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 33, __PRETTY_FUNCTION__));
  (((h1) == 3.0) ? (void) (0) : __assert_fail ("(h1) == 3.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 34, __PRETTY_FUNCTION__));

  (((--h1) == 2.0) ? (void) (0) : __assert_fail ("(--h1) == 2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 36, __PRETTY_FUNCTION__));
  (((h1) == 2.0) ? (void) (0) : __assert_fail ("(h1) == 2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 37, __PRETTY_FUNCTION__));
  (((h1--) == 2.0) ? (void) (0) : __assert_fail ("(h1--) == 2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 38, __PRETTY_FUNCTION__));
  (((h1) == 1.0) ? (void) (0) : __assert_fail ("(h1) == 1.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 39, __PRETTY_FUNCTION__));

  ((((h42 * hm2) == -84.0) ? (void) (0) : __assert_fail ("(h42 * hm2) == -84.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 41, __PRETTY_FUNCTION__)), temp = (h42 * hm2), ((temp == -84.0) ? (void) (0) : __assert_fail ("temp == -84.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 41, __PRETTY_FUNCTION__)));
  ((((h42 * (__fp16) -2.0) == -84.0) ? (void) (0) : __assert_fail ("(h42 * (__fp16) -2.0) == -84.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 42, __PRETTY_FUNCTION__)), temp = (h42 * (__fp16) -2.0), ((temp == -84.0) ? (void) (0) : __assert_fail ("temp == -84.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 42, __PRETTY_FUNCTION__)));
  ((((h42 * fm2) == -84.0) ? (void) (0) : __assert_fail ("(h42 * fm2) == -84.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 43, __PRETTY_FUNCTION__)), temp = (h42 * fm2), ((temp == -84.0) ? (void) (0) : __assert_fail ("temp == -84.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 43, __PRETTY_FUNCTION__)));
  ((((f42 * hm2) == -84.0) ? (void) (0) : __assert_fail ("(f42 * hm2) == -84.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 44, __PRETTY_FUNCTION__)), temp = (f42 * hm2), ((temp == -84.0) ? (void) (0) : __assert_fail ("temp == -84.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 44, __PRETTY_FUNCTION__)));

  ((((h42 / hm2) == -21.0) ? (void) (0) : __assert_fail ("(h42 / hm2) == -21.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 46, __PRETTY_FUNCTION__)), temp = (h42 / hm2), ((temp == -21.0) ? (void) (0) : __assert_fail ("temp == -21.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 46, __PRETTY_FUNCTION__)));
  ((((h42 / (__fp16) -2.0) == -21.0) ? (void) (0) : __assert_fail ("(h42 / (__fp16) -2.0) == -21.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 47, __PRETTY_FUNCTION__)), temp = (h42 / (__fp16) -2.0), ((temp == -21.0) ? (void) (0) : __assert_fail ("temp == -21.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 47, __PRETTY_FUNCTION__)));
  ((((h42 / fm2) == -21.0) ? (void) (0) : __assert_fail ("(h42 / fm2) == -21.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 48, __PRETTY_FUNCTION__)), temp = (h42 / fm2), ((temp == -21.0) ? (void) (0) : __assert_fail ("temp == -21.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 48, __PRETTY_FUNCTION__)));
  ((((f42 / hm2) == -21.0) ? (void) (0) : __assert_fail ("(f42 / hm2) == -21.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 49, __PRETTY_FUNCTION__)), temp = (f42 / hm2), ((temp == -21.0) ? (void) (0) : __assert_fail ("temp == -21.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 49, __PRETTY_FUNCTION__)));

  ((((hm2 + h42) == 40.0) ? (void) (0) : __assert_fail ("(hm2 + h42) == 40.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 51, __PRETTY_FUNCTION__)), temp = (hm2 + h42), ((temp == 40.0) ? (void) (0) : __assert_fail ("temp == 40.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 51, __PRETTY_FUNCTION__)));
  (((((__fp16)-2.0 + h42) == 40.0) ? (void) (0) : __assert_fail ("((__fp16)-2.0 + h42) == 40.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 52, __PRETTY_FUNCTION__)), temp = ((__fp16)-2.0 + h42), ((temp == 40.0) ? (void) (0) : __assert_fail ("temp == 40.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 52, __PRETTY_FUNCTION__)));
  ((((hm2 + f42) == 40.0) ? (void) (0) : __assert_fail ("(hm2 + f42) == 40.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 53, __PRETTY_FUNCTION__)), temp = (hm2 + f42), ((temp == 40.0) ? (void) (0) : __assert_fail ("temp == 40.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 53, __PRETTY_FUNCTION__)));
  ((((fm2 + h42) == 40.0) ? (void) (0) : __assert_fail ("(fm2 + h42) == 40.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 54, __PRETTY_FUNCTION__)), temp = (fm2 + h42), ((temp == 40.0) ? (void) (0) : __assert_fail ("temp == 40.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 54, __PRETTY_FUNCTION__)));

  ((((hm2 - h42) == -44.0) ? (void) (0) : __assert_fail ("(hm2 - h42) == -44.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 56, __PRETTY_FUNCTION__)), temp = (hm2 - h42), ((temp == -44.0) ? (void) (0) : __assert_fail ("temp == -44.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 56, __PRETTY_FUNCTION__)));
  (((((__fp16)-2.0 - h42) == -44.0) ? (void) (0) : __assert_fail ("((__fp16)-2.0 - h42) == -44.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 57, __PRETTY_FUNCTION__)), temp = ((__fp16)-2.0 - h42), ((temp == -44.0) ? (void) (0) : __assert_fail ("temp == -44.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 57, __PRETTY_FUNCTION__)));
  ((((hm2 - f42) == -44.0) ? (void) (0) : __assert_fail ("(hm2 - f42) == -44.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 58, __PRETTY_FUNCTION__)), temp = (hm2 - f42), ((temp == -44.0) ? (void) (0) : __assert_fail ("temp == -44.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 58, __PRETTY_FUNCTION__)));
  ((((fm2 - h42) == -44.0) ? (void) (0) : __assert_fail ("(fm2 - h42) == -44.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 59, __PRETTY_FUNCTION__)), temp = (fm2 - h42), ((temp == -44.0) ? (void) (0) : __assert_fail ("temp == -44.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 59, __PRETTY_FUNCTION__)));

  ((hm2 < h42) ? (void) (0) : __assert_fail ("hm2 < h42", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 61, __PRETTY_FUNCTION__));
  ((hm2 < (__fp16)42.0) ? (void) (0) : __assert_fail ("hm2 < (__fp16)42.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 62, __PRETTY_FUNCTION__));
  ((hm2 < f42) ? (void) (0) : __assert_fail ("hm2 < f42", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 63, __PRETTY_FUNCTION__));
  ((fm2 < h42) ? (void) (0) : __assert_fail ("fm2 < h42", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 64, __PRETTY_FUNCTION__));

  ((h42 > hm2) ? (void) (0) : __assert_fail ("h42 > hm2", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 66, __PRETTY_FUNCTION__));
  (((__fp16)42.0 > hm2) ? (void) (0) : __assert_fail ("(__fp16)42.0 > hm2", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 67, __PRETTY_FUNCTION__));
  ((h42 > fm2) ? (void) (0) : __assert_fail ("h42 > fm2", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 68, __PRETTY_FUNCTION__));
  ((f42 > hm2) ? (void) (0) : __assert_fail ("f42 > hm2", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 69, __PRETTY_FUNCTION__));

  ((hm2 <= h42) ? (void) (0) : __assert_fail ("hm2 <= h42", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 71, __PRETTY_FUNCTION__));
  ((hm2 <= (__fp16)42.0) ? (void) (0) : __assert_fail ("hm2 <= (__fp16)42.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 72, __PRETTY_FUNCTION__));
  ((hm2 <= f42) ? (void) (0) : __assert_fail ("hm2 <= f42", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 73, __PRETTY_FUNCTION__));
  ((fm2 <= h42) ? (void) (0) : __assert_fail ("fm2 <= h42", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 74, __PRETTY_FUNCTION__));

  ((h42 >= hm2) ? (void) (0) : __assert_fail ("h42 >= hm2", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 76, __PRETTY_FUNCTION__));
  ((h42 >= (__fp16)-2.0) ? (void) (0) : __assert_fail ("h42 >= (__fp16)-2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 77, __PRETTY_FUNCTION__));
  ((h42 >= fm2) ? (void) (0) : __assert_fail ("h42 >= fm2", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 78, __PRETTY_FUNCTION__));
  ((f42 >= hm2) ? (void) (0) : __assert_fail ("f42 >= hm2", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 79, __PRETTY_FUNCTION__));

  ((!(h1 == hm2)) ? (void) (0) : __assert_fail ("!(h1 == hm2)", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 81, __PRETTY_FUNCTION__));
  ((h1 == h1) ? (void) (0) : __assert_fail ("h1 == h1", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 82, __PRETTY_FUNCTION__));
  ((h1 == (__fp16)1.0) ? (void) (0) : __assert_fail ("h1 == (__fp16)1.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 83, __PRETTY_FUNCTION__));
  ((h1 == f1) ? (void) (0) : __assert_fail ("h1 == f1", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 84, __PRETTY_FUNCTION__));
  ((f1 == h1) ? (void) (0) : __assert_fail ("f1 == h1", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 85, __PRETTY_FUNCTION__));

  ((h1 != hm2) ? (void) (0) : __assert_fail ("h1 != hm2", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 87, __PRETTY_FUNCTION__));
  ((!(h1 != h1)) ? (void) (0) : __assert_fail ("!(h1 != h1)", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 88, __PRETTY_FUNCTION__));
  ((!(h1 != (__fp16)1.0)) ? (void) (0) : __assert_fail ("!(h1 != (__fp16)1.0)", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 89, __PRETTY_FUNCTION__));
  ((!(h1 != f1)) ? (void) (0) : __assert_fail ("!(h1 != f1)", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 90, __PRETTY_FUNCTION__));
  ((!(f1 != h1)) ? (void) (0) : __assert_fail ("!(f1 != h1)", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 91, __PRETTY_FUNCTION__));

  (((((h1 ? hm2 : h42)) == -2.0) ? (void) (0) : __assert_fail ("((h1 ? hm2 : h42)) == -2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 93, __PRETTY_FUNCTION__)), temp = ((h1 ? hm2 : h42)), ((temp == -2.0) ? (void) (0) : __assert_fail ("temp == -2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 93, __PRETTY_FUNCTION__)));
  (((((h0 ? hm2 : h42)) == 42.0) ? (void) (0) : __assert_fail ("((h0 ? hm2 : h42)) == 42.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 94, __PRETTY_FUNCTION__)), temp = ((h0 ? hm2 : h42)), ((temp == 42.0) ? (void) (0) : __assert_fail ("temp == 42.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 94, __PRETTY_FUNCTION__)));

  (((h0 = h42) == 42.0) ? (void) (0) : __assert_fail ("(h0 = h42) == 42.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 96, __PRETTY_FUNCTION__));
  (((h0) == 42.0) ? (void) (0) : __assert_fail ("(h0) == 42.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 97, __PRETTY_FUNCTION__));
  (((h0 = (__fp16)-2.0) == -2.0) ? (void) (0) : __assert_fail ("(h0 = (__fp16)-2.0) == -2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 98, __PRETTY_FUNCTION__));
  (((h0) == -2.0) ? (void) (0) : __assert_fail ("(h0) == -2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 99, __PRETTY_FUNCTION__));
  (((h0 = f0) == 0.0) ? (void) (0) : __assert_fail ("(h0 = f0) == 0.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 100, __PRETTY_FUNCTION__));
  (((h0) == 0.0) ? (void) (0) : __assert_fail ("(h0) == 0.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 101, __PRETTY_FUNCTION__));

  (((h0 += h1) == 1.0) ? (void) (0) : __assert_fail ("(h0 += h1) == 1.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 103, __PRETTY_FUNCTION__));
  (((h0) == 1.0) ? (void) (0) : __assert_fail ("(h0) == 1.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 104, __PRETTY_FUNCTION__));
  (((h0 += (__fp16)1.0) == 2.0) ? (void) (0) : __assert_fail ("(h0 += (__fp16)1.0) == 2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 105, __PRETTY_FUNCTION__));
  (((h0) == 2.0) ? (void) (0) : __assert_fail ("(h0) == 2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 106, __PRETTY_FUNCTION__));
  (((h0 += fm2) == 0.0) ? (void) (0) : __assert_fail ("(h0 += fm2) == 0.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 107, __PRETTY_FUNCTION__));
  (((h0) == 0.0) ? (void) (0) : __assert_fail ("(h0) == 0.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 108, __PRETTY_FUNCTION__));

  (((h0 -= h1) == -1.0) ? (void) (0) : __assert_fail ("(h0 -= h1) == -1.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 110, __PRETTY_FUNCTION__));
  (((h0) == -1.0) ? (void) (0) : __assert_fail ("(h0) == -1.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 111, __PRETTY_FUNCTION__));
  (((h0 -= (__fp16)1.0) == -2.0) ? (void) (0) : __assert_fail ("(h0 -= (__fp16)1.0) == -2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 112, __PRETTY_FUNCTION__));
  (((h0) == -2.0) ? (void) (0) : __assert_fail ("(h0) == -2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 113, __PRETTY_FUNCTION__));
  (((h0 -= fm2) == 0.0) ? (void) (0) : __assert_fail ("(h0 -= fm2) == 0.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 114, __PRETTY_FUNCTION__));
  (((h0) == 0.0) ? (void) (0) : __assert_fail ("(h0) == 0.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 115, __PRETTY_FUNCTION__));

  h0 = hm2;
  (((h0 *= hm2) == 4.0) ? (void) (0) : __assert_fail ("(h0 *= hm2) == 4.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 118, __PRETTY_FUNCTION__));
  (((h0) == 4.0) ? (void) (0) : __assert_fail ("(h0) == 4.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 119, __PRETTY_FUNCTION__));
  (((h0 *= (__fp16)-2.0) == -8.0) ? (void) (0) : __assert_fail ("(h0 *= (__fp16)-2.0) == -8.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 120, __PRETTY_FUNCTION__));
  (((h0) == -8.0) ? (void) (0) : __assert_fail ("(h0) == -8.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 121, __PRETTY_FUNCTION__));
  (((h0 *= fm2) == 16.0) ? (void) (0) : __assert_fail ("(h0 *= fm2) == 16.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 122, __PRETTY_FUNCTION__));
  (((h0) == 16.0) ? (void) (0) : __assert_fail ("(h0) == 16.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 123, __PRETTY_FUNCTION__));

  (((h0 /= hm2) == -8.0) ? (void) (0) : __assert_fail ("(h0 /= hm2) == -8.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 125, __PRETTY_FUNCTION__));
  (((h0) == -8.0) ? (void) (0) : __assert_fail ("(h0) == -8.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 126, __PRETTY_FUNCTION__));
  (((h0 /= (__fp16)-2.0) == 4.0) ? (void) (0) : __assert_fail ("(h0 /= (__fp16)-2.0) == 4.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 127, __PRETTY_FUNCTION__));
  (((h0) == 4.0) ? (void) (0) : __assert_fail ("(h0) == 4.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 128, __PRETTY_FUNCTION__));
  (((h0 /= fm2) == -2.0) ? (void) (0) : __assert_fail ("(h0 /= fm2) == -2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 129, __PRETTY_FUNCTION__));
  (((h0) == -2.0) ? (void) (0) : __assert_fail ("(h0) == -2.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 130, __PRETTY_FUNCTION__));

  ((((h0, h1)) == 1.0) ? (void) (0) : __assert_fail ("((h0, h1)) == 1.0", "../gcc-seed-programs/gcc.dg/torture/arm-fp16-ops.h", 132, __PRETTY_FUNCTION__));

  return 0;
}


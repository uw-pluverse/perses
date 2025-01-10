



#include "arm_mve.h"

float16x8_t
foo (uint16x8_t a, mve_pred16_t p)
{
  return vcvtq_x_n_f16_u16 (a, 1, p);
}




float16x8_t
foo1 (uint16x8_t a, mve_pred16_t p)
{
  return vcvtq_x_n (a, 1, p);
}

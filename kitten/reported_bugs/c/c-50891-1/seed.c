



#include "arm_mve.h"

uint8x16_t
foo (uint8x16_t a, uint8x16_t b)
{
  return vqaddq_u8 (a, b);
}



uint8x16_t
foo1 (uint8x16_t a, uint8x16_t b)
{
  return vqaddq (a, b);
}

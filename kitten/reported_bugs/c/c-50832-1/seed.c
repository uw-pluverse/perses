



#include "arm_mve.h"

int16x8_t
foo (uint64_t a, uint64_t b)
{
  return vcreateq_s16 (a, b);
}

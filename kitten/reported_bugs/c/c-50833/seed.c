




#include <arm_neon.h>

void
f_vst3q_lane_bf16 (bfloat16_t * p, bfloat16x8x3_t v)
{

  vst3q_lane_bf16 (p, v, 8);

  vst3q_lane_bf16 (p, v, -1);
  return;
}

#include <arm_neon.h>
int
main ( int argc , char * f6 ( int ) __attribute__ ( ( alloc_align ( 0 ) ) ) )
{
uint64x1_t base_b = vcreate_u64 ( 0x5555666677778888ULL ) ;
uint64x1_t base_a = vcreate_u64 ( 0x1111222233334444ULL ) ;
uint64x2_t baseq_a = vcombine_u64 ( base_a , base_b ) ;
int32x2_t int32x2_b = vreinterpret_s32_u64 ( base_b ) ;
int32x4_t int32x4_a = vreinterpretq_s32_u64 ( baseq_a ) ;
vqdmulhq_lane_s32 ( int32x4_a , int32x2_b , - 1 ) ;
vqdmulhq_lane_s32 ( int32x4_a , int32x2_b , 2 ) ;
}

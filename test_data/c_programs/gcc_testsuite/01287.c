




typedef unsigned short v16u16 __attribute__ ((vector_size (16)));
typedef unsigned int v16u32 __attribute__ ((vector_size (16)));

unsigned short
foo (v16u16 v16u16_1, v16u32 v16u32_1)
{
  v16u16_1 += (v16u16) v16u32_1;
  return v16u16_1[5] + v16u32_1[1];
}

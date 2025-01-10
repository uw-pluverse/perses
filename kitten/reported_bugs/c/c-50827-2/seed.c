




#include <arm_bf16.h>









bfloat16_t stacktest1 (bfloat16_t __a)
{
  volatile bfloat16_t b = __a;
  return b;
}






void bfloat_mov_ww (void)
{
  register bfloat16_t x asm ("h2");
  register bfloat16_t y asm ("h1");
  asm volatile ("" : "=w" (x));
  y = x;
  asm volatile ("" :: "w" (y));
}






void bfloat_mov_rw (void)
{
  register bfloat16_t x asm ("w1");
  register bfloat16_t y asm ("h1");
  asm volatile ("" : "=r" (x));
  y = x;
  asm volatile ("" :: "w" (y));
}






void bfloat_mov_wr (void)
{
  register bfloat16_t x asm ("h1");
  register bfloat16_t y asm ("w1");
  asm volatile ("" : "=w" (x));
  y = x;
  asm volatile ("" :: "r" (y));
}






void bfloat_mov_rr (void)
{
  register bfloat16_t x asm ("w2");
  register bfloat16_t y asm ("w1");
  asm volatile ("" : "=r" (x));
  y = x;
  asm volatile ("" :: "r" (y));
}






void bfloat_mov_rm (bfloat16_t *ptr)
{
   register bfloat16_t x asm ("w2");
   asm volatile ("" : "=r" (x));
   *ptr = x;
}






void bfloat_mov_mr (bfloat16_t *ptr)
{
   register bfloat16_t y asm ("w2");
   y = *ptr;
   asm volatile ("" :: "r" (y));
}

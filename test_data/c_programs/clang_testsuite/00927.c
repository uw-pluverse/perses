typedef unsigned int u_int32_t;
typedef u_int32_t uint32_t;
typedef unsigned long long u_int64_t;
typedef u_int64_t uint64_t;
typedef float __m128 __attribute__ ((vector_size (16)));
typedef float __m256 __attribute__ ((vector_size (32)));
typedef float __m512 __attribute__ ((vector_size (64)));
__m128 val128;
__m256 val256;
__m512 val512;
int func1() {
  uint32_t msr = 0x8b;
  uint64_t val = 0;
  __asm__ volatile("wrmsr"
                   :
                   : "c" (msr),
                     "a" ((val & 0xFFFFFFFFUL)),
                     "d" (((val >> 32) & 0xFFFFFFFFUL)));
  unsigned char data;
  unsigned int port;
  __asm__ volatile("outb %0, %w1" : : "a" (data), "Nd" (port));
  __asm__ volatile("outb %0, %w1" : : "R" (val), "Nd" (port));
  __asm__ volatile("outb %0, %w1" : : "q" (val), "Nd" (port));
  __asm__ volatile("outb %0, %w1" : : "Q" (val), "Nd" (port));
  __asm__ volatile("outb %0, %w1" : : "b" (val), "Nd" (port));
  __asm__ volatile("outb %0, %w1" : : "c" (val), "Nd" (port));
  __asm__ volatile("outb %0, %w1" : : "d" (val), "Nd" (port));
  __asm__ volatile("outb %0, %w1" : : "S" (val), "Nd" (port));
  __asm__ volatile("outb %0, %w1" : : "D" (val), "Nd" (port));
  __asm__ volatile("foo1 %0" : : "A" (val128));
  __asm__ volatile("foo1 %0" : : "f" (val256));
  __asm__ volatile("foo1 %0" : : "t" (val256));
  __asm__ volatile("foo1 %0" : : "u" (val256));
  __asm__ volatile("foo1 %0" : : "x" (val512));
  __asm__ volatile("foo1 %0" : "=R" (val));
  __asm__ volatile("foo1 %0" : "=q" (val));
  __asm__ volatile("foo1 %0" : "=Q" (val));
  __asm__ volatile("foo1 %0" : "=a" (val));
  __asm__ volatile("foo1 %0" : "=b" (val));
  __asm__ volatile("foo1 %0" : "=c" (val));
  __asm__ volatile("foo1 %0" : "=d" (val));
  __asm__ volatile("foo1 %0" : "=S" (val));
  __asm__ volatile("foo1 %0" : "=D" (val));
  __asm__ volatile("foo1 %0" : "=A" (val128));
  __asm__ volatile("foo1 %0" : "=t" (val256));
  __asm__ volatile("foo1 %0" : "=u" (val256));
  __asm__ volatile("foo1 %0" : "=x" (val512));
  __asm__ volatile("foo1 %0" : : "x" (val256));
  __asm__ volatile("foo1 %0" : "=x" (val256));
}

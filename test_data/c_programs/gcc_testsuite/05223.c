

extern const unsigned long base;
static inline void wreg(unsigned char val, unsigned long addr) __attribute__((always_inline));
static inline void wreg(unsigned char val, unsigned long addr)
{
   *((volatile unsigned char *) (long unsigned int) (base + addr)) = val;
}
void wreg_twice(void)
{
   wreg(0, 42);
   wreg(0, 42);
}

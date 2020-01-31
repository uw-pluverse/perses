

typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
void test16(uint16_t x, uint32_t eflags)
{
        uint16_t bsr_result;
        uint32_t bsr_eflags;
        uint16_t bsf_result;
        uint32_t bsf_eflags;

        __asm volatile(""
                : "=&r" (bsr_result), "=&r" (bsr_eflags)
                : "r" (x), "i" (~((1<<0)|(1<<2)|(1<<4)|(1<<6)|(1<<7)|(1<<11))), "r" (eflags));
        __asm volatile(""
                : "=&r" (bsf_result), "=&r" (bsf_eflags)
                : "r" (x), "i" (~((1<<0)|(1<<2)|(1<<4)|(1<<6)|(1<<7)|(1<<11))), "r" (eflags));
        printf("%08x %04x bsrw %02x %08x bsfw %02x %08x\n",
                x, eflags, bsr_result, bsr_eflags, bsf_result, bsf_eflags);
}

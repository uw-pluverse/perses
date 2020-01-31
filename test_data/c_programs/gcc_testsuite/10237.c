


static inline void asmfunc()
{
__asm__("");
}

__attribute__((transaction_callable))
void push()
{
        asmfunc();
}

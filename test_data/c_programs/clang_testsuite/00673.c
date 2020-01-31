union reg
{
    unsigned char b[2][2];
    unsigned short w[2];
    unsigned int d;
};
struct cpu
{
    union reg pc;
};
extern struct cpu cpu;
struct svar
{
    void *ptr;
};
struct svar svars1[] =
{
    { &((cpu.pc).w[0]) }
};
struct svar svars2[] =
{
    { &((cpu.pc).b[0][1]) }
};
struct svar svars3[] =
{
    { &((cpu.pc).w[1]) }
};
struct svar svars4[] =
{
    { &((cpu.pc).b[1][1]) }
};

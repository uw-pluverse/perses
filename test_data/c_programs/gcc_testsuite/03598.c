typedef signed int s32;
typedef signed long s64;
typedef unsigned int u32;
typedef unsigned long u64;

extern __inline__ u32 foobar(int logmask)
{
        u32 ret = ~(1 << logmask);



        return ret;
}


u32 good(u32 var)
{
        var = foobar(0);
        return var;
}





u32 fails(u32 *var)
{
        *var = foobar(0);
        return *var;
}

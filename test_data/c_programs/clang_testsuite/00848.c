typedef short short_fixed;
enum
{
        SHORT_FIXED_FRACTIONAL_BITS= 8,
        SHORT_FIXED_ONE= 1<<SHORT_FIXED_FRACTIONAL_BITS
};
enum
{
        SOME_VALUE= ((short_fixed)((0.1)*SHORT_FIXED_ONE))
};

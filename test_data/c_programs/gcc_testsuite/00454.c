















typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;

typedef long int int64_t;







typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;



typedef unsigned long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;

typedef long int int_least64_t;






typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;

typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
typedef long int intmax_t;
typedef unsigned long int uintmax_t;
uint64_t
swap64_load (uint64_t *in)
{
  return ((uint64_t)( (((uint64_t)(*in) & (uint64_t)0x00000000000000ffULL) << 56) | (((uint64_t)(*in) & (uint64_t)0x000000000000ff00ULL) << 40) | (((uint64_t)(*in) & (uint64_t)0x0000000000ff0000ULL) << 24) | (((uint64_t)(*in) & (uint64_t)0x00000000ff000000ULL) << 8) | (((uint64_t)(*in) & (uint64_t)0x000000ff00000000ULL) >> 8) | (((uint64_t)(*in) & (uint64_t)0x0000ff0000000000ULL) >> 24) | (((uint64_t)(*in) & (uint64_t)0x00ff000000000000ULL) >> 40) | (((uint64_t)(*in) & (uint64_t)0xff00000000000000ULL) >> 56)));
}

void
swap64_store (uint64_t *out, uint64_t in)
{
  *out = ((uint64_t)( (((uint64_t)(in) & (uint64_t)0x00000000000000ffULL) << 56) | (((uint64_t)(in) & (uint64_t)0x000000000000ff00ULL) << 40) | (((uint64_t)(in) & (uint64_t)0x0000000000ff0000ULL) << 24) | (((uint64_t)(in) & (uint64_t)0x00000000ff000000ULL) << 8) | (((uint64_t)(in) & (uint64_t)0x000000ff00000000ULL) >> 8) | (((uint64_t)(in) & (uint64_t)0x0000ff0000000000ULL) >> 24) | (((uint64_t)(in) & (uint64_t)0x00ff000000000000ULL) >> 40) | (((uint64_t)(in) & (uint64_t)0xff00000000000000ULL) >> 56)));
}

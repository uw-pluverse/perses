













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
swap64 (uint64_t in)
{
  return ((uint64_t)( (((uint64_t)(in) & (uint64_t)0x00000000000000ffULL) << 56) | (((uint64_t)(in) & (uint64_t)0x000000000000ff00ULL) << 40) | (((uint64_t)(in) & (uint64_t)0x0000000000ff0000ULL) << 24) | (((uint64_t)(in) & (uint64_t)0x00000000ff000000ULL) << 8) | (((uint64_t)(in) & (uint64_t)0x000000ff00000000ULL) >> 8) | (((uint64_t)(in) & (uint64_t)0x0000ff0000000000ULL) >> 24) | (((uint64_t)(in) & (uint64_t)0x00ff000000000000ULL) >> 40) | (((uint64_t)(in) & (uint64_t)0xff00000000000000ULL) >> 56)));
}






typedef int DItype __attribute__ ((mode (DI)));
DItype
swap64_b (DItype u)
{
  return ((((u) & 0xff00000000000000ull) >> 56)
   | (((u) & 0x00ff000000000000ull) >> 40)
   | (((u) & 0x0000ff0000000000ull) >> 24)
   | (((u) & 0x000000ff00000000ull) >> 8)
   | (((u) & 0x00000000ff000000ull) << 8)
   | (((u) & 0x0000000000ff0000ull) << 24)
   | (((u) & 0x000000000000ff00ull) << 40)
   | (((u) & 0x00000000000000ffull) << 56));
}



uint64_t
swap64_c (uint64_t x)
{
  uint32_t a = x >> 32;
  uint32_t b = (uint32_t) x;
  return ((uint64_t) ((((((b)) >> (8)) | (((b)) << (32 - (8)))) & 0xff00ff00L)
        | (((((b)) << (8)) | (((b)) >> (32 - (8)))) & 0x00ff00ffL)) << 32)
          | (uint64_t) ((((((a)) >> (8)) | (((a)) << (32 - (8)))) & 0xff00ff00L)
   | (((((a)) << (8)) | (((a)) >> (32 - (8)))) & 0x00ff00ffL));
}

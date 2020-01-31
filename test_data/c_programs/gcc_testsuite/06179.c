







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



int foo1 (uint32_t a)
{
  if (__builtin_bswap32(a) == 0xA0000)
    return 1;
  return 2;
}

int foo2 (uint32_t a)
{
  if (__builtin_bswap32(a) != 0xA0000)
    return 1;
  return 2;
}

int foo3 (uint32_t a, uint32_t b)
{
  if (__builtin_bswap32(a) == __builtin_bswap32(b))
    return 1;
  return 2;
}

int foo4 (uint32_t a, uint32_t b)
{
  if (__builtin_bswap32(a) != __builtin_bswap32(b))
    return 1;
  return 2;
}

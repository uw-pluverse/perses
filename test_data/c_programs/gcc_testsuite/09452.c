













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
swap64_c (uint64_t x)
{
  uint16_t a0 = x >> 48;
  uint16_t a1 = x >> 32;
  uint16_t a2 = x >> 16;
  uint16_t a3 = x;

  return ((uint64_t) (((a0 >> 8) & 0xff) | ((a0 << 8) & 0xff00)))
 | ((uint64_t) (((a1 >> 8) & 0xff) | ((a1 << 8) & 0xff00)) << 16)
 | ((uint64_t) (((a2 >> 8) & 0xff) | ((a2 << 8) & 0xff00)) << 32)
 | ((uint64_t) (((a3 >> 8) & 0xff) | ((a3 << 8) & 0xff00)) << 48);
}

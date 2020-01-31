











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

extern void abort (void);

uint64_t __attribute__((noinline))
byteswap64(uint64_t x)
{
  uint32_t a = x >> 32;
  uint32_t b = (uint32_t) x;
  return ((uint64_t) ((((((b)) >> (8)) | (((b)) << (32 - (8)))) & 0xff00ff00L)
        | (((((b)) << (8)) | (((b)) >> (32 - (8)))) & 0x00ff00ffL)) << 32)
          | (uint64_t) ((((((a)) >> (8)) | (((a)) << (32 - (8)))) & 0xff00ff00L)
   | (((((a)) << (8)) | (((a)) >> (32 - (8)))) & 0x00ff00ffL));
}

int
main ()
{
  uint64_t in = (uint64_t)0x01020304 << 32 | 0x05060708;
  uint64_t cmp = (uint64_t)0x08070605 << 32 | 0x04030201;

  if (cmp != byteswap64 (in))
    abort ();

  return 0;
}

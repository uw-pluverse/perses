











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

typedef unsigned int word __attribute__((mode(word)));
typedef unsigned __int128 bigger_than_word;

int
foo (bigger_than_word a, word b, uint8_t c)
{

  const uint8_t t1 = b % (127*2 +1);


  const uint8_t t2 = a % (127*2 +1);


  const uint32_t t3 = (const uint32_t)(c >> 1);

  uint16_t ret = 0;

  if (t1 == 1)
    ret = 20;
  else if (t2 == 2)
    ret = 30;
  else if (t3 == 3)
    ret = 40;


  else if (t3 == 4)
    ret = 50;

  return ret;
}

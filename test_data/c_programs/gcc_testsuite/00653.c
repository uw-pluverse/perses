










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

uint32_t
truncate_int (const unsigned long long value)
{
  if ( value < 0 )
    {
      return 0;
    }
  else if ( value > (4294967295U) )
    {
      return (4294967295U);
    }
  else
    return (uint32_t)value;
}

uint32_t
mul (const unsigned long long x, const unsigned long long y)
{
  uint32_t value = truncate_int (x * y);
  return value;
}

uint32_t *
test(unsigned size, uint32_t *a, uint32_t s)
{
  unsigned i;

  for (i = 0; i < size; i++)
    {
      a[i] = mul (a[i], s);
    }

  return a;
}

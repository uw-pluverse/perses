













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
swap32_a (uint32_t in)
{
  return ((uint32_t)( (((uint32_t)(in) & (uint32_t)0x000000ffUL) << 24) | (((uint32_t)(in) & (uint32_t)0x0000ff00UL) << 8) | (((uint32_t)(in) & (uint32_t)0x00ff0000UL) >> 8) | (((uint32_t)(in) & (uint32_t)0xff000000UL) >> 24)));
}


uint32_t
swap32_b (uint32_t in)
{
  uint32_t a;

  a = (in << 16) | (in >> 16);
  a = ((a & 0x00ff00ff) << 8) | ((a & 0xff00ff00) >> 8);

  return a;
}






typedef int SItype __attribute__ ((mode (SI)));

SItype
swap32_c (SItype u)
{
  return ((((u) & 0xff000000) >> 24)
   | (((u) & 0x00ff0000) >> 8)
   | (((u) & 0x0000ff00) << 8)
   | (((u) & 0x000000ff) << 24));
}





SItype
swap32_d (SItype in)
{


  return (((in >> 0) & 0xFF) << 24)
  | (((in >> 8) & 0xFF) << 16)
  | (((in >> 16) & 0xFF) << 8)
  | (((in >> 24) & 0xFF) << 0);
}






SItype
swap32_e (SItype in)
{
  return (((in >> 0) & 0xFF) << 24)
  | (((in >> 8) & 0xFF) << 16)
  | (((((int64_t) in) & 0xFF0000FF0000) >> 16) << 8)
  | (((in >> 24) & 0xFF) << 0);
}




unsigned
swap32_f (unsigned in)
{
  in = ((in & 0xff00ff00) >> 8) | ((in & 0x00ff00ff) << 8);
  in = ((in & 0xffff0000) >> 16) | ((in & 0x0000ffff) << 16);
  return in;
}

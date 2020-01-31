













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

unsigned char data[2];

struct uint16_st {
  unsigned char u0, u1;
};

uint32_t read_le16_1 (void)
{
  return data[0] | (data[1] << 8);
}

uint32_t read_le16_2 (struct uint16_st data)
{
  return data.u0 | (data.u1 << 8);
}

uint32_t read_le16_3 (unsigned char *data)
{
  return *data | (*(data + 1) << 8);
}

uint32_t read_be16_1 (void)
{
  return data[1] | (data[0] << 8);
}

uint32_t read_be16_2 (struct uint16_st data)
{
  return data.u1 | (data.u0 << 8);
}

uint32_t read_be16_3 (unsigned char *data)
{
  return *(data + 1) | (*data << 8);
}

typedef int HItype __attribute__ ((mode (HI)));




HItype
swap16 (HItype in)
{
  return (HItype) (((in >> 0) & 0xFF) << 8)
  | (((in >> 8) & 0xFF) << 0);
}

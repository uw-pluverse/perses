













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

extern unsigned char data[4];

struct uint32_st {
  unsigned char u0, u1, u2, u3;
};

uint32_t read_le32_1 (void)
{
  return data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
}

uint32_t read_le32_2 (struct uint32_st data)
{
  return data.u0 | (data.u1 << 8) | (data.u2 << 16) | (data.u3 << 24);
}

uint32_t read_le32_3 (unsigned char *data)
{
  return *data | (*(data + 1) << 8) | (*(data + 2) << 16)
  | (*(data + 3) << 24);
}

uint32_t read_be32_1 (void)
{
  return data[3] | (data[2] << 8) | (data[1] << 16) | (data[0] << 24);
}

uint32_t read_be32_2 (struct uint32_st data)
{
  return data.u3 | (data.u2 << 8) | (data.u1 << 16) | (data.u0 << 24);
}

uint32_t read_be32_3 (unsigned char *data)
{
  return *(data + 3) | (*(data + 2) << 8) | (*(data + 1) << 16)
  | (*data << 24);
}

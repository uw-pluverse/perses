













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

unsigned char data[8];

struct uint64_st {
  unsigned char u0, u1, u2, u3, u4, u5, u6, u7;
};

uint64_t read_le64_1 (void)
{
  return (uint64_t) data[0] | ((uint64_t) data[1] << 8)
  | ((uint64_t) data[2] << 16) | ((uint64_t) data[3] << 24)
  | ((uint64_t) data[4] << 32) | ((uint64_t) data[5] << 40)
  | ((uint64_t) data[6] << 48) | ((uint64_t) data[7] << 56);
}

uint64_t read_le64_2 (struct uint64_st data)
{
  return (uint64_t) data.u0 | ((uint64_t) data.u1 << 8)
  | ((uint64_t) data.u2 << 16) | ((uint64_t) data.u3 << 24)
  | ((uint64_t) data.u4 << 32) | ((uint64_t) data.u5 << 40)
  | ((uint64_t) data.u6 << 48) | ((uint64_t) data.u7 << 56);
}

uint64_t read_le64_3 (unsigned char *data)
{
  return (uint64_t) *data | ((uint64_t) *(data + 1) << 8)
  | ((uint64_t) *(data + 2) << 16) | ((uint64_t) *(data + 3) << 24)
  | ((uint64_t) *(data + 4) << 32) | ((uint64_t) *(data + 5) << 40)
  | ((uint64_t) *(data + 6) << 48) | ((uint64_t) *(data + 7) << 56);
}

uint64_t read_be64_1 (void)
{
  return (uint64_t) data[7] | ((uint64_t) data[6] << 8)
  | ((uint64_t) data[5] << 16) | ((uint64_t) data[4] << 24)
  | ((uint64_t) data[3] << 32) | ((uint64_t) data[2] << 40)
  | ((uint64_t) data[1] << 48) | ((uint64_t) data[0] << 56);
}

uint64_t read_be64_2 (struct uint64_st data)
{
  return (uint64_t) data.u7 | ((uint64_t) data.u6 << 8)
  | ((uint64_t) data.u5 << 16) | ((uint64_t) data.u4 << 24)
  | ((uint64_t) data.u3 << 32) | ((uint64_t) data.u2 << 40)
  | ((uint64_t) data.u1 << 48) | ((uint64_t) data.u0 << 56);
}

uint64_t read_be64_3 (unsigned char *data)
{
  return (uint64_t) *(data + 7) | ((uint64_t) *(data + 6) << 8)
  | ((uint64_t) *(data + 5) << 16) | ((uint64_t) *(data + 4) << 24)
  | ((uint64_t) *(data + 3) << 32) | ((uint64_t) *(data + 2) << 40)
  | ((uint64_t) *(data + 1) << 48) | ((uint64_t) *data << 56);
}

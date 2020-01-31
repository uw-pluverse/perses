






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




void
check_corresponding (void)
{

  do { int8_t a; uint8_t *b = &a; uint8_t c; int8_t *d = &c; } while (0);


  do { int16_t a; uint16_t *b = &a; uint16_t c; int16_t *d = &c; } while (0);


  do { int32_t a; uint32_t *b = &a; uint32_t c; int32_t *d = &c; } while (0);


  do { int64_t a; uint64_t *b = &a; uint64_t c; int64_t *d = &c; } while (0);

  do { int_least8_t a; uint_least8_t *b = &a; uint_least8_t c; int_least8_t *d = &c; } while (0);
  do { int_least16_t a; uint_least16_t *b = &a; uint_least16_t c; int_least16_t *d = &c; } while (0);
  do { int_least32_t a; uint_least32_t *b = &a; uint_least32_t c; int_least32_t *d = &c; } while (0);
  do { int_least64_t a; uint_least64_t *b = &a; uint_least64_t c; int_least64_t *d = &c; } while (0);
  do { int_fast8_t a; uint_fast8_t *b = &a; uint_fast8_t c; int_fast8_t *d = &c; } while (0);
  do { int_fast16_t a; uint_fast16_t *b = &a; uint_fast16_t c; int_fast16_t *d = &c; } while (0);
  do { int_fast32_t a; uint_fast32_t *b = &a; uint_fast32_t c; int_fast32_t *d = &c; } while (0);
  do { int_fast64_t a; uint_fast64_t *b = &a; uint_fast64_t c; int_fast64_t *d = &c; } while (0);

  do { intptr_t a; uintptr_t *b = &a; uintptr_t c; intptr_t *d = &c; } while (0);

  do { intmax_t a; uintmax_t *b = &a; uintmax_t c; intmax_t *d = &c; } while (0);
}


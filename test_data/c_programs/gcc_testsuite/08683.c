










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

extern int fail_the_test(void *);
extern int pass_the_test(void *);
extern int diversion (void *);

struct somestruct
{
  void *whee;
  void *oops;
};

struct container
{
  struct somestruct first;
  struct somestruct buf[32];
};

static int __attribute__((noinline))
foo (void *p)
{
  uintptr_t a = (uintptr_t) p;

  if (a % 4)
    return fail_the_test (p);
  else
    return pass_the_test (p);
}

int
bar (void)
{
  struct container c;
  return foo (c.buf);
}


static int
through (struct somestruct *p)
{
  diversion (p);
  return foo (&p[16]);
}

int
bar2 (void)
{
  struct container c;
  through (c.buf);
}

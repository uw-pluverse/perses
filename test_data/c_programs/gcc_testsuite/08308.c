












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

typedef struct {
  int64_t counter;
} atomic64_t;

struct buffer_page {
  void *a, *b;
  atomic64_t entries;
};

static __inline__ __attribute__((always_inline)) int64_t
atomic64_read(const atomic64_t *v)
{
 int64_t t;
 __asm__ __volatile__("# %0, %1" : "=r"(t) : "m"(v->counter));
 return t;
}

int rb_remove_pages(void *p)
{
  struct buffer_page *blah = (void *)((intptr_t) p & -4);
  return atomic64_read(&blah->entries);
}












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







struct dev_ino_4
{
  uint32_t mode:2;
  uint32_t short_ino:(32 - 5 - 2 - 1);
  uint32_t mapped_dev:5;
  uint32_t always_set:1;
};

struct dev_ino_8
{
  uint32_t mode:2;
  uint64_t short_ino:(64 - 8 - 2 - 1);
  uint32_t mapped_dev:8;
  uint32_t always_set:1;
};

struct dev_ino_full
{
  uint32_t mode:2;
  uint32_t dev;
  uint32_t ino;
};

enum di_mode
{
  DI_MODE_4 = 1,
  DI_MODE_8 = 2,
  DI_MODE_FULL = 3
};

struct di_ent
{
  union
  {
    struct dev_ino_4 di4;
    struct dev_ino_8 di8;
    struct dev_ino_full full;
    uint32_t u32;
    uint64_t u64;
    void *ptr;
  } u;
};

static struct di_ent
decode_ptr (struct di_ent const *v)
{
  struct di_ent di;
  di.u.ptr = (void *) v;
  return di;
}

static int
di_ent_equal (void const *x, void const *y)
{
  struct di_ent a = decode_ptr (x);
  struct di_ent b = decode_ptr (y);
  if (a.u.di4.mode != b.u.di4.mode)
    return 0;

  if (a.u.di4.mode == DI_MODE_4)
    return (a.u.di4.short_ino == b.u.di4.short_ino
            && a.u.di4.mapped_dev == b.u.di4.mapped_dev);

  if (a.u.di8.mode == DI_MODE_8)
    return (a.u.di8.short_ino == b.u.di8.short_ino
            && a.u.di8.mapped_dev == b.u.di8.mapped_dev);

  return (a.u.full.ino == b.u.full.ino
          && a.u.full.dev == b.u.full.dev);
}

int
main ()
{
  if (di_ent_equal ((void *) 0x80143c4d, (void *) 0x80173851) != 0)
    abort ();
  return 0;
}

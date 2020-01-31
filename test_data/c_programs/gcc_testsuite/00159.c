

typedef int int128_t __attribute__((mode(TI)));
typedef unsigned int uint128_t __attribute__((mode(TI)));




volatile uint128_t a = (((uint128_t) (0x1111111111111111ULL) << 64) | (0xa222222222222222ULL));
volatile uint128_t b = (((uint128_t) (0x0000000000000005ULL) << 64) | (0x0000000000000003ULL));
volatile uint128_t c = (((uint128_t) (0x5ddddddddddddddeULL) << 64) | (0xe666666666666666ULL));
volatile uint128_t d = (((uint128_t) (0xe612340000000000ULL) << 64) | (0x5000000000234500ULL));
volatile uint128_t e = (((uint128_t) (0x43f011dddddddddfULL) << 64) | (0x366666666689ab66ULL));
volatile uint128_t f = (((uint128_t) (0x4210100000000000ULL) << 64) | (0x1000000000010100ULL));
volatile uint128_t g = (((uint128_t) (0xa5e225dddddddddfULL) << 64) | (0x6666666666aaee66ULL));
volatile uint128_t h = (((uint128_t) (0xe7f235dddddddddfULL) << 64) | (0x7666666666abef66ULL));
volatile uint128_t i = (((uint128_t) (0x5e225dddddddddf6ULL) << 64) | (0x666666666aaee660ULL));
volatile uint128_t j = (((uint128_t) (0x0a5e225dddddddddULL) << 64) | (0xf6666666666aaee6ULL));
volatile uint128_t k = (((uint128_t) (0xfa5e225dddddddddULL) << 64) | (0xf6666666666aaee6ULL));

volatile int amount = 4;

volatile uint128_t result;

int
test1 (void)
{
  result = a * b;
  if (result != c)
    return 1;
  return 0;
}

int
test2 (void)
{
  result = c + d;
  if (result != e)
    return 1;
  return 0;
}

int
test3 (void)
{
  result = e - d;
  if (result != c)
    return 1;
  return 0;
}

int
test4 (void)
{
  result = d & e;
  if (result != f)
    return 1;
  return 0;
}

int
test5 (void)
{
  result = d ^ e;
  if (result != g)
    return 1;
  return 0;
}

int
test6 (void)
{
  result = d | e;
  if (result != h)
    return 1;
  return 0;
}

int
test7 (void)
{
  result = g << amount;
  if (result != i)
    return 1;
  return 0;
}

int
test8 (void)
{
  result = g >> amount;
  if (result != j)
    return 1;
  return 0;
}

int
test9 (void)
{
  result = (int128_t) g >> amount;
  if (result != k)
    return 1;
  return 0;
}

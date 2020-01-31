

typedef short int16_t;
typedef int int32_t;

static inline int32_t bar (int16_t x, int16_t y)
{
  return x * y;
}

void foo (int16_t i, int16_t *p, int16_t x)
{
  while (i--)
    {
      *p = bar (*p, x) >> 15;
      p++;
      *p = bar (*p, x) >> 15;
      p++;
    }
}

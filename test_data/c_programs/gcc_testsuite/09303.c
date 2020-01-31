




unsigned int
lsr (unsigned int a, unsigned int b)
{
  return ~((~a) >> b);
}

int
sl (int a, int b)
{
  return ~((~a) << b);
}

typedef unsigned int uint32_t;
typedef long int int64_t;

int64_t
asr_widen1 (uint32_t a, int b)
{
  return ~((int64_t)(~a) >> b);
}

int64_t
asr_widen2 (uint32_t a, int b)
{
  return ~(int64_t)(~a >> b);
}

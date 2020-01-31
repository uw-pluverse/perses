
typedef unsigned int uint32_t;
__attribute__ ((noinline, noclone)) uint32_t
fake_swap32 (uint32_t in)
{
  return ((uint32_t)( (((uint32_t)(in) & (uint32_t)0x000000ffUL) << 24) | (((uint32_t)(in) & (uint32_t)0x0000ff00UL) << 8) | (((uint32_t)(in) & (uint32_t)0x000000ffUL) << 8) | (((uint32_t)(in) & (uint32_t)0x0000ff00UL) ) | (((uint32_t)(in) & (uint32_t)0xff000000UL) >> 24)));
}

int main(void)
{
  if (sizeof (uint32_t) * 8 != 32)
    return 0;
  if (fake_swap32 (0x12345678UL) != 0x78567E12UL)
    __builtin_abort ();
  return 0;
}

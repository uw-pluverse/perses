
typedef short int16_t;





typedef unsigned int uint32_t;
__attribute__ ((noinline, noclone)) uint32_t
fake_bswap32 (uint32_t in)
{
  return ((uint32_t)( (((uint32_t) (in) & (uint32_t)0x000000ffUL) << 24) | (((uint32_t)(int16_t)(in) & (uint32_t)0x00ffff00UL) << 8) | (((uint32_t) (in) & (uint32_t)0x00ff0000UL) >> 8) | (((uint32_t) (in) & (uint32_t)0xff000000UL) >> 24)));
}

int
main(void)
{
  if (sizeof (uint32_t) * 8 != 32)
    return 0;
  if (sizeof (int16_t) * 8 != 16)
    return 0;
  if (fake_bswap32 (0x81828384) != 0xff838281)
    __builtin_abort ();
  return 0;
}

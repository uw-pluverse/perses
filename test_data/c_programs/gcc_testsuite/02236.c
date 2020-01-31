
typedef long unsigned int uint64_t;
__attribute__ ((noinline, noclone)) uint64_t
uint128_central_bitsi_ior (unsigned __int128 in1, uint64_t in2)
{
  __int128 mask = (__int128)0xffff << 56;
  return ((in1 & mask) >> 56) | in2;
}

int
main(int argc, char **argv)
{
  __int128 in = 1;

  in <<= 64;

  if (sizeof (uint64_t) * 8 != 64)
    return 0;
  if (sizeof (unsigned __int128) * 8 != 128)
    return 0;
  if (uint128_central_bitsi_ior (in, 2) != 0x102)
    __builtin_abort ();
  return 0;
}

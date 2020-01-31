





typedef int SItype __attribute__ ((mode (SI)));
typedef int DItype __attribute__ ((mode (DI)));





SItype
swap32 (SItype in)
{
  return (((in >> 0) & 0xFF) << 24)
  | (((in >> 8) & 0xFF) << 16)
  | (((((DItype) in) & 0xFF00FF0000llu) >> 16) << 8)
  | (((in >> 24) & 0xFF) << 0);
}

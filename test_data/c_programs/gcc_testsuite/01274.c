



typedef int SItype __attribute__ ((mode (SI)));
typedef int DItype __attribute__ ((mode (DI)));
void abort (void);

SItype
__mulvsi3 (SItype a, SItype b)
{
  const DItype w = (DItype) a * (DItype) b;
  if ((SItype) (w >> (4 * 8)) != (SItype) w >> ((4 * 8) - 1))
    abort ();
  return w;
}

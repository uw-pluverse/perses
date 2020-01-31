





extern void abort (void);

int main(void)
{
  volatile long double ee = 1.0;
  long double eps = ee;
  while (ee + 1.0 != 1.0)
    {
      eps = ee;
      ee = eps / 2;
    }
  if (eps != 1.08420217248550443401e-19L)
    abort ();
  return 0;
}









int __attribute__ ((noinline,noclone))
fn1 (unsigned int u)
{
  return (-(int) (u - 1U)) - 1;
}

long __attribute__ ((noinline,noclone))
fn2 (unsigned long int ul)
{
  return (-(long) (ul - 1UL)) - 1L;
}

long long __attribute__ ((noinline,noclone))
fn3 (unsigned long long int ull)
{
  return (-(long long) (ull - 1ULL)) - 1LL;
}

int
main (void)
{
  if (fn1 (2147483647 + 1U) != (-2147483647 - 1)
      || fn2 (9223372036854775807L + 1UL) != (-9223372036854775807L - 1L)
      || fn3 (9223372036854775807LL + 1ULL) != (-9223372036854775807LL - 1LL))
    __builtin_abort ();
}

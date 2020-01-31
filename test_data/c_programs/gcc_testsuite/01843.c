



int
main ()
{
  volatile long long l1 = 1;
  volatile long long l2 = -1;
  volatile long long l3 = -1;

  if (((-9223372036854775807LL - 1) % 1LL) != 0)
    __builtin_abort ();
  if (((-9223372036854775807LL - 1) % l1) != 0)
    __builtin_abort ();
  if (l2 == -1)
    {
      if (((-9223372036854775807LL - 1) % 1LL) != 0)
 __builtin_abort ();
    }
  else if (((-9223372036854775807LL - 1) % -l2) != 0)
    __builtin_abort ();
  if (((-9223372036854775807LL - 1) % -l3) != 0)
    __builtin_abort ();

  return 0;
}

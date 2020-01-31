int
main (void)
{
  volatile signed char c = -(-127 - 1);
  ({ if ((c) != (-128)) __builtin_abort (); });

  volatile short s = -(-32767 - 1);
  ({ if ((s) != (-32768)) __builtin_abort (); });

  volatile int i = (-2147483647 - 1);
  i = -(unsigned) i;
  ({ if ((i) != (-0x80000000)) __builtin_abort (); });

  volatile long int li = (-9223372036854775807L - 1L);
  li = -(unsigned long) li;



  ({ if ((li) != (-0x8000000000000000L)) __builtin_abort (); });


  volatile long long lli = (-9223372036854775807LL - 1LL);
  lli = -(unsigned long long) lli;
  ({ if ((lli) != (-0x8000000000000000L)) __builtin_abort (); });
  return 0;
}

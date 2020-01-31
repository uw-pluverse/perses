






extern void abort(void);

short v = 0;
short expected = 0;
short max = ~0;
short desired = ~0;
short zero = 0;




int
main ()
{

  if (!__atomic_compare_exchange_n (&v, &expected, max, 0 , 0, 0))
    abort ();
  if (expected != 0)
    abort ();

  if (__atomic_compare_exchange_n (&v, &expected, 0, 0 , 2, 0))
    abort ();
  if (expected != max)
    abort ();

  if (!__atomic_compare_exchange_n (&v, &expected, 0, 0 , 3, 2))
    abort ();
  if (expected != max)
    abort ();
  if (v != 0)
    abort ();

  if (__atomic_compare_exchange_n (&v, &expected, desired, 1, 4, 2))
    abort ();
  if (expected != 0)
    abort ();

  if (!__atomic_compare_exchange_n (&v, &expected, desired, 0 , 5, 5))
    abort ();
  if (expected != 0)
    abort ();
  if (v != max)
    abort ();



  v = 0;

  if (!__atomic_compare_exchange (&v, &expected, &max, 0, 0, 0))
    abort ();
  if (expected != 0)
    abort ();

  if (__atomic_compare_exchange (&v, &expected, &zero, 0 , 2, 0))
    abort ();
  if (expected != max)
    abort ();

  if (!__atomic_compare_exchange (&v, &expected, &zero, 0 , 3, 2))
    abort ();
  if (expected != max)
    abort ();
  if (v != 0)
    abort ();

  if (__atomic_compare_exchange (&v, &expected, &desired, 1, 4, 2))
    abort ();
  if (expected != 0)
    abort ();

  if (!__atomic_compare_exchange (&v, &expected, &desired, 0 , 5, 5))
    abort ();
  if (expected != 0)
    abort ();
  if (v != max)
    abort ();

  return 0;
}

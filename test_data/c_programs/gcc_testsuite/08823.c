extern void abort(void);

long long v, count, ret;

int
main ()
{
  v = 0;
  count = 0;

  if (__atomic_exchange_n (&v, count + 1, 0) != count)
    abort ();
  count++;

  if (__atomic_exchange_n (&v, count + 1, 2) != count)
    abort ();
  count++;

  if (__atomic_exchange_n (&v, count + 1, 3) != count)
    abort ();
  count++;

  if (__atomic_exchange_n (&v, count + 1, 4) != count)
    abort ();
  count++;

  if (__atomic_exchange_n (&v, count + 1, 5) != count)
    abort ();
  count++;



  count++;

  __atomic_exchange (&v, &count, &ret, 0);
  if (ret != count - 1 || v != count)
    abort ();
  count++;

  __atomic_exchange (&v, &count, &ret, 2);
  if (ret != count - 1 || v != count)
    abort ();
  count++;

  __atomic_exchange (&v, &count, &ret, 3);
  if (ret != count - 1 || v != count)
    abort ();
  count++;

  __atomic_exchange (&v, &count, &ret, 4);
  if (ret != count - 1 || v != count)
    abort ();
  count++;

  __atomic_exchange (&v, &count, &ret, 5);
  if (ret != count - 1 || v != count)
    abort ();
  count++;

  return 0;
}

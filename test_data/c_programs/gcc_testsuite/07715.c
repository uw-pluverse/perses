







extern void abort(void);

__int128_t v, count;

int
main ()
{
  v = 0;
  count = 0;

  __atomic_store_n (&v, count + 1, 0);
  if (v != ++count)
    abort ();

  __atomic_store_n (&v, count + 1, 3);
  if (v != ++count)
    abort ();

  __atomic_store_n (&v, count + 1, 5);
  if (v != ++count)
    abort ();


  count++;

  __atomic_store (&v, &count, 0);
  if (v != count++)
    abort ();

  __atomic_store (&v, &count, 3);
  if (v != count++)
    abort ();

  __atomic_store (&v, &count, 5);
  if (v != count)
    abort ();


  return 0;
}







extern void abort(void);
unsigned char a;

int
main ()
{
  int b;

  __atomic_clear (&a, 0);
  if (a != 0)
    abort ();

  b = __atomic_test_and_set (&a, 5);
  if (a != 1 || b != 0)
    abort ();

  b = __atomic_test_and_set (&a, 4);
  if (a != 1 || b != 1)
    abort ();

  __atomic_clear (&a, 5);
  if (a != 0)
    abort ();

  return 0;
}

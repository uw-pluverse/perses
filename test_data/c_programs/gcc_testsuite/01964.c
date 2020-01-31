

static int test_var;





void not_inlinable() __attribute__((noinline));

static void
inlinable ()
{
  test_var = -10;
}

void
not_inlinable ()
{
  inlinable();
}

main ()
{
  test_var = 10;


  not_inlinable ();
  if (test_var == 10)
    abort ();
  return 0;
}

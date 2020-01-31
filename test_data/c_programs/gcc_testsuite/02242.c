




foo (int *p)
{
  *p = 10;
}

main()
{
  int *ptr = alloca (sizeof (int));
  *ptr = 5;
  foo (ptr);
  if (*ptr == 5)
    abort ();
  exit (0);
}

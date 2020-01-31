





double g()
{
  return 1.0;
}

f()
{
  char dummy[399999];
  double f1, f2, f3;
  f1 = g();
  f2 = g();
  f3 = g();
  return f1 + f2 + f3;
}

main()
{
  if (f() != 3.0)
    abort();
  exit(0);
}

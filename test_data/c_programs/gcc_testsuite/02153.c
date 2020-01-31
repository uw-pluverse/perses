






static long double
test_isunordered(long double x, long double y, long double a, long double b)
{
  return __builtin_isunordered(x, y) ? a : b;
}

static long double
test_not_isunordered(long double x, long double y, long double a, long double b)
{
  return !__builtin_isunordered(x, y) ? a : b;
}

static long double
test_isless(long double x, long double y, long double a, long double b)
{
  return __builtin_isless(x, y) ? a : b;
}

static long double
test_not_isless(long double x, long double y, long double a, long double b)
{
  return !__builtin_isless(x, y) ? a : b;
}

static long double
test_islessequal(long double x, long double y, long double a, long double b)
{
  return __builtin_islessequal(x, y) ? a : b;
}

static long double
test_not_islessequal(long double x, long double y, long double a, long double b)
{
  return !__builtin_islessequal(x, y) ? a : b;
}

static long double
test_isgreater(long double x, long double y, long double a, long double b)
{
  return __builtin_isgreater(x, y) ? a : b;
}

static long double
test_not_isgreater(long double x, long double y, long double a, long double b)
{
  return !__builtin_isgreater(x, y) ? a : b;
}

static long double
test_isgreaterequal(long double x, long double y, long double a, long double b)
{
  return __builtin_isgreaterequal(x, y) ? a : b;
}

static long double
test_not_isgreaterequal(long double x, long double y, long double a, long double b)
{
  return !__builtin_isgreaterequal(x, y) ? a : b;
}

static long double
test_islessgreater(long double x, long double y, long double a, long double b)
{
  return __builtin_islessgreater(x, y) ? a : b;
}

static long double
test_not_islessgreater(long double x, long double y, long double a, long double b)
{
  return !__builtin_islessgreater(x, y) ? a : b;
}

static void
one_test(long double x, long double y, int expected,
         long double (*pos) (long double, long double, long double, long double),
  long double (*neg) (long double, long double, long double, long double))
{
  if (((*pos)(x, y, 1.0, 2.0) == 1.0) != expected)
    abort ();
  if (((*neg)(x, y, 3.0, 4.0) == 4.0) != expected)
    abort ();
}




int
main()
{
  struct try
  {
    long double x, y;
    int result[6];
  };

  static struct try const data[] =
  {
    { (0.0 / 0.0), (0.0 / 0.0), { 1, 0, 0, 0, 0, 0 } },
    { 0.0, (0.0 / 0.0), { 1, 0, 0, 0, 0, 0 } },
    { (0.0 / 0.0), 0.0, { 1, 0, 0, 0, 0, 0 } },
    { 0.0, 0.0, { 0, 0, 1, 0, 1, 0 } },
    { 1.0, 2.0, { 0, 1, 1, 0, 0, 1 } },
    { 2.0, 1.0, { 0, 0, 0, 1, 1, 1 } },
    { (1.0 / 0.0), 0.0, { 0, 0, 0, 1, 1, 1 } },
    { 1.0, (1.0 / 0.0), { 0, 1, 1, 0, 0, 1 } },
    { (1.0 / 0.0), (1.0 / 0.0), { 0, 0, 1, 0, 1, 0 } },
    { 0.0, -(1.0 / 0.0), { 0, 0, 0, 1, 1, 1 } },
    { -(1.0 / 0.0), 1.0, { 0, 1, 1, 0, 0, 1 } },
    { -(1.0 / 0.0), -(1.0 / 0.0), { 0, 0, 1, 0, 1, 0 } },
    { (1.0 / 0.0), -(1.0 / 0.0), { 0, 0, 0, 1, 1, 1 } },
    { -(1.0 / 0.0), (1.0 / 0.0), { 0, 1, 1, 0, 0, 1 } },
  };

  struct test
  {
    long double (*pos)(long double, long double, long double, long double);
    long double (*neg)(long double, long double, long double, long double);
  };

  static struct test const tests[] =
  {
    { test_isunordered, test_not_isunordered },
    { test_isless, test_not_isless },
    { test_islessequal, test_not_islessequal },
    { test_isgreater, test_not_isgreater },
    { test_isgreaterequal, test_not_isgreaterequal },
    { test_islessgreater, test_not_islessgreater }
  };

  const int n = sizeof(data) / sizeof(data[0]);
  int i, j;

  for (i = 0; i < n; ++i)
    for (j = 0; j < 6; ++j)
      one_test (data[i].x, data[i].y, data[i].result[j],
  tests[j].pos, tests[j].neg);

  exit (0);
}


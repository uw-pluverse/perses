











double __attribute__((sseregparm))
test_noneg_add_noneg_add (double a, double b, double c)
{
  return ((a * b) + c) * a + c;
}

double __attribute__((sseregparm))
test_noneg_add_noneg_sub (double a, double b, double c)
{
  return ((a * b) + c) * a - c;
}

double __attribute__((sseregparm))
test_noneg_add_neg_add (double a, double b, double c)
{
  return -((a * b) + c) * a + c;
}

double __attribute__((sseregparm))
test_noneg_add_neg_sub (double a, double b, double c)
{
  return -((a * b) + c) * a - c;
}

double __attribute__((sseregparm))
test_noneg_sub_noneg_add (double a, double b, double c)
{
  return ((a * b) - c) * a + c;
}

double __attribute__((sseregparm))
test_noneg_sub_noneg_sub (double a, double b, double c)
{
  return ((a * b) - c) * a - c;
}

double __attribute__((sseregparm))
test_noneg_sub_neg_add (double a, double b, double c)
{
  return -((a * b) - c) * a + c;
}

double __attribute__((sseregparm))
test_noneg_sub_neg_sub (double a, double b, double c)
{
  return -((a * b) - c) * a - c;
}

double __attribute__((sseregparm))
test_neg_add_noneg_add (double a, double b, double c)
{
  return (-(a * b) + c) * a + c;
}

double __attribute__((sseregparm))
test_neg_add_noneg_sub (double a, double b, double c)
{
  return (-(a * b) + c) * a - c;
}

double __attribute__((sseregparm))
test_neg_add_neg_add (double a, double b, double c)
{
  return -(-(a * b) + c) * a + c;
}

double __attribute__((sseregparm))
test_neg_add_neg_sub (double a, double b, double c)
{
  return -(-(a * b) + c) * a - c;
}

double __attribute__((sseregparm))
test_neg_sub_noneg_add (double a, double b, double c)
{
  return (-(a * b) - c) * a + c;
}

double __attribute__((sseregparm))
test_neg_sub_noneg_sub (double a, double b, double c)
{
  return (-(a * b) - c) * a - c;
}

double __attribute__((sseregparm))
test_neg_sub_neg_add (double a, double b, double c)
{
  return -(-(a * b) - c) * a + c;
}

double __attribute__((sseregparm))
test_neg_sub_neg_sub (double a, double b, double c)
{
  return -(-(a * b) - c) * a - c;
}


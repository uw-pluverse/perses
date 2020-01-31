











float __attribute__((sseregparm))
test_noneg_add_noneg_add (float a, float b, float c)
{
  return ((a * b) + c) * a + c;
}

float __attribute__((sseregparm))
test_noneg_add_noneg_sub (float a, float b, float c)
{
  return ((a * b) + c) * a - c;
}

float __attribute__((sseregparm))
test_noneg_add_neg_add (float a, float b, float c)
{
  return -((a * b) + c) * a + c;
}

float __attribute__((sseregparm))
test_noneg_add_neg_sub (float a, float b, float c)
{
  return -((a * b) + c) * a - c;
}

float __attribute__((sseregparm))
test_noneg_sub_noneg_add (float a, float b, float c)
{
  return ((a * b) - c) * a + c;
}

float __attribute__((sseregparm))
test_noneg_sub_noneg_sub (float a, float b, float c)
{
  return ((a * b) - c) * a - c;
}

float __attribute__((sseregparm))
test_noneg_sub_neg_add (float a, float b, float c)
{
  return -((a * b) - c) * a + c;
}

float __attribute__((sseregparm))
test_noneg_sub_neg_sub (float a, float b, float c)
{
  return -((a * b) - c) * a - c;
}

float __attribute__((sseregparm))
test_neg_add_noneg_add (float a, float b, float c)
{
  return (-(a * b) + c) * a + c;
}

float __attribute__((sseregparm))
test_neg_add_noneg_sub (float a, float b, float c)
{
  return (-(a * b) + c) * a - c;
}

float __attribute__((sseregparm))
test_neg_add_neg_add (float a, float b, float c)
{
  return -(-(a * b) + c) * a + c;
}

float __attribute__((sseregparm))
test_neg_add_neg_sub (float a, float b, float c)
{
  return -(-(a * b) + c) * a - c;
}

float __attribute__((sseregparm))
test_neg_sub_noneg_add (float a, float b, float c)
{
  return (-(a * b) - c) * a + c;
}

float __attribute__((sseregparm))
test_neg_sub_noneg_sub (float a, float b, float c)
{
  return (-(a * b) - c) * a - c;
}

float __attribute__((sseregparm))
test_neg_sub_neg_add (float a, float b, float c)
{
  return -(-(a * b) - c) * a + c;
}

float __attribute__((sseregparm))
test_neg_sub_neg_sub (float a, float b, float c)
{
  return -(-(a * b) - c) * a - c;
}






unsigned long int __attribute__ ((aligned (64)))arr[100];
int i;

void negative_test_for_vectorshifts_via_mul_with_const ()
{
  for (i=0; i<=99; i++)
    arr[i] = arr[i] * 123;
}

void negative_test_for_vectorshifts_via_mul_with_negative_const ()
{
  for (i=0; i<=99; i++)
    arr[i] = arr[i] * (-123);
}

void negative_test_for_vectorshifts_via_mul_with_varable (int x)
{
  for (i=0; i<=99; i++)
    arr[i] = arr[i] * x;
}

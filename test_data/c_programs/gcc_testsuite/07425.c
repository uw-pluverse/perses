



unsigned long int __attribute__ ((aligned (64)))arr[100];
int i;

void test_for_vectorshifts_via_mul_with_power2_const ()
{
  for (i=0; i<=99; i++)
    arr[i] = arr[i] * 4;
}

void test_for_vectorshifts_via_mul_with_negative_power2_const ()
{
  for (i=0; i<=99; i++)
    arr[i] = arr[i] * (-4);
}

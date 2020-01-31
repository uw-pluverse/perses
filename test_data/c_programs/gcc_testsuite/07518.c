

extern void abort (void);



int a[128];

int main1 (int res0, int res1)
{
  int i;
  int sum0 = 0, sum1 = 0;

  for (i = 0; i < 128/2; i++) {
    sum1 += a[2*i];
    sum0 += a[2*i];
  }


  if (sum0 != res0
      || sum1 != res1)
    abort ();

  return 0;
}

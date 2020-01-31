


int a[1000], b[1000];

void test(void)
{
  int i;

  for (i = 1; i < 999; i++)
    b[i] = (a[i + 1] + a[i] + a[i - 1]) / 3;
}

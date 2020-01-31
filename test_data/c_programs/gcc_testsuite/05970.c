




void abort (void);

int a[1000], b[1000], c[1000];

int main(void)
{
  int i;

  for (i = 0; i < 1000; i++)
    a[i] = b[i] = i;

  for (i = 1; i < 998; i++)
    c[i] = a[i + 2] * b[i + 1] - b[i - 1] * a[i];

  for (i = 1; i < 998; i++)
    if (c[i] != 4 * i + 2)
      abort ();

  return 0;
}

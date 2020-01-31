




extern void abort (void);

int main(void)
{
  double arr[1000];
  double a, b;

  int i;

  for (i = 0; i < 1000; i++)
    arr[i] = 4294967296.0 + (double)i;

  a = arr[0];
  b = (unsigned int)((unsigned long long int)a % 4294967296ULL);

  if (b >= 4294967296.0)
    abort ();

  return 0;
}

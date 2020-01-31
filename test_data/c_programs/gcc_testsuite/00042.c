



unsigned int a[1024] __attribute__((aligned (32)));

__attribute__((noinline, noclone)) void
foo (int j)
{
  int i;
  for (i = 0; i < 1024; i++)
    a[i] = (a[i] << j) | (a[i] >> ((-j) & 31));
}

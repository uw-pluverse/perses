






int test0(void)
{
  __attribute__((vector_size(16) )) int a;
  return a[10];
}

int test1(void)
{
  __attribute__((vector_size(16) )) int a;
  return a[-1];
}

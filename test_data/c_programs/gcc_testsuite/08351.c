






int test1 (void)
{
  return * (volatile int *) 0x1234;
}

int test2 (void)
{
  int local = * (volatile int *) 0x1234;
  return local;
}

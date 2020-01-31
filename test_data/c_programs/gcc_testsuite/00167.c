

int data[4096];

int
f (void)
{
  return (((unsigned long) &data[0]) == 0xdeadbea0U);
}

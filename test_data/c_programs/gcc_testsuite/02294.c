struct foo
{
  unsigned long long b:40;
} x;

extern void abort (void);

void test1(unsigned long long res)
{

  if (x.b<<32 != res)
    abort ();
}

int main()
{
  x.b = 0x0100;
  test1(0);
  return 0;
}

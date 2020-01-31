







extern void abort();

void f(unsigned short ad)
{
  if ((short) (ad - 0x4000) >= 0)
    abort();
}

int main(void)
{
  f(0xc000);
  return 0;
}








extern void abort(void);

void f(unsigned short ad)
{
  if (ad >= 0x4000 && ad < 0xc000)
    abort();
}

int main(void)
{
  f(0xff00);
  return 0;
}

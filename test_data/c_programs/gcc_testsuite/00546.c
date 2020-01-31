static inline unsigned int shift(int n, unsigned int value)
{
  return value << n;
}

unsigned int val = 1;

int main(void)
{
  int i;

  for (i = 0; i < 4; i++)
    val = shift(32, val);

  return 0;
}

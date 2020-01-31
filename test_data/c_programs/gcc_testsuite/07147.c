


int main (void)
{
  int a = -1;
  int b = 2147483647;
  int c = 2;
  int t = 1 - ((a - b) / c);
  if (t != (1 - (-1 - 2147483647) / 2))
    __builtin_abort();
  return 0;
}

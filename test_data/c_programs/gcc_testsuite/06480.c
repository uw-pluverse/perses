


int main ()
{
  int a = 0;
  int b = 2147483647;
  int t = (a - 2) > (b - 1);
  if (t != 0)
    __builtin_abort();
  return 0;
}

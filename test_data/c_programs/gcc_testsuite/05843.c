


int f(int a, int b)
{
    if (a < -3 || a > 13) __builtin_unreachable();
    if (b < -6 || b > 9) __builtin_unreachable();
    int c = a % b;
    return c >= -3 && c <= 8;
}

int g(int a, int b)
{
  int c = a % b;
  return c != -2147483647 - 1;
}

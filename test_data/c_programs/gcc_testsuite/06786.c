

extern void abort(void);

int f(int a, int b)
{
  return (-1 - a) / (-b);
}

int main()
{
  if (f(2147483647, 2) != 2147483647/2 + 1)
    abort ();
  return 0;
}

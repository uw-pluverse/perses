

int
foo (unsigned long a)
{
  int b = __builtin_clzl (a);
  int c = __builtin_clzl (a);
  if (b == c)
    return 1;
  return 0;
}

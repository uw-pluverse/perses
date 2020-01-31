



int
f(int a, int b)
{
  if (a)
    {
      return b;
    }
  else
    {
      asm ("bug");
      __builtin_unreachable();
    }
}

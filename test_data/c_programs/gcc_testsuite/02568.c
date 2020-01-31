




typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

struct two { long x, y; };

void foo(int a, int b, int c, int d, int e, struct two f, int g, ...)
{
  va_list args;
  int h;

  __builtin_va_start(args, g);
  h = __builtin_va_arg(args, int);
  if (g != 1 || h != 2)
    abort ();
}

int main()
{
  struct two t = { 0, 0 };
  foo(0, 0, 0, 0, 0, t, 1, 2);
  return 0;
}

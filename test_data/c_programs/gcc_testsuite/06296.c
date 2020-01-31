extern void abort(void);

int loo = 1;

__inline__ char InlineFunc(void)
{
  return __builtin_expect(!!(loo == 1), 1);
}

int FooBar(void)
{
  int i;
  int var1 = InlineFunc() ? 2046 : 1023;
  int var2 = InlineFunc() ? 512 : 1024;

  for (i = 0; i < var1; i++)
    ;

  if (InlineFunc() && var2 != 512)
    abort();

  return 0;
}

int main(void)
{
  return FooBar();
}

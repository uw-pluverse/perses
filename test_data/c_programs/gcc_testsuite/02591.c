

_Bool f(int a, _Bool c) __attribute__((noinline));
_Bool f(int a, _Bool c)
{
  if (!a)
    c = !c;
  return c;
}

void checkf(int a, _Bool b)
{
  _Bool c = f(a, b);
  char d;
  __builtin_memcpy (&d, &c, 1);
  if ( d != (a==0)^b)
    __builtin_abort();
}

int main(void)
{
  checkf(0, 0);
  checkf(0, 1);
  checkf(1, 1);
  checkf(1, 0);
  return 0;
}





int foo (int x)
{
  return __builtin_ffsl (x);
}

int bar (int x)
{
  return __builtin_clzl (x);
}

int baz (int x)
{
  return __builtin_ctzl (x);
}

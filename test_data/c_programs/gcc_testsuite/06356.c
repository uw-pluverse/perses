




extern void abort(void);

void f1(int p)
{
  if (p)
    __builtin_trap();
  else
    abort();
}

void f2(int p)
{
  if (p)
    abort();
  else
    __builtin_trap();
}

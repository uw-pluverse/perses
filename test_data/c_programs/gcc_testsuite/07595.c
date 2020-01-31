void f(void) __attribute__ ((__noreturn__));
void _exit(int status) __attribute__ ((__noreturn__));

int z = 0;

void g()
{
  if (++z > 10)
    _exit(0);
  g();
}

void f()
{
  if (++z > 10)
    _exit(0);
  f();
}

int h()
{
  if (++z > 10)
    _exit(0);
  return h();
}

int k()
{
  if (++z > 10)
    _exit(0);
  k();
}

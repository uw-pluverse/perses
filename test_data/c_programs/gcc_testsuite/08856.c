



typedef _Atomic int atomic_int;

atomic_int
fn1 (void)
{
  atomic_int y = 0;
  return y;
}

atomic_int
fn2 (void)
{
  atomic_int y = 0;
  y;
  return y;
}

atomic_int
fn3 (void)
{
  atomic_int y = 0;
  y++;
  return y;
}

void
fn4 (void)
{
  atomic_int y;
  y = 0;
  (void) y;
}

void
fn5 (void)
{
  atomic_int y = 0;
}

void
fn6 (void)
{
  atomic_int y;
  y = 0;
}

void
fn7 (void)
{
  atomic_int y = 0;
  y++;
}

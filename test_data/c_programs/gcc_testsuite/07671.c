



__attribute__ ((noinline))
__attribute__ ((always_inline))
int
fn1 (int r)
{
  return r & 4;
}

__attribute__ ((noinline, always_inline))
int
fn2 (int r)
{
  return r & 4;
}

__attribute__ ((always_inline))
__attribute__ ((noinline))
inline int
fn3 (int r)
{
  return r & 8;
}

__attribute__ ((always_inline, noinline))
inline int
fn4 (int r)
{
  return r & 8;
}





_Bool
fn1 (unsigned int p)
{
  return 0ULL > p;
}

_Bool
fn2 (unsigned int p)
{
  return 0ULL <= p;
}

_Bool
fn3 (unsigned int p)
{
  return p >= 0U;
}

_Bool
fn4 (unsigned int p)
{
  return p < 0U;
}

_Bool
fn5 (_Bool p)
{
  return p || !p;
}

_Bool
fn6 (_Bool p)
{
  return p && !p;
}

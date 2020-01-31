


int
fn1 (int x)
{
  return ~x | x;
}

int
fn2 (int x)
{
  return x | ~x;
}

unsigned int
fn3 (unsigned int x)
{
  return ~x | x;
}

unsigned int
fn4 (unsigned int x)
{
  return x | ~x;
}

int
fn5 (int x)
{
  return ~x | (unsigned) x;
}

int
fn6 (int x)
{
  return (unsigned) ~x | x;
}

int
fn7 (int x)
{
  return ~(unsigned) x | x;
}

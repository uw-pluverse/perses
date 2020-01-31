


unsigned int b;

unsigned int
fn1 (unsigned int d)
{
  int i;

  for (i = 0; i < 1000; i++)
    b |= d;

  return b;
}

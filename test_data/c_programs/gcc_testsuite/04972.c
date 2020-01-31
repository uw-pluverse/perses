


unsigned char
fn1 (unsigned char a)
{
  return a >> ~6;
}

unsigned short
fn2 (unsigned short a)
{
  return a >> ~6;
}

unsigned int
fn3 (unsigned int a)
{
  return a >> ~6;
}

unsigned char
fn4 (unsigned char a)
{
  return a >> 0xff03;
}

unsigned short
fn5 (unsigned short a)
{
  return a >> 0xff03;
}

unsigned int
fn6 (unsigned int a)
{
  return a >> 0xff03;
}

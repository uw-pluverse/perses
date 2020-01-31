




int
f (int a, int b)
{
  return a + b;
}



int
f2 (int a, int b, int c)
{
  return b + c;
}


int
g1 (int a)
{
  return a + 255;
}



int
g2 (int a)
{
  return a + 256;
}



int
g3 (int a)
{
  return a - 255;
}



int
g4 (int a)
{
  return a - 256;
}



int
h1 (int a, int b)
{
  return b + 7;
}



int
h2 (int a, int b)
{
  return b + 8;
}



int
h3 (int a, int b)
{
  return b - 7;
}



int
h4 (int a, int b)
{
  return b - 8;
}



int
i (int a, int b)
{
  return b;
}



int
j1 ()
{
  return 255;
}



int
j2 ()
{
  return 256;
}



int
k (int a, int b)
{
  return b << 15;
}



int
l1 (int a, int b)
{
  return a << b;
}



int
l2 (int a, int b, int c)
{
  return b << c;
}



int
m (int a, int b)
{
  return b >> 15;
}



int
n1 (int a, int b)
{
  return a >> b;
}



int
n2 (int a, int b, int c)
{
  return b >> c;
}



unsigned int
o (unsigned int a, unsigned int b)
{
  return b >> 15;
}



unsigned int
p1 (unsigned int a, unsigned int b)
{
  return a >> b;
}



unsigned int
p2 (unsigned int a, unsigned int b, unsigned int c)
{
  return b >> c;
}



int
q (int a, int b)
{
  return b * a;
}



int
r (int a, int b)
{
  return ~b;
}



int
s (int a, int b)
{
  return -b;
}

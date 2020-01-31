

struct Q
{
  long x:20;
  long y:4;
  long z:8;
}b;

void rotins (unsigned int x)
{
  b.y = (x<<12) | (x>>20);
}

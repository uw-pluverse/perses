unsigned int f (volatile unsigned int *u, unsigned int u2)
{
  *u = u2;
  return *u;
}

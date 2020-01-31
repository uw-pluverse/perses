


int f[100];
int g[100];
unsigned char
f1 (int a, int b)
{
  long unsigned int ix;
  if (a)
    return 1;
  for (ix = 4; ix--;)
      if (f[ix] != g[ix])
   return 0;
  return 1;
}

int main(void)
{
  if (!f1 (0, 2))
    __builtin_abort();
  return 0;
}




char a[32];
char b[32];
char c[32];

void test()
{
  int i = 0;
  for (i = 0; i < 32; i++)
    if (b[i] > 0)
      a[i] = c[i];
}

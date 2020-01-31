



unsigned char a[1024], b[1024], c[1024];

void f1(void)
{
  int i;
  for (i = 0; i < 1024; ++i)
    a[i] = b[i] * c[i];
}

void f2(void)
{
  int i;
  for (i = 0; i < 1024; ++i)
    a[i] = b[i] * 2;
}

void f3(void)
{
  int i;
  for (i = 0; i < 1024; ++i)
    a[i] = b[i] * 20;
}

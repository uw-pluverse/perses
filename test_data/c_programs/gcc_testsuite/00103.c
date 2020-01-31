


unsigned short b[1024] = { 0 };
int a[1024] = { 0 };

int
f1 (int x)
{
  int i;
  for (i = 0; i < 1024; i++)
    a[i] = (b[i] + 7) / 15;
}

int
f2 (int x)
{
  int i;
  for (i = 0; i < 1024; i++)
    a[i] = (b[i] + 7) % 15;
}

int
f3 (int x)
{
  int i;
  for (i = 0; i < 1024; i++)
    a[i] = (b[i] - 66000) / 15;
}

int
f4 (int x)
{
  int i;
  for (i = 0; i < 1024; i++)
    a[i] = (b[i] - 66000) % 15;
}

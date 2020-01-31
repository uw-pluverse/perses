




float res[1024], data[1025];

void foo (void)
{
  int i;
  for (i = 0; i < 1024; ++i)
    res[i] = data[i] + data[i + 1];
}

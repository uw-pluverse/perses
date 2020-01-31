




void bar (float);

void foo (float y, unsigned long z)
{
  int b;
  float c = y;

  for (b = 0; b < z; b++)
    {
      bar (c);
      if (c == y)
 c = -y;
      else
 c = y;
    }
}

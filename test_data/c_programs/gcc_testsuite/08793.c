



int Foo (int X)
{
  if (X < 0)
    X = 0;
  if (X > 191)
    X = 191;

  return X << 23;
}

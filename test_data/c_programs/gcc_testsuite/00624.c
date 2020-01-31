


int
f255 (int x)
{
  if (x & 255)
    return 1;
  return x;
}

int
f65535 (int x)
{
  if (x & 65535)
    return 1;
  return x;
}

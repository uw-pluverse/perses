







int
fooctz (int i)
{
  return (i == 0) ? 32 : __builtin_ctz (i);
}

int
fooctz2 (int i)
{
  return (i != 0) ? __builtin_ctz (i) : 32;
}

unsigned int
fooctz3 (unsigned int i)
{
  return (i > 0) ? __builtin_ctz (i) : 32;
}



int
fooclz (int i)
{
  return (i == 0) ? 32 : __builtin_clz (i);
}

int
fooclz2 (int i)
{
  return (i != 0) ? __builtin_clz (i) : 32;
}

unsigned int
fooclz3 (unsigned int i)
{
  return (i > 0) ? __builtin_clz (i) : 32;
}

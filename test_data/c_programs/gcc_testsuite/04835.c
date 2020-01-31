



typedef char char4[4] __attribute__ ((aligned (4)));
char4 c4[4] __attribute__ ((aligned (16)));

typedef char char16[16] __attribute__ ((aligned (16)));
char16 c16[4] __attribute__ ((aligned (4)));

int f1 (void)
{

  return 15 & (long unsigned int)&c4[3];
}

int f2 (int i)
{

  return 15 & (long unsigned int)&c4[i];
}

int f3 (int i)
{

  return 3 & (long unsigned int)&c4[i];
}

int f4 (int i)
{

  return 7 & (long unsigned int)&c16[i];
}

int f5 (int i)
{

  return 3 & (long unsigned int)&c16[i];
}

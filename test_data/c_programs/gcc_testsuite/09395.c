


extern void abort (void);

char *
foo (int count, char **list)
{
  char *minaddr = list[0];
  int i;

  for (i = 0; i < count; i++)
    {
      char *addr = list[i];
      if (addr < minaddr)
 minaddr = addr;
    }

  return minaddr;
}

char *
foo2 (int count, char **list)
{
  char *maxaddr = list[0];
  int i;

  for (i = 0; i < count; i++)
    {
      char *addr = list[i];
      if (addr > maxaddr)
 maxaddr = addr;
    }

  return maxaddr;
}

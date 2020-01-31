


extern int global;

int bar (int);

void foo (int base, int bound)
{
  int i, ret = 0;
  for (i = base; i <= bound; i++)
    {
      if (i > base)
 global += bar (i);
      if (i > base + 1)
 global += bar (i);
      if (i >= base + 3)
 global += bar (i);
      if (i - 2 >= base)
 global += bar (i);
    }
}




extern int global;

int bar(int);

void foo (int bound)
{
  int i, ret = 0;
  for (i = 0; i < bound; i++)
    {
      if (i > bound)
 global += bar (i);
      if (i >= bound + 2)
 global += bar (i);
      if (i > bound - 2)
 global += bar (i);
      if (i + 2 > bound)
 global += bar (i);
      if (i == 10)
 global += bar (i);
    }
}

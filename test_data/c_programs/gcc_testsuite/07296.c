


extern int global;

int bar(int);

void foo (int bound)
{
  int i, ret = 0;
  for (i = 0; i < 10; i++)
    {
      if (i < 5)
 global += bar (i);
    }
}




int bar(void *);

void foo (void *p)
{
  int i = 1;
  while (i)
    i = bar (p);
}





int bar (int);
int cal (void *);

int
foo (int a, int bound)
{
  int i = 0;
  int sum = 0;

  for (i; i < bound; i++)
    sum = cal (bar);

  return sum;
}

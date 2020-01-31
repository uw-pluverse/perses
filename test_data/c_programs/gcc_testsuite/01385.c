



void foo (int *);
int *bar (int, long long, int);

void
test (int *p)
{
  if (p)
    foo (p);
  else if (p = bar (0, 1, 2))
    foo (p);
}

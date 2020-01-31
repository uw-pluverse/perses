
int glob;

void
foo (int a, int b, volatile int * bar)
{
  if (a < b)
    glob = *bar;
}

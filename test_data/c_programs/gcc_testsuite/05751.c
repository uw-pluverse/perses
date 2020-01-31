

int *gp;
int foo(int p)
{
  int t = 0;
  if (p)
    t = *gp + 1;

  return (*gp + t);
}

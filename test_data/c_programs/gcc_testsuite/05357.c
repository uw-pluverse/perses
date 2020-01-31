


int g, h;

int
foo (int a)
{
  int *p;

  if (a)
    p = &g;
  else
    p = &h;

  if (p != 0)
    return 1;
  else
    return 0;
}

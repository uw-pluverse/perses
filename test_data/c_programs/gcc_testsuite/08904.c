


int foo (int *p1, int *p2);

int
test (int *p1, int *p2)
{
  int *p;

  for (p = p2; p != 0; p++)
    {
      if (!foo (p, p1))
        return 0;
    }

  return 1;
}

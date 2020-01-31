

void
foo (int a, int b)
{
  switch (a)
    {
      { int c; }
      { int d; }
      { int e; }
      b++;
    case 1:
      break;
    }

  switch (a)
    {
      { int c; }
      { int d = 1; }
      { int e; }
      b++;
    case 1:
      break;
    }
}

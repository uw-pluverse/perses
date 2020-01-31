



enum e { e1 = 0, e2 = 1, e3 = 1, e4 = 2 };

int
foo (enum e ei, int j)
{
  switch (ei)
    {
    case e1: return 1;
    case e3: return 2;
    case e4: return 3;
    }
  switch (ei)
    {
    case e1: return 1;
    case e2: return 2;
    }
  switch ((int) ei)
    {
    case e1: return 1;
    }
  switch ((enum e) j)
    {
    case e2: return 1;
    case e4: return 2;
    }
  return 0;
}

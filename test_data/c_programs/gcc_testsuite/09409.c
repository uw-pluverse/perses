



static inline void
bar (int i)
{
  (void) i;
}

int
foo (int *begin, int *end)
{
  int s = 0;
  int *i;
  for (i = begin; i != end; ++i)
    {
      bar (0);
      if (begin)
 return s;
    }
  return 0;
}

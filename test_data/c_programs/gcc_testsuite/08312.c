


int
f (int i, int j)
{
  unsigned int c = 0;
  if (i < j)
    {
      unsigned int n = j - i;
      unsigned int i;
      for (i = 0; i < n; i++)
 c++;
    }
  return c;
}

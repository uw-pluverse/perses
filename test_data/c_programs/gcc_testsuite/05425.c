



void
f1 (int *p, unsigned int i)
{
  p += i;
  do
    {
      *p = 0;
      p += 1;
      i++;
    }
  while (i < 100);
}

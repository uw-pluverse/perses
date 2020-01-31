


int
foo (int *p, int i)
{
  int x;

  if (i > 10)
    {
      if (p)
 {
   x = *p;
   p = 0;
 }
    }
  else
    p = 0;



  if (p == 0)
    return x + 1;

  return i;
}

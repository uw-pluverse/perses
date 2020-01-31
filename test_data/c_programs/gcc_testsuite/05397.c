


int
foo (int i, int *p)
{
  int j;

  if (i > 10)
    {
      if (p)
 {
   j = *p;



   if (p)
     return j + 1;
 }
    }
  else
    {
      j = *p - 3;



      if (!p)
 return j - 4;
    }

  return i;
}

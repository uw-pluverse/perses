



void
foo (int unit)
{
  int i;

  for (i = 0; unit; i++, unit--)
    {
      if (i >= 0)
 {
   int j = i;
   while (j)
     j--;
 }
    }
}

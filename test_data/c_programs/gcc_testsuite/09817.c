





extern void _gfortran_abort ();

void foo (void)
{
  int i, m;
  float xa[21];

  m = 0;
  while (1)
    {
      i = 0;
      while (1)
 {
   if (xa[(long int)i] == xa[(long int)(i+m)])
     _gfortran_abort ();
   if (i == 10)
     break;
   i++;
 }
      if (m == 10)
 break;
      m++;
    }
}

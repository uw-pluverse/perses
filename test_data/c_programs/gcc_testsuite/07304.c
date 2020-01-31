


int
foo (int ko)
{
 int j,i = 0;
  for (j = 0; j < ko; j++)
   i += (i > 10) ? -5 : 7;
 return i;
}

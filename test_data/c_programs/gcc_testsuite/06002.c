


int
foo (unsigned int n)
{
  int i, r = 1;
  if (n > 0)
    {
      asm ("");
      if (n < 10)
 {
   asm ("");
   do
     {
       --n;
       r *= 2;
     }
   while (n > 0);
 }
    }
  return r + n;
}

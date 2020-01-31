


double g;

int foo(char *flags, long len, long i, long steps)
{
  register long step, iter;

  if(*(flags + i))
    {
      step = i + i + 3;
      for(iter = i + step ; iter <= len ; iter += step)
 {
   steps++;
   *(flags + iter)=0;
 }
    }
   g = 5.0*(double)steps;

   return 0;
}

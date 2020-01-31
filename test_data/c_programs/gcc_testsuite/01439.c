



int foo(int *p, int i)
{
  return( (i < 0 && *p == 1)
   || (i > 0 && *p == 2) );
}

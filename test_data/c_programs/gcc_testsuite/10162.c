


int a[2];
int foo (int q)
{
  if (__builtin_constant_p (q))
    {
      if (q == 4)
 return a[4];
      else
 return a[0];
    }
  else
    return a[q];
}

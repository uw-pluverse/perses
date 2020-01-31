


void bar (void);
int foo (int i, int j)
{
  int res = 1;
  if (i < j)
    {


      if (i > j)
 res = 0;
    }

  if (res)
    return i;
  return j;
}

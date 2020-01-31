





int foo(int p, int* q)
{
  if (p!=9)
    *q = 0;
  else
    *(q+1) = 0;
  return 3;
}

extern void bar(int*);

int t1, t2, t3, t4, t5;
int foo()
{
  int i,j,k,x = 0;
  for (i = 0; i < t1; i++)
    for (j = 0; j < t2; j++)
   bar(&x);
  return x;
}

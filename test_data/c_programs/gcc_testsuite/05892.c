


extern int status, pt;
extern int count;
void
foo (int N, int c, int b, int *a)
{
  int i, flag;
  i = b -1;
  flag = 1;
  if (status && i < N && a[i] == b) {
    N--;
    flag = 0;
   if (pt)
     count++;
  }
  else
    for (i = -1, flag = 1; ++i < N && flag;)
      if (a[i] == b)
        {
          --N;
          flag = 0;
          if (i < N)
            a[i] = a[N];
           else
            a[i] = 0;
          if (pt)
            count++;
        }
 if(status && flag)
   pt--;
}

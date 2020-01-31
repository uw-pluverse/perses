


extern void bar(int);

void foo (int n)
{
  int i;

 for (i = 0; i < n; ++i)
    bar(i);
}

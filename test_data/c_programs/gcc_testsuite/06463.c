





void do_something ();

void f (int m, int n)
{
  int j;

  for (j = m; j < m + 10 && j < n; j ++)
    do_something (j);
}

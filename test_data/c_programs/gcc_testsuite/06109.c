


char x[100000];

void foo(int n)
{
  int i;

  for (i = 0; i < n; i++)
    x[i] = (char) i;
}

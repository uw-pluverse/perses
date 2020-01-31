


void bar(char *p, int n)
{
  int i;
  for (i = 1; i < n; i++)
    p[i-1] = p[i];
}

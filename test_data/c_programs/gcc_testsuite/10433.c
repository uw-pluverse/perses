

struct a {int a[7];};
int t(struct a *a, int n)
{
  int i;
  for (i=0;i<n;i++)
    a->a[i]++;
}

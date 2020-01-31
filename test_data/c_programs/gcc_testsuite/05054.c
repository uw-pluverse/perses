

struct a {int a[100];};
void
t(struct a *a)
{
  for (int i=0;i<5 && a->a[i];i++)
    a->a[i]++;
}

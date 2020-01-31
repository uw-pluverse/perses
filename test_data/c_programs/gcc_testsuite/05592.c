

struct a {int a[8];int b;};
void
t(struct a *a)
{
  for (int i=0;a->a[i];i++)
    a->a[i]++;
}

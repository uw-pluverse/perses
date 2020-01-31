

struct foo {int b; int a[3];} foo;
void add(struct foo *a,int l)
{
  int i;
  for (i=0;i<l;i++)
    a->a[i]++;
}

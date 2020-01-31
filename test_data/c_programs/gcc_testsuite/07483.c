

struct a
{
  int a[100];
};
typedef struct a b __attribute__ ((aligned (32)));
typedef struct a c __attribute__ ((aligned (4)));

int t(b *a)
{
  int i;
  c *ptr = a;
  for (i=0;i<100;i++)
    ptr->a[i]++;
}

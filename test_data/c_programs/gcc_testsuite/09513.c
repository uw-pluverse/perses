



extern float a[], b[], c[], d[];
extern int k[];

void
foo (void)
{
  int i;
  for (i = 0; i < 1024; ++i)
    k[i] = (a[i] < b[i]) | (c[i] < d[i]);
}





extern int a[1024], b[1024], k, l, m;

void
foo ()
{
  int i;
 for (i = 0; i < 1024; i++)
    a[i] *= b[i];
}

void
bar (int *p)
{
  int i;
 for (i = 0; i < 1024; i++)
    a[i] *= p[i], k += m + 1;
}

void
baz (int *p)
{
 for (int i = 0; i < 1024; i++)
    a[i] *= p[i], k += m + 1;
}

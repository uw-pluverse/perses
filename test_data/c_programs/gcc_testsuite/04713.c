





typedef long unsigned int size_t;
void *malloc (size_t);
void free (void *);






void
foo (void)
{
  unsigned int *a = (unsigned int *)malloc (2 * sizeof (unsigned int));
  unsigned int *b = a;
  unsigned int *c = (unsigned int *)malloc (2 * sizeof (unsigned int));

 {
    a[0] = 0;
    b[0] = 1;
    c[0] = a[0];
  }

  free (a);
  free (c);
}

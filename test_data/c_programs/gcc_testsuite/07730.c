


typedef int V __attribute__ ((vector_size (8 * sizeof (int))));

void
foo (V *p, V *q)
{
  *p = (*p == *q);
}

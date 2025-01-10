



typedef __attribute__ ((vector_size ((8) * sizeof (short)))) short V;

int k;
V v;

void
foo (void)
{
  V w = { k, k, k, k, k, k, k, k };
  V x = v >> w;
}

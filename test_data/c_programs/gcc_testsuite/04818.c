



void
foo (int *a, char *b, char *c)
{

  __builtin_memmove (c, b, a[c[0]]);

  __builtin_memmove (c, b, a[b[0]]);

  int d = c[0] == b[0];
}





void
foo (int *a, char *b, char *c)
{

  __builtin_memmove (c, b, a[0]);

  int d = a[0] == 0;
}

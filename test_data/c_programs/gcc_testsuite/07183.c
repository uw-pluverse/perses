



void
fn1 (char *b, char *d, int *c, int i)
{
  for (; i; i++, d++)
    if (b[i])
      *d = c[i];
}

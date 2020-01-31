





float a[256], b[256], c[256];

void opt3 (void) __attribute__((__optimize__(3)));

void
opt3 (void)
{
  int i;

  for (i = 0; i < 256; i++)
    a[i] = b[i] + c[i];
}

void
not_opt3 (void)
{
  int i;

  for (i = 0; i < 256; i++)
    a[i] = b[i] - c[i];
}

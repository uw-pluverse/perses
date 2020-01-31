





float a[256], b[256], c[256];

void non_opt3 (void) __attribute__((__optimize__(1)));

void
not_opt3 (void)
{
  int i;

  for (i = 0; i < 256; i++)
    a[i] = b[i] - c[i];
}

void
opt3 (void)
{
  int i;

  for (i = 0; i < 256; i++)
    a[i] = b[i] + c[i];
}

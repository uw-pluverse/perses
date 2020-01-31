




double _Complex *a;
static const double _Complex b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void
test (void)
{
  a[0] = b[0] + b[1];
  a[1] = b[0] + b[1];
  return;
}

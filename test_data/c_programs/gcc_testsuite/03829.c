

int *a, b, c, d;

void
foo (void)
{
  for (; d <= 0; d++)
    b &= ((a || d) ^ c) == 1;
}

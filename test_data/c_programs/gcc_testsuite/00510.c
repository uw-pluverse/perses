






unsigned int a, b;

int
foo (void)
{
  if (a == b) return 1;
  if (a > b) return 2;
  if (a < b) return 3;
  if (a != b) return 4;
  return 0;
}

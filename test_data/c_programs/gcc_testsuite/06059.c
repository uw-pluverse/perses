





int
main (int argc, char **argv)
{
  int a[8];
  for (int i = 0; i < 8; i++)
    a[i] = 2*i + 1;
  int *p = &a[0];
  __builtin_printf ("%d\n", a[argc]);
  return *(++p);
}

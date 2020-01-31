



int
main (int argc, char **argv)
{
  union {
    int a[4];
    int b[2];
  } u;
  u.a[0] = 1;
  u.a[1] = 42;
  u.a[2] = 3;
  u.a[3] = 4;
  __builtin_printf ("%d\n", u.a[argc]);
  return u.b[1];
}

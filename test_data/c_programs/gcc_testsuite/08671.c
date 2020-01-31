


int a[2];
static int *b = &a[0], *c = &a[1];

int
main ()
{
  *c = 1;
  *b = 0;

  if (a[1] != 1)
    __builtin_abort ();

  return 0;
}

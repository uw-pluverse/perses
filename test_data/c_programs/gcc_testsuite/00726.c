




void abort ();
int global_a;

int
initialize (void)
{
  global_a = 0x10;
  return global_a - 1;
}

int
main (int argc, char **argv)
{
  int a = initialize ();

  if (a != global_a - 1)
    abort ();

  return 0;
}

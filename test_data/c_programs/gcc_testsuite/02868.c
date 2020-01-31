




struct
{
  int x;
  struct
  {
    int a;
    union
    {
      int b;
    };
  };
} foo;

int
main(int argc, char *argv[])
{
  foo.b = 6;
  foo.a = 5;

  if (foo.b != 6)
    abort ();

  return 0;
}

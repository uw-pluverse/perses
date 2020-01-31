



static int
__attribute__ ((noinline))
func1 (int i)
{
  return i + 2;
}

extern int func2 (int i);

int
main (int argc, char **argv)
{
  return func1 (argc) + func2 (argc) + 1;
}

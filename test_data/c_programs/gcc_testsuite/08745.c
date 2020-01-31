




static int __attribute__ ((noinline, section ("test_section")))
foo (int arg)
{
  return 7 * arg;
}

int
bar (int arg)
{
  return foo (5);
}

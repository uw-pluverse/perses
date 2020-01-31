


void
test1 (int a, long long value, int after)
{
  if (a != 1
      || value != 0x123456789abcdefLL
      || after != 0x55)
    abort ();
}

void
test2 (int a, int b, long long value, int after)
{
  if (a != 1
      || b != 2
      || value != 0x123456789abcdefLL
      || after != 0x55)
    abort ();
}

void
test3 (int a, int b, int c, long long value, int after)
{
  if (a != 1
      || b != 2
      || c != 3
      || value != 0x123456789abcdefLL
      || after != 0x55)
    abort ();
}

void
test4 (int a, int b, int c, int d, long long value, int after)
{
  if (a != 1
      || b != 2
      || c != 3
      || d != 4
      || value != 0x123456789abcdefLL
      || after != 0x55)
    abort ();
}

void
test5 (int a, int b, int c, int d, int e, long long value, int after)
{
  if (a != 1
      || b != 2
      || c != 3
      || d != 4
      || e != 5
      || value != 0x123456789abcdefLL
      || after != 0x55)
    abort ();
}

void
test6 (int a, int b, int c, int d, int e, int f, long long value, int after)
{
  if (a != 1
      || b != 2
      || c != 3
      || d != 4
      || e != 5
      || f != 6
      || value != 0x123456789abcdefLL
      || after != 0x55)
    abort ();
}

void
test7 (int a, int b, int c, int d, int e, int f, int g, long long value, int after)
{
  if (a != 1
      || b != 2
      || c != 3
      || d != 4
      || e != 5
      || f != 6
      || g != 7
      || value != 0x123456789abcdefLL
      || after != 0x55)
    abort ();
}

void
test8 (int a, int b, int c, int d, int e, int f, int g, int h, long long value, int after)
{
  if (a != 1
      || b != 2
      || c != 3
      || d != 4
      || e != 5
      || f != 6
      || g != 7
      || h != 8
      || value != 0x123456789abcdefLL
      || after != 0x55)
    abort ();
}

int
main ()
{
  test1 (1, 0x123456789abcdefLL, 0x55);
  test2 (1, 2, 0x123456789abcdefLL, 0x55);
  test3 (1, 2, 3, 0x123456789abcdefLL, 0x55);
  test4 (1, 2, 3, 4, 0x123456789abcdefLL, 0x55);
  test5 (1, 2, 3, 4, 5, 0x123456789abcdefLL, 0x55);
  test6 (1, 2, 3, 4, 5, 6, 0x123456789abcdefLL, 0x55);
  test7 (1, 2, 3, 4, 5, 6, 7, 0x123456789abcdefLL, 0x55);
  test8 (1, 2, 3, 4, 5, 6, 7, 8, 0x123456789abcdefLL, 0x55);
  exit (0);
}

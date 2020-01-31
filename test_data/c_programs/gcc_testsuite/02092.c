







extern void abort (void);

void test1 (signed char c, int set);
void test2 (unsigned char c, int set);
void test3 (short s, int set);
void test4 (unsigned short s, int set);
void test5 (int i, int set);
void test6 (unsigned int i, int set);
void test7 (long long l, int set);
void test8 (unsigned long long l, int set);
void
test1 (signed char c, int set)
{
  if ((c & (127 +1)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((c & (127 +1)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((c & (127 +1)) == (127 +1))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((c & (127 +1)) != (127 +1))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test2 (unsigned char c, int set)
{
  if ((c & (127 +1)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((c & (127 +1)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((c & (127 +1)) == (127 +1))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((c & (127 +1)) != (127 +1))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test3 (short s, int set)
{
  if ((s & (32767 +1)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((s & (32767 +1)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((s & (32767 +1)) == (32767 +1))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((s & (32767 +1)) != (32767 +1))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test4 (unsigned short s, int set)
{
  if ((s & (32767 +1)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((s & (32767 +1)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((s & (32767 +1)) == (32767 +1))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((s & (32767 +1)) != (32767 +1))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test5 (int i, int set)
{
  if ((i & (2147483647 +1U)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((i & (2147483647 +1U)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((i & (2147483647 +1U)) == (2147483647 +1U))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((i & (2147483647 +1U)) != (2147483647 +1U))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test6 (unsigned int i, int set)
{
  if ((i & (2147483647 +1U)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((i & (2147483647 +1U)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((i & (2147483647 +1U)) == (2147483647 +1U))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((i & (2147483647 +1U)) != (2147483647 +1U))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test7 (long long l, int set)
{
  if ((l & (9223372036854775807LL +1ULL)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((l & (9223372036854775807LL +1ULL)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((l & (9223372036854775807LL +1ULL)) == (9223372036854775807LL +1ULL))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((l & (9223372036854775807LL +1ULL)) != (9223372036854775807LL +1ULL))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test8 (unsigned long long l, int set)
{
  if ((l & (9223372036854775807LL +1ULL)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((l & (9223372036854775807LL +1ULL)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((l & (9223372036854775807LL +1ULL)) == (9223372036854775807LL +1ULL))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((l & (9223372036854775807LL +1ULL)) != (9223372036854775807LL +1ULL))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

int
main ()
{
  test1 (0, 0);
  test1 (127, 0);
  test1 ((-127 -1), 1);
  test1 ((127*2 +1), 1);

  test2 (0, 0);
  test2 (127, 0);
  test2 ((-127 -1), 1);
  test2 ((127*2 +1), 1);

  test3 (0, 0);
  test3 (32767, 0);
  test3 ((-32767 -1), 1);
  test3 ((32767 *2 +1), 1);

  test4 (0, 0);
  test4 (32767, 0);
  test4 ((-32767 -1), 1);
  test4 ((32767 *2 +1), 1);

  test5 (0, 0);
  test5 (2147483647, 0);
  test5 ((-2147483647 -1), 1);
  test5 ((2147483647 *2U +1U), 1);

  test6 (0, 0);
  test6 (2147483647, 0);
  test6 ((-2147483647 -1), 1);
  test6 ((2147483647 *2U +1U), 1);

  test7 (0, 0);
  test7 (9223372036854775807LL, 0);
  test7 ((-9223372036854775807LL -1), 1);
  test7 ((9223372036854775807LL * 2ULL + 1), 1);

  test8 (0, 0);
  test8 (9223372036854775807LL, 0);
  test8 ((-9223372036854775807LL -1), 1);
  test8 ((9223372036854775807LL * 2ULL + 1), 1);

  return 0;
}

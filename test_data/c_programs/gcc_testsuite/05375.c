




void foo(long);

void xxx(void)
{
  long iter, jter;

  for (iter = 0, jter = 2; iter < 100; iter++, jter++)
    {
      foo (iter);
      foo (jter);
    }
}

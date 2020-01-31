



int
very_long_function(int a)
{
  if (a > 0)
    return 2 * a + very_long_function (a)/4;
  else
    return 2 * -a + very_long_function (a)/4;
}

int
blah ()
{
  very_long_function (1);
}

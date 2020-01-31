




enum test_enum {
  FOO,
  BAR
};

int valid(enum test_enum arg)
{
  return arg >= 0 && arg <= BAR;
}

int valid2(unsigned int arg2)
{
  return arg2 >= FOO && arg2 <= BAR;
}

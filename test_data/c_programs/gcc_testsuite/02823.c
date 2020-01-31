long
f (long x)
{
  return x / (-0x7fffffffL - 1L);
}

long
r (long x)
{
  return x % (-0x7fffffffL - 1L);
}



long
std_eqn (long num, long denom, long quot, long rem)
{


  return quot * (-0x7fffffffL - 1L) + rem == num;
}

long nums[] =
{
  -1L, 0x7fffffffL, -0x7fffffffL - 1L
};

main ()
{
  int i;

  for (i = 0;
       i < sizeof (nums) / sizeof (nums[0]);
       i++)
    if (std_eqn (nums[i], -0x7fffffffL - 1L, f (nums[i]), r (nums[i])) == 0)
      abort ();

  exit (0);
}




unsigned long foobar(unsigned long ns)
{
  while(ns >= 10000L)
    ns -= 10000L;
  return ns;
}

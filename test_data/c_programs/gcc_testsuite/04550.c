



int
fn1 (int f, int s)
{
  int ret = 0;
  if (f)
    ret = s / (f ? (unsigned long) 8 : 0);
  return ret;
}

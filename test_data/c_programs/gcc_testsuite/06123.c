


int foo11 (int c)
{
  __attribute__ ((used))
  static int local1, local2;
  local1 = 0;
  local2 += c;
  local1 = 2;
  local2++;
  return local1 + local2;
}

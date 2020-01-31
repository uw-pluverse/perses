



static int __attribute__((noinline)) t(int a)
{
 return a+1;
}
void q(void)
{
  int i = t(1);
  if (!i)
    i = t(1);
}

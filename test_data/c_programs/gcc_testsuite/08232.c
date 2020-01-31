






const char *sarr[10000];
const char *buf_hot;
const char *buf_cold;

__attribute__((noinline))
void
foo (int path)
{
  int i;
  if (path)
    {
      for (i = 0; i < 10000; i++)
 sarr[i] = buf_hot;
    }
  else
    {
      for (i = 0; i < 10000; i++)
 sarr[i] = buf_cold;
    }
}

int
main (int argc, char *argv[])
{
  buf_hot = "hello";
  buf_cold = "world";
  foo (argc);
  return 0;
}

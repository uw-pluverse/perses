


static const char digs[] = "0123456789ABCDEF";
int __attribute__((pure)) bar();

int foo (int i)
{
  int len;
  if (i)
    return 0;
  len = bar();
  return digs[len];
}




static const int x;

int test1 (void)
{
  char *p = "hello";
  int i = x;
  i = i + 5;
  return p[i];
}

int test2 (void)
{
  int i = x;
  i = i + 5;
  return "hello"[i];
}

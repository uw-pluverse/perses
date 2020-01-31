



char
foo (int *p)
{

  int ret = *(char *) p;

  *p = 26;
  return ret;
}

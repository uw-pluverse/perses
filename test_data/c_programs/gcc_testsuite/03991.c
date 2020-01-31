


void *foo (void *c)
{
  void *a = __builtin_extract_return_addr (c);
  return a;
}

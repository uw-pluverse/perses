


int bbb = 0;

int __attribute__((noinline,noclone)) aaa(void)
{
    ++bbb;
    return 0;
}

int __attribute__((noinline,noclone)) ccc(void)
{
  int ddd;

  if (aaa())
    return bbb;


  ddd = bbb;

  if (aaa ())
    return 0;


  return ddd;
}

int main(void)
{
    if (ccc() != 1)
 __builtin_abort();
    return 0;
}

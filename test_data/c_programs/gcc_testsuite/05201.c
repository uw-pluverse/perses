

static void bad_boy()
{
}
int
main()
{
  void *t=(void *)bad_boy;
  if (!t)
    return 1;
  return 0;
}






__attribute__((noinline, noclone))
static void
NullDeref(int *ptr)
{
  ptr[10]++;
}

int main()
{
  NullDeref((int*)0);
  return 0;
}

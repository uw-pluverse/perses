





int __attribute__((target("arm")))
foo(int a)
{
  return a ? 1 : 5;
}

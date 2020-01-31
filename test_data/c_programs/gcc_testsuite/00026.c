



extern void bar(long long);

int foo(long long a, char b, long long c, long long d)
{
  if (c == 0)
    c = d;

  bar(b + c);

  return a == d;
}

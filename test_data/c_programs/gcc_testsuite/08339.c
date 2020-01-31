


typedef long long s64;

int
foo (s64 a, s64 b, s64 c)
{
 s64 d = a - b;

  if (d == 0)
    return a + c;
  else
    return b + d + c;
}





extern void bar (char, char);
int
foo (char b)
{
  char a;
  a = b;
  b = 'b';
  bar (a, b);
  b = a;
  if (b == 0)
    a++;
  return a + b;
}

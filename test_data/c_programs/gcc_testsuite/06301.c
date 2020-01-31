



typedef int word __attribute__((mode(word)));

word
foo (word x, word y, word a)
{
  word i = x;
  word j = y;

  __builtin_expect (x > y, 1);
  if (x > y)
    {
      i = a;
      j = i;
    }
  return i * j;
}

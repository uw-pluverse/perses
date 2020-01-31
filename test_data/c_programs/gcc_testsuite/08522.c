




typedef int word __attribute__((mode(word)));

word
foo (word x, word y, word a)
{
  word i = x;
  word j = y;
  if (x > y)
    {
      i = a;
      j = i;
    }
  return i * j;
}

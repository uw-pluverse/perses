



void bar(int i, int j)
{
  return;
}

void foo (int i)
{
   int a = i-i++; (void)a;

   bar (i--, i++);
}

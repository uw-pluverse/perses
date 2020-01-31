


void bar (int);
void
foo (int a, int b)
{
  if (a)
    if (b)
      bar (1);
  else
    bar (2);
}

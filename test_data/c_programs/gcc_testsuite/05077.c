


int x;
void
foo (void)
{
  if (x == 0)
    x = 0;
}
void
bar (int i)
{
  if (x == i)
    x = i;
}

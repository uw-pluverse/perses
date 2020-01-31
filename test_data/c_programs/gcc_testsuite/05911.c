


void bar1 (void);
void bar2 (void);

void
foo (unsigned int a, unsigned int b)
{
  if (a >= b)
    bar1 ();
  else if (b <= a)
    bar2 ();
}

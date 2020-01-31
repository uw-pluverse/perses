


void *arf ();
int
foo(void (*q)(void))
{
  int r = q;

  if (r != 0)
    return 1;
  else
    return 2;
}

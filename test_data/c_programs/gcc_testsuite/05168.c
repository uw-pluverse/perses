



void *arf ();
int
foo()
{
  void *p = arf ();

  if ((void (*)(void))p != 0)
    return 1;
  else
    return 2;
}





unsigned nonvolvar[2];

void
test (int arg)
{
  unsigned v = *(volatile unsigned *) (&nonvolvar[arg]);
  *(volatile unsigned *) (&nonvolvar[arg]) = v;
}

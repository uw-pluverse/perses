


int f (int);
unsigned int glob;

void
g ()
{
  while (f (glob));
  glob = 5;
}

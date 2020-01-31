





static struct { int i:8; } s;

void
foo ()
{
  if (s.i = 0) ;
}

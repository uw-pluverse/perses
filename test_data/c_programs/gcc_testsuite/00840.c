



int* bar (void) ;

int
foo (int a)
{
  int *b = bar ();
  return b[a];
}

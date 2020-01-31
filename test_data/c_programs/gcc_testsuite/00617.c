



__attribute__ ((noplt))
int* bar0 (void) ;
int* bar1 (void) ;

int
foo (int a)
{
  int *b0 = bar0 ();
  int *b1 = bar1 ();
  return b0[a] + b1[a];
}

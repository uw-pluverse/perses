





int A[2];
int *gp = &A[4];
int *gpi;

int
main (void)
{
  gpi = &A[4];
  static int *pi = &A[4];
  return 0;
}

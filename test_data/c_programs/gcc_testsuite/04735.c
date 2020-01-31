


void
foo (int *a)
{
  int *p = a;

 {
    *a = 0;
    *p = 1;
  }
}




void
foo (void)
{
  unsigned int a;
  unsigned int *p = &a;

 {
    a = 0;
    *p = 1;
  }
}






void
foo (void)
{
  unsigned int a[2];
  unsigned int *p = &a[0];

 {
    a[0] = 0;
    *p = 1;
  }
}

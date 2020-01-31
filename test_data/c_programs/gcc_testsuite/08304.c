



extern void foo (void *p);

void
bar (void)
{
  {

    int i __attribute__((cleanup (foo)));
  }
}

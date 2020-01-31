




static __thread void *foo [2];
void
test1 (void)
{
  unsigned int s;

  for (s = 0; s < 2; ++s)
    foo [s] = &foo[s];
}

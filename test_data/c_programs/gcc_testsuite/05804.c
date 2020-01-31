

static int local_static;
void __attribute__ ((leaf)) leaf_call (void);

int
clobber_it (void)
{
  return local_static++;
}
int
test (void)
{
  local_static = 9;
  leaf_call ();
  return local_static;
}

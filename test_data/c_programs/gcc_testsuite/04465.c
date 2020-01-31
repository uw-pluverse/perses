


extern int j;
static int i __attribute__((weakref("j")));

int
foo (void)
{
  return &i ? i : 0;
}

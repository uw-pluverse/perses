




int e;

int
main (void)
{
  return e ? 0 : (__builtin_unreachable (), 1);
}

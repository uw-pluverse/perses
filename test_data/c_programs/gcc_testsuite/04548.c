



typedef volatile const _Complex float *T;

int
main (void)
{
  T t = 0;
  if (*t)
    return 42;
  return 0;
}

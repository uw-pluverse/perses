

long unsigned int f (void *ptr)
{
  return ((long unsigned int)(ptr)-1) | 1ULL;
}

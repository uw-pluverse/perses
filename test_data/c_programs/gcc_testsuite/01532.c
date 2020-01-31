



int
f (int start, int end, int *start_)
{
  if (start == -1 || end == -1)
    return -1;

  if (end - start)
    return -1;

  *start_ = start;

  return 0;
}

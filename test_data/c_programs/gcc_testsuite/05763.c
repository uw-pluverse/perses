


int mymax2(int *it, int *end)
{
  int max = *it;
  while (++it != end)
    if (*it > max)
      max = *it;
  return max;
}

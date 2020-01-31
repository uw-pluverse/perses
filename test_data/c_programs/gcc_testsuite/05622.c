


long
NumSift (long *array, unsigned long k)
{
  if (array[k] < array[k + 1L])
    ++k;
  return array[k];
}





float
foo (float f)
{
  float array[128];
  float x = 0.;
  int i;
  for (i = 0; i < sizeof(array) / sizeof(*array); i++)
    array[i] = f;
  for (i = 0; i < sizeof(array) / sizeof(*array); i++)
    x += array[i];
  return x;
}

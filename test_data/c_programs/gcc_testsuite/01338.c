




float
foo (float x, float y)
{
  return __builtin_isunordered (x, y) ? x : y;
}

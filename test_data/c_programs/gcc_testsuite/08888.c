







_Complex float
foo (float a)
{
  return __builtin_copysign (a != a, a);
}

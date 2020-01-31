







double
f1 (double y)
{
  return (1.2 * __builtin_copysign (1.1, y));
}

double
f2 (double y)
{
  return (-1.2 * __builtin_copysign (1.1, y));
}

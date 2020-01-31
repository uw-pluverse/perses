double normal1 (double, double);
double power5 (double, double) __attribute__((__target__("cpu=power5")));
double power6 (double, double) __attribute__((__target__("cpu=power6")));
double power6x (double, double) __attribute__((__target__("cpu=power6x")));
double power7 (double, double) __attribute__((__target__("cpu=power7")));
double power7n (double, double) __attribute__((__target__("cpu=power7,no-vsx")));
double normal2 (double, double);


double normal1 (double a, double b)
{
  return __builtin_copysign (a, b);
}


double power5 (double a, double b)
{
  return __builtin_copysign (a, b);
}


double power6 (double a, double b)
{
  return __builtin_copysign (a, b);
}


double power6x (double a, double b)
{
  return __builtin_copysign (a, b);
}


double power7 (double a, double b)
{
  return __builtin_copysign (a, b);
}


double power7n (double a, double b)
{
  return __builtin_copysign (a, b);
}


double normal2 (double a, double b)
{
  return __builtin_copysign (a, b);
}

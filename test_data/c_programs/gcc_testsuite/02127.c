double func (double d, int n)
{
  if (n == 0)
    return d;
  else
    return d + func (d, n - 1);
}

int main ()
{
  if (__builtin_copysign (1.0, func (0.0 / -5.0, 10)) != -1.0)
    abort ();
  exit (0);
}

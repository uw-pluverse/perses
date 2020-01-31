



typedef long double a __attribute__((vector_size (16)));

a __attribute__((noinline))
sum (a first, a second)
{
    return first + second;
}

a
foo (a x, a y, a z)
{
  return sum (x, y) + z;
}

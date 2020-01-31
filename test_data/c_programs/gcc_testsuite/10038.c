


int
foo (_Bool a, _Bool b)
{
  return (a | !a) | (!b | b);
}

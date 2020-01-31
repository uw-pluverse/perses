


_Bool
foo (_Bool a, _Bool b, _Bool c)
{
  _Bool r1 = a == 0 & b != 0;
  _Bool r2 = b != 0 & c == 0;
  return (r1 == 0 & r2 == 0);
}

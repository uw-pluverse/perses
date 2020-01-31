







_Bool r;

void
foo (_Bool b)
{
  r = !b == 1;
  r = !b != 1;
  r = !b > 1;
  r = !b >= 1;
  r = !b < 1;
  r = !b <= 1;
}

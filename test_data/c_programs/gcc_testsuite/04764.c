_Bool r;

int
f1 (int a)
{
  r = !a == 0;
  r = !a != 0;
  r = !a == 1;
  r = !a != 1;
}

int
f2 (int a)
{
  r = !a > 0;
  r = !a >= 0;
  r = !a < 0;
  r = !a <= 0;
  r = !a > 1;
  r = !a >= 1;
  r = !a < 1;
  r = !a <= 1;
}

_Bool r;

int
same (int a, int b)
{
  r = !a == !b;
  r = !!a == !!b;
  r = !!a == !b;
  r = !a == !!b;
}

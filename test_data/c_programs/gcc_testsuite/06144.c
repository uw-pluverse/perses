


char *foo(int bar, char *baz)
{
  char *tmp;

  if (bar & 3)
    tmp = baz;

  switch (bar) {
  case 1:
    tmp[5] = 7;
    break;
  case 2:
    tmp[11] = 15;
    break;
  default:
    tmp = 0;
    break;
  }

  return tmp;
}

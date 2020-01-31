int foo (int a, int b)
{
  __label__ z;
  int x;
  int y;
  static void *p;

  switch (a) {
  case 2:
    x = 4;
    break;
  case 4:
    x = 6;
    break;
  case 8: case 10: case 13: case 11: case 17: case 19:
    x = 7;
    break;
  default:
    x = -1;
    break;
  }
  switch (b) {
  case 2:
    y = 4;
    break;
  case 4:
    y = 6;
    break;
  case 8: case 10: case 13: case 11: case 17: case 19:
    y = 7;
    break;
  default:
    y = -1;
    break;
  }
 z:
  p = &&z;
  return x * y;
}
int main (int argc, char *argv[])
{
  return 1 == foo (argc, argc + 1);
}

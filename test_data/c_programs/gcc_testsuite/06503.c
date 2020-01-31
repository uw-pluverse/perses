volatile int x;

int main(void)
{
  int y;

  x = 0;

  switch(x)
    {
    case 0:
      y = 2 * x;
      break;
    case 1:
      y = -3 * x;
      break;
    case 2:
      y = x + 5;
      break;
    case 3:
      y = x - 7;
      break;
    default:
      break;
    }

  x = y;

  return 0;
}

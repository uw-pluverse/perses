


void foo (int y)
{
  switch (y)
    {
    case 3:
    case 5:
    case 7:
    case 11:
      break;
    default:
      __builtin_unreachable ();
    }
}

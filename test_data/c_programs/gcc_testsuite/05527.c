






int
foo (int a)
{
  int b;
  int c;
  int d;

  if (a == 2)
    b = 3;
  else
    b = 5;

  c = 7;

  d = 11;

  for (;;)
    {
      if (d == 5)
 break;

      d = b;
    }

  return 13;
}

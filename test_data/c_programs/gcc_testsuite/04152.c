



void f (void)
{
  char *c;
  do
    {
      if (c)
 break;
    }
  while (1);
  if (!c)
    while (1)
      f ();
}

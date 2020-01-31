
int a[2];

f (int i)
{
  for (; i < 2147483647; i++)
    {
      a[i] = -2;
      if (&a[i] == &a[1])
 break;
    }
}

main ()
{
  a[0] = a[1] = 0;
  f (0);
  if (a[0] != -2 || a[1] != -2)
    abort ();
  exit (0);
}

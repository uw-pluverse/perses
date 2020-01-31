

main()
{
  int a[8] = {1};
  int i;

  for (i = 1; i < 8; i++)
    if (a[i] != 0)
      abort();

  exit (0);
}

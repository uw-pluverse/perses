





int
foo (int a)
{
  if (!a)
    return 1;

  {
    int s[a];
    return 0;
  }
}

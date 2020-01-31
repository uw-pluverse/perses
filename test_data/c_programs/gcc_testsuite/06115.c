


int test(int v)
{
  int x = 0;
  int u;
  for (u=0;u<2;u++)
  {
    if (u>v)
    {
      if (u%2==1)
        x++;
    }
  }
  return x;
}

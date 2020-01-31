



extern int q(int);
int t(int a)
{
  if (a > 12)
    {
      q(a+5);
      q(a+5);
    }
  else
      q(a+10);
}

int
main()
{
   t(5);
   t(20);
}

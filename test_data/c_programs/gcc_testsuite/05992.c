


__attribute__ ((pure))
int bla(int);

int foo(void)
{
  int i;
  int sum = 0;


  for (i = 0; i < 4; i++)
    {
      sum += bla (i);
      sum += bla (2*i);
      sum += bla (3*i);
      sum += bla (4*i);
      sum += bla (5*i);
      sum += bla (6*i);
      sum += bla (7*i);
      sum += bla (8*i);
    }
  return sum;
}

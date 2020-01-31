



int bar()
{
  unsigned x = 0;
  int y = 1;


  x += x < y ? 1 : 0;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"

 x += x < y ? 1 : 0;
#pragma GCC diagnostic pop

 x += x < y ? 1 : 0;

  return x;
}

enum EE { ONE, TWO };

int f (enum EE e)
{
  int r = 0;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch-enum"

 switch (e)
    {
    case ONE:
      r = 1;
      break;
    }
#pragma GCC diagnostic pop

 switch (e)
    {
    case ONE:
      r = 1;
      break;
    }
  return r;
}

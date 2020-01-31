



int foo()
{
  int x[2][2], y[2];
  int i, n, s;




  for (n = 0; n < 2; n++)
    {
      s = 0;
      for (i = 0; i < 2; i++)
        s += x[n][i]*y[i];
      s += 1;
    }

  return s;
}




int g;
void bar();
void blah(int);
int foo (int n, int m, int r, int t)
{
  int flag = 0;
  int v;

  if (t)
    {
      if (n)
        {
          v = r;
          flag = 1;
        }

      if (m) g++;
      else bar();

      if (flag)
        blah(v);
    }
  else
    {
      v = r+1;
      flag = 2;
    }

  if (m) g++;
  else bar();

  if (g)
    blah(v);

  return 0;
}

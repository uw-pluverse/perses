


int g;
void bar (void);
void blah (int);

int foo (int n, int m, int r)
{
  int flag = 0;
  int v;

  if (n)
    {
      v = r;
      flag = 1;
    }

  if (m) g++;
  else bar();

  if (flag)
    blah(v);

  return 0;
}

int foo_2 (int n, int m, int r)
{
  int flag = 0;
  int v;

  if (n)
    {
      v = r;
      flag = 1;
    }

  if (m) g++;
  else bar();

  if (flag)
    blah(v);
  else
    blah(v);

  return 0;
}

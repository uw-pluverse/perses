






struct tail0
{
  int xxx;
  int yyy[0];
};

int loop0 (int n, struct tail0 *x)
{
  int i, s = 0;

  for (i = 0; i < n; i++)
    s += x->yyy[i];

  return s;
}

struct tail1
{
  int xxx;
  int yyy[1];
};
int loop1 (int n, struct tail1 *x)
{
  int i, s = 0;

  for (i = 0; i < n; i++)
    s += x->yyy[i];

  return s;
}




struct tail5
{
  int xxx;
  int yyy[5];
};
int loop5 (int n, struct tail5 *x)
{
  int i, s = 0;

  for (i = 0; i < n; i++)
    s += x->yyy[i];

  return s;
}




struct Loc {
    int x[3];
};

void bar (struct Loc *);

int foo (int i, int j, int k, int b)
{
  struct Loc IND;
  int res;

  if (b)
    {
      IND.x[0] = i;
      IND.x[1] = j;
      IND.x[2] = k-1;
    }
  else
    {
      IND.x[0] = i;
      IND.x[1] = j;
      IND.x[2] = k;
    }


  res = IND.x[0] + IND.x[1] + IND.x[2];


  bar (&IND);

  return res;
}





int test1 (int a, int b)
{
  return (a < b || a == b);
}


int test2 (int a, int b)
{
  int lt = a < b;
  int eq = a == b;

  return (lt || eq);
}


int test3 (int a, int b)
{
  int lt = a <= b;
  int eq = a == b;

  return (lt || eq);
}


int test4 (int a, int b)
{
  int lt = a < b;
  int eq = b == a;

  return (lt || eq);
}


int test5 (int a, int b)
{
  int lt = a < b;
  int eq = a == b;

  return (lt && eq);
}

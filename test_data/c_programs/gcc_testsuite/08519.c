







int tf = 1;


enum mm1
{
  VOID, SI, DI, MAX = -1
};


enum mm2
{
  VOID2, SI2, DI2, MAX2
};

int f(enum mm1 x)
{
  return x == (tf?DI:SI);
}

int g(enum mm1 x)
{
  return x == (tf?DI:-1);
}

int h(enum mm2 x)
{
  return x == (tf?DI2:SI2);
}

int i(enum mm2 x)
{
  return x == (tf?DI2:-1);
}

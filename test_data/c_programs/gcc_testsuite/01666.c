


int (*funpointer)(int);

int f(int t)
{
  return t*3;
}

void init()
{
 funpointer=f;
}

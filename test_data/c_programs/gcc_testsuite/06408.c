






int * f( int a)
{
 return &a;
}

int * g()
{
 int b = 0;
 return &b;
}

struct ll
{
  int i;
};

int *h(struct ll c)
{
  return &c.i;
}


struct ll d;

int *i()
{
  return &d.i;
}


int *j(struct ll *c)
{
  return &c->i;
}

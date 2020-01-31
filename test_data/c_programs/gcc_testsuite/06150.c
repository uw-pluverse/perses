





int x[];

void
f (void)
{
  extern int x[];
}

int x[10];

void
g (void)
{
  int x;
  {
    extern int x[10];
  }
}

void
h (void)
{
  sizeof (x);
}

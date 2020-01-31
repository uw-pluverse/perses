






static int x[];

void
f (void)
{
  extern int x[2];
}



static int y[];
void
g (void)
{
  extern int y[1];
}

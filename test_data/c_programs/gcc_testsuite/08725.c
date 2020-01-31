


int
t(int s, void **p)
{
  int i;
  for (i=0;i<10000;i+=s)
    p[i]=0;
}
int
m(void **p)
{
  t (10, p);
}

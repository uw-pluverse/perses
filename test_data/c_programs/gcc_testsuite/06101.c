




extern int a;
int
t()
{
  return &a!=0;
}
extern int a __attribute__ ((weak));

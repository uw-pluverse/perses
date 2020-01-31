

extern void *alloca (long unsigned int);
int q(int a);
int *v;
int
t(int a)
{
 int r,r1;
 if (a)
  r1=r = q(a-1);
 else
  return 0;

 if (r!=r1)
  v=alloca(r);
 return r;
}

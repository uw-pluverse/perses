

int
t(int a)
{
 int r;
 if (a)
  r = t(a-1);
 else
  return 0;
 if (r)
  r=r;
 return r;
}

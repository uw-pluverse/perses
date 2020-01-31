

int
t(int a)
{
 int r;
 if (a&1)
  r = t(a-1);
 else if (a)
  r = t(a-2);
 else
  return 0;
 if (r)
  r=r;
 return r;
}

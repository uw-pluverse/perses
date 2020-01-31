

int link_error(void);
int s(void);

int t(int i)
{
  _Bool g = i == 4;
 int h = g;
 _Bool j = h;
 int k = j;
 _Bool l = k == 0;
 _Bool o = !l;
 int m = o;

 if (m)
  if (i != 4)
   return link_error();
 return 0;
}

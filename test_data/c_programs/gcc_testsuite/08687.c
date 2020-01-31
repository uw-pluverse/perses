



struct a {int a,b,c,d,e;};
void t(int);
void t2();

void
accessfield (struct a a)
{
  t(a.a);




  t2(&a);
  t(a.a);
  return;

}
void
accessreference (struct a *a)
{
  t(a->a);






  t2(&a);
  return;

}

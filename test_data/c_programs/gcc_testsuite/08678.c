


void test2 (int);
int
test (int a)
{
   int i;
   for (i=0; i<a; i++)
{
     test2(a);
     test2(a);
}
}
int
m()
{
  test (10);
}

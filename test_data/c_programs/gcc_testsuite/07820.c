




struct S { int s; int t; };
__thread struct S a[10];
int b;

int
main ()
{
  int c = a[b].t;
  (void) c;
  return 0;
}

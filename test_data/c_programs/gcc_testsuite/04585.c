





struct T { char d[8]; int e; };
struct T t = { "abcdefg", 1 };



struct U { int a : 5; int b : 19; int c : 8; };
struct S { struct U d[10]; };
struct S s __attribute__ ((aligned(4096)));

int
f1 (struct T x, int i)
{
  char *p = x.d;
  p += i;
  return *p;
}
int
f4 (int i)
{
  return s.d[i].b;
}







int
f5 (int i)
{
  struct U *u = s.d;
  u += i;
  return u->b;
}






int
main (void)
{
  f1 (t, 12);




  f4 (12);
  f5 (12);
  return 0;
}

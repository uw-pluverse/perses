



extern int gi;

extern int foo1(int, int);
extern void foo2(int, int);
extern float foo3(int);

float bar(int i1, int i2)
{
  int i3;

  if (i2) {
    i3 = foo1(i1, gi);
    foo2(i1, i3);
  }
  else
    return foo3(i2);
}

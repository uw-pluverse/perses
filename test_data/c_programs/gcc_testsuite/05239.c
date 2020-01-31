



struct S
{
  int i;
  unsigned short f1;
  char f2;
  unsigned short f3, f4;
};


int foo (struct S *p)
{
  struct S l;

  l = *p;
  l.i++;
  *p = l;
}

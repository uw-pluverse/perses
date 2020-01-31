


struct S { unsigned f; };

int
foo ( struct S *p)
{
  int *q = (int *)&p->f;
  int i = *q;
  return i + p->f;
}

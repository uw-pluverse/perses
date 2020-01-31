


struct A
{
  int a;
  int b;
};

int
foo (struct A *p, struct A *q)
{
  int *r = 0;

  if (p)
    {
      if (p == q)
 {


   if (q)
     r = &q->a;



   if (r)
     return 5;
 }
    }

  return q->a;
}

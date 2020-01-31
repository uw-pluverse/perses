


void link_error (void);

struct A
{
  int x;
  float y;
};

volatile float X, Y;

int __attribute__ ((__noinline__))
baz (struct A *z, struct A *y)
{
  z->x = (int) X;
  z->y = Y;
  y->x = (int) X;
  y->y = Y;
}


struct A B;

float foo (int i)
{
  struct A *p, x, y, z;

  p = (i > 10) ? &x : &z;
  x.y = 3.0;
  p->x += baz (&z, &y);
  X = z.y;
  Y = p->y;





  if (x.y != 3.0)
    link_error ();
}

int
main(int argc, char **argv)
{
  foo (argc);
}

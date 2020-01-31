


extern void link_error (void);



struct s
{
  char d;
  int a, b;
  double m;
};

void foo2 (struct s* r, struct s* p)
{
  r->a = 0;
  p->b = 1;
  r->a++;
  p->b++;
  if (r->a != 1)
    link_error ();
  if (p->b != 2)
    link_error ();
}

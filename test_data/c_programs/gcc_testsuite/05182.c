


extern void link_error (void);



struct s
{
  char d;
  int a, b;
  double m;
};


void foo (struct s* r)
{
  r->a = 0;
  r->b = 1;
  r->a++;
  r->b++;
  if (r->a != 1)
    link_error ();
  if (r->b != 2)
    link_error ();
}

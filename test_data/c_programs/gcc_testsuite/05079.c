


extern void link_error (void);



struct s
{
  char d;
  int a, b;
  double m;
};

void foo (struct s* teststruct)
{
  teststruct->a = 0;
  teststruct->a++;
  if (teststruct->a != 1)
    link_error ();
}

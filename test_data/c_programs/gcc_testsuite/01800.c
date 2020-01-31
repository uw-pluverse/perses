struct s
{
  short i1;
  long i2;
  short i3;
};

struct s foo (struct s s)
{
  s.i2++;
  return s;
}

int main ()
{
  struct s s = foo ((struct s) { 1000, 2000L, 3000 });
  if (s.i1 != 1000 || s.i2 != 2001L || s.i3 != 3000)
    abort ();
  exit (0);
}

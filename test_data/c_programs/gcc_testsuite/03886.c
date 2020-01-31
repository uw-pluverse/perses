







struct s {
  int m : 1;
};

int
foo (struct s *p)
{
  return !p->m;
}

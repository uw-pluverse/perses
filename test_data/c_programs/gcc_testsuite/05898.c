




struct s {
    int *blah;
};

static struct s array[] = { { 0 } };

void
foo (struct s *p)
{
  struct s *q = &array[1];
  while (p < q)
    p++;
}

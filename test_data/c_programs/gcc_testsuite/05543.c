

struct s {
      int *n;
};

int
foo (long unsigned int i, struct s *array)
{
  int *p = array[i].n;
  if (p)
    {
      int *q = array[i].n;
      if (p != q)
 return 1;
    }
  return 0;
}
